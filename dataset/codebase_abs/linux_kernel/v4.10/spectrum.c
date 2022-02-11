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
bool V_62 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_63 [ V_64 ] ;
F_49 ( V_63 , V_30 -> V_10 ,
V_62 ? V_65 :
V_66 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_67 ) , V_63 ) ;
}
static int F_50 ( struct V_30 * V_30 ,
unsigned char * V_68 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_69 [ V_70 ] ;
F_51 ( V_69 , true , V_30 -> V_10 ) ;
F_52 ( V_69 , V_68 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_71 ) , V_69 ) ;
}
static int F_53 ( struct V_30 * V_30 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
unsigned char * V_68 = V_30 -> V_48 -> V_72 ;
F_54 ( V_68 , V_12 -> V_18 ) ;
V_68 [ V_73 - 1 ] += V_30 -> V_10 ;
return F_50 ( V_30 , V_68 ) ;
}
static int F_55 ( struct V_30 * V_30 , T_2 V_44 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_74 [ V_75 ] ;
int V_76 ;
int V_15 ;
V_44 += V_6 + V_77 ;
F_56 ( V_74 , V_30 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_78 ) , V_74 ) ;
if ( V_15 )
return V_15 ;
V_76 = F_57 ( V_74 ) ;
if ( V_44 > V_76 )
return - V_79 ;
F_56 ( V_74 , V_30 -> V_10 , V_44 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_78 ) , V_74 ) ;
}
static int F_58 ( struct V_12 * V_12 , T_1 V_10 ,
T_1 V_80 )
{
char V_81 [ V_82 ] ;
F_59 ( V_81 , V_80 , V_10 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_83 ) , V_81 ) ;
}
static int F_60 ( struct V_30 * V_30 , T_1 V_80 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
return F_58 ( V_12 , V_30 -> V_10 ,
V_80 ) ;
}
static int F_61 ( struct V_30 * V_30 ,
bool V_84 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_85 [ V_86 ] ;
F_62 ( V_85 , V_30 -> V_10 , V_84 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_87 ) , V_85 ) ;
}
int F_63 ( struct V_30 * V_30 ,
enum V_88 V_89 , bool V_90 , T_2 V_91 ,
T_2 V_92 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_93 [ V_94 ] ;
F_64 ( V_93 , V_30 -> V_10 , V_89 , V_90 ,
V_91 , V_92 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_95 ) , V_93 ) ;
}
int F_65 ( struct V_30 * V_30 ,
T_2 V_96 , T_2 V_97 ,
bool V_98 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char * V_99 ;
int V_15 ;
V_99 = F_66 ( V_100 , V_26 ) ;
if ( ! V_99 )
return - V_27 ;
F_67 ( V_99 , V_30 -> V_10 , V_96 ,
V_97 , V_98 ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_101 ) , V_99 ) ;
F_22 ( V_99 ) ;
return V_15 ;
}
static int F_68 ( struct V_30 * V_30 ,
T_2 V_92 , bool V_98 )
{
return F_65 ( V_30 , V_92 , V_92 ,
V_98 ) ;
}
static int
F_69 ( struct V_30 * V_30 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_102 [ V_103 ] ;
F_70 ( V_102 , V_30 -> V_10 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_104 ) , V_102 ) ;
}
static int F_71 ( struct V_12 * V_12 ,
T_1 V_10 , T_1 * V_105 ,
T_1 * V_106 , T_1 * V_107 )
{
char V_108 [ V_109 ] ;
int V_15 ;
F_72 ( V_108 , V_10 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_110 ) , V_108 ) ;
if ( V_15 )
return V_15 ;
* V_105 = F_73 ( V_108 , 0 ) ;
* V_106 = F_74 ( V_108 ) ;
* V_107 = F_75 ( V_108 , 0 ) ;
return 0 ;
}
static int F_76 ( struct V_12 * V_12 , T_1 V_10 ,
T_1 V_111 , T_1 V_112 , T_1 V_113 )
{
char V_108 [ V_109 ] ;
int V_19 ;
F_72 ( V_108 , V_10 ) ;
F_77 ( V_108 , V_112 ) ;
for ( V_19 = 0 ; V_19 < V_112 ; V_19 ++ ) {
F_78 ( V_108 , V_19 , V_111 ) ;
F_79 ( V_108 , V_19 , V_113 + V_19 ) ;
}
return F_25 ( V_12 -> V_16 , F_12 ( V_110 ) , V_108 ) ;
}
static int F_80 ( struct V_12 * V_12 , T_1 V_10 )
{
char V_108 [ V_109 ] ;
F_72 ( V_108 , V_10 ) ;
F_77 ( V_108 , 0 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_110 ) , V_108 ) ;
}
static int F_81 ( struct V_114 * V_48 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
int V_15 ;
V_15 = F_48 ( V_30 , true ) ;
if ( V_15 )
return V_15 ;
F_83 ( V_48 ) ;
return 0 ;
}
static int F_84 ( struct V_114 * V_48 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
F_85 ( V_48 ) ;
return F_48 ( V_30 , false ) ;
}
static T_3 F_86 ( struct V_1 * V_2 ,
struct V_114 * V_48 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
struct V_115 * V_116 ;
const struct V_3 V_4 = {
. V_10 = V_30 -> V_10 ,
. V_117 = false ,
} ;
T_4 V_118 ;
int V_15 ;
if ( F_87 ( V_12 -> V_16 , & V_4 ) )
return V_119 ;
if ( F_88 ( F_89 ( V_2 ) < V_6 ) ) {
struct V_1 * V_120 = V_2 ;
V_2 = F_90 ( V_2 , V_6 ) ;
if ( ! V_2 ) {
F_91 ( V_30 -> V_116 -> V_121 ) ;
F_92 ( V_120 ) ;
return V_122 ;
}
F_93 ( V_120 ) ;
}
if ( F_94 ( V_2 ) ) {
F_91 ( V_30 -> V_116 -> V_121 ) ;
return V_122 ;
}
F_1 ( V_2 , & V_4 ) ;
V_118 = V_2 -> V_118 - V_6 ;
V_15 = F_95 ( V_12 -> V_16 , V_2 , & V_4 ) ;
if ( ! V_15 ) {
V_116 = F_96 ( V_30 -> V_116 ) ;
F_97 ( & V_116 -> V_123 ) ;
V_116 -> V_124 ++ ;
V_116 -> V_125 += V_118 ;
F_98 ( & V_116 -> V_123 ) ;
} else {
F_91 ( V_30 -> V_116 -> V_121 ) ;
F_92 ( V_2 ) ;
}
return V_122 ;
}
static void F_99 ( struct V_114 * V_48 )
{
}
static int F_100 ( struct V_114 * V_48 , void * V_42 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
struct V_126 * V_68 = V_42 ;
int V_15 ;
if ( ! F_101 ( V_68 -> V_127 ) )
return - V_128 ;
V_15 = F_50 ( V_30 , V_68 -> V_127 ) ;
if ( V_15 )
return V_15 ;
memcpy ( V_48 -> V_72 , V_68 -> V_127 , V_48 -> V_129 ) ;
return 0 ;
}
static void F_102 ( char * V_130 , int V_131 , int V_44 ,
bool V_132 , bool V_133 , T_2 V_134 )
{
T_2 V_135 = 2 * F_34 ( V_44 ) ;
V_134 = V_133 ? F_103 ( V_44 , V_134 ) :
V_136 ;
if ( V_132 || V_133 )
F_104 ( V_130 , V_131 ,
V_135 + V_134 , V_135 ) ;
else
F_105 ( V_130 , V_131 , V_135 ) ;
}
int F_106 ( struct V_30 * V_30 , int V_44 ,
T_1 * V_137 , bool V_132 ,
struct V_138 * V_139 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
T_1 V_133 = ! ! V_139 ? V_139 -> V_133 : 0 ;
T_2 V_134 = ! ! V_139 ? V_139 -> V_134 : 0 ;
char V_130 [ V_140 ] ;
int V_19 , V_141 , V_15 ;
F_107 ( V_130 , V_30 -> V_10 , 0 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_142 ) , V_130 ) ;
if ( V_15 )
return V_15 ;
for ( V_19 = 0 ; V_19 < V_143 ; V_19 ++ ) {
bool V_144 = false ;
bool V_145 = false ;
for ( V_141 = 0 ; V_141 < V_143 ; V_141 ++ ) {
if ( V_137 [ V_141 ] == V_19 ) {
V_145 = V_133 & F_108 ( V_141 ) ;
V_144 = true ;
break;
}
}
if ( ! V_144 )
continue;
F_102 ( V_130 , V_19 , V_44 , V_132 , V_145 , V_134 ) ;
}
return F_25 ( V_12 -> V_16 , F_12 ( V_142 ) , V_130 ) ;
}
static int F_109 ( struct V_30 * V_30 ,
int V_44 , bool V_132 )
{
T_1 V_146 [ V_143 ] = { 0 } ;
bool V_147 = ! ! V_30 -> V_148 . V_149 ;
struct V_138 * V_139 ;
T_1 * V_137 ;
V_137 = V_147 ? V_30 -> V_148 . V_149 -> V_137 : V_146 ;
V_139 = V_147 ? V_30 -> V_148 . V_145 : NULL ;
return F_106 ( V_30 , V_44 , V_137 ,
V_132 , V_139 ) ;
}
static int F_110 ( struct V_114 * V_48 , int V_44 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
bool V_132 = F_111 ( V_30 ) ;
int V_15 ;
V_15 = F_109 ( V_30 , V_44 , V_132 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_35 ( V_30 , V_44 ) ;
if ( V_15 )
goto V_150;
V_15 = F_55 ( V_30 , V_44 ) ;
if ( V_15 )
goto V_151;
V_48 -> V_44 = V_44 ;
return 0 ;
V_151:
F_35 ( V_30 , V_48 -> V_44 ) ;
V_150:
F_109 ( V_30 , V_48 -> V_44 , V_132 ) ;
return V_15 ;
}
static int
F_112 ( const struct V_114 * V_48 ,
struct V_152 * V_153 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
struct V_115 * V_42 ;
T_4 V_154 , V_155 , V_124 , V_125 ;
T_5 V_121 = 0 ;
unsigned int V_156 ;
int V_19 ;
F_113 (i) {
V_42 = F_114 ( V_30 -> V_116 , V_19 ) ;
do {
V_156 = F_115 ( & V_42 -> V_123 ) ;
V_154 = V_42 -> V_154 ;
V_155 = V_42 -> V_155 ;
V_124 = V_42 -> V_124 ;
V_125 = V_42 -> V_125 ;
} while ( F_116 ( & V_42 -> V_123 , V_156 ) );
V_153 -> V_154 += V_154 ;
V_153 -> V_155 += V_155 ;
V_153 -> V_124 += V_124 ;
V_153 -> V_125 += V_125 ;
V_121 += V_42 -> V_121 ;
}
V_153 -> V_121 = V_121 ;
return 0 ;
}
static bool F_117 ( const struct V_114 * V_48 , int V_157 )
{
switch ( V_157 ) {
case V_158 :
return true ;
}
return false ;
}
static int F_118 ( int V_157 , const struct V_114 * V_48 ,
void * V_159 )
{
switch ( V_157 ) {
case V_158 :
return F_112 ( V_48 , V_159 ) ;
}
return - V_79 ;
}
static int F_119 ( struct V_114 * V_48 , int V_160 ,
int V_161 , char * V_162 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
F_120 ( V_162 , V_30 -> V_10 , V_160 , V_161 ) ;
return F_11 ( V_12 -> V_16 , F_12 ( V_163 ) , V_162 ) ;
}
static int F_121 ( struct V_114 * V_48 ,
struct V_152 * V_153 )
{
char V_162 [ V_164 ] ;
int V_15 ;
V_15 = F_119 ( V_48 , V_165 ,
0 , V_162 ) ;
if ( V_15 )
goto V_166;
V_153 -> V_124 =
F_122 ( V_162 ) ;
V_153 -> V_154 =
F_123 ( V_162 ) ;
V_153 -> V_125 =
F_124 ( V_162 ) ;
V_153 -> V_155 =
F_125 ( V_162 ) ;
V_153 -> V_167 =
F_126 ( V_162 ) ;
V_153 -> V_168 =
F_127 ( V_162 ) ;
V_153 -> V_169 =
F_128 ( V_162 ) ;
V_153 -> V_170 = (
F_129 ( V_162 ) +
F_130 ( V_162 ) +
F_131 ( V_162 ) ) ;
V_153 -> V_171 = ( V_153 -> V_168 +
V_153 -> V_169 + V_153 -> V_170 ) ;
V_166:
return V_15 ;
}
static void F_132 ( struct V_172 * V_173 )
{
struct V_30 * V_30 =
F_133 ( V_173 , struct V_30 ,
V_174 . V_175 . V_173 ) ;
if ( ! F_134 ( V_30 -> V_48 ) )
goto V_166;
F_121 ( V_30 -> V_48 ,
V_30 -> V_174 . V_176 ) ;
V_166:
F_135 ( & V_30 -> V_174 . V_175 ,
V_177 ) ;
}
static struct V_152 *
F_136 ( struct V_114 * V_48 ,
struct V_152 * V_153 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
memcpy ( V_153 , V_30 -> V_174 . V_176 , sizeof( * V_153 ) ) ;
return V_153 ;
}
int F_137 ( struct V_30 * V_30 , T_2 V_96 ,
T_2 V_97 , bool V_178 , bool V_179 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char * V_180 ;
int V_15 ;
V_180 = F_66 ( V_181 , V_26 ) ;
if ( ! V_180 )
return - V_27 ;
F_138 ( V_180 , V_30 -> V_10 , V_96 ,
V_97 , V_178 , V_179 ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_182 ) , V_180 ) ;
F_22 ( V_180 ) ;
return V_15 ;
}
static int F_139 ( struct V_30 * V_30 )
{
enum V_88 V_89 = V_183 ;
T_2 V_92 , V_184 ;
int V_15 ;
F_140 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_63 ( V_30 , V_89 , true , V_92 ,
V_92 ) ;
if ( V_15 ) {
V_184 = V_92 ;
goto V_185;
}
}
V_15 = F_61 ( V_30 , true ) ;
if ( V_15 ) {
V_184 = V_186 ;
goto V_185;
}
return 0 ;
V_185:
F_140 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_63 ( V_30 , V_89 , false , V_92 ,
V_92 ) ;
return V_15 ;
}
static int F_141 ( struct V_30 * V_30 )
{
enum V_88 V_89 = V_183 ;
T_2 V_92 ;
int V_15 ;
V_15 = F_61 ( V_30 , false ) ;
if ( V_15 )
return V_15 ;
F_140 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_63 ( V_30 , V_89 , false ,
V_92 , V_92 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static struct V_30 *
F_142 ( struct V_30 * V_30 , T_2 V_92 )
{
struct V_30 * V_187 ;
V_187 = F_41 ( sizeof( * V_187 ) , V_26 ) ;
if ( ! V_187 )
return NULL ;
V_187 -> V_48 = V_30 -> V_48 ;
V_187 -> V_12 = V_30 -> V_12 ;
V_187 -> V_10 = V_30 -> V_10 ;
V_187 -> V_188 = V_189 ;
V_187 -> V_190 = V_30 -> V_190 ;
V_187 -> V_191 = V_30 -> V_191 ;
V_187 -> V_192 . V_92 = V_92 ;
F_143 ( & V_187 -> V_192 . V_57 , & V_30 -> V_193 ) ;
return V_187 ;
}
static void F_144 ( struct V_30 * V_187 )
{
F_44 ( & V_187 -> V_192 . V_57 ) ;
F_22 ( V_187 ) ;
}
static int F_145 ( struct V_114 * V_48 ,
T_6 T_7 V_194 , T_2 V_92 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
struct V_30 * V_187 ;
bool V_179 = V_92 == 1 ;
int V_15 ;
if ( ! V_92 )
return 0 ;
if ( F_146 ( V_30 , V_92 ) )
return 0 ;
V_187 = F_142 ( V_30 , V_92 ) ;
if ( ! V_187 )
return - V_27 ;
if ( F_147 ( & V_30 -> V_193 ) ) {
V_15 = F_139 ( V_30 ) ;
if ( V_15 )
goto V_195;
}
V_15 = F_137 ( V_187 , V_92 , V_92 , true , V_179 ) ;
if ( V_15 )
goto V_196;
return 0 ;
V_196:
if ( F_147 ( & V_30 -> V_193 ) )
F_141 ( V_30 ) ;
V_195:
F_144 ( V_187 ) ;
return V_15 ;
}
static int F_148 ( struct V_114 * V_48 ,
T_6 T_7 V_194 , T_2 V_92 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
struct V_30 * V_187 ;
struct V_197 * V_198 ;
if ( ! V_92 )
return 0 ;
V_187 = F_146 ( V_30 , V_92 ) ;
if ( F_30 ( ! V_187 ) )
return 0 ;
F_137 ( V_187 , V_92 , V_92 , false , false ) ;
V_198 = F_149 ( V_187 ) ;
if ( V_198 && ! F_30 ( ! V_198 -> V_199 ) )
V_198 -> V_199 ( V_187 ) ;
if ( F_147 ( & V_30 -> V_193 ) )
F_141 ( V_30 ) ;
F_144 ( V_187 ) ;
return 0 ;
}
static int F_150 ( struct V_114 * V_48 , char * V_200 ,
T_8 V_118 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
T_1 V_111 = V_30 -> V_201 . V_111 ;
T_1 V_112 = V_30 -> V_201 . V_112 ;
T_1 V_113 = V_30 -> V_201 . V_113 ;
int V_15 ;
if ( ! V_30 -> V_202 )
V_15 = snprintf ( V_200 , V_118 , L_6 , V_111 + 1 ) ;
else
V_15 = snprintf ( V_200 , V_118 , L_7 , V_111 + 1 ,
V_113 / V_112 ) ;
if ( V_15 >= V_118 )
return - V_79 ;
return 0 ;
}
static struct V_203 *
F_151 ( struct V_30 * V_31 ,
unsigned long V_204 ) {
struct V_203 * V_205 ;
F_32 (mall_tc_entry, &port->mall_tc_list, list)
if ( V_205 -> V_204 == V_204 )
return V_205 ;
return NULL ;
}
static int
F_152 ( struct V_30 * V_30 ,
struct V_206 * V_207 ,
const struct V_208 * V_209 ,
bool V_210 )
{
struct V_203 * V_205 ;
struct V_211 * V_211 = F_153 ( V_30 -> V_48 ) ;
enum V_49 V_212 ;
struct V_30 * V_213 ;
struct V_114 * V_214 ;
int V_215 ;
int V_15 ;
V_215 = F_154 ( V_209 ) ;
V_214 = F_155 ( V_211 , V_215 ) ;
if ( ! V_214 ) {
F_37 ( V_30 -> V_48 , L_8 ) ;
return - V_79 ;
}
if ( ! F_156 ( V_214 ) ) {
F_37 ( V_30 -> V_48 , L_9 ) ;
return - V_216 ;
}
V_213 = F_82 ( V_214 ) ;
V_205 = F_41 ( sizeof( * V_205 ) , V_26 ) ;
if ( ! V_205 )
return - V_27 ;
V_205 -> V_204 = V_207 -> V_204 ;
V_205 -> type = V_217 ;
V_205 -> V_218 . V_219 = V_213 -> V_10 ;
V_205 -> V_218 . V_210 = V_210 ;
F_42 ( & V_205 -> V_57 , & V_30 -> V_220 ) ;
V_212 = V_210 ? V_221 : V_43 ;
V_15 = F_45 ( V_30 , V_213 , V_212 ) ;
if ( V_15 )
goto V_222;
return 0 ;
V_222:
F_44 ( & V_205 -> V_57 ) ;
F_22 ( V_205 ) ;
return V_15 ;
}
static int F_157 ( struct V_30 * V_30 ,
T_6 V_223 ,
struct V_206 * V_207 ,
bool V_210 )
{
const struct V_208 * V_209 ;
F_158 ( V_224 ) ;
int V_15 ;
if ( ! F_159 ( V_207 -> V_225 ) ) {
F_37 ( V_30 -> V_48 , L_10 ) ;
return - V_216 ;
}
F_160 ( V_207 -> V_225 , & V_224 ) ;
F_32 (a, &actions, list) {
if ( ! F_161 ( V_209 ) ||
V_223 != F_162 ( V_226 ) ) {
return - V_216 ;
}
V_15 = F_152 ( V_30 , V_207 ,
V_209 , V_210 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static void F_163 ( struct V_30 * V_30 ,
struct V_206 * V_207 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
struct V_203 * V_205 ;
enum V_49 V_212 ;
struct V_30 * V_213 ;
V_205 = F_151 ( V_30 ,
V_207 -> V_204 ) ;
if ( ! V_205 ) {
F_46 ( V_30 -> V_48 , L_11 ) ;
return;
}
switch ( V_205 -> type ) {
case V_217 :
V_213 = V_12 -> V_227 [ V_205 -> V_218 . V_219 ] ;
V_212 = V_205 -> V_218 . V_210 ?
V_221 : V_43 ;
F_47 ( V_30 , V_213 , V_212 ) ;
break;
default:
F_30 ( 1 ) ;
}
F_44 ( & V_205 -> V_57 ) ;
F_22 ( V_205 ) ;
}
static int F_164 ( struct V_114 * V_48 , T_5 V_228 ,
T_6 V_194 , struct V_229 * V_230 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
bool V_210 = F_165 ( V_228 ) == F_165 ( V_231 ) ;
if ( V_230 -> type == V_232 ) {
switch ( V_230 -> V_233 -> V_234 ) {
case V_235 :
return F_157 ( V_30 ,
V_194 ,
V_230 -> V_233 ,
V_210 ) ;
case V_236 :
F_163 ( V_30 ,
V_230 -> V_233 ) ;
return 0 ;
default:
return - V_79 ;
}
}
return - V_216 ;
}
static void F_166 ( struct V_114 * V_48 ,
struct V_237 * V_238 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
F_167 ( V_238 -> V_239 , V_240 , sizeof( V_238 -> V_239 ) ) ;
F_167 ( V_238 -> V_241 , V_242 ,
sizeof( V_238 -> V_241 ) ) ;
snprintf ( V_238 -> V_243 , sizeof( V_238 -> V_243 ) ,
L_12 ,
V_12 -> V_244 -> V_245 . V_246 ,
V_12 -> V_244 -> V_245 . V_247 ,
V_12 -> V_244 -> V_245 . V_248 ) ;
F_167 ( V_238 -> V_244 , V_12 -> V_244 -> V_249 ,
sizeof( V_238 -> V_244 ) ) ;
}
static void F_168 ( struct V_114 * V_48 ,
struct V_250 * V_251 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
V_251 -> V_252 = V_30 -> V_253 . V_252 ;
V_251 -> V_254 = V_30 -> V_253 . V_254 ;
}
static int F_169 ( struct V_30 * V_30 ,
struct V_250 * V_251 )
{
char V_255 [ V_256 ] ;
F_170 ( V_255 , V_30 -> V_10 ) ;
F_171 ( V_255 , V_251 -> V_252 ) ;
F_172 ( V_255 , V_251 -> V_254 ) ;
return F_25 ( V_30 -> V_12 -> V_16 , F_12 ( V_257 ) ,
V_255 ) ;
}
static int F_173 ( struct V_114 * V_48 ,
struct V_250 * V_251 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
bool V_132 = V_251 -> V_254 || V_251 -> V_252 ;
int V_15 ;
if ( V_30 -> V_148 . V_145 && V_30 -> V_148 . V_145 -> V_133 ) {
F_37 ( V_48 , L_13 ) ;
return - V_79 ;
}
if ( V_251 -> V_258 ) {
F_37 ( V_48 , L_14 ) ;
return - V_79 ;
}
V_15 = F_109 ( V_30 , V_48 -> V_44 , V_132 ) ;
if ( V_15 ) {
F_37 ( V_48 , L_15 ) ;
return V_15 ;
}
V_15 = F_169 ( V_30 , V_251 ) ;
if ( V_15 ) {
F_37 ( V_48 , L_16 ) ;
goto V_259;
}
V_30 -> V_253 . V_252 = V_251 -> V_252 ;
V_30 -> V_253 . V_254 = V_251 -> V_254 ;
return 0 ;
V_259:
V_132 = F_111 ( V_30 ) ;
F_109 ( V_30 , V_48 -> V_44 , V_132 ) ;
return V_15 ;
}
static T_4 F_174 ( const char * V_162 )
{
T_4 V_260 = F_175 ( V_162 ) ;
return F_176 ( V_260 ) ;
}
static void F_177 ( T_1 * * V_42 , int V_161 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_261 ; V_19 ++ ) {
snprintf ( * V_42 , V_262 , L_17 ,
V_263 [ V_19 ] . V_264 , V_161 ) ;
* V_42 += V_262 ;
}
}
static void F_178 ( T_1 * * V_42 , int V_230 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_265 ; V_19 ++ ) {
snprintf ( * V_42 , V_262 , L_17 ,
V_266 [ V_19 ] . V_264 , V_230 ) ;
* V_42 += V_262 ;
}
}
static void F_179 ( struct V_114 * V_48 ,
T_5 V_267 , T_1 * V_268 )
{
T_1 * V_42 = V_268 ;
int V_19 ;
switch ( V_267 ) {
case V_269 :
for ( V_19 = 0 ; V_19 < V_270 ; V_19 ++ ) {
memcpy ( V_42 , V_271 [ V_19 ] . V_264 ,
V_262 ) ;
V_42 += V_262 ;
}
for ( V_19 = 0 ; V_19 < V_143 ; V_19 ++ )
F_177 ( & V_42 , V_19 ) ;
for ( V_19 = 0 ; V_19 < V_143 ; V_19 ++ )
F_178 ( & V_42 , V_19 ) ;
break;
}
}
static int F_180 ( struct V_114 * V_48 ,
enum V_272 V_273 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
char V_274 [ V_275 ] ;
bool V_276 ;
switch ( V_273 ) {
case V_277 :
V_276 = true ;
break;
case V_278 :
V_276 = false ;
break;
default:
return - V_279 ;
}
F_181 ( V_274 , V_30 -> V_10 , V_276 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_280 ) , V_274 ) ;
}
static int
F_182 ( struct V_271 * * V_281 ,
int * V_282 , enum V_283 V_160 )
{
switch ( V_160 ) {
case V_165 :
* V_281 = V_271 ;
* V_282 = V_270 ;
break;
case V_284 :
* V_281 = V_263 ;
* V_282 = V_261 ;
break;
case V_285 :
* V_281 = V_266 ;
* V_282 = V_265 ;
break;
default:
F_30 ( 1 ) ;
return - V_216 ;
}
return 0 ;
}
static void F_183 ( struct V_114 * V_48 ,
enum V_283 V_160 , int V_161 ,
T_4 * V_268 , int V_286 )
{
struct V_271 * V_174 ;
char V_162 [ V_164 ] ;
int V_19 , V_118 ;
int V_15 ;
V_15 = F_182 ( & V_174 , & V_118 , V_160 ) ;
if ( V_15 )
return;
F_119 ( V_48 , V_160 , V_161 , V_162 ) ;
for ( V_19 = 0 ; V_19 < V_118 ; V_19 ++ )
V_268 [ V_286 + V_19 ] = V_174 [ V_19 ] . F_184 ( V_162 ) ;
}
static void F_185 ( struct V_114 * V_48 ,
struct V_287 * V_153 , T_4 * V_268 )
{
int V_19 , V_286 = 0 ;
F_183 ( V_48 , V_165 , 0 ,
V_268 , V_286 ) ;
V_286 = V_270 ;
for ( V_19 = 0 ; V_19 < V_143 ; V_19 ++ ) {
F_183 ( V_48 , V_284 , V_19 ,
V_268 , V_286 ) ;
V_286 += V_261 ;
}
for ( V_19 = 0 ; V_19 < V_143 ; V_19 ++ ) {
F_183 ( V_48 , V_285 , V_19 ,
V_268 , V_286 ) ;
V_286 += V_265 ;
}
}
static int F_186 ( struct V_114 * V_48 , int V_288 )
{
switch ( V_288 ) {
case V_269 :
return V_289 ;
default:
return - V_279 ;
}
}
static void
F_187 ( T_5 V_290 ,
struct V_291 * V_292 )
{
if ( V_290 & ( V_293 |
V_294 |
V_295 |
V_296 |
V_297 |
V_298 ) )
F_188 ( V_292 , V_299 , V_300 ) ;
if ( V_290 & ( V_301 |
V_302 |
V_303 |
V_304 |
V_305 ) )
F_188 ( V_292 , V_299 , V_306 ) ;
}
static void F_189 ( T_5 V_290 , unsigned long * V_307 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_308 ; V_19 ++ ) {
if ( V_290 & V_309 [ V_19 ] . V_310 )
F_190 ( V_309 [ V_19 ] . V_311 ,
V_307 ) ;
}
}
static void F_191 ( bool V_312 , T_5 V_290 ,
struct V_291 * V_292 )
{
T_5 V_313 = V_314 ;
T_1 V_315 = V_316 ;
int V_19 ;
if ( ! V_312 )
goto V_166;
for ( V_19 = 0 ; V_19 < V_308 ; V_19 ++ ) {
if ( V_290 & V_309 [ V_19 ] . V_310 ) {
V_313 = V_309 [ V_19 ] . V_313 ;
V_315 = V_317 ;
break;
}
}
V_166:
V_292 -> V_318 . V_313 = V_313 ;
V_292 -> V_318 . V_315 = V_315 ;
}
static T_1 F_192 ( T_5 V_290 )
{
if ( V_290 & ( V_294 |
V_296 |
V_297 |
V_298 ) )
return V_319 ;
if ( V_290 & ( V_293 |
V_295 |
V_320 ) )
return V_321 ;
if ( V_290 & ( V_301 |
V_302 |
V_303 |
V_304 ) )
return V_322 ;
return V_323 ;
}
static T_5
F_193 ( const struct V_291 * V_292 )
{
T_5 V_324 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_308 ; V_19 ++ ) {
if ( F_194 ( V_309 [ V_19 ] . V_311 ,
V_292 -> V_325 . V_326 ) )
V_324 |= V_309 [ V_19 ] . V_310 ;
}
return V_324 ;
}
static T_5 F_195 ( T_5 V_313 )
{
T_5 V_324 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_308 ; V_19 ++ ) {
if ( V_313 == V_309 [ V_19 ] . V_313 )
V_324 |= V_309 [ V_19 ] . V_310 ;
}
return V_324 ;
}
static T_5 F_196 ( T_5 V_327 )
{
T_5 V_324 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_308 ; V_19 ++ ) {
if ( V_309 [ V_19 ] . V_313 <= V_327 )
V_324 |= V_309 [ V_19 ] . V_310 ;
}
return V_324 ;
}
static void F_197 ( T_5 V_328 ,
struct V_291 * V_292 )
{
F_188 ( V_292 , V_299 , V_329 ) ;
F_188 ( V_292 , V_299 , V_330 ) ;
F_188 ( V_292 , V_299 , V_331 ) ;
F_187 ( V_328 , V_292 ) ;
F_189 ( V_328 , V_292 -> V_325 . V_299 ) ;
}
static void F_198 ( T_5 V_332 , bool V_258 ,
struct V_291 * V_292 )
{
if ( ! V_258 )
return;
F_188 ( V_292 , V_326 , V_330 ) ;
F_189 ( V_332 , V_292 -> V_325 . V_326 ) ;
}
static void
F_199 ( T_5 V_333 , T_1 V_334 ,
struct V_291 * V_292 )
{
if ( V_334 != V_335 || ! V_333 )
return;
F_188 ( V_292 , V_336 , V_330 ) ;
F_189 ( V_333 , V_292 -> V_325 . V_336 ) ;
}
static int F_200 ( struct V_114 * V_48 ,
struct V_291 * V_292 )
{
T_5 V_328 , V_332 , V_337 , V_333 ;
struct V_30 * V_30 = F_82 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
char V_338 [ V_339 ] ;
T_1 V_334 ;
bool V_258 ;
int V_15 ;
V_258 = V_30 -> V_253 . V_258 ;
F_201 ( V_338 , V_30 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_340 ) , V_338 ) ;
if ( V_15 )
return V_15 ;
F_202 ( V_338 , & V_328 , & V_332 ,
& V_337 ) ;
F_197 ( V_328 , V_292 ) ;
F_198 ( V_332 , V_258 , V_292 ) ;
V_333 = F_203 ( V_338 ) ;
V_334 = F_204 ( V_338 ) ;
F_199 ( V_333 , V_334 , V_292 ) ;
V_292 -> V_318 . V_258 = V_258 ? V_341 : V_342 ;
V_292 -> V_318 . V_31 = F_192 ( V_337 ) ;
F_191 ( F_134 ( V_48 ) , V_337 ,
V_292 ) ;
return 0 ;
}
static int
F_205 ( struct V_114 * V_48 ,
const struct V_291 * V_292 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
struct V_12 * V_12 = V_30 -> V_12 ;
char V_338 [ V_339 ] ;
T_5 V_328 , V_343 ;
bool V_258 ;
int V_15 ;
F_201 ( V_338 , V_30 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_340 ) , V_338 ) ;
if ( V_15 )
return V_15 ;
F_202 ( V_338 , & V_328 , NULL , NULL ) ;
V_258 = V_292 -> V_318 . V_258 == V_341 ;
V_343 = V_258 ?
F_193 ( V_292 ) :
F_195 ( V_292 -> V_318 . V_313 ) ;
V_343 = V_343 & V_328 ;
if ( ! V_343 ) {
F_37 ( V_48 , L_18 ) ;
return - V_79 ;
}
F_201 ( V_338 , V_30 -> V_10 ,
V_343 ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_340 ) , V_338 ) ;
if ( V_15 )
return V_15 ;
if ( ! F_206 ( V_48 ) )
return 0 ;
V_30 -> V_253 . V_258 = V_258 ;
F_48 ( V_30 , false ) ;
F_48 ( V_30 , true ) ;
return 0 ;
}
static int
F_207 ( struct V_30 * V_30 , T_1 V_112 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
T_5 V_327 = V_344 * V_112 ;
char V_338 [ V_339 ] ;
T_5 V_332 ;
V_332 = F_196 ( V_327 ) ;
F_201 ( V_338 , V_30 -> V_10 ,
V_332 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_340 ) , V_338 ) ;
}
int F_208 ( struct V_30 * V_30 ,
enum V_345 V_346 , T_1 V_35 , T_1 V_347 ,
bool V_348 , T_1 V_349 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_350 [ V_351 ] ;
F_209 ( V_350 , V_30 -> V_10 , V_346 , V_35 ,
V_347 ) ;
F_210 ( V_350 , true ) ;
F_211 ( V_350 , V_348 ) ;
F_212 ( V_350 , V_349 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_352 ) , V_350 ) ;
}
int F_213 ( struct V_30 * V_30 ,
enum V_345 V_346 , T_1 V_35 ,
T_1 V_347 , T_5 V_353 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_350 [ V_351 ] ;
F_209 ( V_350 , V_30 -> V_10 , V_346 , V_35 ,
V_347 ) ;
F_214 ( V_350 , true ) ;
F_215 ( V_350 , V_353 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_352 ) , V_350 ) ;
}
int F_216 ( struct V_30 * V_30 ,
T_1 V_354 , T_1 V_355 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_356 [ V_357 ] ;
F_217 ( V_356 , V_30 -> V_10 , V_354 ,
V_355 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_358 ) , V_356 ) ;
}
static int F_218 ( struct V_30 * V_30 )
{
int V_15 , V_19 ;
V_15 = F_208 ( V_30 ,
V_359 , 0 , 0 , false ,
0 ) ;
if ( V_15 )
return V_15 ;
for ( V_19 = 0 ; V_19 < V_143 ; V_19 ++ ) {
V_15 = F_208 ( V_30 ,
V_360 , V_19 ,
0 , false , 0 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_19 = 0 ; V_19 < V_143 ; V_19 ++ ) {
V_15 = F_208 ( V_30 ,
V_361 , V_19 , V_19 ,
false , 0 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = F_213 ( V_30 ,
V_362 , 0 , 0 ,
V_363 ) ;
if ( V_15 )
return V_15 ;
for ( V_19 = 0 ; V_19 < V_143 ; V_19 ++ ) {
V_15 = F_213 ( V_30 ,
V_360 ,
V_19 , 0 ,
V_363 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_19 = 0 ; V_19 < V_143 ; V_19 ++ ) {
V_15 = F_213 ( V_30 ,
V_361 ,
V_19 , V_19 ,
V_363 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_19 = 0 ; V_19 < V_143 ; V_19 ++ ) {
V_15 = F_216 ( V_30 , V_19 , 0 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_219 ( struct V_30 * V_30 )
{
V_30 -> V_364 = 1 ;
return F_145 ( V_30 -> V_48 , 0 , 1 ) ;
}
static int F_220 ( struct V_30 * V_30 )
{
return F_148 ( V_30 -> V_48 , 0 , 1 ) ;
}
static int F_221 ( struct V_12 * V_12 , T_1 V_10 ,
bool V_202 , T_1 V_111 , T_1 V_112 , T_1 V_113 )
{
struct V_30 * V_30 ;
struct V_114 * V_48 ;
T_8 V_365 ;
int V_15 ;
V_48 = F_222 ( sizeof( struct V_30 ) ) ;
if ( ! V_48 )
return - V_27 ;
F_223 ( V_48 , V_12 -> V_244 -> V_48 ) ;
V_30 = F_82 ( V_48 ) ;
V_30 -> V_48 = V_48 ;
V_30 -> V_12 = V_12 ;
V_30 -> V_10 = V_10 ;
V_30 -> V_202 = V_202 ;
V_30 -> V_201 . V_111 = V_111 ;
V_30 -> V_201 . V_112 = V_112 ;
V_30 -> V_201 . V_113 = V_113 ;
V_30 -> V_253 . V_258 = 1 ;
V_365 = F_224 ( V_186 , V_366 ) ;
V_30 -> V_367 = F_41 ( V_365 , V_26 ) ;
if ( ! V_30 -> V_367 ) {
V_15 = - V_27 ;
goto V_368;
}
V_30 -> V_369 = F_41 ( V_365 , V_26 ) ;
if ( ! V_30 -> V_369 ) {
V_15 = - V_27 ;
goto V_370;
}
F_18 ( & V_30 -> V_193 ) ;
F_18 ( & V_30 -> V_220 ) ;
V_30 -> V_116 =
F_225 ( struct V_115 ) ;
if ( ! V_30 -> V_116 ) {
V_15 = - V_27 ;
goto V_371;
}
V_30 -> V_174 . V_176 =
F_41 ( sizeof( * V_30 -> V_174 . V_176 ) , V_26 ) ;
if ( ! V_30 -> V_174 . V_176 ) {
V_15 = - V_27 ;
goto V_372;
}
F_226 ( & V_30 -> V_174 . V_175 ,
& F_132 ) ;
V_48 -> V_373 = & V_374 ;
V_48 -> V_375 = & V_376 ;
V_15 = F_60 ( V_30 , 0 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_19 ,
V_30 -> V_10 ) ;
goto V_377;
}
V_15 = F_53 ( V_30 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_20 ,
V_30 -> V_10 ) ;
goto V_378;
}
F_228 ( V_48 ) ;
V_48 -> V_379 |= V_380 | V_381 | V_382 |
V_383 | V_384 ;
V_48 -> V_385 |= V_384 ;
V_48 -> V_386 = 0 ;
V_48 -> V_76 = V_387 ;
V_48 -> V_388 = V_6 ;
V_15 = F_69 ( V_30 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_21 ,
V_30 -> V_10 ) ;
goto V_389;
}
V_15 = F_207 ( V_30 , V_112 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_22 ,
V_30 -> V_10 ) ;
goto V_390;
}
V_15 = F_55 ( V_30 , V_391 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_23 ,
V_30 -> V_10 ) ;
goto V_151;
}
V_15 = F_48 ( V_30 , false ) ;
if ( V_15 )
goto V_392;
V_15 = F_229 ( V_30 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_24 ,
V_30 -> V_10 ) ;
goto V_393;
}
V_15 = F_218 ( V_30 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_25 ,
V_30 -> V_10 ) ;
goto V_394;
}
V_15 = F_230 ( V_30 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_26 ,
V_30 -> V_10 ) ;
goto V_395;
}
V_15 = F_219 ( V_30 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_27 ,
V_30 -> V_10 ) ;
goto V_396;
}
F_231 ( V_30 ) ;
V_12 -> V_227 [ V_10 ] = V_30 ;
V_15 = F_232 ( V_48 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_28 ,
V_30 -> V_10 ) ;
goto V_397;
}
F_233 ( V_12 -> V_16 , V_30 -> V_10 ,
V_30 , V_48 , V_30 -> V_202 ,
V_111 ) ;
F_135 ( & V_30 -> V_174 . V_175 , 0 ) ;
return 0 ;
V_397:
V_12 -> V_227 [ V_10 ] = NULL ;
F_234 ( V_30 ) ;
F_220 ( V_30 ) ;
V_396:
F_235 ( V_30 ) ;
V_395:
V_394:
V_393:
V_392:
V_151:
V_390:
V_389:
V_378:
F_60 ( V_30 , V_398 ) ;
V_377:
F_22 ( V_30 -> V_174 . V_176 ) ;
V_372:
F_236 ( V_30 -> V_116 ) ;
V_371:
F_22 ( V_30 -> V_369 ) ;
V_370:
F_22 ( V_30 -> V_367 ) ;
V_368:
F_237 ( V_48 ) ;
return V_15 ;
}
static int F_238 ( struct V_12 * V_12 , T_1 V_10 ,
bool V_202 , T_1 V_111 , T_1 V_112 , T_1 V_113 )
{
int V_15 ;
V_15 = F_239 ( V_12 -> V_16 , V_10 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_29 ,
V_10 ) ;
return V_15 ;
}
V_15 = F_221 ( V_12 , V_10 , V_202 ,
V_111 , V_112 , V_113 ) ;
if ( V_15 )
goto V_399;
return 0 ;
V_399:
F_240 ( V_12 -> V_16 , V_10 ) ;
return V_15 ;
}
static void F_241 ( struct V_12 * V_12 , T_1 V_10 )
{
struct V_30 * V_30 = V_12 -> V_227 [ V_10 ] ;
F_242 ( & V_30 -> V_174 . V_175 ) ;
F_243 ( V_12 -> V_16 , V_10 , V_12 ) ;
F_244 ( V_30 -> V_48 ) ;
V_12 -> V_227 [ V_10 ] = NULL ;
F_234 ( V_30 ) ;
F_220 ( V_30 ) ;
F_235 ( V_30 ) ;
F_60 ( V_30 , V_398 ) ;
F_80 ( V_12 , V_30 -> V_10 ) ;
F_236 ( V_30 -> V_116 ) ;
F_22 ( V_30 -> V_174 . V_176 ) ;
F_22 ( V_30 -> V_369 ) ;
F_22 ( V_30 -> V_367 ) ;
F_20 ( ! F_21 ( & V_30 -> V_193 ) ) ;
F_237 ( V_30 -> V_48 ) ;
}
static void F_245 ( struct V_12 * V_12 , T_1 V_10 )
{
F_241 ( V_12 , V_10 ) ;
F_240 ( V_12 -> V_16 , V_10 ) ;
}
static bool F_246 ( struct V_12 * V_12 , T_1 V_10 )
{
return V_12 -> V_227 [ V_10 ] != NULL ;
}
static void F_247 ( struct V_12 * V_12 )
{
int V_19 ;
for ( V_19 = 1 ; V_19 < V_400 ; V_19 ++ )
if ( F_246 ( V_12 , V_19 ) )
F_245 ( V_12 , V_19 ) ;
F_22 ( V_12 -> V_227 ) ;
}
static int F_248 ( struct V_12 * V_12 )
{
T_1 V_111 , V_112 , V_113 ;
T_8 V_401 ;
int V_19 ;
int V_15 ;
V_401 = sizeof( struct V_30 * ) * V_400 ;
V_12 -> V_227 = F_41 ( V_401 , V_26 ) ;
if ( ! V_12 -> V_227 )
return - V_27 ;
for ( V_19 = 1 ; V_19 < V_400 ; V_19 ++ ) {
V_15 = F_71 ( V_12 , V_19 , & V_111 ,
& V_112 , & V_113 ) ;
if ( V_15 )
goto V_402;
if ( ! V_112 )
continue;
V_12 -> V_403 [ V_19 ] = V_111 ;
V_15 = F_238 ( V_12 , V_19 , false ,
V_111 , V_112 , V_113 ) ;
if ( V_15 )
goto V_399;
}
return 0 ;
V_399:
V_402:
for ( V_19 -- ; V_19 >= 1 ; V_19 -- )
if ( F_246 ( V_12 , V_19 ) )
F_245 ( V_12 , V_19 ) ;
F_22 ( V_12 -> V_227 ) ;
return V_15 ;
}
static T_1 F_249 ( T_1 V_10 )
{
T_1 V_404 = ( V_10 - 1 ) % V_405 ;
return V_10 - V_404 ;
}
static int F_250 ( struct V_12 * V_12 , T_1 V_406 ,
T_1 V_111 , unsigned int V_407 )
{
T_1 V_112 = V_408 / V_407 ;
int V_15 , V_19 ;
for ( V_19 = 0 ; V_19 < V_407 ; V_19 ++ ) {
V_15 = F_76 ( V_12 , V_406 + V_19 , V_111 ,
V_112 , V_19 * V_112 ) ;
if ( V_15 )
goto V_409;
}
for ( V_19 = 0 ; V_19 < V_407 ; V_19 ++ ) {
V_15 = F_58 ( V_12 , V_406 + V_19 , 0 ) ;
if ( V_15 )
goto V_377;
}
for ( V_19 = 0 ; V_19 < V_407 ; V_19 ++ ) {
V_15 = F_238 ( V_12 , V_406 + V_19 , true ,
V_111 , V_112 , V_19 * V_112 ) ;
if ( V_15 )
goto V_399;
}
return 0 ;
V_399:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- )
if ( F_246 ( V_12 , V_406 + V_19 ) )
F_245 ( V_12 , V_406 + V_19 ) ;
V_19 = V_407 ;
V_377:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- )
F_58 ( V_12 , V_406 + V_19 ,
V_398 ) ;
V_19 = V_407 ;
V_409:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- )
F_80 ( V_12 , V_406 + V_19 ) ;
return V_15 ;
}
static void F_251 ( struct V_12 * V_12 ,
T_1 V_406 , unsigned int V_407 )
{
T_1 V_10 , V_111 , V_112 = V_408 ;
int V_19 ;
V_407 = V_407 / 2 ;
for ( V_19 = 0 ; V_19 < V_407 ; V_19 ++ ) {
V_10 = V_406 + V_19 * 2 ;
V_111 = V_12 -> V_403 [ V_10 ] ;
F_76 ( V_12 , V_10 , V_111 , V_112 ,
0 ) ;
}
for ( V_19 = 0 ; V_19 < V_407 ; V_19 ++ )
F_58 ( V_12 , V_406 + V_19 * 2 , 0 ) ;
for ( V_19 = 0 ; V_19 < V_407 ; V_19 ++ ) {
V_10 = V_406 + V_19 * 2 ;
V_111 = V_12 -> V_403 [ V_10 ] ;
F_238 ( V_12 , V_10 , false , V_111 ,
V_112 , 0 ) ;
}
}
static int F_252 ( struct V_410 * V_410 , T_1 V_10 ,
unsigned int V_407 )
{
struct V_12 * V_12 = F_253 ( V_410 ) ;
struct V_30 * V_30 ;
T_1 V_111 , V_411 , V_406 ;
int V_19 ;
int V_15 ;
V_30 = V_12 -> V_227 [ V_10 ] ;
if ( ! V_30 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_30 ,
V_10 ) ;
return - V_79 ;
}
V_111 = V_30 -> V_201 . V_111 ;
V_411 = V_30 -> V_201 . V_112 ;
if ( V_407 != 2 && V_407 != 4 ) {
F_37 ( V_30 -> V_48 , L_31 ) ;
return - V_79 ;
}
if ( V_411 != V_408 ) {
F_37 ( V_30 -> V_48 , L_32 ) ;
return - V_79 ;
}
if ( V_407 == 2 ) {
V_406 = V_10 ;
if ( V_12 -> V_227 [ V_406 + 1 ] ) {
F_37 ( V_30 -> V_48 , L_33 ) ;
return - V_79 ;
}
} else {
V_406 = F_249 ( V_10 ) ;
if ( V_12 -> V_227 [ V_406 + 1 ] ||
V_12 -> V_227 [ V_406 + 3 ] ) {
F_37 ( V_30 -> V_48 , L_33 ) ;
return - V_79 ;
}
}
for ( V_19 = 0 ; V_19 < V_407 ; V_19 ++ )
if ( F_246 ( V_12 , V_406 + V_19 ) )
F_245 ( V_12 , V_406 + V_19 ) ;
V_15 = F_250 ( V_12 , V_406 , V_111 , V_407 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_34 ) ;
goto V_412;
}
return 0 ;
V_412:
F_251 ( V_12 , V_406 , V_407 ) ;
return V_15 ;
}
static int F_254 ( struct V_410 * V_410 , T_1 V_10 )
{
struct V_12 * V_12 = F_253 ( V_410 ) ;
struct V_30 * V_30 ;
T_1 V_411 , V_406 ;
unsigned int V_407 ;
int V_19 ;
V_30 = V_12 -> V_227 [ V_10 ] ;
if ( ! V_30 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_30 ,
V_10 ) ;
return - V_79 ;
}
if ( ! V_30 -> V_202 ) {
F_37 ( V_30 -> V_48 , L_35 ) ;
return - V_79 ;
}
V_411 = V_30 -> V_201 . V_112 ;
V_407 = V_411 == 1 ? 4 : 2 ;
V_406 = F_249 ( V_10 ) ;
if ( V_407 == 2 && V_10 >= V_406 + 2 )
V_406 = V_406 + 2 ;
for ( V_19 = 0 ; V_19 < V_407 ; V_19 ++ )
if ( F_246 ( V_12 , V_406 + V_19 ) )
F_245 ( V_12 , V_406 + V_19 ) ;
F_251 ( V_12 , V_406 , V_407 ) ;
return 0 ;
}
static void F_255 ( const struct V_413 * V_414 ,
char * V_415 , void * V_416 )
{
struct V_12 * V_12 = V_416 ;
struct V_30 * V_30 ;
enum V_417 V_418 ;
T_1 V_10 ;
V_10 = F_256 ( V_415 ) ;
V_30 = V_12 -> V_227 [ V_10 ] ;
if ( ! V_30 )
return;
V_418 = F_257 ( V_415 ) ;
if ( V_418 == V_419 ) {
F_258 ( V_30 -> V_48 , L_36 ) ;
F_259 ( V_30 -> V_48 ) ;
} else {
F_258 ( V_30 -> V_48 , L_37 ) ;
F_228 ( V_30 -> V_48 ) ;
}
}
static void F_260 ( struct V_1 * V_2 ,
T_1 V_10 , void * V_416 )
{
struct V_12 * V_12 = V_416 ;
struct V_30 * V_30 = V_12 -> V_227 [ V_10 ] ;
struct V_115 * V_116 ;
if ( F_88 ( ! V_30 ) ) {
F_261 ( V_12 -> V_244 -> V_48 , L_38 ,
V_10 ) ;
return;
}
V_2 -> V_48 = V_30 -> V_48 ;
V_116 = F_96 ( V_30 -> V_116 ) ;
F_97 ( & V_116 -> V_123 ) ;
V_116 -> V_154 ++ ;
V_116 -> V_155 += V_2 -> V_118 ;
F_98 ( & V_116 -> V_123 ) ;
V_2 -> V_223 = F_262 ( V_2 , V_2 -> V_48 ) ;
F_263 ( V_2 ) ;
}
static void F_264 ( struct V_1 * V_2 , T_1 V_10 ,
void * V_416 )
{
V_2 -> V_420 = 1 ;
return F_260 ( V_2 , V_10 , V_416 ) ;
}
static int F_265 ( struct V_410 * V_410 )
{
char V_421 [ V_422 ] ;
enum V_423 V_424 ;
int V_425 ;
bool V_426 ;
T_1 V_427 ;
T_5 V_428 ;
int V_19 , V_15 ;
if ( ! F_15 ( V_410 , V_429 ) )
return - V_21 ;
V_425 = F_16 ( V_410 , V_429 ) ;
V_424 = V_430 ;
for ( V_19 = 0 ; V_19 < V_425 ; V_19 ++ ) {
V_426 = false ;
switch ( V_19 ) {
case V_431 :
case V_432 :
case V_433 :
case V_434 :
V_428 = 128 ;
V_427 = 7 ;
break;
case V_435 :
V_428 = 16 * 1024 ;
V_427 = 10 ;
break;
case V_436 :
case V_437 :
case V_438 :
case V_439 :
case V_440 :
case V_441 :
V_428 = 1024 ;
V_427 = 7 ;
break;
case V_442 :
V_426 = true ;
V_428 = 4 * 1024 ;
V_427 = 4 ;
break;
default:
continue;
}
F_266 ( V_421 , V_19 , V_424 , V_426 , V_428 ,
V_427 ) ;
V_15 = F_25 ( V_410 , F_12 ( V_443 ) , V_421 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_267 ( struct V_410 * V_410 )
{
char V_444 [ V_445 ] ;
enum V_446 V_19 ;
int V_425 ;
int V_447 ;
T_1 V_448 , V_230 ;
T_2 V_449 ;
int V_15 ;
if ( ! F_15 ( V_410 , V_450 ) )
return - V_21 ;
V_447 = F_16 ( V_410 , V_450 ) ;
V_425 = F_16 ( V_410 , V_429 ) ;
for ( V_19 = 0 ; V_19 < V_447 ; V_19 ++ ) {
V_449 = V_19 ;
switch ( V_19 ) {
case V_431 :
case V_432 :
case V_433 :
case V_434 :
V_448 = 5 ;
V_230 = 5 ;
break;
case V_436 :
case V_438 :
V_448 = 4 ;
V_230 = 4 ;
break;
case V_435 :
case V_442 :
V_448 = 3 ;
V_230 = 3 ;
break;
case V_437 :
V_448 = 2 ;
V_230 = 2 ;
break;
case V_439 :
case V_440 :
case V_441 :
V_448 = 1 ;
V_230 = 1 ;
break;
case V_451 :
V_448 = V_452 ;
V_230 = V_453 ;
V_449 = V_454 ;
break;
default:
continue;
}
if ( V_425 <= V_449 &&
V_449 != V_454 )
return - V_21 ;
F_268 ( V_444 , V_19 , V_449 , V_448 , V_230 ) ;
V_15 = F_25 ( V_410 , F_12 ( V_455 ) , V_444 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_269 ( struct V_12 * V_12 )
{
int V_19 ;
int V_15 ;
V_15 = F_265 ( V_12 -> V_16 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_267 ( V_12 -> V_16 ) ;
if ( V_15 )
return V_15 ;
for ( V_19 = 0 ; V_19 < F_270 ( V_456 ) ; V_19 ++ ) {
V_15 = F_271 ( V_12 -> V_16 ,
& V_456 [ V_19 ] ,
V_12 ) ;
if ( V_15 )
goto V_457;
}
return 0 ;
V_457:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- ) {
F_272 ( V_12 -> V_16 ,
& V_456 [ V_19 ] ,
V_12 ) ;
}
return V_15 ;
}
static void F_273 ( struct V_12 * V_12 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_270 ( V_456 ) ; V_19 ++ ) {
F_272 ( V_12 -> V_16 ,
& V_456 [ V_19 ] ,
V_12 ) ;
}
}
static int F_274 ( struct V_410 * V_410 ,
enum V_458 type ,
enum V_459 V_460 )
{
enum V_461 V_462 ;
enum V_463 V_464 ;
char V_465 [ V_466 ] ;
if ( V_460 == V_467 )
V_462 = V_468 ;
else
V_462 = V_469 ;
if ( type == V_470 )
V_464 = V_471 ;
else
V_464 = V_472 ;
F_275 ( V_465 , type , V_460 , V_462 ,
V_464 ) ;
return F_25 ( V_410 , F_12 ( V_473 ) , V_465 ) ;
}
static int F_276 ( struct V_12 * V_12 )
{
int type , V_15 ;
for ( type = 0 ; type < V_474 ; type ++ ) {
if ( type == V_475 )
continue;
V_15 = F_274 ( V_12 -> V_16 , type ,
V_467 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_274 ( V_12 -> V_16 , type ,
V_476 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_277 ( struct V_12 * V_12 )
{
char V_477 [ V_478 ] ;
int V_15 ;
F_278 ( V_477 , V_479 |
V_480 |
V_481 |
V_482 |
V_483 |
V_484 |
V_485 |
V_486 |
V_487 ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_488 ) , V_477 ) ;
if ( V_15 )
return V_15 ;
if ( ! F_15 ( V_12 -> V_16 , V_489 ) ||
! F_15 ( V_12 -> V_16 , V_490 ) )
return - V_21 ;
V_12 -> V_491 = F_17 ( F_16 ( V_12 -> V_16 , V_489 ) ,
sizeof( struct V_492 ) ,
V_26 ) ;
if ( ! V_12 -> V_491 )
return - V_27 ;
return 0 ;
}
static void F_279 ( struct V_12 * V_12 )
{
F_22 ( V_12 -> V_491 ) ;
}
static int F_280 ( struct V_410 * V_410 )
{
char V_444 [ V_445 ] ;
F_268 ( V_444 , V_493 ,
V_454 ,
V_452 ,
V_453 ) ;
return F_25 ( V_410 , F_12 ( V_455 ) , V_444 ) ;
}
static int F_281 ( struct V_410 * V_410 ,
const struct V_494 * V_494 )
{
struct V_12 * V_12 = F_253 ( V_410 ) ;
int V_15 ;
V_12 -> V_16 = V_410 ;
V_12 -> V_244 = V_494 ;
F_18 ( & V_12 -> V_495 ) ;
F_18 ( & V_12 -> V_496 . V_57 ) ;
F_18 ( & V_12 -> V_497 . V_57 ) ;
V_15 = F_10 ( V_12 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_39 ) ;
return V_15 ;
}
V_15 = F_269 ( V_12 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_40 ) ;
return V_15 ;
}
V_15 = F_276 ( V_12 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_41 ) ;
goto V_498;
}
V_15 = F_282 ( V_12 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_42 ) ;
goto V_499;
}
V_15 = F_277 ( V_12 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_43 ) ;
goto V_500;
}
V_15 = F_283 ( V_12 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_44 ) ;
goto V_501;
}
V_15 = F_284 ( V_12 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_45 ) ;
goto V_502;
}
V_15 = F_14 ( V_12 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_46 ) ;
goto V_503;
}
V_15 = F_248 ( V_12 ) ;
if ( V_15 ) {
F_227 ( V_12 -> V_244 -> V_48 , L_47 ) ;
goto V_504;
}
return 0 ;
V_504:
F_19 ( V_12 ) ;
V_503:
F_285 ( V_12 ) ;
V_502:
F_286 ( V_12 ) ;
V_501:
F_279 ( V_12 ) ;
V_500:
F_287 ( V_12 ) ;
V_499:
V_498:
F_273 ( V_12 ) ;
return V_15 ;
}
static void F_288 ( struct V_410 * V_410 )
{
struct V_12 * V_12 = F_253 ( V_410 ) ;
F_247 ( V_12 ) ;
F_19 ( V_12 ) ;
F_285 ( V_12 ) ;
F_286 ( V_12 ) ;
F_279 ( V_12 ) ;
F_287 ( V_12 ) ;
F_273 ( V_12 ) ;
F_30 ( ! F_21 ( & V_12 -> V_496 . V_57 ) ) ;
F_30 ( ! F_21 ( & V_12 -> V_495 ) ) ;
}
static bool F_156 ( const struct V_114 * V_48 )
{
return V_48 -> V_373 == & V_374 ;
}
static int F_289 ( struct V_114 * V_505 , void * V_268 )
{
struct V_30 * * V_31 = V_268 ;
int V_506 = 0 ;
if ( F_156 ( V_505 ) ) {
* V_31 = F_82 ( V_505 ) ;
V_506 = 1 ;
}
return V_506 ;
}
static struct V_30 * F_290 ( struct V_114 * V_48 )
{
struct V_30 * V_31 ;
if ( F_156 ( V_48 ) )
return F_82 ( V_48 ) ;
V_31 = NULL ;
F_291 ( V_48 , F_289 , & V_31 ) ;
return V_31 ;
}
static struct V_12 * F_292 ( struct V_114 * V_48 )
{
struct V_30 * V_30 ;
V_30 = F_290 ( V_48 ) ;
return V_30 ? V_30 -> V_12 : NULL ;
}
static struct V_30 * F_293 ( struct V_114 * V_48 )
{
struct V_30 * V_31 ;
if ( F_156 ( V_48 ) )
return F_82 ( V_48 ) ;
V_31 = NULL ;
F_294 ( V_48 , F_289 , & V_31 ) ;
return V_31 ;
}
struct V_30 * F_295 ( struct V_114 * V_48 )
{
struct V_30 * V_30 ;
F_296 () ;
V_30 = F_293 ( V_48 ) ;
if ( V_30 )
F_297 ( V_30 -> V_48 ) ;
F_298 () ;
return V_30 ;
}
void F_299 ( struct V_30 * V_30 )
{
F_300 ( V_30 -> V_48 ) ;
}
static bool F_301 ( struct V_507 * V_508 ,
unsigned long V_509 )
{
switch ( V_509 ) {
case V_510 :
if ( ! V_508 )
return true ;
V_508 -> V_39 ++ ;
return false ;
case V_511 :
if ( V_508 && -- V_508 -> V_39 == 0 )
return true ;
return false ;
}
return false ;
}
static int F_302 ( struct V_12 * V_12 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_16 ( V_12 -> V_16 , V_512 ) ; V_19 ++ )
if ( ! V_12 -> V_513 [ V_19 ] )
return V_19 ;
return V_514 ;
}
static void F_303 ( struct V_30 * V_187 ,
bool * V_515 , T_2 * V_516 )
{
T_1 V_10 = V_187 -> V_10 ;
* V_515 = V_187 -> V_190 ;
* V_516 = * V_515 ? V_187 -> V_191 : V_10 ;
}
static int F_304 ( struct V_30 * V_187 ,
struct V_114 * V_517 , T_2 V_518 ,
bool V_519 )
{
struct V_12 * V_12 = V_187 -> V_12 ;
bool V_190 = V_187 -> V_190 ;
char V_520 [ V_521 ] ;
T_2 V_522 ;
F_305 ( V_520 , V_519 , V_523 , V_518 ,
V_517 -> V_44 , V_517 -> V_72 ) ;
F_303 ( V_187 , & V_190 , & V_522 ) ;
F_306 ( V_520 , V_190 , V_522 ,
F_307 ( V_187 ) ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_524 ) , V_520 ) ;
}
static struct V_197 *
F_308 ( T_2 V_91 , struct V_114 * V_517 )
{
struct V_197 * V_198 ;
V_198 = F_41 ( sizeof( * V_198 ) , V_26 ) ;
if ( ! V_198 )
return NULL ;
V_198 -> V_199 = V_525 ;
V_198 -> V_39 = 0 ;
V_198 -> V_48 = V_517 ;
V_198 -> V_91 = V_91 ;
return V_198 ;
}
static struct V_507 *
F_309 ( T_2 V_518 , struct V_114 * V_517 , struct V_197 * V_198 )
{
struct V_507 * V_508 ;
V_508 = F_41 ( sizeof( * V_508 ) , V_26 ) ;
if ( ! V_508 )
return NULL ;
F_54 ( V_508 -> V_68 , V_517 -> V_72 ) ;
V_508 -> V_44 = V_517 -> V_44 ;
V_508 -> V_39 = 1 ;
V_508 -> V_48 = V_517 ;
V_508 -> V_518 = V_518 ;
V_508 -> V_198 = V_198 ;
return V_508 ;
}
static struct V_507 *
F_310 ( struct V_30 * V_187 ,
struct V_114 * V_517 )
{
struct V_12 * V_12 = V_187 -> V_12 ;
struct V_197 * V_198 ;
struct V_507 * V_508 ;
T_2 V_91 , V_518 ;
int V_15 ;
V_518 = F_302 ( V_12 ) ;
if ( V_518 == V_514 )
return F_311 ( - V_526 ) ;
V_15 = F_304 ( V_187 , V_517 , V_518 , true ) ;
if ( V_15 )
return F_311 ( V_15 ) ;
V_91 = F_312 ( V_518 ) ;
V_15 = F_313 ( V_12 , V_517 -> V_72 , V_91 , true ) ;
if ( V_15 )
goto V_527;
V_198 = F_308 ( V_91 , V_517 ) ;
if ( ! V_198 ) {
V_15 = - V_27 ;
goto V_528;
}
V_508 = F_309 ( V_518 , V_517 , V_198 ) ;
if ( ! V_508 ) {
V_15 = - V_27 ;
goto V_529;
}
V_198 -> V_508 = V_508 ;
V_12 -> V_513 [ V_518 ] = V_508 ;
return V_508 ;
V_529:
F_22 ( V_198 ) ;
V_528:
F_313 ( V_12 , V_517 -> V_72 , V_91 , false ) ;
V_527:
F_304 ( V_187 , V_517 , V_518 , false ) ;
return F_311 ( V_15 ) ;
}
static void F_314 ( struct V_30 * V_187 ,
struct V_507 * V_508 )
{
struct V_12 * V_12 = V_187 -> V_12 ;
struct V_114 * V_517 = V_508 -> V_48 ;
struct V_197 * V_198 = V_508 -> V_198 ;
T_2 V_91 = V_198 -> V_91 ;
T_2 V_518 = V_508 -> V_518 ;
V_12 -> V_513 [ V_518 ] = NULL ;
V_198 -> V_508 = NULL ;
F_22 ( V_508 ) ;
F_22 ( V_198 ) ;
F_313 ( V_12 , V_517 -> V_72 , V_91 , false ) ;
F_304 ( V_187 , V_517 , V_518 , false ) ;
}
static int F_315 ( struct V_30 * V_187 ,
struct V_114 * V_517 )
{
struct V_12 * V_12 = V_187 -> V_12 ;
struct V_507 * V_508 ;
V_508 = F_316 ( V_12 , V_517 ) ;
if ( ! V_508 ) {
V_508 = F_310 ( V_187 , V_517 ) ;
if ( F_317 ( V_508 ) )
return F_318 ( V_508 ) ;
}
F_319 ( V_187 , V_508 -> V_198 ) ;
V_508 -> V_198 -> V_39 ++ ;
F_46 ( V_187 -> V_48 , L_48 , V_508 -> V_198 -> V_91 ) ;
return 0 ;
}
static void V_525 ( struct V_30 * V_187 )
{
struct V_197 * V_198 = F_149 ( V_187 ) ;
F_46 ( V_187 -> V_48 , L_49 , V_198 -> V_91 ) ;
F_319 ( V_187 , NULL ) ;
if ( -- V_198 -> V_39 == 0 )
F_314 ( V_187 , V_198 -> V_508 ) ;
}
static int F_320 ( struct V_114 * V_517 ,
struct V_114 * V_530 ,
unsigned long V_509 , T_2 V_92 )
{
struct V_30 * V_30 = F_82 ( V_530 ) ;
struct V_30 * V_187 ;
V_187 = F_146 ( V_30 , V_92 ) ;
if ( F_30 ( ! V_187 ) )
return - V_79 ;
switch ( V_509 ) {
case V_510 :
return F_315 ( V_187 , V_517 ) ;
case V_511 :
V_525 ( V_187 ) ;
break;
}
return 0 ;
}
static int F_321 ( struct V_114 * V_530 ,
unsigned long V_509 )
{
if ( F_322 ( V_530 ) || F_323 ( V_530 ) )
return 0 ;
return F_320 ( V_530 , V_530 , V_509 , 1 ) ;
}
static int F_324 ( struct V_114 * V_517 ,
struct V_114 * V_531 ,
unsigned long V_509 , T_2 V_92 )
{
struct V_114 * V_530 ;
struct V_532 * V_533 ;
int V_15 ;
F_325 (lag_dev, port_dev, iter) {
if ( F_156 ( V_530 ) ) {
V_15 = F_320 ( V_517 , V_530 ,
V_509 , V_92 ) ;
if ( V_15 )
return V_15 ;
}
}
return 0 ;
}
static int F_326 ( struct V_114 * V_531 ,
unsigned long V_509 )
{
if ( F_322 ( V_531 ) )
return 0 ;
return F_324 ( V_531 , V_531 , V_509 , 1 ) ;
}
static struct V_197 * F_327 ( struct V_12 * V_12 ,
struct V_114 * V_517 )
{
T_2 V_91 ;
if ( F_328 ( V_517 ) )
V_91 = F_329 ( V_517 ) ;
else if ( V_12 -> V_534 . V_48 == V_517 )
V_91 = 1 ;
else
return F_330 ( V_12 , V_517 ) ;
return F_331 ( V_12 , V_91 ) ;
}
static enum V_461 F_332 ( T_2 V_91 )
{
return F_333 ( V_91 ) ? V_468 :
V_469 ;
}
static T_2 F_334 ( T_2 V_91 )
{
return F_333 ( V_91 ) ? F_335 ( V_91 ) : V_91 ;
}
static int F_336 ( struct V_12 * V_12 , T_2 V_91 ,
bool V_535 )
{
enum V_461 V_462 ;
char * V_536 ;
T_2 V_35 ;
int V_15 ;
V_536 = F_66 ( V_537 , V_26 ) ;
if ( ! V_536 )
return - V_27 ;
V_462 = F_332 ( V_91 ) ;
V_35 = F_334 ( V_91 ) ;
F_337 ( V_536 , V_472 , V_35 , V_462 ,
1 , V_538 , V_535 ) ;
V_15 = F_25 ( V_12 -> V_16 , F_12 ( V_539 ) , V_536 ) ;
F_22 ( V_536 ) ;
return V_15 ;
}
static enum V_540 F_338 ( T_2 V_91 )
{
if ( F_333 ( V_91 ) )
return V_541 ;
else
return V_542 ;
}
static int F_339 ( struct V_12 * V_12 ,
struct V_114 * V_517 ,
T_2 V_91 , T_2 V_518 ,
bool V_519 )
{
enum V_540 V_543 ;
char V_520 [ V_521 ] ;
V_543 = F_338 ( V_91 ) ;
F_305 ( V_520 , V_519 , V_543 , V_518 , V_517 -> V_44 ,
V_517 -> V_72 ) ;
F_340 ( V_520 , V_543 , V_91 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_524 ) , V_520 ) ;
}
static int F_341 ( struct V_12 * V_12 ,
struct V_114 * V_517 ,
struct V_197 * V_198 )
{
struct V_507 * V_508 ;
T_2 V_518 ;
int V_15 ;
V_518 = F_302 ( V_12 ) ;
if ( V_518 == V_514 )
return - V_526 ;
V_15 = F_336 ( V_12 , V_198 -> V_91 , true ) ;
if ( V_15 )
return V_15 ;
V_15 = F_339 ( V_12 , V_517 , V_198 -> V_91 , V_518 , true ) ;
if ( V_15 )
goto V_544;
V_15 = F_313 ( V_12 , V_517 -> V_72 , V_198 -> V_91 , true ) ;
if ( V_15 )
goto V_527;
V_508 = F_309 ( V_518 , V_517 , V_198 ) ;
if ( ! V_508 ) {
V_15 = - V_27 ;
goto V_529;
}
V_198 -> V_508 = V_508 ;
V_12 -> V_513 [ V_518 ] = V_508 ;
F_46 ( V_517 , L_50 , V_518 ) ;
return 0 ;
V_529:
F_313 ( V_12 , V_517 -> V_72 , V_198 -> V_91 , false ) ;
V_527:
F_339 ( V_12 , V_517 , V_198 -> V_91 , V_518 , false ) ;
V_544:
F_336 ( V_12 , V_198 -> V_91 , false ) ;
return V_15 ;
}
void F_342 ( struct V_12 * V_12 ,
struct V_507 * V_508 )
{
struct V_114 * V_517 = V_508 -> V_48 ;
struct V_197 * V_198 = V_508 -> V_198 ;
T_2 V_518 = V_508 -> V_518 ;
V_12 -> V_513 [ V_518 ] = NULL ;
V_198 -> V_508 = NULL ;
F_22 ( V_508 ) ;
F_313 ( V_12 , V_517 -> V_72 , V_198 -> V_91 , false ) ;
F_339 ( V_12 , V_517 , V_198 -> V_91 , V_518 , false ) ;
F_336 ( V_12 , V_198 -> V_91 , false ) ;
F_46 ( V_517 , L_51 , V_518 ) ;
}
static int F_343 ( struct V_114 * V_517 ,
struct V_114 * V_545 ,
unsigned long V_509 )
{
struct V_12 * V_12 = F_292 ( V_517 ) ;
struct V_197 * V_198 ;
V_198 = F_327 ( V_12 , V_517 ) ;
if ( F_30 ( ! V_198 ) )
return - V_79 ;
switch ( V_509 ) {
case V_510 :
return F_341 ( V_12 , V_517 , V_198 ) ;
case V_511 :
F_342 ( V_12 , V_198 -> V_508 ) ;
break;
}
return 0 ;
}
static int F_344 ( struct V_114 * V_546 ,
unsigned long V_509 )
{
struct V_114 * V_547 = F_345 ( V_546 ) ;
struct V_12 * V_12 = F_292 ( V_546 ) ;
T_2 V_92 = F_329 ( V_546 ) ;
if ( F_156 ( V_547 ) )
return F_320 ( V_546 , V_547 , V_509 ,
V_92 ) ;
else if ( F_346 ( V_547 ) )
return F_324 ( V_546 , V_547 , V_509 ,
V_92 ) ;
else if ( F_347 ( V_547 ) &&
V_12 -> V_534 . V_48 == V_547 )
return F_343 ( V_546 , V_547 ,
V_509 ) ;
return 0 ;
}
static int F_348 ( struct V_548 * V_549 ,
unsigned long V_509 , void * V_550 )
{
struct V_551 * V_552 = (struct V_551 * ) V_550 ;
struct V_114 * V_48 = V_552 -> V_553 -> V_48 ;
struct V_12 * V_12 ;
struct V_507 * V_508 ;
int V_15 = 0 ;
V_12 = F_292 ( V_48 ) ;
if ( ! V_12 )
goto V_166;
V_508 = F_316 ( V_12 , V_48 ) ;
if ( ! F_301 ( V_508 , V_509 ) )
goto V_166;
if ( F_156 ( V_48 ) )
V_15 = F_321 ( V_48 , V_509 ) ;
else if ( F_346 ( V_48 ) )
V_15 = F_326 ( V_48 , V_509 ) ;
else if ( F_347 ( V_48 ) )
V_15 = F_343 ( V_48 , V_48 , V_509 ) ;
else if ( F_328 ( V_48 ) )
V_15 = F_344 ( V_48 , V_509 ) ;
V_166:
return F_349 ( V_15 ) ;
}
static int F_350 ( struct V_12 * V_12 , T_2 V_518 ,
const char * V_554 , int V_44 )
{
char V_520 [ V_521 ] ;
int V_15 ;
F_351 ( V_520 , V_518 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_524 ) , V_520 ) ;
if ( V_15 )
return V_15 ;
F_352 ( V_520 , V_44 ) ;
F_353 ( V_520 , V_554 ) ;
F_354 ( V_520 , V_555 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_524 ) , V_520 ) ;
}
static int F_355 ( struct V_114 * V_48 )
{
struct V_12 * V_12 ;
struct V_507 * V_508 ;
int V_15 ;
V_12 = F_292 ( V_48 ) ;
if ( ! V_12 )
return 0 ;
V_508 = F_316 ( V_12 , V_48 ) ;
if ( ! V_508 )
return 0 ;
V_15 = F_313 ( V_12 , V_508 -> V_68 , V_508 -> V_198 -> V_91 , false ) ;
if ( V_15 )
return V_15 ;
V_15 = F_350 ( V_12 , V_508 -> V_518 , V_48 -> V_72 , V_48 -> V_44 ) ;
if ( V_15 )
goto V_556;
V_15 = F_313 ( V_12 , V_48 -> V_72 , V_508 -> V_198 -> V_91 , true ) ;
if ( V_15 )
goto V_527;
F_54 ( V_508 -> V_68 , V_48 -> V_72 ) ;
V_508 -> V_44 = V_48 -> V_44 ;
F_46 ( V_48 , L_52 , V_508 -> V_518 ) ;
return 0 ;
V_527:
F_350 ( V_12 , V_508 -> V_518 , V_508 -> V_68 , V_508 -> V_44 ) ;
V_556:
F_313 ( V_12 , V_508 -> V_68 , V_508 -> V_198 -> V_91 , true ) ;
return V_15 ;
}
static bool F_356 ( struct V_30 * V_557 ,
T_2 V_91 )
{
if ( F_333 ( V_91 ) )
return F_357 ( V_557 , V_91 ) ;
else
return F_194 ( V_91 , V_557 -> V_367 ) ;
}
static bool F_358 ( struct V_30 * V_30 ,
T_2 V_91 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
T_1 V_10 = V_30 -> V_10 ;
T_2 V_191 = V_30 -> V_191 ;
T_4 V_558 ;
int V_19 , V_407 = 0 ;
if ( ! V_30 -> V_190 )
return true ;
V_558 = F_16 ( V_12 -> V_16 ,
V_490 ) ;
for ( V_19 = 0 ; V_19 < V_558 ; V_19 ++ ) {
struct V_30 * V_557 ;
V_557 = F_359 ( V_12 , V_191 , V_19 ) ;
if ( ! V_557 || V_557 -> V_10 == V_10 )
continue;
if ( F_356 ( V_557 , V_91 ) )
V_407 ++ ;
}
return ! V_407 ;
}
static int
F_360 ( const struct V_30 * V_30 ,
T_2 V_91 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_559 [ V_560 ] ;
F_361 ( V_559 , V_561 ) ;
F_362 ( V_559 , V_91 ) ;
F_363 ( V_559 ,
V_30 -> V_10 ) ;
F_46 ( V_30 -> V_48 , L_53 ,
V_30 -> V_10 , V_91 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_562 ) , V_559 ) ;
}
static int
F_364 ( const struct V_30 * V_30 ,
T_2 V_91 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_559 [ V_560 ] ;
F_361 ( V_559 , V_563 ) ;
F_362 ( V_559 , V_91 ) ;
F_365 ( V_559 , V_30 -> V_191 ) ;
F_46 ( V_30 -> V_48 , L_54 ,
V_30 -> V_191 , V_91 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_562 ) , V_559 ) ;
}
int F_366 ( struct V_30 * V_30 , T_2 V_91 )
{
if ( ! F_358 ( V_30 , V_91 ) )
return 0 ;
if ( V_30 -> V_190 )
return F_364 ( V_30 ,
V_91 ) ;
else
return F_360 ( V_30 , V_91 ) ;
}
static void F_367 ( struct V_12 * V_12 )
{
struct V_197 * V_198 , * V_564 ;
F_368 (f, tmp, &mlxsw_sp->fids, list)
if ( -- V_198 -> V_39 == 0 )
F_369 ( V_12 , V_198 ) ;
else
F_20 ( 1 ) ;
}
static bool F_370 ( struct V_12 * V_12 ,
struct V_114 * V_545 )
{
return ! V_12 -> V_534 . V_48 ||
V_12 -> V_534 . V_48 == V_545 ;
}
static void F_371 ( struct V_12 * V_12 ,
struct V_114 * V_545 )
{
V_12 -> V_534 . V_48 = V_545 ;
V_12 -> V_534 . V_39 ++ ;
}
static void F_372 ( struct V_12 * V_12 )
{
if ( -- V_12 -> V_534 . V_39 == 0 ) {
V_12 -> V_534 . V_48 = NULL ;
F_367 ( V_12 ) ;
}
}
static int F_373 ( struct V_30 * V_30 ,
struct V_114 * V_545 )
{
struct V_114 * V_48 = V_30 -> V_48 ;
int V_15 ;
V_15 = F_148 ( V_48 , 0 , 1 ) ;
if ( V_15 )
return V_15 ;
F_371 ( V_30 -> V_12 , V_545 ) ;
V_30 -> V_565 = 1 ;
V_30 -> V_566 = 1 ;
V_30 -> V_567 = 1 ;
V_30 -> V_568 = 1 ;
return 0 ;
}
static void F_374 ( struct V_30 * V_30 )
{
struct V_114 * V_48 = V_30 -> V_48 ;
F_375 ( V_30 , 1 ) ;
F_372 ( V_30 -> V_12 ) ;
V_30 -> V_565 = 0 ;
V_30 -> V_566 = 0 ;
V_30 -> V_567 = 0 ;
V_30 -> V_568 = 0 ;
F_145 ( V_48 , 0 , 1 ) ;
}
static int F_376 ( struct V_12 * V_12 , T_2 V_191 )
{
char V_569 [ V_570 ] ;
F_377 ( V_569 , V_191 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_571 ) , V_569 ) ;
}
static int F_378 ( struct V_12 * V_12 , T_2 V_191 )
{
char V_569 [ V_570 ] ;
F_379 ( V_569 , V_191 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_571 ) , V_569 ) ;
}
static int F_380 ( struct V_30 * V_30 ,
T_2 V_191 , T_1 V_572 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_573 [ V_574 ] ;
F_381 ( V_573 , V_30 -> V_10 ,
V_191 , V_572 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_575 ) , V_573 ) ;
}
static int F_382 ( struct V_30 * V_30 ,
T_2 V_191 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_573 [ V_574 ] ;
F_383 ( V_573 , V_30 -> V_10 ,
V_191 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_575 ) , V_573 ) ;
}
static int F_384 ( struct V_30 * V_30 ,
T_2 V_191 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_573 [ V_574 ] ;
F_385 ( V_573 , V_30 -> V_10 ,
V_191 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_575 ) , V_573 ) ;
}
static int F_386 ( struct V_30 * V_30 ,
T_2 V_191 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_573 [ V_574 ] ;
F_387 ( V_573 , V_30 -> V_10 ,
V_191 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_575 ) , V_573 ) ;
}
static int F_388 ( struct V_12 * V_12 ,
struct V_114 * V_531 ,
T_2 * V_576 )
{
struct V_492 * V_577 ;
int V_578 = - 1 ;
T_4 V_579 ;
int V_19 ;
V_579 = F_16 ( V_12 -> V_16 , V_489 ) ;
for ( V_19 = 0 ; V_19 < V_579 ; V_19 ++ ) {
V_577 = F_389 ( V_12 , V_19 ) ;
if ( V_577 -> V_39 ) {
if ( V_577 -> V_48 == V_531 ) {
* V_576 = V_19 ;
return 0 ;
}
} else if ( V_578 < 0 ) {
V_578 = V_19 ;
}
}
if ( V_578 < 0 )
return - V_580 ;
* V_576 = V_578 ;
return 0 ;
}
static bool
F_390 ( struct V_12 * V_12 ,
struct V_114 * V_531 ,
struct V_581 * V_582 )
{
T_2 V_191 ;
if ( F_388 ( V_12 , V_531 , & V_191 ) != 0 )
return false ;
if ( V_582 -> V_583 != V_584 )
return false ;
return true ;
}
static int F_391 ( struct V_12 * V_12 ,
T_2 V_191 , T_1 * V_585 )
{
T_4 V_558 ;
int V_19 ;
V_558 = F_16 ( V_12 -> V_16 ,
V_490 ) ;
for ( V_19 = 0 ; V_19 < V_558 ; V_19 ++ ) {
if ( ! F_359 ( V_12 , V_191 , V_19 ) ) {
* V_585 = V_19 ;
return 0 ;
}
}
return - V_580 ;
}
static void
F_392 ( struct V_30 * V_30 ,
T_2 V_191 )
{
struct V_30 * V_187 ;
struct V_197 * V_198 ;
V_187 = F_146 ( V_30 , 1 ) ;
if ( F_30 ( ! V_187 ) )
return;
V_198 = F_149 ( V_187 ) ;
if ( V_198 )
V_198 -> V_199 ( V_187 ) ;
V_187 -> V_191 = V_191 ;
V_187 -> V_190 = 1 ;
}
static void
F_393 ( struct V_30 * V_30 )
{
struct V_30 * V_187 ;
struct V_197 * V_198 ;
V_187 = F_146 ( V_30 , 1 ) ;
if ( F_30 ( ! V_187 ) )
return;
V_198 = F_149 ( V_187 ) ;
if ( V_198 )
V_198 -> V_199 ( V_187 ) ;
V_187 -> V_190 = 0 ;
}
static int F_394 ( struct V_30 * V_30 ,
struct V_114 * V_531 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
struct V_492 * V_577 ;
T_2 V_191 ;
T_1 V_572 ;
int V_15 ;
V_15 = F_388 ( V_12 , V_531 , & V_191 ) ;
if ( V_15 )
return V_15 ;
V_577 = F_389 ( V_12 , V_191 ) ;
if ( ! V_577 -> V_39 ) {
V_15 = F_376 ( V_12 , V_191 ) ;
if ( V_15 )
return V_15 ;
V_577 -> V_48 = V_531 ;
}
V_15 = F_391 ( V_12 , V_191 , & V_572 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_380 ( V_30 , V_191 , V_572 ) ;
if ( V_15 )
goto V_586;
V_15 = F_384 ( V_30 , V_191 ) ;
if ( V_15 )
goto V_587;
F_395 ( V_12 -> V_16 , V_191 , V_572 ,
V_30 -> V_10 ) ;
V_30 -> V_191 = V_191 ;
V_30 -> V_190 = 1 ;
V_577 -> V_39 ++ ;
F_392 ( V_30 , V_191 ) ;
return 0 ;
V_587:
F_382 ( V_30 , V_191 ) ;
V_586:
if ( ! V_577 -> V_39 )
F_378 ( V_12 , V_191 ) ;
return V_15 ;
}
static void F_396 ( struct V_30 * V_30 ,
struct V_114 * V_531 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
T_2 V_191 = V_30 -> V_191 ;
struct V_492 * V_577 ;
if ( ! V_30 -> V_190 )
return;
V_577 = F_389 ( V_12 , V_191 ) ;
F_30 ( V_577 -> V_39 == 0 ) ;
F_386 ( V_30 , V_191 ) ;
F_382 ( V_30 , V_191 ) ;
if ( V_30 -> V_568 ) {
F_397 ( V_30 ) ;
F_374 ( V_30 ) ;
}
if ( V_577 -> V_39 == 1 )
F_378 ( V_12 , V_191 ) ;
F_398 ( V_12 -> V_16 , V_191 ,
V_30 -> V_10 ) ;
V_30 -> V_190 = 0 ;
V_577 -> V_39 -- ;
F_393 ( V_30 ) ;
}
static int F_399 ( struct V_30 * V_30 ,
T_2 V_191 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_569 [ V_570 ] ;
F_400 ( V_569 , V_191 ,
V_30 -> V_10 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_571 ) , V_569 ) ;
}
static int F_401 ( struct V_30 * V_30 ,
T_2 V_191 )
{
struct V_12 * V_12 = V_30 -> V_12 ;
char V_569 [ V_570 ] ;
F_402 ( V_569 , V_191 ,
V_30 -> V_10 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_571 ) , V_569 ) ;
}
static int F_403 ( struct V_30 * V_30 ,
bool V_588 )
{
if ( V_588 )
return F_399 ( V_30 ,
V_30 -> V_191 ) ;
else
return F_401 ( V_30 ,
V_30 -> V_191 ) ;
}
static int F_404 ( struct V_30 * V_30 ,
struct V_589 * V_590 )
{
return F_403 ( V_30 , V_590 -> V_591 ) ;
}
static int F_405 ( struct V_30 * V_30 ,
struct V_114 * V_546 )
{
struct V_30 * V_187 ;
T_2 V_92 = F_329 ( V_546 ) ;
V_187 = F_146 ( V_30 , V_92 ) ;
if ( F_30 ( ! V_187 ) )
return - V_79 ;
V_187 -> V_48 = V_546 ;
return 0 ;
}
static void F_406 ( struct V_30 * V_30 ,
struct V_114 * V_546 )
{
struct V_30 * V_187 ;
T_2 V_92 = F_329 ( V_546 ) ;
V_187 = F_146 ( V_30 , V_92 ) ;
if ( F_30 ( ! V_187 ) )
return;
V_187 -> V_48 = V_30 -> V_48 ;
}
static int F_407 ( struct V_114 * V_48 ,
unsigned long V_509 , void * V_550 )
{
struct V_592 * V_590 ;
struct V_30 * V_30 ;
struct V_114 * V_593 ;
struct V_12 * V_12 ;
int V_15 = 0 ;
V_30 = F_82 ( V_48 ) ;
V_12 = V_30 -> V_12 ;
V_590 = V_550 ;
switch ( V_509 ) {
case V_594 :
V_593 = V_590 -> V_593 ;
if ( ! F_328 ( V_593 ) &&
! F_346 ( V_593 ) &&
! F_347 ( V_593 ) )
return - V_79 ;
if ( ! V_590 -> V_595 )
break;
if ( F_347 ( V_593 ) &&
! F_370 ( V_12 , V_593 ) )
return - V_79 ;
if ( F_346 ( V_593 ) &&
! F_390 ( V_12 , V_593 ,
V_590 -> V_596 ) )
return - V_79 ;
if ( F_346 ( V_593 ) && F_408 ( V_48 ) )
return - V_79 ;
if ( F_323 ( V_48 ) && F_328 ( V_593 ) &&
! F_346 ( F_345 ( V_593 ) ) )
return - V_79 ;
break;
case V_597 :
V_593 = V_590 -> V_593 ;
if ( F_328 ( V_593 ) ) {
if ( V_590 -> V_595 )
V_15 = F_405 ( V_30 ,
V_593 ) ;
else
F_406 ( V_30 ,
V_593 ) ;
} else if ( F_347 ( V_593 ) ) {
if ( V_590 -> V_595 )
V_15 = F_373 ( V_30 ,
V_593 ) ;
else
F_374 ( V_30 ) ;
} else if ( F_346 ( V_593 ) ) {
if ( V_590 -> V_595 )
V_15 = F_394 ( V_30 ,
V_593 ) ;
else
F_396 ( V_30 ,
V_593 ) ;
} else {
V_15 = - V_79 ;
F_30 ( 1 ) ;
}
break;
}
return V_15 ;
}
static int F_409 ( struct V_114 * V_48 ,
unsigned long V_509 , void * V_550 )
{
struct V_598 * V_590 ;
struct V_30 * V_30 ;
int V_15 ;
V_30 = F_82 ( V_48 ) ;
V_590 = V_550 ;
switch ( V_509 ) {
case V_599 :
if ( F_323 ( V_48 ) && V_30 -> V_190 ) {
V_15 = F_404 ( V_30 ,
V_590 -> V_600 ) ;
if ( V_15 )
F_37 ( V_48 , L_55 ) ;
}
break;
}
return 0 ;
}
static int F_410 ( struct V_114 * V_48 ,
unsigned long V_509 , void * V_550 )
{
switch ( V_509 ) {
case V_594 :
case V_597 :
return F_407 ( V_48 , V_509 , V_550 ) ;
case V_599 :
return F_409 ( V_48 , V_509 , V_550 ) ;
}
return 0 ;
}
static int F_411 ( struct V_114 * V_531 ,
unsigned long V_509 , void * V_550 )
{
struct V_114 * V_48 ;
struct V_532 * V_533 ;
int V_506 ;
F_325 (lag_dev, dev, iter) {
if ( F_156 ( V_48 ) ) {
V_506 = F_410 ( V_48 , V_509 , V_550 ) ;
if ( V_506 )
return V_506 ;
}
}
return 0 ;
}
static int F_412 ( struct V_12 * V_12 ,
struct V_114 * V_546 )
{
T_2 V_91 = F_329 ( V_546 ) ;
struct V_197 * V_198 ;
V_198 = F_331 ( V_12 , V_91 ) ;
if ( ! V_198 ) {
V_198 = F_413 ( V_12 , V_91 ) ;
if ( F_317 ( V_198 ) )
return F_318 ( V_198 ) ;
}
V_198 -> V_39 ++ ;
return 0 ;
}
static void F_414 ( struct V_12 * V_12 ,
struct V_114 * V_546 )
{
T_2 V_91 = F_329 ( V_546 ) ;
struct V_197 * V_198 ;
V_198 = F_331 ( V_12 , V_91 ) ;
if ( V_198 && V_198 -> V_508 )
F_342 ( V_12 , V_198 -> V_508 ) ;
if ( V_198 && -- V_198 -> V_39 == 0 )
F_369 ( V_12 , V_198 ) ;
}
static int F_415 ( struct V_114 * V_545 ,
unsigned long V_509 , void * V_550 )
{
struct V_592 * V_590 ;
struct V_114 * V_593 ;
struct V_12 * V_12 ;
int V_15 ;
V_12 = F_292 ( V_545 ) ;
if ( ! V_12 )
return 0 ;
if ( V_545 != V_12 -> V_534 . V_48 )
return 0 ;
V_590 = V_550 ;
switch ( V_509 ) {
case V_597 :
V_593 = V_590 -> V_593 ;
if ( ! F_328 ( V_593 ) )
break;
if ( V_590 -> V_595 ) {
V_15 = F_412 ( V_12 ,
V_593 ) ;
if ( V_15 )
return V_15 ;
} else {
F_414 ( V_12 , V_593 ) ;
}
break;
}
return 0 ;
}
static T_2 F_416 ( const struct V_12 * V_12 )
{
return F_417 ( V_12 -> V_496 . V_601 ,
V_602 ) ;
}
static int F_418 ( struct V_12 * V_12 , T_2 V_91 , bool V_519 )
{
char V_603 [ V_604 ] ;
F_419 ( V_603 , ! V_519 , V_91 , 0 ) ;
return F_25 ( V_12 -> V_16 , F_12 ( V_605 ) , V_603 ) ;
}
static struct V_197 * F_420 ( struct V_12 * V_12 ,
struct V_114 * V_545 )
{
struct V_606 * V_48 = V_12 -> V_244 -> V_48 ;
struct V_197 * V_198 ;
T_2 V_607 , V_91 ;
int V_15 ;
V_607 = F_416 ( V_12 ) ;
if ( V_607 == V_602 ) {
F_227 ( V_48 , L_56 ) ;
return F_311 ( - V_526 ) ;
}
V_91 = F_421 ( V_607 ) ;
V_15 = F_418 ( V_12 , V_91 , true ) ;
if ( V_15 ) {
F_227 ( V_48 , L_57 , V_91 ) ;
return F_311 ( V_15 ) ;
}
V_198 = F_41 ( sizeof( * V_198 ) , V_26 ) ;
if ( ! V_198 )
goto V_608;
V_198 -> V_199 = V_609 ;
V_198 -> V_91 = V_91 ;
V_198 -> V_48 = V_545 ;
F_143 ( & V_198 -> V_57 , & V_12 -> V_496 . V_57 ) ;
F_422 ( V_607 , V_12 -> V_496 . V_601 ) ;
return V_198 ;
V_608:
F_418 ( V_12 , V_91 , false ) ;
return F_311 ( - V_27 ) ;
}
static void F_423 ( struct V_12 * V_12 ,
struct V_197 * V_198 )
{
T_2 V_607 = F_335 ( V_198 -> V_91 ) ;
T_2 V_91 = V_198 -> V_91 ;
F_424 ( V_607 , V_12 -> V_496 . V_601 ) ;
F_44 ( & V_198 -> V_57 ) ;
if ( V_198 -> V_508 )
F_342 ( V_12 , V_198 -> V_508 ) ;
F_22 ( V_198 ) ;
F_418 ( V_12 , V_91 , false ) ;
}
static int F_425 ( struct V_30 * V_187 , T_2 V_91 ,
bool V_90 )
{
enum V_88 V_89 = V_183 ;
T_2 V_92 = F_307 ( V_187 ) ;
return F_63 ( V_187 , V_89 , V_90 , V_91 ,
V_92 ) ;
}
static int F_426 ( struct V_30 * V_187 ,
struct V_114 * V_545 )
{
struct V_197 * V_198 ;
int V_15 ;
V_198 = F_330 ( V_187 -> V_12 , V_545 ) ;
if ( ! V_198 ) {
V_198 = F_420 ( V_187 -> V_12 , V_545 ) ;
if ( F_317 ( V_198 ) )
return F_318 ( V_198 ) ;
}
V_15 = F_427 ( V_187 , V_198 -> V_91 , true ) ;
if ( V_15 )
goto V_610;
V_15 = F_425 ( V_187 , V_198 -> V_91 , true ) ;
if ( V_15 )
goto V_611;
F_319 ( V_187 , V_198 ) ;
V_198 -> V_39 ++ ;
F_46 ( V_187 -> V_48 , L_48 , V_198 -> V_91 ) ;
return 0 ;
V_611:
F_427 ( V_187 , V_198 -> V_91 , false ) ;
V_610:
if ( ! V_198 -> V_39 )
F_423 ( V_187 -> V_12 , V_198 ) ;
return V_15 ;
}
static void V_609 ( struct V_30 * V_187 )
{
struct V_197 * V_198 = F_149 ( V_187 ) ;
F_46 ( V_187 -> V_48 , L_49 , V_198 -> V_91 ) ;
F_425 ( V_187 , V_198 -> V_91 , false ) ;
F_427 ( V_187 , V_198 -> V_91 , false ) ;
F_366 ( V_187 , V_198 -> V_91 ) ;
F_319 ( V_187 , NULL ) ;
if ( -- V_198 -> V_39 == 0 )
F_423 ( V_187 -> V_12 , V_198 ) ;
}
static int F_428 ( struct V_30 * V_187 ,
struct V_114 * V_545 )
{
struct V_197 * V_198 = F_149 ( V_187 ) ;
T_2 V_92 = F_307 ( V_187 ) ;
struct V_114 * V_48 = V_187 -> V_48 ;
int V_15 ;
if ( V_198 && ! F_30 ( ! V_198 -> V_199 ) )
V_198 -> V_199 ( V_187 ) ;
V_15 = F_426 ( V_187 , V_545 ) ;
if ( V_15 ) {
F_37 ( V_48 , L_58 ) ;
return V_15 ;
}
V_15 = F_68 ( V_187 , V_92 , true ) ;
if ( V_15 ) {
F_37 ( V_48 , L_59 ) ;
goto V_612;
}
V_187 -> V_565 = 1 ;
V_187 -> V_566 = 1 ;
V_187 -> V_567 = 1 ;
V_187 -> V_568 = 1 ;
return 0 ;
V_612:
V_609 ( V_187 ) ;
return V_15 ;
}
static void F_429 ( struct V_30 * V_187 )
{
T_2 V_92 = F_307 ( V_187 ) ;
F_68 ( V_187 , V_92 , false ) ;
V_609 ( V_187 ) ;
V_187 -> V_565 = 0 ;
V_187 -> V_566 = 0 ;
V_187 -> V_567 = 0 ;
V_187 -> V_568 = 0 ;
}
static bool
F_430 ( const struct V_30 * V_30 ,
const struct V_114 * V_545 )
{
struct V_30 * V_187 ;
F_32 (mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
struct V_114 * V_48 = F_431 ( V_187 ) ;
if ( V_48 && V_48 == V_545 )
return false ;
}
return true ;
}
static int F_432 ( struct V_114 * V_48 ,
unsigned long V_509 , void * V_550 ,
T_2 V_92 )
{
struct V_30 * V_30 = F_82 ( V_48 ) ;
struct V_592 * V_590 = V_550 ;
struct V_30 * V_187 ;
struct V_114 * V_593 ;
int V_15 = 0 ;
V_187 = F_146 ( V_30 , V_92 ) ;
switch ( V_509 ) {
case V_594 :
V_593 = V_590 -> V_593 ;
if ( ! F_347 ( V_593 ) )
return - V_79 ;
if ( ! V_590 -> V_595 )
break;
if ( ! F_430 ( V_30 ,
V_593 ) )
return - V_79 ;
break;
case V_597 :
V_593 = V_590 -> V_593 ;
if ( V_590 -> V_595 ) {
if ( F_30 ( ! V_187 ) )
return - V_79 ;
V_15 = F_428 ( V_187 ,
V_593 ) ;
} else {
if ( ! V_187 )
return 0 ;
F_429 ( V_187 ) ;
}
}
return V_15 ;
}
static int F_433 ( struct V_114 * V_531 ,
unsigned long V_509 , void * V_550 ,
T_2 V_92 )
{
struct V_114 * V_48 ;
struct V_532 * V_533 ;
int V_506 ;
F_325 (lag_dev, dev, iter) {
if ( F_156 ( V_48 ) ) {
V_506 = F_432 ( V_48 , V_509 , V_550 ,
V_92 ) ;
if ( V_506 )
return V_506 ;
}
}
return 0 ;
}
static int F_434 ( struct V_114 * V_546 ,
unsigned long V_509 , void * V_550 )
{
struct V_114 * V_547 = F_345 ( V_546 ) ;
T_2 V_92 = F_329 ( V_546 ) ;
if ( F_156 ( V_547 ) )
return F_432 ( V_547 , V_509 , V_550 ,
V_92 ) ;
else if ( F_346 ( V_547 ) )
return F_433 ( V_547 , V_509 , V_550 ,
V_92 ) ;
return 0 ;
}
static int F_435 ( struct V_548 * V_549 ,
unsigned long V_509 , void * V_550 )
{
struct V_114 * V_48 = F_436 ( V_550 ) ;
int V_15 = 0 ;
if ( V_509 == V_613 || V_509 == V_614 )
V_15 = F_355 ( V_48 ) ;
else if ( F_156 ( V_48 ) )
V_15 = F_410 ( V_48 , V_509 , V_550 ) ;
else if ( F_346 ( V_48 ) )
V_15 = F_411 ( V_48 , V_509 , V_550 ) ;
else if ( F_347 ( V_48 ) )
V_15 = F_415 ( V_48 , V_509 , V_550 ) ;
else if ( F_328 ( V_48 ) )
V_15 = F_434 ( V_48 , V_509 , V_550 ) ;
return F_349 ( V_15 ) ;
}
static int T_9 F_437 ( void )
{
int V_15 ;
F_438 ( & V_615 ) ;
F_439 ( & V_616 ) ;
F_440 ( & V_617 ) ;
V_15 = F_441 ( & V_618 ) ;
if ( V_15 )
goto V_619;
V_15 = F_442 ( & V_620 ) ;
if ( V_15 )
goto V_621;
return 0 ;
V_621:
F_443 ( & V_618 ) ;
V_619:
F_444 ( & V_617 ) ;
F_445 ( & V_616 ) ;
F_446 ( & V_615 ) ;
return V_15 ;
}
static void T_10 F_447 ( void )
{
F_448 ( & V_620 ) ;
F_443 ( & V_618 ) ;
F_444 ( & V_617 ) ;
F_445 ( & V_616 ) ;
F_446 ( & V_615 ) ;
}
