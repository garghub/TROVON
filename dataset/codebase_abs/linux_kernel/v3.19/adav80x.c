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
unsigned int V_17 = V_29 -> V_30 . V_31 . V_32 [ 0 ] ;
if ( V_17 > 1 )
return - V_33 ;
V_7 -> V_17 = V_17 ;
return F_5 ( V_5 ) ;
}
static int F_9 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = F_8 ( V_27 ) ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
V_29 -> V_30 . V_31 . V_32 [ 0 ] = V_7 -> V_17 ;
return 0 ;
}
static int F_10 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_4 * V_5 = V_35 -> V_5 ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_37 = 0x00 ;
unsigned int V_38 = 0x00 ;
switch ( V_36 & V_39 ) {
case V_40 :
V_37 |= V_41 ;
V_38 |= V_42 ;
case V_43 :
break;
default:
return - V_33 ;
}
switch ( V_36 & V_44 ) {
case V_45 :
V_37 |= V_46 ;
V_38 |= V_47 ;
break;
case V_48 :
V_37 |= V_49 ;
V_38 |= V_50 ;
break;
case V_51 :
V_37 |= V_52 ;
V_38 |= V_53 ;
break;
default:
return - V_33 ;
}
switch ( V_36 & V_54 ) {
case V_55 :
break;
default:
return - V_33 ;
}
F_6 ( V_7 -> V_23 , V_56 [ V_35 -> V_57 ] [ 0 ] ,
V_58 | V_41 ,
V_37 ) ;
F_11 ( V_7 -> V_23 , V_56 [ V_35 -> V_57 ] [ 1 ] ,
V_38 ) ;
V_7 -> V_59 [ V_35 -> V_57 ] = V_36 & V_44 ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 ,
unsigned int V_60 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_16 ;
if ( V_60 <= 48000 )
V_16 = V_61 ;
else
V_16 = V_62 ;
F_6 ( V_7 -> V_23 , V_63 ,
V_64 , V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 ,
unsigned int V_60 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_16 ;
if ( V_60 <= 48000 )
V_16 = V_65 | V_66 ;
else
V_16 = V_67 | V_68 ;
F_6 ( V_7 -> V_23 , V_24 ,
V_69 | V_70 ,
V_16 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_34 * V_35 , struct V_71 * V_72 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_16 ;
switch ( F_15 ( V_72 ) ) {
case 16 :
V_16 = V_73 ;
break;
case 18 :
V_16 = V_74 ;
break;
case 20 :
V_16 = V_75 ;
break;
case 24 :
V_16 = V_76 ;
break;
default:
return - V_33 ;
}
F_6 ( V_7 -> V_23 , V_56 [ V_35 -> V_57 ] [ 0 ] ,
V_77 , V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_34 * V_35 , struct V_71 * V_72 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_16 ;
if ( V_7 -> V_59 [ V_35 -> V_57 ] != V_51 )
return 0 ;
switch ( F_15 ( V_72 ) ) {
case 16 :
V_16 = V_78 ;
break;
case 18 :
V_16 = V_79 ;
break;
case 20 :
V_16 = V_80 ;
break;
case 24 :
V_16 = V_53 ;
break;
default:
return - V_33 ;
}
F_6 ( V_7 -> V_23 , V_56 [ V_35 -> V_57 ] [ 1 ] ,
V_81 , V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_82 * V_83 ,
struct V_71 * V_72 , struct V_34 * V_35 )
{
struct V_4 * V_5 = V_35 -> V_5 ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_18 = F_18 ( V_72 ) ;
if ( V_18 * 256 != V_7 -> V_84 )
return - V_33 ;
if ( V_83 -> V_85 == V_86 ) {
F_16 ( V_5 , V_35 , V_72 ) ;
F_13 ( V_5 , V_18 ) ;
} else {
F_14 ( V_5 , V_35 , V_72 ) ;
F_12 ( V_5 , V_18 ) ;
}
V_7 -> V_18 = V_18 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 ,
int V_87 , int V_2 ,
unsigned int V_88 , int V_89 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
struct V_90 * V_6 = & V_5 -> V_6 ;
if ( V_89 == V_91 ) {
switch ( V_87 ) {
case V_92 :
case V_12 :
case V_93 :
case V_10 :
case V_11 :
break;
default:
return - V_33 ;
}
V_7 -> V_84 = V_88 ;
if ( V_7 -> V_9 != V_87 ) {
unsigned int V_94 , V_95 ;
V_7 -> V_9 = V_87 ;
if ( V_87 == V_12 )
V_87 = V_92 ;
V_94 = F_20 ( V_87 ) |
F_21 ( V_87 ) |
F_22 ( V_87 ) ;
V_95 = F_23 ( V_87 ) ;
F_11 ( V_7 -> V_23 , V_96 ,
V_94 ) ;
F_11 ( V_7 -> V_23 , V_97 ,
V_95 ) ;
F_24 ( V_6 ) ;
}
} else {
unsigned int V_98 ;
switch ( V_87 ) {
case V_99 :
case V_100 :
case V_101 :
break;
default:
return - V_33 ;
}
V_87 -= V_99 ;
V_98 = F_25 ( V_87 ) ;
if ( V_88 == 0 ) {
F_6 ( V_7 -> V_23 , V_102 ,
V_98 , V_98 ) ;
V_7 -> V_103 [ V_87 ] = true ;
} else {
F_6 ( V_7 -> V_23 , V_102 ,
V_98 , 0 ) ;
V_7 -> V_103 [ V_87 ] = false ;
}
F_26 ( V_6 ) ;
if ( V_7 -> V_103 [ 0 ] )
F_27 ( V_6 , L_1 ) ;
else
F_28 ( V_6 , L_1 ) ;
if ( V_7 -> V_103 [ 1 ] || V_7 -> V_103 [ 2 ] )
F_27 ( V_6 , L_2 ) ;
else
F_28 ( V_6 , L_2 ) ;
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
}
return 0 ;
}
static int F_31 ( struct V_4 * V_5 , int V_104 ,
int V_2 , unsigned int V_105 , unsigned int V_106 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_107 = 0 ;
unsigned int V_108 = 0 ;
unsigned int V_14 ;
switch ( V_2 ) {
case V_15 :
case V_109 :
case V_110 :
break;
default:
return - V_33 ;
}
if ( ! V_106 )
return 0 ;
switch ( V_105 ) {
case 27000000 :
break;
case 54000000 :
if ( V_2 == V_109 ) {
V_107 |= V_111 ;
break;
}
default:
return - V_33 ;
}
if ( V_106 > 12288000 ) {
V_108 |= F_32 ( V_104 ) ;
V_106 /= 2 ;
}
switch ( V_106 ) {
case 8192000 :
V_108 |= F_33 ( V_104 ) ;
break;
case 11289600 :
V_108 |= F_34 ( V_104 ) ;
break;
case 12288000 :
V_108 |= F_35 ( V_104 ) ;
break;
default:
return - V_33 ;
}
F_6 ( V_7 -> V_23 , V_112 ,
V_111 , V_107 ) ;
F_6 ( V_7 -> V_23 , V_113 ,
F_36 ( V_104 ) , V_108 ) ;
if ( V_2 != V_7 -> V_14 ) {
if ( V_2 == V_110 )
V_14 = F_37 ( V_104 ) ;
else
V_14 = F_38 ( V_104 ) ;
F_6 ( V_7 -> V_23 , V_114 ,
F_39 ( V_104 ) , V_14 ) ;
V_7 -> V_14 = V_2 ;
F_24 ( & V_5 -> V_6 ) ;
}
return 0 ;
}
static int F_40 ( struct V_4 * V_5 ,
enum V_115 V_116 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
unsigned int V_98 = V_117 ;
switch ( V_116 ) {
case V_118 :
break;
case V_119 :
break;
case V_120 :
F_6 ( V_7 -> V_23 , V_121 , V_98 ,
0x00 ) ;
break;
case V_122 :
F_6 ( V_7 -> V_23 , V_121 , V_98 ,
V_98 ) ;
break;
}
V_5 -> V_6 . V_123 = V_116 ;
return 0 ;
}
static int F_41 ( struct V_82 * V_83 ,
struct V_34 * V_35 )
{
struct V_4 * V_5 = V_35 -> V_5 ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
if ( ! F_42 ( V_5 ) || ! V_7 -> V_18 )
return 0 ;
return F_43 ( V_83 -> V_124 ,
V_125 , V_7 -> V_18 , V_7 -> V_18 ) ;
}
static void F_44 ( struct V_82 * V_83 ,
struct V_34 * V_35 )
{
struct V_4 * V_5 = V_35 -> V_5 ;
struct V_7 * V_7 = F_3 ( V_5 ) ;
if ( ! F_42 ( V_5 ) )
V_7 -> V_18 = 0 ;
}
static int F_45 ( struct V_4 * V_5 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
F_46 ( & V_5 -> V_6 , L_1 ) ;
F_46 ( & V_5 -> V_6 , L_2 ) ;
F_11 ( V_7 -> V_23 , V_102 , 0x20 ) ;
F_11 ( V_7 -> V_23 , V_126 , 0x6 ) ;
return 0 ;
}
static int F_47 ( struct V_4 * V_5 )
{
struct V_7 * V_7 = F_3 ( V_5 ) ;
F_48 ( V_7 -> V_23 ) ;
return 0 ;
}
int F_49 ( struct V_127 * V_128 , struct V_23 * V_23 )
{
struct V_7 * V_7 ;
if ( F_50 ( V_23 ) )
return F_51 ( V_23 ) ;
V_7 = F_52 ( V_128 , sizeof( * V_7 ) , V_129 ) ;
if ( ! V_7 )
return - V_130 ;
F_53 ( V_128 , V_7 ) ;
V_7 -> V_23 = V_23 ;
return F_54 ( V_128 , & V_131 ,
V_132 , F_55 ( V_132 ) ) ;
}
