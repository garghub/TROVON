static int F_1 ( void T_1 * V_1 )
{
F_2 ( 0 , V_1 + V_2 ) ;
F_2 ( 0 , V_1 + V_3 ) ;
F_2 ( 0 , V_1 + V_4 ) ;
F_2 ( 0 , V_1 + V_5 ) ;
F_2 ( 0 , V_1 + V_6 ) ;
F_2 ( 0 , V_1 + V_7 ) ;
F_2 ( 0x1FFFFFF , V_1 + V_8 ) ;
return 0 ;
}
static void F_3 ( void T_1 * V_1 ,
struct V_9 * V_10 ,
T_2 V_11 , T_2 V_12 , int V_13 )
{
F_2 ( V_12 , V_1 + V_5 ) ;
F_2 ( V_11 , V_1 + V_6 ) ;
F_2 ( V_14 | V_15 , V_1 + V_7 ) ;
F_2 ( 0x1FFFFFF , V_1 + V_8 ) ;
}
static void F_4 ( void T_1 * V_1 , T_2 * V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < 0xC8 ; V_17 += 4 ) {
if ( V_17 == 0x32 || V_17 == 0x3C )
continue;
V_16 [ V_17 / 4 ] = F_5 ( V_1 + V_17 ) ;
}
}
static void F_6 ( struct V_18 * V_19 ,
T_2 * V_16 )
{
int V_17 ;
void T_1 * V_1 = V_19 -> V_20 ;
for ( V_17 = 0 ; V_17 < 0xC8 ; V_17 += 4 ) {
if ( V_17 == 0x32 || V_17 == 0x3C )
continue;
V_16 [ V_17 / 4 ] = F_5 ( V_1 + V_17 ) ;
}
}
static void F_7 ( void T_1 * V_1 , T_2 V_21 )
{
F_2 ( V_14 | V_15 , V_1 + V_7 ) ;
}
static void F_8 ( void T_1 * V_1 , T_2 V_21 )
{
F_2 ( 0 , V_1 + V_7 ) ;
}
static void F_9 ( void T_1 * V_1 , T_2 V_21 )
{
T_2 V_22 ;
V_22 = F_5 ( V_1 + V_3 ) ;
V_22 |= V_23 ;
V_22 |= V_24 ;
F_2 ( V_22 , V_1 + V_3 ) ;
}
static void F_10 ( void T_1 * V_1 )
{
T_2 V_22 ;
V_22 = F_5 ( V_1 + V_3 ) ;
V_22 |= V_23 ;
V_22 |= V_24 ;
F_2 ( V_22 , V_1 + V_3 ) ;
}
static void F_11 ( void T_1 * V_1 , T_2 V_21 )
{
T_2 V_22 ;
V_22 = F_5 ( V_1 + V_3 ) ;
V_22 &= ~ V_24 ;
F_2 ( V_22 , V_1 + V_3 ) ;
}
static void F_12 ( void T_1 * V_1 , T_2 V_21 )
{
T_2 V_22 ;
V_22 = F_5 ( V_1 + V_2 ) ;
V_22 |= V_25 ;
V_22 |= V_26 ;
F_2 ( V_22 , V_1 + V_2 ) ;
}
static void F_13 ( void T_1 * V_1 , T_2 V_21 )
{
T_2 V_22 ;
V_22 = F_5 ( V_1 + V_2 ) ;
V_22 &= ~ V_26 ;
F_2 ( V_22 , V_1 + V_2 ) ;
}
static int F_14 ( void T_1 * V_1 ,
struct V_27 * V_28 , T_2 V_21 )
{
T_2 V_22 ;
int V_29 = 0 ;
V_22 = F_5 ( V_1 + V_8 ) ;
if ( V_22 & V_15 ) {
V_29 |= V_30 ;
V_28 -> V_31 ++ ;
}
if ( V_22 & V_32 )
V_28 -> V_33 ++ ;
if ( V_22 & V_34 )
V_28 -> V_33 ++ ;
if ( V_22 & V_35 )
V_29 |= V_36 ;
if ( V_22 & V_37 ) {
V_29 |= V_36 ;
V_28 -> V_38 ++ ;
}
if ( V_22 & V_39 )
V_28 -> V_40 ++ ;
if ( V_22 & V_14 ) {
V_29 |= V_41 ;
V_28 -> V_42 ++ ;
}
if ( V_22 & V_43 )
V_28 -> V_44 ++ ;
if ( V_22 & V_45 )
V_28 -> V_46 ++ ;
if ( V_22 & V_47 )
V_29 |= V_36 ;
if ( V_22 & V_48 ) {
V_29 |= V_36 ;
V_28 -> V_49 ++ ;
}
if ( V_22 & V_50 )
V_28 -> V_51 ++ ;
if ( V_22 & V_52 )
V_28 -> V_53 ++ ;
F_2 ( V_22 , V_1 + V_8 ) ;
return V_29 ;
}
static void F_15 ( void T_1 * V_1 , int V_54 ,
int V_55 , int V_56 )
{
T_2 V_22 ;
V_22 = F_5 ( V_1 + V_3 ) ;
if ( V_54 == V_57 ) {
V_22 |= V_58 ;
V_22 |= V_59 ;
} else {
V_22 &= ~ V_58 ;
V_22 &= ~ V_60 ;
if ( V_54 < 64 )
V_22 |= V_61 ;
else if ( V_54 < 128 )
V_22 |= V_62 ;
else if ( V_54 < 192 )
V_22 |= V_63 ;
else if ( V_54 < 256 )
V_22 |= V_64 ;
}
F_2 ( V_22 , V_1 + V_3 ) ;
V_22 = F_5 ( V_1 + V_2 ) ;
if ( V_55 == V_57 ) {
V_22 |= V_65 ;
} else {
V_22 &= ~ V_65 ;
V_22 &= ~ V_66 ;
if ( V_55 < 32 )
V_22 |= V_67 ;
else if ( V_55 < 64 )
V_22 |= V_68 ;
else if ( V_55 < 96 )
V_22 |= V_69 ;
else if ( V_55 < 128 )
V_22 |= V_70 ;
}
F_2 ( V_22 , V_1 + V_2 ) ;
}
static int F_16 ( struct V_71 * V_72 , void * V_73 )
{
struct V_74 * V_75 = V_73 ;
int V_29 ;
if ( V_75 -> V_76 ) {
V_29 = F_17 ( V_75 -> V_76 ) ;
if ( V_29 ) {
F_18 ( & V_72 -> V_77 , L_1 ) ;
return V_29 ;
}
}
V_29 = F_19 ( V_75 -> V_78 ) ;
if ( V_29 ) {
if ( V_75 -> V_76 )
F_20 ( V_75 -> V_76 ) ;
F_18 ( & V_72 -> V_77 , L_2 ) ;
return V_29 ;
}
return 0 ;
}
static void F_21 ( struct V_18 * V_19 , int V_79 )
{
void T_1 * V_1 = V_19 -> V_20 ;
T_2 V_22 ;
V_22 = ( 8 << V_80 ) ;
F_2 ( V_22 , V_1 + V_81 ) ;
}
static void F_22 ( void T_1 * V_1 , bool V_82 )
{
T_2 V_83 , V_84 ;
V_83 = F_5 ( V_1 + V_85 ) ;
V_84 = F_5 ( V_1 + V_86 ) ;
if ( V_82 ) {
V_83 |= V_87 ;
V_84 |= V_88 ;
} else {
V_83 &= ~ V_87 ;
V_84 &= ~ V_88 ;
}
F_2 ( V_83 , V_1 + V_85 ) ;
F_2 ( V_84 , V_1 + V_86 ) ;
}
static void F_23 ( struct V_18 * V_19 ,
unsigned char * V_89 ,
unsigned int V_90 )
{
void T_1 * V_1 = V_19 -> V_20 ;
T_2 V_22 ;
if ( ! V_89 ) {
F_2 ( 0 , V_1 + F_24 ( V_90 ) ) ;
return;
}
F_25 ( V_1 , V_89 , F_24 ( V_90 ) ,
F_26 ( V_90 ) ) ;
if ( V_90 > 0 ) {
V_22 = F_5 ( V_1 + F_24 ( V_90 ) ) ;
V_22 |= V_91 ;
F_2 ( V_22 , V_1 + F_24 ( V_90 ) ) ;
}
}
static void F_27 ( struct V_18 * V_19 ,
unsigned char * V_89 ,
unsigned int V_90 )
{
void T_1 * V_1 = V_19 -> V_20 ;
F_28 ( V_1 , V_89 , F_24 ( V_90 ) ,
F_26 ( V_90 ) ) ;
}
static int F_29 ( struct V_18 * V_19 )
{
void T_1 * V_1 = V_19 -> V_20 ;
T_2 V_22 ;
V_22 = F_5 ( V_1 + V_86 ) ;
V_22 |= V_92 ;
F_2 ( V_22 , V_1 + V_86 ) ;
return 1 ;
}
static void F_30 ( struct V_18 * V_19 ,
struct V_93 * V_77 )
{
void T_1 * V_1 = V_19 -> V_20 ;
T_2 V_22 ;
int V_17 = 1 ;
struct V_94 * V_95 ;
int V_96 = F_31 ( V_77 ) + F_32 ( V_77 ) + 1 ;
V_22 = V_97 ;
if ( V_77 -> V_98 & V_99 ) {
V_22 = V_100 ;
} else if ( V_77 -> V_98 & V_101 ) {
V_22 |= V_102 ;
} else if ( V_96 <= V_19 -> V_103 ) {
if ( ! F_33 ( V_77 ) ) {
F_34 (ha, dev) {
F_23 ( V_19 , V_95 -> V_89 , V_17 ) ;
V_17 ++ ;
}
}
if ( ! F_35 ( V_77 ) ) {
F_36 (ha, dev) {
F_23 ( V_19 , V_95 -> V_89 , V_17 ) ;
V_17 ++ ;
}
}
} else {
F_37 ( V_77 , L_3 ) ;
V_22 = V_100 ;
}
while ( V_17 < V_19 -> V_103 )
F_23 ( V_19 , NULL , V_17 ++ ) ;
F_2 ( V_22 , V_1 + V_4 ) ;
}
static void F_38 ( struct V_18 * V_19 ,
unsigned int V_104 , unsigned int V_105 ,
unsigned int V_106 , T_2 V_107 )
{
void T_1 * V_1 = V_19 -> V_20 ;
T_2 V_22 ;
V_22 = F_5 ( V_1 + V_86 ) ;
if ( V_105 == V_108 )
V_22 |= V_109 ;
else
V_22 &= ~ V_109 ;
F_2 ( V_22 , V_1 + V_86 ) ;
V_22 = F_5 ( V_1 + V_110 ) ;
if ( V_105 == V_108 )
V_22 |= V_111 ;
else
V_22 &= ~ V_111 ;
F_2 ( V_22 , V_1 + V_110 ) ;
}
static int F_39 ( struct V_112 * V_73 )
{
T_2 V_22 ;
int V_113 ;
V_22 = F_5 ( V_73 -> V_1 + V_81 ) ;
F_2 ( V_22 | 0x01 , V_73 -> V_1 + V_81 ) ;
V_113 = F_40 ( V_73 -> V_1 + V_81 , V_22 ,
! ( V_22 & 0x01 ) , 100 , 100000 ) ;
if ( V_113 ) {
F_18 ( V_73 -> V_114 , L_4 ) ;
return - V_115 ;
}
return 0 ;
}
static int F_41 ( struct V_112 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_116 -> V_117 ;
struct V_118 * V_119 = V_73 -> V_114 -> V_120 ;
int V_29 ;
T_2 V_121 , V_122 ;
F_42 ( V_75 -> V_123 , V_124 , & V_122 ) ;
V_121 = V_75 -> V_125 -> V_126 ;
if ( V_121 != V_122 )
F_43 ( V_73 -> V_114 ,
L_5 ,
V_122 , V_121 ) ;
if ( V_75 -> V_125 -> V_127 ) {
if ( ! V_75 -> V_128 ) {
V_121 &= ~ V_129 ;
} else {
V_121 |= V_129 ;
V_121 &= ~ V_130 ;
F_44 ( V_73 -> V_114 , L_6 , V_121 ) ;
if ( F_45 ( V_73 -> V_116 -> V_131 ,
L_7 ) )
V_121 |= V_132 ;
else
V_121 &= ~ V_132 ;
V_121 |= V_133 ;
V_29 = F_46 ( V_73 -> V_114 ,
V_73 -> V_116 -> V_131 ) ;
if ( V_29 < 0 ) {
F_18 ( V_73 -> V_114 , L_8 ) ;
return V_29 ;
}
V_121 |= V_29 << V_134 ;
}
}
if ( ! F_47 ( V_119 , L_9 , & V_122 ) ) {
if ( V_122 % 100 ) {
F_18 ( V_73 -> V_114 , L_10 ) ;
return - V_135 ;
}
V_122 /= 100 ;
F_44 ( V_73 -> V_114 , L_11 , V_122 ) ;
if ( V_122 <= V_136 ) {
V_121 &= ~ ( V_136 << V_137 ) ;
V_121 |= ( V_122 << V_137 ) ;
} else {
F_18 ( V_73 -> V_114 , L_12 ,
V_122 ) ;
return - V_135 ;
}
}
if ( ! F_47 ( V_119 , L_13 , & V_122 ) ) {
if ( V_122 % 100 ) {
F_18 ( V_73 -> V_114 , L_14 ) ;
return - V_135 ;
}
V_122 /= 100 ;
F_44 ( V_73 -> V_114 , L_15 , V_122 ) ;
if ( V_122 <= V_138 ) {
V_121 &= ~ ( V_138 << V_139 ) ;
V_121 |= ( V_122 << V_139 ) ;
} else {
F_18 ( V_73 -> V_114 , L_16 ,
V_122 ) ;
return - V_135 ;
}
}
V_121 &= ~ ( V_140 | V_141 ) ;
if ( V_75 -> V_125 -> V_142 )
V_121 &= ~ V_143 ;
switch ( V_73 -> V_116 -> V_144 ) {
case V_145 :
break;
case V_146 :
V_121 |= V_141 | V_147 ;
break;
case V_148 :
V_121 |= V_143 | V_149 ;
break;
default:
F_18 ( V_73 -> V_114 , L_17 ,
F_48 ( V_73 -> V_116 -> V_144 ) ) ;
return - V_135 ;
}
F_49 ( V_75 -> V_123 , V_124 , V_121 ) ;
return 0 ;
}
static void F_50 ( struct V_74 * V_75 )
{
T_2 V_121 = V_75 -> V_125 -> V_126 ;
F_49 ( V_75 -> V_123 , V_124 , V_121 ) ;
}
static int F_51 ( struct V_112 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_116 -> V_117 ;
int V_29 ;
if ( ! V_75 -> V_128 )
return 0 ;
V_29 = F_19 ( V_75 -> V_150 ) ;
if ( V_29 ) {
F_18 ( V_73 -> V_114 , L_18 ) ;
return V_29 ;
}
F_52 ( V_75 -> V_151 ) ;
V_29 = F_53 ( V_75 -> V_151 ) ;
if ( V_29 ) {
F_18 ( V_73 -> V_114 , L_19 ) ;
F_54 ( V_75 -> V_150 ) ;
return V_29 ;
}
return 0 ;
}
static int F_55 ( struct V_74 * V_75 )
{
if ( ! V_75 -> V_128 )
return 0 ;
F_54 ( V_75 -> V_150 ) ;
F_52 ( V_75 -> V_151 ) ;
return 0 ;
}
static int F_56 ( struct V_112 * V_73 )
{
int V_29 ;
V_29 = F_51 ( V_73 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_41 ( V_73 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_39 ( V_73 ) ;
if ( V_29 )
return V_29 ;
return 0 ;
}
static void F_57 ( struct V_74 * V_75 )
{
F_50 ( V_75 ) ;
F_55 ( V_75 ) ;
}
static void F_58 ( struct V_71 * V_72 , void * V_73 )
{
struct V_74 * V_75 = V_73 ;
F_57 ( V_75 ) ;
F_54 ( V_75 -> V_78 ) ;
if ( V_75 -> V_76 )
F_20 ( V_75 -> V_76 ) ;
}
static struct V_18 * F_59 ( void * V_152 )
{
struct V_18 * V_153 ;
struct V_112 * V_73 = V_152 ;
int V_29 ;
V_153 = F_60 ( V_73 -> V_114 , sizeof( * V_153 ) , V_154 ) ;
if ( ! V_153 )
return NULL ;
V_29 = F_56 ( V_73 ) ;
if ( V_29 )
return NULL ;
V_153 -> V_20 = V_73 -> V_1 ;
V_153 -> V_153 = & V_155 ;
V_153 -> V_156 = & V_157 ;
V_153 -> V_158 . V_159 = F_61 ( 3 , 2 ) | V_160 ;
V_153 -> V_158 . V_161 = V_162 ;
V_153 -> V_158 . V_163 = V_164 ;
V_153 -> V_158 . V_165 = V_166 ;
V_153 -> V_158 . V_104 = V_167 ;
V_153 -> V_168 . V_89 = V_169 ;
V_153 -> V_168 . V_170 = V_171 ;
V_153 -> V_168 . V_172 = 4 ;
V_153 -> V_168 . V_173 = F_61 ( 8 , 4 ) ;
V_153 -> V_168 . V_174 = 12 ;
V_153 -> V_168 . V_175 = F_61 ( 16 , 12 ) ;
V_153 -> V_168 . V_176 = 20 ;
V_153 -> V_168 . V_177 = F_61 ( 22 , 20 ) ;
V_153 -> V_103 = 8 ;
V_73 -> V_178 = 0 ;
return V_153 ;
}
static int F_62 ( struct V_71 * V_72 )
{
struct V_179 * V_180 ;
struct V_181 V_182 ;
struct V_74 * V_75 ;
struct V_114 * V_77 = & V_72 -> V_77 ;
int V_29 ;
V_29 = F_63 ( V_72 , & V_182 ) ;
if ( V_29 )
return V_29 ;
V_180 = F_64 ( V_72 , & V_182 . V_153 ) ;
if ( F_65 ( V_180 ) )
return F_66 ( V_180 ) ;
V_75 = F_60 ( V_77 , sizeof( * V_75 ) , V_154 ) ;
if ( ! V_75 )
return - V_183 ;
V_75 -> V_125 = F_67 ( & V_72 -> V_77 ) ;
if ( ! V_75 -> V_125 ) {
F_18 ( & V_72 -> V_77 , L_20 ) ;
return - V_135 ;
}
V_75 -> V_78 = F_68 ( V_77 , L_21 ) ;
if ( F_65 ( V_75 -> V_78 ) ) {
F_18 ( V_77 , L_22 ) ;
return F_66 ( V_75 -> V_78 ) ;
}
V_75 -> V_76 = F_69 ( V_77 , L_23 ) ;
if ( F_65 ( V_75 -> V_76 ) ) {
if ( F_66 ( V_75 -> V_76 ) == - V_184 )
return - V_184 ;
F_70 ( V_77 , L_24 ) ;
V_75 -> V_76 = NULL ;
}
V_75 -> V_123 = F_71 ( V_72 -> V_77 . V_120 ,
L_25 ) ;
if ( F_65 ( V_75 -> V_123 ) ) {
V_29 = F_66 ( V_75 -> V_123 ) ;
F_18 ( & V_72 -> V_77 , L_26 , V_29 ) ;
return V_29 ;
}
V_180 -> V_144 = F_72 ( V_77 -> V_120 ) ;
if ( V_180 -> V_144 == V_75 -> V_125 -> V_127 ) {
F_70 ( & V_72 -> V_77 , L_27 ) ;
V_75 -> V_128 = true ;
V_75 -> V_150 = F_73 ( V_180 -> V_131 , 0 ) ;
if ( F_65 ( V_75 -> V_150 ) ) {
V_29 = F_66 ( V_75 -> V_150 ) ;
F_18 ( & V_72 -> V_77 , L_28 , V_29 ) ;
return - V_135 ;
}
V_75 -> V_151 = F_74 ( V_180 -> V_131 , NULL ) ;
if ( F_65 ( V_75 -> V_151 ) ) {
V_29 = F_66 ( V_75 -> V_151 ) ;
if ( V_29 == - V_184 )
return V_29 ;
F_18 ( & V_72 -> V_77 , L_29 ,
V_29 ) ;
return - V_135 ;
}
} else {
F_70 ( & V_72 -> V_77 , L_30 ) ;
V_75 -> V_128 = false ;
}
V_180 -> V_185 = V_186 ;
V_180 -> V_187 = 1 ;
V_180 -> V_188 = true ;
V_180 -> V_117 = V_75 ;
V_180 -> V_189 = F_16 ;
V_180 -> exit = F_58 ;
V_180 -> V_190 = F_59 ;
V_29 = F_16 ( V_72 , V_180 -> V_117 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_75 ( & V_72 -> V_77 , V_180 , & V_182 ) ;
if ( V_29 )
F_58 ( V_72 , V_180 -> V_117 ) ;
return V_29 ;
}
