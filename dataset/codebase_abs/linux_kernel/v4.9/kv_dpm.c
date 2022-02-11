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
}
static void F_61 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_32 * V_194 = F_6 ( V_34 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_197 = * V_34 ;
V_38 -> V_198 = * V_194 ;
V_38 -> V_197 . V_36 = & V_38 -> V_198 ;
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
V_65 = F_88 ( V_2 , V_236 ,
V_237 ) ;
if ( V_65 )
return V_65 ;
if ( V_38 -> V_230 )
V_38 -> V_238 = V_21 -> V_13 - 1 ;
else
V_38 -> V_238 = F_86 ( V_2 , V_234 -> V_165 ) ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_239 ) ,
( V_87 * ) & V_38 -> V_238 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
if ( V_38 -> V_230 )
F_85 ( V_2 ,
V_240 ,
( 1 << V_38 -> V_238 ) ) ;
F_81 ( V_2 , true ) ;
} else if ( V_234 -> V_165 == 0 && V_235 -> V_165 > 0 ) {
F_81 ( V_2 , false ) ;
V_65 = F_88 ( V_2 , V_236 ,
V_241 ) ;
if ( V_65 )
return V_65 ;
F_76 ( V_2 , true ) ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_175 ;
int V_65 ;
if ( ! V_227 ) {
if ( V_38 -> V_230 )
V_38 -> V_242 = V_21 -> V_13 - 1 ;
else
V_38 -> V_242 = 0 ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_243 ) ,
( V_87 * ) & V_38 -> V_242 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
if ( V_38 -> V_230 )
F_85 ( V_2 ,
V_244 ,
( 1 << V_38 -> V_242 ) ) ;
}
return F_82 ( V_2 , ! V_227 ) ;
}
static V_87 F_90 ( struct V_1 * V_2 )
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
static void F_91 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_87 V_193 ;
if ( ! V_38 -> V_230 ) {
V_193 = F_90 ( V_2 ) ;
if ( V_193 != V_38 -> V_193 ) {
V_38 -> V_193 = V_193 ;
F_85 ( V_2 ,
V_245 ,
( 1 << V_38 -> V_193 ) ) ;
}
}
}
static int F_92 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_183 ;
int V_65 ;
if ( ! V_227 ) {
if ( V_38 -> V_230 )
V_38 -> V_193 = V_21 -> V_13 - 1 ;
else
V_38 -> V_193 = F_90 ( V_2 ) ;
V_65 = F_23 ( V_2 ,
V_38 -> V_81 +
F_21 ( V_85 , V_246 ) ,
( V_87 * ) & V_38 -> V_193 ,
sizeof( V_87 ) ,
V_38 -> V_80 ) ;
if ( V_65 )
return V_65 ;
if ( V_38 -> V_230 )
F_85 ( V_2 ,
V_245 ,
( 1 << V_38 -> V_193 ) ) ;
}
return F_83 ( V_2 , ! V_227 ) ;
}
static void F_77 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
if ( V_38 -> V_215 == V_227 )
return;
V_38 -> V_215 = V_227 ;
if ( V_227 ) {
if ( V_38 -> V_247 ) {
V_65 = F_88 ( V_2 , V_248 ,
V_237 ) ;
V_65 = F_93 ( V_2 , V_248 ,
V_249 ) ;
}
F_84 ( V_2 , V_227 ) ;
if ( V_38 -> V_247 )
F_18 ( V_2 , V_250 ) ;
} else {
if ( V_38 -> V_247 ) {
F_18 ( V_2 , V_251 ) ;
V_65 = F_93 ( V_2 , V_248 ,
V_252 ) ;
V_65 = F_88 ( V_2 , V_248 ,
V_241 ) ;
}
F_84 ( V_2 , V_227 ) ;
}
}
static void F_76 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 ;
if ( V_38 -> V_216 == V_227 )
return;
V_38 -> V_216 = V_227 ;
if ( V_227 ) {
if ( V_38 -> V_253 ) {
V_65 = F_93 ( V_2 , V_236 ,
V_249 ) ;
F_18 ( V_2 , V_254 ) ;
}
} else {
if ( V_38 -> V_253 ) {
F_18 ( V_2 , V_255 ) ;
V_65 = F_93 ( V_2 , V_236 ,
V_252 ) ;
}
}
}
static void F_75 ( struct V_1 * V_2 , bool V_227 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
if ( V_38 -> V_217 == V_227 )
return;
V_38 -> V_217 = V_227 ;
if ( V_227 ) {
F_89 ( V_2 , true ) ;
if ( V_38 -> V_256 )
F_18 ( V_2 , V_257 ) ;
} else {
if ( V_38 -> V_256 )
F_18 ( V_2 , V_258 ) ;
F_89 ( V_2 , false ) ;
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
F_92 ( V_2 , true ) ;
if ( V_38 -> V_259 )
F_18 ( V_2 , V_260 ) ;
} else {
if ( V_38 -> V_259 )
F_18 ( V_2 , V_261 ) ;
F_92 ( V_2 , false ) ;
}
}
static void F_94 ( struct V_1 * V_2 ,
struct V_33 * V_262 )
{
struct V_32 * V_194 = F_6 ( V_262 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_38 -> V_129 ; V_12 ++ ) {
if ( ( V_21 -> V_14 [ V_12 ] . V_130 >= V_194 -> V_263 [ 0 ] . V_94 ) ||
( V_12 == ( V_38 -> V_129 - 1 ) ) ) {
V_38 -> V_264 = V_12 ;
break;
}
}
for ( V_12 = V_38 -> V_129 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_21 -> V_14 [ V_12 ] . V_130 <= V_194 -> V_263 [ V_194 -> V_265 - 1 ] . V_94 )
break;
}
V_38 -> V_266 = V_12 ;
if ( V_38 -> V_264 > V_38 -> V_266 ) {
if ( ( V_194 -> V_263 [ 0 ] . V_94 - V_21 -> V_14 [ V_38 -> V_266 ] . V_130 ) >
( V_21 -> V_14 [ V_38 -> V_264 ] . V_130 - V_194 -> V_263 [ V_194 -> V_265 - 1 ] . V_94 ) )
V_38 -> V_266 = V_38 -> V_264 ;
else
V_38 -> V_264 = V_38 -> V_266 ;
}
} else {
struct V_19 * V_21 =
& V_38 -> V_104 . V_20 ;
for ( V_12 = 0 ; V_12 < ( int ) V_38 -> V_129 ; V_12 ++ ) {
if ( V_21 -> V_14 [ V_12 ] . V_26 >= V_194 -> V_263 [ 0 ] . V_94 ||
V_12 == ( int ) ( V_38 -> V_129 - 1 ) ) {
V_38 -> V_264 = V_12 ;
break;
}
}
for ( V_12 = V_38 -> V_129 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_21 -> V_14 [ V_12 ] . V_26 <=
V_194 -> V_263 [ V_194 -> V_265 - 1 ] . V_94 )
break;
}
V_38 -> V_266 = V_12 ;
if ( V_38 -> V_264 > V_38 -> V_266 ) {
if ( ( V_194 -> V_263 [ 0 ] . V_94 -
V_21 -> V_14 [ V_38 -> V_266 ] . V_26 ) >
( V_21 -> V_14 [ V_38 -> V_264 ] . V_26 -
V_194 -> V_263 [ V_194 -> V_265 - 1 ] . V_94 ) )
V_38 -> V_266 = V_38 -> V_264 ;
else
V_38 -> V_264 = V_38 -> V_266 ;
}
}
}
static int F_95 ( struct V_1 * V_2 ,
struct V_33 * V_262 )
{
struct V_32 * V_194 = F_6 ( V_262 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
int V_65 = 0 ;
V_87 V_267 ;
if ( V_38 -> V_140 ) {
V_267 = V_194 -> V_268 ?
V_38 -> V_98 [ V_38 -> V_91 ] . V_167 : 0 ;
V_65 = F_23 ( V_2 ,
( V_38 -> V_81 +
F_21 ( V_85 , V_134 ) +
( V_38 -> V_91 * sizeof( V_135 ) ) +
F_21 ( V_135 , V_167 ) ) ,
& V_267 ,
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
if ( V_38 -> V_269 && ! V_38 -> V_270 ) {
V_65 = F_18 ( V_2 , V_271 ) ;
if ( V_65 == 0 )
V_38 -> V_270 = true ;
}
} else {
if ( V_38 -> V_269 && V_38 -> V_270 ) {
V_65 = F_18 ( V_2 , V_272 ) ;
if ( V_65 == 0 )
V_38 -> V_270 = false ;
}
}
return V_65 ;
}
static int F_96 ( struct V_1 * V_2 ,
enum V_273 V_274 )
{
int V_65 ;
if ( V_274 == V_275 ) {
V_65 = F_97 ( V_2 ) ;
if ( V_65 )
return V_65 ;
} else if ( V_274 == V_276 ) {
V_65 = F_44 ( V_2 ) ;
if ( V_65 )
return V_65 ;
} else if ( V_274 == V_277 ) {
V_65 = F_45 ( V_2 ) ;
if ( V_65 )
return V_65 ;
}
V_2 -> V_8 . V_9 . V_278 = V_274 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_33 V_198 = * V_2 -> V_8 . V_9 . V_198 ;
struct V_33 * V_194 = & V_198 ;
F_61 ( V_2 , V_194 ) ;
F_99 ( V_2 ,
& V_38 -> V_197 ,
& V_38 -> V_195 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_33 * V_194 = & V_38 -> V_197 ;
struct V_33 * V_279 = & V_38 -> V_195 ;
int V_65 ;
if ( V_38 -> V_199 ) {
V_65 = F_63 ( V_2 , V_2 -> V_8 . V_9 . V_280 ) ;
if ( V_65 ) {
F_64 ( L_1 ) ;
return V_65 ;
}
}
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 ) {
if ( V_38 -> V_281 ) {
F_94 ( V_2 , V_194 ) ;
F_95 ( V_2 , V_194 ) ;
V_65 = F_101 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_17 ) ;
return V_65 ;
}
F_102 ( V_2 ) ;
F_103 ( V_2 ) ;
F_43 ( V_2 ) ;
F_104 ( V_2 ) ;
F_50 ( V_2 ) ;
F_105 ( V_2 , V_194 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_43 ( V_2 ) ;
F_45 ( V_2 ) ;
V_65 = F_87 ( V_2 , V_194 , V_279 ) ;
if ( V_65 ) {
F_64 ( L_18 ) ;
return V_65 ;
}
F_47 ( V_2 ) ;
if ( V_2 -> V_122 == V_124 )
F_73 ( V_2 , true ) ;
}
} else {
if ( V_38 -> V_281 ) {
F_94 ( V_2 , V_194 ) ;
F_95 ( V_2 , V_194 ) ;
V_65 = F_101 ( V_2 ) ;
if ( V_65 ) {
F_64 ( L_17 ) ;
return V_65 ;
}
F_102 ( V_2 ) ;
F_103 ( V_2 ) ;
F_42 ( V_2 , true ) ;
F_50 ( V_2 ) ;
F_105 ( V_2 , V_194 ) ;
F_42 ( V_2 , false ) ;
F_46 ( V_2 ) ;
V_65 = F_87 ( V_2 , V_194 , V_279 ) ;
if ( V_65 ) {
F_64 ( L_18 ) ;
return V_65 ;
}
F_91 ( V_2 ) ;
F_47 ( V_2 ) ;
F_73 ( V_2 , true ) ;
}
}
return 0 ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_33 * V_194 = & V_38 -> V_197 ;
F_60 ( V_2 , V_194 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
F_3 ( V_2 , true ) ;
F_79 ( V_2 ) ;
F_78 ( V_2 ) ;
}
static void F_108 ( struct V_1 * V_2 ,
struct V_282 * V_21 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
if ( V_38 -> V_104 . V_20 . V_28 > 0 ) {
int V_283 = V_38 -> V_104 . V_20 . V_28 - 1 ;
V_21 -> V_94 =
V_38 -> V_104 . V_20 . V_14 [ V_283 ] . V_26 ;
V_21 -> V_284 =
F_32 ( V_2 ,
V_38 -> V_104 . V_20 . V_14 [ V_283 ] . V_5 ) ;
}
V_21 -> V_285 = V_38 -> V_104 . V_286 [ 0 ] ;
}
static void F_109 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_141 * V_287 =
& V_2 -> V_8 . V_9 . V_10 . V_142 ;
struct V_160 * V_288 =
& V_2 -> V_8 . V_9 . V_10 . V_161 ;
struct V_6 * V_289 =
& V_2 -> V_8 . V_9 . V_10 . V_175 ;
struct V_6 * V_290 =
& V_2 -> V_8 . V_9 . V_10 . V_183 ;
if ( V_287 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_287 -> V_13 ; V_12 ++ )
V_287 -> V_14 [ V_12 ] . V_15 =
F_31 ( V_2 ,
V_287 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_288 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_288 -> V_13 ; V_12 ++ )
V_288 -> V_14 [ V_12 ] . V_15 =
F_31 ( V_2 ,
V_288 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_289 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_289 -> V_13 ; V_12 ++ )
V_289 -> V_14 [ V_12 ] . V_15 =
F_31 ( V_2 ,
V_289 -> V_14 [ V_12 ] . V_15 ) ;
}
if ( V_290 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_290 -> V_13 ; V_12 ++ )
V_290 -> V_14 [ V_12 ] . V_15 =
F_31 ( V_2 ,
V_290 -> V_14 [ V_12 ] . V_15 ) ;
}
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_131 . V_94 = V_38 -> V_104 . V_291 ;
V_38 -> V_131 . V_292 = V_38 -> V_104 . V_293 ;
V_38 -> V_131 . V_294 = 0 ;
V_38 -> V_131 . V_295 = 0 ;
V_38 -> V_131 . V_296 = 1 ;
V_38 -> V_131 . V_297 = 0 ;
V_38 -> V_131 . V_298 = 0 ;
V_38 -> V_131 . V_299 = 0 ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_65 ;
T_1 V_300 , V_12 ;
V_65 = F_111 ( V_2 , & V_300 ) ;
if ( V_65 )
return V_65 ;
for ( V_12 = V_136 - 1 ; V_12 > 0 ; V_12 -- ) {
if ( V_300 & ( 1 << V_12 ) )
break;
}
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 )
return F_85 ( V_2 , V_301 , V_12 ) ;
else
return F_112 ( V_2 , V_12 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_65 ;
T_1 V_300 , V_12 ;
V_65 = F_111 ( V_2 , & V_300 ) ;
if ( V_65 )
return V_65 ;
for ( V_12 = 0 ; V_12 < V_136 ; V_12 ++ ) {
if ( V_300 & ( 1 << V_12 ) )
break;
}
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 )
return F_85 ( V_2 , V_301 , V_12 ) ;
else
return F_112 ( V_2 , V_12 ) ;
}
static V_87 F_113 ( struct V_1 * V_2 ,
T_1 V_94 , T_1 V_302 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
T_1 V_303 ;
T_1 V_304 = F_114 ( V_302 , ( T_1 ) V_305 ) ;
if ( V_94 < V_304 )
return 0 ;
if ( ! V_38 -> V_306 )
return 0 ;
for ( V_12 = V_307 ; V_12 > 0 ; V_12 -- ) {
V_303 = V_94 >> V_12 ;
if ( V_303 >= V_304 )
break;
}
return ( V_87 ) V_12 ;
}
static int F_115 ( struct V_1 * V_2 , int * V_308 )
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
* V_308 = V_12 ;
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
* V_308 = V_12 ;
return 0 ;
}
}
}
* V_308 = 0 ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_33 * V_262 ,
struct V_33 * V_309 )
{
struct V_32 * V_35 = F_6 ( V_262 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_310 = 10000 ;
T_1 V_94 , V_285 = 0 ;
int V_12 , V_308 ;
bool V_311 ;
struct V_6 * V_21 =
& V_2 -> V_8 . V_9 . V_10 . V_11 ;
T_1 V_312 = 0 ;
struct V_282 * V_313 =
& V_2 -> V_8 . V_9 . V_10 . V_314 ;
if ( V_262 -> V_315 ) {
V_262 -> V_165 = V_2 -> V_8 . V_9 . V_316 [ V_2 -> V_8 . V_9 . V_163 ] . V_165 ;
V_262 -> V_317 = V_2 -> V_8 . V_9 . V_316 [ V_2 -> V_8 . V_9 . V_163 ] . V_317 ;
} else {
V_262 -> V_165 = 0 ;
V_262 -> V_317 = 0 ;
}
V_285 = V_313 -> V_285 ;
V_94 = V_310 ;
if ( V_38 -> V_230 ) {
V_312 = ( V_313 -> V_94 * 75 ) / 100 ;
for ( V_12 = V_21 -> V_13 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_312 >= V_21 -> V_14 [ V_12 ] . V_130 ) {
V_312 = V_21 -> V_14 [ V_12 ] . V_130 ;
break;
}
}
if ( V_12 > 0 )
V_312 = V_21 -> V_14 [ 0 ] . V_130 ;
V_94 = V_312 ;
}
if ( V_262 -> V_315 ) {
if ( V_94 < V_2 -> V_8 . V_9 . V_316 [ V_2 -> V_8 . V_9 . V_163 ] . V_94 )
V_94 = V_2 -> V_8 . V_9 . V_316 [ V_2 -> V_8 . V_9 . V_163 ] . V_94 ;
}
V_35 -> V_268 = true ;
for ( V_12 = 0 ; V_12 < V_35 -> V_265 ; V_12 ++ ) {
if ( V_35 -> V_263 [ V_12 ] . V_94 < V_94 )
V_35 -> V_263 [ V_12 ] . V_94 = V_94 ;
}
if ( V_21 && V_21 -> V_13 ) {
for ( V_12 = 0 ; V_12 < V_35 -> V_265 ; V_12 ++ ) {
if ( V_38 -> V_144 &&
( V_38 -> V_144 <
F_31 ( V_2 , V_35 -> V_263 [ V_12 ] . V_292 ) ) ) {
F_115 ( V_2 , & V_308 ) ;
V_35 -> V_263 [ V_12 ] . V_94 = V_21 -> V_14 [ V_308 ] . V_130 ;
}
}
} else {
struct V_19 * V_21 =
& V_38 -> V_104 . V_20 ;
for ( V_12 = 0 ; V_12 < V_35 -> V_265 ; V_12 ++ ) {
if ( V_38 -> V_144 &&
( V_38 -> V_144 <
F_31 ( V_2 , V_35 -> V_263 [ V_12 ] . V_292 ) ) ) {
F_115 ( V_2 , & V_308 ) ;
V_35 -> V_263 [ V_12 ] . V_94 = V_21 -> V_14 [ V_308 ] . V_26 ;
}
}
}
if ( V_38 -> V_230 ) {
for ( V_12 = 0 ; V_12 < V_35 -> V_265 ; V_12 ++ ) {
V_35 -> V_263 [ V_12 ] . V_94 = V_312 ;
}
}
V_38 -> V_318 = V_262 -> V_149 || V_262 -> V_147 ||
V_262 -> V_165 || V_262 -> V_317 ;
if ( ( V_262 -> V_319 & V_320 ) ==
V_321 )
V_38 -> V_322 = true ;
else
V_38 -> V_322 = false ;
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 ) {
V_35 -> V_323 = 0x1 ;
V_35 -> V_324 = 0x0 ;
V_35 -> V_325 = 0x1 ;
V_35 -> V_326 = 0x0 ;
} else {
V_35 -> V_323 = 0x3 ;
V_35 -> V_324 = 0x0 ;
V_35 -> V_325 = 0x3 ;
V_35 -> V_326 = 0x0 ;
if ( V_38 -> V_104 . V_327 ) {
V_311 = ( V_285 >= V_38 -> V_104 . V_286 [ 3 ] ) ||
V_38 -> V_318 || ( V_2 -> V_8 . V_9 . V_328 >= 3 ) ||
V_38 -> V_329 ;
V_35 -> V_323 = V_311 ? 0x2 : 0x3 ;
V_35 -> V_324 = 0x2 ;
V_35 -> V_325 = V_311 ? 0x2 : 0x3 ;
V_35 -> V_326 = 0x2 ;
}
}
}
static void F_116 ( struct V_1 * V_2 ,
T_1 V_93 , bool V_18 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_38 -> V_98 [ V_93 ] . V_330 = V_18 ? 1 : 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_331 = 10000 ;
T_1 V_12 ;
if ( V_38 -> V_264 > V_38 -> V_266 )
return - V_45 ;
for ( V_12 = V_38 -> V_264 ; V_12 <= V_38 -> V_266 ; V_12 ++ ) {
V_38 -> V_98 [ V_12 ] . V_332 =
F_113 ( V_2 ,
F_117 ( V_38 -> V_98 [ V_12 ] . V_101 ) ,
V_331 ) ;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
bool V_311 ;
struct V_282 * V_313 =
& V_2 -> V_8 . V_9 . V_10 . V_314 ;
T_1 V_285 = V_313 -> V_285 ;
if ( V_38 -> V_264 > V_38 -> V_266 )
return - V_45 ;
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 ) {
for ( V_12 = V_38 -> V_264 ; V_12 <= V_38 -> V_266 ; V_12 ++ ) {
V_38 -> V_98 [ V_12 ] . V_333 = 1 ;
V_38 -> V_98 [ V_12 ] . V_334 = 0 ;
V_38 -> V_98 [ V_12 ] . V_335 = 0 ;
}
if ( ! V_38 -> V_104 . V_327 )
return 0 ;
V_311 = ( ( V_285 >= V_38 -> V_104 . V_286 [ 3 ] ) ||
( V_2 -> V_8 . V_9 . V_328 >= 3 ) || V_38 -> V_318 ) ;
if ( V_311 ) {
for ( V_12 = V_38 -> V_264 ; V_12 <= V_38 -> V_266 ; V_12 ++ )
V_38 -> V_98 [ V_12 ] . V_333 = 0 ;
} else {
if ( V_38 -> V_322 )
V_38 -> V_98 [ 0 ] . V_334 = 1 ;
V_38 -> V_98 [ 1 ] . V_333 = 0 ;
V_38 -> V_98 [ 2 ] . V_333 = 0 ;
V_38 -> V_98 [ 3 ] . V_333 = 0 ;
V_38 -> V_98 [ 4 ] . V_333 = 0 ;
}
} else {
for ( V_12 = V_38 -> V_264 ; V_12 <= V_38 -> V_266 ; V_12 ++ ) {
V_38 -> V_98 [ V_12 ] . V_333 = 1 ;
V_38 -> V_98 [ V_12 ] . V_334 = 0 ;
V_38 -> V_98 [ V_12 ] . V_335 = 0 ;
}
if ( V_38 -> V_104 . V_327 && V_38 -> V_322 ) {
V_38 -> V_98 [ V_38 -> V_264 ] . V_335 = 0x28 ;
V_38 -> V_98 [ V_38 -> V_264 ] . V_333 = 0 ;
if ( V_38 -> V_264 != V_38 -> V_266 )
V_38 -> V_98 [ V_38 -> V_264 ] . V_334 = 1 ;
}
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
if ( V_38 -> V_264 > V_38 -> V_266 )
return - V_45 ;
for ( V_12 = V_38 -> V_264 ; V_12 <= V_38 -> V_266 ; V_12 ++ )
V_38 -> V_98 [ V_12 ] . V_336 = ( V_12 == V_38 -> V_266 ) ? 1 : 0 ;
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
F_116 ( V_2 , V_12 , true ) ;
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
F_116 ( V_2 , V_12 , true ) ;
V_38 -> V_129 ++ ;
}
}
for ( V_12 = 0 ; V_12 < V_136 ; V_12 ++ )
F_36 ( V_2 , V_12 , false ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 ;
for ( V_12 = 0 ; V_12 < V_136 ; V_12 ++ ) {
if ( V_12 >= V_38 -> V_264 && V_12 <= V_38 -> V_266 )
F_36 ( V_2 , V_12 , true ) ;
}
}
static int F_112 ( struct V_1 * V_2 , T_1 V_274 )
{
T_1 V_337 = ( 1 << V_274 ) ;
return F_85 ( V_2 ,
V_338 ,
V_337 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_12 , V_337 = 0 ;
for ( V_12 = V_38 -> V_264 ; V_12 <= V_38 -> V_266 ; V_12 ++ )
V_337 |= ( 1 << V_12 ) ;
return F_85 ( V_2 ,
V_338 ,
V_337 ) ;
}
static void F_105 ( struct V_1 * V_2 ,
struct V_33 * V_262 )
{
struct V_32 * V_194 = F_6 ( V_262 ) ;
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_339 ;
if ( V_2 -> V_122 == V_123 || V_2 -> V_122 == V_124 )
return;
if ( V_38 -> V_104 . V_327 ) {
V_339 = F_9 ( V_340 ) ;
V_339 &= ~ ( V_341 |
V_342 |
V_343 |
V_344 ) ;
V_339 |= ( V_194 -> V_323 << V_345 ) |
( V_194 -> V_324 << V_346 ) |
( V_194 -> V_325 << V_347 ) |
( V_194 -> V_326 << V_348 ) ;
F_12 ( V_340 , V_339 ) ;
}
}
static int F_69 ( struct V_1 * V_2 ,
int V_349 , int V_350 )
{
int V_351 = 0 * 1000 ;
int V_352 = 255 * 1000 ;
T_1 V_76 ;
if ( V_351 < V_349 )
V_351 = V_349 ;
if ( V_352 > V_350 )
V_352 = V_350 ;
if ( V_352 < V_351 ) {
F_64 ( L_19 , V_351 , V_352 ) ;
return - V_45 ;
}
V_76 = F_9 ( V_353 ) ;
V_76 &= ~ ( V_354 |
V_355 ) ;
V_76 |= ( ( 49 + ( V_352 / 1000 ) ) << V_356 ) |
( ( 49 + ( V_351 / 1000 ) ) << V_357 ) ;
F_12 ( V_353 , V_76 ) ;
V_2 -> V_8 . V_9 . V_207 . V_349 = V_351 ;
V_2 -> V_8 . V_9 . V_207 . V_350 = V_352 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_358 * V_359 = & V_2 -> V_359 ;
int V_93 = F_119 ( V_360 , V_361 ) ;
union V_362 * V_362 ;
V_87 V_363 , V_364 ;
T_3 V_365 ;
int V_12 ;
if ( F_120 ( V_359 -> V_366 , V_93 , NULL ,
& V_363 , & V_364 , & V_365 ) ) {
V_362 = (union V_362 * ) ( V_359 -> V_366 -> V_367 +
V_365 ) ;
if ( V_364 != 8 ) {
F_64 ( L_20 , V_363 , V_364 ) ;
return - V_45 ;
}
V_38 -> V_104 . V_291 = F_121 ( V_362 -> V_368 . V_369 ) ;
V_38 -> V_104 . V_370 = F_121 ( V_362 -> V_368 . V_371 ) ;
V_38 -> V_104 . V_293 =
F_122 ( V_362 -> V_368 . V_372 ) ;
if ( V_362 -> V_368 . V_373 == 0 )
V_38 -> V_104 . V_374 = 203 ;
else
V_38 -> V_104 . V_374 = V_362 -> V_368 . V_373 ;
if ( V_362 -> V_368 . V_375 == 0 )
V_38 -> V_104 . V_376 = 5 ;
else
V_38 -> V_104 . V_376 = V_362 -> V_368 . V_375 ;
if ( V_38 -> V_104 . V_374 <= V_38 -> V_104 . V_376 ) {
F_64 ( L_21 ) ;
}
if ( F_121 ( V_362 -> V_368 . V_377 ) & ( 1 << 3 ) )
V_38 -> V_104 . V_327 = true ;
else
V_38 -> V_104 . V_327 = false ;
for ( V_12 = 0 ; V_12 < V_378 ; V_12 ++ ) {
V_38 -> V_104 . V_286 [ V_12 ] =
F_121 ( V_362 -> V_368 . V_379 [ V_12 ] ) ;
V_38 -> V_104 . V_380 [ V_12 ] =
F_121 ( V_362 -> V_368 . V_381 [ V_12 ] ) ;
}
if ( F_121 ( V_362 -> V_368 . V_382 ) &
V_383 )
V_38 -> V_140 = true ;
F_4 ( V_2 ,
& V_38 -> V_104 . V_20 ,
V_362 -> V_368 . V_384 ) ;
F_5 ( V_2 ,
& V_38 -> V_104 . V_4 ,
V_362 -> V_368 . V_384 ) ;
F_108 ( V_2 ,
& V_2 -> V_8 . V_9 . V_10 . V_314 ) ;
}
return 0 ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_32 * V_35 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
V_35 -> V_265 = 1 ;
V_35 -> V_263 [ 0 ] = V_38 -> V_131 ;
}
static void F_124 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_385 * V_386 ,
V_87 V_387 )
{
struct V_32 * V_35 = F_6 ( V_34 ) ;
V_34 -> V_388 = F_121 ( V_386 -> V_389 ) ;
V_34 -> V_319 = F_122 ( V_386 -> V_390 ) ;
V_34 -> V_391 = F_122 ( V_386 -> V_392 ) ;
if ( V_393 < V_387 ) {
V_34 -> V_147 = F_121 ( V_386 -> V_394 ) ;
V_34 -> V_149 = F_121 ( V_386 -> V_395 ) ;
} else {
V_34 -> V_147 = 0 ;
V_34 -> V_149 = 0 ;
}
if ( V_34 -> V_319 & V_396 ) {
V_2 -> V_8 . V_9 . V_201 = V_34 ;
F_123 ( V_2 , V_35 ) ;
}
if ( V_34 -> V_319 & V_397 )
V_2 -> V_8 . V_9 . V_398 = V_34 ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_33 * V_34 , int V_93 ,
union V_399 * V_400 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_32 * V_35 = F_6 ( V_34 ) ;
struct V_401 * V_402 = & V_35 -> V_263 [ V_93 ] ;
T_1 V_94 ;
V_94 = F_122 ( V_400 -> V_403 . V_404 ) ;
V_94 |= V_400 -> V_403 . V_405 << 16 ;
V_402 -> V_94 = V_94 ;
V_402 -> V_292 = V_400 -> V_403 . V_406 ;
V_35 -> V_265 = V_93 + 1 ;
if ( V_38 -> V_306 ) {
V_402 -> V_294 = 5 ;
V_402 -> V_295 = 5 ;
}
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_358 * V_359 = & V_2 -> V_359 ;
struct V_385 * V_386 ;
union V_407 * V_408 ;
int V_12 , V_29 , V_409 , V_410 , V_411 ;
union V_399 * V_400 ;
struct V_412 * V_413 ;
struct V_414 * V_415 ;
struct V_416 * V_417 ;
union V_418 * V_418 ;
int V_93 = F_119 ( V_360 , V_419 ) ;
T_3 V_365 ;
V_87 V_363 , V_364 ;
V_87 * V_420 ;
struct V_32 * V_35 ;
if ( ! F_120 ( V_359 -> V_366 , V_93 , NULL ,
& V_363 , & V_364 , & V_365 ) )
return - V_45 ;
V_418 = (union V_418 * ) ( V_359 -> V_366 -> V_367 + V_365 ) ;
F_127 ( V_2 ) ;
V_413 = (struct V_412 * )
( V_359 -> V_366 -> V_367 + V_365 +
F_122 ( V_418 -> V_421 . V_422 ) ) ;
V_415 = (struct V_414 * )
( V_359 -> V_366 -> V_367 + V_365 +
F_122 ( V_418 -> V_421 . V_423 ) ) ;
V_417 = (struct V_416 * )
( V_359 -> V_366 -> V_367 + V_365 +
F_122 ( V_418 -> V_421 . V_424 ) ) ;
V_2 -> V_8 . V_9 . V_35 = F_128 ( sizeof( struct V_33 ) *
V_413 -> V_425 , V_426 ) ;
if ( ! V_2 -> V_8 . V_9 . V_35 )
return - V_427 ;
V_420 = ( V_87 * ) V_413 -> V_428 ;
for ( V_12 = 0 ; V_12 < V_413 -> V_425 ; V_12 ++ ) {
V_87 * V_283 ;
V_408 = (union V_407 * ) V_420 ;
V_410 = V_408 -> V_429 . V_430 ;
V_386 = (struct V_385 * )
& V_417 -> V_431 [ V_410 ] ;
V_35 = F_128 ( sizeof( struct V_32 ) , V_426 ) ;
if ( V_35 == NULL ) {
F_129 ( V_2 -> V_8 . V_9 . V_35 ) ;
return - V_427 ;
}
V_2 -> V_8 . V_9 . V_35 [ V_12 ] . V_36 = V_35 ;
V_409 = 0 ;
V_283 = ( V_87 * ) & V_408 -> V_429 . V_432 [ 0 ] ;
for ( V_29 = 0 ; V_29 < V_408 -> V_429 . V_433 ; V_29 ++ ) {
V_411 = V_283 [ V_29 ] ;
if ( V_411 >= V_415 -> V_425 )
continue;
if ( V_409 >= V_24 )
break;
V_400 = (union V_399 * )
( ( V_87 * ) & V_415 -> V_434 [ 0 ] +
( V_411 * V_415 -> V_435 ) ) ;
F_125 ( V_2 ,
& V_2 -> V_8 . V_9 . V_35 [ V_12 ] , V_409 ,
V_400 ) ;
V_409 ++ ;
}
F_124 ( V_2 , & V_2 -> V_8 . V_9 . V_35 [ V_12 ] ,
V_386 ,
V_417 -> V_435 ) ;
V_420 += 2 + V_408 -> V_429 . V_433 ;
}
V_2 -> V_8 . V_9 . V_436 = V_413 -> V_425 ;
for ( V_12 = 0 ; V_12 < V_437 ; V_12 ++ ) {
T_1 V_94 ;
V_411 = V_2 -> V_8 . V_9 . V_316 [ V_12 ] . V_438 ;
V_400 = (union V_399 * )
& V_415 -> V_434 [ V_411 * V_415 -> V_435 ] ;
V_94 = F_122 ( V_400 -> V_403 . V_404 ) ;
V_94 |= V_400 -> V_403 . V_405 << 16 ;
V_2 -> V_8 . V_9 . V_316 [ V_12 ] . V_94 = V_94 ;
V_2 -> V_8 . V_9 . V_316 [ V_12 ] . V_285 = 0 ;
}
return 0 ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_65 , V_12 ;
V_38 = F_128 ( sizeof( struct V_37 ) , V_426 ) ;
if ( V_38 == NULL )
return - V_427 ;
V_2 -> V_8 . V_9 . V_39 = V_38 ;
V_65 = F_131 ( V_2 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_132 ( V_2 ) ;
if ( V_65 )
return V_65 ;
for ( V_12 = 0 ; V_12 < V_24 ; V_12 ++ )
V_38 -> V_109 [ V_12 ] = V_439 ;
V_38 -> V_80 = V_440 ;
V_38 -> V_269 = true ;
V_38 -> V_441 = true ;
V_38 -> V_72 = true ;
V_38 -> V_442 = false ;
if ( V_38 -> V_442 ) {
V_38 -> V_53 = true ;
V_38 -> V_56 = true ;
V_38 -> V_59 = true ;
V_38 -> V_62 = true ;
}
if ( V_443 )
V_38 -> V_306 = true ;
else
V_38 -> V_306 = false ;
V_38 -> V_200 = true ;
V_38 -> V_329 = false ;
if ( V_444 == 0 )
V_38 -> V_199 = false ;
else
V_38 -> V_199 = true ;
V_38 -> V_107 = 0 ;
V_38 -> V_127 = false ;
V_38 -> V_210 = false ;
V_38 -> V_247 = ( V_2 -> V_445 & V_446 ) ? true : false ;
V_38 -> V_229 = true ;
V_38 -> V_253 = ( V_2 -> V_445 & V_447 ) ? true : false ;
V_38 -> V_256 = ( V_2 -> V_445 & V_448 ) ? true : false ;
V_38 -> V_259 = ( V_2 -> V_445 & V_449 ) ? true : false ;
V_38 -> V_230 = false ;
V_65 = F_118 ( V_2 ) ;
if ( V_65 )
return V_65 ;
F_109 ( V_2 ) ;
F_110 ( V_2 ) ;
V_65 = F_126 ( V_2 ) ;
if ( V_65 )
return V_65 ;
V_38 -> V_281 = true ;
return 0 ;
}
static void
F_133 ( struct V_1 * V_2 ,
struct V_450 * V_451 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
T_1 V_452 =
( F_9 ( V_453 ) &
V_454 ) >>
V_455 ;
T_1 V_94 , V_76 ;
T_3 V_284 ;
if ( V_452 >= V_456 ) {
F_134 ( V_451 , L_22 , V_452 ) ;
} else {
V_94 = F_117 ( V_38 -> V_98 [ V_452 ] . V_101 ) ;
V_76 = ( F_9 ( V_457 ) &
V_458 ) >>
V_459 ;
V_284 = F_31 ( V_2 , ( T_3 ) V_76 ) ;
F_134 ( V_451 , L_23 , V_38 -> V_215 ? L_24 : L_25 ) ;
F_134 ( V_451 , L_26 , V_38 -> V_216 ? L_24 : L_25 ) ;
F_134 ( V_451 , L_27 ,
V_452 , V_94 , V_284 ) ;
}
}
static void
F_135 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_12 ;
struct V_32 * V_35 = F_6 ( V_34 ) ;
F_136 ( V_34 -> V_319 , V_34 -> V_391 ) ;
F_137 ( V_34 -> V_388 ) ;
F_138 ( L_28 , V_34 -> V_147 , V_34 -> V_149 ) ;
for ( V_12 = 0 ; V_12 < V_35 -> V_265 ; V_12 ++ ) {
struct V_401 * V_402 = & V_35 -> V_263 [ V_12 ] ;
F_138 ( L_29 ,
V_12 , V_402 -> V_94 ,
F_31 ( V_2 , V_402 -> V_292 ) ) ;
}
F_139 ( V_2 , V_34 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_8 . V_9 . V_436 ; V_12 ++ ) {
F_129 ( V_2 -> V_8 . V_9 . V_35 [ V_12 ] . V_36 ) ;
}
F_129 ( V_2 -> V_8 . V_9 . V_35 ) ;
F_129 ( V_2 -> V_8 . V_9 . V_39 ) ;
F_141 ( V_2 ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
}
static T_1 F_143 ( struct V_1 * V_2 , bool V_460 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
struct V_32 * V_461 = F_6 ( & V_38 -> V_197 ) ;
if ( V_460 )
return V_461 -> V_263 [ 0 ] . V_94 ;
else
return V_461 -> V_263 [ V_461 -> V_265 - 1 ] . V_94 ;
}
static T_1 F_144 ( struct V_1 * V_2 , bool V_460 )
{
struct V_37 * V_38 = F_7 ( V_2 ) ;
return V_38 -> V_104 . V_370 ;
}
static int F_145 ( struct V_1 * V_2 )
{
T_1 V_303 ;
int V_462 = 0 ;
V_303 = F_9 ( 0xC0300E0C ) ;
if ( V_303 )
V_462 = ( V_303 / 8 ) - 49 ;
else
V_462 = 0 ;
V_462 = V_462 * 1000 ;
return V_462 ;
}
static int F_146 ( void * V_463 )
{
struct V_1 * V_2 = (struct V_1 * ) V_463 ;
F_147 ( V_2 ) ;
F_148 ( V_2 ) ;
return 0 ;
}
static int F_149 ( void * V_463 )
{
struct V_1 * V_2 = (struct V_1 * ) V_463 ;
int V_65 ;
if ( ! V_464 )
return 0 ;
V_65 = F_150 ( V_2 ) ;
if ( V_65 )
return V_65 ;
F_74 ( V_2 , true ) ;
F_75 ( V_2 , true ) ;
F_76 ( V_2 , true ) ;
F_77 ( V_2 , true ) ;
return 0 ;
}
static int F_151 ( void * V_463 )
{
int V_65 ;
struct V_1 * V_2 = (struct V_1 * ) V_463 ;
V_65 = F_152 ( V_2 , 230 , & V_2 -> V_8 . V_9 . V_207 . V_202 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_152 ( V_2 , 231 , & V_2 -> V_8 . V_9 . V_207 . V_202 ) ;
if ( V_65 )
return V_65 ;
V_2 -> V_8 . V_9 . V_465 = V_466 ;
V_2 -> V_8 . V_9 . V_467 = V_466 ;
V_2 -> V_8 . V_9 . V_278 = V_277 ;
V_2 -> V_8 . V_468 = V_2 -> clock . V_468 ;
V_2 -> V_8 . V_469 = V_2 -> clock . V_469 ;
V_2 -> V_8 . V_470 = V_2 -> clock . V_468 ;
V_2 -> V_8 . V_471 = V_2 -> clock . V_469 ;
V_2 -> V_8 . V_204 = V_472 ;
if ( V_464 == 0 )
return 0 ;
F_153 ( & V_2 -> V_8 . V_9 . V_207 . V_473 , V_474 ) ;
F_154 ( & V_2 -> V_8 . V_475 ) ;
V_65 = F_130 ( V_2 ) ;
if ( V_65 )
goto V_476;
V_2 -> V_8 . V_9 . V_196 = V_2 -> V_8 . V_9 . V_198 = V_2 -> V_8 . V_9 . V_201 ;
if ( V_464 == 1 )
F_155 ( V_2 ) ;
F_156 ( & V_2 -> V_8 . V_475 ) ;
F_157 ( L_30 ) ;
return 0 ;
V_476:
F_140 ( V_2 ) ;
F_156 ( & V_2 -> V_8 . V_475 ) ;
F_64 ( L_31 ) ;
return V_65 ;
}
static int F_158 ( void * V_463 )
{
struct V_1 * V_2 = (struct V_1 * ) V_463 ;
F_159 ( & V_2 -> V_8 . V_9 . V_207 . V_473 ) ;
F_154 ( & V_2 -> V_8 . V_475 ) ;
F_160 ( V_2 ) ;
F_140 ( V_2 ) ;
F_156 ( & V_2 -> V_8 . V_475 ) ;
return 0 ;
}
static int F_161 ( void * V_463 )
{
int V_65 ;
struct V_1 * V_2 = (struct V_1 * ) V_463 ;
F_154 ( & V_2 -> V_8 . V_475 ) ;
F_107 ( V_2 ) ;
V_65 = F_65 ( V_2 ) ;
if ( V_65 )
V_2 -> V_8 . V_477 = false ;
else
V_2 -> V_8 . V_477 = true ;
F_156 ( & V_2 -> V_8 . V_475 ) ;
return V_65 ;
}
static int F_162 ( void * V_463 )
{
struct V_1 * V_2 = (struct V_1 * ) V_463 ;
if ( V_2 -> V_8 . V_477 ) {
F_154 ( & V_2 -> V_8 . V_475 ) ;
F_71 ( V_2 ) ;
F_156 ( & V_2 -> V_8 . V_475 ) ;
}
return 0 ;
}
static int F_163 ( void * V_463 )
{
struct V_1 * V_2 = (struct V_1 * ) V_463 ;
if ( V_2 -> V_8 . V_477 ) {
F_154 ( & V_2 -> V_8 . V_475 ) ;
F_71 ( V_2 ) ;
V_2 -> V_8 . V_9 . V_196 = V_2 -> V_8 . V_9 . V_198 = V_2 -> V_8 . V_9 . V_201 ;
F_156 ( & V_2 -> V_8 . V_475 ) ;
}
return 0 ;
}
static int F_164 ( void * V_463 )
{
int V_65 ;
struct V_1 * V_2 = (struct V_1 * ) V_463 ;
if ( V_2 -> V_8 . V_477 ) {
F_154 ( & V_2 -> V_8 . V_475 ) ;
F_107 ( V_2 ) ;
V_65 = F_65 ( V_2 ) ;
if ( V_65 )
V_2 -> V_8 . V_477 = false ;
else
V_2 -> V_8 . V_477 = true ;
F_156 ( & V_2 -> V_8 . V_475 ) ;
if ( V_2 -> V_8 . V_477 )
F_165 ( V_2 ) ;
}
return 0 ;
}
static bool F_166 ( void * V_463 )
{
return true ;
}
static int F_167 ( void * V_463 )
{
return 0 ;
}
static int F_168 ( void * V_463 )
{
return 0 ;
}
static int F_169 ( struct V_1 * V_2 ,
struct V_478 * V_479 ,
unsigned type ,
enum V_480 V_465 )
{
T_1 V_481 ;
switch ( type ) {
case V_208 :
switch ( V_465 ) {
case V_482 :
V_481 = F_9 ( V_353 ) ;
V_481 &= ~ V_483 ;
F_12 ( V_353 , V_481 ) ;
break;
case V_484 :
V_481 = F_9 ( V_353 ) ;
V_481 |= V_483 ;
F_12 ( V_353 , V_481 ) ;
break;
default:
break;
}
break;
case V_209 :
switch ( V_465 ) {
case V_482 :
V_481 = F_9 ( V_353 ) ;
V_481 &= ~ V_485 ;
F_12 ( V_353 , V_481 ) ;
break;
case V_484 :
V_481 = F_9 ( V_353 ) ;
V_481 |= V_485 ;
F_12 ( V_353 , V_481 ) ;
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
static int F_170 ( struct V_1 * V_2 ,
struct V_478 * V_486 ,
struct V_487 * V_488 )
{
bool V_489 = false ;
if ( V_488 == NULL )
return - V_45 ;
switch ( V_488 -> V_490 ) {
case 230 :
F_171 ( L_32 ) ;
V_2 -> V_8 . V_9 . V_207 . V_491 = false ;
V_489 = true ;
break;
case 231 :
F_171 ( L_33 ) ;
V_2 -> V_8 . V_9 . V_207 . V_491 = true ;
V_489 = true ;
break;
default:
break;
}
if ( V_489 )
F_172 ( & V_2 -> V_8 . V_9 . V_207 . V_473 ) ;
return 0 ;
}
static int F_173 ( void * V_463 ,
enum V_492 V_465 )
{
return 0 ;
}
static int F_174 ( void * V_463 ,
enum V_493 V_465 )
{
return 0 ;
}
static void F_147 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_68 == NULL )
V_2 -> V_8 . V_68 = & V_494 ;
}
static void F_148 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_9 . V_207 . V_202 . V_495 = V_496 ;
V_2 -> V_8 . V_9 . V_207 . V_202 . V_68 = & V_497 ;
}
