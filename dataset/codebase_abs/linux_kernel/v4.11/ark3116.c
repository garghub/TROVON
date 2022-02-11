static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_2 ( V_4 -> V_5 . V_6 ) == 0x18ec &&
F_2 ( V_4 -> V_5 . V_7 ) == 0x3118 )
return 1 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_8 , T_1 V_9 )
{
int V_10 ;
V_10 = F_4 ( V_2 -> V_4 ,
F_5 ( V_2 -> V_4 , 0 ) ,
0xfe , 0x40 , V_9 , V_8 ,
NULL , 0 , V_11 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_8 , unsigned char * V_12 )
{
int V_10 ;
V_10 = F_4 ( V_2 -> V_4 ,
F_7 ( V_2 -> V_4 , 0 ) ,
0xfe , 0xc0 , 0 , V_8 ,
V_12 , 1 , V_11 ) ;
if ( V_10 < 1 ) {
F_8 ( & V_2 -> V_13 -> V_4 ,
L_1 ,
V_8 , V_10 ) ;
if ( V_10 >= 0 )
V_10 = - V_14 ;
return V_10 ;
}
return V_12 [ 0 ] ;
}
static inline int F_9 ( int V_15 )
{
return ( 12000000 + 2 * V_15 ) / ( 4 * V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 == 0 ||
V_2 -> V_17 == 0 ||
V_2 -> V_18 == 0 ) {
F_8 ( & V_2 -> V_13 -> V_4 , L_2 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_11 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_23 ;
V_23 = F_12 ( sizeof( * V_23 ) , V_24 ) ;
if ( ! V_23 )
return - V_25 ;
F_13 ( & V_23 -> V_26 ) ;
F_14 ( & V_23 -> V_27 ) ;
V_23 -> V_28 = F_1 ( V_2 ) ;
F_15 ( V_21 , V_23 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
F_3 ( V_2 , V_30 , 0 ) ;
V_23 -> V_31 = 0 ;
F_3 ( V_2 , 0x8 , 0 ) ;
V_23 -> V_32 = 0 ;
F_3 ( V_2 , V_33 , 0 ) ;
if ( ! ( V_23 -> V_28 ) ) {
F_3 ( V_2 , 0xb , 0 ) ;
} else {
F_3 ( V_2 , 0xb , 1 ) ;
F_3 ( V_2 , 0xc , 0 ) ;
F_3 ( V_2 , 0xd , 0x41 ) ;
F_3 ( V_2 , 0xa , 1 ) ;
}
F_3 ( V_2 , V_34 , V_35 ) ;
V_23 -> V_36 = F_9 ( 9600 ) ;
F_3 ( V_2 , V_37 , V_23 -> V_36 & 0xff ) ;
F_3 ( V_2 , V_38 , ( V_23 -> V_36 >> 8 ) & 0xff ) ;
V_23 -> V_39 = V_40 ;
F_3 ( V_2 , V_34 , V_40 ) ;
F_3 ( V_2 , 0xe , 0 ) ;
if ( V_23 -> V_28 )
F_3 ( V_2 , 0x9 , 0 ) ;
F_16 ( & V_21 -> V_4 , L_3 , V_23 -> V_28 ? L_4 : L_5 ) ;
return 0 ;
}
static int F_17 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_18 ( V_21 ) ;
F_19 ( & V_23 -> V_26 ) ;
F_20 ( V_23 ) ;
return 0 ;
}
static void F_21 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = & V_42 -> V_44 ;
* V_44 = V_45 ;
V_44 -> V_46 = V_47 | V_48
| V_49 | V_50 | V_51 ;
V_44 -> V_52 = 9600 ;
V_44 -> V_53 = 9600 ;
}
static void F_22 ( struct V_41 * V_42 ,
struct V_20 * V_21 ,
struct V_43 * V_54 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_22 * V_23 = F_18 ( V_21 ) ;
struct V_43 * V_44 = & V_42 -> V_44 ;
unsigned int V_55 = V_44 -> V_46 ;
int V_15 = F_23 ( V_42 ) ;
int V_36 ;
T_1 V_39 , V_31 , V_56 ;
switch ( V_55 & V_57 ) {
case V_58 :
V_39 = V_59 ;
break;
case V_60 :
V_39 = V_61 ;
break;
case V_62 :
V_39 = V_63 ;
break;
default:
case V_48 :
V_39 = V_40 ;
break;
}
if ( V_55 & V_64 )
V_39 |= V_65 ;
if ( V_55 & V_66 )
V_39 |= V_67 ;
if ( ! ( V_55 & V_68 ) )
V_39 |= V_69 ;
#ifdef F_24
if ( V_55 & F_24 )
V_39 |= V_70 ;
#endif
V_31 = ( V_55 & V_71 ) ? 0x03 : 0x00 ;
F_25 ( & V_21 -> V_4 , L_6 , V_72 , V_15 ) ;
V_56 = 0 ;
switch ( V_15 ) {
case 0 :
V_36 = F_9 ( 9600 ) ;
break;
default:
if ( ( V_15 < 75 ) || ( V_15 > 3000000 ) )
V_15 = 9600 ;
V_36 = F_9 ( V_15 ) ;
break;
case 460800 :
V_56 = 1 ;
V_36 = F_9 ( V_15 ) ;
break;
case 921600 :
V_56 = 2 ;
V_36 = F_9 ( V_15 ) ;
break;
}
F_26 ( & V_23 -> V_26 ) ;
V_39 |= ( V_23 -> V_39 & V_73 ) ;
F_25 ( & V_21 -> V_4 , L_7 ,
V_72 , V_31 , V_39 , V_36 ) ;
if ( V_23 -> V_31 != V_31 ) {
V_23 -> V_31 = V_31 ;
F_3 ( V_2 , 0x8 , V_31 ) ;
}
if ( V_23 -> V_36 != V_36 ) {
V_23 -> V_36 = V_36 ;
V_23 -> V_39 = V_39 ;
F_3 ( V_2 , V_30 , 0 ) ;
F_3 ( V_2 , V_34 ,
V_39 | V_35 ) ;
F_3 ( V_2 , V_37 , V_36 & 0xff ) ;
F_3 ( V_2 , V_38 , ( V_36 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_34 , V_39 ) ;
F_3 ( V_2 , 0xe , V_56 ) ;
F_3 ( V_2 , V_30 , V_74 ) ;
} else if ( V_23 -> V_39 != V_39 ) {
V_23 -> V_39 = V_39 ;
F_3 ( V_2 , V_34 , V_39 ) ;
}
F_27 ( & V_23 -> V_26 ) ;
if ( F_28 ( V_42 ) || F_29 ( V_42 ) ) {
F_30 ( & V_21 -> V_4 ,
L_8 ) ;
}
if ( F_31 ( V_44 ) )
F_32 ( V_44 , V_15 , V_15 ) ;
}
static void F_33 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
F_3 ( V_2 , V_30 , 0 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
F_34 ( V_21 ) ;
F_35 ( V_21 -> V_75 ) ;
}
static int F_36 ( struct V_41 * V_42 , struct V_20 * V_21 )
{
struct V_22 * V_23 = F_18 ( V_21 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
unsigned char * V_12 ;
int V_10 ;
V_12 = F_37 ( 1 , V_24 ) ;
if ( V_12 == NULL )
return - V_25 ;
V_10 = F_38 ( V_42 , V_21 ) ;
if ( V_10 ) {
F_25 ( & V_21 -> V_4 ,
L_9 ,
V_72 , V_10 ) ;
goto V_76;
}
F_6 ( V_2 , V_77 , V_12 ) ;
V_10 = F_6 ( V_2 , V_78 , V_12 ) ;
if ( V_10 < 0 )
goto V_79;
V_23 -> V_80 = * V_12 ;
V_10 = F_6 ( V_2 , V_81 , V_12 ) ;
if ( V_10 < 0 )
goto V_79;
V_23 -> V_82 = * V_12 ;
V_10 = F_39 ( V_21 -> V_75 , V_24 ) ;
if ( V_10 ) {
F_8 ( & V_21 -> V_4 , L_10 ,
V_10 ) ;
goto V_79;
}
F_3 ( V_21 -> V_2 , V_29 , V_83 | V_84 ) ;
F_3 ( V_21 -> V_2 , V_30 , V_74 ) ;
if ( V_42 )
F_22 ( V_42 , V_21 , NULL ) ;
F_20 ( V_12 ) ;
return 0 ;
V_79:
F_34 ( V_21 ) ;
V_76:
F_20 ( V_12 ) ;
return V_10 ;
}
static int F_40 ( struct V_41 * V_42 ,
unsigned int V_85 , unsigned long V_86 )
{
struct V_20 * V_21 = V_42 -> V_87 ;
struct V_88 V_89 ;
void T_2 * V_90 = ( void T_2 * ) V_86 ;
switch ( V_85 ) {
case V_91 :
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . type = V_92 ;
V_89 . line = V_21 -> V_93 ;
V_89 . V_21 = V_21 -> V_94 ;
V_89 . V_95 = 0 ;
V_89 . V_96 = 460800 ;
if ( F_41 ( V_90 , & V_89 , sizeof( V_89 ) ) )
return - V_97 ;
return 0 ;
case V_98 :
if ( F_42 ( & V_89 , V_90 , sizeof( V_89 ) ) )
return - V_97 ;
return 0 ;
}
return - V_99 ;
}
static int F_43 ( struct V_41 * V_42 )
{
struct V_20 * V_21 = V_42 -> V_87 ;
struct V_22 * V_23 = F_18 ( V_21 ) ;
T_3 V_100 ;
T_3 V_101 ;
unsigned long V_102 ;
F_26 ( & V_23 -> V_26 ) ;
V_101 = V_23 -> V_32 ;
F_27 ( & V_23 -> V_26 ) ;
F_44 ( & V_23 -> V_27 , V_102 ) ;
V_100 = V_23 -> V_80 ;
F_45 ( & V_23 -> V_27 , V_102 ) ;
return ( V_100 & V_103 ? V_104 : 0 ) |
( V_100 & V_105 ? V_106 : 0 ) |
( V_100 & V_107 ? V_108 : 0 ) |
( V_100 & V_109 ? V_110 : 0 ) |
( V_101 & V_111 ? V_112 : 0 ) |
( V_101 & V_113 ? V_114 : 0 ) |
( V_101 & V_115 ? V_116 : 0 ) |
( V_101 & V_117 ? V_118 : 0 ) ;
}
static int F_46 ( struct V_41 * V_42 ,
unsigned V_119 , unsigned V_120 )
{
struct V_20 * V_21 = V_42 -> V_87 ;
struct V_22 * V_23 = F_18 ( V_21 ) ;
F_26 ( & V_23 -> V_26 ) ;
if ( V_119 & V_114 )
V_23 -> V_32 |= V_113 ;
if ( V_119 & V_112 )
V_23 -> V_32 |= V_111 ;
if ( V_119 & V_116 )
V_23 -> V_32 |= V_115 ;
if ( V_119 & V_118 )
V_23 -> V_32 |= V_117 ;
if ( V_120 & V_114 )
V_23 -> V_32 &= ~ V_113 ;
if ( V_120 & V_112 )
V_23 -> V_32 &= ~ V_111 ;
if ( V_120 & V_116 )
V_23 -> V_32 &= ~ V_115 ;
if ( V_120 & V_118 )
V_23 -> V_32 &= ~ V_117 ;
F_3 ( V_21 -> V_2 , V_33 , V_23 -> V_32 ) ;
F_27 ( & V_23 -> V_26 ) ;
return 0 ;
}
static void F_47 ( struct V_41 * V_42 , int V_121 )
{
struct V_20 * V_21 = V_42 -> V_87 ;
struct V_22 * V_23 = F_18 ( V_21 ) ;
F_26 ( & V_23 -> V_26 ) ;
if ( V_121 )
V_23 -> V_39 |= V_73 ;
else
V_23 -> V_39 &= ~ V_73 ;
F_3 ( V_21 -> V_2 , V_34 , V_23 -> V_39 ) ;
F_27 ( & V_23 -> V_26 ) ;
}
static void F_48 ( struct V_20 * V_21 , T_1 V_80 )
{
struct V_22 * V_23 = F_18 ( V_21 ) ;
unsigned long V_102 ;
F_44 ( & V_23 -> V_27 , V_102 ) ;
V_23 -> V_80 = V_80 ;
F_45 ( & V_23 -> V_27 , V_102 ) ;
if ( V_80 & V_122 ) {
if ( V_80 & V_123 )
V_21 -> V_124 . V_125 ++ ;
if ( V_80 & V_126 )
V_21 -> V_124 . V_127 ++ ;
if ( V_80 & V_128 )
V_21 -> V_124 . V_129 ++ ;
if ( V_80 & V_130 )
V_21 -> V_124 . V_131 ++ ;
F_49 ( & V_21 -> V_21 . V_132 ) ;
}
}
static void F_50 ( struct V_20 * V_21 , T_1 V_82 )
{
struct V_22 * V_23 = F_18 ( V_21 ) ;
unsigned long V_102 ;
F_44 ( & V_23 -> V_27 , V_102 ) ;
V_23 -> V_82 |= V_82 ;
F_45 ( & V_23 -> V_27 , V_102 ) ;
if ( V_82 & V_133 ) {
if ( V_82 & V_134 )
V_21 -> V_124 . V_135 ++ ;
if ( V_82 & V_136 )
V_21 -> V_124 . V_137 ++ ;
if ( V_82 & V_138 )
V_21 -> V_124 . V_139 ++ ;
if ( V_82 & V_140 )
V_21 -> V_124 . V_141 ++ ;
}
}
static void F_51 ( struct V_142 * V_142 )
{
struct V_20 * V_21 = V_142 -> V_143 ;
int V_100 = V_142 -> V_100 ;
const T_1 * V_144 = V_142 -> V_145 ;
int V_10 ;
switch ( V_100 ) {
case - V_146 :
case - V_147 :
case - V_148 :
F_25 ( & V_21 -> V_4 , L_11 ,
V_72 , V_100 ) ;
return;
default:
F_25 ( & V_21 -> V_4 , L_12 ,
V_72 , V_100 ) ;
break;
case 0 :
if ( ( V_142 -> V_149 == 4 ) && ( V_144 [ 0 ] == 0xe8 ) ) {
const T_1 V_150 = V_144 [ 1 ] & V_151 ;
F_25 ( & V_21 -> V_4 , L_13 , V_72 , V_144 [ 1 ] ) ;
if ( V_150 == V_152 ) {
F_25 ( & V_21 -> V_4 , L_14 ,
V_72 , V_144 [ 3 ] ) ;
F_48 ( V_21 , V_144 [ 3 ] ) ;
break;
} else if ( V_150 == V_153 ) {
F_25 ( & V_21 -> V_4 , L_15 ,
V_72 , V_144 [ 2 ] ) ;
F_50 ( V_21 , V_144 [ 2 ] ) ;
break;
}
}
F_52 ( & V_21 -> V_4 , V_72 ,
V_142 -> V_149 ,
V_142 -> V_145 ) ;
break;
}
V_10 = F_39 ( V_142 , V_154 ) ;
if ( V_10 )
F_8 ( & V_21 -> V_4 , L_16 ,
V_10 ) ;
}
static void F_53 ( struct V_142 * V_142 )
{
struct V_20 * V_21 = V_142 -> V_143 ;
struct V_22 * V_23 = F_18 ( V_21 ) ;
unsigned char * V_144 = V_142 -> V_145 ;
char V_155 = V_156 ;
unsigned long V_102 ;
T_3 V_82 ;
F_44 ( & V_23 -> V_27 , V_102 ) ;
V_82 = V_23 -> V_82 ;
V_23 -> V_82 &= ~ V_133 ;
F_45 ( & V_23 -> V_27 , V_102 ) ;
if ( ! V_142 -> V_149 )
return;
if ( V_82 & V_133 ) {
if ( V_82 & V_134 )
V_155 = V_157 ;
else if ( V_82 & V_138 )
V_155 = V_158 ;
else if ( V_82 & V_136 )
V_155 = V_159 ;
if ( V_82 & V_140 )
F_54 ( & V_21 -> V_21 , 0 , V_160 ) ;
}
F_55 ( & V_21 -> V_21 , V_144 , V_155 ,
V_142 -> V_149 ) ;
F_56 ( & V_21 -> V_21 ) ;
}
