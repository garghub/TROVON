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
V_51 -> V_61 = V_25 ;
return V_25 ;
V_32:
F_1 ( V_34 , V_3 ) ;
V_25 = - V_35 ;
goto V_60;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_50 * V_51 )
{
int V_25 ;
if ( V_51 -> V_62 == 0 )
return 0 ;
V_25 = F_14 ( V_3 , V_54 , & V_51 -> V_61 ) ;
if ( F_16 ( V_25 || V_51 -> V_61 ) )
return V_25 ;
return F_23 ( V_3 , V_51 ) ;
}
static void F_26 ( struct V_63 * V_64 , struct V_2 * V_3 ,
void * V_65 )
{
F_5 ( V_3 , 0 ) ;
}
static void F_27 ( struct V_63 * V_64 , struct V_2 * V_3 ,
const struct V_50 * V_51 )
{
const struct V_43 * V_44 = F_28 ( V_51 ) ;
struct V_36 V_37 = {
. V_39 = V_51 -> V_52 -> V_66 ,
. V_38 = V_51 -> V_62 ,
} ;
F_18 ( V_3 , & V_37 ) ;
F_22 ( V_3 , V_51 , & V_37 ) ;
F_21 ( V_3 , V_44 , & V_37 ) ;
F_19 ( & V_37 ) ;
}
static int F_29 ( struct V_63 * V_64 , struct V_2 * V_3 ,
void * V_65 )
{
return 0 ;
}
static int F_30 ( struct V_63 * V_67 ,
struct V_2 * V_3 ,
struct V_50 * V_51 )
{
struct V_36 V_37 ;
int V_25 ;
V_25 = F_20 ( V_3 , & V_37 ) ;
if ( F_16 ( V_25 ) )
return V_25 ;
if ( V_51 != NULL ) {
V_25 = F_25 ( V_3 , V_51 ) ;
if ( F_16 ( V_25 || V_51 -> V_61 ) )
return V_25 ;
}
return F_14 ( V_3 , V_45 , & V_51 -> V_68 ) ;
}
static void F_31 ( struct V_2 * V_3 ,
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
V_5 = F_32 ( V_5 , 0 ) ;
F_32 ( V_5 , V_76 ) ;
F_10 ( V_3 , & V_70 -> V_77 ) ;
V_37 -> V_41 ++ ;
}
static void F_33 ( struct V_63 * V_64 ,
struct V_2 * V_3 ,
const struct V_50 * V_51 )
{
const struct V_69 * V_70 =
F_34 ( V_51 , struct V_69 , V_78 ) ;
struct V_36 V_37 = {
. V_39 = 0 ,
. V_38 = V_51 -> V_62 ,
} ;
F_18 ( V_3 , & V_37 ) ;
F_22 ( V_3 , V_51 , & V_37 ) ;
F_31 ( V_3 , V_70 , & V_37 ) ;
F_19 ( & V_37 ) ;
}
static int F_35 ( struct V_63 * V_67 ,
struct V_2 * V_3 ,
struct V_50 * V_51 )
{
struct V_36 V_37 ;
int V_25 ;
V_25 = F_20 ( V_3 , & V_37 ) ;
if ( F_16 ( V_25 ) )
return V_25 ;
if ( V_51 ) {
V_25 = F_25 ( V_3 , V_51 ) ;
if ( F_16 ( V_25 || V_51 -> V_61 ) )
return V_25 ;
}
return F_14 ( V_3 , V_71 , & V_51 -> V_68 ) ;
}
static int F_36 ( struct V_79 * V_79 )
{
struct V_80 * V_81 = F_37 ( V_79 , V_82 ) ;
return F_38 ( V_81 -> V_83 / 10 , ( V_84 ) 1 ) * V_85 ;
}
int F_39 ( void )
{
if ( V_86 )
return 0 ;
V_86 = F_40 ( L_9 ) ;
if ( ! V_86 )
return - V_87 ;
return 0 ;
}
static struct V_88 * F_41 ( struct V_89 * V_90 , struct V_91 * V_92 , struct V_20 * V_93 )
{
if ( V_90 -> V_94 == 0 ) {
return F_42 ( V_86 ) ;
} else {
struct V_95 * V_96 = V_92 -> V_97 ;
struct V_98 V_99 = {} ;
V_99 . V_100 = V_93 -> V_101 . V_100 ;
V_99 . V_102 = V_93 -> V_101 . V_102 ;
return V_96 -> V_103 -> V_104 ( V_92 -> V_97 , & V_99 , 0 ) ;
}
}
static int F_43 ( struct V_89 * V_90 , struct V_105 * V_106 , struct V_20 * V_93 )
{
int V_107 = F_36 ( V_90 -> V_79 ) ;
struct V_108 V_109 = {
. V_110 = V_107 ,
. V_111 = 0 ,
. V_112 = V_107 ,
} ;
struct V_113 args = {
. V_79 = V_90 -> V_79 ,
. V_114 = (struct V_115 * ) & V_106 -> V_116 ,
. V_117 = V_106 -> V_118 ,
. V_119 = (struct V_115 * ) & V_106 -> V_120 ,
. V_121 = & V_109 ,
. V_122 = & V_123 ,
. V_124 = 0 ,
. V_125 = ( V_126 | V_127 ) ,
} ;
struct V_91 * V_92 ;
struct V_88 * V_128 ;
if ( V_90 -> V_94 == 0 ) {
if ( ! V_90 -> V_129 . V_130 &&
( V_90 -> V_129 . V_131 >= V_132 ) )
return - V_133 ;
args . V_134 = V_90 -> V_129 . V_130 ;
args . V_135 = V_106 -> V_136 ;
args . V_137 = V_138 ;
args . V_139 = V_90 -> V_129 . V_131 ;
V_90 -> V_66 = V_106 -> V_140 ;
} else {
if ( ! V_106 -> V_141 )
return - V_133 ;
V_90 -> V_142 . V_141 = V_106 -> V_141 ;
V_90 -> V_53 = V_93 ;
args . V_143 = V_106 -> V_141 ;
args . V_135 = V_90 -> V_53 -> V_144 ;
args . V_137 = V_106 -> V_141 -> V_145 -> V_146 |
V_147 ;
args . V_139 = V_93 -> V_101 . V_148 ;
}
V_92 = F_44 ( & args ) ;
if ( F_45 ( V_92 ) ) {
F_2 ( L_10 ,
F_46 ( V_92 ) ) ;
return F_46 ( V_92 ) ;
}
V_128 = F_41 ( V_90 , V_92 , V_93 ) ;
if ( F_45 ( V_128 ) ) {
F_47 ( V_92 ) ;
return F_46 ( V_128 ) ;
}
V_90 -> V_149 = V_92 ;
V_90 -> V_150 = V_128 ;
return 0 ;
}
static void F_48 ( struct V_89 * V_90 , int V_151 )
{
F_2 ( L_11 ,
( int ) V_90 -> V_152 . V_153 , V_90 -> V_152 . V_24 , V_151 ) ;
}
static void F_49 ( struct V_89 * V_90 , int V_151 )
{
if ( F_50 ( V_154 , & V_90 -> V_155 ) )
return;
V_90 -> V_156 = V_157 ;
F_48 ( V_90 , V_151 ) ;
}
static void F_51 ( struct V_89 * V_90 , int V_151 )
{
if ( F_50 ( V_154 , & V_90 -> V_155 ) )
return;
V_90 -> V_156 = V_158 ;
F_48 ( V_90 , V_151 ) ;
}
static void F_52 ( struct V_159 * V_160 , void * V_161 )
{
struct V_89 * V_90 = F_34 ( V_161 , struct V_89 , V_162 ) ;
if ( V_160 -> V_163 )
F_49 ( V_90 , V_160 -> V_163 ) ;
else
V_90 -> V_156 = V_164 ;
}
void F_53 ( struct V_89 * V_90 )
{
V_90 -> V_156 = V_165 ;
F_54 ( V_154 , & V_90 -> V_155 ) ;
F_55 ( & V_90 -> V_162 ) ;
}
void F_56 ( struct V_89 * V_90 )
{
F_53 ( V_90 ) ;
F_57 ( V_166 ) ;
}
void F_58 ( struct V_89 * V_90 , struct V_105 * V_106 )
{
V_90 -> V_156 = V_165 ;
F_59 ( & V_90 -> V_167 ) ;
memcpy ( & V_90 -> V_142 , V_106 , sizeof( struct V_105 ) ) ;
F_60 ( & V_90 -> V_167 ) ;
}
static bool F_61 ( struct V_89 * V_90 , struct V_159 * V_160 )
{
if ( F_62 ( 0 , & V_90 -> V_168 ) != 0 ) {
F_63 ( & V_90 -> V_169 , V_160 , NULL ) ;
if ( F_62 ( 0 , & V_90 -> V_168 ) != 0 ) {
F_2 ( L_12 , V_34 ) ;
return false ;
}
F_64 ( & V_90 -> V_169 , V_160 ) ;
}
return true ;
}
static void F_65 ( struct V_159 * V_160 , void * V_161 )
{
struct V_50 * V_51 = V_161 ;
struct V_89 * V_90 = V_51 -> V_52 ;
T_2 V_38 = V_90 -> V_94 ;
V_51 -> V_62 = V_38 ;
V_51 -> V_61 = 1 ;
V_51 -> V_68 = 0 ;
if ( V_38 ) {
if ( ! F_61 ( V_90 , V_160 ) )
return;
}
F_66 ( V_160 ) ;
}
static bool F_67 ( struct V_159 * V_160 , struct V_50 * V_51 )
{
struct V_89 * V_90 = V_51 -> V_52 ;
struct V_20 * V_21 = V_90 -> V_53 ;
bool V_170 = true ;
if ( ! V_90 -> V_94 ) {
if ( V_160 -> V_171 & V_172 )
goto V_173;
return true ;
}
switch ( V_51 -> V_61 ) {
case 0 :
++ V_21 -> V_55 ;
break;
case - V_59 :
++ V_21 -> V_55 ;
case 1 :
case - V_174 :
F_51 ( V_51 -> V_52 , V_51 -> V_61 ) ;
V_170 = false ;
break;
case - V_175 :
if ( ! F_68 ( V_160 ) )
goto V_60;
F_69 ( V_160 , 2 * V_85 ) ;
return false ;
case - V_176 :
goto V_177;
case - V_178 :
if ( V_21 -> V_55 != 1 ) {
V_21 -> V_55 = 1 ;
goto V_177;
}
break;
default:
F_2 ( L_13 , V_34 ,
V_51 -> V_61 ) ;
}
F_70 ( 0 , & V_90 -> V_168 ) ;
F_71 ( & V_90 -> V_169 ) ;
F_2 ( L_14 , V_34 ,
V_90 -> V_53 -> V_55 ) ;
if ( V_160 -> V_171 & V_172 )
goto V_173;
V_60:
return V_170 ;
V_177:
if ( F_72 ( V_160 ) )
V_170 = false ;
goto V_60;
V_173:
V_160 -> V_163 = 0 ;
V_51 -> V_179 = true ;
return false ;
}
static void F_73 ( struct V_159 * V_160 , void * V_161 )
{
struct V_50 * V_51 = V_161 ;
struct V_89 * V_90 = V_51 -> V_52 ;
F_2 ( L_15 , V_34 ,
V_90 -> V_94 ) ;
if ( ! F_67 ( V_160 , V_51 ) )
return;
if ( V_51 -> V_68 ) {
F_74 ( V_160 -> V_163 ) ;
V_160 -> V_163 = V_51 -> V_68 ;
}
switch ( V_51 -> V_180 -> V_181 ( V_51 , V_160 ) ) {
case 0 :
V_160 -> V_163 = 0 ;
F_72 ( V_160 ) ;
return;
case 1 :
break;
case - 1 :
F_49 ( V_90 , V_160 -> V_163 ) ;
break;
default:
F_75 () ;
}
}
static void F_76 ( void * V_161 )
{
struct V_50 * V_51 = V_161 ;
if ( V_51 -> V_179 )
F_55 ( V_51 ) ;
else
V_51 -> V_180 -> V_182 ( V_51 ) ;
}
int F_77 ( void )
{
V_166 = F_78 ( L_16 ) ;
if ( ! V_166 )
return - V_87 ;
return 0 ;
}
void F_79 ( void )
{
F_80 ( V_166 ) ;
}
void F_81 ( struct V_89 * V_90 )
{
F_54 ( V_183 , & V_90 -> V_155 ) ;
F_55 ( & V_90 -> V_162 ) ;
F_57 ( V_166 ) ;
}
static struct V_184 * F_82 ( struct V_89 * V_90 )
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
struct V_105 V_106 ;
struct V_89 * V_90 = V_51 -> V_52 ;
struct V_20 * V_93 = NULL ;
struct V_184 * V_186 ;
int V_189 ;
if ( V_90 -> V_149 ) {
F_47 ( V_90 -> V_149 ) ;
V_90 -> V_149 = NULL ;
F_85 ( V_90 -> V_150 ) ;
V_90 -> V_150 = NULL ;
}
if ( V_90 -> V_142 . V_141 ) {
F_86 ( V_90 -> V_142 . V_141 ) ;
V_90 -> V_142 . V_141 = NULL ;
}
if ( F_50 ( V_183 , & V_90 -> V_155 ) )
return;
F_59 ( & V_90 -> V_167 ) ;
F_8 ( ! ( V_90 -> V_155 & V_190 ) ) ;
F_70 ( V_154 , & V_90 -> V_155 ) ;
memcpy ( & V_106 , & V_51 -> V_52 -> V_142 , sizeof( struct V_105 ) ) ;
V_186 = F_82 ( V_90 ) ;
if ( V_186 ) {
F_87 ( V_186 -> V_191 ) ;
V_106 . V_141 = V_186 -> V_191 ;
V_93 = V_186 -> V_192 ;
}
F_60 ( & V_90 -> V_167 ) ;
V_189 = F_43 ( V_90 , & V_106 , V_93 ) ;
if ( V_189 ) {
F_49 ( V_90 , V_189 ) ;
return;
}
}
static void
F_88 ( struct V_193 * V_194 )
{
struct V_50 * V_51 =
F_34 ( V_194 , struct V_50 , V_195 ) ;
struct V_89 * V_90 = V_51 -> V_52 ;
struct V_91 * V_196 ;
if ( V_51 -> V_179 ) {
V_51 -> V_179 = false ;
} else {
if ( V_51 -> V_180 && V_51 -> V_180 -> V_197 )
V_51 -> V_180 -> V_197 ( V_51 ) ;
}
if ( V_90 -> V_155 & V_190 )
F_84 ( V_51 ) ;
V_196 = V_90 -> V_149 ;
if ( ! V_196 ) {
if ( V_51 -> V_180 && V_51 -> V_180 -> V_182 )
V_51 -> V_180 -> V_182 ( V_51 ) ;
return;
}
if ( ! V_51 -> V_180 && V_90 -> V_94 ) {
V_90 -> V_156 = V_164 ;
return;
}
V_51 -> V_198 . V_88 = V_90 -> V_150 ;
F_89 ( V_196 , & V_51 -> V_198 , V_199 | V_200 ,
V_51 -> V_180 ? & V_201 : & V_202 , V_51 ) ;
}
void F_90 ( struct V_50 * V_51 , struct V_89 * V_90 ,
const struct V_203 * V_204 , enum V_205 V_8 )
{
V_51 -> V_52 = V_90 ;
V_51 -> V_198 . V_206 = & V_207 [ V_8 ] ;
V_51 -> V_198 . V_208 = V_51 ;
V_51 -> V_198 . V_209 = V_51 ;
V_51 -> V_180 = V_204 ;
F_91 ( & V_51 -> V_195 , F_88 ) ;
V_51 -> V_61 = 1 ;
V_51 -> V_68 = 0 ;
V_51 -> V_179 = false ;
}
void F_55 ( struct V_50 * V_51 )
{
F_92 ( V_166 , & V_51 -> V_195 ) ;
}
