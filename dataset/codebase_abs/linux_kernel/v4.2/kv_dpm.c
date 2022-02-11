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
static T_1 F_4 ( T_1 V_19 )
{
return 1 << V_19 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
T_2 * V_22 )
{
T_1 V_12 ;
T_1 V_23 = 0 ;
T_1 V_24 = 0 ;
for ( V_12 = 0 ; V_12 < V_25 ; V_12 ++ ) {
if ( V_22 [ V_12 ] . V_26 > V_24 ) {
V_21 -> V_14 [ V_23 ] . V_27 =
V_22 [ V_12 ] . V_26 ;
V_21 -> V_14 [ V_23 ] . V_5 =
V_22 [ V_12 ] . V_28 ;
V_24 = V_22 [ V_12 ] . V_26 ;
V_23 ++ ;
}
}
V_21 -> V_29 = V_23 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 * V_22 )
{
T_1 V_12 , V_30 ;
for ( V_12 = 0 ; V_12 < V_25 ; V_12 ++ ) {
if ( V_22 [ V_12 ] . V_26 != 0 ) {
V_4 -> V_14 [ V_22 [ V_12 ] . V_28 ] . V_17 =
V_22 [ V_12 ] . V_31 ;
V_4 -> V_14 [ V_22 [ V_12 ] . V_28 ] . V_5 =
V_22 [ V_12 ] . V_28 ;
}
}
for ( V_12 = 0 ; V_12 < V_32 ; V_12 ++ ) {
if ( V_4 -> V_14 [ V_12 ] . V_17 == 0 ) {
for ( V_30 = V_12 + 1 ; V_30 < V_32 ; V_30 ++ ) {
if ( V_4 -> V_14 [ V_30 ] . V_17 != 0 ) {
V_4 -> V_14 [ V_12 ] =
V_4 -> V_14 [ V_30 ] ;
V_4 -> V_14 [ V_30 ] . V_17 = 0 ;
break;
}
}
if ( V_30 == V_32 )
break;
}
}
V_4 -> V_16 = V_12 ;
}
static struct V_33 * F_7 ( struct V_34 * V_35 )
{
struct V_33 * V_36 = V_35 -> V_37 ;
return V_36 ;
}
static struct V_38 * F_8 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_8 . V_9 . V_40 ;
return V_39 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_41 * V_42 )
{
const struct V_41 * V_43 = V_42 ;
T_1 V_44 ;
T_1 V_45 = 0 ;
if ( V_43 == NULL )
return - V_46 ;
while ( V_43 -> V_47 != 0xFFFFFFFF ) {
if ( V_43 -> type == V_48 ) {
V_45 |= ( ( V_43 -> V_49 << V_43 -> V_50 ) & V_43 -> V_51 ) ;
} else {
switch ( V_43 -> type ) {
case V_52 :
V_44 = F_10 ( V_43 -> V_47 ) ;
break;
case V_53 :
V_44 = F_11 ( V_43 -> V_47 ) ;
break;
default:
V_44 = F_12 ( V_43 -> V_47 ) ;
break;
}
V_44 &= ~ V_43 -> V_51 ;
V_44 |= ( ( V_43 -> V_49 << V_43 -> V_50 ) & V_43 -> V_51 ) ;
V_44 |= V_45 ;
V_45 = 0 ;
switch ( V_43 -> type ) {
case V_52 :
F_13 ( V_43 -> V_47 , V_44 ) ;
break;
case V_53 :
F_14 ( V_43 -> V_47 , V_44 ) ;
break;
default:
F_15 ( V_43 -> V_47 , V_44 ) ;
break;
}
}
V_43 ++ ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , bool V_18 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_44 ;
if ( V_39 -> V_54 ) {
V_44 = F_11 ( V_55 ) ;
if ( V_18 )
V_44 |= V_56 ;
else
V_44 &= ~ V_56 ;
F_14 ( V_55 , V_44 ) ;
}
if ( V_39 -> V_57 ) {
V_44 = F_11 ( V_58 ) ;
if ( V_18 )
V_44 |= V_59 ;
else
V_44 &= ~ V_59 ;
F_14 ( V_58 , V_44 ) ;
}
if ( V_39 -> V_60 ) {
V_44 = F_11 ( V_61 ) ;
if ( V_18 )
V_44 |= V_62 ;
else
V_44 &= ~ V_62 ;
F_14 ( V_61 , V_44 ) ;
}
if ( V_39 -> V_63 ) {
V_44 = F_11 ( V_64 ) ;
if ( V_18 )
V_44 |= V_65 ;
else
V_44 &= ~ V_65 ;
F_14 ( V_64 , V_44 ) ;
}
}
static int F_17 ( struct V_1 * V_2 , bool V_18 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 ;
if ( V_39 -> V_54 ||
V_39 -> V_57 ||
V_39 -> V_60 ||
V_39 -> V_63 ) {
F_18 ( V_2 ) ;
if ( V_18 ) {
V_66 = F_9 ( V_2 , V_67 ) ;
if ( V_66 ) {
F_19 ( V_2 ) ;
return V_66 ;
}
}
F_16 ( V_2 , V_18 ) ;
F_19 ( V_2 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , bool V_18 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 = 0 ;
if ( V_39 -> V_68 ) {
if ( V_18 ) {
V_66 = F_21 ( V_2 , V_69 ) ;
if ( V_66 )
V_39 -> V_70 = false ;
else
V_39 -> V_70 = true ;
} else if ( V_39 -> V_70 ) {
F_21 ( V_2 , V_71 ) ;
V_39 -> V_70 = false ;
}
}
return V_66 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_72 ;
int V_66 ;
V_66 = F_23 ( V_2 , V_73 +
F_24 ( V_74 , V_75 ) ,
& V_72 , V_39 -> V_76 ) ;
if ( V_66 == 0 )
V_39 -> V_77 = V_72 ;
V_66 = F_23 ( V_2 , V_73 +
F_24 ( V_74 , V_78 ) ,
& V_72 , V_39 -> V_76 ) ;
if ( V_66 == 0 )
V_39 -> V_79 = V_72 ;
return V_66 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 ;
V_39 -> V_80 = 1 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_82 ) ,
& V_39 -> V_80 ,
sizeof( V_83 ) , V_39 -> V_76 ) ;
return V_66 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 ;
V_39 -> V_84 = 1 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_85 ) ,
& V_39 -> V_84 ,
sizeof( V_83 ) , V_39 -> V_76 ) ;
return V_66 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_86 ) ,
& V_39 -> V_87 ,
sizeof( V_83 ) , V_39 -> V_76 ) ;
return V_66 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_13 ( V_88 , 0x3FFFC100 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_13 ( V_88 , 0 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
T_1 V_89 , T_1 V_90 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_91 V_92 ;
int V_66 ;
V_66 = F_32 ( V_2 , V_93 ,
V_90 , false , & V_92 ) ;
if ( V_66 )
return V_66 ;
V_39 -> V_94 [ V_89 ] . V_95 = ( V_83 ) V_92 . V_96 ;
V_39 -> V_94 [ V_89 ] . V_97 = F_33 ( V_90 ) ;
return 0 ;
}
static T_3 F_34 ( struct V_1 * V_2 ,
T_3 V_98 )
{
return 6200 - ( V_98 * 25 ) ;
}
static T_3 F_35 ( struct V_1 * V_2 ,
T_1 V_5 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_99 = F_1 ( V_2 ,
& V_39 -> V_100 . V_4 ,
V_5 ) ;
return F_34 ( V_2 , ( T_3 ) V_99 ) ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_89 , T_1 V_101 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_39 -> V_94 [ V_89 ] . V_102 = ( V_83 ) V_39 -> V_103 ;
V_39 -> V_94 [ V_89 ] . V_104 =
F_33 ( F_35 ( V_2 , V_101 ) ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_89 , T_1 V_105 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_39 -> V_94 [ V_89 ] . V_106 = F_38 ( ( T_3 ) V_105 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
T_1 V_89 , bool V_18 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_39 -> V_94 [ V_89 ] . V_107 = V_18 ? 1 : 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_72 = F_10 ( V_108 ) ;
V_72 |= V_109 ;
F_13 ( V_108 , V_72 ) ;
F_41 ( V_2 , true ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_41 ( V_2 , false ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
T_1 V_110 = F_10 ( V_111 ) ;
V_110 &= ~ ( V_112 |
V_113 ) ;
V_110 |= V_114 ;
F_13 ( V_111 , V_110 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
T_1 V_110 = F_10 ( V_111 ) ;
V_110 |= ( V_112 |
V_113 ) ;
F_13 ( V_111 , V_110 ) ;
}
static int F_45 ( struct V_1 * V_2 , bool V_115 )
{
return F_21 ( V_2 , V_115 ?
V_116 : V_117 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_118 == V_119 || V_2 -> V_118 == V_120 )
return F_21 ( V_2 , V_121 ) ;
else
return F_49 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_122 = 0 ;
int V_66 = 0 ;
if ( V_39 -> V_123 ) {
V_122 = F_33 ( V_39 -> V_122 ) ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_124 ) ,
( V_83 * ) & V_122 ,
sizeof( T_1 ) , V_39 -> V_76 ) ;
}
return V_66 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_22 && V_22 -> V_13 ) {
for ( V_12 = V_39 -> V_125 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_22 -> V_14 [ V_12 ] . V_126 == V_39 -> V_127 . V_90 )
break;
}
V_39 -> V_87 = ( V_83 ) V_12 ;
F_39 ( V_2 , V_12 , true ) ;
} else {
struct V_20 * V_22 =
& V_39 -> V_100 . V_21 ;
if ( V_22 -> V_29 == 0 )
return - V_46 ;
for ( V_12 = V_39 -> V_125 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_22 -> V_14 [ V_12 ] . V_27 == V_39 -> V_127 . V_90 )
break;
}
V_39 -> V_87 = ( V_83 ) V_12 ;
F_39 ( V_2 , V_12 , true ) ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 ;
V_39 -> V_128 = 1 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_129 ) ,
& V_39 -> V_128 ,
sizeof( V_83 ) , V_39 -> V_76 ) ;
return V_66 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_130 ) ,
( V_83 * ) & V_39 -> V_94 ,
sizeof( V_131 ) * V_132 ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_133 ) ,
& V_39 -> V_125 ,
sizeof( V_83 ) , V_39 -> V_76 ) ;
return V_66 ;
}
static T_1 F_54 ( T_1 V_134 , T_1 V_135 )
{
return ( V_134 >= V_135 ) ? V_134 - V_135 : V_135 - V_134 ;
}
static T_1 F_55 ( struct V_1 * V_2 , T_1 V_126 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_49 ;
if ( V_39 -> V_136 ) {
if ( F_54 ( V_126 , 40000 ) < 200 )
V_49 = 3 ;
else if ( F_54 ( V_126 , 30000 ) < 200 )
V_49 = 2 ;
else if ( F_54 ( V_126 , 20000 ) < 200 )
V_49 = 7 ;
else if ( F_54 ( V_126 , 15000 ) < 200 )
V_49 = 6 ;
else if ( F_54 ( V_126 , 10000 ) < 200 )
V_49 = 8 ;
else
V_49 = 0 ;
} else {
V_49 = 0 ;
}
return V_49 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_137 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_138 ;
struct V_91 V_92 ;
int V_66 ;
T_1 V_12 ;
if ( V_22 == NULL || V_22 -> V_13 == 0 )
return 0 ;
V_39 -> V_139 = 0 ;
for ( V_12 = 0 ; V_12 < V_22 -> V_13 ; V_12 ++ ) {
if ( V_39 -> V_140 &&
( V_39 -> V_140 < V_22 -> V_14 [ V_12 ] . V_15 ) )
break;
V_39 -> V_141 [ V_12 ] . V_142 = F_33 ( V_22 -> V_14 [ V_12 ] . V_143 ) ;
V_39 -> V_141 [ V_12 ] . V_144 = F_33 ( V_22 -> V_14 [ V_12 ] . V_145 ) ;
V_39 -> V_141 [ V_12 ] . V_104 = F_38 ( V_22 -> V_14 [ V_12 ] . V_15 ) ;
V_39 -> V_141 [ V_12 ] . V_146 =
( V_83 ) F_55 ( V_2 , V_22 -> V_14 [ V_12 ] . V_143 ) ;
V_39 -> V_141 [ V_12 ] . V_147 =
( V_83 ) F_55 ( V_2 , V_22 -> V_14 [ V_12 ] . V_145 ) ;
V_66 = F_32 ( V_2 , V_93 ,
V_22 -> V_14 [ V_12 ] . V_143 , false , & V_92 ) ;
if ( V_66 )
return V_66 ;
V_39 -> V_141 [ V_12 ] . V_148 = ( V_83 ) V_92 . V_96 ;
V_66 = F_32 ( V_2 , V_93 ,
V_22 -> V_14 [ V_12 ] . V_145 , false , & V_92 ) ;
if ( V_66 )
return V_66 ;
V_39 -> V_141 [ V_12 ] . V_149 = ( V_83 ) V_92 . V_96 ;
V_39 -> V_139 ++ ;
}
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_150 ) ,
( V_83 * ) & V_39 -> V_139 ,
sizeof( V_83 ) , V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
V_39 -> V_151 = 1 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_152 ) ,
& V_39 -> V_151 ,
sizeof( V_83 ) , V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_153 ) ,
( V_83 * ) & V_39 -> V_141 ,
sizeof( V_154 ) * V_155 ,
V_39 -> V_76 ) ;
return V_66 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 ;
T_1 V_12 ;
struct V_156 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_157 ;
struct V_91 V_92 ;
if ( V_22 == NULL || V_22 -> V_13 == 0 )
return 0 ;
V_39 -> V_158 = 0 ;
for ( V_12 = 0 ; V_12 < V_22 -> V_13 ; V_12 ++ ) {
if ( V_39 -> V_140 &&
V_39 -> V_140 < V_22 -> V_14 [ V_12 ] . V_15 )
break;
V_39 -> V_159 [ V_12 ] . V_160 = F_33 ( V_22 -> V_14 [ V_12 ] . V_161 ) ;
V_39 -> V_159 [ V_12 ] . V_162 = F_38 ( V_22 -> V_14 [ V_12 ] . V_15 ) ;
V_39 -> V_159 [ V_12 ] . V_163 =
( V_83 ) F_55 ( V_2 , V_22 -> V_14 [ V_12 ] . V_161 ) ;
V_66 = F_32 ( V_2 , V_93 ,
V_22 -> V_14 [ V_12 ] . V_161 , false , & V_92 ) ;
if ( V_66 )
return V_66 ;
V_39 -> V_159 [ V_12 ] . V_164 = ( V_83 ) V_92 . V_96 ;
V_39 -> V_158 ++ ;
}
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_165 ) ,
( V_83 * ) & V_39 -> V_158 ,
sizeof( V_83 ) ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
V_39 -> V_166 = 1 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_167 ) ,
( V_83 * ) & V_39 -> V_166 ,
sizeof( V_83 ) ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_168 ) ,
( V_83 * ) & V_39 -> V_159 ,
sizeof( V_169 ) * V_170 ,
V_39 -> V_76 ) ;
return V_66 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_6 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_171 ;
struct V_91 V_92 ;
int V_66 ;
T_1 V_12 ;
if ( V_22 == NULL || V_22 -> V_13 == 0 )
return 0 ;
V_39 -> V_172 = 0 ;
for ( V_12 = 0 ; V_12 < V_22 -> V_13 ; V_12 ++ ) {
if ( V_39 -> V_140 &&
V_39 -> V_140 < V_22 -> V_14 [ V_12 ] . V_15 )
break;
V_39 -> V_173 [ V_12 ] . V_160 = F_33 ( V_22 -> V_14 [ V_12 ] . V_126 ) ;
V_39 -> V_173 [ V_12 ] . V_162 = F_38 ( V_22 -> V_14 [ V_12 ] . V_15 ) ;
V_39 -> V_173 [ V_12 ] . V_163 =
( V_83 ) F_55 ( V_2 , V_22 -> V_14 [ V_12 ] . V_126 ) ;
V_66 = F_32 ( V_2 , V_93 ,
V_22 -> V_14 [ V_12 ] . V_126 , false , & V_92 ) ;
if ( V_66 )
return V_66 ;
V_39 -> V_173 [ V_12 ] . V_164 = ( V_83 ) V_92 . V_96 ;
V_39 -> V_172 ++ ;
}
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_174 ) ,
( V_83 * ) & V_39 -> V_172 ,
sizeof( V_83 ) ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
V_39 -> V_175 = 1 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_176 ) ,
( V_83 * ) & V_39 -> V_175 ,
sizeof( V_83 ) ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_177 ) ,
( V_83 * ) & V_39 -> V_173 ,
sizeof( V_169 ) * V_178 ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
return V_66 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_6 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_179 ;
struct V_91 V_92 ;
int V_66 ;
T_1 V_12 ;
if ( V_22 == NULL || V_22 -> V_13 == 0 )
return 0 ;
V_39 -> V_180 = 0 ;
for ( V_12 = 0 ; V_12 < V_22 -> V_13 ; V_12 ++ ) {
V_39 -> V_181 [ V_12 ] . V_160 = F_33 ( V_22 -> V_14 [ V_12 ] . V_126 ) ;
V_39 -> V_181 [ V_12 ] . V_162 = F_38 ( V_22 -> V_14 [ V_12 ] . V_15 ) ;
V_66 = F_32 ( V_2 , V_93 ,
V_22 -> V_14 [ V_12 ] . V_126 , false , & V_92 ) ;
if ( V_66 )
return V_66 ;
V_39 -> V_181 [ V_12 ] . V_164 = ( V_83 ) V_92 . V_96 ;
V_39 -> V_180 ++ ;
}
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_182 ) ,
( V_83 * ) & V_39 -> V_180 ,
sizeof( V_83 ) ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
V_39 -> V_183 = 1 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_184 ) ,
( V_83 * ) & V_39 -> V_183 ,
sizeof( V_83 ) ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_185 ) ,
( V_83 * ) & V_39 -> V_181 ,
sizeof( V_169 ) * V_186 ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
return V_66 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_22 && V_22 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_39 -> V_125 ; V_12 ++ ) {
if ( V_39 -> V_136 ) {
if ( F_54 ( V_22 -> V_14 [ V_12 ] . V_126 , 40000 ) < 200 )
V_39 -> V_94 [ V_12 ] . V_163 = 3 ;
else if ( F_54 ( V_22 -> V_14 [ V_12 ] . V_126 , 30000 ) < 200 )
V_39 -> V_94 [ V_12 ] . V_163 = 2 ;
else if ( F_54 ( V_22 -> V_14 [ V_12 ] . V_126 , 26600 ) < 200 )
V_39 -> V_94 [ V_12 ] . V_163 = 7 ;
else if ( F_54 ( V_22 -> V_14 [ V_12 ] . V_126 , 20000 ) < 200 )
V_39 -> V_94 [ V_12 ] . V_163 = 6 ;
else if ( F_54 ( V_22 -> V_14 [ V_12 ] . V_126 , 10000 ) < 200 )
V_39 -> V_94 [ V_12 ] . V_163 = 8 ;
else
V_39 -> V_94 [ V_12 ] . V_163 = 0 ;
} else {
V_39 -> V_94 [ V_12 ] . V_163 = 0 ;
}
}
} else {
struct V_20 * V_22 =
& V_39 -> V_100 . V_21 ;
for ( V_12 = 0 ; V_12 < V_39 -> V_125 ; V_12 ++ ) {
if ( V_39 -> V_136 ) {
if ( F_54 ( V_22 -> V_14 [ V_12 ] . V_27 , 40000 ) < 200 )
V_39 -> V_94 [ V_12 ] . V_163 = 3 ;
else if ( F_54 ( V_22 -> V_14 [ V_12 ] . V_27 , 30000 ) < 200 )
V_39 -> V_94 [ V_12 ] . V_163 = 2 ;
else if ( F_54 ( V_22 -> V_14 [ V_12 ] . V_27 , 26600 ) < 200 )
V_39 -> V_94 [ V_12 ] . V_163 = 7 ;
else if ( F_54 ( V_22 -> V_14 [ V_12 ] . V_27 , 20000 ) < 200 )
V_39 -> V_94 [ V_12 ] . V_163 = 6 ;
else if ( F_54 ( V_22 -> V_14 [ V_12 ] . V_27 , 10000 ) < 200 )
V_39 -> V_94 [ V_12 ] . V_163 = 8 ;
else
V_39 -> V_94 [ V_12 ] . V_163 = 0 ;
} else {
V_39 -> V_94 [ V_12 ] . V_163 = 0 ;
}
}
}
}
static int F_61 ( struct V_1 * V_2 , bool V_18 )
{
return F_21 ( V_2 , V_18 ?
V_187 : V_188 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_39 -> V_189 = 0xff ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_33 * V_190 = F_7 ( V_35 ) ;
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_39 -> V_191 = * V_35 ;
V_39 -> V_192 = * V_190 ;
V_39 -> V_191 . V_37 = & V_39 -> V_192 ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_33 * V_190 = F_7 ( V_35 ) ;
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_39 -> V_193 = * V_35 ;
V_39 -> V_194 = * V_190 ;
V_39 -> V_193 . V_37 = & V_39 -> V_194 ;
}
static void F_65 ( struct V_1 * V_2 , bool V_18 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 ;
if ( V_39 -> V_195 ) {
V_66 = F_66 ( V_2 , V_18 ) ;
if ( V_66 )
F_67 ( L_1 ) ;
}
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 ;
V_66 = F_22 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_2 ) ;
return V_66 ;
}
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
V_66 = F_51 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_3 ) ;
return V_66 ;
}
F_60 ( V_2 ) ;
V_66 = F_53 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_4 ) ;
return V_66 ;
}
V_66 = F_56 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_5 ) ;
return V_66 ;
}
V_66 = F_57 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_6 ) ;
return V_66 ;
}
V_66 = F_58 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_7 ) ;
return V_66 ;
}
V_66 = F_59 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_8 ) ;
return V_66 ;
}
F_29 ( V_2 ) ;
#if 0
kv_initialize_hardware_cac_manager(adev);
#endif
F_43 ( V_2 ) ;
if ( V_39 -> V_196 ) {
V_66 = F_52 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_9 ) ;
return V_66 ;
}
}
V_66 = F_25 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_10 ) ;
return V_66 ;
}
V_66 = F_27 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_11 ) ;
return V_66 ;
}
V_66 = F_28 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_12 ) ;
return V_66 ;
}
V_66 = F_61 ( V_2 , true ) ;
if ( V_66 ) {
F_67 ( L_13 ) ;
return V_66 ;
}
F_40 ( V_2 ) ;
V_66 = F_17 ( V_2 , true ) ;
if ( V_66 ) {
F_67 ( L_14 ) ;
return V_66 ;
}
V_66 = F_20 ( V_2 , true ) ;
if ( V_66 ) {
F_67 ( L_15 ) ;
return V_66 ;
}
F_62 ( V_2 ) ;
V_66 = F_66 ( V_2 , false ) ;
if ( V_66 ) {
F_67 ( L_1 ) ;
return V_66 ;
}
F_63 ( V_2 , V_2 -> V_8 . V_9 . V_197 ) ;
if ( V_2 -> V_198 . V_199 &&
F_71 ( V_2 -> V_8 . V_200 ) ) {
V_66 = F_72 ( V_2 , V_201 , V_202 ) ;
if ( V_66 ) {
F_67 ( L_16 ) ;
return V_66 ;
}
F_73 ( V_2 , & V_2 -> V_8 . V_9 . V_203 . V_198 ,
V_204 ) ;
F_73 ( V_2 , & V_2 -> V_8 . V_9 . V_203 . V_198 ,
V_205 ) ;
}
return V_66 ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_75 ( V_2 , & V_2 -> V_8 . V_9 . V_203 . V_198 ,
V_204 ) ;
F_75 ( V_2 , & V_2 -> V_8 . V_9 . V_203 . V_198 ,
V_205 ) ;
F_66 ( V_2 , false ) ;
if ( V_2 -> V_118 == V_120 )
F_76 ( V_2 , false ) ;
F_77 ( V_2 , false ) ;
F_78 ( V_2 , false ) ;
F_79 ( V_2 , false ) ;
F_80 ( V_2 , false ) ;
F_20 ( V_2 , false ) ;
F_17 ( V_2 , false ) ;
F_30 ( V_2 ) ;
F_42 ( V_2 ) ;
F_61 ( V_2 , false ) ;
F_44 ( V_2 ) ;
F_63 ( V_2 , V_2 -> V_8 . V_9 . V_197 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_39 -> V_122 = 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 = 0 ;
if ( V_39 -> V_206 ) {
T_3 V_72 ;
V_72 = 45 ;
V_39 -> V_207 = F_38 ( V_72 ) ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_208 ) ,
( V_83 * ) & V_39 -> V_207 ,
sizeof( T_3 ) , V_39 -> V_76 ) ;
V_72 = 30 ;
V_39 -> V_209 = F_38 ( V_72 ) ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_210 ) ,
( V_83 * ) & V_39 -> V_209 ,
sizeof( T_3 ) , V_39 -> V_76 ) ;
}
return V_66 ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_39 -> V_211 = false ;
V_39 -> V_212 = false ;
V_39 -> V_213 = false ;
V_39 -> V_214 = false ;
}
static int F_83 ( struct V_1 * V_2 , bool V_18 )
{
return F_21 ( V_2 , V_18 ?
V_215 : V_216 ) ;
}
static int F_84 ( struct V_1 * V_2 , bool V_18 )
{
return F_21 ( V_2 , V_18 ?
V_217 : V_218 ) ;
}
static int F_85 ( struct V_1 * V_2 , bool V_18 )
{
return F_21 ( V_2 , V_18 ?
V_219 : V_220 ) ;
}
static int F_86 ( struct V_1 * V_2 , bool V_18 )
{
return F_21 ( V_2 , V_18 ?
V_221 : V_222 ) ;
}
static int F_87 ( struct V_1 * V_2 , bool V_223 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_137 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_138 ;
int V_66 ;
T_1 V_51 ;
if ( ! V_223 ) {
if ( V_22 -> V_13 )
V_39 -> V_224 = V_22 -> V_13 - 1 ;
else
V_39 -> V_224 = 0 ;
if ( ! V_39 -> V_225 || V_39 -> V_226 ) {
V_51 = 1 << V_39 -> V_224 ;
} else {
V_51 = 0x1f ;
}
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_227 ) ,
( V_228 * ) & V_39 -> V_224 ,
sizeof( V_83 ) , V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
F_88 ( V_2 ,
V_229 ,
V_51 ) ;
}
return F_83 ( V_2 , ! V_223 ) ;
}
static V_83 F_89 ( struct V_1 * V_2 , T_1 V_161 )
{
V_83 V_12 ;
struct V_156 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_157 ;
for ( V_12 = 0 ; V_12 < V_22 -> V_13 ; V_12 ++ ) {
if ( V_22 -> V_14 [ V_12 ] . V_161 >= V_161 )
break;
}
return V_12 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_34 * V_230 ,
struct V_34 * V_231 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_156 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_157 ;
int V_66 ;
if ( V_230 -> V_161 > 0 && V_231 -> V_161 == 0 ) {
F_79 ( V_2 , false ) ;
V_66 = F_91 ( V_2 , V_232 ,
V_233 ) ;
if ( V_66 )
return V_66 ;
if ( V_39 -> V_226 )
V_39 -> V_234 = V_22 -> V_13 - 1 ;
else
V_39 -> V_234 = F_89 ( V_2 , V_230 -> V_161 ) ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_235 ) ,
( V_83 * ) & V_39 -> V_234 ,
sizeof( V_83 ) ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
if ( V_39 -> V_226 )
F_88 ( V_2 ,
V_236 ,
( 1 << V_39 -> V_234 ) ) ;
F_84 ( V_2 , true ) ;
} else if ( V_230 -> V_161 == 0 && V_231 -> V_161 > 0 ) {
F_84 ( V_2 , false ) ;
V_66 = F_91 ( V_2 , V_232 ,
V_237 ) ;
if ( V_66 )
return V_66 ;
F_79 ( V_2 , true ) ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , bool V_223 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_6 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_171 ;
int V_66 ;
if ( ! V_223 ) {
if ( V_39 -> V_226 )
V_39 -> V_238 = V_22 -> V_13 - 1 ;
else
V_39 -> V_238 = 0 ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_239 ) ,
( V_83 * ) & V_39 -> V_238 ,
sizeof( V_83 ) ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
if ( V_39 -> V_226 )
F_88 ( V_2 ,
V_240 ,
( 1 << V_39 -> V_238 ) ) ;
}
return F_85 ( V_2 , ! V_223 ) ;
}
static V_83 F_93 ( struct V_1 * V_2 )
{
V_83 V_12 ;
struct V_6 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_179 ;
for ( V_12 = 0 ; V_12 < V_22 -> V_13 ; V_12 ++ ) {
if ( V_22 -> V_14 [ V_12 ] . V_126 >= 0 )
break;
}
if ( V_12 >= V_22 -> V_13 )
V_12 = V_22 -> V_13 - 1 ;
return V_12 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_83 V_189 ;
if ( ! V_39 -> V_226 ) {
V_189 = F_93 ( V_2 ) ;
if ( V_189 != V_39 -> V_189 ) {
V_39 -> V_189 = V_189 ;
F_88 ( V_2 ,
V_241 ,
( 1 << V_39 -> V_189 ) ) ;
}
}
}
static int F_95 ( struct V_1 * V_2 , bool V_223 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_6 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_179 ;
int V_66 ;
if ( ! V_223 ) {
if ( V_39 -> V_226 )
V_39 -> V_189 = V_22 -> V_13 - 1 ;
else
V_39 -> V_189 = F_93 ( V_2 ) ;
V_66 = F_26 ( V_2 ,
V_39 -> V_77 +
F_24 ( V_81 , V_242 ) ,
( V_83 * ) & V_39 -> V_189 ,
sizeof( V_83 ) ,
V_39 -> V_76 ) ;
if ( V_66 )
return V_66 ;
if ( V_39 -> V_226 )
F_88 ( V_2 ,
V_241 ,
( 1 << V_39 -> V_189 ) ) ;
}
return F_86 ( V_2 , ! V_223 ) ;
}
static void F_80 ( struct V_1 * V_2 , bool V_223 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 ;
if ( V_39 -> V_211 == V_223 )
return;
V_39 -> V_211 = V_223 ;
if ( V_223 ) {
if ( V_39 -> V_243 ) {
V_66 = F_91 ( V_2 , V_244 ,
V_233 ) ;
V_66 = F_96 ( V_2 , V_244 ,
V_245 ) ;
}
F_87 ( V_2 , V_223 ) ;
if ( V_39 -> V_243 )
F_21 ( V_2 , V_246 ) ;
} else {
if ( V_39 -> V_243 ) {
F_21 ( V_2 , V_247 ) ;
V_66 = F_96 ( V_2 , V_244 ,
V_248 ) ;
V_66 = F_91 ( V_2 , V_244 ,
V_237 ) ;
}
F_87 ( V_2 , V_223 ) ;
}
}
static void F_79 ( struct V_1 * V_2 , bool V_223 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 ;
if ( V_39 -> V_212 == V_223 )
return;
V_39 -> V_212 = V_223 ;
if ( V_223 ) {
if ( V_39 -> V_249 ) {
V_66 = F_96 ( V_2 , V_232 ,
V_245 ) ;
F_21 ( V_2 , V_250 ) ;
}
} else {
if ( V_39 -> V_249 ) {
F_21 ( V_2 , V_251 ) ;
V_66 = F_96 ( V_2 , V_232 ,
V_248 ) ;
}
}
}
static void F_78 ( struct V_1 * V_2 , bool V_223 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
if ( V_39 -> V_213 == V_223 )
return;
V_39 -> V_213 = V_223 ;
if ( V_223 ) {
F_92 ( V_2 , true ) ;
if ( V_39 -> V_252 )
F_21 ( V_2 , V_253 ) ;
} else {
if ( V_39 -> V_252 )
F_21 ( V_2 , V_254 ) ;
F_92 ( V_2 , false ) ;
}
}
static void F_77 ( struct V_1 * V_2 , bool V_223 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
if ( V_39 -> V_214 == V_223 )
return;
if ( V_2 -> V_118 == V_119 || V_2 -> V_118 == V_120 )
return;
V_39 -> V_214 = V_223 ;
if ( V_223 ) {
F_95 ( V_2 , true ) ;
if ( V_39 -> V_255 )
F_21 ( V_2 , V_256 ) ;
} else {
if ( V_39 -> V_255 )
F_21 ( V_2 , V_257 ) ;
F_95 ( V_2 , false ) ;
}
}
static void F_97 ( struct V_1 * V_2 ,
struct V_34 * V_258 )
{
struct V_33 * V_190 = F_7 ( V_258 ) ;
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_22 && V_22 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_39 -> V_125 ; V_12 ++ ) {
if ( ( V_22 -> V_14 [ V_12 ] . V_126 >= V_190 -> V_259 [ 0 ] . V_90 ) ||
( V_12 == ( V_39 -> V_125 - 1 ) ) ) {
V_39 -> V_260 = V_12 ;
break;
}
}
for ( V_12 = V_39 -> V_125 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_22 -> V_14 [ V_12 ] . V_126 <= V_190 -> V_259 [ V_190 -> V_261 - 1 ] . V_90 )
break;
}
V_39 -> V_262 = V_12 ;
if ( V_39 -> V_260 > V_39 -> V_262 ) {
if ( ( V_190 -> V_259 [ 0 ] . V_90 - V_22 -> V_14 [ V_39 -> V_262 ] . V_126 ) >
( V_22 -> V_14 [ V_39 -> V_260 ] . V_126 - V_190 -> V_259 [ V_190 -> V_261 - 1 ] . V_90 ) )
V_39 -> V_262 = V_39 -> V_260 ;
else
V_39 -> V_260 = V_39 -> V_262 ;
}
} else {
struct V_20 * V_22 =
& V_39 -> V_100 . V_21 ;
for ( V_12 = 0 ; V_12 < ( int ) V_39 -> V_125 ; V_12 ++ ) {
if ( V_22 -> V_14 [ V_12 ] . V_27 >= V_190 -> V_259 [ 0 ] . V_90 ||
V_12 == ( int ) ( V_39 -> V_125 - 1 ) ) {
V_39 -> V_260 = V_12 ;
break;
}
}
for ( V_12 = V_39 -> V_125 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_22 -> V_14 [ V_12 ] . V_27 <=
V_190 -> V_259 [ V_190 -> V_261 - 1 ] . V_90 )
break;
}
V_39 -> V_262 = V_12 ;
if ( V_39 -> V_260 > V_39 -> V_262 ) {
if ( ( V_190 -> V_259 [ 0 ] . V_90 -
V_22 -> V_14 [ V_39 -> V_262 ] . V_27 ) >
( V_22 -> V_14 [ V_39 -> V_260 ] . V_27 -
V_190 -> V_259 [ V_190 -> V_261 - 1 ] . V_90 ) )
V_39 -> V_262 = V_39 -> V_260 ;
else
V_39 -> V_260 = V_39 -> V_262 ;
}
}
}
static int F_98 ( struct V_1 * V_2 ,
struct V_34 * V_258 )
{
struct V_33 * V_190 = F_7 ( V_258 ) ;
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 = 0 ;
V_83 V_263 ;
if ( V_39 -> V_136 ) {
V_263 = V_190 -> V_264 ?
V_39 -> V_94 [ V_39 -> V_87 ] . V_163 : 0 ;
V_66 = F_26 ( V_2 ,
( V_39 -> V_77 +
F_24 ( V_81 , V_130 ) +
( V_39 -> V_87 * sizeof( V_131 ) ) +
F_24 ( V_131 , V_163 ) ) ,
& V_263 ,
sizeof( V_83 ) , V_39 -> V_76 ) ;
}
return V_66 ;
}
static int F_76 ( struct V_1 * V_2 ,
bool V_18 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
int V_66 = 0 ;
if ( V_18 ) {
if ( V_39 -> V_265 && ! V_39 -> V_266 ) {
V_66 = F_21 ( V_2 , V_267 ) ;
if ( V_66 == 0 )
V_39 -> V_266 = true ;
}
} else {
if ( V_39 -> V_265 && V_39 -> V_266 ) {
V_66 = F_21 ( V_2 , V_268 ) ;
if ( V_66 == 0 )
V_39 -> V_266 = false ;
}
}
return V_66 ;
}
static int F_99 ( struct V_1 * V_2 ,
enum V_269 V_270 )
{
int V_66 ;
if ( V_270 == V_271 ) {
V_66 = F_100 ( V_2 ) ;
if ( V_66 )
return V_66 ;
} else if ( V_270 == V_272 ) {
V_66 = F_47 ( V_2 ) ;
if ( V_66 )
return V_66 ;
} else if ( V_270 == V_273 ) {
V_66 = F_48 ( V_2 ) ;
if ( V_66 )
return V_66 ;
}
V_2 -> V_8 . V_9 . V_274 = V_270 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_34 V_194 = * V_2 -> V_8 . V_9 . V_194 ;
struct V_34 * V_190 = & V_194 ;
F_64 ( V_2 , V_190 ) ;
F_102 ( V_2 ,
& V_39 -> V_193 ,
& V_39 -> V_191 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_34 * V_190 = & V_39 -> V_193 ;
struct V_34 * V_275 = & V_39 -> V_191 ;
int V_66 ;
if ( V_39 -> V_195 ) {
V_66 = F_66 ( V_2 , V_2 -> V_8 . V_9 . V_276 ) ;
if ( V_66 ) {
F_67 ( L_1 ) ;
return V_66 ;
}
}
if ( V_2 -> V_118 == V_119 || V_2 -> V_118 == V_120 ) {
if ( V_39 -> V_277 ) {
F_97 ( V_2 , V_190 ) ;
F_98 ( V_2 , V_190 ) ;
V_66 = F_104 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_17 ) ;
return V_66 ;
}
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
F_46 ( V_2 ) ;
F_107 ( V_2 ) ;
F_53 ( V_2 ) ;
F_108 ( V_2 , V_190 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_46 ( V_2 ) ;
F_48 ( V_2 ) ;
V_66 = F_90 ( V_2 , V_190 , V_275 ) ;
if ( V_66 ) {
F_67 ( L_18 ) ;
return V_66 ;
}
F_50 ( V_2 ) ;
if ( V_2 -> V_118 == V_120 )
F_76 ( V_2 , true ) ;
}
} else {
if ( V_39 -> V_277 ) {
F_97 ( V_2 , V_190 ) ;
F_98 ( V_2 , V_190 ) ;
V_66 = F_104 ( V_2 ) ;
if ( V_66 ) {
F_67 ( L_17 ) ;
return V_66 ;
}
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
F_45 ( V_2 , true ) ;
F_53 ( V_2 ) ;
F_108 ( V_2 , V_190 ) ;
F_45 ( V_2 , false ) ;
F_49 ( V_2 ) ;
V_66 = F_90 ( V_2 , V_190 , V_275 ) ;
if ( V_66 ) {
F_67 ( L_18 ) ;
return V_66 ;
}
F_94 ( V_2 ) ;
F_50 ( V_2 ) ;
F_76 ( V_2 , true ) ;
}
}
return 0 ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_34 * V_190 = & V_39 -> V_193 ;
F_63 ( V_2 , V_190 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
F_3 ( V_2 , true ) ;
F_82 ( V_2 ) ;
F_81 ( V_2 ) ;
}
static void F_111 ( struct V_1 * V_2 ,
struct V_278 * V_22 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
if ( V_39 -> V_100 . V_21 . V_29 > 0 ) {
int V_279 = V_39 -> V_100 . V_21 . V_29 - 1 ;
V_22 -> V_90 =
V_39 -> V_100 . V_21 . V_14 [ V_279 ] . V_27 ;
V_22 -> V_280 =
F_35 ( V_2 ,
V_39 -> V_100 . V_21 . V_14 [ V_279 ] . V_5 ) ;
}
V_22 -> V_281 = V_39 -> V_100 . V_282 [ 0 ] ;
}
static void F_112 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_137 * V_283 =
& V_2 -> V_8 . V_9 . V_10 . V_138 ;
struct V_156 * V_284 =
& V_2 -> V_8 . V_9 . V_10 . V_157 ;
struct V_6 * V_285 =
& V_2 -> V_8 . V_9 . V_10 . V_171 ;
struct V_6 * V_286 =
& V_2 -> V_8 . V_9 . V_10 . V_179 ;
if ( V_283 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_283 -> V_13 ; V_12 ++ )
V_283 -> V_14 [ V_12 ] . V_15 =
F_34 ( V_2 ,
V_283 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_284 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_284 -> V_13 ; V_12 ++ )
V_284 -> V_14 [ V_12 ] . V_15 =
F_34 ( V_2 ,
V_284 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_285 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_285 -> V_13 ; V_12 ++ )
V_285 -> V_14 [ V_12 ] . V_15 =
F_34 ( V_2 ,
V_285 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_286 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_286 -> V_13 ; V_12 ++ )
V_286 -> V_14 [ V_12 ] . V_15 =
F_34 ( V_2 ,
V_286 -> V_14 [ V_12 ] . V_15 ) ;
}
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_39 -> V_127 . V_90 = V_39 -> V_100 . V_287 ;
V_39 -> V_127 . V_288 = V_39 -> V_100 . V_289 ;
V_39 -> V_127 . V_290 = 0 ;
V_39 -> V_127 . V_291 = 0 ;
V_39 -> V_127 . V_292 = 1 ;
V_39 -> V_127 . V_293 = 0 ;
V_39 -> V_127 . V_294 = 0 ;
V_39 -> V_127 . V_295 = 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_66 ;
T_1 V_296 , V_12 ;
V_66 = F_114 ( V_2 , & V_296 ) ;
if ( V_66 )
return V_66 ;
for ( V_12 = V_132 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_296 & ( 1 << V_12 ) )
break;
}
if ( V_2 -> V_118 == V_119 || V_2 -> V_118 == V_120 )
return F_88 ( V_2 , V_297 , V_12 ) ;
else
return F_115 ( V_2 , V_12 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_66 ;
T_1 V_296 , V_12 ;
V_66 = F_114 ( V_2 , & V_296 ) ;
if ( V_66 )
return V_66 ;
for ( V_12 = 0 ; V_12 < V_132 ; V_12 ++ ) {
if ( V_296 & ( 1 << V_12 ) )
break;
}
if ( V_2 -> V_118 == V_119 || V_2 -> V_118 == V_120 )
return F_88 ( V_2 , V_297 , V_12 ) ;
else
return F_115 ( V_2 , V_12 ) ;
}
static V_83 F_116 ( struct V_1 * V_2 ,
T_1 V_90 , T_1 V_298 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_12 ;
T_1 V_299 ;
T_1 V_300 = ( V_298 > V_301 ) ?
V_298 : V_301 ;
if ( V_90 < V_300 )
return 0 ;
if ( ! V_39 -> V_302 )
return 0 ;
for ( V_12 = V_303 ; V_12 > 0 ; V_12 -- ) {
V_299 = V_90 / F_4 ( V_12 ) ;
if ( V_299 >= V_300 )
break;
}
return ( V_83 ) V_12 ;
}
static int F_117 ( struct V_1 * V_2 , int * V_304 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_6 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
int V_12 ;
if ( V_22 && V_22 -> V_13 ) {
for ( V_12 = V_22 -> V_13 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_39 -> V_140 &&
( F_34 ( V_2 , V_22 -> V_14 [ V_12 ] . V_15 ) <=
V_39 -> V_140 ) ) {
* V_304 = V_12 ;
return 0 ;
}
}
} else {
struct V_20 * V_22 =
& V_39 -> V_100 . V_21 ;
for ( V_12 = V_22 -> V_29 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_39 -> V_140 &&
( F_35 ( V_2 , V_22 -> V_14 [ V_12 ] . V_5 ) <=
V_39 -> V_140 ) ) {
* V_304 = V_12 ;
return 0 ;
}
}
}
* V_304 = 0 ;
return 0 ;
}
static void F_102 ( struct V_1 * V_2 ,
struct V_34 * V_258 ,
struct V_34 * V_305 )
{
struct V_33 * V_36 = F_7 ( V_258 ) ;
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_306 = 10000 ;
T_1 V_90 , V_281 = 0 ;
int V_12 , V_304 ;
bool V_307 ;
struct V_6 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
T_1 V_308 = 0 ;
struct V_278 * V_309 =
& V_2 -> V_8 . V_9 . V_10 . V_310 ;
if ( V_258 -> V_311 ) {
V_258 -> V_161 = V_2 -> V_8 . V_9 . V_312 [ V_2 -> V_8 . V_9 . V_159 ] . V_161 ;
V_258 -> V_313 = V_2 -> V_8 . V_9 . V_312 [ V_2 -> V_8 . V_9 . V_159 ] . V_313 ;
} else {
V_258 -> V_161 = 0 ;
V_258 -> V_313 = 0 ;
}
V_281 = V_309 -> V_281 ;
V_90 = V_306 ;
if ( V_39 -> V_226 ) {
V_308 = ( V_309 -> V_90 * 75 ) / 100 ;
for ( V_12 = V_22 -> V_13 - 1 ; V_12 >= 0 ; V_12 ++ ) {
if ( V_308 >= V_22 -> V_14 [ V_12 ] . V_126 ) {
V_308 = V_22 -> V_14 [ V_12 ] . V_126 ;
break;
}
}
if ( V_12 > 0 )
V_308 = V_22 -> V_14 [ 0 ] . V_126 ;
V_90 = V_308 ;
}
if ( V_258 -> V_311 ) {
if ( V_90 < V_2 -> V_8 . V_9 . V_312 [ V_2 -> V_8 . V_9 . V_159 ] . V_90 )
V_90 = V_2 -> V_8 . V_9 . V_312 [ V_2 -> V_8 . V_9 . V_159 ] . V_90 ;
}
V_36 -> V_264 = true ;
for ( V_12 = 0 ; V_12 < V_36 -> V_261 ; V_12 ++ ) {
if ( V_36 -> V_259 [ V_12 ] . V_90 < V_90 )
V_36 -> V_259 [ V_12 ] . V_90 = V_90 ;
}
if ( V_22 && V_22 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_36 -> V_261 ; V_12 ++ ) {
if ( V_39 -> V_140 &&
( V_39 -> V_140 <
F_34 ( V_2 , V_36 -> V_259 [ V_12 ] . V_288 ) ) ) {
F_117 ( V_2 , & V_304 ) ;
V_36 -> V_259 [ V_12 ] . V_90 = V_22 -> V_14 [ V_304 ] . V_126 ;
}
}
} else {
struct V_20 * V_22 =
& V_39 -> V_100 . V_21 ;
for ( V_12 = 0 ; V_12 < V_36 -> V_261 ; V_12 ++ ) {
if ( V_39 -> V_140 &&
( V_39 -> V_140 <
F_34 ( V_2 , V_36 -> V_259 [ V_12 ] . V_288 ) ) ) {
F_117 ( V_2 , & V_304 ) ;
V_36 -> V_259 [ V_12 ] . V_90 = V_22 -> V_14 [ V_304 ] . V_27 ;
}
}
}
if ( V_39 -> V_226 ) {
for ( V_12 = 0 ; V_12 < V_36 -> V_261 ; V_12 ++ ) {
V_36 -> V_259 [ V_12 ] . V_90 = V_308 ;
}
}
V_39 -> V_314 = V_258 -> V_145 || V_258 -> V_143 ||
V_258 -> V_161 || V_258 -> V_313 ;
if ( ( V_258 -> V_315 & V_316 ) ==
V_317 )
V_39 -> V_318 = true ;
else
V_39 -> V_318 = false ;
if ( V_2 -> V_118 == V_119 || V_2 -> V_118 == V_120 ) {
V_36 -> V_319 = 0x1 ;
V_36 -> V_320 = 0x0 ;
V_36 -> V_321 = 0x1 ;
V_36 -> V_322 = 0x0 ;
} else {
V_36 -> V_319 = 0x3 ;
V_36 -> V_320 = 0x0 ;
V_36 -> V_321 = 0x3 ;
V_36 -> V_322 = 0x0 ;
if ( V_39 -> V_100 . V_323 ) {
V_307 = ( V_281 >= V_39 -> V_100 . V_282 [ 3 ] ) ||
V_39 -> V_314 || ( V_2 -> V_8 . V_9 . V_324 >= 3 ) ||
V_39 -> V_325 ;
V_36 -> V_319 = V_307 ? 0x2 : 0x3 ;
V_36 -> V_320 = 0x2 ;
V_36 -> V_321 = V_307 ? 0x2 : 0x3 ;
V_36 -> V_322 = 0x2 ;
}
}
}
static void F_118 ( struct V_1 * V_2 ,
T_1 V_89 , bool V_18 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_39 -> V_94 [ V_89 ] . V_326 = V_18 ? 1 : 0 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_327 = 10000 ;
T_1 V_12 ;
if ( V_39 -> V_260 > V_39 -> V_262 )
return - V_46 ;
for ( V_12 = V_39 -> V_260 ; V_12 <= V_39 -> V_262 ; V_12 ++ ) {
V_39 -> V_94 [ V_12 ] . V_328 =
F_116 ( V_2 ,
F_119 ( V_39 -> V_94 [ V_12 ] . V_97 ) ,
V_327 ) ;
}
return 0 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_12 ;
bool V_307 ;
struct V_278 * V_309 =
& V_2 -> V_8 . V_9 . V_10 . V_310 ;
T_1 V_281 = V_309 -> V_281 ;
if ( V_39 -> V_260 > V_39 -> V_262 )
return - V_46 ;
if ( V_2 -> V_118 == V_119 || V_2 -> V_118 == V_120 ) {
for ( V_12 = V_39 -> V_260 ; V_12 <= V_39 -> V_262 ; V_12 ++ ) {
V_39 -> V_94 [ V_12 ] . V_329 = 1 ;
V_39 -> V_94 [ V_12 ] . V_330 = 0 ;
V_39 -> V_94 [ V_12 ] . V_331 = 0 ;
}
if ( ! V_39 -> V_100 . V_323 )
return 0 ;
V_307 = ( ( V_281 >= V_39 -> V_100 . V_282 [ 3 ] ) ||
( V_2 -> V_8 . V_9 . V_324 >= 3 ) || V_39 -> V_314 ) ;
if ( V_307 ) {
for ( V_12 = V_39 -> V_260 ; V_12 <= V_39 -> V_262 ; V_12 ++ )
V_39 -> V_94 [ V_12 ] . V_329 = 0 ;
} else {
if ( V_39 -> V_318 )
V_39 -> V_94 [ 0 ] . V_330 = 1 ;
V_39 -> V_94 [ 1 ] . V_329 = 0 ;
V_39 -> V_94 [ 2 ] . V_329 = 0 ;
V_39 -> V_94 [ 3 ] . V_329 = 0 ;
V_39 -> V_94 [ 4 ] . V_329 = 0 ;
}
} else {
for ( V_12 = V_39 -> V_260 ; V_12 <= V_39 -> V_262 ; V_12 ++ ) {
V_39 -> V_94 [ V_12 ] . V_329 = 1 ;
V_39 -> V_94 [ V_12 ] . V_330 = 0 ;
V_39 -> V_94 [ V_12 ] . V_331 = 0 ;
}
if ( V_39 -> V_100 . V_323 && V_39 -> V_318 ) {
V_39 -> V_94 [ V_39 -> V_260 ] . V_331 = 0x28 ;
V_39 -> V_94 [ V_39 -> V_260 ] . V_329 = 0 ;
if ( V_39 -> V_260 != V_39 -> V_262 )
V_39 -> V_94 [ V_39 -> V_260 ] . V_330 = 1 ;
}
}
return 0 ;
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_12 ;
if ( V_39 -> V_260 > V_39 -> V_262 )
return - V_46 ;
for ( V_12 = V_39 -> V_260 ; V_12 <= V_39 -> V_262 ; V_12 ++ )
V_39 -> V_94 [ V_12 ] . V_332 = ( V_12 == V_39 -> V_262 ) ? 1 : 0 ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_22 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_22 && V_22 -> V_13 ) {
T_1 V_5 ;
V_39 -> V_125 = 0 ;
for ( V_12 = 0 ; V_12 < V_22 -> V_13 ; V_12 ++ ) {
if ( V_39 -> V_140 &&
( V_39 -> V_140 <
F_34 ( V_2 , V_22 -> V_14 [ V_12 ] . V_15 ) ) )
break;
F_31 ( V_2 , V_12 , V_22 -> V_14 [ V_12 ] . V_126 ) ;
V_5 = F_2 ( V_2 ,
& V_39 -> V_100 . V_4 ,
V_22 -> V_14 [ V_12 ] . V_15 ) ;
F_36 ( V_2 , V_12 , V_5 ) ;
F_37 ( V_2 , V_12 , V_39 -> V_105 [ V_12 ] ) ;
F_118 ( V_2 , V_12 , true ) ;
V_39 -> V_125 ++ ;
}
} else {
struct V_20 * V_22 =
& V_39 -> V_100 . V_21 ;
V_39 -> V_125 = 0 ;
for ( V_12 = 0 ; V_12 < V_22 -> V_29 ; V_12 ++ ) {
if ( V_39 -> V_140 &&
V_39 -> V_140 <
F_35 ( V_2 , V_22 -> V_14 [ V_12 ] . V_5 ) )
break;
F_31 ( V_2 , V_12 , V_22 -> V_14 [ V_12 ] . V_27 ) ;
F_36 ( V_2 , V_12 , V_22 -> V_14 [ V_12 ] . V_5 ) ;
F_37 ( V_2 , V_12 , V_39 -> V_105 [ V_12 ] ) ;
F_118 ( V_2 , V_12 , true ) ;
V_39 -> V_125 ++ ;
}
}
for ( V_12 = 0 ; V_12 < V_132 ; V_12 ++ )
F_39 ( V_2 , V_12 , false ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_12 ;
for ( V_12 = 0 ; V_12 < V_132 ; V_12 ++ ) {
if ( V_12 >= V_39 -> V_260 && V_12 <= V_39 -> V_262 )
F_39 ( V_2 , V_12 , true ) ;
}
}
static int F_115 ( struct V_1 * V_2 , T_1 V_270 )
{
T_1 V_333 = ( 1 << V_270 ) ;
return F_88 ( V_2 ,
V_334 ,
V_333 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_12 , V_333 = 0 ;
for ( V_12 = V_39 -> V_260 ; V_12 <= V_39 -> V_262 ; V_12 ++ )
V_333 |= ( 1 << V_12 ) ;
return F_88 ( V_2 ,
V_334 ,
V_333 ) ;
}
static void F_108 ( struct V_1 * V_2 ,
struct V_34 * V_258 )
{
struct V_33 * V_190 = F_7 ( V_258 ) ;
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_335 ;
if ( V_2 -> V_118 == V_119 || V_2 -> V_118 == V_120 )
return;
if ( V_39 -> V_100 . V_323 ) {
V_335 = F_10 ( V_336 ) ;
V_335 &= ~ ( V_337 |
V_338 |
V_339 |
V_340 ) ;
V_335 |= ( V_190 -> V_319 << V_341 ) |
( V_190 -> V_320 << V_342 ) |
( V_190 -> V_321 << V_343 ) |
( V_190 -> V_322 << V_344 ) ;
F_13 ( V_336 , V_335 ) ;
}
}
static int F_72 ( struct V_1 * V_2 ,
int V_345 , int V_346 )
{
int V_347 = 0 * 1000 ;
int V_348 = 255 * 1000 ;
T_1 V_72 ;
if ( V_347 < V_345 )
V_347 = V_345 ;
if ( V_348 > V_346 )
V_348 = V_346 ;
if ( V_348 < V_347 ) {
F_67 ( L_19 , V_347 , V_348 ) ;
return - V_46 ;
}
V_72 = F_10 ( V_349 ) ;
V_72 &= ~ ( V_350 |
V_351 ) ;
V_72 |= ( ( 49 + ( V_348 / 1000 ) ) << V_352 ) |
( ( 49 + ( V_347 / 1000 ) ) << V_353 ) ;
F_13 ( V_349 , V_72 ) ;
V_2 -> V_8 . V_9 . V_203 . V_345 = V_347 ;
V_2 -> V_8 . V_9 . V_203 . V_346 = V_348 ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_354 * V_355 = & V_2 -> V_355 ;
int V_89 = F_121 ( V_356 , V_357 ) ;
union V_358 * V_358 ;
V_83 V_359 , V_360 ;
T_3 V_361 ;
int V_12 ;
if ( F_122 ( V_355 -> V_362 , V_89 , NULL ,
& V_359 , & V_360 , & V_361 ) ) {
V_358 = (union V_358 * ) ( V_355 -> V_362 -> V_363 +
V_361 ) ;
if ( V_360 != 8 ) {
F_67 ( L_20 , V_359 , V_360 ) ;
return - V_46 ;
}
V_39 -> V_100 . V_287 = F_123 ( V_358 -> V_364 . V_365 ) ;
V_39 -> V_100 . V_366 = F_123 ( V_358 -> V_364 . V_367 ) ;
V_39 -> V_100 . V_289 =
F_124 ( V_358 -> V_364 . V_368 ) ;
if ( V_358 -> V_364 . V_369 == 0 )
V_39 -> V_100 . V_370 = 203 ;
else
V_39 -> V_100 . V_370 = V_358 -> V_364 . V_369 ;
if ( V_358 -> V_364 . V_371 == 0 )
V_39 -> V_100 . V_372 = 5 ;
else
V_39 -> V_100 . V_372 = V_358 -> V_364 . V_371 ;
if ( V_39 -> V_100 . V_370 <= V_39 -> V_100 . V_372 ) {
F_67 ( L_21 ) ;
}
if ( F_123 ( V_358 -> V_364 . V_373 ) & ( 1 << 3 ) )
V_39 -> V_100 . V_323 = true ;
else
V_39 -> V_100 . V_323 = false ;
for ( V_12 = 0 ; V_12 < V_374 ; V_12 ++ ) {
V_39 -> V_100 . V_282 [ V_12 ] =
F_123 ( V_358 -> V_364 . V_375 [ V_12 ] ) ;
V_39 -> V_100 . V_376 [ V_12 ] =
F_123 ( V_358 -> V_364 . V_377 [ V_12 ] ) ;
}
if ( F_123 ( V_358 -> V_364 . V_378 ) &
V_379 )
V_39 -> V_136 = true ;
F_5 ( V_2 ,
& V_39 -> V_100 . V_21 ,
V_358 -> V_364 . V_380 ) ;
F_6 ( V_2 ,
& V_39 -> V_100 . V_4 ,
V_358 -> V_364 . V_380 ) ;
F_111 ( V_2 ,
& V_2 -> V_8 . V_9 . V_10 . V_310 ) ;
}
return 0 ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_33 * V_36 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
V_36 -> V_261 = 1 ;
V_36 -> V_259 [ 0 ] = V_39 -> V_127 ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_381 * V_382 ,
V_83 V_383 )
{
struct V_33 * V_36 = F_7 ( V_35 ) ;
V_35 -> V_384 = F_123 ( V_382 -> V_385 ) ;
V_35 -> V_315 = F_124 ( V_382 -> V_386 ) ;
V_35 -> V_387 = F_124 ( V_382 -> V_388 ) ;
if ( V_389 < V_383 ) {
V_35 -> V_143 = F_123 ( V_382 -> V_390 ) ;
V_35 -> V_145 = F_123 ( V_382 -> V_391 ) ;
} else {
V_35 -> V_143 = 0 ;
V_35 -> V_145 = 0 ;
}
if ( V_35 -> V_315 & V_392 ) {
V_2 -> V_8 . V_9 . V_197 = V_35 ;
F_125 ( V_2 , V_36 ) ;
}
if ( V_35 -> V_315 & V_393 )
V_2 -> V_8 . V_9 . V_394 = V_35 ;
}
static void F_127 ( struct V_1 * V_2 ,
struct V_34 * V_35 , int V_89 ,
union V_395 * V_396 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_33 * V_36 = F_7 ( V_35 ) ;
struct V_397 * V_398 = & V_36 -> V_259 [ V_89 ] ;
T_1 V_90 ;
V_90 = F_124 ( V_396 -> V_399 . V_400 ) ;
V_90 |= V_396 -> V_399 . V_401 << 16 ;
V_398 -> V_90 = V_90 ;
V_398 -> V_288 = V_396 -> V_399 . V_402 ;
V_36 -> V_261 = V_89 + 1 ;
if ( V_39 -> V_302 ) {
V_398 -> V_290 = 5 ;
V_398 -> V_291 = 5 ;
}
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_354 * V_355 = & V_2 -> V_355 ;
struct V_381 * V_382 ;
union V_403 * V_404 ;
int V_12 , V_30 , V_405 , V_406 , V_407 ;
union V_395 * V_396 ;
struct V_408 * V_409 ;
struct V_410 * V_411 ;
struct V_412 * V_413 ;
union V_414 * V_414 ;
int V_89 = F_121 ( V_356 , V_415 ) ;
T_3 V_361 ;
V_83 V_359 , V_360 ;
V_83 * V_416 ;
struct V_33 * V_36 ;
if ( ! F_122 ( V_355 -> V_362 , V_89 , NULL ,
& V_359 , & V_360 , & V_361 ) )
return - V_46 ;
V_414 = (union V_414 * ) ( V_355 -> V_362 -> V_363 + V_361 ) ;
F_129 ( V_2 ) ;
V_409 = (struct V_408 * )
( V_355 -> V_362 -> V_363 + V_361 +
F_124 ( V_414 -> V_417 . V_418 ) ) ;
V_411 = (struct V_410 * )
( V_355 -> V_362 -> V_363 + V_361 +
F_124 ( V_414 -> V_417 . V_419 ) ) ;
V_413 = (struct V_412 * )
( V_355 -> V_362 -> V_363 + V_361 +
F_124 ( V_414 -> V_417 . V_420 ) ) ;
V_2 -> V_8 . V_9 . V_36 = F_130 ( sizeof( struct V_34 ) *
V_409 -> V_421 , V_422 ) ;
if ( ! V_2 -> V_8 . V_9 . V_36 )
return - V_423 ;
V_416 = ( V_83 * ) V_409 -> V_424 ;
for ( V_12 = 0 ; V_12 < V_409 -> V_421 ; V_12 ++ ) {
V_83 * V_279 ;
V_404 = (union V_403 * ) V_416 ;
V_406 = V_404 -> V_425 . V_426 ;
V_382 = (struct V_381 * )
& V_413 -> V_427 [ V_406 ] ;
V_36 = F_130 ( sizeof( struct V_33 ) , V_422 ) ;
if ( V_36 == NULL ) {
F_131 ( V_2 -> V_8 . V_9 . V_36 ) ;
return - V_423 ;
}
V_2 -> V_8 . V_9 . V_36 [ V_12 ] . V_37 = V_36 ;
V_405 = 0 ;
V_279 = ( V_83 * ) & V_404 -> V_425 . V_428 [ 0 ] ;
for ( V_30 = 0 ; V_30 < V_404 -> V_425 . V_429 ; V_30 ++ ) {
V_407 = V_279 [ V_30 ] ;
if ( V_407 >= V_411 -> V_421 )
continue;
if ( V_405 >= V_25 )
break;
V_396 = (union V_395 * )
( ( V_83 * ) & V_411 -> V_430 [ 0 ] +
( V_407 * V_411 -> V_431 ) ) ;
F_127 ( V_2 ,
& V_2 -> V_8 . V_9 . V_36 [ V_12 ] , V_405 ,
V_396 ) ;
V_405 ++ ;
}
F_126 ( V_2 , & V_2 -> V_8 . V_9 . V_36 [ V_12 ] ,
V_382 ,
V_413 -> V_431 ) ;
V_416 += 2 + V_404 -> V_425 . V_429 ;
}
V_2 -> V_8 . V_9 . V_432 = V_409 -> V_421 ;
for ( V_12 = 0 ; V_12 < V_433 ; V_12 ++ ) {
T_1 V_90 ;
V_407 = V_2 -> V_8 . V_9 . V_312 [ V_12 ] . V_434 ;
V_396 = (union V_395 * )
& V_411 -> V_430 [ V_407 * V_411 -> V_431 ] ;
V_90 = F_124 ( V_396 -> V_399 . V_400 ) ;
V_90 |= V_396 -> V_399 . V_401 << 16 ;
V_2 -> V_8 . V_9 . V_312 [ V_12 ] . V_90 = V_90 ;
V_2 -> V_8 . V_9 . V_312 [ V_12 ] . V_281 = 0 ;
}
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
int V_66 , V_12 ;
V_39 = F_130 ( sizeof( struct V_38 ) , V_422 ) ;
if ( V_39 == NULL )
return - V_423 ;
V_2 -> V_8 . V_9 . V_40 = V_39 ;
V_66 = F_133 ( V_2 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_134 ( V_2 ) ;
if ( V_66 )
return V_66 ;
for ( V_12 = 0 ; V_12 < V_25 ; V_12 ++ )
V_39 -> V_105 [ V_12 ] = V_435 ;
V_39 -> V_76 = V_436 ;
V_39 -> V_265 = true ;
V_39 -> V_437 = true ;
V_39 -> V_68 = true ;
V_39 -> V_438 = false ;
if ( V_39 -> V_438 ) {
V_39 -> V_54 = true ;
V_39 -> V_57 = true ;
V_39 -> V_60 = true ;
V_39 -> V_63 = true ;
}
V_39 -> V_302 = true ;
V_39 -> V_196 = true ;
V_39 -> V_325 = false ;
if ( V_439 == 0 )
V_39 -> V_195 = false ;
else
V_39 -> V_195 = true ;
V_39 -> V_103 = 0 ;
V_39 -> V_123 = false ;
V_39 -> V_206 = false ;
V_39 -> V_243 = ( V_2 -> V_440 & V_441 ) ? true : false ;
V_39 -> V_225 = true ;
V_39 -> V_249 = ( V_2 -> V_440 & V_442 ) ? true : false ;
V_39 -> V_252 = ( V_2 -> V_440 & V_443 ) ? true : false ;
V_39 -> V_255 = ( V_2 -> V_440 & V_444 ) ? true : false ;
V_39 -> V_226 = false ;
V_66 = F_120 ( V_2 ) ;
if ( V_66 )
return V_66 ;
F_112 ( V_2 ) ;
F_113 ( V_2 ) ;
V_66 = F_128 ( V_2 ) ;
if ( V_66 )
return V_66 ;
V_39 -> V_277 = true ;
return 0 ;
}
static void
F_135 ( struct V_1 * V_2 ,
struct V_445 * V_446 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
T_1 V_447 =
( F_10 ( V_448 ) &
V_449 ) >>
V_450 ;
T_1 V_90 , V_72 ;
T_3 V_280 ;
if ( V_447 >= V_451 ) {
F_136 ( V_446 , L_22 , V_447 ) ;
} else {
V_90 = F_119 ( V_39 -> V_94 [ V_447 ] . V_97 ) ;
V_72 = ( F_10 ( V_452 ) &
V_453 ) >>
V_454 ;
V_280 = F_34 ( V_2 , ( T_3 ) V_72 ) ;
F_136 ( V_446 , L_23 , V_39 -> V_211 ? L_24 : L_25 ) ;
F_136 ( V_446 , L_26 , V_39 -> V_212 ? L_24 : L_25 ) ;
F_136 ( V_446 , L_27 ,
V_447 , V_90 , V_280 ) ;
}
}
static void
F_137 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
int V_12 ;
struct V_33 * V_36 = F_7 ( V_35 ) ;
F_138 ( V_35 -> V_315 , V_35 -> V_387 ) ;
F_139 ( V_35 -> V_384 ) ;
F_140 ( L_28 , V_35 -> V_143 , V_35 -> V_145 ) ;
for ( V_12 = 0 ; V_12 < V_36 -> V_261 ; V_12 ++ ) {
struct V_397 * V_398 = & V_36 -> V_259 [ V_12 ] ;
F_140 ( L_29 ,
V_12 , V_398 -> V_90 ,
F_34 ( V_2 , V_398 -> V_288 ) ) ;
}
F_141 ( V_2 , V_35 ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_8 . V_9 . V_432 ; V_12 ++ ) {
F_131 ( V_2 -> V_8 . V_9 . V_36 [ V_12 ] . V_37 ) ;
}
F_131 ( V_2 -> V_8 . V_9 . V_36 ) ;
F_131 ( V_2 -> V_8 . V_9 . V_40 ) ;
F_143 ( V_2 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
}
static T_1 F_145 ( struct V_1 * V_2 , bool V_455 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
struct V_33 * V_456 = F_7 ( & V_39 -> V_193 ) ;
if ( V_455 )
return V_456 -> V_259 [ 0 ] . V_90 ;
else
return V_456 -> V_259 [ V_456 -> V_261 - 1 ] . V_90 ;
}
static T_1 F_146 ( struct V_1 * V_2 , bool V_455 )
{
struct V_38 * V_39 = F_8 ( V_2 ) ;
return V_39 -> V_100 . V_366 ;
}
static int F_147 ( struct V_1 * V_2 )
{
T_1 V_299 ;
int V_457 = 0 ;
V_299 = F_10 ( 0xC0300E0C ) ;
if ( V_299 )
V_457 = ( V_299 / 8 ) - 49 ;
else
V_457 = 0 ;
V_457 = V_457 * 1000 ;
return V_457 ;
}
static int F_148 ( void * V_458 )
{
struct V_1 * V_2 = (struct V_1 * ) V_458 ;
F_149 ( V_2 ) ;
F_150 ( V_2 ) ;
return 0 ;
}
static int F_151 ( void * V_458 )
{
struct V_1 * V_2 = (struct V_1 * ) V_458 ;
F_77 ( V_2 , true ) ;
F_78 ( V_2 , true ) ;
F_79 ( V_2 , true ) ;
F_80 ( V_2 , true ) ;
return 0 ;
}
static int F_152 ( void * V_458 )
{
int V_66 ;
struct V_1 * V_2 = (struct V_1 * ) V_458 ;
V_66 = F_153 ( V_2 , 230 , & V_2 -> V_8 . V_9 . V_203 . V_198 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_153 ( V_2 , 231 , & V_2 -> V_8 . V_9 . V_203 . V_198 ) ;
if ( V_66 )
return V_66 ;
V_2 -> V_8 . V_9 . V_459 = V_460 ;
V_2 -> V_8 . V_9 . V_461 = V_460 ;
V_2 -> V_8 . V_9 . V_274 = V_273 ;
V_2 -> V_8 . V_462 = V_2 -> clock . V_462 ;
V_2 -> V_8 . V_463 = V_2 -> clock . V_463 ;
V_2 -> V_8 . V_464 = V_2 -> clock . V_462 ;
V_2 -> V_8 . V_465 = V_2 -> clock . V_463 ;
V_2 -> V_8 . V_200 = V_466 ;
if ( V_467 == 0 )
return 0 ;
F_154 ( & V_2 -> V_8 . V_9 . V_203 . V_468 , V_469 ) ;
F_155 ( & V_2 -> V_8 . V_470 ) ;
V_66 = F_132 ( V_2 ) ;
if ( V_66 )
goto V_471;
V_2 -> V_8 . V_9 . V_192 = V_2 -> V_8 . V_9 . V_194 = V_2 -> V_8 . V_9 . V_197 ;
if ( V_467 == 1 )
F_156 ( V_2 ) ;
V_66 = F_157 ( V_2 ) ;
if ( V_66 )
goto V_471;
F_158 ( & V_2 -> V_8 . V_470 ) ;
F_159 ( L_30 ) ;
return 0 ;
V_471:
F_142 ( V_2 ) ;
F_158 ( & V_2 -> V_8 . V_470 ) ;
F_67 ( L_31 ) ;
return V_66 ;
}
static int F_160 ( void * V_458 )
{
struct V_1 * V_2 = (struct V_1 * ) V_458 ;
F_155 ( & V_2 -> V_8 . V_470 ) ;
F_161 ( V_2 ) ;
F_142 ( V_2 ) ;
F_158 ( & V_2 -> V_8 . V_470 ) ;
return 0 ;
}
static int F_162 ( void * V_458 )
{
int V_66 ;
struct V_1 * V_2 = (struct V_1 * ) V_458 ;
F_155 ( & V_2 -> V_8 . V_470 ) ;
F_110 ( V_2 ) ;
V_66 = F_68 ( V_2 ) ;
if ( V_66 )
V_2 -> V_8 . V_472 = false ;
else
V_2 -> V_8 . V_472 = true ;
F_158 ( & V_2 -> V_8 . V_470 ) ;
return V_66 ;
}
static int F_163 ( void * V_458 )
{
struct V_1 * V_2 = (struct V_1 * ) V_458 ;
if ( V_2 -> V_8 . V_472 ) {
F_155 ( & V_2 -> V_8 . V_470 ) ;
F_74 ( V_2 ) ;
F_158 ( & V_2 -> V_8 . V_470 ) ;
}
return 0 ;
}
static int F_164 ( void * V_458 )
{
struct V_1 * V_2 = (struct V_1 * ) V_458 ;
if ( V_2 -> V_8 . V_472 ) {
F_155 ( & V_2 -> V_8 . V_470 ) ;
F_74 ( V_2 ) ;
V_2 -> V_8 . V_9 . V_192 = V_2 -> V_8 . V_9 . V_194 = V_2 -> V_8 . V_9 . V_197 ;
F_158 ( & V_2 -> V_8 . V_470 ) ;
}
return 0 ;
}
static int F_165 ( void * V_458 )
{
int V_66 ;
struct V_1 * V_2 = (struct V_1 * ) V_458 ;
if ( V_2 -> V_8 . V_472 ) {
F_155 ( & V_2 -> V_8 . V_470 ) ;
F_110 ( V_2 ) ;
V_66 = F_68 ( V_2 ) ;
if ( V_66 )
V_2 -> V_8 . V_472 = false ;
else
V_2 -> V_8 . V_472 = true ;
F_158 ( & V_2 -> V_8 . V_470 ) ;
if ( V_2 -> V_8 . V_472 )
F_166 ( V_2 ) ;
}
return 0 ;
}
static bool F_167 ( void * V_458 )
{
return true ;
}
static int F_168 ( void * V_458 )
{
return 0 ;
}
static void F_169 ( void * V_458 )
{
struct V_1 * V_2 = (struct V_1 * ) V_458 ;
F_170 ( V_2 -> V_473 , L_32 ) ;
F_170 ( V_2 -> V_473 , L_33 ,
F_11 ( V_55 ) ) ;
F_170 ( V_2 -> V_473 , L_34 ,
F_11 ( V_58 ) ) ;
F_170 ( V_2 -> V_473 , L_35 ,
F_11 ( V_61 ) ) ;
F_170 ( V_2 -> V_473 , L_36 ,
F_11 ( V_64 ) ) ;
F_170 ( V_2 -> V_473 , L_37 ,
F_10 ( V_474 ) ) ;
F_170 ( V_2 -> V_473 , L_38 ,
F_10 ( V_475 ) ) ;
F_170 ( V_2 -> V_473 , L_39 ,
F_10 ( V_476 ) ) ;
F_170 ( V_2 -> V_473 , L_40 ,
F_10 ( V_477 ) ) ;
F_170 ( V_2 -> V_473 , L_41 ,
F_10 ( V_478 ) ) ;
F_170 ( V_2 -> V_473 , L_42 ,
F_10 ( V_479 ) ) ;
F_170 ( V_2 -> V_473 , L_43 ,
F_10 ( V_480 ) ) ;
F_170 ( V_2 -> V_473 , L_44 ,
F_10 ( V_481 ) ) ;
F_170 ( V_2 -> V_473 , L_45 ,
F_10 ( V_482 ) ) ;
F_170 ( V_2 -> V_473 , L_46 ,
F_10 ( V_483 ) ) ;
F_170 ( V_2 -> V_473 , L_47 ,
F_10 ( V_484 ) ) ;
F_170 ( V_2 -> V_473 , L_48 ,
F_10 ( V_485 ) ) ;
F_170 ( V_2 -> V_473 , L_49 ,
F_10 ( V_88 ) ) ;
F_170 ( V_2 -> V_473 , L_50 ,
F_10 ( V_108 ) ) ;
F_170 ( V_2 -> V_473 , L_51 ,
F_10 ( V_111 ) ) ;
F_170 ( V_2 -> V_473 , L_52 ,
F_12 ( V_486 ) ) ;
F_170 ( V_2 -> V_473 , L_53 ,
F_12 ( V_487 ) ) ;
F_170 ( V_2 -> V_473 , L_54 ,
F_12 ( V_488 ) ) ;
F_170 ( V_2 -> V_473 , L_55 ,
F_12 ( V_489 ) ) ;
F_170 ( V_2 -> V_473 , L_56 ,
F_12 ( V_490 ) ) ;
F_170 ( V_2 -> V_473 , L_57 ,
F_12 ( V_491 ) ) ;
}
static int F_171 ( void * V_458 )
{
return 0 ;
}
static int F_172 ( struct V_1 * V_2 ,
struct V_492 * V_493 ,
unsigned type ,
enum V_494 V_459 )
{
T_1 V_495 ;
switch ( type ) {
case V_204 :
switch ( V_459 ) {
case V_496 :
V_495 = F_10 ( V_349 ) ;
V_495 &= ~ V_497 ;
F_13 ( V_349 , V_495 ) ;
break;
case V_498 :
V_495 = F_10 ( V_349 ) ;
V_495 |= V_497 ;
F_13 ( V_349 , V_495 ) ;
break;
default:
break;
}
break;
case V_205 :
switch ( V_459 ) {
case V_496 :
V_495 = F_10 ( V_349 ) ;
V_495 &= ~ V_499 ;
F_13 ( V_349 , V_495 ) ;
break;
case V_498 :
V_495 = F_10 ( V_349 ) ;
V_495 |= V_499 ;
F_13 ( V_349 , V_495 ) ;
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
static int F_173 ( struct V_1 * V_2 ,
struct V_492 * V_500 ,
struct V_501 * V_502 )
{
bool V_503 = false ;
if ( V_502 == NULL )
return - V_46 ;
switch ( V_502 -> V_504 ) {
case 230 :
F_174 ( L_58 ) ;
V_2 -> V_8 . V_9 . V_203 . V_505 = false ;
V_503 = true ;
break;
case 231 :
F_174 ( L_59 ) ;
V_2 -> V_8 . V_9 . V_203 . V_505 = true ;
V_503 = true ;
break;
default:
break;
}
if ( V_503 )
F_175 ( & V_2 -> V_8 . V_9 . V_203 . V_468 ) ;
return 0 ;
}
static int F_176 ( void * V_458 ,
enum V_506 V_459 )
{
return 0 ;
}
static int F_177 ( void * V_458 ,
enum V_507 V_459 )
{
return 0 ;
}
static void F_149 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_508 == NULL )
V_2 -> V_8 . V_508 = & V_509 ;
}
static void F_150 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_9 . V_203 . V_198 . V_510 = V_511 ;
V_2 -> V_8 . V_9 . V_203 . V_198 . V_508 = & V_512 ;
}
