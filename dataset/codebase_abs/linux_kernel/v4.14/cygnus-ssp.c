static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return & V_5 -> V_6 [ V_3 -> V_7 ] ;
}
static int F_3 ( struct V_1 * V_8 )
{
T_1 V_9 , V_10 ;
int V_11 = 0 ;
switch ( V_8 -> V_12 ) {
case V_13 :
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_16 ) ;
V_9 &= ~ V_17 ;
F_5 ( V_8 -> V_18 ,
V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_19 ) ;
V_9 |= V_8 -> V_18 << V_20 ;
V_9 |= V_8 -> V_18 ;
V_9 |= V_21 << V_22 ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_16 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_9 &= ~ F_6 ( V_24 ) ;
V_9 |= F_6 ( V_25 ) ;
V_9 |= F_6 ( V_26 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_27 +
V_8 -> V_15 . V_28 ) ;
V_9 &= ~ V_29 ;
V_9 |= V_8 -> V_18 << V_30 ;
F_5 ( V_9 , V_8 -> V_5 -> V_27 +
V_8 -> V_15 . V_28 ) ;
V_10 = V_31 + V_8 -> V_18 ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_32 ) ;
V_9 |= F_6 ( V_33 ) ;
V_9 &= ~ F_6 ( V_34 ) ;
V_9 |= ( V_10 << V_35 ) ;
V_9 |= F_6 ( V_36 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_32 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_37 ) ;
V_9 &= ~ F_6 ( ( V_8 -> V_18 * 4 ) + V_38 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_37 ) ;
break;
case V_39 :
F_5 ( V_8 -> V_18 , V_8 -> V_5 -> V_14 + V_40 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_41 ) ;
V_9 |= F_6 ( V_42 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_41 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_43 ) ;
V_9 &= ~ V_44 ;
V_9 |= V_8 -> V_18 ;
V_9 |= F_6 ( V_45 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_43 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_9 &= ~ F_6 ( V_24 ) ;
V_9 |= F_6 ( V_25 ) ;
V_9 |= F_6 ( V_26 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_37 ) ;
V_9 &= ~ F_6 ( V_46 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_37 ) ;
break;
default:
F_7 ( V_8 -> V_5 -> V_47 , L_1 ) ;
V_11 = - V_48 ;
}
return V_11 ;
}
static void F_8 ( struct V_1 * V_8 )
{
T_1 V_9 ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_32 ) ;
V_9 |= F_6 ( V_49 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_32 ) ;
F_5 ( 0x1 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_50 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
V_9 |= F_6 ( V_52 ) ;
V_9 |= F_6 ( V_53 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_27 + V_8 -> V_15 . V_28 ) ;
V_9 |= F_6 ( V_54 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_27 + V_8 -> V_15 . V_28 ) ;
V_8 -> V_55 |= V_56 ;
}
static void F_9 ( struct V_1 * V_8 )
{
T_1 V_9 ;
V_9 = F_4 ( V_8 -> V_5 -> V_27 + V_8 -> V_15 . V_28 ) ;
V_9 &= ~ F_6 ( V_54 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_27 + V_8 -> V_15 . V_28 ) ;
V_8 -> V_55 &= ~ V_56 ;
if ( ! V_8 -> V_55 ) {
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
V_9 &= ~ F_6 ( V_52 ) ;
V_9 &= ~ F_6 ( V_53 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
}
F_5 ( 0x0 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_50 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_32 ) ;
V_9 &= ~ F_6 ( V_49 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_32 ) ;
}
static int F_10 ( struct V_1 * V_8 )
{
T_1 V_9 ;
int V_11 = 0 ;
switch ( V_8 -> V_12 ) {
case V_13 :
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_16 ) ;
V_9 |= F_6 ( V_57 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_16 ) ;
F_5 ( 1 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_58 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
V_9 |= F_6 ( V_52 ) ;
V_9 |= F_6 ( V_53 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_9 |= F_6 ( V_59 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_8 -> V_55 |= V_60 ;
break;
case V_39 :
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_61 ) ;
V_9 |= 0x3 ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_61 ) ;
F_5 ( 1 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_58 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_9 |= F_6 ( V_59 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
break;
default:
F_7 ( V_8 -> V_5 -> V_47 ,
L_2 , V_8 -> V_18 ) ;
V_11 = - V_48 ;
}
return V_11 ;
}
static int F_11 ( struct V_1 * V_8 )
{
T_1 V_9 ;
int V_11 = 0 ;
switch ( V_8 -> V_12 ) {
case V_13 :
V_8 -> V_55 &= ~ V_60 ;
if ( ! V_8 -> V_55 ) {
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
V_9 &= ~ F_6 ( V_52 ) ;
V_9 &= ~ F_6 ( V_53 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
}
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_62 ) ;
V_9 |= F_6 ( V_8 -> V_18 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_62 ) ;
F_5 ( 0 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_58 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_9 &= ~ F_6 ( V_59 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_62 ) ;
V_9 &= ~ F_6 ( V_8 -> V_18 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_62 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_16 ) ;
V_9 &= ~ F_6 ( V_57 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_16 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_27 + V_63 ) ;
V_9 |= F_6 ( V_8 -> V_18 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_27 + V_63 ) ;
V_9 &= ~ F_6 ( V_8 -> V_18 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_27 + V_63 ) ;
break;
case V_39 :
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_61 ) ;
V_9 &= ~ 0x3 ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_61 ) ;
F_5 ( 0 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_58 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_9 &= ~ F_6 ( V_59 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
break;
default:
F_7 ( V_8 -> V_5 -> V_47 ,
L_2 , V_8 -> V_18 ) ;
V_11 = - V_48 ;
}
return V_11 ;
}
static int F_12 ( struct V_4 * V_5 , T_1 V_64 ,
struct V_1 * V_8 )
{
int V_65 = 0 , error ;
bool V_66 = false ;
const struct V_67 * V_68 ;
struct V_69 * V_70 ;
for ( V_65 = 0 ; V_65 < F_13 ( V_71 ) ; V_65 ++ ) {
V_68 = & V_71 [ V_65 ] ;
if ( V_68 -> V_64 == V_64 ) {
V_66 = true ;
break;
}
}
if ( ! V_66 ) {
F_7 ( V_5 -> V_47 ,
L_3 , V_72 , V_64 ) ;
return - V_48 ;
}
V_70 = V_5 -> V_73 [ V_68 -> V_74 ] ;
if ( ( V_8 -> V_75 . V_76 ) && ( ! V_8 -> V_75 . V_77 ) ) {
error = F_14 ( V_70 ) ;
if ( error ) {
F_7 ( V_5 -> V_47 , L_4 ,
V_72 , error ) ;
return error ;
}
V_8 -> V_75 . V_77 = true ;
}
if ( ( V_8 -> V_75 . V_78 ) && ( ! V_8 -> V_75 . V_79 ) ) {
error = F_14 ( V_70 ) ;
if ( error ) {
F_7 ( V_5 -> V_47 , L_4 ,
V_72 , error ) ;
return error ;
}
V_8 -> V_75 . V_79 = true ;
}
error = F_15 ( V_70 , V_64 ) ;
if ( error ) {
F_7 ( V_5 -> V_47 , L_5 ,
V_72 , error ) ;
return error ;
}
return V_68 -> V_74 ;
}
static int F_16 ( struct V_1 * V_8 )
{
T_1 V_9 ;
T_1 V_80 = 0xf ;
T_1 V_81 ;
T_1 V_82 ;
unsigned int V_83 ;
unsigned int V_84 ;
V_83 = V_8 -> V_85 * V_8 -> V_86 ;
if ( ( V_8 -> V_64 % V_83 ) != 0 )
return - V_48 ;
V_84 = V_8 -> V_64 / V_83 ;
switch ( V_84 ) {
case 2 :
case 4 :
case 6 :
case 8 :
case 10 :
case 12 :
case 14 :
V_82 = V_84 / 2 ;
break;
default:
F_7 ( V_8 -> V_5 -> V_47 ,
L_6 ) ;
F_7 ( V_8 -> V_5 -> V_47 , L_7 ,
V_8 -> V_86 , V_8 -> V_85 , V_8 -> V_64 ) ;
return - V_48 ;
}
switch ( V_8 -> V_12 ) {
case V_13 :
V_81 = V_8 -> V_85 ;
if ( V_81 == 512 )
V_81 = 0 ;
V_81 /= 32 ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
V_9 &= ~ ( V_80 << V_87 ) ;
V_9 |= V_81 << V_87 ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
F_17 ( V_8 -> V_5 -> V_47 ,
L_8 , V_9 ) ;
break;
case V_39 :
break;
default:
F_7 ( V_8 -> V_5 -> V_47 , L_9 ) ;
return - V_48 ;
}
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_88 ) ;
V_9 &= ~ ( 0xf << V_89 ) ;
V_9 |= ( V_82 << V_89 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_88 ) ;
F_17 ( V_8 -> V_5 -> V_47 , L_10 , V_9 ) ;
F_17 ( V_8 -> V_5 -> V_47 , L_11 ,
V_8 -> V_85 , V_8 -> V_64 , V_8 -> V_86 ) ;
return 0 ;
}
static int F_18 ( struct V_90 * V_91 ,
struct V_92 * V_93 ,
struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_94 , V_95 ;
T_1 V_9 ;
T_1 V_80 = 0x1f ;
int V_96 = 0 ;
F_17 ( V_8 -> V_5 -> V_47 , L_12 , V_72 , V_8 -> V_18 ) ;
F_17 ( V_8 -> V_5 -> V_47 , L_13 ,
F_19 ( V_93 ) ) ;
F_17 ( V_8 -> V_5 -> V_47 , L_14 , F_20 ( V_93 ) ) ;
F_17 ( V_8 -> V_5 -> V_47 , L_15 , F_21 ( V_93 ) ) ;
V_94 = F_20 ( V_93 ) ;
switch ( V_8 -> V_97 ) {
case V_98 :
if ( ( V_94 == 192000 ) && ( F_19 ( V_93 ) > 4 ) ) {
F_7 ( V_8 -> V_5 -> V_47 , L_16 ,
F_19 ( V_93 ) , V_94 ) ;
return - V_48 ;
}
break;
case V_99 :
V_8 -> V_85 = 64 ;
break;
default:
F_7 ( V_8 -> V_5 -> V_47 ,
L_17 , V_72 ) ;
return - V_48 ;
}
if ( V_91 -> V_100 == V_101 ) {
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_9 &= ~ F_6 ( V_102 ) ;
if ( F_19 ( V_93 ) == 1 )
V_9 |= F_6 ( V_103 ) ;
else
V_9 &= ~ F_6 ( V_103 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
switch ( F_21 ( V_93 ) ) {
case V_104 :
if ( V_8 -> V_12 == V_39 ) {
F_7 ( V_8 -> V_5 -> V_47 ,
L_18 ) ;
return - V_48 ;
}
V_95 = 8 ;
break;
case V_105 :
V_95 = 16 ;
break;
case V_106 :
V_95 = 0 ;
break;
default:
return - V_48 ;
}
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
V_9 &= ~ ( V_80 << V_107 ) ;
V_9 |= ( V_95 << V_107 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_23 ) ;
} else {
switch ( F_21 ( V_93 ) ) {
case V_105 :
V_9 = F_4 ( V_8 -> V_5 -> V_14 +
V_8 -> V_15 . V_32 ) ;
V_9 |= F_6 ( V_108 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 +
V_8 -> V_15 . V_32 ) ;
break;
case V_106 :
V_9 = F_4 ( V_8 -> V_5 -> V_14 +
V_8 -> V_15 . V_32 ) ;
V_9 &= ~ F_6 ( V_108 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 +
V_8 -> V_15 . V_32 ) ;
break;
default:
return - V_48 ;
}
}
V_8 -> V_86 = V_94 ;
if ( ! V_8 -> V_109 )
V_96 = F_16 ( V_8 ) ;
return V_96 ;
}
static int F_22 ( struct V_2 * V_3 ,
int V_110 , unsigned int V_111 , int V_112 )
{
int V_113 ;
T_1 V_9 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_17 ( V_8 -> V_5 -> V_47 ,
L_19 , V_72 , V_8 -> V_18 ) ;
V_113 = F_12 ( V_5 , V_111 , V_8 ) ;
if ( V_113 < 0 ) {
F_7 ( V_8 -> V_5 -> V_47 ,
L_20 , V_72 ) ;
return - V_48 ;
}
V_8 -> V_64 = V_111 ;
F_17 ( V_8 -> V_5 -> V_47 , L_21 , V_72 , V_113 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_88 ) ;
V_9 &= ~ ( 0xf << V_114 ) ;
V_9 |= ( V_113 << V_114 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_88 ) ;
return 0 ;
}
static int F_23 ( struct V_90 * V_91 ,
struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_24 ( V_3 , V_91 , V_8 ) ;
if ( V_91 -> V_100 == V_101 )
V_8 -> V_75 . V_78 = true ;
else
V_8 -> V_75 . V_76 = true ;
V_91 -> V_115 -> V_116 . V_117 = V_118 ;
V_91 -> V_115 -> V_116 . V_119 = V_120 ;
F_25 ( V_91 -> V_115 , 0 ,
V_121 , & V_122 ) ;
return 0 ;
}
static void F_26 ( struct V_90 * V_91 ,
struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_91 -> V_100 == V_101 )
V_8 -> V_75 . V_78 = false ;
else
V_8 -> V_75 . V_76 = false ;
if ( ! V_8 -> V_109 ) {
T_1 V_123 ;
V_123 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_88 ) ;
V_123 &= V_124 ;
if ( V_123 >= F_13 ( V_8 -> V_5 -> V_73 ) ) {
F_7 ( V_8 -> V_5 -> V_47 , L_22 ,
V_123 ) ;
return;
}
if ( V_91 -> V_100 == V_101 ) {
if ( V_8 -> V_75 . V_79 ) {
F_27 ( V_8 -> V_5 ->
V_73 [ V_123 ] ) ;
V_8 -> V_75 . V_79 = false ;
}
} else {
if ( V_8 -> V_75 . V_77 ) {
F_27 ( V_8 -> V_5 ->
V_73 [ V_123 ] ) ;
V_8 -> V_75 . V_77 = false ;
}
}
}
}
int F_28 ( struct V_2 * V_125 , int V_126 )
{
struct V_1 * V_8 = F_1 ( V_125 ) ;
if ( ( V_126 > 0 ) && ( V_126 < 256 ) ) {
V_8 -> V_127 = V_126 ;
return 0 ;
} else {
return - V_48 ;
}
}
static int F_29 ( struct V_2 * V_125 , unsigned int V_128 )
{
struct V_1 * V_8 = F_1 ( V_125 ) ;
T_1 V_129 ;
T_1 V_130 ;
T_1 V_131 ;
T_1 V_132 ;
T_1 V_123 ;
T_1 V_80 ;
F_17 ( V_8 -> V_5 -> V_47 , L_23 , V_72 , V_128 ) ;
if ( V_8 -> V_12 == V_39 )
return - V_48 ;
V_130 = 0 ;
switch ( V_128 & V_133 ) {
case V_134 :
V_130 |= F_6 ( V_135 ) ;
V_8 -> V_109 = 1 ;
break;
case V_136 :
V_130 &= ~ F_6 ( V_135 ) ;
V_8 -> V_109 = 0 ;
break;
default:
return - V_48 ;
}
switch ( V_128 & V_137 ) {
case V_138 :
V_130 |= F_6 ( V_139 ) ;
V_130 |= F_6 ( V_140 ) ;
V_8 -> V_97 = V_99 ;
break;
case V_141 :
case V_142 :
V_130 |= F_6 ( V_143 ) ;
if ( ( V_128 & V_137 ) == V_141 )
V_130 |= F_6 ( V_139 ) ;
if ( ( V_8 -> V_127 > 0 ) && ( V_8 -> V_127 < 256 ) )
V_130 |=
( V_8 -> V_127 << V_140 ) ;
else
V_130 |= F_6 ( V_140 ) ;
V_8 -> V_97 = V_98 ;
break;
default:
return - V_48 ;
}
V_129 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
V_131 = ( V_129 & V_144 ) | V_130 ;
F_5 ( V_131 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
V_129 = F_4 ( V_8 -> V_5 -> V_27 + V_8 -> V_15 . V_145 ) ;
V_132 = ( V_129 & V_146 ) | V_130 ;
F_5 ( V_132 , V_8 -> V_5 -> V_27 + V_8 -> V_15 . V_145 ) ;
V_123 = F_4 ( V_8 -> V_5 -> V_14 + V_37 ) ;
V_80 = F_6 ( V_147 )
| F_6 ( V_148 )
| F_6 ( V_149 ) ;
V_80 = V_80 << ( V_8 -> V_18 * 4 ) ;
if ( V_8 -> V_109 )
V_123 |= V_80 ;
else
V_123 &= ~ V_80 ;
F_17 ( V_8 -> V_5 -> V_47 , L_24 , V_72 , V_123 ) ;
F_5 ( V_123 , V_8 -> V_5 -> V_14 + V_37 ) ;
return 0 ;
}
static int F_30 ( struct V_90 * V_91 , int V_150 ,
struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_17 ( V_8 -> V_5 -> V_47 ,
L_25 , V_72 , V_150 , V_8 -> V_18 ) ;
switch ( V_150 ) {
case V_151 :
case V_152 :
case V_153 :
if ( V_91 -> V_100 == V_101 )
F_10 ( V_8 ) ;
else
F_8 ( V_8 ) ;
V_5 -> V_154 ++ ;
break;
case V_155 :
case V_156 :
case V_157 :
if ( V_91 -> V_100 == V_101 )
F_11 ( V_8 ) ;
else
F_9 ( V_8 ) ;
V_5 -> V_154 -- ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static int F_31 ( struct V_2 * V_125 ,
unsigned int V_158 , unsigned int V_159 , int V_160 , int V_161 )
{
struct V_1 * V_8 = F_1 ( V_125 ) ;
T_1 V_9 ;
int V_162 = 0 ;
int V_163 ;
unsigned int V_164 ;
bool V_66 = false ;
int V_65 ;
if ( V_158 != V_159 ) {
F_7 ( V_8 -> V_5 -> V_47 ,
L_26 , V_72 ) ;
return - V_48 ;
}
V_164 = F_32 ( V_158 ) ;
if ( ( V_164 < 0 ) || ( V_164 > 16 ) )
return - V_48 ;
if ( V_164 % 2 )
return - V_48 ;
if ( V_164 == 16 )
V_164 = 0 ;
switch ( V_161 ) {
case 16 :
V_162 = 1 ;
break;
case 32 :
V_162 = 0 ;
break;
default:
V_162 = 0 ;
F_33 ( V_8 -> V_5 -> V_47 ,
L_27 , V_72 ) ;
}
V_163 = V_160 * V_161 ;
for ( V_65 = 0 ; V_65 < F_13 ( V_165 ) ; V_65 ++ ) {
if ( V_165 [ V_65 ] == V_163 ) {
V_66 = true ;
break;
}
}
if ( ! V_66 ) {
F_7 ( V_8 -> V_5 -> V_47 ,
L_28 ,
V_72 , V_163 ) ;
return - V_48 ;
}
V_8 -> V_85 = V_163 ;
F_17 ( V_8 -> V_5 -> V_47 , L_29 ,
V_72 , V_164 , V_163 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_27 + V_8 -> V_15 . V_145 ) ;
V_9 &= ~ ( 0xf << V_166 ) ;
V_9 |= ( V_164 << V_166 ) ;
V_9 &= ~ F_6 ( V_167 ) ;
V_9 |= ( V_162 << V_167 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_27 + V_8 -> V_15 . V_145 ) ;
V_9 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
V_9 &= ~ ( 0xf << V_166 ) ;
V_9 |= ( V_164 << V_166 ) ;
V_9 &= ~ F_6 ( V_167 ) ;
V_9 |= ( V_162 << V_167 ) ;
F_5 ( V_9 , V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_51 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_125 )
{
struct V_1 * V_8 = F_1 ( V_125 ) ;
if ( ! V_8 -> V_109 ) {
T_1 V_123 ;
V_123 = F_4 ( V_8 -> V_5 -> V_14 + V_8 -> V_15 . V_88 ) ;
V_123 &= V_124 ;
if ( V_123 >= F_13 ( V_8 -> V_5 -> V_73 ) ) {
F_7 ( V_8 -> V_5 -> V_47 , L_22 ,
V_123 ) ;
return - V_48 ;
}
if ( V_8 -> V_75 . V_77 )
F_27 ( V_8 -> V_5 -> V_73 [ V_123 ] ) ;
if ( V_8 -> V_75 . V_79 )
F_27 ( V_8 -> V_5 -> V_73 [ V_123 ] ) ;
V_8 -> V_168 = V_123 ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_125 )
{
struct V_1 * V_8 = F_1 ( V_125 ) ;
int error ;
if ( ! V_8 -> V_109 ) {
if ( V_8 -> V_75 . V_77 ) {
error = F_14 ( V_8 -> V_5 ->
V_73 [ V_8 -> V_168 ] ) ;
if ( error ) {
F_7 ( V_8 -> V_5 -> V_47 , L_30 ,
V_72 ) ;
return - V_48 ;
}
}
if ( V_8 -> V_75 . V_79 ) {
error = F_14 ( V_8 -> V_5 ->
V_73 [ V_8 -> V_168 ] ) ;
if ( error ) {
if ( V_8 -> V_75 . V_77 )
F_27 ( V_8 -> V_5 ->
V_73 [ V_8 -> V_168 ] ) ;
F_7 ( V_8 -> V_5 -> V_47 , L_30 ,
V_72 ) ;
return - V_48 ;
}
}
}
return 0 ;
}
static int F_36 ( struct V_169 * V_170 ,
struct V_171 * V_172 ,
struct V_4 * V_5 ,
struct V_173 * V_174 )
{
struct V_1 * V_8 ;
struct V_175 V_176 [ 3 ] ;
T_1 V_177 ;
int V_18 = - 1 ;
enum V_178 V_12 ;
if ( F_37 ( V_172 , L_31 , & V_177 ) ) {
F_7 ( & V_170 -> V_47 , L_32 ) ;
return - V_48 ;
}
V_18 = V_177 ;
switch ( V_177 ) {
case 0 :
V_176 [ 0 ] = F_38 ( 0 ) ;
V_12 = V_13 ;
break;
case 1 :
V_176 [ 1 ] = F_38 ( 1 ) ;
V_12 = V_13 ;
break;
case 2 :
V_176 [ 2 ] = F_38 ( 2 ) ;
V_12 = V_13 ;
break;
case 3 :
V_12 = V_39 ;
break;
default:
F_7 ( & V_170 -> V_47 , L_33 , V_177 ) ;
return - V_48 ;
}
V_8 = & V_5 -> V_6 [ V_18 ] ;
V_8 -> V_5 = V_5 ;
V_8 -> V_18 = V_18 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_127 = - 1 ;
switch ( V_12 ) {
case V_13 :
V_8 -> V_15 = V_176 [ V_18 ] ;
* V_174 = V_179 [ V_18 ] ;
V_8 -> V_97 = V_180 ;
break;
case V_39 :
V_8 -> V_15 . V_23 = V_181 ;
V_8 -> V_15 . V_58 = V_182 ;
V_8 -> V_15 . V_88 = V_183 ;
V_8 -> V_15 . V_16 = V_43 ;
* V_174 = V_184 ;
V_8 -> V_97 = V_99 ;
break;
default:
F_7 ( & V_170 -> V_47 , L_34 , V_12 ) ;
return - V_48 ;
}
F_17 ( & V_170 -> V_47 , L_35 , V_72 , V_8 -> V_18 ) ;
V_8 -> V_55 = 0 ;
V_8 -> V_5 -> V_47 = & V_170 -> V_47 ;
V_8 -> V_75 . V_78 = false ;
V_8 -> V_75 . V_76 = false ;
F_3 ( V_8 ) ;
return 0 ;
}
static int F_39 ( struct V_169 * V_170 ,
struct V_4 * V_5 )
{
int V_65 ;
char V_185 [ V_186 ] ;
for ( V_65 = 0 ; V_65 < F_13 ( V_5 -> V_73 ) ; V_65 ++ ) {
snprintf ( V_185 , V_186 , L_36 , V_65 ) ;
V_5 -> V_73 [ V_65 ] = F_40 ( & V_170 -> V_47 , V_185 ) ;
if ( F_41 ( V_5 -> V_73 [ V_65 ] ) )
return F_42 ( V_5 -> V_73 [ V_65 ] ) ;
}
return 0 ;
}
static int F_43 ( struct V_169 * V_170 )
{
struct V_187 * V_47 = & V_170 -> V_47 ;
struct V_171 * V_188 ;
struct V_189 * V_190 = V_170 -> V_189 ;
struct V_4 * V_5 ;
int V_191 = - V_48 ;
int V_192 ;
int V_193 ;
V_5 = F_44 ( V_47 , sizeof( struct V_4 ) , V_194 ) ;
if ( ! V_5 )
return - V_195 ;
F_45 ( V_47 , V_5 ) ;
V_190 = F_46 ( V_170 , V_196 , L_37 ) ;
V_5 -> V_14 = F_47 ( V_47 , V_190 ) ;
if ( F_41 ( V_5 -> V_14 ) )
return F_42 ( V_5 -> V_14 ) ;
V_190 = F_46 ( V_170 , V_196 , L_38 ) ;
V_5 -> V_27 = F_47 ( V_47 , V_190 ) ;
if ( F_41 ( V_5 -> V_27 ) )
return F_42 ( V_5 -> V_27 ) ;
F_5 ( V_197 ,
V_5 -> V_14 + V_37 ) ;
V_192 = F_48 ( V_170 -> V_47 . V_198 ) ;
if ( ( V_192 < 1 ) || ( V_192 > V_199 ) ) {
F_7 ( V_47 , L_39 ,
V_192 , V_199 ) ;
return - V_48 ;
}
V_193 = 0 ;
F_49 (pdev->dev.of_node, child_node) {
V_191 = F_36 ( V_170 , V_188 , V_5 ,
& V_200 [ V_193 ] ) ;
if ( V_191 < 0 )
return V_191 ;
else if ( ! V_191 ) {
F_17 ( V_47 , L_40 ,
V_200 [ V_193 ] . V_201 ) ;
V_193 ++ ;
}
}
V_5 -> V_47 = V_47 ;
V_5 -> V_154 = 0 ;
F_17 ( V_47 , L_41 , V_193 ) ;
V_191 = F_50 ( V_47 , & V_202 ,
V_200 , V_193 ) ;
if ( V_191 ) {
F_7 ( V_47 , L_42 ) ;
return V_191 ;
}
V_5 -> V_203 = F_51 ( V_170 , 0 ) ;
if ( V_5 -> V_203 <= 0 ) {
F_7 ( V_47 , L_43 ) ;
V_191 = V_5 -> V_203 ;
goto V_204;
}
V_191 = F_39 ( V_170 , V_5 ) ;
if ( V_191 ) {
F_7 ( V_47 , L_44 ) ;
goto V_204;
}
V_191 = F_52 ( V_47 , V_5 ) ;
if ( V_191 ) {
F_7 ( V_47 , L_45 , V_191 ) ;
goto V_204;
}
return 0 ;
V_204:
F_53 ( V_47 ) ;
return V_191 ;
}
static int F_54 ( struct V_169 * V_170 )
{
F_55 ( & V_170 -> V_47 ) ;
F_53 ( & V_170 -> V_47 ) ;
return 0 ;
}
