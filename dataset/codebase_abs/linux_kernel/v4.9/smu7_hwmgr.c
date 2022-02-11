struct V_1 * F_1 (
struct V_2 * V_3 )
{
F_2 ((PhwVIslands_Magic == hw_ps->magic),
L_1 ,
return NULL) ;
return (struct V_1 * ) V_3 ;
}
const struct V_1 * F_3 (
const struct V_2 * V_3 )
{
F_2 ((PhwVIslands_Magic == hw_ps->magic),
L_1 ,
return NULL) ;
return ( const struct V_1 * ) V_3 ;
}
int F_4 ( struct V_4 * V_5 )
{
F_5 ( V_5 -> V_6 , V_7 , 0x9F ) ;
V_5 -> V_8 . V_9 = F_6 ( V_5 -> V_6 , V_10 ) ;
return 0 ;
}
T_1 F_7 ( struct V_4 * V_5 )
{
T_2 V_11 = 0 ;
V_11 = F_8 ( V_5 -> V_6 , V_12 ,
V_13 ) ;
return ( ( T_1 ) F_9 ( V_11 ,
V_14 , V_15 ) ) ;
}
int F_10 ( struct V_4 * V_5 )
{
T_2 V_16 ;
V_16 = F_11 ( V_5 -> V_6 , V_12 ,
V_17 , V_18 ) ;
F_2 ((7 >= link_width),
L_2 , return 0 ) ;
return F_12 ( V_16 ) ;
}
int F_13 ( struct V_4 * V_5 )
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
int F_47 ( struct V_4 * V_5 )
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
F_2 (
(0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_Voltage_Cntl_Enable)),
L_27 ,
return -EINVAL) ;
if ( F_60 ( V_5 ) ) {
F_63 ( V_212 L_28 ) ;
return - V_120 ;
}
if ( 0 == V_24 -> V_213 ) {
F_2 (
(0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_PCIeDPM_Enable)),
L_29 ,
return -EINVAL) ;
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_214 ) ) {
F_2 ( ( 0 == F_14 ( V_5 -> V_21 ,
V_215 ) ) ,
L_30 ,
) ;
}
return 0 ;
}
static int F_64 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( ! V_24 -> V_199 ) {
F_2 (true == smum_is_dpm_running(hwmgr),
L_31 ,
return 0 ) ;
F_14 ( V_5 -> V_21 , V_216 ) ;
}
if ( ! V_24 -> V_200 ) {
F_2 (true == smum_is_dpm_running(hwmgr),
L_32 ,
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
L_33 ,
return -EINVAL) ;
}
F_64 ( V_5 ) ;
F_2 (true == smum_is_dpm_running(hwmgr),
L_34 ,
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
F_63 ( V_212 L_35 ) ;
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
int F_71 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_233 = true ;
return 0 ;
}
int F_72 ( struct V_4 * V_5 )
{
int V_234 = 0 ;
int V_45 = 0 ;
V_234 = ( ! F_73 ( V_5 ) ) ? 0 : - 1 ;
F_2 ( V_234 == 0 ,
L_36 ,
) ;
if ( F_15 ( V_5 ) ) {
V_234 = F_16 ( V_5 ) ;
F_2 ( V_234 == 0 ,
L_37 ,
V_45 = V_234 ) ;
V_234 = F_19 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_38 ,
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
L_39 ,
V_45 = V_234 ) ;
V_234 = F_27 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_40 , V_45 = V_234 ) ;
V_234 = F_30 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_41 , V_45 = V_234 ) ;
V_234 = F_75 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_42 , V_45 = V_234 ) ;
V_234 = F_36 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_43 ,
V_45 = V_234 ) ;
V_45 = F_47 ( V_5 ) ;
F_2 ( 0 == result,
L_44 , return result) ;
V_234 = F_76 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_45 , V_45 = V_234 ) ;
V_234 = F_51 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_46 , V_45 = V_234 ) ;
F_14 ( V_5 -> V_21 , ( V_237 ) V_238 ) ;
V_234 = F_53 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_47 , V_45 = V_234 ) ;
V_234 = F_13 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_37 , V_45 = V_234 ) ;
V_234 = F_54 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_48 , V_45 = V_234 ) ;
V_234 = F_56 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_49 , V_45 = V_234 ) ;
V_234 = F_77 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_49 , V_45 = V_234 ) ;
V_234 = F_62 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_50 , V_45 = V_234 ) ;
V_234 = F_78 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_51 , V_45 = V_234 ) ;
V_234 = F_79 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_52 , V_45 = V_234 ) ;
V_234 = F_80 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_53 , V_45 = V_234 ) ;
V_234 = F_68 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_54 , V_45 = V_234 ) ;
V_234 = F_71 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_55 , V_45 = V_234 ) ;
return 0 ;
}
int F_81 ( struct V_4 * V_5 )
{
int V_234 , V_45 = 0 ;
V_234 = ( F_73 ( V_5 ) ) ? 0 : - 1 ;
F_2 (tmp_result == 0 ,
L_56 ,
return 0 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_230 ) )
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_229 , 1 ) ;
V_234 = F_82 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_57 , V_45 = V_234 ) ;
V_234 = F_83 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_58 , V_45 = V_234 ) ;
F_17 ( V_5 -> V_6 , V_28 ,
V_239 , V_240 , 0 ) ;
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_236 , 0 ) ;
V_234 = F_70 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_59 , V_45 = V_234 ) ;
if ( 1 == F_49 ( V_5 -> V_6 , V_28 , V_241 , V_242 ) ) {
F_2 ((0 == smum_send_msg_to_smc(hwmgr->smumgr, PPSMC_MSG_DisableAvfs)),
L_60 ,
return -EINVAL) ;
}
V_234 = F_65 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_61 , V_45 = V_234 ) ;
V_234 = F_57 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_62 , V_45 = V_234 ) ;
V_234 = F_55 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_63 , V_45 = V_234 ) ;
V_234 = F_31 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_64 , V_45 = V_234 ) ;
V_234 = F_35 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_65 , V_45 = V_234 ) ;
V_234 = F_37 ( V_5 ) ;
F_2 ( ( V_234 == 0 ) ,
L_66 , V_45 = V_234 ) ;
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
V_24 -> V_243 = false ;
V_24 -> V_244 = 0xa ;
V_24 -> V_245 = V_246 ;
V_24 -> V_247 = 300 ;
V_24 -> V_78 = V_248 ;
V_24 -> V_76 = V_249 ;
V_24 -> V_90 = V_250 ;
V_24 -> V_92 = V_251 ;
V_24 -> V_94 = V_252 ;
V_24 -> V_96 = V_253 ;
V_24 -> V_98 = V_254 ;
V_24 -> V_100 = V_255 ;
V_24 -> V_102 = V_256 ;
V_24 -> V_104 = V_257 ;
V_24 -> V_200 = V_5 -> V_19 & V_258 ? false : true ;
V_24 -> V_199 = V_5 -> V_19 & V_259 ? false : true ;
V_24 -> V_213 = V_5 -> V_19 & V_260 ? false : true ;
V_24 -> V_27 = V_26 ;
V_24 -> V_59 = V_26 ;
V_24 -> V_48 = V_26 ;
V_24 -> V_261 = true ;
V_24 -> V_262 = true ;
V_24 -> V_263 = V_264 ;
V_24 -> V_187 = V_5 -> V_19 & V_265 ? true : false ;
V_24 -> V_266 = 100 ;
if ( F_86 ( V_5 ,
V_66 , V_267 ) )
V_24 -> V_27 = V_52 ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_268 ) ) {
if ( F_86 ( V_5 ,
V_269 , V_267 ) ) {
V_24 -> V_63 = V_52 ;
}
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_270 ) ) {
if ( F_86 ( V_5 ,
V_49 , V_50 ) )
V_24 -> V_48 = V_47 ;
else if ( F_86 ( V_5 ,
V_49 , V_267 ) )
V_24 -> V_48 = V_52 ;
}
if ( V_26 == V_24 -> V_63 ) {
F_87 ( V_5 -> V_182 . V_183 ,
V_268 ) ;
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_271 ) ) {
if ( F_86 ( V_5 ,
V_60 , V_50 ) )
V_24 -> V_59 = V_47 ;
else if ( F_86 ( V_5 ,
V_60 , V_267 ) )
V_24 -> V_59 = V_52 ;
}
if ( V_24 -> V_48 == V_26 )
F_87 ( V_5 -> V_182 . V_183 ,
V_270 ) ;
if ( V_24 -> V_59 == V_26 )
F_87 ( V_5 -> V_182 . V_183 ,
V_271 ) ;
if ( ( V_5 -> V_53 != V_56 )
&& ( V_43 -> V_272 -> V_273 != 0 ) )
F_88 ( V_5 -> V_182 . V_183 ,
V_274 ) ;
V_24 -> V_132 . V_275 = V_276 ;
V_24 -> V_132 . V_277 = V_278 ;
V_24 -> V_131 . V_275 = V_276 ;
V_24 -> V_131 . V_277 = V_278 ;
V_24 -> V_134 . V_275 = 0 ;
V_24 -> V_134 . V_277 = 16 ;
V_24 -> V_133 . V_275 = 0 ;
V_24 -> V_133 . V_277 = 16 ;
}
static int F_89 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_1 V_279 ;
T_1 V_280 = 0 ;
T_1 V_281 = 0 ;
T_1 V_34 , V_282 ;
T_2 V_283 = 0 ;
struct V_42 * V_43 =
(struct V_42 * ) V_5 -> V_44 ;
struct V_165 * V_147 = NULL ;
for ( V_34 = 0 ; V_34 < V_284 ; V_34 ++ ) {
V_279 = V_285 + V_34 ;
if ( V_24 -> V_63 == V_52 ) {
if ( ( V_5 -> V_53 == V_54 )
&& ! F_90 ( V_5 ,
V_43 -> V_65 , V_279 , & V_283 ) ) {
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_274 ) ) {
V_147 = V_43 -> V_168 ;
for ( V_282 = 1 ; V_282 < V_147 -> V_37 ; V_282 ++ ) {
if ( V_147 -> V_38 [ V_282 ] . V_161 == V_283 &&
V_147 -> V_38 [ V_282 ] . V_286 == 0 ) {
V_283 += 5000 ;
break;
}
}
}
if ( 0 == F_91
( V_5 , V_269 , V_283 ,
V_279 , & V_281 ) ) {
F_2 ((vddgfx < 2000 && vddgfx != 0), L_67 , return -EINVAL) ;
if ( V_281 != 0 && V_281 != V_279 ) {
V_24 -> V_287 . V_288 [ V_24 -> V_287 . V_37 ] = V_281 ;
V_24 -> V_287 . V_289 [ V_24 -> V_287 . V_37 ] = V_279 ;
V_24 -> V_287 . V_37 ++ ;
}
} else {
F_63 ( L_68 ) ;
}
}
} else {
if ( ( V_5 -> V_53 == V_56 )
|| ! F_90 ( V_5 ,
V_43 -> V_69 , V_279 , & V_283 ) ) {
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_274 ) ) {
if ( V_43 == NULL )
return - V_120 ;
V_147 = V_43 -> V_168 ;
for ( V_282 = 1 ; V_282 < V_147 -> V_37 ; V_282 ++ ) {
if ( V_147 -> V_38 [ V_282 ] . V_161 == V_283 &&
V_147 -> V_38 [ V_282 ] . V_286 == 0 ) {
V_283 += 5000 ;
break;
}
}
}
if ( F_92 ( V_5 ,
V_66 ,
V_283 , V_279 , & V_280 ) == 0 ) {
if ( V_280 >= 2000 || V_280 == 0 )
return - V_120 ;
} else {
F_63 ( V_290 L_69 ) ;
continue;
}
if ( V_280 != 0 && V_280 != V_279 ) {
V_24 -> V_291 . V_288 [ V_24 -> V_291 . V_37 ] = ( T_1 ) ( V_280 ) ;
V_24 -> V_291 . V_289 [ V_24 -> V_291 . V_37 ] = V_279 ;
V_24 -> V_291 . V_37 ++ ;
}
}
}
}
return 0 ;
}
static void F_93 ( struct V_4 * V_5 ,
T_1 * V_292 , struct V_293 * V_294 )
{
T_2 V_295 ;
for ( V_295 = 0 ; V_295 < V_294 -> V_37 ; V_295 ++ ) {
if ( V_294 -> V_289 [ V_295 ] == * V_292 ) {
* V_292 = V_294 -> V_288 [ V_295 ] ;
break;
}
}
if ( * V_292 > V_285 )
F_63 ( V_212 L_70 ) ;
}
static int F_94 ( struct V_4 * V_5 ,
T_5 * V_296 ,
struct V_293 * V_294 )
{
T_2 V_34 ;
for ( V_34 = 0 ; V_34 < V_296 -> V_37 ; V_34 ++ )
F_93 ( V_5 ,
& V_296 -> V_38 [ V_34 ] . V_297 , V_294 ) ;
return 0 ;
}
static int F_95 (
struct V_4 * V_5 , struct V_293 * V_294 ,
T_1 * V_280 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
F_93 ( V_5 , ( T_1 * ) V_280 , V_294 ) ;
V_5 -> V_57 . V_298 . V_280 =
V_43 -> V_298 . V_280 ;
return 0 ;
}
static int F_96 (
struct V_4 * V_5 )
{
T_6 V_299 ;
T_6 V_300 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_147 =
V_43 -> V_168 ;
struct V_165 * V_149 =
V_43 -> V_55 ;
struct V_301 * V_302 =
V_43 -> V_303 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_299 = 0 ; V_299 < V_147 -> V_37 ; ++ V_299 ) {
V_300 = V_147 -> V_38 [ V_299 ] . V_304 ;
V_147 -> V_38 [ V_299 ] . V_281 =
V_43 -> V_65 -> V_38 [ V_300 ] . V_297 ;
}
} else {
for ( V_299 = 0 ; V_299 < V_147 -> V_37 ; ++ V_299 ) {
V_300 = V_147 -> V_38 [ V_299 ] . V_304 ;
V_147 -> V_38 [ V_299 ] . V_280 =
V_43 -> V_69 -> V_38 [ V_300 ] . V_297 ;
}
}
for ( V_299 = 0 ; V_299 < V_149 -> V_37 ; ++ V_299 ) {
V_300 = V_149 -> V_38 [ V_299 ] . V_304 ;
V_149 -> V_38 [ V_299 ] . V_280 =
V_43 -> V_69 -> V_38 [ V_300 ] . V_297 ;
}
for ( V_299 = 0 ; V_299 < V_302 -> V_37 ; ++ V_299 ) {
V_300 = V_302 -> V_38 [ V_299 ] . V_305 ;
V_302 -> V_38 [ V_299 ] . V_280 =
V_43 -> V_69 -> V_38 [ V_300 ] . V_297 ;
}
return 0 ;
}
static int F_97 ( struct V_4 * V_5 ,
T_5 * V_306 ,
T_7 * V_307 )
{
T_2 V_34 ;
F_2 ((NULL != look_up_table),
L_71 , return -EINVAL) ;
F_2 ((0 != look_up_table->count),
L_71 , return -EINVAL) ;
V_34 = F_24 ( V_5 -> V_21 , V_71 ) ;
F_2 ((i >= look_up_table->count),
L_72 , return -EINVAL) ;
for ( V_34 = 0 ; V_34 < V_306 -> V_37 ; V_34 ++ ) {
if ( V_306 -> V_38 [ V_34 ] . V_297 == V_307 -> V_297 ) {
if ( V_306 -> V_38 [ V_34 ] . V_308 == 1 )
return 0 ;
break;
}
}
V_306 -> V_38 [ V_34 ] . V_308 = 1 ;
V_306 -> V_38 [ V_34 ] . V_297 = V_307 -> V_297 ;
V_306 -> V_38 [ V_34 ] . V_309 = V_307 -> V_309 ;
V_306 -> V_38 [ V_34 ] . V_310 = V_307 -> V_310 ;
V_306 -> V_38 [ V_34 ] . V_311 = V_307 -> V_311 ;
if ( V_34 == V_306 -> V_37 )
V_306 -> V_37 ++ ;
return 0 ;
}
static int F_98 ( struct V_4 * V_5 )
{
T_6 V_299 ;
struct T_7 V_312 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_313 = (struct V_42 * ) ( V_5 -> V_44 ) ;
V_165 * V_147 = V_313 -> V_168 ;
V_165 * V_149 = V_313 -> V_55 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_299 = 0 ; V_299 < V_147 -> V_37 ; ++ V_299 ) {
if ( V_147 -> V_38 [ V_299 ] . V_314 & ( 1 << 15 ) )
V_312 . V_297 = V_147 -> V_38 [ V_299 ] . V_281 +
V_147 -> V_38 [ V_299 ] . V_314 - 0xFFFF ;
else
V_312 . V_297 = V_147 -> V_38 [ V_299 ] . V_281 +
V_147 -> V_38 [ V_299 ] . V_314 ;
V_147 -> V_38 [ V_299 ] . V_280 =
V_312 . V_309 = V_312 . V_310 =
V_312 . V_311 = V_312 . V_297 ;
F_97 ( V_5 , V_313 -> V_69 , & V_312 ) ;
}
for ( V_299 = 0 ; V_299 < V_149 -> V_37 ; ++ V_299 ) {
if ( V_149 -> V_38 [ V_299 ] . V_314 & ( 1 << 15 ) )
V_312 . V_297 = V_149 -> V_38 [ V_299 ] . V_280 +
V_149 -> V_38 [ V_299 ] . V_314 - 0xFFFF ;
else
V_312 . V_297 = V_149 -> V_38 [ V_299 ] . V_280 +
V_149 -> V_38 [ V_299 ] . V_314 ;
V_149 -> V_38 [ V_299 ] . V_281 = V_312 . V_309 =
V_312 . V_310 = V_312 . V_311 = V_312 . V_297 ;
F_97 ( V_5 , V_313 -> V_65 , & V_312 ) ;
}
}
return 0 ;
}
static int F_99 ( struct V_4 * V_5 )
{
T_6 V_299 ;
struct T_7 V_312 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_313 = (struct V_42 * ) ( V_5 -> V_44 ) ;
V_301 * V_302 = V_313 -> V_303 ;
if ( V_24 -> V_63 == V_52 ) {
for ( V_299 = 0 ; V_299 < V_302 -> V_37 ; V_299 ++ ) {
if ( V_302 -> V_38 [ V_299 ] . V_315 & ( 1 << 15 ) )
V_312 . V_297 = V_302 -> V_38 [ V_299 ] . V_280 +
V_302 -> V_38 [ V_299 ] . V_315 - 0xFFFF ;
else
V_312 . V_297 = V_302 -> V_38 [ V_299 ] . V_280 +
V_302 -> V_38 [ V_299 ] . V_315 ;
V_302 -> V_38 [ V_299 ] . V_281 = V_312 . V_309 =
V_312 . V_310 = V_312 . V_311 = V_312 . V_297 ;
F_97 ( V_5 , V_313 -> V_65 , & V_312 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_4 * V_5 ,
struct T_5 * V_296 )
{
T_2 V_316 , V_34 , V_282 ;
struct T_7 V_317 ;
V_316 = V_296 -> V_37 ;
F_2 ( 0 != lookup_table->count,
L_73 , return -EINVAL) ;
for ( V_34 = 0 ; V_34 < V_316 - 1 ; V_34 ++ ) {
for ( V_282 = V_34 + 1 ; V_282 > 0 ; V_282 -- ) {
if ( V_296 -> V_38 [ V_282 ] . V_297 <
V_296 -> V_38 [ V_282 - 1 ] . V_297 ) {
V_317 = V_296 -> V_38 [ V_282 - 1 ] ;
V_296 -> V_38 [ V_282 - 1 ] = V_296 -> V_38 [ V_282 ] ;
V_296 -> V_38 [ V_282 ] = V_317 ;
}
}
}
return 0 ;
}
static int F_101 ( struct V_4 * V_5 )
{
int V_45 = 0 ;
int V_234 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
if ( V_24 -> V_63 == V_52 ) {
V_234 = F_94 ( V_5 ,
V_43 -> V_65 , & ( V_24 -> V_287 ) ) ;
if ( V_234 != 0 )
V_45 = V_234 ;
F_93 ( V_5 ,
& V_43 -> V_298 . V_281 , & ( V_24 -> V_287 ) ) ;
} else {
V_234 = F_94 ( V_5 ,
V_43 -> V_69 , & ( V_24 -> V_291 ) ) ;
if ( V_234 )
V_45 = V_234 ;
V_234 = F_95 ( V_5 ,
& ( V_24 -> V_291 ) , & V_43 -> V_298 . V_280 ) ;
if ( V_234 )
V_45 = V_234 ;
}
V_234 = F_96 ( V_5 ) ;
if ( V_234 )
V_45 = V_234 ;
V_234 = F_98 ( V_5 ) ;
if ( V_234 )
V_45 = V_234 ;
V_234 = F_99 ( V_5 ) ;
if ( V_234 )
V_45 = V_234 ;
V_234 = F_100 ( V_5 , V_43 -> V_65 ) ;
if ( V_234 )
V_45 = V_234 ;
V_234 = F_100 ( V_5 , V_43 -> V_69 ) ;
if ( V_234 )
V_45 = V_234 ;
return V_45 ;
}
static int F_102 ( struct V_4 * V_5 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_318 =
V_43 -> V_168 ;
struct V_165 * V_319 =
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
V_43 -> V_320 . V_283 =
V_318 -> V_38 [ V_318 -> V_37 - 1 ] . V_161 ;
V_43 -> V_320 . V_321 =
V_319 -> V_38 [ V_319 -> V_37 - 1 ] . V_161 ;
V_43 -> V_320 . V_280 =
V_318 -> V_38 [ V_318 -> V_37 - 1 ] . V_280 ;
V_43 -> V_320 . V_322 =
V_319 -> V_38 [ V_319 -> V_37 - 1 ] . V_322 ;
V_5 -> V_57 . V_320 . V_283 = V_43 -> V_320 . V_283 ;
V_5 -> V_57 . V_320 . V_321 = V_43 -> V_320 . V_321 ;
V_5 -> V_57 . V_320 . V_280 = V_43 -> V_320 . V_280 ;
V_5 -> V_57 . V_320 . V_322 = V_43 -> V_320 . V_322 ;
return 0 ;
}
int F_103 ( struct V_4 * V_5 )
{
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_167 ;
struct T_5 * V_296 ;
T_2 V_34 ;
T_2 V_323 , V_324 , V_325 ;
struct V_326 V_327 = { 0 } ;
if ( V_43 != NULL ) {
V_167 = V_43 -> V_55 ;
V_296 = V_43 -> V_69 ;
} else
return 0 ;
V_327 . V_328 = sizeof( struct V_326 ) ;
V_327 . V_329 = V_330 ;
F_104 ( V_5 -> V_6 , & V_327 ) ;
V_323 = ( T_2 ) V_327 . V_39 ;
V_327 . V_329 = V_331 ;
F_104 ( V_5 -> V_6 , & V_327 ) ;
V_325 = ( T_2 ) V_327 . V_39 ;
V_327 . V_329 = V_332 ;
F_104 ( V_5 -> V_6 , & V_327 ) ;
V_324 = ( T_2 ) V_327 . V_39 ;
if ( V_5 -> V_333 == V_334 && V_323 == 0xC7 &&
( ( V_325 == 0xb37 && V_324 == 0x1002 ) ||
( V_325 == 0x4a8 && V_324 == 0x1043 ) ||
( V_325 == 0x9480 && V_324 == 0x1682 ) ) ) {
if ( V_296 -> V_38 [ V_167 -> V_38 [ V_167 -> V_37 - 1 ] . V_304 ] . V_297 >= 1000 )
return 0 ;
for ( V_34 = 0 ; V_34 < V_296 -> V_37 ; V_34 ++ ) {
if ( V_296 -> V_38 [ V_34 ] . V_297 < 0xff01 && V_296 -> V_38 [ V_34 ] . V_297 >= 1000 ) {
V_167 -> V_38 [ V_167 -> V_37 - 1 ] . V_304 = ( T_6 ) V_34 ;
return 0 ;
}
}
}
return 0 ;
}
static int F_105 ( struct V_4 * V_5 )
{
struct V_335 V_336 ;
T_2 V_337 ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
if ( F_106 ( V_5 , V_338 , & V_336 ) ) {
V_337 = F_8 ( V_5 -> V_6 , V_28 , V_339 ) ;
switch ( V_336 . V_340 ) {
case 0 :
V_337 = F_28 ( V_337 , V_341 , V_342 , 0x1 ) ;
break;
case 1 :
V_337 = F_28 ( V_337 , V_341 , V_342 , 0x2 ) ;
break;
case 2 :
V_337 = F_28 ( V_337 , V_341 , V_343 , 0x1 ) ;
break;
case 3 :
V_337 = F_28 ( V_337 , V_341 , V_344 , 0x1 ) ;
break;
case 4 :
V_337 = F_28 ( V_337 , V_341 , V_345 , 0x1 ) ;
break;
default:
F_2 ( 0 ,
L_78 ,
) ;
break;
}
F_29 ( V_5 -> V_6 , V_28 , V_339 , V_337 ) ;
}
if ( V_43 == NULL )
return 0 ;
if ( V_43 -> V_272 -> V_346 != 0 &&
V_5 -> V_347 . V_348 . V_349 ) {
V_5 -> V_347 . V_348 . V_350 =
( T_1 ) V_5 -> V_347 . V_348 . V_351 ;
V_5 -> V_347 . V_348 . V_352 =
( T_1 ) V_5 -> V_347 . V_348 . V_353 ;
V_5 -> V_347 . V_348 . V_354 = 1 ;
V_5 -> V_347 . V_348 . V_355 = 100 ;
V_5 -> V_347 . V_348 . V_356 =
( T_1 ) V_5 -> V_347 . V_348 . V_351 ;
V_5 -> V_347 . V_348 . V_357 = 1 ;
V_43 -> V_272 -> V_346 = ( V_43 -> V_272 -> V_346 >= 50 ) ?
( V_43 -> V_272 -> V_346 - 50 ) : 0 ;
V_43 -> V_272 -> V_358 = V_43 -> V_272 -> V_346 ;
V_43 -> V_272 -> V_359 = 1 ;
V_43 -> V_272 -> V_360 = 1 ;
V_5 -> V_347 . V_348 . V_361 =
V_5 -> V_347 . V_348 . V_353 ;
V_5 -> V_347 . V_348 . V_362 =
V_5 -> V_347 . V_348 . V_363 ;
V_5 -> V_57 . V_272 -> V_364 =
V_43 -> V_272 -> V_364 ;
V_5 -> V_57 . V_272 -> V_358 =
V_43 -> V_272 -> V_358 ;
V_5 -> V_57 . V_272 -> V_346 =
V_43 -> V_272 -> V_346 ;
V_5 -> V_57 . V_272 -> V_359 =
V_43 -> V_272 -> V_359 ;
V_5 -> V_57 . V_272 -> V_365 =
V_43 -> V_272 -> V_365 ;
F_88 ( V_5 -> V_182 . V_183 ,
V_366 ) ;
}
return 0 ;
}
static void F_107 ( struct V_4 * V_5 ,
T_2 * V_292 , struct V_293 * V_294 )
{
T_2 V_295 ;
for ( V_295 = 0 ; V_295 < V_294 -> V_37 ; V_295 ++ ) {
if ( V_294 -> V_289 [ V_295 ] == * V_292 ) {
* V_292 = V_294 -> V_288 [ V_295 ] ;
break;
}
}
if ( * V_292 > V_285 )
F_63 ( V_212 L_70 ) ;
}
static int F_108 ( struct V_4 * V_5 ,
struct V_32 * V_367 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_367 )
for ( V_34 = 0 ; V_34 < V_367 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_367 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_291 ) ;
return 0 ;
}
static int F_109 ( struct V_4 * V_5 ,
struct V_32 * V_367 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_367 )
for ( V_34 = 0 ; V_34 < V_367 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_367 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_368 ) ;
return 0 ;
}
static int F_110 ( struct V_4 * V_5 ,
struct V_369 * V_367 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_367 )
for ( V_34 = 0 ; V_34 < V_367 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_367 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_291 ) ;
return 0 ;
}
static int F_111 ( struct V_4 * V_5 ,
struct V_370 * V_367 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_367 )
for ( V_34 = 0 ; V_34 < V_367 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_367 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_291 ) ;
return 0 ;
}
static int F_112 ( struct V_4 * V_5 ,
struct V_371 * V_367 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_367 )
for ( V_34 = 0 ; V_34 < V_367 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_367 -> V_38 [ V_34 ] . V_372 ,
& V_24 -> V_291 ) ;
return 0 ;
}
static int F_113 ( struct V_4 * V_5 ,
struct V_373 * V_367 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_367 )
for ( V_34 = 0 ; V_34 < V_367 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_367 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_291 ) ;
return 0 ;
}
static int F_114 ( struct V_4 * V_5 ,
struct V_374 * V_367 )
{
T_1 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_367 )
for ( V_34 = 0 ; V_34 < V_367 -> V_37 ; V_34 ++ )
F_107 ( V_5 , & V_367 -> V_38 [ V_34 ] . V_40 ,
& V_24 -> V_291 ) ;
return 0 ;
}
static int F_115 ( struct V_4 * V_5 ,
struct V_375 * V_367 )
{
T_2 V_280 , V_322 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_367 ) {
V_280 = V_367 -> V_280 ;
F_107 ( V_5 , & V_280 ,
& V_24 -> V_291 ) ;
V_367 -> V_280 = V_280 ;
V_322 = V_367 -> V_322 ;
F_107 ( V_5 , & V_322 ,
& V_24 -> V_368 ) ;
V_367 -> V_322 = V_322 ;
}
return 0 ;
}
static int F_116 ( struct V_4 * V_5 , struct V_157 * V_367 )
{
T_2 V_34 ;
T_2 V_280 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_367 ) {
for ( V_34 = 0 ; V_34 < V_367 -> V_37 ; V_34 ++ ) {
V_280 = ( T_2 ) ( V_367 -> V_38 [ V_34 ] . V_376 ) ;
F_107 ( V_5 , & V_280 , & V_24 -> V_291 ) ;
V_367 -> V_38 [ V_34 ] . V_376 = ( T_1 ) V_280 ;
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
V_46 = F_108 ( V_5 , V_5 -> V_57 . V_377 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_109 ( V_5 , V_5 -> V_57 . V_62 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_110 ( V_5 , V_5 -> V_57 . V_378 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_111 ( V_5 , V_5 -> V_57 . V_379 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_113 ( V_5 , V_5 -> V_57 . V_380 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_114 ( V_5 , V_5 -> V_57 . V_381 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_112 ( V_5 , V_5 -> V_57 . V_382 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_115 ( V_5 , & V_5 -> V_57 . V_320 ) ;
if ( V_46 )
return - V_120 ;
V_46 = F_115 ( V_5 , & V_5 -> V_57 . V_298 ) ;
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
struct V_32 * V_383 = V_5 -> V_57 . V_155 ;
struct V_32 * V_384 = V_5 -> V_57 . V_68 ;
struct V_32 * V_385 = V_5 -> V_57 . V_62 ;
F_2 (allowed_sclk_vddc_table != NULL,
L_79 , return -EINVAL) ;
F_2 (allowed_sclk_vddc_table->count >= 1 ,
L_80 , return -EINVAL) ;
F_2 (allowed_mclk_vddc_table != NULL,
L_81 , return -EINVAL) ;
F_2 (allowed_mclk_vddc_table->count >= 1 ,
L_82 , return -EINVAL) ;
V_24 -> V_386 = ( T_1 ) V_383 -> V_38 [ 0 ] . V_40 ;
V_24 -> V_387 = ( T_1 ) V_383 -> V_38 [ V_383 -> V_37 - 1 ] . V_40 ;
V_5 -> V_57 . V_320 . V_283 =
V_383 -> V_38 [ V_383 -> V_37 - 1 ] . V_161 ;
V_5 -> V_57 . V_320 . V_321 =
V_384 -> V_38 [ V_384 -> V_37 - 1 ] . V_161 ;
V_5 -> V_57 . V_320 . V_280 =
V_383 -> V_38 [ V_383 -> V_37 - 1 ] . V_40 ;
if ( V_385 != NULL && V_385 -> V_37 >= 1 ) {
V_24 -> V_388 = ( T_1 ) V_385 -> V_38 [ 0 ] . V_40 ;
V_24 -> V_389 = ( T_1 ) V_385 -> V_38 [ V_385 -> V_37 - 1 ] . V_40 ;
}
if ( V_5 -> V_57 . V_62 != NULL && V_5 -> V_57 . V_62 -> V_37 > 1 )
V_5 -> V_57 . V_320 . V_322 = V_5 -> V_57 . V_62 -> V_38 [ V_5 -> V_57 . V_62 -> V_37 - 1 ] . V_40 ;
return 0 ;
}
int F_119 ( struct V_4 * V_5 )
{
struct V_23 * V_24 ;
int V_45 ;
V_24 = F_120 ( sizeof( struct V_23 ) , V_390 ) ;
if ( V_24 == NULL )
return - V_391 ;
V_5 -> V_25 = V_24 ;
F_103 ( V_5 ) ;
F_85 ( V_5 ) ;
V_45 = F_89 ( V_5 ) ;
if ( V_45 ) {
F_63 ( L_83 ) ;
return - V_120 ;
}
if ( V_5 -> V_53 == V_54 ) {
F_101 ( V_5 ) ;
F_102 ( V_5 ) ;
} else if ( V_5 -> V_53 == V_56 ) {
F_117 ( V_5 ) ;
F_118 ( V_5 ) ;
}
V_45 = F_121 ( V_5 ) ;
if ( 0 == V_45 ) {
struct V_326 V_327 = { 0 } ;
V_24 -> V_392 = false ;
V_5 -> V_182 . V_393 =
V_394 ;
V_5 -> V_182 . V_395 = 2 ;
V_5 -> V_182 . V_396 = 50 ;
V_327 . V_328 = sizeof( struct V_326 ) ;
V_327 . V_329 = V_397 ;
V_45 = F_104 ( V_5 -> V_6 , & V_327 ) ;
if ( V_45 )
V_24 -> V_139 = V_398 ;
else
V_24 -> V_139 = ( T_2 ) V_327 . V_39 ;
if ( V_24 -> V_139 & V_399 )
V_24 -> V_400 = 20 ;
V_327 . V_328 = sizeof( struct V_326 ) ;
V_327 . V_329 = V_401 ;
V_45 = F_104 ( V_5 -> V_6 , & V_327 ) ;
if ( V_45 )
V_24 -> V_141 = V_402 ;
else
V_24 -> V_141 = ( T_2 ) V_327 . V_39 ;
V_5 -> V_182 . V_403 = 0x20000400 ;
V_5 -> V_182 . V_404 . V_405 = 500 ;
V_5 -> V_182 . V_404 . V_406 = 500 ;
F_105 ( V_5 ) ;
} else {
F_122 ( V_5 ) ;
}
return 0 ;
}
static int F_123 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_407 , V_46 ;
if ( ! V_24 -> V_213 ) {
if ( V_24 -> V_408 . V_409 ) {
V_407 = 0 ;
V_46 = V_24 -> V_408 . V_409 ;
while ( V_46 >>= 1 )
V_407 ++ ;
if ( V_407 )
F_124 ( V_5 -> V_21 ,
V_410 , V_407 ) ;
}
}
if ( ! V_24 -> V_199 ) {
if ( V_24 -> V_408 . V_411 ) {
V_407 = 0 ;
V_46 = V_24 -> V_408 . V_411 ;
while ( V_46 >>= 1 )
V_407 ++ ;
if ( V_407 )
F_124 ( V_5 -> V_21 ,
V_412 ,
( 1 << V_407 ) ) ;
}
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_408 . V_413 ) {
V_407 = 0 ;
V_46 = V_24 -> V_408 . V_413 ;
while ( V_46 >>= 1 )
V_407 ++ ;
if ( V_407 )
F_124 ( V_5 -> V_21 ,
V_414 ,
( 1 << V_407 ) ) ;
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
if ( V_24 -> V_408 . V_411 )
F_124 ( V_5 -> V_21 ,
V_412 ,
V_24 -> V_408 . V_411 ) ;
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_408 . V_413 )
F_124 ( V_5 -> V_21 ,
V_414 ,
V_24 -> V_408 . V_413 ) ;
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
V_415 ) ;
}
return F_125 ( V_5 ) ;
}
static int F_128 ( struct V_4 * V_5 )
{
struct V_23 * V_24 =
(struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_407 ;
if ( ! V_24 -> V_199 )
if ( V_24 -> V_408 . V_411 ) {
V_407 = F_129 ( V_5 ,
V_24 -> V_408 . V_411 ) ;
F_124 ( V_5 -> V_21 ,
V_412 ,
( 1 << V_407 ) ) ;
}
if ( ! V_24 -> V_200 ) {
if ( V_24 -> V_408 . V_413 ) {
V_407 = F_129 ( V_5 ,
V_24 -> V_408 . V_413 ) ;
F_124 ( V_5 -> V_21 ,
V_414 ,
( 1 << V_407 ) ) ;
}
}
if ( ! V_24 -> V_213 ) {
if ( V_24 -> V_408 . V_409 ) {
V_407 = F_129 ( V_5 ,
V_24 -> V_408 . V_409 ) ;
F_124 ( V_5 -> V_21 ,
V_410 ,
( V_407 ) ) ;
}
}
return 0 ;
}
static int F_130 ( struct V_4 * V_5 ,
enum V_416 V_407 )
{
int V_417 = 0 ;
switch ( V_407 ) {
case V_418 :
V_417 = F_123 ( V_5 ) ;
if ( V_417 )
return V_417 ;
break;
case V_419 :
V_417 = F_128 ( V_5 ) ;
if ( V_417 )
return V_417 ;
break;
case V_420 :
V_417 = F_127 ( V_5 ) ;
if ( V_417 )
return V_417 ;
break;
default:
break;
}
V_5 -> V_421 = V_407 ;
return V_417 ;
}
static int F_131 ( struct V_4 * V_5 )
{
return sizeof( struct V_1 ) ;
}
static int F_132 ( struct V_4 * V_5 ,
struct V_422 * V_423 ,
const struct V_422 * V_424 )
{
struct V_1 * V_425 =
F_1 ( & V_423 -> V_426 ) ;
T_2 V_283 ;
T_2 V_321 ;
struct V_427 V_428 = { 0 } ;
bool V_429 ;
bool V_430 ;
struct V_172 V_173 = { 0 } ;
const struct V_375 * V_431 ;
T_2 V_34 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
T_8 V_37 ;
T_8 V_432 = 0 , V_433 = 0 ;
V_24 -> V_434 = ( V_435 ==
V_423 -> V_436 . V_437 ) ;
F_2 ( V_425 -> V_438 == 2 ,
L_84 ,
) ;
V_431 = ( V_439 == V_5 -> V_440 ) ?
& ( V_5 -> V_57 . V_320 ) :
& ( V_5 -> V_57 . V_298 ) ;
if ( V_441 == V_5 -> V_440 ) {
for ( V_34 = 0 ; V_34 < V_425 -> V_438 ; V_34 ++ ) {
if ( V_425 -> V_442 [ V_34 ] . V_443 > V_431 -> V_321 )
V_425 -> V_442 [ V_34 ] . V_443 = V_431 -> V_321 ;
if ( V_425 -> V_442 [ V_34 ] . V_444 > V_431 -> V_283 )
V_425 -> V_442 [ V_34 ] . V_444 = V_431 -> V_283 ;
}
}
V_425 -> V_445 . V_446 = V_5 -> V_447 . V_446 ;
V_425 -> V_445 . V_448 = V_5 -> V_447 . V_448 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_428 . V_405 = V_5 -> V_449 . V_450 ;
V_428 . V_406 = V_5 -> V_449 . V_451 ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_452 ) ) {
V_431 = & ( V_5 -> V_57 . V_320 ) ;
V_432 = ( V_431 -> V_283 * 75 ) / 100 ;
for ( V_37 = V_43 -> V_168 -> V_37 - 1 ;
V_37 >= 0 ; V_37 -- ) {
if ( V_432 >=
V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ) {
V_432 =
V_43 -> V_168 -> V_38 [ V_37 ] . V_161 ;
break;
}
}
if ( V_37 < 0 )
V_432 = V_43 -> V_168 -> V_38 [ 0 ] . V_161 ;
V_433 = V_431 -> V_321 ;
V_428 . V_405 = V_432 ;
V_428 . V_406 = V_433 ;
}
if ( V_428 . V_405 < V_5 -> V_453 . V_283 )
V_428 . V_405 = V_5 -> V_453 . V_283 ;
if ( V_428 . V_406 < V_5 -> V_453 . V_321 )
V_428 . V_406 = V_5 -> V_453 . V_321 ;
V_425 -> V_454 = V_5 -> V_453 . V_454 ;
if ( 0 != V_5 -> V_453 . V_455 ) {
F_2 ( ( V_5 -> V_453 . V_455 <=
V_5 -> V_182 . V_456 . V_405 ) ,
L_85 ,
V_5 -> V_453 . V_455 =
V_5 -> V_182 . V_456 . V_405 ) ;
if ( V_5 -> V_453 . V_455 >= V_5 -> V_453 . V_283 )
V_425 -> V_442 [ 1 ] . V_444 =
V_5 -> V_453 . V_455 ;
}
if ( 0 != V_5 -> V_453 . V_457 ) {
F_2 ( ( V_5 -> V_453 . V_457 <=
V_5 -> V_182 . V_456 . V_406 ) ,
L_86 ,
V_5 -> V_453 . V_457 =
V_5 -> V_182 . V_456 . V_406 ) ;
if ( V_5 -> V_453 . V_457 >= V_5 -> V_453 . V_321 )
V_425 -> V_442 [ 1 ] . V_443 =
V_5 -> V_453 . V_457 ;
}
V_430 = F_52 (
V_5 -> V_182 . V_183 ,
V_458 ) ;
V_429 = ( 1 < V_173 . V_459 ) ||
V_430 ;
V_283 = V_425 -> V_442 [ 0 ] . V_444 ;
V_321 = V_425 -> V_442 [ 0 ] . V_443 ;
if ( V_429 )
V_321 = V_425 -> V_442
[ V_425 -> V_438 - 1 ] . V_443 ;
if ( V_283 < V_428 . V_405 )
V_283 = ( V_428 . V_405 > V_431 -> V_283 ) ?
V_431 -> V_283 : V_428 . V_405 ;
if ( V_321 < V_428 . V_406 )
V_321 = ( V_428 . V_406 > V_431 -> V_321 ) ?
V_431 -> V_321 : V_428 . V_406 ;
V_425 -> V_442 [ 0 ] . V_444 = V_283 ;
V_425 -> V_442 [ 0 ] . V_443 = V_321 ;
V_425 -> V_442 [ 1 ] . V_444 =
( V_425 -> V_442 [ 1 ] . V_444 >=
V_425 -> V_442 [ 0 ] . V_444 ) ?
V_425 -> V_442 [ 1 ] . V_444 :
V_425 -> V_442 [ 0 ] . V_444 ;
if ( V_429 ) {
if ( V_321 < V_425 -> V_442 [ 1 ] . V_443 )
V_321 = V_425 -> V_442 [ 1 ] . V_443 ;
V_425 -> V_442 [ 0 ] . V_443 = V_321 ;
V_425 -> V_442 [ 1 ] . V_443 = V_321 ;
} else {
if ( V_425 -> V_442 [ 1 ] . V_443 <
V_425 -> V_442 [ 0 ] . V_443 )
V_425 -> V_442 [ 1 ] . V_443 =
V_425 -> V_442 [ 0 ] . V_443 ;
}
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_452 ) ) {
for ( V_34 = 0 ; V_34 < V_425 -> V_438 ; V_34 ++ ) {
V_425 -> V_442 [ V_34 ] . V_444 = V_432 ;
V_425 -> V_442 [ V_34 ] . V_443 = V_433 ;
V_425 -> V_442 [ V_34 ] . V_460 = V_24 -> V_132 . V_275 ;
V_425 -> V_442 [ V_34 ] . V_461 = V_24 -> V_132 . V_275 ;
}
}
return 0 ;
}
static int F_133 ( struct V_4 * V_5 , bool V_462 )
{
struct V_422 * V_463 ;
struct V_1 * V_425 ;
if ( V_5 == NULL )
return - V_120 ;
V_463 = V_5 -> V_423 ;
if ( V_463 == NULL )
return - V_120 ;
V_425 = F_1 ( & V_463 -> V_426 ) ;
if ( V_462 )
return V_425 -> V_442 [ 0 ] . V_443 ;
else
return V_425 -> V_442
[ V_425 -> V_438 - 1 ] . V_443 ;
}
static int F_134 ( struct V_4 * V_5 , bool V_462 )
{
struct V_422 * V_463 ;
struct V_1 * V_425 ;
if ( V_5 == NULL )
return - V_120 ;
V_463 = V_5 -> V_423 ;
if ( V_463 == NULL )
return - V_120 ;
V_425 = F_1 ( & V_463 -> V_426 ) ;
if ( V_462 )
return V_425 -> V_442 [ 0 ] . V_444 ;
else
return V_425 -> V_442
[ V_425 -> V_438 - 1 ] . V_444 ;
}
static int F_135 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_463 = (struct V_1 * ) V_3 ;
T_9 * V_464 ;
T_1 V_328 ;
T_6 V_465 , V_466 ;
int V_295 = F_136 ( V_467 , V_468 ) ;
V_464 = ( T_9 * ) F_137 (
V_5 -> V_6 , V_295 ,
& V_328 , & V_465 , & V_466 ) ;
if ( ! V_464 )
return 0 ;
V_24 -> V_469 . V_470 =
F_138 ( V_464 -> V_471 ) ;
V_24 -> V_469 . V_472 =
F_138 ( V_464 -> V_473 ) ;
V_24 -> V_469 . V_474 =
F_139 ( V_464 -> V_475 ) ;
V_24 -> V_469 . V_476 =
F_139 ( V_464 -> V_477 ) ;
V_24 -> V_469 . V_478 =
F_139 ( V_464 -> V_479 ) ;
V_24 -> V_469 . V_480 =
F_7 ( V_5 ) ;
V_24 -> V_469 . V_481 =
( T_1 ) F_10 ( V_5 ) ;
V_463 -> V_442 [ 0 ] . V_443 = V_24 -> V_469 . V_472 ;
V_463 -> V_442 [ 0 ] . V_444 = V_24 -> V_469 . V_470 ;
V_463 -> V_442 [ 0 ] . V_460 = V_24 -> V_469 . V_480 ;
V_463 -> V_442 [ 0 ] . V_461 = V_24 -> V_469 . V_481 ;
return 0 ;
}
static int F_140 ( struct V_4 * V_5 )
{
int V_45 ;
unsigned long V_417 = 0 ;
if ( V_5 -> V_53 == V_56 ) {
V_45 = F_141 ( V_5 , & V_417 ) ;
return V_45 ? 0 : V_417 ;
} else if ( V_5 -> V_53 == V_54 ) {
V_45 = F_142 ( V_5 ) ;
return V_45 ;
}
return 0 ;
}
static int F_143 ( struct V_4 * V_5 ,
void * V_482 , struct V_422 * V_483 ,
void * V_484 , T_2 V_485 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_1 =
(struct V_1 * ) ( & ( V_483 -> V_426 ) ) ;
struct V_486 * V_487 ;
T_10 * V_488 = ( T_10 * ) V_482 ;
T_11 * V_489 =
( T_11 * ) V_484 ;
T_12 * V_490 =
( T_12 * )
( ( ( unsigned long ) V_489 ) +
F_139 ( V_489 -> V_491 ) ) ;
T_13 * V_492 =
( T_13 * )
( ( ( unsigned long ) V_489 ) +
F_139 ( V_489 -> V_493 ) ) ;
V_483 -> V_436 . V_437 =
( F_139 ( V_488 -> V_494 ) &
V_495 ) >>
V_496 ;
V_483 -> V_436 . V_497 = V_485 ;
V_483 -> V_436 . V_498 = false ;
V_483 -> V_436 . V_499 = false ;
V_483 -> V_500 . V_501 =
( 0 != ( F_138 ( V_488 -> V_502 ) &
V_503 ) ) ;
V_483 -> V_504 . V_505 = 0 ;
V_483 -> V_506 . V_507 = false ;
V_483 -> V_506 . V_508 = false ;
V_483 -> V_506 . V_509 =
( 0 != ( F_138 ( V_488 -> V_502 ) &
V_510 ) ) ;
V_483 -> V_500 . V_511 = 0 ;
V_483 -> V_512 . V_513 = 0 ;
V_483 -> V_512 . V_514 = 0 ;
V_483 -> V_515 . V_277 = 0 ;
V_483 -> V_515 . V_275 = 0 ;
V_487 = & ( V_1 -> V_442
[ V_1 -> V_438 ++ ] ) ;
F_2 (
(smu7_power_state->performance_level_count < smum_get_mac_definition(hwmgr->smumgr, SMU_MAX_LEVELS_GRAPHICS)),
L_87 ,
return -EINVAL) ;
F_2 (
(smu7_power_state->performance_level_count <=
hwmgr->platform_descriptor.hardwareActivityPerformanceLevels),
L_88 ,
return -EINVAL) ;
V_487 -> V_443 = V_492 -> V_38
[ V_488 -> V_516 ] . V_517 ;
if ( V_490 -> V_518 == 0 )
V_487 -> V_444 = ( ( V_519 * ) V_490 ) -> V_38
[ V_488 -> V_520 ] . V_521 ;
else if ( V_490 -> V_518 == 1 )
V_487 -> V_444 = ( ( V_522 * ) V_490 ) -> V_38
[ V_488 -> V_520 ] . V_521 ;
V_487 -> V_460 = F_41 ( V_24 -> V_139 ,
V_488 -> V_523 ) ;
V_487 -> V_461 = F_42 ( V_24 -> V_141 ,
V_488 -> V_524 ) ;
V_487 = & ( V_1 -> V_442
[ V_1 -> V_438 ++ ] ) ;
V_487 -> V_443 = V_492 -> V_38
[ V_488 -> V_525 ] . V_517 ;
if ( V_490 -> V_518 == 0 )
V_487 -> V_444 = ( ( V_519 * ) V_490 ) -> V_38
[ V_488 -> V_526 ] . V_521 ;
else if ( V_490 -> V_518 == 1 )
V_487 -> V_444 = ( ( V_522 * ) V_490 ) -> V_38
[ V_488 -> V_526 ] . V_521 ;
V_487 -> V_460 = F_41 ( V_24 -> V_139 ,
V_488 -> V_527 ) ;
V_487 -> V_461 = F_42 ( V_24 -> V_141 ,
V_488 -> V_524 ) ;
return 0 ;
}
static int F_144 ( struct V_4 * V_5 ,
unsigned long V_528 , struct V_422 * V_482 )
{
int V_45 ;
struct V_1 * V_463 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_42 * V_43 =
(struct V_42 * ) ( V_5 -> V_44 ) ;
struct V_165 * V_167 =
V_43 -> V_55 ;
V_482 -> V_426 . V_529 = V_530 ;
V_463 = (struct V_1 * ) ( & V_482 -> V_426 ) ;
V_45 = F_145 ( V_5 , V_528 , V_482 ,
F_143 ) ;
if ( V_167 != NULL && V_167 -> V_37 == 1 ) {
if ( V_167 -> V_38 [ 0 ] . V_161 !=
V_24 -> V_469 . V_472 )
F_63 ( V_212 L_89
L_90 ) ;
if ( V_167 -> V_38 [ 0 ] . V_322 !=
V_24 -> V_469 . V_478 )
F_63 ( V_212 L_91
L_92 ) ;
}
if ( ! V_482 -> V_500 . V_501 )
V_463 -> V_531 = true ;
if ( V_482 -> V_436 . V_497 & V_532 )
V_24 -> V_533 = V_463 -> V_442 [ 0 ] . V_460 ;
V_463 -> V_534 . V_535 = V_482 -> V_512 . V_513 ;
V_463 -> V_534 . V_536 = V_482 -> V_512 . V_514 ;
if ( ! V_45 ) {
T_2 V_34 ;
switch ( V_482 -> V_436 . V_437 ) {
case V_537 :
V_24 -> V_129 = true ;
for ( V_34 = 0 ; V_34 < V_463 -> V_438 ; V_34 ++ ) {
if ( V_24 -> V_132 . V_275 <
V_463 -> V_442 [ V_34 ] . V_460 )
V_24 -> V_132 . V_275 =
V_463 -> V_442 [ V_34 ] . V_460 ;
if ( V_24 -> V_132 . V_277 >
V_463 -> V_442 [ V_34 ] . V_460 )
V_24 -> V_132 . V_277 =
V_463 -> V_442 [ V_34 ] . V_460 ;
if ( V_24 -> V_134 . V_275 <
V_463 -> V_442 [ V_34 ] . V_461 )
V_24 -> V_134 . V_275 =
V_463 -> V_442 [ V_34 ] . V_461 ;
if ( V_24 -> V_134 . V_277 >
V_463 -> V_442 [ V_34 ] . V_461 )
V_24 -> V_134 . V_277 =
V_463 -> V_442 [ V_34 ] . V_461 ;
}
break;
case V_435 :
V_24 -> V_130 = true ;
for ( V_34 = 0 ; V_34 < V_463 -> V_438 ; V_34 ++ ) {
if ( V_24 -> V_131 . V_275 <
V_463 -> V_442 [ V_34 ] . V_460 )
V_24 -> V_131 . V_275 =
V_463 -> V_442 [ V_34 ] . V_460 ;
if ( V_24 -> V_131 . V_277 >
V_463 -> V_442 [ V_34 ] . V_460 )
V_24 -> V_131 . V_277 =
V_463 -> V_442 [ V_34 ] . V_460 ;
if ( V_24 -> V_133 . V_275 <
V_463 -> V_442 [ V_34 ] . V_461 )
V_24 -> V_133 . V_275 =
V_463 -> V_442 [ V_34 ] . V_461 ;
if ( V_24 -> V_133 . V_277 >
V_463 -> V_442 [ V_34 ] . V_461 )
V_24 -> V_133 . V_277 =
V_463 -> V_442 [ V_34 ] . V_461 ;
}
break;
default:
break;
}
}
return 0 ;
}
static int F_146 ( struct V_4 * V_5 ,
struct V_2 * V_483 ,
unsigned int V_295 , const void * V_538 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_1 * V_463 = F_1 ( V_483 ) ;
const T_14 * V_539 = V_538 ;
struct V_486 * V_487 ;
T_2 V_444 , V_443 ;
T_1 V_540 ;
V_444 = V_539 -> V_541 << 16 | V_539 -> V_542 ;
V_443 = V_539 -> V_543 << 16 | V_539 -> V_544 ;
if ( ! ( V_24 -> V_545 & V_546 ) && V_443 > V_24 -> V_547 )
V_24 -> V_547 = V_443 ;
F_2 (
(ps->performance_level_count < smum_get_mac_definition(hwmgr->smumgr, SMU_MAX_LEVELS_GRAPHICS)),
L_87 ,
return -EINVAL) ;
F_2 (
(ps->performance_level_count <
hwmgr->platform_descriptor.hardwareActivityPerformanceLevels),
L_93 ,
return 0 ) ;
V_487 = & ( V_463 -> V_442
[ V_463 -> V_438 ++ ] ) ;
V_487 -> V_443 = V_443 ;
V_487 -> V_444 = V_444 ;
V_540 = V_539 -> V_548 ;
V_487 -> V_460 = F_41 ( V_24 -> V_139 , V_540 ) ;
V_487 -> V_461 = F_42 ( V_24 -> V_141 , V_539 -> V_549 ) ;
return 0 ;
}
static int F_147 ( struct V_4 * V_5 ,
unsigned long V_528 , struct V_422 * V_482 )
{
int V_45 ;
struct V_1 * V_463 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_32 * V_167 =
V_5 -> V_57 . V_62 ;
memset ( & V_482 -> V_426 , 0x00 , sizeof( struct V_2 ) ) ;
V_482 -> V_426 . V_529 = V_530 ;
V_463 = (struct V_1 * ) ( & V_482 -> V_426 ) ;
V_45 = F_148 ( V_5 , V_528 , V_482 ,
F_146 ) ;
if ( V_167 != NULL && V_167 -> V_37 == 1 ) {
if ( V_167 -> V_38 [ 0 ] . V_161 !=
V_24 -> V_469 . V_472 )
F_63 ( V_212 L_89
L_90 ) ;
if ( V_167 -> V_38 [ 0 ] . V_40 !=
V_24 -> V_469 . V_478 )
F_63 ( V_212 L_91
L_92 ) ;
}
if ( ! V_482 -> V_500 . V_501 )
V_463 -> V_531 = true ;
if ( V_482 -> V_436 . V_497 & V_532 )
V_24 -> V_533 = V_463 -> V_442 [ 0 ] . V_460 ;
V_463 -> V_534 . V_535 = V_482 -> V_512 . V_513 ;
V_463 -> V_534 . V_536 = V_482 -> V_512 . V_514 ;
if ( ! V_45 ) {
T_2 V_34 ;
switch ( V_482 -> V_436 . V_437 ) {
case V_537 :
V_24 -> V_129 = true ;
for ( V_34 = 0 ; V_34 < V_463 -> V_438 ; V_34 ++ ) {
if ( V_24 -> V_132 . V_275 <
V_463 -> V_442 [ V_34 ] . V_460 )
V_24 -> V_132 . V_275 =
V_463 -> V_442 [ V_34 ] . V_460 ;
if ( V_24 -> V_132 . V_277 >
V_463 -> V_442 [ V_34 ] . V_460 )
V_24 -> V_132 . V_277 =
V_463 -> V_442 [ V_34 ] . V_460 ;
if ( V_24 -> V_134 . V_275 <
V_463 -> V_442 [ V_34 ] . V_461 )
V_24 -> V_134 . V_275 =
V_463 -> V_442 [ V_34 ] . V_461 ;
if ( V_24 -> V_134 . V_277 >
V_463 -> V_442 [ V_34 ] . V_461 )
V_24 -> V_134 . V_277 =
V_463 -> V_442 [ V_34 ] . V_461 ;
}
break;
case V_435 :
V_24 -> V_130 = true ;
for ( V_34 = 0 ; V_34 < V_463 -> V_438 ; V_34 ++ ) {
if ( V_24 -> V_131 . V_275 <
V_463 -> V_442 [ V_34 ] . V_460 )
V_24 -> V_131 . V_275 =
V_463 -> V_442 [ V_34 ] . V_460 ;
if ( V_24 -> V_131 . V_277 >
V_463 -> V_442 [ V_34 ] . V_460 )
V_24 -> V_131 . V_277 =
V_463 -> V_442 [ V_34 ] . V_460 ;
if ( V_24 -> V_133 . V_275 <
V_463 -> V_442 [ V_34 ] . V_461 )
V_24 -> V_133 . V_275 =
V_463 -> V_442 [ V_34 ] . V_461 ;
if ( V_24 -> V_133 . V_277 >
V_463 -> V_442 [ V_34 ] . V_461 )
V_24 -> V_133 . V_277 =
V_463 -> V_442 [ V_34 ] . V_461 ;
}
break;
default:
break;
}
}
return 0 ;
}
static int F_149 ( struct V_4 * V_5 ,
unsigned long V_528 , struct V_422 * V_482 )
{
if ( V_5 -> V_53 == V_56 )
return F_147 ( V_5 , V_528 , V_482 ) ;
else if ( V_5 -> V_53 == V_54 )
return F_144 ( V_5 , V_528 , V_482 ) ;
return 0 ;
}
static int F_150 ( struct V_4 * V_5 , int V_550 , T_8 * V_39 )
{
T_2 V_283 , V_321 , V_551 ;
T_2 V_552 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
switch ( V_550 ) {
case V_553 :
F_14 ( V_5 -> V_21 , V_554 ) ;
V_283 = F_6 ( V_5 -> V_6 , V_555 ) ;
* V_39 = V_283 ;
return 0 ;
case V_556 :
F_14 ( V_5 -> V_21 , V_557 ) ;
V_321 = F_6 ( V_5 -> V_6 , V_555 ) ;
* V_39 = V_321 ;
return 0 ;
case V_558 :
V_552 = V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_559 ) ;
V_551 = F_8 ( V_5 -> V_6 , V_28 , V_552 ) ;
V_551 += 0x80 ;
V_551 >>= 8 ;
* V_39 = V_551 > 100 ? 100 : V_551 ;
return 0 ;
case V_560 :
* V_39 = F_151 ( V_5 ) ;
return 0 ;
case V_561 :
* V_39 = V_24 -> V_562 ? 0 : 1 ;
return 0 ;
case V_563 :
* V_39 = V_24 -> V_564 ? 0 : 1 ;
return 0 ;
default:
return - V_120 ;
}
}
static int F_152 ( struct V_4 * V_5 , const void * V_565 )
{
const struct V_566 * V_567 =
( const struct V_566 * ) V_565 ;
const struct V_1 * V_425 =
F_3 ( V_567 -> V_568 ) ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_569 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
T_2 V_283 = V_425 -> V_442
[ V_425 -> V_438 - 1 ] . V_444 ;
struct V_569 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
T_2 V_321 = V_425 -> V_442
[ V_425 -> V_438 - 1 ] . V_443 ;
struct V_427 V_570 = { 0 } ;
T_2 V_34 ;
struct V_172 V_173 = { 0 } ;
V_24 -> V_571 = 0 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ ) {
if ( V_283 == V_147 -> V_160 [ V_34 ] . V_39 )
break;
}
if ( V_34 >= V_147 -> V_37 )
V_24 -> V_571 |= V_572 ;
else {
if ( V_24 -> V_573 . V_574 != V_570 . V_575 &&
( V_570 . V_575 >= V_576 ||
V_24 -> V_573 . V_574 >= V_576 ) )
V_24 -> V_571 |= V_577 ;
}
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ ) {
if ( V_321 == V_149 -> V_160 [ V_34 ] . V_39 )
break;
}
if ( V_34 >= V_149 -> V_37 )
V_24 -> V_571 |= V_578 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
if ( V_24 -> V_573 . V_579 != V_173 . V_459 )
V_24 -> V_571 |= V_580 ;
return 0 ;
}
static T_1 F_153 ( struct V_4 * V_5 ,
const struct V_1 * V_425 )
{
T_2 V_34 ;
T_2 V_283 , V_581 = 0 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_170 * V_136 = & V_24 -> V_136 ;
for ( V_34 = 0 ; V_34 < V_425 -> V_438 ; V_34 ++ ) {
V_283 = V_425 -> V_442 [ V_34 ] . V_444 ;
if ( V_581 < V_283 )
V_581 = V_283 ;
}
for ( V_34 = 0 ; V_34 < V_136 -> V_147 . V_37 ; V_34 ++ ) {
if ( V_136 -> V_147 . V_160 [ V_34 ] . V_39 == V_581 )
return ( T_1 ) ( ( V_34 >= V_136 -> V_137 . V_37 ) ?
V_136 -> V_137 . V_160
[ V_136 -> V_137 . V_37 - 1 ] . V_39 :
V_136 -> V_137 . V_160 [ V_34 ] . V_39 ) ;
}
return 0 ;
}
static int F_154 (
struct V_4 * V_5 , const void * V_565 )
{
const struct V_566 * V_567 =
( const struct V_566 * ) V_565 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_582 =
F_3 ( V_567 -> V_568 ) ;
const struct V_1 * V_583 =
F_3 ( V_567 -> V_584 ) ;
T_1 V_585 = F_153 ( V_5 , V_582 ) ;
T_1 V_586 ;
if ( V_24 -> V_263 == V_264 )
V_586 = F_153 ( V_5 , V_583 ) ;
else
V_586 = V_24 -> V_263 ;
V_24 -> V_263 = V_264 ;
V_24 -> V_587 = false ;
if ( V_585 > V_586 ) {
switch ( V_585 ) {
case V_278 :
if ( 0 == F_155 ( V_5 -> V_6 , V_588 , false ) )
break;
V_24 -> V_263 = V_589 ;
if ( V_586 == V_589 )
break;
case V_589 :
if ( 0 == F_155 ( V_5 -> V_6 , V_590 , false ) )
break;
default:
V_24 -> V_263 = F_7 ( V_5 ) ;
break;
}
} else {
if ( V_585 < V_586 )
V_24 -> V_587 = true ;
}
return 0 ;
}
static int F_156 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( 0 == V_24 -> V_571 )
return 0 ;
if ( ( 0 == V_24 -> V_199 ) &&
( V_24 -> V_571 &
( V_572 + V_577 ) ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_94 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_FreezeLevel),
L_95 ,
return -EINVAL) ;
}
if ( ( 0 == V_24 -> V_200 ) &&
( V_24 -> V_571 &
V_578 ) ) {
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
static int F_157 (
struct V_4 * V_5 , const void * V_565 )
{
int V_45 = 0 ;
const struct V_566 * V_567 =
( const struct V_566 * ) V_565 ;
const struct V_1 * V_425 =
F_3 ( V_567 -> V_568 ) ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_283 = V_425 -> V_442
[ V_425 -> V_438 - 1 ] . V_444 ;
T_2 V_321 = V_425 -> V_442
[ V_425 -> V_438 - 1 ] . V_443 ;
struct V_170 * V_136 = & V_24 -> V_136 ;
struct V_170 * V_169 = & V_24 -> V_169 ;
T_2 V_591 , V_592 ;
T_2 V_34 ;
if ( 0 == V_24 -> V_571 )
return 0 ;
if ( V_24 -> V_571 & V_572 ) {
V_136 -> V_147 . V_160
[ V_136 -> V_147 . V_37 - 1 ] . V_39 = V_283 ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_593 ) ||
F_52 ( V_5 -> V_182 . V_183 , V_594 ) ) {
F_2 (
(golden_dpm_table->sclk_table.dpm_levels
[golden_dpm_table->sclk_table.count - 1].value != 0),
L_98 ,
return -EINVAL) ;
V_591 = V_136 -> V_147 . V_37 < 2 ? 0 : V_136 -> V_147 . V_37 - 2 ;
for ( V_34 = V_591 ; V_34 > 1 ; V_34 -- ) {
if ( V_283 > V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ) {
V_592 =
( ( V_283
- V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39
) * 100 )
/ V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ;
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 +
( V_169 -> V_147 . V_160 [ V_34 ] . V_39 *
V_592 ) / 100 ;
} else if ( V_169 -> V_147 . V_160 [ V_136 -> V_147 . V_37 - 1 ] . V_39 > V_283 ) {
V_592 =
( ( V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39
- V_283 ) * 100 )
/ V_169 -> V_147 . V_160 [ V_169 -> V_147 . V_37 - 1 ] . V_39 ;
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 -
( V_169 -> V_147 . V_160 [ V_34 ] . V_39 *
V_592 ) / 100 ;
} else
V_136 -> V_147 . V_160 [ V_34 ] . V_39 =
V_169 -> V_147 . V_160 [ V_34 ] . V_39 ;
}
}
}
if ( V_24 -> V_571 & V_578 ) {
V_136 -> V_149 . V_160
[ V_136 -> V_149 . V_37 - 1 ] . V_39 = V_321 ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_593 ) ||
F_52 ( V_5 -> V_182 . V_183 , V_594 ) ) {
F_2 (
(golden_dpm_table->mclk_table.dpm_levels
[golden_dpm_table->mclk_table.count-1].value != 0),
L_98 ,
return -EINVAL) ;
V_591 = V_136 -> V_149 . V_37 < 2 ? 0 : V_136 -> V_149 . V_37 - 2 ;
for ( V_34 = V_591 ; V_34 > 1 ; V_34 -- ) {
if ( V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 < V_321 ) {
V_592 = ( ( V_321 -
V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ) * 100 )
/ V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 +
( V_169 -> V_149 . V_160 [ V_34 ] . V_39 *
V_592 ) / 100 ;
} else if ( V_169 -> V_149 . V_160 [ V_136 -> V_149 . V_37 - 1 ] . V_39 > V_321 ) {
V_592 = (
( V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 - V_321 )
* 100 )
/ V_169 -> V_149 . V_160 [ V_169 -> V_149 . V_37 - 1 ] . V_39 ;
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 -
( V_169 -> V_149 . V_160 [ V_34 ] . V_39 *
V_592 ) / 100 ;
} else
V_136 -> V_149 . V_160 [ V_34 ] . V_39 =
V_169 -> V_149 . V_160 [ V_34 ] . V_39 ;
}
}
}
if ( V_24 -> V_571 &
( V_572 + V_577 ) ) {
V_45 = F_158 ( V_5 ) ;
F_2 ((0 == result),
L_99 ,
return result) ;
}
if ( V_24 -> V_571 &
( V_578 + V_580 ) ) {
V_45 = F_159 ( V_5 ) ;
F_2 ((0 == result),
L_100 ,
return result) ;
}
return V_45 ;
}
static int F_160 ( struct V_4 * V_5 ,
struct V_569 * V_136 ,
T_2 V_595 , T_2 V_596 )
{
T_2 V_34 ;
for ( V_34 = 0 ; V_34 < V_136 -> V_37 ; V_34 ++ ) {
if ( ( V_136 -> V_160 [ V_34 ] . V_39 < V_595 )
|| ( V_136 -> V_160 [ V_34 ] . V_39 > V_596 ) )
V_136 -> V_160 [ V_34 ] . V_162 = false ;
else
V_136 -> V_160 [ V_34 ] . V_162 = true ;
}
return 0 ;
}
static int F_161 ( struct V_4 * V_5 ,
const struct V_1 * V_425 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_597 ;
F_2 ((smu7_ps->performance_level_count >= 1),
L_101 ,
return -EINVAL) ;
V_597 = ( 1 == V_425 -> V_438 ) ? 0 : 1 ;
F_160 ( V_5 ,
& ( V_24 -> V_136 . V_147 ) ,
V_425 -> V_442 [ 0 ] . V_444 ,
V_425 -> V_442 [ V_597 ] . V_444 ) ;
F_160 ( V_5 ,
& ( V_24 -> V_136 . V_149 ) ,
V_425 -> V_442 [ 0 ] . V_443 ,
V_425 -> V_442 [ V_597 ] . V_443 ) ;
return 0 ;
}
static int F_162 (
struct V_4 * V_5 , const void * V_565 )
{
int V_45 ;
const struct V_566 * V_567 =
( const struct V_566 * ) V_565 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_425 =
F_3 ( V_567 -> V_568 ) ;
V_45 = F_161 ( V_5 , V_425 ) ;
if ( V_45 )
return V_45 ;
V_24 -> V_408 . V_411 =
F_163 ( & V_24 -> V_136 . V_147 ) ;
V_24 -> V_408 . V_413 =
F_163 ( & V_24 -> V_136 . V_149 ) ;
V_24 -> V_408 . V_409 =
F_163 ( & V_24 -> V_136 . V_137 ) ;
return 0 ;
}
static int F_164 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( 0 == V_24 -> V_571 )
return 0 ;
if ( ( 0 == V_24 -> V_199 ) &&
( V_24 -> V_571 &
( V_572 + V_577 ) ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_102 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_UnfreezeLevel),
L_103 ,
return -EINVAL) ;
}
if ( ( 0 == V_24 -> V_200 ) &&
( V_24 -> V_571 & V_578 ) ) {
F_2 ( true == F_73 ( V_5 ) ,
L_104 ,
) ;
F_2 ( 0 == smum_send_msg_to_smc(hwmgr->smumgr,
PPSMC_MSG_SCLKDPM_UnfreezeLevel),
L_105 ,
return -EINVAL) ;
}
V_24 -> V_571 = 0 ;
return 0 ;
}
static int F_165 (
struct V_4 * V_5 , const void * V_565 )
{
const struct V_566 * V_567 =
( const struct V_566 * ) V_565 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
const struct V_1 * V_425 =
F_3 ( V_567 -> V_568 ) ;
T_1 V_585 = F_153 ( V_5 , V_425 ) ;
T_6 V_598 ;
if ( V_24 -> V_587 ) {
if ( V_585 == V_278 )
V_598 = V_588 ;
else if ( V_585 == V_589 )
V_598 = V_590 ;
else
V_598 = V_599 ;
if ( V_598 == V_599 &&
F_7 ( V_5 ) > 0 )
return 0 ;
if ( F_155 ( V_5 -> V_6 , V_598 , false ) ) {
if ( V_589 == V_585 )
F_63 ( L_106 ) ;
else
F_63 ( L_107 ) ;
}
}
return 0 ;
}
static int F_166 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_5 -> V_19 & V_600 )
F_124 ( V_5 -> V_21 ,
( V_237 ) V_601 , V_24 -> V_602 ) ;
return ( F_14 ( V_5 -> V_21 , ( V_237 ) V_603 ) == 0 ) ? 0 : - V_120 ;
}
static int F_167 ( struct V_4 * V_5 , const void * V_565 )
{
int V_234 , V_45 = 0 ;
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_234 = F_152 ( V_5 , V_565 ) ;
F_2 ( ( 0 == V_234 ) ,
L_108 ,
V_45 = V_234 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_604 ) ) {
V_234 =
F_154 ( V_5 , V_565 ) ;
F_2 ( ( 0 == V_234 ) ,
L_109 ,
V_45 = V_234 ) ;
}
V_234 = F_156 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_110 , V_45 = V_234 ) ;
V_234 = F_157 ( V_5 , V_565 ) ;
F_2 ( ( 0 == V_234 ) ,
L_111 ,
V_45 = V_234 ) ;
V_234 = F_162 ( V_5 , V_565 ) ;
F_2 ( ( 0 == V_234 ) ,
L_112 ,
V_45 = V_234 ) ;
V_234 = F_168 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_113 ,
V_45 = V_234 ) ;
V_234 = F_166 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_114 ,
V_45 = V_234 ) ;
V_234 = F_164 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_115 ,
V_45 = V_234 ) ;
V_234 = F_125 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_116 ,
V_45 = V_234 ) ;
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_604 ) ) {
V_234 =
F_165 ( V_5 , V_565 ) ;
F_2 ( ( 0 == V_234 ) ,
L_117 ,
V_45 = V_234 ) ;
}
V_24 -> V_605 = false ;
return V_45 ;
}
static int F_169 ( struct V_4 * V_5 , T_1 V_606 )
{
V_5 -> V_347 .
V_348 . V_361 = V_606 ;
if ( F_170 ( V_5 ) )
return 0 ;
return F_124 ( V_5 -> V_21 ,
V_607 , V_606 ) ;
}
int F_171 ( struct V_4 * V_5 , bool V_608 )
{
V_237 V_609 = V_608 ? ( V_237 ) V_603 : ( V_237 ) V_238 ;
return ( F_14 ( V_5 -> V_21 , V_609 ) == 0 ) ? 0 : - 1 ;
}
int F_172 ( struct V_4 * V_5 )
{
T_2 V_610 = 0 ;
struct V_172 V_173 = { 0 } ;
V_173 . V_175 = NULL ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_610 = V_173 . V_459 ;
if ( V_610 > 1 && V_5 -> V_449 . V_611 != true )
F_171 ( V_5 , false ) ;
return 0 ;
}
int F_173 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_610 = 0 ;
T_2 V_79 = F_8 ( V_5 -> V_6 , V_28 , V_80 ) ;
T_2 V_612 ;
T_2 V_613 ;
T_2 V_614 ;
T_2 V_179 ;
T_2 V_615 = 0 ;
struct V_172 V_173 = { 0 } ;
struct V_174 V_175 ;
V_173 . V_175 = & V_175 ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
V_610 = V_173 . V_459 ;
V_79 = F_28 ( V_79 , V_81 , V_82 , ( V_610 > 0 ) ? V_616 : V_83 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_80 , V_79 ) ;
V_179 = V_175 . V_179 ;
V_615 = V_175 . V_615 ;
if ( 0 == V_615 )
V_615 = 60 ;
V_614 = 1000000 / V_615 ;
V_613 = V_614 - 200 - V_175 . V_617 ;
V_24 -> V_602 = V_614 * 2 / 100 ;
V_612 = V_613 * ( V_179 / 100 ) ;
F_29 ( V_5 -> V_6 , V_28 , V_618 , V_612 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_619 ) , 0x64 ) ;
F_29 ( V_5 -> V_6 , V_28 ,
V_24 -> V_195 + F_59 ( V_5 -> V_21 ,
V_196 ,
V_620 ) ,
( V_614 - V_613 ) ) ;
return 0 ;
}
int F_174 ( struct V_4 * V_5 )
{
return F_173 ( V_5 ) ;
}
static int F_175 ( struct V_4 * V_5 , T_1 V_621 )
{
V_5 -> V_347 .
V_348 . V_362 = V_621 ;
if ( F_170 ( V_5 ) )
return 0 ;
return F_124 ( V_5 -> V_21 ,
V_622 , V_621 ) ;
}
int F_176 ( struct V_4 * V_5 ,
const void * V_623 )
{
return 0 ;
}
bool F_177 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
bool V_624 = false ;
struct V_172 V_173 = { 0 , 0 , NULL } ;
F_50 ( V_5 -> V_6 , & V_173 ) ;
if ( V_24 -> V_573 . V_579 != V_173 . V_459 )
V_624 = true ;
if ( F_52 ( V_5 -> V_182 . V_183 , V_190 ) ) {
if ( V_24 -> V_573 . V_574 != V_5 -> V_449 . V_625 &&
( V_24 -> V_573 . V_574 >= V_576 ||
V_5 -> V_449 . V_625 >= V_576 ) )
V_624 = true ;
}
return V_624 ;
}
static inline bool F_178 ( const struct V_486 * V_626 ,
const struct V_486 * V_627 )
{
return ( ( V_626 -> V_443 == V_627 -> V_443 ) &&
( V_626 -> V_444 == V_627 -> V_444 ) &&
( V_626 -> V_460 == V_627 -> V_460 ) &&
( V_626 -> V_461 == V_627 -> V_461 ) ) ;
}
int F_179 ( struct V_4 * V_5 , const struct V_2 * V_628 , const struct V_2 * V_629 , bool * V_630 )
{
const struct V_1 * V_631 ;
const struct V_1 * V_632 ;
int V_34 ;
if ( V_628 == NULL || V_629 == NULL || V_630 == NULL )
return - V_120 ;
V_631 = F_3 ( V_628 ) ;
V_632 = F_3 ( V_629 ) ;
if ( V_631 -> V_438 != V_632 -> V_438 ) {
* V_630 = false ;
return 0 ;
}
for ( V_34 = 0 ; V_34 < V_631 -> V_438 ; V_34 ++ ) {
if ( ! F_178 ( & ( V_631 -> V_442 [ V_34 ] ) , & ( V_632 -> V_442 [ V_34 ] ) ) ) {
* V_630 = false ;
return 0 ;
}
}
* V_630 = ( ( V_631 -> V_534 . V_535 == V_632 -> V_534 . V_535 ) && ( V_631 -> V_534 . V_536 == V_632 -> V_534 . V_536 ) ) ;
* V_630 &= ( ( V_631 -> V_445 . V_446 == V_632 -> V_445 . V_446 ) && ( V_631 -> V_445 . V_448 == V_632 -> V_445 . V_448 ) ) ;
* V_630 &= ( V_631 -> V_454 == V_632 -> V_454 ) ;
return 0 ;
}
int F_180 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_633 ;
T_2 V_46 ;
F_4 ( V_5 ) ;
V_633 = V_5 -> V_8 . V_9 & 0xf ;
V_24 -> V_634 = false ;
F_5 ( V_5 -> V_6 , V_7 ,
V_635 ) ;
V_46 = F_6 ( V_5 -> V_6 , V_10 ) ;
if ( V_46 & ( 1 << 23 ) ) {
V_24 -> V_636 = V_637 ;
V_24 -> V_638 = V_639 ;
} else {
V_24 -> V_636 = 330 ;
V_24 -> V_638 = 330 ;
}
return 0 ;
}
static int F_181 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_640 . V_641 =
F_8 ( V_5 -> V_6 , V_28 , V_642 ) ;
V_24 -> V_640 . V_643 =
F_8 ( V_5 -> V_6 , V_28 , V_644 ) ;
V_24 -> V_640 . V_645 =
F_8 ( V_5 -> V_6 , V_28 , V_646 ) ;
V_24 -> V_640 . V_647 =
F_8 ( V_5 -> V_6 , V_28 , V_648 ) ;
V_24 -> V_640 . V_649 =
F_8 ( V_5 -> V_6 , V_28 , V_650 ) ;
V_24 -> V_640 . V_651 =
F_8 ( V_5 -> V_6 , V_28 , V_652 ) ;
V_24 -> V_640 . V_653 =
F_6 ( V_5 -> V_6 , V_654 ) ;
V_24 -> V_640 . V_655 =
F_6 ( V_5 -> V_6 , V_656 ) ;
V_24 -> V_640 . V_657 =
F_6 ( V_5 -> V_6 , V_658 ) ;
V_24 -> V_640 . V_659 =
F_6 ( V_5 -> V_6 , V_660 ) ;
V_24 -> V_640 . V_661 =
F_6 ( V_5 -> V_6 , V_662 ) ;
V_24 -> V_640 . V_663 =
F_6 ( V_5 -> V_6 , V_664 ) ;
V_24 -> V_640 . V_665 =
F_6 ( V_5 -> V_6 , V_666 ) ;
V_24 -> V_640 . V_667 =
F_6 ( V_5 -> V_6 , V_668 ) ;
V_24 -> V_640 . V_669 =
F_6 ( V_5 -> V_6 , V_670 ) ;
return 0 ;
}
static int F_182 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
T_2 V_671 ;
V_671 = F_6 ( V_5 -> V_6 , V_672 ) ;
V_24 -> V_673 = ( V_674 ==
( ( V_671 & V_675 ) >>
V_676 ) ) ;
return 0 ;
}
static int F_183 ( struct V_4 * V_5 )
{
F_17 ( V_5 -> V_6 , V_28 ,
V_29 , V_677 , 1 ) ;
return 0 ;
}
static int F_184 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_562 = false ;
V_24 -> V_564 = false ;
V_24 -> V_678 = false ;
return 0 ;
}
static int F_185 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
V_24 -> V_679 = 0 ;
return 0 ;
}
int F_186 ( struct V_4 * V_5 )
{
int V_234 , V_45 = 0 ;
F_180 ( V_5 ) ;
V_234 = F_181 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_118 , V_45 = V_234 ) ;
V_234 = F_182 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_119 , V_45 = V_234 ) ;
V_234 = F_183 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_120 , V_45 = V_234 ) ;
V_234 = F_184 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_121 , V_45 = V_234 ) ;
V_234 = F_4 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_122 , V_45 = V_234 ) ;
V_234 = F_185 ( V_5 ) ;
F_2 ( ( 0 == V_234 ) ,
L_123 , V_45 = V_234 ) ;
return V_45 ;
}
static int F_187 ( struct V_4 * V_5 ,
enum V_680 type , T_2 V_681 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_5 -> V_421 != V_682 )
return - V_120 ;
switch ( type ) {
case V_683 :
if ( ! V_24 -> V_199 )
F_124 ( V_5 -> V_21 ,
V_412 ,
V_24 -> V_408 . V_411 & V_681 ) ;
break;
case V_684 :
if ( ! V_24 -> V_200 )
F_124 ( V_5 -> V_21 ,
V_414 ,
V_24 -> V_408 . V_413 & V_681 ) ;
break;
case V_685 :
{
T_2 V_46 = V_681 & V_24 -> V_408 . V_409 ;
T_2 V_407 = 0 ;
while ( V_46 >>= 1 )
V_407 ++ ;
if ( ! V_24 -> V_213 )
F_124 ( V_5 -> V_21 ,
V_410 ,
V_407 ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_188 ( struct V_4 * V_5 ,
enum V_680 type , char * V_686 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_569 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
struct V_569 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
struct V_569 * V_127 = & ( V_24 -> V_136 . V_137 ) ;
int V_34 , V_687 , V_328 = 0 ;
T_2 clock , V_688 ;
switch ( type ) {
case V_683 :
F_14 ( V_5 -> V_21 , V_554 ) ;
clock = F_6 ( V_5 -> V_6 , V_555 ) ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ ) {
if ( clock > V_147 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_687 = V_34 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ )
V_328 += sprintf ( V_686 + V_328 , L_124 ,
V_34 , V_147 -> V_160 [ V_34 ] . V_39 / 100 ,
( V_34 == V_687 ) ? L_125 : L_126 ) ;
break;
case V_684 :
F_14 ( V_5 -> V_21 , V_557 ) ;
clock = F_6 ( V_5 -> V_6 , V_555 ) ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ ) {
if ( clock > V_149 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_687 = V_34 ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ )
V_328 += sprintf ( V_686 + V_328 , L_124 ,
V_34 , V_149 -> V_160 [ V_34 ] . V_39 / 100 ,
( V_34 == V_687 ) ? L_125 : L_126 ) ;
break;
case V_685 :
V_688 = F_7 ( V_5 ) ;
for ( V_34 = 0 ; V_34 < V_127 -> V_37 ; V_34 ++ ) {
if ( V_688 != V_127 -> V_160 [ V_34 ] . V_39 )
continue;
break;
}
V_687 = V_34 ;
for ( V_34 = 0 ; V_34 < V_127 -> V_37 ; V_34 ++ )
V_328 += sprintf ( V_686 + V_328 , L_127 , V_34 ,
( V_127 -> V_160 [ V_34 ] . V_39 == 0 ) ? L_128 :
( V_127 -> V_160 [ V_34 ] . V_39 == 1 ) ? L_129 :
( V_127 -> V_160 [ V_34 ] . V_39 == 2 ) ? L_130 : L_126 ,
( V_34 == V_687 ) ? L_125 : L_126 ) ;
break;
default:
break;
}
return V_328 ;
}
static int F_189 ( struct V_4 * V_5 , T_2 V_689 )
{
if ( V_689 ) {
if ( F_52 ( V_5 -> V_182 . V_183 ,
V_690 ) )
F_190 ( V_5 ) ;
F_191 ( V_5 , V_689 ) ;
} else
F_192 ( V_5 ) ;
return 0 ;
}
static int F_193 ( struct V_4 * V_5 )
{
if ( V_5 -> V_691 )
return V_5 -> V_692 ;
else
return F_49 ( V_5 -> V_6 , V_28 ,
V_693 , V_694 ) ;
}
static int F_194 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_569 * V_147 = & ( V_24 -> V_136 . V_147 ) ;
struct V_569 * V_695 =
& ( V_24 -> V_169 . V_147 ) ;
int V_39 ;
V_39 = ( V_147 -> V_160 [ V_147 -> V_37 - 1 ] . V_39 -
V_695 -> V_160 [ V_695 -> V_37 - 1 ] . V_39 ) *
100 /
V_695 -> V_160 [ V_695 -> V_37 - 1 ] . V_39 ;
return V_39 ;
}
static int F_195 ( struct V_4 * V_5 , T_2 V_39 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_569 * V_695 =
& ( V_24 -> V_169 . V_147 ) ;
struct V_422 * V_463 ;
struct V_1 * V_425 ;
if ( V_39 > 20 )
V_39 = 20 ;
V_463 = V_5 -> V_423 ;
if ( V_463 == NULL )
return - V_120 ;
V_425 = F_1 ( & V_463 -> V_426 ) ;
V_425 -> V_442 [ V_425 -> V_438 - 1 ] . V_444 =
V_695 -> V_160 [ V_695 -> V_37 - 1 ] . V_39 *
V_39 / 100 +
V_695 -> V_160 [ V_695 -> V_37 - 1 ] . V_39 ;
return 0 ;
}
static int F_196 ( struct V_4 * V_5 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_569 * V_149 = & ( V_24 -> V_136 . V_149 ) ;
struct V_569 * V_696 =
& ( V_24 -> V_169 . V_149 ) ;
int V_39 ;
V_39 = ( V_149 -> V_160 [ V_149 -> V_37 - 1 ] . V_39 -
V_696 -> V_160 [ V_696 -> V_37 - 1 ] . V_39 ) *
100 /
V_696 -> V_160 [ V_696 -> V_37 - 1 ] . V_39 ;
return V_39 ;
}
static int F_197 ( struct V_4 * V_5 , T_2 V_39 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
struct V_569 * V_696 =
& ( V_24 -> V_169 . V_149 ) ;
struct V_422 * V_463 ;
struct V_1 * V_425 ;
if ( V_39 > 20 )
V_39 = 20 ;
V_463 = V_5 -> V_423 ;
if ( V_463 == NULL )
return - V_120 ;
V_425 = F_1 ( & V_463 -> V_426 ) ;
V_425 -> V_442 [ V_425 -> V_438 - 1 ] . V_443 =
V_696 -> V_160 [ V_696 -> V_37 - 1 ] . V_39 *
V_39 / 100 +
V_696 -> V_160 [ V_696 -> V_37 - 1 ] . V_39 ;
return 0 ;
}
static int F_198 ( struct V_4 * V_5 , struct V_697 * V_698 )
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
V_698 -> clock [ V_34 ] = V_166 -> V_38 [ V_34 ] . V_161 ;
V_698 -> V_37 ++ ;
}
} else if ( V_5 -> V_53 == V_56 ) {
V_147 = V_5 -> V_57 . V_155 ;
for ( V_34 = 0 ; V_34 < V_147 -> V_37 ; V_34 ++ ) {
V_698 -> clock [ V_34 ] = V_147 -> V_38 [ V_34 ] . V_161 ;
V_698 -> V_37 ++ ;
}
}
return 0 ;
}
static T_2 F_199 ( struct V_4 * V_5 , T_2 V_161 )
{
struct V_23 * V_24 = (struct V_23 * ) ( V_5 -> V_25 ) ;
if ( V_161 >= V_699 && V_161 < V_700 )
return V_24 -> V_636 ;
else if ( V_161 >= V_700 )
return V_24 -> V_638 ;
else
return V_701 ;
}
static int F_200 ( struct V_4 * V_5 , struct V_697 * V_698 )
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
V_698 -> clock [ V_34 ] = V_167 -> V_38 [ V_34 ] . V_161 ;
V_698 -> V_702 [ V_34 ] = F_199 ( V_5 ,
V_167 -> V_38 [ V_34 ] . V_161 ) ;
V_698 -> V_37 ++ ;
}
} else if ( V_5 -> V_53 == V_56 ) {
V_149 = V_5 -> V_57 . V_68 ;
for ( V_34 = 0 ; V_34 < V_149 -> V_37 ; V_34 ++ ) {
V_698 -> clock [ V_34 ] = V_149 -> V_38 [ V_34 ] . V_161 ;
V_698 -> V_37 ++ ;
}
}
return 0 ;
}
static int F_201 ( struct V_4 * V_5 , enum V_703 type ,
struct V_697 * V_698 )
{
switch ( type ) {
case V_704 :
F_198 ( V_5 , V_698 ) ;
break;
case V_705 :
F_200 ( V_5 , V_698 ) ;
break;
default:
return - V_120 ;
}
return 0 ;
}
T_6 F_202 ( T_2 clock ,
T_2 V_706 )
{
T_6 V_34 ;
T_2 V_671 ;
T_2 V_277 = V_275 ( V_706 , ( T_2 ) V_576 ) ;
F_2 ((clock >= min), L_131 , return 0 ) ;
for ( V_34 = V_707 ; ; V_34 -- ) {
V_671 = clock >> V_34 ;
if ( V_671 >= V_277 || V_34 == 0 )
break;
}
return V_34 ;
}
int F_203 ( struct V_4 * V_5 )
{
int V_417 = 0 ;
V_5 -> V_708 = & V_709 ;
if ( V_5 -> V_53 == V_56 )
V_5 -> V_710 = & V_711 ;
else if ( V_5 -> V_53 == V_54 )
V_5 -> V_710 = & V_712 ;
F_204 ( V_5 ) ;
return V_417 ;
}
