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
. V_97 = V_75 -> V_98 ,
. V_99 = ( V_100 | V_101 ) ,
} ;
struct V_102 * V_103 ;
if ( V_75 -> V_104 == 0 ) {
if ( ! V_75 -> V_105 && ( V_75 -> V_98 >= V_106 ) )
return - V_107 ;
args . V_108 = V_75 -> V_105 ;
args . V_109 = V_77 -> V_110 ,
args . V_111 = V_112 ;
V_75 -> V_69 = V_77 -> V_113 ;
} else {
if ( ! V_77 -> V_114 )
return - V_107 ;
V_75 -> V_115 . V_114 = V_77 -> V_114 ;
V_75 -> V_53 = V_78 ;
args . V_116 = V_77 -> V_114 ;
args . V_109 = V_75 -> V_53 -> V_117 ;
args . V_111 = V_118 ;
}
V_103 = F_34 ( & args ) ;
if ( F_35 ( V_103 ) ) {
F_2 ( L_9 ,
F_36 ( V_103 ) ) ;
return F_36 ( V_103 ) ;
}
V_75 -> V_119 = V_103 ;
return 0 ;
}
static void F_37 ( struct V_74 * V_75 , int V_120 )
{
F_2 ( L_10 ,
( int ) V_75 -> V_121 . V_122 , V_75 -> V_121 . V_24 , V_120 ) ;
}
static void F_38 ( struct V_74 * V_75 , int V_120 )
{
V_75 -> V_123 = V_124 ;
F_37 ( V_75 , V_120 ) ;
}
static void F_25 ( struct V_74 * V_75 , int V_120 )
{
V_75 -> V_123 = V_125 ;
F_37 ( V_75 , V_120 ) ;
}
static void F_39 ( struct V_126 * V_127 , void * V_128 )
{
struct V_74 * V_75 = F_40 ( V_128 , struct V_74 , V_129 ) ;
if ( V_127 -> V_130 )
F_38 ( V_75 , V_127 -> V_130 ) ;
else
V_75 -> V_123 = V_131 ;
}
int F_41 ( void )
{
if ( V_132 )
return 0 ;
V_132 = F_42 ( L_11 ) ;
if ( ! V_132 )
return - V_133 ;
return 0 ;
}
static void F_43 ( struct V_50 * V_51 )
{
F_44 ( V_134 , & V_51 -> V_135 ) ;
}
static void F_45 ( struct V_74 * V_75 )
{
struct V_50 * V_51 = & V_75 -> V_129 ;
V_51 -> V_68 = NULL ;
V_51 -> V_52 = V_75 ;
V_51 -> V_136 . V_137 = & V_138 [ V_139 ] ;
V_51 -> V_136 . V_140 = NULL ;
V_51 -> V_136 . V_141 = NULL ;
V_51 -> V_136 . V_142 = V_132 ;
V_51 -> V_143 = & V_144 ;
F_43 ( V_51 ) ;
}
void F_46 ( struct V_74 * V_75 )
{
V_75 -> V_123 = V_145 ;
F_47 ( V_146 , & V_75 -> V_147 ) ;
F_45 ( V_75 ) ;
}
void F_48 ( struct V_74 * V_75 )
{
F_46 ( V_75 ) ;
F_49 ( V_134 ) ;
}
void F_50 ( struct V_74 * V_75 , struct V_76 * V_77 )
{
V_75 -> V_123 = V_145 ;
F_51 ( & V_75 -> V_148 ) ;
memcpy ( & V_75 -> V_115 , V_77 , sizeof( struct V_76 ) ) ;
F_52 ( & V_75 -> V_148 ) ;
}
static bool F_53 ( struct V_74 * V_75 , struct V_126 * V_127 )
{
if ( F_54 ( 0 , & V_75 -> V_149 ) != 0 ) {
F_55 ( & V_75 -> V_150 , V_127 , NULL ) ;
F_2 ( L_12 , V_35 ) ;
return false ;
}
return true ;
}
static void F_56 ( struct V_126 * V_127 , void * V_128 )
{
struct V_50 * V_51 = V_128 ;
struct V_44 * V_45 = F_40 ( V_51 , struct V_44 , V_151 ) ;
struct V_74 * V_75 = V_45 -> V_47 . V_152 ;
T_2 V_39 = V_75 -> V_104 ;
V_51 -> V_62 = V_39 ;
if ( V_39 ) {
if ( ! F_53 ( V_75 , V_127 ) )
return;
}
F_51 ( & V_75 -> V_148 ) ;
if ( F_57 ( & V_51 -> V_153 ) ) {
V_51 -> V_154 = false ;
F_58 ( & V_51 -> V_153 , & V_75 -> V_155 ) ;
}
F_52 ( & V_75 -> V_148 ) ;
F_59 ( V_127 ) ;
}
static void F_60 ( struct V_126 * V_127 , void * V_128 )
{
struct V_50 * V_51 = V_128 ;
struct V_44 * V_45 = F_40 ( V_51 , struct V_44 , V_151 ) ;
struct V_74 * V_75 = V_45 -> V_47 . V_152 ;
F_2 ( L_13 , V_35 ,
V_75 -> V_104 ) ;
if ( V_75 -> V_104 ) {
++ V_75 -> V_53 -> V_55 ;
F_61 ( 0 , & V_75 -> V_149 ) ;
F_62 ( & V_75 -> V_150 ) ;
F_2 ( L_14 , V_35 ,
V_75 -> V_53 -> V_55 ) ;
V_127 -> V_156 . V_141 = NULL ;
}
}
static void F_63 ( struct V_126 * V_127 , void * V_128 )
{
struct V_50 * V_51 = V_128 ;
struct V_44 * V_45 = F_40 ( V_51 , struct V_44 , V_151 ) ;
struct V_74 * V_75 = V_45 -> V_47 . V_152 ;
struct V_102 * V_157 = V_75 -> V_119 ;
F_60 ( V_127 , V_128 ) ;
if ( V_157 != V_127 -> V_158 ) {
return;
}
if ( V_51 -> V_154 )
return;
switch ( V_127 -> V_130 ) {
case 0 :
V_51 -> V_154 = true ;
return;
case - V_159 :
case - V_160 :
break;
default:
F_38 ( V_75 , V_127 -> V_130 ) ;
}
if ( V_45 -> V_161 -- ) {
F_64 ( V_127 , 2 * V_73 ) ;
V_127 -> V_130 = 0 ;
F_65 ( V_127 ) ;
return;
}
F_38 ( V_75 , V_127 -> V_130 ) ;
V_51 -> V_154 = true ;
}
static void F_66 ( void * V_128 )
{
struct V_50 * V_51 = V_128 ;
struct V_74 * V_75 = V_51 -> V_52 ;
struct V_44 * V_45 = F_40 ( V_51 , struct V_44 , V_151 ) ;
if ( V_51 -> V_154 ) {
F_51 ( & V_75 -> V_148 ) ;
F_67 ( & V_51 -> V_153 ) ;
F_52 ( & V_75 -> V_148 ) ;
F_68 ( V_45 ) ;
}
}
int F_69 ( void )
{
V_134 = F_70 ( L_15 ) ;
if ( ! V_134 )
return - V_133 ;
return 0 ;
}
void F_71 ( void )
{
F_72 ( V_134 ) ;
}
void F_73 ( struct V_74 * V_75 )
{
F_47 ( V_162 , & V_75 -> V_147 ) ;
F_45 ( V_75 ) ;
F_49 ( V_134 ) ;
}
static void F_74 ( struct V_50 * V_51 )
{
if ( V_51 -> V_143 -> V_163 )
V_51 -> V_143 -> V_163 ( V_51 ) ;
}
static struct V_164 * F_75 ( struct V_74 * V_75 )
{
struct V_20 * V_165 ;
struct V_164 * V_166 ;
F_76 (s, &clp->cl_sessions, se_perclnt) {
F_76 (c, &s->se_conns, cn_persession) {
if ( V_166 -> V_167 & V_168 )
return V_166 ;
}
}
return NULL ;
}
static void F_77 ( struct V_50 * V_51 )
{
struct V_76 V_77 ;
struct V_74 * V_75 = V_51 -> V_52 ;
struct V_20 * V_78 = NULL ;
struct V_164 * V_166 ;
int V_169 ;
if ( V_75 -> V_119 ) {
F_78 ( V_75 -> V_119 ) ;
V_75 -> V_119 = NULL ;
}
if ( V_75 -> V_115 . V_114 ) {
F_79 ( V_75 -> V_115 . V_114 ) ;
V_75 -> V_115 . V_114 = NULL ;
}
if ( F_80 ( V_162 , & V_75 -> V_147 ) )
return;
F_51 ( & V_75 -> V_148 ) ;
F_8 ( ! V_75 -> V_147 ) ;
F_61 ( V_146 , & V_75 -> V_147 ) ;
memcpy ( & V_77 , & V_51 -> V_52 -> V_115 , sizeof( struct V_76 ) ) ;
V_166 = F_75 ( V_75 ) ;
if ( V_166 ) {
F_81 ( V_166 -> V_170 ) ;
V_77 . V_114 = V_166 -> V_170 ;
V_78 = V_166 -> V_171 ;
}
F_52 ( & V_75 -> V_148 ) ;
V_169 = F_33 ( V_75 , & V_77 , V_78 ) ;
if ( V_169 ) {
F_37 ( V_75 , V_169 ) ;
return;
}
F_76 (cb, &clp->cl_callbacks, cb_per_client)
F_43 ( V_51 ) ;
}
void F_82 ( struct V_172 * V_173 )
{
struct V_50 * V_51 = F_40 ( V_173 , struct V_50 , V_135 ) ;
struct V_74 * V_75 = V_51 -> V_52 ;
struct V_102 * V_174 ;
if ( V_75 -> V_147 )
F_77 ( V_51 ) ;
V_174 = V_75 -> V_119 ;
if ( ! V_174 ) {
F_74 ( V_51 ) ;
return;
}
F_83 ( V_174 , & V_51 -> V_136 , V_175 | V_176 ,
V_51 -> V_143 , V_51 ) ;
}
void F_84 ( struct V_44 * V_45 )
{
struct V_50 * V_51 = & V_45 -> V_151 ;
struct V_74 * V_75 = V_45 -> V_47 . V_152 ;
V_45 -> V_161 = 1 ;
V_51 -> V_68 = V_45 ;
V_51 -> V_52 = V_75 ;
V_51 -> V_136 . V_137 = & V_138 [ V_177 ] ;
V_51 -> V_136 . V_140 = V_51 ;
V_51 -> V_136 . V_141 = V_51 ;
V_51 -> V_136 . V_142 = V_132 ;
V_51 -> V_143 = & V_178 ;
V_45 -> V_161 = 1 ;
F_85 ( & V_51 -> V_153 ) ;
V_51 -> V_154 = true ;
F_43 ( & V_45 -> V_151 ) ;
}
