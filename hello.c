#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/types.h>

MODULE_AUTHOR("Sirokomskyi M <warface123roadster@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint counter = 1;
module_param(counter,uint,S_IRUGO);
MODULE_PARM_DESC(counter, "This parameter is for number of hello world");

static int __init hello_init(void)
{
	uint i = 0;
  	pr_info("Input %d\n", counter);

	if(counter == 0) 
	{
		pr_warn("You cannot enter 0");
	}
	else if(counter >= 5 && counter <= 10) 
	{
		pr_warn("You should enter number less than 5");
	} 
	else if(counter > 10) 
	{
		pr_err("The parameter is greater than 10");
		pr_info("");
		return -EINVAL;
	}

	for(i = 0; i < counter; i++) {
		printk(KERN_INFO "Hello, world!\n");
	}

	pr_info("");
	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);


