static unsigned int F_1 ( struct V_1 * V_1 ,
unsigned int V_2 )
{
const unsigned int * V_3 = NULL ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( V_5 [ V_4 ] . V_2 == V_2 ) {
V_3 = V_5 [ V_4 ] . V_3 ;
break;
}
}
if ( ! V_3 )
return - V_6 ;
for ( V_4 = 0 ; V_3 [ V_4 ] ; V_4 ++ ) {
if ( V_3 [ V_4 ] == V_1 -> V_7 )
return V_4 ;
}
return - V_6 ;
}
static int F_3 ( struct V_8 * V_9 ,
struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_1 * V_1 = F_4 ( V_15 ) ;
unsigned int V_2 = F_5 ( V_11 ) ;
unsigned int V_16 , V_17 ;
int V_18 ;
int V_19 ;
V_18 = F_1 ( V_1 , V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_17 = V_20 ;
if ( V_2 >= 8000 && V_2 <= 12000 )
V_16 = V_21 ;
else if ( V_2 >= 16000 && V_2 <= 24000 )
V_16 = V_22 ;
else if ( V_2 >= 32000 && V_2 <= 48000 )
V_16 = V_23 ;
else if ( V_2 >= 64000 && V_2 <= 96000 )
V_16 = V_24 ;
else
return - V_6 ;
if ( V_1 -> V_25 ) {
switch ( F_6 ( V_11 ) ) {
case V_26 :
V_16 |= V_27 ;
break;
case V_28 :
V_16 |= V_29 ;
break;
default:
return - V_6 ;
}
V_17 |= V_30 ;
}
V_19 = F_7 ( V_1 -> V_31 , V_32 ,
V_33 , V_33 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_7 ( V_1 -> V_31 , V_34 ,
V_17 , V_16 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_7 ( V_1 -> V_31 , V_35 ,
V_36 , V_18 << 1 ) ;
}
static int F_8 ( struct V_12 * V_13 , int V_37 )
{
struct V_1 * V_1 = F_4 ( V_13 -> V_15 ) ;
unsigned int V_38 ;
if ( V_37 )
V_38 = V_39 ;
else
V_38 = 0 ;
return F_7 ( V_1 -> V_31 , V_40 ,
V_39 , V_38 ) ;
}
static int F_9 ( struct V_12 * V_13 , unsigned int V_41 )
{
struct V_1 * V_1 = F_4 ( V_13 -> V_15 ) ;
unsigned int V_16 = 0 , V_42 = 0 ;
bool V_43 ;
int V_19 ;
switch ( V_41 & V_44 ) {
case V_45 :
break;
default:
return - V_6 ;
}
switch ( V_41 & V_46 ) {
case V_47 :
V_43 = false ;
break;
case V_48 :
V_42 |= V_49 ;
V_43 = false ;
break;
case V_50 :
V_43 = true ;
break;
case V_51 :
V_42 |= V_49 ;
V_43 = true ;
break;
default:
return - V_6 ;
}
V_1 -> V_25 = false ;
switch ( V_41 & V_52 ) {
case V_53 :
V_16 |= V_54 ;
break;
case V_55 :
V_16 |= V_56 ;
V_43 = ! V_43 ;
break;
case V_57 :
V_16 |= V_29 ;
V_1 -> V_25 = true ;
V_43 = ! V_43 ;
break;
case V_58 :
V_42 |= V_59 ;
V_16 |= V_54 ;
V_43 = false ;
break;
case V_60 :
V_42 |= V_59 ;
V_16 |= V_56 ;
V_43 = false ;
break;
default:
return - V_6 ;
}
if ( V_43 )
V_42 |= V_61 ;
V_19 = F_10 ( V_1 -> V_31 , V_34 , V_16 ) ;
if ( V_19 )
return V_19 ;
return F_10 ( V_1 -> V_31 , V_62 , V_42 ) ;
}
static int F_11 ( struct V_1 * V_1 , bool V_63 )
{
int V_19 = 0 ;
if ( ! V_63 ) {
V_19 = F_7 ( V_1 -> V_31 , V_35 ,
V_64 , V_64 ) ;
F_12 ( V_1 -> V_31 ) ;
}
if ( F_13 ( V_1 -> V_65 ) )
F_14 ( V_1 -> V_65 , V_63 ) ;
F_15 ( V_1 -> V_31 , ! V_63 ) ;
if ( V_63 ) {
V_19 = F_7 ( V_1 -> V_31 , V_35 ,
V_64 | V_66 , 0x00 ) ;
F_16 ( V_1 -> V_31 ) ;
}
return V_19 ;
}
static int F_17 ( struct V_14 * V_15 ,
enum V_67 V_68 )
{
struct V_1 * V_1 = F_4 ( V_15 ) ;
int V_19 = 0 ;
switch ( V_68 ) {
case V_69 :
break;
case V_70 :
break;
case V_71 :
if ( V_15 -> V_72 . V_73 == V_74 )
V_19 = F_11 ( V_1 , true ) ;
break;
case V_74 :
V_19 = F_11 ( V_1 , false ) ;
break;
}
if ( V_19 )
return V_19 ;
V_15 -> V_72 . V_73 = V_68 ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 , unsigned int V_75 ,
unsigned int V_76 , int V_77 , int V_78 )
{
struct V_1 * V_1 = F_4 ( V_13 -> V_15 ) ;
unsigned int V_16 , V_42 ;
int V_79 , V_80 ;
int V_19 ;
if ( V_77 == 0 )
return F_7 ( V_1 -> V_31 ,
V_34 , V_81 ,
V_82 ) ;
if ( V_75 == 0 || V_76 != 0 )
return - V_6 ;
if ( V_77 == 1 ) {
if ( V_75 != 1 )
return - V_6 ;
V_79 = 0 ;
V_80 = 0 ;
} else {
V_79 = F_19 ( V_75 ) ;
V_75 &= ~ ( 1 << V_79 ) ;
if ( V_75 == 0 ) {
V_80 = V_79 ;
} else {
V_80 = F_19 ( V_75 ) ;
V_75 &= ~ ( 1 << V_80 ) ;
}
}
if ( V_75 != 0 || V_79 >= V_77 || V_80 >= V_77 )
return - V_6 ;
switch ( V_78 ) {
case 16 :
V_42 = V_83 ;
break;
case 24 :
V_42 = V_84 ;
break;
case 32 :
V_42 = V_85 ;
break;
default:
return - V_6 ;
}
switch ( V_77 ) {
case 1 :
V_16 = V_86 ;
break;
case 2 :
V_16 = V_87 ;
break;
case 4 :
V_16 = V_88 ;
break;
case 8 :
V_16 = V_89 ;
break;
case 16 :
V_16 = V_90 ;
break;
default:
return - V_6 ;
}
V_19 = F_10 ( V_1 -> V_31 , V_91 ,
( V_79 << V_92 ) |
( V_80 << V_93 ) ) ;
if ( V_19 )
return V_19 ;
V_19 = F_7 ( V_1 -> V_31 , V_34 ,
V_81 , V_16 ) ;
if ( V_19 )
return V_19 ;
return F_7 ( V_1 -> V_31 , V_62 ,
V_94 , V_42 ) ;
}
static int F_20 ( struct V_8 * V_9 ,
struct V_12 * V_13 )
{
struct V_1 * V_1 = F_4 ( V_13 -> V_15 ) ;
if ( V_1 -> V_95 )
F_21 ( V_9 -> V_96 , 0 ,
V_97 , V_1 -> V_95 ) ;
return 0 ;
}
static int F_22 ( struct V_14 * V_15 )
{
return F_17 ( V_15 , V_74 ) ;
}
static int F_23 ( struct V_14 * V_15 )
{
F_17 ( V_15 , V_74 ) ;
return 0 ;
}
static int F_24 ( struct V_14 * V_15 , int V_98 ,
int V_99 , unsigned int V_100 , int V_101 )
{
struct V_1 * V_1 = F_4 ( V_15 ) ;
unsigned int V_38 ;
if ( V_98 != V_102 )
return - V_6 ;
switch ( V_99 ) {
case V_103 :
V_38 = 0 ;
break;
case V_104 :
V_38 = V_105 ;
break;
default:
return - V_6 ;
}
switch ( V_100 ) {
case 0 :
V_1 -> V_95 = NULL ;
break;
case 2048000 :
case 4096000 :
case 8192000 :
case 3200000 :
case 6400000 :
case 12800000 :
V_1 -> V_95 = & V_106 ;
break;
case 2822000 :
case 5644800 :
case 11289600 :
case 16934400 :
case 22579200 :
case 33868800 :
case 4410000 :
case 8820000 :
case 17640000 :
V_1 -> V_95 = & V_107 ;
break;
case 3072000 :
case 6144000 :
case 38864000 :
case 4800000 :
case 9600000 :
case 19200000 :
V_1 -> V_95 = & V_108 ;
break;
case 12288000 :
case 16384000 :
case 24576000 :
V_1 -> V_95 = & V_109 ;
break;
default:
return - V_6 ;
}
V_1 -> V_7 = V_100 ;
return F_7 ( V_1 -> V_31 , V_35 ,
V_105 , V_38 ) ;
}
static bool F_25 ( struct V_110 * V_111 , unsigned int V_112 )
{
return false ;
}
static int F_26 ( struct V_113 * V_114 ,
const struct V_115 * V_116 )
{
struct V_117 * V_118 = V_114 -> V_111 . V_119 ;
struct V_1 * V_1 ;
int V_19 ;
V_1 = F_27 ( & V_114 -> V_111 , sizeof( * V_1 ) , V_120 ) ;
if ( V_1 == NULL )
return - V_121 ;
if ( V_118 ) {
V_1 -> V_65 = V_118 -> V_65 ;
} else if ( V_114 -> V_111 . V_122 ) {
V_1 -> V_65 = F_28 ( V_114 -> V_111 . V_122 , 0 ) ;
if ( V_1 -> V_65 < 0 && V_1 -> V_65 != - V_123 )
return V_1 -> V_65 ;
} else {
V_1 -> V_65 = - 1 ;
}
if ( F_13 ( V_1 -> V_65 ) ) {
V_19 = F_29 ( & V_114 -> V_111 , V_1 -> V_65 ,
V_124 , L_1 ) ;
if ( V_19 )
return V_19 ;
}
F_30 ( V_114 , V_1 ) ;
V_1 -> V_31 = F_31 ( V_114 , & V_125 ) ;
if ( F_32 ( V_1 -> V_31 ) )
return F_33 ( V_1 -> V_31 ) ;
F_34 ( V_1 -> V_31 , true ) ;
V_19 = F_10 ( V_1 -> V_31 , V_35 ,
V_66 ) ;
F_34 ( V_1 -> V_31 , false ) ;
if ( V_19 )
return V_19 ;
V_19 = F_7 ( V_1 -> V_31 , V_126 ,
V_127 , 0x00 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_11 ( V_1 , false ) ;
if ( V_19 )
return V_19 ;
return F_35 ( & V_114 -> V_111 , & V_128 ,
& V_129 , 1 ) ;
}
static int F_36 ( struct V_113 * V_130 )
{
F_37 ( & V_130 -> V_111 ) ;
return 0 ;
}
