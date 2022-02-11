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
bool * V_26 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_21 [ V_22 ] ;
T_1 V_27 ;
int V_15 ;
F_15 ( V_21 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_25 ) , V_21 ) ;
if ( V_15 )
return V_15 ;
V_27 = F_18 ( V_21 ) ;
* V_26 = V_27 == V_23 ? true : false ;
return 0 ;
}
static int F_19 ( struct V_19 * V_19 ,
unsigned char * V_28 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_29 [ V_30 ] ;
F_20 ( V_29 , true , V_19 -> V_10 ) ;
F_21 ( V_29 , V_28 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_31 ) , V_29 ) ;
}
static int F_22 ( struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
unsigned char * V_28 = V_19 -> V_32 -> V_33 ;
F_23 ( V_28 , V_12 -> V_18 ) ;
V_28 [ V_34 - 1 ] += V_19 -> V_10 ;
return F_19 ( V_19 , V_28 ) ;
}
static int F_24 ( struct V_19 * V_19 ,
T_2 V_35 , enum V_36 V_37 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char * V_38 ;
int V_15 ;
V_38 = F_25 ( V_39 , V_40 ) ;
if ( ! V_38 )
return - V_41 ;
F_26 ( V_38 , V_19 -> V_10 ) ;
F_27 ( V_38 , V_35 , V_37 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_42 ) , V_38 ) ;
F_28 ( V_38 ) ;
return V_15 ;
}
static int F_29 ( struct V_19 * V_19 , T_2 V_43 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_44 [ V_45 ] ;
int V_46 ;
int V_15 ;
V_43 += V_6 + V_47 ;
F_30 ( V_44 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_48 ) , V_44 ) ;
if ( V_15 )
return V_15 ;
V_46 = F_31 ( V_44 ) ;
if ( V_43 > V_46 )
return - V_49 ;
F_30 ( V_44 , V_19 -> V_10 , V_43 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_48 ) , V_44 ) ;
}
static int F_32 ( struct V_19 * V_19 , T_1 V_50 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_51 [ V_52 ] ;
F_33 ( V_51 , V_50 , V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_53 ) , V_51 ) ;
}
static int F_34 ( struct V_19 * V_19 ,
bool V_54 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_55 [ V_56 ] ;
F_35 ( V_55 , V_19 -> V_10 , V_54 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_57 ) , V_55 ) ;
}
int F_36 ( struct V_19 * V_19 ,
enum V_58 V_59 , bool V_60 , T_2 V_61 ,
T_2 V_35 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_62 [ V_63 ] ;
F_37 ( V_62 , V_19 -> V_10 , V_59 , V_60 ,
V_61 , V_35 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_64 ) , V_62 ) ;
}
static int F_38 ( struct V_19 * V_19 ,
T_2 V_35 , bool V_65 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char * V_66 ;
int V_15 ;
V_66 = F_25 ( V_67 , V_40 ) ;
if ( ! V_66 )
return - V_41 ;
F_39 ( V_66 , V_19 -> V_10 , V_35 , V_35 ,
V_65 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_68 ) , V_66 ) ;
F_28 ( V_66 ) ;
return V_15 ;
}
static int
F_40 ( struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_69 [ V_70 ] ;
F_41 ( V_69 , V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_71 ) , V_69 ) ;
}
static int F_42 ( struct V_12 * V_12 ,
T_1 V_10 , T_1 * V_72 ,
T_1 * V_73 )
{
char V_74 [ V_75 ] ;
int V_15 ;
F_43 ( V_74 , V_10 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_76 ) , V_74 ) ;
if ( V_15 )
return V_15 ;
* V_72 = F_44 ( V_74 , 0 ) ;
* V_73 = F_45 ( V_74 ) ;
return 0 ;
}
static int F_46 ( struct V_12 * V_12 , T_1 V_10 ,
T_1 V_77 , T_1 V_78 , T_1 V_79 )
{
char V_74 [ V_75 ] ;
int V_80 ;
F_43 ( V_74 , V_10 ) ;
F_47 ( V_74 , V_78 ) ;
for ( V_80 = 0 ; V_80 < V_78 ; V_80 ++ ) {
F_48 ( V_74 , V_80 , V_77 ) ;
F_49 ( V_74 , V_80 , V_79 + V_80 ) ;
}
return F_16 ( V_12 -> V_16 , F_12 ( V_76 ) , V_74 ) ;
}
static int F_50 ( struct V_12 * V_12 , T_1 V_10 )
{
char V_74 [ V_75 ] ;
F_43 ( V_74 , V_10 ) ;
F_47 ( V_74 , 0 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_76 ) , V_74 ) ;
}
static int F_51 ( struct V_81 * V_32 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
int V_15 ;
V_15 = F_14 ( V_19 , true ) ;
if ( V_15 )
return V_15 ;
F_53 ( V_32 ) ;
return 0 ;
}
static int F_54 ( struct V_81 * V_32 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
F_55 ( V_32 ) ;
return F_14 ( V_19 , false ) ;
}
static T_3 F_56 ( struct V_1 * V_2 ,
struct V_81 * V_32 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_82 * V_83 ;
const struct V_3 V_4 = {
. V_10 = V_19 -> V_10 ,
. V_84 = false ,
} ;
T_4 V_85 ;
int V_15 ;
if ( F_57 ( V_12 , & V_4 ) )
return V_86 ;
if ( F_58 ( F_59 ( V_2 ) < V_6 ) ) {
struct V_1 * V_87 = V_2 ;
V_2 = F_60 ( V_2 , V_6 ) ;
if ( ! V_2 ) {
F_61 ( V_19 -> V_83 -> V_88 ) ;
F_62 ( V_87 ) ;
return V_89 ;
}
}
if ( F_63 ( V_2 ) ) {
F_61 ( V_19 -> V_83 -> V_88 ) ;
return V_89 ;
}
F_1 ( V_2 , & V_4 ) ;
V_85 = V_2 -> V_85 ;
V_15 = F_64 ( V_12 , V_2 , & V_4 ) ;
if ( ! V_15 ) {
V_83 = F_65 ( V_19 -> V_83 ) ;
F_66 ( & V_83 -> V_90 ) ;
V_83 -> V_91 ++ ;
V_83 -> V_92 += V_85 ;
F_67 ( & V_83 -> V_90 ) ;
} else {
F_61 ( V_19 -> V_83 -> V_88 ) ;
F_62 ( V_2 ) ;
}
return V_89 ;
}
static void F_68 ( struct V_81 * V_32 )
{
}
static int F_69 ( struct V_81 * V_32 , void * V_93 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
struct V_94 * V_28 = V_93 ;
int V_15 ;
if ( ! F_70 ( V_28 -> V_95 ) )
return - V_96 ;
V_15 = F_19 ( V_19 , V_28 -> V_95 ) ;
if ( V_15 )
return V_15 ;
memcpy ( V_32 -> V_33 , V_28 -> V_95 , V_32 -> V_97 ) ;
return 0 ;
}
static int F_71 ( struct V_81 * V_32 , int V_43 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
int V_15 ;
V_15 = F_29 ( V_19 , V_43 ) ;
if ( V_15 )
return V_15 ;
V_32 -> V_43 = V_43 ;
return 0 ;
}
static struct V_98 *
F_72 ( struct V_81 * V_32 ,
struct V_98 * V_99 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
struct V_82 * V_93 ;
T_4 V_100 , V_101 , V_91 , V_92 ;
T_5 V_88 = 0 ;
unsigned int V_102 ;
int V_80 ;
F_73 (i) {
V_93 = F_74 ( V_19 -> V_83 , V_80 ) ;
do {
V_102 = F_75 ( & V_93 -> V_90 ) ;
V_100 = V_93 -> V_100 ;
V_101 = V_93 -> V_101 ;
V_91 = V_93 -> V_91 ;
V_92 = V_93 -> V_92 ;
} while ( F_76 ( & V_93 -> V_90 , V_102 ) );
V_99 -> V_100 += V_100 ;
V_99 -> V_101 += V_101 ;
V_99 -> V_91 += V_91 ;
V_99 -> V_92 += V_92 ;
V_88 += V_93 -> V_88 ;
}
V_99 -> V_88 = V_88 ;
return V_99 ;
}
int F_77 ( struct V_19 * V_19 , T_2 V_103 ,
T_2 V_104 , bool V_105 , bool V_106 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char * V_107 ;
int V_15 ;
V_107 = F_25 ( V_108 , V_40 ) ;
if ( ! V_107 )
return - V_41 ;
F_78 ( V_107 , V_19 -> V_10 , V_103 ,
V_104 , V_105 , V_106 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_109 ) , V_107 ) ;
F_28 ( V_107 ) ;
return V_15 ;
}
static int F_79 ( struct V_19 * V_19 )
{
enum V_58 V_59 = V_110 ;
T_2 V_35 , V_111 ;
int V_15 ;
F_80 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_36 ( V_19 , V_59 , true , V_35 ,
V_35 ) ;
if ( V_15 ) {
V_111 = V_35 ;
goto V_112;
}
}
V_15 = F_34 ( V_19 , true ) ;
if ( V_15 ) {
V_111 = V_113 ;
goto V_112;
}
return 0 ;
V_112:
F_80 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_36 ( V_19 , V_59 , false , V_35 ,
V_35 ) ;
return V_15 ;
}
static int F_81 ( struct V_19 * V_19 )
{
enum V_58 V_59 = V_110 ;
T_2 V_35 ;
int V_15 ;
V_15 = F_34 ( V_19 , false ) ;
if ( V_15 )
return V_15 ;
F_80 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_36 ( V_19 , V_59 , false ,
V_35 , V_35 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static struct V_114 *
F_82 ( const struct V_12 * V_12 , T_2 V_35 )
{
struct V_114 * V_115 ;
F_83 (vfid, &mlxsw_sp->port_vfids.list, list) {
if ( V_115 -> V_35 == V_35 )
return V_115 ;
}
return NULL ;
}
static T_2 F_84 ( const struct V_12 * V_12 )
{
return F_85 ( V_12 -> V_116 . V_117 ,
V_118 ) ;
}
static int F_86 ( struct V_12 * V_12 , T_2 V_115 )
{
T_2 V_61 = F_87 ( V_115 ) ;
char V_119 [ V_120 ] ;
F_88 ( V_119 , V_121 , V_61 , 0 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_122 ) , V_119 ) ;
}
static void F_89 ( struct V_12 * V_12 , T_2 V_115 )
{
T_2 V_61 = F_87 ( V_115 ) ;
char V_119 [ V_120 ] ;
F_88 ( V_119 , V_123 , V_61 , 0 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_122 ) , V_119 ) ;
}
static struct V_114 * F_90 ( struct V_12 * V_12 ,
T_2 V_35 )
{
struct V_124 * V_32 = V_12 -> V_125 -> V_32 ;
struct V_114 * V_115 ;
T_2 V_126 ;
int V_15 ;
V_126 = F_84 ( V_12 ) ;
if ( V_126 == V_118 ) {
F_91 ( V_32 , L_1 ) ;
return F_92 ( - V_127 ) ;
}
V_15 = F_86 ( V_12 , V_126 ) ;
if ( V_15 ) {
F_91 ( V_32 , L_2 , V_126 ) ;
return F_92 ( V_15 ) ;
}
V_115 = F_93 ( sizeof( * V_115 ) , V_40 ) ;
if ( ! V_115 )
goto V_128;
V_115 -> V_115 = V_126 ;
V_115 -> V_35 = V_35 ;
F_94 ( & V_115 -> V_129 , & V_12 -> V_116 . V_129 ) ;
F_95 ( V_126 , V_12 -> V_116 . V_117 ) ;
return V_115 ;
V_128:
F_89 ( V_12 , V_126 ) ;
return F_92 ( - V_41 ) ;
}
static void F_96 ( struct V_12 * V_12 ,
struct V_114 * V_115 )
{
F_97 ( V_115 -> V_115 , V_12 -> V_116 . V_117 ) ;
F_98 ( & V_115 -> V_129 ) ;
F_89 ( V_12 , V_115 -> V_115 ) ;
F_28 ( V_115 ) ;
}
static struct V_19 *
F_99 ( struct V_19 * V_19 ,
struct V_114 * V_115 )
{
struct V_19 * V_130 ;
V_130 = F_93 ( sizeof( * V_130 ) , V_40 ) ;
if ( ! V_130 )
return NULL ;
V_130 -> V_32 = V_19 -> V_32 ;
V_130 -> V_12 = V_19 -> V_12 ;
V_130 -> V_10 = V_19 -> V_10 ;
V_130 -> V_131 = V_132 ;
V_130 -> V_133 = V_19 -> V_133 ;
V_130 -> V_134 = V_19 -> V_134 ;
V_130 -> V_135 . V_115 = V_115 ;
V_130 -> V_135 . V_35 = V_115 -> V_35 ;
F_94 ( & V_130 -> V_135 . V_129 , & V_19 -> V_136 ) ;
return V_130 ;
}
static void F_100 ( struct V_19 * V_130 )
{
F_98 ( & V_130 -> V_135 . V_129 ) ;
F_28 ( V_130 ) ;
}
int F_101 ( struct V_81 * V_32 , T_6 T_7 V_137 ,
T_2 V_35 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_19 * V_130 ;
struct V_114 * V_115 ;
int V_15 ;
if ( ! V_35 )
return 0 ;
if ( F_102 ( V_19 , V_35 ) ) {
F_103 ( V_32 , L_3 , V_35 ) ;
return 0 ;
}
V_115 = F_82 ( V_12 , V_35 ) ;
if ( ! V_115 ) {
V_115 = F_90 ( V_12 , V_35 ) ;
if ( F_104 ( V_115 ) ) {
F_105 ( V_32 , L_4 ,
V_35 ) ;
return F_106 ( V_115 ) ;
}
}
V_130 = F_99 ( V_19 , V_115 ) ;
if ( ! V_130 ) {
F_105 ( V_32 , L_5 , V_35 ) ;
V_15 = - V_41 ;
goto V_138;
}
if ( ! V_115 -> V_139 ) {
V_15 = F_107 ( V_130 , V_115 -> V_115 ,
true , false ) ;
if ( V_15 ) {
F_105 ( V_32 , L_6 ,
V_115 -> V_115 ) ;
goto V_140;
}
}
if ( F_108 ( & V_19 -> V_136 ) ) {
V_15 = F_79 ( V_19 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_7 ) ;
goto V_141;
}
}
V_15 = F_36 ( V_130 ,
V_110 ,
true ,
F_87 ( V_115 -> V_115 ) ,
V_35 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_8 ,
V_35 , V_115 -> V_115 ) ;
goto V_112;
}
V_15 = F_38 ( V_130 , V_35 , false ) ;
if ( V_15 ) {
F_105 ( V_32 , L_9 , V_35 ) ;
goto V_142;
}
V_15 = F_77 ( V_130 , V_35 , V_35 , true , false ) ;
if ( V_15 ) {
F_105 ( V_32 , L_10 ,
V_35 ) ;
goto V_143;
}
V_15 = F_24 ( V_130 , V_35 ,
V_144 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_11 , V_35 ) ;
goto V_145;
}
V_115 -> V_139 ++ ;
return 0 ;
V_145:
F_77 ( V_130 , V_35 , V_35 , false , false ) ;
V_143:
F_38 ( V_130 , V_35 , true ) ;
V_142:
F_36 ( V_130 ,
V_110 , false ,
F_87 ( V_115 -> V_115 ) , V_35 ) ;
V_112:
if ( F_108 ( & V_19 -> V_136 ) )
F_81 ( V_19 ) ;
V_141:
if ( ! V_115 -> V_139 )
F_107 ( V_130 , V_115 -> V_115 , false ,
false ) ;
V_140:
F_100 ( V_130 ) ;
V_138:
if ( ! V_115 -> V_139 )
F_96 ( V_12 , V_115 ) ;
return V_15 ;
}
int F_109 ( struct V_81 * V_32 ,
T_6 T_7 V_137 , T_2 V_35 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
struct V_19 * V_130 ;
struct V_114 * V_115 ;
int V_15 ;
if ( ! V_35 )
return 0 ;
V_130 = F_102 ( V_19 , V_35 ) ;
if ( ! V_130 ) {
F_103 ( V_32 , L_12 , V_35 ) ;
return 0 ;
}
V_115 = V_130 -> V_135 . V_115 ;
V_15 = F_24 ( V_130 , V_35 ,
V_146 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_11 , V_35 ) ;
return V_15 ;
}
V_15 = F_77 ( V_130 , V_35 , V_35 , false , false ) ;
if ( V_15 ) {
F_105 ( V_32 , L_10 ,
V_35 ) ;
return V_15 ;
}
V_15 = F_38 ( V_130 , V_35 , true ) ;
if ( V_15 ) {
F_105 ( V_32 , L_13 , V_35 ) ;
return V_15 ;
}
V_15 = F_36 ( V_130 ,
V_110 ,
false ,
F_87 ( V_115 -> V_115 ) ,
V_35 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_14 ,
V_35 , V_115 -> V_115 ) ;
return V_15 ;
}
if ( F_108 ( & V_19 -> V_136 ) ) {
V_15 = F_81 ( V_19 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_15 ) ;
return V_15 ;
}
}
V_115 -> V_139 -- ;
F_100 ( V_130 ) ;
if ( ! V_115 -> V_139 )
F_96 ( V_19 -> V_12 , V_115 ) ;
return 0 ;
}
static void F_110 ( struct V_81 * V_32 ,
struct V_147 * V_148 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
F_111 ( V_148 -> V_149 , V_150 , sizeof( V_148 -> V_149 ) ) ;
F_111 ( V_148 -> V_151 , V_152 ,
sizeof( V_148 -> V_151 ) ) ;
snprintf ( V_148 -> V_153 , sizeof( V_148 -> V_153 ) ,
L_16 ,
V_12 -> V_125 -> V_154 . V_155 ,
V_12 -> V_125 -> V_154 . V_156 ,
V_12 -> V_125 -> V_154 . V_157 ) ;
F_111 ( V_148 -> V_125 , V_12 -> V_125 -> V_158 ,
sizeof( V_148 -> V_125 ) ) ;
}
static void F_112 ( struct V_81 * V_32 ,
T_5 V_159 , T_1 * V_160 )
{
T_1 * V_93 = V_160 ;
int V_80 ;
switch ( V_159 ) {
case V_161 :
for ( V_80 = 0 ; V_80 < V_162 ; V_80 ++ ) {
memcpy ( V_93 , V_163 [ V_80 ] . V_164 ,
V_165 ) ;
V_93 += V_165 ;
}
break;
}
}
static int F_113 ( struct V_81 * V_32 ,
enum V_166 V_37 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_167 [ V_168 ] ;
bool V_169 ;
switch ( V_37 ) {
case V_170 :
V_169 = true ;
break;
case V_171 :
V_169 = false ;
break;
default:
return - V_172 ;
}
F_114 ( V_167 , V_19 -> V_10 , V_169 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_173 ) , V_167 ) ;
}
static void F_115 ( struct V_81 * V_32 ,
struct V_174 * V_99 , T_4 * V_160 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_175 [ V_176 ] ;
int V_80 ;
int V_15 ;
F_116 ( V_175 , V_19 -> V_10 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_177 ) , V_175 ) ;
for ( V_80 = 0 ; V_80 < V_162 ; V_80 ++ )
V_160 [ V_80 ] = ! V_15 ? V_163 [ V_80 ] . F_117 ( V_175 ) : 0 ;
}
static int F_118 ( struct V_81 * V_32 , int V_178 )
{
switch ( V_178 ) {
case V_161 :
return V_162 ;
default:
return - V_172 ;
}
}
static T_5 F_119 ( T_5 V_179 )
{
if ( V_179 & ( V_180 |
V_181 |
V_182 |
V_183 |
V_184 |
V_185 ) )
return V_186 ;
if ( V_179 & ( V_187 |
V_188 |
V_189 |
V_190 |
V_191 ) )
return V_192 ;
return 0 ;
}
static T_5 F_120 ( T_5 V_179 )
{
T_5 V_193 = 0 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_194 ; V_80 ++ ) {
if ( V_179 & V_195 [ V_80 ] . V_196 )
V_193 |= V_195 [ V_80 ] . V_197 ;
}
return V_193 ;
}
static T_5 F_121 ( T_5 V_179 )
{
T_5 V_193 = 0 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_194 ; V_80 ++ ) {
if ( V_179 & V_195 [ V_80 ] . V_196 )
V_193 |= V_195 [ V_80 ] . V_198 ;
}
return V_193 ;
}
static void F_122 ( bool V_199 , T_5 V_179 ,
struct V_200 * V_201 )
{
T_5 V_202 = V_203 ;
T_1 V_204 = V_205 ;
int V_80 ;
if ( ! V_199 )
goto V_206;
for ( V_80 = 0 ; V_80 < V_194 ; V_80 ++ ) {
if ( V_179 & V_195 [ V_80 ] . V_196 ) {
V_202 = V_195 [ V_80 ] . V_202 ;
V_204 = V_207 ;
break;
}
}
V_206:
F_123 ( V_201 , V_202 ) ;
V_201 -> V_204 = V_204 ;
}
static T_1 F_124 ( T_5 V_179 )
{
if ( V_179 & ( V_181 |
V_183 |
V_184 |
V_185 ) )
return V_208 ;
if ( V_179 & ( V_180 |
V_182 |
V_209 ) )
return V_210 ;
if ( V_179 & ( V_187 |
V_188 |
V_189 |
V_190 ) )
return V_211 ;
return V_212 ;
}
static int F_125 ( struct V_81 * V_32 ,
struct V_200 * V_201 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_213 [ V_214 ] ;
T_5 V_215 ;
T_5 V_216 ;
T_5 V_217 ;
int V_15 ;
F_126 ( V_213 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_218 ) , V_213 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_17 ) ;
return V_15 ;
}
F_127 ( V_213 , & V_215 ,
& V_216 , & V_217 ) ;
V_201 -> V_197 = F_119 ( V_215 ) |
F_120 ( V_215 ) |
V_219 | V_220 ;
V_201 -> V_221 = F_121 ( V_216 ) ;
F_122 ( F_128 ( V_32 ) ,
V_217 , V_201 ) ;
V_217 = V_217 ? V_217 : V_215 ;
V_201 -> V_222 = F_124 ( V_217 ) ;
V_201 -> V_223 = F_121 ( V_217 ) ;
V_201 -> V_224 = V_225 ;
return 0 ;
}
static T_5 F_129 ( T_5 V_221 )
{
T_5 V_226 = 0 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_194 ; V_80 ++ ) {
if ( V_221 & V_195 [ V_80 ] . V_198 )
V_226 |= V_195 [ V_80 ] . V_196 ;
}
return V_226 ;
}
static T_5 F_130 ( T_5 V_202 )
{
T_5 V_226 = 0 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_194 ; V_80 ++ ) {
if ( V_202 == V_195 [ V_80 ] . V_202 )
V_226 |= V_195 [ V_80 ] . V_196 ;
}
return V_226 ;
}
static T_5 F_131 ( T_5 V_227 )
{
T_5 V_226 = 0 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_194 ; V_80 ++ ) {
if ( V_195 [ V_80 ] . V_202 <= V_227 )
V_226 |= V_195 [ V_80 ] . V_196 ;
}
return V_226 ;
}
static int F_132 ( struct V_81 * V_32 ,
struct V_200 * V_201 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_213 [ V_214 ] ;
T_5 V_202 ;
T_5 V_228 ;
T_5 V_215 ;
T_5 V_216 ;
bool V_20 ;
int V_15 ;
V_202 = F_133 ( V_201 ) ;
V_228 = V_201 -> V_229 == V_230 ?
F_129 ( V_201 -> V_221 ) :
F_130 ( V_202 ) ;
F_126 ( V_213 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_218 ) , V_213 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_17 ) ;
return V_15 ;
}
F_127 ( V_213 , & V_215 , & V_216 , NULL ) ;
V_228 = V_228 & V_215 ;
if ( ! V_228 ) {
F_105 ( V_32 , L_18 ) ;
return - V_49 ;
}
if ( V_228 == V_216 )
return 0 ;
F_126 ( V_213 , V_19 -> V_10 , V_228 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_218 ) , V_213 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_19 ) ;
return V_15 ;
}
V_15 = F_17 ( V_19 , & V_20 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_20 ) ;
return V_15 ;
}
if ( ! V_20 )
return 0 ;
V_15 = F_14 ( V_19 , false ) ;
if ( V_15 ) {
F_105 ( V_32 , L_21 ) ;
return V_15 ;
}
V_15 = F_14 ( V_19 , true ) ;
if ( V_15 ) {
F_105 ( V_32 , L_21 ) ;
return V_15 ;
}
return 0 ;
}
static int
F_134 ( struct V_19 * V_19 , T_1 V_78 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
T_5 V_227 = V_231 * V_78 ;
char V_213 [ V_214 ] ;
T_5 V_216 ;
V_216 = F_131 ( V_227 ) ;
F_126 ( V_213 , V_19 -> V_10 ,
V_216 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_218 ) , V_213 ) ;
}
static int F_135 ( struct V_12 * V_12 , T_1 V_10 ,
bool V_232 , T_1 V_77 , T_1 V_78 )
{
struct V_233 * V_233 = F_136 ( V_12 -> V_16 ) ;
struct V_19 * V_19 ;
struct V_234 * V_234 ;
struct V_81 * V_32 ;
T_8 V_235 ;
int V_15 ;
V_32 = F_137 ( sizeof( struct V_19 ) ) ;
if ( ! V_32 )
return - V_41 ;
V_19 = F_52 ( V_32 ) ;
V_19 -> V_32 = V_32 ;
V_19 -> V_12 = V_12 ;
V_19 -> V_10 = V_10 ;
V_19 -> V_232 = V_232 ;
V_235 = F_138 ( V_113 , V_236 ) ;
V_19 -> V_237 = F_93 ( V_235 , V_40 ) ;
if ( ! V_19 -> V_237 ) {
V_15 = - V_41 ;
goto V_238;
}
V_19 -> V_239 = F_93 ( V_235 , V_40 ) ;
if ( ! V_19 -> V_239 ) {
V_15 = - V_41 ;
goto V_240;
}
F_139 ( & V_19 -> V_136 ) ;
V_19 -> V_83 =
F_140 ( struct V_82 ) ;
if ( ! V_19 -> V_83 ) {
V_15 = - V_41 ;
goto V_241;
}
V_32 -> V_242 = & V_243 ;
V_32 -> V_244 = & V_245 ;
V_15 = F_22 ( V_19 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_22 ,
V_19 -> V_10 ) ;
goto V_246;
}
F_141 ( V_32 ) ;
V_32 -> V_247 |= V_248 | V_249 | V_250 |
V_251 ;
V_32 -> V_252 += V_6 ;
V_234 = & V_19 -> V_234 ;
if ( V_19 -> V_232 )
F_142 ( V_234 , V_77 ) ;
V_15 = F_143 ( V_233 , V_234 , V_10 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_23 ,
V_19 -> V_10 ) ;
goto V_253;
}
V_15 = F_40 ( V_19 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_24 ,
V_19 -> V_10 ) ;
goto V_254;
}
V_15 = F_32 ( V_19 , 0 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_25 ,
V_19 -> V_10 ) ;
goto V_255;
}
V_15 = F_134 ( V_19 , V_78 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_26 ,
V_19 -> V_10 ) ;
goto V_256;
}
V_15 = F_29 ( V_19 , V_257 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_27 ,
V_19 -> V_10 ) ;
goto V_258;
}
V_15 = F_14 ( V_19 , false ) ;
if ( V_15 )
goto V_259;
V_15 = F_144 ( V_19 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_28 ,
V_19 -> V_10 ) ;
goto V_260;
}
F_145 ( V_19 ) ;
V_15 = F_146 ( V_32 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_29 ,
V_19 -> V_10 ) ;
goto V_261;
}
F_147 ( V_234 , V_32 ) ;
V_15 = F_148 ( V_19 ) ;
if ( V_15 )
goto V_262;
V_12 -> V_263 [ V_10 ] = V_19 ;
return 0 ;
V_262:
F_149 ( V_32 ) ;
V_261:
V_260:
V_259:
V_258:
V_256:
V_255:
V_254:
F_150 ( & V_19 -> V_234 ) ;
V_253:
V_246:
F_151 ( V_19 -> V_83 ) ;
V_241:
F_28 ( V_19 -> V_239 ) ;
V_240:
F_28 ( V_19 -> V_237 ) ;
V_238:
F_152 ( V_32 ) ;
return V_15 ;
}
static int F_153 ( struct V_12 * V_12 , T_1 V_10 ,
bool V_232 , T_1 V_77 , T_1 V_78 , T_1 V_79 )
{
int V_15 ;
V_15 = F_46 ( V_12 , V_10 , V_77 , V_78 ,
V_79 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_135 ( V_12 , V_10 , V_232 , V_77 ,
V_78 ) ;
if ( V_15 )
goto V_264;
return 0 ;
V_264:
F_50 ( V_12 , V_10 ) ;
return V_15 ;
}
static void F_154 ( struct V_19 * V_19 )
{
struct V_81 * V_32 = V_19 -> V_32 ;
struct V_19 * V_130 , * V_265 ;
F_155 (mlxsw_sp_vport, tmp,
&mlxsw_sp_port->vports_list, vport.list) {
T_2 V_35 = F_156 ( V_130 ) ;
F_157 ( F_158 ( V_130 -> V_32 ) ) ;
F_109 ( V_32 , 0 , V_35 ) ;
}
}
static void F_159 ( struct V_12 * V_12 , T_1 V_10 )
{
struct V_19 * V_19 = V_12 -> V_263 [ V_10 ] ;
struct V_234 * V_234 ;
if ( ! V_19 )
return;
V_12 -> V_263 [ V_10 ] = NULL ;
V_234 = & V_19 -> V_234 ;
F_160 ( V_234 ) ;
F_149 ( V_19 -> V_32 ) ;
F_150 ( V_234 ) ;
F_154 ( V_19 ) ;
F_161 ( V_19 ) ;
F_32 ( V_19 , V_266 ) ;
F_50 ( V_12 , V_19 -> V_10 ) ;
F_151 ( V_19 -> V_83 ) ;
F_28 ( V_19 -> V_239 ) ;
F_28 ( V_19 -> V_237 ) ;
F_152 ( V_19 -> V_32 ) ;
}
static void F_162 ( struct V_12 * V_12 )
{
int V_80 ;
for ( V_80 = 1 ; V_80 < V_267 ; V_80 ++ )
F_159 ( V_12 , V_80 ) ;
F_28 ( V_12 -> V_263 ) ;
}
static int F_163 ( struct V_12 * V_12 )
{
T_8 V_268 ;
T_1 V_77 , V_78 ;
int V_80 ;
int V_15 ;
V_268 = sizeof( struct V_19 * ) * V_267 ;
V_12 -> V_263 = F_93 ( V_268 , V_40 ) ;
if ( ! V_12 -> V_263 )
return - V_41 ;
for ( V_80 = 1 ; V_80 < V_267 ; V_80 ++ ) {
V_15 = F_42 ( V_12 , V_80 , & V_77 ,
& V_78 ) ;
if ( V_15 )
goto V_269;
if ( ! V_78 )
continue;
V_12 -> V_270 [ V_80 ] = V_77 ;
V_15 = F_135 ( V_12 , V_80 , false , V_77 , V_78 ) ;
if ( V_15 )
goto V_264;
}
return 0 ;
V_264:
V_269:
for ( V_80 -- ; V_80 >= 1 ; V_80 -- )
F_159 ( V_12 , V_80 ) ;
F_28 ( V_12 -> V_263 ) ;
return V_15 ;
}
static T_1 F_164 ( T_1 V_10 )
{
T_1 V_271 = ( V_10 - 1 ) % V_272 ;
return V_10 - V_271 ;
}
static int F_165 ( void * V_273 , T_1 V_10 , unsigned int V_274 )
{
struct V_12 * V_12 = V_273 ;
struct V_19 * V_19 ;
T_1 V_78 = V_275 / V_274 ;
T_1 V_77 , V_276 , V_277 ;
int V_80 ;
int V_15 ;
V_19 = V_12 -> V_263 [ V_10 ] ;
if ( ! V_19 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_30 ,
V_10 ) ;
return - V_49 ;
}
if ( V_274 != 2 && V_274 != 4 ) {
F_105 ( V_19 -> V_32 , L_31 ) ;
return - V_49 ;
}
V_15 = F_42 ( V_12 , V_10 , & V_77 ,
& V_276 ) ;
if ( V_15 ) {
F_105 ( V_19 -> V_32 , L_32 ) ;
return V_15 ;
}
if ( V_276 != V_275 ) {
F_105 ( V_19 -> V_32 , L_33 ) ;
return - V_49 ;
}
if ( V_274 == 2 ) {
V_277 = V_10 ;
if ( V_12 -> V_263 [ V_277 + 1 ] ) {
F_105 ( V_19 -> V_32 , L_34 ) ;
return - V_49 ;
}
} else {
V_277 = F_164 ( V_10 ) ;
if ( V_12 -> V_263 [ V_277 + 1 ] ||
V_12 -> V_263 [ V_277 + 3 ] ) {
F_105 ( V_19 -> V_32 , L_34 ) ;
return - V_49 ;
}
}
for ( V_80 = 0 ; V_80 < V_274 ; V_80 ++ )
F_159 ( V_12 , V_277 + V_80 ) ;
for ( V_80 = 0 ; V_80 < V_274 ; V_80 ++ ) {
V_15 = F_153 ( V_12 , V_277 + V_80 , true ,
V_77 , V_78 , V_80 * V_78 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_35 ) ;
goto V_264;
}
}
return 0 ;
V_264:
for ( V_80 -- ; V_80 >= 0 ; V_80 -- )
F_159 ( V_12 , V_277 + V_80 ) ;
for ( V_80 = 0 ; V_80 < V_274 / 2 ; V_80 ++ ) {
V_77 = V_12 -> V_270 [ V_277 + V_80 * 2 ] ;
F_153 ( V_12 , V_277 + V_80 * 2 , false ,
V_77 , V_275 , 0 ) ;
}
return V_15 ;
}
static int F_166 ( void * V_273 , T_1 V_10 )
{
struct V_12 * V_12 = V_273 ;
struct V_19 * V_19 ;
T_1 V_77 , V_276 , V_277 ;
unsigned int V_274 ;
int V_80 ;
int V_15 ;
V_19 = V_12 -> V_263 [ V_10 ] ;
if ( ! V_19 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_30 ,
V_10 ) ;
return - V_49 ;
}
if ( ! V_19 -> V_232 ) {
F_105 ( V_19 -> V_32 , L_36 ) ;
return - V_49 ;
}
V_15 = F_42 ( V_12 , V_10 , & V_77 ,
& V_276 ) ;
if ( V_15 ) {
F_105 ( V_19 -> V_32 , L_32 ) ;
return V_15 ;
}
V_274 = V_276 == 1 ? 4 : 2 ;
V_277 = F_164 ( V_10 ) ;
if ( V_274 == 2 && V_10 >= V_277 + 2 )
V_277 = V_277 + 2 ;
for ( V_80 = 0 ; V_80 < V_274 ; V_80 ++ )
F_159 ( V_12 , V_277 + V_80 ) ;
for ( V_80 = 0 ; V_80 < V_274 / 2 ; V_80 ++ ) {
V_77 = V_12 -> V_270 [ V_277 + V_80 * 2 ] ;
V_15 = F_153 ( V_12 , V_277 + V_80 * 2 , false ,
V_77 , V_275 ,
0 ) ;
if ( V_15 )
F_91 ( V_12 -> V_125 -> V_32 , L_37 ) ;
}
return 0 ;
}
static void F_167 ( const struct V_278 * V_279 ,
char * V_280 , void * V_273 )
{
struct V_12 * V_12 = V_273 ;
struct V_19 * V_19 ;
enum V_281 V_282 ;
T_1 V_10 ;
V_10 = F_168 ( V_280 ) ;
V_19 = V_12 -> V_263 [ V_10 ] ;
if ( ! V_19 ) {
F_169 ( V_12 -> V_125 -> V_32 , L_38 ,
V_10 ) ;
return;
}
V_282 = F_170 ( V_280 ) ;
if ( V_282 == V_283 ) {
F_171 ( V_19 -> V_32 , L_39 ) ;
F_172 ( V_19 -> V_32 ) ;
} else {
F_171 ( V_19 -> V_32 , L_40 ) ;
F_141 ( V_19 -> V_32 ) ;
}
}
static int F_173 ( struct V_12 * V_12 ,
enum V_284 V_285 )
{
struct V_286 * V_287 ;
char V_288 [ V_289 ] ;
int V_15 ;
switch ( V_285 ) {
case V_290 :
V_287 = & V_291 ;
break;
}
V_15 = F_174 ( V_12 -> V_16 , V_287 , V_12 ) ;
if ( V_15 )
return V_15 ;
F_175 ( V_288 , V_292 , V_285 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_293 ) , V_288 ) ;
if ( V_15 )
goto V_294;
return 0 ;
V_294:
F_176 ( V_12 -> V_16 , V_287 , V_12 ) ;
return V_15 ;
}
static void F_177 ( struct V_12 * V_12 ,
enum V_284 V_285 )
{
struct V_286 * V_287 ;
switch ( V_285 ) {
case V_290 :
V_287 = & V_291 ;
break;
}
F_176 ( V_12 -> V_16 , V_287 , V_12 ) ;
}
static void F_178 ( struct V_1 * V_2 , T_1 V_10 ,
void * V_273 )
{
struct V_12 * V_12 = V_273 ;
struct V_19 * V_19 = V_12 -> V_263 [ V_10 ] ;
struct V_82 * V_83 ;
if ( F_58 ( ! V_19 ) ) {
F_179 ( V_12 -> V_125 -> V_32 , L_41 ,
V_10 ) ;
return;
}
V_2 -> V_32 = V_19 -> V_32 ;
V_83 = F_65 ( V_19 -> V_83 ) ;
F_66 ( & V_83 -> V_90 ) ;
V_83 -> V_100 ++ ;
V_83 -> V_101 += V_2 -> V_85 ;
F_67 ( & V_83 -> V_90 ) ;
V_2 -> V_295 = F_180 ( V_2 , V_2 -> V_32 ) ;
F_181 ( V_2 ) ;
}
static int F_182 ( struct V_12 * V_12 )
{
char V_296 [ V_297 ] ;
char V_288 [ V_289 ] ;
int V_80 ;
int V_15 ;
F_183 ( V_296 , V_298 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_299 ) , V_296 ) ;
if ( V_15 )
return V_15 ;
F_183 ( V_296 , V_300 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_299 ) , V_296 ) ;
if ( V_15 )
return V_15 ;
for ( V_80 = 0 ; V_80 < F_184 ( V_301 ) ; V_80 ++ ) {
V_15 = F_185 ( V_12 -> V_16 ,
& V_301 [ V_80 ] ,
V_12 ) ;
if ( V_15 )
goto V_302;
F_175 ( V_288 , V_303 ,
V_301 [ V_80 ] . V_285 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_293 ) , V_288 ) ;
if ( V_15 )
goto V_304;
}
return 0 ;
V_304:
F_186 ( V_12 -> V_16 ,
& V_301 [ V_80 ] ,
V_12 ) ;
V_302:
for ( V_80 -- ; V_80 >= 0 ; V_80 -- ) {
F_175 ( V_288 , V_292 ,
V_301 [ V_80 ] . V_285 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_293 ) , V_288 ) ;
F_186 ( V_12 -> V_16 ,
& V_301 [ V_80 ] ,
V_12 ) ;
}
return V_15 ;
}
static void F_187 ( struct V_12 * V_12 )
{
char V_288 [ V_289 ] ;
int V_80 ;
for ( V_80 = 0 ; V_80 < F_184 ( V_301 ) ; V_80 ++ ) {
F_175 ( V_288 , V_292 ,
V_301 [ V_80 ] . V_285 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_293 ) , V_288 ) ;
F_186 ( V_12 -> V_16 ,
& V_301 [ V_80 ] ,
V_12 ) ;
}
}
static int F_188 ( struct V_305 * V_305 ,
enum V_306 type ,
enum V_307 V_308 )
{
enum V_309 V_310 ;
enum V_311 V_312 ;
char V_313 [ V_314 ] ;
if ( V_308 == V_315 )
V_310 = V_316 ;
else
V_310 = V_317 ;
if ( type == V_318 )
V_312 = V_319 ;
else
V_312 = V_320 ;
F_189 ( V_313 , type , V_308 , V_310 ,
V_312 ) ;
return F_16 ( V_305 , F_12 ( V_321 ) , V_313 ) ;
}
static int F_190 ( struct V_12 * V_12 )
{
int type , V_15 ;
for ( type = 0 ; type < V_322 ; type ++ ) {
if ( type == V_323 )
continue;
V_15 = F_188 ( V_12 -> V_16 , type ,
V_315 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_188 ( V_12 -> V_16 , type ,
V_324 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_191 ( struct V_12 * V_12 )
{
char V_325 [ V_326 ] ;
F_192 ( V_325 , V_327 |
V_328 |
V_329 |
V_330 |
V_331 |
V_332 |
V_333 |
V_334 |
V_335 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_336 ) , V_325 ) ;
}
static int F_193 ( void * V_273 , struct V_305 * V_305 ,
const struct V_337 * V_337 )
{
struct V_12 * V_12 = V_273 ;
int V_15 ;
V_12 -> V_16 = V_305 ;
V_12 -> V_125 = V_337 ;
F_139 ( & V_12 -> V_116 . V_129 ) ;
F_139 ( & V_12 -> V_338 . V_129 ) ;
F_139 ( & V_12 -> V_339 . V_129 ) ;
V_15 = F_10 ( V_12 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_42 ) ;
return V_15 ;
}
V_15 = F_163 ( V_12 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_43 ) ;
return V_15 ;
}
V_15 = F_173 ( V_12 , V_290 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_44 ) ;
goto V_340;
}
V_15 = F_182 ( V_12 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_45 ) ;
goto V_302;
}
V_15 = F_190 ( V_12 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_46 ) ;
goto V_341;
}
V_15 = F_194 ( V_12 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_47 ) ;
goto V_342;
}
V_15 = F_191 ( V_12 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_48 ) ;
goto V_343;
}
V_15 = F_195 ( V_12 ) ;
if ( V_15 ) {
F_91 ( V_12 -> V_125 -> V_32 , L_49 ) ;
goto V_344;
}
return 0 ;
V_344:
V_343:
V_342:
V_341:
F_187 ( V_12 ) ;
V_302:
F_177 ( V_12 , V_290 ) ;
V_340:
F_162 ( V_12 ) ;
return V_15 ;
}
static void F_196 ( void * V_273 )
{
struct V_12 * V_12 = V_273 ;
F_197 ( V_12 ) ;
F_187 ( V_12 ) ;
F_177 ( V_12 , V_290 ) ;
F_162 ( V_12 ) ;
}
static int
F_198 ( const struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_345 [ V_346 ] ;
F_199 ( V_345 , V_347 ) ;
F_200 ( V_345 , V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_348 ) , V_345 ) ;
}
static int
F_201 ( const struct V_19 * V_19 ,
T_2 V_61 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_345 [ V_346 ] ;
F_199 ( V_345 , V_349 ) ;
F_202 ( V_345 , V_61 ) ;
F_203 ( V_345 ,
V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_348 ) , V_345 ) ;
}
static int
F_204 ( const struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_345 [ V_346 ] ;
F_199 ( V_345 , V_350 ) ;
F_205 ( V_345 , V_19 -> V_134 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_348 ) , V_345 ) ;
}
static int
F_206 ( const struct V_19 * V_19 ,
T_2 V_61 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_345 [ V_346 ] ;
F_199 ( V_345 , V_351 ) ;
F_202 ( V_345 , V_61 ) ;
F_207 ( V_345 , V_19 -> V_134 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_348 ) , V_345 ) ;
}
static int
F_208 ( const struct V_19 * V_19 )
{
int V_15 , V_352 = 0 ;
T_2 V_35 ;
for ( V_35 = 1 ; V_35 < V_113 - 1 ; V_35 ++ ) {
V_15 = F_201 ( V_19 , V_35 ) ;
if ( V_15 )
V_352 = V_15 ;
}
return V_352 ;
}
static int
F_209 ( const struct V_19 * V_19 )
{
int V_15 , V_352 = 0 ;
T_2 V_35 ;
for ( V_35 = 1 ; V_35 < V_113 - 1 ; V_35 ++ ) {
V_15 = F_206 ( V_19 , V_35 ) ;
if ( V_15 )
V_352 = V_15 ;
}
return V_352 ;
}
static int F_210 ( struct V_19 * V_19 )
{
if ( ! F_211 ( & V_19 -> V_136 ) )
if ( V_19 -> V_133 )
return F_209 ( V_19 ) ;
else
return F_208 ( V_19 ) ;
else
if ( V_19 -> V_133 )
return F_204 ( V_19 ) ;
else
return F_198 ( V_19 ) ;
}
static int F_212 ( struct V_19 * V_130 )
{
T_2 V_115 = F_213 ( V_130 ) ;
T_2 V_61 = F_87 ( V_115 ) ;
if ( V_130 -> V_133 )
return F_206 ( V_130 ,
V_61 ) ;
else
return F_201 ( V_130 , V_61 ) ;
}
static bool F_214 ( const struct V_81 * V_32 )
{
return V_32 -> V_242 == & V_243 ;
}
static int F_215 ( struct V_19 * V_19 )
{
struct V_81 * V_32 = V_19 -> V_32 ;
int V_15 ;
V_15 = F_109 ( V_32 , 0 , 1 ) ;
if ( V_15 )
return V_15 ;
V_19 -> V_353 = 1 ;
V_19 -> V_354 = 1 ;
V_19 -> V_355 = 1 ;
V_19 -> V_356 = 1 ;
return 0 ;
}
static int F_216 ( struct V_19 * V_19 ,
bool V_357 )
{
struct V_81 * V_32 = V_19 -> V_32 ;
if ( V_357 && F_210 ( V_19 ) )
F_105 ( V_19 -> V_32 , L_50 ) ;
F_217 ( V_19 , 1 ) ;
V_19 -> V_353 = 0 ;
V_19 -> V_354 = 0 ;
V_19 -> V_355 = 0 ;
V_19 -> V_356 = 0 ;
return F_101 ( V_32 , 0 , 1 ) ;
}
static bool F_218 ( struct V_12 * V_12 ,
struct V_81 * V_358 )
{
return ! V_12 -> V_359 . V_32 ||
V_12 -> V_359 . V_32 == V_358 ;
}
static void F_219 ( struct V_12 * V_12 ,
struct V_81 * V_358 )
{
V_12 -> V_359 . V_32 = V_358 ;
V_12 -> V_359 . V_360 ++ ;
}
static void F_220 ( struct V_12 * V_12 ,
struct V_81 * V_358 )
{
if ( -- V_12 -> V_359 . V_360 == 0 )
V_12 -> V_359 . V_32 = NULL ;
}
static int F_221 ( struct V_12 * V_12 , T_2 V_134 )
{
char V_361 [ V_362 ] ;
F_222 ( V_361 , V_134 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_363 ) , V_361 ) ;
}
static int F_223 ( struct V_12 * V_12 , T_2 V_134 )
{
char V_361 [ V_362 ] ;
F_224 ( V_361 , V_134 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_363 ) , V_361 ) ;
}
static int F_225 ( struct V_19 * V_19 ,
T_2 V_134 , T_1 V_364 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_365 [ V_366 ] ;
F_226 ( V_365 , V_19 -> V_10 ,
V_134 , V_364 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_367 ) , V_365 ) ;
}
static int F_227 ( struct V_19 * V_19 ,
T_2 V_134 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_365 [ V_366 ] ;
F_228 ( V_365 , V_19 -> V_10 ,
V_134 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_367 ) , V_365 ) ;
}
static int F_229 ( struct V_19 * V_19 ,
T_2 V_134 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_365 [ V_366 ] ;
F_230 ( V_365 , V_19 -> V_10 ,
V_134 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_367 ) , V_365 ) ;
}
static int F_231 ( struct V_19 * V_19 ,
T_2 V_134 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_365 [ V_366 ] ;
F_232 ( V_365 , V_19 -> V_10 ,
V_134 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_367 ) , V_365 ) ;
}
static int F_233 ( struct V_12 * V_12 ,
struct V_81 * V_368 ,
T_2 * V_369 )
{
struct V_370 * V_371 ;
int V_372 = - 1 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_373 ; V_80 ++ ) {
V_371 = F_234 ( V_12 , V_80 ) ;
if ( V_371 -> V_360 ) {
if ( V_371 -> V_32 == V_368 ) {
* V_369 = V_80 ;
return 0 ;
}
} else if ( V_372 < 0 ) {
V_372 = V_80 ;
}
}
if ( V_372 < 0 )
return - V_374 ;
* V_369 = V_372 ;
return 0 ;
}
static bool
F_235 ( struct V_12 * V_12 ,
struct V_81 * V_368 ,
struct V_375 * V_376 )
{
T_2 V_134 ;
if ( F_233 ( V_12 , V_368 , & V_134 ) != 0 )
return false ;
if ( V_376 -> V_377 != V_378 )
return false ;
return true ;
}
static int F_236 ( struct V_12 * V_12 ,
T_2 V_134 , T_1 * V_379 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_380 ; V_80 ++ ) {
if ( ! F_237 ( V_12 , V_134 , V_80 ) ) {
* V_379 = V_80 ;
return 0 ;
}
}
return - V_374 ;
}
static int F_238 ( struct V_19 * V_19 ,
struct V_81 * V_368 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_370 * V_371 ;
T_2 V_134 ;
T_1 V_364 ;
int V_15 ;
V_15 = F_233 ( V_12 , V_368 , & V_134 ) ;
if ( V_15 )
return V_15 ;
V_371 = F_234 ( V_12 , V_134 ) ;
if ( ! V_371 -> V_360 ) {
V_15 = F_221 ( V_12 , V_134 ) ;
if ( V_15 )
return V_15 ;
V_371 -> V_32 = V_368 ;
}
V_15 = F_236 ( V_12 , V_134 , & V_364 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_225 ( V_19 , V_134 , V_364 ) ;
if ( V_15 )
goto V_381;
V_15 = F_229 ( V_19 , V_134 ) ;
if ( V_15 )
goto V_382;
F_239 ( V_12 -> V_16 , V_134 , V_364 ,
V_19 -> V_10 ) ;
V_19 -> V_134 = V_134 ;
V_19 -> V_133 = 1 ;
V_371 -> V_360 ++ ;
return 0 ;
V_382:
F_227 ( V_19 , V_134 ) ;
V_381:
if ( ! V_371 -> V_360 )
F_223 ( V_12 , V_134 ) ;
return V_15 ;
}
static int F_240 ( struct V_19 * V_19 ,
struct V_81 * V_368 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_19 * V_130 ;
struct V_370 * V_371 ;
T_2 V_134 = V_19 -> V_134 ;
int V_15 ;
if ( ! V_19 -> V_133 )
return 0 ;
V_371 = F_234 ( V_12 , V_134 ) ;
F_157 ( V_371 -> V_360 == 0 ) ;
V_15 = F_231 ( V_19 , V_134 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_227 ( V_19 , V_134 ) ;
if ( V_15 )
return V_15 ;
F_83 (mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
struct V_81 * V_358 ;
if ( ! V_130 -> V_356 )
continue;
V_358 = F_241 ( V_130 ) ;
F_242 ( V_130 , V_358 , false ) ;
}
if ( V_19 -> V_356 ) {
F_243 ( V_19 ) ;
F_216 ( V_19 , false ) ;
F_220 ( V_12 , NULL ) ;
}
if ( V_371 -> V_360 == 1 ) {
if ( F_204 ( V_19 ) )
F_105 ( V_19 -> V_32 , L_50 ) ;
V_15 = F_223 ( V_12 , V_134 ) ;
if ( V_15 )
return V_15 ;
}
F_244 ( V_12 -> V_16 , V_134 ,
V_19 -> V_10 ) ;
V_19 -> V_133 = 0 ;
V_371 -> V_360 -- ;
return 0 ;
}
static int F_245 ( struct V_19 * V_19 ,
T_2 V_134 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_361 [ V_362 ] ;
F_246 ( V_361 , V_134 ,
V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_363 ) , V_361 ) ;
}
static int F_247 ( struct V_19 * V_19 ,
T_2 V_134 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_361 [ V_362 ] ;
F_248 ( V_361 , V_134 ,
V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_363 ) , V_361 ) ;
}
static int F_249 ( struct V_19 * V_19 ,
bool V_383 )
{
if ( V_383 )
return F_245 ( V_19 ,
V_19 -> V_134 ) ;
else
return F_247 ( V_19 ,
V_19 -> V_134 ) ;
}
static int F_250 ( struct V_19 * V_19 ,
struct V_384 * V_385 )
{
return F_249 ( V_19 , V_385 -> V_386 ) ;
}
static int F_251 ( struct V_19 * V_19 ,
struct V_81 * V_387 )
{
struct V_19 * V_130 ;
T_2 V_35 = F_252 ( V_387 ) ;
V_130 = F_102 ( V_19 , V_35 ) ;
if ( ! V_130 ) {
F_157 ( ! V_130 ) ;
return - V_49 ;
}
V_130 -> V_32 = V_387 ;
return 0 ;
}
static int F_253 ( struct V_19 * V_19 ,
struct V_81 * V_387 )
{
struct V_19 * V_130 ;
T_2 V_35 = F_252 ( V_387 ) ;
V_130 = F_102 ( V_19 , V_35 ) ;
if ( ! V_130 ) {
F_157 ( ! V_130 ) ;
return - V_49 ;
}
if ( V_130 -> V_356 ) {
struct V_81 * V_358 ;
V_358 = F_241 ( V_130 ) ;
F_242 ( V_130 , V_358 , true ) ;
}
V_130 -> V_32 = V_19 -> V_32 ;
return 0 ;
}
static int F_254 ( struct V_81 * V_32 ,
unsigned long V_388 , void * V_389 )
{
struct V_390 * V_385 ;
struct V_19 * V_19 ;
struct V_81 * V_391 ;
struct V_12 * V_12 ;
int V_15 ;
V_19 = F_52 ( V_32 ) ;
V_12 = V_19 -> V_12 ;
V_385 = V_389 ;
switch ( V_388 ) {
case V_392 :
V_391 = V_385 -> V_391 ;
if ( ! V_385 -> V_393 || ! V_385 -> V_394 )
break;
if ( F_255 ( V_391 ) &&
! F_218 ( V_12 , V_391 ) )
return V_395 ;
if ( F_256 ( V_391 ) &&
! F_235 ( V_12 , V_391 ,
V_385 -> V_396 ) )
return V_395 ;
break;
case V_397 :
V_391 = V_385 -> V_391 ;
if ( F_158 ( V_391 ) ) {
if ( V_385 -> V_394 ) {
V_15 = F_251 ( V_19 ,
V_391 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_51 ) ;
return V_395 ;
}
} else {
V_15 = F_253 ( V_19 ,
V_391 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_52 ) ;
return V_395 ;
}
}
} else if ( F_255 ( V_391 ) ) {
if ( V_385 -> V_394 ) {
V_15 = F_215 ( V_19 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_53 ) ;
return V_395 ;
}
F_219 ( V_12 , V_391 ) ;
} else {
V_15 = F_216 ( V_19 ,
true ) ;
F_220 ( V_12 , V_391 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_54 ) ;
return V_395 ;
}
}
} else if ( F_256 ( V_391 ) ) {
if ( V_385 -> V_394 ) {
V_15 = F_238 ( V_19 ,
V_391 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_55 ) ;
return V_395 ;
}
} else {
V_15 = F_240 ( V_19 ,
V_391 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_56 ) ;
return V_395 ;
}
}
}
break;
}
return V_398 ;
}
static int F_257 ( struct V_81 * V_32 ,
unsigned long V_388 , void * V_389 )
{
struct V_399 * V_385 ;
struct V_19 * V_19 ;
int V_15 ;
V_19 = F_52 ( V_32 ) ;
V_385 = V_389 ;
switch ( V_388 ) {
case V_400 :
if ( F_258 ( V_32 ) && V_19 -> V_133 ) {
V_15 = F_250 ( V_19 ,
V_385 -> V_401 ) ;
if ( V_15 )
F_105 ( V_32 , L_57 ) ;
}
break;
}
return V_398 ;
}
static int F_259 ( struct V_81 * V_32 ,
unsigned long V_388 , void * V_389 )
{
switch ( V_388 ) {
case V_392 :
case V_397 :
return F_254 ( V_32 , V_388 , V_389 ) ;
case V_400 :
return F_257 ( V_32 , V_388 , V_389 ) ;
}
return V_398 ;
}
static int F_260 ( struct V_81 * V_368 ,
unsigned long V_388 , void * V_389 )
{
struct V_81 * V_32 ;
struct V_402 * V_403 ;
int V_404 ;
F_261 (lag_dev, dev, iter) {
if ( F_214 ( V_32 ) ) {
V_404 = F_259 ( V_32 , V_388 , V_389 ) ;
if ( V_404 == V_395 )
return V_404 ;
}
}
return V_398 ;
}
static struct V_114 *
F_262 ( const struct V_12 * V_12 ,
const struct V_81 * V_358 )
{
struct V_114 * V_115 ;
F_83 (vfid, &mlxsw_sp->br_vfids.list, list) {
if ( V_115 -> V_358 == V_358 )
return V_115 ;
}
return NULL ;
}
static T_2 F_263 ( T_2 V_115 )
{
return V_115 - V_118 ;
}
static T_2 F_264 ( T_2 V_405 )
{
return V_118 + V_405 ;
}
static T_2 F_265 ( const struct V_12 * V_12 )
{
return F_85 ( V_12 -> V_338 . V_117 ,
V_406 ) ;
}
static struct V_114 * F_266 ( struct V_12 * V_12 ,
struct V_81 * V_358 )
{
struct V_124 * V_32 = V_12 -> V_125 -> V_32 ;
struct V_114 * V_115 ;
T_2 V_126 ;
int V_15 ;
V_126 = F_264 ( F_265 ( V_12 ) ) ;
if ( V_126 == V_407 ) {
F_91 ( V_32 , L_1 ) ;
return F_92 ( - V_127 ) ;
}
V_15 = F_86 ( V_12 , V_126 ) ;
if ( V_15 ) {
F_91 ( V_32 , L_2 , V_126 ) ;
return F_92 ( V_15 ) ;
}
V_115 = F_93 ( sizeof( * V_115 ) , V_40 ) ;
if ( ! V_115 )
goto V_128;
V_115 -> V_115 = V_126 ;
V_115 -> V_358 = V_358 ;
F_94 ( & V_115 -> V_129 , & V_12 -> V_338 . V_129 ) ;
F_95 ( F_263 ( V_126 ) , V_12 -> V_338 . V_117 ) ;
return V_115 ;
V_128:
F_89 ( V_12 , V_126 ) ;
return F_92 ( - V_41 ) ;
}
static void F_267 ( struct V_12 * V_12 ,
struct V_114 * V_115 )
{
T_2 V_405 = F_263 ( V_115 -> V_115 ) ;
F_97 ( V_405 , V_12 -> V_338 . V_117 ) ;
F_98 ( & V_115 -> V_129 ) ;
F_89 ( V_12 , V_115 -> V_115 ) ;
F_28 ( V_115 ) ;
}
static int F_242 ( struct V_19 * V_130 ,
struct V_81 * V_358 ,
bool V_357 )
{
struct V_12 * V_12 = V_130 -> V_12 ;
T_2 V_35 = F_156 ( V_130 ) ;
struct V_81 * V_32 = V_130 -> V_32 ;
struct V_114 * V_115 , * V_408 ;
int V_15 ;
V_115 = F_262 ( V_12 , V_358 ) ;
if ( ! V_115 ) {
F_157 ( ! V_115 ) ;
return - V_49 ;
}
V_408 = F_82 ( V_12 , V_35 ) ;
if ( ! V_408 ) {
V_408 = F_90 ( V_12 , V_35 ) ;
if ( F_104 ( V_408 ) ) {
F_105 ( V_32 , L_4 ,
V_35 ) ;
return F_106 ( V_408 ) ;
}
}
V_15 = F_36 ( V_130 ,
V_110 ,
false ,
F_87 ( V_115 -> V_115 ) ,
V_35 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_58 ,
V_115 -> V_115 ) ;
goto V_409;
}
V_15 = F_36 ( V_130 ,
V_110 ,
true ,
F_87 ( V_408 -> V_115 ) ,
V_35 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_59 ,
V_408 -> V_115 ) ;
goto V_410;
}
V_15 = F_38 ( V_130 , V_35 , false ) ;
if ( V_15 ) {
F_105 ( V_32 , L_60 ) ;
goto V_142;
}
V_15 = F_107 ( V_130 , V_115 -> V_115 , false ,
false ) ;
if ( V_15 ) {
F_105 ( V_32 , L_61 ) ;
goto V_140;
}
V_15 = F_24 ( V_130 , V_35 ,
V_144 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_62 ) ;
goto V_145;
}
if ( V_357 && F_212 ( V_130 ) )
F_105 ( V_32 , L_50 ) ;
V_408 -> V_139 ++ ;
V_130 -> V_135 . V_115 = V_408 ;
V_115 -> V_139 -- ;
if ( ! V_115 -> V_139 )
F_267 ( V_12 , V_115 ) ;
V_130 -> V_353 = 0 ;
V_130 -> V_354 = 0 ;
V_130 -> V_355 = 0 ;
V_130 -> V_356 = 0 ;
return 0 ;
V_145:
V_140:
V_142:
V_410:
V_409:
if ( ! V_408 -> V_139 )
F_96 ( V_12 , V_408 ) ;
return V_15 ;
}
static int F_268 ( struct V_19 * V_130 ,
struct V_81 * V_358 )
{
struct V_114 * V_411 = V_130 -> V_135 . V_115 ;
struct V_12 * V_12 = V_130 -> V_12 ;
T_2 V_35 = F_156 ( V_130 ) ;
struct V_81 * V_32 = V_130 -> V_32 ;
struct V_114 * V_115 ;
int V_15 ;
V_115 = F_262 ( V_12 , V_358 ) ;
if ( ! V_115 ) {
V_115 = F_266 ( V_12 , V_358 ) ;
if ( F_104 ( V_115 ) ) {
F_105 ( V_32 , L_63 ) ;
return F_106 ( V_115 ) ;
}
}
V_15 = F_107 ( V_130 , V_115 -> V_115 , true , false ) ;
if ( V_15 ) {
F_105 ( V_32 , L_6 ,
V_115 -> V_115 ) ;
goto V_412;
}
V_15 = F_38 ( V_130 , V_35 , true ) ;
if ( V_15 ) {
F_105 ( V_32 , L_64 ) ;
goto V_142;
}
V_15 = F_36 ( V_130 ,
V_110 ,
false ,
F_87 ( V_411 -> V_115 ) ,
V_35 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_58 ,
V_411 -> V_115 ) ;
goto V_409;
}
V_15 = F_36 ( V_130 ,
V_110 ,
true ,
F_87 ( V_115 -> V_115 ) ,
V_35 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_59 ,
V_115 -> V_115 ) ;
goto V_410;
}
V_115 -> V_139 ++ ;
V_130 -> V_135 . V_115 = V_115 ;
V_411 -> V_139 -- ;
if ( ! V_411 -> V_139 )
F_96 ( V_12 , V_411 ) ;
V_130 -> V_353 = 1 ;
V_130 -> V_354 = 1 ;
V_130 -> V_355 = 1 ;
V_130 -> V_356 = 1 ;
return 0 ;
V_410:
F_36 ( V_130 ,
V_110 , false ,
F_87 ( V_411 -> V_115 ) , V_35 ) ;
V_409:
F_38 ( V_130 , V_35 , false ) ;
V_142:
F_107 ( V_130 , V_115 -> V_115 , false , false ) ;
V_412:
if ( ! V_115 -> V_139 )
F_267 ( V_12 , V_115 ) ;
return V_15 ;
}
static bool
F_269 ( const struct V_19 * V_19 ,
const struct V_81 * V_358 )
{
struct V_19 * V_130 ;
F_83 (mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
if ( F_241 ( V_130 ) == V_358 )
return false ;
}
return true ;
}
static int F_270 ( struct V_81 * V_32 ,
unsigned long V_388 , void * V_389 ,
T_2 V_35 )
{
struct V_19 * V_19 = F_52 ( V_32 ) ;
struct V_390 * V_385 = V_389 ;
struct V_19 * V_130 ;
struct V_81 * V_391 ;
int V_15 ;
V_130 = F_102 ( V_19 , V_35 ) ;
switch ( V_388 ) {
case V_392 :
V_391 = V_385 -> V_391 ;
if ( ! V_385 -> V_393 || ! V_385 -> V_394 )
break;
if ( ! F_255 ( V_391 ) )
return V_395 ;
if ( ! F_269 ( V_19 ,
V_391 ) )
return V_395 ;
break;
case V_397 :
V_391 = V_385 -> V_391 ;
if ( ! V_385 -> V_393 )
break;
if ( V_385 -> V_394 ) {
if ( ! V_130 ) {
F_157 ( ! V_130 ) ;
return V_395 ;
}
V_15 = F_268 ( V_130 ,
V_391 ) ;
if ( V_15 ) {
F_105 ( V_32 , L_53 ) ;
return V_395 ;
}
} else {
if ( ! V_130 )
return V_398 ;
V_15 = F_242 ( V_130 ,
V_391 , true ) ;
if ( V_15 ) {
F_105 ( V_32 , L_54 ) ;
return V_395 ;
}
}
}
return V_398 ;
}
static int F_271 ( struct V_81 * V_368 ,
unsigned long V_388 , void * V_389 ,
T_2 V_35 )
{
struct V_81 * V_32 ;
struct V_402 * V_403 ;
int V_404 ;
F_261 (lag_dev, dev, iter) {
if ( F_214 ( V_32 ) ) {
V_404 = F_270 ( V_32 , V_388 , V_389 ,
V_35 ) ;
if ( V_404 == V_395 )
return V_404 ;
}
}
return V_398 ;
}
static int F_272 ( struct V_81 * V_387 ,
unsigned long V_388 , void * V_389 )
{
struct V_81 * V_413 = F_273 ( V_387 ) ;
T_2 V_35 = F_252 ( V_387 ) ;
if ( F_214 ( V_413 ) )
return F_270 ( V_413 , V_388 , V_389 ,
V_35 ) ;
else if ( F_256 ( V_413 ) )
return F_271 ( V_413 , V_388 , V_389 ,
V_35 ) ;
return V_398 ;
}
static int F_274 ( struct V_414 * V_415 ,
unsigned long V_388 , void * V_389 )
{
struct V_81 * V_32 = F_275 ( V_389 ) ;
if ( F_214 ( V_32 ) )
return F_259 ( V_32 , V_388 , V_389 ) ;
if ( F_256 ( V_32 ) )
return F_260 ( V_32 , V_388 , V_389 ) ;
if ( F_158 ( V_32 ) )
return F_272 ( V_32 , V_388 , V_389 ) ;
return V_398 ;
}
static int T_9 F_276 ( void )
{
int V_15 ;
F_277 ( & V_416 ) ;
V_15 = F_278 ( & V_417 ) ;
if ( V_15 )
goto V_418;
return 0 ;
V_418:
F_279 ( & V_416 ) ;
return V_15 ;
}
static void T_10 F_280 ( void )
{
F_281 ( & V_417 ) ;
F_279 ( & V_416 ) ;
}
