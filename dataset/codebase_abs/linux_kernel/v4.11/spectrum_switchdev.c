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
T_1 V_133 , T_1 V_134 , bool V_135 ,
bool V_136 )
{
T_1 V_2 , V_137 ;
int V_34 ;
for ( V_2 = V_133 ; V_2 <= V_134 ;
V_2 += V_138 ) {
V_137 = F_76 ( ( T_1 ) ( V_2 + V_138 - 1 ) ,
V_134 ) ;
V_34 = F_77 ( V_1 , V_2 , V_137 ,
V_135 , V_136 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_1 ,
T_1 V_133 , T_1 V_134 ,
bool V_139 )
{
T_1 V_2 , V_137 ;
int V_34 ;
for ( V_2 = V_133 ; V_2 <= V_134 ;
V_2 += V_140 ) {
V_137 = F_76 ( ( T_1 ) ( V_2 + V_140 - 1 ) ,
V_134 ) ;
V_34 = F_35 ( V_1 , V_2 ,
V_137 , V_139 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_1 ,
T_1 V_133 , T_1 V_134 ,
bool V_141 , bool V_142 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
T_1 V_2 , V_143 ;
int V_34 ;
if ( ! V_1 -> V_80 )
return - V_14 ;
V_34 = F_68 ( V_1 , V_133 , V_134 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_8 ) ;
return V_34 ;
}
V_34 = F_75 ( V_1 , V_133 , V_134 ,
true , V_141 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_9 , V_133 ,
V_134 ) ;
goto V_144;
}
V_143 = V_1 -> V_6 ;
if ( V_142 && V_143 != V_133 ) {
V_34 = F_74 ( V_1 , V_133 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_10 , V_133 ) ;
goto V_145;
}
} else if ( ! V_142 && V_143 >= V_133 && V_143 <= V_134 ) {
V_34 = F_74 ( V_1 , 0 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_11 ) ;
goto V_145;
}
}
V_34 = F_78 ( V_1 , V_133 , V_134 ,
V_1 -> V_23 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_12 ,
V_133 , V_134 ) ;
goto V_79;
}
for ( V_2 = V_133 ; V_2 <= V_134 ; V_2 ++ ) {
F_80 ( V_2 , V_1 -> V_117 ) ;
if ( V_141 )
F_80 ( V_2 , V_1 -> V_146 ) ;
else
F_81 ( V_2 , V_1 -> V_146 ) ;
}
V_34 = F_13 ( V_1 ,
V_1 -> V_51 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_13 ) ;
goto V_147;
}
return 0 ;
V_147:
for ( V_2 = V_133 ; V_2 <= V_134 ; V_2 ++ )
F_81 ( V_2 , V_1 -> V_117 ) ;
F_78 ( V_1 , V_133 , V_134 ,
false ) ;
V_79:
if ( V_143 != V_1 -> V_6 )
F_74 ( V_1 , V_143 ) ;
V_145:
F_75 ( V_1 , V_133 , V_134 , false ,
false ) ;
V_144:
F_69 ( V_1 , V_133 , V_134 ) ;
return V_34 ;
}
static int F_82 ( struct V_1 * V_1 ,
const struct V_148 * V_149 ,
struct V_49 * V_50 )
{
bool V_141 = V_149 -> V_150 & V_151 ;
bool V_142 = V_149 -> V_150 & V_152 ;
if ( F_25 ( V_50 ) )
return 0 ;
return F_79 ( V_1 ,
V_149 -> V_133 , V_149 -> V_134 ,
V_141 , V_142 ) ;
}
static enum V_153 F_83 ( bool V_154 )
{
return V_154 ? V_155 :
V_156 ;
}
static enum V_157 F_84 ( bool V_158 )
{
return V_158 ? V_159 :
V_160 ;
}
static int F_85 ( struct V_10 * V_10 , T_2 V_46 ,
const char * V_161 , T_1 V_5 , bool V_158 ,
enum V_162 V_163 ,
bool V_154 )
{
char * V_164 ;
int V_34 ;
V_164 = F_15 ( V_165 , V_44 ) ;
if ( ! V_164 )
return - V_45 ;
F_86 ( V_164 , F_84 ( V_158 ) , 0 ) ;
F_87 ( V_164 , 0 , F_83 ( V_154 ) ,
V_161 , V_5 , V_163 , V_46 ) ;
V_34 = F_21 ( V_10 -> V_47 , F_22 ( V_166 ) , V_164 ) ;
F_23 ( V_164 ) ;
return V_34 ;
}
static int F_88 ( struct V_10 * V_10 , T_2 V_46 ,
const char * V_161 , T_1 V_5 , bool V_158 ,
bool V_154 )
{
return F_85 ( V_10 , V_46 , V_161 , V_5 , V_158 ,
V_167 , V_154 ) ;
}
int F_89 ( struct V_10 * V_10 , const char * V_161 , T_1 V_5 ,
bool V_158 )
{
return F_85 ( V_10 , 0 , V_161 , V_5 , V_158 ,
V_168 ,
false ) ;
}
static int F_90 ( struct V_10 * V_10 , T_1 V_169 ,
const char * V_161 , T_1 V_5 , T_1 V_170 ,
bool V_158 , bool V_154 )
{
char * V_164 ;
int V_34 ;
V_164 = F_15 ( V_165 , V_44 ) ;
if ( ! V_164 )
return - V_45 ;
F_86 ( V_164 , F_84 ( V_158 ) , 0 ) ;
F_91 ( V_164 , 0 , F_83 ( V_154 ) ,
V_161 , V_5 , V_167 ,
V_170 , V_169 ) ;
V_34 = F_21 ( V_10 -> V_47 , F_22 ( V_166 ) , V_164 ) ;
F_23 ( V_164 ) ;
return V_34 ;
}
static int
F_92 ( struct V_1 * V_1 ,
const struct V_171 * V_172 ,
struct V_49 * V_50 )
{
T_1 V_5 = F_1 ( V_1 , V_172 -> V_2 ) ;
T_1 V_170 = 0 ;
if ( F_25 ( V_50 ) )
return 0 ;
if ( F_17 ( V_1 ) ) {
V_170 = F_18 ( V_1 ) ;
}
if ( ! V_1 -> V_173 )
return F_88 ( V_1 -> V_10 ,
V_1 -> V_46 ,
V_172 -> V_174 , V_5 , true , false ) ;
else
return F_90 ( V_1 -> V_10 ,
V_1 -> V_169 ,
V_172 -> V_174 , V_5 , V_170 ,
true , false ) ;
}
static int F_93 ( struct V_10 * V_10 , const char * V_174 ,
T_1 V_5 , T_1 V_175 , bool V_158 )
{
char * V_164 ;
int V_34 ;
V_164 = F_15 ( V_165 , V_44 ) ;
if ( ! V_164 )
return - V_45 ;
F_86 ( V_164 , F_84 ( V_158 ) , 0 ) ;
F_94 ( V_164 , 0 , V_174 , V_5 ,
V_167 , V_175 ) ;
V_34 = F_21 ( V_10 -> V_47 , F_22 ( V_166 ) , V_164 ) ;
F_23 ( V_164 ) ;
return V_34 ;
}
static int F_95 ( struct V_1 * V_1 , T_1 V_175 ,
bool V_176 , bool V_177 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
char * V_178 ;
int V_34 , V_179 ;
V_178 = F_15 ( V_180 , V_44 ) ;
if ( ! V_178 )
return - V_45 ;
F_96 ( V_178 , V_175 , V_1 -> V_46 , V_176 ) ;
if ( V_177 ) {
for ( V_179 = 1 ; V_179 < V_181 ; V_179 ++ )
if ( V_10 -> V_182 [ V_179 ] )
F_97 ( V_178 , V_179 , 1 ) ;
}
V_34 = F_21 ( V_10 -> V_47 , F_22 ( V_183 ) , V_178 ) ;
F_23 ( V_178 ) ;
return V_34 ;
}
static struct V_184 * F_98 ( struct V_10 * V_10 ,
const unsigned char * V_174 ,
T_1 V_5 )
{
struct V_184 * V_175 ;
F_99 (mid, &mlxsw_sp->br_mids.list, list) {
if ( F_100 ( V_175 -> V_174 , V_174 ) && V_175 -> V_5 == V_5 )
return V_175 ;
}
return NULL ;
}
static struct V_184 * F_101 ( struct V_10 * V_10 ,
const unsigned char * V_174 ,
T_1 V_5 )
{
struct V_184 * V_175 ;
T_1 V_185 ;
V_185 = F_102 ( V_10 -> V_186 . V_187 ,
V_188 ) ;
if ( V_185 == V_188 )
return NULL ;
V_175 = F_50 ( sizeof( * V_175 ) , V_44 ) ;
if ( ! V_175 )
return NULL ;
F_80 ( V_185 , V_10 -> V_186 . V_187 ) ;
F_103 ( V_175 -> V_174 , V_174 ) ;
V_175 -> V_5 = V_5 ;
V_175 -> V_175 = V_185 ;
V_175 -> V_118 = 0 ;
F_104 ( & V_175 -> V_114 , & V_10 -> V_186 . V_114 ) ;
return V_175 ;
}
static int F_105 ( struct V_10 * V_10 ,
struct V_184 * V_175 )
{
if ( -- V_175 -> V_118 == 0 ) {
F_55 ( & V_175 -> V_114 ) ;
F_81 ( V_175 -> V_175 , V_10 -> V_186 . V_187 ) ;
F_23 ( V_175 ) ;
return 1 ;
}
return 0 ;
}
static int F_106 ( struct V_1 * V_1 ,
const struct V_189 * V_190 ,
struct V_49 * V_50 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_184 * V_175 ;
T_1 V_5 = F_1 ( V_1 , V_190 -> V_2 ) ;
int V_34 = 0 ;
if ( F_25 ( V_50 ) )
return 0 ;
V_175 = F_98 ( V_10 , V_190 -> V_174 , V_5 ) ;
if ( ! V_175 ) {
V_175 = F_101 ( V_10 , V_190 -> V_174 , V_5 ) ;
if ( ! V_175 ) {
F_31 ( V_8 , L_14 ) ;
return - V_45 ;
}
}
V_175 -> V_118 ++ ;
V_34 = F_95 ( V_1 , V_175 -> V_175 , true ,
V_175 -> V_118 == 1 ) ;
if ( V_34 ) {
F_31 ( V_8 , L_15 ) ;
goto V_191;
}
if ( V_175 -> V_118 == 1 ) {
V_34 = F_93 ( V_10 , V_190 -> V_174 , V_5 , V_175 -> V_175 ,
true ) ;
if ( V_34 ) {
F_31 ( V_8 , L_16 ) ;
goto V_191;
}
}
return 0 ;
V_191:
F_105 ( V_10 , V_175 ) ;
return V_34 ;
}
static int F_107 ( struct V_7 * V_8 ,
const struct V_192 * V_193 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = F_12 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_193 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_193 -> V_15 ) {
case V_194 :
if ( F_17 ( V_1 ) )
return 0 ;
V_34 = F_82 ( V_1 ,
F_108 ( V_193 ) ,
V_50 ) ;
break;
case V_195 :
V_34 = F_92 ( V_1 ,
F_109 ( V_193 ) ,
V_50 ) ;
break;
case V_196 :
V_34 = F_106 ( V_1 ,
F_110 ( V_193 ) ,
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
F_78 ( V_1 , V_133 , V_134 ,
false ) ;
V_6 = V_1 -> V_6 ;
if ( V_6 >= V_133 && V_6 <= V_134 )
F_74 ( V_1 , 0 ) ;
F_75 ( V_1 , V_133 , V_134 , false ,
false ) ;
F_69 ( V_1 , V_133 , V_134 ) ;
for ( V_2 = V_133 ; V_2 <= V_134 ; V_2 ++ )
F_81 ( V_2 , V_1 -> V_117 ) ;
return 0 ;
}
static int F_112 ( struct V_1 * V_1 ,
const struct V_148 * V_149 )
{
return F_111 ( V_1 , V_149 -> V_133 ,
V_149 -> V_134 ) ;
}
void F_113 ( struct V_1 * V_1 )
{
T_1 V_2 ;
F_20 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_111 ( V_1 , V_2 , V_2 ) ;
}
static int
F_114 ( struct V_1 * V_1 ,
const struct V_171 * V_172 )
{
T_1 V_5 = F_1 ( V_1 , V_172 -> V_2 ) ;
T_1 V_170 = 0 ;
if ( F_17 ( V_1 ) ) {
V_170 = F_18 ( V_1 ) ;
}
if ( ! V_1 -> V_173 )
return F_88 ( V_1 -> V_10 ,
V_1 -> V_46 ,
V_172 -> V_174 , V_5 ,
false , false ) ;
else
return F_90 ( V_1 -> V_10 ,
V_1 -> V_169 ,
V_172 -> V_174 , V_5 , V_170 ,
false , false ) ;
}
static int F_115 ( struct V_1 * V_1 ,
const struct V_189 * V_190 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_184 * V_175 ;
T_1 V_5 = F_1 ( V_1 , V_190 -> V_2 ) ;
T_1 V_185 ;
int V_34 = 0 ;
V_175 = F_98 ( V_10 , V_190 -> V_174 , V_5 ) ;
if ( ! V_175 ) {
F_31 ( V_8 , L_17 ) ;
return - V_14 ;
}
V_34 = F_95 ( V_1 , V_175 -> V_175 , false , false ) ;
if ( V_34 )
F_31 ( V_8 , L_18 ) ;
V_185 = V_175 -> V_175 ;
if ( F_105 ( V_10 , V_175 ) ) {
V_34 = F_93 ( V_10 , V_190 -> V_174 , V_5 , V_185 ,
false ) ;
if ( V_34 )
F_31 ( V_8 , L_19 ) ;
}
return V_34 ;
}
static int F_116 ( struct V_7 * V_8 ,
const struct V_192 * V_193 )
{
struct V_1 * V_1 = F_12 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_193 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_193 -> V_15 ) {
case V_194 :
if ( F_17 ( V_1 ) )
return 0 ;
V_34 = F_112 ( V_1 ,
F_108 ( V_193 ) ) ;
break;
case V_195 :
V_34 = F_114 ( V_1 ,
F_109 ( V_193 ) ) ;
break;
case V_196 :
V_34 = F_115 ( V_1 ,
F_110 ( V_193 ) ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static struct V_1 * F_117 ( struct V_10 * V_10 ,
T_1 V_169 )
{
struct V_1 * V_1 ;
T_4 V_197 ;
int V_179 ;
V_197 = F_118 ( V_10 -> V_47 ,
V_198 ) ;
for ( V_179 = 0 ; V_179 < V_197 ; V_179 ++ ) {
V_1 = F_119 ( V_10 , V_169 , V_179 ) ;
if ( V_1 )
return V_1 ;
}
return NULL ;
}
static int F_120 ( struct V_1 * V_1 ,
struct V_171 * V_172 ,
T_5 * V_199 ,
struct V_7 * V_13 )
{
struct V_10 * V_10 = V_1 -> V_10 ;
struct V_1 * V_200 ;
struct V_3 * V_4 ;
T_1 V_201 ;
char * V_164 ;
char V_161 [ V_202 ] ;
T_1 V_5 ;
T_2 V_46 ;
T_1 V_169 ;
T_2 V_203 ;
int V_204 = 0 ;
int V_179 ;
int V_34 ;
V_164 = F_15 ( V_165 , V_44 ) ;
if ( ! V_164 )
return - V_45 ;
V_4 = F_2 ( V_1 ) ;
V_201 = V_4 ? V_4 -> V_5 : 0 ;
F_86 ( V_164 , V_205 , 0 ) ;
do {
F_121 ( V_164 , V_206 ) ;
V_34 = F_122 ( V_10 -> V_47 , F_22 ( V_166 ) , V_164 ) ;
if ( V_34 )
goto V_207;
V_203 = F_123 ( V_164 ) ;
if ( V_204 )
continue;
for ( V_179 = 0 ; V_179 < V_203 ; V_179 ++ ) {
switch ( F_124 ( V_164 , V_179 ) ) {
case V_208 :
F_125 ( V_164 , V_179 , V_161 , & V_5 ,
& V_46 ) ;
if ( V_46 == V_1 -> V_46 ) {
if ( V_201 && V_201 == V_5 )
V_172 -> V_2 = 0 ;
else if ( ! V_201 &&
! F_126 ( V_5 ) )
V_172 -> V_2 = V_5 ;
else
continue;
F_103 ( V_172 -> V_174 , V_161 ) ;
V_172 -> V_209 = V_210 ;
V_34 = V_199 ( & V_172 -> V_193 ) ;
if ( V_34 )
V_204 = V_34 ;
}
break;
case V_211 :
F_127 ( V_164 , V_179 ,
V_161 , & V_5 , & V_169 ) ;
V_200 = F_117 ( V_10 , V_169 ) ;
if ( V_200 && V_200 -> V_46 ==
V_1 -> V_46 ) {
if ( ! F_128 ( V_13 ) &&
! F_8 ( V_13 ) )
continue;
if ( V_201 && V_201 == V_5 )
V_172 -> V_2 = 0 ;
else if ( ! V_201 &&
! F_126 ( V_5 ) )
V_172 -> V_2 = V_5 ;
else
continue;
F_103 ( V_172 -> V_174 , V_161 ) ;
V_172 -> V_209 = V_210 ;
V_34 = V_199 ( & V_172 -> V_193 ) ;
if ( V_34 )
V_204 = V_34 ;
}
break;
}
}
} while ( V_203 == V_206 );
V_207:
F_23 ( V_164 ) ;
return V_204 ? V_204 : V_34 ;
}
static int F_129 ( struct V_1 * V_1 ,
struct V_148 * V_149 ,
T_5 * V_199 )
{
T_1 V_2 ;
int V_34 = 0 ;
if ( F_17 ( V_1 ) ) {
V_149 -> V_150 = 0 ;
V_149 -> V_133 = F_18 ( V_1 ) ;
V_149 -> V_134 = F_18 ( V_1 ) ;
return V_199 ( & V_149 -> V_193 ) ;
}
F_20 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_149 -> V_150 = 0 ;
if ( V_2 == V_1 -> V_6 )
V_149 -> V_150 |= V_152 ;
if ( F_58 ( V_2 , V_1 -> V_146 ) )
V_149 -> V_150 |= V_151 ;
V_149 -> V_133 = V_2 ;
V_149 -> V_134 = V_2 ;
V_34 = V_199 ( & V_149 -> V_193 ) ;
if ( V_34 )
break;
}
return V_34 ;
}
static int F_130 ( struct V_7 * V_8 ,
struct V_192 * V_193 ,
T_5 * V_199 )
{
struct V_1 * V_1 = F_12 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_193 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_193 -> V_15 ) {
case V_194 :
V_34 = F_129 ( V_1 ,
F_108 ( V_193 ) , V_199 ) ;
break;
case V_195 :
V_34 = F_120 ( V_1 ,
F_109 ( V_193 ) , V_199 ,
V_193 -> V_13 ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static void F_131 ( bool V_25 , bool V_158 ,
char * V_161 , T_1 V_2 ,
struct V_7 * V_8 )
{
struct V_212 V_213 ;
unsigned long V_214 ;
if ( V_25 ) {
V_213 . V_174 = V_161 ;
V_213 . V_2 = V_2 ;
V_214 = V_158 ? V_215 : V_216 ;
F_132 ( V_214 , V_8 , & V_213 . V_213 ) ;
}
}
static void F_133 ( struct V_10 * V_10 ,
char * V_217 , int V_218 ,
bool V_158 )
{
struct V_1 * V_1 ;
char V_161 [ V_202 ] ;
T_2 V_46 ;
T_1 V_2 , V_5 ;
bool V_219 = true ;
int V_34 ;
F_134 ( V_217 , V_218 , V_161 , & V_5 , & V_46 ) ;
V_1 = V_10 -> V_182 [ V_46 ] ;
if ( ! V_1 ) {
F_135 ( V_10 -> V_220 -> V_8 , L_20 ) ;
goto V_221;
}
if ( F_126 ( V_5 ) ) {
struct V_1 * V_9 ;
V_9 = F_6 ( V_1 ,
V_5 ) ;
if ( ! V_9 ) {
F_31 ( V_1 -> V_8 , L_21 ) ;
goto V_221;
}
V_2 = 0 ;
V_1 = V_9 ;
} else {
V_2 = V_5 ;
}
V_222:
V_34 = F_88 ( V_10 , V_46 , V_161 , V_5 ,
V_158 , true ) ;
if ( V_34 ) {
if ( F_136 () )
F_31 ( V_1 -> V_8 , L_22 ) ;
return;
}
if ( ! V_219 )
return;
F_131 ( V_1 -> V_25 ,
V_158 , V_161 , V_2 , V_1 -> V_8 ) ;
return;
V_221:
V_158 = false ;
V_219 = false ;
goto V_222;
}
static void F_137 ( struct V_10 * V_10 ,
char * V_217 , int V_218 ,
bool V_158 )
{
struct V_1 * V_1 ;
struct V_7 * V_8 ;
char V_161 [ V_202 ] ;
T_1 V_170 = 0 ;
T_1 V_169 ;
T_1 V_2 , V_5 ;
bool V_219 = true ;
int V_34 ;
F_138 ( V_217 , V_218 , V_161 , & V_5 , & V_169 ) ;
V_1 = F_117 ( V_10 , V_169 ) ;
if ( ! V_1 ) {
F_135 ( V_10 -> V_220 -> V_8 , L_23 ) ;
goto V_221;
}
if ( F_126 ( V_5 ) ) {
struct V_1 * V_9 ;
V_9 = F_6 ( V_1 ,
V_5 ) ;
if ( ! V_9 ) {
F_31 ( V_1 -> V_8 , L_21 ) ;
goto V_221;
}
V_170 = F_18 ( V_9 ) ;
V_8 = V_9 -> V_8 ;
V_2 = 0 ;
V_1 = V_9 ;
} else {
V_8 = F_139 ( V_10 , V_169 ) -> V_8 ;
V_2 = V_5 ;
}
V_222:
V_34 = F_90 ( V_10 , V_169 , V_161 , V_5 , V_170 ,
V_158 , true ) ;
if ( V_34 ) {
if ( F_136 () )
F_31 ( V_1 -> V_8 , L_22 ) ;
return;
}
if ( ! V_219 )
return;
F_131 ( V_1 -> V_25 , V_158 , V_161 ,
V_2 , V_8 ) ;
return;
V_221:
V_158 = false ;
V_219 = false ;
goto V_222;
}
static void F_140 ( struct V_10 * V_10 ,
char * V_217 , int V_218 )
{
switch ( F_141 ( V_217 , V_218 ) ) {
case V_223 :
F_133 ( V_10 , V_217 ,
V_218 , true ) ;
break;
case V_224 :
F_133 ( V_10 , V_217 ,
V_218 , false ) ;
break;
case V_225 :
F_137 ( V_10 , V_217 ,
V_218 , true ) ;
break;
case V_226 :
F_137 ( V_10 , V_217 ,
V_218 , false ) ;
break;
}
}
static void F_142 ( struct V_10 * V_10 )
{
F_143 ( & V_10 -> V_227 . V_228 ,
F_144 ( V_10 -> V_227 . V_229 ) ) ;
}
static void F_145 ( struct V_230 * V_231 )
{
struct V_10 * V_10 ;
char * V_217 ;
T_2 V_203 ;
int V_179 ;
int V_34 ;
V_217 = F_15 ( V_232 , V_44 ) ;
if ( ! V_217 )
return;
V_10 = F_146 ( V_231 , struct V_10 , V_227 . V_228 . V_231 ) ;
F_147 () ;
F_148 ( V_217 ) ;
V_34 = F_122 ( V_10 -> V_47 , F_22 ( V_233 ) , V_217 ) ;
if ( V_34 ) {
F_135 ( V_10 -> V_220 -> V_8 , L_24 ) ;
goto V_207;
}
V_203 = F_149 ( V_217 ) ;
for ( V_179 = 0 ; V_179 < V_203 ; V_179 ++ )
F_140 ( V_10 , V_217 , V_179 ) ;
V_207:
F_150 () ;
F_23 ( V_217 ) ;
F_142 ( V_10 ) ;
}
static int F_151 ( struct V_10 * V_10 )
{
int V_34 ;
V_34 = F_37 ( V_10 , V_234 ) ;
if ( V_34 ) {
F_152 ( V_10 -> V_220 -> V_8 , L_25 ) ;
return V_34 ;
}
F_153 ( & V_10 -> V_227 . V_228 , F_145 ) ;
V_10 -> V_227 . V_229 = V_235 ;
F_142 ( V_10 ) ;
return 0 ;
}
static void F_154 ( struct V_10 * V_10 )
{
F_155 ( & V_10 -> V_227 . V_228 ) ;
}
int F_156 ( struct V_10 * V_10 )
{
return F_151 ( V_10 ) ;
}
void F_157 ( struct V_10 * V_10 )
{
F_154 ( V_10 ) ;
}
void F_158 ( struct V_1 * V_1 )
{
V_1 -> V_8 -> V_236 = & V_237 ;
}
void F_159 ( struct V_1 * V_1 )
{
}
