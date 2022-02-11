static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
switch ( V_4 -> V_7 ) {
case V_8 :
V_4 -> V_9 . V_10 . V_11 = sizeof( V_6 -> V_12 ) ;
memcpy ( & V_4 -> V_9 . V_10 . V_7 , & V_6 -> V_12 ,
V_4 -> V_9 . V_10 . V_11 ) ;
break;
case V_13 :
V_4 -> V_9 . V_14 =
( V_5 -> V_15 ? V_16 : 0 ) |
( V_5 -> V_17 ? V_18 : 0 ) |
( V_5 -> V_19 ? V_20 : 0 ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_3 ( struct V_5 * V_5 ,
T_1 V_22 )
{
struct V_6 * V_6 = V_5 -> V_6 ;
enum V_23 V_24 ;
char * V_25 ;
T_2 V_26 ;
int V_27 ;
switch ( V_22 ) {
case V_28 :
case V_29 :
V_24 = V_30 ;
break;
case V_31 :
case V_32 :
V_24 = V_33 ;
break;
case V_34 :
V_24 = V_35 ;
break;
default:
F_4 () ;
}
V_25 = F_5 ( V_36 , V_37 ) ;
if ( ! V_25 )
return - V_38 ;
F_6 ( V_25 , V_5 -> V_39 ) ;
F_7 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID)
F_8 ( V_25 , V_26 , V_24 ) ;
V_27 = F_9 ( V_6 -> V_40 , F_10 ( V_41 ) , V_25 ) ;
F_11 ( V_25 ) ;
return V_27 ;
}
static int F_12 ( struct V_5 * V_5 ,
struct V_42 * V_43 ,
T_1 V_22 )
{
if ( F_13 ( V_43 ) )
return 0 ;
V_5 -> V_44 = V_22 ;
return F_3 ( V_5 , V_22 ) ;
}
static int F_14 ( struct V_5 * V_5 ,
T_2 V_45 , T_2 V_46 , bool V_47 ,
bool V_48 )
{
struct V_6 * V_6 = V_5 -> V_6 ;
T_2 V_49 = V_46 - V_45 + 1 ;
char * V_50 ;
int V_27 ;
V_50 = F_5 ( V_51 , V_37 ) ;
if ( ! V_50 )
return - V_38 ;
F_15 ( V_50 , V_52 , V_45 ,
V_53 , V_49 ,
V_5 -> V_39 , V_47 ) ;
V_27 = F_9 ( V_6 -> V_40 , F_10 ( V_54 ) , V_50 ) ;
if ( V_27 )
goto V_55;
if ( V_48 )
goto V_55;
F_15 ( V_50 , V_56 , V_45 ,
V_53 , V_49 ,
V_5 -> V_39 , V_47 ) ;
V_27 = F_9 ( V_6 -> V_40 , F_10 ( V_54 ) , V_50 ) ;
V_55:
F_11 ( V_50 ) ;
return V_27 ;
}
static int F_16 ( struct V_5 * V_5 ,
bool V_47 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
T_2 V_26 , V_57 ;
int V_27 ;
F_7 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_27 = F_14 ( V_5 , V_26 , V_26 , V_47 ,
true ) ;
if ( V_27 ) {
V_57 = V_26 ;
goto V_58;
}
}
return 0 ;
V_58:
F_7 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_14 ( V_5 , V_26 , V_26 , ! V_47 , true ) ;
F_17 ( V_2 , L_1 ) ;
return V_27 ;
}
static int F_18 ( struct V_5 * V_5 ,
struct V_42 * V_43 ,
unsigned long V_14 )
{
unsigned long V_19 = V_5 -> V_19 ? V_20 : 0 ;
bool V_47 ;
int V_27 ;
if ( F_13 ( V_43 ) )
return 0 ;
if ( ( V_19 ^ V_14 ) & V_20 ) {
V_47 = V_5 -> V_19 ? false : true ;
V_27 = F_16 ( V_5 , V_47 ) ;
if ( V_27 )
return V_27 ;
}
V_5 -> V_19 = V_14 & V_20 ? 1 : 0 ;
V_5 -> V_15 = V_14 & V_16 ? 1 : 0 ;
V_5 -> V_17 = V_14 & V_18 ? 1 : 0 ;
return 0 ;
}
static int F_19 ( struct V_6 * V_6 , T_3 V_59 )
{
char V_60 [ V_61 ] ;
int V_27 ;
F_20 ( V_60 , V_59 ) ;
V_27 = F_9 ( V_6 -> V_40 , F_10 ( V_62 ) , V_60 ) ;
if ( V_27 )
return V_27 ;
V_6 -> V_59 = V_59 ;
return 0 ;
}
static int F_21 ( struct V_5 * V_5 ,
struct V_42 * V_43 ,
unsigned long V_63 )
{
struct V_6 * V_6 = V_5 -> V_6 ;
unsigned long V_64 = F_22 ( V_63 ) ;
T_3 V_59 = F_23 ( V_64 ) / 1000 ;
if ( F_13 ( V_43 ) )
return 0 ;
return F_19 ( V_6 , V_59 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_42 * V_43 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_27 = 0 ;
switch ( V_4 -> V_7 ) {
case V_65 :
V_27 = F_12 ( V_5 , V_43 ,
V_4 -> V_9 . V_44 ) ;
break;
case V_13 :
V_27 = F_18 ( V_5 , V_43 ,
V_4 -> V_9 . V_14 ) ;
break;
case V_66 :
V_27 = F_21 ( V_5 , V_43 ,
V_4 -> V_9 . V_59 ) ;
break;
default:
V_27 = - V_21 ;
break;
}
return V_27 ;
}
static int F_25 ( struct V_5 * V_5 , T_2 V_26 )
{
struct V_6 * V_6 = V_5 -> V_6 ;
char V_67 [ V_68 ] ;
F_26 ( V_67 , V_5 -> V_39 , V_26 ) ;
return F_9 ( V_6 -> V_40 , F_10 ( V_69 ) , V_67 ) ;
}
static int F_27 ( struct V_6 * V_6 , T_2 V_70 )
{
char V_71 [ V_72 ] ;
int V_27 ;
F_28 ( V_71 , V_73 , V_70 , V_70 ) ;
V_27 = F_9 ( V_6 -> V_40 , F_10 ( V_74 ) , V_71 ) ;
if ( V_27 )
return V_27 ;
F_29 ( V_70 , V_6 -> V_75 ) ;
return 0 ;
}
static void F_30 ( struct V_6 * V_6 , T_2 V_70 )
{
char V_71 [ V_72 ] ;
F_31 ( V_70 , V_6 -> V_75 ) ;
F_28 ( V_71 , V_76 ,
V_70 , V_70 ) ;
F_9 ( V_6 -> V_40 , F_10 ( V_74 ) , V_71 ) ;
}
static int F_32 ( struct V_5 * V_5 , T_2 V_70 )
{
enum V_77 V_78 ;
if ( V_5 -> V_79 )
V_78 = V_80 ;
else
V_78 = V_81 ;
return F_33 ( V_5 , V_78 , true , V_70 , V_70 ) ;
}
static int F_34 ( struct V_5 * V_5 , T_2 V_70 )
{
enum V_77 V_78 ;
if ( ! V_5 -> V_79 )
return 0 ;
V_78 = V_80 ;
return F_33 ( V_5 , V_78 , false , V_70 , V_70 ) ;
}
static int F_35 ( struct V_1 * V_2 , T_2 V_82 ,
T_2 V_83 )
{
T_2 V_26 ;
int V_27 ;
for ( V_26 = V_82 ; V_26 <= V_83 ; V_26 ++ ) {
V_27 = F_36 ( V_2 , 0 , V_26 ) ;
if ( V_27 )
goto V_84;
}
return 0 ;
V_84:
for ( V_26 -- ; V_26 >= V_82 ; V_26 -- )
F_37 ( V_2 , 0 , V_26 ) ;
return V_27 ;
}
static int F_38 ( struct V_5 * V_5 ,
T_2 V_82 , T_2 V_83 ,
bool V_85 , bool V_86 )
{
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_1 * V_2 = V_5 -> V_2 ;
enum V_77 V_78 ;
T_2 V_26 , V_87 ;
int V_27 ;
if ( ! V_5 -> V_88 )
return F_35 ( V_2 , V_82 , V_83 ) ;
for ( V_26 = V_82 ; V_26 <= V_83 ; V_26 ++ ) {
if ( ! F_39 ( V_26 , V_6 -> V_75 ) ) {
V_27 = F_27 ( V_6 , V_26 ) ;
if ( V_27 ) {
F_17 ( V_2 , L_2 ,
V_26 ) ;
return V_27 ;
}
V_78 = V_81 ;
V_27 = F_33 ( V_5 , V_78 ,
true , V_26 , V_26 ) ;
if ( V_27 ) {
F_17 ( V_2 , L_3 ,
V_26 ) ;
return V_27 ;
}
}
V_27 = F_32 ( V_5 , V_26 ) ;
if ( V_27 ) {
F_17 ( V_2 , L_4 , V_26 ) ;
return V_27 ;
}
}
V_27 = F_14 ( V_5 , V_82 , V_83 ,
true , false ) ;
if ( V_27 ) {
F_17 ( V_2 , L_5 ) ;
return V_27 ;
}
for ( V_26 = V_82 ; V_26 <= V_83 ;
V_26 += V_89 ) {
V_87 = F_40 ( ( T_2 ) ( V_26 + V_89 - 1 ) ,
V_83 ) ;
V_27 = F_41 ( V_5 , V_26 , V_87 , true ,
V_85 ) ;
if ( V_27 ) {
F_17 ( V_5 -> V_2 , L_6 ,
V_26 , V_87 ) ;
return V_27 ;
}
}
V_26 = V_82 ;
if ( V_86 && V_5 -> V_90 != V_26 ) {
V_27 = F_25 ( V_5 , V_26 ) ;
if ( V_27 ) {
F_17 ( V_5 -> V_2 , L_7 ,
V_26 ) ;
return V_27 ;
}
V_5 -> V_90 = V_26 ;
}
for ( V_26 = V_82 ; V_26 <= V_83 ; V_26 ++ )
F_29 ( V_26 , V_5 -> V_91 ) ;
return F_3 ( V_5 ,
V_5 -> V_44 ) ;
}
static int F_42 ( struct V_5 * V_5 ,
const struct V_92 * V_93 ,
struct V_42 * V_43 )
{
bool V_94 = V_93 -> V_95 & V_96 ;
bool V_97 = V_93 -> V_95 & V_98 ;
if ( F_13 ( V_43 ) )
return 0 ;
return F_38 ( V_5 ,
V_93 -> V_82 , V_93 -> V_83 ,
V_94 , V_97 ) ;
}
static int F_43 ( struct V_5 * V_5 ,
const char * V_99 , T_2 V_26 , bool V_100 ,
bool V_101 )
{
enum V_102 V_103 ;
enum V_104 V_105 ;
char * V_106 ;
int V_27 ;
if ( ! V_26 )
V_26 = V_5 -> V_90 ;
V_106 = F_5 ( V_107 , V_37 ) ;
if ( ! V_106 )
return - V_38 ;
V_103 = V_101 ? V_108 :
V_109 ;
V_105 = V_100 ? V_110 :
V_111 ;
F_44 ( V_106 , V_105 , 0 ) ;
F_45 ( V_106 , 0 , V_103 ,
V_99 , V_26 , V_112 ,
V_5 -> V_39 ) ;
V_27 = F_9 ( V_5 -> V_6 -> V_40 , F_10 ( V_113 ) ,
V_106 ) ;
F_11 ( V_106 ) ;
return V_27 ;
}
static int
F_46 ( struct V_5 * V_5 ,
const struct V_114 * V_115 ,
struct V_42 * V_43 )
{
if ( F_13 ( V_43 ) )
return 0 ;
return F_43 ( V_5 , V_115 -> V_116 , V_115 -> V_26 ,
true , false ) ;
}
static int F_47 ( struct V_1 * V_2 ,
const struct V_117 * V_118 ,
struct V_42 * V_43 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_27 = 0 ;
switch ( V_118 -> V_7 ) {
case V_119 :
V_27 = F_42 ( V_5 ,
F_48 ( V_118 ) ,
V_43 ) ;
break;
case V_120 :
V_27 = F_46 ( V_5 ,
F_49 ( V_118 ) ,
V_43 ) ;
break;
default:
V_27 = - V_21 ;
break;
}
return V_27 ;
}
static int F_50 ( struct V_1 * V_2 , T_2 V_82 ,
T_2 V_83 )
{
T_2 V_26 ;
int V_27 ;
for ( V_26 = V_82 ; V_26 <= V_83 ; V_26 ++ ) {
V_27 = F_37 ( V_2 , 0 , V_26 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_51 ( struct V_5 * V_5 ,
T_2 V_82 , T_2 V_83 , bool V_121 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
T_2 V_26 , V_87 ;
int V_27 ;
if ( ! V_121 && ! V_5 -> V_88 )
return F_50 ( V_2 , V_82 , V_83 ) ;
for ( V_26 = V_82 ; V_26 <= V_83 ;
V_26 += V_89 ) {
V_87 = F_40 ( ( T_2 ) ( V_26 + V_89 - 1 ) ,
V_83 ) ;
V_27 = F_41 ( V_5 , V_26 , V_87 , false ,
false ) ;
if ( V_27 ) {
F_17 ( V_5 -> V_2 , L_8 ,
V_26 , V_87 ) ;
return V_27 ;
}
}
if ( ( V_5 -> V_90 >= V_82 ) &&
( V_5 -> V_90 <= V_83 ) ) {
V_5 -> V_90 = 1 ;
V_27 = F_25 ( V_5 ,
V_5 -> V_90 ) ;
if ( V_27 ) {
F_17 ( V_5 -> V_2 , L_9 ,
V_26 ) ;
return V_27 ;
}
}
if ( V_121 )
goto V_122;
V_27 = F_14 ( V_5 , V_82 , V_83 ,
false , false ) ;
if ( V_27 ) {
F_17 ( V_2 , L_10 ) ;
return V_27 ;
}
for ( V_26 = V_82 ; V_26 <= V_83 ; V_26 ++ ) {
V_27 = F_34 ( V_5 , V_26 ) ;
if ( V_27 ) {
F_17 ( V_2 , L_11 , V_26 ) ;
return V_27 ;
}
}
V_122:
for ( V_26 = V_82 ; V_26 <= V_83 ; V_26 ++ )
F_31 ( V_26 , V_5 -> V_91 ) ;
return 0 ;
}
static int F_52 ( struct V_5 * V_5 ,
const struct V_92 * V_93 )
{
return F_51 ( V_5 ,
V_93 -> V_82 , V_93 -> V_83 , false ) ;
}
static int
F_53 ( struct V_5 * V_5 ,
const struct V_114 * V_115 )
{
return F_43 ( V_5 , V_115 -> V_116 , V_115 -> V_26 ,
false , false ) ;
}
static int F_54 ( struct V_1 * V_2 ,
const struct V_117 * V_118 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_27 = 0 ;
switch ( V_118 -> V_7 ) {
case V_119 :
V_27 = F_52 ( V_5 ,
F_48 ( V_118 ) ) ;
break;
case V_120 :
V_27 = F_53 ( V_5 ,
F_49 ( V_118 ) ) ;
break;
default:
V_27 = - V_21 ;
break;
}
return V_27 ;
}
static int F_55 ( struct V_5 * V_5 ,
struct V_114 * V_115 ,
T_4 * V_123 )
{
char * V_106 ;
char V_99 [ V_124 ] ;
T_2 V_26 ;
T_1 V_39 ;
T_1 V_125 ;
int V_126 = 0 ;
int V_127 ;
int V_27 ;
V_106 = F_5 ( V_107 , V_37 ) ;
if ( ! V_106 )
return - V_38 ;
F_44 ( V_106 , V_128 , 0 ) ;
do {
F_56 ( V_106 , V_129 ) ;
V_27 = F_57 ( V_5 -> V_6 -> V_40 ,
F_10 ( V_113 ) , V_106 ) ;
if ( V_27 )
goto V_122;
V_125 = F_58 ( V_106 ) ;
if ( V_126 )
continue;
for ( V_127 = 0 ; V_127 < V_125 ; V_127 ++ ) {
switch ( F_59 ( V_106 , V_127 ) ) {
case V_130 :
F_60 ( V_106 , V_127 , V_99 , & V_26 ,
& V_39 ) ;
if ( V_39 == V_5 -> V_39 ) {
F_61 ( V_115 -> V_116 , V_99 ) ;
V_115 -> V_131 = V_132 ;
V_115 -> V_26 = V_26 ;
V_27 = V_123 ( & V_115 -> V_118 ) ;
if ( V_27 )
V_126 = V_27 ;
}
}
}
} while ( V_125 == V_129 );
V_122:
F_11 ( V_106 ) ;
return V_126 ? V_126 : V_27 ;
}
static int F_62 ( struct V_5 * V_5 ,
struct V_92 * V_93 ,
T_4 * V_123 )
{
T_2 V_26 ;
int V_27 = 0 ;
F_7 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_93 -> V_95 = 0 ;
if ( V_26 == V_5 -> V_90 )
V_93 -> V_95 |= V_98 ;
V_93 -> V_82 = V_26 ;
V_93 -> V_83 = V_26 ;
V_27 = V_123 ( & V_93 -> V_118 ) ;
if ( V_27 )
break;
}
return V_27 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_117 * V_118 ,
T_4 * V_123 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_27 = 0 ;
switch ( V_118 -> V_7 ) {
case V_119 :
V_27 = F_62 ( V_5 ,
F_48 ( V_118 ) , V_123 ) ;
break;
case V_120 :
V_27 = F_55 ( V_5 ,
F_49 ( V_118 ) , V_123 ) ;
break;
default:
V_27 = - V_21 ;
break;
}
return V_27 ;
}
static void F_64 ( struct V_6 * V_6 ,
char * V_133 , int V_134 ,
bool V_100 )
{
struct V_5 * V_5 ;
char V_99 [ V_124 ] ;
T_1 V_39 ;
T_2 V_26 ;
int V_27 ;
F_65 ( V_133 , V_134 , V_99 , & V_26 , & V_39 ) ;
V_5 = V_6 -> V_135 [ V_39 ] ;
if ( ! V_5 ) {
F_66 ( V_6 -> V_136 -> V_2 , L_12 ) ;
return;
}
V_27 = F_43 ( V_5 , V_99 , V_26 ,
V_100 && V_5 -> V_15 , true ) ;
if ( V_27 ) {
if ( F_67 () )
F_17 ( V_5 -> V_2 , L_13 ) ;
return;
}
if ( V_5 -> V_15 && V_5 -> V_17 ) {
struct V_137 V_138 ;
unsigned long V_139 ;
V_138 . V_116 = V_99 ;
V_138 . V_26 = V_26 ;
V_139 = V_100 ? V_140 : V_141 ;
F_68 ( V_139 , V_5 -> V_2 ,
& V_138 . V_138 ) ;
}
}
static void F_69 ( struct V_6 * V_6 ,
char * V_133 , int V_134 )
{
switch ( F_70 ( V_133 , V_134 ) ) {
case V_142 :
F_64 ( V_6 , V_133 ,
V_134 , true ) ;
break;
case V_143 :
F_64 ( V_6 , V_133 ,
V_134 , false ) ;
break;
}
}
static void F_71 ( struct V_6 * V_6 )
{
F_72 ( & V_6 -> V_144 . V_145 ,
F_73 ( V_6 -> V_144 . V_146 ) ) ;
}
static void F_74 ( struct V_147 * V_148 )
{
struct V_6 * V_6 ;
char * V_133 ;
T_1 V_125 ;
int V_127 ;
int V_27 ;
V_133 = F_5 ( V_149 , V_37 ) ;
if ( ! V_133 )
return;
V_6 = F_75 ( V_148 , struct V_6 , V_144 . V_145 . V_148 ) ;
do {
F_76 ( V_133 ) ;
V_27 = F_57 ( V_6 -> V_40 , F_10 ( V_150 ) , V_133 ) ;
if ( V_27 ) {
F_66 ( V_6 -> V_136 -> V_2 , L_14 ) ;
break;
}
V_125 = F_77 ( V_133 ) ;
for ( V_127 = 0 ; V_127 < V_125 ; V_127 ++ )
F_69 ( V_6 , V_133 , V_127 ) ;
} while ( V_125 );
F_11 ( V_133 ) ;
F_71 ( V_6 ) ;
}
static int F_78 ( struct V_6 * V_6 )
{
int V_27 ;
V_27 = F_19 ( V_6 , V_151 ) ;
if ( V_27 ) {
F_79 ( V_6 -> V_136 -> V_2 , L_15 ) ;
return V_27 ;
}
F_80 ( & V_6 -> V_144 . V_145 , F_74 ) ;
V_6 -> V_144 . V_146 = V_152 ;
F_71 ( V_6 ) ;
return 0 ;
}
static void F_81 ( struct V_6 * V_6 )
{
F_82 ( & V_6 -> V_144 . V_145 ) ;
}
static void F_83 ( struct V_6 * V_6 )
{
T_2 V_70 ;
F_7 (fid, mlxsw_sp->active_fids, VLAN_N_VID)
F_30 ( V_6 , V_70 ) ;
}
int F_84 ( struct V_6 * V_6 )
{
return F_78 ( V_6 ) ;
}
void F_85 ( struct V_6 * V_6 )
{
F_81 ( V_6 ) ;
F_83 ( V_6 ) ;
}
int F_86 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
int V_27 ;
V_5 -> V_90 = 1 ;
V_27 = F_51 ( V_5 , 0 , V_153 , true ) ;
if ( V_27 ) {
F_17 ( V_2 , L_16 ) ;
return V_27 ;
}
V_27 = F_36 ( V_2 , 0 , 1 ) ;
if ( V_27 )
F_17 ( V_2 , L_17 ) ;
return V_27 ;
}
void F_87 ( struct V_5 * V_5 )
{
V_5 -> V_2 -> V_154 = & V_155 ;
}
void F_88 ( struct V_5 * V_5 )
{
}
