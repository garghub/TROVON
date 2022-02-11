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
char V_13 [ V_14 ] = { 0 } ;
int V_15 ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_17 ) , V_13 ) ;
if ( V_15 )
return V_15 ;
F_13 ( V_13 , V_12 -> V_18 ) ;
return 0 ;
}
static int F_14 ( struct V_12 * V_12 )
{
int V_19 ;
if ( ! F_15 ( V_12 -> V_16 , V_20 ) )
return - V_21 ;
V_12 -> V_22 . V_23 = F_16 ( V_12 -> V_16 ,
V_20 ) ;
V_12 -> V_22 . V_24 = F_17 ( V_12 -> V_22 . V_23 ,
sizeof( struct V_25 ) ,
V_26 ) ;
if ( ! V_12 -> V_22 . V_24 )
return - V_27 ;
for ( V_19 = 0 ; V_19 < V_12 -> V_22 . V_23 ; V_19 ++ )
F_18 ( & V_12 -> V_22 . V_24 [ V_19 ] . V_28 ) ;
return 0 ;
}
static void F_19 ( struct V_12 * V_12 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_12 -> V_22 . V_23 ; V_19 ++ ) {
struct V_25 * V_29 = & V_12 -> V_22 . V_24 [ V_19 ] ;
F_20 ( ! F_21 ( & V_29 -> V_28 ) ) ;
}
F_22 ( V_12 -> V_22 . V_24 ) ;
}
static struct V_25 *
F_23 ( struct V_30 * V_31 )
{
struct V_12 * V_12 = V_31 -> V_12 ;
struct V_25 * V_32 ;
char V_33 [ V_34 ] ;
T_1 V_10 = V_31 -> V_10 ;
int V_35 ;
int V_19 ;
int V_15 ;
V_35 = - 1 ;
for ( V_19 = 0 ; V_19 < V_12 -> V_22 . V_23 ; V_19 ++ ) {
if ( ! V_12 -> V_22 . V_24 [ V_19 ] . V_36 ) {
V_35 = V_19 ;
V_32 = & V_12 -> V_22 . V_24 [ V_19 ] ;
break;
}
}
if ( V_35 < 0 )
return NULL ;
F_24 ( V_33 , V_35 , V_10 , true ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_37 ) , V_33 ) ;
if ( V_15 )
return NULL ;
V_32 -> V_36 = true ;
V_32 -> V_38 = V_35 ;
V_32 -> V_39 = 1 ;
V_32 -> V_10 = V_10 ;
return V_32 ;
}
static void F_26 ( struct V_12 * V_12 ,
struct V_25 * V_32 )
{
T_1 V_10 = V_32 -> V_10 ;
char V_33 [ V_34 ] ;
int V_40 = V_32 -> V_38 ;
F_24 ( V_33 , V_40 , V_10 , false ) ;
F_25 ( V_12 -> V_16 , F_12 ( V_37 ) , V_33 ) ;
V_32 -> V_36 = false ;
}
static struct V_25 *
F_27 ( struct V_30 * V_31 )
{
struct V_12 * V_12 = V_31 -> V_12 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_12 -> V_22 . V_23 ; V_19 ++ ) {
struct V_25 * V_29 = & V_12 -> V_22 . V_24 [ V_19 ] ;
if ( V_29 -> V_36 && V_29 -> V_10 == V_31 -> V_10 )
return V_29 ;
}
return NULL ;
}
static struct V_25
* F_28 ( struct V_30 * V_31 )
{
struct V_25 * V_32 ;
V_32 = F_27 ( V_31 ) ;
if ( V_32 ) {
V_32 -> V_39 ++ ;
return V_32 ;
}
return F_23 ( V_31 ) ;
}
static int F_29 ( struct V_12 * V_12 ,
struct V_25 * V_32 )
{
F_30 ( ! V_32 -> V_39 ) ;
if ( -- V_32 -> V_39 == 0 )
F_26 ( V_12 , V_32 ) ;
return 0 ;
}
static bool F_31 ( struct V_30 * V_31 )
{
struct V_12 * V_12 = V_31 -> V_12 ;
struct V_41 * V_42 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_12 -> V_22 . V_23 ; V_19 ++ ) {
struct V_25 * V_29 = & V_12 -> V_22 . V_24 [ V_19 ] ;
F_32 (p, &curr->bound_ports_list, list)
if ( V_42 -> V_10 == V_31 -> V_10 &&
V_42 -> type == V_43 )
return true ;
}
return false ;
}
static int F_33 ( int V_44 )
{
return F_34 ( V_44 * 5 / 2 ) + 1 ;
}
static int F_35 ( struct V_30 * V_31 , T_2 V_44 )
{
struct V_12 * V_12 = V_31 -> V_12 ;
char V_45 [ V_46 ] ;
int V_15 ;
if ( F_31 ( V_31 ) ) {
F_36 ( V_45 , V_31 -> V_10 ,
F_33 ( V_44 ) ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_47 ) , V_45 ) ;
if ( V_15 ) {
F_37 ( V_31 -> V_48 , L_1 ) ;
return V_15 ;
}
}
return 0 ;
}
static struct V_41 *
F_38 ( struct V_30 * V_31 ,
struct V_25 * V_32 )
{
struct V_41 * V_42 ;
F_32 (p, &span_entry->bound_ports_list, list)
if ( V_31 -> V_10 == V_42 -> V_10 )
return V_42 ;
return NULL ;
}
static int
F_39 ( struct V_30 * V_31 ,
struct V_25 * V_32 ,
enum V_49 type )
{
struct V_41 * V_50 ;
struct V_12 * V_12 = V_31 -> V_12 ;
char V_51 [ V_52 ] ;
char V_45 [ V_46 ] ;
int V_40 = V_32 -> V_38 ;
int V_15 ;
if ( type == V_43 ) {
F_36 ( V_45 , V_31 -> V_10 ,
F_33 ( V_31 -> V_48 -> V_44 ) ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_47 ) , V_45 ) ;
if ( V_15 ) {
F_37 ( V_31 -> V_48 , L_2 ) ;
return V_15 ;
}
}
F_40 ( V_51 , V_31 -> V_10 ,
(enum V_53 ) type , true , V_40 ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_54 ) , V_51 ) ;
if ( V_15 )
goto V_55;
V_50 = F_41 ( sizeof( * V_50 ) , V_26 ) ;
if ( ! V_50 ) {
V_15 = - V_27 ;
goto V_56;
}
V_50 -> V_10 = V_31 -> V_10 ;
V_50 -> type = type ;
F_42 ( & V_50 -> V_57 , & V_32 -> V_28 ) ;
return 0 ;
V_55:
V_56:
if ( type == V_43 ) {
F_36 ( V_45 , V_31 -> V_10 , 0 ) ;
F_25 ( V_12 -> V_16 , F_12 ( V_47 ) , V_45 ) ;
}
return V_15 ;
}
static void
F_43 ( struct V_30 * V_31 ,
struct V_25 * V_32 ,
enum V_49 type )
{
struct V_41 * V_50 ;
struct V_12 * V_12 = V_31 -> V_12 ;
char V_51 [ V_52 ] ;
char V_45 [ V_46 ] ;
int V_40 = V_32 -> V_38 ;
V_50 = F_38 ( V_31 , V_32 ) ;
if ( ! V_50 )
return;
F_40 ( V_51 , V_31 -> V_10 ,
(enum V_53 ) type , false , V_40 ) ;
F_25 ( V_12 -> V_16 , F_12 ( V_54 ) , V_51 ) ;
if ( type == V_43 ) {
F_36 ( V_45 , V_31 -> V_10 , 0 ) ;
F_25 ( V_12 -> V_16 , F_12 ( V_47 ) , V_45 ) ;
}
F_29 ( V_12 , V_32 ) ;
F_44 ( & V_50 -> V_57 ) ;
F_22 ( V_50 ) ;
}
static int F_45 ( struct V_30 * V_58 ,
struct V_30 * V_59 ,
enum V_49 type )
{
struct V_12 * V_12 = V_58 -> V_12 ;
struct V_25 * V_32 ;
int V_15 ;
V_32 = F_28 ( V_59 ) ;
if ( ! V_32 )
return - V_60 ;
F_46 ( V_58 -> V_48 , L_3 ,
V_32 -> V_38 ) ;
V_15 = F_39 ( V_58 , V_32 , type ) ;
if ( V_15 )
goto V_61;
return 0 ;
V_61:
F_29 ( V_12 , V_32 ) ;
return V_15 ;
}
static void F_47 ( struct V_30 * V_58 ,
struct V_30 * V_59 ,
enum V_49 type )
{
struct V_25 * V_32 ;
V_32 = F_27 ( V_59 ) ;
if ( ! V_32 ) {
F_37 ( V_58 -> V_48 , L_4 ) ;
return;
}
F_46 ( V_58 -> V_48 , L_5 ,
V_32 -> V_38 ) ;
F_43 ( V_58 , V_32 , type ) ;
}
static int F_48 ( struct V_30 * V_30 ,
bool V_62 , T_3 V_63 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_64 [ V_65 ] ;
F_49 ( V_64 , V_30 -> V_10 , V_62 , V_63 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_66 ) , V_64 ) ;
}
static int F_50 ( struct V_30 * V_30 ,
bool V_67 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_68 [ V_69 ] ;
F_51 ( V_68 , V_30 -> V_10 ,
V_67 ? V_70 :
V_71 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_72 ) , V_68 ) ;
}
static int F_52 ( struct V_30 * V_30 ,
unsigned char * V_73 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_74 [ V_75 ] ;
F_53 ( V_74 , true , V_30 -> V_10 ) ;
F_54 ( V_74 , V_73 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_76 ) , V_74 ) ;
}
static int F_55 ( struct V_30 * V_30 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
unsigned char * V_73 = V_30 -> V_48 -> V_77 ;
F_56 ( V_73 , V_12 -> V_18 ) ;
V_73 [ V_78 - 1 ] += V_30 -> V_10 ;
return F_52 ( V_30 , V_73 ) ;
}
static int F_57 ( struct V_30 * V_30 , T_2 V_44 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_79 [ V_80 ] ;
int V_81 ;
int V_15 ;
V_44 += V_6 + V_82 ;
F_58 ( V_79 , V_30 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_83 ) , V_79 ) ;
if ( V_15 )
return V_15 ;
V_81 = F_59 ( V_79 ) ;
if ( V_44 > V_81 )
return - V_84 ;
F_58 ( V_79 , V_30 -> V_10 , V_44 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_83 ) , V_79 ) ;
}
static int F_60 ( struct V_12 * V_12 , T_1 V_10 ,
T_1 V_85 )
{
char V_86 [ V_87 ] ;
F_61 ( V_86 , V_85 , V_10 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_88 ) , V_86 ) ;
}
static int F_62 ( struct V_30 * V_30 , T_1 V_85 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
return F_60 ( V_12 , V_30 -> V_10 ,
V_85 ) ;
}
static int F_63 ( struct V_30 * V_30 ,
bool V_62 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_89 [ V_90 ] ;
F_64 ( V_89 , V_30 -> V_10 , V_62 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_91 ) , V_89 ) ;
}
int F_65 ( struct V_30 * V_30 ,
enum V_92 V_93 , bool V_94 , T_2 V_95 ,
T_2 V_96 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_97 [ V_98 ] ;
F_66 ( V_97 , V_30 -> V_10 , V_93 , V_94 ,
V_95 , V_96 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_99 ) , V_97 ) ;
}
int F_67 ( struct V_30 * V_30 ,
T_2 V_100 , T_2 V_101 ,
bool V_102 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char * V_103 ;
int V_15 ;
V_103 = F_68 ( V_104 , V_26 ) ;
if ( ! V_103 )
return - V_27 ;
F_69 ( V_103 , V_30 -> V_10 , V_100 ,
V_101 , V_102 ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_105 ) , V_103 ) ;
F_22 ( V_103 ) ;
return V_15 ;
}
static int F_70 ( struct V_30 * V_30 ,
T_2 V_96 , bool V_102 )
{
return F_67 ( V_30 , V_96 , V_96 ,
V_102 ) ;
}
static int
F_71 ( struct V_30 * V_30 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_106 [ V_107 ] ;
F_72 ( V_106 , V_30 -> V_10 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_108 ) , V_106 ) ;
}
static int F_73 ( struct V_12 * V_12 ,
T_1 V_10 , T_1 * V_109 ,
T_1 * V_110 , T_1 * V_111 )
{
char V_112 [ V_113 ] ;
int V_15 ;
F_74 ( V_112 , V_10 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_114 ) , V_112 ) ;
if ( V_15 )
return V_15 ;
* V_109 = F_75 ( V_112 , 0 ) ;
* V_110 = F_76 ( V_112 ) ;
* V_111 = F_77 ( V_112 , 0 ) ;
return 0 ;
}
static int F_78 ( struct V_12 * V_12 , T_1 V_10 ,
T_1 V_115 , T_1 V_116 , T_1 V_117 )
{
char V_112 [ V_113 ] ;
int V_19 ;
F_74 ( V_112 , V_10 ) ;
F_79 ( V_112 , V_116 ) ;
for ( V_19 = 0 ; V_19 < V_116 ; V_19 ++ ) {
F_80 ( V_112 , V_19 , V_115 ) ;
F_81 ( V_112 , V_19 , V_117 + V_19 ) ;
}
return F_25 ( V_12 -> V_16 , F_12 ( V_114 ) , V_112 ) ;
}
static int F_82 ( struct V_12 * V_12 , T_1 V_10 )
{
char V_112 [ V_113 ] ;
F_74 ( V_112 , V_10 ) ;
F_79 ( V_112 , 0 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_114 ) , V_112 ) ;
}
static int F_83 ( struct V_118 * V_48 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
int V_15 ;
V_15 = F_50 ( V_30 , true ) ;
if ( V_15 )
return V_15 ;
F_85 ( V_48 ) ;
return 0 ;
}
static int F_86 ( struct V_118 * V_48 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
F_87 ( V_48 ) ;
return F_50 ( V_30 , false ) ;
}
static T_4 F_88 ( struct V_1 * V_2 ,
struct V_118 * V_48 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
struct V_119 * V_120 ;
const struct V_3 V_4 = {
. V_10 = V_30 -> V_10 ,
. V_121 = false ,
} ;
T_5 V_122 ;
int V_15 ;
if ( F_89 ( V_12 -> V_16 , & V_4 ) )
return V_123 ;
if ( F_90 ( F_91 ( V_2 ) < V_6 ) ) {
struct V_1 * V_124 = V_2 ;
V_2 = F_92 ( V_2 , V_6 ) ;
if ( ! V_2 ) {
F_93 ( V_30 -> V_120 -> V_125 ) ;
F_94 ( V_124 ) ;
return V_126 ;
}
F_95 ( V_124 ) ;
}
if ( F_96 ( V_2 ) ) {
F_93 ( V_30 -> V_120 -> V_125 ) ;
return V_126 ;
}
F_1 ( V_2 , & V_4 ) ;
V_122 = V_2 -> V_122 - V_6 ;
V_15 = F_97 ( V_12 -> V_16 , V_2 , & V_4 ) ;
if ( ! V_15 ) {
V_120 = F_98 ( V_30 -> V_120 ) ;
F_99 ( & V_120 -> V_127 ) ;
V_120 -> V_128 ++ ;
V_120 -> V_129 += V_122 ;
F_100 ( & V_120 -> V_127 ) ;
} else {
F_93 ( V_30 -> V_120 -> V_125 ) ;
F_94 ( V_2 ) ;
}
return V_126 ;
}
static void F_101 ( struct V_118 * V_48 )
{
}
static int F_102 ( struct V_118 * V_48 , void * V_42 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
struct V_130 * V_73 = V_42 ;
int V_15 ;
if ( ! F_103 ( V_73 -> V_131 ) )
return - V_132 ;
V_15 = F_52 ( V_30 , V_73 -> V_131 ) ;
if ( V_15 )
return V_15 ;
memcpy ( V_48 -> V_77 , V_73 -> V_131 , V_48 -> V_133 ) ;
return 0 ;
}
static void F_104 ( char * V_134 , int V_135 , int V_44 ,
bool V_136 , bool V_137 , T_2 V_138 )
{
T_2 V_139 = 2 * F_34 ( V_44 ) ;
V_138 = V_137 ? F_105 ( V_44 , V_138 ) :
V_140 ;
if ( V_136 || V_137 )
F_106 ( V_134 , V_135 ,
V_139 + V_138 , V_139 ) ;
else
F_107 ( V_134 , V_135 , V_139 ) ;
}
int F_108 ( struct V_30 * V_30 , int V_44 ,
T_1 * V_141 , bool V_136 ,
struct V_142 * V_143 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
T_1 V_137 = ! ! V_143 ? V_143 -> V_137 : 0 ;
T_2 V_138 = ! ! V_143 ? V_143 -> V_138 : 0 ;
char V_134 [ V_144 ] ;
int V_19 , V_145 , V_15 ;
F_109 ( V_134 , V_30 -> V_10 , 0 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_146 ) , V_134 ) ;
if ( V_15 )
return V_15 ;
for ( V_19 = 0 ; V_19 < V_147 ; V_19 ++ ) {
bool V_148 = false ;
bool V_149 = false ;
for ( V_145 = 0 ; V_145 < V_147 ; V_145 ++ ) {
if ( V_141 [ V_145 ] == V_19 ) {
V_149 = V_137 & F_110 ( V_145 ) ;
V_148 = true ;
break;
}
}
if ( ! V_148 )
continue;
F_104 ( V_134 , V_19 , V_44 , V_136 , V_149 , V_138 ) ;
}
return F_25 ( V_12 -> V_16 , F_12 ( V_146 ) , V_134 ) ;
}
static int F_111 ( struct V_30 * V_30 ,
int V_44 , bool V_136 )
{
T_1 V_150 [ V_147 ] = { 0 } ;
bool V_151 = ! ! V_30 -> V_152 . V_153 ;
struct V_142 * V_143 ;
T_1 * V_141 ;
V_141 = V_151 ? V_30 -> V_152 . V_153 -> V_141 : V_150 ;
V_143 = V_151 ? V_30 -> V_152 . V_149 : NULL ;
return F_108 ( V_30 , V_44 , V_141 ,
V_136 , V_143 ) ;
}
static int F_112 ( struct V_118 * V_48 , int V_44 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
bool V_136 = F_113 ( V_30 ) ;
int V_15 ;
V_15 = F_111 ( V_30 , V_44 , V_136 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_35 ( V_30 , V_44 ) ;
if ( V_15 )
goto V_154;
V_15 = F_57 ( V_30 , V_44 ) ;
if ( V_15 )
goto V_155;
V_48 -> V_44 = V_44 ;
return 0 ;
V_155:
F_35 ( V_30 , V_48 -> V_44 ) ;
V_154:
F_111 ( V_30 , V_48 -> V_44 , V_136 ) ;
return V_15 ;
}
static int
F_114 ( const struct V_118 * V_48 ,
struct V_156 * V_157 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
struct V_119 * V_42 ;
T_5 V_158 , V_159 , V_128 , V_129 ;
T_3 V_125 = 0 ;
unsigned int V_160 ;
int V_19 ;
F_115 (i) {
V_42 = F_116 ( V_30 -> V_120 , V_19 ) ;
do {
V_160 = F_117 ( & V_42 -> V_127 ) ;
V_158 = V_42 -> V_158 ;
V_159 = V_42 -> V_159 ;
V_128 = V_42 -> V_128 ;
V_129 = V_42 -> V_129 ;
} while ( F_118 ( & V_42 -> V_127 , V_160 ) );
V_157 -> V_158 += V_158 ;
V_157 -> V_159 += V_159 ;
V_157 -> V_128 += V_128 ;
V_157 -> V_129 += V_129 ;
V_125 += V_42 -> V_125 ;
}
V_157 -> V_125 = V_125 ;
return 0 ;
}
static bool F_119 ( const struct V_118 * V_48 , int V_161 )
{
switch ( V_161 ) {
case V_162 :
return true ;
}
return false ;
}
static int F_120 ( int V_161 , const struct V_118 * V_48 ,
void * V_163 )
{
switch ( V_161 ) {
case V_162 :
return F_114 ( V_48 , V_163 ) ;
}
return - V_84 ;
}
static int F_121 ( struct V_118 * V_48 , int V_164 ,
int V_165 , char * V_166 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
F_122 ( V_166 , V_30 -> V_10 , V_164 , V_165 ) ;
return F_11 ( V_12 -> V_16 , F_12 ( V_167 ) , V_166 ) ;
}
static int F_123 ( struct V_118 * V_48 ,
struct V_156 * V_157 )
{
char V_166 [ V_168 ] ;
int V_15 ;
V_15 = F_121 ( V_48 , V_169 ,
0 , V_166 ) ;
if ( V_15 )
goto V_170;
V_157 -> V_128 =
F_124 ( V_166 ) ;
V_157 -> V_158 =
F_125 ( V_166 ) ;
V_157 -> V_129 =
F_126 ( V_166 ) ;
V_157 -> V_159 =
F_127 ( V_166 ) ;
V_157 -> V_171 =
F_128 ( V_166 ) ;
V_157 -> V_172 =
F_129 ( V_166 ) ;
V_157 -> V_173 =
F_130 ( V_166 ) ;
V_157 -> V_174 = (
F_131 ( V_166 ) +
F_132 ( V_166 ) +
F_133 ( V_166 ) ) ;
V_157 -> V_175 = ( V_157 -> V_172 +
V_157 -> V_173 + V_157 -> V_174 ) ;
V_170:
return V_15 ;
}
static void F_134 ( struct V_176 * V_177 )
{
struct V_30 * V_30 =
F_135 ( V_177 , struct V_30 ,
V_178 . V_179 . V_177 ) ;
if ( ! F_136 ( V_30 -> V_48 ) )
goto V_170;
F_123 ( V_30 -> V_48 ,
V_30 -> V_178 . V_180 ) ;
V_170:
F_137 ( & V_30 -> V_178 . V_179 ,
V_181 ) ;
}
static void
F_138 ( struct V_118 * V_48 ,
struct V_156 * V_157 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
memcpy ( V_157 , V_30 -> V_178 . V_180 , sizeof( * V_157 ) ) ;
}
int F_139 ( struct V_30 * V_30 , T_2 V_100 ,
T_2 V_101 , bool V_182 , bool V_183 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char * V_184 ;
int V_15 ;
V_184 = F_68 ( V_185 , V_26 ) ;
if ( ! V_184 )
return - V_27 ;
F_140 ( V_184 , V_30 -> V_10 , V_100 ,
V_101 , V_182 , V_183 ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_186 ) , V_184 ) ;
F_22 ( V_184 ) ;
return V_15 ;
}
static int F_141 ( struct V_30 * V_30 )
{
enum V_92 V_93 = V_187 ;
T_2 V_96 , V_188 ;
int V_15 ;
F_142 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_65 ( V_30 , V_93 , true , V_96 ,
V_96 ) ;
if ( V_15 ) {
V_188 = V_96 ;
goto V_189;
}
}
V_15 = F_63 ( V_30 , true ) ;
if ( V_15 ) {
V_188 = V_190 ;
goto V_189;
}
return 0 ;
V_189:
F_142 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_65 ( V_30 , V_93 , false , V_96 ,
V_96 ) ;
return V_15 ;
}
static int F_143 ( struct V_30 * V_30 )
{
enum V_92 V_93 = V_187 ;
T_2 V_96 ;
int V_15 ;
V_15 = F_63 ( V_30 , false ) ;
if ( V_15 )
return V_15 ;
F_142 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_65 ( V_30 , V_93 , false ,
V_96 , V_96 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static struct V_30 *
F_144 ( struct V_30 * V_30 , T_2 V_96 )
{
struct V_30 * V_191 ;
V_191 = F_41 ( sizeof( * V_191 ) , V_26 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_48 = V_30 -> V_48 ;
V_191 -> V_12 = V_30 -> V_12 ;
V_191 -> V_10 = V_30 -> V_10 ;
V_191 -> V_192 = V_193 ;
V_191 -> V_194 = V_30 -> V_194 ;
V_191 -> V_195 = V_30 -> V_195 ;
V_191 -> V_196 . V_96 = V_96 ;
F_145 ( & V_191 -> V_196 . V_57 , & V_30 -> V_197 ) ;
return V_191 ;
}
static void F_146 ( struct V_30 * V_191 )
{
F_44 ( & V_191 -> V_196 . V_57 ) ;
F_22 ( V_191 ) ;
}
static int F_147 ( struct V_118 * V_48 ,
T_6 T_7 V_198 , T_2 V_96 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
struct V_30 * V_191 ;
bool V_183 = V_96 == 1 ;
int V_15 ;
if ( ! V_96 )
return 0 ;
if ( F_148 ( V_30 , V_96 ) )
return 0 ;
V_191 = F_144 ( V_30 , V_96 ) ;
if ( ! V_191 )
return - V_27 ;
if ( F_149 ( & V_30 -> V_197 ) ) {
V_15 = F_141 ( V_30 ) ;
if ( V_15 )
goto V_199;
}
V_15 = F_139 ( V_191 , V_96 , V_96 , true , V_183 ) ;
if ( V_15 )
goto V_200;
return 0 ;
V_200:
if ( F_149 ( & V_30 -> V_197 ) )
F_143 ( V_30 ) ;
V_199:
F_146 ( V_191 ) ;
return V_15 ;
}
static int F_150 ( struct V_118 * V_48 ,
T_6 T_7 V_198 , T_2 V_96 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
struct V_30 * V_191 ;
struct V_201 * V_202 ;
if ( ! V_96 )
return 0 ;
V_191 = F_148 ( V_30 , V_96 ) ;
if ( F_30 ( ! V_191 ) )
return 0 ;
F_139 ( V_191 , V_96 , V_96 , false , false ) ;
V_202 = F_151 ( V_191 ) ;
if ( V_202 && ! F_30 ( ! V_202 -> V_203 ) )
V_202 -> V_203 ( V_191 ) ;
if ( F_149 ( & V_30 -> V_197 ) )
F_143 ( V_30 ) ;
F_146 ( V_191 ) ;
return 0 ;
}
static int F_152 ( struct V_118 * V_48 , char * V_204 ,
T_8 V_122 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
T_1 V_115 = V_30 -> V_205 . V_115 ;
T_1 V_116 = V_30 -> V_205 . V_116 ;
T_1 V_117 = V_30 -> V_205 . V_117 ;
int V_15 ;
if ( ! V_30 -> V_206 )
V_15 = snprintf ( V_204 , V_122 , L_6 , V_115 + 1 ) ;
else
V_15 = snprintf ( V_204 , V_122 , L_7 , V_115 + 1 ,
V_117 / V_116 ) ;
if ( V_15 >= V_122 )
return - V_84 ;
return 0 ;
}
static struct V_207 *
F_153 ( struct V_30 * V_31 ,
unsigned long V_208 ) {
struct V_207 * V_209 ;
F_32 (mall_tc_entry, &port->mall_tc_list, list)
if ( V_209 -> V_208 == V_208 )
return V_209 ;
return NULL ;
}
static int
F_154 ( struct V_30 * V_30 ,
struct V_210 * V_211 ,
const struct V_212 * V_213 ,
bool V_214 )
{
struct V_215 * V_215 = F_155 ( V_30 -> V_48 ) ;
enum V_49 V_216 ;
struct V_30 * V_217 ;
struct V_118 * V_218 ;
int V_219 ;
V_219 = F_156 ( V_213 ) ;
V_218 = F_157 ( V_215 , V_219 ) ;
if ( ! V_218 ) {
F_37 ( V_30 -> V_48 , L_8 ) ;
return - V_84 ;
}
if ( ! F_158 ( V_218 ) ) {
F_37 ( V_30 -> V_48 , L_9 ) ;
return - V_220 ;
}
V_217 = F_84 ( V_218 ) ;
V_211 -> V_221 = V_217 -> V_10 ;
V_211 -> V_214 = V_214 ;
V_216 = V_214 ? V_222 : V_43 ;
return F_45 ( V_30 , V_217 , V_216 ) ;
}
static void
F_159 ( struct V_30 * V_30 ,
struct V_210 * V_211 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
enum V_49 V_216 ;
struct V_30 * V_217 ;
V_217 = V_12 -> V_223 [ V_211 -> V_221 ] ;
V_216 = V_211 -> V_214 ?
V_222 : V_43 ;
F_47 ( V_30 , V_217 , V_216 ) ;
}
static int
F_160 ( struct V_30 * V_30 ,
struct V_224 * V_225 ,
const struct V_212 * V_213 ,
bool V_214 )
{
int V_15 ;
if ( ! V_30 -> V_226 )
return - V_220 ;
if ( F_161 ( V_30 -> V_226 -> V_227 ) ) {
F_37 ( V_30 -> V_48 , L_10 ) ;
return - V_228 ;
}
if ( F_162 ( V_213 ) > V_229 ) {
F_37 ( V_30 -> V_48 , L_11 ) ;
return - V_220 ;
}
F_163 ( V_30 -> V_226 -> V_227 ,
F_164 ( V_213 ) ) ;
V_30 -> V_226 -> V_230 = F_165 ( V_213 ) ;
V_30 -> V_226 -> V_231 = F_166 ( V_213 ) ;
V_30 -> V_226 -> V_63 = F_162 ( V_213 ) ;
V_15 = F_48 ( V_30 , true , F_162 ( V_213 ) ) ;
if ( V_15 )
goto V_232;
return 0 ;
V_232:
F_167 ( V_30 -> V_226 -> V_227 , NULL ) ;
return V_15 ;
}
static void
F_168 ( struct V_30 * V_30 )
{
if ( ! V_30 -> V_226 )
return;
F_48 ( V_30 , false , 1 ) ;
F_167 ( V_30 -> V_226 -> V_227 , NULL ) ;
}
static int F_169 ( struct V_30 * V_30 ,
T_6 V_233 ,
struct V_224 * V_225 ,
bool V_214 )
{
struct V_207 * V_209 ;
const struct V_212 * V_213 ;
F_170 ( V_234 ) ;
int V_15 ;
if ( ! F_171 ( V_225 -> V_235 ) ) {
F_37 ( V_30 -> V_48 , L_12 ) ;
return - V_220 ;
}
V_209 = F_41 ( sizeof( * V_209 ) , V_26 ) ;
if ( ! V_209 )
return - V_27 ;
V_209 -> V_208 = V_225 -> V_208 ;
F_172 ( V_225 -> V_235 , & V_234 ) ;
V_213 = F_173 ( & V_234 , struct V_212 , V_57 ) ;
if ( F_174 ( V_213 ) && V_233 == F_175 ( V_236 ) ) {
struct V_210 * V_211 ;
V_209 -> type = V_237 ;
V_211 = & V_209 -> V_211 ;
V_15 = F_154 ( V_30 ,
V_211 , V_213 , V_214 ) ;
} else if ( F_176 ( V_213 ) && V_233 == F_175 ( V_236 ) ) {
V_209 -> type = V_238 ;
V_15 = F_160 ( V_30 , V_225 ,
V_213 , V_214 ) ;
} else {
V_15 = - V_220 ;
}
if ( V_15 )
goto V_239;
F_42 ( & V_209 -> V_57 , & V_30 -> V_240 ) ;
return 0 ;
V_239:
F_22 ( V_209 ) ;
return V_15 ;
}
static void F_177 ( struct V_30 * V_30 ,
struct V_224 * V_225 )
{
struct V_207 * V_209 ;
V_209 = F_153 ( V_30 ,
V_225 -> V_208 ) ;
if ( ! V_209 ) {
F_46 ( V_30 -> V_48 , L_13 ) ;
return;
}
F_44 ( & V_209 -> V_57 ) ;
switch ( V_209 -> type ) {
case V_237 :
F_159 ( V_30 ,
& V_209 -> V_211 ) ;
break;
case V_238 :
F_168 ( V_30 ) ;
break;
default:
F_30 ( 1 ) ;
}
F_22 ( V_209 ) ;
}
static int F_178 ( struct V_118 * V_48 , T_3 V_241 ,
T_6 V_198 , struct V_242 * V_243 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
bool V_214 = F_179 ( V_241 ) == F_179 ( V_244 ) ;
switch ( V_243 -> type ) {
case V_245 :
switch ( V_243 -> V_246 -> V_247 ) {
case V_248 :
return F_169 ( V_30 ,
V_198 ,
V_243 -> V_246 ,
V_214 ) ;
case V_249 :
F_177 ( V_30 ,
V_243 -> V_246 ) ;
return 0 ;
default:
return - V_84 ;
}
case V_250 :
switch ( V_243 -> V_251 -> V_247 ) {
case V_252 :
return F_180 ( V_30 , V_214 ,
V_198 , V_243 -> V_251 ) ;
case V_253 :
F_181 ( V_30 , V_214 ,
V_243 -> V_251 ) ;
return 0 ;
default:
return - V_220 ;
}
}
return - V_220 ;
}
static void F_182 ( struct V_118 * V_48 ,
struct V_254 * V_255 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
F_183 ( V_255 -> V_256 , V_257 , sizeof( V_255 -> V_256 ) ) ;
F_183 ( V_255 -> V_258 , V_259 ,
sizeof( V_255 -> V_258 ) ) ;
snprintf ( V_255 -> V_260 , sizeof( V_255 -> V_260 ) ,
L_14 ,
V_12 -> V_261 -> V_262 . V_263 ,
V_12 -> V_261 -> V_262 . V_264 ,
V_12 -> V_261 -> V_262 . V_265 ) ;
F_183 ( V_255 -> V_261 , V_12 -> V_261 -> V_266 ,
sizeof( V_255 -> V_261 ) ) ;
}
static void F_184 ( struct V_118 * V_48 ,
struct V_267 * V_268 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
V_268 -> V_269 = V_30 -> V_270 . V_269 ;
V_268 -> V_271 = V_30 -> V_270 . V_271 ;
}
static int F_185 ( struct V_30 * V_30 ,
struct V_267 * V_268 )
{
char V_272 [ V_273 ] ;
F_186 ( V_272 , V_30 -> V_10 ) ;
F_187 ( V_272 , V_268 -> V_269 ) ;
F_188 ( V_272 , V_268 -> V_271 ) ;
return F_25 ( V_30 -> V_12 -> V_16 , F_12 ( V_274 ) ,
V_272 ) ;
}
static int F_189 ( struct V_118 * V_48 ,
struct V_267 * V_268 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
bool V_136 = V_268 -> V_271 || V_268 -> V_269 ;
int V_15 ;
if ( V_30 -> V_152 . V_149 && V_30 -> V_152 . V_149 -> V_137 ) {
F_37 ( V_48 , L_15 ) ;
return - V_84 ;
}
if ( V_268 -> V_275 ) {
F_37 ( V_48 , L_16 ) ;
return - V_84 ;
}
V_15 = F_111 ( V_30 , V_48 -> V_44 , V_136 ) ;
if ( V_15 ) {
F_37 ( V_48 , L_17 ) ;
return V_15 ;
}
V_15 = F_185 ( V_30 , V_268 ) ;
if ( V_15 ) {
F_37 ( V_48 , L_18 ) ;
goto V_276;
}
V_30 -> V_270 . V_269 = V_268 -> V_269 ;
V_30 -> V_270 . V_271 = V_268 -> V_271 ;
return 0 ;
V_276:
V_136 = F_113 ( V_30 ) ;
F_111 ( V_30 , V_48 -> V_44 , V_136 ) ;
return V_15 ;
}
static T_5 F_190 ( const char * V_166 )
{
T_5 V_277 = F_191 ( V_166 ) ;
return F_192 ( V_277 ) ;
}
static void F_193 ( T_1 * * V_42 , int V_165 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_278 ; V_19 ++ ) {
snprintf ( * V_42 , V_279 , L_19 ,
V_280 [ V_19 ] . V_281 , V_165 ) ;
* V_42 += V_279 ;
}
}
static void F_194 ( T_1 * * V_42 , int V_243 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_282 ; V_19 ++ ) {
snprintf ( * V_42 , V_279 , L_19 ,
V_283 [ V_19 ] . V_281 , V_243 ) ;
* V_42 += V_279 ;
}
}
static void F_195 ( struct V_118 * V_48 ,
T_3 V_284 , T_1 * V_285 )
{
T_1 * V_42 = V_285 ;
int V_19 ;
switch ( V_284 ) {
case V_286 :
for ( V_19 = 0 ; V_19 < V_287 ; V_19 ++ ) {
memcpy ( V_42 , V_288 [ V_19 ] . V_281 ,
V_279 ) ;
V_42 += V_279 ;
}
for ( V_19 = 0 ; V_19 < V_147 ; V_19 ++ )
F_193 ( & V_42 , V_19 ) ;
for ( V_19 = 0 ; V_19 < V_147 ; V_19 ++ )
F_194 ( & V_42 , V_19 ) ;
break;
}
}
static int F_196 ( struct V_118 * V_48 ,
enum V_289 V_290 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
char V_291 [ V_292 ] ;
bool V_293 ;
switch ( V_290 ) {
case V_294 :
V_293 = true ;
break;
case V_295 :
V_293 = false ;
break;
default:
return - V_220 ;
}
F_197 ( V_291 , V_30 -> V_10 , V_293 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_296 ) , V_291 ) ;
}
static int
F_198 ( struct V_288 * * V_297 ,
int * V_298 , enum V_299 V_164 )
{
switch ( V_164 ) {
case V_169 :
* V_297 = V_288 ;
* V_298 = V_287 ;
break;
case V_300 :
* V_297 = V_280 ;
* V_298 = V_278 ;
break;
case V_301 :
* V_297 = V_283 ;
* V_298 = V_282 ;
break;
default:
F_30 ( 1 ) ;
return - V_220 ;
}
return 0 ;
}
static void F_199 ( struct V_118 * V_48 ,
enum V_299 V_164 , int V_165 ,
T_5 * V_285 , int V_302 )
{
struct V_288 * V_178 ;
char V_166 [ V_168 ] ;
int V_19 , V_122 ;
int V_15 ;
V_15 = F_198 ( & V_178 , & V_122 , V_164 ) ;
if ( V_15 )
return;
F_121 ( V_48 , V_164 , V_165 , V_166 ) ;
for ( V_19 = 0 ; V_19 < V_122 ; V_19 ++ )
V_285 [ V_302 + V_19 ] = V_178 [ V_19 ] . F_200 ( V_166 ) ;
}
static void F_201 ( struct V_118 * V_48 ,
struct V_303 * V_157 , T_5 * V_285 )
{
int V_19 , V_302 = 0 ;
F_199 ( V_48 , V_169 , 0 ,
V_285 , V_302 ) ;
V_302 = V_287 ;
for ( V_19 = 0 ; V_19 < V_147 ; V_19 ++ ) {
F_199 ( V_48 , V_300 , V_19 ,
V_285 , V_302 ) ;
V_302 += V_278 ;
}
for ( V_19 = 0 ; V_19 < V_147 ; V_19 ++ ) {
F_199 ( V_48 , V_301 , V_19 ,
V_285 , V_302 ) ;
V_302 += V_282 ;
}
}
static int F_202 ( struct V_118 * V_48 , int V_304 )
{
switch ( V_304 ) {
case V_286 :
return V_305 ;
default:
return - V_220 ;
}
}
static void
F_203 ( T_3 V_306 ,
struct V_307 * V_308 )
{
if ( V_306 & ( V_309 |
V_310 |
V_311 |
V_312 |
V_313 |
V_314 ) )
F_204 ( V_308 , V_315 , V_316 ) ;
if ( V_306 & ( V_317 |
V_318 |
V_319 |
V_320 |
V_321 ) )
F_204 ( V_308 , V_315 , V_322 ) ;
}
static void F_205 ( T_3 V_306 , unsigned long * V_323 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_324 ; V_19 ++ ) {
if ( V_306 & V_325 [ V_19 ] . V_326 )
F_206 ( V_325 [ V_19 ] . V_327 ,
V_323 ) ;
}
}
static void F_207 ( bool V_328 , T_3 V_306 ,
struct V_307 * V_308 )
{
T_3 V_329 = V_330 ;
T_1 V_331 = V_332 ;
int V_19 ;
if ( ! V_328 )
goto V_170;
for ( V_19 = 0 ; V_19 < V_324 ; V_19 ++ ) {
if ( V_306 & V_325 [ V_19 ] . V_326 ) {
V_329 = V_325 [ V_19 ] . V_329 ;
V_331 = V_333 ;
break;
}
}
V_170:
V_308 -> V_334 . V_329 = V_329 ;
V_308 -> V_334 . V_331 = V_331 ;
}
static T_1 F_208 ( T_3 V_306 )
{
if ( V_306 & ( V_310 |
V_312 |
V_313 |
V_314 ) )
return V_335 ;
if ( V_306 & ( V_309 |
V_311 |
V_336 ) )
return V_337 ;
if ( V_306 & ( V_317 |
V_318 |
V_319 |
V_320 ) )
return V_338 ;
return V_339 ;
}
static T_3
F_209 ( const struct V_307 * V_308 )
{
T_3 V_340 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_324 ; V_19 ++ ) {
if ( F_210 ( V_325 [ V_19 ] . V_327 ,
V_308 -> V_341 . V_342 ) )
V_340 |= V_325 [ V_19 ] . V_326 ;
}
return V_340 ;
}
static T_3 F_211 ( T_3 V_329 )
{
T_3 V_340 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_324 ; V_19 ++ ) {
if ( V_329 == V_325 [ V_19 ] . V_329 )
V_340 |= V_325 [ V_19 ] . V_326 ;
}
return V_340 ;
}
static T_3 F_212 ( T_3 V_343 )
{
T_3 V_340 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_324 ; V_19 ++ ) {
if ( V_325 [ V_19 ] . V_329 <= V_343 )
V_340 |= V_325 [ V_19 ] . V_326 ;
}
return V_340 ;
}
static void F_213 ( T_3 V_344 ,
struct V_307 * V_308 )
{
F_204 ( V_308 , V_315 , V_345 ) ;
F_204 ( V_308 , V_315 , V_346 ) ;
F_204 ( V_308 , V_315 , V_347 ) ;
F_203 ( V_344 , V_308 ) ;
F_205 ( V_344 , V_308 -> V_341 . V_315 ) ;
}
static void F_214 ( T_3 V_348 , bool V_275 ,
struct V_307 * V_308 )
{
if ( ! V_275 )
return;
F_204 ( V_308 , V_342 , V_346 ) ;
F_205 ( V_348 , V_308 -> V_341 . V_342 ) ;
}
static void
F_215 ( T_3 V_349 , T_1 V_350 ,
struct V_307 * V_308 )
{
if ( V_350 != V_351 || ! V_349 )
return;
F_204 ( V_308 , V_352 , V_346 ) ;
F_205 ( V_349 , V_308 -> V_341 . V_352 ) ;
}
static int F_216 ( struct V_118 * V_48 ,
struct V_307 * V_308 )
{
T_3 V_344 , V_348 , V_353 , V_349 ;
struct V_30 * V_30 = F_84 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
char V_354 [ V_355 ] ;
T_1 V_350 ;
bool V_275 ;
int V_15 ;
V_275 = V_30 -> V_270 . V_275 ;
F_217 ( V_354 , V_30 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_356 ) , V_354 ) ;
if ( V_15 )
return V_15 ;
F_218 ( V_354 , & V_344 , & V_348 ,
& V_353 ) ;
F_213 ( V_344 , V_308 ) ;
F_214 ( V_348 , V_275 , V_308 ) ;
V_349 = F_219 ( V_354 ) ;
V_350 = F_220 ( V_354 ) ;
F_215 ( V_349 , V_350 , V_308 ) ;
V_308 -> V_334 . V_275 = V_275 ? V_357 : V_358 ;
V_308 -> V_334 . V_31 = F_208 ( V_353 ) ;
F_207 ( F_136 ( V_48 ) , V_353 ,
V_308 ) ;
return 0 ;
}
static int
F_221 ( struct V_118 * V_48 ,
const struct V_307 * V_308 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
char V_354 [ V_355 ] ;
T_3 V_344 , V_359 ;
bool V_275 ;
int V_15 ;
F_217 ( V_354 , V_30 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_356 ) , V_354 ) ;
if ( V_15 )
return V_15 ;
F_218 ( V_354 , & V_344 , NULL , NULL ) ;
V_275 = V_308 -> V_334 . V_275 == V_357 ;
V_359 = V_275 ?
F_209 ( V_308 ) :
F_211 ( V_308 -> V_334 . V_329 ) ;
V_359 = V_359 & V_344 ;
if ( ! V_359 ) {
F_37 ( V_48 , L_20 ) ;
return - V_84 ;
}
F_217 ( V_354 , V_30 -> V_10 ,
V_359 ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_356 ) , V_354 ) ;
if ( V_15 )
return V_15 ;
if ( ! F_222 ( V_48 ) )
return 0 ;
V_30 -> V_270 . V_275 = V_275 ;
F_50 ( V_30 , false ) ;
F_50 ( V_30 , true ) ;
return 0 ;
}
static int
F_223 ( struct V_30 * V_30 , T_1 V_116 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
T_3 V_343 = V_360 * V_116 ;
char V_354 [ V_355 ] ;
T_3 V_348 ;
V_348 = F_212 ( V_343 ) ;
F_217 ( V_354 , V_30 -> V_10 ,
V_348 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_356 ) , V_354 ) ;
}
int F_224 ( struct V_30 * V_30 ,
enum V_361 V_362 , T_1 V_35 , T_1 V_363 ,
bool V_364 , T_1 V_365 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_366 [ V_367 ] ;
F_225 ( V_366 , V_30 -> V_10 , V_362 , V_35 ,
V_363 ) ;
F_226 ( V_366 , true ) ;
F_227 ( V_366 , V_364 ) ;
F_228 ( V_366 , V_365 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_368 ) , V_366 ) ;
}
int F_229 ( struct V_30 * V_30 ,
enum V_361 V_362 , T_1 V_35 ,
T_1 V_363 , T_3 V_369 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_366 [ V_367 ] ;
F_225 ( V_366 , V_30 -> V_10 , V_362 , V_35 ,
V_363 ) ;
F_230 ( V_366 , true ) ;
F_231 ( V_366 , V_369 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_368 ) , V_366 ) ;
}
int F_232 ( struct V_30 * V_30 ,
T_1 V_370 , T_1 V_371 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_372 [ V_373 ] ;
F_233 ( V_372 , V_30 -> V_10 , V_370 ,
V_371 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_374 ) , V_372 ) ;
}
static int F_234 ( struct V_30 * V_30 )
{
int V_15 , V_19 ;
V_15 = F_224 ( V_30 ,
V_375 , 0 , 0 , false ,
0 ) ;
if ( V_15 )
return V_15 ;
for ( V_19 = 0 ; V_19 < V_147 ; V_19 ++ ) {
V_15 = F_224 ( V_30 ,
V_376 , V_19 ,
0 , false , 0 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_19 = 0 ; V_19 < V_147 ; V_19 ++ ) {
V_15 = F_224 ( V_30 ,
V_377 , V_19 , V_19 ,
false , 0 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = F_229 ( V_30 ,
V_378 , 0 , 0 ,
V_379 ) ;
if ( V_15 )
return V_15 ;
for ( V_19 = 0 ; V_19 < V_147 ; V_19 ++ ) {
V_15 = F_229 ( V_30 ,
V_376 ,
V_19 , 0 ,
V_379 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_19 = 0 ; V_19 < V_147 ; V_19 ++ ) {
V_15 = F_229 ( V_30 ,
V_377 ,
V_19 , V_19 ,
V_379 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_19 = 0 ; V_19 < V_147 ; V_19 ++ ) {
V_15 = F_232 ( V_30 , V_19 , 0 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_235 ( struct V_30 * V_30 )
{
V_30 -> V_380 = 1 ;
return F_147 ( V_30 -> V_48 , 0 , 1 ) ;
}
static int F_236 ( struct V_30 * V_30 )
{
return F_150 ( V_30 -> V_48 , 0 , 1 ) ;
}
static int F_237 ( struct V_12 * V_12 , T_1 V_10 ,
bool V_206 , T_1 V_115 , T_1 V_116 , T_1 V_117 )
{
struct V_30 * V_30 ;
struct V_118 * V_48 ;
T_8 V_381 ;
int V_15 ;
V_48 = F_238 ( sizeof( struct V_30 ) ) ;
if ( ! V_48 )
return - V_27 ;
F_239 ( V_48 , V_12 -> V_261 -> V_48 ) ;
V_30 = F_84 ( V_48 ) ;
V_30 -> V_48 = V_48 ;
V_30 -> V_12 = V_12 ;
V_30 -> V_10 = V_10 ;
V_30 -> V_206 = V_206 ;
V_30 -> V_205 . V_115 = V_115 ;
V_30 -> V_205 . V_116 = V_116 ;
V_30 -> V_205 . V_117 = V_117 ;
V_30 -> V_270 . V_275 = 1 ;
V_381 = F_240 ( V_190 , V_382 ) ;
V_30 -> V_383 = F_41 ( V_381 , V_26 ) ;
if ( ! V_30 -> V_383 ) {
V_15 = - V_27 ;
goto V_384;
}
V_30 -> V_385 = F_41 ( V_381 , V_26 ) ;
if ( ! V_30 -> V_385 ) {
V_15 = - V_27 ;
goto V_386;
}
F_18 ( & V_30 -> V_197 ) ;
F_18 ( & V_30 -> V_240 ) ;
V_30 -> V_120 =
F_241 ( struct V_119 ) ;
if ( ! V_30 -> V_120 ) {
V_15 = - V_27 ;
goto V_387;
}
V_30 -> V_226 = F_41 ( sizeof( * V_30 -> V_226 ) ,
V_26 ) ;
if ( ! V_30 -> V_226 ) {
V_15 = - V_27 ;
goto V_388;
}
V_30 -> V_178 . V_180 =
F_41 ( sizeof( * V_30 -> V_178 . V_180 ) , V_26 ) ;
if ( ! V_30 -> V_178 . V_180 ) {
V_15 = - V_27 ;
goto V_389;
}
F_242 ( & V_30 -> V_178 . V_179 ,
& F_134 ) ;
V_48 -> V_390 = & V_391 ;
V_48 -> V_392 = & V_393 ;
V_15 = F_62 ( V_30 , 0 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_21 ,
V_30 -> V_10 ) ;
goto V_394;
}
V_15 = F_55 ( V_30 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_22 ,
V_30 -> V_10 ) ;
goto V_395;
}
F_244 ( V_48 ) ;
V_48 -> V_396 |= V_397 | V_398 | V_399 |
V_400 | V_401 ;
V_48 -> V_402 |= V_401 ;
V_48 -> V_403 = 0 ;
V_48 -> V_81 = V_404 ;
V_48 -> V_405 = V_6 ;
V_15 = F_71 ( V_30 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_23 ,
V_30 -> V_10 ) ;
goto V_406;
}
V_15 = F_223 ( V_30 , V_116 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_24 ,
V_30 -> V_10 ) ;
goto V_407;
}
V_15 = F_57 ( V_30 , V_408 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_25 ,
V_30 -> V_10 ) ;
goto V_155;
}
V_15 = F_50 ( V_30 , false ) ;
if ( V_15 )
goto V_409;
V_15 = F_245 ( V_30 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_26 ,
V_30 -> V_10 ) ;
goto V_410;
}
V_15 = F_234 ( V_30 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_27 ,
V_30 -> V_10 ) ;
goto V_411;
}
V_15 = F_246 ( V_30 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_28 ,
V_30 -> V_10 ) ;
goto V_412;
}
V_15 = F_235 ( V_30 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_29 ,
V_30 -> V_10 ) ;
goto V_413;
}
F_247 ( V_30 ) ;
V_12 -> V_223 [ V_10 ] = V_30 ;
V_15 = F_248 ( V_48 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_30 ,
V_30 -> V_10 ) ;
goto V_414;
}
F_249 ( V_12 -> V_16 , V_30 -> V_10 ,
V_30 , V_48 , V_30 -> V_206 ,
V_115 ) ;
F_137 ( & V_30 -> V_178 . V_179 , 0 ) ;
return 0 ;
V_414:
V_12 -> V_223 [ V_10 ] = NULL ;
F_250 ( V_30 ) ;
F_236 ( V_30 ) ;
V_413:
F_251 ( V_30 ) ;
V_412:
V_411:
V_410:
V_409:
V_155:
V_407:
V_406:
V_395:
F_62 ( V_30 , V_415 ) ;
V_394:
F_22 ( V_30 -> V_178 . V_180 ) ;
V_389:
F_22 ( V_30 -> V_226 ) ;
V_388:
F_252 ( V_30 -> V_120 ) ;
V_387:
F_22 ( V_30 -> V_385 ) ;
V_386:
F_22 ( V_30 -> V_383 ) ;
V_384:
F_253 ( V_48 ) ;
return V_15 ;
}
static int F_254 ( struct V_12 * V_12 , T_1 V_10 ,
bool V_206 , T_1 V_115 , T_1 V_116 , T_1 V_117 )
{
int V_15 ;
V_15 = F_255 ( V_12 -> V_16 , V_10 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_31 ,
V_10 ) ;
return V_15 ;
}
V_15 = F_237 ( V_12 , V_10 , V_206 ,
V_115 , V_116 , V_117 ) ;
if ( V_15 )
goto V_416;
return 0 ;
V_416:
F_256 ( V_12 -> V_16 , V_10 ) ;
return V_15 ;
}
static void F_257 ( struct V_12 * V_12 , T_1 V_10 )
{
struct V_30 * V_30 = V_12 -> V_223 [ V_10 ] ;
F_258 ( & V_30 -> V_178 . V_179 ) ;
F_259 ( V_12 -> V_16 , V_10 , V_12 ) ;
F_260 ( V_30 -> V_48 ) ;
V_12 -> V_223 [ V_10 ] = NULL ;
F_250 ( V_30 ) ;
F_236 ( V_30 ) ;
F_251 ( V_30 ) ;
F_62 ( V_30 , V_415 ) ;
F_82 ( V_12 , V_30 -> V_10 ) ;
F_22 ( V_30 -> V_178 . V_180 ) ;
F_22 ( V_30 -> V_226 ) ;
F_252 ( V_30 -> V_120 ) ;
F_22 ( V_30 -> V_385 ) ;
F_22 ( V_30 -> V_383 ) ;
F_20 ( ! F_21 ( & V_30 -> V_197 ) ) ;
F_253 ( V_30 -> V_48 ) ;
}
static void F_261 ( struct V_12 * V_12 , T_1 V_10 )
{
F_257 ( V_12 , V_10 ) ;
F_256 ( V_12 -> V_16 , V_10 ) ;
}
static bool F_262 ( struct V_12 * V_12 , T_1 V_10 )
{
return V_12 -> V_223 [ V_10 ] != NULL ;
}
static void F_263 ( struct V_12 * V_12 )
{
int V_19 ;
for ( V_19 = 1 ; V_19 < V_417 ; V_19 ++ )
if ( F_262 ( V_12 , V_19 ) )
F_261 ( V_12 , V_19 ) ;
F_22 ( V_12 -> V_223 ) ;
}
static int F_264 ( struct V_12 * V_12 )
{
T_1 V_115 , V_116 , V_117 ;
T_8 V_418 ;
int V_19 ;
int V_15 ;
V_418 = sizeof( struct V_30 * ) * V_417 ;
V_12 -> V_223 = F_41 ( V_418 , V_26 ) ;
if ( ! V_12 -> V_223 )
return - V_27 ;
for ( V_19 = 1 ; V_19 < V_417 ; V_19 ++ ) {
V_15 = F_73 ( V_12 , V_19 , & V_115 ,
& V_116 , & V_117 ) ;
if ( V_15 )
goto V_419;
if ( ! V_116 )
continue;
V_12 -> V_420 [ V_19 ] = V_115 ;
V_15 = F_254 ( V_12 , V_19 , false ,
V_115 , V_116 , V_117 ) ;
if ( V_15 )
goto V_416;
}
return 0 ;
V_416:
V_419:
for ( V_19 -- ; V_19 >= 1 ; V_19 -- )
if ( F_262 ( V_12 , V_19 ) )
F_261 ( V_12 , V_19 ) ;
F_22 ( V_12 -> V_223 ) ;
return V_15 ;
}
static T_1 F_265 ( T_1 V_10 )
{
T_1 V_421 = ( V_10 - 1 ) % V_422 ;
return V_10 - V_421 ;
}
static int F_266 ( struct V_12 * V_12 , T_1 V_423 ,
T_1 V_115 , unsigned int V_424 )
{
T_1 V_116 = V_425 / V_424 ;
int V_15 , V_19 ;
for ( V_19 = 0 ; V_19 < V_424 ; V_19 ++ ) {
V_15 = F_78 ( V_12 , V_423 + V_19 , V_115 ,
V_116 , V_19 * V_116 ) ;
if ( V_15 )
goto V_426;
}
for ( V_19 = 0 ; V_19 < V_424 ; V_19 ++ ) {
V_15 = F_60 ( V_12 , V_423 + V_19 , 0 ) ;
if ( V_15 )
goto V_394;
}
for ( V_19 = 0 ; V_19 < V_424 ; V_19 ++ ) {
V_15 = F_254 ( V_12 , V_423 + V_19 , true ,
V_115 , V_116 , V_19 * V_116 ) ;
if ( V_15 )
goto V_416;
}
return 0 ;
V_416:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- )
if ( F_262 ( V_12 , V_423 + V_19 ) )
F_261 ( V_12 , V_423 + V_19 ) ;
V_19 = V_424 ;
V_394:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- )
F_60 ( V_12 , V_423 + V_19 ,
V_415 ) ;
V_19 = V_424 ;
V_426:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- )
F_82 ( V_12 , V_423 + V_19 ) ;
return V_15 ;
}
static void F_267 ( struct V_12 * V_12 ,
T_1 V_423 , unsigned int V_424 )
{
T_1 V_10 , V_115 , V_116 = V_425 ;
int V_19 ;
V_424 = V_424 / 2 ;
for ( V_19 = 0 ; V_19 < V_424 ; V_19 ++ ) {
V_10 = V_423 + V_19 * 2 ;
V_115 = V_12 -> V_420 [ V_10 ] ;
F_78 ( V_12 , V_10 , V_115 , V_116 ,
0 ) ;
}
for ( V_19 = 0 ; V_19 < V_424 ; V_19 ++ )
F_60 ( V_12 , V_423 + V_19 * 2 , 0 ) ;
for ( V_19 = 0 ; V_19 < V_424 ; V_19 ++ ) {
V_10 = V_423 + V_19 * 2 ;
V_115 = V_12 -> V_420 [ V_10 ] ;
F_254 ( V_12 , V_10 , false , V_115 ,
V_116 , 0 ) ;
}
}
static int F_268 ( struct V_427 * V_427 , T_1 V_10 ,
unsigned int V_424 )
{
struct V_12 * V_12 = F_269 ( V_427 ) ;
struct V_30 * V_30 ;
T_1 V_115 , V_428 , V_423 ;
int V_19 ;
int V_15 ;
V_30 = V_12 -> V_223 [ V_10 ] ;
if ( ! V_30 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_32 ,
V_10 ) ;
return - V_84 ;
}
V_115 = V_30 -> V_205 . V_115 ;
V_428 = V_30 -> V_205 . V_116 ;
if ( V_424 != 2 && V_424 != 4 ) {
F_37 ( V_30 -> V_48 , L_33 ) ;
return - V_84 ;
}
if ( V_428 != V_425 ) {
F_37 ( V_30 -> V_48 , L_34 ) ;
return - V_84 ;
}
if ( V_424 == 2 ) {
V_423 = V_10 ;
if ( V_12 -> V_223 [ V_423 + 1 ] ) {
F_37 ( V_30 -> V_48 , L_35 ) ;
return - V_84 ;
}
} else {
V_423 = F_265 ( V_10 ) ;
if ( V_12 -> V_223 [ V_423 + 1 ] ||
V_12 -> V_223 [ V_423 + 3 ] ) {
F_37 ( V_30 -> V_48 , L_35 ) ;
return - V_84 ;
}
}
for ( V_19 = 0 ; V_19 < V_424 ; V_19 ++ )
if ( F_262 ( V_12 , V_423 + V_19 ) )
F_261 ( V_12 , V_423 + V_19 ) ;
V_15 = F_266 ( V_12 , V_423 , V_115 , V_424 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_36 ) ;
goto V_429;
}
return 0 ;
V_429:
F_267 ( V_12 , V_423 , V_424 ) ;
return V_15 ;
}
static int F_270 ( struct V_427 * V_427 , T_1 V_10 )
{
struct V_12 * V_12 = F_269 ( V_427 ) ;
struct V_30 * V_30 ;
T_1 V_428 , V_423 ;
unsigned int V_424 ;
int V_19 ;
V_30 = V_12 -> V_223 [ V_10 ] ;
if ( ! V_30 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_32 ,
V_10 ) ;
return - V_84 ;
}
if ( ! V_30 -> V_206 ) {
F_37 ( V_30 -> V_48 , L_37 ) ;
return - V_84 ;
}
V_428 = V_30 -> V_205 . V_116 ;
V_424 = V_428 == 1 ? 4 : 2 ;
V_423 = F_265 ( V_10 ) ;
if ( V_424 == 2 && V_10 >= V_423 + 2 )
V_423 = V_423 + 2 ;
for ( V_19 = 0 ; V_19 < V_424 ; V_19 ++ )
if ( F_262 ( V_12 , V_423 + V_19 ) )
F_261 ( V_12 , V_423 + V_19 ) ;
F_267 ( V_12 , V_423 , V_424 ) ;
return 0 ;
}
static void F_271 ( const struct V_430 * V_431 ,
char * V_432 , void * V_433 )
{
struct V_12 * V_12 = V_433 ;
struct V_30 * V_30 ;
enum V_434 V_435 ;
T_1 V_10 ;
V_10 = F_272 ( V_432 ) ;
V_30 = V_12 -> V_223 [ V_10 ] ;
if ( ! V_30 )
return;
V_435 = F_273 ( V_432 ) ;
if ( V_435 == V_436 ) {
F_274 ( V_30 -> V_48 , L_38 ) ;
F_275 ( V_30 -> V_48 ) ;
} else {
F_274 ( V_30 -> V_48 , L_39 ) ;
F_244 ( V_30 -> V_48 ) ;
}
}
static void F_276 ( struct V_1 * V_2 ,
T_1 V_10 , void * V_433 )
{
struct V_12 * V_12 = V_433 ;
struct V_30 * V_30 = V_12 -> V_223 [ V_10 ] ;
struct V_119 * V_120 ;
if ( F_90 ( ! V_30 ) ) {
F_277 ( V_12 -> V_261 -> V_48 , L_40 ,
V_10 ) ;
return;
}
V_2 -> V_48 = V_30 -> V_48 ;
V_120 = F_98 ( V_30 -> V_120 ) ;
F_99 ( & V_120 -> V_127 ) ;
V_120 -> V_158 ++ ;
V_120 -> V_159 += V_2 -> V_122 ;
F_100 ( & V_120 -> V_127 ) ;
V_2 -> V_233 = F_278 ( V_2 , V_2 -> V_48 ) ;
F_279 ( V_2 ) ;
}
static void F_280 ( struct V_1 * V_2 , T_1 V_10 ,
void * V_433 )
{
V_2 -> V_437 = 1 ;
return F_276 ( V_2 , V_10 , V_433 ) ;
}
static void F_281 ( struct V_1 * V_2 , T_1 V_10 ,
void * V_433 )
{
struct V_12 * V_12 = V_433 ;
struct V_30 * V_30 = V_12 -> V_223 [ V_10 ] ;
struct V_227 * V_227 ;
T_3 V_438 ;
if ( F_90 ( ! V_30 ) ) {
F_277 ( V_12 -> V_261 -> V_48 , L_41 ,
V_10 ) ;
goto V_170;
}
if ( F_90 ( ! V_30 -> V_226 ) ) {
F_277 ( V_12 -> V_261 -> V_48 , L_42 ,
V_10 ) ;
goto V_170;
}
V_438 = V_30 -> V_226 -> V_230 ?
V_30 -> V_226 -> V_231 : V_2 -> V_122 ;
F_282 () ;
V_227 = F_283 ( V_30 -> V_226 -> V_227 ) ;
if ( ! V_227 )
goto V_439;
F_284 ( V_227 , V_2 , V_438 ,
V_30 -> V_48 -> V_219 , 0 ,
V_30 -> V_226 -> V_63 ) ;
V_439:
F_285 () ;
V_170:
F_286 ( V_2 ) ;
}
static int F_287 ( struct V_427 * V_427 )
{
char V_440 [ V_441 ] ;
enum V_442 V_443 ;
int V_444 ;
bool V_445 ;
T_1 V_446 ;
T_3 V_63 ;
int V_19 , V_15 ;
if ( ! F_15 ( V_427 , V_447 ) )
return - V_21 ;
V_444 = F_16 ( V_427 , V_447 ) ;
V_443 = V_448 ;
for ( V_19 = 0 ; V_19 < V_444 ; V_19 ++ ) {
V_445 = false ;
switch ( V_19 ) {
case V_449 :
case V_450 :
case V_451 :
case V_452 :
V_63 = 128 ;
V_446 = 7 ;
break;
case V_453 :
V_63 = 16 * 1024 ;
V_446 = 10 ;
break;
case V_454 :
case V_455 :
case V_456 :
case V_457 :
case V_458 :
case V_459 :
V_63 = 1024 ;
V_446 = 7 ;
break;
case V_460 :
V_445 = true ;
V_63 = 4 * 1024 ;
V_446 = 4 ;
break;
default:
continue;
}
F_288 ( V_440 , V_19 , V_443 , V_445 , V_63 ,
V_446 ) ;
V_15 = F_25 ( V_427 , F_12 ( V_461 ) , V_440 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_289 ( struct V_427 * V_427 )
{
char V_462 [ V_463 ] ;
enum V_464 V_19 ;
int V_444 ;
int V_465 ;
T_1 V_466 , V_243 ;
T_2 V_467 ;
int V_15 ;
if ( ! F_15 ( V_427 , V_468 ) )
return - V_21 ;
V_465 = F_16 ( V_427 , V_468 ) ;
V_444 = F_16 ( V_427 , V_447 ) ;
for ( V_19 = 0 ; V_19 < V_465 ; V_19 ++ ) {
V_467 = V_19 ;
switch ( V_19 ) {
case V_449 :
case V_450 :
case V_451 :
case V_452 :
V_466 = 5 ;
V_243 = 5 ;
break;
case V_454 :
case V_456 :
V_466 = 4 ;
V_243 = 4 ;
break;
case V_453 :
case V_460 :
V_466 = 3 ;
V_243 = 3 ;
break;
case V_455 :
V_466 = 2 ;
V_243 = 2 ;
break;
case V_457 :
case V_458 :
case V_459 :
V_466 = 1 ;
V_243 = 1 ;
break;
case V_469 :
V_466 = V_470 ;
V_243 = V_471 ;
V_467 = V_472 ;
break;
default:
continue;
}
if ( V_444 <= V_467 &&
V_467 != V_472 )
return - V_21 ;
F_290 ( V_462 , V_19 , V_467 , V_466 , V_243 ) ;
V_15 = F_25 ( V_427 , F_12 ( V_473 ) , V_462 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_291 ( struct V_12 * V_12 )
{
int V_19 ;
int V_15 ;
V_15 = F_287 ( V_12 -> V_16 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_289 ( V_12 -> V_16 ) ;
if ( V_15 )
return V_15 ;
for ( V_19 = 0 ; V_19 < F_292 ( V_474 ) ; V_19 ++ ) {
V_15 = F_293 ( V_12 -> V_16 ,
& V_474 [ V_19 ] ,
V_12 ) ;
if ( V_15 )
goto V_475;
}
return 0 ;
V_475:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- ) {
F_294 ( V_12 -> V_16 ,
& V_474 [ V_19 ] ,
V_12 ) ;
}
return V_15 ;
}
static void F_295 ( struct V_12 * V_12 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_292 ( V_474 ) ; V_19 ++ ) {
F_294 ( V_12 -> V_16 ,
& V_474 [ V_19 ] ,
V_12 ) ;
}
}
static int F_296 ( struct V_427 * V_427 ,
enum V_476 type ,
enum V_477 V_478 )
{
enum V_479 V_480 ;
enum V_481 V_482 ;
char V_483 [ V_484 ] ;
if ( V_478 == V_485 )
V_480 = V_486 ;
else
V_480 = V_487 ;
switch ( type ) {
case V_488 :
V_482 = V_489 ;
break;
case V_490 :
V_482 = V_491 ;
break;
default:
V_482 = V_492 ;
}
F_297 ( V_483 , type , V_478 , V_480 ,
V_482 ) ;
return F_25 ( V_427 , F_12 ( V_493 ) , V_483 ) ;
}
static int F_298 ( struct V_12 * V_12 )
{
int type , V_15 ;
for ( type = 0 ; type < V_494 ; type ++ ) {
if ( type == V_495 )
continue;
V_15 = F_296 ( V_12 -> V_16 , type ,
V_485 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_296 ( V_12 -> V_16 , type ,
V_496 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_299 ( struct V_12 * V_12 )
{
char V_497 [ V_498 ] ;
int V_15 ;
F_300 ( V_497 , V_499 |
V_500 |
V_501 |
V_502 |
V_503 |
V_504 |
V_505 |
V_506 |
V_507 ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_508 ) , V_497 ) ;
if ( V_15 )
return V_15 ;
if ( ! F_15 ( V_12 -> V_16 , V_509 ) ||
! F_15 ( V_12 -> V_16 , V_510 ) )
return - V_21 ;
V_12 -> V_511 = F_17 ( F_16 ( V_12 -> V_16 , V_509 ) ,
sizeof( struct V_512 ) ,
V_26 ) ;
if ( ! V_12 -> V_511 )
return - V_27 ;
return 0 ;
}
static void F_301 ( struct V_12 * V_12 )
{
F_22 ( V_12 -> V_511 ) ;
}
static int F_302 ( struct V_427 * V_427 )
{
char V_462 [ V_463 ] ;
F_290 ( V_462 , V_513 ,
V_472 ,
V_470 ,
V_471 ) ;
return F_25 ( V_427 , F_12 ( V_473 ) , V_462 ) ;
}
static int F_303 ( struct V_427 * V_427 ,
const struct V_514 * V_514 )
{
struct V_12 * V_12 = F_269 ( V_427 ) ;
int V_15 ;
V_12 -> V_16 = V_427 ;
V_12 -> V_261 = V_514 ;
F_18 ( & V_12 -> V_515 ) ;
F_18 ( & V_12 -> V_516 . V_57 ) ;
F_18 ( & V_12 -> V_517 . V_57 ) ;
V_15 = F_10 ( V_12 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_43 ) ;
return V_15 ;
}
V_15 = F_291 ( V_12 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_44 ) ;
return V_15 ;
}
V_15 = F_298 ( V_12 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_45 ) ;
goto V_518;
}
V_15 = F_304 ( V_12 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_46 ) ;
goto V_519;
}
V_15 = F_299 ( V_12 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_47 ) ;
goto V_520;
}
V_15 = F_305 ( V_12 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_48 ) ;
goto V_521;
}
V_15 = F_306 ( V_12 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_49 ) ;
goto V_522;
}
V_15 = F_14 ( V_12 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_50 ) ;
goto V_523;
}
V_15 = F_307 ( V_12 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_51 ) ;
goto V_524;
}
V_15 = F_264 ( V_12 ) ;
if ( V_15 ) {
F_243 ( V_12 -> V_261 -> V_48 , L_52 ) ;
goto V_525;
}
return 0 ;
V_525:
F_308 ( V_12 ) ;
V_524:
F_19 ( V_12 ) ;
V_523:
F_309 ( V_12 ) ;
V_522:
F_310 ( V_12 ) ;
V_521:
F_301 ( V_12 ) ;
V_520:
F_311 ( V_12 ) ;
V_519:
V_518:
F_295 ( V_12 ) ;
return V_15 ;
}
static void F_312 ( struct V_427 * V_427 )
{
struct V_12 * V_12 = F_269 ( V_427 ) ;
F_263 ( V_12 ) ;
F_308 ( V_12 ) ;
F_19 ( V_12 ) ;
F_309 ( V_12 ) ;
F_310 ( V_12 ) ;
F_301 ( V_12 ) ;
F_311 ( V_12 ) ;
F_295 ( V_12 ) ;
F_30 ( ! F_21 ( & V_12 -> V_516 . V_57 ) ) ;
F_30 ( ! F_21 ( & V_12 -> V_515 ) ) ;
}
bool F_158 ( const struct V_118 * V_48 )
{
return V_48 -> V_390 == & V_391 ;
}
static int F_313 ( struct V_118 * V_526 , void * V_285 )
{
struct V_30 * * V_31 = V_285 ;
int V_527 = 0 ;
if ( F_158 ( V_526 ) ) {
* V_31 = F_84 ( V_526 ) ;
V_527 = 1 ;
}
return V_527 ;
}
static struct V_30 * F_314 ( struct V_118 * V_48 )
{
struct V_30 * V_31 ;
if ( F_158 ( V_48 ) )
return F_84 ( V_48 ) ;
V_31 = NULL ;
F_315 ( V_48 , F_313 , & V_31 ) ;
return V_31 ;
}
static struct V_12 * F_316 ( struct V_118 * V_48 )
{
struct V_30 * V_30 ;
V_30 = F_314 ( V_48 ) ;
return V_30 ? V_30 -> V_12 : NULL ;
}
static struct V_30 * F_317 ( struct V_118 * V_48 )
{
struct V_30 * V_31 ;
if ( F_158 ( V_48 ) )
return F_84 ( V_48 ) ;
V_31 = NULL ;
F_318 ( V_48 , F_313 , & V_31 ) ;
return V_31 ;
}
struct V_30 * F_319 ( struct V_118 * V_48 )
{
struct V_30 * V_30 ;
F_282 () ;
V_30 = F_317 ( V_48 ) ;
if ( V_30 )
F_320 ( V_30 -> V_48 ) ;
F_285 () ;
return V_30 ;
}
void F_321 ( struct V_30 * V_30 )
{
F_322 ( V_30 -> V_48 ) ;
}
static bool F_323 ( struct V_528 * V_529 ,
unsigned long V_530 )
{
switch ( V_530 ) {
case V_531 :
if ( ! V_529 )
return true ;
V_529 -> V_39 ++ ;
return false ;
case V_532 :
if ( V_529 && -- V_529 -> V_39 == 0 )
return true ;
return false ;
}
return false ;
}
static int F_324 ( struct V_12 * V_12 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_16 ( V_12 -> V_16 , V_533 ) ; V_19 ++ )
if ( ! V_12 -> V_534 [ V_19 ] )
return V_19 ;
return V_535 ;
}
static void F_325 ( struct V_30 * V_191 ,
bool * V_536 , T_2 * V_537 )
{
T_1 V_10 = V_191 -> V_10 ;
* V_536 = V_191 -> V_194 ;
* V_537 = * V_536 ? V_191 -> V_195 : V_10 ;
}
static int F_326 ( struct V_30 * V_191 ,
struct V_118 * V_538 , T_2 V_539 ,
bool V_540 )
{
struct V_12 * V_12 = V_191 -> V_12 ;
bool V_194 = V_191 -> V_194 ;
char V_541 [ V_542 ] ;
T_2 V_543 ;
F_327 ( V_541 , V_540 , V_544 , V_539 ,
V_538 -> V_44 , V_538 -> V_77 ) ;
F_325 ( V_191 , & V_194 , & V_543 ) ;
F_328 ( V_541 , V_194 , V_543 ,
F_329 ( V_191 ) ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_545 ) , V_541 ) ;
}
static struct V_201 *
F_330 ( T_2 V_95 , struct V_118 * V_538 )
{
struct V_201 * V_202 ;
V_202 = F_41 ( sizeof( * V_202 ) , V_26 ) ;
if ( ! V_202 )
return NULL ;
V_202 -> V_203 = V_546 ;
V_202 -> V_39 = 0 ;
V_202 -> V_48 = V_538 ;
V_202 -> V_95 = V_95 ;
return V_202 ;
}
static struct V_528 *
F_331 ( T_2 V_539 , struct V_118 * V_538 , struct V_201 * V_202 )
{
struct V_528 * V_529 ;
V_529 = F_41 ( sizeof( * V_529 ) , V_26 ) ;
if ( ! V_529 )
return NULL ;
F_18 ( & V_529 -> V_547 ) ;
F_18 ( & V_529 -> V_548 ) ;
F_56 ( V_529 -> V_73 , V_538 -> V_77 ) ;
V_529 -> V_44 = V_538 -> V_44 ;
V_529 -> V_39 = 1 ;
V_529 -> V_48 = V_538 ;
V_529 -> V_539 = V_539 ;
V_529 -> V_202 = V_202 ;
return V_529 ;
}
static struct V_528 *
F_332 ( struct V_30 * V_191 ,
struct V_118 * V_538 )
{
struct V_12 * V_12 = V_191 -> V_12 ;
struct V_201 * V_202 ;
struct V_528 * V_529 ;
T_2 V_95 , V_539 ;
int V_15 ;
V_539 = F_324 ( V_12 ) ;
if ( V_539 == V_535 )
return F_333 ( - V_549 ) ;
V_15 = F_326 ( V_191 , V_538 , V_539 , true ) ;
if ( V_15 )
return F_333 ( V_15 ) ;
V_95 = F_334 ( V_539 ) ;
V_15 = F_335 ( V_12 , V_538 -> V_77 , V_95 , true ) ;
if ( V_15 )
goto V_550;
V_202 = F_330 ( V_95 , V_538 ) ;
if ( ! V_202 ) {
V_15 = - V_27 ;
goto V_551;
}
V_529 = F_331 ( V_539 , V_538 , V_202 ) ;
if ( ! V_529 ) {
V_15 = - V_27 ;
goto V_552;
}
V_202 -> V_529 = V_529 ;
V_12 -> V_534 [ V_539 ] = V_529 ;
return V_529 ;
V_552:
F_22 ( V_202 ) ;
V_551:
F_335 ( V_12 , V_538 -> V_77 , V_95 , false ) ;
V_550:
F_326 ( V_191 , V_538 , V_539 , false ) ;
return F_333 ( V_15 ) ;
}
static void F_336 ( struct V_30 * V_191 ,
struct V_528 * V_529 )
{
struct V_12 * V_12 = V_191 -> V_12 ;
struct V_118 * V_538 = V_529 -> V_48 ;
struct V_201 * V_202 = V_529 -> V_202 ;
T_2 V_95 = V_202 -> V_95 ;
T_2 V_539 = V_529 -> V_539 ;
F_337 ( V_12 , V_529 ) ;
V_12 -> V_534 [ V_539 ] = NULL ;
V_202 -> V_529 = NULL ;
F_22 ( V_529 ) ;
F_22 ( V_202 ) ;
F_335 ( V_12 , V_538 -> V_77 , V_95 , false ) ;
F_326 ( V_191 , V_538 , V_539 , false ) ;
}
static int F_338 ( struct V_30 * V_191 ,
struct V_118 * V_538 )
{
struct V_12 * V_12 = V_191 -> V_12 ;
struct V_528 * V_529 ;
V_529 = F_339 ( V_12 , V_538 ) ;
if ( ! V_529 ) {
V_529 = F_332 ( V_191 , V_538 ) ;
if ( F_340 ( V_529 ) )
return F_341 ( V_529 ) ;
}
F_342 ( V_191 , V_529 -> V_202 ) ;
V_529 -> V_202 -> V_39 ++ ;
F_46 ( V_191 -> V_48 , L_53 , V_529 -> V_202 -> V_95 ) ;
return 0 ;
}
static void V_546 ( struct V_30 * V_191 )
{
struct V_201 * V_202 = F_151 ( V_191 ) ;
F_46 ( V_191 -> V_48 , L_54 , V_202 -> V_95 ) ;
F_342 ( V_191 , NULL ) ;
if ( -- V_202 -> V_39 == 0 )
F_336 ( V_191 , V_202 -> V_529 ) ;
}
static int F_343 ( struct V_118 * V_538 ,
struct V_118 * V_553 ,
unsigned long V_530 , T_2 V_96 )
{
struct V_30 * V_30 = F_84 ( V_553 ) ;
struct V_30 * V_191 ;
V_191 = F_148 ( V_30 , V_96 ) ;
if ( F_30 ( ! V_191 ) )
return - V_84 ;
switch ( V_530 ) {
case V_531 :
return F_338 ( V_191 , V_538 ) ;
case V_532 :
V_546 ( V_191 ) ;
break;
}
return 0 ;
}
static int F_344 ( struct V_118 * V_553 ,
unsigned long V_530 )
{
if ( F_345 ( V_553 ) || F_346 ( V_553 ) )
return 0 ;
return F_343 ( V_553 , V_553 , V_530 , 1 ) ;
}
static int F_347 ( struct V_118 * V_538 ,
struct V_118 * V_554 ,
unsigned long V_530 , T_2 V_96 )
{
struct V_118 * V_553 ;
struct V_555 * V_556 ;
int V_15 ;
F_348 (lag_dev, port_dev, iter) {
if ( F_158 ( V_553 ) ) {
V_15 = F_343 ( V_538 , V_553 ,
V_530 , V_96 ) ;
if ( V_15 )
return V_15 ;
}
}
return 0 ;
}
static int F_349 ( struct V_118 * V_554 ,
unsigned long V_530 )
{
if ( F_345 ( V_554 ) )
return 0 ;
return F_347 ( V_554 , V_554 , V_530 , 1 ) ;
}
static struct V_201 * F_350 ( struct V_12 * V_12 ,
struct V_118 * V_538 )
{
T_2 V_95 ;
if ( F_351 ( V_538 ) )
V_95 = F_352 ( V_538 ) ;
else if ( V_12 -> V_557 . V_48 == V_538 )
V_95 = 1 ;
else
return F_353 ( V_12 , V_538 ) ;
return F_354 ( V_12 , V_95 ) ;
}
static enum V_479 F_355 ( T_2 V_95 )
{
return F_356 ( V_95 ) ? V_486 :
V_487 ;
}
static T_2 F_357 ( T_2 V_95 )
{
return F_356 ( V_95 ) ? F_358 ( V_95 ) : V_95 ;
}
static int F_359 ( struct V_12 * V_12 , T_2 V_95 ,
bool V_558 )
{
enum V_479 V_480 ;
char * V_559 ;
T_2 V_35 ;
int V_15 ;
V_559 = F_68 ( V_560 , V_26 ) ;
if ( ! V_559 )
return - V_27 ;
V_480 = F_355 ( V_95 ) ;
V_35 = F_357 ( V_95 ) ;
F_360 ( V_559 , V_492 , V_35 , V_480 ,
1 , V_561 , V_558 ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_562 ) , V_559 ) ;
F_22 ( V_559 ) ;
return V_15 ;
}
static enum V_563 F_361 ( T_2 V_95 )
{
if ( F_356 ( V_95 ) )
return V_564 ;
else
return V_565 ;
}
static int F_362 ( struct V_12 * V_12 ,
struct V_118 * V_538 ,
T_2 V_95 , T_2 V_539 ,
bool V_540 )
{
enum V_563 V_566 ;
char V_541 [ V_542 ] ;
V_566 = F_361 ( V_95 ) ;
F_327 ( V_541 , V_540 , V_566 , V_539 , V_538 -> V_44 ,
V_538 -> V_77 ) ;
F_363 ( V_541 , V_566 , V_95 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_545 ) , V_541 ) ;
}
static int F_364 ( struct V_12 * V_12 ,
struct V_118 * V_538 ,
struct V_201 * V_202 )
{
struct V_528 * V_529 ;
T_2 V_539 ;
int V_15 ;
V_539 = F_324 ( V_12 ) ;
if ( V_539 == V_535 )
return - V_549 ;
V_15 = F_359 ( V_12 , V_202 -> V_95 , true ) ;
if ( V_15 )
return V_15 ;
V_15 = F_362 ( V_12 , V_538 , V_202 -> V_95 , V_539 , true ) ;
if ( V_15 )
goto V_567;
V_15 = F_335 ( V_12 , V_538 -> V_77 , V_202 -> V_95 , true ) ;
if ( V_15 )
goto V_550;
V_529 = F_331 ( V_539 , V_538 , V_202 ) ;
if ( ! V_529 ) {
V_15 = - V_27 ;
goto V_552;
}
V_202 -> V_529 = V_529 ;
V_12 -> V_534 [ V_539 ] = V_529 ;
F_46 ( V_538 , L_55 , V_539 ) ;
return 0 ;
V_552:
F_335 ( V_12 , V_538 -> V_77 , V_202 -> V_95 , false ) ;
V_550:
F_362 ( V_12 , V_538 , V_202 -> V_95 , V_539 , false ) ;
V_567:
F_359 ( V_12 , V_202 -> V_95 , false ) ;
return V_15 ;
}
void F_365 ( struct V_12 * V_12 ,
struct V_528 * V_529 )
{
struct V_118 * V_538 = V_529 -> V_48 ;
struct V_201 * V_202 = V_529 -> V_202 ;
T_2 V_539 = V_529 -> V_539 ;
F_337 ( V_12 , V_529 ) ;
V_12 -> V_534 [ V_539 ] = NULL ;
V_202 -> V_529 = NULL ;
F_22 ( V_529 ) ;
F_335 ( V_12 , V_538 -> V_77 , V_202 -> V_95 , false ) ;
F_362 ( V_12 , V_538 , V_202 -> V_95 , V_539 , false ) ;
F_359 ( V_12 , V_202 -> V_95 , false ) ;
F_46 ( V_538 , L_56 , V_539 ) ;
}
static int F_366 ( struct V_118 * V_538 ,
struct V_118 * V_568 ,
unsigned long V_530 )
{
struct V_12 * V_12 = F_316 ( V_538 ) ;
struct V_201 * V_202 ;
V_202 = F_350 ( V_12 , V_538 ) ;
if ( F_30 ( ! V_202 ) )
return - V_84 ;
switch ( V_530 ) {
case V_531 :
return F_364 ( V_12 , V_538 , V_202 ) ;
case V_532 :
F_365 ( V_12 , V_202 -> V_529 ) ;
break;
}
return 0 ;
}
static int F_367 ( struct V_118 * V_569 ,
unsigned long V_530 )
{
struct V_118 * V_570 = F_368 ( V_569 ) ;
struct V_12 * V_12 = F_316 ( V_569 ) ;
T_2 V_96 = F_352 ( V_569 ) ;
if ( F_158 ( V_570 ) )
return F_343 ( V_569 , V_570 , V_530 ,
V_96 ) ;
else if ( F_369 ( V_570 ) )
return F_347 ( V_569 , V_570 , V_530 ,
V_96 ) ;
else if ( F_370 ( V_570 ) &&
V_12 -> V_557 . V_48 == V_570 )
return F_366 ( V_569 , V_570 ,
V_530 ) ;
return 0 ;
}
static int F_371 ( struct V_571 * V_572 ,
unsigned long V_530 , void * V_573 )
{
struct V_574 * V_575 = (struct V_574 * ) V_573 ;
struct V_118 * V_48 = V_575 -> V_576 -> V_48 ;
struct V_12 * V_12 ;
struct V_528 * V_529 ;
int V_15 = 0 ;
V_12 = F_316 ( V_48 ) ;
if ( ! V_12 )
goto V_170;
V_529 = F_339 ( V_12 , V_48 ) ;
if ( ! F_323 ( V_529 , V_530 ) )
goto V_170;
if ( F_158 ( V_48 ) )
V_15 = F_344 ( V_48 , V_530 ) ;
else if ( F_369 ( V_48 ) )
V_15 = F_349 ( V_48 , V_530 ) ;
else if ( F_370 ( V_48 ) )
V_15 = F_366 ( V_48 , V_48 , V_530 ) ;
else if ( F_351 ( V_48 ) )
V_15 = F_367 ( V_48 , V_530 ) ;
V_170:
return F_372 ( V_15 ) ;
}
static int F_373 ( struct V_12 * V_12 , T_2 V_539 ,
const char * V_577 , int V_44 )
{
char V_541 [ V_542 ] ;
int V_15 ;
F_374 ( V_541 , V_539 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_545 ) , V_541 ) ;
if ( V_15 )
return V_15 ;
F_375 ( V_541 , V_44 ) ;
F_376 ( V_541 , V_577 ) ;
F_377 ( V_541 , V_578 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_545 ) , V_541 ) ;
}
static int F_378 ( struct V_118 * V_48 )
{
struct V_12 * V_12 ;
struct V_528 * V_529 ;
int V_15 ;
V_12 = F_316 ( V_48 ) ;
if ( ! V_12 )
return 0 ;
V_529 = F_339 ( V_12 , V_48 ) ;
if ( ! V_529 )
return 0 ;
V_15 = F_335 ( V_12 , V_529 -> V_73 , V_529 -> V_202 -> V_95 , false ) ;
if ( V_15 )
return V_15 ;
V_15 = F_373 ( V_12 , V_529 -> V_539 , V_48 -> V_77 , V_48 -> V_44 ) ;
if ( V_15 )
goto V_579;
V_15 = F_335 ( V_12 , V_48 -> V_77 , V_529 -> V_202 -> V_95 , true ) ;
if ( V_15 )
goto V_550;
F_56 ( V_529 -> V_73 , V_48 -> V_77 ) ;
V_529 -> V_44 = V_48 -> V_44 ;
F_46 ( V_48 , L_57 , V_529 -> V_539 ) ;
return 0 ;
V_550:
F_373 ( V_12 , V_529 -> V_539 , V_529 -> V_73 , V_529 -> V_44 ) ;
V_579:
F_335 ( V_12 , V_529 -> V_73 , V_529 -> V_202 -> V_95 , true ) ;
return V_15 ;
}
static bool F_379 ( struct V_30 * V_580 ,
T_2 V_95 )
{
if ( F_356 ( V_95 ) )
return F_380 ( V_580 , V_95 ) ;
else
return F_210 ( V_95 , V_580 -> V_383 ) ;
}
static bool F_381 ( struct V_30 * V_30 ,
T_2 V_95 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
T_1 V_10 = V_30 -> V_10 ;
T_2 V_195 = V_30 -> V_195 ;
T_5 V_581 ;
int V_19 , V_424 = 0 ;
if ( ! V_30 -> V_194 )
return true ;
V_581 = F_16 ( V_12 -> V_16 ,
V_510 ) ;
for ( V_19 = 0 ; V_19 < V_581 ; V_19 ++ ) {
struct V_30 * V_580 ;
V_580 = F_382 ( V_12 , V_195 , V_19 ) ;
if ( ! V_580 || V_580 -> V_10 == V_10 )
continue;
if ( F_379 ( V_580 , V_95 ) )
V_424 ++ ;
}
return ! V_424 ;
}
static int
F_383 ( const struct V_30 * V_30 ,
T_2 V_95 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_582 [ V_583 ] ;
F_384 ( V_582 , V_584 ) ;
F_385 ( V_582 , V_95 ) ;
F_386 ( V_582 ,
V_30 -> V_10 ) ;
F_46 ( V_30 -> V_48 , L_58 ,
V_30 -> V_10 , V_95 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_585 ) , V_582 ) ;
}
static int
F_387 ( const struct V_30 * V_30 ,
T_2 V_95 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_582 [ V_583 ] ;
F_384 ( V_582 , V_586 ) ;
F_385 ( V_582 , V_95 ) ;
F_388 ( V_582 , V_30 -> V_195 ) ;
F_46 ( V_30 -> V_48 , L_59 ,
V_30 -> V_195 , V_95 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_585 ) , V_582 ) ;
}
int F_389 ( struct V_30 * V_30 , T_2 V_95 )
{
if ( ! F_381 ( V_30 , V_95 ) )
return 0 ;
if ( V_30 -> V_194 )
return F_387 ( V_30 ,
V_95 ) ;
else
return F_383 ( V_30 , V_95 ) ;
}
static void F_390 ( struct V_12 * V_12 )
{
struct V_201 * V_202 , * V_587 ;
F_391 (f, tmp, &mlxsw_sp->fids, list)
if ( -- V_202 -> V_39 == 0 )
F_392 ( V_12 , V_202 ) ;
else
F_20 ( 1 ) ;
}
static bool F_393 ( struct V_12 * V_12 ,
struct V_118 * V_568 )
{
return ! V_12 -> V_557 . V_48 ||
V_12 -> V_557 . V_48 == V_568 ;
}
static void F_394 ( struct V_12 * V_12 ,
struct V_118 * V_568 )
{
V_12 -> V_557 . V_48 = V_568 ;
V_12 -> V_557 . V_39 ++ ;
}
static void F_395 ( struct V_12 * V_12 )
{
if ( -- V_12 -> V_557 . V_39 == 0 ) {
V_12 -> V_557 . V_48 = NULL ;
F_390 ( V_12 ) ;
}
}
static int F_396 ( struct V_30 * V_30 ,
struct V_118 * V_568 )
{
struct V_118 * V_48 = V_30 -> V_48 ;
int V_15 ;
V_15 = F_150 ( V_48 , 0 , 1 ) ;
if ( V_15 )
return V_15 ;
F_394 ( V_30 -> V_12 , V_568 ) ;
V_30 -> V_588 = 1 ;
V_30 -> V_589 = 1 ;
V_30 -> V_590 = 1 ;
V_30 -> V_591 = 1 ;
V_30 -> V_592 = 0 ;
V_30 -> V_593 = 1 ;
V_30 -> V_594 = 1 ;
return 0 ;
}
static void F_397 ( struct V_30 * V_30 )
{
struct V_118 * V_48 = V_30 -> V_48 ;
F_398 ( V_30 , 1 ) ;
F_395 ( V_30 -> V_12 ) ;
V_30 -> V_588 = 0 ;
V_30 -> V_589 = 0 ;
V_30 -> V_590 = 0 ;
V_30 -> V_591 = 0 ;
V_30 -> V_592 = 0 ;
V_30 -> V_594 = 0 ;
F_147 ( V_48 , 0 , 1 ) ;
}
static int F_399 ( struct V_12 * V_12 , T_2 V_195 )
{
char V_595 [ V_596 ] ;
F_400 ( V_595 , V_195 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_597 ) , V_595 ) ;
}
static int F_401 ( struct V_12 * V_12 , T_2 V_195 )
{
char V_595 [ V_596 ] ;
F_402 ( V_595 , V_195 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_597 ) , V_595 ) ;
}
static int F_403 ( struct V_30 * V_30 ,
T_2 V_195 , T_1 V_598 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_599 [ V_600 ] ;
F_404 ( V_599 , V_30 -> V_10 ,
V_195 , V_598 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_601 ) , V_599 ) ;
}
static int F_405 ( struct V_30 * V_30 ,
T_2 V_195 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_599 [ V_600 ] ;
F_406 ( V_599 , V_30 -> V_10 ,
V_195 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_601 ) , V_599 ) ;
}
static int F_407 ( struct V_30 * V_30 ,
T_2 V_195 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_599 [ V_600 ] ;
F_408 ( V_599 , V_30 -> V_10 ,
V_195 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_601 ) , V_599 ) ;
}
static int F_409 ( struct V_30 * V_30 ,
T_2 V_195 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_599 [ V_600 ] ;
F_410 ( V_599 , V_30 -> V_10 ,
V_195 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_601 ) , V_599 ) ;
}
static int F_411 ( struct V_12 * V_12 ,
struct V_118 * V_554 ,
T_2 * V_602 )
{
struct V_512 * V_603 ;
int V_604 = - 1 ;
T_5 V_605 ;
int V_19 ;
V_605 = F_16 ( V_12 -> V_16 , V_509 ) ;
for ( V_19 = 0 ; V_19 < V_605 ; V_19 ++ ) {
V_603 = F_412 ( V_12 , V_19 ) ;
if ( V_603 -> V_39 ) {
if ( V_603 -> V_48 == V_554 ) {
* V_602 = V_19 ;
return 0 ;
}
} else if ( V_604 < 0 ) {
V_604 = V_19 ;
}
}
if ( V_604 < 0 )
return - V_606 ;
* V_602 = V_604 ;
return 0 ;
}
static bool
F_413 ( struct V_12 * V_12 ,
struct V_118 * V_554 ,
struct V_607 * V_608 )
{
T_2 V_195 ;
if ( F_411 ( V_12 , V_554 , & V_195 ) != 0 )
return false ;
if ( V_608 -> V_609 != V_610 )
return false ;
return true ;
}
static int F_414 ( struct V_12 * V_12 ,
T_2 V_195 , T_1 * V_611 )
{
T_5 V_581 ;
int V_19 ;
V_581 = F_16 ( V_12 -> V_16 ,
V_510 ) ;
for ( V_19 = 0 ; V_19 < V_581 ; V_19 ++ ) {
if ( ! F_382 ( V_12 , V_195 , V_19 ) ) {
* V_611 = V_19 ;
return 0 ;
}
}
return - V_606 ;
}
static void
F_415 ( struct V_30 * V_30 ,
T_2 V_195 )
{
struct V_30 * V_191 ;
struct V_201 * V_202 ;
V_191 = F_148 ( V_30 , 1 ) ;
if ( F_30 ( ! V_191 ) )
return;
V_202 = F_151 ( V_191 ) ;
if ( V_202 )
V_202 -> V_203 ( V_191 ) ;
V_191 -> V_195 = V_195 ;
V_191 -> V_194 = 1 ;
}
static void
F_416 ( struct V_30 * V_30 )
{
struct V_30 * V_191 ;
struct V_201 * V_202 ;
V_191 = F_148 ( V_30 , 1 ) ;
if ( F_30 ( ! V_191 ) )
return;
V_202 = F_151 ( V_191 ) ;
if ( V_202 )
V_202 -> V_203 ( V_191 ) ;
V_191 -> V_194 = 0 ;
}
static int F_417 ( struct V_30 * V_30 ,
struct V_118 * V_554 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
struct V_512 * V_603 ;
T_2 V_195 ;
T_1 V_598 ;
int V_15 ;
V_15 = F_411 ( V_12 , V_554 , & V_195 ) ;
if ( V_15 )
return V_15 ;
V_603 = F_412 ( V_12 , V_195 ) ;
if ( ! V_603 -> V_39 ) {
V_15 = F_399 ( V_12 , V_195 ) ;
if ( V_15 )
return V_15 ;
V_603 -> V_48 = V_554 ;
}
V_15 = F_414 ( V_12 , V_195 , & V_598 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_403 ( V_30 , V_195 , V_598 ) ;
if ( V_15 )
goto V_612;
V_15 = F_407 ( V_30 , V_195 ) ;
if ( V_15 )
goto V_613;
F_418 ( V_12 -> V_16 , V_195 , V_598 ,
V_30 -> V_10 ) ;
V_30 -> V_195 = V_195 ;
V_30 -> V_194 = 1 ;
V_603 -> V_39 ++ ;
F_415 ( V_30 , V_195 ) ;
return 0 ;
V_613:
F_405 ( V_30 , V_195 ) ;
V_612:
if ( ! V_603 -> V_39 )
F_401 ( V_12 , V_195 ) ;
return V_15 ;
}
static void F_419 ( struct V_30 * V_30 ,
struct V_118 * V_554 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
T_2 V_195 = V_30 -> V_195 ;
struct V_512 * V_603 ;
if ( ! V_30 -> V_194 )
return;
V_603 = F_412 ( V_12 , V_195 ) ;
F_30 ( V_603 -> V_39 == 0 ) ;
F_409 ( V_30 , V_195 ) ;
F_405 ( V_30 , V_195 ) ;
if ( V_30 -> V_594 ) {
F_420 ( V_30 ) ;
F_397 ( V_30 ) ;
}
if ( V_603 -> V_39 == 1 )
F_401 ( V_12 , V_195 ) ;
F_421 ( V_12 -> V_16 , V_195 ,
V_30 -> V_10 ) ;
V_30 -> V_194 = 0 ;
V_603 -> V_39 -- ;
F_416 ( V_30 ) ;
}
static int F_422 ( struct V_30 * V_30 ,
T_2 V_195 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_595 [ V_596 ] ;
F_423 ( V_595 , V_195 ,
V_30 -> V_10 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_597 ) , V_595 ) ;
}
static int F_424 ( struct V_30 * V_30 ,
T_2 V_195 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_595 [ V_596 ] ;
F_425 ( V_595 , V_195 ,
V_30 -> V_10 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_597 ) , V_595 ) ;
}
static int F_426 ( struct V_30 * V_30 ,
bool V_614 )
{
if ( V_614 )
return F_422 ( V_30 ,
V_30 -> V_195 ) ;
else
return F_424 ( V_30 ,
V_30 -> V_195 ) ;
}
static int F_427 ( struct V_30 * V_30 ,
struct V_615 * V_616 )
{
return F_426 ( V_30 , V_616 -> V_617 ) ;
}
static int F_428 ( struct V_30 * V_30 ,
struct V_118 * V_569 )
{
struct V_30 * V_191 ;
T_2 V_96 = F_352 ( V_569 ) ;
V_191 = F_148 ( V_30 , V_96 ) ;
if ( F_30 ( ! V_191 ) )
return - V_84 ;
V_191 -> V_48 = V_569 ;
return 0 ;
}
static void F_429 ( struct V_30 * V_30 ,
struct V_118 * V_569 )
{
struct V_30 * V_191 ;
T_2 V_96 = F_352 ( V_569 ) ;
V_191 = F_148 ( V_30 , V_96 ) ;
if ( F_30 ( ! V_191 ) )
return;
V_191 -> V_48 = V_30 -> V_48 ;
}
static int F_430 ( struct V_118 * V_48 ,
unsigned long V_530 , void * V_573 )
{
struct V_618 * V_616 ;
struct V_30 * V_30 ;
struct V_118 * V_619 ;
struct V_12 * V_12 ;
int V_15 = 0 ;
V_30 = F_84 ( V_48 ) ;
V_12 = V_30 -> V_12 ;
V_616 = V_573 ;
switch ( V_530 ) {
case V_620 :
V_619 = V_616 -> V_619 ;
if ( ! F_351 ( V_619 ) &&
! F_369 ( V_619 ) &&
! F_370 ( V_619 ) )
return - V_84 ;
if ( ! V_616 -> V_621 )
break;
if ( F_370 ( V_619 ) &&
! F_393 ( V_12 , V_619 ) )
return - V_84 ;
if ( F_369 ( V_619 ) &&
! F_413 ( V_12 , V_619 ,
V_616 -> V_622 ) )
return - V_84 ;
if ( F_369 ( V_619 ) && F_431 ( V_48 ) )
return - V_84 ;
if ( F_346 ( V_48 ) && F_351 ( V_619 ) &&
! F_369 ( F_368 ( V_619 ) ) )
return - V_84 ;
break;
case V_623 :
V_619 = V_616 -> V_619 ;
if ( F_351 ( V_619 ) ) {
if ( V_616 -> V_621 )
V_15 = F_428 ( V_30 ,
V_619 ) ;
else
F_429 ( V_30 ,
V_619 ) ;
} else if ( F_370 ( V_619 ) ) {
if ( V_616 -> V_621 )
V_15 = F_396 ( V_30 ,
V_619 ) ;
else
F_397 ( V_30 ) ;
} else if ( F_369 ( V_619 ) ) {
if ( V_616 -> V_621 )
V_15 = F_417 ( V_30 ,
V_619 ) ;
else
F_419 ( V_30 ,
V_619 ) ;
} else {
V_15 = - V_84 ;
F_30 ( 1 ) ;
}
break;
}
return V_15 ;
}
static int F_432 ( struct V_118 * V_48 ,
unsigned long V_530 , void * V_573 )
{
struct V_624 * V_616 ;
struct V_30 * V_30 ;
int V_15 ;
V_30 = F_84 ( V_48 ) ;
V_616 = V_573 ;
switch ( V_530 ) {
case V_625 :
if ( F_346 ( V_48 ) && V_30 -> V_194 ) {
V_15 = F_427 ( V_30 ,
V_616 -> V_626 ) ;
if ( V_15 )
F_37 ( V_48 , L_60 ) ;
}
break;
}
return 0 ;
}
static int F_433 ( struct V_118 * V_48 ,
unsigned long V_530 , void * V_573 )
{
switch ( V_530 ) {
case V_620 :
case V_623 :
return F_430 ( V_48 , V_530 , V_573 ) ;
case V_625 :
return F_432 ( V_48 , V_530 , V_573 ) ;
}
return 0 ;
}
static int F_434 ( struct V_118 * V_554 ,
unsigned long V_530 , void * V_573 )
{
struct V_118 * V_48 ;
struct V_555 * V_556 ;
int V_527 ;
F_348 (lag_dev, dev, iter) {
if ( F_158 ( V_48 ) ) {
V_527 = F_433 ( V_48 , V_530 , V_573 ) ;
if ( V_527 )
return V_527 ;
}
}
return 0 ;
}
static int F_435 ( struct V_12 * V_12 ,
struct V_118 * V_569 )
{
T_2 V_95 = F_352 ( V_569 ) ;
struct V_201 * V_202 ;
V_202 = F_354 ( V_12 , V_95 ) ;
if ( ! V_202 ) {
V_202 = F_436 ( V_12 , V_95 ) ;
if ( F_340 ( V_202 ) )
return F_341 ( V_202 ) ;
}
V_202 -> V_39 ++ ;
return 0 ;
}
static void F_437 ( struct V_12 * V_12 ,
struct V_118 * V_569 )
{
T_2 V_95 = F_352 ( V_569 ) ;
struct V_201 * V_202 ;
V_202 = F_354 ( V_12 , V_95 ) ;
if ( V_202 && V_202 -> V_529 )
F_365 ( V_12 , V_202 -> V_529 ) ;
if ( V_202 && -- V_202 -> V_39 == 0 )
F_392 ( V_12 , V_202 ) ;
}
static int F_438 ( struct V_118 * V_568 ,
unsigned long V_530 , void * V_573 )
{
struct V_618 * V_616 ;
struct V_118 * V_619 ;
struct V_12 * V_12 ;
int V_15 ;
V_12 = F_316 ( V_568 ) ;
if ( ! V_12 )
return 0 ;
if ( V_568 != V_12 -> V_557 . V_48 )
return 0 ;
V_616 = V_573 ;
switch ( V_530 ) {
case V_623 :
V_619 = V_616 -> V_619 ;
if ( ! F_351 ( V_619 ) )
break;
if ( V_616 -> V_621 ) {
V_15 = F_435 ( V_12 ,
V_619 ) ;
if ( V_15 )
return V_15 ;
} else {
F_437 ( V_12 , V_619 ) ;
}
break;
}
return 0 ;
}
static T_2 F_439 ( const struct V_12 * V_12 )
{
return F_440 ( V_12 -> V_516 . V_627 ,
V_628 ) ;
}
static int F_441 ( struct V_12 * V_12 , T_2 V_95 , bool V_540 )
{
char V_629 [ V_630 ] ;
F_442 ( V_629 , ! V_540 , V_95 , 0 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_631 ) , V_629 ) ;
}
static struct V_201 * F_443 ( struct V_12 * V_12 ,
struct V_118 * V_568 )
{
struct V_632 * V_48 = V_12 -> V_261 -> V_48 ;
struct V_201 * V_202 ;
T_2 V_633 , V_95 ;
int V_15 ;
V_633 = F_439 ( V_12 ) ;
if ( V_633 == V_628 ) {
F_243 ( V_48 , L_61 ) ;
return F_333 ( - V_549 ) ;
}
V_95 = F_444 ( V_633 ) ;
V_15 = F_441 ( V_12 , V_95 , true ) ;
if ( V_15 ) {
F_243 ( V_48 , L_62 , V_95 ) ;
return F_333 ( V_15 ) ;
}
V_202 = F_41 ( sizeof( * V_202 ) , V_26 ) ;
if ( ! V_202 )
goto V_634;
V_202 -> V_203 = V_635 ;
V_202 -> V_95 = V_95 ;
V_202 -> V_48 = V_568 ;
F_145 ( & V_202 -> V_57 , & V_12 -> V_516 . V_57 ) ;
F_445 ( V_633 , V_12 -> V_516 . V_627 ) ;
return V_202 ;
V_634:
F_441 ( V_12 , V_95 , false ) ;
return F_333 ( - V_27 ) ;
}
static void F_446 ( struct V_12 * V_12 ,
struct V_201 * V_202 )
{
T_2 V_633 = F_358 ( V_202 -> V_95 ) ;
T_2 V_95 = V_202 -> V_95 ;
F_447 ( V_633 , V_12 -> V_516 . V_627 ) ;
F_44 ( & V_202 -> V_57 ) ;
if ( V_202 -> V_529 )
F_365 ( V_12 , V_202 -> V_529 ) ;
F_22 ( V_202 ) ;
F_441 ( V_12 , V_95 , false ) ;
}
static int F_448 ( struct V_30 * V_191 , T_2 V_95 ,
bool V_94 )
{
enum V_92 V_93 = V_187 ;
T_2 V_96 = F_329 ( V_191 ) ;
return F_65 ( V_191 , V_93 , V_94 , V_95 ,
V_96 ) ;
}
static int F_449 ( struct V_30 * V_191 ,
struct V_118 * V_568 )
{
struct V_201 * V_202 ;
int V_15 ;
V_202 = F_353 ( V_191 -> V_12 , V_568 ) ;
if ( ! V_202 ) {
V_202 = F_443 ( V_191 -> V_12 , V_568 ) ;
if ( F_340 ( V_202 ) )
return F_341 ( V_202 ) ;
}
V_15 = F_450 ( V_191 , V_202 -> V_95 , true ) ;
if ( V_15 )
goto V_636;
V_15 = F_448 ( V_191 , V_202 -> V_95 , true ) ;
if ( V_15 )
goto V_637;
F_342 ( V_191 , V_202 ) ;
V_202 -> V_39 ++ ;
F_46 ( V_191 -> V_48 , L_53 , V_202 -> V_95 ) ;
return 0 ;
V_637:
F_450 ( V_191 , V_202 -> V_95 , false ) ;
V_636:
if ( ! V_202 -> V_39 )
F_446 ( V_191 -> V_12 , V_202 ) ;
return V_15 ;
}
static void V_635 ( struct V_30 * V_191 )
{
struct V_201 * V_202 = F_151 ( V_191 ) ;
F_46 ( V_191 -> V_48 , L_54 , V_202 -> V_95 ) ;
F_448 ( V_191 , V_202 -> V_95 , false ) ;
F_450 ( V_191 , V_202 -> V_95 , false ) ;
F_389 ( V_191 , V_202 -> V_95 ) ;
F_342 ( V_191 , NULL ) ;
if ( -- V_202 -> V_39 == 0 )
F_446 ( V_191 -> V_12 , V_202 ) ;
}
static int F_451 ( struct V_30 * V_191 ,
struct V_118 * V_568 )
{
struct V_201 * V_202 = F_151 ( V_191 ) ;
T_2 V_96 = F_329 ( V_191 ) ;
struct V_118 * V_48 = V_191 -> V_48 ;
int V_15 ;
if ( V_202 && ! F_30 ( ! V_202 -> V_203 ) )
V_202 -> V_203 ( V_191 ) ;
V_15 = F_449 ( V_191 , V_568 ) ;
if ( V_15 ) {
F_37 ( V_48 , L_63 ) ;
return V_15 ;
}
V_15 = F_70 ( V_191 , V_96 , true ) ;
if ( V_15 ) {
F_37 ( V_48 , L_64 ) ;
goto V_638;
}
V_191 -> V_588 = 1 ;
V_191 -> V_589 = 1 ;
V_191 -> V_590 = 1 ;
V_191 -> V_591 = 1 ;
V_191 -> V_592 = 0 ;
V_191 -> V_593 = 1 ;
V_191 -> V_594 = 1 ;
return 0 ;
V_638:
V_635 ( V_191 ) ;
return V_15 ;
}
static void F_452 ( struct V_30 * V_191 )
{
T_2 V_96 = F_329 ( V_191 ) ;
F_70 ( V_191 , V_96 , false ) ;
V_635 ( V_191 ) ;
V_191 -> V_588 = 0 ;
V_191 -> V_589 = 0 ;
V_191 -> V_590 = 0 ;
V_191 -> V_591 = 0 ;
V_191 -> V_592 = 0 ;
V_191 -> V_594 = 0 ;
}
static bool
F_453 ( const struct V_30 * V_30 ,
const struct V_118 * V_568 )
{
struct V_30 * V_191 ;
F_32 (mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
struct V_118 * V_48 = F_454 ( V_191 ) ;
if ( V_48 && V_48 == V_568 )
return false ;
}
return true ;
}
static int F_455 ( struct V_118 * V_48 ,
unsigned long V_530 , void * V_573 ,
T_2 V_96 )
{
struct V_30 * V_30 = F_84 ( V_48 ) ;
struct V_618 * V_616 = V_573 ;
struct V_30 * V_191 ;
struct V_118 * V_619 ;
int V_15 = 0 ;
V_191 = F_148 ( V_30 , V_96 ) ;
switch ( V_530 ) {
case V_620 :
V_619 = V_616 -> V_619 ;
if ( ! F_370 ( V_619 ) )
return - V_84 ;
if ( ! V_616 -> V_621 )
break;
if ( ! F_453 ( V_30 ,
V_619 ) )
return - V_84 ;
break;
case V_623 :
V_619 = V_616 -> V_619 ;
if ( V_616 -> V_621 ) {
if ( F_30 ( ! V_191 ) )
return - V_84 ;
V_15 = F_451 ( V_191 ,
V_619 ) ;
} else {
if ( ! V_191 )
return 0 ;
F_452 ( V_191 ) ;
}
}
return V_15 ;
}
static int F_456 ( struct V_118 * V_554 ,
unsigned long V_530 , void * V_573 ,
T_2 V_96 )
{
struct V_118 * V_48 ;
struct V_555 * V_556 ;
int V_527 ;
F_348 (lag_dev, dev, iter) {
if ( F_158 ( V_48 ) ) {
V_527 = F_455 ( V_48 , V_530 , V_573 ,
V_96 ) ;
if ( V_527 )
return V_527 ;
}
}
return 0 ;
}
static int F_457 ( struct V_118 * V_569 ,
unsigned long V_530 , void * V_573 )
{
struct V_118 * V_570 = F_368 ( V_569 ) ;
T_2 V_96 = F_352 ( V_569 ) ;
if ( F_158 ( V_570 ) )
return F_455 ( V_570 , V_530 , V_573 ,
V_96 ) ;
else if ( F_369 ( V_570 ) )
return F_456 ( V_570 , V_530 , V_573 ,
V_96 ) ;
return 0 ;
}
static int F_458 ( struct V_571 * V_572 ,
unsigned long V_530 , void * V_573 )
{
struct V_118 * V_48 = F_459 ( V_573 ) ;
int V_15 = 0 ;
if ( V_530 == V_639 || V_530 == V_640 )
V_15 = F_378 ( V_48 ) ;
else if ( F_158 ( V_48 ) )
V_15 = F_433 ( V_48 , V_530 , V_573 ) ;
else if ( F_369 ( V_48 ) )
V_15 = F_434 ( V_48 , V_530 , V_573 ) ;
else if ( F_370 ( V_48 ) )
V_15 = F_438 ( V_48 , V_530 , V_573 ) ;
else if ( F_351 ( V_48 ) )
V_15 = F_457 ( V_48 , V_530 , V_573 ) ;
return F_372 ( V_15 ) ;
}
static int T_9 F_460 ( void )
{
int V_15 ;
F_461 ( & V_641 ) ;
F_462 ( & V_642 ) ;
F_463 ( & V_643 ) ;
V_15 = F_464 ( & V_644 ) ;
if ( V_15 )
goto V_645;
V_15 = F_465 ( & V_646 ) ;
if ( V_15 )
goto V_647;
return 0 ;
V_647:
F_466 ( & V_644 ) ;
V_645:
F_467 ( & V_643 ) ;
F_468 ( & V_642 ) ;
F_469 ( & V_641 ) ;
return V_15 ;
}
static void T_10 F_470 ( void )
{
F_471 ( & V_646 ) ;
F_466 ( & V_644 ) ;
F_467 ( & V_643 ) ;
F_468 ( & V_642 ) ;
F_469 ( & V_641 ) ;
}
