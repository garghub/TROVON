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
F_63 ( L_27 ) ;
return - V_120 ;
}
if ( 0 == V_24 -> V_212 ) {
F_2 (
(0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_PCIeDPM_Enable)),
L_28 ,
return -EINVAL) ;
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_213 ) ) {
F_2 ( ( 0 == F_14 ( V_5 -> V_21 ,
V_214 ) ) ,
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
F_14 ( V_5 -> V_21 , V_215 ) ;
}
if ( ! V_24 -> V_200 ) {
F_2 (true == smum_is_dpm_running(hwmgr),
L_31 ,
return 0 ) ;
F_14 ( V_5 -> V_21 , V_216 ) ;
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
if ( ! V_24 -> V_212 ) {
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
F_14 ( V_5 -> V_21 , V_217 ) ;
return 0 ;
}
static void F_66 ( struct V_4 * V_5 , T_2 V_218 )
{
bool V_219 ;
enum V_220 V_221 ;
switch ( V_218 ) {
default:
F_63 ( L_34 ) ;
case 0 :
V_219 = false ;
break;
case ( 1 << V_222 ) :
V_219 = true ;
V_221 = V_223 ;
break;
case ( 1 << V_224 ) :
V_219 = true ;
V_221 = V_225 ;
break;
case ( 1 << V_224 ) |
( 1 << V_222 ) :
V_219 = true ;
V_221 = V_226 ;
break;
}
if ( V_219 ) {
F_17 ( V_5 -> V_6 , V_28 , V_227 ,
V_220 , V_221 ) ;
F_17 ( V_5 -> V_6 , V_28 , V_29 ,
V_228 ,
! F_52 ( V_5 -> V_182 . V_183 ,
V_229 ) ) ;
} else
F_17 ( V_5 -> V_6 , V_28 , V_29 ,
V_228 , 1 ) ;
}
static int F_67 ( struct V_4 * V_5 ,
T_4 V_230 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( ! ( V_24 -> V_231 & ( 1 << V_230 ) ) ) {
V_24 -> V_231 |= 1 << V_230 ;
F_66 ( V_5 , V_24 -> V_231 ) ;
}
return 0 ;
}
static int F_68 ( struct V_4 * V_5 )
{
return F_67 ( V_5 , V_222 ) ;
}
static int F_69 ( struct V_4 * V_5 ,
T_4 V_230 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_24 -> V_231 & ( 1 << V_230 ) ) {
V_24 -> V_231 &= ~ ( 1 << V_230 ) ;
F_66 ( V_5 , V_24 -> V_231 ) ;
}
return 0 ;
}
static int F_70 ( struct V_4 * V_5 )
{
return F_69 ( V_5 , V_222 ) ;
}
static int F_71 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_232 = true ;
return 0 ;
}
static int F_72 ( struct V_4 * V_5 )
{
int V_233 = 0 ;
int V_45 = 0 ;
V_233 = ( ! F_73 ( V_5 ) ) ? 0 : - 1 ;
F_2 ( V_233 == 0 ,
L_35 ,
) ;
if ( F_15 ( V_5 ) ) {
V_233 = F_16 ( V_5 ) ;
F_2 ( V_233 == 0 ,
L_36 ,
V_45 = V_233 ) ;
V_233 = F_19 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_37 ,
V_45 = V_233 ) ;
}
F_74 ( V_5 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_234 ) )
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_235 , 1 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_229 ) )
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_228 , 0 ) ;
V_233 = F_26 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_38 ,
V_45 = V_233 ) ;
V_233 = F_27 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_39 , V_45 = V_233 ) ;
V_233 = F_30 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_40 , V_45 = V_233 ) ;
V_233 = F_75 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_41 , V_45 = V_233 ) ;
V_233 = F_36 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_42 ,
V_45 = V_233 ) ;
V_45 = F_47 ( V_5 ) ;
F_2 ( 0 == result,
L_43 , return result) ;
V_233 = F_76 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_44 , V_45 = V_233 ) ;
V_233 = F_51 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_45 , V_45 = V_233 ) ;
F_14 ( V_5 -> V_21 , ( V_236 ) V_237 ) ;
V_233 = F_53 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_46 , V_45 = V_233 ) ;
V_233 = F_13 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_36 , V_45 = V_233 ) ;
V_233 = F_54 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_47 , V_45 = V_233 ) ;
V_233 = F_56 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_48 , V_45 = V_233 ) ;
V_233 = F_77 ( V_5 ) ;
F_2 ( ( V_233 == 0 ) ,
L_48 , V_45 = V_233 ) ;
V_233 = F_62 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_49 , V_45 = V_233 ) ;
V_233 = F_78 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_50 , V_45 = V_233 ) ;
V_233 = F_79 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_51 , V_45 = V_233 ) ;
V_233 = F_80 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_52 , V_45 = V_233 ) ;
V_233 = F_68 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_53 , V_45 = V_233 ) ;
V_233 = F_71 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_54 , V_45 = V_233 ) ;
return 0 ;
}
int F_81 ( struct V_4 * V_5 )
{
int V_233 , V_45 = 0 ;
V_233 = ( F_73 ( V_5 ) ) ? 0 : - 1 ;
F_2 (tmp_result == 0 ,
L_55 ,
return 0 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_229 ) )
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_228 , 1 ) ;
V_233 = F_82 ( V_5 ) ;
F_2 ( ( V_233 == 0 ) ,
L_56 , V_45 = V_233 ) ;
V_233 = F_83 ( V_5 ) ;
F_2 ( ( V_233 == 0 ) ,
L_57 , V_45 = V_233 ) ;
V_233 = F_84 ( V_5 ) ;
F_2 ( ( V_233 == 0 ) ,
L_58 , V_45 = V_233 ) ;
F_17 ( V_5 -> V_6 , V_28 ,
V_238 , V_239 , 0 ) ;
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_235 , 0 ) ;
V_233 = F_70 ( V_5 ) ;
F_2 ( ( V_233 == 0 ) ,
L_59 , V_45 = V_233 ) ;
if ( 1 == F_49 ( V_5 -> V_6 , V_28 , V_240 , V_241 ) ) {
F_2 ((0 == smum_send_msg_to_smc(hwmgr->smumgr, PPSMC_MSG_DisableAvfs)),
L_60 ,
return -EINVAL) ;
}
V_233 = F_65 ( V_5 ) ;
F_2 ( ( V_233 == 0 ) ,
L_61 , V_45 = V_233 ) ;
V_233 = F_57 ( V_5 ) ;
F_2 ( ( V_233 == 0 ) ,
L_62 , V_45 = V_233 ) ;
V_233 = F_55 ( V_5 ) ;
F_2 ( ( V_233 == 0 ) ,
L_63 , V_45 = V_233 ) ;
V_233 = F_31 ( V_5 ) ;
F_2 ( ( V_233 == 0 ) ,
L_64 , V_45 = V_233 ) ;
V_233 = F_35 ( V_5 ) ;
F_2 ( ( V_233 == 0 ) ,
L_65 , V_45 = V_233 ) ;
V_233 = F_37 ( V_5 ) ;
F_2 ( ( V_233 == 0 ) ,
L_66 , V_45 = V_233 ) ;
return V_45 ;
}
int F_85 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_86 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_242 V_243 = { 0 } ;
int V_45 ;
V_24 -> V_244 = false ;
V_24 -> V_245 = 0xa ;
V_24 -> V_246 = V_247 ;
V_24 -> V_248 = 300 ;
V_24 -> V_78 = V_249 ;
V_24 -> V_76 = V_250 ;
V_24 -> V_90 = V_251 ;
V_24 -> V_92 = V_252 ;
V_24 -> V_94 = V_253 ;
V_24 -> V_96 = V_254 ;
V_24 -> V_98 = V_255 ;
V_24 -> V_100 = V_256 ;
V_24 -> V_102 = V_257 ;
V_24 -> V_104 = V_258 ;
V_24 -> V_200 = V_5 -> V_19 & V_259 ? false : true ;
V_24 -> V_199 = V_5 -> V_19 & V_260 ? false : true ;
V_24 -> V_212 = V_5 -> V_19 & V_261 ? false : true ;
V_24 -> V_27 = V_26 ;
V_24 -> V_59 = V_26 ;
V_24 -> V_48 = V_26 ;
V_24 -> V_262 = true ;
V_24 -> V_263 = true ;
V_24 -> V_264 = V_265 ;
V_24 -> V_187 = V_5 -> V_19 & V_266 ? true : false ;
if ( V_5 -> V_267 == V_268 || V_5 -> V_21 -> V_269 ) {
T_5 V_270 , V_271 ;
T_1 V_272 = 0 ;
F_87 ( V_5 , V_66 , & V_270 , & V_271 ,
& V_272 ) ;
V_272 = ( V_272 >> 5 ) & 0x3 ;
V_24 -> V_273 = ( ( V_272 << 1 ) | ( V_272 >> 1 ) ) & 0x3 ;
}
V_24 -> V_274 = 100 ;
if ( F_88 ( V_5 ,
V_66 , V_275 ) )
V_24 -> V_27 = V_52 ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_276 ) ) {
if ( F_88 ( V_5 ,
V_277 , V_275 ) ) {
V_24 -> V_63 = V_52 ;
}
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_278 ) ) {
if ( F_88 ( V_5 ,
V_49 , V_50 ) )
V_24 -> V_48 = V_47 ;
else if ( F_88 ( V_5 ,
V_49 , V_275 ) )
V_24 -> V_48 = V_52 ;
}
if ( V_26 == V_24 -> V_63 ) {
F_89 ( V_5 -> V_182 . V_183 ,
V_276 ) ;
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_279 ) ) {
if ( F_88 ( V_5 ,
V_60 , V_50 ) )
V_24 -> V_59 = V_47 ;
else if ( F_88 ( V_5 ,
V_60 , V_275 ) )
V_24 -> V_59 = V_52 ;
}
if ( V_24 -> V_48 == V_26 )
F_89 ( V_5 -> V_182 . V_183 ,
V_278 ) ;
if ( V_24 -> V_59 == V_26 )
F_89 ( V_5 -> V_182 . V_183 ,
V_279 ) ;
if ( ( V_5 -> V_53 != V_56 ) && ( V_5 -> V_19 & V_280 )
&& ( V_43 -> V_281 -> V_282 != 0 ) )
F_90 ( V_5 -> V_182 . V_183 ,
V_283 ) ;
V_24 -> V_132 . V_284 = V_285 ;
V_24 -> V_132 . V_286 = V_287 ;
V_24 -> V_131 . V_284 = V_285 ;
V_24 -> V_131 . V_286 = V_287 ;
V_24 -> V_134 . V_284 = 0 ;
V_24 -> V_134 . V_286 = 16 ;
V_24 -> V_133 . V_284 = 0 ;
V_24 -> V_133 . V_286 = 16 ;
V_243 . V_288 = sizeof( struct V_242 ) ;
V_243 . V_289 = V_290 ;
V_45 = F_91 ( V_5 -> V_6 , & V_243 ) ;
if ( ! V_45 ) {
if ( V_243 . V_39 & V_291 )
F_90 ( V_5 -> V_182 . V_183 ,
V_292 ) ;
if ( V_243 . V_39 & V_293 )
F_90 ( V_5 -> V_182 . V_183 ,
V_294 ) ;
}
}
static int F_92 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_1 V_295 ;
T_1 V_296 = 0 ;
T_1 V_297 = 0 ;
T_1 V_34 , V_298 ;
T_2 V_299 = 0 ;
struct V_42 * V_43 =
(struct V_42 * ) V_5 -> V_44 ;
struct V_165 * V_147 = NULL ;
for ( V_34 = 0 ; V_34 < V_300 ; V_34 ++ ) {
V_295 = V_301 + V_34 ;
if ( V_24 -> V_63 == V_52 ) {
if ( ( V_5 -> V_53 == V_54 )
&& ! F_93 ( V_5 ,
V_43 -> V_65 , V_295 , & V_299 ) ) {
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_283 ) ) {
V_147 = V_43 -> V_168 ;
for ( V_298 = 1 ; V_298 < V_147 -> V_37 ; V_298 ++ ) {
if ( V_147 -> V_38 [ V_298 ] . V_161 == V_299 &&
V_147 -> V_38 [ V_298 ] . V_302 == 0 ) {
V_299 += 5000 ;
break;
}
}
}
if ( 0 == F_94
( V_5 , V_277 , V_299 ,
V_295 , & V_297 ) ) {
F_2 ((vddgfx < 2000 && vddgfx != 0), L_67 , return -EINVAL) ;
if ( V_297 != 0 && V_297 != V_295 ) {
V_24 -> V_303 . V_304 [ V_24 -> V_303 . V_37 ] = V_297 ;
V_24 -> V_303 . V_305 [ V_24 -> V_303 . V_37 ] = V_295 ;
V_24 -> V_303 . V_37 ++ ;
}
} else {
F_95 ( L_68 ) ;
}
}
} else {
if ( ( V_5 -> V_53 == V_56 )
|| ! F_93 ( V_5 ,
V_43 -> V_69 , V_295 , & V_299 ) ) {
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_283 ) ) {
if ( V_43 == NULL )
return - V_120 ;
V_147 = V_43 -> V_168 ;
for ( V_298 = 1 ; V_298 < V_147 -> V_37 ; V_298 ++ ) {
if ( V_147 -> V_38 [ V_298 ] . V_161 == V_299 &&
V_147 -> V_38 [ V_298 ] . V_302 == 0 ) {
V_299 += 5000 ;
break;
}
}
}
if ( F_96 ( V_5 ,
V_66 ,
V_299 , V_295 , & V_296 ) == 0 ) {
if ( V_296 >= 2000 || V_296 == 0 )
return - V_120 ;
} else {
F_97 ( L_69 ) ;
continue;
}
if ( V_296 != 0 && V_296 != V_295 ) {
V_24 -> V_306 . V_304 [ V_24 -> V_306 . V_37 ] = ( T_1 ) ( V_296 ) ;
V_24 -> V_306 . V_305 [ V_24 -> V_306 . V_37 ] = V_295 ;
V_24 -> V_306 . V_37 ++ ;
}
}
}
}
return 0 ;
}
static void F_98 ( struct V_4 * V_5 ,
T_1 * V_307 , struct V_308 * V_309 )
{
T_2 V_310 ;
for ( V_310 = 0 ; V_310 < V_309 -> V_37 ; V_310 ++ ) {
if ( V_309 -> V_305 [ V_310 ] == * V_307 ) {
* V_307 = V_309 -> V_304 [ V_310 ] ;
break;
}
}
if ( * V_307 > V_301 )
F_63 ( L_70 ) ;
}
static int F_99 ( struct V_4 * V_5 ,
T_6 * V_311 ,
struct V_308 * V_309 )
{
T_2 V_34 ;
for ( V_34 = 0 ; V_34 < V_311 -> V_37 ; V_34 ++ )
F_98 ( V_5 ,
& V_311 -> V_38 [ V_34 ] . V_312 , V_309 ) ;
return 0 ;
}
static int F_100 (
struct V_4 * V_5 , struct V_308 * V_309 ,
T_1 * V_296 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
F_98 ( V_5 , ( T_1 * ) V_296 , V_309 ) ;
V_5 -> V_57 . V_313 . V_296 =
V_43 -> V_313 . V_296 ;
return 0 ;
}
static int F_101 (
struct V_4 * V_5 )
{
T_5 V_314 ;
T_5 V_315 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_147 =
V_43 -> V_168 ;
struct V_165 * V_149 =
V_43 -> V_55 ;
struct V_316 * V_317 =
V_43 -> V_318 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_314 = 0 ; V_314 < V_147 -> V_37 ; ++ V_314 ) {
V_315 = V_147 -> V_38 [ V_314 ] . V_319 ;
V_147 -> V_38 [ V_314 ] . V_297 =
V_43 -> V_65 -> V_38 [ V_315 ] . V_312 ;
}
} else {
for ( V_314 = 0 ; V_314 < V_147 -> V_37 ; ++ V_314 ) {
V_315 = V_147 -> V_38 [ V_314 ] . V_319 ;
V_147 -> V_38 [ V_314 ] . V_296 =
V_43 -> V_69 -> V_38 [ V_315 ] . V_312 ;
}
}
for ( V_314 = 0 ; V_314 < V_149 -> V_37 ; ++ V_314 ) {
V_315 = V_149 -> V_38 [ V_314 ] . V_319 ;
V_149 -> V_38 [ V_314 ] . V_296 =
V_43 -> V_69 -> V_38 [ V_315 ] . V_312 ;
}
for ( V_314 = 0 ; V_314 < V_317 -> V_37 ; ++ V_314 ) {
V_315 = V_317 -> V_38 [ V_314 ] . V_320 ;
V_317 -> V_38 [ V_314 ] . V_296 =
V_43 -> V_69 -> V_38 [ V_315 ] . V_312 ;
}
return 0 ;
}
static int F_102 ( struct V_4 * V_5 ,
T_6 * V_321 ,
T_7 * V_322 )
{
T_2 V_34 ;
F_2 ((NULL != look_up_table),
L_71 , return -EINVAL) ;
F_2 ((0 != look_up_table->count),
L_71 , return -EINVAL) ;
V_34 = F_24 ( V_5 -> V_21 , V_71 ) ;
F_2 ((i >= look_up_table->count),
L_72 , return -EINVAL) ;
for ( V_34 = 0 ; V_34 < V_321 -> V_37 ; V_34 ++ ) {
if ( V_321 -> V_38 [ V_34 ] . V_312 == V_322 -> V_312 ) {
if ( V_321 -> V_38 [ V_34 ] . V_323 == 1 )
return 0 ;
break;
}
}
V_321 -> V_38 [ V_34 ] . V_323 = 1 ;
V_321 -> V_38 [ V_34 ] . V_312 = V_322 -> V_312 ;
V_321 -> V_38 [ V_34 ] . V_324 = V_322 -> V_324 ;
V_321 -> V_38 [ V_34 ] . V_325 = V_322 -> V_325 ;
V_321 -> V_38 [ V_34 ] . V_326 = V_322 -> V_326 ;
if ( V_34 == V_321 -> V_37 )
V_321 -> V_37 ++ ;
return 0 ;
}
static int F_103 ( struct V_4 * V_5 )
{
T_5 V_314 ;
struct T_7 V_327 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_328 = (struct V_42 * ) ( V_5 -> V_44 ) ;
V_165 * V_147 = V_328 -> V_168 ;
V_165 * V_149 = V_328 -> V_55 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_314 = 0 ; V_314 < V_147 -> V_37 ; ++ V_314 ) {
if ( V_147 -> V_38 [ V_314 ] . V_329 & ( 1 << 15 ) )
V_327 . V_312 = V_147 -> V_38 [ V_314 ] . V_297 +
V_147 -> V_38 [ V_314 ] . V_329 - 0xFFFF ;
else
V_327 . V_312 = V_147 -> V_38 [ V_314 ] . V_297 +
V_147 -> V_38 [ V_314 ] . V_329 ;
V_147 -> V_38 [ V_314 ] . V_296 =
V_327 . V_324 = V_327 . V_325 =
V_327 . V_326 = V_327 . V_312 ;
F_102 ( V_5 , V_328 -> V_69 , & V_327 ) ;
}
for ( V_314 = 0 ; V_314 < V_149 -> V_37 ; ++ V_314 ) {
if ( V_149 -> V_38 [ V_314 ] . V_329 & ( 1 << 15 ) )
V_327 . V_312 = V_149 -> V_38 [ V_314 ] . V_296 +
V_149 -> V_38 [ V_314 ] . V_329 - 0xFFFF ;
else
V_327 . V_312 = V_149 -> V_38 [ V_314 ] . V_296 +
V_149 -> V_38 [ V_314 ] . V_329 ;
V_149 -> V_38 [ V_314 ] . V_297 = V_327 . V_324 =
V_327 . V_325 = V_327 . V_326 = V_327 . V_312 ;
F_102 ( V_5 , V_328 -> V_65 , & V_327 ) ;
}
}
return 0 ;
}
static int F_104 ( struct V_4 * V_5 )
{
T_5 V_314 ;
struct T_7 V_327 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_328 = (struct V_42 * ) ( V_5 -> V_44 ) ;
V_316 * V_317 = V_328 -> V_318 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_314 = 0 ; V_314 < V_317 -> V_37 ; V_314 ++ ) {
if ( V_317 -> V_38 [ V_314 ] . V_330 & ( 1 << 15 ) )
V_327 . V_312 = V_317 -> V_38 [ V_314 ] . V_296 +
V_317 -> V_38 [ V_314 ] . V_330 - 0xFFFF ;
else
V_327 . V_312 = V_317 -> V_38 [ V_314 ] . V_296 +
V_317 -> V_38 [ V_314 ] . V_330 ;
V_317 -> V_38 [ V_314 ] . V_297 = V_327 . V_324 =
V_327 . V_325 = V_327 . V_326 = V_327 . V_312 ;
F_102 ( V_5 , V_328 -> V_65 , & V_327 ) ;
}
}
return 0 ;
}
static int F_105 ( struct V_4 * V_5 ,
struct T_6 * V_311 )
{
T_2 V_331 , V_34 , V_298 ;
struct T_7 V_332 ;
V_331 = V_311 -> V_37 ;
F_2 ( 0 != lookup_table->count,
L_73 , return -EINVAL) ;
for ( V_34 = 0 ; V_34 < V_331 - 1 ; V_34 ++ ) {
for ( V_298 = V_34 + 1 ; V_298 > 0 ; V_298 -- ) {
if ( V_311 -> V_38 [ V_298 ] . V_312 <
V_311 -> V_38 [ V_298 - 1 ] . V_312 ) {
V_332 = V_311 -> V_38 [ V_298 - 1 ] ;
V_311 -> V_38 [ V_298 - 1 ] = V_311 -> V_38 [ V_298 ] ;
V_311 -> V_38 [ V_298 ] = V_332 ;
}
}
}
return 0 ;
}
static int F_106 ( struct V_4 * V_5 )
{
int V_45 = 0 ;
int V_233 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
if ( V_24 -> V_63 == V_52 ) {
V_233 = F_99 ( V_5 ,
V_43 -> V_65 , & ( V_24 -> V_303 ) ) ;
if ( V_233 != 0 )
V_45 = V_233 ;
F_98 ( V_5 ,
& V_43 -> V_313 . V_297 , & ( V_24 -> V_303 ) ) ;
} else {
V_233 = F_99 ( V_5 ,
V_43 -> V_69 , & ( V_24 -> V_306 ) ) ;
if ( V_233 )
V_45 = V_233 ;
V_233 = F_100 ( V_5 ,
& ( V_24 -> V_306 ) , & V_43 -> V_313 . V_296 ) ;
if ( V_233 )
V_45 = V_233 ;
}
V_233 = F_101 ( V_5 ) ;
if ( V_233 )
V_45 = V_233 ;
V_233 = F_103 ( V_5 ) ;
if ( V_233 )
V_45 = V_233 ;
V_233 = F_104 ( V_5 ) ;
if ( V_233 )
V_45 = V_233 ;
V_233 = F_105 ( V_5 , V_43 -> V_65 ) ;
if ( V_233 )
V_45 = V_233 ;
V_233 = F_105 ( V_5 , V_43 -> V_69 ) ;
if ( V_233 )
V_45 = V_233 ;
return V_45 ;
}
static int F_107 ( struct V_4 * V_5 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_333 =
V_43 -> V_168 ;
struct V_165 * V_334 =
V_43 -> V_55 ;
F_2 (allowed_sclk_vdd_table != NULL,
L_74 ,
return -EINVAL) ;
F_2 (allowed_sclk_vdd_table->count >= 1 ,
L_75 ,
return -EINVAL) ;
F_2 (allowed_mclk_vdd_table != NULL,
L_76 ,
return -EINVAL) ;
F_2 (allowed_mclk_vdd_table->count >= 1 ,
L_77 ,
return -EINVAL) ;
V_43 -> V_335 . V_299 =
V_333 -> V_38 [ V_333 -> V_37 - 1 ] . V_161 ;
V_43 -> V_335 . V_336 =
V_334 -> V_38 [ V_334 -> V_37 - 1 ] . V_161 ;
V_43 -> V_335 . V_296 =
V_333 -> V_38 [ V_333 -> V_37 - 1 ] . V_296 ;
V_43 -> V_335 . V_337 =
V_334 -> V_38 [ V_334 -> V_37 - 1 ] . V_337 ;
V_5 -> V_57 . V_335 . V_299 = V_43 -> V_335 . V_299 ;
V_5 -> V_57 . V_335 . V_336 = V_43 -> V_335 . V_336 ;
V_5 -> V_57 . V_335 . V_296 = V_43 -> V_335 . V_296 ;
V_5 -> V_57 . V_335 . V_337 = V_43 -> V_335 . V_337 ;
return 0 ;
}
static int F_108 ( struct V_4 * V_5 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_167 ;
struct T_6 * V_311 ;
T_2 V_34 ;
T_2 V_338 , V_339 , V_340 ;
struct V_242 V_243 = { 0 } ;
if ( V_43 != NULL ) {
V_167 = V_43 -> V_55 ;
V_311 = V_43 -> V_69 ;
} else
return 0 ;
V_243 . V_288 = sizeof( struct V_242 ) ;
V_243 . V_289 = V_341 ;
F_91 ( V_5 -> V_6 , & V_243 ) ;
V_338 = ( T_2 ) V_243 . V_39 ;
V_243 . V_289 = V_342 ;
F_91 ( V_5 -> V_6 , & V_243 ) ;
V_340 = ( T_2 ) V_243 . V_39 ;
V_243 . V_289 = V_343 ;
F_91 ( V_5 -> V_6 , & V_243 ) ;
V_339 = ( T_2 ) V_243 . V_39 ;
if ( V_5 -> V_267 == V_344 && V_338 == 0xC7 &&
( ( V_340 == 0xb37 && V_339 == 0x1002 ) ||
( V_340 == 0x4a8 && V_339 == 0x1043 ) ||
( V_340 == 0x9480 && V_339 == 0x1682 ) ) ) {
if ( V_311 -> V_38 [ V_167 -> V_38 [ V_167 -> V_37 - 1 ] . V_319 ] . V_312 >= 1000 )
return 0 ;
for ( V_34 = 0 ; V_34 < V_311 -> V_37 ; V_34 ++ ) {
if ( V_311 -> V_38 [ V_34 ] . V_312 < 0xff01 && V_311 -> V_38 [ V_34 ] . V_312 >= 1000 ) {
V_167 -> V_38 [ V_167 -> V_37 - 1 ] . V_319 = ( T_5 ) V_34 ;
return 0 ;
}
}
}
return 0 ;
}
static int F_109 ( struct V_4 * V_5 )
{
struct V_345 V_346 ;
T_2 V_347 ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
if ( F_110 ( V_5 , V_348 , & V_346 ) ) {
V_347 = F_8 ( V_5 -> V_6 , V_28 , V_349 ) ;
switch ( V_346 . V_350 ) {
case 0 :
V_347 = F_28 ( V_347 , V_351 , V_352 , 0x1 ) ;
break;
case 1 :
V_347 = F_28 ( V_347 , V_351 , V_352 , 0x2 ) ;
break;
case 2 :
V_347 = F_28 ( V_347 , V_351 , V_353 , 0x1 ) ;
break;
case 3 :
V_347 = F_28 ( V_347 , V_351 , V_354 , 0x1 ) ;
break;
case 4 :
V_347 = F_28 ( V_347 , V_351 , V_355 , 0x1 ) ;
break;
default:
F_2 ( 0 ,
L_78 ,
) ;
break;
}
F_29 ( V_5 -> V_6 , V_28 , V_349 , V_347 ) ;
}
if ( V_43 == NULL )
return 0 ;
if ( V_43 -> V_281 -> V_356 != 0 &&
V_5 -> V_357 . V_358 . V_359 ) {
V_5 -> V_357 . V_358 . V_360 =
( T_1 ) V_5 -> V_357 . V_358 . V_361 ;
V_5 -> V_357 . V_358 . V_362 =
( T_1 ) V_5 -> V_357 . V_358 . V_363 ;
V_5 -> V_357 . V_358 . V_364 = 1 ;
V_5 -> V_357 . V_358 . V_365 = 100 ;
V_5 -> V_357 . V_358 . V_366 =
( T_1 ) V_5 -> V_357 . V_358 . V_361 ;
V_5 -> V_357 . V_358 . V_367 = 1 ;
V_43 -> V_281 -> V_356 = ( V_43 -> V_281 -> V_356 >= 50 ) ?
( V_43 -> V_281 -> V_356 - 50 ) : 0 ;
V_43 -> V_281 -> V_368 = V_43 -> V_281 -> V_356 ;
V_43 -> V_281 -> V_369 = 1 ;
V_43 -> V_281 -> V_370 = 1 ;
V_5 -> V_357 . V_358 . V_371 =
V_5 -> V_357 . V_358 . V_363 ;
V_5 -> V_357 . V_358 . V_372 =
V_5 -> V_357 . V_358 . V_373 ;
V_5 -> V_57 . V_281 -> V_374 =
V_43 -> V_281 -> V_374 ;
V_5 -> V_57 . V_281 -> V_368 =
V_43 -> V_281 -> V_368 ;
V_5 -> V_57 . V_281 -> V_356 =
V_43 -> V_281 -> V_356 ;
V_5 -> V_57 . V_281 -> V_369 =
V_43 -> V_281 -> V_369 ;
V_5 -> V_57 . V_281 -> V_375 =
V_43 -> V_281 -> V_375 ;
if ( V_5 -> V_19 & V_376 )
F_90 ( V_5 -> V_182 . V_183 ,
V_377 ) ;
}
return 0 ;
}
static void F_111 ( struct V_4 * V_5 ,
T_2 * V_307 , struct V_308 * V_309 )
{
T_2 V_310 ;
for ( V_310 = 0 ; V_310 < V_309 -> V_37 ; V_310 ++ ) {
if ( V_309 -> V_305 [ V_310 ] == * V_307 ) {
* V_307 = V_309 -> V_304 [ V_310 ] ;
break;
}
}
if ( * V_307 > V_301 )
F_63 ( L_70 ) ;
}
static int F_112 ( struct V_4 * V_5 ,
struct V_32 * V_378 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_378 )
for ( V_34 = 0 ; V_34 < V_378 -> V_37 ; V_34 ++ )
F_111 ( V_5 , & V_378 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_306 ) ;
return 0 ;
}
static int F_113 ( struct V_4 * V_5 ,
struct V_32 * V_378 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_378 )
for ( V_34 = 0 ; V_34 < V_378 -> V_37 ; V_34 ++ )
F_111 ( V_5 , & V_378 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_379 ) ;
return 0 ;
}
static int F_114 ( struct V_4 * V_5 ,
struct V_380 * V_378 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_378 )
for ( V_34 = 0 ; V_34 < V_378 -> V_37 ; V_34 ++ )
F_111 ( V_5 , & V_378 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_306 ) ;
return 0 ;
}
static int F_115 ( struct V_4 * V_5 ,
struct V_381 * V_378 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_378 )
for ( V_34 = 0 ; V_34 < V_378 -> V_37 ; V_34 ++ )
F_111 ( V_5 , & V_378 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_306 ) ;
return 0 ;
}
static int F_116 ( struct V_4 * V_5 ,
struct V_382 * V_378 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_378 )
for ( V_34 = 0 ; V_34 < V_378 -> V_37 ; V_34 ++ )
F_111 ( V_5 , & V_378 -> V_38 [ V_34 ] . V_383 ,
& V_24 -> V_306 ) ;
return 0 ;
}
static int F_117 ( struct V_4 * V_5 ,
struct V_384 * V_378 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_378 )
for ( V_34 = 0 ; V_34 < V_378 -> V_37 ; V_34 ++ )
F_111 ( V_5 , & V_378 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_306 ) ;
return 0 ;
}
static int F_118 ( struct V_4 * V_5 ,
struct V_385 * V_378 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_378 )
for ( V_34 = 0 ; V_34 < V_378 -> V_37 ; V_34 ++ )
F_111 ( V_5 , & V_378 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_306 ) ;
return 0 ;
}
static int F_119 ( struct V_4 * V_5 ,
struct V_386 * V_378 )
{
T_2 V_296 , V_337 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_378 ) {
V_296 = V_378 -> V_296 ;
F_111 ( V_5 , & V_296 ,
& V_24 -> V_306 ) ;
V_378 -> V_296 = V_296 ;
V_337 = V_378 -> V_337 ;
F_111 ( V_5 , & V_337 ,
& V_24 -> V_379 ) ;
V_378 -> V_337 = V_337 ;
}
return 0 ;
}
static int F_120 ( struct V_4 * V_5 , struct V_157 * V_378 )
{
T_2 V_34 ;
T_2 V_296 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_378 ) {
for ( V_34 = 0 ; V_34 < V_378 -> V_37 ; V_34 ++ ) {
V_296 = ( T_2 ) ( V_378 -> V_38 [ V_34 ] . V_387 ) ;
F_111 ( V_5 , & V_296 , & V_24 -> V_306 ) ;
V_378 -> V_38 [ V_34 ] . V_387 = ( T_1 ) V_296 ;
}
}
return 0 ;
}
static int F_121 ( struct V_4 * V_5 )
{
int V_46 ;
V_46 = F_112 ( V_5 , V_5 -> V_57 . V_155 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_112 ( V_5 , V_5 -> V_57 . V_68 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_112 ( V_5 , V_5 -> V_57 . V_388 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_113 ( V_5 , V_5 -> V_57 . V_62 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_114 ( V_5 , V_5 -> V_57 . V_389 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_115 ( V_5 , V_5 -> V_57 . V_390 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_117 ( V_5 , V_5 -> V_57 . V_391 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_118 ( V_5 , V_5 -> V_57 . V_392 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_116 ( V_5 , V_5 -> V_57 . V_393 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_119 ( V_5 , & V_5 -> V_57 . V_335 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_119 ( V_5 , & V_5 -> V_57 . V_313 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_120 ( V_5 , V_5 -> V_57 . V_159 ) ;
if ( V_46 )
return - V_120 ;
return 0 ;
}
static int F_122 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_32 * V_394 = V_5 -> V_57 . V_155 ;
struct V_32 * V_395 = V_5 -> V_57 . V_68 ;
struct V_32 * V_396 = V_5 -> V_57 . V_62 ;
F_2 (allowed_sclk_vddc_table != NULL,
L_79 , return -EINVAL) ;
F_2 (allowed_sclk_vddc_table->count >= 1 ,
L_80 , return -EINVAL) ;
F_2 (allowed_mclk_vddc_table != NULL,
L_81 , return -EINVAL) ;
F_2 (allowed_mclk_vddc_table->count >= 1 ,
L_82 , return -EINVAL) ;
V_24 -> V_397 = ( T_1 ) V_394 -> V_38 [ 0 ] . V_40 ;
V_24 -> V_398 = ( T_1 ) V_394 -> V_38 [ V_394 -> V_37 - 1 ] . V_40 ;
V_5 -> V_57 . V_335 . V_299 =
V_394 -> V_38 [ V_394 -> V_37 - 1 ] . V_161 ;
V_5 -> V_57 . V_335 . V_336 =
V_395 -> V_38 [ V_395 -> V_37 - 1 ] . V_161 ;
V_5 -> V_57 . V_335 . V_296 =
V_394 -> V_38 [ V_394 -> V_37 - 1 ] . V_40 ;
if ( V_396 != NULL && V_396 -> V_37 >= 1 ) {
V_24 -> V_399 = ( T_1 ) V_396 -> V_38 [ 0 ] . V_40 ;
V_24 -> V_400 = ( T_1 ) V_396 -> V_38 [ V_396 -> V_37 - 1 ] . V_40 ;
}
if ( V_5 -> V_57 . V_62 != NULL && V_5 -> V_57 . V_62 -> V_37 > 1 )
V_5 -> V_57 . V_335 . V_337 = V_5 -> V_57 . V_62 -> V_38 [ V_5 -> V_57 . V_62 -> V_37 - 1 ] . V_40 ;
return 0 ;
}
static int F_123 ( struct V_4 * V_5 )
{
if ( NULL != V_5 -> V_57 . V_388 ) {
F_124 ( V_5 -> V_57 . V_388 ) ;
V_5 -> V_57 . V_388 = NULL ;
}
F_125 ( V_5 ) ;
if ( NULL != V_5 -> V_25 ) {
F_124 ( V_5 -> V_25 ) ;
V_5 -> V_25 = NULL ;
}
return 0 ;
}
static int F_126 ( struct V_4 * V_5 )
{
struct V_23 * V_24 ;
int V_45 ;
V_24 = F_127 ( sizeof( struct V_23 ) , V_401 ) ;
if ( V_24 == NULL )
return - V_402 ;
V_5 -> V_25 = V_24 ;
F_128 ( V_5 ) ;
F_108 ( V_5 ) ;
F_86 ( V_5 ) ;
V_45 = F_92 ( V_5 ) ;
if ( V_45 ) {
F_95 ( L_83 ) ;
return - V_120 ;
}
if ( V_5 -> V_53 == V_54 ) {
F_106 ( V_5 ) ;
F_107 ( V_5 ) ;
} else if ( V_5 -> V_53 == V_56 ) {
F_121 ( V_5 ) ;
F_122 ( V_5 ) ;
}
V_45 = F_129 ( V_5 ) ;
if ( 0 == V_45 ) {
struct V_242 V_243 = { 0 } ;
V_24 -> V_403 = false ;
V_5 -> V_182 . V_404 =
V_405 ;
V_5 -> V_182 . V_406 = 2 ;
V_5 -> V_182 . V_407 = 50 ;
V_243 . V_288 = sizeof( struct V_242 ) ;
V_243 . V_289 = V_408 ;
V_45 = F_91 ( V_5 -> V_6 , & V_243 ) ;
if ( V_45 )
V_24 -> V_139 = V_409 ;
else
V_24 -> V_139 = ( T_2 ) V_243 . V_39 ;
if ( V_24 -> V_139 & V_410 )
V_24 -> V_411 = 20 ;
V_243 . V_288 = sizeof( struct V_242 ) ;
V_243 . V_289 = V_412 ;
V_45 = F_91 ( V_5 -> V_6 , & V_243 ) ;
if ( V_45 )
V_24 -> V_141 = V_413 ;
else
V_24 -> V_141 = ( T_2 ) V_243 . V_39 ;
V_5 -> V_182 . V_414 = 0x20000400 ;
V_5 -> V_182 . V_415 . V_416 = 500 ;
V_5 -> V_182 . V_415 . V_417 = 500 ;
F_109 ( V_5 ) ;
} else {
F_123 ( V_5 ) ;
}
return 0 ;
}
static int F_130 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_418 , V_46 ;
if ( ! V_24 -> V_212 ) {
if ( V_24 -> V_419 . V_420 ) {
V_418 = 0 ;
V_46 = V_24 -> V_419 . V_420 ;
while ( V_46 >>= 1 )
V_418 ++ ;
if ( V_418 )
F_131 ( V_5 -> V_21 ,
V_421 , V_418 ) ;
}
}
if ( ! V_24 -> V_199 ) {
if ( V_24 -> V_419 . V_422 ) {
V_418 = 0 ;
V_46 = V_24 -> V_419 . V_422 ;
while ( V_46 >>= 1 )
V_418 ++ ;
if ( V_418 )
F_131 ( V_5 -> V_21 ,
V_423 ,
( 1 << V_418 ) ) ;
}
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_419 . V_424 ) {
V_418 = 0 ;
V_46 = V_24 -> V_419 . V_424 ;
while ( V_46 >>= 1 )
V_418 ++ ;
if ( V_418 )
F_131 ( V_5 -> V_21 ,
V_425 ,
( 1 << V_418 ) ) ;
}
}
return 0 ;
}
static int F_132 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_5 -> V_53 == V_54 )
F_133 ( V_5 ) ;
if ( ! V_24 -> V_199 ) {
if ( V_24 -> V_419 . V_422 )
F_131 ( V_5 -> V_21 ,
V_423 ,
V_24 -> V_419 . V_422 ) ;
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_419 . V_424 )
F_131 ( V_5 -> V_21 ,
V_425 ,
V_24 -> V_419 . V_424 ) ;
}
return 0 ;
}
static int F_134 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( ! F_73 ( V_5 ) )
return - V_120 ;
if ( ! V_24 -> V_212 ) {
F_14 ( V_5 -> V_21 ,
V_426 ) ;
}
return F_132 ( V_5 ) ;
}
static int F_135 ( struct V_4 * V_5 )
{
struct V_23 * V_24 =
(struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_418 ;
if ( ! V_24 -> V_199 )
if ( V_24 -> V_419 . V_422 ) {
V_418 = F_136 ( V_5 ,
V_24 -> V_419 . V_422 ) ;
F_131 ( V_5 -> V_21 ,
V_423 ,
( 1 << V_418 ) ) ;
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_419 . V_424 ) {
V_418 = F_136 ( V_5 ,
V_24 -> V_419 . V_424 ) ;
F_131 ( V_5 -> V_21 ,
V_425 ,
( 1 << V_418 ) ) ;
}
}
if ( ! V_24 -> V_212 ) {
if ( V_24 -> V_419 . V_420 ) {
V_418 = F_136 ( V_5 ,
V_24 -> V_419 . V_420 ) ;
F_131 ( V_5 -> V_21 ,
V_421 ,
( V_418 ) ) ;
}
}
return 0 ;
}
static int F_137 ( struct V_4 * V_5 , enum V_427 V_418 ,
T_2 * V_428 , T_2 * V_429 , T_2 * V_430 )
{
T_2 V_431 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_170 * V_169 = & V_24 -> V_169 ;
T_8 V_432 ;
T_8 V_433 ;
T_8 V_37 ;
if ( V_169 -> V_149 . V_37 < 1 )
return - V_120 ;
V_431 = 100 * V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 /
V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
if ( V_169 -> V_149 . V_37 == 1 ) {
V_431 = 70 ;
V_432 = V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
* V_429 = V_169 -> V_149 . V_37 - 1 ;
} else {
V_432 = V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 2 ] . V_39 ;
* V_429 = V_169 -> V_149 . V_37 - 2 ;
}
V_433 = V_432 * V_431 / 100 ;
if ( V_5 -> V_53 == V_56 ) {
for ( V_37 = V_5 -> V_57 . V_155 -> V_37 - 1 ;
V_37 >= 0 ; V_37 -- ) {
if ( V_433 >= V_5 -> V_57 . V_155 -> V_38 [ V_37 ] . V_161 ) {
V_433 = V_5 -> V_57 . V_155 -> V_38 [ V_37 ] . V_161 ;
* V_428 = V_37 ;
break;
}
}
if ( V_37 < 0 || V_418 == V_434 )
* V_428 = 0 ;
if ( V_418 == V_435 )
* V_428 = V_5 -> V_57 . V_155 -> V_37 - 1 ;
} else if ( V_5 -> V_53 == V_54 ) {
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
for ( V_37 = V_43 -> V_168 -> V_37 - 1 ; V_37 >= 0 ; V_37 -- ) {
if ( V_433 >= V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ) {
V_433 = V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ;
* V_428 = V_37 ;
break;
}
}
if ( V_37 < 0 || V_418 == V_434 )
* V_428 = 0 ;
if ( V_418 == V_435 )
* V_428 = V_43 -> V_168 -> V_37 - 1 ;
}
if ( V_418 == V_436 )
* V_429 = 0 ;
else if ( V_418 == V_435 )
* V_429 = V_169 -> V_149 . V_37 - 1 ;
* V_430 = V_24 -> V_136 . V_137 . V_37 - 1 ;
return 0 ;
}
static int F_138 ( struct V_4 * V_5 ,
enum V_427 V_418 )
{
int V_437 = 0 ;
T_2 V_428 = 0 ;
T_2 V_429 = 0 ;
T_2 V_430 = 0 ;
T_2 V_438 = V_439 |
V_434 |
V_436 |
V_435 ;
if ( V_418 == V_5 -> V_440 )
return V_437 ;
if ( ! ( V_5 -> V_440 & V_438 ) ) {
if ( V_418 & V_438 ) {
V_5 -> V_441 = V_5 -> V_440 ;
F_139 ( V_5 -> V_6 ,
V_442 ,
V_443 ) ;
}
} else {
if ( ! ( V_418 & V_438 ) ) {
if ( V_418 == V_444 )
V_418 = V_5 -> V_441 ;
F_139 ( V_5 -> V_6 ,
V_442 ,
V_445 ) ;
}
}
switch ( V_418 ) {
case V_446 :
V_437 = F_130 ( V_5 ) ;
if ( V_437 )
return V_437 ;
V_5 -> V_440 = V_418 ;
break;
case V_447 :
V_437 = F_135 ( V_5 ) ;
if ( V_437 )
return V_437 ;
V_5 -> V_440 = V_418 ;
break;
case V_448 :
V_437 = F_134 ( V_5 ) ;
if ( V_437 )
return V_437 ;
V_5 -> V_440 = V_418 ;
break;
case V_439 :
case V_434 :
case V_436 :
case V_435 :
V_437 = F_137 ( V_5 , V_418 , & V_428 , & V_429 , & V_430 ) ;
if ( V_437 )
return V_437 ;
V_5 -> V_440 = V_418 ;
F_140 ( V_5 , V_449 , 1 << V_428 ) ;
F_140 ( V_5 , V_450 , 1 << V_429 ) ;
F_140 ( V_5 , V_451 , 1 << V_430 ) ;
break;
case V_452 :
V_5 -> V_440 = V_418 ;
break;
case V_444 :
default:
break;
}
if ( V_418 == V_435 && V_5 -> V_441 != V_435 )
F_141 ( V_5 , 100 ) ;
else if ( V_418 != V_435 && V_5 -> V_441 == V_435 )
F_142 ( V_5 ) ;
return 0 ;
}
static int F_143 ( struct V_4 * V_5 )
{
return sizeof( struct V_1 ) ;
}
static int F_144 ( struct V_4 * V_5 ,
struct V_453 * V_454 ,
const struct V_453 * V_455 )
{
struct V_1 * V_456 =
F_1 ( & V_454 -> V_457 ) ;
T_2 V_299 ;
T_2 V_336 ;
struct V_458 V_459 = { 0 } ;
bool V_460 ;
bool V_461 ;
struct V_172 V_173 = { 0 } ;
const struct V_386 * V_462 ;
T_2 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
T_8 V_37 ;
T_8 V_463 = 0 , V_464 = 0 ;
V_24 -> V_465 = ( V_466 ==
V_454 -> V_467 . V_468 ) ;
F_2 ( V_456 -> V_469 == 2 ,
L_84 ,
) ;
V_462 = ( V_470 == V_5 -> V_471 ) ?
& ( V_5 -> V_57 . V_335 ) :
& ( V_5 -> V_57 . V_313 ) ;
if ( V_472 == V_5 -> V_471 ) {
for ( V_34 = 0 ; V_34 < V_456 -> V_469 ; V_34 ++ ) {
if ( V_456 -> V_473 [ V_34 ] . V_474 > V_462 -> V_336 )
V_456 -> V_473 [ V_34 ] . V_474 = V_462 -> V_336 ;
if ( V_456 -> V_473 [ V_34 ] . V_475 > V_462 -> V_299 )
V_456 -> V_473 [ V_34 ] . V_475 = V_462 -> V_299 ;
}
}
V_456 -> V_476 . V_477 = V_5 -> V_478 . V_477 ;
V_456 -> V_476 . V_479 = V_5 -> V_478 . V_479 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_459 . V_416 = V_5 -> V_480 . V_481 ;
V_459 . V_417 = V_5 -> V_480 . V_482 ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_483 ) ) {
V_462 = & ( V_5 -> V_57 . V_335 ) ;
V_463 = ( V_462 -> V_299 * 75 ) / 100 ;
for ( V_37 = V_43 -> V_168 -> V_37 - 1 ;
V_37 >= 0 ; V_37 -- ) {
if ( V_463 >=
V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ) {
V_463 =
V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ;
break;
}
}
if ( V_37 < 0 )
V_463 = V_43 -> V_168 -> V_38 [ 0 ] . V_161 ;
V_464 = V_462 -> V_336 ;
V_459 . V_416 = V_463 ;
V_459 . V_417 = V_464 ;
}
if ( V_459 . V_416 < V_5 -> V_484 . V_299 )
V_459 . V_416 = V_5 -> V_484 . V_299 ;
if ( V_459 . V_417 < V_5 -> V_484 . V_336 )
V_459 . V_417 = V_5 -> V_484 . V_336 ;
V_456 -> V_485 = V_5 -> V_484 . V_485 ;
if ( 0 != V_5 -> V_484 . V_486 ) {
F_2 ( ( V_5 -> V_484 . V_486 <=
V_5 -> V_182 . V_487 . V_416 ) ,
L_85 ,
V_5 -> V_484 . V_486 =
V_5 -> V_182 . V_487 . V_416 ) ;
if ( V_5 -> V_484 . V_486 >= V_5 -> V_484 . V_299 )
V_456 -> V_473 [ 1 ] . V_475 =
V_5 -> V_484 . V_486 ;
}
if ( 0 != V_5 -> V_484 . V_488 ) {
F_2 ( ( V_5 -> V_484 . V_488 <=
V_5 -> V_182 . V_487 . V_417 ) ,
L_86 ,
V_5 -> V_484 . V_488 =
V_5 -> V_182 . V_487 . V_417 ) ;
if ( V_5 -> V_484 . V_488 >= V_5 -> V_484 . V_336 )
V_456 -> V_473 [ 1 ] . V_474 =
V_5 -> V_484 . V_488 ;
}
V_461 = F_52 (
V_5 -> V_182 . V_183 ,
V_489 ) ;
V_460 = ( 1 < V_173 . V_490 ) ||
V_461 ;
V_299 = V_456 -> V_473 [ 0 ] . V_475 ;
V_336 = V_456 -> V_473 [ 0 ] . V_474 ;
if ( V_460 )
V_336 = V_456 -> V_473
[ V_456 -> V_469 - 1 ] . V_474 ;
if ( V_299 < V_459 . V_416 )
V_299 = ( V_459 . V_416 > V_462 -> V_299 ) ?
V_462 -> V_299 : V_459 . V_416 ;
if ( V_336 < V_459 . V_417 )
V_336 = ( V_459 . V_417 > V_462 -> V_336 ) ?
V_462 -> V_336 : V_459 . V_417 ;
V_456 -> V_473 [ 0 ] . V_475 = V_299 ;
V_456 -> V_473 [ 0 ] . V_474 = V_336 ;
V_456 -> V_473 [ 1 ] . V_475 =
( V_456 -> V_473 [ 1 ] . V_475 >=
V_456 -> V_473 [ 0 ] . V_475 ) ?
V_456 -> V_473 [ 1 ] . V_475 :
V_456 -> V_473 [ 0 ] . V_475 ;
if ( V_460 ) {
if ( V_336 < V_456 -> V_473 [ 1 ] . V_474 )
V_336 = V_456 -> V_473 [ 1 ] . V_474 ;
V_456 -> V_473 [ 0 ] . V_474 = V_336 ;
V_456 -> V_473 [ 1 ] . V_474 = V_336 ;
} else {
if ( V_456 -> V_473 [ 1 ] . V_474 <
V_456 -> V_473 [ 0 ] . V_474 )
V_456 -> V_473 [ 1 ] . V_474 =
V_456 -> V_473 [ 0 ] . V_474 ;
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_483 ) ) {
for ( V_34 = 0 ; V_34 < V_456 -> V_469 ; V_34 ++ ) {
V_456 -> V_473 [ V_34 ] . V_475 = V_463 ;
V_456 -> V_473 [ V_34 ] . V_474 = V_464 ;
V_456 -> V_473 [ V_34 ] . V_491 = V_24 -> V_132 . V_284 ;
V_456 -> V_473 [ V_34 ] . V_492 = V_24 -> V_132 . V_284 ;
}
}
return 0 ;
}
static int F_145 ( struct V_4 * V_5 , bool V_493 )
{
struct V_453 * V_494 ;
struct V_1 * V_456 ;
if ( V_5 == NULL )
return - V_120 ;
V_494 = V_5 -> V_454 ;
if ( V_494 == NULL )
return - V_120 ;
V_456 = F_1 ( & V_494 -> V_457 ) ;
if ( V_493 )
return V_456 -> V_473 [ 0 ] . V_474 ;
else
return V_456 -> V_473
[ V_456 -> V_469 - 1 ] . V_474 ;
}
static int F_146 ( struct V_4 * V_5 , bool V_493 )
{
struct V_453 * V_494 ;
struct V_1 * V_456 ;
if ( V_5 == NULL )
return - V_120 ;
V_494 = V_5 -> V_454 ;
if ( V_494 == NULL )
return - V_120 ;
V_456 = F_1 ( & V_494 -> V_457 ) ;
if ( V_493 )
return V_456 -> V_473 [ 0 ] . V_475 ;
else
return V_456 -> V_473
[ V_456 -> V_469 - 1 ] . V_475 ;
}
static int F_147 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_494 = (struct V_1 * ) V_3 ;
T_9 * V_495 ;
T_1 V_288 ;
T_5 V_496 , V_497 ;
int V_310 = F_148 ( V_498 , V_499 ) ;
V_495 = ( T_9 * ) F_149 (
V_5 -> V_6 , V_310 ,
& V_288 , & V_496 , & V_497 ) ;
if ( ! V_495 )
return 0 ;
V_24 -> V_500 . V_501 =
F_150 ( V_495 -> V_502 ) ;
V_24 -> V_500 . V_503 =
F_150 ( V_495 -> V_504 ) ;
V_24 -> V_500 . V_505 =
F_151 ( V_495 -> V_506 ) ;
V_24 -> V_500 . V_507 =
F_151 ( V_495 -> V_508 ) ;
V_24 -> V_500 . V_509 =
F_151 ( V_495 -> V_510 ) ;
V_24 -> V_500 . V_511 =
F_7 ( V_5 ) ;
V_24 -> V_500 . V_512 =
( T_1 ) F_10 ( V_5 ) ;
V_494 -> V_473 [ 0 ] . V_474 = V_24 -> V_500 . V_503 ;
V_494 -> V_473 [ 0 ] . V_475 = V_24 -> V_500 . V_501 ;
V_494 -> V_473 [ 0 ] . V_491 = V_24 -> V_500 . V_511 ;
V_494 -> V_473 [ 0 ] . V_492 = V_24 -> V_500 . V_512 ;
return 0 ;
}
static int F_152 ( struct V_4 * V_5 )
{
int V_45 ;
unsigned long V_437 = 0 ;
if ( V_5 -> V_53 == V_56 ) {
V_45 = F_153 ( V_5 , & V_437 ) ;
return V_45 ? 0 : V_437 ;
} else if ( V_5 -> V_53 == V_54 ) {
V_45 = F_154 ( V_5 ) ;
return V_45 ;
}
return 0 ;
}
static int F_155 ( struct V_4 * V_5 ,
void * V_513 , struct V_453 * V_514 ,
void * V_515 , T_2 V_516 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_1 =
(struct V_1 * ) ( & ( V_514 -> V_457 ) ) ;
struct V_517 * V_518 ;
T_10 * V_519 = ( T_10 * ) V_513 ;
T_11 * V_520 =
( T_11 * ) V_515 ;
T_12 * V_521 =
( T_12 * )
( ( ( unsigned long ) V_520 ) +
F_151 ( V_520 -> V_522 ) ) ;
T_13 * V_523 =
( T_13 * )
( ( ( unsigned long ) V_520 ) +
F_151 ( V_520 -> V_524 ) ) ;
V_514 -> V_467 . V_468 =
( F_151 ( V_519 -> V_525 ) &
V_526 ) >>
V_527 ;
V_514 -> V_467 . V_528 = V_516 ;
V_514 -> V_467 . V_529 = false ;
V_514 -> V_467 . V_530 = false ;
V_514 -> V_531 . V_532 =
( 0 != ( F_150 ( V_519 -> V_533 ) &
V_534 ) ) ;
V_514 -> V_535 . V_536 = 0 ;
V_514 -> V_537 . V_538 = false ;
V_514 -> V_537 . V_539 = false ;
V_514 -> V_537 . V_540 =
( 0 != ( F_150 ( V_519 -> V_533 ) &
V_541 ) ) ;
V_514 -> V_531 . V_542 = 0 ;
V_514 -> V_543 . V_544 = 0 ;
V_514 -> V_543 . V_545 = 0 ;
V_514 -> V_546 . V_286 = 0 ;
V_514 -> V_546 . V_284 = 0 ;
V_518 = & ( V_1 -> V_473
[ V_1 -> V_469 ++ ] ) ;
F_2 (
(smu7_power_state->performance_level_count < smum_get_mac_definition(hwmgr->smumgr, SMU_MAX_LEVELS_GRAPHICS)),
L_87 ,
return -EINVAL) ;
F_2 (
(smu7_power_state->performance_level_count <=
hwmgr->platform_descriptor.hardwareActivityPerformanceLevels),
L_88 ,
return -EINVAL) ;
V_518 -> V_474 = V_523 -> V_38
[ V_519 -> V_547 ] . V_548 ;
if ( V_521 -> V_549 == 0 )
V_518 -> V_475 = ( ( V_550 * ) V_521 ) -> V_38
[ V_519 -> V_551 ] . V_552 ;
else if ( V_521 -> V_549 == 1 )
V_518 -> V_475 = ( ( V_553 * ) V_521 ) -> V_38
[ V_519 -> V_551 ] . V_552 ;
V_518 -> V_491 = F_41 ( V_24 -> V_139 ,
V_519 -> V_554 ) ;
V_518 -> V_492 = F_42 ( V_24 -> V_141 ,
V_519 -> V_555 ) ;
V_518 = & ( V_1 -> V_473
[ V_1 -> V_469 ++ ] ) ;
V_518 -> V_474 = V_523 -> V_38
[ V_519 -> V_556 ] . V_548 ;
if ( V_521 -> V_549 == 0 )
V_518 -> V_475 = ( ( V_550 * ) V_521 ) -> V_38
[ V_519 -> V_557 ] . V_552 ;
else if ( V_521 -> V_549 == 1 )
V_518 -> V_475 = ( ( V_553 * ) V_521 ) -> V_38
[ V_519 -> V_557 ] . V_552 ;
V_518 -> V_491 = F_41 ( V_24 -> V_139 ,
V_519 -> V_558 ) ;
V_518 -> V_492 = F_42 ( V_24 -> V_141 ,
V_519 -> V_555 ) ;
return 0 ;
}
static int F_156 ( struct V_4 * V_5 ,
unsigned long V_559 , struct V_453 * V_513 )
{
int V_45 ;
struct V_1 * V_494 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_167 =
V_43 -> V_55 ;
V_513 -> V_457 . V_560 = V_561 ;
V_494 = (struct V_1 * ) ( & V_513 -> V_457 ) ;
V_45 = F_157 ( V_5 , V_559 , V_513 ,
F_155 ) ;
if ( V_167 != NULL && V_167 -> V_37 == 1 ) {
if ( V_167 -> V_38 [ 0 ] . V_161 !=
V_24 -> V_500 . V_503 )
F_63 ( L_89
L_90 ) ;
if ( V_167 -> V_38 [ 0 ] . V_337 !=
V_24 -> V_500 . V_509 )
F_63 ( L_91
L_92 ) ;
}
if ( ! V_513 -> V_531 . V_532 )
V_494 -> V_562 = true ;
if ( V_513 -> V_467 . V_528 & V_563 )
V_24 -> V_564 = V_494 -> V_473 [ 0 ] . V_491 ;
V_494 -> V_565 . V_566 = V_513 -> V_543 . V_544 ;
V_494 -> V_565 . V_567 = V_513 -> V_543 . V_545 ;
if ( ! V_45 ) {
T_2 V_34 ;
switch ( V_513 -> V_467 . V_468 ) {
case V_568 :
V_24 -> V_129 = true ;
for ( V_34 = 0 ; V_34 < V_494 -> V_469 ; V_34 ++ ) {
if ( V_24 -> V_132 . V_284 <
V_494 -> V_473 [ V_34 ] . V_491 )
V_24 -> V_132 . V_284 =
V_494 -> V_473 [ V_34 ] . V_491 ;
if ( V_24 -> V_132 . V_286 >
V_494 -> V_473 [ V_34 ] . V_491 )
V_24 -> V_132 . V_286 =
V_494 -> V_473 [ V_34 ] . V_491 ;
if ( V_24 -> V_134 . V_284 <
V_494 -> V_473 [ V_34 ] . V_492 )
V_24 -> V_134 . V_284 =
V_494 -> V_473 [ V_34 ] . V_492 ;
if ( V_24 -> V_134 . V_286 >
V_494 -> V_473 [ V_34 ] . V_492 )
V_24 -> V_134 . V_286 =
V_494 -> V_473 [ V_34 ] . V_492 ;
}
break;
case V_466 :
V_24 -> V_130 = true ;
for ( V_34 = 0 ; V_34 < V_494 -> V_469 ; V_34 ++ ) {
if ( V_24 -> V_131 . V_284 <
V_494 -> V_473 [ V_34 ] . V_491 )
V_24 -> V_131 . V_284 =
V_494 -> V_473 [ V_34 ] . V_491 ;
if ( V_24 -> V_131 . V_286 >
V_494 -> V_473 [ V_34 ] . V_491 )
V_24 -> V_131 . V_286 =
V_494 -> V_473 [ V_34 ] . V_491 ;
if ( V_24 -> V_133 . V_284 <
V_494 -> V_473 [ V_34 ] . V_492 )
V_24 -> V_133 . V_284 =
V_494 -> V_473 [ V_34 ] . V_492 ;
if ( V_24 -> V_133 . V_286 >
V_494 -> V_473 [ V_34 ] . V_492 )
V_24 -> V_133 . V_286 =
V_494 -> V_473 [ V_34 ] . V_492 ;
}
break;
default:
break;
}
}
return 0 ;
}
static int F_158 ( struct V_4 * V_5 ,
struct V_2 * V_514 ,
unsigned int V_310 , const void * V_569 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_494 = F_1 ( V_514 ) ;
const T_14 * V_570 = V_569 ;
struct V_517 * V_518 ;
T_2 V_475 , V_474 ;
T_1 V_571 ;
V_475 = V_570 -> V_572 << 16 | V_570 -> V_573 ;
V_474 = V_570 -> V_574 << 16 | V_570 -> V_575 ;
if ( ! ( V_24 -> V_576 & V_577 ) && V_474 > V_24 -> V_578 )
V_24 -> V_578 = V_474 ;
F_2 (
(ps->performance_level_count < smum_get_mac_definition(hwmgr->smumgr, SMU_MAX_LEVELS_GRAPHICS)),
L_87 ,
return -EINVAL) ;
F_2 (
(ps->performance_level_count <
hwmgr->platform_descriptor.hardwareActivityPerformanceLevels),
L_93 ,
return 0 ) ;
V_518 = & ( V_494 -> V_473
[ V_494 -> V_469 ++ ] ) ;
V_518 -> V_474 = V_474 ;
V_518 -> V_475 = V_475 ;
V_571 = V_570 -> V_579 ;
V_518 -> V_491 = F_41 ( V_24 -> V_139 , V_571 ) ;
V_518 -> V_492 = F_42 ( V_24 -> V_141 , V_570 -> V_580 ) ;
return 0 ;
}
static int F_159 ( struct V_4 * V_5 ,
unsigned long V_559 , struct V_453 * V_513 )
{
int V_45 ;
struct V_1 * V_494 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_32 * V_167 =
V_5 -> V_57 . V_62 ;
memset ( & V_513 -> V_457 , 0x00 , sizeof( struct V_2 ) ) ;
V_513 -> V_457 . V_560 = V_561 ;
V_494 = (struct V_1 * ) ( & V_513 -> V_457 ) ;
V_45 = F_160 ( V_5 , V_559 , V_513 ,
F_158 ) ;
if ( V_167 != NULL && V_167 -> V_37 == 1 ) {
if ( V_167 -> V_38 [ 0 ] . V_161 !=
V_24 -> V_500 . V_503 )
F_63 ( L_89
L_90 ) ;
if ( V_167 -> V_38 [ 0 ] . V_40 !=
V_24 -> V_500 . V_509 )
F_63 ( L_91
L_92 ) ;
}
if ( ! V_513 -> V_531 . V_532 )
V_494 -> V_562 = true ;
if ( V_513 -> V_467 . V_528 & V_563 )
V_24 -> V_564 = V_494 -> V_473 [ 0 ] . V_491 ;
V_494 -> V_565 . V_566 = V_513 -> V_543 . V_544 ;
V_494 -> V_565 . V_567 = V_513 -> V_543 . V_545 ;
if ( ! V_45 ) {
T_2 V_34 ;
switch ( V_513 -> V_467 . V_468 ) {
case V_568 :
V_24 -> V_129 = true ;
for ( V_34 = 0 ; V_34 < V_494 -> V_469 ; V_34 ++ ) {
if ( V_24 -> V_132 . V_284 <
V_494 -> V_473 [ V_34 ] . V_491 )
V_24 -> V_132 . V_284 =
V_494 -> V_473 [ V_34 ] . V_491 ;
if ( V_24 -> V_132 . V_286 >
V_494 -> V_473 [ V_34 ] . V_491 )
V_24 -> V_132 . V_286 =
V_494 -> V_473 [ V_34 ] . V_491 ;
if ( V_24 -> V_134 . V_284 <
V_494 -> V_473 [ V_34 ] . V_492 )
V_24 -> V_134 . V_284 =
V_494 -> V_473 [ V_34 ] . V_492 ;
if ( V_24 -> V_134 . V_286 >
V_494 -> V_473 [ V_34 ] . V_492 )
V_24 -> V_134 . V_286 =
V_494 -> V_473 [ V_34 ] . V_492 ;
}
break;
case V_466 :
V_24 -> V_130 = true ;
for ( V_34 = 0 ; V_34 < V_494 -> V_469 ; V_34 ++ ) {
if ( V_24 -> V_131 . V_284 <
V_494 -> V_473 [ V_34 ] . V_491 )
V_24 -> V_131 . V_284 =
V_494 -> V_473 [ V_34 ] . V_491 ;
if ( V_24 -> V_131 . V_286 >
V_494 -> V_473 [ V_34 ] . V_491 )
V_24 -> V_131 . V_286 =
V_494 -> V_473 [ V_34 ] . V_491 ;
if ( V_24 -> V_133 . V_284 <
V_494 -> V_473 [ V_34 ] . V_492 )
V_24 -> V_133 . V_284 =
V_494 -> V_473 [ V_34 ] . V_492 ;
if ( V_24 -> V_133 . V_286 >
V_494 -> V_473 [ V_34 ] . V_492 )
V_24 -> V_133 . V_286 =
V_494 -> V_473 [ V_34 ] . V_492 ;
}
break;
default:
break;
}
}
return 0 ;
}
static int F_161 ( struct V_4 * V_5 ,
unsigned long V_559 , struct V_453 * V_513 )
{
if ( V_5 -> V_53 == V_56 )
return F_159 ( V_5 , V_559 , V_513 ) ;
else if ( V_5 -> V_53 == V_54 )
return F_156 ( V_5 , V_559 , V_513 ) ;
return 0 ;
}
static int F_162 ( struct V_4 * V_5 , int V_581 , T_8 * V_39 )
{
T_2 V_299 , V_336 , V_582 ;
T_2 V_583 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
switch ( V_581 ) {
case V_584 :
F_14 ( V_5 -> V_21 , V_585 ) ;
V_299 = F_6 ( V_5 -> V_6 , V_586 ) ;
* V_39 = V_299 ;
return 0 ;
case V_587 :
F_14 ( V_5 -> V_21 , V_588 ) ;
V_336 = F_6 ( V_5 -> V_6 , V_586 ) ;
* V_39 = V_336 ;
return 0 ;
case V_589 :
V_583 = V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_590 ) ;
V_582 = F_8 ( V_5 -> V_6 , V_28 , V_583 ) ;
V_582 += 0x80 ;
V_582 >>= 8 ;
* V_39 = V_582 > 100 ? 100 : V_582 ;
return 0 ;
case V_591 :
* V_39 = F_163 ( V_5 ) ;
return 0 ;
case V_592 :
* V_39 = V_24 -> V_593 ? 0 : 1 ;
return 0 ;
case V_594 :
* V_39 = V_24 -> V_595 ? 0 : 1 ;
return 0 ;
default:
return - V_120 ;
}
}
static int F_164 ( struct V_4 * V_5 , const void * V_596 )
{
const struct V_597 * V_598 =
( const struct V_597 * ) V_596 ;
const struct V_1 * V_456 =
F_3 ( V_598 -> V_599 ) ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_600 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
T_2 V_299 = V_456 -> V_473
[ V_456 -> V_469 - 1 ] . V_475 ;
struct V_600 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
T_2 V_336 = V_456 -> V_473
[ V_456 -> V_469 - 1 ] . V_474 ;
struct V_458 V_601 = { 0 } ;
T_2 V_34 ;
struct V_172 V_173 = { 0 } ;
V_24 -> V_602 = 0 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ ) {
if ( V_299 == V_147 -> V_160 [ V_34 ] . V_39 )
break;
}
if ( V_34 >= V_147 -> V_37 )
V_24 -> V_602 |= V_603 ;
else {
if ( V_24 -> V_604 . V_605 != V_601 . V_606 &&
( V_601 . V_606 >= V_607 ||
V_24 -> V_604 . V_605 >= V_607 ) )
V_24 -> V_602 |= V_608 ;
}
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ ) {
if ( V_336 == V_149 -> V_160 [ V_34 ] . V_39 )
break;
}
if ( V_34 >= V_149 -> V_37 )
V_24 -> V_602 |= V_609 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
if ( V_24 -> V_604 . V_610 != V_173 . V_490 )
V_24 -> V_602 |= V_611 ;
return 0 ;
}
static T_1 F_165 ( struct V_4 * V_5 ,
const struct V_1 * V_456 )
{
T_2 V_34 ;
T_2 V_299 , V_612 = 0 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_170 * V_136 = & V_24 -> V_136 ;
for ( V_34 = 0 ; V_34 < V_456 -> V_469 ; V_34 ++ ) {
V_299 = V_456 -> V_473 [ V_34 ] . V_475 ;
if ( V_612 < V_299 )
V_612 = V_299 ;
}
for ( V_34 = 0 ; V_34 < V_136 -> V_147 . V_37 ; V_34 ++ ) {
if ( V_136 -> V_147 . V_160 [ V_34 ] . V_39 == V_612 )
return ( T_1 ) ( ( V_34 >= V_136 -> V_137 . V_37 ) ?
V_136 -> V_137 . V_160
[ V_136 -> V_137 . V_37 - 1 ] . V_39 :
V_136 -> V_137 . V_160 [ V_34 ] . V_39 ) ;
}
return 0 ;
}
static int F_166 (
struct V_4 * V_5 , const void * V_596 )
{
const struct V_597 * V_598 =
( const struct V_597 * ) V_596 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_613 =
F_3 ( V_598 -> V_599 ) ;
const struct V_1 * V_614 =
F_3 ( V_598 -> V_615 ) ;
T_1 V_616 = F_165 ( V_5 , V_613 ) ;
T_1 V_617 ;
if ( V_24 -> V_264 == V_265 )
V_617 = F_165 ( V_5 , V_614 ) ;
else
V_617 = V_24 -> V_264 ;
V_24 -> V_264 = V_265 ;
V_24 -> V_618 = false ;
if ( V_616 > V_617 ) {
switch ( V_616 ) {
case V_287 :
if ( 0 == F_167 ( V_5 -> V_6 , V_619 , false ) )
break;
V_24 -> V_264 = V_620 ;
if ( V_617 == V_620 )
break;
case V_620 :
if ( 0 == F_167 ( V_5 -> V_6 , V_621 , false ) )
break;
default:
V_24 -> V_264 = F_7 ( V_5 ) ;
break;
}
} else {
if ( V_616 < V_617 )
V_24 -> V_618 = true ;
}
return 0 ;
}
static int F_168 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( 0 == V_24 -> V_602 )
return 0 ;
if ( ( 0 == V_24 -> V_199 ) &&
( V_24 -> V_602 &
( V_603 + V_608 ) ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_94 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_FreezeLevel),
L_95 ,
return -EINVAL) ;
}
if ( ( 0 == V_24 -> V_200 ) &&
( V_24 -> V_602 &
V_609 ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_96 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_MCLKDPM_FreezeLevel),
L_97 ,
return -EINVAL) ;
}
return 0 ;
}
static int F_169 (
struct V_4 * V_5 , const void * V_596 )
{
int V_45 = 0 ;
const struct V_597 * V_598 =
( const struct V_597 * ) V_596 ;
const struct V_1 * V_456 =
F_3 ( V_598 -> V_599 ) ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_299 = V_456 -> V_473
[ V_456 -> V_469 - 1 ] . V_475 ;
T_2 V_336 = V_456 -> V_473
[ V_456 -> V_469 - 1 ] . V_474 ;
struct V_170 * V_136 = & V_24 -> V_136 ;
struct V_170 * V_169 = & V_24 -> V_169 ;
T_2 V_622 , V_623 ;
T_2 V_34 ;
if ( 0 == V_24 -> V_602 )
return 0 ;
if ( V_24 -> V_602 & V_603 ) {
V_136 -> V_147 . V_160
[ V_136 -> V_147 . V_37 - 1 ] . V_39 = V_299 ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_624 ) ||
F_52 ( V_5 -> V_182 . V_183 , V_625 ) ) {
F_2 (
(golden_dpm_table->sclk_table.dpm_levels
[golden_dpm_table->sclk_table.count - 1].value != 0),
L_98 ,
return -EINVAL) ;
V_622 = V_136 -> V_147 . V_37 < 2 ? 0 : V_136 -> V_147 . V_37 - 2 ;
for ( V_34 = V_622 ; V_34 > 1 ; V_34 -- ) {
if ( V_299 > V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ) {
V_623 =
( ( V_299
- V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39
) * 100 )
/ V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ;
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 +
( V_169 -> V_147 . V_160 [ V_34 ] . V_39 *
V_623 ) / 100 ;
} else if ( V_169 -> V_147 . V_160 [ V_136 -> V_147 . V_37 - 1 ] . V_39 > V_299 ) {
V_623 =
( ( V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39
- V_299 ) * 100 )
/ V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ;
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 -
( V_169 -> V_147 . V_160 [ V_34 ] . V_39 *
V_623 ) / 100 ;
} else
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 ;
}
}
}
if ( V_24 -> V_602 & V_609 ) {
V_136 -> V_149 . V_160
[ V_136 -> V_149 . V_37 - 1 ] . V_39 = V_336 ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_624 ) ||
F_52 ( V_5 -> V_182 . V_183 , V_625 ) ) {
F_2 (
(golden_dpm_table->mclk_table.dpm_levels
[golden_dpm_table->mclk_table.count-1].value != 0),
L_98 ,
return -EINVAL) ;
V_622 = V_136 -> V_149 . V_37 < 2 ? 0 : V_136 -> V_149 . V_37 - 2 ;
for ( V_34 = V_622 ; V_34 > 1 ; V_34 -- ) {
if ( V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 < V_336 ) {
V_623 = ( ( V_336 -
V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ) * 100 )
/ V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 +
( V_169 -> V_149 . V_160 [ V_34 ] . V_39 *
V_623 ) / 100 ;
} else if ( V_169 -> V_149 . V_160 [ V_136 -> V_149 . V_37 - 1 ] . V_39 > V_336 ) {
V_623 = (
( V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 - V_336 )
* 100 )
/ V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 -
( V_169 -> V_149 . V_160 [ V_34 ] . V_39 *
V_623 ) / 100 ;
} else
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 ;
}
}
}
if ( V_24 -> V_602 &
( V_603 + V_608 ) ) {
V_45 = F_170 ( V_5 ) ;
F_2 ((0 == result),
L_99 ,
return result) ;
}
if ( V_24 -> V_602 &
( V_609 + V_611 ) ) {
V_45 = F_171 ( V_5 ) ;
F_2 ((0 == result),
L_100 ,
return result) ;
}
return V_45 ;
}
static int F_172 ( struct V_4 * V_5 ,
struct V_600 * V_136 ,
T_2 V_626 , T_2 V_627 )
{
T_2 V_34 ;
for ( V_34 = 0 ; V_34 < V_136 -> V_37 ; V_34 ++ ) {
if ( ( V_136 -> V_160 [ V_34 ] . V_39 < V_626 )
|| ( V_136 -> V_160 [ V_34 ] . V_39 > V_627 ) )
V_136 -> V_160 [ V_34 ] . V_162 = false ;
else
V_136 -> V_160 [ V_34 ] . V_162 = true ;
}
return 0 ;
}
static int F_173 ( struct V_4 * V_5 ,
const struct V_1 * V_456 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_628 ;
F_2 ((smu7_ps->performance_level_count >= 1),
L_101 ,
return -EINVAL) ;
V_628 = ( 1 == V_456 -> V_469 ) ? 0 : 1 ;
F_172 ( V_5 ,
& ( V_24 -> V_136 . V_147 ) ,
V_456 -> V_473 [ 0 ] . V_475 ,
V_456 -> V_473 [ V_628 ] . V_475 ) ;
F_172 ( V_5 ,
& ( V_24 -> V_136 . V_149 ) ,
V_456 -> V_473 [ 0 ] . V_474 ,
V_456 -> V_473 [ V_628 ] . V_474 ) ;
return 0 ;
}
static int F_174 (
struct V_4 * V_5 , const void * V_596 )
{
int V_45 ;
const struct V_597 * V_598 =
( const struct V_597 * ) V_596 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_456 =
F_3 ( V_598 -> V_599 ) ;
V_45 = F_173 ( V_5 , V_456 ) ;
if ( V_45 )
return V_45 ;
V_24 -> V_419 . V_422 =
F_175 ( & V_24 -> V_136 . V_147 ) ;
V_24 -> V_419 . V_424 =
F_175 ( & V_24 -> V_136 . V_149 ) ;
V_24 -> V_419 . V_420 =
F_175 ( & V_24 -> V_136 . V_137 ) ;
return 0 ;
}
static int F_176 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( 0 == V_24 -> V_602 )
return 0 ;
if ( ( 0 == V_24 -> V_199 ) &&
( V_24 -> V_602 &
( V_603 + V_608 ) ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_102 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_UnfreezeLevel),
L_103 ,
return -EINVAL) ;
}
if ( ( 0 == V_24 -> V_200 ) &&
( V_24 -> V_602 & V_609 ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_104 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_UnfreezeLevel),
L_105 ,
return -EINVAL) ;
}
V_24 -> V_602 = 0 ;
return 0 ;
}
static int F_177 (
struct V_4 * V_5 , const void * V_596 )
{
const struct V_597 * V_598 =
( const struct V_597 * ) V_596 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_456 =
F_3 ( V_598 -> V_599 ) ;
T_1 V_616 = F_165 ( V_5 , V_456 ) ;
T_5 V_629 ;
if ( V_24 -> V_618 ) {
if ( V_616 == V_287 )
V_629 = V_619 ;
else if ( V_616 == V_620 )
V_629 = V_621 ;
else
V_629 = V_630 ;
if ( V_629 == V_630 &&
F_7 ( V_5 ) > 0 )
return 0 ;
if ( F_167 ( V_5 -> V_6 , V_629 , false ) ) {
if ( V_620 == V_616 )
F_95 ( L_106 ) ;
else
F_95 ( L_107 ) ;
}
}
return 0 ;
}
static int F_178 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_5 -> V_19 & V_631 )
F_131 ( V_5 -> V_21 ,
( V_236 ) V_632 , V_24 -> V_633 ) ;
return ( F_14 ( V_5 -> V_21 , ( V_236 ) V_634 ) == 0 ) ? 0 : - V_120 ;
}
static int F_179 ( struct V_4 * V_5 , const void * V_596 )
{
int V_233 , V_45 = 0 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_233 = F_164 ( V_5 , V_596 ) ;
F_2 ( ( 0 == V_233 ) ,
L_108 ,
V_45 = V_233 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_635 ) ) {
V_233 =
F_166 ( V_5 , V_596 ) ;
F_2 ( ( 0 == V_233 ) ,
L_109 ,
V_45 = V_233 ) ;
}
V_233 = F_168 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_110 , V_45 = V_233 ) ;
V_233 = F_169 ( V_5 , V_596 ) ;
F_2 ( ( 0 == V_233 ) ,
L_111 ,
V_45 = V_233 ) ;
V_233 = F_174 ( V_5 , V_596 ) ;
F_2 ( ( 0 == V_233 ) ,
L_112 ,
V_45 = V_233 ) ;
V_233 = F_180 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_113 ,
V_45 = V_233 ) ;
V_233 = F_178 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_114 ,
V_45 = V_233 ) ;
V_233 = F_176 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_115 ,
V_45 = V_233 ) ;
V_233 = F_132 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_116 ,
V_45 = V_233 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_635 ) ) {
V_233 =
F_177 ( V_5 , V_596 ) ;
F_2 ( ( 0 == V_233 ) ,
L_117 ,
V_45 = V_233 ) ;
}
V_24 -> V_636 = false ;
return V_45 ;
}
static int F_181 ( struct V_4 * V_5 , T_1 V_637 )
{
V_5 -> V_357 .
V_358 . V_371 = V_637 ;
if ( F_182 ( V_5 ) )
return 0 ;
return F_131 ( V_5 -> V_21 ,
V_638 , V_637 ) ;
}
static int
F_183 ( struct V_4 * V_5 , bool V_639 )
{
V_236 V_640 = V_639 ? ( V_236 ) V_634 : ( V_236 ) V_237 ;
return ( F_14 ( V_5 -> V_21 , V_640 ) == 0 ) ? 0 : - 1 ;
}
static int
F_184 ( struct V_4 * V_5 )
{
T_2 V_641 = 0 ;
struct V_172 V_173 = { 0 } ;
V_173 . V_175 = NULL ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_641 = V_173 . V_490 ;
if ( V_641 > 1 && V_5 -> V_480 . V_642 != true )
F_183 ( V_5 , false ) ;
return 0 ;
}
static int F_185 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_641 = 0 ;
T_2 V_79 = F_8 ( V_5 -> V_6 , V_28 , V_80 ) ;
T_2 V_643 ;
T_2 V_644 ;
T_2 V_645 ;
T_2 V_179 ;
T_2 V_646 = 0 ;
struct V_172 V_173 = { 0 } ;
struct V_174 V_175 ;
V_173 . V_175 = & V_175 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_641 = V_173 . V_490 ;
V_79 = F_28 ( V_79 , V_81 , V_82 , ( V_641 > 0 ) ? V_647 : V_83 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_80 , V_79 ) ;
V_179 = V_175 . V_179 ;
V_646 = V_175 . V_646 ;
if ( 0 == V_646 )
V_646 = 60 ;
V_645 = 1000000 / V_646 ;
V_644 = V_645 - 200 - V_175 . V_648 ;
V_24 -> V_633 = V_645 * 2 / 100 ;
V_643 = V_644 * ( V_179 / 100 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_649 , V_643 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_650 ) , 0x64 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_651 ) ,
( V_645 - V_644 ) ) ;
return 0 ;
}
static int F_186 ( struct V_4 * V_5 )
{
return F_185 ( V_5 ) ;
}
static int F_187 ( struct V_4 * V_5 , T_1 V_652 )
{
V_5 -> V_357 .
V_358 . V_372 = V_652 ;
if ( F_182 ( V_5 ) )
return 0 ;
return F_131 ( V_5 -> V_21 ,
V_653 , V_652 ) ;
}
static int F_188 ( struct V_4 * V_5 ,
const void * V_654 )
{
return 0 ;
}
static bool
F_189 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
bool V_655 = false ;
struct V_172 V_173 = { 0 , 0 , NULL } ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
if ( V_24 -> V_604 . V_610 != V_173 . V_490 )
V_655 = true ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_190 ) ) {
if ( V_24 -> V_604 . V_605 != V_5 -> V_480 . V_656 &&
( V_24 -> V_604 . V_605 >= V_607 ||
V_5 -> V_480 . V_656 >= V_607 ) )
V_655 = true ;
}
return V_655 ;
}
static inline bool F_190 ( const struct V_517 * V_657 ,
const struct V_517 * V_658 )
{
return ( ( V_657 -> V_474 == V_658 -> V_474 ) &&
( V_657 -> V_475 == V_658 -> V_475 ) &&
( V_657 -> V_491 == V_658 -> V_491 ) &&
( V_657 -> V_492 == V_658 -> V_492 ) ) ;
}
static int F_191 ( struct V_4 * V_5 ,
const struct V_2 * V_659 ,
const struct V_2 * V_660 , bool * V_661 )
{
const struct V_1 * V_662 ;
const struct V_1 * V_663 ;
int V_34 ;
if ( V_659 == NULL || V_660 == NULL || V_661 == NULL )
return - V_120 ;
V_662 = F_3 ( V_659 ) ;
V_663 = F_3 ( V_660 ) ;
if ( V_662 -> V_469 != V_663 -> V_469 ) {
* V_661 = false ;
return 0 ;
}
for ( V_34 = 0 ; V_34 < V_662 -> V_469 ; V_34 ++ ) {
if ( ! F_190 ( & ( V_662 -> V_473 [ V_34 ] ) , & ( V_663 -> V_473 [ V_34 ] ) ) ) {
* V_661 = false ;
return 0 ;
}
}
* V_661 = ( ( V_662 -> V_565 . V_566 == V_663 -> V_565 . V_566 ) && ( V_662 -> V_565 . V_567 == V_663 -> V_565 . V_567 ) ) ;
* V_661 &= ( ( V_662 -> V_476 . V_477 == V_663 -> V_476 . V_477 ) && ( V_662 -> V_476 . V_479 == V_663 -> V_476 . V_479 ) ) ;
* V_661 &= ( V_662 -> V_485 == V_663 -> V_485 ) ;
return 0 ;
}
static int F_192 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_664 ;
T_2 V_46 ;
F_4 ( V_5 ) ;
V_664 = V_5 -> V_8 . V_9 & 0xf ;
V_24 -> V_665 = false ;
F_5 ( V_5 -> V_6 , V_7 ,
V_666 ) ;
V_46 = F_6 ( V_5 -> V_6 , V_10 ) ;
if ( V_46 & ( 1 << 23 ) ) {
V_24 -> V_667 = V_668 ;
V_24 -> V_669 = V_670 ;
} else {
V_24 -> V_667 = 330 ;
V_24 -> V_669 = 330 ;
}
return 0 ;
}
static int F_193 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_671 . V_672 =
F_8 ( V_5 -> V_6 , V_28 , V_673 ) ;
V_24 -> V_671 . V_674 =
F_8 ( V_5 -> V_6 , V_28 , V_675 ) ;
V_24 -> V_671 . V_676 =
F_8 ( V_5 -> V_6 , V_28 , V_677 ) ;
V_24 -> V_671 . V_678 =
F_8 ( V_5 -> V_6 , V_28 , V_679 ) ;
V_24 -> V_671 . V_680 =
F_8 ( V_5 -> V_6 , V_28 , V_681 ) ;
V_24 -> V_671 . V_682 =
F_8 ( V_5 -> V_6 , V_28 , V_683 ) ;
V_24 -> V_671 . V_684 =
F_6 ( V_5 -> V_6 , V_685 ) ;
V_24 -> V_671 . V_686 =
F_6 ( V_5 -> V_6 , V_687 ) ;
V_24 -> V_671 . V_688 =
F_6 ( V_5 -> V_6 , V_689 ) ;
V_24 -> V_671 . V_690 =
F_6 ( V_5 -> V_6 , V_691 ) ;
V_24 -> V_671 . V_692 =
F_6 ( V_5 -> V_6 , V_693 ) ;
V_24 -> V_671 . V_694 =
F_6 ( V_5 -> V_6 , V_695 ) ;
V_24 -> V_671 . V_696 =
F_6 ( V_5 -> V_6 , V_697 ) ;
V_24 -> V_671 . V_698 =
F_6 ( V_5 -> V_6 , V_699 ) ;
V_24 -> V_671 . V_700 =
F_6 ( V_5 -> V_6 , V_701 ) ;
return 0 ;
}
static int F_194 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_702 ;
V_702 = F_6 ( V_5 -> V_6 , V_703 ) ;
V_24 -> V_704 = ( V_705 ==
( ( V_702 & V_706 ) >>
V_707 ) ) ;
return 0 ;
}
static int F_195 ( struct V_4 * V_5 )
{
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_708 , 1 ) ;
return 0 ;
}
static int F_196 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_593 = false ;
V_24 -> V_595 = false ;
V_24 -> V_709 = false ;
return 0 ;
}
static int F_197 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_710 = 0 ;
return 0 ;
}
static int F_198 ( struct V_4 * V_5 )
{
int V_233 , V_45 = 0 ;
F_192 ( V_5 ) ;
V_233 = F_193 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_118 , V_45 = V_233 ) ;
V_233 = F_194 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_119 , V_45 = V_233 ) ;
V_233 = F_195 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_120 , V_45 = V_233 ) ;
V_233 = F_196 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_121 , V_45 = V_233 ) ;
V_233 = F_4 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_122 , V_45 = V_233 ) ;
V_233 = F_197 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_123 , V_45 = V_233 ) ;
return V_45 ;
}
static int F_140 ( struct V_4 * V_5 ,
enum V_711 type , T_2 V_712 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_5 -> V_440 & ( V_448 |
V_447 |
V_446 ) )
return - V_120 ;
switch ( type ) {
case V_449 :
if ( ! V_24 -> V_199 )
F_131 ( V_5 -> V_21 ,
V_423 ,
V_24 -> V_419 . V_422 & V_712 ) ;
break;
case V_450 :
if ( ! V_24 -> V_200 )
F_131 ( V_5 -> V_21 ,
V_425 ,
V_24 -> V_419 . V_424 & V_712 ) ;
break;
case V_451 :
{
T_2 V_46 = V_712 & V_24 -> V_419 . V_420 ;
T_2 V_418 = 0 ;
while ( V_46 >>= 1 )
V_418 ++ ;
if ( ! V_24 -> V_212 )
F_131 ( V_5 -> V_21 ,
V_421 ,
V_418 ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_199 ( struct V_4 * V_5 ,
enum V_711 type , char * V_713 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_600 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
struct V_600 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
struct V_600 * V_127 = & ( V_24 -> V_136 . V_137 ) ;
int V_34 , V_714 , V_288 = 0 ;
T_2 clock , V_715 ;
switch ( type ) {
case V_449 :
F_14 ( V_5 -> V_21 , V_585 ) ;
clock = F_6 ( V_5 -> V_6 , V_586 ) ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ ) {
if ( clock > V_147 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_714 = V_34 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ )
V_288 += sprintf ( V_713 + V_288 , L_124 ,
V_34 , V_147 -> V_160 [ V_34 ] . V_39 / 100 ,
( V_34 == V_714 ) ? L_125 : L_126 ) ;
break;
case V_450 :
F_14 ( V_5 -> V_21 , V_588 ) ;
clock = F_6 ( V_5 -> V_6 , V_586 ) ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ ) {
if ( clock > V_149 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_714 = V_34 ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ )
V_288 += sprintf ( V_713 + V_288 , L_124 ,
V_34 , V_149 -> V_160 [ V_34 ] . V_39 / 100 ,
( V_34 == V_714 ) ? L_125 : L_126 ) ;
break;
case V_451 :
V_715 = F_7 ( V_5 ) ;
for ( V_34 = 0 ; V_34 < V_127 -> V_37 ; V_34 ++ ) {
if ( V_715 != V_127 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_714 = V_34 ;
for ( V_34 = 0 ; V_34 < V_127 -> V_37 ; V_34 ++ )
V_288 += sprintf ( V_713 + V_288 , L_127 , V_34 ,
( V_127 -> V_160 [ V_34 ] . V_39 == 0 ) ? L_128 :
( V_127 -> V_160 [ V_34 ] . V_39 == 1 ) ? L_129 :
( V_127 -> V_160 [ V_34 ] . V_39 == 2 ) ? L_130 : L_126 ,
( V_34 == V_714 ) ? L_125 : L_126 ) ;
break;
default:
break;
}
return V_288 ;
}
static int F_200 ( struct V_4 * V_5 , T_2 V_716 )
{
if ( V_716 ) {
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_717 ) )
F_201 ( V_5 ) ;
F_202 ( V_5 , V_716 ) ;
} else
F_142 ( V_5 ) ;
return 0 ;
}
static int F_203 ( struct V_4 * V_5 )
{
if ( V_5 -> V_718 )
return V_5 -> V_719 ;
else
return F_49 ( V_5 -> V_6 , V_28 ,
V_720 , V_721 ) ;
}
static int F_204 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_600 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
struct V_600 * V_722 =
& ( V_24 -> V_169 . V_147 ) ;
int V_39 ;
V_39 = ( V_147 -> V_160 [ V_147 -> V_37 - 1 ] . V_39 -
V_722 -> V_160 [ V_722 -> V_37 - 1 ] . V_39 ) *
100 /
V_722 -> V_160 [ V_722 -> V_37 - 1 ] . V_39 ;
return V_39 ;
}
static int F_205 ( struct V_4 * V_5 , T_2 V_39 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_600 * V_722 =
& ( V_24 -> V_169 . V_147 ) ;
struct V_453 * V_494 ;
struct V_1 * V_456 ;
if ( V_39 > 20 )
V_39 = 20 ;
V_494 = V_5 -> V_454 ;
if ( V_494 == NULL )
return - V_120 ;
V_456 = F_1 ( & V_494 -> V_457 ) ;
V_456 -> V_473 [ V_456 -> V_469 - 1 ] . V_475 =
V_722 -> V_160 [ V_722 -> V_37 - 1 ] . V_39 *
V_39 / 100 +
V_722 -> V_160 [ V_722 -> V_37 - 1 ] . V_39 ;
return 0 ;
}
static int F_206 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_600 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
struct V_600 * V_723 =
& ( V_24 -> V_169 . V_149 ) ;
int V_39 ;
V_39 = ( V_149 -> V_160 [ V_149 -> V_37 - 1 ] . V_39 -
V_723 -> V_160 [ V_723 -> V_37 - 1 ] . V_39 ) *
100 /
V_723 -> V_160 [ V_723 -> V_37 - 1 ] . V_39 ;
return V_39 ;
}
static int F_207 ( struct V_4 * V_5 , T_2 V_39 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_600 * V_723 =
& ( V_24 -> V_169 . V_149 ) ;
struct V_453 * V_494 ;
struct V_1 * V_456 ;
if ( V_39 > 20 )
V_39 = 20 ;
V_494 = V_5 -> V_454 ;
if ( V_494 == NULL )
return - V_120 ;
V_456 = F_1 ( & V_494 -> V_457 ) ;
V_456 -> V_473 [ V_456 -> V_469 - 1 ] . V_474 =
V_723 -> V_160 [ V_723 -> V_37 - 1 ] . V_39 *
V_39 / 100 +
V_723 -> V_160 [ V_723 -> V_37 - 1 ] . V_39 ;
return 0 ;
}
static int F_208 ( struct V_4 * V_5 , struct V_724 * V_725 )
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
for ( V_34 = 0 ; V_34 < V_166 -> V_37 ; V_34 ++ )
V_725 -> clock [ V_34 ] = V_166 -> V_38 [ V_34 ] . V_161 ;
V_725 -> V_37 = V_166 -> V_37 ;
} else if ( V_5 -> V_53 == V_56 ) {
V_147 = V_5 -> V_57 . V_155 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ )
V_725 -> clock [ V_34 ] = V_147 -> V_38 [ V_34 ] . V_161 ;
V_725 -> V_37 = V_147 -> V_37 ;
}
return 0 ;
}
static T_2 F_209 ( struct V_4 * V_5 , T_2 V_161 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_161 >= V_726 && V_161 < V_727 )
return V_24 -> V_667 ;
else if ( V_161 >= V_727 )
return V_24 -> V_669 ;
else
return V_728 ;
}
static int F_210 ( struct V_4 * V_5 , struct V_724 * V_725 )
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
V_725 -> clock [ V_34 ] = V_167 -> V_38 [ V_34 ] . V_161 ;
V_725 -> V_729 [ V_34 ] = F_209 ( V_5 ,
V_167 -> V_38 [ V_34 ] . V_161 ) ;
}
V_725 -> V_37 = V_167 -> V_37 ;
} else if ( V_5 -> V_53 == V_56 ) {
V_149 = V_5 -> V_57 . V_68 ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ )
V_725 -> clock [ V_34 ] = V_149 -> V_38 [ V_34 ] . V_161 ;
V_725 -> V_37 = V_149 -> V_37 ;
}
return 0 ;
}
static int F_211 ( struct V_4 * V_5 , enum V_730 type ,
struct V_724 * V_725 )
{
switch ( type ) {
case V_731 :
F_208 ( V_5 , V_725 ) ;
break;
case V_732 :
F_210 ( V_5 , V_725 ) ;
break;
default:
return - V_120 ;
}
return 0 ;
}
static int F_212 ( struct V_4 * V_5 )
{
int V_437 ;
struct V_733 V_173 = { 0 } ;
V_437 = F_213 ( V_5 -> V_6 ,
F_214 ( V_734 ) ,
& V_173 ) ;
if ( V_437 || ! V_173 . V_735 )
return - V_120 ;
return 0 ;
}
static int F_215 ( struct V_4 * V_5 )
{
int V_437 ;
V_437 = F_216 ( V_5 -> V_6 ,
F_214 ( V_734 ) ) ;
if ( V_437 )
return - V_120 ;
return 0 ;
}
T_5 F_217 ( T_2 clock ,
T_2 V_736 )
{
T_5 V_34 ;
T_2 V_702 ;
T_2 V_286 = V_284 ( V_736 , ( T_2 ) V_607 ) ;
F_2 ((clock >= min), L_131 , return 0 ) ;
for ( V_34 = V_737 ; ; V_34 -- ) {
V_702 = clock >> V_34 ;
if ( V_702 >= V_286 || V_34 == 0 )
break;
}
return V_34 ;
}
int F_218 ( struct V_4 * V_5 )
{
int V_437 = 0 ;
V_5 -> V_738 = & V_739 ;
if ( V_5 -> V_53 == V_56 )
V_5 -> V_740 = & V_741 ;
else if ( V_5 -> V_53 == V_54 )
V_5 -> V_740 = & V_742 ;
return V_437 ;
}
