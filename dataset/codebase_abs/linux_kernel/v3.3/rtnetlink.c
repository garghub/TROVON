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
void F_51 ( struct V_39 * V_40 , int V_52 , int V_53 , const void * V_42 )
{
struct V_54 * V_55 ;
int V_31 = F_52 ( V_53 ) ;
V_55 = (struct V_54 * ) F_53 ( V_40 , F_54 ( V_31 ) ) ;
V_55 -> V_56 = V_52 ;
V_55 -> V_57 = V_31 ;
memcpy ( F_55 ( V_55 ) , V_42 , V_53 ) ;
memset ( F_55 ( V_55 ) + V_53 , 0 , F_54 ( V_31 ) - V_31 ) ;
}
int F_56 ( struct V_39 * V_40 , struct V_27 * V_27 , T_5 V_58 , unsigned V_59 , int V_60 )
{
struct V_61 * V_62 = V_27 -> V_62 ;
int V_26 = 0 ;
F_57 ( V_40 ) . V_63 = V_59 ;
if ( V_60 )
F_58 ( & V_40 -> V_64 ) ;
F_59 ( V_62 , V_40 , V_58 , V_59 , V_15 ) ;
if ( V_60 )
V_26 = F_60 ( V_62 , V_40 , V_58 , V_65 ) ;
return V_26 ;
}
int F_61 ( struct V_39 * V_40 , struct V_27 * V_27 , T_5 V_58 )
{
struct V_61 * V_62 = V_27 -> V_62 ;
return F_62 ( V_62 , V_40 , V_58 ) ;
}
void F_63 ( struct V_39 * V_40 , struct V_27 * V_27 , T_5 V_58 , T_5 V_59 ,
struct V_66 * V_67 , T_6 V_68 )
{
struct V_61 * V_62 = V_27 -> V_62 ;
int V_69 = 0 ;
if ( V_67 )
V_69 = F_64 ( V_67 ) ;
F_65 ( V_62 , V_40 , V_58 , V_59 , V_69 , V_68 ) ;
}
void F_66 ( struct V_27 * V_27 , T_5 V_59 , int error )
{
struct V_61 * V_62 = V_27 -> V_62 ;
F_67 ( V_62 , 0 , V_59 , error ) ;
}
int F_68 ( struct V_39 * V_40 , T_5 * V_70 )
{
struct V_32 * V_71 ;
int V_72 , V_73 = 0 ;
V_71 = F_47 ( V_40 , V_74 ) ;
if ( V_71 == NULL )
return - V_16 ;
for ( V_72 = 0 ; V_72 < V_75 ; V_72 ++ ) {
if ( V_70 [ V_72 ] ) {
V_73 ++ ;
F_69 ( V_40 , V_72 + 1 , V_70 [ V_72 ] ) ;
}
}
if ( ! V_73 ) {
F_50 ( V_40 , V_71 ) ;
return 0 ;
}
return F_49 ( V_40 , V_71 ) ;
V_76:
F_50 ( V_40 , V_71 ) ;
return - V_43 ;
}
int F_70 ( struct V_39 * V_40 , struct V_77 * V_78 , T_5 V_79 ,
T_5 V_80 , T_5 V_81 , long V_82 , T_5 error )
{
struct V_83 V_84 = {
. V_85 = F_71 ( V_86 - V_78 -> V_87 ) ,
. V_88 = V_78 -> V_89 ,
. V_90 = F_72 ( & ( V_78 -> V_91 ) ) ,
. V_92 = error ,
. V_93 = V_79 ,
. V_94 = V_80 ,
. V_95 = V_81 ,
} ;
if ( V_82 )
V_84 . V_96 = F_71 ( V_82 ) ;
return F_73 ( V_40 , V_97 , sizeof( V_84 ) , & V_84 ) ;
}
static void F_74 ( struct V_28 * V_29 , unsigned char V_98 )
{
unsigned char V_99 = V_29 -> V_99 ;
switch ( V_98 ) {
case V_100 :
if ( ( V_99 == V_101 ||
V_99 == V_102 ) &&
! F_75 ( V_29 ) )
V_99 = V_100 ;
break;
case V_101 :
if ( V_99 == V_100 ||
V_99 == V_102 )
V_99 = V_101 ;
break;
}
if ( V_29 -> V_99 != V_99 ) {
F_76 ( & V_103 ) ;
V_29 -> V_99 = V_99 ;
F_77 ( & V_103 ) ;
F_78 ( V_29 ) ;
}
}
static unsigned int F_79 ( const struct V_28 * V_29 ,
const struct V_104 * V_105 )
{
unsigned int V_68 = V_105 -> V_106 ;
if ( V_105 -> V_107 )
V_68 = ( V_68 & V_105 -> V_107 ) |
( V_29 -> V_68 & ~ V_105 -> V_107 ) ;
return V_68 ;
}
static void F_80 ( struct V_108 * V_109 ,
const struct V_110 * V_111 )
{
V_109 -> V_112 = V_111 -> V_112 ;
V_109 -> V_113 = V_111 -> V_113 ;
V_109 -> V_114 = V_111 -> V_114 ;
V_109 -> V_115 = V_111 -> V_115 ;
V_109 -> V_116 = V_111 -> V_116 ;
V_109 -> V_117 = V_111 -> V_117 ;
V_109 -> V_118 = V_111 -> V_118 ;
V_109 -> V_119 = V_111 -> V_119 ;
V_109 -> V_120 = V_111 -> V_120 ;
V_109 -> V_121 = V_111 -> V_121 ;
V_109 -> V_122 = V_111 -> V_122 ;
V_109 -> V_123 = V_111 -> V_123 ;
V_109 -> V_124 = V_111 -> V_124 ;
V_109 -> V_125 = V_111 -> V_125 ;
V_109 -> V_126 = V_111 -> V_126 ;
V_109 -> V_127 = V_111 -> V_127 ;
V_109 -> V_128 = V_111 -> V_128 ;
V_109 -> V_129 = V_111 -> V_129 ;
V_109 -> V_130 = V_111 -> V_130 ;
V_109 -> V_131 = V_111 -> V_131 ;
V_109 -> V_132 = V_111 -> V_132 ;
V_109 -> V_133 = V_111 -> V_133 ;
V_109 -> V_134 = V_111 -> V_134 ;
}
static void F_81 ( void * V_135 , const struct V_110 * V_111 )
{
memcpy ( V_135 , V_111 , sizeof( * V_111 ) ) ;
}
static inline int F_82 ( const struct V_28 * V_29 ,
T_5 V_136 )
{
if ( V_29 -> V_29 . V_137 && F_83 ( V_29 -> V_29 . V_137 ) &&
( V_136 & V_138 ) ) {
int V_139 = F_84 ( V_29 -> V_29 . V_137 ) ;
T_4 V_31 = F_39 ( sizeof( struct V_32 ) ) ;
V_31 += F_39 ( V_139 * sizeof( struct V_32 ) ) ;
V_31 += V_139 *
( F_39 ( sizeof( struct V_140 ) ) +
F_39 ( sizeof( struct V_141 ) ) +
F_39 ( sizeof( struct V_142 ) ) +
F_39 ( sizeof( struct V_143 ) ) ) ;
return V_31 ;
} else
return 0 ;
}
static T_4 F_85 ( const struct V_28 * V_29 )
{
T_4 V_144 = F_39 ( 4 )
+ F_39 ( V_145 )
+ F_39 ( sizeof( struct V_146 ) )
+ F_39 ( V_147 )
+ F_39 ( V_147 )
+ F_39 ( 1 )
+ F_39 ( 2 ) ;
T_4 V_148 = F_39 ( sizeof( struct V_32 ) ) ;
T_4 V_149 = F_39 ( sizeof( struct V_32 ) )
+ V_144 ;
T_4 V_150 = F_39 ( sizeof( struct V_32 ) )
+ V_144 ;
if ( ! V_29 -> V_151 -> V_152 || ! V_29 -> V_29 . V_137 )
return 0 ;
if ( F_84 ( V_29 -> V_29 . V_137 ) )
return V_150 + V_148 +
V_149 * F_84 ( V_29 -> V_29 . V_137 ) ;
else
return V_150 ;
}
static T_7 T_4 F_86 ( const struct V_28 * V_29 ,
T_5 V_136 )
{
return F_87 ( sizeof( struct V_104 ) )
+ F_39 ( V_153 )
+ F_39 ( V_154 )
+ F_39 ( V_153 )
+ F_39 ( sizeof( struct V_155 ) )
+ F_39 ( sizeof( struct V_108 ) )
+ F_39 ( sizeof( struct V_110 ) )
+ F_39 ( V_156 )
+ F_39 ( V_156 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 1 )
+ F_39 ( 1 )
+ F_39 ( V_136
& V_138 ? 4 : 0 )
+ F_82 ( V_29 , V_136 )
+ F_85 ( V_29 )
+ F_38 ( V_29 )
+ F_45 ( V_29 ) ;
}
static int F_88 ( struct V_39 * V_40 , struct V_28 * V_29 )
{
struct V_32 * V_157 ;
struct V_32 * V_158 ;
int V_159 ;
int V_26 ;
V_157 = F_47 ( V_40 , V_160 ) ;
if ( ! V_157 )
return - V_43 ;
for ( V_159 = 0 ; V_159 < F_84 ( V_29 -> V_29 . V_137 ) ; V_159 ++ ) {
V_158 = F_47 ( V_40 , V_161 ) ;
if ( ! V_158 )
goto V_76;
F_69 ( V_40 , V_162 , V_159 ) ;
V_26 = V_29 -> V_151 -> V_152 ( V_29 , V_159 , V_40 ) ;
if ( V_26 == - V_43 )
goto V_76;
if ( V_26 ) {
F_50 ( V_40 , V_158 ) ;
continue;
}
F_49 ( V_40 , V_158 ) ;
}
F_49 ( V_40 , V_157 ) ;
return 0 ;
V_76:
F_50 ( V_40 , V_157 ) ;
return - V_43 ;
}
static int F_89 ( struct V_39 * V_40 , struct V_28 * V_29 )
{
struct V_32 * V_163 ;
int V_26 ;
V_163 = F_47 ( V_40 , V_164 ) ;
if ( ! V_163 )
return - V_43 ;
V_26 = V_29 -> V_151 -> V_152 ( V_29 , V_165 , V_40 ) ;
if ( V_26 ) {
F_50 ( V_40 , V_163 ) ;
return ( V_26 == - V_43 ) ? V_26 : 0 ;
}
F_49 ( V_40 , V_163 ) ;
return 0 ;
}
static int F_90 ( struct V_39 * V_40 , struct V_28 * V_29 )
{
int V_26 ;
if ( ! V_29 -> V_151 -> V_152 || ! V_29 -> V_29 . V_137 )
return 0 ;
V_26 = F_89 ( V_40 , V_29 ) ;
if ( V_26 )
return V_26 ;
if ( F_84 ( V_29 -> V_29 . V_137 ) ) {
V_26 = F_88 ( V_40 , V_29 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_91 ( struct V_39 * V_40 , struct V_28 * V_29 ,
int type , T_5 V_58 , T_5 V_166 , T_5 V_167 ,
unsigned int V_68 , T_5 V_136 )
{
struct V_104 * V_105 ;
struct V_66 * V_67 ;
struct V_110 V_168 ;
const struct V_110 * V_169 ;
struct V_32 * V_170 , * V_171 ;
struct V_35 * V_37 ;
F_92 () ;
V_67 = F_93 ( V_40 , V_58 , V_166 , type , sizeof( * V_105 ) , V_68 ) ;
if ( V_67 == NULL )
return - V_43 ;
V_105 = F_94 ( V_67 ) ;
V_105 -> V_172 = V_173 ;
V_105 -> V_174 = 0 ;
V_105 -> V_175 = V_29 -> type ;
V_105 -> V_176 = V_29 -> V_177 ;
V_105 -> V_106 = F_95 ( V_29 ) ;
V_105 -> V_107 = V_167 ;
F_96 ( V_40 , V_178 , V_29 -> V_179 ) ;
F_69 ( V_40 , V_180 , V_29 -> V_181 ) ;
F_97 ( V_40 , V_182 ,
F_98 ( V_29 ) ? V_29 -> V_99 : V_183 ) ;
F_97 ( V_40 , V_184 , V_29 -> V_185 ) ;
F_69 ( V_40 , V_186 , V_29 -> V_187 ) ;
F_69 ( V_40 , V_188 , V_29 -> V_59 ) ;
if ( V_29 -> V_177 != V_29 -> V_189 )
F_69 ( V_40 , V_190 , V_29 -> V_189 ) ;
if ( V_29 -> V_191 )
F_69 ( V_40 , V_192 , V_29 -> V_191 -> V_177 ) ;
if ( V_29 -> V_193 )
F_96 ( V_40 , V_194 , V_29 -> V_193 -> V_20 -> V_79 ) ;
if ( V_29 -> V_195 )
F_96 ( V_40 , V_196 , V_29 -> V_195 ) ;
if ( 1 ) {
struct V_155 V_197 = {
. V_198 = V_29 -> V_198 ,
. V_199 = V_29 -> V_199 ,
. V_200 = V_29 -> V_200 ,
. V_201 = V_29 -> V_201 ,
. V_202 = V_29 -> V_202 ,
. V_203 = V_29 -> V_204 ,
} ;
F_99 ( V_40 , V_205 , sizeof( V_197 ) , & V_197 ) ;
}
if ( V_29 -> V_206 ) {
F_99 ( V_40 , V_207 , V_29 -> V_206 , V_29 -> V_208 ) ;
F_99 ( V_40 , V_209 , V_29 -> V_206 , V_29 -> V_210 ) ;
}
V_170 = F_100 ( V_40 , V_211 ,
sizeof( struct V_108 ) ) ;
if ( V_170 == NULL )
goto V_76;
V_169 = F_101 ( V_29 , & V_168 ) ;
F_80 ( F_102 ( V_170 ) , V_169 ) ;
V_170 = F_100 ( V_40 , V_212 ,
sizeof( struct V_110 ) ) ;
if ( V_170 == NULL )
goto V_76;
F_81 ( F_102 ( V_170 ) , V_169 ) ;
if ( V_29 -> V_29 . V_137 && ( V_136 & V_138 ) )
F_69 ( V_40 , V_213 , F_84 ( V_29 -> V_29 . V_137 ) ) ;
if ( V_29 -> V_151 -> V_214 && V_29 -> V_29 . V_137
&& ( V_136 & V_138 ) ) {
int V_72 ;
struct V_32 * V_215 , * V_159 ;
int V_139 = F_84 ( V_29 -> V_29 . V_137 ) ;
V_215 = F_47 ( V_40 , V_216 ) ;
if ( ! V_215 )
goto V_76;
for ( V_72 = 0 ; V_72 < V_139 ; V_72 ++ ) {
struct V_217 V_218 ;
struct V_140 V_219 ;
struct V_141 V_220 ;
struct V_142 V_221 ;
struct V_143 V_222 ;
V_218 . V_223 = - 1 ;
if ( V_29 -> V_151 -> V_214 ( V_29 , V_72 , & V_218 ) )
break;
V_219 . V_159 =
V_220 . V_159 =
V_221 . V_159 =
V_222 . V_159 = V_218 . V_159 ;
memcpy ( V_219 . V_224 , V_218 . V_224 , sizeof( V_218 . V_224 ) ) ;
V_220 . V_225 = V_218 . V_225 ;
V_220 . V_226 = V_218 . V_226 ;
V_221 . V_227 = V_218 . V_228 ;
V_222 . V_229 = V_218 . V_223 ;
V_159 = F_47 ( V_40 , V_230 ) ;
if ( ! V_159 ) {
F_50 ( V_40 , V_215 ) ;
goto V_76;
}
F_99 ( V_40 , V_231 , sizeof( V_219 ) , & V_219 ) ;
F_99 ( V_40 , V_232 , sizeof( V_220 ) , & V_220 ) ;
F_99 ( V_40 , V_233 , sizeof( V_221 ) ,
& V_221 ) ;
F_99 ( V_40 , V_234 , sizeof( V_222 ) ,
& V_222 ) ;
F_49 ( V_40 , V_159 ) ;
}
F_49 ( V_40 , V_215 ) ;
}
if ( F_90 ( V_40 , V_29 ) )
goto V_76;
if ( V_29 -> V_18 ) {
if ( F_46 ( V_40 , V_29 ) < 0 )
goto V_76;
}
if ( ! ( V_171 = F_47 ( V_40 , V_235 ) ) )
goto V_76;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_37 -> V_236 ) {
struct V_32 * V_237 ;
int V_26 ;
if ( ! ( V_237 = F_47 ( V_40 , V_37 -> V_36 ) ) )
goto V_76;
V_26 = V_37 -> V_236 ( V_40 , V_29 ) ;
if ( V_26 == - V_238 )
F_50 ( V_40 , V_237 ) ;
else if ( V_26 < 0 )
goto V_76;
F_49 ( V_40 , V_237 ) ;
}
}
F_49 ( V_40 , V_171 ) ;
return F_103 ( V_40 , V_67 ) ;
V_76:
F_104 ( V_40 , V_67 ) ;
return - V_43 ;
}
static int F_105 ( struct V_39 * V_40 , struct V_239 * V_240 )
{
struct V_27 * V_27 = F_106 ( V_40 -> V_241 ) ;
int V_242 , V_243 ;
int V_244 = 0 , V_245 ;
struct V_28 * V_29 ;
struct V_246 * V_247 ;
struct V_248 * V_249 ;
struct V_32 * V_250 [ V_251 + 1 ] ;
T_5 V_136 = 0 ;
V_243 = V_240 -> args [ 0 ] ;
V_245 = V_240 -> args [ 1 ] ;
F_107 () ;
V_240 -> V_166 = V_27 -> V_252 ;
if ( F_108 ( V_240 -> V_67 , sizeof( struct V_253 ) , V_250 , V_251 ,
V_254 ) >= 0 ) {
if ( V_250 [ V_255 ] )
V_136 = F_109 ( V_250 [ V_255 ] ) ;
}
for ( V_242 = V_243 ; V_242 < V_256 ; V_242 ++ , V_245 = 0 ) {
V_244 = 0 ;
V_247 = & V_27 -> V_257 [ V_242 ] ;
F_110 (dev, node, head, index_hlist) {
if ( V_244 < V_245 )
goto V_258;
if ( F_91 ( V_40 , V_29 , V_259 ,
F_57 ( V_240 -> V_40 ) . V_58 ,
V_240 -> V_67 -> V_260 , 0 ,
V_261 ,
V_136 ) <= 0 )
goto V_45;
F_111 ( V_240 , F_112 ( V_40 ) ) ;
V_258:
V_244 ++ ;
}
}
V_45:
F_113 () ;
V_240 -> args [ 1 ] = V_244 ;
V_240 -> args [ 0 ] = V_242 ;
return V_40 -> V_262 ;
}
struct V_27 * F_114 ( struct V_27 * V_263 , struct V_32 * V_250 [] )
{
struct V_27 * V_27 ;
if ( V_250 [ V_264 ] )
V_27 = F_115 ( F_109 ( V_250 [ V_264 ] ) ) ;
else if ( V_250 [ V_265 ] )
V_27 = F_116 ( F_109 ( V_250 [ V_265 ] ) ) ;
else
V_27 = F_117 ( V_263 ) ;
return V_27 ;
}
static int F_118 ( struct V_28 * V_29 , struct V_32 * V_250 [] )
{
if ( V_29 ) {
if ( V_250 [ V_207 ] &&
F_119 ( V_250 [ V_207 ] ) < V_29 -> V_206 )
return - V_266 ;
if ( V_250 [ V_209 ] &&
F_119 ( V_250 [ V_209 ] ) < V_29 -> V_206 )
return - V_266 ;
}
if ( V_250 [ V_235 ] ) {
struct V_32 * V_237 ;
int V_267 , V_26 ;
F_120 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_35 * V_37 ;
if ( ! ( V_37 = F_40 ( F_121 ( V_237 ) ) ) )
return - V_268 ;
if ( ! V_37 -> V_269 )
return - V_270 ;
if ( V_37 -> V_271 ) {
V_26 = V_37 -> V_271 ( V_29 , V_237 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
}
return 0 ;
}
static int F_122 ( struct V_28 * V_29 , struct V_32 * V_170 )
{
int V_267 , V_26 = - V_266 ;
struct V_32 * V_159 ;
const struct V_272 * V_20 = V_29 -> V_151 ;
F_120 (vf, attr, rem) {
switch ( F_121 ( V_159 ) ) {
case V_231 : {
struct V_140 * V_273 ;
V_273 = F_102 ( V_159 ) ;
V_26 = - V_270 ;
if ( V_20 -> V_274 )
V_26 = V_20 -> V_274 ( V_29 , V_273 -> V_159 ,
V_273 -> V_224 ) ;
break;
}
case V_232 : {
struct V_141 * V_275 ;
V_275 = F_102 ( V_159 ) ;
V_26 = - V_270 ;
if ( V_20 -> V_276 )
V_26 = V_20 -> V_276 ( V_29 , V_275 -> V_159 ,
V_275 -> V_225 ,
V_275 -> V_226 ) ;
break;
}
case V_233 : {
struct V_142 * V_277 ;
V_277 = F_102 ( V_159 ) ;
V_26 = - V_270 ;
if ( V_20 -> V_278 )
V_26 = V_20 -> V_278 ( V_29 , V_277 -> V_159 ,
V_277 -> V_227 ) ;
break;
}
case V_234 : {
struct V_143 * V_279 ;
V_279 = F_102 ( V_159 ) ;
V_26 = - V_270 ;
if ( V_20 -> V_280 )
V_26 = V_20 -> V_280 ( V_29 , V_279 -> V_159 ,
V_279 -> V_229 ) ;
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
static int F_123 ( struct V_28 * V_29 , int V_177 )
{
struct V_28 * V_281 ;
const struct V_272 * V_20 ;
int V_26 ;
if ( V_29 -> V_191 ) {
if ( V_29 -> V_191 -> V_177 == V_177 )
return 0 ;
V_20 = V_29 -> V_191 -> V_151 ;
if ( V_20 -> V_282 ) {
V_26 = V_20 -> V_282 ( V_29 -> V_191 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_270 ;
}
}
if ( V_177 ) {
V_281 = F_124 ( F_125 ( V_29 ) , V_177 ) ;
if ( ! V_281 )
return - V_266 ;
V_20 = V_281 -> V_151 ;
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
static int F_126 ( struct V_28 * V_29 , struct V_104 * V_105 ,
struct V_32 * * V_250 , char * V_284 , int V_285 )
{
const struct V_272 * V_20 = V_29 -> V_151 ;
int V_286 = 0 ;
int V_26 ;
if ( V_250 [ V_264 ] || V_250 [ V_265 ] ) {
struct V_27 * V_27 = F_114 ( F_125 ( V_29 ) , V_250 ) ;
if ( F_127 ( V_27 ) ) {
V_26 = F_128 ( V_27 ) ;
goto V_287;
}
V_26 = F_129 ( V_29 , V_27 , V_284 ) ;
F_130 ( V_27 ) ;
if ( V_26 )
goto V_287;
V_285 = 1 ;
}
if ( V_250 [ V_205 ] ) {
struct V_155 * V_288 ;
struct V_289 V_290 ;
if ( ! V_20 -> V_291 ) {
V_26 = - V_270 ;
goto V_287;
}
if ( ! F_131 ( V_29 ) ) {
V_26 = - V_292 ;
goto V_287;
}
V_288 = F_102 ( V_250 [ V_205 ] ) ;
V_290 . V_198 = ( unsigned long ) V_288 -> V_198 ;
V_290 . V_199 = ( unsigned long ) V_288 -> V_199 ;
V_290 . V_200 = ( unsigned short ) V_288 -> V_200 ;
V_290 . V_201 = ( unsigned char ) V_288 -> V_201 ;
V_290 . V_202 = ( unsigned char ) V_288 -> V_202 ;
V_290 . V_203 = ( unsigned char ) V_288 -> V_203 ;
V_26 = V_20 -> V_291 ( V_29 , & V_290 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
if ( V_250 [ V_207 ] ) {
struct V_293 * V_294 ;
int V_262 ;
if ( ! V_20 -> V_295 ) {
V_26 = - V_270 ;
goto V_287;
}
if ( ! F_131 ( V_29 ) ) {
V_26 = - V_292 ;
goto V_287;
}
V_262 = sizeof( V_296 ) + V_29 -> V_206 ;
V_294 = F_132 ( V_262 , V_15 ) ;
if ( ! V_294 ) {
V_26 = - V_297 ;
goto V_287;
}
V_294 -> V_298 = V_29 -> type ;
memcpy ( V_294 -> V_299 , F_102 ( V_250 [ V_207 ] ) ,
V_29 -> V_206 ) ;
V_26 = V_20 -> V_295 ( V_29 , V_294 ) ;
F_24 ( V_294 ) ;
if ( V_26 )
goto V_287;
V_286 = 1 ;
V_285 = 1 ;
}
if ( V_250 [ V_186 ] ) {
V_26 = F_133 ( V_29 , F_109 ( V_250 [ V_186 ] ) ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
if ( V_250 [ V_188 ] ) {
F_134 ( V_29 , F_109 ( V_250 [ V_188 ] ) ) ;
V_285 = 1 ;
}
if ( V_105 -> V_176 > 0 && V_284 [ 0 ] ) {
V_26 = F_135 ( V_29 , V_284 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
if ( V_250 [ V_196 ] ) {
V_26 = F_136 ( V_29 , F_102 ( V_250 [ V_196 ] ) ,
F_119 ( V_250 [ V_196 ] ) ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
if ( V_250 [ V_209 ] ) {
F_137 ( V_29 -> V_210 , V_250 [ V_209 ] , V_29 -> V_206 ) ;
V_286 = 1 ;
}
if ( V_105 -> V_106 || V_105 -> V_107 ) {
V_26 = F_138 ( V_29 , F_79 ( V_29 , V_105 ) ) ;
if ( V_26 < 0 )
goto V_287;
}
if ( V_250 [ V_192 ] ) {
V_26 = F_123 ( V_29 , F_109 ( V_250 [ V_192 ] ) ) ;
if ( V_26 )
goto V_287;
V_285 = 1 ;
}
if ( V_250 [ V_180 ] )
V_29 -> V_181 = F_109 ( V_250 [ V_180 ] ) ;
if ( V_250 [ V_182 ] )
F_74 ( V_29 , F_139 ( V_250 [ V_182 ] ) ) ;
if ( V_250 [ V_184 ] ) {
F_76 ( & V_103 ) ;
V_29 -> V_185 = F_139 ( V_250 [ V_184 ] ) ;
F_77 ( & V_103 ) ;
}
if ( V_250 [ V_216 ] ) {
struct V_32 * V_170 ;
int V_267 ;
F_120 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_121 ( V_170 ) != V_230 ) {
V_26 = - V_266 ;
goto V_287;
}
V_26 = F_122 ( V_29 , V_170 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
}
V_26 = 0 ;
if ( V_250 [ V_160 ] ) {
struct V_32 * V_203 [ V_300 + 1 ] ;
struct V_32 * V_170 ;
int V_159 ;
int V_267 ;
V_26 = - V_270 ;
if ( ! V_20 -> V_301 )
goto V_287;
F_120 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_121 ( V_170 ) != V_161 )
continue;
V_26 = F_140 ( V_203 , V_300 ,
V_170 , V_302 ) ;
if ( V_26 < 0 )
goto V_287;
if ( ! V_203 [ V_162 ] ) {
V_26 = - V_270 ;
goto V_287;
}
V_159 = F_109 ( V_203 [ V_162 ] ) ;
V_26 = V_20 -> V_301 ( V_29 , V_159 , V_203 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
}
V_26 = 0 ;
if ( V_250 [ V_164 ] ) {
struct V_32 * V_203 [ V_300 + 1 ] ;
V_26 = F_140 ( V_203 , V_300 ,
V_250 [ V_164 ] , V_302 ) ;
if ( V_26 < 0 )
goto V_287;
V_26 = - V_270 ;
if ( V_20 -> V_301 )
V_26 = V_20 -> V_301 ( V_29 , V_165 , V_203 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
if ( V_250 [ V_235 ] ) {
struct V_32 * V_237 ;
int V_267 ;
F_120 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_35 * V_37 ;
if ( ! ( V_37 = F_40 ( F_121 ( V_237 ) ) ) )
F_141 () ;
V_26 = V_37 -> V_269 ( V_29 , V_237 ) ;
if ( V_26 < 0 )
goto V_287;
V_285 = 1 ;
}
}
V_26 = 0 ;
V_287:
if ( V_26 < 0 && V_285 && F_142 () )
F_143 ( V_303 L_3
L_4
L_5
L_6 , V_29 -> V_179 ) ;
if ( V_286 )
F_144 ( V_304 , V_29 ) ;
return V_26 ;
}
static int F_145 ( struct V_39 * V_40 , struct V_66 * V_67 , void * V_305 )
{
struct V_27 * V_27 = F_106 ( V_40 -> V_241 ) ;
struct V_104 * V_105 ;
struct V_28 * V_29 ;
int V_26 ;
struct V_32 * V_250 [ V_251 + 1 ] ;
char V_284 [ V_153 ] ;
V_26 = F_108 ( V_67 , sizeof( * V_105 ) , V_250 , V_251 , V_254 ) ;
if ( V_26 < 0 )
goto V_287;
if ( V_250 [ V_178 ] )
F_146 ( V_284 , V_250 [ V_178 ] , V_153 ) ;
else
V_284 [ 0 ] = '\0' ;
V_26 = - V_266 ;
V_105 = F_94 ( V_67 ) ;
if ( V_105 -> V_176 > 0 )
V_29 = F_124 ( V_27 , V_105 -> V_176 ) ;
else if ( V_250 [ V_178 ] )
V_29 = F_147 ( V_27 , V_284 ) ;
else
goto V_287;
if ( V_29 == NULL ) {
V_26 = - V_292 ;
goto V_287;
}
V_26 = F_118 ( V_29 , V_250 ) ;
if ( V_26 < 0 )
goto V_287;
V_26 = F_126 ( V_29 , V_105 , V_250 , V_284 , 0 ) ;
V_287:
return V_26 ;
}
static int F_148 ( struct V_39 * V_40 , struct V_66 * V_67 , void * V_305 )
{
struct V_27 * V_27 = F_106 ( V_40 -> V_241 ) ;
const struct V_18 * V_20 ;
struct V_28 * V_29 ;
struct V_104 * V_105 ;
char V_284 [ V_153 ] ;
struct V_32 * V_250 [ V_251 + 1 ] ;
int V_26 ;
F_31 ( V_30 ) ;
V_26 = F_108 ( V_67 , sizeof( * V_105 ) , V_250 , V_251 , V_254 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_250 [ V_178 ] )
F_146 ( V_284 , V_250 [ V_178 ] , V_153 ) ;
V_105 = F_94 ( V_67 ) ;
if ( V_105 -> V_176 > 0 )
V_29 = F_124 ( V_27 , V_105 -> V_176 ) ;
else if ( V_250 [ V_178 ] )
V_29 = F_147 ( V_27 , V_284 ) ;
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
int F_149 ( struct V_28 * V_29 , const struct V_104 * V_105 )
{
unsigned int V_306 ;
int V_26 ;
V_306 = V_29 -> V_68 ;
if ( V_105 && ( V_105 -> V_106 || V_105 -> V_107 ) ) {
V_26 = F_150 ( V_29 , F_79 ( V_29 , V_105 ) ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_29 -> V_307 = V_308 ;
F_151 ( V_259 , V_29 , ~ 0U ) ;
F_152 ( V_29 , V_306 ) ;
return 0 ;
}
struct V_28 * F_153 ( struct V_27 * V_263 , struct V_27 * V_27 ,
char * V_284 , const struct V_18 * V_20 , struct V_32 * V_250 [] )
{
int V_26 ;
struct V_28 * V_29 ;
unsigned int V_309 = 1 ;
unsigned int V_310 = 1 ;
if ( V_20 -> V_311 ) {
V_26 = V_20 -> V_311 ( V_263 , V_250 , & V_309 ,
& V_310 ) ;
if ( V_26 )
goto V_26;
}
V_26 = - V_297 ;
V_29 = F_154 ( V_20 -> V_312 , V_284 , V_20 -> V_313 , V_309 ) ;
if ( ! V_29 )
goto V_26;
F_155 ( V_29 , V_27 ) ;
V_29 -> V_18 = V_20 ;
V_29 -> V_307 = V_314 ;
if ( V_250 [ V_186 ] )
V_29 -> V_187 = F_109 ( V_250 [ V_186 ] ) ;
if ( V_250 [ V_207 ] )
memcpy ( V_29 -> V_208 , F_102 ( V_250 [ V_207 ] ) ,
F_119 ( V_250 [ V_207 ] ) ) ;
if ( V_250 [ V_209 ] )
memcpy ( V_29 -> V_210 , F_102 ( V_250 [ V_209 ] ) ,
F_119 ( V_250 [ V_209 ] ) ) ;
if ( V_250 [ V_180 ] )
V_29 -> V_181 = F_109 ( V_250 [ V_180 ] ) ;
if ( V_250 [ V_182 ] )
F_74 ( V_29 , F_139 ( V_250 [ V_182 ] ) ) ;
if ( V_250 [ V_184 ] )
V_29 -> V_185 = F_139 ( V_250 [ V_184 ] ) ;
if ( V_250 [ V_188 ] )
F_134 ( V_29 , F_109 ( V_250 [ V_188 ] ) ) ;
return V_29 ;
V_26:
return F_156 ( V_26 ) ;
}
static int F_157 ( struct V_27 * V_27 , int V_59 ,
struct V_104 * V_105 ,
struct V_32 * * V_250 )
{
struct V_28 * V_29 ;
int V_26 ;
F_32 (net, dev) {
if ( V_29 -> V_59 == V_59 ) {
V_26 = F_126 ( V_29 , V_105 , V_250 , NULL , 0 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
return 0 ;
}
static int F_158 ( struct V_39 * V_40 , struct V_66 * V_67 , void * V_305 )
{
struct V_27 * V_27 = F_106 ( V_40 -> V_241 ) ;
const struct V_18 * V_20 ;
struct V_28 * V_29 ;
struct V_104 * V_105 ;
char V_19 [ V_315 ] ;
char V_284 [ V_153 ] ;
struct V_32 * V_250 [ V_251 + 1 ] ;
struct V_32 * V_41 [ V_316 + 1 ] ;
int V_26 ;
#ifdef F_159
V_317:
#endif
V_26 = F_108 ( V_67 , sizeof( * V_105 ) , V_250 , V_251 , V_254 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_250 [ V_178 ] )
F_146 ( V_284 , V_250 [ V_178 ] , V_153 ) ;
else
V_284 [ 0 ] = '\0' ;
V_105 = F_94 ( V_67 ) ;
if ( V_105 -> V_176 > 0 )
V_29 = F_124 ( V_27 , V_105 -> V_176 ) ;
else {
if ( V_284 [ 0 ] )
V_29 = F_147 ( V_27 , V_284 ) ;
else
V_29 = NULL ;
}
V_26 = F_118 ( V_29 , V_250 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_250 [ V_44 ] ) {
V_26 = F_140 ( V_41 , V_316 ,
V_250 [ V_44 ] , V_318 ) ;
if ( V_26 < 0 )
return V_26 ;
} else
memset ( V_41 , 0 , sizeof( V_41 ) ) ;
if ( V_41 [ V_46 ] ) {
F_146 ( V_19 , V_41 [ V_46 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_32 * V_170 [ V_20 ? V_20 -> V_319 + 1 : 0 ] , * * V_42 = NULL ;
struct V_27 * V_320 ;
if ( V_20 ) {
if ( V_20 -> V_319 && V_41 [ V_50 ] ) {
V_26 = F_140 ( V_170 , V_20 -> V_319 ,
V_41 [ V_50 ] ,
V_20 -> V_321 ) ;
if ( V_26 < 0 )
return V_26 ;
V_42 = V_170 ;
}
if ( V_20 -> V_322 ) {
V_26 = V_20 -> V_322 ( V_250 , V_42 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
if ( V_29 ) {
int V_285 = 0 ;
if ( V_67 -> V_323 & V_324 )
return - V_21 ;
if ( V_67 -> V_323 & V_325 )
return - V_270 ;
if ( V_41 [ V_50 ] ) {
if ( ! V_20 || V_20 != V_29 -> V_18 ||
! V_20 -> V_326 )
return - V_270 ;
V_26 = V_20 -> V_326 ( V_29 , V_250 , V_42 ) ;
if ( V_26 < 0 )
return V_26 ;
V_285 = 1 ;
}
return F_126 ( V_29 , V_105 , V_250 , V_284 , V_285 ) ;
}
if ( ! ( V_67 -> V_323 & V_327 ) ) {
if ( V_105 -> V_176 == 0 && V_250 [ V_188 ] )
return F_157 ( V_27 ,
F_109 ( V_250 [ V_188 ] ) ,
V_105 , V_250 ) ;
return - V_292 ;
}
if ( V_105 -> V_176 )
return - V_270 ;
if ( V_250 [ V_205 ] || V_250 [ V_192 ] || V_250 [ V_328 ] )
return - V_270 ;
if ( ! V_20 ) {
#ifdef F_159
if ( V_19 [ 0 ] ) {
F_3 () ;
F_160 ( L_7 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_317;
}
#endif
return - V_270 ;
}
if ( ! V_284 [ 0 ] )
snprintf ( V_284 , V_153 , L_8 , V_20 -> V_19 ) ;
V_320 = F_114 ( V_27 , V_250 ) ;
if ( F_127 ( V_320 ) )
return F_128 ( V_320 ) ;
V_29 = F_153 ( V_27 , V_320 , V_284 , V_20 , V_250 ) ;
if ( F_127 ( V_29 ) )
V_26 = F_128 ( V_29 ) ;
else if ( V_20 -> V_329 )
V_26 = V_20 -> V_329 ( V_27 , V_29 , V_250 , V_42 ) ;
else
V_26 = F_161 ( V_29 ) ;
if ( V_26 < 0 && ! F_127 ( V_29 ) )
F_162 ( V_29 ) ;
if ( V_26 < 0 )
goto V_45;
V_26 = F_149 ( V_29 , V_105 ) ;
if ( V_26 < 0 )
F_163 ( V_29 ) ;
V_45:
F_130 ( V_320 ) ;
return V_26 ;
}
}
static int F_164 ( struct V_39 * V_40 , struct V_66 * V_67 , void * V_305 )
{
struct V_27 * V_27 = F_106 ( V_40 -> V_241 ) ;
struct V_104 * V_105 ;
char V_284 [ V_153 ] ;
struct V_32 * V_250 [ V_251 + 1 ] ;
struct V_28 * V_29 = NULL ;
struct V_39 * V_330 ;
int V_26 ;
T_5 V_136 = 0 ;
V_26 = F_108 ( V_67 , sizeof( * V_105 ) , V_250 , V_251 , V_254 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_250 [ V_178 ] )
F_146 ( V_284 , V_250 [ V_178 ] , V_153 ) ;
if ( V_250 [ V_255 ] )
V_136 = F_109 ( V_250 [ V_255 ] ) ;
V_105 = F_94 ( V_67 ) ;
if ( V_105 -> V_176 > 0 )
V_29 = F_124 ( V_27 , V_105 -> V_176 ) ;
else if ( V_250 [ V_178 ] )
V_29 = F_147 ( V_27 , V_284 ) ;
else
return - V_266 ;
if ( V_29 == NULL )
return - V_292 ;
V_330 = F_165 ( F_86 ( V_29 , V_136 ) , V_15 ) ;
if ( V_330 == NULL )
return - V_16 ;
V_26 = F_91 ( V_330 , V_29 , V_259 , F_57 ( V_40 ) . V_58 ,
V_67 -> V_260 , 0 , 0 , V_136 ) ;
if ( V_26 < 0 ) {
F_166 ( V_26 == - V_43 ) ;
F_167 ( V_330 ) ;
} else
V_26 = F_61 ( V_330 , V_27 , F_57 ( V_40 ) . V_58 ) ;
return V_26 ;
}
static T_8 F_168 ( struct V_39 * V_40 , struct V_66 * V_67 )
{
struct V_27 * V_27 = F_106 ( V_40 -> V_241 ) ;
struct V_28 * V_29 ;
struct V_32 * V_250 [ V_251 + 1 ] ;
T_5 V_136 = 0 ;
T_8 V_331 = 0 ;
if ( F_108 ( V_67 , sizeof( struct V_253 ) , V_250 , V_251 ,
V_254 ) >= 0 ) {
if ( V_250 [ V_255 ] )
V_136 = F_109 ( V_250 [ V_255 ] ) ;
}
if ( ! V_136 )
return V_332 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_331 = F_169 ( T_8 , V_331 ,
F_86 ( V_29 ,
V_136 ) ) ;
}
return V_331 ;
}
static int F_170 ( struct V_39 * V_40 , struct V_239 * V_240 )
{
int V_244 ;
int V_245 = V_240 -> V_36 ;
if ( V_245 == 0 )
V_245 = 1 ;
for ( V_244 = 1 ; V_244 <= V_9 ; V_244 ++ ) {
int type = V_240 -> V_67 -> V_333 - V_4 ;
if ( V_244 < V_245 || V_244 == V_334 )
continue;
if ( V_10 [ V_244 ] == NULL ||
V_10 [ V_244 ] [ type ] . V_13 == NULL )
continue;
if ( V_244 > V_245 )
memset ( & V_240 -> args [ 0 ] , 0 , sizeof( V_240 -> args ) ) ;
if ( V_10 [ V_244 ] [ type ] . V_13 ( V_40 , V_240 ) )
break;
}
V_240 -> V_36 = V_244 ;
return V_40 -> V_262 ;
}
void F_151 ( int type , struct V_28 * V_29 , unsigned V_167 )
{
struct V_27 * V_27 = F_125 ( V_29 ) ;
struct V_39 * V_40 ;
int V_26 = - V_16 ;
T_4 V_335 ;
V_40 = F_165 ( ( V_335 = F_86 ( V_29 , 0 ) ) , V_15 ) ;
if ( V_40 == NULL )
goto V_287;
V_26 = F_91 ( V_40 , V_29 , type , 0 , 0 , V_167 , 0 , 0 ) ;
if ( V_26 < 0 ) {
F_166 ( V_26 == - V_43 ) ;
F_167 ( V_40 ) ;
goto V_287;
}
F_63 ( V_40 , V_27 , 0 , V_336 , NULL , V_15 ) ;
return;
V_287:
if ( V_26 < 0 )
F_66 ( V_27 , V_336 , V_26 ) ;
}
static int F_171 ( struct V_39 * V_40 , struct V_66 * V_67 )
{
struct V_27 * V_27 = F_106 ( V_40 -> V_241 ) ;
T_1 V_11 ;
int V_337 , V_19 ;
int V_338 ;
int V_36 ;
int type ;
int V_26 ;
type = V_67 -> V_333 ;
if ( type > V_339 )
return - V_270 ;
type -= V_4 ;
if ( V_67 -> V_340 < F_172 ( sizeof( struct V_253 ) ) )
return 0 ;
V_36 = ( (struct V_253 * ) F_173 ( V_67 ) ) -> V_341 ;
V_337 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_174 ( V_342 ) )
return - V_343 ;
if ( V_19 == 2 && V_67 -> V_323 & V_344 ) {
struct V_61 * V_62 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_345 = 0 ;
V_13 = F_16 ( V_36 , type ) ;
if ( V_13 == NULL )
return - V_270 ;
V_14 = F_17 ( V_36 , type ) ;
if ( V_14 )
V_345 = V_14 ( V_40 , V_67 ) ;
F_3 () ;
V_62 = V_27 -> V_62 ;
V_26 = F_175 ( V_62 , V_40 , V_67 , V_13 ,
NULL , V_345 ) ;
F_1 () ;
return V_26 ;
}
memset ( V_346 , 0 , ( V_347 * sizeof( struct V_54 * ) ) ) ;
V_338 = V_348 [ V_337 ] ;
if ( V_67 -> V_340 < V_338 )
return - V_266 ;
if ( V_67 -> V_340 > V_338 ) {
int V_53 = V_67 -> V_340 - F_87 ( V_338 ) ;
struct V_54 * V_170 = ( void * ) V_67 + F_87 ( V_338 ) ;
while ( F_176 ( V_170 , V_53 ) ) {
unsigned V_349 = V_170 -> V_56 ;
if ( V_349 ) {
if ( V_349 > V_350 [ V_337 ] )
return - V_266 ;
V_346 [ V_349 - 1 ] = V_170 ;
}
V_170 = F_177 ( V_170 , V_53 ) ;
}
}
V_11 = F_15 ( V_36 , type ) ;
if ( V_11 == NULL )
return - V_270 ;
return V_11 ( V_40 , V_67 , ( void * ) & V_346 [ 0 ] ) ;
}
static void F_178 ( struct V_39 * V_40 )
{
F_1 () ;
F_179 ( V_40 , & F_171 ) ;
F_5 () ;
}
static int F_180 ( struct V_351 * V_352 , unsigned long V_353 , void * V_354 )
{
struct V_28 * V_29 = V_354 ;
switch ( V_353 ) {
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
break;
default:
F_151 ( V_259 , V_29 , 0 ) ;
break;
}
return V_367 ;
}
static int T_9 F_181 ( struct V_27 * V_27 )
{
struct V_61 * V_241 ;
V_241 = F_182 ( V_27 , V_368 , V_369 ,
F_178 , & V_1 , V_370 ) ;
if ( ! V_241 )
return - V_297 ;
V_27 -> V_62 = V_241 ;
return 0 ;
}
static void T_10 F_183 ( struct V_27 * V_27 )
{
F_184 ( V_27 -> V_62 ) ;
V_27 -> V_62 = NULL ;
}
void T_11 F_185 ( void )
{
int V_72 ;
V_347 = 0 ;
for ( V_72 = 0 ; V_72 < F_186 ( V_350 ) ; V_72 ++ )
if ( V_350 [ V_72 ] > V_347 )
V_347 = V_350 [ V_72 ] ;
V_346 = F_132 ( V_347 * sizeof( struct V_54 * ) , V_15 ) ;
if ( ! V_346 )
F_21 ( L_9 ) ;
if ( F_187 ( & V_371 ) )
F_21 ( L_10 ) ;
F_188 ( V_368 , V_372 ) ;
F_189 ( & V_373 ) ;
F_20 ( V_12 , V_374 , F_164 ,
F_105 , F_168 ) ;
F_20 ( V_12 , V_375 , F_145 , NULL , NULL ) ;
F_20 ( V_12 , V_259 , F_158 , NULL , NULL ) ;
F_20 ( V_12 , V_376 , F_148 , NULL , NULL ) ;
F_20 ( V_12 , V_377 , NULL , F_170 , NULL ) ;
F_20 ( V_12 , V_378 , NULL , F_170 , NULL ) ;
}
