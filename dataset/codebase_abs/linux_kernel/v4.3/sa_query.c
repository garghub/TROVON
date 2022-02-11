static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 &= ~ V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 [ 1 ] ;
struct V_12 * V_13 = V_2 -> V_10 -> V_13 ;
T_1 V_14 = V_13 -> V_15 . V_14 ;
T_2 V_16 ;
T_3 V_17 ;
struct V_18 * V_19 ;
V_2 -> V_10 -> V_11 [ 1 ] = NULL ;
V_19 = (struct V_18 * )
F_4 ( V_7 , F_5 ( sizeof( * V_19 ) ) ) ;
memcpy ( V_19 -> V_20 , V_2 -> V_21 -> V_22 -> V_23 -> V_24 ,
V_25 ) ;
V_19 -> V_26 = V_2 -> V_21 -> V_26 ;
if ( ( V_14 & V_27 ) &&
V_9 -> V_28 != 0 )
V_2 -> V_29 = V_30 ;
else
V_2 -> V_29 = V_31 ;
V_19 -> V_29 = V_2 -> V_29 ;
if ( V_14 & V_32 ) {
V_17 = F_6 ( V_9 -> V_33 ) ;
F_7 ( V_7 , V_34 | V_35 ,
sizeof( V_17 ) , & V_17 ) ;
}
if ( V_14 & V_36 )
F_7 ( V_7 , V_34 | V_37 ,
sizeof( V_9 -> V_38 ) , & V_9 -> V_38 ) ;
if ( V_14 & V_39 )
F_7 ( V_7 , V_34 | V_40 ,
sizeof( V_9 -> V_41 ) , & V_9 -> V_41 ) ;
if ( V_14 & V_42 )
F_7 ( V_7 , V_34 | V_43 ,
sizeof( V_9 -> V_44 ) , & V_9 -> V_44 ) ;
if ( V_14 & V_45 ) {
V_16 = F_8 ( V_9 -> V_46 ) ;
F_7 ( V_7 , V_34 | V_47 ,
sizeof( V_16 ) , & V_16 ) ;
}
if ( V_14 & V_48 ) {
V_16 = F_8 ( V_9 -> V_49 ) ;
F_7 ( V_7 , V_34 | V_50 ,
sizeof( V_16 ) , & V_16 ) ;
}
}
static int F_9 ( T_1 V_14 )
{
int V_51 = 0 ;
if ( V_14 & V_32 )
V_51 += F_10 ( sizeof( T_3 ) ) ;
if ( V_14 & V_36 )
V_51 += F_10 ( sizeof( struct V_52 ) ) ;
if ( V_14 & V_39 )
V_51 += F_10 ( sizeof( struct V_52 ) ) ;
if ( V_14 & V_42 )
V_51 += F_10 ( sizeof( V_53 ) ) ;
if ( V_14 & V_45 )
V_51 += F_10 ( sizeof( T_2 ) ) ;
if ( V_14 & V_48 )
V_51 += F_10 ( sizeof( T_2 ) ) ;
if ( F_11 ( V_51 == 0 ) )
return V_51 ;
V_51 += F_5 ( sizeof( struct V_18 ) ) ;
return V_51 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = NULL ;
struct V_54 * V_55 ;
void * V_56 ;
int V_57 = 0 ;
struct V_12 * V_13 ;
int V_51 ;
V_13 = V_2 -> V_10 -> V_13 ;
V_51 = F_9 ( V_13 -> V_15 . V_14 ) ;
if ( V_51 <= 0 )
return - V_58 ;
V_7 = F_13 ( V_51 , V_59 ) ;
if ( ! V_7 )
return - V_60 ;
V_56 = F_14 ( V_7 , & V_55 , V_2 -> V_61 , 0 , V_62 ,
V_63 , V_64 ) ;
if ( ! V_56 ) {
F_15 ( V_7 ) ;
return - V_58 ;
}
F_3 ( V_7 , V_2 ) ;
F_16 ( V_7 , V_55 ) ;
V_57 = F_17 ( V_7 , V_55 , V_65 , V_59 ) ;
if ( ! V_57 )
V_57 = V_51 ;
else
V_57 = 0 ;
return V_57 ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned long V_66 ;
int V_57 ;
F_19 ( & V_2 -> V_67 ) ;
V_2 -> V_61 = ( V_68 ) F_20 ( & V_69 ) ;
F_21 ( & V_70 , V_3 ) ;
V_57 = F_12 ( V_2 ) ;
if ( V_57 <= 0 ) {
V_57 = - V_71 ;
goto V_72;
} else {
V_57 = 0 ;
}
V_66 = F_22 ( V_73 ) ;
V_2 -> V_74 = V_66 + V_75 ;
F_23 ( & V_2 -> V_67 , & V_76 ) ;
if ( V_76 . V_77 == & V_2 -> V_67 )
F_24 ( V_78 , & V_79 , V_66 ) ;
V_72:
F_25 ( & V_70 , V_3 ) ;
return V_57 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_1 * V_80 ;
int V_81 = 0 ;
F_21 ( & V_70 , V_3 ) ;
F_27 (wait_query, &ib_nl_request_list, list) {
if ( V_2 == V_80 ) {
V_2 -> V_3 |= V_5 ;
V_2 -> V_74 = V_75 ;
F_28 ( & V_2 -> V_67 , & V_76 ) ;
V_81 = 1 ;
F_29 ( V_78 , & V_79 , 1 ) ;
break;
}
}
F_25 ( & V_70 , V_3 ) ;
return V_81 ;
}
static void F_30 ( struct V_1 * V_2 ,
const struct V_54 * V_55 )
{
struct V_82 V_83 ;
struct V_12 * V_13 = NULL ;
const struct V_84 * V_85 , * V_86 ;
struct V_87 * V_88 ;
int V_51 , V_89 ;
V_68 V_90 = 0 ;
int V_91 = - V_71 ;
if ( V_2 -> V_92 ) {
V_85 = ( const struct V_84 * ) F_31 ( V_55 ) ;
V_51 = F_32 ( V_55 ) ;
switch ( V_2 -> V_29 ) {
case V_31 :
V_90 = V_93 | V_94 ;
break;
case V_95 :
case V_30 :
default:
V_90 = V_93 | V_96 |
V_97 ;
break;
}
F_33 (curr, head, len, rem) {
if ( V_86 -> V_98 == V_99 ) {
V_88 = F_34 ( V_86 ) ;
if ( ( V_88 -> V_3 & V_90 ) == V_90 ) {
V_13 = V_2 -> V_10 -> V_13 ;
V_13 -> V_100 . V_101 |=
V_102 ;
memcpy ( V_13 -> V_56 , V_88 -> V_103 ,
sizeof( V_88 -> V_103 ) ) ;
V_91 = 0 ;
break;
}
}
}
V_2 -> V_92 ( V_2 , V_91 , V_13 ) ;
}
V_83 . V_104 = V_2 -> V_10 ;
V_83 . V_91 = V_105 ;
F_35 ( V_2 -> V_10 -> V_106 , & V_83 ) ;
}
static void F_36 ( struct V_107 * V_108 )
{
unsigned long V_3 ;
struct V_1 * V_2 ;
unsigned long V_66 ;
struct V_82 V_83 ;
int V_57 ;
F_21 ( & V_70 , V_3 ) ;
while ( ! F_37 ( & V_76 ) ) {
V_2 = F_38 ( V_76 . V_77 ,
struct V_1 , V_67 ) ;
if ( F_39 ( V_2 -> V_74 , V_75 ) ) {
V_66 = V_2 -> V_74 - V_75 ;
if ( ( long ) V_66 <= 0 )
V_66 = 1 ;
F_24 ( V_78 , & V_79 , V_66 ) ;
break;
}
F_40 ( & V_2 -> V_67 ) ;
F_1 ( V_2 ) ;
if ( F_2 ( V_2 ) )
V_57 = - 1 ;
else
V_57 = F_41 ( V_2 -> V_10 , NULL ) ;
if ( V_57 ) {
V_83 . V_104 = V_2 -> V_10 ;
V_83 . V_91 = V_109 ;
F_25 ( & V_70 , V_3 ) ;
F_35 ( V_2 -> V_21 -> V_22 , & V_83 ) ;
F_21 ( & V_70 , V_3 ) ;
}
}
F_25 ( & V_70 , V_3 ) ;
}
static int F_42 ( struct V_6 * V_7 ,
struct V_110 * V_111 )
{
const struct V_54 * V_55 = (struct V_54 * ) V_111 -> V_55 ;
int V_74 , V_112 , V_113 ;
const struct V_84 * V_114 ;
unsigned long V_3 ;
struct V_1 * V_2 ;
long V_66 = 0 ;
struct V_84 * V_115 [ V_116 ] ;
int V_57 ;
if ( ! F_43 ( V_7 , V_117 ) )
return - V_118 ;
V_57 = F_44 ( V_115 , V_116 - 1 , F_31 ( V_55 ) ,
F_32 ( V_55 ) , V_119 ) ;
V_114 = ( const struct V_84 * ) V_115 [ V_120 ] ;
if ( V_57 || ! V_114 )
goto V_121;
V_74 = * ( int * ) F_34 ( V_114 ) ;
if ( V_74 < V_122 )
V_74 = V_122 ;
if ( V_74 > V_123 )
V_74 = V_123 ;
V_112 = V_74 - V_73 ;
if ( V_112 < 0 )
V_113 = - V_112 ;
else
V_113 = V_112 ;
if ( V_112 != 0 ) {
F_21 ( & V_70 , V_3 ) ;
V_73 = V_74 ;
F_27 (query, &ib_nl_request_list, list) {
if ( V_112 < 0 && V_113 > V_2 -> V_74 )
V_2 -> V_74 = 0 ;
else
V_2 -> V_74 += V_112 ;
if ( ! V_66 ) {
V_66 = V_2 -> V_74 - V_75 ;
if ( V_66 <= 0 )
V_66 = 1 ;
}
}
if ( V_66 )
F_29 ( V_78 , & V_79 ,
( unsigned long ) V_66 ) ;
F_25 ( & V_70 , V_3 ) ;
}
V_121:
return V_7 -> V_51 ;
}
static inline int F_45 ( const struct V_54 * V_55 )
{
struct V_84 * V_115 [ V_116 ] ;
int V_57 ;
if ( V_55 -> V_124 & V_125 )
return 0 ;
V_57 = F_44 ( V_115 , V_116 - 1 , F_31 ( V_55 ) ,
F_32 ( V_55 ) , V_119 ) ;
if ( V_57 )
return 0 ;
return 1 ;
}
static int F_46 ( struct V_6 * V_7 ,
struct V_110 * V_111 )
{
const struct V_54 * V_55 = (struct V_54 * ) V_111 -> V_55 ;
unsigned long V_3 ;
struct V_1 * V_2 ;
struct V_126 * V_104 ;
struct V_82 V_83 ;
int V_81 = 0 ;
int V_57 ;
if ( ! F_43 ( V_7 , V_117 ) )
return - V_118 ;
F_21 ( & V_70 , V_3 ) ;
F_27 (query, &ib_nl_request_list, list) {
if ( V_55 -> V_127 == V_2 -> V_61 ) {
V_81 = ! F_2 ( V_2 ) ;
if ( V_81 )
F_40 ( & V_2 -> V_67 ) ;
break;
}
}
if ( ! V_81 ) {
F_25 ( & V_70 , V_3 ) ;
goto V_128;
}
V_104 = V_2 -> V_10 ;
if ( ! F_45 ( V_55 ) ) {
F_1 ( V_2 ) ;
V_57 = F_41 ( V_2 -> V_10 , NULL ) ;
F_25 ( & V_70 , V_3 ) ;
if ( V_57 ) {
V_83 . V_104 = V_104 ;
V_83 . V_91 = V_129 ;
F_35 ( V_2 -> V_21 -> V_22 , & V_83 ) ;
}
} else {
F_25 ( & V_70 , V_3 ) ;
F_30 ( V_2 , V_55 ) ;
}
V_128:
return V_7 -> V_51 ;
}
static void F_47 ( struct V_130 * V_130 )
{
struct V_131 * V_132 = F_48 ( V_130 , struct V_131 , V_133 ) ;
F_49 ( V_132 -> V_134 ) ;
F_50 ( V_132 ) ;
}
static void F_51 ( struct V_107 * V_108 )
{
struct V_135 * V_21 =
F_48 ( V_108 , struct V_135 , V_136 ) ;
struct V_131 * V_137 ;
struct V_138 V_139 ;
struct V_140 V_141 ;
if ( F_52 ( V_21 -> V_22 -> V_23 , V_21 -> V_26 , & V_139 ) ) {
F_53 ( V_142 L_1 ) ;
return;
}
V_137 = F_54 ( sizeof *V_137 , V_59 ) ;
if ( ! V_137 ) {
F_53 ( V_142 L_2 ) ;
return;
}
F_55 ( & V_137 -> V_133 ) ;
V_137 -> V_143 = ( 1 << V_139 . V_144 ) - 1 ;
V_137 -> V_145 = 0 ;
if ( F_56 ( V_21 -> V_22 -> V_23 , V_21 -> V_26 ,
V_146 , & V_137 -> V_145 ) )
F_53 ( V_147 L_3 ) ;
memset ( & V_141 , 0 , sizeof V_141 ) ;
V_141 . V_148 = V_139 . V_149 ;
V_141 . V_150 = V_139 . V_151 ;
V_141 . V_26 = V_21 -> V_26 ;
V_137 -> V_134 = F_57 ( V_21 -> V_22 -> V_152 -> V_153 , & V_141 ) ;
if ( F_58 ( V_137 -> V_134 ) ) {
F_53 ( V_142 L_4 ) ;
F_50 ( V_137 ) ;
return;
}
F_59 ( & V_21 -> V_154 ) ;
if ( V_21 -> V_132 )
F_60 ( & V_21 -> V_132 -> V_133 , F_47 ) ;
V_21 -> V_132 = V_137 ;
F_61 ( & V_21 -> V_154 ) ;
}
static void F_62 ( struct V_155 * V_156 , struct V_157 * V_158 )
{
if ( V_158 -> V_158 == V_159 ||
V_158 -> V_158 == V_160 ||
V_158 -> V_158 == V_161 ||
V_158 -> V_158 == V_162 ||
V_158 -> V_158 == V_163 ||
V_158 -> V_158 == V_164 ) {
unsigned long V_3 ;
struct V_165 * V_166 =
F_48 ( V_156 , F_63 ( * V_166 ) , V_167 ) ;
struct V_135 * V_21 =
& V_166 -> V_21 [ V_158 -> V_168 . V_26 - V_166 -> V_169 ] ;
if ( ! F_64 ( V_156 -> V_23 , V_21 -> V_26 ) )
return;
F_21 ( & V_21 -> V_154 , V_3 ) ;
if ( V_21 -> V_132 )
F_60 ( & V_21 -> V_132 -> V_133 , F_47 ) ;
V_21 -> V_132 = NULL ;
F_25 ( & V_21 -> V_154 , V_3 ) ;
F_65 ( V_170 , & V_166 -> V_21 [ V_158 -> V_168 . V_26 -
V_166 -> V_169 ] . V_136 ) ;
}
}
void F_66 ( struct V_171 * V_172 )
{
F_67 ( & V_172 -> V_173 , 1 ) ;
F_68 ( & V_172 -> V_174 ) ;
}
void F_69 ( struct V_171 * V_172 )
{
F_70 ( V_172 ) ;
F_71 ( & V_172 -> V_174 ) ;
}
void F_72 ( int V_175 , struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_176 * V_22 ;
struct V_126 * V_10 ;
F_21 ( & V_177 , V_3 ) ;
if ( F_73 ( & V_178 , V_175 ) != V_2 ) {
F_25 ( & V_177 , V_3 ) ;
return;
}
V_22 = V_2 -> V_21 -> V_22 ;
V_10 = V_2 -> V_10 ;
F_25 ( & V_177 , V_3 ) ;
if ( ! F_26 ( V_2 ) )
F_74 ( V_22 , V_10 ) ;
}
static V_53 F_75 ( struct V_179 * V_23 , V_53 V_26 )
{
struct V_165 * V_166 ;
struct V_135 * V_21 ;
unsigned long V_3 ;
V_53 V_143 ;
V_166 = F_76 ( V_23 , & V_180 ) ;
if ( ! V_166 )
return 0x7f ;
V_21 = & V_166 -> V_21 [ V_26 - V_166 -> V_169 ] ;
F_21 ( & V_21 -> V_154 , V_3 ) ;
V_143 = V_21 -> V_132 ? V_21 -> V_132 -> V_143 : 0x7f ;
F_25 ( & V_21 -> V_154 , V_3 ) ;
return V_143 ;
}
int F_77 ( struct V_179 * V_23 , V_53 V_26 ,
struct V_8 * V_88 , struct V_140 * V_141 )
{
int V_57 ;
T_2 V_181 ;
int V_182 ;
memset ( V_141 , 0 , sizeof *V_141 ) ;
V_141 -> V_148 = F_8 ( V_88 -> V_148 ) ;
V_141 -> V_150 = V_88 -> V_150 ;
V_141 -> V_183 = F_8 ( V_88 -> V_184 ) &
F_75 ( V_23 , V_26 ) ;
V_141 -> V_26 = V_26 ;
V_141 -> V_185 = V_88 -> V_186 ;
V_182 = F_78 ( V_23 , V_26 ) ;
if ( V_88 -> V_187 > 1 || V_182 ) {
V_141 -> V_188 = V_189 ;
V_141 -> V_190 . V_38 = V_88 -> V_38 ;
V_57 = F_79 ( V_23 , & V_88 -> V_41 , & V_26 ,
& V_181 ) ;
if ( V_57 )
return V_57 ;
V_141 -> V_190 . V_191 = V_181 ;
V_141 -> V_190 . V_192 = F_80 ( V_88 -> V_192 ) ;
V_141 -> V_190 . V_187 = V_88 -> V_187 ;
V_141 -> V_190 . V_44 = V_88 -> V_44 ;
}
if ( V_182 ) {
memcpy ( V_141 -> V_193 , V_88 -> V_193 , V_194 ) ;
V_141 -> V_195 = V_88 -> V_195 ;
} else {
V_141 -> V_195 = 0xffff ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , T_4 V_196 )
{
unsigned long V_3 ;
F_21 ( & V_2 -> V_21 -> V_154 , V_3 ) ;
if ( ! V_2 -> V_21 -> V_132 ) {
F_25 ( & V_2 -> V_21 -> V_154 , V_3 ) ;
return - V_197 ;
}
F_82 ( & V_2 -> V_21 -> V_132 -> V_133 ) ;
V_2 -> V_132 = V_2 -> V_21 -> V_132 ;
F_25 ( & V_2 -> V_21 -> V_154 , V_3 ) ;
V_2 -> V_10 = F_83 ( V_2 -> V_21 -> V_22 , 1 ,
V_2 -> V_132 -> V_145 ,
0 , V_198 , V_199 ,
V_196 ,
V_200 ) ;
if ( F_58 ( V_2 -> V_10 ) ) {
F_60 ( & V_2 -> V_132 -> V_133 , F_47 ) ;
return - V_60 ;
}
V_2 -> V_10 -> V_134 = V_2 -> V_132 -> V_134 ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_85 ( V_2 -> V_10 ) ;
F_60 ( & V_2 -> V_132 -> V_133 , F_47 ) ;
}
static void F_86 ( struct V_12 * V_13 , struct V_176 * V_22 )
{
unsigned long V_3 ;
memset ( V_13 , 0 , sizeof *V_13 ) ;
V_13 -> V_100 . V_201 = V_200 ;
V_13 -> V_100 . V_202 = V_203 ;
V_13 -> V_100 . V_204 = V_205 ;
F_21 ( & V_206 , V_3 ) ;
V_13 -> V_100 . V_207 =
F_87 ( ( ( T_3 ) V_22 -> V_208 ) << 32 | V_207 ++ ) ;
F_25 ( & V_206 , V_3 ) ;
}
static int F_88 ( struct V_1 * V_2 , int V_209 , T_4 V_196 )
{
bool V_210 = ! ! ( V_196 & V_211 ) ;
unsigned long V_3 ;
int V_57 , V_175 ;
if ( V_210 )
F_89 ( V_196 ) ;
F_21 ( & V_177 , V_3 ) ;
V_175 = F_90 ( & V_178 , V_2 , 0 , 0 , V_212 ) ;
F_25 ( & V_177 , V_3 ) ;
if ( V_210 )
F_91 () ;
if ( V_175 < 0 )
return V_175 ;
V_2 -> V_10 -> V_209 = V_209 ;
V_2 -> V_10 -> V_11 [ 0 ] = V_2 ;
V_2 -> V_175 = V_175 ;
if ( V_2 -> V_3 & V_4 ) {
if ( ! F_92 ( V_65 ) ) {
if ( ! F_18 ( V_2 ) )
return V_175 ;
}
F_1 ( V_2 ) ;
}
V_57 = F_41 ( V_2 -> V_10 , NULL ) ;
if ( V_57 ) {
F_21 ( & V_177 , V_3 ) ;
F_93 ( & V_178 , V_175 ) ;
F_25 ( & V_177 , V_3 ) ;
}
return V_57 ? V_57 : V_175 ;
}
void F_94 ( void * V_213 , struct V_8 * V_88 )
{
F_95 ( V_214 , F_96 ( V_214 ) , V_213 , V_88 ) ;
}
void F_97 ( struct V_8 * V_88 , void * V_213 )
{
F_98 ( V_214 , F_96 ( V_214 ) , V_88 , V_213 ) ;
}
static void F_99 ( struct V_1 * V_215 ,
int V_91 ,
struct V_12 * V_13 )
{
struct V_216 * V_2 =
F_48 ( V_215 , struct V_216 , V_215 ) ;
if ( V_13 ) {
struct V_8 V_88 ;
F_95 ( V_214 , F_96 ( V_214 ) ,
V_13 -> V_56 , & V_88 ) ;
V_88 . V_195 = 0xffff ;
memset ( V_88 . V_193 , 0 , V_194 ) ;
memset ( V_88 . V_217 , 0 , V_194 ) ;
V_2 -> V_92 ( V_91 , & V_88 , V_2 -> V_11 ) ;
} else
V_2 -> V_92 ( V_91 , NULL , V_2 -> V_11 ) ;
}
static void F_100 ( struct V_1 * V_215 )
{
F_50 ( F_48 ( V_215 , struct V_216 , V_215 ) ) ;
}
int F_101 ( struct V_171 * V_172 ,
struct V_179 * V_23 , V_53 V_26 ,
struct V_8 * V_88 ,
T_1 V_14 ,
int V_209 , T_4 V_196 ,
void (* V_92)( int V_91 ,
struct V_8 * V_218 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_215 )
{
struct V_216 * V_2 ;
struct V_165 * V_166 = F_76 ( V_23 , & V_180 ) ;
struct V_135 * V_21 ;
struct V_176 * V_22 ;
struct V_12 * V_13 ;
int V_57 ;
if ( ! V_166 )
return - V_219 ;
V_21 = & V_166 -> V_21 [ V_26 - V_166 -> V_169 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_102 ( sizeof( * V_2 ) , V_196 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_215 . V_21 = V_21 ;
V_57 = F_81 ( & V_2 -> V_215 , V_196 ) ;
if ( V_57 )
goto V_220;
F_103 ( V_172 ) ;
V_2 -> V_215 . V_172 = V_172 ;
V_2 -> V_92 = V_92 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_215 . V_10 -> V_13 ;
F_86 ( V_13 , V_22 ) ;
V_2 -> V_215 . V_92 = V_92 ? F_99 : NULL ;
V_2 -> V_215 . V_221 = F_100 ;
V_13 -> V_100 . V_101 = V_222 ;
V_13 -> V_100 . V_223 = F_104 ( V_224 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_98 ( V_214 , F_96 ( V_214 ) , V_88 , V_13 -> V_56 ) ;
* V_215 = & V_2 -> V_215 ;
V_2 -> V_215 . V_3 |= V_4 ;
V_2 -> V_215 . V_10 -> V_11 [ 1 ] = V_88 ;
V_57 = F_88 ( & V_2 -> V_215 , V_209 , V_196 ) ;
if ( V_57 < 0 )
goto V_225;
return V_57 ;
V_225:
* V_215 = NULL ;
F_70 ( V_2 -> V_215 . V_172 ) ;
F_84 ( & V_2 -> V_215 ) ;
V_220:
F_50 ( V_2 ) ;
return V_57 ;
}
static void F_105 ( struct V_1 * V_215 ,
int V_91 ,
struct V_12 * V_13 )
{
struct V_226 * V_2 =
F_48 ( V_215 , struct V_226 , V_215 ) ;
if ( V_13 ) {
struct V_227 V_88 ;
F_95 ( V_228 , F_96 ( V_228 ) ,
V_13 -> V_56 , & V_88 ) ;
V_2 -> V_92 ( V_91 , & V_88 , V_2 -> V_11 ) ;
} else
V_2 -> V_92 ( V_91 , NULL , V_2 -> V_11 ) ;
}
static void F_106 ( struct V_1 * V_215 )
{
F_50 ( F_48 ( V_215 , struct V_226 , V_215 ) ) ;
}
int F_107 ( struct V_171 * V_172 ,
struct V_179 * V_23 , V_53 V_26 , V_53 V_101 ,
struct V_227 * V_88 ,
T_1 V_14 ,
int V_209 , T_4 V_196 ,
void (* V_92)( int V_91 ,
struct V_227 * V_218 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_215 )
{
struct V_226 * V_2 ;
struct V_165 * V_166 = F_76 ( V_23 , & V_180 ) ;
struct V_135 * V_21 ;
struct V_176 * V_22 ;
struct V_12 * V_13 ;
int V_57 ;
if ( ! V_166 )
return - V_219 ;
V_21 = & V_166 -> V_21 [ V_26 - V_166 -> V_169 ] ;
V_22 = V_21 -> V_22 ;
if ( V_101 != V_222 &&
V_101 != V_229 &&
V_101 != V_230 )
return - V_231 ;
V_2 = F_102 ( sizeof( * V_2 ) , V_196 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_215 . V_21 = V_21 ;
V_57 = F_81 ( & V_2 -> V_215 , V_196 ) ;
if ( V_57 )
goto V_220;
F_103 ( V_172 ) ;
V_2 -> V_215 . V_172 = V_172 ;
V_2 -> V_92 = V_92 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_215 . V_10 -> V_13 ;
F_86 ( V_13 , V_22 ) ;
V_2 -> V_215 . V_92 = V_92 ? F_105 : NULL ;
V_2 -> V_215 . V_221 = F_106 ;
V_13 -> V_100 . V_101 = V_101 ;
V_13 -> V_100 . V_223 = F_104 ( V_232 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_98 ( V_228 , F_96 ( V_228 ) ,
V_88 , V_13 -> V_56 ) ;
* V_215 = & V_2 -> V_215 ;
V_57 = F_88 ( & V_2 -> V_215 , V_209 , V_196 ) ;
if ( V_57 < 0 )
goto V_225;
return V_57 ;
V_225:
* V_215 = NULL ;
F_70 ( V_2 -> V_215 . V_172 ) ;
F_84 ( & V_2 -> V_215 ) ;
V_220:
F_50 ( V_2 ) ;
return V_57 ;
}
static void F_108 ( struct V_1 * V_215 ,
int V_91 ,
struct V_12 * V_13 )
{
struct V_233 * V_2 =
F_48 ( V_215 , struct V_233 , V_215 ) ;
if ( V_13 ) {
struct V_234 V_88 ;
F_95 ( V_235 , F_96 ( V_235 ) ,
V_13 -> V_56 , & V_88 ) ;
V_2 -> V_92 ( V_91 , & V_88 , V_2 -> V_11 ) ;
} else
V_2 -> V_92 ( V_91 , NULL , V_2 -> V_11 ) ;
}
static void F_109 ( struct V_1 * V_215 )
{
F_50 ( F_48 ( V_215 , struct V_233 , V_215 ) ) ;
}
int F_110 ( struct V_171 * V_172 ,
struct V_179 * V_23 , V_53 V_26 ,
V_53 V_101 ,
struct V_234 * V_88 ,
T_1 V_14 ,
int V_209 , T_4 V_196 ,
void (* V_92)( int V_91 ,
struct V_234 * V_218 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_215 )
{
struct V_233 * V_2 ;
struct V_165 * V_166 = F_76 ( V_23 , & V_180 ) ;
struct V_135 * V_21 ;
struct V_176 * V_22 ;
struct V_12 * V_13 ;
int V_57 ;
if ( ! V_166 )
return - V_219 ;
V_21 = & V_166 -> V_21 [ V_26 - V_166 -> V_169 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_102 ( sizeof( * V_2 ) , V_196 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_215 . V_21 = V_21 ;
V_57 = F_81 ( & V_2 -> V_215 , V_196 ) ;
if ( V_57 )
goto V_220;
F_103 ( V_172 ) ;
V_2 -> V_215 . V_172 = V_172 ;
V_2 -> V_92 = V_92 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_215 . V_10 -> V_13 ;
F_86 ( V_13 , V_22 ) ;
V_2 -> V_215 . V_92 = V_92 ? F_108 : NULL ;
V_2 -> V_215 . V_221 = F_109 ;
V_13 -> V_100 . V_101 = V_101 ;
V_13 -> V_100 . V_223 = F_104 ( V_236 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_98 ( V_235 , F_96 ( V_235 ) ,
V_88 , V_13 -> V_56 ) ;
* V_215 = & V_2 -> V_215 ;
V_57 = F_88 ( & V_2 -> V_215 , V_209 , V_196 ) ;
if ( V_57 < 0 )
goto V_225;
return V_57 ;
V_225:
* V_215 = NULL ;
F_70 ( V_2 -> V_215 . V_172 ) ;
F_84 ( & V_2 -> V_215 ) ;
V_220:
F_50 ( V_2 ) ;
return V_57 ;
}
static void F_111 ( struct V_1 * V_215 ,
int V_91 ,
struct V_12 * V_13 )
{
struct V_237 * V_2 =
F_48 ( V_215 , struct V_237 , V_215 ) ;
if ( V_13 ) {
struct V_238 V_88 ;
F_95 ( V_239 , F_96 ( V_239 ) ,
V_13 -> V_56 , & V_88 ) ;
V_2 -> V_92 ( V_91 , & V_88 , V_2 -> V_11 ) ;
} else
V_2 -> V_92 ( V_91 , NULL , V_2 -> V_11 ) ;
}
static void F_112 ( struct V_1 * V_215 )
{
F_50 ( F_48 ( V_215 , struct V_237 , V_215 ) ) ;
}
int F_113 ( struct V_171 * V_172 ,
struct V_179 * V_23 , V_53 V_26 ,
struct V_238 * V_88 ,
T_1 V_14 , V_53 V_101 ,
int V_209 , T_4 V_196 ,
void (* V_92)( int V_91 ,
struct V_238 * V_218 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_215 )
{
struct V_237 * V_2 ;
struct V_165 * V_166 = F_76 ( V_23 , & V_180 ) ;
struct V_135 * V_21 ;
struct V_176 * V_22 ;
struct V_12 * V_13 ;
int V_57 ;
if ( ! V_166 )
return - V_219 ;
if ( V_101 != V_222 &&
V_101 != V_229 &&
V_101 != V_230 ) {
return - V_231 ;
}
V_21 = & V_166 -> V_21 [ V_26 - V_166 -> V_169 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_102 ( sizeof( * V_2 ) , V_196 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_215 . V_21 = V_21 ;
V_57 = F_81 ( & V_2 -> V_215 , V_196 ) ;
if ( V_57 )
goto V_220;
F_103 ( V_172 ) ;
V_2 -> V_215 . V_172 = V_172 ;
V_2 -> V_92 = V_92 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_215 . V_10 -> V_13 ;
F_86 ( V_13 , V_22 ) ;
V_2 -> V_215 . V_92 = V_92 ? F_111 : NULL ;
V_2 -> V_215 . V_221 = F_112 ;
V_13 -> V_100 . V_101 = V_101 ;
V_13 -> V_100 . V_223 = F_104 ( V_240 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_98 ( V_239 , F_96 ( V_239 ) , V_88 ,
V_13 -> V_56 ) ;
* V_215 = & V_2 -> V_215 ;
V_57 = F_88 ( & V_2 -> V_215 , V_209 , V_196 ) ;
if ( V_57 < 0 )
goto V_225;
return V_57 ;
V_225:
* V_215 = NULL ;
F_70 ( V_2 -> V_215 . V_172 ) ;
F_84 ( & V_2 -> V_215 ) ;
V_220:
F_50 ( V_2 ) ;
return V_57 ;
}
static void F_35 ( struct V_176 * V_22 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = V_83 -> V_104 -> V_11 [ 0 ] ;
unsigned long V_3 ;
if ( V_2 -> V_92 )
switch ( V_83 -> V_91 ) {
case V_105 :
break;
case V_241 :
V_2 -> V_92 ( V_2 , - V_242 , NULL ) ;
break;
case V_109 :
V_2 -> V_92 ( V_2 , - V_243 , NULL ) ;
break;
default:
V_2 -> V_92 ( V_2 , - V_71 , NULL ) ;
break;
}
F_21 ( & V_177 , V_3 ) ;
F_93 ( & V_178 , V_2 -> V_175 ) ;
F_25 ( & V_177 , V_3 ) ;
F_84 ( V_2 ) ;
F_70 ( V_2 -> V_172 ) ;
V_2 -> V_221 ( V_2 ) ;
}
static void F_114 ( struct V_176 * V_106 ,
struct V_244 * V_245 )
{
struct V_1 * V_2 ;
struct V_126 * V_10 ;
V_10 = ( void * ) ( unsigned long ) V_245 -> V_246 -> V_247 ;
V_2 = V_10 -> V_11 [ 0 ] ;
if ( V_2 -> V_92 ) {
if ( V_245 -> V_246 -> V_91 == V_105 )
V_2 -> V_92 ( V_2 ,
V_245 -> V_248 . V_13 -> V_100 . V_91 ?
- V_231 : 0 ,
(struct V_12 * ) V_245 -> V_248 . V_13 ) ;
else
V_2 -> V_92 ( V_2 , - V_71 , NULL ) ;
}
F_115 ( V_245 ) ;
}
static void F_116 ( struct V_179 * V_23 )
{
struct V_165 * V_166 ;
int V_249 , V_250 , V_251 ;
int V_252 = 0 ;
V_249 = F_117 ( V_23 ) ;
V_250 = F_118 ( V_23 ) ;
V_166 = F_102 ( sizeof *V_166 +
( V_250 - V_249 + 1 ) * sizeof ( struct V_135 ) ,
V_59 ) ;
if ( ! V_166 )
return;
V_166 -> V_169 = V_249 ;
V_166 -> V_253 = V_250 ;
for ( V_251 = 0 ; V_251 <= V_250 - V_249 ; ++ V_251 ) {
F_119 ( & V_166 -> V_21 [ V_251 ] . V_154 ) ;
if ( ! F_64 ( V_23 , V_251 + 1 ) )
continue;
V_166 -> V_21 [ V_251 ] . V_132 = NULL ;
V_166 -> V_21 [ V_251 ] . V_26 = V_251 + V_249 ;
V_166 -> V_21 [ V_251 ] . V_22 =
F_120 ( V_23 , V_251 + V_249 , V_254 ,
NULL , 0 , F_35 ,
F_114 , V_166 , 0 ) ;
if ( F_58 ( V_166 -> V_21 [ V_251 ] . V_22 ) )
goto V_255;
F_121 ( & V_166 -> V_21 [ V_251 ] . V_136 , F_51 ) ;
V_252 ++ ;
}
if ( ! V_252 )
goto free;
F_122 ( V_23 , & V_180 , V_166 ) ;
F_123 ( & V_166 -> V_167 , V_23 , F_62 ) ;
if ( F_124 ( & V_166 -> V_167 ) )
goto V_255;
for ( V_251 = 0 ; V_251 <= V_250 - V_249 ; ++ V_251 ) {
if ( F_64 ( V_23 , V_251 + 1 ) )
F_51 ( & V_166 -> V_21 [ V_251 ] . V_136 ) ;
}
return;
V_255:
while ( -- V_251 >= 0 ) {
if ( F_64 ( V_23 , V_251 + 1 ) )
F_125 ( V_166 -> V_21 [ V_251 ] . V_22 ) ;
}
free:
F_50 ( V_166 ) ;
return;
}
static void F_126 ( struct V_179 * V_23 , void * V_256 )
{
struct V_165 * V_166 = V_256 ;
int V_251 ;
if ( ! V_166 )
return;
F_127 ( & V_166 -> V_167 ) ;
F_128 ( V_170 ) ;
for ( V_251 = 0 ; V_251 <= V_166 -> V_253 - V_166 -> V_169 ; ++ V_251 ) {
if ( F_64 ( V_23 , V_251 + 1 ) ) {
F_125 ( V_166 -> V_21 [ V_251 ] . V_22 ) ;
if ( V_166 -> V_21 [ V_251 ] . V_132 )
F_60 ( & V_166 -> V_21 [ V_251 ] . V_132 -> V_133 , F_47 ) ;
}
}
F_50 ( V_166 ) ;
}
static int T_5 F_129 ( void )
{
int V_57 ;
F_130 ( & V_207 , sizeof V_207 ) ;
F_67 ( & V_69 , 0 ) ;
V_57 = F_131 ( & V_180 ) ;
if ( V_57 ) {
F_53 ( V_147 L_5 ) ;
goto V_220;
}
V_57 = F_132 () ;
if ( V_57 ) {
F_53 ( V_147 L_6 ) ;
goto V_225;
}
V_78 = F_133 ( L_7 ) ;
if ( ! V_78 ) {
V_57 = - V_60 ;
goto V_257;
}
if ( F_134 ( V_62 , V_258 ,
V_259 ) ) {
F_135 ( L_8 ) ;
V_57 = - V_231 ;
goto V_260;
}
F_136 ( & V_79 , F_36 ) ;
return 0 ;
V_260:
F_137 ( V_78 ) ;
V_257:
F_138 () ;
V_225:
F_139 ( & V_180 ) ;
V_220:
return V_57 ;
}
static void T_6 F_140 ( void )
{
F_141 ( V_62 ) ;
F_142 ( & V_79 ) ;
F_128 ( V_78 ) ;
F_137 ( V_78 ) ;
F_138 () ;
F_139 ( & V_180 ) ;
F_143 ( & V_178 ) ;
}
