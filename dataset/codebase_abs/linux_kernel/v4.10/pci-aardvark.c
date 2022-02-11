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
struct V_11 * V_12 = & V_2 -> V_13 -> V_12 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( F_5 ( V_2 ) ) {
F_7 ( V_12 , L_1 ) ;
return 0 ;
}
F_8 ( V_16 , V_17 ) ;
}
F_9 ( V_12 , L_2 ) ;
return - V_18 ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_19 , T_1 V_20 ,
T_1 V_21 , T_1 V_22 ,
T_1 V_23 , T_1 V_24 ,
T_1 V_25 , T_1 V_26 )
{
F_1 ( V_2 , V_21 , F_11 ( V_19 ) ) ;
F_1 ( V_2 , V_20 , F_12 ( V_19 ) ) ;
F_1 ( V_2 , V_22 , F_13 ( V_19 ) ) ;
F_1 ( V_2 , V_23 , F_14 ( V_19 ) ) ;
F_1 ( V_2 , V_24 , F_15 ( V_19 ) ) ;
F_1 ( V_2 , V_25 , F_16 ( V_19 ) ) ;
F_1 ( V_2 , V_26 , F_17 ( V_19 ) ) ;
F_1 ( V_2 , V_21 | F_18 ( 0 ) , F_11 ( V_19 ) ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ )
F_10 ( V_2 , V_27 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
V_4 = F_3 ( V_2 , V_28 ) ;
V_4 &= ~ ( V_29 << V_30 ) ;
V_4 |= ( ( V_31 & V_29 ) << V_30 ) ;
F_1 ( V_2 , V_4 , V_28 ) ;
V_4 = F_3 ( V_2 , V_32 ) ;
V_4 |= ( V_33 << V_34 ) ;
F_1 ( V_2 , V_4 , V_32 ) ;
V_4 = V_35 |
V_36 |
V_37 |
V_38 ;
F_1 ( V_2 , V_4 , V_39 ) ;
V_4 = V_40 |
( 7 << V_41 ) |
V_42 |
V_43 ;
F_1 ( V_2 , V_4 , V_44 ) ;
V_4 = V_45 |
V_46 ;
F_1 ( V_2 , V_4 , V_47 ) ;
V_4 = F_3 ( V_2 , V_32 ) ;
V_4 &= ~ V_48 ;
V_4 |= V_49 ;
F_1 ( V_2 , V_4 , V_32 ) ;
V_4 = F_3 ( V_2 , V_32 ) ;
V_4 &= ~ V_50 ;
V_4 |= V_51 ;
F_1 ( V_2 , V_4 , V_32 ) ;
V_4 = F_3 ( V_2 , V_32 ) ;
V_4 |= V_52 ;
F_1 ( V_2 , V_4 , V_32 ) ;
V_4 = F_3 ( V_2 , V_47 ) ;
V_4 |= V_53 ;
F_1 ( V_2 , V_4 , V_47 ) ;
F_1 ( V_2 , V_54 , V_55 ) ;
F_1 ( V_2 , V_56 , V_57 ) ;
F_1 ( V_2 , V_58 , V_59 ) ;
V_4 = V_54 ;
V_4 &= ~ V_60 ;
F_1 ( V_2 , V_4 , V_61 ) ;
F_1 ( V_2 , V_56 , V_62 ) ;
F_1 ( V_2 , 0 , V_63 ) ;
V_4 = V_58 & ( ~ V_64 ) ;
F_1 ( V_2 , V_4 , V_65 ) ;
V_4 = F_3 ( V_2 , V_47 ) ;
V_4 |= V_66 ;
F_1 ( V_2 , V_4 , V_47 ) ;
V_4 = F_3 ( V_2 , V_67 ) ;
V_4 |= V_68 ;
F_1 ( V_2 , V_4 , V_67 ) ;
V_4 = F_3 ( V_2 , V_69 ) ;
V_4 |= V_70 ;
F_1 ( V_2 , V_4 , V_69 ) ;
F_6 ( V_2 ) ;
V_4 = V_71 |
( 1 << V_72 ) ;
F_1 ( V_2 , V_4 , V_69 ) ;
V_4 = F_3 ( V_2 , V_73 ) ;
V_4 |= V_74 |
V_75 |
V_76 ;
F_1 ( V_2 , V_4 , V_73 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_13 -> V_12 ;
T_1 V_4 ;
unsigned int V_77 ;
char * V_78 , * V_79 ;
V_4 = F_3 ( V_2 , V_80 ) ;
V_77 = ( V_4 & V_81 ) >>
V_82 ;
if ( ! V_77 )
return;
switch ( V_77 ) {
case V_83 :
V_78 = L_3 ;
break;
case V_84 :
V_78 = L_4 ;
break;
case V_85 :
V_78 = L_5 ;
break;
default:
V_78 = L_6 ;
break;
}
if ( V_4 & V_86 )
V_79 = L_7 ;
else
V_79 = L_8 ;
F_9 ( V_12 , L_9 ,
V_79 , V_78 , V_4 , F_3 ( V_2 , V_87 ) ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_13 -> V_12 ;
unsigned long V_88 ;
V_88 = V_89 + F_22 ( V_90 ) ;
while ( F_23 ( V_89 , V_88 ) ) {
T_1 V_91 , V_92 ;
V_91 = F_3 ( V_2 , V_93 ) ;
V_92 = F_3 ( V_2 , V_94 ) ;
if ( ! V_91 && V_92 )
return 0 ;
}
F_9 ( V_12 , L_10 ) ;
return - V_18 ;
}
static int F_24 ( struct V_95 * V_96 , T_1 V_97 ,
int V_98 , int V_99 , T_1 * V_3 )
{
struct V_1 * V_2 = V_96 -> V_100 ;
T_1 V_4 ;
int V_101 ;
if ( F_25 ( V_97 ) != 0 ) {
* V_3 = 0xffffffff ;
return V_102 ;
}
F_1 ( V_2 , 0 , V_93 ) ;
F_1 ( V_2 , 1 , V_94 ) ;
V_4 = F_3 ( V_2 , V_67 ) ;
V_4 &= ~ V_103 ;
if ( V_96 -> V_104 == V_2 -> V_105 )
V_4 |= V_106 ;
else
V_4 |= V_107 ;
F_1 ( V_2 , V_4 , V_67 ) ;
V_4 = F_26 ( V_97 ) | F_27 ( V_98 ) ;
F_1 ( V_2 , V_4 , V_87 ) ;
F_1 ( V_2 , 0 , V_108 ) ;
F_1 ( V_2 , 0xf , V_109 ) ;
F_1 ( V_2 , 1 , V_93 ) ;
V_101 = F_21 ( V_2 ) ;
if ( V_101 < 0 )
return V_110 ;
F_20 ( V_2 ) ;
* V_3 = F_3 ( V_2 , V_111 ) ;
if ( V_99 == 1 )
* V_3 = ( * V_3 >> ( 8 * ( V_98 & 3 ) ) ) & 0xff ;
else if ( V_99 == 2 )
* V_3 = ( * V_3 >> ( 8 * ( V_98 & 3 ) ) ) & 0xffff ;
return V_112 ;
}
static int F_28 ( struct V_95 * V_96 , T_1 V_97 ,
int V_98 , int V_99 , T_1 V_3 )
{
struct V_1 * V_2 = V_96 -> V_100 ;
T_1 V_4 ;
T_1 V_113 = 0x0 ;
int V_114 ;
int V_101 ;
if ( F_25 ( V_97 ) != 0 )
return V_102 ;
if ( V_98 % V_99 )
return V_110 ;
F_1 ( V_2 , 0 , V_93 ) ;
F_1 ( V_2 , 1 , V_94 ) ;
V_4 = F_3 ( V_2 , V_67 ) ;
V_4 &= ~ V_103 ;
if ( V_96 -> V_104 == V_2 -> V_105 )
V_4 |= V_115 ;
else
V_4 |= V_116 ;
F_1 ( V_2 , V_4 , V_67 ) ;
V_4 = F_29 ( V_96 -> V_104 , V_97 , V_98 ) ;
F_1 ( V_2 , V_4 , V_87 ) ;
F_1 ( V_2 , 0 , V_108 ) ;
V_114 = V_98 & 0x3 ;
V_4 = V_3 << ( 8 * V_114 ) ;
V_113 = F_30 ( V_99 - 1 , 0 ) << V_114 ;
F_1 ( V_2 , V_4 , V_117 ) ;
F_1 ( V_2 , V_113 , V_109 ) ;
F_1 ( V_2 , 1 , V_93 ) ;
V_101 = F_21 ( V_2 ) ;
if ( V_101 < 0 )
return V_110 ;
F_20 ( V_2 ) ;
return V_112 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_118 ;
F_32 ( & V_2 -> V_119 ) ;
V_118 = F_33 ( V_2 -> V_120 , V_121 ) ;
if ( V_118 >= V_121 )
V_118 = - V_122 ;
else
F_34 ( V_118 , V_2 -> V_120 ) ;
F_35 ( & V_2 -> V_119 ) ;
return V_118 ;
}
static void F_36 ( struct V_1 * V_2 , int V_118 )
{
struct V_11 * V_12 = & V_2 -> V_13 -> V_12 ;
F_32 ( & V_2 -> V_119 ) ;
if ( ! F_37 ( V_118 , V_2 -> V_120 ) )
F_9 ( V_12 , L_11 , V_118 ) ;
else
F_38 ( V_118 , V_2 -> V_120 ) ;
F_35 ( & V_2 -> V_119 ) ;
}
static int F_39 ( struct V_123 * V_124 ,
struct V_125 * V_13 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = V_13 -> V_96 -> V_100 ;
struct V_128 V_129 ;
int V_130 , V_118 ;
T_3 V_131 ;
if ( V_127 -> V_132 . V_133 )
return - V_134 ;
V_118 = F_31 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
V_130 = F_40 ( V_2 -> V_135 , V_118 ) ;
if ( ! V_130 ) {
F_36 ( V_2 , V_118 ) ;
return - V_134 ;
}
F_41 ( V_130 , V_127 ) ;
V_131 = F_42 ( & V_2 -> V_128 ) ;
V_129 . V_136 = F_43 ( V_131 ) ;
V_129 . V_137 = F_44 ( V_131 ) ;
V_129 . V_138 = V_130 ;
F_45 ( V_130 , & V_129 ) ;
return 0 ;
}
static void F_46 ( struct V_123 * V_124 ,
unsigned int V_139 )
{
struct V_140 * V_141 = F_47 ( V_139 ) ;
struct V_126 * V_142 = F_48 ( V_141 ) ;
struct V_1 * V_2 = F_49 ( V_142 ) ;
unsigned long V_118 = V_141 -> V_118 ;
F_50 ( V_139 ) ;
F_36 ( V_2 , V_118 ) ;
}
static int F_51 ( struct V_143 * V_144 ,
unsigned int V_130 , T_4 V_145 )
{
struct V_1 * V_2 = V_144 -> V_146 ;
F_52 ( V_130 , & V_2 -> V_147 ,
V_148 ) ;
return 0 ;
}
static void F_53 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = V_141 -> V_144 -> V_146 ;
T_4 V_118 = F_54 ( V_141 ) ;
T_1 V_149 ;
V_149 = F_3 ( V_2 , V_61 ) ;
V_149 |= F_55 ( V_118 ) ;
F_1 ( V_2 , V_149 , V_61 ) ;
}
static void F_56 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = V_141 -> V_144 -> V_146 ;
T_4 V_118 = F_54 ( V_141 ) ;
T_1 V_149 ;
V_149 = F_3 ( V_2 , V_61 ) ;
V_149 &= ~ F_55 ( V_118 ) ;
F_1 ( V_2 , V_149 , V_61 ) ;
}
static int F_57 ( struct V_143 * V_150 ,
unsigned int V_130 , T_4 V_118 )
{
struct V_1 * V_2 = V_150 -> V_146 ;
F_53 ( F_47 ( V_130 ) ) ;
F_58 ( V_130 , V_151 ) ;
F_52 ( V_130 , & V_2 -> V_152 ,
V_153 ) ;
F_59 ( V_130 , V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_13 -> V_12 ;
struct V_154 * V_155 = V_12 -> V_156 ;
struct V_152 * V_147 ;
struct V_123 * V_142 ;
T_3 V_131 ;
int V_101 ;
V_147 = & V_2 -> V_147 ;
V_147 -> V_157 = F_61 ( V_12 , V_158 , L_12 ,
F_62 ( V_12 ) ) ;
if ( ! V_147 -> V_157 )
return - V_159 ;
V_147 -> V_160 = V_161 ;
V_147 -> V_162 = V_163 ;
V_147 -> V_164 = V_163 ;
V_147 -> V_165 = V_161 ;
V_142 = & V_2 -> V_142 ;
V_142 -> V_166 = F_39 ;
V_142 -> V_167 = F_46 ;
V_142 -> V_156 = V_155 ;
F_63 ( & V_2 -> V_119 ) ;
V_131 = F_42 ( & V_2 -> V_128 ) ;
F_1 ( V_2 , F_43 ( V_131 ) ,
V_168 ) ;
F_1 ( V_2 , F_44 ( V_131 ) ,
V_169 ) ;
V_2 -> V_135 =
F_64 ( NULL , V_121 ,
& V_170 , V_2 ) ;
if ( ! V_2 -> V_135 )
return - V_159 ;
V_101 = F_65 ( V_142 ) ;
if ( V_101 < 0 ) {
F_66 ( V_2 -> V_135 ) ;
return V_101 ;
}
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_68 ( & V_2 -> V_142 ) ;
F_66 ( V_2 -> V_135 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_13 -> V_12 ;
struct V_154 * V_155 = V_12 -> V_156 ;
struct V_154 * V_171 ;
struct V_152 * V_152 ;
V_171 = F_70 ( V_155 , NULL ) ;
if ( ! V_171 ) {
F_9 ( V_12 , L_13 ) ;
return - V_172 ;
}
V_152 = & V_2 -> V_152 ;
V_152 -> V_157 = F_61 ( V_12 , V_158 , L_14 ,
F_62 ( V_12 ) ) ;
if ( ! V_152 -> V_157 ) {
F_71 ( V_171 ) ;
return - V_159 ;
}
V_152 -> V_164 = F_53 ;
V_152 -> V_173 = F_53 ;
V_152 -> V_165 = F_56 ;
V_2 -> V_143 =
F_64 ( V_171 , V_174 ,
& V_175 , V_2 ) ;
if ( ! V_2 -> V_143 ) {
F_9 ( V_12 , L_15 ) ;
F_71 ( V_171 ) ;
return - V_159 ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_66 ( V_2 -> V_143 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
T_1 V_176 , V_177 , V_178 , V_179 ;
T_5 V_180 ;
V_177 = F_3 ( V_2 , V_63 ) ;
V_176 = F_3 ( V_2 , V_181 ) ;
V_178 = V_176 & ~ V_177 ;
for ( V_179 = 0 ; V_179 < V_121 ; V_179 ++ ) {
if ( ! ( F_18 ( V_179 ) & V_178 ) )
continue;
F_1 ( V_2 , F_18 ( V_179 ) , V_181 ) ;
V_180 = F_3 ( V_2 , V_182 ) & 0xFF ;
F_74 ( V_180 ) ;
}
F_1 ( V_2 , V_60 ,
V_55 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
T_1 V_3 , V_149 , V_77 ;
int V_27 , V_130 ;
V_3 = F_3 ( V_2 , V_55 ) ;
V_149 = F_3 ( V_2 , V_61 ) ;
V_77 = V_3 & ( ( ~ V_149 ) & V_54 ) ;
if ( ! V_77 ) {
F_1 ( V_2 , V_3 , V_55 ) ;
return;
}
if ( V_77 & V_60 )
F_73 ( V_2 ) ;
for ( V_27 = 0 ; V_27 < V_174 ; V_27 ++ ) {
if ( ! ( V_77 & F_55 ( V_27 ) ) )
continue;
F_1 ( V_2 , F_55 ( V_27 ) ,
V_55 ) ;
V_130 = F_76 ( V_2 -> V_143 , V_27 ) ;
F_74 ( V_130 ) ;
}
}
static T_6 F_77 ( int V_139 , void * V_183 )
{
struct V_1 * V_2 = V_183 ;
T_1 V_77 ;
V_77 = F_3 ( V_2 , V_59 ) ;
if ( ! ( V_77 & V_184 ) )
return V_185 ;
F_75 ( V_2 ) ;
F_1 ( V_2 , V_184 , V_59 ) ;
return V_186 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_187 , V_188 = 0 ;
struct V_11 * V_12 = & V_2 -> V_13 -> V_12 ;
struct V_154 * V_189 = V_12 -> V_156 ;
struct V_190 * V_191 , * V_192 ;
T_7 V_193 ;
F_79 ( & V_2 -> V_194 ) ;
V_187 = F_80 ( V_189 , 0 , 0xff , & V_2 -> V_194 ,
& V_193 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_81 ( V_12 , & V_2 -> V_194 ) ;
if ( V_187 )
goto V_195;
F_82 (win, tmp, &pcie->resources) {
struct V_196 * V_197 = V_191 -> V_197 ;
switch ( F_83 ( V_197 ) ) {
case V_198 :
F_10 ( V_2 , 1 ,
F_44 ( V_197 -> V_91 ) ,
F_43 ( V_197 -> V_91 ) ,
0 , 0xF8000000 , 0 ,
F_43 ( V_197 -> V_91 ) ,
V_199 ) ;
V_187 = F_84 ( V_197 , V_193 ) ;
if ( V_187 ) {
F_85 ( V_12 , L_16 ,
V_187 , V_197 ) ;
F_86 ( V_191 ) ;
}
break;
case V_200 :
F_10 ( V_2 , 0 ,
F_44 ( V_197 -> V_91 ) ,
F_43 ( V_197 -> V_91 ) ,
0x0 , 0xF8000000 , 0 ,
F_43 ( V_197 -> V_91 ) ,
( 2 << 20 ) | V_201 ) ;
V_188 |= ! ( V_197 -> V_202 & V_203 ) ;
break;
case V_204 :
V_2 -> V_105 = V_197 -> V_91 ;
break;
}
}
if ( ! V_188 ) {
F_9 ( V_12 , L_17 ) ;
V_187 = - V_134 ;
goto V_195;
}
return 0 ;
V_195:
F_87 ( & V_2 -> V_194 ) ;
return V_187 ;
}
static int F_88 ( struct V_205 * V_13 )
{
struct V_11 * V_12 = & V_13 -> V_12 ;
struct V_1 * V_2 ;
struct V_196 * V_197 ;
struct V_95 * V_96 , * V_206 ;
struct V_123 * V_142 ;
struct V_154 * V_207 ;
int V_101 , V_139 ;
V_2 = F_89 ( V_12 , sizeof( struct V_1 ) , V_158 ) ;
if ( ! V_2 )
return - V_159 ;
V_2 -> V_13 = V_13 ;
V_197 = F_90 ( V_13 , V_200 , 0 ) ;
V_2 -> V_5 = F_91 ( V_12 , V_197 ) ;
if ( F_92 ( V_2 -> V_5 ) )
return F_93 ( V_2 -> V_5 ) ;
V_139 = F_94 ( V_13 , 0 ) ;
V_101 = F_95 ( V_12 , V_139 , F_77 ,
V_208 | V_209 , L_18 ,
V_2 ) ;
if ( V_101 ) {
F_9 ( V_12 , L_19 ) ;
return V_101 ;
}
V_101 = F_78 ( V_2 ) ;
if ( V_101 ) {
F_9 ( V_12 , L_20 ) ;
return V_101 ;
}
F_19 ( V_2 ) ;
V_101 = F_69 ( V_2 ) ;
if ( V_101 ) {
F_9 ( V_12 , L_21 ) ;
return V_101 ;
}
V_101 = F_60 ( V_2 ) ;
if ( V_101 ) {
F_9 ( V_12 , L_21 ) ;
F_72 ( V_2 ) ;
return V_101 ;
}
V_207 = F_96 ( V_12 -> V_156 , L_22 , 0 ) ;
if ( V_207 )
V_142 = F_97 ( V_207 ) ;
else
V_142 = NULL ;
V_96 = F_98 ( V_12 , 0 , & V_210 ,
V_2 , & V_2 -> V_194 , & V_2 -> V_142 ) ;
if ( ! V_96 ) {
F_67 ( V_2 ) ;
F_72 ( V_2 ) ;
return - V_159 ;
}
F_99 ( V_96 ) ;
F_100 (child, &bus->children, node)
F_101 ( V_206 ) ;
F_102 ( V_96 ) ;
return 0 ;
}
