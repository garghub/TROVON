static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
void T_1 * V_5 = F_2 ( V_4 -> V_5 . V_6 ) ;
int V_7 ;
F_3 ( V_2 -> V_8 , L_1 ) ;
for ( V_7 = 0 ; V_7 < 256 ; V_7 ++ ) {
F_4 ( V_4 -> V_5 . V_9 [ V_7 ] >> 2 , V_5 + 8 * V_7 + 0 ) ;
F_4 ( V_4 -> V_5 . V_10 [ V_7 ] >> 2 , V_5 + 8 * V_7 + 2 ) ;
F_4 ( V_4 -> V_5 . V_11 [ V_7 ] >> 2 , V_5 + 8 * V_7 + 4 ) ;
}
if ( V_4 -> V_5 . V_12 == 30 ) {
F_4 ( V_4 -> V_5 . V_9 [ V_7 - 1 ] >> 2 , V_5 + 8 * V_7 + 0 ) ;
F_4 ( V_4 -> V_5 . V_10 [ V_7 - 1 ] >> 2 , V_5 + 8 * V_7 + 2 ) ;
F_4 ( V_4 -> V_5 . V_11 [ V_7 - 1 ] >> 2 , V_5 + 8 * V_7 + 4 ) ;
}
}
int
F_5 ( struct V_3 * V_4 , bool V_13 )
{
struct V_14 * V_8 = V_4 -> V_15 . V_8 ;
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_19 * V_20 = F_6 ( V_8 ) -> V_21 ;
int V_22 = V_4 -> V_22 , V_23 ;
F_3 ( V_8 , L_2 , V_4 -> V_22 ) ;
F_3 ( V_8 , L_3 , V_13 ? L_4 : L_5 ) ;
if ( V_13 ) {
V_4 -> V_24 . V_25 ( V_4 , false ) ;
V_23 = F_7 ( V_20 , V_17 -> V_26 != 0x50 ? 7 : 5 ) ;
if ( V_23 ) {
F_8 ( V_8 , L_6 ) ;
return V_23 ;
}
F_9 ( V_20 , 0 , F_10 ( V_22 , V_27 ) , 2 ) ;
F_11 ( V_20 , V_28 ) ;
F_11 ( V_20 , 0 ) ;
if ( V_17 -> V_26 != 0x50 ) {
F_9 ( V_20 , 0 , F_12 ( V_22 , V_29 ) , 1 ) ;
F_11 ( V_20 , V_30 ) ;
}
F_9 ( V_20 , 0 , F_10 ( V_22 , V_31 ) , 1 ) ;
F_11 ( V_20 , V_32 ) ;
} else {
if ( V_4 -> V_24 . V_33 )
V_4 -> V_24 . V_34 ( V_4 , false ) ;
else
V_4 -> V_24 . V_25 ( V_4 , false ) ;
V_23 = F_7 ( V_20 , V_17 -> V_26 != 0x50 ? 10 : 8 ) ;
if ( V_23 ) {
F_8 ( V_8 , L_7 ) ;
return V_23 ;
}
F_9 ( V_20 , 0 , F_10 ( V_22 , V_27 ) , 2 ) ;
F_11 ( V_20 , V_4 -> V_5 . V_12 == 8 ?
V_35 :
V_36 ) ;
F_11 ( V_20 , V_4 -> V_5 . V_6 -> V_37 . V_38 >> 8 ) ;
if ( V_17 -> V_26 != 0x50 ) {
F_9 ( V_20 , 0 , F_12 ( V_22 , V_29 ) , 1 ) ;
F_11 ( V_20 , V_39 ) ;
}
F_9 ( V_20 , 0 , F_10 ( V_22 , V_40 ) , 2 ) ;
F_11 ( V_20 , V_4 -> V_41 . V_38 >> 8 ) ;
F_11 ( V_20 , 0 ) ;
F_9 ( V_20 , 0 , F_10 ( V_22 , V_31 ) , 1 ) ;
if ( V_17 -> V_26 != 0x50 )
if ( V_4 -> V_41 . V_42 == 0x7a00 ||
V_4 -> V_41 . V_42 == 0xfe00 )
F_11 ( V_20 , V_43 ) ;
else
if ( V_4 -> V_41 . V_42 == 0x7000 )
F_11 ( V_20 , V_44 ) ;
else
F_11 ( V_20 , V_45 ) ;
else
F_11 ( V_20 , V_45 ) ;
}
V_4 -> V_41 . V_13 = V_13 ;
return 0 ;
}
static int
F_13 ( struct V_3 * V_4 , bool V_46 )
{
struct V_19 * V_20 = F_6 ( V_4 -> V_15 . V_8 ) -> V_21 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
int V_51 = V_4 -> V_22 , V_23 ;
T_2 V_52 = 0x00 ;
V_48 = F_14 ( V_4 ) ;
V_50 = & V_48 -> V_15 ;
if ( V_48 -> V_53 == V_54 ) {
if ( V_4 -> V_15 . V_41 -> V_12 > V_50 -> V_55 . V_56 * 3 )
V_52 = V_57 ;
} else {
V_52 = V_48 -> V_53 ;
}
if ( V_48 -> V_58 == V_59 ) {
if ( V_50 -> V_55 . V_56 >= 8 )
V_52 |= V_60 ;
} else {
V_52 |= V_48 -> V_58 ;
}
V_23 = F_7 ( V_20 , 2 + ( V_46 ? 2 : 0 ) ) ;
if ( V_23 == 0 ) {
F_9 ( V_20 , 0 , F_10 ( V_51 , V_61 ) , 1 ) ;
F_11 ( V_20 , V_52 ) ;
if ( V_46 ) {
F_9 ( V_20 , 0 , V_62 , 1 ) ;
F_11 ( V_20 , 0 ) ;
F_15 ( V_20 ) ;
}
}
return V_23 ;
}
struct V_47 *
F_14 ( struct V_3 * V_4 )
{
struct V_14 * V_8 = V_4 -> V_15 . V_8 ;
struct V_49 * V_50 ;
struct V_1 * V_2 = F_16 ( V_4 ) ;
F_17 (connector, &dev->mode_config.connector_list, head) {
if ( V_50 -> V_63 )
if ( V_50 -> V_63 -> V_2 == V_2 )
return V_47 ( V_50 ) ;
}
return NULL ;
}
static int
F_18 ( struct V_3 * V_4 , bool V_46 )
{
struct V_47 * V_48 ;
struct V_1 * V_2 = & V_4 -> V_15 ;
struct V_14 * V_8 = V_2 -> V_8 ;
struct V_19 * V_20 = F_6 ( V_8 ) -> V_21 ;
struct V_64 * V_65 = & V_2 -> V_52 ;
struct V_64 * V_66 ;
int V_67 , V_23 ;
T_2 V_68 = 0 , V_69 , V_70 ;
F_3 ( V_8 , L_1 ) ;
V_48 = F_14 ( V_4 ) ;
if ( ! V_48 || ! V_48 -> V_71 ) {
F_8 ( V_8 , L_8 ) ;
V_67 = V_72 ;
} else {
V_67 = V_48 -> V_67 ;
}
if ( V_67 != V_72 )
V_66 = V_48 -> V_71 ;
else
V_66 = V_65 ;
V_69 = V_66 -> V_73 ;
V_70 = V_66 -> V_74 ;
if ( V_66 -> V_75 & V_76 )
V_70 *= 2 ;
if ( V_48 && ( V_48 -> V_77 == V_78 ||
( V_48 -> V_77 == V_79 &&
V_48 -> V_80 &&
F_19 ( V_48 -> V_80 ) ) ) ) {
T_2 V_81 = V_48 -> V_82 ;
T_2 V_83 = V_48 -> V_84 ;
T_2 V_85 = ( V_70 << 19 ) / V_69 ;
if ( V_81 ) {
V_69 -= ( V_81 * 2 ) ;
if ( V_83 ) V_70 -= ( V_83 * 2 ) ;
else V_70 = ( ( V_69 * V_85 ) + ( V_85 / 2 ) ) >> 19 ;
} else {
V_69 -= ( V_69 >> 4 ) + 32 ;
if ( V_83 ) V_70 -= ( V_83 * 2 ) ;
else V_70 = ( ( V_69 * V_85 ) + ( V_85 / 2 ) ) >> 19 ;
}
}
switch ( V_67 ) {
case V_86 :
V_69 = F_20 ( ( T_2 ) V_65 -> V_73 , V_69 ) ;
V_70 = F_20 ( ( T_2 ) V_65 -> V_74 , V_70 ) ;
case V_87 :
if ( V_70 < V_69 ) {
T_2 V_85 = ( V_65 -> V_73 << 19 ) / V_65 -> V_74 ;
V_69 = ( ( V_70 * V_85 ) + ( V_85 / 2 ) ) >> 19 ;
} else {
T_2 V_85 = ( V_65 -> V_74 << 19 ) / V_65 -> V_73 ;
V_70 = ( ( V_69 * V_85 ) + ( V_85 / 2 ) ) >> 19 ;
}
break;
default:
break;
}
if ( V_65 -> V_73 != V_69 || V_65 -> V_74 != V_70 ||
V_65 -> V_75 & V_88 ||
V_65 -> V_75 & V_76 )
V_68 |= V_89 ;
V_23 = F_7 ( V_20 , 5 ) ;
if ( V_23 )
return V_23 ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_90 ) , 1 ) ;
F_11 ( V_20 , V_68 ) ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_91 ) , 2 ) ;
F_11 ( V_20 , V_70 << 16 | V_69 ) ;
F_11 ( V_20 , V_70 << 16 | V_69 ) ;
if ( V_46 ) {
F_21 ( V_2 ) ;
F_22 ( V_8 ) ;
F_23 ( V_2 , V_2 -> V_41 , NULL ) ;
}
return 0 ;
}
int
F_24 ( struct V_14 * V_8 , int V_51 , int V_92 )
{
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_93 V_94 ;
T_3 V_95 , V_96 ;
int V_23 , V_97 , V_98 , V_99 , V_100 , V_101 ;
V_23 = F_25 ( V_8 , V_102 + V_51 , & V_94 ) ;
if ( V_23 )
return V_23 ;
if ( V_94 . V_103 . V_104 ) {
V_23 = F_26 ( V_8 , & V_94 , V_92 , & V_97 , & V_98 , & V_99 , & V_100 , & V_101 ) ;
if ( V_23 <= 0 )
return 0 ;
F_27 ( V_8 , L_9 ,
V_92 , V_23 , V_97 , V_98 , V_99 , V_100 , V_101 ) ;
V_95 = F_28 ( V_8 , V_94 . V_105 + 4 ) & 0xff00ff00 ;
V_96 = F_28 ( V_8 , V_94 . V_105 + 8 ) & 0x8000ff00 ;
F_29 ( V_8 , V_94 . V_105 + 0 , 0x10000611 ) ;
F_29 ( V_8 , V_94 . V_105 + 4 , V_95 | ( V_98 << 16 ) | V_97 ) ;
F_29 ( V_8 , V_94 . V_105 + 8 , V_96 | ( V_101 << 28 ) | ( V_100 << 16 ) | V_99 ) ;
} else
if ( V_17 -> V_26 < V_106 ) {
V_23 = F_30 ( V_8 , & V_94 , V_92 , & V_97 , & V_99 , & V_98 , & V_101 ) ;
if ( V_23 <= 0 )
return 0 ;
F_27 ( V_8 , L_10 ,
V_92 , V_23 , V_97 , V_99 , V_98 , V_101 ) ;
V_95 = F_28 ( V_8 , V_94 . V_105 + 4 ) & 0xffc00000 ;
F_29 ( V_8 , V_94 . V_105 + 0 , 0x50000610 ) ;
F_29 ( V_8 , V_94 . V_105 + 4 , V_95 | ( V_101 << 16 ) | ( V_98 << 8 ) | V_97 ) ;
F_29 ( V_8 , V_94 . V_105 + 8 , V_99 ) ;
} else {
V_23 = F_30 ( V_8 , & V_94 , V_92 , & V_97 , & V_99 , & V_98 , & V_101 ) ;
if ( V_23 <= 0 )
return 0 ;
F_27 ( V_8 , L_10 ,
V_92 , V_23 , V_97 , V_99 , V_98 , V_101 ) ;
F_31 ( V_8 , V_94 . V_105 + 0x0c , 0x00000000 , 0x00000100 ) ;
F_29 ( V_8 , V_94 . V_105 + 0x04 , ( V_101 << 16 ) | ( V_97 << 8 ) | V_98 ) ;
F_29 ( V_8 , V_94 . V_105 + 0x10 , V_99 << 16 ) ;
}
return 0 ;
}
static void
F_32 ( struct V_1 * V_2 )
{
struct V_14 * V_8 ;
struct V_3 * V_4 ;
if ( ! V_2 )
return;
V_8 = V_2 -> V_8 ;
V_4 = V_3 ( V_2 ) ;
F_3 ( V_8 , L_1 ) ;
F_33 ( & V_4 -> V_15 ) ;
F_34 ( V_4 -> V_5 . V_6 ) ;
F_35 ( NULL , & V_4 -> V_5 . V_6 ) ;
F_34 ( V_4 -> V_24 . V_6 ) ;
F_35 ( NULL , & V_4 -> V_24 . V_6 ) ;
F_36 ( V_4 ) ;
}
int
F_37 ( struct V_1 * V_2 , struct V_107 * V_108 ,
T_3 V_109 , T_3 V_110 , T_3 V_111 )
{
struct V_14 * V_8 = V_2 -> V_8 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_112 * V_24 = NULL ;
struct V_113 * V_114 ;
int V_23 = 0 , V_7 ;
if ( ! V_109 ) {
V_4 -> V_24 . V_25 ( V_4 , true ) ;
return 0 ;
}
if ( V_110 != 64 || V_111 != 64 )
return - V_115 ;
V_114 = F_38 ( V_8 , V_108 , V_109 ) ;
if ( ! V_114 )
return - V_116 ;
V_24 = F_39 ( V_114 ) ;
V_23 = F_40 ( V_24 ) ;
if ( V_23 )
goto V_117;
for ( V_7 = 0 ; V_7 < 64 * 64 ; V_7 ++ )
F_41 ( V_4 -> V_24 . V_6 , V_7 , F_42 ( V_24 , V_7 ) ) ;
F_34 ( V_24 ) ;
V_4 -> V_24 . V_118 ( V_4 , V_4 -> V_24 . V_6 -> V_37 . V_38 ) ;
V_4 -> V_24 . V_34 ( V_4 , true ) ;
V_117:
F_43 ( V_114 ) ;
return V_23 ;
}
int
F_44 ( struct V_1 * V_2 , int V_119 , int V_120 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
V_4 -> V_24 . V_121 ( V_4 , V_119 , V_120 ) ;
return 0 ;
}
static void
F_45 ( struct V_1 * V_2 , T_4 * V_9 , T_4 * V_10 , T_4 * V_11 ,
T_3 V_122 , T_3 V_123 )
{
int V_124 = ( V_122 + V_123 > 256 ) ? 256 : V_122 + V_123 , V_7 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
for ( V_7 = V_122 ; V_7 < V_124 ; V_7 ++ ) {
V_4 -> V_5 . V_9 [ V_7 ] = V_9 [ V_7 ] ;
V_4 -> V_5 . V_10 [ V_7 ] = V_10 [ V_7 ] ;
V_4 -> V_5 . V_11 [ V_7 ] = V_11 [ V_7 ] ;
}
if ( ! V_4 -> V_15 . V_41 ) {
V_4 -> V_5 . V_12 = 0 ;
return;
}
F_1 ( V_2 ) ;
}
static void
F_46 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_8 , L_11 ) ;
}
static void
F_47 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_8 , L_11 ) ;
}
static void
F_48 ( struct V_1 * V_2 , int V_52 )
{
}
static void
F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_14 * V_8 = V_2 -> V_8 ;
F_3 ( V_8 , L_2 , V_4 -> V_22 ) ;
F_21 ( V_2 ) ;
F_50 ( V_8 , V_4 -> V_22 ) ;
F_5 ( V_4 , true ) ;
}
static void
F_51 ( struct V_1 * V_2 )
{
struct V_14 * V_8 = V_2 -> V_8 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
F_3 ( V_8 , L_2 , V_4 -> V_22 ) ;
F_5 ( V_4 , false ) ;
F_52 ( V_8 , V_4 -> V_22 ) ;
F_22 ( V_8 ) ;
F_23 ( V_2 , V_2 -> V_41 , NULL ) ;
}
static bool
F_53 ( struct V_1 * V_2 , struct V_64 * V_52 ,
struct V_64 * V_125 )
{
return true ;
}
static int
F_54 ( struct V_1 * V_2 ,
struct V_126 * V_127 ,
int V_119 , int V_120 , bool V_128 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_14 * V_8 = V_4 -> V_15 . V_8 ;
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_19 * V_20 = F_6 ( V_8 ) -> V_21 ;
struct V_126 * V_129 ;
struct V_130 * V_41 ;
int V_23 ;
F_3 ( V_8 , L_2 , V_4 -> V_22 ) ;
if ( ! V_128 && ! V_2 -> V_41 ) {
F_3 ( V_8 , L_12 ) ;
return 0 ;
}
if ( V_128 ) {
V_129 = V_127 ;
V_41 = V_130 ( V_127 ) ;
} else {
V_129 = V_2 -> V_41 ;
V_41 = V_130 ( V_2 -> V_41 ) ;
V_23 = F_55 ( V_41 -> V_6 , V_131 ) ;
if ( V_23 )
return V_23 ;
if ( V_127 ) {
struct V_130 * V_132 = V_130 ( V_127 ) ;
F_56 ( V_132 -> V_6 ) ;
}
}
V_4 -> V_41 . V_38 = V_41 -> V_6 -> V_37 . V_38 ;
V_4 -> V_41 . V_42 = F_57 ( V_41 -> V_6 ) ;
V_4 -> V_41 . V_133 = V_129 -> V_134 / 8 ;
if ( ! V_4 -> V_41 . V_13 && V_17 -> V_26 != 0x50 ) {
V_23 = F_7 ( V_20 , 2 ) ;
if ( V_23 )
return V_23 ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_31 ) , 1 ) ;
F_11 ( V_20 , V_41 -> V_135 ) ;
}
V_23 = F_7 ( V_20 , 12 ) ;
if ( V_23 )
return V_23 ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_40 ) , 5 ) ;
F_11 ( V_20 , V_4 -> V_41 . V_38 >> 8 ) ;
F_11 ( V_20 , 0 ) ;
F_11 ( V_20 , ( V_129 -> V_111 << 16 ) | V_129 -> V_110 ) ;
F_11 ( V_20 , V_41 -> V_136 ) ;
F_11 ( V_20 , V_41 -> V_137 ) ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_27 ) , 1 ) ;
F_11 ( V_20 , V_41 -> V_15 . V_12 == 8 ?
V_35 : V_36 ) ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_138 ) , 1 ) ;
F_11 ( V_20 , V_139 ) ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_140 ) , 1 ) ;
F_11 ( V_20 , ( V_120 << 16 ) | V_119 ) ;
if ( V_4 -> V_5 . V_12 != V_41 -> V_15 . V_12 ) {
V_4 -> V_5 . V_12 = V_41 -> V_15 . V_12 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int
F_58 ( struct V_1 * V_2 , struct V_64 * V_65 ,
struct V_64 * V_52 , int V_119 , int V_120 ,
struct V_126 * V_141 )
{
struct V_14 * V_8 = V_2 -> V_8 ;
struct V_19 * V_20 = F_6 ( V_8 ) -> V_21 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
T_2 V_51 = V_4 -> V_22 * 0x400 ;
T_2 V_142 = ( V_52 -> V_75 & V_88 ) ? 2 : 1 ;
T_2 V_143 = ( V_52 -> V_75 & V_76 ) ? 2 : 1 ;
T_2 V_144 , V_145 , V_146 , V_147 , V_148 , V_149 ;
T_2 V_150 , V_151 , V_152 , V_153 , V_154 , V_155 ;
T_2 V_156 = 0 , V_157 = 1 ;
int V_23 ;
V_144 = V_52 -> V_158 ;
V_145 = V_52 -> V_159 - V_52 -> V_160 - 1 ;
V_146 = V_52 -> V_158 - V_52 -> V_159 ;
V_148 = V_145 + V_146 ;
V_147 = V_52 -> V_160 - V_52 -> V_73 ;
V_149 = V_52 -> V_158 - V_147 - 1 ;
V_150 = V_52 -> V_161 * V_143 / V_142 ;
V_151 = ( ( V_52 -> V_162 - V_52 -> V_163 ) * V_143 / V_142 ) - 1 ;
V_152 = ( V_52 -> V_161 - V_52 -> V_162 ) * V_143 / V_142 ;
V_154 = V_151 + V_152 ;
V_153 = ( V_52 -> V_163 - V_52 -> V_74 ) * V_143 / V_142 ;
V_155 = V_150 - V_153 - 1 ;
if ( V_52 -> V_75 & V_88 ) {
V_156 = V_150 + V_151 + V_152 ;
V_157 = V_156 + ( V_52 -> V_74 * V_143 / V_142 ) ;
V_150 = ( V_150 * 2 ) + 1 ;
}
V_23 = F_7 ( V_20 , 18 ) ;
if ( V_23 == 0 ) {
F_9 ( V_20 , 0 , 0x0804 + V_51 , 2 ) ;
F_11 ( V_20 , 0x00800000 | V_52 -> clock ) ;
F_11 ( V_20 , ( V_142 == 2 ) ? 2 : 0 ) ;
F_9 ( V_20 , 0 , 0x0810 + V_51 , 6 ) ;
F_11 ( V_20 , 0x00000000 ) ;
F_11 ( V_20 , ( V_150 << 16 ) | V_144 ) ;
F_11 ( V_20 , ( V_151 << 16 ) | V_145 ) ;
F_11 ( V_20 , ( V_154 << 16 ) | V_148 ) ;
F_11 ( V_20 , ( V_155 << 16 ) | V_149 ) ;
F_11 ( V_20 , ( V_156 << 16 ) | V_157 ) ;
F_9 ( V_20 , 0 , 0x082c + V_51 , 1 ) ;
F_11 ( V_20 , 0x00000000 ) ;
F_9 ( V_20 , 0 , 0x0900 + V_51 , 1 ) ;
F_11 ( V_20 , 0x00000311 ) ;
F_9 ( V_20 , 0 , 0x08c8 + V_51 , 1 ) ;
F_11 ( V_20 , ( V_65 -> V_74 << 16 ) | V_65 -> V_73 ) ;
F_9 ( V_20 , 0 , 0x08d4 + V_51 , 1 ) ;
F_11 ( V_20 , 0x00000000 ) ;
}
V_4 -> V_164 ( V_4 , false ) ;
V_4 -> V_165 ( V_4 , false ) ;
return F_54 ( V_2 , V_141 , V_119 , V_120 , false ) ;
}
static int
F_59 ( struct V_1 * V_2 , int V_119 , int V_120 ,
struct V_126 * V_141 )
{
int V_23 ;
F_21 ( V_2 ) ;
V_23 = F_54 ( V_2 , V_141 , V_119 , V_120 , false ) ;
if ( V_23 )
return V_23 ;
V_23 = F_22 ( V_2 -> V_8 ) ;
if ( V_23 )
return V_23 ;
return F_23 ( V_2 , V_2 -> V_41 , NULL ) ;
}
static int
F_60 ( struct V_1 * V_2 ,
struct V_126 * V_41 ,
int V_119 , int V_120 , enum V_166 V_167 )
{
int V_23 ;
F_21 ( V_2 ) ;
V_23 = F_54 ( V_2 , V_41 , V_119 , V_120 , true ) ;
if ( V_23 )
return V_23 ;
return F_22 ( V_2 -> V_8 ) ;
}
int
F_61 ( struct V_14 * V_8 , int V_22 )
{
struct V_3 * V_4 = NULL ;
int V_23 , V_7 ;
F_3 ( V_8 , L_1 ) ;
V_4 = F_62 ( sizeof( * V_4 ) , V_168 ) ;
if ( ! V_4 )
return - V_169 ;
for ( V_7 = 0 ; V_7 < 256 ; V_7 ++ ) {
V_4 -> V_5 . V_9 [ V_7 ] = V_7 << 8 ;
V_4 -> V_5 . V_10 [ V_7 ] = V_7 << 8 ;
V_4 -> V_5 . V_11 [ V_7 ] = V_7 << 8 ;
}
V_4 -> V_5 . V_12 = 0 ;
V_23 = F_63 ( V_8 , 4096 , 0x100 , V_131 ,
0 , 0x0000 , & V_4 -> V_5 . V_6 ) ;
if ( ! V_23 ) {
V_23 = F_55 ( V_4 -> V_5 . V_6 , V_131 ) ;
if ( ! V_23 )
V_23 = F_40 ( V_4 -> V_5 . V_6 ) ;
if ( V_23 )
F_35 ( NULL , & V_4 -> V_5 . V_6 ) ;
}
if ( V_23 ) {
F_36 ( V_4 ) ;
return V_23 ;
}
V_4 -> V_22 = V_22 ;
V_4 -> V_164 = F_13 ;
V_4 -> V_165 = F_18 ;
F_64 ( V_8 , & V_4 -> V_15 , & V_170 ) ;
F_65 ( & V_4 -> V_15 , & V_171 ) ;
F_66 ( & V_4 -> V_15 , 256 ) ;
V_23 = F_63 ( V_8 , 64 * 64 * 4 , 0x100 , V_131 ,
0 , 0x0000 , & V_4 -> V_24 . V_6 ) ;
if ( ! V_23 ) {
V_23 = F_55 ( V_4 -> V_24 . V_6 , V_131 ) ;
if ( ! V_23 )
V_23 = F_40 ( V_4 -> V_24 . V_6 ) ;
if ( V_23 )
F_35 ( NULL , & V_4 -> V_24 . V_6 ) ;
}
F_67 ( V_4 ) ;
return 0 ;
}
