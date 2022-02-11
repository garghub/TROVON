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
F_10 ( V_3 , & V_45 -> V_47 ) ;
V_5 = F_5 ( V_3 , 4 ) ;
* V_5 ++ = V_6 ;
F_7 ( V_3 , & V_45 -> V_48 ) ;
V_38 -> V_42 ++ ;
}
static void F_22 ( struct V_2 * V_3 ,
const struct V_49 * V_50 ,
struct V_37 * V_38 )
{
struct V_20 * V_21 = V_50 -> V_51 -> V_52 ;
T_1 * V_5 ;
if ( V_38 -> V_39 == 0 )
return;
F_4 ( V_3 , V_53 ) ;
F_12 ( V_3 , V_21 ) ;
V_5 = F_5 ( V_3 , 4 + 4 + 4 + 4 + 4 ) ;
* V_5 ++ = F_6 ( V_21 -> V_54 ) ;
* V_5 ++ = V_6 ;
* V_5 ++ = V_6 ;
* V_5 ++ = V_6 ;
F_3 ( V_5 ) ;
V_38 -> V_42 ++ ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_49 * V_50 )
{
struct V_20 * V_21 = V_50 -> V_51 -> V_52 ;
struct V_55 V_56 ;
int V_25 ;
T_1 * V_5 ;
T_2 V_57 ;
V_25 = - V_58 ;
V_5 = F_15 ( V_3 , V_22 + 4 + 4 + 4 + 4 ) ;
if ( F_16 ( V_5 == NULL ) )
goto V_33;
memcpy ( V_56 . V_24 , V_5 , V_22 ) ;
if ( memcmp ( V_56 . V_24 , V_21 -> V_23 . V_24 ,
V_22 ) != 0 ) {
F_2 ( L_6 , V_35 ) ;
goto V_59;
}
V_5 += F_24 ( V_22 ) ;
V_57 = F_17 ( V_5 ++ ) ;
if ( V_57 != V_21 -> V_54 ) {
F_2 ( L_7 , V_35 ) ;
goto V_59;
}
V_57 = F_17 ( V_5 ++ ) ;
if ( V_57 != 0 ) {
F_2 ( L_8 , V_35 ) ;
goto V_59;
}
V_25 = 0 ;
V_59:
return V_25 ;
V_33:
F_1 ( V_35 , V_3 ) ;
return - V_36 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_49 * V_50 )
{
enum V_32 V_60 ;
int V_25 ;
if ( V_50 -> V_61 == 0 )
return 0 ;
V_25 = F_14 ( V_3 , V_53 , & V_60 ) ;
if ( F_16 ( V_25 ) )
goto V_59;
if ( F_16 ( V_60 != V_62 ) )
goto V_63;
V_25 = F_23 ( V_3 , V_50 ) ;
V_59:
return V_25 ;
V_63:
return F_13 ( V_60 ) ;
}
static void F_26 ( struct V_64 * V_65 , struct V_2 * V_3 ,
void * V_66 )
{
F_5 ( V_3 , 0 ) ;
}
static void F_27 ( struct V_64 * V_65 , struct V_2 * V_3 ,
const struct V_49 * V_50 )
{
const struct V_44 * args = V_50 -> V_67 ;
struct V_37 V_38 = {
. V_40 = V_50 -> V_51 -> V_68 ,
. V_39 = V_50 -> V_61 ,
} ;
F_18 ( V_3 , & V_38 ) ;
F_22 ( V_3 , V_50 , & V_38 ) ;
F_21 ( V_3 , args , & V_38 ) ;
F_19 ( & V_38 ) ;
}
static int F_28 ( struct V_64 * V_65 , struct V_2 * V_3 ,
void * V_66 )
{
return 0 ;
}
static int F_29 ( struct V_64 * V_69 ,
struct V_2 * V_3 ,
struct V_49 * V_50 )
{
struct V_37 V_38 ;
enum V_32 V_60 ;
int V_25 ;
V_25 = F_20 ( V_3 , & V_38 ) ;
if ( F_16 ( V_25 ) )
goto V_59;
if ( V_50 != NULL ) {
V_25 = F_25 ( V_3 , V_50 ) ;
if ( F_16 ( V_25 ) )
goto V_59;
}
V_25 = F_14 ( V_3 , V_46 , & V_60 ) ;
if ( F_16 ( V_25 ) )
goto V_59;
if ( F_16 ( V_60 != V_62 ) )
V_25 = F_13 ( V_60 ) ;
V_59:
return V_25 ;
}
static int F_30 ( void )
{
return F_31 ( V_70 / 10 , ( V_71 ) 1 ) * V_72 ;
}
static int F_32 ( struct V_73 * V_74 , struct V_75 * V_76 , struct V_20 * V_77 )
{
struct V_78 V_79 = {
. V_80 = F_30 () ,
. V_81 = 0 ,
} ;
struct V_82 args = {
. V_83 = & V_84 ,
. V_85 = (struct V_86 * ) & V_76 -> V_87 ,
. V_88 = V_76 -> V_89 ,
. V_90 = (struct V_86 * ) & V_76 -> V_91 ,
. V_92 = & V_79 ,
. V_93 = & V_94 ,
. V_95 = 0 ,
. V_96 = V_74 -> V_97 ,
. V_98 = ( V_99 | V_100 ) ,
} ;
struct V_101 * V_102 ;
if ( V_74 -> V_103 == 0 ) {
if ( ! V_74 -> V_104 && ( V_74 -> V_97 >= V_105 ) )
return - V_106 ;
args . V_107 = V_74 -> V_104 ;
args . V_108 = V_76 -> V_109 ,
args . V_110 = V_111 ;
V_74 -> V_68 = V_76 -> V_112 ;
} else {
if ( ! V_76 -> V_113 )
return - V_106 ;
V_74 -> V_114 . V_113 = V_76 -> V_113 ;
V_74 -> V_52 = V_77 ;
args . V_115 = V_76 -> V_113 ;
args . V_108 = V_74 -> V_52 -> V_116 ;
args . V_110 = V_117 ;
}
V_102 = F_33 ( & args ) ;
if ( F_34 ( V_102 ) ) {
F_2 ( L_9 ,
F_35 ( V_102 ) ) ;
return F_35 ( V_102 ) ;
}
V_74 -> V_118 = V_102 ;
return 0 ;
}
static void F_36 ( struct V_73 * V_74 , int V_119 )
{
F_2 ( L_10 ,
( int ) V_74 -> V_120 . V_121 , V_74 -> V_120 . V_24 , V_119 ) ;
}
static void F_37 ( struct V_73 * V_74 , int V_119 )
{
V_74 -> V_122 = V_123 ;
F_36 ( V_74 , V_119 ) ;
}
static void F_38 ( struct V_124 * V_125 , void * V_126 )
{
struct V_73 * V_74 = F_39 ( V_126 , struct V_73 , V_127 ) ;
if ( V_125 -> V_128 )
F_37 ( V_74 , V_125 -> V_128 ) ;
else
V_74 -> V_122 = V_129 ;
}
int F_40 ( void )
{
if ( V_130 )
return 0 ;
V_130 = F_41 () ;
if ( ! V_130 )
return - V_131 ;
return 0 ;
}
static void F_42 ( struct V_49 * V_50 )
{
F_43 ( V_132 , & V_50 -> V_133 ) ;
}
static void F_44 ( struct V_73 * V_74 )
{
struct V_49 * V_50 = & V_74 -> V_127 ;
V_50 -> V_67 = NULL ;
V_50 -> V_51 = V_74 ;
V_50 -> V_134 . V_135 = & V_136 [ V_137 ] ;
V_50 -> V_134 . V_138 = NULL ;
V_50 -> V_134 . V_139 = NULL ;
V_50 -> V_134 . V_140 = V_130 ;
V_50 -> V_141 = & V_142 ;
F_42 ( V_50 ) ;
}
void F_45 ( struct V_73 * V_74 )
{
V_74 -> V_122 = V_143 ;
F_46 ( V_144 , & V_74 -> V_145 ) ;
F_44 ( V_74 ) ;
}
void F_47 ( struct V_73 * V_74 )
{
F_45 ( V_74 ) ;
F_48 ( V_132 ) ;
}
void F_49 ( struct V_73 * V_74 , struct V_75 * V_76 )
{
V_74 -> V_122 = V_143 ;
F_50 ( & V_74 -> V_146 ) ;
memcpy ( & V_74 -> V_114 , V_76 , sizeof( struct V_75 ) ) ;
F_51 ( & V_74 -> V_146 ) ;
}
static bool F_52 ( struct V_73 * V_74 , struct V_124 * V_125 )
{
if ( F_53 ( 0 , & V_74 -> V_147 ) != 0 ) {
F_54 ( & V_74 -> V_148 , V_125 , NULL ) ;
F_2 ( L_11 , V_35 ) ;
return false ;
}
return true ;
}
static void F_55 ( struct V_124 * V_125 , void * V_126 )
{
struct V_49 * V_50 = V_126 ;
struct V_44 * V_45 = F_39 ( V_50 , struct V_44 , V_149 ) ;
struct V_73 * V_74 = V_45 -> V_150 ;
T_2 V_39 = V_74 -> V_103 ;
V_50 -> V_61 = V_39 ;
if ( V_39 ) {
if ( ! F_52 ( V_74 , V_125 ) )
return;
}
F_50 ( & V_74 -> V_146 ) ;
if ( F_56 ( & V_50 -> V_151 ) ) {
V_50 -> V_152 = false ;
F_57 ( & V_50 -> V_151 , & V_74 -> V_153 ) ;
}
F_51 ( & V_74 -> V_146 ) ;
F_58 ( V_125 ) ;
}
static void F_59 ( struct V_124 * V_125 , void * V_126 )
{
struct V_49 * V_50 = V_126 ;
struct V_44 * V_45 = F_39 ( V_50 , struct V_44 , V_149 ) ;
struct V_73 * V_74 = V_45 -> V_150 ;
F_2 ( L_12 , V_35 ,
V_74 -> V_103 ) ;
if ( V_74 -> V_103 ) {
++ V_74 -> V_52 -> V_54 ;
F_60 ( 0 , & V_74 -> V_147 ) ;
F_61 ( & V_74 -> V_148 ) ;
F_2 ( L_13 , V_35 ,
V_74 -> V_52 -> V_54 ) ;
V_125 -> V_154 . V_139 = NULL ;
}
}
static void F_62 ( struct V_124 * V_125 , void * V_126 )
{
struct V_49 * V_50 = V_126 ;
struct V_44 * V_45 = F_39 ( V_50 , struct V_44 , V_149 ) ;
struct V_73 * V_74 = V_45 -> V_150 ;
struct V_101 * V_155 = V_74 -> V_118 ;
F_59 ( V_125 , V_126 ) ;
if ( V_155 != V_125 -> V_156 ) {
return;
}
if ( V_50 -> V_152 )
return;
switch ( V_125 -> V_128 ) {
case 0 :
V_50 -> V_152 = true ;
return;
case - V_157 :
case - V_158 :
break;
default:
F_37 ( V_74 , V_125 -> V_128 ) ;
}
if ( V_45 -> V_159 -- ) {
F_63 ( V_125 , 2 * V_72 ) ;
V_125 -> V_128 = 0 ;
F_64 ( V_125 ) ;
return;
}
F_37 ( V_74 , V_125 -> V_128 ) ;
V_50 -> V_152 = true ;
}
static void F_65 ( void * V_126 )
{
struct V_49 * V_50 = V_126 ;
struct V_73 * V_74 = V_50 -> V_51 ;
struct V_44 * V_45 = F_39 ( V_50 , struct V_44 , V_149 ) ;
if ( V_50 -> V_152 ) {
F_50 ( & V_74 -> V_146 ) ;
F_66 ( & V_50 -> V_151 ) ;
F_51 ( & V_74 -> V_146 ) ;
F_67 ( V_45 ) ;
}
}
int F_68 ( void )
{
V_132 = F_69 ( L_14 ) ;
if ( ! V_132 )
return - V_131 ;
return 0 ;
}
void F_70 ( void )
{
F_71 ( V_132 ) ;
}
void F_72 ( struct V_73 * V_74 )
{
F_46 ( V_160 , & V_74 -> V_145 ) ;
F_44 ( V_74 ) ;
F_48 ( V_132 ) ;
}
static void F_73 ( struct V_49 * V_50 )
{
if ( V_50 -> V_141 -> V_161 )
V_50 -> V_141 -> V_161 ( V_50 ) ;
}
static struct V_162 * F_74 ( struct V_73 * V_74 )
{
struct V_20 * V_163 ;
struct V_162 * V_164 ;
F_75 (s, &clp->cl_sessions, se_perclnt) {
F_75 (c, &s->se_conns, cn_persession) {
if ( V_164 -> V_165 & V_166 )
return V_164 ;
}
}
return NULL ;
}
static void F_76 ( struct V_49 * V_50 )
{
struct V_75 V_76 ;
struct V_73 * V_74 = V_50 -> V_51 ;
struct V_20 * V_77 = NULL ;
struct V_162 * V_164 ;
int V_167 ;
if ( V_74 -> V_118 ) {
F_77 ( V_74 -> V_118 ) ;
V_74 -> V_118 = NULL ;
}
if ( V_74 -> V_114 . V_113 ) {
F_78 ( V_74 -> V_114 . V_113 ) ;
V_74 -> V_114 . V_113 = NULL ;
}
if ( F_79 ( V_160 , & V_74 -> V_145 ) )
return;
F_50 ( & V_74 -> V_146 ) ;
F_8 ( ! V_74 -> V_145 ) ;
F_60 ( V_144 , & V_74 -> V_145 ) ;
memcpy ( & V_76 , & V_50 -> V_51 -> V_114 , sizeof( struct V_75 ) ) ;
V_164 = F_74 ( V_74 ) ;
if ( V_164 ) {
F_80 ( V_164 -> V_168 ) ;
V_76 . V_113 = V_164 -> V_168 ;
V_77 = V_164 -> V_169 ;
}
F_51 ( & V_74 -> V_146 ) ;
V_167 = F_32 ( V_74 , & V_76 , V_77 ) ;
if ( V_167 ) {
F_36 ( V_74 , V_167 ) ;
return;
}
F_75 (cb, &clp->cl_callbacks, cb_per_client)
F_42 ( V_50 ) ;
}
void F_81 ( struct V_170 * V_171 )
{
struct V_49 * V_50 = F_39 ( V_171 , struct V_49 , V_133 ) ;
struct V_73 * V_74 = V_50 -> V_51 ;
struct V_101 * V_172 ;
if ( V_74 -> V_145 )
F_76 ( V_50 ) ;
V_172 = V_74 -> V_118 ;
if ( ! V_172 ) {
F_73 ( V_50 ) ;
return;
}
F_82 ( V_172 , & V_50 -> V_134 , V_173 | V_174 ,
V_50 -> V_141 , V_50 ) ;
}
void F_83 ( struct V_44 * V_45 )
{
struct V_49 * V_50 = & V_45 -> V_149 ;
struct V_73 * V_74 = V_45 -> V_150 ;
V_45 -> V_159 = 1 ;
V_50 -> V_67 = V_45 ;
V_50 -> V_51 = V_74 ;
V_50 -> V_134 . V_135 = & V_136 [ V_175 ] ;
V_50 -> V_134 . V_138 = V_50 ;
V_50 -> V_134 . V_139 = V_50 ;
V_50 -> V_134 . V_140 = V_130 ;
V_50 -> V_141 = & V_176 ;
V_45 -> V_159 = 1 ;
F_84 ( & V_50 -> V_151 ) ;
V_50 -> V_152 = true ;
F_42 ( & V_45 -> V_149 ) ;
}
