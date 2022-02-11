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
int * V_25 )
{
T_1 * V_5 ;
T_2 V_8 ;
V_5 = F_15 ( V_3 , 4 + 4 ) ;
if ( F_16 ( V_5 == NULL ) )
goto V_32;
V_8 = F_17 ( V_5 ++ ) ;
if ( F_16 ( V_8 != V_31 ) )
goto V_33;
* V_25 = F_13 ( F_17 ( V_5 ) ) ;
return 0 ;
V_32:
F_1 ( V_34 , V_3 ) ;
return - V_35 ;
V_33:
F_2 ( L_4
L_5 , V_8 , V_31 ) ;
return - V_35 ;
}
static void F_18 ( struct V_2 * V_3 ,
struct V_36 * V_37 )
{
T_1 * V_5 ;
V_5 = F_5 ( V_3 , 4 + 4 + 4 + 4 ) ;
V_5 = F_3 ( V_5 ) ;
* V_5 ++ = F_6 ( V_37 -> V_38 ) ;
* V_5 ++ = F_6 ( V_37 -> V_39 ) ;
V_37 -> V_40 = V_5 ;
* V_5 = F_6 ( V_37 -> V_41 ) ;
}
static void F_19 ( struct V_36 * V_37 )
{
F_8 ( V_37 -> V_41 > V_42 ) ;
* V_37 -> V_40 = F_6 ( V_37 -> V_41 ) ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_36 * V_37 )
{
T_2 V_11 ;
T_1 * V_5 ;
V_5 = F_15 ( V_3 , 4 + 4 ) ;
if ( F_16 ( V_5 == NULL ) )
goto V_32;
V_37 -> V_25 = F_17 ( V_5 ++ ) ;
V_11 = F_17 ( V_5 ++ ) ;
V_5 = F_15 ( V_3 , V_11 + 4 ) ;
if ( F_16 ( V_5 == NULL ) )
goto V_32;
V_37 -> V_41 = F_17 ( V_5 ) ;
return 0 ;
V_32:
F_1 ( V_34 , V_3 ) ;
return - V_35 ;
}
static void F_21 ( struct V_2 * V_3 ,
const struct V_43 * V_44 ,
struct V_36 * V_37 )
{
T_1 * V_5 ;
F_4 ( V_3 , V_45 ) ;
F_10 ( V_3 , & V_44 -> V_46 . V_47 ) ;
V_5 = F_5 ( V_3 , 4 ) ;
* V_5 ++ = V_6 ;
F_7 ( V_3 , & V_44 -> V_46 . V_48 -> V_49 ) ;
V_37 -> V_41 ++ ;
}
static void F_22 ( struct V_2 * V_3 ,
const struct V_50 * V_51 ,
struct V_36 * V_37 )
{
struct V_20 * V_21 = V_51 -> V_52 -> V_53 ;
T_1 * V_5 ;
if ( V_37 -> V_38 == 0 )
return;
F_4 ( V_3 , V_54 ) ;
F_12 ( V_3 , V_21 ) ;
V_5 = F_5 ( V_3 , 4 + 4 + 4 + 4 + 4 ) ;
* V_5 ++ = F_6 ( V_21 -> V_55 ) ;
* V_5 ++ = V_6 ;
* V_5 ++ = V_6 ;
* V_5 ++ = V_6 ;
F_3 ( V_5 ) ;
V_37 -> V_41 ++ ;
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
goto V_32;
memcpy ( V_57 . V_24 , V_5 , V_22 ) ;
if ( memcmp ( V_57 . V_24 , V_21 -> V_23 . V_24 ,
V_22 ) != 0 ) {
F_2 ( L_6 , V_34 ) ;
goto V_60;
}
V_5 += F_24 ( V_22 ) ;
V_58 = F_17 ( V_5 ++ ) ;
if ( V_58 != V_21 -> V_55 ) {
F_2 ( L_7 , V_34 ) ;
goto V_60;
}
V_58 = F_17 ( V_5 ++ ) ;
if ( V_58 != 0 ) {
F_2 ( L_8 , V_34 ) ;
goto V_60;
}
V_25 = 0 ;
V_60:
if ( V_25 )
F_25 ( V_51 -> V_52 , V_25 ) ;
return V_25 ;
V_32:
F_1 ( V_34 , V_3 ) ;
return - V_35 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_50 * V_51 )
{
int V_25 ;
if ( V_51 -> V_61 == 0 )
return 0 ;
V_25 = F_14 ( V_3 , V_54 , & V_51 -> V_62 ) ;
if ( F_16 ( V_25 || V_51 -> V_62 ) )
return V_25 ;
V_51 -> V_63 = true ;
return F_23 ( V_3 , V_51 ) ;
}
static void F_27 ( struct V_64 * V_65 , struct V_2 * V_3 ,
void * V_66 )
{
F_5 ( V_3 , 0 ) ;
}
static void F_28 ( struct V_64 * V_65 , struct V_2 * V_3 ,
const struct V_50 * V_51 )
{
const struct V_43 * V_44 = F_29 ( V_51 ) ;
struct V_36 V_37 = {
. V_39 = V_51 -> V_52 -> V_67 ,
. V_38 = V_51 -> V_61 ,
} ;
F_18 ( V_3 , & V_37 ) ;
F_22 ( V_3 , V_51 , & V_37 ) ;
F_21 ( V_3 , V_44 , & V_37 ) ;
F_19 ( & V_37 ) ;
}
static int F_30 ( struct V_64 * V_65 , struct V_2 * V_3 ,
void * V_66 )
{
return 0 ;
}
static int F_31 ( struct V_64 * V_68 ,
struct V_2 * V_3 ,
struct V_50 * V_51 )
{
struct V_36 V_37 ;
int V_25 ;
V_25 = F_20 ( V_3 , & V_37 ) ;
if ( F_16 ( V_25 ) )
return V_25 ;
if ( V_51 != NULL ) {
V_25 = F_26 ( V_3 , V_51 ) ;
if ( F_16 ( V_25 || V_51 -> V_62 ) )
return V_25 ;
}
return F_14 ( V_3 , V_45 , & V_51 -> V_62 ) ;
}
static void F_32 ( struct V_2 * V_3 ,
const struct V_69 * V_70 ,
struct V_36 * V_37 )
{
T_1 * V_5 ;
F_8 ( V_37 -> V_38 == 0 ) ;
V_5 = F_5 ( V_3 , 5 * 4 ) ;
* V_5 ++ = F_6 ( V_71 ) ;
* V_5 ++ = F_6 ( V_70 -> V_72 ) ;
* V_5 ++ = F_6 ( V_73 ) ;
* V_5 ++ = F_6 ( 1 ) ;
* V_5 = F_6 ( V_74 ) ;
F_7 ( V_3 , & V_70 -> V_75 . V_48 -> V_49 ) ;
V_5 = F_5 ( V_3 , 2 * 8 ) ;
V_5 = F_33 ( V_5 , 0 ) ;
F_33 ( V_5 , V_76 ) ;
F_10 ( V_3 , & V_70 -> V_77 ) ;
V_37 -> V_41 ++ ;
}
static void F_34 ( struct V_64 * V_65 ,
struct V_2 * V_3 ,
const struct V_50 * V_51 )
{
const struct V_69 * V_70 =
F_35 ( V_51 , struct V_69 , V_78 ) ;
struct V_36 V_37 = {
. V_39 = 0 ,
. V_38 = V_51 -> V_61 ,
} ;
F_18 ( V_3 , & V_37 ) ;
F_22 ( V_3 , V_51 , & V_37 ) ;
F_32 ( V_3 , V_70 , & V_37 ) ;
F_19 ( & V_37 ) ;
}
static int F_36 ( struct V_64 * V_68 ,
struct V_2 * V_3 ,
struct V_50 * V_51 )
{
struct V_36 V_37 ;
int V_25 ;
V_25 = F_20 ( V_3 , & V_37 ) ;
if ( F_16 ( V_25 ) )
return V_25 ;
if ( V_51 ) {
V_25 = F_26 ( V_3 , V_51 ) ;
if ( F_16 ( V_25 || V_51 -> V_62 ) )
return V_25 ;
}
return F_14 ( V_3 , V_71 , & V_51 -> V_62 ) ;
}
static int F_37 ( struct V_79 * V_79 )
{
struct V_80 * V_81 = F_38 ( V_79 , V_82 ) ;
return F_39 ( V_81 -> V_83 / 10 , ( V_84 ) 1 ) * V_85 ;
}
int F_40 ( void )
{
if ( V_86 )
return 0 ;
V_86 = F_41 ( L_9 ) ;
if ( ! V_86 )
return - V_87 ;
return 0 ;
}
static struct V_88 * F_42 ( struct V_89 * V_90 , struct V_91 * V_92 , struct V_20 * V_93 )
{
if ( V_90 -> V_94 == 0 ) {
return F_43 ( V_86 ) ;
} else {
struct V_95 * V_96 = V_92 -> V_97 ;
struct V_98 V_99 = {} ;
V_99 . V_100 = V_93 -> V_101 . V_100 ;
V_99 . V_102 = V_93 -> V_101 . V_102 ;
return V_96 -> V_103 -> V_104 ( V_92 -> V_97 , & V_99 , 0 ) ;
}
}
static struct V_91 * F_44 ( struct V_105 * args )
{
struct V_106 * V_107 ;
if ( args -> V_108 != V_109 )
return F_45 ( args ) ;
V_107 = args -> V_110 -> V_111 ;
if ( V_107 ) {
F_46 ( V_107 ) ;
return F_47 ( args , V_107 ) ;
}
return F_45 ( args ) ;
}
static int F_48 ( struct V_89 * V_90 , struct V_112 * V_113 , struct V_20 * V_93 )
{
int V_114 = F_37 ( V_90 -> V_79 ) ;
struct V_115 V_116 = {
. V_117 = V_114 ,
. V_118 = 0 ,
. V_119 = V_114 ,
} ;
struct V_105 args = {
. V_79 = V_90 -> V_79 ,
. V_120 = (struct V_121 * ) & V_113 -> V_122 ,
. V_123 = V_113 -> V_124 ,
. V_125 = (struct V_121 * ) & V_113 -> V_126 ,
. V_127 = & V_116 ,
. V_128 = & V_129 ,
. V_130 = 0 ,
. V_131 = ( V_132 | V_133 ) ,
} ;
struct V_91 * V_92 ;
struct V_88 * V_134 ;
if ( V_90 -> V_94 == 0 ) {
if ( ! V_90 -> V_135 . V_136 &&
( V_90 -> V_135 . V_137 >= V_138 ) )
return - V_139 ;
args . V_140 = V_90 -> V_135 . V_136 ;
args . V_141 = V_113 -> V_142 ;
args . V_108 = V_143 ;
args . V_144 = V_90 -> V_135 . V_137 ;
V_90 -> V_67 = V_113 -> V_145 ;
} else {
if ( ! V_113 -> V_146 )
return - V_139 ;
V_90 -> V_147 . V_146 = V_113 -> V_146 ;
V_90 -> V_53 = V_93 ;
args . V_110 = V_113 -> V_146 ;
args . V_141 = V_90 -> V_53 -> V_148 ;
args . V_108 = V_113 -> V_146 -> V_149 -> V_150 |
V_151 ;
args . V_144 = V_93 -> V_101 . V_152 ;
}
V_92 = F_44 ( & args ) ;
if ( F_49 ( V_92 ) ) {
F_2 ( L_10 ,
F_50 ( V_92 ) ) ;
return F_50 ( V_92 ) ;
}
V_134 = F_42 ( V_90 , V_92 , V_93 ) ;
if ( F_49 ( V_134 ) ) {
F_51 ( V_92 ) ;
return F_50 ( V_134 ) ;
}
V_90 -> V_153 = V_92 ;
V_90 -> V_154 = V_134 ;
return 0 ;
}
static void F_52 ( struct V_89 * V_90 , int V_155 )
{
F_2 ( L_11 ,
( int ) V_90 -> V_156 . V_157 , V_90 -> V_156 . V_24 , V_155 ) ;
}
static void F_53 ( struct V_89 * V_90 , int V_155 )
{
V_90 -> V_158 = V_159 ;
F_52 ( V_90 , V_155 ) ;
}
static void F_25 ( struct V_89 * V_90 , int V_155 )
{
V_90 -> V_158 = V_160 ;
F_52 ( V_90 , V_155 ) ;
}
static void F_54 ( struct V_161 * V_162 , void * V_163 )
{
struct V_89 * V_90 = F_35 ( V_163 , struct V_89 , V_164 ) ;
if ( V_162 -> V_165 )
F_53 ( V_90 , V_162 -> V_165 ) ;
else
V_90 -> V_158 = V_166 ;
}
void F_55 ( struct V_89 * V_90 )
{
V_90 -> V_158 = V_167 ;
F_56 ( V_168 , & V_90 -> V_169 ) ;
F_57 ( & V_90 -> V_164 ) ;
}
void F_58 ( struct V_89 * V_90 )
{
F_55 ( V_90 ) ;
F_59 ( V_170 ) ;
}
void F_60 ( struct V_89 * V_90 , struct V_112 * V_113 )
{
V_90 -> V_158 = V_167 ;
F_61 ( & V_90 -> V_171 ) ;
memcpy ( & V_90 -> V_147 , V_113 , sizeof( struct V_112 ) ) ;
F_62 ( & V_90 -> V_171 ) ;
}
static bool F_63 ( struct V_89 * V_90 , struct V_161 * V_162 )
{
if ( F_64 ( 0 , & V_90 -> V_172 ) != 0 ) {
F_65 ( & V_90 -> V_173 , V_162 , NULL ) ;
if ( F_64 ( 0 , & V_90 -> V_172 ) != 0 ) {
F_2 ( L_12 , V_34 ) ;
return false ;
}
F_66 ( & V_90 -> V_173 , V_162 ) ;
}
return true ;
}
static void F_67 ( struct V_161 * V_162 , void * V_163 )
{
struct V_50 * V_51 = V_163 ;
struct V_89 * V_90 = V_51 -> V_52 ;
T_2 V_38 = V_90 -> V_94 ;
V_51 -> V_61 = V_38 ;
V_51 -> V_63 = false ;
V_51 -> V_62 = 0 ;
if ( V_38 ) {
if ( ! F_63 ( V_90 , V_162 ) )
return;
}
F_68 ( V_162 ) ;
}
static void F_69 ( struct V_161 * V_162 , void * V_163 )
{
struct V_50 * V_51 = V_163 ;
struct V_89 * V_90 = V_51 -> V_52 ;
F_2 ( L_13 , V_34 ,
V_90 -> V_94 ) ;
if ( V_90 -> V_94 ) {
if ( V_51 -> V_63 )
++ V_90 -> V_53 -> V_55 ;
F_70 ( 0 , & V_90 -> V_172 ) ;
F_71 ( & V_90 -> V_173 ) ;
F_2 ( L_14 , V_34 ,
V_90 -> V_53 -> V_55 ) ;
}
if ( V_162 -> V_174 & V_175 ) {
V_162 -> V_165 = 0 ;
V_51 -> V_176 = true ;
return;
}
if ( V_51 -> V_62 ) {
F_72 ( V_162 -> V_165 ) ;
V_162 -> V_165 = V_51 -> V_62 ;
}
switch ( V_51 -> V_177 -> V_178 ( V_51 , V_162 ) ) {
case 0 :
V_162 -> V_165 = 0 ;
F_73 ( V_162 ) ;
return;
case 1 :
break;
case - 1 :
F_53 ( V_90 , V_162 -> V_165 ) ;
break;
default:
F_74 () ;
}
}
static void F_75 ( void * V_163 )
{
struct V_50 * V_51 = V_163 ;
if ( V_51 -> V_176 )
F_57 ( V_51 ) ;
else
V_51 -> V_177 -> V_179 ( V_51 ) ;
}
int F_76 ( void )
{
V_170 = F_77 ( L_15 ) ;
if ( ! V_170 )
return - V_87 ;
return 0 ;
}
void F_78 ( void )
{
F_79 ( V_170 ) ;
}
void F_80 ( struct V_89 * V_90 )
{
F_56 ( V_180 , & V_90 -> V_169 ) ;
F_57 ( & V_90 -> V_164 ) ;
F_59 ( V_170 ) ;
}
static struct V_181 * F_81 ( struct V_89 * V_90 )
{
struct V_20 * V_182 ;
struct V_181 * V_183 ;
F_82 (s, &clp->cl_sessions, se_perclnt) {
F_82 (c, &s->se_conns, cn_persession) {
if ( V_183 -> V_184 & V_185 )
return V_183 ;
}
}
return NULL ;
}
static void F_83 ( struct V_50 * V_51 )
{
struct V_112 V_113 ;
struct V_89 * V_90 = V_51 -> V_52 ;
struct V_20 * V_93 = NULL ;
struct V_181 * V_183 ;
int V_186 ;
if ( V_90 -> V_153 ) {
F_51 ( V_90 -> V_153 ) ;
V_90 -> V_153 = NULL ;
F_84 ( V_90 -> V_154 ) ;
V_90 -> V_154 = NULL ;
}
if ( V_90 -> V_147 . V_146 ) {
F_85 ( V_90 -> V_147 . V_146 ) ;
V_90 -> V_147 . V_146 = NULL ;
}
if ( F_86 ( V_180 , & V_90 -> V_169 ) )
return;
F_61 ( & V_90 -> V_171 ) ;
F_8 ( ! ( V_90 -> V_169 & V_187 ) ) ;
F_70 ( V_168 , & V_90 -> V_169 ) ;
memcpy ( & V_113 , & V_51 -> V_52 -> V_147 , sizeof( struct V_112 ) ) ;
V_183 = F_81 ( V_90 ) ;
if ( V_183 ) {
F_87 ( V_183 -> V_188 ) ;
V_113 . V_146 = V_183 -> V_188 ;
V_93 = V_183 -> V_189 ;
}
F_62 ( & V_90 -> V_171 ) ;
V_186 = F_48 ( V_90 , & V_113 , V_93 ) ;
if ( V_186 ) {
F_53 ( V_90 , V_186 ) ;
return;
}
}
static void
F_88 ( struct V_190 * V_191 )
{
struct V_50 * V_51 =
F_35 ( V_191 , struct V_50 , V_192 ) ;
struct V_89 * V_90 = V_51 -> V_52 ;
struct V_91 * V_193 ;
if ( V_51 -> V_176 ) {
V_51 -> V_176 = false ;
} else {
if ( V_51 -> V_177 && V_51 -> V_177 -> V_194 )
V_51 -> V_177 -> V_194 ( V_51 ) ;
}
if ( V_90 -> V_169 & V_187 )
F_83 ( V_51 ) ;
V_193 = V_90 -> V_153 ;
if ( ! V_193 ) {
if ( V_51 -> V_177 && V_51 -> V_177 -> V_179 )
V_51 -> V_177 -> V_179 ( V_51 ) ;
return;
}
if ( ! V_51 -> V_177 && V_90 -> V_94 ) {
V_90 -> V_158 = V_166 ;
return;
}
V_51 -> V_195 . V_88 = V_90 -> V_154 ;
F_89 ( V_193 , & V_51 -> V_195 , V_196 | V_197 ,
V_51 -> V_177 ? & V_198 : & V_199 , V_51 ) ;
}
void F_90 ( struct V_50 * V_51 , struct V_89 * V_90 ,
struct V_200 * V_201 , enum V_202 V_8 )
{
V_51 -> V_52 = V_90 ;
V_51 -> V_195 . V_203 = & V_204 [ V_8 ] ;
V_51 -> V_195 . V_205 = V_51 ;
V_51 -> V_195 . V_206 = V_51 ;
V_51 -> V_177 = V_201 ;
F_91 ( & V_51 -> V_192 , F_88 ) ;
V_51 -> V_62 = 0 ;
V_51 -> V_63 = false ;
V_51 -> V_176 = false ;
}
void F_57 ( struct V_50 * V_51 )
{
F_92 ( V_170 , & V_51 -> V_192 ) ;
}
