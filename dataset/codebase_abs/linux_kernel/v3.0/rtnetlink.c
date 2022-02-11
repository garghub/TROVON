void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
void F_5 ( void )
{
F_6 () ;
}
int F_7 ( void )
{
return F_8 ( & V_1 ) ;
}
int F_9 ( void )
{
return F_10 ( & V_1 ) ;
}
int F_11 ( void )
{
return F_12 ( & V_1 ) ;
}
static inline int F_13 ( int V_2 )
{
int V_3 = V_2 - V_4 ;
F_14 ( V_3 < 0 || V_3 >= V_5 ) ;
return V_3 ;
}
static T_1 F_15 ( int V_6 , int V_3 )
{
struct V_7 * V_8 ;
if ( V_6 <= V_9 )
V_8 = V_10 [ V_6 ] ;
else
V_8 = NULL ;
if ( V_8 == NULL || V_8 [ V_3 ] . V_11 == NULL )
V_8 = V_10 [ V_12 ] ;
return V_8 ? V_8 [ V_3 ] . V_11 : NULL ;
}
static T_2 F_16 ( int V_6 , int V_3 )
{
struct V_7 * V_8 ;
if ( V_6 <= V_9 )
V_8 = V_10 [ V_6 ] ;
else
V_8 = NULL ;
if ( V_8 == NULL || V_8 [ V_3 ] . V_13 == NULL )
V_8 = V_10 [ V_12 ] ;
return V_8 ? V_8 [ V_3 ] . V_13 : NULL ;
}
int F_17 ( int V_6 , int V_2 ,
T_1 V_11 , T_2 V_13 )
{
struct V_7 * V_8 ;
int V_3 ;
F_14 ( V_6 < 0 || V_6 > V_9 ) ;
V_3 = F_13 ( V_2 ) ;
V_8 = V_10 [ V_6 ] ;
if ( V_8 == NULL ) {
V_8 = F_18 ( V_5 , sizeof( * V_8 ) , V_14 ) ;
if ( V_8 == NULL )
return - V_15 ;
V_10 [ V_6 ] = V_8 ;
}
if ( V_11 )
V_8 [ V_3 ] . V_11 = V_11 ;
if ( V_13 )
V_8 [ V_3 ] . V_13 = V_13 ;
return 0 ;
}
void F_19 ( int V_6 , int V_2 ,
T_1 V_11 , T_2 V_13 )
{
if ( F_17 ( V_6 , V_2 , V_11 , V_13 ) < 0 )
F_20 ( L_1
L_2 ,
V_6 , V_2 ) ;
}
int F_21 ( int V_6 , int V_2 )
{
int V_3 ;
F_14 ( V_6 < 0 || V_6 > V_9 ) ;
V_3 = F_13 ( V_2 ) ;
if ( V_10 [ V_6 ] == NULL )
return - V_16 ;
V_10 [ V_6 ] [ V_3 ] . V_11 = NULL ;
V_10 [ V_6 ] [ V_3 ] . V_13 = NULL ;
return 0 ;
}
void F_22 ( int V_6 )
{
F_14 ( V_6 < 0 || V_6 > V_9 ) ;
F_23 ( V_10 [ V_6 ] ) ;
V_10 [ V_6 ] = NULL ;
}
int F_24 ( struct V_17 * V_18 )
{
if ( ! V_18 -> V_19 )
V_18 -> V_19 = V_20 ;
F_25 ( & V_18 -> V_21 , & V_22 ) ;
return 0 ;
}
int F_26 ( struct V_17 * V_18 )
{
int V_23 ;
F_1 () ;
V_23 = F_24 ( V_18 ) ;
F_5 () ;
return V_23 ;
}
static void F_27 ( struct V_24 * V_24 , struct V_17 * V_18 )
{
struct V_25 * V_26 ;
F_28 ( V_27 ) ;
F_29 (net, dev) {
if ( V_26 -> V_17 == V_18 )
V_18 -> V_19 ( V_26 , & V_27 ) ;
}
F_30 ( & V_27 ) ;
}
void F_31 ( struct V_17 * V_18 )
{
struct V_24 * V_24 ;
F_32 (net) {
F_27 ( V_24 , V_18 ) ;
}
F_33 ( & V_18 -> V_21 ) ;
}
void F_34 ( struct V_17 * V_18 )
{
F_1 () ;
F_31 ( V_18 ) ;
F_5 () ;
}
static const struct V_17 * F_35 ( const char * V_28 )
{
const struct V_17 * V_18 ;
F_36 (ops, &link_ops, list) {
if ( ! strcmp ( V_18 -> V_28 , V_28 ) )
return V_18 ;
}
return NULL ;
}
static T_3 F_37 ( const struct V_25 * V_26 )
{
const struct V_17 * V_18 = V_26 -> V_17 ;
T_3 V_29 ;
if ( ! V_18 )
return 0 ;
V_29 = F_38 ( sizeof( struct V_30 ) ) +
F_38 ( strlen ( V_18 -> V_28 ) + 1 ) ;
if ( V_18 -> V_31 )
V_29 += F_38 ( sizeof( struct V_30 ) ) +
V_18 -> V_31 ( V_26 ) ;
if ( V_18 -> V_32 )
V_29 += F_38 ( V_18 -> V_32 ( V_26 ) ) ;
return V_29 ;
}
static const struct V_33 * F_39 ( const int V_34 )
{
const struct V_33 * V_18 ;
F_36 (ops, &rtnl_af_ops, list) {
if ( V_18 -> V_34 == V_34 )
return V_18 ;
}
return NULL ;
}
int F_40 ( struct V_33 * V_18 )
{
F_25 ( & V_18 -> V_21 , & V_33 ) ;
return 0 ;
}
int F_41 ( struct V_33 * V_18 )
{
int V_23 ;
F_1 () ;
V_23 = F_40 ( V_18 ) ;
F_5 () ;
return V_23 ;
}
void F_42 ( struct V_33 * V_18 )
{
F_33 ( & V_18 -> V_21 ) ;
}
void F_43 ( struct V_33 * V_18 )
{
F_1 () ;
F_42 ( V_18 ) ;
F_5 () ;
}
static T_3 F_44 ( const struct V_25 * V_26 )
{
struct V_33 * V_35 ;
T_3 V_29 ;
V_29 = F_38 ( sizeof( struct V_30 ) ) ;
F_36 (af_ops, &rtnl_af_ops, list) {
if ( V_35 -> V_36 ) {
V_29 += F_38 ( sizeof( struct V_30 ) ) +
V_35 -> V_36 ( V_26 ) ;
}
}
return V_29 ;
}
static int F_45 ( struct V_37 * V_38 , const struct V_25 * V_26 )
{
const struct V_17 * V_18 = V_26 -> V_17 ;
struct V_30 * V_39 , * V_40 ;
int V_23 = - V_41 ;
V_39 = F_46 ( V_38 , V_42 ) ;
if ( V_39 == NULL )
goto V_43;
if ( F_47 ( V_38 , V_44 , V_18 -> V_28 ) < 0 )
goto V_45;
if ( V_18 -> V_46 ) {
V_23 = V_18 -> V_46 ( V_38 , V_26 ) ;
if ( V_23 < 0 )
goto V_45;
}
if ( V_18 -> V_47 ) {
V_40 = F_46 ( V_38 , V_48 ) ;
if ( V_40 == NULL )
goto V_45;
V_23 = V_18 -> V_47 ( V_38 , V_26 ) ;
if ( V_23 < 0 )
goto V_49;
F_48 ( V_38 , V_40 ) ;
}
F_48 ( V_38 , V_39 ) ;
return 0 ;
V_49:
F_49 ( V_38 , V_40 ) ;
V_45:
F_49 ( V_38 , V_39 ) ;
V_43:
return V_23 ;
}
void F_50 ( struct V_37 * V_38 , int V_50 , int V_51 , const void * V_40 )
{
struct V_52 * V_53 ;
int V_29 = F_51 ( V_51 ) ;
V_53 = (struct V_52 * ) F_52 ( V_38 , F_53 ( V_29 ) ) ;
V_53 -> V_54 = V_50 ;
V_53 -> V_55 = V_29 ;
memcpy ( F_54 ( V_53 ) , V_40 , V_51 ) ;
memset ( F_54 ( V_53 ) + V_51 , 0 , F_53 ( V_29 ) - V_29 ) ;
}
int F_55 ( struct V_37 * V_38 , struct V_24 * V_24 , T_4 V_56 , unsigned V_57 , int V_58 )
{
struct V_59 * V_60 = V_24 -> V_60 ;
int V_23 = 0 ;
F_56 ( V_38 ) . V_61 = V_57 ;
if ( V_58 )
F_57 ( & V_38 -> V_62 ) ;
F_58 ( V_60 , V_38 , V_56 , V_57 , V_14 ) ;
if ( V_58 )
V_23 = F_59 ( V_60 , V_38 , V_56 , V_63 ) ;
return V_23 ;
}
int F_60 ( struct V_37 * V_38 , struct V_24 * V_24 , T_4 V_56 )
{
struct V_59 * V_60 = V_24 -> V_60 ;
return F_61 ( V_60 , V_38 , V_56 ) ;
}
void F_62 ( struct V_37 * V_38 , struct V_24 * V_24 , T_4 V_56 , T_4 V_57 ,
struct V_64 * V_65 , T_5 V_66 )
{
struct V_59 * V_60 = V_24 -> V_60 ;
int V_67 = 0 ;
if ( V_65 )
V_67 = F_63 ( V_65 ) ;
F_64 ( V_60 , V_38 , V_56 , V_57 , V_67 , V_66 ) ;
}
void F_65 ( struct V_24 * V_24 , T_4 V_57 , int error )
{
struct V_59 * V_60 = V_24 -> V_60 ;
F_66 ( V_60 , 0 , V_57 , error ) ;
}
int F_67 ( struct V_37 * V_38 , T_4 * V_68 )
{
struct V_30 * V_69 ;
int V_70 , V_71 = 0 ;
V_69 = F_46 ( V_38 , V_72 ) ;
if ( V_69 == NULL )
return - V_15 ;
for ( V_70 = 0 ; V_70 < V_73 ; V_70 ++ ) {
if ( V_68 [ V_70 ] ) {
V_71 ++ ;
F_68 ( V_38 , V_70 + 1 , V_68 [ V_70 ] ) ;
}
}
if ( ! V_71 ) {
F_49 ( V_38 , V_69 ) ;
return 0 ;
}
return F_48 ( V_38 , V_69 ) ;
V_74:
F_49 ( V_38 , V_69 ) ;
return - V_41 ;
}
int F_69 ( struct V_37 * V_38 , struct V_75 * V_76 , T_4 V_77 ,
T_4 V_78 , T_4 V_79 , long V_80 , T_4 error )
{
struct V_81 V_82 = {
. V_83 = F_70 ( V_84 - V_76 -> V_85 ) ,
. V_86 = V_76 -> V_87 ,
. V_88 = F_71 ( & ( V_76 -> V_89 ) ) ,
. V_90 = error ,
. V_91 = V_77 ,
. V_92 = V_78 ,
. V_93 = V_79 ,
} ;
if ( V_80 )
V_82 . V_94 = F_70 ( V_80 ) ;
return F_72 ( V_38 , V_95 , sizeof( V_82 ) , & V_82 ) ;
}
static void F_73 ( struct V_25 * V_26 , unsigned char V_96 )
{
unsigned char V_97 = V_26 -> V_97 ;
switch ( V_96 ) {
case V_98 :
if ( ( V_97 == V_99 ||
V_97 == V_100 ) &&
! F_74 ( V_26 ) )
V_97 = V_98 ;
break;
case V_99 :
if ( V_97 == V_98 ||
V_97 == V_100 )
V_97 = V_99 ;
break;
}
if ( V_26 -> V_97 != V_97 ) {
F_75 ( & V_101 ) ;
V_26 -> V_97 = V_97 ;
F_76 ( & V_101 ) ;
F_77 ( V_26 ) ;
}
}
static unsigned int F_78 ( const struct V_25 * V_26 ,
const struct V_102 * V_103 )
{
unsigned int V_66 = V_103 -> V_104 ;
if ( V_103 -> V_105 )
V_66 = ( V_66 & V_103 -> V_105 ) |
( V_26 -> V_66 & ~ V_103 -> V_105 ) ;
return V_66 ;
}
static void F_79 ( struct V_106 * V_107 ,
const struct V_108 * V_109 )
{
V_107 -> V_110 = V_109 -> V_110 ;
V_107 -> V_111 = V_109 -> V_111 ;
V_107 -> V_112 = V_109 -> V_112 ;
V_107 -> V_113 = V_109 -> V_113 ;
V_107 -> V_114 = V_109 -> V_114 ;
V_107 -> V_115 = V_109 -> V_115 ;
V_107 -> V_116 = V_109 -> V_116 ;
V_107 -> V_117 = V_109 -> V_117 ;
V_107 -> V_118 = V_109 -> V_118 ;
V_107 -> V_119 = V_109 -> V_119 ;
V_107 -> V_120 = V_109 -> V_120 ;
V_107 -> V_121 = V_109 -> V_121 ;
V_107 -> V_122 = V_109 -> V_122 ;
V_107 -> V_123 = V_109 -> V_123 ;
V_107 -> V_124 = V_109 -> V_124 ;
V_107 -> V_125 = V_109 -> V_125 ;
V_107 -> V_126 = V_109 -> V_126 ;
V_107 -> V_127 = V_109 -> V_127 ;
V_107 -> V_128 = V_109 -> V_128 ;
V_107 -> V_129 = V_109 -> V_129 ;
V_107 -> V_130 = V_109 -> V_130 ;
V_107 -> V_131 = V_109 -> V_131 ;
V_107 -> V_132 = V_109 -> V_132 ;
}
static void F_80 ( void * V_133 , const struct V_108 * V_109 )
{
memcpy ( V_133 , V_109 , sizeof( * V_109 ) ) ;
}
static inline int F_81 ( const struct V_25 * V_26 )
{
if ( V_26 -> V_26 . V_134 && F_82 ( V_26 -> V_26 . V_134 ) ) {
int V_135 = F_83 ( V_26 -> V_26 . V_134 ) ;
T_3 V_29 = F_38 ( sizeof( struct V_30 ) ) ;
V_29 += F_38 ( V_135 * sizeof( struct V_30 ) ) ;
V_29 += V_135 *
( F_38 ( sizeof( struct V_136 ) ) +
F_38 ( sizeof( struct V_137 ) ) +
F_38 ( sizeof( struct V_138 ) ) ) ;
return V_29 ;
} else
return 0 ;
}
static T_3 F_84 ( const struct V_25 * V_26 )
{
T_3 V_139 = F_38 ( 4 )
+ F_38 ( V_140 )
+ F_38 ( sizeof( struct V_141 ) )
+ F_38 ( V_142 )
+ F_38 ( V_142 )
+ F_38 ( 1 )
+ F_38 ( 2 ) ;
T_3 V_143 = F_38 ( sizeof( struct V_30 ) ) ;
T_3 V_144 = F_38 ( sizeof( struct V_30 ) )
+ V_139 ;
T_3 V_145 = F_38 ( sizeof( struct V_30 ) )
+ V_139 ;
if ( ! V_26 -> V_146 -> V_147 || ! V_26 -> V_26 . V_134 )
return 0 ;
if ( F_83 ( V_26 -> V_26 . V_134 ) )
return V_145 + V_143 +
V_144 * F_83 ( V_26 -> V_26 . V_134 ) ;
else
return V_145 ;
}
static T_6 T_3 F_85 ( const struct V_25 * V_26 )
{
return F_86 ( sizeof( struct V_102 ) )
+ F_38 ( V_148 )
+ F_38 ( V_149 )
+ F_38 ( V_148 )
+ F_38 ( sizeof( struct V_150 ) )
+ F_38 ( sizeof( struct V_106 ) )
+ F_38 ( sizeof( struct V_108 ) )
+ F_38 ( V_151 )
+ F_38 ( V_151 )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 1 )
+ F_38 ( 1 )
+ F_38 ( 4 )
+ F_81 ( V_26 )
+ F_84 ( V_26 )
+ F_37 ( V_26 )
+ F_44 ( V_26 ) ;
}
static int F_87 ( struct V_37 * V_38 , struct V_25 * V_26 )
{
struct V_30 * V_152 ;
struct V_30 * V_153 ;
int V_154 ;
int V_23 ;
V_152 = F_46 ( V_38 , V_155 ) ;
if ( ! V_152 )
return - V_41 ;
for ( V_154 = 0 ; V_154 < F_83 ( V_26 -> V_26 . V_134 ) ; V_154 ++ ) {
V_153 = F_46 ( V_38 , V_156 ) ;
if ( ! V_153 )
goto V_74;
F_68 ( V_38 , V_157 , V_154 ) ;
V_23 = V_26 -> V_146 -> V_147 ( V_26 , V_154 , V_38 ) ;
if ( V_23 == - V_41 )
goto V_74;
if ( V_23 ) {
F_49 ( V_38 , V_153 ) ;
continue;
}
F_48 ( V_38 , V_153 ) ;
}
F_48 ( V_38 , V_152 ) ;
return 0 ;
V_74:
F_49 ( V_38 , V_152 ) ;
return - V_41 ;
}
static int F_88 ( struct V_37 * V_38 , struct V_25 * V_26 )
{
struct V_30 * V_158 ;
int V_23 ;
V_158 = F_46 ( V_38 , V_159 ) ;
if ( ! V_158 )
return - V_41 ;
V_23 = V_26 -> V_146 -> V_147 ( V_26 , V_160 , V_38 ) ;
if ( V_23 ) {
F_49 ( V_38 , V_158 ) ;
return ( V_23 == - V_41 ) ? V_23 : 0 ;
}
F_48 ( V_38 , V_158 ) ;
return 0 ;
}
static int F_89 ( struct V_37 * V_38 , struct V_25 * V_26 )
{
int V_23 ;
if ( ! V_26 -> V_146 -> V_147 || ! V_26 -> V_26 . V_134 )
return 0 ;
V_23 = F_88 ( V_38 , V_26 ) ;
if ( V_23 )
return V_23 ;
if ( F_83 ( V_26 -> V_26 . V_134 ) ) {
V_23 = F_87 ( V_38 , V_26 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_90 ( struct V_37 * V_38 , struct V_25 * V_26 ,
int type , T_4 V_56 , T_4 V_161 , T_4 V_162 ,
unsigned int V_66 )
{
struct V_102 * V_103 ;
struct V_64 * V_65 ;
struct V_108 V_163 ;
const struct V_108 * V_164 ;
struct V_30 * V_165 , * V_166 ;
struct V_33 * V_35 ;
F_91 () ;
V_65 = F_92 ( V_38 , V_56 , V_161 , type , sizeof( * V_103 ) , V_66 ) ;
if ( V_65 == NULL )
return - V_41 ;
V_103 = F_93 ( V_65 ) ;
V_103 -> V_167 = V_168 ;
V_103 -> V_169 = 0 ;
V_103 -> V_170 = V_26 -> type ;
V_103 -> V_171 = V_26 -> V_172 ;
V_103 -> V_104 = F_94 ( V_26 ) ;
V_103 -> V_105 = V_162 ;
F_95 ( V_38 , V_173 , V_26 -> V_174 ) ;
F_68 ( V_38 , V_175 , V_26 -> V_176 ) ;
F_96 ( V_38 , V_177 ,
F_97 ( V_26 ) ? V_26 -> V_97 : V_178 ) ;
F_96 ( V_38 , V_179 , V_26 -> V_180 ) ;
F_68 ( V_38 , V_181 , V_26 -> V_182 ) ;
F_68 ( V_38 , V_183 , V_26 -> V_57 ) ;
if ( V_26 -> V_172 != V_26 -> V_184 )
F_68 ( V_38 , V_185 , V_26 -> V_184 ) ;
if ( V_26 -> V_186 )
F_68 ( V_38 , V_187 , V_26 -> V_186 -> V_172 ) ;
if ( V_26 -> V_188 )
F_95 ( V_38 , V_189 , V_26 -> V_188 -> V_18 -> V_77 ) ;
if ( V_26 -> V_190 )
F_95 ( V_38 , V_191 , V_26 -> V_190 ) ;
if ( 1 ) {
struct V_150 V_192 = {
. V_193 = V_26 -> V_193 ,
. V_194 = V_26 -> V_194 ,
. V_195 = V_26 -> V_195 ,
. V_196 = V_26 -> V_196 ,
. V_197 = V_26 -> V_197 ,
. V_198 = V_26 -> V_199 ,
} ;
F_98 ( V_38 , V_200 , sizeof( V_192 ) , & V_192 ) ;
}
if ( V_26 -> V_201 ) {
F_98 ( V_38 , V_202 , V_26 -> V_201 , V_26 -> V_203 ) ;
F_98 ( V_38 , V_204 , V_26 -> V_201 , V_26 -> V_205 ) ;
}
V_165 = F_99 ( V_38 , V_206 ,
sizeof( struct V_106 ) ) ;
if ( V_165 == NULL )
goto V_74;
V_164 = F_100 ( V_26 , & V_163 ) ;
F_79 ( F_101 ( V_165 ) , V_164 ) ;
V_165 = F_99 ( V_38 , V_207 ,
sizeof( struct V_108 ) ) ;
if ( V_165 == NULL )
goto V_74;
F_80 ( F_101 ( V_165 ) , V_164 ) ;
if ( V_26 -> V_26 . V_134 )
F_68 ( V_38 , V_208 , F_83 ( V_26 -> V_26 . V_134 ) ) ;
if ( V_26 -> V_146 -> V_209 && V_26 -> V_26 . V_134 ) {
int V_70 ;
struct V_30 * V_210 , * V_154 ;
int V_135 = F_83 ( V_26 -> V_26 . V_134 ) ;
V_210 = F_46 ( V_38 , V_211 ) ;
if ( ! V_210 )
goto V_74;
for ( V_70 = 0 ; V_70 < V_135 ; V_70 ++ ) {
struct V_212 V_213 ;
struct V_136 V_214 ;
struct V_137 V_215 ;
struct V_138 V_216 ;
if ( V_26 -> V_146 -> V_209 ( V_26 , V_70 , & V_213 ) )
break;
V_214 . V_154 = V_215 . V_154 = V_216 . V_154 = V_213 . V_154 ;
memcpy ( V_214 . V_217 , V_213 . V_217 , sizeof( V_213 . V_217 ) ) ;
V_215 . V_218 = V_213 . V_218 ;
V_215 . V_219 = V_213 . V_219 ;
V_216 . V_220 = V_213 . V_221 ;
V_154 = F_46 ( V_38 , V_222 ) ;
if ( ! V_154 ) {
F_49 ( V_38 , V_210 ) ;
goto V_74;
}
F_98 ( V_38 , V_223 , sizeof( V_214 ) , & V_214 ) ;
F_98 ( V_38 , V_224 , sizeof( V_215 ) , & V_215 ) ;
F_98 ( V_38 , V_225 , sizeof( V_216 ) , & V_216 ) ;
F_48 ( V_38 , V_154 ) ;
}
F_48 ( V_38 , V_210 ) ;
}
if ( F_89 ( V_38 , V_26 ) )
goto V_74;
if ( V_26 -> V_17 ) {
if ( F_45 ( V_38 , V_26 ) < 0 )
goto V_74;
}
if ( ! ( V_166 = F_46 ( V_38 , V_226 ) ) )
goto V_74;
F_36 (af_ops, &rtnl_af_ops, list) {
if ( V_35 -> V_227 ) {
struct V_30 * V_228 ;
int V_23 ;
if ( ! ( V_228 = F_46 ( V_38 , V_35 -> V_34 ) ) )
goto V_74;
V_23 = V_35 -> V_227 ( V_38 , V_26 ) ;
if ( V_23 == - V_229 )
F_49 ( V_38 , V_228 ) ;
else if ( V_23 < 0 )
goto V_74;
F_48 ( V_38 , V_228 ) ;
}
}
F_48 ( V_38 , V_166 ) ;
return F_102 ( V_38 , V_65 ) ;
V_74:
F_103 ( V_38 , V_65 ) ;
return - V_41 ;
}
static int F_104 ( struct V_37 * V_38 , struct V_230 * V_231 )
{
struct V_24 * V_24 = F_105 ( V_38 -> V_232 ) ;
int V_233 , V_234 ;
int V_235 = 0 , V_236 ;
struct V_25 * V_26 ;
struct V_237 * V_238 ;
struct V_239 * V_240 ;
V_234 = V_231 -> args [ 0 ] ;
V_236 = V_231 -> args [ 1 ] ;
F_106 () ;
for ( V_233 = V_234 ; V_233 < V_241 ; V_233 ++ , V_236 = 0 ) {
V_235 = 0 ;
V_238 = & V_24 -> V_242 [ V_233 ] ;
F_107 (dev, node, head, index_hlist) {
if ( V_235 < V_236 )
goto V_243;
if ( F_90 ( V_38 , V_26 , V_244 ,
F_56 ( V_231 -> V_38 ) . V_56 ,
V_231 -> V_65 -> V_245 , 0 ,
V_246 ) <= 0 )
goto V_43;
V_243:
V_235 ++ ;
}
}
V_43:
F_108 () ;
V_231 -> args [ 1 ] = V_235 ;
V_231 -> args [ 0 ] = V_233 ;
return V_38 -> V_247 ;
}
struct V_24 * F_109 ( struct V_24 * V_248 , struct V_30 * V_249 [] )
{
struct V_24 * V_24 ;
if ( V_249 [ V_250 ] )
V_24 = F_110 ( F_111 ( V_249 [ V_250 ] ) ) ;
else if ( V_249 [ V_251 ] )
V_24 = F_112 ( F_111 ( V_249 [ V_251 ] ) ) ;
else
V_24 = F_113 ( V_248 ) ;
return V_24 ;
}
static int F_114 ( struct V_25 * V_26 , struct V_30 * V_249 [] )
{
if ( V_26 ) {
if ( V_249 [ V_202 ] &&
F_115 ( V_249 [ V_202 ] ) < V_26 -> V_201 )
return - V_252 ;
if ( V_249 [ V_204 ] &&
F_115 ( V_249 [ V_204 ] ) < V_26 -> V_201 )
return - V_252 ;
}
if ( V_249 [ V_226 ] ) {
struct V_30 * V_228 ;
int V_253 , V_23 ;
F_116 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_33 * V_35 ;
if ( ! ( V_35 = F_39 ( F_117 ( V_228 ) ) ) )
return - V_254 ;
if ( ! V_35 -> V_255 )
return - V_256 ;
if ( V_35 -> V_257 ) {
V_23 = V_35 -> V_257 ( V_26 , V_228 ) ;
if ( V_23 < 0 )
return V_23 ;
}
}
}
return 0 ;
}
static int F_118 ( struct V_25 * V_26 , struct V_30 * V_165 )
{
int V_253 , V_23 = - V_252 ;
struct V_30 * V_154 ;
const struct V_258 * V_18 = V_26 -> V_146 ;
F_116 (vf, attr, rem) {
switch ( F_117 ( V_154 ) ) {
case V_223 : {
struct V_136 * V_259 ;
V_259 = F_101 ( V_154 ) ;
V_23 = - V_256 ;
if ( V_18 -> V_260 )
V_23 = V_18 -> V_260 ( V_26 , V_259 -> V_154 ,
V_259 -> V_217 ) ;
break;
}
case V_224 : {
struct V_137 * V_261 ;
V_261 = F_101 ( V_154 ) ;
V_23 = - V_256 ;
if ( V_18 -> V_262 )
V_23 = V_18 -> V_262 ( V_26 , V_261 -> V_154 ,
V_261 -> V_218 ,
V_261 -> V_219 ) ;
break;
}
case V_225 : {
struct V_138 * V_263 ;
V_263 = F_101 ( V_154 ) ;
V_23 = - V_256 ;
if ( V_18 -> V_264 )
V_23 = V_18 -> V_264 ( V_26 , V_263 -> V_154 ,
V_263 -> V_220 ) ;
break;
}
default:
V_23 = - V_252 ;
break;
}
if ( V_23 )
break;
}
return V_23 ;
}
static int F_119 ( struct V_25 * V_26 , int V_172 )
{
struct V_25 * V_265 ;
const struct V_258 * V_18 ;
int V_23 ;
if ( V_26 -> V_186 ) {
if ( V_26 -> V_186 -> V_172 == V_172 )
return 0 ;
V_18 = V_26 -> V_186 -> V_146 ;
if ( V_18 -> V_266 ) {
V_23 = V_18 -> V_266 ( V_26 -> V_186 , V_26 ) ;
if ( V_23 )
return V_23 ;
} else {
return - V_256 ;
}
}
if ( V_172 ) {
V_265 = F_120 ( F_121 ( V_26 ) , V_172 ) ;
if ( ! V_265 )
return - V_252 ;
V_18 = V_265 -> V_146 ;
if ( V_18 -> V_267 ) {
V_23 = V_18 -> V_267 ( V_265 , V_26 ) ;
if ( V_23 )
return V_23 ;
} else {
return - V_256 ;
}
}
return 0 ;
}
static int F_122 ( struct V_25 * V_26 , struct V_102 * V_103 ,
struct V_30 * * V_249 , char * V_268 , int V_269 )
{
const struct V_258 * V_18 = V_26 -> V_146 ;
int V_270 = 0 ;
int V_23 ;
if ( V_249 [ V_250 ] || V_249 [ V_251 ] ) {
struct V_24 * V_24 = F_109 ( F_121 ( V_26 ) , V_249 ) ;
if ( F_123 ( V_24 ) ) {
V_23 = F_124 ( V_24 ) ;
goto V_271;
}
V_23 = F_125 ( V_26 , V_24 , V_268 ) ;
F_126 ( V_24 ) ;
if ( V_23 )
goto V_271;
V_269 = 1 ;
}
if ( V_249 [ V_200 ] ) {
struct V_150 * V_272 ;
struct V_273 V_274 ;
if ( ! V_18 -> V_275 ) {
V_23 = - V_256 ;
goto V_271;
}
if ( ! F_127 ( V_26 ) ) {
V_23 = - V_276 ;
goto V_271;
}
V_272 = F_101 ( V_249 [ V_200 ] ) ;
V_274 . V_193 = ( unsigned long ) V_272 -> V_193 ;
V_274 . V_194 = ( unsigned long ) V_272 -> V_194 ;
V_274 . V_195 = ( unsigned short ) V_272 -> V_195 ;
V_274 . V_196 = ( unsigned char ) V_272 -> V_196 ;
V_274 . V_197 = ( unsigned char ) V_272 -> V_197 ;
V_274 . V_198 = ( unsigned char ) V_272 -> V_198 ;
V_23 = V_18 -> V_275 ( V_26 , & V_274 ) ;
if ( V_23 < 0 )
goto V_271;
V_269 = 1 ;
}
if ( V_249 [ V_202 ] ) {
struct V_277 * V_278 ;
int V_247 ;
if ( ! V_18 -> V_279 ) {
V_23 = - V_256 ;
goto V_271;
}
if ( ! F_127 ( V_26 ) ) {
V_23 = - V_276 ;
goto V_271;
}
V_247 = sizeof( V_280 ) + V_26 -> V_201 ;
V_278 = F_128 ( V_247 , V_14 ) ;
if ( ! V_278 ) {
V_23 = - V_281 ;
goto V_271;
}
V_278 -> V_282 = V_26 -> type ;
memcpy ( V_278 -> V_283 , F_101 ( V_249 [ V_202 ] ) ,
V_26 -> V_201 ) ;
V_23 = V_18 -> V_279 ( V_26 , V_278 ) ;
F_23 ( V_278 ) ;
if ( V_23 )
goto V_271;
V_270 = 1 ;
V_269 = 1 ;
}
if ( V_249 [ V_181 ] ) {
V_23 = F_129 ( V_26 , F_111 ( V_249 [ V_181 ] ) ) ;
if ( V_23 < 0 )
goto V_271;
V_269 = 1 ;
}
if ( V_249 [ V_183 ] ) {
F_130 ( V_26 , F_111 ( V_249 [ V_183 ] ) ) ;
V_269 = 1 ;
}
if ( V_103 -> V_171 > 0 && V_268 [ 0 ] ) {
V_23 = F_131 ( V_26 , V_268 ) ;
if ( V_23 < 0 )
goto V_271;
V_269 = 1 ;
}
if ( V_249 [ V_191 ] ) {
V_23 = F_132 ( V_26 , F_101 ( V_249 [ V_191 ] ) ,
F_115 ( V_249 [ V_191 ] ) ) ;
if ( V_23 < 0 )
goto V_271;
V_269 = 1 ;
}
if ( V_249 [ V_204 ] ) {
F_133 ( V_26 -> V_205 , V_249 [ V_204 ] , V_26 -> V_201 ) ;
V_270 = 1 ;
}
if ( V_103 -> V_104 || V_103 -> V_105 ) {
V_23 = F_134 ( V_26 , F_78 ( V_26 , V_103 ) ) ;
if ( V_23 < 0 )
goto V_271;
}
if ( V_249 [ V_187 ] ) {
V_23 = F_119 ( V_26 , F_111 ( V_249 [ V_187 ] ) ) ;
if ( V_23 )
goto V_271;
V_269 = 1 ;
}
if ( V_249 [ V_175 ] )
V_26 -> V_176 = F_111 ( V_249 [ V_175 ] ) ;
if ( V_249 [ V_177 ] )
F_73 ( V_26 , F_135 ( V_249 [ V_177 ] ) ) ;
if ( V_249 [ V_179 ] ) {
F_75 ( & V_101 ) ;
V_26 -> V_180 = F_135 ( V_249 [ V_179 ] ) ;
F_76 ( & V_101 ) ;
}
if ( V_249 [ V_211 ] ) {
struct V_30 * V_165 ;
int V_253 ;
F_116 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_117 ( V_165 ) != V_222 ) {
V_23 = - V_252 ;
goto V_271;
}
V_23 = F_118 ( V_26 , V_165 ) ;
if ( V_23 < 0 )
goto V_271;
V_269 = 1 ;
}
}
V_23 = 0 ;
if ( V_249 [ V_155 ] ) {
struct V_30 * V_198 [ V_284 + 1 ] ;
struct V_30 * V_165 ;
int V_154 ;
int V_253 ;
V_23 = - V_256 ;
if ( ! V_18 -> V_285 )
goto V_271;
F_116 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_117 ( V_165 ) != V_156 )
continue;
V_23 = F_136 ( V_198 , V_284 ,
V_165 , V_286 ) ;
if ( V_23 < 0 )
goto V_271;
if ( ! V_198 [ V_157 ] ) {
V_23 = - V_256 ;
goto V_271;
}
V_154 = F_111 ( V_198 [ V_157 ] ) ;
V_23 = V_18 -> V_285 ( V_26 , V_154 , V_198 ) ;
if ( V_23 < 0 )
goto V_271;
V_269 = 1 ;
}
}
V_23 = 0 ;
if ( V_249 [ V_159 ] ) {
struct V_30 * V_198 [ V_284 + 1 ] ;
V_23 = F_136 ( V_198 , V_284 ,
V_249 [ V_159 ] , V_286 ) ;
if ( V_23 < 0 )
goto V_271;
V_23 = - V_256 ;
if ( V_18 -> V_285 )
V_23 = V_18 -> V_285 ( V_26 , V_160 , V_198 ) ;
if ( V_23 < 0 )
goto V_271;
V_269 = 1 ;
}
if ( V_249 [ V_226 ] ) {
struct V_30 * V_228 ;
int V_253 ;
F_116 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_33 * V_35 ;
if ( ! ( V_35 = F_39 ( F_117 ( V_228 ) ) ) )
F_137 () ;
V_23 = V_35 -> V_255 ( V_26 , V_228 ) ;
if ( V_23 < 0 )
goto V_271;
V_269 = 1 ;
}
}
V_23 = 0 ;
V_271:
if ( V_23 < 0 && V_269 && F_138 () )
F_139 ( V_287 L_3
L_4
L_5
L_6 , V_26 -> V_174 ) ;
if ( V_270 )
F_140 ( V_288 , V_26 ) ;
return V_23 ;
}
static int F_141 ( struct V_37 * V_38 , struct V_64 * V_65 , void * V_289 )
{
struct V_24 * V_24 = F_105 ( V_38 -> V_232 ) ;
struct V_102 * V_103 ;
struct V_25 * V_26 ;
int V_23 ;
struct V_30 * V_249 [ V_290 + 1 ] ;
char V_268 [ V_148 ] ;
V_23 = F_142 ( V_65 , sizeof( * V_103 ) , V_249 , V_290 , V_291 ) ;
if ( V_23 < 0 )
goto V_271;
if ( V_249 [ V_173 ] )
F_143 ( V_268 , V_249 [ V_173 ] , V_148 ) ;
else
V_268 [ 0 ] = '\0' ;
V_23 = - V_252 ;
V_103 = F_93 ( V_65 ) ;
if ( V_103 -> V_171 > 0 )
V_26 = F_120 ( V_24 , V_103 -> V_171 ) ;
else if ( V_249 [ V_173 ] )
V_26 = F_144 ( V_24 , V_268 ) ;
else
goto V_271;
if ( V_26 == NULL ) {
V_23 = - V_276 ;
goto V_271;
}
V_23 = F_114 ( V_26 , V_249 ) ;
if ( V_23 < 0 )
goto V_271;
V_23 = F_122 ( V_26 , V_103 , V_249 , V_268 , 0 ) ;
V_271:
return V_23 ;
}
static int F_145 ( struct V_37 * V_38 , struct V_64 * V_65 , void * V_289 )
{
struct V_24 * V_24 = F_105 ( V_38 -> V_232 ) ;
const struct V_17 * V_18 ;
struct V_25 * V_26 ;
struct V_102 * V_103 ;
char V_268 [ V_148 ] ;
struct V_30 * V_249 [ V_290 + 1 ] ;
int V_23 ;
F_28 ( V_27 ) ;
V_23 = F_142 ( V_65 , sizeof( * V_103 ) , V_249 , V_290 , V_291 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_249 [ V_173 ] )
F_143 ( V_268 , V_249 [ V_173 ] , V_148 ) ;
V_103 = F_93 ( V_65 ) ;
if ( V_103 -> V_171 > 0 )
V_26 = F_120 ( V_24 , V_103 -> V_171 ) ;
else if ( V_249 [ V_173 ] )
V_26 = F_144 ( V_24 , V_268 ) ;
else
return - V_252 ;
if ( ! V_26 )
return - V_276 ;
V_18 = V_26 -> V_17 ;
if ( ! V_18 )
return - V_256 ;
V_18 -> V_19 ( V_26 , & V_27 ) ;
F_30 ( & V_27 ) ;
F_33 ( & V_27 ) ;
return 0 ;
}
int F_146 ( struct V_25 * V_26 , const struct V_102 * V_103 )
{
unsigned int V_292 ;
int V_23 ;
V_292 = V_26 -> V_66 ;
if ( V_103 && ( V_103 -> V_104 || V_103 -> V_105 ) ) {
V_23 = F_147 ( V_26 , F_78 ( V_26 , V_103 ) ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_26 -> V_293 = V_294 ;
F_148 ( V_244 , V_26 , ~ 0U ) ;
F_149 ( V_26 , V_292 ) ;
return 0 ;
}
struct V_25 * F_150 ( struct V_24 * V_248 , struct V_24 * V_24 ,
char * V_268 , const struct V_17 * V_18 , struct V_30 * V_249 [] )
{
int V_23 ;
struct V_25 * V_26 ;
unsigned int V_295 = 1 ;
unsigned int V_296 = 1 ;
if ( V_18 -> V_297 ) {
V_23 = V_18 -> V_297 ( V_248 , V_249 , & V_295 ,
& V_296 ) ;
if ( V_23 )
goto V_23;
}
V_23 = - V_281 ;
V_26 = F_151 ( V_18 -> V_298 , V_268 , V_18 -> V_299 , V_295 ) ;
if ( ! V_26 )
goto V_23;
F_152 ( V_26 , V_24 ) ;
V_26 -> V_17 = V_18 ;
V_26 -> V_293 = V_300 ;
V_26 -> V_301 = V_296 ;
if ( V_249 [ V_181 ] )
V_26 -> V_182 = F_111 ( V_249 [ V_181 ] ) ;
if ( V_249 [ V_202 ] )
memcpy ( V_26 -> V_203 , F_101 ( V_249 [ V_202 ] ) ,
F_115 ( V_249 [ V_202 ] ) ) ;
if ( V_249 [ V_204 ] )
memcpy ( V_26 -> V_205 , F_101 ( V_249 [ V_204 ] ) ,
F_115 ( V_249 [ V_204 ] ) ) ;
if ( V_249 [ V_175 ] )
V_26 -> V_176 = F_111 ( V_249 [ V_175 ] ) ;
if ( V_249 [ V_177 ] )
F_73 ( V_26 , F_135 ( V_249 [ V_177 ] ) ) ;
if ( V_249 [ V_179 ] )
V_26 -> V_180 = F_135 ( V_249 [ V_179 ] ) ;
if ( V_249 [ V_183 ] )
F_130 ( V_26 , F_111 ( V_249 [ V_183 ] ) ) ;
return V_26 ;
V_23:
return F_153 ( V_23 ) ;
}
static int F_154 ( struct V_24 * V_24 , int V_57 ,
struct V_102 * V_103 ,
struct V_30 * * V_249 )
{
struct V_25 * V_26 ;
int V_23 ;
F_29 (net, dev) {
if ( V_26 -> V_57 == V_57 ) {
V_23 = F_122 ( V_26 , V_103 , V_249 , NULL , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
}
}
return 0 ;
}
static int F_155 ( struct V_37 * V_38 , struct V_64 * V_65 , void * V_289 )
{
struct V_24 * V_24 = F_105 ( V_38 -> V_232 ) ;
const struct V_17 * V_18 ;
struct V_25 * V_26 ;
struct V_102 * V_103 ;
char V_28 [ V_302 ] ;
char V_268 [ V_148 ] ;
struct V_30 * V_249 [ V_290 + 1 ] ;
struct V_30 * V_39 [ V_303 + 1 ] ;
int V_23 ;
#ifdef F_156
V_304:
#endif
V_23 = F_142 ( V_65 , sizeof( * V_103 ) , V_249 , V_290 , V_291 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_249 [ V_173 ] )
F_143 ( V_268 , V_249 [ V_173 ] , V_148 ) ;
else
V_268 [ 0 ] = '\0' ;
V_103 = F_93 ( V_65 ) ;
if ( V_103 -> V_171 > 0 )
V_26 = F_120 ( V_24 , V_103 -> V_171 ) ;
else {
if ( V_268 [ 0 ] )
V_26 = F_144 ( V_24 , V_268 ) ;
else
V_26 = NULL ;
}
V_23 = F_114 ( V_26 , V_249 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_249 [ V_42 ] ) {
V_23 = F_136 ( V_39 , V_303 ,
V_249 [ V_42 ] , V_305 ) ;
if ( V_23 < 0 )
return V_23 ;
} else
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
if ( V_39 [ V_44 ] ) {
F_143 ( V_28 , V_39 [ V_44 ] , sizeof( V_28 ) ) ;
V_18 = F_35 ( V_28 ) ;
} else {
V_28 [ 0 ] = '\0' ;
V_18 = NULL ;
}
if ( 1 ) {
struct V_30 * V_165 [ V_18 ? V_18 -> V_306 + 1 : 0 ] , * * V_40 = NULL ;
struct V_24 * V_307 ;
if ( V_18 ) {
if ( V_18 -> V_306 && V_39 [ V_48 ] ) {
V_23 = F_136 ( V_165 , V_18 -> V_306 ,
V_39 [ V_48 ] ,
V_18 -> V_308 ) ;
if ( V_23 < 0 )
return V_23 ;
V_40 = V_165 ;
}
if ( V_18 -> V_309 ) {
V_23 = V_18 -> V_309 ( V_249 , V_40 ) ;
if ( V_23 < 0 )
return V_23 ;
}
}
if ( V_26 ) {
int V_269 = 0 ;
if ( V_65 -> V_310 & V_311 )
return - V_312 ;
if ( V_65 -> V_310 & V_313 )
return - V_256 ;
if ( V_39 [ V_48 ] ) {
if ( ! V_18 || V_18 != V_26 -> V_17 ||
! V_18 -> V_314 )
return - V_256 ;
V_23 = V_18 -> V_314 ( V_26 , V_249 , V_40 ) ;
if ( V_23 < 0 )
return V_23 ;
V_269 = 1 ;
}
return F_122 ( V_26 , V_103 , V_249 , V_268 , V_269 ) ;
}
if ( ! ( V_65 -> V_310 & V_315 ) ) {
if ( V_103 -> V_171 == 0 && V_249 [ V_183 ] )
return F_154 ( V_24 ,
F_111 ( V_249 [ V_183 ] ) ,
V_103 , V_249 ) ;
return - V_276 ;
}
if ( V_103 -> V_171 )
return - V_256 ;
if ( V_249 [ V_200 ] || V_249 [ V_187 ] || V_249 [ V_316 ] )
return - V_256 ;
if ( ! V_18 ) {
#ifdef F_156
if ( V_28 [ 0 ] ) {
F_3 () ;
F_157 ( L_7 , V_28 ) ;
F_1 () ;
V_18 = F_35 ( V_28 ) ;
if ( V_18 )
goto V_304;
}
#endif
return - V_256 ;
}
if ( ! V_268 [ 0 ] )
snprintf ( V_268 , V_148 , L_8 , V_18 -> V_28 ) ;
V_307 = F_109 ( V_24 , V_249 ) ;
if ( F_123 ( V_307 ) )
return F_124 ( V_307 ) ;
V_26 = F_150 ( V_24 , V_307 , V_268 , V_18 , V_249 ) ;
if ( F_123 ( V_26 ) )
V_23 = F_124 ( V_26 ) ;
else if ( V_18 -> V_317 )
V_23 = V_18 -> V_317 ( V_24 , V_26 , V_249 , V_40 ) ;
else
V_23 = F_158 ( V_26 ) ;
if ( V_23 < 0 && ! F_123 ( V_26 ) )
F_159 ( V_26 ) ;
if ( V_23 < 0 )
goto V_43;
V_23 = F_146 ( V_26 , V_103 ) ;
if ( V_23 < 0 )
F_160 ( V_26 ) ;
V_43:
F_126 ( V_307 ) ;
return V_23 ;
}
}
static int F_161 ( struct V_37 * V_38 , struct V_64 * V_65 , void * V_289 )
{
struct V_24 * V_24 = F_105 ( V_38 -> V_232 ) ;
struct V_102 * V_103 ;
char V_268 [ V_148 ] ;
struct V_30 * V_249 [ V_290 + 1 ] ;
struct V_25 * V_26 = NULL ;
struct V_37 * V_318 ;
int V_23 ;
V_23 = F_142 ( V_65 , sizeof( * V_103 ) , V_249 , V_290 , V_291 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_249 [ V_173 ] )
F_143 ( V_268 , V_249 [ V_173 ] , V_148 ) ;
V_103 = F_93 ( V_65 ) ;
if ( V_103 -> V_171 > 0 )
V_26 = F_120 ( V_24 , V_103 -> V_171 ) ;
else if ( V_249 [ V_173 ] )
V_26 = F_144 ( V_24 , V_268 ) ;
else
return - V_252 ;
if ( V_26 == NULL )
return - V_276 ;
V_318 = F_162 ( F_85 ( V_26 ) , V_14 ) ;
if ( V_318 == NULL )
return - V_15 ;
V_23 = F_90 ( V_318 , V_26 , V_244 , F_56 ( V_38 ) . V_56 ,
V_65 -> V_245 , 0 , 0 ) ;
if ( V_23 < 0 ) {
F_163 ( V_23 == - V_41 ) ;
F_164 ( V_318 ) ;
} else
V_23 = F_60 ( V_318 , V_24 , F_56 ( V_38 ) . V_56 ) ;
return V_23 ;
}
static int F_165 ( struct V_37 * V_38 , struct V_230 * V_231 )
{
int V_235 ;
int V_236 = V_231 -> V_34 ;
if ( V_236 == 0 )
V_236 = 1 ;
for ( V_235 = 1 ; V_235 <= V_9 ; V_235 ++ ) {
int type = V_231 -> V_65 -> V_319 - V_4 ;
if ( V_235 < V_236 || V_235 == V_320 )
continue;
if ( V_10 [ V_235 ] == NULL ||
V_10 [ V_235 ] [ type ] . V_13 == NULL )
continue;
if ( V_235 > V_236 )
memset ( & V_231 -> args [ 0 ] , 0 , sizeof( V_231 -> args ) ) ;
if ( V_10 [ V_235 ] [ type ] . V_13 ( V_38 , V_231 ) )
break;
}
V_231 -> V_34 = V_235 ;
return V_38 -> V_247 ;
}
void F_148 ( int type , struct V_25 * V_26 , unsigned V_162 )
{
struct V_24 * V_24 = F_121 ( V_26 ) ;
struct V_37 * V_38 ;
int V_23 = - V_15 ;
V_38 = F_162 ( F_85 ( V_26 ) , V_14 ) ;
if ( V_38 == NULL )
goto V_271;
V_23 = F_90 ( V_38 , V_26 , type , 0 , 0 , V_162 , 0 ) ;
if ( V_23 < 0 ) {
F_163 ( V_23 == - V_41 ) ;
F_164 ( V_38 ) ;
goto V_271;
}
F_62 ( V_38 , V_24 , 0 , V_321 , NULL , V_14 ) ;
return;
V_271:
if ( V_23 < 0 )
F_65 ( V_24 , V_321 , V_23 ) ;
}
static int F_166 ( struct V_37 * V_38 , struct V_64 * V_65 )
{
struct V_24 * V_24 = F_105 ( V_38 -> V_232 ) ;
T_1 V_11 ;
int V_322 , V_28 ;
int V_323 ;
int V_34 ;
int type ;
int V_23 ;
type = V_65 -> V_319 ;
if ( type > V_324 )
return - V_256 ;
type -= V_4 ;
if ( V_65 -> V_325 < F_167 ( sizeof( struct V_326 ) ) )
return 0 ;
V_34 = ( (struct V_326 * ) F_168 ( V_65 ) ) -> V_327 ;
V_322 = type >> 2 ;
V_28 = type & 3 ;
if ( V_28 != 2 && F_169 ( V_38 , V_328 ) )
return - V_329 ;
if ( V_28 == 2 && V_65 -> V_310 & V_330 ) {
struct V_59 * V_60 ;
T_2 V_13 ;
V_13 = F_16 ( V_34 , type ) ;
if ( V_13 == NULL )
return - V_256 ;
F_3 () ;
V_60 = V_24 -> V_60 ;
V_23 = F_170 ( V_60 , V_38 , V_65 , V_13 , NULL ) ;
F_1 () ;
return V_23 ;
}
memset ( V_331 , 0 , ( V_332 * sizeof( struct V_52 * ) ) ) ;
V_323 = V_333 [ V_322 ] ;
if ( V_65 -> V_325 < V_323 )
return - V_252 ;
if ( V_65 -> V_325 > V_323 ) {
int V_51 = V_65 -> V_325 - F_86 ( V_323 ) ;
struct V_52 * V_165 = ( void * ) V_65 + F_86 ( V_323 ) ;
while ( F_171 ( V_165 , V_51 ) ) {
unsigned V_334 = V_165 -> V_54 ;
if ( V_334 ) {
if ( V_334 > V_335 [ V_322 ] )
return - V_252 ;
V_331 [ V_334 - 1 ] = V_165 ;
}
V_165 = F_172 ( V_165 , V_51 ) ;
}
}
V_11 = F_15 ( V_34 , type ) ;
if ( V_11 == NULL )
return - V_256 ;
return V_11 ( V_38 , V_65 , ( void * ) & V_331 [ 0 ] ) ;
}
static void F_173 ( struct V_37 * V_38 )
{
F_1 () ;
F_174 ( V_38 , & F_166 ) ;
F_5 () ;
}
static int F_175 ( struct V_336 * V_337 , unsigned long V_338 , void * V_339 )
{
struct V_25 * V_26 = V_339 ;
switch ( V_338 ) {
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
break;
default:
F_148 ( V_244 , V_26 , 0 ) ;
break;
}
return V_352 ;
}
static int T_7 F_176 ( struct V_24 * V_24 )
{
struct V_59 * V_232 ;
V_232 = F_177 ( V_24 , V_353 , V_354 ,
F_173 , & V_1 , V_355 ) ;
if ( ! V_232 )
return - V_281 ;
V_24 -> V_60 = V_232 ;
return 0 ;
}
static void T_8 F_178 ( struct V_24 * V_24 )
{
F_179 ( V_24 -> V_60 ) ;
V_24 -> V_60 = NULL ;
}
void T_9 F_180 ( void )
{
int V_70 ;
V_332 = 0 ;
for ( V_70 = 0 ; V_70 < F_181 ( V_335 ) ; V_70 ++ )
if ( V_335 [ V_70 ] > V_332 )
V_332 = V_335 [ V_70 ] ;
V_331 = F_128 ( V_332 * sizeof( struct V_52 * ) , V_14 ) ;
if ( ! V_331 )
F_20 ( L_9 ) ;
if ( F_182 ( & V_356 ) )
F_20 ( L_10 ) ;
F_183 ( V_353 , V_357 ) ;
F_184 ( & V_358 ) ;
F_19 ( V_12 , V_359 , F_161 , F_104 ) ;
F_19 ( V_12 , V_360 , F_141 , NULL ) ;
F_19 ( V_12 , V_244 , F_155 , NULL ) ;
F_19 ( V_12 , V_361 , F_145 , NULL ) ;
F_19 ( V_12 , V_362 , NULL , F_165 ) ;
F_19 ( V_12 , V_363 , NULL , F_165 ) ;
}
