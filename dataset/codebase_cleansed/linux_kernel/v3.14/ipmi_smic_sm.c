static unsigned int init_smic_data(struct si_sm_data *smic,
struct si_sm_io *io)
{
smic->state = SMIC_IDLE;
smic->io = io;
smic->write_pos = 0;
smic->write_count = 0;
smic->orig_write_count = 0;
smic->read_pos = 0;
smic->error_retries = 0;
smic->truncated = 0;
smic->smic_timeout = SMIC_RETRY_TIMEOUT;
return 3;
}
static int start_smic_transaction(struct si_sm_data *smic,
unsigned char *data, unsigned int size)
{
unsigned int i;
if (size < 2)
return IPMI_REQ_LEN_INVALID_ERR;
if (size > MAX_SMIC_WRITE_SIZE)
return IPMI_REQ_LEN_EXCEEDED_ERR;
if ((smic->state != SMIC_IDLE) && (smic->state != SMIC_HOSED))
return IPMI_NOT_IN_MY_STATE_ERR;
if (smic_debug & SMIC_DEBUG_MSG) {
printk(KERN_DEBUG "start_smic_transaction -");
for (i = 0; i < size; i++)
printk(" %02x", (unsigned char) data[i]);
printk("\n");
}
smic->error_retries = 0;
memcpy(smic->write_data, data, size);
smic->write_count = size;
smic->orig_write_count = size;
smic->write_pos = 0;
smic->read_pos = 0;
smic->state = SMIC_START_OP;
smic->smic_timeout = SMIC_RETRY_TIMEOUT;
return 0;
}
static int smic_get_result(struct si_sm_data *smic,
unsigned char *data, unsigned int length)
{
int i;
if (smic_debug & SMIC_DEBUG_MSG) {
printk(KERN_DEBUG "smic_get result -");
for (i = 0; i < smic->read_pos; i++)
printk(" %02x", smic->read_data[i]);
printk("\n");
}
if (length < smic->read_pos) {
smic->read_pos = length;
smic->truncated = 1;
}
memcpy(data, smic->read_data, smic->read_pos);
if ((length >= 3) && (smic->read_pos < 3)) {
data[2] = IPMI_ERR_UNSPECIFIED;
smic->read_pos = 3;
}
if (smic->truncated) {
data[2] = IPMI_ERR_MSG_TRUNCATED;
smic->truncated = 0;
}
return smic->read_pos;
}
static inline unsigned char read_smic_flags(struct si_sm_data *smic)
{
return smic->io->inputb(smic->io, 2);
}
static inline unsigned char read_smic_status(struct si_sm_data *smic)
{
return smic->io->inputb(smic->io, 1);
}
static inline unsigned char read_smic_data(struct si_sm_data *smic)
{
return smic->io->inputb(smic->io, 0);
}
static inline void write_smic_flags(struct si_sm_data *smic,
unsigned char flags)
{
smic->io->outputb(smic->io, 2, flags);
}
static inline void write_smic_control(struct si_sm_data *smic,
unsigned char control)
{
smic->io->outputb(smic->io, 1, control);
}
static inline void write_si_sm_data(struct si_sm_data *smic,
unsigned char data)
{
smic->io->outputb(smic->io, 0, data);
}
static inline void start_error_recovery(struct si_sm_data *smic, char *reason)
{
(smic->error_retries)++;
if (smic->error_retries > SMIC_MAX_ERROR_RETRIES) {
if (smic_debug & SMIC_DEBUG_ENABLE)
printk(KERN_WARNING
"ipmi_smic_drv: smic hosed: %s\n", reason);
smic->state = SMIC_HOSED;
} else {
smic->write_count = smic->orig_write_count;
smic->write_pos = 0;
smic->read_pos = 0;
smic->state = SMIC_START_OP;
smic->smic_timeout = SMIC_RETRY_TIMEOUT;
}
}
static inline void write_next_byte(struct si_sm_data *smic)
{
write_si_sm_data(smic, smic->write_data[smic->write_pos]);
(smic->write_pos)++;
(smic->write_count)--;
}
static inline void read_next_byte(struct si_sm_data *smic)
{
if (smic->read_pos >= MAX_SMIC_READ_SIZE) {
read_smic_data(smic);
smic->truncated = 1;
} else {
smic->read_data[smic->read_pos] = read_smic_data(smic);
smic->read_pos++;
}
}
static enum si_sm_result smic_event(struct si_sm_data *smic, long time)
{
unsigned char status;
unsigned char flags;
unsigned char data;
if (smic->state == SMIC_HOSED) {
init_smic_data(smic, smic->io);
return SI_SM_HOSED;
}
if (smic->state != SMIC_IDLE) {
if (smic_debug & SMIC_DEBUG_STATES)
printk(KERN_DEBUG
"smic_event - smic->smic_timeout = %ld,"
" time = %ld\n",
smic->smic_timeout, time);
if (time < SMIC_RETRY_TIMEOUT) {
smic->smic_timeout -= time;
if (smic->smic_timeout < 0) {
start_error_recovery(smic, "smic timed out.");
return SI_SM_CALL_WITH_DELAY;
}
}
}
flags = read_smic_flags(smic);
if (flags & SMIC_FLAG_BSY)
return SI_SM_CALL_WITH_DELAY;
status = read_smic_status(smic);
if (smic_debug & SMIC_DEBUG_STATES)
printk(KERN_DEBUG
"smic_event - state = %d, flags = 0x%02x,"
" status = 0x%02x\n",
smic->state, flags, status);
switch (smic->state) {
case SMIC_IDLE:
if (flags & SMIC_SMS_DATA_AVAIL)
return SI_SM_ATTN;
return SI_SM_IDLE;
case SMIC_START_OP:
write_smic_control(smic, SMIC_CC_SMS_GET_STATUS);
write_smic_flags(smic, flags | SMIC_FLAG_BSY);
smic->state = SMIC_OP_OK;
break;
case SMIC_OP_OK:
if (status != SMIC_SC_SMS_READY) {
start_error_recovery(smic,
"state = SMIC_OP_OK,"
" status != SMIC_SC_SMS_READY");
return SI_SM_CALL_WITH_DELAY;
}
write_smic_control(smic, SMIC_CC_SMS_WR_START);
write_next_byte(smic);
write_smic_flags(smic, flags | SMIC_FLAG_BSY);
smic->state = SMIC_WRITE_START;
break;
case SMIC_WRITE_START:
if (status != SMIC_SC_SMS_WR_START) {
start_error_recovery(smic,
"state = SMIC_WRITE_START, "
"status != SMIC_SC_SMS_WR_START");
return SI_SM_CALL_WITH_DELAY;
}
if (flags & SMIC_TX_DATA_READY) {
if (smic->write_count == 1) {
write_smic_control(smic, SMIC_CC_SMS_WR_END);
smic->state = SMIC_WRITE_END;
} else {
write_smic_control(smic, SMIC_CC_SMS_WR_NEXT);
smic->state = SMIC_WRITE_NEXT;
}
write_next_byte(smic);
write_smic_flags(smic, flags | SMIC_FLAG_BSY);
} else
return SI_SM_CALL_WITH_DELAY;
break;
case SMIC_WRITE_NEXT:
if (status != SMIC_SC_SMS_WR_NEXT) {
start_error_recovery(smic,
"state = SMIC_WRITE_NEXT, "
"status != SMIC_SC_SMS_WR_NEXT");
return SI_SM_CALL_WITH_DELAY;
}
if (flags & SMIC_TX_DATA_READY) {
if (smic->write_count == 1) {
write_smic_control(smic, SMIC_CC_SMS_WR_END);
smic->state = SMIC_WRITE_END;
} else {
write_smic_control(smic, SMIC_CC_SMS_WR_NEXT);
smic->state = SMIC_WRITE_NEXT;
}
write_next_byte(smic);
write_smic_flags(smic, flags | SMIC_FLAG_BSY);
} else
return SI_SM_CALL_WITH_DELAY;
break;
case SMIC_WRITE_END:
if (status != SMIC_SC_SMS_WR_END) {
start_error_recovery(smic,
"state = SMIC_WRITE_END, "
"status != SMIC_SC_SMS_WR_END");
return SI_SM_CALL_WITH_DELAY;
}
data = read_smic_data(smic);
if (data != 0) {
if (smic_debug & SMIC_DEBUG_ENABLE)
printk(KERN_DEBUG
"SMIC_WRITE_END: data = %02x\n", data);
start_error_recovery(smic,
"state = SMIC_WRITE_END, "
"data != SUCCESS");
return SI_SM_CALL_WITH_DELAY;
} else
smic->state = SMIC_WRITE2READ;
break;
case SMIC_WRITE2READ:
if (flags & SMIC_RX_DATA_READY) {
write_smic_control(smic, SMIC_CC_SMS_RD_START);
write_smic_flags(smic, flags | SMIC_FLAG_BSY);
smic->state = SMIC_READ_START;
} else
return SI_SM_CALL_WITH_DELAY;
break;
case SMIC_READ_START:
if (status != SMIC_SC_SMS_RD_START) {
start_error_recovery(smic,
"state = SMIC_READ_START, "
"status != SMIC_SC_SMS_RD_START");
return SI_SM_CALL_WITH_DELAY;
}
if (flags & SMIC_RX_DATA_READY) {
read_next_byte(smic);
write_smic_control(smic, SMIC_CC_SMS_RD_NEXT);
write_smic_flags(smic, flags | SMIC_FLAG_BSY);
smic->state = SMIC_READ_NEXT;
} else
return SI_SM_CALL_WITH_DELAY;
break;
case SMIC_READ_NEXT:
switch (status) {
case SMIC_SC_SMS_RD_END:
read_next_byte(smic);
write_smic_control(smic, SMIC_CC_SMS_RD_END);
write_smic_flags(smic, flags | SMIC_FLAG_BSY);
smic->state = SMIC_READ_END;
break;
case SMIC_SC_SMS_RD_NEXT:
if (flags & SMIC_RX_DATA_READY) {
read_next_byte(smic);
write_smic_control(smic, SMIC_CC_SMS_RD_NEXT);
write_smic_flags(smic, flags | SMIC_FLAG_BSY);
smic->state = SMIC_READ_NEXT;
} else
return SI_SM_CALL_WITH_DELAY;
break;
default:
start_error_recovery(
smic,
"state = SMIC_READ_NEXT, "
"status != SMIC_SC_SMS_RD_(NEXT|END)");
return SI_SM_CALL_WITH_DELAY;
}
break;
case SMIC_READ_END:
if (status != SMIC_SC_SMS_READY) {
start_error_recovery(smic,
"state = SMIC_READ_END, "
"status != SMIC_SC_SMS_READY");
return SI_SM_CALL_WITH_DELAY;
}
data = read_smic_data(smic);
if (data != 0) {
if (smic_debug & SMIC_DEBUG_ENABLE)
printk(KERN_DEBUG
"SMIC_READ_END: data = %02x\n", data);
start_error_recovery(smic,
"state = SMIC_READ_END, "
"data != SUCCESS");
return SI_SM_CALL_WITH_DELAY;
} else {
smic->state = SMIC_IDLE;
return SI_SM_TRANSACTION_COMPLETE;
}
case SMIC_HOSED:
init_smic_data(smic, smic->io);
return SI_SM_HOSED;
default:
if (smic_debug & SMIC_DEBUG_ENABLE) {
printk(KERN_DEBUG "smic->state = %d\n", smic->state);
start_error_recovery(smic, "state = UNKNOWN");
return SI_SM_CALL_WITH_DELAY;
}
}
smic->smic_timeout = SMIC_RETRY_TIMEOUT;
return SI_SM_CALL_WITHOUT_DELAY;
}
static int smic_detect(struct si_sm_data *smic)
{
if (read_smic_flags(smic) == 0xff)
return 1;
return 0;
}
static void smic_cleanup(struct si_sm_data *kcs)
{
}
static int smic_size(void)
{
return sizeof(struct si_sm_data);
}
