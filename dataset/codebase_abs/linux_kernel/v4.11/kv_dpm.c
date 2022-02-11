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
V_2 -> V_66 . V_67 . V_68 -> V_69 ( V_2 ) ;
if ( V_18 ) {
V_65 = F_8 ( V_2 , V_70 ) ;
if ( V_65 ) {
V_2 -> V_66 . V_67 . V_68 -> V_71 ( V_2 ) ;
return V_65 ;
}
}
F_15 ( V_2 , V_18 ) ;
V_2 -> V_66 . V_67 . V_68 -> V_71 ( V_2 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 = 0 ;
if ( V_38 -> V_72 ) {
if ( V_18 ) {
V_65 = F_18 ( V_2 , V_73 ) ;
if ( V_65 )
V_38 -> V_74 = false ;
else
V_38 -> V_74 = true ;
} else if ( V_38 -> V_74 ) {
F_18 ( V_2 , V_75 ) ;
V_38 -> V_74 = false ;
}
}
return V_65 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_76 ;
int V_65 ;
V_65 = F_20 ( V_2 , V_77 +
F_21 ( V_78 , V_79 ) ,
& V_76 , V_38 -> V_80 ) ;
if ( V_65 == 0 )
V_38 -> V_81 = V_76 ;
V_65 = F_20 ( V_2 , V_77 +
F_21 ( V_78 , V_82 ) ,
& V_76 , V_38 -> V_80 ) ;
if ( V_65 == 0 )
V_38 -> V_83 = V_76 ;
return V_65 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_38 -> V_84 = 1 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_86 ) ,
& V_38 -> V_84 ,
sizeof( V_87 ) , V_38 -> V_80 ) ;
return V_65 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_38 -> V_88 = 1 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_89 ) ,
& V_38 -> V_88 ,
sizeof( V_87 ) , V_38 -> V_80 ) ;
return V_65 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_90 ) ,
& V_38 -> V_91 ,
sizeof( V_87 ) , V_38 -> V_80 ) ;
return V_65 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_12 ( V_92 , 0x3FFFC100 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_12 ( V_92 , 0 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
T_1 V_93 , T_1 V_94 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_95 V_96 ;
int V_65 ;
V_65 = F_29 ( V_2 , V_97 ,
V_94 , false , & V_96 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_98 [ V_93 ] . V_99 = ( V_87 ) V_96 . V_100 ;
V_38 -> V_98 [ V_93 ] . V_101 = F_30 ( V_94 ) ;
return 0 ;
}
static T_3 F_31 ( struct V_1 * V_2 ,
T_3 V_102 )
{
return 6200 - ( V_102 * 25 ) ;
}
static T_3 F_32 ( struct V_1 * V_2 ,
T_1 V_5 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_103 = F_1 ( V_2 ,
& V_38 -> V_104 . V_4 ,
V_5 ) ;
return F_31 ( V_2 , ( T_3 ) V_103 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_93 , T_1 V_105 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_98 [ V_93 ] . V_106 = ( V_87 ) V_38 -> V_107 ;
V_38 -> V_98 [ V_93 ] . V_108 =
F_30 ( F_32 ( V_2 , V_105 ) ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_93 , T_1 V_109 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_98 [ V_93 ] . V_110 = F_35 ( ( T_3 ) V_109 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 ,
T_1 V_93 , bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_98 [ V_93 ] . V_111 = V_18 ? 1 : 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
T_1 V_76 = F_9 ( V_112 ) ;
V_76 |= V_113 ;
F_12 ( V_112 , V_76 ) ;
F_38 ( V_2 , true ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_38 ( V_2 , false ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_114 = F_9 ( V_115 ) ;
V_114 &= ~ ( V_116 |
V_117 ) ;
V_114 |= V_118 ;
F_12 ( V_115 , V_114 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_1 V_114 = F_9 ( V_115 ) ;
V_114 |= ( V_116 |
V_117 ) ;
F_12 ( V_115 , V_114 ) ;
}
static int F_42 ( struct V_1 * V_2 , bool V_119 )
{
return F_18 ( V_2 , V_119 ?
V_120 : V_121 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
return F_44 ( V_2 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 )
return F_18 ( V_2 , V_125 ) ;
else
return F_46 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_126 = 0 ;
int V_65 = 0 ;
if ( V_38 -> V_127 ) {
V_126 = F_30 ( V_38 -> V_126 ) ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_128 ) ,
( V_87 * ) & V_126 ,
sizeof( T_1 ) , V_38 -> V_80 ) ;
}
return V_65 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = V_38 -> V_129 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_21 -> V_14 [ V_12 ] . V_130 == V_38 -> V_131 . V_94 )
break;
}
V_38 -> V_91 = ( V_87 ) V_12 ;
F_36 ( V_2 , V_12 , true ) ;
} else {
struct V_19 * V_21 =
& V_38 -> V_104 . V_20 ;
if ( V_21 -> V_28 == 0 )
return - V_45 ;
for ( V_12 = V_38 -> V_129 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_21 -> V_14 [ V_12 ] . V_26 == V_38 -> V_131 . V_94 )
break;
}
V_38 -> V_91 = ( V_87 ) V_12 ;
F_36 ( V_2 , V_12 , true ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_38 -> V_132 = 1 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_133 ) ,
& V_38 -> V_132 ,
sizeof( V_87 ) , V_38 -> V_80 ) ;
return V_65 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_134 ) ,
( V_87 * ) & V_38 -> V_98 ,
sizeof( V_135 ) * V_136 ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_137 ) ,
& V_38 -> V_129 ,
sizeof( V_87 ) , V_38 -> V_80 ) ;
return V_65 ;
}
static T_1 F_51 ( T_1 V_138 , T_1 V_139 )
{
return ( V_138 >= V_139 ) ? V_138 - V_139 : V_139 - V_138 ;
}
static T_1 F_52 ( struct V_1 * V_2 , T_1 V_130 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_48 ;
if ( V_38 -> V_140 ) {
if ( F_51 ( V_130 , 40000 ) < 200 )
V_48 = 3 ;
else if ( F_51 ( V_130 , 30000 ) < 200 )
V_48 = 2 ;
else if ( F_51 ( V_130 , 20000 ) < 200 )
V_48 = 7 ;
else if ( F_51 ( V_130 , 15000 ) < 200 )
V_48 = 6 ;
else if ( F_51 ( V_130 , 10000 ) < 200 )
V_48 = 8 ;
else
V_48 = 0 ;
} else {
V_48 = 0 ;
}
return V_48 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_141 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_142 ;
struct V_95 V_96 ;
int V_65 ;
T_1 V_12 ;
if ( V_21 == NULL || V_21 -> V_13 == 0 )
return 0 ;
V_38 -> V_143 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_38 -> V_144 &&
( V_38 -> V_144 < V_21 -> V_14 [ V_12 ] . V_15 ) )
break;
V_38 -> V_145 [ V_12 ] . V_146 = F_30 ( V_21 -> V_14 [ V_12 ] . V_147 ) ;
V_38 -> V_145 [ V_12 ] . V_148 = F_30 ( V_21 -> V_14 [ V_12 ] . V_149 ) ;
V_38 -> V_145 [ V_12 ] . V_108 = F_35 ( V_21 -> V_14 [ V_12 ] . V_15 ) ;
V_38 -> V_145 [ V_12 ] . V_150 =
( V_87 ) F_52 ( V_2 , V_21 -> V_14 [ V_12 ] . V_147 ) ;
V_38 -> V_145 [ V_12 ] . V_151 =
( V_87 ) F_52 ( V_2 , V_21 -> V_14 [ V_12 ] . V_149 ) ;
V_65 = F_29 ( V_2 , V_97 ,
V_21 -> V_14 [ V_12 ] . V_147 , false , & V_96 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_145 [ V_12 ] . V_152 = ( V_87 ) V_96 . V_100 ;
V_65 = F_29 ( V_2 , V_97 ,
V_21 -> V_14 [ V_12 ] . V_149 , false , & V_96 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_145 [ V_12 ] . V_153 = ( V_87 ) V_96 . V_100 ;
V_38 -> V_143 ++ ;
}
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_154 ) ,
( V_87 * ) & V_38 -> V_143 ,
sizeof( V_87 ) , V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_155 = 1 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_156 ) ,
& V_38 -> V_155 ,
sizeof( V_87 ) , V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_157 ) ,
( V_87 * ) & V_38 -> V_145 ,
sizeof( V_158 ) * V_159 ,
V_38 -> V_80 ) ;
return V_65 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
T_1 V_12 ;
struct V_160 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_161 ;
struct V_95 V_96 ;
if ( V_21 == NULL || V_21 -> V_13 == 0 )
return 0 ;
V_38 -> V_162 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_38 -> V_144 &&
V_38 -> V_144 < V_21 -> V_14 [ V_12 ] . V_15 )
break;
V_38 -> V_163 [ V_12 ] . V_164 = F_30 ( V_21 -> V_14 [ V_12 ] . V_165 ) ;
V_38 -> V_163 [ V_12 ] . V_166 = F_35 ( V_21 -> V_14 [ V_12 ] . V_15 ) ;
V_38 -> V_163 [ V_12 ] . V_167 =
( V_87 ) F_52 ( V_2 , V_21 -> V_14 [ V_12 ] . V_165 ) ;
V_65 = F_29 ( V_2 , V_97 ,
V_21 -> V_14 [ V_12 ] . V_165 , false , & V_96 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_163 [ V_12 ] . V_168 = ( V_87 ) V_96 . V_100 ;
V_38 -> V_162 ++ ;
}
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_169 ) ,
( V_87 * ) & V_38 -> V_162 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_170 = 1 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_171 ) ,
( V_87 * ) & V_38 -> V_170 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_172 ) ,
( V_87 * ) & V_38 -> V_163 ,
sizeof( V_173 ) * V_174 ,
V_38 -> V_80 ) ;
return V_65 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_175 ;
struct V_95 V_96 ;
int V_65 ;
T_1 V_12 ;
if ( V_21 == NULL || V_21 -> V_13 == 0 )
return 0 ;
V_38 -> V_176 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_38 -> V_144 &&
V_38 -> V_144 < V_21 -> V_14 [ V_12 ] . V_15 )
break;
V_38 -> V_177 [ V_12 ] . V_164 = F_30 ( V_21 -> V_14 [ V_12 ] . V_130 ) ;
V_38 -> V_177 [ V_12 ] . V_166 = F_35 ( V_21 -> V_14 [ V_12 ] . V_15 ) ;
V_38 -> V_177 [ V_12 ] . V_167 =
( V_87 ) F_52 ( V_2 , V_21 -> V_14 [ V_12 ] . V_130 ) ;
V_65 = F_29 ( V_2 , V_97 ,
V_21 -> V_14 [ V_12 ] . V_130 , false , & V_96 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_177 [ V_12 ] . V_168 = ( V_87 ) V_96 . V_100 ;
V_38 -> V_176 ++ ;
}
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_178 ) ,
( V_87 * ) & V_38 -> V_176 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_179 = 1 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_180 ) ,
( V_87 * ) & V_38 -> V_179 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_181 ) ,
( V_87 * ) & V_38 -> V_177 ,
sizeof( V_173 ) * V_182 ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
return V_65 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_183 ;
struct V_95 V_96 ;
int V_65 ;
T_1 V_12 ;
if ( V_21 == NULL || V_21 -> V_13 == 0 )
return 0 ;
V_38 -> V_184 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
V_38 -> V_185 [ V_12 ] . V_164 = F_30 ( V_21 -> V_14 [ V_12 ] . V_130 ) ;
V_38 -> V_185 [ V_12 ] . V_166 = F_35 ( V_21 -> V_14 [ V_12 ] . V_15 ) ;
V_65 = F_29 ( V_2 , V_97 ,
V_21 -> V_14 [ V_12 ] . V_130 , false , & V_96 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_185 [ V_12 ] . V_168 = ( V_87 ) V_96 . V_100 ;
V_38 -> V_184 ++ ;
}
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_186 ) ,
( V_87 * ) & V_38 -> V_184 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_187 = 1 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_188 ) ,
( V_87 * ) & V_38 -> V_187 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_189 ) ,
( V_87 * ) & V_38 -> V_185 ,
sizeof( V_173 ) * V_190 ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
return V_65 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_38 -> V_129 ; V_12 ++ ) {
if ( V_38 -> V_140 ) {
if ( F_51 ( V_21 -> V_14 [ V_12 ] . V_130 , 40000 ) < 200 )
V_38 -> V_98 [ V_12 ] . V_167 = 3 ;
else if ( F_51 ( V_21 -> V_14 [ V_12 ] . V_130 , 30000 ) < 200 )
V_38 -> V_98 [ V_12 ] . V_167 = 2 ;
else if ( F_51 ( V_21 -> V_14 [ V_12 ] . V_130 , 26600 ) < 200 )
V_38 -> V_98 [ V_12 ] . V_167 = 7 ;
else if ( F_51 ( V_21 -> V_14 [ V_12 ] . V_130 , 20000 ) < 200 )
V_38 -> V_98 [ V_12 ] . V_167 = 6 ;
else if ( F_51 ( V_21 -> V_14 [ V_12 ] . V_130 , 10000 ) < 200 )
V_38 -> V_98 [ V_12 ] . V_167 = 8 ;
else
V_38 -> V_98 [ V_12 ] . V_167 = 0 ;
} else {
V_38 -> V_98 [ V_12 ] . V_167 = 0 ;
}
}
} else {
struct V_19 * V_21 =
& V_38 -> V_104 . V_20 ;
for ( V_12 = 0 ; V_12 < V_38 -> V_129 ; V_12 ++ ) {
if ( V_38 -> V_140 ) {
if ( F_51 ( V_21 -> V_14 [ V_12 ] . V_26 , 40000 ) < 200 )
V_38 -> V_98 [ V_12 ] . V_167 = 3 ;
else if ( F_51 ( V_21 -> V_14 [ V_12 ] . V_26 , 30000 ) < 200 )
V_38 -> V_98 [ V_12 ] . V_167 = 2 ;
else if ( F_51 ( V_21 -> V_14 [ V_12 ] . V_26 , 26600 ) < 200 )
V_38 -> V_98 [ V_12 ] . V_167 = 7 ;
else if ( F_51 ( V_21 -> V_14 [ V_12 ] . V_26 , 20000 ) < 200 )
V_38 -> V_98 [ V_12 ] . V_167 = 6 ;
else if ( F_51 ( V_21 -> V_14 [ V_12 ] . V_26 , 10000 ) < 200 )
V_38 -> V_98 [ V_12 ] . V_167 = 8 ;
else
V_38 -> V_98 [ V_12 ] . V_167 = 0 ;
} else {
V_38 -> V_98 [ V_12 ] . V_167 = 0 ;
}
}
}
}
static int F_58 ( struct V_1 * V_2 , bool V_18 )
{
return F_18 ( V_2 , V_18 ?
V_191 : V_192 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_193 = 0xff ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_32 * V_194 = F_6 ( V_34 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_195 = * V_34 ;
V_38 -> V_196 = * V_194 ;
V_38 -> V_195 . V_36 = & V_38 -> V_196 ;
V_2 -> V_8 . V_9 . V_196 = & V_38 -> V_195 ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_32 * V_194 = F_6 ( V_34 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_197 = * V_34 ;
V_38 -> V_198 = * V_194 ;
V_38 -> V_197 . V_36 = & V_38 -> V_198 ;
V_2 -> V_8 . V_9 . V_198 = & V_38 -> V_197 ;
}
static void F_62 ( struct V_1 * V_2 , bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
if ( V_38 -> V_199 ) {
V_65 = F_63 ( V_2 , V_18 ) ;
if ( V_65 )
F_64 ( L_1 ) ;
}
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_65 = F_19 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_2 ) ;
return V_65 ;
}
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
V_65 = F_48 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_3 ) ;
return V_65 ;
}
F_57 ( V_2 ) ;
V_65 = F_50 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_4 ) ;
return V_65 ;
}
V_65 = F_53 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_5 ) ;
return V_65 ;
}
V_65 = F_54 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_6 ) ;
return V_65 ;
}
V_65 = F_55 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_7 ) ;
return V_65 ;
}
V_65 = F_56 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_8 ) ;
return V_65 ;
}
F_26 ( V_2 ) ;
#if 0
kv_initialize_hardware_cac_manager(adev);
#endif
F_40 ( V_2 ) ;
if ( V_38 -> V_200 ) {
V_65 = F_49 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_9 ) ;
return V_65 ;
}
}
V_65 = F_22 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_10 ) ;
return V_65 ;
}
V_65 = F_24 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_11 ) ;
return V_65 ;
}
V_65 = F_25 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_12 ) ;
return V_65 ;
}
V_65 = F_58 ( V_2 , true ) ;
if ( V_65 ) {
F_64 ( L_13 ) ;
return V_65 ;
}
F_37 ( V_2 ) ;
V_65 = F_16 ( V_2 , true ) ;
if ( V_65 ) {
F_64 ( L_14 ) ;
return V_65 ;
}
V_65 = F_17 ( V_2 , true ) ;
if ( V_65 ) {
F_64 ( L_15 ) ;
return V_65 ;
}
F_59 ( V_2 ) ;
V_65 = F_63 ( V_2 , false ) ;
if ( V_65 ) {
F_64 ( L_1 ) ;
return V_65 ;
}
F_60 ( V_2 , V_2 -> V_8 . V_9 . V_201 ) ;
if ( V_2 -> V_202 . V_203 &&
F_68 ( V_2 -> V_8 . V_204 ) ) {
V_65 = F_69 ( V_2 , V_205 , V_206 ) ;
if ( V_65 ) {
F_64 ( L_16 ) ;
return V_65 ;
}
F_70 ( V_2 , & V_2 -> V_8 . V_9 . V_207 . V_202 ,
V_208 ) ;
F_70 ( V_2 , & V_2 -> V_8 . V_9 . V_207 . V_202 ,
V_209 ) ;
}
return V_65 ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_72 ( V_2 , & V_2 -> V_8 . V_9 . V_207 . V_202 ,
V_208 ) ;
F_72 ( V_2 , & V_2 -> V_8 . V_9 . V_207 . V_202 ,
V_209 ) ;
F_63 ( V_2 , false ) ;
if ( V_2 -> V_122 == V_124 )
F_73 ( V_2 , false ) ;
F_74 ( V_2 , false ) ;
F_75 ( V_2 , false ) ;
F_76 ( V_2 , false ) ;
F_77 ( V_2 , false ) ;
F_17 ( V_2 , false ) ;
F_16 ( V_2 , false ) ;
F_27 ( V_2 ) ;
F_39 ( V_2 ) ;
F_58 ( V_2 , false ) ;
F_41 ( V_2 ) ;
F_60 ( V_2 , V_2 -> V_8 . V_9 . V_201 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_126 = 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 = 0 ;
if ( V_38 -> V_210 ) {
T_3 V_76 ;
V_76 = 45 ;
V_38 -> V_211 = F_35 ( V_76 ) ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_212 ) ,
( V_87 * ) & V_38 -> V_211 ,
sizeof( T_3 ) , V_38 -> V_80 ) ;
V_76 = 30 ;
V_38 -> V_213 = F_35 ( V_76 ) ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_214 ) ,
( V_87 * ) & V_38 -> V_213 ,
sizeof( T_3 ) , V_38 -> V_80 ) ;
}
return V_65 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_215 = false ;
V_38 -> V_216 = false ;
V_38 -> V_217 = false ;
V_38 -> V_218 = false ;
}
static int F_80 ( struct V_1 * V_2 , bool V_18 )
{
return F_18 ( V_2 , V_18 ?
V_219 : V_220 ) ;
}
static int F_81 ( struct V_1 * V_2 , bool V_18 )
{
return F_18 ( V_2 , V_18 ?
V_221 : V_222 ) ;
}
static int F_82 ( struct V_1 * V_2 , bool V_18 )
{
return F_18 ( V_2 , V_18 ?
V_223 : V_224 ) ;
}
static int F_83 ( struct V_1 * V_2 , bool V_18 )
{
return F_18 ( V_2 , V_18 ?
V_225 : V_226 ) ;
}
static int F_84 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_141 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_142 ;
int V_65 ;
T_1 V_50 ;
if ( ! V_227 ) {
if ( V_21 -> V_13 )
V_38 -> V_228 = V_21 -> V_13 - 1 ;
else
V_38 -> V_228 = 0 ;
if ( ! V_38 -> V_229 || V_38 -> V_230 ) {
V_50 = 1 << V_38 -> V_228 ;
} else {
V_50 = 0x1f ;
}
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_231 ) ,
( V_232 * ) & V_38 -> V_228 ,
sizeof( V_87 ) , V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
F_85 ( V_2 ,
V_233 ,
V_50 ) ;
}
return F_80 ( V_2 , ! V_227 ) ;
}
static V_87 F_86 ( struct V_1 * V_2 , T_1 V_165 )
{
V_87 V_12 ;
struct V_160 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_161 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_21 -> V_14 [ V_12 ] . V_165 >= V_165 )
break;
}
return V_12 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_33 * V_234 ,
struct V_33 * V_235 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_160 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_161 ;
int V_65 ;
if ( V_234 -> V_165 > 0 && V_235 -> V_165 == 0 ) {
F_76 ( V_2 , false ) ;
if ( V_38 -> V_230 )
V_38 -> V_236 = V_21 -> V_13 - 1 ;
else
V_38 -> V_236 = F_86 ( V_2 , V_234 -> V_165 ) ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_237 ) ,
( V_87 * ) & V_38 -> V_236 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
if ( V_38 -> V_230 )
F_85 ( V_2 ,
V_238 ,
( 1 << V_38 -> V_236 ) ) ;
F_81 ( V_2 , true ) ;
} else if ( V_234 -> V_165 == 0 && V_235 -> V_165 > 0 ) {
F_81 ( V_2 , false ) ;
F_76 ( V_2 , true ) ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_175 ;
int V_65 ;
if ( ! V_227 ) {
if ( V_38 -> V_230 )
V_38 -> V_239 = V_21 -> V_13 - 1 ;
else
V_38 -> V_239 = 0 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_240 ) ,
( V_87 * ) & V_38 -> V_239 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
if ( V_38 -> V_230 )
F_85 ( V_2 ,
V_241 ,
( 1 << V_38 -> V_239 ) ) ;
}
return F_82 ( V_2 , ! V_227 ) ;
}
static V_87 F_89 ( struct V_1 * V_2 )
{
V_87 V_12 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_183 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_21 -> V_14 [ V_12 ] . V_130 >= 0 )
break;
}
if ( V_12 >= V_21 -> V_13 )
V_12 = V_21 -> V_13 - 1 ;
return V_12 ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_87 V_193 ;
if ( ! V_38 -> V_230 ) {
V_193 = F_89 ( V_2 ) ;
if ( V_193 != V_38 -> V_193 ) {
V_38 -> V_193 = V_193 ;
F_85 ( V_2 ,
V_242 ,
( 1 << V_38 -> V_193 ) ) ;
}
}
}
static int F_91 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_183 ;
int V_65 ;
if ( ! V_227 ) {
if ( V_38 -> V_230 )
V_38 -> V_193 = V_21 -> V_13 - 1 ;
else
V_38 -> V_193 = F_89 ( V_2 ) ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_243 ) ,
( V_87 * ) & V_38 -> V_193 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
if ( V_38 -> V_230 )
F_85 ( V_2 ,
V_242 ,
( 1 << V_38 -> V_193 ) ) ;
}
return F_83 ( V_2 , ! V_227 ) ;
}
static void F_77 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
V_38 -> V_215 = V_227 ;
if ( V_227 ) {
V_65 = F_92 ( V_2 , V_244 ,
V_245 ) ;
F_84 ( V_2 , V_227 ) ;
if ( V_38 -> V_246 )
F_18 ( V_2 , V_247 ) ;
} else {
if ( V_38 -> V_246 )
F_18 ( V_2 , V_248 ) ;
F_84 ( V_2 , V_227 ) ;
V_65 = F_92 ( V_2 , V_244 ,
V_249 ) ;
}
}
static void F_76 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
if ( V_38 -> V_216 == V_227 )
return;
V_38 -> V_216 = V_227 ;
if ( ! V_38 -> V_250 )
return;
if ( V_227 )
F_18 ( V_2 , V_251 ) ;
else
F_18 ( V_2 , V_252 ) ;
}
static void F_75 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
if ( V_38 -> V_217 == V_227 )
return;
V_38 -> V_217 = V_227 ;
if ( V_227 ) {
F_88 ( V_2 , true ) ;
if ( V_38 -> V_253 )
F_18 ( V_2 , V_254 ) ;
} else {
if ( V_38 -> V_253 )
F_18 ( V_2 , V_255 ) ;
F_88 ( V_2 , false ) ;
}
}
static void F_74 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
if ( V_38 -> V_218 == V_227 )
return;
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 )
return;
V_38 -> V_218 = V_227 ;
if ( V_227 ) {
F_91 ( V_2 , true ) ;
if ( V_38 -> V_256 )
F_18 ( V_2 , V_257 ) ;
} else {
if ( V_38 -> V_256 )
F_18 ( V_2 , V_258 ) ;
F_91 ( V_2 , false ) ;
}
}
static void F_93 ( struct V_1 * V_2 ,
struct V_33 * V_259 )
{
struct V_32 * V_194 = F_6 ( V_259 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_38 -> V_129 ; V_12 ++ ) {
if ( ( V_21 -> V_14 [ V_12 ] . V_130 >= V_194 -> V_260 [ 0 ] . V_94 ) ||
( V_12 == ( V_38 -> V_129 - 1 ) ) ) {
V_38 -> V_261 = V_12 ;
break;
}
}
for ( V_12 = V_38 -> V_129 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_21 -> V_14 [ V_12 ] . V_130 <= V_194 -> V_260 [ V_194 -> V_262 - 1 ] . V_94 )
break;
}
V_38 -> V_263 = V_12 ;
if ( V_38 -> V_261 > V_38 -> V_263 ) {
if ( ( V_194 -> V_260 [ 0 ] . V_94 - V_21 -> V_14 [ V_38 -> V_263 ] . V_130 ) >
( V_21 -> V_14 [ V_38 -> V_261 ] . V_130 - V_194 -> V_260 [ V_194 -> V_262 - 1 ] . V_94 ) )
V_38 -> V_263 = V_38 -> V_261 ;
else
V_38 -> V_261 = V_38 -> V_263 ;
}
} else {
struct V_19 * V_21 =
& V_38 -> V_104 . V_20 ;
for ( V_12 = 0 ; V_12 < ( int ) V_38 -> V_129 ; V_12 ++ ) {
if ( V_21 -> V_14 [ V_12 ] . V_26 >= V_194 -> V_260 [ 0 ] . V_94 ||
V_12 == ( int ) ( V_38 -> V_129 - 1 ) ) {
V_38 -> V_261 = V_12 ;
break;
}
}
for ( V_12 = V_38 -> V_129 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_21 -> V_14 [ V_12 ] . V_26 <=
V_194 -> V_260 [ V_194 -> V_262 - 1 ] . V_94 )
break;
}
V_38 -> V_263 = V_12 ;
if ( V_38 -> V_261 > V_38 -> V_263 ) {
if ( ( V_194 -> V_260 [ 0 ] . V_94 -
V_21 -> V_14 [ V_38 -> V_263 ] . V_26 ) >
( V_21 -> V_14 [ V_38 -> V_261 ] . V_26 -
V_194 -> V_260 [ V_194 -> V_262 - 1 ] . V_94 ) )
V_38 -> V_263 = V_38 -> V_261 ;
else
V_38 -> V_261 = V_38 -> V_263 ;
}
}
}
static int F_94 ( struct V_1 * V_2 ,
struct V_33 * V_259 )
{
struct V_32 * V_194 = F_6 ( V_259 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 = 0 ;
V_87 V_264 ;
if ( V_38 -> V_140 ) {
V_264 = V_194 -> V_265 ?
V_38 -> V_98 [ V_38 -> V_91 ] . V_167 : 0 ;
V_65 = F_23 ( V_2 ,
( V_38 -> V_81 +
F_21 ( V_85 , V_134 ) +
( V_38 -> V_91 * sizeof( V_135 ) ) +
F_21 ( V_135 , V_167 ) ) ,
& V_264 ,
sizeof( V_87 ) , V_38 -> V_80 ) ;
}
return V_65 ;
}
static int F_73 ( struct V_1 * V_2 ,
bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 = 0 ;
if ( V_18 ) {
if ( V_38 -> V_266 && ! V_38 -> V_267 ) {
V_65 = F_18 ( V_2 , V_268 ) ;
if ( V_65 == 0 )
V_38 -> V_267 = true ;
}
} else {
if ( V_38 -> V_266 && V_38 -> V_267 ) {
V_65 = F_18 ( V_2 , V_269 ) ;
if ( V_65 == 0 )
V_38 -> V_267 = false ;
}
}
return V_65 ;
}
static int F_95 ( struct V_1 * V_2 ,
enum V_270 V_271 )
{
int V_65 ;
if ( V_271 == V_272 ) {
V_65 = F_96 ( V_2 ) ;
if ( V_65 )
return V_65 ;
} else if ( V_271 == V_273 ) {
V_65 = F_44 ( V_2 ) ;
if ( V_65 )
return V_65 ;
} else if ( V_271 == V_274 ) {
V_65 = F_45 ( V_2 ) ;
if ( V_65 )
return V_65 ;
}
V_2 -> V_8 . V_9 . V_275 = V_271 ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_33 V_198 = * V_2 -> V_8 . V_9 . V_198 ;
struct V_33 * V_194 = & V_198 ;
F_61 ( V_2 , V_194 ) ;
F_98 ( V_2 ,
& V_38 -> V_197 ,
& V_38 -> V_195 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_33 * V_194 = & V_38 -> V_197 ;
struct V_33 * V_276 = & V_38 -> V_195 ;
int V_65 ;
if ( V_38 -> V_199 ) {
V_65 = F_63 ( V_2 , V_2 -> V_8 . V_9 . V_277 ) ;
if ( V_65 ) {
F_64 ( L_1 ) ;
return V_65 ;
}
}
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 ) {
if ( V_38 -> V_278 ) {
F_93 ( V_2 , V_194 ) ;
F_94 ( V_2 , V_194 ) ;
V_65 = F_100 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_17 ) ;
return V_65 ;
}
F_101 ( V_2 ) ;
F_102 ( V_2 ) ;
F_43 ( V_2 ) ;
F_103 ( V_2 ) ;
F_50 ( V_2 ) ;
F_104 ( V_2 , V_194 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_43 ( V_2 ) ;
F_45 ( V_2 ) ;
V_65 = F_87 ( V_2 , V_194 , V_276 ) ;
if ( V_65 ) {
F_64 ( L_18 ) ;
return V_65 ;
}
F_47 ( V_2 ) ;
if ( V_2 -> V_122 == V_124 )
F_73 ( V_2 , true ) ;
}
} else {
if ( V_38 -> V_278 ) {
F_93 ( V_2 , V_194 ) ;
F_94 ( V_2 , V_194 ) ;
V_65 = F_100 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_17 ) ;
return V_65 ;
}
F_101 ( V_2 ) ;
F_102 ( V_2 ) ;
F_42 ( V_2 , true ) ;
F_50 ( V_2 ) ;
F_104 ( V_2 , V_194 ) ;
F_42 ( V_2 , false ) ;
F_46 ( V_2 ) ;
V_65 = F_87 ( V_2 , V_194 , V_276 ) ;
if ( V_65 ) {
F_64 ( L_18 ) ;
return V_65 ;
}
F_90 ( V_2 ) ;
F_47 ( V_2 ) ;
F_73 ( V_2 , true ) ;
}
}
return 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_33 * V_194 = & V_38 -> V_197 ;
F_60 ( V_2 , V_194 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
F_3 ( V_2 , true ) ;
F_79 ( V_2 ) ;
F_78 ( V_2 ) ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_279 * V_21 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
if ( V_38 -> V_104 . V_20 . V_28 > 0 ) {
int V_280 = V_38 -> V_104 . V_20 . V_28 - 1 ;
V_21 -> V_94 =
V_38 -> V_104 . V_20 . V_14 [ V_280 ] . V_26 ;
V_21 -> V_281 =
F_32 ( V_2 ,
V_38 -> V_104 . V_20 . V_14 [ V_280 ] . V_5 ) ;
}
V_21 -> V_282 = V_38 -> V_104 . V_283 [ 0 ] ;
}
static void F_108 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_141 * V_284 =
& V_2 -> V_8 . V_9 . V_10 . V_142 ;
struct V_160 * V_285 =
& V_2 -> V_8 . V_9 . V_10 . V_161 ;
struct V_6 * V_286 =
& V_2 -> V_8 . V_9 . V_10 . V_175 ;
struct V_6 * V_287 =
& V_2 -> V_8 . V_9 . V_10 . V_183 ;
if ( V_284 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_284 -> V_13 ; V_12 ++ )
V_284 -> V_14 [ V_12 ] . V_15 =
F_31 ( V_2 ,
V_284 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_285 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_285 -> V_13 ; V_12 ++ )
V_285 -> V_14 [ V_12 ] . V_15 =
F_31 ( V_2 ,
V_285 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_286 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_286 -> V_13 ; V_12 ++ )
V_286 -> V_14 [ V_12 ] . V_15 =
F_31 ( V_2 ,
V_286 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_287 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_287 -> V_13 ; V_12 ++ )
V_287 -> V_14 [ V_12 ] . V_15 =
F_31 ( V_2 ,
V_287 -> V_14 [ V_12 ] . V_15 ) ;
}
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_131 . V_94 = V_38 -> V_104 . V_288 ;
V_38 -> V_131 . V_289 = V_38 -> V_104 . V_290 ;
V_38 -> V_131 . V_291 = 0 ;
V_38 -> V_131 . V_292 = 0 ;
V_38 -> V_131 . V_293 = 1 ;
V_38 -> V_131 . V_294 = 0 ;
V_38 -> V_131 . V_295 = 0 ;
V_38 -> V_131 . V_296 = 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_65 ;
T_1 V_297 , V_12 ;
V_65 = F_110 ( V_2 , & V_297 ) ;
if ( V_65 )
return V_65 ;
for ( V_12 = V_136 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_297 & ( 1 << V_12 ) )
break;
}
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 )
return F_85 ( V_2 , V_298 , V_12 ) ;
else
return F_111 ( V_2 , V_12 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_65 ;
T_1 V_297 , V_12 ;
V_65 = F_110 ( V_2 , & V_297 ) ;
if ( V_65 )
return V_65 ;
for ( V_12 = 0 ; V_12 < V_136 ; V_12 ++ ) {
if ( V_297 & ( 1 << V_12 ) )
break;
}
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 )
return F_85 ( V_2 , V_298 , V_12 ) ;
else
return F_111 ( V_2 , V_12 ) ;
}
static V_87 F_112 ( struct V_1 * V_2 ,
T_1 V_94 , T_1 V_299 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
T_1 V_300 ;
T_1 V_301 = F_113 ( V_299 , ( T_1 ) V_302 ) ;
if ( V_94 < V_301 )
return 0 ;
if ( ! V_38 -> V_303 )
return 0 ;
for ( V_12 = V_304 ; V_12 > 0 ; V_12 -- ) {
V_300 = V_94 >> V_12 ;
if ( V_300 >= V_301 )
break;
}
return ( V_87 ) V_12 ;
}
static int F_114 ( struct V_1 * V_2 , int * V_305 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
int V_12 ;
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = V_21 -> V_13 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_38 -> V_144 &&
( F_31 ( V_2 , V_21 -> V_14 [ V_12 ] . V_15 ) <=
V_38 -> V_144 ) ) {
* V_305 = V_12 ;
return 0 ;
}
}
} else {
struct V_19 * V_21 =
& V_38 -> V_104 . V_20 ;
for ( V_12 = V_21 -> V_28 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_38 -> V_144 &&
( F_32 ( V_2 , V_21 -> V_14 [ V_12 ] . V_5 ) <=
V_38 -> V_144 ) ) {
* V_305 = V_12 ;
return 0 ;
}
}
}
* V_305 = 0 ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_33 * V_259 ,
struct V_33 * V_306 )
{
struct V_32 * V_35 = F_6 ( V_259 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_307 = 10000 ;
T_1 V_94 , V_282 = 0 ;
int V_12 , V_305 ;
bool V_308 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
T_1 V_309 = 0 ;
struct V_279 * V_310 =
& V_2 -> V_8 . V_9 . V_10 . V_311 ;
if ( V_259 -> V_312 ) {
V_259 -> V_165 = V_2 -> V_8 . V_9 . V_313 [ V_2 -> V_8 . V_9 . V_163 ] . V_165 ;
V_259 -> V_314 = V_2 -> V_8 . V_9 . V_313 [ V_2 -> V_8 . V_9 . V_163 ] . V_314 ;
} else {
V_259 -> V_165 = 0 ;
V_259 -> V_314 = 0 ;
}
V_282 = V_310 -> V_282 ;
V_94 = V_307 ;
if ( V_38 -> V_230 ) {
V_309 = ( V_310 -> V_94 * 75 ) / 100 ;
for ( V_12 = V_21 -> V_13 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_309 >= V_21 -> V_14 [ V_12 ] . V_130 ) {
V_309 = V_21 -> V_14 [ V_12 ] . V_130 ;
break;
}
}
if ( V_12 > 0 )
V_309 = V_21 -> V_14 [ 0 ] . V_130 ;
V_94 = V_309 ;
}
if ( V_259 -> V_312 ) {
if ( V_94 < V_2 -> V_8 . V_9 . V_313 [ V_2 -> V_8 . V_9 . V_163 ] . V_94 )
V_94 = V_2 -> V_8 . V_9 . V_313 [ V_2 -> V_8 . V_9 . V_163 ] . V_94 ;
}
V_35 -> V_265 = true ;
for ( V_12 = 0 ; V_12 < V_35 -> V_262 ; V_12 ++ ) {
if ( V_35 -> V_260 [ V_12 ] . V_94 < V_94 )
V_35 -> V_260 [ V_12 ] . V_94 = V_94 ;
}
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_35 -> V_262 ; V_12 ++ ) {
if ( V_38 -> V_144 &&
( V_38 -> V_144 <
F_31 ( V_2 , V_35 -> V_260 [ V_12 ] . V_289 ) ) ) {
F_114 ( V_2 , & V_305 ) ;
V_35 -> V_260 [ V_12 ] . V_94 = V_21 -> V_14 [ V_305 ] . V_130 ;
}
}
} else {
struct V_19 * V_21 =
& V_38 -> V_104 . V_20 ;
for ( V_12 = 0 ; V_12 < V_35 -> V_262 ; V_12 ++ ) {
if ( V_38 -> V_144 &&
( V_38 -> V_144 <
F_31 ( V_2 , V_35 -> V_260 [ V_12 ] . V_289 ) ) ) {
F_114 ( V_2 , & V_305 ) ;
V_35 -> V_260 [ V_12 ] . V_94 = V_21 -> V_14 [ V_305 ] . V_26 ;
}
}
}
if ( V_38 -> V_230 ) {
for ( V_12 = 0 ; V_12 < V_35 -> V_262 ; V_12 ++ ) {
V_35 -> V_260 [ V_12 ] . V_94 = V_309 ;
}
}
V_38 -> V_315 = V_259 -> V_149 || V_259 -> V_147 ||
V_259 -> V_165 || V_259 -> V_314 ;
if ( ( V_259 -> V_316 & V_317 ) ==
V_318 )
V_38 -> V_319 = true ;
else
V_38 -> V_319 = false ;
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 ) {
V_35 -> V_320 = 0x1 ;
V_35 -> V_321 = 0x0 ;
V_35 -> V_322 = 0x1 ;
V_35 -> V_323 = 0x0 ;
} else {
V_35 -> V_320 = 0x3 ;
V_35 -> V_321 = 0x0 ;
V_35 -> V_322 = 0x3 ;
V_35 -> V_323 = 0x0 ;
if ( V_38 -> V_104 . V_324 ) {
V_308 = ( V_282 >= V_38 -> V_104 . V_283 [ 3 ] ) ||
V_38 -> V_315 || ( V_2 -> V_8 . V_9 . V_325 >= 3 ) ||
V_38 -> V_326 ;
V_35 -> V_320 = V_308 ? 0x2 : 0x3 ;
V_35 -> V_321 = 0x2 ;
V_35 -> V_322 = V_308 ? 0x2 : 0x3 ;
V_35 -> V_323 = 0x2 ;
}
}
}
static void F_115 ( struct V_1 * V_2 ,
T_1 V_93 , bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_98 [ V_93 ] . V_327 = V_18 ? 1 : 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_328 = 10000 ;
T_1 V_12 ;
if ( V_38 -> V_261 > V_38 -> V_263 )
return - V_45 ;
for ( V_12 = V_38 -> V_261 ; V_12 <= V_38 -> V_263 ; V_12 ++ ) {
V_38 -> V_98 [ V_12 ] . V_329 =
F_112 ( V_2 ,
F_116 ( V_38 -> V_98 [ V_12 ] . V_101 ) ,
V_328 ) ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
bool V_308 ;
struct V_279 * V_310 =
& V_2 -> V_8 . V_9 . V_10 . V_311 ;
T_1 V_282 = V_310 -> V_282 ;
if ( V_38 -> V_261 > V_38 -> V_263 )
return - V_45 ;
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 ) {
for ( V_12 = V_38 -> V_261 ; V_12 <= V_38 -> V_263 ; V_12 ++ ) {
V_38 -> V_98 [ V_12 ] . V_330 = 1 ;
V_38 -> V_98 [ V_12 ] . V_331 = 0 ;
V_38 -> V_98 [ V_12 ] . V_332 = 0 ;
}
if ( ! V_38 -> V_104 . V_324 )
return 0 ;
V_308 = ( ( V_282 >= V_38 -> V_104 . V_283 [ 3 ] ) ||
( V_2 -> V_8 . V_9 . V_325 >= 3 ) || V_38 -> V_315 ) ;
if ( V_308 ) {
for ( V_12 = V_38 -> V_261 ; V_12 <= V_38 -> V_263 ; V_12 ++ )
V_38 -> V_98 [ V_12 ] . V_330 = 0 ;
} else {
if ( V_38 -> V_319 )
V_38 -> V_98 [ 0 ] . V_331 = 1 ;
V_38 -> V_98 [ 1 ] . V_330 = 0 ;
V_38 -> V_98 [ 2 ] . V_330 = 0 ;
V_38 -> V_98 [ 3 ] . V_330 = 0 ;
V_38 -> V_98 [ 4 ] . V_330 = 0 ;
}
} else {
for ( V_12 = V_38 -> V_261 ; V_12 <= V_38 -> V_263 ; V_12 ++ ) {
V_38 -> V_98 [ V_12 ] . V_330 = 1 ;
V_38 -> V_98 [ V_12 ] . V_331 = 0 ;
V_38 -> V_98 [ V_12 ] . V_332 = 0 ;
}
if ( V_38 -> V_104 . V_324 && V_38 -> V_319 ) {
V_38 -> V_98 [ V_38 -> V_261 ] . V_332 = 0x28 ;
V_38 -> V_98 [ V_38 -> V_261 ] . V_330 = 0 ;
if ( V_38 -> V_261 != V_38 -> V_263 )
V_38 -> V_98 [ V_38 -> V_261 ] . V_331 = 1 ;
}
}
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
if ( V_38 -> V_261 > V_38 -> V_263 )
return - V_45 ;
for ( V_12 = V_38 -> V_261 ; V_12 <= V_38 -> V_263 ; V_12 ++ )
V_38 -> V_98 [ V_12 ] . V_333 = ( V_12 == V_38 -> V_263 ) ? 1 : 0 ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_21 && V_21 -> V_13 ) {
T_1 V_5 ;
V_38 -> V_129 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_13 ; V_12 ++ ) {
if ( V_38 -> V_144 &&
( V_38 -> V_144 <
F_31 ( V_2 , V_21 -> V_14 [ V_12 ] . V_15 ) ) )
break;
F_28 ( V_2 , V_12 , V_21 -> V_14 [ V_12 ] . V_130 ) ;
V_5 = F_2 ( V_2 ,
& V_38 -> V_104 . V_4 ,
V_21 -> V_14 [ V_12 ] . V_15 ) ;
F_33 ( V_2 , V_12 , V_5 ) ;
F_34 ( V_2 , V_12 , V_38 -> V_109 [ V_12 ] ) ;
F_115 ( V_2 , V_12 , true ) ;
V_38 -> V_129 ++ ;
}
} else {
struct V_19 * V_21 =
& V_38 -> V_104 . V_20 ;
V_38 -> V_129 = 0 ;
for ( V_12 = 0 ; V_12 < V_21 -> V_28 ; V_12 ++ ) {
if ( V_38 -> V_144 &&
V_38 -> V_144 <
F_32 ( V_2 , V_21 -> V_14 [ V_12 ] . V_5 ) )
break;
F_28 ( V_2 , V_12 , V_21 -> V_14 [ V_12 ] . V_26 ) ;
F_33 ( V_2 , V_12 , V_21 -> V_14 [ V_12 ] . V_5 ) ;
F_34 ( V_2 , V_12 , V_38 -> V_109 [ V_12 ] ) ;
F_115 ( V_2 , V_12 , true ) ;
V_38 -> V_129 ++ ;
}
}
for ( V_12 = 0 ; V_12 < V_136 ; V_12 ++ )
F_36 ( V_2 , V_12 , false ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
for ( V_12 = 0 ; V_12 < V_136 ; V_12 ++ ) {
if ( V_12 >= V_38 -> V_261 && V_12 <= V_38 -> V_263 )
F_36 ( V_2 , V_12 , true ) ;
}
}
static int F_111 ( struct V_1 * V_2 , T_1 V_271 )
{
T_1 V_334 = ( 1 << V_271 ) ;
return F_85 ( V_2 ,
V_335 ,
V_334 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 , V_334 = 0 ;
for ( V_12 = V_38 -> V_261 ; V_12 <= V_38 -> V_263 ; V_12 ++ )
V_334 |= ( 1 << V_12 ) ;
return F_85 ( V_2 ,
V_335 ,
V_334 ) ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_33 * V_259 )
{
struct V_32 * V_194 = F_6 ( V_259 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_336 ;
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 )
return;
if ( V_38 -> V_104 . V_324 ) {
V_336 = F_9 ( V_337 ) ;
V_336 &= ~ ( V_338 |
V_339 |
V_340 |
V_341 ) ;
V_336 |= ( V_194 -> V_320 << V_342 ) |
( V_194 -> V_321 << V_343 ) |
( V_194 -> V_322 << V_344 ) |
( V_194 -> V_323 << V_345 ) ;
F_12 ( V_337 , V_336 ) ;
}
}
static int F_69 ( struct V_1 * V_2 ,
int V_346 , int V_347 )
{
int V_348 = 0 * 1000 ;
int V_349 = 255 * 1000 ;
T_1 V_76 ;
if ( V_348 < V_346 )
V_348 = V_346 ;
if ( V_349 > V_347 )
V_349 = V_347 ;
if ( V_349 < V_348 ) {
F_64 ( L_19 , V_348 , V_349 ) ;
return - V_45 ;
}
V_76 = F_9 ( V_350 ) ;
V_76 &= ~ ( V_351 |
V_352 ) ;
V_76 |= ( ( 49 + ( V_349 / 1000 ) ) << V_353 ) |
( ( 49 + ( V_348 / 1000 ) ) << V_354 ) ;
F_12 ( V_350 , V_76 ) ;
V_2 -> V_8 . V_9 . V_207 . V_346 = V_348 ;
V_2 -> V_8 . V_9 . V_207 . V_347 = V_349 ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_355 * V_356 = & V_2 -> V_356 ;
int V_93 = F_118 ( V_357 , V_358 ) ;
union V_359 * V_359 ;
V_87 V_360 , V_361 ;
T_3 V_362 ;
int V_12 ;
if ( F_119 ( V_356 -> V_363 , V_93 , NULL ,
& V_360 , & V_361 , & V_362 ) ) {
V_359 = (union V_359 * ) ( V_356 -> V_363 -> V_364 +
V_362 ) ;
if ( V_361 != 8 ) {
F_64 ( L_20 , V_360 , V_361 ) ;
return - V_45 ;
}
V_38 -> V_104 . V_288 = F_120 ( V_359 -> V_365 . V_366 ) ;
V_38 -> V_104 . V_367 = F_120 ( V_359 -> V_365 . V_368 ) ;
V_38 -> V_104 . V_290 =
F_121 ( V_359 -> V_365 . V_369 ) ;
if ( V_359 -> V_365 . V_370 == 0 )
V_38 -> V_104 . V_371 = 203 ;
else
V_38 -> V_104 . V_371 = V_359 -> V_365 . V_370 ;
if ( V_359 -> V_365 . V_372 == 0 )
V_38 -> V_104 . V_373 = 5 ;
else
V_38 -> V_104 . V_373 = V_359 -> V_365 . V_372 ;
if ( V_38 -> V_104 . V_371 <= V_38 -> V_104 . V_373 ) {
F_64 ( L_21 ) ;
}
if ( F_120 ( V_359 -> V_365 . V_374 ) & ( 1 << 3 ) )
V_38 -> V_104 . V_324 = true ;
else
V_38 -> V_104 . V_324 = false ;
for ( V_12 = 0 ; V_12 < V_375 ; V_12 ++ ) {
V_38 -> V_104 . V_283 [ V_12 ] =
F_120 ( V_359 -> V_365 . V_376 [ V_12 ] ) ;
V_38 -> V_104 . V_377 [ V_12 ] =
F_120 ( V_359 -> V_365 . V_378 [ V_12 ] ) ;
}
if ( F_120 ( V_359 -> V_365 . V_379 ) &
V_380 )
V_38 -> V_140 = true ;
F_4 ( V_2 ,
& V_38 -> V_104 . V_20 ,
V_359 -> V_365 . V_381 ) ;
F_5 ( V_2 ,
& V_38 -> V_104 . V_4 ,
V_359 -> V_365 . V_381 ) ;
F_107 ( V_2 ,
& V_2 -> V_8 . V_9 . V_10 . V_311 ) ;
}
return 0 ;
}
static void F_122 ( struct V_1 * V_2 ,
struct V_32 * V_35 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_35 -> V_262 = 1 ;
V_35 -> V_260 [ 0 ] = V_38 -> V_131 ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_382 * V_383 ,
V_87 V_384 )
{
struct V_32 * V_35 = F_6 ( V_34 ) ;
V_34 -> V_385 = F_120 ( V_383 -> V_386 ) ;
V_34 -> V_316 = F_121 ( V_383 -> V_387 ) ;
V_34 -> V_388 = F_121 ( V_383 -> V_389 ) ;
if ( V_390 < V_384 ) {
V_34 -> V_147 = F_120 ( V_383 -> V_391 ) ;
V_34 -> V_149 = F_120 ( V_383 -> V_392 ) ;
} else {
V_34 -> V_147 = 0 ;
V_34 -> V_149 = 0 ;
}
if ( V_34 -> V_316 & V_393 ) {
V_2 -> V_8 . V_9 . V_201 = V_34 ;
F_122 ( V_2 , V_35 ) ;
}
if ( V_34 -> V_316 & V_394 )
V_2 -> V_8 . V_9 . V_395 = V_34 ;
}
static void F_124 ( struct V_1 * V_2 ,
struct V_33 * V_34 , int V_93 ,
union V_396 * V_397 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_32 * V_35 = F_6 ( V_34 ) ;
struct V_398 * V_399 = & V_35 -> V_260 [ V_93 ] ;
T_1 V_94 ;
V_94 = F_121 ( V_397 -> V_400 . V_401 ) ;
V_94 |= V_397 -> V_400 . V_402 << 16 ;
V_399 -> V_94 = V_94 ;
V_399 -> V_289 = V_397 -> V_400 . V_403 ;
V_35 -> V_262 = V_93 + 1 ;
if ( V_38 -> V_303 ) {
V_399 -> V_291 = 5 ;
V_399 -> V_292 = 5 ;
}
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_355 * V_356 = & V_2 -> V_356 ;
struct V_382 * V_383 ;
union V_404 * V_405 ;
int V_12 , V_29 , V_406 , V_407 , V_408 ;
union V_396 * V_397 ;
struct V_409 * V_410 ;
struct V_411 * V_412 ;
struct V_413 * V_414 ;
union V_415 * V_415 ;
int V_93 = F_118 ( V_357 , V_416 ) ;
T_3 V_362 ;
V_87 V_360 , V_361 ;
V_87 * V_417 ;
struct V_32 * V_35 ;
if ( ! F_119 ( V_356 -> V_363 , V_93 , NULL ,
& V_360 , & V_361 , & V_362 ) )
return - V_45 ;
V_415 = (union V_415 * ) ( V_356 -> V_363 -> V_364 + V_362 ) ;
F_126 ( V_2 ) ;
V_410 = (struct V_409 * )
( V_356 -> V_363 -> V_364 + V_362 +
F_121 ( V_415 -> V_418 . V_419 ) ) ;
V_412 = (struct V_411 * )
( V_356 -> V_363 -> V_364 + V_362 +
F_121 ( V_415 -> V_418 . V_420 ) ) ;
V_414 = (struct V_413 * )
( V_356 -> V_363 -> V_364 + V_362 +
F_121 ( V_415 -> V_418 . V_421 ) ) ;
V_2 -> V_8 . V_9 . V_35 = F_127 ( sizeof( struct V_33 ) *
V_410 -> V_422 , V_423 ) ;
if ( ! V_2 -> V_8 . V_9 . V_35 )
return - V_424 ;
V_417 = ( V_87 * ) V_410 -> V_425 ;
for ( V_12 = 0 ; V_12 < V_410 -> V_422 ; V_12 ++ ) {
V_87 * V_280 ;
V_405 = (union V_404 * ) V_417 ;
V_407 = V_405 -> V_426 . V_427 ;
V_383 = (struct V_382 * )
& V_414 -> V_428 [ V_407 ] ;
V_35 = F_127 ( sizeof( struct V_32 ) , V_423 ) ;
if ( V_35 == NULL ) {
F_128 ( V_2 -> V_8 . V_9 . V_35 ) ;
return - V_424 ;
}
V_2 -> V_8 . V_9 . V_35 [ V_12 ] . V_36 = V_35 ;
V_406 = 0 ;
V_280 = ( V_87 * ) & V_405 -> V_426 . V_429 [ 0 ] ;
for ( V_29 = 0 ; V_29 < V_405 -> V_426 . V_430 ; V_29 ++ ) {
V_408 = V_280 [ V_29 ] ;
if ( V_408 >= V_412 -> V_422 )
continue;
if ( V_406 >= V_24 )
break;
V_397 = (union V_396 * )
( ( V_87 * ) & V_412 -> V_431 [ 0 ] +
( V_408 * V_412 -> V_432 ) ) ;
F_124 ( V_2 ,
& V_2 -> V_8 . V_9 . V_35 [ V_12 ] , V_406 ,
V_397 ) ;
V_406 ++ ;
}
F_123 ( V_2 , & V_2 -> V_8 . V_9 . V_35 [ V_12 ] ,
V_383 ,
V_414 -> V_432 ) ;
V_417 += 2 + V_405 -> V_426 . V_430 ;
}
V_2 -> V_8 . V_9 . V_433 = V_410 -> V_422 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_8 . V_9 . V_434 ; V_12 ++ ) {
T_1 V_94 ;
V_408 = V_2 -> V_8 . V_9 . V_313 [ V_12 ] . V_435 ;
V_397 = (union V_396 * )
& V_412 -> V_431 [ V_408 * V_412 -> V_432 ] ;
V_94 = F_121 ( V_397 -> V_400 . V_401 ) ;
V_94 |= V_397 -> V_400 . V_402 << 16 ;
V_2 -> V_8 . V_9 . V_313 [ V_12 ] . V_94 = V_94 ;
V_2 -> V_8 . V_9 . V_313 [ V_12 ] . V_282 = 0 ;
}
return 0 ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_65 , V_12 ;
V_38 = F_127 ( sizeof( struct V_37 ) , V_423 ) ;
if ( V_38 == NULL )
return - V_424 ;
V_2 -> V_8 . V_9 . V_39 = V_38 ;
V_65 = F_130 ( V_2 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_131 ( V_2 ) ;
if ( V_65 )
return V_65 ;
for ( V_12 = 0 ; V_12 < V_24 ; V_12 ++ )
V_38 -> V_109 [ V_12 ] = V_436 ;
V_38 -> V_80 = V_437 ;
V_38 -> V_266 = true ;
V_38 -> V_438 = true ;
V_38 -> V_72 = true ;
V_38 -> V_439 = false ;
if ( V_38 -> V_439 ) {
V_38 -> V_53 = true ;
V_38 -> V_56 = true ;
V_38 -> V_59 = true ;
V_38 -> V_62 = true ;
}
if ( V_440 & V_441 )
V_38 -> V_303 = true ;
else
V_38 -> V_303 = false ;
V_38 -> V_200 = true ;
V_38 -> V_326 = false ;
if ( V_442 == 0 )
V_38 -> V_199 = false ;
else
V_38 -> V_199 = true ;
V_38 -> V_107 = 0 ;
V_38 -> V_127 = false ;
V_38 -> V_210 = false ;
V_38 -> V_246 = ( V_2 -> V_443 & V_444 ) ? true : false ;
V_38 -> V_229 = true ;
V_38 -> V_250 = ( V_2 -> V_443 & V_445 ) ? true : false ;
V_38 -> V_253 = ( V_2 -> V_443 & V_446 ) ? true : false ;
V_38 -> V_256 = ( V_2 -> V_443 & V_447 ) ? true : false ;
V_38 -> V_230 = false ;
V_65 = F_117 ( V_2 ) ;
if ( V_65 )
return V_65 ;
F_108 ( V_2 ) ;
F_109 ( V_2 ) ;
V_65 = F_125 ( V_2 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_278 = true ;
return 0 ;
}
static void
F_132 ( struct V_1 * V_2 ,
struct V_448 * V_449 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_450 =
( F_9 ( V_451 ) &
V_452 ) >>
V_453 ;
T_1 V_94 , V_76 ;
T_3 V_281 ;
if ( V_450 >= V_454 ) {
F_133 ( V_449 , L_22 , V_450 ) ;
} else {
V_94 = F_116 ( V_38 -> V_98 [ V_450 ] . V_101 ) ;
V_76 = ( F_9 ( V_455 ) &
V_456 ) >>
V_457 ;
V_281 = F_31 ( V_2 , ( T_3 ) V_76 ) ;
F_133 ( V_449 , L_23 , V_38 -> V_215 ? L_24 : L_25 ) ;
F_133 ( V_449 , L_26 , V_38 -> V_216 ? L_24 : L_25 ) ;
F_133 ( V_449 , L_27 ,
V_450 , V_94 , V_281 ) ;
}
}
static void
F_134 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_12 ;
struct V_32 * V_35 = F_6 ( V_34 ) ;
F_135 ( V_34 -> V_316 , V_34 -> V_388 ) ;
F_136 ( V_34 -> V_385 ) ;
F_137 ( L_28 , V_34 -> V_147 , V_34 -> V_149 ) ;
for ( V_12 = 0 ; V_12 < V_35 -> V_262 ; V_12 ++ ) {
struct V_398 * V_399 = & V_35 -> V_260 [ V_12 ] ;
F_137 ( L_29 ,
V_12 , V_399 -> V_94 ,
F_31 ( V_2 , V_399 -> V_289 ) ) ;
}
F_138 ( V_2 , V_34 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_8 . V_9 . V_433 ; V_12 ++ ) {
F_128 ( V_2 -> V_8 . V_9 . V_35 [ V_12 ] . V_36 ) ;
}
F_128 ( V_2 -> V_8 . V_9 . V_35 ) ;
F_128 ( V_2 -> V_8 . V_9 . V_39 ) ;
F_140 ( V_2 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
}
static T_1 F_142 ( struct V_1 * V_2 , bool V_458 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_32 * V_459 = F_6 ( & V_38 -> V_197 ) ;
if ( V_458 )
return V_459 -> V_260 [ 0 ] . V_94 ;
else
return V_459 -> V_260 [ V_459 -> V_262 - 1 ] . V_94 ;
}
static T_1 F_143 ( struct V_1 * V_2 , bool V_458 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
return V_38 -> V_104 . V_367 ;
}
static int F_144 ( struct V_1 * V_2 )
{
T_1 V_300 ;
int V_460 = 0 ;
V_300 = F_9 ( 0xC0300E0C ) ;
if ( V_300 )
V_460 = ( V_300 / 8 ) - 49 ;
else
V_460 = 0 ;
V_460 = V_460 * 1000 ;
return V_460 ;
}
static int F_145 ( void * V_461 )
{
struct V_1 * V_2 = (struct V_1 * ) V_461 ;
F_146 ( V_2 ) ;
F_147 ( V_2 ) ;
return 0 ;
}
static int F_148 ( void * V_461 )
{
struct V_1 * V_2 = (struct V_1 * ) V_461 ;
int V_65 ;
if ( ! V_462 )
return 0 ;
V_65 = F_149 ( V_2 ) ;
if ( V_65 )
return V_65 ;
F_74 ( V_2 , true ) ;
F_75 ( V_2 , true ) ;
return 0 ;
}
static int F_150 ( void * V_461 )
{
int V_65 ;
struct V_1 * V_2 = (struct V_1 * ) V_461 ;
V_65 = F_151 ( V_2 , 230 , & V_2 -> V_8 . V_9 . V_207 . V_202 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_151 ( V_2 , 231 , & V_2 -> V_8 . V_9 . V_207 . V_202 ) ;
if ( V_65 )
return V_65 ;
V_2 -> V_8 . V_9 . V_463 = V_464 ;
V_2 -> V_8 . V_9 . V_465 = V_464 ;
V_2 -> V_8 . V_9 . V_275 = V_274 ;
V_2 -> V_8 . V_466 = V_2 -> clock . V_466 ;
V_2 -> V_8 . V_467 = V_2 -> clock . V_467 ;
V_2 -> V_8 . V_468 = V_2 -> clock . V_466 ;
V_2 -> V_8 . V_469 = V_2 -> clock . V_467 ;
V_2 -> V_8 . V_204 = V_470 ;
if ( V_462 == 0 )
return 0 ;
F_152 ( & V_2 -> V_8 . V_9 . V_207 . V_471 , V_472 ) ;
F_153 ( & V_2 -> V_8 . V_473 ) ;
V_65 = F_129 ( V_2 ) ;
if ( V_65 )
goto V_474;
V_2 -> V_8 . V_9 . V_196 = V_2 -> V_8 . V_9 . V_198 = V_2 -> V_8 . V_9 . V_201 ;
if ( V_462 == 1 )
F_154 ( V_2 ) ;
F_155 ( & V_2 -> V_8 . V_473 ) ;
F_156 ( L_30 ) ;
return 0 ;
V_474:
F_139 ( V_2 ) ;
F_155 ( & V_2 -> V_8 . V_473 ) ;
F_64 ( L_31 ) ;
return V_65 ;
}
static int F_157 ( void * V_461 )
{
struct V_1 * V_2 = (struct V_1 * ) V_461 ;
F_158 ( & V_2 -> V_8 . V_9 . V_207 . V_471 ) ;
F_153 ( & V_2 -> V_8 . V_473 ) ;
F_159 ( V_2 ) ;
F_139 ( V_2 ) ;
F_155 ( & V_2 -> V_8 . V_473 ) ;
return 0 ;
}
static int F_160 ( void * V_461 )
{
int V_65 ;
struct V_1 * V_2 = (struct V_1 * ) V_461 ;
if ( ! V_462 )
return 0 ;
F_153 ( & V_2 -> V_8 . V_473 ) ;
F_106 ( V_2 ) ;
V_65 = F_65 ( V_2 ) ;
if ( V_65 )
V_2 -> V_8 . V_475 = false ;
else
V_2 -> V_8 . V_475 = true ;
F_155 ( & V_2 -> V_8 . V_473 ) ;
return V_65 ;
}
static int F_161 ( void * V_461 )
{
struct V_1 * V_2 = (struct V_1 * ) V_461 ;
if ( V_2 -> V_8 . V_475 ) {
F_153 ( & V_2 -> V_8 . V_473 ) ;
F_71 ( V_2 ) ;
F_155 ( & V_2 -> V_8 . V_473 ) ;
}
return 0 ;
}
static int F_162 ( void * V_461 )
{
struct V_1 * V_2 = (struct V_1 * ) V_461 ;
if ( V_2 -> V_8 . V_475 ) {
F_153 ( & V_2 -> V_8 . V_473 ) ;
F_71 ( V_2 ) ;
V_2 -> V_8 . V_9 . V_196 = V_2 -> V_8 . V_9 . V_198 = V_2 -> V_8 . V_9 . V_201 ;
F_155 ( & V_2 -> V_8 . V_473 ) ;
}
return 0 ;
}
static int F_163 ( void * V_461 )
{
int V_65 ;
struct V_1 * V_2 = (struct V_1 * ) V_461 ;
if ( V_2 -> V_8 . V_475 ) {
F_153 ( & V_2 -> V_8 . V_473 ) ;
F_106 ( V_2 ) ;
V_65 = F_65 ( V_2 ) ;
if ( V_65 )
V_2 -> V_8 . V_475 = false ;
else
V_2 -> V_8 . V_475 = true ;
F_155 ( & V_2 -> V_8 . V_473 ) ;
if ( V_2 -> V_8 . V_475 )
F_164 ( V_2 ) ;
}
return 0 ;
}
static bool F_165 ( void * V_461 )
{
return true ;
}
static int F_166 ( void * V_461 )
{
return 0 ;
}
static int F_167 ( void * V_461 )
{
return 0 ;
}
static int F_168 ( struct V_1 * V_2 ,
struct V_476 * V_477 ,
unsigned type ,
enum V_478 V_463 )
{
T_1 V_479 ;
switch ( type ) {
case V_208 :
switch ( V_463 ) {
case V_480 :
V_479 = F_9 ( V_350 ) ;
V_479 &= ~ V_481 ;
F_12 ( V_350 , V_479 ) ;
break;
case V_482 :
V_479 = F_9 ( V_350 ) ;
V_479 |= V_481 ;
F_12 ( V_350 , V_479 ) ;
break;
default:
break;
}
break;
case V_209 :
switch ( V_463 ) {
case V_480 :
V_479 = F_9 ( V_350 ) ;
V_479 &= ~ V_483 ;
F_12 ( V_350 , V_479 ) ;
break;
case V_482 :
V_479 = F_9 ( V_350 ) ;
V_479 |= V_483 ;
F_12 ( V_350 , V_479 ) ;
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
static int F_169 ( struct V_1 * V_2 ,
struct V_476 * V_484 ,
struct V_485 * V_486 )
{
bool V_487 = false ;
if ( V_486 == NULL )
return - V_45 ;
switch ( V_486 -> V_488 ) {
case 230 :
F_170 ( L_32 ) ;
V_2 -> V_8 . V_9 . V_207 . V_489 = false ;
V_487 = true ;
break;
case 231 :
F_170 ( L_33 ) ;
V_2 -> V_8 . V_9 . V_207 . V_489 = true ;
V_487 = true ;
break;
default:
break;
}
if ( V_487 )
F_171 ( & V_2 -> V_8 . V_9 . V_207 . V_471 ) ;
return 0 ;
}
static int F_172 ( void * V_461 ,
enum V_490 V_463 )
{
return 0 ;
}
static int F_173 ( void * V_461 ,
enum V_491 V_463 )
{
return 0 ;
}
static inline bool F_174 ( const struct V_398 * V_492 ,
const struct V_398 * V_493 )
{
return ( ( V_492 -> V_94 == V_493 -> V_94 ) &&
( V_492 -> V_289 == V_493 -> V_289 ) &&
( V_492 -> V_291 == V_493 -> V_291 ) &&
( V_492 -> V_294 == V_493 -> V_294 ) ) ;
}
static int F_175 ( struct V_1 * V_2 ,
struct V_33 * V_494 ,
struct V_33 * V_34 ,
bool * V_495 )
{
struct V_32 * V_496 ;
struct V_32 * V_497 ;
int V_12 ;
if ( V_2 == NULL || V_494 == NULL || V_34 == NULL || V_495 == NULL )
return - V_45 ;
V_496 = F_6 ( V_494 ) ;
V_497 = F_6 ( V_34 ) ;
if ( V_496 == NULL ) {
* V_495 = false ;
return 0 ;
}
if ( V_496 -> V_262 != V_497 -> V_262 ) {
* V_495 = false ;
return 0 ;
}
for ( V_12 = 0 ; V_12 < V_496 -> V_262 ; V_12 ++ ) {
if ( ! F_174 ( & ( V_496 -> V_260 [ V_12 ] ) ,
& ( V_497 -> V_260 [ V_12 ] ) ) ) {
* V_495 = false ;
return 0 ;
}
}
* V_495 = ( ( V_494 -> V_147 == V_34 -> V_147 ) && ( V_494 -> V_149 == V_34 -> V_149 ) ) ;
* V_495 &= ( ( V_494 -> V_165 == V_34 -> V_165 ) && ( V_494 -> V_314 == V_34 -> V_314 ) ) ;
return 0 ;
}
static void F_146 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_68 == NULL )
V_2 -> V_8 . V_68 = & V_498 ;
}
static void F_147 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_9 . V_207 . V_202 . V_499 = V_500 ;
V_2 -> V_8 . V_9 . V_207 . V_202 . V_68 = & V_501 ;
}
