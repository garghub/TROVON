static T_1 F_1 ( struct V_1 * V_1 ,
T_1 V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
T_1 V_5 = V_2 ;
V_5 = V_4 ? V_4 -> V_5 : V_5 ;
if ( ! V_5 )
V_5 = V_1 -> V_6 ;
return V_5 ;
}
static struct V_1 *
F_3 ( struct V_7 * V_8 ,
struct V_1 * V_1 )
{
struct V_1 * V_9 ;
struct V_3 * V_5 ;
T_1 V_2 ;
if ( F_4 ( V_8 ) ) {
V_5 = F_5 ( V_1 -> V_10 ,
V_8 ) ;
if ( V_5 ) {
V_9 =
F_6 ( V_1 ,
V_5 -> V_5 ) ;
F_7 ( ! V_9 ) ;
return V_9 ;
}
}
if ( ! F_8 ( V_8 ) )
return V_1 ;
V_2 = F_9 ( V_8 ) ;
V_9 = F_10 ( V_1 , V_2 ) ;
F_7 ( ! V_9 ) ;
return V_9 ;
}
static int F_11 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
struct V_1 * V_1 = F_12 ( V_8 ) ;
struct V_10 * V_10 = V_1 -> V_10 ;
V_1 = F_3 ( V_12 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_12 -> V_15 ) {
case V_16 :
V_12 -> V_17 . V_18 . V_19 = sizeof( V_10 -> V_20 ) ;
memcpy ( & V_12 -> V_17 . V_18 . V_15 , & V_10 -> V_20 ,
V_12 -> V_17 . V_18 . V_19 ) ;
break;
case V_21 :
V_12 -> V_17 . V_22 =
( V_1 -> V_23 ? V_24 : 0 ) |
( V_1 -> V_25 ? V_26 : 0 ) |
( V_1 -> V_27 ? V_28 : 0 ) ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_1 ,
T_2 V_30 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
enum V_31 V_32 ;
char * V_33 ;
T_1 V_2 ;
int V_34 ;
switch ( V_30 ) {
case V_35 :
V_32 = V_36 ;
break;
case V_37 :
V_32 = V_38 ;
break;
case V_39 :
case V_40 :
case V_41 :
V_32 = V_42 ;
break;
default:
F_14 () ;
}
V_33 = F_15 ( V_43 , V_44 ) ;
if ( ! V_33 )
return - V_45 ;
F_16 ( V_33 , V_1 -> V_46 ) ;
if ( F_17 ( V_1 ) ) {
V_2 = F_18 ( V_1 ) ;
F_19 ( V_33 , V_2 , V_32 ) ;
} else {
F_20 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_19 ( V_33 , V_2 , V_32 ) ;
}
V_34 = F_21 ( V_10 -> V_47 , F_22 ( V_48 ) , V_33 ) ;
F_23 ( V_33 ) ;
return V_34 ;
}
static int F_24 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
T_2 V_30 )
{
if ( F_25 ( V_50 ) )
return 0 ;
V_1 -> V_51 = V_30 ;
return F_13 ( V_1 , V_30 ) ;
}
static int F_26 ( struct V_1 * V_1 ,
T_1 V_52 , T_1 V_53 ,
enum V_54 V_55 ,
bool V_56 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
T_1 V_46 = V_1 -> V_46 ;
enum V_57 V_58 ;
T_1 V_59 = V_53 - V_52 + 1 ;
char * V_60 ;
int V_34 ;
if ( F_17 ( V_1 ) )
V_58 = V_61 ;
else
V_58 = V_62 ;
V_60 = F_15 ( V_63 , V_44 ) ;
if ( ! V_60 )
return - V_45 ;
F_27 ( V_60 , V_55 , V_52 ,
V_58 , V_59 , V_46 , V_56 ) ;
V_34 = F_21 ( V_10 -> V_47 , F_22 ( V_64 ) , V_60 ) ;
F_23 ( V_60 ) ;
return V_34 ;
}
static int F_28 ( struct V_1 * V_1 ,
T_1 V_52 , T_1 V_53 , bool V_65 ,
bool V_66 , bool V_67 )
{
int V_34 ;
V_34 = F_26 ( V_1 , V_52 , V_53 ,
V_68 , V_65 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_26 ( V_1 , V_52 , V_53 ,
V_69 , V_66 ) ;
if ( V_34 )
goto V_70;
V_34 = F_26 ( V_1 , V_52 , V_53 ,
V_71 , V_67 ) ;
if ( V_34 )
goto V_72;
return 0 ;
V_72:
F_26 ( V_1 , V_52 , V_53 ,
V_69 , ! V_66 ) ;
V_70:
F_26 ( V_1 , V_52 , V_53 ,
V_68 , ! V_65 ) ;
return V_34 ;
}
static int F_29 ( struct V_1 * V_1 ,
enum V_54 V_55 ,
bool V_56 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
T_1 V_2 , V_73 ;
int V_34 ;
if ( F_17 ( V_1 ) ) {
T_1 V_5 = F_2 ( V_1 ) -> V_5 ;
T_1 V_74 = F_30 ( V_5 ) ;
return F_26 ( V_1 , V_74 ,
V_74 , V_55 , V_56 ) ;
}
F_20 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_34 = F_26 ( V_1 , V_2 , V_2 ,
V_55 , V_56 ) ;
if ( V_34 ) {
V_73 = V_2 ;
goto V_75;
}
}
return 0 ;
V_75:
F_20 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_26 ( V_1 , V_2 , V_2 , V_55 ,
! V_56 ) ;
F_31 ( V_8 , L_1 ) ;
return V_34 ;
}
static int F_32 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
bool V_76 )
{
int V_56 ;
int V_34 = 0 ;
if ( F_25 ( V_50 ) )
return 0 ;
if ( V_1 -> V_77 != V_1 -> V_78 ) {
V_56 = V_76 ?
V_1 -> V_78 : V_1 -> V_77 ;
V_34 = F_29 ( V_1 ,
V_71 ,
V_56 ) ;
}
if ( ! V_34 )
V_1 -> V_76 = V_76 ;
return V_34 ;
}
int F_33 ( struct V_1 * V_9 , T_1 V_5 ,
bool V_56 )
{
bool V_67 = V_56 ;
T_1 V_74 ;
V_74 = F_30 ( V_5 ) ;
if ( V_56 )
V_67 = V_9 -> V_76 ?
V_9 -> V_78 : V_9 -> V_77 ;
return F_28 ( V_9 , V_74 , V_74 , V_56 , V_56 ,
V_67 ) ;
}
static int F_34 ( struct V_1 * V_1 ,
bool V_56 )
{
T_1 V_2 ;
int V_34 ;
if ( F_17 ( V_1 ) ) {
V_2 = F_18 ( V_1 ) ;
return F_35 ( V_1 , V_2 , V_2 ,
V_56 ) ;
}
F_20 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_34 = F_35 ( V_1 , V_2 , V_2 ,
V_56 ) ;
if ( V_34 )
goto V_79;
}
return 0 ;
V_79:
F_20 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_35 ( V_1 , V_2 , V_2 , ! V_56 ) ;
return V_34 ;
}
static int F_36 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
unsigned long V_22 )
{
unsigned long V_23 = V_1 -> V_23 ? V_24 : 0 ;
unsigned long V_27 = V_1 -> V_27 ? V_28 : 0 ;
int V_34 ;
if ( ! V_1 -> V_80 )
return - V_14 ;
if ( F_25 ( V_50 ) )
return 0 ;
if ( ( V_27 ^ V_22 ) & V_28 ) {
V_34 = F_29 ( V_1 ,
V_68 ,
! V_1 -> V_27 ) ;
if ( V_34 )
return V_34 ;
}
if ( ( V_23 ^ V_22 ) & V_24 ) {
V_34 = F_34 ( V_1 ,
! V_1 -> V_23 ) ;
if ( V_34 )
goto V_81;
}
V_1 -> V_27 = V_22 & V_28 ? 1 : 0 ;
V_1 -> V_23 = V_22 & V_24 ? 1 : 0 ;
V_1 -> V_25 = V_22 & V_26 ? 1 : 0 ;
return 0 ;
V_81:
if ( ( V_27 ^ V_22 ) & V_28 )
F_29 ( V_1 ,
V_68 ,
V_1 -> V_27 ) ;
return V_34 ;
}
static int F_37 ( struct V_10 * V_10 , T_3 V_82 )
{
char V_83 [ V_84 ] ;
int V_34 ;
F_38 ( V_83 , V_82 ) ;
V_34 = F_21 ( V_10 -> V_47 , F_22 ( V_85 ) , V_83 ) ;
if ( V_34 )
return V_34 ;
V_10 -> V_82 = V_82 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
unsigned long V_86 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
unsigned long V_87 = F_40 ( V_86 ) ;
T_3 V_82 = F_41 ( V_87 ) / 1000 ;
if ( F_25 ( V_50 ) ) {
if ( V_82 < V_88 ||
V_82 > V_89 )
return - V_90 ;
else
return 0 ;
}
return F_37 ( V_10 , V_82 ) ;
}
static int F_42 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
struct V_7 * V_13 ,
bool V_91 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
if ( ( ! V_91 ) && ( V_10 -> V_92 . V_8 == V_13 ) ) {
F_31 ( V_1 -> V_8 , L_2 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
bool V_93 )
{
if ( F_25 ( V_50 ) )
return 0 ;
V_1 -> V_77 = V_93 ;
if ( ! V_1 -> V_76 )
return F_29 ( V_1 ,
V_71 ,
V_93 ) ;
return 0 ;
}
static int F_44 ( struct V_7 * V_8 ,
const struct V_11 * V_12 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = F_12 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_12 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_12 -> V_15 ) {
case V_94 :
V_34 = F_24 ( V_1 , V_50 ,
V_12 -> V_17 . V_51 ) ;
break;
case V_21 :
V_34 = F_36 ( V_1 , V_50 ,
V_12 -> V_17 . V_22 ) ;
break;
case V_95 :
V_34 = F_39 ( V_1 , V_50 ,
V_12 -> V_17 . V_82 ) ;
break;
case V_96 :
V_34 = F_42 ( V_1 , V_50 ,
V_12 -> V_13 ,
V_12 -> V_17 . V_97 ) ;
break;
case V_98 :
V_34 = F_43 ( V_1 , V_50 ,
V_12 -> V_17 . V_99 ) ;
break;
case V_100 :
V_34 = F_32 ( V_1 , V_50 ,
V_12 -> V_17 . V_76 ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static int F_45 ( struct V_10 * V_10 , T_1 V_5 , bool V_101 )
{
char V_102 [ V_103 ] ;
F_46 ( V_102 , ! V_101 , V_5 , V_5 ) ;
return F_21 ( V_10 -> V_47 , F_22 ( V_104 ) , V_102 ) ;
}
static int F_47 ( struct V_10 * V_10 , T_1 V_5 , bool V_105 )
{
enum V_106 V_107 = V_108 ;
char V_109 [ V_110 ] ;
F_48 ( V_109 , 0 , V_107 , V_105 , V_5 , V_5 ) ;
return F_21 ( V_10 -> V_47 , F_22 ( V_111 ) , V_109 ) ;
}
static struct V_3 * F_49 ( T_1 V_5 )
{
struct V_3 * V_4 ;
V_4 = F_50 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_5 = V_5 ;
return V_4 ;
}
struct V_3 * F_51 ( struct V_10 * V_10 , T_1 V_5 )
{
struct V_3 * V_4 ;
int V_34 ;
V_34 = F_45 ( V_10 , V_5 , true ) ;
if ( V_34 )
return F_52 ( V_34 ) ;
V_34 = F_47 ( V_10 , V_5 , true ) ;
if ( V_34 )
goto V_112;
V_4 = F_49 ( V_5 ) ;
if ( ! V_4 ) {
V_34 = - V_45 ;
goto V_113;
}
F_53 ( & V_4 -> V_114 , & V_10 -> V_115 ) ;
return V_4 ;
V_113:
F_47 ( V_10 , V_5 , false ) ;
V_112:
F_45 ( V_10 , V_5 , false ) ;
return F_52 ( V_34 ) ;
}
void F_54 ( struct V_10 * V_10 , struct V_3 * V_4 )
{
T_1 V_5 = V_4 -> V_5 ;
F_55 ( & V_4 -> V_114 ) ;
if ( V_4 -> V_116 )
F_56 ( V_10 , V_4 -> V_116 ) ;
F_23 ( V_4 ) ;
F_47 ( V_10 , V_5 , false ) ;
F_45 ( V_10 , V_5 , false ) ;
}
static int F_57 ( struct V_1 * V_1 ,
T_1 V_5 )
{
struct V_3 * V_4 ;
if ( F_58 ( V_5 , V_1 -> V_117 ) )
return 0 ;
V_4 = F_59 ( V_1 -> V_10 , V_5 ) ;
if ( ! V_4 ) {
V_4 = F_51 ( V_1 -> V_10 , V_5 ) ;
if ( F_60 ( V_4 ) )
return F_61 ( V_4 ) ;
}
V_4 -> V_118 ++ ;
F_62 ( V_1 -> V_8 , L_3 , V_5 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_1 ,
T_1 V_5 )
{
struct V_3 * V_4 ;
V_4 = F_59 ( V_1 -> V_10 , V_5 ) ;
if ( F_7 ( ! V_4 ) )
return;
F_62 ( V_1 -> V_8 , L_4 , V_5 ) ;
F_64 ( V_1 , V_5 ) ;
if ( -- V_4 -> V_118 == 0 )
F_54 ( V_1 -> V_10 , V_4 ) ;
}
static int F_65 ( struct V_1 * V_1 , T_1 V_5 ,
bool V_105 )
{
enum V_106 V_107 = V_119 ;
if ( F_66 ( & V_1 -> V_120 ) )
return 0 ;
return F_67 ( V_1 , V_107 , V_105 , V_5 , V_5 ) ;
}
static int F_68 ( struct V_1 * V_1 ,
T_1 V_121 , T_1 V_122 )
{
bool V_78 ;
int V_5 , V_34 ;
for ( V_5 = V_121 ; V_5 <= V_122 ; V_5 ++ ) {
V_34 = F_57 ( V_1 , V_5 ) ;
if ( V_34 )
goto V_123;
}
V_78 = V_1 -> V_76 ?
V_1 -> V_78 : V_1 -> V_77 ;
V_34 = F_28 ( V_1 , V_121 , V_122 ,
V_1 -> V_27 , true ,
V_78 ) ;
if ( V_34 )
goto V_75;
for ( V_5 = V_121 ; V_5 <= V_122 ; V_5 ++ ) {
V_34 = F_65 ( V_1 , V_5 , true ) ;
if ( V_34 )
goto V_124;
}
return 0 ;
V_124:
for ( V_5 -- ; V_5 >= V_121 ; V_5 -- )
F_65 ( V_1 , V_5 , false ) ;
F_28 ( V_1 , V_121 , V_122 , false ,
false , false ) ;
V_75:
V_5 = V_122 ;
V_123:
for ( V_5 -- ; V_5 >= V_121 ; V_5 -- )
F_63 ( V_1 , V_5 ) ;
return V_34 ;
}
static void F_69 ( struct V_1 * V_1 ,
T_1 V_121 , T_1 V_122 )
{
int V_5 ;
for ( V_5 = V_121 ; V_5 <= V_122 ; V_5 ++ )
F_65 ( V_1 , V_5 , false ) ;
F_28 ( V_1 , V_121 , V_122 , false ,
false , false ) ;
for ( V_5 = V_121 ; V_5 <= V_122 ; V_5 ++ )
F_63 ( V_1 , V_5 ) ;
}
static int F_70 ( struct V_1 * V_1 ,
T_1 V_2 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
char V_125 [ V_126 ] ;
F_71 ( V_125 , V_1 -> V_46 , V_2 ) ;
return F_21 ( V_10 -> V_47 , F_22 ( V_127 ) , V_125 ) ;
}
static int F_72 ( struct V_1 * V_1 ,
bool V_128 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
char V_129 [ V_130 ] ;
F_73 ( V_129 , V_1 -> V_46 , V_128 ) ;
return F_21 ( V_10 -> V_47 , F_22 ( V_131 ) , V_129 ) ;
}
int F_74 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
int V_34 ;
if ( ! V_2 ) {
V_34 = F_72 ( V_1 , false ) ;
if ( V_34 ) {
F_31 ( V_8 , L_5 ) ;
return V_34 ;
}
} else {
V_34 = F_70 ( V_1 , V_2 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_6 ) ;
return V_34 ;
}
if ( ! V_1 -> V_6 ) {
V_34 = F_72 ( V_1 ,
true ) ;
if ( V_34 ) {
F_31 ( V_8 , L_7 ) ;
goto V_132;
}
}
}
V_1 -> V_6 = V_2 ;
return 0 ;
V_132:
F_70 ( V_1 , V_1 -> V_6 ) ;
return V_34 ;
}
static int F_75 ( struct V_1 * V_1 ,
T_1 V_133 , T_1 V_134 ,
bool V_135 )
{
T_1 V_2 , V_136 ;
int V_34 ;
for ( V_2 = V_133 ; V_2 <= V_134 ;
V_2 += V_137 ) {
V_136 = F_76 ( ( T_1 ) ( V_2 + V_137 - 1 ) ,
V_134 ) ;
V_34 = F_35 ( V_1 , V_2 ,
V_136 , V_135 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_1 ,
T_1 V_133 , T_1 V_134 ,
bool V_138 , bool V_139 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
T_1 V_2 , V_140 ;
int V_34 ;
if ( ! V_1 -> V_80 )
return - V_14 ;
V_34 = F_68 ( V_1 , V_133 , V_134 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_8 ) ;
return V_34 ;
}
V_34 = F_78 ( V_1 , V_133 , V_134 ,
true , V_138 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_9 , V_133 ,
V_134 ) ;
goto V_141;
}
V_140 = V_1 -> V_6 ;
if ( V_139 && V_140 != V_133 ) {
V_34 = F_74 ( V_1 , V_133 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_10 , V_133 ) ;
goto V_142;
}
} else if ( ! V_139 && V_140 >= V_133 && V_140 <= V_134 ) {
V_34 = F_74 ( V_1 , 0 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_11 ) ;
goto V_142;
}
}
V_34 = F_75 ( V_1 , V_133 , V_134 ,
V_1 -> V_23 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_12 ,
V_133 , V_134 ) ;
goto V_79;
}
for ( V_2 = V_133 ; V_2 <= V_134 ; V_2 ++ ) {
F_79 ( V_2 , V_1 -> V_117 ) ;
if ( V_138 )
F_79 ( V_2 , V_1 -> V_143 ) ;
else
F_80 ( V_2 , V_1 -> V_143 ) ;
}
V_34 = F_13 ( V_1 ,
V_1 -> V_51 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_13 ) ;
goto V_144;
}
return 0 ;
V_144:
for ( V_2 = V_133 ; V_2 <= V_134 ; V_2 ++ )
F_80 ( V_2 , V_1 -> V_117 ) ;
F_75 ( V_1 , V_133 , V_134 ,
false ) ;
V_79:
if ( V_140 != V_1 -> V_6 )
F_74 ( V_1 , V_140 ) ;
V_142:
F_78 ( V_1 , V_133 , V_134 ,
false , false ) ;
V_141:
F_69 ( V_1 , V_133 , V_134 ) ;
return V_34 ;
}
static int F_81 ( struct V_1 * V_1 ,
const struct V_145 * V_146 ,
struct V_49 * V_50 )
{
bool V_138 = V_146 -> V_147 & V_148 ;
bool V_139 = V_146 -> V_147 & V_149 ;
if ( F_25 ( V_50 ) )
return 0 ;
return F_77 ( V_1 ,
V_146 -> V_133 , V_146 -> V_134 ,
V_138 , V_139 ) ;
}
static enum V_150 F_82 ( bool V_151 )
{
return V_151 ? V_152 :
V_153 ;
}
static enum V_154 F_83 ( bool V_155 )
{
return V_155 ? V_156 :
V_157 ;
}
static int F_84 ( struct V_10 * V_10 , T_2 V_46 ,
const char * V_158 , T_1 V_5 , bool V_155 ,
enum V_159 V_160 ,
bool V_151 )
{
char * V_161 ;
int V_34 ;
V_161 = F_15 ( V_162 , V_44 ) ;
if ( ! V_161 )
return - V_45 ;
F_85 ( V_161 , F_83 ( V_155 ) , 0 ) ;
F_86 ( V_161 , 0 , F_82 ( V_151 ) ,
V_158 , V_5 , V_160 , V_46 ) ;
V_34 = F_21 ( V_10 -> V_47 , F_22 ( V_163 ) , V_161 ) ;
F_23 ( V_161 ) ;
return V_34 ;
}
static int F_87 ( struct V_10 * V_10 , T_2 V_46 ,
const char * V_158 , T_1 V_5 , bool V_155 ,
bool V_151 )
{
return F_84 ( V_10 , V_46 , V_158 , V_5 , V_155 ,
V_164 , V_151 ) ;
}
int F_88 ( struct V_10 * V_10 , const char * V_158 , T_1 V_5 ,
bool V_155 )
{
return F_84 ( V_10 , 0 , V_158 , V_5 , V_155 ,
V_165 ,
false ) ;
}
static int F_89 ( struct V_10 * V_10 , T_1 V_166 ,
const char * V_158 , T_1 V_5 , T_1 V_167 ,
bool V_155 , bool V_151 )
{
char * V_161 ;
int V_34 ;
V_161 = F_15 ( V_162 , V_44 ) ;
if ( ! V_161 )
return - V_45 ;
F_85 ( V_161 , F_83 ( V_155 ) , 0 ) ;
F_90 ( V_161 , 0 , F_82 ( V_151 ) ,
V_158 , V_5 , V_164 ,
V_167 , V_166 ) ;
V_34 = F_21 ( V_10 -> V_47 , F_22 ( V_163 ) , V_161 ) ;
F_23 ( V_161 ) ;
return V_34 ;
}
static int
F_91 ( struct V_1 * V_1 ,
const struct V_168 * V_169 ,
struct V_49 * V_50 )
{
T_1 V_5 = F_1 ( V_1 , V_169 -> V_2 ) ;
T_1 V_167 = 0 ;
if ( F_25 ( V_50 ) )
return 0 ;
if ( F_17 ( V_1 ) ) {
V_167 = F_18 ( V_1 ) ;
}
if ( ! V_1 -> V_170 )
return F_87 ( V_1 -> V_10 ,
V_1 -> V_46 ,
V_169 -> V_171 , V_5 , true , false ) ;
else
return F_89 ( V_1 -> V_10 ,
V_1 -> V_166 ,
V_169 -> V_171 , V_5 , V_167 ,
true , false ) ;
}
static int F_92 ( struct V_10 * V_10 , const char * V_171 ,
T_1 V_5 , T_1 V_172 , bool V_155 )
{
char * V_161 ;
int V_34 ;
V_161 = F_15 ( V_162 , V_44 ) ;
if ( ! V_161 )
return - V_45 ;
F_85 ( V_161 , F_83 ( V_155 ) , 0 ) ;
F_93 ( V_161 , 0 , V_171 , V_5 ,
V_164 , V_172 ) ;
V_34 = F_21 ( V_10 -> V_47 , F_22 ( V_163 ) , V_161 ) ;
F_23 ( V_161 ) ;
return V_34 ;
}
static int F_94 ( struct V_1 * V_1 , T_1 V_172 ,
bool V_173 , bool V_174 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
char * V_175 ;
int V_34 , V_176 ;
V_175 = F_15 ( V_177 , V_44 ) ;
if ( ! V_175 )
return - V_45 ;
F_95 ( V_175 , V_172 , V_1 -> V_46 , V_173 ) ;
if ( V_174 ) {
for ( V_176 = 1 ; V_176 < F_96 ( V_10 -> V_47 ) ; V_176 ++ )
if ( V_10 -> V_178 [ V_176 ] )
F_97 ( V_175 , V_176 , 1 ) ;
}
V_34 = F_21 ( V_10 -> V_47 , F_22 ( V_179 ) , V_175 ) ;
F_23 ( V_175 ) ;
return V_34 ;
}
static struct V_180 * F_98 ( struct V_10 * V_10 ,
const unsigned char * V_171 ,
T_1 V_5 )
{
struct V_180 * V_172 ;
F_99 (mid, &mlxsw_sp->br_mids.list, list) {
if ( F_100 ( V_172 -> V_171 , V_171 ) && V_172 -> V_5 == V_5 )
return V_172 ;
}
return NULL ;
}
static struct V_180 * F_101 ( struct V_10 * V_10 ,
const unsigned char * V_171 ,
T_1 V_5 )
{
struct V_180 * V_172 ;
T_1 V_181 ;
V_181 = F_102 ( V_10 -> V_182 . V_183 ,
V_184 ) ;
if ( V_181 == V_184 )
return NULL ;
V_172 = F_50 ( sizeof( * V_172 ) , V_44 ) ;
if ( ! V_172 )
return NULL ;
F_79 ( V_181 , V_10 -> V_182 . V_183 ) ;
F_103 ( V_172 -> V_171 , V_171 ) ;
V_172 -> V_5 = V_5 ;
V_172 -> V_172 = V_181 ;
V_172 -> V_118 = 0 ;
F_104 ( & V_172 -> V_114 , & V_10 -> V_182 . V_114 ) ;
return V_172 ;
}
static int F_105 ( struct V_10 * V_10 ,
struct V_180 * V_172 )
{
if ( -- V_172 -> V_118 == 0 ) {
F_55 ( & V_172 -> V_114 ) ;
F_80 ( V_172 -> V_172 , V_10 -> V_182 . V_183 ) ;
F_23 ( V_172 ) ;
return 1 ;
}
return 0 ;
}
static int F_106 ( struct V_1 * V_1 ,
const struct V_185 * V_186 ,
struct V_49 * V_50 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_180 * V_172 ;
T_1 V_5 = F_1 ( V_1 , V_186 -> V_2 ) ;
int V_34 = 0 ;
if ( F_25 ( V_50 ) )
return 0 ;
V_172 = F_98 ( V_10 , V_186 -> V_171 , V_5 ) ;
if ( ! V_172 ) {
V_172 = F_101 ( V_10 , V_186 -> V_171 , V_5 ) ;
if ( ! V_172 ) {
F_31 ( V_8 , L_14 ) ;
return - V_45 ;
}
}
V_172 -> V_118 ++ ;
V_34 = F_94 ( V_1 , V_172 -> V_172 , true ,
V_172 -> V_118 == 1 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_15 ) ;
goto V_187;
}
if ( V_172 -> V_118 == 1 ) {
V_34 = F_92 ( V_10 , V_186 -> V_171 , V_5 , V_172 -> V_172 ,
true ) ;
if ( V_34 ) {
F_31 ( V_8 , L_16 ) ;
goto V_187;
}
}
return 0 ;
V_187:
F_105 ( V_10 , V_172 ) ;
return V_34 ;
}
static int F_107 ( struct V_7 * V_8 ,
const struct V_188 * V_189 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = F_12 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_189 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_189 -> V_15 ) {
case V_190 :
if ( F_17 ( V_1 ) )
return 0 ;
V_34 = F_81 ( V_1 ,
F_108 ( V_189 ) ,
V_50 ) ;
break;
case V_191 :
V_34 = F_91 ( V_1 ,
F_109 ( V_189 ) ,
V_50 ) ;
break;
case V_192 :
V_34 = F_106 ( V_1 ,
F_110 ( V_189 ) ,
V_50 ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static int F_111 ( struct V_1 * V_1 ,
T_1 V_133 , T_1 V_134 )
{
T_1 V_2 , V_6 ;
if ( ! V_1 -> V_80 )
return - V_14 ;
F_75 ( V_1 , V_133 , V_134 ,
false ) ;
V_6 = V_1 -> V_6 ;
if ( V_6 >= V_133 && V_6 <= V_134 )
F_74 ( V_1 , 0 ) ;
F_78 ( V_1 , V_133 , V_134 ,
false , false ) ;
F_69 ( V_1 , V_133 , V_134 ) ;
for ( V_2 = V_133 ; V_2 <= V_134 ; V_2 ++ )
F_80 ( V_2 , V_1 -> V_117 ) ;
return 0 ;
}
static int F_112 ( struct V_1 * V_1 ,
const struct V_145 * V_146 )
{
return F_111 ( V_1 , V_146 -> V_133 ,
V_146 -> V_134 ) ;
}
void F_113 ( struct V_1 * V_1 )
{
T_1 V_2 ;
F_20 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_111 ( V_1 , V_2 , V_2 ) ;
}
static int
F_114 ( struct V_1 * V_1 ,
const struct V_168 * V_169 )
{
T_1 V_5 = F_1 ( V_1 , V_169 -> V_2 ) ;
T_1 V_167 = 0 ;
if ( F_17 ( V_1 ) ) {
V_167 = F_18 ( V_1 ) ;
}
if ( ! V_1 -> V_170 )
return F_87 ( V_1 -> V_10 ,
V_1 -> V_46 ,
V_169 -> V_171 , V_5 ,
false , false ) ;
else
return F_89 ( V_1 -> V_10 ,
V_1 -> V_166 ,
V_169 -> V_171 , V_5 , V_167 ,
false , false ) ;
}
static int F_115 ( struct V_1 * V_1 ,
const struct V_185 * V_186 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_180 * V_172 ;
T_1 V_5 = F_1 ( V_1 , V_186 -> V_2 ) ;
T_1 V_181 ;
int V_34 = 0 ;
V_172 = F_98 ( V_10 , V_186 -> V_171 , V_5 ) ;
if ( ! V_172 ) {
F_31 ( V_8 , L_17 ) ;
return - V_14 ;
}
V_34 = F_94 ( V_1 , V_172 -> V_172 , false , false ) ;
if ( V_34 )
F_31 ( V_8 , L_18 ) ;
V_181 = V_172 -> V_172 ;
if ( F_105 ( V_10 , V_172 ) ) {
V_34 = F_92 ( V_10 , V_186 -> V_171 , V_5 , V_181 ,
false ) ;
if ( V_34 )
F_31 ( V_8 , L_19 ) ;
}
return V_34 ;
}
static int F_116 ( struct V_7 * V_8 ,
const struct V_188 * V_189 )
{
struct V_1 * V_1 = F_12 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_189 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_189 -> V_15 ) {
case V_190 :
if ( F_17 ( V_1 ) )
return 0 ;
V_34 = F_112 ( V_1 ,
F_108 ( V_189 ) ) ;
break;
case V_191 :
V_34 = F_114 ( V_1 ,
F_109 ( V_189 ) ) ;
break;
case V_192 :
V_34 = F_115 ( V_1 ,
F_110 ( V_189 ) ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static struct V_1 * F_117 ( struct V_10 * V_10 ,
T_1 V_166 )
{
struct V_1 * V_1 ;
T_4 V_193 ;
int V_176 ;
V_193 = F_118 ( V_10 -> V_47 ,
V_194 ) ;
for ( V_176 = 0 ; V_176 < V_193 ; V_176 ++ ) {
V_1 = F_119 ( V_10 , V_166 , V_176 ) ;
if ( V_1 )
return V_1 ;
}
return NULL ;
}
static int F_120 ( struct V_1 * V_1 ,
struct V_168 * V_169 ,
T_5 * V_195 ,
struct V_7 * V_13 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
struct V_1 * V_196 ;
struct V_3 * V_4 ;
T_1 V_197 ;
char * V_161 ;
char V_158 [ V_198 ] ;
T_1 V_5 ;
T_2 V_46 ;
T_1 V_166 ;
T_2 V_199 ;
int V_200 = 0 ;
int V_176 ;
int V_34 ;
V_161 = F_15 ( V_162 , V_44 ) ;
if ( ! V_161 )
return - V_45 ;
V_4 = F_2 ( V_1 ) ;
V_197 = V_4 ? V_4 -> V_5 : 0 ;
F_85 ( V_161 , V_201 , 0 ) ;
do {
F_121 ( V_161 , V_202 ) ;
V_34 = F_122 ( V_10 -> V_47 , F_22 ( V_163 ) , V_161 ) ;
if ( V_34 )
goto V_203;
V_199 = F_123 ( V_161 ) ;
if ( V_200 )
continue;
for ( V_176 = 0 ; V_176 < V_199 ; V_176 ++ ) {
switch ( F_124 ( V_161 , V_176 ) ) {
case V_204 :
F_125 ( V_161 , V_176 , V_158 , & V_5 ,
& V_46 ) ;
if ( V_46 == V_1 -> V_46 ) {
if ( V_197 && V_197 == V_5 )
V_169 -> V_2 = 0 ;
else if ( ! V_197 &&
! F_126 ( V_5 ) )
V_169 -> V_2 = V_5 ;
else
continue;
F_103 ( V_169 -> V_171 , V_158 ) ;
V_169 -> V_205 = V_206 ;
V_34 = V_195 ( & V_169 -> V_189 ) ;
if ( V_34 )
V_200 = V_34 ;
}
break;
case V_207 :
F_127 ( V_161 , V_176 ,
V_158 , & V_5 , & V_166 ) ;
V_196 = F_117 ( V_10 , V_166 ) ;
if ( V_196 && V_196 -> V_46 ==
V_1 -> V_46 ) {
if ( ! F_128 ( V_13 ) &&
! F_8 ( V_13 ) )
continue;
if ( V_197 && V_197 == V_5 )
V_169 -> V_2 = 0 ;
else if ( ! V_197 &&
! F_126 ( V_5 ) )
V_169 -> V_2 = V_5 ;
else
continue;
F_103 ( V_169 -> V_171 , V_158 ) ;
V_169 -> V_205 = V_206 ;
V_34 = V_195 ( & V_169 -> V_189 ) ;
if ( V_34 )
V_200 = V_34 ;
}
break;
}
}
} while ( V_199 == V_202 );
V_203:
F_23 ( V_161 ) ;
return V_200 ? V_200 : V_34 ;
}
static int F_129 ( struct V_1 * V_1 ,
struct V_145 * V_146 ,
T_5 * V_195 )
{
T_1 V_2 ;
int V_34 = 0 ;
if ( F_17 ( V_1 ) ) {
V_146 -> V_147 = 0 ;
V_146 -> V_133 = F_18 ( V_1 ) ;
V_146 -> V_134 = F_18 ( V_1 ) ;
return V_195 ( & V_146 -> V_189 ) ;
}
F_20 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_146 -> V_147 = 0 ;
if ( V_2 == V_1 -> V_6 )
V_146 -> V_147 |= V_149 ;
if ( F_58 ( V_2 , V_1 -> V_143 ) )
V_146 -> V_147 |= V_148 ;
V_146 -> V_133 = V_2 ;
V_146 -> V_134 = V_2 ;
V_34 = V_195 ( & V_146 -> V_189 ) ;
if ( V_34 )
break;
}
return V_34 ;
}
static int F_130 ( struct V_7 * V_8 ,
struct V_188 * V_189 ,
T_5 * V_195 )
{
struct V_1 * V_1 = F_12 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_189 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_189 -> V_15 ) {
case V_190 :
V_34 = F_129 ( V_1 ,
F_108 ( V_189 ) , V_195 ) ;
break;
case V_191 :
V_34 = F_120 ( V_1 ,
F_109 ( V_189 ) , V_195 ,
V_189 -> V_13 ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static void F_131 ( bool V_25 , bool V_155 ,
char * V_158 , T_1 V_2 ,
struct V_7 * V_8 )
{
struct V_208 V_209 ;
unsigned long V_210 ;
if ( V_25 ) {
V_209 . V_171 = V_158 ;
V_209 . V_2 = V_2 ;
V_210 = V_155 ? V_211 : V_212 ;
F_132 ( V_210 , V_8 , & V_209 . V_209 ) ;
}
}
static void F_133 ( struct V_10 * V_10 ,
char * V_213 , int V_214 ,
bool V_155 )
{
struct V_1 * V_1 ;
char V_158 [ V_198 ] ;
T_2 V_46 ;
T_1 V_2 , V_5 ;
bool V_215 = true ;
int V_34 ;
F_134 ( V_213 , V_214 , V_158 , & V_5 , & V_46 ) ;
V_1 = V_10 -> V_178 [ V_46 ] ;
if ( ! V_1 ) {
F_135 ( V_10 -> V_216 -> V_8 , L_20 ) ;
goto V_217;
}
if ( F_126 ( V_5 ) ) {
struct V_1 * V_9 ;
V_9 = F_6 ( V_1 ,
V_5 ) ;
if ( ! V_9 ) {
F_31 ( V_1 -> V_8 , L_21 ) ;
goto V_217;
}
V_2 = 0 ;
V_1 = V_9 ;
} else {
V_2 = V_5 ;
}
V_218:
V_34 = F_87 ( V_10 , V_46 , V_158 , V_5 ,
V_155 , true ) ;
if ( V_34 ) {
F_135 ( V_10 -> V_216 -> V_8 , L_22 ) ;
return;
}
if ( ! V_215 )
return;
F_131 ( V_1 -> V_25 ,
V_155 , V_158 , V_2 , V_1 -> V_8 ) ;
return;
V_217:
V_155 = false ;
V_215 = false ;
goto V_218;
}
static void F_136 ( struct V_10 * V_10 ,
char * V_213 , int V_214 ,
bool V_155 )
{
struct V_1 * V_1 ;
struct V_7 * V_8 ;
char V_158 [ V_198 ] ;
T_1 V_167 = 0 ;
T_1 V_166 ;
T_1 V_2 , V_5 ;
bool V_215 = true ;
int V_34 ;
F_137 ( V_213 , V_214 , V_158 , & V_5 , & V_166 ) ;
V_1 = F_117 ( V_10 , V_166 ) ;
if ( ! V_1 ) {
F_135 ( V_10 -> V_216 -> V_8 , L_23 ) ;
goto V_217;
}
if ( F_126 ( V_5 ) ) {
struct V_1 * V_9 ;
V_9 = F_6 ( V_1 ,
V_5 ) ;
if ( ! V_9 ) {
F_31 ( V_1 -> V_8 , L_21 ) ;
goto V_217;
}
V_167 = F_18 ( V_9 ) ;
V_8 = V_9 -> V_8 ;
V_2 = 0 ;
V_1 = V_9 ;
} else {
V_8 = F_138 ( V_10 , V_166 ) -> V_8 ;
V_2 = V_5 ;
}
V_218:
V_34 = F_89 ( V_10 , V_166 , V_158 , V_5 , V_167 ,
V_155 , true ) ;
if ( V_34 ) {
F_135 ( V_10 -> V_216 -> V_8 , L_22 ) ;
return;
}
if ( ! V_215 )
return;
F_131 ( V_1 -> V_25 , V_155 , V_158 ,
V_2 , V_8 ) ;
return;
V_217:
V_155 = false ;
V_215 = false ;
goto V_218;
}
static void F_139 ( struct V_10 * V_10 ,
char * V_213 , int V_214 )
{
switch ( F_140 ( V_213 , V_214 ) ) {
case V_219 :
F_133 ( V_10 , V_213 ,
V_214 , true ) ;
break;
case V_220 :
F_133 ( V_10 , V_213 ,
V_214 , false ) ;
break;
case V_221 :
F_136 ( V_10 , V_213 ,
V_214 , true ) ;
break;
case V_222 :
F_136 ( V_10 , V_213 ,
V_214 , false ) ;
break;
}
}
static void F_141 ( struct V_10 * V_10 )
{
F_142 ( & V_10 -> V_223 . V_224 ,
F_143 ( V_10 -> V_223 . V_225 ) ) ;
}
static void F_144 ( struct V_226 * V_227 )
{
struct V_10 * V_10 ;
char * V_213 ;
T_2 V_199 ;
int V_176 ;
int V_34 ;
V_213 = F_15 ( V_228 , V_44 ) ;
if ( ! V_213 )
return;
V_10 = F_145 ( V_227 , struct V_10 , V_223 . V_224 . V_227 ) ;
F_146 () ;
F_147 ( V_213 ) ;
V_34 = F_122 ( V_10 -> V_47 , F_22 ( V_229 ) , V_213 ) ;
if ( V_34 ) {
F_135 ( V_10 -> V_216 -> V_8 , L_24 ) ;
goto V_203;
}
V_199 = F_148 ( V_213 ) ;
for ( V_176 = 0 ; V_176 < V_199 ; V_176 ++ )
F_139 ( V_10 , V_213 , V_176 ) ;
V_203:
F_149 () ;
F_23 ( V_213 ) ;
F_141 ( V_10 ) ;
}
static int F_150 ( struct V_10 * V_10 )
{
int V_34 ;
V_34 = F_37 ( V_10 , V_230 ) ;
if ( V_34 ) {
F_151 ( V_10 -> V_216 -> V_8 , L_25 ) ;
return V_34 ;
}
F_152 ( & V_10 -> V_223 . V_224 , F_144 ) ;
V_10 -> V_223 . V_225 = V_231 ;
F_141 ( V_10 ) ;
return 0 ;
}
static void F_153 ( struct V_10 * V_10 )
{
F_154 ( & V_10 -> V_223 . V_224 ) ;
}
int F_155 ( struct V_10 * V_10 )
{
return F_150 ( V_10 ) ;
}
void F_156 ( struct V_10 * V_10 )
{
F_153 ( V_10 ) ;
}
void F_157 ( struct V_1 * V_1 )
{
V_1 -> V_8 -> V_232 = & V_233 ;
}
void F_158 ( struct V_1 * V_1 )
{
}
