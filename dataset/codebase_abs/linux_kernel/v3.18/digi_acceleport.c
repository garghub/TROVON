static long F_1 (
T_1 * V_1 , long V_2 ,
T_2 * V_3 , unsigned long V_4 )
__releases( V_3 )
{
F_2 ( V_5 ) ;
F_3 ( V_1 , & V_5 , V_6 ) ;
F_4 ( V_3 , V_4 ) ;
V_2 = F_5 ( V_2 ) ;
F_6 ( V_1 , & V_5 ) ;
return V_2 ;
}
static void F_7 ( struct V_7 * V_8 )
{
struct V_9 * V_10 =
F_8 ( V_8 , struct V_9 , V_11 ) ;
struct V_12 * V_13 = V_10 -> V_14 ;
unsigned long V_4 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
F_10 ( & V_13 -> V_13 ) ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
}
static int F_11 ( struct V_12 * V_13 ,
unsigned char * V_16 , int V_17 , int V_18 )
{
int V_19 = 0 ;
int V_20 ;
struct V_12 * V_21 = (struct V_12 * ) ( (struct V_22 * ) ( F_12 ( V_13 -> V_23 ) ) ) -> V_24 ;
struct V_9 * V_25 = F_13 ( V_21 ) ;
unsigned long V_4 = 0 ;
F_14 ( & V_13 -> V_26 ,
L_1 ,
V_25 -> V_27 , V_17 ) ;
F_9 ( & V_25 -> V_15 , V_4 ) ;
while ( V_17 > 0 ) {
while ( V_25 -> V_28 ) {
F_1 (
& V_21 -> V_29 , V_30 ,
& V_25 -> V_15 , V_4 ) ;
if ( V_18 && F_15 ( V_31 ) )
return - V_32 ;
F_9 ( & V_25 -> V_15 , V_4 ) ;
}
V_20 = F_16 ( V_17 , V_21 -> V_33 ) ;
if ( V_20 > 4 )
V_20 &= ~ 3 ;
memcpy ( V_21 -> V_34 -> V_35 , V_16 , V_20 ) ;
V_21 -> V_34 -> V_36 = V_20 ;
V_19 = F_17 ( V_21 -> V_34 , V_37 ) ;
if ( V_19 == 0 ) {
V_25 -> V_28 = 1 ;
V_17 -= V_20 ;
V_16 += V_20 ;
}
}
F_4 ( & V_25 -> V_15 , V_4 ) ;
if ( V_19 )
F_18 ( & V_13 -> V_26 , L_2 ,
V_38 , V_19 ) ;
return V_19 ;
}
static int F_19 ( struct V_12 * V_13 ,
unsigned char * V_16 , int V_17 , unsigned long V_2 )
{
int V_19 = 0 ;
int V_20 ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
unsigned char * V_39 = V_13 -> V_34 -> V_35 ;
unsigned long V_4 = 0 ;
F_14 ( & V_13 -> V_26 , L_3 ,
V_10 -> V_27 , V_17 ) ;
if ( V_2 )
V_2 += V_40 ;
else
V_2 = V_41 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
while ( V_17 > 0 && V_19 == 0 ) {
while ( V_10 -> V_28 &&
F_20 ( V_40 , V_2 ) ) {
F_1 (
& V_13 -> V_29 , V_30 ,
& V_10 -> V_15 , V_4 ) ;
if ( F_15 ( V_31 ) )
return - V_32 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
}
V_20 = F_16 ( V_17 , V_13 -> V_33 - 2 - V_10 -> V_42 ) ;
if ( V_20 > 4 )
V_20 &= ~ 3 ;
if ( V_10 -> V_42 > 0 ) {
V_39 [ 0 ] = V_43 ;
V_39 [ 1 ] = V_10 -> V_42 ;
memcpy ( V_39 + 2 , V_10 -> V_44 ,
V_10 -> V_42 ) ;
memcpy ( V_39 + 2 + V_10 -> V_42 , V_16 , V_20 ) ;
V_13 -> V_34 -> V_36
= V_10 -> V_42 + 2 + V_20 ;
} else {
memcpy ( V_39 , V_16 , V_20 ) ;
V_13 -> V_34 -> V_36 = V_20 ;
}
V_19 = F_17 ( V_13 -> V_34 , V_37 ) ;
if ( V_19 == 0 ) {
V_10 -> V_28 = 1 ;
V_10 -> V_42 = 0 ;
V_17 -= V_20 ;
V_16 += V_20 ;
}
}
F_4 ( & V_10 -> V_15 , V_4 ) ;
if ( V_19 )
F_18 ( & V_13 -> V_26 ,
L_4 ,
V_38 , V_19 , V_10 -> V_27 ) ;
return V_19 ;
}
static int F_21 ( struct V_12 * V_13 ,
unsigned int V_45 , int V_18 )
{
int V_19 ;
struct V_9 * V_46 = F_13 ( V_13 ) ;
struct V_12 * V_21 = (struct V_12 * ) ( (struct V_22 * ) ( F_12 ( V_13 -> V_23 ) ) ) -> V_24 ;
struct V_9 * V_25 = F_13 ( V_21 ) ;
unsigned char * V_39 = V_21 -> V_34 -> V_35 ;
unsigned long V_4 = 0 ;
F_14 ( & V_13 -> V_26 ,
L_5 ,
V_46 -> V_27 , V_45 ) ;
F_9 ( & V_25 -> V_15 , V_4 ) ;
F_22 ( & V_46 -> V_15 ) ;
while ( V_25 -> V_28 ) {
F_23 ( & V_46 -> V_15 ) ;
F_1 (
& V_21 -> V_29 , V_30 ,
& V_25 -> V_15 , V_4 ) ;
if ( V_18 && F_15 ( V_31 ) )
return - V_32 ;
F_9 ( & V_25 -> V_15 , V_4 ) ;
F_22 ( & V_46 -> V_15 ) ;
}
V_39 [ 0 ] = V_47 ;
V_39 [ 1 ] = V_46 -> V_27 ;
V_39 [ 2 ] = ( V_45 & V_48 ) ?
V_49 : V_50 ;
V_39 [ 3 ] = 0 ;
V_39 [ 4 ] = V_51 ;
V_39 [ 5 ] = V_46 -> V_27 ;
V_39 [ 6 ] = ( V_45 & V_52 ) ?
V_53 : V_54 ;
V_39 [ 7 ] = 0 ;
V_21 -> V_34 -> V_36 = 8 ;
V_19 = F_17 ( V_21 -> V_34 , V_37 ) ;
if ( V_19 == 0 ) {
V_25 -> V_28 = 1 ;
V_46 -> V_55 =
( V_46 -> V_55 & ~ ( V_48 | V_52 ) )
| ( V_45 & ( V_48 | V_52 ) ) ;
}
F_23 ( & V_46 -> V_15 ) ;
F_4 ( & V_25 -> V_15 , V_4 ) ;
if ( V_19 )
F_18 ( & V_13 -> V_26 , L_2 ,
V_38 , V_19 ) ;
return V_19 ;
}
static int F_24 ( struct V_12 * V_13 ,
unsigned long V_2 )
{
int V_19 ;
unsigned char V_16 [ 2 ] ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
unsigned long V_4 = 0 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
V_10 -> V_56 = 0 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
V_16 [ 0 ] = V_57 ;
V_16 [ 1 ] = 0 ;
V_2 += V_40 ;
V_19 = F_19 ( V_13 , V_16 , 2 , V_2 - V_40 ) ;
if ( V_19 != 0 )
return V_19 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
while ( F_20 ( V_40 , V_2 ) && ! V_10 -> V_56 ) {
F_1 (
& V_10 -> V_58 , V_30 ,
& V_10 -> V_15 , V_4 ) ;
if ( F_15 ( V_31 ) )
return - V_32 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
}
V_10 -> V_56 = 0 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
return 0 ;
}
static void F_25 ( struct V_59 * V_60 )
{
unsigned long V_4 ;
struct V_12 * V_13 = V_60 -> V_61 ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
V_10 -> V_62 = 1 ;
V_10 -> V_63 = 0 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
}
static void F_26 ( struct V_59 * V_60 )
{
int V_19 = 0 ;
unsigned long V_4 ;
struct V_12 * V_13 = V_60 -> V_61 ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
if ( V_10 -> V_63 )
V_19 = F_17 ( V_13 -> V_64 , V_37 ) ;
V_10 -> V_62 = 0 ;
V_10 -> V_63 = 0 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
if ( V_19 )
F_18 ( & V_13 -> V_26 ,
L_4 ,
V_38 , V_19 , V_10 -> V_27 ) ;
}
static void F_27 ( struct V_59 * V_60 ,
struct V_12 * V_13 , struct V_65 * V_66 )
{
struct V_9 * V_10 = F_13 ( V_13 ) ;
struct V_67 * V_26 = & V_13 -> V_26 ;
unsigned int V_68 = V_60 -> V_69 . V_70 ;
unsigned int V_71 = V_60 -> V_69 . V_72 ;
unsigned int V_73 = V_66 -> V_70 ;
unsigned int V_74 = V_66 -> V_72 ;
unsigned char V_16 [ 32 ] ;
unsigned int V_45 ;
int V_75 , V_19 ;
int V_76 = 0 ;
T_3 V_77 ;
F_14 ( V_26 ,
L_6 ,
V_10 -> V_27 , V_68 , V_73 , V_71 , V_74 ) ;
V_77 = F_28 ( V_60 ) ;
if ( V_77 != F_29 ( V_66 ) ) {
V_75 = - 1 ;
if ( ( V_74 & V_78 ) == V_79 ) {
V_45 = V_48 ;
if ( ! ( V_60 -> V_69 . V_72 & V_80 ) ||
! F_30 ( V_81 , & V_60 -> V_4 ) )
V_45 |= V_52 ;
F_21 ( V_13 , V_45 , 1 ) ;
}
switch ( V_77 ) {
case 0 : F_21 ( V_13 , 0 , 1 ) ; break;
case 50 : V_75 = V_82 ; break;
case 75 : V_75 = V_83 ; break;
case 110 : V_75 = V_84 ; break;
case 150 : V_75 = V_85 ; break;
case 200 : V_75 = V_86 ; break;
case 300 : V_75 = V_87 ; break;
case 600 : V_75 = V_88 ; break;
case 1200 : V_75 = V_89 ; break;
case 1800 : V_75 = V_90 ; break;
case 2400 : V_75 = V_91 ; break;
case 4800 : V_75 = V_92 ; break;
case 9600 : V_75 = V_93 ; break;
case 19200 : V_75 = V_94 ; break;
case 38400 : V_75 = V_95 ; break;
case 57600 : V_75 = V_96 ; break;
case 115200 : V_75 = V_97 ; break;
case 230400 : V_75 = V_98 ; break;
case 460800 : V_75 = V_99 ; break;
default:
V_75 = V_93 ;
V_77 = 9600 ;
break;
}
if ( V_75 != - 1 ) {
V_16 [ V_76 ++ ] = V_100 ;
V_16 [ V_76 ++ ] = V_10 -> V_27 ;
V_16 [ V_76 ++ ] = V_75 ;
V_16 [ V_76 ++ ] = 0 ;
}
}
V_60 -> V_69 . V_72 &= ~ V_101 ;
if ( ( V_71 & ( V_102 | V_103 ) ) != ( V_74 & ( V_102 | V_103 ) ) ) {
if ( V_71 & V_102 ) {
if ( V_71 & V_103 )
V_75 = V_104 ;
else
V_75 = V_105 ;
} else {
V_75 = V_106 ;
}
V_16 [ V_76 ++ ] = V_107 ;
V_16 [ V_76 ++ ] = V_10 -> V_27 ;
V_16 [ V_76 ++ ] = V_75 ;
V_16 [ V_76 ++ ] = 0 ;
}
if ( ( V_71 & V_108 ) != ( V_74 & V_108 ) ) {
V_75 = - 1 ;
switch ( V_71 & V_108 ) {
case V_109 : V_75 = V_110 ; break;
case V_111 : V_75 = V_112 ; break;
case V_113 : V_75 = V_114 ; break;
case V_115 : V_75 = V_116 ; break;
default:
F_14 ( V_26 ,
L_7 ,
( V_71 & V_108 ) ) ;
break;
}
if ( V_75 != - 1 ) {
V_16 [ V_76 ++ ] = V_117 ;
V_16 [ V_76 ++ ] = V_10 -> V_27 ;
V_16 [ V_76 ++ ] = V_75 ;
V_16 [ V_76 ++ ] = 0 ;
}
}
if ( ( V_71 & V_118 ) != ( V_74 & V_118 ) ) {
if ( ( V_71 & V_118 ) )
V_75 = V_119 ;
else
V_75 = V_120 ;
V_16 [ V_76 ++ ] = V_121 ;
V_16 [ V_76 ++ ] = V_10 -> V_27 ;
V_16 [ V_76 ++ ] = V_75 ;
V_16 [ V_76 ++ ] = 0 ;
}
if ( ( V_68 & V_122 ) != ( V_73 & V_122 )
|| ( V_71 & V_80 ) != ( V_74 & V_80 ) ) {
V_75 = 0 ;
if ( V_68 & V_122 )
V_75 |= V_123 ;
else
V_75 &= ~ V_123 ;
if ( V_71 & V_80 ) {
V_75 |= V_124 ;
V_16 [ V_76 ++ ] = V_51 ;
V_16 [ V_76 ++ ] = V_10 -> V_27 ;
V_16 [ V_76 ++ ] = V_53 ;
V_16 [ V_76 ++ ] = 0 ;
} else {
V_75 &= ~ V_124 ;
}
V_16 [ V_76 ++ ] = V_125 ;
V_16 [ V_76 ++ ] = V_10 -> V_27 ;
V_16 [ V_76 ++ ] = V_75 ;
V_16 [ V_76 ++ ] = 0 ;
}
if ( ( V_68 & V_126 ) != ( V_73 & V_126 )
|| ( V_71 & V_80 ) != ( V_74 & V_80 ) ) {
V_75 = 0 ;
if ( V_68 & V_126 )
V_75 |= V_127 ;
else
V_75 &= ~ V_127 ;
if ( V_71 & V_80 ) {
V_75 |= V_128 ;
} else {
V_75 &= ~ V_128 ;
}
V_16 [ V_76 ++ ] = V_129 ;
V_16 [ V_76 ++ ] = V_10 -> V_27 ;
V_16 [ V_76 ++ ] = V_75 ;
V_16 [ V_76 ++ ] = 0 ;
}
if ( ( V_71 & V_130 ) != ( V_74 & V_130 ) ) {
if ( V_71 & V_130 )
V_75 = V_131 ;
else
V_75 = V_132 ;
V_16 [ V_76 ++ ] = V_133 ;
V_16 [ V_76 ++ ] = V_10 -> V_27 ;
V_16 [ V_76 ++ ] = V_75 ;
V_16 [ V_76 ++ ] = 0 ;
}
V_19 = F_11 ( V_13 , V_16 , V_76 , 1 ) ;
if ( V_19 != 0 )
F_14 ( V_26 , L_8 , V_19 ) ;
F_31 ( V_60 , V_77 , V_77 ) ;
}
static void F_32 ( struct V_59 * V_60 , int V_134 )
{
struct V_12 * V_13 = V_60 -> V_61 ;
unsigned char V_16 [ 4 ] ;
V_16 [ 0 ] = V_135 ;
V_16 [ 1 ] = 2 ;
V_16 [ 2 ] = V_134 ? 1 : 0 ;
V_16 [ 3 ] = 0 ;
F_19 ( V_13 , V_16 , 4 , 0 ) ;
}
static int F_33 ( struct V_59 * V_60 )
{
struct V_12 * V_13 = V_60 -> V_61 ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
unsigned int V_136 ;
unsigned long V_4 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
V_136 = V_10 -> V_55 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
return V_136 ;
}
static int F_34 ( struct V_59 * V_60 ,
unsigned int V_137 , unsigned int V_138 )
{
struct V_12 * V_13 = V_60 -> V_61 ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
unsigned int V_136 ;
unsigned long V_4 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
V_136 = ( V_10 -> V_55 & ~ V_138 ) | V_137 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
return F_21 ( V_13 , V_136 , 1 ) ;
}
static int F_35 ( struct V_59 * V_60 , struct V_12 * V_13 ,
const unsigned char * V_16 , int V_17 )
{
int V_19 , V_139 , V_140 ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
unsigned char * V_39 = V_13 -> V_34 -> V_35 ;
unsigned long V_4 = 0 ;
F_14 ( & V_13 -> V_26 ,
L_9 ,
V_10 -> V_27 , V_17 , F_36 () ) ;
V_17 = F_16 ( V_17 , V_13 -> V_33 - 2 ) ;
V_17 = F_16 ( 64 , V_17 ) ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
if ( V_10 -> V_28 ) {
if ( V_17 == 1 && V_10 -> V_42 < V_141 ) {
V_10 -> V_44 [ V_10 -> V_42 ++ ] = * V_16 ;
V_140 = 1 ;
} else {
V_140 = 0 ;
}
F_4 ( & V_10 -> V_15 , V_4 ) ;
return V_140 ;
}
V_140 = F_16 ( V_17 , V_13 -> V_33 - 2 - V_10 -> V_42 ) ;
V_139 = V_140 + V_10 -> V_42 ;
if ( V_139 == 0 ) {
F_4 ( & V_10 -> V_15 , V_4 ) ;
return 0 ;
}
V_13 -> V_34 -> V_36 = V_139 + 2 ;
* V_39 ++ = V_43 ;
* V_39 ++ = V_139 ;
memcpy ( V_39 , V_10 -> V_44 , V_10 -> V_42 ) ;
V_39 += V_10 -> V_42 ;
memcpy ( V_39 , V_16 , V_140 ) ;
V_19 = F_17 ( V_13 -> V_34 , V_37 ) ;
if ( V_19 == 0 ) {
V_10 -> V_28 = 1 ;
V_19 = V_140 ;
V_10 -> V_42 = 0 ;
}
F_4 ( & V_10 -> V_15 , V_4 ) ;
if ( V_19 < 0 )
F_37 ( V_13 ,
L_4 ,
V_38 , V_19 , V_10 -> V_27 ) ;
F_14 ( & V_13 -> V_26 , L_10 , V_19 ) ;
return V_19 ;
}
static void F_38 ( struct V_142 * V_142 )
{
struct V_12 * V_13 = V_142 -> V_143 ;
struct V_144 * V_23 ;
struct V_9 * V_10 ;
struct V_22 * V_145 ;
int V_19 = 0 ;
int V_146 = V_142 -> V_146 ;
if ( V_13 == NULL || ( V_10 = F_13 ( V_13 ) ) == NULL ) {
F_39 ( L_11 ,
V_38 , V_146 ) ;
return;
}
V_23 = V_13 -> V_23 ;
if ( V_23 == NULL || ( V_145 = F_12 ( V_23 ) ) == NULL ) {
F_18 ( & V_13 -> V_26 ,
L_12 ,
V_38 , V_146 ) ;
return;
}
if ( V_10 -> V_27 == V_145 -> V_147 ) {
F_14 ( & V_13 -> V_26 , L_13 ) ;
F_22 ( & V_10 -> V_15 ) ;
V_10 -> V_28 = 0 ;
F_40 ( & V_13 -> V_29 ) ;
F_23 ( & V_10 -> V_15 ) ;
return;
}
F_22 ( & V_10 -> V_15 ) ;
V_10 -> V_28 = 0 ;
if ( V_10 -> V_42 > 0 ) {
* ( ( unsigned char * ) ( V_13 -> V_34 -> V_35 ) )
= ( unsigned char ) V_43 ;
* ( ( unsigned char * ) ( V_13 -> V_34 -> V_35 ) + 1 )
= ( unsigned char ) V_10 -> V_42 ;
V_13 -> V_34 -> V_36 =
V_10 -> V_42 + 2 ;
memcpy ( V_13 -> V_34 -> V_35 + 2 , V_10 -> V_44 ,
V_10 -> V_42 ) ;
V_19 = F_17 ( V_13 -> V_34 , V_37 ) ;
if ( V_19 == 0 ) {
V_10 -> V_28 = 1 ;
V_10 -> V_42 = 0 ;
}
}
F_10 ( & V_13 -> V_13 ) ;
F_41 ( & V_10 -> V_11 ) ;
F_23 ( & V_10 -> V_15 ) ;
if ( V_19 && V_19 != - V_148 )
F_37 ( V_13 ,
L_4 ,
V_38 , V_19 , V_10 -> V_27 ) ;
}
static int F_42 ( struct V_59 * V_60 )
{
struct V_12 * V_13 = V_60 -> V_61 ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
int V_149 ;
unsigned long V_4 = 0 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
if ( V_10 -> V_28 )
V_149 = 0 ;
else
V_149 = V_13 -> V_33 - 2 - V_10 -> V_42 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
F_14 ( & V_13 -> V_26 , L_14 , V_10 -> V_27 , V_149 ) ;
return V_149 ;
}
static int F_43 ( struct V_59 * V_60 )
{
struct V_12 * V_13 = V_60 -> V_61 ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
if ( V_10 -> V_28 ) {
F_14 ( & V_13 -> V_26 , L_15 ,
V_10 -> V_27 , V_13 -> V_33 - 2 ) ;
return 256 ;
} else {
F_14 ( & V_13 -> V_26 , L_15 ,
V_10 -> V_27 , V_10 -> V_42 ) ;
return V_10 -> V_42 ;
}
}
static void F_44 ( struct V_12 * V_13 , int V_150 )
{
F_21 ( V_13 , V_150 * ( V_48 | V_52 ) , 1 ) ;
}
static int F_45 ( struct V_59 * V_60 , struct V_12 * V_13 )
{
int V_19 ;
unsigned char V_16 [ 32 ] ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
struct V_65 V_151 ;
if ( F_46 ( V_13 -> V_23 ) != 0 )
return - V_152 ;
V_16 [ 0 ] = V_153 ;
V_16 [ 1 ] = V_10 -> V_27 ;
V_16 [ 2 ] = V_131 ;
V_16 [ 3 ] = 0 ;
V_16 [ 4 ] = V_154 ;
V_16 [ 5 ] = V_10 -> V_27 ;
V_16 [ 6 ] = V_155 | V_156 ;
V_16 [ 7 ] = 0 ;
V_19 = F_11 ( V_13 , V_16 , 8 , 1 ) ;
if ( V_19 != 0 )
F_14 ( & V_13 -> V_26 , L_16 , V_19 ) ;
if ( V_60 ) {
V_151 . V_72 = ~ V_60 -> V_69 . V_72 ;
V_151 . V_70 = ~ V_60 -> V_69 . V_70 ;
F_27 ( V_60 , V_13 , & V_151 ) ;
}
return 0 ;
}
static void F_47 ( struct V_12 * V_13 )
{
F_2 ( V_5 ) ;
int V_19 ;
unsigned char V_16 [ 32 ] ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
F_48 ( & V_13 -> V_23 -> V_157 ) ;
if ( V_13 -> V_23 -> V_158 )
goto exit;
F_24 ( V_13 , V_159 ) ;
V_16 [ 0 ] = V_125 ;
V_16 [ 1 ] = V_10 -> V_27 ;
V_16 [ 2 ] = V_132 ;
V_16 [ 3 ] = 0 ;
V_16 [ 4 ] = V_129 ;
V_16 [ 5 ] = V_10 -> V_27 ;
V_16 [ 6 ] = V_132 ;
V_16 [ 7 ] = 0 ;
V_16 [ 8 ] = V_153 ;
V_16 [ 9 ] = V_10 -> V_27 ;
V_16 [ 10 ] = V_132 ;
V_16 [ 11 ] = 0 ;
V_16 [ 12 ] = V_133 ;
V_16 [ 13 ] = V_10 -> V_27 ;
V_16 [ 14 ] = V_132 ;
V_16 [ 15 ] = 0 ;
V_16 [ 16 ] = V_154 ;
V_16 [ 17 ] = V_10 -> V_27 ;
V_16 [ 18 ] = V_155 | V_156 ;
V_16 [ 19 ] = 0 ;
V_19 = F_11 ( V_13 , V_16 , 20 , 0 ) ;
if ( V_19 != 0 )
F_14 ( & V_13 -> V_26 , L_17 ,
V_19 ) ;
F_3 ( & V_10 -> V_160 , & V_5 ,
V_6 ) ;
F_5 ( V_159 ) ;
F_6 ( & V_10 -> V_160 , & V_5 ) ;
F_49 ( V_13 -> V_34 ) ;
exit:
F_50 ( & V_10 -> V_15 ) ;
V_10 -> V_28 = 0 ;
F_40 ( & V_10 -> V_161 ) ;
F_51 ( & V_10 -> V_15 ) ;
F_52 ( & V_13 -> V_23 -> V_157 ) ;
}
static int F_46 ( struct V_144 * V_23 )
{
int V_76 , V_19 = 0 ;
struct V_22 * V_145 = F_12 ( V_23 ) ;
struct V_12 * V_13 ;
F_22 ( & V_145 -> V_162 ) ;
if ( V_145 -> V_163 ) {
F_23 ( & V_145 -> V_162 ) ;
return 0 ;
}
V_145 -> V_163 = 1 ;
F_23 ( & V_145 -> V_162 ) ;
for ( V_76 = 0 ; V_76 < V_23 -> type -> V_164 + 1 ; V_76 ++ ) {
V_13 = V_23 -> V_13 [ V_76 ] ;
V_19 = F_17 ( V_13 -> V_64 , V_165 ) ;
if ( V_19 != 0 ) {
F_18 ( & V_13 -> V_26 ,
L_4 ,
V_38 , V_19 , V_76 ) ;
break;
}
}
return V_19 ;
}
static int F_53 ( struct V_12 * V_13 , unsigned V_166 )
{
struct V_9 * V_10 ;
V_10 = F_54 ( sizeof( * V_10 ) , V_165 ) ;
if ( ! V_10 )
return - V_167 ;
F_55 ( & V_10 -> V_15 ) ;
V_10 -> V_27 = V_166 ;
F_56 ( & V_10 -> V_58 ) ;
F_56 ( & V_10 -> V_160 ) ;
F_56 ( & V_10 -> V_161 ) ;
F_57 ( & V_10 -> V_11 , F_7 ) ;
V_10 -> V_14 = V_13 ;
F_56 ( & V_13 -> V_29 ) ;
F_58 ( V_13 , V_10 ) ;
return 0 ;
}
static int F_59 ( struct V_144 * V_23 )
{
struct V_22 * V_145 ;
int V_19 ;
V_145 = F_54 ( sizeof( * V_145 ) , V_165 ) ;
if ( ! V_145 )
return - V_167 ;
F_55 ( & V_145 -> V_162 ) ;
V_145 -> V_147 = V_23 -> type -> V_164 ;
V_145 -> V_24 = V_23 -> V_13 [ V_145 -> V_147 ] ;
V_19 = F_53 ( V_145 -> V_24 ,
V_145 -> V_147 ) ;
if ( V_19 ) {
F_60 ( V_145 ) ;
return V_19 ;
}
F_61 ( V_23 , V_145 ) ;
return 0 ;
}
static void F_62 ( struct V_144 * V_23 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_23 -> type -> V_164 + 1 ; V_76 ++ ) {
F_49 ( V_23 -> V_13 [ V_76 ] -> V_64 ) ;
F_49 ( V_23 -> V_13 [ V_76 ] -> V_34 ) ;
}
}
static void F_63 ( struct V_144 * V_23 )
{
struct V_22 * V_145 ;
struct V_9 * V_10 ;
V_145 = F_12 ( V_23 ) ;
V_10 = F_13 ( V_145 -> V_24 ) ;
F_60 ( V_10 ) ;
F_60 ( V_145 ) ;
}
static int F_64 ( struct V_12 * V_13 )
{
return F_53 ( V_13 , V_13 -> V_168 ) ;
}
static int F_65 ( struct V_12 * V_13 )
{
struct V_9 * V_10 ;
V_10 = F_13 ( V_13 ) ;
F_60 ( V_10 ) ;
return 0 ;
}
static void F_66 ( struct V_142 * V_142 )
{
struct V_12 * V_13 = V_142 -> V_143 ;
struct V_9 * V_10 ;
struct V_22 * V_145 ;
int V_19 ;
int V_146 = V_142 -> V_146 ;
if ( V_13 == NULL )
return;
V_10 = F_13 ( V_13 ) ;
if ( V_10 == NULL ) {
F_18 ( & V_13 -> V_26 , L_18 ,
V_38 , V_146 ) ;
return;
}
if ( V_13 -> V_23 == NULL ||
( V_145 = F_12 ( V_13 -> V_23 ) ) == NULL ) {
F_18 ( & V_13 -> V_26 , L_19
L_20 , V_38 , V_146 ) ;
return;
}
if ( V_146 ) {
F_18 ( & V_13 -> V_26 ,
L_21 ,
V_38 , V_146 , V_10 -> V_27 ) ;
return;
}
if ( V_10 -> V_27 == V_145 -> V_147 ) {
if ( F_67 ( V_142 ) != 0 )
return;
} else {
if ( F_68 ( V_142 ) != 0 )
return;
}
V_19 = F_17 ( V_142 , V_37 ) ;
if ( V_19 != 0 && V_19 != - V_148 ) {
F_18 ( & V_13 -> V_26 ,
L_22 ,
V_38 , V_19 , V_10 -> V_27 ) ;
}
}
static int F_68 ( struct V_142 * V_142 )
{
struct V_12 * V_13 = V_142 -> V_143 ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
int V_169 = ( ( unsigned char * ) V_142 -> V_35 ) [ 0 ] ;
int V_20 = ( ( unsigned char * ) V_142 -> V_35 ) [ 1 ] ;
int V_170 = ( ( unsigned char * ) V_142 -> V_35 ) [ 2 ] ;
unsigned char * V_39 = ( ( unsigned char * ) V_142 -> V_35 ) + 3 ;
int V_171 , V_172 ;
int V_146 = V_142 -> V_146 ;
if ( V_142 -> V_146 == - V_173 )
return 0 ;
if ( V_142 -> V_174 != V_20 + 2 ) {
F_18 ( & V_13 -> V_26 , L_23
L_24
L_25 , V_38 , V_146 ,
V_10 -> V_27 , V_169 , V_20 , V_142 -> V_174 ,
V_170 ) ;
return - 1 ;
}
F_22 ( & V_10 -> V_15 ) ;
V_172 = V_10 -> V_62 ;
if ( V_172 )
V_10 -> V_63 = 1 ;
if ( V_169 == V_175 ) {
V_171 = 0 ;
if ( V_170 & V_176 )
F_69 ( & V_13 -> V_13 , 0 , V_177 ) ;
if ( V_170 & V_178 )
V_171 = V_179 ;
else if ( V_170 & V_180 )
V_171 = V_181 ;
else if ( V_170 & V_182 )
V_171 = V_183 ;
-- V_20 ;
if ( V_20 > 0 ) {
F_70 ( & V_13 -> V_13 , V_39 ,
V_171 , V_20 ) ;
F_71 ( & V_13 -> V_13 ) ;
}
}
F_23 ( & V_10 -> V_15 ) ;
if ( V_169 == V_184 )
F_14 ( & V_13 -> V_26 , L_26 , V_38 ) ;
else if ( V_169 != V_175 )
F_14 ( & V_13 -> V_26 , L_27 , V_38 , V_169 ) ;
return V_172 ? 1 : 0 ;
}
static int F_67 ( struct V_142 * V_142 )
{
struct V_12 * V_13 = V_142 -> V_143 ;
struct V_144 * V_23 = V_13 -> V_23 ;
struct V_59 * V_60 ;
struct V_9 * V_10 = F_13 ( V_13 ) ;
int V_169 , line , V_146 , V_136 ;
int V_76 ;
unsigned int V_185 ;
for ( V_76 = 0 ; V_76 < V_142 -> V_174 - 3 ; ) {
V_169 = ( ( unsigned char * ) V_142 -> V_35 ) [ V_76 ++ ] ;
line = ( ( unsigned char * ) V_142 -> V_35 ) [ V_76 ++ ] ;
V_146 = ( ( unsigned char * ) V_142 -> V_35 ) [ V_76 ++ ] ;
V_136 = ( ( unsigned char * ) V_142 -> V_35 ) [ V_76 ++ ] ;
F_14 ( & V_13 -> V_26 , L_28 ,
V_169 , line , V_146 , V_136 ) ;
if ( V_146 != 0 || line >= V_23 -> type -> V_164 )
continue;
V_13 = V_23 -> V_13 [ line ] ;
V_10 = F_13 ( V_13 ) ;
if ( V_10 == NULL )
return - 1 ;
V_60 = F_72 ( & V_13 -> V_13 ) ;
V_185 = 0 ;
if ( V_60 )
V_185 = V_60 -> V_69 . V_72 & V_80 ;
if ( V_60 && V_169 == V_153 ) {
F_22 ( & V_10 -> V_15 ) ;
if ( V_136 & V_186 ) {
V_10 -> V_55 |= V_187 ;
if ( V_185 )
F_10 ( & V_13 -> V_13 ) ;
} else {
V_10 -> V_55 &= ~ V_187 ;
}
if ( V_136 & V_188 )
V_10 -> V_55 |= V_189 ;
else
V_10 -> V_55 &= ~ V_189 ;
if ( V_136 & V_190 )
V_10 -> V_55 |= V_191 ;
else
V_10 -> V_55 &= ~ V_191 ;
if ( V_136 & V_192 )
V_10 -> V_55 |= V_193 ;
else
V_10 -> V_55 &= ~ V_193 ;
F_23 ( & V_10 -> V_15 ) ;
} else if ( V_169 == V_57 ) {
F_22 ( & V_10 -> V_15 ) ;
V_10 -> V_56 = 1 ;
F_40 ( & V_10 -> V_58 ) ;
F_23 ( & V_10 -> V_15 ) ;
} else if ( V_169 == V_154 ) {
F_40 ( & V_10 -> V_160 ) ;
}
F_73 ( V_60 ) ;
}
return 0 ;
}
