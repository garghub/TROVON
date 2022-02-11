static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 . V_2 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
int V_11 ;
V_9 = F_3 ( V_12 , V_13 ) ;
if ( V_9 == NULL ) {
F_4 ( & V_7 -> V_14 , L_1 , V_15 ) ;
F_5 ( & V_4 -> V_5 ,
F_6 ( 2 ) ) ;
return;
}
V_11 = F_7 ( V_7 -> V_16 -> V_14 ,
F_8 ( V_7 -> V_16 -> V_14 , 0 ) ,
V_17 ,
V_18 ,
0 , 0 ,
V_9 , V_12 ,
100 ) ;
if ( V_11 != V_12 ) {
F_4 ( & V_7 -> V_14 , L_2 , V_15 ) ;
F_9 ( V_9 ) ;
F_5 ( & V_4 -> V_5 ,
F_6 ( 2 ) ) ;
return;
}
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( ! F_11 ( V_9 , V_4 ) ) {
V_9 -> V_20 = V_4 -> V_21 . V_20 ;
V_9 -> V_22 = V_4 -> V_21 . V_22 ;
V_9 -> V_23 = V_4 -> V_21 . V_23 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
V_11 = F_7 ( V_7 -> V_16 -> V_14 ,
F_13 ( V_7 -> V_16 -> V_14 , 0 ) ,
V_24 ,
V_25 ,
0 , 0 ,
V_9 , V_12 ,
100 ) ;
} else {
F_12 ( & V_4 -> V_19 , V_10 ) ;
V_11 = 0 ;
}
F_9 ( V_9 ) ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( V_11 != V_12 )
V_4 -> V_26 = 0 ;
V_4 -> V_27 = 1 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
F_14 ( & V_7 -> V_14 , L_3 , V_15 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_13 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_7 -> V_14 , L_4 ,
V_15 , V_11 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_29 . V_2 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_30 = 0 , V_11 ;
unsigned long V_10 ;
T_1 * V_31 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( V_4 -> V_10 . V_32 ) {
F_12 ( & V_4 -> V_19 , V_10 ) ;
F_5 ( & V_4 -> V_29 ,
F_6 ( 2 ) ) ;
return;
}
V_4 -> V_10 . V_32 = 1 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
V_30 = F_17 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
if ( V_30 > V_7 -> V_34 )
V_30 = V_7 -> V_34 ;
if ( V_30 != 0 ) {
V_31 = F_3 ( 1 , V_13 ) ;
if ( ! V_31 ) {
F_18 ( V_7 , L_5 ,
V_15 ) ;
return;
}
V_11 = F_7 ( V_7 -> V_16 -> V_14 ,
F_8 ( V_7 -> V_16 -> V_14 , 0 ) ,
V_35 ,
V_36 ,
V_30 , 0 , V_31 , 1 , 100 ) ;
if ( V_11 != 1 || * V_31 != 0 )
V_30 = 0 ;
F_9 ( V_31 ) ;
}
if ( V_30 == 0 ) {
V_4 -> V_10 . V_32 = 0 ;
F_14 ( & V_7 -> V_14 , L_3 , V_15 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_37 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_7 -> V_14 , L_4 ,
V_15 , V_11 ) ;
}
return;
}
V_30 = F_19 ( & V_7 -> V_33 ,
V_7 -> V_38 -> V_39 ,
V_30 , & V_7 -> V_19 ) ;
V_7 -> V_38 -> V_40 = V_30 ;
V_11 = F_15 ( V_7 -> V_38 , V_37 ) ;
if ( V_11 != 0 ) {
F_18 ( V_7 , L_4 ,
V_15 , V_11 ) ;
V_4 -> V_10 . V_32 = 0 ;
}
F_20 ( V_7 ) ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_3 * V_4 ;
V_4 = F_22 ( sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 )
return - V_41 ;
F_23 ( & V_4 -> V_19 ) ;
V_4 -> V_7 = V_7 ;
F_24 ( & V_4 -> V_5 , F_1 ) ;
F_24 ( & V_4 -> V_29 , F_16 ) ;
F_25 ( V_7 , V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_3 * V_4 ;
V_4 = F_27 ( V_7 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_28 ( struct V_42 * V_43 , struct V_6 * V_7 ,
const unsigned char * V_44 , int V_30 )
{
if ( ! V_30 )
return V_30 ;
V_30 = F_29 ( & V_7 -> V_33 , V_44 , V_30 , & V_7 -> V_19 ) ;
return V_30 ;
}
static int F_30 ( struct V_42 * V_43 )
{
struct V_6 * V_7 = V_43 -> V_45 ;
int V_46 = 0 ;
unsigned long V_10 ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
V_46 = F_31 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
return V_46 ;
}
static int F_32 ( struct V_42 * V_43 )
{
struct V_6 * V_7 = V_43 -> V_45 ;
int V_47 = 0 ;
unsigned long V_10 ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
V_47 = F_17 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
return V_47 ;
}
static void F_33 ( struct V_42 * V_43 )
{
V_43 -> V_48 = V_49 ;
V_43 -> V_48 . V_50 = V_51 | V_52 | V_53 | V_54 | V_55 ;
V_43 -> V_48 . V_56 = 38400 ;
V_43 -> V_48 . V_57 = 38400 ;
}
static void F_34 ( struct V_42 * V_43 ,
struct V_6 * V_7 , struct V_58 * V_59 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
unsigned int V_60 ;
T_1 V_23 , V_22 ;
T_2 V_20 ;
int V_61 ;
if ( ! V_43 )
return;
V_60 = V_43 -> V_48 . V_50 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_20 = V_4 -> V_21 . V_20 ;
V_23 = V_4 -> V_21 . V_23 ;
V_22 = V_4 -> V_21 . V_22 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
V_23 &= ~ V_62 ;
switch ( V_60 & V_63 ) {
case V_64 :
V_23 |= V_65 ;
break;
case V_66 :
V_23 |= V_67 ;
break;
case V_68 :
V_23 |= V_69 ;
break;
default:
case V_52 :
V_23 |= V_70 ;
break;
}
V_61 = F_35 ( V_43 ) ;
if ( V_61 == 0 ) {
V_20 = 0 ;
} else {
int V_71 ;
int V_72 ;
V_61 = F_36 ( V_61 , V_73 ) ;
V_72 = ( 96000000 + 8 * V_61 ) / ( 16 * V_61 ) ;
V_71 = 96000000 / ( 16 * V_72 ) ;
V_20 = F_37 ( V_72 ) ;
F_38 ( V_43 , V_71 , V_71 ) ;
}
V_23 &= ~ V_74 ;
if ( ( V_60 & V_75 ) != 0 )
V_23 |= V_76 ;
else
V_23 |= V_77 ;
V_23 &= ~ V_78 ;
if ( ( V_60 & V_79 ) != 0 ) {
if ( ( V_60 & V_80 ) != 0 )
V_23 |= V_81 ;
else
V_23 |= V_82 ;
} else {
V_23 |= V_83 ;
}
V_22 &= ~ V_84 ;
if ( ( V_60 & V_85 ) != 0 )
V_22 |= ( V_86 | V_87 ) ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( V_20 != V_4 -> V_21 . V_20
|| V_22 != V_4 -> V_21 . V_22
|| V_23 != V_4 -> V_21 . V_23 ) {
V_4 -> V_21 . V_20 = V_20 ;
V_4 -> V_21 . V_22 = V_22 ;
V_4 -> V_21 . V_23 = V_23 ;
}
F_12 ( & V_4 -> V_19 , V_10 ) ;
}
static int F_39 ( struct V_42 * V_43 , struct V_6 * V_7 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
struct V_58 V_88 ;
struct V_89 * V_16 = V_7 -> V_16 ;
struct V_8 * V_44 ;
unsigned long V_10 ;
int V_11 ;
F_40 ( V_16 -> V_14 , V_7 -> V_38 -> V_90 ) ;
F_40 ( V_16 -> V_14 , V_7 -> V_91 -> V_90 ) ;
V_44 = F_3 ( V_12 , V_13 ) ;
if ( V_44 == NULL ) {
F_4 ( & V_7 -> V_14 , L_1 , V_15 ) ;
return - V_41 ;
}
V_11 = F_7 ( V_16 -> V_14 , F_8 ( V_16 -> V_14 , 0 ) ,
V_17 ,
V_18 ,
0 , 0 ,
V_44 , V_12 ,
100 ) ;
if ( V_11 != V_12 ) {
V_44 -> V_20 = F_37 ( 0x009c ) ;
V_44 -> V_23 = 0x03 ;
V_44 -> V_92 = 0x43 ;
V_44 -> V_22 = 0x4c ;
V_44 -> V_93 = 0x00 ;
V_44 -> V_94 = 0x5b ;
V_44 -> V_95 = 0x00 ;
}
F_10 ( & V_4 -> V_19 , V_10 ) ;
memcpy ( & V_4 -> V_96 , V_44 , V_12 ) ;
V_4 -> V_21 . V_20 = V_44 -> V_20 ;
V_4 -> V_21 . V_23 = V_44 -> V_23 ;
V_4 -> V_21 . V_22 = V_44 -> V_22 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
F_9 ( V_44 ) ;
F_14 ( & V_7 -> V_14 , L_3 , V_15 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_13 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_7 -> V_14 , L_4 ,
V_15 , V_11 ) ;
F_41 ( V_7 ) ;
return V_11 ;
}
if ( V_43 )
F_34 ( V_43 , V_7 , & V_88 ) ;
V_7 -> V_7 . V_97 = 256 ;
return 0 ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
F_42 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
F_14 ( & V_7 -> V_14 , L_6 , V_15 ) ;
F_43 ( & V_4 -> V_5 ) ;
F_43 ( & V_4 -> V_29 ) ;
F_14 ( & V_7 -> V_14 , L_7 , V_15 ) ;
F_44 ( V_7 -> V_38 ) ;
F_44 ( V_7 -> V_91 ) ;
F_44 ( V_7 -> V_28 ) ;
}
static int F_45 ( struct V_42 * V_43 ,
unsigned int V_98 , unsigned int V_99 )
{
struct V_6 * V_7 = V_43 -> V_45 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
T_1 V_22 ;
F_14 ( & V_7 -> V_14 , L_8 ,
V_15 , V_98 , V_99 ) ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_22 = V_4 -> V_21 . V_22 ;
if ( ( V_98 & V_100 ) != 0 )
V_22 |= V_87 ;
if ( ( V_98 & V_101 ) != 0 )
V_22 |= V_86 ;
if ( ( V_99 & V_100 ) != 0 )
V_22 &= ~ V_87 ;
if ( ( V_99 & V_101 ) != 0 )
V_22 &= ~ V_86 ;
if ( V_22 != V_4 -> V_21 . V_22 )
V_4 -> V_21 . V_22 = V_22 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
return 0 ;
}
static int F_46 ( struct V_42 * V_43 )
{
struct V_6 * V_7 = V_43 -> V_45 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
unsigned V_94 ;
unsigned V_11 = 0 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_94 = V_4 -> V_96 . V_94 & V_102 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
if ( ( V_94 & V_103 ) != 0 )
V_11 |= V_100 ;
if ( ( V_94 & V_104 ) != 0 )
V_11 |= V_105 ;
if ( ( V_94 & V_106 ) != 0 )
V_11 |= V_107 ;
if ( ( V_94 & V_108 ) != 0 )
V_11 |= V_101 ;
if ( ( V_94 & V_109 ) != 0 )
V_11 |= V_110 ;
if ( ( V_94 & V_111 ) != 0 )
V_11 |= V_112 ;
F_14 ( & V_7 -> V_14 , L_9 , V_15 , V_11 ) ;
return V_11 ;
}
static int F_47 ( struct V_6 * V_7 , unsigned int V_113 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
unsigned int V_114 , V_96 ;
unsigned int V_115 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_114 = V_4 -> V_96 . V_94 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
while ( 1 ) {
F_48 ( V_7 -> V_116 ,
V_7 -> V_16 -> V_117 ||
V_4 -> V_96 . V_94 != V_114 ) ;
if ( F_49 ( V_118 ) )
return - V_119 ;
if ( V_7 -> V_16 -> V_117 )
return - V_120 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_96 = V_4 -> V_96 . V_94 & V_102 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
V_115 = V_114 ^ V_96 ;
if ( ( ( V_113 & V_121 ) && ( V_115 & V_109 ) ) ||
( ( V_113 & V_107 ) && ( V_115 & V_106 ) ) ||
( ( V_113 & V_112 ) && ( V_115 & V_111 ) ) ||
( ( V_113 & V_105 ) && ( V_115 & V_104 ) ) )
return 0 ;
V_114 = V_96 ;
}
return 0 ;
}
static int F_50 ( struct V_42 * V_43 ,
unsigned int V_122 , unsigned long V_113 )
{
struct V_6 * V_7 = V_43 -> V_45 ;
F_14 ( & V_7 -> V_14 , L_10 , V_15 , V_122 , V_113 ) ;
switch ( V_122 ) {
case V_123 :
F_14 ( & V_7 -> V_14 , L_11 , V_15 ) ;
return F_47 ( V_7 , V_113 ) ;
default:
F_14 ( & V_7 -> V_14 , L_12 , V_15 , V_122 ) ;
break;
}
return - V_124 ;
}
static void F_51 ( struct V_125 * V_125 )
{
struct V_6 * V_7 = V_125 -> V_126 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
int V_26 = 0 , V_127 = 0 , V_128 = 1 ;
int V_96 = V_125 -> V_96 ;
switch ( V_96 ) {
case 0 :
break;
case - V_129 :
case - V_130 :
case - V_131 :
F_14 ( & V_125 -> V_14 -> V_14 , L_13 ,
V_15 , V_96 ) ;
return;
default:
F_14 ( & V_125 -> V_14 -> V_14 , L_14 ,
V_15 , V_96 ) ;
break;
}
if ( V_96 == 0 && V_125 -> V_132 == V_12 ) {
struct V_8 * V_133 = V_125 -> V_39 ;
unsigned long V_10 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( ! V_4 -> V_26 ) {
if ( ! F_11 ( V_133 , V_4 ) ) {
if ( V_133 -> V_95 == 0 ) {
V_4 -> V_26 = 4 ;
V_4 -> V_27 = 0 ;
V_128 = 0 ;
F_14 ( & V_7 -> V_14 , L_15 , V_15 ) ;
F_5 ( & V_4 -> V_5 , 0 ) ;
}
}
} else {
if ( F_11 ( V_133 , V_4 ) ) {
V_4 -> V_26 = 0 ;
} else if ( ! V_4 -> V_27 ) {
V_128 = 0 ;
} else if ( -- V_4 -> V_26 == 0 ) {
if ( V_133 -> V_95 == 0 ) {
V_4 -> V_26 = 4 ;
V_4 -> V_27 = 0 ;
V_128 = 0 ;
F_14 ( & V_7 -> V_14 , L_15 , V_15 ) ;
F_5 ( & V_4 -> V_5 , 0 ) ;
}
}
}
if ( ! V_4 -> V_26 ) {
if ( V_133 -> V_94 != V_4 -> V_96 . V_94 )
F_52 ( & V_7 -> V_116 ) ;
memcpy ( & V_4 -> V_96 , V_133 , V_12 ) ;
}
if ( ! V_4 -> V_26 && V_133 -> V_95 != 0 ) {
V_127 = V_133 -> V_95 ;
V_4 -> V_10 . V_134 = 1 ;
}
V_26 = V_4 -> V_26 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
}
if ( V_127 ) {
int V_11 ;
V_11 = F_15 ( V_7 -> V_91 , V_135 ) ;
if ( V_11 != 0 ) {
V_4 -> V_10 . V_134 = 0 ;
F_4 ( & V_7 -> V_14 , L_16
L_17 , V_15 , V_11 ) ;
} else {
V_128 = 0 ;
}
} else if ( ! V_26 ) {
unsigned long V_10 ;
int V_30 ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
V_30 = F_17 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( V_4 -> V_10 . V_32 == 0 && V_30 != 0 ) {
F_5 ( & V_4 -> V_29 , 0 ) ;
V_128 = 0 ;
}
F_12 ( & V_4 -> V_19 , V_10 ) ;
}
if ( V_128 ) {
int V_11 ;
V_11 = F_15 ( V_125 , V_135 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_125 -> V_14 -> V_14 ,
L_18
L_17 , V_15 , V_11 ) ;
}
}
}
static void F_53 ( struct V_125 * V_125 )
{
struct V_6 * V_7 = V_125 -> V_126 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned char * V_136 = V_125 -> V_39 ;
unsigned long V_10 ;
int V_96 = V_125 -> V_96 ;
int V_11 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_4 -> V_10 . V_134 = 0 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
if ( V_96 != 0 ) {
F_14 ( & V_125 -> V_14 -> V_14 , L_19 , V_15 ) ;
return;
}
if ( V_125 -> V_132 > 0 ) {
F_54 ( & V_7 -> V_7 , V_136 , V_125 -> V_132 ) ;
F_55 ( & V_7 -> V_7 ) ;
}
V_11 = F_15 ( V_7 -> V_28 , V_135 ) ;
if ( V_11 != 0 && V_11 != - V_137 ) {
F_4 ( & V_7 -> V_14 , L_16
L_17 , V_15 , V_11 ) ;
}
}
static void F_56 ( struct V_125 * V_125 )
{
struct V_6 * V_7 = V_125 -> V_126 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
int V_96 = V_125 -> V_96 ;
int V_11 ;
switch ( V_96 ) {
case 0 :
break;
case - V_129 :
case - V_130 :
case - V_131 :
F_14 ( & V_125 -> V_14 -> V_14 , L_13 , V_15 , V_96 ) ;
V_4 -> V_10 . V_32 = 0 ;
return;
default:
F_14 ( & V_125 -> V_14 -> V_14 , L_20 , V_15 , V_96 ) ;
F_14 ( & V_125 -> V_14 -> V_14 , L_21 , V_15 ) ;
V_7 -> V_38 -> V_40 = 1 ;
V_11 = F_15 ( V_7 -> V_38 , V_135 ) ;
if ( V_11 ) {
F_18 ( V_7 , L_16
L_17 , V_15 , V_11 ) ;
} else {
return;
}
}
V_4 -> V_10 . V_32 = 0 ;
F_14 ( & V_7 -> V_14 , L_3 , V_15 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_135 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_7 -> V_14 , L_22
L_17 , V_15 , V_11 ) ;
}
}
