static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
* V_4 = V_3 ;
if ( F_2 ( V_2 -> V_5 -> V_6 . V_7 ) == V_8
|| F_2 ( V_2 -> V_5 -> V_6 . V_7 ) == V_9 ) {
switch ( V_3 ) {
case 300 :
return 0x01 ;
case 600 :
return 0x02 ;
case 1200 :
return 0x03 ;
case 2400 :
return 0x04 ;
case 4800 :
return 0x06 ;
case 9600 :
return 0x08 ;
case 19200 :
return 0x09 ;
case 38400 :
return 0x0a ;
case 57600 :
return 0x0b ;
case 115200 :
return 0x0c ;
default:
* V_4 = 9600 ;
return 0x08 ;
}
} else {
switch ( V_3 ) {
case 300 : break;
case 600 : break;
case 1200 : break;
case 2400 : break;
case 4800 : break;
case 9600 : break;
case 19200 : break;
case 38400 : break;
case 57600 : break;
case 115200 : break;
default:
V_3 = 9600 ;
* V_4 = 9600 ;
}
return 115200 / V_3 ;
}
}
static int F_3 ( struct V_10 * V_11 ,
struct V_1 * V_2 , struct V_12 * V_13 , T_1 V_3 )
{
unsigned int V_14 ;
int V_15 ;
unsigned char * V_16 ;
unsigned char V_17 = 0 ;
T_1 V_18 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL )
return - V_21 ;
V_14 = F_1 ( V_2 , V_3 , & V_18 ) ;
F_5 ( F_6 ( V_14 ) , V_16 ) ;
V_15 = F_7 ( V_2 -> V_5 , F_8 ( V_2 -> V_5 , 0 ) ,
V_22 ,
V_23 ,
0 , 0 , V_16 , V_24 ,
V_25 ) ;
if ( V_15 < 0 )
F_9 ( & V_13 -> V_5 , L_1 ,
V_3 , V_15 ) ;
else
F_10 ( V_11 , V_18 , V_18 ) ;
F_11 ( & V_13 -> V_5 , L_2 , V_3 , V_14 ) ;
V_16 [ 0 ] = 0 ;
V_15 = F_7 ( V_2 -> V_5 , F_8 ( V_2 -> V_5 , 0 ) ,
V_26 ,
V_23 ,
0 , 0 , V_16 , V_27 ,
V_25 ) ;
if ( V_15 < 0 )
F_9 ( & V_13 -> V_5 , L_3
L_4 , V_26 ,
V_15 ) ;
if ( V_13 && F_12 ( V_11 ) )
V_17 = 1 ;
F_11 ( & V_13 -> V_5 , L_5 ,
V_17 ) ;
V_16 [ 0 ] = V_17 ;
V_15 = F_7 ( V_2 -> V_5 , F_8 ( V_2 -> V_5 , 0 ) ,
V_28 ,
V_23 ,
0 , 0 , V_16 , V_29 ,
V_25 ) ;
if ( V_15 < 0 )
F_9 ( & V_13 -> V_5 , L_3
L_4 , V_28 , V_15 ) ;
F_13 ( V_16 ) ;
return V_15 ;
}
static int F_14 ( struct V_12 * V_13 ,
unsigned char V_30 )
{
int V_15 ;
unsigned char * V_16 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL )
return - V_21 ;
V_16 [ 0 ] = V_30 ;
V_15 = F_7 ( V_13 -> V_2 -> V_5 , F_8 ( V_13 -> V_2 -> V_5 , 0 ) ,
V_31 ,
V_23 ,
0 , 0 , V_16 , V_32 ,
V_25 ) ;
if ( V_15 < 0 )
F_9 ( & V_13 -> V_5 , L_6 , V_30 , V_15 ) ;
F_11 ( & V_13 -> V_5 , L_7 , V_30 ) ;
F_13 ( V_16 ) ;
return V_15 ;
}
static int F_15 ( struct V_12 * V_13 ,
unsigned int V_33 )
{
int V_15 ;
unsigned char V_34 ;
unsigned char * V_16 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL )
return - V_21 ;
V_34 = V_35 ;
if ( V_33 & V_36 )
V_34 |= V_37 ;
if ( V_33 & V_38 )
V_34 |= V_39 ;
V_16 [ 0 ] = V_34 ;
V_15 = F_7 ( V_13 -> V_2 -> V_5 , F_8 ( V_13 -> V_2 -> V_5 , 0 ) ,
V_40 ,
V_23 ,
0 , 0 , V_16 , V_41 ,
V_25 ) ;
F_13 ( V_16 ) ;
F_11 ( & V_13 -> V_5 , L_8 , V_33 , V_34 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_13 -> V_5 , L_9 , V_34 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static int F_16 ( struct V_12 * V_13 ,
unsigned char * V_42 )
{
int V_15 ;
unsigned char * V_16 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL ) {
* V_42 = 0 ;
return - V_21 ;
}
V_15 = F_7 ( V_13 -> V_2 -> V_5 , F_17 ( V_13 -> V_2 -> V_5 , 0 ) ,
V_43 ,
V_44 ,
0 , 0 , V_16 , V_45 ,
V_25 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_13 -> V_5 , L_10 , V_15 ) ;
* V_42 = 0 ;
} else {
* V_42 = V_16 [ 0 ] ;
}
F_11 ( & V_13 -> V_5 , L_11 , * V_42 ) ;
F_13 ( V_16 ) ;
return V_15 ;
}
static void F_18 ( struct V_46 * V_47 ,
unsigned char V_42 )
{
if ( V_42 & V_48 )
V_47 -> V_49 ++ ;
if ( V_42 & V_50 )
V_47 -> V_51 ++ ;
if ( V_42 & V_52 )
V_47 -> V_53 ++ ;
if ( V_42 & V_54 )
V_47 -> V_55 ++ ;
}
static void F_19 ( struct V_12 * V_13 ,
unsigned int * V_33 , unsigned char V_42 )
{
if ( V_42 & V_56 )
* V_33 |= V_57 ;
else
* V_33 &= ~ V_57 ;
if ( V_42 & V_58 )
* V_33 |= V_59 ;
else
* V_33 &= ~ V_59 ;
if ( V_42 & V_60 )
* V_33 |= V_61 ;
else
* V_33 &= ~ V_61 ;
if ( V_42 & V_62 )
* V_33 |= V_63 ;
else
* V_33 &= ~ V_63 ;
F_11 ( & V_13 -> V_5 , L_12 , V_42 , * V_33 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_12 * V_13 , * V_64 ;
V_13 = V_2 -> V_13 [ 0 ] ;
V_64 = V_2 -> V_13 [ 1 ] ;
F_21 ( V_13 -> V_65 ) ;
V_13 -> V_65 = V_64 -> V_66 ;
V_64 -> V_66 = NULL ;
V_13 -> V_65 -> V_67 = V_13 ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 )
{
struct V_68 * V_69 ;
V_69 = F_23 ( sizeof( * V_69 ) , V_20 ) ;
if ( ! V_69 )
return - V_21 ;
F_24 ( & V_69 -> V_70 ) ;
F_25 ( & V_69 -> V_71 ) ;
F_26 ( V_13 , V_69 ) ;
return 0 ;
}
static int F_27 ( struct V_12 * V_13 )
{
struct V_68 * V_69 ;
V_69 = F_28 ( V_13 ) ;
F_13 ( V_69 ) ;
return 0 ;
}
static int F_29 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_68 * V_69 = F_28 ( V_13 ) ;
int V_72 = 0 ;
unsigned int V_33 ;
unsigned long V_73 ;
unsigned char V_74 ;
unsigned char V_75 ;
if ( F_2 ( V_2 -> V_5 -> V_6 . V_7 )
== V_8 )
V_13 -> V_76 = 16 ;
F_30 ( & V_69 -> V_70 , V_73 ) ;
if ( V_11 && ( V_11 -> V_77 . V_78 & V_79 ) )
V_69 -> V_33 = V_36 | V_38 ;
else
V_69 -> V_33 = 0 ;
V_69 -> V_74 = ( V_80 |
V_81 |
V_82 ) ;
V_33 = V_69 -> V_33 ;
V_74 = V_69 -> V_74 ;
F_31 ( & V_69 -> V_70 , V_73 ) ;
F_15 ( V_13 , V_33 ) ;
F_14 ( V_13 , V_74 ) ;
F_16 ( V_13 , & V_75 ) ;
F_30 ( & V_69 -> V_70 , V_73 ) ;
V_69 -> V_75 = V_75 ;
F_19 ( V_13 , & V_69 -> V_33 , V_69 -> V_75 ) ;
F_31 ( & V_69 -> V_70 , V_73 ) ;
V_72 = F_32 ( V_13 -> V_65 , V_20 ) ;
if ( V_72 ) {
F_9 ( & V_13 -> V_5 ,
L_13 ,
V_13 -> V_65 -> V_83 , V_72 ) ;
goto error;
}
V_72 = F_32 ( V_13 -> V_66 , V_20 ) ;
if ( V_72 ) {
F_33 ( V_13 -> V_65 ) ;
F_9 ( & V_13 -> V_5 ,
L_14 ,
V_13 -> V_66 -> V_83 , V_72 ) ;
goto error;
}
return 0 ;
error:
return V_72 ;
}
static void F_34 ( struct V_12 * V_13 , int V_84 )
{
unsigned int V_33 ;
struct V_68 * V_69 = F_28 ( V_13 ) ;
F_35 ( & V_13 -> V_2 -> V_85 ) ;
if ( ! V_13 -> V_2 -> V_86 ) {
F_36 ( & V_69 -> V_70 ) ;
if ( V_84 )
V_69 -> V_33 |= V_36 | V_38 ;
else
V_69 -> V_33 &= ~ ( V_36 | V_38 ) ;
V_33 = V_69 -> V_33 ;
F_37 ( & V_69 -> V_70 ) ;
F_15 ( V_13 , V_33 ) ;
}
F_38 ( & V_13 -> V_2 -> V_85 ) ;
}
static void F_39 ( struct V_12 * V_13 )
{
F_33 ( V_13 -> V_65 ) ;
F_33 ( V_13 -> V_66 ) ;
F_40 ( V_13 ) ;
}
static void F_41 ( struct V_87 * V_87 )
{
struct V_12 * V_13 = V_87 -> V_67 ;
struct V_68 * V_69 = F_28 ( V_13 ) ;
struct V_10 * V_11 ;
unsigned char * V_88 = V_87 -> V_89 ;
int V_72 ;
int V_90 = V_87 -> V_90 ;
unsigned long V_73 ;
switch ( V_90 ) {
case 0 :
break;
case - V_91 :
case - V_92 :
case - V_93 :
F_11 ( & V_13 -> V_5 , L_15 ,
V_94 , V_90 ) ;
return;
default:
F_11 ( & V_13 -> V_5 , L_16 ,
V_94 , V_90 ) ;
goto exit;
}
F_42 ( & V_13 -> V_5 , V_94 , V_87 -> V_95 , V_88 ) ;
if ( V_87 -> V_96 > 2 ) {
if ( V_87 -> V_95 ) {
V_11 = F_43 ( & V_13 -> V_13 ) ;
if ( V_11 ) {
F_44 ( V_11 , V_88 ,
V_87 -> V_95 ) ;
F_45 ( V_11 ) ;
}
F_46 ( V_11 ) ;
}
goto exit;
}
F_30 ( & V_69 -> V_70 , V_73 ) ;
V_69 -> V_75 = V_88 [ V_97 ] ;
F_19 ( V_13 , & V_69 -> V_33 , V_69 -> V_75 ) ;
F_18 ( & V_69 -> V_47 , V_69 -> V_75 ) ;
#if 0
priv->last_lsr = data[MCT_U232_LSR_INDEX];
if (priv->last_lsr & MCT_U232_LSR_ERR) {
tty = tty_port_tty_get(&port->port);
if (priv->last_lsr & MCT_U232_LSR_OE) {
}
if (priv->last_lsr & MCT_U232_LSR_PE) {
}
if (priv->last_lsr & MCT_U232_LSR_FE) {
}
if (priv->last_lsr & MCT_U232_LSR_BI) {
}
tty_kref_put(tty);
}
#endif
F_47 ( & V_69 -> V_71 ) ;
F_31 ( & V_69 -> V_70 , V_73 ) ;
exit:
V_72 = F_32 ( V_87 , V_98 ) ;
if ( V_72 )
F_9 ( & V_13 -> V_5 ,
L_17 ,
V_94 , V_72 ) ;
}
static void F_48 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_68 * V_69 = F_28 ( V_13 ) ;
struct V_99 * V_77 = & V_11 -> V_77 ;
unsigned int V_101 = V_77 -> V_78 ;
unsigned int V_102 = V_100 -> V_78 ;
unsigned long V_73 ;
unsigned int V_33 ;
unsigned char V_74 ;
F_30 ( & V_69 -> V_70 , V_73 ) ;
V_33 = V_69 -> V_33 ;
F_31 ( & V_69 -> V_70 , V_73 ) ;
V_74 = 0 ;
if ( ( V_102 & V_79 ) == V_103 ) {
F_11 ( & V_13 -> V_5 , L_18 , V_94 ) ;
V_33 |= V_36 | V_38 ;
F_15 ( V_13 , V_33 ) ;
}
F_3 ( V_11 , V_2 , V_13 , F_49 ( V_11 ) ) ;
if ( ( V_101 & V_79 ) == V_103 ) {
F_11 ( & V_13 -> V_5 , L_19 , V_94 ) ;
V_33 &= ~ ( V_36 | V_38 ) ;
F_15 ( V_13 , V_33 ) ;
}
if ( V_101 & V_104 )
V_74 |= ( V_101 & V_105 ) ?
V_106 : V_107 ;
else
V_74 |= V_81 ;
switch ( V_101 & V_108 ) {
case V_109 :
V_74 |= V_110 ; break;
case V_111 :
V_74 |= V_112 ; break;
case V_113 :
V_74 |= V_114 ; break;
case V_115 :
V_74 |= V_80 ; break;
default:
F_9 ( & V_13 -> V_5 ,
L_20 ) ;
V_74 |= V_80 ;
break;
}
V_77 -> V_78 &= ~ V_116 ;
V_74 |= ( V_101 & V_117 ) ?
V_118 : V_82 ;
F_14 ( V_13 , V_74 ) ;
F_30 ( & V_69 -> V_70 , V_73 ) ;
V_69 -> V_33 = V_33 ;
V_69 -> V_74 = V_74 ;
F_31 ( & V_69 -> V_70 , V_73 ) ;
}
static void F_50 ( struct V_10 * V_11 , int V_119 )
{
struct V_12 * V_13 = V_11 -> V_120 ;
struct V_68 * V_69 = F_28 ( V_13 ) ;
unsigned char V_30 ;
unsigned long V_73 ;
F_30 ( & V_69 -> V_70 , V_73 ) ;
V_30 = V_69 -> V_74 ;
if ( V_119 )
V_30 |= V_121 ;
F_31 ( & V_69 -> V_70 , V_73 ) ;
F_14 ( V_13 , V_30 ) ;
}
static int F_51 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_120 ;
struct V_68 * V_69 = F_28 ( V_13 ) ;
unsigned int V_33 ;
unsigned long V_73 ;
F_30 ( & V_69 -> V_70 , V_73 ) ;
V_33 = V_69 -> V_33 ;
F_31 ( & V_69 -> V_70 , V_73 ) ;
return V_33 ;
}
static int F_52 ( struct V_10 * V_11 ,
unsigned int V_122 , unsigned int V_123 )
{
struct V_12 * V_13 = V_11 -> V_120 ;
struct V_68 * V_69 = F_28 ( V_13 ) ;
unsigned int V_33 ;
unsigned long V_73 ;
F_30 ( & V_69 -> V_70 , V_73 ) ;
V_33 = V_69 -> V_33 ;
if ( V_122 & V_38 )
V_33 |= V_38 ;
if ( V_122 & V_36 )
V_33 |= V_36 ;
if ( V_123 & V_38 )
V_33 &= ~ V_38 ;
if ( V_123 & V_36 )
V_33 &= ~ V_36 ;
V_69 -> V_33 = V_33 ;
F_31 ( & V_69 -> V_70 , V_73 ) ;
return F_15 ( V_13 , V_33 ) ;
}
static void F_53 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_120 ;
struct V_68 * V_69 = F_28 ( V_13 ) ;
unsigned int V_33 ;
F_36 ( & V_69 -> V_70 ) ;
V_69 -> V_124 |= V_125 ;
if ( F_12 ( V_11 ) ) {
V_69 -> V_33 &= ~ V_38 ;
V_33 = V_69 -> V_33 ;
F_37 ( & V_69 -> V_70 ) ;
F_15 ( V_13 , V_33 ) ;
} else {
F_37 ( & V_69 -> V_70 ) ;
}
}
static void F_54 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_120 ;
struct V_68 * V_69 = F_28 ( V_13 ) ;
unsigned int V_33 ;
F_36 ( & V_69 -> V_70 ) ;
if ( ( V_69 -> V_124 & V_125 ) && F_12 ( V_11 ) ) {
V_69 -> V_124 &= ~ V_125 ;
V_69 -> V_33 |= V_38 ;
V_33 = V_69 -> V_33 ;
F_37 ( & V_69 -> V_70 ) ;
F_15 ( V_13 , V_33 ) ;
} else {
F_37 ( & V_69 -> V_70 ) ;
}
}
static int F_55 ( struct V_10 * V_11 ,
unsigned int V_126 , unsigned long V_127 )
{
F_56 ( V_128 ) ;
struct V_12 * V_13 = V_11 -> V_120 ;
struct V_68 * V_129 = F_28 ( V_13 ) ;
struct V_46 V_130 , V_131 ;
unsigned long V_73 ;
F_11 ( & V_13 -> V_5 , L_21 , V_94 , V_126 ) ;
switch ( V_126 ) {
case V_132 :
F_11 ( & V_13 -> V_5 , L_22 , V_94 ) ;
F_30 ( & V_129 -> V_70 , V_73 ) ;
V_131 = V_129 -> V_47 ;
F_31 ( & V_129 -> V_70 , V_73 ) ;
for ( ; ; ) {
F_57 ( & V_129 -> V_71 ,
& V_128 , V_133 ) ;
F_58 () ;
F_59 ( & V_129 -> V_71 , & V_128 ) ;
if ( F_60 ( V_134 ) )
return - V_135 ;
F_30 ( & V_129 -> V_70 , V_73 ) ;
V_130 = V_129 -> V_47 ;
F_31 ( & V_129 -> V_70 , V_73 ) ;
if ( V_130 . V_53 == V_131 . V_53 && V_130 . V_49 == V_131 . V_49 &&
V_130 . V_55 == V_131 . V_55 && V_130 . V_51 == V_131 . V_51 )
return - V_136 ;
if ( ( ( V_127 & V_137 ) && ( V_130 . V_53 != V_131 . V_53 ) ) ||
( ( V_127 & V_57 ) && ( V_130 . V_49 != V_131 . V_49 ) ) ||
( ( V_127 & V_63 ) && ( V_130 . V_55 != V_131 . V_55 ) ) ||
( ( V_127 & V_59 ) && ( V_130 . V_51 != V_131 . V_51 ) ) ) {
return 0 ;
}
V_131 = V_130 ;
}
}
return - V_138 ;
}
static int F_61 ( struct V_10 * V_11 ,
struct V_139 * V_47 )
{
struct V_12 * V_13 = V_11 -> V_120 ;
struct V_68 * V_129 = F_28 ( V_13 ) ;
struct V_46 * V_140 = & V_129 -> V_47 ;
unsigned long V_73 ;
F_30 ( & V_129 -> V_70 , V_73 ) ;
V_47 -> V_51 = V_140 -> V_51 ;
V_47 -> V_49 = V_140 -> V_49 ;
V_47 -> V_53 = V_140 -> V_53 ;
V_47 -> V_55 = V_140 -> V_55 ;
V_47 -> V_141 = V_140 -> V_141 ;
V_47 -> V_142 = V_140 -> V_142 ;
V_47 -> V_143 = V_140 -> V_143 ;
V_47 -> V_144 = V_140 -> V_144 ;
V_47 -> V_145 = V_140 -> V_145 ;
V_47 -> V_146 = V_140 -> V_146 ;
V_47 -> V_147 = V_140 -> V_147 ;
F_31 ( & V_129 -> V_70 , V_73 ) ;
F_11 ( & V_13 -> V_5 , L_23 ,
V_94 , V_47 -> V_141 , V_47 -> V_142 ) ;
return 0 ;
}
