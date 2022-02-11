static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
F_2 (!smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_GetCurrentRpm),
L_1 ,
return -1 ) ;
F_2 (!vega10_read_arg_from_smc(hwmgr->smumgr,
current_rpm),
L_2 ,
return -1 ) ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
if ( V_2 -> V_6 . V_7 . V_8 )
return 0 ;
V_5 -> V_9 = true ;
V_5 -> V_10 = true ;
V_5 -> V_11 = 0 ;
V_5 -> V_12 = 100 ;
if ( F_4 ( V_2 -> V_13 . V_14 ,
V_15 ) &&
V_2 -> V_6 . V_7 .
V_16 ) {
V_5 -> V_17 = true ;
V_5 -> V_18 = true ;
V_5 -> V_19 =
V_2 -> V_6 . V_7 . V_20 ;
V_5 -> V_21 =
V_2 -> V_6 . V_7 . V_22 ;
} else {
V_5 -> V_19 = 0 ;
V_5 -> V_21 = 0 ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
T_1 * V_23 )
{
T_1 V_3 ;
T_1 V_24 = 0 ;
if ( V_2 -> V_6 . V_7 . V_8 )
return 0 ;
if ( F_1 ( V_2 , & V_3 ) )
return - 1 ;
if ( V_2 -> V_6 .
V_25 . V_26 != 0 )
V_24 = V_3 * 100 /
V_2 -> V_6 .
V_25 . V_26 ;
* V_23 = V_24 > 100 ? 100 : V_24 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 * V_23 )
{
struct V_27 * V_28 = (struct V_27 * ) ( V_2 -> V_29 ) ;
T_1 V_30 ;
T_1 V_31 ;
int V_32 = 0 ;
if ( V_2 -> V_6 . V_7 . V_8 )
return - 1 ;
if ( V_28 -> V_33 [ V_34 ] . V_35 )
V_32 = F_1 ( V_2 , V_23 ) ;
else {
T_1 V_36 = F_7 ( V_37 , 0 ,
V_38 , V_39 ) ;
V_30 = ( F_8 ( V_2 -> V_40 ,
V_36 ) & V_41 ) >>
V_42 ;
if ( V_30 == 0 )
return - V_43 ;
V_31 = F_9 ( V_2 ) ;
* V_23 = 60 * V_31 * 10000 / V_30 ;
}
return V_32 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_44 )
{
T_1 V_36 ;
V_36 = F_7 ( V_37 , 0 ,
V_45 , V_46 ) ;
if ( V_2 -> V_47 ) {
V_2 -> V_48 =
( F_8 ( V_2 -> V_40 , V_36 ) &
V_49 ) >>
V_50 ;
V_2 -> V_51 = ( F_8 ( V_2 -> V_40 , V_36 ) &
V_52 ) >>
V_53 ;
V_2 -> V_47 = false ;
}
F_11 ( V_2 -> V_40 , V_36 ,
( F_8 ( V_2 -> V_40 , V_36 ) &
~ V_52 ) |
( 0 << V_53 ) ) ;
F_11 ( V_2 -> V_40 , V_36 ,
( F_8 ( V_2 -> V_40 , V_36 ) &
~ V_49 ) |
( V_44 << V_50 ) ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
T_1 V_36 ;
V_36 = F_7 ( V_37 , 0 ,
V_45 , V_46 ) ;
if ( ! V_2 -> V_47 ) {
F_11 ( V_2 -> V_40 , V_36 ,
( F_8 ( V_2 -> V_40 , V_36 ) &
~ V_49 ) |
( V_2 -> V_48 <<
V_50 ) ) ;
F_11 ( V_2 -> V_40 , V_36 ,
( F_8 ( V_2 -> V_40 , V_36 ) &
~ V_52 ) |
( V_2 -> V_51 << V_53 ) ) ;
V_2 -> V_47 = true ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = (struct V_27 * ) ( V_2 -> V_29 ) ;
if ( V_28 -> V_33 [ V_34 ] . V_35 ) {
F_2 (!vega10_enable_smc_features(
hwmgr->smumgr, true,
data->smu_features[GNLD_FAN_CONTROL].
smu_feature_bitmap),
L_3 ,
return -1 ) ;
V_28 -> V_33 [ V_34 ] . V_54 = true ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = (struct V_27 * ) ( V_2 -> V_29 ) ;
if ( V_28 -> V_33 [ V_34 ] . V_35 ) {
F_2 (!vega10_enable_smc_features(
hwmgr->smumgr, false,
data->smu_features[GNLD_FAN_CONTROL].
smu_feature_bitmap),
L_3 ,
return -1 ) ;
V_28 -> V_33 [ V_34 ] . V_54 = false ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_7 . V_8 )
return - 1 ;
F_2 (!vega10_enable_fan_control_feature(hwmgr),
L_4 ,
return -1 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = (struct V_27 * ) ( V_2 -> V_29 ) ;
if ( V_2 -> V_6 . V_7 . V_8 )
return - 1 ;
if ( V_28 -> V_33 [ V_34 ] . V_35 ) {
F_2 (!vega10_disable_fan_control_feature(hwmgr),
L_5 ,
return -1 ) ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
T_1 V_23 )
{
T_1 V_55 ;
T_1 V_56 ;
T_2 V_57 ;
T_1 V_36 ;
if ( V_2 -> V_6 . V_7 . V_8 )
return 0 ;
if ( V_23 > 100 )
V_23 = 100 ;
if ( F_4 ( V_2 -> V_13 . V_14 ,
V_58 ) )
F_16 ( V_2 ) ;
V_36 = F_7 ( V_37 , 0 ,
V_59 , V_60 ) ;
V_55 = ( F_8 ( V_2 -> V_40 , V_36 ) &
V_61 ) >>
V_62 ;
if ( V_55 == 0 )
return - V_43 ;
V_57 = ( T_2 ) V_23 * V_55 ;
F_18 ( V_57 , 100 ) ;
V_56 = ( T_1 ) V_57 ;
V_36 = F_7 ( V_37 , 0 ,
V_63 , V_64 ) ;
F_11 ( V_2 -> V_40 , V_36 ,
( F_8 ( V_2 -> V_40 , V_36 ) &
~ V_65 ) |
( V_56 << V_66 ) ) ;
return F_10 ( V_2 , V_67 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_32 ;
if ( V_2 -> V_6 . V_7 . V_8 )
return 0 ;
if ( F_4 ( V_2 -> V_13 . V_14 ,
V_58 ) ) {
V_32 = F_15 ( V_2 ) ;
} else
V_32 = F_12 ( V_2 ) ;
return V_32 ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_23 )
{
T_1 V_30 ;
T_1 V_31 ;
int V_32 = 0 ;
T_1 V_36 ;
if ( V_2 -> V_6 . V_7 . V_8 ||
( V_23 < V_2 -> V_6 . V_7 . V_20 ) ||
( V_23 > V_2 -> V_6 . V_7 . V_22 ) )
return - 1 ;
if ( F_4 ( V_2 -> V_13 . V_14 ,
V_58 ) )
V_32 = F_16 ( V_2 ) ;
if ( ! V_32 ) {
V_31 = F_9 ( V_2 ) ;
V_30 = 60 * V_31 * 10000 / ( 8 * V_23 ) ;
V_36 = F_7 ( V_37 , 0 ,
V_38 , V_39 ) ;
F_11 ( V_2 -> V_40 , V_36 ,
( F_8 ( V_2 -> V_40 , V_36 ) &
~ V_41 ) |
( V_30 << V_42 ) ) ;
}
return F_10 ( V_2 , V_68 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_69 ;
T_1 V_36 ;
V_36 = F_7 ( V_37 , 0 ,
V_38 , V_70 ) ;
V_69 = F_8 ( V_2 -> V_40 , V_36 ) ;
V_69 = ( V_69 & V_71 ) >>
V_72 ;
V_69 = V_69 & 0x1ff ;
V_69 *= V_73 ;
return V_69 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
T_1 V_76 = V_77 *
V_73 ;
T_1 V_78 = V_79 *
V_73 ;
T_1 V_80 , V_36 ;
if ( V_76 < V_75 -> V_81 )
V_76 = V_75 -> V_81 ;
if ( V_78 > V_75 -> V_82 )
V_78 = V_75 -> V_82 ;
if ( V_76 > V_78 )
return - V_43 ;
V_36 = F_7 ( V_37 , 0 ,
V_83 , V_84 ) ;
V_80 = F_8 ( V_2 -> V_40 , V_36 ) ;
V_80 &= ( ~ V_85 ) ;
V_80 |= ( 5 << V_86 ) ;
V_80 &= ( ~ V_87 ) ;
V_80 |= ( 1 << V_88 ) ;
V_80 &= ( ~ V_89 ) ;
V_80 |= ( ( V_78 / V_73 )
<< V_90 ) ;
V_80 &= ( ~ V_91 ) ;
V_80 |= ( ( V_76 / V_73 )
<< V_92 ) ;
V_80 = V_80 & ( ~ V_93 ) ;
F_11 ( V_2 -> V_40 , V_36 , V_80 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_1 V_36 ;
if ( V_2 -> V_6 . V_7 . V_16 ) {
V_36 = F_7 ( V_37 , 0 ,
V_94 , V_95 ) ;
F_11 ( V_2 -> V_40 , V_36 ,
( F_8 ( V_2 -> V_40 , V_36 ) &
~ V_96 ) |
( ( V_2 -> V_6 . V_7 .
V_16 - 1 ) <<
V_97 ) ) ;
}
V_36 = F_7 ( V_37 , 0 ,
V_45 , V_46 ) ;
F_11 ( V_2 -> V_40 , V_36 ,
( F_8 ( V_2 -> V_40 , V_36 ) &
~ V_98 ) |
( 0x28 << V_99 ) ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = (struct V_27 * ) ( V_2 -> V_29 ) ;
T_1 V_80 = 0 ;
T_1 V_36 ;
if ( V_28 -> V_33 [ V_100 ] . V_35 ) {
if ( V_28 -> V_33 [ V_100 ] . V_54 )
F_25 ( L_6 ) ;
F_2 (!vega10_enable_smc_features(hwmgr->smumgr,
true,
data->smu_features[GNLD_FW_CTF].smu_feature_bitmap),
L_7 ,
return -1 ) ;
V_28 -> V_33 [ V_100 ] . V_54 = true ;
}
V_80 |= ( 1 << V_101 ) ;
V_80 |= ( 1 << V_102 ) ;
V_80 |= ( 1 << V_103 ) ;
V_36 = F_7 ( V_37 , 0 , V_104 , V_105 ) ;
F_11 ( V_2 -> V_40 , V_36 , V_80 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = (struct V_27 * ) ( V_2 -> V_29 ) ;
T_1 V_36 ;
if ( V_28 -> V_33 [ V_100 ] . V_35 ) {
if ( ! V_28 -> V_33 [ V_100 ] . V_54 )
F_25 ( L_8 ) ;
F_2 (!vega10_enable_smc_features(hwmgr->smumgr,
false,
data->smu_features[GNLD_FW_CTF].smu_feature_bitmap),
L_9 ,
return -1 ) ;
V_28 -> V_33 [ V_100 ] . V_54 = false ;
}
V_36 = F_7 ( V_37 , 0 , V_104 , V_105 ) ;
F_11 ( V_2 -> V_40 , V_36 , 0 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_32 = F_26 ( V_2 ) ;
if ( ! V_2 -> V_6 . V_7 . V_8 )
F_12 ( V_2 ) ;
return V_32 ;
}
int F_28 ( struct V_1 * V_2 ,
void * V_106 , void * V_107 , void * V_108 , int V_32 )
{
int V_109 ;
struct V_27 * V_28 = (struct V_27 * ) ( V_2 -> V_29 ) ;
T_3 * V_110 = & ( V_28 -> V_111 . V_112 ) ;
if ( ! V_28 -> V_33 [ V_34 ] . V_35 )
return 0 ;
V_110 -> V_113 = ( V_114 ) V_2 -> V_6 .
V_25 . V_26 ;
V_110 -> V_115 = V_2 -> V_6 .
V_25 . V_116 ;
V_110 -> V_117 = ( V_114 ) ( V_2 -> V_6 .
V_25 . V_118 ) ;
V_110 -> V_119 = V_2 -> V_6 .
V_25 . V_120 ;
F_29 ( V_2 -> V_121 ,
V_122 ,
( T_1 ) V_110 -> V_119 ) ;
V_110 -> V_123 = V_2 -> V_6 .
V_25 . V_124 * 255 / 100 ;
V_110 -> V_125 = ( V_114 ) ( V_2 -> V_6 .
V_25 . V_126 ) ;
V_110 -> V_127 = V_2 -> V_6 .
V_25 . V_128 ;
V_110 -> V_129 = V_2 -> V_6 .
V_25 . V_130 ;
V_110 -> V_131 = V_2 -> V_6 .
V_25 . V_132 ;
V_110 -> V_133 = V_2 -> V_6 .
V_25 . V_134 ;
V_110 -> V_135 = V_2 -> V_6 .
V_25 . V_136 ;
V_110 -> V_137 = V_2 -> V_6 .
V_25 . V_138 ;
V_110 -> V_139 = V_2 -> V_6 .
V_25 . V_140 ;
V_110 -> V_141 = V_2 -> V_6 .
V_25 . V_142 ;
V_110 -> V_143 = V_2 -> V_6 .
V_25 . V_144 ;
V_110 -> V_145 = V_2 -> V_6 .
V_25 . V_146 ;
V_109 = F_30 ( V_2 -> V_121 ,
( V_147 * ) ( & ( V_28 -> V_111 . V_112 ) ) , V_148 ) ;
if ( V_109 )
F_31 ( L_10 ) ;
return V_109 ;
}
int F_32 ( struct V_1 * V_2 ,
void * V_106 , void * V_107 , void * V_108 , int V_32 )
{
if ( F_4 ( V_2 -> V_13 . V_14 ,
V_58 ) ) {
F_15 ( V_2 ) ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 ,
void * V_106 , void * V_107 , void * V_108 , int V_32 )
{
struct V_74 * V_75 = (struct V_74 * ) V_106 ;
if ( V_75 == NULL )
return - V_43 ;
return F_22 ( V_2 , V_75 ) ;
}
int F_34 ( struct V_1 * V_2 ,
void * V_106 , void * V_107 , void * V_108 , int V_32 )
{
return F_23 ( V_2 ) ;
}
int F_35 ( struct V_1 * V_2 ,
void * V_106 , void * V_107 , void * V_108 , int V_32 )
{
return F_24 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
void * V_106 , void * V_107 , void * V_108 , int V_32 )
{
return F_26 ( V_2 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 . V_7 . V_8 ) {
F_12 ( V_2 ) ;
F_16 ( V_2 ) ;
}
return 0 ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_39 ( V_2 ,
& V_149 ,
& ( V_2 -> V_150 ) ) ;
if ( ! V_32 ) {
V_32 = F_39 ( V_2 ,
& V_151 ,
& ( V_2 -> V_152 ) ) ;
if ( V_32 )
F_40 ( V_2 ,
& ( V_2 -> V_150 ) ) ;
}
if ( ! V_32 )
V_2 -> V_47 = true ;
return V_32 ;
}
