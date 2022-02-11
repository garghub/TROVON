static inline void F_1 ( const struct V_1 * V_2 ,
int * V_3 , int * V_4 )
{
* V_3 = V_2 -> V_5 >> 8 ;
* V_4 = V_2 -> V_5 & 0xff ;
}
static int F_2 ( int V_6 )
{
int V_7 = - V_8 ;
F_3 ( & V_9 ) ;
if ( V_10 + V_6 <= V_11 ) {
V_7 = V_10 ;
V_10 += V_6 ;
}
F_4 ( & V_9 ) ;
return V_7 ;
}
static inline struct V_12 * F_5 ( struct V_13 * V_14 )
{
return F_6 ( V_14 , struct V_12 , V_14 ) ;
}
static void F_7 ( struct V_12 * V_15 , int V_16 ,
T_1 V_17 , T_1 V_18 )
{
T_1 V_19 = F_8 ( V_15 -> V_20 + V_16 ) ;
V_19 &= ~ V_17 ;
V_19 |= V_18 ;
F_9 ( V_19 , V_15 -> V_20 + V_16 ) ;
}
static void F_10 ( struct V_12 * V_15 , int V_16 , T_1 V_21 )
{
F_7 ( V_15 , V_16 , V_21 , 0 ) ;
}
static void F_11 ( struct V_12 * V_15 , int V_16 , T_1 V_21 )
{
F_7 ( V_15 , V_16 , 0 , V_21 ) ;
}
static void F_12 ( struct V_12 * V_15 , int V_22 ,
int V_23 )
{
unsigned long V_24 , V_25 ;
F_13 ( & V_15 -> V_26 -> V_27 , V_24 ) ;
V_25 = F_8 ( V_15 -> V_28 + V_29 ) ;
if ( V_23 )
V_25 &= ~ F_14 ( V_22 ) ;
else
V_25 |= F_14 ( V_22 ) ;
F_9 ( V_25 , V_15 -> V_28 + V_29 ) ;
F_15 ( & V_15 -> V_26 -> V_27 , V_24 ) ;
}
static unsigned int F_16 ( struct V_13 * V_14 )
{
struct V_12 * V_15 = F_5 ( V_14 ) ;
unsigned long V_30 , V_24 ;
F_13 ( & V_15 -> V_14 . V_31 , V_24 ) ;
V_30 = F_17 ( V_15 -> V_20 + V_32 ) ;
F_15 ( & V_15 -> V_14 . V_31 , V_24 ) ;
return V_30 ? 0 : V_33 ;
}
static unsigned int F_18 ( struct V_13 * V_14 )
{
struct V_12 * V_15 = F_5 ( V_14 ) ;
T_1 V_34 ;
V_34 = F_8 ( V_15 -> V_20 + V_35 ) ;
return ( ( V_34 & V_36 ) ? V_37 : 0 ) |
( ( V_34 & V_38 ) ? V_39 : 0 ) |
( ( V_34 & V_40 ) ? V_41 : 0 ) |
( ( V_34 & V_42 ) ? V_43 : 0 ) ;
}
static void F_19 ( struct V_13 * V_14 , unsigned int V_44 )
{
F_7 ( F_5 ( V_14 ) , V_45 ,
V_46 | V_47 | V_48 ,
( ( V_44 & V_49 ) ? V_46 : 0 ) |
( ( V_44 & V_50 ) ? V_47 : 0 ) |
( ( V_44 & V_51 ) ? V_48 : 0 ) ) ;
}
static void F_20 ( struct V_13 * V_14 )
{
F_11 ( F_5 ( V_14 ) , V_45 , V_52 ) ;
}
static void F_21 ( struct V_13 * V_14 )
{
F_10 ( F_5 ( V_14 ) , V_45 , V_52 ) ;
}
static void F_22 ( struct V_13 * V_14 )
{
F_10 ( F_5 ( V_14 ) , V_45 , V_53 ) ;
}
static void F_23 ( struct V_13 * V_14 , int V_54 )
{
unsigned long V_24 ;
F_13 ( & V_14 -> V_31 , V_24 ) ;
F_7 ( F_5 ( V_14 ) , V_45 , V_55 ,
V_54 ? V_55 : 0 ) ;
F_15 ( & V_14 -> V_31 , V_24 ) ;
}
static void F_24 ( struct V_13 * V_14 )
{
F_11 ( F_5 ( V_14 ) , V_45 , V_56 ) ;
}
static void F_25 ( struct V_12 * V_15 ,
unsigned long V_57 ,
unsigned long V_58 ,
unsigned int V_59 )
{
F_26 ( V_59 - 1 , V_15 -> V_20 + V_60 ) ;
F_7 ( V_15 , V_61 ,
V_62 | V_63 ,
( ( V_57 & V_64 ) ? V_62 : 0 ) |
( ( ( V_57 & V_65 ) == V_66 ) ? V_67 : 0 ) |
( ( ( V_57 & V_65 ) == V_68 ) ? V_69 : 0 ) |
( ( ( V_57 & V_65 ) == V_70 ) ? V_71 : 0 ) |
( ( ( V_57 & V_65 ) == V_72 ) ? V_73 : 0 ) ) ;
F_7 ( V_15 , V_45 ,
V_74 | V_75 |
V_76 | V_77 |
V_78 | V_79 |
V_80 ,
( ( V_57 & V_81 ) ? V_74 : 0 ) |
( ( V_57 & V_82 ) ? 0 : V_75 ) |
( ( V_57 & V_83 ) ? V_76 : 0 ) |
( ( V_57 & V_84 ) ? ( V_79 |
V_80 ) : 0 ) ) ;
F_27 ( ( V_58 & V_85 ) ? V_86 : V_87 ,
V_15 -> V_88 + V_89 ) ;
F_27 ( ( V_58 & V_90 ) ? V_91 : V_92 ,
V_15 -> V_88 + V_93 ) ;
}
static void F_28 ( struct V_13 * V_14 ,
struct V_94 * V_95 ,
struct V_94 * V_96 )
{
struct V_12 * V_15 = F_5 ( V_14 ) ;
unsigned long V_24 ;
unsigned int V_97 , V_59 ;
V_97 = F_29 ( V_14 , V_95 , V_96 , 0 , V_14 -> V_98 / 16 ) ;
V_59 = F_30 ( V_14 , V_97 ) ;
if ( F_31 ( V_95 ) )
F_32 ( V_95 , V_97 , V_97 ) ;
F_13 ( & V_14 -> V_31 , V_24 ) ;
V_14 -> V_99 = ( V_95 -> V_100 & V_101 ) ? 0 : V_102 ;
F_25 ( V_15 , V_95 -> V_100 , V_95 -> V_103 , V_59 ) ;
F_33 ( V_14 , V_95 -> V_100 , V_97 ) ;
F_15 ( & V_14 -> V_31 , V_24 ) ;
}
static void F_34 ( struct V_12 * V_15 )
{
T_2 V_104 = F_17 ( V_15 -> V_20 + V_105 ) ;
struct V_106 * V_14 = & V_15 -> V_14 . V_107 -> V_14 ;
for (; V_104 != 0 ; V_104 -- ) {
T_1 V_108 = F_17 ( V_15 -> V_20 + V_109 ) | V_102 ;
char V_110 = V_108 & 0xff ;
if ( F_35 ( ! ( V_108 & V_111 ) ) ) {
if ( ! F_36 ( & V_15 -> V_14 , V_110 ) )
F_37 ( & V_15 -> V_14 , V_108 , 0 , V_110 ,
V_112 ) ;
} else {
char V_113 = V_112 ;
if ( V_108 & V_114 )
V_113 = V_115 ;
else if ( V_108 & V_116 )
V_113 = V_117 ;
else if ( V_108 & V_118 )
V_113 = V_119 ;
F_37 ( & V_15 -> V_14 , V_108 ,
V_120 , V_110 , V_113 ) ;
}
V_15 -> V_14 . V_121 . V_122 ++ ;
}
F_38 ( V_14 ) ;
}
static void F_39 ( struct V_12 * V_15 )
{
T_2 V_123 = V_124 - F_17 ( V_15 -> V_20 + V_32 ) ;
struct V_125 * V_126 = & V_15 -> V_14 . V_107 -> V_126 ;
if ( F_40 ( & V_15 -> V_14 ) ) {
F_21 ( & V_15 -> V_14 ) ;
return;
}
for (; V_123 != 0 ; V_123 -- ) {
if ( V_15 -> V_14 . V_127 ) {
F_27 ( V_15 -> V_14 . V_127 , V_15 -> V_20 + V_109 ) ;
V_15 -> V_14 . V_127 = 0 ;
V_15 -> V_14 . V_121 . V_128 ++ ;
continue;
}
if ( F_41 ( V_126 ) ) {
F_21 ( & V_15 -> V_14 ) ;
break;
}
F_27 ( V_126 -> V_129 [ V_126 -> V_130 ] , V_15 -> V_20 + V_109 ) ;
V_126 -> V_130 = ( V_126 -> V_130 + 1 ) & ( V_131 - 1 ) ;
V_15 -> V_14 . V_121 . V_128 ++ ;
}
if ( F_42 ( V_126 ) < V_132 )
F_43 ( & V_15 -> V_14 ) ;
}
static void F_44 ( struct V_12 * V_15 )
{
T_1 V_34 ;
F_3 ( & V_15 -> V_14 . V_31 ) ;
V_34 = F_8 ( V_15 -> V_20 + V_35 ) ;
F_9 ( V_34 , V_15 -> V_20 + V_35 ) ;
if ( V_34 & V_133 )
F_34 ( V_15 ) ;
if ( V_34 & V_134 )
F_39 ( V_15 ) ;
if ( V_34 & V_135 )
F_45 ( & V_15 -> V_14 . V_107 -> V_14 . V_136 ) ;
F_4 ( & V_15 -> V_14 . V_31 ) ;
}
static int F_46 ( struct V_137 * V_26 , unsigned int V_138 )
{
void T_3 * V_20 = V_26 -> V_139 + F_47 ( V_138 ) ;
int V_110 , V_140 = 0 ;
unsigned long V_34 = F_8 ( V_20 + V_141 ) &
~ F_8 ( V_20 + V_29 ) ;
F_48 (ch, &status, PORTS_PER_ASIC) {
F_44 ( & V_26 -> V_3 [ V_110 ] ) ;
V_140 ++ ;
}
return V_140 ;
}
static T_4 F_49 ( int V_142 , void * V_143 )
{
struct V_137 * V_26 = V_143 ;
int V_140 ;
V_140 = F_46 ( V_26 , 0 ) ;
if ( V_26 -> V_6 >= V_144 )
V_140 += F_46 ( V_26 , 1 ) ;
return V_140 ? V_145 : V_146 ;
}
static inline void F_50 ( struct V_12 * V_15 )
{
F_11 ( V_15 , V_61 ,
V_147 | V_148 ) ;
F_8 ( V_15 -> V_20 + V_61 ) ;
F_51 ( 10 ) ;
F_10 ( V_15 , V_61 ,
V_147 | V_148 ) ;
}
static int F_52 ( struct V_13 * V_14 )
{
struct V_12 * V_15 = F_5 ( V_14 ) ;
F_50 ( V_15 ) ;
F_7 ( V_15 , V_45 , V_56 , V_53 ) ;
F_7 ( V_15 , V_45 , V_149 ,
V_150 ) ;
F_7 ( V_15 , V_35 , 0 , 0 ) ;
F_12 ( V_15 , V_15 -> V_151 , 1 ) ;
return 0 ;
}
static void F_53 ( struct V_13 * V_14 )
{
struct V_12 * V_15 = F_5 ( V_14 ) ;
unsigned long V_24 ;
F_23 ( V_14 , 0 ) ;
F_13 ( & V_14 -> V_31 , V_24 ) ;
F_12 ( V_15 , V_15 -> V_151 , 0 ) ;
F_7 ( V_15 , V_35 , 0 , 0 ) ;
F_15 ( & V_14 -> V_31 , V_24 ) ;
}
static const char * F_54 ( struct V_13 * V_14 )
{
return ( V_14 -> type == V_152 ) ? L_1 : NULL ;
}
static void F_55 ( struct V_13 * V_14 )
{
}
static int F_56 ( struct V_13 * V_14 )
{
return 0 ;
}
static void F_57 ( struct V_13 * V_14 , int V_24 )
{
if ( V_24 & V_153 )
V_14 -> type = V_152 ;
}
static int F_58 ( struct V_13 * V_14 ,
struct V_154 * V_155 )
{
if ( V_155 -> type != V_156 && V_155 -> type != V_152 )
return - V_157 ;
return 0 ;
}
static void F_59 ( struct V_137 * V_26 , unsigned int V_138 )
{
void T_3 * V_20 = V_26 -> V_139 + F_47 ( V_138 ) ;
T_1 V_158 ;
F_26 ( 1 , V_20 + V_159 ) ;
F_17 ( V_20 + V_159 ) ;
F_60 ( 100 ) ;
F_9 ( 0 , V_20 + V_160 ) ;
V_158 = F_17 ( V_20 + V_161 ) ;
V_158 = ( V_158 & ~ F_14 ( 8 ) ) | F_14 ( 9 ) ;
F_26 ( V_158 , V_20 + V_161 ) ;
F_9 ( V_162 , V_20 + V_29 ) ;
F_9 ( V_163 , V_20 + V_164 ) ;
}
static void F_61 ( struct V_137 * V_26 )
{
F_9 ( 4 , V_26 -> V_165 + V_166 ) ;
F_9 ( 0 , V_26 -> V_165 + V_167 ) ;
F_59 ( V_26 , 0 ) ;
if ( V_26 -> V_6 >= V_144 )
F_59 ( V_26 , 1 ) ;
F_9 ( V_168 , V_26 -> V_165 + V_169 ) ;
}
static void F_62 ( struct V_12 * V_15 , const struct V_170 * V_171 )
{
int V_172 ;
F_9 ( V_173 , V_15 -> V_20 + V_61 ) ;
F_8 ( V_15 -> V_20 + V_61 ) ;
F_51 ( 1 ) ;
F_9 ( 0 , V_15 -> V_20 + V_45 ) ;
F_9 ( 0 , V_15 -> V_20 + V_61 ) ;
F_8 ( V_15 -> V_20 + V_61 ) ;
F_51 ( 1 ) ;
F_50 ( V_15 ) ;
for ( V_172 = 0 ; V_172 < F_63 ( int , V_171 -> V_174 , V_175 ) ; V_172 ++ )
F_27 ( V_171 -> V_176 [ V_172 ] , V_15 -> V_88 + V_172 ) ;
F_25 ( V_15 , V_66 | V_101 | V_177 , 0 , V_178 ) ;
F_19 ( & V_15 -> V_14 , 0 ) ;
F_27 ( V_179 , V_15 -> V_88 + V_180 ) ;
F_7 ( V_15 , V_61 , V_181 ,
V_182 | V_183 ) ;
F_11 ( V_15 , V_45 ,
V_184 | V_185 ) ;
}
static void F_64 ( struct V_137 * V_26 )
{
int V_172 ;
for ( V_172 = 0 ; V_172 < V_26 -> V_186 ; V_172 ++ )
F_65 ( & V_187 , & V_26 -> V_3 [ V_172 ] . V_14 ) ;
V_26 -> V_186 = 0 ;
}
static void F_66 ( const struct V_170 * V_171 , void * V_188 )
{
struct V_137 * V_26 = V_188 ;
T_5 V_189 ;
int V_172 , V_190 = - V_191 ;
if ( ! V_171 ) {
F_67 ( & V_26 -> V_192 -> V_193 , L_2 ,
V_194 ) ;
goto V_195;
}
V_189 = F_68 ( V_26 -> V_192 , 1 ) ;
for ( V_172 = 0 ; V_172 < V_26 -> V_6 ; V_172 ++ ) {
struct V_12 * V_196 = & V_26 -> V_3 [ V_172 ] ;
struct V_13 * V_197 ;
int V_198 = ( unsigned ) V_172 % V_144 ;
V_196 -> V_28 = V_26 -> V_139 ;
V_196 -> V_20 = V_26 -> V_139 + V_199 + V_198 * V_200 ;
V_196 -> V_88 = V_26 -> V_139 + V_201 + V_198 * V_202 ;
V_196 -> V_26 = V_26 ;
V_196 -> V_151 = V_198 ;
V_197 = & V_196 -> V_14 ;
V_197 -> line = V_26 -> V_203 + V_172 ;
V_197 -> V_193 = & V_26 -> V_192 -> V_193 ;
V_197 -> type = V_152 ;
V_197 -> V_204 = V_205 ;
V_197 -> V_98 = V_206 ;
V_197 -> V_207 = 2 ;
V_197 -> V_208 = V_124 ;
V_197 -> V_209 = & V_210 ;
V_197 -> V_142 = V_26 -> V_192 -> V_142 ;
V_197 -> V_211 = V_196 -> V_20 ;
V_197 -> V_212 = V_189 + V_199 + V_198 * V_200 ;
if ( V_172 >= V_144 ) {
V_196 -> V_28 += V_213 ;
V_196 -> V_20 += V_213 ;
V_196 -> V_88 += V_213 ;
V_197 -> V_212 += V_213 ;
}
F_62 ( V_196 , V_171 ) ;
V_190 = F_69 ( & V_187 , V_197 ) ;
if ( V_190 ) {
F_67 ( & V_26 -> V_192 -> V_193 ,
L_3 , V_172 , V_190 ) ;
F_64 ( V_26 ) ;
break;
}
V_26 -> V_186 ++ ;
}
F_70 ( V_171 ) ;
V_195:
if ( V_190 )
F_71 ( & V_26 -> V_192 -> V_193 , L_4 ) ;
F_72 ( & V_26 -> V_214 ) ;
}
static int F_73 ( struct V_215 * V_192 ,
const struct V_1 * V_2 )
{
struct V_137 * V_26 ;
struct V_12 * V_3 ;
void T_3 * const * V_216 ;
int V_190 ;
V_26 = F_74 ( & V_192 -> V_193 , sizeof( * V_26 ) , V_217 ) ;
if ( ! V_26 )
return - V_218 ;
F_75 ( V_192 , V_26 ) ;
F_76 ( & V_26 -> V_27 ) ;
F_77 ( & V_26 -> V_214 ) ;
V_190 = F_78 ( V_192 ) ;
if ( V_190 )
return V_190 ;
V_190 = F_79 ( V_192 , 0x03 , V_219 ) ;
if ( V_190 )
return V_190 ;
V_216 = F_80 ( V_192 ) ;
V_26 -> V_165 = V_216 [ 0 ] ;
V_26 -> V_139 = V_216 [ 1 ] ;
V_26 -> V_192 = V_192 ;
F_1 ( V_2 , & V_26 -> V_6 , & V_26 -> V_4 ) ;
F_81 ( & V_192 -> V_193 , L_5 , V_26 -> V_6 ) ;
V_26 -> V_203 = F_2 ( V_26 -> V_6 ) ;
if ( V_26 -> V_203 < 0 ) {
F_67 ( & V_192 -> V_193 ,
L_6 ) ;
return - V_157 ;
}
F_61 ( V_26 ) ;
V_3 = F_74 ( & V_192 -> V_193 , sizeof( * V_3 ) * V_26 -> V_6 ,
V_217 ) ;
if ( ! V_3 )
return - V_218 ;
V_26 -> V_3 = V_3 ;
V_190 = F_82 ( & V_192 -> V_193 , V_192 -> V_142 , F_49 ,
V_220 , V_219 , V_26 ) ;
if ( V_190 )
return V_190 ;
V_190 = F_83 ( V_221 , 1 , V_194 , & V_192 -> V_193 ,
V_217 , V_26 , F_66 ) ;
if ( V_190 )
return V_190 ;
F_84 ( & V_192 -> V_193 , L_7 ) ;
return 0 ;
}
static void F_85 ( struct V_215 * V_192 )
{
struct V_137 * V_26 = F_86 ( V_192 ) ;
F_87 ( & V_26 -> V_214 ) ;
F_64 ( V_26 ) ;
}
static int T_6 F_88 ( void )
{
int V_190 ;
V_190 = F_89 ( & V_187 ) ;
if ( V_190 )
return V_190 ;
V_190 = F_90 ( & V_222 ) ;
if ( V_190 ) {
F_91 ( & V_187 ) ;
return V_190 ;
}
return 0 ;
}
static void T_7 F_92 ( void )
{
F_93 ( & V_222 ) ;
F_91 ( & V_187 ) ;
}
