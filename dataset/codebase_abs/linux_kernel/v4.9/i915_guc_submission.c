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
F_13 ( L_1 ,
V_7 [ 0 ] , V_10 , V_3 , F_2 ( F_3 ( 15 ) ) ) ;
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
F_31 ( L_2 ,
V_54 ? L_3 : L_4 , V_60 ) ;
return V_60 ;
}
static T_5 F_32 ( struct V_5 * V_6 )
{
const T_5 V_61 = F_33 () ;
T_5 V_62 ;
V_62 = F_34 ( V_6 -> V_63 ) ;
V_6 -> V_63 += V_61 ;
F_31 ( L_5 ,
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
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_73 * V_74 ;
struct V_75 * V_76 = V_24 -> V_77 ;
struct V_39 V_40 ;
struct V_32 * V_33 ;
unsigned int V_78 ;
T_1 V_79 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_80 = V_81 | V_82 ;
V_40 . V_68 = V_24 -> V_26 ;
V_40 . V_53 = V_24 -> V_53 ;
V_40 . V_50 = V_24 -> V_43 ;
F_37 (engine, dev_priv, client->engines, tmp) {
struct V_83 * V_84 = & V_76 -> V_74 [ V_74 -> V_60 ] ;
T_5 V_85 = V_74 -> V_86 ;
struct V_87 * V_88 = & V_40 . V_88 [ V_85 ] ;
if ( ! V_84 -> V_89 )
break;
V_88 -> V_90 = F_38 ( V_84 -> V_91 ) ;
V_88 -> V_92 =
F_39 ( V_84 -> V_89 ) + V_93 * V_94 ;
V_88 -> V_68 = ( V_24 -> V_26 << V_95 ) |
( V_85 << V_96 ) ;
V_88 -> V_97 = F_39 ( V_84 -> V_98 -> V_99 ) ;
V_88 -> V_100 = V_88 -> V_97 + V_84 -> V_98 -> V_101 - 1 ;
V_88 -> V_102 = V_88 -> V_97 ;
V_88 -> V_103 = 0 ;
V_40 . V_104 |= ( 1 << V_85 ) ;
}
F_31 ( L_6 ,
V_24 -> V_105 , V_40 . V_104 ) ;
F_7 ( V_40 . V_104 == 0 ) ;
V_79 = F_39 ( V_24 -> V_99 ) ;
V_40 . V_106 = F_40 ( V_24 -> V_99 -> V_35 -> V_47 ) +
V_24 -> V_42 ;
V_40 . V_107 = ( V_108 ) V_24 -> V_41 +
V_24 -> V_42 ;
V_40 . V_109 = V_79 + V_24 -> V_42 ;
V_40 . V_110 = V_79 + V_24 -> V_65 ;
V_40 . V_111 = V_79 + V_24 -> V_112 ;
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
struct V_64 * V_40 = V_118 -> V_41 + V_118 -> V_65 ;
T_1 V_121 ;
int V_10 ;
F_43 ( & V_118 -> V_122 ) ;
V_121 = F_44 ( V_118 -> V_123 , V_40 -> V_124 , V_118 -> V_70 ) ;
V_121 -= V_118 -> V_125 ;
if ( F_45 ( V_121 >= V_116 ) ) {
V_118 -> V_125 += V_116 ;
V_10 = 0 ;
} else {
V_118 -> V_126 ++ ;
V_10 = - V_127 ;
}
F_46 ( & V_118 -> V_122 ) ;
return V_10 ;
}
void F_47 ( struct V_114 * V_115 )
{
const T_3 V_116 = sizeof( struct V_117 ) ;
struct V_23 * V_118 = V_115 -> V_119 -> V_6 . V_120 ;
F_48 ( F_49 ( V_118 -> V_125 ) < V_116 ) ;
F_43 ( & V_118 -> V_122 ) ;
V_118 -> V_125 -= V_116 ;
F_46 ( & V_118 -> V_122 ) ;
}
static void F_50 ( struct V_23 * V_118 ,
struct V_114 * V_128 )
{
const T_3 V_116 = sizeof( struct V_117 ) ;
const T_1 V_129 = V_116 / sizeof( T_1 ) - 1 ;
struct V_73 * V_74 = V_128 -> V_74 ;
struct V_64 * V_40 ;
struct V_117 * V_130 ;
void * V_131 ;
T_1 V_121 , V_132 , V_133 , V_134 ;
V_40 = V_118 -> V_41 + V_118 -> V_65 ;
V_121 = F_44 ( V_118 -> V_123 , V_40 -> V_124 , V_118 -> V_70 ) ;
F_48 ( V_121 < V_116 ) ;
V_132 = V_128 -> V_132 ;
F_48 ( V_132 & 7 ) ;
V_132 >>= 3 ;
F_48 ( V_132 > V_135 ) ;
F_51 ( V_116 != 16 ) ;
F_48 ( V_118 -> V_125 < V_116 ) ;
V_133 = V_118 -> V_123 ;
F_48 ( V_133 & ( V_116 - 1 ) ) ;
V_118 -> V_123 += V_116 ;
V_118 -> V_123 &= V_118 -> V_70 - 1 ;
V_118 -> V_125 -= V_116 ;
V_134 = ( V_133 + V_136 ) >> V_137 ;
V_133 &= V_94 - 1 ;
V_131 = F_52 ( F_53 ( V_118 -> V_99 -> V_138 , V_134 ) ) ;
V_130 = (struct V_117 * ) ( ( char * ) V_131 + V_133 ) ;
V_130 -> V_139 = V_140 |
( V_129 << V_141 ) |
( V_74 -> V_86 << V_142 ) |
V_143 ;
V_130 -> V_90 = ( T_1 ) F_54 ( V_128 -> V_76 , V_74 ) ;
V_130 -> V_144 = V_132 << V_145 ;
V_130 -> V_146 = V_128 -> V_147 . V_148 ;
F_55 ( V_131 ) ;
}
static int F_56 ( struct V_23 * V_118 )
{
struct V_64 * V_40 ;
union V_149 V_150 , V_151 , V_152 ;
union V_149 * V_153 ;
int V_154 = 2 , V_10 = - V_127 ;
V_40 = V_118 -> V_41 + V_118 -> V_65 ;
V_40 -> V_132 = V_118 -> V_123 ;
V_150 . V_45 = V_52 ;
V_150 . V_51 = V_118 -> V_51 ;
V_151 . V_45 = V_52 ;
V_151 . V_51 = V_118 -> V_51 + 1 ;
if ( V_151 . V_51 == 0 )
V_151 . V_51 = 1 ;
V_153 = V_118 -> V_41 + V_118 -> V_42 ;
while ( V_154 -- ) {
V_152 . V_155 = F_57 ( ( V_156 * ) V_153 ,
V_150 . V_155 , V_151 . V_155 ) ;
if ( V_152 . V_155 == V_150 . V_155 ) {
V_118 -> V_51 = V_151 . V_51 ;
V_10 = 0 ;
break;
}
if ( V_152 . V_45 == V_46 )
break;
F_13 ( L_7 ,
V_150 . V_51 , V_152 . V_51 ) ;
V_150 . V_51 = V_152 . V_51 ;
V_151 . V_51 = V_152 . V_51 + 1 ;
if ( V_151 . V_51 == 0 )
V_151 . V_51 = 1 ;
}
return V_10 ;
}
static void F_58 ( struct V_114 * V_128 )
{
unsigned int V_157 = V_128 -> V_74 -> V_60 ;
struct V_5 * V_6 = & V_128 -> V_119 -> V_6 ;
struct V_23 * V_24 = V_6 -> V_120 ;
int V_158 ;
F_43 ( & V_24 -> V_122 ) ;
F_50 ( V_24 , V_128 ) ;
V_158 = F_56 ( V_24 ) ;
V_24 -> V_159 [ V_157 ] += 1 ;
V_24 -> V_160 = V_158 ;
if ( V_158 )
V_24 -> V_161 += 1 ;
V_6 -> V_159 [ V_157 ] += 1 ;
V_6 -> V_162 [ V_157 ] = V_128 -> V_147 . V_148 ;
F_46 ( & V_24 -> V_122 ) ;
}
static struct V_163 * F_59 ( struct V_5 * V_6 , T_1 V_101 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_164 * V_138 ;
struct V_163 * V_99 ;
int V_10 ;
V_138 = F_60 ( & V_2 -> V_165 , V_101 ) ;
if ( F_61 ( V_138 ) )
return F_62 ( V_138 ) ;
V_99 = F_63 ( V_138 , & V_2 -> V_166 . V_131 , NULL ) ;
if ( F_61 ( V_99 ) )
goto V_167;
V_10 = F_64 ( V_99 , 0 , V_94 ,
V_168 | V_169 | V_170 ) ;
if ( V_10 ) {
V_99 = F_65 ( V_10 ) ;
goto V_167;
}
F_9 ( V_171 , V_172 ) ;
return V_99 ;
V_167:
F_66 ( V_138 ) ;
return V_99 ;
}
static void
F_67 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_24 )
return;
if ( V_24 -> V_41 ) {
F_28 ( V_6 , V_24 ) ;
F_68 ( F_69 ( V_24 -> V_41 ) ) ;
}
F_70 ( & V_24 -> V_99 ) ;
if ( V_24 -> V_26 != V_173 ) {
F_41 ( V_6 , V_24 ) ;
F_71 ( & V_6 -> V_174 , V_24 -> V_26 ) ;
}
F_72 ( V_24 ) ;
}
static bool F_73 ( struct V_5 * V_6 , T_4 V_50 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
T_6 V_175 = F_74 ( V_50 ) ;
T_5 V_176 = F_2 ( V_175 ) ;
bool V_177 = ( V_176 & V_52 ) != 0 ;
bool V_178 = F_22 ( V_50 , V_6 -> V_36 ) ;
if ( V_177 == V_178 )
return true ;
F_31 ( L_8 ,
V_50 , V_175 . V_179 , V_176 ,
V_178 ? L_9 : L_10 ) ;
return false ;
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_23 * V_24 = V_6 -> V_120 ;
T_4 V_50 ;
int V_9 , V_167 ;
V_50 = V_24 -> V_43 ;
for ( V_9 = 0 ; V_9 < V_57 ; ++ V_9 ) {
if ( F_73 ( V_6 , V_9 ) )
continue;
V_167 = F_21 ( V_6 , V_24 , V_9 ) ;
if ( V_167 )
F_31 ( L_11 ,
V_9 , V_167 ) ;
}
V_167 = F_21 ( V_6 , V_24 , V_50 ) ;
if ( V_167 )
F_13 ( L_12 ,
V_50 , V_167 ) ;
for ( V_9 = 0 ; V_9 < V_57 ; ++ V_9 )
( void ) F_73 ( V_6 , V_9 ) ;
}
static struct V_23 *
F_76 ( struct V_1 * V_2 ,
T_5 V_105 ,
T_5 V_53 ,
struct V_75 * V_76 )
{
struct V_23 * V_24 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_163 * V_99 ;
T_4 V_50 ;
V_24 = F_77 ( sizeof( * V_24 ) , V_180 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_77 = V_76 ;
V_24 -> V_6 = V_6 ;
V_24 -> V_105 = V_105 ;
V_24 -> V_53 = V_53 ;
V_24 -> V_43 = V_44 ;
V_24 -> V_26 = ( T_5 ) F_78 ( & V_6 -> V_174 , 0 ,
V_181 , V_180 ) ;
if ( V_24 -> V_26 >= V_181 ) {
V_24 -> V_26 = V_173 ;
goto V_167;
}
V_99 = F_59 ( V_6 , V_136 + V_182 ) ;
if ( F_61 ( V_99 ) )
goto V_167;
V_24 -> V_99 = V_99 ;
V_24 -> V_41 = F_79 ( F_80 ( V_99 ) ) ;
F_81 ( & V_24 -> V_122 ) ;
V_24 -> V_112 = V_136 ;
V_24 -> V_70 = V_182 ;
V_50 = F_29 ( V_6 , V_24 -> V_53 ) ;
if ( V_50 == V_44 )
goto V_167;
V_24 -> V_42 = F_32 ( V_6 ) ;
if ( V_24 -> V_42 >= ( V_136 / 2 ) )
V_24 -> V_65 = 0 ;
else
V_24 -> V_65 = ( V_136 / 2 ) ;
F_35 ( V_6 , V_24 ) ;
F_36 ( V_6 , V_24 ) ;
if ( F_27 ( V_6 , V_24 , V_50 ) )
goto V_167;
F_31 ( L_13 ,
V_53 , V_24 , V_24 -> V_105 , V_24 -> V_26 ) ;
F_31 ( L_14 ,
V_24 -> V_43 , V_24 -> V_42 ) ;
return V_24 ;
V_167:
F_67 ( V_2 , V_24 ) ;
return NULL ;
}
static void F_82 ( struct V_5 * V_6 )
{
struct V_163 * V_99 ;
unsigned long V_62 ;
T_5 V_101 , V_183 ;
if ( V_119 . V_184 < V_185 )
return;
if ( V_119 . V_184 > V_186 )
V_119 . V_184 = V_186 ;
V_101 = ( 1 + V_187 + 1 +
V_188 + 1 +
V_189 + 1 ) << V_137 ;
V_99 = V_6 -> V_190 ;
if ( ! V_99 ) {
V_99 = F_59 ( V_6 , V_101 ) ;
if ( F_61 ( V_99 ) ) {
V_119 . V_184 = - 1 ;
return;
}
V_6 -> V_190 = V_99 ;
}
V_183 = V_191 | V_192 |
( V_187 << V_193 ) |
( V_188 << V_194 ) |
( V_189 << V_195 ) ;
V_62 = F_39 ( V_99 ) >> V_137 ;
V_6 -> V_196 = ( V_62 << V_197 ) | V_183 ;
}
static void F_83 ( struct V_198 * V_199 )
{
struct V_200 * V_201 ;
T_1 V_202 , V_9 ;
V_199 -> V_203 = 500000 ;
V_199 -> V_204 = V_205 ;
for ( V_202 = 0 ; V_202 < V_206 ; V_202 ++ ) {
for ( V_9 = V_207 ; V_9 < V_208 ; V_9 ++ ) {
V_201 = & V_199 -> V_201 [ V_202 ] [ V_9 ] ;
V_201 -> V_209 = 1000000 ;
V_201 -> V_210 = 500000 ;
V_201 -> V_211 = 250000 ;
V_201 -> V_212 = 0 ;
}
}
V_199 -> V_213 = 1 ;
}
static void F_84 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_163 * V_99 ;
struct V_214 * V_215 ;
struct V_198 * V_199 ;
struct V_216 * V_217 ;
struct V_73 * V_74 ;
struct V_218 * V_218 ;
T_1 V_101 ;
V_101 = sizeof( struct V_214 ) + sizeof( struct V_198 ) +
sizeof( struct V_216 ) +
V_219 * V_94 ;
V_99 = V_6 -> V_220 ;
if ( ! V_99 ) {
V_99 = F_59 ( V_6 , F_85 ( V_101 ) ) ;
if ( F_61 ( V_99 ) )
return;
V_6 -> V_220 = V_99 ;
}
V_218 = F_80 ( V_99 ) ;
V_215 = F_79 ( V_218 ) ;
V_74 = & V_2 -> V_74 [ V_221 ] ;
V_215 -> V_222 = V_74 -> V_223 . V_224 ;
F_86 (engine, dev_priv)
V_215 -> V_225 [ V_74 -> V_86 ] = F_87 ( V_74 ) ;
V_199 = ( void * ) V_215 + sizeof( struct V_214 ) ;
F_83 ( V_199 ) ;
V_215 -> V_226 =
F_39 ( V_99 ) + sizeof( struct V_214 ) ;
V_217 = ( void * ) V_199 + sizeof( struct V_198 ) ;
F_86 (engine, dev_priv) {
V_217 -> V_227 [ V_74 -> V_86 ] . V_228 =
V_74 -> V_229 + V_230 ;
V_217 -> V_227 [ V_74 -> V_86 ] . V_231 = 0 ;
}
V_215 -> V_232 = V_215 -> V_226 +
sizeof( struct V_198 ) ;
V_215 -> V_233 = V_215 -> V_232 +
sizeof( struct V_216 ) ;
F_68 ( V_218 ) ;
}
int F_88 ( struct V_1 * V_2 )
{
const T_3 V_234 = sizeof( struct V_39 ) ;
const T_3 V_235 = V_181 * V_234 ;
const T_3 V_236 = F_89 ( V_235 , V_94 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_163 * V_99 ;
F_90 ( V_6 -> V_36 , 0 , V_57 ) ;
F_91 ( V_2 ) ;
if ( ! V_119 . V_237 )
return 0 ;
if ( V_6 -> V_34 )
return 0 ;
V_99 = F_59 ( V_6 , V_236 ) ;
if ( F_61 ( V_99 ) )
return F_92 ( V_99 ) ;
V_6 -> V_34 = V_99 ;
F_93 ( & V_6 -> V_174 ) ;
F_82 ( V_6 ) ;
F_84 ( V_6 ) ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_23 * V_24 ;
struct V_73 * V_74 ;
struct V_114 * V_115 ;
V_24 = F_76 ( V_2 ,
F_95 ( V_2 ) -> V_238 ,
V_239 ,
V_2 -> V_240 ) ;
if ( ! V_24 ) {
F_96 ( L_15 ) ;
return - V_241 ;
}
V_6 -> V_120 = V_24 ;
F_17 ( V_6 , V_24 ) ;
F_75 ( V_6 ) ;
F_86 (engine, dev_priv) {
V_74 -> V_242 = F_58 ;
F_97 (request, &engine->request_list, link) {
V_24 -> V_125 += sizeof( struct V_117 ) ;
if ( F_98 ( & V_115 -> V_243 ) )
F_58 ( V_115 ) ;
}
}
return 0 ;
}
void F_91 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_6 -> V_120 )
return;
F_99 ( V_2 ) ;
F_67 ( V_2 , V_6 -> V_120 ) ;
V_6 -> V_120 = NULL ;
}
void F_100 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_70 ( & V_6 -> V_220 ) ;
F_70 ( & V_6 -> V_190 ) ;
if ( V_6 -> V_34 )
F_101 ( & V_6 -> V_174 ) ;
F_70 ( & V_6 -> V_34 ) ;
}
int F_102 ( struct V_244 * V_245 )
{
struct V_1 * V_2 = F_103 ( V_245 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_75 * V_76 ;
T_1 V_7 [ 3 ] ;
if ( V_6 -> V_246 . V_247 != V_248 )
return 0 ;
V_76 = V_2 -> V_240 ;
V_7 [ 0 ] = V_249 ;
V_7 [ 1 ] = V_250 ;
V_7 [ 2 ] = F_39 ( V_76 -> V_74 [ V_221 ] . V_89 ) ;
return F_5 ( V_6 , V_7 , F_20 ( V_7 ) ) ;
}
int F_104 ( struct V_244 * V_245 )
{
struct V_1 * V_2 = F_103 ( V_245 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_75 * V_76 ;
T_1 V_7 [ 3 ] ;
if ( V_6 -> V_246 . V_247 != V_248 )
return 0 ;
V_76 = V_2 -> V_240 ;
V_7 [ 0 ] = V_251 ;
V_7 [ 1 ] = V_252 ;
V_7 [ 2 ] = F_39 ( V_76 -> V_74 [ V_221 ] . V_89 ) ;
return F_5 ( V_6 , V_7 , F_20 ( V_7 ) ) ;
}
