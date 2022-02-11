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
V_19 = F_4 ( V_7 , F_5 ( sizeof( * V_19 ) ) ) ;
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
int F_42 ( struct V_6 * V_7 ,
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
if ( ! ( V_56 -> V_116 & V_64 ) ||
! ( F_43 ( V_7 ) . V_117 ) ||
! F_44 ( V_7 , V_118 ) )
return - V_119 ;
V_58 = F_45 ( V_114 , V_115 - 1 , F_32 ( V_56 ) ,
F_33 ( V_56 ) , V_120 , NULL ) ;
V_113 = ( const struct V_83 * ) V_114 [ V_121 ] ;
if ( V_58 || ! V_113 )
goto V_122;
V_72 = * ( int * ) F_35 ( V_113 ) ;
if ( V_72 < V_123 )
V_72 = V_123 ;
if ( V_72 > V_124 )
V_72 = V_124 ;
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
V_122:
return V_7 -> V_51 ;
}
static inline int F_46 ( const struct V_55 * V_56 )
{
struct V_83 * V_114 [ V_115 ] ;
int V_58 ;
if ( V_56 -> V_116 & V_125 )
return 0 ;
V_58 = F_45 ( V_114 , V_115 - 1 , F_32 ( V_56 ) ,
F_33 ( V_56 ) , V_120 , NULL ) ;
if ( V_58 )
return 0 ;
return 1 ;
}
int F_47 ( struct V_6 * V_7 ,
struct V_109 * V_110 )
{
const struct V_55 * V_56 = (struct V_55 * ) V_110 -> V_56 ;
unsigned long V_3 ;
struct V_1 * V_2 ;
struct V_126 * V_103 ;
struct V_81 V_82 ;
int V_80 = 0 ;
int V_58 ;
if ( ( V_56 -> V_116 & V_64 ) ||
! ( F_43 ( V_7 ) . V_117 ) ||
! F_44 ( V_7 , V_118 ) )
return - V_119 ;
F_21 ( & V_70 , V_3 ) ;
F_28 (query, &ib_nl_request_list, list) {
if ( V_56 -> V_127 == V_2 -> V_61 ) {
V_80 = ! F_2 ( V_2 ) ;
if ( V_80 )
F_26 ( & V_2 -> V_67 ) ;
break;
}
}
if ( ! V_80 ) {
F_25 ( & V_70 , V_3 ) ;
goto V_128;
}
V_103 = V_2 -> V_10 ;
if ( ! F_46 ( V_56 ) ) {
F_1 ( V_2 ) ;
V_58 = F_41 ( V_2 -> V_10 , NULL ) ;
F_25 ( & V_70 , V_3 ) ;
if ( V_58 ) {
V_82 . V_103 = V_103 ;
V_82 . V_90 = V_129 ;
F_36 ( V_2 -> V_21 -> V_22 , & V_82 ) ;
}
} else {
F_25 ( & V_70 , V_3 ) ;
F_31 ( V_2 , V_56 ) ;
}
V_128:
return V_7 -> V_51 ;
}
static void F_48 ( struct V_130 * V_130 )
{
struct V_131 * V_132 = F_49 ( V_130 , struct V_131 , V_133 ) ;
F_50 ( V_132 -> V_134 ) ;
F_51 ( V_132 ) ;
}
void F_52 ( struct V_135 * V_136 )
{
F_53 ( & V_136 -> V_137 , 1 ) ;
F_54 ( & V_136 -> V_138 ) ;
}
void F_55 ( struct V_135 * V_136 )
{
F_56 ( V_136 ) ;
F_57 ( & V_136 -> V_138 ) ;
}
void F_58 ( int V_139 , struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_140 * V_22 ;
struct V_126 * V_10 ;
F_21 ( & V_141 , V_3 ) ;
if ( F_59 ( & V_142 , V_139 ) != V_2 ) {
F_25 ( & V_141 , V_3 ) ;
return;
}
V_22 = V_2 -> V_21 -> V_22 ;
V_10 = V_2 -> V_10 ;
F_25 ( & V_141 , V_3 ) ;
if ( ! F_27 ( V_2 ) )
F_60 ( V_22 , V_10 ) ;
}
static V_53 F_61 ( struct V_143 * V_23 , V_53 V_26 )
{
struct V_144 * V_145 ;
struct V_146 * V_21 ;
unsigned long V_3 ;
V_53 V_147 ;
V_145 = F_62 ( V_23 , & V_148 ) ;
if ( ! V_145 )
return 0x7f ;
V_21 = & V_145 -> V_21 [ V_26 - V_145 -> V_149 ] ;
F_21 ( & V_21 -> V_150 , V_3 ) ;
V_147 = V_21 -> V_132 ? V_21 -> V_132 -> V_147 : 0x7f ;
F_25 ( & V_21 -> V_150 , V_3 ) ;
return V_147 ;
}
int F_63 ( struct V_143 * V_23 , V_53 V_26 ,
struct V_8 * V_87 ,
struct V_151 * V_152 )
{
int V_58 ;
T_2 V_153 ;
int V_154 ;
struct V_155 * V_156 = NULL ;
memset ( V_152 , 0 , sizeof *V_152 ) ;
V_152 -> type = F_64 ( V_23 , V_26 ) ;
F_65 ( V_152 , F_66 ( F_67 ( V_87 ) ) ) ;
F_68 ( V_152 , V_87 -> V_157 ) ;
F_69 ( V_152 , F_66 ( F_70 ( V_87 ) ) &
F_61 ( V_23 , V_26 ) ) ;
F_71 ( V_152 , V_26 ) ;
F_72 ( V_152 , V_87 -> V_158 ) ;
V_154 = F_73 ( V_23 , V_26 ) ;
if ( V_154 ) {
struct V_155 * V_159 ;
struct V_155 * V_160 ;
struct V_161 V_162 = {
. V_163 = ( ( F_74 ( V_87 ) >= 0 ) ?
F_74 ( V_87 ) : 0 ) ,
. V_164 = F_75 ( V_87 ) ?
F_75 ( V_87 ) :
& V_165
} ;
union {
struct V_166 V_167 ;
struct V_168 V_169 ;
struct V_170 V_171 ;
} V_172 , V_173 ;
if ( ! V_23 -> V_174 )
return - V_175 ;
F_76 ( & V_172 . V_167 , & V_87 -> V_41 ) ;
F_76 ( & V_173 . V_167 , & V_87 -> V_38 ) ;
V_58 = F_77 ( & V_172 . V_167 ,
& V_173 . V_167 , & V_162 ) ;
if ( V_58 )
return V_58 ;
if ( ( V_162 . V_176 == V_177 ||
V_162 . V_176 == V_178 ) &&
V_87 -> V_179 != V_180 )
return - V_181 ;
V_159 = V_23 -> V_174 ( V_23 , V_26 ) ;
if ( ! V_159 )
return - V_182 ;
V_160 = F_78 ( V_162 . V_164 ,
V_162 . V_163 ) ;
if ( V_160 -> V_3 & V_183 ) {
F_79 ( V_160 ) ;
V_160 = V_159 ;
F_80 ( V_160 ) ;
}
V_156 = F_81 ( V_87 ) ;
F_82 () ;
if ( ( V_156 && V_156 != V_160 ) ||
( V_160 != V_159 &&
! F_83 ( V_159 , V_160 ) ) )
V_58 = - V_184 ;
F_84 () ;
F_79 ( V_159 ) ;
F_79 ( V_160 ) ;
if ( V_58 ) {
if ( V_156 )
F_79 ( V_156 ) ;
return V_58 ;
}
}
if ( V_87 -> V_185 > 0 || V_154 ) {
enum V_186 type = F_85 ( V_87 ) ;
V_58 = F_86 ( V_23 , & V_87 -> V_41 , type ,
V_26 , V_156 , & V_153 ) ;
if ( V_58 ) {
if ( V_156 )
F_79 ( V_156 ) ;
return V_58 ;
}
F_87 ( V_152 , & V_87 -> V_38 ,
F_66 ( V_87 -> V_187 ) ,
V_153 , V_87 -> V_185 ,
V_87 -> V_44 ) ;
if ( V_156 )
F_79 ( V_156 ) ;
}
if ( V_154 ) {
V_53 * V_188 = F_88 ( V_87 ) ;
if ( ! V_188 )
return - V_181 ;
memcpy ( V_152 -> V_189 . V_188 , V_188 , V_190 ) ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , T_4 V_54 )
{
unsigned long V_3 ;
F_21 ( & V_2 -> V_21 -> V_150 , V_3 ) ;
if ( ! V_2 -> V_21 -> V_132 ) {
F_25 ( & V_2 -> V_21 -> V_150 , V_3 ) ;
return - V_191 ;
}
F_90 ( & V_2 -> V_21 -> V_132 -> V_133 ) ;
V_2 -> V_132 = V_2 -> V_21 -> V_132 ;
F_25 ( & V_2 -> V_21 -> V_150 , V_3 ) ;
V_2 -> V_10 = F_91 ( V_2 -> V_21 -> V_22 , 1 ,
V_2 -> V_132 -> V_192 ,
0 , V_193 , V_194 ,
V_54 ,
( ( V_2 -> V_3 & V_195 ) ?
V_196 :
V_197 ) ) ;
if ( F_92 ( V_2 -> V_10 ) ) {
F_93 ( & V_2 -> V_132 -> V_133 , F_48 ) ;
return - V_60 ;
}
V_2 -> V_10 -> V_134 = V_2 -> V_132 -> V_134 ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 )
{
F_95 ( V_2 -> V_10 ) ;
F_93 ( & V_2 -> V_132 -> V_133 , F_48 ) ;
}
static void F_96 ( struct V_1 * V_2 , struct V_140 * V_22 )
{
struct V_12 * V_13 = V_2 -> V_10 -> V_13 ;
unsigned long V_3 ;
memset ( V_13 , 0 , sizeof *V_13 ) ;
if ( V_2 -> V_3 & V_195 ) {
V_13 -> V_99 . V_198 = V_196 ;
V_13 -> V_99 . V_199 = V_200 ;
} else {
V_13 -> V_99 . V_198 = V_197 ;
V_13 -> V_99 . V_199 = V_201 ;
}
V_13 -> V_99 . V_202 = V_203 ;
F_21 ( & V_204 , V_3 ) ;
V_13 -> V_99 . V_205 =
F_97 ( ( ( T_3 ) V_22 -> V_206 ) << 32 | V_205 ++ ) ;
F_25 ( & V_204 , V_3 ) ;
}
static int F_98 ( struct V_1 * V_2 , int V_207 , T_4 V_54 )
{
bool V_208 = F_99 ( V_54 ) ;
unsigned long V_3 ;
int V_58 , V_139 ;
if ( V_208 )
F_100 ( V_54 ) ;
F_21 ( & V_141 , V_3 ) ;
V_139 = F_101 ( & V_142 , V_2 , 0 , 0 , V_209 ) ;
F_25 ( & V_141 , V_3 ) ;
if ( V_208 )
F_102 () ;
if ( V_139 < 0 )
return V_139 ;
V_2 -> V_10 -> V_207 = V_207 ;
V_2 -> V_10 -> V_11 [ 0 ] = V_2 ;
V_2 -> V_139 = V_139 ;
if ( ( V_2 -> V_3 & V_4 ) &&
( ! ( V_2 -> V_3 & V_195 ) ) ) {
if ( ! F_103 ( V_65 ) ) {
if ( ! F_18 ( V_2 , V_54 ) )
return V_139 ;
}
F_1 ( V_2 ) ;
}
V_58 = F_41 ( V_2 -> V_10 , NULL ) ;
if ( V_58 ) {
F_21 ( & V_141 , V_3 ) ;
F_104 ( & V_142 , V_139 ) ;
F_25 ( & V_141 , V_3 ) ;
}
return V_58 ? V_58 : V_139 ;
}
void F_105 ( void * V_210 , struct V_8 * V_87 )
{
F_106 ( V_211 , F_107 ( V_211 ) , V_210 , V_87 ) ;
}
void F_108 ( struct V_8 * V_87 , void * V_210 )
{
F_109 ( V_211 , F_107 ( V_211 ) , V_87 , V_210 ) ;
}
static bool F_110 ( struct V_135 * V_136 ,
struct V_143 * V_23 ,
V_53 V_26 )
{
struct V_144 * V_145 = F_62 ( V_23 , & V_148 ) ;
struct V_146 * V_21 ;
unsigned long V_3 ;
bool V_58 = false ;
if ( ! V_145 )
return V_58 ;
V_21 = & V_145 -> V_21 [ V_26 - V_145 -> V_149 ] ;
F_21 ( & V_21 -> V_212 , V_3 ) ;
if ( ! V_21 -> V_213 . V_214 )
goto V_58;
if ( V_21 -> V_213 . V_57 . type == V_215 )
V_58 = F_111 ( & V_21 -> V_213 . V_57 . V_216 ) &
V_217 ;
V_58:
F_25 ( & V_21 -> V_212 , V_3 ) ;
return V_58 ;
}
static int F_112 ( struct V_135 * V_136 ,
struct V_143 * V_23 ,
V_53 V_26 ,
struct V_8 * V_87 )
{
struct V_218 V_219 ;
if ( F_113 ( V_23 , V_26 , & V_219 ) )
return V_220 ;
if ( F_110 ( V_136 , V_23 , V_26 ) )
return V_221 ;
if ( V_219 . V_222 >= F_8 ( V_223 ) )
return V_220 ;
else
return V_224 ;
}
static void F_114 ( struct V_1 * V_225 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_226 * V_2 =
F_49 ( V_225 , struct V_226 , V_225 ) ;
if ( V_13 ) {
struct V_8 V_87 ;
if ( V_225 -> V_3 & V_195 ) {
F_106 ( V_227 ,
F_107 ( V_227 ) ,
V_13 -> V_57 , & V_87 ) ;
V_87 . V_179 = V_228 ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else {
F_106 ( V_211 ,
F_107 ( V_211 ) ,
V_13 -> V_57 , & V_87 ) ;
V_87 . V_179 = V_229 ;
F_115 ( & V_87 , NULL ) ;
F_116 ( & V_87 , 0 ) ;
F_117 ( & V_87 ) ;
if ( V_2 -> V_230 ) {
struct V_8 V_216 ;
memset ( & V_216 , 0 , sizeof( struct V_8 ) ) ;
F_118 ( & V_216 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_216 , V_2 -> V_11 ) ;
} else {
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
}
}
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_119 ( struct V_1 * V_225 )
{
struct V_226 * V_2 =
F_49 ( V_225 , struct V_226 , V_225 ) ;
F_51 ( V_2 -> V_230 ) ;
F_51 ( V_2 ) ;
}
int F_120 ( struct V_135 * V_136 ,
struct V_143 * V_23 , V_53 V_26 ,
struct V_8 * V_87 ,
T_1 V_14 ,
int V_207 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_8 * V_231 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_225 )
{
struct V_226 * V_2 ;
struct V_144 * V_145 = F_62 ( V_23 , & V_148 ) ;
struct V_146 * V_21 ;
struct V_140 * V_22 ;
struct V_12 * V_13 ;
enum V_232 V_90 ;
int V_58 ;
if ( ! V_145 )
return - V_182 ;
if ( ( V_87 -> V_179 != V_229 ) &&
( V_87 -> V_179 != V_228 ) )
return - V_181 ;
V_21 = & V_145 -> V_21 [ V_26 - V_145 -> V_149 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_121 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_225 . V_21 = V_21 ;
if ( V_87 -> V_179 == V_228 ) {
V_90 = F_112 ( V_136 , V_23 , V_26 , V_87 ) ;
if ( V_90 == V_220 ) {
V_58 = - V_181 ;
goto V_233;
} else if ( V_90 == V_221 ) {
V_2 -> V_225 . V_3 |= V_195 ;
} else {
V_2 -> V_230 =
F_122 ( sizeof( * V_2 -> V_230 ) , V_54 ) ;
if ( ! V_2 -> V_230 ) {
V_58 = - V_60 ;
goto V_233;
}
}
}
V_58 = F_89 ( & V_2 -> V_225 , V_54 ) ;
if ( V_58 )
goto V_234;
F_123 ( V_136 ) ;
V_2 -> V_225 . V_136 = V_136 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_225 . V_10 -> V_13 ;
F_96 ( & V_2 -> V_225 , V_22 ) ;
V_2 -> V_225 . V_91 = V_91 ? F_114 : NULL ;
V_2 -> V_225 . V_235 = F_119 ;
V_13 -> V_99 . V_100 = V_236 ;
V_13 -> V_99 . V_237 = F_124 ( V_238 ) ;
V_13 -> V_15 . V_14 = V_14 ;
if ( V_2 -> V_225 . V_3 & V_195 ) {
F_109 ( V_227 , F_107 ( V_227 ) ,
V_87 , V_13 -> V_57 ) ;
} else if ( V_2 -> V_230 ) {
F_125 ( V_2 -> V_230 , V_87 ) ;
F_109 ( V_211 , F_107 ( V_211 ) ,
V_2 -> V_230 , V_13 -> V_57 ) ;
} else {
F_109 ( V_211 , F_107 ( V_211 ) ,
V_87 , V_13 -> V_57 ) ;
}
* V_225 = & V_2 -> V_225 ;
V_2 -> V_225 . V_3 |= V_4 ;
V_2 -> V_225 . V_10 -> V_11 [ 1 ] = ( V_2 -> V_230 ) ?
V_2 -> V_230 : V_87 ;
V_58 = F_98 ( & V_2 -> V_225 , V_207 , V_54 ) ;
if ( V_58 < 0 )
goto V_239;
return V_58 ;
V_239:
* V_225 = NULL ;
F_56 ( V_2 -> V_225 . V_136 ) ;
F_94 ( & V_2 -> V_225 ) ;
V_234:
F_51 ( V_2 -> V_230 ) ;
V_233:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_126 ( struct V_1 * V_225 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_240 * V_2 =
F_49 ( V_225 , struct V_240 , V_225 ) ;
if ( V_13 ) {
struct V_241 V_87 ;
F_106 ( V_242 , F_107 ( V_242 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_127 ( struct V_1 * V_225 )
{
F_51 ( F_49 ( V_225 , struct V_240 , V_225 ) ) ;
}
int F_128 ( struct V_135 * V_136 ,
struct V_143 * V_23 , V_53 V_26 , V_53 V_100 ,
struct V_241 * V_87 ,
T_1 V_14 ,
int V_207 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_241 * V_231 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_225 )
{
struct V_240 * V_2 ;
struct V_144 * V_145 = F_62 ( V_23 , & V_148 ) ;
struct V_146 * V_21 ;
struct V_140 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_145 )
return - V_182 ;
V_21 = & V_145 -> V_21 [ V_26 - V_145 -> V_149 ] ;
V_22 = V_21 -> V_22 ;
if ( V_100 != V_236 &&
V_100 != V_243 &&
V_100 != V_244 )
return - V_181 ;
V_2 = F_121 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_225 . V_21 = V_21 ;
V_58 = F_89 ( & V_2 -> V_225 , V_54 ) ;
if ( V_58 )
goto V_233;
F_123 ( V_136 ) ;
V_2 -> V_225 . V_136 = V_136 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_225 . V_10 -> V_13 ;
F_96 ( & V_2 -> V_225 , V_22 ) ;
V_2 -> V_225 . V_91 = V_91 ? F_126 : NULL ;
V_2 -> V_225 . V_235 = F_127 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_237 = F_124 ( V_245 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_109 ( V_242 , F_107 ( V_242 ) ,
V_87 , V_13 -> V_57 ) ;
* V_225 = & V_2 -> V_225 ;
V_58 = F_98 ( & V_2 -> V_225 , V_207 , V_54 ) ;
if ( V_58 < 0 )
goto V_234;
return V_58 ;
V_234:
* V_225 = NULL ;
F_56 ( V_2 -> V_225 . V_136 ) ;
F_94 ( & V_2 -> V_225 ) ;
V_233:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_129 ( struct V_1 * V_225 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_246 * V_2 =
F_49 ( V_225 , struct V_246 , V_225 ) ;
if ( V_13 ) {
struct V_247 V_87 ;
F_106 ( V_248 , F_107 ( V_248 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_130 ( struct V_1 * V_225 )
{
F_51 ( F_49 ( V_225 , struct V_246 , V_225 ) ) ;
}
int F_131 ( struct V_135 * V_136 ,
struct V_143 * V_23 , V_53 V_26 ,
V_53 V_100 ,
struct V_247 * V_87 ,
T_1 V_14 ,
int V_207 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_247 * V_231 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_225 )
{
struct V_246 * V_2 ;
struct V_144 * V_145 = F_62 ( V_23 , & V_148 ) ;
struct V_146 * V_21 ;
struct V_140 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_145 )
return - V_182 ;
V_21 = & V_145 -> V_21 [ V_26 - V_145 -> V_149 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_121 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_225 . V_21 = V_21 ;
V_58 = F_89 ( & V_2 -> V_225 , V_54 ) ;
if ( V_58 )
goto V_233;
F_123 ( V_136 ) ;
V_2 -> V_225 . V_136 = V_136 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_225 . V_10 -> V_13 ;
F_96 ( & V_2 -> V_225 , V_22 ) ;
V_2 -> V_225 . V_91 = V_91 ? F_129 : NULL ;
V_2 -> V_225 . V_235 = F_130 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_237 = F_124 ( V_249 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_109 ( V_248 , F_107 ( V_248 ) ,
V_87 , V_13 -> V_57 ) ;
* V_225 = & V_2 -> V_225 ;
V_58 = F_98 ( & V_2 -> V_225 , V_207 , V_54 ) ;
if ( V_58 < 0 )
goto V_234;
return V_58 ;
V_234:
* V_225 = NULL ;
F_56 ( V_2 -> V_225 . V_136 ) ;
F_94 ( & V_2 -> V_225 ) ;
V_233:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_132 ( struct V_1 * V_225 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_250 * V_2 =
F_49 ( V_225 , struct V_250 , V_225 ) ;
if ( V_13 ) {
struct V_251 V_87 ;
F_106 ( V_252 , F_107 ( V_252 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_133 ( struct V_1 * V_225 )
{
F_51 ( F_49 ( V_225 , struct V_250 , V_225 ) ) ;
}
int F_134 ( struct V_135 * V_136 ,
struct V_143 * V_23 , V_53 V_26 ,
struct V_251 * V_87 ,
T_1 V_14 , V_53 V_100 ,
int V_207 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_251 * V_231 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_225 )
{
struct V_250 * V_2 ;
struct V_144 * V_145 = F_62 ( V_23 , & V_148 ) ;
struct V_146 * V_21 ;
struct V_140 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_145 )
return - V_182 ;
if ( V_100 != V_236 &&
V_100 != V_243 &&
V_100 != V_244 ) {
return - V_181 ;
}
V_21 = & V_145 -> V_21 [ V_26 - V_145 -> V_149 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_121 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_225 . V_21 = V_21 ;
V_58 = F_89 ( & V_2 -> V_225 , V_54 ) ;
if ( V_58 )
goto V_233;
F_123 ( V_136 ) ;
V_2 -> V_225 . V_136 = V_136 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_225 . V_10 -> V_13 ;
F_96 ( & V_2 -> V_225 , V_22 ) ;
V_2 -> V_225 . V_91 = V_91 ? F_132 : NULL ;
V_2 -> V_225 . V_235 = F_133 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_237 = F_124 ( V_253 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_109 ( V_252 , F_107 ( V_252 ) , V_87 ,
V_13 -> V_57 ) ;
* V_225 = & V_2 -> V_225 ;
V_58 = F_98 ( & V_2 -> V_225 , V_207 , V_54 ) ;
if ( V_58 < 0 )
goto V_234;
return V_58 ;
V_234:
* V_225 = NULL ;
F_56 ( V_2 -> V_225 . V_136 ) ;
F_94 ( & V_2 -> V_225 ) ;
V_233:
F_51 ( V_2 ) ;
return V_58 ;
}
bool F_135 ( struct V_135 * V_136 ,
struct V_143 * V_23 ,
V_53 V_26 )
{
struct V_144 * V_145 = F_62 ( V_23 , & V_148 ) ;
struct V_146 * V_21 ;
bool V_58 = false ;
unsigned long V_3 ;
if ( ! V_145 )
return V_58 ;
V_21 = & V_145 -> V_21 [ V_26 - V_145 -> V_149 ] ;
F_21 ( & V_21 -> V_212 , V_3 ) ;
if ( ( V_21 -> V_213 . V_214 ) &&
( V_21 -> V_213 . V_57 . type == V_254 ) )
V_58 = F_136 ( & V_21 -> V_213 . V_57 . V_255 )
& V_256 ;
F_25 ( & V_21 -> V_212 , V_3 ) ;
return V_58 ;
}
static void F_137 ( void * V_11 )
{
struct V_257 * V_258 = V_11 ;
F_138 ( & V_258 -> V_259 ) ;
}
static void F_139 ( struct V_1 * V_225 ,
int V_90 ,
struct V_12 * V_13 )
{
unsigned long V_3 ;
struct V_260 * V_2 =
F_49 ( V_225 , struct V_260 , V_225 ) ;
struct V_261 * V_262 = & V_225 -> V_21 -> V_213 ;
if ( V_13 ) {
if ( V_225 -> V_3 & V_195 ) {
struct V_263 V_87 ;
F_106 ( V_264 ,
F_107 ( V_264 ) ,
V_13 -> V_57 , & V_87 ) ;
F_21 ( & V_225 -> V_21 -> V_212 ,
V_3 ) ;
if ( ! V_90 && ! V_262 -> V_214 ) {
memcpy ( & V_262 -> V_57 . V_216 , & V_87 ,
sizeof( V_262 -> V_57 . V_216 ) ) ;
V_262 -> V_214 = true ;
V_262 -> V_57 . type = V_215 ;
}
F_25 ( & V_225 -> V_21 -> V_212 ,
V_3 ) ;
} else {
struct V_265 V_87 ;
F_106 ( V_266 ,
F_107 ( V_266 ) ,
V_13 -> V_57 , & V_87 ) ;
F_21 ( & V_225 -> V_21 -> V_212 ,
V_3 ) ;
if ( ! V_90 && ! V_262 -> V_214 ) {
memcpy ( & V_262 -> V_57 . V_255 , & V_87 ,
sizeof( V_262 -> V_57 . V_255 ) ) ;
V_262 -> V_214 = true ;
V_262 -> V_57 . type = V_254 ;
}
F_25 ( & V_225 -> V_21 -> V_212 ,
V_3 ) ;
}
}
V_2 -> V_91 ( V_2 -> V_11 ) ;
}
static void F_140 ( struct V_1 * V_225 )
{
F_51 ( F_49 ( V_225 , struct V_260 ,
V_225 ) ) ;
}
static int F_141 ( struct V_146 * V_21 ,
int V_207 ,
void (* V_91)( void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_225 )
{
struct V_140 * V_22 ;
struct V_260 * V_2 ;
struct V_12 * V_13 ;
T_4 V_54 = V_267 ;
int V_58 ;
V_22 = V_21 -> V_22 ;
V_2 = F_121 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_225 . V_21 = V_21 ;
V_2 -> V_225 . V_3 |= F_142 ( V_21 -> V_22 -> V_23 ,
V_21 -> V_26 ) ?
V_195 : 0 ;
V_58 = F_89 ( & V_2 -> V_225 , V_54 ) ;
if ( V_58 )
goto V_268;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_225 . V_10 -> V_13 ;
F_96 ( & V_2 -> V_225 , V_22 ) ;
V_2 -> V_225 . V_91 = F_139 ;
V_2 -> V_225 . V_235 = F_140 ;
V_13 -> V_99 . V_100 = V_236 ;
V_13 -> V_99 . V_237 = F_124 ( V_269 ) ;
V_13 -> V_15 . V_14 = 0 ;
* V_225 = & V_2 -> V_225 ;
V_58 = F_98 ( & V_2 -> V_225 , V_207 , V_54 ) ;
if ( V_58 < 0 )
goto V_270;
return V_58 ;
V_270:
* V_225 = NULL ;
F_94 ( & V_2 -> V_225 ) ;
V_268:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_143 ( struct V_106 * V_107 )
{
struct V_146 * V_21 =
F_49 ( V_107 , struct V_146 , V_271 . V_107 ) ;
struct V_257 * V_272 ;
unsigned long V_3 ;
int V_58 ;
F_21 ( & V_21 -> V_212 , V_3 ) ;
if ( V_21 -> V_213 . V_214 ) {
F_25 ( & V_21 -> V_212 , V_3 ) ;
return;
}
F_25 ( & V_21 -> V_212 , V_3 ) ;
V_272 = F_122 ( sizeof( * V_272 ) , V_267 ) ;
if ( ! V_272 )
goto V_273;
F_54 ( & V_272 -> V_259 ) ;
V_58 = F_141 ( V_21 , 3000 ,
F_137 , V_272 ,
& V_272 -> V_225 ) ;
if ( V_58 < 0 )
goto V_274;
F_57 ( & V_272 -> V_259 ) ;
V_274:
F_51 ( V_272 ) ;
F_21 ( & V_21 -> V_212 , V_3 ) ;
if ( ! V_21 -> V_213 . V_214 ) {
V_21 -> V_213 . V_275 ++ ;
if ( V_21 -> V_213 . V_275 <=
V_276 ) {
unsigned long V_66 =
F_22 ( V_277 ) ;
F_24 ( V_278 , & V_21 -> V_271 , V_66 ) ;
}
}
F_25 ( & V_21 -> V_212 , V_3 ) ;
V_273:
return;
}
static void F_36 ( struct V_140 * V_22 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_103 -> V_11 [ 0 ] ;
unsigned long V_3 ;
if ( V_2 -> V_91 )
switch ( V_82 -> V_90 ) {
case V_104 :
break;
case V_279 :
V_2 -> V_91 ( V_2 , - V_280 , NULL ) ;
break;
case V_108 :
V_2 -> V_91 ( V_2 , - V_281 , NULL ) ;
break;
default:
V_2 -> V_91 ( V_2 , - V_78 , NULL ) ;
break;
}
F_21 ( & V_141 , V_3 ) ;
F_104 ( & V_142 , V_2 -> V_139 ) ;
F_25 ( & V_141 , V_3 ) ;
F_94 ( V_2 ) ;
if ( V_2 -> V_136 )
F_56 ( V_2 -> V_136 ) ;
V_2 -> V_235 ( V_2 ) ;
}
static void F_144 ( struct V_140 * V_105 ,
struct V_126 * V_103 ,
struct V_282 * V_283 )
{
struct V_1 * V_2 ;
if ( ! V_103 )
return;
V_2 = V_103 -> V_11 [ 0 ] ;
if ( V_2 -> V_91 ) {
if ( V_283 -> V_284 -> V_90 == V_104 )
V_2 -> V_91 ( V_2 ,
V_283 -> V_285 . V_13 -> V_99 . V_90 ?
- V_181 : 0 ,
(struct V_12 * ) V_283 -> V_285 . V_13 ) ;
else
V_2 -> V_91 ( V_2 , - V_78 , NULL ) ;
}
F_145 ( V_283 ) ;
}
static void F_146 ( struct V_106 * V_107 )
{
struct V_146 * V_21 =
F_49 ( V_107 , struct V_146 , V_286 ) ;
struct V_131 * V_287 ;
struct V_218 V_219 ;
struct V_151 V_152 ;
if ( F_113 ( V_21 -> V_22 -> V_23 , V_21 -> V_26 , & V_219 ) ) {
F_147 ( L_1 ) ;
return;
}
V_287 = F_122 ( sizeof( * V_287 ) , V_267 ) ;
if ( ! V_287 )
return;
F_148 ( & V_287 -> V_133 ) ;
V_287 -> V_147 = ( 1 << V_219 . V_288 ) - 1 ;
V_287 -> V_192 = 0 ;
if ( F_149 ( V_21 -> V_22 -> V_23 , V_21 -> V_26 ,
V_289 , & V_287 -> V_192 ) )
F_150 ( L_2 ) ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_152 . type = F_64 ( V_21 -> V_22 -> V_23 ,
V_21 -> V_26 ) ;
F_65 ( & V_152 , V_219 . V_290 ) ;
F_68 ( & V_152 , V_219 . V_291 ) ;
F_71 ( & V_152 , V_21 -> V_26 ) ;
if ( V_219 . V_292 ) {
F_151 ( & V_152 , V_293 ) ;
F_152 ( & V_152 ,
F_97 ( V_219 . V_294 ) ) ;
F_153 ( & V_152 ,
F_97 ( V_295 ) ) ;
}
V_287 -> V_134 = F_154 ( V_21 -> V_22 -> V_296 -> V_297 , & V_152 ) ;
if ( F_92 ( V_287 -> V_134 ) ) {
F_147 ( L_3 ) ;
F_51 ( V_287 ) ;
return;
}
F_155 ( & V_21 -> V_150 ) ;
if ( V_21 -> V_132 )
F_93 ( & V_21 -> V_132 -> V_133 , F_48 ) ;
V_21 -> V_132 = V_287 ;
F_156 ( & V_21 -> V_150 ) ;
}
static void F_157 ( struct V_298 * V_299 ,
struct V_300 * V_301 )
{
if ( V_301 -> V_301 == V_302 ||
V_301 -> V_301 == V_303 ||
V_301 -> V_301 == V_304 ||
V_301 -> V_301 == V_305 ||
V_301 -> V_301 == V_306 ||
V_301 -> V_301 == V_307 ) {
unsigned long V_3 ;
struct V_144 * V_145 =
F_49 ( V_299 , F_158 ( * V_145 ) , V_308 ) ;
V_53 V_26 = V_301 -> V_309 . V_26 - V_145 -> V_149 ;
struct V_146 * V_21 = & V_145 -> V_21 [ V_26 ] ;
if ( ! F_159 ( V_299 -> V_23 , V_21 -> V_26 ) )
return;
F_21 ( & V_21 -> V_150 , V_3 ) ;
if ( V_21 -> V_132 )
F_93 ( & V_21 -> V_132 -> V_133 , F_48 ) ;
V_21 -> V_132 = NULL ;
F_25 ( & V_21 -> V_150 , V_3 ) ;
if ( V_301 -> V_301 == V_306 ||
V_301 -> V_301 == V_307 ||
V_301 -> V_301 == V_304 ||
V_301 -> V_301 == V_303 ) {
unsigned long V_66 =
F_22 ( V_277 ) ;
F_21 ( & V_21 -> V_212 , V_3 ) ;
V_21 -> V_213 . V_214 = false ;
V_21 -> V_213 . V_275 = 0 ;
F_25 ( & V_21 -> V_212 , V_3 ) ;
F_24 ( V_278 ,
& V_21 -> V_271 , V_66 ) ;
}
F_160 ( V_278 , & V_145 -> V_21 [ V_26 ] . V_286 ) ;
}
}
static void F_161 ( struct V_143 * V_23 )
{
struct V_144 * V_145 ;
int V_310 , V_311 , V_312 ;
int V_313 = 0 ;
V_310 = F_162 ( V_23 ) ;
V_311 = F_163 ( V_23 ) ;
V_145 = F_121 ( sizeof *V_145 +
( V_311 - V_310 + 1 ) * sizeof ( struct V_146 ) ,
V_267 ) ;
if ( ! V_145 )
return;
V_145 -> V_149 = V_310 ;
V_145 -> V_314 = V_311 ;
for ( V_312 = 0 ; V_312 <= V_311 - V_310 ; ++ V_312 ) {
F_164 ( & V_145 -> V_21 [ V_312 ] . V_150 ) ;
if ( ! F_159 ( V_23 , V_312 + 1 ) )
continue;
V_145 -> V_21 [ V_312 ] . V_132 = NULL ;
V_145 -> V_21 [ V_312 ] . V_26 = V_312 + V_310 ;
F_164 ( & V_145 -> V_21 [ V_312 ] . V_212 ) ;
V_145 -> V_21 [ V_312 ] . V_213 . V_214 = false ;
V_145 -> V_21 [ V_312 ] . V_22 =
F_165 ( V_23 , V_312 + V_310 , V_315 ,
NULL , 0 , F_36 ,
F_144 , V_145 , 0 ) ;
if ( F_92 ( V_145 -> V_21 [ V_312 ] . V_22 ) )
goto V_316;
F_166 ( & V_145 -> V_21 [ V_312 ] . V_286 , F_146 ) ;
F_167 ( & V_145 -> V_21 [ V_312 ] . V_271 ,
F_143 ) ;
V_313 ++ ;
}
if ( ! V_313 )
goto free;
F_168 ( V_23 , & V_148 , V_145 ) ;
F_169 ( & V_145 -> V_308 , V_23 , F_157 ) ;
if ( F_170 ( & V_145 -> V_308 ) )
goto V_316;
for ( V_312 = 0 ; V_312 <= V_311 - V_310 ; ++ V_312 ) {
if ( F_159 ( V_23 , V_312 + 1 ) )
F_146 ( & V_145 -> V_21 [ V_312 ] . V_286 ) ;
}
return;
V_316:
while ( -- V_312 >= 0 ) {
if ( F_159 ( V_23 , V_312 + 1 ) )
F_171 ( V_145 -> V_21 [ V_312 ] . V_22 ) ;
}
free:
F_51 ( V_145 ) ;
return;
}
static void F_172 ( struct V_143 * V_23 , void * V_317 )
{
struct V_144 * V_145 = V_317 ;
int V_312 ;
if ( ! V_145 )
return;
F_173 ( & V_145 -> V_308 ) ;
F_174 ( V_278 ) ;
for ( V_312 = 0 ; V_312 <= V_145 -> V_314 - V_145 -> V_149 ; ++ V_312 ) {
if ( F_159 ( V_23 , V_312 + 1 ) ) {
F_175 ( & V_145 -> V_21 [ V_312 ] . V_271 ) ;
F_171 ( V_145 -> V_21 [ V_312 ] . V_22 ) ;
if ( V_145 -> V_21 [ V_312 ] . V_132 )
F_93 ( & V_145 -> V_21 [ V_312 ] . V_132 -> V_133 , F_48 ) ;
}
}
F_51 ( V_145 ) ;
}
int F_176 ( void )
{
int V_58 ;
F_177 ( & V_205 , sizeof V_205 ) ;
F_53 ( & V_69 , 0 ) ;
V_58 = F_178 ( & V_148 ) ;
if ( V_58 ) {
F_150 ( L_4 ) ;
goto V_233;
}
V_58 = F_179 () ;
if ( V_58 ) {
F_150 ( L_5 ) ;
goto V_234;
}
V_76 = F_180 ( L_6 , V_318 ) ;
if ( ! V_76 ) {
V_58 = - V_60 ;
goto V_239;
}
F_167 ( & V_77 , F_37 ) ;
return 0 ;
V_239:
F_181 () ;
V_234:
F_182 ( & V_148 ) ;
V_233:
return V_58 ;
}
void F_183 ( void )
{
F_184 ( & V_77 ) ;
F_174 ( V_76 ) ;
F_185 ( V_76 ) ;
F_181 () ;
F_182 ( & V_148 ) ;
F_186 ( & V_142 ) ;
}
