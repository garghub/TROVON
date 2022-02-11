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
static T_3 F_17 ( int V_6 , int V_3 )
{
struct V_7 * V_8 ;
if ( V_6 <= V_9 )
V_8 = V_10 [ V_6 ] ;
else
V_8 = NULL ;
if ( V_8 == NULL || V_8 [ V_3 ] . V_14 == NULL )
V_8 = V_10 [ V_12 ] ;
return V_8 ? V_8 [ V_3 ] . V_14 : NULL ;
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
if ( V_42 == NULL )
goto V_47;
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
+ F_45 ( V_29 ) ;
}
static int F_86 ( struct V_39 * V_40 , struct V_28 * V_29 )
{
struct V_32 * V_150 ;
struct V_32 * V_151 ;
int V_152 ;
int V_26 ;
V_150 = F_47 ( V_40 , V_153 ) ;
if ( ! V_150 )
return - V_43 ;
for ( V_152 = 0 ; V_152 < F_82 ( V_29 -> V_29 . V_130 ) ; V_152 ++ ) {
V_151 = F_47 ( V_40 , V_154 ) ;
if ( ! V_151 )
goto V_70;
if ( F_64 ( V_40 , V_155 , V_152 ) )
goto V_70;
V_26 = V_29 -> V_144 -> V_145 ( V_29 , V_152 , V_40 ) ;
if ( V_26 == - V_43 )
goto V_70;
if ( V_26 ) {
F_50 ( V_40 , V_151 ) ;
continue;
}
F_49 ( V_40 , V_151 ) ;
}
F_49 ( V_40 , V_150 ) ;
return 0 ;
V_70:
F_50 ( V_40 , V_150 ) ;
return - V_43 ;
}
static int F_87 ( struct V_39 * V_40 , struct V_28 * V_29 )
{
struct V_32 * V_156 ;
int V_26 ;
V_156 = F_47 ( V_40 , V_157 ) ;
if ( ! V_156 )
return - V_43 ;
V_26 = V_29 -> V_144 -> V_145 ( V_29 , V_158 , V_40 ) ;
if ( V_26 ) {
F_50 ( V_40 , V_156 ) ;
return ( V_26 == - V_43 ) ? V_26 : 0 ;
}
F_49 ( V_40 , V_156 ) ;
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
static int F_89 ( struct V_39 * V_40 , struct V_28 * V_29 ,
int type , T_5 V_52 , T_5 V_159 , T_5 V_160 ,
unsigned int V_62 , T_5 V_129 )
{
struct V_97 * V_98 ;
struct V_60 * V_61 ;
struct V_103 V_161 ;
const struct V_103 * V_162 ;
struct V_32 * V_163 , * V_164 ;
struct V_35 * V_37 ;
F_90 () ;
V_61 = F_91 ( V_40 , V_52 , V_159 , type , sizeof( * V_98 ) , V_62 ) ;
if ( V_61 == NULL )
return - V_43 ;
V_98 = F_92 ( V_61 ) ;
V_98 -> V_165 = V_166 ;
V_98 -> V_167 = 0 ;
V_98 -> V_168 = V_29 -> type ;
V_98 -> V_169 = V_29 -> V_170 ;
V_98 -> V_99 = F_93 ( V_29 ) ;
V_98 -> V_100 = V_160 ;
if ( F_48 ( V_40 , V_171 , V_29 -> V_172 ) ||
F_64 ( V_40 , V_173 , V_29 -> V_174 ) ||
F_94 ( V_40 , V_175 ,
F_95 ( V_29 ) ? V_29 -> V_89 : V_176 ) ||
F_94 ( V_40 , V_177 , V_29 -> V_178 ) ||
F_64 ( V_40 , V_179 , V_29 -> V_180 ) ||
F_64 ( V_40 , V_181 , V_29 -> V_53 ) ||
F_64 ( V_40 , V_182 , V_29 -> V_183 ) ||
F_64 ( V_40 , V_184 , V_29 -> V_185 ) ||
#ifdef F_96
F_64 ( V_40 , V_186 , V_29 -> V_187 ) ||
#endif
( V_29 -> V_170 != V_29 -> V_188 &&
F_64 ( V_40 , V_189 , V_29 -> V_188 ) ) ||
( V_29 -> V_190 &&
F_64 ( V_40 , V_191 , V_29 -> V_190 -> V_170 ) ) ||
( V_29 -> V_192 &&
F_48 ( V_40 , V_193 , V_29 -> V_192 -> V_20 -> V_73 ) ) ||
( V_29 -> V_194 &&
F_48 ( V_40 , V_195 , V_29 -> V_194 ) ) )
goto V_70;
if ( 1 ) {
struct V_148 V_196 = {
. V_197 = V_29 -> V_197 ,
. V_198 = V_29 -> V_198 ,
. V_199 = V_29 -> V_199 ,
. V_200 = V_29 -> V_200 ,
. V_201 = V_29 -> V_201 ,
. V_202 = V_29 -> V_203 ,
} ;
if ( F_70 ( V_40 , V_204 , sizeof( V_196 ) , & V_196 ) )
goto V_70;
}
if ( V_29 -> V_205 ) {
if ( F_70 ( V_40 , V_206 , V_29 -> V_205 , V_29 -> V_207 ) ||
F_70 ( V_40 , V_208 , V_29 -> V_205 , V_29 -> V_209 ) )
goto V_70;
}
V_163 = F_97 ( V_40 , V_210 ,
sizeof( struct V_101 ) ) ;
if ( V_163 == NULL )
goto V_70;
V_162 = F_98 ( V_29 , & V_161 ) ;
F_78 ( F_99 ( V_163 ) , V_162 ) ;
V_163 = F_97 ( V_40 , V_211 ,
sizeof( struct V_103 ) ) ;
if ( V_163 == NULL )
goto V_70;
F_79 ( F_99 ( V_163 ) , V_162 ) ;
if ( V_29 -> V_29 . V_130 && ( V_129 & V_131 ) &&
F_64 ( V_40 , V_212 , F_82 ( V_29 -> V_29 . V_130 ) ) )
goto V_70;
if ( V_29 -> V_144 -> V_213 && V_29 -> V_29 . V_130
&& ( V_129 & V_131 ) ) {
int V_66 ;
struct V_32 * V_214 , * V_152 ;
int V_132 = F_82 ( V_29 -> V_29 . V_130 ) ;
V_214 = F_47 ( V_40 , V_215 ) ;
if ( ! V_214 )
goto V_70;
for ( V_66 = 0 ; V_66 < V_132 ; V_66 ++ ) {
struct V_216 V_217 ;
struct V_133 V_218 ;
struct V_134 V_219 ;
struct V_135 V_220 ;
struct V_136 V_221 ;
V_217 . V_222 = - 1 ;
if ( V_29 -> V_144 -> V_213 ( V_29 , V_66 , & V_217 ) )
break;
V_218 . V_152 =
V_219 . V_152 =
V_220 . V_152 =
V_221 . V_152 = V_217 . V_152 ;
memcpy ( V_218 . V_223 , V_217 . V_223 , sizeof( V_217 . V_223 ) ) ;
V_219 . V_224 = V_217 . V_224 ;
V_219 . V_225 = V_217 . V_225 ;
V_220 . V_226 = V_217 . V_227 ;
V_221 . V_228 = V_217 . V_222 ;
V_152 = F_47 ( V_40 , V_229 ) ;
if ( ! V_152 ) {
F_50 ( V_40 , V_214 ) ;
goto V_70;
}
if ( F_70 ( V_40 , V_230 , sizeof( V_218 ) , & V_218 ) ||
F_70 ( V_40 , V_231 , sizeof( V_219 ) , & V_219 ) ||
F_70 ( V_40 , V_232 , sizeof( V_220 ) ,
& V_220 ) ||
F_70 ( V_40 , V_233 , sizeof( V_221 ) ,
& V_221 ) )
goto V_70;
F_49 ( V_40 , V_152 ) ;
}
F_49 ( V_40 , V_214 ) ;
}
if ( F_88 ( V_40 , V_29 ) )
goto V_70;
if ( V_29 -> V_18 ) {
if ( F_46 ( V_40 , V_29 ) < 0 )
goto V_70;
}
if ( ! ( V_164 = F_47 ( V_40 , V_234 ) ) )
goto V_70;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_37 -> V_235 ) {
struct V_32 * V_236 ;
int V_26 ;
if ( ! ( V_236 = F_47 ( V_40 , V_37 -> V_36 ) ) )
goto V_70;
V_26 = V_37 -> V_235 ( V_40 , V_29 ) ;
if ( V_26 == - V_237 )
F_50 ( V_40 , V_236 ) ;
else if ( V_26 < 0 )
goto V_70;
F_49 ( V_40 , V_236 ) ;
}
}
F_49 ( V_40 , V_164 ) ;
return F_100 ( V_40 , V_61 ) ;
V_70:
F_101 ( V_40 , V_61 ) ;
return - V_43 ;
}
static int F_102 ( struct V_39 * V_40 , struct V_238 * V_239 )
{
struct V_27 * V_27 = F_103 ( V_40 -> V_240 ) ;
int V_241 , V_242 ;
int V_243 = 0 , V_244 ;
struct V_28 * V_29 ;
struct V_245 * V_246 ;
struct V_247 * V_248 ;
struct V_32 * V_249 [ V_250 + 1 ] ;
T_5 V_129 = 0 ;
V_242 = V_239 -> args [ 0 ] ;
V_244 = V_239 -> args [ 1 ] ;
F_104 () ;
V_239 -> V_159 = V_27 -> V_251 ;
if ( F_105 ( V_239 -> V_61 , sizeof( struct V_252 ) , V_249 , V_250 ,
V_253 ) >= 0 ) {
if ( V_249 [ V_254 ] )
V_129 = F_106 ( V_249 [ V_254 ] ) ;
}
for ( V_241 = V_242 ; V_241 < V_255 ; V_241 ++ , V_244 = 0 ) {
V_243 = 0 ;
V_246 = & V_27 -> V_256 [ V_241 ] ;
F_107 (dev, node, head, index_hlist) {
if ( V_243 < V_244 )
goto V_257;
if ( F_89 ( V_40 , V_29 , V_258 ,
F_52 ( V_239 -> V_40 ) . V_259 ,
V_239 -> V_61 -> V_260 , 0 ,
V_261 ,
V_129 ) <= 0 )
goto V_45;
F_108 ( V_239 , F_109 ( V_40 ) ) ;
V_257:
V_243 ++ ;
}
}
V_45:
F_110 () ;
V_239 -> args [ 1 ] = V_243 ;
V_239 -> args [ 0 ] = V_241 ;
return V_40 -> V_262 ;
}
struct V_27 * F_111 ( struct V_27 * V_263 , struct V_32 * V_249 [] )
{
struct V_27 * V_27 ;
if ( V_249 [ V_264 ] )
V_27 = F_112 ( F_106 ( V_249 [ V_264 ] ) ) ;
else if ( V_249 [ V_265 ] )
V_27 = F_113 ( F_106 ( V_249 [ V_265 ] ) ) ;
else
V_27 = F_114 ( V_263 ) ;
return V_27 ;
}
static int F_115 ( struct V_28 * V_29 , struct V_32 * V_249 [] )
{
if ( V_29 ) {
if ( V_249 [ V_206 ] &&
F_116 ( V_249 [ V_206 ] ) < V_29 -> V_205 )
return - V_266 ;
if ( V_249 [ V_208 ] &&
F_116 ( V_249 [ V_208 ] ) < V_29 -> V_205 )
return - V_266 ;
}
if ( V_249 [ V_234 ] ) {
struct V_32 * V_236 ;
int V_267 , V_26 ;
F_117 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_35 * V_37 ;
if ( ! ( V_37 = F_40 ( F_118 ( V_236 ) ) ) )
return - V_268 ;
if ( ! V_37 -> V_269 )
return - V_270 ;
if ( V_37 -> V_271 ) {
V_26 = V_37 -> V_271 ( V_29 , V_236 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
}
return 0 ;
}
static int F_119 ( struct V_28 * V_29 , struct V_32 * V_163 )
{
int V_267 , V_26 = - V_266 ;
struct V_32 * V_152 ;
const struct V_272 * V_20 = V_29 -> V_144 ;
F_117 (vf, attr, rem) {
switch ( F_118 ( V_152 ) ) {
case V_230 : {
struct V_133 * V_273 ;
V_273 = F_99 ( V_152 ) ;
V_26 = - V_270 ;
if ( V_20 -> V_274 )
V_26 = V_20 -> V_274 ( V_29 , V_273 -> V_152 ,
V_273 -> V_223 ) ;
break;
}
case V_231 : {
struct V_134 * V_275 ;
V_275 = F_99 ( V_152 ) ;
V_26 = - V_270 ;
if ( V_20 -> V_276 )
V_26 = V_20 -> V_276 ( V_29 , V_275 -> V_152 ,
V_275 -> V_224 ,
V_275 -> V_225 ) ;
break;
}
case V_232 : {
struct V_135 * V_277 ;
V_277 = F_99 ( V_152 ) ;
V_26 = - V_270 ;
if ( V_20 -> V_278 )
V_26 = V_20 -> V_278 ( V_29 , V_277 -> V_152 ,
V_277 -> V_226 ) ;
break;
}
case V_233 : {
struct V_136 * V_279 ;
V_279 = F_99 ( V_152 ) ;
V_26 = - V_270 ;
if ( V_20 -> V_280 )
V_26 = V_20 -> V_280 ( V_29 , V_279 -> V_152 ,
V_279 -> V_228 ) ;
break;
}
default:
V_26 = - V_266 ;
break;
}
if ( V_26 )
break;
}
return V_26 ;
}
static int F_120 ( struct V_28 * V_29 , int V_170 )
{
struct V_28 * V_281 ;
const struct V_272 * V_20 ;
int V_26 ;
if ( V_29 -> V_190 ) {
if ( V_29 -> V_190 -> V_170 == V_170 )
return 0 ;
V_20 = V_29 -> V_190 -> V_144 ;
if ( V_20 -> V_282 ) {
V_26 = V_20 -> V_282 ( V_29 -> V_190 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_270 ;
}
}
if ( V_170 ) {
V_281 = F_121 ( F_122 ( V_29 ) , V_170 ) ;
if ( ! V_281 )
return - V_266 ;
V_20 = V_281 -> V_144 ;
if ( V_20 -> V_283 ) {
V_26 = V_20 -> V_283 ( V_281 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_270 ;
}
}
return 0 ;
}
static int F_123 ( struct V_28 * V_29 , struct V_97 * V_98 ,
struct V_32 * * V_249 , char * V_284 , int V_285 )
{
const struct V_272 * V_20 = V_29 -> V_144 ;
int V_286 = 0 ;
int V_26 ;
if ( V_249 [ V_264 ] || V_249 [ V_265 ] ) {
struct V_27 * V_27 = F_111 ( F_122 ( V_29 ) , V_249 ) ;
if ( F_124 ( V_27 ) ) {
V_26 = F_125 ( V_27 ) ;
goto V_287;
}
V_26 = F_126 ( V_29 , V_27 , V_284 ) ;
F_127 ( V_27 ) ;
if ( V_26 )
goto V_287;
V_285 = 1 ;
}
if ( V_249 [ V_204 ] ) {
struct V_148 * V_288 ;
struct V_289 V_290 ;
if ( ! V_20 -> V_291 ) {
V_26 = - V_270 ;
goto V_287;
}
if ( ! F_128 ( V_29 ) ) {
V_26 = - V_292 ;
goto V_287;
}
V_288 = F_99 ( V_249 [ V_204 ] ) ;
V_290 . V_197 = ( unsigned long ) V_288 -> V_197 ;
V_290 . V_198 = ( unsigned long ) V_288 -> V_198 ;
V_290 . V_199 = ( unsigned short ) V_288 -> V_199 ;
V_290 . V_200 = ( unsigned char ) V_288 -> V_200 ;
V_290 . V_201 = ( unsigned char ) V_288 -> V_201 ;
V_290 . V_202 = ( unsigned char ) V_288 -> V_202 ;
V_26 = V_20 -> V_291 ( V_29 , & V_290 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
if ( V_249 [ V_206 ] ) {
struct V_293 * V_294 ;
int V_262 ;
if ( ! V_20 -> V_295 ) {
V_26 = - V_270 ;
goto V_287;
}
if ( ! F_128 ( V_29 ) ) {
V_26 = - V_292 ;
goto V_287;
}
V_262 = sizeof( V_296 ) + V_29 -> V_205 ;
V_294 = F_129 ( V_262 , V_15 ) ;
if ( ! V_294 ) {
V_26 = - V_297 ;
goto V_287;
}
V_294 -> V_298 = V_29 -> type ;
memcpy ( V_294 -> V_299 , F_99 ( V_249 [ V_206 ] ) ,
V_29 -> V_205 ) ;
V_26 = V_20 -> V_295 ( V_29 , V_294 ) ;
F_24 ( V_294 ) ;
if ( V_26 )
goto V_287;
V_286 = 1 ;
V_285 = 1 ;
F_130 ( V_29 -> V_207 , V_29 -> V_205 ) ;
}
if ( V_249 [ V_179 ] ) {
V_26 = F_131 ( V_29 , F_106 ( V_249 [ V_179 ] ) ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
if ( V_249 [ V_181 ] ) {
F_132 ( V_29 , F_106 ( V_249 [ V_181 ] ) ) ;
V_285 = 1 ;
}
if ( V_98 -> V_169 > 0 && V_284 [ 0 ] ) {
V_26 = F_133 ( V_29 , V_284 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
if ( V_249 [ V_195 ] ) {
V_26 = F_134 ( V_29 , F_99 ( V_249 [ V_195 ] ) ,
F_116 ( V_249 [ V_195 ] ) ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
if ( V_249 [ V_208 ] ) {
F_135 ( V_29 -> V_209 , V_249 [ V_208 ] , V_29 -> V_205 ) ;
V_286 = 1 ;
}
if ( V_98 -> V_99 || V_98 -> V_100 ) {
V_26 = F_136 ( V_29 , F_77 ( V_29 , V_98 ) ) ;
if ( V_26 < 0 )
goto V_287;
}
if ( V_249 [ V_191 ] ) {
V_26 = F_120 ( V_29 , F_106 ( V_249 [ V_191 ] ) ) ;
if ( V_26 )
goto V_287;
V_285 = 1 ;
}
if ( V_249 [ V_173 ] )
V_29 -> V_174 = F_106 ( V_249 [ V_173 ] ) ;
if ( V_249 [ V_175 ] )
F_71 ( V_29 , F_137 ( V_249 [ V_175 ] ) ) ;
if ( V_249 [ V_177 ] ) {
F_73 ( & V_93 ) ;
V_29 -> V_178 = F_137 ( V_249 [ V_177 ] ) ;
F_74 ( & V_93 ) ;
}
if ( V_249 [ V_215 ] ) {
struct V_32 * V_163 ;
int V_267 ;
F_117 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_118 ( V_163 ) != V_229 ) {
V_26 = - V_266 ;
goto V_287;
}
V_26 = F_119 ( V_29 , V_163 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
}
V_26 = 0 ;
if ( V_249 [ V_153 ] ) {
struct V_32 * V_202 [ V_300 + 1 ] ;
struct V_32 * V_163 ;
int V_152 ;
int V_267 ;
V_26 = - V_270 ;
if ( ! V_20 -> V_301 )
goto V_287;
F_117 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_118 ( V_163 ) != V_154 )
continue;
V_26 = F_138 ( V_202 , V_300 ,
V_163 , V_302 ) ;
if ( V_26 < 0 )
goto V_287;
if ( ! V_202 [ V_155 ] ) {
V_26 = - V_270 ;
goto V_287;
}
V_152 = F_106 ( V_202 [ V_155 ] ) ;
V_26 = V_20 -> V_301 ( V_29 , V_152 , V_202 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
}
V_26 = 0 ;
if ( V_249 [ V_157 ] ) {
struct V_32 * V_202 [ V_300 + 1 ] ;
V_26 = F_138 ( V_202 , V_300 ,
V_249 [ V_157 ] , V_302 ) ;
if ( V_26 < 0 )
goto V_287;
V_26 = - V_270 ;
if ( V_20 -> V_301 )
V_26 = V_20 -> V_301 ( V_29 , V_158 , V_202 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
if ( V_249 [ V_234 ] ) {
struct V_32 * V_236 ;
int V_267 ;
F_117 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_35 * V_37 ;
if ( ! ( V_37 = F_40 ( F_118 ( V_236 ) ) ) )
F_139 () ;
V_26 = V_37 -> V_269 ( V_29 , V_236 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
}
V_26 = 0 ;
V_287:
if ( V_26 < 0 && V_285 )
F_140 ( L_3 ,
V_29 -> V_172 ) ;
if ( V_286 )
F_141 ( V_303 , V_29 ) ;
return V_26 ;
}
static int F_142 ( struct V_39 * V_40 , struct V_60 * V_61 , void * V_304 )
{
struct V_27 * V_27 = F_103 ( V_40 -> V_240 ) ;
struct V_97 * V_98 ;
struct V_28 * V_29 ;
int V_26 ;
struct V_32 * V_249 [ V_250 + 1 ] ;
char V_284 [ V_146 ] ;
V_26 = F_105 ( V_61 , sizeof( * V_98 ) , V_249 , V_250 , V_253 ) ;
if ( V_26 < 0 )
goto V_287;
if ( V_249 [ V_171 ] )
F_143 ( V_284 , V_249 [ V_171 ] , V_146 ) ;
else
V_284 [ 0 ] = '\0' ;
V_26 = - V_266 ;
V_98 = F_92 ( V_61 ) ;
if ( V_98 -> V_169 > 0 )
V_29 = F_121 ( V_27 , V_98 -> V_169 ) ;
else if ( V_249 [ V_171 ] )
V_29 = F_144 ( V_27 , V_284 ) ;
else
goto V_287;
if ( V_29 == NULL ) {
V_26 = - V_292 ;
goto V_287;
}
V_26 = F_115 ( V_29 , V_249 ) ;
if ( V_26 < 0 )
goto V_287;
V_26 = F_123 ( V_29 , V_98 , V_249 , V_284 , 0 ) ;
V_287:
return V_26 ;
}
static int F_145 ( struct V_39 * V_40 , struct V_60 * V_61 , void * V_304 )
{
struct V_27 * V_27 = F_103 ( V_40 -> V_240 ) ;
const struct V_18 * V_20 ;
struct V_28 * V_29 ;
struct V_97 * V_98 ;
char V_284 [ V_146 ] ;
struct V_32 * V_249 [ V_250 + 1 ] ;
int V_26 ;
F_31 ( V_30 ) ;
V_26 = F_105 ( V_61 , sizeof( * V_98 ) , V_249 , V_250 , V_253 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_249 [ V_171 ] )
F_143 ( V_284 , V_249 [ V_171 ] , V_146 ) ;
V_98 = F_92 ( V_61 ) ;
if ( V_98 -> V_169 > 0 )
V_29 = F_121 ( V_27 , V_98 -> V_169 ) ;
else if ( V_249 [ V_171 ] )
V_29 = F_144 ( V_27 , V_284 ) ;
else
return - V_266 ;
if ( ! V_29 )
return - V_292 ;
V_20 = V_29 -> V_18 ;
if ( ! V_20 )
return - V_270 ;
V_20 -> V_22 ( V_29 , & V_30 ) ;
F_33 ( & V_30 ) ;
F_36 ( & V_30 ) ;
return 0 ;
}
int F_146 ( struct V_28 * V_29 , const struct V_97 * V_98 )
{
unsigned int V_305 ;
int V_26 ;
V_305 = V_29 -> V_62 ;
if ( V_98 && ( V_98 -> V_99 || V_98 -> V_100 ) ) {
V_26 = F_147 ( V_29 , F_77 ( V_29 , V_98 ) ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_29 -> V_306 = V_307 ;
F_148 ( V_258 , V_29 , ~ 0U ) ;
F_149 ( V_29 , V_305 ) ;
return 0 ;
}
struct V_28 * F_150 ( struct V_27 * V_263 , struct V_27 * V_27 ,
char * V_284 , const struct V_18 * V_20 , struct V_32 * V_249 [] )
{
int V_26 ;
struct V_28 * V_29 ;
unsigned int V_185 = 1 ;
unsigned int V_187 = 1 ;
if ( V_249 [ V_184 ] )
V_185 = F_106 ( V_249 [ V_184 ] ) ;
else if ( V_20 -> V_308 )
V_185 = V_20 -> V_308 () ;
if ( V_249 [ V_186 ] )
V_187 = F_106 ( V_249 [ V_186 ] ) ;
else if ( V_20 -> V_309 )
V_187 = V_20 -> V_309 () ;
V_26 = - V_297 ;
V_29 = F_151 ( V_20 -> V_310 , V_284 , V_20 -> V_311 ,
V_185 , V_187 ) ;
if ( ! V_29 )
goto V_26;
F_152 ( V_29 , V_27 ) ;
V_29 -> V_18 = V_20 ;
V_29 -> V_306 = V_312 ;
if ( V_249 [ V_179 ] )
V_29 -> V_180 = F_106 ( V_249 [ V_179 ] ) ;
if ( V_249 [ V_206 ] )
memcpy ( V_29 -> V_207 , F_99 ( V_249 [ V_206 ] ) ,
F_116 ( V_249 [ V_206 ] ) ) ;
if ( V_249 [ V_208 ] )
memcpy ( V_29 -> V_209 , F_99 ( V_249 [ V_208 ] ) ,
F_116 ( V_249 [ V_208 ] ) ) ;
if ( V_249 [ V_173 ] )
V_29 -> V_174 = F_106 ( V_249 [ V_173 ] ) ;
if ( V_249 [ V_175 ] )
F_71 ( V_29 , F_137 ( V_249 [ V_175 ] ) ) ;
if ( V_249 [ V_177 ] )
V_29 -> V_178 = F_137 ( V_249 [ V_177 ] ) ;
if ( V_249 [ V_181 ] )
F_132 ( V_29 , F_106 ( V_249 [ V_181 ] ) ) ;
return V_29 ;
V_26:
return F_153 ( V_26 ) ;
}
static int F_154 ( struct V_27 * V_27 , int V_53 ,
struct V_97 * V_98 ,
struct V_32 * * V_249 )
{
struct V_28 * V_29 ;
int V_26 ;
F_32 (net, dev) {
if ( V_29 -> V_53 == V_53 ) {
V_26 = F_123 ( V_29 , V_98 , V_249 , NULL , 0 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
return 0 ;
}
static int F_155 ( struct V_39 * V_40 , struct V_60 * V_61 , void * V_304 )
{
struct V_27 * V_27 = F_103 ( V_40 -> V_240 ) ;
const struct V_18 * V_20 ;
struct V_28 * V_29 ;
struct V_97 * V_98 ;
char V_19 [ V_313 ] ;
char V_284 [ V_146 ] ;
struct V_32 * V_249 [ V_250 + 1 ] ;
struct V_32 * V_41 [ V_314 + 1 ] ;
int V_26 ;
#ifdef F_156
V_315:
#endif
V_26 = F_105 ( V_61 , sizeof( * V_98 ) , V_249 , V_250 , V_253 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_249 [ V_171 ] )
F_143 ( V_284 , V_249 [ V_171 ] , V_146 ) ;
else
V_284 [ 0 ] = '\0' ;
V_98 = F_92 ( V_61 ) ;
if ( V_98 -> V_169 > 0 )
V_29 = F_121 ( V_27 , V_98 -> V_169 ) ;
else {
if ( V_284 [ 0 ] )
V_29 = F_144 ( V_27 , V_284 ) ;
else
V_29 = NULL ;
}
V_26 = F_115 ( V_29 , V_249 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_249 [ V_44 ] ) {
V_26 = F_138 ( V_41 , V_314 ,
V_249 [ V_44 ] , V_316 ) ;
if ( V_26 < 0 )
return V_26 ;
} else
memset ( V_41 , 0 , sizeof( V_41 ) ) ;
if ( V_41 [ V_46 ] ) {
F_143 ( V_19 , V_41 [ V_46 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_32 * V_163 [ V_20 ? V_20 -> V_317 + 1 : 0 ] , * * V_42 = NULL ;
struct V_27 * V_318 ;
if ( V_20 ) {
if ( V_20 -> V_317 && V_41 [ V_50 ] ) {
V_26 = F_138 ( V_163 , V_20 -> V_317 ,
V_41 [ V_50 ] ,
V_20 -> V_319 ) ;
if ( V_26 < 0 )
return V_26 ;
V_42 = V_163 ;
}
if ( V_20 -> V_320 ) {
V_26 = V_20 -> V_320 ( V_249 , V_42 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
if ( V_29 ) {
int V_285 = 0 ;
if ( V_61 -> V_321 & V_322 )
return - V_21 ;
if ( V_61 -> V_321 & V_323 )
return - V_270 ;
if ( V_41 [ V_50 ] ) {
if ( ! V_20 || V_20 != V_29 -> V_18 ||
! V_20 -> V_324 )
return - V_270 ;
V_26 = V_20 -> V_324 ( V_29 , V_249 , V_42 ) ;
if ( V_26 < 0 )
return V_26 ;
V_285 = 1 ;
}
return F_123 ( V_29 , V_98 , V_249 , V_284 , V_285 ) ;
}
if ( ! ( V_61 -> V_321 & V_325 ) ) {
if ( V_98 -> V_169 == 0 && V_249 [ V_181 ] )
return F_154 ( V_27 ,
F_106 ( V_249 [ V_181 ] ) ,
V_98 , V_249 ) ;
return - V_292 ;
}
if ( V_249 [ V_204 ] || V_249 [ V_191 ] || V_249 [ V_326 ] )
return - V_270 ;
if ( ! V_20 ) {
#ifdef F_156
if ( V_19 [ 0 ] ) {
F_3 () ;
F_157 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_315;
}
#endif
return - V_270 ;
}
if ( ! V_284 [ 0 ] )
snprintf ( V_284 , V_146 , L_5 , V_20 -> V_19 ) ;
V_318 = F_111 ( V_27 , V_249 ) ;
if ( F_124 ( V_318 ) )
return F_125 ( V_318 ) ;
V_29 = F_150 ( V_27 , V_318 , V_284 , V_20 , V_249 ) ;
if ( F_124 ( V_29 ) ) {
V_26 = F_125 ( V_29 ) ;
goto V_45;
}
V_29 -> V_170 = V_98 -> V_169 ;
if ( V_20 -> V_327 )
V_26 = V_20 -> V_327 ( V_27 , V_29 , V_249 , V_42 ) ;
else
V_26 = F_158 ( V_29 ) ;
if ( V_26 < 0 && ! F_124 ( V_29 ) )
F_159 ( V_29 ) ;
if ( V_26 < 0 )
goto V_45;
V_26 = F_146 ( V_29 , V_98 ) ;
if ( V_26 < 0 )
F_160 ( V_29 ) ;
V_45:
F_127 ( V_318 ) ;
return V_26 ;
}
}
static int F_161 ( struct V_39 * V_40 , struct V_60 * V_61 , void * V_304 )
{
struct V_27 * V_27 = F_103 ( V_40 -> V_240 ) ;
struct V_97 * V_98 ;
char V_284 [ V_146 ] ;
struct V_32 * V_249 [ V_250 + 1 ] ;
struct V_28 * V_29 = NULL ;
struct V_39 * V_328 ;
int V_26 ;
T_5 V_129 = 0 ;
V_26 = F_105 ( V_61 , sizeof( * V_98 ) , V_249 , V_250 , V_253 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_249 [ V_171 ] )
F_143 ( V_284 , V_249 [ V_171 ] , V_146 ) ;
if ( V_249 [ V_254 ] )
V_129 = F_106 ( V_249 [ V_254 ] ) ;
V_98 = F_92 ( V_61 ) ;
if ( V_98 -> V_169 > 0 )
V_29 = F_121 ( V_27 , V_98 -> V_169 ) ;
else if ( V_249 [ V_171 ] )
V_29 = F_144 ( V_27 , V_284 ) ;
else
return - V_266 ;
if ( V_29 == NULL )
return - V_292 ;
V_328 = F_162 ( F_84 ( V_29 , V_129 ) , V_15 ) ;
if ( V_328 == NULL )
return - V_16 ;
V_26 = F_89 ( V_328 , V_29 , V_258 , F_52 ( V_40 ) . V_259 ,
V_61 -> V_260 , 0 , 0 , V_129 ) ;
if ( V_26 < 0 ) {
F_163 ( V_26 == - V_43 ) ;
F_164 ( V_328 ) ;
} else
V_26 = F_56 ( V_328 , V_27 , F_52 ( V_40 ) . V_259 ) ;
return V_26 ;
}
static T_8 F_165 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_103 ( V_40 -> V_240 ) ;
struct V_28 * V_29 ;
struct V_32 * V_249 [ V_250 + 1 ] ;
T_5 V_129 = 0 ;
T_8 V_329 = 0 ;
if ( F_105 ( V_61 , sizeof( struct V_252 ) , V_249 , V_250 ,
V_253 ) >= 0 ) {
if ( V_249 [ V_254 ] )
V_129 = F_106 ( V_249 [ V_254 ] ) ;
}
if ( ! V_129 )
return V_330 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_329 = F_166 ( T_8 , V_329 ,
F_84 ( V_29 ,
V_129 ) ) ;
}
return V_329 ;
}
static int F_167 ( struct V_39 * V_40 , struct V_238 * V_239 )
{
int V_243 ;
int V_244 = V_239 -> V_36 ;
if ( V_244 == 0 )
V_244 = 1 ;
for ( V_243 = 1 ; V_243 <= V_9 ; V_243 ++ ) {
int type = V_239 -> V_61 -> V_331 - V_4 ;
if ( V_243 < V_244 || V_243 == V_332 )
continue;
if ( V_10 [ V_243 ] == NULL ||
V_10 [ V_243 ] [ type ] . V_13 == NULL )
continue;
if ( V_243 > V_244 )
memset ( & V_239 -> args [ 0 ] , 0 , sizeof( V_239 -> args ) ) ;
if ( V_10 [ V_243 ] [ type ] . V_13 ( V_40 , V_239 ) )
break;
}
V_239 -> V_36 = V_243 ;
return V_40 -> V_262 ;
}
void F_148 ( int type , struct V_28 * V_29 , unsigned int V_160 )
{
struct V_27 * V_27 = F_122 ( V_29 ) ;
struct V_39 * V_40 ;
int V_26 = - V_16 ;
T_4 V_333 ;
V_40 = F_162 ( ( V_333 = F_84 ( V_29 , 0 ) ) , V_15 ) ;
if ( V_40 == NULL )
goto V_287;
V_26 = F_89 ( V_40 , V_29 , type , 0 , 0 , V_160 , 0 , 0 ) ;
if ( V_26 < 0 ) {
F_163 ( V_26 == - V_43 ) ;
F_164 ( V_40 ) ;
goto V_287;
}
F_58 ( V_40 , V_27 , 0 , V_334 , NULL , V_15 ) ;
return;
V_287:
if ( V_26 < 0 )
F_61 ( V_27 , V_334 , V_26 ) ;
}
static int F_168 ( struct V_39 * V_40 ,
struct V_28 * V_29 ,
T_9 * V_335 , T_5 V_52 , T_5 V_159 ,
int type , unsigned int V_62 )
{
struct V_60 * V_61 ;
struct V_336 * V_337 ;
V_61 = F_91 ( V_40 , V_52 , V_159 , type , sizeof( * V_337 ) , V_261 ) ;
if ( ! V_61 )
return - V_43 ;
V_337 = F_92 ( V_61 ) ;
V_337 -> V_338 = V_339 ;
V_337 -> V_340 = 0 ;
V_337 -> V_341 = 0 ;
V_337 -> V_342 = V_62 ;
V_337 -> V_343 = 0 ;
V_337 -> V_344 = V_29 -> V_170 ;
V_337 -> V_345 = V_346 ;
if ( F_70 ( V_40 , V_347 , V_348 , V_335 ) )
goto V_70;
return F_100 ( V_40 , V_61 ) ;
V_70:
F_101 ( V_40 , V_61 ) ;
return - V_43 ;
}
static inline T_4 F_169 ( void )
{
return F_85 ( sizeof( struct V_336 ) ) + F_39 ( V_348 ) ;
}
static void F_170 ( struct V_28 * V_29 , T_9 * V_335 , int type )
{
struct V_27 * V_27 = F_122 ( V_29 ) ;
struct V_39 * V_40 ;
int V_26 = - V_16 ;
V_40 = F_162 ( F_169 () , V_349 ) ;
if ( ! V_40 )
goto V_287;
V_26 = F_168 ( V_40 , V_29 , V_335 , 0 , 0 , type , V_350 ) ;
if ( V_26 < 0 ) {
F_164 ( V_40 ) ;
goto V_287;
}
F_58 ( V_40 , V_27 , 0 , V_351 , NULL , V_349 ) ;
return;
V_287:
F_61 ( V_27 , V_351 , V_26 ) ;
}
static int F_171 ( struct V_39 * V_40 , struct V_60 * V_61 , void * V_304 )
{
struct V_27 * V_27 = F_103 ( V_40 -> V_240 ) ;
struct V_28 * V_190 = NULL ;
struct V_336 * V_337 ;
struct V_32 * V_249 [ V_352 + 1 ] ;
struct V_28 * V_29 ;
T_9 * V_335 ;
int V_26 ;
V_26 = F_105 ( V_61 , sizeof( * V_337 ) , V_249 , V_352 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_337 = F_92 ( V_61 ) ;
if ( V_337 -> V_344 == 0 ) {
F_172 ( L_6 ) ;
return - V_266 ;
}
V_29 = F_121 ( V_27 , V_337 -> V_344 ) ;
if ( V_29 == NULL ) {
F_172 ( L_7 ) ;
return - V_292 ;
}
if ( ! V_249 [ V_347 ] || F_116 ( V_249 [ V_347 ] ) != V_348 ) {
F_172 ( L_8 ) ;
return - V_266 ;
}
V_335 = F_99 ( V_249 [ V_347 ] ) ;
if ( ! F_173 ( V_335 ) ) {
F_172 ( L_9 ) ;
return - V_266 ;
}
V_26 = - V_270 ;
if ( ( ! V_337 -> V_342 || V_337 -> V_342 & V_353 ) &&
( V_29 -> V_354 & V_355 ) ) {
V_190 = V_29 -> V_190 ;
V_26 = V_190 -> V_144 -> V_356 ( V_337 , V_249 ,
V_29 , V_335 ,
V_61 -> V_321 ) ;
if ( V_26 )
goto V_45;
else
V_337 -> V_342 &= ~ V_353 ;
}
if ( ( V_337 -> V_342 & V_350 ) && V_29 -> V_144 -> V_356 ) {
V_26 = V_29 -> V_144 -> V_356 ( V_337 , V_249 ,
V_29 , V_335 ,
V_61 -> V_321 ) ;
if ( ! V_26 ) {
F_170 ( V_29 , V_335 , V_357 ) ;
V_337 -> V_342 &= ~ V_350 ;
}
}
V_45:
return V_26 ;
}
static int F_174 ( struct V_39 * V_40 , struct V_60 * V_61 , void * V_304 )
{
struct V_27 * V_27 = F_103 ( V_40 -> V_240 ) ;
struct V_336 * V_337 ;
struct V_32 * V_358 ;
struct V_28 * V_29 ;
int V_26 = - V_266 ;
T_10 * V_335 ;
if ( F_175 ( V_61 ) < sizeof( * V_337 ) )
return - V_266 ;
V_337 = F_92 ( V_61 ) ;
if ( V_337 -> V_344 == 0 ) {
F_172 ( L_10 ) ;
return - V_266 ;
}
V_29 = F_121 ( V_27 , V_337 -> V_344 ) ;
if ( V_29 == NULL ) {
F_172 ( L_11 ) ;
return - V_292 ;
}
V_358 = F_176 ( V_61 , sizeof( * V_337 ) , V_347 ) ;
if ( V_358 == NULL || F_116 ( V_358 ) != V_348 ) {
F_172 ( L_12 ) ;
return - V_266 ;
}
V_335 = F_99 ( V_358 ) ;
V_26 = - V_270 ;
if ( ( ! V_337 -> V_342 || V_337 -> V_342 & V_353 ) &&
( V_29 -> V_354 & V_355 ) ) {
struct V_28 * V_190 = V_29 -> V_190 ;
if ( V_190 -> V_144 -> V_359 )
V_26 = V_190 -> V_144 -> V_359 ( V_337 , V_29 , V_335 ) ;
if ( V_26 )
goto V_45;
else
V_337 -> V_342 &= ~ V_353 ;
}
if ( ( V_337 -> V_342 & V_350 ) && V_29 -> V_144 -> V_359 ) {
V_26 = V_29 -> V_144 -> V_359 ( V_337 , V_29 , V_335 ) ;
if ( ! V_26 ) {
F_170 ( V_29 , V_335 , V_360 ) ;
V_337 -> V_342 &= ~ V_350 ;
}
}
V_45:
return V_26 ;
}
static int F_177 ( struct V_39 * V_40 ,
struct V_238 * V_239 ,
struct V_28 * V_29 ,
int * V_243 ,
struct V_361 * V_24 )
{
struct V_362 * V_363 ;
int V_26 ;
T_5 V_259 , V_159 ;
V_259 = F_52 ( V_239 -> V_40 ) . V_259 ;
V_159 = V_239 -> V_61 -> V_260 ;
F_26 (ha, &list->list, list) {
if ( * V_243 < V_239 -> args [ 0 ] )
goto V_364;
V_26 = F_168 ( V_40 , V_29 , V_363 -> V_335 ,
V_259 , V_159 ,
V_357 , V_350 ) ;
if ( V_26 < 0 )
return V_26 ;
V_364:
* V_243 += 1 ;
}
return 0 ;
}
int F_178 ( struct V_39 * V_40 ,
struct V_238 * V_239 ,
struct V_28 * V_29 ,
int V_243 )
{
int V_26 ;
F_179 ( V_29 ) ;
V_26 = F_177 ( V_40 , V_239 , V_29 , & V_243 , & V_29 -> V_365 ) ;
if ( V_26 )
goto V_45;
F_177 ( V_40 , V_239 , V_29 , & V_243 , & V_29 -> V_366 ) ;
V_45:
F_180 ( V_29 ) ;
return V_243 ;
}
static int F_181 ( struct V_39 * V_40 , struct V_238 * V_239 )
{
int V_243 = 0 ;
struct V_27 * V_27 = F_103 ( V_40 -> V_240 ) ;
struct V_28 * V_29 ;
F_104 () ;
F_182 (net, dev) {
if ( V_29 -> V_354 & V_355 ) {
struct V_28 * V_190 = V_29 -> V_190 ;
const struct V_272 * V_20 = V_190 -> V_144 ;
if ( V_20 -> V_367 )
V_243 = V_20 -> V_367 ( V_40 , V_239 , V_29 , V_243 ) ;
}
if ( V_29 -> V_144 -> V_367 )
V_243 = V_29 -> V_144 -> V_367 ( V_40 , V_239 , V_29 , V_243 ) ;
}
F_110 () ;
V_239 -> args [ 0 ] = V_243 ;
return V_40 -> V_262 ;
}
static int F_183 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_103 ( V_40 -> V_240 ) ;
T_1 V_11 ;
int V_368 , V_19 ;
int V_369 ;
int V_36 ;
int type ;
int V_26 ;
type = V_61 -> V_331 ;
if ( type > V_370 )
return - V_270 ;
type -= V_4 ;
if ( V_61 -> F_175 < F_184 ( sizeof( struct V_252 ) ) )
return 0 ;
V_36 = ( (struct V_252 * ) F_185 ( V_61 ) ) -> V_371 ;
V_368 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_186 ( V_372 ) )
return - V_373 ;
if ( V_19 == 2 && V_61 -> V_321 & V_374 ) {
struct V_55 * V_56 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_375 = 0 ;
V_13 = F_16 ( V_36 , type ) ;
if ( V_13 == NULL )
return - V_270 ;
V_14 = F_17 ( V_36 , type ) ;
if ( V_14 )
V_375 = V_14 ( V_40 , V_61 ) ;
F_3 () ;
V_56 = V_27 -> V_56 ;
{
struct V_376 V_377 = {
. V_378 = V_13 ,
. V_375 = V_375 ,
} ;
V_26 = F_187 ( V_56 , V_40 , V_61 , & V_377 ) ;
}
F_1 () ;
return V_26 ;
}
memset ( V_379 , 0 , ( V_380 * sizeof( struct V_381 * ) ) ) ;
V_369 = V_382 [ V_368 ] ;
if ( V_61 -> F_175 < V_369 )
return - V_266 ;
if ( V_61 -> F_175 > V_369 ) {
int V_383 = V_61 -> F_175 - F_85 ( V_369 ) ;
struct V_381 * V_163 = ( void * ) V_61 + F_85 ( V_369 ) ;
while ( F_188 ( V_163 , V_383 ) ) {
unsigned int V_384 = V_163 -> V_385 ;
if ( V_384 ) {
if ( V_384 > V_386 [ V_368 ] )
return - V_266 ;
V_379 [ V_384 - 1 ] = V_163 ;
}
V_163 = F_189 ( V_163 , V_383 ) ;
}
}
V_11 = F_15 ( V_36 , type ) ;
if ( V_11 == NULL )
return - V_270 ;
return V_11 ( V_40 , V_61 , ( void * ) & V_379 [ 0 ] ) ;
}
static void F_190 ( struct V_39 * V_40 )
{
F_1 () ;
F_191 ( V_40 , & F_183 ) ;
F_5 () ;
}
static int F_192 ( struct V_387 * V_388 , unsigned long V_389 , void * V_390 )
{
struct V_28 * V_29 = V_390 ;
switch ( V_389 ) {
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
break;
default:
F_148 ( V_258 , V_29 , 0 ) ;
break;
}
return V_403 ;
}
static int T_11 F_193 ( struct V_27 * V_27 )
{
struct V_55 * V_240 ;
struct V_404 V_405 = {
. V_406 = V_407 ,
. V_408 = F_190 ,
. V_409 = & V_1 ,
. V_62 = V_410 ,
} ;
V_240 = F_194 ( V_27 , V_411 , & V_405 ) ;
if ( ! V_240 )
return - V_297 ;
V_27 -> V_56 = V_240 ;
return 0 ;
}
static void T_12 F_195 ( struct V_27 * V_27 )
{
F_196 ( V_27 -> V_56 ) ;
V_27 -> V_56 = NULL ;
}
void T_13 F_197 ( void )
{
int V_66 ;
V_380 = 0 ;
for ( V_66 = 0 ; V_66 < F_198 ( V_386 ) ; V_66 ++ )
if ( V_386 [ V_66 ] > V_380 )
V_380 = V_386 [ V_66 ] ;
V_379 = F_129 ( V_380 * sizeof( struct V_381 * ) , V_15 ) ;
if ( ! V_379 )
F_21 ( L_13 ) ;
if ( F_199 ( & V_412 ) )
F_21 ( L_14 ) ;
F_200 ( & V_413 ) ;
F_20 ( V_12 , V_414 , F_161 ,
F_102 , F_165 ) ;
F_20 ( V_12 , V_415 , F_142 , NULL , NULL ) ;
F_20 ( V_12 , V_258 , F_155 , NULL , NULL ) ;
F_20 ( V_12 , V_416 , F_145 , NULL , NULL ) ;
F_20 ( V_12 , V_417 , NULL , F_167 , NULL ) ;
F_20 ( V_12 , V_418 , NULL , F_167 , NULL ) ;
F_20 ( V_419 , V_357 , F_171 , NULL , NULL ) ;
F_20 ( V_419 , V_360 , F_174 , NULL , NULL ) ;
F_20 ( V_419 , V_420 , NULL , F_181 , NULL ) ;
}
