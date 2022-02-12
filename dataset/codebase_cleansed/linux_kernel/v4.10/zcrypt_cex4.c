static int zcrypt_cex4_card_probe(struct ap_device *ap_dev)
{
static const int CEX4A_SPEED_IDX[] = {
5, 6, 59, 20, 115, 581, 0, 0};
static const int CEX5A_SPEED_IDX[] = {
3, 3, 6, 8, 32, 218, 0, 0};
static const int CEX4C_SPEED_IDX[] = {
24, 25, 82, 41, 138, 1111, 79, 8};
static const int CEX5C_SPEED_IDX[] = {
10, 14, 23, 17, 45, 242, 63, 4};
static const int CEX4P_SPEED_IDX[] = {
142, 198, 1852, 203, 331, 1563, 0, 8};
static const int CEX5P_SPEED_IDX[] = {
49, 67, 131, 52, 85, 287, 0, 4};
struct ap_card *ac = to_ap_card(&ap_dev->device);
struct zcrypt_card *zc;
int rc = 0;
zc = zcrypt_card_alloc();
if (!zc)
return -ENOMEM;
zc->card = ac;
ac->private = zc;
if (ap_test_bit(&ac->functions, AP_FUNC_ACCEL)) {
if (ac->ap_dev.device_type == AP_DEVICE_TYPE_CEX4) {
zc->type_string = "CEX4A";
zc->user_space_type = ZCRYPT_CEX4;
memcpy(zc->speed_rating, CEX4A_SPEED_IDX,
sizeof(CEX4A_SPEED_IDX));
} else {
zc->type_string = "CEX5A";
zc->user_space_type = ZCRYPT_CEX5;
memcpy(zc->speed_rating, CEX5A_SPEED_IDX,
sizeof(CEX5A_SPEED_IDX));
}
zc->min_mod_size = CEX4A_MIN_MOD_SIZE;
if (ap_test_bit(&ac->functions, AP_FUNC_MEX4K) &&
ap_test_bit(&ac->functions, AP_FUNC_CRT4K)) {
zc->max_mod_size = CEX4A_MAX_MOD_SIZE_4K;
zc->max_exp_bit_length =
CEX4A_MAX_MOD_SIZE_4K;
} else {
zc->max_mod_size = CEX4A_MAX_MOD_SIZE_2K;
zc->max_exp_bit_length =
CEX4A_MAX_MOD_SIZE_2K;
}
} else if (ap_test_bit(&ac->functions, AP_FUNC_COPRO)) {
if (ac->ap_dev.device_type == AP_DEVICE_TYPE_CEX4) {
zc->type_string = "CEX4C";
zc->user_space_type = ZCRYPT_CEX3C;
memcpy(zc->speed_rating, CEX4C_SPEED_IDX,
sizeof(CEX4C_SPEED_IDX));
} else {
zc->type_string = "CEX5C";
zc->user_space_type = ZCRYPT_CEX3C;
memcpy(zc->speed_rating, CEX5C_SPEED_IDX,
sizeof(CEX5C_SPEED_IDX));
}
zc->min_mod_size = CEX4C_MIN_MOD_SIZE;
zc->max_mod_size = CEX4C_MAX_MOD_SIZE;
zc->max_exp_bit_length = CEX4C_MAX_MOD_SIZE;
} else if (ap_test_bit(&ac->functions, AP_FUNC_EP11)) {
if (ac->ap_dev.device_type == AP_DEVICE_TYPE_CEX4) {
zc->type_string = "CEX4P";
zc->user_space_type = ZCRYPT_CEX4;
memcpy(zc->speed_rating, CEX4P_SPEED_IDX,
sizeof(CEX4P_SPEED_IDX));
} else {
zc->type_string = "CEX5P";
zc->user_space_type = ZCRYPT_CEX5;
memcpy(zc->speed_rating, CEX5P_SPEED_IDX,
sizeof(CEX5P_SPEED_IDX));
}
zc->min_mod_size = CEX4C_MIN_MOD_SIZE;
zc->max_mod_size = CEX4C_MAX_MOD_SIZE;
zc->max_exp_bit_length = CEX4C_MAX_MOD_SIZE;
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
static void zcrypt_cex4_card_remove(struct ap_device *ap_dev)
{
struct zcrypt_card *zc = to_ap_card(&ap_dev->device)->private;
if (zc)
zcrypt_card_unregister(zc);
}
static int zcrypt_cex4_queue_probe(struct ap_device *ap_dev)
{
struct ap_queue *aq = to_ap_queue(&ap_dev->device);
struct zcrypt_queue *zq;
int rc;
if (ap_test_bit(&aq->card->functions, AP_FUNC_ACCEL)) {
zq = zcrypt_queue_alloc(CEX4A_MAX_MESSAGE_SIZE);
if (!zq)
return -ENOMEM;
zq->ops = zcrypt_msgtype(MSGTYPE50_NAME,
MSGTYPE50_VARIANT_DEFAULT);
} else if (ap_test_bit(&aq->card->functions, AP_FUNC_COPRO)) {
zq = zcrypt_queue_alloc(CEX4C_MAX_MESSAGE_SIZE);
if (!zq)
return -ENOMEM;
zq->ops = zcrypt_msgtype(MSGTYPE06_NAME,
MSGTYPE06_VARIANT_DEFAULT);
} else if (ap_test_bit(&aq->card->functions, AP_FUNC_EP11)) {
zq = zcrypt_queue_alloc(CEX4C_MAX_MESSAGE_SIZE);
if (!zq)
return -ENOMEM;
zq->ops = zcrypt_msgtype(MSGTYPE06_NAME,
MSGTYPE06_VARIANT_EP11);
} else {
return -ENODEV;
}
zq->queue = aq;
zq->online = 1;
atomic_set(&zq->load, 0);
ap_queue_init_reply(aq, &zq->reply);
aq->request_timeout = CEX4_CLEANUP_TIME,
aq->private = zq;
rc = zcrypt_queue_register(zq);
if (rc) {
aq->private = NULL;
zcrypt_queue_free(zq);
}
return rc;
}
static void zcrypt_cex4_queue_remove(struct ap_device *ap_dev)
{
struct ap_queue *aq = to_ap_queue(&ap_dev->device);
struct zcrypt_queue *zq = aq->private;
ap_queue_remove(aq);
if (zq)
zcrypt_queue_unregister(zq);
}
int __init zcrypt_cex4_init(void)
{
int rc;
rc = ap_driver_register(&zcrypt_cex4_card_driver,
THIS_MODULE, "cex4card");
if (rc)
return rc;
rc = ap_driver_register(&zcrypt_cex4_queue_driver,
THIS_MODULE, "cex4queue");
if (rc)
ap_driver_unregister(&zcrypt_cex4_card_driver);
return rc;
}
void __exit zcrypt_cex4_exit(void)
{
ap_driver_unregister(&zcrypt_cex4_queue_driver);
ap_driver_unregister(&zcrypt_cex4_card_driver);
}
