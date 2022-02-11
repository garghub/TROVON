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
static int F_14 ( struct V_19 * V_19 ,
bool V_20 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_21 [ V_22 ] ;
F_15 ( V_21 , V_19 -> V_10 ,
V_20 ? V_23 :
V_24 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_25 ) , V_21 ) ;
}
static int F_17 ( struct V_19 * V_19 ,
unsigned char * V_26 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_27 [ V_28 ] ;
F_18 ( V_27 , true , V_19 -> V_10 ) ;
F_19 ( V_27 , V_26 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_29 ) , V_27 ) ;
}
static int F_20 ( struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
unsigned char * V_26 = V_19 -> V_30 -> V_31 ;
F_21 ( V_26 , V_12 -> V_18 ) ;
V_26 [ V_32 - 1 ] += V_19 -> V_10 ;
return F_17 ( V_19 , V_26 ) ;
}
static int F_22 ( struct V_19 * V_19 ,
T_1 V_33 , enum V_34 V_35 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char * V_36 ;
int V_15 ;
V_36 = F_23 ( V_37 , V_38 ) ;
if ( ! V_36 )
return - V_39 ;
F_24 ( V_36 , V_19 -> V_10 ) ;
F_25 ( V_36 , V_33 , V_35 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_40 ) , V_36 ) ;
F_26 ( V_36 ) ;
return V_15 ;
}
static int F_27 ( struct V_19 * V_19 , T_1 V_41 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_42 [ V_43 ] ;
int V_44 ;
int V_15 ;
V_41 += V_6 + V_45 ;
F_28 ( V_42 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_46 ) , V_42 ) ;
if ( V_15 )
return V_15 ;
V_44 = F_29 ( V_42 ) ;
if ( V_41 > V_44 )
return - V_47 ;
F_28 ( V_42 , V_19 -> V_10 , V_41 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_46 ) , V_42 ) ;
}
static int F_30 ( struct V_12 * V_12 , T_2 V_10 ,
T_2 V_48 )
{
char V_49 [ V_50 ] ;
F_31 ( V_49 , V_48 , V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_51 ) , V_49 ) ;
}
static int F_32 ( struct V_19 * V_19 , T_2 V_48 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
return F_30 ( V_12 , V_19 -> V_10 ,
V_48 ) ;
}
static int F_33 ( struct V_19 * V_19 ,
bool V_52 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_53 [ V_54 ] ;
F_34 ( V_53 , V_19 -> V_10 , V_52 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_55 ) , V_53 ) ;
}
int F_35 ( struct V_19 * V_19 ,
enum V_56 V_57 , bool V_58 , T_1 V_59 ,
T_1 V_33 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_60 [ V_61 ] ;
F_36 ( V_60 , V_19 -> V_10 , V_57 , V_58 ,
V_59 , V_33 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_62 ) , V_60 ) ;
}
static int F_37 ( struct V_19 * V_19 ,
T_1 V_33 , bool V_63 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char * V_64 ;
int V_15 ;
V_64 = F_23 ( V_65 , V_38 ) ;
if ( ! V_64 )
return - V_39 ;
F_38 ( V_64 , V_19 -> V_10 , V_33 , V_33 ,
V_63 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_66 ) , V_64 ) ;
F_26 ( V_64 ) ;
return V_15 ;
}
static int
F_39 ( struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_67 [ V_68 ] ;
F_40 ( V_67 , V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_69 ) , V_67 ) ;
}
static int F_41 ( struct V_12 * V_12 ,
T_2 V_10 , T_2 * V_70 ,
T_2 * V_71 , T_2 * V_72 )
{
char V_73 [ V_74 ] ;
int V_15 ;
F_42 ( V_73 , V_10 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_75 ) , V_73 ) ;
if ( V_15 )
return V_15 ;
* V_70 = F_43 ( V_73 , 0 ) ;
* V_71 = F_44 ( V_73 ) ;
* V_72 = F_45 ( V_73 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_12 * V_12 , T_2 V_10 ,
T_2 V_76 , T_2 V_77 , T_2 V_78 )
{
char V_73 [ V_74 ] ;
int V_79 ;
F_42 ( V_73 , V_10 ) ;
F_47 ( V_73 , V_77 ) ;
for ( V_79 = 0 ; V_79 < V_77 ; V_79 ++ ) {
F_48 ( V_73 , V_79 , V_76 ) ;
F_49 ( V_73 , V_79 , V_78 + V_79 ) ;
}
return F_16 ( V_12 -> V_16 , F_12 ( V_75 ) , V_73 ) ;
}
static int F_50 ( struct V_12 * V_12 , T_2 V_10 )
{
char V_73 [ V_74 ] ;
F_42 ( V_73 , V_10 ) ;
F_47 ( V_73 , 0 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_75 ) , V_73 ) ;
}
static int F_51 ( struct V_80 * V_30 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
int V_15 ;
V_15 = F_14 ( V_19 , true ) ;
if ( V_15 )
return V_15 ;
F_53 ( V_30 ) ;
return 0 ;
}
static int F_54 ( struct V_80 * V_30 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
F_55 ( V_30 ) ;
return F_14 ( V_19 , false ) ;
}
static T_3 F_56 ( struct V_1 * V_2 ,
struct V_80 * V_30 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_81 * V_82 ;
const struct V_3 V_4 = {
. V_10 = V_19 -> V_10 ,
. V_83 = false ,
} ;
T_4 V_84 ;
int V_15 ;
if ( F_57 ( V_12 -> V_16 , & V_4 ) )
return V_85 ;
if ( F_58 ( F_59 ( V_2 ) < V_6 ) ) {
struct V_1 * V_86 = V_2 ;
V_2 = F_60 ( V_2 , V_6 ) ;
if ( ! V_2 ) {
F_61 ( V_19 -> V_82 -> V_87 ) ;
F_62 ( V_86 ) ;
return V_88 ;
}
}
if ( F_63 ( V_2 ) ) {
F_61 ( V_19 -> V_82 -> V_87 ) ;
return V_88 ;
}
F_1 ( V_2 , & V_4 ) ;
V_84 = V_2 -> V_84 - V_6 ;
V_15 = F_64 ( V_12 -> V_16 , V_2 , & V_4 ) ;
if ( ! V_15 ) {
V_82 = F_65 ( V_19 -> V_82 ) ;
F_66 ( & V_82 -> V_89 ) ;
V_82 -> V_90 ++ ;
V_82 -> V_91 += V_84 ;
F_67 ( & V_82 -> V_89 ) ;
} else {
F_61 ( V_19 -> V_82 -> V_87 ) ;
F_62 ( V_2 ) ;
}
return V_88 ;
}
static void F_68 ( struct V_80 * V_30 )
{
}
static int F_69 ( struct V_80 * V_30 , void * V_92 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
struct V_93 * V_26 = V_92 ;
int V_15 ;
if ( ! F_70 ( V_26 -> V_94 ) )
return - V_95 ;
V_15 = F_17 ( V_19 , V_26 -> V_94 ) ;
if ( V_15 )
return V_15 ;
memcpy ( V_30 -> V_31 , V_26 -> V_94 , V_30 -> V_96 ) ;
return 0 ;
}
static void F_71 ( char * V_97 , int V_98 , int V_41 ,
bool V_99 , bool V_100 , T_1 V_101 )
{
T_1 V_102 = 2 * F_72 ( V_41 ) ;
V_101 = V_100 ? F_73 ( V_41 , V_101 ) :
V_103 ;
if ( V_99 || V_100 )
F_74 ( V_97 , V_98 ,
V_102 + V_101 , V_102 ) ;
else
F_75 ( V_97 , V_98 , V_102 ) ;
}
int F_76 ( struct V_19 * V_19 , int V_41 ,
T_2 * V_104 , bool V_99 ,
struct V_105 * V_106 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
T_2 V_100 = ! ! V_106 ? V_106 -> V_100 : 0 ;
T_1 V_101 = ! ! V_106 ? V_106 -> V_101 : 0 ;
char V_97 [ V_107 ] ;
int V_79 , V_108 , V_15 ;
F_77 ( V_97 , V_19 -> V_10 , 0 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_109 ) , V_97 ) ;
if ( V_15 )
return V_15 ;
for ( V_79 = 0 ; V_79 < V_110 ; V_79 ++ ) {
bool V_111 = false ;
bool V_112 = false ;
for ( V_108 = 0 ; V_108 < V_110 ; V_108 ++ ) {
if ( V_104 [ V_108 ] == V_79 ) {
V_112 = V_100 & F_78 ( V_108 ) ;
V_111 = true ;
break;
}
}
if ( ! V_111 )
continue;
F_71 ( V_97 , V_79 , V_41 , V_99 , V_112 , V_101 ) ;
}
return F_16 ( V_12 -> V_16 , F_12 ( V_109 ) , V_97 ) ;
}
static int F_79 ( struct V_19 * V_19 ,
int V_41 , bool V_99 )
{
T_2 V_113 [ V_110 ] = { 0 } ;
bool V_114 = ! ! V_19 -> V_115 . V_116 ;
struct V_105 * V_106 ;
T_2 * V_104 ;
V_104 = V_114 ? V_19 -> V_115 . V_116 -> V_104 : V_113 ;
V_106 = V_114 ? V_19 -> V_115 . V_112 : NULL ;
return F_76 ( V_19 , V_41 , V_104 ,
V_99 , V_106 ) ;
}
static int F_80 ( struct V_80 * V_30 , int V_41 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
bool V_99 = F_81 ( V_19 ) ;
int V_15 ;
V_15 = F_79 ( V_19 , V_41 , V_99 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_27 ( V_19 , V_41 ) ;
if ( V_15 )
goto V_117;
V_30 -> V_41 = V_41 ;
return 0 ;
V_117:
F_79 ( V_19 , V_30 -> V_41 , V_99 ) ;
return V_15 ;
}
static struct V_118 *
F_82 ( struct V_80 * V_30 ,
struct V_118 * V_119 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
struct V_81 * V_92 ;
T_4 V_120 , V_121 , V_90 , V_91 ;
T_5 V_87 = 0 ;
unsigned int V_122 ;
int V_79 ;
F_83 (i) {
V_92 = F_84 ( V_19 -> V_82 , V_79 ) ;
do {
V_122 = F_85 ( & V_92 -> V_89 ) ;
V_120 = V_92 -> V_120 ;
V_121 = V_92 -> V_121 ;
V_90 = V_92 -> V_90 ;
V_91 = V_92 -> V_91 ;
} while ( F_86 ( & V_92 -> V_89 , V_122 ) );
V_119 -> V_120 += V_120 ;
V_119 -> V_121 += V_121 ;
V_119 -> V_90 += V_90 ;
V_119 -> V_91 += V_91 ;
V_87 += V_92 -> V_87 ;
}
V_119 -> V_87 = V_87 ;
return V_119 ;
}
int F_87 ( struct V_19 * V_19 , T_1 V_123 ,
T_1 V_124 , bool V_125 , bool V_126 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char * V_127 ;
int V_15 ;
V_127 = F_23 ( V_128 , V_38 ) ;
if ( ! V_127 )
return - V_39 ;
F_88 ( V_127 , V_19 -> V_10 , V_123 ,
V_124 , V_125 , V_126 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_129 ) , V_127 ) ;
F_26 ( V_127 ) ;
return V_15 ;
}
static int F_89 ( struct V_19 * V_19 )
{
enum V_56 V_57 = V_130 ;
T_1 V_33 , V_131 ;
int V_15 ;
F_90 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_35 ( V_19 , V_57 , true , V_33 ,
V_33 ) ;
if ( V_15 ) {
V_131 = V_33 ;
goto V_132;
}
}
V_15 = F_33 ( V_19 , true ) ;
if ( V_15 ) {
V_131 = V_133 ;
goto V_132;
}
return 0 ;
V_132:
F_90 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_35 ( V_19 , V_57 , false , V_33 ,
V_33 ) ;
return V_15 ;
}
static int F_91 ( struct V_19 * V_19 )
{
enum V_56 V_57 = V_130 ;
T_1 V_33 ;
int V_15 ;
V_15 = F_33 ( V_19 , false ) ;
if ( V_15 )
return V_15 ;
F_90 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_35 ( V_19 , V_57 , false ,
V_33 , V_33 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static struct V_134 *
F_92 ( const struct V_12 * V_12 , T_1 V_33 )
{
struct V_134 * V_135 ;
F_93 (vfid, &mlxsw_sp->port_vfids.list, list) {
if ( V_135 -> V_33 == V_33 )
return V_135 ;
}
return NULL ;
}
static T_1 F_94 ( const struct V_12 * V_12 )
{
return F_95 ( V_12 -> V_136 . V_137 ,
V_138 ) ;
}
static int F_96 ( struct V_12 * V_12 , T_1 V_135 )
{
T_1 V_59 = F_97 ( V_135 ) ;
char V_139 [ V_140 ] ;
F_98 ( V_139 , V_141 , V_59 , 0 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_142 ) , V_139 ) ;
}
static void F_99 ( struct V_12 * V_12 , T_1 V_135 )
{
T_1 V_59 = F_97 ( V_135 ) ;
char V_139 [ V_140 ] ;
F_98 ( V_139 , V_143 , V_59 , 0 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_142 ) , V_139 ) ;
}
static struct V_134 * F_100 ( struct V_12 * V_12 ,
T_1 V_33 )
{
struct V_144 * V_30 = V_12 -> V_145 -> V_30 ;
struct V_134 * V_135 ;
T_1 V_146 ;
int V_15 ;
V_146 = F_94 ( V_12 ) ;
if ( V_146 == V_138 ) {
F_101 ( V_30 , L_1 ) ;
return F_102 ( - V_147 ) ;
}
V_15 = F_96 ( V_12 , V_146 ) ;
if ( V_15 ) {
F_101 ( V_30 , L_2 , V_146 ) ;
return F_102 ( V_15 ) ;
}
V_135 = F_103 ( sizeof( * V_135 ) , V_38 ) ;
if ( ! V_135 )
goto V_148;
V_135 -> V_135 = V_146 ;
V_135 -> V_33 = V_33 ;
F_104 ( & V_135 -> V_149 , & V_12 -> V_136 . V_149 ) ;
F_105 ( V_146 , V_12 -> V_136 . V_137 ) ;
return V_135 ;
V_148:
F_99 ( V_12 , V_146 ) ;
return F_102 ( - V_39 ) ;
}
static void F_106 ( struct V_12 * V_12 ,
struct V_134 * V_135 )
{
F_107 ( V_135 -> V_135 , V_12 -> V_136 . V_137 ) ;
F_108 ( & V_135 -> V_149 ) ;
F_99 ( V_12 , V_135 -> V_135 ) ;
F_26 ( V_135 ) ;
}
static struct V_19 *
F_109 ( struct V_19 * V_19 ,
struct V_134 * V_135 )
{
struct V_19 * V_150 ;
V_150 = F_103 ( sizeof( * V_150 ) , V_38 ) ;
if ( ! V_150 )
return NULL ;
V_150 -> V_30 = V_19 -> V_30 ;
V_150 -> V_12 = V_19 -> V_12 ;
V_150 -> V_10 = V_19 -> V_10 ;
V_150 -> V_151 = V_152 ;
V_150 -> V_153 = V_19 -> V_153 ;
V_150 -> V_154 = V_19 -> V_154 ;
V_150 -> V_155 . V_135 = V_135 ;
V_150 -> V_155 . V_33 = V_135 -> V_33 ;
F_104 ( & V_150 -> V_155 . V_149 , & V_19 -> V_156 ) ;
return V_150 ;
}
static void F_110 ( struct V_19 * V_150 )
{
F_108 ( & V_150 -> V_155 . V_149 ) ;
F_26 ( V_150 ) ;
}
int F_111 ( struct V_80 * V_30 , T_6 T_7 V_157 ,
T_1 V_33 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_19 * V_150 ;
struct V_134 * V_135 ;
int V_15 ;
if ( ! V_33 )
return 0 ;
if ( F_112 ( V_19 , V_33 ) ) {
F_113 ( V_30 , L_3 , V_33 ) ;
return 0 ;
}
V_135 = F_92 ( V_12 , V_33 ) ;
if ( ! V_135 ) {
V_135 = F_100 ( V_12 , V_33 ) ;
if ( F_114 ( V_135 ) ) {
F_115 ( V_30 , L_4 ,
V_33 ) ;
return F_116 ( V_135 ) ;
}
}
V_150 = F_109 ( V_19 , V_135 ) ;
if ( ! V_150 ) {
F_115 ( V_30 , L_5 , V_33 ) ;
V_15 = - V_39 ;
goto V_158;
}
if ( ! V_135 -> V_159 ) {
V_15 = F_117 ( V_150 , V_135 -> V_135 ,
true , false ) ;
if ( V_15 ) {
F_115 ( V_30 , L_6 ,
V_135 -> V_135 ) ;
goto V_160;
}
}
if ( F_118 ( & V_19 -> V_156 ) ) {
V_15 = F_89 ( V_19 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_7 ) ;
goto V_161;
}
}
V_15 = F_35 ( V_150 ,
V_130 ,
true ,
F_97 ( V_135 -> V_135 ) ,
V_33 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_8 ,
V_33 , V_135 -> V_135 ) ;
goto V_132;
}
V_15 = F_37 ( V_150 , V_33 , false ) ;
if ( V_15 ) {
F_115 ( V_30 , L_9 , V_33 ) ;
goto V_162;
}
V_15 = F_87 ( V_150 , V_33 , V_33 , true , false ) ;
if ( V_15 ) {
F_115 ( V_30 , L_10 ,
V_33 ) ;
goto V_163;
}
V_15 = F_22 ( V_150 , V_33 ,
V_164 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_11 , V_33 ) ;
goto V_165;
}
V_135 -> V_159 ++ ;
return 0 ;
V_165:
F_87 ( V_150 , V_33 , V_33 , false , false ) ;
V_163:
F_37 ( V_150 , V_33 , true ) ;
V_162:
F_35 ( V_150 ,
V_130 , false ,
F_97 ( V_135 -> V_135 ) , V_33 ) ;
V_132:
if ( F_118 ( & V_19 -> V_156 ) )
F_91 ( V_19 ) ;
V_161:
if ( ! V_135 -> V_159 )
F_117 ( V_150 , V_135 -> V_135 , false ,
false ) ;
V_160:
F_110 ( V_150 ) ;
V_158:
if ( ! V_135 -> V_159 )
F_106 ( V_12 , V_135 ) ;
return V_15 ;
}
int F_119 ( struct V_80 * V_30 ,
T_6 T_7 V_157 , T_1 V_33 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
struct V_19 * V_150 ;
struct V_134 * V_135 ;
int V_15 ;
if ( ! V_33 )
return 0 ;
V_150 = F_112 ( V_19 , V_33 ) ;
if ( ! V_150 ) {
F_113 ( V_30 , L_12 , V_33 ) ;
return 0 ;
}
V_135 = V_150 -> V_155 . V_135 ;
V_15 = F_22 ( V_150 , V_33 ,
V_166 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_11 , V_33 ) ;
return V_15 ;
}
V_15 = F_87 ( V_150 , V_33 , V_33 , false , false ) ;
if ( V_15 ) {
F_115 ( V_30 , L_10 ,
V_33 ) ;
return V_15 ;
}
V_15 = F_37 ( V_150 , V_33 , true ) ;
if ( V_15 ) {
F_115 ( V_30 , L_13 , V_33 ) ;
return V_15 ;
}
V_15 = F_35 ( V_150 ,
V_130 ,
false ,
F_97 ( V_135 -> V_135 ) ,
V_33 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_14 ,
V_33 , V_135 -> V_135 ) ;
return V_15 ;
}
if ( F_118 ( & V_19 -> V_156 ) ) {
V_15 = F_91 ( V_19 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_15 ) ;
return V_15 ;
}
}
V_135 -> V_159 -- ;
F_110 ( V_150 ) ;
if ( ! V_135 -> V_159 )
F_106 ( V_19 -> V_12 , V_135 ) ;
return 0 ;
}
static int F_120 ( struct V_80 * V_30 , char * V_167 ,
T_8 V_84 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
T_2 V_76 = V_19 -> V_168 . V_76 ;
T_2 V_77 = V_19 -> V_168 . V_77 ;
T_2 V_78 = V_19 -> V_168 . V_78 ;
int V_15 ;
if ( ! V_19 -> V_169 )
V_15 = snprintf ( V_167 , V_84 , L_16 , V_76 + 1 ) ;
else
V_15 = snprintf ( V_167 , V_84 , L_17 , V_76 + 1 ,
V_78 / V_77 ) ;
if ( V_15 >= V_84 )
return - V_47 ;
return 0 ;
}
static void F_121 ( struct V_80 * V_30 ,
struct V_170 * V_171 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
F_122 ( V_171 -> V_172 , V_173 , sizeof( V_171 -> V_172 ) ) ;
F_122 ( V_171 -> V_174 , V_175 ,
sizeof( V_171 -> V_174 ) ) ;
snprintf ( V_171 -> V_176 , sizeof( V_171 -> V_176 ) ,
L_18 ,
V_12 -> V_145 -> V_177 . V_178 ,
V_12 -> V_145 -> V_177 . V_179 ,
V_12 -> V_145 -> V_177 . V_180 ) ;
F_122 ( V_171 -> V_145 , V_12 -> V_145 -> V_181 ,
sizeof( V_171 -> V_145 ) ) ;
}
static void F_123 ( struct V_80 * V_30 ,
struct V_182 * V_183 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
V_183 -> V_184 = V_19 -> V_185 . V_184 ;
V_183 -> V_186 = V_19 -> V_185 . V_186 ;
}
static int F_124 ( struct V_19 * V_19 ,
struct V_182 * V_183 )
{
char V_187 [ V_188 ] ;
F_125 ( V_187 , V_19 -> V_10 ) ;
F_126 ( V_187 , V_183 -> V_184 ) ;
F_127 ( V_187 , V_183 -> V_186 ) ;
return F_16 ( V_19 -> V_12 -> V_16 , F_12 ( V_189 ) ,
V_187 ) ;
}
static int F_128 ( struct V_80 * V_30 ,
struct V_182 * V_183 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
bool V_99 = V_183 -> V_186 || V_183 -> V_184 ;
int V_15 ;
if ( V_19 -> V_115 . V_112 && V_19 -> V_115 . V_112 -> V_100 ) {
F_115 ( V_30 , L_19 ) ;
return - V_47 ;
}
if ( V_183 -> V_190 ) {
F_115 ( V_30 , L_20 ) ;
return - V_47 ;
}
V_15 = F_79 ( V_19 , V_30 -> V_41 , V_99 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_21 ) ;
return V_15 ;
}
V_15 = F_124 ( V_19 , V_183 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_22 ) ;
goto V_191;
}
V_19 -> V_185 . V_184 = V_183 -> V_184 ;
V_19 -> V_185 . V_186 = V_183 -> V_186 ;
return 0 ;
V_191:
V_99 = F_81 ( V_19 ) ;
F_79 ( V_19 , V_30 -> V_41 , V_99 ) ;
return V_15 ;
}
static void F_129 ( struct V_80 * V_30 ,
T_5 V_192 , T_2 * V_193 )
{
T_2 * V_92 = V_193 ;
int V_79 ;
switch ( V_192 ) {
case V_194 :
for ( V_79 = 0 ; V_79 < V_195 ; V_79 ++ ) {
memcpy ( V_92 , V_196 [ V_79 ] . V_197 ,
V_198 ) ;
V_92 += V_198 ;
}
break;
}
}
static int F_130 ( struct V_80 * V_30 ,
enum V_199 V_35 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_200 [ V_201 ] ;
bool V_202 ;
switch ( V_35 ) {
case V_203 :
V_202 = true ;
break;
case V_204 :
V_202 = false ;
break;
default:
return - V_205 ;
}
F_131 ( V_200 , V_19 -> V_10 , V_202 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_206 ) , V_200 ) ;
}
static void F_132 ( struct V_80 * V_30 ,
struct V_207 * V_119 , T_4 * V_193 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_208 [ V_209 ] ;
int V_79 ;
int V_15 ;
F_133 ( V_208 , V_19 -> V_10 ,
V_210 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_211 ) , V_208 ) ;
for ( V_79 = 0 ; V_79 < V_195 ; V_79 ++ )
V_193 [ V_79 ] = ! V_15 ? V_196 [ V_79 ] . F_134 ( V_208 ) : 0 ;
}
static int F_135 ( struct V_80 * V_30 , int V_212 )
{
switch ( V_212 ) {
case V_194 :
return V_195 ;
default:
return - V_205 ;
}
}
static T_5 F_136 ( T_5 V_213 )
{
if ( V_213 & ( V_214 |
V_215 |
V_216 |
V_217 |
V_218 |
V_219 ) )
return V_220 ;
if ( V_213 & ( V_221 |
V_222 |
V_223 |
V_224 |
V_225 ) )
return V_226 ;
return 0 ;
}
static T_5 F_137 ( T_5 V_213 )
{
T_5 V_227 = 0 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_228 ; V_79 ++ ) {
if ( V_213 & V_229 [ V_79 ] . V_230 )
V_227 |= V_229 [ V_79 ] . V_231 ;
}
return V_227 ;
}
static T_5 F_138 ( T_5 V_213 )
{
T_5 V_227 = 0 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_228 ; V_79 ++ ) {
if ( V_213 & V_229 [ V_79 ] . V_230 )
V_227 |= V_229 [ V_79 ] . V_232 ;
}
return V_227 ;
}
static void F_139 ( bool V_233 , T_5 V_213 ,
struct V_234 * V_235 )
{
T_5 V_236 = V_237 ;
T_2 V_238 = V_239 ;
int V_79 ;
if ( ! V_233 )
goto V_240;
for ( V_79 = 0 ; V_79 < V_228 ; V_79 ++ ) {
if ( V_213 & V_229 [ V_79 ] . V_230 ) {
V_236 = V_229 [ V_79 ] . V_236 ;
V_238 = V_241 ;
break;
}
}
V_240:
F_140 ( V_235 , V_236 ) ;
V_235 -> V_238 = V_238 ;
}
static T_2 F_141 ( T_5 V_213 )
{
if ( V_213 & ( V_215 |
V_217 |
V_218 |
V_219 ) )
return V_242 ;
if ( V_213 & ( V_214 |
V_216 |
V_243 ) )
return V_244 ;
if ( V_213 & ( V_221 |
V_222 |
V_223 |
V_224 ) )
return V_245 ;
return V_246 ;
}
static int F_142 ( struct V_80 * V_30 ,
struct V_234 * V_235 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_247 [ V_248 ] ;
T_5 V_249 ;
T_5 V_250 ;
T_5 V_251 ;
int V_15 ;
F_143 ( V_247 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_252 ) , V_247 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_23 ) ;
return V_15 ;
}
F_144 ( V_247 , & V_249 ,
& V_250 , & V_251 ) ;
V_235 -> V_231 = F_136 ( V_249 ) |
F_137 ( V_249 ) |
V_253 | V_254 |
V_255 ;
V_235 -> V_256 = F_138 ( V_250 ) ;
F_139 ( F_145 ( V_30 ) ,
V_251 , V_235 ) ;
V_251 = V_251 ? V_251 : V_249 ;
V_235 -> V_257 = F_141 ( V_251 ) ;
V_235 -> V_258 = F_138 ( V_251 ) ;
V_235 -> V_259 = V_260 ;
return 0 ;
}
static T_5 F_146 ( T_5 V_256 )
{
T_5 V_261 = 0 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_228 ; V_79 ++ ) {
if ( V_256 & V_229 [ V_79 ] . V_232 )
V_261 |= V_229 [ V_79 ] . V_230 ;
}
return V_261 ;
}
static T_5 F_147 ( T_5 V_236 )
{
T_5 V_261 = 0 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_228 ; V_79 ++ ) {
if ( V_236 == V_229 [ V_79 ] . V_236 )
V_261 |= V_229 [ V_79 ] . V_230 ;
}
return V_261 ;
}
static T_5 F_148 ( T_5 V_262 )
{
T_5 V_261 = 0 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_228 ; V_79 ++ ) {
if ( V_229 [ V_79 ] . V_236 <= V_262 )
V_261 |= V_229 [ V_79 ] . V_230 ;
}
return V_261 ;
}
static int F_149 ( struct V_80 * V_30 ,
struct V_234 * V_235 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_247 [ V_248 ] ;
T_5 V_236 ;
T_5 V_263 ;
T_5 V_249 ;
T_5 V_250 ;
int V_15 ;
V_236 = F_150 ( V_235 ) ;
V_263 = V_235 -> V_190 == V_264 ?
F_146 ( V_235 -> V_256 ) :
F_147 ( V_236 ) ;
F_143 ( V_247 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_252 ) , V_247 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_23 ) ;
return V_15 ;
}
F_144 ( V_247 , & V_249 , & V_250 , NULL ) ;
V_263 = V_263 & V_249 ;
if ( ! V_263 ) {
F_115 ( V_30 , L_24 ) ;
return - V_47 ;
}
if ( V_263 == V_250 )
return 0 ;
F_143 ( V_247 , V_19 -> V_10 , V_263 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_252 ) , V_247 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_25 ) ;
return V_15 ;
}
if ( ! F_151 ( V_30 ) )
return 0 ;
V_15 = F_14 ( V_19 , false ) ;
if ( V_15 ) {
F_115 ( V_30 , L_26 ) ;
return V_15 ;
}
V_15 = F_14 ( V_19 , true ) ;
if ( V_15 ) {
F_115 ( V_30 , L_26 ) ;
return V_15 ;
}
return 0 ;
}
static int
F_152 ( struct V_19 * V_19 , T_2 V_77 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
T_5 V_262 = V_265 * V_77 ;
char V_247 [ V_248 ] ;
T_5 V_250 ;
V_250 = F_148 ( V_262 ) ;
F_143 ( V_247 , V_19 -> V_10 ,
V_250 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_252 ) , V_247 ) ;
}
int F_153 ( struct V_19 * V_19 ,
enum V_266 V_267 , T_2 V_268 , T_2 V_269 ,
bool V_270 , T_2 V_271 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_272 [ V_273 ] ;
F_154 ( V_272 , V_19 -> V_10 , V_267 , V_268 ,
V_269 ) ;
F_155 ( V_272 , true ) ;
F_156 ( V_272 , V_270 ) ;
F_157 ( V_272 , V_271 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_274 ) , V_272 ) ;
}
int F_158 ( struct V_19 * V_19 ,
enum V_266 V_267 , T_2 V_268 ,
T_2 V_269 , T_5 V_275 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_272 [ V_273 ] ;
F_154 ( V_272 , V_19 -> V_10 , V_267 , V_268 ,
V_269 ) ;
F_159 ( V_272 , true ) ;
F_160 ( V_272 , V_275 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_274 ) , V_272 ) ;
}
int F_161 ( struct V_19 * V_19 ,
T_2 V_276 , T_2 V_277 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_278 [ V_279 ] ;
F_162 ( V_278 , V_19 -> V_10 , V_276 ,
V_277 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_280 ) , V_278 ) ;
}
static int F_163 ( struct V_19 * V_19 )
{
int V_15 , V_79 ;
V_15 = F_153 ( V_19 ,
V_281 , 0 , 0 , false ,
0 ) ;
if ( V_15 )
return V_15 ;
for ( V_79 = 0 ; V_79 < V_110 ; V_79 ++ ) {
V_15 = F_153 ( V_19 ,
V_282 , V_79 ,
0 , false , 0 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_79 = 0 ; V_79 < V_110 ; V_79 ++ ) {
V_15 = F_153 ( V_19 ,
V_283 , V_79 , V_79 ,
false , 0 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = F_158 ( V_19 ,
V_284 , 0 , 0 ,
V_285 ) ;
if ( V_15 )
return V_15 ;
for ( V_79 = 0 ; V_79 < V_110 ; V_79 ++ ) {
V_15 = F_158 ( V_19 ,
V_282 ,
V_79 , 0 ,
V_285 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_79 = 0 ; V_79 < V_110 ; V_79 ++ ) {
V_15 = F_158 ( V_19 ,
V_283 ,
V_79 , V_79 ,
V_285 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_79 = 0 ; V_79 < V_110 ; V_79 ++ ) {
V_15 = F_161 ( V_19 , V_79 , 0 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_164 ( struct V_12 * V_12 , T_2 V_10 ,
bool V_169 , T_2 V_76 , T_2 V_77 , T_2 V_78 )
{
struct V_19 * V_19 ;
struct V_80 * V_30 ;
T_8 V_286 ;
int V_15 ;
V_30 = F_165 ( sizeof( struct V_19 ) ) ;
if ( ! V_30 )
return - V_39 ;
V_19 = F_52 ( V_30 ) ;
V_19 -> V_30 = V_30 ;
V_19 -> V_12 = V_12 ;
V_19 -> V_10 = V_10 ;
V_19 -> V_169 = V_169 ;
V_19 -> V_168 . V_76 = V_76 ;
V_19 -> V_168 . V_77 = V_77 ;
V_19 -> V_168 . V_78 = V_78 ;
V_286 = F_166 ( V_133 , V_287 ) ;
V_19 -> V_288 = F_103 ( V_286 , V_38 ) ;
if ( ! V_19 -> V_288 ) {
V_15 = - V_39 ;
goto V_289;
}
V_19 -> V_290 = F_103 ( V_286 , V_38 ) ;
if ( ! V_19 -> V_290 ) {
V_15 = - V_39 ;
goto V_291;
}
F_167 ( & V_19 -> V_156 ) ;
V_19 -> V_82 =
F_168 ( struct V_81 ) ;
if ( ! V_19 -> V_82 ) {
V_15 = - V_39 ;
goto V_292;
}
V_30 -> V_293 = & V_294 ;
V_30 -> V_295 = & V_296 ;
V_15 = F_20 ( V_19 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_27 ,
V_19 -> V_10 ) ;
goto V_297;
}
F_169 ( V_30 ) ;
V_30 -> V_298 |= V_299 | V_300 | V_301 |
V_302 ;
V_30 -> V_303 += V_6 ;
V_15 = F_39 ( V_19 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_28 ,
V_19 -> V_10 ) ;
goto V_304;
}
V_15 = F_32 ( V_19 , 0 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_29 ,
V_19 -> V_10 ) ;
goto V_305;
}
V_15 = F_152 ( V_19 , V_77 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_30 ,
V_19 -> V_10 ) ;
goto V_306;
}
V_15 = F_27 ( V_19 , V_307 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_31 ,
V_19 -> V_10 ) ;
goto V_117;
}
V_15 = F_14 ( V_19 , false ) ;
if ( V_15 )
goto V_308;
V_15 = F_170 ( V_19 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_32 ,
V_19 -> V_10 ) ;
goto V_309;
}
V_15 = F_163 ( V_19 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_33 ,
V_19 -> V_10 ) ;
goto V_310;
}
V_15 = F_171 ( V_19 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_34 ,
V_19 -> V_10 ) ;
goto V_311;
}
F_172 ( V_19 ) ;
V_15 = F_173 ( V_30 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_35 ,
V_19 -> V_10 ) ;
goto V_312;
}
V_15 = F_174 ( V_12 -> V_16 , & V_19 -> V_313 ,
V_19 -> V_10 , V_30 ,
V_19 -> V_169 , V_76 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_36 ,
V_19 -> V_10 ) ;
goto V_314;
}
V_15 = F_175 ( V_19 ) ;
if ( V_15 )
goto V_315;
V_12 -> V_316 [ V_10 ] = V_19 ;
return 0 ;
V_315:
F_176 ( & V_19 -> V_313 ) ;
V_314:
F_177 ( V_30 ) ;
V_312:
V_311:
V_310:
V_309:
V_308:
V_117:
V_306:
V_305:
V_304:
V_297:
F_178 ( V_19 -> V_82 ) ;
V_292:
F_26 ( V_19 -> V_290 ) ;
V_291:
F_26 ( V_19 -> V_288 ) ;
V_289:
F_179 ( V_30 ) ;
return V_15 ;
}
static void F_180 ( struct V_19 * V_19 )
{
struct V_80 * V_30 = V_19 -> V_30 ;
struct V_19 * V_150 , * V_317 ;
F_181 (mlxsw_sp_vport, tmp,
&mlxsw_sp_port->vports_list, vport.list) {
T_1 V_33 = F_182 ( V_150 ) ;
F_183 ( F_184 ( V_150 -> V_30 ) ) ;
F_119 ( V_30 , 0 , V_33 ) ;
}
}
static void F_185 ( struct V_12 * V_12 , T_2 V_10 )
{
struct V_19 * V_19 = V_12 -> V_316 [ V_10 ] ;
if ( ! V_19 )
return;
V_12 -> V_316 [ V_10 ] = NULL ;
F_176 ( & V_19 -> V_313 ) ;
F_177 ( V_19 -> V_30 ) ;
F_186 ( V_19 ) ;
F_180 ( V_19 ) ;
F_187 ( V_19 ) ;
F_32 ( V_19 , V_318 ) ;
F_50 ( V_12 , V_19 -> V_10 ) ;
F_178 ( V_19 -> V_82 ) ;
F_26 ( V_19 -> V_290 ) ;
F_26 ( V_19 -> V_288 ) ;
F_179 ( V_19 -> V_30 ) ;
}
static void F_188 ( struct V_12 * V_12 )
{
int V_79 ;
for ( V_79 = 1 ; V_79 < V_319 ; V_79 ++ )
F_185 ( V_12 , V_79 ) ;
F_26 ( V_12 -> V_316 ) ;
}
static int F_189 ( struct V_12 * V_12 )
{
T_2 V_76 , V_77 , V_78 ;
T_8 V_320 ;
int V_79 ;
int V_15 ;
V_320 = sizeof( struct V_19 * ) * V_319 ;
V_12 -> V_316 = F_103 ( V_320 , V_38 ) ;
if ( ! V_12 -> V_316 )
return - V_39 ;
for ( V_79 = 1 ; V_79 < V_319 ; V_79 ++ ) {
V_15 = F_41 ( V_12 , V_79 , & V_76 ,
& V_77 , & V_78 ) ;
if ( V_15 )
goto V_321;
if ( ! V_77 )
continue;
V_12 -> V_322 [ V_79 ] = V_76 ;
V_15 = F_164 ( V_12 , V_79 , false , V_76 , V_77 ,
V_78 ) ;
if ( V_15 )
goto V_323;
}
return 0 ;
V_323:
V_321:
for ( V_79 -- ; V_79 >= 1 ; V_79 -- )
F_185 ( V_12 , V_79 ) ;
F_26 ( V_12 -> V_316 ) ;
return V_15 ;
}
static T_2 F_190 ( T_2 V_10 )
{
T_2 V_324 = ( V_10 - 1 ) % V_325 ;
return V_10 - V_324 ;
}
static int F_191 ( struct V_12 * V_12 , T_2 V_326 ,
T_2 V_76 , unsigned int V_327 )
{
T_2 V_77 = V_328 / V_327 ;
int V_15 , V_79 ;
for ( V_79 = 0 ; V_79 < V_327 ; V_79 ++ ) {
V_15 = F_46 ( V_12 , V_326 + V_79 , V_76 ,
V_77 , V_79 * V_77 ) ;
if ( V_15 )
goto V_329;
}
for ( V_79 = 0 ; V_79 < V_327 ; V_79 ++ ) {
V_15 = F_30 ( V_12 , V_326 + V_79 , 0 ) ;
if ( V_15 )
goto V_305;
}
for ( V_79 = 0 ; V_79 < V_327 ; V_79 ++ ) {
V_15 = F_164 ( V_12 , V_326 + V_79 , true ,
V_76 , V_77 , V_79 * V_77 ) ;
if ( V_15 )
goto V_323;
}
return 0 ;
V_323:
for ( V_79 -- ; V_79 >= 0 ; V_79 -- )
F_185 ( V_12 , V_326 + V_79 ) ;
V_79 = V_327 ;
V_305:
for ( V_79 -- ; V_79 >= 0 ; V_79 -- )
F_30 ( V_12 , V_326 + V_79 ,
V_318 ) ;
V_79 = V_327 ;
V_329:
for ( V_79 -- ; V_79 >= 0 ; V_79 -- )
F_50 ( V_12 , V_326 + V_79 ) ;
return V_15 ;
}
static void F_192 ( struct V_12 * V_12 ,
T_2 V_326 , unsigned int V_327 )
{
T_2 V_10 , V_76 , V_77 = V_328 ;
int V_79 ;
V_327 = V_327 / 2 ;
for ( V_79 = 0 ; V_79 < V_327 ; V_79 ++ ) {
V_10 = V_326 + V_79 * 2 ;
V_76 = V_12 -> V_322 [ V_10 ] ;
F_46 ( V_12 , V_10 , V_76 , V_77 ,
0 ) ;
}
for ( V_79 = 0 ; V_79 < V_327 ; V_79 ++ )
F_30 ( V_12 , V_326 + V_79 * 2 , 0 ) ;
for ( V_79 = 0 ; V_79 < V_327 ; V_79 ++ ) {
V_10 = V_326 + V_79 * 2 ;
V_76 = V_12 -> V_322 [ V_10 ] ;
F_164 ( V_12 , V_10 , false , V_76 ,
V_77 , 0 ) ;
}
}
static int F_193 ( struct V_330 * V_330 , T_2 V_10 ,
unsigned int V_327 )
{
struct V_12 * V_12 = F_194 ( V_330 ) ;
struct V_19 * V_19 ;
T_2 V_76 , V_331 , V_326 ;
int V_79 ;
int V_15 ;
V_19 = V_12 -> V_316 [ V_10 ] ;
if ( ! V_19 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_37 ,
V_10 ) ;
return - V_47 ;
}
V_76 = V_19 -> V_168 . V_76 ;
V_331 = V_19 -> V_168 . V_77 ;
if ( V_327 != 2 && V_327 != 4 ) {
F_115 ( V_19 -> V_30 , L_38 ) ;
return - V_47 ;
}
if ( V_331 != V_328 ) {
F_115 ( V_19 -> V_30 , L_39 ) ;
return - V_47 ;
}
if ( V_327 == 2 ) {
V_326 = V_10 ;
if ( V_12 -> V_316 [ V_326 + 1 ] ) {
F_115 ( V_19 -> V_30 , L_40 ) ;
return - V_47 ;
}
} else {
V_326 = F_190 ( V_10 ) ;
if ( V_12 -> V_316 [ V_326 + 1 ] ||
V_12 -> V_316 [ V_326 + 3 ] ) {
F_115 ( V_19 -> V_30 , L_40 ) ;
return - V_47 ;
}
}
for ( V_79 = 0 ; V_79 < V_327 ; V_79 ++ )
F_185 ( V_12 , V_326 + V_79 ) ;
V_15 = F_191 ( V_12 , V_326 , V_76 , V_327 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_41 ) ;
goto V_332;
}
return 0 ;
V_332:
F_192 ( V_12 , V_326 , V_327 ) ;
return V_15 ;
}
static int F_195 ( struct V_330 * V_330 , T_2 V_10 )
{
struct V_12 * V_12 = F_194 ( V_330 ) ;
struct V_19 * V_19 ;
T_2 V_331 , V_326 ;
unsigned int V_327 ;
int V_79 ;
V_19 = V_12 -> V_316 [ V_10 ] ;
if ( ! V_19 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_37 ,
V_10 ) ;
return - V_47 ;
}
if ( ! V_19 -> V_169 ) {
F_115 ( V_19 -> V_30 , L_42 ) ;
return - V_47 ;
}
V_331 = V_19 -> V_168 . V_77 ;
V_327 = V_331 == 1 ? 4 : 2 ;
V_326 = F_190 ( V_10 ) ;
if ( V_327 == 2 && V_10 >= V_326 + 2 )
V_326 = V_326 + 2 ;
for ( V_79 = 0 ; V_79 < V_327 ; V_79 ++ )
F_185 ( V_12 , V_326 + V_79 ) ;
F_192 ( V_12 , V_326 , V_327 ) ;
return 0 ;
}
static void F_196 ( const struct V_333 * V_334 ,
char * V_335 , void * V_336 )
{
struct V_12 * V_12 = V_336 ;
struct V_19 * V_19 ;
enum V_337 V_338 ;
T_2 V_10 ;
V_10 = F_197 ( V_335 ) ;
V_19 = V_12 -> V_316 [ V_10 ] ;
if ( ! V_19 ) {
F_198 ( V_12 -> V_145 -> V_30 , L_43 ,
V_10 ) ;
return;
}
V_338 = F_199 ( V_335 ) ;
if ( V_338 == V_339 ) {
F_200 ( V_19 -> V_30 , L_44 ) ;
F_201 ( V_19 -> V_30 ) ;
} else {
F_200 ( V_19 -> V_30 , L_45 ) ;
F_169 ( V_19 -> V_30 ) ;
}
}
static int F_202 ( struct V_12 * V_12 ,
enum V_340 V_341 )
{
struct V_342 * V_343 ;
char V_344 [ V_345 ] ;
int V_15 ;
switch ( V_341 ) {
case V_346 :
V_343 = & V_347 ;
break;
}
V_15 = F_203 ( V_12 -> V_16 , V_343 , V_12 ) ;
if ( V_15 )
return V_15 ;
F_204 ( V_344 , V_348 , V_341 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_349 ) , V_344 ) ;
if ( V_15 )
goto V_350;
return 0 ;
V_350:
F_205 ( V_12 -> V_16 , V_343 , V_12 ) ;
return V_15 ;
}
static void F_206 ( struct V_12 * V_12 ,
enum V_340 V_341 )
{
struct V_342 * V_343 ;
switch ( V_341 ) {
case V_346 :
V_343 = & V_347 ;
break;
}
F_205 ( V_12 -> V_16 , V_343 , V_12 ) ;
}
static void F_207 ( struct V_1 * V_2 , T_2 V_10 ,
void * V_336 )
{
struct V_12 * V_12 = V_336 ;
struct V_19 * V_19 = V_12 -> V_316 [ V_10 ] ;
struct V_81 * V_82 ;
if ( F_58 ( ! V_19 ) ) {
F_208 ( V_12 -> V_145 -> V_30 , L_46 ,
V_10 ) ;
return;
}
V_2 -> V_30 = V_19 -> V_30 ;
V_82 = F_65 ( V_19 -> V_82 ) ;
F_66 ( & V_82 -> V_89 ) ;
V_82 -> V_120 ++ ;
V_82 -> V_121 += V_2 -> V_84 ;
F_67 ( & V_82 -> V_89 ) ;
V_2 -> V_351 = F_209 ( V_2 , V_2 -> V_30 ) ;
F_210 ( V_2 ) ;
}
static int F_211 ( struct V_12 * V_12 )
{
char V_352 [ V_353 ] ;
char V_344 [ V_345 ] ;
int V_79 ;
int V_15 ;
F_212 ( V_352 , V_354 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_355 ) , V_352 ) ;
if ( V_15 )
return V_15 ;
F_212 ( V_352 , V_356 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_355 ) , V_352 ) ;
if ( V_15 )
return V_15 ;
for ( V_79 = 0 ; V_79 < F_213 ( V_357 ) ; V_79 ++ ) {
V_15 = F_214 ( V_12 -> V_16 ,
& V_357 [ V_79 ] ,
V_12 ) ;
if ( V_15 )
goto V_358;
F_204 ( V_344 , V_359 ,
V_357 [ V_79 ] . V_341 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_349 ) , V_344 ) ;
if ( V_15 )
goto V_360;
}
return 0 ;
V_360:
F_215 ( V_12 -> V_16 ,
& V_357 [ V_79 ] ,
V_12 ) ;
V_358:
for ( V_79 -- ; V_79 >= 0 ; V_79 -- ) {
F_204 ( V_344 , V_348 ,
V_357 [ V_79 ] . V_341 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_349 ) , V_344 ) ;
F_215 ( V_12 -> V_16 ,
& V_357 [ V_79 ] ,
V_12 ) ;
}
return V_15 ;
}
static void F_216 ( struct V_12 * V_12 )
{
char V_344 [ V_345 ] ;
int V_79 ;
for ( V_79 = 0 ; V_79 < F_213 ( V_357 ) ; V_79 ++ ) {
F_204 ( V_344 , V_348 ,
V_357 [ V_79 ] . V_341 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_349 ) , V_344 ) ;
F_215 ( V_12 -> V_16 ,
& V_357 [ V_79 ] ,
V_12 ) ;
}
}
static int F_217 ( struct V_330 * V_330 ,
enum V_361 type ,
enum V_362 V_363 )
{
enum V_364 V_365 ;
enum V_366 V_367 ;
char V_368 [ V_369 ] ;
if ( V_363 == V_370 )
V_365 = V_371 ;
else
V_365 = V_372 ;
if ( type == V_373 )
V_367 = V_374 ;
else
V_367 = V_375 ;
F_218 ( V_368 , type , V_363 , V_365 ,
V_367 ) ;
return F_16 ( V_330 , F_12 ( V_376 ) , V_368 ) ;
}
static int F_219 ( struct V_12 * V_12 )
{
int type , V_15 ;
for ( type = 0 ; type < V_377 ; type ++ ) {
if ( type == V_378 )
continue;
V_15 = F_217 ( V_12 -> V_16 , type ,
V_370 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_217 ( V_12 -> V_16 , type ,
V_379 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_220 ( struct V_12 * V_12 )
{
char V_380 [ V_381 ] ;
F_221 ( V_380 , V_382 |
V_383 |
V_384 |
V_385 |
V_386 |
V_387 |
V_388 |
V_389 |
V_390 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_391 ) , V_380 ) ;
}
static int F_222 ( struct V_330 * V_330 ,
const struct V_392 * V_392 )
{
struct V_12 * V_12 = F_194 ( V_330 ) ;
int V_15 ;
V_12 -> V_16 = V_330 ;
V_12 -> V_145 = V_392 ;
F_167 ( & V_12 -> V_136 . V_149 ) ;
F_167 ( & V_12 -> V_393 . V_149 ) ;
F_167 ( & V_12 -> V_394 . V_149 ) ;
V_15 = F_10 ( V_12 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_47 ) ;
return V_15 ;
}
V_15 = F_189 ( V_12 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_48 ) ;
return V_15 ;
}
V_15 = F_202 ( V_12 , V_346 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_49 ) ;
goto V_395;
}
V_15 = F_211 ( V_12 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_50 ) ;
goto V_358;
}
V_15 = F_219 ( V_12 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_51 ) ;
goto V_396;
}
V_15 = F_223 ( V_12 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_52 ) ;
goto V_397;
}
V_15 = F_220 ( V_12 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_53 ) ;
goto V_398;
}
V_15 = F_224 ( V_12 ) ;
if ( V_15 ) {
F_101 ( V_12 -> V_145 -> V_30 , L_54 ) ;
goto V_399;
}
return 0 ;
V_399:
V_398:
F_225 ( V_12 ) ;
V_397:
V_396:
F_216 ( V_12 ) ;
V_358:
F_206 ( V_12 , V_346 ) ;
V_395:
F_188 ( V_12 ) ;
return V_15 ;
}
static void F_226 ( struct V_330 * V_330 )
{
struct V_12 * V_12 = F_194 ( V_330 ) ;
F_227 ( V_12 ) ;
F_225 ( V_12 ) ;
F_216 ( V_12 ) ;
F_206 ( V_12 , V_346 ) ;
F_188 ( V_12 ) ;
}
static int
F_228 ( const struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_400 [ V_401 ] ;
F_229 ( V_400 , V_402 ) ;
F_230 ( V_400 , V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_403 ) , V_400 ) ;
}
static int
F_231 ( const struct V_19 * V_19 ,
T_1 V_59 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_400 [ V_401 ] ;
F_229 ( V_400 , V_404 ) ;
F_232 ( V_400 , V_59 ) ;
F_233 ( V_400 ,
V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_403 ) , V_400 ) ;
}
static int
F_234 ( const struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_400 [ V_401 ] ;
F_229 ( V_400 , V_405 ) ;
F_235 ( V_400 , V_19 -> V_154 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_403 ) , V_400 ) ;
}
static int
F_236 ( const struct V_19 * V_19 ,
T_1 V_59 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_400 [ V_401 ] ;
F_229 ( V_400 , V_406 ) ;
F_232 ( V_400 , V_59 ) ;
F_237 ( V_400 , V_19 -> V_154 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_403 ) , V_400 ) ;
}
static int
F_238 ( const struct V_19 * V_19 )
{
int V_15 , V_407 = 0 ;
T_1 V_33 ;
for ( V_33 = 1 ; V_33 < V_133 - 1 ; V_33 ++ ) {
V_15 = F_231 ( V_19 , V_33 ) ;
if ( V_15 )
V_407 = V_15 ;
}
return V_407 ;
}
static int
F_239 ( const struct V_19 * V_19 )
{
int V_15 , V_407 = 0 ;
T_1 V_33 ;
for ( V_33 = 1 ; V_33 < V_133 - 1 ; V_33 ++ ) {
V_15 = F_236 ( V_19 , V_33 ) ;
if ( V_15 )
V_407 = V_15 ;
}
return V_407 ;
}
static int F_240 ( struct V_19 * V_19 )
{
if ( ! F_241 ( & V_19 -> V_156 ) )
if ( V_19 -> V_153 )
return F_239 ( V_19 ) ;
else
return F_238 ( V_19 ) ;
else
if ( V_19 -> V_153 )
return F_234 ( V_19 ) ;
else
return F_228 ( V_19 ) ;
}
static int F_242 ( struct V_19 * V_150 )
{
T_1 V_135 = F_243 ( V_150 ) ;
T_1 V_59 = F_97 ( V_135 ) ;
if ( V_150 -> V_153 )
return F_236 ( V_150 ,
V_59 ) ;
else
return F_231 ( V_150 , V_59 ) ;
}
static bool F_244 ( const struct V_80 * V_30 )
{
return V_30 -> V_293 == & V_294 ;
}
static int F_245 ( struct V_19 * V_19 )
{
struct V_80 * V_30 = V_19 -> V_30 ;
int V_15 ;
V_15 = F_119 ( V_30 , 0 , 1 ) ;
if ( V_15 )
return V_15 ;
V_19 -> V_408 = 1 ;
V_19 -> V_409 = 1 ;
V_19 -> V_410 = 1 ;
V_19 -> V_411 = 1 ;
return 0 ;
}
static int F_246 ( struct V_19 * V_19 ,
bool V_412 )
{
struct V_80 * V_30 = V_19 -> V_30 ;
if ( V_412 && F_240 ( V_19 ) )
F_115 ( V_19 -> V_30 , L_55 ) ;
F_247 ( V_19 , 1 ) ;
V_19 -> V_408 = 0 ;
V_19 -> V_409 = 0 ;
V_19 -> V_410 = 0 ;
V_19 -> V_411 = 0 ;
return F_111 ( V_30 , 0 , 1 ) ;
}
static bool F_248 ( struct V_12 * V_12 ,
struct V_80 * V_413 )
{
return ! V_12 -> V_414 . V_30 ||
V_12 -> V_414 . V_30 == V_413 ;
}
static void F_249 ( struct V_12 * V_12 ,
struct V_80 * V_413 )
{
V_12 -> V_414 . V_30 = V_413 ;
V_12 -> V_414 . V_415 ++ ;
}
static void F_250 ( struct V_12 * V_12 ,
struct V_80 * V_413 )
{
if ( -- V_12 -> V_414 . V_415 == 0 )
V_12 -> V_414 . V_30 = NULL ;
}
static int F_251 ( struct V_12 * V_12 , T_1 V_154 )
{
char V_416 [ V_417 ] ;
F_252 ( V_416 , V_154 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_418 ) , V_416 ) ;
}
static int F_253 ( struct V_12 * V_12 , T_1 V_154 )
{
char V_416 [ V_417 ] ;
F_254 ( V_416 , V_154 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_418 ) , V_416 ) ;
}
static int F_255 ( struct V_19 * V_19 ,
T_1 V_154 , T_2 V_419 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_420 [ V_421 ] ;
F_256 ( V_420 , V_19 -> V_10 ,
V_154 , V_419 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_422 ) , V_420 ) ;
}
static int F_257 ( struct V_19 * V_19 ,
T_1 V_154 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_420 [ V_421 ] ;
F_258 ( V_420 , V_19 -> V_10 ,
V_154 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_422 ) , V_420 ) ;
}
static int F_259 ( struct V_19 * V_19 ,
T_1 V_154 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_420 [ V_421 ] ;
F_260 ( V_420 , V_19 -> V_10 ,
V_154 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_422 ) , V_420 ) ;
}
static int F_261 ( struct V_19 * V_19 ,
T_1 V_154 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_420 [ V_421 ] ;
F_262 ( V_420 , V_19 -> V_10 ,
V_154 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_422 ) , V_420 ) ;
}
static int F_263 ( struct V_12 * V_12 ,
struct V_80 * V_423 ,
T_1 * V_424 )
{
struct V_425 * V_426 ;
int V_427 = - 1 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_428 ; V_79 ++ ) {
V_426 = F_264 ( V_12 , V_79 ) ;
if ( V_426 -> V_415 ) {
if ( V_426 -> V_30 == V_423 ) {
* V_424 = V_79 ;
return 0 ;
}
} else if ( V_427 < 0 ) {
V_427 = V_79 ;
}
}
if ( V_427 < 0 )
return - V_429 ;
* V_424 = V_427 ;
return 0 ;
}
static bool
F_265 ( struct V_12 * V_12 ,
struct V_80 * V_423 ,
struct V_430 * V_431 )
{
T_1 V_154 ;
if ( F_263 ( V_12 , V_423 , & V_154 ) != 0 )
return false ;
if ( V_431 -> V_432 != V_433 )
return false ;
return true ;
}
static int F_266 ( struct V_12 * V_12 ,
T_1 V_154 , T_2 * V_434 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_435 ; V_79 ++ ) {
if ( ! F_267 ( V_12 , V_154 , V_79 ) ) {
* V_434 = V_79 ;
return 0 ;
}
}
return - V_429 ;
}
static int F_268 ( struct V_19 * V_19 ,
struct V_80 * V_423 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_425 * V_426 ;
T_1 V_154 ;
T_2 V_419 ;
int V_15 ;
V_15 = F_263 ( V_12 , V_423 , & V_154 ) ;
if ( V_15 )
return V_15 ;
V_426 = F_264 ( V_12 , V_154 ) ;
if ( ! V_426 -> V_415 ) {
V_15 = F_251 ( V_12 , V_154 ) ;
if ( V_15 )
return V_15 ;
V_426 -> V_30 = V_423 ;
}
V_15 = F_266 ( V_12 , V_154 , & V_419 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_255 ( V_19 , V_154 , V_419 ) ;
if ( V_15 )
goto V_436;
V_15 = F_259 ( V_19 , V_154 ) ;
if ( V_15 )
goto V_437;
F_269 ( V_12 -> V_16 , V_154 , V_419 ,
V_19 -> V_10 ) ;
V_19 -> V_154 = V_154 ;
V_19 -> V_153 = 1 ;
V_426 -> V_415 ++ ;
return 0 ;
V_437:
F_257 ( V_19 , V_154 ) ;
V_436:
if ( ! V_426 -> V_415 )
F_253 ( V_12 , V_154 ) ;
return V_15 ;
}
static int F_270 ( struct V_19 * V_19 ,
struct V_80 * V_423 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_19 * V_150 ;
struct V_425 * V_426 ;
T_1 V_154 = V_19 -> V_154 ;
int V_15 ;
if ( ! V_19 -> V_153 )
return 0 ;
V_426 = F_264 ( V_12 , V_154 ) ;
F_183 ( V_426 -> V_415 == 0 ) ;
V_15 = F_261 ( V_19 , V_154 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_257 ( V_19 , V_154 ) ;
if ( V_15 )
return V_15 ;
F_93 (mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
struct V_80 * V_413 ;
if ( ! V_150 -> V_411 )
continue;
V_413 = F_271 ( V_150 ) ;
F_272 ( V_150 , V_413 , false ) ;
}
if ( V_19 -> V_411 ) {
F_273 ( V_19 ) ;
F_246 ( V_19 , false ) ;
F_250 ( V_12 , NULL ) ;
}
if ( V_426 -> V_415 == 1 ) {
if ( F_234 ( V_19 ) )
F_115 ( V_19 -> V_30 , L_55 ) ;
V_15 = F_253 ( V_12 , V_154 ) ;
if ( V_15 )
return V_15 ;
}
F_274 ( V_12 -> V_16 , V_154 ,
V_19 -> V_10 ) ;
V_19 -> V_153 = 0 ;
V_426 -> V_415 -- ;
return 0 ;
}
static int F_275 ( struct V_19 * V_19 ,
T_1 V_154 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_416 [ V_417 ] ;
F_276 ( V_416 , V_154 ,
V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_418 ) , V_416 ) ;
}
static int F_277 ( struct V_19 * V_19 ,
T_1 V_154 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_416 [ V_417 ] ;
F_278 ( V_416 , V_154 ,
V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_418 ) , V_416 ) ;
}
static int F_279 ( struct V_19 * V_19 ,
bool V_438 )
{
if ( V_438 )
return F_275 ( V_19 ,
V_19 -> V_154 ) ;
else
return F_277 ( V_19 ,
V_19 -> V_154 ) ;
}
static int F_280 ( struct V_19 * V_19 ,
struct V_439 * V_440 )
{
return F_279 ( V_19 , V_440 -> V_441 ) ;
}
static int F_281 ( struct V_19 * V_19 ,
struct V_80 * V_442 )
{
struct V_19 * V_150 ;
T_1 V_33 = F_282 ( V_442 ) ;
V_150 = F_112 ( V_19 , V_33 ) ;
if ( ! V_150 ) {
F_183 ( ! V_150 ) ;
return - V_47 ;
}
V_150 -> V_30 = V_442 ;
return 0 ;
}
static int F_283 ( struct V_19 * V_19 ,
struct V_80 * V_442 )
{
struct V_19 * V_150 ;
T_1 V_33 = F_282 ( V_442 ) ;
V_150 = F_112 ( V_19 , V_33 ) ;
if ( ! V_150 ) {
F_183 ( ! V_150 ) ;
return - V_47 ;
}
if ( V_150 -> V_411 ) {
struct V_80 * V_413 ;
V_413 = F_271 ( V_150 ) ;
F_272 ( V_150 , V_413 , true ) ;
}
V_150 -> V_30 = V_19 -> V_30 ;
return 0 ;
}
static int F_284 ( struct V_80 * V_30 ,
unsigned long V_443 , void * V_444 )
{
struct V_445 * V_440 ;
struct V_19 * V_19 ;
struct V_80 * V_446 ;
struct V_12 * V_12 ;
int V_15 ;
V_19 = F_52 ( V_30 ) ;
V_12 = V_19 -> V_12 ;
V_440 = V_444 ;
switch ( V_443 ) {
case V_447 :
V_446 = V_440 -> V_446 ;
if ( ! V_440 -> V_448 || ! V_440 -> V_449 )
break;
if ( F_285 ( V_446 ) &&
! F_248 ( V_12 , V_446 ) )
return V_450 ;
if ( F_286 ( V_446 ) &&
! F_265 ( V_12 , V_446 ,
V_440 -> V_451 ) )
return V_450 ;
break;
case V_452 :
V_446 = V_440 -> V_446 ;
if ( F_184 ( V_446 ) ) {
if ( V_440 -> V_449 ) {
V_15 = F_281 ( V_19 ,
V_446 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_56 ) ;
return V_450 ;
}
} else {
V_15 = F_283 ( V_19 ,
V_446 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_57 ) ;
return V_450 ;
}
}
} else if ( F_285 ( V_446 ) ) {
if ( V_440 -> V_449 ) {
V_15 = F_245 ( V_19 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_58 ) ;
return V_450 ;
}
F_249 ( V_12 , V_446 ) ;
} else {
V_15 = F_246 ( V_19 ,
true ) ;
F_250 ( V_12 , V_446 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_59 ) ;
return V_450 ;
}
}
} else if ( F_286 ( V_446 ) ) {
if ( V_440 -> V_449 ) {
V_15 = F_268 ( V_19 ,
V_446 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_60 ) ;
return V_450 ;
}
} else {
V_15 = F_270 ( V_19 ,
V_446 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_61 ) ;
return V_450 ;
}
}
}
break;
}
return V_453 ;
}
static int F_287 ( struct V_80 * V_30 ,
unsigned long V_443 , void * V_444 )
{
struct V_454 * V_440 ;
struct V_19 * V_19 ;
int V_15 ;
V_19 = F_52 ( V_30 ) ;
V_440 = V_444 ;
switch ( V_443 ) {
case V_455 :
if ( F_288 ( V_30 ) && V_19 -> V_153 ) {
V_15 = F_280 ( V_19 ,
V_440 -> V_456 ) ;
if ( V_15 )
F_115 ( V_30 , L_62 ) ;
}
break;
}
return V_453 ;
}
static int F_289 ( struct V_80 * V_30 ,
unsigned long V_443 , void * V_444 )
{
switch ( V_443 ) {
case V_447 :
case V_452 :
return F_284 ( V_30 , V_443 , V_444 ) ;
case V_455 :
return F_287 ( V_30 , V_443 , V_444 ) ;
}
return V_453 ;
}
static int F_290 ( struct V_80 * V_423 ,
unsigned long V_443 , void * V_444 )
{
struct V_80 * V_30 ;
struct V_457 * V_458 ;
int V_459 ;
F_291 (lag_dev, dev, iter) {
if ( F_244 ( V_30 ) ) {
V_459 = F_289 ( V_30 , V_443 , V_444 ) ;
if ( V_459 == V_450 )
return V_459 ;
}
}
return V_453 ;
}
static struct V_134 *
F_292 ( const struct V_12 * V_12 ,
const struct V_80 * V_413 )
{
struct V_134 * V_135 ;
F_93 (vfid, &mlxsw_sp->br_vfids.list, list) {
if ( V_135 -> V_413 == V_413 )
return V_135 ;
}
return NULL ;
}
static T_1 F_293 ( T_1 V_135 )
{
return V_135 - V_138 ;
}
static T_1 F_294 ( T_1 V_460 )
{
return V_138 + V_460 ;
}
static T_1 F_295 ( const struct V_12 * V_12 )
{
return F_95 ( V_12 -> V_393 . V_137 ,
V_461 ) ;
}
static struct V_134 * F_296 ( struct V_12 * V_12 ,
struct V_80 * V_413 )
{
struct V_144 * V_30 = V_12 -> V_145 -> V_30 ;
struct V_134 * V_135 ;
T_1 V_146 ;
int V_15 ;
V_146 = F_294 ( F_295 ( V_12 ) ) ;
if ( V_146 == V_462 ) {
F_101 ( V_30 , L_1 ) ;
return F_102 ( - V_147 ) ;
}
V_15 = F_96 ( V_12 , V_146 ) ;
if ( V_15 ) {
F_101 ( V_30 , L_2 , V_146 ) ;
return F_102 ( V_15 ) ;
}
V_135 = F_103 ( sizeof( * V_135 ) , V_38 ) ;
if ( ! V_135 )
goto V_148;
V_135 -> V_135 = V_146 ;
V_135 -> V_413 = V_413 ;
F_104 ( & V_135 -> V_149 , & V_12 -> V_393 . V_149 ) ;
F_105 ( F_293 ( V_146 ) , V_12 -> V_393 . V_137 ) ;
return V_135 ;
V_148:
F_99 ( V_12 , V_146 ) ;
return F_102 ( - V_39 ) ;
}
static void F_297 ( struct V_12 * V_12 ,
struct V_134 * V_135 )
{
T_1 V_460 = F_293 ( V_135 -> V_135 ) ;
F_107 ( V_460 , V_12 -> V_393 . V_137 ) ;
F_108 ( & V_135 -> V_149 ) ;
F_99 ( V_12 , V_135 -> V_135 ) ;
F_26 ( V_135 ) ;
}
static int F_272 ( struct V_19 * V_150 ,
struct V_80 * V_413 ,
bool V_412 )
{
struct V_12 * V_12 = V_150 -> V_12 ;
T_1 V_33 = F_182 ( V_150 ) ;
struct V_80 * V_30 = V_150 -> V_30 ;
struct V_134 * V_135 , * V_463 ;
int V_15 ;
V_135 = F_292 ( V_12 , V_413 ) ;
if ( ! V_135 ) {
F_183 ( ! V_135 ) ;
return - V_47 ;
}
V_463 = F_92 ( V_12 , V_33 ) ;
if ( ! V_463 ) {
V_463 = F_100 ( V_12 , V_33 ) ;
if ( F_114 ( V_463 ) ) {
F_115 ( V_30 , L_4 ,
V_33 ) ;
return F_116 ( V_463 ) ;
}
}
V_15 = F_35 ( V_150 ,
V_130 ,
false ,
F_97 ( V_135 -> V_135 ) ,
V_33 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_63 ,
V_135 -> V_135 ) ;
goto V_464;
}
V_15 = F_35 ( V_150 ,
V_130 ,
true ,
F_97 ( V_463 -> V_135 ) ,
V_33 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_64 ,
V_463 -> V_135 ) ;
goto V_465;
}
V_15 = F_37 ( V_150 , V_33 , false ) ;
if ( V_15 ) {
F_115 ( V_30 , L_65 ) ;
goto V_162;
}
V_15 = F_117 ( V_150 , V_135 -> V_135 , false ,
false ) ;
if ( V_15 ) {
F_115 ( V_30 , L_66 ) ;
goto V_160;
}
V_15 = F_22 ( V_150 , V_33 ,
V_164 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_67 ) ;
goto V_165;
}
if ( V_412 && F_242 ( V_150 ) )
F_115 ( V_30 , L_55 ) ;
V_463 -> V_159 ++ ;
V_150 -> V_155 . V_135 = V_463 ;
V_135 -> V_159 -- ;
if ( ! V_135 -> V_159 )
F_297 ( V_12 , V_135 ) ;
V_150 -> V_408 = 0 ;
V_150 -> V_409 = 0 ;
V_150 -> V_410 = 0 ;
V_150 -> V_411 = 0 ;
return 0 ;
V_165:
V_160:
V_162:
V_465:
V_464:
if ( ! V_463 -> V_159 )
F_106 ( V_12 , V_463 ) ;
return V_15 ;
}
static int F_298 ( struct V_19 * V_150 ,
struct V_80 * V_413 )
{
struct V_134 * V_466 = V_150 -> V_155 . V_135 ;
struct V_12 * V_12 = V_150 -> V_12 ;
T_1 V_33 = F_182 ( V_150 ) ;
struct V_80 * V_30 = V_150 -> V_30 ;
struct V_134 * V_135 ;
int V_15 ;
V_135 = F_292 ( V_12 , V_413 ) ;
if ( ! V_135 ) {
V_135 = F_296 ( V_12 , V_413 ) ;
if ( F_114 ( V_135 ) ) {
F_115 ( V_30 , L_68 ) ;
return F_116 ( V_135 ) ;
}
}
V_15 = F_117 ( V_150 , V_135 -> V_135 , true , false ) ;
if ( V_15 ) {
F_115 ( V_30 , L_6 ,
V_135 -> V_135 ) ;
goto V_467;
}
V_15 = F_37 ( V_150 , V_33 , true ) ;
if ( V_15 ) {
F_115 ( V_30 , L_69 ) ;
goto V_162;
}
V_15 = F_35 ( V_150 ,
V_130 ,
false ,
F_97 ( V_466 -> V_135 ) ,
V_33 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_63 ,
V_466 -> V_135 ) ;
goto V_464;
}
V_15 = F_35 ( V_150 ,
V_130 ,
true ,
F_97 ( V_135 -> V_135 ) ,
V_33 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_64 ,
V_135 -> V_135 ) ;
goto V_465;
}
V_135 -> V_159 ++ ;
V_150 -> V_155 . V_135 = V_135 ;
V_466 -> V_159 -- ;
if ( ! V_466 -> V_159 )
F_106 ( V_12 , V_466 ) ;
V_150 -> V_408 = 1 ;
V_150 -> V_409 = 1 ;
V_150 -> V_410 = 1 ;
V_150 -> V_411 = 1 ;
return 0 ;
V_465:
F_35 ( V_150 ,
V_130 , false ,
F_97 ( V_466 -> V_135 ) , V_33 ) ;
V_464:
F_37 ( V_150 , V_33 , false ) ;
V_162:
F_117 ( V_150 , V_135 -> V_135 , false , false ) ;
V_467:
if ( ! V_135 -> V_159 )
F_297 ( V_12 , V_135 ) ;
return V_15 ;
}
static bool
F_299 ( const struct V_19 * V_19 ,
const struct V_80 * V_413 )
{
struct V_19 * V_150 ;
F_93 (mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
if ( F_271 ( V_150 ) == V_413 )
return false ;
}
return true ;
}
static int F_300 ( struct V_80 * V_30 ,
unsigned long V_443 , void * V_444 ,
T_1 V_33 )
{
struct V_19 * V_19 = F_52 ( V_30 ) ;
struct V_445 * V_440 = V_444 ;
struct V_19 * V_150 ;
struct V_80 * V_446 ;
int V_15 ;
V_150 = F_112 ( V_19 , V_33 ) ;
switch ( V_443 ) {
case V_447 :
V_446 = V_440 -> V_446 ;
if ( ! V_440 -> V_448 || ! V_440 -> V_449 )
break;
if ( ! F_285 ( V_446 ) )
return V_450 ;
if ( ! F_299 ( V_19 ,
V_446 ) )
return V_450 ;
break;
case V_452 :
V_446 = V_440 -> V_446 ;
if ( ! V_440 -> V_448 )
break;
if ( V_440 -> V_449 ) {
if ( ! V_150 ) {
F_183 ( ! V_150 ) ;
return V_450 ;
}
V_15 = F_298 ( V_150 ,
V_446 ) ;
if ( V_15 ) {
F_115 ( V_30 , L_58 ) ;
return V_450 ;
}
} else {
if ( ! V_150 )
return V_453 ;
V_15 = F_272 ( V_150 ,
V_446 , true ) ;
if ( V_15 ) {
F_115 ( V_30 , L_59 ) ;
return V_450 ;
}
}
}
return V_453 ;
}
static int F_301 ( struct V_80 * V_423 ,
unsigned long V_443 , void * V_444 ,
T_1 V_33 )
{
struct V_80 * V_30 ;
struct V_457 * V_458 ;
int V_459 ;
F_291 (lag_dev, dev, iter) {
if ( F_244 ( V_30 ) ) {
V_459 = F_300 ( V_30 , V_443 , V_444 ,
V_33 ) ;
if ( V_459 == V_450 )
return V_459 ;
}
}
return V_453 ;
}
static int F_302 ( struct V_80 * V_442 ,
unsigned long V_443 , void * V_444 )
{
struct V_80 * V_468 = F_303 ( V_442 ) ;
T_1 V_33 = F_282 ( V_442 ) ;
if ( F_244 ( V_468 ) )
return F_300 ( V_468 , V_443 , V_444 ,
V_33 ) ;
else if ( F_286 ( V_468 ) )
return F_301 ( V_468 , V_443 , V_444 ,
V_33 ) ;
return V_453 ;
}
static int F_304 ( struct V_469 * V_470 ,
unsigned long V_443 , void * V_444 )
{
struct V_80 * V_30 = F_305 ( V_444 ) ;
if ( F_244 ( V_30 ) )
return F_289 ( V_30 , V_443 , V_444 ) ;
if ( F_286 ( V_30 ) )
return F_290 ( V_30 , V_443 , V_444 ) ;
if ( F_184 ( V_30 ) )
return F_302 ( V_30 , V_443 , V_444 ) ;
return V_453 ;
}
static int T_9 F_306 ( void )
{
int V_15 ;
F_307 ( & V_471 ) ;
V_15 = F_308 ( & V_472 ) ;
if ( V_15 )
goto V_473;
return 0 ;
V_473:
F_309 ( & V_471 ) ;
return V_15 ;
}
static void T_10 F_310 ( void )
{
F_311 ( & V_472 ) ;
F_309 ( & V_471 ) ;
}
