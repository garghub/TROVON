static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static inline int F_4 ( struct V_2 * V_3 , unsigned char V_8 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
return F_6 ( V_10 , V_8 ) ;
}
static inline int F_7 ( struct V_2 * V_3 , unsigned char V_8 ,
unsigned char V_11 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
return F_8 ( V_10 , V_8 , V_11 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
const unsigned char * V_12 , unsigned int V_13 )
{
unsigned char V_8 , V_14 ;
unsigned int V_15 = 0 ;
if ( V_13 & 0x1 ) {
F_10 ( V_3 , L_1 ) ;
return - 1 ;
}
while ( V_15 < V_13 ) {
V_8 = * V_12 ++ ;
V_14 = * V_12 ++ ;
V_15 += 2 ;
F_7 ( V_3 , V_8 , V_14 ) ;
}
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_12 ( V_3 , L_2 ,
F_4 ( V_3 , V_17 ) ) ;
F_12 ( V_3 , L_3 ,
F_4 ( V_3 , V_18 ) ) ;
F_12 ( V_3 , L_4 ,
F_4 ( V_3 , V_19 ) ) ;
F_12 ( V_3 , L_5 ,
F_4 ( V_3 , V_20 ) ) ;
F_12 ( V_3 , L_6 ,
F_4 ( V_3 , V_21 ) ) ;
F_12 ( V_3 , L_7 ,
F_4 ( V_3 , V_22 ) ) ;
F_12 ( V_3 , L_8 ,
F_4 ( V_3 , V_23 ) ) ;
F_12 ( V_3 , L_9 ,
F_4 ( V_3 , V_24 ) ) ;
F_12 ( V_3 , L_10 ,
F_4 ( V_3 , V_25 ) ) ;
F_12 ( V_3 , L_11 ,
F_4 ( V_3 , V_26 ) ) ;
F_12 ( V_3 , L_12 ,
F_4 ( V_3 , V_27 ) ) ;
F_12 ( V_3 , L_13 ,
F_4 ( V_3 , V_28 ) ) ;
F_12 ( V_3 , L_14 ,
F_4 ( V_3 , V_29 ) ,
F_4 ( V_3 , V_30 ) ,
F_4 ( V_3 , V_31 ) ) ;
F_12 ( V_3 , L_15 ,
F_4 ( V_3 , V_32 ) ) ;
F_12 ( V_3 , L_16 ,
F_4 ( V_3 , V_33 ) ) ;
F_12 ( V_3 , L_17 ,
F_4 ( V_3 , V_34 ) ) ;
F_12 ( V_3 , L_18 ,
F_4 ( V_3 , V_35 ) ,
F_4 ( V_3 , V_36 ) ) ;
F_12 ( V_3 , L_19 ,
F_4 ( V_3 , V_37 ) ) ;
F_12 ( V_3 , L_20 ,
F_4 ( V_3 , V_38 ) ) ;
F_12 ( V_3 , L_21 ,
F_4 ( V_3 , V_39 ) ) ;
F_12 ( V_3 , L_22 ,
F_4 ( V_3 , V_40 ) ) ;
F_12 ( V_3 , L_23 ,
F_4 ( V_3 , V_41 ) ) ;
F_12 ( V_3 , L_24 ,
F_4 ( V_3 , V_42 ) ,
F_4 ( V_3 , V_43 ) ) ;
F_12 ( V_3 , L_25 ,
F_4 ( V_3 , V_44 ) ,
F_4 ( V_3 , V_45 ) ) ;
F_12 ( V_3 , L_26 ,
F_4 ( V_3 , V_46 ) ,
F_4 ( V_3 , V_47 ) ,
F_4 ( V_3 , V_48 ) ) ;
F_12 ( V_3 , L_27 ,
F_4 ( V_3 , V_49 ) ,
F_4 ( V_3 , V_50 ) ,
F_4 ( V_3 , V_51 ) ) ;
F_12 ( V_3 , L_28 ,
F_4 ( V_3 , V_52 ) ) ;
F_12 ( V_3 , L_29 ,
F_4 ( V_3 , V_53 ) ) ;
F_12 ( V_3 , L_30 ,
F_4 ( V_3 , V_54 ) ,
F_4 ( V_3 , V_55 ) ) ;
F_12 ( V_3 , L_31 ,
F_4 ( V_3 , V_56 ) ,
F_4 ( V_3 , V_57 ) ) ;
F_12 ( V_3 , L_32 ,
F_4 ( V_3 , V_58 ) ) ;
F_13 ( & V_16 -> V_7 , V_3 -> V_59 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , T_1 * V_60 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
* V_60 = V_16 -> V_60 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , T_1 V_60 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_8 ;
V_8 = F_4 ( V_3 , V_17 ) & 0xF ;
if ( V_60 == V_61 )
V_8 |= 0x60 ;
else if ( V_60 == V_62 )
V_8 |= 0x70 ;
else if ( V_60 == V_63 )
V_8 |= 0x90 ;
else if ( V_60 == V_64 )
V_8 |= 0xA0 ;
else if ( V_60 == V_65 )
V_8 |= 0xC0 ;
else if ( V_60 & V_66 )
V_8 |= 0x80 ;
else if ( V_60 & V_67 )
V_8 |= 0x50 ;
else if ( V_60 & V_68 )
V_8 |= 0xE0 ;
else
return - V_69 ;
F_7 ( V_3 , V_17 , V_8 ) ;
V_16 -> V_60 = V_60 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , T_2 V_70 )
{
int V_8 ;
V_8 = F_4 ( V_3 , V_28 ) | 0x80 ;
F_7 ( V_3 , V_28 , V_8 ) ;
F_17 ( 5000 , 10000 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
T_2 V_71 , T_2 V_72 , T_2 V_73 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_8 ;
if ( ( V_71 > V_74 ) || ( V_72 > V_75 ) )
return - V_69 ;
if ( V_71 != V_16 -> V_71 ) {
V_16 -> V_71 = V_71 ;
V_8 = F_4 ( V_3 , V_17 ) & 0xF0 ;
switch ( V_71 ) {
case V_76 :
V_8 |= 0x1 ;
break;
case V_77 :
V_8 |= 0x2 ;
break;
case V_78 :
V_8 |= 0x3 ;
break;
case V_79 :
V_8 |= 0x4 ;
break;
case V_80 :
V_8 |= 0x5 ;
break;
case V_81 :
V_8 |= 0xB ;
break;
case V_82 :
V_8 |= 0xC ;
break;
case V_83 :
V_8 |= 0xD ;
break;
case V_84 :
V_8 |= 0xE ;
break;
case V_85 :
V_8 |= 0xF ;
break;
case V_86 :
V_8 |= 0x6 ;
break;
case V_87 :
V_8 |= 0x7 ;
break;
case V_88 :
V_8 |= 0x8 ;
break;
case V_89 :
V_8 |= 0x9 ;
break;
case V_74 :
V_8 |= 0xA ;
break;
default:
break;
}
F_7 ( V_3 , V_17 , V_8 ) ;
}
if ( V_72 != V_16 -> V_72 ) {
V_16 -> V_72 = V_72 ;
V_8 = F_4 ( V_3 , V_19 ) & 0xC0 ;
switch ( V_72 ) {
case V_75 :
V_8 |= 0x9 ;
break;
default:
V_8 |= 0xC ;
break;
}
F_7 ( V_3 , V_19 , V_8 ) ;
}
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
int V_70 = V_5 -> V_70 ;
switch ( V_5 -> V_90 ) {
case V_91 :
if ( V_70 < 0 )
V_70 = 127 - V_70 ;
F_7 ( V_3 , V_23 , V_70 ) ;
break;
case V_92 :
F_7 ( V_3 , V_22 , V_70 ) ;
break;
case V_93 :
F_7 ( V_3 , V_56 , V_70 >> 8 ) ;
F_7 ( V_3 , V_57 , ( V_70 & 0xFF ) ) ;
break;
case V_94 :
F_7 ( V_3 , V_54 , V_70 >> 8 ) ;
F_7 ( V_3 , V_55 , ( V_70 & 0xFF ) ) ;
break;
default:
return - V_69 ;
}
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , T_1 * V_60 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_8 ;
V_8 = F_4 ( V_3 , V_17 ) & 0xF ;
F_7 ( V_3 , V_17 , V_8 ) ;
F_21 ( 10 ) ;
V_8 = F_4 ( V_3 , V_29 ) ;
switch ( ( V_8 >> 0x4 ) & 0x7 ) {
case 0 :
* V_60 &= V_67 ;
break;
case 1 :
* V_60 &= V_62 ;
break;
case 2 :
* V_60 &= V_64 ;
break;
case 3 :
* V_60 &= V_61 ;
break;
case 4 :
* V_60 &= V_66 ;
break;
case 5 :
* V_60 &= V_68 ;
break;
case 6 :
* V_60 &= V_65 ;
break;
case 7 :
* V_60 &= V_68 ;
break;
default:
* V_60 = V_95 ;
break;
}
F_15 ( V_3 , V_16 -> V_60 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , T_2 * V_96 )
{
int V_8 ;
* V_96 = V_97 ;
V_8 = F_4 ( V_3 , V_29 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & 0x1 )
* V_96 = 0 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , unsigned V_98 ,
enum V_99 * V_100 )
{
if ( V_98 > 0 )
return - V_69 ;
* V_100 = V_101 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_102 * V_103 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_103 -> V_100 = V_101 ;
V_103 -> V_104 = V_105 ;
if ( V_16 -> V_60 & V_106 ) {
V_103 -> V_107 = V_108 ;
V_103 -> V_109 = 720 ;
V_103 -> V_110 = 480 ;
} else {
V_103 -> V_107 = V_111 ;
V_103 -> V_109 = 720 ;
V_103 -> V_110 = 576 ;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_102 * V_103 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_24 ( V_3 , V_103 ) ;
V_16 -> V_103 = * V_103 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_102 * V_103 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
* V_103 = V_16 -> V_103 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , int V_112 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_112 )
F_28 ( V_16 -> V_113 , 0 ) ;
else
F_28 ( V_16 -> V_113 , 1 ) ;
F_29 ( 1 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , struct V_114 * V_8 )
{
V_8 -> V_70 = F_4 ( V_3 , V_8 -> V_8 & 0xff ) ;
V_8 -> V_115 = 1 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , const struct V_114 * V_8 )
{
F_7 ( V_3 , V_8 -> V_8 & 0xff , V_8 -> V_70 & 0xff ) ;
return 0 ;
}
static int F_32 ( struct V_9 * V_10 ,
const struct V_116 * V_90 )
{
struct V_1 * V_16 ;
struct V_2 * V_3 ;
struct V_117 * V_7 ;
int V_118 ;
struct V_102 V_103 ;
const unsigned * V_119 ;
if ( ! F_33 ( V_10 -> V_120 , V_121 ) )
return - V_122 ;
F_34 ( V_10 , L_33 ,
V_10 -> V_123 << 1 , V_10 -> V_120 -> V_59 ) ;
V_119 = V_10 -> V_124 . V_125 ;
if ( V_119 == NULL )
return - V_69 ;
V_16 = F_35 ( & V_10 -> V_124 , sizeof( * V_16 ) , V_126 ) ;
if ( V_16 == NULL )
return - V_127 ;
V_16 -> V_128 = V_119 [ 0 ] ;
V_16 -> V_113 = V_119 [ 1 ] ;
if ( F_36 ( & V_10 -> V_124 , V_16 -> V_128 ,
V_129 , L_34 ) ) {
F_37 ( V_10 , L_35 , V_16 -> V_128 ) ;
return - V_130 ;
}
if ( F_36 ( & V_10 -> V_124 , V_16 -> V_113 ,
V_131 ,
L_36 ) ) {
F_37 ( V_10 , L_35 , V_16 -> V_113 ) ;
return - V_130 ;
}
V_3 = & V_16 -> V_3 ;
F_38 ( V_3 , V_10 , & V_132 ) ;
V_7 = & V_16 -> V_7 ;
F_39 ( V_7 , 4 ) ;
F_40 ( V_7 , & V_133 ,
V_91 , - 128 , 127 , 1 , 0 ) ;
F_40 ( V_7 , & V_133 ,
V_92 , 0 , 0xFF , 1 , 0x80 ) ;
F_40 ( V_7 , & V_133 ,
V_93 , 0 , 0xFFFF , 1 , 0x8080 ) ;
F_40 ( V_7 , & V_133 ,
V_94 , 0 , 0xFFFF , 1 , 0x8080 ) ;
V_3 -> V_134 = V_7 ;
if ( V_7 -> error ) {
V_118 = V_7 -> error ;
F_41 ( V_7 ) ;
return V_118 ;
}
V_16 -> V_60 = V_66 ;
V_16 -> V_71 = V_79 ;
V_16 -> V_72 = V_135 ;
F_21 ( 10 ) ;
F_28 ( V_16 -> V_128 , 1 ) ;
F_21 ( 5 ) ;
F_9 ( V_3 , V_136 , F_42 ( V_136 ) ) ;
F_15 ( V_3 , V_16 -> V_60 ) ;
V_103 . V_109 = 720 ;
V_103 . V_110 = 576 ;
F_25 ( V_3 , & V_103 ) ;
V_118 = F_43 ( V_7 ) ;
if ( V_118 ) {
F_41 ( V_7 ) ;
return V_118 ;
}
return 0 ;
}
static int F_44 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_45 ( V_10 ) ;
F_46 ( V_3 ) ;
F_41 ( V_3 -> V_134 ) ;
return 0 ;
}
