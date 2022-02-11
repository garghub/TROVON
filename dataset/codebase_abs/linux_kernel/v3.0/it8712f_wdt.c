static int F_1 ( int V_1 )
{
F_2 ( V_1 , V_2 ) ;
return F_3 ( V_3 ) ;
}
static void F_4 ( int V_4 , int V_1 )
{
F_2 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_3 ) ;
}
static int F_5 ( int V_1 )
{
int V_4 ;
F_2 ( V_1 ++ , V_2 ) ;
V_4 = F_3 ( V_3 ) << 8 ;
F_2 ( V_1 , V_2 ) ;
V_4 |= F_3 ( V_3 ) ;
return V_4 ;
}
static inline void F_6 ( int V_5 )
{
F_2 ( V_6 , V_2 ) ;
F_2 ( V_5 , V_3 ) ;
}
static inline void F_7 ( void )
{
F_8 ( & V_7 ) ;
F_2 ( 0x87 , V_2 ) ;
F_2 ( 0x01 , V_2 ) ;
F_2 ( 0x55 , V_2 ) ;
F_2 ( 0x55 , V_2 ) ;
}
static inline void F_9 ( void )
{
F_2 ( 0x02 , V_2 ) ;
F_2 ( 0x02 , V_3 ) ;
F_10 ( & V_7 ) ;
}
static inline void F_11 ( void )
{
if ( V_8 & V_9 )
F_3 ( V_10 ) ;
}
static void F_12 ( void )
{
int V_11 = V_12 | V_13 ;
int V_14 = V_15 ;
if ( V_14 <= V_16 ) {
V_11 |= V_17 ;
F_13 (KERN_INFO NAME L_1 , units) ;
} else {
V_14 /= 60 ;
F_13 (KERN_INFO NAME L_2 , units) ;
}
F_4 ( V_11 , V_18 ) ;
if ( V_19 >= 0x08 )
F_4 ( V_14 >> 8 , V_20 + 1 ) ;
F_4 ( V_14 , V_20 ) ;
}
static int F_14 ( void )
{
if ( F_1 ( V_21 ) & 0x01 )
return V_22 ;
else
return 0 ;
}
static void F_15 ( void )
{
F_13 (KERN_DEBUG NAME L_3 ) ;
F_7 () ;
F_6 ( V_23 ) ;
F_4 ( V_8 , V_21 ) ;
F_12 () ;
F_9 () ;
F_11 () ;
}
static void F_16 ( void )
{
F_13 (KERN_DEBUG NAME L_4 ) ;
F_7 () ;
F_6 ( V_23 ) ;
F_4 ( 0 , V_18 ) ;
F_4 ( 0 , V_21 ) ;
if ( V_19 >= 0x08 )
F_4 ( 0 , V_20 + 1 ) ;
F_4 ( 0 , V_20 ) ;
F_9 () ;
}
static int F_17 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
if ( V_26 == V_28 || V_26 == V_29 )
if ( ! V_30 )
F_16 () ;
return V_31 ;
}
static T_1 F_18 ( struct V_32 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
if ( V_34 ) {
T_3 V_36 ;
F_11 () ;
V_37 = 0 ;
for ( V_36 = 0 ; V_36 < V_34 ; ++ V_36 ) {
char V_38 ;
if ( F_19 ( V_38 , V_33 + V_36 ) )
return - V_39 ;
if ( V_38 == 'V' )
V_37 = 42 ;
}
}
return V_34 ;
}
static long F_20 ( struct V_32 * V_32 , unsigned int V_40 ,
unsigned long V_41 )
{
void T_2 * V_42 = ( void T_2 * ) V_41 ;
int T_2 * V_43 = V_42 ;
static const struct V_44 V_45 = {
. V_46 = L_5 ,
. V_47 = 1 ,
. V_48 = V_49 | V_50 |
V_51 ,
} ;
int V_52 ;
switch ( V_40 ) {
case V_53 :
if ( F_21 ( V_42 , & V_45 , sizeof( V_45 ) ) )
return - V_39 ;
return 0 ;
case V_54 :
F_7 () ;
F_6 ( V_23 ) ;
V_52 = F_14 () ;
F_9 () ;
return F_22 ( V_52 , V_43 ) ;
case V_55 :
return F_22 ( 0 , V_43 ) ;
case V_56 :
F_11 () ;
return 0 ;
case V_57 :
if ( F_19 ( V_52 , V_43 ) )
return - V_39 ;
if ( V_52 < 1 )
return - V_58 ;
if ( V_52 > ( V_16 * 60 ) )
return - V_58 ;
V_15 = V_52 ;
F_7 () ;
F_6 ( V_23 ) ;
F_12 () ;
F_9 () ;
F_11 () ;
case V_59 :
if ( F_22 ( V_15 , V_43 ) )
return - V_39 ;
return 0 ;
default:
return - V_60 ;
}
}
static int F_23 ( struct V_61 * V_61 , struct V_32 * V_32 )
{
if ( F_24 ( 0 , & V_62 ) )
return - V_63 ;
F_15 () ;
return F_25 ( V_61 , V_32 ) ;
}
static int F_26 ( struct V_61 * V_61 , struct V_32 * V_32 )
{
if ( V_37 != 42 ) {
F_13 (KERN_WARNING NAME
L_6
L_7 ) ;
} else if ( ! V_30 ) {
F_16 () ;
}
V_37 = 0 ;
F_27 ( 0 , & V_62 ) ;
return 0 ;
}
static int T_5 F_28 ( unsigned short * V_10 )
{
int V_64 = - V_65 ;
int V_66 ;
F_7 () ;
V_66 = F_5 ( V_67 ) ;
if ( V_66 != V_68 )
goto exit;
F_6 ( V_69 ) ;
F_4 ( 1 , V_70 ) ;
if ( ! ( F_1 ( V_70 ) & 0x01 ) ) {
F_13 (KERN_ERR NAME L_8 ) ;
goto exit;
}
* V_10 = F_5 ( V_71 ) ;
if ( * V_10 == 0 ) {
F_13 (KERN_ERR NAME L_9 ) ;
goto exit;
}
V_64 = 0 ;
V_19 = F_1 ( V_72 ) & 0x0f ;
if ( V_19 >= 0x08 )
V_16 = 65535 ;
if ( V_15 > ( V_16 * 60 ) )
V_15 = ( V_16 * 60 ) ;
F_13 (KERN_INFO NAME L_10
L_11 ,
chip_type, revision, *address) ;
exit:
F_9 () ;
return V_64 ;
}
static int T_5 F_29 ( void )
{
int V_64 = 0 ;
F_30 ( & V_7 ) ;
if ( F_28 ( & V_10 ) )
return - V_65 ;
if ( ! F_31 ( V_10 , 1 , L_5 ) ) {
F_13 (KERN_WARNING NAME L_12 ) ;
return - V_63 ;
}
F_16 () ;
V_64 = F_32 ( & V_73 ) ;
if ( V_64 ) {
F_13 (KERN_ERR NAME L_13 ) ;
goto V_74;
}
V_64 = F_33 ( & V_75 ) ;
if ( V_64 ) {
F_13 (KERN_ERR NAME
L_14 ,
WATCHDOG_MINOR, err) ;
goto V_76;
}
return 0 ;
V_76:
F_34 ( & V_73 ) ;
V_74:
F_35 ( V_10 , 1 ) ;
return V_64 ;
}
static void T_6 F_36 ( void )
{
F_37 ( & V_75 ) ;
F_34 ( & V_73 ) ;
F_35 ( V_10 , 1 ) ;
}
