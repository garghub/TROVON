static int zcrypt_cex2a_card_probe(struct ap_device *ap_dev)
{
static const int CEX2A_SPEED_IDX[] = {
800, 1000, 2000, 900, 1200, 2400, 0, 0};
static const int CEX3A_SPEED_IDX[] = {
400, 500, 1000, 450, 550, 1200, 0, 0};
struct ap_card *ac = to_ap_card(&ap_dev->device);
struct zcrypt_card *zc;
int rc = 0;
zc = zcrypt_card_alloc();
if (!zc)
return -ENOMEM;
zc->card = ac;
ac->private = zc;
if (ac->ap_dev.device_type == AP_DEVICE_TYPE_CEX2A) {
zc->min_mod_size = CEX2A_MIN_MOD_SIZE;
zc->max_mod_size = CEX2A_MAX_MOD_SIZE;
memcpy(zc->speed_rating, CEX2A_SPEED_IDX,
sizeof(CEX2A_SPEED_IDX));
zc->max_exp_bit_length = CEX2A_MAX_MOD_SIZE;
zc->type_string = "CEX2A";
zc->user_space_type = ZCRYPT_CEX2A;
} else if (ac->ap_dev.device_type == AP_DEVICE_TYPE_CEX3A) {
zc->min_mod_size = CEX2A_MIN_MOD_SIZE;
zc->max_mod_size = CEX2A_MAX_MOD_SIZE;
zc->max_exp_bit_length = CEX2A_MAX_MOD_SIZE;
if (ap_test_bit(&ac->functions, AP_FUNC_MEX4K) &&
ap_test_bit(&ac->functions, AP_FUNC_CRT4K)) {
zc->max_mod_size = CEX3A_MAX_MOD_SIZE;
zc->max_exp_bit_length = CEX3A_MAX_MOD_SIZE;
}
memcpy(zc->speed_rating, CEX3A_SPEED_IDX,
sizeof(CEX3A_SPEED_IDX));
zc->type_string = "CEX3A";
zc->user_space_type = ZCRYPT_CEX3A;
} else {
zcrypt_card_free(zc);
return -ENODEV;
}
zc->online = 1;
rc = zcrypt_card_register(zc);
if (rc) {
ac->private = NULL;
zcrypt_card_free(zc);
}
return rc;
}
static void zcrypt_cex2a_card_remove(struct ap_device *ap_dev)
{
struct zcrypt_card *zc = to_ap_card(&ap_dev->device)->private;
if (zc)
zcrypt_card_unregister(zc);
}
static int zcrypt_cex2a_queue_probe(struct ap_device *ap_dev)
{
struct ap_queue *aq = to_ap_queue(&ap_dev->device);
struct zcrypt_queue *zq = NULL;
int rc;
switch (ap_dev->device_type) {
case AP_DEVICE_TYPE_CEX2A:
zq = zcrypt_queue_alloc(CEX2A_MAX_RESPONSE_SIZE);
if (!zq)
return -ENOMEM;
break;
case AP_DEVICE_TYPE_CEX3A:
zq = zcrypt_queue_alloc(CEX3A_MAX_RESPONSE_SIZE);
if (!zq)
return -ENOMEM;
break;
}
if (!zq)
return -ENODEV;
zq->ops = zcrypt_msgtype(MSGTYPE50_NAME, MSGTYPE50_VARIANT_DEFAULT);
zq->queue = aq;
zq->online = 1;
atomic_set(&zq->load, 0);
ap_queue_init_reply(aq, &zq->reply);
aq->request_timeout = CEX2A_CLEANUP_TIME,
aq->private = zq;
rc = zcrypt_queue_register(zq);
if (rc) {
aq->private = NULL;
zcrypt_queue_free(zq);
}
return rc;
}
static void zcrypt_cex2a_queue_remove(struct ap_device *ap_dev)
{
struct ap_queue *aq = to_ap_queue(&ap_dev->device);
struct zcrypt_queue *zq = aq->private;
ap_queue_remove(aq);
if (zq)
zcrypt_queue_unregister(zq);
}
int __init zcrypt_cex2a_init(void)
{
int rc;
rc = ap_driver_register(&zcrypt_cex2a_card_driver,
THIS_MODULE, "cex2acard");
if (rc)
return rc;
rc = ap_driver_register(&zcrypt_cex2a_queue_driver,
THIS_MODULE, "cex2aqueue");
if (rc)
ap_driver_unregister(&zcrypt_cex2a_card_driver);
return rc;
}
void __exit zcrypt_cex2a_exit(void)
{
ap_driver_unregister(&zcrypt_cex2a_queue_driver);
ap_driver_unregister(&zcrypt_cex2a_card_driver);
}
