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
static int F_38 ( struct V_81 * V_82 , struct V_97 * V_98 , struct V_20 * V_85 )
{
struct V_99 V_100 = {
. V_101 = F_31 ( V_82 -> V_71 ) ,
. V_102 = 0 ,
} ;
struct V_103 args = {
. V_71 = V_82 -> V_71 ,
. V_104 = (struct V_105 * ) & V_98 -> V_106 ,
. V_107 = V_98 -> V_108 ,
. V_109 = (struct V_105 * ) & V_98 -> V_110 ,
. V_111 = & V_100 ,
. V_112 = & V_113 ,
. V_114 = 0 ,
. V_115 = ( V_116 | V_117 ) ,
} ;
struct V_83 * V_84 ;
struct V_80 * V_118 ;
if ( V_82 -> V_86 == 0 ) {
if ( ! V_82 -> V_119 . V_120 &&
( V_82 -> V_119 . V_121 >= V_122 ) )
return - V_123 ;
args . V_124 = V_82 -> V_119 . V_120 ;
args . V_125 = V_98 -> V_126 ,
args . V_127 = V_128 ;
args . V_129 = V_82 -> V_119 . V_121 ;
V_82 -> V_69 = V_98 -> V_130 ;
} else {
if ( ! V_98 -> V_131 )
return - V_123 ;
V_82 -> V_132 . V_131 = V_98 -> V_131 ;
V_82 -> V_53 = V_85 ;
args . V_133 = V_98 -> V_131 ;
args . V_125 = V_82 -> V_53 -> V_134 ;
args . V_127 = V_135 ;
args . V_129 = V_85 -> V_93 . V_136 ;
}
V_84 = F_39 ( & args ) ;
if ( F_40 ( V_84 ) ) {
F_2 ( L_10 ,
F_41 ( V_84 ) ) ;
return F_41 ( V_84 ) ;
}
V_118 = F_36 ( V_82 , V_84 , V_85 ) ;
if ( F_40 ( V_118 ) ) {
F_42 ( V_84 ) ;
return F_41 ( V_118 ) ;
}
V_82 -> V_137 = V_84 ;
V_82 -> V_138 = V_118 ;
return 0 ;
}
static void F_43 ( struct V_81 * V_82 , int V_139 )
{
F_2 ( L_11 ,
( int ) V_82 -> V_140 . V_141 , V_82 -> V_140 . V_24 , V_139 ) ;
}
static void F_44 ( struct V_81 * V_82 , int V_139 )
{
V_82 -> V_142 = V_143 ;
F_43 ( V_82 , V_139 ) ;
}
static void F_25 ( struct V_81 * V_82 , int V_139 )
{
V_82 -> V_142 = V_144 ;
F_43 ( V_82 , V_139 ) ;
}
static void F_45 ( struct V_145 * V_146 , void * V_147 )
{
struct V_81 * V_82 = F_46 ( V_147 , struct V_81 , V_148 ) ;
if ( V_146 -> V_149 )
F_44 ( V_82 , V_146 -> V_149 ) ;
else
V_82 -> V_142 = V_150 ;
}
static void F_47 ( struct V_50 * V_51 )
{
F_48 ( V_151 , & V_51 -> V_152 ) ;
}
static void F_49 ( struct V_81 * V_82 )
{
struct V_50 * V_51 = & V_82 -> V_148 ;
V_51 -> V_68 = NULL ;
V_51 -> V_52 = V_82 ;
V_51 -> V_153 . V_154 = & V_155 [ V_156 ] ;
V_51 -> V_153 . V_157 = NULL ;
V_51 -> V_153 . V_158 = NULL ;
V_51 -> V_159 = & V_160 ;
F_47 ( V_51 ) ;
}
void F_50 ( struct V_81 * V_82 )
{
V_82 -> V_142 = V_161 ;
F_51 ( V_162 , & V_82 -> V_163 ) ;
F_49 ( V_82 ) ;
}
void F_52 ( struct V_81 * V_82 )
{
F_50 ( V_82 ) ;
F_53 ( V_151 ) ;
}
void F_54 ( struct V_81 * V_82 , struct V_97 * V_98 )
{
V_82 -> V_142 = V_161 ;
F_55 ( & V_82 -> V_164 ) ;
memcpy ( & V_82 -> V_132 , V_98 , sizeof( struct V_97 ) ) ;
F_56 ( & V_82 -> V_164 ) ;
}
static bool F_57 ( struct V_81 * V_82 , struct V_145 * V_146 )
{
if ( F_58 ( 0 , & V_82 -> V_165 ) != 0 ) {
F_59 ( & V_82 -> V_166 , V_146 , NULL ) ;
F_2 ( L_12 , V_35 ) ;
return false ;
}
return true ;
}
static void F_60 ( struct V_145 * V_146 , void * V_147 )
{
struct V_50 * V_51 = V_147 ;
struct V_81 * V_82 = V_51 -> V_52 ;
T_2 V_39 = V_82 -> V_86 ;
V_51 -> V_62 = V_39 ;
if ( V_39 ) {
if ( ! F_57 ( V_82 , V_146 ) )
return;
}
F_55 ( & V_82 -> V_164 ) ;
if ( F_61 ( & V_51 -> V_167 ) ) {
V_51 -> V_168 = false ;
F_62 ( & V_51 -> V_167 , & V_82 -> V_169 ) ;
}
F_56 ( & V_82 -> V_164 ) ;
F_63 ( V_146 ) ;
}
static void F_64 ( struct V_145 * V_146 , void * V_147 )
{
struct V_50 * V_51 = V_147 ;
struct V_81 * V_82 = V_51 -> V_52 ;
F_2 ( L_13 , V_35 ,
V_82 -> V_86 ) ;
if ( V_82 -> V_86 ) {
++ V_82 -> V_53 -> V_55 ;
F_65 ( 0 , & V_82 -> V_165 ) ;
F_66 ( & V_82 -> V_166 ) ;
F_2 ( L_14 , V_35 ,
V_82 -> V_53 -> V_55 ) ;
V_146 -> V_170 . V_158 = NULL ;
}
}
static void F_67 ( struct V_145 * V_146 , void * V_147 )
{
struct V_50 * V_51 = V_147 ;
struct V_44 * V_45 = F_46 ( V_51 , struct V_44 , V_171 ) ;
struct V_81 * V_82 = V_51 -> V_52 ;
struct V_83 * V_172 = V_82 -> V_137 ;
F_64 ( V_146 , V_147 ) ;
if ( V_172 != V_146 -> V_173 ) {
return;
}
if ( V_51 -> V_168 )
return;
switch ( V_146 -> V_149 ) {
case 0 :
V_51 -> V_168 = true ;
return;
case - V_174 :
case - V_175 :
break;
default:
F_44 ( V_82 , V_146 -> V_149 ) ;
}
if ( V_45 -> V_176 -- ) {
F_68 ( V_146 , 2 * V_77 ) ;
V_146 -> V_149 = 0 ;
F_69 ( V_146 ) ;
return;
}
F_44 ( V_82 , V_146 -> V_149 ) ;
V_51 -> V_168 = true ;
}
static void F_70 ( void * V_147 )
{
struct V_50 * V_51 = V_147 ;
struct V_81 * V_82 = V_51 -> V_52 ;
struct V_44 * V_45 = F_46 ( V_51 , struct V_44 , V_171 ) ;
if ( V_51 -> V_168 ) {
F_55 ( & V_82 -> V_164 ) ;
F_71 ( & V_51 -> V_167 ) ;
F_56 ( & V_82 -> V_164 ) ;
F_72 ( V_45 ) ;
}
}
int F_73 ( void )
{
V_151 = F_74 ( L_15 ) ;
if ( ! V_151 )
return - V_79 ;
return 0 ;
}
void F_75 ( void )
{
F_76 ( V_151 ) ;
}
void F_77 ( struct V_81 * V_82 )
{
F_51 ( V_177 , & V_82 -> V_163 ) ;
F_49 ( V_82 ) ;
F_53 ( V_151 ) ;
}
static void F_78 ( struct V_50 * V_51 )
{
if ( V_51 -> V_159 -> V_178 )
V_51 -> V_159 -> V_178 ( V_51 ) ;
}
static struct V_179 * F_79 ( struct V_81 * V_82 )
{
struct V_20 * V_180 ;
struct V_179 * V_181 ;
F_80 (s, &clp->cl_sessions, se_perclnt) {
F_80 (c, &s->se_conns, cn_persession) {
if ( V_181 -> V_182 & V_183 )
return V_181 ;
}
}
return NULL ;
}
static void F_81 ( struct V_50 * V_51 )
{
struct V_97 V_98 ;
struct V_81 * V_82 = V_51 -> V_52 ;
struct V_20 * V_85 = NULL ;
struct V_179 * V_181 ;
int V_184 ;
if ( V_82 -> V_137 ) {
F_42 ( V_82 -> V_137 ) ;
V_82 -> V_137 = NULL ;
F_82 ( V_82 -> V_138 ) ;
V_82 -> V_138 = NULL ;
}
if ( V_82 -> V_132 . V_131 ) {
F_83 ( V_82 -> V_132 . V_131 ) ;
V_82 -> V_132 . V_131 = NULL ;
}
if ( F_84 ( V_177 , & V_82 -> V_163 ) )
return;
F_55 ( & V_82 -> V_164 ) ;
F_8 ( ! ( V_82 -> V_163 & V_185 ) ) ;
F_65 ( V_162 , & V_82 -> V_163 ) ;
memcpy ( & V_98 , & V_51 -> V_52 -> V_132 , sizeof( struct V_97 ) ) ;
V_181 = F_79 ( V_82 ) ;
if ( V_181 ) {
F_85 ( V_181 -> V_186 ) ;
V_98 . V_131 = V_181 -> V_186 ;
V_85 = V_181 -> V_187 ;
}
F_56 ( & V_82 -> V_164 ) ;
V_184 = F_38 ( V_82 , & V_98 , V_85 ) ;
if ( V_184 ) {
F_44 ( V_82 , V_184 ) ;
return;
}
F_80 (cb, &clp->cl_callbacks, cb_per_client)
F_47 ( V_51 ) ;
}
static void F_86 ( struct V_188 * V_189 )
{
struct V_50 * V_51 = F_46 ( V_189 , struct V_50 , V_152 ) ;
struct V_81 * V_82 = V_51 -> V_52 ;
struct V_83 * V_190 ;
if ( V_82 -> V_163 & V_185 )
F_81 ( V_51 ) ;
V_190 = V_82 -> V_137 ;
if ( ! V_190 ) {
F_78 ( V_51 ) ;
return;
}
V_51 -> V_153 . V_80 = V_82 -> V_138 ;
F_87 ( V_190 , & V_51 -> V_153 , V_191 | V_192 ,
V_51 -> V_159 , V_51 ) ;
}
void F_88 ( struct V_50 * V_51 )
{
F_89 ( & V_51 -> V_152 , F_86 ) ;
}
void F_90 ( struct V_44 * V_45 )
{
struct V_50 * V_51 = & V_45 -> V_171 ;
struct V_81 * V_82 = V_45 -> V_47 . V_193 ;
V_45 -> V_176 = 1 ;
V_51 -> V_68 = V_45 ;
V_51 -> V_52 = V_82 ;
V_51 -> V_153 . V_154 = & V_155 [ V_194 ] ;
V_51 -> V_153 . V_157 = V_51 ;
V_51 -> V_153 . V_158 = V_51 ;
V_51 -> V_159 = & V_195 ;
F_91 ( & V_51 -> V_167 ) ;
V_51 -> V_168 = true ;
F_47 ( & V_45 -> V_171 ) ;
}
