static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
char * V_5 = F_2 ( V_2 , V_6 ) ;
memset ( V_5 , 0 , V_6 ) ;
F_3 ( V_5 , V_7 ) ;
F_4 ( V_5 , V_8 ) ;
F_5 ( V_5 , V_9 ) ;
F_6 ( V_5 , 0 ) ;
F_7 ( V_5 , 1 ) ;
F_8 ( V_5 , V_4 -> V_10 ) ;
F_9 ( V_5 , V_11 ) ;
}
static int F_10 ( struct V_12 * V_12 )
{
char V_13 [ V_14 ] ;
int V_15 ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_17 ) , V_13 ) ;
if ( V_15 )
return V_15 ;
F_13 ( V_13 , V_12 -> V_18 ) ;
return 0 ;
}
static int F_14 ( struct V_12 * V_12 )
{
struct V_19 * V_20 ;
int V_21 ;
V_20 = F_15 ( V_12 -> V_16 ) ;
if ( ! V_20 -> V_22 )
return - V_23 ;
V_12 -> V_24 . V_25 = V_20 -> V_26 ;
V_12 -> V_24 . V_27 = F_16 ( V_12 -> V_24 . V_25 ,
sizeof( struct V_28 ) ,
V_29 ) ;
if ( ! V_12 -> V_24 . V_27 )
return - V_30 ;
for ( V_21 = 0 ; V_21 < V_12 -> V_24 . V_25 ; V_21 ++ )
F_17 ( & V_12 -> V_24 . V_27 [ V_21 ] . V_31 ) ;
return 0 ;
}
static void F_18 ( struct V_12 * V_12 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_12 -> V_24 . V_25 ; V_21 ++ ) {
struct V_28 * V_32 = & V_12 -> V_24 . V_27 [ V_21 ] ;
F_19 ( ! F_20 ( & V_32 -> V_31 ) ) ;
}
F_21 ( V_12 -> V_24 . V_27 ) ;
}
static struct V_28 *
F_22 ( struct V_33 * V_34 )
{
struct V_12 * V_12 = V_34 -> V_12 ;
struct V_28 * V_35 ;
char V_36 [ V_37 ] ;
T_1 V_10 = V_34 -> V_10 ;
int V_38 ;
int V_21 ;
int V_15 ;
V_38 = - 1 ;
for ( V_21 = 0 ; V_21 < V_12 -> V_24 . V_25 ; V_21 ++ ) {
if ( ! V_12 -> V_24 . V_27 [ V_21 ] . V_39 ) {
V_38 = V_21 ;
V_35 = & V_12 -> V_24 . V_27 [ V_21 ] ;
break;
}
}
if ( V_38 < 0 )
return NULL ;
F_23 ( V_36 , V_38 , V_10 , true ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_40 ) , V_36 ) ;
if ( V_15 )
return NULL ;
V_35 -> V_39 = true ;
V_35 -> V_41 = V_38 ;
V_35 -> V_42 = 1 ;
V_35 -> V_10 = V_10 ;
return V_35 ;
}
static void F_25 ( struct V_12 * V_12 ,
struct V_28 * V_35 )
{
T_1 V_10 = V_35 -> V_10 ;
char V_36 [ V_37 ] ;
int V_43 = V_35 -> V_41 ;
F_23 ( V_36 , V_43 , V_10 , false ) ;
F_24 ( V_12 -> V_16 , F_12 ( V_40 ) , V_36 ) ;
V_35 -> V_39 = false ;
}
static struct V_28 *
F_26 ( struct V_33 * V_34 )
{
struct V_12 * V_12 = V_34 -> V_12 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_12 -> V_24 . V_25 ; V_21 ++ ) {
struct V_28 * V_32 = & V_12 -> V_24 . V_27 [ V_21 ] ;
if ( V_32 -> V_39 && V_32 -> V_10 == V_34 -> V_10 )
return V_32 ;
}
return NULL ;
}
static struct V_28
* F_27 ( struct V_33 * V_34 )
{
struct V_28 * V_35 ;
V_35 = F_26 ( V_34 ) ;
if ( V_35 ) {
V_35 -> V_42 ++ ;
return V_35 ;
}
return F_22 ( V_34 ) ;
}
static int F_28 ( struct V_12 * V_12 ,
struct V_28 * V_35 )
{
F_29 ( ! V_35 -> V_42 ) ;
if ( -- V_35 -> V_42 == 0 )
F_25 ( V_12 , V_35 ) ;
return 0 ;
}
static bool F_30 ( struct V_33 * V_34 )
{
struct V_12 * V_12 = V_34 -> V_12 ;
struct V_44 * V_45 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_12 -> V_24 . V_25 ; V_21 ++ ) {
struct V_28 * V_32 = & V_12 -> V_24 . V_27 [ V_21 ] ;
F_31 (p, &curr->bound_ports_list, list)
if ( V_45 -> V_10 == V_34 -> V_10 &&
V_45 -> type == V_46 )
return true ;
}
return false ;
}
static int F_32 ( int V_47 )
{
return F_33 ( V_47 * 5 / 2 ) + 1 ;
}
static int F_34 ( struct V_33 * V_34 , T_2 V_47 )
{
struct V_12 * V_12 = V_34 -> V_12 ;
char V_48 [ V_49 ] ;
int V_15 ;
if ( F_30 ( V_34 ) ) {
F_35 ( V_48 , V_34 -> V_10 ,
F_32 ( V_47 ) ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_50 ) , V_48 ) ;
if ( V_15 ) {
F_36 ( V_34 -> V_51 , L_1 ) ;
return V_15 ;
}
}
return 0 ;
}
static struct V_44 *
F_37 ( struct V_33 * V_34 ,
struct V_28 * V_35 )
{
struct V_44 * V_45 ;
F_31 (p, &span_entry->bound_ports_list, list)
if ( V_34 -> V_10 == V_45 -> V_10 )
return V_45 ;
return NULL ;
}
static int
F_38 ( struct V_33 * V_34 ,
struct V_28 * V_35 ,
enum V_52 type )
{
struct V_44 * V_53 ;
struct V_12 * V_12 = V_34 -> V_12 ;
char V_54 [ V_55 ] ;
char V_48 [ V_49 ] ;
int V_43 = V_35 -> V_41 ;
int V_15 ;
if ( type == V_46 ) {
F_35 ( V_48 , V_34 -> V_10 ,
F_32 ( V_34 -> V_51 -> V_47 ) ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_50 ) , V_48 ) ;
if ( V_15 ) {
F_36 ( V_34 -> V_51 , L_2 ) ;
return V_15 ;
}
}
F_39 ( V_54 , V_34 -> V_10 ,
(enum V_56 ) type , true , V_43 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_57 ) , V_54 ) ;
if ( V_15 )
goto V_58;
V_53 = F_40 ( sizeof( * V_53 ) , V_29 ) ;
if ( ! V_53 ) {
V_15 = - V_30 ;
goto V_59;
}
V_53 -> V_10 = V_34 -> V_10 ;
V_53 -> type = type ;
F_41 ( & V_53 -> V_60 , & V_35 -> V_31 ) ;
return 0 ;
V_58:
V_59:
if ( type == V_46 ) {
F_35 ( V_48 , V_34 -> V_10 , 0 ) ;
F_24 ( V_12 -> V_16 , F_12 ( V_50 ) , V_48 ) ;
}
return V_15 ;
}
static void
F_42 ( struct V_33 * V_34 ,
struct V_28 * V_35 ,
enum V_52 type )
{
struct V_44 * V_53 ;
struct V_12 * V_12 = V_34 -> V_12 ;
char V_54 [ V_55 ] ;
char V_48 [ V_49 ] ;
int V_43 = V_35 -> V_41 ;
V_53 = F_37 ( V_34 , V_35 ) ;
if ( ! V_53 )
return;
F_39 ( V_54 , V_34 -> V_10 ,
(enum V_56 ) type , false , V_43 ) ;
F_24 ( V_12 -> V_16 , F_12 ( V_57 ) , V_54 ) ;
if ( type == V_46 ) {
F_35 ( V_48 , V_34 -> V_10 , 0 ) ;
F_24 ( V_12 -> V_16 , F_12 ( V_50 ) , V_48 ) ;
}
F_28 ( V_12 , V_35 ) ;
F_43 ( & V_53 -> V_60 ) ;
F_21 ( V_53 ) ;
}
static int F_44 ( struct V_33 * V_61 ,
struct V_33 * V_62 ,
enum V_52 type )
{
struct V_12 * V_12 = V_61 -> V_12 ;
struct V_28 * V_35 ;
int V_15 ;
V_35 = F_27 ( V_62 ) ;
if ( ! V_35 )
return - V_63 ;
F_45 ( V_61 -> V_51 , L_3 ,
V_35 -> V_41 ) ;
V_15 = F_38 ( V_61 , V_35 , type ) ;
if ( V_15 )
goto V_64;
return 0 ;
V_64:
F_28 ( V_12 , V_35 ) ;
return V_15 ;
}
static void F_46 ( struct V_33 * V_61 ,
struct V_33 * V_62 ,
enum V_52 type )
{
struct V_28 * V_35 ;
V_35 = F_26 ( V_62 ) ;
if ( ! V_35 ) {
F_36 ( V_61 -> V_51 , L_4 ) ;
return;
}
F_45 ( V_61 -> V_51 , L_5 ,
V_35 -> V_41 ) ;
F_42 ( V_61 , V_35 , type ) ;
}
static int F_47 ( struct V_33 * V_33 ,
bool V_65 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_66 [ V_67 ] ;
F_48 ( V_66 , V_33 -> V_10 ,
V_65 ? V_68 :
V_69 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_70 ) , V_66 ) ;
}
static int F_49 ( struct V_33 * V_33 ,
unsigned char * V_71 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_72 [ V_73 ] ;
F_50 ( V_72 , true , V_33 -> V_10 ) ;
F_51 ( V_72 , V_71 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_74 ) , V_72 ) ;
}
static int F_52 ( struct V_33 * V_33 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
unsigned char * V_71 = V_33 -> V_51 -> V_75 ;
F_53 ( V_71 , V_12 -> V_18 ) ;
V_71 [ V_76 - 1 ] += V_33 -> V_10 ;
return F_49 ( V_33 , V_71 ) ;
}
static int F_54 ( struct V_33 * V_33 , T_2 V_47 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_77 [ V_78 ] ;
int V_79 ;
int V_15 ;
V_47 += V_6 + V_80 ;
F_55 ( V_77 , V_33 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_81 ) , V_77 ) ;
if ( V_15 )
return V_15 ;
V_79 = F_56 ( V_77 ) ;
if ( V_47 > V_79 )
return - V_82 ;
F_55 ( V_77 , V_33 -> V_10 , V_47 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_81 ) , V_77 ) ;
}
static int F_57 ( struct V_12 * V_12 , T_1 V_10 ,
T_1 V_83 )
{
char V_84 [ V_85 ] ;
F_58 ( V_84 , V_83 , V_10 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_86 ) , V_84 ) ;
}
static int F_59 ( struct V_33 * V_33 , T_1 V_83 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
return F_57 ( V_12 , V_33 -> V_10 ,
V_83 ) ;
}
static int F_60 ( struct V_33 * V_33 ,
bool V_87 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_88 [ V_89 ] ;
F_61 ( V_88 , V_33 -> V_10 , V_87 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_90 ) , V_88 ) ;
}
int F_62 ( struct V_33 * V_33 ,
enum V_91 V_92 , bool V_93 , T_2 V_94 ,
T_2 V_95 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_96 [ V_97 ] ;
F_63 ( V_96 , V_33 -> V_10 , V_92 , V_93 ,
V_94 , V_95 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_98 ) , V_96 ) ;
}
int F_64 ( struct V_33 * V_33 ,
T_2 V_99 , T_2 V_100 ,
bool V_101 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char * V_102 ;
int V_15 ;
V_102 = F_65 ( V_103 , V_29 ) ;
if ( ! V_102 )
return - V_30 ;
F_66 ( V_102 , V_33 -> V_10 , V_99 ,
V_100 , V_101 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_104 ) , V_102 ) ;
F_21 ( V_102 ) ;
return V_15 ;
}
static int F_67 ( struct V_33 * V_33 ,
T_2 V_95 , bool V_101 )
{
return F_64 ( V_33 , V_95 , V_95 ,
V_101 ) ;
}
static int
F_68 ( struct V_33 * V_33 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_105 [ V_106 ] ;
F_69 ( V_105 , V_33 -> V_10 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_107 ) , V_105 ) ;
}
static int F_70 ( struct V_12 * V_12 ,
T_1 V_10 , T_1 * V_108 ,
T_1 * V_109 , T_1 * V_110 )
{
char V_111 [ V_112 ] ;
int V_15 ;
F_71 ( V_111 , V_10 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_113 ) , V_111 ) ;
if ( V_15 )
return V_15 ;
* V_108 = F_72 ( V_111 , 0 ) ;
* V_109 = F_73 ( V_111 ) ;
* V_110 = F_74 ( V_111 , 0 ) ;
return 0 ;
}
static int F_75 ( struct V_12 * V_12 , T_1 V_10 ,
T_1 V_114 , T_1 V_115 , T_1 V_116 )
{
char V_111 [ V_112 ] ;
int V_21 ;
F_71 ( V_111 , V_10 ) ;
F_76 ( V_111 , V_115 ) ;
for ( V_21 = 0 ; V_21 < V_115 ; V_21 ++ ) {
F_77 ( V_111 , V_21 , V_114 ) ;
F_78 ( V_111 , V_21 , V_116 + V_21 ) ;
}
return F_24 ( V_12 -> V_16 , F_12 ( V_113 ) , V_111 ) ;
}
static int F_79 ( struct V_12 * V_12 , T_1 V_10 )
{
char V_111 [ V_112 ] ;
F_71 ( V_111 , V_10 ) ;
F_76 ( V_111 , 0 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_113 ) , V_111 ) ;
}
static int F_80 ( struct V_117 * V_51 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
int V_15 ;
V_15 = F_47 ( V_33 , true ) ;
if ( V_15 )
return V_15 ;
F_82 ( V_51 ) ;
return 0 ;
}
static int F_83 ( struct V_117 * V_51 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
F_84 ( V_51 ) ;
return F_47 ( V_33 , false ) ;
}
static T_3 F_85 ( struct V_1 * V_2 ,
struct V_117 * V_51 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
struct V_118 * V_119 ;
const struct V_3 V_4 = {
. V_10 = V_33 -> V_10 ,
. V_120 = false ,
} ;
T_4 V_121 ;
int V_15 ;
if ( F_86 ( V_12 -> V_16 , & V_4 ) )
return V_122 ;
if ( F_87 ( F_88 ( V_2 ) < V_6 ) ) {
struct V_1 * V_123 = V_2 ;
V_2 = F_89 ( V_2 , V_6 ) ;
if ( ! V_2 ) {
F_90 ( V_33 -> V_119 -> V_124 ) ;
F_91 ( V_123 ) ;
return V_125 ;
}
}
if ( F_92 ( V_2 ) ) {
F_90 ( V_33 -> V_119 -> V_124 ) ;
return V_125 ;
}
F_1 ( V_2 , & V_4 ) ;
V_121 = V_2 -> V_121 - V_6 ;
V_15 = F_93 ( V_12 -> V_16 , V_2 , & V_4 ) ;
if ( ! V_15 ) {
V_119 = F_94 ( V_33 -> V_119 ) ;
F_95 ( & V_119 -> V_126 ) ;
V_119 -> V_127 ++ ;
V_119 -> V_128 += V_121 ;
F_96 ( & V_119 -> V_126 ) ;
} else {
F_90 ( V_33 -> V_119 -> V_124 ) ;
F_91 ( V_2 ) ;
}
return V_125 ;
}
static void F_97 ( struct V_117 * V_51 )
{
}
static int F_98 ( struct V_117 * V_51 , void * V_45 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
struct V_129 * V_71 = V_45 ;
int V_15 ;
if ( ! F_99 ( V_71 -> V_130 ) )
return - V_131 ;
V_15 = F_49 ( V_33 , V_71 -> V_130 ) ;
if ( V_15 )
return V_15 ;
memcpy ( V_51 -> V_75 , V_71 -> V_130 , V_51 -> V_132 ) ;
return 0 ;
}
static void F_100 ( char * V_133 , int V_134 , int V_47 ,
bool V_135 , bool V_136 , T_2 V_137 )
{
T_2 V_138 = 2 * F_33 ( V_47 ) ;
V_137 = V_136 ? F_101 ( V_47 , V_137 ) :
V_139 ;
if ( V_135 || V_136 )
F_102 ( V_133 , V_134 ,
V_138 + V_137 , V_138 ) ;
else
F_103 ( V_133 , V_134 , V_138 ) ;
}
int F_104 ( struct V_33 * V_33 , int V_47 ,
T_1 * V_140 , bool V_135 ,
struct V_141 * V_142 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
T_1 V_136 = ! ! V_142 ? V_142 -> V_136 : 0 ;
T_2 V_137 = ! ! V_142 ? V_142 -> V_137 : 0 ;
char V_133 [ V_143 ] ;
int V_21 , V_144 , V_15 ;
F_105 ( V_133 , V_33 -> V_10 , 0 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_145 ) , V_133 ) ;
if ( V_15 )
return V_15 ;
for ( V_21 = 0 ; V_21 < V_146 ; V_21 ++ ) {
bool V_147 = false ;
bool V_148 = false ;
for ( V_144 = 0 ; V_144 < V_146 ; V_144 ++ ) {
if ( V_140 [ V_144 ] == V_21 ) {
V_148 = V_136 & F_106 ( V_144 ) ;
V_147 = true ;
break;
}
}
if ( ! V_147 )
continue;
F_100 ( V_133 , V_21 , V_47 , V_135 , V_148 , V_137 ) ;
}
return F_24 ( V_12 -> V_16 , F_12 ( V_145 ) , V_133 ) ;
}
static int F_107 ( struct V_33 * V_33 ,
int V_47 , bool V_135 )
{
T_1 V_149 [ V_146 ] = { 0 } ;
bool V_150 = ! ! V_33 -> V_151 . V_152 ;
struct V_141 * V_142 ;
T_1 * V_140 ;
V_140 = V_150 ? V_33 -> V_151 . V_152 -> V_140 : V_149 ;
V_142 = V_150 ? V_33 -> V_151 . V_148 : NULL ;
return F_104 ( V_33 , V_47 , V_140 ,
V_135 , V_142 ) ;
}
static int F_108 ( struct V_117 * V_51 , int V_47 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
bool V_135 = F_109 ( V_33 ) ;
int V_15 ;
V_15 = F_107 ( V_33 , V_47 , V_135 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_34 ( V_33 , V_47 ) ;
if ( V_15 )
goto V_153;
V_15 = F_54 ( V_33 , V_47 ) ;
if ( V_15 )
goto V_154;
V_51 -> V_47 = V_47 ;
return 0 ;
V_154:
F_34 ( V_33 , V_51 -> V_47 ) ;
V_153:
F_107 ( V_33 , V_51 -> V_47 , V_135 ) ;
return V_15 ;
}
static int
F_110 ( const struct V_117 * V_51 ,
struct V_155 * V_156 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
struct V_118 * V_45 ;
T_4 V_157 , V_158 , V_127 , V_128 ;
T_5 V_124 = 0 ;
unsigned int V_159 ;
int V_21 ;
F_111 (i) {
V_45 = F_112 ( V_33 -> V_119 , V_21 ) ;
do {
V_159 = F_113 ( & V_45 -> V_126 ) ;
V_157 = V_45 -> V_157 ;
V_158 = V_45 -> V_158 ;
V_127 = V_45 -> V_127 ;
V_128 = V_45 -> V_128 ;
} while ( F_114 ( & V_45 -> V_126 , V_159 ) );
V_156 -> V_157 += V_157 ;
V_156 -> V_158 += V_158 ;
V_156 -> V_127 += V_127 ;
V_156 -> V_128 += V_128 ;
V_124 += V_45 -> V_124 ;
}
V_156 -> V_124 = V_124 ;
return 0 ;
}
static bool F_115 ( int V_160 )
{
switch ( V_160 ) {
case V_161 :
return true ;
}
return false ;
}
static int F_116 ( int V_160 , const struct V_117 * V_51 ,
void * V_162 )
{
switch ( V_160 ) {
case V_161 :
return F_110 ( V_51 , V_162 ) ;
}
return - V_82 ;
}
static int F_117 ( struct V_117 * V_51 , int V_163 ,
int V_164 , char * V_165 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
F_118 ( V_165 , V_33 -> V_10 , V_163 , V_164 ) ;
return F_11 ( V_12 -> V_16 , F_12 ( V_166 ) , V_165 ) ;
}
static int F_119 ( struct V_117 * V_51 ,
struct V_155 * V_156 )
{
char V_165 [ V_167 ] ;
int V_15 ;
V_15 = F_117 ( V_51 , V_168 ,
0 , V_165 ) ;
if ( V_15 )
goto V_169;
V_156 -> V_127 =
F_120 ( V_165 ) ;
V_156 -> V_157 =
F_121 ( V_165 ) ;
V_156 -> V_128 =
F_122 ( V_165 ) ;
V_156 -> V_158 =
F_123 ( V_165 ) ;
V_156 -> V_170 =
F_124 ( V_165 ) ;
V_156 -> V_171 =
F_125 ( V_165 ) ;
V_156 -> V_172 =
F_126 ( V_165 ) ;
V_156 -> V_173 = (
F_127 ( V_165 ) +
F_128 ( V_165 ) +
F_129 ( V_165 ) ) ;
V_156 -> V_174 = ( V_156 -> V_171 +
V_156 -> V_172 + V_156 -> V_173 ) ;
V_169:
return V_15 ;
}
static void F_130 ( struct V_175 * V_176 )
{
struct V_33 * V_33 =
F_131 ( V_176 , struct V_33 ,
V_177 . V_178 . V_176 ) ;
if ( ! F_132 ( V_33 -> V_51 ) )
goto V_169;
F_119 ( V_33 -> V_51 ,
V_33 -> V_177 . V_179 ) ;
V_169:
F_133 ( & V_33 -> V_177 . V_178 ,
V_180 ) ;
}
static struct V_155 *
F_134 ( struct V_117 * V_51 ,
struct V_155 * V_156 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
memcpy ( V_156 , V_33 -> V_177 . V_179 , sizeof( * V_156 ) ) ;
return V_156 ;
}
int F_135 ( struct V_33 * V_33 , T_2 V_99 ,
T_2 V_100 , bool V_181 , bool V_182 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char * V_183 ;
int V_15 ;
V_183 = F_65 ( V_184 , V_29 ) ;
if ( ! V_183 )
return - V_30 ;
F_136 ( V_183 , V_33 -> V_10 , V_99 ,
V_100 , V_181 , V_182 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_185 ) , V_183 ) ;
F_21 ( V_183 ) ;
return V_15 ;
}
static int F_137 ( struct V_33 * V_33 )
{
enum V_91 V_92 = V_186 ;
T_2 V_95 , V_187 ;
int V_15 ;
F_138 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_62 ( V_33 , V_92 , true , V_95 ,
V_95 ) ;
if ( V_15 ) {
V_187 = V_95 ;
goto V_188;
}
}
V_15 = F_60 ( V_33 , true ) ;
if ( V_15 ) {
V_187 = V_189 ;
goto V_188;
}
return 0 ;
V_188:
F_138 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_62 ( V_33 , V_92 , false , V_95 ,
V_95 ) ;
return V_15 ;
}
static int F_139 ( struct V_33 * V_33 )
{
enum V_91 V_92 = V_186 ;
T_2 V_95 ;
int V_15 ;
V_15 = F_60 ( V_33 , false ) ;
if ( V_15 )
return V_15 ;
F_138 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_62 ( V_33 , V_92 , false ,
V_95 , V_95 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static struct V_33 *
F_140 ( struct V_33 * V_33 , T_2 V_95 )
{
struct V_33 * V_190 ;
V_190 = F_40 ( sizeof( * V_190 ) , V_29 ) ;
if ( ! V_190 )
return NULL ;
V_190 -> V_51 = V_33 -> V_51 ;
V_190 -> V_12 = V_33 -> V_12 ;
V_190 -> V_10 = V_33 -> V_10 ;
V_190 -> V_191 = V_192 ;
V_190 -> V_193 = V_33 -> V_193 ;
V_190 -> V_194 = V_33 -> V_194 ;
V_190 -> V_195 . V_95 = V_95 ;
F_141 ( & V_190 -> V_195 . V_60 , & V_33 -> V_196 ) ;
return V_190 ;
}
static void F_142 ( struct V_33 * V_190 )
{
F_43 ( & V_190 -> V_195 . V_60 ) ;
F_21 ( V_190 ) ;
}
static int F_143 ( struct V_117 * V_51 ,
T_6 T_7 V_197 , T_2 V_95 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
struct V_33 * V_190 ;
bool V_182 = V_95 == 1 ;
int V_15 ;
if ( ! V_95 )
return 0 ;
if ( F_144 ( V_33 , V_95 ) )
return 0 ;
V_190 = F_140 ( V_33 , V_95 ) ;
if ( ! V_190 )
return - V_30 ;
if ( F_145 ( & V_33 -> V_196 ) ) {
V_15 = F_137 ( V_33 ) ;
if ( V_15 )
goto V_198;
}
V_15 = F_135 ( V_190 , V_95 , V_95 , true , V_182 ) ;
if ( V_15 )
goto V_199;
return 0 ;
V_199:
if ( F_145 ( & V_33 -> V_196 ) )
F_139 ( V_33 ) ;
V_198:
F_142 ( V_190 ) ;
return V_15 ;
}
static int F_146 ( struct V_117 * V_51 ,
T_6 T_7 V_197 , T_2 V_95 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
struct V_33 * V_190 ;
struct V_200 * V_201 ;
if ( ! V_95 )
return 0 ;
V_190 = F_144 ( V_33 , V_95 ) ;
if ( F_29 ( ! V_190 ) )
return 0 ;
F_135 ( V_190 , V_95 , V_95 , false , false ) ;
V_201 = F_147 ( V_190 ) ;
if ( V_201 && ! F_29 ( ! V_201 -> V_202 ) )
V_201 -> V_202 ( V_190 ) ;
if ( F_145 ( & V_33 -> V_196 ) )
F_139 ( V_33 ) ;
F_142 ( V_190 ) ;
return 0 ;
}
static int F_148 ( struct V_117 * V_51 , char * V_203 ,
T_8 V_121 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
T_1 V_114 = V_33 -> V_204 . V_114 ;
T_1 V_115 = V_33 -> V_204 . V_115 ;
T_1 V_116 = V_33 -> V_204 . V_116 ;
int V_15 ;
if ( ! V_33 -> V_205 )
V_15 = snprintf ( V_203 , V_121 , L_6 , V_114 + 1 ) ;
else
V_15 = snprintf ( V_203 , V_121 , L_7 , V_114 + 1 ,
V_116 / V_115 ) ;
if ( V_15 >= V_121 )
return - V_82 ;
return 0 ;
}
static struct V_206 *
F_149 ( struct V_33 * V_34 ,
unsigned long V_207 ) {
struct V_206 * V_208 ;
F_31 (mall_tc_entry, &port->mall_tc_list, list)
if ( V_208 -> V_207 == V_207 )
return V_208 ;
return NULL ;
}
static int
F_150 ( struct V_33 * V_33 ,
struct V_209 * V_210 ,
const struct V_211 * V_212 ,
bool V_213 )
{
struct V_206 * V_208 ;
struct V_214 * V_214 = F_151 ( V_33 -> V_51 ) ;
enum V_52 V_215 ;
struct V_33 * V_216 ;
struct V_117 * V_217 ;
int V_218 ;
int V_15 ;
V_218 = F_152 ( V_212 ) ;
V_217 = F_153 ( V_214 , V_218 ) ;
if ( ! V_217 ) {
F_36 ( V_33 -> V_51 , L_8 ) ;
return - V_82 ;
}
if ( ! F_154 ( V_217 ) ) {
F_36 ( V_33 -> V_51 , L_9 ) ;
return - V_219 ;
}
V_216 = F_81 ( V_217 ) ;
V_208 = F_40 ( sizeof( * V_208 ) , V_29 ) ;
if ( ! V_208 )
return - V_30 ;
V_208 -> V_207 = V_210 -> V_207 ;
V_208 -> type = V_220 ;
V_208 -> V_221 . V_222 = V_216 -> V_10 ;
V_208 -> V_221 . V_213 = V_213 ;
F_41 ( & V_208 -> V_60 , & V_33 -> V_223 ) ;
V_215 = V_213 ? V_224 : V_46 ;
V_15 = F_44 ( V_33 , V_216 , V_215 ) ;
if ( V_15 )
goto V_225;
return 0 ;
V_225:
F_43 ( & V_208 -> V_60 ) ;
F_21 ( V_208 ) ;
return V_15 ;
}
static int F_155 ( struct V_33 * V_33 ,
T_6 V_226 ,
struct V_209 * V_210 ,
bool V_213 )
{
const struct V_211 * V_212 ;
F_156 ( V_227 ) ;
int V_15 ;
if ( ! F_157 ( V_210 -> V_228 ) ) {
F_36 ( V_33 -> V_51 , L_10 ) ;
return - V_219 ;
}
F_158 ( V_210 -> V_228 , & V_227 ) ;
F_31 (a, &actions, list) {
if ( ! F_159 ( V_212 ) || V_226 != F_160 ( V_229 ) )
return - V_219 ;
V_15 = F_150 ( V_33 , V_210 ,
V_212 , V_213 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static void F_161 ( struct V_33 * V_33 ,
struct V_209 * V_210 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
struct V_206 * V_208 ;
enum V_52 V_215 ;
struct V_33 * V_216 ;
V_208 = F_149 ( V_33 ,
V_210 -> V_207 ) ;
if ( ! V_208 ) {
F_45 ( V_33 -> V_51 , L_11 ) ;
return;
}
switch ( V_208 -> type ) {
case V_220 :
V_216 = V_12 -> V_230 [ V_208 -> V_221 . V_222 ] ;
V_215 = V_208 -> V_221 . V_213 ?
V_224 : V_46 ;
F_46 ( V_33 , V_216 , V_215 ) ;
break;
default:
F_29 ( 1 ) ;
}
F_43 ( & V_208 -> V_60 ) ;
F_21 ( V_208 ) ;
}
static int F_162 ( struct V_117 * V_51 , T_5 V_231 ,
T_6 V_197 , struct V_232 * V_233 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
bool V_213 = F_163 ( V_231 ) == F_163 ( V_234 ) ;
if ( V_233 -> type == V_235 ) {
switch ( V_233 -> V_236 -> V_237 ) {
case V_238 :
return F_155 ( V_33 ,
V_197 ,
V_233 -> V_236 ,
V_213 ) ;
case V_239 :
F_161 ( V_33 ,
V_233 -> V_236 ) ;
return 0 ;
default:
return - V_82 ;
}
}
return - V_219 ;
}
static void F_164 ( struct V_117 * V_51 ,
struct V_240 * V_241 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
F_165 ( V_241 -> V_242 , V_243 , sizeof( V_241 -> V_242 ) ) ;
F_165 ( V_241 -> V_244 , V_245 ,
sizeof( V_241 -> V_244 ) ) ;
snprintf ( V_241 -> V_246 , sizeof( V_241 -> V_246 ) ,
L_12 ,
V_12 -> V_247 -> V_248 . V_249 ,
V_12 -> V_247 -> V_248 . V_250 ,
V_12 -> V_247 -> V_248 . V_251 ) ;
F_165 ( V_241 -> V_247 , V_12 -> V_247 -> V_252 ,
sizeof( V_241 -> V_247 ) ) ;
}
static void F_166 ( struct V_117 * V_51 ,
struct V_253 * V_254 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
V_254 -> V_255 = V_33 -> V_256 . V_255 ;
V_254 -> V_257 = V_33 -> V_256 . V_257 ;
}
static int F_167 ( struct V_33 * V_33 ,
struct V_253 * V_254 )
{
char V_258 [ V_259 ] ;
F_168 ( V_258 , V_33 -> V_10 ) ;
F_169 ( V_258 , V_254 -> V_255 ) ;
F_170 ( V_258 , V_254 -> V_257 ) ;
return F_24 ( V_33 -> V_12 -> V_16 , F_12 ( V_260 ) ,
V_258 ) ;
}
static int F_171 ( struct V_117 * V_51 ,
struct V_253 * V_254 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
bool V_135 = V_254 -> V_257 || V_254 -> V_255 ;
int V_15 ;
if ( V_33 -> V_151 . V_148 && V_33 -> V_151 . V_148 -> V_136 ) {
F_36 ( V_51 , L_13 ) ;
return - V_82 ;
}
if ( V_254 -> V_261 ) {
F_36 ( V_51 , L_14 ) ;
return - V_82 ;
}
V_15 = F_107 ( V_33 , V_51 -> V_47 , V_135 ) ;
if ( V_15 ) {
F_36 ( V_51 , L_15 ) ;
return V_15 ;
}
V_15 = F_167 ( V_33 , V_254 ) ;
if ( V_15 ) {
F_36 ( V_51 , L_16 ) ;
goto V_262;
}
V_33 -> V_256 . V_255 = V_254 -> V_255 ;
V_33 -> V_256 . V_257 = V_254 -> V_257 ;
return 0 ;
V_262:
V_135 = F_109 ( V_33 ) ;
F_107 ( V_33 , V_51 -> V_47 , V_135 ) ;
return V_15 ;
}
static T_4 F_172 ( char * V_165 )
{
T_4 V_263 = F_173 ( V_165 ) ;
return F_174 ( V_263 ) ;
}
static void F_175 ( T_1 * * V_45 , int V_164 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_264 ; V_21 ++ ) {
snprintf ( * V_45 , V_265 , L_17 ,
V_266 [ V_21 ] . V_267 , V_164 ) ;
* V_45 += V_265 ;
}
}
static void F_176 ( T_1 * * V_45 , int V_233 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_268 ; V_21 ++ ) {
snprintf ( * V_45 , V_265 , L_17 ,
V_269 [ V_21 ] . V_267 , V_233 ) ;
* V_45 += V_265 ;
}
}
static void F_177 ( struct V_117 * V_51 ,
T_5 V_270 , T_1 * V_271 )
{
T_1 * V_45 = V_271 ;
int V_21 ;
switch ( V_270 ) {
case V_272 :
for ( V_21 = 0 ; V_21 < V_273 ; V_21 ++ ) {
memcpy ( V_45 , V_274 [ V_21 ] . V_267 ,
V_265 ) ;
V_45 += V_265 ;
}
for ( V_21 = 0 ; V_21 < V_146 ; V_21 ++ )
F_175 ( & V_45 , V_21 ) ;
for ( V_21 = 0 ; V_21 < V_146 ; V_21 ++ )
F_176 ( & V_45 , V_21 ) ;
break;
}
}
static int F_178 ( struct V_117 * V_51 ,
enum V_275 V_276 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
char V_277 [ V_278 ] ;
bool V_279 ;
switch ( V_276 ) {
case V_280 :
V_279 = true ;
break;
case V_281 :
V_279 = false ;
break;
default:
return - V_282 ;
}
F_179 ( V_277 , V_33 -> V_10 , V_279 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_283 ) , V_277 ) ;
}
static int
F_180 ( struct V_274 * * V_284 ,
int * V_285 , enum V_286 V_163 )
{
switch ( V_163 ) {
case V_168 :
* V_284 = V_274 ;
* V_285 = V_273 ;
break;
case V_287 :
* V_284 = V_266 ;
* V_285 = V_264 ;
break;
case V_288 :
* V_284 = V_269 ;
* V_285 = V_268 ;
break;
default:
F_29 ( 1 ) ;
return - V_219 ;
}
return 0 ;
}
static void F_181 ( struct V_117 * V_51 ,
enum V_286 V_163 , int V_164 ,
T_4 * V_271 , int V_289 )
{
struct V_274 * V_177 ;
char V_165 [ V_167 ] ;
int V_21 , V_121 ;
int V_15 ;
V_15 = F_180 ( & V_177 , & V_121 , V_163 ) ;
if ( V_15 )
return;
F_117 ( V_51 , V_163 , V_164 , V_165 ) ;
for ( V_21 = 0 ; V_21 < V_121 ; V_21 ++ )
V_271 [ V_289 + V_21 ] = V_177 [ V_21 ] . F_182 ( V_165 ) ;
}
static void F_183 ( struct V_117 * V_51 ,
struct V_290 * V_156 , T_4 * V_271 )
{
int V_21 , V_289 = 0 ;
F_181 ( V_51 , V_168 , 0 ,
V_271 , V_289 ) ;
V_289 = V_273 ;
for ( V_21 = 0 ; V_21 < V_146 ; V_21 ++ ) {
F_181 ( V_51 , V_287 , V_21 ,
V_271 , V_289 ) ;
V_289 += V_264 ;
}
for ( V_21 = 0 ; V_21 < V_146 ; V_21 ++ ) {
F_181 ( V_51 , V_288 , V_21 ,
V_271 , V_289 ) ;
V_289 += V_268 ;
}
}
static int F_184 ( struct V_117 * V_51 , int V_291 )
{
switch ( V_291 ) {
case V_272 :
return V_292 ;
default:
return - V_282 ;
}
}
static void
F_185 ( T_5 V_293 ,
struct V_294 * V_295 )
{
if ( V_293 & ( V_296 |
V_297 |
V_298 |
V_299 |
V_300 |
V_301 ) )
F_186 ( V_295 , V_302 , V_303 ) ;
if ( V_293 & ( V_304 |
V_305 |
V_306 |
V_307 |
V_308 ) )
F_186 ( V_295 , V_302 , V_309 ) ;
}
static void F_187 ( T_5 V_293 , unsigned long * V_310 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_311 ; V_21 ++ ) {
if ( V_293 & V_312 [ V_21 ] . V_313 )
F_188 ( V_312 [ V_21 ] . V_314 ,
V_310 ) ;
}
}
static void F_189 ( bool V_315 , T_5 V_293 ,
struct V_294 * V_295 )
{
T_5 V_316 = V_317 ;
T_1 V_318 = V_319 ;
int V_21 ;
if ( ! V_315 )
goto V_169;
for ( V_21 = 0 ; V_21 < V_311 ; V_21 ++ ) {
if ( V_293 & V_312 [ V_21 ] . V_313 ) {
V_316 = V_312 [ V_21 ] . V_316 ;
V_318 = V_320 ;
break;
}
}
V_169:
V_295 -> V_321 . V_316 = V_316 ;
V_295 -> V_321 . V_318 = V_318 ;
}
static T_1 F_190 ( T_5 V_293 )
{
if ( V_293 & ( V_297 |
V_299 |
V_300 |
V_301 ) )
return V_322 ;
if ( V_293 & ( V_296 |
V_298 |
V_323 ) )
return V_324 ;
if ( V_293 & ( V_304 |
V_305 |
V_306 |
V_307 ) )
return V_325 ;
return V_326 ;
}
static T_5
F_191 ( const struct V_294 * V_295 )
{
T_5 V_327 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_311 ; V_21 ++ ) {
if ( F_192 ( V_312 [ V_21 ] . V_314 ,
V_295 -> V_328 . V_329 ) )
V_327 |= V_312 [ V_21 ] . V_313 ;
}
return V_327 ;
}
static T_5 F_193 ( T_5 V_316 )
{
T_5 V_327 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_311 ; V_21 ++ ) {
if ( V_316 == V_312 [ V_21 ] . V_316 )
V_327 |= V_312 [ V_21 ] . V_313 ;
}
return V_327 ;
}
static T_5 F_194 ( T_5 V_330 )
{
T_5 V_327 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_311 ; V_21 ++ ) {
if ( V_312 [ V_21 ] . V_316 <= V_330 )
V_327 |= V_312 [ V_21 ] . V_313 ;
}
return V_327 ;
}
static void F_195 ( T_5 V_331 ,
struct V_294 * V_295 )
{
F_186 ( V_295 , V_302 , V_332 ) ;
F_186 ( V_295 , V_302 , V_333 ) ;
F_186 ( V_295 , V_302 , V_334 ) ;
F_185 ( V_331 , V_295 ) ;
F_187 ( V_331 , V_295 -> V_328 . V_302 ) ;
}
static void F_196 ( T_5 V_335 , bool V_261 ,
struct V_294 * V_295 )
{
if ( ! V_261 )
return;
F_186 ( V_295 , V_329 , V_333 ) ;
F_187 ( V_335 , V_295 -> V_328 . V_329 ) ;
}
static void
F_197 ( T_5 V_336 , T_1 V_337 ,
struct V_294 * V_295 )
{
if ( V_337 != V_338 || ! V_336 )
return;
F_186 ( V_295 , V_339 , V_333 ) ;
F_187 ( V_336 , V_295 -> V_328 . V_339 ) ;
}
static int F_198 ( struct V_117 * V_51 ,
struct V_294 * V_295 )
{
T_5 V_331 , V_335 , V_340 , V_336 ;
struct V_33 * V_33 = F_81 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
char V_341 [ V_342 ] ;
T_1 V_337 ;
bool V_261 ;
int V_15 ;
V_261 = V_33 -> V_256 . V_261 ;
F_199 ( V_341 , V_33 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_343 ) , V_341 ) ;
if ( V_15 )
return V_15 ;
F_200 ( V_341 , & V_331 , & V_335 ,
& V_340 ) ;
F_195 ( V_331 , V_295 ) ;
F_196 ( V_335 , V_261 , V_295 ) ;
V_336 = F_201 ( V_341 ) ;
V_337 = F_202 ( V_341 ) ;
F_197 ( V_336 , V_337 , V_295 ) ;
V_295 -> V_321 . V_261 = V_261 ? V_344 : V_345 ;
V_295 -> V_321 . V_34 = F_190 ( V_340 ) ;
F_189 ( F_132 ( V_51 ) , V_340 ,
V_295 ) ;
return 0 ;
}
static int
F_203 ( struct V_117 * V_51 ,
const struct V_294 * V_295 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
char V_341 [ V_342 ] ;
T_5 V_331 , V_346 ;
bool V_261 ;
int V_15 ;
F_199 ( V_341 , V_33 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_343 ) , V_341 ) ;
if ( V_15 )
return V_15 ;
F_200 ( V_341 , & V_331 , NULL , NULL ) ;
V_261 = V_295 -> V_321 . V_261 == V_344 ;
V_346 = V_261 ?
F_191 ( V_295 ) :
F_193 ( V_295 -> V_321 . V_316 ) ;
V_346 = V_346 & V_331 ;
if ( ! V_346 ) {
F_36 ( V_51 , L_18 ) ;
return - V_82 ;
}
F_199 ( V_341 , V_33 -> V_10 , V_346 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_343 ) , V_341 ) ;
if ( V_15 )
return V_15 ;
if ( ! F_204 ( V_51 ) )
return 0 ;
V_33 -> V_256 . V_261 = V_261 ;
F_47 ( V_33 , false ) ;
F_47 ( V_33 , true ) ;
return 0 ;
}
static int
F_205 ( struct V_33 * V_33 , T_1 V_115 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
T_5 V_330 = V_347 * V_115 ;
char V_341 [ V_342 ] ;
T_5 V_335 ;
V_335 = F_194 ( V_330 ) ;
F_199 ( V_341 , V_33 -> V_10 ,
V_335 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_343 ) , V_341 ) ;
}
int F_206 ( struct V_33 * V_33 ,
enum V_348 V_349 , T_1 V_38 , T_1 V_350 ,
bool V_351 , T_1 V_352 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_353 [ V_354 ] ;
F_207 ( V_353 , V_33 -> V_10 , V_349 , V_38 ,
V_350 ) ;
F_208 ( V_353 , true ) ;
F_209 ( V_353 , V_351 ) ;
F_210 ( V_353 , V_352 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_355 ) , V_353 ) ;
}
int F_211 ( struct V_33 * V_33 ,
enum V_348 V_349 , T_1 V_38 ,
T_1 V_350 , T_5 V_356 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_353 [ V_354 ] ;
F_207 ( V_353 , V_33 -> V_10 , V_349 , V_38 ,
V_350 ) ;
F_212 ( V_353 , true ) ;
F_213 ( V_353 , V_356 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_355 ) , V_353 ) ;
}
int F_214 ( struct V_33 * V_33 ,
T_1 V_357 , T_1 V_358 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_359 [ V_360 ] ;
F_215 ( V_359 , V_33 -> V_10 , V_357 ,
V_358 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_361 ) , V_359 ) ;
}
static int F_216 ( struct V_33 * V_33 )
{
int V_15 , V_21 ;
V_15 = F_206 ( V_33 ,
V_362 , 0 , 0 , false ,
0 ) ;
if ( V_15 )
return V_15 ;
for ( V_21 = 0 ; V_21 < V_146 ; V_21 ++ ) {
V_15 = F_206 ( V_33 ,
V_363 , V_21 ,
0 , false , 0 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_21 = 0 ; V_21 < V_146 ; V_21 ++ ) {
V_15 = F_206 ( V_33 ,
V_364 , V_21 , V_21 ,
false , 0 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = F_211 ( V_33 ,
V_365 , 0 , 0 ,
V_366 ) ;
if ( V_15 )
return V_15 ;
for ( V_21 = 0 ; V_21 < V_146 ; V_21 ++ ) {
V_15 = F_211 ( V_33 ,
V_363 ,
V_21 , 0 ,
V_366 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_21 = 0 ; V_21 < V_146 ; V_21 ++ ) {
V_15 = F_211 ( V_33 ,
V_364 ,
V_21 , V_21 ,
V_366 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_21 = 0 ; V_21 < V_146 ; V_21 ++ ) {
V_15 = F_214 ( V_33 , V_21 , 0 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_217 ( struct V_33 * V_33 )
{
V_33 -> V_367 = 1 ;
return F_143 ( V_33 -> V_51 , 0 , 1 ) ;
}
static int F_218 ( struct V_33 * V_33 )
{
return F_146 ( V_33 -> V_51 , 0 , 1 ) ;
}
static int F_219 ( struct V_12 * V_12 , T_1 V_10 ,
bool V_205 , T_1 V_114 , T_1 V_115 , T_1 V_116 )
{
struct V_33 * V_33 ;
struct V_117 * V_51 ;
T_8 V_368 ;
int V_15 ;
V_51 = F_220 ( sizeof( struct V_33 ) ) ;
if ( ! V_51 )
return - V_30 ;
V_33 = F_81 ( V_51 ) ;
V_33 -> V_51 = V_51 ;
V_33 -> V_12 = V_12 ;
V_33 -> V_10 = V_10 ;
V_33 -> V_205 = V_205 ;
V_33 -> V_204 . V_114 = V_114 ;
V_33 -> V_204 . V_115 = V_115 ;
V_33 -> V_204 . V_116 = V_116 ;
V_33 -> V_256 . V_261 = 1 ;
V_368 = F_221 ( V_189 , V_369 ) ;
V_33 -> V_370 = F_40 ( V_368 , V_29 ) ;
if ( ! V_33 -> V_370 ) {
V_15 = - V_30 ;
goto V_371;
}
V_33 -> V_372 = F_40 ( V_368 , V_29 ) ;
if ( ! V_33 -> V_372 ) {
V_15 = - V_30 ;
goto V_373;
}
F_17 ( & V_33 -> V_196 ) ;
F_17 ( & V_33 -> V_223 ) ;
V_33 -> V_119 =
F_222 ( struct V_118 ) ;
if ( ! V_33 -> V_119 ) {
V_15 = - V_30 ;
goto V_374;
}
V_33 -> V_177 . V_179 =
F_40 ( sizeof( * V_33 -> V_177 . V_179 ) , V_29 ) ;
if ( ! V_33 -> V_177 . V_179 ) {
V_15 = - V_30 ;
goto V_375;
}
F_223 ( & V_33 -> V_177 . V_178 ,
& F_130 ) ;
V_51 -> V_376 = & V_377 ;
V_51 -> V_378 = & V_379 ;
V_15 = F_59 ( V_33 , 0 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_19 ,
V_33 -> V_10 ) ;
goto V_380;
}
V_15 = F_52 ( V_33 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_20 ,
V_33 -> V_10 ) ;
goto V_381;
}
F_225 ( V_51 ) ;
V_51 -> V_382 |= V_383 | V_384 | V_385 |
V_386 | V_387 ;
V_51 -> V_388 |= V_387 ;
V_51 -> V_389 = V_6 ;
V_15 = F_68 ( V_33 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_21 ,
V_33 -> V_10 ) ;
goto V_390;
}
V_15 = F_205 ( V_33 , V_115 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_22 ,
V_33 -> V_10 ) ;
goto V_391;
}
V_15 = F_54 ( V_33 , V_392 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_23 ,
V_33 -> V_10 ) ;
goto V_154;
}
V_15 = F_47 ( V_33 , false ) ;
if ( V_15 )
goto V_393;
V_15 = F_226 ( V_33 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_24 ,
V_33 -> V_10 ) ;
goto V_394;
}
V_15 = F_216 ( V_33 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_25 ,
V_33 -> V_10 ) ;
goto V_395;
}
V_15 = F_227 ( V_33 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_26 ,
V_33 -> V_10 ) ;
goto V_396;
}
V_15 = F_217 ( V_33 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_27 ,
V_33 -> V_10 ) ;
goto V_397;
}
F_228 ( V_33 ) ;
V_12 -> V_230 [ V_10 ] = V_33 ;
V_15 = F_229 ( V_51 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_28 ,
V_33 -> V_10 ) ;
goto V_398;
}
V_15 = F_230 ( V_12 -> V_16 , & V_33 -> V_399 ,
V_33 -> V_10 , V_51 ,
V_33 -> V_205 , V_114 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_29 ,
V_33 -> V_10 ) ;
goto V_400;
}
F_133 ( & V_33 -> V_177 . V_178 , 0 ) ;
return 0 ;
V_400:
F_231 ( V_51 ) ;
V_398:
V_12 -> V_230 [ V_10 ] = NULL ;
F_232 ( V_33 ) ;
F_218 ( V_33 ) ;
V_397:
F_233 ( V_33 ) ;
V_396:
V_395:
V_394:
V_393:
V_154:
V_391:
V_390:
V_381:
F_59 ( V_33 , V_401 ) ;
V_380:
F_21 ( V_33 -> V_177 . V_179 ) ;
V_375:
F_234 ( V_33 -> V_119 ) ;
V_374:
F_21 ( V_33 -> V_372 ) ;
V_373:
F_21 ( V_33 -> V_370 ) ;
V_371:
F_235 ( V_51 ) ;
return V_15 ;
}
static void F_236 ( struct V_12 * V_12 , T_1 V_10 )
{
struct V_33 * V_33 = V_12 -> V_230 [ V_10 ] ;
if ( ! V_33 )
return;
F_237 ( & V_33 -> V_177 . V_178 ) ;
F_238 ( & V_33 -> V_399 ) ;
F_231 ( V_33 -> V_51 ) ;
V_12 -> V_230 [ V_10 ] = NULL ;
F_232 ( V_33 ) ;
F_218 ( V_33 ) ;
F_233 ( V_33 ) ;
F_59 ( V_33 , V_401 ) ;
F_79 ( V_12 , V_33 -> V_10 ) ;
F_234 ( V_33 -> V_119 ) ;
F_21 ( V_33 -> V_177 . V_179 ) ;
F_21 ( V_33 -> V_372 ) ;
F_21 ( V_33 -> V_370 ) ;
F_19 ( ! F_20 ( & V_33 -> V_196 ) ) ;
F_235 ( V_33 -> V_51 ) ;
}
static void F_239 ( struct V_12 * V_12 )
{
int V_21 ;
for ( V_21 = 1 ; V_21 < V_402 ; V_21 ++ )
F_236 ( V_12 , V_21 ) ;
F_21 ( V_12 -> V_230 ) ;
}
static int F_240 ( struct V_12 * V_12 )
{
T_1 V_114 , V_115 , V_116 ;
T_8 V_403 ;
int V_21 ;
int V_15 ;
V_403 = sizeof( struct V_33 * ) * V_402 ;
V_12 -> V_230 = F_40 ( V_403 , V_29 ) ;
if ( ! V_12 -> V_230 )
return - V_30 ;
for ( V_21 = 1 ; V_21 < V_402 ; V_21 ++ ) {
V_15 = F_70 ( V_12 , V_21 , & V_114 ,
& V_115 , & V_116 ) ;
if ( V_15 )
goto V_404;
if ( ! V_115 )
continue;
V_12 -> V_405 [ V_21 ] = V_114 ;
V_15 = F_219 ( V_12 , V_21 , false , V_114 , V_115 ,
V_116 ) ;
if ( V_15 )
goto V_406;
}
return 0 ;
V_406:
V_404:
for ( V_21 -- ; V_21 >= 1 ; V_21 -- )
F_236 ( V_12 , V_21 ) ;
F_21 ( V_12 -> V_230 ) ;
return V_15 ;
}
static T_1 F_241 ( T_1 V_10 )
{
T_1 V_407 = ( V_10 - 1 ) % V_408 ;
return V_10 - V_407 ;
}
static int F_242 ( struct V_12 * V_12 , T_1 V_409 ,
T_1 V_114 , unsigned int V_410 )
{
T_1 V_115 = V_411 / V_410 ;
int V_15 , V_21 ;
for ( V_21 = 0 ; V_21 < V_410 ; V_21 ++ ) {
V_15 = F_75 ( V_12 , V_409 + V_21 , V_114 ,
V_115 , V_21 * V_115 ) ;
if ( V_15 )
goto V_412;
}
for ( V_21 = 0 ; V_21 < V_410 ; V_21 ++ ) {
V_15 = F_57 ( V_12 , V_409 + V_21 , 0 ) ;
if ( V_15 )
goto V_380;
}
for ( V_21 = 0 ; V_21 < V_410 ; V_21 ++ ) {
V_15 = F_219 ( V_12 , V_409 + V_21 , true ,
V_114 , V_115 , V_21 * V_115 ) ;
if ( V_15 )
goto V_406;
}
return 0 ;
V_406:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- )
F_236 ( V_12 , V_409 + V_21 ) ;
V_21 = V_410 ;
V_380:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- )
F_57 ( V_12 , V_409 + V_21 ,
V_401 ) ;
V_21 = V_410 ;
V_412:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- )
F_79 ( V_12 , V_409 + V_21 ) ;
return V_15 ;
}
static void F_243 ( struct V_12 * V_12 ,
T_1 V_409 , unsigned int V_410 )
{
T_1 V_10 , V_114 , V_115 = V_411 ;
int V_21 ;
V_410 = V_410 / 2 ;
for ( V_21 = 0 ; V_21 < V_410 ; V_21 ++ ) {
V_10 = V_409 + V_21 * 2 ;
V_114 = V_12 -> V_405 [ V_10 ] ;
F_75 ( V_12 , V_10 , V_114 , V_115 ,
0 ) ;
}
for ( V_21 = 0 ; V_21 < V_410 ; V_21 ++ )
F_57 ( V_12 , V_409 + V_21 * 2 , 0 ) ;
for ( V_21 = 0 ; V_21 < V_410 ; V_21 ++ ) {
V_10 = V_409 + V_21 * 2 ;
V_114 = V_12 -> V_405 [ V_10 ] ;
F_219 ( V_12 , V_10 , false , V_114 ,
V_115 , 0 ) ;
}
}
static int F_244 ( struct V_413 * V_413 , T_1 V_10 ,
unsigned int V_410 )
{
struct V_12 * V_12 = F_245 ( V_413 ) ;
struct V_33 * V_33 ;
T_1 V_114 , V_414 , V_409 ;
int V_21 ;
int V_15 ;
V_33 = V_12 -> V_230 [ V_10 ] ;
if ( ! V_33 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_30 ,
V_10 ) ;
return - V_82 ;
}
V_114 = V_33 -> V_204 . V_114 ;
V_414 = V_33 -> V_204 . V_115 ;
if ( V_410 != 2 && V_410 != 4 ) {
F_36 ( V_33 -> V_51 , L_31 ) ;
return - V_82 ;
}
if ( V_414 != V_411 ) {
F_36 ( V_33 -> V_51 , L_32 ) ;
return - V_82 ;
}
if ( V_410 == 2 ) {
V_409 = V_10 ;
if ( V_12 -> V_230 [ V_409 + 1 ] ) {
F_36 ( V_33 -> V_51 , L_33 ) ;
return - V_82 ;
}
} else {
V_409 = F_241 ( V_10 ) ;
if ( V_12 -> V_230 [ V_409 + 1 ] ||
V_12 -> V_230 [ V_409 + 3 ] ) {
F_36 ( V_33 -> V_51 , L_33 ) ;
return - V_82 ;
}
}
for ( V_21 = 0 ; V_21 < V_410 ; V_21 ++ )
F_236 ( V_12 , V_409 + V_21 ) ;
V_15 = F_242 ( V_12 , V_409 , V_114 , V_410 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_34 ) ;
goto V_415;
}
return 0 ;
V_415:
F_243 ( V_12 , V_409 , V_410 ) ;
return V_15 ;
}
static int F_246 ( struct V_413 * V_413 , T_1 V_10 )
{
struct V_12 * V_12 = F_245 ( V_413 ) ;
struct V_33 * V_33 ;
T_1 V_414 , V_409 ;
unsigned int V_410 ;
int V_21 ;
V_33 = V_12 -> V_230 [ V_10 ] ;
if ( ! V_33 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_30 ,
V_10 ) ;
return - V_82 ;
}
if ( ! V_33 -> V_205 ) {
F_36 ( V_33 -> V_51 , L_35 ) ;
return - V_82 ;
}
V_414 = V_33 -> V_204 . V_115 ;
V_410 = V_414 == 1 ? 4 : 2 ;
V_409 = F_241 ( V_10 ) ;
if ( V_410 == 2 && V_10 >= V_409 + 2 )
V_409 = V_409 + 2 ;
for ( V_21 = 0 ; V_21 < V_410 ; V_21 ++ )
F_236 ( V_12 , V_409 + V_21 ) ;
F_243 ( V_12 , V_409 , V_410 ) ;
return 0 ;
}
static void F_247 ( const struct V_416 * V_417 ,
char * V_418 , void * V_419 )
{
struct V_12 * V_12 = V_419 ;
struct V_33 * V_33 ;
enum V_420 V_421 ;
T_1 V_10 ;
V_10 = F_248 ( V_418 ) ;
V_33 = V_12 -> V_230 [ V_10 ] ;
if ( ! V_33 )
return;
V_421 = F_249 ( V_418 ) ;
if ( V_421 == V_422 ) {
F_250 ( V_33 -> V_51 , L_36 ) ;
F_251 ( V_33 -> V_51 ) ;
} else {
F_250 ( V_33 -> V_51 , L_37 ) ;
F_225 ( V_33 -> V_51 ) ;
}
}
static int F_252 ( struct V_12 * V_12 ,
enum V_423 V_424 )
{
struct V_425 * V_426 ;
char V_427 [ V_428 ] ;
int V_15 ;
switch ( V_424 ) {
case V_429 :
V_426 = & V_430 ;
break;
}
V_15 = F_253 ( V_12 -> V_16 , V_426 , V_12 ) ;
if ( V_15 )
return V_15 ;
F_254 ( V_427 , V_431 , V_424 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_432 ) , V_427 ) ;
if ( V_15 )
goto V_433;
return 0 ;
V_433:
F_255 ( V_12 -> V_16 , V_426 , V_12 ) ;
return V_15 ;
}
static void F_256 ( struct V_12 * V_12 ,
enum V_423 V_424 )
{
struct V_425 * V_426 ;
switch ( V_424 ) {
case V_429 :
V_426 = & V_430 ;
break;
}
F_255 ( V_12 -> V_16 , V_426 , V_12 ) ;
}
static void F_257 ( struct V_1 * V_2 , T_1 V_10 ,
void * V_419 )
{
struct V_12 * V_12 = V_419 ;
struct V_33 * V_33 = V_12 -> V_230 [ V_10 ] ;
struct V_118 * V_119 ;
if ( F_87 ( ! V_33 ) ) {
F_258 ( V_12 -> V_247 -> V_51 , L_38 ,
V_10 ) ;
return;
}
V_2 -> V_51 = V_33 -> V_51 ;
V_119 = F_94 ( V_33 -> V_119 ) ;
F_95 ( & V_119 -> V_126 ) ;
V_119 -> V_157 ++ ;
V_119 -> V_158 += V_2 -> V_121 ;
F_96 ( & V_119 -> V_126 ) ;
V_2 -> V_226 = F_259 ( V_2 , V_2 -> V_51 ) ;
F_260 ( V_2 ) ;
}
static void F_261 ( struct V_1 * V_2 , T_1 V_10 ,
void * V_419 )
{
V_2 -> V_434 = 1 ;
return F_257 ( V_2 , V_10 , V_419 ) ;
}
static int F_262 ( struct V_12 * V_12 )
{
char V_435 [ V_436 ] ;
char V_427 [ V_428 ] ;
int V_21 ;
int V_15 ;
F_263 ( V_435 , V_437 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_438 ) , V_435 ) ;
if ( V_15 )
return V_15 ;
F_263 ( V_435 , V_439 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_438 ) , V_435 ) ;
if ( V_15 )
return V_15 ;
for ( V_21 = 0 ; V_21 < F_264 ( V_440 ) ; V_21 ++ ) {
V_15 = F_265 ( V_12 -> V_16 ,
& V_440 [ V_21 ] ,
V_12 ) ;
if ( V_15 )
goto V_441;
F_254 ( V_427 , V_440 [ V_21 ] . V_442 ,
V_440 [ V_21 ] . V_424 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_432 ) , V_427 ) ;
if ( V_15 )
goto V_443;
}
return 0 ;
V_443:
F_266 ( V_12 -> V_16 ,
& V_440 [ V_21 ] ,
V_12 ) ;
V_441:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- ) {
F_254 ( V_427 , V_444 ,
V_440 [ V_21 ] . V_424 ) ;
F_24 ( V_12 -> V_16 , F_12 ( V_432 ) , V_427 ) ;
F_266 ( V_12 -> V_16 ,
& V_440 [ V_21 ] ,
V_12 ) ;
}
return V_15 ;
}
static void F_267 ( struct V_12 * V_12 )
{
char V_427 [ V_428 ] ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_264 ( V_440 ) ; V_21 ++ ) {
F_254 ( V_427 , V_444 ,
V_440 [ V_21 ] . V_424 ) ;
F_24 ( V_12 -> V_16 , F_12 ( V_432 ) , V_427 ) ;
F_266 ( V_12 -> V_16 ,
& V_440 [ V_21 ] ,
V_12 ) ;
}
}
static int F_268 ( struct V_413 * V_413 ,
enum V_445 type ,
enum V_446 V_447 )
{
enum V_448 V_449 ;
enum V_450 V_451 ;
char V_452 [ V_453 ] ;
if ( V_447 == V_454 )
V_449 = V_455 ;
else
V_449 = V_456 ;
if ( type == V_457 )
V_451 = V_458 ;
else
V_451 = V_459 ;
F_269 ( V_452 , type , V_447 , V_449 ,
V_451 ) ;
return F_24 ( V_413 , F_12 ( V_460 ) , V_452 ) ;
}
static int F_270 ( struct V_12 * V_12 )
{
int type , V_15 ;
for ( type = 0 ; type < V_461 ; type ++ ) {
if ( type == V_462 )
continue;
V_15 = F_268 ( V_12 -> V_16 , type ,
V_454 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_268 ( V_12 -> V_16 , type ,
V_463 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_271 ( struct V_12 * V_12 )
{
struct V_19 * V_20 ;
char V_464 [ V_465 ] ;
int V_15 ;
F_272 ( V_464 , V_466 |
V_467 |
V_468 |
V_469 |
V_470 |
V_471 |
V_472 |
V_473 |
V_474 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_475 ) , V_464 ) ;
if ( V_15 )
return V_15 ;
V_20 = F_15 ( V_12 -> V_16 ) ;
if ( ! ( V_20 -> V_476 && V_20 -> V_477 ) )
return - V_23 ;
V_12 -> V_478 = F_16 ( V_20 -> V_479 ,
sizeof( struct V_480 ) ,
V_29 ) ;
if ( ! V_12 -> V_478 )
return - V_30 ;
return 0 ;
}
static void F_273 ( struct V_12 * V_12 )
{
F_21 ( V_12 -> V_478 ) ;
}
static int F_274 ( struct V_413 * V_413 ,
const struct V_481 * V_481 )
{
struct V_12 * V_12 = F_245 ( V_413 ) ;
int V_15 ;
V_12 -> V_16 = V_413 ;
V_12 -> V_247 = V_481 ;
F_17 ( & V_12 -> V_482 ) ;
F_17 ( & V_12 -> V_483 . V_60 ) ;
F_17 ( & V_12 -> V_484 . V_60 ) ;
V_15 = F_10 ( V_12 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_39 ) ;
return V_15 ;
}
V_15 = F_252 ( V_12 , V_429 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_40 ) ;
return V_15 ;
}
V_15 = F_262 ( V_12 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_41 ) ;
goto V_441;
}
V_15 = F_270 ( V_12 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_42 ) ;
goto V_485;
}
V_15 = F_275 ( V_12 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_43 ) ;
goto V_486;
}
V_15 = F_271 ( V_12 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_44 ) ;
goto V_487;
}
V_15 = F_276 ( V_12 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_45 ) ;
goto V_488;
}
V_15 = F_277 ( V_12 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_46 ) ;
goto V_489;
}
V_15 = F_14 ( V_12 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_47 ) ;
goto V_490;
}
V_15 = F_240 ( V_12 ) ;
if ( V_15 ) {
F_224 ( V_12 -> V_247 -> V_51 , L_48 ) ;
goto V_491;
}
return 0 ;
V_491:
F_18 ( V_12 ) ;
V_490:
F_278 ( V_12 ) ;
V_489:
F_279 ( V_12 ) ;
V_488:
F_273 ( V_12 ) ;
V_487:
F_280 ( V_12 ) ;
V_486:
V_485:
F_267 ( V_12 ) ;
V_441:
F_256 ( V_12 , V_429 ) ;
return V_15 ;
}
static void F_281 ( struct V_413 * V_413 )
{
struct V_12 * V_12 = F_245 ( V_413 ) ;
F_239 ( V_12 ) ;
F_18 ( V_12 ) ;
F_278 ( V_12 ) ;
F_279 ( V_12 ) ;
F_273 ( V_12 ) ;
F_280 ( V_12 ) ;
F_267 ( V_12 ) ;
F_256 ( V_12 , V_429 ) ;
F_29 ( ! F_20 ( & V_12 -> V_483 . V_60 ) ) ;
F_29 ( ! F_20 ( & V_12 -> V_482 ) ) ;
}
static bool F_154 ( const struct V_117 * V_51 )
{
return V_51 -> V_376 == & V_377 ;
}
static struct V_33 * F_282 ( struct V_117 * V_51 )
{
struct V_117 * V_492 ;
struct V_493 * V_494 ;
if ( F_154 ( V_51 ) )
return F_81 ( V_51 ) ;
F_283 (dev, lower_dev, iter) {
if ( F_154 ( V_492 ) )
return F_81 ( V_492 ) ;
}
return NULL ;
}
static struct V_12 * F_284 ( struct V_117 * V_51 )
{
struct V_33 * V_33 ;
V_33 = F_282 ( V_51 ) ;
return V_33 ? V_33 -> V_12 : NULL ;
}
static struct V_33 * F_285 ( struct V_117 * V_51 )
{
struct V_117 * V_492 ;
struct V_493 * V_494 ;
if ( F_154 ( V_51 ) )
return F_81 ( V_51 ) ;
F_286 (dev, lower_dev, iter) {
if ( F_154 ( V_492 ) )
return F_81 ( V_492 ) ;
}
return NULL ;
}
struct V_33 * F_287 ( struct V_117 * V_51 )
{
struct V_33 * V_33 ;
F_288 () ;
V_33 = F_285 ( V_51 ) ;
if ( V_33 )
F_289 ( V_33 -> V_51 ) ;
F_290 () ;
return V_33 ;
}
void F_291 ( struct V_33 * V_33 )
{
F_292 ( V_33 -> V_51 ) ;
}
static bool F_293 ( struct V_495 * V_496 ,
unsigned long V_497 )
{
switch ( V_497 ) {
case V_498 :
if ( ! V_496 )
return true ;
V_496 -> V_42 ++ ;
return false ;
case V_499 :
if ( V_496 && -- V_496 -> V_42 == 0 )
return true ;
return false ;
}
return false ;
}
static int F_294 ( struct V_12 * V_12 )
{
struct V_19 * V_20 ;
int V_21 ;
V_20 = F_15 ( V_12 -> V_16 ) ;
for ( V_21 = 0 ; V_21 < V_20 -> V_500 ; V_21 ++ )
if ( ! V_12 -> V_501 [ V_21 ] )
return V_21 ;
return V_502 ;
}
static void F_295 ( struct V_33 * V_190 ,
bool * V_503 , T_2 * V_504 )
{
T_1 V_10 = V_190 -> V_10 ;
* V_503 = V_190 -> V_193 ;
* V_504 = * V_503 ? V_190 -> V_194 : V_10 ;
}
static int F_296 ( struct V_33 * V_190 ,
struct V_117 * V_505 , T_2 V_506 ,
bool V_507 )
{
struct V_12 * V_12 = V_190 -> V_12 ;
bool V_193 = V_190 -> V_193 ;
char V_508 [ V_509 ] ;
T_2 V_510 ;
F_297 ( V_508 , V_507 , V_511 , V_506 ,
V_505 -> V_47 , V_505 -> V_75 ) ;
F_295 ( V_190 , & V_193 , & V_510 ) ;
F_298 ( V_508 , V_193 , V_510 ,
F_299 ( V_190 ) ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_512 ) , V_508 ) ;
}
static struct V_200 *
F_300 ( T_2 V_94 , struct V_117 * V_505 )
{
struct V_200 * V_201 ;
V_201 = F_40 ( sizeof( * V_201 ) , V_29 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_202 = V_513 ;
V_201 -> V_42 = 0 ;
V_201 -> V_51 = V_505 ;
V_201 -> V_94 = V_94 ;
return V_201 ;
}
static struct V_495 *
F_301 ( T_2 V_506 , struct V_117 * V_505 , struct V_200 * V_201 )
{
struct V_495 * V_496 ;
V_496 = F_40 ( sizeof( * V_496 ) , V_29 ) ;
if ( ! V_496 )
return NULL ;
F_53 ( V_496 -> V_71 , V_505 -> V_75 ) ;
V_496 -> V_47 = V_505 -> V_47 ;
V_496 -> V_42 = 1 ;
V_496 -> V_51 = V_505 ;
V_496 -> V_506 = V_506 ;
V_496 -> V_201 = V_201 ;
return V_496 ;
}
static struct V_495 *
F_302 ( struct V_33 * V_190 ,
struct V_117 * V_505 )
{
struct V_12 * V_12 = V_190 -> V_12 ;
struct V_200 * V_201 ;
struct V_495 * V_496 ;
T_2 V_94 , V_506 ;
int V_15 ;
V_506 = F_294 ( V_12 ) ;
if ( V_506 == V_502 )
return F_303 ( - V_514 ) ;
V_15 = F_296 ( V_190 , V_505 , V_506 , true ) ;
if ( V_15 )
return F_303 ( V_15 ) ;
V_94 = F_304 ( V_506 ) ;
V_15 = F_305 ( V_12 , V_505 -> V_75 , V_94 , true ) ;
if ( V_15 )
goto V_515;
V_201 = F_300 ( V_94 , V_505 ) ;
if ( ! V_201 ) {
V_15 = - V_30 ;
goto V_516;
}
V_496 = F_301 ( V_506 , V_505 , V_201 ) ;
if ( ! V_496 ) {
V_15 = - V_30 ;
goto V_517;
}
V_201 -> V_496 = V_496 ;
V_12 -> V_501 [ V_506 ] = V_496 ;
return V_496 ;
V_517:
F_21 ( V_201 ) ;
V_516:
F_305 ( V_12 , V_505 -> V_75 , V_94 , false ) ;
V_515:
F_296 ( V_190 , V_505 , V_506 , false ) ;
return F_303 ( V_15 ) ;
}
static void F_306 ( struct V_33 * V_190 ,
struct V_495 * V_496 )
{
struct V_12 * V_12 = V_190 -> V_12 ;
struct V_117 * V_505 = V_496 -> V_51 ;
struct V_200 * V_201 = V_496 -> V_201 ;
T_2 V_94 = V_201 -> V_94 ;
T_2 V_506 = V_496 -> V_506 ;
V_12 -> V_501 [ V_506 ] = NULL ;
V_201 -> V_496 = NULL ;
F_21 ( V_496 ) ;
F_21 ( V_201 ) ;
F_305 ( V_12 , V_505 -> V_75 , V_94 , false ) ;
F_296 ( V_190 , V_505 , V_506 , false ) ;
}
static int F_307 ( struct V_33 * V_190 ,
struct V_117 * V_505 )
{
struct V_12 * V_12 = V_190 -> V_12 ;
struct V_495 * V_496 ;
V_496 = F_308 ( V_12 , V_505 ) ;
if ( ! V_496 ) {
V_496 = F_302 ( V_190 , V_505 ) ;
if ( F_309 ( V_496 ) )
return F_310 ( V_496 ) ;
}
F_311 ( V_190 , V_496 -> V_201 ) ;
V_496 -> V_201 -> V_42 ++ ;
F_45 ( V_190 -> V_51 , L_49 , V_496 -> V_201 -> V_94 ) ;
return 0 ;
}
static void V_513 ( struct V_33 * V_190 )
{
struct V_200 * V_201 = F_147 ( V_190 ) ;
F_45 ( V_190 -> V_51 , L_50 , V_201 -> V_94 ) ;
F_311 ( V_190 , NULL ) ;
if ( -- V_201 -> V_42 == 0 )
F_306 ( V_190 , V_201 -> V_496 ) ;
}
static int F_312 ( struct V_117 * V_505 ,
struct V_117 * V_518 ,
unsigned long V_497 , T_2 V_95 )
{
struct V_33 * V_33 = F_81 ( V_518 ) ;
struct V_33 * V_190 ;
V_190 = F_144 ( V_33 , V_95 ) ;
if ( F_29 ( ! V_190 ) )
return - V_82 ;
switch ( V_497 ) {
case V_498 :
return F_307 ( V_190 , V_505 ) ;
case V_499 :
V_513 ( V_190 ) ;
break;
}
return 0 ;
}
static int F_313 ( struct V_117 * V_518 ,
unsigned long V_497 )
{
if ( F_314 ( V_518 ) || F_315 ( V_518 ) )
return 0 ;
return F_312 ( V_518 , V_518 , V_497 , 1 ) ;
}
static int F_316 ( struct V_117 * V_505 ,
struct V_117 * V_519 ,
unsigned long V_497 , T_2 V_95 )
{
struct V_117 * V_518 ;
struct V_493 * V_494 ;
int V_15 ;
F_317 (lag_dev, port_dev, iter) {
if ( F_154 ( V_518 ) ) {
V_15 = F_312 ( V_505 , V_518 ,
V_497 , V_95 ) ;
if ( V_15 )
return V_15 ;
}
}
return 0 ;
}
static int F_318 ( struct V_117 * V_519 ,
unsigned long V_497 )
{
if ( F_314 ( V_519 ) )
return 0 ;
return F_316 ( V_519 , V_519 , V_497 , 1 ) ;
}
static struct V_200 * F_319 ( struct V_12 * V_12 ,
struct V_117 * V_505 )
{
T_2 V_94 ;
if ( F_320 ( V_505 ) )
V_94 = F_321 ( V_505 ) ;
else if ( V_12 -> V_520 . V_51 == V_505 )
V_94 = 1 ;
else
return F_322 ( V_12 , V_505 ) ;
return F_323 ( V_12 , V_94 ) ;
}
static enum V_448 F_324 ( T_2 V_94 )
{
return F_325 ( V_94 ) ? V_455 :
V_456 ;
}
static T_2 F_326 ( T_2 V_94 )
{
return F_325 ( V_94 ) ? F_327 ( V_94 ) : V_94 ;
}
static int F_328 ( struct V_12 * V_12 , T_2 V_94 ,
bool V_521 )
{
enum V_448 V_449 ;
char * V_522 ;
T_2 V_38 ;
int V_15 ;
V_522 = F_65 ( V_523 , V_29 ) ;
if ( ! V_522 )
return - V_30 ;
V_449 = F_324 ( V_94 ) ;
V_38 = F_326 ( V_94 ) ;
F_329 ( V_522 , V_459 , V_38 , V_449 ,
1 , V_524 , V_521 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_525 ) , V_522 ) ;
F_21 ( V_522 ) ;
return V_15 ;
}
static enum V_526 F_330 ( T_2 V_94 )
{
if ( F_325 ( V_94 ) )
return V_527 ;
else
return V_528 ;
}
static int F_331 ( struct V_12 * V_12 ,
struct V_117 * V_505 ,
T_2 V_94 , T_2 V_506 ,
bool V_507 )
{
enum V_526 V_529 ;
char V_508 [ V_509 ] ;
V_529 = F_330 ( V_94 ) ;
F_297 ( V_508 , V_507 , V_529 , V_506 , V_505 -> V_47 ,
V_505 -> V_75 ) ;
F_332 ( V_508 , V_529 , V_94 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_512 ) , V_508 ) ;
}
static int F_333 ( struct V_12 * V_12 ,
struct V_117 * V_505 ,
struct V_200 * V_201 )
{
struct V_495 * V_496 ;
T_2 V_506 ;
int V_15 ;
V_506 = F_294 ( V_12 ) ;
if ( V_506 == V_502 )
return - V_514 ;
V_15 = F_328 ( V_12 , V_201 -> V_94 , true ) ;
if ( V_15 )
return V_15 ;
V_15 = F_331 ( V_12 , V_505 , V_201 -> V_94 , V_506 , true ) ;
if ( V_15 )
goto V_530;
V_15 = F_305 ( V_12 , V_505 -> V_75 , V_201 -> V_94 , true ) ;
if ( V_15 )
goto V_515;
V_496 = F_301 ( V_506 , V_505 , V_201 ) ;
if ( ! V_496 ) {
V_15 = - V_30 ;
goto V_517;
}
V_201 -> V_496 = V_496 ;
V_12 -> V_501 [ V_506 ] = V_496 ;
F_45 ( V_505 , L_51 , V_506 ) ;
return 0 ;
V_517:
F_305 ( V_12 , V_505 -> V_75 , V_201 -> V_94 , false ) ;
V_515:
F_331 ( V_12 , V_505 , V_201 -> V_94 , V_506 , false ) ;
V_530:
F_328 ( V_12 , V_201 -> V_94 , false ) ;
return V_15 ;
}
void F_334 ( struct V_12 * V_12 ,
struct V_495 * V_496 )
{
struct V_117 * V_505 = V_496 -> V_51 ;
struct V_200 * V_201 = V_496 -> V_201 ;
T_2 V_506 = V_496 -> V_506 ;
V_12 -> V_501 [ V_506 ] = NULL ;
V_201 -> V_496 = NULL ;
F_21 ( V_496 ) ;
F_305 ( V_12 , V_505 -> V_75 , V_201 -> V_94 , false ) ;
F_331 ( V_12 , V_505 , V_201 -> V_94 , V_506 , false ) ;
F_328 ( V_12 , V_201 -> V_94 , false ) ;
F_45 ( V_505 , L_52 , V_506 ) ;
}
static int F_335 ( struct V_117 * V_505 ,
struct V_117 * V_531 ,
unsigned long V_497 )
{
struct V_12 * V_12 = F_284 ( V_505 ) ;
struct V_200 * V_201 ;
V_201 = F_319 ( V_12 , V_505 ) ;
if ( F_29 ( ! V_201 ) )
return - V_82 ;
switch ( V_497 ) {
case V_498 :
return F_333 ( V_12 , V_505 , V_201 ) ;
case V_499 :
F_334 ( V_12 , V_201 -> V_496 ) ;
break;
}
return 0 ;
}
static int F_336 ( struct V_117 * V_532 ,
unsigned long V_497 )
{
struct V_117 * V_533 = F_337 ( V_532 ) ;
struct V_12 * V_12 = F_284 ( V_532 ) ;
T_2 V_95 = F_321 ( V_532 ) ;
if ( F_154 ( V_533 ) )
return F_312 ( V_532 , V_533 , V_497 ,
V_95 ) ;
else if ( F_338 ( V_533 ) )
return F_316 ( V_532 , V_533 , V_497 ,
V_95 ) ;
else if ( F_339 ( V_533 ) &&
V_12 -> V_520 . V_51 == V_533 )
return F_335 ( V_532 , V_533 ,
V_497 ) ;
return 0 ;
}
static int F_340 ( struct V_534 * V_535 ,
unsigned long V_497 , void * V_536 )
{
struct V_537 * V_538 = (struct V_537 * ) V_536 ;
struct V_117 * V_51 = V_538 -> V_539 -> V_51 ;
struct V_12 * V_12 ;
struct V_495 * V_496 ;
int V_15 = 0 ;
V_12 = F_284 ( V_51 ) ;
if ( ! V_12 )
goto V_169;
V_496 = F_308 ( V_12 , V_51 ) ;
if ( ! F_293 ( V_496 , V_497 ) )
goto V_169;
if ( F_154 ( V_51 ) )
V_15 = F_313 ( V_51 , V_497 ) ;
else if ( F_338 ( V_51 ) )
V_15 = F_318 ( V_51 , V_497 ) ;
else if ( F_339 ( V_51 ) )
V_15 = F_335 ( V_51 , V_51 , V_497 ) ;
else if ( F_320 ( V_51 ) )
V_15 = F_336 ( V_51 , V_497 ) ;
V_169:
return F_341 ( V_15 ) ;
}
static int F_342 ( struct V_12 * V_12 , T_2 V_506 ,
const char * V_540 , int V_47 )
{
char V_508 [ V_509 ] ;
int V_15 ;
F_343 ( V_508 , V_506 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_512 ) , V_508 ) ;
if ( V_15 )
return V_15 ;
F_344 ( V_508 , V_47 ) ;
F_345 ( V_508 , V_540 ) ;
F_346 ( V_508 , V_541 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_512 ) , V_508 ) ;
}
static int F_347 ( struct V_117 * V_51 )
{
struct V_12 * V_12 ;
struct V_495 * V_496 ;
int V_15 ;
V_12 = F_284 ( V_51 ) ;
if ( ! V_12 )
return 0 ;
V_496 = F_308 ( V_12 , V_51 ) ;
if ( ! V_496 )
return 0 ;
V_15 = F_305 ( V_12 , V_496 -> V_71 , V_496 -> V_201 -> V_94 , false ) ;
if ( V_15 )
return V_15 ;
V_15 = F_342 ( V_12 , V_496 -> V_506 , V_51 -> V_75 , V_51 -> V_47 ) ;
if ( V_15 )
goto V_542;
V_15 = F_305 ( V_12 , V_51 -> V_75 , V_496 -> V_201 -> V_94 , true ) ;
if ( V_15 )
goto V_515;
F_53 ( V_496 -> V_71 , V_51 -> V_75 ) ;
V_496 -> V_47 = V_51 -> V_47 ;
F_45 ( V_51 , L_53 , V_496 -> V_506 ) ;
return 0 ;
V_515:
F_342 ( V_12 , V_496 -> V_506 , V_496 -> V_71 , V_496 -> V_47 ) ;
V_542:
F_305 ( V_12 , V_496 -> V_71 , V_496 -> V_201 -> V_94 , true ) ;
return V_15 ;
}
static bool F_348 ( struct V_33 * V_543 ,
T_2 V_94 )
{
if ( F_325 ( V_94 ) )
return F_349 ( V_543 , V_94 ) ;
else
return F_192 ( V_94 , V_543 -> V_370 ) ;
}
static bool F_350 ( struct V_33 * V_33 ,
T_2 V_94 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
T_1 V_10 = V_33 -> V_10 ;
T_2 V_194 = V_33 -> V_194 ;
struct V_19 * V_20 ;
int V_21 , V_410 = 0 ;
if ( ! V_33 -> V_193 )
return true ;
V_20 = F_15 ( V_12 -> V_16 ) ;
for ( V_21 = 0 ; V_21 < V_20 -> V_544 ; V_21 ++ ) {
struct V_33 * V_543 ;
V_543 = F_351 ( V_12 , V_194 , V_21 ) ;
if ( ! V_543 || V_543 -> V_10 == V_10 )
continue;
if ( F_348 ( V_543 , V_94 ) )
V_410 ++ ;
}
return ! V_410 ;
}
static int
F_352 ( const struct V_33 * V_33 ,
T_2 V_94 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_545 [ V_546 ] ;
F_353 ( V_545 , V_547 ) ;
F_354 ( V_545 , V_94 ) ;
F_355 ( V_545 ,
V_33 -> V_10 ) ;
F_45 ( V_33 -> V_51 , L_54 ,
V_33 -> V_10 , V_94 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_548 ) , V_545 ) ;
}
static int
F_356 ( const struct V_33 * V_33 ,
T_2 V_94 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_545 [ V_546 ] ;
F_353 ( V_545 , V_549 ) ;
F_354 ( V_545 , V_94 ) ;
F_357 ( V_545 , V_33 -> V_194 ) ;
F_45 ( V_33 -> V_51 , L_55 ,
V_33 -> V_194 , V_94 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_548 ) , V_545 ) ;
}
int F_358 ( struct V_33 * V_33 , T_2 V_94 )
{
if ( ! F_350 ( V_33 , V_94 ) )
return 0 ;
if ( V_33 -> V_193 )
return F_356 ( V_33 ,
V_94 ) ;
else
return F_352 ( V_33 , V_94 ) ;
}
static void F_359 ( struct V_12 * V_12 )
{
struct V_200 * V_201 , * V_550 ;
F_360 (f, tmp, &mlxsw_sp->fids, list)
if ( -- V_201 -> V_42 == 0 )
F_361 ( V_12 , V_201 ) ;
else
F_19 ( 1 ) ;
}
static bool F_362 ( struct V_12 * V_12 ,
struct V_117 * V_531 )
{
return ! V_12 -> V_520 . V_51 ||
V_12 -> V_520 . V_51 == V_531 ;
}
static void F_363 ( struct V_12 * V_12 ,
struct V_117 * V_531 )
{
V_12 -> V_520 . V_51 = V_531 ;
V_12 -> V_520 . V_42 ++ ;
}
static void F_364 ( struct V_12 * V_12 )
{
if ( -- V_12 -> V_520 . V_42 == 0 ) {
V_12 -> V_520 . V_51 = NULL ;
F_359 ( V_12 ) ;
}
}
static int F_365 ( struct V_33 * V_33 ,
struct V_117 * V_531 )
{
struct V_117 * V_51 = V_33 -> V_51 ;
int V_15 ;
V_15 = F_146 ( V_51 , 0 , 1 ) ;
if ( V_15 )
return V_15 ;
F_363 ( V_33 -> V_12 , V_531 ) ;
V_33 -> V_551 = 1 ;
V_33 -> V_552 = 1 ;
V_33 -> V_553 = 1 ;
V_33 -> V_554 = 1 ;
return 0 ;
}
static void F_366 ( struct V_33 * V_33 )
{
struct V_117 * V_51 = V_33 -> V_51 ;
F_367 ( V_33 , 1 ) ;
F_364 ( V_33 -> V_12 ) ;
V_33 -> V_551 = 0 ;
V_33 -> V_552 = 0 ;
V_33 -> V_553 = 0 ;
V_33 -> V_554 = 0 ;
F_143 ( V_51 , 0 , 1 ) ;
}
static int F_368 ( struct V_12 * V_12 , T_2 V_194 )
{
char V_555 [ V_556 ] ;
F_369 ( V_555 , V_194 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_557 ) , V_555 ) ;
}
static int F_370 ( struct V_12 * V_12 , T_2 V_194 )
{
char V_555 [ V_556 ] ;
F_371 ( V_555 , V_194 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_557 ) , V_555 ) ;
}
static int F_372 ( struct V_33 * V_33 ,
T_2 V_194 , T_1 V_558 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_559 [ V_560 ] ;
F_373 ( V_559 , V_33 -> V_10 ,
V_194 , V_558 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_561 ) , V_559 ) ;
}
static int F_374 ( struct V_33 * V_33 ,
T_2 V_194 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_559 [ V_560 ] ;
F_375 ( V_559 , V_33 -> V_10 ,
V_194 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_561 ) , V_559 ) ;
}
static int F_376 ( struct V_33 * V_33 ,
T_2 V_194 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_559 [ V_560 ] ;
F_377 ( V_559 , V_33 -> V_10 ,
V_194 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_561 ) , V_559 ) ;
}
static int F_378 ( struct V_33 * V_33 ,
T_2 V_194 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_559 [ V_560 ] ;
F_379 ( V_559 , V_33 -> V_10 ,
V_194 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_561 ) , V_559 ) ;
}
static int F_380 ( struct V_12 * V_12 ,
struct V_117 * V_519 ,
T_2 * V_562 )
{
struct V_19 * V_20 ;
struct V_480 * V_563 ;
int V_564 = - 1 ;
int V_21 ;
V_20 = F_15 ( V_12 -> V_16 ) ;
for ( V_21 = 0 ; V_21 < V_20 -> V_479 ; V_21 ++ ) {
V_563 = F_381 ( V_12 , V_21 ) ;
if ( V_563 -> V_42 ) {
if ( V_563 -> V_51 == V_519 ) {
* V_562 = V_21 ;
return 0 ;
}
} else if ( V_564 < 0 ) {
V_564 = V_21 ;
}
}
if ( V_564 < 0 )
return - V_565 ;
* V_562 = V_564 ;
return 0 ;
}
static bool
F_382 ( struct V_12 * V_12 ,
struct V_117 * V_519 ,
struct V_566 * V_567 )
{
T_2 V_194 ;
if ( F_380 ( V_12 , V_519 , & V_194 ) != 0 )
return false ;
if ( V_567 -> V_568 != V_569 )
return false ;
return true ;
}
static int F_383 ( struct V_12 * V_12 ,
T_2 V_194 , T_1 * V_570 )
{
struct V_19 * V_20 ;
int V_21 ;
V_20 = F_15 ( V_12 -> V_16 ) ;
for ( V_21 = 0 ; V_21 < V_20 -> V_544 ; V_21 ++ ) {
if ( ! F_351 ( V_12 , V_194 , V_21 ) ) {
* V_570 = V_21 ;
return 0 ;
}
}
return - V_565 ;
}
static void
F_384 ( struct V_33 * V_33 ,
T_2 V_194 )
{
struct V_33 * V_190 ;
struct V_200 * V_201 ;
V_190 = F_144 ( V_33 , 1 ) ;
if ( F_29 ( ! V_190 ) )
return;
V_201 = F_147 ( V_190 ) ;
if ( V_201 )
V_201 -> V_202 ( V_190 ) ;
V_190 -> V_194 = V_194 ;
V_190 -> V_193 = 1 ;
}
static void
F_385 ( struct V_33 * V_33 )
{
struct V_33 * V_190 ;
struct V_200 * V_201 ;
V_190 = F_144 ( V_33 , 1 ) ;
if ( F_29 ( ! V_190 ) )
return;
V_201 = F_147 ( V_190 ) ;
if ( V_201 )
V_201 -> V_202 ( V_190 ) ;
V_190 -> V_193 = 0 ;
}
static int F_386 ( struct V_33 * V_33 ,
struct V_117 * V_519 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
struct V_480 * V_563 ;
T_2 V_194 ;
T_1 V_558 ;
int V_15 ;
V_15 = F_380 ( V_12 , V_519 , & V_194 ) ;
if ( V_15 )
return V_15 ;
V_563 = F_381 ( V_12 , V_194 ) ;
if ( ! V_563 -> V_42 ) {
V_15 = F_368 ( V_12 , V_194 ) ;
if ( V_15 )
return V_15 ;
V_563 -> V_51 = V_519 ;
}
V_15 = F_383 ( V_12 , V_194 , & V_558 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_372 ( V_33 , V_194 , V_558 ) ;
if ( V_15 )
goto V_571;
V_15 = F_376 ( V_33 , V_194 ) ;
if ( V_15 )
goto V_572;
F_387 ( V_12 -> V_16 , V_194 , V_558 ,
V_33 -> V_10 ) ;
V_33 -> V_194 = V_194 ;
V_33 -> V_193 = 1 ;
V_563 -> V_42 ++ ;
F_384 ( V_33 , V_194 ) ;
return 0 ;
V_572:
F_374 ( V_33 , V_194 ) ;
V_571:
if ( ! V_563 -> V_42 )
F_370 ( V_12 , V_194 ) ;
return V_15 ;
}
static void F_388 ( struct V_33 * V_33 ,
struct V_117 * V_519 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
T_2 V_194 = V_33 -> V_194 ;
struct V_480 * V_563 ;
if ( ! V_33 -> V_193 )
return;
V_563 = F_381 ( V_12 , V_194 ) ;
F_29 ( V_563 -> V_42 == 0 ) ;
F_378 ( V_33 , V_194 ) ;
F_374 ( V_33 , V_194 ) ;
if ( V_33 -> V_554 ) {
F_389 ( V_33 ) ;
F_366 ( V_33 ) ;
}
if ( V_563 -> V_42 == 1 )
F_370 ( V_12 , V_194 ) ;
F_390 ( V_12 -> V_16 , V_194 ,
V_33 -> V_10 ) ;
V_33 -> V_193 = 0 ;
V_563 -> V_42 -- ;
F_385 ( V_33 ) ;
}
static int F_391 ( struct V_33 * V_33 ,
T_2 V_194 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_555 [ V_556 ] ;
F_392 ( V_555 , V_194 ,
V_33 -> V_10 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_557 ) , V_555 ) ;
}
static int F_393 ( struct V_33 * V_33 ,
T_2 V_194 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_555 [ V_556 ] ;
F_394 ( V_555 , V_194 ,
V_33 -> V_10 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_557 ) , V_555 ) ;
}
static int F_395 ( struct V_33 * V_33 ,
bool V_573 )
{
if ( V_573 )
return F_391 ( V_33 ,
V_33 -> V_194 ) ;
else
return F_393 ( V_33 ,
V_33 -> V_194 ) ;
}
static int F_396 ( struct V_33 * V_33 ,
struct V_574 * V_575 )
{
return F_395 ( V_33 , V_575 -> V_576 ) ;
}
static int F_397 ( struct V_33 * V_33 ,
struct V_117 * V_532 )
{
struct V_33 * V_190 ;
T_2 V_95 = F_321 ( V_532 ) ;
V_190 = F_144 ( V_33 , V_95 ) ;
if ( F_29 ( ! V_190 ) )
return - V_82 ;
V_190 -> V_51 = V_532 ;
return 0 ;
}
static void F_398 ( struct V_33 * V_33 ,
struct V_117 * V_532 )
{
struct V_33 * V_190 ;
T_2 V_95 = F_321 ( V_532 ) ;
V_190 = F_144 ( V_33 , V_95 ) ;
if ( F_29 ( ! V_190 ) )
return;
V_190 -> V_51 = V_33 -> V_51 ;
}
static int F_399 ( struct V_117 * V_51 ,
unsigned long V_497 , void * V_536 )
{
struct V_577 * V_575 ;
struct V_33 * V_33 ;
struct V_117 * V_578 ;
struct V_12 * V_12 ;
int V_15 = 0 ;
V_33 = F_81 ( V_51 ) ;
V_12 = V_33 -> V_12 ;
V_575 = V_536 ;
switch ( V_497 ) {
case V_579 :
V_578 = V_575 -> V_578 ;
if ( ! F_320 ( V_578 ) &&
! F_338 ( V_578 ) &&
! F_339 ( V_578 ) )
return - V_82 ;
if ( ! V_575 -> V_580 )
break;
if ( F_339 ( V_578 ) &&
! F_362 ( V_12 , V_578 ) )
return - V_82 ;
if ( F_338 ( V_578 ) &&
! F_382 ( V_12 , V_578 ,
V_575 -> V_581 ) )
return - V_82 ;
if ( F_338 ( V_578 ) && F_400 ( V_51 ) )
return - V_82 ;
if ( F_315 ( V_51 ) && F_320 ( V_578 ) &&
! F_338 ( F_337 ( V_578 ) ) )
return - V_82 ;
break;
case V_582 :
V_578 = V_575 -> V_578 ;
if ( F_320 ( V_578 ) ) {
if ( V_575 -> V_580 )
V_15 = F_397 ( V_33 ,
V_578 ) ;
else
F_398 ( V_33 ,
V_578 ) ;
} else if ( F_339 ( V_578 ) ) {
if ( V_575 -> V_580 )
V_15 = F_365 ( V_33 ,
V_578 ) ;
else
F_366 ( V_33 ) ;
} else if ( F_338 ( V_578 ) ) {
if ( V_575 -> V_580 )
V_15 = F_386 ( V_33 ,
V_578 ) ;
else
F_388 ( V_33 ,
V_578 ) ;
} else {
V_15 = - V_82 ;
F_29 ( 1 ) ;
}
break;
}
return V_15 ;
}
static int F_401 ( struct V_117 * V_51 ,
unsigned long V_497 , void * V_536 )
{
struct V_583 * V_575 ;
struct V_33 * V_33 ;
int V_15 ;
V_33 = F_81 ( V_51 ) ;
V_575 = V_536 ;
switch ( V_497 ) {
case V_584 :
if ( F_315 ( V_51 ) && V_33 -> V_193 ) {
V_15 = F_396 ( V_33 ,
V_575 -> V_585 ) ;
if ( V_15 )
F_36 ( V_51 , L_56 ) ;
}
break;
}
return 0 ;
}
static int F_402 ( struct V_117 * V_51 ,
unsigned long V_497 , void * V_536 )
{
switch ( V_497 ) {
case V_579 :
case V_582 :
return F_399 ( V_51 , V_497 , V_536 ) ;
case V_584 :
return F_401 ( V_51 , V_497 , V_536 ) ;
}
return 0 ;
}
static int F_403 ( struct V_117 * V_519 ,
unsigned long V_497 , void * V_536 )
{
struct V_117 * V_51 ;
struct V_493 * V_494 ;
int V_586 ;
F_317 (lag_dev, dev, iter) {
if ( F_154 ( V_51 ) ) {
V_586 = F_402 ( V_51 , V_497 , V_536 ) ;
if ( V_586 )
return V_586 ;
}
}
return 0 ;
}
static int F_404 ( struct V_12 * V_12 ,
struct V_117 * V_532 )
{
T_2 V_94 = F_321 ( V_532 ) ;
struct V_200 * V_201 ;
V_201 = F_323 ( V_12 , V_94 ) ;
if ( ! V_201 ) {
V_201 = F_405 ( V_12 , V_94 ) ;
if ( F_309 ( V_201 ) )
return F_310 ( V_201 ) ;
}
V_201 -> V_42 ++ ;
return 0 ;
}
static void F_406 ( struct V_12 * V_12 ,
struct V_117 * V_532 )
{
T_2 V_94 = F_321 ( V_532 ) ;
struct V_200 * V_201 ;
V_201 = F_323 ( V_12 , V_94 ) ;
if ( V_201 && V_201 -> V_496 )
F_334 ( V_12 , V_201 -> V_496 ) ;
if ( V_201 && -- V_201 -> V_42 == 0 )
F_361 ( V_12 , V_201 ) ;
}
static int F_407 ( struct V_117 * V_531 ,
unsigned long V_497 , void * V_536 )
{
struct V_577 * V_575 ;
struct V_117 * V_578 ;
struct V_12 * V_12 ;
int V_15 ;
V_12 = F_284 ( V_531 ) ;
if ( ! V_12 )
return 0 ;
if ( V_531 != V_12 -> V_520 . V_51 )
return 0 ;
V_575 = V_536 ;
switch ( V_497 ) {
case V_582 :
V_578 = V_575 -> V_578 ;
if ( ! F_320 ( V_578 ) )
break;
if ( V_575 -> V_580 ) {
V_15 = F_404 ( V_12 ,
V_578 ) ;
if ( V_15 )
return V_15 ;
} else {
F_406 ( V_12 , V_578 ) ;
}
break;
}
return 0 ;
}
static T_2 F_408 ( const struct V_12 * V_12 )
{
return F_409 ( V_12 -> V_483 . V_587 ,
V_588 ) ;
}
static int F_410 ( struct V_12 * V_12 , T_2 V_94 , bool V_507 )
{
char V_589 [ V_590 ] ;
F_411 ( V_589 , ! V_507 , V_94 , 0 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_591 ) , V_589 ) ;
}
static struct V_200 * F_412 ( struct V_12 * V_12 ,
struct V_117 * V_531 )
{
struct V_592 * V_51 = V_12 -> V_247 -> V_51 ;
struct V_200 * V_201 ;
T_2 V_593 , V_94 ;
int V_15 ;
V_593 = F_408 ( V_12 ) ;
if ( V_593 == V_588 ) {
F_224 ( V_51 , L_57 ) ;
return F_303 ( - V_514 ) ;
}
V_94 = F_413 ( V_593 ) ;
V_15 = F_410 ( V_12 , V_94 , true ) ;
if ( V_15 ) {
F_224 ( V_51 , L_58 , V_94 ) ;
return F_303 ( V_15 ) ;
}
V_201 = F_40 ( sizeof( * V_201 ) , V_29 ) ;
if ( ! V_201 )
goto V_594;
V_201 -> V_202 = V_595 ;
V_201 -> V_94 = V_94 ;
V_201 -> V_51 = V_531 ;
F_141 ( & V_201 -> V_60 , & V_12 -> V_483 . V_60 ) ;
F_414 ( V_593 , V_12 -> V_483 . V_587 ) ;
return V_201 ;
V_594:
F_410 ( V_12 , V_94 , false ) ;
return F_303 ( - V_30 ) ;
}
static void F_415 ( struct V_12 * V_12 ,
struct V_200 * V_201 )
{
T_2 V_593 = F_327 ( V_201 -> V_94 ) ;
T_2 V_94 = V_201 -> V_94 ;
F_416 ( V_593 , V_12 -> V_483 . V_587 ) ;
F_43 ( & V_201 -> V_60 ) ;
if ( V_201 -> V_496 )
F_334 ( V_12 , V_201 -> V_496 ) ;
F_21 ( V_201 ) ;
F_410 ( V_12 , V_94 , false ) ;
}
static int F_417 ( struct V_33 * V_190 , T_2 V_94 ,
bool V_93 )
{
enum V_91 V_92 = V_186 ;
T_2 V_95 = F_299 ( V_190 ) ;
return F_62 ( V_190 , V_92 , V_93 , V_94 ,
V_95 ) ;
}
static int F_418 ( struct V_33 * V_190 ,
struct V_117 * V_531 )
{
struct V_200 * V_201 ;
int V_15 ;
V_201 = F_322 ( V_190 -> V_12 , V_531 ) ;
if ( ! V_201 ) {
V_201 = F_412 ( V_190 -> V_12 , V_531 ) ;
if ( F_309 ( V_201 ) )
return F_310 ( V_201 ) ;
}
V_15 = F_419 ( V_190 , V_201 -> V_94 , true ) ;
if ( V_15 )
goto V_596;
V_15 = F_417 ( V_190 , V_201 -> V_94 , true ) ;
if ( V_15 )
goto V_597;
F_311 ( V_190 , V_201 ) ;
V_201 -> V_42 ++ ;
F_45 ( V_190 -> V_51 , L_49 , V_201 -> V_94 ) ;
return 0 ;
V_597:
F_419 ( V_190 , V_201 -> V_94 , false ) ;
V_596:
if ( ! V_201 -> V_42 )
F_415 ( V_190 -> V_12 , V_201 ) ;
return V_15 ;
}
static void V_595 ( struct V_33 * V_190 )
{
struct V_200 * V_201 = F_147 ( V_190 ) ;
F_45 ( V_190 -> V_51 , L_50 , V_201 -> V_94 ) ;
F_417 ( V_190 , V_201 -> V_94 , false ) ;
F_419 ( V_190 , V_201 -> V_94 , false ) ;
F_358 ( V_190 , V_201 -> V_94 ) ;
F_311 ( V_190 , NULL ) ;
if ( -- V_201 -> V_42 == 0 )
F_415 ( V_190 -> V_12 , V_201 ) ;
}
static int F_420 ( struct V_33 * V_190 ,
struct V_117 * V_531 )
{
struct V_200 * V_201 = F_147 ( V_190 ) ;
T_2 V_95 = F_299 ( V_190 ) ;
struct V_117 * V_51 = V_190 -> V_51 ;
int V_15 ;
if ( V_201 && ! F_29 ( ! V_201 -> V_202 ) )
V_201 -> V_202 ( V_190 ) ;
V_15 = F_418 ( V_190 , V_531 ) ;
if ( V_15 ) {
F_36 ( V_51 , L_59 ) ;
return V_15 ;
}
V_15 = F_67 ( V_190 , V_95 , true ) ;
if ( V_15 ) {
F_36 ( V_51 , L_60 ) ;
goto V_598;
}
V_190 -> V_551 = 1 ;
V_190 -> V_552 = 1 ;
V_190 -> V_553 = 1 ;
V_190 -> V_554 = 1 ;
return 0 ;
V_598:
V_595 ( V_190 ) ;
return V_15 ;
}
static void F_421 ( struct V_33 * V_190 )
{
T_2 V_95 = F_299 ( V_190 ) ;
F_67 ( V_190 , V_95 , false ) ;
V_595 ( V_190 ) ;
V_190 -> V_551 = 0 ;
V_190 -> V_552 = 0 ;
V_190 -> V_553 = 0 ;
V_190 -> V_554 = 0 ;
}
static bool
F_422 ( const struct V_33 * V_33 ,
const struct V_117 * V_531 )
{
struct V_33 * V_190 ;
F_31 (mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
struct V_117 * V_51 = F_423 ( V_190 ) ;
if ( V_51 && V_51 == V_531 )
return false ;
}
return true ;
}
static int F_424 ( struct V_117 * V_51 ,
unsigned long V_497 , void * V_536 ,
T_2 V_95 )
{
struct V_33 * V_33 = F_81 ( V_51 ) ;
struct V_577 * V_575 = V_536 ;
struct V_33 * V_190 ;
struct V_117 * V_578 ;
int V_15 = 0 ;
V_190 = F_144 ( V_33 , V_95 ) ;
switch ( V_497 ) {
case V_579 :
V_578 = V_575 -> V_578 ;
if ( ! F_339 ( V_578 ) )
return - V_82 ;
if ( ! V_575 -> V_580 )
break;
if ( ! F_422 ( V_33 ,
V_578 ) )
return - V_82 ;
break;
case V_582 :
V_578 = V_575 -> V_578 ;
if ( V_575 -> V_580 ) {
if ( F_29 ( ! V_190 ) )
return - V_82 ;
V_15 = F_420 ( V_190 ,
V_578 ) ;
} else {
if ( ! V_190 )
return 0 ;
F_421 ( V_190 ) ;
}
}
return V_15 ;
}
static int F_425 ( struct V_117 * V_519 ,
unsigned long V_497 , void * V_536 ,
T_2 V_95 )
{
struct V_117 * V_51 ;
struct V_493 * V_494 ;
int V_586 ;
F_317 (lag_dev, dev, iter) {
if ( F_154 ( V_51 ) ) {
V_586 = F_424 ( V_51 , V_497 , V_536 ,
V_95 ) ;
if ( V_586 )
return V_586 ;
}
}
return 0 ;
}
static int F_426 ( struct V_117 * V_532 ,
unsigned long V_497 , void * V_536 )
{
struct V_117 * V_533 = F_337 ( V_532 ) ;
T_2 V_95 = F_321 ( V_532 ) ;
if ( F_154 ( V_533 ) )
return F_424 ( V_533 , V_497 , V_536 ,
V_95 ) ;
else if ( F_338 ( V_533 ) )
return F_425 ( V_533 , V_497 , V_536 ,
V_95 ) ;
return 0 ;
}
static int F_427 ( struct V_534 * V_535 ,
unsigned long V_497 , void * V_536 )
{
struct V_117 * V_51 = F_428 ( V_536 ) ;
int V_15 = 0 ;
if ( V_497 == V_599 || V_497 == V_600 )
V_15 = F_347 ( V_51 ) ;
else if ( F_154 ( V_51 ) )
V_15 = F_402 ( V_51 , V_497 , V_536 ) ;
else if ( F_338 ( V_51 ) )
V_15 = F_403 ( V_51 , V_497 , V_536 ) ;
else if ( F_339 ( V_51 ) )
V_15 = F_407 ( V_51 , V_497 , V_536 ) ;
else if ( F_320 ( V_51 ) )
V_15 = F_426 ( V_51 , V_497 , V_536 ) ;
return F_341 ( V_15 ) ;
}
static int T_9 F_429 ( void )
{
int V_15 ;
F_430 ( & V_601 ) ;
F_431 ( & V_602 ) ;
F_432 ( & V_603 ) ;
V_15 = F_433 ( & V_604 ) ;
if ( V_15 )
goto V_605;
return 0 ;
V_605:
F_434 ( & V_603 ) ;
F_435 ( & V_602 ) ;
F_436 ( & V_601 ) ;
return V_15 ;
}
static void T_10 F_437 ( void )
{
F_438 ( & V_604 ) ;
F_434 ( & V_603 ) ;
F_435 ( & V_602 ) ;
F_436 ( & V_601 ) ;
}
