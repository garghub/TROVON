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
F_11 ( V_20 , ( V_4 -> V_5 . V_6 -> V_37 . V_38 . V_39 << V_40 ) >> 8 ) ;
if ( V_17 -> V_26 != 0x50 ) {
F_9 ( V_20 , 0 , F_12 ( V_22 , V_29 ) , 1 ) ;
F_11 ( V_20 , V_41 ) ;
}
F_9 ( V_20 , 0 , F_10 ( V_22 , V_42 ) , 2 ) ;
F_11 ( V_20 , V_4 -> V_43 . V_44 >> 8 ) ;
F_11 ( V_20 , 0 ) ;
F_9 ( V_20 , 0 , F_10 ( V_22 , V_31 ) , 1 ) ;
if ( V_17 -> V_26 != 0x50 )
if ( V_4 -> V_43 . V_45 == 0x7a00 ||
V_4 -> V_43 . V_45 == 0xfe00 )
F_11 ( V_20 , V_46 ) ;
else
if ( V_4 -> V_43 . V_45 == 0x7000 )
F_11 ( V_20 , V_47 ) ;
else
F_11 ( V_20 , V_48 ) ;
else
F_11 ( V_20 , V_48 ) ;
}
V_4 -> V_43 . V_13 = V_13 ;
return 0 ;
}
static int
F_13 ( struct V_3 * V_4 , bool V_49 , bool V_50 )
{
struct V_14 * V_8 = V_4 -> V_15 . V_8 ;
struct V_19 * V_20 = F_6 ( V_8 ) -> V_21 ;
int V_23 ;
F_3 ( V_8 , L_1 ) ;
V_23 = F_7 ( V_20 , 2 + ( V_50 ? 2 : 0 ) ) ;
if ( V_23 ) {
F_8 ( V_8 , L_8 ) ;
return V_23 ;
}
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_51 ) , 1 ) ;
if ( V_49 )
F_11 ( V_20 , V_52 ) ;
else
F_11 ( V_20 , V_53 ) ;
if ( V_50 ) {
F_9 ( V_20 , 0 , V_54 , 1 ) ;
F_11 ( V_20 , 0 ) ;
F_14 ( V_20 ) ;
}
return 0 ;
}
struct V_55 *
F_15 ( struct V_3 * V_4 )
{
struct V_14 * V_8 = V_4 -> V_15 . V_8 ;
struct V_56 * V_57 ;
struct V_1 * V_2 = F_16 ( V_4 ) ;
F_17 (connector, &dev->mode_config.connector_list, head) {
if ( V_57 -> V_58 )
if ( V_57 -> V_58 -> V_2 == V_2 )
return V_55 ( V_57 ) ;
}
return NULL ;
}
static int
F_18 ( struct V_3 * V_4 , int V_59 , bool V_50 )
{
struct V_55 * V_60 =
F_15 ( V_4 ) ;
struct V_14 * V_8 = V_4 -> V_15 . V_8 ;
struct V_19 * V_20 = F_6 ( V_8 ) -> V_21 ;
struct V_61 * V_62 = NULL ;
struct V_61 * V_63 = & V_4 -> V_15 . V_63 ;
T_2 V_64 , V_65 , V_66 , V_67 ;
int V_23 ;
F_3 ( V_8 , L_1 ) ;
switch ( V_59 ) {
case V_68 :
break;
default:
if ( ! V_60 || ! V_60 -> V_62 ) {
F_8 ( V_8 , L_9 ) ;
V_59 = V_68 ;
} else {
V_62 = V_60 -> V_62 ;
}
break;
}
switch ( V_59 ) {
case V_69 :
V_66 = ( V_62 -> V_70 << 19 ) / V_63 -> V_70 ;
V_67 = ( V_62 -> V_71 << 19 ) / V_63 -> V_71 ;
if ( V_67 > V_66 ) {
V_64 = ( V_63 -> V_70 * V_66 ) >> 19 ;
V_65 = ( V_63 -> V_71 * V_66 ) >> 19 ;
} else {
V_64 = ( V_63 -> V_70 * V_67 ) >> 19 ;
V_65 = ( V_63 -> V_71 * V_67 ) >> 19 ;
}
break;
case V_72 :
V_64 = V_62 -> V_70 ;
V_65 = V_62 -> V_71 ;
break;
case V_73 :
case V_68 :
default:
V_64 = V_63 -> V_70 ;
V_65 = V_63 -> V_71 ;
break;
}
V_23 = F_7 ( V_20 , V_50 ? 7 : 5 ) ;
if ( V_23 )
return V_23 ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_74 ) , 1 ) ;
if ( ( V_63 -> V_75 & V_76 ) ||
( V_63 -> V_75 & V_77 ) ||
V_63 -> V_70 != V_64 || V_63 -> V_71 != V_65 ) {
F_11 ( V_20 , V_78 ) ;
} else {
F_11 ( V_20 , V_79 ) ;
}
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_80 ) , 2 ) ;
F_11 ( V_20 , V_65 << 16 | V_64 ) ;
F_11 ( V_20 , V_65 << 16 | V_64 ) ;
if ( V_50 ) {
F_9 ( V_20 , 0 , V_54 , 1 ) ;
F_11 ( V_20 , 0 ) ;
F_14 ( V_20 ) ;
}
return 0 ;
}
int
F_19 ( struct V_14 * V_8 , int V_81 , int V_82 )
{
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_83 V_84 ;
T_2 V_85 , V_86 ;
int V_23 , V_87 , V_88 , V_89 , V_90 , V_91 ;
V_23 = F_20 ( V_8 , V_92 + V_81 , & V_84 ) ;
if ( V_23 )
return V_23 ;
if ( V_84 . V_93 . V_94 ) {
V_23 = F_21 ( V_8 , & V_84 , V_82 , & V_87 , & V_88 , & V_89 , & V_90 , & V_91 ) ;
if ( V_23 <= 0 )
return 0 ;
F_22 ( V_8 , L_10 ,
V_82 , V_23 , V_87 , V_88 , V_89 , V_90 , V_91 ) ;
V_85 = F_23 ( V_8 , V_84 . V_95 + 4 ) & 0xff00ff00 ;
V_86 = F_23 ( V_8 , V_84 . V_95 + 8 ) & 0x8000ff00 ;
F_24 ( V_8 , V_84 . V_95 + 0 , 0x10000611 ) ;
F_24 ( V_8 , V_84 . V_95 + 4 , V_85 | ( V_88 << 16 ) | V_87 ) ;
F_24 ( V_8 , V_84 . V_95 + 8 , V_86 | ( V_91 << 28 ) | ( V_90 << 16 ) | V_89 ) ;
} else
if ( V_17 -> V_26 < V_96 ) {
V_23 = F_25 ( V_8 , & V_84 , V_82 , & V_87 , & V_89 , & V_88 , & V_91 ) ;
if ( V_23 <= 0 )
return 0 ;
F_22 ( V_8 , L_11 ,
V_82 , V_23 , V_87 , V_89 , V_88 , V_91 ) ;
V_85 = F_23 ( V_8 , V_84 . V_95 + 4 ) & 0xffc00000 ;
F_24 ( V_8 , V_84 . V_95 + 0 , 0x50000610 ) ;
F_24 ( V_8 , V_84 . V_95 + 4 , V_85 | ( V_91 << 16 ) | ( V_88 << 8 ) | V_87 ) ;
F_24 ( V_8 , V_84 . V_95 + 8 , V_89 ) ;
} else {
V_23 = F_25 ( V_8 , & V_84 , V_82 , & V_87 , & V_89 , & V_88 , & V_91 ) ;
if ( V_23 <= 0 )
return 0 ;
F_22 ( V_8 , L_11 ,
V_82 , V_23 , V_87 , V_89 , V_88 , V_91 ) ;
F_26 ( V_8 , V_84 . V_95 + 0x0c , 0x00000000 , 0x00000100 ) ;
F_24 ( V_8 , V_84 . V_95 + 0x04 , ( V_91 << 16 ) | ( V_87 << 8 ) | V_88 ) ;
F_24 ( V_8 , V_84 . V_95 + 0x10 , V_89 << 16 ) ;
}
return 0 ;
}
static void
F_27 ( struct V_1 * V_2 )
{
struct V_14 * V_8 ;
struct V_3 * V_4 ;
if ( ! V_2 )
return;
V_8 = V_2 -> V_8 ;
V_4 = V_3 ( V_2 ) ;
F_3 ( V_8 , L_1 ) ;
F_28 ( & V_4 -> V_15 ) ;
F_29 ( V_4 ) ;
F_30 ( V_4 -> V_5 . V_6 ) ;
F_31 ( NULL , & V_4 -> V_5 . V_6 ) ;
F_30 ( V_4 -> V_24 . V_6 ) ;
F_31 ( NULL , & V_4 -> V_24 . V_6 ) ;
F_32 ( V_4 -> V_63 ) ;
F_32 ( V_4 ) ;
}
int
F_33 ( struct V_1 * V_2 , struct V_97 * V_98 ,
T_2 V_99 , T_2 V_100 , T_2 V_101 )
{
struct V_14 * V_8 = V_2 -> V_8 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_102 * V_24 = NULL ;
struct V_103 * V_104 ;
int V_23 = 0 , V_7 ;
if ( ! V_99 ) {
V_4 -> V_24 . V_25 ( V_4 , true ) ;
return 0 ;
}
if ( V_100 != 64 || V_101 != 64 )
return - V_105 ;
V_104 = F_34 ( V_8 , V_98 , V_99 ) ;
if ( ! V_104 )
return - V_106 ;
V_24 = F_35 ( V_104 ) ;
V_23 = F_36 ( V_24 ) ;
if ( V_23 )
goto V_107;
for ( V_7 = 0 ; V_7 < 64 * 64 ; V_7 ++ )
F_37 ( V_4 -> V_24 . V_6 , V_7 , F_38 ( V_24 , V_7 ) ) ;
F_30 ( V_24 ) ;
V_4 -> V_24 . V_108 ( V_4 , V_4 -> V_24 . V_6 -> V_37 . V_38 . V_39 << V_40 ) ;
V_4 -> V_24 . V_34 ( V_4 , true ) ;
V_107:
F_39 ( V_104 ) ;
return V_23 ;
}
int
F_40 ( struct V_1 * V_2 , int V_109 , int V_110 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
V_4 -> V_24 . V_111 ( V_4 , V_109 , V_110 ) ;
return 0 ;
}
static void
F_41 ( struct V_1 * V_2 , T_3 * V_9 , T_3 * V_10 , T_3 * V_11 ,
T_2 V_39 , T_2 V_112 )
{
int V_113 = ( V_39 + V_112 > 256 ) ? 256 : V_39 + V_112 , V_7 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
for ( V_7 = V_39 ; V_7 < V_113 ; V_7 ++ ) {
V_4 -> V_5 . V_9 [ V_7 ] = V_9 [ V_7 ] ;
V_4 -> V_5 . V_10 [ V_7 ] = V_10 [ V_7 ] ;
V_4 -> V_5 . V_11 [ V_7 ] = V_11 [ V_7 ] ;
}
if ( ! V_4 -> V_15 . V_43 ) {
V_4 -> V_5 . V_12 = 0 ;
return;
}
F_1 ( V_2 ) ;
}
static void
F_42 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_8 , L_12 ) ;
}
static void
F_43 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_8 , L_12 ) ;
}
static void
F_44 ( struct V_1 * V_2 , int V_63 )
{
}
static int
F_45 ( struct V_1 * V_2 )
{
struct V_14 * V_8 = V_2 -> V_8 ;
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_114 * V_115 = & V_17 -> V_116 . V_117 ;
struct F_6 * V_118 = F_6 ( V_8 ) ;
struct V_19 * V_20 = V_118 -> V_21 ;
T_4 V_39 ;
int V_23 ;
V_23 = F_7 ( V_20 , 6 ) ;
if ( V_23 )
return V_23 ;
F_9 ( V_20 , 0 , 0x0084 , 1 ) ;
F_11 ( V_20 , 0x80000000 ) ;
F_9 ( V_20 , 0 , 0x0080 , 1 ) ;
F_11 ( V_20 , 0 ) ;
F_9 ( V_20 , 0 , 0x0084 , 1 ) ;
F_11 ( V_20 , 0x00000000 ) ;
F_46 ( V_118 -> V_119 , 0x000 , 0x00000000 ) ;
F_14 ( V_20 ) ;
V_39 = V_115 -> V_120 ( V_8 ) ;
do {
if ( F_47 ( V_118 -> V_119 , 0x000 ) )
return 0 ;
} while ( V_115 -> V_120 ( V_8 ) - V_39 < 2000000000ULL );
return - V_121 ;
}
static void
F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_14 * V_8 = V_2 -> V_8 ;
F_3 ( V_8 , L_2 , V_4 -> V_22 ) ;
F_49 ( V_2 ) ;
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
F_45 ( V_2 ) ;
F_53 ( V_2 , V_2 -> V_43 , NULL ) ;
}
static bool
F_54 ( struct V_1 * V_2 , struct V_61 * V_63 ,
struct V_61 * V_122 )
{
return true ;
}
static int
F_55 ( struct V_1 * V_2 ,
struct V_123 * V_124 ,
int V_109 , int V_110 , bool V_125 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_14 * V_8 = V_4 -> V_15 . V_8 ;
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_19 * V_20 = F_6 ( V_8 ) -> V_21 ;
struct V_123 * V_126 = V_4 -> V_15 . V_43 ;
struct V_127 * V_43 = V_127 ( V_126 ) ;
int V_23 ;
F_3 ( V_8 , L_2 , V_4 -> V_22 ) ;
if ( V_125 ) {
V_126 = V_124 ;
V_43 = V_127 ( V_124 ) ;
} else {
V_23 = F_56 ( V_43 -> V_6 , V_128 ) ;
if ( V_23 )
return V_23 ;
if ( V_124 ) {
struct V_127 * V_129 = V_127 ( V_124 ) ;
F_57 ( V_129 -> V_6 ) ;
}
}
V_4 -> V_43 . V_44 = V_43 -> V_6 -> V_37 . V_38 . V_39 << V_40 ;
V_4 -> V_43 . V_45 = F_58 ( V_43 -> V_6 ) ;
V_4 -> V_43 . V_130 = V_126 -> V_131 / 8 ;
if ( ! V_4 -> V_43 . V_13 && V_17 -> V_26 != 0x50 ) {
V_23 = F_7 ( V_20 , 2 ) ;
if ( V_23 )
return V_23 ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_31 ) , 1 ) ;
F_11 ( V_20 , V_43 -> V_132 ) ;
}
V_23 = F_7 ( V_20 , 12 ) ;
if ( V_23 )
return V_23 ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_42 ) , 5 ) ;
F_11 ( V_20 , V_4 -> V_43 . V_44 >> 8 ) ;
F_11 ( V_20 , 0 ) ;
F_11 ( V_20 , ( V_126 -> V_101 << 16 ) | V_126 -> V_100 ) ;
F_11 ( V_20 , V_43 -> V_133 ) ;
F_11 ( V_20 , V_43 -> V_134 ) ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_27 ) , 1 ) ;
F_11 ( V_20 , V_43 -> V_15 . V_12 == 8 ?
V_35 : V_36 ) ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_135 ) , 1 ) ;
F_11 ( V_20 , V_136 ) ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_137 ) , 1 ) ;
F_11 ( V_20 , ( V_110 << 16 ) | V_109 ) ;
if ( V_4 -> V_5 . V_12 != V_43 -> V_15 . V_12 ) {
V_4 -> V_5 . V_12 = V_43 -> V_15 . V_12 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int
F_59 ( struct V_1 * V_2 , struct V_61 * V_63 ,
struct V_61 * V_122 , int V_109 , int V_110 ,
struct V_123 * V_138 )
{
struct V_14 * V_8 = V_2 -> V_8 ;
struct V_19 * V_20 = F_6 ( V_8 ) -> V_21 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_55 * V_60 = NULL ;
T_2 V_139 , V_140 , V_141 , V_142 ;
T_2 V_143 , V_144 , V_145 , V_146 ;
int V_23 ;
V_60 = F_15 ( V_4 ) ;
* V_4 -> V_63 = * V_122 ;
F_3 ( V_8 , L_2 , V_4 -> V_22 ) ;
V_139 = V_122 -> V_147 - V_122 -> V_148 ;
V_140 = V_122 -> V_149 - V_122 -> V_150 ;
V_141 = V_122 -> V_151 - V_122 -> V_148 ;
V_142 = V_122 -> V_152 - V_122 -> V_150 ;
V_143 = V_122 -> V_151 -
V_122 -> V_148 + V_122 -> V_70 ;
V_144 = V_122 -> V_152 -
V_122 -> V_150 + V_122 -> V_71 ;
V_145 = 2 * V_122 -> V_152 -
V_122 -> V_150 + V_122 -> V_71 ;
V_146 = V_122 -> V_152 -
V_122 -> V_150 + V_122 -> V_152 ;
if ( V_122 -> V_75 & V_77 ) {
V_140 /= 2 ;
V_142 /= 2 ;
V_144 /= 2 ;
V_145 /= 2 ;
V_146 /= 2 ;
if ( V_122 -> V_75 & V_76 ) {
V_142 -= 1 ;
V_144 -= 1 ;
V_145 -= 1 ;
V_146 -= 1 ;
}
}
V_23 = F_7 ( V_20 , 17 ) ;
if ( V_23 )
return V_23 ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , CLOCK ) , 2 ) ;
F_11 ( V_20 , V_122 -> clock | 0x800000 ) ;
F_11 ( V_20 , ( V_122 -> V_75 & V_77 ) ? 2 : 0 ) ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_153 ) , 5 ) ;
F_11 ( V_20 , 0 ) ;
F_11 ( V_20 , ( V_122 -> V_152 << 16 ) | V_122 -> V_151 ) ;
F_11 ( V_20 , ( V_140 - 1 ) << 16 | ( V_139 - 1 ) ) ;
F_11 ( V_20 , ( V_142 - 1 ) << 16 |
( V_141 - 1 ) ) ;
F_11 ( V_20 , ( V_144 - 1 ) << 16 | ( V_143 - 1 ) ) ;
if ( V_122 -> V_75 & V_77 ) {
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_154 ) , 1 ) ;
F_11 ( V_20 , ( V_146 - 1 ) << 16 | ( V_145 - 1 ) ) ;
} else {
F_11 ( V_20 , 0 ) ;
F_11 ( V_20 , 0 ) ;
}
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_155 ) , 1 ) ;
F_11 ( V_20 , 0 ) ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_156 ) , 1 ) ;
F_11 ( V_20 , ( V_63 -> V_71 << 16 ) | V_63 -> V_70 ) ;
F_9 ( V_20 , 0 , F_10 ( V_4 -> V_22 , V_157 ) , 1 ) ;
F_11 ( V_20 , F_60 ( 0 , 0 ) ) ;
V_4 -> V_158 ( V_4 , V_60 -> V_159 , false ) ;
V_4 -> V_160 ( V_4 , V_60 -> V_59 , false ) ;
return F_55 ( V_2 , V_138 , V_109 , V_110 , false ) ;
}
static int
F_61 ( struct V_1 * V_2 , int V_109 , int V_110 ,
struct V_123 * V_138 )
{
int V_23 ;
F_49 ( V_2 ) ;
V_23 = F_55 ( V_2 , V_138 , V_109 , V_110 , false ) ;
if ( V_23 )
return V_23 ;
V_23 = F_45 ( V_2 ) ;
if ( V_23 )
return V_23 ;
return F_53 ( V_2 , V_2 -> V_43 , NULL ) ;
}
static int
F_62 ( struct V_1 * V_2 ,
struct V_123 * V_43 ,
int V_109 , int V_110 , enum V_161 V_162 )
{
int V_23 ;
F_49 ( V_2 ) ;
V_23 = F_55 ( V_2 , V_43 , V_109 , V_110 , true ) ;
if ( V_23 )
return V_23 ;
return F_45 ( V_2 ) ;
}
int
F_63 ( struct V_14 * V_8 , int V_22 )
{
struct V_3 * V_4 = NULL ;
int V_23 , V_7 ;
F_3 ( V_8 , L_1 ) ;
V_4 = F_64 ( sizeof( * V_4 ) , V_163 ) ;
if ( ! V_4 )
return - V_164 ;
V_4 -> V_63 = F_64 ( sizeof( * V_4 -> V_63 ) , V_163 ) ;
if ( ! V_4 -> V_63 ) {
F_32 ( V_4 ) ;
return - V_164 ;
}
for ( V_7 = 0 ; V_7 < 256 ; V_7 ++ ) {
V_4 -> V_5 . V_9 [ V_7 ] = V_7 << 8 ;
V_4 -> V_5 . V_10 [ V_7 ] = V_7 << 8 ;
V_4 -> V_5 . V_11 [ V_7 ] = V_7 << 8 ;
}
V_4 -> V_5 . V_12 = 0 ;
V_23 = F_65 ( V_8 , NULL , 4096 , 0x100 , V_128 ,
0 , 0x0000 , & V_4 -> V_5 . V_6 ) ;
if ( ! V_23 ) {
V_23 = F_56 ( V_4 -> V_5 . V_6 , V_128 ) ;
if ( ! V_23 )
V_23 = F_36 ( V_4 -> V_5 . V_6 ) ;
if ( V_23 )
F_31 ( NULL , & V_4 -> V_5 . V_6 ) ;
}
if ( V_23 ) {
F_32 ( V_4 -> V_63 ) ;
F_32 ( V_4 ) ;
return V_23 ;
}
V_4 -> V_22 = V_22 ;
V_4 -> V_158 = F_13 ;
V_4 -> V_160 = F_18 ;
F_66 ( V_8 , & V_4 -> V_15 , & V_165 ) ;
F_67 ( & V_4 -> V_15 , & V_166 ) ;
F_68 ( & V_4 -> V_15 , 256 ) ;
V_23 = F_65 ( V_8 , NULL , 64 * 64 * 4 , 0x100 , V_128 ,
0 , 0x0000 , & V_4 -> V_24 . V_6 ) ;
if ( ! V_23 ) {
V_23 = F_56 ( V_4 -> V_24 . V_6 , V_128 ) ;
if ( ! V_23 )
V_23 = F_36 ( V_4 -> V_24 . V_6 ) ;
if ( V_23 )
F_31 ( NULL , & V_4 -> V_24 . V_6 ) ;
}
F_69 ( V_4 ) ;
return 0 ;
}
