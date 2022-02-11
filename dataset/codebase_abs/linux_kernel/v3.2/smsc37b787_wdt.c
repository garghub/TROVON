static inline void F_1 ( void )
{
F_2 ( 0x55 , V_1 ) ;
F_3 ( 1 ) ;
F_2 ( 0x55 , V_1 ) ;
}
static inline void F_4 ( void )
{
F_2 ( 0xAA , V_1 ) ;
}
static inline void F_5 ( unsigned char V_2 )
{
F_2 ( 0x07 , V_1 ) ;
F_2 ( V_2 , V_1 + 1 ) ;
}
static inline void F_6 ( unsigned char V_3 , unsigned char V_4 )
{
F_2 ( V_3 , V_1 ) ;
F_2 ( V_4 , V_1 + 1 ) ;
}
static inline char F_7 ( unsigned char V_3 )
{
F_2 ( V_3 , V_1 ) ;
return F_8 ( V_1 + 1 ) ;
}
static inline void F_9 ( unsigned char V_3 )
{
F_6 ( 0xE2 , V_3 ) ;
}
static inline void F_10 ( unsigned char V_3 )
{
F_6 ( 0xE3 , V_3 ) ;
}
static inline void F_11 ( unsigned char V_5 )
{
F_6 ( 0xF1 , V_5 ) ;
}
static inline void F_12 ( unsigned char V_6 )
{
F_6 ( 0xF2 , V_6 ) ;
}
static inline void F_13 ( unsigned char V_7 )
{
F_6 ( 0xF3 , V_7 ) ;
}
static inline void F_14 ( unsigned char V_3 )
{
F_6 ( 0xF4 , V_3 ) ;
}
static void F_15 ( void )
{
unsigned char V_8 ;
F_16 ( & V_9 ) ;
F_1 () ;
F_5 ( V_10 ) ;
F_10 ( 0x08 ) ;
F_9 ( 0x0A ) ;
F_12 ( 0 ) ;
F_14 ( 0x00 ) ;
F_13 ( 0x00 ) ;
V_8 = F_7 ( 0xF1 ) & 0x7F ;
if ( V_11 == V_12 )
V_8 |= 0x80 ;
F_11 ( V_8 ) ;
F_4 () ;
F_17 ( & V_9 ) ;
}
static void F_18 ( void )
{
F_16 ( & V_9 ) ;
F_1 () ;
F_5 ( V_10 ) ;
F_10 ( 0x09 ) ;
F_9 ( 0x09 ) ;
F_13 ( 0x00 ) ;
F_14 ( 0x00 ) ;
F_12 ( 0x00 ) ;
F_4 () ;
F_17 ( & V_9 ) ;
}
static void F_19 ( unsigned char V_6 )
{
F_16 ( & V_9 ) ;
F_1 () ;
F_5 ( V_10 ) ;
F_14 ( ( V_6 == 0 ) ? 0x00 : 0x02 ) ;
F_12 ( V_6 ) ;
F_4 () ;
F_17 ( & V_9 ) ;
}
static unsigned char F_20 ( void )
{
unsigned char V_13 ;
F_16 ( & V_9 ) ;
F_1 () ;
F_5 ( V_10 ) ;
V_13 = F_7 ( 0xF2 ) ;
F_4 () ;
F_17 ( & V_9 ) ;
return V_13 ;
}
static void F_21 ( void )
{
F_19 ( 0 ) ;
}
static void F_22 ( void )
{
F_19 ( V_14 ) ;
}
static void F_23 ( void )
{
F_16 ( & V_9 ) ;
F_1 () ;
F_5 ( V_10 ) ;
F_12 ( V_14 ) ;
F_13 ( 0x08 ) ;
F_4 () ;
F_17 ( & V_9 ) ;
}
static int F_24 ( void )
{
return ( F_20 () == 0 ) ? 0 : V_15 ;
}
static int F_25 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
if ( F_26 ( 0 , & V_18 ) )
return - V_19 ;
if ( V_20 )
F_27 ( V_21 ) ;
F_22 () ;
F_28 (KERN_INFO MODNAME
L_1 ,
timeout, (unit == UNIT_SECOND) ? L_2 : L_3 ) ;
return F_29 ( V_16 , V_17 ) ;
}
static int F_30 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
if ( V_22 == 42 ) {
F_21 () ;
F_28 (KERN_INFO MODNAME
L_4 ) ;
} else {
F_28 (KERN_CRIT MODNAME
L_5 ) ;
F_23 () ;
}
F_31 ( 0 , & V_18 ) ;
V_22 = 0 ;
return 0 ;
}
static T_1 F_32 ( struct V_17 * V_17 , const char T_2 * V_4 ,
T_3 V_23 , T_4 * V_24 )
{
if ( V_23 ) {
if ( ! V_20 ) {
T_3 V_25 ;
V_22 = 0 ;
for ( V_25 = 0 ; V_25 != V_23 ; V_25 ++ ) {
char V_26 ;
if ( F_33 ( V_26 , V_4 + V_25 ) )
return - V_27 ;
if ( V_26 == 'V' )
V_22 = 42 ;
}
}
F_23 () ;
}
return V_23 ;
}
static long F_34 ( struct V_17 * V_17 ,
unsigned int V_28 , unsigned long V_29 )
{
int V_6 ;
union {
struct V_30 T_2 * V_31 ;
int T_2 * V_25 ;
} V_32 ;
static const struct V_30 V_31 = {
. V_33 = V_15 |
V_34 |
V_35 ,
. V_36 = 0 ,
. V_37 = L_6 ,
} ;
V_32 . V_25 = ( int T_2 * ) V_29 ;
switch ( V_28 ) {
case V_38 :
return F_35 ( V_32 . V_31 , & V_31 , sizeof( V_31 ) )
? - V_27 : 0 ;
case V_39 :
return F_36 ( F_24 () , V_32 . V_25 ) ;
case V_40 :
return F_36 ( 0 , V_32 . V_25 ) ;
case V_41 :
{
int V_33 , V_42 = - V_43 ;
if ( F_33 ( V_33 , V_32 . V_25 ) )
return - V_27 ;
if ( V_33 & V_44 ) {
F_21 () ;
V_42 = 0 ;
}
if ( V_33 & V_45 ) {
F_22 () ;
V_42 = 0 ;
}
return V_42 ;
}
case V_46 :
F_23 () ;
return 0 ;
case V_47 :
if ( F_33 ( V_6 , V_32 . V_25 ) )
return - V_27 ;
if ( V_11 == V_48 )
V_6 /= 60 ;
if ( V_6 < 0 || V_6 > V_49 )
return - V_43 ;
V_14 = V_6 ;
F_19 ( V_14 ) ;
case V_50 :
V_6 = V_14 ;
if ( V_11 == V_48 )
V_6 *= 60 ;
return F_36 ( V_6 , V_32 . V_25 ) ;
default:
return - V_51 ;
}
}
static int F_37 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_55 )
{
if ( V_54 == V_56 || V_54 == V_57 ) {
V_14 = 0 ;
F_21 () ;
}
return V_58 ;
}
static int T_5 F_38 ( void )
{
int V_59 ;
F_28 ( V_60 L_7
V_61 L_8 ) ;
if ( ! F_39 ( V_1 , V_62 , L_9 ) ) {
F_28 (KERN_ERR MODNAME L_10 ,
IOPORT) ;
V_59 = - V_19 ;
goto V_63;
}
if ( V_14 > V_49 )
V_14 = V_49 ;
F_15 () ;
V_59 = F_40 ( & V_64 ) ;
if ( V_59 ) {
F_28 (KERN_ERR MODNAME
L_11 , ret) ;
goto V_65;
}
V_59 = F_41 ( & V_66 ) ;
if ( V_59 ) {
F_28 (KERN_ERR MODNAME
L_12 ,
WATCHDOG_MINOR) ;
goto V_67;
}
F_28 (KERN_INFO MODNAME L_13 ,
timeout, (unit == UNIT_SECOND) ? L_2 : L_3 ) ;
F_28 (KERN_INFO MODNAME
L_14 ,
nowayout) ;
V_68:
return V_59 ;
V_67:
F_42 ( & V_64 ) ;
V_65:
F_43 ( V_1 , V_62 ) ;
V_63:
goto V_68;
}
static void T_6 F_44 ( void )
{
if ( ! V_20 ) {
F_18 () ;
F_28 (KERN_INFO MODNAME L_15 ) ;
}
F_45 ( & V_66 ) ;
F_42 ( & V_64 ) ;
F_43 ( V_1 , V_62 ) ;
F_28 ( V_60 L_16 ) ;
}
