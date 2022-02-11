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
if ( V_10 < 0 )
return V_10 ;
else
return V_12 [ 0 ] ;
}
static inline int F_8 ( int V_13 )
{
return ( 12000000 + 2 * V_13 ) / ( 4 * V_13 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_14 == 0 ) ||
( V_2 -> V_15 == 0 ) ||
( V_2 -> V_16 == 0 ) ) {
F_10 ( & V_2 -> V_4 -> V_4 ,
L_1
L_2 ,
V_17 ,
V_2 -> V_14 ,
V_2 -> V_15 ,
V_2 -> V_16 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_11 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 ;
V_22 = F_12 ( sizeof( * V_22 ) , V_23 ) ;
if ( ! V_22 )
return - V_24 ;
F_13 ( & V_22 -> V_25 ) ;
F_14 ( & V_22 -> V_26 ) ;
V_22 -> V_27 = F_1 ( V_2 ) ;
F_15 ( V_20 , V_22 ) ;
F_3 ( V_2 , V_28 , 0 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
V_22 -> V_30 = 0 ;
F_3 ( V_2 , 0x8 , 0 ) ;
V_22 -> V_31 = 0 ;
F_3 ( V_2 , V_32 , 0 ) ;
if ( ! ( V_22 -> V_27 ) ) {
F_3 ( V_2 , 0xb , 0 ) ;
} else {
F_3 ( V_2 , 0xb , 1 ) ;
F_3 ( V_2 , 0xc , 0 ) ;
F_3 ( V_2 , 0xd , 0x41 ) ;
F_3 ( V_2 , 0xa , 1 ) ;
}
F_3 ( V_2 , V_33 , V_34 ) ;
V_22 -> V_35 = F_8 ( 9600 ) ;
F_3 ( V_2 , V_36 , V_22 -> V_35 & 0xff ) ;
F_3 ( V_2 , V_37 , ( V_22 -> V_35 >> 8 ) & 0xff ) ;
V_22 -> V_38 = V_39 ;
F_3 ( V_2 , V_33 , V_39 ) ;
F_3 ( V_2 , 0xe , 0 ) ;
if ( V_22 -> V_27 )
F_3 ( V_2 , 0x9 , 0 ) ;
F_16 ( & V_2 -> V_4 -> V_4 ,
L_3 ,
V_17 ,
V_22 -> V_27 ? L_4 : L_5 ) ;
return 0 ;
}
static int F_17 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_18 ( V_20 ) ;
F_19 ( & V_22 -> V_25 ) ;
F_20 ( V_22 ) ;
return 0 ;
}
static void F_21 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = & V_41 -> V_43 ;
* V_43 = V_44 ;
V_43 -> V_45 = V_46 | V_47
| V_48 | V_49 | V_50 ;
V_43 -> V_51 = 9600 ;
V_43 -> V_52 = 9600 ;
}
static void F_22 ( struct V_40 * V_41 ,
struct V_19 * V_20 ,
struct V_42 * V_53 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = F_18 ( V_20 ) ;
struct V_42 * V_43 = & V_41 -> V_43 ;
unsigned int V_54 = V_43 -> V_45 ;
int V_13 = F_23 ( V_41 ) ;
int V_35 ;
T_1 V_38 , V_30 , V_55 ;
switch ( V_54 & V_56 ) {
case V_57 :
V_38 = V_58 ;
break;
case V_59 :
V_38 = V_60 ;
break;
case V_61 :
V_38 = V_62 ;
break;
default:
case V_47 :
V_38 = V_39 ;
break;
}
if ( V_54 & V_63 )
V_38 |= V_64 ;
if ( V_54 & V_65 )
V_38 |= V_66 ;
if ( ! ( V_54 & V_67 ) )
V_38 |= V_68 ;
#ifdef F_24
if ( V_54 & F_24 )
V_38 |= V_69 ;
#endif
V_30 = ( V_54 & V_70 ) ? 0x03 : 0x00 ;
F_25 ( & V_20 -> V_4 , L_6 , V_71 , V_13 ) ;
V_55 = 0 ;
switch ( V_13 ) {
case 0 :
V_35 = F_8 ( 9600 ) ;
break;
default:
if ( ( V_13 < 75 ) || ( V_13 > 3000000 ) )
V_13 = 9600 ;
V_35 = F_8 ( V_13 ) ;
break;
case 460800 :
V_55 = 1 ;
V_35 = F_8 ( V_13 ) ;
break;
case 921600 :
V_55 = 2 ;
V_35 = F_8 ( V_13 ) ;
break;
}
F_26 ( & V_22 -> V_25 ) ;
V_38 |= ( V_22 -> V_38 & V_72 ) ;
F_25 ( & V_20 -> V_4 , L_7 ,
V_71 , V_30 , V_38 , V_35 ) ;
if ( V_22 -> V_30 != V_30 ) {
V_22 -> V_30 = V_30 ;
F_3 ( V_2 , 0x8 , V_30 ) ;
}
if ( V_22 -> V_35 != V_35 ) {
V_22 -> V_35 = V_35 ;
V_22 -> V_38 = V_38 ;
F_3 ( V_2 , V_29 , 0 ) ;
F_3 ( V_2 , V_33 ,
V_38 | V_34 ) ;
F_3 ( V_2 , V_36 , V_35 & 0xff ) ;
F_3 ( V_2 , V_37 , ( V_35 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_33 , V_38 ) ;
F_3 ( V_2 , 0xe , V_55 ) ;
F_3 ( V_2 , V_29 , V_73 ) ;
} else if ( V_22 -> V_38 != V_38 ) {
V_22 -> V_38 = V_38 ;
F_3 ( V_2 , V_33 , V_38 ) ;
}
F_27 ( & V_22 -> V_25 ) ;
if ( F_28 ( V_41 ) || F_29 ( V_41 ) ) {
F_30 ( & V_2 -> V_4 -> V_4 ,
L_8 ,
V_17 ) ;
}
if ( F_31 ( V_43 ) )
F_32 ( V_43 , V_13 , V_13 ) ;
}
static void F_33 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
if ( V_2 -> V_4 ) {
F_3 ( V_2 , V_29 , 0 ) ;
F_3 ( V_2 , V_28 , 0 ) ;
F_34 ( V_20 ) ;
if ( V_2 -> V_16 )
F_35 ( V_20 -> V_74 ) ;
}
}
static int F_36 ( struct V_40 * V_41 , struct V_19 * V_20 )
{
struct V_21 * V_22 = F_18 ( V_20 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
unsigned char * V_12 ;
int V_10 ;
V_12 = F_37 ( 1 , V_23 ) ;
if ( V_12 == NULL )
return - V_24 ;
V_10 = F_38 ( V_41 , V_20 ) ;
if ( V_10 ) {
F_25 ( & V_20 -> V_4 ,
L_9 ,
V_71 , V_10 ) ;
goto V_75;
}
F_6 ( V_2 , V_76 , V_12 ) ;
V_22 -> V_77 = F_6 ( V_2 , V_78 , V_12 ) ;
V_22 -> V_79 = F_6 ( V_2 , V_80 , V_12 ) ;
V_10 = F_39 ( V_20 -> V_74 , V_23 ) ;
if ( V_10 ) {
F_10 ( & V_20 -> V_4 , L_10 ,
V_10 ) ;
F_33 ( V_20 ) ;
goto V_75;
}
F_3 ( V_20 -> V_2 , V_28 , V_81 | V_82 ) ;
F_3 ( V_20 -> V_2 , V_29 , V_73 ) ;
if ( V_41 )
F_22 ( V_41 , V_20 , NULL ) ;
V_75:
F_20 ( V_12 ) ;
return V_10 ;
}
static int F_40 ( struct V_40 * V_41 ,
struct V_83 * V_84 )
{
struct V_19 * V_20 = V_41 -> V_85 ;
struct V_21 * V_22 = F_18 ( V_20 ) ;
struct V_86 V_87 = V_22 -> V_84 ;
V_84 -> V_88 = V_87 . V_88 ;
V_84 -> V_89 = V_87 . V_89 ;
V_84 -> V_90 = V_87 . V_90 ;
V_84 -> V_91 = V_87 . V_91 ;
V_84 -> V_92 = V_87 . V_92 ;
V_84 -> V_93 = V_87 . V_93 ;
V_84 -> V_94 = V_87 . V_94 ;
V_84 -> V_95 = V_87 . V_95 ;
V_84 -> V_96 = V_87 . V_96 ;
V_84 -> V_97 = V_87 . V_97 ;
V_84 -> V_98 = V_87 . V_98 ;
return 0 ;
}
static int F_41 ( struct V_40 * V_41 ,
unsigned int V_99 , unsigned long V_100 )
{
struct V_19 * V_20 = V_41 -> V_85 ;
struct V_21 * V_22 = F_18 ( V_20 ) ;
struct V_101 V_102 ;
void T_2 * V_103 = ( void T_2 * ) V_100 ;
switch ( V_99 ) {
case V_104 :
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . type = V_105 ;
V_102 . line = V_20 -> V_2 -> V_106 ;
V_102 . V_20 = V_20 -> V_107 ;
V_102 . V_108 = 0 ;
V_102 . V_109 = 460800 ;
if ( F_42 ( V_103 , & V_102 , sizeof( V_102 ) ) )
return - V_110 ;
return 0 ;
case V_111 :
if ( F_43 ( & V_102 , V_103 , sizeof( V_102 ) ) )
return - V_110 ;
return 0 ;
case V_112 :
for (; ; ) {
struct V_86 V_113 = V_22 -> V_84 ;
F_44 ( & V_20 -> V_114 ) ;
if ( F_45 ( V_115 ) )
return - V_116 ;
if ( V_20 -> V_2 -> V_117 )
return - V_118 ;
if ( ( V_113 . V_90 == V_22 -> V_84 . V_90 ) &&
( V_113 . V_89 == V_22 -> V_84 . V_89 ) &&
( V_113 . V_91 == V_22 -> V_84 . V_91 ) &&
( V_113 . V_88 == V_22 -> V_84 . V_88 ) )
return - V_118 ;
if ( ( V_100 & V_119 &&
( V_113 . V_90 != V_22 -> V_84 . V_90 ) ) ||
( V_100 & V_120 &&
( V_113 . V_89 != V_22 -> V_84 . V_89 ) ) ||
( V_100 & V_121 &&
( V_113 . V_91 != V_22 -> V_84 . V_91 ) ) ||
( V_100 & V_122 &&
( V_113 . V_88 != V_22 -> V_84 . V_88 ) ) )
return 0 ;
}
break;
}
return - V_123 ;
}
static int F_46 ( struct V_40 * V_41 )
{
struct V_19 * V_20 = V_41 -> V_85 ;
struct V_21 * V_22 = F_18 ( V_20 ) ;
T_3 V_124 ;
T_3 V_125 ;
unsigned long V_126 ;
F_26 ( & V_22 -> V_25 ) ;
V_125 = V_22 -> V_31 ;
F_27 ( & V_22 -> V_25 ) ;
F_47 ( & V_22 -> V_26 , V_126 ) ;
V_124 = V_22 -> V_77 ;
F_48 ( & V_22 -> V_26 , V_126 ) ;
return ( V_124 & V_127 ? V_120 : 0 ) |
( V_124 & V_128 ? V_122 : 0 ) |
( V_124 & V_129 ? V_130 : 0 ) |
( V_124 & V_131 ? V_121 : 0 ) |
( V_125 & V_132 ? V_133 : 0 ) |
( V_125 & V_134 ? V_135 : 0 ) |
( V_125 & V_136 ? V_137 : 0 ) |
( V_125 & V_138 ? V_139 : 0 ) ;
}
static int F_49 ( struct V_40 * V_41 ,
unsigned V_140 , unsigned V_141 )
{
struct V_19 * V_20 = V_41 -> V_85 ;
struct V_21 * V_22 = F_18 ( V_20 ) ;
F_26 ( & V_22 -> V_25 ) ;
if ( V_140 & V_135 )
V_22 -> V_31 |= V_134 ;
if ( V_140 & V_133 )
V_22 -> V_31 |= V_132 ;
if ( V_140 & V_137 )
V_22 -> V_31 |= V_136 ;
if ( V_140 & V_139 )
V_22 -> V_31 |= V_138 ;
if ( V_141 & V_135 )
V_22 -> V_31 &= ~ V_134 ;
if ( V_141 & V_133 )
V_22 -> V_31 &= ~ V_132 ;
if ( V_141 & V_137 )
V_22 -> V_31 &= ~ V_136 ;
if ( V_141 & V_139 )
V_22 -> V_31 &= ~ V_138 ;
F_3 ( V_20 -> V_2 , V_32 , V_22 -> V_31 ) ;
F_27 ( & V_22 -> V_25 ) ;
return 0 ;
}
static void F_50 ( struct V_40 * V_41 , int V_142 )
{
struct V_19 * V_20 = V_41 -> V_85 ;
struct V_21 * V_22 = F_18 ( V_20 ) ;
F_26 ( & V_22 -> V_25 ) ;
if ( V_142 )
V_22 -> V_38 |= V_72 ;
else
V_22 -> V_38 &= ~ V_72 ;
F_3 ( V_20 -> V_2 , V_33 , V_22 -> V_38 ) ;
F_27 ( & V_22 -> V_25 ) ;
}
static void F_51 ( struct V_19 * V_20 , T_1 V_77 )
{
struct V_21 * V_22 = F_18 ( V_20 ) ;
unsigned long V_126 ;
F_47 ( & V_22 -> V_26 , V_126 ) ;
V_22 -> V_77 = V_77 ;
F_48 ( & V_22 -> V_26 , V_126 ) ;
if ( V_77 & V_143 ) {
if ( V_77 & V_144 )
V_22 -> V_84 . V_88 ++ ;
if ( V_77 & V_145 )
V_22 -> V_84 . V_89 ++ ;
if ( V_77 & V_146 )
V_22 -> V_84 . V_91 ++ ;
if ( V_77 & V_147 )
V_22 -> V_84 . V_90 ++ ;
F_52 ( & V_20 -> V_114 ) ;
}
}
static void F_53 ( struct V_19 * V_20 , T_1 V_79 )
{
struct V_21 * V_22 = F_18 ( V_20 ) ;
unsigned long V_126 ;
F_47 ( & V_22 -> V_26 , V_126 ) ;
V_22 -> V_79 |= V_79 ;
F_48 ( & V_22 -> V_26 , V_126 ) ;
if ( V_79 & V_148 ) {
if ( V_79 & V_149 )
V_22 -> V_84 . V_97 ++ ;
if ( V_79 & V_150 )
V_22 -> V_84 . V_94 ++ ;
if ( V_79 & V_151 )
V_22 -> V_84 . V_96 ++ ;
if ( V_79 & V_152 )
V_22 -> V_84 . V_95 ++ ;
}
}
static void F_54 ( struct V_153 * V_153 )
{
struct V_19 * V_20 = V_153 -> V_154 ;
int V_124 = V_153 -> V_124 ;
const T_1 * V_155 = V_153 -> V_156 ;
int V_10 ;
switch ( V_124 ) {
case - V_157 :
case - V_158 :
case - V_159 :
F_25 ( & V_20 -> V_4 , L_11 ,
V_71 , V_124 ) ;
return;
default:
F_25 ( & V_20 -> V_4 , L_12 ,
V_71 , V_124 ) ;
break;
case 0 :
if ( ( V_153 -> V_160 == 4 ) && ( V_155 [ 0 ] == 0xe8 ) ) {
const T_1 V_161 = V_155 [ 1 ] & V_162 ;
F_25 ( & V_20 -> V_4 , L_13 , V_71 , V_155 [ 1 ] ) ;
if ( V_161 == V_163 ) {
F_25 ( & V_20 -> V_4 , L_14 ,
V_71 , V_155 [ 3 ] ) ;
F_51 ( V_20 , V_155 [ 3 ] ) ;
break;
} else if ( V_161 == V_164 ) {
F_25 ( & V_20 -> V_4 , L_15 ,
V_71 , V_155 [ 2 ] ) ;
F_53 ( V_20 , V_155 [ 2 ] ) ;
break;
}
}
F_55 ( & V_20 -> V_4 , V_71 ,
V_153 -> V_160 ,
V_153 -> V_156 ) ;
break;
}
V_10 = F_39 ( V_153 , V_165 ) ;
if ( V_10 )
F_10 ( & V_153 -> V_4 -> V_4 ,
L_16 ,
V_71 , V_10 ) ;
}
static void F_56 ( struct V_153 * V_153 )
{
struct V_19 * V_20 = V_153 -> V_154 ;
struct V_21 * V_22 = F_18 ( V_20 ) ;
unsigned char * V_155 = V_153 -> V_156 ;
char V_166 = V_167 ;
unsigned long V_126 ;
T_3 V_79 ;
F_47 ( & V_22 -> V_26 , V_126 ) ;
V_79 = V_22 -> V_79 ;
V_22 -> V_79 &= ~ V_148 ;
F_48 ( & V_22 -> V_26 , V_126 ) ;
if ( ! V_153 -> V_160 )
return;
if ( V_79 & V_148 ) {
if ( V_79 & V_149 )
V_166 = V_168 ;
else if ( V_79 & V_151 )
V_166 = V_169 ;
else if ( V_79 & V_150 )
V_166 = V_170 ;
if ( V_79 & V_152 )
F_57 ( & V_20 -> V_20 , 0 , V_171 ) ;
}
F_58 ( & V_20 -> V_20 , V_155 , V_166 ,
V_153 -> V_160 ) ;
F_59 ( & V_20 -> V_20 ) ;
}
