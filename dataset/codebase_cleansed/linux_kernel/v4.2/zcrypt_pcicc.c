static inline int is_PKCS11_padded(unsigned char *buffer, int length)
{
int i;
if ((buffer[0] != 0x00) || (buffer[1] != 0x01))
return 0;
for (i = 2; i < length; i++)
if (buffer[i] != 0xFF)
break;
if (i < 10 || i == length)
return 0;
if (buffer[i] != 0x00)
return 0;
return 1;
}
static inline int is_PKCS12_padded(unsigned char *buffer, int length)
{
int i;
if ((buffer[0] != 0x00) || (buffer[1] != 0x02))
return 0;
for (i = 2; i < length; i++)
if (buffer[i] == 0x00)
break;
if ((i < 10) || (i == length))
return 0;
if (buffer[i] != 0x00)
return 0;
return 1;
}
static int ICAMEX_msg_to_type6MEX_msg(struct zcrypt_device *zdev,
struct ap_message *ap_msg,
struct ica_rsa_modexpo *mex)
{
static struct type6_hdr static_type6_hdr = {
.type = 0x06,
.offset1 = 0x00000058,
.agent_id = {0x01,0x00,0x43,0x43,0x41,0x2D,0x41,0x50,
0x50,0x4C,0x20,0x20,0x20,0x01,0x01,0x01},
.function_code = {'P','K'},
};
static struct function_and_rules_block static_pke_function_and_rules ={
.function_code = {'P','K'},
.ulen = cpu_to_le16(10),
.only_rule = {'P','K','C','S','-','1','.','2'}
};
struct {
struct type6_hdr hdr;
struct CPRB cprb;
struct function_and_rules_block fr;
unsigned short length;
char text[0];
} __attribute__((packed)) *msg = ap_msg->message;
int vud_len, pad_len, size;
if (copy_from_user(msg->text, mex->inputdata, mex->inputdatalength))
return -EFAULT;
if (is_PKCS11_padded(msg->text, mex->inputdatalength))
return -EINVAL;
msg->hdr = static_type6_hdr;
msg->fr = static_pke_function_and_rules;
if (is_PKCS12_padded(msg->text, mex->inputdatalength)) {
pad_len = strnlen(msg->text + 2, mex->inputdatalength - 2) + 3;
if (pad_len <= 9 || pad_len >= mex->inputdatalength)
return -ENODEV;
vud_len = mex->inputdatalength - pad_len;
memmove(msg->text, msg->text + pad_len, vud_len);
msg->length = cpu_to_le16(vud_len + 2);
size = zcrypt_type6_mex_key_en(mex, msg->text + vud_len, 0);
if (size < 0)
return size;
size += sizeof(*msg) + vud_len;
} else {
vud_len = mex->inputdatalength;
msg->length = cpu_to_le16(2 + vud_len);
msg->hdr.function_code[1] = 'D';
msg->fr.function_code[1] = 'D';
size = zcrypt_type6_mex_key_de(mex, msg->text + vud_len, 0);
if (size < 0)
return size;
size += sizeof(*msg) + vud_len;
}
msg->hdr.ToCardLen1 = (size - sizeof(msg->hdr) + 3) & -4;
msg->hdr.FromCardLen1 = PCICC_MAX_RESPONSE_SIZE - sizeof(msg->hdr);
msg->cprb = static_cprb;
msg->cprb.usage_domain[0]= AP_QID_QUEUE(zdev->ap_dev->qid);
msg->cprb.req_parml = cpu_to_le16(size - sizeof(msg->hdr) -
sizeof(msg->cprb));
msg->cprb.rpl_parml = cpu_to_le16(msg->hdr.FromCardLen1);
ap_msg->length = (size + 3) & -4;
return 0;
}
static int ICACRT_msg_to_type6CRT_msg(struct zcrypt_device *zdev,
struct ap_message *ap_msg,
struct ica_rsa_modexpo_crt *crt)
{
static struct type6_hdr static_type6_hdr = {
.type = 0x06,
.offset1 = 0x00000058,
.agent_id = {0x01,0x00,0x43,0x43,0x41,0x2D,0x41,0x50,
0x50,0x4C,0x20,0x20,0x20,0x01,0x01,0x01},
.function_code = {'P','D'},
};
static struct function_and_rules_block static_pkd_function_and_rules ={
.function_code = {'P','D'},
.ulen = cpu_to_le16(10),
.only_rule = {'P','K','C','S','-','1','.','2'}
};
struct {
struct type6_hdr hdr;
struct CPRB cprb;
struct function_and_rules_block fr;
unsigned short length;
char text[0];
} __attribute__((packed)) *msg = ap_msg->message;
int size;
msg->length = cpu_to_le16(2 + crt->inputdatalength);
if (copy_from_user(msg->text, crt->inputdata, crt->inputdatalength))
return -EFAULT;
if (is_PKCS11_padded(msg->text, crt->inputdatalength))
return -EINVAL;
size = zcrypt_type6_crt_key(crt, msg->text + crt->inputdatalength, 0);
if (size < 0)
return size;
size += sizeof(*msg) + crt->inputdatalength;
msg->hdr = static_type6_hdr;
msg->hdr.ToCardLen1 = (size - sizeof(msg->hdr) + 3) & -4;
msg->hdr.FromCardLen1 = PCICC_MAX_RESPONSE_SIZE - sizeof(msg->hdr);
msg->cprb = static_cprb;
msg->cprb.usage_domain[0] = AP_QID_QUEUE(zdev->ap_dev->qid);
msg->cprb.req_parml = msg->cprb.rpl_parml =
cpu_to_le16(size - sizeof(msg->hdr) - sizeof(msg->cprb));
msg->fr = static_pkd_function_and_rules;
ap_msg->length = (size + 3) & -4;
return 0;
}
static int convert_type86(struct zcrypt_device *zdev,
struct ap_message *reply,
char __user *outputdata,
unsigned int outputdatalength)
{
static unsigned char static_pad[] = {
0x00,0x02,
0x1B,0x7B,0x5D,0xB5,0x75,0x01,0x3D,0xFD,
0x8D,0xD1,0xC7,0x03,0x2D,0x09,0x23,0x57,
0x89,0x49,0xB9,0x3F,0xBB,0x99,0x41,0x5B,
0x75,0x21,0x7B,0x9D,0x3B,0x6B,0x51,0x39,
0xBB,0x0D,0x35,0xB9,0x89,0x0F,0x93,0xA5,
0x0B,0x47,0xF1,0xD3,0xBB,0xCB,0xF1,0x9D,
0x23,0x73,0x71,0xFF,0xF3,0xF5,0x45,0xFB,
0x61,0x29,0x23,0xFD,0xF1,0x29,0x3F,0x7F,
0x17,0xB7,0x1B,0xA9,0x19,0xBD,0x57,0xA9,
0xD7,0x95,0xA3,0xCB,0xED,0x1D,0xDB,0x45,
0x7D,0x11,0xD1,0x51,0x1B,0xED,0x71,0xE9,
0xB1,0xD1,0xAB,0xAB,0x21,0x2B,0x1B,0x9F,
0x3B,0x9F,0xF7,0xF7,0xBD,0x63,0xEB,0xAD,
0xDF,0xB3,0x6F,0x5B,0xDB,0x8D,0xA9,0x5D,
0xE3,0x7D,0x77,0x49,0x47,0xF5,0xA7,0xFD,
0xAB,0x2F,0x27,0x35,0x77,0xD3,0x49,0xC9,
0x09,0xEB,0xB1,0xF9,0xBF,0x4B,0xCB,0x2B,
0xEB,0xEB,0x05,0xFF,0x7D,0xC7,0x91,0x8B,
0x09,0x83,0xB9,0xB9,0x69,0x33,0x39,0x6B,
0x79,0x75,0x19,0xBF,0xBB,0x07,0x1D,0xBD,
0x29,0xBF,0x39,0x95,0x93,0x1D,0x35,0xC7,
0xC9,0x4D,0xE5,0x97,0x0B,0x43,0x9B,0xF1,
0x16,0x93,0x03,0x1F,0xA5,0xFB,0xDB,0xF3,
0x27,0x4F,0x27,0x61,0x05,0x1F,0xB9,0x23,
0x2F,0xC3,0x81,0xA9,0x23,0x71,0x55,0x55,
0xEB,0xED,0x41,0xE5,0xF3,0x11,0xF1,0x43,
0x69,0x03,0xBD,0x0B,0x37,0x0F,0x51,0x8F,
0x0B,0xB5,0x89,0x5B,0x67,0xA9,0xD9,0x4F,
0x01,0xF9,0x21,0x77,0x37,0x73,0x79,0xC5,
0x7F,0x51,0xC1,0xCF,0x97,0xA1,0x75,0xAD,
0x35,0x9D,0xD3,0xD3,0xA7,0x9D,0x5D,0x41,
0x6F,0x65,0x1B,0xCF,0xA9,0x87,0x91,0x09
};
struct type86_reply *msg = reply->message;
unsigned short service_rc, service_rs;
unsigned int reply_len, pad_len;
char *data;
service_rc = le16_to_cpu(msg->cprb.ccp_rtcode);
if (unlikely(service_rc != 0)) {
service_rs = le16_to_cpu(msg->cprb.ccp_rscode);
if (service_rc == 8 && service_rs == 66)
return -EINVAL;
if (service_rc == 8 && service_rs == 65)
return -EINVAL;
if (service_rc == 8 && service_rs == 770) {
zdev->max_mod_size = PCICC_MAX_MOD_SIZE_OLD;
return -EAGAIN;
}
if (service_rc == 8 && service_rs == 783) {
zdev->max_mod_size = PCICC_MAX_MOD_SIZE_OLD;
return -EAGAIN;
}
if (service_rc == 8 && service_rs == 72)
return -EINVAL;
zdev->online = 0;
pr_err("Cryptographic device %x failed and was set offline\n",
zdev->ap_dev->qid);
ZCRYPT_DBF_DEV(DBF_ERR, zdev, "dev%04xo%drc%d",
zdev->ap_dev->qid, zdev->online,
msg->hdr.reply_code);
return -EAGAIN;
}
data = msg->text;
reply_len = le16_to_cpu(msg->length) - 2;
if (reply_len > outputdatalength)
return -EINVAL;
pad_len = outputdatalength - reply_len;
if (pad_len > 0) {
if (pad_len < 10)
return -EINVAL;
if (copy_to_user(outputdata, static_pad, pad_len - 1))
return -EFAULT;
if (put_user(0, outputdata + pad_len - 1))
return -EFAULT;
}
if (copy_to_user(outputdata + pad_len, data, reply_len))
return -EFAULT;
return 0;
}
static int convert_response(struct zcrypt_device *zdev,
struct ap_message *reply,
char __user *outputdata,
unsigned int outputdatalength)
{
struct type86_reply *msg = reply->message;
switch (msg->hdr.type) {
case TYPE82_RSP_CODE:
case TYPE88_RSP_CODE:
return convert_error(zdev, reply);
case TYPE86_RSP_CODE:
if (msg->hdr.reply_code)
return convert_error(zdev, reply);
if (msg->cprb.cprb_ver_id == 0x01)
return convert_type86(zdev, reply,
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
static void zcrypt_pcicc_receive(struct ap_device *ap_dev,
struct ap_message *msg,
struct ap_message *reply)
{
static struct error_hdr error_reply = {
.type = TYPE82_RSP_CODE,
.reply_code = REP82_ERROR_MACHINE_FAILURE,
};
struct type86_reply *t86r;
int length;
if (IS_ERR(reply)) {
memcpy(msg->message, &error_reply, sizeof(error_reply));
goto out;
}
t86r = reply->message;
if (t86r->hdr.type == TYPE86_RSP_CODE &&
t86r->cprb.cprb_ver_id == 0x01) {
length = sizeof(struct type86_reply) + t86r->length - 2;
length = min(PCICC_MAX_RESPONSE_SIZE, length);
memcpy(msg->message, reply->message, length);
} else
memcpy(msg->message, reply->message, sizeof error_reply);
out:
complete((struct completion *) msg->private);
}
static long zcrypt_pcicc_modexpo(struct zcrypt_device *zdev,
struct ica_rsa_modexpo *mex)
{
struct ap_message ap_msg;
struct completion work;
int rc;
ap_init_message(&ap_msg);
ap_msg.message = (void *) get_zeroed_page(GFP_KERNEL);
if (!ap_msg.message)
return -ENOMEM;
ap_msg.receive = zcrypt_pcicc_receive;
ap_msg.length = PAGE_SIZE;
ap_msg.psmid = (((unsigned long long) current->pid) << 32) +
atomic_inc_return(&zcrypt_step);
ap_msg.private = &work;
rc = ICAMEX_msg_to_type6MEX_msg(zdev, &ap_msg, mex);
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
free_page((unsigned long) ap_msg.message);
return rc;
}
static long zcrypt_pcicc_modexpo_crt(struct zcrypt_device *zdev,
struct ica_rsa_modexpo_crt *crt)
{
struct ap_message ap_msg;
struct completion work;
int rc;
ap_init_message(&ap_msg);
ap_msg.message = (void *) get_zeroed_page(GFP_KERNEL);
if (!ap_msg.message)
return -ENOMEM;
ap_msg.receive = zcrypt_pcicc_receive;
ap_msg.length = PAGE_SIZE;
ap_msg.psmid = (((unsigned long long) current->pid) << 32) +
atomic_inc_return(&zcrypt_step);
ap_msg.private = &work;
rc = ICACRT_msg_to_type6CRT_msg(zdev, &ap_msg, crt);
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
free_page((unsigned long) ap_msg.message);
return rc;
}
static int zcrypt_pcicc_probe(struct ap_device *ap_dev)
{
struct zcrypt_device *zdev;
int rc;
zdev = zcrypt_device_alloc(PCICC_MAX_RESPONSE_SIZE);
if (!zdev)
return -ENOMEM;
zdev->ap_dev = ap_dev;
zdev->ops = &zcrypt_pcicc_ops;
zdev->online = 1;
zdev->user_space_type = ZCRYPT_PCICC;
zdev->type_string = "PCICC";
zdev->min_mod_size = PCICC_MIN_MOD_SIZE;
zdev->max_mod_size = PCICC_MAX_MOD_SIZE;
zdev->speed_rating = PCICC_SPEED_RATING;
zdev->max_exp_bit_length = PCICC_MAX_MOD_SIZE;
ap_dev->reply = &zdev->reply;
ap_dev->private = zdev;
rc = zcrypt_device_register(zdev);
if (rc)
goto out_free;
return 0;
out_free:
ap_dev->private = NULL;
zcrypt_device_free(zdev);
return rc;
}
static void zcrypt_pcicc_remove(struct ap_device *ap_dev)
{
struct zcrypt_device *zdev = ap_dev->private;
zcrypt_device_unregister(zdev);
}
int __init zcrypt_pcicc_init(void)
{
return ap_driver_register(&zcrypt_pcicc_driver, THIS_MODULE, "pcicc");
}
void zcrypt_pcicc_exit(void)
{
ap_driver_unregister(&zcrypt_pcicc_driver);
}
