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
static inline int F_7 ( void )
{
if ( ! F_8 ( V_2 , 2 , V_7 ) )
return - V_8 ;
F_2 ( 0x87 , V_2 ) ;
F_2 ( 0x01 , V_2 ) ;
F_2 ( 0x55 , V_2 ) ;
F_2 ( 0x55 , V_2 ) ;
return 0 ;
}
static inline void F_9 ( void )
{
F_2 ( 0x02 , V_2 ) ;
F_2 ( 0x02 , V_3 ) ;
F_10 ( V_2 , 2 ) ;
}
static inline void F_11 ( void )
{
if ( V_9 & V_10 )
F_3 ( V_11 ) ;
}
static void F_12 ( void )
{
int V_12 = V_13 | V_14 ;
int V_15 = V_16 ;
if ( V_15 <= V_17 ) {
V_12 |= V_18 ;
F_13 (KERN_INFO NAME L_1 , units) ;
} else {
V_15 /= 60 ;
F_13 (KERN_INFO NAME L_2 , units) ;
}
F_4 ( V_12 , V_19 ) ;
if ( V_20 >= 0x08 )
F_4 ( V_15 >> 8 , V_21 + 1 ) ;
F_4 ( V_15 , V_21 ) ;
}
static int F_14 ( void )
{
if ( F_1 ( V_22 ) & 0x01 )
return V_23 ;
else
return 0 ;
}
static int F_15 ( void )
{
int V_24 = F_7 () ;
if ( V_24 )
return V_24 ;
F_13 (KERN_DEBUG NAME L_3 ) ;
F_6 ( V_25 ) ;
F_4 ( V_9 , V_22 ) ;
F_12 () ;
F_9 () ;
F_11 () ;
return 0 ;
}
static int F_16 ( void )
{
int V_24 = F_7 () ;
if ( V_24 )
return V_24 ;
F_13 (KERN_DEBUG NAME L_4 ) ;
F_6 ( V_25 ) ;
F_4 ( 0 , V_19 ) ;
F_4 ( 0 , V_22 ) ;
if ( V_20 >= 0x08 )
F_4 ( 0 , V_21 + 1 ) ;
F_4 ( 0 , V_21 ) ;
F_9 () ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
if ( V_28 == V_30 || V_28 == V_31 )
if ( ! V_32 )
F_16 () ;
return V_33 ;
}
static T_1 F_18 ( struct V_34 * V_34 , const char T_2 * V_35 ,
T_3 V_36 , T_4 * V_37 )
{
if ( V_36 ) {
T_3 V_38 ;
F_11 () ;
V_39 = 0 ;
for ( V_38 = 0 ; V_38 < V_36 ; ++ V_38 ) {
char V_40 ;
if ( F_19 ( V_40 , V_35 + V_38 ) )
return - V_41 ;
if ( V_40 == 'V' )
V_39 = 42 ;
}
}
return V_36 ;
}
static long F_20 ( struct V_34 * V_34 , unsigned int V_42 ,
unsigned long V_43 )
{
void T_2 * V_44 = ( void T_2 * ) V_43 ;
int T_2 * V_45 = V_44 ;
static const struct V_46 V_47 = {
. V_48 = L_5 ,
. V_49 = 1 ,
. V_50 = V_51 | V_52 |
V_53 ,
} ;
int V_54 ;
int V_24 ;
switch ( V_42 ) {
case V_55 :
if ( F_21 ( V_44 , & V_47 , sizeof( V_47 ) ) )
return - V_41 ;
return 0 ;
case V_56 :
V_24 = F_7 () ;
if ( V_24 )
return V_24 ;
F_6 ( V_25 ) ;
V_54 = F_14 () ;
F_9 () ;
return F_22 ( V_54 , V_45 ) ;
case V_57 :
return F_22 ( 0 , V_45 ) ;
case V_58 :
F_11 () ;
return 0 ;
case V_59 :
if ( F_19 ( V_54 , V_45 ) )
return - V_41 ;
if ( V_54 < 1 )
return - V_60 ;
if ( V_54 > ( V_17 * 60 ) )
return - V_60 ;
V_16 = V_54 ;
V_24 = F_7 () ;
if ( V_24 )
return V_24 ;
F_6 ( V_25 ) ;
F_12 () ;
F_9 () ;
F_11 () ;
case V_61 :
if ( F_22 ( V_16 , V_45 ) )
return - V_41 ;
return 0 ;
default:
return - V_62 ;
}
}
static int F_23 ( struct V_63 * V_63 , struct V_34 * V_34 )
{
int V_24 ;
if ( F_24 ( 0 , & V_64 ) )
return - V_8 ;
V_24 = F_15 () ;
if ( V_24 )
return V_24 ;
return F_25 ( V_63 , V_34 ) ;
}
static int F_26 ( struct V_63 * V_63 , struct V_34 * V_34 )
{
if ( V_39 != 42 ) {
F_13 (KERN_WARNING NAME
L_6
L_7 ) ;
} else if ( ! V_32 ) {
if ( F_16 () )
F_13 (KERN_WARNING NAME L_8 ) ;
}
V_39 = 0 ;
F_27 ( 0 , & V_64 ) ;
return 0 ;
}
static int T_5 F_28 ( unsigned short * V_11 )
{
int V_65 = - V_66 ;
int V_67 ;
int V_24 = F_7 () ;
if ( V_24 )
return V_24 ;
V_67 = F_5 ( V_68 ) ;
if ( V_67 != V_69 )
goto exit;
F_6 ( V_70 ) ;
F_4 ( 1 , V_71 ) ;
if ( ! ( F_1 ( V_71 ) & 0x01 ) ) {
F_13 (KERN_ERR NAME L_9 ) ;
goto exit;
}
* V_11 = F_5 ( V_72 ) ;
if ( * V_11 == 0 ) {
F_13 (KERN_ERR NAME L_10 ) ;
goto exit;
}
V_65 = 0 ;
V_20 = F_1 ( V_73 ) & 0x0f ;
if ( V_20 >= 0x08 )
V_17 = 65535 ;
if ( V_16 > ( V_17 * 60 ) )
V_16 = ( V_17 * 60 ) ;
F_13 (KERN_INFO NAME L_11
L_12 ,
chip_type, revision, *address) ;
exit:
F_9 () ;
return V_65 ;
}
static int T_5 F_29 ( void )
{
int V_65 = 0 ;
if ( F_28 ( & V_11 ) )
return - V_66 ;
if ( ! F_30 ( V_11 , 1 , L_5 ) ) {
F_13 (KERN_WARNING NAME L_13 ) ;
return - V_8 ;
}
V_65 = F_16 () ;
if ( V_65 ) {
F_13 (KERN_ERR NAME L_14 ) ;
goto V_74;
}
V_65 = F_31 ( & V_75 ) ;
if ( V_65 ) {
F_13 (KERN_ERR NAME L_15 ) ;
goto V_74;
}
V_65 = F_32 ( & V_76 ) ;
if ( V_65 ) {
F_13 (KERN_ERR NAME
L_16 ,
WATCHDOG_MINOR, err) ;
goto V_77;
}
return 0 ;
V_77:
F_33 ( & V_75 ) ;
V_74:
F_10 ( V_11 , 1 ) ;
return V_65 ;
}
static void T_6 F_34 ( void )
{
F_35 ( & V_76 ) ;
F_33 ( & V_75 ) ;
F_10 ( V_11 , 1 ) ;
}
