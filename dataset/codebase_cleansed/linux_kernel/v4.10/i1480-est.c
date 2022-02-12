static int __init i1480_est_init(void)
{
int result = uwb_est_register(i1480_CET_VS1, 0x00, 0x8086, 0x0c3b,
i1480_est_fd00,
ARRAY_SIZE(i1480_est_fd00));
if (result < 0) {
printk(KERN_ERR "Can't register EST table fd00: %d\n", result);
return result;
}
result = uwb_est_register(i1480_CET_VS1, 0x01, 0x8086, 0x0c3b,
i1480_est_fd01, ARRAY_SIZE(i1480_est_fd01));
if (result < 0) {
printk(KERN_ERR "Can't register EST table fd01: %d\n", result);
return result;
}
return 0;
}
static void __exit i1480_est_exit(void)
{
uwb_est_unregister(i1480_CET_VS1, 0x00, 0x8086, 0x0c3b,
i1480_est_fd00, ARRAY_SIZE(i1480_est_fd00));
uwb_est_unregister(i1480_CET_VS1, 0x01, 0x8086, 0x0c3b,
i1480_est_fd01, ARRAY_SIZE(i1480_est_fd01));
}
