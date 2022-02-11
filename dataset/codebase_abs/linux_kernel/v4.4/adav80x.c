static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
const char * V_8 ;
switch ( V_7 -> V_9 ) {
case V_10 :
V_8 = L_1 ;
break;
case V_11 :
V_8 = L_2 ;
break;
case V_12 :
V_8 = L_3 ;
break;
default:
return 0 ;
}
return strcmp ( V_2 -> V_13 , V_8 ) == 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
return V_7 -> V_14 == V_15 ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_16 ;
if ( V_7 -> V_17 ) {
switch ( V_7 -> V_18 ) {
case 32000 :
V_16 = V_19 ;
break;
case 44100 :
V_16 = V_20 ;
break;
case 48000 :
case 64000 :
case 88200 :
case 96000 :
V_16 = V_21 ;
break;
default:
V_16 = V_22 ;
break;
}
} else {
V_16 = V_22 ;
}
return F_6 ( V_7 -> V_23 , V_24 ,
V_25 , V_16 ) ;
}
static int F_7 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = F_8 ( V_27 ) ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_17 = V_29 -> V_30 . integer . V_30 [ 0 ] ;
if ( V_17 > 1 )
return - V_31 ;
V_7 -> V_17 = V_17 ;
return F_5 ( V_5 ) ;
}
static int F_9 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = F_8 ( V_27 ) ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
V_29 -> V_30 . integer . V_30 [ 0 ] = V_7 -> V_17 ;
return 0 ;
}
static int F_10 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_4 * V_5 = V_33 -> V_5 ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_35 = 0x00 ;
unsigned int V_36 = 0x00 ;
switch ( V_34 & V_37 ) {
case V_38 :
V_35 |= V_39 ;
V_36 |= V_40 ;
case V_41 :
break;
default:
return - V_31 ;
}
switch ( V_34 & V_42 ) {
case V_43 :
V_35 |= V_44 ;
V_36 |= V_45 ;
break;
case V_46 :
V_35 |= V_47 ;
V_36 |= V_48 ;
break;
case V_49 :
V_35 |= V_50 ;
V_36 |= V_51 ;
break;
default:
return - V_31 ;
}
switch ( V_34 & V_52 ) {
case V_53 :
break;
default:
return - V_31 ;
}
F_6 ( V_7 -> V_23 , V_54 [ V_33 -> V_55 ] [ 0 ] ,
V_56 | V_39 ,
V_35 ) ;
F_11 ( V_7 -> V_23 , V_54 [ V_33 -> V_55 ] [ 1 ] ,
V_36 ) ;
V_7 -> V_57 [ V_33 -> V_55 ] = V_34 & V_42 ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 ,
unsigned int V_58 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_16 ;
if ( V_58 <= 48000 )
V_16 = V_59 ;
else
V_16 = V_60 ;
F_6 ( V_7 -> V_23 , V_61 ,
V_62 , V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 ,
unsigned int V_58 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_16 ;
if ( V_58 <= 48000 )
V_16 = V_63 | V_64 ;
else
V_16 = V_65 | V_66 ;
F_6 ( V_7 -> V_23 , V_24 ,
V_67 | V_68 ,
V_16 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_32 * V_33 , struct V_69 * V_70 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_16 ;
switch ( F_15 ( V_70 ) ) {
case 16 :
V_16 = V_71 ;
break;
case 18 :
V_16 = V_72 ;
break;
case 20 :
V_16 = V_73 ;
break;
case 24 :
V_16 = V_74 ;
break;
default:
return - V_31 ;
}
F_6 ( V_7 -> V_23 , V_54 [ V_33 -> V_55 ] [ 0 ] ,
V_75 , V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_32 * V_33 , struct V_69 * V_70 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_16 ;
if ( V_7 -> V_57 [ V_33 -> V_55 ] != V_49 )
return 0 ;
switch ( F_15 ( V_70 ) ) {
case 16 :
V_16 = V_76 ;
break;
case 18 :
V_16 = V_77 ;
break;
case 20 :
V_16 = V_78 ;
break;
case 24 :
V_16 = V_51 ;
break;
default:
return - V_31 ;
}
F_6 ( V_7 -> V_23 , V_54 [ V_33 -> V_55 ] [ 1 ] ,
V_79 , V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_80 * V_81 ,
struct V_69 * V_70 , struct V_32 * V_33 )
{
struct V_4 * V_5 = V_33 -> V_5 ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_18 = F_18 ( V_70 ) ;
if ( V_18 * 256 != V_7 -> V_82 )
return - V_31 ;
if ( V_81 -> V_83 == V_84 ) {
F_16 ( V_5 , V_33 , V_70 ) ;
F_13 ( V_5 , V_18 ) ;
} else {
F_14 ( V_5 , V_33 , V_70 ) ;
F_12 ( V_5 , V_18 ) ;
}
V_7 -> V_18 = V_18 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 ,
int V_85 , int V_2 ,
unsigned int V_86 , int V_87 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
struct V_88 * V_6 = F_20 ( V_5 ) ;
if ( V_87 == V_89 ) {
switch ( V_85 ) {
case V_90 :
case V_12 :
case V_91 :
case V_10 :
case V_11 :
break;
default:
return - V_31 ;
}
V_7 -> V_82 = V_86 ;
if ( V_7 -> V_9 != V_85 ) {
unsigned int V_92 , V_93 ;
V_7 -> V_9 = V_85 ;
if ( V_85 == V_12 )
V_85 = V_90 ;
V_92 = F_21 ( V_85 ) |
F_22 ( V_85 ) |
F_23 ( V_85 ) ;
V_93 = F_24 ( V_85 ) ;
F_11 ( V_7 -> V_23 , V_94 ,
V_92 ) ;
F_11 ( V_7 -> V_23 , V_95 ,
V_93 ) ;
F_25 ( V_6 ) ;
}
} else {
unsigned int V_96 ;
switch ( V_85 ) {
case V_97 :
case V_98 :
case V_99 :
break;
default:
return - V_31 ;
}
V_85 -= V_97 ;
V_96 = F_26 ( V_85 ) ;
if ( V_86 == 0 ) {
F_6 ( V_7 -> V_23 , V_100 ,
V_96 , V_96 ) ;
V_7 -> V_101 [ V_85 ] = true ;
} else {
F_6 ( V_7 -> V_23 , V_100 ,
V_96 , 0 ) ;
V_7 -> V_101 [ V_85 ] = false ;
}
F_27 ( V_6 ) ;
if ( V_7 -> V_101 [ 0 ] )
F_28 ( V_6 , L_1 ) ;
else
F_29 ( V_6 , L_1 ) ;
if ( V_7 -> V_101 [ 1 ] || V_7 -> V_101 [ 2 ] )
F_28 ( V_6 , L_2 ) ;
else
F_29 ( V_6 , L_2 ) ;
F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
}
return 0 ;
}
static int F_32 ( struct V_4 * V_5 , int V_102 ,
int V_2 , unsigned int V_103 , unsigned int V_104 )
{
struct V_88 * V_6 = F_20 ( V_5 ) ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_105 = 0 ;
unsigned int V_106 = 0 ;
unsigned int V_14 ;
switch ( V_2 ) {
case V_15 :
case V_107 :
case V_108 :
break;
default:
return - V_31 ;
}
if ( ! V_104 )
return 0 ;
switch ( V_103 ) {
case 27000000 :
break;
case 54000000 :
if ( V_2 == V_107 ) {
V_105 |= V_109 ;
break;
}
default:
return - V_31 ;
}
if ( V_104 > 12288000 ) {
V_106 |= F_33 ( V_102 ) ;
V_104 /= 2 ;
}
switch ( V_104 ) {
case 8192000 :
V_106 |= F_34 ( V_102 ) ;
break;
case 11289600 :
V_106 |= F_35 ( V_102 ) ;
break;
case 12288000 :
V_106 |= F_36 ( V_102 ) ;
break;
default:
return - V_31 ;
}
F_6 ( V_7 -> V_23 , V_110 ,
V_109 , V_105 ) ;
F_6 ( V_7 -> V_23 , V_111 ,
F_37 ( V_102 ) , V_106 ) ;
if ( V_2 != V_7 -> V_14 ) {
if ( V_2 == V_108 )
V_14 = F_38 ( V_102 ) ;
else
V_14 = F_39 ( V_102 ) ;
F_6 ( V_7 -> V_23 , V_112 ,
F_40 ( V_102 ) , V_14 ) ;
V_7 -> V_14 = V_2 ;
F_25 ( V_6 ) ;
}
return 0 ;
}
static int F_41 ( struct V_4 * V_5 ,
enum V_113 V_114 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_96 = V_115 ;
switch ( V_114 ) {
case V_116 :
break;
case V_117 :
break;
case V_118 :
F_6 ( V_7 -> V_23 , V_119 , V_96 ,
0x00 ) ;
break;
case V_120 :
F_6 ( V_7 -> V_23 , V_119 , V_96 ,
V_96 ) ;
break;
}
return 0 ;
}
static int F_42 ( struct V_80 * V_81 ,
struct V_32 * V_33 )
{
struct V_4 * V_5 = V_33 -> V_5 ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
if ( ! F_43 ( V_5 ) || ! V_7 -> V_18 )
return 0 ;
return F_44 ( V_81 -> V_121 ,
V_122 , V_7 -> V_18 ) ;
}
static void F_45 ( struct V_80 * V_81 ,
struct V_32 * V_33 )
{
struct V_4 * V_5 = V_33 -> V_5 ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
if ( ! F_43 ( V_5 ) )
V_7 -> V_18 = 0 ;
}
static int F_46 ( struct V_4 * V_5 )
{
struct V_88 * V_6 = F_20 ( V_5 ) ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
F_47 ( V_6 , L_1 ) ;
F_47 ( V_6 , L_2 ) ;
F_11 ( V_7 -> V_23 , V_100 , 0x20 ) ;
F_11 ( V_7 -> V_23 , V_123 , 0x6 ) ;
return 0 ;
}
static int F_48 ( struct V_4 * V_5 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
F_49 ( V_7 -> V_23 ) ;
return 0 ;
}
int F_50 ( struct V_124 * V_125 , struct V_23 * V_23 )
{
struct V_7 * V_7 ;
if ( F_51 ( V_23 ) )
return F_52 ( V_23 ) ;
V_7 = F_53 ( V_125 , sizeof( * V_7 ) , V_126 ) ;
if ( ! V_7 )
return - V_127 ;
F_54 ( V_125 , V_7 ) ;
V_7 -> V_23 = V_23 ;
return F_55 ( V_125 , & V_128 ,
V_129 , F_56 ( V_129 ) ) ;
}
