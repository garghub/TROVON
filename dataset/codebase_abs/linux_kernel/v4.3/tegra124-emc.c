static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_6 ) ;
F_2 ( V_4 , V_2 -> V_5 + V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
T_1 V_3 ;
F_2 ( 1 , V_2 -> V_5 + V_9 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; ++ V_8 ) {
V_3 = F_4 ( V_2 -> V_5 + V_11 ) ;
if ( ( V_3 & V_12 ) == 0 )
return;
F_5 ( 1 ) ;
}
F_6 ( V_2 -> V_13 , L_1 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
T_1 V_3 ;
F_2 ( 0 , V_2 -> V_5 + V_14 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; ++ V_8 ) {
V_3 = F_4 ( V_2 -> V_5 + V_15 ) ;
if ( ( V_3 & V_16 ) == 0 )
return;
F_5 ( 1 ) ;
}
F_6 ( V_2 -> V_13 , L_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
T_1 V_3 ;
for ( V_8 = 0 ; V_8 < V_10 ; ++ V_8 ) {
V_3 = F_4 ( V_2 -> V_5 + V_17 ) ;
if ( V_3 & V_18 )
return;
F_5 ( 1 ) ;
}
F_6 ( V_2 -> V_13 , L_3 ) ;
}
static struct V_19 * F_9 ( struct V_1 * V_2 ,
unsigned long V_20 )
{
struct V_19 * V_21 = NULL ;
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_22 ; V_8 ++ ) {
if ( V_2 -> V_23 [ V_8 ] . V_20 == V_20 ) {
V_21 = & V_2 -> V_23 [ V_8 ] ;
break;
}
}
if ( ! V_21 ) {
F_6 ( V_2 -> V_13 , L_4 , V_20 ) ;
return NULL ;
}
return V_21 ;
}
int F_10 ( struct V_1 * V_2 ,
unsigned long V_20 )
{
struct V_19 * V_21 = F_9 ( V_2 , V_20 ) ;
struct V_19 * V_24 = & V_2 -> V_25 ;
enum V_26 V_27 ;
unsigned int V_28 = 0 ;
T_1 V_29 , V_30 , V_31 ;
bool V_32 = false ;
unsigned int V_8 ;
if ( ! V_21 )
return - V_33 ;
if ( ( V_24 -> V_34 & 0x1 ) == ( V_21 -> V_34 & 0x1 ) )
V_27 = V_35 ;
else if ( V_21 -> V_34 & 0x1 )
V_27 = V_36 ;
else
V_27 = V_37 ;
F_2 ( V_18 , V_2 -> V_5 + V_17 ) ;
V_29 = F_4 ( V_2 -> V_5 + V_38 ) ;
if ( V_29 & V_39 ) {
V_29 &= ~ V_40 ;
F_2 ( V_29 , V_2 -> V_5 + V_38 ) ;
V_28 = 5 ;
}
if ( V_2 -> V_41 == V_42 )
V_31 = V_43 ;
else
V_31 = V_44 ;
V_29 = F_4 ( V_2 -> V_5 + V_45 ) ;
if ( V_29 & V_31 ) {
V_29 &= ~ V_31 ;
F_2 ( V_29 , V_2 -> V_5 + V_45 ) ;
}
V_29 = F_4 ( V_2 -> V_5 + V_46 ) ;
V_30 = V_24 -> V_47 ;
if ( ! ( V_21 -> V_47 &
V_48 ) &&
( V_29 & V_48 ) ) {
V_30 &= ~ V_48 ;
V_32 = true ;
}
if ( ( V_29 & V_49 ) ||
( V_29 & V_50 ) ) {
V_32 = true ;
}
if ( V_32 ) {
F_2 ( V_30 , V_2 -> V_5 + V_46 ) ;
if ( V_28 < 5 )
V_28 = 5 ;
}
V_32 = false ;
V_29 = F_4 ( V_2 -> V_5 + V_51 ) ;
if ( V_21 -> V_52 & V_53 &&
! ( V_29 & V_53 ) ) {
V_29 |= V_53 ;
V_32 = true ;
}
if ( V_21 -> V_52 & V_54 &&
! ( V_29 & V_54 ) ) {
V_29 |= V_54 ;
V_32 = true ;
}
if ( V_32 ) {
F_2 ( V_29 , V_2 -> V_5 + V_51 ) ;
if ( V_28 < 30 )
V_28 = 30 ;
}
if ( V_28 ) {
F_3 ( V_2 ) ;
F_5 ( V_28 ) ;
}
if ( V_24 -> V_55 != V_21 -> V_55 ) {
F_7 ( V_2 ) ;
F_2 ( V_21 -> V_55 ,
V_2 -> V_5 + V_56 ) ;
F_3 ( V_2 ) ;
}
for ( V_8 = 0 ; V_8 < F_11 ( V_21 -> V_57 ) ; ++ V_8 )
F_2 ( V_21 -> V_57 [ V_8 ] ,
V_2 -> V_5 + V_58 [ V_8 ] ) ;
F_2 ( V_21 -> V_52 , V_2 -> V_5 + V_51 ) ;
F_2 ( V_21 -> V_59 , V_2 -> V_5 + V_60 ) ;
F_12 ( V_2 -> V_61 , V_21 -> V_20 ) ;
V_29 = V_21 -> V_62 & ~ V_40 ;
F_1 ( V_2 , V_29 , V_38 ) ;
if ( V_21 -> V_63 != V_24 -> V_63 )
F_1 ( V_2 , V_21 -> V_63 ,
V_64 ) ;
if ( V_21 -> V_65 != V_24 -> V_65 )
F_1 ( V_2 , V_21 -> V_65 ,
V_66 ) ;
if ( V_21 -> V_67 != V_24 -> V_67 ) {
V_29 = V_21 -> V_67 ;
V_29 &= V_68 ;
F_1 ( V_2 , V_29 , V_69 ) ;
}
if ( V_2 -> V_41 == V_42 &&
V_27 == V_36 ) {
T_1 V_70 = 512 ;
if ( V_21 -> V_59 != 0 &&
V_24 -> V_59 == 0 )
V_70 -= V_2 -> V_71 * 256 ;
V_29 = ( V_21 -> V_72
& V_73 )
>> V_74 ;
if ( V_70 < V_29 )
V_70 = V_29 ;
V_29 = V_21 -> V_72
& ~ V_75 ;
V_29 |= ( V_70 << V_76 )
& V_75 ;
F_2 ( V_29 , V_2 -> V_5 + V_77 ) ;
}
V_29 = V_21 -> V_78 ;
V_29 &= ~ V_79 ;
F_1 ( V_2 , V_29 , V_80 ) ;
if ( V_2 -> V_41 == V_42 && V_27 == V_37 )
F_1 ( V_2 , V_21 -> V_34 , V_81 ) ;
F_1 ( V_2 , F_13 ( V_2 -> V_71 ) ,
V_82 ) ;
if ( V_2 -> V_41 == V_42 )
F_1 ( V_2 , F_14 ( V_2 -> V_71 ) |
V_83 ,
V_84 ) ;
F_1 ( V_2 , 1 , V_85 ) ;
if ( V_2 -> V_41 == V_42 )
F_1 ( V_2 , F_14 ( V_2 -> V_71 ) ,
V_84 ) ;
F_1 ( V_2 , F_13 ( V_2 -> V_71 ) |
V_86 ,
V_82 ) ;
if ( V_2 -> V_41 == V_42 ) {
if ( V_21 -> V_34 != V_24 -> V_34 )
F_1 ( V_2 , V_21 -> V_34 , V_81 ) ;
if ( V_21 -> V_87 != V_24 -> V_87 )
F_1 ( V_2 , V_21 -> V_87 , V_88 ) ;
if ( ( V_21 -> V_89 != V_24 -> V_89 ) ||
V_27 == V_36 ) {
V_29 = V_21 -> V_89 ;
if ( V_27 == V_36 ) {
V_29 |= V_90 ;
V_29 |= V_91 ;
} else {
V_29 &= ~ V_90 ;
}
F_1 ( V_2 , V_29 , V_92 ) ;
}
} else {
if ( V_21 -> V_87 != V_24 -> V_87 )
F_1 ( V_2 , V_21 -> V_87 , V_93 ) ;
if ( V_21 -> V_34 != V_24 -> V_34 )
F_1 ( V_2 , V_21 -> V_34 , V_94 ) ;
if ( V_21 -> V_95 != V_24 -> V_95 )
F_1 ( V_2 , V_21 -> V_95 , V_96 ) ;
}
if ( V_21 -> V_59 != 0 && V_24 -> V_59 == 0 ) {
F_1 ( V_2 , V_97 , V_98 ) ;
if ( V_2 -> V_71 > 1 )
F_1 ( V_2 , V_99 ,
V_98 ) ;
}
F_1 ( V_2 , 0 , V_100 ) ;
if ( V_21 -> V_78 & V_79 )
F_1 ( V_2 , V_21 -> V_78 , V_80 ) ;
F_7 ( V_2 ) ;
F_4 ( V_2 -> V_5 + V_17 ) ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 ,
unsigned long V_20 )
{
struct V_19 * V_21 = F_9 ( V_2 , V_20 ) ;
struct V_19 * V_24 = & V_2 -> V_25 ;
T_1 V_29 ;
if ( ! V_21 )
return;
F_8 ( V_2 ) ;
if ( V_21 -> V_55 != V_24 -> V_55 )
F_2 ( V_21 -> V_101 ,
V_2 -> V_5 + V_14 ) ;
if ( V_21 -> V_62 & V_39 )
F_2 ( V_21 -> V_62 , V_2 -> V_5 + V_38 ) ;
F_2 ( V_21 -> V_102 , V_2 -> V_5 + V_103 ) ;
if ( V_2 -> V_41 == V_104 &&
V_21 -> V_47 &
V_48 ) {
V_29 = V_21 -> V_47 ;
V_29 |= V_50 ;
V_29 |= V_49 ;
F_2 ( V_29 , V_2 -> V_5 + V_46 ) ;
} else {
if ( V_2 -> V_41 == V_42 &&
F_4 ( V_2 -> V_5 + V_46 ) !=
V_21 -> V_47 ) {
F_2 ( V_21 -> V_47 ,
V_2 -> V_5 + V_46 ) ;
}
F_2 ( V_21 -> V_101 ,
V_2 -> V_5 + V_14 ) ;
}
F_5 ( 2 ) ;
F_2 ( V_21 -> V_105 , V_2 -> V_5 + V_45 ) ;
F_3 ( V_2 ) ;
V_2 -> V_25 = * V_21 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_19 * V_21 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < F_11 ( V_58 ) ; ++ V_8 )
V_21 -> V_57 [ V_8 ] =
F_4 ( V_2 -> V_5 + V_58 [ V_8 ] ) ;
V_21 -> V_62 = F_4 ( V_2 -> V_5 + V_38 ) ;
V_21 -> V_101 = 0 ;
V_21 -> V_102 = 0 ;
V_21 -> V_34 = 0 ;
V_21 -> V_87 = 0 ;
V_21 -> V_95 = 0 ;
V_21 -> V_89 = 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
V_2 -> V_41 = F_4 ( V_2 -> V_5 + V_106 ) ;
V_2 -> V_41 &= V_107 ;
V_2 -> V_41 >>= V_108 ;
V_2 -> V_71 = F_18 ( V_2 -> V_61 ) ;
F_16 ( V_2 , & V_2 -> V_25 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_19 * V_21 ,
struct V_109 * V_110 )
{
T_1 V_3 ;
int V_111 ;
V_111 = F_20 ( V_110 , L_5 , & V_3 ) ;
if ( V_111 ) {
F_6 ( V_2 -> V_13 , L_6 ,
V_110 -> V_112 , V_111 ) ;
return V_111 ;
}
V_21 -> V_20 = V_3 ;
V_111 = F_21 ( V_110 , L_7 ,
V_21 -> V_57 ,
F_11 ( V_21 -> V_57 ) ) ;
if ( V_111 ) {
F_6 ( V_2 -> V_13 ,
L_8 ,
V_110 -> V_112 , V_111 ) ;
return V_111 ;
}
#define F_22 ( T_2 , T_3 ) { \
err = of_property_read_u32(node, dtprop, &timing->prop); \
if (err) { \
dev_err(emc->dev, "timing %s: failed to read " #prop ": %d\n", \
node->name, err); \
return err; \
} \
}
F_22 (emc_auto_cal_config, L_9 )
F_22 (emc_auto_cal_config2, L_10 )
F_22 (emc_auto_cal_config3, L_11 )
F_22 (emc_auto_cal_interval, L_12 )
F_22 (emc_bgbias_ctl0, L_13 )
F_22 (emc_cfg, L_14 )
F_22 (emc_cfg_2, L_15 )
F_22 (emc_ctt_term_ctrl, L_16 )
F_22 (emc_mode_1, L_17 )
F_22 (emc_mode_2, L_18 )
F_22 (emc_mode_4, L_19 )
F_22 (emc_mode_reset, L_20 )
F_22 (emc_mrs_wait_cnt, L_21 )
F_22 (emc_sel_dpd_ctrl, L_22 )
F_22 (emc_xm2dqspadctrl2, L_23 )
F_22 (emc_zcal_cnt_long, L_24 )
F_22 (emc_zcal_interval, L_25 )
#undef F_22
return 0 ;
}
static int F_23 ( const void * V_113 , const void * V_114 )
{
const struct V_19 * V_115 = V_113 ;
const struct V_19 * V_116 = V_114 ;
if ( V_115 -> V_20 < V_116 -> V_20 )
return - 1 ;
else if ( V_115 -> V_20 == V_116 -> V_20 )
return 0 ;
else
return 1 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
int V_117 = F_25 ( V_110 ) ;
struct V_109 * V_118 ;
struct V_19 * V_21 ;
unsigned int V_8 = 0 ;
int V_111 ;
V_2 -> V_23 = F_26 ( V_2 -> V_13 , V_117 , sizeof( * V_21 ) ,
V_119 ) ;
if ( ! V_2 -> V_23 )
return - V_120 ;
V_2 -> V_22 = V_117 ;
F_27 (node, child) {
V_21 = & V_2 -> V_23 [ V_8 ++ ] ;
V_111 = F_19 ( V_2 , V_21 , V_118 ) ;
if ( V_111 )
return V_111 ;
}
F_28 ( V_2 -> V_23 , V_2 -> V_22 , sizeof( * V_21 ) , F_23 ,
NULL ) ;
return 0 ;
}
static struct V_109 *
F_29 ( struct V_109 * V_110 , T_1 V_121 )
{
struct V_109 * V_122 ;
int V_111 ;
F_27 (node, np) {
T_1 V_3 ;
V_111 = F_20 ( V_122 , L_26 , & V_3 ) ;
if ( V_111 || ( V_3 != V_121 ) ) {
F_30 ( V_122 ) ;
continue;
}
return V_122 ;
}
return NULL ;
}
static int F_31 ( void * V_123 , T_4 * V_20 )
{
struct V_124 * V_125 = V_123 ;
* V_20 = F_32 ( V_125 ) ;
return 0 ;
}
static int F_33 ( void * V_123 , T_4 V_20 )
{
struct V_124 * V_125 = V_123 ;
return F_34 ( V_125 , V_20 ) ;
}
static int F_35 ( struct V_126 * V_127 , void * V_123 )
{
struct V_1 * V_2 = V_127 -> V_128 ;
const char * V_129 = L_27 ;
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_22 ; V_8 ++ ) {
struct V_19 * V_21 = & V_2 -> V_23 [ V_8 ] ;
F_36 ( V_127 , L_28 , V_129 , V_21 -> V_20 ) ;
V_129 = L_29 ;
}
F_37 ( V_127 , L_30 ) ;
return 0 ;
}
static int F_38 ( struct V_130 * V_130 ,
struct V_131 * V_131 )
{
return F_39 ( V_131 , F_35 ,
V_130 -> V_132 ) ;
}
static void F_40 ( struct V_133 * V_13 , struct V_1 * V_2 )
{
struct V_134 * V_135 , * V_131 ;
struct V_124 * V_124 ;
V_135 = F_41 ( L_31 , NULL ) ;
if ( ! V_135 ) {
F_6 ( V_13 , L_32 ) ;
return;
}
V_124 = F_42 ( L_33 , L_31 ) ;
if ( F_43 ( V_124 ) ) {
F_6 ( V_13 , L_34 , F_44 ( V_124 ) ) ;
return;
}
V_131 = F_45 ( L_35 , V_136 | V_137 , V_135 , V_124 ,
& V_138 ) ;
if ( ! V_131 )
F_6 ( V_13 , L_36 ) ;
V_131 = F_45 ( L_37 , V_136 , V_135 , V_2 ,
& V_139 ) ;
if ( ! V_131 )
F_6 ( V_13 , L_36 ) ;
}
static int F_46 ( struct V_140 * V_141 )
{
struct V_140 * V_61 ;
struct V_109 * V_122 ;
struct V_1 * V_2 ;
struct V_142 * V_143 ;
T_1 V_121 ;
int V_111 ;
V_2 = F_47 ( & V_141 -> V_13 , sizeof( * V_2 ) , V_119 ) ;
if ( ! V_2 )
return - V_120 ;
V_2 -> V_13 = & V_141 -> V_13 ;
V_143 = F_48 ( V_141 , V_144 , 0 ) ;
V_2 -> V_5 = F_49 ( & V_141 -> V_13 , V_143 ) ;
if ( F_43 ( V_2 -> V_5 ) )
return F_44 ( V_2 -> V_5 ) ;
V_122 = F_50 ( V_141 -> V_13 . V_145 , L_38 , 0 ) ;
if ( ! V_122 ) {
F_6 ( & V_141 -> V_13 , L_39 ) ;
return - V_33 ;
}
V_61 = F_51 ( V_122 ) ;
if ( ! V_61 )
return - V_33 ;
F_30 ( V_122 ) ;
V_2 -> V_61 = F_52 ( V_61 ) ;
if ( ! V_2 -> V_61 )
return - V_146 ;
V_121 = F_53 () ;
V_122 = F_29 ( V_141 -> V_13 . V_145 , V_121 ) ;
if ( ! V_122 ) {
F_6 ( & V_141 -> V_13 ,
L_40 ,
V_121 ) ;
return - V_33 ;
}
V_111 = F_24 ( V_2 , V_122 ) ;
F_30 ( V_122 ) ;
if ( V_111 )
return V_111 ;
if ( V_2 -> V_22 == 0 ) {
F_6 ( & V_141 -> V_13 ,
L_41 ,
V_121 ) ;
return - V_33 ;
}
V_111 = F_17 ( V_2 ) ;
if ( V_111 ) {
F_6 ( & V_141 -> V_13 , L_42 , V_111 ) ;
return V_111 ;
}
F_54 ( V_141 , V_2 ) ;
if ( F_55 ( V_147 ) )
F_40 ( & V_141 -> V_13 , V_2 ) ;
return 0 ;
}
static int F_56 ( void )
{
return F_57 ( & V_148 ) ;
}
