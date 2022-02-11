static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static int F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 , int V_8 )
{
F_2 ( V_5 -> V_2 , V_9 , 0x46 ) ;
switch ( V_8 ) {
case V_10 :
F_2 ( V_5 -> V_2 , V_11 , 0xFFFF ) ;
break;
case V_12 :
F_2 ( V_5 -> V_2 , V_11 , 0 ) ;
break;
}
return 0 ;
}
static int F_4 ( struct V_13 * V_14 , int V_15 ,
int V_16 , unsigned int V_17 , unsigned int V_18 )
{
int V_19 ;
struct V_1 * V_2 = V_14 -> V_2 ;
int V_20 = 0 , V_21 = 0 ;
T_1 V_22 ;
if ( V_15 < V_23 || V_15 > V_24 )
return - V_25 ;
F_5 ( V_2 , V_26 ,
V_27 ,
0 ) ;
V_22 = F_6 ( V_2 , V_28 ) ;
if ( V_22 & V_29 )
return 0 ;
if ( ! V_17 || ! V_18 )
return 0 ;
switch ( V_15 ) {
case V_23 :
for ( V_19 = 0 ; V_19 < F_7 ( V_30 ) ; V_19 ++ ) {
if ( V_30 [ V_19 ] . V_31 == V_17
&& V_30 [ V_19 ] . V_32 == V_18 ) {
V_21 = V_30 [ V_19 ] . V_33 ;
break;
}
}
break;
case V_24 :
for ( V_19 = 0 ; V_19 < F_7 ( V_34 ) ; V_19 ++ ) {
if ( V_34 [ V_19 ] . V_31 == V_17
&& V_34 [ V_19 ] . V_32 == V_18 ) {
V_20 = V_35 ;
V_21 = V_34 [ V_19 ] . V_33 ;
break;
}
}
break;
default:
return - V_36 ;
}
if ( ! V_21 )
return - V_36 ;
F_2 ( V_2 , V_37 , V_20 ) ;
F_2 ( V_2 , V_38 , V_21 ) ;
F_5 ( V_2 , V_26 ,
V_27 ,
V_27 ) ;
V_20 |= V_39 ;
F_2 ( V_2 , V_37 , V_20 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_40 )
{
struct V_41 * V_42 = F_9 ( V_2 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_7 ( V_43 ) ; V_19 ++ ) {
if ( V_43 [ V_19 ] . V_44 * V_40 == V_42 -> V_45 )
return V_19 ;
}
return - V_36 ;
}
static int F_10 ( struct V_13 * V_14 ,
int V_46 , unsigned int V_47 , int V_48 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_41 * V_42 = F_9 ( V_2 ) ;
switch ( V_47 ) {
case 8192000 :
case 11289600 :
case 12288000 :
case 16384000 :
case 16934400 :
case 18432000 :
case 22579200 :
case 24576000 :
V_42 -> V_45 = V_47 ;
return 0 ;
}
return - V_36 ;
}
static int F_11 ( struct V_13 * V_14 ,
unsigned int V_49 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
T_1 V_50 = 0 ;
switch ( V_49 & V_51 ) {
case V_52 :
V_50 = V_53 ;
break;
case V_54 :
V_50 = V_29 ;
break;
default:
return - V_36 ;
}
switch ( V_49 & V_55 ) {
case V_56 :
V_50 |= V_57 ;
break;
case V_58 :
V_50 |= V_59 ;
break;
case V_60 :
V_50 |= V_61 ;
break;
case V_62 :
V_50 |= V_63 ;
break;
case V_64 :
V_50 |= V_63 | V_65 ;
break;
default:
return - V_36 ;
}
switch ( V_49 & V_66 ) {
case V_67 :
break;
case V_68 :
V_50 |= V_69 ;
break;
case V_70 :
V_50 |= V_69 ;
break;
case V_71 :
break;
default:
return - V_36 ;
}
return F_2 ( V_2 , V_28 , V_50 ) ;
}
static int F_12 ( struct V_72 * V_73 ,
struct V_74 * V_75 , struct V_13 * V_76 )
{
struct V_1 * V_2 = V_76 -> V_2 ;
struct V_41 * V_42 = F_9 ( V_2 ) ;
int V_77 , V_40 ;
T_1 V_50 ;
V_50 = F_6 ( V_2 , V_28 ) ;
V_50 &= ~ V_78 ;
switch ( F_13 ( V_75 ) ) {
case 16 :
V_50 |= V_79 ;
break;
case 20 :
V_50 |= V_80 ;
break;
case 24 :
V_50 |= V_81 ;
break;
case 32 :
V_50 |= V_82 ;
break;
default:
return - V_36 ;
}
F_2 ( V_2 , V_28 , V_50 ) ;
V_40 = F_14 ( V_75 ) ;
V_77 = F_8 ( V_2 , V_40 ) ;
if ( V_77 < 0 )
return - V_36 ;
V_77 = V_43 [ V_77 ] . V_33 ;
F_15 ( V_2 -> V_83 , L_1 ,
V_84 , V_42 -> V_45 , V_40 , V_77 ) ;
F_2 ( V_2 , V_85 , V_77 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_76 , int V_86 )
{
struct V_1 * V_2 = V_76 -> V_2 ;
T_1 V_87 = V_88 | V_89 ;
T_1 V_90 = F_6 ( V_2 , V_91 ) & ~ V_87 ;
if ( V_86 )
V_90 |= V_87 ;
return F_2 ( V_2 , V_91 , V_90 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_9 ( V_2 ) ;
F_5 ( V_2 , V_92 ,
V_93 ,
V_93 ) ;
F_2 ( V_2 , V_94 , V_95 ) ;
F_5 ( V_2 , V_91 ,
V_96 ,
V_96 ) ;
F_18 ( 500 ) ;
F_2 ( V_2 , V_26 , V_97 ) ;
if ( V_42 -> V_98 == 0x22 )
F_2 ( V_2 , V_92 ,
V_99 ) ;
else
F_2 ( V_2 , V_92 ,
V_100 ) ;
F_5 ( V_2 , V_91 ,
V_96 ,
0 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
enum V_101 V_102 )
{
switch ( V_102 ) {
case V_103 :
F_17 ( V_2 ) ;
break;
case V_104 :
break;
case V_105 :
F_2 ( V_2 , V_26 ,
V_106 ) ;
F_2 ( V_2 , V_94 ,
V_107 ) ;
break;
case V_108 :
F_2 ( V_2 , V_26 , 0 ) ;
F_2 ( V_2 , V_94 , 0 ) ;
F_2 ( V_2 , V_92 , 0 ) ;
break;
}
V_2 -> V_109 . V_110 = V_102 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_9 ( V_2 ) ;
F_21 ( V_42 -> V_111 , true ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_9 ( V_2 ) ;
int V_112 ;
F_21 ( V_42 -> V_111 , false ) ;
V_112 = F_23 ( V_42 -> V_111 ) ;
if ( V_112 != 0 ) {
F_24 ( V_2 -> V_83 , L_2 ,
V_112 ) ;
F_21 ( V_42 -> V_111 , true ) ;
return V_112 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_9 ( V_2 ) ;
struct V_113 * V_109 = & V_2 -> V_109 ;
F_1 ( V_2 ) ;
if ( V_42 -> V_114 ) {
F_2 ( V_2 , V_115 ,
V_42 -> V_114 ) ;
}
if ( V_42 -> V_116 ) {
F_2 ( V_2 , V_117 ,
V_42 -> V_116 ) ;
}
switch ( V_42 -> V_98 ) {
case 0x21 :
F_26 ( V_2 , V_118 ,
F_7 ( V_118 ) ) ;
break;
case 0x22 :
F_26 ( V_2 , V_119 ,
F_7 ( V_119 ) ) ;
break;
case 0x23 :
F_26 ( V_2 , V_120 ,
F_7 ( V_120 ) ) ;
break;
default:
return - V_36 ;
}
F_26 ( V_2 , V_121 ,
F_7 ( V_121 ) ) ;
F_27 ( V_109 , V_122 ,
F_7 ( V_122 ) ) ;
F_28 ( V_109 , V_123 , F_7 ( V_123 ) ) ;
switch ( V_42 -> V_98 ) {
case 0x21 :
case 0x22 :
F_27 ( V_109 , V_124 ,
F_7 ( V_124 ) ) ;
F_28 ( V_109 , V_125 ,
F_7 ( V_125 ) ) ;
break;
case 0x23 :
F_28 ( V_109 , V_126 ,
F_7 ( V_126 ) ) ;
break;
default:
return - V_36 ;
}
return 0 ;
}
static int F_29 ( struct V_127 * V_128 ,
const struct V_129 * V_98 )
{
struct V_130 * V_131 ;
struct V_41 * V_42 ;
struct V_132 * V_133 ;
unsigned int V_134 , V_135 ;
int V_112 ;
T_2 V_136 ;
V_42 = F_30 ( & V_128 -> V_83 , sizeof( struct V_41 ) ,
V_137 ) ;
if ( V_42 == NULL )
return - V_138 ;
V_42 -> V_111 = F_31 ( V_128 , & V_139 ) ;
if ( F_32 ( V_42 -> V_111 ) ) {
V_112 = F_33 ( V_42 -> V_111 ) ;
F_24 ( & V_128 -> V_83 , L_3 , V_112 ) ;
return V_112 ;
}
V_112 = F_34 ( V_42 -> V_111 , V_140 , & V_134 ) ;
if ( V_112 < 0 ) {
F_24 ( & V_128 -> V_83 , L_4 , V_112 ) ;
return V_112 ;
}
V_112 = F_34 ( V_42 -> V_111 , V_141 , & V_135 ) ;
if ( V_112 < 0 ) {
F_24 ( & V_128 -> V_83 , L_5 , V_112 ) ;
return V_112 ;
}
V_135 >>= 8 ;
if ( ( V_134 != 0x10ec ) || ( V_135 != V_98 -> V_142 ) ) {
F_24 ( & V_128 -> V_83 , L_6 ) ;
F_24 ( & V_128 -> V_83 , L_7 ,
0x10ec , V_98 -> V_142 ,
V_134 , V_135 ) ;
return - V_25 ;
}
F_15 ( & V_128 -> V_83 , L_8 , V_135 ) ;
V_131 = V_128 -> V_83 . V_143 ;
if ( V_131 ) {
V_42 -> V_114 = V_131 -> V_114 ;
V_42 -> V_116 = V_131 -> V_116 ;
} else {
if ( V_128 -> V_83 . V_144 ) {
V_133 = V_128 -> V_83 . V_144 ;
V_112 = F_35 ( V_133 , L_9 , & V_136 ) ;
if ( ! V_112 )
V_42 -> V_114 = V_136 ;
V_112 = F_35 ( V_133 , L_10 , & V_136 ) ;
if ( ! V_112 )
V_42 -> V_116 = V_136 ;
}
}
V_42 -> V_98 = V_135 ;
switch ( V_42 -> V_98 ) {
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
return - V_36 ;
}
F_36 ( V_128 , V_42 ) ;
V_112 = F_37 ( & V_128 -> V_83 ,
& V_147 , & V_145 , 1 ) ;
if ( V_112 != 0 )
F_24 ( & V_128 -> V_83 , L_14 , V_112 ) ;
return V_112 ;
}
static int F_38 ( struct V_127 * V_128 )
{
F_39 ( & V_128 -> V_83 ) ;
return 0 ;
}
