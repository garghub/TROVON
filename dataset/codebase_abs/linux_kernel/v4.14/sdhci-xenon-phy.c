static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 ;
V_8 = F_4 ( F_5 ( V_2 -> V_9 ) , sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 )
return - V_11 ;
V_6 -> V_12 = V_8 ;
if ( V_6 -> V_13 == V_14 )
V_6 -> V_15 = & V_16 ;
else
V_6 -> V_15 = & V_17 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_18 ;
T_1 V_19 , clock ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_20 * V_21 = V_6 -> V_15 ;
V_18 = F_7 ( V_2 , V_21 -> V_22 ) ;
V_18 |= V_23 ;
F_8 ( V_2 , V_18 , V_21 -> V_22 ) ;
V_19 = ( ( V_18 >> V_24 ) &
V_25 ) ;
V_19 += ( ( V_18 >> V_26 ) &
V_27 ) ;
V_19 += ( ( V_18 >> V_28 ) &
V_29 ) ;
V_19 += ( ( V_18 >> V_30 ) &
V_31 ) ;
V_19 += 8 ;
V_19 <<= 20 ;
clock = V_2 -> clock ;
if ( ! clock )
clock = V_32 ;
V_19 /= clock ;
V_19 ++ ;
F_9 ( V_19 ) ;
V_18 = F_7 ( V_2 , V_21 -> V_22 ) ;
V_18 &= V_23 ;
if ( V_18 ) {
F_10 ( F_5 ( V_2 -> V_9 ) , L_1 ,
V_19 ) ;
return - V_33 ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned char V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_12 ;
if ( V_8 -> V_35 . V_36 == V_37 ) {
F_12 ( V_38 , V_8 -> V_35 . V_18 ) ;
} else if ( V_8 -> V_35 . V_36 == V_39 ) {
if ( V_34 == V_40 )
F_12 ( V_38 , V_8 -> V_35 . V_18 ) ;
else if ( V_34 == V_41 )
F_12 ( V_42 , V_8 -> V_35 . V_18 ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
unsigned char V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_12 ;
if ( ! V_8 -> V_35 . V_18 )
return;
if ( V_8 -> V_35 . V_43 )
V_8 -> V_35 . V_43 ( V_2 , V_34 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_20 * V_21 = V_6 -> V_15 ;
T_2 V_44 ;
if ( F_15 ( V_2 -> clock <= V_45 ) )
return - V_46 ;
V_18 = F_7 ( V_2 , V_21 -> V_47 ) ;
if ( V_18 & V_48 )
return 0 ;
V_18 = F_7 ( V_2 , V_21 -> V_47 ) ;
V_18 |= ( V_48 | V_49 ) ;
V_18 &= ~ ( ( V_50 << V_51 ) |
( V_50 << V_52 ) ) ;
V_18 |= ( ( V_53 << V_51 ) |
( V_53 << V_52 ) ) ;
V_18 &= ~ V_54 ;
V_18 |= V_21 -> V_55 ;
if ( V_6 -> V_13 == V_56 )
V_18 &= ~ V_57 ;
F_8 ( V_2 , V_18 , V_21 -> V_47 ) ;
V_44 = F_16 ( F_17 () , 32 ) ;
while ( ! ( F_18 ( V_2 , V_58 ) &
V_59 ) ) {
if ( F_19 ( F_17 () , V_44 ) ) {
F_10 ( F_5 ( V_2 -> V_9 ) , L_2 ) ;
return - V_33 ;
}
F_9 ( 100 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_12 ;
T_1 V_18 , V_60 ;
int V_61 ;
if ( V_2 -> clock <= V_45 )
return - V_46 ;
V_61 = F_14 ( V_2 ) ;
if ( V_61 )
return V_61 ;
V_18 = F_7 ( V_2 , V_62 ) ;
V_60 = V_18 / V_8 -> V_63 ;
if ( F_21 ( V_60 > V_64 ) ) {
F_22 ( F_5 ( V_2 -> V_9 ) ,
L_3 ,
V_60 ) ;
V_60 = V_64 ;
}
V_18 = F_7 ( V_2 , V_65 ) ;
V_18 &= ~ ( V_66 <<
V_67 ) ;
V_18 |= ( V_8 -> V_68 << V_67 ) ;
V_18 &= ~ ( V_64 << V_69 ) ;
V_18 |= ( V_60 << V_69 ) ;
F_8 ( V_2 , V_18 , V_65 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_18 ;
V_18 = F_7 ( V_2 , V_70 ) ;
V_18 &= ~ ( V_71 | V_72 ) ;
F_8 ( V_2 , V_18 , V_70 ) ;
if ( V_6 -> V_13 == V_14 ) {
V_18 = F_7 ( V_2 , V_73 ) ;
V_18 &= ~ ( V_74 | V_75 ) ;
F_8 ( V_2 , V_18 , V_73 ) ;
} else {
V_18 = F_7 ( V_2 , V_76 ) ;
V_18 &= ~ ( V_77 | V_78 ) ;
F_8 ( V_2 , V_18 , V_76 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_18 ;
if ( F_15 ( V_2 -> V_79 != V_80 ) )
return;
if ( V_2 -> clock <= V_45 )
return;
F_25 ( F_5 ( V_2 -> V_9 ) , L_4 ) ;
F_14 ( V_2 ) ;
V_18 = F_7 ( V_2 , V_70 ) ;
V_18 |= V_71 ;
if ( V_2 -> V_9 -> V_81 . V_82 )
V_18 |= V_72 ;
F_8 ( V_2 , V_18 , V_70 ) ;
if ( V_6 -> V_13 == V_14 ) {
V_18 = F_7 ( V_2 , V_73 ) ;
V_18 |= V_74 ;
V_18 &= ~ V_75 ;
F_8 ( V_2 , V_18 , V_73 ) ;
} else {
V_18 = F_7 ( V_2 , V_76 ) ;
V_18 |= V_77 ;
V_18 &= ~ V_78 ;
F_8 ( V_2 , V_18 , V_76 ) ;
}
}
static bool F_26 ( struct V_1 * V_2 ,
unsigned char V_79 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_12 ;
struct V_20 * V_21 = V_6 -> V_15 ;
T_1 V_18 ;
int V_61 ;
if ( V_2 -> clock > V_45 )
return false ;
V_18 = F_7 ( V_2 , V_21 -> V_22 ) ;
switch ( V_79 ) {
case V_83 :
if ( V_8 -> V_84 ) {
V_18 |= V_85 ;
V_61 = true ;
} else {
V_18 &= ~ V_85 ;
V_61 = false ;
}
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
if ( ( V_6 -> V_90 == V_91 ) ||
V_8 -> V_84 ) {
V_18 |= V_85 ;
V_61 = true ;
break;
}
default:
V_18 &= ~ V_85 ;
V_61 = false ;
}
F_8 ( V_2 , V_18 , V_21 -> V_22 ) ;
return V_61 ;
}
static void F_27 ( struct V_1 * V_2 ,
unsigned char V_79 )
{
T_1 V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_12 ;
struct V_20 * V_21 = V_6 -> V_15 ;
F_25 ( F_5 ( V_2 -> V_9 ) , L_5 ) ;
V_18 = F_7 ( V_2 , V_21 -> V_35 ) ;
V_18 |= ( V_92 | V_93 |
V_94 | V_95 ) ;
V_18 |= V_96 ;
F_8 ( V_2 , V_18 , V_21 -> V_35 ) ;
if ( V_6 -> V_13 == V_14 ) {
V_18 = F_7 ( V_2 , V_73 ) ;
V_18 |= ( V_97 | V_98 ) ;
V_18 &= ~ ( V_99 | V_100 ) ;
F_8 ( V_2 , V_18 , V_73 ) ;
} else {
V_18 = F_7 ( V_2 , V_76 ) ;
V_18 |= ( V_101 | V_102 ) ;
V_18 &= ~ ( V_103 | V_104 ) ;
F_8 ( V_2 , V_18 , V_76 ) ;
}
if ( V_79 == V_83 ) {
F_26 ( V_2 , V_79 ) ;
goto V_105;
}
V_18 = F_7 ( V_2 , V_21 -> V_22 ) ;
if ( V_6 -> V_90 == V_91 )
V_18 |= V_106 ;
else
V_18 &= ~ V_106 ;
F_8 ( V_2 , V_18 , V_21 -> V_22 ) ;
if ( F_26 ( V_2 , V_79 ) )
goto V_105;
V_18 = F_7 ( V_2 , V_21 -> V_107 ) ;
V_18 &= ~ ( ( V_108 << V_109 ) | V_110 ) ;
V_18 |= ( ( V_8 -> V_111 << V_109 ) | V_8 -> V_112 ) ;
F_8 ( V_2 , V_18 , V_21 -> V_107 ) ;
V_18 = F_7 ( V_2 , V_113 ) ;
V_18 &= ~ V_114 ;
F_28 ( V_2 , V_18 , V_113 ) ;
V_18 = F_7 ( V_2 , V_21 -> V_115 ) ;
switch ( V_79 ) {
case V_80 :
V_18 |= ( V_116 << V_117 ) |
V_118 ;
V_18 &= ~ V_119 ;
break;
case V_120 :
case V_121 :
V_18 |= ( V_116 << V_117 ) |
V_118 | V_119 ;
break;
default:
V_18 &= ~ ( ( V_116 << V_117 ) |
V_118 ) ;
V_18 |= V_119 ;
}
F_8 ( V_2 , V_18 , V_21 -> V_115 ) ;
V_18 = F_7 ( V_2 , V_113 ) ;
V_18 |= V_114 ;
F_28 ( V_2 , V_18 , V_113 ) ;
if ( V_79 == V_80 )
F_8 ( V_2 , V_21 -> V_122 ,
V_21 -> V_123 ) ;
else
F_23 ( V_2 ) ;
V_105:
F_6 ( V_2 ) ;
F_25 ( F_5 ( V_2 -> V_9 ) , L_6 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
struct V_7 * V_8 )
{
int V_61 = 0 ;
const char * V_126 ;
struct V_127 V_128 ;
if ( F_30 ( V_125 , L_7 ) )
V_8 -> V_35 . V_43 = F_11 ;
else
return 0 ;
if ( F_31 ( V_125 , 1 , & V_128 ) ) {
F_10 ( F_5 ( V_2 -> V_9 ) , L_8 ,
V_125 -> V_126 ) ;
return - V_46 ;
}
V_8 -> V_35 . V_18 = F_32 ( F_5 ( V_2 -> V_9 ) ,
& V_128 ) ;
if ( F_33 ( V_8 -> V_35 . V_18 ) )
return F_34 ( V_8 -> V_35 . V_18 ) ;
V_61 = F_35 ( V_125 , L_9 , & V_126 ) ;
if ( V_61 ) {
F_10 ( F_5 ( V_2 -> V_9 ) , L_10 ) ;
return V_61 ;
}
if ( ! strcmp ( V_126 , L_11 ) ) {
V_8 -> V_35 . V_36 = V_39 ;
} else if ( ! strcmp ( V_126 , L_12 ) ) {
V_8 -> V_35 . V_36 = V_37 ;
} else {
F_10 ( F_5 ( V_2 -> V_9 ) , L_13 ,
V_126 ) ;
return - V_46 ;
}
return V_61 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
struct V_7 * V_8 )
{
T_1 V_129 ;
V_8 -> V_84 = false ;
if ( F_37 ( V_125 , L_14 ) )
V_8 -> V_84 = true ;
V_8 -> V_111 = V_130 ;
if ( ! F_38 ( V_125 , L_15 , & V_129 ) )
V_8 -> V_111 = V_129 & V_108 ;
V_8 -> V_112 = V_131 ;
if ( ! F_38 ( V_125 , L_16 , & V_129 ) )
V_8 -> V_112 = V_129 & V_110 ;
V_8 -> V_68 = V_132 ;
if ( ! F_38 ( V_125 , L_17 ,
& V_129 ) )
V_8 -> V_68 = V_129 & V_66 ;
V_8 -> V_63 = V_133 ;
if ( ! F_38 ( V_125 , L_18 ,
& V_129 ) )
V_8 -> V_63 = V_129 & 0xFF ;
return F_29 ( V_2 , V_125 , V_8 ) ;
}
void F_39 ( struct V_1 * V_2 ,
unsigned char V_34 )
{
F_13 ( V_2 , V_34 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_61 = 0 ;
if ( F_15 ( V_2 -> clock <= V_134 ) )
return - V_46 ;
switch ( V_2 -> V_79 ) {
case V_80 :
F_24 ( V_2 ) ;
return 0 ;
case V_135 :
case V_136 :
return F_20 ( V_2 ) ;
case V_121 :
case V_120 :
F_41 ( F_5 ( V_2 -> V_9 ) , L_19 ) ;
return 0 ;
}
return V_61 ;
}
int F_42 ( struct V_1 * V_2 , struct V_137 * V_81 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_61 = 0 ;
if ( ! V_2 -> clock ) {
V_6 -> clock = 0 ;
return 0 ;
}
if ( ( V_2 -> clock == V_6 -> clock ) &&
( V_81 -> V_138 == V_6 -> V_138 ) &&
( V_81 -> V_79 == V_6 -> V_79 ) )
return 0 ;
F_27 ( V_2 , V_81 -> V_79 ) ;
V_6 -> V_138 = V_81 -> V_138 ;
V_6 -> V_79 = V_81 -> V_79 ;
V_6 -> clock = V_2 -> clock ;
if ( V_81 -> V_79 == V_83 )
return 0 ;
if ( V_2 -> clock > V_134 )
V_61 = F_40 ( V_2 ) ;
return V_61 ;
}
static int F_43 ( struct V_124 * V_125 , struct V_1 * V_2 ,
const char * V_139 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_140 , V_61 ;
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ ) {
if ( ! strcmp ( V_139 , V_142 [ V_140 ] ) ) {
V_6 -> V_13 = V_140 ;
break;
}
}
if ( V_140 == V_141 ) {
F_10 ( F_5 ( V_2 -> V_9 ) ,
L_20 ,
V_139 ) ;
V_6 -> V_13 = V_56 ;
}
V_61 = F_1 ( V_2 ) ;
if ( V_61 )
return V_61 ;
return F_36 ( V_2 , V_125 , V_6 -> V_12 ) ;
}
int F_44 ( struct V_124 * V_125 , struct V_1 * V_2 )
{
const char * V_13 = NULL ;
if ( ! F_35 ( V_125 , L_21 , & V_13 ) )
return F_43 ( V_125 , V_2 , V_13 ) ;
return F_43 ( V_125 , V_2 , L_22 ) ;
}
