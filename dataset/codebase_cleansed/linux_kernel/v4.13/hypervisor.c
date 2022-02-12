int __init hypervisor_init(void)
{
hypervisor_kobj = kobject_create_and_add("hypervisor", NULL);
if (!hypervisor_kobj)
return -ENOMEM;
return 0;
}
