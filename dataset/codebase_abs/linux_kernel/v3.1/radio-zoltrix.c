static int F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 = V_3 ;
if ( V_2 -> V_5 )
return 0 ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_3 == 0 ) {
F_3 ( 0 , V_2 -> V_7 ) ;
F_3 ( 0 , V_2 -> V_7 ) ;
F_4 ( V_2 -> V_7 + 3 ) ;
F_5 ( & V_2 -> V_6 ) ;
return 0 ;
}
F_3 ( V_2 -> V_4 - 1 , V_2 -> V_7 ) ;
F_6 ( 10 ) ;
F_4 ( V_2 -> V_7 + 2 ) ;
F_5 ( & V_2 -> V_6 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_5 = 1 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( 0 , V_2 -> V_7 ) ;
F_3 ( 0 , V_2 -> V_7 ) ;
F_4 ( V_2 -> V_7 + 3 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_5 = 0 ;
F_1 ( V_2 , V_2 -> V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
unsigned long long V_11 , V_12 , V_13 ;
unsigned int V_14 = V_2 -> V_14 ;
int V_15 ;
if ( V_8 == 0 ) {
F_10 ( V_10 , L_1 ) ;
return - V_16 ;
}
V_13 = ( V_8 / 160 - 8800 ) * 2 ;
V_12 = ( unsigned long long ) V_13 + 0x4d1c ;
V_11 = 0xc480402c10080000ull ;
V_15 = 45 ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_17 = V_8 ;
F_3 ( 0 , V_2 -> V_7 ) ;
F_3 ( 0 , V_2 -> V_7 ) ;
F_4 ( V_2 -> V_7 + 3 ) ;
F_3 ( 0x40 , V_2 -> V_7 ) ;
F_3 ( 0xc0 , V_2 -> V_7 ) ;
V_11 = ( V_11 ^ ( ( V_12 & 0xff ) << 47 ) ^ ( ( V_12 & 0xff00 ) << 30 ) ^ ( V_14 << 31 ) ) ;
while ( V_15 -- ) {
if ( ( V_11 & 0x8000000000000000ull ) != 0 ) {
F_3 ( 0x80 , V_2 -> V_7 ) ;
F_11 ( 50 ) ;
F_3 ( 0x00 , V_2 -> V_7 ) ;
F_11 ( 50 ) ;
F_3 ( 0x80 , V_2 -> V_7 ) ;
F_11 ( 50 ) ;
} else {
F_3 ( 0xc0 , V_2 -> V_7 ) ;
F_11 ( 50 ) ;
F_3 ( 0x40 , V_2 -> V_7 ) ;
F_11 ( 50 ) ;
F_3 ( 0xc0 , V_2 -> V_7 ) ;
F_11 ( 50 ) ;
}
V_11 *= 2 ;
}
F_3 ( 0x80 , V_2 -> V_7 ) ;
F_3 ( 0xc0 , V_2 -> V_7 ) ;
F_3 ( 0x40 , V_2 -> V_7 ) ;
F_11 ( 1000 ) ;
F_4 ( V_2 -> V_7 + 2 ) ;
F_11 ( 1000 ) ;
if ( V_2 -> V_5 ) {
F_3 ( 0 , V_2 -> V_7 ) ;
F_3 ( 0 , V_2 -> V_7 ) ;
F_4 ( V_2 -> V_7 + 3 ) ;
F_11 ( 1000 ) ;
}
F_5 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_5 )
F_1 ( V_2 , V_2 -> V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_18 , V_19 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( 0x00 , V_2 -> V_7 ) ;
F_3 ( V_2 -> V_4 , V_2 -> V_7 ) ;
F_6 ( 20 ) ;
V_18 = F_4 ( V_2 -> V_7 ) ;
F_6 ( 10 ) ;
V_19 = F_4 ( V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_6 ) ;
if ( V_18 != V_19 )
return 0 ;
return V_18 == 0xcf || V_18 == 0xdf || V_18 == 0xef ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_20 , V_21 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( 0x00 , V_2 -> V_7 ) ;
F_3 ( V_2 -> V_4 , V_2 -> V_7 ) ;
F_6 ( 20 ) ;
V_20 = F_4 ( V_2 -> V_7 ) ;
F_6 ( 10 ) ;
V_21 = F_4 ( V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_6 ) ;
return V_20 == V_21 && V_20 == 0xcf ;
}
static int F_14 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_25 )
{
F_15 ( V_25 -> V_26 , L_2 , sizeof( V_25 -> V_26 ) ) ;
F_15 ( V_25 -> V_27 , L_3 , sizeof( V_25 -> V_27 ) ) ;
F_15 ( V_25 -> V_28 , L_4 , sizeof( V_25 -> V_28 ) ) ;
V_25 -> V_29 = V_30 | V_31 ;
return 0 ;
}
static int F_16 ( struct V_22 * V_22 , void * V_23 ,
struct V_32 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
if ( V_25 -> V_33 > 0 )
return - V_16 ;
F_15 ( V_25 -> V_34 , L_5 , sizeof( V_25 -> V_34 ) ) ;
V_25 -> type = V_35 ;
V_25 -> V_36 = 88 * 16000 ;
V_25 -> V_37 = 108 * 16000 ;
V_25 -> V_38 = V_39 | V_40 ;
V_25 -> V_41 = V_42 ;
if ( F_13 ( V_2 ) )
V_25 -> V_43 = V_44 ;
else
V_25 -> V_43 = V_45 ;
V_25 -> signal = 0xFFFF * F_12 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_22 , void * V_23 ,
struct V_32 * V_25 )
{
return V_25 -> V_33 ? - V_16 : 0 ;
}
static int F_19 ( struct V_22 * V_22 , void * V_23 ,
struct V_46 * V_12 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
if ( V_12 -> V_47 != 0 || V_12 -> type != V_35 )
return - V_16 ;
if ( F_9 ( V_2 , V_12 -> V_48 ) != 0 )
return - V_16 ;
return 0 ;
}
static int F_20 ( struct V_22 * V_22 , void * V_23 ,
struct V_46 * V_12 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
if ( V_12 -> V_47 != 0 )
return - V_16 ;
V_12 -> type = V_35 ;
V_12 -> V_48 = V_2 -> V_17 ;
return 0 ;
}
static int F_21 ( struct V_22 * V_22 , void * V_23 ,
struct V_49 * V_50 )
{
switch ( V_50 -> V_51 ) {
case V_52 :
return F_22 ( V_50 , 0 , 1 , 1 , 1 ) ;
case V_53 :
return F_22 ( V_50 , 0 , 65535 , 4096 , 65535 ) ;
}
return - V_16 ;
}
static int F_23 ( struct V_22 * V_22 , void * V_23 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
switch ( V_55 -> V_51 ) {
case V_52 :
V_55 -> V_56 = V_2 -> V_5 ;
return 0 ;
case V_53 :
V_55 -> V_56 = V_2 -> V_4 * 4096 ;
return 0 ;
}
return - V_16 ;
}
static int F_24 ( struct V_22 * V_22 , void * V_23 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
switch ( V_55 -> V_51 ) {
case V_52 :
if ( V_55 -> V_56 )
F_7 ( V_2 ) ;
else {
F_8 ( V_2 ) ;
F_1 ( V_2 , V_2 -> V_4 ) ;
}
return 0 ;
case V_53 :
F_1 ( V_2 , V_55 -> V_56 / 4096 ) ;
return 0 ;
}
V_2 -> V_14 = 1 ;
if ( F_9 ( V_2 , V_2 -> V_17 ) != 0 )
return - V_16 ;
#if 0
if (v->mode & VIDEO_SOUND_STEREO) {
zol->stereo = 1;
zol_setfreq(zol, zol->curfreq);
}
if (v->mode & VIDEO_SOUND_MONO) {
zol->stereo = 0;
zol_setfreq(zol, zol->curfreq);
}
#endif
return - V_16 ;
}
static int F_25 ( struct V_22 * V_57 , void * V_23 , unsigned int * V_15 )
{
* V_15 = 0 ;
return 0 ;
}
static int F_26 ( struct V_22 * V_57 , void * V_23 , unsigned int V_15 )
{
return V_15 ? - V_16 : 0 ;
}
static int F_27 ( struct V_22 * V_22 , void * V_23 ,
struct V_58 * V_18 )
{
V_18 -> V_33 = 0 ;
F_15 ( V_18 -> V_34 , L_6 , sizeof( V_18 -> V_34 ) ) ;
V_18 -> V_41 = V_59 ;
return 0 ;
}
static int F_28 ( struct V_22 * V_22 , void * V_23 ,
struct V_58 * V_18 )
{
return V_18 -> V_33 ? - V_16 : 0 ;
}
static int T_1 F_29 ( void )
{
struct V_1 * V_2 = & V_60 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_61 ;
F_15 ( V_10 -> V_34 , L_7 , sizeof( V_10 -> V_34 ) ) ;
V_2 -> V_7 = V_7 ;
if ( V_2 -> V_7 == - 1 ) {
F_30 ( V_10 , L_8 ) ;
return - V_16 ;
}
if ( V_2 -> V_7 != 0x20c && V_2 -> V_7 != 0x30c ) {
F_30 ( V_10 , L_9 ) ;
return - V_62 ;
}
if ( ! F_31 ( V_2 -> V_7 , 2 , L_7 ) ) {
F_30 ( V_10 , L_10 , V_2 -> V_7 ) ;
return - V_63 ;
}
V_61 = F_32 ( NULL , V_10 ) ;
if ( V_61 < 0 ) {
F_33 ( V_2 -> V_7 , 2 ) ;
F_30 ( V_10 , L_11 ) ;
return V_61 ;
}
F_34 ( & V_2 -> V_6 ) ;
F_3 ( 0 , V_2 -> V_7 ) ;
F_3 ( 0 , V_2 -> V_7 ) ;
F_6 ( 20 ) ;
F_4 ( V_2 -> V_7 + 3 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_14 = 1 ;
F_15 ( V_2 -> V_64 . V_34 , V_10 -> V_34 , sizeof( V_2 -> V_64 . V_34 ) ) ;
V_2 -> V_64 . V_10 = V_10 ;
V_2 -> V_64 . V_65 = & V_66 ;
V_2 -> V_64 . V_67 = & V_68 ;
V_2 -> V_64 . V_69 = V_70 ;
F_35 ( & V_2 -> V_64 , V_2 ) ;
if ( F_36 ( & V_2 -> V_64 , V_71 , V_72 ) < 0 ) {
F_37 ( V_10 ) ;
F_33 ( V_2 -> V_7 , 2 ) ;
return - V_16 ;
}
F_38 ( V_10 , L_12 ) ;
return 0 ;
}
static void T_2 F_39 ( void )
{
struct V_1 * V_2 = & V_60 ;
F_40 ( & V_2 -> V_64 ) ;
F_37 ( & V_2 -> V_10 ) ;
F_33 ( V_2 -> V_7 , 2 ) ;
}
