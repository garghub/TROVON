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
struct V_53 * V_54 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
struct V_8 * V_9 ;
T_3 V_57 ;
int V_58 ;
V_56 = (struct V_55 * ) ( V_16 -> V_9 -> V_59 ) ;
V_57 = V_56 -> V_57 ;
V_58 = F_26 ( F_18 ( V_56 -> V_28 ) ) - sizeof( * V_56 ) ;
F_27 ( V_16 -> V_9 , sizeof( * V_56 ) ) ;
V_9 = F_15 ( V_16 -> V_9 , sizeof( * V_54 ) , 0 , V_7 ) ;
F_27 ( V_16 -> V_9 , V_58 ) ;
if ( ! V_9 )
goto V_10;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , V_12 , V_9 -> V_11 ) ;
V_54 = F_16 ( V_9 , sizeof( * V_54 ) ) ;
F_17 ( V_9 , sizeof( * V_54 ) + V_58 ) ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_60 = V_61 ;
V_54 -> V_62 = 0 ;
V_54 -> V_63 = V_9 -> V_4 ;
V_54 -> V_64 = V_57 ;
F_6 ( V_2 , V_14 ) ;
V_54 -> V_65 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_28 (
const struct V_13 * V_14 , struct V_15 * V_16 ,
T_1 V_21 , T_4 error , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_66 * V_67 ;
struct V_8 * V_9 ;
int V_4 = F_18 ( V_16 -> V_27 -> V_28 ) ;
V_9 = F_15 ( V_16 -> V_9 ,
sizeof( struct V_66 ) ,
0 ,
V_7 ) ;
if ( ! V_9 )
goto V_10;
F_27 ( V_9 , sizeof( struct V_68 ) ) ;
V_4 -= sizeof( struct V_68 ) ;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , V_12 , V_9 -> V_11 ) ;
V_67 = F_16 ( V_9 , sizeof( struct V_66 ) ) ;
V_67 -> V_69 = V_70 ;
V_67 -> V_71 = V_21 ;
V_67 -> V_72 = sizeof( struct V_66 ) + V_4 ;
F_17 ( V_9 , V_67 -> V_72 ) ;
V_67 -> V_73 = error ;
memcpy ( & V_67 -> V_74 , & V_16 -> V_75 , sizeof( struct V_76 ) ) ;
V_67 -> V_74 . V_77 = V_16 -> V_27 -> V_21 ;
F_6 ( V_2 , V_14 ) ;
V_67 -> V_78 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_29 (
const struct V_13 * V_14 ,
T_1 V_21 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_79 * V_80 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_79 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_80 = F_19 ( V_9 , sizeof( struct V_79 ) ) ;
V_80 -> V_81 = V_82 ;
V_80 -> V_83 = 0 ;
V_80 -> V_84 = sizeof( struct V_79 ) ;
F_6 ( V_2 , V_14 ) ;
V_80 -> V_85 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_30 (
const struct V_13 * V_14 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_86 * V_87 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_86 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_87 = F_19 ( V_9 , sizeof( struct V_86 ) ) ;
V_87 -> V_88 = V_89 ;
V_87 -> V_90 = 0 ;
V_87 -> V_91 = sizeof( struct V_86 ) ;
V_87 -> V_92 = V_14 -> V_93 . V_94 ;
F_6 ( V_2 , V_14 ) ;
V_87 -> V_95 = F_20 ( V_14 ) ;
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
T_5 V_96 , V_4 ;
int V_97 ;
if ( V_14 -> V_98 -> V_99 )
V_97 = F_32 ( & V_14 -> V_17 ) ;
else
V_97 = F_32 ( & V_14 -> V_18 . V_19 -> V_100 ) ;
if ( V_97 >= V_14 -> V_18 . V_19 -> V_101 ) {
if ( ( V_14 -> V_18 . V_19 -> V_102 & V_103 ) ||
( ! F_33 ( V_14 -> V_18 . V_19 , V_16 -> V_9 ,
V_16 -> V_9 -> V_11 ) ) )
goto V_10;
}
V_9 = F_34 ( V_16 -> V_9 , V_7 ) ;
if ( ! V_9 )
goto V_10;
if ( F_35 ( & V_14 -> V_93 . V_104 ,
F_36 ( V_16 -> V_105 . V_106 -> V_107 ) ,
V_16 -> V_108 ) )
goto V_109;
V_4 = F_18 ( V_16 -> V_27 -> V_28 ) ;
V_96 = F_26 ( V_4 ) - V_4 ;
F_17 ( V_9 , V_16 -> V_110 - V_96 - V_9 -> V_59 ) ;
V_2 = F_4 ( V_9 ) ;
F_1 ( V_2 , 0 , V_9 -> V_4 + sizeof( struct V_8 ) ) ;
F_37 ( V_16 ) ;
V_2 -> V_16 = V_16 ;
F_38 ( V_2 , V_14 ) ;
V_2 -> V_111 = F_18 ( V_16 -> V_105 . V_106 -> V_111 ) ;
V_2 -> V_112 = F_18 ( V_16 -> V_105 . V_106 -> V_112 ) ;
V_2 -> V_113 = V_16 -> V_105 . V_106 -> V_113 ;
if ( V_16 -> V_27 -> V_21 & V_114 ) {
V_2 -> V_21 |= V_115 ;
V_2 -> V_116 = F_39 ( & V_14 -> V_93 . V_104 ) ;
}
V_2 -> V_107 = F_36 ( V_16 -> V_105 . V_106 -> V_107 ) ;
V_2 -> V_3 |= V_16 -> V_27 -> V_21 ;
return V_2 ;
V_109:
F_40 ( V_16 ) ;
F_41 ( V_9 ) ;
V_10:
return NULL ;
}
struct V_1 * F_42 (
const struct V_13 * V_14 , T_4 V_117 ,
T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_118 * V_119 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_118 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_119 = F_19 ( V_9 , sizeof( struct V_118 ) ) ;
V_119 -> V_120 = V_121 ;
V_119 -> V_122 = 0 ;
V_119 -> V_123 = sizeof( struct V_118 ) ;
V_119 -> V_124 = V_117 ;
F_6 ( V_2 , V_14 ) ;
V_119 -> V_125 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_43 (
const struct V_13 * V_14 , T_1 V_126 ,
T_4 V_117 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_127 * V_128 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_127 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
goto V_10;
V_9 = F_8 ( V_2 ) ;
V_128 = F_19 ( V_9 , sizeof( struct V_127 ) ) ;
V_128 -> V_129 = V_130 ;
V_128 -> V_131 = 0 ;
V_128 -> V_132 = sizeof( struct V_127 ) ;
V_128 -> V_133 = V_126 ;
V_128 -> V_134 = 0 ;
V_128 -> V_135 = V_117 ;
F_6 ( V_2 , V_14 ) ;
V_128 -> V_136 = F_20 ( V_14 ) ;
return V_2 ;
V_10:
return NULL ;
}
struct V_1 * F_44 (
const struct V_13 * V_14 , T_2 V_7 )
{
struct V_1 * V_2 ;
struct V_137 * V_138 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_137 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_9 = F_8 ( V_2 ) ;
V_138 = F_19 ( V_9 , sizeof( struct V_137 ) ) ;
V_138 -> V_139 = V_140 ;
V_138 -> V_141 = 0 ;
V_138 -> V_142 = sizeof( struct V_137 ) ;
F_6 ( V_2 , V_14 ) ;
V_138 -> V_143 = F_20 ( V_14 ) ;
return V_2 ;
}
struct V_1 * F_45 (
const struct V_13 * V_14 , T_1 V_21 , T_1 V_144 ,
T_3 * V_145 , T_2 V_7 )
{
struct V_146 * V_147 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_28 , V_148 ;
V_28 = sizeof( struct V_146 ) + 2 * V_144 ;
V_2 = F_2 ( V_28 , V_12 , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_9 = F_8 ( V_2 ) ;
V_147 = F_19 ( V_9 , V_28 ) ;
V_147 -> V_149 = V_150 ;
V_147 -> V_151 = V_21 ;
V_147 -> V_152 = V_28 ;
F_6 ( V_2 , V_14 ) ;
V_147 -> V_153 = F_20 ( V_14 ) ;
for ( V_148 = 0 ; V_148 < V_144 ; V_148 ++ )
V_147 -> V_154 [ V_148 ] = F_18 ( V_145 [ V_148 ] ) ;
return V_2 ;
}
struct V_1 * F_46 (
const struct V_13 * V_14 , T_1 V_21 , T_4 V_155 ,
T_4 V_156 , T_2 V_7 )
{
struct V_157 * V_158 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_157 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_9 = F_8 ( V_2 ) ;
V_158 = F_19 ( V_9 , sizeof( struct V_157 ) ) ;
V_158 -> V_159 = V_160 ;
V_158 -> V_161 = V_21 ;
V_158 -> V_162 = sizeof( struct V_157 ) ;
F_6 ( V_2 , V_14 ) ;
V_158 -> V_163 = F_20 ( V_14 ) ;
V_158 -> V_164 = V_155 ;
V_158 -> V_165 = V_156 ;
return V_2 ;
}
struct V_1 * F_47 (
const struct V_13 * V_14 , T_1 V_21 ,
T_4 V_166 , T_4 V_167 , T_2 V_7 )
{
struct V_168 * V_169 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_2 = F_2 ( sizeof( struct V_168 ) ,
V_12 , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_9 = F_8 ( V_2 ) ;
V_169 = F_19 ( V_9 , sizeof( struct V_168 ) ) ;
V_169 -> V_170 = V_171 ;
V_169 -> V_172 = V_21 ;
V_169 -> V_173 = sizeof( struct V_168 ) ;
F_6 ( V_2 , V_14 ) ;
V_169 -> V_174 = F_20 ( V_14 ) ;
V_169 -> V_166 = V_166 ;
V_169 -> V_167 = V_167 ;
return V_2 ;
}
T_1 F_48 ( const struct V_1 * V_2 )
{
union V_175 * V_176 ;
struct V_8 * V_9 ;
V_9 = F_8 ( V_2 ) ;
V_176 = (union V_175 * ) V_9 -> V_59 ;
return V_176 -> V_177 . V_178 ;
}
void F_49 ( const struct V_1 * V_2 ,
struct V_179 * V_179 )
{
struct V_76 V_75 ;
if ( F_5 ( V_2 ) )
return;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_180 = V_2 -> V_111 ;
V_75 . V_181 = V_2 -> V_112 ;
V_75 . V_182 = V_2 -> V_113 ;
V_75 . V_77 = V_2 -> V_21 ;
V_75 . V_183 = V_2 -> V_107 ;
V_75 . V_184 = V_2 -> V_116 ;
V_75 . V_185 = F_20 ( V_2 -> V_14 ) ;
V_75 . V_186 = V_2 -> V_14 -> V_187 ;
V_75 . V_188 = 0 ;
F_50 ( V_179 , V_189 , V_190 ,
sizeof( V_75 ) , & V_75 ) ;
}
void F_51 ( const struct V_1 * V_2 ,
struct V_179 * V_179 )
{
struct V_191 V_192 ;
if ( F_5 ( V_2 ) )
return;
memset ( & V_192 , 0 , sizeof( struct V_191 ) ) ;
V_192 . V_193 = V_2 -> V_111 ;
V_192 . V_194 = V_2 -> V_112 ;
V_192 . V_195 = V_2 -> V_113 ;
V_192 . V_196 = V_2 -> V_21 ;
V_192 . V_197 = V_2 -> V_107 ;
V_192 . V_198 = V_2 -> V_116 ;
V_192 . V_199 = F_20 ( V_2 -> V_14 ) ;
V_192 . V_200 = V_2 -> V_14 -> V_187 ;
F_50 ( V_179 , V_189 , V_201 ,
sizeof( V_192 ) , & V_192 ) ;
}
static void F_52 ( const struct V_1 * V_2 ,
struct V_179 * V_179 ,
const struct V_8 * V_9 )
{
struct V_202 V_203 ;
memset ( & V_203 , 0 , sizeof( V_203 ) ) ;
V_203 . V_204 = V_2 -> V_111 ;
V_203 . V_205 = V_2 -> V_113 ;
V_203 . V_206 = V_2 -> V_21 ;
if ( F_5 ( V_2 ) )
V_203 . V_206 |= V_207 ;
V_203 . V_208 = V_9 -> V_4 ;
V_203 . V_209 = F_20 ( V_2 -> V_14 ) ;
F_50 ( V_179 , V_189 , V_210 ,
sizeof( V_203 ) , & V_203 ) ;
}
void F_53 ( const struct V_1 * V_2 ,
struct V_179 * V_179 ,
struct V_211 * V_19 )
{
struct V_8 * V_9 ;
int V_212 ;
V_9 = F_54 ( V_19 , V_213 , 1 , & V_212 ) ;
if ( V_9 != NULL ) {
F_52 ( F_4 ( V_9 ) ,
V_179 , V_9 ) ;
F_41 ( V_9 ) ;
}
}
static void F_38 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_8 * V_9 , * V_214 ;
V_9 = F_8 ( V_2 ) ;
F_6 ( V_2 , V_14 ) ;
F_55 ( V_14 , F_56 ( V_9 ) ) ;
if ( ! V_9 -> V_215 )
return;
F_57 (skb, frag)
F_38 ( F_4 ( V_214 ) , V_14 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_214 ;
unsigned int V_4 ;
V_9 = F_8 ( V_2 ) ;
V_4 = V_9 -> V_4 ;
if ( ! V_9 -> V_215 )
goto V_216;
F_57 (skb, frag) {
F_59 ( F_4 ( V_214 ) ) ;
}
V_216:
F_60 ( V_2 -> V_14 , V_4 ) ;
F_40 ( V_2 -> V_16 ) ;
F_11 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_214 ;
V_9 = F_8 ( V_2 ) ;
if ( ! V_9 -> V_215 )
goto V_216;
F_57 (skb, frag) {
F_59 ( F_4 ( V_214 ) ) ;
}
V_216:
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
unsigned int F_62 ( struct V_217 * V_218 )
{
struct V_8 * V_9 ;
unsigned int V_219 = 0 ;
while ( ( V_9 = F_63 ( V_218 ) ) != NULL ) {
struct V_1 * V_2 = F_4 ( V_9 ) ;
if ( ! F_5 ( V_2 ) )
V_219 += V_9 -> V_4 ;
F_61 ( V_2 ) ;
}
return V_219 ;
}
