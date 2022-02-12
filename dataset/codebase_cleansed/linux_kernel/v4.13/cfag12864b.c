unsigned int cfag12864b_getrate(void)
{
return cfag12864b_rate;
}
static void cfag12864b_set(void)
{
ks0108_writecontrol(cfag12864b_state);
}
static void cfag12864b_setbit(unsigned char state, unsigned char n)
{
if (state)
cfag12864b_state |= bit(n);
else
cfag12864b_state &= ~bit(n);
}
static void cfag12864b_e(unsigned char state)
{
cfag12864b_setbit(state, CFAG12864B_BIT_E);
cfag12864b_set();
}
static void cfag12864b_cs1(unsigned char state)
{
cfag12864b_setbit(state, CFAG12864B_BIT_CS1);
}
static void cfag12864b_cs2(unsigned char state)
{
cfag12864b_setbit(state, CFAG12864B_BIT_CS2);
}
static void cfag12864b_di(unsigned char state)
{
cfag12864b_setbit(state, CFAG12864B_BIT_DI);
}
static void cfag12864b_setcontrollers(unsigned char first,
unsigned char second)
{
if (first)
cfag12864b_cs1(0);
else
cfag12864b_cs1(1);
if (second)
cfag12864b_cs2(0);
else
cfag12864b_cs2(1);
}
static void cfag12864b_controller(unsigned char which)
{
if (which == 0)
cfag12864b_setcontrollers(1, 0);
else if (which == 1)
cfag12864b_setcontrollers(0, 1);
}
static void cfag12864b_displaystate(unsigned char state)
{
cfag12864b_di(0);
cfag12864b_e(1);
ks0108_displaystate(state);
cfag12864b_e(0);
}
static void cfag12864b_address(unsigned char address)
{
cfag12864b_di(0);
cfag12864b_e(1);
ks0108_address(address);
cfag12864b_e(0);
}
static void cfag12864b_page(unsigned char page)
{
cfag12864b_di(0);
cfag12864b_e(1);
ks0108_page(page);
cfag12864b_e(0);
}
static void cfag12864b_startline(unsigned char startline)
{
cfag12864b_di(0);
cfag12864b_e(1);
ks0108_startline(startline);
cfag12864b_e(0);
}
static void cfag12864b_writebyte(unsigned char byte)
{
cfag12864b_di(1);
cfag12864b_e(1);
ks0108_writedata(byte);
cfag12864b_e(0);
}
static void cfag12864b_nop(void)
{
cfag12864b_startline(0);
}
static void cfag12864b_on(void)
{
cfag12864b_setcontrollers(1, 1);
cfag12864b_displaystate(1);
}
static void cfag12864b_off(void)
{
cfag12864b_setcontrollers(1, 1);
cfag12864b_displaystate(0);
}
static void cfag12864b_clear(void)
{
unsigned char i, j;
cfag12864b_setcontrollers(1, 1);
for (i = 0; i < CFAG12864B_PAGES; i++) {
cfag12864b_page(i);
cfag12864b_address(0);
for (j = 0; j < CFAG12864B_ADDRESSES; j++)
cfag12864b_writebyte(0);
}
}
static void cfag12864b_queue(void)
{
queue_delayed_work(cfag12864b_workqueue, &cfag12864b_work,
HZ / cfag12864b_rate);
}
unsigned char cfag12864b_enable(void)
{
unsigned char ret;
mutex_lock(&cfag12864b_mutex);
if (!cfag12864b_updating) {
cfag12864b_updating = 1;
cfag12864b_queue();
ret = 0;
} else
ret = 1;
mutex_unlock(&cfag12864b_mutex);
return ret;
}
void cfag12864b_disable(void)
{
mutex_lock(&cfag12864b_mutex);
if (cfag12864b_updating) {
cfag12864b_updating = 0;
cancel_delayed_work(&cfag12864b_work);
flush_workqueue(cfag12864b_workqueue);
}
mutex_unlock(&cfag12864b_mutex);
}
unsigned char cfag12864b_isenabled(void)
{
return cfag12864b_updating;
}
static void cfag12864b_update(struct work_struct *work)
{
unsigned char c;
unsigned short i, j, k, b;
if (memcmp(cfag12864b_cache, cfag12864b_buffer, CFAG12864B_SIZE)) {
for (i = 0; i < CFAG12864B_CONTROLLERS; i++) {
cfag12864b_controller(i);
cfag12864b_nop();
for (j = 0; j < CFAG12864B_PAGES; j++) {
cfag12864b_page(j);
cfag12864b_nop();
cfag12864b_address(0);
cfag12864b_nop();
for (k = 0; k < CFAG12864B_ADDRESSES; k++) {
for (c = 0, b = 0; b < 8; b++)
if (cfag12864b_buffer
[i * CFAG12864B_ADDRESSES / 8
+ k / 8 + (j * 8 + b) *
CFAG12864B_WIDTH / 8]
& bit(k % 8))
c |= bit(b);
cfag12864b_writebyte(c);
}
}
}
memcpy(cfag12864b_cache, cfag12864b_buffer, CFAG12864B_SIZE);
}
if (cfag12864b_updating)
cfag12864b_queue();
}
unsigned char cfag12864b_isinited(void)
{
return cfag12864b_inited;
}
static int __init cfag12864b_init(void)
{
int ret = -EINVAL;
if (!ks0108_isinited()) {
printk(KERN_ERR CFAG12864B_NAME ": ERROR: "
"ks0108 is not initialized\n");
goto none;
}
BUILD_BUG_ON(PAGE_SIZE < CFAG12864B_SIZE);
cfag12864b_buffer = (unsigned char *) get_zeroed_page(GFP_KERNEL);
if (cfag12864b_buffer == NULL) {
printk(KERN_ERR CFAG12864B_NAME ": ERROR: "
"can't get a free page\n");
ret = -ENOMEM;
goto none;
}
cfag12864b_cache = kmalloc(sizeof(unsigned char) *
CFAG12864B_SIZE, GFP_KERNEL);
if (cfag12864b_cache == NULL) {
printk(KERN_ERR CFAG12864B_NAME ": ERROR: "
"can't alloc cache buffer (%i bytes)\n",
CFAG12864B_SIZE);
ret = -ENOMEM;
goto bufferalloced;
}
cfag12864b_workqueue = create_singlethread_workqueue(CFAG12864B_NAME);
if (cfag12864b_workqueue == NULL)
goto cachealloced;
cfag12864b_clear();
cfag12864b_on();
cfag12864b_inited = 1;
return 0;
cachealloced:
kfree(cfag12864b_cache);
bufferalloced:
free_page((unsigned long) cfag12864b_buffer);
none:
return ret;
}
static void __exit cfag12864b_exit(void)
{
cfag12864b_disable();
cfag12864b_off();
destroy_workqueue(cfag12864b_workqueue);
kfree(cfag12864b_cache);
free_page((unsigned long) cfag12864b_buffer);
}
