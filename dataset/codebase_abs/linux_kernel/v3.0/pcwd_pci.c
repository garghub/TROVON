static int F_1 ( int V_1 , int * V_2 , int * V_3 )
{
int V_4 , V_5 ;
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_1
L_2 , cmd, *msb, *lsb) ;
F_3 ( & V_8 . V_9 ) ;
F_4 ( * V_3 , V_8 . V_10 + 4 ) ;
F_4 ( * V_2 , V_8 . V_10 + 5 ) ;
F_4 ( V_1 , V_8 . V_10 + 6 ) ;
V_4 = F_5 ( V_8 . V_10 + 2 ) & V_11 ;
for ( V_5 = 0 ; ( V_5 < V_12 ) && ( ! V_4 ) ;
V_5 ++ ) {
F_6 ( 1 ) ;
V_4 = F_5 ( V_8 . V_10 + 2 ) & V_11 ;
}
if ( V_6 >= V_7 ) {
if ( V_4 ) {
F_2 (KERN_DEBUG PFX
L_3 ,
count) ;
} else {
F_2 (KERN_DEBUG PFX
L_4 ) ;
}
}
if ( V_4 ) {
* V_3 = F_5 ( V_8 . V_10 + 4 ) ;
* V_2 = F_5 ( V_8 . V_10 + 5 ) ;
F_5 ( V_8 . V_10 + 6 ) ;
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_5
L_6 ,
cmd, *msb, *lsb) ;
}
F_7 ( & V_8 . V_9 ) ;
return V_4 ;
}
static inline void F_8 ( void )
{
if ( F_5 ( V_8 . V_10 ) != 0xF0 )
V_8 . V_13 = 1 ;
}
static int F_9 ( void )
{
int V_14 ;
V_14 = F_5 ( V_8 . V_10 + 3 ) ;
return V_14 ;
}
static void F_10 ( void )
{
int V_15 , V_16 , V_17 ;
char V_18 [ 20 ] ;
int V_14 ;
V_15 = F_1 ( V_19 , & V_16 ,
& V_17 ) ;
if ( V_15 )
sprintf ( V_18 , L_7 , V_16 , V_17 ) ;
else
sprintf ( V_18 , L_8 ) ;
V_14 = F_9 () ;
F_2 (KERN_INFO PFX L_9
L_10 ,
(int) pcipcwd_private.io_addr, fw_ver_str,
(pcipcwd_private.supports_temp ? L_11 : L_12)) ;
F_2 (KERN_INFO PFX L_13
L_14 ,
option_switches,
((option_switches & 0x10) ? L_15 : L_16),
((option_switches & 0x08) ? L_15 : L_16)) ;
if ( V_8 . V_20 & V_21 )
F_2 (KERN_INFO PFX
L_17 ) ;
if ( V_8 . V_20 & V_22 )
F_2 (KERN_INFO PFX L_18 ) ;
if ( V_8 . V_20 == 0 )
F_2 (KERN_INFO PFX
L_19 ) ;
}
static int F_11 ( void )
{
int V_23 ;
F_3 ( & V_8 . V_9 ) ;
F_4 ( 0x00 , V_8 . V_10 + 3 ) ;
F_12 ( 1000 ) ;
V_23 = F_5 ( V_8 . V_10 + 2 ) ;
F_7 ( & V_8 . V_9 ) ;
if ( V_23 & V_24 ) {
F_2 (KERN_ERR PFX L_20 ) ;
return - 1 ;
}
if ( V_6 >= V_25 )
F_2 (KERN_DEBUG PFX L_21 ) ;
return 0 ;
}
static int F_13 ( void )
{
int V_23 ;
F_3 ( & V_8 . V_9 ) ;
F_4 ( 0xA5 , V_8 . V_10 + 3 ) ;
F_12 ( 1000 ) ;
F_4 ( 0xA5 , V_8 . V_10 + 3 ) ;
F_12 ( 1000 ) ;
V_23 = F_5 ( V_8 . V_10 + 2 ) ;
F_7 ( & V_8 . V_9 ) ;
if ( ! ( V_23 & V_24 ) ) {
F_2 (KERN_ERR PFX
L_22 ) ;
return - 1 ;
}
if ( V_6 >= V_25 )
F_2 (KERN_DEBUG PFX L_23 ) ;
return 0 ;
}
static int F_14 ( void )
{
F_3 ( & V_8 . V_9 ) ;
F_4 ( 0x42 , V_8 . V_10 ) ;
F_7 ( & V_8 . V_9 ) ;
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_24 ) ;
return 0 ;
}
static int F_15 ( int V_26 )
{
int V_27 = V_26 / 256 ;
int V_28 = V_26 % 256 ;
if ( ( V_26 < 0x0001 ) || ( V_26 > 0xFFFF ) )
return - V_29 ;
F_1 ( V_30 , & V_27 , & V_28 ) ;
V_31 = V_26 ;
if ( V_6 >= V_25 )
F_2 (KERN_DEBUG PFX L_25 ,
heartbeat) ;
return 0 ;
}
static int F_16 ( int * V_32 )
{
int V_33 ;
* V_32 = 0 ;
V_33 = F_5 ( V_8 . V_10 + 1 ) ;
if ( V_33 & V_34 )
* V_32 |= V_21 ;
if ( V_33 & V_35 ) {
* V_32 |= V_22 ;
if ( V_36 )
F_17 ( V_37 L_26 ) ;
}
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_27 ,
control_status) ;
return 0 ;
}
static int F_18 ( void )
{
int V_33 ;
int V_2 ;
int V_38 ;
if ( V_6 >= V_25 )
F_2 (KERN_INFO PFX L_28 ) ;
V_33 = F_5 ( V_8 . V_10 + 1 ) ;
if ( V_6 >= V_7 ) {
F_2 (KERN_DEBUG PFX L_29 , control_status) ;
F_2 (KERN_DEBUG PFX L_30 ,
(control_status & WD_PCI_R2DS) | WD_PCI_WTRP) ;
}
F_4 ( ( V_33 & V_39 ) | V_34 ,
V_8 . V_10 + 1 ) ;
V_2 = 0 ;
V_38 = 0xff ;
F_1 ( V_40 , & V_2 , & V_38 ) ;
if ( V_6 >= V_7 ) {
F_2 (KERN_DEBUG PFX L_31 ,
reset_counter) ;
}
return 0 ;
}
static int F_19 ( int * V_41 )
{
* V_41 = 0 ;
if ( ! V_8 . V_13 )
return - V_42 ;
F_3 ( & V_8 . V_9 ) ;
* V_41 = F_5 ( V_8 . V_10 ) ;
F_7 ( & V_8 . V_9 ) ;
* V_41 = ( * V_41 * 9 / 5 ) + 32 ;
if ( V_6 >= V_7 ) {
F_2 (KERN_DEBUG PFX L_32 ,
*temperature) ;
}
return 0 ;
}
static int F_20 ( int * V_43 )
{
int V_2 ;
int V_3 ;
F_1 ( V_44 , & V_2 , & V_3 ) ;
* V_43 = ( V_2 << 8 ) + V_3 ;
if ( V_6 >= V_25 )
F_2 (KERN_DEBUG PFX L_33 ,
*time_left) ;
return 0 ;
}
static T_1 F_21 ( struct V_45 * V_45 , const char T_2 * V_46 ,
T_3 V_47 , T_4 * V_48 )
{
if ( V_47 ) {
if ( ! V_49 ) {
T_3 V_50 ;
V_51 = 0 ;
for ( V_50 = 0 ; V_50 != V_47 ; V_50 ++ ) {
char V_52 ;
if ( F_22 ( V_52 , V_46 + V_50 ) )
return - V_53 ;
if ( V_52 == 'V' )
V_51 = 42 ;
}
}
F_14 () ;
}
return V_47 ;
}
static long F_23 ( struct V_45 * V_45 , unsigned int V_1 ,
unsigned long V_54 )
{
void T_2 * V_55 = ( void T_2 * ) V_54 ;
int T_2 * V_56 = V_55 ;
static const struct V_57 V_58 = {
. V_59 = V_22 |
V_21 |
V_60 |
V_61 |
V_62 ,
. V_63 = 1 ,
. V_64 = V_65 ,
} ;
switch ( V_1 ) {
case V_66 :
return F_24 ( V_55 , & V_58 , sizeof( V_58 ) ) ? - V_53 : 0 ;
case V_67 :
{
int V_32 ;
F_16 ( & V_32 ) ;
return F_25 ( V_32 , V_56 ) ;
}
case V_68 :
return F_25 ( V_8 . V_20 , V_56 ) ;
case V_69 :
{
int V_41 ;
if ( F_19 ( & V_41 ) )
return - V_53 ;
return F_25 ( V_41 , V_56 ) ;
}
case V_70 :
{
int V_71 , V_72 = - V_29 ;
if ( F_22 ( V_71 , V_56 ) )
return - V_53 ;
if ( V_71 & V_73 ) {
if ( F_13 () )
return - V_74 ;
V_72 = 0 ;
}
if ( V_71 & V_75 ) {
if ( F_11 () )
return - V_74 ;
V_72 = 0 ;
}
if ( V_71 & V_76 ) {
V_36 = 1 ;
V_72 = 0 ;
}
return V_72 ;
}
case V_77 :
F_14 () ;
return 0 ;
case V_78 :
{
int V_79 ;
if ( F_22 ( V_79 , V_56 ) )
return - V_53 ;
if ( F_15 ( V_79 ) )
return - V_29 ;
F_14 () ;
}
case V_80 :
return F_25 ( V_31 , V_56 ) ;
case V_81 :
{
int V_43 ;
if ( F_20 ( & V_43 ) )
return - V_53 ;
return F_25 ( V_43 , V_56 ) ;
}
default:
return - V_82 ;
}
}
static int F_26 ( struct V_83 * V_83 , struct V_45 * V_45 )
{
if ( F_27 ( 0 , & V_84 ) ) {
if ( V_6 >= V_25 )
F_2 (KERN_ERR PFX
L_34 ) ;
return - V_85 ;
}
F_11 () ;
F_14 () ;
return F_28 ( V_83 , V_45 ) ;
}
static int F_29 ( struct V_83 * V_83 , struct V_45 * V_45 )
{
if ( V_51 == 42 ) {
F_13 () ;
} else {
F_2 (KERN_CRIT PFX
L_35 ) ;
F_14 () ;
}
V_51 = 0 ;
F_30 ( 0 , & V_84 ) ;
return 0 ;
}
static T_1 F_31 ( struct V_45 * V_45 , char T_2 * V_46 ,
T_3 V_47 , T_4 * V_48 )
{
int V_41 ;
if ( F_19 ( & V_41 ) )
return - V_53 ;
if ( F_24 ( V_46 , & V_41 , 1 ) )
return - V_53 ;
return 1 ;
}
static int F_32 ( struct V_83 * V_83 , struct V_45 * V_45 )
{
if ( ! V_8 . V_13 )
return - V_42 ;
return F_28 ( V_83 , V_45 ) ;
}
static int F_33 ( struct V_83 * V_83 , struct V_45 * V_45 )
{
return 0 ;
}
static int F_34 ( struct V_86 * V_87 , unsigned long V_88 ,
void * V_89 )
{
if ( V_88 == V_90 || V_88 == V_91 )
F_13 () ;
return V_92 ;
}
static int T_5 F_35 ( struct V_93 * V_94 ,
const struct V_95 * V_96 )
{
int V_97 = - V_74 ;
V_98 ++ ;
if ( V_98 == 1 )
F_2 (KERN_INFO PFX DRIVER_VERSION) ;
if ( V_98 > 1 ) {
F_2 (KERN_ERR PFX L_36 ) ;
return - V_42 ;
}
if ( F_36 ( V_94 ) ) {
F_2 (KERN_ERR PFX L_37 ) ;
return - V_42 ;
}
if ( F_37 ( V_94 , 0 ) == 0x0000 ) {
F_2 (KERN_ERR PFX L_38 ) ;
V_97 = - V_42 ;
goto V_99;
}
V_8 . V_94 = V_94 ;
V_8 . V_10 = F_37 ( V_94 , 0 ) ;
if ( F_38 ( V_94 , V_100 ) ) {
F_2 (KERN_ERR PFX L_39 ,
(int) pcipcwd_private.io_addr) ;
V_97 = - V_74 ;
goto V_99;
}
F_16 ( & V_8 . V_20 ) ;
F_18 () ;
F_13 () ;
F_8 () ;
F_10 () ;
if ( V_31 == 0 )
V_31 =
V_101 [ ( F_9 () & 0x07 ) ] ;
if ( F_15 ( V_31 ) ) {
F_15 ( V_102 ) ;
F_2 (KERN_INFO PFX
L_40 ,
WATCHDOG_HEARTBEAT) ;
}
V_97 = F_39 ( & V_103 ) ;
if ( V_97 != 0 ) {
F_2 (KERN_ERR PFX
L_41 , ret) ;
goto V_104;
}
if ( V_8 . V_13 ) {
V_97 = F_40 ( & V_105 ) ;
if ( V_97 != 0 ) {
F_2 (KERN_ERR PFX L_42
L_43 , TEMP_MINOR, ret) ;
goto V_106;
}
}
V_97 = F_40 ( & V_107 ) ;
if ( V_97 != 0 ) {
F_2 (KERN_ERR PFX
L_44 ,
WATCHDOG_MINOR, ret) ;
goto V_108;
}
F_2 (KERN_INFO PFX L_45 ,
heartbeat, nowayout) ;
return 0 ;
V_108:
if ( V_8 . V_13 )
F_41 ( & V_105 ) ;
V_106:
F_42 ( & V_103 ) ;
V_104:
F_43 ( V_94 ) ;
V_99:
F_44 ( V_94 ) ;
return V_97 ;
}
static void T_6 F_45 ( struct V_93 * V_94 )
{
if ( ! V_49 )
F_13 () ;
F_41 ( & V_107 ) ;
if ( V_8 . V_13 )
F_41 ( & V_105 ) ;
F_42 ( & V_103 ) ;
F_43 ( V_94 ) ;
F_44 ( V_94 ) ;
V_98 -- ;
}
static int T_7 F_46 ( void )
{
F_47 ( & V_8 . V_9 ) ;
return F_48 ( & V_109 ) ;
}
static void T_8 F_49 ( void )
{
F_50 ( & V_109 ) ;
F_2 (KERN_INFO PFX L_46 ) ;
}
