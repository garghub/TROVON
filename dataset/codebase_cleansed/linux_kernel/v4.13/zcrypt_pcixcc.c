static int zcrypt_pcixcc_rng_supported(struct ap_queue *aq)
{
struct ap_message ap_msg;
unsigned long long psmid;
unsigned int domain;
struct {
struct type86_hdr hdr;
struct type86_fmt2_ext fmt2;
struct CPRBX cprbx;
} __attribute__((packed)) *reply;
struct {
struct type6_hdr hdr;
struct CPRBX cprbx;
char function_code[2];
short int rule_length;
char rule[8];
short int verb_length;
short int key_length;
} __packed * msg;
int rc, i;
ap_init_message(&ap_msg);
ap_msg.message = (void *) get_zeroed_page(GFP_KERNEL);
if (!ap_msg.message)
return -ENOMEM;
rng_type6CPRB_msgX(&ap_msg, 4, &domain);
msg = ap_msg.message;
msg->cprbx.domain = AP_QID_QUEUE(aq->qid);
rc = ap_send(aq->qid, 0x0102030405060708ULL, ap_msg.message,
ap_msg.length);
if (rc)
goto out_free;
for (i = 0; i < 2 * HZ; i++) {
msleep(1000 / HZ);
rc = ap_recv(aq->qid, &psmid, ap_msg.message, 4096);
if (rc == 0 && psmid == 0x0102030405060708ULL)
break;
}
if (i >= 2 * HZ) {
rc = -ENODEV;
goto out_free;
}
reply = ap_msg.message;
if (reply->cprbx.ccp_rtcode == 0 && reply->cprbx.ccp_rscode == 0)
rc = 1;
else
rc = 0;
out_free:
free_page((unsigned long) ap_msg.message);
return rc;
}
static int zcrypt_pcixcc_card_probe(struct ap_device *ap_dev)
{
static const int CEX2C_SPEED_IDX[] = {
1000, 1400, 2400, 1100, 1500, 2600, 100, 12};
static const int CEX3C_SPEED_IDX[] = {
500, 700, 1400, 550, 800, 1500, 80, 10};
struct ap_card *ac = to_ap_card(&ap_dev->device);
struct zcrypt_card *zc;
int rc = 0;
zc = zcrypt_card_alloc();
if (!zc)
return -ENOMEM;
zc->card = ac;
ac->private = zc;
switch (ac->ap_dev.device_type) {
case AP_DEVICE_TYPE_CEX2C:
zc->user_space_type = ZCRYPT_CEX2C;
zc->type_string = "CEX2C";
memcpy(zc->speed_rating, CEX2C_SPEED_IDX,
sizeof(CEX2C_SPEED_IDX));
zc->min_mod_size = PCIXCC_MIN_MOD_SIZE;
zc->max_mod_size = PCIXCC_MAX_MOD_SIZE;
zc->max_exp_bit_length = PCIXCC_MAX_MOD_SIZE;
break;
case AP_DEVICE_TYPE_CEX3C:
zc->user_space_type = ZCRYPT_CEX3C;
zc->type_string = "CEX3C";
memcpy(zc->speed_rating, CEX3C_SPEED_IDX,
sizeof(CEX3C_SPEED_IDX));
zc->min_mod_size = CEX3C_MIN_MOD_SIZE;
zc->max_mod_size = CEX3C_MAX_MOD_SIZE;
zc->max_exp_bit_length = CEX3C_MAX_MOD_SIZE;
break;
default:
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
static void zcrypt_pcixcc_card_remove(struct ap_device *ap_dev)
{
struct zcrypt_card *zc = to_ap_card(&ap_dev->device)->private;
if (zc)
zcrypt_card_unregister(zc);
}
static int zcrypt_pcixcc_queue_probe(struct ap_device *ap_dev)
{
struct ap_queue *aq = to_ap_queue(&ap_dev->device);
struct zcrypt_queue *zq;
int rc;
zq = zcrypt_queue_alloc(PCIXCC_MAX_XCRB_MESSAGE_SIZE);
if (!zq)
return -ENOMEM;
zq->queue = aq;
zq->online = 1;
atomic_set(&zq->load, 0);
rc = zcrypt_pcixcc_rng_supported(aq);
if (rc < 0) {
zcrypt_queue_free(zq);
return rc;
}
if (rc)
zq->ops = zcrypt_msgtype(MSGTYPE06_NAME,
MSGTYPE06_VARIANT_DEFAULT);
else
zq->ops = zcrypt_msgtype(MSGTYPE06_NAME,
MSGTYPE06_VARIANT_NORNG);
ap_queue_init_reply(aq, &zq->reply);
aq->request_timeout = PCIXCC_CLEANUP_TIME,
aq->private = zq;
rc = zcrypt_queue_register(zq);
if (rc) {
aq->private = NULL;
zcrypt_queue_free(zq);
}
return rc;
}
static void zcrypt_pcixcc_queue_remove(struct ap_device *ap_dev)
{
struct ap_queue *aq = to_ap_queue(&ap_dev->device);
struct zcrypt_queue *zq = aq->private;
ap_queue_remove(aq);
if (zq)
zcrypt_queue_unregister(zq);
}
int __init zcrypt_pcixcc_init(void)
{
int rc;
rc = ap_driver_register(&zcrypt_pcixcc_card_driver,
THIS_MODULE, "pcixcccard");
if (rc)
return rc;
rc = ap_driver_register(&zcrypt_pcixcc_queue_driver,
THIS_MODULE, "pcixccqueue");
if (rc)
ap_driver_unregister(&zcrypt_pcixcc_card_driver);
return rc;
}
void zcrypt_pcixcc_exit(void)
{
ap_driver_unregister(&zcrypt_pcixcc_queue_driver);
ap_driver_unregister(&zcrypt_pcixcc_card_driver);
}
