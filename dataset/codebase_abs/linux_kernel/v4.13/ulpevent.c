static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_4 ;
}
static struct V_1 * F_2 ( int V_6 , T_1 V_3 ,
T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_9 = F_3 ( V_6 , V_7 ) ;
if ( ! V_9 )
goto V_10;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , V_3 , V_9 -> V_11 ) ;
return V_2 ;
V_10:
return NULL ;
}
int F_5 ( const struct V_1 * V_2 )
{
return V_12 == ( V_2 -> V_3 & V_12 ) ;
}
static inline void F_6 ( struct V_1 * V_2 ,
const struct V_13 * V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_8 * V_9 ;
F_7 ( (struct V_13 * ) V_14 ) ;
V_9 = F_8 ( V_2 ) ;
V_2 -> V_14 = (struct V_13 * ) V_14 ;
F_9 ( V_2 -> V_5 , & V_2 -> V_14 -> V_17 ) ;
F_10 ( V_9 , V_14 -> V_18 . V_19 ) ;
if ( V_16 && V_16 -> V_20 && ! V_16 -> V_20 -> V_19 )
V_16 -> V_20 -> V_19 = V_14 -> V_18 . V_19 ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_12 ( V_2 -> V_5 , & V_14 -> V_17 ) ;
F_13 ( V_14 ) ;
}
struct V_1 * F_14 (
const struct V_13 * V_14 ,
T_1 V_21 , T_1 V_22 , T_1 error , T_1 V_23 ,
T_1 V_24 , struct V_15 * V_16 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
struct V_8 * V_9 ;
if ( V_16 ) {
V_9 = F_15 ( V_16 -> V_9 ,
sizeof( struct V_25 ) , 0 , V_7 ) ;
if ( ! V_9 )
goto V_10;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , V_12 , V_9 -> V_11 ) ;
V_26 = F_16 ( V_9 , sizeof( struct V_25 ) ) ;
F_17 ( V_9 , sizeof( struct V_25 ) +
F_18 ( V_16 -> V_27 -> V_28 ) -
sizeof( struct V_29 ) ) ;
} else {
V_2 = F_2 ( sizeof( struct V_25 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_26 = F_19 ( V_9 , sizeof( struct V_25 ) ) ;
}
V_26 -> V_30 = V_31 ;
V_26 -> V_32 = V_22 ;
V_26 -> V_33 = 0 ;
V_26 -> V_34 = V_9 -> V_4 ;
V_26 -> V_35 = error ;
V_26 -> V_36 = V_23 ;
V_26 -> V_37 = V_24 ;
F_6 ( V_2 , V_14 ) ;
V_26 -> V_38 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_21 (
const struct V_13 * V_14 ,
const struct V_39 * V_40 ,
int V_21 , int V_22 , int error , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_41 * V_42 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_41 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_42 = F_19 ( V_9 , sizeof( struct V_41 ) ) ;
V_42 -> V_43 = V_44 ;
V_42 -> V_45 = sizeof( struct V_41 ) ;
V_42 -> V_46 = 0 ;
V_42 -> V_47 = V_22 ;
V_42 -> V_48 = error ;
F_6 ( V_2 , V_14 ) ;
V_42 -> V_49 = F_20 ( V_14 ) ;
memcpy ( & V_42 -> V_50 , V_40 , sizeof( struct V_39 ) ) ;
F_22 ( V_14 -> V_18 . V_19 -> V_51 ) -> F_23 (
F_24 ( V_14 -> V_18 . V_19 ) ,
(union V_52 * ) & V_42 -> V_50 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 *
F_25 ( const struct V_13 * V_14 ,
struct V_15 * V_16 , T_1 V_21 ,
T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_53 * V_54 ;
struct V_8 * V_9 ;
T_3 * V_55 ;
T_4 V_56 ;
int V_57 ;
V_55 = ( T_3 * ) ( V_16 -> V_9 -> V_58 ) ;
V_56 = V_55 -> V_56 ;
V_57 = F_26 ( F_18 ( V_55 -> V_28 ) ) - sizeof( T_3 ) ;
F_27 ( V_16 -> V_9 , sizeof( T_3 ) ) ;
V_9 = F_15 ( V_16 -> V_9 , sizeof( * V_54 ) , 0 , V_7 ) ;
F_27 ( V_16 -> V_9 , V_57 ) ;
if ( ! V_9 )
goto V_10;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , V_12 , V_9 -> V_11 ) ;
V_54 = F_16 ( V_9 , sizeof( * V_54 ) ) ;
F_17 ( V_9 , sizeof( * V_54 ) + V_57 ) ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_59 = V_60 ;
V_54 -> V_61 = 0 ;
V_54 -> V_62 = V_9 -> V_4 ;
V_54 -> V_63 = V_56 ;
F_6 ( V_2 , V_14 ) ;
V_54 -> V_64 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_28 (
const struct V_13 * V_14 , struct V_15 * V_16 ,
T_1 V_21 , T_5 error , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_65 * V_66 ;
struct V_8 * V_9 ;
int V_4 = F_18 ( V_16 -> V_27 -> V_28 ) ;
V_9 = F_15 ( V_16 -> V_9 ,
sizeof( struct V_65 ) ,
0 ,
V_7 ) ;
if ( ! V_9 )
goto V_10;
F_27 ( V_9 , sizeof( struct V_67 ) ) ;
V_4 -= sizeof( struct V_67 ) ;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , V_12 , V_9 -> V_11 ) ;
V_66 = F_16 ( V_9 , sizeof( struct V_65 ) ) ;
V_66 -> V_68 = V_69 ;
V_66 -> V_70 = V_21 ;
V_66 -> V_71 = sizeof( struct V_65 ) + V_4 ;
F_17 ( V_9 , V_66 -> V_71 ) ;
V_66 -> V_72 = error ;
memcpy ( & V_66 -> V_73 , & V_16 -> V_74 , sizeof( struct V_75 ) ) ;
V_66 -> V_73 . V_76 = V_16 -> V_27 -> V_21 ;
F_6 ( V_2 , V_14 ) ;
V_66 -> V_77 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_29 (
const struct V_13 * V_14 ,
T_1 V_21 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_78 * V_79 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_78 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_79 = F_19 ( V_9 , sizeof( struct V_78 ) ) ;
V_79 -> V_80 = V_81 ;
V_79 -> V_82 = 0 ;
V_79 -> V_83 = sizeof( struct V_78 ) ;
F_6 ( V_2 , V_14 ) ;
V_79 -> V_84 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_30 (
const struct V_13 * V_14 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_85 * V_86 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_85 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_86 = F_19 ( V_9 , sizeof( struct V_85 ) ) ;
V_86 -> V_87 = V_88 ;
V_86 -> V_89 = 0 ;
V_86 -> V_90 = sizeof( struct V_85 ) ;
V_86 -> V_91 = V_14 -> V_92 . V_93 ;
F_6 ( V_2 , V_14 ) ;
V_86 -> V_94 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_31 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
T_2 V_7 )
{
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 ;
T_6 V_95 , V_4 ;
int V_96 ;
if ( V_14 -> V_97 -> V_98 )
V_96 = F_32 ( & V_14 -> V_17 ) ;
else
V_96 = F_32 ( & V_14 -> V_18 . V_19 -> V_99 ) ;
if ( V_96 >= V_14 -> V_18 . V_19 -> V_100 ) {
if ( ( V_14 -> V_18 . V_19 -> V_101 & V_102 ) ||
( ! F_33 ( V_14 -> V_18 . V_19 , V_16 -> V_9 ,
V_16 -> V_9 -> V_11 ) ) )
goto V_10;
}
V_9 = F_34 ( V_16 -> V_9 , V_7 ) ;
if ( ! V_9 )
goto V_10;
if ( F_35 ( & V_14 -> V_92 . V_103 ,
F_36 ( V_16 -> V_104 . V_105 -> V_106 ) ,
V_16 -> V_107 ) )
goto V_108;
V_4 = F_18 ( V_16 -> V_27 -> V_28 ) ;
V_95 = F_26 ( V_4 ) - V_4 ;
F_17 ( V_9 , V_16 -> V_109 - V_95 - V_9 -> V_58 ) ;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , 0 , V_9 -> V_4 + sizeof( struct V_8 ) ) ;
F_37 ( V_16 ) ;
V_2 -> V_16 = V_16 ;
F_38 ( V_2 , V_14 ) ;
V_2 -> V_110 = F_18 ( V_16 -> V_104 . V_105 -> V_110 ) ;
V_2 -> V_111 = F_18 ( V_16 -> V_104 . V_105 -> V_111 ) ;
V_2 -> V_112 = V_16 -> V_104 . V_105 -> V_112 ;
if ( V_16 -> V_27 -> V_21 & V_113 ) {
V_2 -> V_21 |= V_114 ;
V_2 -> V_115 = F_39 ( & V_14 -> V_92 . V_103 ) ;
}
V_2 -> V_106 = F_36 ( V_16 -> V_104 . V_105 -> V_106 ) ;
V_2 -> V_3 |= V_16 -> V_27 -> V_21 ;
return V_2 ;
V_108:
F_40 ( V_16 ) ;
F_41 ( V_9 ) ;
V_10:
return NULL ;
}
struct V_1 * F_42 (
const struct V_13 * V_14 , T_5 V_116 ,
T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_117 * V_118 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_117 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_118 = F_19 ( V_9 , sizeof( struct V_117 ) ) ;
V_118 -> V_119 = V_120 ;
V_118 -> V_121 = 0 ;
V_118 -> V_122 = sizeof( struct V_117 ) ;
V_118 -> V_123 = V_116 ;
F_6 ( V_2 , V_14 ) ;
V_118 -> V_124 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_43 (
const struct V_13 * V_14 , T_1 V_125 ,
T_5 V_116 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_126 * V_127 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_126 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_127 = F_19 ( V_9 , sizeof( struct V_126 ) ) ;
V_127 -> V_128 = V_129 ;
V_127 -> V_130 = 0 ;
V_127 -> V_131 = sizeof( struct V_126 ) ;
V_127 -> V_132 = V_125 ;
V_127 -> V_133 = 0 ;
V_127 -> V_134 = V_116 ;
F_6 ( V_2 , V_14 ) ;
V_127 -> V_135 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_44 (
const struct V_13 * V_14 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_136 * V_137 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_136 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_9 = F_8 ( V_2 ) ;
V_137 = F_19 ( V_9 , sizeof( struct V_136 ) ) ;
V_137 -> V_138 = V_139 ;
V_137 -> V_140 = 0 ;
V_137 -> V_141 = sizeof( struct V_136 ) ;
F_6 ( V_2 , V_14 ) ;
V_137 -> V_142 = F_20 ( V_14 ) ;
return V_2 ;
}
struct V_1 * F_45 (
const struct V_13 * V_14 , T_1 V_21 , T_1 V_143 ,
T_1 * V_144 , T_2 V_7 )
{
struct V_145 * V_146 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_28 , V_147 ;
V_28 = sizeof( struct V_145 ) + 2 * V_143 ;
V_2 = F_2 ( V_28 , V_12 , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_9 = F_8 ( V_2 ) ;
V_146 = F_19 ( V_9 , V_28 ) ;
V_146 -> V_148 = V_149 ;
V_146 -> V_150 = V_21 ;
V_146 -> V_151 = V_28 ;
F_6 ( V_2 , V_14 ) ;
V_146 -> V_152 = F_20 ( V_14 ) ;
for ( V_147 = 0 ; V_147 < V_143 ; V_147 ++ )
V_146 -> V_153 [ V_147 ] = F_18 ( V_144 [ V_147 ] ) ;
return V_2 ;
}
struct V_1 * F_46 (
const struct V_13 * V_14 , T_1 V_21 , T_5 V_154 ,
T_5 V_155 , T_2 V_7 )
{
struct V_156 * V_157 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_156 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_9 = F_8 ( V_2 ) ;
V_157 = F_19 ( V_9 , sizeof( struct V_156 ) ) ;
V_157 -> V_158 = V_159 ;
V_157 -> V_160 = V_21 ;
V_157 -> V_161 = sizeof( struct V_156 ) ;
F_6 ( V_2 , V_14 ) ;
V_157 -> V_162 = F_20 ( V_14 ) ;
V_157 -> V_163 = V_154 ;
V_157 -> V_164 = V_155 ;
return V_2 ;
}
struct V_1 * F_47 (
const struct V_13 * V_14 , T_1 V_21 ,
T_5 V_165 , T_5 V_166 , T_2 V_7 )
{
struct V_167 * V_168 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_167 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_9 = F_8 ( V_2 ) ;
V_168 = F_19 ( V_9 , sizeof( struct V_167 ) ) ;
V_168 -> V_169 = V_170 ;
V_168 -> V_171 = V_21 ;
V_168 -> V_172 = sizeof( struct V_167 ) ;
F_6 ( V_2 , V_14 ) ;
V_168 -> V_173 = F_20 ( V_14 ) ;
V_168 -> V_165 = V_165 ;
V_168 -> V_166 = V_166 ;
return V_2 ;
}
T_1 F_48 ( const struct V_1 * V_2 )
{
union V_174 * V_175 ;
struct V_8 * V_9 ;
V_9 = F_8 ( V_2 ) ;
V_175 = (union V_174 * ) V_9 -> V_58 ;
return V_175 -> V_176 . V_177 ;
}
void F_49 ( const struct V_1 * V_2 ,
struct V_178 * V_178 )
{
struct V_75 V_74 ;
if ( F_5 ( V_2 ) )
return;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_179 = V_2 -> V_110 ;
V_74 . V_180 = V_2 -> V_111 ;
V_74 . V_181 = V_2 -> V_112 ;
V_74 . V_76 = V_2 -> V_21 ;
V_74 . V_182 = V_2 -> V_106 ;
V_74 . V_183 = V_2 -> V_115 ;
V_74 . V_184 = F_20 ( V_2 -> V_14 ) ;
V_74 . V_185 = V_2 -> V_14 -> V_186 ;
V_74 . V_187 = 0 ;
F_50 ( V_178 , V_188 , V_189 ,
sizeof( V_74 ) , & V_74 ) ;
}
void F_51 ( const struct V_1 * V_2 ,
struct V_178 * V_178 )
{
struct V_190 V_191 ;
if ( F_5 ( V_2 ) )
return;
memset ( & V_191 , 0 , sizeof( struct V_190 ) ) ;
V_191 . V_192 = V_2 -> V_110 ;
V_191 . V_193 = V_2 -> V_111 ;
V_191 . V_194 = V_2 -> V_112 ;
V_191 . V_195 = V_2 -> V_21 ;
V_191 . V_196 = V_2 -> V_106 ;
V_191 . V_197 = V_2 -> V_115 ;
V_191 . V_198 = F_20 ( V_2 -> V_14 ) ;
V_191 . V_199 = V_2 -> V_14 -> V_186 ;
F_50 ( V_178 , V_188 , V_200 ,
sizeof( V_191 ) , & V_191 ) ;
}
static void F_52 ( const struct V_1 * V_2 ,
struct V_178 * V_178 ,
const struct V_8 * V_9 )
{
struct V_201 V_202 ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_203 = V_2 -> V_110 ;
V_202 . V_204 = V_2 -> V_112 ;
V_202 . V_205 = V_2 -> V_21 ;
if ( F_5 ( V_2 ) )
V_202 . V_205 |= V_206 ;
V_202 . V_207 = V_9 -> V_4 ;
V_202 . V_208 = F_20 ( V_2 -> V_14 ) ;
F_50 ( V_178 , V_188 , V_209 ,
sizeof( V_202 ) , & V_202 ) ;
}
void F_53 ( const struct V_1 * V_2 ,
struct V_178 * V_178 ,
struct V_210 * V_19 )
{
struct V_8 * V_9 ;
int V_211 ;
V_9 = F_54 ( V_19 , V_212 , 1 , & V_211 ) ;
if ( V_9 != NULL ) {
F_52 ( F_4 ( V_9 ) ,
V_178 , V_9 ) ;
F_41 ( V_9 ) ;
}
}
static void F_38 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_8 * V_9 , * V_213 ;
V_9 = F_8 ( V_2 ) ;
F_6 ( V_2 , V_14 ) ;
F_55 ( V_14 , F_56 ( V_9 ) ) ;
if ( ! V_9 -> V_214 )
return;
F_57 (skb, frag)
F_38 ( F_4 ( V_213 ) , V_14 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_213 ;
unsigned int V_4 ;
V_9 = F_8 ( V_2 ) ;
V_4 = V_9 -> V_4 ;
if ( ! V_9 -> V_214 )
goto V_215;
F_57 (skb, frag) {
F_59 ( F_4 ( V_213 ) ) ;
}
V_215:
F_60 ( V_2 -> V_14 , V_4 ) ;
F_40 ( V_2 -> V_16 ) ;
F_11 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_213 ;
V_9 = F_8 ( V_2 ) ;
if ( ! V_9 -> V_214 )
goto V_215;
F_57 (skb, frag) {
F_59 ( F_4 ( V_213 ) ) ;
}
V_215:
F_40 ( V_2 -> V_16 ) ;
F_11 ( V_2 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) )
F_11 ( V_2 ) ;
else
F_58 ( V_2 ) ;
F_41 ( F_8 ( V_2 ) ) ;
}
unsigned int F_62 ( struct V_216 * V_217 )
{
struct V_8 * V_9 ;
unsigned int V_218 = 0 ;
while ( ( V_9 = F_63 ( V_217 ) ) != NULL ) {
struct V_1 * V_2 = F_4 ( V_9 ) ;
if ( ! F_5 ( V_2 ) )
V_218 += V_9 -> V_4 ;
F_61 ( V_2 ) ;
}
return V_218 ;
}
