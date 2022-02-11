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
struct V_174 V_175 = { 0 } ;
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
V_233 = F_85 ( V_5 , false ) ;
F_2 ( ( V_233 == 0 ) ,
L_60 , V_45 = V_233 ) ;
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
int F_86 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_87 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_240 V_241 = { 0 } ;
int V_45 ;
V_24 -> V_242 = false ;
V_24 -> V_243 = 0xa ;
V_24 -> V_244 = V_245 ;
V_24 -> V_246 = 300 ;
V_24 -> V_78 = V_247 ;
V_24 -> V_76 = V_248 ;
V_24 -> V_90 = V_249 ;
V_24 -> V_92 = V_250 ;
V_24 -> V_94 = V_251 ;
V_24 -> V_96 = V_252 ;
V_24 -> V_98 = V_253 ;
V_24 -> V_100 = V_254 ;
V_24 -> V_102 = V_255 ;
V_24 -> V_104 = V_256 ;
V_24 -> V_200 = V_5 -> V_19 & V_257 ? false : true ;
V_24 -> V_199 = V_5 -> V_19 & V_258 ? false : true ;
V_24 -> V_212 = V_5 -> V_19 & V_259 ? false : true ;
V_24 -> V_27 = V_26 ;
V_24 -> V_59 = V_26 ;
V_24 -> V_48 = V_26 ;
V_24 -> V_260 = true ;
V_24 -> V_261 = true ;
V_24 -> V_262 = V_263 ;
V_24 -> V_187 = V_5 -> V_19 & V_264 ? true : false ;
if ( V_5 -> V_265 == V_266 || V_5 -> V_21 -> V_267 ) {
T_5 V_268 , V_269 ;
T_1 V_270 = 0 ;
F_88 ( V_5 , V_66 , & V_268 , & V_269 ,
& V_270 ) ;
V_270 = ( V_270 >> 5 ) & 0x3 ;
V_24 -> V_271 = ( ( V_270 << 1 ) | ( V_270 >> 1 ) ) & 0x3 ;
}
V_24 -> V_272 = 100 ;
if ( F_89 ( V_5 ,
V_66 , V_273 ) )
V_24 -> V_27 = V_52 ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_274 ) ) {
if ( F_89 ( V_5 ,
V_275 , V_273 ) ) {
V_24 -> V_63 = V_52 ;
}
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_276 ) ) {
if ( F_89 ( V_5 ,
V_49 , V_50 ) )
V_24 -> V_48 = V_47 ;
else if ( F_89 ( V_5 ,
V_49 , V_273 ) )
V_24 -> V_48 = V_52 ;
}
if ( V_26 == V_24 -> V_63 ) {
F_90 ( V_5 -> V_182 . V_183 ,
V_274 ) ;
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_277 ) ) {
if ( F_89 ( V_5 ,
V_60 , V_50 ) )
V_24 -> V_59 = V_47 ;
else if ( F_89 ( V_5 ,
V_60 , V_273 ) )
V_24 -> V_59 = V_52 ;
}
if ( V_24 -> V_48 == V_26 )
F_90 ( V_5 -> V_182 . V_183 ,
V_276 ) ;
if ( V_24 -> V_59 == V_26 )
F_90 ( V_5 -> V_182 . V_183 ,
V_277 ) ;
if ( ( V_5 -> V_53 != V_56 ) && ( V_5 -> V_19 & V_278 )
&& ( V_43 -> V_279 -> V_280 != 0 ) )
F_91 ( V_5 -> V_182 . V_183 ,
V_281 ) ;
V_24 -> V_132 . V_282 = V_283 ;
V_24 -> V_132 . V_284 = V_285 ;
V_24 -> V_131 . V_282 = V_283 ;
V_24 -> V_131 . V_284 = V_285 ;
V_24 -> V_134 . V_282 = 0 ;
V_24 -> V_134 . V_284 = 16 ;
V_24 -> V_133 . V_282 = 0 ;
V_24 -> V_133 . V_284 = 16 ;
V_241 . V_286 = sizeof( struct V_240 ) ;
V_241 . V_287 = V_288 ;
V_45 = F_92 ( V_5 -> V_6 , & V_241 ) ;
if ( ! V_45 ) {
if ( V_241 . V_39 & V_289 )
F_91 ( V_5 -> V_182 . V_183 ,
V_290 ) ;
if ( V_241 . V_39 & V_291 )
F_91 ( V_5 -> V_182 . V_183 ,
V_292 ) ;
}
}
static int F_93 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_1 V_293 ;
T_1 V_294 = 0 ;
T_1 V_295 = 0 ;
T_1 V_34 , V_296 ;
T_2 V_297 = 0 ;
struct V_42 * V_43 =
(struct V_42 * ) V_5 -> V_44 ;
struct V_165 * V_147 = NULL ;
for ( V_34 = 0 ; V_34 < V_298 ; V_34 ++ ) {
V_293 = V_299 + V_34 ;
if ( V_24 -> V_63 == V_52 ) {
if ( ( V_5 -> V_53 == V_54 )
&& ! F_94 ( V_5 ,
V_43 -> V_65 , V_293 , & V_297 ) ) {
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_281 ) ) {
V_147 = V_43 -> V_168 ;
for ( V_296 = 1 ; V_296 < V_147 -> V_37 ; V_296 ++ ) {
if ( V_147 -> V_38 [ V_296 ] . V_161 == V_297 &&
V_147 -> V_38 [ V_296 ] . V_300 == 0 ) {
V_297 += 5000 ;
break;
}
}
}
if ( 0 == F_95
( V_5 , V_275 , V_297 ,
V_293 , & V_295 ) ) {
F_2 ((vddgfx < 2000 && vddgfx != 0), L_67 , return -EINVAL) ;
if ( V_295 != 0 && V_295 != V_293 ) {
V_24 -> V_301 . V_302 [ V_24 -> V_301 . V_37 ] = V_295 ;
V_24 -> V_301 . V_303 [ V_24 -> V_301 . V_37 ] = V_293 ;
V_24 -> V_301 . V_37 ++ ;
}
} else {
F_96 ( L_68 ) ;
}
}
} else {
if ( ( V_5 -> V_53 == V_56 )
|| ! F_94 ( V_5 ,
V_43 -> V_69 , V_293 , & V_297 ) ) {
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_281 ) ) {
if ( V_43 == NULL )
return - V_120 ;
V_147 = V_43 -> V_168 ;
for ( V_296 = 1 ; V_296 < V_147 -> V_37 ; V_296 ++ ) {
if ( V_147 -> V_38 [ V_296 ] . V_161 == V_297 &&
V_147 -> V_38 [ V_296 ] . V_300 == 0 ) {
V_297 += 5000 ;
break;
}
}
}
if ( F_97 ( V_5 ,
V_66 ,
V_297 , V_293 , & V_294 ) == 0 ) {
if ( V_294 >= 2000 || V_294 == 0 )
return - V_120 ;
} else {
F_98 ( L_69 ) ;
continue;
}
if ( V_294 != 0 && V_294 != V_293 ) {
V_24 -> V_304 . V_302 [ V_24 -> V_304 . V_37 ] = ( T_1 ) ( V_294 ) ;
V_24 -> V_304 . V_303 [ V_24 -> V_304 . V_37 ] = V_293 ;
V_24 -> V_304 . V_37 ++ ;
}
}
}
}
return 0 ;
}
static void F_99 ( struct V_4 * V_5 ,
T_1 * V_305 , struct V_306 * V_307 )
{
T_2 V_308 ;
for ( V_308 = 0 ; V_308 < V_307 -> V_37 ; V_308 ++ ) {
if ( V_307 -> V_303 [ V_308 ] == * V_305 ) {
* V_305 = V_307 -> V_302 [ V_308 ] ;
break;
}
}
if ( * V_305 > V_299 )
F_63 ( L_70 ) ;
}
static int F_100 ( struct V_4 * V_5 ,
T_6 * V_309 ,
struct V_306 * V_307 )
{
T_2 V_34 ;
for ( V_34 = 0 ; V_34 < V_309 -> V_37 ; V_34 ++ )
F_99 ( V_5 ,
& V_309 -> V_38 [ V_34 ] . V_310 , V_307 ) ;
return 0 ;
}
static int F_101 (
struct V_4 * V_5 , struct V_306 * V_307 ,
T_1 * V_294 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
F_99 ( V_5 , ( T_1 * ) V_294 , V_307 ) ;
V_5 -> V_57 . V_311 . V_294 =
V_43 -> V_311 . V_294 ;
return 0 ;
}
static int F_102 (
struct V_4 * V_5 )
{
T_5 V_312 ;
T_5 V_313 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_147 =
V_43 -> V_168 ;
struct V_165 * V_149 =
V_43 -> V_55 ;
struct V_314 * V_315 =
V_43 -> V_316 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_312 = 0 ; V_312 < V_147 -> V_37 ; ++ V_312 ) {
V_313 = V_147 -> V_38 [ V_312 ] . V_317 ;
V_147 -> V_38 [ V_312 ] . V_295 =
V_43 -> V_65 -> V_38 [ V_313 ] . V_310 ;
}
} else {
for ( V_312 = 0 ; V_312 < V_147 -> V_37 ; ++ V_312 ) {
V_313 = V_147 -> V_38 [ V_312 ] . V_317 ;
V_147 -> V_38 [ V_312 ] . V_294 =
V_43 -> V_69 -> V_38 [ V_313 ] . V_310 ;
}
}
for ( V_312 = 0 ; V_312 < V_149 -> V_37 ; ++ V_312 ) {
V_313 = V_149 -> V_38 [ V_312 ] . V_317 ;
V_149 -> V_38 [ V_312 ] . V_294 =
V_43 -> V_69 -> V_38 [ V_313 ] . V_310 ;
}
for ( V_312 = 0 ; V_312 < V_315 -> V_37 ; ++ V_312 ) {
V_313 = V_315 -> V_38 [ V_312 ] . V_318 ;
V_315 -> V_38 [ V_312 ] . V_294 =
V_43 -> V_69 -> V_38 [ V_313 ] . V_310 ;
}
return 0 ;
}
static int F_103 ( struct V_4 * V_5 ,
T_6 * V_319 ,
T_7 * V_320 )
{
T_2 V_34 ;
F_2 ((NULL != look_up_table),
L_71 , return -EINVAL) ;
F_2 ((0 != look_up_table->count),
L_71 , return -EINVAL) ;
V_34 = F_24 ( V_5 -> V_21 , V_71 ) ;
F_2 ((i >= look_up_table->count),
L_72 , return -EINVAL) ;
for ( V_34 = 0 ; V_34 < V_319 -> V_37 ; V_34 ++ ) {
if ( V_319 -> V_38 [ V_34 ] . V_310 == V_320 -> V_310 ) {
if ( V_319 -> V_38 [ V_34 ] . V_321 == 1 )
return 0 ;
break;
}
}
V_319 -> V_38 [ V_34 ] . V_321 = 1 ;
V_319 -> V_38 [ V_34 ] . V_310 = V_320 -> V_310 ;
V_319 -> V_38 [ V_34 ] . V_322 = V_320 -> V_322 ;
V_319 -> V_38 [ V_34 ] . V_323 = V_320 -> V_323 ;
V_319 -> V_38 [ V_34 ] . V_324 = V_320 -> V_324 ;
if ( V_34 == V_319 -> V_37 )
V_319 -> V_37 ++ ;
return 0 ;
}
static int F_104 ( struct V_4 * V_5 )
{
T_5 V_312 ;
struct T_7 V_325 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_326 = (struct V_42 * ) ( V_5 -> V_44 ) ;
V_165 * V_147 = V_326 -> V_168 ;
V_165 * V_149 = V_326 -> V_55 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_312 = 0 ; V_312 < V_147 -> V_37 ; ++ V_312 ) {
if ( V_147 -> V_38 [ V_312 ] . V_327 & ( 1 << 15 ) )
V_325 . V_310 = V_147 -> V_38 [ V_312 ] . V_295 +
V_147 -> V_38 [ V_312 ] . V_327 - 0xFFFF ;
else
V_325 . V_310 = V_147 -> V_38 [ V_312 ] . V_295 +
V_147 -> V_38 [ V_312 ] . V_327 ;
V_147 -> V_38 [ V_312 ] . V_294 =
V_325 . V_322 = V_325 . V_323 =
V_325 . V_324 = V_325 . V_310 ;
F_103 ( V_5 , V_326 -> V_69 , & V_325 ) ;
}
for ( V_312 = 0 ; V_312 < V_149 -> V_37 ; ++ V_312 ) {
if ( V_149 -> V_38 [ V_312 ] . V_327 & ( 1 << 15 ) )
V_325 . V_310 = V_149 -> V_38 [ V_312 ] . V_294 +
V_149 -> V_38 [ V_312 ] . V_327 - 0xFFFF ;
else
V_325 . V_310 = V_149 -> V_38 [ V_312 ] . V_294 +
V_149 -> V_38 [ V_312 ] . V_327 ;
V_149 -> V_38 [ V_312 ] . V_295 = V_325 . V_322 =
V_325 . V_323 = V_325 . V_324 = V_325 . V_310 ;
F_103 ( V_5 , V_326 -> V_65 , & V_325 ) ;
}
}
return 0 ;
}
static int F_105 ( struct V_4 * V_5 )
{
T_5 V_312 ;
struct T_7 V_325 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_326 = (struct V_42 * ) ( V_5 -> V_44 ) ;
V_314 * V_315 = V_326 -> V_316 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_312 = 0 ; V_312 < V_315 -> V_37 ; V_312 ++ ) {
if ( V_315 -> V_38 [ V_312 ] . V_328 & ( 1 << 15 ) )
V_325 . V_310 = V_315 -> V_38 [ V_312 ] . V_294 +
V_315 -> V_38 [ V_312 ] . V_328 - 0xFFFF ;
else
V_325 . V_310 = V_315 -> V_38 [ V_312 ] . V_294 +
V_315 -> V_38 [ V_312 ] . V_328 ;
V_315 -> V_38 [ V_312 ] . V_295 = V_325 . V_322 =
V_325 . V_323 = V_325 . V_324 = V_325 . V_310 ;
F_103 ( V_5 , V_326 -> V_65 , & V_325 ) ;
}
}
return 0 ;
}
static int F_106 ( struct V_4 * V_5 ,
struct T_6 * V_309 )
{
T_2 V_329 , V_34 , V_296 ;
struct T_7 V_330 ;
V_329 = V_309 -> V_37 ;
F_2 ( 0 != lookup_table->count,
L_73 , return -EINVAL) ;
for ( V_34 = 0 ; V_34 < V_329 - 1 ; V_34 ++ ) {
for ( V_296 = V_34 + 1 ; V_296 > 0 ; V_296 -- ) {
if ( V_309 -> V_38 [ V_296 ] . V_310 <
V_309 -> V_38 [ V_296 - 1 ] . V_310 ) {
V_330 = V_309 -> V_38 [ V_296 - 1 ] ;
V_309 -> V_38 [ V_296 - 1 ] = V_309 -> V_38 [ V_296 ] ;
V_309 -> V_38 [ V_296 ] = V_330 ;
}
}
}
return 0 ;
}
static int F_107 ( struct V_4 * V_5 )
{
int V_45 = 0 ;
int V_233 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
if ( V_24 -> V_63 == V_52 ) {
V_233 = F_100 ( V_5 ,
V_43 -> V_65 , & ( V_24 -> V_301 ) ) ;
if ( V_233 != 0 )
V_45 = V_233 ;
F_99 ( V_5 ,
& V_43 -> V_311 . V_295 , & ( V_24 -> V_301 ) ) ;
} else {
V_233 = F_100 ( V_5 ,
V_43 -> V_69 , & ( V_24 -> V_304 ) ) ;
if ( V_233 )
V_45 = V_233 ;
V_233 = F_101 ( V_5 ,
& ( V_24 -> V_304 ) , & V_43 -> V_311 . V_294 ) ;
if ( V_233 )
V_45 = V_233 ;
}
V_233 = F_102 ( V_5 ) ;
if ( V_233 )
V_45 = V_233 ;
V_233 = F_104 ( V_5 ) ;
if ( V_233 )
V_45 = V_233 ;
V_233 = F_105 ( V_5 ) ;
if ( V_233 )
V_45 = V_233 ;
V_233 = F_106 ( V_5 , V_43 -> V_65 ) ;
if ( V_233 )
V_45 = V_233 ;
V_233 = F_106 ( V_5 , V_43 -> V_69 ) ;
if ( V_233 )
V_45 = V_233 ;
return V_45 ;
}
static int F_108 ( struct V_4 * V_5 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_331 =
V_43 -> V_168 ;
struct V_165 * V_332 =
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
V_43 -> V_333 . V_297 =
V_331 -> V_38 [ V_331 -> V_37 - 1 ] . V_161 ;
V_43 -> V_333 . V_334 =
V_332 -> V_38 [ V_332 -> V_37 - 1 ] . V_161 ;
V_43 -> V_333 . V_294 =
V_331 -> V_38 [ V_331 -> V_37 - 1 ] . V_294 ;
V_43 -> V_333 . V_335 =
V_332 -> V_38 [ V_332 -> V_37 - 1 ] . V_335 ;
V_5 -> V_57 . V_333 . V_297 = V_43 -> V_333 . V_297 ;
V_5 -> V_57 . V_333 . V_334 = V_43 -> V_333 . V_334 ;
V_5 -> V_57 . V_333 . V_294 = V_43 -> V_333 . V_294 ;
V_5 -> V_57 . V_333 . V_335 = V_43 -> V_333 . V_335 ;
return 0 ;
}
static int F_109 ( struct V_4 * V_5 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_167 ;
struct T_6 * V_309 ;
T_2 V_34 ;
T_2 V_336 , V_337 , V_338 ;
struct V_240 V_241 = { 0 } ;
if ( V_43 != NULL ) {
V_167 = V_43 -> V_55 ;
V_309 = V_43 -> V_69 ;
} else
return 0 ;
V_241 . V_286 = sizeof( struct V_240 ) ;
V_241 . V_287 = V_339 ;
F_92 ( V_5 -> V_6 , & V_241 ) ;
V_336 = ( T_2 ) V_241 . V_39 ;
V_241 . V_287 = V_340 ;
F_92 ( V_5 -> V_6 , & V_241 ) ;
V_338 = ( T_2 ) V_241 . V_39 ;
V_241 . V_287 = V_341 ;
F_92 ( V_5 -> V_6 , & V_241 ) ;
V_337 = ( T_2 ) V_241 . V_39 ;
if ( V_5 -> V_265 == V_342 && V_336 == 0xC7 &&
( ( V_338 == 0xb37 && V_337 == 0x1002 ) ||
( V_338 == 0x4a8 && V_337 == 0x1043 ) ||
( V_338 == 0x9480 && V_337 == 0x1682 ) ) ) {
if ( V_309 -> V_38 [ V_167 -> V_38 [ V_167 -> V_37 - 1 ] . V_317 ] . V_310 >= 1000 )
return 0 ;
for ( V_34 = 0 ; V_34 < V_309 -> V_37 ; V_34 ++ ) {
if ( V_309 -> V_38 [ V_34 ] . V_310 < 0xff01 && V_309 -> V_38 [ V_34 ] . V_310 >= 1000 ) {
V_167 -> V_38 [ V_167 -> V_37 - 1 ] . V_317 = ( T_5 ) V_34 ;
return 0 ;
}
}
}
return 0 ;
}
static int F_110 ( struct V_4 * V_5 )
{
struct V_343 V_344 ;
T_2 V_345 ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
if ( F_111 ( V_5 , V_346 , & V_344 ) ) {
V_345 = F_8 ( V_5 -> V_6 , V_28 , V_347 ) ;
switch ( V_344 . V_348 ) {
case 0 :
V_345 = F_28 ( V_345 , V_349 , V_350 , 0x1 ) ;
break;
case 1 :
V_345 = F_28 ( V_345 , V_349 , V_350 , 0x2 ) ;
break;
case 2 :
V_345 = F_28 ( V_345 , V_349 , V_351 , 0x1 ) ;
break;
case 3 :
V_345 = F_28 ( V_345 , V_349 , V_352 , 0x1 ) ;
break;
case 4 :
V_345 = F_28 ( V_345 , V_349 , V_353 , 0x1 ) ;
break;
default:
break;
}
F_29 ( V_5 -> V_6 , V_28 , V_347 , V_345 ) ;
}
if ( V_43 == NULL )
return 0 ;
if ( V_43 -> V_279 -> V_354 != 0 &&
V_5 -> V_355 . V_356 . V_357 ) {
V_5 -> V_355 . V_356 . V_358 =
( T_1 ) V_5 -> V_355 . V_356 . V_359 ;
V_5 -> V_355 . V_356 . V_360 =
( T_1 ) V_5 -> V_355 . V_356 . V_361 ;
V_5 -> V_355 . V_356 . V_362 = 1 ;
V_5 -> V_355 . V_356 . V_363 = 100 ;
V_5 -> V_355 . V_356 . V_364 =
( T_1 ) V_5 -> V_355 . V_356 . V_359 ;
V_5 -> V_355 . V_356 . V_365 = 1 ;
V_43 -> V_279 -> V_354 = ( V_43 -> V_279 -> V_354 >= 50 ) ?
( V_43 -> V_279 -> V_354 - 50 ) : 0 ;
V_43 -> V_279 -> V_366 = V_43 -> V_279 -> V_354 ;
V_43 -> V_279 -> V_367 = 1 ;
V_43 -> V_279 -> V_368 = 1 ;
V_5 -> V_355 . V_356 . V_369 =
V_5 -> V_355 . V_356 . V_361 ;
V_5 -> V_355 . V_356 . V_370 =
V_5 -> V_355 . V_356 . V_371 ;
V_5 -> V_57 . V_279 -> V_372 =
V_43 -> V_279 -> V_372 ;
V_5 -> V_57 . V_279 -> V_366 =
V_43 -> V_279 -> V_366 ;
V_5 -> V_57 . V_279 -> V_354 =
V_43 -> V_279 -> V_354 ;
V_5 -> V_57 . V_279 -> V_367 =
V_43 -> V_279 -> V_367 ;
V_5 -> V_57 . V_279 -> V_373 =
V_43 -> V_279 -> V_373 ;
if ( V_5 -> V_19 & V_374 )
F_91 ( V_5 -> V_182 . V_183 ,
V_375 ) ;
}
return 0 ;
}
static void F_112 ( struct V_4 * V_5 ,
T_2 * V_305 , struct V_306 * V_307 )
{
T_2 V_308 ;
for ( V_308 = 0 ; V_308 < V_307 -> V_37 ; V_308 ++ ) {
if ( V_307 -> V_303 [ V_308 ] == * V_305 ) {
* V_305 = V_307 -> V_302 [ V_308 ] ;
break;
}
}
if ( * V_305 > V_299 )
F_63 ( L_70 ) ;
}
static int F_113 ( struct V_4 * V_5 ,
struct V_32 * V_376 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_376 )
for ( V_34 = 0 ; V_34 < V_376 -> V_37 ; V_34 ++ )
F_112 ( V_5 , & V_376 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_304 ) ;
return 0 ;
}
static int F_114 ( struct V_4 * V_5 ,
struct V_32 * V_376 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_376 )
for ( V_34 = 0 ; V_34 < V_376 -> V_37 ; V_34 ++ )
F_112 ( V_5 , & V_376 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_377 ) ;
return 0 ;
}
static int F_115 ( struct V_4 * V_5 ,
struct V_378 * V_376 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_376 )
for ( V_34 = 0 ; V_34 < V_376 -> V_37 ; V_34 ++ )
F_112 ( V_5 , & V_376 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_304 ) ;
return 0 ;
}
static int F_116 ( struct V_4 * V_5 ,
struct V_379 * V_376 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_376 )
for ( V_34 = 0 ; V_34 < V_376 -> V_37 ; V_34 ++ )
F_112 ( V_5 , & V_376 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_304 ) ;
return 0 ;
}
static int F_117 ( struct V_4 * V_5 ,
struct V_380 * V_376 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_376 )
for ( V_34 = 0 ; V_34 < V_376 -> V_37 ; V_34 ++ )
F_112 ( V_5 , & V_376 -> V_38 [ V_34 ] . V_381 ,
& V_24 -> V_304 ) ;
return 0 ;
}
static int F_118 ( struct V_4 * V_5 ,
struct V_382 * V_376 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_376 )
for ( V_34 = 0 ; V_34 < V_376 -> V_37 ; V_34 ++ )
F_112 ( V_5 , & V_376 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_304 ) ;
return 0 ;
}
static int F_119 ( struct V_4 * V_5 ,
struct V_383 * V_376 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_376 )
for ( V_34 = 0 ; V_34 < V_376 -> V_37 ; V_34 ++ )
F_112 ( V_5 , & V_376 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_304 ) ;
return 0 ;
}
static int F_120 ( struct V_4 * V_5 ,
struct V_384 * V_376 )
{
T_2 V_294 , V_335 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_376 ) {
V_294 = V_376 -> V_294 ;
F_112 ( V_5 , & V_294 ,
& V_24 -> V_304 ) ;
V_376 -> V_294 = V_294 ;
V_335 = V_376 -> V_335 ;
F_112 ( V_5 , & V_335 ,
& V_24 -> V_377 ) ;
V_376 -> V_335 = V_335 ;
}
return 0 ;
}
static int F_121 ( struct V_4 * V_5 , struct V_157 * V_376 )
{
T_2 V_34 ;
T_2 V_294 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_376 ) {
for ( V_34 = 0 ; V_34 < V_376 -> V_37 ; V_34 ++ ) {
V_294 = ( T_2 ) ( V_376 -> V_38 [ V_34 ] . V_385 ) ;
F_112 ( V_5 , & V_294 , & V_24 -> V_304 ) ;
V_376 -> V_38 [ V_34 ] . V_385 = ( T_1 ) V_294 ;
}
}
return 0 ;
}
static int F_122 ( struct V_4 * V_5 )
{
int V_46 ;
V_46 = F_113 ( V_5 , V_5 -> V_57 . V_155 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_113 ( V_5 , V_5 -> V_57 . V_68 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_113 ( V_5 , V_5 -> V_57 . V_386 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_114 ( V_5 , V_5 -> V_57 . V_62 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_115 ( V_5 , V_5 -> V_57 . V_387 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_116 ( V_5 , V_5 -> V_57 . V_388 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_118 ( V_5 , V_5 -> V_57 . V_389 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_119 ( V_5 , V_5 -> V_57 . V_390 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_117 ( V_5 , V_5 -> V_57 . V_391 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_120 ( V_5 , & V_5 -> V_57 . V_333 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_120 ( V_5 , & V_5 -> V_57 . V_311 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_121 ( V_5 , V_5 -> V_57 . V_159 ) ;
if ( V_46 )
return - V_120 ;
return 0 ;
}
static int F_123 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_32 * V_392 = V_5 -> V_57 . V_155 ;
struct V_32 * V_393 = V_5 -> V_57 . V_68 ;
struct V_32 * V_394 = V_5 -> V_57 . V_62 ;
F_2 (allowed_sclk_vddc_table != NULL,
L_78 , return -EINVAL) ;
F_2 (allowed_sclk_vddc_table->count >= 1 ,
L_79 , return -EINVAL) ;
F_2 (allowed_mclk_vddc_table != NULL,
L_80 , return -EINVAL) ;
F_2 (allowed_mclk_vddc_table->count >= 1 ,
L_81 , return -EINVAL) ;
V_24 -> V_395 = ( T_1 ) V_392 -> V_38 [ 0 ] . V_40 ;
V_24 -> V_396 = ( T_1 ) V_392 -> V_38 [ V_392 -> V_37 - 1 ] . V_40 ;
V_5 -> V_57 . V_333 . V_297 =
V_392 -> V_38 [ V_392 -> V_37 - 1 ] . V_161 ;
V_5 -> V_57 . V_333 . V_334 =
V_393 -> V_38 [ V_393 -> V_37 - 1 ] . V_161 ;
V_5 -> V_57 . V_333 . V_294 =
V_392 -> V_38 [ V_392 -> V_37 - 1 ] . V_40 ;
if ( V_394 != NULL && V_394 -> V_37 >= 1 ) {
V_24 -> V_397 = ( T_1 ) V_394 -> V_38 [ 0 ] . V_40 ;
V_24 -> V_398 = ( T_1 ) V_394 -> V_38 [ V_394 -> V_37 - 1 ] . V_40 ;
}
if ( V_5 -> V_57 . V_62 != NULL && V_5 -> V_57 . V_62 -> V_37 > 1 )
V_5 -> V_57 . V_333 . V_335 = V_5 -> V_57 . V_62 -> V_38 [ V_5 -> V_57 . V_62 -> V_37 - 1 ] . V_40 ;
return 0 ;
}
static int F_124 ( struct V_4 * V_5 )
{
if ( NULL != V_5 -> V_57 . V_386 ) {
F_125 ( V_5 -> V_57 . V_386 ) ;
V_5 -> V_57 . V_386 = NULL ;
}
F_126 ( V_5 ) ;
if ( NULL != V_5 -> V_25 ) {
F_125 ( V_5 -> V_25 ) ;
V_5 -> V_25 = NULL ;
}
return 0 ;
}
static int F_127 ( struct V_4 * V_5 )
{
struct V_23 * V_24 ;
int V_45 ;
V_24 = F_128 ( sizeof( struct V_23 ) , V_399 ) ;
if ( V_24 == NULL )
return - V_400 ;
V_5 -> V_25 = V_24 ;
F_129 ( V_5 ) ;
F_109 ( V_5 ) ;
F_87 ( V_5 ) ;
V_45 = F_93 ( V_5 ) ;
if ( V_45 ) {
F_96 ( L_82 ) ;
return - V_120 ;
}
if ( V_5 -> V_53 == V_54 ) {
F_107 ( V_5 ) ;
F_108 ( V_5 ) ;
} else if ( V_5 -> V_53 == V_56 ) {
F_122 ( V_5 ) ;
F_123 ( V_5 ) ;
}
V_45 = F_130 ( V_5 ) ;
if ( 0 == V_45 ) {
struct V_240 V_241 = { 0 } ;
V_24 -> V_401 = false ;
V_5 -> V_182 . V_402 =
V_403 ;
V_5 -> V_182 . V_404 = 2 ;
V_5 -> V_182 . V_405 = 50 ;
V_241 . V_286 = sizeof( struct V_240 ) ;
V_241 . V_287 = V_406 ;
V_45 = F_92 ( V_5 -> V_6 , & V_241 ) ;
if ( V_45 )
V_24 -> V_139 = V_407 ;
else
V_24 -> V_139 = ( T_2 ) V_241 . V_39 ;
if ( V_24 -> V_139 & V_408 )
V_24 -> V_409 = 20 ;
V_241 . V_286 = sizeof( struct V_240 ) ;
V_241 . V_287 = V_410 ;
V_45 = F_92 ( V_5 -> V_6 , & V_241 ) ;
if ( V_45 )
V_24 -> V_141 = V_411 ;
else
V_24 -> V_141 = ( T_2 ) V_241 . V_39 ;
V_5 -> V_182 . V_412 = 0x20000400 ;
V_5 -> V_182 . V_413 . V_414 = 500 ;
V_5 -> V_182 . V_413 . V_415 = 500 ;
F_110 ( V_5 ) ;
} else {
F_124 ( V_5 ) ;
}
return 0 ;
}
static int F_131 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_416 , V_46 ;
if ( ! V_24 -> V_212 ) {
if ( V_24 -> V_417 . V_418 ) {
V_416 = 0 ;
V_46 = V_24 -> V_417 . V_418 ;
while ( V_46 >>= 1 )
V_416 ++ ;
if ( V_416 )
F_132 ( V_5 -> V_21 ,
V_419 , V_416 ) ;
}
}
if ( ! V_24 -> V_199 ) {
if ( V_24 -> V_417 . V_420 ) {
V_416 = 0 ;
V_46 = V_24 -> V_417 . V_420 ;
while ( V_46 >>= 1 )
V_416 ++ ;
if ( V_416 )
F_132 ( V_5 -> V_21 ,
V_421 ,
( 1 << V_416 ) ) ;
}
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_417 . V_422 ) {
V_416 = 0 ;
V_46 = V_24 -> V_417 . V_422 ;
while ( V_46 >>= 1 )
V_416 ++ ;
if ( V_416 )
F_132 ( V_5 -> V_21 ,
V_423 ,
( 1 << V_416 ) ) ;
}
}
return 0 ;
}
static int F_133 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_5 -> V_53 == V_54 )
F_134 ( V_5 ) ;
if ( ! V_24 -> V_199 ) {
if ( V_24 -> V_417 . V_420 )
F_132 ( V_5 -> V_21 ,
V_421 ,
V_24 -> V_417 . V_420 ) ;
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_417 . V_422 )
F_132 ( V_5 -> V_21 ,
V_423 ,
V_24 -> V_417 . V_422 ) ;
}
return 0 ;
}
static int F_135 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( ! F_73 ( V_5 ) )
return - V_120 ;
if ( ! V_24 -> V_212 ) {
F_14 ( V_5 -> V_21 ,
V_424 ) ;
}
return F_133 ( V_5 ) ;
}
static int F_136 ( struct V_4 * V_5 )
{
struct V_23 * V_24 =
(struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_416 ;
if ( ! V_24 -> V_199 )
if ( V_24 -> V_417 . V_420 ) {
V_416 = F_137 ( V_5 ,
V_24 -> V_417 . V_420 ) ;
F_132 ( V_5 -> V_21 ,
V_421 ,
( 1 << V_416 ) ) ;
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_417 . V_422 ) {
V_416 = F_137 ( V_5 ,
V_24 -> V_417 . V_422 ) ;
F_132 ( V_5 -> V_21 ,
V_423 ,
( 1 << V_416 ) ) ;
}
}
if ( ! V_24 -> V_212 ) {
if ( V_24 -> V_417 . V_418 ) {
V_416 = F_137 ( V_5 ,
V_24 -> V_417 . V_418 ) ;
F_132 ( V_5 -> V_21 ,
V_419 ,
( V_416 ) ) ;
}
}
return 0 ;
}
static int F_138 ( struct V_4 * V_5 , enum V_425 V_416 ,
T_2 * V_426 , T_2 * V_427 , T_2 * V_428 )
{
T_2 V_429 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_170 * V_169 = & V_24 -> V_169 ;
T_8 V_430 ;
T_8 V_431 ;
T_8 V_37 ;
if ( V_169 -> V_149 . V_37 < 1 )
return - V_120 ;
V_429 = 100 * V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 /
V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
if ( V_169 -> V_149 . V_37 == 1 ) {
V_429 = 70 ;
V_430 = V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
* V_427 = V_169 -> V_149 . V_37 - 1 ;
} else {
V_430 = V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 2 ] . V_39 ;
* V_427 = V_169 -> V_149 . V_37 - 2 ;
}
V_431 = V_430 * V_429 / 100 ;
if ( V_5 -> V_53 == V_56 ) {
for ( V_37 = V_5 -> V_57 . V_155 -> V_37 - 1 ;
V_37 >= 0 ; V_37 -- ) {
if ( V_431 >= V_5 -> V_57 . V_155 -> V_38 [ V_37 ] . V_161 ) {
V_431 = V_5 -> V_57 . V_155 -> V_38 [ V_37 ] . V_161 ;
* V_426 = V_37 ;
break;
}
}
if ( V_37 < 0 || V_416 == V_432 )
* V_426 = 0 ;
if ( V_416 == V_433 )
* V_426 = V_5 -> V_57 . V_155 -> V_37 - 1 ;
} else if ( V_5 -> V_53 == V_54 ) {
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
for ( V_37 = V_43 -> V_168 -> V_37 - 1 ; V_37 >= 0 ; V_37 -- ) {
if ( V_431 >= V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ) {
V_431 = V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ;
* V_426 = V_37 ;
break;
}
}
if ( V_37 < 0 || V_416 == V_432 )
* V_426 = 0 ;
if ( V_416 == V_433 )
* V_426 = V_43 -> V_168 -> V_37 - 1 ;
}
if ( V_416 == V_434 )
* V_427 = 0 ;
else if ( V_416 == V_433 )
* V_427 = V_169 -> V_149 . V_37 - 1 ;
* V_428 = V_24 -> V_136 . V_137 . V_37 - 1 ;
return 0 ;
}
static int F_139 ( struct V_4 * V_5 ,
enum V_425 V_416 )
{
int V_435 = 0 ;
T_2 V_426 = 0 ;
T_2 V_427 = 0 ;
T_2 V_428 = 0 ;
T_2 V_436 = V_437 |
V_432 |
V_434 |
V_433 ;
if ( V_416 == V_5 -> V_438 )
return V_435 ;
if ( ! ( V_5 -> V_438 & V_436 ) ) {
if ( V_416 & V_436 ) {
V_5 -> V_439 = V_5 -> V_438 ;
F_140 ( V_5 -> V_6 ,
V_440 ,
V_441 ) ;
}
} else {
if ( ! ( V_416 & V_436 ) ) {
if ( V_416 == V_442 )
V_416 = V_5 -> V_439 ;
F_140 ( V_5 -> V_6 ,
V_440 ,
V_443 ) ;
}
}
switch ( V_416 ) {
case V_444 :
V_435 = F_131 ( V_5 ) ;
if ( V_435 )
return V_435 ;
V_5 -> V_438 = V_416 ;
break;
case V_445 :
V_435 = F_136 ( V_5 ) ;
if ( V_435 )
return V_435 ;
V_5 -> V_438 = V_416 ;
break;
case V_446 :
V_435 = F_135 ( V_5 ) ;
if ( V_435 )
return V_435 ;
V_5 -> V_438 = V_416 ;
break;
case V_437 :
case V_432 :
case V_434 :
case V_433 :
V_435 = F_138 ( V_5 , V_416 , & V_426 , & V_427 , & V_428 ) ;
if ( V_435 )
return V_435 ;
V_5 -> V_438 = V_416 ;
F_141 ( V_5 , V_447 , 1 << V_426 ) ;
F_141 ( V_5 , V_448 , 1 << V_427 ) ;
F_141 ( V_5 , V_449 , 1 << V_428 ) ;
break;
case V_450 :
V_5 -> V_438 = V_416 ;
break;
case V_442 :
default:
break;
}
if ( V_416 == V_433 && V_5 -> V_439 != V_433 )
F_142 ( V_5 , 100 ) ;
else if ( V_416 != V_433 && V_5 -> V_439 == V_433 )
F_143 ( V_5 ) ;
return 0 ;
}
static int F_144 ( struct V_4 * V_5 )
{
return sizeof( struct V_1 ) ;
}
static int F_145 ( struct V_4 * V_5 ,
T_2 V_451 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_452 ;
switch ( V_5 -> V_265 ) {
case V_342 :
case V_453 :
case V_266 :
V_452 = V_24 -> V_454 ? 190 : 150 ;
break;
default:
V_452 = V_24 -> V_454 ? 450 : 150 ;
break;
}
if ( V_451 < V_452 )
return true ;
else
return false ;
}
static int F_146 ( struct V_4 * V_5 ,
struct V_455 * V_456 ,
const struct V_455 * V_457 )
{
struct V_1 * V_458 =
F_1 ( & V_456 -> V_459 ) ;
T_2 V_297 ;
T_2 V_334 ;
struct V_460 V_461 = { 0 } ;
bool V_462 ;
bool V_463 ;
struct V_172 V_173 = { 0 } ;
struct V_174 V_175 = { 0 } ;
const struct V_384 * V_464 ;
T_2 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
T_8 V_37 ;
T_8 V_465 = 0 , V_466 = 0 ;
V_173 . V_175 = & V_175 ;
V_24 -> V_467 = ( V_468 ==
V_456 -> V_469 . V_470 ) ;
F_2 ( V_458 -> V_471 == 2 ,
L_83 ,
) ;
V_464 = ( V_472 == V_5 -> V_473 ) ?
& ( V_5 -> V_57 . V_333 ) :
& ( V_5 -> V_57 . V_311 ) ;
if ( V_474 == V_5 -> V_473 ) {
for ( V_34 = 0 ; V_34 < V_458 -> V_471 ; V_34 ++ ) {
if ( V_458 -> V_475 [ V_34 ] . V_476 > V_464 -> V_334 )
V_458 -> V_475 [ V_34 ] . V_476 = V_464 -> V_334 ;
if ( V_458 -> V_475 [ V_34 ] . V_477 > V_464 -> V_297 )
V_458 -> V_475 [ V_34 ] . V_477 = V_464 -> V_297 ;
}
}
V_458 -> V_478 . V_479 = V_5 -> V_480 . V_479 ;
V_458 -> V_478 . V_481 = V_5 -> V_480 . V_481 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_461 . V_414 = V_5 -> V_482 . V_483 ;
V_461 . V_415 = V_5 -> V_482 . V_484 ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_485 ) ) {
V_464 = & ( V_5 -> V_57 . V_333 ) ;
V_465 = ( V_464 -> V_297 * 75 ) / 100 ;
for ( V_37 = V_43 -> V_168 -> V_37 - 1 ;
V_37 >= 0 ; V_37 -- ) {
if ( V_465 >=
V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ) {
V_465 =
V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ;
break;
}
}
if ( V_37 < 0 )
V_465 = V_43 -> V_168 -> V_38 [ 0 ] . V_161 ;
V_466 = V_464 -> V_334 ;
V_461 . V_414 = V_465 ;
V_461 . V_415 = V_466 ;
}
if ( V_461 . V_414 < V_5 -> V_486 . V_297 )
V_461 . V_414 = V_5 -> V_486 . V_297 ;
if ( V_461 . V_415 < V_5 -> V_486 . V_334 )
V_461 . V_415 = V_5 -> V_486 . V_334 ;
V_458 -> V_487 = V_5 -> V_486 . V_487 ;
if ( 0 != V_5 -> V_486 . V_488 ) {
F_2 ( ( V_5 -> V_486 . V_488 <=
V_5 -> V_182 . V_489 . V_414 ) ,
L_84 ,
V_5 -> V_486 . V_488 =
V_5 -> V_182 . V_489 . V_414 ) ;
if ( V_5 -> V_486 . V_488 >= V_5 -> V_486 . V_297 )
V_458 -> V_475 [ 1 ] . V_477 =
V_5 -> V_486 . V_488 ;
}
if ( 0 != V_5 -> V_486 . V_490 ) {
F_2 ( ( V_5 -> V_486 . V_490 <=
V_5 -> V_182 . V_489 . V_415 ) ,
L_85 ,
V_5 -> V_486 . V_490 =
V_5 -> V_182 . V_489 . V_415 ) ;
if ( V_5 -> V_486 . V_490 >= V_5 -> V_486 . V_334 )
V_458 -> V_475 [ 1 ] . V_476 =
V_5 -> V_486 . V_490 ;
}
V_463 = F_52 (
V_5 -> V_182 . V_183 ,
V_491 ) ;
V_462 = ( ( 1 < V_173 . V_492 ) ||
V_463 ||
F_145 ( V_5 , V_175 . V_451 ) ||
( V_175 . V_493 > 120 ) ) ;
V_297 = V_458 -> V_475 [ 0 ] . V_477 ;
V_334 = V_458 -> V_475 [ 0 ] . V_476 ;
if ( V_462 )
V_334 = V_458 -> V_475
[ V_458 -> V_471 - 1 ] . V_476 ;
if ( V_297 < V_461 . V_414 )
V_297 = ( V_461 . V_414 > V_464 -> V_297 ) ?
V_464 -> V_297 : V_461 . V_414 ;
if ( V_334 < V_461 . V_415 )
V_334 = ( V_461 . V_415 > V_464 -> V_334 ) ?
V_464 -> V_334 : V_461 . V_415 ;
V_458 -> V_475 [ 0 ] . V_477 = V_297 ;
V_458 -> V_475 [ 0 ] . V_476 = V_334 ;
V_458 -> V_475 [ 1 ] . V_477 =
( V_458 -> V_475 [ 1 ] . V_477 >=
V_458 -> V_475 [ 0 ] . V_477 ) ?
V_458 -> V_475 [ 1 ] . V_477 :
V_458 -> V_475 [ 0 ] . V_477 ;
if ( V_462 ) {
if ( V_334 < V_458 -> V_475 [ 1 ] . V_476 )
V_334 = V_458 -> V_475 [ 1 ] . V_476 ;
V_458 -> V_475 [ 0 ] . V_476 = V_334 ;
V_458 -> V_475 [ 1 ] . V_476 = V_334 ;
} else {
if ( V_458 -> V_475 [ 1 ] . V_476 <
V_458 -> V_475 [ 0 ] . V_476 )
V_458 -> V_475 [ 1 ] . V_476 =
V_458 -> V_475 [ 0 ] . V_476 ;
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_485 ) ) {
for ( V_34 = 0 ; V_34 < V_458 -> V_471 ; V_34 ++ ) {
V_458 -> V_475 [ V_34 ] . V_477 = V_465 ;
V_458 -> V_475 [ V_34 ] . V_476 = V_466 ;
V_458 -> V_475 [ V_34 ] . V_494 = V_24 -> V_132 . V_282 ;
V_458 -> V_475 [ V_34 ] . V_495 = V_24 -> V_132 . V_282 ;
}
}
return 0 ;
}
static int F_147 ( struct V_4 * V_5 , bool V_496 )
{
struct V_455 * V_497 ;
struct V_1 * V_458 ;
if ( V_5 == NULL )
return - V_120 ;
V_497 = V_5 -> V_456 ;
if ( V_497 == NULL )
return - V_120 ;
V_458 = F_1 ( & V_497 -> V_459 ) ;
if ( V_496 )
return V_458 -> V_475 [ 0 ] . V_476 ;
else
return V_458 -> V_475
[ V_458 -> V_471 - 1 ] . V_476 ;
}
static int F_148 ( struct V_4 * V_5 , bool V_496 )
{
struct V_455 * V_497 ;
struct V_1 * V_458 ;
if ( V_5 == NULL )
return - V_120 ;
V_497 = V_5 -> V_456 ;
if ( V_497 == NULL )
return - V_120 ;
V_458 = F_1 ( & V_497 -> V_459 ) ;
if ( V_496 )
return V_458 -> V_475 [ 0 ] . V_477 ;
else
return V_458 -> V_475
[ V_458 -> V_471 - 1 ] . V_477 ;
}
static int F_149 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_497 = (struct V_1 * ) V_3 ;
T_9 * V_498 ;
T_1 V_286 ;
T_5 V_499 , V_500 ;
int V_308 = F_150 ( V_501 , V_502 ) ;
V_498 = ( T_9 * ) F_151 (
V_5 -> V_6 , V_308 ,
& V_286 , & V_499 , & V_500 ) ;
if ( ! V_498 )
return 0 ;
V_24 -> V_503 . V_504 =
F_152 ( V_498 -> V_505 ) ;
V_24 -> V_503 . V_506 =
F_152 ( V_498 -> V_507 ) ;
V_24 -> V_503 . V_508 =
F_153 ( V_498 -> V_509 ) ;
V_24 -> V_503 . V_510 =
F_153 ( V_498 -> V_511 ) ;
V_24 -> V_503 . V_512 =
F_153 ( V_498 -> V_513 ) ;
V_24 -> V_503 . V_514 =
F_7 ( V_5 ) ;
V_24 -> V_503 . V_515 =
( T_1 ) F_10 ( V_5 ) ;
V_497 -> V_475 [ 0 ] . V_476 = V_24 -> V_503 . V_506 ;
V_497 -> V_475 [ 0 ] . V_477 = V_24 -> V_503 . V_504 ;
V_497 -> V_475 [ 0 ] . V_494 = V_24 -> V_503 . V_514 ;
V_497 -> V_475 [ 0 ] . V_495 = V_24 -> V_503 . V_515 ;
return 0 ;
}
static int F_154 ( struct V_4 * V_5 )
{
int V_45 ;
unsigned long V_435 = 0 ;
if ( V_5 -> V_53 == V_56 ) {
V_45 = F_155 ( V_5 , & V_435 ) ;
return V_45 ? 0 : V_435 ;
} else if ( V_5 -> V_53 == V_54 ) {
V_45 = F_156 ( V_5 ) ;
return V_45 ;
}
return 0 ;
}
static int F_157 ( struct V_4 * V_5 ,
void * V_516 , struct V_455 * V_517 ,
void * V_518 , T_2 V_519 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_1 =
(struct V_1 * ) ( & ( V_517 -> V_459 ) ) ;
struct V_520 * V_521 ;
T_10 * V_522 = ( T_10 * ) V_516 ;
T_11 * V_523 =
( T_11 * ) V_518 ;
T_12 * V_524 =
( T_12 * )
( ( ( unsigned long ) V_523 ) +
F_153 ( V_523 -> V_525 ) ) ;
T_13 * V_526 =
( T_13 * )
( ( ( unsigned long ) V_523 ) +
F_153 ( V_523 -> V_527 ) ) ;
V_517 -> V_469 . V_470 =
( F_153 ( V_522 -> V_528 ) &
V_529 ) >>
V_530 ;
V_517 -> V_469 . V_531 = V_519 ;
V_517 -> V_469 . V_532 = false ;
V_517 -> V_469 . V_533 = false ;
V_517 -> V_534 . V_535 =
( 0 != ( F_152 ( V_522 -> V_536 ) &
V_537 ) ) ;
V_517 -> V_538 . V_539 = 0 ;
V_517 -> V_540 . V_541 = false ;
V_517 -> V_540 . V_542 = false ;
V_517 -> V_540 . V_543 =
( 0 != ( F_152 ( V_522 -> V_536 ) &
V_544 ) ) ;
V_517 -> V_534 . V_545 = 0 ;
V_517 -> V_546 . V_547 = 0 ;
V_517 -> V_546 . V_548 = 0 ;
V_517 -> V_549 . V_284 = 0 ;
V_517 -> V_549 . V_282 = 0 ;
V_521 = & ( V_1 -> V_475
[ V_1 -> V_471 ++ ] ) ;
F_2 (
(smu7_power_state->performance_level_count < smum_get_mac_definition(hwmgr->smumgr, SMU_MAX_LEVELS_GRAPHICS)),
L_86 ,
return -EINVAL) ;
F_2 (
(smu7_power_state->performance_level_count <=
hwmgr->platform_descriptor.hardwareActivityPerformanceLevels),
L_87 ,
return -EINVAL) ;
V_521 -> V_476 = V_526 -> V_38
[ V_522 -> V_550 ] . V_551 ;
if ( V_524 -> V_552 == 0 )
V_521 -> V_477 = ( ( V_553 * ) V_524 ) -> V_38
[ V_522 -> V_554 ] . V_555 ;
else if ( V_524 -> V_552 == 1 )
V_521 -> V_477 = ( ( V_556 * ) V_524 ) -> V_38
[ V_522 -> V_554 ] . V_555 ;
V_521 -> V_494 = F_41 ( V_24 -> V_139 ,
V_522 -> V_557 ) ;
V_521 -> V_495 = F_42 ( V_24 -> V_141 ,
V_522 -> V_558 ) ;
V_521 = & ( V_1 -> V_475
[ V_1 -> V_471 ++ ] ) ;
V_521 -> V_476 = V_526 -> V_38
[ V_522 -> V_559 ] . V_551 ;
if ( V_524 -> V_552 == 0 )
V_521 -> V_477 = ( ( V_553 * ) V_524 ) -> V_38
[ V_522 -> V_560 ] . V_555 ;
else if ( V_524 -> V_552 == 1 )
V_521 -> V_477 = ( ( V_556 * ) V_524 ) -> V_38
[ V_522 -> V_560 ] . V_555 ;
V_521 -> V_494 = F_41 ( V_24 -> V_139 ,
V_522 -> V_561 ) ;
V_521 -> V_495 = F_42 ( V_24 -> V_141 ,
V_522 -> V_558 ) ;
return 0 ;
}
static int F_158 ( struct V_4 * V_5 ,
unsigned long V_562 , struct V_455 * V_516 )
{
int V_45 ;
struct V_1 * V_497 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_167 =
V_43 -> V_55 ;
V_516 -> V_459 . V_563 = V_564 ;
V_497 = (struct V_1 * ) ( & V_516 -> V_459 ) ;
V_45 = F_159 ( V_5 , V_562 , V_516 ,
F_157 ) ;
if ( V_167 != NULL && V_167 -> V_37 == 1 ) {
if ( V_167 -> V_38 [ 0 ] . V_161 !=
V_24 -> V_503 . V_506 )
F_63 ( L_88
L_89 ) ;
if ( V_167 -> V_38 [ 0 ] . V_335 !=
V_24 -> V_503 . V_512 )
F_63 ( L_90
L_91 ) ;
}
if ( ! V_516 -> V_534 . V_535 )
V_497 -> V_565 = true ;
if ( V_516 -> V_469 . V_531 & V_566 )
V_24 -> V_567 = V_497 -> V_475 [ 0 ] . V_494 ;
V_497 -> V_568 . V_569 = V_516 -> V_546 . V_547 ;
V_497 -> V_568 . V_570 = V_516 -> V_546 . V_548 ;
if ( ! V_45 ) {
T_2 V_34 ;
switch ( V_516 -> V_469 . V_470 ) {
case V_571 :
V_24 -> V_129 = true ;
for ( V_34 = 0 ; V_34 < V_497 -> V_471 ; V_34 ++ ) {
if ( V_24 -> V_132 . V_282 <
V_497 -> V_475 [ V_34 ] . V_494 )
V_24 -> V_132 . V_282 =
V_497 -> V_475 [ V_34 ] . V_494 ;
if ( V_24 -> V_132 . V_284 >
V_497 -> V_475 [ V_34 ] . V_494 )
V_24 -> V_132 . V_284 =
V_497 -> V_475 [ V_34 ] . V_494 ;
if ( V_24 -> V_134 . V_282 <
V_497 -> V_475 [ V_34 ] . V_495 )
V_24 -> V_134 . V_282 =
V_497 -> V_475 [ V_34 ] . V_495 ;
if ( V_24 -> V_134 . V_284 >
V_497 -> V_475 [ V_34 ] . V_495 )
V_24 -> V_134 . V_284 =
V_497 -> V_475 [ V_34 ] . V_495 ;
}
break;
case V_468 :
V_24 -> V_130 = true ;
for ( V_34 = 0 ; V_34 < V_497 -> V_471 ; V_34 ++ ) {
if ( V_24 -> V_131 . V_282 <
V_497 -> V_475 [ V_34 ] . V_494 )
V_24 -> V_131 . V_282 =
V_497 -> V_475 [ V_34 ] . V_494 ;
if ( V_24 -> V_131 . V_284 >
V_497 -> V_475 [ V_34 ] . V_494 )
V_24 -> V_131 . V_284 =
V_497 -> V_475 [ V_34 ] . V_494 ;
if ( V_24 -> V_133 . V_282 <
V_497 -> V_475 [ V_34 ] . V_495 )
V_24 -> V_133 . V_282 =
V_497 -> V_475 [ V_34 ] . V_495 ;
if ( V_24 -> V_133 . V_284 >
V_497 -> V_475 [ V_34 ] . V_495 )
V_24 -> V_133 . V_284 =
V_497 -> V_475 [ V_34 ] . V_495 ;
}
break;
default:
break;
}
}
return 0 ;
}
static int F_160 ( struct V_4 * V_5 ,
struct V_2 * V_517 ,
unsigned int V_308 , const void * V_572 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_497 = F_1 ( V_517 ) ;
const T_14 * V_573 = V_572 ;
struct V_520 * V_521 ;
T_2 V_477 , V_476 ;
T_1 V_574 ;
V_477 = V_573 -> V_575 << 16 | V_573 -> V_576 ;
V_476 = V_573 -> V_577 << 16 | V_573 -> V_578 ;
if ( ! ( V_24 -> V_579 & V_580 ) && V_476 > V_24 -> V_581 )
V_24 -> V_581 = V_476 ;
F_2 (
(ps->performance_level_count < smum_get_mac_definition(hwmgr->smumgr, SMU_MAX_LEVELS_GRAPHICS)),
L_86 ,
return -EINVAL) ;
F_2 (
(ps->performance_level_count <
hwmgr->platform_descriptor.hardwareActivityPerformanceLevels),
L_92 ,
return 0 ) ;
V_521 = & ( V_497 -> V_475
[ V_497 -> V_471 ++ ] ) ;
V_521 -> V_476 = V_476 ;
V_521 -> V_477 = V_477 ;
V_574 = V_573 -> V_582 ;
V_521 -> V_494 = F_41 ( V_24 -> V_139 , V_574 ) ;
V_521 -> V_495 = F_42 ( V_24 -> V_141 , V_573 -> V_583 ) ;
return 0 ;
}
static int F_161 ( struct V_4 * V_5 ,
unsigned long V_562 , struct V_455 * V_516 )
{
int V_45 ;
struct V_1 * V_497 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_32 * V_167 =
V_5 -> V_57 . V_62 ;
memset ( & V_516 -> V_459 , 0x00 , sizeof( struct V_2 ) ) ;
V_516 -> V_459 . V_563 = V_564 ;
V_497 = (struct V_1 * ) ( & V_516 -> V_459 ) ;
V_45 = F_162 ( V_5 , V_562 , V_516 ,
F_160 ) ;
if ( V_167 != NULL && V_167 -> V_37 == 1 ) {
if ( V_167 -> V_38 [ 0 ] . V_161 !=
V_24 -> V_503 . V_506 )
F_63 ( L_88
L_89 ) ;
if ( V_167 -> V_38 [ 0 ] . V_40 !=
V_24 -> V_503 . V_512 )
F_63 ( L_90
L_91 ) ;
}
if ( ! V_516 -> V_534 . V_535 )
V_497 -> V_565 = true ;
if ( V_516 -> V_469 . V_531 & V_566 )
V_24 -> V_567 = V_497 -> V_475 [ 0 ] . V_494 ;
V_497 -> V_568 . V_569 = V_516 -> V_546 . V_547 ;
V_497 -> V_568 . V_570 = V_516 -> V_546 . V_548 ;
if ( ! V_45 ) {
T_2 V_34 ;
switch ( V_516 -> V_469 . V_470 ) {
case V_571 :
V_24 -> V_129 = true ;
for ( V_34 = 0 ; V_34 < V_497 -> V_471 ; V_34 ++ ) {
if ( V_24 -> V_132 . V_282 <
V_497 -> V_475 [ V_34 ] . V_494 )
V_24 -> V_132 . V_282 =
V_497 -> V_475 [ V_34 ] . V_494 ;
if ( V_24 -> V_132 . V_284 >
V_497 -> V_475 [ V_34 ] . V_494 )
V_24 -> V_132 . V_284 =
V_497 -> V_475 [ V_34 ] . V_494 ;
if ( V_24 -> V_134 . V_282 <
V_497 -> V_475 [ V_34 ] . V_495 )
V_24 -> V_134 . V_282 =
V_497 -> V_475 [ V_34 ] . V_495 ;
if ( V_24 -> V_134 . V_284 >
V_497 -> V_475 [ V_34 ] . V_495 )
V_24 -> V_134 . V_284 =
V_497 -> V_475 [ V_34 ] . V_495 ;
}
break;
case V_468 :
V_24 -> V_130 = true ;
for ( V_34 = 0 ; V_34 < V_497 -> V_471 ; V_34 ++ ) {
if ( V_24 -> V_131 . V_282 <
V_497 -> V_475 [ V_34 ] . V_494 )
V_24 -> V_131 . V_282 =
V_497 -> V_475 [ V_34 ] . V_494 ;
if ( V_24 -> V_131 . V_284 >
V_497 -> V_475 [ V_34 ] . V_494 )
V_24 -> V_131 . V_284 =
V_497 -> V_475 [ V_34 ] . V_494 ;
if ( V_24 -> V_133 . V_282 <
V_497 -> V_475 [ V_34 ] . V_495 )
V_24 -> V_133 . V_282 =
V_497 -> V_475 [ V_34 ] . V_495 ;
if ( V_24 -> V_133 . V_284 >
V_497 -> V_475 [ V_34 ] . V_495 )
V_24 -> V_133 . V_284 =
V_497 -> V_475 [ V_34 ] . V_495 ;
}
break;
default:
break;
}
}
return 0 ;
}
static int F_163 ( struct V_4 * V_5 ,
unsigned long V_562 , struct V_455 * V_516 )
{
if ( V_5 -> V_53 == V_56 )
return F_161 ( V_5 , V_562 , V_516 ) ;
else if ( V_5 -> V_53 == V_54 )
return F_158 ( V_5 , V_562 , V_516 ) ;
return 0 ;
}
static int F_164 ( struct V_4 * V_5 ,
struct V_584 * V_585 )
{
F_2 (!smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_PmStatusLogStart),
L_93 ,
return -1 ) ;
F_165 ( 20 ) ;
F_2 (!smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_PmStatusLogSample),
L_94 ,
return -1 ) ;
V_585 -> V_586 = F_8 ( V_5 -> V_6 ,
V_28 ,
V_587 ) ;
V_585 -> V_588 = F_8 ( V_5 -> V_6 ,
V_28 ,
V_589 ) ;
V_585 -> V_590 = F_8 ( V_5 -> V_6 ,
V_28 ,
V_591 ) ;
V_585 -> V_592 = F_8 ( V_5 -> V_6 ,
V_28 ,
V_593 ) ;
return 0 ;
}
static int F_166 ( struct V_4 * V_5 , int V_594 ,
void * V_39 , int * V_286 )
{
T_2 V_297 , V_334 , V_595 ;
T_2 V_596 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( * V_286 < 4 )
return - V_120 ;
switch ( V_594 ) {
case V_597 :
F_14 ( V_5 -> V_21 , V_598 ) ;
V_297 = F_6 ( V_5 -> V_6 , V_599 ) ;
* ( ( T_2 * ) V_39 ) = V_297 ;
* V_286 = 4 ;
return 0 ;
case V_600 :
F_14 ( V_5 -> V_21 , V_601 ) ;
V_334 = F_6 ( V_5 -> V_6 , V_599 ) ;
* ( ( T_2 * ) V_39 ) = V_334 ;
* V_286 = 4 ;
return 0 ;
case V_602 :
V_596 = V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_603 ) ;
V_595 = F_8 ( V_5 -> V_6 , V_28 , V_596 ) ;
V_595 += 0x80 ;
V_595 >>= 8 ;
* ( ( T_2 * ) V_39 ) = V_595 > 100 ? 100 : V_595 ;
* V_286 = 4 ;
return 0 ;
case V_604 :
* ( ( T_2 * ) V_39 ) = F_167 ( V_5 ) ;
* V_286 = 4 ;
return 0 ;
case V_605 :
* ( ( T_2 * ) V_39 ) = V_24 -> V_606 ? 0 : 1 ;
* V_286 = 4 ;
return 0 ;
case V_607 :
* ( ( T_2 * ) V_39 ) = V_24 -> V_608 ? 0 : 1 ;
* V_286 = 4 ;
return 0 ;
case V_609 :
if ( * V_286 < sizeof( struct V_584 ) )
return - V_120 ;
* V_286 = sizeof( struct V_584 ) ;
return F_164 ( V_5 , (struct V_584 * ) V_39 ) ;
default:
return - V_120 ;
}
}
static int F_168 ( struct V_4 * V_5 , const void * V_610 )
{
const struct V_611 * V_612 =
( const struct V_611 * ) V_610 ;
const struct V_1 * V_458 =
F_3 ( V_612 -> V_613 ) ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_614 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
T_2 V_297 = V_458 -> V_475
[ V_458 -> V_471 - 1 ] . V_477 ;
struct V_614 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
T_2 V_334 = V_458 -> V_475
[ V_458 -> V_471 - 1 ] . V_476 ;
struct V_460 V_615 = { 0 } ;
T_2 V_34 ;
struct V_172 V_173 = { 0 } ;
V_24 -> V_616 = 0 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ ) {
if ( V_297 == V_147 -> V_160 [ V_34 ] . V_39 )
break;
}
if ( V_34 >= V_147 -> V_37 )
V_24 -> V_616 |= V_617 ;
else {
if ( V_24 -> V_618 . V_619 != V_615 . V_620 &&
( V_615 . V_620 >= V_621 ||
V_24 -> V_618 . V_619 >= V_621 ) )
V_24 -> V_616 |= V_622 ;
}
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ ) {
if ( V_334 == V_149 -> V_160 [ V_34 ] . V_39 )
break;
}
if ( V_34 >= V_149 -> V_37 )
V_24 -> V_616 |= V_623 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
if ( V_24 -> V_618 . V_624 != V_173 . V_492 )
V_24 -> V_616 |= V_625 ;
return 0 ;
}
static T_1 F_169 ( struct V_4 * V_5 ,
const struct V_1 * V_458 )
{
T_2 V_34 ;
T_2 V_297 , V_626 = 0 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_170 * V_136 = & V_24 -> V_136 ;
for ( V_34 = 0 ; V_34 < V_458 -> V_471 ; V_34 ++ ) {
V_297 = V_458 -> V_475 [ V_34 ] . V_477 ;
if ( V_626 < V_297 )
V_626 = V_297 ;
}
for ( V_34 = 0 ; V_34 < V_136 -> V_147 . V_37 ; V_34 ++ ) {
if ( V_136 -> V_147 . V_160 [ V_34 ] . V_39 == V_626 )
return ( T_1 ) ( ( V_34 >= V_136 -> V_137 . V_37 ) ?
V_136 -> V_137 . V_160
[ V_136 -> V_137 . V_37 - 1 ] . V_39 :
V_136 -> V_137 . V_160 [ V_34 ] . V_39 ) ;
}
return 0 ;
}
static int F_170 (
struct V_4 * V_5 , const void * V_610 )
{
const struct V_611 * V_612 =
( const struct V_611 * ) V_610 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_627 =
F_3 ( V_612 -> V_613 ) ;
const struct V_1 * V_628 =
F_3 ( V_612 -> V_629 ) ;
T_1 V_630 = F_169 ( V_5 , V_627 ) ;
T_1 V_631 ;
if ( V_24 -> V_262 == V_263 )
V_631 = F_169 ( V_5 , V_628 ) ;
else
V_631 = V_24 -> V_262 ;
V_24 -> V_262 = V_263 ;
V_24 -> V_632 = false ;
if ( V_630 > V_631 ) {
switch ( V_630 ) {
case V_285 :
if ( 0 == F_171 ( V_5 -> V_6 , V_633 , false ) )
break;
V_24 -> V_262 = V_634 ;
if ( V_631 == V_634 )
break;
case V_634 :
if ( 0 == F_171 ( V_5 -> V_6 , V_635 , false ) )
break;
default:
V_24 -> V_262 = F_7 ( V_5 ) ;
break;
}
} else {
if ( V_630 < V_631 )
V_24 -> V_632 = true ;
}
return 0 ;
}
static int F_172 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( 0 == V_24 -> V_616 )
return 0 ;
if ( ( 0 == V_24 -> V_199 ) &&
( V_24 -> V_616 &
( V_617 + V_622 ) ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_95 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_FreezeLevel),
L_96 ,
return -EINVAL) ;
}
if ( ( 0 == V_24 -> V_200 ) &&
( V_24 -> V_616 &
V_623 ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_97 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_MCLKDPM_FreezeLevel),
L_98 ,
return -EINVAL) ;
}
return 0 ;
}
static int F_173 (
struct V_4 * V_5 , const void * V_610 )
{
int V_45 = 0 ;
const struct V_611 * V_612 =
( const struct V_611 * ) V_610 ;
const struct V_1 * V_458 =
F_3 ( V_612 -> V_613 ) ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_297 = V_458 -> V_475
[ V_458 -> V_471 - 1 ] . V_477 ;
T_2 V_334 = V_458 -> V_475
[ V_458 -> V_471 - 1 ] . V_476 ;
struct V_170 * V_136 = & V_24 -> V_136 ;
struct V_170 * V_169 = & V_24 -> V_169 ;
T_2 V_636 , V_637 ;
T_2 V_34 ;
if ( 0 == V_24 -> V_616 )
return 0 ;
if ( V_24 -> V_616 & V_617 ) {
V_136 -> V_147 . V_160
[ V_136 -> V_147 . V_37 - 1 ] . V_39 = V_297 ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_638 ) ||
F_52 ( V_5 -> V_182 . V_183 , V_639 ) ) {
F_2 (
(golden_dpm_table->sclk_table.dpm_levels
[golden_dpm_table->sclk_table.count - 1].value != 0),
L_99 ,
return -EINVAL) ;
V_636 = V_136 -> V_147 . V_37 < 2 ? 0 : V_136 -> V_147 . V_37 - 2 ;
for ( V_34 = V_636 ; V_34 > 1 ; V_34 -- ) {
if ( V_297 > V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ) {
V_637 =
( ( V_297
- V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39
) * 100 )
/ V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ;
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 +
( V_169 -> V_147 . V_160 [ V_34 ] . V_39 *
V_637 ) / 100 ;
} else if ( V_169 -> V_147 . V_160 [ V_136 -> V_147 . V_37 - 1 ] . V_39 > V_297 ) {
V_637 =
( ( V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39
- V_297 ) * 100 )
/ V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ;
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 -
( V_169 -> V_147 . V_160 [ V_34 ] . V_39 *
V_637 ) / 100 ;
} else
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 ;
}
}
}
if ( V_24 -> V_616 & V_623 ) {
V_136 -> V_149 . V_160
[ V_136 -> V_149 . V_37 - 1 ] . V_39 = V_334 ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_638 ) ||
F_52 ( V_5 -> V_182 . V_183 , V_639 ) ) {
F_2 (
(golden_dpm_table->mclk_table.dpm_levels
[golden_dpm_table->mclk_table.count-1].value != 0),
L_99 ,
return -EINVAL) ;
V_636 = V_136 -> V_149 . V_37 < 2 ? 0 : V_136 -> V_149 . V_37 - 2 ;
for ( V_34 = V_636 ; V_34 > 1 ; V_34 -- ) {
if ( V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 < V_334 ) {
V_637 = ( ( V_334 -
V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ) * 100 )
/ V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 +
( V_169 -> V_149 . V_160 [ V_34 ] . V_39 *
V_637 ) / 100 ;
} else if ( V_169 -> V_149 . V_160 [ V_136 -> V_149 . V_37 - 1 ] . V_39 > V_334 ) {
V_637 = (
( V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 - V_334 )
* 100 )
/ V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 -
( V_169 -> V_149 . V_160 [ V_34 ] . V_39 *
V_637 ) / 100 ;
} else
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 ;
}
}
}
if ( V_24 -> V_616 &
( V_617 + V_622 ) ) {
V_45 = F_174 ( V_5 ) ;
F_2 ((0 == result),
L_100 ,
return result) ;
}
if ( V_24 -> V_616 &
( V_623 + V_625 ) ) {
V_45 = F_175 ( V_5 ) ;
F_2 ((0 == result),
L_101 ,
return result) ;
}
return V_45 ;
}
static int F_176 ( struct V_4 * V_5 ,
struct V_614 * V_136 ,
T_2 V_640 , T_2 V_641 )
{
T_2 V_34 ;
for ( V_34 = 0 ; V_34 < V_136 -> V_37 ; V_34 ++ ) {
if ( ( V_136 -> V_160 [ V_34 ] . V_39 < V_640 )
|| ( V_136 -> V_160 [ V_34 ] . V_39 > V_641 ) )
V_136 -> V_160 [ V_34 ] . V_162 = false ;
else
V_136 -> V_160 [ V_34 ] . V_162 = true ;
}
return 0 ;
}
static int F_177 ( struct V_4 * V_5 ,
const struct V_1 * V_458 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_642 ;
F_2 ((smu7_ps->performance_level_count >= 1),
L_102 ,
return -EINVAL) ;
V_642 = ( 1 == V_458 -> V_471 ) ? 0 : 1 ;
F_176 ( V_5 ,
& ( V_24 -> V_136 . V_147 ) ,
V_458 -> V_475 [ 0 ] . V_477 ,
V_458 -> V_475 [ V_642 ] . V_477 ) ;
F_176 ( V_5 ,
& ( V_24 -> V_136 . V_149 ) ,
V_458 -> V_475 [ 0 ] . V_476 ,
V_458 -> V_475 [ V_642 ] . V_476 ) ;
return 0 ;
}
static int F_178 (
struct V_4 * V_5 , const void * V_610 )
{
int V_45 ;
const struct V_611 * V_612 =
( const struct V_611 * ) V_610 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_458 =
F_3 ( V_612 -> V_613 ) ;
V_45 = F_177 ( V_5 , V_458 ) ;
if ( V_45 )
return V_45 ;
V_24 -> V_417 . V_420 =
F_179 ( & V_24 -> V_136 . V_147 ) ;
V_24 -> V_417 . V_422 =
F_179 ( & V_24 -> V_136 . V_149 ) ;
V_24 -> V_417 . V_418 =
F_179 ( & V_24 -> V_136 . V_137 ) ;
return 0 ;
}
static int F_180 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( 0 == V_24 -> V_616 )
return 0 ;
if ( ( 0 == V_24 -> V_199 ) &&
( V_24 -> V_616 &
( V_617 + V_622 ) ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_103 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_UnfreezeLevel),
L_104 ,
return -EINVAL) ;
}
if ( ( 0 == V_24 -> V_200 ) &&
( V_24 -> V_616 & V_623 ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_105 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_UnfreezeLevel),
L_106 ,
return -EINVAL) ;
}
V_24 -> V_616 = 0 ;
return 0 ;
}
static int F_181 (
struct V_4 * V_5 , const void * V_610 )
{
const struct V_611 * V_612 =
( const struct V_611 * ) V_610 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_458 =
F_3 ( V_612 -> V_613 ) ;
T_1 V_630 = F_169 ( V_5 , V_458 ) ;
T_5 V_643 ;
if ( V_24 -> V_632 ) {
if ( V_630 == V_285 )
V_643 = V_633 ;
else if ( V_630 == V_634 )
V_643 = V_635 ;
else
V_643 = V_644 ;
if ( V_643 == V_644 &&
F_7 ( V_5 ) > 0 )
return 0 ;
if ( F_171 ( V_5 -> V_6 , V_643 , false ) ) {
if ( V_634 == V_630 )
F_96 ( L_107 ) ;
else
F_96 ( L_108 ) ;
}
}
return 0 ;
}
static int F_182 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_5 -> V_19 & V_645 )
F_132 ( V_5 -> V_21 ,
( V_236 ) V_646 , V_24 -> V_647 ) ;
return ( F_14 ( V_5 -> V_21 , ( V_236 ) V_648 ) == 0 ) ? 0 : - V_120 ;
}
static int F_183 ( struct V_4 * V_5 , const void * V_610 )
{
int V_233 , V_45 = 0 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_233 = F_168 ( V_5 , V_610 ) ;
F_2 ( ( 0 == V_233 ) ,
L_109 ,
V_45 = V_233 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_649 ) ) {
V_233 =
F_170 ( V_5 , V_610 ) ;
F_2 ( ( 0 == V_233 ) ,
L_110 ,
V_45 = V_233 ) ;
}
V_233 = F_172 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_111 , V_45 = V_233 ) ;
V_233 = F_173 ( V_5 , V_610 ) ;
F_2 ( ( 0 == V_233 ) ,
L_112 ,
V_45 = V_233 ) ;
V_233 = F_178 ( V_5 , V_610 ) ;
F_2 ( ( 0 == V_233 ) ,
L_113 ,
V_45 = V_233 ) ;
V_233 = F_184 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_114 ,
V_45 = V_233 ) ;
V_233 = F_182 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_115 ,
V_45 = V_233 ) ;
V_233 = F_180 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_116 ,
V_45 = V_233 ) ;
V_233 = F_133 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_117 ,
V_45 = V_233 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_649 ) ) {
V_233 =
F_181 ( V_5 , V_610 ) ;
F_2 ( ( 0 == V_233 ) ,
L_118 ,
V_45 = V_233 ) ;
}
V_24 -> V_650 = false ;
return V_45 ;
}
static int F_185 ( struct V_4 * V_5 , T_1 V_651 )
{
V_5 -> V_355 .
V_356 . V_369 = V_651 ;
if ( F_186 ( V_5 ) )
return 0 ;
return F_132 ( V_5 -> V_21 ,
V_652 , V_651 ) ;
}
static int
F_187 ( struct V_4 * V_5 , bool V_653 )
{
V_236 V_654 = V_653 ? ( V_236 ) V_648 : ( V_236 ) V_237 ;
return ( F_14 ( V_5 -> V_21 , V_654 ) == 0 ) ? 0 : - 1 ;
}
static int
F_188 ( struct V_4 * V_5 )
{
T_2 V_655 = 0 ;
struct V_172 V_173 = { 0 } ;
V_173 . V_175 = NULL ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_655 = V_173 . V_492 ;
if ( V_655 > 1 && V_5 -> V_482 . V_656 != true )
F_187 ( V_5 , false ) ;
return 0 ;
}
static int F_189 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_655 = 0 ;
T_2 V_79 = F_8 ( V_5 -> V_6 , V_28 , V_80 ) ;
T_2 V_657 ;
T_2 V_658 ;
T_2 V_659 ;
T_2 V_179 ;
T_2 V_493 = 0 ;
struct V_172 V_173 = { 0 } ;
struct V_174 V_175 = { 0 } ;
V_173 . V_175 = & V_175 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_655 = V_173 . V_492 ;
V_79 = F_28 ( V_79 , V_81 , V_82 , ( V_655 > 0 ) ? V_660 : V_83 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_80 , V_79 ) ;
V_179 = V_175 . V_179 ;
V_493 = V_175 . V_493 ;
if ( 0 == V_493 )
V_493 = 60 ;
V_659 = 1000000 / V_493 ;
V_658 = V_659 - 200 - V_175 . V_451 ;
V_24 -> V_647 = V_659 * 2 / 100 ;
V_657 = V_658 * ( V_179 / 100 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_661 , V_657 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_662 ) , 0x64 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_663 ) ,
( V_659 - V_658 ) ) ;
return 0 ;
}
static int F_190 ( struct V_4 * V_5 )
{
return F_189 ( V_5 ) ;
}
static int F_191 ( struct V_4 * V_5 , T_1 V_664 )
{
V_5 -> V_355 .
V_356 . V_370 = V_664 ;
if ( F_186 ( V_5 ) )
return 0 ;
return F_132 ( V_5 -> V_21 ,
V_665 , V_664 ) ;
}
static int F_192 ( struct V_4 * V_5 ,
const void * V_666 )
{
return 0 ;
}
static bool
F_193 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
bool V_667 = false ;
struct V_172 V_173 = { 0 , 0 , NULL } ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
if ( V_24 -> V_618 . V_624 != V_173 . V_492 )
V_667 = true ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_190 ) ) {
if ( V_24 -> V_618 . V_619 != V_5 -> V_482 . V_668 &&
( V_24 -> V_618 . V_619 >= V_621 ||
V_5 -> V_482 . V_668 >= V_621 ) )
V_667 = true ;
}
return V_667 ;
}
static inline bool F_194 ( const struct V_520 * V_669 ,
const struct V_520 * V_670 )
{
return ( ( V_669 -> V_476 == V_670 -> V_476 ) &&
( V_669 -> V_477 == V_670 -> V_477 ) &&
( V_669 -> V_494 == V_670 -> V_494 ) &&
( V_669 -> V_495 == V_670 -> V_495 ) ) ;
}
static int F_195 ( struct V_4 * V_5 ,
const struct V_2 * V_671 ,
const struct V_2 * V_672 , bool * V_673 )
{
const struct V_1 * V_674 ;
const struct V_1 * V_675 ;
int V_34 ;
if ( V_671 == NULL || V_672 == NULL || V_673 == NULL )
return - V_120 ;
V_674 = F_3 ( V_671 ) ;
V_675 = F_3 ( V_672 ) ;
if ( V_674 -> V_471 != V_675 -> V_471 ) {
* V_673 = false ;
return 0 ;
}
for ( V_34 = 0 ; V_34 < V_674 -> V_471 ; V_34 ++ ) {
if ( ! F_194 ( & ( V_674 -> V_475 [ V_34 ] ) , & ( V_675 -> V_475 [ V_34 ] ) ) ) {
* V_673 = false ;
return 0 ;
}
}
* V_673 = ( ( V_674 -> V_568 . V_569 == V_675 -> V_568 . V_569 ) && ( V_674 -> V_568 . V_570 == V_675 -> V_568 . V_570 ) ) ;
* V_673 &= ( ( V_674 -> V_478 . V_479 == V_675 -> V_478 . V_479 ) && ( V_674 -> V_478 . V_481 == V_675 -> V_478 . V_481 ) ) ;
* V_673 &= ( V_674 -> V_487 == V_675 -> V_487 ) ;
return 0 ;
}
static int F_196 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_676 ;
T_2 V_46 ;
F_4 ( V_5 ) ;
V_676 = V_5 -> V_8 . V_9 & 0xf ;
V_24 -> V_677 = false ;
F_5 ( V_5 -> V_6 , V_7 ,
V_678 ) ;
V_46 = F_6 ( V_5 -> V_6 , V_10 ) ;
if ( V_46 & ( 1 << 23 ) ) {
V_24 -> V_679 = V_680 ;
V_24 -> V_681 = V_682 ;
} else {
V_24 -> V_679 = 330 ;
V_24 -> V_681 = 330 ;
}
return 0 ;
}
static int F_197 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_683 . V_684 =
F_8 ( V_5 -> V_6 , V_28 , V_685 ) ;
V_24 -> V_683 . V_686 =
F_8 ( V_5 -> V_6 , V_28 , V_687 ) ;
V_24 -> V_683 . V_688 =
F_8 ( V_5 -> V_6 , V_28 , V_689 ) ;
V_24 -> V_683 . V_690 =
F_8 ( V_5 -> V_6 , V_28 , V_691 ) ;
V_24 -> V_683 . V_692 =
F_8 ( V_5 -> V_6 , V_28 , V_693 ) ;
V_24 -> V_683 . V_694 =
F_8 ( V_5 -> V_6 , V_28 , V_695 ) ;
V_24 -> V_683 . V_696 =
F_6 ( V_5 -> V_6 , V_697 ) ;
V_24 -> V_683 . V_698 =
F_6 ( V_5 -> V_6 , V_699 ) ;
V_24 -> V_683 . V_700 =
F_6 ( V_5 -> V_6 , V_701 ) ;
V_24 -> V_683 . V_702 =
F_6 ( V_5 -> V_6 , V_703 ) ;
V_24 -> V_683 . V_704 =
F_6 ( V_5 -> V_6 , V_705 ) ;
V_24 -> V_683 . V_706 =
F_6 ( V_5 -> V_6 , V_707 ) ;
V_24 -> V_683 . V_708 =
F_6 ( V_5 -> V_6 , V_709 ) ;
V_24 -> V_683 . V_710 =
F_6 ( V_5 -> V_6 , V_711 ) ;
V_24 -> V_683 . V_712 =
F_6 ( V_5 -> V_6 , V_713 ) ;
return 0 ;
}
static int F_198 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_714 ;
V_714 = F_6 ( V_5 -> V_6 , V_715 ) ;
V_24 -> V_454 = ( V_716 ==
( ( V_714 & V_717 ) >>
V_718 ) ) ;
return 0 ;
}
static int F_199 ( struct V_4 * V_5 )
{
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_719 , 1 ) ;
return 0 ;
}
static int F_200 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_606 = false ;
V_24 -> V_608 = false ;
V_24 -> V_720 = false ;
return 0 ;
}
static int F_201 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_721 = 0 ;
return 0 ;
}
static int F_202 ( struct V_4 * V_5 )
{
int V_233 , V_45 = 0 ;
F_196 ( V_5 ) ;
V_233 = F_197 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_119 , V_45 = V_233 ) ;
V_233 = F_198 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_120 , V_45 = V_233 ) ;
V_233 = F_199 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_121 , V_45 = V_233 ) ;
V_233 = F_200 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_122 , V_45 = V_233 ) ;
V_233 = F_4 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_123 , V_45 = V_233 ) ;
V_233 = F_201 ( V_5 ) ;
F_2 ( ( 0 == V_233 ) ,
L_124 , V_45 = V_233 ) ;
return V_45 ;
}
static int F_141 ( struct V_4 * V_5 ,
enum V_722 type , T_2 V_723 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_5 -> V_438 & ( V_446 |
V_445 |
V_444 ) )
return - V_120 ;
switch ( type ) {
case V_447 :
if ( ! V_24 -> V_199 )
F_132 ( V_5 -> V_21 ,
V_421 ,
V_24 -> V_417 . V_420 & V_723 ) ;
break;
case V_448 :
if ( ! V_24 -> V_200 )
F_132 ( V_5 -> V_21 ,
V_423 ,
V_24 -> V_417 . V_422 & V_723 ) ;
break;
case V_449 :
{
T_2 V_46 = V_723 & V_24 -> V_417 . V_418 ;
T_2 V_416 = 0 ;
while ( V_46 >>= 1 )
V_416 ++ ;
if ( ! V_24 -> V_212 )
F_132 ( V_5 -> V_21 ,
V_419 ,
V_416 ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_203 ( struct V_4 * V_5 ,
enum V_722 type , char * V_724 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_614 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
struct V_614 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
struct V_614 * V_127 = & ( V_24 -> V_136 . V_137 ) ;
int V_34 , V_725 , V_286 = 0 ;
T_2 clock , V_726 ;
switch ( type ) {
case V_447 :
F_14 ( V_5 -> V_21 , V_598 ) ;
clock = F_6 ( V_5 -> V_6 , V_599 ) ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ ) {
if ( clock > V_147 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_725 = V_34 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ )
V_286 += sprintf ( V_724 + V_286 , L_125 ,
V_34 , V_147 -> V_160 [ V_34 ] . V_39 / 100 ,
( V_34 == V_725 ) ? L_126 : L_127 ) ;
break;
case V_448 :
F_14 ( V_5 -> V_21 , V_601 ) ;
clock = F_6 ( V_5 -> V_6 , V_599 ) ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ ) {
if ( clock > V_149 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_725 = V_34 ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ )
V_286 += sprintf ( V_724 + V_286 , L_125 ,
V_34 , V_149 -> V_160 [ V_34 ] . V_39 / 100 ,
( V_34 == V_725 ) ? L_126 : L_127 ) ;
break;
case V_449 :
V_726 = F_7 ( V_5 ) ;
for ( V_34 = 0 ; V_34 < V_127 -> V_37 ; V_34 ++ ) {
if ( V_726 != V_127 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_725 = V_34 ;
for ( V_34 = 0 ; V_34 < V_127 -> V_37 ; V_34 ++ )
V_286 += sprintf ( V_724 + V_286 , L_128 , V_34 ,
( V_127 -> V_160 [ V_34 ] . V_39 == 0 ) ? L_129 :
( V_127 -> V_160 [ V_34 ] . V_39 == 1 ) ? L_130 :
( V_127 -> V_160 [ V_34 ] . V_39 == 2 ) ? L_131 : L_127 ,
( V_34 == V_725 ) ? L_126 : L_127 ) ;
break;
default:
break;
}
return V_286 ;
}
static int F_204 ( struct V_4 * V_5 , T_2 V_727 )
{
int V_45 = 0 ;
switch ( V_727 ) {
case V_728 :
V_45 = F_142 ( V_5 , 100 ) ;
break;
case V_729 :
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_730 ) )
V_45 = F_205 ( V_5 ) ;
break;
case V_731 :
V_45 = F_206 ( V_5 , V_727 ) ;
if ( ! V_45 )
V_45 = F_207 ( V_5 ) ;
break;
default:
break;
}
return V_45 ;
}
static int F_208 ( struct V_4 * V_5 )
{
return V_5 -> V_732 ? V_731 : V_729 ;
}
static int F_209 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_614 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
struct V_614 * V_733 =
& ( V_24 -> V_169 . V_147 ) ;
int V_39 ;
V_39 = ( V_147 -> V_160 [ V_147 -> V_37 - 1 ] . V_39 -
V_733 -> V_160 [ V_733 -> V_37 - 1 ] . V_39 ) *
100 /
V_733 -> V_160 [ V_733 -> V_37 - 1 ] . V_39 ;
return V_39 ;
}
static int F_210 ( struct V_4 * V_5 , T_2 V_39 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_614 * V_733 =
& ( V_24 -> V_169 . V_147 ) ;
struct V_455 * V_497 ;
struct V_1 * V_458 ;
if ( V_39 > 20 )
V_39 = 20 ;
V_497 = V_5 -> V_456 ;
if ( V_497 == NULL )
return - V_120 ;
V_458 = F_1 ( & V_497 -> V_459 ) ;
V_458 -> V_475 [ V_458 -> V_471 - 1 ] . V_477 =
V_733 -> V_160 [ V_733 -> V_37 - 1 ] . V_39 *
V_39 / 100 +
V_733 -> V_160 [ V_733 -> V_37 - 1 ] . V_39 ;
return 0 ;
}
static int F_211 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_614 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
struct V_614 * V_734 =
& ( V_24 -> V_169 . V_149 ) ;
int V_39 ;
V_39 = ( V_149 -> V_160 [ V_149 -> V_37 - 1 ] . V_39 -
V_734 -> V_160 [ V_734 -> V_37 - 1 ] . V_39 ) *
100 /
V_734 -> V_160 [ V_734 -> V_37 - 1 ] . V_39 ;
return V_39 ;
}
static int F_212 ( struct V_4 * V_5 , T_2 V_39 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_614 * V_734 =
& ( V_24 -> V_169 . V_149 ) ;
struct V_455 * V_497 ;
struct V_1 * V_458 ;
if ( V_39 > 20 )
V_39 = 20 ;
V_497 = V_5 -> V_456 ;
if ( V_497 == NULL )
return - V_120 ;
V_458 = F_1 ( & V_497 -> V_459 ) ;
V_458 -> V_475 [ V_458 -> V_471 - 1 ] . V_476 =
V_734 -> V_160 [ V_734 -> V_37 - 1 ] . V_39 *
V_39 / 100 +
V_734 -> V_160 [ V_734 -> V_37 - 1 ] . V_39 ;
return 0 ;
}
static int F_213 ( struct V_4 * V_5 , struct V_735 * V_736 )
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
V_736 -> clock [ V_34 ] = V_166 -> V_38 [ V_34 ] . V_161 ;
V_736 -> V_37 = V_166 -> V_37 ;
} else if ( V_5 -> V_53 == V_56 ) {
V_147 = V_5 -> V_57 . V_155 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ )
V_736 -> clock [ V_34 ] = V_147 -> V_38 [ V_34 ] . V_161 ;
V_736 -> V_37 = V_147 -> V_37 ;
}
return 0 ;
}
static T_2 F_214 ( struct V_4 * V_5 , T_2 V_161 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_161 >= V_737 && V_161 < V_738 )
return V_24 -> V_679 ;
else if ( V_161 >= V_738 )
return V_24 -> V_681 ;
else
return V_739 ;
}
static int F_215 ( struct V_4 * V_5 , struct V_735 * V_736 )
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
V_736 -> clock [ V_34 ] = V_167 -> V_38 [ V_34 ] . V_161 ;
V_736 -> V_740 [ V_34 ] = F_214 ( V_5 ,
V_167 -> V_38 [ V_34 ] . V_161 ) ;
}
V_736 -> V_37 = V_167 -> V_37 ;
} else if ( V_5 -> V_53 == V_56 ) {
V_149 = V_5 -> V_57 . V_68 ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ )
V_736 -> clock [ V_34 ] = V_149 -> V_38 [ V_34 ] . V_161 ;
V_736 -> V_37 = V_149 -> V_37 ;
}
return 0 ;
}
static int F_216 ( struct V_4 * V_5 , enum V_741 type ,
struct V_735 * V_736 )
{
switch ( type ) {
case V_742 :
F_213 ( V_5 , V_736 ) ;
break;
case V_743 :
F_215 ( V_5 , V_736 ) ;
break;
default:
return - V_120 ;
}
return 0 ;
}
static void F_217 ( struct V_4 * V_5 ,
T_2 * V_426 , T_2 * V_427 ,
T_2 V_744 , T_2 V_745 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_170 * V_136 = & ( V_24 -> V_136 ) ;
T_2 V_34 ;
for ( V_34 = 0 ; V_34 < V_136 -> V_147 . V_37 ; V_34 ++ ) {
if ( V_136 -> V_147 . V_160 [ V_34 ] . V_162 &&
V_136 -> V_147 . V_160 [ V_34 ] . V_39 >= V_744 )
* V_426 |= 1 << V_34 ;
}
for ( V_34 = 0 ; V_34 < V_136 -> V_149 . V_37 ; V_34 ++ ) {
if ( V_136 -> V_149 . V_160 [ V_34 ] . V_162 &&
V_136 -> V_149 . V_160 [ V_34 ] . V_39 >= V_745 )
* V_427 |= 1 << V_34 ;
}
}
static int F_218 ( struct V_4 * V_5 ,
struct V_746 * V_643 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
int V_233 , V_45 = 0 ;
T_2 V_426 = 0 , V_427 = 0 ;
if ( V_5 -> V_265 == V_747 ) {
if ( V_643 -> type == V_748 )
F_79 ( V_5 ) ;
else if ( V_643 -> type == V_749 )
F_82 ( V_5 ) ;
}
if ( V_5 -> V_438 != V_446 )
return - V_120 ;
V_233 = F_172 ( V_5 ) ;
F_2 ( ! V_233 ,
L_111 ,
V_45 = V_233 ) ;
V_233 = F_219 ( V_5 , V_643 ) ;
F_2 ( ! V_233 ,
L_132 ,
V_45 = V_233 ) ;
V_233 = F_180 ( V_5 ) ;
F_2 ( ! V_233 ,
L_116 ,
V_45 = V_233 ) ;
F_217 ( V_5 , & V_426 , & V_427 ,
V_643 -> V_744 , V_643 -> V_745 ) ;
if ( V_426 ) {
if ( ! V_24 -> V_199 )
F_132 ( V_5 -> V_21 ,
V_421 ,
V_24 -> V_417 .
V_420 &
V_426 ) ;
}
if ( V_427 ) {
if ( ! V_24 -> V_200 )
F_132 ( V_5 -> V_21 ,
V_423 ,
V_24 -> V_417 .
V_422 &
V_427 ) ;
}
return V_45 ;
}
static int F_85 ( struct V_4 * V_5 , bool V_750 )
{
struct V_751 * V_21 = (struct V_751 * ) ( V_5 -> V_21 ) ;
struct V_752 * V_753 = (struct V_752 * ) ( V_21 -> V_25 ) ;
if ( V_753 == NULL )
return - V_120 ;
if ( V_753 -> V_754 . V_755 == V_756 )
return 0 ;
if ( V_750 ) {
if ( ! F_49 ( V_5 -> V_6 ,
V_28 , V_757 , V_758 ) )
F_2 (!smum_send_msg_to_smc(
hwmgr->smumgr, PPSMC_MSG_EnableAvfs),
L_133 ,
return -EINVAL) ;
} else if ( F_49 ( V_5 -> V_6 ,
V_28 , V_757 , V_758 ) )
F_2 (!smum_send_msg_to_smc(
hwmgr->smumgr, PPSMC_MSG_DisableAvfs),
L_60 ,
return -EINVAL) ;
return 0 ;
}
T_5 F_220 ( T_2 clock ,
T_2 V_759 )
{
T_5 V_34 ;
T_2 V_714 ;
T_2 V_284 = V_282 ( V_759 , ( T_2 ) V_621 ) ;
F_2 ((clock >= min), L_134 , return 0 ) ;
for ( V_34 = V_760 ; ; V_34 -- ) {
V_714 = clock >> V_34 ;
if ( V_714 >= V_284 || V_34 == 0 )
break;
}
return V_34 ;
}
int F_221 ( struct V_4 * V_5 )
{
int V_435 = 0 ;
V_5 -> V_761 = & V_762 ;
if ( V_5 -> V_53 == V_56 )
V_5 -> V_763 = & V_764 ;
else if ( V_5 -> V_53 == V_54 )
V_5 -> V_763 = & V_765 ;
return V_435 ;
}
