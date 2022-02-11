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
struct V_28 * V_165 = F_90 ( V_29 ) ;
F_91 () ;
V_61 = F_92 ( V_40 , V_52 , V_159 , type , sizeof( * V_98 ) , V_62 ) ;
if ( V_61 == NULL )
return - V_43 ;
V_98 = F_93 ( V_61 ) ;
V_98 -> V_166 = V_167 ;
V_98 -> V_168 = 0 ;
V_98 -> V_169 = V_29 -> type ;
V_98 -> V_170 = V_29 -> V_171 ;
V_98 -> V_99 = F_94 ( V_29 ) ;
V_98 -> V_100 = V_160 ;
if ( F_48 ( V_40 , V_172 , V_29 -> V_173 ) ||
F_64 ( V_40 , V_174 , V_29 -> V_175 ) ||
F_95 ( V_40 , V_176 ,
F_96 ( V_29 ) ? V_29 -> V_89 : V_177 ) ||
F_95 ( V_40 , V_178 , V_29 -> V_179 ) ||
F_64 ( V_40 , V_180 , V_29 -> V_181 ) ||
F_64 ( V_40 , V_182 , V_29 -> V_53 ) ||
F_64 ( V_40 , V_183 , V_29 -> V_184 ) ||
F_64 ( V_40 , V_185 , V_29 -> V_186 ) ||
#ifdef F_97
F_64 ( V_40 , V_187 , V_29 -> V_188 ) ||
#endif
( V_29 -> V_171 != V_29 -> V_189 &&
F_64 ( V_40 , V_190 , V_29 -> V_189 ) ) ||
( V_165 &&
F_64 ( V_40 , V_191 , V_165 -> V_171 ) ) ||
F_95 ( V_40 , V_192 , F_98 ( V_29 ) ) ||
( V_29 -> V_193 &&
F_48 ( V_40 , V_194 , V_29 -> V_193 -> V_20 -> V_73 ) ) ||
( V_29 -> V_195 &&
F_48 ( V_40 , V_196 , V_29 -> V_195 ) ) )
goto V_70;
if ( 1 ) {
struct V_148 V_197 = {
. V_198 = V_29 -> V_198 ,
. V_199 = V_29 -> V_199 ,
. V_200 = V_29 -> V_200 ,
. V_201 = V_29 -> V_201 ,
. V_202 = V_29 -> V_202 ,
. V_203 = V_29 -> V_204 ,
} ;
if ( F_70 ( V_40 , V_205 , sizeof( V_197 ) , & V_197 ) )
goto V_70;
}
if ( V_29 -> V_206 ) {
if ( F_70 ( V_40 , V_207 , V_29 -> V_206 , V_29 -> V_208 ) ||
F_70 ( V_40 , V_209 , V_29 -> V_206 , V_29 -> V_210 ) )
goto V_70;
}
V_163 = F_99 ( V_40 , V_211 ,
sizeof( struct V_101 ) ) ;
if ( V_163 == NULL )
goto V_70;
V_162 = F_100 ( V_29 , & V_161 ) ;
F_78 ( F_101 ( V_163 ) , V_162 ) ;
V_163 = F_99 ( V_40 , V_212 ,
sizeof( struct V_103 ) ) ;
if ( V_163 == NULL )
goto V_70;
F_79 ( F_101 ( V_163 ) , V_162 ) ;
if ( V_29 -> V_29 . V_130 && ( V_129 & V_131 ) &&
F_64 ( V_40 , V_213 , F_82 ( V_29 -> V_29 . V_130 ) ) )
goto V_70;
if ( V_29 -> V_144 -> V_214 && V_29 -> V_29 . V_130
&& ( V_129 & V_131 ) ) {
int V_66 ;
struct V_32 * V_215 , * V_152 ;
int V_132 = F_82 ( V_29 -> V_29 . V_130 ) ;
V_215 = F_47 ( V_40 , V_216 ) ;
if ( ! V_215 )
goto V_70;
for ( V_66 = 0 ; V_66 < V_132 ; V_66 ++ ) {
struct V_217 V_218 ;
struct V_133 V_219 ;
struct V_134 V_220 ;
struct V_135 V_221 ;
struct V_136 V_222 ;
struct V_223 V_224 ;
V_218 . V_225 = - 1 ;
memset ( V_218 . V_226 , 0 , sizeof( V_218 . V_226 ) ) ;
V_218 . V_227 = 0 ;
if ( V_29 -> V_144 -> V_214 ( V_29 , V_66 , & V_218 ) )
break;
V_219 . V_152 =
V_220 . V_152 =
V_221 . V_152 =
V_222 . V_152 =
V_224 . V_152 = V_218 . V_152 ;
memcpy ( V_219 . V_226 , V_218 . V_226 , sizeof( V_218 . V_226 ) ) ;
V_220 . V_228 = V_218 . V_228 ;
V_220 . V_229 = V_218 . V_229 ;
V_221 . V_230 = V_218 . V_231 ;
V_222 . V_232 = V_218 . V_225 ;
V_224 . V_233 = V_218 . V_227 ;
V_152 = F_47 ( V_40 , V_234 ) ;
if ( ! V_152 ) {
F_50 ( V_40 , V_215 ) ;
goto V_70;
}
if ( F_70 ( V_40 , V_235 , sizeof( V_219 ) , & V_219 ) ||
F_70 ( V_40 , V_236 , sizeof( V_220 ) , & V_220 ) ||
F_70 ( V_40 , V_237 , sizeof( V_221 ) ,
& V_221 ) ||
F_70 ( V_40 , V_238 , sizeof( V_222 ) ,
& V_222 ) ||
F_70 ( V_40 , V_239 , sizeof( V_224 ) ,
& V_224 ) )
goto V_70;
F_49 ( V_40 , V_152 ) ;
}
F_49 ( V_40 , V_215 ) ;
}
if ( F_88 ( V_40 , V_29 ) )
goto V_70;
if ( V_29 -> V_18 ) {
if ( F_46 ( V_40 , V_29 ) < 0 )
goto V_70;
}
if ( ! ( V_164 = F_47 ( V_40 , V_240 ) ) )
goto V_70;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_37 -> V_241 ) {
struct V_32 * V_242 ;
int V_26 ;
if ( ! ( V_242 = F_47 ( V_40 , V_37 -> V_36 ) ) )
goto V_70;
V_26 = V_37 -> V_241 ( V_40 , V_29 ) ;
if ( V_26 == - V_243 )
F_50 ( V_40 , V_242 ) ;
else if ( V_26 < 0 )
goto V_70;
F_49 ( V_40 , V_242 ) ;
}
}
F_49 ( V_40 , V_164 ) ;
return F_102 ( V_40 , V_61 ) ;
V_70:
F_103 ( V_40 , V_61 ) ;
return - V_43 ;
}
static int F_104 ( struct V_39 * V_40 , struct V_244 * V_245 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
int V_247 , V_248 ;
int V_249 = 0 , V_250 ;
struct V_28 * V_29 ;
struct V_251 * V_252 ;
struct V_32 * V_253 [ V_254 + 1 ] ;
T_5 V_129 = 0 ;
V_248 = V_245 -> args [ 0 ] ;
V_250 = V_245 -> args [ 1 ] ;
F_106 () ;
V_245 -> V_159 = V_27 -> V_255 ;
if ( F_107 ( V_245 -> V_61 , sizeof( struct V_97 ) , V_253 , V_254 ,
V_256 ) >= 0 ) {
if ( V_253 [ V_257 ] )
V_129 = F_108 ( V_253 [ V_257 ] ) ;
}
for ( V_247 = V_248 ; V_247 < V_258 ; V_247 ++ , V_250 = 0 ) {
V_249 = 0 ;
V_252 = & V_27 -> V_259 [ V_247 ] ;
F_109 (dev, head, index_hlist) {
if ( V_249 < V_250 )
goto V_260;
if ( F_89 ( V_40 , V_29 , V_261 ,
F_52 ( V_245 -> V_40 ) . V_262 ,
V_245 -> V_61 -> V_263 , 0 ,
V_264 ,
V_129 ) <= 0 )
goto V_45;
F_110 ( V_245 , F_111 ( V_40 ) ) ;
V_260:
V_249 ++ ;
}
}
V_45:
F_112 () ;
V_245 -> args [ 1 ] = V_249 ;
V_245 -> args [ 0 ] = V_247 ;
return V_40 -> V_265 ;
}
struct V_27 * F_113 ( struct V_27 * V_266 , struct V_32 * V_253 [] )
{
struct V_27 * V_27 ;
if ( V_253 [ V_267 ] )
V_27 = F_114 ( F_108 ( V_253 [ V_267 ] ) ) ;
else if ( V_253 [ V_268 ] )
V_27 = F_115 ( F_108 ( V_253 [ V_268 ] ) ) ;
else
V_27 = F_116 ( V_266 ) ;
return V_27 ;
}
static int F_117 ( struct V_28 * V_29 , struct V_32 * V_253 [] )
{
if ( V_29 ) {
if ( V_253 [ V_207 ] &&
F_118 ( V_253 [ V_207 ] ) < V_29 -> V_206 )
return - V_269 ;
if ( V_253 [ V_209 ] &&
F_118 ( V_253 [ V_209 ] ) < V_29 -> V_206 )
return - V_269 ;
}
if ( V_253 [ V_240 ] ) {
struct V_32 * V_242 ;
int V_270 , V_26 ;
F_119 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_35 * V_37 ;
if ( ! ( V_37 = F_40 ( F_120 ( V_242 ) ) ) )
return - V_271 ;
if ( ! V_37 -> V_272 )
return - V_273 ;
if ( V_37 -> V_274 ) {
V_26 = V_37 -> V_274 ( V_29 , V_242 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
}
return 0 ;
}
static int F_121 ( struct V_28 * V_29 , struct V_32 * V_163 )
{
int V_270 , V_26 = - V_269 ;
struct V_32 * V_152 ;
const struct V_275 * V_20 = V_29 -> V_144 ;
F_119 (vf, attr, rem) {
switch ( F_120 ( V_152 ) ) {
case V_235 : {
struct V_133 * V_276 ;
V_276 = F_101 ( V_152 ) ;
V_26 = - V_273 ;
if ( V_20 -> V_277 )
V_26 = V_20 -> V_277 ( V_29 , V_276 -> V_152 ,
V_276 -> V_226 ) ;
break;
}
case V_236 : {
struct V_134 * V_278 ;
V_278 = F_101 ( V_152 ) ;
V_26 = - V_273 ;
if ( V_20 -> V_279 )
V_26 = V_20 -> V_279 ( V_29 , V_278 -> V_152 ,
V_278 -> V_228 ,
V_278 -> V_229 ) ;
break;
}
case V_237 : {
struct V_135 * V_280 ;
V_280 = F_101 ( V_152 ) ;
V_26 = - V_273 ;
if ( V_20 -> V_281 )
V_26 = V_20 -> V_281 ( V_29 , V_280 -> V_152 ,
V_280 -> V_230 ) ;
break;
}
case V_238 : {
struct V_136 * V_282 ;
V_282 = F_101 ( V_152 ) ;
V_26 = - V_273 ;
if ( V_20 -> V_283 )
V_26 = V_20 -> V_283 ( V_29 , V_282 -> V_152 ,
V_282 -> V_232 ) ;
break;
}
case V_239 : {
struct V_223 * V_284 ;
V_284 = F_101 ( V_152 ) ;
V_26 = - V_273 ;
if ( V_20 -> V_285 )
V_26 = V_20 -> V_285 ( V_29 , V_284 -> V_152 ,
V_284 -> V_233 ) ;
break;
}
default:
V_26 = - V_269 ;
break;
}
if ( V_26 )
break;
}
return V_26 ;
}
static int F_122 ( struct V_28 * V_29 , int V_171 )
{
struct V_28 * V_165 = F_90 ( V_29 ) ;
const struct V_275 * V_20 ;
int V_26 ;
if ( V_165 ) {
if ( V_165 -> V_171 == V_171 )
return 0 ;
V_20 = V_165 -> V_144 ;
if ( V_20 -> V_286 ) {
V_26 = V_20 -> V_286 ( V_165 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_273 ;
}
}
if ( V_171 ) {
V_165 = F_123 ( F_124 ( V_29 ) , V_171 ) ;
if ( ! V_165 )
return - V_269 ;
V_20 = V_165 -> V_144 ;
if ( V_20 -> V_287 ) {
V_26 = V_20 -> V_287 ( V_165 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_273 ;
}
}
return 0 ;
}
static int F_125 ( struct V_28 * V_29 , struct V_97 * V_98 ,
struct V_32 * * V_253 , char * V_288 , int V_289 )
{
const struct V_275 * V_20 = V_29 -> V_144 ;
int V_26 ;
if ( V_253 [ V_267 ] || V_253 [ V_268 ] ) {
struct V_27 * V_27 = F_113 ( F_124 ( V_29 ) , V_253 ) ;
if ( F_126 ( V_27 ) ) {
V_26 = F_127 ( V_27 ) ;
goto V_290;
}
if ( ! F_128 ( V_27 -> V_291 , V_292 ) ) {
V_26 = - V_293 ;
goto V_290;
}
V_26 = F_129 ( V_29 , V_27 , V_288 ) ;
F_130 ( V_27 ) ;
if ( V_26 )
goto V_290;
V_289 = 1 ;
}
if ( V_253 [ V_205 ] ) {
struct V_148 * V_294 ;
struct V_295 V_296 ;
if ( ! V_20 -> V_297 ) {
V_26 = - V_273 ;
goto V_290;
}
if ( ! F_131 ( V_29 ) ) {
V_26 = - V_298 ;
goto V_290;
}
V_294 = F_101 ( V_253 [ V_205 ] ) ;
V_296 . V_198 = ( unsigned long ) V_294 -> V_198 ;
V_296 . V_199 = ( unsigned long ) V_294 -> V_199 ;
V_296 . V_200 = ( unsigned short ) V_294 -> V_200 ;
V_296 . V_201 = ( unsigned char ) V_294 -> V_201 ;
V_296 . V_202 = ( unsigned char ) V_294 -> V_202 ;
V_296 . V_203 = ( unsigned char ) V_294 -> V_203 ;
V_26 = V_20 -> V_297 ( V_29 , & V_296 ) ;
if ( V_26 < 0 )
goto V_290;
V_289 = 1 ;
}
if ( V_253 [ V_207 ] ) {
struct V_299 * V_300 ;
int V_265 ;
V_265 = sizeof( V_301 ) + V_29 -> V_206 ;
V_300 = F_132 ( V_265 , V_15 ) ;
if ( ! V_300 ) {
V_26 = - V_302 ;
goto V_290;
}
V_300 -> V_303 = V_29 -> type ;
memcpy ( V_300 -> V_304 , F_101 ( V_253 [ V_207 ] ) ,
V_29 -> V_206 ) ;
V_26 = F_133 ( V_29 , V_300 ) ;
F_24 ( V_300 ) ;
if ( V_26 )
goto V_290;
V_289 = 1 ;
}
if ( V_253 [ V_180 ] ) {
V_26 = F_134 ( V_29 , F_108 ( V_253 [ V_180 ] ) ) ;
if ( V_26 < 0 )
goto V_290;
V_289 = 1 ;
}
if ( V_253 [ V_182 ] ) {
F_135 ( V_29 , F_108 ( V_253 [ V_182 ] ) ) ;
V_289 = 1 ;
}
if ( V_98 -> V_170 > 0 && V_288 [ 0 ] ) {
V_26 = F_136 ( V_29 , V_288 ) ;
if ( V_26 < 0 )
goto V_290;
V_289 = 1 ;
}
if ( V_253 [ V_196 ] ) {
V_26 = F_137 ( V_29 , F_101 ( V_253 [ V_196 ] ) ,
F_118 ( V_253 [ V_196 ] ) ) ;
if ( V_26 < 0 )
goto V_290;
V_289 = 1 ;
}
if ( V_253 [ V_209 ] ) {
F_138 ( V_29 -> V_210 , V_253 [ V_209 ] , V_29 -> V_206 ) ;
F_139 ( V_305 , V_29 ) ;
}
if ( V_98 -> V_99 || V_98 -> V_100 ) {
V_26 = F_140 ( V_29 , F_77 ( V_29 , V_98 ) ) ;
if ( V_26 < 0 )
goto V_290;
}
if ( V_253 [ V_191 ] ) {
V_26 = F_122 ( V_29 , F_108 ( V_253 [ V_191 ] ) ) ;
if ( V_26 )
goto V_290;
V_289 = 1 ;
}
if ( V_253 [ V_192 ] ) {
V_26 = F_141 ( V_29 , F_142 ( V_253 [ V_192 ] ) ) ;
if ( V_26 )
goto V_290;
V_289 = 1 ;
}
if ( V_253 [ V_174 ] )
V_29 -> V_175 = F_108 ( V_253 [ V_174 ] ) ;
if ( V_253 [ V_176 ] )
F_71 ( V_29 , F_142 ( V_253 [ V_176 ] ) ) ;
if ( V_253 [ V_178 ] ) {
F_73 ( & V_93 ) ;
V_29 -> V_179 = F_142 ( V_253 [ V_178 ] ) ;
F_74 ( & V_93 ) ;
}
if ( V_253 [ V_216 ] ) {
struct V_32 * V_163 ;
int V_270 ;
F_119 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_120 ( V_163 ) != V_234 ) {
V_26 = - V_269 ;
goto V_290;
}
V_26 = F_121 ( V_29 , V_163 ) ;
if ( V_26 < 0 )
goto V_290;
V_289 = 1 ;
}
}
V_26 = 0 ;
if ( V_253 [ V_153 ] ) {
struct V_32 * V_203 [ V_306 + 1 ] ;
struct V_32 * V_163 ;
int V_152 ;
int V_270 ;
V_26 = - V_273 ;
if ( ! V_20 -> V_307 )
goto V_290;
F_119 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_120 ( V_163 ) != V_154 )
continue;
V_26 = F_143 ( V_203 , V_306 ,
V_163 , V_308 ) ;
if ( V_26 < 0 )
goto V_290;
if ( ! V_203 [ V_155 ] ) {
V_26 = - V_273 ;
goto V_290;
}
V_152 = F_108 ( V_203 [ V_155 ] ) ;
V_26 = V_20 -> V_307 ( V_29 , V_152 , V_203 ) ;
if ( V_26 < 0 )
goto V_290;
V_289 = 1 ;
}
}
V_26 = 0 ;
if ( V_253 [ V_157 ] ) {
struct V_32 * V_203 [ V_306 + 1 ] ;
V_26 = F_143 ( V_203 , V_306 ,
V_253 [ V_157 ] , V_308 ) ;
if ( V_26 < 0 )
goto V_290;
V_26 = - V_273 ;
if ( V_20 -> V_307 )
V_26 = V_20 -> V_307 ( V_29 , V_158 , V_203 ) ;
if ( V_26 < 0 )
goto V_290;
V_289 = 1 ;
}
if ( V_253 [ V_240 ] ) {
struct V_32 * V_242 ;
int V_270 ;
F_119 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_35 * V_37 ;
if ( ! ( V_37 = F_40 ( F_120 ( V_242 ) ) ) )
F_144 () ;
V_26 = V_37 -> V_272 ( V_29 , V_242 ) ;
if ( V_26 < 0 )
goto V_290;
V_289 = 1 ;
}
}
V_26 = 0 ;
V_290:
if ( V_26 < 0 && V_289 )
F_145 ( L_3 ,
V_29 -> V_173 ) ;
return V_26 ;
}
static int F_146 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
struct V_97 * V_98 ;
struct V_28 * V_29 ;
int V_26 ;
struct V_32 * V_253 [ V_254 + 1 ] ;
char V_288 [ V_146 ] ;
V_26 = F_107 ( V_61 , sizeof( * V_98 ) , V_253 , V_254 , V_256 ) ;
if ( V_26 < 0 )
goto V_290;
if ( V_253 [ V_172 ] )
F_147 ( V_288 , V_253 [ V_172 ] , V_146 ) ;
else
V_288 [ 0 ] = '\0' ;
V_26 = - V_269 ;
V_98 = F_93 ( V_61 ) ;
if ( V_98 -> V_170 > 0 )
V_29 = F_123 ( V_27 , V_98 -> V_170 ) ;
else if ( V_253 [ V_172 ] )
V_29 = F_148 ( V_27 , V_288 ) ;
else
goto V_290;
if ( V_29 == NULL ) {
V_26 = - V_298 ;
goto V_290;
}
V_26 = F_117 ( V_29 , V_253 ) ;
if ( V_26 < 0 )
goto V_290;
V_26 = F_125 ( V_29 , V_98 , V_253 , V_288 , 0 ) ;
V_290:
return V_26 ;
}
static int F_149 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
const struct V_18 * V_20 ;
struct V_28 * V_29 ;
struct V_97 * V_98 ;
char V_288 [ V_146 ] ;
struct V_32 * V_253 [ V_254 + 1 ] ;
int V_26 ;
F_31 ( V_30 ) ;
V_26 = F_107 ( V_61 , sizeof( * V_98 ) , V_253 , V_254 , V_256 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_253 [ V_172 ] )
F_147 ( V_288 , V_253 [ V_172 ] , V_146 ) ;
V_98 = F_93 ( V_61 ) ;
if ( V_98 -> V_170 > 0 )
V_29 = F_123 ( V_27 , V_98 -> V_170 ) ;
else if ( V_253 [ V_172 ] )
V_29 = F_148 ( V_27 , V_288 ) ;
else
return - V_269 ;
if ( ! V_29 )
return - V_298 ;
V_20 = V_29 -> V_18 ;
if ( ! V_20 )
return - V_273 ;
V_20 -> V_22 ( V_29 , & V_30 ) ;
F_33 ( & V_30 ) ;
F_36 ( & V_30 ) ;
return 0 ;
}
int F_150 ( struct V_28 * V_29 , const struct V_97 * V_98 )
{
unsigned int V_309 ;
int V_26 ;
V_309 = V_29 -> V_62 ;
if ( V_98 && ( V_98 -> V_99 || V_98 -> V_100 ) ) {
V_26 = F_151 ( V_29 , F_77 ( V_29 , V_98 ) ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_29 -> V_310 = V_311 ;
F_152 ( V_261 , V_29 , ~ 0U ) ;
F_153 ( V_29 , V_309 ) ;
return 0 ;
}
struct V_28 * F_154 ( struct V_27 * V_27 ,
char * V_288 , const struct V_18 * V_20 , struct V_32 * V_253 [] )
{
int V_26 ;
struct V_28 * V_29 ;
unsigned int V_186 = 1 ;
unsigned int V_188 = 1 ;
if ( V_253 [ V_185 ] )
V_186 = F_108 ( V_253 [ V_185 ] ) ;
else if ( V_20 -> V_312 )
V_186 = V_20 -> V_312 () ;
if ( V_253 [ V_187 ] )
V_188 = F_108 ( V_253 [ V_187 ] ) ;
else if ( V_20 -> V_313 )
V_188 = V_20 -> V_313 () ;
V_26 = - V_302 ;
V_29 = F_155 ( V_20 -> V_314 , V_288 , V_20 -> V_315 ,
V_186 , V_188 ) ;
if ( ! V_29 )
goto V_26;
F_156 ( V_29 , V_27 ) ;
V_29 -> V_18 = V_20 ;
V_29 -> V_310 = V_316 ;
if ( V_253 [ V_180 ] )
V_29 -> V_181 = F_108 ( V_253 [ V_180 ] ) ;
if ( V_253 [ V_207 ] ) {
memcpy ( V_29 -> V_208 , F_101 ( V_253 [ V_207 ] ) ,
F_118 ( V_253 [ V_207 ] ) ) ;
V_29 -> V_317 = V_318 ;
}
if ( V_253 [ V_209 ] )
memcpy ( V_29 -> V_210 , F_101 ( V_253 [ V_209 ] ) ,
F_118 ( V_253 [ V_209 ] ) ) ;
if ( V_253 [ V_174 ] )
V_29 -> V_175 = F_108 ( V_253 [ V_174 ] ) ;
if ( V_253 [ V_176 ] )
F_71 ( V_29 , F_142 ( V_253 [ V_176 ] ) ) ;
if ( V_253 [ V_178 ] )
V_29 -> V_179 = F_142 ( V_253 [ V_178 ] ) ;
if ( V_253 [ V_182 ] )
F_135 ( V_29 , F_108 ( V_253 [ V_182 ] ) ) ;
return V_29 ;
V_26:
return F_157 ( V_26 ) ;
}
static int F_158 ( struct V_27 * V_27 , int V_53 ,
struct V_97 * V_98 ,
struct V_32 * * V_253 )
{
struct V_28 * V_29 ;
int V_26 ;
F_32 (net, dev) {
if ( V_29 -> V_53 == V_53 ) {
V_26 = F_125 ( V_29 , V_98 , V_253 , NULL , 0 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
return 0 ;
}
static int F_159 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
const struct V_18 * V_20 ;
struct V_28 * V_29 ;
struct V_97 * V_98 ;
char V_19 [ V_319 ] ;
char V_288 [ V_146 ] ;
struct V_32 * V_253 [ V_254 + 1 ] ;
struct V_32 * V_41 [ V_320 + 1 ] ;
int V_26 ;
#ifdef F_160
V_321:
#endif
V_26 = F_107 ( V_61 , sizeof( * V_98 ) , V_253 , V_254 , V_256 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_253 [ V_172 ] )
F_147 ( V_288 , V_253 [ V_172 ] , V_146 ) ;
else
V_288 [ 0 ] = '\0' ;
V_98 = F_93 ( V_61 ) ;
if ( V_98 -> V_170 > 0 )
V_29 = F_123 ( V_27 , V_98 -> V_170 ) ;
else {
if ( V_288 [ 0 ] )
V_29 = F_148 ( V_27 , V_288 ) ;
else
V_29 = NULL ;
}
V_26 = F_117 ( V_29 , V_253 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_253 [ V_44 ] ) {
V_26 = F_143 ( V_41 , V_320 ,
V_253 [ V_44 ] , V_322 ) ;
if ( V_26 < 0 )
return V_26 ;
} else
memset ( V_41 , 0 , sizeof( V_41 ) ) ;
if ( V_41 [ V_46 ] ) {
F_147 ( V_19 , V_41 [ V_46 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_32 * V_163 [ V_20 ? V_20 -> V_323 + 1 : 0 ] , * * V_42 = NULL ;
struct V_27 * V_324 ;
if ( V_20 ) {
if ( V_20 -> V_323 && V_41 [ V_50 ] ) {
V_26 = F_143 ( V_163 , V_20 -> V_323 ,
V_41 [ V_50 ] ,
V_20 -> V_325 ) ;
if ( V_26 < 0 )
return V_26 ;
V_42 = V_163 ;
}
if ( V_20 -> V_326 ) {
V_26 = V_20 -> V_326 ( V_253 , V_42 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
if ( V_29 ) {
int V_289 = 0 ;
if ( V_61 -> V_327 & V_328 )
return - V_21 ;
if ( V_61 -> V_327 & V_329 )
return - V_273 ;
if ( V_41 [ V_50 ] ) {
if ( ! V_20 || V_20 != V_29 -> V_18 ||
! V_20 -> V_330 )
return - V_273 ;
V_26 = V_20 -> V_330 ( V_29 , V_253 , V_42 ) ;
if ( V_26 < 0 )
return V_26 ;
V_289 = 1 ;
}
return F_125 ( V_29 , V_98 , V_253 , V_288 , V_289 ) ;
}
if ( ! ( V_61 -> V_327 & V_331 ) ) {
if ( V_98 -> V_170 == 0 && V_253 [ V_182 ] )
return F_158 ( V_27 ,
F_108 ( V_253 [ V_182 ] ) ,
V_98 , V_253 ) ;
return - V_298 ;
}
if ( V_253 [ V_205 ] || V_253 [ V_191 ] || V_253 [ V_332 ] )
return - V_273 ;
if ( ! V_20 ) {
#ifdef F_160
if ( V_19 [ 0 ] ) {
F_3 () ;
F_161 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_321;
}
#endif
return - V_273 ;
}
if ( ! V_288 [ 0 ] )
snprintf ( V_288 , V_146 , L_5 , V_20 -> V_19 ) ;
V_324 = F_113 ( V_27 , V_253 ) ;
if ( F_126 ( V_324 ) )
return F_127 ( V_324 ) ;
V_29 = F_154 ( V_324 , V_288 , V_20 , V_253 ) ;
if ( F_126 ( V_29 ) ) {
V_26 = F_127 ( V_29 ) ;
goto V_45;
}
V_29 -> V_171 = V_98 -> V_170 ;
if ( V_20 -> V_333 )
V_26 = V_20 -> V_333 ( V_27 , V_29 , V_253 , V_42 ) ;
else
V_26 = F_162 ( V_29 ) ;
if ( V_26 < 0 && ! F_126 ( V_29 ) )
F_163 ( V_29 ) ;
if ( V_26 < 0 )
goto V_45;
V_26 = F_150 ( V_29 , V_98 ) ;
if ( V_26 < 0 )
F_164 ( V_29 ) ;
V_45:
F_130 ( V_324 ) ;
return V_26 ;
}
}
static int F_165 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
struct V_97 * V_98 ;
char V_288 [ V_146 ] ;
struct V_32 * V_253 [ V_254 + 1 ] ;
struct V_28 * V_29 = NULL ;
struct V_39 * V_334 ;
int V_26 ;
T_5 V_129 = 0 ;
V_26 = F_107 ( V_61 , sizeof( * V_98 ) , V_253 , V_254 , V_256 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_253 [ V_172 ] )
F_147 ( V_288 , V_253 [ V_172 ] , V_146 ) ;
if ( V_253 [ V_257 ] )
V_129 = F_108 ( V_253 [ V_257 ] ) ;
V_98 = F_93 ( V_61 ) ;
if ( V_98 -> V_170 > 0 )
V_29 = F_123 ( V_27 , V_98 -> V_170 ) ;
else if ( V_253 [ V_172 ] )
V_29 = F_148 ( V_27 , V_288 ) ;
else
return - V_269 ;
if ( V_29 == NULL )
return - V_298 ;
V_334 = F_166 ( F_84 ( V_29 , V_129 ) , V_15 ) ;
if ( V_334 == NULL )
return - V_16 ;
V_26 = F_89 ( V_334 , V_29 , V_261 , F_52 ( V_40 ) . V_262 ,
V_61 -> V_263 , 0 , 0 , V_129 ) ;
if ( V_26 < 0 ) {
F_167 ( V_26 == - V_43 ) ;
F_168 ( V_334 ) ;
} else
V_26 = F_56 ( V_334 , V_27 , F_52 ( V_40 ) . V_262 ) ;
return V_26 ;
}
static T_8 F_169 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
struct V_28 * V_29 ;
struct V_32 * V_253 [ V_254 + 1 ] ;
T_5 V_129 = 0 ;
T_8 V_335 = 0 ;
if ( F_107 ( V_61 , sizeof( struct V_97 ) , V_253 , V_254 ,
V_256 ) >= 0 ) {
if ( V_253 [ V_257 ] )
V_129 = F_108 ( V_253 [ V_257 ] ) ;
}
if ( ! V_129 )
return V_336 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_335 = F_170 ( T_8 , V_335 ,
F_84 ( V_29 ,
V_129 ) ) ;
}
return V_335 ;
}
static int F_171 ( struct V_39 * V_40 , struct V_244 * V_245 )
{
int V_249 ;
int V_250 = V_245 -> V_36 ;
if ( V_250 == 0 )
V_250 = 1 ;
for ( V_249 = 1 ; V_249 <= V_9 ; V_249 ++ ) {
int type = V_245 -> V_61 -> V_337 - V_4 ;
if ( V_249 < V_250 || V_249 == V_338 )
continue;
if ( V_10 [ V_249 ] == NULL ||
V_10 [ V_249 ] [ type ] . V_13 == NULL )
continue;
if ( V_249 > V_250 ) {
memset ( & V_245 -> args [ 0 ] , 0 , sizeof( V_245 -> args ) ) ;
V_245 -> V_339 = 0 ;
V_245 -> V_159 = 0 ;
}
if ( V_10 [ V_249 ] [ type ] . V_13 ( V_40 , V_245 ) )
break;
}
V_245 -> V_36 = V_249 ;
return V_40 -> V_265 ;
}
void F_152 ( int type , struct V_28 * V_29 , unsigned int V_160 )
{
struct V_27 * V_27 = F_124 ( V_29 ) ;
struct V_39 * V_40 ;
int V_26 = - V_16 ;
T_4 V_340 ;
V_40 = F_166 ( ( V_340 = F_84 ( V_29 , 0 ) ) , V_15 ) ;
if ( V_40 == NULL )
goto V_290;
V_26 = F_89 ( V_40 , V_29 , type , 0 , 0 , V_160 , 0 , 0 ) ;
if ( V_26 < 0 ) {
F_167 ( V_26 == - V_43 ) ;
F_168 ( V_40 ) ;
goto V_290;
}
F_58 ( V_40 , V_27 , 0 , V_341 , NULL , V_15 ) ;
return;
V_290:
if ( V_26 < 0 )
F_61 ( V_27 , V_341 , V_26 ) ;
}
static int F_172 ( struct V_39 * V_40 ,
struct V_28 * V_29 ,
T_9 * V_342 , T_5 V_52 , T_5 V_159 ,
int type , unsigned int V_62 )
{
struct V_60 * V_61 ;
struct V_343 * V_344 ;
V_61 = F_92 ( V_40 , V_52 , V_159 , type , sizeof( * V_344 ) , V_264 ) ;
if ( ! V_61 )
return - V_43 ;
V_344 = F_93 ( V_61 ) ;
V_344 -> V_345 = V_346 ;
V_344 -> V_347 = 0 ;
V_344 -> V_348 = 0 ;
V_344 -> V_349 = V_62 ;
V_344 -> V_350 = 0 ;
V_344 -> V_351 = V_29 -> V_171 ;
V_344 -> V_352 = V_353 ;
if ( F_70 ( V_40 , V_354 , V_355 , V_342 ) )
goto V_70;
return F_102 ( V_40 , V_61 ) ;
V_70:
F_103 ( V_40 , V_61 ) ;
return - V_43 ;
}
static inline T_4 F_173 ( void )
{
return F_85 ( sizeof( struct V_343 ) ) + F_39 ( V_355 ) ;
}
static void F_174 ( struct V_28 * V_29 , T_9 * V_342 , int type )
{
struct V_27 * V_27 = F_124 ( V_29 ) ;
struct V_39 * V_40 ;
int V_26 = - V_16 ;
V_40 = F_166 ( F_173 () , V_356 ) ;
if ( ! V_40 )
goto V_290;
V_26 = F_172 ( V_40 , V_29 , V_342 , 0 , 0 , type , V_357 ) ;
if ( V_26 < 0 ) {
F_168 ( V_40 ) ;
goto V_290;
}
F_58 ( V_40 , V_27 , 0 , V_358 , NULL , V_356 ) ;
return;
V_290:
F_61 ( V_27 , V_358 , V_26 ) ;
}
int F_175 ( struct V_343 * V_344 ,
struct V_32 * V_253 [] ,
struct V_28 * V_29 ,
const unsigned char * V_342 ,
T_8 V_62 )
{
int V_26 = - V_269 ;
if ( V_344 -> V_352 && ! ( V_344 -> V_352 & V_353 ) ) {
F_176 ( L_6 , V_29 -> V_173 ) ;
return V_26 ;
}
if ( F_177 ( V_342 ) || F_178 ( V_342 ) )
V_26 = F_179 ( V_29 , V_342 ) ;
else if ( F_180 ( V_342 ) )
V_26 = F_181 ( V_29 , V_342 ) ;
if ( V_26 == - V_21 && ! ( V_62 & V_328 ) )
V_26 = 0 ;
return V_26 ;
}
static int F_182 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
struct V_343 * V_344 ;
struct V_32 * V_253 [ V_359 + 1 ] ;
struct V_28 * V_29 ;
T_9 * V_342 ;
int V_26 ;
V_26 = F_107 ( V_61 , sizeof( * V_344 ) , V_253 , V_359 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_344 = F_93 ( V_61 ) ;
if ( V_344 -> V_351 == 0 ) {
F_176 ( L_7 ) ;
return - V_269 ;
}
V_29 = F_123 ( V_27 , V_344 -> V_351 ) ;
if ( V_29 == NULL ) {
F_176 ( L_8 ) ;
return - V_298 ;
}
if ( ! V_253 [ V_354 ] || F_118 ( V_253 [ V_354 ] ) != V_355 ) {
F_176 ( L_9 ) ;
return - V_269 ;
}
V_342 = F_101 ( V_253 [ V_354 ] ) ;
V_26 = - V_273 ;
if ( ( ! V_344 -> V_349 || V_344 -> V_349 & V_360 ) &&
( V_29 -> V_361 & V_362 ) ) {
struct V_28 * V_363 = F_90 ( V_29 ) ;
const struct V_275 * V_20 = V_363 -> V_144 ;
V_26 = V_20 -> V_364 ( V_344 , V_253 , V_29 , V_342 , V_61 -> V_327 ) ;
if ( V_26 )
goto V_45;
else
V_344 -> V_349 &= ~ V_360 ;
}
if ( ( V_344 -> V_349 & V_357 ) ) {
if ( V_29 -> V_144 -> V_364 )
V_26 = V_29 -> V_144 -> V_364 ( V_344 , V_253 , V_29 , V_342 ,
V_61 -> V_327 ) ;
else
V_26 = F_175 ( V_344 , V_253 , V_29 , V_342 ,
V_61 -> V_327 ) ;
if ( ! V_26 ) {
F_174 ( V_29 , V_342 , V_365 ) ;
V_344 -> V_349 &= ~ V_357 ;
}
}
V_45:
return V_26 ;
}
int F_183 ( struct V_343 * V_344 ,
struct V_32 * V_253 [] ,
struct V_28 * V_29 ,
const unsigned char * V_342 )
{
int V_26 = - V_273 ;
if ( ! ( V_344 -> V_352 & V_353 ) ) {
F_176 ( L_6 , V_29 -> V_173 ) ;
return - V_269 ;
}
if ( F_177 ( V_342 ) || F_178 ( V_342 ) )
V_26 = F_184 ( V_29 , V_342 ) ;
else if ( F_180 ( V_342 ) )
V_26 = F_185 ( V_29 , V_342 ) ;
else
V_26 = - V_269 ;
return V_26 ;
}
static int F_186 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
struct V_343 * V_344 ;
struct V_32 * V_253 [ V_359 + 1 ] ;
struct V_28 * V_29 ;
int V_26 = - V_269 ;
T_10 * V_342 ;
if ( ! F_187 ( V_292 ) )
return - V_293 ;
V_26 = F_107 ( V_61 , sizeof( * V_344 ) , V_253 , V_359 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_344 = F_93 ( V_61 ) ;
if ( V_344 -> V_351 == 0 ) {
F_176 ( L_10 ) ;
return - V_269 ;
}
V_29 = F_123 ( V_27 , V_344 -> V_351 ) ;
if ( V_29 == NULL ) {
F_176 ( L_11 ) ;
return - V_298 ;
}
if ( ! V_253 [ V_354 ] || F_118 ( V_253 [ V_354 ] ) != V_355 ) {
F_176 ( L_12 ) ;
return - V_269 ;
}
V_342 = F_101 ( V_253 [ V_354 ] ) ;
V_26 = - V_273 ;
if ( ( ! V_344 -> V_349 || V_344 -> V_349 & V_360 ) &&
( V_29 -> V_361 & V_362 ) ) {
struct V_28 * V_363 = F_90 ( V_29 ) ;
const struct V_275 * V_20 = V_363 -> V_144 ;
if ( V_20 -> V_366 )
V_26 = V_20 -> V_366 ( V_344 , V_253 , V_29 , V_342 ) ;
if ( V_26 )
goto V_45;
else
V_344 -> V_349 &= ~ V_360 ;
}
if ( V_344 -> V_349 & V_357 ) {
if ( V_29 -> V_144 -> V_366 )
V_26 = V_29 -> V_144 -> V_366 ( V_344 , V_253 , V_29 , V_342 ) ;
else
V_26 = F_183 ( V_344 , V_253 , V_29 , V_342 ) ;
if ( ! V_26 ) {
F_174 ( V_29 , V_342 , V_367 ) ;
V_344 -> V_349 &= ~ V_357 ;
}
}
V_45:
return V_26 ;
}
static int F_188 ( struct V_39 * V_40 ,
struct V_244 * V_245 ,
struct V_28 * V_29 ,
int * V_249 ,
struct V_368 * V_24 )
{
struct V_369 * V_370 ;
int V_26 ;
T_5 V_262 , V_159 ;
V_262 = F_52 ( V_245 -> V_40 ) . V_262 ;
V_159 = V_245 -> V_61 -> V_263 ;
F_26 (ha, &list->list, list) {
if ( * V_249 < V_245 -> args [ 0 ] )
goto V_371;
V_26 = F_172 ( V_40 , V_29 , V_370 -> V_342 ,
V_262 , V_159 ,
V_365 , V_357 ) ;
if ( V_26 < 0 )
return V_26 ;
V_371:
* V_249 += 1 ;
}
return 0 ;
}
int F_189 ( struct V_39 * V_40 ,
struct V_244 * V_245 ,
struct V_28 * V_29 ,
int V_249 )
{
int V_26 ;
F_190 ( V_29 ) ;
V_26 = F_188 ( V_40 , V_245 , V_29 , & V_249 , & V_29 -> V_372 ) ;
if ( V_26 )
goto V_45;
F_188 ( V_40 , V_245 , V_29 , & V_249 , & V_29 -> V_373 ) ;
V_45:
F_191 ( V_29 ) ;
return V_249 ;
}
static int F_192 ( struct V_39 * V_40 , struct V_244 * V_245 )
{
int V_249 = 0 ;
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
struct V_28 * V_29 ;
F_106 () ;
F_193 (net, dev) {
if ( V_29 -> V_361 & V_362 ) {
struct V_28 * V_363 ;
const struct V_275 * V_20 ;
V_363 = F_90 ( V_29 ) ;
V_20 = V_363 -> V_144 ;
if ( V_20 -> V_374 )
V_249 = V_20 -> V_374 ( V_40 , V_245 , V_29 , V_249 ) ;
}
if ( V_29 -> V_144 -> V_374 )
V_249 = V_29 -> V_144 -> V_374 ( V_40 , V_245 , V_29 , V_249 ) ;
else
V_249 = F_189 ( V_40 , V_245 , V_29 , V_249 ) ;
}
F_112 () ;
V_245 -> args [ 0 ] = V_249 ;
return V_40 -> V_265 ;
}
int F_194 ( struct V_39 * V_40 , T_5 V_52 , T_5 V_159 ,
struct V_28 * V_29 , T_8 V_375 )
{
struct V_60 * V_61 ;
struct V_97 * V_98 ;
struct V_32 * V_376 ;
T_9 V_89 = F_96 ( V_29 ) ? V_29 -> V_89 : V_177 ;
struct V_28 * V_363 = F_90 ( V_29 ) ;
V_61 = F_92 ( V_40 , V_52 , V_159 , V_261 , sizeof( * V_98 ) , V_264 ) ;
if ( V_61 == NULL )
return - V_43 ;
V_98 = F_93 ( V_61 ) ;
V_98 -> V_166 = V_346 ;
V_98 -> V_168 = 0 ;
V_98 -> V_169 = V_29 -> type ;
V_98 -> V_170 = V_29 -> V_171 ;
V_98 -> V_99 = F_94 ( V_29 ) ;
V_98 -> V_100 = 0 ;
if ( F_48 ( V_40 , V_172 , V_29 -> V_173 ) ||
F_64 ( V_40 , V_180 , V_29 -> V_181 ) ||
F_95 ( V_40 , V_176 , V_89 ) ||
( V_363 &&
F_64 ( V_40 , V_191 , V_363 -> V_171 ) ) ||
( V_29 -> V_206 &&
F_70 ( V_40 , V_207 , V_29 -> V_206 , V_29 -> V_208 ) ) ||
( V_29 -> V_171 != V_29 -> V_189 &&
F_64 ( V_40 , V_190 , V_29 -> V_189 ) ) )
goto V_70;
V_376 = F_47 ( V_40 , V_240 ) ;
if ( ! V_376 )
goto V_70;
if ( F_195 ( V_40 , V_377 , V_378 ) ||
F_195 ( V_40 , V_379 , V_375 ) ) {
F_50 ( V_40 , V_376 ) ;
goto V_70;
}
F_49 ( V_40 , V_376 ) ;
return F_102 ( V_40 , V_61 ) ;
V_70:
F_103 ( V_40 , V_61 ) ;
return - V_43 ;
}
static int F_196 ( struct V_39 * V_40 , struct V_244 * V_245 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
struct V_28 * V_29 ;
int V_249 = 0 ;
T_5 V_262 = F_52 ( V_245 -> V_40 ) . V_262 ;
T_5 V_159 = V_245 -> V_61 -> V_263 ;
struct V_32 * V_380 ;
T_5 V_381 = 0 ;
V_380 = F_197 ( V_245 -> V_61 , sizeof( struct V_97 ) ,
V_257 ) ;
if ( V_380 )
V_381 = F_108 ( V_380 ) ;
F_106 () ;
F_193 (net, dev) {
const struct V_275 * V_20 = V_29 -> V_144 ;
struct V_28 * V_363 = F_90 ( V_29 ) ;
if ( V_363 && V_363 -> V_144 -> V_382 ) {
if ( V_249 >= V_245 -> args [ 0 ] &&
V_363 -> V_144 -> V_382 (
V_40 , V_262 , V_159 , V_29 , V_381 ) < 0 )
break;
V_249 ++ ;
}
if ( V_20 -> V_382 ) {
if ( V_249 >= V_245 -> args [ 0 ] &&
V_20 -> V_382 ( V_40 , V_262 , V_159 , V_29 ,
V_381 ) < 0 )
break;
V_249 ++ ;
}
}
F_112 () ;
V_245 -> args [ 0 ] = V_249 ;
return V_40 -> V_265 ;
}
static inline T_4 F_198 ( void )
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
static int F_199 ( struct V_28 * V_29 , T_8 V_62 )
{
struct V_27 * V_27 = F_124 ( V_29 ) ;
struct V_28 * V_363 = F_90 ( V_29 ) ;
struct V_39 * V_40 ;
int V_26 = - V_273 ;
V_40 = F_166 ( F_198 () , V_356 ) ;
if ( ! V_40 ) {
V_26 = - V_302 ;
goto V_290;
}
if ( ( ! V_62 || ( V_62 & V_383 ) ) &&
V_363 && V_363 -> V_144 -> V_382 ) {
V_26 = V_363 -> V_144 -> V_382 ( V_40 , 0 , 0 , V_29 , 0 ) ;
if ( V_26 < 0 )
goto V_290;
}
if ( ( V_62 & V_378 ) &&
V_29 -> V_144 -> V_382 ) {
V_26 = V_29 -> V_144 -> V_382 ( V_40 , 0 , 0 , V_29 , 0 ) ;
if ( V_26 < 0 )
goto V_290;
}
F_58 ( V_40 , V_27 , 0 , V_341 , NULL , V_356 ) ;
return 0 ;
V_290:
F_167 ( V_26 == - V_43 ) ;
F_168 ( V_40 ) ;
F_61 ( V_27 , V_341 , V_26 ) ;
return V_26 ;
}
static int F_200 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
struct V_97 * V_98 ;
struct V_28 * V_29 ;
struct V_32 * V_384 , * V_163 = NULL ;
int V_270 , V_26 = - V_273 ;
T_8 V_385 , V_62 = 0 ;
bool V_386 = false ;
if ( F_201 ( V_61 ) < sizeof( * V_98 ) )
return - V_269 ;
V_98 = F_93 ( V_61 ) ;
if ( V_98 -> V_166 != V_346 )
return - V_387 ;
V_29 = F_123 ( V_27 , V_98 -> V_170 ) ;
if ( ! V_29 ) {
F_176 ( L_13 ) ;
return - V_298 ;
}
V_384 = F_197 ( V_61 , sizeof( struct V_97 ) , V_240 ) ;
if ( V_384 ) {
F_119 (attr, br_spec, rem) {
if ( F_120 ( V_163 ) == V_377 ) {
V_386 = true ;
V_62 = F_202 ( V_163 ) ;
break;
}
}
}
V_385 = V_62 ;
if ( ! V_62 || ( V_62 & V_383 ) ) {
struct V_28 * V_363 = F_90 ( V_29 ) ;
if ( ! V_363 || ! V_363 -> V_144 -> V_388 ) {
V_26 = - V_273 ;
goto V_45;
}
V_26 = V_363 -> V_144 -> V_388 ( V_29 , V_61 ) ;
if ( V_26 )
goto V_45;
V_62 &= ~ V_383 ;
}
if ( ( V_62 & V_378 ) ) {
if ( ! V_29 -> V_144 -> V_388 )
V_26 = - V_273 ;
else
V_26 = V_29 -> V_144 -> V_388 ( V_29 , V_61 ) ;
if ( ! V_26 )
V_62 &= ~ V_378 ;
}
if ( V_386 )
memcpy ( F_101 ( V_163 ) , & V_62 , sizeof( V_62 ) ) ;
if ( ! V_26 )
V_26 = F_199 ( V_29 , V_385 ) ;
V_45:
return V_26 ;
}
static int F_203 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
struct V_97 * V_98 ;
struct V_28 * V_29 ;
struct V_32 * V_384 , * V_163 = NULL ;
int V_270 , V_26 = - V_273 ;
T_8 V_385 , V_62 = 0 ;
bool V_386 = false ;
if ( F_201 ( V_61 ) < sizeof( * V_98 ) )
return - V_269 ;
V_98 = F_93 ( V_61 ) ;
if ( V_98 -> V_166 != V_346 )
return - V_387 ;
V_29 = F_123 ( V_27 , V_98 -> V_170 ) ;
if ( ! V_29 ) {
F_176 ( L_13 ) ;
return - V_298 ;
}
V_384 = F_197 ( V_61 , sizeof( struct V_97 ) , V_240 ) ;
if ( V_384 ) {
F_119 (attr, br_spec, rem) {
if ( F_120 ( V_163 ) == V_377 ) {
V_386 = true ;
V_62 = F_202 ( V_163 ) ;
break;
}
}
}
V_385 = V_62 ;
if ( ! V_62 || ( V_62 & V_383 ) ) {
struct V_28 * V_363 = F_90 ( V_29 ) ;
if ( ! V_363 || ! V_363 -> V_144 -> V_389 ) {
V_26 = - V_273 ;
goto V_45;
}
V_26 = V_363 -> V_144 -> V_389 ( V_29 , V_61 ) ;
if ( V_26 )
goto V_45;
V_62 &= ~ V_383 ;
}
if ( ( V_62 & V_378 ) ) {
if ( ! V_29 -> V_144 -> V_389 )
V_26 = - V_273 ;
else
V_26 = V_29 -> V_144 -> V_389 ( V_29 , V_61 ) ;
if ( ! V_26 )
V_62 &= ~ V_378 ;
}
if ( V_386 )
memcpy ( F_101 ( V_163 ) , & V_62 , sizeof( V_62 ) ) ;
if ( ! V_26 )
V_26 = F_199 ( V_29 , V_385 ) ;
V_45:
return V_26 ;
}
static int F_204 ( struct V_39 * V_40 , struct V_60 * V_61 )
{
struct V_27 * V_27 = F_105 ( V_40 -> V_246 ) ;
T_1 V_11 ;
int V_390 , V_19 ;
int V_36 ;
int type ;
int V_26 ;
type = V_61 -> V_337 ;
if ( type > V_391 )
return - V_273 ;
type -= V_4 ;
if ( F_201 ( V_61 ) < sizeof( struct V_392 ) )
return 0 ;
V_36 = ( (struct V_392 * ) F_93 ( V_61 ) ) -> V_393 ;
V_390 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_128 ( V_27 -> V_291 , V_292 ) )
return - V_293 ;
if ( V_19 == 2 && V_61 -> V_327 & V_394 ) {
struct V_55 * V_56 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_395 = 0 ;
V_13 = F_16 ( V_36 , type ) ;
if ( V_13 == NULL )
return - V_273 ;
V_14 = F_17 ( V_36 , type ) ;
if ( V_14 )
V_395 = V_14 ( V_40 , V_61 ) ;
F_3 () ;
V_56 = V_27 -> V_56 ;
{
struct V_396 V_397 = {
. V_398 = V_13 ,
. V_395 = V_395 ,
} ;
V_26 = F_205 ( V_56 , V_40 , V_61 , & V_397 ) ;
}
F_1 () ;
return V_26 ;
}
V_11 = F_15 ( V_36 , type ) ;
if ( V_11 == NULL )
return - V_273 ;
return V_11 ( V_40 , V_61 ) ;
}
static void F_206 ( struct V_39 * V_40 )
{
F_1 () ;
F_207 ( V_40 , & F_204 ) ;
F_5 () ;
}
static int F_208 ( struct V_399 * V_400 , unsigned long V_401 , void * V_402 )
{
struct V_28 * V_29 = F_209 ( V_402 ) ;
switch ( V_401 ) {
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
break;
default:
F_152 ( V_261 , V_29 , 0 ) ;
break;
}
return V_415 ;
}
static int T_11 F_210 ( struct V_27 * V_27 )
{
struct V_55 * V_246 ;
struct V_416 V_417 = {
. V_418 = V_419 ,
. V_420 = F_206 ,
. V_421 = & V_1 ,
. V_62 = V_422 ,
} ;
V_246 = F_211 ( V_27 , V_423 , & V_417 ) ;
if ( ! V_246 )
return - V_302 ;
V_27 -> V_56 = V_246 ;
return 0 ;
}
static void T_12 F_212 ( struct V_27 * V_27 )
{
F_213 ( V_27 -> V_56 ) ;
V_27 -> V_56 = NULL ;
}
void T_13 F_214 ( void )
{
if ( F_215 ( & V_424 ) )
F_21 ( L_14 ) ;
F_216 ( & V_425 ) ;
F_20 ( V_12 , V_426 , F_165 ,
F_104 , F_169 ) ;
F_20 ( V_12 , V_427 , F_146 , NULL , NULL ) ;
F_20 ( V_12 , V_261 , F_159 , NULL , NULL ) ;
F_20 ( V_12 , V_428 , F_149 , NULL , NULL ) ;
F_20 ( V_12 , V_429 , NULL , F_171 , NULL ) ;
F_20 ( V_12 , V_430 , NULL , F_171 , NULL ) ;
F_20 ( V_431 , V_365 , F_182 , NULL , NULL ) ;
F_20 ( V_431 , V_367 , F_186 , NULL , NULL ) ;
F_20 ( V_431 , V_432 , NULL , F_192 , NULL ) ;
F_20 ( V_431 , V_426 , NULL , F_196 , NULL ) ;
F_20 ( V_431 , V_428 , F_203 , NULL , NULL ) ;
F_20 ( V_431 , V_427 , F_200 , NULL , NULL ) ;
}
