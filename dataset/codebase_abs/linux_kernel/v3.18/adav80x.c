static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
const char * V_7 ;
switch ( V_6 -> V_8 ) {
case V_9 :
V_7 = L_1 ;
break;
case V_10 :
V_7 = L_2 ;
break;
case V_11 :
V_7 = L_3 ;
break;
default:
return 0 ;
}
return strcmp ( V_2 -> V_12 , V_7 ) == 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
return V_6 -> V_13 == V_14 ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_15 ;
if ( V_6 -> V_16 ) {
switch ( V_6 -> V_17 ) {
case 32000 :
V_15 = V_18 ;
break;
case 44100 :
V_15 = V_19 ;
break;
case 48000 :
case 64000 :
case 88200 :
case 96000 :
V_15 = V_20 ;
break;
default:
V_15 = V_21 ;
break;
}
} else {
V_15 = V_21 ;
}
return F_5 ( V_6 -> V_22 , V_23 ,
V_24 , V_15 ) ;
}
static int F_6 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_4 * V_5 = F_7 ( V_26 ) ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_16 = V_28 -> V_29 . V_30 . V_31 [ 0 ] ;
if ( V_16 > 1 )
return - V_32 ;
V_6 -> V_16 = V_16 ;
return F_4 ( V_5 ) ;
}
static int F_8 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_4 * V_5 = F_7 ( V_26 ) ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
V_28 -> V_29 . V_30 . V_31 [ 0 ] = V_6 -> V_16 ;
return 0 ;
}
static int F_9 ( struct V_33 * V_34 , unsigned int V_35 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_36 = 0x00 ;
unsigned int V_37 = 0x00 ;
switch ( V_35 & V_38 ) {
case V_39 :
V_36 |= V_40 ;
V_37 |= V_41 ;
case V_42 :
break;
default:
return - V_32 ;
}
switch ( V_35 & V_43 ) {
case V_44 :
V_36 |= V_45 ;
V_37 |= V_46 ;
break;
case V_47 :
V_36 |= V_48 ;
V_37 |= V_49 ;
break;
case V_50 :
V_36 |= V_51 ;
V_37 |= V_52 ;
break;
default:
return - V_32 ;
}
switch ( V_35 & V_53 ) {
case V_54 :
break;
default:
return - V_32 ;
}
F_5 ( V_6 -> V_22 , V_55 [ V_34 -> V_56 ] [ 0 ] ,
V_57 | V_40 ,
V_36 ) ;
F_10 ( V_6 -> V_22 , V_55 [ V_34 -> V_56 ] [ 1 ] ,
V_37 ) ;
V_6 -> V_58 [ V_34 -> V_56 ] = V_35 & V_43 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 ,
unsigned int V_59 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_15 ;
if ( V_59 <= 48000 )
V_15 = V_60 ;
else
V_15 = V_61 ;
F_5 ( V_6 -> V_22 , V_62 ,
V_63 , V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 ,
unsigned int V_59 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_15 ;
if ( V_59 <= 48000 )
V_15 = V_64 | V_65 ;
else
V_15 = V_66 | V_67 ;
F_5 ( V_6 -> V_22 , V_23 ,
V_68 | V_69 ,
V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_33 * V_34 , struct V_70 * V_71 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_15 ;
switch ( F_14 ( V_71 ) ) {
case 16 :
V_15 = V_72 ;
break;
case 18 :
V_15 = V_73 ;
break;
case 20 :
V_15 = V_74 ;
break;
case 24 :
V_15 = V_75 ;
break;
default:
return - V_32 ;
}
F_5 ( V_6 -> V_22 , V_55 [ V_34 -> V_56 ] [ 0 ] ,
V_76 , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_33 * V_34 , struct V_70 * V_71 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_15 ;
if ( V_6 -> V_58 [ V_34 -> V_56 ] != V_50 )
return 0 ;
switch ( F_14 ( V_71 ) ) {
case 16 :
V_15 = V_77 ;
break;
case 18 :
V_15 = V_78 ;
break;
case 20 :
V_15 = V_79 ;
break;
case 24 :
V_15 = V_52 ;
break;
default:
return - V_32 ;
}
F_5 ( V_6 -> V_22 , V_55 [ V_34 -> V_56 ] [ 1 ] ,
V_80 , V_15 ) ;
return 0 ;
}
static int F_16 ( struct V_81 * V_82 ,
struct V_70 * V_71 , struct V_33 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_17 = F_17 ( V_71 ) ;
if ( V_17 * 256 != V_6 -> V_83 )
return - V_32 ;
if ( V_82 -> V_84 == V_85 ) {
F_15 ( V_5 , V_34 , V_71 ) ;
F_12 ( V_5 , V_17 ) ;
} else {
F_13 ( V_5 , V_34 , V_71 ) ;
F_11 ( V_5 , V_17 ) ;
}
V_6 -> V_17 = V_17 ;
F_4 ( V_5 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 ,
int V_86 , int V_2 ,
unsigned int V_87 , int V_88 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
struct V_89 * V_90 = & V_5 -> V_90 ;
if ( V_88 == V_91 ) {
switch ( V_86 ) {
case V_92 :
case V_11 :
case V_93 :
case V_9 :
case V_10 :
break;
default:
return - V_32 ;
}
V_6 -> V_83 = V_87 ;
if ( V_6 -> V_8 != V_86 ) {
unsigned int V_94 , V_95 ;
V_6 -> V_8 = V_86 ;
if ( V_86 == V_11 )
V_86 = V_92 ;
V_94 = F_19 ( V_86 ) |
F_20 ( V_86 ) |
F_21 ( V_86 ) ;
V_95 = F_22 ( V_86 ) ;
F_10 ( V_6 -> V_22 , V_96 ,
V_94 ) ;
F_10 ( V_6 -> V_22 , V_97 ,
V_95 ) ;
F_23 ( V_90 ) ;
}
} else {
unsigned int V_98 ;
switch ( V_86 ) {
case V_99 :
case V_100 :
case V_101 :
break;
default:
return - V_32 ;
}
V_86 -= V_99 ;
V_98 = F_24 ( V_86 ) ;
if ( V_87 == 0 ) {
F_5 ( V_6 -> V_22 , V_102 ,
V_98 , V_98 ) ;
V_6 -> V_103 [ V_86 ] = true ;
} else {
F_5 ( V_6 -> V_22 , V_102 ,
V_98 , 0 ) ;
V_6 -> V_103 [ V_86 ] = false ;
}
F_25 ( V_90 ) ;
if ( V_6 -> V_103 [ 0 ] )
F_26 ( V_90 , L_1 ) ;
else
F_27 ( V_90 , L_1 ) ;
if ( V_6 -> V_103 [ 1 ] || V_6 -> V_103 [ 2 ] )
F_26 ( V_90 , L_2 ) ;
else
F_27 ( V_90 , L_2 ) ;
F_28 ( V_90 ) ;
F_29 ( V_90 ) ;
}
return 0 ;
}
static int F_30 ( struct V_4 * V_5 , int V_104 ,
int V_2 , unsigned int V_105 , unsigned int V_106 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_107 = 0 ;
unsigned int V_108 = 0 ;
unsigned int V_13 ;
switch ( V_2 ) {
case V_14 :
case V_109 :
case V_110 :
break;
default:
return - V_32 ;
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
return - V_32 ;
}
if ( V_106 > 12288000 ) {
V_108 |= F_31 ( V_104 ) ;
V_106 /= 2 ;
}
switch ( V_106 ) {
case 8192000 :
V_108 |= F_32 ( V_104 ) ;
break;
case 11289600 :
V_108 |= F_33 ( V_104 ) ;
break;
case 12288000 :
V_108 |= F_34 ( V_104 ) ;
break;
default:
return - V_32 ;
}
F_5 ( V_6 -> V_22 , V_112 ,
V_111 , V_107 ) ;
F_5 ( V_6 -> V_22 , V_113 ,
F_35 ( V_104 ) , V_108 ) ;
if ( V_2 != V_6 -> V_13 ) {
if ( V_2 == V_110 )
V_13 = F_36 ( V_104 ) ;
else
V_13 = F_37 ( V_104 ) ;
F_5 ( V_6 -> V_22 , V_114 ,
F_38 ( V_104 ) , V_13 ) ;
V_6 -> V_13 = V_2 ;
F_23 ( & V_5 -> V_90 ) ;
}
return 0 ;
}
static int F_39 ( struct V_4 * V_5 ,
enum V_115 V_116 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
unsigned int V_98 = V_117 ;
switch ( V_116 ) {
case V_118 :
break;
case V_119 :
break;
case V_120 :
F_5 ( V_6 -> V_22 , V_121 , V_98 ,
0x00 ) ;
break;
case V_122 :
F_5 ( V_6 -> V_22 , V_121 , V_98 ,
V_98 ) ;
break;
}
V_5 -> V_90 . V_123 = V_116 ;
return 0 ;
}
static int F_40 ( struct V_81 * V_82 ,
struct V_33 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
if ( ! F_41 ( V_5 ) || ! V_6 -> V_17 )
return 0 ;
return F_42 ( V_82 -> V_124 ,
V_125 , V_6 -> V_17 , V_6 -> V_17 ) ;
}
static void F_43 ( struct V_81 * V_82 ,
struct V_33 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_5 ) ;
if ( ! F_41 ( V_5 ) )
V_6 -> V_17 = 0 ;
}
static int F_44 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
F_45 ( & V_5 -> V_90 , L_1 ) ;
F_45 ( & V_5 -> V_90 , L_2 ) ;
F_10 ( V_6 -> V_22 , V_102 , 0x20 ) ;
F_10 ( V_6 -> V_22 , V_126 , 0x6 ) ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_5 ) ;
F_47 ( V_6 -> V_22 ) ;
return 0 ;
}
int F_48 ( struct V_127 * V_128 , struct V_22 * V_22 )
{
struct V_6 * V_6 ;
if ( F_49 ( V_22 ) )
return F_50 ( V_22 ) ;
V_6 = F_51 ( V_128 , sizeof( * V_6 ) , V_129 ) ;
if ( ! V_6 )
return - V_130 ;
F_52 ( V_128 , V_6 ) ;
V_6 -> V_22 = V_22 ;
return F_53 ( V_128 , & V_131 ,
V_132 , F_54 ( V_132 ) ) ;
}
