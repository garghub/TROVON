static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static int F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 , int V_8 )
{
struct V_1 * V_2 = F_4 ( V_5 -> V_9 ) ;
F_2 ( V_2 , V_10 , 0x46 ) ;
switch ( V_8 ) {
case V_11 :
F_2 ( V_2 , V_12 , 0xFFFF ) ;
break;
case V_13 :
F_2 ( V_2 , V_12 , 0 ) ;
break;
}
return 0 ;
}
static int F_5 ( struct V_14 * V_15 , int V_16 ,
int V_17 , unsigned int V_18 , unsigned int V_19 )
{
int V_20 ;
struct V_1 * V_2 = V_15 -> V_2 ;
int V_21 = 0 , V_22 = 0 ;
T_1 V_23 ;
if ( V_16 < V_24 || V_16 > V_25 )
return - V_26 ;
F_6 ( V_2 , V_27 ,
V_28 ,
0 ) ;
V_23 = F_7 ( V_2 , V_29 ) ;
if ( V_23 & V_30 )
return 0 ;
if ( ! V_18 || ! V_19 )
return 0 ;
switch ( V_16 ) {
case V_24 :
for ( V_20 = 0 ; V_20 < F_8 ( V_31 ) ; V_20 ++ ) {
if ( V_31 [ V_20 ] . V_32 == V_18
&& V_31 [ V_20 ] . V_33 == V_19 ) {
V_22 = V_31 [ V_20 ] . V_34 ;
break;
}
}
break;
case V_25 :
for ( V_20 = 0 ; V_20 < F_8 ( V_35 ) ; V_20 ++ ) {
if ( V_35 [ V_20 ] . V_32 == V_18
&& V_35 [ V_20 ] . V_33 == V_19 ) {
V_21 = V_36 ;
V_22 = V_35 [ V_20 ] . V_34 ;
break;
}
}
break;
default:
return - V_37 ;
}
if ( ! V_22 )
return - V_37 ;
F_2 ( V_2 , V_38 , V_21 ) ;
F_2 ( V_2 , V_39 , V_22 ) ;
F_6 ( V_2 , V_27 ,
V_28 ,
V_28 ) ;
V_21 |= V_40 ;
F_2 ( V_2 , V_38 , V_21 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_41 )
{
struct V_42 * V_43 = F_10 ( V_2 ) ;
int V_20 ;
for ( V_20 = 0 ; V_20 < F_8 ( V_44 ) ; V_20 ++ ) {
if ( V_44 [ V_20 ] . V_45 * V_41 == V_43 -> V_46 )
return V_20 ;
}
return - V_37 ;
}
static int F_11 ( struct V_14 * V_15 ,
int V_47 , unsigned int V_48 , int V_49 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_42 * V_43 = F_10 ( V_2 ) ;
switch ( V_48 ) {
case 8192000 :
case 11289600 :
case 12288000 :
case 16384000 :
case 16934400 :
case 18432000 :
case 22579200 :
case 24576000 :
V_43 -> V_46 = V_48 ;
return 0 ;
}
return - V_37 ;
}
static int F_12 ( struct V_14 * V_15 ,
unsigned int V_50 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
T_1 V_51 = 0 ;
switch ( V_50 & V_52 ) {
case V_53 :
V_51 = V_54 ;
break;
case V_55 :
V_51 = V_30 ;
break;
default:
return - V_37 ;
}
switch ( V_50 & V_56 ) {
case V_57 :
V_51 |= V_58 ;
break;
case V_59 :
V_51 |= V_60 ;
break;
case V_61 :
V_51 |= V_62 ;
break;
case V_63 :
V_51 |= V_64 ;
break;
case V_65 :
V_51 |= V_64 | V_66 ;
break;
default:
return - V_37 ;
}
switch ( V_50 & V_67 ) {
case V_68 :
break;
case V_69 :
V_51 |= V_70 ;
break;
case V_71 :
V_51 |= V_70 ;
break;
case V_72 :
break;
default:
return - V_37 ;
}
return F_2 ( V_2 , V_29 , V_51 ) ;
}
static int F_13 ( struct V_73 * V_74 ,
struct V_75 * V_76 , struct V_14 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_2 ;
struct V_42 * V_43 = F_10 ( V_2 ) ;
int V_78 , V_41 ;
T_1 V_51 ;
V_51 = F_7 ( V_2 , V_29 ) ;
V_51 &= ~ V_79 ;
switch ( F_14 ( V_76 ) ) {
case 16 :
V_51 |= V_80 ;
break;
case 20 :
V_51 |= V_81 ;
break;
case 24 :
V_51 |= V_82 ;
break;
case 32 :
V_51 |= V_83 ;
break;
default:
return - V_37 ;
}
F_2 ( V_2 , V_29 , V_51 ) ;
V_41 = F_15 ( V_76 ) ;
V_78 = F_9 ( V_2 , V_41 ) ;
if ( V_78 < 0 )
return - V_37 ;
V_78 = V_44 [ V_78 ] . V_34 ;
F_16 ( V_2 -> V_84 , L_1 ,
V_85 , V_43 -> V_46 , V_41 , V_78 ) ;
F_2 ( V_2 , V_86 , V_78 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_77 , int V_87 )
{
struct V_1 * V_2 = V_77 -> V_2 ;
T_1 V_88 = V_89 | V_90 ;
T_1 V_91 = F_7 ( V_2 , V_92 ) & ~ V_88 ;
if ( V_87 )
V_91 |= V_88 ;
return F_2 ( V_2 , V_92 , V_91 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_10 ( V_2 ) ;
F_6 ( V_2 , V_93 ,
V_94 ,
V_94 ) ;
F_2 ( V_2 , V_95 , V_96 ) ;
F_6 ( V_2 , V_92 ,
V_97 ,
V_97 ) ;
F_19 ( 500 ) ;
F_2 ( V_2 , V_27 , V_98 ) ;
if ( V_43 -> V_99 == 0x22 )
F_2 ( V_2 , V_93 ,
V_100 ) ;
else
F_2 ( V_2 , V_93 ,
V_101 ) ;
F_6 ( V_2 , V_92 ,
V_97 ,
0 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_102 V_103 )
{
switch ( V_103 ) {
case V_104 :
F_18 ( V_2 ) ;
break;
case V_105 :
break;
case V_106 :
F_2 ( V_2 , V_27 ,
V_107 ) ;
F_2 ( V_2 , V_95 ,
V_108 ) ;
break;
case V_109 :
F_2 ( V_2 , V_27 , 0 ) ;
F_2 ( V_2 , V_95 , 0 ) ;
F_2 ( V_2 , V_93 , 0 ) ;
break;
}
V_2 -> V_9 . V_110 = V_103 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_10 ( V_2 ) ;
F_22 ( V_43 -> V_111 , true ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_10 ( V_2 ) ;
int V_112 ;
F_22 ( V_43 -> V_111 , false ) ;
V_112 = F_24 ( V_43 -> V_111 ) ;
if ( V_112 != 0 ) {
F_25 ( V_2 -> V_84 , L_2 ,
V_112 ) ;
F_22 ( V_43 -> V_111 , true ) ;
return V_112 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_10 ( V_2 ) ;
struct V_113 * V_9 = & V_2 -> V_9 ;
F_1 ( V_2 ) ;
if ( V_43 -> V_114 ) {
F_2 ( V_2 , V_115 ,
V_43 -> V_114 ) ;
}
if ( V_43 -> V_116 ) {
F_2 ( V_2 , V_117 ,
V_43 -> V_116 ) ;
}
switch ( V_43 -> V_99 ) {
case 0x21 :
F_27 ( V_2 , V_118 ,
F_8 ( V_118 ) ) ;
break;
case 0x22 :
F_27 ( V_2 , V_119 ,
F_8 ( V_119 ) ) ;
break;
case 0x23 :
F_27 ( V_2 , V_120 ,
F_8 ( V_120 ) ) ;
break;
default:
return - V_37 ;
}
F_27 ( V_2 , V_121 ,
F_8 ( V_121 ) ) ;
F_28 ( V_9 , V_122 ,
F_8 ( V_122 ) ) ;
F_29 ( V_9 , V_123 , F_8 ( V_123 ) ) ;
switch ( V_43 -> V_99 ) {
case 0x21 :
case 0x22 :
F_28 ( V_9 , V_124 ,
F_8 ( V_124 ) ) ;
F_29 ( V_9 , V_125 ,
F_8 ( V_125 ) ) ;
break;
case 0x23 :
F_29 ( V_9 , V_126 ,
F_8 ( V_126 ) ) ;
break;
default:
return - V_37 ;
}
return 0 ;
}
static int F_30 ( struct V_127 * V_128 ,
const struct V_129 * V_99 )
{
struct V_130 * V_131 ;
struct V_42 * V_43 ;
struct V_132 * V_133 ;
unsigned int V_134 , V_135 ;
int V_112 ;
T_2 V_136 ;
V_43 = F_31 ( & V_128 -> V_84 , sizeof( struct V_42 ) ,
V_137 ) ;
if ( V_43 == NULL )
return - V_138 ;
V_43 -> V_111 = F_32 ( V_128 , & V_139 ) ;
if ( F_33 ( V_43 -> V_111 ) ) {
V_112 = F_34 ( V_43 -> V_111 ) ;
F_25 ( & V_128 -> V_84 , L_3 , V_112 ) ;
return V_112 ;
}
V_112 = F_35 ( V_43 -> V_111 , V_140 , & V_134 ) ;
if ( V_112 < 0 ) {
F_25 ( & V_128 -> V_84 , L_4 , V_112 ) ;
return V_112 ;
}
V_112 = F_35 ( V_43 -> V_111 , V_141 , & V_135 ) ;
if ( V_112 < 0 ) {
F_25 ( & V_128 -> V_84 , L_5 , V_112 ) ;
return V_112 ;
}
V_135 >>= 8 ;
if ( ( V_134 != 0x10ec ) || ( V_135 != V_99 -> V_142 ) ) {
F_25 ( & V_128 -> V_84 , L_6 ) ;
F_25 ( & V_128 -> V_84 , L_7 ,
0x10ec , V_99 -> V_142 ,
V_134 , V_135 ) ;
return - V_26 ;
}
F_16 ( & V_128 -> V_84 , L_8 , V_135 ) ;
V_131 = V_128 -> V_84 . V_143 ;
if ( V_131 ) {
V_43 -> V_114 = V_131 -> V_114 ;
V_43 -> V_116 = V_131 -> V_116 ;
} else {
if ( V_128 -> V_84 . V_144 ) {
V_133 = V_128 -> V_84 . V_144 ;
V_112 = F_36 ( V_133 , L_9 , & V_136 ) ;
if ( ! V_112 )
V_43 -> V_114 = V_136 ;
V_112 = F_36 ( V_133 , L_10 , & V_136 ) ;
if ( ! V_112 )
V_43 -> V_116 = V_136 ;
}
}
V_43 -> V_99 = V_135 ;
switch ( V_43 -> V_99 ) {
case 0x21 :
V_145 . V_146 = L_11 ;
break;
case 0x22 :
V_145 . V_146 = L_12 ;
break;
case 0x23 :
V_145 . V_146 = L_13 ;
break;
default:
return - V_37 ;
}
F_37 ( V_128 , V_43 ) ;
V_112 = F_38 ( & V_128 -> V_84 ,
& V_147 , & V_145 , 1 ) ;
if ( V_112 != 0 )
F_25 ( & V_128 -> V_84 , L_14 , V_112 ) ;
return V_112 ;
}
static int F_39 ( struct V_127 * V_128 )
{
F_40 ( & V_128 -> V_84 ) ;
return 0 ;
}
