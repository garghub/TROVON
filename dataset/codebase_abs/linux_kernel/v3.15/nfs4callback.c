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
F_7 ( V_3 , & V_45 -> V_49 ) ;
V_38 -> V_42 ++ ;
}
static void F_22 ( struct V_2 * V_3 ,
const struct V_50 * V_51 ,
struct V_37 * V_38 )
{
struct V_20 * V_21 = V_51 -> V_52 -> V_53 ;
T_1 * V_5 ;
if ( V_38 -> V_39 == 0 )
return;
F_4 ( V_3 , V_54 ) ;
F_12 ( V_3 , V_21 ) ;
V_5 = F_5 ( V_3 , 4 + 4 + 4 + 4 + 4 ) ;
* V_5 ++ = F_6 ( V_21 -> V_55 ) ;
* V_5 ++ = V_6 ;
* V_5 ++ = V_6 ;
* V_5 ++ = V_6 ;
F_3 ( V_5 ) ;
V_38 -> V_42 ++ ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_50 * V_51 )
{
struct V_20 * V_21 = V_51 -> V_52 -> V_53 ;
struct V_56 V_57 ;
int V_25 ;
T_1 * V_5 ;
T_2 V_58 ;
V_25 = - V_59 ;
V_5 = F_15 ( V_3 , V_22 + 4 + 4 + 4 + 4 ) ;
if ( F_16 ( V_5 == NULL ) )
goto V_33;
memcpy ( V_57 . V_24 , V_5 , V_22 ) ;
if ( memcmp ( V_57 . V_24 , V_21 -> V_23 . V_24 ,
V_22 ) != 0 ) {
F_2 ( L_6 , V_35 ) ;
goto V_60;
}
V_5 += F_24 ( V_22 ) ;
V_58 = F_17 ( V_5 ++ ) ;
if ( V_58 != V_21 -> V_55 ) {
F_2 ( L_7 , V_35 ) ;
goto V_60;
}
V_58 = F_17 ( V_5 ++ ) ;
if ( V_58 != 0 ) {
F_2 ( L_8 , V_35 ) ;
goto V_60;
}
V_25 = 0 ;
V_60:
if ( V_25 )
F_25 ( V_51 -> V_52 , V_25 ) ;
return V_25 ;
V_33:
F_1 ( V_35 , V_3 ) ;
return - V_36 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_50 * V_51 )
{
enum V_32 V_61 ;
int V_25 ;
if ( V_51 -> V_62 == 0 )
return 0 ;
V_25 = F_14 ( V_3 , V_54 , & V_61 ) ;
if ( F_16 ( V_25 ) )
goto V_60;
if ( F_16 ( V_61 != V_63 ) )
goto V_64;
V_25 = F_23 ( V_3 , V_51 ) ;
V_60:
return V_25 ;
V_64:
return F_13 ( V_61 ) ;
}
static void F_27 ( struct V_65 * V_66 , struct V_2 * V_3 ,
void * V_67 )
{
F_5 ( V_3 , 0 ) ;
}
static void F_28 ( struct V_65 * V_66 , struct V_2 * V_3 ,
const struct V_50 * V_51 )
{
const struct V_44 * args = V_51 -> V_68 ;
struct V_37 V_38 = {
. V_40 = V_51 -> V_52 -> V_69 ,
. V_39 = V_51 -> V_62 ,
} ;
F_18 ( V_3 , & V_38 ) ;
F_22 ( V_3 , V_51 , & V_38 ) ;
F_21 ( V_3 , args , & V_38 ) ;
F_19 ( & V_38 ) ;
}
static int F_29 ( struct V_65 * V_66 , struct V_2 * V_3 ,
void * V_67 )
{
return 0 ;
}
static int F_30 ( struct V_65 * V_70 ,
struct V_2 * V_3 ,
struct V_50 * V_51 )
{
struct V_37 V_38 ;
enum V_32 V_61 ;
int V_25 ;
V_25 = F_20 ( V_3 , & V_38 ) ;
if ( F_16 ( V_25 ) )
goto V_60;
if ( V_51 != NULL ) {
V_25 = F_26 ( V_3 , V_51 ) ;
if ( F_16 ( V_25 ) )
goto V_60;
}
V_25 = F_14 ( V_3 , V_46 , & V_61 ) ;
if ( F_16 ( V_25 ) )
goto V_60;
if ( F_16 ( V_61 != V_63 ) )
V_25 = F_13 ( V_61 ) ;
V_60:
return V_25 ;
}
static int F_31 ( struct V_71 * V_71 )
{
struct V_72 * V_73 = F_32 ( V_71 , V_74 ) ;
return F_33 ( V_73 -> V_75 / 10 , ( V_76 ) 1 ) * V_77 ;
}
int F_34 ( void )
{
if ( V_78 )
return 0 ;
V_78 = F_35 ( L_9 ) ;
if ( ! V_78 )
return - V_79 ;
return 0 ;
}
static struct V_80 * F_36 ( struct V_81 * V_82 , struct V_83 * V_84 , struct V_20 * V_85 )
{
if ( V_82 -> V_86 == 0 ) {
return F_37 ( V_78 ) ;
} else {
struct V_87 * V_88 = V_84 -> V_89 ;
struct V_90 V_91 = {} ;
V_91 . V_92 = V_85 -> V_93 . V_92 ;
V_91 . V_94 = V_85 -> V_93 . V_94 ;
return V_88 -> V_95 -> V_96 ( V_84 -> V_89 , & V_91 , 0 ) ;
}
}
static struct V_83 * F_38 ( struct V_97 * args )
{
struct V_98 * V_99 ;
if ( args -> V_100 != V_101 )
return F_39 ( args ) ;
V_99 = args -> V_102 -> V_103 ;
if ( V_99 ) {
F_40 ( V_99 ) ;
return F_41 ( args , V_99 ) ;
}
return F_39 ( args ) ;
}
static int F_42 ( struct V_81 * V_82 , struct V_104 * V_105 , struct V_20 * V_85 )
{
int V_106 = F_31 ( V_82 -> V_71 ) ;
struct V_107 V_108 = {
. V_109 = V_106 ,
. V_110 = 0 ,
. V_111 = V_106 ,
} ;
struct V_97 args = {
. V_71 = V_82 -> V_71 ,
. V_112 = (struct V_113 * ) & V_105 -> V_114 ,
. V_115 = V_105 -> V_116 ,
. V_117 = (struct V_113 * ) & V_105 -> V_118 ,
. V_119 = & V_108 ,
. V_120 = & V_121 ,
. V_122 = 0 ,
. V_123 = ( V_124 | V_125 ) ,
} ;
struct V_83 * V_84 ;
struct V_80 * V_126 ;
if ( V_82 -> V_86 == 0 ) {
if ( ! V_82 -> V_127 . V_128 &&
( V_82 -> V_127 . V_129 >= V_130 ) )
return - V_131 ;
args . V_132 = V_82 -> V_127 . V_128 ;
args . V_133 = V_105 -> V_134 ,
args . V_100 = V_135 ;
args . V_136 = V_82 -> V_127 . V_129 ;
V_82 -> V_69 = V_105 -> V_137 ;
} else {
if ( ! V_105 -> V_138 )
return - V_131 ;
V_82 -> V_139 . V_138 = V_105 -> V_138 ;
V_82 -> V_53 = V_85 ;
args . V_102 = V_105 -> V_138 ;
args . V_133 = V_82 -> V_53 -> V_140 ;
args . V_100 = V_101 ;
args . V_136 = V_85 -> V_93 . V_141 ;
}
V_84 = F_38 ( & args ) ;
if ( F_43 ( V_84 ) ) {
F_2 ( L_10 ,
F_44 ( V_84 ) ) ;
return F_44 ( V_84 ) ;
}
V_126 = F_36 ( V_82 , V_84 , V_85 ) ;
if ( F_43 ( V_126 ) ) {
F_45 ( V_84 ) ;
return F_44 ( V_126 ) ;
}
V_82 -> V_142 = V_84 ;
V_82 -> V_143 = V_126 ;
return 0 ;
}
static void F_46 ( struct V_81 * V_82 , int V_144 )
{
F_2 ( L_11 ,
( int ) V_82 -> V_145 . V_146 , V_82 -> V_145 . V_24 , V_144 ) ;
}
static void F_47 ( struct V_81 * V_82 , int V_144 )
{
V_82 -> V_147 = V_148 ;
F_46 ( V_82 , V_144 ) ;
}
static void F_25 ( struct V_81 * V_82 , int V_144 )
{
V_82 -> V_147 = V_149 ;
F_46 ( V_82 , V_144 ) ;
}
static void F_48 ( struct V_150 * V_151 , void * V_152 )
{
struct V_81 * V_82 = F_49 ( V_152 , struct V_81 , V_153 ) ;
if ( V_151 -> V_154 )
F_47 ( V_82 , V_151 -> V_154 ) ;
else
V_82 -> V_147 = V_155 ;
}
static void F_50 ( struct V_50 * V_51 )
{
F_51 ( V_156 , & V_51 -> V_157 ) ;
}
static void F_52 ( struct V_81 * V_82 )
{
struct V_50 * V_51 = & V_82 -> V_153 ;
V_51 -> V_68 = NULL ;
V_51 -> V_52 = V_82 ;
V_51 -> V_158 . V_159 = & V_160 [ V_161 ] ;
V_51 -> V_158 . V_162 = NULL ;
V_51 -> V_158 . V_163 = NULL ;
V_51 -> V_164 = & V_165 ;
F_50 ( V_51 ) ;
}
void F_53 ( struct V_81 * V_82 )
{
V_82 -> V_147 = V_166 ;
F_54 ( V_167 , & V_82 -> V_168 ) ;
F_52 ( V_82 ) ;
}
void F_55 ( struct V_81 * V_82 )
{
F_53 ( V_82 ) ;
F_56 ( V_156 ) ;
}
void F_57 ( struct V_81 * V_82 , struct V_104 * V_105 )
{
V_82 -> V_147 = V_166 ;
F_58 ( & V_82 -> V_169 ) ;
memcpy ( & V_82 -> V_139 , V_105 , sizeof( struct V_104 ) ) ;
F_59 ( & V_82 -> V_169 ) ;
}
static bool F_60 ( struct V_81 * V_82 , struct V_150 * V_151 )
{
if ( F_61 ( 0 , & V_82 -> V_170 ) != 0 ) {
F_62 ( & V_82 -> V_171 , V_151 , NULL ) ;
F_2 ( L_12 , V_35 ) ;
return false ;
}
return true ;
}
static void F_63 ( struct V_150 * V_151 , void * V_152 )
{
struct V_50 * V_51 = V_152 ;
struct V_81 * V_82 = V_51 -> V_52 ;
T_2 V_39 = V_82 -> V_86 ;
V_51 -> V_62 = V_39 ;
if ( V_39 ) {
if ( ! F_60 ( V_82 , V_151 ) )
return;
}
F_58 ( & V_82 -> V_169 ) ;
if ( F_64 ( & V_51 -> V_172 ) ) {
V_51 -> V_173 = false ;
F_65 ( & V_51 -> V_172 , & V_82 -> V_174 ) ;
}
F_59 ( & V_82 -> V_169 ) ;
F_66 ( V_151 ) ;
}
static void F_67 ( struct V_150 * V_151 , void * V_152 )
{
struct V_50 * V_51 = V_152 ;
struct V_81 * V_82 = V_51 -> V_52 ;
F_2 ( L_13 , V_35 ,
V_82 -> V_86 ) ;
if ( V_82 -> V_86 ) {
++ V_82 -> V_53 -> V_55 ;
F_68 ( 0 , & V_82 -> V_170 ) ;
F_69 ( & V_82 -> V_171 ) ;
F_2 ( L_14 , V_35 ,
V_82 -> V_53 -> V_55 ) ;
V_151 -> V_175 . V_163 = NULL ;
}
}
static void F_70 ( struct V_150 * V_151 , void * V_152 )
{
struct V_50 * V_51 = V_152 ;
struct V_44 * V_45 = F_49 ( V_51 , struct V_44 , V_176 ) ;
struct V_81 * V_82 = V_51 -> V_52 ;
struct V_83 * V_177 = V_82 -> V_142 ;
F_67 ( V_151 , V_152 ) ;
if ( V_177 != V_151 -> V_178 ) {
return;
}
if ( V_51 -> V_173 )
return;
switch ( V_151 -> V_154 ) {
case 0 :
V_51 -> V_173 = true ;
return;
case - V_179 :
case - V_180 :
break;
default:
F_47 ( V_82 , V_151 -> V_154 ) ;
}
if ( V_45 -> V_181 -- ) {
F_71 ( V_151 , 2 * V_77 ) ;
V_151 -> V_154 = 0 ;
F_72 ( V_151 ) ;
return;
}
F_47 ( V_82 , V_151 -> V_154 ) ;
V_51 -> V_173 = true ;
}
static void F_73 ( void * V_152 )
{
struct V_50 * V_51 = V_152 ;
struct V_81 * V_82 = V_51 -> V_52 ;
struct V_44 * V_45 = F_49 ( V_51 , struct V_44 , V_176 ) ;
if ( V_51 -> V_173 ) {
F_58 ( & V_82 -> V_169 ) ;
F_74 ( & V_51 -> V_172 ) ;
F_59 ( & V_82 -> V_169 ) ;
F_75 ( V_45 ) ;
}
}
int F_76 ( void )
{
V_156 = F_77 ( L_15 ) ;
if ( ! V_156 )
return - V_79 ;
return 0 ;
}
void F_78 ( void )
{
F_79 ( V_156 ) ;
}
void F_80 ( struct V_81 * V_82 )
{
F_54 ( V_182 , & V_82 -> V_168 ) ;
F_52 ( V_82 ) ;
F_56 ( V_156 ) ;
}
static void F_81 ( struct V_50 * V_51 )
{
if ( V_51 -> V_164 -> V_183 )
V_51 -> V_164 -> V_183 ( V_51 ) ;
}
static struct V_184 * F_82 ( struct V_81 * V_82 )
{
struct V_20 * V_185 ;
struct V_184 * V_186 ;
F_83 (s, &clp->cl_sessions, se_perclnt) {
F_83 (c, &s->se_conns, cn_persession) {
if ( V_186 -> V_187 & V_188 )
return V_186 ;
}
}
return NULL ;
}
static void F_84 ( struct V_50 * V_51 )
{
struct V_104 V_105 ;
struct V_81 * V_82 = V_51 -> V_52 ;
struct V_20 * V_85 = NULL ;
struct V_184 * V_186 ;
int V_189 ;
if ( V_82 -> V_142 ) {
F_45 ( V_82 -> V_142 ) ;
V_82 -> V_142 = NULL ;
F_85 ( V_82 -> V_143 ) ;
V_82 -> V_143 = NULL ;
}
if ( V_82 -> V_139 . V_138 ) {
F_86 ( V_82 -> V_139 . V_138 ) ;
V_82 -> V_139 . V_138 = NULL ;
}
if ( F_87 ( V_182 , & V_82 -> V_168 ) )
return;
F_58 ( & V_82 -> V_169 ) ;
F_8 ( ! ( V_82 -> V_168 & V_190 ) ) ;
F_68 ( V_167 , & V_82 -> V_168 ) ;
memcpy ( & V_105 , & V_51 -> V_52 -> V_139 , sizeof( struct V_104 ) ) ;
V_186 = F_82 ( V_82 ) ;
if ( V_186 ) {
F_88 ( V_186 -> V_191 ) ;
V_105 . V_138 = V_186 -> V_191 ;
V_85 = V_186 -> V_192 ;
}
F_59 ( & V_82 -> V_169 ) ;
V_189 = F_42 ( V_82 , & V_105 , V_85 ) ;
if ( V_189 ) {
F_47 ( V_82 , V_189 ) ;
return;
}
F_83 (cb, &clp->cl_callbacks, cb_per_client)
F_50 ( V_51 ) ;
}
static void F_89 ( struct V_193 * V_194 )
{
struct V_50 * V_51 = F_49 ( V_194 , struct V_50 , V_157 ) ;
struct V_81 * V_82 = V_51 -> V_52 ;
struct V_83 * V_195 ;
if ( V_82 -> V_168 & V_190 )
F_84 ( V_51 ) ;
V_195 = V_82 -> V_142 ;
if ( ! V_195 ) {
F_81 ( V_51 ) ;
return;
}
V_51 -> V_158 . V_80 = V_82 -> V_143 ;
F_90 ( V_195 , & V_51 -> V_158 , V_196 | V_197 ,
V_51 -> V_164 , V_51 ) ;
}
void F_91 ( struct V_50 * V_51 )
{
F_92 ( & V_51 -> V_157 , F_89 ) ;
}
void F_93 ( struct V_44 * V_45 )
{
struct V_50 * V_51 = & V_45 -> V_176 ;
struct V_81 * V_82 = V_45 -> V_47 . V_198 ;
V_45 -> V_181 = 1 ;
V_51 -> V_68 = V_45 ;
V_51 -> V_52 = V_82 ;
V_51 -> V_158 . V_159 = & V_160 [ V_199 ] ;
V_51 -> V_158 . V_162 = V_51 ;
V_51 -> V_158 . V_163 = V_51 ;
V_51 -> V_164 = & V_200 ;
F_94 ( & V_51 -> V_172 ) ;
V_51 -> V_173 = true ;
F_50 ( & V_45 -> V_176 ) ;
}
