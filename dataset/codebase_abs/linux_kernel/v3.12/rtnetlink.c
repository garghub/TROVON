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
return V_8 [ V_3 ] . V_11 ;
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
return V_8 [ V_3 ] . V_13 ;
}
static T_3 F_17 ( int V_6 , int V_3 )
{
struct V_7 * V_8 ;
if ( V_6 <= V_9 )
V_8 = V_10 [ V_6 ] ;
else
V_8 = NULL ;
if ( V_8 == NULL || V_8 [ V_3 ] . V_14 == NULL )
V_8 = V_10 [ V_12 ] ;
return V_8 [ V_3 ] . V_14 ;
}
int F_18 ( int V_6 , int V_2 ,
T_1 V_11 , T_2 V_13 ,
T_3 V_14 )
{
struct V_7 * V_8 ;
int V_3 ;
F_14 ( V_6 < 0 || V_6 > V_9 ) ;
V_3 = F_13 ( V_2 ) ;
V_8 = V_10 [ V_6 ] ;
if ( V_8 == NULL ) {
V_8 = F_19 ( V_5 , sizeof( * V_8 ) , V_15 ) ;
if ( V_8 == NULL )
return - V_16 ;
V_10 [ V_6 ] = V_8 ;
}
if ( V_11 )
V_8 [ V_3 ] . V_11 = V_11 ;
if ( V_13 )
V_8 [ V_3 ] . V_13 = V_13 ;
if ( V_14 )
V_8 [ V_3 ] . V_14 = V_14 ;
return 0 ;
}
void F_20 ( int V_6 , int V_2 ,
T_1 V_11 , T_2 V_13 ,
T_3 V_14 )
{
if ( F_18 ( V_6 , V_2 , V_11 , V_13 , V_14 ) < 0 )
F_21 ( L_1
L_2 ,
V_6 , V_2 ) ;
}
int F_22 ( int V_6 , int V_2 )
{
int V_3 ;
F_14 ( V_6 < 0 || V_6 > V_9 ) ;
V_3 = F_13 ( V_2 ) ;
if ( V_10 [ V_6 ] == NULL )
return - V_17 ;
V_10 [ V_6 ] [ V_3 ] . V_11 = NULL ;
V_10 [ V_6 ] [ V_3 ] . V_13 = NULL ;
return 0 ;
}
void F_23 ( int V_6 )
{
F_14 ( V_6 < 0 || V_6 > V_9 ) ;
F_24 ( V_10 [ V_6 ] ) ;
V_10 [ V_6 ] = NULL ;
}
static const struct V_18 * F_25 ( const char * V_19 )
{
const struct V_18 * V_20 ;
F_26 (ops, &link_ops, list) {
if ( ! strcmp ( V_20 -> V_19 , V_19 ) )
return V_20 ;
}
return NULL ;
}
int F_27 ( struct V_18 * V_20 )
{
if ( F_25 ( V_20 -> V_19 ) )
return - V_21 ;
if ( ! V_20 -> V_22 )
V_20 -> V_22 = V_23 ;
F_28 ( & V_20 -> V_24 , & V_25 ) ;
return 0 ;
}
int F_29 ( struct V_18 * V_20 )
{
int V_26 ;
F_1 () ;
V_26 = F_27 ( V_20 ) ;
F_5 () ;
return V_26 ;
}
static void F_30 ( struct V_27 * V_27 , struct V_18 * V_20 )
{
struct V_28 * V_29 ;
F_31 ( V_30 ) ;
F_32 (net, dev) {
if ( V_29 -> V_18 == V_20 )
V_20 -> V_22 ( V_29 , & V_30 ) ;
}
F_33 ( & V_30 ) ;
}
void F_34 ( struct V_18 * V_20 )
{
struct V_27 * V_27 ;
F_35 (net) {
F_30 ( V_27 , V_20 ) ;
}
F_36 ( & V_20 -> V_24 ) ;
}
void F_37 ( struct V_18 * V_20 )
{
F_1 () ;
F_34 ( V_20 ) ;
F_5 () ;
}
static T_4 F_38 ( const struct V_28 * V_29 )
{
const struct V_18 * V_20 = V_29 -> V_18 ;
T_4 V_31 ;
if ( ! V_20 )
return 0 ;
V_31 = F_39 ( sizeof( struct V_32 ) ) +
F_39 ( strlen ( V_20 -> V_19 ) + 1 ) ;
if ( V_20 -> V_33 )
V_31 += F_39 ( sizeof( struct V_32 ) ) +
V_20 -> V_33 ( V_29 ) ;
if ( V_20 -> V_34 )
V_31 += F_39 ( V_20 -> V_34 ( V_29 ) ) ;
return V_31 ;
}
static const struct V_35 * F_40 ( const int V_36 )
{
const struct V_35 * V_20 ;
F_26 (ops, &rtnl_af_ops, list) {
if ( V_20 -> V_36 == V_36 )
return V_20 ;
}
return NULL ;
}
int F_41 ( struct V_35 * V_20 )
{
F_28 ( & V_20 -> V_24 , & V_35 ) ;
return 0 ;
}
int F_42 ( struct V_35 * V_20 )
{
int V_26 ;
F_1 () ;
V_26 = F_41 ( V_20 ) ;
F_5 () ;
return V_26 ;
}
void F_43 ( struct V_35 * V_20 )
{
F_36 ( & V_20 -> V_24 ) ;
}
void F_44 ( struct V_35 * V_20 )
{
F_1 () ;
F_43 ( V_20 ) ;
F_5 () ;
}
static T_4 F_45 ( const struct V_28 * V_29 )
{
struct V_35 * V_37 ;
T_4 V_31 ;
V_31 = F_39 ( sizeof( struct V_32 ) ) ;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_37 -> V_38 ) {
V_31 += F_39 ( sizeof( struct V_32 ) ) +
V_37 -> V_38 ( V_29 ) ;
}
}
return V_31 ;
}
static int F_46 ( struct V_39 * V_40 , const struct V_28 * V_29 )
{
const struct V_18 * V_20 = V_29 -> V_18 ;
struct V_32 * V_41 , * V_42 ;
int V_26 = - V_43 ;
V_41 = F_47 ( V_40 , V_44 ) ;
if ( V_41 == NULL )
goto V_45;
if ( F_48 ( V_40 , V_46 , V_20 -> V_19 ) < 0 )
goto V_47;
if ( V_20 -> V_48 ) {
V_26 = V_20 -> V_48 ( V_40 , V_29 ) ;
if ( V_26 < 0 )
goto V_47;
}
if ( V_20 -> V_49 ) {
V_42 = F_47 ( V_40 , V_50 ) ;
if ( V_42 == NULL ) {
V_26 = - V_43 ;
goto V_47;
}
V_26 = V_20 -> V_49 ( V_40 , V_29 ) ;
if ( V_26 < 0 )
goto V_51;
F_49 ( V_40 , V_42 ) ;
}
F_49 ( V_40 , V_41 ) ;
return 0 ;
V_51:
F_50 ( V_40 , V_42 ) ;
V_47:
F_50 ( V_40 , V_41 ) ;
V_45:
return V_26 ;
}
int F_51 ( struct V_39 * V_40 , struct V_27 * V_27 , T_5 V_52 , unsigned int V_53 , int V_54 )
{
struct V_55 * V_56 = V_27 -> V_56 ;
int V_26 = 0 ;
F_52 ( V_40 ) . V_57 = V_53 ;
if ( V_54 )
F_53 ( & V_40 -> V_58 ) ;
F_54 ( V_56 , V_40 , V_52 , V_53 , V_15 ) ;
if ( V_54 )
V_26 = F_55 ( V_56 , V_40 , V_52 , V_59 ) ;
return V_26 ;
}
int F_56 ( struct V_39 * V_40 , struct V_27 * V_27 , T_5 V_52 )
{
struct V_55 * V_56 = V_27 -> V_56 ;
return F_57 ( V_56 , V_40 , V_52 ) ;
}
void F_58 ( struct V_39 * V_40 , struct V_27 * V_27 , T_5 V_52 , T_5 V_53 ,
struct V_60 * V_61 , T_6 V_62 )
{
struct V_55 * V_56 = V_27 -> V_56 ;
int V_63 = 0 ;
if ( V_61 )
V_63 = F_59 ( V_61 ) ;
F_60 ( V_56 , V_40 , V_52 , V_53 , V_63 , V_62 ) ;
}
void F_61 ( struct V_27 * V_27 , T_5 V_53 , int error )
{
struct V_55 * V_56 = V_27 -> V_56 ;
F_62 ( V_56 , 0 , V_53 , error ) ;
}
int F_63 ( struct V_39 * V_40 , T_5 * V_64 )
{
struct V_32 * V_65 ;
int V_66 , V_67 = 0 ;
V_65 = F_47 ( V_40 , V_68 ) ;
if ( V_65 == NULL )
return - V_16 ;
for ( V_66 = 0 ; V_66 < V_69 ; V_66 ++ ) {
if ( V_64 [ V_66 ] ) {
V_67 ++ ;
if ( F_64 ( V_40 , V_66 + 1 , V_64 [ V_66 ] ) )
goto V_70;
}
}
if ( ! V_67 ) {
F_50 ( V_40 , V_65 ) ;
return 0 ;
}
return F_49 ( V_40 , V_65 ) ;
V_70:
F_50 ( V_40 , V_65 ) ;
return - V_43 ;
}
int F_65 ( struct V_39 * V_40 , struct V_71 * V_72 , T_5 V_73 ,
long V_74 , T_5 error )
{
struct V_75 V_76 = {
. V_77 = F_66 ( V_78 - V_72 -> V_79 ) ,
. V_80 = V_72 -> V_81 ,
. V_82 = F_67 ( & ( V_72 -> V_83 ) ) ,
. V_84 = error ,
. V_85 = V_73 ,
} ;
if ( V_74 ) {
unsigned long clock ;
clock = F_68 ( abs ( V_74 ) ) ;
clock = F_69 (unsigned long, clock, INT_MAX) ;
V_76 . V_86 = ( V_74 > 0 ) ? clock : - clock ;
}
return F_70 ( V_40 , V_87 , sizeof( V_76 ) , & V_76 ) ;
}
static void F_71 ( struct V_28 * V_29 , unsigned char V_88 )
{
unsigned char V_89 = V_29 -> V_89 ;
switch ( V_88 ) {
case V_90 :
if ( ( V_89 == V_91 ||
V_89 == V_92 ) &&
! F_72 ( V_29 ) )
V_89 = V_90 ;
break;
case V_91 :
if ( V_89 == V_90 ||
V_89 == V_92 )
V_89 = V_91 ;
break;
}
if ( V_29 -> V_89 != V_89 ) {
F_73 ( & V_93 ) ;
V_29 -> V_89 = V_89 ;
F_74 ( & V_93 ) ;
F_75 ( V_29 ) ;
}
}
static unsigned int F_76 ( const struct V_28 * V_29 )
{
return ( V_29 -> V_62 & ~ ( V_94 | V_95 ) ) |
( V_29 -> V_96 & ( V_94 | V_95 ) ) ;
}
static unsigned int F_77 ( const struct V_28 * V_29 ,
const struct V_97 * V_98 )
{
unsigned int V_62 = V_98 -> V_99 ;
if ( V_98 -> V_100 )
V_62 = ( V_62 & V_98 -> V_100 ) |
( F_76 ( V_29 ) & ~ V_98 -> V_100 ) ;
return V_62 ;
}
static void F_78 ( struct V_101 * V_102 ,
const struct V_103 * V_104 )
{
V_102 -> V_105 = V_104 -> V_105 ;
V_102 -> V_106 = V_104 -> V_106 ;
V_102 -> V_107 = V_104 -> V_107 ;
V_102 -> V_108 = V_104 -> V_108 ;
V_102 -> V_109 = V_104 -> V_109 ;
V_102 -> V_110 = V_104 -> V_110 ;
V_102 -> V_111 = V_104 -> V_111 ;
V_102 -> V_112 = V_104 -> V_112 ;
V_102 -> V_113 = V_104 -> V_113 ;
V_102 -> V_114 = V_104 -> V_114 ;
V_102 -> V_115 = V_104 -> V_115 ;
V_102 -> V_116 = V_104 -> V_116 ;
V_102 -> V_117 = V_104 -> V_117 ;
V_102 -> V_118 = V_104 -> V_118 ;
V_102 -> V_119 = V_104 -> V_119 ;
V_102 -> V_120 = V_104 -> V_120 ;
V_102 -> V_121 = V_104 -> V_121 ;
V_102 -> V_122 = V_104 -> V_122 ;
V_102 -> V_123 = V_104 -> V_123 ;
V_102 -> V_124 = V_104 -> V_124 ;
V_102 -> V_125 = V_104 -> V_125 ;
V_102 -> V_126 = V_104 -> V_126 ;
V_102 -> V_127 = V_104 -> V_127 ;
}
static void F_79 ( void * V_128 , const struct V_103 * V_104 )
{
memcpy ( V_128 , V_104 , sizeof( * V_104 ) ) ;
}
static inline int F_80 ( const struct V_28 * V_29 ,
T_5 V_129 )
{
if ( V_29 -> V_29 . V_130 && F_81 ( V_29 -> V_29 . V_130 ) &&
( V_129 & V_131 ) ) {
int V_132 = F_82 ( V_29 -> V_29 . V_130 ) ;
T_4 V_31 = F_39 ( sizeof( struct V_32 ) ) ;
V_31 += F_39 ( V_132 * sizeof( struct V_32 ) ) ;
V_31 += V_132 *
( F_39 ( sizeof( struct V_133 ) ) +
F_39 ( sizeof( struct V_134 ) ) +
F_39 ( sizeof( struct V_135 ) ) +
F_39 ( sizeof( struct V_136 ) ) ) ;
return V_31 ;
} else
return 0 ;
}
static T_4 F_83 ( const struct V_28 * V_29 )
{
T_4 V_137 = F_39 ( 4 )
+ F_39 ( V_138 )
+ F_39 ( sizeof( struct V_139 ) )
+ F_39 ( V_140 )
+ F_39 ( V_140 )
+ F_39 ( 1 )
+ F_39 ( 2 ) ;
T_4 V_141 = F_39 ( sizeof( struct V_32 ) ) ;
T_4 V_142 = F_39 ( sizeof( struct V_32 ) )
+ V_137 ;
T_4 V_143 = F_39 ( sizeof( struct V_32 ) )
+ V_137 ;
if ( ! V_29 -> V_144 -> V_145 || ! V_29 -> V_29 . V_130 )
return 0 ;
if ( F_82 ( V_29 -> V_29 . V_130 ) )
return V_143 + V_141 +
V_142 * F_82 ( V_29 -> V_29 . V_130 ) ;
else
return V_143 ;
}
static T_7 T_4 F_84 ( const struct V_28 * V_29 ,
T_5 V_129 )
{
return F_85 ( sizeof( struct V_97 ) )
+ F_39 ( V_146 )
+ F_39 ( V_147 )
+ F_39 ( V_146 )
+ F_39 ( sizeof( struct V_148 ) )
+ F_39 ( sizeof( struct V_101 ) )
+ F_39 ( sizeof( struct V_103 ) )
+ F_39 ( V_149 )
+ F_39 ( V_149 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 1 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 1 )
+ F_39 ( 1 )
+ F_39 ( V_129
& V_131 ? 4 : 0 )
+ F_80 ( V_29 , V_129 )
+ F_83 ( V_29 )
+ F_38 ( V_29 )
+ F_45 ( V_29 )
+ F_39 ( V_150 ) ;
}
static int F_86 ( struct V_39 * V_40 , struct V_28 * V_29 )
{
struct V_32 * V_151 ;
struct V_32 * V_152 ;
int V_153 ;
int V_26 ;
V_151 = F_47 ( V_40 , V_154 ) ;
if ( ! V_151 )
return - V_43 ;
for ( V_153 = 0 ; V_153 < F_82 ( V_29 -> V_29 . V_130 ) ; V_153 ++ ) {
V_152 = F_47 ( V_40 , V_155 ) ;
if ( ! V_152 )
goto V_70;
if ( F_64 ( V_40 , V_156 , V_153 ) )
goto V_70;
V_26 = V_29 -> V_144 -> V_145 ( V_29 , V_153 , V_40 ) ;
if ( V_26 == - V_43 )
goto V_70;
if ( V_26 ) {
F_50 ( V_40 , V_152 ) ;
continue;
}
F_49 ( V_40 , V_152 ) ;
}
F_49 ( V_40 , V_151 ) ;
return 0 ;
V_70:
F_50 ( V_40 , V_151 ) ;
return - V_43 ;
}
static int F_87 ( struct V_39 * V_40 , struct V_28 * V_29 )
{
struct V_32 * V_157 ;
int V_26 ;
V_157 = F_47 ( V_40 , V_158 ) ;
if ( ! V_157 )
return - V_43 ;
V_26 = V_29 -> V_144 -> V_145 ( V_29 , V_159 , V_40 ) ;
if ( V_26 ) {
F_50 ( V_40 , V_157 ) ;
return ( V_26 == - V_43 ) ? V_26 : 0 ;
}
F_49 ( V_40 , V_157 ) ;
return 0 ;
}
static int F_88 ( struct V_39 * V_40 , struct V_28 * V_29 )
{
int V_26 ;
if ( ! V_29 -> V_144 -> V_145 || ! V_29 -> V_29 . V_130 )
return 0 ;
V_26 = F_87 ( V_40 , V_29 ) ;
if ( V_26 )
return V_26 ;
if ( F_82 ( V_29 -> V_29 . V_130 ) ) {
V_26 = F_86 ( V_40 , V_29 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_89 ( struct V_39 * V_40 , struct V_28 * V_29 )
{
int V_26 ;
struct V_160 V_161 ;
V_26 = F_90 ( V_29 , & V_161 ) ;
if ( V_26 ) {
if ( V_26 == - V_162 )
return 0 ;
return V_26 ;
}
if ( F_70 ( V_40 , V_163 , V_161 . V_164 , V_161 . V_73 ) )
return - V_43 ;
return 0 ;
}
static int F_91 ( struct V_39 * V_40 , struct V_28 * V_29 ,
int type , T_5 V_52 , T_5 V_165 , T_5 V_166 ,
unsigned int V_62 , T_5 V_129 )
{
struct V_97 * V_98 ;
struct V_60 * V_61 ;
struct V_103 V_167 ;
const struct V_103 * V_168 ;
struct V_32 * V_169 , * V_170 ;
struct V_35 * V_37 ;
struct V_28 * V_171 = F_92 ( V_29 ) ;
F_93 () ;
V_61 = F_94 ( V_40 , V_52 , V_165 , type , sizeof( * V_98 ) , V_62 ) ;
if ( V_61 == NULL )
return - V_43 ;
V_98 = F_95 ( V_61 ) ;
V_98 -> V_172 = V_173 ;
V_98 -> V_174 = 0 ;
V_98 -> V_175 = V_29 -> type ;
V_98 -> V_176 = V_29 -> V_177 ;
V_98 -> V_99 = F_96 ( V_29 ) ;
V_98 -> V_100 = V_166 ;
if ( F_48 ( V_40 , V_178 , V_29 -> V_179 ) ||
F_64 ( V_40 , V_180 , V_29 -> V_181 ) ||
F_97 ( V_40 , V_182 ,
F_98 ( V_29 ) ? V_29 -> V_89 : V_183 ) ||
F_97 ( V_40 , V_184 , V_29 -> V_185 ) ||
F_64 ( V_40 , V_186 , V_29 -> V_187 ) ||
F_64 ( V_40 , V_188 , V_29 -> V_53 ) ||
F_64 ( V_40 , V_189 , V_29 -> V_190 ) ||
F_64 ( V_40 , V_191 , V_29 -> V_192 ) ||
#ifdef F_99
F_64 ( V_40 , V_193 , V_29 -> V_194 ) ||
#endif
( V_29 -> V_177 != V_29 -> V_195 &&
F_64 ( V_40 , V_196 , V_29 -> V_195 ) ) ||
( V_171 &&
F_64 ( V_40 , V_197 , V_171 -> V_177 ) ) ||
F_97 ( V_40 , V_198 , F_100 ( V_29 ) ) ||
( V_29 -> V_199 &&
F_48 ( V_40 , V_200 , V_29 -> V_199 -> V_20 -> V_73 ) ) ||
( V_29 -> V_201 &&
F_48 ( V_40 , V_202 , V_29 -> V_201 ) ) )
goto V_70;
if ( 1 ) {
struct V_148 V_203 = {
. V_204 = V_29 -> V_204 ,
. V_205 = V_29 -> V_205 ,
. V_206 = V_29 -> V_206 ,
. V_207 = V_29 -> V_207 ,
. V_208 = V_29 -> V_208 ,
. V_209 = V_29 -> V_210 ,
} ;
if ( F_70 ( V_40 , V_211 , sizeof( V_203 ) , & V_203 ) )
goto V_70;
}
if ( V_29 -> V_212 ) {
if ( F_70 ( V_40 , V_213 , V_29 -> V_212 , V_29 -> V_214 ) ||
F_70 ( V_40 , V_215 , V_29 -> V_212 , V_29 -> V_216 ) )
goto V_70;
}
if ( F_89 ( V_40 , V_29 ) )
goto V_70;
V_169 = F_101 ( V_40 , V_217 ,
sizeof( struct V_101 ) ) ;
if ( V_169 == NULL )
goto V_70;
V_168 = F_102 ( V_29 , & V_167 ) ;
F_78 ( F_103 ( V_169 ) , V_168 ) ;
V_169 = F_101 ( V_40 , V_218 ,
sizeof( struct V_103 ) ) ;
if ( V_169 == NULL )
goto V_70;
F_79 ( F_103 ( V_169 ) , V_168 ) ;
if ( V_29 -> V_29 . V_130 && ( V_129 & V_131 ) &&
F_64 ( V_40 , V_219 , F_82 ( V_29 -> V_29 . V_130 ) ) )
goto V_70;
if ( V_29 -> V_144 -> V_220 && V_29 -> V_29 . V_130
&& ( V_129 & V_131 ) ) {
int V_66 ;
struct V_32 * V_221 , * V_153 ;
int V_132 = F_82 ( V_29 -> V_29 . V_130 ) ;
V_221 = F_47 ( V_40 , V_222 ) ;
if ( ! V_221 )
goto V_70;
for ( V_66 = 0 ; V_66 < V_132 ; V_66 ++ ) {
struct V_223 V_224 ;
struct V_133 V_225 ;
struct V_134 V_226 ;
struct V_135 V_227 ;
struct V_136 V_228 ;
struct V_229 V_230 ;
V_224 . V_231 = - 1 ;
memset ( V_224 . V_232 , 0 , sizeof( V_224 . V_232 ) ) ;
V_224 . V_233 = 0 ;
if ( V_29 -> V_144 -> V_220 ( V_29 , V_66 , & V_224 ) )
break;
V_225 . V_153 =
V_226 . V_153 =
V_227 . V_153 =
V_228 . V_153 =
V_230 . V_153 = V_224 . V_153 ;
memcpy ( V_225 . V_232 , V_224 . V_232 , sizeof( V_224 . V_232 ) ) ;
V_226 . V_234 = V_224 . V_234 ;
V_226 . V_235 = V_224 . V_235 ;
V_227 . V_236 = V_224 . V_237 ;
V_228 . V_238 = V_224 . V_231 ;
V_230 . V_239 = V_224 . V_233 ;
V_153 = F_47 ( V_40 , V_240 ) ;
if ( ! V_153 ) {
F_50 ( V_40 , V_221 ) ;
goto V_70;
}
if ( F_70 ( V_40 , V_241 , sizeof( V_225 ) , & V_225 ) ||
F_70 ( V_40 , V_242 , sizeof( V_226 ) , & V_226 ) ||
F_70 ( V_40 , V_243 , sizeof( V_227 ) ,
& V_227 ) ||
F_70 ( V_40 , V_244 , sizeof( V_228 ) ,
& V_228 ) ||
F_70 ( V_40 , V_245 , sizeof( V_230 ) ,
& V_230 ) )
goto V_70;
F_49 ( V_40 , V_153 ) ;
}
F_49 ( V_40 , V_221 ) ;
}
if ( F_88 ( V_40 , V_29 ) )
goto V_70;
if ( V_29 -> V_18 ) {
if ( F_46 ( V_40 , V_29 ) < 0 )
goto V_70;
}
if ( ! ( V_170 = F_47 ( V_40 , V_246 ) ) )
goto V_70;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_37 -> V_247 ) {
struct V_32 * V_248 ;
int V_26 ;
if ( ! ( V_248 = F_47 ( V_40 , V_37 -> V_36 ) ) )
goto V_70;
V_26 = V_37 -> V_247 ( V_40 , V_29 ) ;
if ( V_26 == - V_249 )
F_50 ( V_40 , V_248 ) ;
else if ( V_26 < 0 )
goto V_70;
F_49 ( V_40 , V_248 ) ;
}
}
F_49 ( V_40 , V_170 ) ;
return F_104 ( V_40 , V_61 ) ;
V_70:
F_105 ( V_40 , V_61 ) ;
return - V_43 ;
}
static int F_106 ( struct V_39 * V_40 , struct V_250 * V_251 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
int V_253 , V_254 ;
int V_255 = 0 , V_256 ;
struct V_28 * V_29 ;
struct V_257 * V_258 ;
struct V_32 * V_259 [ V_260 + 1 ] ;
T_5 V_129 = 0 ;
V_254 = V_251 -> args [ 0 ] ;
V_256 = V_251 -> args [ 1 ] ;
F_108 () ;
V_251 -> V_165 = V_27 -> V_261 ;
if ( F_109 ( V_251 -> V_61 , sizeof( struct V_97 ) , V_259 , V_260 ,
V_262 ) >= 0 ) {
if ( V_259 [ V_263 ] )
V_129 = F_110 ( V_259 [ V_263 ] ) ;
}
for ( V_253 = V_254 ; V_253 < V_264 ; V_253 ++ , V_256 = 0 ) {
V_255 = 0 ;
V_258 = & V_27 -> V_265 [ V_253 ] ;
F_111 (dev, head, index_hlist) {
if ( V_255 < V_256 )
goto V_266;
if ( F_91 ( V_40 , V_29 , V_267 ,
F_52 ( V_251 -> V_40 ) . V_268 ,
V_251 -> V_61 -> V_269 , 0 ,
V_270 ,
V_129 ) <= 0 )
goto V_45;
F_112 ( V_251 , F_113 ( V_40 ) ) ;
V_266:
V_255 ++ ;
}
}
V_45:
F_114 () ;
V_251 -> args [ 1 ] = V_255 ;
V_251 -> args [ 0 ] = V_253 ;
return V_40 -> V_271 ;
}
struct V_27 * F_115 ( struct V_27 * V_272 , struct V_32 * V_259 [] )
{
struct V_27 * V_27 ;
if ( V_259 [ V_273 ] )
V_27 = F_116 ( F_110 ( V_259 [ V_273 ] ) ) ;
else if ( V_259 [ V_274 ] )
V_27 = F_117 ( F_110 ( V_259 [ V_274 ] ) ) ;
else
V_27 = F_118 ( V_272 ) ;
return V_27 ;
}
static int F_119 ( struct V_28 * V_29 , struct V_32 * V_259 [] )
{
if ( V_29 ) {
if ( V_259 [ V_213 ] &&
F_120 ( V_259 [ V_213 ] ) < V_29 -> V_212 )
return - V_275 ;
if ( V_259 [ V_215 ] &&
F_120 ( V_259 [ V_215 ] ) < V_29 -> V_212 )
return - V_275 ;
}
if ( V_259 [ V_246 ] ) {
struct V_32 * V_248 ;
int V_276 , V_26 ;
F_121 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_35 * V_37 ;
if ( ! ( V_37 = F_40 ( F_122 ( V_248 ) ) ) )
return - V_277 ;
if ( ! V_37 -> V_278 )
return - V_162 ;
if ( V_37 -> V_279 ) {
V_26 = V_37 -> V_279 ( V_29 , V_248 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
}
return 0 ;
}
static int F_123 ( struct V_28 * V_29 , struct V_32 * V_169 )
{
int V_276 , V_26 = - V_275 ;
struct V_32 * V_153 ;
const struct V_280 * V_20 = V_29 -> V_144 ;
F_121 (vf, attr, rem) {
switch ( F_122 ( V_153 ) ) {
case V_241 : {
struct V_133 * V_281 ;
V_281 = F_103 ( V_153 ) ;
V_26 = - V_162 ;
if ( V_20 -> V_282 )
V_26 = V_20 -> V_282 ( V_29 , V_281 -> V_153 ,
V_281 -> V_232 ) ;
break;
}
case V_242 : {
struct V_134 * V_283 ;
V_283 = F_103 ( V_153 ) ;
V_26 = - V_162 ;
if ( V_20 -> V_284 )
V_26 = V_20 -> V_284 ( V_29 , V_283 -> V_153 ,
V_283 -> V_234 ,
V_283 -> V_235 ) ;
break;
}
case V_243 : {
struct V_135 * V_285 ;
V_285 = F_103 ( V_153 ) ;
V_26 = - V_162 ;
if ( V_20 -> V_286 )
V_26 = V_20 -> V_286 ( V_29 , V_285 -> V_153 ,
V_285 -> V_236 ) ;
break;
}
case V_244 : {
struct V_136 * V_287 ;
V_287 = F_103 ( V_153 ) ;
V_26 = - V_162 ;
if ( V_20 -> V_288 )
V_26 = V_20 -> V_288 ( V_29 , V_287 -> V_153 ,
V_287 -> V_238 ) ;
break;
}
case V_245 : {
struct V_229 * V_289 ;
V_289 = F_103 ( V_153 ) ;
V_26 = - V_162 ;
if ( V_20 -> V_290 )
V_26 = V_20 -> V_290 ( V_29 , V_289 -> V_153 ,
V_289 -> V_239 ) ;
break;
}
default:
V_26 = - V_275 ;
break;
}
if ( V_26 )
break;
}
return V_26 ;
}
static int F_124 ( struct V_28 * V_29 , int V_177 )
{
struct V_28 * V_171 = F_92 ( V_29 ) ;
const struct V_280 * V_20 ;
int V_26 ;
if ( V_171 ) {
if ( V_171 -> V_177 == V_177 )
return 0 ;
V_20 = V_171 -> V_144 ;
if ( V_20 -> V_291 ) {
V_26 = V_20 -> V_291 ( V_171 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_162 ;
}
}
if ( V_177 ) {
V_171 = F_125 ( F_126 ( V_29 ) , V_177 ) ;
if ( ! V_171 )
return - V_275 ;
V_20 = V_171 -> V_144 ;
if ( V_20 -> V_292 ) {
V_26 = V_20 -> V_292 ( V_171 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_162 ;
}
}
return 0 ;
}
static int F_127 ( struct V_28 * V_29 , struct V_97 * V_98 ,
struct V_32 * * V_259 , char * V_293 , int V_294 )
{
const struct V_280 * V_20 = V_29 -> V_144 ;
int V_26 ;
if ( V_259 [ V_273 ] || V_259 [ V_274 ] ) {
struct V_27 * V_27 = F_115 ( F_126 ( V_29 ) , V_259 ) ;
if ( F_128 ( V_27 ) ) {
V_26 = F_129 ( V_27 ) ;
goto V_295;
}
if ( ! F_130 ( V_27 -> V_296 , V_297 ) ) {
V_26 = - V_298 ;
goto V_295;
}
V_26 = F_131 ( V_29 , V_27 , V_293 ) ;
F_132 ( V_27 ) ;
if ( V_26 )
goto V_295;
V_294 = 1 ;
}
if ( V_259 [ V_211 ] ) {
struct V_148 * V_299 ;
struct V_300 V_301 ;
if ( ! V_20 -> V_302 ) {
V_26 = - V_162 ;
goto V_295;
}
if ( ! F_133 ( V_29 ) ) {
V_26 = - V_303 ;
goto V_295;
}
V_299 = F_103 ( V_259 [ V_211 ] ) ;
V_301 . V_204 = ( unsigned long ) V_299 -> V_204 ;
V_301 . V_205 = ( unsigned long ) V_299 -> V_205 ;
V_301 . V_206 = ( unsigned short ) V_299 -> V_206 ;
V_301 . V_207 = ( unsigned char ) V_299 -> V_207 ;
V_301 . V_208 = ( unsigned char ) V_299 -> V_208 ;
V_301 . V_209 = ( unsigned char ) V_299 -> V_209 ;
V_26 = V_20 -> V_302 ( V_29 , & V_301 ) ;
if ( V_26 < 0 )
goto V_295;
V_294 = 1 ;
}
if ( V_259 [ V_213 ] ) {
struct V_304 * V_305 ;
int V_271 ;
V_271 = sizeof( V_306 ) + V_29 -> V_212 ;
V_305 = F_134 ( V_271 , V_15 ) ;
if ( ! V_305 ) {
V_26 = - V_307 ;
goto V_295;
}
V_305 -> V_308 = V_29 -> type ;
memcpy ( V_305 -> V_309 , F_103 ( V_259 [ V_213 ] ) ,
V_29 -> V_212 ) ;
V_26 = F_135 ( V_29 , V_305 ) ;
F_24 ( V_305 ) ;
if ( V_26 )
goto V_295;
V_294 = 1 ;
}
if ( V_259 [ V_186 ] ) {
V_26 = F_136 ( V_29 , F_110 ( V_259 [ V_186 ] ) ) ;
if ( V_26 < 0 )
goto V_295;
V_294 = 1 ;
}
if ( V_259 [ V_188 ] ) {
F_137 ( V_29 , F_110 ( V_259 [ V_188 ] ) ) ;
V_294 = 1 ;
}
if ( V_98 -> V_176 > 0 && V_293 [ 0 ] ) {
V_26 = F_138 ( V_29 , V_293 ) ;
if ( V_26 < 0 )
goto V_295;
V_294 = 1 ;
}
if ( V_259 [ V_202 ] ) {
V_26 = F_139 ( V_29 , F_103 ( V_259 [ V_202 ] ) ,
F_120 ( V_259 [ V_202 ] ) ) ;
if ( V_26 < 0 )
goto V_295;
V_294 = 1 ;
}
if ( V_259 [ V_215 ] ) {
F_140 ( V_29 -> V_216 , V_259 [ V_215 ] , V_29 -> V_212 ) ;
F_141 ( V_310 , V_29 ) ;
}
if ( V_98 -> V_99 || V_98 -> V_100 ) {
V_26 = F_142 ( V_29 , F_77 ( V_29 , V_98 ) ) ;
if ( V_26 < 0 )
goto V_295;
}
if ( V_259 [ V_197 ] ) {
V_26 = F_124 ( V_29 , F_110 ( V_259 [ V_197 ] ) ) ;
if ( V_26 )
goto V_295;
V_294 = 1 ;
}
if ( V_259 [ V_198 ] ) {
V_26 = F_143 ( V_29 , F_144 ( V_259 [ V_198 ] ) ) ;
if ( V_26 )
goto V_295;
V_294 = 1 ;
}
if ( V_259 [ V_180 ] )
V_29 -> V_181 = F_110 ( V_259 [ V_180 ] ) ;
if ( V_259 [ V_182 ] )
F_71 ( V_29 , F_144 ( V_259 [ V_182 ] ) ) ;
if ( V_259 [ V_184 ] ) {
F_73 ( & V_93 ) ;
V_29 -> V_185 = F_144 ( V_259 [ V_184 ] ) ;
F_74 ( & V_93 ) ;
}
if ( V_259 [ V_222 ] ) {
struct V_32 * V_169 ;
int V_276 ;
F_121 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_122 ( V_169 ) != V_240 ) {
V_26 = - V_275 ;
goto V_295;
}
V_26 = F_123 ( V_29 , V_169 ) ;
if ( V_26 < 0 )
goto V_295;
V_294 = 1 ;
}
}
V_26 = 0 ;
if ( V_259 [ V_154 ] ) {
struct V_32 * V_209 [ V_311 + 1 ] ;
struct V_32 * V_169 ;
int V_153 ;
int V_276 ;
V_26 = - V_162 ;
if ( ! V_20 -> V_312 )
goto V_295;
F_121 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_122 ( V_169 ) != V_155 )
continue;
V_26 = F_145 ( V_209 , V_311 ,
V_169 , V_313 ) ;
if ( V_26 < 0 )
goto V_295;
if ( ! V_209 [ V_156 ] ) {
V_26 = - V_162 ;
goto V_295;
}
V_153 = F_110 ( V_209 [ V_156 ] ) ;
V_26 = V_20 -> V_312 ( V_29 , V_153 , V_209 ) ;
if ( V_26 < 0 )
goto V_295;
V_294 = 1 ;
}
}
V_26 = 0 ;
if ( V_259 [ V_158 ] ) {
struct V_32 * V_209 [ V_311 + 1 ] ;
V_26 = F_145 ( V_209 , V_311 ,
V_259 [ V_158 ] , V_313 ) ;
if ( V_26 < 0 )
goto V_295;
V_26 = - V_162 ;
if ( V_20 -> V_312 )
V_26 = V_20 -> V_312 ( V_29 , V_159 , V_209 ) ;
if ( V_26 < 0 )
goto V_295;
V_294 = 1 ;
}
if ( V_259 [ V_246 ] ) {
struct V_32 * V_248 ;
int V_276 ;
F_121 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_35 * V_37 ;
if ( ! ( V_37 = F_40 ( F_122 ( V_248 ) ) ) )
F_146 () ;
V_26 = V_37 -> V_278 ( V_29 , V_248 ) ;
if ( V_26 < 0 )
goto V_295;
V_294 = 1 ;
}
}
V_26 = 0 ;
V_295:
if ( V_26 < 0 && V_294 )
F_147 ( L_3 ,
V_29 -> V_179 ) ;
return V_26 ;
}
static int F_148 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
struct V_97 * V_98 ;
struct V_28 * V_29 ;
int V_26 ;
struct V_32 * V_259 [ V_260 + 1 ] ;
char V_293 [ V_146 ] ;
V_26 = F_109 ( V_61 , sizeof( * V_98 ) , V_259 , V_260 , V_262 ) ;
if ( V_26 < 0 )
goto V_295;
if ( V_259 [ V_178 ] )
F_149 ( V_293 , V_259 [ V_178 ] , V_146 ) ;
else
V_293 [ 0 ] = '\0' ;
V_26 = - V_275 ;
V_98 = F_95 ( V_61 ) ;
if ( V_98 -> V_176 > 0 )
V_29 = F_125 ( V_27 , V_98 -> V_176 ) ;
else if ( V_259 [ V_178 ] )
V_29 = F_150 ( V_27 , V_293 ) ;
else
goto V_295;
if ( V_29 == NULL ) {
V_26 = - V_303 ;
goto V_295;
}
V_26 = F_119 ( V_29 , V_259 ) ;
if ( V_26 < 0 )
goto V_295;
V_26 = F_127 ( V_29 , V_98 , V_259 , V_293 , 0 ) ;
V_295:
return V_26 ;
}
static int F_151 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
const struct V_18 * V_20 ;
struct V_28 * V_29 ;
struct V_97 * V_98 ;
char V_293 [ V_146 ] ;
struct V_32 * V_259 [ V_260 + 1 ] ;
int V_26 ;
F_31 ( V_30 ) ;
V_26 = F_109 ( V_61 , sizeof( * V_98 ) , V_259 , V_260 , V_262 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_259 [ V_178 ] )
F_149 ( V_293 , V_259 [ V_178 ] , V_146 ) ;
V_98 = F_95 ( V_61 ) ;
if ( V_98 -> V_176 > 0 )
V_29 = F_125 ( V_27 , V_98 -> V_176 ) ;
else if ( V_259 [ V_178 ] )
V_29 = F_150 ( V_27 , V_293 ) ;
else
return - V_275 ;
if ( ! V_29 )
return - V_303 ;
V_20 = V_29 -> V_18 ;
if ( ! V_20 )
return - V_162 ;
V_20 -> V_22 ( V_29 , & V_30 ) ;
F_33 ( & V_30 ) ;
F_36 ( & V_30 ) ;
return 0 ;
}
int F_152 ( struct V_28 * V_29 , const struct V_97 * V_98 )
{
unsigned int V_314 ;
int V_26 ;
V_314 = V_29 -> V_62 ;
if ( V_98 && ( V_98 -> V_99 || V_98 -> V_100 ) ) {
V_26 = F_153 ( V_29 , F_77 ( V_29 , V_98 ) ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_29 -> V_315 = V_316 ;
F_154 ( V_267 , V_29 , ~ 0U ) ;
F_155 ( V_29 , V_314 ) ;
return 0 ;
}
struct V_28 * F_156 ( struct V_27 * V_27 ,
char * V_293 , const struct V_18 * V_20 , struct V_32 * V_259 [] )
{
int V_26 ;
struct V_28 * V_29 ;
unsigned int V_192 = 1 ;
unsigned int V_194 = 1 ;
if ( V_259 [ V_191 ] )
V_192 = F_110 ( V_259 [ V_191 ] ) ;
else if ( V_20 -> V_317 )
V_192 = V_20 -> V_317 () ;
if ( V_259 [ V_193 ] )
V_194 = F_110 ( V_259 [ V_193 ] ) ;
else if ( V_20 -> V_318 )
V_194 = V_20 -> V_318 () ;
V_26 = - V_307 ;
V_29 = F_157 ( V_20 -> V_319 , V_293 , V_20 -> V_320 ,
V_192 , V_194 ) ;
if ( ! V_29 )
goto V_26;
F_158 ( V_29 , V_27 ) ;
V_29 -> V_18 = V_20 ;
V_29 -> V_315 = V_321 ;
if ( V_259 [ V_186 ] )
V_29 -> V_187 = F_110 ( V_259 [ V_186 ] ) ;
if ( V_259 [ V_213 ] ) {
memcpy ( V_29 -> V_214 , F_103 ( V_259 [ V_213 ] ) ,
F_120 ( V_259 [ V_213 ] ) ) ;
V_29 -> V_322 = V_323 ;
}
if ( V_259 [ V_215 ] )
memcpy ( V_29 -> V_216 , F_103 ( V_259 [ V_215 ] ) ,
F_120 ( V_259 [ V_215 ] ) ) ;
if ( V_259 [ V_180 ] )
V_29 -> V_181 = F_110 ( V_259 [ V_180 ] ) ;
if ( V_259 [ V_182 ] )
F_71 ( V_29 , F_144 ( V_259 [ V_182 ] ) ) ;
if ( V_259 [ V_184 ] )
V_29 -> V_185 = F_144 ( V_259 [ V_184 ] ) ;
if ( V_259 [ V_188 ] )
F_137 ( V_29 , F_110 ( V_259 [ V_188 ] ) ) ;
return V_29 ;
V_26:
return F_159 ( V_26 ) ;
}
static int F_160 ( struct V_27 * V_27 , int V_53 ,
struct V_97 * V_98 ,
struct V_32 * * V_259 )
{
struct V_28 * V_29 ;
int V_26 ;
F_32 (net, dev) {
if ( V_29 -> V_53 == V_53 ) {
V_26 = F_127 ( V_29 , V_98 , V_259 , NULL , 0 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
return 0 ;
}
static int F_161 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
const struct V_18 * V_20 ;
struct V_28 * V_29 ;
struct V_97 * V_98 ;
char V_19 [ V_324 ] ;
char V_293 [ V_146 ] ;
struct V_32 * V_259 [ V_260 + 1 ] ;
struct V_32 * V_41 [ V_325 + 1 ] ;
int V_26 ;
#ifdef F_162
V_326:
#endif
V_26 = F_109 ( V_61 , sizeof( * V_98 ) , V_259 , V_260 , V_262 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_259 [ V_178 ] )
F_149 ( V_293 , V_259 [ V_178 ] , V_146 ) ;
else
V_293 [ 0 ] = '\0' ;
V_98 = F_95 ( V_61 ) ;
if ( V_98 -> V_176 > 0 )
V_29 = F_125 ( V_27 , V_98 -> V_176 ) ;
else {
if ( V_293 [ 0 ] )
V_29 = F_150 ( V_27 , V_293 ) ;
else
V_29 = NULL ;
}
V_26 = F_119 ( V_29 , V_259 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_259 [ V_44 ] ) {
V_26 = F_145 ( V_41 , V_325 ,
V_259 [ V_44 ] , V_327 ) ;
if ( V_26 < 0 )
return V_26 ;
} else
memset ( V_41 , 0 , sizeof( V_41 ) ) ;
if ( V_41 [ V_46 ] ) {
F_149 ( V_19 , V_41 [ V_46 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_32 * V_169 [ V_20 ? V_20 -> V_328 + 1 : 0 ] , * * V_42 = NULL ;
struct V_27 * V_329 ;
if ( V_20 ) {
if ( V_20 -> V_328 && V_41 [ V_50 ] ) {
V_26 = F_145 ( V_169 , V_20 -> V_328 ,
V_41 [ V_50 ] ,
V_20 -> V_330 ) ;
if ( V_26 < 0 )
return V_26 ;
V_42 = V_169 ;
}
if ( V_20 -> V_331 ) {
V_26 = V_20 -> V_331 ( V_259 , V_42 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
if ( V_29 ) {
int V_294 = 0 ;
if ( V_61 -> V_332 & V_333 )
return - V_21 ;
if ( V_61 -> V_332 & V_334 )
return - V_162 ;
if ( V_41 [ V_50 ] ) {
if ( ! V_20 || V_20 != V_29 -> V_18 ||
! V_20 -> V_335 )
return - V_162 ;
V_26 = V_20 -> V_335 ( V_29 , V_259 , V_42 ) ;
if ( V_26 < 0 )
return V_26 ;
V_294 = 1 ;
}
return F_127 ( V_29 , V_98 , V_259 , V_293 , V_294 ) ;
}
if ( ! ( V_61 -> V_332 & V_336 ) ) {
if ( V_98 -> V_176 == 0 && V_259 [ V_188 ] )
return F_160 ( V_27 ,
F_110 ( V_259 [ V_188 ] ) ,
V_98 , V_259 ) ;
return - V_303 ;
}
if ( V_259 [ V_211 ] || V_259 [ V_197 ] || V_259 [ V_337 ] )
return - V_162 ;
if ( ! V_20 ) {
#ifdef F_162
if ( V_19 [ 0 ] ) {
F_3 () ;
F_163 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_326;
}
#endif
return - V_162 ;
}
if ( ! V_293 [ 0 ] )
snprintf ( V_293 , V_146 , L_5 , V_20 -> V_19 ) ;
V_329 = F_115 ( V_27 , V_259 ) ;
if ( F_128 ( V_329 ) )
return F_129 ( V_329 ) ;
V_29 = F_156 ( V_329 , V_293 , V_20 , V_259 ) ;
if ( F_128 ( V_29 ) ) {
V_26 = F_129 ( V_29 ) ;
goto V_45;
}
V_29 -> V_177 = V_98 -> V_176 ;
if ( V_20 -> V_338 )
V_26 = V_20 -> V_338 ( V_27 , V_29 , V_259 , V_42 ) ;
else
V_26 = F_164 ( V_29 ) ;
if ( V_26 < 0 ) {
F_165 ( V_29 ) ;
goto V_45;
}
V_26 = F_152 ( V_29 , V_98 ) ;
if ( V_26 < 0 )
F_166 ( V_29 ) ;
V_45:
F_132 ( V_329 ) ;
return V_26 ;
}
}
static int F_167 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
struct V_97 * V_98 ;
char V_293 [ V_146 ] ;
struct V_32 * V_259 [ V_260 + 1 ] ;
struct V_28 * V_29 = NULL ;
struct V_39 * V_339 ;
int V_26 ;
T_5 V_129 = 0 ;
V_26 = F_109 ( V_61 , sizeof( * V_98 ) , V_259 , V_260 , V_262 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_259 [ V_178 ] )
F_149 ( V_293 , V_259 [ V_178 ] , V_146 ) ;
if ( V_259 [ V_263 ] )
V_129 = F_110 ( V_259 [ V_263 ] ) ;
V_98 = F_95 ( V_61 ) ;
if ( V_98 -> V_176 > 0 )
V_29 = F_125 ( V_27 , V_98 -> V_176 ) ;
else if ( V_259 [ V_178 ] )
V_29 = F_150 ( V_27 , V_293 ) ;
else
return - V_275 ;
if ( V_29 == NULL )
return - V_303 ;
V_339 = F_168 ( F_84 ( V_29 , V_129 ) , V_15 ) ;
if ( V_339 == NULL )
return - V_16 ;
V_26 = F_91 ( V_339 , V_29 , V_267 , F_52 ( V_40 ) . V_268 ,
V_61 -> V_269 , 0 , 0 , V_129 ) ;
if ( V_26 < 0 ) {
F_169 ( V_26 == - V_43 ) ;
F_170 ( V_339 ) ;
} else
V_26 = F_56 ( V_339 , V_27 , F_52 ( V_40 ) . V_268 ) ;
return V_26 ;
}
static T_8 F_171 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
struct V_28 * V_29 ;
struct V_32 * V_259 [ V_260 + 1 ] ;
T_5 V_129 = 0 ;
T_8 V_340 = 0 ;
if ( F_109 ( V_61 , sizeof( struct V_97 ) , V_259 , V_260 ,
V_262 ) >= 0 ) {
if ( V_259 [ V_263 ] )
V_129 = F_110 ( V_259 [ V_263 ] ) ;
}
if ( ! V_129 )
return V_341 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_340 = F_172 ( T_8 , V_340 ,
F_84 ( V_29 ,
V_129 ) ) ;
}
return V_340 ;
}
static int F_173 ( struct V_39 * V_40 , struct V_250 * V_251 )
{
int V_255 ;
int V_256 = V_251 -> V_36 ;
if ( V_256 == 0 )
V_256 = 1 ;
for ( V_255 = 1 ; V_255 <= V_9 ; V_255 ++ ) {
int type = V_251 -> V_61 -> V_342 - V_4 ;
if ( V_255 < V_256 || V_255 == V_343 )
continue;
if ( V_10 [ V_255 ] == NULL ||
V_10 [ V_255 ] [ type ] . V_13 == NULL )
continue;
if ( V_255 > V_256 ) {
memset ( & V_251 -> args [ 0 ] , 0 , sizeof( V_251 -> args ) ) ;
V_251 -> V_344 = 0 ;
V_251 -> V_165 = 0 ;
}
if ( V_10 [ V_255 ] [ type ] . V_13 ( V_40 , V_251 ) )
break;
}
V_251 -> V_36 = V_255 ;
return V_40 -> V_271 ;
}
void F_154 ( int type , struct V_28 * V_29 , unsigned int V_166 )
{
struct V_27 * V_27 = F_126 ( V_29 ) ;
struct V_39 * V_40 ;
int V_26 = - V_16 ;
T_4 V_345 ;
V_40 = F_168 ( ( V_345 = F_84 ( V_29 , 0 ) ) , V_15 ) ;
if ( V_40 == NULL )
goto V_295;
V_26 = F_91 ( V_40 , V_29 , type , 0 , 0 , V_166 , 0 , 0 ) ;
if ( V_26 < 0 ) {
F_169 ( V_26 == - V_43 ) ;
F_170 ( V_40 ) ;
goto V_295;
}
F_58 ( V_40 , V_27 , 0 , V_346 , NULL , V_15 ) ;
return;
V_295:
if ( V_26 < 0 )
F_61 ( V_27 , V_346 , V_26 ) ;
}
static int F_174 ( struct V_39 * V_40 ,
struct V_28 * V_29 ,
T_9 * V_347 , T_5 V_52 , T_5 V_165 ,
int type , unsigned int V_62 )
{
struct V_60 * V_61 ;
struct V_348 * V_349 ;
V_61 = F_94 ( V_40 , V_52 , V_165 , type , sizeof( * V_349 ) , V_270 ) ;
if ( ! V_61 )
return - V_43 ;
V_349 = F_95 ( V_61 ) ;
V_349 -> V_350 = V_351 ;
V_349 -> V_352 = 0 ;
V_349 -> V_353 = 0 ;
V_349 -> V_354 = V_62 ;
V_349 -> V_355 = 0 ;
V_349 -> V_356 = V_29 -> V_177 ;
V_349 -> V_357 = V_358 ;
if ( F_70 ( V_40 , V_359 , V_360 , V_347 ) )
goto V_70;
return F_104 ( V_40 , V_61 ) ;
V_70:
F_105 ( V_40 , V_61 ) ;
return - V_43 ;
}
static inline T_4 F_175 ( void )
{
return F_85 ( sizeof( struct V_348 ) ) + F_39 ( V_360 ) ;
}
static void F_176 ( struct V_28 * V_29 , T_9 * V_347 , int type )
{
struct V_27 * V_27 = F_126 ( V_29 ) ;
struct V_39 * V_40 ;
int V_26 = - V_16 ;
V_40 = F_168 ( F_175 () , V_361 ) ;
if ( ! V_40 )
goto V_295;
V_26 = F_174 ( V_40 , V_29 , V_347 , 0 , 0 , type , V_362 ) ;
if ( V_26 < 0 ) {
F_170 ( V_40 ) ;
goto V_295;
}
F_58 ( V_40 , V_27 , 0 , V_363 , NULL , V_361 ) ;
return;
V_295:
F_61 ( V_27 , V_363 , V_26 ) ;
}
int F_177 ( struct V_348 * V_349 ,
struct V_32 * V_259 [] ,
struct V_28 * V_29 ,
const unsigned char * V_347 ,
T_8 V_62 )
{
int V_26 = - V_275 ;
if ( V_349 -> V_357 && ! ( V_349 -> V_357 & V_358 ) ) {
F_178 ( L_6 , V_29 -> V_179 ) ;
return V_26 ;
}
if ( F_179 ( V_347 ) || F_180 ( V_347 ) )
V_26 = F_181 ( V_29 , V_347 ) ;
else if ( F_182 ( V_347 ) )
V_26 = F_183 ( V_29 , V_347 ) ;
if ( V_26 == - V_21 && ! ( V_62 & V_333 ) )
V_26 = 0 ;
return V_26 ;
}
static int F_184 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
struct V_348 * V_349 ;
struct V_32 * V_259 [ V_364 + 1 ] ;
struct V_28 * V_29 ;
T_9 * V_347 ;
int V_26 ;
V_26 = F_109 ( V_61 , sizeof( * V_349 ) , V_259 , V_364 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_349 = F_95 ( V_61 ) ;
if ( V_349 -> V_356 == 0 ) {
F_178 ( L_7 ) ;
return - V_275 ;
}
V_29 = F_125 ( V_27 , V_349 -> V_356 ) ;
if ( V_29 == NULL ) {
F_178 ( L_8 ) ;
return - V_303 ;
}
if ( ! V_259 [ V_359 ] || F_120 ( V_259 [ V_359 ] ) != V_360 ) {
F_178 ( L_9 ) ;
return - V_275 ;
}
V_347 = F_103 ( V_259 [ V_359 ] ) ;
V_26 = - V_162 ;
if ( ( ! V_349 -> V_354 || V_349 -> V_354 & V_365 ) &&
( V_29 -> V_366 & V_367 ) ) {
struct V_28 * V_368 = F_92 ( V_29 ) ;
const struct V_280 * V_20 = V_368 -> V_144 ;
V_26 = V_20 -> V_369 ( V_349 , V_259 , V_29 , V_347 , V_61 -> V_332 ) ;
if ( V_26 )
goto V_45;
else
V_349 -> V_354 &= ~ V_365 ;
}
if ( ( V_349 -> V_354 & V_362 ) ) {
if ( V_29 -> V_144 -> V_369 )
V_26 = V_29 -> V_144 -> V_369 ( V_349 , V_259 , V_29 , V_347 ,
V_61 -> V_332 ) ;
else
V_26 = F_177 ( V_349 , V_259 , V_29 , V_347 ,
V_61 -> V_332 ) ;
if ( ! V_26 ) {
F_176 ( V_29 , V_347 , V_370 ) ;
V_349 -> V_354 &= ~ V_362 ;
}
}
V_45:
return V_26 ;
}
int F_185 ( struct V_348 * V_349 ,
struct V_32 * V_259 [] ,
struct V_28 * V_29 ,
const unsigned char * V_347 )
{
int V_26 = - V_162 ;
if ( ! ( V_349 -> V_357 & V_358 ) ) {
F_178 ( L_6 , V_29 -> V_179 ) ;
return - V_275 ;
}
if ( F_179 ( V_347 ) || F_180 ( V_347 ) )
V_26 = F_186 ( V_29 , V_347 ) ;
else if ( F_182 ( V_347 ) )
V_26 = F_187 ( V_29 , V_347 ) ;
else
V_26 = - V_275 ;
return V_26 ;
}
static int F_188 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
struct V_348 * V_349 ;
struct V_32 * V_259 [ V_364 + 1 ] ;
struct V_28 * V_29 ;
int V_26 = - V_275 ;
T_10 * V_347 ;
if ( ! F_189 ( V_297 ) )
return - V_298 ;
V_26 = F_109 ( V_61 , sizeof( * V_349 ) , V_259 , V_364 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_349 = F_95 ( V_61 ) ;
if ( V_349 -> V_356 == 0 ) {
F_178 ( L_10 ) ;
return - V_275 ;
}
V_29 = F_125 ( V_27 , V_349 -> V_356 ) ;
if ( V_29 == NULL ) {
F_178 ( L_11 ) ;
return - V_303 ;
}
if ( ! V_259 [ V_359 ] || F_120 ( V_259 [ V_359 ] ) != V_360 ) {
F_178 ( L_12 ) ;
return - V_275 ;
}
V_347 = F_103 ( V_259 [ V_359 ] ) ;
V_26 = - V_162 ;
if ( ( ! V_349 -> V_354 || V_349 -> V_354 & V_365 ) &&
( V_29 -> V_366 & V_367 ) ) {
struct V_28 * V_368 = F_92 ( V_29 ) ;
const struct V_280 * V_20 = V_368 -> V_144 ;
if ( V_20 -> V_371 )
V_26 = V_20 -> V_371 ( V_349 , V_259 , V_29 , V_347 ) ;
if ( V_26 )
goto V_45;
else
V_349 -> V_354 &= ~ V_365 ;
}
if ( V_349 -> V_354 & V_362 ) {
if ( V_29 -> V_144 -> V_371 )
V_26 = V_29 -> V_144 -> V_371 ( V_349 , V_259 , V_29 , V_347 ) ;
else
V_26 = F_185 ( V_349 , V_259 , V_29 , V_347 ) ;
if ( ! V_26 ) {
F_176 ( V_29 , V_347 , V_372 ) ;
V_349 -> V_354 &= ~ V_362 ;
}
}
V_45:
return V_26 ;
}
static int F_190 ( struct V_39 * V_40 ,
struct V_250 * V_251 ,
struct V_28 * V_29 ,
int * V_255 ,
struct V_373 * V_24 )
{
struct V_374 * V_375 ;
int V_26 ;
T_5 V_268 , V_165 ;
V_268 = F_52 ( V_251 -> V_40 ) . V_268 ;
V_165 = V_251 -> V_61 -> V_269 ;
F_26 (ha, &list->list, list) {
if ( * V_255 < V_251 -> args [ 0 ] )
goto V_376;
V_26 = F_174 ( V_40 , V_29 , V_375 -> V_347 ,
V_268 , V_165 ,
V_370 , V_362 ) ;
if ( V_26 < 0 )
return V_26 ;
V_376:
* V_255 += 1 ;
}
return 0 ;
}
int F_191 ( struct V_39 * V_40 ,
struct V_250 * V_251 ,
struct V_28 * V_29 ,
int V_255 )
{
int V_26 ;
F_192 ( V_29 ) ;
V_26 = F_190 ( V_40 , V_251 , V_29 , & V_255 , & V_29 -> V_377 ) ;
if ( V_26 )
goto V_45;
F_190 ( V_40 , V_251 , V_29 , & V_255 , & V_29 -> V_378 ) ;
V_45:
F_193 ( V_29 ) ;
return V_255 ;
}
static int F_194 ( struct V_39 * V_40 , struct V_250 * V_251 )
{
int V_255 = 0 ;
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
struct V_28 * V_29 ;
F_108 () ;
F_195 (net, dev) {
if ( V_29 -> V_366 & V_367 ) {
struct V_28 * V_368 ;
const struct V_280 * V_20 ;
V_368 = F_92 ( V_29 ) ;
V_20 = V_368 -> V_144 ;
if ( V_20 -> V_379 )
V_255 = V_20 -> V_379 ( V_40 , V_251 , V_29 , V_255 ) ;
}
if ( V_29 -> V_144 -> V_379 )
V_255 = V_29 -> V_144 -> V_379 ( V_40 , V_251 , V_29 , V_255 ) ;
else
V_255 = F_191 ( V_40 , V_251 , V_29 , V_255 ) ;
}
F_114 () ;
V_251 -> args [ 0 ] = V_255 ;
return V_40 -> V_271 ;
}
int F_196 ( struct V_39 * V_40 , T_5 V_52 , T_5 V_165 ,
struct V_28 * V_29 , T_8 V_380 )
{
struct V_60 * V_61 ;
struct V_97 * V_98 ;
struct V_32 * V_381 ;
T_9 V_89 = F_98 ( V_29 ) ? V_29 -> V_89 : V_183 ;
struct V_28 * V_368 = F_92 ( V_29 ) ;
V_61 = F_94 ( V_40 , V_52 , V_165 , V_267 , sizeof( * V_98 ) , V_270 ) ;
if ( V_61 == NULL )
return - V_43 ;
V_98 = F_95 ( V_61 ) ;
V_98 -> V_172 = V_351 ;
V_98 -> V_174 = 0 ;
V_98 -> V_175 = V_29 -> type ;
V_98 -> V_176 = V_29 -> V_177 ;
V_98 -> V_99 = F_96 ( V_29 ) ;
V_98 -> V_100 = 0 ;
if ( F_48 ( V_40 , V_178 , V_29 -> V_179 ) ||
F_64 ( V_40 , V_186 , V_29 -> V_187 ) ||
F_97 ( V_40 , V_182 , V_89 ) ||
( V_368 &&
F_64 ( V_40 , V_197 , V_368 -> V_177 ) ) ||
( V_29 -> V_212 &&
F_70 ( V_40 , V_213 , V_29 -> V_212 , V_29 -> V_214 ) ) ||
( V_29 -> V_177 != V_29 -> V_195 &&
F_64 ( V_40 , V_196 , V_29 -> V_195 ) ) )
goto V_70;
V_381 = F_47 ( V_40 , V_246 ) ;
if ( ! V_381 )
goto V_70;
if ( F_197 ( V_40 , V_382 , V_383 ) ||
F_197 ( V_40 , V_384 , V_380 ) ) {
F_50 ( V_40 , V_381 ) ;
goto V_70;
}
F_49 ( V_40 , V_381 ) ;
return F_104 ( V_40 , V_61 ) ;
V_70:
F_105 ( V_40 , V_61 ) ;
return - V_43 ;
}
static int F_198 ( struct V_39 * V_40 , struct V_250 * V_251 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
struct V_28 * V_29 ;
int V_255 = 0 ;
T_5 V_268 = F_52 ( V_251 -> V_40 ) . V_268 ;
T_5 V_165 = V_251 -> V_61 -> V_269 ;
struct V_32 * V_385 ;
T_5 V_386 = 0 ;
V_385 = F_199 ( V_251 -> V_61 , sizeof( struct V_97 ) ,
V_263 ) ;
if ( V_385 )
V_386 = F_110 ( V_385 ) ;
F_108 () ;
F_195 (net, dev) {
const struct V_280 * V_20 = V_29 -> V_144 ;
struct V_28 * V_368 = F_92 ( V_29 ) ;
if ( V_368 && V_368 -> V_144 -> V_387 ) {
if ( V_255 >= V_251 -> args [ 0 ] &&
V_368 -> V_144 -> V_387 (
V_40 , V_268 , V_165 , V_29 , V_386 ) < 0 )
break;
V_255 ++ ;
}
if ( V_20 -> V_387 ) {
if ( V_255 >= V_251 -> args [ 0 ] &&
V_20 -> V_387 ( V_40 , V_268 , V_165 , V_29 ,
V_386 ) < 0 )
break;
V_255 ++ ;
}
}
F_114 () ;
V_251 -> args [ 0 ] = V_255 ;
return V_40 -> V_271 ;
}
static inline T_4 F_200 ( void )
{
return F_85 ( sizeof( struct V_97 ) )
+ F_39 ( V_146 )
+ F_39 ( V_149 )
+ F_39 ( sizeof( T_5 ) )
+ F_39 ( sizeof( T_5 ) )
+ F_39 ( sizeof( T_5 ) )
+ F_39 ( sizeof( T_5 ) )
+ F_39 ( sizeof( T_9 ) )
+ F_39 ( sizeof( struct V_32 ) )
+ F_39 ( sizeof( T_8 ) )
+ F_39 ( sizeof( T_8 ) ) ;
}
static int F_201 ( struct V_28 * V_29 , T_8 V_62 )
{
struct V_27 * V_27 = F_126 ( V_29 ) ;
struct V_28 * V_368 = F_92 ( V_29 ) ;
struct V_39 * V_40 ;
int V_26 = - V_162 ;
V_40 = F_168 ( F_200 () , V_361 ) ;
if ( ! V_40 ) {
V_26 = - V_307 ;
goto V_295;
}
if ( ( ! V_62 || ( V_62 & V_388 ) ) &&
V_368 && V_368 -> V_144 -> V_387 ) {
V_26 = V_368 -> V_144 -> V_387 ( V_40 , 0 , 0 , V_29 , 0 ) ;
if ( V_26 < 0 )
goto V_295;
}
if ( ( V_62 & V_383 ) &&
V_29 -> V_144 -> V_387 ) {
V_26 = V_29 -> V_144 -> V_387 ( V_40 , 0 , 0 , V_29 , 0 ) ;
if ( V_26 < 0 )
goto V_295;
}
F_58 ( V_40 , V_27 , 0 , V_346 , NULL , V_361 ) ;
return 0 ;
V_295:
F_169 ( V_26 == - V_43 ) ;
F_170 ( V_40 ) ;
F_61 ( V_27 , V_346 , V_26 ) ;
return V_26 ;
}
static int F_202 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
struct V_97 * V_98 ;
struct V_28 * V_29 ;
struct V_32 * V_389 , * V_169 = NULL ;
int V_276 , V_26 = - V_162 ;
T_8 V_390 , V_62 = 0 ;
bool V_391 = false ;
if ( F_203 ( V_61 ) < sizeof( * V_98 ) )
return - V_275 ;
V_98 = F_95 ( V_61 ) ;
if ( V_98 -> V_172 != V_351 )
return - V_392 ;
V_29 = F_125 ( V_27 , V_98 -> V_176 ) ;
if ( ! V_29 ) {
F_178 ( L_13 ) ;
return - V_303 ;
}
V_389 = F_199 ( V_61 , sizeof( struct V_97 ) , V_246 ) ;
if ( V_389 ) {
F_121 (attr, br_spec, rem) {
if ( F_122 ( V_169 ) == V_382 ) {
V_391 = true ;
V_62 = F_204 ( V_169 ) ;
break;
}
}
}
V_390 = V_62 ;
if ( ! V_62 || ( V_62 & V_388 ) ) {
struct V_28 * V_368 = F_92 ( V_29 ) ;
if ( ! V_368 || ! V_368 -> V_144 -> V_393 ) {
V_26 = - V_162 ;
goto V_45;
}
V_26 = V_368 -> V_144 -> V_393 ( V_29 , V_61 ) ;
if ( V_26 )
goto V_45;
V_62 &= ~ V_388 ;
}
if ( ( V_62 & V_383 ) ) {
if ( ! V_29 -> V_144 -> V_393 )
V_26 = - V_162 ;
else
V_26 = V_29 -> V_144 -> V_393 ( V_29 , V_61 ) ;
if ( ! V_26 )
V_62 &= ~ V_383 ;
}
if ( V_391 )
memcpy ( F_103 ( V_169 ) , & V_62 , sizeof( V_62 ) ) ;
if ( ! V_26 )
V_26 = F_201 ( V_29 , V_390 ) ;
V_45:
return V_26 ;
}
static int F_205 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
struct V_97 * V_98 ;
struct V_28 * V_29 ;
struct V_32 * V_389 , * V_169 = NULL ;
int V_276 , V_26 = - V_162 ;
T_8 V_390 , V_62 = 0 ;
bool V_391 = false ;
if ( F_203 ( V_61 ) < sizeof( * V_98 ) )
return - V_275 ;
V_98 = F_95 ( V_61 ) ;
if ( V_98 -> V_172 != V_351 )
return - V_392 ;
V_29 = F_125 ( V_27 , V_98 -> V_176 ) ;
if ( ! V_29 ) {
F_178 ( L_13 ) ;
return - V_303 ;
}
V_389 = F_199 ( V_61 , sizeof( struct V_97 ) , V_246 ) ;
if ( V_389 ) {
F_121 (attr, br_spec, rem) {
if ( F_122 ( V_169 ) == V_382 ) {
V_391 = true ;
V_62 = F_204 ( V_169 ) ;
break;
}
}
}
V_390 = V_62 ;
if ( ! V_62 || ( V_62 & V_388 ) ) {
struct V_28 * V_368 = F_92 ( V_29 ) ;
if ( ! V_368 || ! V_368 -> V_144 -> V_394 ) {
V_26 = - V_162 ;
goto V_45;
}
V_26 = V_368 -> V_144 -> V_394 ( V_29 , V_61 ) ;
if ( V_26 )
goto V_45;
V_62 &= ~ V_388 ;
}
if ( ( V_62 & V_383 ) ) {
if ( ! V_29 -> V_144 -> V_394 )
V_26 = - V_162 ;
else
V_26 = V_29 -> V_144 -> V_394 ( V_29 , V_61 ) ;
if ( ! V_26 )
V_62 &= ~ V_383 ;
}
if ( V_391 )
memcpy ( F_103 ( V_169 ) , & V_62 , sizeof( V_62 ) ) ;
if ( ! V_26 )
V_26 = F_201 ( V_29 , V_390 ) ;
V_45:
return V_26 ;
}
static int F_206 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_107 ( V_40 -> V_252 ) ;
T_1 V_11 ;
int V_395 , V_19 ;
int V_36 ;
int type ;
int V_26 ;
type = V_61 -> V_342 ;
if ( type > V_396 )
return - V_162 ;
type -= V_4 ;
if ( F_203 ( V_61 ) < sizeof( struct V_397 ) )
return 0 ;
V_36 = ( (struct V_397 * ) F_95 ( V_61 ) ) -> V_398 ;
V_395 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_130 ( V_27 -> V_296 , V_297 ) )
return - V_298 ;
if ( V_19 == 2 && V_61 -> V_332 & V_399 ) {
struct V_55 * V_56 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_400 = 0 ;
V_13 = F_16 ( V_36 , type ) ;
if ( V_13 == NULL )
return - V_162 ;
V_14 = F_17 ( V_36 , type ) ;
if ( V_14 )
V_400 = V_14 ( V_40 , V_61 ) ;
F_3 () ;
V_56 = V_27 -> V_56 ;
{
struct V_401 V_402 = {
. V_403 = V_13 ,
. V_400 = V_400 ,
} ;
V_26 = F_207 ( V_56 , V_40 , V_61 , & V_402 ) ;
}
F_1 () ;
return V_26 ;
}
V_11 = F_15 ( V_36 , type ) ;
if ( V_11 == NULL )
return - V_162 ;
return V_11 ( V_40 , V_61 ) ;
}
static void F_208 ( struct V_39 * V_40 )
{
F_1 () ;
F_209 ( V_40 , & F_206 ) ;
F_5 () ;
}
static int F_210 ( struct V_404 * V_405 , unsigned long V_406 , void * V_407 )
{
struct V_28 * V_29 = F_211 ( V_407 ) ;
switch ( V_406 ) {
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
break;
default:
F_154 ( V_267 , V_29 , 0 ) ;
break;
}
return V_420 ;
}
static int T_11 F_212 ( struct V_27 * V_27 )
{
struct V_55 * V_252 ;
struct V_421 V_422 = {
. V_423 = V_424 ,
. V_425 = F_208 ,
. V_426 = & V_1 ,
. V_62 = V_427 ,
} ;
V_252 = F_213 ( V_27 , V_428 , & V_422 ) ;
if ( ! V_252 )
return - V_307 ;
V_27 -> V_56 = V_252 ;
return 0 ;
}
static void T_12 F_214 ( struct V_27 * V_27 )
{
F_215 ( V_27 -> V_56 ) ;
V_27 -> V_56 = NULL ;
}
void T_13 F_216 ( void )
{
if ( F_217 ( & V_429 ) )
F_21 ( L_14 ) ;
F_218 ( & V_430 ) ;
F_20 ( V_12 , V_431 , F_167 ,
F_106 , F_171 ) ;
F_20 ( V_12 , V_432 , F_148 , NULL , NULL ) ;
F_20 ( V_12 , V_267 , F_161 , NULL , NULL ) ;
F_20 ( V_12 , V_433 , F_151 , NULL , NULL ) ;
F_20 ( V_12 , V_434 , NULL , F_173 , NULL ) ;
F_20 ( V_12 , V_435 , NULL , F_173 , NULL ) ;
F_20 ( V_436 , V_370 , F_184 , NULL , NULL ) ;
F_20 ( V_436 , V_372 , F_188 , NULL , NULL ) ;
F_20 ( V_436 , V_437 , NULL , F_194 , NULL ) ;
F_20 ( V_436 , V_431 , NULL , F_198 , NULL ) ;
F_20 ( V_436 , V_433 , F_205 , NULL , NULL ) ;
F_20 ( V_436 , V_432 , F_202 , NULL , NULL ) ;
}
