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
T_1 V_2 ;
if ( ! F_4 ( V_8 ) )
return V_1 ;
V_2 = F_5 ( V_8 ) ;
V_9 = F_6 ( V_1 , V_2 ) ;
F_7 ( ! V_9 ) ;
return V_9 ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
struct V_12 * V_12 = V_1 -> V_12 ;
V_1 = F_3 ( V_11 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_11 -> V_15 ) {
case V_16 :
V_11 -> V_17 . V_18 . V_19 = sizeof( V_12 -> V_20 ) ;
memcpy ( & V_11 -> V_17 . V_18 . V_15 , & V_12 -> V_20 ,
V_11 -> V_17 . V_18 . V_19 ) ;
break;
case V_21 :
V_11 -> V_17 . V_22 =
( V_1 -> V_23 ? V_24 : 0 ) |
( V_1 -> V_25 ? V_26 : 0 ) |
( V_1 -> V_27 ? V_28 : 0 ) ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_1 ,
T_2 V_30 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
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
F_11 () ;
}
V_33 = F_12 ( V_43 , V_44 ) ;
if ( ! V_33 )
return - V_45 ;
F_13 ( V_33 , V_1 -> V_46 ) ;
if ( F_14 ( V_1 ) ) {
V_2 = F_15 ( V_1 ) ;
F_16 ( V_33 , V_2 , V_32 ) ;
} else {
F_17 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_16 ( V_33 , V_2 , V_32 ) ;
}
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_48 ) , V_33 ) ;
F_20 ( V_33 ) ;
return V_34 ;
}
static int F_21 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
T_2 V_30 )
{
if ( F_22 ( V_50 ) )
return 0 ;
V_1 -> V_51 = V_30 ;
return F_10 ( V_1 , V_30 ) ;
}
static int F_23 ( struct V_1 * V_1 ,
T_1 V_52 , T_1 V_53 , bool V_54 ,
bool V_55 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
T_1 V_46 = V_1 -> V_46 ;
enum V_56 V_57 ;
T_1 V_58 = V_53 - V_52 + 1 ;
char * V_59 ;
int V_34 ;
if ( F_14 ( V_1 ) )
V_57 = V_60 ;
else
V_57 = V_61 ;
V_59 = F_12 ( V_62 , V_44 ) ;
if ( ! V_59 )
return - V_45 ;
F_24 ( V_59 , V_63 , V_52 ,
V_57 , V_58 , V_46 , V_54 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_64 ) , V_59 ) ;
if ( V_34 )
goto V_65;
F_24 ( V_59 , V_66 , V_52 ,
V_57 , V_58 , V_46 , V_55 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_64 ) , V_59 ) ;
if ( V_34 )
goto V_67;
goto V_65;
V_67:
F_24 ( V_59 , V_63 , V_52 ,
V_57 , V_58 , V_46 , ! V_54 ) ;
F_18 ( V_12 -> V_47 , F_19 ( V_64 ) , V_59 ) ;
V_65:
F_20 ( V_59 ) ;
return V_34 ;
}
static int F_25 ( struct V_1 * V_1 ,
bool V_68 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
T_1 V_2 , V_69 ;
int V_34 ;
if ( F_14 ( V_1 ) ) {
T_1 V_5 = F_2 ( V_1 ) -> V_5 ;
T_1 V_70 = F_26 ( V_5 ) ;
return F_23 ( V_1 , V_70 , V_70 ,
V_68 , true ) ;
}
F_17 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_34 = F_23 ( V_1 , V_2 , V_2 , V_68 ,
true ) ;
if ( V_34 ) {
V_69 = V_2 ;
goto V_71;
}
}
return 0 ;
V_71:
F_17 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_23 ( V_1 , V_2 , V_2 , ! V_68 , true ) ;
F_27 ( V_8 , L_1 ) ;
return V_34 ;
}
int F_28 ( struct V_1 * V_9 , T_1 V_5 ,
bool V_68 )
{
T_1 V_70 ;
V_70 = F_26 ( V_5 ) ;
return F_23 ( V_9 , V_70 , V_70 , V_68 , V_68 ) ;
}
static int F_29 ( struct V_1 * V_1 ,
bool V_68 )
{
T_1 V_2 ;
int V_34 ;
if ( F_14 ( V_1 ) ) {
V_2 = F_15 ( V_1 ) ;
return F_30 ( V_1 , V_2 , V_2 ,
V_68 ) ;
}
F_17 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_34 = F_30 ( V_1 , V_2 , V_2 ,
V_68 ) ;
if ( V_34 )
goto V_72;
}
return 0 ;
V_72:
F_17 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_30 ( V_1 , V_2 , V_2 , ! V_68 ) ;
return V_34 ;
}
static int F_31 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
unsigned long V_22 )
{
unsigned long V_23 = V_1 -> V_23 ? V_24 : 0 ;
unsigned long V_27 = V_1 -> V_27 ? V_28 : 0 ;
int V_34 ;
if ( ! V_1 -> V_73 )
return - V_14 ;
if ( F_22 ( V_50 ) )
return 0 ;
if ( ( V_27 ^ V_22 ) & V_28 ) {
V_34 = F_25 ( V_1 ,
! V_1 -> V_27 ) ;
if ( V_34 )
return V_34 ;
}
if ( ( V_23 ^ V_22 ) & V_24 ) {
V_34 = F_29 ( V_1 ,
! V_1 -> V_23 ) ;
if ( V_34 )
goto V_74;
}
V_1 -> V_27 = V_22 & V_28 ? 1 : 0 ;
V_1 -> V_23 = V_22 & V_24 ? 1 : 0 ;
V_1 -> V_25 = V_22 & V_26 ? 1 : 0 ;
return 0 ;
V_74:
if ( ( V_27 ^ V_22 ) & V_28 )
F_25 ( V_1 ,
V_1 -> V_27 ) ;
return V_34 ;
}
static int F_32 ( struct V_12 * V_12 , T_3 V_75 )
{
char V_76 [ V_77 ] ;
int V_34 ;
F_33 ( V_76 , V_75 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_78 ) , V_76 ) ;
if ( V_34 )
return V_34 ;
V_12 -> V_75 = V_75 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
unsigned long V_79 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
unsigned long V_80 = F_35 ( V_79 ) ;
T_3 V_75 = F_36 ( V_80 ) / 1000 ;
if ( F_22 ( V_50 ) ) {
if ( V_75 < V_81 ||
V_75 > V_82 )
return - V_83 ;
else
return 0 ;
}
return F_32 ( V_12 , V_75 ) ;
}
static int F_37 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
struct V_7 * V_13 ,
bool V_84 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
if ( ( ! V_84 ) && ( V_12 -> V_85 . V_8 == V_13 ) ) {
F_27 ( V_1 -> V_8 , L_2 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_38 ( struct V_7 * V_8 ,
const struct V_10 * V_11 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_11 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_11 -> V_15 ) {
case V_86 :
V_34 = F_21 ( V_1 , V_50 ,
V_11 -> V_17 . V_51 ) ;
break;
case V_21 :
V_34 = F_31 ( V_1 , V_50 ,
V_11 -> V_17 . V_22 ) ;
break;
case V_87 :
V_34 = F_34 ( V_1 , V_50 ,
V_11 -> V_17 . V_75 ) ;
break;
case V_88 :
V_34 = F_37 ( V_1 , V_50 ,
V_11 -> V_13 ,
V_11 -> V_17 . V_89 ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static int F_39 ( struct V_12 * V_12 , T_1 V_5 , bool V_90 )
{
char V_91 [ V_92 ] ;
F_40 ( V_91 , ! V_90 , V_5 , V_5 ) ;
return F_18 ( V_12 -> V_47 , F_19 ( V_93 ) , V_91 ) ;
}
static int F_41 ( struct V_12 * V_12 , T_1 V_5 , bool V_94 )
{
enum V_95 V_96 = V_97 ;
char V_98 [ V_99 ] ;
F_42 ( V_98 , 0 , V_96 , V_94 , V_5 , V_5 ) ;
return F_18 ( V_12 -> V_47 , F_19 ( V_100 ) , V_98 ) ;
}
static struct V_3 * F_43 ( T_1 V_5 )
{
struct V_3 * V_4 ;
V_4 = F_44 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_5 = V_5 ;
return V_4 ;
}
struct V_3 * F_45 ( struct V_12 * V_12 , T_1 V_5 )
{
struct V_3 * V_4 ;
int V_34 ;
V_34 = F_39 ( V_12 , V_5 , true ) ;
if ( V_34 )
return F_46 ( V_34 ) ;
V_34 = F_41 ( V_12 , V_5 , true ) ;
if ( V_34 )
goto V_101;
V_4 = F_43 ( V_5 ) ;
if ( ! V_4 ) {
V_34 = - V_45 ;
goto V_102;
}
F_47 ( & V_4 -> V_103 , & V_12 -> V_104 ) ;
return V_4 ;
V_102:
F_41 ( V_12 , V_5 , false ) ;
V_101:
F_39 ( V_12 , V_5 , false ) ;
return F_46 ( V_34 ) ;
}
void F_48 ( struct V_12 * V_12 , struct V_3 * V_4 )
{
T_1 V_5 = V_4 -> V_5 ;
F_49 ( & V_4 -> V_103 ) ;
if ( V_4 -> V_105 )
F_50 ( V_12 , V_4 -> V_105 ) ;
F_20 ( V_4 ) ;
F_41 ( V_12 , V_5 , false ) ;
F_39 ( V_12 , V_5 , false ) ;
}
static int F_51 ( struct V_1 * V_1 ,
T_1 V_5 )
{
struct V_3 * V_4 ;
if ( F_52 ( V_5 , V_1 -> V_106 ) )
return 0 ;
V_4 = F_53 ( V_1 -> V_12 , V_5 ) ;
if ( ! V_4 ) {
V_4 = F_45 ( V_1 -> V_12 , V_5 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
}
V_4 -> V_107 ++ ;
F_56 ( V_1 -> V_8 , L_3 , V_5 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_1 ,
T_1 V_5 )
{
struct V_3 * V_4 ;
V_4 = F_53 ( V_1 -> V_12 , V_5 ) ;
if ( F_7 ( ! V_4 ) )
return;
F_56 ( V_1 -> V_8 , L_4 , V_5 ) ;
F_58 ( V_1 , V_5 ) ;
if ( -- V_4 -> V_107 == 0 )
F_48 ( V_1 -> V_12 , V_4 ) ;
}
static int F_59 ( struct V_1 * V_1 , T_1 V_5 ,
bool V_94 )
{
enum V_95 V_96 = V_108 ;
if ( F_60 ( & V_1 -> V_109 ) )
return 0 ;
return F_61 ( V_1 , V_96 , V_94 , V_5 , V_5 ) ;
}
static int F_62 ( struct V_1 * V_1 ,
T_1 V_110 , T_1 V_111 )
{
int V_5 , V_34 ;
for ( V_5 = V_110 ; V_5 <= V_111 ; V_5 ++ ) {
V_34 = F_51 ( V_1 , V_5 ) ;
if ( V_34 )
goto V_112;
}
V_34 = F_23 ( V_1 , V_110 , V_111 ,
V_1 -> V_27 , true ) ;
if ( V_34 )
goto V_71;
for ( V_5 = V_110 ; V_5 <= V_111 ; V_5 ++ ) {
V_34 = F_59 ( V_1 , V_5 , true ) ;
if ( V_34 )
goto V_113;
}
return 0 ;
V_113:
for ( V_5 -- ; V_5 >= V_110 ; V_5 -- )
F_59 ( V_1 , V_5 , false ) ;
F_23 ( V_1 , V_110 , V_111 , false ,
false ) ;
V_71:
V_5 = V_111 ;
V_112:
for ( V_5 -- ; V_5 >= V_110 ; V_5 -- )
F_57 ( V_1 , V_5 ) ;
return V_34 ;
}
static void F_63 ( struct V_1 * V_1 ,
T_1 V_110 , T_1 V_111 )
{
int V_5 ;
for ( V_5 = V_110 ; V_5 <= V_111 ; V_5 ++ )
F_59 ( V_1 , V_5 , false ) ;
F_23 ( V_1 , V_110 , V_111 , false ,
false ) ;
for ( V_5 = V_110 ; V_5 <= V_111 ; V_5 ++ )
F_57 ( V_1 , V_5 ) ;
}
static int F_64 ( struct V_1 * V_1 ,
T_1 V_2 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
char V_114 [ V_115 ] ;
F_65 ( V_114 , V_1 -> V_46 , V_2 ) ;
return F_18 ( V_12 -> V_47 , F_19 ( V_116 ) , V_114 ) ;
}
static int F_66 ( struct V_1 * V_1 ,
bool V_117 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
char V_118 [ V_119 ] ;
F_67 ( V_118 , V_1 -> V_46 , V_117 ) ;
return F_18 ( V_12 -> V_47 , F_19 ( V_120 ) , V_118 ) ;
}
int F_68 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
int V_34 ;
if ( ! V_2 ) {
V_34 = F_66 ( V_1 , false ) ;
if ( V_34 ) {
F_27 ( V_8 , L_5 ) ;
return V_34 ;
}
} else {
V_34 = F_64 ( V_1 , V_2 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_6 ) ;
return V_34 ;
}
if ( ! V_1 -> V_6 ) {
V_34 = F_66 ( V_1 ,
true ) ;
if ( V_34 ) {
F_27 ( V_8 , L_7 ) ;
goto V_121;
}
}
}
V_1 -> V_6 = V_2 ;
return 0 ;
V_121:
F_64 ( V_1 , V_1 -> V_6 ) ;
return V_34 ;
}
static int F_69 ( struct V_1 * V_1 ,
T_1 V_122 , T_1 V_123 , bool V_124 ,
bool V_125 )
{
T_1 V_2 , V_126 ;
int V_34 ;
for ( V_2 = V_122 ; V_2 <= V_123 ;
V_2 += V_127 ) {
V_126 = F_70 ( ( T_1 ) ( V_2 + V_127 - 1 ) ,
V_123 ) ;
V_34 = F_71 ( V_1 , V_2 , V_126 ,
V_124 , V_125 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_1 ,
T_1 V_122 , T_1 V_123 ,
bool V_128 )
{
T_1 V_2 , V_126 ;
int V_34 ;
for ( V_2 = V_122 ; V_2 <= V_123 ;
V_2 += V_129 ) {
V_126 = F_70 ( ( T_1 ) ( V_2 + V_129 - 1 ) ,
V_123 ) ;
V_34 = F_30 ( V_1 , V_2 ,
V_126 , V_128 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_1 ,
T_1 V_122 , T_1 V_123 ,
bool V_130 , bool V_131 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
T_1 V_2 , V_132 ;
int V_34 ;
if ( ! V_1 -> V_73 )
return - V_14 ;
V_34 = F_62 ( V_1 , V_122 , V_123 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_8 ) ;
return V_34 ;
}
V_34 = F_69 ( V_1 , V_122 , V_123 ,
true , V_130 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_9 , V_122 ,
V_123 ) ;
goto V_133;
}
V_132 = V_1 -> V_6 ;
if ( V_131 && V_132 != V_122 ) {
V_34 = F_68 ( V_1 , V_122 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_10 , V_122 ) ;
goto V_134;
}
} else if ( ! V_131 && V_132 >= V_122 && V_132 <= V_123 ) {
V_34 = F_68 ( V_1 , 0 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_11 ) ;
goto V_134;
}
}
V_34 = F_72 ( V_1 , V_122 , V_123 ,
V_1 -> V_23 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_12 ,
V_122 , V_123 ) ;
goto V_72;
}
for ( V_2 = V_122 ; V_2 <= V_123 ; V_2 ++ ) {
F_74 ( V_2 , V_1 -> V_106 ) ;
if ( V_130 )
F_74 ( V_2 , V_1 -> V_135 ) ;
else
F_75 ( V_2 , V_1 -> V_135 ) ;
}
V_34 = F_10 ( V_1 ,
V_1 -> V_51 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_13 ) ;
goto V_136;
}
return 0 ;
V_136:
for ( V_2 = V_122 ; V_2 <= V_123 ; V_2 ++ )
F_75 ( V_2 , V_1 -> V_106 ) ;
F_72 ( V_1 , V_122 , V_123 ,
false ) ;
V_72:
if ( V_132 != V_1 -> V_6 )
F_68 ( V_1 , V_132 ) ;
V_134:
F_69 ( V_1 , V_122 , V_123 , false ,
false ) ;
V_133:
F_63 ( V_1 , V_122 , V_123 ) ;
return V_34 ;
}
static int F_76 ( struct V_1 * V_1 ,
const struct V_137 * V_138 ,
struct V_49 * V_50 )
{
bool V_130 = V_138 -> V_139 & V_140 ;
bool V_131 = V_138 -> V_139 & V_141 ;
if ( F_22 ( V_50 ) )
return 0 ;
return F_73 ( V_1 ,
V_138 -> V_122 , V_138 -> V_123 ,
V_130 , V_131 ) ;
}
static enum V_142 F_77 ( bool V_143 )
{
return V_143 ? V_144 :
V_145 ;
}
static enum V_146 F_78 ( bool V_147 )
{
return V_147 ? V_148 :
V_149 ;
}
static int F_79 ( struct V_12 * V_12 , T_2 V_46 ,
const char * V_150 , T_1 V_5 , bool V_147 ,
enum V_151 V_152 ,
bool V_143 )
{
char * V_153 ;
int V_34 ;
V_153 = F_12 ( V_154 , V_44 ) ;
if ( ! V_153 )
return - V_45 ;
F_80 ( V_153 , F_78 ( V_147 ) , 0 ) ;
F_81 ( V_153 , 0 , F_77 ( V_143 ) ,
V_150 , V_5 , V_152 , V_46 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_155 ) , V_153 ) ;
F_20 ( V_153 ) ;
return V_34 ;
}
static int F_82 ( struct V_12 * V_12 , T_2 V_46 ,
const char * V_150 , T_1 V_5 , bool V_147 ,
bool V_143 )
{
return F_79 ( V_12 , V_46 , V_150 , V_5 , V_147 ,
V_156 , V_143 ) ;
}
int F_83 ( struct V_12 * V_12 , const char * V_150 , T_1 V_5 ,
bool V_147 )
{
return F_79 ( V_12 , 0 , V_150 , V_5 , V_147 ,
V_157 ,
false ) ;
}
static int F_84 ( struct V_12 * V_12 , T_1 V_158 ,
const char * V_150 , T_1 V_5 , T_1 V_159 ,
bool V_147 , bool V_143 )
{
char * V_153 ;
int V_34 ;
V_153 = F_12 ( V_154 , V_44 ) ;
if ( ! V_153 )
return - V_45 ;
F_80 ( V_153 , F_78 ( V_147 ) , 0 ) ;
F_85 ( V_153 , 0 , F_77 ( V_143 ) ,
V_150 , V_5 , V_156 ,
V_159 , V_158 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_155 ) , V_153 ) ;
F_20 ( V_153 ) ;
return V_34 ;
}
static int
F_86 ( struct V_1 * V_1 ,
const struct V_160 * V_161 ,
struct V_49 * V_50 )
{
T_1 V_5 = F_1 ( V_1 , V_161 -> V_2 ) ;
T_1 V_159 = 0 ;
if ( F_22 ( V_50 ) )
return 0 ;
if ( F_14 ( V_1 ) ) {
V_159 = F_15 ( V_1 ) ;
}
if ( ! V_1 -> V_162 )
return F_82 ( V_1 -> V_12 ,
V_1 -> V_46 ,
V_161 -> V_163 , V_5 , true , false ) ;
else
return F_84 ( V_1 -> V_12 ,
V_1 -> V_158 ,
V_161 -> V_163 , V_5 , V_159 ,
true , false ) ;
}
static int F_87 ( struct V_12 * V_12 , const char * V_163 ,
T_1 V_5 , T_1 V_164 , bool V_147 )
{
char * V_153 ;
int V_34 ;
V_153 = F_12 ( V_154 , V_44 ) ;
if ( ! V_153 )
return - V_45 ;
F_80 ( V_153 , F_78 ( V_147 ) , 0 ) ;
F_88 ( V_153 , 0 , V_163 , V_5 ,
V_156 , V_164 ) ;
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_155 ) , V_153 ) ;
F_20 ( V_153 ) ;
return V_34 ;
}
static int F_89 ( struct V_1 * V_1 , T_1 V_164 ,
bool V_165 , bool V_166 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
char * V_167 ;
int V_34 , V_168 ;
V_167 = F_12 ( V_169 , V_44 ) ;
if ( ! V_167 )
return - V_45 ;
F_90 ( V_167 , V_164 , V_1 -> V_46 , V_165 ) ;
if ( V_166 ) {
for ( V_168 = 1 ; V_168 < V_170 ; V_168 ++ )
if ( V_12 -> V_171 [ V_168 ] )
F_91 ( V_167 , V_168 , 1 ) ;
}
V_34 = F_18 ( V_12 -> V_47 , F_19 ( V_172 ) , V_167 ) ;
F_20 ( V_167 ) ;
return V_34 ;
}
static struct V_173 * F_92 ( struct V_12 * V_12 ,
const unsigned char * V_163 ,
T_1 V_5 )
{
struct V_173 * V_164 ;
F_93 (mid, &mlxsw_sp->br_mids.list, list) {
if ( F_94 ( V_164 -> V_163 , V_163 ) && V_164 -> V_5 == V_5 )
return V_164 ;
}
return NULL ;
}
static struct V_173 * F_95 ( struct V_12 * V_12 ,
const unsigned char * V_163 ,
T_1 V_5 )
{
struct V_173 * V_164 ;
T_1 V_174 ;
V_174 = F_96 ( V_12 -> V_175 . V_176 ,
V_177 ) ;
if ( V_174 == V_177 )
return NULL ;
V_164 = F_44 ( sizeof( * V_164 ) , V_44 ) ;
if ( ! V_164 )
return NULL ;
F_74 ( V_174 , V_12 -> V_175 . V_176 ) ;
F_97 ( V_164 -> V_163 , V_163 ) ;
V_164 -> V_5 = V_5 ;
V_164 -> V_164 = V_174 ;
V_164 -> V_107 = 0 ;
F_98 ( & V_164 -> V_103 , & V_12 -> V_175 . V_103 ) ;
return V_164 ;
}
static int F_99 ( struct V_12 * V_12 ,
struct V_173 * V_164 )
{
if ( -- V_164 -> V_107 == 0 ) {
F_49 ( & V_164 -> V_103 ) ;
F_75 ( V_164 -> V_164 , V_12 -> V_175 . V_176 ) ;
F_20 ( V_164 ) ;
return 1 ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_1 ,
const struct V_178 * V_179 ,
struct V_49 * V_50 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_173 * V_164 ;
T_1 V_5 = F_1 ( V_1 , V_179 -> V_2 ) ;
int V_34 = 0 ;
if ( F_22 ( V_50 ) )
return 0 ;
V_164 = F_92 ( V_12 , V_179 -> V_163 , V_5 ) ;
if ( ! V_164 ) {
V_164 = F_95 ( V_12 , V_179 -> V_163 , V_5 ) ;
if ( ! V_164 ) {
F_27 ( V_8 , L_14 ) ;
return - V_45 ;
}
}
V_164 -> V_107 ++ ;
V_34 = F_89 ( V_1 , V_164 -> V_164 , true ,
V_164 -> V_107 == 1 ) ;
if ( V_34 ) {
F_27 ( V_8 , L_15 ) ;
goto V_180;
}
if ( V_164 -> V_107 == 1 ) {
V_34 = F_87 ( V_12 , V_179 -> V_163 , V_5 , V_164 -> V_164 ,
true ) ;
if ( V_34 ) {
F_27 ( V_8 , L_16 ) ;
goto V_180;
}
}
return 0 ;
V_180:
F_99 ( V_12 , V_164 ) ;
return V_34 ;
}
static int F_101 ( struct V_7 * V_8 ,
const struct V_181 * V_182 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_182 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_182 -> V_15 ) {
case V_183 :
if ( F_14 ( V_1 ) )
return 0 ;
V_34 = F_76 ( V_1 ,
F_102 ( V_182 ) ,
V_50 ) ;
break;
case V_184 :
V_34 = F_86 ( V_1 ,
F_103 ( V_182 ) ,
V_50 ) ;
break;
case V_185 :
V_34 = F_100 ( V_1 ,
F_104 ( V_182 ) ,
V_50 ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static int F_105 ( struct V_1 * V_1 ,
T_1 V_122 , T_1 V_123 )
{
T_1 V_2 , V_6 ;
if ( ! V_1 -> V_73 )
return - V_14 ;
F_72 ( V_1 , V_122 , V_123 ,
false ) ;
V_6 = V_1 -> V_6 ;
if ( V_6 >= V_122 && V_6 <= V_123 )
F_68 ( V_1 , 0 ) ;
F_69 ( V_1 , V_122 , V_123 , false ,
false ) ;
F_63 ( V_1 , V_122 , V_123 ) ;
for ( V_2 = V_122 ; V_2 <= V_123 ; V_2 ++ )
F_75 ( V_2 , V_1 -> V_106 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_1 ,
const struct V_137 * V_138 )
{
return F_105 ( V_1 , V_138 -> V_122 ,
V_138 -> V_123 ) ;
}
void F_107 ( struct V_1 * V_1 )
{
T_1 V_2 ;
F_17 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_105 ( V_1 , V_2 , V_2 ) ;
}
static int
F_108 ( struct V_1 * V_1 ,
const struct V_160 * V_161 )
{
T_1 V_5 = F_1 ( V_1 , V_161 -> V_2 ) ;
T_1 V_159 = 0 ;
if ( F_14 ( V_1 ) ) {
V_159 = F_15 ( V_1 ) ;
}
if ( ! V_1 -> V_162 )
return F_82 ( V_1 -> V_12 ,
V_1 -> V_46 ,
V_161 -> V_163 , V_5 ,
false , false ) ;
else
return F_84 ( V_1 -> V_12 ,
V_1 -> V_158 ,
V_161 -> V_163 , V_5 , V_159 ,
false , false ) ;
}
static int F_109 ( struct V_1 * V_1 ,
const struct V_178 * V_179 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_173 * V_164 ;
T_1 V_5 = F_1 ( V_1 , V_179 -> V_2 ) ;
T_1 V_174 ;
int V_34 = 0 ;
V_164 = F_92 ( V_12 , V_179 -> V_163 , V_5 ) ;
if ( ! V_164 ) {
F_27 ( V_8 , L_17 ) ;
return - V_14 ;
}
V_34 = F_89 ( V_1 , V_164 -> V_164 , false , false ) ;
if ( V_34 )
F_27 ( V_8 , L_18 ) ;
V_174 = V_164 -> V_164 ;
if ( F_99 ( V_12 , V_164 ) ) {
V_34 = F_87 ( V_12 , V_179 -> V_163 , V_5 , V_174 ,
false ) ;
if ( V_34 )
F_27 ( V_8 , L_19 ) ;
}
return V_34 ;
}
static int F_110 ( struct V_7 * V_8 ,
const struct V_181 * V_182 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_182 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_182 -> V_15 ) {
case V_183 :
if ( F_14 ( V_1 ) )
return 0 ;
V_34 = F_106 ( V_1 ,
F_102 ( V_182 ) ) ;
break;
case V_184 :
V_34 = F_108 ( V_1 ,
F_103 ( V_182 ) ) ;
break;
case V_185 :
V_34 = F_109 ( V_1 ,
F_104 ( V_182 ) ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static struct V_1 * F_111 ( struct V_12 * V_12 ,
T_1 V_158 )
{
struct V_1 * V_1 ;
T_4 V_186 ;
int V_168 ;
V_186 = F_112 ( V_12 -> V_47 ,
V_187 ) ;
for ( V_168 = 0 ; V_168 < V_186 ; V_168 ++ ) {
V_1 = F_113 ( V_12 , V_158 , V_168 ) ;
if ( V_1 )
return V_1 ;
}
return NULL ;
}
static int F_114 ( struct V_1 * V_1 ,
struct V_160 * V_161 ,
T_5 * V_188 ,
struct V_7 * V_13 )
{
struct V_12 * V_12 = V_1 -> V_12 ;
struct V_1 * V_189 ;
struct V_3 * V_4 ;
T_1 V_190 ;
char * V_153 ;
char V_150 [ V_191 ] ;
T_1 V_5 ;
T_2 V_46 ;
T_1 V_158 ;
T_2 V_192 ;
int V_193 = 0 ;
int V_168 ;
int V_34 ;
V_153 = F_12 ( V_154 , V_44 ) ;
if ( ! V_153 )
return - V_45 ;
V_4 = F_2 ( V_1 ) ;
V_190 = V_4 ? V_4 -> V_5 : 0 ;
F_80 ( V_153 , V_194 , 0 ) ;
do {
F_115 ( V_153 , V_195 ) ;
V_34 = F_116 ( V_12 -> V_47 , F_19 ( V_155 ) , V_153 ) ;
if ( V_34 )
goto V_196;
V_192 = F_117 ( V_153 ) ;
if ( V_193 )
continue;
for ( V_168 = 0 ; V_168 < V_192 ; V_168 ++ ) {
switch ( F_118 ( V_153 , V_168 ) ) {
case V_197 :
F_119 ( V_153 , V_168 , V_150 , & V_5 ,
& V_46 ) ;
if ( V_46 == V_1 -> V_46 ) {
if ( V_190 && V_190 == V_5 )
V_161 -> V_2 = 0 ;
else if ( ! V_190 &&
! F_120 ( V_5 ) )
V_161 -> V_2 = V_5 ;
else
continue;
F_97 ( V_161 -> V_163 , V_150 ) ;
V_161 -> V_198 = V_199 ;
V_34 = V_188 ( & V_161 -> V_182 ) ;
if ( V_34 )
V_193 = V_34 ;
}
break;
case V_200 :
F_121 ( V_153 , V_168 ,
V_150 , & V_5 , & V_158 ) ;
V_189 = F_111 ( V_12 , V_158 ) ;
if ( V_189 && V_189 -> V_46 ==
V_1 -> V_46 ) {
if ( ! F_122 ( V_13 ) &&
! F_4 ( V_13 ) )
continue;
if ( V_190 && V_190 == V_5 )
V_161 -> V_2 = 0 ;
else if ( ! V_190 &&
! F_120 ( V_5 ) )
V_161 -> V_2 = V_5 ;
else
continue;
F_97 ( V_161 -> V_163 , V_150 ) ;
V_161 -> V_198 = V_199 ;
V_34 = V_188 ( & V_161 -> V_182 ) ;
if ( V_34 )
V_193 = V_34 ;
}
break;
}
}
} while ( V_192 == V_195 );
V_196:
F_20 ( V_153 ) ;
return V_193 ? V_193 : V_34 ;
}
static int F_123 ( struct V_1 * V_1 ,
struct V_137 * V_138 ,
T_5 * V_188 )
{
T_1 V_2 ;
int V_34 = 0 ;
if ( F_14 ( V_1 ) ) {
V_138 -> V_139 = 0 ;
V_138 -> V_122 = F_15 ( V_1 ) ;
V_138 -> V_123 = F_15 ( V_1 ) ;
return V_188 ( & V_138 -> V_182 ) ;
}
F_17 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_138 -> V_139 = 0 ;
if ( V_2 == V_1 -> V_6 )
V_138 -> V_139 |= V_141 ;
if ( F_52 ( V_2 , V_1 -> V_135 ) )
V_138 -> V_139 |= V_140 ;
V_138 -> V_122 = V_2 ;
V_138 -> V_123 = V_2 ;
V_34 = V_188 ( & V_138 -> V_182 ) ;
if ( V_34 )
break;
}
return V_34 ;
}
static int F_124 ( struct V_7 * V_8 ,
struct V_181 * V_182 ,
T_5 * V_188 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
int V_34 = 0 ;
V_1 = F_3 ( V_182 -> V_13 , V_1 ) ;
if ( ! V_1 )
return - V_14 ;
switch ( V_182 -> V_15 ) {
case V_183 :
V_34 = F_123 ( V_1 ,
F_102 ( V_182 ) , V_188 ) ;
break;
case V_184 :
V_34 = F_114 ( V_1 ,
F_103 ( V_182 ) , V_188 ,
V_182 -> V_13 ) ;
break;
default:
V_34 = - V_29 ;
break;
}
return V_34 ;
}
static void F_125 ( bool V_25 , bool V_147 ,
char * V_150 , T_1 V_2 ,
struct V_7 * V_8 )
{
struct V_201 V_202 ;
unsigned long V_203 ;
if ( V_25 ) {
V_202 . V_163 = V_150 ;
V_202 . V_2 = V_2 ;
V_203 = V_147 ? V_204 : V_205 ;
F_126 ( V_203 , V_8 , & V_202 . V_202 ) ;
}
}
static void F_127 ( struct V_12 * V_12 ,
char * V_206 , int V_207 ,
bool V_147 )
{
struct V_1 * V_1 ;
char V_150 [ V_191 ] ;
T_2 V_46 ;
T_1 V_2 , V_5 ;
bool V_208 = true ;
int V_34 ;
F_128 ( V_206 , V_207 , V_150 , & V_5 , & V_46 ) ;
V_1 = V_12 -> V_171 [ V_46 ] ;
if ( ! V_1 ) {
F_129 ( V_12 -> V_209 -> V_8 , L_20 ) ;
goto V_210;
}
if ( F_120 ( V_5 ) ) {
struct V_1 * V_9 ;
V_9 = F_130 ( V_1 ,
V_5 ) ;
if ( ! V_9 ) {
F_27 ( V_1 -> V_8 , L_21 ) ;
goto V_210;
}
V_2 = 0 ;
V_1 = V_9 ;
} else {
V_2 = V_5 ;
}
V_211:
V_34 = F_82 ( V_12 , V_46 , V_150 , V_5 ,
V_147 , true ) ;
if ( V_34 ) {
if ( F_131 () )
F_27 ( V_1 -> V_8 , L_22 ) ;
return;
}
if ( ! V_208 )
return;
F_125 ( V_1 -> V_25 ,
V_147 , V_150 , V_2 , V_1 -> V_8 ) ;
return;
V_210:
V_147 = false ;
V_208 = false ;
goto V_211;
}
static void F_132 ( struct V_12 * V_12 ,
char * V_206 , int V_207 ,
bool V_147 )
{
struct V_1 * V_1 ;
struct V_7 * V_8 ;
char V_150 [ V_191 ] ;
T_1 V_159 = 0 ;
T_1 V_158 ;
T_1 V_2 , V_5 ;
bool V_208 = true ;
int V_34 ;
F_133 ( V_206 , V_207 , V_150 , & V_5 , & V_158 ) ;
V_1 = F_111 ( V_12 , V_158 ) ;
if ( ! V_1 ) {
F_129 ( V_12 -> V_209 -> V_8 , L_23 ) ;
goto V_210;
}
if ( F_120 ( V_5 ) ) {
struct V_1 * V_9 ;
V_9 = F_130 ( V_1 ,
V_5 ) ;
if ( ! V_9 ) {
F_27 ( V_1 -> V_8 , L_21 ) ;
goto V_210;
}
V_159 = F_15 ( V_9 ) ;
V_8 = V_9 -> V_8 ;
V_2 = 0 ;
V_1 = V_9 ;
} else {
V_8 = F_134 ( V_12 , V_158 ) -> V_8 ;
V_2 = V_5 ;
}
V_211:
V_34 = F_84 ( V_12 , V_158 , V_150 , V_5 , V_159 ,
V_147 , true ) ;
if ( V_34 ) {
if ( F_131 () )
F_27 ( V_1 -> V_8 , L_22 ) ;
return;
}
if ( ! V_208 )
return;
F_125 ( V_1 -> V_25 , V_147 , V_150 ,
V_2 , V_8 ) ;
return;
V_210:
V_147 = false ;
V_208 = false ;
goto V_211;
}
static void F_135 ( struct V_12 * V_12 ,
char * V_206 , int V_207 )
{
switch ( F_136 ( V_206 , V_207 ) ) {
case V_212 :
F_127 ( V_12 , V_206 ,
V_207 , true ) ;
break;
case V_213 :
F_127 ( V_12 , V_206 ,
V_207 , false ) ;
break;
case V_214 :
F_132 ( V_12 , V_206 ,
V_207 , true ) ;
break;
case V_215 :
F_132 ( V_12 , V_206 ,
V_207 , false ) ;
break;
}
}
static void F_137 ( struct V_12 * V_12 )
{
F_138 ( & V_12 -> V_216 . V_217 ,
F_139 ( V_12 -> V_216 . V_218 ) ) ;
}
static void F_140 ( struct V_219 * V_220 )
{
struct V_12 * V_12 ;
char * V_206 ;
T_2 V_192 ;
int V_168 ;
int V_34 ;
V_206 = F_12 ( V_221 , V_44 ) ;
if ( ! V_206 )
return;
V_12 = F_141 ( V_220 , struct V_12 , V_216 . V_217 . V_220 ) ;
F_142 () ;
F_143 ( V_206 ) ;
V_34 = F_116 ( V_12 -> V_47 , F_19 ( V_222 ) , V_206 ) ;
if ( V_34 ) {
F_129 ( V_12 -> V_209 -> V_8 , L_24 ) ;
goto V_196;
}
V_192 = F_144 ( V_206 ) ;
for ( V_168 = 0 ; V_168 < V_192 ; V_168 ++ )
F_135 ( V_12 , V_206 , V_168 ) ;
V_196:
F_145 () ;
F_20 ( V_206 ) ;
F_137 ( V_12 ) ;
}
static int F_146 ( struct V_12 * V_12 )
{
int V_34 ;
V_34 = F_32 ( V_12 , V_223 ) ;
if ( V_34 ) {
F_147 ( V_12 -> V_209 -> V_8 , L_25 ) ;
return V_34 ;
}
F_148 ( & V_12 -> V_216 . V_217 , F_140 ) ;
V_12 -> V_216 . V_218 = V_224 ;
F_137 ( V_12 ) ;
return 0 ;
}
static void F_149 ( struct V_12 * V_12 )
{
F_150 ( & V_12 -> V_216 . V_217 ) ;
}
int F_151 ( struct V_12 * V_12 )
{
return F_146 ( V_12 ) ;
}
void F_152 ( struct V_12 * V_12 )
{
F_149 ( V_12 ) ;
}
void F_153 ( struct V_1 * V_1 )
{
V_1 -> V_8 -> V_225 = & V_226 ;
}
void F_154 ( struct V_1 * V_1 )
{
}
