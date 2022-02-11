static inline bool F_1 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
T_1 V_4 = F_2 ( F_3 ( 0 ) ) ;
* V_3 = V_4 ;
return F_4 ( V_4 ) ;
}
static int F_5 ( struct V_5 * V_6 , T_1 * V_7 , T_1 V_8 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
T_1 V_3 ;
int V_9 ;
int V_10 ;
if ( F_7 ( V_8 < 1 || V_8 > 15 ) )
return - V_11 ;
F_8 ( V_2 , V_12 ) ;
V_2 -> V_6 . V_13 += 1 ;
V_2 -> V_6 . V_14 = V_7 [ 0 ] ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
F_9 ( F_3 ( V_9 ) , V_7 [ V_9 ] ) ;
F_10 ( F_3 ( V_9 - 1 ) ) ;
F_9 ( V_15 , V_16 ) ;
V_10 = F_11 ( F_1 ( V_2 , & V_3 ) , 10 ) ;
if ( V_10 )
V_10 = F_12 ( F_1 ( V_2 , & V_3 ) , 10 ) ;
if ( V_3 != V_17 ) {
if ( V_10 != - V_18 )
V_10 = - V_19 ;
F_13 ( L_1
L_2 ,
V_7 [ 0 ] , V_10 , V_3 ,
F_2 ( F_3 ( 15 ) ) ) ;
V_2 -> V_6 . V_20 += 1 ;
V_2 -> V_6 . V_21 = V_10 ;
}
V_2 -> V_6 . V_22 = V_3 ;
F_14 ( V_2 , V_12 ) ;
return V_10 ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_25 ;
V_7 [ 1 ] = V_24 -> V_26 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_27 ;
V_7 [ 1 ] = V_24 -> V_26 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_28 ;
if ( ! F_18 () || F_19 ( V_2 ) )
V_7 [ 1 ] = 0 ;
else
V_7 [ 1 ] = V_29 | V_30 ;
return F_5 ( V_6 , V_7 , F_20 ( V_7 ) ) ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_23 * V_24 ,
T_2 V_31 )
{
struct V_32 * V_33 = V_6 -> V_34 -> V_35 ;
void * V_36 = V_6 -> V_36 ;
struct V_37 * V_38 ;
struct V_39 V_40 ;
T_3 V_8 ;
V_38 = V_24 -> V_41 + V_24 -> V_42 ;
if ( V_24 -> V_43 != V_44 &&
F_22 ( V_24 -> V_43 , V_36 ) ) {
V_38 -> V_45 = V_46 ;
( void ) F_16 ( V_6 , V_24 ) ;
F_23 ( V_24 -> V_43 , V_36 ) ;
}
V_8 = F_24 ( V_33 -> V_47 , V_33 -> V_48 , & V_40 , sizeof( V_40 ) ,
sizeof( V_40 ) * V_24 -> V_26 ) ;
if ( V_8 != sizeof( V_40 ) )
return - V_49 ;
V_40 . V_50 = V_31 ;
V_8 = F_25 ( V_33 -> V_47 , V_33 -> V_48 , & V_40 , sizeof( V_40 ) ,
sizeof( V_40 ) * V_24 -> V_26 ) ;
if ( V_8 != sizeof( V_40 ) )
return - V_49 ;
V_24 -> V_43 = V_31 ;
if ( V_31 == V_44 )
return 0 ;
F_26 ( V_31 , V_36 ) ;
V_38 -> V_51 = 0 ;
V_38 -> V_45 = V_52 ;
return F_15 ( V_6 , V_24 ) ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_23 * V_24 ,
T_4 V_50 )
{
return F_21 ( V_6 , V_24 , V_50 ) ;
}
static void F_28 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
( void ) F_21 ( V_6 , V_24 , V_44 ) ;
}
static T_4
F_29 ( struct V_5 * V_6 , T_5 V_53 )
{
const bool V_54 = ( V_53 <= V_55 ) ;
const T_4 V_56 = V_57 / 2 ;
const T_4 V_58 = V_54 ? V_56 : 0 ;
const T_4 V_59 = V_58 + V_56 ;
T_4 V_60 ;
V_60 = F_30 ( V_6 -> V_36 , V_59 , V_58 ) ;
if ( V_60 == V_59 )
V_60 = V_44 ;
F_31 ( L_3 ,
V_54 ? L_4 : L_5 , V_60 ) ;
return V_60 ;
}
static T_5 F_32 ( struct V_5 * V_6 )
{
const T_5 V_61 = F_33 () ;
T_5 V_62 ;
V_62 = F_34 ( V_6 -> V_63 ) ;
V_6 -> V_63 += V_61 ;
F_31 ( L_6 ,
V_62 , V_6 -> V_63 , V_61 ) ;
return V_62 ;
}
static void F_35 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_64 * V_40 ;
V_40 = V_24 -> V_41 + V_24 -> V_65 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_40 -> V_66 = 0 ;
V_40 -> V_67 = 0 ;
V_40 -> V_68 = V_24 -> V_26 ;
V_40 -> V_69 = V_24 -> V_70 ;
V_40 -> V_71 = V_72 ;
V_40 -> V_53 = V_24 -> V_53 ;
}
static void F_36 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_73 * V_74 = V_24 -> V_74 ;
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_75 * V_76 ;
struct V_77 * V_78 = V_24 -> V_79 ;
struct V_39 V_40 ;
struct V_32 * V_33 ;
T_1 V_80 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_81 = V_82 | V_83 ;
V_40 . V_68 = V_24 -> V_26 ;
V_40 . V_53 = V_24 -> V_53 ;
V_40 . V_50 = V_24 -> V_43 ;
F_37 (engine, dev_priv) {
struct V_84 * V_85 = & V_78 -> V_76 [ V_76 -> V_60 ] ;
struct V_86 * V_87 = & V_40 . V_87 [ V_76 -> V_88 ] ;
struct V_73 * V_89 ;
if ( ! V_85 -> V_90 )
break;
V_87 -> V_91 = F_38 ( V_85 -> V_92 ) ;
V_80 = F_39 ( V_85 -> V_90 ) ;
V_87 -> V_93 = V_80 + V_94 * V_95 ;
V_87 -> V_68 = ( V_24 -> V_26 << V_96 ) |
( V_76 -> V_88 << V_97 ) ;
V_89 = V_85 -> V_98 -> V_89 ;
V_80 = F_39 ( V_89 ) ;
V_87 -> V_99 = V_80 ;
V_87 -> V_100 = V_80 + V_89 -> V_101 . V_102 - 1 ;
V_87 -> V_103 = V_80 ;
V_87 -> V_104 = 0 ;
V_40 . V_105 |= ( 1 << V_76 -> V_88 ) ;
}
F_7 ( V_40 . V_105 == 0 ) ;
V_80 = F_39 ( V_74 ) ;
V_40 . V_106 = F_40 ( V_74 -> V_35 -> V_47 ) +
V_24 -> V_42 ;
V_40 . V_107 = ( V_108 ) V_24 -> V_41 +
V_24 -> V_42 ;
V_40 . V_109 = V_80 + V_24 -> V_42 ;
V_40 . V_110 = V_80 + V_24 -> V_65 ;
V_40 . V_111 = V_80 + V_24 -> V_112 ;
V_40 . V_70 = V_24 -> V_70 ;
V_40 . V_113 = ( V_108 ) V_24 ;
V_33 = V_6 -> V_34 -> V_35 ;
F_25 ( V_33 -> V_47 , V_33 -> V_48 , & V_40 , sizeof( V_40 ) ,
sizeof( V_40 ) * V_24 -> V_26 ) ;
}
static void F_41 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_39 V_40 ;
struct V_32 * V_33 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_33 = V_6 -> V_34 -> V_35 ;
F_25 ( V_33 -> V_47 , V_33 -> V_48 , & V_40 , sizeof( V_40 ) ,
sizeof( V_40 ) * V_24 -> V_26 ) ;
}
int F_42 ( struct V_114 * V_115 )
{
const T_3 V_116 = sizeof( struct V_117 ) ;
struct V_23 * V_118 = V_115 -> V_119 -> V_6 . V_120 ;
struct V_64 * V_40 ;
T_1 V_121 ;
F_43 ( V_118 == NULL ) ;
V_40 = V_118 -> V_41 + V_118 -> V_65 ;
V_121 = F_44 ( V_118 -> V_122 , V_40 -> V_123 , V_118 -> V_70 ) ;
if ( F_45 ( V_121 >= V_116 ) )
return 0 ;
V_118 -> V_124 += 1 ;
return - V_125 ;
}
static void F_46 ( struct V_23 * V_118 ,
struct V_114 * V_126 )
{
const T_3 V_116 = sizeof( struct V_117 ) ;
const T_1 V_127 = V_116 / sizeof( T_1 ) - 1 ;
struct V_64 * V_40 ;
struct V_117 * V_128 ;
void * V_101 ;
T_1 V_121 , V_129 , V_130 , V_131 ;
V_40 = V_118 -> V_41 + V_118 -> V_65 ;
V_121 = F_44 ( V_118 -> V_122 , V_40 -> V_123 , V_118 -> V_70 ) ;
F_43 ( V_121 < V_116 ) ;
V_129 = V_126 -> V_129 ;
F_43 ( V_129 & 7 ) ;
V_129 >>= 3 ;
F_43 ( V_129 > V_132 ) ;
F_47 ( V_116 != 16 ) ;
V_130 = V_118 -> V_122 ;
V_118 -> V_122 += V_116 ;
V_118 -> V_122 &= V_118 -> V_70 - 1 ;
F_43 ( V_130 & ( V_116 - 1 ) ) ;
V_131 = ( V_130 + V_133 ) >> V_134 ;
V_130 &= V_95 - 1 ;
V_101 = F_48 ( F_49 ( V_118 -> V_74 , V_131 ) ) ;
V_128 = (struct V_117 * ) ( ( char * ) V_101 + V_130 ) ;
V_128 -> V_135 = V_136 |
( V_127 << V_137 ) |
( V_126 -> V_76 -> V_88 << V_138 ) |
V_139 ;
V_128 -> V_91 = ( T_1 ) F_50 ( V_126 -> V_78 ,
V_126 -> V_76 ) ;
V_128 -> V_140 = V_129 << V_141 ;
V_128 -> V_142 = V_126 -> V_143 ;
F_51 ( V_101 ) ;
}
static int F_52 ( struct V_23 * V_118 )
{
struct V_64 * V_40 ;
union V_144 V_145 , V_146 , V_147 ;
union V_144 * V_148 ;
int V_149 = 2 , V_10 = - V_125 ;
V_40 = V_118 -> V_41 + V_118 -> V_65 ;
V_40 -> V_129 = V_118 -> V_122 ;
V_145 . V_45 = V_52 ;
V_145 . V_51 = V_118 -> V_51 ;
V_146 . V_45 = V_52 ;
V_146 . V_51 = V_118 -> V_51 + 1 ;
if ( V_146 . V_51 == 0 )
V_146 . V_51 = 1 ;
V_148 = V_118 -> V_41 + V_118 -> V_42 ;
while ( V_149 -- ) {
V_147 . V_150 = F_53 ( ( V_151 * ) V_148 ,
V_145 . V_150 , V_146 . V_150 ) ;
if ( V_147 . V_150 == V_145 . V_150 ) {
V_118 -> V_51 = V_146 . V_51 ;
V_10 = 0 ;
break;
}
if ( V_147 . V_45 == V_46 )
break;
F_13 ( L_7 ,
V_145 . V_51 , V_147 . V_51 ) ;
V_145 . V_51 = V_147 . V_51 ;
V_146 . V_51 = V_147 . V_51 + 1 ;
if ( V_146 . V_51 == 0 )
V_146 . V_51 = 1 ;
}
return V_10 ;
}
int F_54 ( struct V_114 * V_126 )
{
unsigned int V_152 = V_126 -> V_76 -> V_60 ;
struct V_5 * V_6 = & V_126 -> V_119 -> V_6 ;
struct V_23 * V_24 = V_6 -> V_120 ;
int V_153 ;
F_46 ( V_24 , V_126 ) ;
V_153 = F_52 ( V_24 ) ;
V_24 -> V_154 [ V_152 ] += 1 ;
V_24 -> V_155 = V_153 ;
if ( V_153 )
V_24 -> V_156 += 1 ;
V_6 -> V_154 [ V_152 ] += 1 ;
V_6 -> V_157 [ V_152 ] = V_126 -> V_143 ;
return V_153 ;
}
static struct V_73 *
F_55 ( struct V_1 * V_2 , T_1 V_102 )
{
struct V_73 * V_89 ;
V_89 = F_56 ( & V_2 -> V_158 , V_102 ) ;
if ( F_57 ( V_89 ) )
return NULL ;
if ( F_58 ( V_89 ) ) {
F_59 ( & V_89 -> V_101 ) ;
return NULL ;
}
if ( F_60 ( V_89 , V_95 ,
V_159 | V_160 ) ) {
F_59 ( & V_89 -> V_101 ) ;
return NULL ;
}
F_9 ( V_161 , V_162 ) ;
return V_89 ;
}
static void F_61 ( struct V_73 * V_89 )
{
if ( ! V_89 )
return;
if ( F_62 ( V_89 ) )
F_63 ( V_89 ) ;
F_59 ( & V_89 -> V_101 ) ;
}
static void
F_64 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_24 )
return;
if ( V_24 -> V_41 ) {
F_28 ( V_6 , V_24 ) ;
F_65 ( F_66 ( V_24 -> V_41 ) ) ;
}
F_61 ( V_24 -> V_74 ) ;
if ( V_24 -> V_26 != V_163 ) {
F_41 ( V_6 , V_24 ) ;
F_67 ( & V_6 -> V_164 , V_24 -> V_26 ) ;
}
F_68 ( V_24 ) ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_23 * V_24 = V_6 -> V_120 ;
T_4 V_50 , V_9 ;
int V_165 ;
V_50 = V_24 -> V_43 ;
for ( V_9 = 0 ; V_9 < V_57 ; ++ V_9 ) {
T_6 V_166 = F_70 ( V_9 ) ;
T_1 V_167 = F_2 ( V_166 ) ;
V_165 = F_21 ( V_6 , V_24 , V_9 ) ;
if ( V_165 || ( V_9 != V_50 && ( V_167 & V_52 ) ) )
F_31 ( L_8 ,
V_9 , V_166 . V_168 , V_167 , V_165 ) ;
}
V_165 = F_21 ( V_6 , V_24 , V_50 ) ;
if ( V_165 )
F_13 ( L_9 ,
V_50 , V_165 ) ;
for ( V_9 = 0 ; V_9 < V_57 ; ++ V_9 ) {
T_6 V_166 = F_70 ( V_9 ) ;
T_1 V_167 = F_2 ( V_166 ) ;
if ( V_9 != V_50 && ( V_167 & V_52 ) )
F_31 ( L_10 ,
V_9 , V_166 . V_168 , V_167 ) ;
}
}
static struct V_23 *
F_71 ( struct V_1 * V_2 ,
T_5 V_53 ,
struct V_77 * V_78 )
{
struct V_23 * V_24 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_73 * V_89 ;
T_4 V_50 ;
V_24 = F_72 ( sizeof( * V_24 ) , V_169 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_43 = V_44 ;
V_24 -> V_53 = V_53 ;
V_24 -> V_79 = V_78 ;
V_24 -> V_6 = V_6 ;
V_24 -> V_26 = ( T_5 ) F_73 ( & V_6 -> V_164 , 0 ,
V_170 , V_169 ) ;
if ( V_24 -> V_26 >= V_170 ) {
V_24 -> V_26 = V_163 ;
goto V_165;
}
V_89 = F_55 ( V_2 , V_133 + V_171 ) ;
if ( ! V_89 )
goto V_165;
V_24 -> V_74 = V_89 ;
V_24 -> V_41 = F_74 ( F_49 ( V_89 , 0 ) ) ;
V_24 -> V_112 = V_133 ;
V_24 -> V_70 = V_171 ;
V_50 = F_29 ( V_6 , V_24 -> V_53 ) ;
if ( V_50 == V_44 )
goto V_165;
V_24 -> V_42 = F_32 ( V_6 ) ;
if ( V_24 -> V_42 >= ( V_133 / 2 ) )
V_24 -> V_65 = 0 ;
else
V_24 -> V_65 = ( V_133 / 2 ) ;
F_35 ( V_6 , V_24 ) ;
F_36 ( V_6 , V_24 ) ;
if ( F_27 ( V_6 , V_24 , V_50 ) )
goto V_165;
F_31 ( L_11 ,
V_53 , V_24 , V_24 -> V_26 ) ;
F_31 ( L_12 ,
V_24 -> V_43 , V_24 -> V_42 ) ;
return V_24 ;
V_165:
F_13 ( L_13 , V_53 ) ;
F_64 ( V_2 , V_24 ) ;
return NULL ;
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_73 * V_89 ;
unsigned long V_62 ;
T_5 V_102 , V_172 ;
if ( V_119 . V_173 < V_174 )
return;
if ( V_119 . V_173 > V_175 )
V_119 . V_173 = V_175 ;
V_102 = ( 1 + V_176 + 1 +
V_177 + 1 +
V_178 + 1 ) << V_134 ;
V_89 = V_6 -> V_179 ;
if ( ! V_89 ) {
V_89 = F_55 ( V_2 , V_102 ) ;
if ( ! V_89 ) {
V_119 . V_173 = - 1 ;
return;
}
V_6 -> V_179 = V_89 ;
}
V_172 = V_180 | V_181 |
( V_176 << V_182 ) |
( V_177 << V_183 ) |
( V_178 << V_184 ) ;
V_62 = F_39 ( V_89 ) >> V_134 ;
V_6 -> V_185 = ( V_62 << V_186 ) | V_172 ;
}
static void F_76 ( struct V_187 * V_188 )
{
struct V_189 * V_190 ;
T_1 V_191 , V_9 ;
V_188 -> V_192 = 500000 ;
V_188 -> V_193 = V_194 ;
for ( V_191 = 0 ; V_191 < V_195 ; V_191 ++ ) {
for ( V_9 = V_196 ; V_9 < V_197 ; V_9 ++ ) {
V_190 = & V_188 -> V_190 [ V_191 ] [ V_9 ] ;
V_190 -> V_198 = 1000000 ;
V_190 -> V_199 = 500000 ;
V_190 -> V_200 = 250000 ;
V_190 -> V_201 = 0 ;
}
}
V_188 -> V_202 = 1 ;
}
static void F_77 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_73 * V_89 ;
struct V_203 * V_204 ;
struct V_187 * V_188 ;
struct V_205 * V_206 ;
struct V_75 * V_76 ;
struct V_207 * V_207 ;
T_1 V_102 ;
V_102 = sizeof( struct V_203 ) + sizeof( struct V_187 ) +
sizeof( struct V_205 ) +
V_208 * V_95 ;
V_89 = V_6 -> V_209 ;
if ( ! V_89 ) {
V_89 = F_55 ( V_2 , F_78 ( V_102 ) ) ;
if ( ! V_89 )
return;
V_6 -> V_209 = V_89 ;
}
V_207 = F_49 ( V_89 , 0 ) ;
V_204 = F_74 ( V_207 ) ;
V_76 = & V_2 -> V_76 [ V_210 ] ;
V_204 -> V_211 = V_76 -> V_212 . V_80 ;
F_37 (engine, dev_priv)
V_204 -> V_213 [ V_76 -> V_88 ] = F_79 ( V_76 ) ;
V_188 = ( void * ) V_204 + sizeof( struct V_203 ) ;
F_76 ( V_188 ) ;
V_204 -> V_214 = F_39 ( V_89 ) +
sizeof( struct V_203 ) ;
V_206 = ( void * ) V_188 + sizeof( struct V_187 ) ;
F_37 (engine, dev_priv) {
V_206 -> V_215 [ V_76 -> V_88 ] . V_216 =
V_76 -> V_217 + V_218 ;
V_206 -> V_215 [ V_76 -> V_88 ] . V_219 = 0 ;
}
V_204 -> V_220 = V_204 -> V_214 +
sizeof( struct V_187 ) ;
V_204 -> V_221 = V_204 -> V_220 +
sizeof( struct V_205 ) ;
F_65 ( V_207 ) ;
}
int F_80 ( struct V_1 * V_2 )
{
const T_3 V_222 = sizeof( struct V_39 ) ;
const T_3 V_223 = V_170 * V_222 ;
const T_3 V_224 = F_81 ( V_223 , V_95 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_82 ( V_6 -> V_36 , 0 , V_57 ) ;
F_83 ( V_2 ) ;
if ( ! V_119 . V_225 )
return 0 ;
if ( V_6 -> V_34 )
return 0 ;
V_6 -> V_34 = F_55 ( V_2 , V_224 ) ;
if ( ! V_6 -> V_34 )
return - V_226 ;
F_84 ( & V_6 -> V_164 ) ;
F_75 ( V_6 ) ;
F_77 ( V_6 ) ;
return 0 ;
}
int F_85 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_23 * V_24 ;
V_24 = F_71 ( V_2 ,
V_227 ,
V_2 -> V_228 ) ;
if ( ! V_24 ) {
F_13 ( L_14 ) ;
return - V_226 ;
}
V_6 -> V_120 = V_24 ;
F_17 ( V_6 , V_24 ) ;
F_69 ( V_6 ) ;
return 0 ;
}
void F_83 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_64 ( V_2 , V_6 -> V_120 ) ;
V_6 -> V_120 = NULL ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_61 ( V_2 -> V_6 . V_209 ) ;
V_6 -> V_209 = NULL ;
F_61 ( V_2 -> V_6 . V_179 ) ;
V_6 -> V_179 = NULL ;
if ( V_6 -> V_34 )
F_87 ( & V_6 -> V_164 ) ;
F_61 ( V_6 -> V_34 ) ;
V_6 -> V_34 = NULL ;
}
int F_88 ( struct V_229 * V_230 )
{
struct V_1 * V_2 = F_89 ( V_230 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_77 * V_78 ;
T_1 V_7 [ 3 ] ;
if ( V_6 -> V_231 . V_232 != V_233 )
return 0 ;
V_78 = V_2 -> V_228 ;
V_7 [ 0 ] = V_234 ;
V_7 [ 1 ] = V_235 ;
V_7 [ 2 ] = F_39 ( V_78 -> V_76 [ V_210 ] . V_90 ) ;
return F_5 ( V_6 , V_7 , F_20 ( V_7 ) ) ;
}
int F_90 ( struct V_229 * V_230 )
{
struct V_1 * V_2 = F_89 ( V_230 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_77 * V_78 ;
T_1 V_7 [ 3 ] ;
if ( V_6 -> V_231 . V_232 != V_233 )
return 0 ;
V_78 = V_2 -> V_228 ;
V_7 [ 0 ] = V_236 ;
V_7 [ 1 ] = V_237 ;
V_7 [ 2 ] = F_39 ( V_78 -> V_76 [ V_210 ] . V_90 ) ;
return F_5 ( V_6 , V_7 , F_20 ( V_7 ) ) ;
}
