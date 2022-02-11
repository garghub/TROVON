static struct V_1 *
F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 ;
F_2 (bridge_device, &bridge->bridges_list, list)
if ( V_6 -> V_7 == V_5 )
return V_6 ;
return NULL ;
}
static struct V_1 *
F_3 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_8 * V_7 = V_3 -> V_9 -> V_10 -> V_7 ;
struct V_1 * V_6 ;
bool V_11 = F_4 ( V_5 ) ;
if ( V_11 && V_3 -> V_12 ) {
F_5 ( V_7 , L_1 ) ;
return F_6 ( - V_13 ) ;
}
V_6 = F_7 ( sizeof( * V_6 ) , V_14 ) ;
if ( ! V_6 )
return F_6 ( - V_15 ) ;
V_6 -> V_7 = V_5 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_16 = F_8 ( V_5 ) ;
F_9 ( & V_6 -> V_17 ) ;
if ( V_11 ) {
V_3 -> V_12 = true ;
V_6 -> V_18 = V_3 -> V_19 ;
} else {
V_6 -> V_18 = V_3 -> V_20 ;
}
F_10 ( & V_6 -> V_21 , & V_3 -> V_22 ) ;
return V_6 ;
}
static void
F_11 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
F_12 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_11 )
V_3 -> V_12 = false ;
F_13 ( ! F_14 ( & V_6 -> V_17 ) ) ;
F_15 ( V_6 ) ;
}
static struct V_1 *
F_16 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 , V_5 ) ;
if ( V_6 )
return V_6 ;
return F_3 ( V_3 , V_5 ) ;
}
static void
F_17 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
if ( F_14 ( & V_6 -> V_17 ) )
F_11 ( V_3 , V_6 ) ;
}
static struct V_23 *
F_18 ( const struct V_1 * V_6 ,
const struct V_4 * V_24 )
{
struct V_23 * V_25 ;
F_2 (bridge_port, &bridge_device->ports_list, list) {
if ( V_25 -> V_7 == V_24 )
return V_25 ;
}
return NULL ;
}
static struct V_23 *
F_19 ( struct V_2 * V_3 ,
struct V_4 * V_24 )
{
struct V_4 * V_5 = F_20 ( V_24 ) ;
struct V_1 * V_6 ;
if ( ! V_5 )
return NULL ;
V_6 = F_1 ( V_3 , V_5 ) ;
if ( ! V_6 )
return NULL ;
return F_18 ( V_6 , V_24 ) ;
}
static struct V_23 *
F_21 ( struct V_1 * V_6 ,
struct V_4 * V_24 )
{
struct V_23 * V_25 ;
struct V_26 * V_26 ;
V_25 = F_7 ( sizeof( * V_25 ) , V_14 ) ;
if ( ! V_25 )
return NULL ;
V_26 = F_22 ( V_24 ) ;
V_25 -> V_27 = V_26 -> V_27 ;
if ( V_25 -> V_27 )
V_25 -> V_28 = V_26 -> V_28 ;
else
V_25 -> V_29 = V_26 -> V_30 ;
V_25 -> V_7 = V_24 ;
V_25 -> V_6 = V_6 ;
V_25 -> V_31 = V_32 ;
V_25 -> V_33 = V_34 | V_35 | V_36 ;
F_9 ( & V_25 -> V_37 ) ;
F_10 ( & V_25 -> V_21 , & V_6 -> V_17 ) ;
V_25 -> V_38 = 1 ;
return V_25 ;
}
static void
F_23 ( struct V_23 * V_25 )
{
F_12 ( & V_25 -> V_21 ) ;
F_13 ( ! F_14 ( & V_25 -> V_37 ) ) ;
F_15 ( V_25 ) ;
}
static bool
F_24 ( const struct V_23 *
V_25 )
{
struct V_9 * V_9 = F_25 ( V_25 -> V_7 ) ;
if ( ! V_9 && F_14 ( & V_25 -> V_37 ) )
return true ;
else if ( V_25 -> V_38 == 0 )
return true ;
else
return false ;
}
static struct V_23 *
F_26 ( struct V_2 * V_3 ,
struct V_4 * V_24 )
{
struct V_4 * V_5 = F_20 ( V_24 ) ;
struct V_1 * V_6 ;
struct V_23 * V_25 ;
int V_39 ;
V_25 = F_19 ( V_3 , V_24 ) ;
if ( V_25 ) {
V_25 -> V_38 ++ ;
return V_25 ;
}
V_6 = F_16 ( V_3 , V_5 ) ;
if ( F_27 ( V_6 ) )
return F_28 ( V_6 ) ;
V_25 = F_21 ( V_6 , V_24 ) ;
if ( ! V_25 ) {
V_39 = - V_15 ;
goto V_40;
}
return V_25 ;
V_40:
F_17 ( V_3 , V_6 ) ;
return F_6 ( V_39 ) ;
}
static void F_29 ( struct V_2 * V_3 ,
struct V_23 * V_25 )
{
struct V_1 * V_6 ;
V_25 -> V_38 -- ;
if ( ! F_24 ( V_25 ) )
return;
V_6 = V_25 -> V_6 ;
F_23 ( V_25 ) ;
F_17 ( V_3 , V_6 ) ;
}
static struct V_41 *
F_30 ( struct V_26 * V_26 ,
const struct V_1 *
V_6 ,
T_1 V_42 )
{
struct V_41 * V_41 ;
F_2 (mlxsw_sp_port_vlan, &mlxsw_sp_port->vlans_list,
list) {
if ( ! V_41 -> V_25 )
continue;
if ( V_41 -> V_25 -> V_6 !=
V_6 )
continue;
if ( V_6 -> V_11 &&
V_41 -> V_42 != V_42 )
continue;
return V_41 ;
}
return NULL ;
}
static struct V_41 *
F_31 ( struct V_26 * V_26 ,
T_1 V_43 )
{
struct V_41 * V_41 ;
F_2 (mlxsw_sp_port_vlan, &mlxsw_sp_port->vlans_list,
list) {
struct V_44 * V_45 = V_41 -> V_45 ;
if ( V_45 && F_32 ( V_45 ) == V_43 )
return V_41 ;
}
return NULL ;
}
static struct V_46 *
F_33 ( const struct V_23 * V_25 ,
T_1 V_42 )
{
struct V_46 * V_47 ;
F_2 (bridge_vlan, &bridge_port->vlans_list, list) {
if ( V_47 -> V_42 == V_42 )
return V_47 ;
}
return NULL ;
}
static struct V_46 *
F_34 ( struct V_23 * V_25 , T_1 V_42 )
{
struct V_46 * V_47 ;
V_47 = F_7 ( sizeof( * V_47 ) , V_14 ) ;
if ( ! V_47 )
return NULL ;
F_9 ( & V_47 -> V_48 ) ;
V_47 -> V_42 = V_42 ;
F_10 ( & V_47 -> V_21 , & V_25 -> V_37 ) ;
return V_47 ;
}
static void
F_35 ( struct V_46 * V_47 )
{
F_12 ( & V_47 -> V_21 ) ;
F_13 ( ! F_14 ( & V_47 -> V_48 ) ) ;
F_15 ( V_47 ) ;
}
static struct V_46 *
F_36 ( struct V_23 * V_25 , T_1 V_42 )
{
struct V_46 * V_47 ;
V_47 = F_33 ( V_25 , V_42 ) ;
if ( V_47 )
return V_47 ;
return F_34 ( V_25 , V_42 ) ;
}
static void F_37 ( struct V_46 * V_47 )
{
if ( F_14 ( & V_47 -> V_48 ) )
F_35 ( V_47 ) ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_4 * V_7 ,
unsigned long * V_49 )
{
struct V_23 * V_25 ;
V_25 = F_19 ( V_3 , V_7 ) ;
if ( F_13 ( ! V_25 ) )
return;
memcpy ( V_49 , & V_25 -> V_33 , sizeof( * V_49 ) ) ;
}
static int F_39 ( struct V_4 * V_7 ,
struct V_50 * V_51 )
{
struct V_26 * V_26 = F_40 ( V_7 ) ;
struct V_9 * V_9 = V_26 -> V_9 ;
switch ( V_51 -> V_52 ) {
case V_53 :
V_51 -> V_54 . V_55 . V_56 = sizeof( V_9 -> V_57 ) ;
memcpy ( & V_51 -> V_54 . V_55 . V_52 , & V_9 -> V_57 ,
V_51 -> V_54 . V_55 . V_56 ) ;
break;
case V_58 :
F_38 ( V_9 -> V_3 , V_51 -> V_59 ,
& V_51 -> V_54 . V_49 ) ;
break;
case V_60 :
V_51 -> V_54 . V_61 = V_34 | V_35 ;
break;
default:
return - V_62 ;
}
return 0 ;
}
static int
F_41 ( struct V_26 * V_26 ,
struct V_46 * V_47 ,
T_2 V_63 )
{
struct V_41 * V_41 ;
F_2 (mlxsw_sp_port_vlan, &bridge_vlan->port_vlan_list,
bridge_vlan_node) {
if ( V_41 -> V_26 != V_26 )
continue;
return F_42 ( V_26 ,
V_47 -> V_42 , V_63 ) ;
}
return 0 ;
}
static int F_43 ( struct V_26 * V_26 ,
struct V_64 * V_65 ,
struct V_4 * V_59 ,
T_2 V_63 )
{
struct V_23 * V_25 ;
struct V_46 * V_47 ;
int V_39 ;
if ( F_44 ( V_65 ) )
return 0 ;
V_25 = F_19 ( V_26 -> V_9 -> V_3 ,
V_59 ) ;
if ( ! V_25 )
return 0 ;
F_2 (bridge_vlan, &bridge_port->vlans_list, list) {
V_39 = F_41 ( V_26 ,
V_47 , V_63 ) ;
if ( V_39 )
goto V_66;
}
V_25 -> V_31 = V_63 ;
return 0 ;
V_66:
F_45 (bridge_vlan,
&bridge_port->vlans_list, list)
F_41 ( V_26 , V_47 ,
V_25 -> V_31 ) ;
return V_39 ;
}
static int
F_46 ( struct V_26 * V_26 ,
struct V_46 * V_47 ,
enum V_67 V_68 ,
bool V_69 )
{
struct V_41 * V_41 ;
F_2 (mlxsw_sp_port_vlan, &bridge_vlan->port_vlan_list,
bridge_vlan_node) {
if ( V_41 -> V_26 != V_26 )
continue;
return F_47 ( V_41 -> V_45 ,
V_68 ,
V_26 -> V_30 ,
V_69 ) ;
}
return 0 ;
}
static int
F_48 ( struct V_26 * V_26 ,
struct V_23 * V_25 ,
enum V_67 V_68 ,
bool V_69 )
{
struct V_46 * V_47 ;
int V_39 ;
F_2 (bridge_vlan, &bridge_port->vlans_list, list) {
V_39 = F_46 ( V_26 ,
V_47 ,
V_68 ,
V_69 ) ;
if ( V_39 )
goto V_70;
}
return 0 ;
V_70:
F_45 (bridge_vlan,
&bridge_port->vlans_list, list)
F_46 ( V_26 , V_47 ,
V_68 , ! V_69 ) ;
return V_39 ;
}
static int
F_49 ( struct V_26 * V_26 ,
struct V_46 * V_47 ,
bool V_71 )
{
struct V_41 * V_41 ;
T_1 V_42 = V_47 -> V_42 ;
F_2 (mlxsw_sp_port_vlan, &bridge_vlan->port_vlan_list,
bridge_vlan_node) {
if ( V_41 -> V_26 != V_26 )
continue;
return F_50 ( V_26 , V_42 , V_71 ) ;
}
return 0 ;
}
static int
F_51 ( struct V_26 * V_26 ,
struct V_23 * V_25 ,
bool V_71 )
{
struct V_46 * V_47 ;
int V_39 ;
F_2 (bridge_vlan, &bridge_port->vlans_list, list) {
V_39 = F_49 ( V_26 ,
V_47 , V_71 ) ;
if ( V_39 )
goto V_72;
}
return 0 ;
V_72:
F_45 (bridge_vlan,
&bridge_port->vlans_list, list)
F_49 ( V_26 ,
V_47 , ! V_71 ) ;
return V_39 ;
}
static int F_52 ( struct V_26 * V_26 ,
struct V_64 * V_65 ,
struct V_4 * V_59 ,
unsigned long V_49 )
{
struct V_23 * V_25 ;
int V_39 ;
if ( F_44 ( V_65 ) )
return 0 ;
V_25 = F_19 ( V_26 -> V_9 -> V_3 ,
V_59 ) ;
if ( ! V_25 )
return 0 ;
V_39 = F_48 ( V_26 , V_25 ,
V_73 ,
V_49 & V_35 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_51 ( V_26 , V_25 ,
V_49 & V_34 ) ;
if ( V_39 )
return V_39 ;
memcpy ( & V_25 -> V_33 , & V_49 , sizeof( V_49 ) ) ;
return 0 ;
}
static int F_53 ( struct V_9 * V_9 , T_3 V_74 )
{
char V_75 [ V_76 ] ;
int V_39 ;
F_54 ( V_75 , V_74 ) ;
V_39 = F_55 ( V_9 -> V_77 , F_56 ( V_78 ) , V_75 ) ;
if ( V_39 )
return V_39 ;
V_9 -> V_3 -> V_74 = V_74 ;
return 0 ;
}
static int F_57 ( struct V_26 * V_26 ,
struct V_64 * V_65 ,
unsigned long V_79 )
{
struct V_9 * V_9 = V_26 -> V_9 ;
unsigned long V_80 = F_58 ( V_79 ) ;
T_3 V_74 = F_59 ( V_80 ) / 1000 ;
if ( F_44 ( V_65 ) ) {
if ( V_74 < V_81 ||
V_74 > V_82 )
return - V_83 ;
else
return 0 ;
}
return F_53 ( V_9 , V_74 ) ;
}
static int F_60 ( struct V_26 * V_26 ,
struct V_64 * V_65 ,
struct V_4 * V_59 ,
bool V_11 )
{
struct V_9 * V_9 = V_26 -> V_9 ;
struct V_1 * V_6 ;
if ( ! F_44 ( V_65 ) )
return 0 ;
V_6 = F_1 ( V_9 -> V_3 , V_59 ) ;
if ( F_13 ( ! V_6 ) )
return - V_13 ;
if ( V_6 -> V_11 == V_11 )
return 0 ;
F_61 ( V_6 -> V_7 , L_2 ) ;
return - V_13 ;
}
static int F_62 ( struct V_26 * V_26 ,
struct V_64 * V_65 ,
struct V_4 * V_59 ,
bool V_84 )
{
struct V_23 * V_25 ;
int V_39 ;
if ( F_44 ( V_65 ) )
return 0 ;
V_25 = F_19 ( V_26 -> V_9 -> V_3 ,
V_59 ) ;
if ( ! V_25 )
return 0 ;
if ( ! V_25 -> V_6 -> V_16 )
goto V_85;
V_39 = F_48 ( V_26 , V_25 ,
V_86 ,
V_84 ) ;
if ( V_39 )
return V_39 ;
V_85:
V_25 -> V_87 = V_84 ;
return 0 ;
}
static int F_63 ( struct V_26 * V_26 ,
struct V_64 * V_65 ,
struct V_4 * V_59 ,
bool V_88 )
{
struct V_9 * V_9 = V_26 -> V_9 ;
struct V_1 * V_6 ;
struct V_23 * V_25 ;
int V_39 ;
if ( F_44 ( V_65 ) )
return 0 ;
V_6 = F_1 ( V_9 -> V_3 , V_59 ) ;
if ( ! V_6 )
return 0 ;
F_2 (bridge_port, &bridge_device->ports_list, list) {
enum V_67 V_68 = V_86 ;
bool V_69 = V_88 ? true : V_25 -> V_87 ;
V_39 = F_48 ( V_26 ,
V_25 ,
V_68 , V_69 ) ;
if ( V_39 )
return V_39 ;
}
V_6 -> V_16 = ! V_88 ;
return 0 ;
}
static int F_64 ( struct V_4 * V_7 ,
const struct V_50 * V_51 ,
struct V_64 * V_65 )
{
struct V_26 * V_26 = F_40 ( V_7 ) ;
int V_39 ;
switch ( V_51 -> V_52 ) {
case V_89 :
V_39 = F_43 ( V_26 , V_65 ,
V_51 -> V_59 ,
V_51 -> V_54 . V_31 ) ;
break;
case V_58 :
V_39 = F_52 ( V_26 , V_65 ,
V_51 -> V_59 ,
V_51 -> V_54 . V_49 ) ;
break;
case V_90 :
V_39 = F_57 ( V_26 , V_65 ,
V_51 -> V_54 . V_74 ) ;
break;
case V_91 :
V_39 = F_60 ( V_26 , V_65 ,
V_51 -> V_59 ,
V_51 -> V_54 . V_92 ) ;
break;
case V_93 :
V_39 = F_62 ( V_26 , V_65 ,
V_51 -> V_59 ,
V_51 -> V_54 . V_87 ) ;
break;
case V_94 :
V_39 = F_63 ( V_26 , V_65 ,
V_51 -> V_59 ,
V_51 -> V_54 . V_88 ) ;
break;
default:
V_39 = - V_62 ;
break;
}
return V_39 ;
}
static bool F_65 ( const struct V_23 * V_25 )
{
const struct V_1 * V_6 ;
V_6 = V_25 -> V_6 ;
return ! V_6 -> V_16 ? true : V_25 -> V_87 ;
}
static int
F_66 ( struct V_41 * V_41 ,
struct V_23 * V_25 )
{
struct V_26 * V_26 = V_41 -> V_26 ;
struct V_1 * V_6 ;
T_2 V_30 = V_26 -> V_30 ;
T_1 V_42 = V_41 -> V_42 ;
struct V_44 * V_45 ;
int V_39 ;
V_6 = V_25 -> V_6 ;
V_45 = V_6 -> V_18 -> V_95 ( V_6 , V_42 ) ;
if ( F_27 ( V_45 ) )
return F_67 ( V_45 ) ;
V_39 = F_47 ( V_45 , V_73 , V_30 ,
V_25 -> V_33 & V_35 ) ;
if ( V_39 )
goto V_96;
V_39 = F_47 ( V_45 , V_86 , V_30 ,
F_65 ( V_25 ) ) ;
if ( V_39 )
goto V_97;
V_39 = F_47 ( V_45 , V_98 , V_30 ,
true ) ;
if ( V_39 )
goto V_99;
V_39 = F_68 ( V_45 , V_26 , V_42 ) ;
if ( V_39 )
goto V_100;
V_41 -> V_45 = V_45 ;
return 0 ;
V_100:
F_47 ( V_45 , V_98 , V_30 , false ) ;
V_99:
F_47 ( V_45 , V_86 , V_30 , false ) ;
V_97:
F_47 ( V_45 , V_73 , V_30 , false ) ;
V_96:
F_69 ( V_45 ) ;
return V_39 ;
}
static void
F_70 ( struct V_41 * V_41 )
{
struct V_26 * V_26 = V_41 -> V_26 ;
struct V_44 * V_45 = V_41 -> V_45 ;
T_2 V_30 = V_26 -> V_30 ;
T_1 V_42 = V_41 -> V_42 ;
V_41 -> V_45 = NULL ;
F_71 ( V_45 , V_26 , V_42 ) ;
F_47 ( V_45 , V_98 , V_30 , false ) ;
F_47 ( V_45 , V_86 , V_30 , false ) ;
F_47 ( V_45 , V_73 , V_30 , false ) ;
F_69 ( V_45 ) ;
}
static T_1
F_72 ( const struct V_26 * V_26 ,
T_1 V_42 , bool V_101 )
{
if ( V_101 )
return V_42 ;
else if ( V_26 -> V_102 == V_42 )
return 0 ;
else
return V_26 -> V_102 ;
}
static int
F_73 ( struct V_41 * V_41 ,
struct V_23 * V_25 )
{
struct V_26 * V_26 = V_41 -> V_26 ;
struct V_46 * V_47 ;
T_1 V_42 = V_41 -> V_42 ;
int V_39 ;
if ( V_41 -> V_25 )
return 0 ;
V_39 = F_66 ( V_41 , V_25 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_50 ( V_26 , V_42 ,
V_25 -> V_33 & V_34 ) ;
if ( V_39 )
goto V_103;
V_39 = F_42 ( V_26 , V_42 ,
V_25 -> V_31 ) ;
if ( V_39 )
goto V_104;
V_47 = F_36 ( V_25 , V_42 ) ;
if ( ! V_47 ) {
V_39 = - V_15 ;
goto V_105;
}
F_10 ( & V_41 -> V_106 ,
& V_47 -> V_48 ) ;
F_26 ( V_26 -> V_9 -> V_3 ,
V_25 -> V_7 ) ;
V_41 -> V_25 = V_25 ;
return 0 ;
V_105:
F_42 ( V_26 , V_42 , V_32 ) ;
V_104:
F_50 ( V_26 , V_42 , false ) ;
V_103:
F_70 ( V_41 ) ;
return V_39 ;
}
void
F_74 ( struct V_41 * V_41 )
{
struct V_26 * V_26 = V_41 -> V_26 ;
struct V_44 * V_45 = V_41 -> V_45 ;
struct V_46 * V_47 ;
struct V_23 * V_25 ;
T_1 V_42 = V_41 -> V_42 ;
bool V_107 ;
if ( F_13 ( F_75 ( V_45 ) != V_108 &&
F_75 ( V_45 ) != V_109 ) )
return;
V_25 = V_41 -> V_25 ;
V_47 = F_33 ( V_25 , V_42 ) ;
V_107 = F_76 ( & V_47 -> V_48 ) ;
F_12 ( & V_41 -> V_106 ) ;
F_37 ( V_47 ) ;
F_42 ( V_26 , V_42 , V_32 ) ;
F_50 ( V_26 , V_42 , false ) ;
if ( V_107 )
F_77 ( V_26 -> V_9 ,
V_25 ,
F_32 ( V_45 ) ) ;
F_70 ( V_41 ) ;
F_29 ( V_26 -> V_9 -> V_3 , V_25 ) ;
V_41 -> V_25 = NULL ;
}
static int
F_78 ( struct V_26 * V_26 ,
struct V_23 * V_25 ,
T_1 V_42 , bool V_110 , bool V_101 )
{
T_1 V_102 = F_72 ( V_26 , V_42 , V_101 ) ;
struct V_41 * V_41 ;
T_1 V_111 = V_26 -> V_102 ;
int V_39 ;
V_41 = F_79 ( V_26 , V_42 ) ;
if ( F_27 ( V_41 ) )
return F_67 ( V_41 ) ;
V_39 = F_80 ( V_26 , V_42 , V_42 , true ,
V_110 ) ;
if ( V_39 )
goto V_112;
V_39 = F_81 ( V_26 , V_102 ) ;
if ( V_39 )
goto V_113;
V_39 = F_73 ( V_41 , V_25 ) ;
if ( V_39 )
goto V_114;
return 0 ;
V_114:
F_81 ( V_26 , V_111 ) ;
V_113:
F_80 ( V_26 , V_42 , V_42 , false , false ) ;
V_112:
F_82 ( V_41 ) ;
return V_39 ;
}
static int F_83 ( struct V_26 * V_26 ,
const struct V_115 * V_116 ,
struct V_64 * V_65 )
{
bool V_117 = V_116 -> V_33 & V_118 ;
bool V_119 = V_116 -> V_33 & V_120 ;
struct V_9 * V_9 = V_26 -> V_9 ;
struct V_4 * V_59 = V_116 -> V_121 . V_59 ;
struct V_23 * V_25 ;
T_1 V_42 ;
if ( F_44 ( V_65 ) )
return 0 ;
V_25 = F_19 ( V_9 -> V_3 , V_59 ) ;
if ( F_13 ( ! V_25 ) )
return - V_13 ;
if ( ! V_25 -> V_6 -> V_11 )
return 0 ;
for ( V_42 = V_116 -> V_122 ; V_42 <= V_116 -> V_123 ; V_42 ++ ) {
int V_39 ;
V_39 = F_78 ( V_26 , V_25 ,
V_42 , V_117 ,
V_119 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
static enum V_124 F_84 ( bool V_27 )
{
return V_27 ? V_125 :
V_126 ;
}
static int
F_77 ( struct V_9 * V_9 ,
struct V_23 * V_25 ,
T_1 V_43 )
{
bool V_27 = V_25 -> V_27 ;
char V_127 [ V_128 ] ;
T_1 V_29 ;
V_29 = V_27 ? V_25 -> V_28 : V_25 -> V_29 ;
F_85 ( V_127 , F_84 ( V_27 ) ) ;
F_86 ( V_127 , V_43 ) ;
F_87 ( V_127 , V_29 ) ;
return F_55 ( V_9 -> V_77 , F_56 ( V_129 ) , V_127 ) ;
}
static enum V_130 F_88 ( bool V_131 )
{
return V_131 ? V_132 :
V_133 ;
}
static enum V_134 F_89 ( bool V_135 )
{
return V_135 ? V_136 :
V_137 ;
}
static int F_90 ( struct V_9 * V_9 , T_2 V_30 ,
const char * V_138 , T_1 V_45 , bool V_135 ,
enum V_139 V_140 ,
bool V_131 )
{
char * V_141 ;
int V_39 ;
V_141 = F_91 ( V_142 , V_14 ) ;
if ( ! V_141 )
return - V_15 ;
F_92 ( V_141 , F_89 ( V_135 ) , 0 ) ;
F_93 ( V_141 , 0 , F_88 ( V_131 ) ,
V_138 , V_45 , V_140 , V_30 ) ;
V_39 = F_55 ( V_9 -> V_77 , F_56 ( V_143 ) , V_141 ) ;
F_15 ( V_141 ) ;
return V_39 ;
}
static int F_94 ( struct V_9 * V_9 , T_2 V_30 ,
const char * V_138 , T_1 V_45 , bool V_135 ,
bool V_131 )
{
return F_90 ( V_9 , V_30 , V_138 , V_45 , V_135 ,
V_144 , V_131 ) ;
}
int F_95 ( struct V_9 * V_9 , const char * V_138 , T_1 V_45 ,
bool V_135 )
{
return F_90 ( V_9 , 0 , V_138 , V_45 , V_135 ,
V_145 ,
false ) ;
}
static int F_96 ( struct V_9 * V_9 , T_1 V_28 ,
const char * V_138 , T_1 V_45 , T_1 V_146 ,
bool V_135 , bool V_131 )
{
char * V_141 ;
int V_39 ;
V_141 = F_91 ( V_142 , V_14 ) ;
if ( ! V_141 )
return - V_15 ;
F_92 ( V_141 , F_89 ( V_135 ) , 0 ) ;
F_97 ( V_141 , 0 , F_88 ( V_131 ) ,
V_138 , V_45 , V_144 ,
V_146 , V_28 ) ;
V_39 = F_55 ( V_9 -> V_77 , F_56 ( V_143 ) , V_141 ) ;
F_15 ( V_141 ) ;
return V_39 ;
}
static int
F_98 ( struct V_26 * V_26 ,
struct V_147 * V_148 , bool V_135 )
{
struct V_9 * V_9 = V_26 -> V_9 ;
struct V_4 * V_59 = V_148 -> V_149 . V_7 ;
struct V_41 * V_41 ;
struct V_1 * V_6 ;
struct V_23 * V_25 ;
T_1 V_43 , V_42 ;
V_25 = F_19 ( V_9 -> V_3 , V_59 ) ;
if ( ! V_25 )
return - V_13 ;
V_6 = V_25 -> V_6 ;
V_41 = F_30 ( V_26 ,
V_6 ,
V_148 -> V_42 ) ;
if ( ! V_41 )
return 0 ;
V_43 = F_32 ( V_41 -> V_45 ) ;
V_42 = V_41 -> V_42 ;
if ( ! V_25 -> V_27 )
return F_94 ( V_9 ,
V_25 -> V_29 ,
V_148 -> V_150 , V_43 ,
V_135 , false ) ;
else
return F_96 ( V_9 ,
V_25 -> V_28 ,
V_148 -> V_150 , V_43 ,
V_42 , V_135 , false ) ;
}
static int F_99 ( struct V_9 * V_9 , const char * V_150 ,
T_1 V_45 , T_1 V_151 , bool V_135 )
{
char * V_141 ;
int V_39 ;
V_141 = F_91 ( V_142 , V_14 ) ;
if ( ! V_141 )
return - V_15 ;
F_92 ( V_141 , F_89 ( V_135 ) , 0 ) ;
F_100 ( V_141 , 0 , V_150 , V_45 ,
V_144 , V_151 ) ;
V_39 = F_55 ( V_9 -> V_77 , F_56 ( V_143 ) , V_141 ) ;
F_15 ( V_141 ) ;
return V_39 ;
}
static int F_101 ( struct V_26 * V_26 , T_1 V_151 ,
bool V_152 , bool V_153 )
{
struct V_9 * V_9 = V_26 -> V_9 ;
char * V_154 ;
int V_39 , V_155 ;
V_154 = F_91 ( V_156 , V_14 ) ;
if ( ! V_154 )
return - V_15 ;
F_102 ( V_154 , V_151 , V_26 -> V_30 , V_152 ) ;
if ( V_153 ) {
for ( V_155 = 1 ; V_155 < F_103 ( V_9 -> V_77 ) ; V_155 ++ )
if ( V_9 -> V_157 [ V_155 ] )
F_104 ( V_154 , V_155 , 1 ) ;
}
V_39 = F_55 ( V_9 -> V_77 , F_56 ( V_158 ) , V_154 ) ;
F_15 ( V_154 ) ;
return V_39 ;
}
static struct V_159 * F_105 ( struct V_9 * V_9 ,
const unsigned char * V_150 ,
T_1 V_45 )
{
struct V_159 * V_151 ;
F_2 (mid, &mlxsw_sp->bridge->mids_list, list) {
if ( F_106 ( V_151 -> V_150 , V_150 ) && V_151 -> V_45 == V_45 )
return V_151 ;
}
return NULL ;
}
static struct V_159 * F_107 ( struct V_9 * V_9 ,
const unsigned char * V_150 ,
T_1 V_45 )
{
struct V_159 * V_151 ;
T_1 V_160 ;
V_160 = F_108 ( V_9 -> V_3 -> V_161 ,
V_162 ) ;
if ( V_160 == V_162 )
return NULL ;
V_151 = F_7 ( sizeof( * V_151 ) , V_14 ) ;
if ( ! V_151 )
return NULL ;
F_109 ( V_160 , V_9 -> V_3 -> V_161 ) ;
F_110 ( V_151 -> V_150 , V_150 ) ;
V_151 -> V_45 = V_45 ;
V_151 -> V_151 = V_160 ;
V_151 -> V_38 = 0 ;
F_111 ( & V_151 -> V_21 , & V_9 -> V_3 -> V_163 ) ;
return V_151 ;
}
static int F_112 ( struct V_9 * V_9 ,
struct V_159 * V_151 )
{
if ( -- V_151 -> V_38 == 0 ) {
F_12 ( & V_151 -> V_21 ) ;
F_113 ( V_151 -> V_151 , V_9 -> V_3 -> V_161 ) ;
F_15 ( V_151 ) ;
return 1 ;
}
return 0 ;
}
static int F_114 ( struct V_26 * V_26 ,
const struct V_164 * V_165 ,
struct V_64 * V_65 )
{
struct V_9 * V_9 = V_26 -> V_9 ;
struct V_4 * V_59 = V_165 -> V_121 . V_59 ;
struct V_41 * V_41 ;
struct V_4 * V_7 = V_26 -> V_7 ;
struct V_1 * V_6 ;
struct V_23 * V_25 ;
struct V_159 * V_151 ;
T_1 V_43 ;
int V_39 = 0 ;
if ( F_44 ( V_65 ) )
return 0 ;
V_25 = F_19 ( V_9 -> V_3 , V_59 ) ;
if ( ! V_25 )
return 0 ;
V_6 = V_25 -> V_6 ;
V_41 = F_30 ( V_26 ,
V_6 ,
V_165 -> V_42 ) ;
if ( ! V_41 )
return 0 ;
V_43 = F_32 ( V_41 -> V_45 ) ;
V_151 = F_105 ( V_9 , V_165 -> V_150 , V_43 ) ;
if ( ! V_151 ) {
V_151 = F_107 ( V_9 , V_165 -> V_150 , V_43 ) ;
if ( ! V_151 ) {
F_61 ( V_7 , L_3 ) ;
return - V_15 ;
}
}
V_151 -> V_38 ++ ;
V_39 = F_101 ( V_26 , V_151 -> V_151 , true ,
V_151 -> V_38 == 1 ) ;
if ( V_39 ) {
F_61 ( V_7 , L_4 ) ;
goto V_166;
}
if ( V_151 -> V_38 == 1 ) {
V_39 = F_99 ( V_9 , V_165 -> V_150 , V_43 ,
V_151 -> V_151 , true ) ;
if ( V_39 ) {
F_61 ( V_7 , L_5 ) ;
goto V_166;
}
}
return 0 ;
V_166:
F_112 ( V_9 , V_151 ) ;
return V_39 ;
}
static int F_115 ( struct V_4 * V_7 ,
const struct V_167 * V_121 ,
struct V_64 * V_65 )
{
struct V_26 * V_26 = F_40 ( V_7 ) ;
int V_39 = 0 ;
switch ( V_121 -> V_52 ) {
case V_168 :
V_39 = F_83 ( V_26 ,
F_116 ( V_121 ) ,
V_65 ) ;
break;
case V_169 :
V_39 = F_114 ( V_26 ,
F_117 ( V_121 ) ,
V_65 ) ;
break;
default:
V_39 = - V_62 ;
break;
}
return V_39 ;
}
static void
F_118 ( struct V_26 * V_26 ,
struct V_23 * V_25 , T_1 V_42 )
{
T_1 V_102 = V_26 -> V_102 == V_42 ? 0 : V_42 ;
struct V_41 * V_41 ;
V_41 = F_119 ( V_26 , V_42 ) ;
if ( F_13 ( ! V_41 ) )
return;
F_74 ( V_41 ) ;
F_81 ( V_26 , V_102 ) ;
F_80 ( V_26 , V_42 , V_42 , false , false ) ;
F_82 ( V_41 ) ;
}
static int F_120 ( struct V_26 * V_26 ,
const struct V_115 * V_116 )
{
struct V_9 * V_9 = V_26 -> V_9 ;
struct V_4 * V_59 = V_116 -> V_121 . V_59 ;
struct V_23 * V_25 ;
T_1 V_42 ;
V_25 = F_19 ( V_9 -> V_3 , V_59 ) ;
if ( F_13 ( ! V_25 ) )
return - V_13 ;
if ( ! V_25 -> V_6 -> V_11 )
return 0 ;
for ( V_42 = V_116 -> V_122 ; V_42 <= V_116 -> V_123 ; V_42 ++ )
F_118 ( V_26 , V_25 , V_42 ) ;
return 0 ;
}
static int F_121 ( struct V_26 * V_26 ,
const struct V_164 * V_165 )
{
struct V_9 * V_9 = V_26 -> V_9 ;
struct V_4 * V_59 = V_165 -> V_121 . V_59 ;
struct V_41 * V_41 ;
struct V_1 * V_6 ;
struct V_4 * V_7 = V_26 -> V_7 ;
struct V_23 * V_25 ;
struct V_159 * V_151 ;
T_1 V_43 ;
T_1 V_160 ;
int V_39 = 0 ;
V_25 = F_19 ( V_9 -> V_3 , V_59 ) ;
if ( ! V_25 )
return 0 ;
V_6 = V_25 -> V_6 ;
V_41 = F_30 ( V_26 ,
V_6 ,
V_165 -> V_42 ) ;
if ( ! V_41 )
return 0 ;
V_43 = F_32 ( V_41 -> V_45 ) ;
V_151 = F_105 ( V_9 , V_165 -> V_150 , V_43 ) ;
if ( ! V_151 ) {
F_61 ( V_7 , L_6 ) ;
return - V_13 ;
}
V_39 = F_101 ( V_26 , V_151 -> V_151 , false , false ) ;
if ( V_39 )
F_61 ( V_7 , L_7 ) ;
V_160 = V_151 -> V_151 ;
if ( F_112 ( V_9 , V_151 ) ) {
V_39 = F_99 ( V_9 , V_165 -> V_150 , V_43 ,
V_160 , false ) ;
if ( V_39 )
F_61 ( V_7 , L_8 ) ;
}
return V_39 ;
}
static int F_122 ( struct V_4 * V_7 ,
const struct V_167 * V_121 )
{
struct V_26 * V_26 = F_40 ( V_7 ) ;
int V_39 = 0 ;
switch ( V_121 -> V_52 ) {
case V_168 :
V_39 = F_120 ( V_26 ,
F_116 ( V_121 ) ) ;
break;
case V_169 :
V_39 = F_121 ( V_26 ,
F_117 ( V_121 ) ) ;
break;
default:
V_39 = - V_62 ;
break;
}
return V_39 ;
}
static struct V_26 * F_123 ( struct V_9 * V_9 ,
T_1 V_28 )
{
struct V_26 * V_26 ;
T_4 V_170 ;
int V_155 ;
V_170 = F_124 ( V_9 -> V_77 ,
V_171 ) ;
for ( V_155 = 0 ; V_155 < V_170 ; V_155 ++ ) {
V_26 = F_125 ( V_9 , V_28 , V_155 ) ;
if ( V_26 )
return V_26 ;
}
return NULL ;
}
static int
F_126 ( struct V_1 * V_6 ,
struct V_23 * V_25 ,
struct V_26 * V_26 )
{
struct V_41 * V_41 ;
if ( F_127 ( V_25 -> V_7 ) )
return - V_13 ;
V_41 = F_119 ( V_26 , 1 ) ;
if ( F_13 ( ! V_41 ) )
return - V_13 ;
F_82 ( V_41 ) ;
return 0 ;
}
static void
F_128 ( struct V_1 * V_6 ,
struct V_23 * V_25 ,
struct V_26 * V_26 )
{
F_79 ( V_26 , 1 ) ;
F_81 ( V_26 , 1 ) ;
}
static struct V_44 *
F_129 ( struct V_1 * V_6 ,
T_1 V_42 )
{
struct V_9 * V_9 = F_25 ( V_6 -> V_7 ) ;
return F_130 ( V_9 , V_42 ) ;
}
static bool
F_131 ( const struct V_26 * V_26 ,
const struct V_4 * V_5 )
{
struct V_41 * V_41 ;
F_2 (mlxsw_sp_port_vlan, &mlxsw_sp_port->vlans_list,
list) {
if ( V_41 -> V_25 &&
V_41 -> V_25 -> V_6 -> V_7 ==
V_5 )
return true ;
}
return false ;
}
static int
F_132 ( struct V_1 * V_6 ,
struct V_23 * V_25 ,
struct V_26 * V_26 )
{
struct V_41 * V_41 ;
T_1 V_42 ;
if ( ! F_127 ( V_25 -> V_7 ) )
return - V_13 ;
V_42 = F_133 ( V_25 -> V_7 ) ;
V_41 = F_119 ( V_26 , V_42 ) ;
if ( F_13 ( ! V_41 ) )
return - V_13 ;
if ( F_131 ( V_26 , V_6 -> V_7 ) ) {
F_61 ( V_26 -> V_7 , L_9 ) ;
return - V_13 ;
}
if ( V_41 -> V_45 )
F_134 ( V_41 ) ;
return F_73 ( V_41 , V_25 ) ;
}
static void
F_135 ( struct V_1 * V_6 ,
struct V_23 * V_25 ,
struct V_26 * V_26 )
{
struct V_41 * V_41 ;
T_1 V_42 = F_133 ( V_25 -> V_7 ) ;
V_41 = F_119 ( V_26 , V_42 ) ;
if ( F_13 ( ! V_41 ) )
return;
F_74 ( V_41 ) ;
}
static struct V_44 *
F_136 ( struct V_1 * V_6 ,
T_1 V_42 )
{
struct V_9 * V_9 = F_25 ( V_6 -> V_7 ) ;
return F_137 ( V_9 , V_6 -> V_7 -> V_172 ) ;
}
int F_138 ( struct V_26 * V_26 ,
struct V_4 * V_24 ,
struct V_4 * V_5 )
{
struct V_9 * V_9 = V_26 -> V_9 ;
struct V_1 * V_6 ;
struct V_23 * V_25 ;
int V_39 ;
V_25 = F_26 ( V_9 -> V_3 , V_24 ) ;
if ( F_27 ( V_25 ) )
return F_67 ( V_25 ) ;
V_6 = V_25 -> V_6 ;
V_39 = V_6 -> V_18 -> V_173 ( V_6 , V_25 ,
V_26 ) ;
if ( V_39 )
goto V_174;
return 0 ;
V_174:
F_29 ( V_9 -> V_3 , V_25 ) ;
return V_39 ;
}
void F_139 ( struct V_26 * V_26 ,
struct V_4 * V_24 ,
struct V_4 * V_5 )
{
struct V_9 * V_9 = V_26 -> V_9 ;
struct V_1 * V_6 ;
struct V_23 * V_25 ;
V_6 = F_1 ( V_9 -> V_3 , V_5 ) ;
if ( ! V_6 )
return;
V_25 = F_18 ( V_6 , V_24 ) ;
if ( ! V_25 )
return;
V_6 -> V_18 -> V_175 ( V_6 , V_25 ,
V_26 ) ;
F_29 ( V_9 -> V_3 , V_25 ) ;
}
static void
F_140 ( enum V_176 type ,
const char * V_138 , T_1 V_42 ,
struct V_4 * V_7 )
{
struct V_147 V_149 ;
V_149 . V_150 = V_138 ;
V_149 . V_42 = V_42 ;
F_141 ( type , V_7 , & V_149 . V_149 ) ;
}
static void F_142 ( struct V_9 * V_9 ,
char * V_177 , int V_178 ,
bool V_135 )
{
struct V_41 * V_41 ;
struct V_1 * V_6 ;
struct V_23 * V_25 ;
struct V_26 * V_26 ;
enum V_176 type ;
char V_138 [ V_179 ] ;
T_2 V_30 ;
T_1 V_42 , V_45 ;
bool V_180 = true ;
int V_39 ;
F_143 ( V_177 , V_178 , V_138 , & V_45 , & V_30 ) ;
V_26 = V_9 -> V_157 [ V_30 ] ;
if ( ! V_26 ) {
F_144 ( V_9 -> V_10 -> V_7 , L_10 ) ;
goto V_181;
}
V_41 = F_31 ( V_26 , V_45 ) ;
if ( ! V_41 ) {
F_61 ( V_26 -> V_7 , L_11 ) ;
goto V_181;
}
V_25 = V_41 -> V_25 ;
if ( ! V_25 ) {
F_61 ( V_26 -> V_7 , L_12 ) ;
goto V_181;
}
V_6 = V_25 -> V_6 ;
V_42 = V_6 -> V_11 ? V_41 -> V_42 : 0 ;
V_182:
V_39 = F_94 ( V_9 , V_30 , V_138 , V_45 ,
V_135 , true ) ;
if ( V_39 ) {
F_144 ( V_9 -> V_10 -> V_7 , L_13 ) ;
return;
}
if ( ! V_180 )
return;
type = V_135 ? V_183 : V_184 ;
F_140 ( type , V_138 , V_42 , V_25 -> V_7 ) ;
return;
V_181:
V_135 = false ;
V_180 = false ;
goto V_182;
}
static void F_145 ( struct V_9 * V_9 ,
char * V_177 , int V_178 ,
bool V_135 )
{
struct V_41 * V_41 ;
struct V_1 * V_6 ;
struct V_23 * V_25 ;
struct V_26 * V_26 ;
enum V_176 type ;
char V_138 [ V_179 ] ;
T_1 V_146 = 0 ;
T_1 V_28 ;
T_1 V_42 , V_45 ;
bool V_180 = true ;
int V_39 ;
F_146 ( V_177 , V_178 , V_138 , & V_45 , & V_28 ) ;
V_26 = F_123 ( V_9 , V_28 ) ;
if ( ! V_26 ) {
F_144 ( V_9 -> V_10 -> V_7 , L_14 ) ;
goto V_181;
}
V_41 = F_31 ( V_26 , V_45 ) ;
if ( ! V_41 ) {
F_61 ( V_26 -> V_7 , L_11 ) ;
goto V_181;
}
V_25 = V_41 -> V_25 ;
if ( ! V_25 ) {
F_61 ( V_26 -> V_7 , L_12 ) ;
goto V_181;
}
V_6 = V_25 -> V_6 ;
V_42 = V_6 -> V_11 ? V_41 -> V_42 : 0 ;
V_146 = V_41 -> V_42 ;
V_182:
V_39 = F_96 ( V_9 , V_28 , V_138 , V_45 , V_146 ,
V_135 , true ) ;
if ( V_39 ) {
F_144 ( V_9 -> V_10 -> V_7 , L_13 ) ;
return;
}
if ( ! V_180 )
return;
type = V_135 ? V_183 : V_184 ;
F_140 ( type , V_138 , V_42 , V_25 -> V_7 ) ;
return;
V_181:
V_135 = false ;
V_180 = false ;
goto V_182;
}
static void F_147 ( struct V_9 * V_9 ,
char * V_177 , int V_178 )
{
switch ( F_148 ( V_177 , V_178 ) ) {
case V_185 :
F_142 ( V_9 , V_177 ,
V_178 , true ) ;
break;
case V_186 :
F_142 ( V_9 , V_177 ,
V_178 , false ) ;
break;
case V_187 :
F_145 ( V_9 , V_177 ,
V_178 , true ) ;
break;
case V_188 :
F_145 ( V_9 , V_177 ,
V_178 , false ) ;
break;
}
}
static void F_149 ( struct V_9 * V_9 )
{
struct V_2 * V_3 = V_9 -> V_3 ;
F_150 ( & V_3 -> V_189 . V_190 ,
F_151 ( V_3 -> V_189 . V_191 ) ) ;
}
static void F_152 ( struct V_192 * V_193 )
{
struct V_2 * V_3 ;
struct V_9 * V_9 ;
char * V_177 ;
T_2 V_194 ;
int V_155 ;
int V_39 ;
V_177 = F_91 ( V_195 , V_14 ) ;
if ( ! V_177 )
return;
V_3 = F_153 ( V_193 , struct V_2 , V_189 . V_190 . V_193 ) ;
V_9 = V_3 -> V_9 ;
F_154 () ;
F_155 ( V_177 ) ;
V_39 = F_156 ( V_9 -> V_77 , F_56 ( V_196 ) , V_177 ) ;
if ( V_39 ) {
F_144 ( V_9 -> V_10 -> V_7 , L_15 ) ;
goto V_85;
}
V_194 = F_157 ( V_177 ) ;
for ( V_155 = 0 ; V_155 < V_194 ; V_155 ++ )
F_147 ( V_9 , V_177 , V_155 ) ;
V_85:
F_158 () ;
F_15 ( V_177 ) ;
F_149 ( V_9 ) ;
}
static void F_159 ( struct V_192 * V_193 )
{
struct F_159 * V_197 =
F_153 ( V_193 , struct F_159 , V_193 ) ;
struct V_4 * V_7 = V_197 -> V_7 ;
struct V_147 * V_148 ;
struct V_26 * V_26 ;
int V_39 ;
F_154 () ;
V_26 = F_22 ( V_7 ) ;
if ( ! V_26 )
goto V_85;
switch ( V_197 -> V_198 ) {
case V_199 :
V_148 = & V_197 -> V_148 ;
V_39 = F_98 ( V_26 , V_148 , true ) ;
if ( V_39 )
break;
F_140 ( V_200 ,
V_148 -> V_150 ,
V_148 -> V_42 , V_7 ) ;
break;
case V_201 :
V_148 = & V_197 -> V_148 ;
F_98 ( V_26 , V_148 , false ) ;
break;
}
V_85:
F_158 () ;
F_15 ( V_197 -> V_148 . V_150 ) ;
F_15 ( V_197 ) ;
F_160 ( V_7 ) ;
}
static int F_161 ( struct V_202 * V_203 ,
unsigned long V_198 , void * V_204 )
{
struct V_4 * V_7 = F_162 ( V_204 ) ;
struct F_159 * V_197 ;
struct V_147 * V_148 = V_204 ;
if ( ! F_163 ( V_7 ) )
return V_205 ;
V_197 = F_7 ( sizeof( * V_197 ) , V_206 ) ;
if ( ! V_197 )
return V_207 ;
F_164 ( & V_197 -> V_193 , F_159 ) ;
V_197 -> V_7 = V_7 ;
V_197 -> V_198 = V_198 ;
switch ( V_198 ) {
case V_199 :
case V_201 :
memcpy ( & V_197 -> V_148 , V_204 ,
sizeof( V_197 -> V_148 ) ) ;
V_197 -> V_148 . V_150 = F_7 ( V_179 , V_206 ) ;
if ( ! V_197 -> V_148 . V_150 )
goto V_208;
F_110 ( ( T_2 * ) V_197 -> V_148 . V_150 ,
V_148 -> V_150 ) ;
F_165 ( V_7 ) ;
break;
default:
F_15 ( V_197 ) ;
return V_205 ;
}
F_166 ( & V_197 -> V_193 ) ;
return V_205 ;
V_208:
F_15 ( V_197 ) ;
return V_207 ;
}
static int F_167 ( struct V_9 * V_9 )
{
struct V_2 * V_3 = V_9 -> V_3 ;
int V_39 ;
V_39 = F_53 ( V_9 , V_209 ) ;
if ( V_39 ) {
F_5 ( V_9 -> V_10 -> V_7 , L_16 ) ;
return V_39 ;
}
V_39 = F_168 ( & V_210 ) ;
if ( V_39 ) {
F_5 ( V_9 -> V_10 -> V_7 , L_17 ) ;
return V_39 ;
}
F_169 ( & V_3 -> V_189 . V_190 , F_152 ) ;
V_3 -> V_189 . V_191 = V_211 ;
F_149 ( V_9 ) ;
return 0 ;
}
static void F_170 ( struct V_9 * V_9 )
{
F_171 ( & V_9 -> V_3 -> V_189 . V_190 ) ;
F_172 ( & V_210 ) ;
}
static void F_173 ( struct V_9 * V_9 )
{
struct V_159 * V_151 , * V_212 ;
F_174 (mid, tmp, &mlxsw_sp->bridge->mids_list, list) {
F_12 ( & V_151 -> V_21 ) ;
F_113 ( V_151 -> V_151 , V_9 -> V_3 -> V_161 ) ;
F_15 ( V_151 ) ;
}
}
int F_175 ( struct V_9 * V_9 )
{
struct V_2 * V_3 ;
V_3 = F_7 ( sizeof( * V_9 -> V_3 ) , V_14 ) ;
if ( ! V_3 )
return - V_15 ;
V_9 -> V_3 = V_3 ;
V_3 -> V_9 = V_9 ;
F_9 ( & V_9 -> V_3 -> V_22 ) ;
F_9 ( & V_9 -> V_3 -> V_163 ) ;
V_3 -> V_19 = & V_213 ;
V_3 -> V_20 = & V_214 ;
return F_167 ( V_9 ) ;
}
void F_176 ( struct V_9 * V_9 )
{
F_170 ( V_9 ) ;
F_173 ( V_9 ) ;
F_13 ( ! F_14 ( & V_9 -> V_3 -> V_22 ) ) ;
F_15 ( V_9 -> V_3 ) ;
}
void F_177 ( struct V_26 * V_26 )
{
V_26 -> V_7 -> V_215 = & V_216 ;
}
void F_178 ( struct V_26 * V_26 )
{
}
