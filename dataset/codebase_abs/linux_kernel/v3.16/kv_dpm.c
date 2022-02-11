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
static T_1 F_28 ( struct V_7 * V_8 ,
struct V_68 * V_69 ,
T_1 V_70 )
{
struct V_71 * V_72 =
& V_8 -> V_10 . V_11 . V_73 . V_74 ;
T_1 V_75 ;
if ( V_72 && V_72 -> V_76 ) {
if ( V_70 < V_72 -> V_76 )
return V_72 -> V_77 [ V_70 ] . V_78 ;
else
return V_72 -> V_77 [ V_72 -> V_76 - 1 ] . V_78 ;
} else {
for ( V_75 = 0 ; V_75 < V_69 -> V_79 ; V_75 ++ ) {
if ( V_69 -> V_77 [ V_75 ] . V_70 == V_70 )
return V_69 -> V_77 [ V_75 ] . V_80 ;
}
return V_69 -> V_77 [ V_69 -> V_79 - 1 ] . V_80 ;
}
}
static T_1 F_29 ( struct V_7 * V_8 ,
struct V_68 * V_69 ,
T_1 V_80 )
{
struct V_71 * V_72 =
& V_8 -> V_10 . V_11 . V_73 . V_74 ;
T_1 V_75 ;
if ( V_72 && V_72 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_72 -> V_76 ; V_75 ++ ) {
if ( V_72 -> V_77 [ V_75 ] . V_78 == V_80 )
return V_75 ;
}
return V_72 -> V_76 - 1 ;
} else {
for ( V_75 = 0 ; V_75 < V_69 -> V_79 ; V_75 ++ ) {
if ( V_69 -> V_77 [ V_75 ] . V_80 == V_80 )
return V_69 -> V_77 [ V_75 ] . V_70 ;
}
return V_69 -> V_77 [ V_69 -> V_79 - 1 ] . V_70 ;
}
}
static T_2 F_30 ( struct V_7 * V_8 ,
T_2 V_81 )
{
return 6200 - ( V_81 * 25 ) ;
}
static T_2 F_31 ( struct V_7 * V_8 ,
T_1 V_70 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_82 = F_28 ( V_8 ,
& V_9 -> V_83 . V_69 ,
V_70 ) ;
return F_30 ( V_8 , ( T_2 ) V_82 ) ;
}
static int F_32 ( struct V_7 * V_8 , T_1 V_59 , T_1 V_84 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_64 [ V_59 ] . V_85 = ( V_53 ) V_9 -> V_86 ;
V_9 -> V_64 [ V_59 ] . V_87 =
F_27 ( F_31 ( V_8 , V_84 ) ) ;
return 0 ;
}
static int F_33 ( struct V_7 * V_8 , T_1 V_59 , T_1 V_88 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_64 [ V_59 ] . V_89 = F_34 ( ( T_2 ) V_88 ) ;
return 0 ;
}
static void F_35 ( struct V_7 * V_8 ,
T_1 V_59 , bool V_26 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_64 [ V_59 ] . V_90 = V_26 ? 1 : 0 ;
}
static void F_36 ( struct V_7 * V_8 )
{
T_1 V_42 = F_4 ( V_91 ) ;
V_42 |= V_92 ;
F_7 ( V_91 , V_42 ) ;
F_37 ( V_8 , true ) ;
}
static void F_38 ( struct V_7 * V_8 )
{
F_37 ( V_8 , false ) ;
}
static void F_39 ( struct V_7 * V_8 )
{
T_1 V_93 = F_4 ( V_94 ) ;
V_93 &= ~ ( V_95 | V_96 ) ;
V_93 |= V_97 ;
F_7 ( V_94 , V_93 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
T_1 V_93 = F_4 ( V_94 ) ;
V_93 |= ( V_95 | V_96 ) ;
F_7 ( V_94 , V_93 ) ;
}
static int F_41 ( struct V_7 * V_8 , bool V_98 )
{
return F_15 ( V_8 , V_98 ?
V_99 : V_100 ) ;
}
static int F_42 ( struct V_7 * V_8 )
{
return F_43 ( V_8 ) ;
}
static int F_44 ( struct V_7 * V_8 )
{
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 )
return F_15 ( V_8 , V_104 ) ;
else
return F_45 ( V_8 ) ;
}
static int F_46 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_105 = 0 ;
int V_36 = 0 ;
if ( V_9 -> V_106 ) {
V_105 = F_27 ( V_9 -> V_105 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_107 ) ,
( V_53 * ) & V_105 ,
sizeof( T_1 ) , V_9 -> V_46 ) ;
}
return V_36 ;
}
static int F_47 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_74 ;
if ( V_108 && V_108 -> V_76 ) {
for ( V_75 = V_9 -> V_109 - 1 ; V_75 > 0 ; V_75 -- ) {
if ( V_108 -> V_77 [ V_75 ] . V_110 == V_9 -> V_111 . V_60 )
break;
}
V_9 -> V_57 = ( V_53 ) V_75 ;
F_35 ( V_8 , V_75 , true ) ;
} else {
struct V_112 * V_108 =
& V_9 -> V_83 . V_113 ;
if ( V_108 -> V_114 == 0 )
return - V_18 ;
for ( V_75 = V_9 -> V_109 - 1 ; V_75 > 0 ; V_75 -- ) {
if ( V_108 -> V_77 [ V_75 ] . V_115 == V_9 -> V_111 . V_60 )
break;
}
V_9 -> V_57 = ( V_53 ) V_75 ;
F_35 ( V_8 , V_75 , true ) ;
}
return 0 ;
}
static int F_48 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
V_9 -> V_116 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_117 ) ,
& V_9 -> V_116 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
return V_36 ;
}
static int F_49 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_118 ) ,
( V_53 * ) & V_9 -> V_64 ,
sizeof( V_119 ) * V_120 ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_121 ) ,
& V_9 -> V_109 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
return V_36 ;
}
static T_1 F_50 ( T_1 V_122 , T_1 V_123 )
{
return ( V_122 >= V_123 ) ? V_122 - V_123 : V_123 - V_122 ;
}
static T_1 F_51 ( struct V_7 * V_8 , T_1 V_110 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_21 ;
if ( V_9 -> V_124 ) {
if ( F_50 ( V_110 , 40000 ) < 200 )
V_21 = 3 ;
else if ( F_50 ( V_110 , 30000 ) < 200 )
V_21 = 2 ;
else if ( F_50 ( V_110 , 20000 ) < 200 )
V_21 = 7 ;
else if ( F_50 ( V_110 , 15000 ) < 200 )
V_21 = 6 ;
else if ( F_50 ( V_110 , 10000 ) < 200 )
V_21 = 8 ;
else
V_21 = 0 ;
} else {
V_21 = 0 ;
}
return V_21 ;
}
static int F_52 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_125 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_126 ;
struct V_61 V_62 ;
int V_36 ;
T_1 V_75 ;
if ( V_108 == NULL || V_108 -> V_76 == 0 )
return 0 ;
V_9 -> V_127 = 0 ;
for ( V_75 = 0 ; V_75 < V_108 -> V_76 ; V_75 ++ ) {
if ( V_9 -> V_128 &&
( V_9 -> V_128 < V_108 -> V_77 [ V_75 ] . V_78 ) )
break;
V_9 -> V_129 [ V_75 ] . V_130 = F_27 ( V_108 -> V_77 [ V_75 ] . V_131 ) ;
V_9 -> V_129 [ V_75 ] . V_132 = F_27 ( V_108 -> V_77 [ V_75 ] . V_133 ) ;
V_9 -> V_129 [ V_75 ] . V_87 = F_34 ( V_108 -> V_77 [ V_75 ] . V_78 ) ;
V_9 -> V_129 [ V_75 ] . V_134 =
( V_53 ) F_51 ( V_8 , V_108 -> V_77 [ V_75 ] . V_131 ) ;
V_9 -> V_129 [ V_75 ] . V_135 =
( V_53 ) F_51 ( V_8 , V_108 -> V_77 [ V_75 ] . V_133 ) ;
V_36 = F_26 ( V_8 , V_63 ,
V_108 -> V_77 [ V_75 ] . V_131 , false , & V_62 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_129 [ V_75 ] . V_136 = ( V_53 ) V_62 . V_66 ;
V_36 = F_26 ( V_8 , V_63 ,
V_108 -> V_77 [ V_75 ] . V_133 , false , & V_62 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_129 [ V_75 ] . V_137 = ( V_53 ) V_62 . V_66 ;
V_9 -> V_127 ++ ;
}
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_138 ) ,
( V_53 * ) & V_9 -> V_127 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_139 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_140 ) ,
& V_9 -> V_139 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_141 ) ,
( V_53 * ) & V_9 -> V_129 ,
sizeof( V_142 ) * V_143 ,
V_9 -> V_46 ) ;
return V_36 ;
}
static int F_53 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
T_1 V_75 ;
struct V_144 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_145 ;
struct V_61 V_62 ;
if ( V_108 == NULL || V_108 -> V_76 == 0 )
return 0 ;
V_9 -> V_146 = 0 ;
for ( V_75 = 0 ; V_75 < V_108 -> V_76 ; V_75 ++ ) {
if ( V_9 -> V_128 &&
V_9 -> V_128 < V_108 -> V_77 [ V_75 ] . V_78 )
break;
V_9 -> V_147 [ V_75 ] . V_148 = F_27 ( V_108 -> V_77 [ V_75 ] . V_149 ) ;
V_9 -> V_147 [ V_75 ] . V_150 = F_34 ( V_108 -> V_77 [ V_75 ] . V_78 ) ;
V_9 -> V_147 [ V_75 ] . V_151 =
( V_53 ) F_51 ( V_8 , V_108 -> V_77 [ V_75 ] . V_149 ) ;
V_36 = F_26 ( V_8 , V_63 ,
V_108 -> V_77 [ V_75 ] . V_149 , false , & V_62 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_147 [ V_75 ] . V_152 = ( V_53 ) V_62 . V_66 ;
V_9 -> V_146 ++ ;
}
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_153 ) ,
( V_53 * ) & V_9 -> V_146 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_154 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_155 ) ,
( V_53 * ) & V_9 -> V_154 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_156 ) ,
( V_53 * ) & V_9 -> V_147 ,
sizeof( V_157 ) * V_158 ,
V_9 -> V_46 ) ;
return V_36 ;
}
static int F_54 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_159 ;
struct V_61 V_62 ;
int V_36 ;
T_1 V_75 ;
if ( V_108 == NULL || V_108 -> V_76 == 0 )
return 0 ;
V_9 -> V_160 = 0 ;
for ( V_75 = 0 ; V_75 < V_108 -> V_76 ; V_75 ++ ) {
if ( V_9 -> V_128 &&
V_9 -> V_128 < V_108 -> V_77 [ V_75 ] . V_78 )
break;
V_9 -> V_161 [ V_75 ] . V_148 = F_27 ( V_108 -> V_77 [ V_75 ] . V_110 ) ;
V_9 -> V_161 [ V_75 ] . V_150 = F_34 ( V_108 -> V_77 [ V_75 ] . V_78 ) ;
V_9 -> V_161 [ V_75 ] . V_151 =
( V_53 ) F_51 ( V_8 , V_108 -> V_77 [ V_75 ] . V_110 ) ;
V_36 = F_26 ( V_8 , V_63 ,
V_108 -> V_77 [ V_75 ] . V_110 , false , & V_62 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_161 [ V_75 ] . V_152 = ( V_53 ) V_62 . V_66 ;
V_9 -> V_160 ++ ;
}
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_162 ) ,
( V_53 * ) & V_9 -> V_160 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_163 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_164 ) ,
( V_53 * ) & V_9 -> V_163 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_165 ) ,
( V_53 * ) & V_9 -> V_161 ,
sizeof( V_157 ) * V_166 ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
return V_36 ;
}
static int F_55 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_167 ;
struct V_61 V_62 ;
int V_36 ;
T_1 V_75 ;
if ( V_108 == NULL || V_108 -> V_76 == 0 )
return 0 ;
V_9 -> V_168 = 0 ;
for ( V_75 = 0 ; V_75 < V_108 -> V_76 ; V_75 ++ ) {
V_9 -> V_169 [ V_75 ] . V_148 = F_27 ( V_108 -> V_77 [ V_75 ] . V_110 ) ;
V_9 -> V_169 [ V_75 ] . V_150 = F_34 ( V_108 -> V_77 [ V_75 ] . V_78 ) ;
V_36 = F_26 ( V_8 , V_63 ,
V_108 -> V_77 [ V_75 ] . V_110 , false , & V_62 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_169 [ V_75 ] . V_152 = ( V_53 ) V_62 . V_66 ;
V_9 -> V_168 ++ ;
}
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_170 ) ,
( V_53 * ) & V_9 -> V_168 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_171 = 1 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_172 ) ,
( V_53 * ) & V_9 -> V_171 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_173 ) ,
( V_53 * ) & V_9 -> V_169 ,
sizeof( V_157 ) * V_174 ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
return V_36 ;
}
static void F_56 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_74 ;
if ( V_108 && V_108 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_9 -> V_109 ; V_75 ++ ) {
if ( V_9 -> V_124 ) {
if ( F_50 ( V_108 -> V_77 [ V_75 ] . V_110 , 40000 ) < 200 )
V_9 -> V_64 [ V_75 ] . V_151 = 3 ;
else if ( F_50 ( V_108 -> V_77 [ V_75 ] . V_110 , 30000 ) < 200 )
V_9 -> V_64 [ V_75 ] . V_151 = 2 ;
else if ( F_50 ( V_108 -> V_77 [ V_75 ] . V_110 , 26600 ) < 200 )
V_9 -> V_64 [ V_75 ] . V_151 = 7 ;
else if ( F_50 ( V_108 -> V_77 [ V_75 ] . V_110 , 20000 ) < 200 )
V_9 -> V_64 [ V_75 ] . V_151 = 6 ;
else if ( F_50 ( V_108 -> V_77 [ V_75 ] . V_110 , 10000 ) < 200 )
V_9 -> V_64 [ V_75 ] . V_151 = 8 ;
else
V_9 -> V_64 [ V_75 ] . V_151 = 0 ;
} else {
V_9 -> V_64 [ V_75 ] . V_151 = 0 ;
}
}
} else {
struct V_112 * V_108 =
& V_9 -> V_83 . V_113 ;
for ( V_75 = 0 ; V_75 < V_9 -> V_109 ; V_75 ++ ) {
if ( V_9 -> V_124 ) {
if ( F_50 ( V_108 -> V_77 [ V_75 ] . V_115 , 40000 ) < 200 )
V_9 -> V_64 [ V_75 ] . V_151 = 3 ;
else if ( F_50 ( V_108 -> V_77 [ V_75 ] . V_115 , 30000 ) < 200 )
V_9 -> V_64 [ V_75 ] . V_151 = 2 ;
else if ( F_50 ( V_108 -> V_77 [ V_75 ] . V_115 , 26600 ) < 200 )
V_9 -> V_64 [ V_75 ] . V_151 = 7 ;
else if ( F_50 ( V_108 -> V_77 [ V_75 ] . V_115 , 20000 ) < 200 )
V_9 -> V_64 [ V_75 ] . V_151 = 6 ;
else if ( F_50 ( V_108 -> V_77 [ V_75 ] . V_115 , 10000 ) < 200 )
V_9 -> V_64 [ V_75 ] . V_151 = 8 ;
else
V_9 -> V_64 [ V_75 ] . V_151 = 0 ;
} else {
V_9 -> V_64 [ V_75 ] . V_151 = 0 ;
}
}
}
}
static int F_57 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_175 : V_176 ) ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_177 = 0xff ;
}
static void F_59 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_1 * V_178 = F_1 ( V_3 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_179 = * V_3 ;
V_9 -> V_180 = * V_178 ;
V_9 -> V_179 . V_5 = & V_9 -> V_180 ;
}
static void F_60 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
struct V_1 * V_178 = F_1 ( V_3 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_181 = * V_3 ;
V_9 -> V_182 = * V_178 ;
V_9 -> V_181 . V_5 = & V_9 -> V_182 ;
}
void F_61 ( struct V_7 * V_8 , bool V_26 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
if ( V_9 -> V_183 ) {
V_36 = F_62 ( V_8 , V_26 ) ;
if ( V_36 )
F_63 ( L_1 ) ;
}
}
int F_64 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
V_36 = F_16 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_2 ) ;
return V_36 ;
}
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
V_36 = F_47 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_3 ) ;
return V_36 ;
}
F_56 ( V_8 ) ;
V_36 = F_49 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_4 ) ;
return V_36 ;
}
V_36 = F_52 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_5 ) ;
return V_36 ;
}
V_36 = F_53 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_6 ) ;
return V_36 ;
}
V_36 = F_54 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_7 ) ;
return V_36 ;
}
V_36 = F_55 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_8 ) ;
return V_36 ;
}
F_23 ( V_8 ) ;
#if 0
kv_initialize_hardware_cac_manager(rdev);
#endif
F_39 ( V_8 ) ;
if ( V_9 -> V_184 ) {
V_36 = F_48 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_9 ) ;
return V_36 ;
}
}
V_36 = F_19 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_10 ) ;
return V_36 ;
}
V_36 = F_21 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_11 ) ;
return V_36 ;
}
V_36 = F_22 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_12 ) ;
return V_36 ;
}
V_36 = F_57 ( V_8 , true ) ;
if ( V_36 ) {
F_63 ( L_13 ) ;
return V_36 ;
}
F_36 ( V_8 ) ;
V_36 = F_11 ( V_8 , true ) ;
if ( V_36 ) {
F_63 ( L_14 ) ;
return V_36 ;
}
V_36 = F_14 ( V_8 , true ) ;
if ( V_36 ) {
F_63 ( L_15 ) ;
return V_36 ;
}
F_58 ( V_8 ) ;
V_36 = F_62 ( V_8 , false ) ;
if ( V_36 ) {
F_63 ( L_1 ) ;
return V_36 ;
}
F_59 ( V_8 , V_8 -> V_10 . V_11 . V_185 ) ;
return V_36 ;
}
int F_67 ( struct V_7 * V_8 )
{
int V_36 = 0 ;
if ( V_8 -> V_186 . V_187 &&
F_68 ( V_8 -> V_10 . V_188 ) ) {
V_36 = F_69 ( V_8 , V_189 , V_190 ) ;
if ( V_36 ) {
F_63 ( L_16 ) ;
return V_36 ;
}
V_8 -> V_186 . V_191 = true ;
F_70 ( V_8 ) ;
}
F_71 ( V_8 , true ) ;
F_72 ( V_8 , true ) ;
F_73 ( V_8 , true ) ;
F_74 ( V_8 , true ) ;
return V_36 ;
}
void F_75 ( struct V_7 * V_8 )
{
F_62 ( V_8 , false ) ;
F_71 ( V_8 , false ) ;
F_72 ( V_8 , false ) ;
F_73 ( V_8 , false ) ;
F_74 ( V_8 , false ) ;
F_14 ( V_8 , false ) ;
F_11 ( V_8 , false ) ;
F_24 ( V_8 ) ;
F_38 ( V_8 ) ;
F_57 ( V_8 , false ) ;
F_40 ( V_8 ) ;
F_59 ( V_8 , V_8 -> V_10 . V_11 . V_185 ) ;
}
static void F_76 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_105 = 0 ;
}
static int F_65 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 = 0 ;
if ( V_9 -> V_192 ) {
T_2 V_42 ;
V_42 = 45 ;
V_9 -> V_193 = F_34 ( V_42 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_194 ) ,
( V_53 * ) & V_9 -> V_193 ,
sizeof( T_2 ) , V_9 -> V_46 ) ;
V_42 = 30 ;
V_9 -> V_195 = F_34 ( V_42 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_196 ) ,
( V_53 * ) & V_9 -> V_195 ,
sizeof( T_2 ) , V_9 -> V_46 ) ;
}
return V_36 ;
}
static void F_77 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_197 = false ;
V_9 -> V_198 = false ;
V_9 -> V_199 = false ;
V_9 -> V_200 = false ;
}
static int F_78 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_201 : V_202 ) ;
}
static int F_79 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_203 : V_204 ) ;
}
static int F_80 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_205 : V_206 ) ;
}
static int F_81 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_207 : V_208 ) ;
}
static int F_82 ( struct V_7 * V_8 , bool V_209 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_125 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_126 ;
int V_36 ;
T_1 V_23 ;
if ( ! V_209 ) {
if ( V_108 -> V_76 )
V_9 -> V_210 = V_108 -> V_76 - 1 ;
else
V_9 -> V_210 = 0 ;
if ( ! V_9 -> V_211 || V_9 -> V_212 ) {
V_23 = 1 << V_9 -> V_210 ;
} else {
V_23 = 0x1f ;
}
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_213 ) ,
( V_214 * ) & V_9 -> V_210 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
F_83 ( V_8 ,
V_215 ,
V_23 ) ;
}
return F_78 ( V_8 , ! V_209 ) ;
}
static V_53 F_84 ( struct V_7 * V_8 )
{
V_53 V_75 ;
struct V_144 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_145 ;
for ( V_75 = 0 ; V_75 < V_108 -> V_76 ; V_75 ++ ) {
if ( V_108 -> V_77 [ V_75 ] . V_149 >= 0 )
break;
}
return V_75 ;
}
static int F_85 ( struct V_7 * V_8 ,
struct V_2 * V_216 ,
struct V_2 * V_217 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_144 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_145 ;
int V_36 ;
if ( V_216 -> V_149 > 0 && V_217 -> V_149 == 0 ) {
F_73 ( V_8 , false ) ;
F_86 ( V_8 , V_218 , false ) ;
if ( V_9 -> V_212 )
V_9 -> V_219 = V_108 -> V_76 - 1 ;
else
V_9 -> V_219 = F_84 ( V_8 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_220 ) ,
( V_53 * ) & V_9 -> V_219 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
if ( V_9 -> V_212 )
F_83 ( V_8 ,
V_221 ,
( 1 << V_9 -> V_219 ) ) ;
F_79 ( V_8 , true ) ;
} else if ( V_216 -> V_149 == 0 && V_217 -> V_149 > 0 ) {
F_79 ( V_8 , false ) ;
F_86 ( V_8 , V_218 , true ) ;
F_73 ( V_8 , true ) ;
}
return 0 ;
}
static int F_87 ( struct V_7 * V_8 , bool V_209 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_159 ;
int V_36 ;
if ( ! V_209 ) {
if ( V_9 -> V_212 )
V_9 -> V_222 = V_108 -> V_76 - 1 ;
else
V_9 -> V_222 = 0 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_223 ) ,
( V_53 * ) & V_9 -> V_222 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
if ( V_9 -> V_212 )
F_83 ( V_8 ,
V_224 ,
( 1 << V_9 -> V_222 ) ) ;
}
return F_80 ( V_8 , ! V_209 ) ;
}
static V_53 F_88 ( struct V_7 * V_8 )
{
V_53 V_75 ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_167 ;
for ( V_75 = 0 ; V_75 < V_108 -> V_76 ; V_75 ++ ) {
if ( V_108 -> V_77 [ V_75 ] . V_110 >= 0 )
break;
}
if ( V_75 >= V_108 -> V_76 )
V_75 = V_108 -> V_76 - 1 ;
return V_75 ;
}
static void F_89 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_53 V_177 ;
if ( ! V_9 -> V_212 ) {
V_177 = F_88 ( V_8 ) ;
if ( V_177 != V_9 -> V_177 ) {
V_9 -> V_177 = V_177 ;
F_83 ( V_8 ,
V_225 ,
( 1 << V_9 -> V_177 ) ) ;
}
}
}
static int F_90 ( struct V_7 * V_8 , bool V_209 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_167 ;
int V_36 ;
if ( ! V_209 ) {
if ( V_9 -> V_212 )
V_9 -> V_177 = V_108 -> V_76 - 1 ;
else
V_9 -> V_177 = F_88 ( V_8 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_226 ) ,
( V_53 * ) & V_9 -> V_177 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
if ( V_9 -> V_212 )
F_83 ( V_8 ,
V_225 ,
( 1 << V_9 -> V_177 ) ) ;
}
return F_81 ( V_8 , ! V_209 ) ;
}
void F_74 ( struct V_7 * V_8 , bool V_209 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_197 == V_209 )
return;
V_9 -> V_197 = V_209 ;
if ( V_209 ) {
if ( V_9 -> V_227 ) {
F_91 ( V_8 ) ;
F_86 ( V_8 , V_228 , false ) ;
}
F_82 ( V_8 , V_209 ) ;
if ( V_9 -> V_227 )
F_15 ( V_8 , V_229 ) ;
} else {
if ( V_9 -> V_227 ) {
F_15 ( V_8 , V_230 ) ;
F_92 ( V_8 ) ;
F_93 ( V_8 ) ;
F_86 ( V_8 , V_228 , true ) ;
}
F_82 ( V_8 , V_209 ) ;
}
}
static void F_73 ( struct V_7 * V_8 , bool V_209 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_198 == V_209 )
return;
V_9 -> V_198 = V_209 ;
if ( V_209 ) {
if ( V_9 -> V_231 ) {
F_15 ( V_8 , V_232 ) ;
}
} else {
if ( V_9 -> V_231 ) {
F_15 ( V_8 , V_233 ) ;
F_94 ( V_8 ) ;
F_95 ( V_8 ) ;
}
}
}
static void F_72 ( struct V_7 * V_8 , bool V_209 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_199 == V_209 )
return;
V_9 -> V_199 = V_209 ;
if ( V_209 ) {
F_87 ( V_8 , true ) ;
if ( V_9 -> V_234 )
F_15 ( V_8 , V_235 ) ;
} else {
if ( V_9 -> V_234 )
F_15 ( V_8 , V_236 ) ;
F_87 ( V_8 , false ) ;
}
}
static void F_71 ( struct V_7 * V_8 , bool V_209 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_200 == V_209 )
return;
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 )
return;
V_9 -> V_200 = V_209 ;
if ( V_209 ) {
F_90 ( V_8 , true ) ;
if ( V_9 -> V_237 )
F_15 ( V_8 , V_238 ) ;
} else {
if ( V_9 -> V_237 )
F_15 ( V_8 , V_239 ) ;
F_90 ( V_8 , false ) ;
}
}
static void F_96 ( struct V_7 * V_8 ,
struct V_2 * V_240 )
{
struct V_1 * V_178 = F_1 ( V_240 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_74 ;
if ( V_108 && V_108 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_9 -> V_109 ; V_75 ++ ) {
if ( ( V_108 -> V_77 [ V_75 ] . V_110 >= V_178 -> V_241 [ 0 ] . V_60 ) ||
( V_75 == ( V_9 -> V_109 - 1 ) ) ) {
V_9 -> V_242 = V_75 ;
break;
}
}
for ( V_75 = V_9 -> V_109 - 1 ; V_75 > 0 ; V_75 -- ) {
if ( V_108 -> V_77 [ V_75 ] . V_110 <= V_178 -> V_241 [ V_178 -> V_243 - 1 ] . V_60 )
break;
}
V_9 -> V_244 = V_75 ;
if ( V_9 -> V_242 > V_9 -> V_244 ) {
if ( ( V_178 -> V_241 [ 0 ] . V_60 - V_108 -> V_77 [ V_9 -> V_244 ] . V_110 ) >
( V_108 -> V_77 [ V_9 -> V_242 ] . V_110 - V_178 -> V_241 [ V_178 -> V_243 - 1 ] . V_60 ) )
V_9 -> V_244 = V_9 -> V_242 ;
else
V_9 -> V_242 = V_9 -> V_244 ;
}
} else {
struct V_112 * V_108 =
& V_9 -> V_83 . V_113 ;
for ( V_75 = 0 ; V_75 < ( int ) V_9 -> V_109 ; V_75 ++ ) {
if ( V_108 -> V_77 [ V_75 ] . V_115 >= V_178 -> V_241 [ 0 ] . V_60 ||
V_75 == ( int ) ( V_9 -> V_109 - 1 ) ) {
V_9 -> V_242 = V_75 ;
break;
}
}
for ( V_75 = V_9 -> V_109 - 1 ; V_75 > 0 ; V_75 -- ) {
if ( V_108 -> V_77 [ V_75 ] . V_115 <=
V_178 -> V_241 [ V_178 -> V_243 - 1 ] . V_60 )
break;
}
V_9 -> V_244 = V_75 ;
if ( V_9 -> V_242 > V_9 -> V_244 ) {
if ( ( V_178 -> V_241 [ 0 ] . V_60 -
V_108 -> V_77 [ V_9 -> V_244 ] . V_115 ) >
( V_108 -> V_77 [ V_9 -> V_242 ] . V_115 -
V_178 -> V_241 [ V_178 -> V_243 - 1 ] . V_60 ) )
V_9 -> V_244 = V_9 -> V_242 ;
else
V_9 -> V_242 = V_9 -> V_244 ;
}
}
}
static int F_97 ( struct V_7 * V_8 ,
struct V_2 * V_240 )
{
struct V_1 * V_178 = F_1 ( V_240 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 = 0 ;
V_53 V_245 ;
if ( V_9 -> V_124 ) {
V_245 = V_178 -> V_246 ?
V_9 -> V_64 [ V_9 -> V_57 ] . V_151 : 0 ;
V_36 = F_20 ( V_8 ,
( V_9 -> V_47 +
F_18 ( V_51 , V_118 ) +
( V_9 -> V_57 * sizeof( V_119 ) ) +
F_18 ( V_119 , V_151 ) ) ,
& V_245 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
}
return V_36 ;
}
static int F_98 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 = 0 ;
if ( V_9 -> V_247 && ! V_9 -> V_248 ) {
V_36 = F_15 ( V_8 , V_249 ) ;
if ( V_36 == 0 )
V_9 -> V_248 = true ;
}
return V_36 ;
}
int F_99 ( struct V_7 * V_8 ,
enum V_250 V_251 )
{
int V_36 ;
if ( V_251 == V_252 ) {
V_36 = F_100 ( V_8 ) ;
if ( V_36 )
return V_36 ;
} else if ( V_251 == V_253 ) {
V_36 = F_43 ( V_8 ) ;
if ( V_36 )
return V_36 ;
} else if ( V_251 == V_254 ) {
V_36 = F_44 ( V_8 ) ;
if ( V_36 )
return V_36 ;
}
V_8 -> V_10 . V_11 . V_255 = V_251 ;
return 0 ;
}
int F_101 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 V_182 = * V_8 -> V_10 . V_11 . V_182 ;
struct V_2 * V_178 = & V_182 ;
F_60 ( V_8 , V_178 ) ;
F_102 ( V_8 ,
& V_9 -> V_181 ,
& V_9 -> V_179 ) ;
return 0 ;
}
int F_103 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_178 = & V_9 -> V_181 ;
struct V_2 * V_256 = & V_9 -> V_179 ;
int V_36 ;
if ( V_9 -> V_183 ) {
V_36 = F_62 ( V_8 , V_8 -> V_10 . V_11 . V_257 ) ;
if ( V_36 ) {
F_63 ( L_1 ) ;
return V_36 ;
}
}
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 ) {
if ( V_9 -> V_258 ) {
F_96 ( V_8 , V_178 ) ;
F_97 ( V_8 , V_178 ) ;
V_36 = F_104 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_17 ) ;
return V_36 ;
}
F_105 ( V_8 ) ;
F_106 ( V_8 ) ;
F_42 ( V_8 ) ;
F_107 ( V_8 ) ;
F_49 ( V_8 ) ;
F_108 ( V_8 , V_178 ) ;
F_44 ( V_8 ) ;
F_45 ( V_8 ) ;
F_42 ( V_8 ) ;
F_44 ( V_8 ) ;
V_36 = F_85 ( V_8 , V_178 , V_256 ) ;
if ( V_36 ) {
F_63 ( L_18 ) ;
return V_36 ;
}
F_46 ( V_8 ) ;
if ( V_8 -> V_101 == V_103 )
F_98 ( V_8 ) ;
}
} else {
if ( V_9 -> V_258 ) {
F_96 ( V_8 , V_178 ) ;
F_97 ( V_8 , V_178 ) ;
V_36 = F_104 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_17 ) ;
return V_36 ;
}
F_105 ( V_8 ) ;
F_106 ( V_8 ) ;
F_41 ( V_8 , true ) ;
F_49 ( V_8 ) ;
F_108 ( V_8 , V_178 ) ;
F_41 ( V_8 , false ) ;
F_45 ( V_8 ) ;
V_36 = F_85 ( V_8 , V_178 , V_256 ) ;
if ( V_36 ) {
F_63 ( L_18 ) ;
return V_36 ;
}
F_89 ( V_8 ) ;
F_46 ( V_8 ) ;
F_98 ( V_8 ) ;
}
}
return 0 ;
}
void F_109 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_2 * V_178 = & V_9 -> V_181 ;
F_59 ( V_8 , V_178 ) ;
}
void F_110 ( struct V_7 * V_8 )
{
F_111 ( V_8 , true ) ;
F_77 ( V_8 ) ;
F_76 ( V_8 ) ;
}
void F_112 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 ) {
F_42 ( V_8 ) ;
F_66 ( V_8 ) ;
F_47 ( V_8 ) ;
F_49 ( V_8 ) ;
F_42 ( V_8 ) ;
F_44 ( V_8 ) ;
} else {
F_66 ( V_8 ) ;
F_47 ( V_8 ) ;
F_41 ( V_8 , true ) ;
F_49 ( V_8 ) ;
F_41 ( V_8 , false ) ;
F_113 ( V_8 , V_9 -> V_57 ) ;
}
}
static void F_114 ( struct V_7 * V_8 ,
struct V_259 * V_108 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_83 . V_113 . V_114 > 0 ) {
int V_260 = V_9 -> V_83 . V_113 . V_114 - 1 ;
V_108 -> V_60 =
V_9 -> V_83 . V_113 . V_77 [ V_260 ] . V_115 ;
V_108 -> V_261 =
F_31 ( V_8 ,
V_9 -> V_83 . V_113 . V_77 [ V_260 ] . V_70 ) ;
}
V_108 -> V_262 = V_9 -> V_83 . V_263 [ 0 ] ;
}
static void F_115 ( struct V_7 * V_8 )
{
int V_75 ;
struct V_125 * V_264 =
& V_8 -> V_10 . V_11 . V_73 . V_126 ;
struct V_144 * V_265 =
& V_8 -> V_10 . V_11 . V_73 . V_145 ;
struct V_71 * V_266 =
& V_8 -> V_10 . V_11 . V_73 . V_159 ;
struct V_71 * V_267 =
& V_8 -> V_10 . V_11 . V_73 . V_167 ;
if ( V_264 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_264 -> V_76 ; V_75 ++ )
V_264 -> V_77 [ V_75 ] . V_78 =
F_30 ( V_8 ,
V_264 -> V_77 [ V_75 ] . V_78 ) ;
}
if ( V_265 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_265 -> V_76 ; V_75 ++ )
V_265 -> V_77 [ V_75 ] . V_78 =
F_30 ( V_8 ,
V_265 -> V_77 [ V_75 ] . V_78 ) ;
}
if ( V_266 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_266 -> V_76 ; V_75 ++ )
V_266 -> V_77 [ V_75 ] . V_78 =
F_30 ( V_8 ,
V_266 -> V_77 [ V_75 ] . V_78 ) ;
}
if ( V_267 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_267 -> V_76 ; V_75 ++ )
V_267 -> V_77 [ V_75 ] . V_78 =
F_30 ( V_8 ,
V_267 -> V_77 [ V_75 ] . V_78 ) ;
}
}
static void F_116 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_111 . V_60 = V_9 -> V_83 . V_268 ;
V_9 -> V_111 . V_269 = V_9 -> V_83 . V_270 ;
V_9 -> V_111 . V_271 = 0 ;
V_9 -> V_111 . V_272 = 0 ;
V_9 -> V_111 . V_273 = 1 ;
V_9 -> V_111 . V_274 = 0 ;
V_9 -> V_111 . V_275 = 0 ;
V_9 -> V_111 . V_276 = 0 ;
}
static int F_100 ( struct V_7 * V_8 )
{
int V_36 ;
T_1 V_277 , V_75 ;
V_36 = F_117 ( V_8 , & V_277 ) ;
if ( V_36 )
return V_36 ;
for ( V_75 = V_120 - 1 ; V_75 > 0 ; V_75 -- ) {
if ( V_277 & ( 1 << V_75 ) )
break;
}
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 )
return F_83 ( V_8 , V_278 , V_75 ) ;
else
return F_113 ( V_8 , V_75 ) ;
}
static int F_43 ( struct V_7 * V_8 )
{
int V_36 ;
T_1 V_277 , V_75 ;
V_36 = F_117 ( V_8 , & V_277 ) ;
if ( V_36 )
return V_36 ;
for ( V_75 = 0 ; V_75 < V_120 ; V_75 ++ ) {
if ( V_277 & ( 1 << V_75 ) )
break;
}
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 )
return F_83 ( V_8 , V_278 , V_75 ) ;
else
return F_113 ( V_8 , V_75 ) ;
}
static V_53 F_118 ( struct V_7 * V_8 ,
T_1 V_60 , T_1 V_279 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
T_1 V_280 ;
T_1 V_281 = ( V_279 > V_282 ) ?
V_279 : V_282 ;
if ( V_60 < V_281 )
return 0 ;
if ( ! V_9 -> V_283 )
return 0 ;
for ( V_75 = V_284 ; V_75 > 0 ; V_75 -- ) {
V_280 = V_60 / F_119 ( V_75 ) ;
if ( V_280 >= V_281 )
break;
}
return ( V_53 ) V_75 ;
}
static int F_120 ( struct V_7 * V_8 , int * V_285 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_74 ;
int V_75 ;
if ( V_108 && V_108 -> V_76 ) {
for ( V_75 = V_108 -> V_76 - 1 ; V_75 >= 0 ; V_75 -- ) {
if ( V_9 -> V_128 &&
( F_30 ( V_8 , V_108 -> V_77 [ V_75 ] . V_78 ) <=
V_9 -> V_128 ) ) {
* V_285 = V_75 ;
return 0 ;
}
}
} else {
struct V_112 * V_108 =
& V_9 -> V_83 . V_113 ;
for ( V_75 = V_108 -> V_114 - 1 ; V_75 >= 0 ; V_75 -- ) {
if ( V_9 -> V_128 &&
( F_31 ( V_8 , V_108 -> V_77 [ V_75 ] . V_70 ) <=
V_9 -> V_128 ) ) {
* V_285 = V_75 ;
return 0 ;
}
}
}
* V_285 = 0 ;
return 0 ;
}
static void F_102 ( struct V_7 * V_8 ,
struct V_2 * V_240 ,
struct V_2 * V_286 )
{
struct V_1 * V_4 = F_1 ( V_240 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_287 = 10000 ;
T_1 V_60 , V_262 = 0 ;
int V_75 , V_285 ;
bool V_288 ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_74 ;
T_1 V_289 = 0 ;
struct V_259 * V_290 =
& V_8 -> V_10 . V_11 . V_73 . V_291 ;
if ( V_240 -> V_292 ) {
V_240 -> V_149 = V_8 -> V_10 . V_11 . V_293 [ V_8 -> V_10 . V_11 . V_147 ] . V_149 ;
V_240 -> V_294 = V_8 -> V_10 . V_11 . V_293 [ V_8 -> V_10 . V_11 . V_147 ] . V_294 ;
} else {
V_240 -> V_149 = 0 ;
V_240 -> V_294 = 0 ;
}
V_262 = V_290 -> V_262 ;
V_60 = V_287 ;
if ( V_9 -> V_212 ) {
V_289 = ( V_290 -> V_60 * 75 ) / 100 ;
for ( V_75 = V_108 -> V_76 - 1 ; V_75 >= 0 ; V_75 ++ ) {
if ( V_289 >= V_108 -> V_77 [ V_75 ] . V_110 ) {
V_289 = V_108 -> V_77 [ V_75 ] . V_110 ;
break;
}
}
if ( V_75 > 0 )
V_289 = V_108 -> V_77 [ 0 ] . V_110 ;
V_60 = V_289 ;
}
if ( V_240 -> V_292 ) {
if ( V_60 < V_8 -> V_10 . V_11 . V_293 [ V_8 -> V_10 . V_11 . V_147 ] . V_60 )
V_60 = V_8 -> V_10 . V_11 . V_293 [ V_8 -> V_10 . V_11 . V_147 ] . V_60 ;
}
V_4 -> V_246 = true ;
for ( V_75 = 0 ; V_75 < V_4 -> V_243 ; V_75 ++ ) {
if ( V_4 -> V_241 [ V_75 ] . V_60 < V_60 )
V_4 -> V_241 [ V_75 ] . V_60 = V_60 ;
}
if ( V_108 && V_108 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_4 -> V_243 ; V_75 ++ ) {
if ( V_9 -> V_128 &&
( V_9 -> V_128 <
F_30 ( V_8 , V_4 -> V_241 [ V_75 ] . V_269 ) ) ) {
F_120 ( V_8 , & V_285 ) ;
V_4 -> V_241 [ V_75 ] . V_60 = V_108 -> V_77 [ V_285 ] . V_110 ;
}
}
} else {
struct V_112 * V_108 =
& V_9 -> V_83 . V_113 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_243 ; V_75 ++ ) {
if ( V_9 -> V_128 &&
( V_9 -> V_128 <
F_30 ( V_8 , V_4 -> V_241 [ V_75 ] . V_269 ) ) ) {
F_120 ( V_8 , & V_285 ) ;
V_4 -> V_241 [ V_75 ] . V_60 = V_108 -> V_77 [ V_285 ] . V_115 ;
}
}
}
if ( V_9 -> V_212 ) {
for ( V_75 = 0 ; V_75 < V_4 -> V_243 ; V_75 ++ ) {
V_4 -> V_241 [ V_75 ] . V_60 = V_289 ;
}
}
V_9 -> V_295 = V_240 -> V_133 || V_240 -> V_131 ||
V_240 -> V_149 || V_240 -> V_294 ;
if ( ( V_240 -> V_296 & V_297 ) ==
V_298 )
V_9 -> V_299 = true ;
else
V_9 -> V_299 = false ;
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 ) {
V_4 -> V_300 = 0x1 ;
V_4 -> V_301 = 0x0 ;
V_4 -> V_302 = 0x1 ;
V_4 -> V_303 = 0x0 ;
} else {
V_4 -> V_300 = 0x3 ;
V_4 -> V_301 = 0x0 ;
V_4 -> V_302 = 0x3 ;
V_4 -> V_303 = 0x0 ;
if ( V_9 -> V_83 . V_304 ) {
V_288 = ( V_262 >= V_9 -> V_83 . V_263 [ 3 ] ) ||
V_9 -> V_295 || ( V_8 -> V_10 . V_11 . V_305 >= 3 ) ||
V_9 -> V_306 ;
V_4 -> V_300 = V_288 ? 0x2 : 0x3 ;
V_4 -> V_301 = 0x2 ;
V_4 -> V_302 = V_288 ? 0x2 : 0x3 ;
V_4 -> V_303 = 0x2 ;
}
}
}
static void F_121 ( struct V_7 * V_8 ,
T_1 V_59 , bool V_26 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_64 [ V_59 ] . V_307 = V_26 ? 1 : 0 ;
}
static int F_104 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_308 = 10000 ;
T_1 V_75 ;
if ( V_9 -> V_242 > V_9 -> V_244 )
return - V_18 ;
for ( V_75 = V_9 -> V_242 ; V_75 <= V_9 -> V_244 ; V_75 ++ ) {
V_9 -> V_64 [ V_75 ] . V_309 =
F_118 ( V_8 ,
F_122 ( V_9 -> V_64 [ V_75 ] . V_67 ) ,
V_308 ) ;
}
return 0 ;
}
static int F_105 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
bool V_288 ;
struct V_259 * V_290 =
& V_8 -> V_10 . V_11 . V_73 . V_291 ;
T_1 V_262 = V_290 -> V_262 ;
if ( V_9 -> V_242 > V_9 -> V_244 )
return - V_18 ;
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 ) {
for ( V_75 = V_9 -> V_242 ; V_75 <= V_9 -> V_244 ; V_75 ++ ) {
V_9 -> V_64 [ V_75 ] . V_310 = 1 ;
V_9 -> V_64 [ V_75 ] . V_311 = 0 ;
V_9 -> V_64 [ V_75 ] . V_312 = 0 ;
}
if ( ! V_9 -> V_83 . V_304 )
return 0 ;
V_288 = ( ( V_262 >= V_9 -> V_83 . V_263 [ 3 ] ) ||
( V_8 -> V_10 . V_11 . V_305 >= 3 ) || V_9 -> V_295 ) ;
if ( V_288 ) {
for ( V_75 = V_9 -> V_242 ; V_75 <= V_9 -> V_244 ; V_75 ++ )
V_9 -> V_64 [ V_75 ] . V_310 = 0 ;
} else {
if ( V_9 -> V_299 )
V_9 -> V_64 [ 0 ] . V_311 = 1 ;
V_9 -> V_64 [ 1 ] . V_310 = 0 ;
V_9 -> V_64 [ 2 ] . V_310 = 0 ;
V_9 -> V_64 [ 3 ] . V_310 = 0 ;
V_9 -> V_64 [ 4 ] . V_310 = 0 ;
}
} else {
for ( V_75 = V_9 -> V_242 ; V_75 <= V_9 -> V_244 ; V_75 ++ ) {
V_9 -> V_64 [ V_75 ] . V_310 = 1 ;
V_9 -> V_64 [ V_75 ] . V_311 = 0 ;
V_9 -> V_64 [ V_75 ] . V_312 = 0 ;
}
if ( V_9 -> V_83 . V_304 && V_9 -> V_299 ) {
V_9 -> V_64 [ V_9 -> V_242 ] . V_312 = 0x28 ;
V_9 -> V_64 [ V_9 -> V_242 ] . V_310 = 0 ;
if ( V_9 -> V_242 != V_9 -> V_244 )
V_9 -> V_64 [ V_9 -> V_242 ] . V_311 = 1 ;
}
}
return 0 ;
}
static int F_106 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
if ( V_9 -> V_242 > V_9 -> V_244 )
return - V_18 ;
for ( V_75 = V_9 -> V_242 ; V_75 <= V_9 -> V_244 ; V_75 ++ )
V_9 -> V_64 [ V_75 ] . V_313 = ( V_75 == V_9 -> V_244 ) ? 1 : 0 ;
return 0 ;
}
static void F_66 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_74 ;
if ( V_108 && V_108 -> V_76 ) {
T_1 V_70 ;
V_9 -> V_109 = 0 ;
for ( V_75 = 0 ; V_75 < V_108 -> V_76 ; V_75 ++ ) {
if ( V_9 -> V_128 &&
( V_9 -> V_128 <
F_30 ( V_8 , V_108 -> V_77 [ V_75 ] . V_78 ) ) )
break;
F_25 ( V_8 , V_75 , V_108 -> V_77 [ V_75 ] . V_110 ) ;
V_70 = F_29 ( V_8 ,
& V_9 -> V_83 . V_69 ,
V_108 -> V_77 [ V_75 ] . V_78 ) ;
F_32 ( V_8 , V_75 , V_70 ) ;
F_33 ( V_8 , V_75 , V_9 -> V_88 [ V_75 ] ) ;
F_121 ( V_8 , V_75 , true ) ;
V_9 -> V_109 ++ ;
}
} else {
struct V_112 * V_108 =
& V_9 -> V_83 . V_113 ;
V_9 -> V_109 = 0 ;
for ( V_75 = 0 ; V_75 < V_108 -> V_114 ; V_75 ++ ) {
if ( V_9 -> V_128 &&
V_9 -> V_128 <
F_31 ( V_8 , V_108 -> V_77 [ V_75 ] . V_70 ) )
break;
F_25 ( V_8 , V_75 , V_108 -> V_77 [ V_75 ] . V_115 ) ;
F_32 ( V_8 , V_75 , V_108 -> V_77 [ V_75 ] . V_70 ) ;
F_33 ( V_8 , V_75 , V_9 -> V_88 [ V_75 ] ) ;
F_121 ( V_8 , V_75 , true ) ;
V_9 -> V_109 ++ ;
}
}
for ( V_75 = 0 ; V_75 < V_120 ; V_75 ++ )
F_35 ( V_8 , V_75 , false ) ;
}
static void F_107 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
for ( V_75 = 0 ; V_75 < V_120 ; V_75 ++ ) {
if ( V_75 >= V_9 -> V_242 && V_75 <= V_9 -> V_244 )
F_35 ( V_8 , V_75 , true ) ;
}
}
static int F_113 ( struct V_7 * V_8 , T_1 V_251 )
{
T_1 V_314 = ( 1 << V_251 ) ;
return F_83 ( V_8 ,
V_315 ,
V_314 ) ;
}
static int F_45 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 , V_314 = 0 ;
for ( V_75 = V_9 -> V_242 ; V_75 <= V_9 -> V_244 ; V_75 ++ )
V_314 |= ( 1 << V_75 ) ;
return F_83 ( V_8 ,
V_315 ,
V_314 ) ;
}
static void F_108 ( struct V_7 * V_8 ,
struct V_2 * V_240 )
{
struct V_1 * V_178 = F_1 ( V_240 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_316 ;
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 )
return;
if ( V_9 -> V_83 . V_304 ) {
V_316 = F_4 ( V_317 ) ;
V_316 &= ~ ( V_318 | V_319 |
V_320 | V_321 ) ;
V_316 |= ( F_123 ( V_178 -> V_300 ) |
F_124 ( V_178 -> V_301 ) |
F_125 ( V_178 -> V_302 ) |
F_126 ( V_178 -> V_303 ) ) ;
F_7 ( V_317 , V_316 ) ;
}
}
static int F_69 ( struct V_7 * V_8 ,
int V_322 , int V_323 )
{
int V_324 = 0 * 1000 ;
int V_325 = 255 * 1000 ;
T_1 V_42 ;
if ( V_324 < V_322 )
V_324 = V_322 ;
if ( V_325 > V_323 )
V_325 = V_323 ;
if ( V_325 < V_324 ) {
F_63 ( L_19 , V_324 , V_325 ) ;
return - V_18 ;
}
V_42 = F_4 ( V_326 ) ;
V_42 &= ~ ( V_327 | V_328 ) ;
V_42 |= ( F_127 ( 49 + ( V_325 / 1000 ) ) |
F_128 ( 49 + ( V_324 / 1000 ) ) ) ;
F_7 ( V_326 , V_42 ) ;
V_8 -> V_10 . V_11 . V_329 . V_322 = V_324 ;
V_8 -> V_10 . V_11 . V_329 . V_323 = V_325 ;
return 0 ;
}
static int F_129 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_330 * V_331 = & V_8 -> V_331 ;
int V_59 = F_130 ( V_332 , V_333 ) ;
union V_334 * V_334 ;
V_53 V_335 , V_336 ;
T_2 V_337 ;
int V_75 ;
if ( F_131 ( V_331 -> V_338 , V_59 , NULL ,
& V_335 , & V_336 , & V_337 ) ) {
V_334 = (union V_334 * ) ( V_331 -> V_338 -> V_339 +
V_337 ) ;
if ( V_336 != 8 ) {
F_63 ( L_20 , V_335 , V_336 ) ;
return - V_18 ;
}
V_9 -> V_83 . V_268 = F_132 ( V_334 -> V_340 . V_341 ) ;
V_9 -> V_83 . V_342 = F_132 ( V_334 -> V_340 . V_343 ) ;
V_9 -> V_83 . V_270 =
F_133 ( V_334 -> V_340 . V_344 ) ;
if ( V_334 -> V_340 . V_345 == 0 )
V_9 -> V_83 . V_346 = 203 ;
else
V_9 -> V_83 . V_346 = V_334 -> V_340 . V_345 ;
if ( V_334 -> V_340 . V_347 == 0 )
V_9 -> V_83 . V_348 = 5 ;
else
V_9 -> V_83 . V_348 = V_334 -> V_340 . V_347 ;
if ( V_9 -> V_83 . V_346 <= V_9 -> V_83 . V_348 ) {
F_63 ( L_21 ) ;
}
if ( F_132 ( V_334 -> V_340 . V_349 ) & ( 1 << 3 ) )
V_9 -> V_83 . V_304 = true ;
else
V_9 -> V_83 . V_304 = false ;
for ( V_75 = 0 ; V_75 < V_350 ; V_75 ++ ) {
V_9 -> V_83 . V_263 [ V_75 ] =
F_132 ( V_334 -> V_340 . V_351 [ V_75 ] ) ;
V_9 -> V_83 . V_352 [ V_75 ] =
F_132 ( V_334 -> V_340 . V_353 [ V_75 ] ) ;
}
if ( F_132 ( V_334 -> V_340 . V_354 ) &
V_355 )
V_9 -> V_124 = true ;
F_134 ( V_8 ,
& V_9 -> V_83 . V_113 ,
V_334 -> V_340 . V_356 ) ;
F_135 ( V_8 ,
& V_9 -> V_83 . V_69 ,
V_334 -> V_340 . V_356 ) ;
F_114 ( V_8 ,
& V_8 -> V_10 . V_11 . V_73 . V_291 ) ;
}
return 0 ;
}
static void F_136 ( struct V_7 * V_8 ,
struct V_1 * V_4 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_4 -> V_243 = 1 ;
V_4 -> V_241 [ 0 ] = V_9 -> V_111 ;
}
static void F_137 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_357 * V_358 ,
V_53 V_359 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_3 -> V_360 = F_132 ( V_358 -> V_361 ) ;
V_3 -> V_296 = F_133 ( V_358 -> V_362 ) ;
V_3 -> V_363 = F_133 ( V_358 -> V_364 ) ;
if ( V_365 < V_359 ) {
V_3 -> V_131 = F_132 ( V_358 -> V_366 ) ;
V_3 -> V_133 = F_132 ( V_358 -> V_367 ) ;
} else {
V_3 -> V_131 = 0 ;
V_3 -> V_133 = 0 ;
}
if ( V_3 -> V_296 & V_368 ) {
V_8 -> V_10 . V_11 . V_185 = V_3 ;
F_136 ( V_8 , V_4 ) ;
}
if ( V_3 -> V_296 & V_369 )
V_8 -> V_10 . V_11 . V_370 = V_3 ;
}
static void F_138 ( struct V_7 * V_8 ,
struct V_2 * V_3 , int V_59 ,
union V_371 * V_372 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_373 * V_374 = & V_4 -> V_241 [ V_59 ] ;
T_1 V_60 ;
V_60 = F_133 ( V_372 -> V_375 . V_376 ) ;
V_60 |= V_372 -> V_375 . V_377 << 16 ;
V_374 -> V_60 = V_60 ;
V_374 -> V_269 = V_372 -> V_375 . V_378 ;
V_4 -> V_243 = V_59 + 1 ;
if ( V_9 -> V_283 ) {
V_374 -> V_271 = 5 ;
V_374 -> V_272 = 5 ;
}
}
static int F_139 ( struct V_7 * V_8 )
{
struct V_330 * V_331 = & V_8 -> V_331 ;
struct V_357 * V_358 ;
union V_379 * V_380 ;
int V_75 , V_381 , V_382 , V_383 , V_384 ;
union V_371 * V_372 ;
struct V_385 * V_386 ;
struct V_387 * V_388 ;
struct V_389 * V_390 ;
union V_391 * V_391 ;
int V_59 = F_130 ( V_332 , V_392 ) ;
T_2 V_337 ;
V_53 V_335 , V_336 ;
V_53 * V_393 ;
struct V_1 * V_4 ;
if ( ! F_131 ( V_331 -> V_338 , V_59 , NULL ,
& V_335 , & V_336 , & V_337 ) )
return - V_18 ;
V_391 = (union V_391 * ) ( V_331 -> V_338 -> V_339 + V_337 ) ;
V_386 = (struct V_385 * )
( V_331 -> V_338 -> V_339 + V_337 +
F_133 ( V_391 -> V_394 . V_395 ) ) ;
V_388 = (struct V_387 * )
( V_331 -> V_338 -> V_339 + V_337 +
F_133 ( V_391 -> V_394 . V_396 ) ) ;
V_390 = (struct V_389 * )
( V_331 -> V_338 -> V_339 + V_337 +
F_133 ( V_391 -> V_394 . V_397 ) ) ;
V_8 -> V_10 . V_11 . V_4 = F_140 ( sizeof( struct V_2 ) *
V_386 -> V_398 , V_399 ) ;
if ( ! V_8 -> V_10 . V_11 . V_4 )
return - V_400 ;
V_393 = ( V_53 * ) V_386 -> V_401 ;
for ( V_75 = 0 ; V_75 < V_386 -> V_398 ; V_75 ++ ) {
V_53 * V_260 ;
V_380 = (union V_379 * ) V_393 ;
V_383 = V_380 -> V_402 . V_403 ;
V_358 = (struct V_357 * )
& V_390 -> V_404 [ V_383 ] ;
if ( ! V_8 -> V_10 . V_380 [ V_75 ] . V_372 )
return - V_18 ;
V_4 = F_140 ( sizeof( struct V_1 ) , V_399 ) ;
if ( V_4 == NULL ) {
F_141 ( V_8 -> V_10 . V_11 . V_4 ) ;
return - V_400 ;
}
V_8 -> V_10 . V_11 . V_4 [ V_75 ] . V_5 = V_4 ;
V_382 = 0 ;
V_260 = ( V_53 * ) & V_380 -> V_402 . V_405 [ 0 ] ;
for ( V_381 = 0 ; V_381 < V_380 -> V_402 . V_406 ; V_381 ++ ) {
V_384 = V_260 [ V_381 ] ;
if ( V_384 >= V_388 -> V_398 )
continue;
if ( V_382 >= V_407 )
break;
V_372 = (union V_371 * )
( ( V_53 * ) & V_388 -> V_408 [ 0 ] +
( V_384 * V_388 -> V_409 ) ) ;
F_138 ( V_8 ,
& V_8 -> V_10 . V_11 . V_4 [ V_75 ] , V_382 ,
V_372 ) ;
V_382 ++ ;
}
F_137 ( V_8 , & V_8 -> V_10 . V_11 . V_4 [ V_75 ] ,
V_358 ,
V_390 -> V_409 ) ;
V_393 += 2 + V_380 -> V_402 . V_406 ;
}
V_8 -> V_10 . V_11 . V_410 = V_386 -> V_398 ;
for ( V_75 = 0 ; V_75 < V_411 ; V_75 ++ ) {
T_1 V_60 ;
V_384 = V_8 -> V_10 . V_11 . V_293 [ V_75 ] . V_412 ;
V_372 = (union V_371 * )
& V_388 -> V_408 [ V_384 * V_388 -> V_409 ] ;
V_60 = F_133 ( V_372 -> V_375 . V_376 ) ;
V_60 |= V_372 -> V_375 . V_377 << 16 ;
V_8 -> V_10 . V_11 . V_293 [ V_75 ] . V_60 = V_60 ;
V_8 -> V_10 . V_11 . V_293 [ V_75 ] . V_262 = 0 ;
}
return 0 ;
}
int F_142 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
int V_36 , V_75 ;
V_9 = F_140 ( sizeof( struct V_6 ) , V_399 ) ;
if ( V_9 == NULL )
return - V_400 ;
V_8 -> V_10 . V_11 . V_12 = V_9 ;
V_36 = F_143 ( V_8 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_144 ( V_8 ) ;
if ( V_36 )
return V_36 ;
for ( V_75 = 0 ; V_75 < V_407 ; V_75 ++ )
V_9 -> V_88 [ V_75 ] = V_413 ;
V_9 -> V_46 = V_414 ;
V_9 -> V_247 = true ;
V_9 -> V_415 = true ;
V_9 -> V_38 = true ;
V_9 -> V_416 = false ;
if ( V_9 -> V_416 ) {
V_9 -> V_27 = true ;
V_9 -> V_30 = true ;
V_9 -> V_32 = true ;
V_9 -> V_34 = true ;
}
V_9 -> V_283 = true ;
V_9 -> V_184 = true ;
V_9 -> V_306 = false ;
V_9 -> V_183 = true ;
V_9 -> V_86 = 0 ;
V_9 -> V_106 = false ;
V_9 -> V_192 = false ;
V_9 -> V_227 = true ;
V_9 -> V_211 = true ;
V_9 -> V_231 = false ;
V_9 -> V_234 = false ;
V_9 -> V_237 = false ;
V_9 -> V_212 = false ;
V_36 = F_129 ( V_8 ) ;
if ( V_36 )
return V_36 ;
F_115 ( V_8 ) ;
F_116 ( V_8 ) ;
V_36 = F_139 ( V_8 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_258 = true ;
return 0 ;
}
void F_145 ( struct V_7 * V_8 ,
struct V_417 * V_418 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_419 =
( F_4 ( V_420 ) & V_421 ) >>
V_422 ;
T_1 V_60 , V_42 ;
T_2 V_261 ;
if ( V_419 >= V_423 ) {
F_146 ( V_418 , L_22 , V_419 ) ;
} else {
V_60 = F_122 ( V_9 -> V_64 [ V_419 ] . V_67 ) ;
V_42 = ( F_4 ( V_424 ) & V_425 ) >>
V_426 ;
V_261 = F_30 ( V_8 , ( T_2 ) V_42 ) ;
F_146 ( V_418 , L_23 ,
V_419 , V_60 , V_261 ) ;
}
}
void F_147 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
int V_75 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_148 ( V_3 -> V_296 , V_3 -> V_363 ) ;
F_149 ( V_3 -> V_360 ) ;
F_150 ( L_24 , V_3 -> V_131 , V_3 -> V_133 ) ;
for ( V_75 = 0 ; V_75 < V_4 -> V_243 ; V_75 ++ ) {
struct V_373 * V_374 = & V_4 -> V_241 [ V_75 ] ;
F_150 ( L_25 ,
V_75 , V_374 -> V_60 ,
F_30 ( V_8 , V_374 -> V_269 ) ) ;
}
F_151 ( V_8 , V_3 ) ;
}
void F_152 ( struct V_7 * V_8 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_8 -> V_10 . V_11 . V_410 ; V_75 ++ ) {
F_141 ( V_8 -> V_10 . V_11 . V_4 [ V_75 ] . V_5 ) ;
}
F_141 ( V_8 -> V_10 . V_11 . V_4 ) ;
F_141 ( V_8 -> V_10 . V_11 . V_12 ) ;
F_153 ( V_8 ) ;
}
void F_154 ( struct V_7 * V_8 )
{
}
T_1 F_155 ( struct V_7 * V_8 , bool V_427 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_428 = F_1 ( & V_9 -> V_181 ) ;
if ( V_427 )
return V_428 -> V_241 [ 0 ] . V_60 ;
else
return V_428 -> V_241 [ V_428 -> V_243 - 1 ] . V_60 ;
}
T_1 F_156 ( struct V_7 * V_8 , bool V_427 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
return V_9 -> V_83 . V_342 ;
}
