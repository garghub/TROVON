static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_2 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_3 , V_6 ;
V_3 = F_3 ( V_2 , V_7 ) ;
V_6 = ( V_3 >> V_8 ) & V_9 ;
return V_6 >= V_10 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
if ( F_5 ( V_2 ) ) {
F_7 ( & V_2 -> V_13 -> V_14 , L_1 ) ;
return 0 ;
}
F_8 ( V_15 , V_16 ) ;
}
F_9 ( & V_2 -> V_13 -> V_14 , L_2 ) ;
return - V_17 ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_18 , T_1 V_19 ,
T_1 V_20 , T_1 V_21 ,
T_1 V_22 , T_1 V_23 ,
T_1 V_24 , T_1 V_25 )
{
F_1 ( V_2 , V_20 , F_11 ( V_18 ) ) ;
F_1 ( V_2 , V_19 , F_12 ( V_18 ) ) ;
F_1 ( V_2 , V_21 , F_13 ( V_18 ) ) ;
F_1 ( V_2 , V_22 , F_14 ( V_18 ) ) ;
F_1 ( V_2 , V_23 , F_15 ( V_18 ) ) ;
F_1 ( V_2 , V_24 , F_16 ( V_18 ) ) ;
F_1 ( V_2 , V_25 , F_17 ( V_18 ) ) ;
F_1 ( V_2 , V_20 | F_18 ( 0 ) , F_11 ( V_18 ) ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ )
F_10 ( V_2 , V_26 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
V_4 = F_3 ( V_2 , V_27 ) ;
V_4 &= ~ ( V_28 << V_29 ) ;
V_4 |= ( ( V_30 & V_28 ) << V_29 ) ;
F_1 ( V_2 , V_4 , V_27 ) ;
V_4 = F_3 ( V_2 , V_31 ) ;
V_4 |= ( V_32 << V_33 ) ;
F_1 ( V_2 , V_4 , V_31 ) ;
V_4 = V_34 |
V_35 |
V_36 |
V_37 ;
F_1 ( V_2 , V_4 , V_38 ) ;
V_4 = V_39 |
( 7 << V_40 ) |
V_41 |
V_42 ;
F_1 ( V_2 , V_4 , V_43 ) ;
V_4 = V_44 |
V_45 ;
F_1 ( V_2 , V_4 , V_46 ) ;
V_4 = F_3 ( V_2 , V_31 ) ;
V_4 &= ~ V_47 ;
V_4 |= V_48 ;
F_1 ( V_2 , V_4 , V_31 ) ;
V_4 = F_3 ( V_2 , V_31 ) ;
V_4 &= ~ V_49 ;
V_4 |= V_50 ;
F_1 ( V_2 , V_4 , V_31 ) ;
V_4 = F_3 ( V_2 , V_31 ) ;
V_4 |= V_51 ;
F_1 ( V_2 , V_4 , V_31 ) ;
V_4 = F_3 ( V_2 , V_46 ) ;
V_4 |= V_52 ;
F_1 ( V_2 , V_4 , V_46 ) ;
F_1 ( V_2 , V_53 , V_54 ) ;
F_1 ( V_2 , V_55 , V_56 ) ;
F_1 ( V_2 , V_57 , V_58 ) ;
V_4 = V_53 ;
V_4 &= ~ V_59 ;
F_1 ( V_2 , V_4 , V_60 ) ;
F_1 ( V_2 , V_55 , V_61 ) ;
F_1 ( V_2 , 0 , V_62 ) ;
V_4 = V_57 & ( ~ V_63 ) ;
F_1 ( V_2 , V_4 , V_64 ) ;
V_4 = F_3 ( V_2 , V_46 ) ;
V_4 |= V_65 ;
F_1 ( V_2 , V_4 , V_46 ) ;
V_4 = F_3 ( V_2 , V_66 ) ;
V_4 |= V_67 ;
F_1 ( V_2 , V_4 , V_66 ) ;
V_4 = F_3 ( V_2 , V_68 ) ;
V_4 |= V_69 ;
F_1 ( V_2 , V_4 , V_68 ) ;
F_6 ( V_2 ) ;
V_4 = V_70 |
( 1 << V_71 ) ;
F_1 ( V_2 , V_4 , V_68 ) ;
V_4 = F_3 ( V_2 , V_72 ) ;
V_4 |= V_73 |
V_74 |
V_75 ;
F_1 ( V_2 , V_4 , V_72 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_4 ;
unsigned int V_76 ;
char * V_77 , * V_78 ;
V_4 = F_3 ( V_2 , V_79 ) ;
V_76 = ( V_4 & V_80 ) >>
V_81 ;
if ( ! V_76 )
return;
switch ( V_76 ) {
case V_82 :
V_77 = L_3 ;
break;
case V_83 :
V_77 = L_4 ;
break;
case V_84 :
V_77 = L_5 ;
break;
default:
V_77 = L_6 ;
break;
}
if ( V_4 & V_85 )
V_78 = L_7 ;
else
V_78 = L_8 ;
F_9 ( & V_2 -> V_13 -> V_14 , L_9 ,
V_78 , V_77 , V_4 , F_3 ( V_2 , V_86 ) ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned long V_87 ;
V_87 = V_88 + F_22 ( V_89 ) ;
while ( F_23 ( V_88 , V_87 ) ) {
T_1 V_90 , V_91 ;
V_90 = F_3 ( V_2 , V_92 ) ;
V_91 = F_3 ( V_2 , V_93 ) ;
if ( ! V_90 && V_91 )
return 0 ;
}
F_9 ( & V_2 -> V_13 -> V_14 , L_10 ) ;
return - V_17 ;
}
static int F_24 ( struct V_94 * V_95 , T_1 V_96 ,
int V_97 , int V_98 , T_1 * V_3 )
{
struct V_1 * V_2 = V_95 -> V_99 ;
T_1 V_4 ;
int V_100 ;
if ( F_25 ( V_96 ) != 0 ) {
* V_3 = 0xffffffff ;
return V_101 ;
}
F_1 ( V_2 , 0 , V_92 ) ;
F_1 ( V_2 , 1 , V_93 ) ;
V_4 = F_3 ( V_2 , V_66 ) ;
V_4 &= ~ V_102 ;
if ( V_95 -> V_103 == V_2 -> V_104 )
V_4 |= V_105 ;
else
V_4 |= V_106 ;
F_1 ( V_2 , V_4 , V_66 ) ;
V_4 = F_26 ( V_96 ) | F_27 ( V_97 ) ;
F_1 ( V_2 , V_4 , V_86 ) ;
F_1 ( V_2 , 0 , V_107 ) ;
F_1 ( V_2 , 0xf , V_108 ) ;
F_1 ( V_2 , 1 , V_92 ) ;
V_100 = F_21 ( V_2 ) ;
if ( V_100 < 0 )
return V_109 ;
F_20 ( V_2 ) ;
* V_3 = F_3 ( V_2 , V_110 ) ;
if ( V_98 == 1 )
* V_3 = ( * V_3 >> ( 8 * ( V_97 & 3 ) ) ) & 0xff ;
else if ( V_98 == 2 )
* V_3 = ( * V_3 >> ( 8 * ( V_97 & 3 ) ) ) & 0xffff ;
return V_111 ;
}
static int F_28 ( struct V_94 * V_95 , T_1 V_96 ,
int V_97 , int V_98 , T_1 V_3 )
{
struct V_1 * V_2 = V_95 -> V_99 ;
T_1 V_4 ;
T_1 V_112 = 0x0 ;
int V_113 ;
int V_100 ;
if ( F_25 ( V_96 ) != 0 )
return V_101 ;
if ( V_97 % V_98 )
return V_109 ;
F_1 ( V_2 , 0 , V_92 ) ;
F_1 ( V_2 , 1 , V_93 ) ;
V_4 = F_3 ( V_2 , V_66 ) ;
V_4 &= ~ V_102 ;
if ( V_95 -> V_103 == V_2 -> V_104 )
V_4 |= V_114 ;
else
V_4 |= V_115 ;
F_1 ( V_2 , V_4 , V_66 ) ;
V_4 = F_29 ( V_95 -> V_103 , V_96 , V_97 ) ;
F_1 ( V_2 , V_4 , V_86 ) ;
F_1 ( V_2 , 0 , V_107 ) ;
V_113 = V_97 & 0x3 ;
V_4 = V_3 << ( 8 * V_113 ) ;
V_112 = F_30 ( V_98 - 1 , 0 ) << V_113 ;
F_1 ( V_2 , V_4 , V_116 ) ;
F_1 ( V_2 , V_112 , V_108 ) ;
F_1 ( V_2 , 1 , V_92 ) ;
V_100 = F_21 ( V_2 ) ;
if ( V_100 < 0 )
return V_109 ;
F_20 ( V_2 ) ;
return V_111 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_117 ;
F_32 ( & V_2 -> V_118 ) ;
V_117 = F_33 ( V_2 -> V_119 , V_120 ) ;
if ( V_117 >= V_120 )
V_117 = - V_121 ;
else
F_34 ( V_117 , V_2 -> V_119 ) ;
F_35 ( & V_2 -> V_118 ) ;
return V_117 ;
}
static void F_36 ( struct V_1 * V_2 , int V_117 )
{
F_32 ( & V_2 -> V_118 ) ;
if ( ! F_37 ( V_117 , V_2 -> V_119 ) )
F_9 ( & V_2 -> V_13 -> V_14 , L_11 ,
V_117 ) ;
else
F_38 ( V_117 , V_2 -> V_119 ) ;
F_35 ( & V_2 -> V_118 ) ;
}
static int F_39 ( struct V_122 * V_123 ,
struct V_124 * V_13 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = V_13 -> V_95 -> V_99 ;
struct V_127 V_128 ;
int V_129 , V_117 ;
T_3 V_130 ;
if ( V_126 -> V_131 . V_132 )
return - V_133 ;
V_117 = F_31 ( V_2 ) ;
if ( V_117 < 0 )
return V_117 ;
V_129 = F_40 ( V_2 -> V_134 , V_117 ) ;
if ( ! V_129 ) {
F_36 ( V_2 , V_117 ) ;
return - V_133 ;
}
F_41 ( V_129 , V_126 ) ;
V_130 = F_42 ( & V_2 -> V_127 ) ;
V_128 . V_135 = F_43 ( V_130 ) ;
V_128 . V_136 = F_44 ( V_130 ) ;
V_128 . V_137 = V_129 ;
F_45 ( V_129 , & V_128 ) ;
return 0 ;
}
static void F_46 ( struct V_122 * V_123 ,
unsigned int V_138 )
{
struct V_139 * V_140 = F_47 ( V_138 ) ;
struct V_125 * V_141 = F_48 ( V_140 ) ;
struct V_1 * V_2 = F_49 ( V_141 ) ;
unsigned long V_117 = V_140 -> V_117 ;
F_50 ( V_138 ) ;
F_36 ( V_2 , V_117 ) ;
}
static int F_51 ( struct V_142 * V_143 ,
unsigned int V_129 , T_4 V_144 )
{
struct V_1 * V_2 = V_143 -> V_145 ;
F_52 ( V_129 , & V_2 -> V_146 ,
V_147 ) ;
return 0 ;
}
static void F_53 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = V_140 -> V_143 -> V_145 ;
T_4 V_117 = F_54 ( V_140 ) ;
T_1 V_148 ;
V_148 = F_3 ( V_2 , V_60 ) ;
V_148 |= F_55 ( V_117 ) ;
F_1 ( V_2 , V_148 , V_60 ) ;
}
static void F_56 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = V_140 -> V_143 -> V_145 ;
T_4 V_117 = F_54 ( V_140 ) ;
T_1 V_148 ;
V_148 = F_3 ( V_2 , V_60 ) ;
V_148 &= ~ F_55 ( V_117 ) ;
F_1 ( V_2 , V_148 , V_60 ) ;
}
static int F_57 ( struct V_142 * V_149 ,
unsigned int V_129 , T_4 V_117 )
{
struct V_1 * V_2 = V_149 -> V_145 ;
F_53 ( F_47 ( V_129 ) ) ;
F_58 ( V_129 , V_150 ) ;
F_52 ( V_129 , & V_2 -> V_151 ,
V_152 ) ;
F_59 ( V_129 , V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_153 * V_14 = & V_2 -> V_13 -> V_14 ;
struct V_154 * V_155 = V_14 -> V_156 ;
struct V_151 * V_146 ;
struct V_122 * V_141 ;
T_3 V_130 ;
int V_100 ;
V_146 = & V_2 -> V_146 ;
V_146 -> V_157 = F_61 ( V_14 , V_158 , L_12 ,
F_62 ( V_14 ) ) ;
if ( ! V_146 -> V_157 )
return - V_159 ;
V_146 -> V_160 = V_161 ;
V_146 -> V_162 = V_163 ;
V_146 -> V_164 = V_163 ;
V_146 -> V_165 = V_161 ;
V_141 = & V_2 -> V_141 ;
V_141 -> V_166 = F_39 ;
V_141 -> V_167 = F_46 ;
V_141 -> V_156 = V_155 ;
F_63 ( & V_2 -> V_118 ) ;
V_130 = F_42 ( & V_2 -> V_127 ) ;
F_1 ( V_2 , F_43 ( V_130 ) ,
V_168 ) ;
F_1 ( V_2 , F_44 ( V_130 ) ,
V_169 ) ;
V_2 -> V_134 =
F_64 ( NULL , V_120 ,
& V_170 , V_2 ) ;
if ( ! V_2 -> V_134 )
return - V_159 ;
V_100 = F_65 ( V_141 ) ;
if ( V_100 < 0 ) {
F_66 ( V_2 -> V_134 ) ;
return V_100 ;
}
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_68 ( & V_2 -> V_141 ) ;
F_66 ( V_2 -> V_134 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_153 * V_14 = & V_2 -> V_13 -> V_14 ;
struct V_154 * V_155 = V_14 -> V_156 ;
struct V_154 * V_171 ;
struct V_151 * V_151 ;
V_171 = F_70 ( V_155 , NULL ) ;
if ( ! V_171 ) {
F_9 ( V_14 , L_13 ) ;
return - V_172 ;
}
V_151 = & V_2 -> V_151 ;
V_151 -> V_157 = F_61 ( V_14 , V_158 , L_14 ,
F_62 ( V_14 ) ) ;
if ( ! V_151 -> V_157 ) {
F_71 ( V_171 ) ;
return - V_159 ;
}
V_151 -> V_164 = F_53 ;
V_151 -> V_173 = F_53 ;
V_151 -> V_165 = F_56 ;
V_2 -> V_142 =
F_64 ( V_171 , V_174 ,
& V_175 , V_2 ) ;
if ( ! V_2 -> V_142 ) {
F_9 ( V_14 , L_15 ) ;
F_71 ( V_171 ) ;
return - V_159 ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_66 ( V_2 -> V_142 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
T_1 V_176 , V_177 , V_178 , V_179 ;
T_5 V_180 ;
V_177 = F_3 ( V_2 , V_62 ) ;
V_176 = F_3 ( V_2 , V_181 ) ;
V_178 = V_176 & ~ V_177 ;
for ( V_179 = 0 ; V_179 < V_120 ; V_179 ++ ) {
if ( ! ( F_18 ( V_179 ) & V_178 ) )
continue;
F_1 ( V_2 , F_18 ( V_179 ) , V_181 ) ;
V_180 = F_3 ( V_2 , V_182 ) & 0xFF ;
F_74 ( V_180 ) ;
}
F_1 ( V_2 , V_59 ,
V_54 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
T_1 V_3 , V_148 , V_76 ;
int V_26 , V_129 ;
V_3 = F_3 ( V_2 , V_54 ) ;
V_148 = F_3 ( V_2 , V_60 ) ;
V_76 = V_3 & ( ( ~ V_148 ) & V_53 ) ;
if ( ! V_76 ) {
F_1 ( V_2 , V_3 , V_54 ) ;
return;
}
if ( V_76 & V_59 )
F_73 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_174 ; V_26 ++ ) {
if ( ! ( V_76 & F_55 ( V_26 ) ) )
continue;
F_1 ( V_2 , F_55 ( V_26 ) ,
V_54 ) ;
V_129 = F_76 ( V_2 -> V_142 , V_26 ) ;
F_74 ( V_129 ) ;
}
}
static T_6 F_77 ( int V_138 , void * V_183 )
{
struct V_1 * V_2 = V_183 ;
T_1 V_76 ;
V_76 = F_3 ( V_2 , V_58 ) ;
if ( ! ( V_76 & V_184 ) )
return V_185 ;
F_75 ( V_2 ) ;
F_1 ( V_2 , V_184 , V_58 ) ;
return V_186 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_187 , V_188 = 0 ;
struct V_153 * V_14 = & V_2 -> V_13 -> V_14 ;
struct V_154 * V_189 = V_14 -> V_156 ;
struct V_190 * V_191 ;
T_7 V_192 ;
F_79 ( & V_2 -> V_193 ) ;
V_187 = F_80 ( V_189 , 0 , 0xff , & V_2 -> V_193 ,
& V_192 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_81 ( V_14 , & V_2 -> V_193 ) ;
if ( V_187 )
goto V_194;
F_82 (win, &pcie->resources) {
struct V_195 * V_196 = V_191 -> V_196 ;
switch ( F_83 ( V_196 ) ) {
case V_197 :
F_10 ( V_2 , 1 ,
F_44 ( V_196 -> V_90 ) ,
F_43 ( V_196 -> V_90 ) ,
0 , 0xF8000000 , 0 ,
F_43 ( V_196 -> V_90 ) ,
V_198 ) ;
V_187 = F_84 ( V_196 , V_192 ) ;
if ( V_187 )
F_85 ( V_14 , L_16 ,
V_187 , V_196 ) ;
break;
case V_199 :
F_10 ( V_2 , 0 ,
F_44 ( V_196 -> V_90 ) ,
F_43 ( V_196 -> V_90 ) ,
0x0 , 0xF8000000 , 0 ,
F_43 ( V_196 -> V_90 ) ,
( 2 << 20 ) | V_200 ) ;
V_188 |= ! ( V_196 -> V_201 & V_202 ) ;
break;
case V_203 :
V_2 -> V_104 = V_196 -> V_90 ;
break;
}
}
if ( ! V_188 ) {
F_9 ( V_14 , L_17 ) ;
V_187 = - V_133 ;
goto V_194;
}
return 0 ;
V_194:
F_86 ( & V_2 -> V_193 ) ;
return V_187 ;
}
static int F_87 ( struct V_204 * V_13 )
{
struct V_1 * V_2 ;
struct V_195 * V_196 ;
struct V_94 * V_95 , * V_205 ;
struct V_122 * V_141 ;
struct V_154 * V_206 ;
int V_100 , V_138 ;
V_2 = F_88 ( & V_13 -> V_14 , sizeof( struct V_1 ) ,
V_158 ) ;
if ( ! V_2 )
return - V_159 ;
V_2 -> V_13 = V_13 ;
F_89 ( V_13 , V_2 ) ;
V_196 = F_90 ( V_13 , V_199 , 0 ) ;
V_2 -> V_5 = F_91 ( & V_13 -> V_14 , V_196 ) ;
if ( F_92 ( V_2 -> V_5 ) ) {
F_9 ( & V_13 -> V_14 , L_18 ) ;
return F_93 ( V_2 -> V_5 ) ;
}
V_138 = F_94 ( V_13 , 0 ) ;
V_100 = F_95 ( & V_13 -> V_14 , V_138 , F_77 ,
V_207 | V_208 , L_19 ,
V_2 ) ;
if ( V_100 ) {
F_9 ( & V_13 -> V_14 , L_20 ) ;
return V_100 ;
}
V_100 = F_78 ( V_2 ) ;
if ( V_100 ) {
F_9 ( & V_13 -> V_14 , L_21 ) ;
return V_100 ;
}
F_19 ( V_2 ) ;
V_100 = F_69 ( V_2 ) ;
if ( V_100 ) {
F_9 ( & V_13 -> V_14 , L_22 ) ;
return V_100 ;
}
V_100 = F_60 ( V_2 ) ;
if ( V_100 ) {
F_9 ( & V_13 -> V_14 , L_22 ) ;
F_72 ( V_2 ) ;
return V_100 ;
}
V_206 = F_96 ( V_13 -> V_14 . V_156 , L_23 , 0 ) ;
if ( V_206 )
V_141 = F_97 ( V_206 ) ;
else
V_141 = NULL ;
V_95 = F_98 ( & V_13 -> V_14 , 0 , & V_209 ,
V_2 , & V_2 -> V_193 , & V_2 -> V_141 ) ;
if ( ! V_95 ) {
F_67 ( V_2 ) ;
F_72 ( V_2 ) ;
return - V_159 ;
}
F_99 ( V_95 ) ;
F_100 (child, &bus->children, node)
F_101 ( V_205 ) ;
F_102 ( V_95 ) ;
return 0 ;
}
