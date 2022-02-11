static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned char V_4 , V_5 , V_6 ;
unsigned long V_7 ;
V_3 = 10 ;
while ( V_3 ) {
F_2 ( & V_2 -> V_8 , V_7 ) ;
V_4 = F_3 ( V_2 ) ;
if ( ! ( V_4 & 0x01 ) ) {
F_4 ( & V_2 -> V_8 , V_7 ) ;
V_3 -- ;
continue;
}
V_3 = 100 ;
V_5 = F_5 ( V_2 ) ;
if ( ! ( V_2 -> V_9 . V_10 & 0x80 ) ) {
F_4 ( & V_2 -> V_8 , V_7 ) ;
continue;
}
if ( V_4 & 0x10 ) {
V_2 -> V_9 . V_11 ++ ;
F_4 ( & V_2 -> V_8 , V_7 ) ;
continue;
}
V_6 = F_5 ( V_2 ) ;
F_4 ( & V_2 -> V_8 , V_7 ) ;
F_6 ( V_2 -> V_12 , & V_6 , 1 ) ;
if ( V_4 & 0x20 ) {
V_2 -> V_9 . V_13 ++ ;
}
}
}
static void F_7 ( struct V_1 * V_2 )
{
char V_6 ;
unsigned long V_7 ;
if ( F_3 ( V_2 ) & 0x01 )
F_1 ( V_2 ) ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
if ( F_3 ( V_2 ) & 0x02 ) {
if ( F_8 ( V_2 -> V_14 , & V_6 , 1 ) != 1 ) {
F_9 ( V_2 , V_2 -> V_9 . V_10 & ~ 0x20 ) ;
} else {
F_10 ( V_2 , V_6 ) ;
}
}
F_4 ( & V_2 -> V_8 , V_7 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_15 )
{
F_9 ( V_2 , 0x03 ) ;
if ( ! V_15 && V_2 -> V_16 ) {
F_12 ( 160 ) ;
F_9 ( V_2 , 0x00 ) ;
}
}
static int F_13 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
struct V_1 * V_2 ;
V_2 = V_18 -> V_19 -> V_20 ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
if ( ! ( V_2 -> V_9 . V_10 & 0x80 ) ) {
F_11 ( V_2 , 0 ) ;
}
V_2 -> V_9 . V_21 = F_7 ;
V_2 -> V_14 = V_18 ;
F_4 ( & V_2 -> V_8 , V_7 ) ;
#if 0
snd_printk(KERN_DEBUG "write init - cmd = 0x%x, stat = 0x%x\n", gus->gf1.uart_cmd, snd_gf1_uart_stat(gus));
#endif
return 0 ;
}
static int F_14 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
struct V_1 * V_2 ;
int V_22 ;
V_2 = V_18 -> V_19 -> V_20 ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_9 . V_21 != F_7 ) {
F_11 ( V_2 , 0 ) ;
}
V_2 -> V_9 . V_23 = F_1 ;
V_2 -> V_12 = V_18 ;
if ( V_2 -> V_16 ) {
for ( V_22 = 0 ; V_22 < 1000 && ( F_3 ( V_2 ) & 0x01 ) ; V_22 ++ )
F_5 ( V_2 ) ;
if ( V_22 >= 1000 )
F_15 ( V_24 L_1 ) ;
}
F_4 ( & V_2 -> V_8 , V_7 ) ;
#if 0
snd_printk(KERN_DEBUG
"read init - enable = %i, cmd = 0x%x, stat = 0x%x\n",
gus->uart_enable, gus->gf1.uart_cmd, snd_gf1_uart_stat(gus));
snd_printk(KERN_DEBUG
"[0x%x] reg (ctrl/status) = 0x%x, reg (data) = 0x%x "
"(page = 0x%x)\n",
gus->gf1.port + 0x100, inb(gus->gf1.port + 0x100),
inb(gus->gf1.port + 0x101), inb(gus->gf1.port + 0x102));
#endif
return 0 ;
}
static int F_16 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
struct V_1 * V_2 ;
V_2 = V_18 -> V_19 -> V_20 ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_9 . V_23 != F_1 )
F_11 ( V_2 , 1 ) ;
F_17 ( V_2 , V_25 ) ;
V_2 -> V_14 = NULL ;
F_4 ( & V_2 -> V_8 , V_7 ) ;
return 0 ;
}
static int F_18 ( struct V_17 * V_18 )
{
unsigned long V_7 ;
struct V_1 * V_2 ;
V_2 = V_18 -> V_19 -> V_20 ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_9 . V_21 != F_7 )
F_11 ( V_2 , 1 ) ;
F_17 ( V_2 , V_26 ) ;
V_2 -> V_12 = NULL ;
F_4 ( & V_2 -> V_8 , V_7 ) ;
return 0 ;
}
static void F_19 ( struct V_17 * V_18 , int V_27 )
{
struct V_1 * V_2 ;
unsigned long V_7 ;
V_2 = V_18 -> V_19 -> V_20 ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
if ( V_27 ) {
if ( ( V_2 -> V_9 . V_10 & 0x80 ) == 0 )
F_9 ( V_2 , V_2 -> V_9 . V_10 | 0x80 ) ;
} else {
if ( V_2 -> V_9 . V_10 & 0x80 )
F_9 ( V_2 , V_2 -> V_9 . V_10 & ~ 0x80 ) ;
}
F_4 ( & V_2 -> V_8 , V_7 ) ;
}
static void F_20 ( struct V_17 * V_18 , int V_27 )
{
unsigned long V_7 ;
struct V_1 * V_2 ;
char V_6 ;
int V_28 ;
V_2 = V_18 -> V_19 -> V_20 ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
if ( V_27 ) {
if ( ( V_2 -> V_9 . V_10 & 0x20 ) == 0 ) {
F_4 ( & V_2 -> V_8 , V_7 ) ;
V_28 = 10000 ;
while ( V_28 -- > 0 && F_3 ( V_2 ) & 0x01 ) ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_9 . V_10 & 0x20 ) {
F_4 ( & V_2 -> V_8 , V_7 ) ;
return;
}
if ( F_3 ( V_2 ) & 0x02 ) {
if ( F_8 ( V_18 , & V_6 , 1 ) != 1 ) {
F_4 ( & V_2 -> V_8 , V_7 ) ;
return;
}
F_10 ( V_2 , V_6 ) ;
}
F_9 ( V_2 , V_2 -> V_9 . V_10 | 0x20 ) ;
}
} else {
if ( V_2 -> V_9 . V_10 & 0x20 )
F_9 ( V_2 , V_2 -> V_9 . V_10 & ~ 0x20 ) ;
}
F_4 ( & V_2 -> V_8 , V_7 ) ;
}
int F_21 ( struct V_1 * V_2 , int V_29 )
{
struct V_30 * V_19 ;
int V_31 ;
if ( ( V_31 = F_22 ( V_2 -> V_32 , L_2 , V_29 , 1 , 1 , & V_19 ) ) < 0 )
return V_31 ;
strcpy ( V_19 -> V_33 , V_2 -> V_34 ? L_3 : L_2 ) ;
F_23 ( V_19 , V_35 , & V_36 ) ;
F_23 ( V_19 , V_37 , & V_38 ) ;
V_19 -> V_39 |= V_40 | V_41 | V_42 ;
V_19 -> V_20 = V_2 ;
V_2 -> V_43 = V_19 ;
return V_31 ;
}
