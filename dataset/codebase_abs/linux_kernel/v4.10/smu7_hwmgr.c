static struct V_1 * F_1 (
struct V_2 * V_3 )
{
F_2 ((PhwVIslands_Magic == hw_ps->magic),
L_1 ,
return NULL) ;
return (struct V_1 * ) V_3 ;
}
static const struct V_1 * F_3 (
const struct V_2 * V_3 )
{
F_2 ((PhwVIslands_Magic == hw_ps->magic),
L_1 ,
return NULL) ;
return ( const struct V_1 * ) V_3 ;
}
static int F_4 ( struct V_4 * V_5 )
{
F_5 ( V_5 -> V_6 , V_7 , 0x9F ) ;
V_5 -> V_8 . V_9 = F_6 ( V_5 -> V_6 , V_10 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_4 * V_5 )
{
T_2 V_11 = 0 ;
V_11 = F_8 ( V_5 -> V_6 , V_12 ,
V_13 ) ;
return ( ( T_1 ) F_9 ( V_11 ,
V_14 , V_15 ) ) ;
}
static int F_10 ( struct V_4 * V_5 )
{
T_2 V_16 ;
V_16 = F_11 ( V_5 -> V_6 , V_12 ,
V_17 , V_18 ) ;
F_2 ((7 >= link_width),
L_2 , return 0 ) ;
return F_12 ( V_16 ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
if ( V_5 -> V_19 & V_20 )
F_14 ( V_5 -> V_21 , V_22 ) ;
return 0 ;
}
static bool F_15 ( const struct V_4 * V_5 )
{
const struct V_23 * V_24 =
( const struct V_23 * ) ( V_5 -> V_25 ) ;
return ( V_26 != V_24 -> V_27 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_30 , 1 ) ;
return 0 ;
}
static int F_18 ( T_3 * V_31 ,
struct V_32 * V_33
)
{
T_2 V_34 ;
F_2 ((NULL != voltage_table),
L_3 , return -EINVAL;) ;
V_31 -> V_35 = 0 ;
V_31 -> V_36 = 0 ;
V_31 -> V_37 = V_33 -> V_37 ;
for ( V_34 = 0 ; V_34 < V_33 -> V_37 ; V_34 ++ ) {
V_31 -> V_38 [ V_34 ] . V_39 =
V_33 -> V_38 [ V_34 ] . V_40 ;
V_31 -> V_38 [ V_34 ] . V_41 = 0 ;
}
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) V_5 -> V_44 ;
int V_45 = 0 ;
T_2 V_46 ;
if ( V_47 == V_24 -> V_48 ) {
V_45 = F_20 ( V_5 ,
V_49 , V_50 ,
& ( V_24 -> V_51 ) ) ;
F_2 ((0 == result),
L_4 ,
return result) ;
} else if ( V_52 == V_24 -> V_48 ) {
if ( V_5 -> V_53 == V_54 )
V_45 = F_21 ( & ( V_24 -> V_51 ) ,
V_43 -> V_55 ) ;
else if ( V_5 -> V_53 == V_56 )
V_45 = F_18 ( & ( V_24 -> V_51 ) ,
V_5 -> V_57 . V_58 ) ;
F_2 ((0 == result),
L_5 ,
return result;) ;
}
if ( V_47 == V_24 -> V_59 ) {
V_45 = F_20 ( V_5 ,
V_60 , V_50 ,
& ( V_24 -> V_61 ) ) ;
F_2 ((0 == result),
L_6 ,
return result) ;
} else if ( V_52 == V_24 -> V_59 ) {
if ( V_5 -> V_53 == V_54 )
V_45 = F_22 ( & ( V_24 -> V_61 ) ,
V_43 -> V_55 ) ;
else if ( V_5 -> V_53 == V_56 )
V_45 = F_18 ( & ( V_24 -> V_61 ) ,
V_5 -> V_57 . V_62 ) ;
F_2 ((0 == result),
L_7 ,
return result) ;
}
if ( V_52 == V_24 -> V_63 ) {
V_45 = F_23 ( & ( V_24 -> V_64 ) ,
V_43 -> V_65 ) ;
F_2 ((0 == result),
L_8 , return result;) ;
}
if ( V_47 == V_24 -> V_27 ) {
V_45 = F_20 ( V_5 ,
V_66 , V_50 ,
& V_24 -> V_67 ) ;
F_2 ((0 == result),
L_9 , return result;) ;
} else if ( V_52 == V_24 -> V_27 ) {
if ( V_5 -> V_53 == V_56 )
V_45 = F_18 ( & V_24 -> V_67 ,
V_5 -> V_57 . V_68 ) ;
else if ( V_5 -> V_53 == V_54 )
V_45 = F_23 ( & ( V_24 -> V_67 ) ,
V_43 -> V_69 ) ;
F_2 ((0 == result),
L_10 , return result;) ;
}
V_46 = F_24 ( V_5 -> V_21 , V_70 ) ;
F_2 (
( V_24 -> V_67 . V_37 <= V_46 ) ,
L_11 ,
F_25 ( V_46 ,
& ( V_24 -> V_67 ) ) ) ;
V_46 = F_24 ( V_5 -> V_21 , V_71 ) ;
F_2 (
( V_24 -> V_64 . V_37 <= V_46 ) ,
L_11 ,
F_25 ( V_46 ,
& ( V_24 -> V_64 ) ) ) ;
V_46 = F_24 ( V_5 -> V_21 , V_72 ) ;
F_2 (
( V_24 -> V_61 . V_37 <= V_46 ) ,
L_12 ,
F_25 ( V_46 ,
& ( V_24 -> V_61 ) ) ) ;
V_46 = F_24 ( V_5 -> V_21 , V_73 ) ;
F_2 (
( V_24 -> V_51 . V_37 <= V_46 ) ,
L_13 ,
F_25 ( V_46 ,
& ( V_24 -> V_51 ) ) ) ;
return 0 ;
}
static int F_26 (
struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
F_17 ( V_5 -> V_6 , V_28 ,
V_74 , V_75 ,
V_24 -> V_76 ) ;
F_17 ( V_5 -> V_6 , V_28 ,
V_74 , V_77 ,
V_24 -> V_78 ) ;
return 0 ;
}
static int F_27 ( struct V_4 * V_5 )
{
T_2 V_79 =
F_8 ( V_5 -> V_6 , V_28 ,
V_80 ) ;
V_79 = F_28 ( V_79 , V_81 ,
V_82 , V_83 ) ;
V_79 = F_28 ( V_79 , V_81 ,
V_84 , V_85 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_80 , V_79 ) ;
return 0 ;
}
static int F_30 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
F_17 ( V_5 -> V_6 , V_28 ,
V_86 , V_87 , 0 ) ;
F_17 ( V_5 -> V_6 , V_28 ,
V_86 , V_88 , 0 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_89 , V_24 -> V_90 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_91 , V_24 -> V_92 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_93 , V_24 -> V_94 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_95 , V_24 -> V_96 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_97 , V_24 -> V_98 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_99 , V_24 -> V_100 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_101 , V_24 -> V_102 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_103 , V_24 -> V_104 ) ;
return 0 ;
}
static int F_31 ( struct V_4 * V_5 )
{
F_17 ( V_5 -> V_6 , V_28 ,
V_86 , V_87 , 1 ) ;
F_17 ( V_5 -> V_6 , V_28 ,
V_86 , V_88 , 1 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_89 , 0 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_91 , 0 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_93 , 0 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_95 , 0 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_97 , 0 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_99 , 0 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_101 , 0 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_103 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 ,
T_2 V_105 , T_2 V_106 )
{
T_2 V_107 ;
T_2 V_108 ;
T_2 V_109 ;
T_2 V_110 ;
switch ( V_105 ) {
case V_111 :
V_107 = F_6 ( V_5 -> V_6 , V_112 ) ;
V_108 = F_6 ( V_5 -> V_6 , V_113 ) ;
V_109 = F_33 ( V_5 -> V_6 , V_114 , V_115 ) ;
break;
case V_116 :
V_107 = F_6 ( V_5 -> V_6 , V_117 ) ;
V_108 = F_6 ( V_5 -> V_6 , V_118 ) ;
V_109 = F_33 ( V_5 -> V_6 , V_114 , V_119 ) ;
break;
default:
return - V_120 ;
}
switch ( V_106 ) {
case V_111 :
F_5 ( V_5 -> V_6 , V_112 , V_107 ) ;
F_5 ( V_5 -> V_6 , V_113 , V_108 ) ;
F_34 ( V_5 -> V_6 , V_114 , V_115 , V_109 ) ;
break;
case V_116 :
F_5 ( V_5 -> V_6 , V_117 , V_107 ) ;
F_5 ( V_5 -> V_6 , V_118 , V_108 ) ;
F_34 ( V_5 -> V_6 , V_114 , V_119 , V_109 ) ;
break;
default:
return - V_120 ;
}
V_110 = F_6 ( V_5 -> V_6 , V_121 ) ;
V_110 |= 0x0000000F ;
F_5 ( V_5 -> V_6 , V_121 , V_110 ) ;
F_34 ( V_5 -> V_6 , V_122 , V_123 , V_106 ) ;
return 0 ;
}
static int F_35 ( struct V_4 * V_5 )
{
return F_14 ( V_5 -> V_21 , V_124 ) ;
}
static int F_36 ( struct V_4 * V_5 )
{
return F_32 ( V_5 ,
V_111 , V_116 ) ;
}
static int F_37 ( struct V_4 * V_5 )
{
T_2 V_46 ;
V_46 = ( F_8 ( V_5 -> V_6 ,
V_28 , V_125 ) &
0x0000ff00 ) >> 8 ;
if ( V_46 == V_111 )
return 0 ;
return F_32 ( V_5 ,
V_46 , V_111 ) ;
}
static int F_38 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_126 * V_127 = NULL ;
T_2 V_34 , V_128 ;
T_2 V_46 ;
F_2 ((data->use_pcie_performance_levels ||
data->use_pcie_power_saving_levels), L_14 ,
return -EINVAL) ;
if ( V_43 != NULL )
V_127 = V_43 -> V_127 ;
if ( V_24 -> V_129 &&
! V_24 -> V_130 ) {
V_24 -> V_131 = V_24 -> V_132 ;
V_24 -> V_133 = V_24 -> V_134 ;
} else if ( ! V_24 -> V_129 &&
V_24 -> V_130 ) {
V_24 -> V_132 = V_24 -> V_131 ;
V_24 -> V_134 = V_24 -> V_133 ;
}
V_46 = F_24 ( V_5 -> V_21 , V_135 ) ;
F_39 ( & V_24 -> V_136 . V_137 ,
V_46 ,
V_138 ) ;
if ( V_127 != NULL ) {
V_128 = ( V_46 < V_127 -> V_37 ) ? V_46 : V_127 -> V_37 ;
for ( V_34 = 1 ; V_34 < V_128 ; V_34 ++ ) {
F_40 ( & V_24 -> V_136 . V_137 , V_34 - 1 ,
F_41 ( V_24 -> V_139 ,
V_127 -> V_38 [ V_34 ] . V_140 ) ,
F_42 ( V_24 -> V_141 ,
V_127 -> V_38 [ V_34 ] . V_142 ) ) ;
}
V_24 -> V_136 . V_137 . V_37 = V_128 - 1 ;
F_43 ( V_5 , V_143 ) ;
} else {
F_40 ( & V_24 -> V_136 . V_137 , 0 ,
F_41 ( V_24 -> V_139 ,
V_144 ) ,
F_42 ( V_24 -> V_141 ,
V_145 ) ) ;
F_40 ( & V_24 -> V_136 . V_137 , 1 ,
F_41 ( V_24 -> V_139 ,
V_144 ) ,
F_42 ( V_24 -> V_141 ,
V_145 ) ) ;
F_40 ( & V_24 -> V_136 . V_137 , 2 ,
F_41 ( V_24 -> V_139 ,
V_146 ) ,
F_42 ( V_24 -> V_141 ,
V_145 ) ) ;
F_40 ( & V_24 -> V_136 . V_137 , 3 ,
F_41 ( V_24 -> V_139 ,
V_146 ) ,
F_42 ( V_24 -> V_141 ,
V_145 ) ) ;
F_40 ( & V_24 -> V_136 . V_137 , 4 ,
F_41 ( V_24 -> V_139 ,
V_146 ) ,
F_42 ( V_24 -> V_141 ,
V_145 ) ) ;
F_40 ( & V_24 -> V_136 . V_137 , 5 ,
F_41 ( V_24 -> V_139 ,
V_146 ) ,
F_42 ( V_24 -> V_141 ,
V_145 ) ) ;
V_24 -> V_136 . V_137 . V_37 = 6 ;
}
F_40 ( & V_24 -> V_136 . V_137 ,
V_24 -> V_136 . V_137 . V_37 ,
F_41 ( V_24 -> V_139 ,
V_144 ) ,
F_42 ( V_24 -> V_141 ,
V_145 ) ) ;
return 0 ;
}
static int F_44 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
memset ( & ( V_24 -> V_136 ) , 0x00 , sizeof( V_24 -> V_136 ) ) ;
F_39 (
& V_24 -> V_136 . V_147 ,
F_24 ( V_5 -> V_21 ,
V_148 ) ,
V_138 ) ;
F_39 (
& V_24 -> V_136 . V_149 ,
F_24 ( V_5 -> V_21 ,
V_150 ) , V_138 ) ;
F_39 (
& V_24 -> V_136 . V_151 ,
F_24 ( V_5 -> V_21 ,
V_70 ) ,
V_138 ) ;
F_39 (
& V_24 -> V_136 . V_152 ,
F_24 ( V_5 -> V_21 ,
V_72 ) , V_138 ) ;
F_39 (
& V_24 -> V_136 . V_153 ,
F_24 ( V_5 -> V_21 ,
V_73 ) ,
V_138 ) ;
return 0 ;
}
static int F_45 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_32 * V_154 =
V_5 -> V_57 . V_155 ;
struct V_32 * V_156 =
V_5 -> V_57 . V_68 ;
struct V_157 * V_158 =
V_5 -> V_57 . V_159 ;
T_2 V_34 ;
F_2 (allowed_vdd_sclk_table != NULL,
L_15 , return -EINVAL) ;
F_2 (allowed_vdd_sclk_table->count >= 1 ,
L_16 , return -EINVAL) ;
F_2 (allowed_vdd_mclk_table != NULL,
L_17 , return -EINVAL) ;
F_2 (allowed_vdd_mclk_table->count >= 1 ,
L_18 , return -EINVAL) ;
V_24 -> V_136 . V_147 . V_37 = 0 ;
for ( V_34 = 0 ; V_34 < V_154 -> V_37 ; V_34 ++ ) {
if ( V_34 == 0 || V_24 -> V_136 . V_147 . V_160 [ V_24 -> V_136 . V_147 . V_37 - 1 ] . V_39 !=
V_154 -> V_38 [ V_34 ] . V_161 ) {
V_24 -> V_136 . V_147 . V_160 [ V_24 -> V_136 . V_147 . V_37 ] . V_39 =
V_154 -> V_38 [ V_34 ] . V_161 ;
V_24 -> V_136 . V_147 . V_160 [ V_24 -> V_136 . V_147 . V_37 ] . V_162 = 1 ;
V_24 -> V_136 . V_147 . V_37 ++ ;
}
}
F_2 (allowed_vdd_mclk_table != NULL,
L_17 , return -EINVAL) ;
V_24 -> V_136 . V_149 . V_37 = 0 ;
for ( V_34 = 0 ; V_34 < V_156 -> V_37 ; V_34 ++ ) {
if ( V_34 == 0 || V_24 -> V_136 . V_149 . V_160 [ V_24 -> V_136 . V_149 . V_37 - 1 ] . V_39 !=
V_156 -> V_38 [ V_34 ] . V_161 ) {
V_24 -> V_136 . V_149 . V_160 [ V_24 -> V_136 . V_149 . V_37 ] . V_39 =
V_156 -> V_38 [ V_34 ] . V_161 ;
V_24 -> V_136 . V_149 . V_160 [ V_24 -> V_136 . V_149 . V_37 ] . V_162 = 1 ;
V_24 -> V_136 . V_149 . V_37 ++ ;
}
}
for ( V_34 = 0 ; V_34 < V_154 -> V_37 ; V_34 ++ ) {
V_24 -> V_136 . V_151 . V_160 [ V_34 ] . V_39 = V_156 -> V_38 [ V_34 ] . V_40 ;
V_24 -> V_136 . V_151 . V_160 [ V_34 ] . V_163 = V_158 -> V_38 [ V_34 ] . V_164 ;
V_24 -> V_136 . V_151 . V_160 [ V_34 ] . V_162 = 1 ;
}
V_24 -> V_136 . V_151 . V_37 = V_154 -> V_37 ;
V_156 = V_5 -> V_57 . V_62 ;
if ( NULL != V_156 ) {
for ( V_34 = 0 ; V_34 < V_156 -> V_37 ; V_34 ++ ) {
V_24 -> V_136 . V_152 . V_160 [ V_34 ] . V_39 = V_156 -> V_38 [ V_34 ] . V_40 ;
V_24 -> V_136 . V_152 . V_160 [ V_34 ] . V_162 = 1 ;
}
V_24 -> V_136 . V_152 . V_37 = V_156 -> V_37 ;
}
V_156 = V_5 -> V_57 . V_58 ;
if ( NULL != V_156 ) {
for ( V_34 = 0 ; V_34 < V_156 -> V_37 ; V_34 ++ ) {
V_24 -> V_136 . V_153 . V_160 [ V_34 ] . V_39 = V_156 -> V_38 [ V_34 ] . V_40 ;
V_24 -> V_136 . V_153 . V_160 [ V_34 ] . V_162 = 1 ;
}
V_24 -> V_136 . V_153 . V_37 = V_156 -> V_37 ;
}
return 0 ;
}
static int F_46 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
T_2 V_34 ;
struct V_165 * V_166 ;
struct V_165 * V_167 ;
if ( V_43 == NULL )
return - V_120 ;
V_166 = V_43 -> V_168 ;
V_167 = V_43 -> V_55 ;
F_2 (dep_sclk_table != NULL,
L_19 ,
return -EINVAL) ;
F_2 (dep_sclk_table->count >= 1 ,
L_20 ,
return -EINVAL) ;
F_2 (dep_mclk_table != NULL,
L_21 ,
return -EINVAL) ;
F_2 (dep_mclk_table->count >= 1 ,
L_22 ,
return -EINVAL) ;
V_24 -> V_136 . V_147 . V_37 = 0 ;
for ( V_34 = 0 ; V_34 < V_166 -> V_37 ; V_34 ++ ) {
if ( V_34 == 0 || V_24 -> V_136 . V_147 . V_160 [ V_24 -> V_136 . V_147 . V_37 - 1 ] . V_39 !=
V_166 -> V_38 [ V_34 ] . V_161 ) {
V_24 -> V_136 . V_147 . V_160 [ V_24 -> V_136 . V_147 . V_37 ] . V_39 =
V_166 -> V_38 [ V_34 ] . V_161 ;
V_24 -> V_136 . V_147 . V_160 [ V_24 -> V_136 . V_147 . V_37 ] . V_162 =
( V_34 == 0 ) ? true : false ;
V_24 -> V_136 . V_147 . V_37 ++ ;
}
}
V_24 -> V_136 . V_149 . V_37 = 0 ;
for ( V_34 = 0 ; V_34 < V_167 -> V_37 ; V_34 ++ ) {
if ( V_34 == 0 || V_24 -> V_136 . V_149 . V_160
[ V_24 -> V_136 . V_149 . V_37 - 1 ] . V_39 !=
V_167 -> V_38 [ V_34 ] . V_161 ) {
V_24 -> V_136 . V_149 . V_160 [ V_24 -> V_136 . V_149 . V_37 ] . V_39 =
V_167 -> V_38 [ V_34 ] . V_161 ;
V_24 -> V_136 . V_149 . V_160 [ V_24 -> V_136 . V_149 . V_37 ] . V_162 =
( V_34 == 0 ) ? true : false ;
V_24 -> V_136 . V_149 . V_37 ++ ;
}
}
return 0 ;
}
static int F_47 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
F_44 ( V_5 ) ;
if ( V_5 -> V_53 == V_54 )
F_46 ( V_5 ) ;
else if ( V_5 -> V_53 == V_56 )
F_45 ( V_5 ) ;
F_38 ( V_5 ) ;
memcpy ( & ( V_24 -> V_169 ) , & ( V_24 -> V_136 ) ,
sizeof( struct V_170 ) ) ;
return 0 ;
}
T_2 F_48 ( struct V_4 * V_5 )
{
T_2 V_171 , V_46 ;
struct V_172 V_173 = { 0 } ;
struct V_174 V_175 ;
V_173 . V_175 = & V_175 ;
V_46 = F_49 ( V_5 -> V_6 , V_28 , V_176 , V_177 ) ;
if ( V_46 )
return V_178 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_171 = V_175 . V_179 ;
V_46 = F_49 ( V_5 -> V_6 , V_28 , V_180 , V_181 ) ;
if ( 0 != V_46 )
return V_171 / 4 ;
return V_171 ;
}
static int F_51 ( struct V_4 * V_5 )
{
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_184 ) )
return F_14 ( V_5 -> V_21 ,
V_185 ) ;
return 0 ;
}
static int F_53 ( struct V_4 * V_5 )
{
F_17 ( V_5 -> V_6 , V_28 , V_86 ,
V_186 , 0 ) ;
return 0 ;
}
static int F_54 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_24 -> V_187 )
return F_14 ( V_5 -> V_21 , V_188 ) ;
return 0 ;
}
static int F_55 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_24 -> V_187 )
return F_14 ( V_5 -> V_21 , V_189 ) ;
return 0 ;
}
static int F_56 ( struct V_4 * V_5 )
{
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_190 ) ) {
if ( F_14 ( V_5 -> V_21 , V_191 ) )
F_2 (false,
L_23 ,
return -EINVAL) ;
} else {
if ( F_14 ( V_5 -> V_21 ,
V_192 ) ) {
F_2 (false,
L_24 ,
return -EINVAL) ;
}
}
return 0 ;
}
static int F_57 ( struct V_4 * V_5 )
{
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_190 ) ) {
if ( F_14 ( V_5 -> V_21 ,
V_192 ) ) {
F_2 (false,
L_24 ,
return -EINVAL) ;
}
}
return 0 ;
}
static int F_58 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_193 = 0 ;
T_2 V_194 = V_24 -> V_195
+ F_59 ( V_5 -> V_21 ,
V_196 , V_197 ) ;
V_193 = F_8 ( V_5 -> V_6 ,
V_28 , V_194 ) ;
V_193 |= F_24 ( V_5 -> V_21 ,
V_198 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_194 , V_193 ) ;
return 0 ;
}
static int F_60 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( ! V_24 -> V_199 )
F_2 (
(0 == smum_send_msg_to_smc(hwmgr->smumgr, PPSMC_MSG_DPM_Enable)),
L_25 ,
return -EINVAL) ;
if ( 0 == V_24 -> V_200 ) {
if ( ! ( V_5 -> V_19 & V_201 ) )
F_58 ( V_5 ) ;
F_2 (
(0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_MCLKDPM_Enable)),
L_26 ,
return -EINVAL) ;
F_34 ( V_5 -> V_6 , V_202 , V_203 , 0x1 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_204 , 0x5 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_205 , 0x5 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_206 , 0x100005 ) ;
F_61 ( 10 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_204 , 0x400005 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_205 , 0x400005 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_206 , 0x500005 ) ;
}
return 0 ;
}
static int F_62 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
F_17 ( V_5 -> V_6 , V_28 , V_29 ,
V_207 , 1 ) ;
F_17 ( V_5 -> V_6 , V_28 , V_86 ,
V_208 , 1 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_24 -> V_195 +
F_59 ( V_5 -> V_21 , V_196 ,
V_209 ) , 0x1000 ) ;
F_17 ( V_5 -> V_6 , V_12 ,
V_210 , V_211 , 0x0 ) ;
if ( F_60 ( V_5 ) ) {
F_63 ( V_212 L_27 ) ;
return - V_120 ;
}
if ( 0 == V_24 -> V_213 ) {
F_2 (
(0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_PCIeDPM_Enable)),
L_28 ,
return -EINVAL) ;
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_214 ) ) {
F_2 ( ( 0 == F_14 ( V_5 -> V_21 ,
V_215 ) ) ,
L_29 ,
) ;
}
return 0 ;
}
static int F_64 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( ! V_24 -> V_199 ) {
F_2 (true == smum_is_dpm_running(hwmgr),
L_30 ,
return 0 ) ;
F_14 ( V_5 -> V_21 , V_216 ) ;
}
if ( ! V_24 -> V_200 ) {
F_2 (true == smum_is_dpm_running(hwmgr),
L_31 ,
return 0 ) ;
F_14 ( V_5 -> V_21 , V_217 ) ;
}
return 0 ;
}
static int F_65 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
F_17 ( V_5 -> V_6 , V_28 , V_29 ,
V_207 , 0 ) ;
F_17 ( V_5 -> V_6 , V_28 , V_86 ,
V_208 , 0 ) ;
if ( ! V_24 -> V_213 ) {
F_2 (
(smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_PCIeDPM_Disable) == 0),
L_32 ,
return -EINVAL) ;
}
F_64 ( V_5 ) ;
F_2 (true == smum_is_dpm_running(hwmgr),
L_33 ,
return 0 ) ;
F_14 ( V_5 -> V_21 , V_218 ) ;
return 0 ;
}
static void F_66 ( struct V_4 * V_5 , T_2 V_219 )
{
bool V_220 ;
enum V_221 V_222 ;
switch ( V_219 ) {
default:
F_63 ( V_212 L_34 ) ;
case 0 :
V_220 = false ;
break;
case ( 1 << V_223 ) :
V_220 = true ;
V_222 = V_224 ;
break;
case ( 1 << V_225 ) :
V_220 = true ;
V_222 = V_226 ;
break;
case ( 1 << V_225 ) |
( 1 << V_223 ) :
V_220 = true ;
V_222 = V_227 ;
break;
}
if ( V_220 ) {
F_17 ( V_5 -> V_6 , V_28 , V_228 ,
V_221 , V_222 ) ;
F_17 ( V_5 -> V_6 , V_28 , V_29 ,
V_229 ,
! F_52 ( V_5 -> V_182 . V_183 ,
V_230 ) ) ;
} else
F_17 ( V_5 -> V_6 , V_28 , V_29 ,
V_229 , 1 ) ;
}
static int F_67 ( struct V_4 * V_5 ,
T_4 V_231 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( ! ( V_24 -> V_232 & ( 1 << V_231 ) ) ) {
V_24 -> V_232 |= 1 << V_231 ;
F_66 ( V_5 , V_24 -> V_232 ) ;
}
return 0 ;
}
static int F_68 ( struct V_4 * V_5 )
{
return F_67 ( V_5 , V_223 ) ;
}
static int F_69 ( struct V_4 * V_5 ,
T_4 V_231 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_24 -> V_232 & ( 1 << V_231 ) ) {
V_24 -> V_232 &= ~ ( 1 << V_231 ) ;
F_66 ( V_5 , V_24 -> V_232 ) ;
}
return 0 ;
}
static int F_70 ( struct V_4 * V_5 )
{
return F_69 ( V_5 , V_223 ) ;
}
static int F_71 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_233 = true ;
return 0 ;
}
static int F_72 ( struct V_4 * V_5 )
{
int V_234 = 0 ;
int V_45 = 0 ;
V_234 = ( ! F_73 ( V_5 ) ) ? 0 : - 1 ;
F_2 ( V_234 == 0 ,
L_35 ,
) ;
if ( F_15 ( V_5 ) ) {
V_234 = F_16 ( V_5 ) ;
F_2 ( V_234 == 0 ,
L_36 ,
V_45 = V_234 ) ;
V_234 = F_19 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_37 ,
V_45 = V_234 ) ;
}
F_74 ( V_5 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_235 ) )
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_236 , 1 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_230 ) )
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_229 , 0 ) ;
V_234 = F_26 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_38 ,
V_45 = V_234 ) ;
V_234 = F_27 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_39 , V_45 = V_234 ) ;
V_234 = F_30 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_40 , V_45 = V_234 ) ;
V_234 = F_75 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_41 , V_45 = V_234 ) ;
V_234 = F_36 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_42 ,
V_45 = V_234 ) ;
V_45 = F_47 ( V_5 ) ;
F_2 ( 0 == result,
L_43 , return result) ;
V_234 = F_76 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_44 , V_45 = V_234 ) ;
V_234 = F_51 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_45 , V_45 = V_234 ) ;
F_14 ( V_5 -> V_21 , ( V_237 ) V_238 ) ;
V_234 = F_53 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_46 , V_45 = V_234 ) ;
V_234 = F_13 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_36 , V_45 = V_234 ) ;
V_234 = F_54 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_47 , V_45 = V_234 ) ;
V_234 = F_56 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_48 , V_45 = V_234 ) ;
V_234 = F_77 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_48 , V_45 = V_234 ) ;
V_234 = F_62 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_49 , V_45 = V_234 ) ;
V_234 = F_78 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_50 , V_45 = V_234 ) ;
V_234 = F_79 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_51 , V_45 = V_234 ) ;
V_234 = F_80 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_52 , V_45 = V_234 ) ;
V_234 = F_68 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_53 , V_45 = V_234 ) ;
V_234 = F_71 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_54 , V_45 = V_234 ) ;
return 0 ;
}
int F_81 ( struct V_4 * V_5 )
{
int V_234 , V_45 = 0 ;
V_234 = ( F_73 ( V_5 ) ) ? 0 : - 1 ;
F_2 (tmp_result == 0 ,
L_55 ,
return 0 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_230 ) )
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_229 , 1 ) ;
V_234 = F_82 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_56 , V_45 = V_234 ) ;
V_234 = F_83 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_57 , V_45 = V_234 ) ;
F_17 ( V_5 -> V_6 , V_28 ,
V_239 , V_240 , 0 ) ;
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_236 , 0 ) ;
V_234 = F_70 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_58 , V_45 = V_234 ) ;
if ( 1 == F_49 ( V_5 -> V_6 , V_28 , V_241 , V_242 ) ) {
F_2 ((0 == smum_send_msg_to_smc(hwmgr->smumgr, PPSMC_MSG_DisableAvfs)),
L_59 ,
return -EINVAL) ;
}
V_234 = F_65 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_60 , V_45 = V_234 ) ;
V_234 = F_57 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_61 , V_45 = V_234 ) ;
V_234 = F_55 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_62 , V_45 = V_234 ) ;
V_234 = F_31 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_63 , V_45 = V_234 ) ;
V_234 = F_35 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_64 , V_45 = V_234 ) ;
V_234 = F_37 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_65 , V_45 = V_234 ) ;
return V_45 ;
}
int F_84 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_85 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_243 V_244 = { 0 } ;
int V_45 ;
V_24 -> V_245 = false ;
V_24 -> V_246 = 0xa ;
V_24 -> V_247 = V_248 ;
V_24 -> V_249 = 300 ;
V_24 -> V_78 = V_250 ;
V_24 -> V_76 = V_251 ;
V_24 -> V_90 = V_252 ;
V_24 -> V_92 = V_253 ;
V_24 -> V_94 = V_254 ;
V_24 -> V_96 = V_255 ;
V_24 -> V_98 = V_256 ;
V_24 -> V_100 = V_257 ;
V_24 -> V_102 = V_258 ;
V_24 -> V_104 = V_259 ;
V_24 -> V_200 = V_5 -> V_19 & V_260 ? false : true ;
V_24 -> V_199 = V_5 -> V_19 & V_261 ? false : true ;
V_24 -> V_213 = V_5 -> V_19 & V_262 ? false : true ;
V_24 -> V_27 = V_26 ;
V_24 -> V_59 = V_26 ;
V_24 -> V_48 = V_26 ;
V_24 -> V_263 = true ;
V_24 -> V_264 = true ;
V_24 -> V_265 = V_266 ;
V_24 -> V_187 = V_5 -> V_19 & V_267 ? true : false ;
V_24 -> V_268 = 100 ;
if ( F_86 ( V_5 ,
V_66 , V_269 ) )
V_24 -> V_27 = V_52 ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_270 ) ) {
if ( F_86 ( V_5 ,
V_271 , V_269 ) ) {
V_24 -> V_63 = V_52 ;
}
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_272 ) ) {
if ( F_86 ( V_5 ,
V_49 , V_50 ) )
V_24 -> V_48 = V_47 ;
else if ( F_86 ( V_5 ,
V_49 , V_269 ) )
V_24 -> V_48 = V_52 ;
}
if ( V_26 == V_24 -> V_63 ) {
F_87 ( V_5 -> V_182 . V_183 ,
V_270 ) ;
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_273 ) ) {
if ( F_86 ( V_5 ,
V_60 , V_50 ) )
V_24 -> V_59 = V_47 ;
else if ( F_86 ( V_5 ,
V_60 , V_269 ) )
V_24 -> V_59 = V_52 ;
}
if ( V_24 -> V_48 == V_26 )
F_87 ( V_5 -> V_182 . V_183 ,
V_272 ) ;
if ( V_24 -> V_59 == V_26 )
F_87 ( V_5 -> V_182 . V_183 ,
V_273 ) ;
if ( ( V_5 -> V_53 != V_56 ) && ( V_5 -> V_19 & V_274 )
&& ( V_43 -> V_275 -> V_276 != 0 ) )
F_88 ( V_5 -> V_182 . V_183 ,
V_277 ) ;
V_24 -> V_132 . V_278 = V_279 ;
V_24 -> V_132 . V_280 = V_281 ;
V_24 -> V_131 . V_278 = V_279 ;
V_24 -> V_131 . V_280 = V_281 ;
V_24 -> V_134 . V_278 = 0 ;
V_24 -> V_134 . V_280 = 16 ;
V_24 -> V_133 . V_278 = 0 ;
V_24 -> V_133 . V_280 = 16 ;
V_244 . V_282 = sizeof( struct V_243 ) ;
V_244 . V_283 = V_284 ;
V_45 = F_89 ( V_5 -> V_6 , & V_244 ) ;
if ( ! V_45 ) {
if ( V_244 . V_39 & V_285 )
F_88 ( V_5 -> V_182 . V_183 ,
V_286 ) ;
if ( V_244 . V_39 & V_287 )
F_88 ( V_5 -> V_182 . V_183 ,
V_288 ) ;
}
}
static int F_90 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_1 V_289 ;
T_1 V_290 = 0 ;
T_1 V_291 = 0 ;
T_1 V_34 , V_292 ;
T_2 V_293 = 0 ;
struct V_42 * V_43 =
(struct V_42 * ) V_5 -> V_44 ;
struct V_165 * V_147 = NULL ;
for ( V_34 = 0 ; V_34 < V_294 ; V_34 ++ ) {
V_289 = V_295 + V_34 ;
if ( V_24 -> V_63 == V_52 ) {
if ( ( V_5 -> V_53 == V_54 )
&& ! F_91 ( V_5 ,
V_43 -> V_65 , V_289 , & V_293 ) ) {
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_277 ) ) {
V_147 = V_43 -> V_168 ;
for ( V_292 = 1 ; V_292 < V_147 -> V_37 ; V_292 ++ ) {
if ( V_147 -> V_38 [ V_292 ] . V_161 == V_293 &&
V_147 -> V_38 [ V_292 ] . V_296 == 0 ) {
V_293 += 5000 ;
break;
}
}
}
if ( 0 == F_92
( V_5 , V_271 , V_293 ,
V_289 , & V_291 ) ) {
F_2 ((vddgfx < 2000 && vddgfx != 0), L_66 , return -EINVAL) ;
if ( V_291 != 0 && V_291 != V_289 ) {
V_24 -> V_297 . V_298 [ V_24 -> V_297 . V_37 ] = V_291 ;
V_24 -> V_297 . V_299 [ V_24 -> V_297 . V_37 ] = V_289 ;
V_24 -> V_297 . V_37 ++ ;
}
} else {
F_63 ( L_67 ) ;
}
}
} else {
if ( ( V_5 -> V_53 == V_56 )
|| ! F_91 ( V_5 ,
V_43 -> V_69 , V_289 , & V_293 ) ) {
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_277 ) ) {
if ( V_43 == NULL )
return - V_120 ;
V_147 = V_43 -> V_168 ;
for ( V_292 = 1 ; V_292 < V_147 -> V_37 ; V_292 ++ ) {
if ( V_147 -> V_38 [ V_292 ] . V_161 == V_293 &&
V_147 -> V_38 [ V_292 ] . V_296 == 0 ) {
V_293 += 5000 ;
break;
}
}
}
if ( F_93 ( V_5 ,
V_66 ,
V_293 , V_289 , & V_290 ) == 0 ) {
if ( V_290 >= 2000 || V_290 == 0 )
return - V_120 ;
} else {
F_63 ( V_300 L_68 ) ;
continue;
}
if ( V_290 != 0 && V_290 != V_289 ) {
V_24 -> V_301 . V_298 [ V_24 -> V_301 . V_37 ] = ( T_1 ) ( V_290 ) ;
V_24 -> V_301 . V_299 [ V_24 -> V_301 . V_37 ] = V_289 ;
V_24 -> V_301 . V_37 ++ ;
}
}
}
}
return 0 ;
}
static void F_94 ( struct V_4 * V_5 ,
T_1 * V_302 , struct V_303 * V_304 )
{
T_2 V_305 ;
for ( V_305 = 0 ; V_305 < V_304 -> V_37 ; V_305 ++ ) {
if ( V_304 -> V_299 [ V_305 ] == * V_302 ) {
* V_302 = V_304 -> V_298 [ V_305 ] ;
break;
}
}
if ( * V_302 > V_295 )
F_63 ( V_212 L_69 ) ;
}
static int F_95 ( struct V_4 * V_5 ,
T_5 * V_306 ,
struct V_303 * V_304 )
{
T_2 V_34 ;
for ( V_34 = 0 ; V_34 < V_306 -> V_37 ; V_34 ++ )
F_94 ( V_5 ,
& V_306 -> V_38 [ V_34 ] . V_307 , V_304 ) ;
return 0 ;
}
static int F_96 (
struct V_4 * V_5 , struct V_303 * V_304 ,
T_1 * V_290 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
F_94 ( V_5 , ( T_1 * ) V_290 , V_304 ) ;
V_5 -> V_57 . V_308 . V_290 =
V_43 -> V_308 . V_290 ;
return 0 ;
}
static int F_97 (
struct V_4 * V_5 )
{
T_6 V_309 ;
T_6 V_310 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_147 =
V_43 -> V_168 ;
struct V_165 * V_149 =
V_43 -> V_55 ;
struct V_311 * V_312 =
V_43 -> V_313 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_309 = 0 ; V_309 < V_147 -> V_37 ; ++ V_309 ) {
V_310 = V_147 -> V_38 [ V_309 ] . V_314 ;
V_147 -> V_38 [ V_309 ] . V_291 =
V_43 -> V_65 -> V_38 [ V_310 ] . V_307 ;
}
} else {
for ( V_309 = 0 ; V_309 < V_147 -> V_37 ; ++ V_309 ) {
V_310 = V_147 -> V_38 [ V_309 ] . V_314 ;
V_147 -> V_38 [ V_309 ] . V_290 =
V_43 -> V_69 -> V_38 [ V_310 ] . V_307 ;
}
}
for ( V_309 = 0 ; V_309 < V_149 -> V_37 ; ++ V_309 ) {
V_310 = V_149 -> V_38 [ V_309 ] . V_314 ;
V_149 -> V_38 [ V_309 ] . V_290 =
V_43 -> V_69 -> V_38 [ V_310 ] . V_307 ;
}
for ( V_309 = 0 ; V_309 < V_312 -> V_37 ; ++ V_309 ) {
V_310 = V_312 -> V_38 [ V_309 ] . V_315 ;
V_312 -> V_38 [ V_309 ] . V_290 =
V_43 -> V_69 -> V_38 [ V_310 ] . V_307 ;
}
return 0 ;
}
static int F_98 ( struct V_4 * V_5 ,
T_5 * V_316 ,
T_7 * V_317 )
{
T_2 V_34 ;
F_2 ((NULL != look_up_table),
L_70 , return -EINVAL) ;
F_2 ((0 != look_up_table->count),
L_70 , return -EINVAL) ;
V_34 = F_24 ( V_5 -> V_21 , V_71 ) ;
F_2 ((i >= look_up_table->count),
L_71 , return -EINVAL) ;
for ( V_34 = 0 ; V_34 < V_316 -> V_37 ; V_34 ++ ) {
if ( V_316 -> V_38 [ V_34 ] . V_307 == V_317 -> V_307 ) {
if ( V_316 -> V_38 [ V_34 ] . V_318 == 1 )
return 0 ;
break;
}
}
V_316 -> V_38 [ V_34 ] . V_318 = 1 ;
V_316 -> V_38 [ V_34 ] . V_307 = V_317 -> V_307 ;
V_316 -> V_38 [ V_34 ] . V_319 = V_317 -> V_319 ;
V_316 -> V_38 [ V_34 ] . V_320 = V_317 -> V_320 ;
V_316 -> V_38 [ V_34 ] . V_321 = V_317 -> V_321 ;
if ( V_34 == V_316 -> V_37 )
V_316 -> V_37 ++ ;
return 0 ;
}
static int F_99 ( struct V_4 * V_5 )
{
T_6 V_309 ;
struct T_7 V_322 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_323 = (struct V_42 * ) ( V_5 -> V_44 ) ;
V_165 * V_147 = V_323 -> V_168 ;
V_165 * V_149 = V_323 -> V_55 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_309 = 0 ; V_309 < V_147 -> V_37 ; ++ V_309 ) {
if ( V_147 -> V_38 [ V_309 ] . V_324 & ( 1 << 15 ) )
V_322 . V_307 = V_147 -> V_38 [ V_309 ] . V_291 +
V_147 -> V_38 [ V_309 ] . V_324 - 0xFFFF ;
else
V_322 . V_307 = V_147 -> V_38 [ V_309 ] . V_291 +
V_147 -> V_38 [ V_309 ] . V_324 ;
V_147 -> V_38 [ V_309 ] . V_290 =
V_322 . V_319 = V_322 . V_320 =
V_322 . V_321 = V_322 . V_307 ;
F_98 ( V_5 , V_323 -> V_69 , & V_322 ) ;
}
for ( V_309 = 0 ; V_309 < V_149 -> V_37 ; ++ V_309 ) {
if ( V_149 -> V_38 [ V_309 ] . V_324 & ( 1 << 15 ) )
V_322 . V_307 = V_149 -> V_38 [ V_309 ] . V_290 +
V_149 -> V_38 [ V_309 ] . V_324 - 0xFFFF ;
else
V_322 . V_307 = V_149 -> V_38 [ V_309 ] . V_290 +
V_149 -> V_38 [ V_309 ] . V_324 ;
V_149 -> V_38 [ V_309 ] . V_291 = V_322 . V_319 =
V_322 . V_320 = V_322 . V_321 = V_322 . V_307 ;
F_98 ( V_5 , V_323 -> V_65 , & V_322 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_4 * V_5 )
{
T_6 V_309 ;
struct T_7 V_322 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_323 = (struct V_42 * ) ( V_5 -> V_44 ) ;
V_311 * V_312 = V_323 -> V_313 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_309 = 0 ; V_309 < V_312 -> V_37 ; V_309 ++ ) {
if ( V_312 -> V_38 [ V_309 ] . V_325 & ( 1 << 15 ) )
V_322 . V_307 = V_312 -> V_38 [ V_309 ] . V_290 +
V_312 -> V_38 [ V_309 ] . V_325 - 0xFFFF ;
else
V_322 . V_307 = V_312 -> V_38 [ V_309 ] . V_290 +
V_312 -> V_38 [ V_309 ] . V_325 ;
V_312 -> V_38 [ V_309 ] . V_291 = V_322 . V_319 =
V_322 . V_320 = V_322 . V_321 = V_322 . V_307 ;
F_98 ( V_5 , V_323 -> V_65 , & V_322 ) ;
}
}
return 0 ;
}
static int F_101 ( struct V_4 * V_5 ,
struct T_5 * V_306 )
{
T_2 V_326 , V_34 , V_292 ;
struct T_7 V_327 ;
V_326 = V_306 -> V_37 ;
F_2 ( 0 != lookup_table->count,
L_72 , return -EINVAL) ;
for ( V_34 = 0 ; V_34 < V_326 - 1 ; V_34 ++ ) {
for ( V_292 = V_34 + 1 ; V_292 > 0 ; V_292 -- ) {
if ( V_306 -> V_38 [ V_292 ] . V_307 <
V_306 -> V_38 [ V_292 - 1 ] . V_307 ) {
V_327 = V_306 -> V_38 [ V_292 - 1 ] ;
V_306 -> V_38 [ V_292 - 1 ] = V_306 -> V_38 [ V_292 ] ;
V_306 -> V_38 [ V_292 ] = V_327 ;
}
}
}
return 0 ;
}
static int F_102 ( struct V_4 * V_5 )
{
int V_45 = 0 ;
int V_234 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
if ( V_24 -> V_63 == V_52 ) {
V_234 = F_95 ( V_5 ,
V_43 -> V_65 , & ( V_24 -> V_297 ) ) ;
if ( V_234 != 0 )
V_45 = V_234 ;
F_94 ( V_5 ,
& V_43 -> V_308 . V_291 , & ( V_24 -> V_297 ) ) ;
} else {
V_234 = F_95 ( V_5 ,
V_43 -> V_69 , & ( V_24 -> V_301 ) ) ;
if ( V_234 )
V_45 = V_234 ;
V_234 = F_96 ( V_5 ,
& ( V_24 -> V_301 ) , & V_43 -> V_308 . V_290 ) ;
if ( V_234 )
V_45 = V_234 ;
}
V_234 = F_97 ( V_5 ) ;
if ( V_234 )
V_45 = V_234 ;
V_234 = F_99 ( V_5 ) ;
if ( V_234 )
V_45 = V_234 ;
V_234 = F_100 ( V_5 ) ;
if ( V_234 )
V_45 = V_234 ;
V_234 = F_101 ( V_5 , V_43 -> V_65 ) ;
if ( V_234 )
V_45 = V_234 ;
V_234 = F_101 ( V_5 , V_43 -> V_69 ) ;
if ( V_234 )
V_45 = V_234 ;
return V_45 ;
}
static int F_103 ( struct V_4 * V_5 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_328 =
V_43 -> V_168 ;
struct V_165 * V_329 =
V_43 -> V_55 ;
F_2 (allowed_sclk_vdd_table != NULL,
L_73 ,
return -EINVAL) ;
F_2 (allowed_sclk_vdd_table->count >= 1 ,
L_74 ,
return -EINVAL) ;
F_2 (allowed_mclk_vdd_table != NULL,
L_75 ,
return -EINVAL) ;
F_2 (allowed_mclk_vdd_table->count >= 1 ,
L_76 ,
return -EINVAL) ;
V_43 -> V_330 . V_293 =
V_328 -> V_38 [ V_328 -> V_37 - 1 ] . V_161 ;
V_43 -> V_330 . V_331 =
V_329 -> V_38 [ V_329 -> V_37 - 1 ] . V_161 ;
V_43 -> V_330 . V_290 =
V_328 -> V_38 [ V_328 -> V_37 - 1 ] . V_290 ;
V_43 -> V_330 . V_332 =
V_329 -> V_38 [ V_329 -> V_37 - 1 ] . V_332 ;
V_5 -> V_57 . V_330 . V_293 = V_43 -> V_330 . V_293 ;
V_5 -> V_57 . V_330 . V_331 = V_43 -> V_330 . V_331 ;
V_5 -> V_57 . V_330 . V_290 = V_43 -> V_330 . V_290 ;
V_5 -> V_57 . V_330 . V_332 = V_43 -> V_330 . V_332 ;
return 0 ;
}
static int F_104 ( struct V_4 * V_5 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_167 ;
struct T_5 * V_306 ;
T_2 V_34 ;
T_2 V_333 , V_334 , V_335 ;
struct V_243 V_244 = { 0 } ;
if ( V_43 != NULL ) {
V_167 = V_43 -> V_55 ;
V_306 = V_43 -> V_69 ;
} else
return 0 ;
V_244 . V_282 = sizeof( struct V_243 ) ;
V_244 . V_283 = V_336 ;
F_89 ( V_5 -> V_6 , & V_244 ) ;
V_333 = ( T_2 ) V_244 . V_39 ;
V_244 . V_283 = V_337 ;
F_89 ( V_5 -> V_6 , & V_244 ) ;
V_335 = ( T_2 ) V_244 . V_39 ;
V_244 . V_283 = V_338 ;
F_89 ( V_5 -> V_6 , & V_244 ) ;
V_334 = ( T_2 ) V_244 . V_39 ;
if ( V_5 -> V_339 == V_340 && V_333 == 0xC7 &&
( ( V_335 == 0xb37 && V_334 == 0x1002 ) ||
( V_335 == 0x4a8 && V_334 == 0x1043 ) ||
( V_335 == 0x9480 && V_334 == 0x1682 ) ) ) {
if ( V_306 -> V_38 [ V_167 -> V_38 [ V_167 -> V_37 - 1 ] . V_314 ] . V_307 >= 1000 )
return 0 ;
for ( V_34 = 0 ; V_34 < V_306 -> V_37 ; V_34 ++ ) {
if ( V_306 -> V_38 [ V_34 ] . V_307 < 0xff01 && V_306 -> V_38 [ V_34 ] . V_307 >= 1000 ) {
V_167 -> V_38 [ V_167 -> V_37 - 1 ] . V_314 = ( T_6 ) V_34 ;
return 0 ;
}
}
}
return 0 ;
}
static int F_105 ( struct V_4 * V_5 )
{
struct V_341 V_342 ;
T_2 V_343 ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
if ( F_106 ( V_5 , V_344 , & V_342 ) ) {
V_343 = F_8 ( V_5 -> V_6 , V_28 , V_345 ) ;
switch ( V_342 . V_346 ) {
case 0 :
V_343 = F_28 ( V_343 , V_347 , V_348 , 0x1 ) ;
break;
case 1 :
V_343 = F_28 ( V_343 , V_347 , V_348 , 0x2 ) ;
break;
case 2 :
V_343 = F_28 ( V_343 , V_347 , V_349 , 0x1 ) ;
break;
case 3 :
V_343 = F_28 ( V_343 , V_347 , V_350 , 0x1 ) ;
break;
case 4 :
V_343 = F_28 ( V_343 , V_347 , V_351 , 0x1 ) ;
break;
default:
F_2 ( 0 ,
L_77 ,
) ;
break;
}
F_29 ( V_5 -> V_6 , V_28 , V_345 , V_343 ) ;
}
if ( V_43 == NULL )
return 0 ;
if ( V_43 -> V_275 -> V_352 != 0 &&
V_5 -> V_353 . V_354 . V_355 ) {
V_5 -> V_353 . V_354 . V_356 =
( T_1 ) V_5 -> V_353 . V_354 . V_357 ;
V_5 -> V_353 . V_354 . V_358 =
( T_1 ) V_5 -> V_353 . V_354 . V_359 ;
V_5 -> V_353 . V_354 . V_360 = 1 ;
V_5 -> V_353 . V_354 . V_361 = 100 ;
V_5 -> V_353 . V_354 . V_362 =
( T_1 ) V_5 -> V_353 . V_354 . V_357 ;
V_5 -> V_353 . V_354 . V_363 = 1 ;
V_43 -> V_275 -> V_352 = ( V_43 -> V_275 -> V_352 >= 50 ) ?
( V_43 -> V_275 -> V_352 - 50 ) : 0 ;
V_43 -> V_275 -> V_364 = V_43 -> V_275 -> V_352 ;
V_43 -> V_275 -> V_365 = 1 ;
V_43 -> V_275 -> V_366 = 1 ;
V_5 -> V_353 . V_354 . V_367 =
V_5 -> V_353 . V_354 . V_359 ;
V_5 -> V_353 . V_354 . V_368 =
V_5 -> V_353 . V_354 . V_369 ;
V_5 -> V_57 . V_275 -> V_370 =
V_43 -> V_275 -> V_370 ;
V_5 -> V_57 . V_275 -> V_364 =
V_43 -> V_275 -> V_364 ;
V_5 -> V_57 . V_275 -> V_352 =
V_43 -> V_275 -> V_352 ;
V_5 -> V_57 . V_275 -> V_365 =
V_43 -> V_275 -> V_365 ;
V_5 -> V_57 . V_275 -> V_371 =
V_43 -> V_275 -> V_371 ;
if ( V_5 -> V_19 & V_372 )
F_88 ( V_5 -> V_182 . V_183 ,
V_373 ) ;
}
return 0 ;
}
static void F_107 ( struct V_4 * V_5 ,
T_2 * V_302 , struct V_303 * V_304 )
{
T_2 V_305 ;
for ( V_305 = 0 ; V_305 < V_304 -> V_37 ; V_305 ++ ) {
if ( V_304 -> V_299 [ V_305 ] == * V_302 ) {
* V_302 = V_304 -> V_298 [ V_305 ] ;
break;
}
}
if ( * V_302 > V_295 )
F_63 ( V_212 L_69 ) ;
}
static int F_108 ( struct V_4 * V_5 ,
struct V_32 * V_374 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_374 )
for ( V_34 = 0 ; V_34 < V_374 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_374 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_301 ) ;
return 0 ;
}
static int F_109 ( struct V_4 * V_5 ,
struct V_32 * V_374 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_374 )
for ( V_34 = 0 ; V_34 < V_374 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_374 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_375 ) ;
return 0 ;
}
static int F_110 ( struct V_4 * V_5 ,
struct V_376 * V_374 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_374 )
for ( V_34 = 0 ; V_34 < V_374 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_374 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_301 ) ;
return 0 ;
}
static int F_111 ( struct V_4 * V_5 ,
struct V_377 * V_374 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_374 )
for ( V_34 = 0 ; V_34 < V_374 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_374 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_301 ) ;
return 0 ;
}
static int F_112 ( struct V_4 * V_5 ,
struct V_378 * V_374 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_374 )
for ( V_34 = 0 ; V_34 < V_374 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_374 -> V_38 [ V_34 ] . V_379 ,
& V_24 -> V_301 ) ;
return 0 ;
}
static int F_113 ( struct V_4 * V_5 ,
struct V_380 * V_374 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_374 )
for ( V_34 = 0 ; V_34 < V_374 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_374 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_301 ) ;
return 0 ;
}
static int F_114 ( struct V_4 * V_5 ,
struct V_381 * V_374 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_374 )
for ( V_34 = 0 ; V_34 < V_374 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_374 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_301 ) ;
return 0 ;
}
static int F_115 ( struct V_4 * V_5 ,
struct V_382 * V_374 )
{
T_2 V_290 , V_332 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_374 ) {
V_290 = V_374 -> V_290 ;
F_107 ( V_5 , & V_290 ,
& V_24 -> V_301 ) ;
V_374 -> V_290 = V_290 ;
V_332 = V_374 -> V_332 ;
F_107 ( V_5 , & V_332 ,
& V_24 -> V_375 ) ;
V_374 -> V_332 = V_332 ;
}
return 0 ;
}
static int F_116 ( struct V_4 * V_5 , struct V_157 * V_374 )
{
T_2 V_34 ;
T_2 V_290 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_374 ) {
for ( V_34 = 0 ; V_34 < V_374 -> V_37 ; V_34 ++ ) {
V_290 = ( T_2 ) ( V_374 -> V_38 [ V_34 ] . V_383 ) ;
F_107 ( V_5 , & V_290 , & V_24 -> V_301 ) ;
V_374 -> V_38 [ V_34 ] . V_383 = ( T_1 ) V_290 ;
}
}
return 0 ;
}
static int F_117 ( struct V_4 * V_5 )
{
int V_46 ;
V_46 = F_108 ( V_5 , V_5 -> V_57 . V_155 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_108 ( V_5 , V_5 -> V_57 . V_68 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_108 ( V_5 , V_5 -> V_57 . V_384 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_109 ( V_5 , V_5 -> V_57 . V_62 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_110 ( V_5 , V_5 -> V_57 . V_385 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_111 ( V_5 , V_5 -> V_57 . V_386 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_113 ( V_5 , V_5 -> V_57 . V_387 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_114 ( V_5 , V_5 -> V_57 . V_388 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_112 ( V_5 , V_5 -> V_57 . V_389 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_115 ( V_5 , & V_5 -> V_57 . V_330 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_115 ( V_5 , & V_5 -> V_57 . V_308 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_116 ( V_5 , V_5 -> V_57 . V_159 ) ;
if ( V_46 )
return - V_120 ;
return 0 ;
}
static int F_118 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_32 * V_390 = V_5 -> V_57 . V_155 ;
struct V_32 * V_391 = V_5 -> V_57 . V_68 ;
struct V_32 * V_392 = V_5 -> V_57 . V_62 ;
F_2 (allowed_sclk_vddc_table != NULL,
L_78 , return -EINVAL) ;
F_2 (allowed_sclk_vddc_table->count >= 1 ,
L_79 , return -EINVAL) ;
F_2 (allowed_mclk_vddc_table != NULL,
L_80 , return -EINVAL) ;
F_2 (allowed_mclk_vddc_table->count >= 1 ,
L_81 , return -EINVAL) ;
V_24 -> V_393 = ( T_1 ) V_390 -> V_38 [ 0 ] . V_40 ;
V_24 -> V_394 = ( T_1 ) V_390 -> V_38 [ V_390 -> V_37 - 1 ] . V_40 ;
V_5 -> V_57 . V_330 . V_293 =
V_390 -> V_38 [ V_390 -> V_37 - 1 ] . V_161 ;
V_5 -> V_57 . V_330 . V_331 =
V_391 -> V_38 [ V_391 -> V_37 - 1 ] . V_161 ;
V_5 -> V_57 . V_330 . V_290 =
V_390 -> V_38 [ V_390 -> V_37 - 1 ] . V_40 ;
if ( V_392 != NULL && V_392 -> V_37 >= 1 ) {
V_24 -> V_395 = ( T_1 ) V_392 -> V_38 [ 0 ] . V_40 ;
V_24 -> V_396 = ( T_1 ) V_392 -> V_38 [ V_392 -> V_37 - 1 ] . V_40 ;
}
if ( V_5 -> V_57 . V_62 != NULL && V_5 -> V_57 . V_62 -> V_37 > 1 )
V_5 -> V_57 . V_330 . V_332 = V_5 -> V_57 . V_62 -> V_38 [ V_5 -> V_57 . V_62 -> V_37 - 1 ] . V_40 ;
return 0 ;
}
static int F_119 ( struct V_4 * V_5 )
{
struct V_23 * V_24 ;
int V_45 ;
V_24 = F_120 ( sizeof( struct V_23 ) , V_397 ) ;
if ( V_24 == NULL )
return - V_398 ;
V_5 -> V_25 = V_24 ;
F_104 ( V_5 ) ;
F_85 ( V_5 ) ;
V_45 = F_90 ( V_5 ) ;
if ( V_45 ) {
F_63 ( L_82 ) ;
return - V_120 ;
}
if ( V_5 -> V_53 == V_54 ) {
F_102 ( V_5 ) ;
F_103 ( V_5 ) ;
} else if ( V_5 -> V_53 == V_56 ) {
F_117 ( V_5 ) ;
F_118 ( V_5 ) ;
}
V_45 = F_121 ( V_5 ) ;
if ( 0 == V_45 ) {
struct V_243 V_244 = { 0 } ;
V_24 -> V_399 = false ;
V_5 -> V_182 . V_400 =
V_401 ;
V_5 -> V_182 . V_402 = 2 ;
V_5 -> V_182 . V_403 = 50 ;
V_244 . V_282 = sizeof( struct V_243 ) ;
V_244 . V_283 = V_404 ;
V_45 = F_89 ( V_5 -> V_6 , & V_244 ) ;
if ( V_45 )
V_24 -> V_139 = V_405 ;
else
V_24 -> V_139 = ( T_2 ) V_244 . V_39 ;
if ( V_24 -> V_139 & V_406 )
V_24 -> V_407 = 20 ;
V_244 . V_282 = sizeof( struct V_243 ) ;
V_244 . V_283 = V_408 ;
V_45 = F_89 ( V_5 -> V_6 , & V_244 ) ;
if ( V_45 )
V_24 -> V_141 = V_409 ;
else
V_24 -> V_141 = ( T_2 ) V_244 . V_39 ;
V_5 -> V_182 . V_410 = 0x20000400 ;
V_5 -> V_182 . V_411 . V_412 = 500 ;
V_5 -> V_182 . V_411 . V_413 = 500 ;
F_105 ( V_5 ) ;
} else {
F_122 ( V_5 ) ;
}
return 0 ;
}
static int F_123 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_414 , V_46 ;
if ( ! V_24 -> V_213 ) {
if ( V_24 -> V_415 . V_416 ) {
V_414 = 0 ;
V_46 = V_24 -> V_415 . V_416 ;
while ( V_46 >>= 1 )
V_414 ++ ;
if ( V_414 )
F_124 ( V_5 -> V_21 ,
V_417 , V_414 ) ;
}
}
if ( ! V_24 -> V_199 ) {
if ( V_24 -> V_415 . V_418 ) {
V_414 = 0 ;
V_46 = V_24 -> V_415 . V_418 ;
while ( V_46 >>= 1 )
V_414 ++ ;
if ( V_414 )
F_124 ( V_5 -> V_21 ,
V_419 ,
( 1 << V_414 ) ) ;
}
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_415 . V_420 ) {
V_414 = 0 ;
V_46 = V_24 -> V_415 . V_420 ;
while ( V_46 >>= 1 )
V_414 ++ ;
if ( V_414 )
F_124 ( V_5 -> V_21 ,
V_421 ,
( 1 << V_414 ) ) ;
}
}
return 0 ;
}
static int F_125 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_5 -> V_53 == V_54 )
F_126 ( V_5 ) ;
if ( ! V_24 -> V_199 ) {
if ( V_24 -> V_415 . V_418 )
F_124 ( V_5 -> V_21 ,
V_419 ,
V_24 -> V_415 . V_418 ) ;
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_415 . V_420 )
F_124 ( V_5 -> V_21 ,
V_421 ,
V_24 -> V_415 . V_420 ) ;
}
return 0 ;
}
static int F_127 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( ! F_73 ( V_5 ) )
return - V_120 ;
if ( ! V_24 -> V_213 ) {
F_14 ( V_5 -> V_21 ,
V_422 ) ;
}
return F_125 ( V_5 ) ;
}
static int F_128 ( struct V_4 * V_5 )
{
struct V_23 * V_24 =
(struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_414 ;
if ( ! V_24 -> V_199 )
if ( V_24 -> V_415 . V_418 ) {
V_414 = F_129 ( V_5 ,
V_24 -> V_415 . V_418 ) ;
F_124 ( V_5 -> V_21 ,
V_419 ,
( 1 << V_414 ) ) ;
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_415 . V_420 ) {
V_414 = F_129 ( V_5 ,
V_24 -> V_415 . V_420 ) ;
F_124 ( V_5 -> V_21 ,
V_421 ,
( 1 << V_414 ) ) ;
}
}
if ( ! V_24 -> V_213 ) {
if ( V_24 -> V_415 . V_416 ) {
V_414 = F_129 ( V_5 ,
V_24 -> V_415 . V_416 ) ;
F_124 ( V_5 -> V_21 ,
V_417 ,
( V_414 ) ) ;
}
}
return 0 ;
}
static int F_130 ( struct V_4 * V_5 ,
enum V_423 V_414 )
{
int V_424 = 0 ;
switch ( V_414 ) {
case V_425 :
V_424 = F_123 ( V_5 ) ;
if ( V_424 )
return V_424 ;
break;
case V_426 :
V_424 = F_128 ( V_5 ) ;
if ( V_424 )
return V_424 ;
break;
case V_427 :
V_424 = F_127 ( V_5 ) ;
if ( V_424 )
return V_424 ;
break;
default:
break;
}
V_5 -> V_428 = V_414 ;
return V_424 ;
}
static int F_131 ( struct V_4 * V_5 )
{
return sizeof( struct V_1 ) ;
}
static int F_132 ( struct V_4 * V_5 ,
struct V_429 * V_430 ,
const struct V_429 * V_431 )
{
struct V_1 * V_432 =
F_1 ( & V_430 -> V_433 ) ;
T_2 V_293 ;
T_2 V_331 ;
struct V_434 V_435 = { 0 } ;
bool V_436 ;
bool V_437 ;
struct V_172 V_173 = { 0 } ;
const struct V_382 * V_438 ;
T_2 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
T_8 V_37 ;
T_8 V_439 = 0 , V_440 = 0 ;
V_24 -> V_441 = ( V_442 ==
V_430 -> V_443 . V_444 ) ;
F_2 ( V_432 -> V_445 == 2 ,
L_83 ,
) ;
V_438 = ( V_446 == V_5 -> V_447 ) ?
& ( V_5 -> V_57 . V_330 ) :
& ( V_5 -> V_57 . V_308 ) ;
if ( V_448 == V_5 -> V_447 ) {
for ( V_34 = 0 ; V_34 < V_432 -> V_445 ; V_34 ++ ) {
if ( V_432 -> V_449 [ V_34 ] . V_450 > V_438 -> V_331 )
V_432 -> V_449 [ V_34 ] . V_450 = V_438 -> V_331 ;
if ( V_432 -> V_449 [ V_34 ] . V_451 > V_438 -> V_293 )
V_432 -> V_449 [ V_34 ] . V_451 = V_438 -> V_293 ;
}
}
V_432 -> V_452 . V_453 = V_5 -> V_454 . V_453 ;
V_432 -> V_452 . V_455 = V_5 -> V_454 . V_455 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_435 . V_412 = V_5 -> V_456 . V_457 ;
V_435 . V_413 = V_5 -> V_456 . V_458 ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_459 ) ) {
V_438 = & ( V_5 -> V_57 . V_330 ) ;
V_439 = ( V_438 -> V_293 * 75 ) / 100 ;
for ( V_37 = V_43 -> V_168 -> V_37 - 1 ;
V_37 >= 0 ; V_37 -- ) {
if ( V_439 >=
V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ) {
V_439 =
V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ;
break;
}
}
if ( V_37 < 0 )
V_439 = V_43 -> V_168 -> V_38 [ 0 ] . V_161 ;
V_440 = V_438 -> V_331 ;
V_435 . V_412 = V_439 ;
V_435 . V_413 = V_440 ;
}
if ( V_435 . V_412 < V_5 -> V_460 . V_293 )
V_435 . V_412 = V_5 -> V_460 . V_293 ;
if ( V_435 . V_413 < V_5 -> V_460 . V_331 )
V_435 . V_413 = V_5 -> V_460 . V_331 ;
V_432 -> V_461 = V_5 -> V_460 . V_461 ;
if ( 0 != V_5 -> V_460 . V_462 ) {
F_2 ( ( V_5 -> V_460 . V_462 <=
V_5 -> V_182 . V_463 . V_412 ) ,
L_84 ,
V_5 -> V_460 . V_462 =
V_5 -> V_182 . V_463 . V_412 ) ;
if ( V_5 -> V_460 . V_462 >= V_5 -> V_460 . V_293 )
V_432 -> V_449 [ 1 ] . V_451 =
V_5 -> V_460 . V_462 ;
}
if ( 0 != V_5 -> V_460 . V_464 ) {
F_2 ( ( V_5 -> V_460 . V_464 <=
V_5 -> V_182 . V_463 . V_413 ) ,
L_85 ,
V_5 -> V_460 . V_464 =
V_5 -> V_182 . V_463 . V_413 ) ;
if ( V_5 -> V_460 . V_464 >= V_5 -> V_460 . V_331 )
V_432 -> V_449 [ 1 ] . V_450 =
V_5 -> V_460 . V_464 ;
}
V_437 = F_52 (
V_5 -> V_182 . V_183 ,
V_465 ) ;
V_436 = ( 1 < V_173 . V_466 ) ||
V_437 ;
V_293 = V_432 -> V_449 [ 0 ] . V_451 ;
V_331 = V_432 -> V_449 [ 0 ] . V_450 ;
if ( V_436 )
V_331 = V_432 -> V_449
[ V_432 -> V_445 - 1 ] . V_450 ;
if ( V_293 < V_435 . V_412 )
V_293 = ( V_435 . V_412 > V_438 -> V_293 ) ?
V_438 -> V_293 : V_435 . V_412 ;
if ( V_331 < V_435 . V_413 )
V_331 = ( V_435 . V_413 > V_438 -> V_331 ) ?
V_438 -> V_331 : V_435 . V_413 ;
V_432 -> V_449 [ 0 ] . V_451 = V_293 ;
V_432 -> V_449 [ 0 ] . V_450 = V_331 ;
V_432 -> V_449 [ 1 ] . V_451 =
( V_432 -> V_449 [ 1 ] . V_451 >=
V_432 -> V_449 [ 0 ] . V_451 ) ?
V_432 -> V_449 [ 1 ] . V_451 :
V_432 -> V_449 [ 0 ] . V_451 ;
if ( V_436 ) {
if ( V_331 < V_432 -> V_449 [ 1 ] . V_450 )
V_331 = V_432 -> V_449 [ 1 ] . V_450 ;
V_432 -> V_449 [ 0 ] . V_450 = V_331 ;
V_432 -> V_449 [ 1 ] . V_450 = V_331 ;
} else {
if ( V_432 -> V_449 [ 1 ] . V_450 <
V_432 -> V_449 [ 0 ] . V_450 )
V_432 -> V_449 [ 1 ] . V_450 =
V_432 -> V_449 [ 0 ] . V_450 ;
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_459 ) ) {
for ( V_34 = 0 ; V_34 < V_432 -> V_445 ; V_34 ++ ) {
V_432 -> V_449 [ V_34 ] . V_451 = V_439 ;
V_432 -> V_449 [ V_34 ] . V_450 = V_440 ;
V_432 -> V_449 [ V_34 ] . V_467 = V_24 -> V_132 . V_278 ;
V_432 -> V_449 [ V_34 ] . V_468 = V_24 -> V_132 . V_278 ;
}
}
return 0 ;
}
static int F_133 ( struct V_4 * V_5 , bool V_469 )
{
struct V_429 * V_470 ;
struct V_1 * V_432 ;
if ( V_5 == NULL )
return - V_120 ;
V_470 = V_5 -> V_430 ;
if ( V_470 == NULL )
return - V_120 ;
V_432 = F_1 ( & V_470 -> V_433 ) ;
if ( V_469 )
return V_432 -> V_449 [ 0 ] . V_450 ;
else
return V_432 -> V_449
[ V_432 -> V_445 - 1 ] . V_450 ;
}
static int F_134 ( struct V_4 * V_5 , bool V_469 )
{
struct V_429 * V_470 ;
struct V_1 * V_432 ;
if ( V_5 == NULL )
return - V_120 ;
V_470 = V_5 -> V_430 ;
if ( V_470 == NULL )
return - V_120 ;
V_432 = F_1 ( & V_470 -> V_433 ) ;
if ( V_469 )
return V_432 -> V_449 [ 0 ] . V_451 ;
else
return V_432 -> V_449
[ V_432 -> V_445 - 1 ] . V_451 ;
}
static int F_135 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_470 = (struct V_1 * ) V_3 ;
T_9 * V_471 ;
T_1 V_282 ;
T_6 V_472 , V_473 ;
int V_305 = F_136 ( V_474 , V_475 ) ;
V_471 = ( T_9 * ) F_137 (
V_5 -> V_6 , V_305 ,
& V_282 , & V_472 , & V_473 ) ;
if ( ! V_471 )
return 0 ;
V_24 -> V_476 . V_477 =
F_138 ( V_471 -> V_478 ) ;
V_24 -> V_476 . V_479 =
F_138 ( V_471 -> V_480 ) ;
V_24 -> V_476 . V_481 =
F_139 ( V_471 -> V_482 ) ;
V_24 -> V_476 . V_483 =
F_139 ( V_471 -> V_484 ) ;
V_24 -> V_476 . V_485 =
F_139 ( V_471 -> V_486 ) ;
V_24 -> V_476 . V_487 =
F_7 ( V_5 ) ;
V_24 -> V_476 . V_488 =
( T_1 ) F_10 ( V_5 ) ;
V_470 -> V_449 [ 0 ] . V_450 = V_24 -> V_476 . V_479 ;
V_470 -> V_449 [ 0 ] . V_451 = V_24 -> V_476 . V_477 ;
V_470 -> V_449 [ 0 ] . V_467 = V_24 -> V_476 . V_487 ;
V_470 -> V_449 [ 0 ] . V_468 = V_24 -> V_476 . V_488 ;
return 0 ;
}
static int F_140 ( struct V_4 * V_5 )
{
int V_45 ;
unsigned long V_424 = 0 ;
if ( V_5 -> V_53 == V_56 ) {
V_45 = F_141 ( V_5 , & V_424 ) ;
return V_45 ? 0 : V_424 ;
} else if ( V_5 -> V_53 == V_54 ) {
V_45 = F_142 ( V_5 ) ;
return V_45 ;
}
return 0 ;
}
static int F_143 ( struct V_4 * V_5 ,
void * V_489 , struct V_429 * V_490 ,
void * V_491 , T_2 V_492 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_1 =
(struct V_1 * ) ( & ( V_490 -> V_433 ) ) ;
struct V_493 * V_494 ;
T_10 * V_495 = ( T_10 * ) V_489 ;
T_11 * V_496 =
( T_11 * ) V_491 ;
T_12 * V_497 =
( T_12 * )
( ( ( unsigned long ) V_496 ) +
F_139 ( V_496 -> V_498 ) ) ;
T_13 * V_499 =
( T_13 * )
( ( ( unsigned long ) V_496 ) +
F_139 ( V_496 -> V_500 ) ) ;
V_490 -> V_443 . V_444 =
( F_139 ( V_495 -> V_501 ) &
V_502 ) >>
V_503 ;
V_490 -> V_443 . V_504 = V_492 ;
V_490 -> V_443 . V_505 = false ;
V_490 -> V_443 . V_506 = false ;
V_490 -> V_507 . V_508 =
( 0 != ( F_138 ( V_495 -> V_509 ) &
V_510 ) ) ;
V_490 -> V_511 . V_512 = 0 ;
V_490 -> V_513 . V_514 = false ;
V_490 -> V_513 . V_515 = false ;
V_490 -> V_513 . V_516 =
( 0 != ( F_138 ( V_495 -> V_509 ) &
V_517 ) ) ;
V_490 -> V_507 . V_518 = 0 ;
V_490 -> V_519 . V_520 = 0 ;
V_490 -> V_519 . V_521 = 0 ;
V_490 -> V_522 . V_280 = 0 ;
V_490 -> V_522 . V_278 = 0 ;
V_494 = & ( V_1 -> V_449
[ V_1 -> V_445 ++ ] ) ;
F_2 (
(smu7_power_state->performance_level_count < smum_get_mac_definition(hwmgr->smumgr, SMU_MAX_LEVELS_GRAPHICS)),
L_86 ,
return -EINVAL) ;
F_2 (
(smu7_power_state->performance_level_count <=
hwmgr->platform_descriptor.hardwareActivityPerformanceLevels),
L_87 ,
return -EINVAL) ;
V_494 -> V_450 = V_499 -> V_38
[ V_495 -> V_523 ] . V_524 ;
if ( V_497 -> V_525 == 0 )
V_494 -> V_451 = ( ( V_526 * ) V_497 ) -> V_38
[ V_495 -> V_527 ] . V_528 ;
else if ( V_497 -> V_525 == 1 )
V_494 -> V_451 = ( ( V_529 * ) V_497 ) -> V_38
[ V_495 -> V_527 ] . V_528 ;
V_494 -> V_467 = F_41 ( V_24 -> V_139 ,
V_495 -> V_530 ) ;
V_494 -> V_468 = F_42 ( V_24 -> V_141 ,
V_495 -> V_531 ) ;
V_494 = & ( V_1 -> V_449
[ V_1 -> V_445 ++ ] ) ;
V_494 -> V_450 = V_499 -> V_38
[ V_495 -> V_532 ] . V_524 ;
if ( V_497 -> V_525 == 0 )
V_494 -> V_451 = ( ( V_526 * ) V_497 ) -> V_38
[ V_495 -> V_533 ] . V_528 ;
else if ( V_497 -> V_525 == 1 )
V_494 -> V_451 = ( ( V_529 * ) V_497 ) -> V_38
[ V_495 -> V_533 ] . V_528 ;
V_494 -> V_467 = F_41 ( V_24 -> V_139 ,
V_495 -> V_534 ) ;
V_494 -> V_468 = F_42 ( V_24 -> V_141 ,
V_495 -> V_531 ) ;
return 0 ;
}
static int F_144 ( struct V_4 * V_5 ,
unsigned long V_535 , struct V_429 * V_489 )
{
int V_45 ;
struct V_1 * V_470 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_167 =
V_43 -> V_55 ;
V_489 -> V_433 . V_536 = V_537 ;
V_470 = (struct V_1 * ) ( & V_489 -> V_433 ) ;
V_45 = F_145 ( V_5 , V_535 , V_489 ,
F_143 ) ;
if ( V_167 != NULL && V_167 -> V_37 == 1 ) {
if ( V_167 -> V_38 [ 0 ] . V_161 !=
V_24 -> V_476 . V_479 )
F_63 ( V_212 L_88
L_89 ) ;
if ( V_167 -> V_38 [ 0 ] . V_332 !=
V_24 -> V_476 . V_485 )
F_63 ( V_212 L_90
L_91 ) ;
}
if ( ! V_489 -> V_507 . V_508 )
V_470 -> V_538 = true ;
if ( V_489 -> V_443 . V_504 & V_539 )
V_24 -> V_540 = V_470 -> V_449 [ 0 ] . V_467 ;
V_470 -> V_541 . V_542 = V_489 -> V_519 . V_520 ;
V_470 -> V_541 . V_543 = V_489 -> V_519 . V_521 ;
if ( ! V_45 ) {
T_2 V_34 ;
switch ( V_489 -> V_443 . V_444 ) {
case V_544 :
V_24 -> V_129 = true ;
for ( V_34 = 0 ; V_34 < V_470 -> V_445 ; V_34 ++ ) {
if ( V_24 -> V_132 . V_278 <
V_470 -> V_449 [ V_34 ] . V_467 )
V_24 -> V_132 . V_278 =
V_470 -> V_449 [ V_34 ] . V_467 ;
if ( V_24 -> V_132 . V_280 >
V_470 -> V_449 [ V_34 ] . V_467 )
V_24 -> V_132 . V_280 =
V_470 -> V_449 [ V_34 ] . V_467 ;
if ( V_24 -> V_134 . V_278 <
V_470 -> V_449 [ V_34 ] . V_468 )
V_24 -> V_134 . V_278 =
V_470 -> V_449 [ V_34 ] . V_468 ;
if ( V_24 -> V_134 . V_280 >
V_470 -> V_449 [ V_34 ] . V_468 )
V_24 -> V_134 . V_280 =
V_470 -> V_449 [ V_34 ] . V_468 ;
}
break;
case V_442 :
V_24 -> V_130 = true ;
for ( V_34 = 0 ; V_34 < V_470 -> V_445 ; V_34 ++ ) {
if ( V_24 -> V_131 . V_278 <
V_470 -> V_449 [ V_34 ] . V_467 )
V_24 -> V_131 . V_278 =
V_470 -> V_449 [ V_34 ] . V_467 ;
if ( V_24 -> V_131 . V_280 >
V_470 -> V_449 [ V_34 ] . V_467 )
V_24 -> V_131 . V_280 =
V_470 -> V_449 [ V_34 ] . V_467 ;
if ( V_24 -> V_133 . V_278 <
V_470 -> V_449 [ V_34 ] . V_468 )
V_24 -> V_133 . V_278 =
V_470 -> V_449 [ V_34 ] . V_468 ;
if ( V_24 -> V_133 . V_280 >
V_470 -> V_449 [ V_34 ] . V_468 )
V_24 -> V_133 . V_280 =
V_470 -> V_449 [ V_34 ] . V_468 ;
}
break;
default:
break;
}
}
return 0 ;
}
static int F_146 ( struct V_4 * V_5 ,
struct V_2 * V_490 ,
unsigned int V_305 , const void * V_545 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_470 = F_1 ( V_490 ) ;
const T_14 * V_546 = V_545 ;
struct V_493 * V_494 ;
T_2 V_451 , V_450 ;
T_1 V_547 ;
V_451 = V_546 -> V_548 << 16 | V_546 -> V_549 ;
V_450 = V_546 -> V_550 << 16 | V_546 -> V_551 ;
if ( ! ( V_24 -> V_552 & V_553 ) && V_450 > V_24 -> V_554 )
V_24 -> V_554 = V_450 ;
F_2 (
(ps->performance_level_count < smum_get_mac_definition(hwmgr->smumgr, SMU_MAX_LEVELS_GRAPHICS)),
L_86 ,
return -EINVAL) ;
F_2 (
(ps->performance_level_count <
hwmgr->platform_descriptor.hardwareActivityPerformanceLevels),
L_92 ,
return 0 ) ;
V_494 = & ( V_470 -> V_449
[ V_470 -> V_445 ++ ] ) ;
V_494 -> V_450 = V_450 ;
V_494 -> V_451 = V_451 ;
V_547 = V_546 -> V_555 ;
V_494 -> V_467 = F_41 ( V_24 -> V_139 , V_547 ) ;
V_494 -> V_468 = F_42 ( V_24 -> V_141 , V_546 -> V_556 ) ;
return 0 ;
}
static int F_147 ( struct V_4 * V_5 ,
unsigned long V_535 , struct V_429 * V_489 )
{
int V_45 ;
struct V_1 * V_470 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_32 * V_167 =
V_5 -> V_57 . V_62 ;
memset ( & V_489 -> V_433 , 0x00 , sizeof( struct V_2 ) ) ;
V_489 -> V_433 . V_536 = V_537 ;
V_470 = (struct V_1 * ) ( & V_489 -> V_433 ) ;
V_45 = F_148 ( V_5 , V_535 , V_489 ,
F_146 ) ;
if ( V_167 != NULL && V_167 -> V_37 == 1 ) {
if ( V_167 -> V_38 [ 0 ] . V_161 !=
V_24 -> V_476 . V_479 )
F_63 ( V_212 L_88
L_89 ) ;
if ( V_167 -> V_38 [ 0 ] . V_40 !=
V_24 -> V_476 . V_485 )
F_63 ( V_212 L_90
L_91 ) ;
}
if ( ! V_489 -> V_507 . V_508 )
V_470 -> V_538 = true ;
if ( V_489 -> V_443 . V_504 & V_539 )
V_24 -> V_540 = V_470 -> V_449 [ 0 ] . V_467 ;
V_470 -> V_541 . V_542 = V_489 -> V_519 . V_520 ;
V_470 -> V_541 . V_543 = V_489 -> V_519 . V_521 ;
if ( ! V_45 ) {
T_2 V_34 ;
switch ( V_489 -> V_443 . V_444 ) {
case V_544 :
V_24 -> V_129 = true ;
for ( V_34 = 0 ; V_34 < V_470 -> V_445 ; V_34 ++ ) {
if ( V_24 -> V_132 . V_278 <
V_470 -> V_449 [ V_34 ] . V_467 )
V_24 -> V_132 . V_278 =
V_470 -> V_449 [ V_34 ] . V_467 ;
if ( V_24 -> V_132 . V_280 >
V_470 -> V_449 [ V_34 ] . V_467 )
V_24 -> V_132 . V_280 =
V_470 -> V_449 [ V_34 ] . V_467 ;
if ( V_24 -> V_134 . V_278 <
V_470 -> V_449 [ V_34 ] . V_468 )
V_24 -> V_134 . V_278 =
V_470 -> V_449 [ V_34 ] . V_468 ;
if ( V_24 -> V_134 . V_280 >
V_470 -> V_449 [ V_34 ] . V_468 )
V_24 -> V_134 . V_280 =
V_470 -> V_449 [ V_34 ] . V_468 ;
}
break;
case V_442 :
V_24 -> V_130 = true ;
for ( V_34 = 0 ; V_34 < V_470 -> V_445 ; V_34 ++ ) {
if ( V_24 -> V_131 . V_278 <
V_470 -> V_449 [ V_34 ] . V_467 )
V_24 -> V_131 . V_278 =
V_470 -> V_449 [ V_34 ] . V_467 ;
if ( V_24 -> V_131 . V_280 >
V_470 -> V_449 [ V_34 ] . V_467 )
V_24 -> V_131 . V_280 =
V_470 -> V_449 [ V_34 ] . V_467 ;
if ( V_24 -> V_133 . V_278 <
V_470 -> V_449 [ V_34 ] . V_468 )
V_24 -> V_133 . V_278 =
V_470 -> V_449 [ V_34 ] . V_468 ;
if ( V_24 -> V_133 . V_280 >
V_470 -> V_449 [ V_34 ] . V_468 )
V_24 -> V_133 . V_280 =
V_470 -> V_449 [ V_34 ] . V_468 ;
}
break;
default:
break;
}
}
return 0 ;
}
static int F_149 ( struct V_4 * V_5 ,
unsigned long V_535 , struct V_429 * V_489 )
{
if ( V_5 -> V_53 == V_56 )
return F_147 ( V_5 , V_535 , V_489 ) ;
else if ( V_5 -> V_53 == V_54 )
return F_144 ( V_5 , V_535 , V_489 ) ;
return 0 ;
}
static int F_150 ( struct V_4 * V_5 , int V_557 , T_8 * V_39 )
{
T_2 V_293 , V_331 , V_558 ;
T_2 V_559 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
switch ( V_557 ) {
case V_560 :
F_14 ( V_5 -> V_21 , V_561 ) ;
V_293 = F_6 ( V_5 -> V_6 , V_562 ) ;
* V_39 = V_293 ;
return 0 ;
case V_563 :
F_14 ( V_5 -> V_21 , V_564 ) ;
V_331 = F_6 ( V_5 -> V_6 , V_562 ) ;
* V_39 = V_331 ;
return 0 ;
case V_565 :
V_559 = V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_566 ) ;
V_558 = F_8 ( V_5 -> V_6 , V_28 , V_559 ) ;
V_558 += 0x80 ;
V_558 >>= 8 ;
* V_39 = V_558 > 100 ? 100 : V_558 ;
return 0 ;
case V_567 :
* V_39 = F_151 ( V_5 ) ;
return 0 ;
case V_568 :
* V_39 = V_24 -> V_569 ? 0 : 1 ;
return 0 ;
case V_570 :
* V_39 = V_24 -> V_571 ? 0 : 1 ;
return 0 ;
default:
return - V_120 ;
}
}
static int F_152 ( struct V_4 * V_5 , const void * V_572 )
{
const struct V_573 * V_574 =
( const struct V_573 * ) V_572 ;
const struct V_1 * V_432 =
F_3 ( V_574 -> V_575 ) ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_576 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
T_2 V_293 = V_432 -> V_449
[ V_432 -> V_445 - 1 ] . V_451 ;
struct V_576 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
T_2 V_331 = V_432 -> V_449
[ V_432 -> V_445 - 1 ] . V_450 ;
struct V_434 V_577 = { 0 } ;
T_2 V_34 ;
struct V_172 V_173 = { 0 } ;
V_24 -> V_578 = 0 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ ) {
if ( V_293 == V_147 -> V_160 [ V_34 ] . V_39 )
break;
}
if ( V_34 >= V_147 -> V_37 )
V_24 -> V_578 |= V_579 ;
else {
if ( V_24 -> V_580 . V_581 != V_577 . V_582 &&
( V_577 . V_582 >= V_583 ||
V_24 -> V_580 . V_581 >= V_583 ) )
V_24 -> V_578 |= V_584 ;
}
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ ) {
if ( V_331 == V_149 -> V_160 [ V_34 ] . V_39 )
break;
}
if ( V_34 >= V_149 -> V_37 )
V_24 -> V_578 |= V_585 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
if ( V_24 -> V_580 . V_586 != V_173 . V_466 )
V_24 -> V_578 |= V_587 ;
return 0 ;
}
static T_1 F_153 ( struct V_4 * V_5 ,
const struct V_1 * V_432 )
{
T_2 V_34 ;
T_2 V_293 , V_588 = 0 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_170 * V_136 = & V_24 -> V_136 ;
for ( V_34 = 0 ; V_34 < V_432 -> V_445 ; V_34 ++ ) {
V_293 = V_432 -> V_449 [ V_34 ] . V_451 ;
if ( V_588 < V_293 )
V_588 = V_293 ;
}
for ( V_34 = 0 ; V_34 < V_136 -> V_147 . V_37 ; V_34 ++ ) {
if ( V_136 -> V_147 . V_160 [ V_34 ] . V_39 == V_588 )
return ( T_1 ) ( ( V_34 >= V_136 -> V_137 . V_37 ) ?
V_136 -> V_137 . V_160
[ V_136 -> V_137 . V_37 - 1 ] . V_39 :
V_136 -> V_137 . V_160 [ V_34 ] . V_39 ) ;
}
return 0 ;
}
static int F_154 (
struct V_4 * V_5 , const void * V_572 )
{
const struct V_573 * V_574 =
( const struct V_573 * ) V_572 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_589 =
F_3 ( V_574 -> V_575 ) ;
const struct V_1 * V_590 =
F_3 ( V_574 -> V_591 ) ;
T_1 V_592 = F_153 ( V_5 , V_589 ) ;
T_1 V_593 ;
if ( V_24 -> V_265 == V_266 )
V_593 = F_153 ( V_5 , V_590 ) ;
else
V_593 = V_24 -> V_265 ;
V_24 -> V_265 = V_266 ;
V_24 -> V_594 = false ;
if ( V_592 > V_593 ) {
switch ( V_592 ) {
case V_281 :
if ( 0 == F_155 ( V_5 -> V_6 , V_595 , false ) )
break;
V_24 -> V_265 = V_596 ;
if ( V_593 == V_596 )
break;
case V_596 :
if ( 0 == F_155 ( V_5 -> V_6 , V_597 , false ) )
break;
default:
V_24 -> V_265 = F_7 ( V_5 ) ;
break;
}
} else {
if ( V_592 < V_593 )
V_24 -> V_594 = true ;
}
return 0 ;
}
static int F_156 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( 0 == V_24 -> V_578 )
return 0 ;
if ( ( 0 == V_24 -> V_199 ) &&
( V_24 -> V_578 &
( V_579 + V_584 ) ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_93 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_FreezeLevel),
L_94 ,
return -EINVAL) ;
}
if ( ( 0 == V_24 -> V_200 ) &&
( V_24 -> V_578 &
V_585 ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_95 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_MCLKDPM_FreezeLevel),
L_96 ,
return -EINVAL) ;
}
return 0 ;
}
static int F_157 (
struct V_4 * V_5 , const void * V_572 )
{
int V_45 = 0 ;
const struct V_573 * V_574 =
( const struct V_573 * ) V_572 ;
const struct V_1 * V_432 =
F_3 ( V_574 -> V_575 ) ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_293 = V_432 -> V_449
[ V_432 -> V_445 - 1 ] . V_451 ;
T_2 V_331 = V_432 -> V_449
[ V_432 -> V_445 - 1 ] . V_450 ;
struct V_170 * V_136 = & V_24 -> V_136 ;
struct V_170 * V_169 = & V_24 -> V_169 ;
T_2 V_598 , V_599 ;
T_2 V_34 ;
if ( 0 == V_24 -> V_578 )
return 0 ;
if ( V_24 -> V_578 & V_579 ) {
V_136 -> V_147 . V_160
[ V_136 -> V_147 . V_37 - 1 ] . V_39 = V_293 ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_600 ) ||
F_52 ( V_5 -> V_182 . V_183 , V_601 ) ) {
F_2 (
(golden_dpm_table->sclk_table.dpm_levels
[golden_dpm_table->sclk_table.count - 1].value != 0),
L_97 ,
return -EINVAL) ;
V_598 = V_136 -> V_147 . V_37 < 2 ? 0 : V_136 -> V_147 . V_37 - 2 ;
for ( V_34 = V_598 ; V_34 > 1 ; V_34 -- ) {
if ( V_293 > V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ) {
V_599 =
( ( V_293
- V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39
) * 100 )
/ V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ;
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 +
( V_169 -> V_147 . V_160 [ V_34 ] . V_39 *
V_599 ) / 100 ;
} else if ( V_169 -> V_147 . V_160 [ V_136 -> V_147 . V_37 - 1 ] . V_39 > V_293 ) {
V_599 =
( ( V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39
- V_293 ) * 100 )
/ V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ;
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 -
( V_169 -> V_147 . V_160 [ V_34 ] . V_39 *
V_599 ) / 100 ;
} else
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 ;
}
}
}
if ( V_24 -> V_578 & V_585 ) {
V_136 -> V_149 . V_160
[ V_136 -> V_149 . V_37 - 1 ] . V_39 = V_331 ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_600 ) ||
F_52 ( V_5 -> V_182 . V_183 , V_601 ) ) {
F_2 (
(golden_dpm_table->mclk_table.dpm_levels
[golden_dpm_table->mclk_table.count-1].value != 0),
L_97 ,
return -EINVAL) ;
V_598 = V_136 -> V_149 . V_37 < 2 ? 0 : V_136 -> V_149 . V_37 - 2 ;
for ( V_34 = V_598 ; V_34 > 1 ; V_34 -- ) {
if ( V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 < V_331 ) {
V_599 = ( ( V_331 -
V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ) * 100 )
/ V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 +
( V_169 -> V_149 . V_160 [ V_34 ] . V_39 *
V_599 ) / 100 ;
} else if ( V_169 -> V_149 . V_160 [ V_136 -> V_149 . V_37 - 1 ] . V_39 > V_331 ) {
V_599 = (
( V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 - V_331 )
* 100 )
/ V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 -
( V_169 -> V_149 . V_160 [ V_34 ] . V_39 *
V_599 ) / 100 ;
} else
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 ;
}
}
}
if ( V_24 -> V_578 &
( V_579 + V_584 ) ) {
V_45 = F_158 ( V_5 ) ;
F_2 ((0 == result),
L_98 ,
return result) ;
}
if ( V_24 -> V_578 &
( V_585 + V_587 ) ) {
V_45 = F_159 ( V_5 ) ;
F_2 ((0 == result),
L_99 ,
return result) ;
}
return V_45 ;
}
static int F_160 ( struct V_4 * V_5 ,
struct V_576 * V_136 ,
T_2 V_602 , T_2 V_603 )
{
T_2 V_34 ;
for ( V_34 = 0 ; V_34 < V_136 -> V_37 ; V_34 ++ ) {
if ( ( V_136 -> V_160 [ V_34 ] . V_39 < V_602 )
|| ( V_136 -> V_160 [ V_34 ] . V_39 > V_603 ) )
V_136 -> V_160 [ V_34 ] . V_162 = false ;
else
V_136 -> V_160 [ V_34 ] . V_162 = true ;
}
return 0 ;
}
static int F_161 ( struct V_4 * V_5 ,
const struct V_1 * V_432 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_604 ;
F_2 ((smu7_ps->performance_level_count >= 1),
L_100 ,
return -EINVAL) ;
V_604 = ( 1 == V_432 -> V_445 ) ? 0 : 1 ;
F_160 ( V_5 ,
& ( V_24 -> V_136 . V_147 ) ,
V_432 -> V_449 [ 0 ] . V_451 ,
V_432 -> V_449 [ V_604 ] . V_451 ) ;
F_160 ( V_5 ,
& ( V_24 -> V_136 . V_149 ) ,
V_432 -> V_449 [ 0 ] . V_450 ,
V_432 -> V_449 [ V_604 ] . V_450 ) ;
return 0 ;
}
static int F_162 (
struct V_4 * V_5 , const void * V_572 )
{
int V_45 ;
const struct V_573 * V_574 =
( const struct V_573 * ) V_572 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_432 =
F_3 ( V_574 -> V_575 ) ;
V_45 = F_161 ( V_5 , V_432 ) ;
if ( V_45 )
return V_45 ;
V_24 -> V_415 . V_418 =
F_163 ( & V_24 -> V_136 . V_147 ) ;
V_24 -> V_415 . V_420 =
F_163 ( & V_24 -> V_136 . V_149 ) ;
V_24 -> V_415 . V_416 =
F_163 ( & V_24 -> V_136 . V_137 ) ;
return 0 ;
}
static int F_164 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( 0 == V_24 -> V_578 )
return 0 ;
if ( ( 0 == V_24 -> V_199 ) &&
( V_24 -> V_578 &
( V_579 + V_584 ) ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_101 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_UnfreezeLevel),
L_102 ,
return -EINVAL) ;
}
if ( ( 0 == V_24 -> V_200 ) &&
( V_24 -> V_578 & V_585 ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_103 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_UnfreezeLevel),
L_104 ,
return -EINVAL) ;
}
V_24 -> V_578 = 0 ;
return 0 ;
}
static int F_165 (
struct V_4 * V_5 , const void * V_572 )
{
const struct V_573 * V_574 =
( const struct V_573 * ) V_572 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_432 =
F_3 ( V_574 -> V_575 ) ;
T_1 V_592 = F_153 ( V_5 , V_432 ) ;
T_6 V_605 ;
if ( V_24 -> V_594 ) {
if ( V_592 == V_281 )
V_605 = V_595 ;
else if ( V_592 == V_596 )
V_605 = V_597 ;
else
V_605 = V_606 ;
if ( V_605 == V_606 &&
F_7 ( V_5 ) > 0 )
return 0 ;
if ( F_155 ( V_5 -> V_6 , V_605 , false ) ) {
if ( V_596 == V_592 )
F_63 ( L_105 ) ;
else
F_63 ( L_106 ) ;
}
}
return 0 ;
}
static int F_166 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_5 -> V_19 & V_607 )
F_124 ( V_5 -> V_21 ,
( V_237 ) V_608 , V_24 -> V_609 ) ;
return ( F_14 ( V_5 -> V_21 , ( V_237 ) V_610 ) == 0 ) ? 0 : - V_120 ;
}
static int F_167 ( struct V_4 * V_5 , const void * V_572 )
{
int V_234 , V_45 = 0 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_234 = F_152 ( V_5 , V_572 ) ;
F_2 ( ( 0 == V_234 ) ,
L_107 ,
V_45 = V_234 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_611 ) ) {
V_234 =
F_154 ( V_5 , V_572 ) ;
F_2 ( ( 0 == V_234 ) ,
L_108 ,
V_45 = V_234 ) ;
}
V_234 = F_156 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_109 , V_45 = V_234 ) ;
V_234 = F_157 ( V_5 , V_572 ) ;
F_2 ( ( 0 == V_234 ) ,
L_110 ,
V_45 = V_234 ) ;
V_234 = F_162 ( V_5 , V_572 ) ;
F_2 ( ( 0 == V_234 ) ,
L_111 ,
V_45 = V_234 ) ;
V_234 = F_168 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_112 ,
V_45 = V_234 ) ;
V_234 = F_166 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_113 ,
V_45 = V_234 ) ;
V_234 = F_164 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_114 ,
V_45 = V_234 ) ;
V_234 = F_125 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_115 ,
V_45 = V_234 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_611 ) ) {
V_234 =
F_165 ( V_5 , V_572 ) ;
F_2 ( ( 0 == V_234 ) ,
L_116 ,
V_45 = V_234 ) ;
}
V_24 -> V_612 = false ;
return V_45 ;
}
static int F_169 ( struct V_4 * V_5 , T_1 V_613 )
{
V_5 -> V_353 .
V_354 . V_367 = V_613 ;
if ( F_170 ( V_5 ) )
return 0 ;
return F_124 ( V_5 -> V_21 ,
V_614 , V_613 ) ;
}
static int
F_171 ( struct V_4 * V_5 , bool V_615 )
{
V_237 V_616 = V_615 ? ( V_237 ) V_610 : ( V_237 ) V_238 ;
return ( F_14 ( V_5 -> V_21 , V_616 ) == 0 ) ? 0 : - 1 ;
}
static int
F_172 ( struct V_4 * V_5 )
{
T_2 V_617 = 0 ;
struct V_172 V_173 = { 0 } ;
V_173 . V_175 = NULL ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_617 = V_173 . V_466 ;
if ( V_617 > 1 && V_5 -> V_456 . V_618 != true )
F_171 ( V_5 , false ) ;
return 0 ;
}
static int F_173 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_617 = 0 ;
T_2 V_79 = F_8 ( V_5 -> V_6 , V_28 , V_80 ) ;
T_2 V_619 ;
T_2 V_620 ;
T_2 V_621 ;
T_2 V_179 ;
T_2 V_622 = 0 ;
struct V_172 V_173 = { 0 } ;
struct V_174 V_175 ;
V_173 . V_175 = & V_175 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_617 = V_173 . V_466 ;
V_79 = F_28 ( V_79 , V_81 , V_82 , ( V_617 > 0 ) ? V_623 : V_83 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_80 , V_79 ) ;
V_179 = V_175 . V_179 ;
V_622 = V_175 . V_622 ;
if ( 0 == V_622 )
V_622 = 60 ;
V_621 = 1000000 / V_622 ;
V_620 = V_621 - 200 - V_175 . V_624 ;
V_24 -> V_609 = V_621 * 2 / 100 ;
V_619 = V_620 * ( V_179 / 100 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_625 , V_619 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_626 ) , 0x64 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_627 ) ,
( V_621 - V_620 ) ) ;
return 0 ;
}
static int F_174 ( struct V_4 * V_5 )
{
return F_173 ( V_5 ) ;
}
static int F_175 ( struct V_4 * V_5 , T_1 V_628 )
{
V_5 -> V_353 .
V_354 . V_368 = V_628 ;
if ( F_170 ( V_5 ) )
return 0 ;
return F_124 ( V_5 -> V_21 ,
V_629 , V_628 ) ;
}
static int F_176 ( struct V_4 * V_5 ,
const void * V_630 )
{
return 0 ;
}
static bool
F_177 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
bool V_631 = false ;
struct V_172 V_173 = { 0 , 0 , NULL } ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
if ( V_24 -> V_580 . V_586 != V_173 . V_466 )
V_631 = true ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_190 ) ) {
if ( V_24 -> V_580 . V_581 != V_5 -> V_456 . V_632 &&
( V_24 -> V_580 . V_581 >= V_583 ||
V_5 -> V_456 . V_632 >= V_583 ) )
V_631 = true ;
}
return V_631 ;
}
static inline bool F_178 ( const struct V_493 * V_633 ,
const struct V_493 * V_634 )
{
return ( ( V_633 -> V_450 == V_634 -> V_450 ) &&
( V_633 -> V_451 == V_634 -> V_451 ) &&
( V_633 -> V_467 == V_634 -> V_467 ) &&
( V_633 -> V_468 == V_634 -> V_468 ) ) ;
}
static int F_179 ( struct V_4 * V_5 ,
const struct V_2 * V_635 ,
const struct V_2 * V_636 , bool * V_637 )
{
const struct V_1 * V_638 ;
const struct V_1 * V_639 ;
int V_34 ;
if ( V_635 == NULL || V_636 == NULL || V_637 == NULL )
return - V_120 ;
V_638 = F_3 ( V_635 ) ;
V_639 = F_3 ( V_636 ) ;
if ( V_638 -> V_445 != V_639 -> V_445 ) {
* V_637 = false ;
return 0 ;
}
for ( V_34 = 0 ; V_34 < V_638 -> V_445 ; V_34 ++ ) {
if ( ! F_178 ( & ( V_638 -> V_449 [ V_34 ] ) , & ( V_639 -> V_449 [ V_34 ] ) ) ) {
* V_637 = false ;
return 0 ;
}
}
* V_637 = ( ( V_638 -> V_541 . V_542 == V_639 -> V_541 . V_542 ) && ( V_638 -> V_541 . V_543 == V_639 -> V_541 . V_543 ) ) ;
* V_637 &= ( ( V_638 -> V_452 . V_453 == V_639 -> V_452 . V_453 ) && ( V_638 -> V_452 . V_455 == V_639 -> V_452 . V_455 ) ) ;
* V_637 &= ( V_638 -> V_461 == V_639 -> V_461 ) ;
return 0 ;
}
static int F_180 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_640 ;
T_2 V_46 ;
F_4 ( V_5 ) ;
V_640 = V_5 -> V_8 . V_9 & 0xf ;
V_24 -> V_641 = false ;
F_5 ( V_5 -> V_6 , V_7 ,
V_642 ) ;
V_46 = F_6 ( V_5 -> V_6 , V_10 ) ;
if ( V_46 & ( 1 << 23 ) ) {
V_24 -> V_643 = V_644 ;
V_24 -> V_645 = V_646 ;
} else {
V_24 -> V_643 = 330 ;
V_24 -> V_645 = 330 ;
}
return 0 ;
}
static int F_181 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_647 . V_648 =
F_8 ( V_5 -> V_6 , V_28 , V_649 ) ;
V_24 -> V_647 . V_650 =
F_8 ( V_5 -> V_6 , V_28 , V_651 ) ;
V_24 -> V_647 . V_652 =
F_8 ( V_5 -> V_6 , V_28 , V_653 ) ;
V_24 -> V_647 . V_654 =
F_8 ( V_5 -> V_6 , V_28 , V_655 ) ;
V_24 -> V_647 . V_656 =
F_8 ( V_5 -> V_6 , V_28 , V_657 ) ;
V_24 -> V_647 . V_658 =
F_8 ( V_5 -> V_6 , V_28 , V_659 ) ;
V_24 -> V_647 . V_660 =
F_6 ( V_5 -> V_6 , V_661 ) ;
V_24 -> V_647 . V_662 =
F_6 ( V_5 -> V_6 , V_663 ) ;
V_24 -> V_647 . V_664 =
F_6 ( V_5 -> V_6 , V_665 ) ;
V_24 -> V_647 . V_666 =
F_6 ( V_5 -> V_6 , V_667 ) ;
V_24 -> V_647 . V_668 =
F_6 ( V_5 -> V_6 , V_669 ) ;
V_24 -> V_647 . V_670 =
F_6 ( V_5 -> V_6 , V_671 ) ;
V_24 -> V_647 . V_672 =
F_6 ( V_5 -> V_6 , V_673 ) ;
V_24 -> V_647 . V_674 =
F_6 ( V_5 -> V_6 , V_675 ) ;
V_24 -> V_647 . V_676 =
F_6 ( V_5 -> V_6 , V_677 ) ;
return 0 ;
}
static int F_182 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_678 ;
V_678 = F_6 ( V_5 -> V_6 , V_679 ) ;
V_24 -> V_680 = ( V_681 ==
( ( V_678 & V_682 ) >>
V_683 ) ) ;
return 0 ;
}
static int F_183 ( struct V_4 * V_5 )
{
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_684 , 1 ) ;
return 0 ;
}
static int F_184 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_569 = false ;
V_24 -> V_571 = false ;
V_24 -> V_685 = false ;
return 0 ;
}
static int F_185 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_686 = 0 ;
return 0 ;
}
static int F_186 ( struct V_4 * V_5 )
{
int V_234 , V_45 = 0 ;
F_180 ( V_5 ) ;
V_234 = F_181 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_117 , V_45 = V_234 ) ;
V_234 = F_182 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_118 , V_45 = V_234 ) ;
V_234 = F_183 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_119 , V_45 = V_234 ) ;
V_234 = F_184 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_120 , V_45 = V_234 ) ;
V_234 = F_4 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_121 , V_45 = V_234 ) ;
V_234 = F_185 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_122 , V_45 = V_234 ) ;
return V_45 ;
}
static int F_187 ( struct V_4 * V_5 ,
enum V_687 type , T_2 V_688 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_5 -> V_428 != V_689 )
return - V_120 ;
switch ( type ) {
case V_690 :
if ( ! V_24 -> V_199 )
F_124 ( V_5 -> V_21 ,
V_419 ,
V_24 -> V_415 . V_418 & V_688 ) ;
break;
case V_691 :
if ( ! V_24 -> V_200 )
F_124 ( V_5 -> V_21 ,
V_421 ,
V_24 -> V_415 . V_420 & V_688 ) ;
break;
case V_692 :
{
T_2 V_46 = V_688 & V_24 -> V_415 . V_416 ;
T_2 V_414 = 0 ;
while ( V_46 >>= 1 )
V_414 ++ ;
if ( ! V_24 -> V_213 )
F_124 ( V_5 -> V_21 ,
V_417 ,
V_414 ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_188 ( struct V_4 * V_5 ,
enum V_687 type , char * V_693 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_576 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
struct V_576 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
struct V_576 * V_127 = & ( V_24 -> V_136 . V_137 ) ;
int V_34 , V_694 , V_282 = 0 ;
T_2 clock , V_695 ;
switch ( type ) {
case V_690 :
F_14 ( V_5 -> V_21 , V_561 ) ;
clock = F_6 ( V_5 -> V_6 , V_562 ) ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ ) {
if ( clock > V_147 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_694 = V_34 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ )
V_282 += sprintf ( V_693 + V_282 , L_123 ,
V_34 , V_147 -> V_160 [ V_34 ] . V_39 / 100 ,
( V_34 == V_694 ) ? L_124 : L_125 ) ;
break;
case V_691 :
F_14 ( V_5 -> V_21 , V_564 ) ;
clock = F_6 ( V_5 -> V_6 , V_562 ) ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ ) {
if ( clock > V_149 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_694 = V_34 ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ )
V_282 += sprintf ( V_693 + V_282 , L_123 ,
V_34 , V_149 -> V_160 [ V_34 ] . V_39 / 100 ,
( V_34 == V_694 ) ? L_124 : L_125 ) ;
break;
case V_692 :
V_695 = F_7 ( V_5 ) ;
for ( V_34 = 0 ; V_34 < V_127 -> V_37 ; V_34 ++ ) {
if ( V_695 != V_127 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_694 = V_34 ;
for ( V_34 = 0 ; V_34 < V_127 -> V_37 ; V_34 ++ )
V_282 += sprintf ( V_693 + V_282 , L_126 , V_34 ,
( V_127 -> V_160 [ V_34 ] . V_39 == 0 ) ? L_127 :
( V_127 -> V_160 [ V_34 ] . V_39 == 1 ) ? L_128 :
( V_127 -> V_160 [ V_34 ] . V_39 == 2 ) ? L_129 : L_125 ,
( V_34 == V_694 ) ? L_124 : L_125 ) ;
break;
default:
break;
}
return V_282 ;
}
static int F_189 ( struct V_4 * V_5 , T_2 V_696 )
{
if ( V_696 ) {
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_697 ) )
F_190 ( V_5 ) ;
F_191 ( V_5 , V_696 ) ;
} else
F_192 ( V_5 ) ;
return 0 ;
}
static int F_193 ( struct V_4 * V_5 )
{
if ( V_5 -> V_698 )
return V_5 -> V_699 ;
else
return F_49 ( V_5 -> V_6 , V_28 ,
V_700 , V_701 ) ;
}
static int F_194 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_576 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
struct V_576 * V_702 =
& ( V_24 -> V_169 . V_147 ) ;
int V_39 ;
V_39 = ( V_147 -> V_160 [ V_147 -> V_37 - 1 ] . V_39 -
V_702 -> V_160 [ V_702 -> V_37 - 1 ] . V_39 ) *
100 /
V_702 -> V_160 [ V_702 -> V_37 - 1 ] . V_39 ;
return V_39 ;
}
static int F_195 ( struct V_4 * V_5 , T_2 V_39 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_576 * V_702 =
& ( V_24 -> V_169 . V_147 ) ;
struct V_429 * V_470 ;
struct V_1 * V_432 ;
if ( V_39 > 20 )
V_39 = 20 ;
V_470 = V_5 -> V_430 ;
if ( V_470 == NULL )
return - V_120 ;
V_432 = F_1 ( & V_470 -> V_433 ) ;
V_432 -> V_449 [ V_432 -> V_445 - 1 ] . V_451 =
V_702 -> V_160 [ V_702 -> V_37 - 1 ] . V_39 *
V_39 / 100 +
V_702 -> V_160 [ V_702 -> V_37 - 1 ] . V_39 ;
return 0 ;
}
static int F_196 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_576 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
struct V_576 * V_703 =
& ( V_24 -> V_169 . V_149 ) ;
int V_39 ;
V_39 = ( V_149 -> V_160 [ V_149 -> V_37 - 1 ] . V_39 -
V_703 -> V_160 [ V_703 -> V_37 - 1 ] . V_39 ) *
100 /
V_703 -> V_160 [ V_703 -> V_37 - 1 ] . V_39 ;
return V_39 ;
}
static int F_197 ( struct V_4 * V_5 , T_2 V_39 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_576 * V_703 =
& ( V_24 -> V_169 . V_149 ) ;
struct V_429 * V_470 ;
struct V_1 * V_432 ;
if ( V_39 > 20 )
V_39 = 20 ;
V_470 = V_5 -> V_430 ;
if ( V_470 == NULL )
return - V_120 ;
V_432 = F_1 ( & V_470 -> V_433 ) ;
V_432 -> V_449 [ V_432 -> V_445 - 1 ] . V_450 =
V_703 -> V_160 [ V_703 -> V_37 - 1 ] . V_39 *
V_39 / 100 +
V_703 -> V_160 [ V_703 -> V_37 - 1 ] . V_39 ;
return 0 ;
}
static int F_198 ( struct V_4 * V_5 , struct V_704 * V_705 )
{
struct V_42 * V_43 =
(struct V_42 * ) V_5 -> V_44 ;
struct V_165 * V_166 = NULL ;
struct V_32 * V_147 ;
int V_34 ;
if ( V_5 -> V_53 == V_54 ) {
if ( V_43 == NULL || V_43 -> V_168 == NULL )
return - V_120 ;
V_166 = V_43 -> V_168 ;
for ( V_34 = 0 ; V_34 < V_166 -> V_37 ; V_34 ++ ) {
V_705 -> clock [ V_34 ] = V_166 -> V_38 [ V_34 ] . V_161 ;
V_705 -> V_37 ++ ;
}
} else if ( V_5 -> V_53 == V_56 ) {
V_147 = V_5 -> V_57 . V_155 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ ) {
V_705 -> clock [ V_34 ] = V_147 -> V_38 [ V_34 ] . V_161 ;
V_705 -> V_37 ++ ;
}
}
return 0 ;
}
static T_2 F_199 ( struct V_4 * V_5 , T_2 V_161 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_161 >= V_706 && V_161 < V_707 )
return V_24 -> V_643 ;
else if ( V_161 >= V_707 )
return V_24 -> V_645 ;
else
return V_708 ;
}
static int F_200 ( struct V_4 * V_5 , struct V_704 * V_705 )
{
struct V_42 * V_43 =
(struct V_42 * ) V_5 -> V_44 ;
struct V_165 * V_167 ;
int V_34 ;
struct V_32 * V_149 ;
if ( V_5 -> V_53 == V_54 ) {
if ( V_43 == NULL )
return - V_120 ;
V_167 = V_43 -> V_55 ;
for ( V_34 = 0 ; V_34 < V_167 -> V_37 ; V_34 ++ ) {
V_705 -> clock [ V_34 ] = V_167 -> V_38 [ V_34 ] . V_161 ;
V_705 -> V_709 [ V_34 ] = F_199 ( V_5 ,
V_167 -> V_38 [ V_34 ] . V_161 ) ;
V_705 -> V_37 ++ ;
}
} else if ( V_5 -> V_53 == V_56 ) {
V_149 = V_5 -> V_57 . V_68 ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ ) {
V_705 -> clock [ V_34 ] = V_149 -> V_38 [ V_34 ] . V_161 ;
V_705 -> V_37 ++ ;
}
}
return 0 ;
}
static int F_201 ( struct V_4 * V_5 , enum V_710 type ,
struct V_704 * V_705 )
{
switch ( type ) {
case V_711 :
F_198 ( V_5 , V_705 ) ;
break;
case V_712 :
F_200 ( V_5 , V_705 ) ;
break;
default:
return - V_120 ;
}
return 0 ;
}
T_6 F_202 ( T_2 clock ,
T_2 V_713 )
{
T_6 V_34 ;
T_2 V_678 ;
T_2 V_280 = V_278 ( V_713 , ( T_2 ) V_583 ) ;
F_2 ((clock >= min), L_130 , return 0 ) ;
for ( V_34 = V_714 ; ; V_34 -- ) {
V_678 = clock >> V_34 ;
if ( V_678 >= V_280 || V_34 == 0 )
break;
}
return V_34 ;
}
int F_203 ( struct V_4 * V_5 )
{
int V_424 = 0 ;
V_5 -> V_715 = & V_716 ;
if ( V_5 -> V_53 == V_56 )
V_5 -> V_717 = & V_718 ;
else if ( V_5 -> V_53 == V_54 )
V_5 -> V_717 = & V_719 ;
F_204 ( V_5 ) ;
return V_424 ;
}
