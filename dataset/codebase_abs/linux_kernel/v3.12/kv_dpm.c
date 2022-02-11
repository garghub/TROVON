static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
return V_4 ;
}
static struct V_6 * F_2 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = V_8 -> V_10 . V_11 . V_12 ;
return V_9 ;
}
static int F_3 ( struct V_7 * V_8 ,
const struct V_13 * V_14 )
{
const struct V_13 * V_15 = V_14 ;
T_1 V_16 ;
T_1 V_17 = 0 ;
if ( V_15 == NULL )
return - V_18 ;
while ( V_15 -> V_19 != 0xFFFFFFFF ) {
if ( V_15 -> type == V_20 ) {
V_17 |= ( ( V_15 -> V_21 << V_15 -> V_22 ) & V_15 -> V_23 ) ;
} else {
switch ( V_15 -> type ) {
case V_24 :
V_16 = F_4 ( V_15 -> V_19 ) ;
break;
case V_25 :
V_16 = F_5 ( V_15 -> V_19 ) ;
break;
default:
V_16 = F_6 ( V_15 -> V_19 << 2 ) ;
break;
}
V_16 &= ~ V_15 -> V_23 ;
V_16 |= ( ( V_15 -> V_21 << V_15 -> V_22 ) & V_15 -> V_23 ) ;
V_16 |= V_17 ;
V_17 = 0 ;
switch ( V_15 -> type ) {
case V_24 :
F_7 ( V_15 -> V_19 , V_16 ) ;
break;
case V_25 :
F_8 ( V_15 -> V_19 , V_16 ) ;
break;
default:
F_9 ( V_15 -> V_19 << 2 , V_16 ) ;
break;
}
}
V_15 ++ ;
}
return 0 ;
}
static void F_10 ( struct V_7 * V_8 , bool V_26 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_16 ;
if ( V_9 -> V_27 ) {
V_16 = F_5 ( V_28 ) ;
if ( V_26 )
V_16 |= V_29 ;
else
V_16 &= ~ V_29 ;
F_8 ( V_28 , V_16 ) ;
}
if ( V_9 -> V_30 ) {
V_16 = F_5 ( V_31 ) ;
if ( V_26 )
V_16 |= V_29 ;
else
V_16 &= ~ V_29 ;
F_8 ( V_31 , V_16 ) ;
}
if ( V_9 -> V_32 ) {
V_16 = F_5 ( V_33 ) ;
if ( V_26 )
V_16 |= V_29 ;
else
V_16 &= ~ V_29 ;
F_8 ( V_33 , V_16 ) ;
}
if ( V_9 -> V_34 ) {
V_16 = F_5 ( V_35 ) ;
if ( V_26 )
V_16 |= V_29 ;
else
V_16 &= ~ V_29 ;
F_8 ( V_35 , V_16 ) ;
}
}
static int F_11 ( struct V_7 * V_8 , bool V_26 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
if ( V_9 -> V_27 ||
V_9 -> V_30 ||
V_9 -> V_32 ||
V_9 -> V_34 ) {
F_12 ( V_8 ) ;
if ( V_26 ) {
V_36 = F_3 ( V_8 , V_37 ) ;
if ( V_36 ) {
F_13 ( V_8 ) ;
return V_36 ;
}
}
F_10 ( V_8 , V_26 ) ;
F_13 ( V_8 ) ;
}
return 0 ;
}
static int F_14 ( struct V_7 * V_8 , bool V_26 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 = 0 ;
if ( V_9 -> V_38 ) {
if ( V_26 ) {
V_36 = F_15 ( V_8 , V_39 ) ;
if ( V_36 )
V_9 -> V_40 = false ;
else
V_9 -> V_40 = true ;
} else if ( V_9 -> V_40 ) {
F_15 ( V_8 , V_41 ) ;
V_9 -> V_40 = false ;
}
}
return V_36 ;
}
static int F_16 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_42 ;
int V_36 ;
V_36 = F_17 ( V_8 , V_43 +
F_18 ( V_44 , V_45 ) ,
& V_42 , V_9 -> V_46 ) ;
if ( V_36 == 0 )
V_9 -> V_47 = V_42 ;
V_36 = F_17 ( V_8 , V_43 +
F_18 ( V_44 , V_48 ) ,
& V_42 , V_9 -> V_46 ) ;
if ( V_36 == 0 )
V_9 -> V_49 = V_42 ;
return V_36 ;
}
static int F_19 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
V_9 -> V_50 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_52 ) ,
& V_9 -> V_50 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
return V_36 ;
}
static int F_21 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
V_9 -> V_54 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_55 ) ,
& V_9 -> V_54 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
return V_36 ;
}
static int F_22 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_56 ) ,
& V_9 -> V_57 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
return V_36 ;
}
static void F_23 ( struct V_7 * V_8 )
{
F_7 ( V_58 , 0x3FFFC100 ) ;
}
static void F_24 ( struct V_7 * V_8 )
{
F_7 ( V_58 , 0 ) ;
}
static int F_25 ( struct V_7 * V_8 ,
T_1 V_59 , T_1 V_60 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_61 V_62 ;
int V_36 ;
V_36 = F_26 ( V_8 , V_63 ,
V_60 , false , & V_62 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_64 [ V_59 ] . V_65 = ( V_53 ) V_62 . V_66 ;
V_9 -> V_64 [ V_59 ] . V_67 = F_27 ( V_60 ) ;
return 0 ;
}
static T_2 F_28 ( struct V_7 * V_8 ,
T_2 V_68 )
{
return 6200 - ( V_68 * 25 ) ;
}
static T_2 F_29 ( struct V_7 * V_8 ,
T_1 V_69 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_70 = F_30 ( V_8 ,
& V_9 -> V_71 . V_72 ,
V_69 ) ;
return F_28 ( V_8 , ( T_2 ) V_70 ) ;
}
static int F_31 ( struct V_7 * V_8 , T_1 V_59 , T_1 V_73 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_64 [ V_59 ] . V_74 = ( V_53 ) V_9 -> V_75 ;
V_9 -> V_64 [ V_59 ] . V_76 =
F_27 ( F_29 ( V_8 , V_73 ) ) ;
return 0 ;
}
static int F_32 ( struct V_7 * V_8 , T_1 V_59 , T_1 V_77 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_64 [ V_59 ] . V_78 = F_33 ( ( T_2 ) V_77 ) ;
return 0 ;
}
static void F_34 ( struct V_7 * V_8 ,
T_1 V_59 , bool V_26 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_64 [ V_59 ] . V_79 = V_26 ? 1 : 0 ;
}
static void F_35 ( struct V_7 * V_8 )
{
T_1 V_42 = F_4 ( V_80 ) ;
V_42 |= V_81 ;
F_7 ( V_80 , V_42 ) ;
F_36 ( V_8 , true ) ;
}
static void F_37 ( struct V_7 * V_8 )
{
F_36 ( V_8 , false ) ;
}
static void F_38 ( struct V_7 * V_8 )
{
T_1 V_82 = F_4 ( V_83 ) ;
V_82 &= ~ ( V_84 | V_85 ) ;
V_82 |= V_86 ;
F_7 ( V_83 , V_82 ) ;
}
static void F_39 ( struct V_7 * V_8 )
{
T_1 V_82 = F_4 ( V_83 ) ;
V_82 |= ( V_84 | V_85 ) ;
F_7 ( V_83 , V_82 ) ;
}
static int F_40 ( struct V_7 * V_8 , bool V_87 )
{
return F_15 ( V_8 , V_87 ?
V_88 : V_89 ) ;
}
static int F_41 ( struct V_7 * V_8 )
{
return F_42 ( V_8 ) ;
}
static int F_43 ( struct V_7 * V_8 )
{
if ( V_8 -> V_90 == V_91 )
return F_15 ( V_8 , V_92 ) ;
else
return F_44 ( V_8 ) ;
}
static int F_45 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_93 = 0 ;
int V_36 = 0 ;
if ( V_9 -> V_94 ) {
V_93 = F_27 ( V_9 -> V_93 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_95 ) ,
( V_53 * ) & V_93 ,
sizeof( T_1 ) , V_9 -> V_46 ) ;
}
return V_36 ;
}
static int F_46 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_96 ;
struct V_97 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_100 ;
if ( V_98 && V_98 -> V_101 ) {
for ( V_96 = V_9 -> V_102 - 1 ; V_96 > 0 ; V_96 -- ) {
if ( V_98 -> V_103 [ V_96 ] . V_104 == V_9 -> V_105 . V_60 )
break;
}
V_9 -> V_57 = ( V_53 ) V_96 ;
F_34 ( V_8 , V_96 , true ) ;
} else {
struct V_106 * V_98 =
& V_9 -> V_71 . V_107 ;
if ( V_98 -> V_108 == 0 )
return - V_18 ;
for ( V_96 = V_9 -> V_102 - 1 ; V_96 > 0 ; V_96 -- ) {
if ( V_98 -> V_103 [ V_96 ] . V_109 == V_9 -> V_105 . V_60 )
break;
}
V_9 -> V_57 = ( V_53 ) V_96 ;
F_34 ( V_8 , V_96 , true ) ;
}
return 0 ;
}
static int F_47 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
V_9 -> V_110 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_111 ) ,
& V_9 -> V_110 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
return V_36 ;
}
static int F_48 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_112 ) ,
( V_53 * ) & V_9 -> V_64 ,
sizeof( V_113 ) * V_114 ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_115 ) ,
& V_9 -> V_102 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
return V_36 ;
}
static T_1 F_49 ( T_1 V_116 , T_1 V_117 )
{
return ( V_116 >= V_117 ) ? V_116 - V_117 : V_117 - V_116 ;
}
static T_1 F_50 ( struct V_7 * V_8 , T_1 V_104 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_21 ;
if ( V_9 -> V_118 ) {
if ( F_49 ( V_104 , 40000 ) < 200 )
V_21 = 3 ;
else if ( F_49 ( V_104 , 30000 ) < 200 )
V_21 = 2 ;
else if ( F_49 ( V_104 , 20000 ) < 200 )
V_21 = 7 ;
else if ( F_49 ( V_104 , 15000 ) < 200 )
V_21 = 6 ;
else if ( F_49 ( V_104 , 10000 ) < 200 )
V_21 = 8 ;
else
V_21 = 0 ;
} else {
V_21 = 0 ;
}
return V_21 ;
}
static int F_51 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_119 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_120 ;
struct V_61 V_62 ;
int V_36 ;
T_1 V_96 ;
if ( V_98 == NULL || V_98 -> V_101 == 0 )
return 0 ;
V_9 -> V_121 = 0 ;
for ( V_96 = 0 ; V_96 < V_98 -> V_101 ; V_96 ++ ) {
if ( V_9 -> V_122 &&
( V_9 -> V_122 < V_98 -> V_103 [ V_96 ] . V_123 ) )
break;
V_9 -> V_124 [ V_96 ] . V_125 = F_27 ( V_98 -> V_103 [ V_96 ] . V_126 ) ;
V_9 -> V_124 [ V_96 ] . V_127 = F_27 ( V_98 -> V_103 [ V_96 ] . V_128 ) ;
V_9 -> V_124 [ V_96 ] . V_76 = F_33 ( V_98 -> V_103 [ V_96 ] . V_123 ) ;
V_9 -> V_124 [ V_96 ] . V_129 =
( V_53 ) F_50 ( V_8 , V_98 -> V_103 [ V_96 ] . V_126 ) ;
V_9 -> V_124 [ V_96 ] . V_130 =
( V_53 ) F_50 ( V_8 , V_98 -> V_103 [ V_96 ] . V_128 ) ;
V_36 = F_26 ( V_8 , V_63 ,
V_98 -> V_103 [ V_96 ] . V_126 , false , & V_62 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_124 [ V_96 ] . V_131 = ( V_53 ) V_62 . V_66 ;
V_36 = F_26 ( V_8 , V_63 ,
V_98 -> V_103 [ V_96 ] . V_128 , false , & V_62 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_124 [ V_96 ] . V_132 = ( V_53 ) V_62 . V_66 ;
V_9 -> V_121 ++ ;
}
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_133 ) ,
( V_53 * ) & V_9 -> V_121 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_134 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_135 ) ,
& V_9 -> V_134 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_136 ) ,
( V_53 * ) & V_9 -> V_124 ,
sizeof( V_137 ) * V_138 ,
V_9 -> V_46 ) ;
return V_36 ;
}
static int F_52 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
T_1 V_96 ;
struct V_139 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_140 ;
struct V_61 V_62 ;
if ( V_98 == NULL || V_98 -> V_101 == 0 )
return 0 ;
V_9 -> V_141 = 0 ;
for ( V_96 = 0 ; V_96 < V_98 -> V_101 ; V_96 ++ ) {
if ( V_9 -> V_122 &&
V_9 -> V_122 < V_98 -> V_103 [ V_96 ] . V_123 )
break;
V_9 -> V_142 [ V_96 ] . V_143 = F_27 ( V_98 -> V_103 [ V_96 ] . V_144 ) ;
V_9 -> V_142 [ V_96 ] . V_145 = F_33 ( V_98 -> V_103 [ V_96 ] . V_123 ) ;
V_9 -> V_142 [ V_96 ] . V_146 =
( V_53 ) F_50 ( V_8 , V_98 -> V_103 [ V_96 ] . V_144 ) ;
V_36 = F_26 ( V_8 , V_63 ,
V_98 -> V_103 [ V_96 ] . V_144 , false , & V_62 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_142 [ V_96 ] . V_147 = ( V_53 ) V_62 . V_66 ;
V_9 -> V_141 ++ ;
}
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_148 ) ,
( V_53 * ) & V_9 -> V_141 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_149 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_150 ) ,
( V_53 * ) & V_9 -> V_149 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_151 ) ,
( V_53 * ) & V_9 -> V_142 ,
sizeof( V_152 ) * V_153 ,
V_9 -> V_46 ) ;
return V_36 ;
}
static int F_53 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_97 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_154 ;
struct V_61 V_62 ;
int V_36 ;
T_1 V_96 ;
if ( V_98 == NULL || V_98 -> V_101 == 0 )
return 0 ;
V_9 -> V_155 = 0 ;
for ( V_96 = 0 ; V_96 < V_98 -> V_101 ; V_96 ++ ) {
if ( V_9 -> V_122 &&
V_9 -> V_122 < V_98 -> V_103 [ V_96 ] . V_123 )
break;
V_9 -> V_156 [ V_96 ] . V_143 = F_27 ( V_98 -> V_103 [ V_96 ] . V_104 ) ;
V_9 -> V_156 [ V_96 ] . V_145 = F_33 ( V_98 -> V_103 [ V_96 ] . V_123 ) ;
V_9 -> V_156 [ V_96 ] . V_146 =
( V_53 ) F_50 ( V_8 , V_98 -> V_103 [ V_96 ] . V_104 ) ;
V_36 = F_26 ( V_8 , V_63 ,
V_98 -> V_103 [ V_96 ] . V_104 , false , & V_62 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_156 [ V_96 ] . V_147 = ( V_53 ) V_62 . V_66 ;
V_9 -> V_155 ++ ;
}
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_157 ) ,
( V_53 * ) & V_9 -> V_155 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_158 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_159 ) ,
( V_53 * ) & V_9 -> V_158 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_160 ) ,
( V_53 * ) & V_9 -> V_156 ,
sizeof( V_152 ) * V_161 ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
return V_36 ;
}
static int F_54 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_97 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_162 ;
struct V_61 V_62 ;
int V_36 ;
T_1 V_96 ;
if ( V_98 == NULL || V_98 -> V_101 == 0 )
return 0 ;
V_9 -> V_163 = 0 ;
for ( V_96 = 0 ; V_96 < V_98 -> V_101 ; V_96 ++ ) {
V_9 -> V_164 [ V_96 ] . V_143 = F_27 ( V_98 -> V_103 [ V_96 ] . V_104 ) ;
V_9 -> V_164 [ V_96 ] . V_145 = F_33 ( V_98 -> V_103 [ V_96 ] . V_123 ) ;
V_36 = F_26 ( V_8 , V_63 ,
V_98 -> V_103 [ V_96 ] . V_104 , false , & V_62 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_164 [ V_96 ] . V_147 = ( V_53 ) V_62 . V_66 ;
V_9 -> V_163 ++ ;
}
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_165 ) ,
( V_53 * ) & V_9 -> V_163 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_166 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_167 ) ,
( V_53 * ) & V_9 -> V_166 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_168 ) ,
( V_53 * ) & V_9 -> V_164 ,
sizeof( V_152 ) * V_169 ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
return V_36 ;
}
static void F_55 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_96 ;
struct V_97 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_100 ;
if ( V_98 && V_98 -> V_101 ) {
for ( V_96 = 0 ; V_96 < V_9 -> V_102 ; V_96 ++ ) {
if ( V_9 -> V_118 ) {
if ( F_49 ( V_98 -> V_103 [ V_96 ] . V_104 , 40000 ) < 200 )
V_9 -> V_64 [ V_96 ] . V_146 = 3 ;
else if ( F_49 ( V_98 -> V_103 [ V_96 ] . V_104 , 30000 ) < 200 )
V_9 -> V_64 [ V_96 ] . V_146 = 2 ;
else if ( F_49 ( V_98 -> V_103 [ V_96 ] . V_104 , 26600 ) < 200 )
V_9 -> V_64 [ V_96 ] . V_146 = 7 ;
else if ( F_49 ( V_98 -> V_103 [ V_96 ] . V_104 , 20000 ) < 200 )
V_9 -> V_64 [ V_96 ] . V_146 = 6 ;
else if ( F_49 ( V_98 -> V_103 [ V_96 ] . V_104 , 10000 ) < 200 )
V_9 -> V_64 [ V_96 ] . V_146 = 8 ;
else
V_9 -> V_64 [ V_96 ] . V_146 = 0 ;
} else {
V_9 -> V_64 [ V_96 ] . V_146 = 0 ;
}
}
} else {
struct V_106 * V_98 =
& V_9 -> V_71 . V_107 ;
for ( V_96 = 0 ; V_96 < V_9 -> V_102 ; V_96 ++ ) {
if ( V_9 -> V_118 ) {
if ( F_49 ( V_98 -> V_103 [ V_96 ] . V_109 , 40000 ) < 200 )
V_9 -> V_64 [ V_96 ] . V_146 = 3 ;
else if ( F_49 ( V_98 -> V_103 [ V_96 ] . V_109 , 30000 ) < 200 )
V_9 -> V_64 [ V_96 ] . V_146 = 2 ;
else if ( F_49 ( V_98 -> V_103 [ V_96 ] . V_109 , 26600 ) < 200 )
V_9 -> V_64 [ V_96 ] . V_146 = 7 ;
else if ( F_49 ( V_98 -> V_103 [ V_96 ] . V_109 , 20000 ) < 200 )
V_9 -> V_64 [ V_96 ] . V_146 = 6 ;
else if ( F_49 ( V_98 -> V_103 [ V_96 ] . V_109 , 10000 ) < 200 )
V_9 -> V_64 [ V_96 ] . V_146 = 8 ;
else
V_9 -> V_64 [ V_96 ] . V_146 = 0 ;
} else {
V_9 -> V_64 [ V_96 ] . V_146 = 0 ;
}
}
}
}
static int F_56 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_170 : V_171 ) ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_172 = 0xff ;
}
static void F_58 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_1 * V_173 = F_1 ( V_3 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_174 = * V_3 ;
V_9 -> V_175 = * V_173 ;
V_9 -> V_174 . V_5 = & V_9 -> V_175 ;
}
static void F_59 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_1 * V_173 = F_1 ( V_3 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_176 = * V_3 ;
V_9 -> V_177 = * V_173 ;
V_9 -> V_176 . V_5 = & V_9 -> V_177 ;
}
void F_60 ( struct V_7 * V_8 , bool V_26 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
if ( V_9 -> V_178 ) {
V_36 = F_61 ( V_8 , V_26 ) ;
if ( V_36 )
F_62 ( L_1 ) ;
}
}
int F_63 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
F_64 ( V_8 , ( V_179 |
V_180 |
V_181 |
V_182 ) , false ) ;
V_36 = F_16 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_2 ) ;
return V_36 ;
}
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
V_36 = F_46 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_3 ) ;
return V_36 ;
}
F_55 ( V_8 ) ;
V_36 = F_48 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_4 ) ;
return V_36 ;
}
V_36 = F_51 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_5 ) ;
return V_36 ;
}
V_36 = F_52 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_6 ) ;
return V_36 ;
}
V_36 = F_53 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_7 ) ;
return V_36 ;
}
V_36 = F_54 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_8 ) ;
return V_36 ;
}
F_23 ( V_8 ) ;
#if 0
kv_initialize_hardware_cac_manager(rdev);
#endif
F_38 ( V_8 ) ;
if ( V_9 -> V_183 ) {
V_36 = F_47 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_9 ) ;
return V_36 ;
}
}
V_36 = F_19 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_10 ) ;
return V_36 ;
}
V_36 = F_21 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_11 ) ;
return V_36 ;
}
V_36 = F_22 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_12 ) ;
return V_36 ;
}
V_36 = F_56 ( V_8 , true ) ;
if ( V_36 ) {
F_62 ( L_13 ) ;
return V_36 ;
}
F_35 ( V_8 ) ;
V_36 = F_11 ( V_8 , true ) ;
if ( V_36 ) {
F_62 ( L_14 ) ;
return V_36 ;
}
V_36 = F_14 ( V_8 , true ) ;
if ( V_36 ) {
F_62 ( L_15 ) ;
return V_36 ;
}
F_57 ( V_8 ) ;
if ( V_8 -> V_184 . V_185 &&
F_67 ( V_8 -> V_10 . V_186 ) ) {
V_36 = F_68 ( V_8 , V_187 , V_188 ) ;
if ( V_36 ) {
F_62 ( L_16 ) ;
return V_36 ;
}
V_8 -> V_184 . V_189 = true ;
F_69 ( V_8 ) ;
}
V_36 = F_61 ( V_8 , false ) ;
if ( V_36 ) {
F_62 ( L_1 ) ;
return V_36 ;
}
F_70 ( V_8 , true ) ;
F_71 ( V_8 , true ) ;
F_72 ( V_8 , true ) ;
F_73 ( V_8 , true ) ;
F_64 ( V_8 , ( V_179 |
V_180 |
V_181 |
V_182 ) , true ) ;
F_58 ( V_8 , V_8 -> V_10 . V_11 . V_190 ) ;
return V_36 ;
}
void F_74 ( struct V_7 * V_8 )
{
F_64 ( V_8 , ( V_179 |
V_180 |
V_181 |
V_182 ) , false ) ;
F_61 ( V_8 , false ) ;
F_70 ( V_8 , false ) ;
F_71 ( V_8 , false ) ;
F_72 ( V_8 , false ) ;
F_73 ( V_8 , false ) ;
F_14 ( V_8 , false ) ;
F_11 ( V_8 , false ) ;
F_24 ( V_8 ) ;
F_37 ( V_8 ) ;
F_56 ( V_8 , false ) ;
F_39 ( V_8 ) ;
F_58 ( V_8 , V_8 -> V_10 . V_11 . V_190 ) ;
}
static void F_75 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_93 = 0 ;
}
static int F_65 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 = 0 ;
if ( V_9 -> V_191 ) {
T_2 V_42 ;
V_42 = 45 ;
V_9 -> V_192 = F_33 ( V_42 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_193 ) ,
( V_53 * ) & V_9 -> V_192 ,
sizeof( T_2 ) , V_9 -> V_46 ) ;
V_42 = 30 ;
V_9 -> V_194 = F_33 ( V_42 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_195 ) ,
( V_53 * ) & V_9 -> V_194 ,
sizeof( T_2 ) , V_9 -> V_46 ) ;
}
return V_36 ;
}
static void F_76 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_196 = false ;
V_9 -> V_197 = false ;
V_9 -> V_198 = false ;
V_9 -> V_199 = false ;
}
static int F_77 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_200 : V_201 ) ;
}
static int F_78 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_202 : V_203 ) ;
}
static int F_79 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_204 : V_205 ) ;
}
static int F_80 ( struct V_7 * V_8 , bool V_206 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_119 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_120 ;
int V_36 ;
if ( ! V_206 ) {
if ( ! V_9 -> V_207 || V_98 -> V_101 || V_9 -> V_208 )
V_9 -> V_209 = V_98 -> V_101 - 1 ;
else
V_9 -> V_209 = 0 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_210 ) ,
( V_211 * ) & V_9 -> V_209 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_9 -> V_207 ||
V_9 -> V_208 )
F_81 ( V_8 ,
V_212 ,
( 1 << V_9 -> V_209 ) ) ;
}
return F_77 ( V_8 , ! V_206 ) ;
}
static int F_82 ( struct V_7 * V_8 , bool V_206 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_97 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_154 ;
int V_36 ;
if ( ! V_206 ) {
if ( V_9 -> V_208 )
V_9 -> V_213 = V_98 -> V_101 - 1 ;
else
V_9 -> V_213 = 0 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_214 ) ,
( V_53 * ) & V_9 -> V_213 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
if ( V_9 -> V_208 )
F_81 ( V_8 ,
V_215 ,
( 1 << V_9 -> V_213 ) ) ;
}
return F_78 ( V_8 , ! V_206 ) ;
}
static V_53 F_83 ( struct V_7 * V_8 )
{
V_53 V_96 ;
struct V_97 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_162 ;
for ( V_96 = 0 ; V_96 < V_98 -> V_101 ; V_96 ++ ) {
if ( V_98 -> V_103 [ V_96 ] . V_104 >= 0 )
break;
}
if ( V_96 >= V_98 -> V_101 )
V_96 = V_98 -> V_101 - 1 ;
return V_96 ;
}
static void F_84 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_53 V_172 ;
if ( ! V_9 -> V_208 ) {
V_172 = F_83 ( V_8 ) ;
if ( V_172 != V_9 -> V_172 ) {
V_9 -> V_172 = V_172 ;
F_81 ( V_8 ,
V_216 ,
( 1 << V_9 -> V_172 ) ) ;
}
}
}
static int F_85 ( struct V_7 * V_8 , bool V_206 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_97 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_162 ;
int V_36 ;
if ( ! V_206 ) {
if ( V_9 -> V_208 )
V_9 -> V_172 = V_98 -> V_101 - 1 ;
else
V_9 -> V_172 = F_83 ( V_8 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_217 ) ,
( V_53 * ) & V_9 -> V_172 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
if ( V_9 -> V_208 )
F_81 ( V_8 ,
V_216 ,
( 1 << V_9 -> V_172 ) ) ;
}
return F_79 ( V_8 , ! V_206 ) ;
}
void F_73 ( struct V_7 * V_8 , bool V_206 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_196 == V_206 )
return;
V_9 -> V_196 = V_206 ;
if ( V_206 ) {
if ( V_9 -> V_218 ) {
F_86 ( V_8 ) ;
F_64 ( V_8 , V_219 , false ) ;
}
F_80 ( V_8 , V_206 ) ;
if ( V_9 -> V_218 )
F_15 ( V_8 , V_220 ) ;
} else {
if ( V_9 -> V_218 ) {
F_15 ( V_8 , V_221 ) ;
F_87 ( V_8 ) ;
F_88 ( V_8 ) ;
F_64 ( V_8 , V_219 , true ) ;
}
F_80 ( V_8 , V_206 ) ;
}
}
static void F_72 ( struct V_7 * V_8 , bool V_206 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_197 == V_206 )
return;
V_9 -> V_197 = V_206 ;
if ( V_206 ) {
if ( V_9 -> V_222 )
F_15 ( V_8 , V_223 ) ;
} else {
if ( V_9 -> V_222 )
F_15 ( V_8 , V_224 ) ;
}
}
static void F_71 ( struct V_7 * V_8 , bool V_206 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_198 == V_206 )
return;
V_9 -> V_198 = V_206 ;
if ( V_206 ) {
F_82 ( V_8 , true ) ;
if ( V_9 -> V_225 )
F_15 ( V_8 , V_226 ) ;
} else {
if ( V_9 -> V_225 )
F_15 ( V_8 , V_227 ) ;
F_82 ( V_8 , false ) ;
}
}
static void F_70 ( struct V_7 * V_8 , bool V_206 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_199 == V_206 )
return;
if ( V_8 -> V_90 == V_91 )
return;
V_9 -> V_199 = V_206 ;
if ( V_206 ) {
F_85 ( V_8 , true ) ;
if ( V_9 -> V_228 )
F_15 ( V_8 , V_229 ) ;
} else {
if ( V_9 -> V_228 )
F_15 ( V_8 , V_230 ) ;
F_85 ( V_8 , false ) ;
}
}
static void F_89 ( struct V_7 * V_8 ,
struct V_2 * V_231 )
{
struct V_1 * V_173 = F_1 ( V_231 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_96 ;
struct V_97 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_100 ;
if ( V_98 && V_98 -> V_101 ) {
for ( V_96 = 0 ; V_96 < V_9 -> V_102 ; V_96 ++ ) {
if ( ( V_98 -> V_103 [ V_96 ] . V_104 >= V_173 -> V_232 [ 0 ] . V_60 ) ||
( V_96 == ( V_9 -> V_102 - 1 ) ) ) {
V_9 -> V_233 = V_96 ;
break;
}
}
for ( V_96 = V_9 -> V_102 - 1 ; V_96 > 0 ; V_96 -- ) {
if ( V_98 -> V_103 [ V_96 ] . V_104 <= V_173 -> V_232 [ V_173 -> V_234 - 1 ] . V_60 )
break;
}
V_9 -> V_235 = V_96 ;
if ( V_9 -> V_233 > V_9 -> V_235 ) {
if ( ( V_173 -> V_232 [ 0 ] . V_60 - V_98 -> V_103 [ V_9 -> V_235 ] . V_104 ) >
( V_98 -> V_103 [ V_9 -> V_233 ] . V_104 - V_173 -> V_232 [ V_173 -> V_234 - 1 ] . V_60 ) )
V_9 -> V_235 = V_9 -> V_233 ;
else
V_9 -> V_233 = V_9 -> V_235 ;
}
} else {
struct V_106 * V_98 =
& V_9 -> V_71 . V_107 ;
for ( V_96 = 0 ; V_96 < ( int ) V_9 -> V_102 ; V_96 ++ ) {
if ( V_98 -> V_103 [ V_96 ] . V_109 >= V_173 -> V_232 [ 0 ] . V_60 ||
V_96 == ( int ) ( V_9 -> V_102 - 1 ) ) {
V_9 -> V_233 = V_96 ;
break;
}
}
for ( V_96 = V_9 -> V_102 - 1 ; V_96 > 0 ; V_96 -- ) {
if ( V_98 -> V_103 [ V_96 ] . V_109 <=
V_173 -> V_232 [ V_173 -> V_234 - 1 ] . V_60 )
break;
}
V_9 -> V_235 = V_96 ;
if ( V_9 -> V_233 > V_9 -> V_235 ) {
if ( ( V_173 -> V_232 [ 0 ] . V_60 -
V_98 -> V_103 [ V_9 -> V_235 ] . V_109 ) >
( V_98 -> V_103 [ V_9 -> V_233 ] . V_109 -
V_173 -> V_232 [ V_173 -> V_234 - 1 ] . V_60 ) )
V_9 -> V_235 = V_9 -> V_233 ;
else
V_9 -> V_233 = V_9 -> V_235 ;
}
}
}
static int F_90 ( struct V_7 * V_8 ,
struct V_2 * V_231 )
{
struct V_1 * V_173 = F_1 ( V_231 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 = 0 ;
V_53 V_236 ;
if ( V_9 -> V_118 ) {
V_236 = V_173 -> V_237 ?
V_9 -> V_64 [ V_9 -> V_57 ] . V_146 : 0 ;
V_36 = F_20 ( V_8 ,
( V_9 -> V_47 +
F_18 ( V_51 , V_112 ) +
( V_9 -> V_57 * sizeof( V_113 ) ) +
F_18 ( V_113 , V_146 ) ) ,
& V_236 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
}
return V_36 ;
}
static int F_91 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 = 0 ;
if ( V_9 -> V_238 && ! V_9 -> V_239 ) {
V_36 = F_15 ( V_8 , V_240 ) ;
if ( V_36 == 0 )
V_9 -> V_239 = true ;
}
return V_36 ;
}
int F_92 ( struct V_7 * V_8 ,
enum V_241 V_242 )
{
int V_36 ;
if ( V_242 == V_243 ) {
V_36 = F_93 ( V_8 ) ;
if ( V_36 )
return V_36 ;
} else if ( V_242 == V_244 ) {
V_36 = F_42 ( V_8 ) ;
if ( V_36 )
return V_36 ;
} else if ( V_242 == V_245 ) {
V_36 = F_43 ( V_8 ) ;
if ( V_36 )
return V_36 ;
}
V_8 -> V_10 . V_11 . V_246 = V_242 ;
return 0 ;
}
int F_94 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 V_177 = * V_8 -> V_10 . V_11 . V_177 ;
struct V_2 * V_173 = & V_177 ;
F_59 ( V_8 , V_173 ) ;
F_95 ( V_8 ,
& V_9 -> V_176 ,
& V_9 -> V_174 ) ;
return 0 ;
}
int F_96 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_173 = & V_9 -> V_176 ;
int V_36 ;
F_64 ( V_8 , ( V_179 |
V_180 |
V_181 |
V_182 ) , false ) ;
if ( V_9 -> V_178 ) {
V_36 = F_61 ( V_8 , V_8 -> V_10 . V_11 . V_247 ) ;
if ( V_36 ) {
F_62 ( L_1 ) ;
return V_36 ;
}
}
if ( V_8 -> V_90 == V_91 ) {
if ( V_9 -> V_248 ) {
F_89 ( V_8 , V_173 ) ;
F_90 ( V_8 , V_173 ) ;
V_36 = F_97 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_17 ) ;
return V_36 ;
}
F_98 ( V_8 ) ;
F_99 ( V_8 ) ;
F_41 ( V_8 ) ;
F_100 ( V_8 ) ;
F_48 ( V_8 ) ;
F_101 ( V_8 , V_173 ) ;
F_43 ( V_8 ) ;
F_44 ( V_8 ) ;
F_41 ( V_8 ) ;
F_43 ( V_8 ) ;
#if 0
ret = kv_update_vce_dpm(rdev, new_ps, old_ps);
if (ret) {
DRM_ERROR("kv_update_vce_dpm failed\n");
return ret;
}
#endif
F_45 ( V_8 ) ;
}
} else {
if ( V_9 -> V_248 ) {
F_89 ( V_8 , V_173 ) ;
F_90 ( V_8 , V_173 ) ;
V_36 = F_97 ( V_8 ) ;
if ( V_36 ) {
F_62 ( L_17 ) ;
return V_36 ;
}
F_98 ( V_8 ) ;
F_99 ( V_8 ) ;
F_40 ( V_8 , true ) ;
F_48 ( V_8 ) ;
F_101 ( V_8 , V_173 ) ;
F_40 ( V_8 , false ) ;
F_44 ( V_8 ) ;
#if 0
ret = kv_update_vce_dpm(rdev, new_ps, old_ps);
if (ret) {
DRM_ERROR("kv_update_vce_dpm failed\n");
return ret;
}
#endif
F_84 ( V_8 ) ;
F_45 ( V_8 ) ;
F_91 ( V_8 ) ;
}
}
F_64 ( V_8 , ( V_179 |
V_180 |
V_181 |
V_182 ) , true ) ;
return 0 ;
}
void F_102 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_173 = & V_9 -> V_176 ;
F_58 ( V_8 , V_173 ) ;
}
void F_103 ( struct V_7 * V_8 )
{
F_104 ( V_8 , true ) ;
F_76 ( V_8 ) ;
F_75 ( V_8 ) ;
}
void F_105 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_8 -> V_90 == V_91 ) {
F_41 ( V_8 ) ;
F_66 ( V_8 ) ;
F_46 ( V_8 ) ;
F_48 ( V_8 ) ;
F_41 ( V_8 ) ;
F_43 ( V_8 ) ;
} else {
F_66 ( V_8 ) ;
F_46 ( V_8 ) ;
F_40 ( V_8 , true ) ;
F_48 ( V_8 ) ;
F_40 ( V_8 , false ) ;
F_106 ( V_8 , V_9 -> V_57 ) ;
}
}
static void F_107 ( struct V_7 * V_8 ,
struct V_249 * V_98 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_71 . V_107 . V_108 > 0 ) {
int V_250 = V_9 -> V_71 . V_107 . V_108 - 1 ;
V_98 -> V_60 =
V_9 -> V_71 . V_107 . V_103 [ V_250 ] . V_109 ;
V_98 -> V_251 =
F_29 ( V_8 ,
V_9 -> V_71 . V_107 . V_103 [ V_250 ] . V_69 ) ;
}
V_98 -> V_252 = V_9 -> V_71 . V_253 [ 0 ] ;
}
static void F_108 ( struct V_7 * V_8 )
{
int V_96 ;
struct V_119 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_120 ;
if ( V_98 -> V_101 ) {
for ( V_96 = 0 ; V_96 < V_98 -> V_101 ; V_96 ++ )
V_98 -> V_103 [ V_96 ] . V_123 =
F_28 ( V_8 ,
V_98 -> V_103 [ V_96 ] . V_123 ) ;
}
}
static void F_109 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_105 . V_60 = V_9 -> V_71 . V_254 ;
V_9 -> V_105 . V_255 = V_9 -> V_71 . V_256 ;
V_9 -> V_105 . V_257 = 0 ;
V_9 -> V_105 . V_258 = 0 ;
V_9 -> V_105 . V_259 = 1 ;
V_9 -> V_105 . V_260 = 0 ;
V_9 -> V_105 . V_261 = 0 ;
V_9 -> V_105 . V_262 = 0 ;
}
static int F_93 ( struct V_7 * V_8 )
{
int V_36 ;
T_1 V_263 , V_96 ;
V_36 = F_110 ( V_8 , & V_263 ) ;
if ( V_36 )
return V_36 ;
for ( V_96 = V_114 - 1 ; V_96 > 0 ; V_96 -- ) {
if ( V_263 & ( 1 << V_96 ) )
break;
}
if ( V_8 -> V_90 == V_91 )
return F_81 ( V_8 , V_264 , V_96 ) ;
else
return F_106 ( V_8 , V_96 ) ;
}
static int F_42 ( struct V_7 * V_8 )
{
int V_36 ;
T_1 V_263 , V_96 ;
V_36 = F_110 ( V_8 , & V_263 ) ;
if ( V_36 )
return V_36 ;
for ( V_96 = 0 ; V_96 < V_114 ; V_96 ++ ) {
if ( V_263 & ( 1 << V_96 ) )
break;
}
if ( V_8 -> V_90 == V_91 )
return F_81 ( V_8 , V_264 , V_96 ) ;
else
return F_106 ( V_8 , V_96 ) ;
}
static V_53 F_111 ( struct V_7 * V_8 ,
T_1 V_60 , T_1 V_265 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_96 ;
T_1 V_266 ;
T_1 V_267 = ( V_265 > V_268 ) ?
V_265 : V_268 ;
if ( V_60 < V_267 )
return 0 ;
if ( ! V_9 -> V_269 )
return 0 ;
for ( V_96 = V_270 ; V_96 > 0 ; V_96 -- ) {
V_266 = V_60 / F_112 ( V_96 ) ;
if ( V_266 >= V_267 )
break;
}
return ( V_53 ) V_96 ;
}
static int F_113 ( struct V_7 * V_8 , int * V_271 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_97 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_100 ;
int V_96 ;
if ( V_98 && V_98 -> V_101 ) {
for ( V_96 = V_98 -> V_101 - 1 ; V_96 >= 0 ; V_96 -- ) {
if ( V_9 -> V_122 &&
( F_28 ( V_8 , V_98 -> V_103 [ V_96 ] . V_123 ) <=
V_9 -> V_122 ) ) {
* V_271 = V_96 ;
return 0 ;
}
}
} else {
struct V_106 * V_98 =
& V_9 -> V_71 . V_107 ;
for ( V_96 = V_98 -> V_108 - 1 ; V_96 >= 0 ; V_96 -- ) {
if ( V_9 -> V_122 &&
( F_29 ( V_8 , V_98 -> V_103 [ V_96 ] . V_69 ) <=
V_9 -> V_122 ) ) {
* V_271 = V_96 ;
return 0 ;
}
}
}
* V_271 = 0 ;
return 0 ;
}
static void F_95 ( struct V_7 * V_8 ,
struct V_2 * V_231 ,
struct V_2 * V_272 )
{
struct V_1 * V_4 = F_1 ( V_231 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_273 = 10000 ;
T_1 V_60 , V_252 = 0 ;
int V_96 , V_271 ;
bool V_274 ;
struct V_97 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_100 ;
T_1 V_275 = 0 ;
struct V_249 * V_276 =
& V_8 -> V_10 . V_11 . V_99 . V_277 ;
V_252 = V_276 -> V_252 ;
V_60 = V_273 ;
if ( V_9 -> V_208 ) {
V_275 = ( V_276 -> V_60 * 75 ) / 100 ;
for ( V_96 = V_98 -> V_101 - 1 ; V_96 >= 0 ; V_96 ++ ) {
if ( V_275 >= V_98 -> V_103 [ V_96 ] . V_104 ) {
V_275 = V_98 -> V_103 [ V_96 ] . V_104 ;
break;
}
}
if ( V_96 > 0 )
V_275 = V_98 -> V_103 [ 0 ] . V_104 ;
V_60 = V_275 ;
}
V_4 -> V_237 = true ;
for ( V_96 = 0 ; V_96 < V_4 -> V_234 ; V_96 ++ ) {
if ( V_4 -> V_232 [ V_96 ] . V_60 < V_60 )
V_4 -> V_232 [ V_96 ] . V_60 = V_60 ;
}
if ( V_98 && V_98 -> V_101 ) {
for ( V_96 = 0 ; V_96 < V_4 -> V_234 ; V_96 ++ ) {
if ( V_9 -> V_122 &&
( V_9 -> V_122 <
F_28 ( V_8 , V_4 -> V_232 [ V_96 ] . V_255 ) ) ) {
F_113 ( V_8 , & V_271 ) ;
V_4 -> V_232 [ V_96 ] . V_60 = V_98 -> V_103 [ V_271 ] . V_104 ;
}
}
} else {
struct V_106 * V_98 =
& V_9 -> V_71 . V_107 ;
for ( V_96 = 0 ; V_96 < V_4 -> V_234 ; V_96 ++ ) {
if ( V_9 -> V_122 &&
( V_9 -> V_122 <
F_28 ( V_8 , V_4 -> V_232 [ V_96 ] . V_255 ) ) ) {
F_113 ( V_8 , & V_271 ) ;
V_4 -> V_232 [ V_96 ] . V_60 = V_98 -> V_103 [ V_271 ] . V_109 ;
}
}
}
if ( V_9 -> V_208 ) {
for ( V_96 = 0 ; V_96 < V_4 -> V_234 ; V_96 ++ ) {
V_4 -> V_232 [ V_96 ] . V_60 = V_275 ;
}
}
V_9 -> V_278 = V_231 -> V_128 || V_231 -> V_126 ;
if ( ( V_231 -> V_279 & V_280 ) ==
V_281 )
V_9 -> V_282 = true ;
else
V_9 -> V_282 = false ;
if ( V_8 -> V_90 == V_91 ) {
V_4 -> V_283 = 0x1 ;
V_4 -> V_284 = 0x0 ;
V_4 -> V_285 = 0x1 ;
V_4 -> V_286 = 0x0 ;
} else {
V_4 -> V_283 = 0x3 ;
V_4 -> V_284 = 0x0 ;
V_4 -> V_285 = 0x3 ;
V_4 -> V_286 = 0x0 ;
if ( V_9 -> V_71 . V_287 ) {
V_274 = ( V_252 >= V_9 -> V_71 . V_253 [ 3 ] ) ||
V_9 -> V_278 || ( V_8 -> V_10 . V_11 . V_288 >= 3 ) ||
V_9 -> V_289 ;
V_4 -> V_283 = V_274 ? 0x2 : 0x3 ;
V_4 -> V_284 = 0x2 ;
V_4 -> V_285 = V_274 ? 0x2 : 0x3 ;
V_4 -> V_286 = 0x2 ;
}
}
}
static void F_114 ( struct V_7 * V_8 ,
T_1 V_59 , bool V_26 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_64 [ V_59 ] . V_290 = V_26 ? 1 : 0 ;
}
static int F_97 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_291 = 10000 ;
T_1 V_96 ;
if ( V_9 -> V_233 > V_9 -> V_235 )
return - V_18 ;
for ( V_96 = V_9 -> V_233 ; V_96 <= V_9 -> V_235 ; V_96 ++ ) {
V_9 -> V_64 [ V_96 ] . V_292 =
F_111 ( V_8 ,
F_115 ( V_9 -> V_64 [ V_96 ] . V_67 ) ,
V_291 ) ;
}
return 0 ;
}
static int F_98 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_96 ;
bool V_274 ;
struct V_249 * V_276 =
& V_8 -> V_10 . V_11 . V_99 . V_277 ;
T_1 V_252 = V_276 -> V_252 ;
if ( V_9 -> V_233 > V_9 -> V_235 )
return - V_18 ;
if ( V_8 -> V_90 == V_91 ) {
for ( V_96 = V_9 -> V_233 ; V_96 <= V_9 -> V_235 ; V_96 ++ ) {
V_9 -> V_64 [ V_96 ] . V_293 = 1 ;
V_9 -> V_64 [ V_96 ] . V_294 = 0 ;
V_9 -> V_64 [ V_96 ] . V_295 = 0 ;
}
if ( ! V_9 -> V_71 . V_287 )
return 0 ;
V_274 = ( ( V_252 >= V_9 -> V_71 . V_253 [ 3 ] ) ||
( V_8 -> V_10 . V_11 . V_288 >= 3 ) || V_9 -> V_278 ) ;
if ( V_274 ) {
for ( V_96 = V_9 -> V_233 ; V_96 <= V_9 -> V_235 ; V_96 ++ )
V_9 -> V_64 [ V_96 ] . V_293 = 0 ;
} else {
if ( V_9 -> V_282 )
V_9 -> V_64 [ 0 ] . V_294 = 1 ;
V_9 -> V_64 [ 1 ] . V_293 = 0 ;
V_9 -> V_64 [ 2 ] . V_293 = 0 ;
V_9 -> V_64 [ 3 ] . V_293 = 0 ;
V_9 -> V_64 [ 4 ] . V_293 = 0 ;
}
} else {
for ( V_96 = V_9 -> V_233 ; V_96 <= V_9 -> V_235 ; V_96 ++ ) {
V_9 -> V_64 [ V_96 ] . V_293 = 1 ;
V_9 -> V_64 [ V_96 ] . V_294 = 0 ;
V_9 -> V_64 [ V_96 ] . V_295 = 0 ;
}
if ( V_9 -> V_71 . V_287 && V_9 -> V_282 ) {
V_9 -> V_64 [ V_9 -> V_233 ] . V_295 = 0x28 ;
V_9 -> V_64 [ V_9 -> V_233 ] . V_293 = 0 ;
if ( V_9 -> V_233 != V_9 -> V_235 )
V_9 -> V_64 [ V_9 -> V_233 ] . V_294 = 1 ;
}
}
return 0 ;
}
static int F_99 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_96 ;
if ( V_9 -> V_233 > V_9 -> V_235 )
return - V_18 ;
for ( V_96 = V_9 -> V_233 ; V_96 <= V_9 -> V_235 ; V_96 ++ )
V_9 -> V_64 [ V_96 ] . V_296 = ( V_96 == V_9 -> V_235 ) ? 1 : 0 ;
return 0 ;
}
static void F_66 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_96 ;
struct V_97 * V_98 =
& V_8 -> V_10 . V_11 . V_99 . V_100 ;
if ( V_98 && V_98 -> V_101 ) {
T_1 V_69 ;
V_9 -> V_102 = 0 ;
for ( V_96 = 0 ; V_96 < V_98 -> V_101 ; V_96 ++ ) {
if ( V_9 -> V_122 &&
( V_9 -> V_122 <
F_28 ( V_8 , V_98 -> V_103 [ V_96 ] . V_123 ) ) )
break;
F_25 ( V_8 , V_96 , V_98 -> V_103 [ V_96 ] . V_104 ) ;
V_69 = F_116 ( V_8 ,
& V_9 -> V_71 . V_72 ,
V_98 -> V_103 [ V_96 ] . V_123 ) ;
F_31 ( V_8 , V_96 , V_69 ) ;
F_32 ( V_8 , V_96 , V_9 -> V_77 [ V_96 ] ) ;
F_114 ( V_8 , V_96 , true ) ;
V_9 -> V_102 ++ ;
}
} else {
struct V_106 * V_98 =
& V_9 -> V_71 . V_107 ;
V_9 -> V_102 = 0 ;
for ( V_96 = 0 ; V_96 < V_98 -> V_108 ; V_96 ++ ) {
if ( V_9 -> V_122 &&
V_9 -> V_122 <
F_29 ( V_8 , V_98 -> V_103 [ V_96 ] . V_69 ) )
break;
F_25 ( V_8 , V_96 , V_98 -> V_103 [ V_96 ] . V_109 ) ;
F_31 ( V_8 , V_96 , V_98 -> V_103 [ V_96 ] . V_69 ) ;
F_32 ( V_8 , V_96 , V_9 -> V_77 [ V_96 ] ) ;
F_114 ( V_8 , V_96 , true ) ;
V_9 -> V_102 ++ ;
}
}
for ( V_96 = 0 ; V_96 < V_114 ; V_96 ++ )
F_34 ( V_8 , V_96 , false ) ;
}
static void F_100 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_96 ;
for ( V_96 = 0 ; V_96 < V_114 ; V_96 ++ ) {
if ( V_96 >= V_9 -> V_233 && V_96 <= V_9 -> V_235 )
F_34 ( V_8 , V_96 , true ) ;
}
}
static int F_106 ( struct V_7 * V_8 , T_1 V_242 )
{
T_1 V_297 = ( 1 << V_242 ) ;
return F_81 ( V_8 ,
V_298 ,
V_297 ) ;
}
static int F_44 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_96 , V_297 = 0 ;
for ( V_96 = V_9 -> V_233 ; V_96 <= V_9 -> V_235 ; V_96 ++ )
V_297 |= ( 1 << V_96 ) ;
return F_81 ( V_8 ,
V_298 ,
V_297 ) ;
}
static void F_101 ( struct V_7 * V_8 ,
struct V_2 * V_231 )
{
struct V_1 * V_173 = F_1 ( V_231 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_299 ;
if ( V_8 -> V_90 == V_91 )
return;
if ( V_9 -> V_71 . V_287 ) {
V_299 = F_4 ( V_300 ) ;
V_299 &= ~ ( V_301 | V_302 |
V_303 | V_304 ) ;
V_299 |= ( F_117 ( V_173 -> V_283 ) |
F_118 ( V_173 -> V_284 ) |
F_119 ( V_173 -> V_285 ) |
F_120 ( V_173 -> V_286 ) ) ;
F_7 ( V_300 , V_299 ) ;
}
}
static int F_68 ( struct V_7 * V_8 ,
int V_305 , int V_306 )
{
int V_307 = 0 * 1000 ;
int V_308 = 255 * 1000 ;
T_1 V_42 ;
if ( V_307 < V_305 )
V_307 = V_305 ;
if ( V_308 > V_306 )
V_308 = V_306 ;
if ( V_308 < V_307 ) {
F_62 ( L_18 , V_307 , V_308 ) ;
return - V_18 ;
}
V_42 = F_4 ( V_309 ) ;
V_42 &= ~ ( V_310 | V_311 ) ;
V_42 |= ( F_121 ( 49 + ( V_308 / 1000 ) ) |
F_122 ( 49 + ( V_307 / 1000 ) ) ) ;
F_7 ( V_309 , V_42 ) ;
V_8 -> V_10 . V_11 . V_312 . V_305 = V_307 ;
V_8 -> V_10 . V_11 . V_312 . V_306 = V_308 ;
return 0 ;
}
static int F_123 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_313 * V_314 = & V_8 -> V_314 ;
int V_59 = F_124 ( V_315 , V_316 ) ;
union V_317 * V_317 ;
V_53 V_318 , V_319 ;
T_2 V_320 ;
int V_96 ;
if ( F_125 ( V_314 -> V_321 , V_59 , NULL ,
& V_318 , & V_319 , & V_320 ) ) {
V_317 = (union V_317 * ) ( V_314 -> V_321 -> V_322 +
V_320 ) ;
if ( V_319 != 8 ) {
F_62 ( L_19 , V_318 , V_319 ) ;
return - V_18 ;
}
V_9 -> V_71 . V_254 = F_126 ( V_317 -> V_323 . V_324 ) ;
V_9 -> V_71 . V_325 = F_126 ( V_317 -> V_323 . V_326 ) ;
V_9 -> V_71 . V_256 =
F_127 ( V_317 -> V_323 . V_327 ) ;
if ( V_317 -> V_323 . V_328 == 0 )
V_9 -> V_71 . V_329 = 203 ;
else
V_9 -> V_71 . V_329 = V_317 -> V_323 . V_328 ;
if ( V_317 -> V_323 . V_330 == 0 )
V_9 -> V_71 . V_331 = 5 ;
else
V_9 -> V_71 . V_331 = V_317 -> V_323 . V_330 ;
if ( V_9 -> V_71 . V_329 <= V_9 -> V_71 . V_331 ) {
F_62 ( L_20 ) ;
}
if ( F_126 ( V_317 -> V_323 . V_332 ) & ( 1 << 3 ) )
V_9 -> V_71 . V_287 = true ;
else
V_9 -> V_71 . V_287 = false ;
for ( V_96 = 0 ; V_96 < V_333 ; V_96 ++ ) {
V_9 -> V_71 . V_253 [ V_96 ] =
F_126 ( V_317 -> V_323 . V_334 [ V_96 ] ) ;
V_9 -> V_71 . V_335 [ V_96 ] =
F_126 ( V_317 -> V_323 . V_336 [ V_96 ] ) ;
}
if ( F_126 ( V_317 -> V_323 . V_337 ) &
V_338 )
V_9 -> V_118 = true ;
F_128 ( V_8 ,
& V_9 -> V_71 . V_107 ,
V_317 -> V_323 . V_339 ) ;
F_129 ( V_8 ,
& V_9 -> V_71 . V_72 ,
V_317 -> V_323 . V_339 ) ;
F_107 ( V_8 ,
& V_8 -> V_10 . V_11 . V_99 . V_277 ) ;
}
return 0 ;
}
static void F_130 ( struct V_7 * V_8 ,
struct V_1 * V_4 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_4 -> V_234 = 1 ;
V_4 -> V_232 [ 0 ] = V_9 -> V_105 ;
}
static void F_131 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_340 * V_341 ,
V_53 V_342 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_3 -> V_343 = F_126 ( V_341 -> V_344 ) ;
V_3 -> V_279 = F_127 ( V_341 -> V_345 ) ;
V_3 -> V_346 = F_127 ( V_341 -> V_347 ) ;
if ( V_348 < V_342 ) {
V_3 -> V_126 = F_126 ( V_341 -> V_349 ) ;
V_3 -> V_128 = F_126 ( V_341 -> V_350 ) ;
} else {
V_3 -> V_126 = 0 ;
V_3 -> V_128 = 0 ;
}
if ( V_3 -> V_279 & V_351 ) {
V_8 -> V_10 . V_11 . V_190 = V_3 ;
F_130 ( V_8 , V_4 ) ;
}
if ( V_3 -> V_279 & V_352 )
V_8 -> V_10 . V_11 . V_353 = V_3 ;
}
static void F_132 ( struct V_7 * V_8 ,
struct V_2 * V_3 , int V_59 ,
union V_354 * V_355 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_356 * V_357 = & V_4 -> V_232 [ V_59 ] ;
T_1 V_60 ;
V_60 = F_127 ( V_355 -> V_358 . V_359 ) ;
V_60 |= V_355 -> V_358 . V_360 << 16 ;
V_357 -> V_60 = V_60 ;
V_357 -> V_255 = V_355 -> V_358 . V_361 ;
V_4 -> V_234 = V_59 + 1 ;
if ( V_9 -> V_269 ) {
V_357 -> V_257 = 5 ;
V_357 -> V_258 = 5 ;
}
}
static int F_133 ( struct V_7 * V_8 )
{
struct V_313 * V_314 = & V_8 -> V_314 ;
struct V_340 * V_341 ;
union V_362 * V_363 ;
int V_96 , V_364 , V_365 , V_366 , V_367 ;
union V_354 * V_355 ;
struct V_368 * V_369 ;
struct V_370 * V_371 ;
struct V_372 * V_373 ;
union V_374 * V_374 ;
int V_59 = F_124 ( V_315 , V_375 ) ;
T_2 V_320 ;
V_53 V_318 , V_319 ;
V_53 * V_376 ;
struct V_1 * V_4 ;
if ( ! F_125 ( V_314 -> V_321 , V_59 , NULL ,
& V_318 , & V_319 , & V_320 ) )
return - V_18 ;
V_374 = (union V_374 * ) ( V_314 -> V_321 -> V_322 + V_320 ) ;
V_369 = (struct V_368 * )
( V_314 -> V_321 -> V_322 + V_320 +
F_127 ( V_374 -> V_377 . V_378 ) ) ;
V_371 = (struct V_370 * )
( V_314 -> V_321 -> V_322 + V_320 +
F_127 ( V_374 -> V_377 . V_379 ) ) ;
V_373 = (struct V_372 * )
( V_314 -> V_321 -> V_322 + V_320 +
F_127 ( V_374 -> V_377 . V_380 ) ) ;
V_8 -> V_10 . V_11 . V_4 = F_134 ( sizeof( struct V_2 ) *
V_369 -> V_381 , V_382 ) ;
if ( ! V_8 -> V_10 . V_11 . V_4 )
return - V_383 ;
V_376 = ( V_53 * ) V_369 -> V_384 ;
V_8 -> V_10 . V_11 . V_385 = F_126 ( V_374 -> V_377 . V_386 ) ;
V_8 -> V_10 . V_11 . V_387 = F_127 ( V_374 -> V_377 . V_388 ) ;
V_8 -> V_10 . V_11 . V_389 = F_127 ( V_374 -> V_377 . V_390 ) ;
for ( V_96 = 0 ; V_96 < V_369 -> V_381 ; V_96 ++ ) {
V_53 * V_250 ;
V_363 = (union V_362 * ) V_376 ;
V_366 = V_363 -> V_391 . V_392 ;
V_341 = (struct V_340 * )
& V_373 -> V_393 [ V_366 ] ;
if ( ! V_8 -> V_10 . V_363 [ V_96 ] . V_355 )
return - V_18 ;
V_4 = F_134 ( sizeof( struct V_1 ) , V_382 ) ;
if ( V_4 == NULL ) {
F_135 ( V_8 -> V_10 . V_11 . V_4 ) ;
return - V_383 ;
}
V_8 -> V_10 . V_11 . V_4 [ V_96 ] . V_5 = V_4 ;
V_365 = 0 ;
V_250 = ( V_53 * ) & V_363 -> V_391 . V_394 [ 0 ] ;
for ( V_364 = 0 ; V_364 < V_363 -> V_391 . V_395 ; V_364 ++ ) {
V_367 = V_250 [ V_364 ] ;
if ( V_367 >= V_371 -> V_381 )
continue;
if ( V_365 >= V_396 )
break;
V_355 = (union V_354 * )
( ( V_53 * ) & V_371 -> V_397 [ 0 ] +
( V_367 * V_371 -> V_398 ) ) ;
F_132 ( V_8 ,
& V_8 -> V_10 . V_11 . V_4 [ V_96 ] , V_365 ,
V_355 ) ;
V_365 ++ ;
}
F_131 ( V_8 , & V_8 -> V_10 . V_11 . V_4 [ V_96 ] ,
V_341 ,
V_373 -> V_398 ) ;
V_376 += 2 + V_363 -> V_391 . V_395 ;
}
V_8 -> V_10 . V_11 . V_399 = V_369 -> V_381 ;
return 0 ;
}
int F_136 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
int V_36 , V_96 ;
V_9 = F_134 ( sizeof( struct V_6 ) , V_382 ) ;
if ( V_9 == NULL )
return - V_383 ;
V_8 -> V_10 . V_11 . V_12 = V_9 ;
V_36 = F_137 ( V_8 ) ;
if ( V_36 )
return V_36 ;
for ( V_96 = 0 ; V_96 < V_396 ; V_96 ++ )
V_9 -> V_77 [ V_96 ] = V_400 ;
V_9 -> V_46 = V_401 ;
if ( V_8 -> V_90 == V_91 )
V_9 -> V_122 = 4001 ;
V_9 -> V_238 = true ;
V_9 -> V_402 = true ;
V_9 -> V_38 = true ;
V_9 -> V_403 = false ;
if ( V_9 -> V_403 ) {
V_9 -> V_27 = true ;
V_9 -> V_30 = true ;
V_9 -> V_32 = true ;
V_9 -> V_34 = true ;
}
V_9 -> V_269 = true ;
V_9 -> V_183 = true ;
V_9 -> V_289 = false ;
V_9 -> V_178 = false ;
V_9 -> V_75 = 0 ;
V_9 -> V_94 = false ;
V_9 -> V_191 = false ;
V_9 -> V_218 = true ;
V_9 -> V_207 = true ;
V_9 -> V_222 = false ;
V_9 -> V_225 = false ;
V_9 -> V_228 = false ;
V_9 -> V_208 = false ;
V_36 = F_123 ( V_8 ) ;
if ( V_36 )
return V_36 ;
F_108 ( V_8 ) ;
F_109 ( V_8 ) ;
V_36 = F_133 ( V_8 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_248 = true ;
return 0 ;
}
void F_138 ( struct V_7 * V_8 ,
struct V_404 * V_405 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_406 =
( F_4 ( V_407 ) & V_408 ) >>
V_409 ;
T_1 V_60 , V_42 ;
T_2 V_251 ;
if ( V_406 >= V_410 ) {
F_139 ( V_405 , L_21 , V_406 ) ;
} else {
V_60 = F_115 ( V_9 -> V_64 [ V_406 ] . V_67 ) ;
V_42 = ( F_4 ( V_411 ) & V_412 ) >>
V_413 ;
V_251 = F_28 ( V_8 , ( T_2 ) V_42 ) ;
F_139 ( V_405 , L_22 ,
V_406 , V_60 , V_251 ) ;
}
}
void F_140 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
int V_96 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_141 ( V_3 -> V_279 , V_3 -> V_346 ) ;
F_142 ( V_3 -> V_343 ) ;
F_143 ( L_23 , V_3 -> V_126 , V_3 -> V_128 ) ;
for ( V_96 = 0 ; V_96 < V_4 -> V_234 ; V_96 ++ ) {
struct V_356 * V_357 = & V_4 -> V_232 [ V_96 ] ;
F_143 ( L_24 ,
V_96 , V_357 -> V_60 ,
F_28 ( V_8 , V_357 -> V_255 ) ) ;
}
F_144 ( V_8 , V_3 ) ;
}
void F_145 ( struct V_7 * V_8 )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_8 -> V_10 . V_11 . V_399 ; V_96 ++ ) {
F_135 ( V_8 -> V_10 . V_11 . V_4 [ V_96 ] . V_5 ) ;
}
F_135 ( V_8 -> V_10 . V_11 . V_4 ) ;
F_135 ( V_8 -> V_10 . V_11 . V_12 ) ;
F_146 ( V_8 ) ;
}
void F_147 ( struct V_7 * V_8 )
{
}
T_1 F_148 ( struct V_7 * V_8 , bool V_414 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_415 = F_1 ( & V_9 -> V_176 ) ;
if ( V_414 )
return V_415 -> V_232 [ 0 ] . V_60 ;
else
return V_415 -> V_232 [ V_415 -> V_234 - 1 ] . V_60 ;
}
T_1 F_149 ( struct V_7 * V_8 , bool V_414 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
return V_9 -> V_71 . V_325 ;
}
