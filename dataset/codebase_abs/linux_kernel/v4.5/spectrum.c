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
static int F_42 ( struct V_19 * V_19 ,
bool * V_72 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_73 [ V_74 ] ;
int V_15 ;
F_43 ( V_73 , V_19 -> V_10 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_75 ) , V_73 ) ;
if ( V_15 )
return V_15 ;
* V_72 = F_44 ( V_73 ) ? true : false ;
return 0 ;
}
static int F_45 ( struct V_76 * V_32 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
int V_15 ;
V_15 = F_14 ( V_19 , true ) ;
if ( V_15 )
return V_15 ;
F_47 ( V_32 ) ;
return 0 ;
}
static int F_48 ( struct V_76 * V_32 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
F_49 ( V_32 ) ;
return F_14 ( V_19 , false ) ;
}
static T_3 F_50 ( struct V_1 * V_2 ,
struct V_76 * V_32 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_77 * V_78 ;
const struct V_3 V_4 = {
. V_10 = V_19 -> V_10 ,
. V_79 = false ,
} ;
T_4 V_80 ;
int V_15 ;
if ( F_51 ( V_12 , & V_4 ) )
return V_81 ;
if ( F_52 ( F_53 ( V_2 ) < V_6 ) ) {
struct V_1 * V_82 = V_2 ;
V_2 = F_54 ( V_2 , V_6 ) ;
if ( ! V_2 ) {
F_55 ( V_19 -> V_78 -> V_83 ) ;
F_56 ( V_82 ) ;
return V_84 ;
}
}
if ( F_57 ( V_2 ) ) {
F_55 ( V_19 -> V_78 -> V_83 ) ;
return V_84 ;
}
F_1 ( V_2 , & V_4 ) ;
V_80 = V_2 -> V_80 ;
V_15 = F_58 ( V_12 , V_2 , & V_4 ) ;
if ( ! V_15 ) {
V_78 = F_59 ( V_19 -> V_78 ) ;
F_60 ( & V_78 -> V_85 ) ;
V_78 -> V_86 ++ ;
V_78 -> V_87 += V_80 ;
F_61 ( & V_78 -> V_85 ) ;
} else {
F_55 ( V_19 -> V_78 -> V_83 ) ;
F_56 ( V_2 ) ;
}
return V_84 ;
}
static void F_62 ( struct V_76 * V_32 )
{
}
static int F_63 ( struct V_76 * V_32 , void * V_88 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
struct V_89 * V_28 = V_88 ;
int V_15 ;
if ( ! F_64 ( V_28 -> V_90 ) )
return - V_91 ;
V_15 = F_19 ( V_19 , V_28 -> V_90 ) ;
if ( V_15 )
return V_15 ;
memcpy ( V_32 -> V_33 , V_28 -> V_90 , V_32 -> V_92 ) ;
return 0 ;
}
static int F_65 ( struct V_76 * V_32 , int V_43 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
int V_15 ;
V_15 = F_29 ( V_19 , V_43 ) ;
if ( V_15 )
return V_15 ;
V_32 -> V_43 = V_43 ;
return 0 ;
}
static struct V_93 *
F_66 ( struct V_76 * V_32 ,
struct V_93 * V_94 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
struct V_77 * V_88 ;
T_4 V_95 , V_96 , V_86 , V_87 ;
T_5 V_83 = 0 ;
unsigned int V_97 ;
int V_98 ;
F_67 (i) {
V_88 = F_68 ( V_19 -> V_78 , V_98 ) ;
do {
V_97 = F_69 ( & V_88 -> V_85 ) ;
V_95 = V_88 -> V_95 ;
V_96 = V_88 -> V_96 ;
V_86 = V_88 -> V_86 ;
V_87 = V_88 -> V_87 ;
} while ( F_70 ( & V_88 -> V_85 , V_97 ) );
V_94 -> V_95 += V_95 ;
V_94 -> V_96 += V_96 ;
V_94 -> V_86 += V_86 ;
V_94 -> V_87 += V_87 ;
V_83 += V_88 -> V_83 ;
}
V_94 -> V_83 = V_83 ;
return V_94 ;
}
int F_71 ( struct V_19 * V_19 , T_2 V_99 ,
T_2 V_100 , bool V_101 , bool V_102 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char * V_103 ;
int V_15 ;
V_103 = F_25 ( V_104 , V_40 ) ;
if ( ! V_103 )
return - V_41 ;
F_72 ( V_103 , V_19 -> V_10 , V_99 ,
V_100 , V_101 , V_102 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_105 ) , V_103 ) ;
F_28 ( V_103 ) ;
return V_15 ;
}
static int F_73 ( struct V_19 * V_19 )
{
enum V_58 V_59 = V_106 ;
T_2 V_35 , V_107 ;
int V_15 ;
F_74 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_36 ( V_19 , V_59 , true , V_35 ,
V_35 ) ;
if ( V_15 ) {
V_107 = V_35 ;
goto V_108;
}
}
V_15 = F_34 ( V_19 , true ) ;
if ( V_15 ) {
V_107 = V_109 ;
goto V_108;
}
return 0 ;
V_108:
F_74 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_36 ( V_19 , V_59 , false , V_35 ,
V_35 ) ;
return V_15 ;
}
static int F_75 ( struct V_19 * V_19 )
{
enum V_58 V_59 = V_106 ;
T_2 V_35 ;
int V_15 ;
V_15 = F_34 ( V_19 , false ) ;
if ( V_15 )
return V_15 ;
F_74 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_15 = F_36 ( V_19 , V_59 , false ,
V_35 , V_35 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static struct V_110 *
F_76 ( const struct V_12 * V_12 , T_2 V_35 )
{
struct V_110 * V_111 ;
F_77 (vfid, &mlxsw_sp->port_vfids.list, list) {
if ( V_111 -> V_35 == V_35 )
return V_111 ;
}
return NULL ;
}
static T_2 F_78 ( const struct V_12 * V_12 )
{
return F_79 ( V_12 -> V_112 . V_113 ,
V_114 ) ;
}
static int F_80 ( struct V_12 * V_12 , T_2 V_111 )
{
T_2 V_61 = F_81 ( V_111 ) ;
char V_115 [ V_116 ] ;
F_82 ( V_115 , V_117 , V_61 , 0 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_118 ) , V_115 ) ;
}
static void F_83 ( struct V_12 * V_12 , T_2 V_111 )
{
T_2 V_61 = F_81 ( V_111 ) ;
char V_115 [ V_116 ] ;
F_82 ( V_115 , V_119 , V_61 , 0 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_118 ) , V_115 ) ;
}
static struct V_110 * F_84 ( struct V_12 * V_12 ,
T_2 V_35 )
{
struct V_120 * V_32 = V_12 -> V_121 -> V_32 ;
struct V_110 * V_111 ;
T_2 V_122 ;
int V_15 ;
V_122 = F_78 ( V_12 ) ;
if ( V_122 == V_114 ) {
F_85 ( V_32 , L_1 ) ;
return F_86 ( - V_123 ) ;
}
V_15 = F_80 ( V_12 , V_122 ) ;
if ( V_15 ) {
F_85 ( V_32 , L_2 , V_122 ) ;
return F_86 ( V_15 ) ;
}
V_111 = F_87 ( sizeof( * V_111 ) , V_40 ) ;
if ( ! V_111 )
goto V_124;
V_111 -> V_111 = V_122 ;
V_111 -> V_35 = V_35 ;
F_88 ( & V_111 -> V_125 , & V_12 -> V_112 . V_125 ) ;
F_89 ( V_122 , V_12 -> V_112 . V_113 ) ;
return V_111 ;
V_124:
F_83 ( V_12 , V_122 ) ;
return F_86 ( - V_41 ) ;
}
static void F_90 ( struct V_12 * V_12 ,
struct V_110 * V_111 )
{
F_91 ( V_111 -> V_111 , V_12 -> V_112 . V_113 ) ;
F_92 ( & V_111 -> V_125 ) ;
F_83 ( V_12 , V_111 -> V_111 ) ;
F_28 ( V_111 ) ;
}
static struct V_19 *
F_93 ( struct V_19 * V_19 ,
struct V_110 * V_111 )
{
struct V_19 * V_126 ;
V_126 = F_87 ( sizeof( * V_126 ) , V_40 ) ;
if ( ! V_126 )
return NULL ;
V_126 -> V_32 = V_19 -> V_32 ;
V_126 -> V_12 = V_19 -> V_12 ;
V_126 -> V_10 = V_19 -> V_10 ;
V_126 -> V_127 = V_128 ;
V_126 -> V_129 = V_19 -> V_129 ;
V_126 -> V_130 = V_19 -> V_130 ;
V_126 -> V_131 . V_111 = V_111 ;
V_126 -> V_131 . V_35 = V_111 -> V_35 ;
F_88 ( & V_126 -> V_131 . V_125 , & V_19 -> V_132 ) ;
return V_126 ;
}
static void F_94 ( struct V_19 * V_126 )
{
F_92 ( & V_126 -> V_131 . V_125 ) ;
F_28 ( V_126 ) ;
}
int F_95 ( struct V_76 * V_32 , T_6 T_7 V_133 ,
T_2 V_35 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_19 * V_126 ;
struct V_110 * V_111 ;
int V_15 ;
if ( ! V_35 )
return 0 ;
if ( F_96 ( V_19 , V_35 ) ) {
F_97 ( V_32 , L_3 , V_35 ) ;
return 0 ;
}
V_111 = F_76 ( V_12 , V_35 ) ;
if ( ! V_111 ) {
V_111 = F_84 ( V_12 , V_35 ) ;
if ( F_98 ( V_111 ) ) {
F_99 ( V_32 , L_4 ,
V_35 ) ;
return F_100 ( V_111 ) ;
}
}
V_126 = F_93 ( V_19 , V_111 ) ;
if ( ! V_126 ) {
F_99 ( V_32 , L_5 , V_35 ) ;
V_15 = - V_41 ;
goto V_134;
}
if ( ! V_111 -> V_135 ) {
V_15 = F_101 ( V_126 , V_111 -> V_111 ,
true , false ) ;
if ( V_15 ) {
F_99 ( V_32 , L_6 ,
V_111 -> V_111 ) ;
goto V_136;
}
}
if ( F_102 ( & V_19 -> V_132 ) ) {
V_15 = F_73 ( V_19 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_7 ) ;
goto V_137;
}
}
V_15 = F_36 ( V_126 ,
V_106 ,
true ,
F_81 ( V_111 -> V_111 ) ,
V_35 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_8 ,
V_35 , V_111 -> V_111 ) ;
goto V_108;
}
V_15 = F_38 ( V_126 , V_35 , false ) ;
if ( V_15 ) {
F_99 ( V_32 , L_9 , V_35 ) ;
goto V_138;
}
V_15 = F_71 ( V_126 , V_35 , V_35 , true , false ) ;
if ( V_15 ) {
F_99 ( V_32 , L_10 ,
V_35 ) ;
goto V_139;
}
V_15 = F_24 ( V_126 , V_35 ,
V_140 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_11 , V_35 ) ;
goto V_141;
}
V_111 -> V_135 ++ ;
return 0 ;
V_141:
F_71 ( V_126 , V_35 , V_35 , false , false ) ;
V_139:
F_38 ( V_126 , V_35 , true ) ;
V_138:
F_36 ( V_126 ,
V_106 , false ,
F_81 ( V_111 -> V_111 ) , V_35 ) ;
V_108:
if ( F_102 ( & V_19 -> V_132 ) )
F_75 ( V_19 ) ;
V_137:
if ( ! V_111 -> V_135 )
F_101 ( V_126 , V_111 -> V_111 , false ,
false ) ;
V_136:
F_94 ( V_126 ) ;
V_134:
if ( ! V_111 -> V_135 )
F_90 ( V_12 , V_111 ) ;
return V_15 ;
}
int F_103 ( struct V_76 * V_32 ,
T_6 T_7 V_133 , T_2 V_35 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
struct V_19 * V_126 ;
struct V_110 * V_111 ;
int V_15 ;
if ( ! V_35 )
return 0 ;
V_126 = F_96 ( V_19 , V_35 ) ;
if ( ! V_126 ) {
F_97 ( V_32 , L_12 , V_35 ) ;
return 0 ;
}
V_111 = V_126 -> V_131 . V_111 ;
V_15 = F_24 ( V_126 , V_35 ,
V_142 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_11 , V_35 ) ;
return V_15 ;
}
V_15 = F_71 ( V_126 , V_35 , V_35 , false , false ) ;
if ( V_15 ) {
F_99 ( V_32 , L_10 ,
V_35 ) ;
return V_15 ;
}
V_15 = F_38 ( V_126 , V_35 , true ) ;
if ( V_15 ) {
F_99 ( V_32 , L_13 , V_35 ) ;
return V_15 ;
}
V_15 = F_36 ( V_126 ,
V_106 ,
false ,
F_81 ( V_111 -> V_111 ) ,
V_35 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_14 ,
V_35 , V_111 -> V_111 ) ;
return V_15 ;
}
if ( F_102 ( & V_19 -> V_132 ) ) {
V_15 = F_75 ( V_19 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_15 ) ;
return V_15 ;
}
}
V_111 -> V_135 -- ;
F_94 ( V_126 ) ;
if ( ! V_111 -> V_135 )
F_90 ( V_19 -> V_12 , V_111 ) ;
return 0 ;
}
static void F_104 ( struct V_76 * V_32 ,
struct V_143 * V_144 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
F_105 ( V_144 -> V_145 , V_146 , sizeof( V_144 -> V_145 ) ) ;
F_105 ( V_144 -> V_147 , V_148 ,
sizeof( V_144 -> V_147 ) ) ;
snprintf ( V_144 -> V_149 , sizeof( V_144 -> V_149 ) ,
L_16 ,
V_12 -> V_121 -> V_150 . V_151 ,
V_12 -> V_121 -> V_150 . V_152 ,
V_12 -> V_121 -> V_150 . V_153 ) ;
F_105 ( V_144 -> V_121 , V_12 -> V_121 -> V_154 ,
sizeof( V_144 -> V_121 ) ) ;
}
static void F_106 ( struct V_76 * V_32 ,
T_5 V_155 , T_1 * V_156 )
{
T_1 * V_88 = V_156 ;
int V_98 ;
switch ( V_155 ) {
case V_157 :
for ( V_98 = 0 ; V_98 < V_158 ; V_98 ++ ) {
memcpy ( V_88 , V_159 [ V_98 ] . V_160 ,
V_161 ) ;
V_88 += V_161 ;
}
break;
}
}
static int F_107 ( struct V_76 * V_32 ,
enum V_162 V_37 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_163 [ V_164 ] ;
bool V_165 ;
switch ( V_37 ) {
case V_166 :
V_165 = true ;
break;
case V_167 :
V_165 = false ;
break;
default:
return - V_168 ;
}
F_108 ( V_163 , V_19 -> V_10 , V_165 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_169 ) , V_163 ) ;
}
static void F_109 ( struct V_76 * V_32 ,
struct V_170 * V_94 , T_4 * V_156 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_171 [ V_172 ] ;
int V_98 ;
int V_15 ;
F_110 ( V_171 , V_19 -> V_10 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_173 ) , V_171 ) ;
for ( V_98 = 0 ; V_98 < V_158 ; V_98 ++ )
V_156 [ V_98 ] = ! V_15 ? V_159 [ V_98 ] . F_111 ( V_171 ) : 0 ;
}
static int F_112 ( struct V_76 * V_32 , int V_174 )
{
switch ( V_174 ) {
case V_157 :
return V_158 ;
default:
return - V_168 ;
}
}
static T_5 F_113 ( T_5 V_175 )
{
if ( V_175 & ( V_176 |
V_177 |
V_178 |
V_179 |
V_180 |
V_181 ) )
return V_182 ;
if ( V_175 & ( V_183 |
V_184 |
V_185 |
V_186 |
V_187 ) )
return V_188 ;
return 0 ;
}
static T_5 F_114 ( T_5 V_175 )
{
T_5 V_189 = 0 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < V_190 ; V_98 ++ ) {
if ( V_175 & V_191 [ V_98 ] . V_192 )
V_189 |= V_191 [ V_98 ] . V_193 ;
}
return V_189 ;
}
static T_5 F_115 ( T_5 V_175 )
{
T_5 V_189 = 0 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < V_190 ; V_98 ++ ) {
if ( V_175 & V_191 [ V_98 ] . V_192 )
V_189 |= V_191 [ V_98 ] . V_194 ;
}
return V_189 ;
}
static void F_116 ( bool V_195 , T_5 V_175 ,
struct V_196 * V_197 )
{
T_5 V_198 = V_199 ;
T_1 V_200 = V_201 ;
int V_98 ;
if ( ! V_195 )
goto V_202;
for ( V_98 = 0 ; V_98 < V_190 ; V_98 ++ ) {
if ( V_175 & V_191 [ V_98 ] . V_192 ) {
V_198 = V_191 [ V_98 ] . V_198 ;
V_200 = V_203 ;
break;
}
}
V_202:
F_117 ( V_197 , V_198 ) ;
V_197 -> V_200 = V_200 ;
}
static T_1 F_118 ( T_5 V_175 )
{
if ( V_175 & ( V_177 |
V_179 |
V_180 |
V_181 ) )
return V_204 ;
if ( V_175 & ( V_176 |
V_178 |
V_205 ) )
return V_206 ;
if ( V_175 & ( V_183 |
V_184 |
V_185 |
V_186 ) )
return V_207 ;
return V_208 ;
}
static int F_119 ( struct V_76 * V_32 ,
struct V_196 * V_197 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_209 [ V_210 ] ;
T_5 V_211 ;
T_5 V_212 ;
T_5 V_213 ;
int V_15 ;
F_120 ( V_209 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_214 ) , V_209 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_17 ) ;
return V_15 ;
}
F_121 ( V_209 , & V_211 ,
& V_212 , & V_213 ) ;
V_197 -> V_193 = F_113 ( V_211 ) |
F_114 ( V_211 ) |
V_215 | V_216 ;
V_197 -> V_217 = F_115 ( V_212 ) ;
F_116 ( F_122 ( V_32 ) ,
V_213 , V_197 ) ;
V_213 = V_213 ? V_213 : V_211 ;
V_197 -> V_218 = F_118 ( V_213 ) ;
V_197 -> V_219 = F_115 ( V_213 ) ;
V_197 -> V_220 = V_221 ;
return 0 ;
}
static T_5 F_123 ( T_5 V_217 )
{
T_5 V_222 = 0 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < V_190 ; V_98 ++ ) {
if ( V_217 & V_191 [ V_98 ] . V_194 )
V_222 |= V_191 [ V_98 ] . V_192 ;
}
return V_222 ;
}
static T_5 F_124 ( T_5 V_198 )
{
T_5 V_222 = 0 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < V_190 ; V_98 ++ ) {
if ( V_198 == V_191 [ V_98 ] . V_198 )
V_222 |= V_191 [ V_98 ] . V_192 ;
}
return V_222 ;
}
static int F_125 ( struct V_76 * V_32 ,
struct V_196 * V_197 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
struct V_12 * V_12 = V_19 -> V_12 ;
char V_209 [ V_210 ] ;
T_5 V_198 ;
T_5 V_223 ;
T_5 V_211 ;
T_5 V_212 ;
bool V_20 ;
int V_15 ;
V_198 = F_126 ( V_197 ) ;
V_223 = V_197 -> V_224 == V_225 ?
F_123 ( V_197 -> V_217 ) :
F_124 ( V_198 ) ;
F_120 ( V_209 , V_19 -> V_10 , 0 ) ;
V_15 = F_11 ( V_12 -> V_16 , F_12 ( V_214 ) , V_209 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_17 ) ;
return V_15 ;
}
F_121 ( V_209 , & V_211 , & V_212 , NULL ) ;
V_223 = V_223 & V_211 ;
if ( ! V_223 ) {
F_99 ( V_32 , L_18 ) ;
return - V_49 ;
}
if ( V_223 == V_212 )
return 0 ;
F_120 ( V_209 , V_19 -> V_10 , V_223 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_214 ) , V_209 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_19 ) ;
return V_15 ;
}
V_15 = F_17 ( V_19 , & V_20 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_20 ) ;
return V_15 ;
}
if ( ! V_20 )
return 0 ;
V_15 = F_14 ( V_19 , false ) ;
if ( V_15 ) {
F_99 ( V_32 , L_21 ) ;
return V_15 ;
}
V_15 = F_14 ( V_19 , true ) ;
if ( V_15 ) {
F_99 ( V_32 , L_21 ) ;
return V_15 ;
}
return 0 ;
}
static int F_127 ( struct V_12 * V_12 , T_1 V_10 )
{
struct V_19 * V_19 ;
struct V_76 * V_32 ;
bool V_226 ;
T_8 V_227 ;
int V_15 ;
V_32 = F_128 ( sizeof( struct V_19 ) ) ;
if ( ! V_32 )
return - V_41 ;
V_19 = F_46 ( V_32 ) ;
V_19 -> V_32 = V_32 ;
V_19 -> V_12 = V_12 ;
V_19 -> V_10 = V_10 ;
V_227 = F_129 ( V_109 , V_228 ) ;
V_19 -> V_229 = F_87 ( V_227 , V_40 ) ;
if ( ! V_19 -> V_229 ) {
V_15 = - V_41 ;
goto V_230;
}
V_19 -> V_231 = F_87 ( V_227 , V_40 ) ;
if ( ! V_19 -> V_231 ) {
V_15 = - V_41 ;
goto V_232;
}
F_130 ( & V_19 -> V_132 ) ;
V_19 -> V_78 =
F_131 ( struct V_77 ) ;
if ( ! V_19 -> V_78 ) {
V_15 = - V_41 ;
goto V_233;
}
V_32 -> V_234 = & V_235 ;
V_32 -> V_236 = & V_237 ;
V_15 = F_22 ( V_19 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_22 ,
V_19 -> V_10 ) ;
goto V_238;
}
F_132 ( V_32 ) ;
V_32 -> V_239 |= V_240 | V_241 | V_242 |
V_243 ;
V_32 -> V_244 += V_6 ;
V_15 = F_42 ( V_19 , & V_226 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_23 ,
V_19 -> V_10 ) ;
goto V_245;
}
if ( ! V_226 ) {
F_133 ( V_12 -> V_121 -> V_32 , L_24 ,
V_19 -> V_10 ) ;
goto V_246;
}
V_15 = F_40 ( V_19 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_25 ,
V_19 -> V_10 ) ;
goto V_247;
}
V_15 = F_32 ( V_19 , 0 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_26 ,
V_19 -> V_10 ) ;
goto V_248;
}
V_15 = F_29 ( V_19 , V_249 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_27 ,
V_19 -> V_10 ) ;
goto V_250;
}
V_15 = F_14 ( V_19 , false ) ;
if ( V_15 )
goto V_251;
V_15 = F_134 ( V_19 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_28 ,
V_19 -> V_10 ) ;
goto V_252;
}
F_135 ( V_19 ) ;
V_15 = F_136 ( V_32 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_29 ,
V_19 -> V_10 ) ;
goto V_253;
}
V_15 = F_137 ( V_19 ) ;
if ( V_15 )
goto V_254;
V_12 -> V_255 [ V_10 ] = V_19 ;
return 0 ;
V_254:
F_138 ( V_32 ) ;
V_253:
V_252:
V_251:
V_250:
V_248:
V_247:
V_246:
V_245:
V_238:
F_139 ( V_19 -> V_78 ) ;
V_233:
F_28 ( V_19 -> V_231 ) ;
V_232:
F_28 ( V_19 -> V_229 ) ;
V_230:
F_140 ( V_32 ) ;
return V_15 ;
}
static void F_141 ( struct V_19 * V_19 )
{
struct V_76 * V_32 = V_19 -> V_32 ;
struct V_19 * V_126 , * V_256 ;
F_142 (mlxsw_sp_vport, tmp,
&mlxsw_sp_port->vports_list, vport.list) {
T_2 V_35 = F_143 ( V_126 ) ;
F_144 ( F_145 ( V_126 -> V_32 ) ) ;
F_103 ( V_32 , 0 , V_35 ) ;
}
}
static void F_146 ( struct V_12 * V_12 , T_1 V_10 )
{
struct V_19 * V_19 = V_12 -> V_255 [ V_10 ] ;
if ( ! V_19 )
return;
F_138 ( V_19 -> V_32 ) ;
F_141 ( V_19 ) ;
F_147 ( V_19 ) ;
F_139 ( V_19 -> V_78 ) ;
F_28 ( V_19 -> V_231 ) ;
F_28 ( V_19 -> V_229 ) ;
F_140 ( V_19 -> V_32 ) ;
}
static void F_148 ( struct V_12 * V_12 )
{
int V_98 ;
for ( V_98 = 1 ; V_98 < V_257 ; V_98 ++ )
F_146 ( V_12 , V_98 ) ;
F_28 ( V_12 -> V_255 ) ;
}
static int F_149 ( struct V_12 * V_12 )
{
T_8 V_258 ;
int V_98 ;
int V_15 ;
V_258 = sizeof( struct V_19 * ) * V_257 ;
V_12 -> V_255 = F_87 ( V_258 , V_40 ) ;
if ( ! V_12 -> V_255 )
return - V_41 ;
for ( V_98 = 1 ; V_98 < V_257 ; V_98 ++ ) {
V_15 = F_127 ( V_12 , V_98 ) ;
if ( V_15 )
goto V_259;
}
return 0 ;
V_259:
for ( V_98 -- ; V_98 >= 1 ; V_98 -- )
F_146 ( V_12 , V_98 ) ;
F_28 ( V_12 -> V_255 ) ;
return V_15 ;
}
static void F_150 ( const struct V_260 * V_261 ,
char * V_262 , void * V_263 )
{
struct V_12 * V_12 = V_263 ;
struct V_19 * V_19 ;
enum V_264 V_265 ;
T_1 V_10 ;
V_10 = F_151 ( V_262 ) ;
V_19 = V_12 -> V_255 [ V_10 ] ;
if ( ! V_19 ) {
F_152 ( V_12 -> V_121 -> V_32 , L_30 ,
V_10 ) ;
return;
}
V_265 = F_153 ( V_262 ) ;
if ( V_265 == V_266 ) {
F_154 ( V_19 -> V_32 , L_31 ) ;
F_155 ( V_19 -> V_32 ) ;
} else {
F_154 ( V_19 -> V_32 , L_32 ) ;
F_132 ( V_19 -> V_32 ) ;
}
}
static int F_156 ( struct V_12 * V_12 ,
enum V_267 V_268 )
{
struct V_269 * V_270 ;
char V_271 [ V_272 ] ;
int V_15 ;
switch ( V_268 ) {
case V_273 :
V_270 = & V_274 ;
break;
}
V_15 = F_157 ( V_12 -> V_16 , V_270 , V_12 ) ;
if ( V_15 )
return V_15 ;
F_158 ( V_271 , V_275 , V_268 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_276 ) , V_271 ) ;
if ( V_15 )
goto V_277;
return 0 ;
V_277:
F_159 ( V_12 -> V_16 , V_270 , V_12 ) ;
return V_15 ;
}
static void F_160 ( struct V_12 * V_12 ,
enum V_267 V_268 )
{
struct V_269 * V_270 ;
switch ( V_268 ) {
case V_273 :
V_270 = & V_274 ;
break;
}
F_159 ( V_12 -> V_16 , V_270 , V_12 ) ;
}
static void F_161 ( struct V_1 * V_2 , T_1 V_10 ,
void * V_263 )
{
struct V_12 * V_12 = V_263 ;
struct V_19 * V_19 = V_12 -> V_255 [ V_10 ] ;
struct V_77 * V_78 ;
if ( F_52 ( ! V_19 ) ) {
F_162 ( V_12 -> V_121 -> V_32 , L_33 ,
V_10 ) ;
return;
}
V_2 -> V_32 = V_19 -> V_32 ;
V_78 = F_59 ( V_19 -> V_78 ) ;
F_60 ( & V_78 -> V_85 ) ;
V_78 -> V_95 ++ ;
V_78 -> V_96 += V_2 -> V_80 ;
F_61 ( & V_78 -> V_85 ) ;
V_2 -> V_278 = F_163 ( V_2 , V_2 -> V_32 ) ;
F_164 ( V_2 ) ;
}
static int F_165 ( struct V_12 * V_12 )
{
char V_279 [ V_280 ] ;
char V_271 [ V_272 ] ;
int V_98 ;
int V_15 ;
F_166 ( V_279 , V_281 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_282 ) , V_279 ) ;
if ( V_15 )
return V_15 ;
F_166 ( V_279 , V_283 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_282 ) , V_279 ) ;
if ( V_15 )
return V_15 ;
for ( V_98 = 0 ; V_98 < F_167 ( V_284 ) ; V_98 ++ ) {
V_15 = F_168 ( V_12 -> V_16 ,
& V_284 [ V_98 ] ,
V_12 ) ;
if ( V_15 )
goto V_285;
F_158 ( V_271 , V_286 ,
V_284 [ V_98 ] . V_268 ) ;
V_15 = F_16 ( V_12 -> V_16 , F_12 ( V_276 ) , V_271 ) ;
if ( V_15 )
goto V_287;
}
return 0 ;
V_287:
F_169 ( V_12 -> V_16 ,
& V_284 [ V_98 ] ,
V_12 ) ;
V_285:
for ( V_98 -- ; V_98 >= 0 ; V_98 -- ) {
F_158 ( V_271 , V_275 ,
V_284 [ V_98 ] . V_268 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_276 ) , V_271 ) ;
F_169 ( V_12 -> V_16 ,
& V_284 [ V_98 ] ,
V_12 ) ;
}
return V_15 ;
}
static void F_170 ( struct V_12 * V_12 )
{
char V_271 [ V_272 ] ;
int V_98 ;
for ( V_98 = 0 ; V_98 < F_167 ( V_284 ) ; V_98 ++ ) {
F_158 ( V_271 , V_275 ,
V_284 [ V_98 ] . V_268 ) ;
F_16 ( V_12 -> V_16 , F_12 ( V_276 ) , V_271 ) ;
F_169 ( V_12 -> V_16 ,
& V_284 [ V_98 ] ,
V_12 ) ;
}
}
static int F_171 ( struct V_288 * V_288 ,
enum V_289 type ,
enum V_290 V_291 )
{
enum V_292 V_293 ;
enum V_294 V_295 ;
char V_296 [ V_297 ] ;
if ( V_291 == V_298 )
V_293 = V_299 ;
else
V_293 = V_300 ;
if ( type == V_301 )
V_295 = V_302 ;
else
V_295 = V_303 ;
F_172 ( V_296 , type , V_291 , V_293 ,
V_295 ) ;
return F_16 ( V_288 , F_12 ( V_304 ) , V_296 ) ;
}
static int F_173 ( struct V_12 * V_12 )
{
int type , V_15 ;
for ( type = 0 ; type < V_305 ; type ++ ) {
if ( type == V_306 )
continue;
V_15 = F_171 ( V_12 -> V_16 , type ,
V_298 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_171 ( V_12 -> V_16 , type ,
V_307 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_174 ( struct V_12 * V_12 )
{
char V_308 [ V_309 ] ;
F_175 ( V_308 , V_310 |
V_311 |
V_312 |
V_313 |
V_314 |
V_315 |
V_316 |
V_317 |
V_318 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_319 ) , V_308 ) ;
}
static int F_176 ( void * V_263 , struct V_288 * V_288 ,
const struct V_320 * V_320 )
{
struct V_12 * V_12 = V_263 ;
int V_15 ;
V_12 -> V_16 = V_288 ;
V_12 -> V_121 = V_320 ;
F_130 ( & V_12 -> V_112 . V_125 ) ;
F_130 ( & V_12 -> V_321 . V_125 ) ;
F_130 ( & V_12 -> V_322 . V_125 ) ;
V_15 = F_10 ( V_12 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_34 ) ;
return V_15 ;
}
V_15 = F_149 ( V_12 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_35 ) ;
return V_15 ;
}
V_15 = F_156 ( V_12 , V_273 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_36 ) ;
goto V_323;
}
V_15 = F_165 ( V_12 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_37 ) ;
goto V_285;
}
V_15 = F_173 ( V_12 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_38 ) ;
goto V_324;
}
V_15 = F_177 ( V_12 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_39 ) ;
goto V_325;
}
V_15 = F_174 ( V_12 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_40 ) ;
goto V_326;
}
V_15 = F_178 ( V_12 ) ;
if ( V_15 ) {
F_85 ( V_12 -> V_121 -> V_32 , L_41 ) ;
goto V_327;
}
return 0 ;
V_327:
V_326:
V_325:
V_324:
F_170 ( V_12 ) ;
V_285:
F_160 ( V_12 , V_273 ) ;
V_323:
F_148 ( V_12 ) ;
return V_15 ;
}
static void F_179 ( void * V_263 )
{
struct V_12 * V_12 = V_263 ;
F_180 ( V_12 ) ;
F_170 ( V_12 ) ;
F_160 ( V_12 , V_273 ) ;
F_148 ( V_12 ) ;
}
static int
F_181 ( const struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_328 [ V_329 ] ;
F_182 ( V_328 , V_330 ) ;
F_183 ( V_328 , V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_331 ) , V_328 ) ;
}
static int
F_184 ( const struct V_19 * V_19 ,
T_2 V_61 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_328 [ V_329 ] ;
F_182 ( V_328 , V_332 ) ;
F_185 ( V_328 , V_61 ) ;
F_186 ( V_328 ,
V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_331 ) , V_328 ) ;
}
static int
F_187 ( const struct V_19 * V_19 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_328 [ V_329 ] ;
F_182 ( V_328 , V_333 ) ;
F_188 ( V_328 , V_19 -> V_130 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_331 ) , V_328 ) ;
}
static int
F_189 ( const struct V_19 * V_19 ,
T_2 V_61 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_328 [ V_329 ] ;
F_182 ( V_328 , V_334 ) ;
F_185 ( V_328 , V_61 ) ;
F_190 ( V_328 , V_19 -> V_130 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_331 ) , V_328 ) ;
}
static int
F_191 ( const struct V_19 * V_19 )
{
int V_15 , V_335 = 0 ;
T_2 V_35 ;
for ( V_35 = 1 ; V_35 < V_109 - 1 ; V_35 ++ ) {
V_15 = F_184 ( V_19 , V_35 ) ;
if ( V_15 )
V_335 = V_15 ;
}
return V_335 ;
}
static int
F_192 ( const struct V_19 * V_19 )
{
int V_15 , V_335 = 0 ;
T_2 V_35 ;
for ( V_35 = 1 ; V_35 < V_109 - 1 ; V_35 ++ ) {
V_15 = F_189 ( V_19 , V_35 ) ;
if ( V_15 )
V_335 = V_15 ;
}
return V_335 ;
}
static int F_193 ( struct V_19 * V_19 )
{
if ( ! F_194 ( & V_19 -> V_132 ) )
if ( V_19 -> V_129 )
return F_192 ( V_19 ) ;
else
return F_191 ( V_19 ) ;
else
if ( V_19 -> V_129 )
return F_187 ( V_19 ) ;
else
return F_181 ( V_19 ) ;
}
static int F_195 ( struct V_19 * V_126 )
{
T_2 V_111 = F_196 ( V_126 ) ;
T_2 V_61 = F_81 ( V_111 ) ;
if ( V_126 -> V_129 )
return F_189 ( V_126 ,
V_61 ) ;
else
return F_184 ( V_126 , V_61 ) ;
}
static bool F_197 ( const struct V_76 * V_32 )
{
return V_32 -> V_234 == & V_235 ;
}
static int F_198 ( struct V_19 * V_19 )
{
struct V_76 * V_32 = V_19 -> V_32 ;
int V_15 ;
V_15 = F_103 ( V_32 , 0 , 1 ) ;
if ( V_15 )
return V_15 ;
V_19 -> V_336 = 1 ;
V_19 -> V_337 = 1 ;
V_19 -> V_338 = 1 ;
V_19 -> V_339 = 1 ;
return 0 ;
}
static int F_199 ( struct V_19 * V_19 ,
bool V_340 )
{
struct V_76 * V_32 = V_19 -> V_32 ;
if ( V_340 && F_193 ( V_19 ) )
F_99 ( V_19 -> V_32 , L_42 ) ;
F_200 ( V_19 , 1 ) ;
V_19 -> V_336 = 0 ;
V_19 -> V_337 = 0 ;
V_19 -> V_338 = 0 ;
V_19 -> V_339 = 0 ;
return F_95 ( V_32 , 0 , 1 ) ;
}
static bool F_201 ( struct V_12 * V_12 ,
struct V_76 * V_341 )
{
return ! V_12 -> V_342 . V_32 ||
V_12 -> V_342 . V_32 == V_341 ;
}
static void F_202 ( struct V_12 * V_12 ,
struct V_76 * V_341 )
{
V_12 -> V_342 . V_32 = V_341 ;
V_12 -> V_342 . V_343 ++ ;
}
static void F_203 ( struct V_12 * V_12 ,
struct V_76 * V_341 )
{
if ( -- V_12 -> V_342 . V_343 == 0 )
V_12 -> V_342 . V_32 = NULL ;
}
static int F_204 ( struct V_12 * V_12 , T_2 V_130 )
{
char V_344 [ V_345 ] ;
F_205 ( V_344 , V_130 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_346 ) , V_344 ) ;
}
static int F_206 ( struct V_12 * V_12 , T_2 V_130 )
{
char V_344 [ V_345 ] ;
F_207 ( V_344 , V_130 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_346 ) , V_344 ) ;
}
static int F_208 ( struct V_19 * V_19 ,
T_2 V_130 , T_1 V_347 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_348 [ V_349 ] ;
F_209 ( V_348 , V_19 -> V_10 ,
V_130 , V_347 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_350 ) , V_348 ) ;
}
static int F_210 ( struct V_19 * V_19 ,
T_2 V_130 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_348 [ V_349 ] ;
F_211 ( V_348 , V_19 -> V_10 ,
V_130 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_350 ) , V_348 ) ;
}
static int F_212 ( struct V_19 * V_19 ,
T_2 V_130 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_348 [ V_349 ] ;
F_213 ( V_348 , V_19 -> V_10 ,
V_130 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_350 ) , V_348 ) ;
}
static int F_214 ( struct V_19 * V_19 ,
T_2 V_130 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_348 [ V_349 ] ;
F_215 ( V_348 , V_19 -> V_10 ,
V_130 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_350 ) , V_348 ) ;
}
static int F_216 ( struct V_12 * V_12 ,
struct V_76 * V_351 ,
T_2 * V_352 )
{
struct V_353 * V_354 ;
int V_355 = - 1 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < V_356 ; V_98 ++ ) {
V_354 = F_217 ( V_12 , V_98 ) ;
if ( V_354 -> V_343 ) {
if ( V_354 -> V_32 == V_351 ) {
* V_352 = V_98 ;
return 0 ;
}
} else if ( V_355 < 0 ) {
V_355 = V_98 ;
}
}
if ( V_355 < 0 )
return - V_357 ;
* V_352 = V_355 ;
return 0 ;
}
static bool
F_218 ( struct V_12 * V_12 ,
struct V_76 * V_351 ,
struct V_358 * V_359 )
{
T_2 V_130 ;
if ( F_216 ( V_12 , V_351 , & V_130 ) != 0 )
return false ;
if ( V_359 -> V_360 != V_361 )
return false ;
return true ;
}
static int F_219 ( struct V_12 * V_12 ,
T_2 V_130 , T_1 * V_362 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_363 ; V_98 ++ ) {
if ( ! F_220 ( V_12 , V_130 , V_98 ) ) {
* V_362 = V_98 ;
return 0 ;
}
}
return - V_357 ;
}
static int F_221 ( struct V_19 * V_19 ,
struct V_76 * V_351 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_353 * V_354 ;
T_2 V_130 ;
T_1 V_347 ;
int V_15 ;
V_15 = F_216 ( V_12 , V_351 , & V_130 ) ;
if ( V_15 )
return V_15 ;
V_354 = F_217 ( V_12 , V_130 ) ;
if ( ! V_354 -> V_343 ) {
V_15 = F_204 ( V_12 , V_130 ) ;
if ( V_15 )
return V_15 ;
V_354 -> V_32 = V_351 ;
}
V_15 = F_219 ( V_12 , V_130 , & V_347 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_208 ( V_19 , V_130 , V_347 ) ;
if ( V_15 )
goto V_364;
V_15 = F_212 ( V_19 , V_130 ) ;
if ( V_15 )
goto V_365;
F_222 ( V_12 -> V_16 , V_130 , V_347 ,
V_19 -> V_10 ) ;
V_19 -> V_130 = V_130 ;
V_19 -> V_129 = 1 ;
V_354 -> V_343 ++ ;
return 0 ;
V_364:
if ( ! V_354 -> V_343 )
F_206 ( V_12 , V_130 ) ;
V_365:
F_210 ( V_19 , V_130 ) ;
return V_15 ;
}
static int F_223 ( struct V_19 * V_19 ,
struct V_76 * V_351 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
struct V_19 * V_126 ;
struct V_353 * V_354 ;
T_2 V_130 = V_19 -> V_130 ;
int V_15 ;
if ( ! V_19 -> V_129 )
return 0 ;
V_354 = F_217 ( V_12 , V_130 ) ;
F_144 ( V_354 -> V_343 == 0 ) ;
V_15 = F_214 ( V_19 , V_130 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_210 ( V_19 , V_130 ) ;
if ( V_15 )
return V_15 ;
F_77 (mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
struct V_76 * V_341 ;
if ( ! V_126 -> V_339 )
continue;
V_341 = F_224 ( V_126 ) ;
F_225 ( V_126 , V_341 , false ) ;
}
if ( V_19 -> V_339 ) {
F_226 ( V_19 ) ;
F_199 ( V_19 , false ) ;
F_203 ( V_12 , NULL ) ;
}
if ( V_354 -> V_343 == 1 ) {
if ( F_187 ( V_19 ) )
F_99 ( V_19 -> V_32 , L_42 ) ;
V_15 = F_206 ( V_12 , V_130 ) ;
if ( V_15 )
return V_15 ;
}
F_227 ( V_12 -> V_16 , V_130 ,
V_19 -> V_10 ) ;
V_19 -> V_129 = 0 ;
V_354 -> V_343 -- ;
return 0 ;
}
static int F_228 ( struct V_19 * V_19 ,
T_2 V_130 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_344 [ V_345 ] ;
F_229 ( V_344 , V_130 ,
V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_346 ) , V_344 ) ;
}
static int F_230 ( struct V_19 * V_19 ,
T_2 V_130 )
{
struct V_12 * V_12 = V_19 -> V_12 ;
char V_344 [ V_345 ] ;
F_231 ( V_344 , V_130 ,
V_19 -> V_10 ) ;
return F_16 ( V_12 -> V_16 , F_12 ( V_346 ) , V_344 ) ;
}
static int F_232 ( struct V_19 * V_19 ,
bool V_366 )
{
if ( V_366 )
return F_228 ( V_19 ,
V_19 -> V_130 ) ;
else
return F_230 ( V_19 ,
V_19 -> V_130 ) ;
}
static int F_233 ( struct V_19 * V_19 ,
struct V_367 * V_368 )
{
return F_232 ( V_19 , V_368 -> V_369 ) ;
}
static int F_234 ( struct V_19 * V_19 ,
struct V_76 * V_370 )
{
struct V_19 * V_126 ;
T_2 V_35 = F_235 ( V_370 ) ;
V_126 = F_96 ( V_19 , V_35 ) ;
if ( ! V_126 ) {
F_144 ( ! V_126 ) ;
return - V_49 ;
}
V_126 -> V_32 = V_370 ;
return 0 ;
}
static int F_236 ( struct V_19 * V_19 ,
struct V_76 * V_370 )
{
struct V_19 * V_126 ;
T_2 V_35 = F_235 ( V_370 ) ;
V_126 = F_96 ( V_19 , V_35 ) ;
if ( ! V_126 ) {
F_144 ( ! V_126 ) ;
return - V_49 ;
}
if ( V_126 -> V_339 ) {
struct V_76 * V_341 ;
V_341 = F_224 ( V_126 ) ;
F_225 ( V_126 , V_341 , true ) ;
}
V_126 -> V_32 = V_19 -> V_32 ;
return 0 ;
}
static int F_237 ( struct V_76 * V_32 ,
unsigned long V_371 , void * V_372 )
{
struct V_373 * V_368 ;
struct V_19 * V_19 ;
struct V_76 * V_374 ;
struct V_12 * V_12 ;
int V_15 ;
V_19 = F_46 ( V_32 ) ;
V_12 = V_19 -> V_12 ;
V_368 = V_372 ;
switch ( V_371 ) {
case V_375 :
V_374 = V_368 -> V_374 ;
if ( ! V_368 -> V_376 || ! V_368 -> V_377 )
break;
if ( F_238 ( V_374 ) &&
! F_201 ( V_12 , V_374 ) )
return V_378 ;
if ( F_239 ( V_374 ) &&
! F_218 ( V_12 , V_374 ,
V_368 -> V_379 ) )
return V_378 ;
break;
case V_380 :
V_374 = V_368 -> V_374 ;
if ( F_145 ( V_374 ) ) {
if ( V_368 -> V_377 ) {
V_15 = F_234 ( V_19 ,
V_374 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_43 ) ;
return V_378 ;
}
} else {
V_15 = F_236 ( V_19 ,
V_374 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_44 ) ;
return V_378 ;
}
}
} else if ( F_238 ( V_374 ) ) {
if ( V_368 -> V_377 ) {
V_15 = F_198 ( V_19 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_45 ) ;
return V_378 ;
}
F_202 ( V_12 , V_374 ) ;
} else {
V_15 = F_199 ( V_19 ,
true ) ;
F_203 ( V_12 , V_374 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_46 ) ;
return V_378 ;
}
}
} else if ( F_239 ( V_374 ) ) {
if ( V_368 -> V_377 ) {
V_15 = F_221 ( V_19 ,
V_374 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_47 ) ;
return V_378 ;
}
} else {
V_15 = F_223 ( V_19 ,
V_374 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_48 ) ;
return V_378 ;
}
}
}
break;
}
return V_381 ;
}
static int F_240 ( struct V_76 * V_32 ,
unsigned long V_371 , void * V_372 )
{
struct V_382 * V_368 ;
struct V_19 * V_19 ;
int V_15 ;
V_19 = F_46 ( V_32 ) ;
V_368 = V_372 ;
switch ( V_371 ) {
case V_383 :
if ( F_241 ( V_32 ) && V_19 -> V_129 ) {
V_15 = F_233 ( V_19 ,
V_368 -> V_384 ) ;
if ( V_15 )
F_99 ( V_32 , L_49 ) ;
}
break;
}
return V_381 ;
}
static int F_242 ( struct V_76 * V_32 ,
unsigned long V_371 , void * V_372 )
{
switch ( V_371 ) {
case V_375 :
case V_380 :
return F_237 ( V_32 , V_371 , V_372 ) ;
case V_383 :
return F_240 ( V_32 , V_371 , V_372 ) ;
}
return V_381 ;
}
static int F_243 ( struct V_76 * V_351 ,
unsigned long V_371 , void * V_372 )
{
struct V_76 * V_32 ;
struct V_385 * V_386 ;
int V_387 ;
F_244 (lag_dev, dev, iter) {
if ( F_197 ( V_32 ) ) {
V_387 = F_242 ( V_32 , V_371 , V_372 ) ;
if ( V_387 == V_378 )
return V_387 ;
}
}
return V_381 ;
}
static struct V_110 *
F_245 ( const struct V_12 * V_12 ,
const struct V_76 * V_341 )
{
struct V_110 * V_111 ;
F_77 (vfid, &mlxsw_sp->br_vfids.list, list) {
if ( V_111 -> V_341 == V_341 )
return V_111 ;
}
return NULL ;
}
static T_2 F_246 ( T_2 V_111 )
{
return V_111 - V_114 ;
}
static T_2 F_247 ( T_2 V_388 )
{
return V_114 + V_388 ;
}
static T_2 F_248 ( const struct V_12 * V_12 )
{
return F_79 ( V_12 -> V_321 . V_113 ,
V_389 ) ;
}
static struct V_110 * F_249 ( struct V_12 * V_12 ,
struct V_76 * V_341 )
{
struct V_120 * V_32 = V_12 -> V_121 -> V_32 ;
struct V_110 * V_111 ;
T_2 V_122 ;
int V_15 ;
V_122 = F_247 ( F_248 ( V_12 ) ) ;
if ( V_122 == V_390 ) {
F_85 ( V_32 , L_1 ) ;
return F_86 ( - V_123 ) ;
}
V_15 = F_80 ( V_12 , V_122 ) ;
if ( V_15 ) {
F_85 ( V_32 , L_2 , V_122 ) ;
return F_86 ( V_15 ) ;
}
V_111 = F_87 ( sizeof( * V_111 ) , V_40 ) ;
if ( ! V_111 )
goto V_124;
V_111 -> V_111 = V_122 ;
V_111 -> V_341 = V_341 ;
F_88 ( & V_111 -> V_125 , & V_12 -> V_321 . V_125 ) ;
F_89 ( F_246 ( V_122 ) , V_12 -> V_321 . V_113 ) ;
return V_111 ;
V_124:
F_83 ( V_12 , V_122 ) ;
return F_86 ( - V_41 ) ;
}
static void F_250 ( struct V_12 * V_12 ,
struct V_110 * V_111 )
{
T_2 V_388 = F_246 ( V_111 -> V_111 ) ;
F_91 ( V_388 , V_12 -> V_321 . V_113 ) ;
F_92 ( & V_111 -> V_125 ) ;
F_83 ( V_12 , V_111 -> V_111 ) ;
F_28 ( V_111 ) ;
}
static int F_225 ( struct V_19 * V_126 ,
struct V_76 * V_341 ,
bool V_340 )
{
struct V_12 * V_12 = V_126 -> V_12 ;
T_2 V_35 = F_143 ( V_126 ) ;
struct V_76 * V_32 = V_126 -> V_32 ;
struct V_110 * V_111 , * V_391 ;
int V_15 ;
V_111 = F_245 ( V_12 , V_341 ) ;
if ( ! V_111 ) {
F_144 ( ! V_111 ) ;
return - V_49 ;
}
V_391 = F_76 ( V_12 , V_35 ) ;
if ( ! V_391 ) {
V_391 = F_84 ( V_12 , V_35 ) ;
if ( F_98 ( V_391 ) ) {
F_99 ( V_32 , L_4 ,
V_35 ) ;
return F_100 ( V_391 ) ;
}
}
V_15 = F_36 ( V_126 ,
V_106 ,
false ,
F_81 ( V_111 -> V_111 ) ,
V_35 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_50 ,
V_111 -> V_111 ) ;
goto V_392;
}
V_15 = F_36 ( V_126 ,
V_106 ,
true ,
F_81 ( V_391 -> V_111 ) ,
V_35 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_51 ,
V_391 -> V_111 ) ;
goto V_393;
}
V_15 = F_38 ( V_126 , V_35 , false ) ;
if ( V_15 ) {
F_99 ( V_32 , L_52 ) ;
goto V_138;
}
V_15 = F_101 ( V_126 , V_111 -> V_111 , false ,
false ) ;
if ( V_15 ) {
F_99 ( V_32 , L_53 ) ;
goto V_136;
}
V_15 = F_24 ( V_126 , V_35 ,
V_140 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_54 ) ;
goto V_141;
}
if ( V_340 && F_195 ( V_126 ) )
F_99 ( V_32 , L_42 ) ;
V_391 -> V_135 ++ ;
V_126 -> V_131 . V_111 = V_391 ;
V_111 -> V_135 -- ;
if ( ! V_111 -> V_135 )
F_250 ( V_12 , V_111 ) ;
V_126 -> V_336 = 0 ;
V_126 -> V_337 = 0 ;
V_126 -> V_338 = 0 ;
V_126 -> V_339 = 0 ;
return 0 ;
V_141:
V_136:
V_138:
V_393:
V_392:
if ( ! V_391 -> V_135 )
F_90 ( V_12 , V_391 ) ;
return V_15 ;
}
static int F_251 ( struct V_19 * V_126 ,
struct V_76 * V_341 )
{
struct V_110 * V_394 = V_126 -> V_131 . V_111 ;
struct V_12 * V_12 = V_126 -> V_12 ;
T_2 V_35 = F_143 ( V_126 ) ;
struct V_76 * V_32 = V_126 -> V_32 ;
struct V_110 * V_111 ;
int V_15 ;
V_111 = F_245 ( V_12 , V_341 ) ;
if ( ! V_111 ) {
V_111 = F_249 ( V_12 , V_341 ) ;
if ( F_98 ( V_111 ) ) {
F_99 ( V_32 , L_55 ) ;
return F_100 ( V_111 ) ;
}
}
V_15 = F_101 ( V_126 , V_111 -> V_111 , true , false ) ;
if ( V_15 ) {
F_99 ( V_32 , L_6 ,
V_111 -> V_111 ) ;
goto V_395;
}
V_15 = F_38 ( V_126 , V_35 , true ) ;
if ( V_15 ) {
F_99 ( V_32 , L_56 ) ;
goto V_138;
}
V_15 = F_36 ( V_126 ,
V_106 ,
false ,
F_81 ( V_394 -> V_111 ) ,
V_35 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_50 ,
V_394 -> V_111 ) ;
goto V_392;
}
V_15 = F_36 ( V_126 ,
V_106 ,
true ,
F_81 ( V_111 -> V_111 ) ,
V_35 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_51 ,
V_111 -> V_111 ) ;
goto V_393;
}
V_111 -> V_135 ++ ;
V_126 -> V_131 . V_111 = V_111 ;
V_394 -> V_135 -- ;
if ( ! V_394 -> V_135 )
F_90 ( V_12 , V_394 ) ;
V_126 -> V_336 = 1 ;
V_126 -> V_337 = 1 ;
V_126 -> V_338 = 1 ;
V_126 -> V_339 = 1 ;
return 0 ;
V_393:
F_36 ( V_126 ,
V_106 , false ,
F_81 ( V_394 -> V_111 ) , V_35 ) ;
V_392:
F_38 ( V_126 , V_35 , false ) ;
V_138:
F_101 ( V_126 , V_111 -> V_111 , false , false ) ;
V_395:
if ( ! V_111 -> V_135 )
F_250 ( V_12 , V_111 ) ;
return V_15 ;
}
static bool
F_252 ( const struct V_19 * V_19 ,
const struct V_76 * V_341 )
{
struct V_19 * V_126 ;
F_77 (mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
if ( F_224 ( V_126 ) == V_341 )
return false ;
}
return true ;
}
static int F_253 ( struct V_76 * V_32 ,
unsigned long V_371 , void * V_372 ,
T_2 V_35 )
{
struct V_19 * V_19 = F_46 ( V_32 ) ;
struct V_373 * V_368 = V_372 ;
struct V_19 * V_126 ;
struct V_76 * V_374 ;
int V_15 ;
V_126 = F_96 ( V_19 , V_35 ) ;
switch ( V_371 ) {
case V_375 :
V_374 = V_368 -> V_374 ;
if ( ! V_368 -> V_376 || ! V_368 -> V_377 )
break;
if ( ! F_238 ( V_374 ) )
return V_378 ;
if ( ! F_252 ( V_19 ,
V_374 ) )
return V_378 ;
break;
case V_380 :
V_374 = V_368 -> V_374 ;
if ( ! V_368 -> V_376 )
break;
if ( V_368 -> V_377 ) {
if ( ! V_126 ) {
F_144 ( ! V_126 ) ;
return V_378 ;
}
V_15 = F_251 ( V_126 ,
V_374 ) ;
if ( V_15 ) {
F_99 ( V_32 , L_45 ) ;
return V_378 ;
}
} else {
if ( ! V_126 )
return V_381 ;
V_15 = F_225 ( V_126 ,
V_374 , true ) ;
if ( V_15 ) {
F_99 ( V_32 , L_46 ) ;
return V_378 ;
}
}
}
return V_381 ;
}
static int F_254 ( struct V_76 * V_351 ,
unsigned long V_371 , void * V_372 ,
T_2 V_35 )
{
struct V_76 * V_32 ;
struct V_385 * V_386 ;
int V_387 ;
F_244 (lag_dev, dev, iter) {
if ( F_197 ( V_32 ) ) {
V_387 = F_253 ( V_32 , V_371 , V_372 ,
V_35 ) ;
if ( V_387 == V_378 )
return V_387 ;
}
}
return V_381 ;
}
static int F_255 ( struct V_76 * V_370 ,
unsigned long V_371 , void * V_372 )
{
struct V_76 * V_396 = F_256 ( V_370 ) ;
T_2 V_35 = F_235 ( V_370 ) ;
if ( F_197 ( V_396 ) )
return F_253 ( V_396 , V_371 , V_372 ,
V_35 ) ;
else if ( F_239 ( V_396 ) )
return F_254 ( V_396 , V_371 , V_372 ,
V_35 ) ;
return V_381 ;
}
static int F_257 ( struct V_397 * V_398 ,
unsigned long V_371 , void * V_372 )
{
struct V_76 * V_32 = F_258 ( V_372 ) ;
if ( F_197 ( V_32 ) )
return F_242 ( V_32 , V_371 , V_372 ) ;
if ( F_239 ( V_32 ) )
return F_243 ( V_32 , V_371 , V_372 ) ;
if ( F_145 ( V_32 ) )
return F_255 ( V_32 , V_371 , V_372 ) ;
return V_381 ;
}
static int T_9 F_259 ( void )
{
int V_15 ;
F_260 ( & V_399 ) ;
V_15 = F_261 ( & V_400 ) ;
if ( V_15 )
goto V_401;
return 0 ;
V_401:
F_262 ( & V_399 ) ;
return V_15 ;
}
static void T_10 F_263 ( void )
{
F_264 ( & V_400 ) ;
F_262 ( & V_399 ) ;
}
