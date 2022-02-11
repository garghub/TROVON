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
F_15 ( & V_22 -> V_27 ) ;
V_22 -> V_28 = F_1 ( V_2 ) ;
F_16 ( V_20 , V_22 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
F_3 ( V_2 , V_30 , 0 ) ;
V_22 -> V_31 = 0 ;
F_3 ( V_2 , 0x8 , 0 ) ;
V_22 -> V_32 = 0 ;
F_3 ( V_2 , V_33 , 0 ) ;
if ( ! ( V_22 -> V_28 ) ) {
F_3 ( V_2 , 0xb , 0 ) ;
} else {
F_3 ( V_2 , 0xb , 1 ) ;
F_3 ( V_2 , 0xc , 0 ) ;
F_3 ( V_2 , 0xd , 0x41 ) ;
F_3 ( V_2 , 0xa , 1 ) ;
}
F_3 ( V_2 , V_34 , V_35 ) ;
V_22 -> V_36 = F_8 ( 9600 ) ;
F_3 ( V_2 , V_37 , V_22 -> V_36 & 0xff ) ;
F_3 ( V_2 , V_38 , ( V_22 -> V_36 >> 8 ) & 0xff ) ;
V_22 -> V_39 = V_40 ;
F_3 ( V_2 , V_34 , V_40 ) ;
F_3 ( V_2 , 0xe , 0 ) ;
if ( V_22 -> V_28 )
F_3 ( V_2 , 0x9 , 0 ) ;
F_17 ( & V_2 -> V_4 -> V_4 ,
L_3 ,
V_17 ,
V_22 -> V_28 ? L_4 : L_5 ) ;
return 0 ;
}
static int F_18 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_19 ( V_20 ) ;
F_20 ( & V_22 -> V_26 ) ;
F_21 ( V_22 ) ;
return 0 ;
}
static void F_22 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = & V_42 -> V_44 ;
* V_44 = V_45 ;
V_44 -> V_46 = V_47 | V_48
| V_49 | V_50 | V_51 ;
V_44 -> V_52 = 9600 ;
V_44 -> V_53 = 9600 ;
}
static void F_23 ( struct V_41 * V_42 ,
struct V_19 * V_20 ,
struct V_43 * V_54 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = F_19 ( V_20 ) ;
struct V_43 * V_44 = & V_42 -> V_44 ;
unsigned int V_55 = V_44 -> V_46 ;
int V_13 = F_24 ( V_42 ) ;
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
#ifdef F_25
if ( V_55 & F_25 )
V_39 |= V_70 ;
#endif
V_31 = ( V_55 & V_71 ) ? 0x03 : 0x00 ;
F_26 ( & V_20 -> V_4 , L_6 , V_72 , V_13 ) ;
V_56 = 0 ;
switch ( V_13 ) {
case 0 :
V_36 = F_8 ( 9600 ) ;
break;
default:
if ( ( V_13 < 75 ) || ( V_13 > 3000000 ) )
V_13 = 9600 ;
V_36 = F_8 ( V_13 ) ;
break;
case 460800 :
V_56 = 1 ;
V_36 = F_8 ( V_13 ) ;
break;
case 921600 :
V_56 = 2 ;
V_36 = F_8 ( V_13 ) ;
break;
}
F_27 ( & V_22 -> V_26 ) ;
V_39 |= ( V_22 -> V_39 & V_73 ) ;
F_26 ( & V_20 -> V_4 , L_7 ,
V_72 , V_31 , V_39 , V_36 ) ;
if ( V_22 -> V_31 != V_31 ) {
V_22 -> V_31 = V_31 ;
F_3 ( V_2 , 0x8 , V_31 ) ;
}
if ( V_22 -> V_36 != V_36 ) {
V_22 -> V_36 = V_36 ;
V_22 -> V_39 = V_39 ;
F_3 ( V_2 , V_30 , 0 ) ;
F_3 ( V_2 , V_34 ,
V_39 | V_35 ) ;
F_3 ( V_2 , V_37 , V_36 & 0xff ) ;
F_3 ( V_2 , V_38 , ( V_36 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_34 , V_39 ) ;
F_3 ( V_2 , 0xe , V_56 ) ;
F_3 ( V_2 , V_30 , V_74 ) ;
} else if ( V_22 -> V_39 != V_39 ) {
V_22 -> V_39 = V_39 ;
F_3 ( V_2 , V_34 , V_39 ) ;
}
F_28 ( & V_22 -> V_26 ) ;
if ( F_29 ( V_42 ) || F_30 ( V_42 ) ) {
F_31 ( & V_2 -> V_4 -> V_4 ,
L_8 ,
V_17 ) ;
}
if ( F_32 ( V_44 ) )
F_33 ( V_44 , V_13 , V_13 ) ;
}
static void F_34 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
if ( V_2 -> V_4 ) {
F_3 ( V_2 , V_30 , 0 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
F_35 ( V_20 ) ;
if ( V_2 -> V_16 )
F_36 ( V_20 -> V_75 ) ;
}
}
static int F_37 ( struct V_41 * V_42 , struct V_19 * V_20 )
{
struct V_21 * V_22 = F_19 ( V_20 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
unsigned char * V_12 ;
int V_10 ;
V_12 = F_38 ( 1 , V_23 ) ;
if ( V_12 == NULL )
return - V_24 ;
V_10 = F_39 ( V_42 , V_20 ) ;
if ( V_10 ) {
F_26 ( & V_20 -> V_4 ,
L_9 ,
V_72 , V_10 ) ;
goto V_76;
}
F_6 ( V_2 , V_77 , V_12 ) ;
V_22 -> V_78 = F_6 ( V_2 , V_79 , V_12 ) ;
V_22 -> V_80 = F_6 ( V_2 , V_81 , V_12 ) ;
V_10 = F_40 ( V_20 -> V_75 , V_23 ) ;
if ( V_10 ) {
F_10 ( & V_20 -> V_4 , L_10 ,
V_10 ) ;
F_34 ( V_20 ) ;
goto V_76;
}
F_3 ( V_20 -> V_2 , V_29 , V_82 | V_83 ) ;
F_3 ( V_20 -> V_2 , V_30 , V_74 ) ;
if ( V_42 )
F_23 ( V_42 , V_20 , NULL ) ;
V_76:
F_21 ( V_12 ) ;
return V_10 ;
}
static int F_41 ( struct V_41 * V_42 ,
struct V_84 * V_85 )
{
struct V_19 * V_20 = V_42 -> V_86 ;
struct V_21 * V_22 = F_19 ( V_20 ) ;
struct V_87 V_88 = V_22 -> V_85 ;
V_85 -> V_89 = V_88 . V_89 ;
V_85 -> V_90 = V_88 . V_90 ;
V_85 -> V_91 = V_88 . V_91 ;
V_85 -> V_92 = V_88 . V_92 ;
V_85 -> V_93 = V_88 . V_93 ;
V_85 -> V_94 = V_88 . V_94 ;
V_85 -> V_95 = V_88 . V_95 ;
V_85 -> V_96 = V_88 . V_96 ;
V_85 -> V_97 = V_88 . V_97 ;
V_85 -> V_98 = V_88 . V_98 ;
V_85 -> V_99 = V_88 . V_99 ;
return 0 ;
}
static int F_42 ( struct V_41 * V_42 ,
unsigned int V_100 , unsigned long V_101 )
{
struct V_19 * V_20 = V_42 -> V_86 ;
struct V_21 * V_22 = F_19 ( V_20 ) ;
struct V_102 V_103 ;
void T_2 * V_104 = ( void T_2 * ) V_101 ;
switch ( V_100 ) {
case V_105 :
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . type = V_106 ;
V_103 . line = V_20 -> V_2 -> V_107 ;
V_103 . V_20 = V_20 -> V_108 ;
V_103 . V_109 = 0 ;
V_103 . V_110 = 460800 ;
if ( F_43 ( V_104 , & V_103 , sizeof( V_103 ) ) )
return - V_111 ;
return 0 ;
case V_112 :
if ( F_44 ( & V_103 , V_104 , sizeof( V_103 ) ) )
return - V_111 ;
return 0 ;
case V_113 :
for (; ; ) {
struct V_87 V_114 = V_22 -> V_85 ;
F_45 ( & V_22 -> V_25 ) ;
if ( F_46 ( V_115 ) )
return - V_116 ;
if ( ( V_114 . V_91 == V_22 -> V_85 . V_91 ) &&
( V_114 . V_90 == V_22 -> V_85 . V_90 ) &&
( V_114 . V_92 == V_22 -> V_85 . V_92 ) &&
( V_114 . V_89 == V_22 -> V_85 . V_89 ) )
return - V_117 ;
if ( ( V_101 & V_118 &&
( V_114 . V_91 != V_22 -> V_85 . V_91 ) ) ||
( V_101 & V_119 &&
( V_114 . V_90 != V_22 -> V_85 . V_90 ) ) ||
( V_101 & V_120 &&
( V_114 . V_92 != V_22 -> V_85 . V_92 ) ) ||
( V_101 & V_121 &&
( V_114 . V_89 != V_22 -> V_85 . V_89 ) ) )
return 0 ;
}
break;
}
return - V_122 ;
}
static int F_47 ( struct V_41 * V_42 )
{
struct V_19 * V_20 = V_42 -> V_86 ;
struct V_21 * V_22 = F_19 ( V_20 ) ;
T_3 V_123 ;
T_3 V_124 ;
unsigned long V_125 ;
F_27 ( & V_22 -> V_26 ) ;
V_124 = V_22 -> V_32 ;
F_28 ( & V_22 -> V_26 ) ;
F_48 ( & V_22 -> V_27 , V_125 ) ;
V_123 = V_22 -> V_78 ;
F_49 ( & V_22 -> V_27 , V_125 ) ;
return ( V_123 & V_126 ? V_119 : 0 ) |
( V_123 & V_127 ? V_121 : 0 ) |
( V_123 & V_128 ? V_129 : 0 ) |
( V_123 & V_130 ? V_120 : 0 ) |
( V_124 & V_131 ? V_132 : 0 ) |
( V_124 & V_133 ? V_134 : 0 ) |
( V_124 & V_135 ? V_136 : 0 ) |
( V_124 & V_137 ? V_138 : 0 ) ;
}
static int F_50 ( struct V_41 * V_42 ,
unsigned V_139 , unsigned V_140 )
{
struct V_19 * V_20 = V_42 -> V_86 ;
struct V_21 * V_22 = F_19 ( V_20 ) ;
F_27 ( & V_22 -> V_26 ) ;
if ( V_139 & V_134 )
V_22 -> V_32 |= V_133 ;
if ( V_139 & V_132 )
V_22 -> V_32 |= V_131 ;
if ( V_139 & V_136 )
V_22 -> V_32 |= V_135 ;
if ( V_139 & V_138 )
V_22 -> V_32 |= V_137 ;
if ( V_140 & V_134 )
V_22 -> V_32 &= ~ V_133 ;
if ( V_140 & V_132 )
V_22 -> V_32 &= ~ V_131 ;
if ( V_140 & V_136 )
V_22 -> V_32 &= ~ V_135 ;
if ( V_140 & V_138 )
V_22 -> V_32 &= ~ V_137 ;
F_3 ( V_20 -> V_2 , V_33 , V_22 -> V_32 ) ;
F_28 ( & V_22 -> V_26 ) ;
return 0 ;
}
static void F_51 ( struct V_41 * V_42 , int V_141 )
{
struct V_19 * V_20 = V_42 -> V_86 ;
struct V_21 * V_22 = F_19 ( V_20 ) ;
F_27 ( & V_22 -> V_26 ) ;
if ( V_141 )
V_22 -> V_39 |= V_73 ;
else
V_22 -> V_39 &= ~ V_73 ;
F_3 ( V_20 -> V_2 , V_34 , V_22 -> V_39 ) ;
F_28 ( & V_22 -> V_26 ) ;
}
static void F_52 ( struct V_19 * V_20 , T_1 V_78 )
{
struct V_21 * V_22 = F_19 ( V_20 ) ;
unsigned long V_125 ;
F_48 ( & V_22 -> V_27 , V_125 ) ;
V_22 -> V_78 = V_78 ;
F_49 ( & V_22 -> V_27 , V_125 ) ;
if ( V_78 & V_142 ) {
if ( V_78 & V_143 )
V_22 -> V_85 . V_89 ++ ;
if ( V_78 & V_144 )
V_22 -> V_85 . V_90 ++ ;
if ( V_78 & V_145 )
V_22 -> V_85 . V_92 ++ ;
if ( V_78 & V_146 )
V_22 -> V_85 . V_91 ++ ;
F_53 ( & V_22 -> V_25 ) ;
}
}
static void F_54 ( struct V_19 * V_20 , T_1 V_80 )
{
struct V_21 * V_22 = F_19 ( V_20 ) ;
unsigned long V_125 ;
F_48 ( & V_22 -> V_27 , V_125 ) ;
V_22 -> V_80 |= V_80 ;
F_49 ( & V_22 -> V_27 , V_125 ) ;
if ( V_80 & V_147 ) {
if ( V_80 & V_148 )
V_22 -> V_85 . V_98 ++ ;
if ( V_80 & V_149 )
V_22 -> V_85 . V_95 ++ ;
if ( V_80 & V_150 )
V_22 -> V_85 . V_97 ++ ;
if ( V_80 & V_151 )
V_22 -> V_85 . V_96 ++ ;
}
}
static void F_55 ( struct V_152 * V_152 )
{
struct V_19 * V_20 = V_152 -> V_153 ;
int V_123 = V_152 -> V_123 ;
const T_1 * V_154 = V_152 -> V_155 ;
int V_10 ;
switch ( V_123 ) {
case - V_156 :
case - V_157 :
case - V_158 :
F_26 ( & V_20 -> V_4 , L_11 ,
V_72 , V_123 ) ;
return;
default:
F_26 ( & V_20 -> V_4 , L_12 ,
V_72 , V_123 ) ;
break;
case 0 :
if ( ( V_152 -> V_159 == 4 ) && ( V_154 [ 0 ] == 0xe8 ) ) {
const T_1 V_160 = V_154 [ 1 ] & V_161 ;
F_26 ( & V_20 -> V_4 , L_13 , V_72 , V_154 [ 1 ] ) ;
if ( V_160 == V_162 ) {
F_26 ( & V_20 -> V_4 , L_14 ,
V_72 , V_154 [ 3 ] ) ;
F_52 ( V_20 , V_154 [ 3 ] ) ;
break;
} else if ( V_160 == V_163 ) {
F_26 ( & V_20 -> V_4 , L_15 ,
V_72 , V_154 [ 2 ] ) ;
F_54 ( V_20 , V_154 [ 2 ] ) ;
break;
}
}
F_56 ( & V_20 -> V_4 , V_72 ,
V_152 -> V_159 ,
V_152 -> V_155 ) ;
break;
}
V_10 = F_40 ( V_152 , V_164 ) ;
if ( V_10 )
F_10 ( & V_152 -> V_4 -> V_4 ,
L_16 ,
V_72 , V_10 ) ;
}
static void F_57 ( struct V_152 * V_152 )
{
struct V_19 * V_20 = V_152 -> V_153 ;
struct V_21 * V_22 = F_19 ( V_20 ) ;
struct V_41 * V_42 ;
unsigned char * V_154 = V_152 -> V_155 ;
char V_165 = V_166 ;
unsigned long V_125 ;
T_3 V_80 ;
F_48 ( & V_22 -> V_27 , V_125 ) ;
V_80 = V_22 -> V_80 ;
V_22 -> V_80 &= ~ V_147 ;
F_49 ( & V_22 -> V_27 , V_125 ) ;
if ( ! V_152 -> V_159 )
return;
V_42 = F_58 ( & V_20 -> V_20 ) ;
if ( ! V_42 )
return;
if ( V_80 & V_147 ) {
if ( V_80 & V_148 )
V_165 = V_167 ;
else if ( V_80 & V_150 )
V_165 = V_168 ;
else if ( V_80 & V_149 )
V_165 = V_169 ;
if ( V_80 & V_151 )
F_59 ( V_42 , 0 , V_170 ) ;
}
F_60 ( V_42 , V_154 , V_165 ,
V_152 -> V_159 ) ;
F_61 ( V_42 ) ;
F_62 ( V_42 ) ;
}
