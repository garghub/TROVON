static int rfkill_set_block(void *data, bool blocked)
{
unsigned char cmd;
if (blocked)
cmd = EC_WLAN_ENTER_RESET;
else
cmd = EC_WLAN_LEAVE_RESET;
return olpc_ec_cmd(cmd, NULL, 0, NULL, 0);
}
static int __devinit xo1_rfkill_probe(struct platform_device *pdev)
{
struct rfkill *rfk;
int r;
rfk = rfkill_alloc(pdev->name, &pdev->dev, RFKILL_TYPE_WLAN,
&rfkill_ops, NULL);
if (!rfk)
return -ENOMEM;
r = rfkill_register(rfk);
if (r) {
rfkill_destroy(rfk);
return r;
}
platform_set_drvdata(pdev, rfk);
return 0;
}
static int __devexit xo1_rfkill_remove(struct platform_device *pdev)
{
struct rfkill *rfk = platform_get_drvdata(pdev);
rfkill_unregister(rfk);
rfkill_destroy(rfk);
return 0;
}
