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
V_35 -> V_42 = 0 ;
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
struct V_28 * F_26 ( struct V_33 * V_34 )
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
struct V_28 * F_27 ( struct V_33 * V_34 )
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
if ( -- V_35 -> V_42 == 0 )
F_25 ( V_12 , V_35 ) ;
return 0 ;
}
static bool F_29 ( struct V_33 * V_34 )
{
struct V_12 * V_12 = V_34 -> V_12 ;
struct V_44 * V_45 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_12 -> V_24 . V_25 ; V_21 ++ ) {
struct V_28 * V_32 = & V_12 -> V_24 . V_27 [ V_21 ] ;
F_30 (p, &curr->bound_ports_list, list)
if ( V_45 -> V_10 == V_34 -> V_10 &&
V_45 -> type == V_46 )
return true ;
}
return false ;
}
static int F_31 ( int V_47 )
{
return F_32 ( V_47 * 5 / 2 ) + 1 ;
}
static int F_33 ( struct V_33 * V_34 , T_2 V_47 )
{
struct V_12 * V_12 = V_34 -> V_12 ;
char V_48 [ V_49 ] ;
int V_15 ;
if ( F_29 ( V_34 ) ) {
F_34 ( V_48 , V_34 -> V_10 ,
F_31 ( V_47 ) ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_50 ) , V_48 ) ;
if ( V_15 ) {
F_35 ( V_34 -> V_51 , L_1 ) ;
return V_15 ;
}
}
return 0 ;
}
static struct V_44 *
F_36 ( struct V_33 * V_34 ,
struct V_28 * V_35 )
{
struct V_44 * V_45 ;
F_30 (p, &span_entry->bound_ports_list, list)
if ( V_34 -> V_10 == V_45 -> V_10 )
return V_45 ;
return NULL ;
}
static int
F_37 ( struct V_33 * V_34 ,
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
F_34 ( V_48 , V_34 -> V_10 ,
F_31 ( V_34 -> V_51 -> V_47 ) ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_50 ) , V_48 ) ;
if ( V_15 ) {
F_35 ( V_34 -> V_51 , L_2 ) ;
return V_15 ;
}
}
F_38 ( V_54 , V_34 -> V_10 , type , true , V_43 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_56 ) , V_54 ) ;
if ( V_15 )
goto V_57;
V_53 = F_39 ( sizeof( * V_53 ) , V_29 ) ;
if ( ! V_53 ) {
V_15 = - V_30 ;
goto V_58;
}
V_53 -> V_10 = V_34 -> V_10 ;
V_53 -> type = type ;
F_40 ( & V_53 -> V_59 , & V_35 -> V_31 ) ;
return 0 ;
V_57:
V_58:
if ( type == V_46 ) {
F_34 ( V_48 , V_34 -> V_10 , 0 ) ;
F_24 ( V_12 -> V_16 , F_12 ( V_50 ) , V_48 ) ;
}
return V_15 ;
}
static void
F_41 ( struct V_33 * V_34 ,
struct V_28 * V_35 ,
enum V_52 type )
{
struct V_44 * V_53 ;
struct V_12 * V_12 = V_34 -> V_12 ;
char V_54 [ V_55 ] ;
char V_48 [ V_49 ] ;
int V_43 = V_35 -> V_41 ;
V_53 = F_36 ( V_34 , V_35 ) ;
if ( ! V_53 )
return;
F_38 ( V_54 , V_34 -> V_10 , type , false , V_43 ) ;
F_24 ( V_12 -> V_16 , F_12 ( V_56 ) , V_54 ) ;
if ( type == V_46 ) {
F_34 ( V_48 , V_34 -> V_10 , 0 ) ;
F_24 ( V_12 -> V_16 , F_12 ( V_50 ) , V_48 ) ;
}
F_28 ( V_12 , V_35 ) ;
F_42 ( & V_53 -> V_59 ) ;
F_21 ( V_53 ) ;
}
static int F_43 ( struct V_33 * V_60 ,
struct V_33 * V_61 ,
enum V_52 type )
{
struct V_12 * V_12 = V_60 -> V_12 ;
struct V_28 * V_35 ;
int V_15 ;
V_35 = F_27 ( V_61 ) ;
if ( ! V_35 )
return - V_62 ;
F_44 ( V_60 -> V_51 , L_3 ,
V_35 -> V_41 ) ;
V_15 = F_37 ( V_60 , V_35 , type ) ;
if ( V_15 )
goto V_63;
return 0 ;
V_63:
F_28 ( V_12 , V_35 ) ;
return V_15 ;
}
static void F_45 ( struct V_33 * V_60 ,
struct V_33 * V_61 ,
enum V_52 type )
{
struct V_28 * V_35 ;
V_35 = F_26 ( V_61 ) ;
if ( ! V_35 ) {
F_35 ( V_60 -> V_51 , L_4 ) ;
return;
}
F_44 ( V_60 -> V_51 , L_5 ,
V_35 -> V_41 ) ;
F_41 ( V_60 , V_35 , type ) ;
}
static int F_46 ( struct V_33 * V_33 ,
bool V_64 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_65 [ V_66 ] ;
F_47 ( V_65 , V_33 -> V_10 ,
V_64 ? V_67 :
V_68 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_69 ) , V_65 ) ;
}
static int F_48 ( struct V_33 * V_33 ,
unsigned char * V_70 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_71 [ V_72 ] ;
F_49 ( V_71 , true , V_33 -> V_10 ) ;
F_50 ( V_71 , V_70 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_73 ) , V_71 ) ;
}
static int F_51 ( struct V_33 * V_33 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
unsigned char * V_70 = V_33 -> V_51 -> V_74 ;
F_52 ( V_70 , V_12 -> V_18 ) ;
V_70 [ V_75 - 1 ] += V_33 -> V_10 ;
return F_48 ( V_33 , V_70 ) ;
}
static int F_53 ( struct V_33 * V_33 , T_2 V_47 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_76 [ V_77 ] ;
int V_78 ;
int V_15 ;
V_47 += V_6 + V_79 ;
F_54 ( V_76 , V_33 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_80 ) , V_76 ) ;
if ( V_15 )
return V_15 ;
V_78 = F_55 ( V_76 ) ;
if ( V_47 > V_78 )
return - V_81 ;
F_54 ( V_76 , V_33 -> V_10 , V_47 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_80 ) , V_76 ) ;
}
static int F_56 ( struct V_12 * V_12 , T_1 V_10 ,
T_1 V_82 )
{
char V_83 [ V_84 ] ;
F_57 ( V_83 , V_82 , V_10 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_85 ) , V_83 ) ;
}
static int F_58 ( struct V_33 * V_33 , T_1 V_82 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
return F_56 ( V_12 , V_33 -> V_10 ,
V_82 ) ;
}
static int F_59 ( struct V_33 * V_33 ,
bool V_86 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_87 [ V_88 ] ;
F_60 ( V_87 , V_33 -> V_10 , V_86 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_89 ) , V_87 ) ;
}
int F_61 ( struct V_33 * V_33 ,
enum V_90 V_91 , bool V_92 , T_2 V_93 ,
T_2 V_94 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_95 [ V_96 ] ;
F_62 ( V_95 , V_33 -> V_10 , V_91 , V_92 ,
V_93 , V_94 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_97 ) , V_95 ) ;
}
static int F_63 ( struct V_33 * V_33 ,
T_2 V_94 , bool V_98 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char * V_99 ;
int V_15 ;
V_99 = F_64 ( V_100 , V_29 ) ;
if ( ! V_99 )
return - V_30 ;
F_65 ( V_99 , V_33 -> V_10 , V_94 , V_94 ,
V_98 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_101 ) , V_99 ) ;
F_21 ( V_99 ) ;
return V_15 ;
}
static int
F_66 ( struct V_33 * V_33 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_102 [ V_103 ] ;
F_67 ( V_102 , V_33 -> V_10 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_104 ) , V_102 ) ;
}
static int F_68 ( struct V_12 * V_12 ,
T_1 V_10 , T_1 * V_105 ,
T_1 * V_106 , T_1 * V_107 )
{
char V_108 [ V_109 ] ;
int V_15 ;
F_69 ( V_108 , V_10 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_110 ) , V_108 ) ;
if ( V_15 )
return V_15 ;
* V_105 = F_70 ( V_108 , 0 ) ;
* V_106 = F_71 ( V_108 ) ;
* V_107 = F_72 ( V_108 , 0 ) ;
return 0 ;
}
static int F_73 ( struct V_12 * V_12 , T_1 V_10 ,
T_1 V_111 , T_1 V_112 , T_1 V_113 )
{
char V_108 [ V_109 ] ;
int V_21 ;
F_69 ( V_108 , V_10 ) ;
F_74 ( V_108 , V_112 ) ;
for ( V_21 = 0 ; V_21 < V_112 ; V_21 ++ ) {
F_75 ( V_108 , V_21 , V_111 ) ;
F_76 ( V_108 , V_21 , V_113 + V_21 ) ;
}
return F_24 ( V_12 -> V_16 , F_12 ( V_110 ) , V_108 ) ;
}
static int F_77 ( struct V_12 * V_12 , T_1 V_10 )
{
char V_108 [ V_109 ] ;
F_69 ( V_108 , V_10 ) ;
F_74 ( V_108 , 0 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_110 ) , V_108 ) ;
}
static int F_78 ( struct V_114 * V_51 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
int V_15 ;
V_15 = F_46 ( V_33 , true ) ;
if ( V_15 )
return V_15 ;
F_80 ( V_51 ) ;
return 0 ;
}
static int F_81 ( struct V_114 * V_51 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
F_82 ( V_51 ) ;
return F_46 ( V_33 , false ) ;
}
static T_3 F_83 ( struct V_1 * V_2 ,
struct V_114 * V_51 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
struct V_115 * V_116 ;
const struct V_3 V_4 = {
. V_10 = V_33 -> V_10 ,
. V_117 = false ,
} ;
T_4 V_118 ;
int V_15 ;
if ( F_84 ( V_12 -> V_16 , & V_4 ) )
return V_119 ;
if ( F_85 ( F_86 ( V_2 ) < V_6 ) ) {
struct V_1 * V_120 = V_2 ;
V_2 = F_87 ( V_2 , V_6 ) ;
if ( ! V_2 ) {
F_88 ( V_33 -> V_116 -> V_121 ) ;
F_89 ( V_120 ) ;
return V_122 ;
}
}
if ( F_90 ( V_2 ) ) {
F_88 ( V_33 -> V_116 -> V_121 ) ;
return V_122 ;
}
F_1 ( V_2 , & V_4 ) ;
V_118 = V_2 -> V_118 - V_6 ;
V_15 = F_91 ( V_12 -> V_16 , V_2 , & V_4 ) ;
if ( ! V_15 ) {
V_116 = F_92 ( V_33 -> V_116 ) ;
F_93 ( & V_116 -> V_123 ) ;
V_116 -> V_124 ++ ;
V_116 -> V_125 += V_118 ;
F_94 ( & V_116 -> V_123 ) ;
} else {
F_88 ( V_33 -> V_116 -> V_121 ) ;
F_89 ( V_2 ) ;
}
return V_122 ;
}
static void F_95 ( struct V_114 * V_51 )
{
}
static int F_96 ( struct V_114 * V_51 , void * V_45 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
struct V_126 * V_70 = V_45 ;
int V_15 ;
if ( ! F_97 ( V_70 -> V_127 ) )
return - V_128 ;
V_15 = F_48 ( V_33 , V_70 -> V_127 ) ;
if ( V_15 )
return V_15 ;
memcpy ( V_51 -> V_74 , V_70 -> V_127 , V_51 -> V_129 ) ;
return 0 ;
}
static void F_98 ( char * V_130 , int V_131 , int V_47 ,
bool V_132 , bool V_133 , T_2 V_134 )
{
T_2 V_135 = 2 * F_32 ( V_47 ) ;
V_134 = V_133 ? F_99 ( V_47 , V_134 ) :
V_136 ;
if ( V_132 || V_133 )
F_100 ( V_130 , V_131 ,
V_135 + V_134 , V_135 ) ;
else
F_101 ( V_130 , V_131 , V_135 ) ;
}
int F_102 ( struct V_33 * V_33 , int V_47 ,
T_1 * V_137 , bool V_132 ,
struct V_138 * V_139 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
T_1 V_133 = ! ! V_139 ? V_139 -> V_133 : 0 ;
T_2 V_134 = ! ! V_139 ? V_139 -> V_134 : 0 ;
char V_130 [ V_140 ] ;
int V_21 , V_141 , V_15 ;
F_103 ( V_130 , V_33 -> V_10 , 0 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_142 ) , V_130 ) ;
if ( V_15 )
return V_15 ;
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ ) {
bool V_144 = false ;
bool V_145 = false ;
for ( V_141 = 0 ; V_141 < V_143 ; V_141 ++ ) {
if ( V_137 [ V_141 ] == V_21 ) {
V_145 = V_133 & F_104 ( V_141 ) ;
V_144 = true ;
break;
}
}
if ( ! V_144 )
continue;
F_98 ( V_130 , V_21 , V_47 , V_132 , V_145 , V_134 ) ;
}
return F_24 ( V_12 -> V_16 , F_12 ( V_142 ) , V_130 ) ;
}
static int F_105 ( struct V_33 * V_33 ,
int V_47 , bool V_132 )
{
T_1 V_146 [ V_143 ] = { 0 } ;
bool V_147 = ! ! V_33 -> V_148 . V_149 ;
struct V_138 * V_139 ;
T_1 * V_137 ;
V_137 = V_147 ? V_33 -> V_148 . V_149 -> V_137 : V_146 ;
V_139 = V_147 ? V_33 -> V_148 . V_145 : NULL ;
return F_102 ( V_33 , V_47 , V_137 ,
V_132 , V_139 ) ;
}
static int F_106 ( struct V_114 * V_51 , int V_47 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
bool V_132 = F_107 ( V_33 ) ;
int V_15 ;
V_15 = F_105 ( V_33 , V_47 , V_132 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_33 ( V_33 , V_47 ) ;
if ( V_15 )
goto V_150;
V_15 = F_53 ( V_33 , V_47 ) ;
if ( V_15 )
goto V_151;
V_51 -> V_47 = V_47 ;
return 0 ;
V_151:
F_33 ( V_33 , V_51 -> V_47 ) ;
V_150:
F_105 ( V_33 , V_51 -> V_47 , V_132 ) ;
return V_15 ;
}
static struct V_152 *
F_108 ( struct V_114 * V_51 ,
struct V_152 * V_153 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
struct V_115 * V_45 ;
T_4 V_154 , V_155 , V_124 , V_125 ;
T_5 V_121 = 0 ;
unsigned int V_156 ;
int V_21 ;
F_109 (i) {
V_45 = F_110 ( V_33 -> V_116 , V_21 ) ;
do {
V_156 = F_111 ( & V_45 -> V_123 ) ;
V_154 = V_45 -> V_154 ;
V_155 = V_45 -> V_155 ;
V_124 = V_45 -> V_124 ;
V_125 = V_45 -> V_125 ;
} while ( F_112 ( & V_45 -> V_123 , V_156 ) );
V_153 -> V_154 += V_154 ;
V_153 -> V_155 += V_155 ;
V_153 -> V_124 += V_124 ;
V_153 -> V_125 += V_125 ;
V_121 += V_45 -> V_121 ;
}
V_153 -> V_121 = V_121 ;
return V_153 ;
}
int F_113 ( struct V_33 * V_33 , T_2 V_157 ,
T_2 V_158 , bool V_159 , bool V_160 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char * V_161 ;
int V_15 ;
V_161 = F_64 ( V_162 , V_29 ) ;
if ( ! V_161 )
return - V_30 ;
F_114 ( V_161 , V_33 -> V_10 , V_157 ,
V_158 , V_159 , V_160 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_163 ) , V_161 ) ;
F_21 ( V_161 ) ;
return V_15 ;
}
static int F_115 ( struct V_33 * V_33 )
{
enum V_90 V_91 = V_164 ;
T_2 V_94 , V_165 ;
int V_15 ;
F_116 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_61 ( V_33 , V_91 , true , V_94 ,
V_94 ) ;
if ( V_15 ) {
V_165 = V_94 ;
goto V_166;
}
}
V_15 = F_59 ( V_33 , true ) ;
if ( V_15 ) {
V_165 = V_167 ;
goto V_166;
}
return 0 ;
V_166:
F_116 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_61 ( V_33 , V_91 , false , V_94 ,
V_94 ) ;
return V_15 ;
}
static int F_117 ( struct V_33 * V_33 )
{
enum V_90 V_91 = V_164 ;
T_2 V_94 ;
int V_15 ;
V_15 = F_59 ( V_33 , false ) ;
if ( V_15 )
return V_15 ;
F_116 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_61 ( V_33 , V_91 , false ,
V_94 , V_94 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static struct V_33 *
F_118 ( struct V_33 * V_33 , T_2 V_94 )
{
struct V_33 * V_168 ;
V_168 = F_39 ( sizeof( * V_168 ) , V_29 ) ;
if ( ! V_168 )
return NULL ;
V_168 -> V_51 = V_33 -> V_51 ;
V_168 -> V_12 = V_33 -> V_12 ;
V_168 -> V_10 = V_33 -> V_10 ;
V_168 -> V_169 = V_170 ;
V_168 -> V_171 = V_33 -> V_171 ;
V_168 -> V_172 = V_33 -> V_172 ;
V_168 -> V_173 . V_94 = V_94 ;
F_119 ( & V_168 -> V_173 . V_59 , & V_33 -> V_174 ) ;
return V_168 ;
}
static void F_120 ( struct V_33 * V_168 )
{
F_42 ( & V_168 -> V_173 . V_59 ) ;
F_21 ( V_168 ) ;
}
static int F_121 ( struct V_114 * V_51 ,
T_6 T_7 V_175 , T_2 V_94 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
struct V_33 * V_168 ;
bool V_160 = V_94 == 1 ;
int V_15 ;
if ( ! V_94 )
return 0 ;
if ( F_122 ( V_33 , V_94 ) )
return 0 ;
V_168 = F_118 ( V_33 , V_94 ) ;
if ( ! V_168 )
return - V_30 ;
if ( F_123 ( & V_33 -> V_174 ) ) {
V_15 = F_115 ( V_33 ) ;
if ( V_15 )
goto V_176;
}
V_15 = F_63 ( V_168 , V_94 , false ) ;
if ( V_15 )
goto V_177;
V_15 = F_113 ( V_168 , V_94 , V_94 , true , V_160 ) ;
if ( V_15 )
goto V_178;
return 0 ;
V_178:
F_63 ( V_168 , V_94 , true ) ;
V_177:
if ( F_123 ( & V_33 -> V_174 ) )
F_117 ( V_33 ) ;
V_176:
F_120 ( V_168 ) ;
return V_15 ;
}
static int F_124 ( struct V_114 * V_51 ,
T_6 T_7 V_175 , T_2 V_94 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
struct V_33 * V_168 ;
struct V_179 * V_180 ;
if ( ! V_94 )
return 0 ;
V_168 = F_122 ( V_33 , V_94 ) ;
if ( F_125 ( ! V_168 ) )
return 0 ;
F_113 ( V_168 , V_94 , V_94 , false , false ) ;
F_63 ( V_168 , V_94 , true ) ;
V_180 = F_126 ( V_168 ) ;
if ( V_180 && ! F_125 ( ! V_180 -> V_181 ) )
V_180 -> V_181 ( V_168 ) ;
if ( F_123 ( & V_33 -> V_174 ) )
F_117 ( V_33 ) ;
F_120 ( V_168 ) ;
return 0 ;
}
static int F_127 ( struct V_114 * V_51 , char * V_182 ,
T_8 V_118 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
T_1 V_111 = V_33 -> V_183 . V_111 ;
T_1 V_112 = V_33 -> V_183 . V_112 ;
T_1 V_113 = V_33 -> V_183 . V_113 ;
int V_15 ;
if ( ! V_33 -> V_184 )
V_15 = snprintf ( V_182 , V_118 , L_6 , V_111 + 1 ) ;
else
V_15 = snprintf ( V_182 , V_118 , L_7 , V_111 + 1 ,
V_113 / V_112 ) ;
if ( V_15 >= V_118 )
return - V_81 ;
return 0 ;
}
static struct V_185 *
F_128 ( struct V_33 * V_34 ,
unsigned long V_186 ) {
struct V_185 * V_187 ;
F_30 (mall_tc_entry, &port->mall_tc_list, list)
if ( V_187 -> V_186 == V_186 )
return V_187 ;
return NULL ;
}
static int
F_129 ( struct V_33 * V_33 ,
struct V_188 * V_189 ,
const struct V_190 * V_191 ,
bool V_192 )
{
struct V_185 * V_187 ;
struct V_193 * V_193 = F_130 ( V_33 -> V_51 ) ;
enum V_52 V_194 ;
struct V_33 * V_195 ;
struct V_114 * V_196 ;
int V_197 ;
int V_15 ;
V_197 = F_131 ( V_191 ) ;
V_196 = F_132 ( V_193 , V_197 ) ;
if ( ! V_196 ) {
F_35 ( V_33 -> V_51 , L_8 ) ;
return - V_81 ;
}
if ( ! F_133 ( V_196 ) ) {
F_35 ( V_33 -> V_51 , L_9 ) ;
return - V_198 ;
}
V_195 = F_79 ( V_196 ) ;
V_187 = F_39 ( sizeof( * V_187 ) , V_29 ) ;
if ( ! V_187 )
return - V_30 ;
V_187 -> V_186 = V_189 -> V_186 ;
V_187 -> type = V_199 ;
V_187 -> V_200 . V_201 = V_195 -> V_10 ;
V_187 -> V_200 . V_192 = V_192 ;
F_40 ( & V_187 -> V_59 , & V_33 -> V_202 ) ;
V_194 = V_192 ? V_203 : V_46 ;
V_15 = F_43 ( V_33 , V_195 , V_194 ) ;
if ( V_15 )
goto V_204;
return 0 ;
V_204:
F_42 ( & V_187 -> V_59 ) ;
F_21 ( V_187 ) ;
return V_15 ;
}
static int F_134 ( struct V_33 * V_33 ,
T_6 V_205 ,
struct V_188 * V_189 ,
bool V_192 )
{
const struct V_190 * V_191 ;
F_135 ( V_206 ) ;
int V_15 ;
if ( ! F_136 ( V_189 -> V_207 ) ) {
F_35 ( V_33 -> V_51 , L_10 ) ;
return - V_198 ;
}
F_137 ( V_189 -> V_207 , & V_206 ) ;
F_30 (a, &actions, list) {
if ( ! F_138 ( V_191 ) || V_205 != F_139 ( V_208 ) )
return - V_198 ;
V_15 = F_129 ( V_33 , V_189 ,
V_191 , V_192 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static void F_140 ( struct V_33 * V_33 ,
struct V_188 * V_189 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
struct V_185 * V_187 ;
enum V_52 V_194 ;
struct V_33 * V_195 ;
V_187 = F_128 ( V_33 ,
V_189 -> V_186 ) ;
if ( ! V_187 ) {
F_44 ( V_33 -> V_51 , L_11 ) ;
return;
}
switch ( V_187 -> type ) {
case V_199 :
V_195 = V_12 -> V_209 [ V_187 -> V_200 . V_201 ] ;
V_194 = V_187 -> V_200 . V_192 ?
V_203 : V_46 ;
F_45 ( V_33 , V_195 , V_194 ) ;
break;
default:
F_125 ( 1 ) ;
}
F_42 ( & V_187 -> V_59 ) ;
F_21 ( V_187 ) ;
}
static int F_141 ( struct V_114 * V_51 , T_5 V_210 ,
T_6 V_175 , struct V_211 * V_212 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
bool V_192 = F_142 ( V_210 ) == F_142 ( V_213 ) ;
if ( V_212 -> type == V_214 ) {
switch ( V_212 -> V_215 -> V_216 ) {
case V_217 :
return F_134 ( V_33 ,
V_175 ,
V_212 -> V_215 ,
V_192 ) ;
case V_218 :
F_140 ( V_33 ,
V_212 -> V_215 ) ;
return 0 ;
default:
return - V_81 ;
}
}
return - V_198 ;
}
static void F_143 ( struct V_114 * V_51 ,
struct V_219 * V_220 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
F_144 ( V_220 -> V_221 , V_222 , sizeof( V_220 -> V_221 ) ) ;
F_144 ( V_220 -> V_223 , V_224 ,
sizeof( V_220 -> V_223 ) ) ;
snprintf ( V_220 -> V_225 , sizeof( V_220 -> V_225 ) ,
L_12 ,
V_12 -> V_226 -> V_227 . V_228 ,
V_12 -> V_226 -> V_227 . V_229 ,
V_12 -> V_226 -> V_227 . V_230 ) ;
F_144 ( V_220 -> V_226 , V_12 -> V_226 -> V_231 ,
sizeof( V_220 -> V_226 ) ) ;
}
static void F_145 ( struct V_114 * V_51 ,
struct V_232 * V_233 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
V_233 -> V_234 = V_33 -> V_235 . V_234 ;
V_233 -> V_236 = V_33 -> V_235 . V_236 ;
}
static int F_146 ( struct V_33 * V_33 ,
struct V_232 * V_233 )
{
char V_237 [ V_238 ] ;
F_147 ( V_237 , V_33 -> V_10 ) ;
F_148 ( V_237 , V_233 -> V_234 ) ;
F_149 ( V_237 , V_233 -> V_236 ) ;
return F_24 ( V_33 -> V_12 -> V_16 , F_12 ( V_239 ) ,
V_237 ) ;
}
static int F_150 ( struct V_114 * V_51 ,
struct V_232 * V_233 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
bool V_132 = V_233 -> V_236 || V_233 -> V_234 ;
int V_15 ;
if ( V_33 -> V_148 . V_145 && V_33 -> V_148 . V_145 -> V_133 ) {
F_35 ( V_51 , L_13 ) ;
return - V_81 ;
}
if ( V_233 -> V_240 ) {
F_35 ( V_51 , L_14 ) ;
return - V_81 ;
}
V_15 = F_105 ( V_33 , V_51 -> V_47 , V_132 ) ;
if ( V_15 ) {
F_35 ( V_51 , L_15 ) ;
return V_15 ;
}
V_15 = F_146 ( V_33 , V_233 ) ;
if ( V_15 ) {
F_35 ( V_51 , L_16 ) ;
goto V_241;
}
V_33 -> V_235 . V_234 = V_233 -> V_234 ;
V_33 -> V_235 . V_236 = V_233 -> V_236 ;
return 0 ;
V_241:
V_132 = F_107 ( V_33 ) ;
F_105 ( V_33 , V_51 -> V_47 , V_132 ) ;
return V_15 ;
}
static T_4 F_151 ( char * V_242 )
{
T_4 V_243 = F_152 ( V_242 ) ;
return F_153 ( V_243 ) ;
}
static void F_154 ( T_1 * * V_45 , int V_244 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_245 ; V_21 ++ ) {
snprintf ( * V_45 , V_246 , L_17 ,
V_247 [ V_21 ] . V_248 , V_244 ) ;
* V_45 += V_246 ;
}
}
static void F_155 ( T_1 * * V_45 , int V_212 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_249 ; V_21 ++ ) {
snprintf ( * V_45 , V_246 , L_17 ,
V_250 [ V_21 ] . V_248 , V_212 ) ;
* V_45 += V_246 ;
}
}
static void F_156 ( struct V_114 * V_51 ,
T_5 V_251 , T_1 * V_252 )
{
T_1 * V_45 = V_252 ;
int V_21 ;
switch ( V_251 ) {
case V_253 :
for ( V_21 = 0 ; V_21 < V_254 ; V_21 ++ ) {
memcpy ( V_45 , V_255 [ V_21 ] . V_248 ,
V_246 ) ;
V_45 += V_246 ;
}
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ )
F_154 ( & V_45 , V_21 ) ;
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ )
F_155 ( & V_45 , V_21 ) ;
break;
}
}
static int F_157 ( struct V_114 * V_51 ,
enum V_256 V_257 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
char V_258 [ V_259 ] ;
bool V_260 ;
switch ( V_257 ) {
case V_261 :
V_260 = true ;
break;
case V_262 :
V_260 = false ;
break;
default:
return - V_263 ;
}
F_158 ( V_258 , V_33 -> V_10 , V_260 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_264 ) , V_258 ) ;
}
static int
F_159 ( struct V_255 * * V_265 ,
int * V_266 , enum V_267 V_268 )
{
switch ( V_268 ) {
case V_269 :
* V_265 = V_255 ;
* V_266 = V_254 ;
break;
case V_270 :
* V_265 = V_247 ;
* V_266 = V_245 ;
break;
case V_271 :
* V_265 = V_250 ;
* V_266 = V_249 ;
break;
default:
F_125 ( 1 ) ;
return - V_198 ;
}
return 0 ;
}
static void F_160 ( struct V_114 * V_51 ,
enum V_267 V_268 , int V_244 ,
T_4 * V_252 , int V_272 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
struct V_255 * V_273 ;
char V_242 [ V_274 ] ;
int V_21 , V_118 ;
int V_15 ;
V_15 = F_159 ( & V_273 , & V_118 , V_268 ) ;
if ( V_15 )
return;
F_161 ( V_242 , V_33 -> V_10 , V_268 , V_244 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_275 ) , V_242 ) ;
for ( V_21 = 0 ; V_21 < V_118 ; V_21 ++ )
V_252 [ V_272 + V_21 ] = ! V_15 ? V_273 [ V_21 ] . F_162 ( V_242 ) : 0 ;
}
static void F_163 ( struct V_114 * V_51 ,
struct V_276 * V_153 , T_4 * V_252 )
{
int V_21 , V_272 = 0 ;
F_160 ( V_51 , V_269 , 0 ,
V_252 , V_272 ) ;
V_272 = V_254 ;
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ ) {
F_160 ( V_51 , V_270 , V_21 ,
V_252 , V_272 ) ;
V_272 += V_245 ;
}
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ ) {
F_160 ( V_51 , V_271 , V_21 ,
V_252 , V_272 ) ;
V_272 += V_249 ;
}
}
static int F_164 ( struct V_114 * V_51 , int V_277 )
{
switch ( V_277 ) {
case V_253 :
return V_278 ;
default:
return - V_263 ;
}
}
static T_5 F_165 ( T_5 V_279 )
{
if ( V_279 & ( V_280 |
V_281 |
V_282 |
V_283 |
V_284 |
V_285 ) )
return V_286 ;
if ( V_279 & ( V_287 |
V_288 |
V_289 |
V_290 |
V_291 ) )
return V_292 ;
return 0 ;
}
static T_5 F_166 ( T_5 V_279 )
{
T_5 V_293 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_294 ; V_21 ++ ) {
if ( V_279 & V_295 [ V_21 ] . V_296 )
V_293 |= V_295 [ V_21 ] . V_297 ;
}
return V_293 ;
}
static T_5 F_167 ( T_5 V_279 )
{
T_5 V_293 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_294 ; V_21 ++ ) {
if ( V_279 & V_295 [ V_21 ] . V_296 )
V_293 |= V_295 [ V_21 ] . V_298 ;
}
return V_293 ;
}
static void F_168 ( bool V_299 , T_5 V_279 ,
struct V_300 * V_301 )
{
T_5 V_302 = V_303 ;
T_1 V_304 = V_305 ;
int V_21 ;
if ( ! V_299 )
goto V_306;
for ( V_21 = 0 ; V_21 < V_294 ; V_21 ++ ) {
if ( V_279 & V_295 [ V_21 ] . V_296 ) {
V_302 = V_295 [ V_21 ] . V_302 ;
V_304 = V_307 ;
break;
}
}
V_306:
F_169 ( V_301 , V_302 ) ;
V_301 -> V_304 = V_304 ;
}
static T_1 F_170 ( T_5 V_279 )
{
if ( V_279 & ( V_281 |
V_283 |
V_284 |
V_285 ) )
return V_308 ;
if ( V_279 & ( V_280 |
V_282 |
V_309 ) )
return V_310 ;
if ( V_279 & ( V_287 |
V_288 |
V_289 |
V_290 ) )
return V_311 ;
return V_312 ;
}
static int F_171 ( struct V_114 * V_51 ,
struct V_300 * V_301 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
char V_313 [ V_314 ] ;
T_5 V_315 ;
T_5 V_316 ;
T_5 V_317 ;
int V_15 ;
F_172 ( V_313 , V_33 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_318 ) , V_313 ) ;
if ( V_15 ) {
F_35 ( V_51 , L_18 ) ;
return V_15 ;
}
F_173 ( V_313 , & V_315 ,
& V_316 , & V_317 ) ;
V_301 -> V_297 = F_165 ( V_315 ) |
F_166 ( V_315 ) |
V_319 | V_320 |
V_321 ;
V_301 -> V_322 = F_167 ( V_316 ) ;
F_168 ( F_174 ( V_51 ) ,
V_317 , V_301 ) ;
V_317 = V_317 ? V_317 : V_315 ;
V_301 -> V_34 = F_170 ( V_317 ) ;
V_301 -> V_323 = F_167 ( V_317 ) ;
V_301 -> V_324 = V_325 ;
return 0 ;
}
static T_5 F_175 ( T_5 V_322 )
{
T_5 V_326 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_294 ; V_21 ++ ) {
if ( V_322 & V_295 [ V_21 ] . V_298 )
V_326 |= V_295 [ V_21 ] . V_296 ;
}
return V_326 ;
}
static T_5 F_176 ( T_5 V_302 )
{
T_5 V_326 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_294 ; V_21 ++ ) {
if ( V_302 == V_295 [ V_21 ] . V_302 )
V_326 |= V_295 [ V_21 ] . V_296 ;
}
return V_326 ;
}
static T_5 F_177 ( T_5 V_327 )
{
T_5 V_326 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_294 ; V_21 ++ ) {
if ( V_295 [ V_21 ] . V_302 <= V_327 )
V_326 |= V_295 [ V_21 ] . V_296 ;
}
return V_326 ;
}
static int F_178 ( struct V_114 * V_51 ,
struct V_300 * V_301 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
struct V_12 * V_12 = V_33 -> V_12 ;
char V_313 [ V_314 ] ;
T_5 V_302 ;
T_5 V_328 ;
T_5 V_315 ;
T_5 V_316 ;
int V_15 ;
V_302 = F_179 ( V_301 ) ;
V_328 = V_301 -> V_240 == V_329 ?
F_175 ( V_301 -> V_322 ) :
F_176 ( V_302 ) ;
F_172 ( V_313 , V_33 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_318 ) , V_313 ) ;
if ( V_15 ) {
F_35 ( V_51 , L_18 ) ;
return V_15 ;
}
F_173 ( V_313 , & V_315 , & V_316 , NULL ) ;
V_328 = V_328 & V_315 ;
if ( ! V_328 ) {
F_35 ( V_51 , L_19 ) ;
return - V_81 ;
}
if ( V_328 == V_316 )
return 0 ;
F_172 ( V_313 , V_33 -> V_10 , V_328 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_318 ) , V_313 ) ;
if ( V_15 ) {
F_35 ( V_51 , L_20 ) ;
return V_15 ;
}
if ( ! F_180 ( V_51 ) )
return 0 ;
V_15 = F_46 ( V_33 , false ) ;
if ( V_15 ) {
F_35 ( V_51 , L_21 ) ;
return V_15 ;
}
V_15 = F_46 ( V_33 , true ) ;
if ( V_15 ) {
F_35 ( V_51 , L_21 ) ;
return V_15 ;
}
return 0 ;
}
static int
F_181 ( struct V_33 * V_33 , T_1 V_112 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
T_5 V_327 = V_330 * V_112 ;
char V_313 [ V_314 ] ;
T_5 V_316 ;
V_316 = F_177 ( V_327 ) ;
F_172 ( V_313 , V_33 -> V_10 ,
V_316 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_318 ) , V_313 ) ;
}
int F_182 ( struct V_33 * V_33 ,
enum V_331 V_332 , T_1 V_38 , T_1 V_333 ,
bool V_334 , T_1 V_335 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_336 [ V_337 ] ;
F_183 ( V_336 , V_33 -> V_10 , V_332 , V_38 ,
V_333 ) ;
F_184 ( V_336 , true ) ;
F_185 ( V_336 , V_334 ) ;
F_186 ( V_336 , V_335 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_338 ) , V_336 ) ;
}
int F_187 ( struct V_33 * V_33 ,
enum V_331 V_332 , T_1 V_38 ,
T_1 V_333 , T_5 V_339 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_336 [ V_337 ] ;
F_183 ( V_336 , V_33 -> V_10 , V_332 , V_38 ,
V_333 ) ;
F_188 ( V_336 , true ) ;
F_189 ( V_336 , V_339 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_338 ) , V_336 ) ;
}
int F_190 ( struct V_33 * V_33 ,
T_1 V_340 , T_1 V_341 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_342 [ V_343 ] ;
F_191 ( V_342 , V_33 -> V_10 , V_340 ,
V_341 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_344 ) , V_342 ) ;
}
static int F_192 ( struct V_33 * V_33 )
{
int V_15 , V_21 ;
V_15 = F_182 ( V_33 ,
V_345 , 0 , 0 , false ,
0 ) ;
if ( V_15 )
return V_15 ;
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ ) {
V_15 = F_182 ( V_33 ,
V_346 , V_21 ,
0 , false , 0 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ ) {
V_15 = F_182 ( V_33 ,
V_347 , V_21 , V_21 ,
false , 0 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = F_187 ( V_33 ,
V_348 , 0 , 0 ,
V_349 ) ;
if ( V_15 )
return V_15 ;
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ ) {
V_15 = F_187 ( V_33 ,
V_346 ,
V_21 , 0 ,
V_349 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ ) {
V_15 = F_187 ( V_33 ,
V_347 ,
V_21 , V_21 ,
V_349 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ ) {
V_15 = F_190 ( V_33 , V_21 , 0 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_193 ( struct V_33 * V_33 )
{
V_33 -> V_350 = 1 ;
return F_121 ( V_33 -> V_51 , 0 , 1 ) ;
}
static int F_194 ( struct V_33 * V_33 )
{
return F_124 ( V_33 -> V_51 , 0 , 1 ) ;
}
static int F_195 ( struct V_12 * V_12 , T_1 V_10 ,
bool V_184 , T_1 V_111 , T_1 V_112 , T_1 V_113 )
{
struct V_33 * V_33 ;
struct V_114 * V_51 ;
T_8 V_351 ;
int V_15 ;
V_51 = F_196 ( sizeof( struct V_33 ) ) ;
if ( ! V_51 )
return - V_30 ;
V_33 = F_79 ( V_51 ) ;
V_33 -> V_51 = V_51 ;
V_33 -> V_12 = V_12 ;
V_33 -> V_10 = V_10 ;
V_33 -> V_184 = V_184 ;
V_33 -> V_183 . V_111 = V_111 ;
V_33 -> V_183 . V_112 = V_112 ;
V_33 -> V_183 . V_113 = V_113 ;
V_351 = F_197 ( V_167 , V_352 ) ;
V_33 -> V_353 = F_39 ( V_351 , V_29 ) ;
if ( ! V_33 -> V_353 ) {
V_15 = - V_30 ;
goto V_354;
}
V_33 -> V_355 = F_39 ( V_351 , V_29 ) ;
if ( ! V_33 -> V_355 ) {
V_15 = - V_30 ;
goto V_356;
}
F_17 ( & V_33 -> V_174 ) ;
F_17 ( & V_33 -> V_202 ) ;
V_33 -> V_116 =
F_198 ( struct V_115 ) ;
if ( ! V_33 -> V_116 ) {
V_15 = - V_30 ;
goto V_357;
}
V_51 -> V_358 = & V_359 ;
V_51 -> V_360 = & V_361 ;
V_15 = F_58 ( V_33 , 0 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_22 ,
V_33 -> V_10 ) ;
goto V_362;
}
V_15 = F_51 ( V_33 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_23 ,
V_33 -> V_10 ) ;
goto V_363;
}
F_200 ( V_51 ) ;
V_51 -> V_364 |= V_365 | V_366 | V_367 |
V_368 | V_369 ;
V_51 -> V_370 |= V_369 ;
V_51 -> V_371 += V_6 ;
V_15 = F_66 ( V_33 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_24 ,
V_33 -> V_10 ) ;
goto V_372;
}
V_15 = F_181 ( V_33 , V_112 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_25 ,
V_33 -> V_10 ) ;
goto V_373;
}
V_15 = F_53 ( V_33 , V_374 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_26 ,
V_33 -> V_10 ) ;
goto V_151;
}
V_15 = F_46 ( V_33 , false ) ;
if ( V_15 )
goto V_375;
V_15 = F_201 ( V_33 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_27 ,
V_33 -> V_10 ) ;
goto V_376;
}
V_15 = F_192 ( V_33 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_28 ,
V_33 -> V_10 ) ;
goto V_377;
}
V_15 = F_202 ( V_33 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_29 ,
V_33 -> V_10 ) ;
goto V_378;
}
V_15 = F_193 ( V_33 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_30 ,
V_33 -> V_10 ) ;
goto V_379;
}
F_203 ( V_33 ) ;
V_12 -> V_209 [ V_10 ] = V_33 ;
V_15 = F_204 ( V_51 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_31 ,
V_33 -> V_10 ) ;
goto V_380;
}
V_15 = F_205 ( V_12 -> V_16 , & V_33 -> V_381 ,
V_33 -> V_10 , V_51 ,
V_33 -> V_184 , V_111 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_32 ,
V_33 -> V_10 ) ;
goto V_382;
}
return 0 ;
V_382:
F_206 ( V_51 ) ;
V_380:
V_12 -> V_209 [ V_10 ] = NULL ;
F_207 ( V_33 ) ;
F_194 ( V_33 ) ;
V_379:
F_208 ( V_33 ) ;
V_378:
V_377:
V_376:
V_375:
V_151:
V_373:
V_372:
V_363:
F_58 ( V_33 , V_383 ) ;
V_362:
F_209 ( V_33 -> V_116 ) ;
V_357:
F_21 ( V_33 -> V_355 ) ;
V_356:
F_21 ( V_33 -> V_353 ) ;
V_354:
F_210 ( V_51 ) ;
return V_15 ;
}
static void F_211 ( struct V_12 * V_12 , T_1 V_10 )
{
struct V_33 * V_33 = V_12 -> V_209 [ V_10 ] ;
if ( ! V_33 )
return;
F_212 ( & V_33 -> V_381 ) ;
F_206 ( V_33 -> V_51 ) ;
V_12 -> V_209 [ V_10 ] = NULL ;
F_207 ( V_33 ) ;
F_194 ( V_33 ) ;
F_208 ( V_33 ) ;
F_58 ( V_33 , V_383 ) ;
F_77 ( V_12 , V_33 -> V_10 ) ;
F_209 ( V_33 -> V_116 ) ;
F_21 ( V_33 -> V_355 ) ;
F_21 ( V_33 -> V_353 ) ;
F_19 ( ! F_20 ( & V_33 -> V_174 ) ) ;
F_210 ( V_33 -> V_51 ) ;
}
static void F_213 ( struct V_12 * V_12 )
{
int V_21 ;
for ( V_21 = 1 ; V_21 < V_384 ; V_21 ++ )
F_211 ( V_12 , V_21 ) ;
F_21 ( V_12 -> V_209 ) ;
}
static int F_214 ( struct V_12 * V_12 )
{
T_1 V_111 , V_112 , V_113 ;
T_8 V_385 ;
int V_21 ;
int V_15 ;
V_385 = sizeof( struct V_33 * ) * V_384 ;
V_12 -> V_209 = F_39 ( V_385 , V_29 ) ;
if ( ! V_12 -> V_209 )
return - V_30 ;
for ( V_21 = 1 ; V_21 < V_384 ; V_21 ++ ) {
V_15 = F_68 ( V_12 , V_21 , & V_111 ,
& V_112 , & V_113 ) ;
if ( V_15 )
goto V_386;
if ( ! V_112 )
continue;
V_12 -> V_387 [ V_21 ] = V_111 ;
V_15 = F_195 ( V_12 , V_21 , false , V_111 , V_112 ,
V_113 ) ;
if ( V_15 )
goto V_388;
}
return 0 ;
V_388:
V_386:
for ( V_21 -- ; V_21 >= 1 ; V_21 -- )
F_211 ( V_12 , V_21 ) ;
F_21 ( V_12 -> V_209 ) ;
return V_15 ;
}
static T_1 F_215 ( T_1 V_10 )
{
T_1 V_389 = ( V_10 - 1 ) % V_390 ;
return V_10 - V_389 ;
}
static int F_216 ( struct V_12 * V_12 , T_1 V_391 ,
T_1 V_111 , unsigned int V_392 )
{
T_1 V_112 = V_393 / V_392 ;
int V_15 , V_21 ;
for ( V_21 = 0 ; V_21 < V_392 ; V_21 ++ ) {
V_15 = F_73 ( V_12 , V_391 + V_21 , V_111 ,
V_112 , V_21 * V_112 ) ;
if ( V_15 )
goto V_394;
}
for ( V_21 = 0 ; V_21 < V_392 ; V_21 ++ ) {
V_15 = F_56 ( V_12 , V_391 + V_21 , 0 ) ;
if ( V_15 )
goto V_362;
}
for ( V_21 = 0 ; V_21 < V_392 ; V_21 ++ ) {
V_15 = F_195 ( V_12 , V_391 + V_21 , true ,
V_111 , V_112 , V_21 * V_112 ) ;
if ( V_15 )
goto V_388;
}
return 0 ;
V_388:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- )
F_211 ( V_12 , V_391 + V_21 ) ;
V_21 = V_392 ;
V_362:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- )
F_56 ( V_12 , V_391 + V_21 ,
V_383 ) ;
V_21 = V_392 ;
V_394:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- )
F_77 ( V_12 , V_391 + V_21 ) ;
return V_15 ;
}
static void F_217 ( struct V_12 * V_12 ,
T_1 V_391 , unsigned int V_392 )
{
T_1 V_10 , V_111 , V_112 = V_393 ;
int V_21 ;
V_392 = V_392 / 2 ;
for ( V_21 = 0 ; V_21 < V_392 ; V_21 ++ ) {
V_10 = V_391 + V_21 * 2 ;
V_111 = V_12 -> V_387 [ V_10 ] ;
F_73 ( V_12 , V_10 , V_111 , V_112 ,
0 ) ;
}
for ( V_21 = 0 ; V_21 < V_392 ; V_21 ++ )
F_56 ( V_12 , V_391 + V_21 * 2 , 0 ) ;
for ( V_21 = 0 ; V_21 < V_392 ; V_21 ++ ) {
V_10 = V_391 + V_21 * 2 ;
V_111 = V_12 -> V_387 [ V_10 ] ;
F_195 ( V_12 , V_10 , false , V_111 ,
V_112 , 0 ) ;
}
}
static int F_218 ( struct V_395 * V_395 , T_1 V_10 ,
unsigned int V_392 )
{
struct V_12 * V_12 = F_219 ( V_395 ) ;
struct V_33 * V_33 ;
T_1 V_111 , V_396 , V_391 ;
int V_21 ;
int V_15 ;
V_33 = V_12 -> V_209 [ V_10 ] ;
if ( ! V_33 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_33 ,
V_10 ) ;
return - V_81 ;
}
V_111 = V_33 -> V_183 . V_111 ;
V_396 = V_33 -> V_183 . V_112 ;
if ( V_392 != 2 && V_392 != 4 ) {
F_35 ( V_33 -> V_51 , L_34 ) ;
return - V_81 ;
}
if ( V_396 != V_393 ) {
F_35 ( V_33 -> V_51 , L_35 ) ;
return - V_81 ;
}
if ( V_392 == 2 ) {
V_391 = V_10 ;
if ( V_12 -> V_209 [ V_391 + 1 ] ) {
F_35 ( V_33 -> V_51 , L_36 ) ;
return - V_81 ;
}
} else {
V_391 = F_215 ( V_10 ) ;
if ( V_12 -> V_209 [ V_391 + 1 ] ||
V_12 -> V_209 [ V_391 + 3 ] ) {
F_35 ( V_33 -> V_51 , L_36 ) ;
return - V_81 ;
}
}
for ( V_21 = 0 ; V_21 < V_392 ; V_21 ++ )
F_211 ( V_12 , V_391 + V_21 ) ;
V_15 = F_216 ( V_12 , V_391 , V_111 , V_392 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_37 ) ;
goto V_397;
}
return 0 ;
V_397:
F_217 ( V_12 , V_391 , V_392 ) ;
return V_15 ;
}
static int F_220 ( struct V_395 * V_395 , T_1 V_10 )
{
struct V_12 * V_12 = F_219 ( V_395 ) ;
struct V_33 * V_33 ;
T_1 V_396 , V_391 ;
unsigned int V_392 ;
int V_21 ;
V_33 = V_12 -> V_209 [ V_10 ] ;
if ( ! V_33 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_33 ,
V_10 ) ;
return - V_81 ;
}
if ( ! V_33 -> V_184 ) {
F_35 ( V_33 -> V_51 , L_38 ) ;
return - V_81 ;
}
V_396 = V_33 -> V_183 . V_112 ;
V_392 = V_396 == 1 ? 4 : 2 ;
V_391 = F_215 ( V_10 ) ;
if ( V_392 == 2 && V_10 >= V_391 + 2 )
V_391 = V_391 + 2 ;
for ( V_21 = 0 ; V_21 < V_392 ; V_21 ++ )
F_211 ( V_12 , V_391 + V_21 ) ;
F_217 ( V_12 , V_391 , V_392 ) ;
return 0 ;
}
static void F_221 ( const struct V_398 * V_399 ,
char * V_400 , void * V_401 )
{
struct V_12 * V_12 = V_401 ;
struct V_33 * V_33 ;
enum V_402 V_403 ;
T_1 V_10 ;
V_10 = F_222 ( V_400 ) ;
V_33 = V_12 -> V_209 [ V_10 ] ;
if ( ! V_33 )
return;
V_403 = F_223 ( V_400 ) ;
if ( V_403 == V_404 ) {
F_224 ( V_33 -> V_51 , L_39 ) ;
F_225 ( V_33 -> V_51 ) ;
} else {
F_224 ( V_33 -> V_51 , L_40 ) ;
F_200 ( V_33 -> V_51 ) ;
}
}
static int F_226 ( struct V_12 * V_12 ,
enum V_405 V_406 )
{
struct V_407 * V_408 ;
char V_409 [ V_410 ] ;
int V_15 ;
switch ( V_406 ) {
case V_411 :
V_408 = & V_412 ;
break;
}
V_15 = F_227 ( V_12 -> V_16 , V_408 , V_12 ) ;
if ( V_15 )
return V_15 ;
F_228 ( V_409 , V_413 , V_406 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_414 ) , V_409 ) ;
if ( V_15 )
goto V_415;
return 0 ;
V_415:
F_229 ( V_12 -> V_16 , V_408 , V_12 ) ;
return V_15 ;
}
static void F_230 ( struct V_12 * V_12 ,
enum V_405 V_406 )
{
struct V_407 * V_408 ;
switch ( V_406 ) {
case V_411 :
V_408 = & V_412 ;
break;
}
F_229 ( V_12 -> V_16 , V_408 , V_12 ) ;
}
static void F_231 ( struct V_1 * V_2 , T_1 V_10 ,
void * V_401 )
{
struct V_12 * V_12 = V_401 ;
struct V_33 * V_33 = V_12 -> V_209 [ V_10 ] ;
struct V_115 * V_116 ;
if ( F_85 ( ! V_33 ) ) {
F_232 ( V_12 -> V_226 -> V_51 , L_41 ,
V_10 ) ;
return;
}
V_2 -> V_51 = V_33 -> V_51 ;
V_116 = F_92 ( V_33 -> V_116 ) ;
F_93 ( & V_116 -> V_123 ) ;
V_116 -> V_154 ++ ;
V_116 -> V_155 += V_2 -> V_118 ;
F_94 ( & V_116 -> V_123 ) ;
V_2 -> V_205 = F_233 ( V_2 , V_2 -> V_51 ) ;
F_234 ( V_2 ) ;
}
static int F_235 ( struct V_12 * V_12 )
{
char V_416 [ V_417 ] ;
char V_409 [ V_410 ] ;
int V_21 ;
int V_15 ;
F_236 ( V_416 , V_418 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_419 ) , V_416 ) ;
if ( V_15 )
return V_15 ;
F_236 ( V_416 , V_420 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_419 ) , V_416 ) ;
if ( V_15 )
return V_15 ;
for ( V_21 = 0 ; V_21 < F_237 ( V_421 ) ; V_21 ++ ) {
V_15 = F_238 ( V_12 -> V_16 ,
& V_421 [ V_21 ] ,
V_12 ) ;
if ( V_15 )
goto V_422;
F_228 ( V_409 , V_423 ,
V_421 [ V_21 ] . V_406 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_414 ) , V_409 ) ;
if ( V_15 )
goto V_424;
}
return 0 ;
V_424:
F_239 ( V_12 -> V_16 ,
& V_421 [ V_21 ] ,
V_12 ) ;
V_422:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- ) {
F_228 ( V_409 , V_425 ,
V_421 [ V_21 ] . V_406 ) ;
F_24 ( V_12 -> V_16 , F_12 ( V_414 ) , V_409 ) ;
F_239 ( V_12 -> V_16 ,
& V_421 [ V_21 ] ,
V_12 ) ;
}
return V_15 ;
}
static void F_240 ( struct V_12 * V_12 )
{
char V_409 [ V_410 ] ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_237 ( V_421 ) ; V_21 ++ ) {
F_228 ( V_409 , V_425 ,
V_421 [ V_21 ] . V_406 ) ;
F_24 ( V_12 -> V_16 , F_12 ( V_414 ) , V_409 ) ;
F_239 ( V_12 -> V_16 ,
& V_421 [ V_21 ] ,
V_12 ) ;
}
}
static int F_241 ( struct V_395 * V_395 ,
enum V_426 type ,
enum V_427 V_428 )
{
enum V_429 V_430 ;
enum V_431 V_432 ;
char V_433 [ V_434 ] ;
if ( V_428 == V_435 )
V_430 = V_436 ;
else
V_430 = V_437 ;
if ( type == V_438 )
V_432 = V_439 ;
else
V_432 = V_440 ;
F_242 ( V_433 , type , V_428 , V_430 ,
V_432 ) ;
return F_24 ( V_395 , F_12 ( V_441 ) , V_433 ) ;
}
static int F_243 ( struct V_12 * V_12 )
{
int type , V_15 ;
for ( type = 0 ; type < V_442 ; type ++ ) {
if ( type == V_443 )
continue;
V_15 = F_241 ( V_12 -> V_16 , type ,
V_435 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_241 ( V_12 -> V_16 , type ,
V_444 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_244 ( struct V_12 * V_12 )
{
char V_445 [ V_446 ] ;
F_245 ( V_445 , V_447 |
V_448 |
V_449 |
V_450 |
V_451 |
V_452 |
V_453 |
V_454 |
V_455 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_456 ) , V_445 ) ;
}
static int F_246 ( struct V_395 * V_395 ,
const struct V_457 * V_457 )
{
struct V_12 * V_12 = F_219 ( V_395 ) ;
int V_15 ;
V_12 -> V_16 = V_395 ;
V_12 -> V_226 = V_457 ;
F_17 ( & V_12 -> V_458 ) ;
F_17 ( & V_12 -> V_459 . V_59 ) ;
F_17 ( & V_12 -> V_460 . V_59 ) ;
V_15 = F_10 ( V_12 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_42 ) ;
return V_15 ;
}
V_15 = F_226 ( V_12 , V_411 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_43 ) ;
return V_15 ;
}
V_15 = F_235 ( V_12 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_44 ) ;
goto V_422;
}
V_15 = F_243 ( V_12 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_45 ) ;
goto V_461;
}
V_15 = F_247 ( V_12 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_46 ) ;
goto V_462;
}
V_15 = F_244 ( V_12 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_47 ) ;
goto V_463;
}
V_15 = F_248 ( V_12 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_48 ) ;
goto V_464;
}
V_15 = F_249 ( V_12 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_49 ) ;
goto V_465;
}
V_15 = F_14 ( V_12 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_50 ) ;
goto V_466;
}
V_15 = F_214 ( V_12 ) ;
if ( V_15 ) {
F_199 ( V_12 -> V_226 -> V_51 , L_51 ) ;
goto V_467;
}
return 0 ;
V_467:
F_18 ( V_12 ) ;
V_466:
F_250 ( V_12 ) ;
V_465:
F_251 ( V_12 ) ;
V_464:
V_463:
F_252 ( V_12 ) ;
V_462:
V_461:
F_240 ( V_12 ) ;
V_422:
F_230 ( V_12 , V_411 ) ;
return V_15 ;
}
static void F_253 ( struct V_395 * V_395 )
{
struct V_12 * V_12 = F_219 ( V_395 ) ;
int V_21 ;
F_213 ( V_12 ) ;
F_18 ( V_12 ) ;
F_250 ( V_12 ) ;
F_251 ( V_12 ) ;
F_252 ( V_12 ) ;
F_240 ( V_12 ) ;
F_230 ( V_12 , V_411 ) ;
F_125 ( ! F_20 ( & V_12 -> V_459 . V_59 ) ) ;
F_125 ( ! F_20 ( & V_12 -> V_458 ) ) ;
for ( V_21 = 0 ; V_21 < V_468 ; V_21 ++ )
F_19 ( V_12 -> V_469 [ V_21 ] ) ;
}
static bool F_133 ( const struct V_114 * V_51 )
{
return V_51 -> V_358 == & V_359 ;
}
static struct V_33 * F_254 ( struct V_114 * V_51 )
{
struct V_114 * V_470 ;
struct V_471 * V_472 ;
if ( F_133 ( V_51 ) )
return F_79 ( V_51 ) ;
F_255 (dev, lower_dev, iter) {
if ( F_133 ( V_470 ) )
return F_79 ( V_470 ) ;
}
return NULL ;
}
static struct V_12 * F_256 ( struct V_114 * V_51 )
{
struct V_33 * V_33 ;
V_33 = F_254 ( V_51 ) ;
return V_33 ? V_33 -> V_12 : NULL ;
}
static struct V_33 * F_257 ( struct V_114 * V_51 )
{
struct V_114 * V_470 ;
struct V_471 * V_472 ;
if ( F_133 ( V_51 ) )
return F_79 ( V_51 ) ;
F_258 (dev, lower_dev, iter) {
if ( F_133 ( V_470 ) )
return F_79 ( V_470 ) ;
}
return NULL ;
}
struct V_33 * F_259 ( struct V_114 * V_51 )
{
struct V_33 * V_33 ;
F_260 () ;
V_33 = F_257 ( V_51 ) ;
if ( V_33 )
F_261 ( V_33 -> V_51 ) ;
F_262 () ;
return V_33 ;
}
void F_263 ( struct V_33 * V_33 )
{
F_264 ( V_33 -> V_51 ) ;
}
static bool F_265 ( struct V_473 * V_474 ,
unsigned long V_475 )
{
switch ( V_475 ) {
case V_476 :
if ( ! V_474 )
return true ;
V_474 -> V_42 ++ ;
return false ;
case V_477 :
if ( V_474 && -- V_474 -> V_42 == 0 )
return true ;
return false ;
}
return false ;
}
static int F_266 ( struct V_12 * V_12 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_468 ; V_21 ++ )
if ( ! V_12 -> V_469 [ V_21 ] )
return V_21 ;
return V_468 ;
}
static void F_267 ( struct V_33 * V_168 ,
bool * V_478 , T_2 * V_479 )
{
T_1 V_10 = V_168 -> V_10 ;
* V_478 = V_168 -> V_171 ;
* V_479 = * V_478 ? V_168 -> V_172 : V_10 ;
}
static int F_268 ( struct V_33 * V_168 ,
struct V_114 * V_480 , T_2 V_481 ,
bool V_482 )
{
struct V_12 * V_12 = V_168 -> V_12 ;
bool V_171 = V_168 -> V_171 ;
char V_483 [ V_484 ] ;
T_2 V_485 ;
F_269 ( V_483 , V_482 , V_486 , V_481 ,
V_480 -> V_47 , V_480 -> V_74 ) ;
F_267 ( V_168 , & V_171 , & V_485 ) ;
F_270 ( V_483 , V_171 , V_485 ,
F_271 ( V_168 ) ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_487 ) , V_483 ) ;
}
static struct V_179 *
F_272 ( T_2 V_93 , struct V_114 * V_480 )
{
struct V_179 * V_180 ;
V_180 = F_39 ( sizeof( * V_180 ) , V_29 ) ;
if ( ! V_180 )
return NULL ;
V_180 -> V_181 = V_488 ;
V_180 -> V_42 = 0 ;
V_180 -> V_51 = V_480 ;
V_180 -> V_93 = V_93 ;
return V_180 ;
}
static struct V_473 *
F_273 ( T_2 V_481 , struct V_114 * V_480 , struct V_179 * V_180 )
{
struct V_473 * V_474 ;
V_474 = F_39 ( sizeof( * V_474 ) , V_29 ) ;
if ( ! V_474 )
return NULL ;
F_52 ( V_474 -> V_70 , V_480 -> V_74 ) ;
V_474 -> V_47 = V_480 -> V_47 ;
V_474 -> V_42 = 1 ;
V_474 -> V_51 = V_480 ;
V_474 -> V_481 = V_481 ;
V_474 -> V_180 = V_180 ;
return V_474 ;
}
static struct V_473 *
F_274 ( struct V_33 * V_168 ,
struct V_114 * V_480 )
{
struct V_12 * V_12 = V_168 -> V_12 ;
struct V_179 * V_180 ;
struct V_473 * V_474 ;
T_2 V_93 , V_481 ;
int V_15 ;
V_481 = F_266 ( V_12 ) ;
if ( V_481 == V_468 )
return F_275 ( - V_489 ) ;
V_15 = F_268 ( V_168 , V_480 , V_481 , true ) ;
if ( V_15 )
return F_275 ( V_15 ) ;
V_93 = F_276 ( V_481 ) ;
V_15 = F_277 ( V_12 , V_480 -> V_74 , V_93 , true ) ;
if ( V_15 )
goto V_490;
V_180 = F_272 ( V_93 , V_480 ) ;
if ( ! V_180 ) {
V_15 = - V_30 ;
goto V_491;
}
V_474 = F_273 ( V_481 , V_480 , V_180 ) ;
if ( ! V_474 ) {
V_15 = - V_30 ;
goto V_492;
}
V_180 -> V_474 = V_474 ;
V_12 -> V_469 [ V_481 ] = V_474 ;
return V_474 ;
V_492:
F_21 ( V_180 ) ;
V_491:
F_277 ( V_12 , V_480 -> V_74 , V_93 , false ) ;
V_490:
F_268 ( V_168 , V_480 , V_481 , false ) ;
return F_275 ( V_15 ) ;
}
static void F_278 ( struct V_33 * V_168 ,
struct V_473 * V_474 )
{
struct V_12 * V_12 = V_168 -> V_12 ;
struct V_114 * V_480 = V_474 -> V_51 ;
struct V_179 * V_180 = V_474 -> V_180 ;
T_2 V_93 = V_180 -> V_93 ;
T_2 V_481 = V_474 -> V_481 ;
V_12 -> V_469 [ V_481 ] = NULL ;
V_180 -> V_474 = NULL ;
F_21 ( V_474 ) ;
F_21 ( V_180 ) ;
F_277 ( V_12 , V_480 -> V_74 , V_93 , false ) ;
F_268 ( V_168 , V_480 , V_481 , false ) ;
}
static int F_279 ( struct V_33 * V_168 ,
struct V_114 * V_480 )
{
struct V_12 * V_12 = V_168 -> V_12 ;
struct V_473 * V_474 ;
V_474 = F_280 ( V_12 , V_480 ) ;
if ( ! V_474 ) {
V_474 = F_274 ( V_168 , V_480 ) ;
if ( F_281 ( V_474 ) )
return F_282 ( V_474 ) ;
}
F_283 ( V_168 , V_474 -> V_180 ) ;
V_474 -> V_180 -> V_42 ++ ;
F_44 ( V_168 -> V_51 , L_52 , V_474 -> V_180 -> V_93 ) ;
return 0 ;
}
static void V_488 ( struct V_33 * V_168 )
{
struct V_179 * V_180 = F_126 ( V_168 ) ;
F_44 ( V_168 -> V_51 , L_53 , V_180 -> V_93 ) ;
F_283 ( V_168 , NULL ) ;
if ( -- V_180 -> V_42 == 0 )
F_278 ( V_168 , V_180 -> V_474 ) ;
}
static int F_284 ( struct V_114 * V_480 ,
struct V_114 * V_493 ,
unsigned long V_475 , T_2 V_94 )
{
struct V_33 * V_33 = F_79 ( V_493 ) ;
struct V_33 * V_168 ;
V_168 = F_122 ( V_33 , V_94 ) ;
if ( F_125 ( ! V_168 ) )
return - V_81 ;
switch ( V_475 ) {
case V_476 :
return F_279 ( V_168 , V_480 ) ;
case V_477 :
V_488 ( V_168 ) ;
break;
}
return 0 ;
}
static int F_285 ( struct V_114 * V_493 ,
unsigned long V_475 )
{
if ( F_286 ( V_493 ) || F_287 ( V_493 ) )
return 0 ;
return F_284 ( V_493 , V_493 , V_475 , 1 ) ;
}
static int F_288 ( struct V_114 * V_480 ,
struct V_114 * V_494 ,
unsigned long V_475 , T_2 V_94 )
{
struct V_114 * V_493 ;
struct V_471 * V_472 ;
int V_15 ;
F_289 (lag_dev, port_dev, iter) {
if ( F_133 ( V_493 ) ) {
V_15 = F_284 ( V_480 , V_493 ,
V_475 , V_94 ) ;
if ( V_15 )
return V_15 ;
}
}
return 0 ;
}
static int F_290 ( struct V_114 * V_494 ,
unsigned long V_475 )
{
if ( F_286 ( V_494 ) )
return 0 ;
return F_288 ( V_494 , V_494 , V_475 , 1 ) ;
}
static struct V_179 * F_291 ( struct V_12 * V_12 ,
struct V_114 * V_480 )
{
T_2 V_93 ;
if ( F_292 ( V_480 ) )
V_93 = F_293 ( V_480 ) ;
else if ( V_12 -> V_495 . V_51 == V_480 )
V_93 = 1 ;
else
return F_294 ( V_12 , V_480 ) ;
return F_295 ( V_12 , V_93 ) ;
}
static enum V_429 F_296 ( T_2 V_93 )
{
return F_297 ( V_93 ) ? V_436 :
V_437 ;
}
static T_2 F_298 ( T_2 V_93 )
{
return F_297 ( V_93 ) ? F_299 ( V_93 ) : V_93 ;
}
static int F_300 ( struct V_12 * V_12 , T_2 V_93 ,
bool V_496 )
{
enum V_429 V_430 ;
char * V_497 ;
T_2 V_38 ;
int V_15 ;
V_497 = F_64 ( V_498 , V_29 ) ;
if ( ! V_497 )
return - V_30 ;
V_430 = F_296 ( V_93 ) ;
V_38 = F_298 ( V_93 ) ;
F_301 ( V_497 , V_440 , V_38 , V_430 ,
1 , V_499 , V_496 ) ;
V_15 = F_24 ( V_12 -> V_16 , F_12 ( V_500 ) , V_497 ) ;
F_21 ( V_497 ) ;
return V_15 ;
}
static enum V_501 F_302 ( T_2 V_93 )
{
if ( F_297 ( V_93 ) )
return V_502 ;
else
return V_503 ;
}
static int F_303 ( struct V_12 * V_12 ,
struct V_114 * V_480 ,
T_2 V_93 , T_2 V_481 ,
bool V_482 )
{
enum V_501 V_504 ;
char V_483 [ V_484 ] ;
V_504 = F_302 ( V_93 ) ;
F_269 ( V_483 , V_482 , V_504 , V_481 , V_480 -> V_47 ,
V_480 -> V_74 ) ;
F_304 ( V_483 , V_504 , V_93 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_487 ) , V_483 ) ;
}
static int F_305 ( struct V_12 * V_12 ,
struct V_114 * V_480 ,
struct V_179 * V_180 )
{
struct V_473 * V_474 ;
T_2 V_481 ;
int V_15 ;
V_481 = F_266 ( V_12 ) ;
if ( V_481 == V_468 )
return - V_489 ;
V_15 = F_300 ( V_12 , V_180 -> V_93 , true ) ;
if ( V_15 )
return V_15 ;
V_15 = F_303 ( V_12 , V_480 , V_180 -> V_93 , V_481 , true ) ;
if ( V_15 )
goto V_505;
V_15 = F_277 ( V_12 , V_480 -> V_74 , V_180 -> V_93 , true ) ;
if ( V_15 )
goto V_490;
V_474 = F_273 ( V_481 , V_480 , V_180 ) ;
if ( ! V_474 ) {
V_15 = - V_30 ;
goto V_492;
}
V_180 -> V_474 = V_474 ;
V_12 -> V_469 [ V_481 ] = V_474 ;
F_44 ( V_480 , L_54 , V_481 ) ;
return 0 ;
V_492:
F_277 ( V_12 , V_480 -> V_74 , V_180 -> V_93 , false ) ;
V_490:
F_303 ( V_12 , V_480 , V_180 -> V_93 , V_481 , false ) ;
V_505:
F_300 ( V_12 , V_180 -> V_93 , false ) ;
return V_15 ;
}
void F_306 ( struct V_12 * V_12 ,
struct V_473 * V_474 )
{
struct V_114 * V_480 = V_474 -> V_51 ;
struct V_179 * V_180 = V_474 -> V_180 ;
T_2 V_481 = V_474 -> V_481 ;
V_12 -> V_469 [ V_481 ] = NULL ;
V_180 -> V_474 = NULL ;
F_21 ( V_474 ) ;
F_277 ( V_12 , V_480 -> V_74 , V_180 -> V_93 , false ) ;
F_303 ( V_12 , V_480 , V_180 -> V_93 , V_481 , false ) ;
F_300 ( V_12 , V_180 -> V_93 , false ) ;
F_44 ( V_480 , L_55 , V_481 ) ;
}
static int F_307 ( struct V_114 * V_480 ,
struct V_114 * V_506 ,
unsigned long V_475 )
{
struct V_12 * V_12 = F_256 ( V_480 ) ;
struct V_179 * V_180 ;
V_180 = F_291 ( V_12 , V_480 ) ;
if ( F_125 ( ! V_180 ) )
return - V_81 ;
switch ( V_475 ) {
case V_476 :
return F_305 ( V_12 , V_480 , V_180 ) ;
case V_477 :
F_306 ( V_12 , V_180 -> V_474 ) ;
break;
}
return 0 ;
}
static int F_308 ( struct V_114 * V_507 ,
unsigned long V_475 )
{
struct V_114 * V_508 = F_309 ( V_507 ) ;
struct V_12 * V_12 = F_256 ( V_507 ) ;
T_2 V_94 = F_293 ( V_507 ) ;
if ( F_133 ( V_508 ) )
return F_284 ( V_507 , V_508 , V_475 ,
V_94 ) ;
else if ( F_310 ( V_508 ) )
return F_288 ( V_507 , V_508 , V_475 ,
V_94 ) ;
else if ( F_311 ( V_508 ) &&
V_12 -> V_495 . V_51 == V_508 )
return F_307 ( V_507 , V_508 ,
V_475 ) ;
return 0 ;
}
static int F_312 ( struct V_509 * V_510 ,
unsigned long V_475 , void * V_511 )
{
struct V_512 * V_513 = (struct V_512 * ) V_511 ;
struct V_114 * V_51 = V_513 -> V_514 -> V_51 ;
struct V_12 * V_12 ;
struct V_473 * V_474 ;
int V_15 = 0 ;
V_12 = F_256 ( V_51 ) ;
if ( ! V_12 )
goto V_306;
V_474 = F_280 ( V_12 , V_51 ) ;
if ( ! F_265 ( V_474 , V_475 ) )
goto V_306;
if ( F_133 ( V_51 ) )
V_15 = F_285 ( V_51 , V_475 ) ;
else if ( F_310 ( V_51 ) )
V_15 = F_290 ( V_51 , V_475 ) ;
else if ( F_311 ( V_51 ) )
V_15 = F_307 ( V_51 , V_51 , V_475 ) ;
else if ( F_292 ( V_51 ) )
V_15 = F_308 ( V_51 , V_475 ) ;
V_306:
return F_313 ( V_15 ) ;
}
static int F_314 ( struct V_12 * V_12 , T_2 V_481 ,
const char * V_515 , int V_47 )
{
char V_483 [ V_484 ] ;
int V_15 ;
F_315 ( V_483 , V_481 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_487 ) , V_483 ) ;
if ( V_15 )
return V_15 ;
F_316 ( V_483 , V_47 ) ;
F_317 ( V_483 , V_515 ) ;
F_318 ( V_483 , V_516 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_487 ) , V_483 ) ;
}
static int F_319 ( struct V_114 * V_51 )
{
struct V_12 * V_12 ;
struct V_473 * V_474 ;
int V_15 ;
V_12 = F_256 ( V_51 ) ;
if ( ! V_12 )
return 0 ;
V_474 = F_280 ( V_12 , V_51 ) ;
if ( ! V_474 )
return 0 ;
V_15 = F_277 ( V_12 , V_474 -> V_70 , V_474 -> V_180 -> V_93 , false ) ;
if ( V_15 )
return V_15 ;
V_15 = F_314 ( V_12 , V_474 -> V_481 , V_51 -> V_74 , V_51 -> V_47 ) ;
if ( V_15 )
goto V_517;
V_15 = F_277 ( V_12 , V_51 -> V_74 , V_474 -> V_180 -> V_93 , true ) ;
if ( V_15 )
goto V_490;
F_52 ( V_474 -> V_70 , V_51 -> V_74 ) ;
V_474 -> V_47 = V_51 -> V_47 ;
F_44 ( V_51 , L_56 , V_474 -> V_481 ) ;
return 0 ;
V_490:
F_314 ( V_12 , V_474 -> V_481 , V_474 -> V_70 , V_474 -> V_47 ) ;
V_517:
F_277 ( V_12 , V_474 -> V_70 , V_474 -> V_180 -> V_93 , true ) ;
return V_15 ;
}
static bool F_320 ( struct V_33 * V_518 ,
T_2 V_93 )
{
if ( F_297 ( V_93 ) )
return F_321 ( V_518 , V_93 ) ;
else
return F_322 ( V_93 , V_518 -> V_353 ) ;
}
static bool F_323 ( struct V_33 * V_33 ,
T_2 V_93 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
T_1 V_10 = V_33 -> V_10 ;
T_2 V_172 = V_33 -> V_172 ;
int V_21 , V_392 = 0 ;
if ( ! V_33 -> V_171 )
return true ;
for ( V_21 = 0 ; V_21 < V_519 ; V_21 ++ ) {
struct V_33 * V_518 ;
V_518 = F_324 ( V_12 , V_172 , V_21 ) ;
if ( ! V_518 || V_518 -> V_10 == V_10 )
continue;
if ( F_320 ( V_518 , V_93 ) )
V_392 ++ ;
}
return ! V_392 ;
}
static int
F_325 ( const struct V_33 * V_33 ,
T_2 V_93 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_520 [ V_521 ] ;
F_326 ( V_520 , V_522 ) ;
F_327 ( V_520 , V_93 ) ;
F_328 ( V_520 ,
V_33 -> V_10 ) ;
F_44 ( V_33 -> V_51 , L_57 ,
V_33 -> V_10 , V_93 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_523 ) , V_520 ) ;
}
static int
F_329 ( const struct V_33 * V_33 ,
T_2 V_93 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_520 [ V_521 ] ;
F_326 ( V_520 , V_524 ) ;
F_327 ( V_520 , V_93 ) ;
F_330 ( V_520 , V_33 -> V_172 ) ;
F_44 ( V_33 -> V_51 , L_58 ,
V_33 -> V_172 , V_93 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_523 ) , V_520 ) ;
}
int F_331 ( struct V_33 * V_33 , T_2 V_93 )
{
if ( ! F_323 ( V_33 , V_93 ) )
return 0 ;
if ( V_33 -> V_171 )
return F_329 ( V_33 ,
V_93 ) ;
else
return F_325 ( V_33 , V_93 ) ;
}
static void F_332 ( struct V_12 * V_12 )
{
struct V_179 * V_180 , * V_525 ;
F_333 (f, tmp, &mlxsw_sp->fids, list)
if ( -- V_180 -> V_42 == 0 )
F_334 ( V_12 , V_180 ) ;
else
F_19 ( 1 ) ;
}
static bool F_335 ( struct V_12 * V_12 ,
struct V_114 * V_506 )
{
return ! V_12 -> V_495 . V_51 ||
V_12 -> V_495 . V_51 == V_506 ;
}
static void F_336 ( struct V_12 * V_12 ,
struct V_114 * V_506 )
{
V_12 -> V_495 . V_51 = V_506 ;
V_12 -> V_495 . V_42 ++ ;
}
static void F_337 ( struct V_12 * V_12 )
{
if ( -- V_12 -> V_495 . V_42 == 0 ) {
V_12 -> V_495 . V_51 = NULL ;
F_332 ( V_12 ) ;
}
}
static int F_338 ( struct V_33 * V_33 ,
struct V_114 * V_506 )
{
struct V_114 * V_51 = V_33 -> V_51 ;
int V_15 ;
V_15 = F_124 ( V_51 , 0 , 1 ) ;
if ( V_15 )
return V_15 ;
F_336 ( V_33 -> V_12 , V_506 ) ;
V_33 -> V_526 = 1 ;
V_33 -> V_527 = 1 ;
V_33 -> V_528 = 1 ;
V_33 -> V_529 = 1 ;
return 0 ;
}
static void F_339 ( struct V_33 * V_33 )
{
struct V_114 * V_51 = V_33 -> V_51 ;
F_340 ( V_33 , 1 ) ;
F_337 ( V_33 -> V_12 ) ;
V_33 -> V_526 = 0 ;
V_33 -> V_527 = 0 ;
V_33 -> V_528 = 0 ;
V_33 -> V_529 = 0 ;
F_121 ( V_51 , 0 , 1 ) ;
}
static int F_341 ( struct V_12 * V_12 , T_2 V_172 )
{
char V_530 [ V_531 ] ;
F_342 ( V_530 , V_172 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_532 ) , V_530 ) ;
}
static int F_343 ( struct V_12 * V_12 , T_2 V_172 )
{
char V_530 [ V_531 ] ;
F_344 ( V_530 , V_172 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_532 ) , V_530 ) ;
}
static int F_345 ( struct V_33 * V_33 ,
T_2 V_172 , T_1 V_533 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_534 [ V_535 ] ;
F_346 ( V_534 , V_33 -> V_10 ,
V_172 , V_533 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_536 ) , V_534 ) ;
}
static int F_347 ( struct V_33 * V_33 ,
T_2 V_172 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_534 [ V_535 ] ;
F_348 ( V_534 , V_33 -> V_10 ,
V_172 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_536 ) , V_534 ) ;
}
static int F_349 ( struct V_33 * V_33 ,
T_2 V_172 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_534 [ V_535 ] ;
F_350 ( V_534 , V_33 -> V_10 ,
V_172 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_536 ) , V_534 ) ;
}
static int F_351 ( struct V_33 * V_33 ,
T_2 V_172 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_534 [ V_535 ] ;
F_352 ( V_534 , V_33 -> V_10 ,
V_172 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_536 ) , V_534 ) ;
}
static int F_353 ( struct V_12 * V_12 ,
struct V_114 * V_494 ,
T_2 * V_537 )
{
struct V_538 * V_539 ;
int V_540 = - 1 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_541 ; V_21 ++ ) {
V_539 = F_354 ( V_12 , V_21 ) ;
if ( V_539 -> V_42 ) {
if ( V_539 -> V_51 == V_494 ) {
* V_537 = V_21 ;
return 0 ;
}
} else if ( V_540 < 0 ) {
V_540 = V_21 ;
}
}
if ( V_540 < 0 )
return - V_542 ;
* V_537 = V_540 ;
return 0 ;
}
static bool
F_355 ( struct V_12 * V_12 ,
struct V_114 * V_494 ,
struct V_543 * V_544 )
{
T_2 V_172 ;
if ( F_353 ( V_12 , V_494 , & V_172 ) != 0 )
return false ;
if ( V_544 -> V_545 != V_546 )
return false ;
return true ;
}
static int F_356 ( struct V_12 * V_12 ,
T_2 V_172 , T_1 * V_547 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_519 ; V_21 ++ ) {
if ( ! F_324 ( V_12 , V_172 , V_21 ) ) {
* V_547 = V_21 ;
return 0 ;
}
}
return - V_542 ;
}
static void
F_357 ( struct V_33 * V_33 ,
T_2 V_172 )
{
struct V_33 * V_168 ;
struct V_179 * V_180 ;
V_168 = F_122 ( V_33 , 1 ) ;
if ( F_125 ( ! V_168 ) )
return;
V_180 = F_126 ( V_168 ) ;
if ( V_180 )
V_180 -> V_181 ( V_168 ) ;
V_168 -> V_172 = V_172 ;
V_168 -> V_171 = 1 ;
}
static void
F_358 ( struct V_33 * V_33 )
{
struct V_33 * V_168 ;
struct V_179 * V_180 ;
V_168 = F_122 ( V_33 , 1 ) ;
if ( F_125 ( ! V_168 ) )
return;
V_180 = F_126 ( V_168 ) ;
if ( V_180 )
V_180 -> V_181 ( V_168 ) ;
V_168 -> V_171 = 0 ;
}
static int F_359 ( struct V_33 * V_33 ,
struct V_114 * V_494 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
struct V_538 * V_539 ;
T_2 V_172 ;
T_1 V_533 ;
int V_15 ;
V_15 = F_353 ( V_12 , V_494 , & V_172 ) ;
if ( V_15 )
return V_15 ;
V_539 = F_354 ( V_12 , V_172 ) ;
if ( ! V_539 -> V_42 ) {
V_15 = F_341 ( V_12 , V_172 ) ;
if ( V_15 )
return V_15 ;
V_539 -> V_51 = V_494 ;
}
V_15 = F_356 ( V_12 , V_172 , & V_533 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_345 ( V_33 , V_172 , V_533 ) ;
if ( V_15 )
goto V_548;
V_15 = F_349 ( V_33 , V_172 ) ;
if ( V_15 )
goto V_549;
F_360 ( V_12 -> V_16 , V_172 , V_533 ,
V_33 -> V_10 ) ;
V_33 -> V_172 = V_172 ;
V_33 -> V_171 = 1 ;
V_539 -> V_42 ++ ;
F_357 ( V_33 , V_172 ) ;
return 0 ;
V_549:
F_347 ( V_33 , V_172 ) ;
V_548:
if ( ! V_539 -> V_42 )
F_343 ( V_12 , V_172 ) ;
return V_15 ;
}
static void F_361 ( struct V_33 * V_33 ,
struct V_114 * V_494 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
T_2 V_172 = V_33 -> V_172 ;
struct V_538 * V_539 ;
if ( ! V_33 -> V_171 )
return;
V_539 = F_354 ( V_12 , V_172 ) ;
F_125 ( V_539 -> V_42 == 0 ) ;
F_351 ( V_33 , V_172 ) ;
F_347 ( V_33 , V_172 ) ;
if ( V_33 -> V_529 ) {
F_362 ( V_33 ) ;
F_339 ( V_33 ) ;
}
if ( V_539 -> V_42 == 1 )
F_343 ( V_12 , V_172 ) ;
F_363 ( V_12 -> V_16 , V_172 ,
V_33 -> V_10 ) ;
V_33 -> V_171 = 0 ;
V_539 -> V_42 -- ;
F_358 ( V_33 ) ;
}
static int F_364 ( struct V_33 * V_33 ,
T_2 V_172 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_530 [ V_531 ] ;
F_365 ( V_530 , V_172 ,
V_33 -> V_10 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_532 ) , V_530 ) ;
}
static int F_366 ( struct V_33 * V_33 ,
T_2 V_172 )
{
struct V_12 * V_12 = V_33 -> V_12 ;
char V_530 [ V_531 ] ;
F_367 ( V_530 , V_172 ,
V_33 -> V_10 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_532 ) , V_530 ) ;
}
static int F_368 ( struct V_33 * V_33 ,
bool V_550 )
{
if ( V_550 )
return F_364 ( V_33 ,
V_33 -> V_172 ) ;
else
return F_366 ( V_33 ,
V_33 -> V_172 ) ;
}
static int F_369 ( struct V_33 * V_33 ,
struct V_551 * V_552 )
{
return F_368 ( V_33 , V_552 -> V_553 ) ;
}
static int F_370 ( struct V_33 * V_33 ,
struct V_114 * V_507 )
{
struct V_33 * V_168 ;
T_2 V_94 = F_293 ( V_507 ) ;
V_168 = F_122 ( V_33 , V_94 ) ;
if ( F_125 ( ! V_168 ) )
return - V_81 ;
V_168 -> V_51 = V_507 ;
return 0 ;
}
static void F_371 ( struct V_33 * V_33 ,
struct V_114 * V_507 )
{
struct V_33 * V_168 ;
T_2 V_94 = F_293 ( V_507 ) ;
V_168 = F_122 ( V_33 , V_94 ) ;
if ( F_125 ( ! V_168 ) )
return;
V_168 -> V_51 = V_33 -> V_51 ;
}
static int F_372 ( struct V_114 * V_51 ,
unsigned long V_475 , void * V_511 )
{
struct V_554 * V_552 ;
struct V_33 * V_33 ;
struct V_114 * V_555 ;
struct V_12 * V_12 ;
int V_15 = 0 ;
V_33 = F_79 ( V_51 ) ;
V_12 = V_33 -> V_12 ;
V_552 = V_511 ;
switch ( V_475 ) {
case V_556 :
V_555 = V_552 -> V_555 ;
if ( ! F_292 ( V_555 ) &&
! F_310 ( V_555 ) &&
! F_311 ( V_555 ) )
return - V_81 ;
if ( ! V_552 -> V_557 )
break;
if ( F_311 ( V_555 ) &&
! F_335 ( V_12 , V_555 ) )
return - V_81 ;
if ( F_310 ( V_555 ) &&
! F_355 ( V_12 , V_555 ,
V_552 -> V_558 ) )
return - V_81 ;
if ( F_310 ( V_555 ) && F_373 ( V_51 ) )
return - V_81 ;
if ( F_287 ( V_51 ) && F_292 ( V_555 ) &&
! F_310 ( F_309 ( V_555 ) ) )
return - V_81 ;
break;
case V_559 :
V_555 = V_552 -> V_555 ;
if ( F_292 ( V_555 ) ) {
if ( V_552 -> V_557 )
V_15 = F_370 ( V_33 ,
V_555 ) ;
else
F_371 ( V_33 ,
V_555 ) ;
} else if ( F_311 ( V_555 ) ) {
if ( V_552 -> V_557 )
V_15 = F_338 ( V_33 ,
V_555 ) ;
else
F_339 ( V_33 ) ;
} else if ( F_310 ( V_555 ) ) {
if ( V_552 -> V_557 )
V_15 = F_359 ( V_33 ,
V_555 ) ;
else
F_361 ( V_33 ,
V_555 ) ;
} else {
V_15 = - V_81 ;
F_125 ( 1 ) ;
}
break;
}
return V_15 ;
}
static int F_374 ( struct V_114 * V_51 ,
unsigned long V_475 , void * V_511 )
{
struct V_560 * V_552 ;
struct V_33 * V_33 ;
int V_15 ;
V_33 = F_79 ( V_51 ) ;
V_552 = V_511 ;
switch ( V_475 ) {
case V_561 :
if ( F_287 ( V_51 ) && V_33 -> V_171 ) {
V_15 = F_369 ( V_33 ,
V_552 -> V_562 ) ;
if ( V_15 )
F_35 ( V_51 , L_59 ) ;
}
break;
}
return 0 ;
}
static int F_375 ( struct V_114 * V_51 ,
unsigned long V_475 , void * V_511 )
{
switch ( V_475 ) {
case V_556 :
case V_559 :
return F_372 ( V_51 , V_475 , V_511 ) ;
case V_561 :
return F_374 ( V_51 , V_475 , V_511 ) ;
}
return 0 ;
}
static int F_376 ( struct V_114 * V_494 ,
unsigned long V_475 , void * V_511 )
{
struct V_114 * V_51 ;
struct V_471 * V_472 ;
int V_563 ;
F_289 (lag_dev, dev, iter) {
if ( F_133 ( V_51 ) ) {
V_563 = F_375 ( V_51 , V_475 , V_511 ) ;
if ( V_563 )
return V_563 ;
}
}
return 0 ;
}
static int F_377 ( struct V_12 * V_12 ,
struct V_114 * V_507 )
{
T_2 V_93 = F_293 ( V_507 ) ;
struct V_179 * V_180 ;
V_180 = F_295 ( V_12 , V_93 ) ;
if ( ! V_180 ) {
V_180 = F_378 ( V_12 , V_93 ) ;
if ( F_281 ( V_180 ) )
return F_282 ( V_180 ) ;
}
V_180 -> V_42 ++ ;
return 0 ;
}
static void F_379 ( struct V_12 * V_12 ,
struct V_114 * V_507 )
{
T_2 V_93 = F_293 ( V_507 ) ;
struct V_179 * V_180 ;
V_180 = F_295 ( V_12 , V_93 ) ;
if ( V_180 && V_180 -> V_474 )
F_306 ( V_12 , V_180 -> V_474 ) ;
if ( V_180 && -- V_180 -> V_42 == 0 )
F_334 ( V_12 , V_180 ) ;
}
static int F_380 ( struct V_114 * V_506 ,
unsigned long V_475 , void * V_511 )
{
struct V_554 * V_552 ;
struct V_114 * V_555 ;
struct V_12 * V_12 ;
int V_15 ;
V_12 = F_256 ( V_506 ) ;
if ( ! V_12 )
return 0 ;
if ( V_506 != V_12 -> V_495 . V_51 )
return 0 ;
V_552 = V_511 ;
switch ( V_475 ) {
case V_559 :
V_555 = V_552 -> V_555 ;
if ( ! F_292 ( V_555 ) )
break;
if ( V_552 -> V_557 ) {
V_15 = F_377 ( V_12 ,
V_555 ) ;
if ( V_15 )
return V_15 ;
} else {
F_379 ( V_12 , V_555 ) ;
}
break;
}
return 0 ;
}
static T_2 F_381 ( const struct V_12 * V_12 )
{
return F_382 ( V_12 -> V_459 . V_564 ,
V_565 ) ;
}
static int F_383 ( struct V_12 * V_12 , T_2 V_93 , bool V_482 )
{
char V_566 [ V_567 ] ;
F_384 ( V_566 , ! V_482 , V_93 , 0 ) ;
return F_24 ( V_12 -> V_16 , F_12 ( V_568 ) , V_566 ) ;
}
static struct V_179 * F_385 ( struct V_12 * V_12 ,
struct V_114 * V_506 )
{
struct V_569 * V_51 = V_12 -> V_226 -> V_51 ;
struct V_179 * V_180 ;
T_2 V_570 , V_93 ;
int V_15 ;
V_570 = F_381 ( V_12 ) ;
if ( V_570 == V_565 ) {
F_199 ( V_51 , L_60 ) ;
return F_275 ( - V_489 ) ;
}
V_93 = F_386 ( V_570 ) ;
V_15 = F_383 ( V_12 , V_93 , true ) ;
if ( V_15 ) {
F_199 ( V_51 , L_61 , V_93 ) ;
return F_275 ( V_15 ) ;
}
V_180 = F_39 ( sizeof( * V_180 ) , V_29 ) ;
if ( ! V_180 )
goto V_571;
V_180 -> V_181 = V_572 ;
V_180 -> V_93 = V_93 ;
V_180 -> V_51 = V_506 ;
F_119 ( & V_180 -> V_59 , & V_12 -> V_459 . V_59 ) ;
F_387 ( V_570 , V_12 -> V_459 . V_564 ) ;
return V_180 ;
V_571:
F_383 ( V_12 , V_93 , false ) ;
return F_275 ( - V_30 ) ;
}
static void F_388 ( struct V_12 * V_12 ,
struct V_179 * V_180 )
{
T_2 V_570 = F_299 ( V_180 -> V_93 ) ;
T_2 V_93 = V_180 -> V_93 ;
F_389 ( V_570 , V_12 -> V_459 . V_564 ) ;
F_42 ( & V_180 -> V_59 ) ;
if ( V_180 -> V_474 )
F_306 ( V_12 , V_180 -> V_474 ) ;
F_21 ( V_180 ) ;
F_383 ( V_12 , V_93 , false ) ;
}
static int F_390 ( struct V_33 * V_168 , T_2 V_93 ,
bool V_92 )
{
enum V_90 V_91 = V_164 ;
T_2 V_94 = F_271 ( V_168 ) ;
return F_61 ( V_168 , V_91 , V_92 , V_93 ,
V_94 ) ;
}
static int F_391 ( struct V_33 * V_168 ,
struct V_114 * V_506 )
{
struct V_179 * V_180 ;
int V_15 ;
V_180 = F_294 ( V_168 -> V_12 , V_506 ) ;
if ( ! V_180 ) {
V_180 = F_385 ( V_168 -> V_12 , V_506 ) ;
if ( F_281 ( V_180 ) )
return F_282 ( V_180 ) ;
}
V_15 = F_392 ( V_168 , V_180 -> V_93 , true ) ;
if ( V_15 )
goto V_573;
V_15 = F_390 ( V_168 , V_180 -> V_93 , true ) ;
if ( V_15 )
goto V_574;
F_283 ( V_168 , V_180 ) ;
V_180 -> V_42 ++ ;
F_44 ( V_168 -> V_51 , L_52 , V_180 -> V_93 ) ;
return 0 ;
V_574:
F_392 ( V_168 , V_180 -> V_93 , false ) ;
V_573:
if ( ! V_180 -> V_42 )
F_388 ( V_168 -> V_12 , V_180 ) ;
return V_15 ;
}
static void V_572 ( struct V_33 * V_168 )
{
struct V_179 * V_180 = F_126 ( V_168 ) ;
F_44 ( V_168 -> V_51 , L_53 , V_180 -> V_93 ) ;
F_390 ( V_168 , V_180 -> V_93 , false ) ;
F_392 ( V_168 , V_180 -> V_93 , false ) ;
F_331 ( V_168 , V_180 -> V_93 ) ;
F_283 ( V_168 , NULL ) ;
if ( -- V_180 -> V_42 == 0 )
F_388 ( V_168 -> V_12 , V_180 ) ;
}
static int F_393 ( struct V_33 * V_168 ,
struct V_114 * V_506 )
{
struct V_179 * V_180 = F_126 ( V_168 ) ;
T_2 V_94 = F_271 ( V_168 ) ;
struct V_114 * V_51 = V_168 -> V_51 ;
int V_15 ;
if ( V_180 && ! F_125 ( ! V_180 -> V_181 ) )
V_180 -> V_181 ( V_168 ) ;
V_15 = F_391 ( V_168 , V_506 ) ;
if ( V_15 ) {
F_35 ( V_51 , L_62 ) ;
return V_15 ;
}
V_15 = F_63 ( V_168 , V_94 , true ) ;
if ( V_15 ) {
F_35 ( V_51 , L_63 ) ;
goto V_177;
}
V_168 -> V_526 = 1 ;
V_168 -> V_527 = 1 ;
V_168 -> V_528 = 1 ;
V_168 -> V_529 = 1 ;
return 0 ;
V_177:
V_572 ( V_168 ) ;
return V_15 ;
}
static void F_394 ( struct V_33 * V_168 )
{
T_2 V_94 = F_271 ( V_168 ) ;
F_63 ( V_168 , V_94 , false ) ;
V_572 ( V_168 ) ;
V_168 -> V_526 = 0 ;
V_168 -> V_527 = 0 ;
V_168 -> V_528 = 0 ;
V_168 -> V_529 = 0 ;
}
static bool
F_395 ( const struct V_33 * V_33 ,
const struct V_114 * V_506 )
{
struct V_33 * V_168 ;
F_30 (mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
struct V_114 * V_51 = F_396 ( V_168 ) ;
if ( V_51 && V_51 == V_506 )
return false ;
}
return true ;
}
static int F_397 ( struct V_114 * V_51 ,
unsigned long V_475 , void * V_511 ,
T_2 V_94 )
{
struct V_33 * V_33 = F_79 ( V_51 ) ;
struct V_554 * V_552 = V_511 ;
struct V_33 * V_168 ;
struct V_114 * V_555 ;
int V_15 = 0 ;
V_168 = F_122 ( V_33 , V_94 ) ;
switch ( V_475 ) {
case V_556 :
V_555 = V_552 -> V_555 ;
if ( ! F_311 ( V_555 ) )
return - V_81 ;
if ( ! V_552 -> V_557 )
break;
if ( ! F_395 ( V_33 ,
V_555 ) )
return - V_81 ;
break;
case V_559 :
V_555 = V_552 -> V_555 ;
if ( V_552 -> V_557 ) {
if ( F_125 ( ! V_168 ) )
return - V_81 ;
V_15 = F_393 ( V_168 ,
V_555 ) ;
} else {
if ( ! V_168 )
return 0 ;
F_394 ( V_168 ) ;
}
}
return V_15 ;
}
static int F_398 ( struct V_114 * V_494 ,
unsigned long V_475 , void * V_511 ,
T_2 V_94 )
{
struct V_114 * V_51 ;
struct V_471 * V_472 ;
int V_563 ;
F_289 (lag_dev, dev, iter) {
if ( F_133 ( V_51 ) ) {
V_563 = F_397 ( V_51 , V_475 , V_511 ,
V_94 ) ;
if ( V_563 )
return V_563 ;
}
}
return 0 ;
}
static int F_399 ( struct V_114 * V_507 ,
unsigned long V_475 , void * V_511 )
{
struct V_114 * V_508 = F_309 ( V_507 ) ;
T_2 V_94 = F_293 ( V_507 ) ;
if ( F_133 ( V_508 ) )
return F_397 ( V_508 , V_475 , V_511 ,
V_94 ) ;
else if ( F_310 ( V_508 ) )
return F_398 ( V_508 , V_475 , V_511 ,
V_94 ) ;
return 0 ;
}
static int F_400 ( struct V_509 * V_510 ,
unsigned long V_475 , void * V_511 )
{
struct V_114 * V_51 = F_401 ( V_511 ) ;
int V_15 = 0 ;
if ( V_475 == V_575 || V_475 == V_576 )
V_15 = F_319 ( V_51 ) ;
else if ( F_133 ( V_51 ) )
V_15 = F_375 ( V_51 , V_475 , V_511 ) ;
else if ( F_310 ( V_51 ) )
V_15 = F_376 ( V_51 , V_475 , V_511 ) ;
else if ( F_311 ( V_51 ) )
V_15 = F_380 ( V_51 , V_475 , V_511 ) ;
else if ( F_292 ( V_51 ) )
V_15 = F_399 ( V_51 , V_475 , V_511 ) ;
return F_313 ( V_15 ) ;
}
static int T_9 F_402 ( void )
{
int V_15 ;
F_403 ( & V_577 ) ;
F_404 ( & V_578 ) ;
F_405 ( & V_579 ) ;
V_15 = F_406 ( & V_580 ) ;
if ( V_15 )
goto V_581;
return 0 ;
V_581:
F_407 ( & V_579 ) ;
F_408 ( & V_578 ) ;
F_409 ( & V_577 ) ;
return V_15 ;
}
static void T_10 F_410 ( void )
{
F_411 ( & V_580 ) ;
F_407 ( & V_579 ) ;
F_408 ( & V_578 ) ;
F_409 ( & V_577 ) ;
}
