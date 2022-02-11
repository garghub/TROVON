static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
T_1 V_12 ;
if ( V_7 && V_7 -> V_13 ) {
if ( V_5 < V_7 -> V_13 )
return V_7 -> V_14 [ V_5 ] . V_15 ;
else
return V_7 -> V_14 [ V_7 -> V_13 - 1 ] . V_15 ;
} else {
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
if ( V_4 -> V_14 [ V_12 ] . V_5 == V_5 )
return V_4 -> V_14 [ V_12 ] . V_17 ;
}
return V_4 -> V_14 [ V_4 -> V_16 - 1 ] . V_17 ;
}
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_17 )
{
struct V_6 * V_7 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
T_1 V_12 ;
if ( V_7 && V_7 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_7 -> V_13 ; V_12 ++ ) {
if ( V_7 -> V_14 [ V_12 ] . V_15 == V_17 )
return V_12 ;
}
return V_7 -> V_13 - 1 ;
} else {
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
if ( V_4 -> V_14 [ V_12 ] . V_17 == V_17 )
return V_4 -> V_14 [ V_12 ] . V_5 ;
}
return V_4 -> V_14 [ V_4 -> V_16 - 1 ] . V_5 ;
}
}
static void F_3 ( struct V_1 * V_2 , bool V_18 )
{
#if 0
u32 v = RREG32(mmDOUT_SCRATCH3);
if (enable)
v |= 0x4;
else
v &= 0xFFFFFFFB;
WREG32(mmDOUT_SCRATCH3, v);
#endif
}
static void F_4 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
T_2 * V_21 )
{
T_1 V_12 ;
T_1 V_22 = 0 ;
T_1 V_23 = 0 ;
for ( V_12 = 0 ; V_12 < V_24 ; V_12 ++ ) {
if ( V_21 [ V_12 ] . V_25 > V_23 ) {
V_20 -> V_14 [ V_22 ] . V_26 =
V_21 [ V_12 ] . V_25 ;
V_20 -> V_14 [ V_22 ] . V_5 =
V_21 [ V_12 ] . V_27 ;
V_23 = V_21 [ V_12 ] . V_25 ;
V_22 ++ ;
}
}
V_20 -> V_28 = V_22 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 * V_21 )
{
T_1 V_12 , V_29 ;
for ( V_12 = 0 ; V_12 < V_24 ; V_12 ++ ) {
if ( V_21 [ V_12 ] . V_25 != 0 ) {
V_4 -> V_14 [ V_21 [ V_12 ] . V_27 ] . V_17 =
V_21 [ V_12 ] . V_30 ;
V_4 -> V_14 [ V_21 [ V_12 ] . V_27 ] . V_5 =
V_21 [ V_12 ] . V_27 ;
}
}
for ( V_12 = 0 ; V_12 < V_31 ; V_12 ++ ) {
if ( V_4 -> V_14 [ V_12 ] . V_17 == 0 ) {
for ( V_29 = V_12 + 1 ; V_29 < V_31 ; V_29 ++ ) {
if ( V_4 -> V_14 [ V_29 ] . V_17 != 0 ) {
V_4 -> V_14 [ V_12 ] =
V_4 -> V_14 [ V_29 ] ;
V_4 -> V_14 [ V_29 ] . V_17 = 0 ;
break;
}
}
if ( V_29 == V_31 )
break;
}
}
V_4 -> V_16 = V_12 ;
}
static struct V_32 * F_6 ( struct V_33 * V_34 )
{
struct V_32 * V_35 = V_34 -> V_36 ;
return V_35 ;
}
static struct V_37 * F_7 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_8 . V_9 . V_39 ;
return V_38 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_40 * V_41 )
{
const struct V_40 * V_42 = V_41 ;
T_1 V_43 ;
T_1 V_44 = 0 ;
if ( V_42 == NULL )
return - V_45 ;
while ( V_42 -> V_46 != 0xFFFFFFFF ) {
if ( V_42 -> type == V_47 ) {
V_44 |= ( ( V_42 -> V_48 << V_42 -> V_49 ) & V_42 -> V_50 ) ;
} else {
switch ( V_42 -> type ) {
case V_51 :
V_43 = F_9 ( V_42 -> V_46 ) ;
break;
case V_52 :
V_43 = F_10 ( V_42 -> V_46 ) ;
break;
default:
V_43 = F_11 ( V_42 -> V_46 ) ;
break;
}
V_43 &= ~ V_42 -> V_50 ;
V_43 |= ( ( V_42 -> V_48 << V_42 -> V_49 ) & V_42 -> V_50 ) ;
V_43 |= V_44 ;
V_44 = 0 ;
switch ( V_42 -> type ) {
case V_51 :
F_12 ( V_42 -> V_46 , V_43 ) ;
break;
case V_52 :
F_13 ( V_42 -> V_46 , V_43 ) ;
break;
default:
F_14 ( V_42 -> V_46 , V_43 ) ;
break;
}
}
V_42 ++ ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_43 ;
if ( V_38 -> V_53 ) {
V_43 = F_10 ( V_54 ) ;
if ( V_18 )
V_43 |= V_55 ;
else
V_43 &= ~ V_55 ;
F_13 ( V_54 , V_43 ) ;
}
if ( V_38 -> V_56 ) {
V_43 = F_10 ( V_57 ) ;
if ( V_18 )
V_43 |= V_58 ;
else
V_43 &= ~ V_58 ;
F_13 ( V_57 , V_43 ) ;
}
if ( V_38 -> V_59 ) {
V_43 = F_10 ( V_60 ) ;
if ( V_18 )
V_43 |= V_61 ;
else
V_43 &= ~ V_61 ;
F_13 ( V_60 , V_43 ) ;
}
if ( V_38 -> V_62 ) {
V_43 = F_10 ( V_63 ) ;
if ( V_18 )
V_43 |= V_64 ;
else
V_43 &= ~ V_64 ;
F_13 ( V_63 , V_43 ) ;
}
}
static int F_16 ( struct V_1 * V_2 , bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
if ( V_38 -> V_53 ||
V_38 -> V_56 ||
V_38 -> V_59 ||
V_38 -> V_62 ) {
F_17 ( V_2 ) ;
if ( V_18 ) {
V_65 = F_8 ( V_2 , V_66 ) ;
if ( V_65 ) {
F_18 ( V_2 ) ;
return V_65 ;
}
}
F_15 ( V_2 , V_18 ) ;
F_18 ( V_2 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 = 0 ;
if ( V_38 -> V_67 ) {
if ( V_18 ) {
V_65 = F_20 ( V_2 , V_68 ) ;
if ( V_65 )
V_38 -> V_69 = false ;
else
V_38 -> V_69 = true ;
} else if ( V_38 -> V_69 ) {
F_20 ( V_2 , V_70 ) ;
V_38 -> V_69 = false ;
}
}
return V_65 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_71 ;
int V_65 ;
V_65 = F_22 ( V_2 , V_72 +
F_23 ( V_73 , V_74 ) ,
& V_71 , V_38 -> V_75 ) ;
if ( V_65 == 0 )
V_38 -> V_76 = V_71 ;
V_65 = F_22 ( V_2 , V_72 +
F_23 ( V_73 , V_77 ) ,
& V_71 , V_38 -> V_75 ) ;
if ( V_65 == 0 )
V_38 -> V_78 = V_71 ;
return V_65 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_38 -> V_79 = 1 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_81 ) ,
& V_38 -> V_79 ,
sizeof( V_82 ) , V_38 -> V_75 ) ;
return V_65 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_38 -> V_83 = 1 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_84 ) ,
& V_38 -> V_83 ,
sizeof( V_82 ) , V_38 -> V_75 ) ;
return V_65 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_85 ) ,
& V_38 -> V_86 ,
sizeof( V_82 ) , V_38 -> V_75 ) ;
return V_65 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_12 ( V_87 , 0x3FFFC100 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_12 ( V_87 , 0 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
T_1 V_88 , T_1 V_89 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_90 V_91 ;
int V_65 ;
V_65 = F_31 ( V_2 , V_92 ,
V_89 , false , & V_91 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_93 [ V_88 ] . V_94 = ( V_82 ) V_91 . V_95 ;
V_38 -> V_93 [ V_88 ] . V_96 = F_32 ( V_89 ) ;
return 0 ;
}
static T_3 F_33 ( struct V_1 * V_2 ,
T_3 V_97 )
{
return 6200 - ( V_97 * 25 ) ;
}
static T_3 F_34 ( struct V_1 * V_2 ,
T_1 V_5 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_98 = F_1 ( V_2 ,
& V_38 -> V_99 . V_4 ,
V_5 ) ;
return F_33 ( V_2 , ( T_3 ) V_98 ) ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_88 , T_1 V_100 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_93 [ V_88 ] . V_101 = ( V_82 ) V_38 -> V_102 ;
V_38 -> V_93 [ V_88 ] . V_103 =
F_32 ( F_34 ( V_2 , V_100 ) ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_88 , T_1 V_104 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_93 [ V_88 ] . V_105 = F_37 ( ( T_3 ) V_104 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
T_1 V_88 , bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_93 [ V_88 ] . V_106 = V_18 ? 1 : 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_1 V_71 = F_9 ( V_107 ) ;
V_71 |= V_108 ;
F_12 ( V_107 , V_71 ) ;
F_40 ( V_2 , true ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_40 ( V_2 , false ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
T_1 V_109 = F_9 ( V_110 ) ;
V_109 &= ~ ( V_111 |
V_112 ) ;
V_109 |= V_113 ;
F_12 ( V_110 , V_109 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
T_1 V_109 = F_9 ( V_110 ) ;
V_109 |= ( V_111 |
V_112 ) ;
F_12 ( V_110 , V_109 ) ;
}
static int F_44 ( struct V_1 * V_2 , bool V_114 )
{
return F_20 ( V_2 , V_114 ?
V_115 : V_116 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
return F_46 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_117 == V_118 || V_2 -> V_117 == V_119 )
return F_20 ( V_2 , V_120 ) ;
else
return F_48 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_121 = 0 ;
int V_65 = 0 ;
if ( V_38 -> V_122 ) {
V_121 = F_32 ( V_38 -> V_121 ) ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_123 ) ,
( V_82 * ) & V_121 ,
sizeof( T_1 ) , V_38 -> V_75 ) ;
}
return V_65 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = V_38 -> V_124 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_21 -> V_14 [ V_12 ] . V_125 == V_38 -> V_126 . V_89 )
break;
}
V_38 -> V_86 = ( V_82 ) V_12 ;
F_38 ( V_2 , V_12 , true ) ;
} else {
struct V_19 * V_21 =
& V_38 -> V_99 . V_20 ;
if ( V_21 -> V_28 == 0 )
return - V_45 ;
for ( V_12 = V_38 -> V_124 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_21 -> V_14 [ V_12 ] . V_26 == V_38 -> V_126 . V_89 )
break;
}
V_38 -> V_86 = ( V_82 ) V_12 ;
F_38 ( V_2 , V_12 , true ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_38 -> V_127 = 1 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_128 ) ,
& V_38 -> V_127 ,
sizeof( V_82 ) , V_38 -> V_75 ) ;
return V_65 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_129 ) ,
( V_82 * ) & V_38 -> V_93 ,
sizeof( V_130 ) * V_131 ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_132 ) ,
& V_38 -> V_124 ,
sizeof( V_82 ) , V_38 -> V_75 ) ;
return V_65 ;
}
static T_1 F_53 ( T_1 V_133 , T_1 V_134 )
{
return ( V_133 >= V_134 ) ? V_133 - V_134 : V_134 - V_133 ;
}
static T_1 F_54 ( struct V_1 * V_2 , T_1 V_125 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_48 ;
if ( V_38 -> V_135 ) {
if ( F_53 ( V_125 , 40000 ) < 200 )
V_48 = 3 ;
else if ( F_53 ( V_125 , 30000 ) < 200 )
V_48 = 2 ;
else if ( F_53 ( V_125 , 20000 ) < 200 )
V_48 = 7 ;
else if ( F_53 ( V_125 , 15000 ) < 200 )
V_48 = 6 ;
else if ( F_53 ( V_125 , 10000 ) < 200 )
V_48 = 8 ;
else
V_48 = 0 ;
} else {
V_48 = 0 ;
}
return V_48 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_136 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_137 ;
struct V_90 V_91 ;
int V_65 ;
T_1 V_12 ;
if ( V_21 == NULL || V_21 -> V_13 == 0 )
return 0 ;
V_38 -> V_138 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_38 -> V_139 &&
( V_38 -> V_139 < V_21 -> V_14 [ V_12 ] . V_15 ) )
break;
V_38 -> V_140 [ V_12 ] . V_141 = F_32 ( V_21 -> V_14 [ V_12 ] . V_142 ) ;
V_38 -> V_140 [ V_12 ] . V_143 = F_32 ( V_21 -> V_14 [ V_12 ] . V_144 ) ;
V_38 -> V_140 [ V_12 ] . V_103 = F_37 ( V_21 -> V_14 [ V_12 ] . V_15 ) ;
V_38 -> V_140 [ V_12 ] . V_145 =
( V_82 ) F_54 ( V_2 , V_21 -> V_14 [ V_12 ] . V_142 ) ;
V_38 -> V_140 [ V_12 ] . V_146 =
( V_82 ) F_54 ( V_2 , V_21 -> V_14 [ V_12 ] . V_144 ) ;
V_65 = F_31 ( V_2 , V_92 ,
V_21 -> V_14 [ V_12 ] . V_142 , false , & V_91 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_140 [ V_12 ] . V_147 = ( V_82 ) V_91 . V_95 ;
V_65 = F_31 ( V_2 , V_92 ,
V_21 -> V_14 [ V_12 ] . V_144 , false , & V_91 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_140 [ V_12 ] . V_148 = ( V_82 ) V_91 . V_95 ;
V_38 -> V_138 ++ ;
}
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_149 ) ,
( V_82 * ) & V_38 -> V_138 ,
sizeof( V_82 ) , V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_150 = 1 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_151 ) ,
& V_38 -> V_150 ,
sizeof( V_82 ) , V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_152 ) ,
( V_82 * ) & V_38 -> V_140 ,
sizeof( V_153 ) * V_154 ,
V_38 -> V_75 ) ;
return V_65 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
T_1 V_12 ;
struct V_155 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_156 ;
struct V_90 V_91 ;
if ( V_21 == NULL || V_21 -> V_13 == 0 )
return 0 ;
V_38 -> V_157 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_38 -> V_139 &&
V_38 -> V_139 < V_21 -> V_14 [ V_12 ] . V_15 )
break;
V_38 -> V_158 [ V_12 ] . V_159 = F_32 ( V_21 -> V_14 [ V_12 ] . V_160 ) ;
V_38 -> V_158 [ V_12 ] . V_161 = F_37 ( V_21 -> V_14 [ V_12 ] . V_15 ) ;
V_38 -> V_158 [ V_12 ] . V_162 =
( V_82 ) F_54 ( V_2 , V_21 -> V_14 [ V_12 ] . V_160 ) ;
V_65 = F_31 ( V_2 , V_92 ,
V_21 -> V_14 [ V_12 ] . V_160 , false , & V_91 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_158 [ V_12 ] . V_163 = ( V_82 ) V_91 . V_95 ;
V_38 -> V_157 ++ ;
}
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_164 ) ,
( V_82 * ) & V_38 -> V_157 ,
sizeof( V_82 ) ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_165 = 1 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_166 ) ,
( V_82 * ) & V_38 -> V_165 ,
sizeof( V_82 ) ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_167 ) ,
( V_82 * ) & V_38 -> V_158 ,
sizeof( V_168 ) * V_169 ,
V_38 -> V_75 ) ;
return V_65 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_170 ;
struct V_90 V_91 ;
int V_65 ;
T_1 V_12 ;
if ( V_21 == NULL || V_21 -> V_13 == 0 )
return 0 ;
V_38 -> V_171 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_38 -> V_139 &&
V_38 -> V_139 < V_21 -> V_14 [ V_12 ] . V_15 )
break;
V_38 -> V_172 [ V_12 ] . V_159 = F_32 ( V_21 -> V_14 [ V_12 ] . V_125 ) ;
V_38 -> V_172 [ V_12 ] . V_161 = F_37 ( V_21 -> V_14 [ V_12 ] . V_15 ) ;
V_38 -> V_172 [ V_12 ] . V_162 =
( V_82 ) F_54 ( V_2 , V_21 -> V_14 [ V_12 ] . V_125 ) ;
V_65 = F_31 ( V_2 , V_92 ,
V_21 -> V_14 [ V_12 ] . V_125 , false , & V_91 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_172 [ V_12 ] . V_163 = ( V_82 ) V_91 . V_95 ;
V_38 -> V_171 ++ ;
}
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_173 ) ,
( V_82 * ) & V_38 -> V_171 ,
sizeof( V_82 ) ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_174 = 1 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_175 ) ,
( V_82 * ) & V_38 -> V_174 ,
sizeof( V_82 ) ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_176 ) ,
( V_82 * ) & V_38 -> V_172 ,
sizeof( V_168 ) * V_177 ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
return V_65 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_178 ;
struct V_90 V_91 ;
int V_65 ;
T_1 V_12 ;
if ( V_21 == NULL || V_21 -> V_13 == 0 )
return 0 ;
V_38 -> V_179 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
V_38 -> V_180 [ V_12 ] . V_159 = F_32 ( V_21 -> V_14 [ V_12 ] . V_125 ) ;
V_38 -> V_180 [ V_12 ] . V_161 = F_37 ( V_21 -> V_14 [ V_12 ] . V_15 ) ;
V_65 = F_31 ( V_2 , V_92 ,
V_21 -> V_14 [ V_12 ] . V_125 , false , & V_91 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_180 [ V_12 ] . V_163 = ( V_82 ) V_91 . V_95 ;
V_38 -> V_179 ++ ;
}
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_181 ) ,
( V_82 * ) & V_38 -> V_179 ,
sizeof( V_82 ) ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_182 = 1 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_183 ) ,
( V_82 * ) & V_38 -> V_182 ,
sizeof( V_82 ) ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_184 ) ,
( V_82 * ) & V_38 -> V_180 ,
sizeof( V_168 ) * V_185 ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
return V_65 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_38 -> V_124 ; V_12 ++ ) {
if ( V_38 -> V_135 ) {
if ( F_53 ( V_21 -> V_14 [ V_12 ] . V_125 , 40000 ) < 200 )
V_38 -> V_93 [ V_12 ] . V_162 = 3 ;
else if ( F_53 ( V_21 -> V_14 [ V_12 ] . V_125 , 30000 ) < 200 )
V_38 -> V_93 [ V_12 ] . V_162 = 2 ;
else if ( F_53 ( V_21 -> V_14 [ V_12 ] . V_125 , 26600 ) < 200 )
V_38 -> V_93 [ V_12 ] . V_162 = 7 ;
else if ( F_53 ( V_21 -> V_14 [ V_12 ] . V_125 , 20000 ) < 200 )
V_38 -> V_93 [ V_12 ] . V_162 = 6 ;
else if ( F_53 ( V_21 -> V_14 [ V_12 ] . V_125 , 10000 ) < 200 )
V_38 -> V_93 [ V_12 ] . V_162 = 8 ;
else
V_38 -> V_93 [ V_12 ] . V_162 = 0 ;
} else {
V_38 -> V_93 [ V_12 ] . V_162 = 0 ;
}
}
} else {
struct V_19 * V_21 =
& V_38 -> V_99 . V_20 ;
for ( V_12 = 0 ; V_12 < V_38 -> V_124 ; V_12 ++ ) {
if ( V_38 -> V_135 ) {
if ( F_53 ( V_21 -> V_14 [ V_12 ] . V_26 , 40000 ) < 200 )
V_38 -> V_93 [ V_12 ] . V_162 = 3 ;
else if ( F_53 ( V_21 -> V_14 [ V_12 ] . V_26 , 30000 ) < 200 )
V_38 -> V_93 [ V_12 ] . V_162 = 2 ;
else if ( F_53 ( V_21 -> V_14 [ V_12 ] . V_26 , 26600 ) < 200 )
V_38 -> V_93 [ V_12 ] . V_162 = 7 ;
else if ( F_53 ( V_21 -> V_14 [ V_12 ] . V_26 , 20000 ) < 200 )
V_38 -> V_93 [ V_12 ] . V_162 = 6 ;
else if ( F_53 ( V_21 -> V_14 [ V_12 ] . V_26 , 10000 ) < 200 )
V_38 -> V_93 [ V_12 ] . V_162 = 8 ;
else
V_38 -> V_93 [ V_12 ] . V_162 = 0 ;
} else {
V_38 -> V_93 [ V_12 ] . V_162 = 0 ;
}
}
}
}
static int F_60 ( struct V_1 * V_2 , bool V_18 )
{
return F_20 ( V_2 , V_18 ?
V_186 : V_187 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_188 = 0xff ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_32 * V_189 = F_6 ( V_34 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_190 = * V_34 ;
V_38 -> V_191 = * V_189 ;
V_38 -> V_190 . V_36 = & V_38 -> V_191 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_32 * V_189 = F_6 ( V_34 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_192 = * V_34 ;
V_38 -> V_193 = * V_189 ;
V_38 -> V_192 . V_36 = & V_38 -> V_193 ;
}
static void F_64 ( struct V_1 * V_2 , bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
if ( V_38 -> V_194 ) {
V_65 = F_65 ( V_2 , V_18 ) ;
if ( V_65 )
F_66 ( L_1 ) ;
}
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_65 = F_21 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_2 ) ;
return V_65 ;
}
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
V_65 = F_50 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_3 ) ;
return V_65 ;
}
F_59 ( V_2 ) ;
V_65 = F_52 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_4 ) ;
return V_65 ;
}
V_65 = F_55 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_5 ) ;
return V_65 ;
}
V_65 = F_56 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_6 ) ;
return V_65 ;
}
V_65 = F_57 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_7 ) ;
return V_65 ;
}
V_65 = F_58 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_8 ) ;
return V_65 ;
}
F_28 ( V_2 ) ;
#if 0
kv_initialize_hardware_cac_manager(adev);
#endif
F_42 ( V_2 ) ;
if ( V_38 -> V_195 ) {
V_65 = F_51 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_9 ) ;
return V_65 ;
}
}
V_65 = F_24 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_10 ) ;
return V_65 ;
}
V_65 = F_26 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_11 ) ;
return V_65 ;
}
V_65 = F_27 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_12 ) ;
return V_65 ;
}
V_65 = F_60 ( V_2 , true ) ;
if ( V_65 ) {
F_66 ( L_13 ) ;
return V_65 ;
}
F_39 ( V_2 ) ;
V_65 = F_16 ( V_2 , true ) ;
if ( V_65 ) {
F_66 ( L_14 ) ;
return V_65 ;
}
V_65 = F_19 ( V_2 , true ) ;
if ( V_65 ) {
F_66 ( L_15 ) ;
return V_65 ;
}
F_61 ( V_2 ) ;
V_65 = F_65 ( V_2 , false ) ;
if ( V_65 ) {
F_66 ( L_1 ) ;
return V_65 ;
}
F_62 ( V_2 , V_2 -> V_8 . V_9 . V_196 ) ;
if ( V_2 -> V_197 . V_198 &&
F_70 ( V_2 -> V_8 . V_199 ) ) {
V_65 = F_71 ( V_2 , V_200 , V_201 ) ;
if ( V_65 ) {
F_66 ( L_16 ) ;
return V_65 ;
}
F_72 ( V_2 , & V_2 -> V_8 . V_9 . V_202 . V_197 ,
V_203 ) ;
F_72 ( V_2 , & V_2 -> V_8 . V_9 . V_202 . V_197 ,
V_204 ) ;
}
return V_65 ;
}
static void F_73 ( struct V_1 * V_2 )
{
F_74 ( V_2 , & V_2 -> V_8 . V_9 . V_202 . V_197 ,
V_203 ) ;
F_74 ( V_2 , & V_2 -> V_8 . V_9 . V_202 . V_197 ,
V_204 ) ;
F_65 ( V_2 , false ) ;
if ( V_2 -> V_117 == V_119 )
F_75 ( V_2 , false ) ;
F_76 ( V_2 , false ) ;
F_77 ( V_2 , false ) ;
F_78 ( V_2 , false ) ;
F_79 ( V_2 , false ) ;
F_19 ( V_2 , false ) ;
F_16 ( V_2 , false ) ;
F_29 ( V_2 ) ;
F_41 ( V_2 ) ;
F_60 ( V_2 , false ) ;
F_43 ( V_2 ) ;
F_62 ( V_2 , V_2 -> V_8 . V_9 . V_196 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_121 = 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 = 0 ;
if ( V_38 -> V_205 ) {
T_3 V_71 ;
V_71 = 45 ;
V_38 -> V_206 = F_37 ( V_71 ) ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_207 ) ,
( V_82 * ) & V_38 -> V_206 ,
sizeof( T_3 ) , V_38 -> V_75 ) ;
V_71 = 30 ;
V_38 -> V_208 = F_37 ( V_71 ) ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_209 ) ,
( V_82 * ) & V_38 -> V_208 ,
sizeof( T_3 ) , V_38 -> V_75 ) ;
}
return V_65 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_210 = false ;
V_38 -> V_211 = false ;
V_38 -> V_212 = false ;
V_38 -> V_213 = false ;
}
static int F_82 ( struct V_1 * V_2 , bool V_18 )
{
return F_20 ( V_2 , V_18 ?
V_214 : V_215 ) ;
}
static int F_83 ( struct V_1 * V_2 , bool V_18 )
{
return F_20 ( V_2 , V_18 ?
V_216 : V_217 ) ;
}
static int F_84 ( struct V_1 * V_2 , bool V_18 )
{
return F_20 ( V_2 , V_18 ?
V_218 : V_219 ) ;
}
static int F_85 ( struct V_1 * V_2 , bool V_18 )
{
return F_20 ( V_2 , V_18 ?
V_220 : V_221 ) ;
}
static int F_86 ( struct V_1 * V_2 , bool V_222 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_136 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_137 ;
int V_65 ;
T_1 V_50 ;
if ( ! V_222 ) {
if ( V_21 -> V_13 )
V_38 -> V_223 = V_21 -> V_13 - 1 ;
else
V_38 -> V_223 = 0 ;
if ( ! V_38 -> V_224 || V_38 -> V_225 ) {
V_50 = 1 << V_38 -> V_223 ;
} else {
V_50 = 0x1f ;
}
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_226 ) ,
( V_227 * ) & V_38 -> V_223 ,
sizeof( V_82 ) , V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
F_87 ( V_2 ,
V_228 ,
V_50 ) ;
}
return F_82 ( V_2 , ! V_222 ) ;
}
static V_82 F_88 ( struct V_1 * V_2 , T_1 V_160 )
{
V_82 V_12 ;
struct V_155 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_156 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_21 -> V_14 [ V_12 ] . V_160 >= V_160 )
break;
}
return V_12 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_33 * V_229 ,
struct V_33 * V_230 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_155 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_156 ;
int V_65 ;
if ( V_229 -> V_160 > 0 && V_230 -> V_160 == 0 ) {
F_78 ( V_2 , false ) ;
V_65 = F_90 ( V_2 , V_231 ,
V_232 ) ;
if ( V_65 )
return V_65 ;
if ( V_38 -> V_225 )
V_38 -> V_233 = V_21 -> V_13 - 1 ;
else
V_38 -> V_233 = F_88 ( V_2 , V_229 -> V_160 ) ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_234 ) ,
( V_82 * ) & V_38 -> V_233 ,
sizeof( V_82 ) ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
if ( V_38 -> V_225 )
F_87 ( V_2 ,
V_235 ,
( 1 << V_38 -> V_233 ) ) ;
F_83 ( V_2 , true ) ;
} else if ( V_229 -> V_160 == 0 && V_230 -> V_160 > 0 ) {
F_83 ( V_2 , false ) ;
V_65 = F_90 ( V_2 , V_231 ,
V_236 ) ;
if ( V_65 )
return V_65 ;
F_78 ( V_2 , true ) ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , bool V_222 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_170 ;
int V_65 ;
if ( ! V_222 ) {
if ( V_38 -> V_225 )
V_38 -> V_237 = V_21 -> V_13 - 1 ;
else
V_38 -> V_237 = 0 ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_238 ) ,
( V_82 * ) & V_38 -> V_237 ,
sizeof( V_82 ) ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
if ( V_38 -> V_225 )
F_87 ( V_2 ,
V_239 ,
( 1 << V_38 -> V_237 ) ) ;
}
return F_84 ( V_2 , ! V_222 ) ;
}
static V_82 F_92 ( struct V_1 * V_2 )
{
V_82 V_12 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_178 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_21 -> V_14 [ V_12 ] . V_125 >= 0 )
break;
}
if ( V_12 >= V_21 -> V_13 )
V_12 = V_21 -> V_13 - 1 ;
return V_12 ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_82 V_188 ;
if ( ! V_38 -> V_225 ) {
V_188 = F_92 ( V_2 ) ;
if ( V_188 != V_38 -> V_188 ) {
V_38 -> V_188 = V_188 ;
F_87 ( V_2 ,
V_240 ,
( 1 << V_38 -> V_188 ) ) ;
}
}
}
static int F_94 ( struct V_1 * V_2 , bool V_222 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_178 ;
int V_65 ;
if ( ! V_222 ) {
if ( V_38 -> V_225 )
V_38 -> V_188 = V_21 -> V_13 - 1 ;
else
V_38 -> V_188 = F_92 ( V_2 ) ;
V_65 = F_25 ( V_2 ,
V_38 -> V_76 +
F_23 ( V_80 , V_241 ) ,
( V_82 * ) & V_38 -> V_188 ,
sizeof( V_82 ) ,
V_38 -> V_75 ) ;
if ( V_65 )
return V_65 ;
if ( V_38 -> V_225 )
F_87 ( V_2 ,
V_240 ,
( 1 << V_38 -> V_188 ) ) ;
}
return F_85 ( V_2 , ! V_222 ) ;
}
static void F_79 ( struct V_1 * V_2 , bool V_222 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
if ( V_38 -> V_210 == V_222 )
return;
V_38 -> V_210 = V_222 ;
if ( V_222 ) {
if ( V_38 -> V_242 ) {
V_65 = F_90 ( V_2 , V_243 ,
V_232 ) ;
V_65 = F_95 ( V_2 , V_243 ,
V_244 ) ;
}
F_86 ( V_2 , V_222 ) ;
if ( V_38 -> V_242 )
F_20 ( V_2 , V_245 ) ;
} else {
if ( V_38 -> V_242 ) {
F_20 ( V_2 , V_246 ) ;
V_65 = F_95 ( V_2 , V_243 ,
V_247 ) ;
V_65 = F_90 ( V_2 , V_243 ,
V_236 ) ;
}
F_86 ( V_2 , V_222 ) ;
}
}
static void F_78 ( struct V_1 * V_2 , bool V_222 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
if ( V_38 -> V_211 == V_222 )
return;
V_38 -> V_211 = V_222 ;
if ( V_222 ) {
if ( V_38 -> V_248 ) {
V_65 = F_95 ( V_2 , V_231 ,
V_244 ) ;
F_20 ( V_2 , V_249 ) ;
}
} else {
if ( V_38 -> V_248 ) {
F_20 ( V_2 , V_250 ) ;
V_65 = F_95 ( V_2 , V_231 ,
V_247 ) ;
}
}
}
static void F_77 ( struct V_1 * V_2 , bool V_222 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
if ( V_38 -> V_212 == V_222 )
return;
V_38 -> V_212 = V_222 ;
if ( V_222 ) {
F_91 ( V_2 , true ) ;
if ( V_38 -> V_251 )
F_20 ( V_2 , V_252 ) ;
} else {
if ( V_38 -> V_251 )
F_20 ( V_2 , V_253 ) ;
F_91 ( V_2 , false ) ;
}
}
static void F_76 ( struct V_1 * V_2 , bool V_222 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
if ( V_38 -> V_213 == V_222 )
return;
if ( V_2 -> V_117 == V_118 || V_2 -> V_117 == V_119 )
return;
V_38 -> V_213 = V_222 ;
if ( V_222 ) {
F_94 ( V_2 , true ) ;
if ( V_38 -> V_254 )
F_20 ( V_2 , V_255 ) ;
} else {
if ( V_38 -> V_254 )
F_20 ( V_2 , V_256 ) ;
F_94 ( V_2 , false ) ;
}
}
static void F_96 ( struct V_1 * V_2 ,
struct V_33 * V_257 )
{
struct V_32 * V_189 = F_6 ( V_257 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_38 -> V_124 ; V_12 ++ ) {
if ( ( V_21 -> V_14 [ V_12 ] . V_125 >= V_189 -> V_258 [ 0 ] . V_89 ) ||
( V_12 == ( V_38 -> V_124 - 1 ) ) ) {
V_38 -> V_259 = V_12 ;
break;
}
}
for ( V_12 = V_38 -> V_124 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_21 -> V_14 [ V_12 ] . V_125 <= V_189 -> V_258 [ V_189 -> V_260 - 1 ] . V_89 )
break;
}
V_38 -> V_261 = V_12 ;
if ( V_38 -> V_259 > V_38 -> V_261 ) {
if ( ( V_189 -> V_258 [ 0 ] . V_89 - V_21 -> V_14 [ V_38 -> V_261 ] . V_125 ) >
( V_21 -> V_14 [ V_38 -> V_259 ] . V_125 - V_189 -> V_258 [ V_189 -> V_260 - 1 ] . V_89 ) )
V_38 -> V_261 = V_38 -> V_259 ;
else
V_38 -> V_259 = V_38 -> V_261 ;
}
} else {
struct V_19 * V_21 =
& V_38 -> V_99 . V_20 ;
for ( V_12 = 0 ; V_12 < ( int ) V_38 -> V_124 ; V_12 ++ ) {
if ( V_21 -> V_14 [ V_12 ] . V_26 >= V_189 -> V_258 [ 0 ] . V_89 ||
V_12 == ( int ) ( V_38 -> V_124 - 1 ) ) {
V_38 -> V_259 = V_12 ;
break;
}
}
for ( V_12 = V_38 -> V_124 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_21 -> V_14 [ V_12 ] . V_26 <=
V_189 -> V_258 [ V_189 -> V_260 - 1 ] . V_89 )
break;
}
V_38 -> V_261 = V_12 ;
if ( V_38 -> V_259 > V_38 -> V_261 ) {
if ( ( V_189 -> V_258 [ 0 ] . V_89 -
V_21 -> V_14 [ V_38 -> V_261 ] . V_26 ) >
( V_21 -> V_14 [ V_38 -> V_259 ] . V_26 -
V_189 -> V_258 [ V_189 -> V_260 - 1 ] . V_89 ) )
V_38 -> V_261 = V_38 -> V_259 ;
else
V_38 -> V_259 = V_38 -> V_261 ;
}
}
}
static int F_97 ( struct V_1 * V_2 ,
struct V_33 * V_257 )
{
struct V_32 * V_189 = F_6 ( V_257 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 = 0 ;
V_82 V_262 ;
if ( V_38 -> V_135 ) {
V_262 = V_189 -> V_263 ?
V_38 -> V_93 [ V_38 -> V_86 ] . V_162 : 0 ;
V_65 = F_25 ( V_2 ,
( V_38 -> V_76 +
F_23 ( V_80 , V_129 ) +
( V_38 -> V_86 * sizeof( V_130 ) ) +
F_23 ( V_130 , V_162 ) ) ,
& V_262 ,
sizeof( V_82 ) , V_38 -> V_75 ) ;
}
return V_65 ;
}
static int F_75 ( struct V_1 * V_2 ,
bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 = 0 ;
if ( V_18 ) {
if ( V_38 -> V_264 && ! V_38 -> V_265 ) {
V_65 = F_20 ( V_2 , V_266 ) ;
if ( V_65 == 0 )
V_38 -> V_265 = true ;
}
} else {
if ( V_38 -> V_264 && V_38 -> V_265 ) {
V_65 = F_20 ( V_2 , V_267 ) ;
if ( V_65 == 0 )
V_38 -> V_265 = false ;
}
}
return V_65 ;
}
static int F_98 ( struct V_1 * V_2 ,
enum V_268 V_269 )
{
int V_65 ;
if ( V_269 == V_270 ) {
V_65 = F_99 ( V_2 ) ;
if ( V_65 )
return V_65 ;
} else if ( V_269 == V_271 ) {
V_65 = F_46 ( V_2 ) ;
if ( V_65 )
return V_65 ;
} else if ( V_269 == V_272 ) {
V_65 = F_47 ( V_2 ) ;
if ( V_65 )
return V_65 ;
}
V_2 -> V_8 . V_9 . V_273 = V_269 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_33 V_193 = * V_2 -> V_8 . V_9 . V_193 ;
struct V_33 * V_189 = & V_193 ;
F_63 ( V_2 , V_189 ) ;
F_101 ( V_2 ,
& V_38 -> V_192 ,
& V_38 -> V_190 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_33 * V_189 = & V_38 -> V_192 ;
struct V_33 * V_274 = & V_38 -> V_190 ;
int V_65 ;
if ( V_38 -> V_194 ) {
V_65 = F_65 ( V_2 , V_2 -> V_8 . V_9 . V_275 ) ;
if ( V_65 ) {
F_66 ( L_1 ) ;
return V_65 ;
}
}
if ( V_2 -> V_117 == V_118 || V_2 -> V_117 == V_119 ) {
if ( V_38 -> V_276 ) {
F_96 ( V_2 , V_189 ) ;
F_97 ( V_2 , V_189 ) ;
V_65 = F_103 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_17 ) ;
return V_65 ;
}
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
F_45 ( V_2 ) ;
F_106 ( V_2 ) ;
F_52 ( V_2 ) ;
F_107 ( V_2 , V_189 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_45 ( V_2 ) ;
F_47 ( V_2 ) ;
V_65 = F_89 ( V_2 , V_189 , V_274 ) ;
if ( V_65 ) {
F_66 ( L_18 ) ;
return V_65 ;
}
F_49 ( V_2 ) ;
if ( V_2 -> V_117 == V_119 )
F_75 ( V_2 , true ) ;
}
} else {
if ( V_38 -> V_276 ) {
F_96 ( V_2 , V_189 ) ;
F_97 ( V_2 , V_189 ) ;
V_65 = F_103 ( V_2 ) ;
if ( V_65 ) {
F_66 ( L_17 ) ;
return V_65 ;
}
F_104 ( V_2 ) ;
F_105 ( V_2 ) ;
F_44 ( V_2 , true ) ;
F_52 ( V_2 ) ;
F_107 ( V_2 , V_189 ) ;
F_44 ( V_2 , false ) ;
F_48 ( V_2 ) ;
V_65 = F_89 ( V_2 , V_189 , V_274 ) ;
if ( V_65 ) {
F_66 ( L_18 ) ;
return V_65 ;
}
F_93 ( V_2 ) ;
F_49 ( V_2 ) ;
F_75 ( V_2 , true ) ;
}
}
return 0 ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_33 * V_189 = & V_38 -> V_192 ;
F_62 ( V_2 , V_189 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
F_3 ( V_2 , true ) ;
F_81 ( V_2 ) ;
F_80 ( V_2 ) ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_277 * V_21 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
if ( V_38 -> V_99 . V_20 . V_28 > 0 ) {
int V_278 = V_38 -> V_99 . V_20 . V_28 - 1 ;
V_21 -> V_89 =
V_38 -> V_99 . V_20 . V_14 [ V_278 ] . V_26 ;
V_21 -> V_279 =
F_34 ( V_2 ,
V_38 -> V_99 . V_20 . V_14 [ V_278 ] . V_5 ) ;
}
V_21 -> V_280 = V_38 -> V_99 . V_281 [ 0 ] ;
}
static void F_111 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_136 * V_282 =
& V_2 -> V_8 . V_9 . V_10 . V_137 ;
struct V_155 * V_283 =
& V_2 -> V_8 . V_9 . V_10 . V_156 ;
struct V_6 * V_284 =
& V_2 -> V_8 . V_9 . V_10 . V_170 ;
struct V_6 * V_285 =
& V_2 -> V_8 . V_9 . V_10 . V_178 ;
if ( V_282 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_282 -> V_13 ; V_12 ++ )
V_282 -> V_14 [ V_12 ] . V_15 =
F_33 ( V_2 ,
V_282 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_283 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_283 -> V_13 ; V_12 ++ )
V_283 -> V_14 [ V_12 ] . V_15 =
F_33 ( V_2 ,
V_283 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_284 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_284 -> V_13 ; V_12 ++ )
V_284 -> V_14 [ V_12 ] . V_15 =
F_33 ( V_2 ,
V_284 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_285 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_285 -> V_13 ; V_12 ++ )
V_285 -> V_14 [ V_12 ] . V_15 =
F_33 ( V_2 ,
V_285 -> V_14 [ V_12 ] . V_15 ) ;
}
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_126 . V_89 = V_38 -> V_99 . V_286 ;
V_38 -> V_126 . V_287 = V_38 -> V_99 . V_288 ;
V_38 -> V_126 . V_289 = 0 ;
V_38 -> V_126 . V_290 = 0 ;
V_38 -> V_126 . V_291 = 1 ;
V_38 -> V_126 . V_292 = 0 ;
V_38 -> V_126 . V_293 = 0 ;
V_38 -> V_126 . V_294 = 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_65 ;
T_1 V_295 , V_12 ;
V_65 = F_113 ( V_2 , & V_295 ) ;
if ( V_65 )
return V_65 ;
for ( V_12 = V_131 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_295 & ( 1 << V_12 ) )
break;
}
if ( V_2 -> V_117 == V_118 || V_2 -> V_117 == V_119 )
return F_87 ( V_2 , V_296 , V_12 ) ;
else
return F_114 ( V_2 , V_12 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_65 ;
T_1 V_295 , V_12 ;
V_65 = F_113 ( V_2 , & V_295 ) ;
if ( V_65 )
return V_65 ;
for ( V_12 = 0 ; V_12 < V_131 ; V_12 ++ ) {
if ( V_295 & ( 1 << V_12 ) )
break;
}
if ( V_2 -> V_117 == V_118 || V_2 -> V_117 == V_119 )
return F_87 ( V_2 , V_296 , V_12 ) ;
else
return F_114 ( V_2 , V_12 ) ;
}
static V_82 F_115 ( struct V_1 * V_2 ,
T_1 V_89 , T_1 V_297 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
T_1 V_298 ;
T_1 V_299 = F_116 ( V_297 , ( T_1 ) V_300 ) ;
if ( V_89 < V_299 )
return 0 ;
if ( ! V_38 -> V_301 )
return 0 ;
for ( V_12 = V_302 ; V_12 > 0 ; V_12 -- ) {
V_298 = V_89 >> V_12 ;
if ( V_298 >= V_299 )
break;
}
return ( V_82 ) V_12 ;
}
static int F_117 ( struct V_1 * V_2 , int * V_303 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
int V_12 ;
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = V_21 -> V_13 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_38 -> V_139 &&
( F_33 ( V_2 , V_21 -> V_14 [ V_12 ] . V_15 ) <=
V_38 -> V_139 ) ) {
* V_303 = V_12 ;
return 0 ;
}
}
} else {
struct V_19 * V_21 =
& V_38 -> V_99 . V_20 ;
for ( V_12 = V_21 -> V_28 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_38 -> V_139 &&
( F_34 ( V_2 , V_21 -> V_14 [ V_12 ] . V_5 ) <=
V_38 -> V_139 ) ) {
* V_303 = V_12 ;
return 0 ;
}
}
}
* V_303 = 0 ;
return 0 ;
}
static void F_101 ( struct V_1 * V_2 ,
struct V_33 * V_257 ,
struct V_33 * V_304 )
{
struct V_32 * V_35 = F_6 ( V_257 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_305 = 10000 ;
T_1 V_89 , V_280 = 0 ;
int V_12 , V_303 ;
bool V_306 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
T_1 V_307 = 0 ;
struct V_277 * V_308 =
& V_2 -> V_8 . V_9 . V_10 . V_309 ;
if ( V_257 -> V_310 ) {
V_257 -> V_160 = V_2 -> V_8 . V_9 . V_311 [ V_2 -> V_8 . V_9 . V_158 ] . V_160 ;
V_257 -> V_312 = V_2 -> V_8 . V_9 . V_311 [ V_2 -> V_8 . V_9 . V_158 ] . V_312 ;
} else {
V_257 -> V_160 = 0 ;
V_257 -> V_312 = 0 ;
}
V_280 = V_308 -> V_280 ;
V_89 = V_305 ;
if ( V_38 -> V_225 ) {
V_307 = ( V_308 -> V_89 * 75 ) / 100 ;
for ( V_12 = V_21 -> V_13 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_307 >= V_21 -> V_14 [ V_12 ] . V_125 ) {
V_307 = V_21 -> V_14 [ V_12 ] . V_125 ;
break;
}
}
if ( V_12 > 0 )
V_307 = V_21 -> V_14 [ 0 ] . V_125 ;
V_89 = V_307 ;
}
if ( V_257 -> V_310 ) {
if ( V_89 < V_2 -> V_8 . V_9 . V_311 [ V_2 -> V_8 . V_9 . V_158 ] . V_89 )
V_89 = V_2 -> V_8 . V_9 . V_311 [ V_2 -> V_8 . V_9 . V_158 ] . V_89 ;
}
V_35 -> V_263 = true ;
for ( V_12 = 0 ; V_12 < V_35 -> V_260 ; V_12 ++ ) {
if ( V_35 -> V_258 [ V_12 ] . V_89 < V_89 )
V_35 -> V_258 [ V_12 ] . V_89 = V_89 ;
}
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_35 -> V_260 ; V_12 ++ ) {
if ( V_38 -> V_139 &&
( V_38 -> V_139 <
F_33 ( V_2 , V_35 -> V_258 [ V_12 ] . V_287 ) ) ) {
F_117 ( V_2 , & V_303 ) ;
V_35 -> V_258 [ V_12 ] . V_89 = V_21 -> V_14 [ V_303 ] . V_125 ;
}
}
} else {
struct V_19 * V_21 =
& V_38 -> V_99 . V_20 ;
for ( V_12 = 0 ; V_12 < V_35 -> V_260 ; V_12 ++ ) {
if ( V_38 -> V_139 &&
( V_38 -> V_139 <
F_33 ( V_2 , V_35 -> V_258 [ V_12 ] . V_287 ) ) ) {
F_117 ( V_2 , & V_303 ) ;
V_35 -> V_258 [ V_12 ] . V_89 = V_21 -> V_14 [ V_303 ] . V_26 ;
}
}
}
if ( V_38 -> V_225 ) {
for ( V_12 = 0 ; V_12 < V_35 -> V_260 ; V_12 ++ ) {
V_35 -> V_258 [ V_12 ] . V_89 = V_307 ;
}
}
V_38 -> V_313 = V_257 -> V_144 || V_257 -> V_142 ||
V_257 -> V_160 || V_257 -> V_312 ;
if ( ( V_257 -> V_314 & V_315 ) ==
V_316 )
V_38 -> V_317 = true ;
else
V_38 -> V_317 = false ;
if ( V_2 -> V_117 == V_118 || V_2 -> V_117 == V_119 ) {
V_35 -> V_318 = 0x1 ;
V_35 -> V_319 = 0x0 ;
V_35 -> V_320 = 0x1 ;
V_35 -> V_321 = 0x0 ;
} else {
V_35 -> V_318 = 0x3 ;
V_35 -> V_319 = 0x0 ;
V_35 -> V_320 = 0x3 ;
V_35 -> V_321 = 0x0 ;
if ( V_38 -> V_99 . V_322 ) {
V_306 = ( V_280 >= V_38 -> V_99 . V_281 [ 3 ] ) ||
V_38 -> V_313 || ( V_2 -> V_8 . V_9 . V_323 >= 3 ) ||
V_38 -> V_324 ;
V_35 -> V_318 = V_306 ? 0x2 : 0x3 ;
V_35 -> V_319 = 0x2 ;
V_35 -> V_320 = V_306 ? 0x2 : 0x3 ;
V_35 -> V_321 = 0x2 ;
}
}
}
static void F_118 ( struct V_1 * V_2 ,
T_1 V_88 , bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_93 [ V_88 ] . V_325 = V_18 ? 1 : 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_326 = 10000 ;
T_1 V_12 ;
if ( V_38 -> V_259 > V_38 -> V_261 )
return - V_45 ;
for ( V_12 = V_38 -> V_259 ; V_12 <= V_38 -> V_261 ; V_12 ++ ) {
V_38 -> V_93 [ V_12 ] . V_327 =
F_115 ( V_2 ,
F_119 ( V_38 -> V_93 [ V_12 ] . V_96 ) ,
V_326 ) ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
bool V_306 ;
struct V_277 * V_308 =
& V_2 -> V_8 . V_9 . V_10 . V_309 ;
T_1 V_280 = V_308 -> V_280 ;
if ( V_38 -> V_259 > V_38 -> V_261 )
return - V_45 ;
if ( V_2 -> V_117 == V_118 || V_2 -> V_117 == V_119 ) {
for ( V_12 = V_38 -> V_259 ; V_12 <= V_38 -> V_261 ; V_12 ++ ) {
V_38 -> V_93 [ V_12 ] . V_328 = 1 ;
V_38 -> V_93 [ V_12 ] . V_329 = 0 ;
V_38 -> V_93 [ V_12 ] . V_330 = 0 ;
}
if ( ! V_38 -> V_99 . V_322 )
return 0 ;
V_306 = ( ( V_280 >= V_38 -> V_99 . V_281 [ 3 ] ) ||
( V_2 -> V_8 . V_9 . V_323 >= 3 ) || V_38 -> V_313 ) ;
if ( V_306 ) {
for ( V_12 = V_38 -> V_259 ; V_12 <= V_38 -> V_261 ; V_12 ++ )
V_38 -> V_93 [ V_12 ] . V_328 = 0 ;
} else {
if ( V_38 -> V_317 )
V_38 -> V_93 [ 0 ] . V_329 = 1 ;
V_38 -> V_93 [ 1 ] . V_328 = 0 ;
V_38 -> V_93 [ 2 ] . V_328 = 0 ;
V_38 -> V_93 [ 3 ] . V_328 = 0 ;
V_38 -> V_93 [ 4 ] . V_328 = 0 ;
}
} else {
for ( V_12 = V_38 -> V_259 ; V_12 <= V_38 -> V_261 ; V_12 ++ ) {
V_38 -> V_93 [ V_12 ] . V_328 = 1 ;
V_38 -> V_93 [ V_12 ] . V_329 = 0 ;
V_38 -> V_93 [ V_12 ] . V_330 = 0 ;
}
if ( V_38 -> V_99 . V_322 && V_38 -> V_317 ) {
V_38 -> V_93 [ V_38 -> V_259 ] . V_330 = 0x28 ;
V_38 -> V_93 [ V_38 -> V_259 ] . V_328 = 0 ;
if ( V_38 -> V_259 != V_38 -> V_261 )
V_38 -> V_93 [ V_38 -> V_259 ] . V_329 = 1 ;
}
}
return 0 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
if ( V_38 -> V_259 > V_38 -> V_261 )
return - V_45 ;
for ( V_12 = V_38 -> V_259 ; V_12 <= V_38 -> V_261 ; V_12 ++ )
V_38 -> V_93 [ V_12 ] . V_331 = ( V_12 == V_38 -> V_261 ) ? 1 : 0 ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_21 && V_21 -> V_13 ) {
T_1 V_5 ;
V_38 -> V_124 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_38 -> V_139 &&
( V_38 -> V_139 <
F_33 ( V_2 , V_21 -> V_14 [ V_12 ] . V_15 ) ) )
break;
F_30 ( V_2 , V_12 , V_21 -> V_14 [ V_12 ] . V_125 ) ;
V_5 = F_2 ( V_2 ,
& V_38 -> V_99 . V_4 ,
V_21 -> V_14 [ V_12 ] . V_15 ) ;
F_35 ( V_2 , V_12 , V_5 ) ;
F_36 ( V_2 , V_12 , V_38 -> V_104 [ V_12 ] ) ;
F_118 ( V_2 , V_12 , true ) ;
V_38 -> V_124 ++ ;
}
} else {
struct V_19 * V_21 =
& V_38 -> V_99 . V_20 ;
V_38 -> V_124 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_28 ; V_12 ++ ) {
if ( V_38 -> V_139 &&
V_38 -> V_139 <
F_34 ( V_2 , V_21 -> V_14 [ V_12 ] . V_5 ) )
break;
F_30 ( V_2 , V_12 , V_21 -> V_14 [ V_12 ] . V_26 ) ;
F_35 ( V_2 , V_12 , V_21 -> V_14 [ V_12 ] . V_5 ) ;
F_36 ( V_2 , V_12 , V_38 -> V_104 [ V_12 ] ) ;
F_118 ( V_2 , V_12 , true ) ;
V_38 -> V_124 ++ ;
}
}
for ( V_12 = 0 ; V_12 < V_131 ; V_12 ++ )
F_38 ( V_2 , V_12 , false ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
for ( V_12 = 0 ; V_12 < V_131 ; V_12 ++ ) {
if ( V_12 >= V_38 -> V_259 && V_12 <= V_38 -> V_261 )
F_38 ( V_2 , V_12 , true ) ;
}
}
static int F_114 ( struct V_1 * V_2 , T_1 V_269 )
{
T_1 V_332 = ( 1 << V_269 ) ;
return F_87 ( V_2 ,
V_333 ,
V_332 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 , V_332 = 0 ;
for ( V_12 = V_38 -> V_259 ; V_12 <= V_38 -> V_261 ; V_12 ++ )
V_332 |= ( 1 << V_12 ) ;
return F_87 ( V_2 ,
V_333 ,
V_332 ) ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_33 * V_257 )
{
struct V_32 * V_189 = F_6 ( V_257 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_334 ;
if ( V_2 -> V_117 == V_118 || V_2 -> V_117 == V_119 )
return;
if ( V_38 -> V_99 . V_322 ) {
V_334 = F_9 ( V_335 ) ;
V_334 &= ~ ( V_336 |
V_337 |
V_338 |
V_339 ) ;
V_334 |= ( V_189 -> V_318 << V_340 ) |
( V_189 -> V_319 << V_341 ) |
( V_189 -> V_320 << V_342 ) |
( V_189 -> V_321 << V_343 ) ;
F_12 ( V_335 , V_334 ) ;
}
}
static int F_71 ( struct V_1 * V_2 ,
int V_344 , int V_345 )
{
int V_346 = 0 * 1000 ;
int V_347 = 255 * 1000 ;
T_1 V_71 ;
if ( V_346 < V_344 )
V_346 = V_344 ;
if ( V_347 > V_345 )
V_347 = V_345 ;
if ( V_347 < V_346 ) {
F_66 ( L_19 , V_346 , V_347 ) ;
return - V_45 ;
}
V_71 = F_9 ( V_348 ) ;
V_71 &= ~ ( V_349 |
V_350 ) ;
V_71 |= ( ( 49 + ( V_347 / 1000 ) ) << V_351 ) |
( ( 49 + ( V_346 / 1000 ) ) << V_352 ) ;
F_12 ( V_348 , V_71 ) ;
V_2 -> V_8 . V_9 . V_202 . V_344 = V_346 ;
V_2 -> V_8 . V_9 . V_202 . V_345 = V_347 ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_353 * V_354 = & V_2 -> V_354 ;
int V_88 = F_121 ( V_355 , V_356 ) ;
union V_357 * V_357 ;
V_82 V_358 , V_359 ;
T_3 V_360 ;
int V_12 ;
if ( F_122 ( V_354 -> V_361 , V_88 , NULL ,
& V_358 , & V_359 , & V_360 ) ) {
V_357 = (union V_357 * ) ( V_354 -> V_361 -> V_362 +
V_360 ) ;
if ( V_359 != 8 ) {
F_66 ( L_20 , V_358 , V_359 ) ;
return - V_45 ;
}
V_38 -> V_99 . V_286 = F_123 ( V_357 -> V_363 . V_364 ) ;
V_38 -> V_99 . V_365 = F_123 ( V_357 -> V_363 . V_366 ) ;
V_38 -> V_99 . V_288 =
F_124 ( V_357 -> V_363 . V_367 ) ;
if ( V_357 -> V_363 . V_368 == 0 )
V_38 -> V_99 . V_369 = 203 ;
else
V_38 -> V_99 . V_369 = V_357 -> V_363 . V_368 ;
if ( V_357 -> V_363 . V_370 == 0 )
V_38 -> V_99 . V_371 = 5 ;
else
V_38 -> V_99 . V_371 = V_357 -> V_363 . V_370 ;
if ( V_38 -> V_99 . V_369 <= V_38 -> V_99 . V_371 ) {
F_66 ( L_21 ) ;
}
if ( F_123 ( V_357 -> V_363 . V_372 ) & ( 1 << 3 ) )
V_38 -> V_99 . V_322 = true ;
else
V_38 -> V_99 . V_322 = false ;
for ( V_12 = 0 ; V_12 < V_373 ; V_12 ++ ) {
V_38 -> V_99 . V_281 [ V_12 ] =
F_123 ( V_357 -> V_363 . V_374 [ V_12 ] ) ;
V_38 -> V_99 . V_375 [ V_12 ] =
F_123 ( V_357 -> V_363 . V_376 [ V_12 ] ) ;
}
if ( F_123 ( V_357 -> V_363 . V_377 ) &
V_378 )
V_38 -> V_135 = true ;
F_4 ( V_2 ,
& V_38 -> V_99 . V_20 ,
V_357 -> V_363 . V_379 ) ;
F_5 ( V_2 ,
& V_38 -> V_99 . V_4 ,
V_357 -> V_363 . V_379 ) ;
F_110 ( V_2 ,
& V_2 -> V_8 . V_9 . V_10 . V_309 ) ;
}
return 0 ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_32 * V_35 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_35 -> V_260 = 1 ;
V_35 -> V_258 [ 0 ] = V_38 -> V_126 ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_380 * V_381 ,
V_82 V_382 )
{
struct V_32 * V_35 = F_6 ( V_34 ) ;
V_34 -> V_383 = F_123 ( V_381 -> V_384 ) ;
V_34 -> V_314 = F_124 ( V_381 -> V_385 ) ;
V_34 -> V_386 = F_124 ( V_381 -> V_387 ) ;
if ( V_388 < V_382 ) {
V_34 -> V_142 = F_123 ( V_381 -> V_389 ) ;
V_34 -> V_144 = F_123 ( V_381 -> V_390 ) ;
} else {
V_34 -> V_142 = 0 ;
V_34 -> V_144 = 0 ;
}
if ( V_34 -> V_314 & V_391 ) {
V_2 -> V_8 . V_9 . V_196 = V_34 ;
F_125 ( V_2 , V_35 ) ;
}
if ( V_34 -> V_314 & V_392 )
V_2 -> V_8 . V_9 . V_393 = V_34 ;
}
static void F_127 ( struct V_1 * V_2 ,
struct V_33 * V_34 , int V_88 ,
union V_394 * V_395 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_32 * V_35 = F_6 ( V_34 ) ;
struct V_396 * V_397 = & V_35 -> V_258 [ V_88 ] ;
T_1 V_89 ;
V_89 = F_124 ( V_395 -> V_398 . V_399 ) ;
V_89 |= V_395 -> V_398 . V_400 << 16 ;
V_397 -> V_89 = V_89 ;
V_397 -> V_287 = V_395 -> V_398 . V_401 ;
V_35 -> V_260 = V_88 + 1 ;
if ( V_38 -> V_301 ) {
V_397 -> V_289 = 5 ;
V_397 -> V_290 = 5 ;
}
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_353 * V_354 = & V_2 -> V_354 ;
struct V_380 * V_381 ;
union V_402 * V_403 ;
int V_12 , V_29 , V_404 , V_405 , V_406 ;
union V_394 * V_395 ;
struct V_407 * V_408 ;
struct V_409 * V_410 ;
struct V_411 * V_412 ;
union V_413 * V_413 ;
int V_88 = F_121 ( V_355 , V_414 ) ;
T_3 V_360 ;
V_82 V_358 , V_359 ;
V_82 * V_415 ;
struct V_32 * V_35 ;
if ( ! F_122 ( V_354 -> V_361 , V_88 , NULL ,
& V_358 , & V_359 , & V_360 ) )
return - V_45 ;
V_413 = (union V_413 * ) ( V_354 -> V_361 -> V_362 + V_360 ) ;
F_129 ( V_2 ) ;
V_408 = (struct V_407 * )
( V_354 -> V_361 -> V_362 + V_360 +
F_124 ( V_413 -> V_416 . V_417 ) ) ;
V_410 = (struct V_409 * )
( V_354 -> V_361 -> V_362 + V_360 +
F_124 ( V_413 -> V_416 . V_418 ) ) ;
V_412 = (struct V_411 * )
( V_354 -> V_361 -> V_362 + V_360 +
F_124 ( V_413 -> V_416 . V_419 ) ) ;
V_2 -> V_8 . V_9 . V_35 = F_130 ( sizeof( struct V_33 ) *
V_408 -> V_420 , V_421 ) ;
if ( ! V_2 -> V_8 . V_9 . V_35 )
return - V_422 ;
V_415 = ( V_82 * ) V_408 -> V_423 ;
for ( V_12 = 0 ; V_12 < V_408 -> V_420 ; V_12 ++ ) {
V_82 * V_278 ;
V_403 = (union V_402 * ) V_415 ;
V_405 = V_403 -> V_424 . V_425 ;
V_381 = (struct V_380 * )
& V_412 -> V_426 [ V_405 ] ;
V_35 = F_130 ( sizeof( struct V_32 ) , V_421 ) ;
if ( V_35 == NULL ) {
F_131 ( V_2 -> V_8 . V_9 . V_35 ) ;
return - V_422 ;
}
V_2 -> V_8 . V_9 . V_35 [ V_12 ] . V_36 = V_35 ;
V_404 = 0 ;
V_278 = ( V_82 * ) & V_403 -> V_424 . V_427 [ 0 ] ;
for ( V_29 = 0 ; V_29 < V_403 -> V_424 . V_428 ; V_29 ++ ) {
V_406 = V_278 [ V_29 ] ;
if ( V_406 >= V_410 -> V_420 )
continue;
if ( V_404 >= V_24 )
break;
V_395 = (union V_394 * )
( ( V_82 * ) & V_410 -> V_429 [ 0 ] +
( V_406 * V_410 -> V_430 ) ) ;
F_127 ( V_2 ,
& V_2 -> V_8 . V_9 . V_35 [ V_12 ] , V_404 ,
V_395 ) ;
V_404 ++ ;
}
F_126 ( V_2 , & V_2 -> V_8 . V_9 . V_35 [ V_12 ] ,
V_381 ,
V_412 -> V_430 ) ;
V_415 += 2 + V_403 -> V_424 . V_428 ;
}
V_2 -> V_8 . V_9 . V_431 = V_408 -> V_420 ;
for ( V_12 = 0 ; V_12 < V_432 ; V_12 ++ ) {
T_1 V_89 ;
V_406 = V_2 -> V_8 . V_9 . V_311 [ V_12 ] . V_433 ;
V_395 = (union V_394 * )
& V_410 -> V_429 [ V_406 * V_410 -> V_430 ] ;
V_89 = F_124 ( V_395 -> V_398 . V_399 ) ;
V_89 |= V_395 -> V_398 . V_400 << 16 ;
V_2 -> V_8 . V_9 . V_311 [ V_12 ] . V_89 = V_89 ;
V_2 -> V_8 . V_9 . V_311 [ V_12 ] . V_280 = 0 ;
}
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_65 , V_12 ;
V_38 = F_130 ( sizeof( struct V_37 ) , V_421 ) ;
if ( V_38 == NULL )
return - V_422 ;
V_2 -> V_8 . V_9 . V_39 = V_38 ;
V_65 = F_133 ( V_2 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_134 ( V_2 ) ;
if ( V_65 )
return V_65 ;
for ( V_12 = 0 ; V_12 < V_24 ; V_12 ++ )
V_38 -> V_104 [ V_12 ] = V_434 ;
V_38 -> V_75 = V_435 ;
V_38 -> V_264 = true ;
V_38 -> V_436 = true ;
V_38 -> V_67 = true ;
V_38 -> V_437 = false ;
if ( V_38 -> V_437 ) {
V_38 -> V_53 = true ;
V_38 -> V_56 = true ;
V_38 -> V_59 = true ;
V_38 -> V_62 = true ;
}
V_38 -> V_301 = true ;
V_38 -> V_195 = true ;
V_38 -> V_324 = false ;
if ( V_438 == 0 )
V_38 -> V_194 = false ;
else
V_38 -> V_194 = true ;
V_38 -> V_102 = 0 ;
V_38 -> V_122 = false ;
V_38 -> V_205 = false ;
V_38 -> V_242 = ( V_2 -> V_439 & V_440 ) ? true : false ;
V_38 -> V_224 = true ;
V_38 -> V_248 = ( V_2 -> V_439 & V_441 ) ? true : false ;
V_38 -> V_251 = ( V_2 -> V_439 & V_442 ) ? true : false ;
V_38 -> V_254 = ( V_2 -> V_439 & V_443 ) ? true : false ;
V_38 -> V_225 = false ;
V_65 = F_120 ( V_2 ) ;
if ( V_65 )
return V_65 ;
F_111 ( V_2 ) ;
F_112 ( V_2 ) ;
V_65 = F_128 ( V_2 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_276 = true ;
return 0 ;
}
static void
F_135 ( struct V_1 * V_2 ,
struct V_444 * V_445 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_446 =
( F_9 ( V_447 ) &
V_448 ) >>
V_449 ;
T_1 V_89 , V_71 ;
T_3 V_279 ;
if ( V_446 >= V_450 ) {
F_136 ( V_445 , L_22 , V_446 ) ;
} else {
V_89 = F_119 ( V_38 -> V_93 [ V_446 ] . V_96 ) ;
V_71 = ( F_9 ( V_451 ) &
V_452 ) >>
V_453 ;
V_279 = F_33 ( V_2 , ( T_3 ) V_71 ) ;
F_136 ( V_445 , L_23 , V_38 -> V_210 ? L_24 : L_25 ) ;
F_136 ( V_445 , L_26 , V_38 -> V_211 ? L_24 : L_25 ) ;
F_136 ( V_445 , L_27 ,
V_446 , V_89 , V_279 ) ;
}
}
static void
F_137 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_12 ;
struct V_32 * V_35 = F_6 ( V_34 ) ;
F_138 ( V_34 -> V_314 , V_34 -> V_386 ) ;
F_139 ( V_34 -> V_383 ) ;
F_140 ( L_28 , V_34 -> V_142 , V_34 -> V_144 ) ;
for ( V_12 = 0 ; V_12 < V_35 -> V_260 ; V_12 ++ ) {
struct V_396 * V_397 = & V_35 -> V_258 [ V_12 ] ;
F_140 ( L_29 ,
V_12 , V_397 -> V_89 ,
F_33 ( V_2 , V_397 -> V_287 ) ) ;
}
F_141 ( V_2 , V_34 ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_8 . V_9 . V_431 ; V_12 ++ ) {
F_131 ( V_2 -> V_8 . V_9 . V_35 [ V_12 ] . V_36 ) ;
}
F_131 ( V_2 -> V_8 . V_9 . V_35 ) ;
F_131 ( V_2 -> V_8 . V_9 . V_39 ) ;
F_143 ( V_2 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
}
static T_1 F_145 ( struct V_1 * V_2 , bool V_454 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_32 * V_455 = F_6 ( & V_38 -> V_192 ) ;
if ( V_454 )
return V_455 -> V_258 [ 0 ] . V_89 ;
else
return V_455 -> V_258 [ V_455 -> V_260 - 1 ] . V_89 ;
}
static T_1 F_146 ( struct V_1 * V_2 , bool V_454 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
return V_38 -> V_99 . V_365 ;
}
static int F_147 ( struct V_1 * V_2 )
{
T_1 V_298 ;
int V_456 = 0 ;
V_298 = F_9 ( 0xC0300E0C ) ;
if ( V_298 )
V_456 = ( V_298 / 8 ) - 49 ;
else
V_456 = 0 ;
V_456 = V_456 * 1000 ;
return V_456 ;
}
static int F_148 ( void * V_457 )
{
struct V_1 * V_2 = (struct V_1 * ) V_457 ;
F_149 ( V_2 ) ;
F_150 ( V_2 ) ;
return 0 ;
}
static int F_151 ( void * V_457 )
{
struct V_1 * V_2 = (struct V_1 * ) V_457 ;
int V_65 ;
if ( ! V_458 )
return 0 ;
V_65 = F_152 ( V_2 ) ;
if ( V_65 )
return V_65 ;
F_76 ( V_2 , true ) ;
F_77 ( V_2 , true ) ;
F_78 ( V_2 , true ) ;
F_79 ( V_2 , true ) ;
return 0 ;
}
static int F_153 ( void * V_457 )
{
int V_65 ;
struct V_1 * V_2 = (struct V_1 * ) V_457 ;
V_65 = F_154 ( V_2 , 230 , & V_2 -> V_8 . V_9 . V_202 . V_197 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_154 ( V_2 , 231 , & V_2 -> V_8 . V_9 . V_202 . V_197 ) ;
if ( V_65 )
return V_65 ;
V_2 -> V_8 . V_9 . V_459 = V_460 ;
V_2 -> V_8 . V_9 . V_461 = V_460 ;
V_2 -> V_8 . V_9 . V_273 = V_272 ;
V_2 -> V_8 . V_462 = V_2 -> clock . V_462 ;
V_2 -> V_8 . V_463 = V_2 -> clock . V_463 ;
V_2 -> V_8 . V_464 = V_2 -> clock . V_462 ;
V_2 -> V_8 . V_465 = V_2 -> clock . V_463 ;
V_2 -> V_8 . V_199 = V_466 ;
if ( V_458 == 0 )
return 0 ;
F_155 ( & V_2 -> V_8 . V_9 . V_202 . V_467 , V_468 ) ;
F_156 ( & V_2 -> V_8 . V_469 ) ;
V_65 = F_132 ( V_2 ) ;
if ( V_65 )
goto V_470;
V_2 -> V_8 . V_9 . V_191 = V_2 -> V_8 . V_9 . V_193 = V_2 -> V_8 . V_9 . V_196 ;
if ( V_458 == 1 )
F_157 ( V_2 ) ;
F_158 ( & V_2 -> V_8 . V_469 ) ;
F_159 ( L_30 ) ;
return 0 ;
V_470:
F_142 ( V_2 ) ;
F_158 ( & V_2 -> V_8 . V_469 ) ;
F_66 ( L_31 ) ;
return V_65 ;
}
static int F_160 ( void * V_457 )
{
struct V_1 * V_2 = (struct V_1 * ) V_457 ;
F_156 ( & V_2 -> V_8 . V_469 ) ;
F_161 ( V_2 ) ;
F_142 ( V_2 ) ;
F_158 ( & V_2 -> V_8 . V_469 ) ;
return 0 ;
}
static int F_162 ( void * V_457 )
{
int V_65 ;
struct V_1 * V_2 = (struct V_1 * ) V_457 ;
F_156 ( & V_2 -> V_8 . V_469 ) ;
F_109 ( V_2 ) ;
V_65 = F_67 ( V_2 ) ;
if ( V_65 )
V_2 -> V_8 . V_471 = false ;
else
V_2 -> V_8 . V_471 = true ;
F_158 ( & V_2 -> V_8 . V_469 ) ;
return V_65 ;
}
static int F_163 ( void * V_457 )
{
struct V_1 * V_2 = (struct V_1 * ) V_457 ;
if ( V_2 -> V_8 . V_471 ) {
F_156 ( & V_2 -> V_8 . V_469 ) ;
F_73 ( V_2 ) ;
F_158 ( & V_2 -> V_8 . V_469 ) ;
}
return 0 ;
}
static int F_164 ( void * V_457 )
{
struct V_1 * V_2 = (struct V_1 * ) V_457 ;
if ( V_2 -> V_8 . V_471 ) {
F_156 ( & V_2 -> V_8 . V_469 ) ;
F_73 ( V_2 ) ;
V_2 -> V_8 . V_9 . V_191 = V_2 -> V_8 . V_9 . V_193 = V_2 -> V_8 . V_9 . V_196 ;
F_158 ( & V_2 -> V_8 . V_469 ) ;
}
return 0 ;
}
static int F_165 ( void * V_457 )
{
int V_65 ;
struct V_1 * V_2 = (struct V_1 * ) V_457 ;
if ( V_2 -> V_8 . V_471 ) {
F_156 ( & V_2 -> V_8 . V_469 ) ;
F_109 ( V_2 ) ;
V_65 = F_67 ( V_2 ) ;
if ( V_65 )
V_2 -> V_8 . V_471 = false ;
else
V_2 -> V_8 . V_471 = true ;
F_158 ( & V_2 -> V_8 . V_469 ) ;
if ( V_2 -> V_8 . V_471 )
F_166 ( V_2 ) ;
}
return 0 ;
}
static bool F_167 ( void * V_457 )
{
return true ;
}
static int F_168 ( void * V_457 )
{
return 0 ;
}
static int F_169 ( void * V_457 )
{
return 0 ;
}
static int F_170 ( struct V_1 * V_2 ,
struct V_472 * V_473 ,
unsigned type ,
enum V_474 V_459 )
{
T_1 V_475 ;
switch ( type ) {
case V_203 :
switch ( V_459 ) {
case V_476 :
V_475 = F_9 ( V_348 ) ;
V_475 &= ~ V_477 ;
F_12 ( V_348 , V_475 ) ;
break;
case V_478 :
V_475 = F_9 ( V_348 ) ;
V_475 |= V_477 ;
F_12 ( V_348 , V_475 ) ;
break;
default:
break;
}
break;
case V_204 :
switch ( V_459 ) {
case V_476 :
V_475 = F_9 ( V_348 ) ;
V_475 &= ~ V_479 ;
F_12 ( V_348 , V_475 ) ;
break;
case V_478 :
V_475 = F_9 ( V_348 ) ;
V_475 |= V_479 ;
F_12 ( V_348 , V_475 ) ;
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
static int F_171 ( struct V_1 * V_2 ,
struct V_472 * V_480 ,
struct V_481 * V_482 )
{
bool V_483 = false ;
if ( V_482 == NULL )
return - V_45 ;
switch ( V_482 -> V_484 ) {
case 230 :
F_172 ( L_32 ) ;
V_2 -> V_8 . V_9 . V_202 . V_485 = false ;
V_483 = true ;
break;
case 231 :
F_172 ( L_33 ) ;
V_2 -> V_8 . V_9 . V_202 . V_485 = true ;
V_483 = true ;
break;
default:
break;
}
if ( V_483 )
F_173 ( & V_2 -> V_8 . V_9 . V_202 . V_467 ) ;
return 0 ;
}
static int F_174 ( void * V_457 ,
enum V_486 V_459 )
{
return 0 ;
}
static int F_175 ( void * V_457 ,
enum V_487 V_459 )
{
return 0 ;
}
static void F_149 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_488 == NULL )
V_2 -> V_8 . V_488 = & V_489 ;
}
static void F_150 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_9 . V_202 . V_197 . V_490 = V_491 ;
V_2 -> V_8 . V_9 . V_202 . V_197 . V_488 = & V_492 ;
}
