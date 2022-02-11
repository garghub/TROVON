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
F_24 ( & V_4 -> V_42 ) ;
V_4 -> V_7 = V_7 ;
F_25 ( & V_4 -> V_5 , F_1 ) ;
F_25 ( & V_4 -> V_29 , F_16 ) ;
F_26 ( V_7 , V_4 ) ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_3 * V_4 ;
V_4 = F_28 ( V_7 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_29 ( struct V_43 * V_44 , struct V_6 * V_7 ,
const unsigned char * V_45 , int V_30 )
{
if ( ! V_30 )
return V_30 ;
V_30 = F_30 ( & V_7 -> V_33 , V_45 , V_30 , & V_7 -> V_19 ) ;
return V_30 ;
}
static int F_31 ( struct V_43 * V_44 )
{
struct V_6 * V_7 = V_44 -> V_46 ;
int V_47 = 0 ;
unsigned long V_10 ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
V_47 = F_32 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
return V_47 ;
}
static int F_33 ( struct V_43 * V_44 )
{
struct V_6 * V_7 = V_44 -> V_46 ;
int V_48 = 0 ;
unsigned long V_10 ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
V_48 = F_17 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
return V_48 ;
}
static void F_34 ( struct V_43 * V_44 )
{
V_44 -> V_49 = V_50 ;
V_44 -> V_49 . V_51 = V_52 | V_53 | V_54 | V_55 | V_56 ;
V_44 -> V_49 . V_57 = 38400 ;
V_44 -> V_49 . V_58 = 38400 ;
}
static void F_35 ( struct V_43 * V_44 ,
struct V_6 * V_7 , struct V_59 * V_60 )
{
struct V_3 * V_4 = F_28 ( V_7 ) ;
unsigned long V_10 ;
unsigned int V_61 ;
T_1 V_23 , V_22 ;
T_2 V_20 ;
int V_62 ;
if ( ! V_44 )
return;
V_61 = V_44 -> V_49 . V_51 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_20 = V_4 -> V_21 . V_20 ;
V_23 = V_4 -> V_21 . V_23 ;
V_22 = V_4 -> V_21 . V_22 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
V_23 &= ~ V_63 ;
switch ( V_61 & V_64 ) {
case V_65 :
V_23 |= V_66 ;
break;
case V_67 :
V_23 |= V_68 ;
break;
case V_69 :
V_23 |= V_70 ;
break;
default:
case V_53 :
V_23 |= V_71 ;
break;
}
V_62 = F_36 ( V_44 ) ;
if ( V_62 == 0 ) {
V_20 = 0 ;
} else {
int V_72 ;
int V_73 ;
V_62 = F_37 ( V_62 , V_74 ) ;
V_73 = ( 96000000 + 8 * V_62 ) / ( 16 * V_62 ) ;
V_72 = 96000000 / ( 16 * V_73 ) ;
V_20 = F_38 ( V_73 ) ;
F_39 ( V_44 , V_72 , V_72 ) ;
}
V_23 &= ~ V_75 ;
if ( ( V_61 & V_76 ) != 0 )
V_23 |= V_77 ;
else
V_23 |= V_78 ;
V_23 &= ~ V_79 ;
if ( ( V_61 & V_80 ) != 0 ) {
if ( ( V_61 & V_81 ) != 0 )
V_23 |= V_82 ;
else
V_23 |= V_83 ;
} else {
V_23 |= V_84 ;
}
V_22 &= ~ V_85 ;
if ( ( V_61 & V_86 ) != 0 )
V_22 |= ( V_87 | V_88 ) ;
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
static int F_40 ( struct V_43 * V_44 , struct V_6 * V_7 )
{
struct V_3 * V_4 = F_28 ( V_7 ) ;
struct V_59 V_89 ;
struct V_90 * V_16 = V_7 -> V_16 ;
struct V_8 * V_45 ;
unsigned long V_10 ;
int V_11 ;
F_41 ( V_16 -> V_14 , V_7 -> V_38 -> V_91 ) ;
F_41 ( V_16 -> V_14 , V_7 -> V_92 -> V_91 ) ;
V_45 = F_3 ( V_12 , V_13 ) ;
if ( V_45 == NULL ) {
F_4 ( & V_7 -> V_14 , L_1 , V_15 ) ;
return - V_41 ;
}
V_11 = F_7 ( V_16 -> V_14 , F_8 ( V_16 -> V_14 , 0 ) ,
V_17 ,
V_18 ,
0 , 0 ,
V_45 , V_12 ,
100 ) ;
if ( V_11 != V_12 ) {
V_45 -> V_20 = F_38 ( 0x009c ) ;
V_45 -> V_23 = 0x03 ;
V_45 -> V_93 = 0x43 ;
V_45 -> V_22 = 0x4c ;
V_45 -> V_94 = 0x00 ;
V_45 -> V_95 = 0x5b ;
V_45 -> V_96 = 0x00 ;
}
F_10 ( & V_4 -> V_19 , V_10 ) ;
memcpy ( & V_4 -> V_97 , V_45 , V_12 ) ;
V_4 -> V_21 . V_20 = V_45 -> V_20 ;
V_4 -> V_21 . V_23 = V_45 -> V_23 ;
V_4 -> V_21 . V_22 = V_45 -> V_22 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
F_9 ( V_45 ) ;
F_14 ( & V_7 -> V_14 , L_3 , V_15 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_13 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_7 -> V_14 , L_4 ,
V_15 , V_11 ) ;
F_42 ( V_7 ) ;
return V_11 ;
}
if ( V_44 )
F_35 ( V_44 , V_7 , & V_89 ) ;
V_7 -> V_7 . V_98 = 256 ;
return 0 ;
}
static void F_42 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_28 ( V_7 ) ;
unsigned long V_10 ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
F_43 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
F_14 ( & V_7 -> V_14 , L_6 , V_15 ) ;
F_44 ( & V_4 -> V_5 ) ;
F_44 ( & V_4 -> V_29 ) ;
F_14 ( & V_7 -> V_14 , L_7 , V_15 ) ;
F_45 ( V_7 -> V_38 ) ;
F_45 ( V_7 -> V_92 ) ;
F_45 ( V_7 -> V_28 ) ;
}
static int F_46 ( struct V_43 * V_44 ,
unsigned int V_99 , unsigned int V_100 )
{
struct V_6 * V_7 = V_44 -> V_46 ;
struct V_3 * V_4 = F_28 ( V_7 ) ;
unsigned long V_10 ;
T_1 V_22 ;
F_14 ( & V_7 -> V_14 , L_8 ,
V_15 , V_99 , V_100 ) ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_22 = V_4 -> V_21 . V_22 ;
if ( ( V_99 & V_101 ) != 0 )
V_22 |= V_88 ;
if ( ( V_99 & V_102 ) != 0 )
V_22 |= V_87 ;
if ( ( V_100 & V_101 ) != 0 )
V_22 &= ~ V_88 ;
if ( ( V_100 & V_102 ) != 0 )
V_22 &= ~ V_87 ;
if ( V_22 != V_4 -> V_21 . V_22 )
V_4 -> V_21 . V_22 = V_22 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
return 0 ;
}
static int F_47 ( struct V_43 * V_44 )
{
struct V_6 * V_7 = V_44 -> V_46 ;
struct V_3 * V_4 = F_28 ( V_7 ) ;
unsigned long V_10 ;
unsigned V_95 ;
unsigned V_11 = 0 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_95 = V_4 -> V_97 . V_95 & V_103 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
if ( ( V_95 & V_104 ) != 0 )
V_11 |= V_101 ;
if ( ( V_95 & V_105 ) != 0 )
V_11 |= V_106 ;
if ( ( V_95 & V_107 ) != 0 )
V_11 |= V_108 ;
if ( ( V_95 & V_109 ) != 0 )
V_11 |= V_102 ;
if ( ( V_95 & V_110 ) != 0 )
V_11 |= V_111 ;
if ( ( V_95 & V_112 ) != 0 )
V_11 |= V_113 ;
F_14 ( & V_7 -> V_14 , L_9 , V_15 , V_11 ) ;
return V_11 ;
}
static int F_48 ( struct V_6 * V_7 , unsigned int V_114 )
{
struct V_3 * V_4 = F_28 ( V_7 ) ;
unsigned long V_10 ;
unsigned int V_115 , V_97 ;
unsigned int V_116 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_115 = V_4 -> V_97 . V_95 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
while ( 1 ) {
F_49 ( V_4 -> V_42 ,
V_4 -> V_97 . V_95 != V_115 ) ;
if ( F_50 ( V_117 ) )
return - V_118 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_97 = V_4 -> V_97 . V_95 & V_103 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
V_116 = V_115 ^ V_97 ;
if ( ( ( V_114 & V_119 ) && ( V_116 & V_110 ) ) ||
( ( V_114 & V_108 ) && ( V_116 & V_107 ) ) ||
( ( V_114 & V_113 ) && ( V_116 & V_112 ) ) ||
( ( V_114 & V_106 ) && ( V_116 & V_105 ) ) )
return 0 ;
V_115 = V_97 ;
}
return 0 ;
}
static int F_51 ( struct V_43 * V_44 ,
unsigned int V_120 , unsigned long V_114 )
{
struct V_6 * V_7 = V_44 -> V_46 ;
F_14 ( & V_7 -> V_14 , L_10 , V_15 , V_120 , V_114 ) ;
switch ( V_120 ) {
case V_121 :
F_14 ( & V_7 -> V_14 , L_11 , V_15 ) ;
return F_48 ( V_7 , V_114 ) ;
default:
F_14 ( & V_7 -> V_14 , L_12 , V_15 , V_120 ) ;
break;
}
return - V_122 ;
}
static void F_52 ( struct V_123 * V_123 )
{
struct V_6 * V_7 = V_123 -> V_124 ;
struct V_3 * V_4 = F_28 ( V_7 ) ;
int V_26 = 0 , V_125 = 0 , V_126 = 1 ;
int V_97 = V_123 -> V_97 ;
switch ( V_97 ) {
case 0 :
break;
case - V_127 :
case - V_128 :
case - V_129 :
F_14 ( & V_123 -> V_14 -> V_14 , L_13 ,
V_15 , V_97 ) ;
return;
default:
F_14 ( & V_123 -> V_14 -> V_14 , L_14 ,
V_15 , V_97 ) ;
break;
}
if ( V_97 == 0 && V_123 -> V_130 == V_12 ) {
struct V_8 * V_131 = V_123 -> V_39 ;
unsigned long V_10 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( ! V_4 -> V_26 ) {
if ( ! F_11 ( V_131 , V_4 ) ) {
if ( V_131 -> V_96 == 0 ) {
V_4 -> V_26 = 4 ;
V_4 -> V_27 = 0 ;
V_126 = 0 ;
F_14 ( & V_7 -> V_14 , L_15 , V_15 ) ;
F_5 ( & V_4 -> V_5 , 0 ) ;
}
}
} else {
if ( F_11 ( V_131 , V_4 ) ) {
V_4 -> V_26 = 0 ;
} else if ( ! V_4 -> V_27 ) {
V_126 = 0 ;
} else if ( -- V_4 -> V_26 == 0 ) {
if ( V_131 -> V_96 == 0 ) {
V_4 -> V_26 = 4 ;
V_4 -> V_27 = 0 ;
V_126 = 0 ;
F_14 ( & V_7 -> V_14 , L_15 , V_15 ) ;
F_5 ( & V_4 -> V_5 , 0 ) ;
}
}
}
if ( ! V_4 -> V_26 ) {
if ( V_131 -> V_95 != V_4 -> V_97 . V_95 )
F_53 ( & V_4 -> V_42 ) ;
memcpy ( & V_4 -> V_97 , V_131 , V_12 ) ;
}
if ( ! V_4 -> V_26 && V_131 -> V_96 != 0 ) {
V_125 = V_131 -> V_96 ;
V_4 -> V_10 . V_132 = 1 ;
}
V_26 = V_4 -> V_26 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
}
if ( V_125 ) {
int V_11 ;
V_11 = F_15 ( V_7 -> V_92 , V_133 ) ;
if ( V_11 != 0 ) {
V_4 -> V_10 . V_132 = 0 ;
F_4 ( & V_7 -> V_14 , L_16
L_17 , V_15 , V_11 ) ;
} else {
V_126 = 0 ;
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
V_126 = 0 ;
}
F_12 ( & V_4 -> V_19 , V_10 ) ;
}
if ( V_126 ) {
int V_11 ;
V_11 = F_15 ( V_123 , V_133 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_123 -> V_14 -> V_14 ,
L_18
L_17 , V_15 , V_11 ) ;
}
}
}
static void F_54 ( struct V_123 * V_123 )
{
struct V_6 * V_7 = V_123 -> V_124 ;
struct V_3 * V_4 = F_28 ( V_7 ) ;
struct V_43 * V_44 ;
unsigned char * V_134 = V_123 -> V_39 ;
unsigned long V_10 ;
int V_97 = V_123 -> V_97 ;
int V_11 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_4 -> V_10 . V_132 = 0 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
if ( V_97 != 0 ) {
F_14 ( & V_123 -> V_14 -> V_14 , L_19 , V_15 ) ;
return;
}
V_44 = F_55 ( & V_7 -> V_7 ) ;
if ( V_44 != NULL && V_123 -> V_130 > 0 ) {
F_56 ( V_44 , V_134 , V_123 -> V_130 ) ;
F_57 ( V_44 ) ;
}
F_58 ( V_44 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_133 ) ;
if ( V_11 != 0 && V_11 != - V_135 ) {
F_4 ( & V_7 -> V_14 , L_16
L_17 , V_15 , V_11 ) ;
}
}
static void F_59 ( struct V_123 * V_123 )
{
struct V_6 * V_7 = V_123 -> V_124 ;
struct V_3 * V_4 = F_28 ( V_7 ) ;
int V_97 = V_123 -> V_97 ;
int V_11 ;
switch ( V_97 ) {
case 0 :
break;
case - V_127 :
case - V_128 :
case - V_129 :
F_14 ( & V_123 -> V_14 -> V_14 , L_13 , V_15 , V_97 ) ;
V_4 -> V_10 . V_32 = 0 ;
return;
default:
F_14 ( & V_123 -> V_14 -> V_14 , L_20 , V_15 , V_97 ) ;
F_14 ( & V_123 -> V_14 -> V_14 , L_21 , V_15 ) ;
V_7 -> V_38 -> V_40 = 1 ;
V_11 = F_15 ( V_7 -> V_38 , V_133 ) ;
if ( V_11 ) {
F_18 ( V_7 , L_16
L_17 , V_15 , V_11 ) ;
} else {
return;
}
}
V_4 -> V_10 . V_32 = 0 ;
F_14 ( & V_7 -> V_14 , L_3 , V_15 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_133 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_7 -> V_14 , L_22
L_17 , V_15 , V_11 ) ;
}
}
