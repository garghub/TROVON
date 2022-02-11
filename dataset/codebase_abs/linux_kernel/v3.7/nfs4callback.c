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
static int F_31 ( void )
{
return F_32 ( V_71 / 10 , ( V_72 ) 1 ) * V_73 ;
}
static int F_33 ( struct V_74 * V_75 , struct V_76 * V_77 , struct V_20 * V_78 )
{
struct V_79 V_80 = {
. V_81 = F_31 () ,
. V_82 = 0 ,
} ;
struct V_83 args = {
. V_84 = & V_85 ,
. V_86 = (struct V_87 * ) & V_77 -> V_88 ,
. V_89 = V_77 -> V_90 ,
. V_91 = (struct V_87 * ) & V_77 -> V_92 ,
. V_93 = & V_80 ,
. V_94 = & V_95 ,
. V_96 = 0 ,
. V_97 = ( V_98 | V_99 ) ,
} ;
struct V_100 * V_101 ;
if ( V_75 -> V_102 == 0 ) {
if ( ! V_75 -> V_103 . V_104 &&
( V_75 -> V_103 . V_105 >= V_106 ) )
return - V_107 ;
args . V_108 = V_75 -> V_103 . V_104 ;
args . V_109 = V_77 -> V_110 ,
args . V_111 = V_112 ;
args . V_113 = V_75 -> V_103 . V_105 ;
V_75 -> V_69 = V_77 -> V_114 ;
} else {
if ( ! V_77 -> V_115 )
return - V_107 ;
V_75 -> V_116 . V_115 = V_77 -> V_115 ;
V_75 -> V_53 = V_78 ;
args . V_117 = V_77 -> V_115 ;
args . V_109 = V_75 -> V_53 -> V_118 ;
args . V_111 = V_119 ;
args . V_113 = V_120 ;
}
V_101 = F_34 ( & args ) ;
if ( F_35 ( V_101 ) ) {
F_2 ( L_9 ,
F_36 ( V_101 ) ) ;
return F_36 ( V_101 ) ;
}
V_75 -> V_121 = V_101 ;
return 0 ;
}
static void F_37 ( struct V_74 * V_75 , int V_122 )
{
F_2 ( L_10 ,
( int ) V_75 -> V_123 . V_124 , V_75 -> V_123 . V_24 , V_122 ) ;
}
static void F_38 ( struct V_74 * V_75 , int V_122 )
{
V_75 -> V_125 = V_126 ;
F_37 ( V_75 , V_122 ) ;
}
static void F_25 ( struct V_74 * V_75 , int V_122 )
{
V_75 -> V_125 = V_127 ;
F_37 ( V_75 , V_122 ) ;
}
static void F_39 ( struct V_128 * V_129 , void * V_130 )
{
struct V_74 * V_75 = F_40 ( V_130 , struct V_74 , V_131 ) ;
if ( V_129 -> V_132 )
F_38 ( V_75 , V_129 -> V_132 ) ;
else
V_75 -> V_125 = V_133 ;
}
int F_41 ( void )
{
if ( V_134 )
return 0 ;
V_134 = F_42 ( L_11 ) ;
if ( ! V_134 )
return - V_135 ;
return 0 ;
}
static void F_43 ( struct V_50 * V_51 )
{
F_44 ( V_136 , & V_51 -> V_137 ) ;
}
static void F_45 ( struct V_74 * V_75 )
{
struct V_50 * V_51 = & V_75 -> V_131 ;
V_51 -> V_68 = NULL ;
V_51 -> V_52 = V_75 ;
V_51 -> V_138 . V_139 = & V_140 [ V_141 ] ;
V_51 -> V_138 . V_142 = NULL ;
V_51 -> V_138 . V_143 = NULL ;
V_51 -> V_138 . V_144 = V_134 ;
V_51 -> V_145 = & V_146 ;
F_43 ( V_51 ) ;
}
void F_46 ( struct V_74 * V_75 )
{
V_75 -> V_125 = V_147 ;
F_47 ( V_148 , & V_75 -> V_149 ) ;
F_45 ( V_75 ) ;
}
void F_48 ( struct V_74 * V_75 )
{
F_46 ( V_75 ) ;
F_49 ( V_136 ) ;
}
void F_50 ( struct V_74 * V_75 , struct V_76 * V_77 )
{
V_75 -> V_125 = V_147 ;
F_51 ( & V_75 -> V_150 ) ;
memcpy ( & V_75 -> V_116 , V_77 , sizeof( struct V_76 ) ) ;
F_52 ( & V_75 -> V_150 ) ;
}
static bool F_53 ( struct V_74 * V_75 , struct V_128 * V_129 )
{
if ( F_54 ( 0 , & V_75 -> V_151 ) != 0 ) {
F_55 ( & V_75 -> V_152 , V_129 , NULL ) ;
F_2 ( L_12 , V_35 ) ;
return false ;
}
return true ;
}
static void F_56 ( struct V_128 * V_129 , void * V_130 )
{
struct V_50 * V_51 = V_130 ;
struct V_44 * V_45 = F_40 ( V_51 , struct V_44 , V_153 ) ;
struct V_74 * V_75 = V_45 -> V_47 . V_154 ;
T_2 V_39 = V_75 -> V_102 ;
V_51 -> V_62 = V_39 ;
if ( V_39 ) {
if ( ! F_53 ( V_75 , V_129 ) )
return;
}
F_51 ( & V_75 -> V_150 ) ;
if ( F_57 ( & V_51 -> V_155 ) ) {
V_51 -> V_156 = false ;
F_58 ( & V_51 -> V_155 , & V_75 -> V_157 ) ;
}
F_52 ( & V_75 -> V_150 ) ;
F_59 ( V_129 ) ;
}
static void F_60 ( struct V_128 * V_129 , void * V_130 )
{
struct V_50 * V_51 = V_130 ;
struct V_44 * V_45 = F_40 ( V_51 , struct V_44 , V_153 ) ;
struct V_74 * V_75 = V_45 -> V_47 . V_154 ;
F_2 ( L_13 , V_35 ,
V_75 -> V_102 ) ;
if ( V_75 -> V_102 ) {
++ V_75 -> V_53 -> V_55 ;
F_61 ( 0 , & V_75 -> V_151 ) ;
F_62 ( & V_75 -> V_152 ) ;
F_2 ( L_14 , V_35 ,
V_75 -> V_53 -> V_55 ) ;
V_129 -> V_158 . V_143 = NULL ;
}
}
static void F_63 ( struct V_128 * V_129 , void * V_130 )
{
struct V_50 * V_51 = V_130 ;
struct V_44 * V_45 = F_40 ( V_51 , struct V_44 , V_153 ) ;
struct V_74 * V_75 = V_45 -> V_47 . V_154 ;
struct V_100 * V_159 = V_75 -> V_121 ;
F_60 ( V_129 , V_130 ) ;
if ( V_159 != V_129 -> V_160 ) {
return;
}
if ( V_51 -> V_156 )
return;
switch ( V_129 -> V_132 ) {
case 0 :
V_51 -> V_156 = true ;
return;
case - V_161 :
case - V_162 :
break;
default:
F_38 ( V_75 , V_129 -> V_132 ) ;
}
if ( V_45 -> V_163 -- ) {
F_64 ( V_129 , 2 * V_73 ) ;
V_129 -> V_132 = 0 ;
F_65 ( V_129 ) ;
return;
}
F_38 ( V_75 , V_129 -> V_132 ) ;
V_51 -> V_156 = true ;
}
static void F_66 ( void * V_130 )
{
struct V_50 * V_51 = V_130 ;
struct V_74 * V_75 = V_51 -> V_52 ;
struct V_44 * V_45 = F_40 ( V_51 , struct V_44 , V_153 ) ;
if ( V_51 -> V_156 ) {
F_51 ( & V_75 -> V_150 ) ;
F_67 ( & V_51 -> V_155 ) ;
F_52 ( & V_75 -> V_150 ) ;
F_68 ( V_45 ) ;
}
}
int F_69 ( void )
{
V_136 = F_70 ( L_15 ) ;
if ( ! V_136 )
return - V_135 ;
return 0 ;
}
void F_71 ( void )
{
F_72 ( V_136 ) ;
}
void F_73 ( struct V_74 * V_75 )
{
F_47 ( V_164 , & V_75 -> V_149 ) ;
F_45 ( V_75 ) ;
F_49 ( V_136 ) ;
}
static void F_74 ( struct V_50 * V_51 )
{
if ( V_51 -> V_145 -> V_165 )
V_51 -> V_145 -> V_165 ( V_51 ) ;
}
static struct V_166 * F_75 ( struct V_74 * V_75 )
{
struct V_20 * V_167 ;
struct V_166 * V_168 ;
F_76 (s, &clp->cl_sessions, se_perclnt) {
F_76 (c, &s->se_conns, cn_persession) {
if ( V_168 -> V_169 & V_170 )
return V_168 ;
}
}
return NULL ;
}
static void F_77 ( struct V_50 * V_51 )
{
struct V_76 V_77 ;
struct V_74 * V_75 = V_51 -> V_52 ;
struct V_20 * V_78 = NULL ;
struct V_166 * V_168 ;
int V_171 ;
if ( V_75 -> V_121 ) {
F_78 ( V_75 -> V_121 ) ;
V_75 -> V_121 = NULL ;
}
if ( V_75 -> V_116 . V_115 ) {
F_79 ( V_75 -> V_116 . V_115 ) ;
V_75 -> V_116 . V_115 = NULL ;
}
if ( F_80 ( V_164 , & V_75 -> V_149 ) )
return;
F_51 ( & V_75 -> V_150 ) ;
F_8 ( ! ( V_75 -> V_149 & V_172 ) ) ;
F_61 ( V_148 , & V_75 -> V_149 ) ;
memcpy ( & V_77 , & V_51 -> V_52 -> V_116 , sizeof( struct V_76 ) ) ;
V_168 = F_75 ( V_75 ) ;
if ( V_168 ) {
F_81 ( V_168 -> V_173 ) ;
V_77 . V_115 = V_168 -> V_173 ;
V_78 = V_168 -> V_174 ;
}
F_52 ( & V_75 -> V_150 ) ;
V_171 = F_33 ( V_75 , & V_77 , V_78 ) ;
if ( V_171 ) {
F_38 ( V_75 , V_171 ) ;
return;
}
F_76 (cb, &clp->cl_callbacks, cb_per_client)
F_43 ( V_51 ) ;
}
void F_82 ( struct V_175 * V_176 )
{
struct V_50 * V_51 = F_40 ( V_176 , struct V_50 , V_137 ) ;
struct V_74 * V_75 = V_51 -> V_52 ;
struct V_100 * V_177 ;
if ( V_75 -> V_149 & V_172 )
F_77 ( V_51 ) ;
V_177 = V_75 -> V_121 ;
if ( ! V_177 ) {
F_74 ( V_51 ) ;
return;
}
F_83 ( V_177 , & V_51 -> V_138 , V_178 | V_179 ,
V_51 -> V_145 , V_51 ) ;
}
void F_84 ( struct V_44 * V_45 )
{
struct V_50 * V_51 = & V_45 -> V_153 ;
struct V_74 * V_75 = V_45 -> V_47 . V_154 ;
V_45 -> V_163 = 1 ;
V_51 -> V_68 = V_45 ;
V_51 -> V_52 = V_75 ;
V_51 -> V_138 . V_139 = & V_140 [ V_180 ] ;
V_51 -> V_138 . V_142 = V_51 ;
V_51 -> V_138 . V_143 = V_51 ;
V_51 -> V_138 . V_144 = V_134 ;
V_51 -> V_145 = & V_181 ;
F_85 ( & V_51 -> V_155 ) ;
V_51 -> V_156 = true ;
F_43 ( & V_45 -> V_153 ) ;
}
