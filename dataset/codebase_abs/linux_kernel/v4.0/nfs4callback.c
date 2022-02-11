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
const struct V_44 * V_45 = F_29 ( V_52 ) ;
struct V_37 V_38 = {
. V_40 = V_52 -> V_53 -> V_69 ,
. V_39 = V_52 -> V_63 ,
} ;
F_18 ( V_3 , & V_38 ) ;
F_22 ( V_3 , V_52 , & V_38 ) ;
F_21 ( V_3 , V_45 , & V_38 ) ;
F_19 ( & V_38 ) ;
}
static int F_30 ( struct V_66 * V_67 , struct V_2 * V_3 ,
void * V_68 )
{
return 0 ;
}
static int F_31 ( struct V_66 * V_70 ,
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
static void F_32 ( struct V_2 * V_3 ,
const struct V_71 * V_72 ,
struct V_37 * V_38 )
{
T_1 * V_5 ;
F_8 ( V_38 -> V_39 == 0 ) ;
V_5 = F_5 ( V_3 , 5 * 4 ) ;
* V_5 ++ = F_6 ( V_73 ) ;
* V_5 ++ = F_6 ( V_72 -> V_74 ) ;
* V_5 ++ = F_6 ( V_75 ) ;
* V_5 ++ = F_6 ( 1 ) ;
* V_5 = F_6 ( V_76 ) ;
F_7 ( V_3 , & V_72 -> V_77 . V_49 -> V_50 ) ;
V_5 = F_5 ( V_3 , 2 * 8 ) ;
V_5 = F_33 ( V_5 , 0 ) ;
F_33 ( V_5 , V_78 ) ;
F_10 ( V_3 , & V_72 -> V_79 ) ;
V_38 -> V_42 ++ ;
}
static void F_34 ( struct V_66 * V_67 ,
struct V_2 * V_3 ,
const struct V_51 * V_52 )
{
const struct V_71 * V_72 =
F_35 ( V_52 , struct V_71 , V_80 ) ;
struct V_37 V_38 = {
. V_40 = 0 ,
. V_39 = V_52 -> V_63 ,
} ;
F_18 ( V_3 , & V_38 ) ;
F_22 ( V_3 , V_52 , & V_38 ) ;
F_32 ( V_3 , V_72 , & V_38 ) ;
F_19 ( & V_38 ) ;
}
static int F_36 ( struct V_66 * V_70 ,
struct V_2 * V_3 ,
struct V_51 * V_52 )
{
struct V_37 V_38 ;
enum V_32 V_62 ;
int V_25 ;
V_25 = F_20 ( V_3 , & V_38 ) ;
if ( F_16 ( V_25 ) )
goto V_61;
if ( V_52 ) {
V_25 = F_26 ( V_3 , V_52 ) ;
if ( F_16 ( V_25 ) )
goto V_61;
}
V_25 = F_14 ( V_3 , V_73 , & V_62 ) ;
if ( F_16 ( V_25 ) )
goto V_61;
if ( F_16 ( V_62 != V_64 ) )
V_25 = F_13 ( V_62 ) ;
V_61:
return V_25 ;
}
static int F_37 ( struct V_81 * V_81 )
{
struct V_82 * V_83 = F_38 ( V_81 , V_84 ) ;
return F_39 ( V_83 -> V_85 / 10 , ( V_86 ) 1 ) * V_87 ;
}
int F_40 ( void )
{
if ( V_88 )
return 0 ;
V_88 = F_41 ( L_9 ) ;
if ( ! V_88 )
return - V_89 ;
return 0 ;
}
static struct V_90 * F_42 ( struct V_91 * V_92 , struct V_93 * V_94 , struct V_20 * V_95 )
{
if ( V_92 -> V_96 == 0 ) {
return F_43 ( V_88 ) ;
} else {
struct V_97 * V_98 = V_94 -> V_99 ;
struct V_100 V_101 = {} ;
V_101 . V_102 = V_95 -> V_103 . V_102 ;
V_101 . V_104 = V_95 -> V_103 . V_104 ;
return V_98 -> V_105 -> V_106 ( V_94 -> V_99 , & V_101 , 0 ) ;
}
}
static struct V_93 * F_44 ( struct V_107 * args )
{
struct V_108 * V_109 ;
if ( args -> V_110 != V_111 )
return F_45 ( args ) ;
V_109 = args -> V_112 -> V_113 ;
if ( V_109 ) {
F_46 ( V_109 ) ;
return F_47 ( args , V_109 ) ;
}
return F_45 ( args ) ;
}
static int F_48 ( struct V_91 * V_92 , struct V_114 * V_115 , struct V_20 * V_95 )
{
int V_116 = F_37 ( V_92 -> V_81 ) ;
struct V_117 V_118 = {
. V_119 = V_116 ,
. V_120 = 0 ,
. V_121 = V_116 ,
} ;
struct V_107 args = {
. V_81 = V_92 -> V_81 ,
. V_122 = (struct V_123 * ) & V_115 -> V_124 ,
. V_125 = V_115 -> V_126 ,
. V_127 = (struct V_123 * ) & V_115 -> V_128 ,
. V_129 = & V_118 ,
. V_130 = & V_131 ,
. V_132 = 0 ,
. V_133 = ( V_134 | V_135 ) ,
} ;
struct V_93 * V_94 ;
struct V_90 * V_136 ;
if ( V_92 -> V_96 == 0 ) {
if ( ! V_92 -> V_137 . V_138 &&
( V_92 -> V_137 . V_139 >= V_140 ) )
return - V_141 ;
args . V_142 = V_92 -> V_137 . V_138 ;
args . V_143 = V_115 -> V_144 ;
args . V_110 = V_145 ;
args . V_146 = V_92 -> V_137 . V_139 ;
V_92 -> V_69 = V_115 -> V_147 ;
} else {
if ( ! V_115 -> V_148 )
return - V_141 ;
V_92 -> V_149 . V_148 = V_115 -> V_148 ;
V_92 -> V_54 = V_95 ;
args . V_112 = V_115 -> V_148 ;
args . V_143 = V_92 -> V_54 -> V_150 ;
args . V_110 = V_115 -> V_148 -> V_151 -> V_152 |
V_153 ;
args . V_146 = V_95 -> V_103 . V_154 ;
}
V_94 = F_44 ( & args ) ;
if ( F_49 ( V_94 ) ) {
F_2 ( L_10 ,
F_50 ( V_94 ) ) ;
return F_50 ( V_94 ) ;
}
V_136 = F_42 ( V_92 , V_94 , V_95 ) ;
if ( F_49 ( V_136 ) ) {
F_51 ( V_94 ) ;
return F_50 ( V_136 ) ;
}
V_92 -> V_155 = V_94 ;
V_92 -> V_156 = V_136 ;
return 0 ;
}
static void F_52 ( struct V_91 * V_92 , int V_157 )
{
F_2 ( L_11 ,
( int ) V_92 -> V_158 . V_159 , V_92 -> V_158 . V_24 , V_157 ) ;
}
static void F_53 ( struct V_91 * V_92 , int V_157 )
{
V_92 -> V_160 = V_161 ;
F_52 ( V_92 , V_157 ) ;
}
static void F_25 ( struct V_91 * V_92 , int V_157 )
{
V_92 -> V_160 = V_162 ;
F_52 ( V_92 , V_157 ) ;
}
static void F_54 ( struct V_163 * V_164 , void * V_165 )
{
struct V_91 * V_92 = F_35 ( V_165 , struct V_91 , V_166 ) ;
if ( V_164 -> V_167 )
F_53 ( V_92 , V_164 -> V_167 ) ;
else
V_92 -> V_160 = V_168 ;
}
void F_55 ( struct V_91 * V_92 )
{
V_92 -> V_160 = V_169 ;
F_56 ( V_170 , & V_92 -> V_171 ) ;
F_57 ( & V_92 -> V_166 ) ;
}
void F_58 ( struct V_91 * V_92 )
{
F_55 ( V_92 ) ;
F_59 ( V_172 ) ;
}
void F_60 ( struct V_91 * V_92 , struct V_114 * V_115 )
{
V_92 -> V_160 = V_169 ;
F_61 ( & V_92 -> V_173 ) ;
memcpy ( & V_92 -> V_149 , V_115 , sizeof( struct V_114 ) ) ;
F_62 ( & V_92 -> V_173 ) ;
}
static bool F_63 ( struct V_91 * V_92 , struct V_163 * V_164 )
{
if ( F_64 ( 0 , & V_92 -> V_174 ) != 0 ) {
F_65 ( & V_92 -> V_175 , V_164 , NULL ) ;
if ( F_64 ( 0 , & V_92 -> V_174 ) != 0 ) {
F_2 ( L_12 , V_35 ) ;
return false ;
}
F_66 ( & V_92 -> V_175 , V_164 ) ;
}
return true ;
}
static void F_67 ( struct V_163 * V_164 , void * V_165 )
{
struct V_51 * V_52 = V_165 ;
struct V_91 * V_92 = V_52 -> V_53 ;
T_2 V_39 = V_92 -> V_96 ;
V_52 -> V_63 = V_39 ;
if ( V_39 ) {
if ( ! F_63 ( V_92 , V_164 ) )
return;
}
F_61 ( & V_92 -> V_173 ) ;
if ( F_68 ( & V_52 -> V_176 ) ) {
V_52 -> V_177 = false ;
F_69 ( & V_52 -> V_176 , & V_92 -> V_178 ) ;
}
F_62 ( & V_92 -> V_173 ) ;
F_70 ( V_164 ) ;
}
static void F_71 ( struct V_163 * V_164 , void * V_165 )
{
struct V_51 * V_52 = V_165 ;
struct V_91 * V_92 = V_52 -> V_53 ;
F_2 ( L_13 , V_35 ,
V_92 -> V_96 ) ;
if ( V_92 -> V_96 ) {
++ V_92 -> V_54 -> V_56 ;
F_72 ( 0 , & V_92 -> V_174 ) ;
F_73 ( & V_92 -> V_175 ) ;
F_2 ( L_14 , V_35 ,
V_92 -> V_54 -> V_56 ) ;
}
if ( V_92 -> V_155 != V_164 -> V_179 ) {
return;
}
if ( V_52 -> V_177 )
return;
switch ( V_52 -> V_180 -> V_181 ( V_52 , V_164 ) ) {
case 0 :
V_164 -> V_167 = 0 ;
F_74 ( V_164 ) ;
return;
case 1 :
break;
case - 1 :
F_53 ( V_92 , V_164 -> V_167 ) ;
break;
default:
F_75 () ;
}
V_52 -> V_177 = true ;
}
static void F_76 ( void * V_165 )
{
struct V_51 * V_52 = V_165 ;
struct V_91 * V_92 = V_52 -> V_53 ;
if ( V_52 -> V_177 ) {
F_61 ( & V_92 -> V_173 ) ;
F_77 ( & V_52 -> V_176 ) ;
F_62 ( & V_92 -> V_173 ) ;
V_52 -> V_180 -> V_182 ( V_52 ) ;
}
}
int F_78 ( void )
{
V_172 = F_79 ( L_15 ) ;
if ( ! V_172 )
return - V_89 ;
return 0 ;
}
void F_80 ( void )
{
F_81 ( V_172 ) ;
}
void F_82 ( struct V_91 * V_92 )
{
F_56 ( V_183 , & V_92 -> V_171 ) ;
F_57 ( & V_92 -> V_166 ) ;
F_59 ( V_172 ) ;
}
static struct V_184 * F_83 ( struct V_91 * V_92 )
{
struct V_20 * V_185 ;
struct V_184 * V_186 ;
F_84 (s, &clp->cl_sessions, se_perclnt) {
F_84 (c, &s->se_conns, cn_persession) {
if ( V_186 -> V_187 & V_188 )
return V_186 ;
}
}
return NULL ;
}
static void F_85 ( struct V_51 * V_52 )
{
struct V_114 V_115 ;
struct V_91 * V_92 = V_52 -> V_53 ;
struct V_20 * V_95 = NULL ;
struct V_184 * V_186 ;
int V_189 ;
if ( V_92 -> V_155 ) {
F_51 ( V_92 -> V_155 ) ;
V_92 -> V_155 = NULL ;
F_86 ( V_92 -> V_156 ) ;
V_92 -> V_156 = NULL ;
}
if ( V_92 -> V_149 . V_148 ) {
F_87 ( V_92 -> V_149 . V_148 ) ;
V_92 -> V_149 . V_148 = NULL ;
}
if ( F_88 ( V_183 , & V_92 -> V_171 ) )
return;
F_61 ( & V_92 -> V_173 ) ;
F_8 ( ! ( V_92 -> V_171 & V_190 ) ) ;
F_72 ( V_170 , & V_92 -> V_171 ) ;
memcpy ( & V_115 , & V_52 -> V_53 -> V_149 , sizeof( struct V_114 ) ) ;
V_186 = F_83 ( V_92 ) ;
if ( V_186 ) {
F_89 ( V_186 -> V_191 ) ;
V_115 . V_148 = V_186 -> V_191 ;
V_95 = V_186 -> V_192 ;
}
F_62 ( & V_92 -> V_173 ) ;
V_189 = F_48 ( V_92 , & V_115 , V_95 ) ;
if ( V_189 ) {
F_53 ( V_92 , V_189 ) ;
return;
}
F_84 (cb, &clp->cl_callbacks, cb_per_client)
F_90 ( V_172 , & V_52 -> V_193 ) ;
}
static void
F_91 ( struct V_194 * V_195 )
{
struct V_51 * V_52 =
F_35 ( V_195 , struct V_51 , V_193 ) ;
struct V_91 * V_92 = V_52 -> V_53 ;
struct V_93 * V_196 ;
if ( V_52 -> V_180 && V_52 -> V_180 -> V_197 )
V_52 -> V_180 -> V_197 ( V_52 ) ;
if ( V_92 -> V_171 & V_190 )
F_85 ( V_52 ) ;
V_196 = V_92 -> V_155 ;
if ( ! V_196 ) {
if ( V_52 -> V_180 && V_52 -> V_180 -> V_182 )
V_52 -> V_180 -> V_182 ( V_52 ) ;
return;
}
V_52 -> V_198 . V_90 = V_92 -> V_156 ;
F_92 ( V_196 , & V_52 -> V_198 , V_199 | V_200 ,
V_52 -> V_180 ? & V_201 : & V_202 , V_52 ) ;
}
void F_93 ( struct V_51 * V_52 , struct V_91 * V_92 ,
struct V_203 * V_204 , enum V_205 V_8 )
{
V_52 -> V_53 = V_92 ;
V_52 -> V_198 . V_206 = & V_207 [ V_8 ] ;
V_52 -> V_198 . V_208 = V_52 ;
V_52 -> V_198 . V_209 = V_52 ;
V_52 -> V_180 = V_204 ;
F_94 ( & V_52 -> V_193 , F_91 ) ;
F_95 ( & V_52 -> V_176 ) ;
V_52 -> V_177 = true ;
}
void F_57 ( struct V_51 * V_52 )
{
F_90 ( V_172 , & V_52 -> V_193 ) ;
}
