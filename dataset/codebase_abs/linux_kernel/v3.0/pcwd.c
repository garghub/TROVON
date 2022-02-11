static int F_1 ( int V_1 )
{
int V_2 ;
int V_3 ;
int V_4 , V_5 ;
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_1 ,
cmd) ;
V_3 = ( V_1 & 0x0F ) | V_8 ;
F_3 ( V_3 , V_9 . V_10 + 2 ) ;
F_4 ( V_11 ) ;
V_4 = F_5 ( V_9 . V_10 ) ;
for ( V_2 = 0 ; V_2 < 25 ; ++ V_2 ) {
V_5 = V_4 ;
V_4 = F_5 ( V_9 . V_10 ) ;
if ( V_4 == V_5 )
break;
F_4 ( 250 ) ;
}
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_2
L_3 ,
cmd, port0, last_port0) ;
return V_4 ;
}
static int F_6 ( void )
{
int V_2 , V_12 = 0 , V_13 = 0 ;
F_7 ( & V_9 . V_14 ) ;
while ( ( ! V_12 ) && ( V_13 < 3 ) ) {
V_2 = F_1 ( V_15 ) ;
if ( V_2 == 0x00 )
V_12 = 1 ;
else if ( V_2 == 0xF3 ) {
F_3 ( 0x00 , V_9 . V_10 + 2 ) ;
F_4 ( 1200 ) ;
F_3 ( 0x00 , V_9 . V_10 + 2 ) ;
F_4 ( V_11 ) ;
}
V_13 ++ ;
}
F_8 ( & V_9 . V_14 ) ;
V_9 . V_16 = V_12 ;
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_4 ,
pcwd_private.command_mode) ;
return V_12 ;
}
static void F_9 ( void )
{
F_7 ( & V_9 . V_14 ) ;
F_3 ( 0x00 , V_9 . V_10 + 2 ) ;
F_4 ( V_11 ) ;
F_8 ( & V_9 . V_14 ) ;
V_9 . V_16 = 0 ;
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_4 ,
pcwd_private.command_mode) ;
}
static inline void F_10 ( void )
{
if ( F_11 ( V_9 . V_10 ) != 0xF0 )
V_9 . V_17 = 1 ;
}
static inline void F_12 ( void )
{
int V_18 , V_19 , V_20 , V_21 ;
strcpy ( V_9 . V_22 , L_5 ) ;
if ( F_6 () ) {
V_18 = F_1 ( V_23 ) ;
V_19 = F_1 ( V_24 ) ;
V_20 = F_1 ( V_25 ) ;
V_21 = F_1 ( V_26 ) ;
sprintf ( V_9 . V_22 , L_6 ,
V_18 , V_19 , V_20 , V_21 ) ;
}
F_9 () ;
return;
}
static inline int F_13 ( void )
{
int V_27 = 0 ;
if ( F_6 () ) {
V_27 = F_1 ( V_28 ) ;
}
F_9 () ;
return V_27 ;
}
static void F_14 ( void )
{
int V_27 ;
if ( V_9 . V_29 == V_30 )
F_2 (KERN_INFO PFX
L_7 ,
pcwd_private.io_addr) ;
else if ( V_9 . V_29 == V_31 ) {
F_12 () ;
F_2 (KERN_INFO PFX L_8
L_9 ,
pcwd_private.io_addr, pcwd_private.fw_ver_str) ;
V_27 = F_13 () ;
F_2 (KERN_INFO PFX L_10
L_11 ,
option_switches,
((option_switches & 0x10) ? L_12 : L_13),
((option_switches & 0x08) ? L_12 : L_13)) ;
if ( F_6 () ) {
F_1 ( V_32 ) ;
F_9 () ;
}
}
if ( V_9 . V_17 )
F_2 (KERN_INFO PFX L_14 ) ;
if ( V_9 . V_33 & V_34 )
F_2 (KERN_INFO PFX
L_15 ) ;
if ( V_9 . V_33 & V_35 ) {
F_2 (KERN_EMERG PFX
L_16 ) ;
F_2 (KERN_EMERG PFX
L_17 ) ;
}
if ( V_9 . V_33 == 0 )
F_2 (KERN_INFO PFX
L_18 ) ;
}
static void F_15 ( unsigned long V_36 )
{
int V_37 ;
if ( F_16 ( V_38 , V_9 . V_39 ) ) {
F_7 ( & V_9 . V_14 ) ;
if ( V_9 . V_29 == V_30 ) {
V_37 = F_5 ( V_9 . V_10 ) ;
V_37 &= 0x0F ;
V_37 |= V_40 ;
F_3 ( V_37 , V_9 . V_10 + 1 ) ;
} else {
F_3 ( 0x00 , V_9 . V_10 ) ;
}
F_17 ( & V_9 . V_41 , V_38 + V_42 ) ;
F_8 ( & V_9 . V_14 ) ;
} else {
F_2 (KERN_WARNING PFX
L_19 ) ;
}
}
static int F_18 ( void )
{
int V_43 ;
V_9 . V_39 = V_38 + ( V_44 * V_45 ) ;
F_17 ( & V_9 . V_41 , V_38 + V_42 ) ;
if ( V_9 . V_29 == V_31 ) {
F_7 ( & V_9 . V_14 ) ;
F_3 ( 0x00 , V_9 . V_10 + 3 ) ;
F_4 ( V_11 ) ;
V_43 = F_5 ( V_9 . V_10 + 2 ) ;
F_8 ( & V_9 . V_14 ) ;
if ( V_43 & V_46 ) {
F_2 (KERN_INFO PFX L_20 ) ;
return - V_47 ;
}
}
if ( V_6 >= V_48 )
F_2 (KERN_DEBUG PFX L_21 ) ;
return 0 ;
}
static int F_19 ( void )
{
int V_43 ;
F_20 ( & V_9 . V_41 ) ;
if ( V_9 . V_29 == V_31 ) {
F_7 ( & V_9 . V_14 ) ;
F_3 ( 0xA5 , V_9 . V_10 + 3 ) ;
F_4 ( V_11 ) ;
F_3 ( 0xA5 , V_9 . V_10 + 3 ) ;
F_4 ( V_11 ) ;
V_43 = F_5 ( V_9 . V_10 + 2 ) ;
F_8 ( & V_9 . V_14 ) ;
if ( ( V_43 & V_46 ) == 0 ) {
F_2 (KERN_INFO PFX L_22 ) ;
return - V_47 ;
}
}
if ( V_6 >= V_48 )
F_2 (KERN_DEBUG PFX L_23 ) ;
return 0 ;
}
static int F_21 ( void )
{
V_9 . V_39 = V_38 + ( V_44 * V_45 ) ;
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_24 ) ;
return 0 ;
}
static int F_22 ( int V_49 )
{
if ( V_49 < 2 || V_49 > 7200 )
return - V_50 ;
V_44 = V_49 ;
if ( V_6 >= V_48 )
F_2 (KERN_DEBUG PFX L_25 ,
heartbeat) ;
return 0 ;
}
static int F_23 ( int * V_51 )
{
int V_3 ;
* V_51 = 0 ;
F_7 ( & V_9 . V_14 ) ;
if ( V_9 . V_29 == V_30 )
V_3 = F_11 ( V_9 . V_10 ) ;
else {
V_3 = F_11 ( V_9 . V_10 + 1 ) ;
}
F_8 ( & V_9 . V_14 ) ;
if ( V_9 . V_29 == V_30 ) {
if ( V_3 & V_40 )
* V_51 |= V_34 ;
if ( V_3 & V_52 ) {
* V_51 |= V_35 ;
if ( V_53 ) {
F_2 (KERN_INFO PFX
L_26 ) ;
F_24 () ;
}
}
} else {
if ( V_3 & V_54 )
* V_51 |= V_34 ;
if ( V_3 & V_55 ) {
* V_51 |= V_35 ;
if ( V_53 ) {
F_2 (KERN_INFO PFX
L_26 ) ;
F_24 () ;
}
}
}
return 0 ;
}
static int F_25 ( void )
{
int V_3 ;
if ( V_9 . V_29 == V_31 ) {
F_7 ( & V_9 . V_14 ) ;
if ( V_6 >= V_48 )
F_2 (KERN_INFO PFX
L_27 ) ;
V_3 = F_5 ( V_9 . V_10 + 1 ) ;
if ( V_6 >= V_7 ) {
F_2 (KERN_DEBUG PFX L_28 ,
control_status) ;
F_2 (KERN_DEBUG PFX L_29 ,
(control_status & WD_REVC_R2DS)) ;
}
F_3 ( ( V_3 & V_56 ) ,
V_9 . V_10 + 1 ) ;
F_8 ( & V_9 . V_14 ) ;
}
return 0 ;
}
static int F_26 ( int * V_57 )
{
if ( V_9 . V_16 )
return - 1 ;
* V_57 = 0 ;
if ( ! V_9 . V_17 )
return - V_58 ;
F_7 ( & V_9 . V_14 ) ;
* V_57 = ( ( F_11 ( V_9 . V_10 ) ) * 9 / 5 ) + 32 ;
F_8 ( & V_9 . V_14 ) ;
if ( V_6 >= V_7 ) {
F_2 (KERN_DEBUG PFX L_30 ,
*temperature) ;
}
return 0 ;
}
static long F_27 ( struct V_59 * V_59 , unsigned int V_1 , unsigned long V_60 )
{
int V_61 ;
int V_51 ;
int V_57 ;
int V_62 ;
int T_1 * V_63 = ( int T_1 * ) V_60 ;
static const struct V_64 V_65 = {
. V_66 = V_35 |
V_34 |
V_67 |
V_68 |
V_69 ,
. V_70 = 1 ,
. V_71 = L_31 ,
} ;
switch ( V_1 ) {
case V_72 :
if ( F_28 ( V_63 , & V_65 , sizeof( V_65 ) ) )
return - V_73 ;
return 0 ;
case V_74 :
F_23 ( & V_51 ) ;
return F_29 ( V_51 , V_63 ) ;
case V_75 :
return F_29 ( V_9 . V_33 , V_63 ) ;
case V_76 :
if ( F_26 ( & V_57 ) )
return - V_73 ;
return F_29 ( V_57 , V_63 ) ;
case V_77 :
if ( V_9 . V_29 == V_31 ) {
if ( F_30 ( V_61 , V_63 ) )
return - V_73 ;
if ( V_61 & V_78 ) {
V_51 = F_19 () ;
if ( V_51 < 0 )
return V_51 ;
}
if ( V_61 & V_79 ) {
V_51 = F_18 () ;
if ( V_51 < 0 )
return V_51 ;
}
if ( V_61 & V_80 )
V_53 = 1 ;
}
return - V_50 ;
case V_81 :
F_21 () ;
return 0 ;
case V_82 :
if ( F_30 ( V_62 , V_63 ) )
return - V_73 ;
if ( F_22 ( V_62 ) )
return - V_50 ;
F_21 () ;
case V_83 :
return F_29 ( V_44 , V_63 ) ;
default:
return - V_84 ;
}
return 0 ;
}
static T_2 F_31 ( struct V_59 * V_59 , const char T_1 * V_85 , T_3 V_86 ,
T_4 * V_87 )
{
if ( V_86 ) {
if ( ! V_88 ) {
T_3 V_2 ;
V_89 = 0 ;
for ( V_2 = 0 ; V_2 != V_86 ; V_2 ++ ) {
char V_90 ;
if ( F_30 ( V_90 , V_85 + V_2 ) )
return - V_73 ;
if ( V_90 == 'V' )
V_89 = 42 ;
}
}
F_21 () ;
}
return V_86 ;
}
static int F_32 ( struct V_91 * V_91 , struct V_59 * V_59 )
{
if ( F_33 ( 0 , & V_92 ) )
return - V_93 ;
if ( V_88 )
F_34 ( V_94 ) ;
F_18 () ;
F_21 () ;
return F_35 ( V_91 , V_59 ) ;
}
static int F_36 ( struct V_91 * V_91 , struct V_59 * V_59 )
{
if ( V_89 == 42 )
F_19 () ;
else {
F_2 (KERN_CRIT PFX
L_32 ) ;
F_21 () ;
}
V_89 = 0 ;
F_37 ( 0 , & V_92 ) ;
return 0 ;
}
static T_2 F_38 ( struct V_59 * V_59 , char T_1 * V_85 , T_3 V_13 ,
T_4 * V_87 )
{
int V_57 ;
if ( F_26 ( & V_57 ) )
return - V_73 ;
if ( F_28 ( V_85 , & V_57 , 1 ) )
return - V_73 ;
return 1 ;
}
static int F_39 ( struct V_91 * V_91 , struct V_59 * V_59 )
{
if ( ! V_9 . V_17 )
return - V_58 ;
return F_35 ( V_91 , V_59 ) ;
}
static int F_40 ( struct V_91 * V_91 , struct V_59 * V_59 )
{
return 0 ;
}
static inline int F_41 ( void )
{
int V_95 = V_31 ;
F_7 ( & V_9 . V_14 ) ;
if ( ( F_11 ( V_9 . V_10 + 2 ) == 0xFF ) ||
( F_11 ( V_9 . V_10 + 3 ) == 0xFF ) )
V_95 = V_30 ;
F_8 ( & V_9 . V_14 ) ;
return V_95 ;
}
static int T_5 F_42 ( struct V_96 * V_97 , unsigned int V_98 )
{
int V_99 = V_100 [ V_98 ] ;
int V_4 , V_5 ;
int V_101 , V_102 ;
int V_2 ;
int V_103 ;
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_33 ,
id) ;
if ( ! F_43 ( V_99 , 4 , L_31 ) ) {
F_2 (KERN_INFO PFX L_34 , base_addr) ;
return 0 ;
}
V_103 = 0 ;
V_4 = F_5 ( V_99 ) ;
V_101 = F_5 ( V_99 + 1 ) ;
if ( V_4 != 0xff || V_101 != 0xff ) {
for ( V_2 = 0 ; V_2 < 4 ; ++ V_2 ) {
F_44 ( 500 ) ;
V_5 = V_4 ;
V_102 = V_101 ;
V_4 = F_5 ( V_99 ) ;
V_101 = F_5 ( V_99 + 1 ) ;
if ( ( V_4 ^ V_5 ) & V_104 ||
( V_101 ^ V_102 ) & V_105 ) {
V_103 = 1 ;
break;
}
}
}
F_45 ( V_99 , 4 ) ;
return V_103 ;
}
static int T_5 F_46 ( struct V_96 * V_97 , unsigned int V_98 )
{
int V_106 ;
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_35 ,
id) ;
V_107 ++ ;
if ( V_107 == 1 )
F_2 (KERN_INFO PFX L_36 ,
WATCHDOG_VERSION) ;
if ( V_107 > 1 ) {
F_2 (KERN_ERR PFX L_37 ) ;
return - V_58 ;
}
if ( V_100 [ V_98 ] == 0x0000 ) {
F_2 (KERN_ERR PFX L_38 ) ;
return - V_58 ;
}
V_9 . V_10 = V_100 [ V_98 ] ;
F_47 ( & V_9 . V_14 ) ;
V_9 . V_29 = F_41 () ;
if ( ! F_43 ( V_9 . V_10 ,
( V_9 . V_29 == V_30 ) ? 2 : 4 , L_31 ) ) {
F_2 (KERN_ERR PFX L_39 ,
pcwd_private.io_addr) ;
V_106 = - V_47 ;
goto V_108;
}
V_9 . V_17 = 0 ;
V_53 = 0 ;
V_9 . V_33 = 0x0000 ;
F_23 ( & V_9 . V_33 ) ;
F_25 () ;
F_48 ( & V_9 . V_41 , F_15 , 0 ) ;
F_19 () ;
F_10 () ;
F_14 () ;
if ( V_44 == 0 )
V_44 = V_109 [ ( F_13 () & 0x07 ) ] ;
if ( F_22 ( V_44 ) ) {
F_22 ( V_110 ) ;
F_2 (KERN_INFO PFX
L_40 ,
WATCHDOG_HEARTBEAT) ;
}
if ( V_9 . V_17 ) {
V_106 = F_49 ( & V_111 ) ;
if ( V_106 ) {
F_2 (KERN_ERR PFX
L_41 ,
TEMP_MINOR, ret) ;
goto V_112;
}
}
V_106 = F_49 ( & V_113 ) ;
if ( V_106 ) {
F_2 (KERN_ERR PFX
L_41 ,
WATCHDOG_MINOR, ret) ;
goto V_114;
}
F_2 (KERN_INFO PFX L_42 ,
heartbeat, nowayout) ;
return 0 ;
V_114:
if ( V_9 . V_17 )
F_50 ( & V_111 ) ;
V_112:
F_45 ( V_9 . V_10 ,
( V_9 . V_29 == V_30 ) ? 2 : 4 ) ;
V_108:
V_9 . V_10 = 0x0000 ;
V_107 -- ;
return V_106 ;
}
static int T_6 F_51 ( struct V_96 * V_97 , unsigned int V_98 )
{
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_43 ,
id) ;
if ( ! V_9 . V_10 )
return 1 ;
if ( ! V_88 )
F_19 () ;
F_50 ( & V_113 ) ;
if ( V_9 . V_17 )
F_50 ( & V_111 ) ;
F_45 ( V_9 . V_10 ,
( V_9 . V_29 == V_30 ) ? 2 : 4 ) ;
V_9 . V_10 = 0x0000 ;
V_107 -- ;
return 0 ;
}
static void F_52 ( struct V_96 * V_97 , unsigned int V_98 )
{
if ( V_6 >= V_7 )
F_2 (KERN_DEBUG PFX L_44 ,
id) ;
F_19 () ;
}
static int T_7 F_53 ( void )
{
return F_54 ( & V_115 , V_116 ) ;
}
static void T_8 F_55 ( void )
{
F_56 ( & V_115 ) ;
F_2 (KERN_INFO PFX L_45 ) ;
}
