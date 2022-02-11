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
static int F_12 ( struct V_1 * V_2 , T_4 V_54 )
{
struct V_6 * V_7 = NULL ;
struct V_55 * V_56 ;
void * V_57 ;
int V_58 = 0 ;
struct V_12 * V_13 ;
int V_51 ;
V_13 = V_2 -> V_10 -> V_13 ;
V_51 = F_9 ( V_13 -> V_15 . V_14 ) ;
if ( V_51 <= 0 )
return - V_59 ;
V_7 = F_13 ( V_51 , V_54 ) ;
if ( ! V_7 )
return - V_60 ;
V_57 = F_14 ( V_7 , & V_56 , V_2 -> V_61 , 0 , V_62 ,
V_63 , V_64 ) ;
if ( ! V_57 ) {
F_15 ( V_7 ) ;
return - V_59 ;
}
F_3 ( V_7 , V_2 ) ;
F_16 ( V_7 , V_56 ) ;
V_58 = F_17 ( V_7 , V_56 , V_65 , V_54 ) ;
if ( ! V_58 )
V_58 = V_51 ;
else
V_58 = 0 ;
return V_58 ;
}
static int F_18 ( struct V_1 * V_2 , T_4 V_54 )
{
unsigned long V_3 ;
unsigned long V_66 ;
int V_58 ;
F_19 ( & V_2 -> V_67 ) ;
V_2 -> V_61 = ( V_68 ) F_20 ( & V_69 ) ;
F_21 ( & V_70 , V_3 ) ;
V_66 = F_22 ( V_71 ) ;
V_2 -> V_72 = V_66 + V_73 ;
F_23 ( & V_2 -> V_67 , & V_74 ) ;
if ( V_74 . V_75 == & V_2 -> V_67 )
F_24 ( V_76 , & V_77 , V_66 ) ;
F_25 ( & V_70 , V_3 ) ;
V_58 = F_12 ( V_2 , V_54 ) ;
if ( V_58 <= 0 ) {
V_58 = - V_78 ;
F_21 ( & V_70 , V_3 ) ;
F_26 ( & V_2 -> V_67 ) ;
F_25 ( & V_70 , V_3 ) ;
} else {
V_58 = 0 ;
}
return V_58 ;
}
static int F_27 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_1 * V_79 ;
int V_80 = 0 ;
F_21 ( & V_70 , V_3 ) ;
F_28 (wait_query, &ib_nl_request_list, list) {
if ( V_2 == V_79 ) {
V_2 -> V_3 |= V_5 ;
V_2 -> V_72 = V_73 ;
F_29 ( & V_2 -> V_67 , & V_74 ) ;
V_80 = 1 ;
F_30 ( V_76 , & V_77 , 1 ) ;
break;
}
}
F_25 ( & V_70 , V_3 ) ;
return V_80 ;
}
static void F_31 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
struct V_81 V_82 ;
struct V_12 * V_13 = NULL ;
const struct V_83 * V_84 , * V_85 ;
struct V_86 * V_87 ;
int V_51 , V_88 ;
V_68 V_89 = 0 ;
int V_90 = - V_78 ;
if ( V_2 -> V_91 ) {
V_84 = ( const struct V_83 * ) F_32 ( V_56 ) ;
V_51 = F_33 ( V_56 ) ;
switch ( V_2 -> V_29 ) {
case V_31 :
V_89 = V_92 | V_93 ;
break;
case V_94 :
case V_30 :
default:
V_89 = V_92 | V_95 |
V_96 ;
break;
}
F_34 (curr, head, len, rem) {
if ( V_85 -> V_97 == V_98 ) {
V_87 = F_35 ( V_85 ) ;
if ( ( V_87 -> V_3 & V_89 ) == V_89 ) {
V_13 = V_2 -> V_10 -> V_13 ;
V_13 -> V_99 . V_100 |=
V_101 ;
memcpy ( V_13 -> V_57 , V_87 -> V_102 ,
sizeof( V_87 -> V_102 ) ) ;
V_90 = 0 ;
break;
}
}
}
V_2 -> V_91 ( V_2 , V_90 , V_13 ) ;
}
V_82 . V_103 = V_2 -> V_10 ;
V_82 . V_90 = V_104 ;
F_36 ( V_2 -> V_10 -> V_105 , & V_82 ) ;
}
static void F_37 ( struct V_106 * V_107 )
{
unsigned long V_3 ;
struct V_1 * V_2 ;
unsigned long V_66 ;
struct V_81 V_82 ;
int V_58 ;
F_21 ( & V_70 , V_3 ) ;
while ( ! F_38 ( & V_74 ) ) {
V_2 = F_39 ( V_74 . V_75 ,
struct V_1 , V_67 ) ;
if ( F_40 ( V_2 -> V_72 , V_73 ) ) {
V_66 = V_2 -> V_72 - V_73 ;
if ( ( long ) V_66 <= 0 )
V_66 = 1 ;
F_24 ( V_76 , & V_77 , V_66 ) ;
break;
}
F_26 ( & V_2 -> V_67 ) ;
F_1 ( V_2 ) ;
if ( F_2 ( V_2 ) )
V_58 = - 1 ;
else
V_58 = F_41 ( V_2 -> V_10 , NULL ) ;
if ( V_58 ) {
V_82 . V_103 = V_2 -> V_10 ;
V_82 . V_90 = V_108 ;
F_25 ( & V_70 , V_3 ) ;
F_36 ( V_2 -> V_21 -> V_22 , & V_82 ) ;
F_21 ( & V_70 , V_3 ) ;
}
}
F_25 ( & V_70 , V_3 ) ;
}
static int F_42 ( struct V_6 * V_7 ,
struct V_109 * V_110 )
{
const struct V_55 * V_56 = (struct V_55 * ) V_110 -> V_56 ;
int V_72 , V_111 , V_112 ;
const struct V_83 * V_113 ;
unsigned long V_3 ;
struct V_1 * V_2 ;
long V_66 = 0 ;
struct V_83 * V_114 [ V_115 ] ;
int V_58 ;
if ( ! F_43 ( V_7 , V_116 ) )
return - V_117 ;
V_58 = F_44 ( V_114 , V_115 - 1 , F_32 ( V_56 ) ,
F_33 ( V_56 ) , V_118 ) ;
V_113 = ( const struct V_83 * ) V_114 [ V_119 ] ;
if ( V_58 || ! V_113 )
goto V_120;
V_72 = * ( int * ) F_35 ( V_113 ) ;
if ( V_72 < V_121 )
V_72 = V_121 ;
if ( V_72 > V_122 )
V_72 = V_122 ;
V_111 = V_72 - V_71 ;
if ( V_111 < 0 )
V_112 = - V_111 ;
else
V_112 = V_111 ;
if ( V_111 != 0 ) {
F_21 ( & V_70 , V_3 ) ;
V_71 = V_72 ;
F_28 (query, &ib_nl_request_list, list) {
if ( V_111 < 0 && V_112 > V_2 -> V_72 )
V_2 -> V_72 = 0 ;
else
V_2 -> V_72 += V_111 ;
if ( ! V_66 ) {
V_66 = V_2 -> V_72 - V_73 ;
if ( V_66 <= 0 )
V_66 = 1 ;
}
}
if ( V_66 )
F_30 ( V_76 , & V_77 ,
( unsigned long ) V_66 ) ;
F_25 ( & V_70 , V_3 ) ;
}
V_120:
return V_7 -> V_51 ;
}
static inline int F_45 ( const struct V_55 * V_56 )
{
struct V_83 * V_114 [ V_115 ] ;
int V_58 ;
if ( V_56 -> V_123 & V_124 )
return 0 ;
V_58 = F_44 ( V_114 , V_115 - 1 , F_32 ( V_56 ) ,
F_33 ( V_56 ) , V_118 ) ;
if ( V_58 )
return 0 ;
return 1 ;
}
static int F_46 ( struct V_6 * V_7 ,
struct V_109 * V_110 )
{
const struct V_55 * V_56 = (struct V_55 * ) V_110 -> V_56 ;
unsigned long V_3 ;
struct V_1 * V_2 ;
struct V_125 * V_103 ;
struct V_81 V_82 ;
int V_80 = 0 ;
int V_58 ;
if ( ! F_43 ( V_7 , V_116 ) )
return - V_117 ;
F_21 ( & V_70 , V_3 ) ;
F_28 (query, &ib_nl_request_list, list) {
if ( V_56 -> V_126 == V_2 -> V_61 ) {
V_80 = ! F_2 ( V_2 ) ;
if ( V_80 )
F_26 ( & V_2 -> V_67 ) ;
break;
}
}
if ( ! V_80 ) {
F_25 ( & V_70 , V_3 ) ;
goto V_127;
}
V_103 = V_2 -> V_10 ;
if ( ! F_45 ( V_56 ) ) {
F_1 ( V_2 ) ;
V_58 = F_41 ( V_2 -> V_10 , NULL ) ;
F_25 ( & V_70 , V_3 ) ;
if ( V_58 ) {
V_82 . V_103 = V_103 ;
V_82 . V_90 = V_128 ;
F_36 ( V_2 -> V_21 -> V_22 , & V_82 ) ;
}
} else {
F_25 ( & V_70 , V_3 ) ;
F_31 ( V_2 , V_56 ) ;
}
V_127:
return V_7 -> V_51 ;
}
static void F_47 ( struct V_129 * V_129 )
{
struct V_130 * V_131 = F_48 ( V_129 , struct V_130 , V_132 ) ;
F_49 ( V_131 -> V_133 ) ;
F_50 ( V_131 ) ;
}
static void F_51 ( struct V_106 * V_107 )
{
struct V_134 * V_21 =
F_48 ( V_107 , struct V_134 , V_135 ) ;
struct V_130 * V_136 ;
struct V_137 V_138 ;
struct V_139 V_140 ;
if ( F_52 ( V_21 -> V_22 -> V_23 , V_21 -> V_26 , & V_138 ) ) {
F_53 ( V_141 L_1 ) ;
return;
}
V_136 = F_54 ( sizeof *V_136 , V_142 ) ;
if ( ! V_136 ) {
F_53 ( V_141 L_2 ) ;
return;
}
F_55 ( & V_136 -> V_132 ) ;
V_136 -> V_143 = ( 1 << V_138 . V_144 ) - 1 ;
V_136 -> V_145 = 0 ;
if ( F_56 ( V_21 -> V_22 -> V_23 , V_21 -> V_26 ,
V_146 , & V_136 -> V_145 ) )
F_53 ( V_147 L_3 ) ;
memset ( & V_140 , 0 , sizeof V_140 ) ;
V_140 . V_148 = V_138 . V_149 ;
V_140 . V_150 = V_138 . V_151 ;
V_140 . V_26 = V_21 -> V_26 ;
V_136 -> V_133 = F_57 ( V_21 -> V_22 -> V_152 -> V_153 , & V_140 ) ;
if ( F_58 ( V_136 -> V_133 ) ) {
F_53 ( V_141 L_4 ) ;
F_50 ( V_136 ) ;
return;
}
F_59 ( & V_21 -> V_154 ) ;
if ( V_21 -> V_131 )
F_60 ( & V_21 -> V_131 -> V_132 , F_47 ) ;
V_21 -> V_131 = V_136 ;
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
struct V_134 * V_21 =
& V_166 -> V_21 [ V_158 -> V_168 . V_26 - V_166 -> V_169 ] ;
if ( ! F_64 ( V_156 -> V_23 , V_21 -> V_26 ) )
return;
F_21 ( & V_21 -> V_154 , V_3 ) ;
if ( V_21 -> V_131 )
F_60 ( & V_21 -> V_131 -> V_132 , F_47 ) ;
V_21 -> V_131 = NULL ;
F_25 ( & V_21 -> V_154 , V_3 ) ;
F_65 ( V_170 , & V_166 -> V_21 [ V_158 -> V_168 . V_26 -
V_166 -> V_169 ] . V_135 ) ;
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
struct V_125 * V_10 ;
F_21 ( & V_177 , V_3 ) ;
if ( F_73 ( & V_178 , V_175 ) != V_2 ) {
F_25 ( & V_177 , V_3 ) ;
return;
}
V_22 = V_2 -> V_21 -> V_22 ;
V_10 = V_2 -> V_10 ;
F_25 ( & V_177 , V_3 ) ;
if ( ! F_27 ( V_2 ) )
F_74 ( V_22 , V_10 ) ;
}
static V_53 F_75 ( struct V_179 * V_23 , V_53 V_26 )
{
struct V_165 * V_166 ;
struct V_134 * V_21 ;
unsigned long V_3 ;
V_53 V_143 ;
V_166 = F_76 ( V_23 , & V_180 ) ;
if ( ! V_166 )
return 0x7f ;
V_21 = & V_166 -> V_21 [ V_26 - V_166 -> V_169 ] ;
F_21 ( & V_21 -> V_154 , V_3 ) ;
V_143 = V_21 -> V_131 ? V_21 -> V_131 -> V_143 : 0x7f ;
F_25 ( & V_21 -> V_154 , V_3 ) ;
return V_143 ;
}
int F_77 ( struct V_179 * V_23 , V_53 V_26 ,
struct V_8 * V_87 , struct V_139 * V_140 )
{
int V_58 ;
T_2 V_181 ;
int V_182 ;
memset ( V_140 , 0 , sizeof *V_140 ) ;
V_140 -> V_148 = F_8 ( V_87 -> V_148 ) ;
V_140 -> V_150 = V_87 -> V_150 ;
V_140 -> V_183 = F_8 ( V_87 -> V_184 ) &
F_75 ( V_23 , V_26 ) ;
V_140 -> V_26 = V_26 ;
V_140 -> V_185 = V_87 -> V_186 ;
V_182 = F_78 ( V_23 , V_26 ) ;
if ( V_87 -> V_187 > 1 || V_182 ) {
struct V_188 * V_189 = F_79 ( V_87 ) ;
V_140 -> V_190 = V_191 ;
V_140 -> V_192 . V_38 = V_87 -> V_38 ;
V_58 = F_80 ( V_23 , & V_87 -> V_41 , V_189 , & V_26 ,
& V_181 ) ;
if ( V_58 ) {
if ( V_189 )
F_81 ( V_189 ) ;
return V_58 ;
}
V_140 -> V_192 . V_193 = V_181 ;
V_140 -> V_192 . V_194 = F_82 ( V_87 -> V_194 ) ;
V_140 -> V_192 . V_187 = V_87 -> V_187 ;
V_140 -> V_192 . V_44 = V_87 -> V_44 ;
if ( V_189 )
F_81 ( V_189 ) ;
}
if ( V_182 ) {
memcpy ( V_140 -> V_195 , V_87 -> V_195 , V_196 ) ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , T_4 V_54 )
{
unsigned long V_3 ;
F_21 ( & V_2 -> V_21 -> V_154 , V_3 ) ;
if ( ! V_2 -> V_21 -> V_131 ) {
F_25 ( & V_2 -> V_21 -> V_154 , V_3 ) ;
return - V_197 ;
}
F_84 ( & V_2 -> V_21 -> V_131 -> V_132 ) ;
V_2 -> V_131 = V_2 -> V_21 -> V_131 ;
F_25 ( & V_2 -> V_21 -> V_154 , V_3 ) ;
V_2 -> V_10 = F_85 ( V_2 -> V_21 -> V_22 , 1 ,
V_2 -> V_131 -> V_145 ,
0 , V_198 , V_199 ,
V_54 ,
V_200 ) ;
if ( F_58 ( V_2 -> V_10 ) ) {
F_60 ( & V_2 -> V_131 -> V_132 , F_47 ) ;
return - V_60 ;
}
V_2 -> V_10 -> V_133 = V_2 -> V_131 -> V_133 ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_87 ( V_2 -> V_10 ) ;
F_60 ( & V_2 -> V_131 -> V_132 , F_47 ) ;
}
static void F_88 ( struct V_12 * V_13 , struct V_176 * V_22 )
{
unsigned long V_3 ;
memset ( V_13 , 0 , sizeof *V_13 ) ;
V_13 -> V_99 . V_201 = V_200 ;
V_13 -> V_99 . V_202 = V_203 ;
V_13 -> V_99 . V_204 = V_205 ;
F_21 ( & V_206 , V_3 ) ;
V_13 -> V_99 . V_207 =
F_89 ( ( ( T_3 ) V_22 -> V_208 ) << 32 | V_207 ++ ) ;
F_25 ( & V_206 , V_3 ) ;
}
static int F_90 ( struct V_1 * V_2 , int V_209 , T_4 V_54 )
{
bool V_210 = F_91 ( V_54 ) ;
unsigned long V_3 ;
int V_58 , V_175 ;
if ( V_210 )
F_92 ( V_54 ) ;
F_21 ( & V_177 , V_3 ) ;
V_175 = F_93 ( & V_178 , V_2 , 0 , 0 , V_211 ) ;
F_25 ( & V_177 , V_3 ) ;
if ( V_210 )
F_94 () ;
if ( V_175 < 0 )
return V_175 ;
V_2 -> V_10 -> V_209 = V_209 ;
V_2 -> V_10 -> V_11 [ 0 ] = V_2 ;
V_2 -> V_175 = V_175 ;
if ( V_2 -> V_3 & V_4 ) {
if ( ! F_95 ( V_65 ) ) {
if ( ! F_18 ( V_2 , V_54 ) )
return V_175 ;
}
F_1 ( V_2 ) ;
}
V_58 = F_41 ( V_2 -> V_10 , NULL ) ;
if ( V_58 ) {
F_21 ( & V_177 , V_3 ) ;
F_96 ( & V_178 , V_175 ) ;
F_25 ( & V_177 , V_3 ) ;
}
return V_58 ? V_58 : V_175 ;
}
void F_97 ( void * V_212 , struct V_8 * V_87 )
{
F_98 ( V_213 , F_99 ( V_213 ) , V_212 , V_87 ) ;
}
void F_100 ( struct V_8 * V_87 , void * V_212 )
{
F_101 ( V_213 , F_99 ( V_213 ) , V_87 , V_212 ) ;
}
static void F_102 ( struct V_1 * V_214 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_215 * V_2 =
F_48 ( V_214 , struct V_215 , V_214 ) ;
if ( V_13 ) {
struct V_8 V_87 ;
F_98 ( V_213 , F_99 ( V_213 ) ,
V_13 -> V_57 , & V_87 ) ;
V_87 . V_216 = NULL ;
V_87 . V_217 = 0 ;
memset ( V_87 . V_195 , 0 , V_196 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_103 ( struct V_1 * V_214 )
{
F_50 ( F_48 ( V_214 , struct V_215 , V_214 ) ) ;
}
int F_104 ( struct V_171 * V_172 ,
struct V_179 * V_23 , V_53 V_26 ,
struct V_8 * V_87 ,
T_1 V_14 ,
int V_209 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_8 * V_218 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_214 )
{
struct V_215 * V_2 ;
struct V_165 * V_166 = F_76 ( V_23 , & V_180 ) ;
struct V_134 * V_21 ;
struct V_176 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_166 )
return - V_219 ;
V_21 = & V_166 -> V_21 [ V_26 - V_166 -> V_169 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_105 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_214 . V_21 = V_21 ;
V_58 = F_83 ( & V_2 -> V_214 , V_54 ) ;
if ( V_58 )
goto V_220;
F_106 ( V_172 ) ;
V_2 -> V_214 . V_172 = V_172 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_214 . V_10 -> V_13 ;
F_88 ( V_13 , V_22 ) ;
V_2 -> V_214 . V_91 = V_91 ? F_102 : NULL ;
V_2 -> V_214 . V_221 = F_103 ;
V_13 -> V_99 . V_100 = V_222 ;
V_13 -> V_99 . V_223 = F_107 ( V_224 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_101 ( V_213 , F_99 ( V_213 ) , V_87 , V_13 -> V_57 ) ;
* V_214 = & V_2 -> V_214 ;
V_2 -> V_214 . V_3 |= V_4 ;
V_2 -> V_214 . V_10 -> V_11 [ 1 ] = V_87 ;
V_58 = F_90 ( & V_2 -> V_214 , V_209 , V_54 ) ;
if ( V_58 < 0 )
goto V_225;
return V_58 ;
V_225:
* V_214 = NULL ;
F_70 ( V_2 -> V_214 . V_172 ) ;
F_86 ( & V_2 -> V_214 ) ;
V_220:
F_50 ( V_2 ) ;
return V_58 ;
}
static void F_108 ( struct V_1 * V_214 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_226 * V_2 =
F_48 ( V_214 , struct V_226 , V_214 ) ;
if ( V_13 ) {
struct V_227 V_87 ;
F_98 ( V_228 , F_99 ( V_228 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_109 ( struct V_1 * V_214 )
{
F_50 ( F_48 ( V_214 , struct V_226 , V_214 ) ) ;
}
int F_110 ( struct V_171 * V_172 ,
struct V_179 * V_23 , V_53 V_26 , V_53 V_100 ,
struct V_227 * V_87 ,
T_1 V_14 ,
int V_209 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_227 * V_218 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_214 )
{
struct V_226 * V_2 ;
struct V_165 * V_166 = F_76 ( V_23 , & V_180 ) ;
struct V_134 * V_21 ;
struct V_176 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_166 )
return - V_219 ;
V_21 = & V_166 -> V_21 [ V_26 - V_166 -> V_169 ] ;
V_22 = V_21 -> V_22 ;
if ( V_100 != V_222 &&
V_100 != V_229 &&
V_100 != V_230 )
return - V_231 ;
V_2 = F_105 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_214 . V_21 = V_21 ;
V_58 = F_83 ( & V_2 -> V_214 , V_54 ) ;
if ( V_58 )
goto V_220;
F_106 ( V_172 ) ;
V_2 -> V_214 . V_172 = V_172 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_214 . V_10 -> V_13 ;
F_88 ( V_13 , V_22 ) ;
V_2 -> V_214 . V_91 = V_91 ? F_108 : NULL ;
V_2 -> V_214 . V_221 = F_109 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_223 = F_107 ( V_232 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_101 ( V_228 , F_99 ( V_228 ) ,
V_87 , V_13 -> V_57 ) ;
* V_214 = & V_2 -> V_214 ;
V_58 = F_90 ( & V_2 -> V_214 , V_209 , V_54 ) ;
if ( V_58 < 0 )
goto V_225;
return V_58 ;
V_225:
* V_214 = NULL ;
F_70 ( V_2 -> V_214 . V_172 ) ;
F_86 ( & V_2 -> V_214 ) ;
V_220:
F_50 ( V_2 ) ;
return V_58 ;
}
static void F_111 ( struct V_1 * V_214 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_233 * V_2 =
F_48 ( V_214 , struct V_233 , V_214 ) ;
if ( V_13 ) {
struct V_234 V_87 ;
F_98 ( V_235 , F_99 ( V_235 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_112 ( struct V_1 * V_214 )
{
F_50 ( F_48 ( V_214 , struct V_233 , V_214 ) ) ;
}
int F_113 ( struct V_171 * V_172 ,
struct V_179 * V_23 , V_53 V_26 ,
V_53 V_100 ,
struct V_234 * V_87 ,
T_1 V_14 ,
int V_209 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_234 * V_218 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_214 )
{
struct V_233 * V_2 ;
struct V_165 * V_166 = F_76 ( V_23 , & V_180 ) ;
struct V_134 * V_21 ;
struct V_176 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_166 )
return - V_219 ;
V_21 = & V_166 -> V_21 [ V_26 - V_166 -> V_169 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_105 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_214 . V_21 = V_21 ;
V_58 = F_83 ( & V_2 -> V_214 , V_54 ) ;
if ( V_58 )
goto V_220;
F_106 ( V_172 ) ;
V_2 -> V_214 . V_172 = V_172 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_214 . V_10 -> V_13 ;
F_88 ( V_13 , V_22 ) ;
V_2 -> V_214 . V_91 = V_91 ? F_111 : NULL ;
V_2 -> V_214 . V_221 = F_112 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_223 = F_107 ( V_236 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_101 ( V_235 , F_99 ( V_235 ) ,
V_87 , V_13 -> V_57 ) ;
* V_214 = & V_2 -> V_214 ;
V_58 = F_90 ( & V_2 -> V_214 , V_209 , V_54 ) ;
if ( V_58 < 0 )
goto V_225;
return V_58 ;
V_225:
* V_214 = NULL ;
F_70 ( V_2 -> V_214 . V_172 ) ;
F_86 ( & V_2 -> V_214 ) ;
V_220:
F_50 ( V_2 ) ;
return V_58 ;
}
static void F_114 ( struct V_1 * V_214 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_237 * V_2 =
F_48 ( V_214 , struct V_237 , V_214 ) ;
if ( V_13 ) {
struct V_238 V_87 ;
F_98 ( V_239 , F_99 ( V_239 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_115 ( struct V_1 * V_214 )
{
F_50 ( F_48 ( V_214 , struct V_237 , V_214 ) ) ;
}
int F_116 ( struct V_171 * V_172 ,
struct V_179 * V_23 , V_53 V_26 ,
struct V_238 * V_87 ,
T_1 V_14 , V_53 V_100 ,
int V_209 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_238 * V_218 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_214 )
{
struct V_237 * V_2 ;
struct V_165 * V_166 = F_76 ( V_23 , & V_180 ) ;
struct V_134 * V_21 ;
struct V_176 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_166 )
return - V_219 ;
if ( V_100 != V_222 &&
V_100 != V_229 &&
V_100 != V_230 ) {
return - V_231 ;
}
V_21 = & V_166 -> V_21 [ V_26 - V_166 -> V_169 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_105 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_214 . V_21 = V_21 ;
V_58 = F_83 ( & V_2 -> V_214 , V_54 ) ;
if ( V_58 )
goto V_220;
F_106 ( V_172 ) ;
V_2 -> V_214 . V_172 = V_172 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_214 . V_10 -> V_13 ;
F_88 ( V_13 , V_22 ) ;
V_2 -> V_214 . V_91 = V_91 ? F_114 : NULL ;
V_2 -> V_214 . V_221 = F_115 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_223 = F_107 ( V_240 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_101 ( V_239 , F_99 ( V_239 ) , V_87 ,
V_13 -> V_57 ) ;
* V_214 = & V_2 -> V_214 ;
V_58 = F_90 ( & V_2 -> V_214 , V_209 , V_54 ) ;
if ( V_58 < 0 )
goto V_225;
return V_58 ;
V_225:
* V_214 = NULL ;
F_70 ( V_2 -> V_214 . V_172 ) ;
F_86 ( & V_2 -> V_214 ) ;
V_220:
F_50 ( V_2 ) ;
return V_58 ;
}
static void F_36 ( struct V_176 * V_22 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_103 -> V_11 [ 0 ] ;
unsigned long V_3 ;
if ( V_2 -> V_91 )
switch ( V_82 -> V_90 ) {
case V_104 :
break;
case V_241 :
V_2 -> V_91 ( V_2 , - V_242 , NULL ) ;
break;
case V_108 :
V_2 -> V_91 ( V_2 , - V_243 , NULL ) ;
break;
default:
V_2 -> V_91 ( V_2 , - V_78 , NULL ) ;
break;
}
F_21 ( & V_177 , V_3 ) ;
F_96 ( & V_178 , V_2 -> V_175 ) ;
F_25 ( & V_177 , V_3 ) ;
F_86 ( V_2 ) ;
F_70 ( V_2 -> V_172 ) ;
V_2 -> V_221 ( V_2 ) ;
}
static void F_117 ( struct V_176 * V_105 ,
struct V_244 * V_245 )
{
struct V_1 * V_2 ;
struct V_125 * V_10 ;
V_10 = ( void * ) ( unsigned long ) V_245 -> V_246 -> V_247 ;
V_2 = V_10 -> V_11 [ 0 ] ;
if ( V_2 -> V_91 ) {
if ( V_245 -> V_246 -> V_90 == V_104 )
V_2 -> V_91 ( V_2 ,
V_245 -> V_248 . V_13 -> V_99 . V_90 ?
- V_231 : 0 ,
(struct V_12 * ) V_245 -> V_248 . V_13 ) ;
else
V_2 -> V_91 ( V_2 , - V_78 , NULL ) ;
}
F_118 ( V_245 ) ;
}
static void F_119 ( struct V_179 * V_23 )
{
struct V_165 * V_166 ;
int V_249 , V_250 , V_251 ;
int V_252 = 0 ;
V_249 = F_120 ( V_23 ) ;
V_250 = F_121 ( V_23 ) ;
V_166 = F_105 ( sizeof *V_166 +
( V_250 - V_249 + 1 ) * sizeof ( struct V_134 ) ,
V_142 ) ;
if ( ! V_166 )
return;
V_166 -> V_169 = V_249 ;
V_166 -> V_253 = V_250 ;
for ( V_251 = 0 ; V_251 <= V_250 - V_249 ; ++ V_251 ) {
F_122 ( & V_166 -> V_21 [ V_251 ] . V_154 ) ;
if ( ! F_64 ( V_23 , V_251 + 1 ) )
continue;
V_166 -> V_21 [ V_251 ] . V_131 = NULL ;
V_166 -> V_21 [ V_251 ] . V_26 = V_251 + V_249 ;
V_166 -> V_21 [ V_251 ] . V_22 =
F_123 ( V_23 , V_251 + V_249 , V_254 ,
NULL , 0 , F_36 ,
F_117 , V_166 , 0 ) ;
if ( F_58 ( V_166 -> V_21 [ V_251 ] . V_22 ) )
goto V_255;
F_124 ( & V_166 -> V_21 [ V_251 ] . V_135 , F_51 ) ;
V_252 ++ ;
}
if ( ! V_252 )
goto free;
F_125 ( V_23 , & V_180 , V_166 ) ;
F_126 ( & V_166 -> V_167 , V_23 , F_62 ) ;
if ( F_127 ( & V_166 -> V_167 ) )
goto V_255;
for ( V_251 = 0 ; V_251 <= V_250 - V_249 ; ++ V_251 ) {
if ( F_64 ( V_23 , V_251 + 1 ) )
F_51 ( & V_166 -> V_21 [ V_251 ] . V_135 ) ;
}
return;
V_255:
while ( -- V_251 >= 0 ) {
if ( F_64 ( V_23 , V_251 + 1 ) )
F_128 ( V_166 -> V_21 [ V_251 ] . V_22 ) ;
}
free:
F_50 ( V_166 ) ;
return;
}
static void F_129 ( struct V_179 * V_23 , void * V_256 )
{
struct V_165 * V_166 = V_256 ;
int V_251 ;
if ( ! V_166 )
return;
F_130 ( & V_166 -> V_167 ) ;
F_131 ( V_170 ) ;
for ( V_251 = 0 ; V_251 <= V_166 -> V_253 - V_166 -> V_169 ; ++ V_251 ) {
if ( F_64 ( V_23 , V_251 + 1 ) ) {
F_128 ( V_166 -> V_21 [ V_251 ] . V_22 ) ;
if ( V_166 -> V_21 [ V_251 ] . V_131 )
F_60 ( & V_166 -> V_21 [ V_251 ] . V_131 -> V_132 , F_47 ) ;
}
}
F_50 ( V_166 ) ;
}
static int T_5 F_132 ( void )
{
int V_58 ;
F_133 ( & V_207 , sizeof V_207 ) ;
F_67 ( & V_69 , 0 ) ;
V_58 = F_134 ( & V_180 ) ;
if ( V_58 ) {
F_53 ( V_147 L_5 ) ;
goto V_220;
}
V_58 = F_135 () ;
if ( V_58 ) {
F_53 ( V_147 L_6 ) ;
goto V_225;
}
V_76 = F_136 ( L_7 ) ;
if ( ! V_76 ) {
V_58 = - V_60 ;
goto V_257;
}
if ( F_137 ( V_62 , V_258 ,
V_259 ) ) {
F_138 ( L_8 ) ;
V_58 = - V_231 ;
goto V_260;
}
F_139 ( & V_77 , F_37 ) ;
return 0 ;
V_260:
F_140 ( V_76 ) ;
V_257:
F_141 () ;
V_225:
F_142 ( & V_180 ) ;
V_220:
return V_58 ;
}
static void T_6 F_143 ( void )
{
F_144 ( V_62 ) ;
F_145 ( & V_77 ) ;
F_131 ( V_76 ) ;
F_140 ( V_76 ) ;
F_141 () ;
F_142 ( & V_180 ) ;
F_146 ( & V_178 ) ;
}
