static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 =
(struct V_2 * ) V_1 -> V_4 ;
unsigned char * V_5 = V_3 -> V_6 ;
int V_7 ;
switch ( V_1 -> V_8 ) {
case 0 :
break;
case - V_9 :
case - V_10 :
case - V_11 :
F_2 ( L_1 , V_12 ,
V_1 -> V_8 ) ;
return;
default:
F_2 ( L_2 , V_12 ,
V_1 -> V_8 ) ;
goto V_13;
}
F_2 ( L_3 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] ) ;
V_3 -> V_14 = V_5 [ 0 ] ;
V_3 -> V_15 = V_5 [ 1 ] ;
V_3 -> V_16 = V_5 [ 2 ] ;
F_3 ( & V_3 -> V_17 , 1 ) ;
V_13:
V_7 = F_4 ( V_1 , V_18 ) ;
if ( V_7 )
F_5 (KERN_ERR PFX L_4
L_5 , retval) ;
}
static int F_6 ( struct V_2 * V_3 ,
unsigned char V_19 , unsigned char * V_20 , unsigned char * V_21 )
{
int V_22 , V_23 ;
unsigned char V_24 [ 6 ] ;
if ( ( ! V_3 ) || ( ! V_3 -> V_25 ) )
return - 1 ;
V_24 [ 0 ] = V_19 ;
V_24 [ 1 ] = * V_20 ;
V_24 [ 2 ] = * V_21 ;
V_24 [ 3 ] = V_24 [ 4 ] = V_24 [ 5 ] = 0 ;
F_2 ( L_6 ,
V_24 [ 0 ] , V_24 [ 1 ] , V_24 [ 2 ] ) ;
F_3 ( & V_3 -> V_17 , 0 ) ;
if ( F_7 ( V_3 -> V_26 , F_8 ( V_3 -> V_26 , 0 ) ,
V_27 , V_28 ,
0x0200 , V_3 -> V_29 , V_24 , sizeof( V_24 ) ,
V_30 ) != sizeof( V_24 ) ) {
F_2 ( L_7
L_8 , V_19 , * V_20 , * V_21 ) ;
}
V_22 = 0 ;
for ( V_23 = 0 ; ( V_23 < V_30 ) && ( ! V_22 ) ;
V_23 ++ ) {
F_9 ( 1 ) ;
if ( F_10 ( & V_3 -> V_17 ) )
V_22 = 1 ;
}
if ( ( V_22 ) && ( V_19 == V_3 -> V_14 ) ) {
* V_20 = V_3 -> V_15 ;
* V_21 = V_3 -> V_16 ;
}
return V_22 ;
}
static int F_11 ( struct V_2 * V_3 )
{
unsigned char V_20 = 0x00 ;
unsigned char V_21 = 0x00 ;
int V_7 ;
V_7 = F_6 ( V_3 , V_31 ,
& V_20 , & V_21 ) ;
if ( ( V_7 == 0 ) || ( V_21 == 0 ) ) {
F_5 (KERN_ERR PFX
L_9 ) ;
return - 1 ;
}
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
unsigned char V_20 = 0xA5 ;
unsigned char V_21 = 0xC3 ;
int V_7 ;
V_7 = F_6 ( V_3 , V_32 ,
& V_20 , & V_21 ) ;
if ( ( V_7 == 0 ) || ( V_21 != 0 ) ) {
F_5 (KERN_ERR PFX
L_10 ) ;
return - 1 ;
}
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
unsigned char V_33 ;
F_6 ( V_3 , V_34 , & V_33 , & V_33 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , int V_35 )
{
unsigned char V_20 = V_35 / 256 ;
unsigned char V_21 = V_35 % 256 ;
if ( ( V_35 < 0x0001 ) || ( V_35 > 0xFFFF ) )
return - V_36 ;
F_6 ( V_3 , V_37 , & V_20 , & V_21 ) ;
V_38 = V_35 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
int * V_39 )
{
unsigned char V_20 , V_21 ;
F_6 ( V_3 , V_40 , & V_20 , & V_21 ) ;
* V_39 = ( V_21 * 9 / 5 ) + 32 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
int * V_41 )
{
unsigned char V_20 , V_21 ;
F_6 ( V_3 , V_42 , & V_20 , & V_21 ) ;
* V_41 = ( V_20 << 8 ) + V_21 ;
return 0 ;
}
static T_1 F_17 ( struct V_43 * V_43 , const char T_2 * V_5 ,
T_3 V_44 , T_4 * V_45 )
{
if ( V_44 ) {
if ( ! V_46 ) {
T_3 V_47 ;
V_48 = 0 ;
for ( V_47 = 0 ; V_47 != V_44 ; V_47 ++ ) {
char V_49 ;
if ( F_18 ( V_49 , V_5 + V_47 ) )
return - V_50 ;
if ( V_49 == 'V' )
V_48 = 42 ;
}
}
F_13 ( V_51 ) ;
}
return V_44 ;
}
static long F_19 ( struct V_43 * V_43 , unsigned int V_19 ,
unsigned long V_52 )
{
void T_2 * V_53 = ( void T_2 * ) V_52 ;
int T_2 * V_54 = V_53 ;
static const struct V_55 V_56 = {
. V_57 = V_58 |
V_59 |
V_60 ,
. V_61 = 1 ,
. V_62 = V_63 ,
} ;
switch ( V_19 ) {
case V_64 :
return F_20 ( V_53 , & V_56 , sizeof( V_56 ) ) ? - V_50 : 0 ;
case V_65 :
case V_66 :
return F_21 ( 0 , V_54 ) ;
case V_67 :
{
int V_39 ;
if ( F_15 ( V_51 , & V_39 ) )
return - V_50 ;
return F_21 ( V_39 , V_54 ) ;
}
case V_68 :
{
int V_69 , V_7 = - V_36 ;
if ( F_18 ( V_69 , V_54 ) )
return - V_50 ;
if ( V_69 & V_70 ) {
F_12 ( V_51 ) ;
V_7 = 0 ;
}
if ( V_69 & V_71 ) {
F_11 ( V_51 ) ;
V_7 = 0 ;
}
return V_7 ;
}
case V_72 :
F_13 ( V_51 ) ;
return 0 ;
case V_73 :
{
int V_74 ;
if ( F_18 ( V_74 , V_54 ) )
return - V_50 ;
if ( F_14 ( V_51 , V_74 ) )
return - V_36 ;
F_13 ( V_51 ) ;
}
case V_75 :
return F_21 ( V_38 , V_54 ) ;
case V_76 :
{
int V_41 ;
if ( F_16 ( V_51 , & V_41 ) )
return - V_50 ;
return F_21 ( V_41 , V_54 ) ;
}
default:
return - V_77 ;
}
}
static int F_22 ( struct V_78 * V_78 , struct V_43 * V_43 )
{
if ( F_23 ( 0 , & V_79 ) )
return - V_80 ;
F_11 ( V_51 ) ;
F_13 ( V_51 ) ;
return F_24 ( V_78 , V_43 ) ;
}
static int F_25 ( struct V_78 * V_78 , struct V_43 * V_43 )
{
if ( V_48 == 42 ) {
F_12 ( V_51 ) ;
} else {
F_5 (KERN_CRIT PFX
L_11 ) ;
F_13 ( V_51 ) ;
}
V_48 = 0 ;
F_26 ( 0 , & V_79 ) ;
return 0 ;
}
static T_1 F_27 ( struct V_43 * V_43 , char T_2 * V_5 ,
T_3 V_44 , T_4 * V_45 )
{
int V_39 ;
if ( F_15 ( V_51 , & V_39 ) )
return - V_50 ;
if ( F_20 ( V_5 , & V_39 , 1 ) )
return - V_50 ;
return 1 ;
}
static int F_28 ( struct V_78 * V_78 , struct V_43 * V_43 )
{
return F_24 ( V_78 , V_43 ) ;
}
static int F_29 ( struct V_78 * V_78 , struct V_43 * V_43 )
{
return 0 ;
}
static int F_30 ( struct V_81 * V_82 , unsigned long V_83 ,
void * V_84 )
{
if ( V_83 == V_85 || V_83 == V_86 )
F_12 ( V_51 ) ;
return V_87 ;
}
static inline void F_31 ( struct V_2 * V_3 )
{
F_32 ( V_3 -> V_88 ) ;
if ( V_3 -> V_6 != NULL )
F_33 ( V_3 -> V_26 , V_3 -> V_89 ,
V_3 -> V_6 , V_3 -> V_90 ) ;
F_34 ( V_3 ) ;
}
static int F_35 ( struct V_91 * V_92 ,
const struct V_93 * V_94 )
{
struct V_95 * V_26 = F_36 ( V_92 ) ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_2 * V_3 = NULL ;
int V_100 , V_101 ;
int V_7 = - V_102 ;
int V_103 ;
unsigned char V_104 , V_105 ;
char V_106 [ 20 ] ;
unsigned char V_107 , V_33 ;
V_108 ++ ;
if ( V_108 > 1 ) {
F_5 (KERN_ERR PFX L_12 ) ;
return - V_109 ;
}
V_97 = V_92 -> V_110 ;
if ( ! ( V_97 -> V_111 . V_112 == V_113 ) ) {
F_5 (KERN_ERR PFX
L_13 ) ;
return - V_109 ;
}
V_99 = & V_97 -> V_99 [ 0 ] . V_111 ;
if ( ! F_37 ( V_99 ) ) {
F_5 (KERN_ERR PFX L_14 ) ;
return - V_109 ;
}
V_100 = F_38 ( V_26 , V_99 -> V_114 ) ;
V_101 = F_39 ( V_26 , V_100 , F_40 ( V_100 ) ) ;
V_3 = F_41 ( sizeof( struct V_2 ) , V_115 ) ;
if ( V_3 == NULL ) {
F_5 (KERN_ERR PFX L_15 ) ;
goto error;
}
V_51 = V_3 ;
F_42 ( & V_3 -> V_116 ) ;
V_3 -> V_26 = V_26 ;
V_3 -> V_92 = V_92 ;
V_3 -> V_29 = V_97 -> V_111 . V_117 ;
V_3 -> V_89 = ( F_43 ( V_99 -> V_118 ) > 8 ?
F_43 ( V_99 -> V_118 ) : 8 ) ;
V_3 -> V_6 = F_44 ( V_26 , V_3 -> V_89 ,
V_18 , & V_3 -> V_90 ) ;
if ( ! V_3 -> V_6 ) {
F_5 (KERN_ERR PFX L_15 ) ;
goto error;
}
V_3 -> V_88 = F_45 ( 0 , V_115 ) ;
if ( ! V_3 -> V_88 ) {
F_5 (KERN_ERR PFX L_15 ) ;
goto error;
}
F_46 ( V_3 -> V_88 , V_26 , V_100 ,
V_3 -> V_6 , V_3 -> V_89 ,
F_1 , V_3 , V_99 -> V_119 ) ;
V_3 -> V_88 -> V_120 = V_3 -> V_90 ;
V_3 -> V_88 -> V_121 |= V_122 ;
if ( F_4 ( V_3 -> V_88 , V_115 ) ) {
F_5 (KERN_ERR PFX L_16 ) ;
V_7 = - V_123 ;
goto error;
}
V_3 -> V_25 = 1 ;
F_12 ( V_3 ) ;
V_103 = F_6 ( V_3 , V_124 ,
& V_104 , & V_105 ) ;
if ( V_103 )
sprintf ( V_106 , L_17 , V_104 , V_105 ) ;
else
sprintf ( V_106 , L_18 ) ;
F_5 (KERN_INFO PFX L_19 ,
fw_ver_str) ;
F_6 ( V_3 , V_125 , & V_33 ,
& V_107 ) ;
F_5 (KERN_INFO PFX L_20
L_21 ,
option_switches,
((option_switches & 0x10) ? L_22 : L_23),
((option_switches & 0x08) ? L_22 : L_23)) ;
if ( V_38 == 0 )
V_38 = V_126 [ ( V_107 & 0x07 ) ] ;
if ( F_14 ( V_3 , V_38 ) ) {
F_14 ( V_3 , V_127 ) ;
F_5 (KERN_INFO PFX
L_24 ,
WATCHDOG_HEARTBEAT) ;
}
V_7 = F_47 ( & V_128 ) ;
if ( V_7 != 0 ) {
F_5 (KERN_ERR PFX
L_25 ,
retval) ;
goto error;
}
V_7 = F_48 ( & V_129 ) ;
if ( V_7 != 0 ) {
F_5 (KERN_ERR PFX
L_26 ,
TEMP_MINOR, retval) ;
goto V_130;
}
V_7 = F_48 ( & V_131 ) ;
if ( V_7 != 0 ) {
F_5 (KERN_ERR PFX
L_26 ,
WATCHDOG_MINOR, retval) ;
goto V_132;
}
F_49 ( V_92 , V_3 ) ;
F_5 (KERN_INFO PFX L_27 ,
heartbeat, nowayout) ;
return 0 ;
V_132:
F_50 ( & V_129 ) ;
V_130:
F_51 ( & V_128 ) ;
error:
if ( V_3 )
F_31 ( V_3 ) ;
V_51 = NULL ;
return V_7 ;
}
static void F_52 ( struct V_91 * V_92 )
{
struct V_2 * V_3 ;
F_53 ( & V_133 ) ;
V_3 = F_54 ( V_92 ) ;
F_49 ( V_92 , NULL ) ;
F_53 ( & V_3 -> V_116 ) ;
if ( ! V_46 )
F_12 ( V_3 ) ;
V_3 -> V_25 = 0 ;
F_50 ( & V_131 ) ;
F_50 ( & V_129 ) ;
F_51 ( & V_128 ) ;
F_55 ( & V_3 -> V_116 ) ;
F_31 ( V_3 ) ;
V_108 -- ;
F_55 ( & V_133 ) ;
F_5 (KERN_INFO PFX L_28 ) ;
}
