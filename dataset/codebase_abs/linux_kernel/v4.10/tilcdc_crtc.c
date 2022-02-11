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
V_12 -> V_27 * F_9 ( V_14 -> V_28 , 0 ) ;
V_21 = V_20 + ( V_12 -> V_29 . V_30 * V_14 -> V_26 [ 0 ] ) ;
if ( V_16 -> V_31 == 1 )
V_21 -= 1 ;
V_22 = ( T_2 ) V_21 << 32 | V_20 ;
F_10 ( V_7 , V_32 , V_22 ) ;
if ( V_4 -> V_33 )
F_11 ( & V_4 -> V_5 ,
V_4 -> V_33 ) ;
V_4 -> V_33 = V_14 ;
}
static void F_12 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
int V_34 ;
F_13 ( & V_4 -> V_35 ) ;
F_14 ( V_7 , V_32 ,
V_4 -> V_36 ) ;
F_14 ( V_7 , V_37 ,
( V_38 ) V_4 -> V_36 +
V_39 - 1 ) ;
F_15 ( V_7 , V_40 ,
F_16 ( V_41 ) ,
V_42 ) ;
if ( V_16 -> V_31 == 1 )
F_17 ( V_7 , V_40 , V_43 ) ;
else
F_14 ( V_7 , V_44 , V_45 ) ;
F_18 ( V_7 , 0xffffffff ) ;
F_17 ( V_7 , V_40 , V_46 ) ;
V_34 = F_19 ( & V_4 -> V_35 ,
F_20 ( 50 ) ) ;
if ( V_34 == 0 )
F_21 ( V_7 -> V_7 , L_1 , V_47 ) ;
F_22 ( V_7 , V_40 , V_46 ) ;
if ( V_16 -> V_31 == 1 )
F_22 ( V_7 , V_40 , V_43 ) ;
else
F_14 ( V_7 , V_48 , V_45 ) ;
}
static void F_23 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 ;
F_18 ( V_7 , 0xffffffff ) ;
if ( V_16 -> V_31 == 1 ) {
F_17 ( V_7 , V_40 ,
V_49 | V_50 |
V_51 ) ;
F_17 ( V_7 , V_52 ,
V_53 ) ;
} else {
F_14 ( V_7 , V_44 ,
V_54 |
V_55 |
V_56 | V_57 ) ;
}
}
static void F_24 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 ;
if ( V_16 -> V_31 == 1 ) {
F_22 ( V_7 , V_40 ,
V_49 | V_50 |
V_51 | V_43 ) ;
F_22 ( V_7 , V_52 ,
V_53 ) ;
} else {
F_14 ( V_7 , V_48 ,
V_54 | V_45 |
V_55 |
V_56 | V_57 ) ;
}
}
static void F_25 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
if ( V_16 -> V_31 != 2 )
return;
F_17 ( V_7 , V_58 , V_59 ) ;
F_26 ( 250 , 1000 ) ;
F_22 ( V_7 , V_58 , V_59 ) ;
}
static unsigned int F_27 ( unsigned long V_60 ,
unsigned long V_61 )
{
int V_62 = V_60 / 100 , V_63 = V_61 / 100 ;
return ( unsigned int ) ( abs ( ( ( V_63 - V_62 ) * 100 ) / V_62 ) ) ;
}
static void F_28 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
struct V_4 * V_4 = F_7 ( V_12 ) ;
unsigned long V_64 , V_61 , V_65 ;
unsigned int V_66 ;
int V_34 ;
V_66 = 2 ;
V_65 = V_12 -> V_29 . clock * 1000 ;
V_34 = F_29 ( V_16 -> V_67 , V_65 * V_66 ) ;
V_64 = F_30 ( V_16 -> V_67 ) ;
if ( V_34 < 0 ) {
if ( ! V_64 ) {
F_21 ( V_7 -> V_7 ,
L_2 ) ;
return;
}
V_66 = F_31 ( V_64 , V_65 ) ;
V_61 = V_66 * V_65 ;
if ( F_27 ( V_64 , V_61 ) > 5 ) {
F_32 ( V_7 -> V_7 ,
L_3 ,
V_64 , V_61 ) ;
}
}
V_4 -> V_68 = V_64 ;
F_33 ( L_4 ,
V_4 -> V_68 , V_12 -> V_29 . clock , V_66 ) ;
F_14 ( V_7 , V_69 , F_34 ( V_66 ) |
V_70 ) ;
if ( V_16 -> V_31 == 2 )
F_17 ( V_7 , V_71 ,
V_72 | V_73 |
V_74 ) ;
}
static void F_35 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
const struct V_75 * V_76 = V_4 -> V_76 ;
T_3 V_77 , V_78 , V_79 , V_80 , V_81 , V_82 , V_83 ;
struct V_84 * V_29 = & V_12 -> V_85 -> V_86 ;
struct V_13 * V_14 = V_12 -> V_87 -> V_85 -> V_14 ;
if ( F_36 ( ! V_76 ) )
return;
if ( F_36 ( ! V_14 ) )
return;
V_77 = F_37 ( V_7 , V_52 ) & ~ 0x00000770 ;
switch ( V_76 -> V_88 ) {
case 1 :
V_77 |= F_38 ( V_89 ) ;
break;
case 2 :
V_77 |= F_38 ( V_90 ) ;
break;
case 4 :
V_77 |= F_38 ( V_91 ) ;
break;
case 8 :
V_77 |= F_38 ( V_92 ) ;
break;
case 16 :
V_77 |= F_38 ( V_93 ) ;
break;
default:
F_21 ( V_7 -> V_7 , L_5 ) ;
return;
}
V_77 |= ( V_76 -> V_94 << 8 ) ;
F_14 ( V_7 , V_52 , V_77 ) ;
V_78 = V_29 -> V_95 - V_29 -> V_96 ;
V_79 = V_29 -> V_97 - V_29 -> V_98 ;
V_80 = V_29 -> V_96 - V_29 -> V_97 ;
V_81 = V_29 -> V_99 - V_29 -> V_100 ;
V_82 = V_29 -> V_101 - V_29 -> V_30 ;
V_83 = V_29 -> V_100 - V_29 -> V_101 ;
F_33 ( L_6 ,
V_29 -> V_98 , V_29 -> V_30 , V_78 , V_79 , V_80 , V_81 , V_82 , V_83 ) ;
V_77 = F_37 ( V_7 , V_102 ) & ~ 0x000fff00 ;
V_77 |= F_39 ( V_76 -> V_103 ) |
F_40 ( V_76 -> V_104 ) ;
if ( V_16 -> V_31 == 2 ) {
V_77 &= ~ 0x78000033 ;
V_77 |= ( ( V_79 - 1 ) & 0x300 ) >> 8 ;
V_77 |= ( ( V_78 - 1 ) & 0x300 ) >> 4 ;
V_77 |= ( ( V_80 - 1 ) & 0x3c0 ) << 21 ;
}
F_14 ( V_7 , V_102 , V_77 ) ;
V_77 = ( ( ( V_29 -> V_98 >> 4 ) - 1 ) << 4 ) |
( ( ( V_78 - 1 ) & 0xff ) << 24 ) |
( ( ( V_79 - 1 ) & 0xff ) << 16 ) |
( ( ( V_80 - 1 ) & 0x3f ) << 10 ) ;
if ( V_16 -> V_31 == 2 )
V_77 |= ( ( ( V_29 -> V_98 >> 4 ) - 1 ) & 0x40 ) >> 3 ;
F_14 ( V_7 , V_105 , V_77 ) ;
V_77 = ( ( V_29 -> V_30 - 1 ) & 0x3ff ) |
( ( V_81 & 0xff ) << 24 ) |
( ( V_82 & 0xff ) << 16 ) |
( ( ( V_83 - 1 ) & 0x3f ) << 10 ) ;
F_14 ( V_7 , V_106 , V_77 ) ;
if ( V_16 -> V_31 == 2 ) {
if ( ( V_29 -> V_30 - 1 ) & 0x400 ) {
F_17 ( V_7 , V_102 ,
V_107 ) ;
} else {
F_22 ( V_7 , V_102 ,
V_107 ) ;
}
}
V_77 = F_37 ( V_7 , V_40 ) &
~ ( V_108 | V_109 | V_110 |
V_111 | V_112 |
0x000ff000 ) ;
V_77 |= V_108 ;
if ( V_76 -> V_113 )
V_77 |= V_114 ;
if ( V_16 -> V_31 == 2 ) {
switch ( V_14 -> V_28 ) {
case V_115 :
case V_116 :
break;
case V_117 :
case V_118 :
V_77 |= V_112 ;
case V_119 :
case V_120 :
V_77 |= V_111 ;
break;
default:
F_21 ( V_7 -> V_7 , L_7 ) ;
return;
}
}
V_77 |= V_76 -> V_121 < 12 ;
F_14 ( V_7 , V_40 , V_77 ) ;
if ( V_76 -> V_122 )
F_17 ( V_7 , V_102 , V_123 ) ;
else
F_22 ( V_7 , V_102 , V_123 ) ;
if ( V_76 -> V_124 )
F_17 ( V_7 , V_102 , V_125 ) ;
else
F_22 ( V_7 , V_102 , V_125 ) ;
if ( V_76 -> V_126 )
F_17 ( V_7 , V_102 , V_127 ) ;
else
F_22 ( V_7 , V_102 , V_127 ) ;
if ( V_29 -> V_128 & V_129 )
F_17 ( V_7 , V_102 , V_130 ) ;
else
F_22 ( V_7 , V_102 , V_130 ) ;
if ( V_29 -> V_128 & V_131 )
F_17 ( V_7 , V_102 , V_132 ) ;
else
F_22 ( V_7 , V_102 , V_132 ) ;
if ( V_76 -> V_133 )
F_17 ( V_7 , V_40 , V_134 ) ;
else
F_22 ( V_7 , V_40 , V_134 ) ;
F_28 ( V_12 ) ;
F_12 ( V_12 ) ;
F_6 ( V_12 , V_14 ) ;
F_41 ( V_14 ) ;
V_12 -> V_135 = V_12 -> V_85 -> V_86 ;
}
static void F_42 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_4 * V_4 = F_7 ( V_12 ) ;
F_36 ( ! F_43 ( & V_12 -> V_10 ) ) ;
F_3 ( & V_4 -> V_136 ) ;
if ( V_4 -> V_137 || V_4 -> V_138 ) {
F_5 ( & V_4 -> V_136 ) ;
return;
}
F_44 ( V_7 -> V_7 ) ;
F_25 ( V_12 ) ;
F_35 ( V_12 ) ;
F_23 ( V_7 ) ;
F_22 ( V_7 , V_52 , V_139 ) ;
F_15 ( V_7 , V_40 ,
F_16 ( V_140 ) ,
V_42 ) ;
F_17 ( V_7 , V_40 , V_46 ) ;
F_45 ( V_12 ) ;
V_4 -> V_137 = true ;
F_5 ( & V_4 -> V_136 ) ;
}
static void F_46 ( struct V_11 * V_12 , bool V_138 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
int V_34 ;
F_3 ( & V_4 -> V_136 ) ;
if ( V_138 )
V_4 -> V_138 = true ;
if ( ! V_4 -> V_137 ) {
F_5 ( & V_4 -> V_136 ) ;
return;
}
V_4 -> V_141 = false ;
F_22 ( V_7 , V_40 , V_46 ) ;
V_34 = F_47 ( V_4 -> V_142 ,
V_4 -> V_141 ,
F_20 ( 500 ) ) ;
if ( V_34 == 0 )
F_21 ( V_7 -> V_7 , L_8 ,
V_47 ) ;
F_48 ( V_12 ) ;
F_24 ( V_7 ) ;
F_49 ( V_7 -> V_7 ) ;
if ( V_4 -> V_143 ) {
F_11 ( & V_4 -> V_5 ,
V_4 -> V_143 ) ;
V_4 -> V_143 = NULL ;
}
if ( V_4 -> V_33 ) {
F_11 ( & V_4 -> V_5 ,
V_4 -> V_33 ) ;
V_4 -> V_33 = NULL ;
}
F_50 ( & V_4 -> V_5 , V_16 -> V_144 ) ;
V_4 -> V_145 = 0 ;
V_4 -> V_137 = false ;
F_5 ( & V_4 -> V_136 ) ;
}
static void F_51 ( struct V_11 * V_12 )
{
F_36 ( ! F_43 ( & V_12 -> V_10 ) ) ;
F_46 ( V_12 , false ) ;
}
void F_52 ( struct V_11 * V_12 )
{
F_46 ( V_12 , true ) ;
}
static bool F_53 ( struct V_11 * V_12 )
{
return V_12 -> V_85 && V_12 -> V_85 -> V_146 && V_12 -> V_85 -> V_147 ;
}
static void F_54 ( struct V_148 * V_2 )
{
struct V_4 * V_4 =
F_2 ( V_2 , struct V_4 , V_149 ) ;
struct V_11 * V_12 = & V_4 -> V_8 ;
F_55 ( V_12 -> V_7 -> V_7 , L_9 , V_47 ) ;
F_56 ( V_12 , NULL ) ;
if ( ! F_53 ( V_12 ) )
goto V_150;
F_51 ( V_12 ) ;
F_42 ( V_12 ) ;
V_150:
F_57 ( V_12 ) ;
}
static void F_58 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_15 * V_16 = V_12 -> V_7 -> V_17 ;
F_56 ( V_12 , NULL ) ;
F_51 ( V_12 ) ;
F_57 ( V_12 ) ;
F_59 ( V_16 -> V_144 ) ;
F_60 ( V_12 -> V_151 ) ;
F_61 ( V_12 ) ;
F_62 ( & V_4 -> V_5 ) ;
}
int F_63 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_152 * V_153 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned long V_128 ;
F_36 ( ! F_43 ( & V_12 -> V_10 ) ) ;
if ( V_4 -> V_153 ) {
F_21 ( V_7 -> V_7 , L_10 ) ;
return - V_154 ;
}
F_41 ( V_14 ) ;
V_12 -> V_87 -> V_14 = V_14 ;
F_64 ( & V_4 -> V_155 , V_128 ) ;
if ( V_12 -> V_135 . V_156 && F_65 ( V_4 -> V_145 ) ) {
T_4 V_157 ;
T_5 V_158 ;
V_157 = F_66 ( V_4 -> V_145 ,
1000000 / V_12 -> V_135 . V_156 ) ;
V_158 = F_67 ( F_68 ( V_157 , F_69 () ) ) ;
if ( V_158 < V_159 )
V_4 -> V_143 = V_14 ;
}
if ( V_4 -> V_143 != V_14 )
F_6 ( V_12 , V_14 ) ;
V_4 -> V_153 = V_153 ;
F_70 ( & V_4 -> V_155 , V_128 ) ;
return 0 ;
}
static bool F_71 ( struct V_11 * V_12 ,
const struct V_84 * V_29 ,
struct V_84 * V_86 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
if ( ! V_4 -> V_160 )
return true ;
V_86 -> V_161 = V_29 -> V_96 - V_29 -> V_97 ;
V_86 -> V_128 |= V_162 ;
if ( V_29 -> V_128 & V_129 ) {
V_86 -> V_128 |= V_163 ;
V_86 -> V_128 &= ~ V_129 ;
} else {
V_86 -> V_128 |= V_129 ;
V_86 -> V_128 &= ~ V_163 ;
}
return true ;
}
static int F_72 ( struct V_11 * V_12 ,
struct V_164 * V_85 )
{
struct V_84 * V_29 = & V_85 -> V_29 ;
int V_34 ;
if ( ! V_85 -> V_147 )
return 0 ;
if ( V_85 -> V_85 -> V_165 [ 0 ] . V_166 != V_12 -> V_87 ||
V_85 -> V_85 -> V_165 [ 0 ] . V_85 == NULL ||
V_85 -> V_85 -> V_165 [ 0 ] . V_85 -> V_12 != V_12 ) {
F_73 ( V_12 -> V_7 -> V_7 , L_11 ) ;
return - V_167 ;
}
V_34 = F_74 ( V_12 , V_29 ) ;
if ( V_34 ) {
F_73 ( V_12 -> V_7 -> V_7 , L_12 , V_29 -> V_168 ) ;
return - V_167 ;
}
return 0 ;
}
int F_75 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
int V_169 = 0 ;
if ( V_16 -> V_31 == 1 )
V_169 = 1024 ;
else if ( V_16 -> V_31 == 2 )
V_169 = 2048 ;
return V_169 ;
}
int F_74 ( struct V_11 * V_12 , struct V_84 * V_29 )
{
struct V_15 * V_16 = V_12 -> V_7 -> V_17 ;
unsigned int V_170 ;
T_3 V_78 , V_79 , V_80 , V_81 , V_82 , V_83 ;
if ( V_29 -> V_98 > F_75 ( V_12 ) )
return V_171 ;
if ( V_29 -> V_98 & 0xf )
return V_171 ;
if ( V_29 -> V_30 > 2048 )
return V_172 ;
F_33 ( L_13 ,
V_29 -> V_98 , V_29 -> V_30 ,
F_76 ( V_29 ) , V_29 -> clock ) ;
V_78 = V_29 -> V_95 - V_29 -> V_96 ;
V_79 = V_29 -> V_97 - V_29 -> V_98 ;
V_80 = V_29 -> V_96 - V_29 -> V_97 ;
V_81 = V_29 -> V_99 - V_29 -> V_100 ;
V_82 = V_29 -> V_101 - V_29 -> V_30 ;
V_83 = V_29 -> V_100 - V_29 -> V_101 ;
if ( ( V_78 - 1 ) & ~ 0x3ff ) {
F_33 ( L_14 ) ;
return V_173 ;
}
if ( ( V_79 - 1 ) & ~ 0x3ff ) {
F_33 ( L_15 ) ;
return V_173 ;
}
if ( ( V_80 - 1 ) & ~ 0x3ff ) {
F_33 ( L_16 ) ;
return V_174 ;
}
if ( V_81 & ~ 0xff ) {
F_33 ( L_17 ) ;
return V_175 ;
}
if ( V_82 & ~ 0xff ) {
F_33 ( L_18 ) ;
return V_175 ;
}
if ( ( V_83 - 1 ) & ~ 0x3f ) {
F_33 ( L_19 ) ;
return V_176 ;
}
if ( V_29 -> clock > V_16 -> V_177 ) {
F_33 ( L_20 ) ;
return V_178 ;
}
if ( V_29 -> V_98 > V_16 -> V_169 )
return V_179 ;
V_170 = V_29 -> V_98 * V_29 -> V_30 *
F_76 ( V_29 ) ;
if ( V_170 > V_16 -> V_180 ) {
F_33 ( L_21 ) ;
return V_181 ;
}
return V_182 ;
}
void F_77 ( struct V_11 * V_12 ,
const struct V_75 * V_76 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_76 = V_76 ;
}
void F_78 ( struct V_11 * V_12 ,
bool V_160 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_160 = V_160 ;
}
void F_79 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
struct V_4 * V_4 = F_7 ( V_12 ) ;
F_56 ( V_12 , NULL ) ;
if ( V_4 -> V_68 != F_30 ( V_16 -> V_67 ) ) {
if ( F_53 ( V_12 ) ) {
F_44 ( V_7 -> V_7 ) ;
F_51 ( V_12 ) ;
F_28 ( V_12 ) ;
F_42 ( V_12 ) ;
F_49 ( V_7 -> V_7 ) ;
}
}
F_57 ( V_12 ) ;
}
T_6 F_80 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 ;
T_3 V_183 , V_77 ;
V_183 = F_81 ( V_7 ) ;
F_18 ( V_7 , V_183 ) ;
if ( V_183 & V_184 ) {
unsigned long V_128 ;
bool V_185 = false ;
T_4 V_186 ;
V_186 = F_69 () ;
F_50 ( & V_4 -> V_5 , V_16 -> V_144 ) ;
F_64 ( & V_4 -> V_155 , V_128 ) ;
V_4 -> V_145 = V_186 ;
if ( V_4 -> V_143 ) {
F_6 ( V_12 , V_4 -> V_143 ) ;
V_4 -> V_143 = NULL ;
V_185 = true ;
}
F_70 ( & V_4 -> V_155 , V_128 ) ;
F_82 ( V_12 ) ;
if ( ! V_185 ) {
struct V_152 * V_153 ;
F_64 ( & V_7 -> V_187 , V_128 ) ;
V_153 = V_4 -> V_153 ;
V_4 -> V_153 = NULL ;
if ( V_153 )
F_83 ( V_12 , V_153 ) ;
F_70 ( & V_7 -> V_187 , V_128 ) ;
}
if ( V_4 -> V_188 )
V_4 -> V_189 = 0 ;
else
V_4 -> V_188 = true ;
}
if ( V_183 & V_190 )
F_84 ( V_7 -> V_7 , L_22 ,
V_47 , V_183 ) ;
if ( V_183 & V_191 ) {
F_85 ( & V_4 -> V_35 ) ;
if ( V_16 -> V_31 == 1 )
F_22 ( V_7 , V_40 ,
V_43 ) ;
else
F_14 ( V_7 , V_48 ,
V_45 ) ;
}
if ( V_183 & V_57 ) {
F_84 ( V_7 -> V_7 , L_23 ,
V_47 , V_183 ) ;
V_4 -> V_188 = false ;
if ( V_16 -> V_31 == 1 ) {
V_77 = F_37 ( V_7 , V_40 ) ;
if ( V_77 & V_46 ) {
F_22 ( V_7 , V_40 ,
V_46 ) ;
F_17 ( V_7 , V_40 ,
V_46 ) ;
}
} else {
if ( V_4 -> V_189 ++ >
V_192 ) {
F_21 ( V_7 -> V_7 ,
L_24 ,
V_47 , V_183 ) ;
F_86 ( V_193 ,
& V_4 -> V_149 ) ;
F_14 ( V_7 , V_48 ,
V_57 ) ;
V_4 -> V_189 = 0 ;
}
}
}
if ( V_183 & V_56 ) {
V_4 -> V_141 = true ;
F_87 ( & V_4 -> V_142 ) ;
if ( V_16 -> V_31 == 1 )
F_22 ( V_7 , V_40 ,
V_50 ) ;
}
if ( V_16 -> V_31 == 2 ) {
F_14 ( V_7 , V_194 , 0 ) ;
}
return V_195 ;
}
int F_88 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 ;
struct V_4 * V_4 ;
struct V_11 * V_12 ;
int V_34 ;
V_4 = F_89 ( V_7 -> V_7 , sizeof( * V_4 ) , V_196 ) ;
if ( ! V_4 ) {
F_21 ( V_7 -> V_7 , L_25 ) ;
return - V_197 ;
}
F_90 ( & V_4 -> V_35 ) ;
V_4 -> V_198 = F_91 ( V_7 -> V_7 ,
V_39 ,
& V_4 -> V_36 ,
V_196 | V_199 ) ;
if ( ! V_4 -> V_198 )
return - V_197 ;
* V_4 -> V_198 = V_200 ;
V_12 = & V_4 -> V_8 ;
V_34 = F_92 ( V_7 , & V_4 -> V_87 ) ;
if ( V_34 < 0 )
goto V_201;
F_93 ( & V_4 -> V_136 ) ;
F_94 ( & V_4 -> V_142 ) ;
F_95 ( & V_4 -> V_5 ,
L_26 , F_1 ) ;
F_96 ( & V_4 -> V_155 ) ;
F_97 ( & V_4 -> V_149 , F_54 ) ;
V_34 = F_98 ( V_7 , V_12 ,
& V_4 -> V_87 ,
NULL ,
& V_202 ,
L_27 ) ;
if ( V_34 < 0 )
goto V_201;
F_99 ( V_12 , & V_203 ) ;
if ( V_16 -> V_204 ) {
struct V_205 * V_206 =
F_100 ( V_7 -> V_7 -> V_207 , L_28 ) ;
if ( V_206 ) {
V_12 -> V_151 = F_100 ( V_206 , L_29 ) ;
F_60 ( V_206 ) ;
} else {
V_12 -> V_151 =
F_100 ( V_7 -> V_7 -> V_207 , L_29 ) ;
}
if ( ! V_12 -> V_151 ) {
F_21 ( V_7 -> V_7 , L_30 ,
V_7 -> V_7 -> V_207 -> V_208 ) ;
V_34 = - V_167 ;
goto V_201;
}
}
V_16 -> V_12 = V_12 ;
return 0 ;
V_201:
F_58 ( V_12 ) ;
return - V_197 ;
}
