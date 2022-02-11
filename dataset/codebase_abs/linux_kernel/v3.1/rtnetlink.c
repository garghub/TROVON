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
int F_25 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_20 )
V_19 -> V_20 = V_21 ;
F_26 ( & V_19 -> V_22 , & V_23 ) ;
return 0 ;
}
int F_27 ( struct V_18 * V_19 )
{
int V_24 ;
F_1 () ;
V_24 = F_25 ( V_19 ) ;
F_5 () ;
return V_24 ;
}
static void F_28 ( struct V_25 * V_25 , struct V_18 * V_19 )
{
struct V_26 * V_27 ;
F_29 ( V_28 ) ;
F_30 (net, dev) {
if ( V_27 -> V_18 == V_19 )
V_19 -> V_20 ( V_27 , & V_28 ) ;
}
F_31 ( & V_28 ) ;
}
void F_32 ( struct V_18 * V_19 )
{
struct V_25 * V_25 ;
F_33 (net) {
F_28 ( V_25 , V_19 ) ;
}
F_34 ( & V_19 -> V_22 ) ;
}
void F_35 ( struct V_18 * V_19 )
{
F_1 () ;
F_32 ( V_19 ) ;
F_5 () ;
}
static const struct V_18 * F_36 ( const char * V_29 )
{
const struct V_18 * V_19 ;
F_37 (ops, &link_ops, list) {
if ( ! strcmp ( V_19 -> V_29 , V_29 ) )
return V_19 ;
}
return NULL ;
}
static T_4 F_38 ( const struct V_26 * V_27 )
{
const struct V_18 * V_19 = V_27 -> V_18 ;
T_4 V_30 ;
if ( ! V_19 )
return 0 ;
V_30 = F_39 ( sizeof( struct V_31 ) ) +
F_39 ( strlen ( V_19 -> V_29 ) + 1 ) ;
if ( V_19 -> V_32 )
V_30 += F_39 ( sizeof( struct V_31 ) ) +
V_19 -> V_32 ( V_27 ) ;
if ( V_19 -> V_33 )
V_30 += F_39 ( V_19 -> V_33 ( V_27 ) ) ;
return V_30 ;
}
static const struct V_34 * F_40 ( const int V_35 )
{
const struct V_34 * V_19 ;
F_37 (ops, &rtnl_af_ops, list) {
if ( V_19 -> V_35 == V_35 )
return V_19 ;
}
return NULL ;
}
int F_41 ( struct V_34 * V_19 )
{
F_26 ( & V_19 -> V_22 , & V_34 ) ;
return 0 ;
}
int F_42 ( struct V_34 * V_19 )
{
int V_24 ;
F_1 () ;
V_24 = F_41 ( V_19 ) ;
F_5 () ;
return V_24 ;
}
void F_43 ( struct V_34 * V_19 )
{
F_34 ( & V_19 -> V_22 ) ;
}
void F_44 ( struct V_34 * V_19 )
{
F_1 () ;
F_43 ( V_19 ) ;
F_5 () ;
}
static T_4 F_45 ( const struct V_26 * V_27 )
{
struct V_34 * V_36 ;
T_4 V_30 ;
V_30 = F_39 ( sizeof( struct V_31 ) ) ;
F_37 (af_ops, &rtnl_af_ops, list) {
if ( V_36 -> V_37 ) {
V_30 += F_39 ( sizeof( struct V_31 ) ) +
V_36 -> V_37 ( V_27 ) ;
}
}
return V_30 ;
}
static int F_46 ( struct V_38 * V_39 , const struct V_26 * V_27 )
{
const struct V_18 * V_19 = V_27 -> V_18 ;
struct V_31 * V_40 , * V_41 ;
int V_24 = - V_42 ;
V_40 = F_47 ( V_39 , V_43 ) ;
if ( V_40 == NULL )
goto V_44;
if ( F_48 ( V_39 , V_45 , V_19 -> V_29 ) < 0 )
goto V_46;
if ( V_19 -> V_47 ) {
V_24 = V_19 -> V_47 ( V_39 , V_27 ) ;
if ( V_24 < 0 )
goto V_46;
}
if ( V_19 -> V_48 ) {
V_41 = F_47 ( V_39 , V_49 ) ;
if ( V_41 == NULL )
goto V_46;
V_24 = V_19 -> V_48 ( V_39 , V_27 ) ;
if ( V_24 < 0 )
goto V_50;
F_49 ( V_39 , V_41 ) ;
}
F_49 ( V_39 , V_40 ) ;
return 0 ;
V_50:
F_50 ( V_39 , V_41 ) ;
V_46:
F_50 ( V_39 , V_40 ) ;
V_44:
return V_24 ;
}
void F_51 ( struct V_38 * V_39 , int V_51 , int V_52 , const void * V_41 )
{
struct V_53 * V_54 ;
int V_30 = F_52 ( V_52 ) ;
V_54 = (struct V_53 * ) F_53 ( V_39 , F_54 ( V_30 ) ) ;
V_54 -> V_55 = V_51 ;
V_54 -> V_56 = V_30 ;
memcpy ( F_55 ( V_54 ) , V_41 , V_52 ) ;
memset ( F_55 ( V_54 ) + V_52 , 0 , F_54 ( V_30 ) - V_30 ) ;
}
int F_56 ( struct V_38 * V_39 , struct V_25 * V_25 , T_5 V_57 , unsigned V_58 , int V_59 )
{
struct V_60 * V_61 = V_25 -> V_61 ;
int V_24 = 0 ;
F_57 ( V_39 ) . V_62 = V_58 ;
if ( V_59 )
F_58 ( & V_39 -> V_63 ) ;
F_59 ( V_61 , V_39 , V_57 , V_58 , V_15 ) ;
if ( V_59 )
V_24 = F_60 ( V_61 , V_39 , V_57 , V_64 ) ;
return V_24 ;
}
int F_61 ( struct V_38 * V_39 , struct V_25 * V_25 , T_5 V_57 )
{
struct V_60 * V_61 = V_25 -> V_61 ;
return F_62 ( V_61 , V_39 , V_57 ) ;
}
void F_63 ( struct V_38 * V_39 , struct V_25 * V_25 , T_5 V_57 , T_5 V_58 ,
struct V_65 * V_66 , T_6 V_67 )
{
struct V_60 * V_61 = V_25 -> V_61 ;
int V_68 = 0 ;
if ( V_66 )
V_68 = F_64 ( V_66 ) ;
F_65 ( V_61 , V_39 , V_57 , V_58 , V_68 , V_67 ) ;
}
void F_66 ( struct V_25 * V_25 , T_5 V_58 , int error )
{
struct V_60 * V_61 = V_25 -> V_61 ;
F_67 ( V_61 , 0 , V_58 , error ) ;
}
int F_68 ( struct V_38 * V_39 , T_5 * V_69 )
{
struct V_31 * V_70 ;
int V_71 , V_72 = 0 ;
V_70 = F_47 ( V_39 , V_73 ) ;
if ( V_70 == NULL )
return - V_16 ;
for ( V_71 = 0 ; V_71 < V_74 ; V_71 ++ ) {
if ( V_69 [ V_71 ] ) {
V_72 ++ ;
F_69 ( V_39 , V_71 + 1 , V_69 [ V_71 ] ) ;
}
}
if ( ! V_72 ) {
F_50 ( V_39 , V_70 ) ;
return 0 ;
}
return F_49 ( V_39 , V_70 ) ;
V_75:
F_50 ( V_39 , V_70 ) ;
return - V_42 ;
}
int F_70 ( struct V_38 * V_39 , struct V_76 * V_77 , T_5 V_78 ,
T_5 V_79 , T_5 V_80 , long V_81 , T_5 error )
{
struct V_82 V_83 = {
. V_84 = F_71 ( V_85 - V_77 -> V_86 ) ,
. V_87 = V_77 -> V_88 ,
. V_89 = F_72 ( & ( V_77 -> V_90 ) ) ,
. V_91 = error ,
. V_92 = V_78 ,
. V_93 = V_79 ,
. V_94 = V_80 ,
} ;
if ( V_81 )
V_83 . V_95 = F_71 ( V_81 ) ;
return F_73 ( V_39 , V_96 , sizeof( V_83 ) , & V_83 ) ;
}
static void F_74 ( struct V_26 * V_27 , unsigned char V_97 )
{
unsigned char V_98 = V_27 -> V_98 ;
switch ( V_97 ) {
case V_99 :
if ( ( V_98 == V_100 ||
V_98 == V_101 ) &&
! F_75 ( V_27 ) )
V_98 = V_99 ;
break;
case V_100 :
if ( V_98 == V_99 ||
V_98 == V_101 )
V_98 = V_100 ;
break;
}
if ( V_27 -> V_98 != V_98 ) {
F_76 ( & V_102 ) ;
V_27 -> V_98 = V_98 ;
F_77 ( & V_102 ) ;
F_78 ( V_27 ) ;
}
}
static unsigned int F_79 ( const struct V_26 * V_27 ,
const struct V_103 * V_104 )
{
unsigned int V_67 = V_104 -> V_105 ;
if ( V_104 -> V_106 )
V_67 = ( V_67 & V_104 -> V_106 ) |
( V_27 -> V_67 & ~ V_104 -> V_106 ) ;
return V_67 ;
}
static void F_80 ( struct V_107 * V_108 ,
const struct V_109 * V_110 )
{
V_108 -> V_111 = V_110 -> V_111 ;
V_108 -> V_112 = V_110 -> V_112 ;
V_108 -> V_113 = V_110 -> V_113 ;
V_108 -> V_114 = V_110 -> V_114 ;
V_108 -> V_115 = V_110 -> V_115 ;
V_108 -> V_116 = V_110 -> V_116 ;
V_108 -> V_117 = V_110 -> V_117 ;
V_108 -> V_118 = V_110 -> V_118 ;
V_108 -> V_119 = V_110 -> V_119 ;
V_108 -> V_120 = V_110 -> V_120 ;
V_108 -> V_121 = V_110 -> V_121 ;
V_108 -> V_122 = V_110 -> V_122 ;
V_108 -> V_123 = V_110 -> V_123 ;
V_108 -> V_124 = V_110 -> V_124 ;
V_108 -> V_125 = V_110 -> V_125 ;
V_108 -> V_126 = V_110 -> V_126 ;
V_108 -> V_127 = V_110 -> V_127 ;
V_108 -> V_128 = V_110 -> V_128 ;
V_108 -> V_129 = V_110 -> V_129 ;
V_108 -> V_130 = V_110 -> V_130 ;
V_108 -> V_131 = V_110 -> V_131 ;
V_108 -> V_132 = V_110 -> V_132 ;
V_108 -> V_133 = V_110 -> V_133 ;
}
static void F_81 ( void * V_134 , const struct V_109 * V_110 )
{
memcpy ( V_134 , V_110 , sizeof( * V_110 ) ) ;
}
static inline int F_82 ( const struct V_26 * V_27 )
{
if ( V_27 -> V_27 . V_135 && F_83 ( V_27 -> V_27 . V_135 ) ) {
int V_136 = F_84 ( V_27 -> V_27 . V_135 ) ;
T_4 V_30 = F_39 ( sizeof( struct V_31 ) ) ;
V_30 += F_39 ( V_136 * sizeof( struct V_31 ) ) ;
V_30 += V_136 *
( F_39 ( sizeof( struct V_137 ) ) +
F_39 ( sizeof( struct V_138 ) ) +
F_39 ( sizeof( struct V_139 ) ) ) ;
return V_30 ;
} else
return 0 ;
}
static T_4 F_85 ( const struct V_26 * V_27 )
{
T_4 V_140 = F_39 ( 4 )
+ F_39 ( V_141 )
+ F_39 ( sizeof( struct V_142 ) )
+ F_39 ( V_143 )
+ F_39 ( V_143 )
+ F_39 ( 1 )
+ F_39 ( 2 ) ;
T_4 V_144 = F_39 ( sizeof( struct V_31 ) ) ;
T_4 V_145 = F_39 ( sizeof( struct V_31 ) )
+ V_140 ;
T_4 V_146 = F_39 ( sizeof( struct V_31 ) )
+ V_140 ;
if ( ! V_27 -> V_147 -> V_148 || ! V_27 -> V_27 . V_135 )
return 0 ;
if ( F_84 ( V_27 -> V_27 . V_135 ) )
return V_146 + V_144 +
V_145 * F_84 ( V_27 -> V_27 . V_135 ) ;
else
return V_146 ;
}
static T_7 T_4 F_86 ( const struct V_26 * V_27 )
{
return F_87 ( sizeof( struct V_103 ) )
+ F_39 ( V_149 )
+ F_39 ( V_150 )
+ F_39 ( V_149 )
+ F_39 ( sizeof( struct V_151 ) )
+ F_39 ( sizeof( struct V_107 ) )
+ F_39 ( sizeof( struct V_109 ) )
+ F_39 ( V_152 )
+ F_39 ( V_152 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 1 )
+ F_39 ( 1 )
+ F_39 ( 4 )
+ F_82 ( V_27 )
+ F_85 ( V_27 )
+ F_38 ( V_27 )
+ F_45 ( V_27 ) ;
}
static int F_88 ( struct V_38 * V_39 , struct V_26 * V_27 )
{
struct V_31 * V_153 ;
struct V_31 * V_154 ;
int V_155 ;
int V_24 ;
V_153 = F_47 ( V_39 , V_156 ) ;
if ( ! V_153 )
return - V_42 ;
for ( V_155 = 0 ; V_155 < F_84 ( V_27 -> V_27 . V_135 ) ; V_155 ++ ) {
V_154 = F_47 ( V_39 , V_157 ) ;
if ( ! V_154 )
goto V_75;
F_69 ( V_39 , V_158 , V_155 ) ;
V_24 = V_27 -> V_147 -> V_148 ( V_27 , V_155 , V_39 ) ;
if ( V_24 == - V_42 )
goto V_75;
if ( V_24 ) {
F_50 ( V_39 , V_154 ) ;
continue;
}
F_49 ( V_39 , V_154 ) ;
}
F_49 ( V_39 , V_153 ) ;
return 0 ;
V_75:
F_50 ( V_39 , V_153 ) ;
return - V_42 ;
}
static int F_89 ( struct V_38 * V_39 , struct V_26 * V_27 )
{
struct V_31 * V_159 ;
int V_24 ;
V_159 = F_47 ( V_39 , V_160 ) ;
if ( ! V_159 )
return - V_42 ;
V_24 = V_27 -> V_147 -> V_148 ( V_27 , V_161 , V_39 ) ;
if ( V_24 ) {
F_50 ( V_39 , V_159 ) ;
return ( V_24 == - V_42 ) ? V_24 : 0 ;
}
F_49 ( V_39 , V_159 ) ;
return 0 ;
}
static int F_90 ( struct V_38 * V_39 , struct V_26 * V_27 )
{
int V_24 ;
if ( ! V_27 -> V_147 -> V_148 || ! V_27 -> V_27 . V_135 )
return 0 ;
V_24 = F_89 ( V_39 , V_27 ) ;
if ( V_24 )
return V_24 ;
if ( F_84 ( V_27 -> V_27 . V_135 ) ) {
V_24 = F_88 ( V_39 , V_27 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int F_91 ( struct V_38 * V_39 , struct V_26 * V_27 ,
int type , T_5 V_57 , T_5 V_162 , T_5 V_163 ,
unsigned int V_67 )
{
struct V_103 * V_104 ;
struct V_65 * V_66 ;
struct V_109 V_164 ;
const struct V_109 * V_165 ;
struct V_31 * V_166 , * V_167 ;
struct V_34 * V_36 ;
F_92 () ;
V_66 = F_93 ( V_39 , V_57 , V_162 , type , sizeof( * V_104 ) , V_67 ) ;
if ( V_66 == NULL )
return - V_42 ;
V_104 = F_94 ( V_66 ) ;
V_104 -> V_168 = V_169 ;
V_104 -> V_170 = 0 ;
V_104 -> V_171 = V_27 -> type ;
V_104 -> V_172 = V_27 -> V_173 ;
V_104 -> V_105 = F_95 ( V_27 ) ;
V_104 -> V_106 = V_163 ;
F_96 ( V_39 , V_174 , V_27 -> V_175 ) ;
F_69 ( V_39 , V_176 , V_27 -> V_177 ) ;
F_97 ( V_39 , V_178 ,
F_98 ( V_27 ) ? V_27 -> V_98 : V_179 ) ;
F_97 ( V_39 , V_180 , V_27 -> V_181 ) ;
F_69 ( V_39 , V_182 , V_27 -> V_183 ) ;
F_69 ( V_39 , V_184 , V_27 -> V_58 ) ;
if ( V_27 -> V_173 != V_27 -> V_185 )
F_69 ( V_39 , V_186 , V_27 -> V_185 ) ;
if ( V_27 -> V_187 )
F_69 ( V_39 , V_188 , V_27 -> V_187 -> V_173 ) ;
if ( V_27 -> V_189 )
F_96 ( V_39 , V_190 , V_27 -> V_189 -> V_19 -> V_78 ) ;
if ( V_27 -> V_191 )
F_96 ( V_39 , V_192 , V_27 -> V_191 ) ;
if ( 1 ) {
struct V_151 V_193 = {
. V_194 = V_27 -> V_194 ,
. V_195 = V_27 -> V_195 ,
. V_196 = V_27 -> V_196 ,
. V_197 = V_27 -> V_197 ,
. V_198 = V_27 -> V_198 ,
. V_199 = V_27 -> V_200 ,
} ;
F_99 ( V_39 , V_201 , sizeof( V_193 ) , & V_193 ) ;
}
if ( V_27 -> V_202 ) {
F_99 ( V_39 , V_203 , V_27 -> V_202 , V_27 -> V_204 ) ;
F_99 ( V_39 , V_205 , V_27 -> V_202 , V_27 -> V_206 ) ;
}
V_166 = F_100 ( V_39 , V_207 ,
sizeof( struct V_107 ) ) ;
if ( V_166 == NULL )
goto V_75;
V_165 = F_101 ( V_27 , & V_164 ) ;
F_80 ( F_102 ( V_166 ) , V_165 ) ;
V_166 = F_100 ( V_39 , V_208 ,
sizeof( struct V_109 ) ) ;
if ( V_166 == NULL )
goto V_75;
F_81 ( F_102 ( V_166 ) , V_165 ) ;
if ( V_27 -> V_27 . V_135 )
F_69 ( V_39 , V_209 , F_84 ( V_27 -> V_27 . V_135 ) ) ;
if ( V_27 -> V_147 -> V_210 && V_27 -> V_27 . V_135 ) {
int V_71 ;
struct V_31 * V_211 , * V_155 ;
int V_136 = F_84 ( V_27 -> V_27 . V_135 ) ;
V_211 = F_47 ( V_39 , V_212 ) ;
if ( ! V_211 )
goto V_75;
for ( V_71 = 0 ; V_71 < V_136 ; V_71 ++ ) {
struct V_213 V_214 ;
struct V_137 V_215 ;
struct V_138 V_216 ;
struct V_139 V_217 ;
if ( V_27 -> V_147 -> V_210 ( V_27 , V_71 , & V_214 ) )
break;
V_215 . V_155 = V_216 . V_155 = V_217 . V_155 = V_214 . V_155 ;
memcpy ( V_215 . V_218 , V_214 . V_218 , sizeof( V_214 . V_218 ) ) ;
V_216 . V_219 = V_214 . V_219 ;
V_216 . V_220 = V_214 . V_220 ;
V_217 . V_221 = V_214 . V_222 ;
V_155 = F_47 ( V_39 , V_223 ) ;
if ( ! V_155 ) {
F_50 ( V_39 , V_211 ) ;
goto V_75;
}
F_99 ( V_39 , V_224 , sizeof( V_215 ) , & V_215 ) ;
F_99 ( V_39 , V_225 , sizeof( V_216 ) , & V_216 ) ;
F_99 ( V_39 , V_226 , sizeof( V_217 ) , & V_217 ) ;
F_49 ( V_39 , V_155 ) ;
}
F_49 ( V_39 , V_211 ) ;
}
if ( F_90 ( V_39 , V_27 ) )
goto V_75;
if ( V_27 -> V_18 ) {
if ( F_46 ( V_39 , V_27 ) < 0 )
goto V_75;
}
if ( ! ( V_167 = F_47 ( V_39 , V_227 ) ) )
goto V_75;
F_37 (af_ops, &rtnl_af_ops, list) {
if ( V_36 -> V_228 ) {
struct V_31 * V_229 ;
int V_24 ;
if ( ! ( V_229 = F_47 ( V_39 , V_36 -> V_35 ) ) )
goto V_75;
V_24 = V_36 -> V_228 ( V_39 , V_27 ) ;
if ( V_24 == - V_230 )
F_50 ( V_39 , V_229 ) ;
else if ( V_24 < 0 )
goto V_75;
F_49 ( V_39 , V_229 ) ;
}
}
F_49 ( V_39 , V_167 ) ;
return F_103 ( V_39 , V_66 ) ;
V_75:
F_104 ( V_39 , V_66 ) ;
return - V_42 ;
}
static int F_105 ( struct V_38 * V_39 , struct V_231 * V_232 )
{
struct V_25 * V_25 = F_106 ( V_39 -> V_233 ) ;
int V_234 , V_235 ;
int V_236 = 0 , V_237 ;
struct V_26 * V_27 ;
struct V_238 * V_239 ;
struct V_240 * V_241 ;
V_235 = V_232 -> args [ 0 ] ;
V_237 = V_232 -> args [ 1 ] ;
F_107 () ;
V_232 -> V_162 = V_25 -> V_242 ;
for ( V_234 = V_235 ; V_234 < V_243 ; V_234 ++ , V_237 = 0 ) {
V_236 = 0 ;
V_239 = & V_25 -> V_244 [ V_234 ] ;
F_108 (dev, node, head, index_hlist) {
if ( V_236 < V_237 )
goto V_245;
if ( F_91 ( V_39 , V_27 , V_246 ,
F_57 ( V_232 -> V_39 ) . V_57 ,
V_232 -> V_66 -> V_247 , 0 ,
V_248 ) <= 0 )
goto V_44;
F_109 ( V_232 , F_110 ( V_39 ) ) ;
V_245:
V_236 ++ ;
}
}
V_44:
F_111 () ;
V_232 -> args [ 1 ] = V_236 ;
V_232 -> args [ 0 ] = V_234 ;
return V_39 -> V_249 ;
}
struct V_25 * F_112 ( struct V_25 * V_250 , struct V_31 * V_251 [] )
{
struct V_25 * V_25 ;
if ( V_251 [ V_252 ] )
V_25 = F_113 ( F_114 ( V_251 [ V_252 ] ) ) ;
else if ( V_251 [ V_253 ] )
V_25 = F_115 ( F_114 ( V_251 [ V_253 ] ) ) ;
else
V_25 = F_116 ( V_250 ) ;
return V_25 ;
}
static int F_117 ( struct V_26 * V_27 , struct V_31 * V_251 [] )
{
if ( V_27 ) {
if ( V_251 [ V_203 ] &&
F_118 ( V_251 [ V_203 ] ) < V_27 -> V_202 )
return - V_254 ;
if ( V_251 [ V_205 ] &&
F_118 ( V_251 [ V_205 ] ) < V_27 -> V_202 )
return - V_254 ;
}
if ( V_251 [ V_227 ] ) {
struct V_31 * V_229 ;
int V_255 , V_24 ;
F_119 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_34 * V_36 ;
if ( ! ( V_36 = F_40 ( F_120 ( V_229 ) ) ) )
return - V_256 ;
if ( ! V_36 -> V_257 )
return - V_258 ;
if ( V_36 -> V_259 ) {
V_24 = V_36 -> V_259 ( V_27 , V_229 ) ;
if ( V_24 < 0 )
return V_24 ;
}
}
}
return 0 ;
}
static int F_121 ( struct V_26 * V_27 , struct V_31 * V_166 )
{
int V_255 , V_24 = - V_254 ;
struct V_31 * V_155 ;
const struct V_260 * V_19 = V_27 -> V_147 ;
F_119 (vf, attr, rem) {
switch ( F_120 ( V_155 ) ) {
case V_224 : {
struct V_137 * V_261 ;
V_261 = F_102 ( V_155 ) ;
V_24 = - V_258 ;
if ( V_19 -> V_262 )
V_24 = V_19 -> V_262 ( V_27 , V_261 -> V_155 ,
V_261 -> V_218 ) ;
break;
}
case V_225 : {
struct V_138 * V_263 ;
V_263 = F_102 ( V_155 ) ;
V_24 = - V_258 ;
if ( V_19 -> V_264 )
V_24 = V_19 -> V_264 ( V_27 , V_263 -> V_155 ,
V_263 -> V_219 ,
V_263 -> V_220 ) ;
break;
}
case V_226 : {
struct V_139 * V_265 ;
V_265 = F_102 ( V_155 ) ;
V_24 = - V_258 ;
if ( V_19 -> V_266 )
V_24 = V_19 -> V_266 ( V_27 , V_265 -> V_155 ,
V_265 -> V_221 ) ;
break;
}
default:
V_24 = - V_254 ;
break;
}
if ( V_24 )
break;
}
return V_24 ;
}
static int F_122 ( struct V_26 * V_27 , int V_173 )
{
struct V_26 * V_267 ;
const struct V_260 * V_19 ;
int V_24 ;
if ( V_27 -> V_187 ) {
if ( V_27 -> V_187 -> V_173 == V_173 )
return 0 ;
V_19 = V_27 -> V_187 -> V_147 ;
if ( V_19 -> V_268 ) {
V_24 = V_19 -> V_268 ( V_27 -> V_187 , V_27 ) ;
if ( V_24 )
return V_24 ;
} else {
return - V_258 ;
}
}
if ( V_173 ) {
V_267 = F_123 ( F_124 ( V_27 ) , V_173 ) ;
if ( ! V_267 )
return - V_254 ;
V_19 = V_267 -> V_147 ;
if ( V_19 -> V_269 ) {
V_24 = V_19 -> V_269 ( V_267 , V_27 ) ;
if ( V_24 )
return V_24 ;
} else {
return - V_258 ;
}
}
return 0 ;
}
static int F_125 ( struct V_26 * V_27 , struct V_103 * V_104 ,
struct V_31 * * V_251 , char * V_270 , int V_271 )
{
const struct V_260 * V_19 = V_27 -> V_147 ;
int V_272 = 0 ;
int V_24 ;
if ( V_251 [ V_252 ] || V_251 [ V_253 ] ) {
struct V_25 * V_25 = F_112 ( F_124 ( V_27 ) , V_251 ) ;
if ( F_126 ( V_25 ) ) {
V_24 = F_127 ( V_25 ) ;
goto V_273;
}
V_24 = F_128 ( V_27 , V_25 , V_270 ) ;
F_129 ( V_25 ) ;
if ( V_24 )
goto V_273;
V_271 = 1 ;
}
if ( V_251 [ V_201 ] ) {
struct V_151 * V_274 ;
struct V_275 V_276 ;
if ( ! V_19 -> V_277 ) {
V_24 = - V_258 ;
goto V_273;
}
if ( ! F_130 ( V_27 ) ) {
V_24 = - V_278 ;
goto V_273;
}
V_274 = F_102 ( V_251 [ V_201 ] ) ;
V_276 . V_194 = ( unsigned long ) V_274 -> V_194 ;
V_276 . V_195 = ( unsigned long ) V_274 -> V_195 ;
V_276 . V_196 = ( unsigned short ) V_274 -> V_196 ;
V_276 . V_197 = ( unsigned char ) V_274 -> V_197 ;
V_276 . V_198 = ( unsigned char ) V_274 -> V_198 ;
V_276 . V_199 = ( unsigned char ) V_274 -> V_199 ;
V_24 = V_19 -> V_277 ( V_27 , & V_276 ) ;
if ( V_24 < 0 )
goto V_273;
V_271 = 1 ;
}
if ( V_251 [ V_203 ] ) {
struct V_279 * V_280 ;
int V_249 ;
if ( ! V_19 -> V_281 ) {
V_24 = - V_258 ;
goto V_273;
}
if ( ! F_130 ( V_27 ) ) {
V_24 = - V_278 ;
goto V_273;
}
V_249 = sizeof( V_282 ) + V_27 -> V_202 ;
V_280 = F_131 ( V_249 , V_15 ) ;
if ( ! V_280 ) {
V_24 = - V_283 ;
goto V_273;
}
V_280 -> V_284 = V_27 -> type ;
memcpy ( V_280 -> V_285 , F_102 ( V_251 [ V_203 ] ) ,
V_27 -> V_202 ) ;
V_24 = V_19 -> V_281 ( V_27 , V_280 ) ;
F_24 ( V_280 ) ;
if ( V_24 )
goto V_273;
V_272 = 1 ;
V_271 = 1 ;
}
if ( V_251 [ V_182 ] ) {
V_24 = F_132 ( V_27 , F_114 ( V_251 [ V_182 ] ) ) ;
if ( V_24 < 0 )
goto V_273;
V_271 = 1 ;
}
if ( V_251 [ V_184 ] ) {
F_133 ( V_27 , F_114 ( V_251 [ V_184 ] ) ) ;
V_271 = 1 ;
}
if ( V_104 -> V_172 > 0 && V_270 [ 0 ] ) {
V_24 = F_134 ( V_27 , V_270 ) ;
if ( V_24 < 0 )
goto V_273;
V_271 = 1 ;
}
if ( V_251 [ V_192 ] ) {
V_24 = F_135 ( V_27 , F_102 ( V_251 [ V_192 ] ) ,
F_118 ( V_251 [ V_192 ] ) ) ;
if ( V_24 < 0 )
goto V_273;
V_271 = 1 ;
}
if ( V_251 [ V_205 ] ) {
F_136 ( V_27 -> V_206 , V_251 [ V_205 ] , V_27 -> V_202 ) ;
V_272 = 1 ;
}
if ( V_104 -> V_105 || V_104 -> V_106 ) {
V_24 = F_137 ( V_27 , F_79 ( V_27 , V_104 ) ) ;
if ( V_24 < 0 )
goto V_273;
}
if ( V_251 [ V_188 ] ) {
V_24 = F_122 ( V_27 , F_114 ( V_251 [ V_188 ] ) ) ;
if ( V_24 )
goto V_273;
V_271 = 1 ;
}
if ( V_251 [ V_176 ] )
V_27 -> V_177 = F_114 ( V_251 [ V_176 ] ) ;
if ( V_251 [ V_178 ] )
F_74 ( V_27 , F_138 ( V_251 [ V_178 ] ) ) ;
if ( V_251 [ V_180 ] ) {
F_76 ( & V_102 ) ;
V_27 -> V_181 = F_138 ( V_251 [ V_180 ] ) ;
F_77 ( & V_102 ) ;
}
if ( V_251 [ V_212 ] ) {
struct V_31 * V_166 ;
int V_255 ;
F_119 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_120 ( V_166 ) != V_223 ) {
V_24 = - V_254 ;
goto V_273;
}
V_24 = F_121 ( V_27 , V_166 ) ;
if ( V_24 < 0 )
goto V_273;
V_271 = 1 ;
}
}
V_24 = 0 ;
if ( V_251 [ V_156 ] ) {
struct V_31 * V_199 [ V_286 + 1 ] ;
struct V_31 * V_166 ;
int V_155 ;
int V_255 ;
V_24 = - V_258 ;
if ( ! V_19 -> V_287 )
goto V_273;
F_119 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_120 ( V_166 ) != V_157 )
continue;
V_24 = F_139 ( V_199 , V_286 ,
V_166 , V_288 ) ;
if ( V_24 < 0 )
goto V_273;
if ( ! V_199 [ V_158 ] ) {
V_24 = - V_258 ;
goto V_273;
}
V_155 = F_114 ( V_199 [ V_158 ] ) ;
V_24 = V_19 -> V_287 ( V_27 , V_155 , V_199 ) ;
if ( V_24 < 0 )
goto V_273;
V_271 = 1 ;
}
}
V_24 = 0 ;
if ( V_251 [ V_160 ] ) {
struct V_31 * V_199 [ V_286 + 1 ] ;
V_24 = F_139 ( V_199 , V_286 ,
V_251 [ V_160 ] , V_288 ) ;
if ( V_24 < 0 )
goto V_273;
V_24 = - V_258 ;
if ( V_19 -> V_287 )
V_24 = V_19 -> V_287 ( V_27 , V_161 , V_199 ) ;
if ( V_24 < 0 )
goto V_273;
V_271 = 1 ;
}
if ( V_251 [ V_227 ] ) {
struct V_31 * V_229 ;
int V_255 ;
F_119 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_34 * V_36 ;
if ( ! ( V_36 = F_40 ( F_120 ( V_229 ) ) ) )
F_140 () ;
V_24 = V_36 -> V_257 ( V_27 , V_229 ) ;
if ( V_24 < 0 )
goto V_273;
V_271 = 1 ;
}
}
V_24 = 0 ;
V_273:
if ( V_24 < 0 && V_271 && F_141 () )
F_142 ( V_289 L_3
L_4
L_5
L_6 , V_27 -> V_175 ) ;
if ( V_272 )
F_143 ( V_290 , V_27 ) ;
return V_24 ;
}
static int F_144 ( struct V_38 * V_39 , struct V_65 * V_66 , void * V_291 )
{
struct V_25 * V_25 = F_106 ( V_39 -> V_233 ) ;
struct V_103 * V_104 ;
struct V_26 * V_27 ;
int V_24 ;
struct V_31 * V_251 [ V_292 + 1 ] ;
char V_270 [ V_149 ] ;
V_24 = F_145 ( V_66 , sizeof( * V_104 ) , V_251 , V_292 , V_293 ) ;
if ( V_24 < 0 )
goto V_273;
if ( V_251 [ V_174 ] )
F_146 ( V_270 , V_251 [ V_174 ] , V_149 ) ;
else
V_270 [ 0 ] = '\0' ;
V_24 = - V_254 ;
V_104 = F_94 ( V_66 ) ;
if ( V_104 -> V_172 > 0 )
V_27 = F_123 ( V_25 , V_104 -> V_172 ) ;
else if ( V_251 [ V_174 ] )
V_27 = F_147 ( V_25 , V_270 ) ;
else
goto V_273;
if ( V_27 == NULL ) {
V_24 = - V_278 ;
goto V_273;
}
V_24 = F_117 ( V_27 , V_251 ) ;
if ( V_24 < 0 )
goto V_273;
V_24 = F_125 ( V_27 , V_104 , V_251 , V_270 , 0 ) ;
V_273:
return V_24 ;
}
static int F_148 ( struct V_38 * V_39 , struct V_65 * V_66 , void * V_291 )
{
struct V_25 * V_25 = F_106 ( V_39 -> V_233 ) ;
const struct V_18 * V_19 ;
struct V_26 * V_27 ;
struct V_103 * V_104 ;
char V_270 [ V_149 ] ;
struct V_31 * V_251 [ V_292 + 1 ] ;
int V_24 ;
F_29 ( V_28 ) ;
V_24 = F_145 ( V_66 , sizeof( * V_104 ) , V_251 , V_292 , V_293 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_251 [ V_174 ] )
F_146 ( V_270 , V_251 [ V_174 ] , V_149 ) ;
V_104 = F_94 ( V_66 ) ;
if ( V_104 -> V_172 > 0 )
V_27 = F_123 ( V_25 , V_104 -> V_172 ) ;
else if ( V_251 [ V_174 ] )
V_27 = F_147 ( V_25 , V_270 ) ;
else
return - V_254 ;
if ( ! V_27 )
return - V_278 ;
V_19 = V_27 -> V_18 ;
if ( ! V_19 )
return - V_258 ;
V_19 -> V_20 ( V_27 , & V_28 ) ;
F_31 ( & V_28 ) ;
F_34 ( & V_28 ) ;
return 0 ;
}
int F_149 ( struct V_26 * V_27 , const struct V_103 * V_104 )
{
unsigned int V_294 ;
int V_24 ;
V_294 = V_27 -> V_67 ;
if ( V_104 && ( V_104 -> V_105 || V_104 -> V_106 ) ) {
V_24 = F_150 ( V_27 , F_79 ( V_27 , V_104 ) ) ;
if ( V_24 < 0 )
return V_24 ;
}
V_27 -> V_295 = V_296 ;
F_151 ( V_246 , V_27 , ~ 0U ) ;
F_152 ( V_27 , V_294 ) ;
return 0 ;
}
struct V_26 * F_153 ( struct V_25 * V_250 , struct V_25 * V_25 ,
char * V_270 , const struct V_18 * V_19 , struct V_31 * V_251 [] )
{
int V_24 ;
struct V_26 * V_27 ;
unsigned int V_297 = 1 ;
unsigned int V_298 = 1 ;
if ( V_19 -> V_299 ) {
V_24 = V_19 -> V_299 ( V_250 , V_251 , & V_297 ,
& V_298 ) ;
if ( V_24 )
goto V_24;
}
V_24 = - V_283 ;
V_27 = F_154 ( V_19 -> V_300 , V_270 , V_19 -> V_301 , V_297 ) ;
if ( ! V_27 )
goto V_24;
F_155 ( V_27 , V_25 ) ;
V_27 -> V_18 = V_19 ;
V_27 -> V_295 = V_302 ;
V_27 -> V_303 = V_298 ;
if ( V_251 [ V_182 ] )
V_27 -> V_183 = F_114 ( V_251 [ V_182 ] ) ;
if ( V_251 [ V_203 ] )
memcpy ( V_27 -> V_204 , F_102 ( V_251 [ V_203 ] ) ,
F_118 ( V_251 [ V_203 ] ) ) ;
if ( V_251 [ V_205 ] )
memcpy ( V_27 -> V_206 , F_102 ( V_251 [ V_205 ] ) ,
F_118 ( V_251 [ V_205 ] ) ) ;
if ( V_251 [ V_176 ] )
V_27 -> V_177 = F_114 ( V_251 [ V_176 ] ) ;
if ( V_251 [ V_178 ] )
F_74 ( V_27 , F_138 ( V_251 [ V_178 ] ) ) ;
if ( V_251 [ V_180 ] )
V_27 -> V_181 = F_138 ( V_251 [ V_180 ] ) ;
if ( V_251 [ V_184 ] )
F_133 ( V_27 , F_114 ( V_251 [ V_184 ] ) ) ;
return V_27 ;
V_24:
return F_156 ( V_24 ) ;
}
static int F_157 ( struct V_25 * V_25 , int V_58 ,
struct V_103 * V_104 ,
struct V_31 * * V_251 )
{
struct V_26 * V_27 ;
int V_24 ;
F_30 (net, dev) {
if ( V_27 -> V_58 == V_58 ) {
V_24 = F_125 ( V_27 , V_104 , V_251 , NULL , 0 ) ;
if ( V_24 < 0 )
return V_24 ;
}
}
return 0 ;
}
static int F_158 ( struct V_38 * V_39 , struct V_65 * V_66 , void * V_291 )
{
struct V_25 * V_25 = F_106 ( V_39 -> V_233 ) ;
const struct V_18 * V_19 ;
struct V_26 * V_27 ;
struct V_103 * V_104 ;
char V_29 [ V_304 ] ;
char V_270 [ V_149 ] ;
struct V_31 * V_251 [ V_292 + 1 ] ;
struct V_31 * V_40 [ V_305 + 1 ] ;
int V_24 ;
#ifdef F_159
V_306:
#endif
V_24 = F_145 ( V_66 , sizeof( * V_104 ) , V_251 , V_292 , V_293 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_251 [ V_174 ] )
F_146 ( V_270 , V_251 [ V_174 ] , V_149 ) ;
else
V_270 [ 0 ] = '\0' ;
V_104 = F_94 ( V_66 ) ;
if ( V_104 -> V_172 > 0 )
V_27 = F_123 ( V_25 , V_104 -> V_172 ) ;
else {
if ( V_270 [ 0 ] )
V_27 = F_147 ( V_25 , V_270 ) ;
else
V_27 = NULL ;
}
V_24 = F_117 ( V_27 , V_251 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_251 [ V_43 ] ) {
V_24 = F_139 ( V_40 , V_305 ,
V_251 [ V_43 ] , V_307 ) ;
if ( V_24 < 0 )
return V_24 ;
} else
memset ( V_40 , 0 , sizeof( V_40 ) ) ;
if ( V_40 [ V_45 ] ) {
F_146 ( V_29 , V_40 [ V_45 ] , sizeof( V_29 ) ) ;
V_19 = F_36 ( V_29 ) ;
} else {
V_29 [ 0 ] = '\0' ;
V_19 = NULL ;
}
if ( 1 ) {
struct V_31 * V_166 [ V_19 ? V_19 -> V_308 + 1 : 0 ] , * * V_41 = NULL ;
struct V_25 * V_309 ;
if ( V_19 ) {
if ( V_19 -> V_308 && V_40 [ V_49 ] ) {
V_24 = F_139 ( V_166 , V_19 -> V_308 ,
V_40 [ V_49 ] ,
V_19 -> V_310 ) ;
if ( V_24 < 0 )
return V_24 ;
V_41 = V_166 ;
}
if ( V_19 -> V_311 ) {
V_24 = V_19 -> V_311 ( V_251 , V_41 ) ;
if ( V_24 < 0 )
return V_24 ;
}
}
if ( V_27 ) {
int V_271 = 0 ;
if ( V_66 -> V_312 & V_313 )
return - V_314 ;
if ( V_66 -> V_312 & V_315 )
return - V_258 ;
if ( V_40 [ V_49 ] ) {
if ( ! V_19 || V_19 != V_27 -> V_18 ||
! V_19 -> V_316 )
return - V_258 ;
V_24 = V_19 -> V_316 ( V_27 , V_251 , V_41 ) ;
if ( V_24 < 0 )
return V_24 ;
V_271 = 1 ;
}
return F_125 ( V_27 , V_104 , V_251 , V_270 , V_271 ) ;
}
if ( ! ( V_66 -> V_312 & V_317 ) ) {
if ( V_104 -> V_172 == 0 && V_251 [ V_184 ] )
return F_157 ( V_25 ,
F_114 ( V_251 [ V_184 ] ) ,
V_104 , V_251 ) ;
return - V_278 ;
}
if ( V_104 -> V_172 )
return - V_258 ;
if ( V_251 [ V_201 ] || V_251 [ V_188 ] || V_251 [ V_318 ] )
return - V_258 ;
if ( ! V_19 ) {
#ifdef F_159
if ( V_29 [ 0 ] ) {
F_3 () ;
F_160 ( L_7 , V_29 ) ;
F_1 () ;
V_19 = F_36 ( V_29 ) ;
if ( V_19 )
goto V_306;
}
#endif
return - V_258 ;
}
if ( ! V_270 [ 0 ] )
snprintf ( V_270 , V_149 , L_8 , V_19 -> V_29 ) ;
V_309 = F_112 ( V_25 , V_251 ) ;
if ( F_126 ( V_309 ) )
return F_127 ( V_309 ) ;
V_27 = F_153 ( V_25 , V_309 , V_270 , V_19 , V_251 ) ;
if ( F_126 ( V_27 ) )
V_24 = F_127 ( V_27 ) ;
else if ( V_19 -> V_319 )
V_24 = V_19 -> V_319 ( V_25 , V_27 , V_251 , V_41 ) ;
else
V_24 = F_161 ( V_27 ) ;
if ( V_24 < 0 && ! F_126 ( V_27 ) )
F_162 ( V_27 ) ;
if ( V_24 < 0 )
goto V_44;
V_24 = F_149 ( V_27 , V_104 ) ;
if ( V_24 < 0 )
F_163 ( V_27 ) ;
V_44:
F_129 ( V_309 ) ;
return V_24 ;
}
}
static int F_164 ( struct V_38 * V_39 , struct V_65 * V_66 , void * V_291 )
{
struct V_25 * V_25 = F_106 ( V_39 -> V_233 ) ;
struct V_103 * V_104 ;
char V_270 [ V_149 ] ;
struct V_31 * V_251 [ V_292 + 1 ] ;
struct V_26 * V_27 = NULL ;
struct V_38 * V_320 ;
int V_24 ;
V_24 = F_145 ( V_66 , sizeof( * V_104 ) , V_251 , V_292 , V_293 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_251 [ V_174 ] )
F_146 ( V_270 , V_251 [ V_174 ] , V_149 ) ;
V_104 = F_94 ( V_66 ) ;
if ( V_104 -> V_172 > 0 )
V_27 = F_123 ( V_25 , V_104 -> V_172 ) ;
else if ( V_251 [ V_174 ] )
V_27 = F_147 ( V_25 , V_270 ) ;
else
return - V_254 ;
if ( V_27 == NULL )
return - V_278 ;
V_320 = F_165 ( F_86 ( V_27 ) , V_15 ) ;
if ( V_320 == NULL )
return - V_16 ;
V_24 = F_91 ( V_320 , V_27 , V_246 , F_57 ( V_39 ) . V_57 ,
V_66 -> V_247 , 0 , 0 ) ;
if ( V_24 < 0 ) {
F_166 ( V_24 == - V_42 ) ;
F_167 ( V_320 ) ;
} else
V_24 = F_61 ( V_320 , V_25 , F_57 ( V_39 ) . V_57 ) ;
return V_24 ;
}
static T_8 F_168 ( struct V_38 * V_39 )
{
return V_321 ;
}
static int F_169 ( struct V_38 * V_39 , struct V_231 * V_232 )
{
int V_236 ;
int V_237 = V_232 -> V_35 ;
if ( V_237 == 0 )
V_237 = 1 ;
for ( V_236 = 1 ; V_236 <= V_9 ; V_236 ++ ) {
int type = V_232 -> V_66 -> V_322 - V_4 ;
if ( V_236 < V_237 || V_236 == V_323 )
continue;
if ( V_10 [ V_236 ] == NULL ||
V_10 [ V_236 ] [ type ] . V_13 == NULL )
continue;
if ( V_236 > V_237 )
memset ( & V_232 -> args [ 0 ] , 0 , sizeof( V_232 -> args ) ) ;
if ( V_10 [ V_236 ] [ type ] . V_13 ( V_39 , V_232 ) )
break;
}
V_232 -> V_35 = V_236 ;
return V_39 -> V_249 ;
}
void F_151 ( int type , struct V_26 * V_27 , unsigned V_163 )
{
struct V_25 * V_25 = F_124 ( V_27 ) ;
struct V_38 * V_39 ;
int V_24 = - V_16 ;
T_4 V_324 ;
V_39 = F_165 ( ( V_324 = F_86 ( V_27 ) ) , V_15 ) ;
if ( V_39 == NULL )
goto V_273;
V_321 = F_170 ( T_8 , V_324 , V_321 ) ;
V_24 = F_91 ( V_39 , V_27 , type , 0 , 0 , V_163 , 0 ) ;
if ( V_24 < 0 ) {
F_166 ( V_24 == - V_42 ) ;
F_167 ( V_39 ) ;
goto V_273;
}
F_63 ( V_39 , V_25 , 0 , V_325 , NULL , V_15 ) ;
return;
V_273:
if ( V_24 < 0 )
F_66 ( V_25 , V_325 , V_24 ) ;
}
static int F_171 ( struct V_38 * V_39 , struct V_65 * V_66 )
{
struct V_25 * V_25 = F_106 ( V_39 -> V_233 ) ;
T_1 V_11 ;
int V_326 , V_29 ;
int V_327 ;
int V_35 ;
int type ;
int V_24 ;
type = V_66 -> V_322 ;
if ( type > V_328 )
return - V_258 ;
type -= V_4 ;
if ( V_66 -> V_329 < F_172 ( sizeof( struct V_330 ) ) )
return 0 ;
V_35 = ( (struct V_330 * ) F_173 ( V_66 ) ) -> V_331 ;
V_326 = type >> 2 ;
V_29 = type & 3 ;
if ( V_29 != 2 && F_174 ( V_39 , V_332 ) )
return - V_333 ;
if ( V_29 == 2 && V_66 -> V_312 & V_334 ) {
struct V_60 * V_61 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_335 = 0 ;
V_13 = F_16 ( V_35 , type ) ;
if ( V_13 == NULL )
return - V_258 ;
V_14 = F_17 ( V_35 , type ) ;
if ( V_14 )
V_335 = V_14 ( V_39 ) ;
F_3 () ;
V_61 = V_25 -> V_61 ;
V_24 = F_175 ( V_61 , V_39 , V_66 , V_13 ,
NULL , V_335 ) ;
F_1 () ;
return V_24 ;
}
memset ( V_336 , 0 , ( V_337 * sizeof( struct V_53 * ) ) ) ;
V_327 = V_338 [ V_326 ] ;
if ( V_66 -> V_329 < V_327 )
return - V_254 ;
if ( V_66 -> V_329 > V_327 ) {
int V_52 = V_66 -> V_329 - F_87 ( V_327 ) ;
struct V_53 * V_166 = ( void * ) V_66 + F_87 ( V_327 ) ;
while ( F_176 ( V_166 , V_52 ) ) {
unsigned V_339 = V_166 -> V_55 ;
if ( V_339 ) {
if ( V_339 > V_340 [ V_326 ] )
return - V_254 ;
V_336 [ V_339 - 1 ] = V_166 ;
}
V_166 = F_177 ( V_166 , V_52 ) ;
}
}
V_11 = F_15 ( V_35 , type ) ;
if ( V_11 == NULL )
return - V_258 ;
return V_11 ( V_39 , V_66 , ( void * ) & V_336 [ 0 ] ) ;
}
static void F_178 ( struct V_38 * V_39 )
{
F_1 () ;
F_179 ( V_39 , & F_171 ) ;
F_5 () ;
}
static int F_180 ( struct V_341 * V_342 , unsigned long V_343 , void * V_344 )
{
struct V_26 * V_27 = V_344 ;
switch ( V_343 ) {
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
break;
default:
F_151 ( V_246 , V_27 , 0 ) ;
break;
}
return V_357 ;
}
static int T_9 F_181 ( struct V_25 * V_25 )
{
struct V_60 * V_233 ;
V_233 = F_182 ( V_25 , V_358 , V_359 ,
F_178 , & V_1 , V_360 ) ;
if ( ! V_233 )
return - V_283 ;
V_25 -> V_61 = V_233 ;
return 0 ;
}
static void T_10 F_183 ( struct V_25 * V_25 )
{
F_184 ( V_25 -> V_61 ) ;
V_25 -> V_61 = NULL ;
}
void T_11 F_185 ( void )
{
int V_71 ;
V_337 = 0 ;
for ( V_71 = 0 ; V_71 < F_186 ( V_340 ) ; V_71 ++ )
if ( V_340 [ V_71 ] > V_337 )
V_337 = V_340 [ V_71 ] ;
V_336 = F_131 ( V_337 * sizeof( struct V_53 * ) , V_15 ) ;
if ( ! V_336 )
F_21 ( L_9 ) ;
if ( F_187 ( & V_361 ) )
F_21 ( L_10 ) ;
F_188 ( V_358 , V_362 ) ;
F_189 ( & V_363 ) ;
F_20 ( V_12 , V_364 , F_164 ,
F_105 , F_168 ) ;
F_20 ( V_12 , V_365 , F_144 , NULL , NULL ) ;
F_20 ( V_12 , V_246 , F_158 , NULL , NULL ) ;
F_20 ( V_12 , V_366 , F_148 , NULL , NULL ) ;
F_20 ( V_12 , V_367 , NULL , F_169 , NULL ) ;
F_20 ( V_12 , V_368 , NULL , F_169 , NULL ) ;
}
