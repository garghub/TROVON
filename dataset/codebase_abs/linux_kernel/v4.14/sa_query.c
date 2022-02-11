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
V_58 = F_17 ( V_7 , V_65 , V_54 ) ;
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
struct V_55 * V_56 ,
struct V_109 * V_110 )
{
int V_72 , V_111 , V_112 ;
const struct V_83 * V_113 ;
unsigned long V_3 ;
struct V_1 * V_2 ;
long V_66 = 0 ;
struct V_83 * V_114 [ V_115 ] ;
int V_58 ;
if ( ! ( V_56 -> V_116 & V_64 ) ||
! ( F_43 ( V_7 ) . V_117 ) )
return - V_118 ;
V_58 = F_44 ( V_114 , V_115 - 1 , F_32 ( V_56 ) ,
F_33 ( V_56 ) , V_119 , NULL ) ;
V_113 = ( const struct V_83 * ) V_114 [ V_120 ] ;
if ( V_58 || ! V_113 )
goto V_121;
V_72 = * ( int * ) F_35 ( V_113 ) ;
if ( V_72 < V_122 )
V_72 = V_122 ;
if ( V_72 > V_123 )
V_72 = V_123 ;
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
V_121:
return V_7 -> V_51 ;
}
static inline int F_45 ( const struct V_55 * V_56 )
{
struct V_83 * V_114 [ V_115 ] ;
int V_58 ;
if ( V_56 -> V_116 & V_124 )
return 0 ;
V_58 = F_44 ( V_114 , V_115 - 1 , F_32 ( V_56 ) ,
F_33 ( V_56 ) , V_119 , NULL ) ;
if ( V_58 )
return 0 ;
return 1 ;
}
int F_46 ( struct V_6 * V_7 ,
struct V_55 * V_56 ,
struct V_109 * V_110 )
{
unsigned long V_3 ;
struct V_1 * V_2 ;
struct V_125 * V_103 ;
struct V_81 V_82 ;
int V_80 = 0 ;
int V_58 ;
if ( ( V_56 -> V_116 & V_64 ) ||
! ( F_43 ( V_7 ) . V_117 ) )
return - V_118 ;
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
void F_51 ( struct V_134 * V_135 )
{
F_52 ( & V_135 -> V_136 , 1 ) ;
F_53 ( & V_135 -> V_137 ) ;
}
void F_54 ( struct V_134 * V_135 )
{
F_55 ( V_135 ) ;
F_56 ( & V_135 -> V_137 ) ;
}
void F_57 ( int V_138 , struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_139 * V_22 ;
struct V_125 * V_10 ;
F_21 ( & V_140 , V_3 ) ;
if ( F_58 ( & V_141 , V_138 ) != V_2 ) {
F_25 ( & V_140 , V_3 ) ;
return;
}
V_22 = V_2 -> V_21 -> V_22 ;
V_10 = V_2 -> V_10 ;
F_25 ( & V_140 , V_3 ) ;
if ( ! F_27 ( V_2 ) )
F_59 ( V_22 , V_10 ) ;
}
static V_53 F_60 ( struct V_142 * V_23 , V_53 V_26 )
{
struct V_143 * V_144 ;
struct V_145 * V_21 ;
unsigned long V_3 ;
V_53 V_146 ;
V_144 = F_61 ( V_23 , & V_147 ) ;
if ( ! V_144 )
return 0x7f ;
V_21 = & V_144 -> V_21 [ V_26 - V_144 -> V_148 ] ;
F_21 ( & V_21 -> V_149 , V_3 ) ;
V_146 = V_21 -> V_131 ? V_21 -> V_131 -> V_146 : 0x7f ;
F_25 ( & V_21 -> V_149 , V_3 ) ;
return V_146 ;
}
int F_62 ( struct V_142 * V_23 , V_53 V_26 ,
struct V_8 * V_87 ,
struct V_150 * V_151 )
{
int V_58 ;
T_2 V_152 ;
int V_153 ;
struct V_154 * V_155 = NULL ;
memset ( V_151 , 0 , sizeof *V_151 ) ;
V_151 -> type = F_63 ( V_23 , V_26 ) ;
F_64 ( V_151 , F_65 ( F_66 ( V_87 ) ) ) ;
if ( ( V_151 -> type == V_156 ) &&
( F_67 ( V_151 ) == F_8 ( V_157 ) ) )
F_68 ( V_151 , true ) ;
F_69 ( V_151 , V_87 -> V_158 ) ;
F_70 ( V_151 , F_65 ( F_71 ( V_87 ) ) &
F_60 ( V_23 , V_26 ) ) ;
F_72 ( V_151 , V_26 ) ;
F_73 ( V_151 , V_87 -> V_159 ) ;
V_153 = F_74 ( V_23 , V_26 ) ;
if ( V_153 ) {
struct V_154 * V_160 ;
struct V_154 * V_161 ;
struct V_162 V_163 = {
. V_164 = ( ( F_75 ( V_87 ) >= 0 ) ?
F_75 ( V_87 ) : 0 ) ,
. V_165 = F_76 ( V_87 ) ?
F_76 ( V_87 ) :
& V_166
} ;
union {
struct V_167 V_168 ;
struct V_169 V_170 ;
struct V_171 V_172 ;
} V_173 , V_174 ;
if ( ! V_23 -> V_175 )
return - V_176 ;
F_77 ( & V_173 . V_168 , & V_87 -> V_41 ) ;
F_77 ( & V_174 . V_168 , & V_87 -> V_38 ) ;
V_58 = F_78 ( & V_173 . V_168 ,
& V_174 . V_168 , & V_163 ) ;
if ( V_58 )
return V_58 ;
if ( ( V_163 . V_177 == V_178 ||
V_163 . V_177 == V_179 ) &&
V_87 -> V_180 != V_181 )
return - V_182 ;
V_160 = V_23 -> V_175 ( V_23 , V_26 ) ;
if ( ! V_160 )
return - V_183 ;
V_161 = F_79 ( V_163 . V_165 ,
V_163 . V_164 ) ;
if ( V_161 -> V_3 & V_184 ) {
F_80 ( V_161 ) ;
V_161 = V_160 ;
F_81 ( V_161 ) ;
}
V_155 = F_82 ( V_87 ) ;
F_83 () ;
if ( ( V_155 && V_155 != V_161 ) ||
( V_161 != V_160 &&
! F_84 ( V_160 , V_161 ) ) )
V_58 = - V_185 ;
F_85 () ;
F_80 ( V_160 ) ;
F_80 ( V_161 ) ;
if ( V_58 ) {
if ( V_155 )
F_80 ( V_155 ) ;
return V_58 ;
}
}
if ( V_87 -> V_186 > 0 || V_153 ) {
enum V_187 type = F_86 ( V_87 ) ;
V_58 = F_87 ( V_23 , & V_87 -> V_41 , type ,
V_26 , V_155 , & V_152 ) ;
if ( V_58 ) {
if ( V_155 )
F_80 ( V_155 ) ;
return V_58 ;
}
F_88 ( V_151 , & V_87 -> V_38 ,
F_65 ( V_87 -> V_188 ) ,
V_152 , V_87 -> V_186 ,
V_87 -> V_44 ) ;
if ( V_155 )
F_80 ( V_155 ) ;
}
if ( V_153 ) {
V_53 * V_189 = F_89 ( V_87 ) ;
if ( ! V_189 )
return - V_182 ;
memcpy ( V_151 -> V_190 . V_189 , V_189 , V_191 ) ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , T_4 V_54 )
{
unsigned long V_3 ;
F_21 ( & V_2 -> V_21 -> V_149 , V_3 ) ;
if ( ! V_2 -> V_21 -> V_131 ) {
F_25 ( & V_2 -> V_21 -> V_149 , V_3 ) ;
return - V_192 ;
}
F_91 ( & V_2 -> V_21 -> V_131 -> V_132 ) ;
V_2 -> V_131 = V_2 -> V_21 -> V_131 ;
F_25 ( & V_2 -> V_21 -> V_149 , V_3 ) ;
V_2 -> V_10 = F_92 ( V_2 -> V_21 -> V_22 , 1 ,
V_2 -> V_131 -> V_193 ,
0 , V_194 , V_195 ,
V_54 ,
( ( V_2 -> V_3 & V_196 ) ?
V_197 :
V_198 ) ) ;
if ( F_93 ( V_2 -> V_10 ) ) {
F_94 ( & V_2 -> V_131 -> V_132 , F_47 ) ;
return - V_60 ;
}
V_2 -> V_10 -> V_133 = V_2 -> V_131 -> V_133 ;
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
F_96 ( V_2 -> V_10 ) ;
F_94 ( & V_2 -> V_131 -> V_132 , F_47 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_139 * V_22 )
{
struct V_12 * V_13 = V_2 -> V_10 -> V_13 ;
unsigned long V_3 ;
memset ( V_13 , 0 , sizeof *V_13 ) ;
if ( V_2 -> V_3 & V_196 ) {
V_13 -> V_99 . V_199 = V_197 ;
V_13 -> V_99 . V_200 = V_201 ;
} else {
V_13 -> V_99 . V_199 = V_198 ;
V_13 -> V_99 . V_200 = V_202 ;
}
V_13 -> V_99 . V_203 = V_204 ;
F_21 ( & V_205 , V_3 ) ;
V_13 -> V_99 . V_206 =
F_98 ( ( ( T_3 ) V_22 -> V_207 ) << 32 | V_206 ++ ) ;
F_25 ( & V_205 , V_3 ) ;
}
static int F_99 ( struct V_1 * V_2 , int V_208 , T_4 V_54 )
{
bool V_209 = F_100 ( V_54 ) ;
unsigned long V_3 ;
int V_58 , V_138 ;
if ( V_209 )
F_101 ( V_54 ) ;
F_21 ( & V_140 , V_3 ) ;
V_138 = F_102 ( & V_141 , V_2 , 0 , 0 , V_210 ) ;
F_25 ( & V_140 , V_3 ) ;
if ( V_209 )
F_103 () ;
if ( V_138 < 0 )
return V_138 ;
V_2 -> V_10 -> V_208 = V_208 ;
V_2 -> V_10 -> V_11 [ 0 ] = V_2 ;
V_2 -> V_138 = V_138 ;
if ( ( V_2 -> V_3 & V_4 ) &&
( ! ( V_2 -> V_3 & V_196 ) ) ) {
if ( ! F_104 ( V_65 ) ) {
if ( ! F_18 ( V_2 , V_54 ) )
return V_138 ;
}
F_1 ( V_2 ) ;
}
V_58 = F_41 ( V_2 -> V_10 , NULL ) ;
if ( V_58 ) {
F_21 ( & V_140 , V_3 ) ;
F_105 ( & V_141 , V_138 ) ;
F_25 ( & V_140 , V_3 ) ;
}
return V_58 ? V_58 : V_138 ;
}
void F_106 ( void * V_211 , struct V_8 * V_87 )
{
F_107 ( V_212 , F_108 ( V_212 ) , V_211 , V_87 ) ;
}
void F_109 ( struct V_8 * V_87 , void * V_211 )
{
F_110 ( V_212 , F_108 ( V_212 ) , V_87 , V_211 ) ;
}
static bool F_111 ( struct V_134 * V_135 ,
struct V_142 * V_23 ,
V_53 V_26 )
{
struct V_143 * V_144 = F_61 ( V_23 , & V_147 ) ;
struct V_145 * V_21 ;
unsigned long V_3 ;
bool V_58 = false ;
if ( ! V_144 )
return V_58 ;
V_21 = & V_144 -> V_21 [ V_26 - V_144 -> V_148 ] ;
F_21 ( & V_21 -> V_213 , V_3 ) ;
if ( ! V_21 -> V_214 . V_215 )
goto V_58;
if ( V_21 -> V_214 . V_57 . type == V_216 )
V_58 = F_112 ( & V_21 -> V_214 . V_57 . V_217 ) &
V_218 ;
V_58:
F_25 ( & V_21 -> V_213 , V_3 ) ;
return V_58 ;
}
static int F_113 ( struct V_134 * V_135 ,
struct V_142 * V_23 ,
V_53 V_26 ,
struct V_8 * V_87 )
{
struct V_219 V_220 ;
if ( F_114 ( V_23 , V_26 , & V_220 ) )
return V_221 ;
if ( F_111 ( V_135 , V_23 , V_26 ) )
return V_222 ;
if ( V_220 . V_223 >= F_8 ( V_224 ) )
return V_221 ;
else
return V_225 ;
}
static void F_115 ( struct V_1 * V_226 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_227 * V_2 =
F_48 ( V_226 , struct V_227 , V_226 ) ;
if ( V_13 ) {
struct V_8 V_87 ;
if ( V_226 -> V_3 & V_196 ) {
F_107 ( V_228 ,
F_108 ( V_228 ) ,
V_13 -> V_57 , & V_87 ) ;
V_87 . V_180 = V_229 ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else {
F_107 ( V_212 ,
F_108 ( V_212 ) ,
V_13 -> V_57 , & V_87 ) ;
V_87 . V_180 = V_230 ;
F_116 ( & V_87 , NULL ) ;
F_117 ( & V_87 , 0 ) ;
F_118 ( & V_87 ) ;
if ( V_2 -> V_231 ) {
struct V_8 V_217 ;
memset ( & V_217 , 0 , sizeof( struct V_8 ) ) ;
F_119 ( & V_217 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_217 , V_2 -> V_11 ) ;
} else {
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
}
}
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_120 ( struct V_1 * V_226 )
{
struct V_227 * V_2 =
F_48 ( V_226 , struct V_227 , V_226 ) ;
F_50 ( V_2 -> V_231 ) ;
F_50 ( V_2 ) ;
}
int F_121 ( struct V_134 * V_135 ,
struct V_142 * V_23 , V_53 V_26 ,
struct V_8 * V_87 ,
T_1 V_14 ,
int V_208 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_8 * V_232 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_226 )
{
struct V_227 * V_2 ;
struct V_143 * V_144 = F_61 ( V_23 , & V_147 ) ;
struct V_145 * V_21 ;
struct V_139 * V_22 ;
struct V_12 * V_13 ;
enum V_233 V_90 ;
int V_58 ;
if ( ! V_144 )
return - V_183 ;
if ( ( V_87 -> V_180 != V_230 ) &&
( V_87 -> V_180 != V_229 ) )
return - V_182 ;
V_21 = & V_144 -> V_21 [ V_26 - V_144 -> V_148 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_122 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_226 . V_21 = V_21 ;
if ( V_87 -> V_180 == V_229 ) {
V_90 = F_113 ( V_135 , V_23 , V_26 , V_87 ) ;
if ( V_90 == V_221 ) {
V_58 = - V_182 ;
goto V_234;
} else if ( V_90 == V_222 ) {
V_2 -> V_226 . V_3 |= V_196 ;
} else {
V_2 -> V_231 =
F_123 ( sizeof( * V_2 -> V_231 ) , V_54 ) ;
if ( ! V_2 -> V_231 ) {
V_58 = - V_60 ;
goto V_234;
}
}
}
V_58 = F_90 ( & V_2 -> V_226 , V_54 ) ;
if ( V_58 )
goto V_235;
F_124 ( V_135 ) ;
V_2 -> V_226 . V_135 = V_135 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_226 . V_10 -> V_13 ;
F_97 ( & V_2 -> V_226 , V_22 ) ;
V_2 -> V_226 . V_91 = V_91 ? F_115 : NULL ;
V_2 -> V_226 . V_236 = F_120 ;
V_13 -> V_99 . V_100 = V_237 ;
V_13 -> V_99 . V_238 = F_125 ( V_239 ) ;
V_13 -> V_15 . V_14 = V_14 ;
if ( V_2 -> V_226 . V_3 & V_196 ) {
F_110 ( V_228 , F_108 ( V_228 ) ,
V_87 , V_13 -> V_57 ) ;
} else if ( V_2 -> V_231 ) {
F_126 ( V_2 -> V_231 , V_87 ) ;
F_110 ( V_212 , F_108 ( V_212 ) ,
V_2 -> V_231 , V_13 -> V_57 ) ;
} else {
F_110 ( V_212 , F_108 ( V_212 ) ,
V_87 , V_13 -> V_57 ) ;
}
* V_226 = & V_2 -> V_226 ;
V_2 -> V_226 . V_3 |= V_4 ;
V_2 -> V_226 . V_10 -> V_11 [ 1 ] = ( V_2 -> V_231 ) ?
V_2 -> V_231 : V_87 ;
V_58 = F_99 ( & V_2 -> V_226 , V_208 , V_54 ) ;
if ( V_58 < 0 )
goto V_240;
return V_58 ;
V_240:
* V_226 = NULL ;
F_55 ( V_2 -> V_226 . V_135 ) ;
F_95 ( & V_2 -> V_226 ) ;
V_235:
F_50 ( V_2 -> V_231 ) ;
V_234:
F_50 ( V_2 ) ;
return V_58 ;
}
static void F_127 ( struct V_1 * V_226 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_241 * V_2 =
F_48 ( V_226 , struct V_241 , V_226 ) ;
if ( V_13 ) {
struct V_242 V_87 ;
F_107 ( V_243 , F_108 ( V_243 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_128 ( struct V_1 * V_226 )
{
F_50 ( F_48 ( V_226 , struct V_241 , V_226 ) ) ;
}
int F_129 ( struct V_134 * V_135 ,
struct V_142 * V_23 , V_53 V_26 , V_53 V_100 ,
struct V_242 * V_87 ,
T_1 V_14 ,
int V_208 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_242 * V_232 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_226 )
{
struct V_241 * V_2 ;
struct V_143 * V_144 = F_61 ( V_23 , & V_147 ) ;
struct V_145 * V_21 ;
struct V_139 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_144 )
return - V_183 ;
V_21 = & V_144 -> V_21 [ V_26 - V_144 -> V_148 ] ;
V_22 = V_21 -> V_22 ;
if ( V_100 != V_237 &&
V_100 != V_244 &&
V_100 != V_245 )
return - V_182 ;
V_2 = F_122 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_226 . V_21 = V_21 ;
V_58 = F_90 ( & V_2 -> V_226 , V_54 ) ;
if ( V_58 )
goto V_234;
F_124 ( V_135 ) ;
V_2 -> V_226 . V_135 = V_135 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_226 . V_10 -> V_13 ;
F_97 ( & V_2 -> V_226 , V_22 ) ;
V_2 -> V_226 . V_91 = V_91 ? F_127 : NULL ;
V_2 -> V_226 . V_236 = F_128 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_238 = F_125 ( V_246 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_110 ( V_243 , F_108 ( V_243 ) ,
V_87 , V_13 -> V_57 ) ;
* V_226 = & V_2 -> V_226 ;
V_58 = F_99 ( & V_2 -> V_226 , V_208 , V_54 ) ;
if ( V_58 < 0 )
goto V_235;
return V_58 ;
V_235:
* V_226 = NULL ;
F_55 ( V_2 -> V_226 . V_135 ) ;
F_95 ( & V_2 -> V_226 ) ;
V_234:
F_50 ( V_2 ) ;
return V_58 ;
}
static void F_130 ( struct V_1 * V_226 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_247 * V_2 =
F_48 ( V_226 , struct V_247 , V_226 ) ;
if ( V_13 ) {
struct V_248 V_87 ;
F_107 ( V_249 , F_108 ( V_249 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_131 ( struct V_1 * V_226 )
{
F_50 ( F_48 ( V_226 , struct V_247 , V_226 ) ) ;
}
int F_132 ( struct V_134 * V_135 ,
struct V_142 * V_23 , V_53 V_26 ,
V_53 V_100 ,
struct V_248 * V_87 ,
T_1 V_14 ,
int V_208 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_248 * V_232 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_226 )
{
struct V_247 * V_2 ;
struct V_143 * V_144 = F_61 ( V_23 , & V_147 ) ;
struct V_145 * V_21 ;
struct V_139 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_144 )
return - V_183 ;
V_21 = & V_144 -> V_21 [ V_26 - V_144 -> V_148 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_122 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_226 . V_21 = V_21 ;
V_58 = F_90 ( & V_2 -> V_226 , V_54 ) ;
if ( V_58 )
goto V_234;
F_124 ( V_135 ) ;
V_2 -> V_226 . V_135 = V_135 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_226 . V_10 -> V_13 ;
F_97 ( & V_2 -> V_226 , V_22 ) ;
V_2 -> V_226 . V_91 = V_91 ? F_130 : NULL ;
V_2 -> V_226 . V_236 = F_131 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_238 = F_125 ( V_250 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_110 ( V_249 , F_108 ( V_249 ) ,
V_87 , V_13 -> V_57 ) ;
* V_226 = & V_2 -> V_226 ;
V_58 = F_99 ( & V_2 -> V_226 , V_208 , V_54 ) ;
if ( V_58 < 0 )
goto V_235;
return V_58 ;
V_235:
* V_226 = NULL ;
F_55 ( V_2 -> V_226 . V_135 ) ;
F_95 ( & V_2 -> V_226 ) ;
V_234:
F_50 ( V_2 ) ;
return V_58 ;
}
static void F_133 ( struct V_1 * V_226 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_251 * V_2 =
F_48 ( V_226 , struct V_251 , V_226 ) ;
if ( V_13 ) {
struct V_252 V_87 ;
F_107 ( V_253 , F_108 ( V_253 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_134 ( struct V_1 * V_226 )
{
F_50 ( F_48 ( V_226 , struct V_251 , V_226 ) ) ;
}
int F_135 ( struct V_134 * V_135 ,
struct V_142 * V_23 , V_53 V_26 ,
struct V_252 * V_87 ,
T_1 V_14 , V_53 V_100 ,
int V_208 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_252 * V_232 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_226 )
{
struct V_251 * V_2 ;
struct V_143 * V_144 = F_61 ( V_23 , & V_147 ) ;
struct V_145 * V_21 ;
struct V_139 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_144 )
return - V_183 ;
if ( V_100 != V_237 &&
V_100 != V_244 &&
V_100 != V_245 ) {
return - V_182 ;
}
V_21 = & V_144 -> V_21 [ V_26 - V_144 -> V_148 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_122 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_226 . V_21 = V_21 ;
V_58 = F_90 ( & V_2 -> V_226 , V_54 ) ;
if ( V_58 )
goto V_234;
F_124 ( V_135 ) ;
V_2 -> V_226 . V_135 = V_135 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_226 . V_10 -> V_13 ;
F_97 ( & V_2 -> V_226 , V_22 ) ;
V_2 -> V_226 . V_91 = V_91 ? F_133 : NULL ;
V_2 -> V_226 . V_236 = F_134 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_238 = F_125 ( V_254 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_110 ( V_253 , F_108 ( V_253 ) , V_87 ,
V_13 -> V_57 ) ;
* V_226 = & V_2 -> V_226 ;
V_58 = F_99 ( & V_2 -> V_226 , V_208 , V_54 ) ;
if ( V_58 < 0 )
goto V_235;
return V_58 ;
V_235:
* V_226 = NULL ;
F_55 ( V_2 -> V_226 . V_135 ) ;
F_95 ( & V_2 -> V_226 ) ;
V_234:
F_50 ( V_2 ) ;
return V_58 ;
}
bool F_136 ( struct V_134 * V_135 ,
struct V_142 * V_23 ,
V_53 V_26 )
{
struct V_143 * V_144 = F_61 ( V_23 , & V_147 ) ;
struct V_145 * V_21 ;
bool V_58 = false ;
unsigned long V_3 ;
if ( ! V_144 )
return V_58 ;
V_21 = & V_144 -> V_21 [ V_26 - V_144 -> V_148 ] ;
F_21 ( & V_21 -> V_213 , V_3 ) ;
if ( ( V_21 -> V_214 . V_215 ) &&
( V_21 -> V_214 . V_57 . type == V_255 ) )
V_58 = F_137 ( & V_21 -> V_214 . V_57 . V_256 )
& V_257 ;
F_25 ( & V_21 -> V_213 , V_3 ) ;
return V_58 ;
}
static void F_138 ( void * V_11 )
{
struct V_258 * V_259 = V_11 ;
F_139 ( & V_259 -> V_260 ) ;
}
static void F_140 ( struct V_1 * V_226 ,
int V_90 ,
struct V_12 * V_13 )
{
unsigned long V_3 ;
struct V_261 * V_2 =
F_48 ( V_226 , struct V_261 , V_226 ) ;
struct V_262 * V_263 = & V_226 -> V_21 -> V_214 ;
if ( V_13 ) {
if ( V_226 -> V_3 & V_196 ) {
struct V_264 V_87 ;
F_107 ( V_265 ,
F_108 ( V_265 ) ,
V_13 -> V_57 , & V_87 ) ;
F_21 ( & V_226 -> V_21 -> V_213 ,
V_3 ) ;
if ( ! V_90 && ! V_263 -> V_215 ) {
memcpy ( & V_263 -> V_57 . V_217 , & V_87 ,
sizeof( V_263 -> V_57 . V_217 ) ) ;
V_263 -> V_215 = true ;
V_263 -> V_57 . type = V_216 ;
}
F_25 ( & V_226 -> V_21 -> V_213 ,
V_3 ) ;
} else {
struct V_266 V_87 ;
F_107 ( V_267 ,
F_108 ( V_267 ) ,
V_13 -> V_57 , & V_87 ) ;
F_21 ( & V_226 -> V_21 -> V_213 ,
V_3 ) ;
if ( ! V_90 && ! V_263 -> V_215 ) {
memcpy ( & V_263 -> V_57 . V_256 , & V_87 ,
sizeof( V_263 -> V_57 . V_256 ) ) ;
V_263 -> V_215 = true ;
V_263 -> V_57 . type = V_255 ;
}
F_25 ( & V_226 -> V_21 -> V_213 ,
V_3 ) ;
}
}
V_2 -> V_91 ( V_2 -> V_11 ) ;
}
static void F_141 ( struct V_1 * V_226 )
{
F_50 ( F_48 ( V_226 , struct V_261 ,
V_226 ) ) ;
}
static int F_142 ( struct V_145 * V_21 ,
int V_208 ,
void (* V_91)( void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_226 )
{
struct V_139 * V_22 ;
struct V_261 * V_2 ;
struct V_12 * V_13 ;
T_4 V_54 = V_268 ;
int V_58 ;
V_22 = V_21 -> V_22 ;
V_2 = F_122 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_226 . V_21 = V_21 ;
V_2 -> V_226 . V_3 |= F_143 ( V_21 -> V_22 -> V_23 ,
V_21 -> V_26 ) ?
V_196 : 0 ;
V_58 = F_90 ( & V_2 -> V_226 , V_54 ) ;
if ( V_58 )
goto V_269;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_226 . V_10 -> V_13 ;
F_97 ( & V_2 -> V_226 , V_22 ) ;
V_2 -> V_226 . V_91 = F_140 ;
V_2 -> V_226 . V_236 = F_141 ;
V_13 -> V_99 . V_100 = V_237 ;
V_13 -> V_99 . V_238 = F_125 ( V_270 ) ;
V_13 -> V_15 . V_14 = 0 ;
* V_226 = & V_2 -> V_226 ;
V_58 = F_99 ( & V_2 -> V_226 , V_208 , V_54 ) ;
if ( V_58 < 0 )
goto V_271;
return V_58 ;
V_271:
* V_226 = NULL ;
F_95 ( & V_2 -> V_226 ) ;
V_269:
F_50 ( V_2 ) ;
return V_58 ;
}
static void F_144 ( struct V_106 * V_107 )
{
struct V_145 * V_21 =
F_48 ( V_107 , struct V_145 , V_272 . V_107 ) ;
struct V_258 * V_273 ;
unsigned long V_3 ;
int V_58 ;
F_21 ( & V_21 -> V_213 , V_3 ) ;
if ( V_21 -> V_214 . V_215 ) {
F_25 ( & V_21 -> V_213 , V_3 ) ;
return;
}
F_25 ( & V_21 -> V_213 , V_3 ) ;
V_273 = F_123 ( sizeof( * V_273 ) , V_268 ) ;
if ( ! V_273 )
goto V_274;
F_53 ( & V_273 -> V_260 ) ;
V_58 = F_142 ( V_21 , 3000 ,
F_138 , V_273 ,
& V_273 -> V_226 ) ;
if ( V_58 < 0 )
goto V_275;
F_56 ( & V_273 -> V_260 ) ;
V_275:
F_50 ( V_273 ) ;
F_21 ( & V_21 -> V_213 , V_3 ) ;
if ( ! V_21 -> V_214 . V_215 ) {
V_21 -> V_214 . V_276 ++ ;
if ( V_21 -> V_214 . V_276 <=
V_277 ) {
unsigned long V_66 =
F_22 ( V_278 ) ;
F_24 ( V_279 , & V_21 -> V_272 , V_66 ) ;
}
}
F_25 ( & V_21 -> V_213 , V_3 ) ;
V_274:
return;
}
static void F_36 ( struct V_139 * V_22 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_103 -> V_11 [ 0 ] ;
unsigned long V_3 ;
if ( V_2 -> V_91 )
switch ( V_82 -> V_90 ) {
case V_104 :
break;
case V_280 :
V_2 -> V_91 ( V_2 , - V_281 , NULL ) ;
break;
case V_108 :
V_2 -> V_91 ( V_2 , - V_282 , NULL ) ;
break;
default:
V_2 -> V_91 ( V_2 , - V_78 , NULL ) ;
break;
}
F_21 ( & V_140 , V_3 ) ;
F_105 ( & V_141 , V_2 -> V_138 ) ;
F_25 ( & V_140 , V_3 ) ;
F_95 ( V_2 ) ;
if ( V_2 -> V_135 )
F_55 ( V_2 -> V_135 ) ;
V_2 -> V_236 ( V_2 ) ;
}
static void F_145 ( struct V_139 * V_105 ,
struct V_125 * V_103 ,
struct V_283 * V_284 )
{
struct V_1 * V_2 ;
if ( ! V_103 )
return;
V_2 = V_103 -> V_11 [ 0 ] ;
if ( V_2 -> V_91 ) {
if ( V_284 -> V_285 -> V_90 == V_104 )
V_2 -> V_91 ( V_2 ,
V_284 -> V_286 . V_13 -> V_99 . V_90 ?
- V_182 : 0 ,
(struct V_12 * ) V_284 -> V_286 . V_13 ) ;
else
V_2 -> V_91 ( V_2 , - V_78 , NULL ) ;
}
F_146 ( V_284 ) ;
}
static void F_147 ( struct V_106 * V_107 )
{
struct V_145 * V_21 =
F_48 ( V_107 , struct V_145 , V_287 ) ;
struct V_130 * V_288 ;
struct V_219 V_220 ;
struct V_150 V_151 ;
if ( F_114 ( V_21 -> V_22 -> V_23 , V_21 -> V_26 , & V_220 ) ) {
F_148 ( L_1 ) ;
return;
}
V_288 = F_123 ( sizeof( * V_288 ) , V_268 ) ;
if ( ! V_288 )
return;
F_149 ( & V_288 -> V_132 ) ;
V_288 -> V_146 = ( 1 << V_220 . V_289 ) - 1 ;
V_288 -> V_193 = 0 ;
if ( F_150 ( V_21 -> V_22 -> V_23 , V_21 -> V_26 ,
V_290 , & V_288 -> V_193 ) )
F_151 ( L_2 ) ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . type = F_63 ( V_21 -> V_22 -> V_23 ,
V_21 -> V_26 ) ;
F_64 ( & V_151 , V_220 . V_291 ) ;
F_69 ( & V_151 , V_220 . V_292 ) ;
F_72 ( & V_151 , V_21 -> V_26 ) ;
if ( V_220 . V_293 ) {
if ( V_151 . type == V_156 ) {
F_68 ( & V_151 , true ) ;
} else {
F_152 ( & V_151 , V_294 ) ;
F_153 ( & V_151 ,
F_98 ( V_220 . V_295 ) ) ;
F_154 ( & V_151 ,
F_98 ( V_296 ) ) ;
}
}
V_288 -> V_133 = F_155 ( V_21 -> V_22 -> V_297 -> V_298 , & V_151 ) ;
if ( F_93 ( V_288 -> V_133 ) ) {
F_148 ( L_3 ) ;
F_50 ( V_288 ) ;
return;
}
F_156 ( & V_21 -> V_149 ) ;
if ( V_21 -> V_131 )
F_94 ( & V_21 -> V_131 -> V_132 , F_47 ) ;
V_21 -> V_131 = V_288 ;
F_157 ( & V_21 -> V_149 ) ;
}
static void F_158 ( struct V_299 * V_300 ,
struct V_301 * V_302 )
{
if ( V_302 -> V_302 == V_303 ||
V_302 -> V_302 == V_304 ||
V_302 -> V_302 == V_305 ||
V_302 -> V_302 == V_306 ||
V_302 -> V_302 == V_307 ||
V_302 -> V_302 == V_308 ) {
unsigned long V_3 ;
struct V_143 * V_144 =
F_48 ( V_300 , F_159 ( * V_144 ) , V_309 ) ;
V_53 V_26 = V_302 -> V_310 . V_26 - V_144 -> V_148 ;
struct V_145 * V_21 = & V_144 -> V_21 [ V_26 ] ;
if ( ! F_160 ( V_300 -> V_23 , V_21 -> V_26 ) )
return;
F_21 ( & V_21 -> V_149 , V_3 ) ;
if ( V_21 -> V_131 )
F_94 ( & V_21 -> V_131 -> V_132 , F_47 ) ;
V_21 -> V_131 = NULL ;
F_25 ( & V_21 -> V_149 , V_3 ) ;
if ( V_302 -> V_302 == V_307 ||
V_302 -> V_302 == V_308 ||
V_302 -> V_302 == V_305 ||
V_302 -> V_302 == V_304 ) {
unsigned long V_66 =
F_22 ( V_278 ) ;
F_21 ( & V_21 -> V_213 , V_3 ) ;
V_21 -> V_214 . V_215 = false ;
V_21 -> V_214 . V_276 = 0 ;
F_25 ( & V_21 -> V_213 , V_3 ) ;
F_24 ( V_279 ,
& V_21 -> V_272 , V_66 ) ;
}
F_161 ( V_279 , & V_144 -> V_21 [ V_26 ] . V_287 ) ;
}
}
static void F_162 ( struct V_142 * V_23 )
{
struct V_143 * V_144 ;
int V_311 , V_312 , V_313 ;
int V_314 = 0 ;
V_311 = F_163 ( V_23 ) ;
V_312 = F_164 ( V_23 ) ;
V_144 = F_122 ( sizeof *V_144 +
( V_312 - V_311 + 1 ) * sizeof ( struct V_145 ) ,
V_268 ) ;
if ( ! V_144 )
return;
V_144 -> V_148 = V_311 ;
V_144 -> V_315 = V_312 ;
for ( V_313 = 0 ; V_313 <= V_312 - V_311 ; ++ V_313 ) {
F_165 ( & V_144 -> V_21 [ V_313 ] . V_149 ) ;
if ( ! F_160 ( V_23 , V_313 + 1 ) )
continue;
V_144 -> V_21 [ V_313 ] . V_131 = NULL ;
V_144 -> V_21 [ V_313 ] . V_26 = V_313 + V_311 ;
F_165 ( & V_144 -> V_21 [ V_313 ] . V_213 ) ;
V_144 -> V_21 [ V_313 ] . V_214 . V_215 = false ;
V_144 -> V_21 [ V_313 ] . V_22 =
F_166 ( V_23 , V_313 + V_311 , V_316 ,
NULL , 0 , F_36 ,
F_145 , V_144 , 0 ) ;
if ( F_93 ( V_144 -> V_21 [ V_313 ] . V_22 ) )
goto V_317;
F_167 ( & V_144 -> V_21 [ V_313 ] . V_287 , F_147 ) ;
F_168 ( & V_144 -> V_21 [ V_313 ] . V_272 ,
F_144 ) ;
V_314 ++ ;
}
if ( ! V_314 )
goto free;
F_169 ( V_23 , & V_147 , V_144 ) ;
F_170 ( & V_144 -> V_309 , V_23 , F_158 ) ;
F_171 ( & V_144 -> V_309 ) ;
for ( V_313 = 0 ; V_313 <= V_312 - V_311 ; ++ V_313 ) {
if ( F_160 ( V_23 , V_313 + 1 ) )
F_147 ( & V_144 -> V_21 [ V_313 ] . V_287 ) ;
}
return;
V_317:
while ( -- V_313 >= 0 ) {
if ( F_160 ( V_23 , V_313 + 1 ) )
F_172 ( V_144 -> V_21 [ V_313 ] . V_22 ) ;
}
free:
F_50 ( V_144 ) ;
return;
}
static void F_173 ( struct V_142 * V_23 , void * V_318 )
{
struct V_143 * V_144 = V_318 ;
int V_313 ;
if ( ! V_144 )
return;
F_174 ( & V_144 -> V_309 ) ;
F_175 ( V_279 ) ;
for ( V_313 = 0 ; V_313 <= V_144 -> V_315 - V_144 -> V_148 ; ++ V_313 ) {
if ( F_160 ( V_23 , V_313 + 1 ) ) {
F_176 ( & V_144 -> V_21 [ V_313 ] . V_272 ) ;
F_172 ( V_144 -> V_21 [ V_313 ] . V_22 ) ;
if ( V_144 -> V_21 [ V_313 ] . V_131 )
F_94 ( & V_144 -> V_21 [ V_313 ] . V_131 -> V_132 , F_47 ) ;
}
}
F_50 ( V_144 ) ;
}
int F_177 ( void )
{
int V_58 ;
F_178 ( & V_206 , sizeof V_206 ) ;
F_52 ( & V_69 , 0 ) ;
V_58 = F_179 ( & V_147 ) ;
if ( V_58 ) {
F_151 ( L_4 ) ;
goto V_234;
}
V_58 = F_180 () ;
if ( V_58 ) {
F_151 ( L_5 ) ;
goto V_235;
}
V_76 = F_181 ( L_6 , V_319 ) ;
if ( ! V_76 ) {
V_58 = - V_60 ;
goto V_240;
}
F_168 ( & V_77 , F_37 ) ;
return 0 ;
V_240:
F_182 () ;
V_235:
F_183 ( & V_147 ) ;
V_234:
return V_58 ;
}
void F_184 ( void )
{
F_185 ( & V_77 ) ;
F_175 ( V_76 ) ;
F_186 ( V_76 ) ;
F_182 () ;
F_183 ( & V_147 ) ;
F_187 ( & V_141 ) ;
}
