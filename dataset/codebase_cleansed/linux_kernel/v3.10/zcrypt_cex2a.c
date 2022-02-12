static int zcrypt_cex2a_probe(struct ap_device *ap_dev)
{
struct zcrypt_device *zdev = NULL;
int rc = 0;
switch (ap_dev->device_type) {
case AP_DEVICE_TYPE_CEX2A:
zdev = zcrypt_device_alloc(CEX2A_MAX_RESPONSE_SIZE);
if (!zdev)
return -ENOMEM;
zdev->user_space_type = ZCRYPT_CEX2A;
zdev->type_string = "CEX2A";
zdev->min_mod_size = CEX2A_MIN_MOD_SIZE;
zdev->max_mod_size = CEX2A_MAX_MOD_SIZE;
zdev->short_crt = 1;
zdev->speed_rating = CEX2A_SPEED_RATING;
zdev->max_exp_bit_length = CEX2A_MAX_MOD_SIZE;
break;
case AP_DEVICE_TYPE_CEX3A:
zdev = zcrypt_device_alloc(CEX3A_MAX_RESPONSE_SIZE);
if (!zdev)
return -ENOMEM;
zdev->user_space_type = ZCRYPT_CEX3A;
zdev->type_string = "CEX3A";
zdev->min_mod_size = CEX2A_MIN_MOD_SIZE;
zdev->max_mod_size = CEX2A_MAX_MOD_SIZE;
zdev->max_exp_bit_length = CEX2A_MAX_MOD_SIZE;
if (ap_test_bit(&ap_dev->functions, AP_FUNC_MEX4K) &&
ap_test_bit(&ap_dev->functions, AP_FUNC_CRT4K)) {
zdev->max_mod_size = CEX3A_MAX_MOD_SIZE;
zdev->max_exp_bit_length = CEX3A_MAX_MOD_SIZE;
}
zdev->short_crt = 1;
zdev->speed_rating = CEX3A_SPEED_RATING;
break;
}
if (!zdev)
return -ENODEV;
zdev->ops = zcrypt_msgtype_request(MSGTYPE50_NAME,
MSGTYPE50_VARIANT_DEFAULT);
zdev->ap_dev = ap_dev;
zdev->online = 1;
ap_dev->reply = &zdev->reply;
ap_dev->private = zdev;
rc = zcrypt_device_register(zdev);
if (rc) {
ap_dev->private = NULL;
zcrypt_msgtype_release(zdev->ops);
zcrypt_device_free(zdev);
}
return rc;
}
static void zcrypt_cex2a_remove(struct ap_device *ap_dev)
{
struct zcrypt_device *zdev = ap_dev->private;
struct zcrypt_ops *zops = zdev->ops;
zcrypt_device_unregister(zdev);
zcrypt_msgtype_release(zops);
}
int __init zcrypt_cex2a_init(void)
{
return ap_driver_register(&zcrypt_cex2a_driver, THIS_MODULE, "cex2a");
}
void __exit zcrypt_cex2a_exit(void)
{
ap_driver_unregister(&zcrypt_cex2a_driver);
}
