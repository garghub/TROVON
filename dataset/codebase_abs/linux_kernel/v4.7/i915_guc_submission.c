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
if ( V_3 != V_17 ) {
if ( V_10 != - V_18 )
V_10 = - V_19 ;
F_12 ( L_1
L_2 ,
V_7 [ 0 ] , V_10 , V_3 ,
F_2 ( F_3 ( 15 ) ) ) ;
V_2 -> V_6 . V_20 += 1 ;
V_2 -> V_6 . V_21 = V_10 ;
}
V_2 -> V_6 . V_22 = V_3 ;
F_13 ( V_2 , V_12 ) ;
return V_10 ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_25 ;
V_7 [ 1 ] = V_24 -> V_26 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_27 ;
V_7 [ 1 ] = V_24 -> V_26 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_30 ;
if ( ! F_17 ( V_29 ) ||
F_18 ( V_29 ) )
V_7 [ 1 ] = 0 ;
else
V_7 [ 1 ] = V_31 | V_32 ;
return F_5 ( V_6 , V_7 , F_19 ( V_7 ) ) ;
}
static void F_20 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_33 * V_34 ;
V_34 = V_24 -> V_35 + V_24 -> V_36 ;
V_34 -> V_37 = V_38 ;
V_34 -> V_39 = 0 ;
}
static int F_21 ( struct V_23 * V_40 )
{
struct V_41 * V_42 ;
union V_43 V_44 , V_45 , V_46 ;
union V_43 * V_47 ;
int V_48 = 2 , V_10 = - V_49 ;
V_42 = V_40 -> V_35 + V_40 -> V_50 ;
V_42 -> V_51 = V_40 -> V_52 ;
V_44 . V_37 = V_38 ;
V_44 . V_39 = V_40 -> V_39 ;
V_45 . V_37 = V_38 ;
V_45 . V_39 = V_40 -> V_39 + 1 ;
if ( V_45 . V_39 == 0 )
V_45 . V_39 = 1 ;
V_47 = V_40 -> V_35 + V_40 -> V_36 ;
while ( V_48 -- ) {
V_46 . V_53 = F_22 ( ( V_54 * ) V_47 ,
V_44 . V_53 , V_45 . V_53 ) ;
if ( V_46 . V_53 == V_44 . V_53 ) {
V_40 -> V_39 = V_45 . V_39 ;
V_10 = 0 ;
break;
}
if ( V_46 . V_37 == V_55 )
break;
F_12 ( L_3 ,
V_44 . V_39 , V_46 . V_39 ) ;
V_44 . V_39 = V_46 . V_39 ;
V_45 . V_39 = V_46 . V_39 + 1 ;
if ( V_45 . V_39 == 0 )
V_45 . V_39 = 1 ;
}
return V_10 ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_33 * V_34 ;
T_2 V_56 = F_24 ( V_24 -> V_57 ) ;
int V_58 ;
V_34 = V_24 -> V_35 + V_24 -> V_36 ;
V_34 -> V_37 = V_55 ;
F_9 ( V_56 , F_2 ( V_56 ) & ~ V_59 ) ;
V_58 = F_2 ( V_56 ) ;
F_7 ( ( V_58 & V_59 ) != 0 ) ;
F_9 ( F_25 ( V_24 -> V_57 ) , 0 ) ;
F_9 ( V_56 , 0 ) ;
}
static T_3 F_26 ( struct V_5 * V_6 )
{
const T_3 V_60 = F_27 () ;
T_3 V_61 ;
V_61 = F_28 ( V_6 -> V_62 ) ;
V_6 -> V_62 += V_60 ;
F_29 ( L_4 ,
V_61 , V_6 -> V_62 , V_60 ) ;
return V_61 ;
}
static T_4 F_30 ( struct V_5 * V_6 , T_3 V_63 )
{
const bool V_64 = ( V_63 <= V_65 ) ;
const T_4 V_66 = V_67 / 2 ;
const T_4 V_68 = V_64 ? V_66 : 0 ;
const T_4 V_69 = V_68 + V_66 ;
T_4 V_70 ;
V_70 = F_31 ( V_6 -> V_71 , V_69 , V_68 ) ;
if ( V_70 == V_69 )
V_70 = V_72 ;
else
F_32 ( V_6 -> V_71 , V_70 , 1 ) ;
F_29 ( L_5 ,
V_64 ? L_6 : L_7 , V_70 ) ;
return V_70 ;
}
static void F_33 ( struct V_5 * V_6 , T_4 V_70 )
{
F_34 ( V_6 -> V_71 , V_70 , 1 ) ;
}
static void F_35 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_41 * V_42 ;
V_42 = V_24 -> V_35 + V_24 -> V_50 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_73 = 0 ;
V_42 -> V_74 = 0 ;
V_42 -> V_75 = V_24 -> V_26 ;
V_42 -> V_76 = V_24 -> V_77 ;
V_42 -> V_78 = V_79 ;
V_42 -> V_63 = V_24 -> V_63 ;
}
static void F_36 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_80 * V_81 = V_24 -> V_81 ;
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_82 * V_83 ;
struct V_84 * V_85 = V_24 -> V_86 ;
struct V_87 V_42 ;
struct V_88 * V_89 ;
enum V_90 V_70 ;
T_1 V_91 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_42 . V_92 = V_93 | V_94 ;
V_42 . V_75 = V_24 -> V_26 ;
V_42 . V_63 = V_24 -> V_63 ;
V_42 . V_95 = V_24 -> V_57 ;
F_37 (engine, dev_priv, id) {
struct V_96 * V_97 = & V_42 . V_97 [ V_83 -> V_98 ] ;
struct V_80 * V_99 ;
T_5 V_100 ;
V_99 = V_85 -> V_83 [ V_70 ] . V_101 ;
if ( ! V_99 )
break;
V_100 = F_38 ( V_85 , V_83 ) ;
V_97 -> V_102 = ( T_1 ) V_100 ;
V_91 = F_39 ( V_99 ) ;
V_97 -> V_103 = V_91 + V_104 * V_105 ;
V_97 -> V_75 = ( V_24 -> V_26 << V_106 ) |
( V_83 -> V_98 << V_107 ) ;
V_99 = V_85 -> V_83 [ V_70 ] . V_108 -> V_99 ;
V_91 = F_39 ( V_99 ) ;
V_97 -> V_109 = V_91 ;
V_97 -> V_110 = V_91 + V_99 -> V_111 . V_112 - 1 ;
V_97 -> V_113 = V_91 ;
V_97 -> V_114 = 0 ;
V_42 . V_115 |= ( 1 << V_83 -> V_98 ) ;
}
F_7 ( V_42 . V_115 == 0 ) ;
V_91 = F_39 ( V_81 ) ;
V_42 . V_116 = F_40 ( V_81 -> V_117 -> V_118 ) +
V_24 -> V_36 ;
V_42 . V_119 = ( V_120 ) V_24 -> V_35 +
V_24 -> V_36 ;
V_42 . V_121 = V_91 + V_24 -> V_36 ;
V_42 . V_122 = V_91 + V_24 -> V_50 ;
V_42 . V_123 = V_91 + V_24 -> V_124 ;
V_42 . V_77 = V_24 -> V_77 ;
V_42 . V_125 = ( V_120 ) V_24 ;
V_89 = V_6 -> V_126 -> V_117 ;
F_41 ( V_89 -> V_118 , V_89 -> V_127 , & V_42 , sizeof( V_42 ) ,
sizeof( V_42 ) * V_24 -> V_26 ) ;
}
static void F_42 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_87 V_42 ;
struct V_88 * V_89 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_89 = V_6 -> V_126 -> V_117 ;
F_41 ( V_89 -> V_118 , V_89 -> V_127 , & V_42 , sizeof( V_42 ) ,
sizeof( V_42 ) * V_24 -> V_26 ) ;
}
int F_43 ( struct V_23 * V_40 )
{
struct V_41 * V_42 ;
T_1 V_112 = sizeof( struct V_128 ) ;
int V_10 = - V_18 , V_129 = 200 ;
if ( ! V_40 )
return 0 ;
V_42 = V_40 -> V_35 + V_40 -> V_50 ;
while ( V_129 -- > 0 ) {
if ( F_44 ( V_40 -> V_52 , V_42 -> V_130 , V_40 -> V_77 ) >= V_112 ) {
V_10 = 0 ;
break;
}
if ( V_129 )
F_45 ( 1000 , 2000 ) ;
} ;
return V_10 ;
}
static int F_46 ( struct V_23 * V_40 ,
struct V_131 * V_132 )
{
struct V_41 * V_42 ;
struct V_128 * V_133 ;
void * V_111 ;
T_1 V_51 , V_134 , V_135 , V_136 ;
V_42 = V_40 -> V_35 + V_40 -> V_50 ;
V_136 = F_44 ( V_40 -> V_52 , V_42 -> V_130 , V_40 -> V_77 ) ;
if ( F_7 ( V_136 < sizeof( struct V_128 ) ) )
return - V_137 ;
V_135 = V_40 -> V_52 ;
V_40 -> V_52 += sizeof( struct V_128 ) ;
V_40 -> V_52 &= V_40 -> V_77 - 1 ;
F_7 ( sizeof( struct V_128 ) != 16 ) ;
F_7 ( V_135 & 3 ) ;
V_111 = F_47 ( F_48 ( V_40 -> V_81 ,
( V_135 + V_138 ) >> V_139 ) ) ;
V_135 &= V_105 - 1 ;
V_133 = (struct V_128 * ) ( ( char * ) V_111 + V_135 ) ;
V_134 = sizeof( struct V_128 ) / sizeof( T_1 ) - 1 ;
V_133 -> V_140 = V_141 |
( V_134 << V_142 ) |
( V_132 -> V_83 -> V_98 << V_143 ) |
V_144 ;
V_133 -> V_102 = ( T_1 ) F_38 ( V_132 -> V_85 ,
V_132 -> V_83 ) ;
V_51 = V_132 -> V_108 -> V_51 >> 3 ;
V_133 -> V_145 = V_51 << V_146 ;
V_133 -> V_147 = 0 ;
F_49 ( V_111 ) ;
return 0 ;
}
int F_50 ( struct V_23 * V_24 ,
struct V_131 * V_132 )
{
struct V_5 * V_6 = V_24 -> V_6 ;
unsigned int V_148 = V_132 -> V_83 -> V_98 ;
int V_149 , V_150 ;
V_149 = F_46 ( V_24 , V_132 ) ;
if ( V_149 == 0 )
V_150 = F_21 ( V_24 ) ;
V_24 -> V_151 [ V_148 ] += 1 ;
if ( V_149 ) {
V_24 -> V_152 += 1 ;
V_24 -> V_153 = V_149 ;
} else if ( V_150 ) {
V_24 -> V_154 += 1 ;
V_24 -> V_153 = V_149 = V_150 ;
} else {
V_24 -> V_153 = 0 ;
}
V_6 -> V_151 [ V_148 ] += 1 ;
V_6 -> V_155 [ V_148 ] = V_132 -> V_156 ;
return V_149 ;
}
static struct V_80 * F_51 ( struct V_28 * V_29 ,
T_1 V_112 )
{
struct V_1 * V_2 = V_29 -> V_157 ;
struct V_80 * V_99 ;
V_99 = F_52 ( V_29 , V_112 ) ;
if ( ! V_99 )
return NULL ;
if ( F_53 ( V_99 ) ) {
F_54 ( & V_99 -> V_111 ) ;
return NULL ;
}
if ( F_55 ( V_99 , V_105 ,
V_158 | V_159 ) ) {
F_54 ( & V_99 -> V_111 ) ;
return NULL ;
}
F_9 ( V_160 , V_161 ) ;
return V_99 ;
}
static void F_56 ( struct V_80 * V_99 )
{
if ( ! V_99 )
return;
if ( F_57 ( V_99 ) )
F_58 ( V_99 ) ;
F_54 ( & V_99 -> V_111 ) ;
}
static void F_59 ( struct V_28 * V_29 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_29 -> V_157 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_24 )
return;
if ( V_24 -> V_35 ) {
if ( V_24 -> V_57 != V_72 ) {
F_23 ( V_6 , V_24 ) ;
F_15 ( V_6 , V_24 ) ;
F_33 ( V_6 , V_24 -> V_57 ) ;
}
F_60 ( F_61 ( V_24 -> V_35 ) ) ;
}
F_56 ( V_24 -> V_81 ) ;
if ( V_24 -> V_26 != V_162 ) {
F_42 ( V_6 , V_24 ) ;
F_62 ( & V_6 -> V_163 , V_24 -> V_26 ) ;
}
F_63 ( V_24 ) ;
}
static struct V_23 * F_64 ( struct V_28 * V_29 ,
T_3 V_63 ,
struct V_84 * V_85 )
{
struct V_23 * V_24 ;
struct V_1 * V_2 = V_29 -> V_157 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_80 * V_99 ;
V_24 = F_65 ( sizeof( * V_24 ) , V_164 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_57 = V_72 ;
V_24 -> V_63 = V_63 ;
V_24 -> V_86 = V_85 ;
V_24 -> V_6 = V_6 ;
V_24 -> V_26 = ( T_3 ) F_66 ( & V_6 -> V_163 , 0 ,
V_165 , V_164 ) ;
if ( V_24 -> V_26 >= V_165 ) {
V_24 -> V_26 = V_162 ;
goto V_166;
}
V_99 = F_51 ( V_29 , V_138 + V_167 ) ;
if ( ! V_99 )
goto V_166;
V_24 -> V_81 = V_99 ;
V_24 -> V_35 = F_67 ( F_48 ( V_99 , 0 ) ) ;
V_24 -> V_124 = V_138 ;
V_24 -> V_77 = V_167 ;
V_24 -> V_36 = F_26 ( V_6 ) ;
if ( V_24 -> V_36 >= ( V_138 / 2 ) )
V_24 -> V_50 = 0 ;
else
V_24 -> V_50 = ( V_138 / 2 ) ;
V_24 -> V_57 = F_30 ( V_6 , V_24 -> V_63 ) ;
if ( V_24 -> V_57 == V_72 )
goto V_166;
F_35 ( V_6 , V_24 ) ;
F_36 ( V_6 , V_24 ) ;
F_20 ( V_6 , V_24 ) ;
if ( F_14 ( V_6 , V_24 ) )
goto V_166;
F_29 ( L_8 ,
V_63 , V_24 , V_24 -> V_26 , V_24 -> V_57 ) ;
return V_24 ;
V_166:
F_12 ( L_9 , V_63 ) ;
F_59 ( V_29 , V_24 ) ;
return NULL ;
}
static void F_68 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_80 * V_99 ;
unsigned long V_61 ;
T_3 V_112 , V_168 ;
if ( V_169 . V_170 < V_171 )
return;
if ( V_169 . V_170 > V_172 )
V_169 . V_170 = V_172 ;
V_112 = ( 1 + V_173 + 1 +
V_174 + 1 +
V_175 + 1 ) << V_139 ;
V_99 = V_6 -> V_176 ;
if ( ! V_99 ) {
V_99 = F_51 ( V_2 -> V_29 , V_112 ) ;
if ( ! V_99 ) {
V_169 . V_170 = - 1 ;
return;
}
V_6 -> V_176 = V_99 ;
}
V_168 = V_177 | V_178 |
( V_173 << V_179 ) |
( V_174 << V_180 ) |
( V_175 << V_181 ) ;
V_61 = F_39 ( V_99 ) >> V_139 ;
V_6 -> V_182 = ( V_61 << V_183 ) | V_168 ;
}
static void F_69 ( struct V_184 * V_185 )
{
struct V_186 * V_187 ;
T_1 V_188 , V_9 ;
V_185 -> V_189 = 500000 ;
V_185 -> V_190 = V_191 ;
for ( V_188 = 0 ; V_188 < V_192 ; V_188 ++ ) {
for ( V_9 = V_193 ; V_9 < V_194 ; V_9 ++ ) {
V_187 = & V_185 -> V_187 [ V_188 ] [ V_9 ] ;
V_187 -> V_195 = 1000000 ;
V_187 -> V_196 = 500000 ;
V_187 -> V_197 = 250000 ;
V_187 -> V_198 = 0 ;
}
}
V_185 -> V_199 = 1 ;
}
static void F_70 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_80 * V_99 ;
struct V_200 * V_201 ;
struct V_184 * V_185 ;
struct V_202 * V_203 ;
struct V_82 * V_83 ;
struct V_204 * V_204 ;
T_1 V_112 ;
V_112 = sizeof( struct V_200 ) + sizeof( struct V_184 ) +
sizeof( struct V_202 ) +
V_205 * V_105 ;
V_99 = V_6 -> V_206 ;
if ( ! V_99 ) {
V_99 = F_51 ( V_2 -> V_29 , F_71 ( V_112 ) ) ;
if ( ! V_99 )
return;
V_6 -> V_206 = V_99 ;
}
V_204 = F_48 ( V_99 , 0 ) ;
V_201 = F_67 ( V_204 ) ;
V_83 = & V_2 -> V_83 [ V_207 ] ;
V_201 -> V_208 = V_83 -> V_209 . V_91 ;
F_72 (engine, dev_priv)
V_201 -> V_210 [ V_83 -> V_98 ] = F_73 ( V_83 ) ;
V_185 = ( void * ) V_201 + sizeof( struct V_200 ) ;
F_69 ( V_185 ) ;
V_201 -> V_211 = F_39 ( V_99 ) +
sizeof( struct V_200 ) ;
V_203 = ( void * ) V_185 + sizeof( struct V_184 ) ;
F_72 (engine, dev_priv) {
V_203 -> V_212 [ V_83 -> V_98 ] . V_213 =
V_83 -> V_214 + V_215 ;
V_203 -> V_212 [ V_83 -> V_98 ] . V_216 = 0 ;
}
V_201 -> V_217 = V_201 -> V_211 +
sizeof( struct V_184 ) ;
V_201 -> V_218 = V_201 -> V_217 +
sizeof( struct V_202 ) ;
F_60 ( V_204 ) ;
}
int F_74 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_157 ;
const T_6 V_219 = sizeof( struct V_87 ) ;
const T_6 V_220 = V_165 * V_219 ;
const T_6 V_221 = F_75 ( V_220 , V_105 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_169 . V_222 )
return 0 ;
if ( V_6 -> V_126 )
return 0 ;
V_6 -> V_126 = F_51 ( V_2 -> V_29 , V_221 ) ;
if ( ! V_6 -> V_126 )
return - V_223 ;
F_76 ( & V_6 -> V_163 ) ;
F_68 ( V_6 ) ;
F_70 ( V_6 ) ;
return 0 ;
}
int F_77 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_157 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_84 * V_85 = V_2 -> V_224 ;
struct V_23 * V_24 ;
V_24 = F_64 ( V_29 , V_225 , V_85 ) ;
if ( ! V_24 ) {
F_12 ( L_10 ) ;
return - V_223 ;
}
V_6 -> V_226 = V_24 ;
F_16 ( V_6 , V_24 ) ;
return 0 ;
}
void F_78 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_157 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_59 ( V_29 , V_6 -> V_226 ) ;
V_6 -> V_226 = NULL ;
}
void F_79 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_157 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_56 ( V_2 -> V_6 . V_206 ) ;
V_6 -> V_206 = NULL ;
F_56 ( V_2 -> V_6 . V_176 ) ;
V_6 -> V_176 = NULL ;
if ( V_6 -> V_126 )
F_80 ( & V_6 -> V_163 ) ;
F_56 ( V_6 -> V_126 ) ;
V_6 -> V_126 = NULL ;
}
int F_81 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_157 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_84 * V_85 ;
T_1 V_7 [ 3 ] ;
if ( ! V_169 . V_222 )
return 0 ;
V_85 = V_2 -> V_224 ;
V_7 [ 0 ] = V_227 ;
V_7 [ 1 ] = V_228 ;
V_7 [ 2 ] = F_39 ( V_85 -> V_83 [ V_207 ] . V_101 ) ;
return F_5 ( V_6 , V_7 , F_19 ( V_7 ) ) ;
}
int F_82 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_157 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_84 * V_85 ;
T_1 V_7 [ 3 ] ;
if ( ! V_169 . V_222 )
return 0 ;
V_85 = V_2 -> V_224 ;
V_7 [ 0 ] = V_229 ;
V_7 [ 1 ] = V_230 ;
V_7 [ 2 ] = F_39 ( V_85 -> V_83 [ V_207 ] . V_101 ) ;
return F_5 ( V_6 , V_7 , F_19 ( V_7 ) ) ;
}
