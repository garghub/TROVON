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
static void F_64 ( struct V_7 * V_8 , bool V_26 )
{
T_1 V_184 ;
V_184 = F_4 ( V_185 ) ;
if ( V_26 )
V_184 |= V_186 | V_187 ;
else
V_184 &= ~ ( V_186 | V_187 ) ;
F_7 ( V_185 , V_184 ) ;
}
int F_65 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 ;
V_36 = F_16 ( V_8 ) ;
if ( V_36 ) {
F_63 ( L_2 ) ;
return V_36 ;
}
F_66 ( V_8 ) ;
F_67 ( V_8 ) ;
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
if ( V_9 -> V_188 ) {
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
F_59 ( V_8 , V_8 -> V_10 . V_11 . V_189 ) ;
return V_36 ;
}
int F_68 ( struct V_7 * V_8 )
{
int V_36 = 0 ;
if ( V_8 -> V_190 . V_191 &&
F_69 ( V_8 -> V_10 . V_192 ) ) {
V_36 = F_70 ( V_8 , V_193 , V_194 ) ;
if ( V_36 ) {
F_63 ( L_16 ) ;
return V_36 ;
}
F_64 ( V_8 , true ) ;
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
if ( V_8 -> V_101 == V_103 )
F_76 ( V_8 , false ) ;
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
F_64 ( V_8 , false ) ;
F_59 ( V_8 , V_8 -> V_10 . V_11 . V_189 ) ;
}
static void F_77 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_105 = 0 ;
}
static int F_66 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 = 0 ;
if ( V_9 -> V_195 ) {
T_2 V_42 ;
V_42 = 45 ;
V_9 -> V_196 = F_34 ( V_42 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_197 ) ,
( V_53 * ) & V_9 -> V_196 ,
sizeof( T_2 ) , V_9 -> V_46 ) ;
V_42 = 30 ;
V_9 -> V_198 = F_34 ( V_42 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_199 ) ,
( V_53 * ) & V_9 -> V_198 ,
sizeof( T_2 ) , V_9 -> V_46 ) ;
}
return V_36 ;
}
static void F_78 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_200 = false ;
V_9 -> V_201 = false ;
V_9 -> V_202 = false ;
V_9 -> V_203 = false ;
}
static int F_79 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_204 : V_205 ) ;
}
static int F_80 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_206 : V_207 ) ;
}
static int F_81 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_208 : V_209 ) ;
}
static int F_82 ( struct V_7 * V_8 , bool V_26 )
{
return F_15 ( V_8 , V_26 ?
V_210 : V_211 ) ;
}
static int F_83 ( struct V_7 * V_8 , bool V_212 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_125 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_126 ;
int V_36 ;
T_1 V_23 ;
if ( ! V_212 ) {
if ( V_108 -> V_76 )
V_9 -> V_213 = V_108 -> V_76 - 1 ;
else
V_9 -> V_213 = 0 ;
if ( ! V_9 -> V_214 || V_9 -> V_215 ) {
V_23 = 1 << V_9 -> V_213 ;
} else {
V_23 = 0x1f ;
}
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_216 ) ,
( V_217 * ) & V_9 -> V_213 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
F_84 ( V_8 ,
V_218 ,
V_23 ) ;
}
return F_79 ( V_8 , ! V_212 ) ;
}
static V_53 F_85 ( struct V_7 * V_8 , T_1 V_149 )
{
V_53 V_75 ;
struct V_144 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_145 ;
for ( V_75 = 0 ; V_75 < V_108 -> V_76 ; V_75 ++ ) {
if ( V_108 -> V_77 [ V_75 ] . V_149 >= V_149 )
break;
}
return V_75 ;
}
static int F_86 ( struct V_7 * V_8 ,
struct V_2 * V_219 ,
struct V_2 * V_220 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_144 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_145 ;
int V_36 ;
if ( V_219 -> V_149 > 0 && V_220 -> V_149 == 0 ) {
F_73 ( V_8 , false ) ;
F_87 ( V_8 , V_221 , false ) ;
if ( V_9 -> V_215 )
V_9 -> V_222 = V_108 -> V_76 - 1 ;
else
V_9 -> V_222 = F_85 ( V_8 , V_219 -> V_149 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_223 ) ,
( V_53 * ) & V_9 -> V_222 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
if ( V_9 -> V_215 )
F_84 ( V_8 ,
V_224 ,
( 1 << V_9 -> V_222 ) ) ;
F_80 ( V_8 , true ) ;
} else if ( V_219 -> V_149 == 0 && V_220 -> V_149 > 0 ) {
F_80 ( V_8 , false ) ;
F_87 ( V_8 , V_221 , true ) ;
F_73 ( V_8 , true ) ;
}
return 0 ;
}
static int F_88 ( struct V_7 * V_8 , bool V_212 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_159 ;
int V_36 ;
if ( ! V_212 ) {
if ( V_9 -> V_215 )
V_9 -> V_225 = V_108 -> V_76 - 1 ;
else
V_9 -> V_225 = 0 ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_226 ) ,
( V_53 * ) & V_9 -> V_225 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
if ( V_9 -> V_215 )
F_84 ( V_8 ,
V_227 ,
( 1 << V_9 -> V_225 ) ) ;
}
return F_81 ( V_8 , ! V_212 ) ;
}
static V_53 F_89 ( struct V_7 * V_8 )
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
static void F_90 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_53 V_177 ;
if ( ! V_9 -> V_215 ) {
V_177 = F_89 ( V_8 ) ;
if ( V_177 != V_9 -> V_177 ) {
V_9 -> V_177 = V_177 ;
F_84 ( V_8 ,
V_228 ,
( 1 << V_9 -> V_177 ) ) ;
}
}
}
static int F_91 ( struct V_7 * V_8 , bool V_212 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_167 ;
int V_36 ;
if ( ! V_212 ) {
if ( V_9 -> V_215 )
V_9 -> V_177 = V_108 -> V_76 - 1 ;
else
V_9 -> V_177 = F_89 ( V_8 ) ;
V_36 = F_20 ( V_8 ,
V_9 -> V_47 +
F_18 ( V_51 , V_229 ) ,
( V_53 * ) & V_9 -> V_177 ,
sizeof( V_53 ) ,
V_9 -> V_46 ) ;
if ( V_36 )
return V_36 ;
if ( V_9 -> V_215 )
F_84 ( V_8 ,
V_228 ,
( 1 << V_9 -> V_177 ) ) ;
}
return F_82 ( V_8 , ! V_212 ) ;
}
void F_74 ( struct V_7 * V_8 , bool V_212 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_200 == V_212 )
return;
V_9 -> V_200 = V_212 ;
if ( V_212 ) {
if ( V_9 -> V_230 ) {
F_92 ( V_8 ) ;
F_87 ( V_8 , V_231 , false ) ;
}
F_83 ( V_8 , V_212 ) ;
if ( V_9 -> V_230 )
F_15 ( V_8 , V_232 ) ;
} else {
if ( V_9 -> V_230 ) {
F_15 ( V_8 , V_233 ) ;
F_93 ( V_8 ) ;
F_94 ( V_8 ) ;
F_87 ( V_8 , V_231 , true ) ;
}
F_83 ( V_8 , V_212 ) ;
}
}
static void F_73 ( struct V_7 * V_8 , bool V_212 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_201 == V_212 )
return;
V_9 -> V_201 = V_212 ;
if ( V_212 ) {
if ( V_9 -> V_234 ) {
F_15 ( V_8 , V_235 ) ;
}
} else {
if ( V_9 -> V_234 ) {
F_15 ( V_8 , V_236 ) ;
F_95 ( V_8 ) ;
F_96 ( V_8 ) ;
}
}
}
static void F_72 ( struct V_7 * V_8 , bool V_212 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_202 == V_212 )
return;
V_9 -> V_202 = V_212 ;
if ( V_212 ) {
F_88 ( V_8 , true ) ;
if ( V_9 -> V_237 )
F_15 ( V_8 , V_238 ) ;
} else {
if ( V_9 -> V_237 )
F_15 ( V_8 , V_239 ) ;
F_88 ( V_8 , false ) ;
}
}
static void F_71 ( struct V_7 * V_8 , bool V_212 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_203 == V_212 )
return;
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 )
return;
V_9 -> V_203 = V_212 ;
if ( V_212 ) {
F_91 ( V_8 , true ) ;
if ( V_9 -> V_240 )
F_15 ( V_8 , V_241 ) ;
} else {
if ( V_9 -> V_240 )
F_15 ( V_8 , V_242 ) ;
F_91 ( V_8 , false ) ;
}
}
static void F_97 ( struct V_7 * V_8 ,
struct V_2 * V_243 )
{
struct V_1 * V_178 = F_1 ( V_243 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_74 ;
if ( V_108 && V_108 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_9 -> V_109 ; V_75 ++ ) {
if ( ( V_108 -> V_77 [ V_75 ] . V_110 >= V_178 -> V_244 [ 0 ] . V_60 ) ||
( V_75 == ( V_9 -> V_109 - 1 ) ) ) {
V_9 -> V_245 = V_75 ;
break;
}
}
for ( V_75 = V_9 -> V_109 - 1 ; V_75 > 0 ; V_75 -- ) {
if ( V_108 -> V_77 [ V_75 ] . V_110 <= V_178 -> V_244 [ V_178 -> V_246 - 1 ] . V_60 )
break;
}
V_9 -> V_247 = V_75 ;
if ( V_9 -> V_245 > V_9 -> V_247 ) {
if ( ( V_178 -> V_244 [ 0 ] . V_60 - V_108 -> V_77 [ V_9 -> V_247 ] . V_110 ) >
( V_108 -> V_77 [ V_9 -> V_245 ] . V_110 - V_178 -> V_244 [ V_178 -> V_246 - 1 ] . V_60 ) )
V_9 -> V_247 = V_9 -> V_245 ;
else
V_9 -> V_245 = V_9 -> V_247 ;
}
} else {
struct V_112 * V_108 =
& V_9 -> V_83 . V_113 ;
for ( V_75 = 0 ; V_75 < ( int ) V_9 -> V_109 ; V_75 ++ ) {
if ( V_108 -> V_77 [ V_75 ] . V_115 >= V_178 -> V_244 [ 0 ] . V_60 ||
V_75 == ( int ) ( V_9 -> V_109 - 1 ) ) {
V_9 -> V_245 = V_75 ;
break;
}
}
for ( V_75 = V_9 -> V_109 - 1 ; V_75 > 0 ; V_75 -- ) {
if ( V_108 -> V_77 [ V_75 ] . V_115 <=
V_178 -> V_244 [ V_178 -> V_246 - 1 ] . V_60 )
break;
}
V_9 -> V_247 = V_75 ;
if ( V_9 -> V_245 > V_9 -> V_247 ) {
if ( ( V_178 -> V_244 [ 0 ] . V_60 -
V_108 -> V_77 [ V_9 -> V_247 ] . V_115 ) >
( V_108 -> V_77 [ V_9 -> V_245 ] . V_115 -
V_178 -> V_244 [ V_178 -> V_246 - 1 ] . V_60 ) )
V_9 -> V_247 = V_9 -> V_245 ;
else
V_9 -> V_245 = V_9 -> V_247 ;
}
}
}
static int F_98 ( struct V_7 * V_8 ,
struct V_2 * V_243 )
{
struct V_1 * V_178 = F_1 ( V_243 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 = 0 ;
V_53 V_248 ;
if ( V_9 -> V_124 ) {
V_248 = V_178 -> V_249 ?
V_9 -> V_64 [ V_9 -> V_57 ] . V_151 : 0 ;
V_36 = F_20 ( V_8 ,
( V_9 -> V_47 +
F_18 ( V_51 , V_118 ) +
( V_9 -> V_57 * sizeof( V_119 ) ) +
F_18 ( V_119 , V_151 ) ) ,
& V_248 ,
sizeof( V_53 ) , V_9 -> V_46 ) ;
}
return V_36 ;
}
static int F_76 ( struct V_7 * V_8 ,
bool V_26 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
int V_36 = 0 ;
if ( V_26 ) {
if ( V_9 -> V_250 && ! V_9 -> V_251 ) {
V_36 = F_15 ( V_8 , V_252 ) ;
if ( V_36 == 0 )
V_9 -> V_251 = true ;
}
} else {
if ( V_9 -> V_250 && V_9 -> V_251 ) {
V_36 = F_15 ( V_8 , V_253 ) ;
if ( V_36 == 0 )
V_9 -> V_251 = false ;
}
}
return V_36 ;
}
int F_99 ( struct V_7 * V_8 ,
enum V_254 V_255 )
{
int V_36 ;
if ( V_255 == V_256 ) {
V_36 = F_100 ( V_8 ) ;
if ( V_36 )
return V_36 ;
} else if ( V_255 == V_257 ) {
V_36 = F_43 ( V_8 ) ;
if ( V_36 )
return V_36 ;
} else if ( V_255 == V_258 ) {
V_36 = F_44 ( V_8 ) ;
if ( V_36 )
return V_36 ;
}
V_8 -> V_10 . V_11 . V_259 = V_255 ;
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
struct V_2 * V_260 = & V_9 -> V_179 ;
int V_36 ;
if ( V_9 -> V_183 ) {
V_36 = F_62 ( V_8 , V_8 -> V_10 . V_11 . V_261 ) ;
if ( V_36 ) {
F_63 ( L_1 ) ;
return V_36 ;
}
}
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 ) {
if ( V_9 -> V_262 ) {
F_97 ( V_8 , V_178 ) ;
F_98 ( V_8 , V_178 ) ;
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
V_36 = F_86 ( V_8 , V_178 , V_260 ) ;
if ( V_36 ) {
F_63 ( L_18 ) ;
return V_36 ;
}
F_46 ( V_8 ) ;
if ( V_8 -> V_101 == V_103 )
F_76 ( V_8 , true ) ;
}
} else {
if ( V_9 -> V_262 ) {
F_97 ( V_8 , V_178 ) ;
F_98 ( V_8 , V_178 ) ;
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
V_36 = F_86 ( V_8 , V_178 , V_260 ) ;
if ( V_36 ) {
F_63 ( L_18 ) ;
return V_36 ;
}
F_90 ( V_8 ) ;
F_46 ( V_8 ) ;
F_76 ( V_8 , true ) ;
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
F_78 ( V_8 ) ;
F_77 ( V_8 ) ;
}
static void F_112 ( struct V_7 * V_8 ,
struct V_263 * V_108 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
if ( V_9 -> V_83 . V_113 . V_114 > 0 ) {
int V_264 = V_9 -> V_83 . V_113 . V_114 - 1 ;
V_108 -> V_60 =
V_9 -> V_83 . V_113 . V_77 [ V_264 ] . V_115 ;
V_108 -> V_265 =
F_31 ( V_8 ,
V_9 -> V_83 . V_113 . V_77 [ V_264 ] . V_70 ) ;
}
V_108 -> V_266 = V_9 -> V_83 . V_267 [ 0 ] ;
}
static void F_113 ( struct V_7 * V_8 )
{
int V_75 ;
struct V_125 * V_268 =
& V_8 -> V_10 . V_11 . V_73 . V_126 ;
struct V_144 * V_269 =
& V_8 -> V_10 . V_11 . V_73 . V_145 ;
struct V_71 * V_270 =
& V_8 -> V_10 . V_11 . V_73 . V_159 ;
struct V_71 * V_271 =
& V_8 -> V_10 . V_11 . V_73 . V_167 ;
if ( V_268 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_268 -> V_76 ; V_75 ++ )
V_268 -> V_77 [ V_75 ] . V_78 =
F_30 ( V_8 ,
V_268 -> V_77 [ V_75 ] . V_78 ) ;
}
if ( V_269 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_269 -> V_76 ; V_75 ++ )
V_269 -> V_77 [ V_75 ] . V_78 =
F_30 ( V_8 ,
V_269 -> V_77 [ V_75 ] . V_78 ) ;
}
if ( V_270 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_270 -> V_76 ; V_75 ++ )
V_270 -> V_77 [ V_75 ] . V_78 =
F_30 ( V_8 ,
V_270 -> V_77 [ V_75 ] . V_78 ) ;
}
if ( V_271 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_271 -> V_76 ; V_75 ++ )
V_271 -> V_77 [ V_75 ] . V_78 =
F_30 ( V_8 ,
V_271 -> V_77 [ V_75 ] . V_78 ) ;
}
}
static void F_114 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_111 . V_60 = V_9 -> V_83 . V_272 ;
V_9 -> V_111 . V_273 = V_9 -> V_83 . V_274 ;
V_9 -> V_111 . V_275 = 0 ;
V_9 -> V_111 . V_276 = 0 ;
V_9 -> V_111 . V_277 = 1 ;
V_9 -> V_111 . V_278 = 0 ;
V_9 -> V_111 . V_279 = 0 ;
V_9 -> V_111 . V_280 = 0 ;
}
static int F_100 ( struct V_7 * V_8 )
{
int V_36 ;
T_1 V_281 , V_75 ;
V_36 = F_115 ( V_8 , & V_281 ) ;
if ( V_36 )
return V_36 ;
for ( V_75 = V_120 - 1 ; V_75 > 0 ; V_75 -- ) {
if ( V_281 & ( 1 << V_75 ) )
break;
}
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 )
return F_84 ( V_8 , V_282 , V_75 ) ;
else
return F_116 ( V_8 , V_75 ) ;
}
static int F_43 ( struct V_7 * V_8 )
{
int V_36 ;
T_1 V_281 , V_75 ;
V_36 = F_115 ( V_8 , & V_281 ) ;
if ( V_36 )
return V_36 ;
for ( V_75 = 0 ; V_75 < V_120 ; V_75 ++ ) {
if ( V_281 & ( 1 << V_75 ) )
break;
}
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 )
return F_84 ( V_8 , V_282 , V_75 ) ;
else
return F_116 ( V_8 , V_75 ) ;
}
static V_53 F_117 ( struct V_7 * V_8 ,
T_1 V_60 , T_1 V_283 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
T_1 V_284 ;
T_1 V_285 = ( V_283 > V_286 ) ?
V_283 : V_286 ;
if ( V_60 < V_285 )
return 0 ;
if ( ! V_9 -> V_287 )
return 0 ;
for ( V_75 = V_288 ; V_75 > 0 ; V_75 -- ) {
V_284 = V_60 / F_118 ( V_75 ) ;
if ( V_284 >= V_285 )
break;
}
return ( V_53 ) V_75 ;
}
static int F_119 ( struct V_7 * V_8 , int * V_289 )
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
* V_289 = V_75 ;
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
* V_289 = V_75 ;
return 0 ;
}
}
}
* V_289 = 0 ;
return 0 ;
}
static void F_102 ( struct V_7 * V_8 ,
struct V_2 * V_243 ,
struct V_2 * V_290 )
{
struct V_1 * V_4 = F_1 ( V_243 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_291 = 10000 ;
T_1 V_60 , V_266 = 0 ;
int V_75 , V_289 ;
bool V_292 ;
struct V_71 * V_108 =
& V_8 -> V_10 . V_11 . V_73 . V_74 ;
T_1 V_293 = 0 ;
struct V_263 * V_294 =
& V_8 -> V_10 . V_11 . V_73 . V_295 ;
if ( V_243 -> V_296 ) {
V_243 -> V_149 = V_8 -> V_10 . V_11 . V_297 [ V_8 -> V_10 . V_11 . V_147 ] . V_149 ;
V_243 -> V_298 = V_8 -> V_10 . V_11 . V_297 [ V_8 -> V_10 . V_11 . V_147 ] . V_298 ;
} else {
V_243 -> V_149 = 0 ;
V_243 -> V_298 = 0 ;
}
V_266 = V_294 -> V_266 ;
V_60 = V_291 ;
if ( V_9 -> V_215 ) {
V_293 = ( V_294 -> V_60 * 75 ) / 100 ;
for ( V_75 = V_108 -> V_76 - 1 ; V_75 >= 0 ; V_75 ++ ) {
if ( V_293 >= V_108 -> V_77 [ V_75 ] . V_110 ) {
V_293 = V_108 -> V_77 [ V_75 ] . V_110 ;
break;
}
}
if ( V_75 > 0 )
V_293 = V_108 -> V_77 [ 0 ] . V_110 ;
V_60 = V_293 ;
}
if ( V_243 -> V_296 ) {
if ( V_60 < V_8 -> V_10 . V_11 . V_297 [ V_8 -> V_10 . V_11 . V_147 ] . V_60 )
V_60 = V_8 -> V_10 . V_11 . V_297 [ V_8 -> V_10 . V_11 . V_147 ] . V_60 ;
}
V_4 -> V_249 = true ;
for ( V_75 = 0 ; V_75 < V_4 -> V_246 ; V_75 ++ ) {
if ( V_4 -> V_244 [ V_75 ] . V_60 < V_60 )
V_4 -> V_244 [ V_75 ] . V_60 = V_60 ;
}
if ( V_108 && V_108 -> V_76 ) {
for ( V_75 = 0 ; V_75 < V_4 -> V_246 ; V_75 ++ ) {
if ( V_9 -> V_128 &&
( V_9 -> V_128 <
F_30 ( V_8 , V_4 -> V_244 [ V_75 ] . V_273 ) ) ) {
F_119 ( V_8 , & V_289 ) ;
V_4 -> V_244 [ V_75 ] . V_60 = V_108 -> V_77 [ V_289 ] . V_110 ;
}
}
} else {
struct V_112 * V_108 =
& V_9 -> V_83 . V_113 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_246 ; V_75 ++ ) {
if ( V_9 -> V_128 &&
( V_9 -> V_128 <
F_30 ( V_8 , V_4 -> V_244 [ V_75 ] . V_273 ) ) ) {
F_119 ( V_8 , & V_289 ) ;
V_4 -> V_244 [ V_75 ] . V_60 = V_108 -> V_77 [ V_289 ] . V_115 ;
}
}
}
if ( V_9 -> V_215 ) {
for ( V_75 = 0 ; V_75 < V_4 -> V_246 ; V_75 ++ ) {
V_4 -> V_244 [ V_75 ] . V_60 = V_293 ;
}
}
V_9 -> V_299 = V_243 -> V_133 || V_243 -> V_131 ||
V_243 -> V_149 || V_243 -> V_298 ;
if ( ( V_243 -> V_300 & V_301 ) ==
V_302 )
V_9 -> V_303 = true ;
else
V_9 -> V_303 = false ;
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 ) {
V_4 -> V_304 = 0x1 ;
V_4 -> V_305 = 0x0 ;
V_4 -> V_306 = 0x1 ;
V_4 -> V_307 = 0x0 ;
} else {
V_4 -> V_304 = 0x3 ;
V_4 -> V_305 = 0x0 ;
V_4 -> V_306 = 0x3 ;
V_4 -> V_307 = 0x0 ;
if ( V_9 -> V_83 . V_308 ) {
V_292 = ( V_266 >= V_9 -> V_83 . V_267 [ 3 ] ) ||
V_9 -> V_299 || ( V_8 -> V_10 . V_11 . V_309 >= 3 ) ||
V_9 -> V_310 ;
V_4 -> V_304 = V_292 ? 0x2 : 0x3 ;
V_4 -> V_305 = 0x2 ;
V_4 -> V_306 = V_292 ? 0x2 : 0x3 ;
V_4 -> V_307 = 0x2 ;
}
}
}
static void F_120 ( struct V_7 * V_8 ,
T_1 V_59 , bool V_26 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_9 -> V_64 [ V_59 ] . V_311 = V_26 ? 1 : 0 ;
}
static int F_104 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_312 = 10000 ;
T_1 V_75 ;
if ( V_9 -> V_245 > V_9 -> V_247 )
return - V_18 ;
for ( V_75 = V_9 -> V_245 ; V_75 <= V_9 -> V_247 ; V_75 ++ ) {
V_9 -> V_64 [ V_75 ] . V_313 =
F_117 ( V_8 ,
F_121 ( V_9 -> V_64 [ V_75 ] . V_67 ) ,
V_312 ) ;
}
return 0 ;
}
static int F_105 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
bool V_292 ;
struct V_263 * V_294 =
& V_8 -> V_10 . V_11 . V_73 . V_295 ;
T_1 V_266 = V_294 -> V_266 ;
if ( V_9 -> V_245 > V_9 -> V_247 )
return - V_18 ;
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 ) {
for ( V_75 = V_9 -> V_245 ; V_75 <= V_9 -> V_247 ; V_75 ++ ) {
V_9 -> V_64 [ V_75 ] . V_314 = 1 ;
V_9 -> V_64 [ V_75 ] . V_315 = 0 ;
V_9 -> V_64 [ V_75 ] . V_316 = 0 ;
}
if ( ! V_9 -> V_83 . V_308 )
return 0 ;
V_292 = ( ( V_266 >= V_9 -> V_83 . V_267 [ 3 ] ) ||
( V_8 -> V_10 . V_11 . V_309 >= 3 ) || V_9 -> V_299 ) ;
if ( V_292 ) {
for ( V_75 = V_9 -> V_245 ; V_75 <= V_9 -> V_247 ; V_75 ++ )
V_9 -> V_64 [ V_75 ] . V_314 = 0 ;
} else {
if ( V_9 -> V_303 )
V_9 -> V_64 [ 0 ] . V_315 = 1 ;
V_9 -> V_64 [ 1 ] . V_314 = 0 ;
V_9 -> V_64 [ 2 ] . V_314 = 0 ;
V_9 -> V_64 [ 3 ] . V_314 = 0 ;
V_9 -> V_64 [ 4 ] . V_314 = 0 ;
}
} else {
for ( V_75 = V_9 -> V_245 ; V_75 <= V_9 -> V_247 ; V_75 ++ ) {
V_9 -> V_64 [ V_75 ] . V_314 = 1 ;
V_9 -> V_64 [ V_75 ] . V_315 = 0 ;
V_9 -> V_64 [ V_75 ] . V_316 = 0 ;
}
if ( V_9 -> V_83 . V_308 && V_9 -> V_303 ) {
V_9 -> V_64 [ V_9 -> V_245 ] . V_316 = 0x28 ;
V_9 -> V_64 [ V_9 -> V_245 ] . V_314 = 0 ;
if ( V_9 -> V_245 != V_9 -> V_247 )
V_9 -> V_64 [ V_9 -> V_245 ] . V_315 = 1 ;
}
}
return 0 ;
}
static int F_106 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 ;
if ( V_9 -> V_245 > V_9 -> V_247 )
return - V_18 ;
for ( V_75 = V_9 -> V_245 ; V_75 <= V_9 -> V_247 ; V_75 ++ )
V_9 -> V_64 [ V_75 ] . V_317 = ( V_75 == V_9 -> V_247 ) ? 1 : 0 ;
return 0 ;
}
static void F_67 ( struct V_7 * V_8 )
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
F_120 ( V_8 , V_75 , true ) ;
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
F_120 ( V_8 , V_75 , true ) ;
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
if ( V_75 >= V_9 -> V_245 && V_75 <= V_9 -> V_247 )
F_35 ( V_8 , V_75 , true ) ;
}
}
static int F_116 ( struct V_7 * V_8 , T_1 V_255 )
{
T_1 V_318 = ( 1 << V_255 ) ;
return F_84 ( V_8 ,
V_319 ,
V_318 ) ;
}
static int F_45 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_75 , V_318 = 0 ;
for ( V_75 = V_9 -> V_245 ; V_75 <= V_9 -> V_247 ; V_75 ++ )
V_318 |= ( 1 << V_75 ) ;
return F_84 ( V_8 ,
V_319 ,
V_318 ) ;
}
static void F_108 ( struct V_7 * V_8 ,
struct V_2 * V_243 )
{
struct V_1 * V_178 = F_1 ( V_243 ) ;
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_320 ;
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 )
return;
if ( V_9 -> V_83 . V_308 ) {
V_320 = F_4 ( V_321 ) ;
V_320 &= ~ ( V_322 | V_323 |
V_324 | V_325 ) ;
V_320 |= ( F_122 ( V_178 -> V_304 ) |
F_123 ( V_178 -> V_305 ) |
F_124 ( V_178 -> V_306 ) |
F_125 ( V_178 -> V_307 ) ) ;
F_7 ( V_321 , V_320 ) ;
}
}
static int F_70 ( struct V_7 * V_8 ,
int V_326 , int V_327 )
{
int V_328 = 0 * 1000 ;
int V_329 = 255 * 1000 ;
T_1 V_42 ;
if ( V_328 < V_326 )
V_328 = V_326 ;
if ( V_329 > V_327 )
V_329 = V_327 ;
if ( V_329 < V_328 ) {
F_63 ( L_19 , V_328 , V_329 ) ;
return - V_18 ;
}
V_42 = F_4 ( V_185 ) ;
V_42 &= ~ ( V_330 | V_331 ) ;
V_42 |= ( F_126 ( 49 + ( V_329 / 1000 ) ) |
F_127 ( 49 + ( V_328 / 1000 ) ) ) ;
F_7 ( V_185 , V_42 ) ;
V_8 -> V_10 . V_11 . V_332 . V_326 = V_328 ;
V_8 -> V_10 . V_11 . V_332 . V_327 = V_329 ;
return 0 ;
}
static int F_128 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_333 * V_334 = & V_8 -> V_334 ;
int V_59 = F_129 ( V_335 , V_336 ) ;
union V_337 * V_337 ;
V_53 V_338 , V_339 ;
T_2 V_340 ;
int V_75 ;
if ( F_130 ( V_334 -> V_341 , V_59 , NULL ,
& V_338 , & V_339 , & V_340 ) ) {
V_337 = (union V_337 * ) ( V_334 -> V_341 -> V_342 +
V_340 ) ;
if ( V_339 != 8 ) {
F_63 ( L_20 , V_338 , V_339 ) ;
return - V_18 ;
}
V_9 -> V_83 . V_272 = F_131 ( V_337 -> V_343 . V_344 ) ;
V_9 -> V_83 . V_345 = F_131 ( V_337 -> V_343 . V_346 ) ;
V_9 -> V_83 . V_274 =
F_132 ( V_337 -> V_343 . V_347 ) ;
if ( V_337 -> V_343 . V_348 == 0 )
V_9 -> V_83 . V_349 = 203 ;
else
V_9 -> V_83 . V_349 = V_337 -> V_343 . V_348 ;
if ( V_337 -> V_343 . V_350 == 0 )
V_9 -> V_83 . V_351 = 5 ;
else
V_9 -> V_83 . V_351 = V_337 -> V_343 . V_350 ;
if ( V_9 -> V_83 . V_349 <= V_9 -> V_83 . V_351 ) {
F_63 ( L_21 ) ;
}
if ( F_131 ( V_337 -> V_343 . V_352 ) & ( 1 << 3 ) )
V_9 -> V_83 . V_308 = true ;
else
V_9 -> V_83 . V_308 = false ;
for ( V_75 = 0 ; V_75 < V_353 ; V_75 ++ ) {
V_9 -> V_83 . V_267 [ V_75 ] =
F_131 ( V_337 -> V_343 . V_354 [ V_75 ] ) ;
V_9 -> V_83 . V_355 [ V_75 ] =
F_131 ( V_337 -> V_343 . V_356 [ V_75 ] ) ;
}
if ( F_131 ( V_337 -> V_343 . V_357 ) &
V_358 )
V_9 -> V_124 = true ;
F_133 ( V_8 ,
& V_9 -> V_83 . V_113 ,
V_337 -> V_343 . V_359 ) ;
F_134 ( V_8 ,
& V_9 -> V_83 . V_69 ,
V_337 -> V_343 . V_359 ) ;
F_112 ( V_8 ,
& V_8 -> V_10 . V_11 . V_73 . V_295 ) ;
}
return 0 ;
}
static void F_135 ( struct V_7 * V_8 ,
struct V_1 * V_4 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
V_4 -> V_246 = 1 ;
V_4 -> V_244 [ 0 ] = V_9 -> V_111 ;
}
static void F_136 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_360 * V_361 ,
V_53 V_362 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_3 -> V_363 = F_131 ( V_361 -> V_364 ) ;
V_3 -> V_300 = F_132 ( V_361 -> V_365 ) ;
V_3 -> V_366 = F_132 ( V_361 -> V_367 ) ;
if ( V_368 < V_362 ) {
V_3 -> V_131 = F_131 ( V_361 -> V_369 ) ;
V_3 -> V_133 = F_131 ( V_361 -> V_370 ) ;
} else {
V_3 -> V_131 = 0 ;
V_3 -> V_133 = 0 ;
}
if ( V_3 -> V_300 & V_371 ) {
V_8 -> V_10 . V_11 . V_189 = V_3 ;
F_135 ( V_8 , V_4 ) ;
}
if ( V_3 -> V_300 & V_372 )
V_8 -> V_10 . V_11 . V_373 = V_3 ;
}
static void F_137 ( struct V_7 * V_8 ,
struct V_2 * V_3 , int V_59 ,
union V_374 * V_375 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_376 * V_377 = & V_4 -> V_244 [ V_59 ] ;
T_1 V_60 ;
V_60 = F_132 ( V_375 -> V_378 . V_379 ) ;
V_60 |= V_375 -> V_378 . V_380 << 16 ;
V_377 -> V_60 = V_60 ;
V_377 -> V_273 = V_375 -> V_378 . V_381 ;
V_4 -> V_246 = V_59 + 1 ;
if ( V_9 -> V_287 ) {
V_377 -> V_275 = 5 ;
V_377 -> V_276 = 5 ;
}
}
static int F_138 ( struct V_7 * V_8 )
{
struct V_333 * V_334 = & V_8 -> V_334 ;
struct V_360 * V_361 ;
union V_382 * V_383 ;
int V_75 , V_384 , V_385 , V_386 , V_387 ;
union V_374 * V_375 ;
struct V_388 * V_389 ;
struct V_390 * V_391 ;
struct V_392 * V_393 ;
union V_394 * V_394 ;
int V_59 = F_129 ( V_335 , V_395 ) ;
T_2 V_340 ;
V_53 V_338 , V_339 ;
V_53 * V_396 ;
struct V_1 * V_4 ;
if ( ! F_130 ( V_334 -> V_341 , V_59 , NULL ,
& V_338 , & V_339 , & V_340 ) )
return - V_18 ;
V_394 = (union V_394 * ) ( V_334 -> V_341 -> V_342 + V_340 ) ;
V_389 = (struct V_388 * )
( V_334 -> V_341 -> V_342 + V_340 +
F_132 ( V_394 -> V_397 . V_398 ) ) ;
V_391 = (struct V_390 * )
( V_334 -> V_341 -> V_342 + V_340 +
F_132 ( V_394 -> V_397 . V_399 ) ) ;
V_393 = (struct V_392 * )
( V_334 -> V_341 -> V_342 + V_340 +
F_132 ( V_394 -> V_397 . V_400 ) ) ;
V_8 -> V_10 . V_11 . V_4 = F_139 ( sizeof( struct V_2 ) *
V_389 -> V_401 , V_402 ) ;
if ( ! V_8 -> V_10 . V_11 . V_4 )
return - V_403 ;
V_396 = ( V_53 * ) V_389 -> V_404 ;
for ( V_75 = 0 ; V_75 < V_389 -> V_401 ; V_75 ++ ) {
V_53 * V_264 ;
V_383 = (union V_382 * ) V_396 ;
V_386 = V_383 -> V_405 . V_406 ;
V_361 = (struct V_360 * )
& V_393 -> V_407 [ V_386 ] ;
if ( ! V_8 -> V_10 . V_383 [ V_75 ] . V_375 )
return - V_18 ;
V_4 = F_139 ( sizeof( struct V_1 ) , V_402 ) ;
if ( V_4 == NULL ) {
F_140 ( V_8 -> V_10 . V_11 . V_4 ) ;
return - V_403 ;
}
V_8 -> V_10 . V_11 . V_4 [ V_75 ] . V_5 = V_4 ;
V_385 = 0 ;
V_264 = ( V_53 * ) & V_383 -> V_405 . V_408 [ 0 ] ;
for ( V_384 = 0 ; V_384 < V_383 -> V_405 . V_409 ; V_384 ++ ) {
V_387 = V_264 [ V_384 ] ;
if ( V_387 >= V_391 -> V_401 )
continue;
if ( V_385 >= V_410 )
break;
V_375 = (union V_374 * )
( ( V_53 * ) & V_391 -> V_411 [ 0 ] +
( V_387 * V_391 -> V_412 ) ) ;
F_137 ( V_8 ,
& V_8 -> V_10 . V_11 . V_4 [ V_75 ] , V_385 ,
V_375 ) ;
V_385 ++ ;
}
F_136 ( V_8 , & V_8 -> V_10 . V_11 . V_4 [ V_75 ] ,
V_361 ,
V_393 -> V_412 ) ;
V_396 += 2 + V_383 -> V_405 . V_409 ;
}
V_8 -> V_10 . V_11 . V_413 = V_389 -> V_401 ;
for ( V_75 = 0 ; V_75 < V_414 ; V_75 ++ ) {
T_1 V_60 ;
V_387 = V_8 -> V_10 . V_11 . V_297 [ V_75 ] . V_415 ;
V_375 = (union V_374 * )
& V_391 -> V_411 [ V_387 * V_391 -> V_412 ] ;
V_60 = F_132 ( V_375 -> V_378 . V_379 ) ;
V_60 |= V_375 -> V_378 . V_380 << 16 ;
V_8 -> V_10 . V_11 . V_297 [ V_75 ] . V_60 = V_60 ;
V_8 -> V_10 . V_11 . V_297 [ V_75 ] . V_266 = 0 ;
}
return 0 ;
}
int F_141 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
int V_36 , V_75 ;
V_9 = F_139 ( sizeof( struct V_6 ) , V_402 ) ;
if ( V_9 == NULL )
return - V_403 ;
V_8 -> V_10 . V_11 . V_12 = V_9 ;
V_36 = F_142 ( V_8 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_143 ( V_8 ) ;
if ( V_36 )
return V_36 ;
for ( V_75 = 0 ; V_75 < V_410 ; V_75 ++ )
V_9 -> V_88 [ V_75 ] = V_416 ;
V_9 -> V_46 = V_417 ;
if ( V_8 -> V_418 -> V_419 == 0x1849 )
V_9 -> V_250 = false ;
else
V_9 -> V_250 = true ;
V_9 -> V_420 = true ;
V_9 -> V_38 = true ;
V_9 -> V_421 = false ;
if ( V_9 -> V_421 ) {
V_9 -> V_27 = true ;
V_9 -> V_30 = true ;
V_9 -> V_32 = true ;
V_9 -> V_34 = true ;
}
V_9 -> V_287 = true ;
V_9 -> V_188 = true ;
V_9 -> V_310 = false ;
if ( V_422 == - 1 ) {
if ( V_8 -> V_101 == V_102 || V_8 -> V_101 == V_103 )
V_9 -> V_183 = true ;
else
V_9 -> V_183 = false ;
} else if ( V_422 == 0 ) {
V_9 -> V_183 = false ;
} else {
V_9 -> V_183 = true ;
}
V_9 -> V_86 = 0 ;
V_9 -> V_106 = false ;
V_9 -> V_195 = false ;
V_9 -> V_230 = true ;
V_9 -> V_214 = true ;
V_9 -> V_234 = false ;
V_9 -> V_237 = false ;
V_9 -> V_240 = false ;
V_9 -> V_215 = false ;
V_36 = F_128 ( V_8 ) ;
if ( V_36 )
return V_36 ;
F_113 ( V_8 ) ;
F_114 ( V_8 ) ;
V_36 = F_138 ( V_8 ) ;
if ( V_36 )
return V_36 ;
V_9 -> V_262 = true ;
return 0 ;
}
void F_144 ( struct V_7 * V_8 ,
struct V_423 * V_424 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_425 =
( F_4 ( V_426 ) & V_427 ) >>
V_428 ;
T_1 V_60 , V_42 ;
T_2 V_265 ;
if ( V_425 >= V_429 ) {
F_145 ( V_424 , L_22 , V_425 ) ;
} else {
V_60 = F_121 ( V_9 -> V_64 [ V_425 ] . V_67 ) ;
V_42 = ( F_4 ( V_430 ) & V_431 ) >>
V_432 ;
V_265 = F_30 ( V_8 , ( T_2 ) V_42 ) ;
F_145 ( V_424 , L_23 , V_9 -> V_200 ? L_24 : L_25 ) ;
F_145 ( V_424 , L_26 , V_9 -> V_201 ? L_24 : L_25 ) ;
F_145 ( V_424 , L_27 ,
V_425 , V_60 , V_265 ) ;
}
}
T_1 F_146 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
T_1 V_425 =
( F_4 ( V_426 ) & V_427 ) >>
V_428 ;
T_1 V_60 ;
if ( V_425 >= V_429 ) {
return 0 ;
} else {
V_60 = F_121 ( V_9 -> V_64 [ V_425 ] . V_67 ) ;
return V_60 ;
}
}
T_1 F_147 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
return V_9 -> V_83 . V_345 ;
}
void F_148 ( struct V_7 * V_8 ,
struct V_2 * V_3 )
{
int V_75 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_149 ( V_3 -> V_300 , V_3 -> V_366 ) ;
F_150 ( V_3 -> V_363 ) ;
F_151 ( L_28 , V_3 -> V_131 , V_3 -> V_133 ) ;
for ( V_75 = 0 ; V_75 < V_4 -> V_246 ; V_75 ++ ) {
struct V_376 * V_377 = & V_4 -> V_244 [ V_75 ] ;
F_151 ( L_29 ,
V_75 , V_377 -> V_60 ,
F_30 ( V_8 , V_377 -> V_273 ) ) ;
}
F_152 ( V_8 , V_3 ) ;
}
void F_153 ( struct V_7 * V_8 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_8 -> V_10 . V_11 . V_413 ; V_75 ++ ) {
F_140 ( V_8 -> V_10 . V_11 . V_4 [ V_75 ] . V_5 ) ;
}
F_140 ( V_8 -> V_10 . V_11 . V_4 ) ;
F_140 ( V_8 -> V_10 . V_11 . V_12 ) ;
F_154 ( V_8 ) ;
}
void F_155 ( struct V_7 * V_8 )
{
}
T_1 F_156 ( struct V_7 * V_8 , bool V_433 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
struct V_1 * V_434 = F_1 ( & V_9 -> V_181 ) ;
if ( V_433 )
return V_434 -> V_244 [ 0 ] . V_60 ;
else
return V_434 -> V_244 [ V_434 -> V_246 - 1 ] . V_60 ;
}
T_1 F_157 ( struct V_7 * V_8 , bool V_433 )
{
struct V_6 * V_9 = F_2 ( V_8 ) ;
return V_9 -> V_83 . V_345 ;
}
