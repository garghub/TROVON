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
return F_23 ( V_3 , V_51 ) ;
}
static void F_27 ( struct V_63 * V_64 , struct V_2 * V_3 ,
void * V_65 )
{
F_5 ( V_3 , 0 ) ;
}
static void F_28 ( struct V_63 * V_64 , struct V_2 * V_3 ,
const struct V_50 * V_51 )
{
const struct V_43 * V_44 = F_29 ( V_51 ) ;
struct V_36 V_37 = {
. V_39 = V_51 -> V_52 -> V_66 ,
. V_38 = V_51 -> V_61 ,
} ;
F_18 ( V_3 , & V_37 ) ;
F_22 ( V_3 , V_51 , & V_37 ) ;
F_21 ( V_3 , V_44 , & V_37 ) ;
F_19 ( & V_37 ) ;
}
static int F_30 ( struct V_63 * V_64 , struct V_2 * V_3 ,
void * V_65 )
{
return 0 ;
}
static int F_31 ( struct V_63 * V_67 ,
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
const struct V_68 * V_69 ,
struct V_36 * V_37 )
{
T_1 * V_5 ;
F_8 ( V_37 -> V_38 == 0 ) ;
V_5 = F_5 ( V_3 , 5 * 4 ) ;
* V_5 ++ = F_6 ( V_70 ) ;
* V_5 ++ = F_6 ( V_69 -> V_71 ) ;
* V_5 ++ = F_6 ( V_72 ) ;
* V_5 ++ = F_6 ( 1 ) ;
* V_5 = F_6 ( V_73 ) ;
F_7 ( V_3 , & V_69 -> V_74 . V_48 -> V_49 ) ;
V_5 = F_5 ( V_3 , 2 * 8 ) ;
V_5 = F_33 ( V_5 , 0 ) ;
F_33 ( V_5 , V_75 ) ;
F_10 ( V_3 , & V_69 -> V_76 ) ;
V_37 -> V_41 ++ ;
}
static void F_34 ( struct V_63 * V_64 ,
struct V_2 * V_3 ,
const struct V_50 * V_51 )
{
const struct V_68 * V_69 =
F_35 ( V_51 , struct V_68 , V_77 ) ;
struct V_36 V_37 = {
. V_39 = 0 ,
. V_38 = V_51 -> V_61 ,
} ;
F_18 ( V_3 , & V_37 ) ;
F_22 ( V_3 , V_51 , & V_37 ) ;
F_32 ( V_3 , V_69 , & V_37 ) ;
F_19 ( & V_37 ) ;
}
static int F_36 ( struct V_63 * V_67 ,
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
return F_14 ( V_3 , V_70 , & V_51 -> V_62 ) ;
}
static int F_37 ( struct V_78 * V_78 )
{
struct V_79 * V_80 = F_38 ( V_78 , V_81 ) ;
return F_39 ( V_80 -> V_82 / 10 , ( V_83 ) 1 ) * V_84 ;
}
int F_40 ( void )
{
if ( V_85 )
return 0 ;
V_85 = F_41 ( L_9 ) ;
if ( ! V_85 )
return - V_86 ;
return 0 ;
}
static struct V_87 * F_42 ( struct V_88 * V_89 , struct V_90 * V_91 , struct V_20 * V_92 )
{
if ( V_89 -> V_93 == 0 ) {
return F_43 ( V_85 ) ;
} else {
struct V_94 * V_95 = V_91 -> V_96 ;
struct V_97 V_98 = {} ;
V_98 . V_99 = V_92 -> V_100 . V_99 ;
V_98 . V_101 = V_92 -> V_100 . V_101 ;
return V_95 -> V_102 -> V_103 ( V_91 -> V_96 , & V_98 , 0 ) ;
}
}
static struct V_90 * F_44 ( struct V_104 * args )
{
struct V_105 * V_106 ;
if ( args -> V_107 != V_108 )
return F_45 ( args ) ;
V_106 = args -> V_109 -> V_110 ;
if ( V_106 ) {
F_46 ( V_106 ) ;
return F_47 ( args , V_106 ) ;
}
return F_45 ( args ) ;
}
static int F_48 ( struct V_88 * V_89 , struct V_111 * V_112 , struct V_20 * V_92 )
{
int V_113 = F_37 ( V_89 -> V_78 ) ;
struct V_114 V_115 = {
. V_116 = V_113 ,
. V_117 = 0 ,
. V_118 = V_113 ,
} ;
struct V_104 args = {
. V_78 = V_89 -> V_78 ,
. V_119 = (struct V_120 * ) & V_112 -> V_121 ,
. V_122 = V_112 -> V_123 ,
. V_124 = (struct V_120 * ) & V_112 -> V_125 ,
. V_126 = & V_115 ,
. V_127 = & V_128 ,
. V_129 = 0 ,
. V_130 = ( V_131 | V_132 ) ,
} ;
struct V_90 * V_91 ;
struct V_87 * V_133 ;
if ( V_89 -> V_93 == 0 ) {
if ( ! V_89 -> V_134 . V_135 &&
( V_89 -> V_134 . V_136 >= V_137 ) )
return - V_138 ;
args . V_139 = V_89 -> V_134 . V_135 ;
args . V_140 = V_112 -> V_141 ;
args . V_107 = V_142 ;
args . V_143 = V_89 -> V_134 . V_136 ;
V_89 -> V_66 = V_112 -> V_144 ;
} else {
if ( ! V_112 -> V_145 )
return - V_138 ;
V_89 -> V_146 . V_145 = V_112 -> V_145 ;
V_89 -> V_53 = V_92 ;
args . V_109 = V_112 -> V_145 ;
args . V_140 = V_89 -> V_53 -> V_147 ;
args . V_107 = V_112 -> V_145 -> V_148 -> V_149 |
V_150 ;
args . V_143 = V_92 -> V_100 . V_151 ;
}
V_91 = F_44 ( & args ) ;
if ( F_49 ( V_91 ) ) {
F_2 ( L_10 ,
F_50 ( V_91 ) ) ;
return F_50 ( V_91 ) ;
}
V_133 = F_42 ( V_89 , V_91 , V_92 ) ;
if ( F_49 ( V_133 ) ) {
F_51 ( V_91 ) ;
return F_50 ( V_133 ) ;
}
V_89 -> V_152 = V_91 ;
V_89 -> V_153 = V_133 ;
return 0 ;
}
static void F_52 ( struct V_88 * V_89 , int V_154 )
{
F_2 ( L_11 ,
( int ) V_89 -> V_155 . V_156 , V_89 -> V_155 . V_24 , V_154 ) ;
}
static void F_53 ( struct V_88 * V_89 , int V_154 )
{
V_89 -> V_157 = V_158 ;
F_52 ( V_89 , V_154 ) ;
}
static void F_25 ( struct V_88 * V_89 , int V_154 )
{
V_89 -> V_157 = V_159 ;
F_52 ( V_89 , V_154 ) ;
}
static void F_54 ( struct V_160 * V_161 , void * V_162 )
{
struct V_88 * V_89 = F_35 ( V_162 , struct V_88 , V_163 ) ;
if ( V_161 -> V_164 )
F_53 ( V_89 , V_161 -> V_164 ) ;
else
V_89 -> V_157 = V_165 ;
}
void F_55 ( struct V_88 * V_89 )
{
V_89 -> V_157 = V_166 ;
F_56 ( V_167 , & V_89 -> V_168 ) ;
F_57 ( & V_89 -> V_163 ) ;
}
void F_58 ( struct V_88 * V_89 )
{
F_55 ( V_89 ) ;
F_59 ( V_169 ) ;
}
void F_60 ( struct V_88 * V_89 , struct V_111 * V_112 )
{
V_89 -> V_157 = V_166 ;
F_61 ( & V_89 -> V_170 ) ;
memcpy ( & V_89 -> V_146 , V_112 , sizeof( struct V_111 ) ) ;
F_62 ( & V_89 -> V_170 ) ;
}
static bool F_63 ( struct V_88 * V_89 , struct V_160 * V_161 )
{
if ( F_64 ( 0 , & V_89 -> V_171 ) != 0 ) {
F_65 ( & V_89 -> V_172 , V_161 , NULL ) ;
if ( F_64 ( 0 , & V_89 -> V_171 ) != 0 ) {
F_2 ( L_12 , V_34 ) ;
return false ;
}
F_66 ( & V_89 -> V_172 , V_161 ) ;
}
return true ;
}
static void F_67 ( struct V_160 * V_161 , void * V_162 )
{
struct V_50 * V_51 = V_162 ;
struct V_88 * V_89 = V_51 -> V_52 ;
T_2 V_38 = V_89 -> V_93 ;
V_51 -> V_61 = V_38 ;
if ( V_38 ) {
if ( ! F_63 ( V_89 , V_161 ) )
return;
}
F_68 ( V_161 ) ;
}
static void F_69 ( struct V_160 * V_161 , void * V_162 )
{
struct V_50 * V_51 = V_162 ;
struct V_88 * V_89 = V_51 -> V_52 ;
F_2 ( L_13 , V_34 ,
V_89 -> V_93 ) ;
if ( V_89 -> V_93 ) {
if ( ! V_161 -> V_164 )
++ V_89 -> V_53 -> V_55 ;
F_70 ( 0 , & V_89 -> V_171 ) ;
F_71 ( & V_89 -> V_172 ) ;
F_2 ( L_14 , V_34 ,
V_89 -> V_53 -> V_55 ) ;
}
if ( V_161 -> V_173 & V_174 ) {
V_161 -> V_164 = 0 ;
V_51 -> V_175 = true ;
return;
}
if ( V_51 -> V_62 ) {
F_72 ( V_161 -> V_164 ) ;
V_161 -> V_164 = V_51 -> V_62 ;
}
switch ( V_51 -> V_176 -> V_177 ( V_51 , V_161 ) ) {
case 0 :
V_161 -> V_164 = 0 ;
F_73 ( V_161 ) ;
return;
case 1 :
break;
case - 1 :
F_53 ( V_89 , V_161 -> V_164 ) ;
break;
default:
F_74 () ;
}
}
static void F_75 ( void * V_162 )
{
struct V_50 * V_51 = V_162 ;
if ( V_51 -> V_175 )
F_57 ( V_51 ) ;
else
V_51 -> V_176 -> V_178 ( V_51 ) ;
}
int F_76 ( void )
{
V_169 = F_77 ( L_15 ) ;
if ( ! V_169 )
return - V_86 ;
return 0 ;
}
void F_78 ( void )
{
F_79 ( V_169 ) ;
}
void F_80 ( struct V_88 * V_89 )
{
F_56 ( V_179 , & V_89 -> V_168 ) ;
F_57 ( & V_89 -> V_163 ) ;
F_59 ( V_169 ) ;
}
static struct V_180 * F_81 ( struct V_88 * V_89 )
{
struct V_20 * V_181 ;
struct V_180 * V_182 ;
F_82 (s, &clp->cl_sessions, se_perclnt) {
F_82 (c, &s->se_conns, cn_persession) {
if ( V_182 -> V_183 & V_184 )
return V_182 ;
}
}
return NULL ;
}
static void F_83 ( struct V_50 * V_51 )
{
struct V_111 V_112 ;
struct V_88 * V_89 = V_51 -> V_52 ;
struct V_20 * V_92 = NULL ;
struct V_180 * V_182 ;
int V_185 ;
if ( V_89 -> V_152 ) {
F_51 ( V_89 -> V_152 ) ;
V_89 -> V_152 = NULL ;
F_84 ( V_89 -> V_153 ) ;
V_89 -> V_153 = NULL ;
}
if ( V_89 -> V_146 . V_145 ) {
F_85 ( V_89 -> V_146 . V_145 ) ;
V_89 -> V_146 . V_145 = NULL ;
}
if ( F_86 ( V_179 , & V_89 -> V_168 ) )
return;
F_61 ( & V_89 -> V_170 ) ;
F_8 ( ! ( V_89 -> V_168 & V_186 ) ) ;
F_70 ( V_167 , & V_89 -> V_168 ) ;
memcpy ( & V_112 , & V_51 -> V_52 -> V_146 , sizeof( struct V_111 ) ) ;
V_182 = F_81 ( V_89 ) ;
if ( V_182 ) {
F_87 ( V_182 -> V_187 ) ;
V_112 . V_145 = V_182 -> V_187 ;
V_92 = V_182 -> V_188 ;
}
F_62 ( & V_89 -> V_170 ) ;
V_185 = F_48 ( V_89 , & V_112 , V_92 ) ;
if ( V_185 ) {
F_53 ( V_89 , V_185 ) ;
return;
}
}
static void
F_88 ( struct V_189 * V_190 )
{
struct V_50 * V_51 =
F_35 ( V_190 , struct V_50 , V_191 ) ;
struct V_88 * V_89 = V_51 -> V_52 ;
struct V_90 * V_192 ;
if ( V_51 -> V_175 ) {
V_51 -> V_175 = false ;
} else {
if ( V_51 -> V_176 && V_51 -> V_176 -> V_193 )
V_51 -> V_176 -> V_193 ( V_51 ) ;
}
if ( V_89 -> V_168 & V_186 )
F_83 ( V_51 ) ;
V_192 = V_89 -> V_152 ;
if ( ! V_192 ) {
if ( V_51 -> V_176 && V_51 -> V_176 -> V_178 )
V_51 -> V_176 -> V_178 ( V_51 ) ;
return;
}
if ( ! V_51 -> V_176 && V_89 -> V_93 ) {
V_89 -> V_157 = V_165 ;
return;
}
V_51 -> V_194 . V_87 = V_89 -> V_153 ;
F_89 ( V_192 , & V_51 -> V_194 , V_195 | V_196 ,
V_51 -> V_176 ? & V_197 : & V_198 , V_51 ) ;
}
void F_90 ( struct V_50 * V_51 , struct V_88 * V_89 ,
struct V_199 * V_200 , enum V_201 V_8 )
{
V_51 -> V_52 = V_89 ;
V_51 -> V_194 . V_202 = & V_203 [ V_8 ] ;
V_51 -> V_194 . V_204 = V_51 ;
V_51 -> V_194 . V_205 = V_51 ;
V_51 -> V_176 = V_200 ;
F_91 ( & V_51 -> V_191 , F_88 ) ;
V_51 -> V_62 = 0 ;
V_51 -> V_175 = false ;
}
void F_57 ( struct V_50 * V_51 )
{
F_92 ( V_169 , & V_51 -> V_191 ) ;
}
