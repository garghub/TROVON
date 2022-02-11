static inline void F_1 ( void )
{
unsigned int V_1 = 0 ;
F_2 ( V_2 , V_3 ) ;
V_1 = F_3 ( V_4 ) ;
V_1 |= 0x80 ;
F_2 ( V_2 , V_3 ) ;
F_2 ( V_1 , V_4 ) ;
#ifdef F_4
F_5 (KERN_INFO DPFX
L_1 ,
cr_data) ;
#endif
}
static inline void F_6 ( void )
{
unsigned int V_1 = 0 ;
F_2 ( 0x07 , V_3 ) ;
F_2 ( V_5 , V_4 ) ;
F_2 ( 0x30 , V_3 ) ;
V_1 = F_3 ( V_4 ) ;
V_1 |= 0x01 ;
F_2 ( 0x30 , V_3 ) ;
F_2 ( V_1 , V_4 ) ;
#ifdef F_4
F_5 (KERN_INFO DPFX L_2 ) ;
#endif
}
static inline unsigned int F_7 ( void )
{
unsigned int V_6 = 0 ;
unsigned char V_7 , V_8 = 0 ;
F_2 ( 0x60 , V_3 ) ;
V_8 = F_3 ( V_4 ) ;
F_2 ( 0x61 , V_3 ) ;
V_7 = F_3 ( V_4 ) ;
V_6 = ( V_8 << 8 ) + V_7 ;
#ifdef F_4
F_5 (KERN_INFO DPFX
L_3 ,
addr_l, addr_h, swc_base_addr) ;
#endif
return V_6 ;
}
static inline void F_8 ( unsigned int V_6 )
{
F_2 ( F_3 ( V_6 + 0x0f ) | 0x03 , V_6 + 0x0f ) ;
#ifdef F_4
F_5 (KERN_INFO DPFX L_4 ) ;
#endif
}
static inline void F_9 ( unsigned int V_6 ,
char V_9 )
{
F_2 ( V_9 , V_6 + V_10 ) ;
#ifdef F_4
F_5 (KERN_INFO DPFX L_5 , pc87413_time) ;
#endif
}
static inline void F_10 ( unsigned int V_6 )
{
F_2 ( F_3 ( V_6 + V_11 ) | 0x01 , V_6 + V_11 ) ;
#ifdef F_4
F_5 (KERN_INFO DPFX L_6 ) ;
#endif
}
static inline void F_11 ( unsigned int V_6 )
{
F_2 ( F_3 ( V_6 + V_12 ) | 0x80 , V_6 + V_12 ) ;
#ifdef F_4
F_5 (KERN_INFO DPFX L_7 ) ;
#endif
}
static inline void F_12 ( unsigned int V_6 )
{
F_2 ( F_3 ( V_6 + V_12 ) & 0x7f , V_6 + V_12 ) ;
#ifdef F_4
F_5 (KERN_INFO DPFX L_8 ) ;
#endif
}
static inline void F_13 ( unsigned int V_6 )
{
F_2 ( F_3 ( V_6 + V_11 ) | 0x80 , V_6 + V_11 ) ;
#ifdef F_4
F_5 (KERN_INFO DPFX L_9 ) ;
#endif
}
static inline void F_14 ( unsigned int V_6 )
{
F_2 ( F_3 ( V_6 + V_11 ) & 0x7f , V_6 + V_11 ) ;
#ifdef F_4
F_5 (KERN_INFO DPFX L_10 ) ;
#endif
}
static void F_15 ( void )
{
unsigned int V_6 ;
F_16 ( & V_13 ) ;
F_1 () ;
F_6 () ;
V_6 = F_7 () ;
F_8 ( V_6 ) ;
F_9 ( V_6 , V_14 ) ;
F_10 ( V_6 ) ;
F_11 ( V_6 ) ;
F_13 ( V_6 ) ;
F_17 ( & V_13 ) ;
}
static void F_18 ( void )
{
unsigned int V_6 ;
F_16 ( & V_13 ) ;
F_1 () ;
F_6 () ;
V_6 = F_7 () ;
F_8 ( V_6 ) ;
F_12 ( V_6 ) ;
F_14 ( V_6 ) ;
F_9 ( V_6 , 0 ) ;
F_17 ( & V_13 ) ;
}
static void F_19 ( void )
{
unsigned int V_6 ;
F_16 ( & V_13 ) ;
F_1 () ;
F_6 () ;
V_6 = F_7 () ;
F_8 ( V_6 ) ;
F_12 ( V_6 ) ;
F_14 ( V_6 ) ;
F_9 ( V_6 , V_14 ) ;
F_10 ( V_6 ) ;
F_11 ( V_6 ) ;
F_13 ( V_6 ) ;
F_17 ( & V_13 ) ;
}
static int F_20 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
if ( F_21 ( 0 , & V_17 ) )
return - V_18 ;
if ( V_19 )
F_22 ( V_20 ) ;
F_19 () ;
F_5 (KERN_INFO MODNAME
L_11 , timeout) ;
return F_23 ( V_15 , V_16 ) ;
}
static int F_24 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
if ( V_21 == 42 ) {
F_18 () ;
F_5 (KERN_INFO MODNAME
L_12 ) ;
} else {
F_5 (KERN_CRIT MODNAME
L_13 ) ;
F_19 () ;
}
F_25 ( 0 , & V_17 ) ;
V_21 = 0 ;
return 0 ;
}
static int F_26 ( void )
{
return 0 ;
}
static T_1 F_27 ( struct V_16 * V_16 , const char T_2 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
if ( V_23 ) {
if ( ! V_19 ) {
T_3 V_25 ;
V_21 = 0 ;
for ( V_25 = 0 ; V_25 != V_23 ; V_25 ++ ) {
char V_26 ;
if ( F_28 ( V_26 , V_22 + V_25 ) )
return - V_27 ;
if ( V_26 == 'V' )
V_21 = 42 ;
}
}
F_19 () ;
}
return V_23 ;
}
static long F_29 ( struct V_16 * V_16 , unsigned int V_28 ,
unsigned long V_29 )
{
int V_30 ;
union {
struct V_31 T_2 * V_32 ;
int T_2 * V_25 ;
} V_33 ;
static const struct V_31 V_32 = {
. V_34 = V_35 |
V_36 |
V_37 ,
. V_38 = 1 ,
. V_39 = L_14 ,
} ;
V_33 . V_25 = ( int T_2 * ) V_29 ;
switch ( V_28 ) {
case V_40 :
return F_30 ( V_33 . V_32 , & V_32 ,
sizeof( V_32 ) ) ? - V_27 : 0 ;
case V_41 :
return F_31 ( F_26 () , V_33 . V_25 ) ;
case V_42 :
return F_31 ( 0 , V_33 . V_25 ) ;
case V_43 :
{
int V_34 , V_44 = - V_45 ;
if ( F_28 ( V_34 , V_33 . V_25 ) )
return - V_27 ;
if ( V_34 & V_46 ) {
F_18 () ;
V_44 = 0 ;
}
if ( V_34 & V_47 ) {
F_15 () ;
V_44 = 0 ;
}
return V_44 ;
}
case V_48 :
F_19 () ;
#ifdef F_4
F_5 (KERN_INFO DPFX L_15 ) ;
#endif
return 0 ;
case V_49 :
if ( F_28 ( V_30 , V_33 . V_25 ) )
return - V_27 ;
V_30 /= 60 ;
if ( V_30 < 0 || V_30 > V_50 )
return - V_45 ;
V_14 = V_30 ;
F_19 () ;
case V_51 :
V_30 = V_14 * 60 ;
return F_31 ( V_30 , V_33 . V_25 ) ;
default:
return - V_52 ;
}
}
static int F_32 ( struct V_53 * V_54 ,
unsigned long V_55 ,
void * V_56 )
{
if ( V_55 == V_57 || V_55 == V_58 )
F_18 () ;
return V_59 ;
}
static int T_5 F_33 ( void )
{
int V_60 ;
F_5 (KERN_INFO PFX L_16 VERSION L_17 ,
WDT_INDEX_IO_PORT) ;
V_60 = F_34 ( & V_61 ) ;
if ( V_60 != 0 ) {
F_5 (KERN_ERR PFX
L_18 , ret) ;
}
V_60 = F_35 ( & V_62 ) ;
if ( V_60 != 0 ) {
F_5 (KERN_ERR PFX
L_19 ,
WATCHDOG_MINOR, ret) ;
F_36 ( & V_61 ) ;
return V_60 ;
}
F_5 (KERN_INFO PFX L_20 , timeout) ;
F_15 () ;
return 0 ;
}
static void T_6 F_37 ( void )
{
if ( ! V_19 ) {
F_18 () ;
F_5 (KERN_INFO MODNAME L_21 ) ;
}
F_38 ( & V_62 ) ;
F_36 ( & V_61 ) ;
F_5 (KERN_INFO MODNAME L_22 ) ;
}
