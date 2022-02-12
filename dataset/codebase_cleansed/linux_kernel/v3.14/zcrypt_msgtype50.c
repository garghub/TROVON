static int ICAMEX_msg_to_type50MEX_msg(struct zcrypt_device *zdev,
struct ap_message *ap_msg,
struct ica_rsa_modexpo *mex)
{
unsigned char *mod, *exp, *inp;
int mod_len;
mod_len = mex->inputdatalength;
if (mod_len <= 128) {
struct type50_meb1_msg *meb1 = ap_msg->message;
memset(meb1, 0, sizeof(*meb1));
ap_msg->length = sizeof(*meb1);
meb1->header.msg_type_code = TYPE50_TYPE_CODE;
meb1->header.msg_len = sizeof(*meb1);
meb1->keyblock_type = TYPE50_MEB1_FMT;
mod = meb1->modulus + sizeof(meb1->modulus) - mod_len;
exp = meb1->exponent + sizeof(meb1->exponent) - mod_len;
inp = meb1->message + sizeof(meb1->message) - mod_len;
} else if (mod_len <= 256) {
struct type50_meb2_msg *meb2 = ap_msg->message;
memset(meb2, 0, sizeof(*meb2));
ap_msg->length = sizeof(*meb2);
meb2->header.msg_type_code = TYPE50_TYPE_CODE;
meb2->header.msg_len = sizeof(*meb2);
meb2->keyblock_type = TYPE50_MEB2_FMT;
mod = meb2->modulus + sizeof(meb2->modulus) - mod_len;
exp = meb2->exponent + sizeof(meb2->exponent) - mod_len;
inp = meb2->message + sizeof(meb2->message) - mod_len;
} else {
struct type50_meb3_msg *meb3 = ap_msg->message;
memset(meb3, 0, sizeof(*meb3));
ap_msg->length = sizeof(*meb3);
meb3->header.msg_type_code = TYPE50_TYPE_CODE;
meb3->header.msg_len = sizeof(*meb3);
meb3->keyblock_type = TYPE50_MEB3_FMT;
mod = meb3->modulus + sizeof(meb3->modulus) - mod_len;
exp = meb3->exponent + sizeof(meb3->exponent) - mod_len;
inp = meb3->message + sizeof(meb3->message) - mod_len;
}
if (copy_from_user(mod, mex->n_modulus, mod_len) ||
copy_from_user(exp, mex->b_key, mod_len) ||
copy_from_user(inp, mex->inputdata, mod_len))
return -EFAULT;
return 0;
}
static int ICACRT_msg_to_type50CRT_msg(struct zcrypt_device *zdev,
struct ap_message *ap_msg,
struct ica_rsa_modexpo_crt *crt)
{
int mod_len, short_len;
unsigned char *p, *q, *dp, *dq, *u, *inp;
mod_len = crt->inputdatalength;
short_len = mod_len / 2;
if (mod_len <= 128) {
struct type50_crb1_msg *crb1 = ap_msg->message;
memset(crb1, 0, sizeof(*crb1));
ap_msg->length = sizeof(*crb1);
crb1->header.msg_type_code = TYPE50_TYPE_CODE;
crb1->header.msg_len = sizeof(*crb1);
crb1->keyblock_type = TYPE50_CRB1_FMT;
p = crb1->p + sizeof(crb1->p) - short_len;
q = crb1->q + sizeof(crb1->q) - short_len;
dp = crb1->dp + sizeof(crb1->dp) - short_len;
dq = crb1->dq + sizeof(crb1->dq) - short_len;
u = crb1->u + sizeof(crb1->u) - short_len;
inp = crb1->message + sizeof(crb1->message) - mod_len;
} else if (mod_len <= 256) {
struct type50_crb2_msg *crb2 = ap_msg->message;
memset(crb2, 0, sizeof(*crb2));
ap_msg->length = sizeof(*crb2);
crb2->header.msg_type_code = TYPE50_TYPE_CODE;
crb2->header.msg_len = sizeof(*crb2);
crb2->keyblock_type = TYPE50_CRB2_FMT;
p = crb2->p + sizeof(crb2->p) - short_len;
q = crb2->q + sizeof(crb2->q) - short_len;
dp = crb2->dp + sizeof(crb2->dp) - short_len;
dq = crb2->dq + sizeof(crb2->dq) - short_len;
u = crb2->u + sizeof(crb2->u) - short_len;
inp = crb2->message + sizeof(crb2->message) - mod_len;
} else if ((mod_len <= 512) &&
(zdev->max_mod_size == CEX3A_MAX_MOD_SIZE)) {
struct type50_crb3_msg *crb3 = ap_msg->message;
memset(crb3, 0, sizeof(*crb3));
ap_msg->length = sizeof(*crb3);
crb3->header.msg_type_code = TYPE50_TYPE_CODE;
crb3->header.msg_len = sizeof(*crb3);
crb3->keyblock_type = TYPE50_CRB3_FMT;
p = crb3->p + sizeof(crb3->p) - short_len;
q = crb3->q + sizeof(crb3->q) - short_len;
dp = crb3->dp + sizeof(crb3->dp) - short_len;
dq = crb3->dq + sizeof(crb3->dq) - short_len;
u = crb3->u + sizeof(crb3->u) - short_len;
inp = crb3->message + sizeof(crb3->message) - mod_len;
} else
return -EINVAL;
if (copy_from_user(p, crt->np_prime + MSGTYPE_ADJUSTMENT, short_len) ||
copy_from_user(q, crt->nq_prime, short_len) ||
copy_from_user(dp, crt->bp_key + MSGTYPE_ADJUSTMENT, short_len) ||
copy_from_user(dq, crt->bq_key, short_len) ||
copy_from_user(u, crt->u_mult_inv + MSGTYPE_ADJUSTMENT, short_len) ||
copy_from_user(inp, crt->inputdata, mod_len))
return -EFAULT;
return 0;
}
static int convert_type80(struct zcrypt_device *zdev,
struct ap_message *reply,
char __user *outputdata,
unsigned int outputdatalength)
{
struct type80_hdr *t80h = reply->message;
unsigned char *data;
if (t80h->len < sizeof(*t80h) + outputdatalength) {
zdev->online = 0;
pr_err("Cryptographic device %x failed and was set offline\n",
zdev->ap_dev->qid);
ZCRYPT_DBF_DEV(DBF_ERR, zdev, "dev%04xo%drc%d",
zdev->ap_dev->qid, zdev->online, t80h->code);
return -EAGAIN;
}
if (zdev->user_space_type == ZCRYPT_CEX2A)
BUG_ON(t80h->len > CEX2A_MAX_RESPONSE_SIZE);
else
BUG_ON(t80h->len > CEX3A_MAX_RESPONSE_SIZE);
data = reply->message + t80h->len - outputdatalength;
if (copy_to_user(outputdata, data, outputdatalength))
return -EFAULT;
return 0;
}
static int convert_response(struct zcrypt_device *zdev,
struct ap_message *reply,
char __user *outputdata,
unsigned int outputdatalength)
{
switch (((unsigned char *) reply->message)[1]) {
case TYPE82_RSP_CODE:
case TYPE88_RSP_CODE:
return convert_error(zdev, reply);
case TYPE80_RSP_CODE:
return convert_type80(zdev, reply,
outputdata, outputdatalength);
default:
zdev->online = 0;
pr_err("Cryptographic device %x failed and was set offline\n",
zdev->ap_dev->qid);
ZCRYPT_DBF_DEV(DBF_ERR, zdev, "dev%04xo%dfail",
zdev->ap_dev->qid, zdev->online);
return -EAGAIN;
}
}
static void zcrypt_cex2a_receive(struct ap_device *ap_dev,
struct ap_message *msg,
struct ap_message *reply)
{
static struct error_hdr error_reply = {
.type = TYPE82_RSP_CODE,
.reply_code = REP82_ERROR_MACHINE_FAILURE,
};
struct type80_hdr *t80h;
int length;
if (IS_ERR(reply)) {
memcpy(msg->message, &error_reply, sizeof(error_reply));
goto out;
}
t80h = reply->message;
if (t80h->type == TYPE80_RSP_CODE) {
if (ap_dev->device_type == AP_DEVICE_TYPE_CEX2A)
length = min_t(int,
CEX2A_MAX_RESPONSE_SIZE, t80h->len);
else
length = min_t(int,
CEX3A_MAX_RESPONSE_SIZE, t80h->len);
memcpy(msg->message, reply->message, length);
} else
memcpy(msg->message, reply->message, sizeof(error_reply));
out:
complete((struct completion *) msg->private);
}
static long zcrypt_cex2a_modexpo(struct zcrypt_device *zdev,
struct ica_rsa_modexpo *mex)
{
struct ap_message ap_msg;
struct completion work;
int rc;
ap_init_message(&ap_msg);
if (zdev->user_space_type == ZCRYPT_CEX2A)
ap_msg.message = kmalloc(MSGTYPE50_CRB2_MAX_MSG_SIZE,
GFP_KERNEL);
else
ap_msg.message = kmalloc(MSGTYPE50_CRB3_MAX_MSG_SIZE,
GFP_KERNEL);
if (!ap_msg.message)
return -ENOMEM;
ap_msg.receive = zcrypt_cex2a_receive;
ap_msg.psmid = (((unsigned long long) current->pid) << 32) +
atomic_inc_return(&zcrypt_step);
ap_msg.private = &work;
rc = ICAMEX_msg_to_type50MEX_msg(zdev, &ap_msg, mex);
if (rc)
goto out_free;
init_completion(&work);
ap_queue_message(zdev->ap_dev, &ap_msg);
rc = wait_for_completion_interruptible(&work);
if (rc == 0)
rc = convert_response(zdev, &ap_msg, mex->outputdata,
mex->outputdatalength);
else
ap_cancel_message(zdev->ap_dev, &ap_msg);
out_free:
kfree(ap_msg.message);
return rc;
}
static long zcrypt_cex2a_modexpo_crt(struct zcrypt_device *zdev,
struct ica_rsa_modexpo_crt *crt)
{
struct ap_message ap_msg;
struct completion work;
int rc;
ap_init_message(&ap_msg);
if (zdev->user_space_type == ZCRYPT_CEX2A)
ap_msg.message = kmalloc(MSGTYPE50_CRB2_MAX_MSG_SIZE,
GFP_KERNEL);
else
ap_msg.message = kmalloc(MSGTYPE50_CRB3_MAX_MSG_SIZE,
GFP_KERNEL);
if (!ap_msg.message)
return -ENOMEM;
ap_msg.receive = zcrypt_cex2a_receive;
ap_msg.psmid = (((unsigned long long) current->pid) << 32) +
atomic_inc_return(&zcrypt_step);
ap_msg.private = &work;
rc = ICACRT_msg_to_type50CRT_msg(zdev, &ap_msg, crt);
if (rc)
goto out_free;
init_completion(&work);
ap_queue_message(zdev->ap_dev, &ap_msg);
rc = wait_for_completion_interruptible(&work);
if (rc == 0)
rc = convert_response(zdev, &ap_msg, crt->outputdata,
crt->outputdatalength);
else
ap_cancel_message(zdev->ap_dev, &ap_msg);
out_free:
kfree(ap_msg.message);
return rc;
}
int __init zcrypt_msgtype50_init(void)
{
zcrypt_msgtype_register(&zcrypt_msgtype50_ops);
return 0;
}
void __exit zcrypt_msgtype50_exit(void)
{
zcrypt_msgtype_unregister(&zcrypt_msgtype50_ops);
}
