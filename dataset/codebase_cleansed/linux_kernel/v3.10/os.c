CsrResult
unifi_net_data_malloc(void *ospriv, bulk_data_desc_t *bulk_data_slot, unsigned int size)
{
struct sk_buff *skb;
unifi_priv_t *priv = (unifi_priv_t*)ospriv;
int rounded_length;
if (priv->card_info.sdio_block_size == 0) {
unifi_error(priv, "unifi_net_data_malloc: Invalid SDIO block size\n");
return CSR_RESULT_FAILURE;
}
rounded_length = (size + priv->card_info.sdio_block_size - 1) & ~(priv->card_info.sdio_block_size - 1);
skb = dev_alloc_skb(rounded_length + 2 + ETH_HLEN + CSR_WIFI_ALIGN_BYTES);
if (! skb) {
unifi_error(ospriv, "alloc_skb failed.\n");
bulk_data_slot->os_net_buf_ptr = NULL;
bulk_data_slot->net_buf_length = 0;
bulk_data_slot->os_data_ptr = NULL;
bulk_data_slot->data_length = 0;
return CSR_RESULT_FAILURE;
}
bulk_data_slot->os_net_buf_ptr = (const unsigned char*)skb;
bulk_data_slot->net_buf_length = rounded_length + 2 + ETH_HLEN + CSR_WIFI_ALIGN_BYTES;
bulk_data_slot->os_data_ptr = (const void*)skb->data;
bulk_data_slot->data_length = size;
return CSR_RESULT_SUCCESS;
}
void
unifi_net_data_free(void *ospriv, bulk_data_desc_t *bulk_data_slot)
{
struct sk_buff *skb;
CSR_UNUSED(ospriv);
skb = (struct sk_buff *)bulk_data_slot->os_net_buf_ptr;
dev_kfree_skb(skb);
bulk_data_slot->net_buf_length = 0;
bulk_data_slot->data_length = 0;
bulk_data_slot->os_data_ptr = bulk_data_slot->os_net_buf_ptr = NULL;
}
CsrResult
unifi_net_dma_align(void *ospriv, bulk_data_desc_t *bulk_data_slot)
{
struct sk_buff *skb;
unsigned long buf_address;
int offset;
unifi_priv_t *priv = (unifi_priv_t*)ospriv;
if ((bulk_data_slot == NULL) || (CSR_WIFI_ALIGN_BYTES == 0)) {
return CSR_RESULT_SUCCESS;
}
if ((bulk_data_slot->os_data_ptr == NULL) || (bulk_data_slot->data_length == 0)) {
return CSR_RESULT_SUCCESS;
}
buf_address = (unsigned long)(bulk_data_slot->os_data_ptr) & (CSR_WIFI_ALIGN_BYTES - 1);
unifi_trace(priv, UDBG5,
"unifi_net_dma_align: Allign buffer (0x%p) by %d bytes\n",
bulk_data_slot->os_data_ptr, buf_address);
offset = CSR_WIFI_ALIGN_BYTES - buf_address;
if (offset < 0) {
unifi_error(priv, "unifi_net_dma_align: Failed (offset=%d)\n", offset);
return CSR_RESULT_FAILURE;
}
skb = (struct sk_buff*)(bulk_data_slot->os_net_buf_ptr);
skb_reserve(skb, offset);
bulk_data_slot->os_net_buf_ptr = (const unsigned char*)skb;
bulk_data_slot->os_data_ptr = (const void*)(skb->data);
return CSR_RESULT_SUCCESS;
}
char* print_time(void )
{
unsigned long long t;
unsigned long nanosec_rem;
t = cpu_clock(printk_cpu);
nanosec_rem = do_div(t, 1000000000);
sprintf(tbuf, "[%5lu.%06lu] ",
(unsigned long) t,
nanosec_rem / 1000);
return tbuf;
}
void
unifi_error(void* ospriv, const char *fmt, ...)
{
unifi_priv_t *priv = (unifi_priv_t*) ospriv;
char s[DEBUG_BUFFER_SIZE];
va_list args;
unsigned int len;
#ifdef ANDROID_TIMESTAMP
if (priv != NULL) {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_ERR "%s unifi%d: ", print_time(), priv->instance);
} else {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_ERR "%s unifi: ", print_time());
}
#else
if (priv != NULL) {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_ERR "unifi%d: ", priv->instance);
} else {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_ERR "unifi: ");
}
#endif
FORMAT_TRACE(s, len, args, fmt);
printk("%s", s);
}
void
unifi_warning(void* ospriv, const char *fmt, ...)
{
unifi_priv_t *priv = (unifi_priv_t*) ospriv;
char s[DEBUG_BUFFER_SIZE];
va_list args;
unsigned int len;
#ifdef ANDROID_TIMESTAMP
if (priv != NULL) {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_WARNING "%s unifi%d: ", print_time(), priv->instance);
} else {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_WARNING "%s unifi: ", print_time());
}
#else
if (priv != NULL) {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_WARNING "unifi%d: ", priv->instance);
} else {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_WARNING "unifi: ");
}
#endif
FORMAT_TRACE(s, len, args, fmt);
printk("%s", s);
}
void
unifi_notice(void* ospriv, const char *fmt, ...)
{
unifi_priv_t *priv = (unifi_priv_t*) ospriv;
char s[DEBUG_BUFFER_SIZE];
va_list args;
unsigned int len;
#ifdef ANDROID_TIMESTAMP
if (priv != NULL) {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_NOTICE "%s unifi%d: ", print_time(), priv->instance);
} else {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_NOTICE "%s unifi: ", print_time());
}
#else
if (priv != NULL) {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_NOTICE "unifi%d: ", priv->instance);
} else {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_NOTICE "unifi: ");
}
#endif
FORMAT_TRACE(s, len, args, fmt);
printk("%s", s);
}
void
unifi_info(void* ospriv, const char *fmt, ...)
{
unifi_priv_t *priv = (unifi_priv_t*) ospriv;
char s[DEBUG_BUFFER_SIZE];
va_list args;
unsigned int len;
#ifdef ANDROID_TIMESTAMP
if (priv != NULL) {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_INFO "%s unifi%d: ", print_time(), priv->instance);
} else {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_INFO "%s unifi: ", print_time());
}
#else
if (priv != NULL) {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_INFO "unifi%d: ", priv->instance);
} else {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_INFO "unifi: ");
}
#endif
FORMAT_TRACE(s, len, args, fmt);
printk("%s", s);
}
void
unifi_trace(void* ospriv, int level, const char *fmt, ...)
{
unifi_priv_t *priv = (unifi_priv_t*) ospriv;
char s[DEBUG_BUFFER_SIZE];
va_list args;
unsigned int len;
if (unifi_debug >= level) {
#ifdef ANDROID_TIMESTAMP
if (priv != NULL) {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_ERR "%s unifi%d: ", print_time(), priv->instance);
} else {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_ERR "%s unifi: ", print_time());
}
#else
if (priv != NULL) {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_ERR "unifi%d: ", priv->instance);
} else {
len = snprintf(s, DEBUG_BUFFER_SIZE, KERN_ERR "unifi: ");
}
#endif
FORMAT_TRACE(s, len, args, fmt);
printk("%s", s);
}
}
void
unifi_error_nop(void* ospriv, const char *fmt, ...)
{
}
void
unifi_trace_nop(void* ospriv, int level, const char *fmt, ...)
{
}
void
unifi_dump(void *ospriv, int level, const char *msg, void *mem, u16 len)
{
unifi_priv_t *priv = (unifi_priv_t*) ospriv;
if (unifi_debug >= level) {
#ifdef ANDROID_TIMESTAMP
if (priv != NULL) {
printk(KERN_ERR "%s unifi%d: --- dump: %s ---\n", print_time(), priv->instance, msg ? msg : "");
} else {
printk(KERN_ERR "%s unifi: --- dump: %s ---\n", print_time(), msg ? msg : "");
}
#else
if (priv != NULL) {
printk(KERN_ERR "unifi%d: --- dump: %s ---\n", priv->instance, msg ? msg : "");
} else {
printk(KERN_ERR "unifi: --- dump: %s ---\n", msg ? msg : "");
}
#endif
dump(mem, len);
if (priv != NULL) {
printk(KERN_ERR "unifi%d: --- end of dump ---\n", priv->instance);
} else {
printk(KERN_ERR "unifi: --- end of dump ---\n");
}
}
}
void
dump(void *mem, u16 len)
{
int i, col = 0;
unsigned char *pdata = (unsigned char *)mem;
#ifdef ANDROID_TIMESTAMP
printk("timestamp %s \n", print_time());
#endif
if (mem == NULL) {
printk("(null dump)\n");
return;
}
for (i = 0; i < len; i++) {
if (col == 0)
printk("0x%02X: ", i);
printk(" %02X", pdata[i]);
if (++col == 16) {
printk("\n");
col = 0;
}
}
if (col)
printk("\n");
}
void
dump16(void *mem, u16 len)
{
int i, col=0;
unsigned short *p = (unsigned short *)mem;
#ifdef ANDROID_TIMESTAMP
printk("timestamp %s \n", print_time());
#endif
for (i = 0; i < len; i+=2) {
if (col == 0)
printk("0x%02X: ", i);
printk(" %04X", *p++);
if (++col == 8) {
printk("\n");
col = 0;
}
}
if (col)
printk("\n");
}
void
dump_str(void *mem, u16 len)
{
int i;
unsigned char *pdata = (unsigned char *)mem;
#ifdef ANDROID_TIMESTAMP
printk("timestamp %s \n", print_time());
#endif
for (i = 0; i < len; i++) {
printk("%c", pdata[i]);
}
printk("\n");
}
