static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 =
F_2 ( V_2 , struct V_4 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_3 ( & V_7 -> V_9 . V_10 ) ;
F_4 ( V_3 ) ;
F_5 ( & V_7 -> V_9 . V_10 ) ;
}
static void F_6 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
struct V_18 * V_19 ;
T_1 V_20 , V_21 ;
T_2 V_22 ;
V_19 = F_8 ( V_14 , 0 ) ;
V_20 = V_19 -> V_23 + V_14 -> V_24 [ 0 ] +
V_12 -> V_25 * V_14 -> V_26 [ 0 ] +
V_12 -> V_27 * V_14 -> V_28 -> V_29 [ 0 ] ;
V_21 = V_20 + ( V_12 -> V_30 . V_31 * V_14 -> V_26 [ 0 ] ) ;
if ( V_16 -> V_32 == 1 )
V_21 -= 1 ;
V_22 = ( T_2 ) V_21 << 32 | V_20 ;
F_9 ( V_7 , V_33 , V_22 ) ;
if ( V_4 -> V_34 )
F_10 ( & V_4 -> V_5 ,
V_4 -> V_34 ) ;
V_4 -> V_34 = V_14 ;
}
static void F_11 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
int V_35 ;
F_12 ( & V_4 -> V_36 ) ;
F_13 ( V_7 , V_33 ,
V_4 -> V_37 ) ;
F_13 ( V_7 , V_38 ,
( V_39 ) V_4 -> V_37 +
V_40 - 1 ) ;
F_14 ( V_7 , V_41 ,
F_15 ( V_42 ) ,
V_43 ) ;
if ( V_16 -> V_32 == 1 )
F_16 ( V_7 , V_41 , V_44 ) ;
else
F_13 ( V_7 , V_45 , V_46 ) ;
F_17 ( V_7 , 0xffffffff ) ;
F_16 ( V_7 , V_41 , V_47 ) ;
V_35 = F_18 ( & V_4 -> V_36 ,
F_19 ( 50 ) ) ;
if ( V_35 == 0 )
F_20 ( V_7 -> V_7 , L_1 , V_48 ) ;
F_21 ( V_7 , V_41 , V_47 ) ;
if ( V_16 -> V_32 == 1 )
F_21 ( V_7 , V_41 , V_44 ) ;
else
F_13 ( V_7 , V_49 , V_46 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 ;
F_17 ( V_7 , 0xffffffff ) ;
if ( V_16 -> V_32 == 1 ) {
F_16 ( V_7 , V_41 ,
V_50 | V_51 |
V_52 ) ;
F_16 ( V_7 , V_53 ,
V_54 ) ;
} else {
F_13 ( V_7 , V_45 ,
V_55 |
V_56 |
V_57 | V_58 ) ;
}
}
static void F_23 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 ;
if ( V_16 -> V_32 == 1 ) {
F_21 ( V_7 , V_41 ,
V_50 | V_51 |
V_52 | V_44 ) ;
F_21 ( V_7 , V_53 ,
V_54 ) ;
} else {
F_13 ( V_7 , V_49 ,
V_55 | V_46 |
V_56 |
V_57 | V_58 ) ;
}
}
static void F_24 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
if ( V_16 -> V_32 != 2 )
return;
F_16 ( V_7 , V_59 , V_60 ) ;
F_25 ( 250 , 1000 ) ;
F_21 ( V_7 , V_59 , V_60 ) ;
}
static unsigned int F_26 ( unsigned long V_61 ,
unsigned long V_62 )
{
int V_63 = V_61 / 100 , V_64 = V_62 / 100 ;
return ( unsigned int ) ( abs ( ( ( V_64 - V_63 ) * 100 ) / V_63 ) ) ;
}
static void F_27 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
struct V_4 * V_4 = F_7 ( V_12 ) ;
unsigned long V_65 , V_62 , V_66 ;
unsigned int V_67 ;
int V_35 ;
V_67 = 2 ;
V_66 = V_12 -> V_30 . clock * 1000 ;
V_35 = F_28 ( V_16 -> V_68 , V_66 * V_67 ) ;
V_65 = F_29 ( V_16 -> V_68 ) ;
if ( V_35 < 0 ) {
if ( ! V_65 ) {
F_20 ( V_7 -> V_7 ,
L_2 ) ;
return;
}
V_67 = F_30 ( V_65 , V_66 ) ;
V_62 = V_67 * V_66 ;
if ( F_26 ( V_65 , V_62 ) > 5 ) {
F_31 ( V_7 -> V_7 ,
L_3 ,
V_65 , V_62 ) ;
}
}
V_4 -> V_69 = V_65 ;
F_32 ( L_4 ,
V_4 -> V_69 , V_12 -> V_30 . clock , V_67 ) ;
F_13 ( V_7 , V_70 , F_33 ( V_67 ) |
V_71 ) ;
if ( V_16 -> V_32 == 2 )
F_16 ( V_7 , V_72 ,
V_73 | V_74 |
V_75 ) ;
}
static void F_34 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
const struct V_76 * V_77 = V_4 -> V_77 ;
T_3 V_78 , V_79 , V_80 , V_81 , V_82 , V_83 , V_84 ;
struct V_85 * V_30 = & V_12 -> V_86 -> V_87 ;
struct V_13 * V_14 = V_12 -> V_88 -> V_86 -> V_14 ;
if ( F_35 ( ! V_77 ) )
return;
if ( F_35 ( ! V_14 ) )
return;
V_78 = F_36 ( V_7 , V_53 ) & ~ 0x00000770 ;
switch ( V_77 -> V_89 ) {
case 1 :
V_78 |= F_37 ( V_90 ) ;
break;
case 2 :
V_78 |= F_37 ( V_91 ) ;
break;
case 4 :
V_78 |= F_37 ( V_92 ) ;
break;
case 8 :
V_78 |= F_37 ( V_93 ) ;
break;
case 16 :
V_78 |= F_37 ( V_94 ) ;
break;
default:
F_20 ( V_7 -> V_7 , L_5 ) ;
return;
}
V_78 |= ( V_77 -> V_95 << 8 ) ;
F_13 ( V_7 , V_53 , V_78 ) ;
V_79 = V_30 -> V_96 - V_30 -> V_97 ;
V_80 = V_30 -> V_98 - V_30 -> V_99 ;
V_81 = V_30 -> V_97 - V_30 -> V_98 ;
V_82 = V_30 -> V_100 - V_30 -> V_101 ;
V_83 = V_30 -> V_102 - V_30 -> V_31 ;
V_84 = V_30 -> V_101 - V_30 -> V_102 ;
F_32 ( L_6 ,
V_30 -> V_99 , V_30 -> V_31 , V_79 , V_80 , V_81 , V_82 , V_83 , V_84 ) ;
V_78 = F_36 ( V_7 , V_103 ) & ~ 0x000fff00 ;
V_78 |= F_38 ( V_77 -> V_104 ) |
F_39 ( V_77 -> V_105 ) ;
if ( V_16 -> V_32 == 2 ) {
V_78 &= ~ 0x78000033 ;
V_78 |= ( ( V_80 - 1 ) & 0x300 ) >> 8 ;
V_78 |= ( ( V_79 - 1 ) & 0x300 ) >> 4 ;
V_78 |= ( ( V_81 - 1 ) & 0x3c0 ) << 21 ;
}
F_13 ( V_7 , V_103 , V_78 ) ;
V_78 = ( ( ( V_30 -> V_99 >> 4 ) - 1 ) << 4 ) |
( ( ( V_79 - 1 ) & 0xff ) << 24 ) |
( ( ( V_80 - 1 ) & 0xff ) << 16 ) |
( ( ( V_81 - 1 ) & 0x3f ) << 10 ) ;
if ( V_16 -> V_32 == 2 )
V_78 |= ( ( ( V_30 -> V_99 >> 4 ) - 1 ) & 0x40 ) >> 3 ;
F_13 ( V_7 , V_106 , V_78 ) ;
V_78 = ( ( V_30 -> V_31 - 1 ) & 0x3ff ) |
( ( V_82 & 0xff ) << 24 ) |
( ( V_83 & 0xff ) << 16 ) |
( ( ( V_84 - 1 ) & 0x3f ) << 10 ) ;
F_13 ( V_7 , V_107 , V_78 ) ;
if ( V_16 -> V_32 == 2 ) {
if ( ( V_30 -> V_31 - 1 ) & 0x400 ) {
F_16 ( V_7 , V_103 ,
V_108 ) ;
} else {
F_21 ( V_7 , V_103 ,
V_108 ) ;
}
}
V_78 = F_36 ( V_7 , V_41 ) &
~ ( V_109 | V_110 | V_111 |
V_112 | V_113 |
0x000ff000 ) ;
V_78 |= V_109 ;
if ( V_77 -> V_114 )
V_78 |= V_115 ;
if ( V_16 -> V_32 == 2 ) {
switch ( V_14 -> V_28 -> V_28 ) {
case V_116 :
case V_117 :
break;
case V_118 :
case V_119 :
V_78 |= V_113 ;
case V_120 :
case V_121 :
V_78 |= V_112 ;
break;
default:
F_20 ( V_7 -> V_7 , L_7 ) ;
return;
}
}
V_78 |= V_77 -> V_122 < 12 ;
F_13 ( V_7 , V_41 , V_78 ) ;
if ( V_77 -> V_123 )
F_16 ( V_7 , V_103 , V_124 ) ;
else
F_21 ( V_7 , V_103 , V_124 ) ;
if ( V_77 -> V_125 )
F_16 ( V_7 , V_103 , V_126 ) ;
else
F_21 ( V_7 , V_103 , V_126 ) ;
if ( V_77 -> V_127 )
F_16 ( V_7 , V_103 , V_128 ) ;
else
F_21 ( V_7 , V_103 , V_128 ) ;
if ( V_30 -> V_129 & V_130 )
F_16 ( V_7 , V_103 , V_131 ) ;
else
F_21 ( V_7 , V_103 , V_131 ) ;
if ( V_30 -> V_129 & V_132 )
F_16 ( V_7 , V_103 , V_133 ) ;
else
F_21 ( V_7 , V_103 , V_133 ) ;
if ( V_77 -> V_134 )
F_16 ( V_7 , V_41 , V_135 ) ;
else
F_21 ( V_7 , V_41 , V_135 ) ;
F_27 ( V_12 ) ;
F_11 ( V_12 ) ;
F_6 ( V_12 , V_14 ) ;
F_40 ( V_14 ) ;
V_12 -> V_136 = V_12 -> V_86 -> V_87 ;
}
static void F_41 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_4 * V_4 = F_7 ( V_12 ) ;
unsigned long V_129 ;
F_35 ( ! F_42 ( & V_12 -> V_10 ) ) ;
F_3 ( & V_4 -> V_137 ) ;
if ( V_4 -> V_138 || V_4 -> V_139 ) {
F_5 ( & V_4 -> V_137 ) ;
return;
}
F_43 ( V_7 -> V_7 ) ;
F_24 ( V_12 ) ;
F_34 ( V_12 ) ;
F_22 ( V_7 ) ;
F_21 ( V_7 , V_53 , V_140 ) ;
F_14 ( V_7 , V_41 ,
F_15 ( V_141 ) ,
V_43 ) ;
F_44 ( & V_4 -> V_142 , V_129 ) ;
V_4 -> V_143 = F_45 () ;
F_16 ( V_7 , V_41 , V_47 ) ;
F_46 ( & V_4 -> V_142 , V_129 ) ;
F_47 ( V_12 ) ;
V_4 -> V_138 = true ;
F_5 ( & V_4 -> V_137 ) ;
}
static void F_48 ( struct V_11 * V_12 ,
struct V_144 * V_145 )
{
F_41 ( V_12 ) ;
}
static void F_49 ( struct V_11 * V_12 , bool V_139 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
int V_35 ;
F_3 ( & V_4 -> V_137 ) ;
if ( V_139 )
V_4 -> V_139 = true ;
if ( ! V_4 -> V_138 ) {
F_5 ( & V_4 -> V_137 ) ;
return;
}
V_4 -> V_146 = false ;
F_21 ( V_7 , V_41 , V_47 ) ;
V_35 = F_50 ( V_4 -> V_147 ,
V_4 -> V_146 ,
F_19 ( 500 ) ) ;
if ( V_35 == 0 )
F_20 ( V_7 -> V_7 , L_8 ,
V_48 ) ;
F_51 ( V_12 ) ;
F_23 ( V_7 ) ;
F_52 ( V_7 -> V_7 ) ;
if ( V_4 -> V_148 ) {
F_10 ( & V_4 -> V_5 ,
V_4 -> V_148 ) ;
V_4 -> V_148 = NULL ;
}
if ( V_4 -> V_34 ) {
F_10 ( & V_4 -> V_5 ,
V_4 -> V_34 ) ;
V_4 -> V_34 = NULL ;
}
F_53 ( & V_4 -> V_5 , V_16 -> V_149 ) ;
V_4 -> V_138 = false ;
F_5 ( & V_4 -> V_137 ) ;
}
static void F_54 ( struct V_11 * V_12 )
{
F_35 ( ! F_42 ( & V_12 -> V_10 ) ) ;
F_49 ( V_12 , false ) ;
}
static void F_55 ( struct V_11 * V_12 ,
struct V_144 * V_145 )
{
F_54 ( V_12 ) ;
}
void F_56 ( struct V_11 * V_12 )
{
F_49 ( V_12 , true ) ;
}
static bool F_57 ( struct V_11 * V_12 )
{
return V_12 -> V_86 && V_12 -> V_86 -> V_150 && V_12 -> V_86 -> V_151 ;
}
static void F_58 ( struct V_152 * V_2 )
{
struct V_4 * V_4 =
F_2 ( V_2 , struct V_4 , V_153 ) ;
struct V_11 * V_12 = & V_4 -> V_8 ;
F_59 ( V_12 -> V_7 -> V_7 , L_9 , V_48 ) ;
F_60 ( & V_12 -> V_10 , NULL ) ;
if ( ! F_57 ( V_12 ) )
goto V_154;
F_54 ( V_12 ) ;
F_41 ( V_12 ) ;
V_154:
F_61 ( & V_12 -> V_10 ) ;
}
static void F_62 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_15 * V_16 = V_12 -> V_7 -> V_17 ;
F_60 ( & V_12 -> V_10 , NULL ) ;
F_54 ( V_12 ) ;
F_61 ( & V_12 -> V_10 ) ;
F_63 ( V_16 -> V_149 ) ;
F_64 ( V_12 -> V_155 ) ;
F_65 ( V_12 ) ;
F_66 ( & V_4 -> V_5 ) ;
}
int F_67 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_156 * V_157 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
F_35 ( ! F_42 ( & V_12 -> V_10 ) ) ;
if ( V_4 -> V_157 ) {
F_20 ( V_7 -> V_7 , L_10 ) ;
return - V_158 ;
}
F_40 ( V_14 ) ;
V_12 -> V_88 -> V_14 = V_14 ;
V_4 -> V_157 = V_157 ;
F_3 ( & V_4 -> V_137 ) ;
if ( V_4 -> V_138 ) {
unsigned long V_129 ;
T_4 V_159 ;
T_5 V_160 ;
F_44 ( & V_4 -> V_142 , V_129 ) ;
V_159 = F_68 ( V_4 -> V_143 ,
1000000 / V_12 -> V_136 . V_161 ) ;
V_160 = F_69 ( F_70 ( V_159 , F_45 () ) ) ;
if ( V_160 < V_162 )
V_4 -> V_148 = V_14 ;
else
F_6 ( V_12 , V_14 ) ;
F_46 ( & V_4 -> V_142 , V_129 ) ;
}
F_5 ( & V_4 -> V_137 ) ;
return 0 ;
}
static bool F_71 ( struct V_11 * V_12 ,
const struct V_85 * V_30 ,
struct V_85 * V_87 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
if ( ! V_4 -> V_163 )
return true ;
V_87 -> V_164 = V_30 -> V_97 - V_30 -> V_98 ;
V_87 -> V_129 |= V_165 ;
if ( V_30 -> V_129 & V_130 ) {
V_87 -> V_129 |= V_166 ;
V_87 -> V_129 &= ~ V_130 ;
} else {
V_87 -> V_129 |= V_130 ;
V_87 -> V_129 &= ~ V_166 ;
}
return true ;
}
static int F_72 ( struct V_11 * V_12 ,
struct V_144 * V_86 )
{
struct V_85 * V_30 = & V_86 -> V_30 ;
int V_35 ;
if ( ! V_86 -> V_151 )
return 0 ;
if ( V_86 -> V_86 -> V_167 [ 0 ] . V_168 != V_12 -> V_88 ||
V_86 -> V_86 -> V_167 [ 0 ] . V_86 == NULL ||
V_86 -> V_86 -> V_167 [ 0 ] . V_86 -> V_12 != V_12 ) {
F_73 ( V_12 -> V_7 -> V_7 , L_11 ) ;
return - V_169 ;
}
V_35 = F_74 ( V_12 , V_30 ) ;
if ( V_35 ) {
F_73 ( V_12 -> V_7 -> V_7 , L_12 , V_30 -> V_170 ) ;
return - V_169 ;
}
return 0 ;
}
static int F_75 ( struct V_11 * V_12 )
{
return 0 ;
}
static void F_76 ( struct V_11 * V_12 )
{
}
int F_77 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
int V_171 = 0 ;
if ( V_16 -> V_32 == 1 )
V_171 = 1024 ;
else if ( V_16 -> V_32 == 2 )
V_171 = 2048 ;
return V_171 ;
}
int F_74 ( struct V_11 * V_12 , struct V_85 * V_30 )
{
struct V_15 * V_16 = V_12 -> V_7 -> V_17 ;
unsigned int V_172 ;
T_3 V_79 , V_80 , V_81 , V_82 , V_83 , V_84 ;
if ( V_30 -> V_99 > F_77 ( V_12 ) )
return V_173 ;
if ( V_30 -> V_99 & 0xf )
return V_173 ;
if ( V_30 -> V_31 > 2048 )
return V_174 ;
F_32 ( L_13 ,
V_30 -> V_99 , V_30 -> V_31 ,
F_78 ( V_30 ) , V_30 -> clock ) ;
V_79 = V_30 -> V_96 - V_30 -> V_97 ;
V_80 = V_30 -> V_98 - V_30 -> V_99 ;
V_81 = V_30 -> V_97 - V_30 -> V_98 ;
V_82 = V_30 -> V_100 - V_30 -> V_101 ;
V_83 = V_30 -> V_102 - V_30 -> V_31 ;
V_84 = V_30 -> V_101 - V_30 -> V_102 ;
if ( ( V_79 - 1 ) & ~ 0x3ff ) {
F_32 ( L_14 ) ;
return V_175 ;
}
if ( ( V_80 - 1 ) & ~ 0x3ff ) {
F_32 ( L_15 ) ;
return V_175 ;
}
if ( ( V_81 - 1 ) & ~ 0x3ff ) {
F_32 ( L_16 ) ;
return V_176 ;
}
if ( V_82 & ~ 0xff ) {
F_32 ( L_17 ) ;
return V_177 ;
}
if ( V_83 & ~ 0xff ) {
F_32 ( L_18 ) ;
return V_177 ;
}
if ( ( V_84 - 1 ) & ~ 0x3f ) {
F_32 ( L_19 ) ;
return V_178 ;
}
if ( V_30 -> clock > V_16 -> V_179 ) {
F_32 ( L_20 ) ;
return V_180 ;
}
if ( V_30 -> V_99 > V_16 -> V_171 )
return V_181 ;
V_172 = V_30 -> V_99 * V_30 -> V_31 *
F_78 ( V_30 ) ;
if ( V_172 > V_16 -> V_182 ) {
F_32 ( L_21 ) ;
return V_183 ;
}
return V_184 ;
}
void F_79 ( struct V_11 * V_12 ,
const struct V_76 * V_77 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_77 = V_77 ;
}
void F_80 ( struct V_11 * V_12 ,
bool V_163 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_163 = V_163 ;
}
void F_81 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
struct V_4 * V_4 = F_7 ( V_12 ) ;
F_60 ( & V_12 -> V_10 , NULL ) ;
if ( V_4 -> V_69 != F_29 ( V_16 -> V_68 ) ) {
if ( F_57 ( V_12 ) ) {
F_43 ( V_7 -> V_7 ) ;
F_54 ( V_12 ) ;
F_27 ( V_12 ) ;
F_41 ( V_12 ) ;
F_52 ( V_7 -> V_7 ) ;
}
}
F_61 ( & V_12 -> V_10 ) ;
}
T_6 F_82 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
T_3 V_185 , V_78 ;
V_185 = F_83 ( V_7 ) ;
F_17 ( V_7 , V_185 ) ;
if ( V_185 & V_186 ) {
unsigned long V_129 ;
bool V_187 = false ;
T_4 V_188 ;
V_188 = F_45 () ;
F_53 ( & V_4 -> V_5 , V_16 -> V_149 ) ;
F_44 ( & V_4 -> V_142 , V_129 ) ;
V_4 -> V_143 = V_188 ;
if ( V_4 -> V_148 ) {
F_6 ( V_12 , V_4 -> V_148 ) ;
V_4 -> V_148 = NULL ;
V_187 = true ;
}
F_46 ( & V_4 -> V_142 , V_129 ) ;
F_84 ( V_12 ) ;
if ( ! V_187 ) {
struct V_156 * V_157 ;
F_44 ( & V_7 -> V_189 , V_129 ) ;
V_157 = V_4 -> V_157 ;
V_4 -> V_157 = NULL ;
if ( V_157 )
F_85 ( V_12 , V_157 ) ;
F_46 ( & V_7 -> V_189 , V_129 ) ;
}
if ( V_4 -> V_190 )
V_4 -> V_191 = 0 ;
else
V_4 -> V_190 = true ;
}
if ( V_185 & V_192 )
F_86 ( V_7 -> V_7 , L_22 ,
V_48 , V_185 ) ;
if ( V_185 & V_193 ) {
F_87 ( & V_4 -> V_36 ) ;
if ( V_16 -> V_32 == 1 )
F_21 ( V_7 , V_41 ,
V_44 ) ;
else
F_13 ( V_7 , V_49 ,
V_46 ) ;
}
if ( V_185 & V_58 ) {
F_86 ( V_7 -> V_7 , L_23 ,
V_48 , V_185 ) ;
V_4 -> V_190 = false ;
if ( V_16 -> V_32 == 1 ) {
V_78 = F_36 ( V_7 , V_41 ) ;
if ( V_78 & V_47 ) {
F_21 ( V_7 , V_41 ,
V_47 ) ;
F_16 ( V_7 , V_41 ,
V_47 ) ;
}
} else {
if ( V_4 -> V_191 ++ >
V_194 ) {
F_20 ( V_7 -> V_7 ,
L_24 ,
V_48 , V_185 ) ;
F_88 ( V_195 ,
& V_4 -> V_153 ) ;
F_13 ( V_7 , V_49 ,
V_58 ) ;
V_4 -> V_191 = 0 ;
}
}
}
if ( V_185 & V_57 ) {
V_4 -> V_146 = true ;
F_89 ( & V_4 -> V_147 ) ;
if ( V_16 -> V_32 == 1 )
F_21 ( V_7 , V_41 ,
V_51 ) ;
}
if ( V_16 -> V_32 == 2 ) {
F_13 ( V_7 , V_196 , 0 ) ;
}
return V_197 ;
}
int F_90 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 ;
struct V_4 * V_4 ;
struct V_11 * V_12 ;
int V_35 ;
V_4 = F_91 ( V_7 -> V_7 , sizeof( * V_4 ) , V_198 ) ;
if ( ! V_4 ) {
F_20 ( V_7 -> V_7 , L_25 ) ;
return - V_199 ;
}
F_92 ( & V_4 -> V_36 ) ;
V_4 -> V_200 = F_93 ( V_7 -> V_7 ,
V_40 ,
& V_4 -> V_37 ,
V_198 | V_201 ) ;
if ( ! V_4 -> V_200 )
return - V_199 ;
* V_4 -> V_200 = V_202 ;
V_12 = & V_4 -> V_8 ;
V_35 = F_94 ( V_7 , & V_4 -> V_88 ) ;
if ( V_35 < 0 )
goto V_203;
F_95 ( & V_4 -> V_137 ) ;
F_96 ( & V_4 -> V_147 ) ;
F_97 ( & V_4 -> V_5 ,
L_26 , F_1 ) ;
F_98 ( & V_4 -> V_142 ) ;
F_99 ( & V_4 -> V_153 , F_58 ) ;
V_35 = F_100 ( V_7 , V_12 ,
& V_4 -> V_88 ,
NULL ,
& V_204 ,
L_27 ) ;
if ( V_35 < 0 )
goto V_203;
F_101 ( V_12 , & V_205 ) ;
if ( V_16 -> V_206 ) {
V_12 -> V_155 = F_102 ( V_7 -> V_7 -> V_207 , 0 ) ;
if ( ! V_12 -> V_155 ) {
F_20 ( V_7 -> V_7 , L_28 ,
V_7 -> V_7 -> V_207 ) ;
V_35 = - V_169 ;
goto V_203;
}
}
V_16 -> V_12 = V_12 ;
return 0 ;
V_203:
F_62 ( V_12 ) ;
return V_35 ;
}
