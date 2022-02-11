static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_6 ) ;
}
static int F_4 ( struct V_7 * V_8 , T_1 V_9 , T_1 V_10 )
{
return F_5 ( V_8 , V_9 , V_10 , V_10 ) ;
}
static int F_6 ( struct V_7 * V_8 , T_1 V_9 , T_1 V_10 )
{
return F_5 ( V_8 , V_9 , V_10 , 0 ) ;
}
static bool F_7 ( struct V_1 * V_1 )
{
unsigned int V_11 ;
int V_12 ;
V_12 = F_8 ( V_1 -> V_8 [ V_13 ] , V_14 ,
& V_11 ) ;
if ( V_12 < 0 )
return false ;
return ( V_11 & V_15 ) == 0 ;
}
static int F_9 ( struct V_1 * V_1 )
{
unsigned long V_16 ;
unsigned int V_17 ;
int V_12 ;
V_16 = V_18 + F_10 ( V_19 ) + 1 ;
while ( ! F_7 ( V_1 ) ) {
if ( F_11 ( V_18 , V_16 ) ) {
if ( ! F_7 ( V_1 ) ) {
F_12 ( L_1 ) ;
return - V_20 ;
}
break;
}
F_13 ( 1000 , 2000 ) ;
}
V_12 = F_8 ( V_1 -> V_8 [ V_13 ] , V_21 ,
& V_17 ) ;
if ( V_12 < 0 ) {
F_12 ( L_2 , V_12 ) ;
return V_12 ;
}
if ( V_17 & V_22 ) {
F_12 ( L_3 ,
V_17 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , unsigned int V_23 )
{
int V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] , V_24 ,
V_23 & 0xff ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] , V_25 ,
( V_23 & 0xff00 ) >> 8 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_5 ( V_1 -> V_8 [ V_13 ] ,
V_26 ,
V_27 ,
( V_23 & 0xf0000 ) >> 16 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static T_2 F_16 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_1 = F_2 ( V_29 , struct V_1 , V_29 ) ;
T_1 V_32 = V_31 -> V_33 ;
T_1 V_34 = V_15 ;
T_1 * V_35 = V_31 -> V_35 ;
int V_12 ;
if ( F_17 ( V_31 -> V_36 > V_37 ) )
return - V_38 ;
if ( V_31 -> V_36 < 1 )
V_34 |= V_39 ;
else
V_32 |= ( V_31 -> V_36 - 1 ) << V_40 ;
if ( ( V_31 -> V_33 & V_41 ) == 0 ) {
V_12 = F_18 ( V_1 -> V_8 [ V_13 ] ,
V_42 , V_35 ,
V_31 -> V_36 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_14 ( V_1 , V_31 -> V_43 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] , V_44 ,
V_32 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_5 ( V_1 -> V_8 [ V_13 ] ,
V_14 , V_39 |
V_15 , V_34 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_9 ( V_1 ) ;
if ( V_12 )
return V_12 ;
V_31 -> V_45 = V_46 ;
if ( ( V_31 -> V_36 > 0 ) && ( V_31 -> V_33 & V_41 ) ) {
V_12 = F_19 ( V_1 -> V_8 [ V_13 ] ,
V_42 , V_35 ,
V_31 -> V_36 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_6 ( V_1 -> V_8 [ V_13 ] ,
V_14 , V_39 ) ;
if ( V_12 )
return V_12 ;
return V_31 -> V_36 ;
}
static int F_20 ( struct V_1 * V_1 )
{
int V_12 ;
V_12 = F_6 ( V_1 -> V_8 [ V_47 ] ,
V_48 + 7 , V_49 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_50 ] , V_51 ,
V_52 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
int V_12 ;
V_12 = F_6 ( V_1 -> V_8 [ V_50 ] , V_51 ,
V_52 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_47 ] ,
V_48 + 7 , V_49 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
int V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_47 ] , V_53 ,
V_54 | V_55 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_47 ] , V_56 ,
V_57 | V_58 |
V_59 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_47 ] ,
V_60 , V_61 |
V_62 | V_63 | V_64 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_6 ( V_1 -> V_8 [ V_47 ] ,
V_60 , V_61 |
V_62 | V_63 | V_64 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_47 ] ,
V_65 + 1 , F_23 ( 5 ) |
F_23 ( 6 ) ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_47 ] ,
V_65 + 3 ,
V_66 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_47 ] , V_67 ,
V_68 | V_69 | V_70 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_6 ( V_1 -> V_8 [ V_47 ] ,
V_71 , V_72 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_47 ] ,
V_73 , V_74 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] ,
V_75 , V_76 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_24 ( V_1 -> V_8 [ V_47 ] ,
V_77 ,
F_25 ( V_77 ) ) ;
if ( V_12 )
return V_12 ;
V_12 = F_21 ( V_1 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 )
{
int V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_50 ] , V_78 ,
0x02 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_18 ( V_1 -> V_8 [ V_79 ] ,
V_80 ,
V_81 ,
F_25 ( V_81 ) ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 )
{
unsigned int V_11 ;
int V_12 ;
V_12 = F_5 ( V_1 -> V_8 [ V_50 ] ,
V_82 ,
V_83 | V_84 ,
V_85 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] , V_86 ,
V_87 & V_88 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] , V_89 ,
( ( V_87 & 0xff00 ) >> 2 ) | ( V_87 / 10 ) ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] ,
V_90 , V_87 & 0xff ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] ,
V_91 ,
( V_87 & 0xff00 ) >> 8 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] , V_92 ,
V_87 / 10 - 1 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_1 -> V_8 [ V_47 ] ,
V_93 ,
& V_11 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_47 ] ,
V_93 ,
( V_11 & V_94 ) |
( ( ( ( V_87 / 10 ) >> 1 ) - 2 ) << 3 ) ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_1 )
{
int V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] , V_14 ,
0x30 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_13 ] ,
V_14 , 0x08 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_6 ( V_1 -> V_8 [ V_13 ] ,
V_95 , V_96 |
V_97 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_24 ( V_1 -> V_8 [ V_13 ] ,
V_98 ,
F_25 ( V_98 ) ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_13 ] ,
V_99 , V_100 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_50 ] , V_101 ,
V_102 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] , V_103 ,
0x00 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_13 ] ,
V_95 , V_104 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_13 ] ,
V_105 , V_106 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_50 ] ,
V_82 , V_107 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_27 ( V_1 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] , V_108 ,
V_109 | 0x0c ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_13 ] ,
V_110 ,
V_111 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] ,
V_112 , 0x1d ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_13 ] ,
V_113 , V_114 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_13 ] ,
V_115 , V_116 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_26 ( V_1 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_13 ] ,
V_117 , V_118 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 )
{
int V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_50 ] , V_119 , 0x01 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_50 ] ,
V_120 , V_121 | V_122 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_50 ] , V_123 ,
V_124 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_47 ] , V_125 ,
V_126 | V_127 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_128 * V_129 = & V_1 -> V_129 ;
int V_12 ;
if ( F_17 ( V_1 -> V_130 ) )
return;
if ( V_129 -> V_131 ) {
V_12 = F_31 ( V_129 -> V_131 ) ;
if ( V_12 ) {
F_12 ( L_4 ,
V_12 ) ;
return;
}
F_13 ( 1000 , 2000 ) ;
}
F_32 ( V_129 -> V_132 , 1 ) ;
F_13 ( 1000 , 2000 ) ;
F_32 ( V_129 -> V_133 , 0 ) ;
F_13 ( 1000 , 2000 ) ;
F_32 ( V_129 -> V_132 , 0 ) ;
F_4 ( V_1 -> V_8 [ V_50 ] , V_134 ,
V_135 | V_136 | V_137 | V_138 ) ;
F_6 ( V_1 -> V_8 [ V_50 ] , V_134 ,
V_139 | V_140 ) ;
V_1 -> V_130 = true ;
}
static void F_33 ( struct V_1 * V_1 )
{
struct V_128 * V_129 = & V_1 -> V_129 ;
int V_12 ;
if ( F_17 ( ! V_1 -> V_130 ) )
return;
F_32 ( V_129 -> V_132 , 1 ) ;
F_13 ( 1000 , 2000 ) ;
F_32 ( V_129 -> V_133 , 1 ) ;
F_13 ( 1000 , 2000 ) ;
if ( V_129 -> V_131 ) {
V_12 = F_34 ( V_129 -> V_131 ) ;
if ( V_12 ) {
F_12 ( L_5 ,
V_12 ) ;
return;
}
F_13 ( 1000 , 2000 ) ;
}
V_1 -> V_130 = false ;
}
static int F_35 ( struct V_1 * V_1 )
{
int V_12 ;
V_12 = F_6 ( V_1 -> V_8 [ V_50 ] ,
V_134 ,
V_135 | V_136 | V_137 |
V_138 ) ;
V_12 = F_29 ( V_1 ) ;
if ( V_12 ) {
F_12 ( L_6 , V_12 ) ;
goto V_141;
}
V_12 = F_22 ( V_1 ) ;
if ( V_12 ) {
F_12 ( L_7 , V_12 ) ;
goto V_141;
}
V_12 = F_28 ( V_1 ) ;
if ( V_12 ) {
F_12 ( L_8 , V_12 ) ;
goto V_141;
}
F_13 ( 10000 , 15000 ) ;
return 0 ;
V_141:
F_12 ( L_9 , V_12 ) ;
F_33 ( V_1 ) ;
return V_12 ;
}
static int F_36 ( struct V_1 * V_1 )
{
struct V_128 * V_129 = & V_1 -> V_129 ;
struct V_142 * V_143 = & V_1 -> V_144 -> V_143 ;
V_129 -> V_131 = F_37 ( V_143 , L_10 ) ;
if ( F_38 ( V_129 -> V_131 ) ) {
F_12 ( L_11 ) ;
return F_39 ( V_129 -> V_131 ) ;
}
V_129 -> V_145 = F_40 ( V_143 , L_12 , V_146 ) ;
if ( F_38 ( V_129 -> V_145 ) )
return F_39 ( V_129 -> V_145 ) ;
V_129 -> V_133 = F_40 ( V_143 , L_13 , V_147 ) ;
if ( F_38 ( V_129 -> V_133 ) )
return F_39 ( V_129 -> V_133 ) ;
V_129 -> V_132 = F_40 ( V_143 , L_14 , V_148 ) ;
return F_41 ( V_129 -> V_132 ) ;
}
static int F_42 ( struct V_1 * V_1 )
{
T_1 V_149 , V_11 ;
int V_12 ;
V_12 = F_15 ( V_1 -> V_8 [ V_47 ] , V_53 ,
0x0 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_6 ( V_1 -> V_8 [ V_50 ] ,
V_134 ,
V_140 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_43 ( & V_1 -> V_29 , V_150 , & V_149 ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( V_149 ) {
case V_151 :
case V_152 :
case V_153 :
break;
default:
F_44 ( L_15 , V_149 ) ;
return - V_154 ;
}
V_12 = F_4 ( V_1 -> V_8 [ V_50 ] , V_155 ,
V_156 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_6 ( V_1 -> V_8 [ V_50 ] ,
V_155 , V_157 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_45 ( & V_1 -> V_29 , V_158 ,
& V_1 -> V_159 , V_160 ) ;
if ( V_12 < 0 ) {
F_12 ( L_16 , V_12 ) ;
return V_12 ;
}
V_12 = F_6 ( V_1 -> V_8 [ V_13 ] ,
V_115 , V_116 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_46 ( & V_1 -> V_29 , & V_1 -> V_161 ) ;
if ( V_12 < 0 ) {
F_12 ( L_17 , V_12 ) ;
return V_12 ;
}
V_12 = F_47 ( & V_1 -> V_29 , & V_1 -> V_161 ) ;
if ( V_12 < 0 ) {
F_12 ( L_18 , V_12 ) ;
return V_12 ;
}
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] ,
V_162 , 0 ) ;
if ( V_12 )
return V_12 ;
if ( V_1 -> V_159 [ V_163 ] & V_164 ) {
F_48 ( L_19 ) ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] ,
V_162 , 8 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_49 ( & V_1 -> V_29 , V_165 ,
V_166 ) ;
if ( V_12 < 0 )
return V_12 ;
} else {
V_12 = F_49 ( & V_1 -> V_29 , V_165 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
}
if ( F_50 ( V_1 -> V_159 ) )
V_12 = F_4 ( V_1 -> V_8 [ V_13 ] ,
V_167 + 4 ,
V_168 ) ;
else
V_12 = F_6 ( V_1 -> V_8 [ V_13 ] ,
V_167 + 4 ,
V_168 ) ;
if ( V_12 )
return V_12 ;
V_11 = F_51 ( V_1 -> V_161 . V_169 ) ;
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] ,
V_170 , V_11 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_52 ( & V_1 -> V_29 , & V_1 -> V_161 ) ;
if ( V_12 < 0 ) {
F_12 ( L_20 , V_12 ) ;
return V_12 ;
}
V_12 = F_15 ( V_1 -> V_8 [ V_13 ] , V_171 ,
V_172 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_1 )
{
int V_12 ;
V_12 = F_6 ( V_1 -> V_8 [ V_50 ] , V_155 ,
V_156 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_50 ] , V_155 ,
V_157 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_1 ,
struct V_173 * V_174 )
{
T_1 V_35 [ V_175 + V_176 ] ;
int V_12 ;
V_12 = F_55 ( V_174 , V_35 , sizeof( V_35 ) ) ;
if ( V_12 < 0 ) {
F_12 ( L_21 , V_12 ) ;
return V_12 ;
}
V_12 = F_6 ( V_1 -> V_8 [ V_13 ] ,
V_177 , V_178 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_18 ( V_1 -> V_8 [ V_50 ] ,
V_179 , V_35 ,
V_174 -> V_180 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_13 ] ,
V_177 , V_181 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_1 -> V_8 [ V_13 ] ,
V_177 , V_178 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_1 )
{
T_1 V_11 ;
int V_12 ;
V_12 = F_43 ( & V_1 -> V_29 , V_182 , & V_11 ) ;
if ( V_12 < 0 ) {
F_12 ( L_22 , V_12 ) ;
return V_12 ;
}
if ( ! F_57 ( V_11 ) ) {
F_12 ( L_23 ) ;
return - V_183 ;
}
return 0 ;
}
static int F_58 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_12 , V_184 = 0 ;
if ( F_17 ( ! V_1 -> V_130 ) )
return 0 ;
if ( V_1 -> V_185 )
return F_59 ( V_4 , V_1 -> V_185 ) ;
F_60 ( & V_1 -> V_186 ) ;
V_12 = F_56 ( V_1 ) ;
if ( V_12 ) {
F_12 ( L_24 , V_12 ) ;
goto V_187;
}
V_1 -> V_185 = F_61 ( V_4 , & V_1 -> V_29 . V_188 ) ;
if ( ! V_1 -> V_185 ) {
F_12 ( L_25 ) ;
goto V_187;
}
V_12 = F_62 ( V_4 ,
V_1 -> V_185 ) ;
if ( V_12 ) {
F_12 ( L_26 , V_12 ) ;
goto V_187;
}
V_184 = F_59 ( V_4 , V_1 -> V_185 ) ;
F_63 ( V_4 , V_1 -> V_185 ) ;
V_187:
F_64 ( & V_1 -> V_186 ) ;
return V_184 ;
}
static enum V_189 F_65 ( struct V_2 * V_4 ,
bool V_190 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( ! F_66 ( V_1 -> V_129 . V_145 ) )
return V_191 ;
return V_192 ;
}
static void F_67 ( struct V_2 * V_4 )
{
F_68 ( V_4 ) ;
}
static int F_69 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
int V_12 ;
if ( ! V_6 -> V_193 ) {
F_12 ( L_27 ) ;
return - V_194 ;
}
V_1 -> V_29 . V_195 = L_28 ;
V_1 -> V_29 . V_143 = & V_1 -> V_144 -> V_143 ;
V_1 -> V_29 . V_196 = F_16 ;
V_12 = F_70 ( & V_1 -> V_29 ) ;
if ( V_12 < 0 ) {
F_12 ( L_29 , V_12 ) ;
return V_12 ;
}
V_12 = F_71 ( V_6 -> V_143 , & V_1 -> V_4 ,
& V_197 ,
V_198 ) ;
if ( V_12 ) {
F_12 ( L_30 , V_12 ) ;
return V_12 ;
}
F_72 ( & V_1 -> V_4 ,
& V_199 ) ;
V_12 = F_73 ( & V_1 -> V_4 ) ;
if ( V_12 ) {
F_12 ( L_31 , V_12 ) ;
return V_12 ;
}
V_1 -> V_4 . V_200 = V_201 ;
V_12 = F_74 ( & V_1 -> V_4 ,
V_6 -> V_193 ) ;
if ( V_12 ) {
F_12 ( L_32 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static bool F_75 ( struct V_5 * V_6 ,
const struct V_202 * V_203 ,
struct V_202 * V_204 )
{
if ( V_203 -> V_205 & V_206 )
return false ;
if ( V_203 -> clock > 154000 )
return false ;
return true ;
}
static void F_76 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
F_4 ( V_1 -> V_8 [ V_50 ] , V_134 ,
V_135 | V_136 | V_137 | V_138 ) ;
}
static void F_77 ( struct V_5 * V_6 ,
struct V_202 * V_203 ,
struct V_202 * V_204 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_173 V_174 ;
int V_12 ;
if ( F_17 ( ! V_1 -> V_130 ) )
return;
F_60 ( & V_1 -> V_186 ) ;
V_12 = F_78 ( & V_174 , V_204 ) ;
if ( V_12 ) {
F_12 ( L_33 , V_12 ) ;
goto V_187;
}
V_12 = F_54 ( V_1 , & V_174 ) ;
if ( V_12 )
F_12 ( L_34 , V_12 ) ;
V_187:
F_64 ( & V_1 -> V_186 ) ;
}
static void F_79 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
int V_12 ;
V_12 = F_35 ( V_1 ) ;
if ( V_12 ) {
F_12 ( L_35 , V_12 ) ;
return;
}
V_12 = F_20 ( V_1 ) ;
if ( V_12 )
F_12 ( L_36 , V_12 ) ;
}
static T_3 F_80 ( int V_207 , void * V_208 )
{
struct V_1 * V_1 = V_208 ;
int V_12 ;
if ( V_1 -> V_130 )
return V_209 ;
F_60 ( & V_1 -> V_186 ) ;
F_30 ( V_1 ) ;
V_12 = F_29 ( V_1 ) ;
if ( V_12 )
F_12 ( L_6 , V_12 ) ;
F_64 ( & V_1 -> V_186 ) ;
return V_209 ;
}
static int F_81 ( struct V_1 * V_1 , T_1 V_207 )
{
int V_12 ;
F_44 ( L_37 , V_207 ) ;
V_12 = F_15 ( V_1 -> V_8 [ V_50 ] , V_210 ,
V_207 ) ;
if ( V_12 )
return V_12 ;
if ( V_207 & V_124 ) {
F_44 ( L_38 ) ;
V_12 = F_53 ( V_1 ) ;
}
return V_12 ;
}
static bool F_82 ( struct V_1 * V_1 , T_1 V_207 )
{
bool V_211 = false ;
int V_12 ;
F_44 ( L_39 , V_207 ) ;
V_12 = F_15 ( V_1 -> V_8 [ V_50 ] ,
V_212 , V_207 ) ;
if ( V_12 ) {
F_12 ( L_40 , V_12 ) ;
return V_211 ;
}
if ( V_207 & V_121 ) {
F_44 ( L_41 ) ;
V_211 = true ;
F_33 ( V_1 ) ;
F_83 ( V_1 -> V_185 ) ;
V_1 -> V_185 = NULL ;
} else if ( V_207 & V_122 ) {
F_44 ( L_42 ) ;
V_211 = true ;
}
return V_211 ;
}
static void F_84 ( struct V_1 * V_1 , T_1 V_207 )
{
unsigned int V_11 ;
int V_12 ;
F_44 ( L_43 , V_207 ) ;
V_12 = F_15 ( V_1 -> V_8 [ V_47 ] , V_213 ,
V_207 ) ;
if ( V_12 ) {
F_12 ( L_44 , V_12 ) ;
return;
}
if ( ( V_207 & V_126 ) || ( V_207 & V_127 ) ) {
F_44 ( L_45 ) ;
V_12 = F_8 ( V_1 -> V_8 [ V_47 ] ,
V_214 , & V_11 ) ;
if ( V_12 ) {
F_12 ( L_46 , V_12 ) ;
return;
}
if ( ! ( V_11 & V_215 ) ) {
F_44 ( L_47 ) ;
return;
}
if ( ! ( V_11 & V_216 ) ) {
F_44 ( L_48 ) ;
return;
}
V_12 = F_42 ( V_1 ) ;
if ( V_12 )
F_12 ( L_49 , V_12 ) ;
}
}
static T_3 F_85 ( int V_217 , void * V_208 )
{
struct V_1 * V_1 = V_208 ;
bool V_211 = false ;
unsigned int V_207 ;
int V_12 ;
F_60 ( & V_1 -> V_186 ) ;
V_12 = F_8 ( V_1 -> V_8 [ V_50 ] , V_210 ,
& V_207 ) ;
if ( V_12 ) {
F_12 ( L_50 , V_12 ) ;
goto V_187;
}
if ( V_207 )
F_81 ( V_1 , V_207 ) ;
V_12 = F_8 ( V_1 -> V_8 [ V_50 ] ,
V_212 , & V_207 ) ;
if ( V_12 ) {
F_12 ( L_51 ,
V_12 ) ;
goto V_187;
}
if ( V_207 )
V_211 = F_82 ( V_1 , V_207 ) ;
if ( ! V_1 -> V_130 )
goto V_187;
V_12 = F_8 ( V_1 -> V_8 [ V_47 ] , V_213 ,
& V_207 ) ;
if ( V_12 ) {
F_12 ( L_52 , V_12 ) ;
goto V_187;
}
if ( V_207 )
F_84 ( V_1 , V_207 ) ;
V_187:
F_64 ( & V_1 -> V_186 ) ;
if ( V_211 )
F_86 ( V_1 -> V_4 . V_143 ) ;
return V_209 ;
}
static void F_87 ( struct V_1 * V_1 )
{
unsigned int V_218 ;
for ( V_218 = 0 ; V_218 < F_25 ( V_1 -> V_219 ) ; V_218 ++ )
if ( V_1 -> V_219 [ V_218 ] )
F_88 ( V_1 -> V_219 [ V_218 ] ) ;
}
static int F_89 ( struct V_220 * V_144 ,
const struct V_221 * V_222 )
{
struct V_1 * V_1 ;
struct V_128 * V_129 ;
unsigned int V_218 , V_223 , V_224 , V_225 ;
bool V_226 = false ;
int V_12 ;
V_1 = F_90 ( & V_144 -> V_143 , sizeof( * V_1 ) , V_227 ) ;
if ( ! V_1 )
return - V_228 ;
V_129 = & V_1 -> V_129 ;
F_91 ( & V_1 -> V_186 ) ;
#if F_92 ( V_229 )
V_1 -> V_6 . V_230 = V_144 -> V_143 . V_230 ;
#endif
V_1 -> V_144 = V_144 ;
F_93 ( V_144 , V_1 ) ;
V_12 = F_36 ( V_1 ) ;
if ( V_12 ) {
F_12 ( L_53 , V_12 ) ;
return V_12 ;
}
V_129 -> V_231 = F_94 ( V_129 -> V_145 ) ;
if ( V_129 -> V_231 < 0 ) {
F_12 ( L_54 , V_129 -> V_231 ) ;
return - V_194 ;
}
V_129 -> V_232 = V_144 -> V_207 ;
if ( ! V_129 -> V_232 ) {
F_12 ( L_55 ) ;
return - V_194 ;
}
for ( V_218 = 0 ; V_218 < V_233 ; V_218 ++ ) {
V_1 -> V_219 [ V_218 ] = F_95 ( V_144 -> V_234 ,
V_235 [ V_218 ] >> 1 ) ;
if ( ! V_1 -> V_219 [ V_218 ] ) {
V_12 = - V_228 ;
F_12 ( L_56 ,
V_235 [ V_218 ] ) ;
goto V_236;
}
V_1 -> V_8 [ V_218 ] = F_96 ( V_1 -> V_219 [ V_218 ] ,
& V_237 ) ;
if ( F_38 ( V_1 -> V_8 [ V_218 ] ) ) {
V_12 = F_39 ( V_1 -> V_8 [ V_218 ] ) ;
F_12 ( L_57 ,
V_235 [ V_218 ] ) ;
goto V_236;
}
}
F_30 ( V_1 ) ;
V_12 = F_8 ( V_1 -> V_8 [ V_50 ] , V_238 ,
& V_223 ) ;
if ( V_12 )
goto V_141;
V_12 = F_8 ( V_1 -> V_8 [ V_50 ] , V_239 ,
& V_224 ) ;
if ( V_12 )
goto V_141;
V_1 -> V_240 = ( T_1 ) V_223 | ( ( T_1 ) V_224 << 8 ) ;
V_12 = F_8 ( V_1 -> V_8 [ V_50 ] , V_241 ,
& V_225 ) ;
if ( V_12 )
goto V_141;
for ( V_218 = 0 ; V_218 < F_25 ( V_242 ) ; V_218 ++ ) {
if ( V_1 -> V_240 == V_242 [ V_218 ] ) {
F_97 ( L_58 ,
V_1 -> V_240 , V_225 ) ;
V_226 = true ;
break;
}
}
if ( ! V_226 ) {
F_12 ( L_59 ,
V_1 -> V_240 , V_225 ) ;
V_12 = - V_194 ;
goto V_141;
}
V_12 = F_98 ( & V_144 -> V_143 , V_129 -> V_231 , NULL ,
F_80 ,
V_243 | V_244 ,
L_60 , V_1 ) ;
if ( V_12 ) {
F_12 ( L_61 ,
V_12 ) ;
goto V_141;
}
V_12 = F_98 ( & V_144 -> V_143 , V_129 -> V_232 , NULL ,
F_85 ,
V_243 | V_244 ,
L_62 , V_1 ) ;
if ( V_12 ) {
F_12 ( L_63 , V_12 ) ;
goto V_141;
}
V_1 -> V_6 . V_245 = & V_246 ;
V_12 = F_99 ( & V_1 -> V_6 ) ;
if ( V_12 < 0 ) {
F_12 ( L_64 , V_12 ) ;
goto V_141;
}
if ( ! F_66 ( V_1 -> V_129 . V_145 ) )
F_33 ( V_1 ) ;
return 0 ;
V_141:
F_33 ( V_1 ) ;
V_236:
F_87 ( V_1 ) ;
return V_12 ;
}
static int F_100 ( struct V_220 * V_144 )
{
struct V_1 * V_1 = F_101 ( V_144 ) ;
F_102 ( & V_1 -> V_6 ) ;
F_87 ( V_1 ) ;
F_83 ( V_1 -> V_185 ) ;
return 0 ;
}
