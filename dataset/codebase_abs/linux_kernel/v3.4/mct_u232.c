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
F_11 ( L_2 , V_3 , V_14 ) ;
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
F_11 ( L_5 ,
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
static int F_14 ( struct V_1 * V_2 , unsigned char V_30 )
{
int V_15 ;
unsigned char * V_16 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL )
return - V_21 ;
V_16 [ 0 ] = V_30 ;
V_15 = F_7 ( V_2 -> V_5 , F_8 ( V_2 -> V_5 , 0 ) ,
V_31 ,
V_23 ,
0 , 0 , V_16 , V_32 ,
V_25 ) ;
if ( V_15 < 0 )
F_9 ( & V_2 -> V_5 -> V_5 ,
L_6 , V_30 , V_15 ) ;
F_11 ( L_7 , V_30 ) ;
F_13 ( V_16 ) ;
return V_15 ;
}
static int F_15 ( struct V_1 * V_2 ,
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
V_15 = F_7 ( V_2 -> V_5 , F_8 ( V_2 -> V_5 , 0 ) ,
V_40 ,
V_23 ,
0 , 0 , V_16 , V_41 ,
V_25 ) ;
if ( V_15 < 0 )
F_9 ( & V_2 -> V_5 -> V_5 ,
L_8 , V_34 , V_15 ) ;
F_11 ( L_9 , V_33 , V_34 ) ;
F_13 ( V_16 ) ;
return V_15 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned char * V_42 )
{
int V_15 ;
unsigned char * V_16 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL ) {
* V_42 = 0 ;
return - V_21 ;
}
V_15 = F_7 ( V_2 -> V_5 , F_17 ( V_2 -> V_5 , 0 ) ,
V_43 ,
V_44 ,
0 , 0 , V_16 , V_45 ,
V_25 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_2 -> V_5 -> V_5 ,
L_10 , V_15 ) ;
* V_42 = 0 ;
} else {
* V_42 = V_16 [ 0 ] ;
}
F_11 ( L_11 , * V_42 ) ;
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
static void F_19 ( unsigned int * V_33 ,
unsigned char V_42 )
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
F_11 ( L_12 , V_42 , * V_33 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
struct V_12 * V_13 , * V_66 ;
V_65 = F_21 ( sizeof( struct V_64 ) , V_20 ) ;
if ( ! V_65 )
return - V_21 ;
F_22 ( & V_65 -> V_67 ) ;
F_23 ( & V_65 -> V_68 ) ;
F_24 ( V_2 -> V_13 [ 0 ] , V_65 ) ;
F_23 ( & V_2 -> V_13 [ 0 ] -> V_69 ) ;
V_13 = V_2 -> V_13 [ 0 ] ;
V_66 = V_2 -> V_13 [ 1 ] ;
F_25 ( V_13 -> V_70 ) ;
V_13 -> V_70 = V_66 -> V_71 ;
V_66 -> V_71 = NULL ;
V_13 -> V_70 -> V_72 = V_13 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
int V_73 ;
F_11 ( L_13 , V_74 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_75 ; ++ V_73 ) {
V_65 = F_27 ( V_2 -> V_13 [ V_73 ] ) ;
F_13 ( V_65 ) ;
}
}
static int F_28 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_64 * V_65 = F_27 ( V_13 ) ;
int V_76 = 0 ;
unsigned int V_33 ;
unsigned long V_77 ;
unsigned char V_78 ;
unsigned char V_79 ;
F_11 ( L_14 , V_74 , V_13 -> V_80 ) ;
if ( F_2 ( V_2 -> V_5 -> V_6 . V_7 )
== V_8 )
V_13 -> V_81 = 16 ;
F_29 ( & V_65 -> V_67 , V_77 ) ;
if ( V_11 && ( V_11 -> V_82 -> V_83 & V_84 ) )
V_65 -> V_33 = V_36 | V_38 ;
else
V_65 -> V_33 = 0 ;
V_65 -> V_78 = ( V_85 |
V_86 |
V_87 ) ;
V_33 = V_65 -> V_33 ;
V_78 = V_65 -> V_78 ;
F_30 ( & V_65 -> V_67 , V_77 ) ;
F_15 ( V_2 , V_33 ) ;
F_14 ( V_2 , V_78 ) ;
F_16 ( V_2 , & V_79 ) ;
F_29 ( & V_65 -> V_67 , V_77 ) ;
V_65 -> V_79 = V_79 ;
F_19 ( & V_65 -> V_33 , V_65 -> V_79 ) ;
F_30 ( & V_65 -> V_67 , V_77 ) ;
V_76 = F_31 ( V_13 -> V_70 , V_20 ) ;
if ( V_76 ) {
F_9 ( & V_13 -> V_5 ,
L_15 ,
V_13 -> V_70 -> V_88 , V_76 ) ;
goto error;
}
V_76 = F_31 ( V_13 -> V_71 , V_20 ) ;
if ( V_76 ) {
F_32 ( V_13 -> V_70 ) ;
F_9 ( & V_13 -> V_5 ,
L_16 ,
V_13 -> V_71 -> V_88 , V_76 ) ;
goto error;
}
return 0 ;
error:
return V_76 ;
}
static void F_33 ( struct V_12 * V_13 , int V_89 )
{
unsigned int V_33 ;
struct V_64 * V_65 = F_27 ( V_13 ) ;
F_34 ( & V_13 -> V_2 -> V_90 ) ;
if ( ! V_13 -> V_2 -> V_91 ) {
F_35 ( & V_65 -> V_67 ) ;
if ( V_89 )
V_65 -> V_33 |= V_36 | V_38 ;
else
V_65 -> V_33 &= ~ ( V_36 | V_38 ) ;
V_33 = V_65 -> V_33 ;
F_36 ( & V_65 -> V_67 ) ;
F_15 ( V_13 -> V_2 , V_33 ) ;
}
F_37 ( & V_13 -> V_2 -> V_90 ) ;
}
static void F_38 ( struct V_12 * V_13 )
{
F_11 ( L_14 , V_74 , V_13 -> V_80 ) ;
if ( V_13 -> V_2 -> V_5 ) {
F_32 ( V_13 -> V_92 ) ;
F_32 ( V_13 -> V_70 ) ;
F_32 ( V_13 -> V_71 ) ;
}
}
static void F_39 ( struct V_93 * V_93 )
{
struct V_12 * V_13 = V_93 -> V_72 ;
struct V_64 * V_65 = F_27 ( V_13 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_10 * V_11 ;
unsigned char * V_94 = V_93 -> V_95 ;
int V_76 ;
int V_96 = V_93 -> V_96 ;
unsigned long V_77 ;
switch ( V_96 ) {
case 0 :
break;
case - V_97 :
case - V_98 :
case - V_99 :
F_11 ( L_17 ,
V_74 , V_96 ) ;
return;
default:
F_11 ( L_18 ,
V_74 , V_96 ) ;
goto exit;
}
if ( ! V_2 ) {
F_11 ( L_19 , V_74 ) ;
return;
}
F_11 ( L_20 , V_74 , V_13 -> V_80 ) ;
F_40 ( V_100 , & V_13 -> V_5 , V_74 ,
V_93 -> V_101 , V_94 ) ;
if ( V_93 -> V_102 > 2 ) {
if ( V_93 -> V_101 ) {
V_11 = F_41 ( & V_13 -> V_13 ) ;
if ( V_11 ) {
F_42 ( V_11 , V_94 ,
V_93 -> V_101 ) ;
F_43 ( V_11 ) ;
}
F_44 ( V_11 ) ;
}
goto exit;
}
F_29 ( & V_65 -> V_67 , V_77 ) ;
V_65 -> V_79 = V_94 [ V_103 ] ;
F_19 ( & V_65 -> V_33 , V_65 -> V_79 ) ;
F_18 ( & V_65 -> V_47 , V_65 -> V_79 ) ;
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
F_45 ( & V_65 -> V_68 ) ;
F_30 ( & V_65 -> V_67 , V_77 ) ;
exit:
V_76 = F_31 ( V_93 , V_104 ) ;
if ( V_76 )
F_9 ( & V_13 -> V_5 ,
L_21 ,
V_74 , V_76 ) ;
}
static void F_46 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_64 * V_65 = F_27 ( V_13 ) ;
struct V_105 * V_82 = V_11 -> V_82 ;
unsigned int V_107 = V_82 -> V_83 ;
unsigned int V_108 = V_106 -> V_83 ;
unsigned long V_77 ;
unsigned int V_33 ;
unsigned char V_78 ;
F_29 ( & V_65 -> V_67 , V_77 ) ;
V_33 = V_65 -> V_33 ;
F_30 ( & V_65 -> V_67 , V_77 ) ;
V_78 = 0 ;
if ( ( V_108 & V_84 ) == V_109 ) {
F_11 ( L_22 , V_74 ) ;
V_33 |= V_36 | V_38 ;
F_15 ( V_2 , V_33 ) ;
}
F_3 ( V_11 , V_2 , V_13 , F_47 ( V_11 ) ) ;
if ( ( V_107 & V_84 ) == V_109 ) {
F_11 ( L_23 , V_74 ) ;
V_33 &= ~ ( V_36 | V_38 ) ;
F_15 ( V_2 , V_33 ) ;
}
if ( V_107 & V_110 )
V_78 |= ( V_107 & V_111 ) ?
V_112 : V_113 ;
else
V_78 |= V_86 ;
switch ( V_107 & V_114 ) {
case V_115 :
V_78 |= V_116 ; break;
case V_117 :
V_78 |= V_118 ; break;
case V_119 :
V_78 |= V_120 ; break;
case V_121 :
V_78 |= V_85 ; break;
default:
F_9 ( & V_13 -> V_5 ,
L_24 ) ;
V_78 |= V_85 ;
break;
}
V_82 -> V_83 &= ~ V_122 ;
V_78 |= ( V_107 & V_123 ) ?
V_124 : V_87 ;
F_14 ( V_2 , V_78 ) ;
F_29 ( & V_65 -> V_67 , V_77 ) ;
V_65 -> V_33 = V_33 ;
V_65 -> V_78 = V_78 ;
F_30 ( & V_65 -> V_67 , V_77 ) ;
}
static void F_48 ( struct V_10 * V_11 , int V_125 )
{
struct V_12 * V_13 = V_11 -> V_126 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_64 * V_65 = F_27 ( V_13 ) ;
unsigned char V_30 ;
unsigned long V_77 ;
F_11 ( L_25 , V_74 , V_125 ) ;
F_29 ( & V_65 -> V_67 , V_77 ) ;
V_30 = V_65 -> V_78 ;
if ( V_125 )
V_30 |= V_127 ;
F_30 ( & V_65 -> V_67 , V_77 ) ;
F_14 ( V_2 , V_30 ) ;
}
static int F_49 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_126 ;
struct V_64 * V_65 = F_27 ( V_13 ) ;
unsigned int V_33 ;
unsigned long V_77 ;
F_11 ( L_13 , V_74 ) ;
F_29 ( & V_65 -> V_67 , V_77 ) ;
V_33 = V_65 -> V_33 ;
F_30 ( & V_65 -> V_67 , V_77 ) ;
return V_33 ;
}
static int F_50 ( struct V_10 * V_11 ,
unsigned int V_128 , unsigned int V_129 )
{
struct V_12 * V_13 = V_11 -> V_126 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_64 * V_65 = F_27 ( V_13 ) ;
unsigned int V_33 ;
unsigned long V_77 ;
F_11 ( L_13 , V_74 ) ;
F_29 ( & V_65 -> V_67 , V_77 ) ;
V_33 = V_65 -> V_33 ;
if ( V_128 & V_38 )
V_33 |= V_38 ;
if ( V_128 & V_36 )
V_33 |= V_36 ;
if ( V_129 & V_38 )
V_33 &= ~ V_38 ;
if ( V_129 & V_36 )
V_33 &= ~ V_36 ;
V_65 -> V_33 = V_33 ;
F_30 ( & V_65 -> V_67 , V_77 ) ;
return F_15 ( V_2 , V_33 ) ;
}
static void F_51 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_126 ;
struct V_64 * V_65 = F_27 ( V_13 ) ;
unsigned int V_33 ;
F_11 ( L_20 , V_74 , V_13 -> V_80 ) ;
F_35 ( & V_65 -> V_67 ) ;
V_65 -> V_130 |= V_131 ;
if ( F_12 ( V_11 ) ) {
V_65 -> V_33 &= ~ V_38 ;
V_33 = V_65 -> V_33 ;
F_36 ( & V_65 -> V_67 ) ;
( void ) F_15 ( V_13 -> V_2 , V_33 ) ;
} else {
F_36 ( & V_65 -> V_67 ) ;
}
}
static void F_52 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_126 ;
struct V_64 * V_65 = F_27 ( V_13 ) ;
unsigned int V_33 ;
F_11 ( L_20 , V_74 , V_13 -> V_80 ) ;
F_35 ( & V_65 -> V_67 ) ;
if ( ( V_65 -> V_130 & V_131 ) && F_12 ( V_11 ) ) {
V_65 -> V_130 &= ~ V_131 ;
V_65 -> V_33 |= V_38 ;
V_33 = V_65 -> V_33 ;
F_36 ( & V_65 -> V_67 ) ;
( void ) F_15 ( V_13 -> V_2 , V_33 ) ;
} else {
F_36 ( & V_65 -> V_67 ) ;
}
}
static int F_53 ( struct V_10 * V_11 ,
unsigned int V_132 , unsigned long V_133 )
{
F_54 ( V_134 ) ;
struct V_12 * V_13 = V_11 -> V_126 ;
struct V_64 * V_135 = F_27 ( V_13 ) ;
struct V_46 V_136 , V_137 ;
unsigned long V_77 ;
F_11 ( L_26 , V_74 , V_13 -> V_80 , V_132 ) ;
switch ( V_132 ) {
case V_138 :
F_11 ( L_27 , V_74 , V_13 -> V_80 ) ;
F_29 ( & V_135 -> V_67 , V_77 ) ;
V_137 = V_135 -> V_47 ;
F_30 ( & V_135 -> V_67 , V_77 ) ;
for ( ; ; ) {
F_55 ( & V_135 -> V_68 ,
& V_134 , V_139 ) ;
F_56 () ;
F_57 ( & V_135 -> V_68 , & V_134 ) ;
if ( F_58 ( V_140 ) )
return - V_141 ;
F_29 ( & V_135 -> V_67 , V_77 ) ;
V_136 = V_135 -> V_47 ;
F_30 ( & V_135 -> V_67 , V_77 ) ;
if ( V_136 . V_53 == V_137 . V_53 && V_136 . V_49 == V_137 . V_49 &&
V_136 . V_55 == V_137 . V_55 && V_136 . V_51 == V_137 . V_51 )
return - V_142 ;
if ( ( ( V_133 & V_143 ) && ( V_136 . V_53 != V_137 . V_53 ) ) ||
( ( V_133 & V_57 ) && ( V_136 . V_49 != V_137 . V_49 ) ) ||
( ( V_133 & V_63 ) && ( V_136 . V_55 != V_137 . V_55 ) ) ||
( ( V_133 & V_59 ) && ( V_136 . V_51 != V_137 . V_51 ) ) ) {
return 0 ;
}
V_137 = V_136 ;
}
}
return - V_144 ;
}
static int F_59 ( struct V_10 * V_11 ,
struct V_145 * V_47 )
{
struct V_12 * V_13 = V_11 -> V_126 ;
struct V_64 * V_135 = F_27 ( V_13 ) ;
struct V_46 * V_146 = & V_135 -> V_47 ;
unsigned long V_77 ;
F_29 ( & V_135 -> V_67 , V_77 ) ;
V_47 -> V_51 = V_146 -> V_51 ;
V_47 -> V_49 = V_146 -> V_49 ;
V_47 -> V_53 = V_146 -> V_53 ;
V_47 -> V_55 = V_146 -> V_55 ;
V_47 -> V_147 = V_146 -> V_147 ;
V_47 -> V_148 = V_146 -> V_148 ;
V_47 -> V_149 = V_146 -> V_149 ;
V_47 -> V_150 = V_146 -> V_150 ;
V_47 -> V_151 = V_146 -> V_151 ;
V_47 -> V_152 = V_146 -> V_152 ;
V_47 -> V_153 = V_146 -> V_153 ;
F_30 ( & V_135 -> V_67 , V_77 ) ;
F_11 ( L_28 ,
V_74 , V_13 -> V_80 , V_47 -> V_147 , V_47 -> V_148 ) ;
return 0 ;
}
