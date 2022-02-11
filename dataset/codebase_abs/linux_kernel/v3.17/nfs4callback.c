static void F_1 ( const char * V_1 , const struct V_2 * V_3 )
{
F_2 ( L_1
L_2 ,
V_1 , V_3 -> V_4 - V_3 -> V_5 ) ;
}
static T_1 * F_3 ( T_1 * V_5 )
{
* V_5 ++ = V_6 ;
return V_5 ;
}
static void F_4 ( struct V_2 * V_3 , enum V_7 V_8 )
{
T_1 * V_5 ;
V_5 = F_5 ( V_3 , 4 ) ;
* V_5 = F_6 ( V_8 ) ;
}
static void F_7 ( struct V_2 * V_3 , const struct V_9 * V_10 )
{
T_2 V_11 = V_10 -> V_12 ;
T_1 * V_5 ;
F_8 ( V_11 > V_13 ) ;
V_5 = F_5 ( V_3 , 4 + V_11 ) ;
F_9 ( V_5 , & V_10 -> V_14 , V_11 ) ;
}
static void F_10 ( struct V_2 * V_3 , const T_3 * V_15 )
{
T_1 * V_5 ;
V_5 = F_5 ( V_3 , V_16 ) ;
* V_5 ++ = F_6 ( V_15 -> V_17 ) ;
F_11 ( V_5 , & V_15 -> V_18 , V_19 ) ;
}
static void F_12 ( struct V_2 * V_3 ,
const struct V_20 * V_21 )
{
T_1 * V_5 ;
V_5 = F_5 ( V_3 , V_22 ) ;
F_11 ( V_5 , V_21 -> V_23 . V_24 ,
V_22 ) ;
}
static int F_13 ( int V_25 )
{
int V_26 ;
for ( V_26 = 0 ; V_27 [ V_26 ] . V_28 != - 1 ; V_26 ++ ) {
if ( V_27 [ V_26 ] . V_28 == V_25 )
return V_27 [ V_26 ] . V_29 ;
}
F_2 ( L_3 , V_25 ) ;
return - V_25 ;
}
static int F_14 ( struct V_2 * V_3 , enum V_30 V_31 ,
enum V_32 * V_25 )
{
T_1 * V_5 ;
T_2 V_8 ;
V_5 = F_15 ( V_3 , 4 + 4 ) ;
if ( F_16 ( V_5 == NULL ) )
goto V_33;
V_8 = F_17 ( V_5 ++ ) ;
if ( F_16 ( V_8 != V_31 ) )
goto V_34;
* V_25 = F_17 ( V_5 ) ;
return 0 ;
V_33:
F_1 ( V_35 , V_3 ) ;
return - V_36 ;
V_34:
F_2 ( L_4
L_5 , V_8 , V_31 ) ;
return - V_36 ;
}
static void F_18 ( struct V_2 * V_3 ,
struct V_37 * V_38 )
{
T_1 * V_5 ;
V_5 = F_5 ( V_3 , 4 + 4 + 4 + 4 ) ;
V_5 = F_3 ( V_5 ) ;
* V_5 ++ = F_6 ( V_38 -> V_39 ) ;
* V_5 ++ = F_6 ( V_38 -> V_40 ) ;
V_38 -> V_41 = V_5 ;
* V_5 = F_6 ( V_38 -> V_42 ) ;
}
static void F_19 ( struct V_37 * V_38 )
{
F_8 ( V_38 -> V_42 > V_43 ) ;
* V_38 -> V_41 = F_6 ( V_38 -> V_42 ) ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_37 * V_38 )
{
T_2 V_11 ;
T_1 * V_5 ;
V_5 = F_15 ( V_3 , 4 + 4 ) ;
if ( F_16 ( V_5 == NULL ) )
goto V_33;
V_38 -> V_25 = F_17 ( V_5 ++ ) ;
V_11 = F_17 ( V_5 ++ ) ;
V_5 = F_15 ( V_3 , V_11 + 4 ) ;
if ( F_16 ( V_5 == NULL ) )
goto V_33;
V_38 -> V_42 = F_17 ( V_5 ) ;
return 0 ;
V_33:
F_1 ( V_35 , V_3 ) ;
return - V_36 ;
}
static void F_21 ( struct V_2 * V_3 ,
const struct V_44 * V_45 ,
struct V_37 * V_38 )
{
T_1 * V_5 ;
F_4 ( V_3 , V_46 ) ;
F_10 ( V_3 , & V_45 -> V_47 . V_48 ) ;
V_5 = F_5 ( V_3 , 4 ) ;
* V_5 ++ = V_6 ;
F_7 ( V_3 , & V_45 -> V_47 . V_49 -> V_50 ) ;
V_38 -> V_42 ++ ;
}
static void F_22 ( struct V_2 * V_3 ,
const struct V_51 * V_52 ,
struct V_37 * V_38 )
{
struct V_20 * V_21 = V_52 -> V_53 -> V_54 ;
T_1 * V_5 ;
if ( V_38 -> V_39 == 0 )
return;
F_4 ( V_3 , V_55 ) ;
F_12 ( V_3 , V_21 ) ;
V_5 = F_5 ( V_3 , 4 + 4 + 4 + 4 + 4 ) ;
* V_5 ++ = F_6 ( V_21 -> V_56 ) ;
* V_5 ++ = V_6 ;
* V_5 ++ = V_6 ;
* V_5 ++ = V_6 ;
F_3 ( V_5 ) ;
V_38 -> V_42 ++ ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_51 * V_52 )
{
struct V_20 * V_21 = V_52 -> V_53 -> V_54 ;
struct V_57 V_58 ;
int V_25 ;
T_1 * V_5 ;
T_2 V_59 ;
V_25 = - V_60 ;
V_5 = F_15 ( V_3 , V_22 + 4 + 4 + 4 + 4 ) ;
if ( F_16 ( V_5 == NULL ) )
goto V_33;
memcpy ( V_58 . V_24 , V_5 , V_22 ) ;
if ( memcmp ( V_58 . V_24 , V_21 -> V_23 . V_24 ,
V_22 ) != 0 ) {
F_2 ( L_6 , V_35 ) ;
goto V_61;
}
V_5 += F_24 ( V_22 ) ;
V_59 = F_17 ( V_5 ++ ) ;
if ( V_59 != V_21 -> V_56 ) {
F_2 ( L_7 , V_35 ) ;
goto V_61;
}
V_59 = F_17 ( V_5 ++ ) ;
if ( V_59 != 0 ) {
F_2 ( L_8 , V_35 ) ;
goto V_61;
}
V_25 = 0 ;
V_61:
if ( V_25 )
F_25 ( V_52 -> V_53 , V_25 ) ;
return V_25 ;
V_33:
F_1 ( V_35 , V_3 ) ;
return - V_36 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_51 * V_52 )
{
enum V_32 V_62 ;
int V_25 ;
if ( V_52 -> V_63 == 0 )
return 0 ;
V_25 = F_14 ( V_3 , V_55 , & V_62 ) ;
if ( F_16 ( V_25 ) )
goto V_61;
if ( F_16 ( V_62 != V_64 ) )
goto V_65;
V_25 = F_23 ( V_3 , V_52 ) ;
V_61:
return V_25 ;
V_65:
return F_13 ( V_62 ) ;
}
static void F_27 ( struct V_66 * V_67 , struct V_2 * V_3 ,
void * V_68 )
{
F_5 ( V_3 , 0 ) ;
}
static void F_28 ( struct V_66 * V_67 , struct V_2 * V_3 ,
const struct V_51 * V_52 )
{
const struct V_44 * args = V_52 -> V_69 ;
struct V_37 V_38 = {
. V_40 = V_52 -> V_53 -> V_70 ,
. V_39 = V_52 -> V_63 ,
} ;
F_18 ( V_3 , & V_38 ) ;
F_22 ( V_3 , V_52 , & V_38 ) ;
F_21 ( V_3 , args , & V_38 ) ;
F_19 ( & V_38 ) ;
}
static int F_29 ( struct V_66 * V_67 , struct V_2 * V_3 ,
void * V_68 )
{
return 0 ;
}
static int F_30 ( struct V_66 * V_71 ,
struct V_2 * V_3 ,
struct V_51 * V_52 )
{
struct V_37 V_38 ;
enum V_32 V_62 ;
int V_25 ;
V_25 = F_20 ( V_3 , & V_38 ) ;
if ( F_16 ( V_25 ) )
goto V_61;
if ( V_52 != NULL ) {
V_25 = F_26 ( V_3 , V_52 ) ;
if ( F_16 ( V_25 ) )
goto V_61;
}
V_25 = F_14 ( V_3 , V_46 , & V_62 ) ;
if ( F_16 ( V_25 ) )
goto V_61;
if ( F_16 ( V_62 != V_64 ) )
V_25 = F_13 ( V_62 ) ;
V_61:
return V_25 ;
}
static int F_31 ( struct V_72 * V_72 )
{
struct V_73 * V_74 = F_32 ( V_72 , V_75 ) ;
return F_33 ( V_74 -> V_76 / 10 , ( V_77 ) 1 ) * V_78 ;
}
int F_34 ( void )
{
if ( V_79 )
return 0 ;
V_79 = F_35 ( L_9 ) ;
if ( ! V_79 )
return - V_80 ;
return 0 ;
}
static struct V_81 * F_36 ( struct V_82 * V_83 , struct V_84 * V_85 , struct V_20 * V_86 )
{
if ( V_83 -> V_87 == 0 ) {
return F_37 ( V_79 ) ;
} else {
struct V_88 * V_89 = V_85 -> V_90 ;
struct V_91 V_92 = {} ;
V_92 . V_93 = V_86 -> V_94 . V_93 ;
V_92 . V_95 = V_86 -> V_94 . V_95 ;
return V_89 -> V_96 -> V_97 ( V_85 -> V_90 , & V_92 , 0 ) ;
}
}
static struct V_84 * F_38 ( struct V_98 * args )
{
struct V_99 * V_100 ;
if ( args -> V_101 != V_102 )
return F_39 ( args ) ;
V_100 = args -> V_103 -> V_104 ;
if ( V_100 ) {
F_40 ( V_100 ) ;
return F_41 ( args , V_100 ) ;
}
return F_39 ( args ) ;
}
static int F_42 ( struct V_82 * V_83 , struct V_105 * V_106 , struct V_20 * V_86 )
{
int V_107 = F_31 ( V_83 -> V_72 ) ;
struct V_108 V_109 = {
. V_110 = V_107 ,
. V_111 = 0 ,
. V_112 = V_107 ,
} ;
struct V_98 args = {
. V_72 = V_83 -> V_72 ,
. V_113 = (struct V_114 * ) & V_106 -> V_115 ,
. V_116 = V_106 -> V_117 ,
. V_118 = (struct V_114 * ) & V_106 -> V_119 ,
. V_120 = & V_109 ,
. V_121 = & V_122 ,
. V_123 = 0 ,
. V_124 = ( V_125 | V_126 ) ,
} ;
struct V_84 * V_85 ;
struct V_81 * V_127 ;
if ( V_83 -> V_87 == 0 ) {
if ( ! V_83 -> V_128 . V_129 &&
( V_83 -> V_128 . V_130 >= V_131 ) )
return - V_132 ;
args . V_133 = V_83 -> V_128 . V_129 ;
args . V_134 = V_106 -> V_135 ;
args . V_101 = V_136 ;
args . V_137 = V_83 -> V_128 . V_130 ;
V_83 -> V_70 = V_106 -> V_138 ;
} else {
if ( ! V_106 -> V_139 )
return - V_132 ;
V_83 -> V_140 . V_139 = V_106 -> V_139 ;
V_83 -> V_54 = V_86 ;
args . V_103 = V_106 -> V_139 ;
args . V_134 = V_83 -> V_54 -> V_141 ;
args . V_101 = V_106 -> V_139 -> V_142 -> V_143 |
V_144 ;
args . V_137 = V_86 -> V_94 . V_145 ;
}
V_85 = F_38 ( & args ) ;
if ( F_43 ( V_85 ) ) {
F_2 ( L_10 ,
F_44 ( V_85 ) ) ;
return F_44 ( V_85 ) ;
}
V_127 = F_36 ( V_83 , V_85 , V_86 ) ;
if ( F_43 ( V_127 ) ) {
F_45 ( V_85 ) ;
return F_44 ( V_127 ) ;
}
V_83 -> V_146 = V_85 ;
V_83 -> V_147 = V_127 ;
return 0 ;
}
static void F_46 ( struct V_82 * V_83 , int V_148 )
{
F_2 ( L_11 ,
( int ) V_83 -> V_149 . V_150 , V_83 -> V_149 . V_24 , V_148 ) ;
}
static void F_47 ( struct V_82 * V_83 , int V_148 )
{
V_83 -> V_151 = V_152 ;
F_46 ( V_83 , V_148 ) ;
}
static void F_25 ( struct V_82 * V_83 , int V_148 )
{
V_83 -> V_151 = V_153 ;
F_46 ( V_83 , V_148 ) ;
}
static void F_48 ( struct V_154 * V_155 , void * V_156 )
{
struct V_82 * V_83 = F_49 ( V_156 , struct V_82 , V_157 ) ;
if ( V_155 -> V_158 )
F_47 ( V_83 , V_155 -> V_158 ) ;
else
V_83 -> V_151 = V_159 ;
}
static void F_50 ( struct V_51 * V_52 )
{
F_51 ( V_160 , & V_52 -> V_161 ) ;
}
static void F_52 ( struct V_82 * V_83 )
{
struct V_51 * V_52 = & V_83 -> V_157 ;
V_52 -> V_69 = NULL ;
V_52 -> V_53 = V_83 ;
V_52 -> V_162 . V_163 = & V_164 [ V_165 ] ;
V_52 -> V_162 . V_166 = NULL ;
V_52 -> V_162 . V_167 = NULL ;
V_52 -> V_168 = & V_169 ;
F_50 ( V_52 ) ;
}
void F_53 ( struct V_82 * V_83 )
{
V_83 -> V_151 = V_170 ;
F_54 ( V_171 , & V_83 -> V_172 ) ;
F_52 ( V_83 ) ;
}
void F_55 ( struct V_82 * V_83 )
{
F_53 ( V_83 ) ;
F_56 ( V_160 ) ;
}
void F_57 ( struct V_82 * V_83 , struct V_105 * V_106 )
{
V_83 -> V_151 = V_170 ;
F_58 ( & V_83 -> V_173 ) ;
memcpy ( & V_83 -> V_140 , V_106 , sizeof( struct V_105 ) ) ;
F_59 ( & V_83 -> V_173 ) ;
}
static bool F_60 ( struct V_82 * V_83 , struct V_154 * V_155 )
{
if ( F_61 ( 0 , & V_83 -> V_174 ) != 0 ) {
F_62 ( & V_83 -> V_175 , V_155 , NULL ) ;
F_2 ( L_12 , V_35 ) ;
return false ;
}
return true ;
}
static void F_63 ( struct V_154 * V_155 , void * V_156 )
{
struct V_51 * V_52 = V_156 ;
struct V_82 * V_83 = V_52 -> V_53 ;
T_2 V_39 = V_83 -> V_87 ;
V_52 -> V_63 = V_39 ;
if ( V_39 ) {
if ( ! F_60 ( V_83 , V_155 ) )
return;
}
F_58 ( & V_83 -> V_173 ) ;
if ( F_64 ( & V_52 -> V_176 ) ) {
V_52 -> V_177 = false ;
F_65 ( & V_52 -> V_176 , & V_83 -> V_178 ) ;
}
F_59 ( & V_83 -> V_173 ) ;
F_66 ( V_155 ) ;
}
static void F_67 ( struct V_154 * V_155 , void * V_156 )
{
struct V_51 * V_52 = V_156 ;
struct V_82 * V_83 = V_52 -> V_53 ;
F_2 ( L_13 , V_35 ,
V_83 -> V_87 ) ;
if ( V_83 -> V_87 ) {
++ V_83 -> V_54 -> V_56 ;
F_68 ( 0 , & V_83 -> V_174 ) ;
F_69 ( & V_83 -> V_175 ) ;
F_2 ( L_14 , V_35 ,
V_83 -> V_54 -> V_56 ) ;
V_155 -> V_179 . V_167 = NULL ;
}
}
static void F_70 ( struct V_154 * V_155 , void * V_156 )
{
struct V_51 * V_52 = V_156 ;
struct V_44 * V_45 = F_49 ( V_52 , struct V_44 , V_180 ) ;
struct V_82 * V_83 = V_52 -> V_53 ;
struct V_84 * V_181 = V_83 -> V_146 ;
F_67 ( V_155 , V_156 ) ;
if ( V_181 != V_155 -> V_182 ) {
return;
}
if ( V_52 -> V_177 )
return;
switch ( V_155 -> V_158 ) {
case 0 :
V_52 -> V_177 = true ;
return;
case - V_183 :
case - V_184 :
break;
default:
F_47 ( V_83 , V_155 -> V_158 ) ;
}
if ( V_45 -> V_185 -- ) {
F_71 ( V_155 , 2 * V_78 ) ;
V_155 -> V_158 = 0 ;
F_72 ( V_155 ) ;
return;
}
F_47 ( V_83 , V_155 -> V_158 ) ;
V_52 -> V_177 = true ;
}
static void F_73 ( void * V_156 )
{
struct V_51 * V_52 = V_156 ;
struct V_82 * V_83 = V_52 -> V_53 ;
struct V_44 * V_45 = F_49 ( V_52 , struct V_44 , V_180 ) ;
if ( V_52 -> V_177 ) {
F_58 ( & V_83 -> V_173 ) ;
F_74 ( & V_52 -> V_176 ) ;
F_59 ( & V_83 -> V_173 ) ;
F_75 ( & V_45 -> V_47 ) ;
}
}
int F_76 ( void )
{
V_160 = F_77 ( L_15 ) ;
if ( ! V_160 )
return - V_80 ;
return 0 ;
}
void F_78 ( void )
{
F_79 ( V_160 ) ;
}
void F_80 ( struct V_82 * V_83 )
{
F_54 ( V_186 , & V_83 -> V_172 ) ;
F_52 ( V_83 ) ;
F_56 ( V_160 ) ;
}
static void F_81 ( struct V_51 * V_52 )
{
if ( V_52 -> V_168 -> V_187 )
V_52 -> V_168 -> V_187 ( V_52 ) ;
}
static struct V_188 * F_82 ( struct V_82 * V_83 )
{
struct V_20 * V_189 ;
struct V_188 * V_190 ;
F_83 (s, &clp->cl_sessions, se_perclnt) {
F_83 (c, &s->se_conns, cn_persession) {
if ( V_190 -> V_191 & V_192 )
return V_190 ;
}
}
return NULL ;
}
static void F_84 ( struct V_51 * V_52 )
{
struct V_105 V_106 ;
struct V_82 * V_83 = V_52 -> V_53 ;
struct V_20 * V_86 = NULL ;
struct V_188 * V_190 ;
int V_193 ;
if ( V_83 -> V_146 ) {
F_45 ( V_83 -> V_146 ) ;
V_83 -> V_146 = NULL ;
F_85 ( V_83 -> V_147 ) ;
V_83 -> V_147 = NULL ;
}
if ( V_83 -> V_140 . V_139 ) {
F_86 ( V_83 -> V_140 . V_139 ) ;
V_83 -> V_140 . V_139 = NULL ;
}
if ( F_87 ( V_186 , & V_83 -> V_172 ) )
return;
F_58 ( & V_83 -> V_173 ) ;
F_8 ( ! ( V_83 -> V_172 & V_194 ) ) ;
F_68 ( V_171 , & V_83 -> V_172 ) ;
memcpy ( & V_106 , & V_52 -> V_53 -> V_140 , sizeof( struct V_105 ) ) ;
V_190 = F_82 ( V_83 ) ;
if ( V_190 ) {
F_88 ( V_190 -> V_195 ) ;
V_106 . V_139 = V_190 -> V_195 ;
V_86 = V_190 -> V_196 ;
}
F_59 ( & V_83 -> V_173 ) ;
V_193 = F_42 ( V_83 , & V_106 , V_86 ) ;
if ( V_193 ) {
F_47 ( V_83 , V_193 ) ;
return;
}
F_83 (cb, &clp->cl_callbacks, cb_per_client)
F_50 ( V_52 ) ;
}
static void
F_89 ( struct V_51 * V_52 )
{
struct V_82 * V_83 = V_52 -> V_53 ;
struct V_84 * V_197 ;
if ( V_83 -> V_172 & V_194 )
F_84 ( V_52 ) ;
V_197 = V_83 -> V_146 ;
if ( ! V_197 ) {
F_81 ( V_52 ) ;
return;
}
V_52 -> V_162 . V_81 = V_83 -> V_147 ;
F_90 ( V_197 , & V_52 -> V_162 , V_198 | V_199 ,
V_52 -> V_168 , V_52 ) ;
}
void
F_91 ( struct V_200 * V_201 )
{
struct V_51 * V_52 = F_49 ( V_201 , struct V_51 ,
V_161 ) ;
F_89 ( V_52 ) ;
}
void
F_92 ( struct V_200 * V_201 )
{
struct V_51 * V_52 = F_49 ( V_201 , struct V_51 ,
V_161 ) ;
F_93 ( V_52 -> V_69 ) ;
F_89 ( V_52 ) ;
}
void F_94 ( struct V_44 * V_45 )
{
struct V_51 * V_52 = & V_45 -> V_180 ;
struct V_82 * V_83 = V_45 -> V_47 . V_202 ;
V_45 -> V_185 = 1 ;
V_52 -> V_69 = V_45 ;
V_52 -> V_53 = V_83 ;
V_52 -> V_162 . V_163 = & V_164 [ V_203 ] ;
V_52 -> V_162 . V_166 = V_52 ;
V_52 -> V_162 . V_167 = V_52 ;
V_52 -> V_168 = & V_204 ;
F_95 ( & V_52 -> V_176 ) ;
V_52 -> V_177 = true ;
F_50 ( & V_45 -> V_180 ) ;
}
