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
static int F_32 ( struct V_71 * V_71 )
{
struct V_72 * V_73 = F_33 ( V_71 , V_74 ) ;
return F_34 ( V_73 -> V_75 / 10 , ( V_76 ) 1 ) * V_77 ;
}
int F_35 ( void )
{
if ( V_78 )
return 0 ;
V_78 = F_36 ( L_9 ) ;
if ( ! V_78 )
return - V_79 ;
return 0 ;
}
static struct V_80 * F_37 ( struct V_81 * V_82 , struct V_83 * V_84 , struct V_20 * V_85 )
{
if ( V_82 -> V_86 == 0 ) {
return F_38 ( V_78 ) ;
} else {
struct V_87 * V_88 = V_84 -> V_89 ;
struct V_90 V_91 = {} ;
V_91 . V_92 = V_85 -> V_93 . V_92 ;
V_91 . V_94 = V_85 -> V_93 . V_94 ;
return V_88 -> V_95 -> V_96 ( V_84 -> V_89 , & V_91 , 0 ) ;
}
}
static struct V_83 * F_39 ( struct V_97 * args )
{
struct V_98 * V_99 ;
if ( args -> V_100 != V_101 )
return F_40 ( args ) ;
V_99 = args -> V_102 -> V_103 ;
if ( V_99 ) {
F_41 ( V_99 ) ;
return F_42 ( args , V_99 ) ;
}
return F_40 ( args ) ;
}
static int F_43 ( struct V_81 * V_82 , struct V_104 * V_105 , struct V_20 * V_85 )
{
int V_106 = F_32 ( V_82 -> V_71 ) ;
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
args . V_133 = V_105 -> V_134 ;
args . V_100 = V_135 ;
args . V_136 = V_82 -> V_127 . V_129 ;
V_82 -> V_69 = V_105 -> V_137 ;
} else {
if ( ! V_105 -> V_138 )
return - V_131 ;
V_82 -> V_139 . V_138 = V_105 -> V_138 ;
V_82 -> V_54 = V_85 ;
args . V_102 = V_105 -> V_138 ;
args . V_133 = V_82 -> V_54 -> V_140 ;
args . V_100 = V_105 -> V_138 -> V_141 -> V_142 |
V_143 ;
args . V_136 = V_85 -> V_93 . V_144 ;
}
V_84 = F_39 ( & args ) ;
if ( F_44 ( V_84 ) ) {
F_2 ( L_10 ,
F_45 ( V_84 ) ) ;
return F_45 ( V_84 ) ;
}
V_126 = F_37 ( V_82 , V_84 , V_85 ) ;
if ( F_44 ( V_126 ) ) {
F_46 ( V_84 ) ;
return F_45 ( V_126 ) ;
}
V_82 -> V_145 = V_84 ;
V_82 -> V_146 = V_126 ;
return 0 ;
}
static void F_47 ( struct V_81 * V_82 , int V_147 )
{
F_2 ( L_11 ,
( int ) V_82 -> V_148 . V_149 , V_82 -> V_148 . V_24 , V_147 ) ;
}
static void F_48 ( struct V_81 * V_82 , int V_147 )
{
V_82 -> V_150 = V_151 ;
F_47 ( V_82 , V_147 ) ;
}
static void F_25 ( struct V_81 * V_82 , int V_147 )
{
V_82 -> V_150 = V_152 ;
F_47 ( V_82 , V_147 ) ;
}
static void F_49 ( struct V_153 * V_154 , void * V_155 )
{
struct V_81 * V_82 = F_50 ( V_155 , struct V_81 , V_156 ) ;
if ( V_154 -> V_157 )
F_48 ( V_82 , V_154 -> V_157 ) ;
else
V_82 -> V_150 = V_158 ;
}
void F_51 ( struct V_81 * V_82 )
{
V_82 -> V_150 = V_159 ;
F_52 ( V_160 , & V_82 -> V_161 ) ;
F_53 ( & V_82 -> V_156 ) ;
}
void F_54 ( struct V_81 * V_82 )
{
F_51 ( V_82 ) ;
F_55 ( V_162 ) ;
}
void F_56 ( struct V_81 * V_82 , struct V_104 * V_105 )
{
V_82 -> V_150 = V_159 ;
F_57 ( & V_82 -> V_163 ) ;
memcpy ( & V_82 -> V_139 , V_105 , sizeof( struct V_104 ) ) ;
F_58 ( & V_82 -> V_163 ) ;
}
static bool F_59 ( struct V_81 * V_82 , struct V_153 * V_154 )
{
if ( F_60 ( 0 , & V_82 -> V_164 ) != 0 ) {
F_61 ( & V_82 -> V_165 , V_154 , NULL ) ;
if ( F_60 ( 0 , & V_82 -> V_164 ) != 0 ) {
F_2 ( L_12 , V_35 ) ;
return false ;
}
F_62 ( & V_82 -> V_165 , V_154 ) ;
}
return true ;
}
static void F_63 ( struct V_153 * V_154 , void * V_155 )
{
struct V_51 * V_52 = V_155 ;
struct V_81 * V_82 = V_52 -> V_53 ;
T_2 V_39 = V_82 -> V_86 ;
V_52 -> V_63 = V_39 ;
if ( V_39 ) {
if ( ! F_59 ( V_82 , V_154 ) )
return;
}
F_57 ( & V_82 -> V_163 ) ;
if ( F_64 ( & V_52 -> V_166 ) ) {
V_52 -> V_167 = false ;
F_65 ( & V_52 -> V_166 , & V_82 -> V_168 ) ;
}
F_58 ( & V_82 -> V_163 ) ;
F_66 ( V_154 ) ;
}
static void F_67 ( struct V_153 * V_154 , void * V_155 )
{
struct V_51 * V_52 = V_155 ;
struct V_81 * V_82 = V_52 -> V_53 ;
F_2 ( L_13 , V_35 ,
V_82 -> V_86 ) ;
if ( V_82 -> V_86 ) {
++ V_82 -> V_54 -> V_56 ;
F_68 ( 0 , & V_82 -> V_164 ) ;
F_69 ( & V_82 -> V_165 ) ;
F_2 ( L_14 , V_35 ,
V_82 -> V_54 -> V_56 ) ;
}
if ( V_82 -> V_145 != V_154 -> V_169 ) {
return;
}
if ( V_52 -> V_167 )
return;
switch ( V_52 -> V_170 -> V_171 ( V_52 , V_154 ) ) {
case 0 :
V_154 -> V_157 = 0 ;
F_70 ( V_154 ) ;
return;
case 1 :
break;
case - 1 :
F_48 ( V_82 , V_154 -> V_157 ) ;
break;
default:
F_71 () ;
}
V_52 -> V_167 = true ;
}
static void F_72 ( void * V_155 )
{
struct V_51 * V_52 = V_155 ;
struct V_81 * V_82 = V_52 -> V_53 ;
if ( V_52 -> V_167 ) {
F_57 ( & V_82 -> V_163 ) ;
F_73 ( & V_52 -> V_166 ) ;
F_58 ( & V_82 -> V_163 ) ;
V_52 -> V_170 -> V_172 ( V_52 ) ;
}
}
int F_74 ( void )
{
V_162 = F_75 ( L_15 ) ;
if ( ! V_162 )
return - V_79 ;
return 0 ;
}
void F_76 ( void )
{
F_77 ( V_162 ) ;
}
void F_78 ( struct V_81 * V_82 )
{
F_52 ( V_173 , & V_82 -> V_161 ) ;
F_53 ( & V_82 -> V_156 ) ;
F_55 ( V_162 ) ;
}
static struct V_174 * F_79 ( struct V_81 * V_82 )
{
struct V_20 * V_175 ;
struct V_174 * V_176 ;
F_80 (s, &clp->cl_sessions, se_perclnt) {
F_80 (c, &s->se_conns, cn_persession) {
if ( V_176 -> V_177 & V_178 )
return V_176 ;
}
}
return NULL ;
}
static void F_81 ( struct V_51 * V_52 )
{
struct V_104 V_105 ;
struct V_81 * V_82 = V_52 -> V_53 ;
struct V_20 * V_85 = NULL ;
struct V_174 * V_176 ;
int V_179 ;
if ( V_82 -> V_145 ) {
F_46 ( V_82 -> V_145 ) ;
V_82 -> V_145 = NULL ;
F_82 ( V_82 -> V_146 ) ;
V_82 -> V_146 = NULL ;
}
if ( V_82 -> V_139 . V_138 ) {
F_83 ( V_82 -> V_139 . V_138 ) ;
V_82 -> V_139 . V_138 = NULL ;
}
if ( F_84 ( V_173 , & V_82 -> V_161 ) )
return;
F_57 ( & V_82 -> V_163 ) ;
F_8 ( ! ( V_82 -> V_161 & V_180 ) ) ;
F_68 ( V_160 , & V_82 -> V_161 ) ;
memcpy ( & V_105 , & V_52 -> V_53 -> V_139 , sizeof( struct V_104 ) ) ;
V_176 = F_79 ( V_82 ) ;
if ( V_176 ) {
F_85 ( V_176 -> V_181 ) ;
V_105 . V_138 = V_176 -> V_181 ;
V_85 = V_176 -> V_182 ;
}
F_58 ( & V_82 -> V_163 ) ;
V_179 = F_43 ( V_82 , & V_105 , V_85 ) ;
if ( V_179 ) {
F_48 ( V_82 , V_179 ) ;
return;
}
F_80 (cb, &clp->cl_callbacks, cb_per_client)
F_86 ( V_162 , & V_52 -> V_183 ) ;
}
static void
F_87 ( struct V_184 * V_185 )
{
struct V_51 * V_52 =
F_50 ( V_185 , struct V_51 , V_183 ) ;
struct V_81 * V_82 = V_52 -> V_53 ;
struct V_83 * V_186 ;
if ( V_52 -> V_170 && V_52 -> V_170 -> V_187 )
V_52 -> V_170 -> V_187 ( V_52 ) ;
if ( V_82 -> V_161 & V_180 )
F_81 ( V_52 ) ;
V_186 = V_82 -> V_145 ;
if ( ! V_186 ) {
if ( V_52 -> V_170 && V_52 -> V_170 -> V_172 )
V_52 -> V_170 -> V_172 ( V_52 ) ;
return;
}
V_52 -> V_188 . V_80 = V_82 -> V_146 ;
F_88 ( V_186 , & V_52 -> V_188 , V_189 | V_190 ,
V_52 -> V_170 ? & V_191 : & V_192 , V_52 ) ;
}
void F_89 ( struct V_51 * V_52 , struct V_81 * V_82 ,
struct V_193 * V_194 , enum V_195 V_8 )
{
V_52 -> V_53 = V_82 ;
V_52 -> V_188 . V_196 = & V_197 [ V_8 ] ;
V_52 -> V_188 . V_198 = V_52 ;
V_52 -> V_188 . V_199 = V_52 ;
V_52 -> V_170 = V_194 ;
F_90 ( & V_52 -> V_183 , F_87 ) ;
F_91 ( & V_52 -> V_166 ) ;
V_52 -> V_167 = true ;
}
void F_53 ( struct V_51 * V_52 )
{
F_86 ( V_162 , & V_52 -> V_183 ) ;
}
