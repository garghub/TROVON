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
F_10 ( V_13 ) ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
}
static void F_10 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_11 ( & V_13 -> V_13 ) ;
if ( V_17 ) {
F_12 ( V_17 ) ;
F_13 ( V_17 ) ;
}
}
static int F_14 ( struct V_12 * V_13 ,
unsigned char * V_18 , int V_19 , int V_20 )
{
int V_21 = 0 ;
int V_22 ;
struct V_12 * V_23 = (struct V_12 * ) ( (struct V_24 * ) ( F_15 ( V_13 -> V_25 ) ) ) -> V_26 ;
struct V_9 * V_27 = F_16 ( V_23 ) ;
unsigned long V_4 = 0 ;
F_17 ( & V_13 -> V_28 ,
L_1 ,
V_27 -> V_29 , V_19 ) ;
F_9 ( & V_27 -> V_15 , V_4 ) ;
while ( V_19 > 0 ) {
while ( V_27 -> V_30 ) {
F_1 (
& V_23 -> V_31 , V_32 ,
& V_27 -> V_15 , V_4 ) ;
if ( V_20 && F_18 ( V_33 ) )
return - V_34 ;
F_9 ( & V_27 -> V_15 , V_4 ) ;
}
V_22 = F_19 ( V_19 , V_23 -> V_35 ) ;
if ( V_22 > 4 )
V_22 &= ~ 3 ;
memcpy ( V_23 -> V_36 -> V_37 , V_18 , V_22 ) ;
V_23 -> V_36 -> V_38 = V_22 ;
V_21 = F_20 ( V_23 -> V_36 , V_39 ) ;
if ( V_21 == 0 ) {
V_27 -> V_30 = 1 ;
V_19 -= V_22 ;
V_18 += V_22 ;
}
}
F_4 ( & V_27 -> V_15 , V_4 ) ;
if ( V_21 )
F_21 ( & V_13 -> V_28 , L_2 ,
V_40 , V_21 ) ;
return V_21 ;
}
static int F_22 ( struct V_12 * V_13 ,
unsigned char * V_18 , int V_19 , unsigned long V_2 )
{
int V_21 = 0 ;
int V_22 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
unsigned char * V_41 = V_13 -> V_36 -> V_37 ;
unsigned long V_4 = 0 ;
F_17 ( & V_13 -> V_28 , L_3 ,
V_10 -> V_29 , V_19 ) ;
if ( V_2 )
V_2 += V_42 ;
else
V_2 = V_43 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
while ( V_19 > 0 && V_21 == 0 ) {
while ( V_10 -> V_30 &&
F_23 ( V_42 , V_2 ) ) {
F_1 (
& V_13 -> V_31 , V_32 ,
& V_10 -> V_15 , V_4 ) ;
if ( F_18 ( V_33 ) )
return - V_34 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
}
V_22 = F_19 ( V_19 , V_13 -> V_35 - 2 - V_10 -> V_44 ) ;
if ( V_22 > 4 )
V_22 &= ~ 3 ;
if ( V_10 -> V_44 > 0 ) {
V_41 [ 0 ] = V_45 ;
V_41 [ 1 ] = V_10 -> V_44 ;
memcpy ( V_41 + 2 , V_10 -> V_46 ,
V_10 -> V_44 ) ;
memcpy ( V_41 + 2 + V_10 -> V_44 , V_18 , V_22 ) ;
V_13 -> V_36 -> V_38
= V_10 -> V_44 + 2 + V_22 ;
} else {
memcpy ( V_41 , V_18 , V_22 ) ;
V_13 -> V_36 -> V_38 = V_22 ;
}
V_21 = F_20 ( V_13 -> V_36 , V_39 ) ;
if ( V_21 == 0 ) {
V_10 -> V_30 = 1 ;
V_10 -> V_44 = 0 ;
V_19 -= V_22 ;
V_18 += V_22 ;
}
}
F_4 ( & V_10 -> V_15 , V_4 ) ;
if ( V_21 )
F_21 ( & V_13 -> V_28 ,
L_4 ,
V_40 , V_21 , V_10 -> V_29 ) ;
return V_21 ;
}
static int F_24 ( struct V_12 * V_13 ,
unsigned int V_47 , int V_20 )
{
int V_21 ;
struct V_9 * V_48 = F_16 ( V_13 ) ;
struct V_12 * V_23 = (struct V_12 * ) ( (struct V_24 * ) ( F_15 ( V_13 -> V_25 ) ) ) -> V_26 ;
struct V_9 * V_27 = F_16 ( V_23 ) ;
unsigned char * V_41 = V_23 -> V_36 -> V_37 ;
unsigned long V_4 = 0 ;
F_17 ( & V_13 -> V_28 ,
L_5 ,
V_48 -> V_29 , V_47 ) ;
F_9 ( & V_27 -> V_15 , V_4 ) ;
F_25 ( & V_48 -> V_15 ) ;
while ( V_27 -> V_30 ) {
F_26 ( & V_48 -> V_15 ) ;
F_1 (
& V_23 -> V_31 , V_32 ,
& V_27 -> V_15 , V_4 ) ;
if ( V_20 && F_18 ( V_33 ) )
return - V_34 ;
F_9 ( & V_27 -> V_15 , V_4 ) ;
F_25 ( & V_48 -> V_15 ) ;
}
V_41 [ 0 ] = V_49 ;
V_41 [ 1 ] = V_48 -> V_29 ;
V_41 [ 2 ] = ( V_47 & V_50 ) ?
V_51 : V_52 ;
V_41 [ 3 ] = 0 ;
V_41 [ 4 ] = V_53 ;
V_41 [ 5 ] = V_48 -> V_29 ;
V_41 [ 6 ] = ( V_47 & V_54 ) ?
V_55 : V_56 ;
V_41 [ 7 ] = 0 ;
V_23 -> V_36 -> V_38 = 8 ;
V_21 = F_20 ( V_23 -> V_36 , V_39 ) ;
if ( V_21 == 0 ) {
V_27 -> V_30 = 1 ;
V_48 -> V_57 =
( V_48 -> V_57 & ~ ( V_50 | V_54 ) )
| ( V_47 & ( V_50 | V_54 ) ) ;
}
F_26 ( & V_48 -> V_15 ) ;
F_4 ( & V_27 -> V_15 , V_4 ) ;
if ( V_21 )
F_21 ( & V_13 -> V_28 , L_2 ,
V_40 , V_21 ) ;
return V_21 ;
}
static int F_27 ( struct V_12 * V_13 ,
unsigned long V_2 )
{
int V_21 ;
unsigned char V_18 [ 2 ] ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
unsigned long V_4 = 0 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
V_10 -> V_58 = 0 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
V_18 [ 0 ] = V_59 ;
V_18 [ 1 ] = 0 ;
V_2 += V_42 ;
V_21 = F_22 ( V_13 , V_18 , 2 , V_2 - V_42 ) ;
if ( V_21 != 0 )
return V_21 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
while ( F_23 ( V_42 , V_2 ) && ! V_10 -> V_58 ) {
F_1 (
& V_10 -> V_60 , V_32 ,
& V_10 -> V_15 , V_4 ) ;
if ( F_18 ( V_33 ) )
return - V_34 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
}
V_10 -> V_58 = 0 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
return 0 ;
}
static void F_28 ( struct V_16 * V_17 )
{
unsigned long V_4 ;
struct V_12 * V_13 = V_17 -> V_61 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
V_10 -> V_62 = 1 ;
V_10 -> V_63 = 0 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
}
static void F_29 ( struct V_16 * V_17 )
{
int V_21 = 0 ;
unsigned long V_4 ;
struct V_12 * V_13 = V_17 -> V_61 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
if ( V_10 -> V_63 )
V_21 = F_20 ( V_13 -> V_64 , V_39 ) ;
V_10 -> V_62 = 0 ;
V_10 -> V_63 = 0 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
if ( V_21 )
F_21 ( & V_13 -> V_28 ,
L_4 ,
V_40 , V_21 , V_10 -> V_29 ) ;
}
static void F_30 ( struct V_16 * V_17 ,
struct V_12 * V_13 , struct V_65 * V_66 )
{
struct V_9 * V_10 = F_16 ( V_13 ) ;
struct V_67 * V_28 = & V_13 -> V_28 ;
unsigned int V_68 = V_17 -> V_69 . V_70 ;
unsigned int V_71 = V_17 -> V_69 . V_72 ;
unsigned int V_73 = V_66 -> V_70 ;
unsigned int V_74 = V_66 -> V_72 ;
unsigned char V_18 [ 32 ] ;
unsigned int V_47 ;
int V_75 , V_21 ;
int V_76 = 0 ;
T_3 V_77 ;
F_17 ( V_28 ,
L_6 ,
V_10 -> V_29 , V_68 , V_73 , V_71 , V_74 ) ;
V_77 = F_31 ( V_17 ) ;
if ( V_77 != F_32 ( V_66 ) ) {
V_75 = - 1 ;
if ( ( V_74 & V_78 ) == V_79 ) {
V_47 = V_50 ;
if ( ! ( V_17 -> V_69 . V_72 & V_80 ) ||
! F_33 ( V_81 , & V_17 -> V_4 ) )
V_47 |= V_54 ;
F_24 ( V_13 , V_47 , 1 ) ;
}
switch ( V_77 ) {
case 0 : F_24 ( V_13 , 0 , 1 ) ; break;
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
V_18 [ V_76 ++ ] = V_100 ;
V_18 [ V_76 ++ ] = V_10 -> V_29 ;
V_18 [ V_76 ++ ] = V_75 ;
V_18 [ V_76 ++ ] = 0 ;
}
}
V_17 -> V_69 . V_72 &= ~ V_101 ;
if ( ( V_71 & ( V_102 | V_103 ) ) != ( V_74 & ( V_102 | V_103 ) ) ) {
if ( V_71 & V_102 ) {
if ( V_71 & V_103 )
V_75 = V_104 ;
else
V_75 = V_105 ;
} else {
V_75 = V_106 ;
}
V_18 [ V_76 ++ ] = V_107 ;
V_18 [ V_76 ++ ] = V_10 -> V_29 ;
V_18 [ V_76 ++ ] = V_75 ;
V_18 [ V_76 ++ ] = 0 ;
}
if ( ( V_71 & V_108 ) != ( V_74 & V_108 ) ) {
V_75 = - 1 ;
switch ( V_71 & V_108 ) {
case V_109 : V_75 = V_110 ; break;
case V_111 : V_75 = V_112 ; break;
case V_113 : V_75 = V_114 ; break;
case V_115 : V_75 = V_116 ; break;
default:
F_17 ( V_28 ,
L_7 ,
( V_71 & V_108 ) ) ;
break;
}
if ( V_75 != - 1 ) {
V_18 [ V_76 ++ ] = V_117 ;
V_18 [ V_76 ++ ] = V_10 -> V_29 ;
V_18 [ V_76 ++ ] = V_75 ;
V_18 [ V_76 ++ ] = 0 ;
}
}
if ( ( V_71 & V_118 ) != ( V_74 & V_118 ) ) {
if ( ( V_71 & V_118 ) )
V_75 = V_119 ;
else
V_75 = V_120 ;
V_18 [ V_76 ++ ] = V_121 ;
V_18 [ V_76 ++ ] = V_10 -> V_29 ;
V_18 [ V_76 ++ ] = V_75 ;
V_18 [ V_76 ++ ] = 0 ;
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
V_18 [ V_76 ++ ] = V_53 ;
V_18 [ V_76 ++ ] = V_10 -> V_29 ;
V_18 [ V_76 ++ ] = V_55 ;
V_18 [ V_76 ++ ] = 0 ;
} else {
V_75 &= ~ V_124 ;
}
V_18 [ V_76 ++ ] = V_125 ;
V_18 [ V_76 ++ ] = V_10 -> V_29 ;
V_18 [ V_76 ++ ] = V_75 ;
V_18 [ V_76 ++ ] = 0 ;
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
V_17 -> V_129 = 0 ;
}
V_18 [ V_76 ++ ] = V_130 ;
V_18 [ V_76 ++ ] = V_10 -> V_29 ;
V_18 [ V_76 ++ ] = V_75 ;
V_18 [ V_76 ++ ] = 0 ;
}
if ( ( V_71 & V_131 ) != ( V_74 & V_131 ) ) {
if ( V_71 & V_131 )
V_75 = V_132 ;
else
V_75 = V_133 ;
V_18 [ V_76 ++ ] = V_134 ;
V_18 [ V_76 ++ ] = V_10 -> V_29 ;
V_18 [ V_76 ++ ] = V_75 ;
V_18 [ V_76 ++ ] = 0 ;
}
V_21 = F_14 ( V_13 , V_18 , V_76 , 1 ) ;
if ( V_21 != 0 )
F_17 ( V_28 , L_8 , V_21 ) ;
F_34 ( V_17 , V_77 , V_77 ) ;
}
static void F_35 ( struct V_16 * V_17 , int V_135 )
{
struct V_12 * V_13 = V_17 -> V_61 ;
unsigned char V_18 [ 4 ] ;
V_18 [ 0 ] = V_136 ;
V_18 [ 1 ] = 2 ;
V_18 [ 2 ] = V_135 ? 1 : 0 ;
V_18 [ 3 ] = 0 ;
F_22 ( V_13 , V_18 , 4 , 0 ) ;
}
static int F_36 ( struct V_16 * V_17 )
{
struct V_12 * V_13 = V_17 -> V_61 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
unsigned int V_137 ;
unsigned long V_4 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
V_137 = V_10 -> V_57 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
return V_137 ;
}
static int F_37 ( struct V_16 * V_17 ,
unsigned int V_138 , unsigned int V_139 )
{
struct V_12 * V_13 = V_17 -> V_61 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
unsigned int V_137 ;
unsigned long V_4 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
V_137 = ( V_10 -> V_57 & ~ V_139 ) | V_138 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
return F_24 ( V_13 , V_137 , 1 ) ;
}
static int F_38 ( struct V_16 * V_17 , struct V_12 * V_13 ,
const unsigned char * V_18 , int V_19 )
{
int V_21 , V_140 , V_141 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
unsigned char * V_41 = V_13 -> V_36 -> V_37 ;
unsigned long V_4 = 0 ;
F_17 ( & V_13 -> V_28 ,
L_9 ,
V_10 -> V_29 , V_19 , F_39 () ) ;
V_19 = F_19 ( V_19 , V_13 -> V_35 - 2 ) ;
V_19 = F_19 ( 64 , V_19 ) ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
if ( V_10 -> V_30 ) {
if ( V_19 == 1 && V_10 -> V_44 < V_142 ) {
V_10 -> V_46 [ V_10 -> V_44 ++ ] = * V_18 ;
V_141 = 1 ;
} else {
V_141 = 0 ;
}
F_4 ( & V_10 -> V_15 , V_4 ) ;
return V_141 ;
}
V_141 = F_19 ( V_19 , V_13 -> V_35 - 2 - V_10 -> V_44 ) ;
V_140 = V_141 + V_10 -> V_44 ;
if ( V_140 == 0 ) {
F_4 ( & V_10 -> V_15 , V_4 ) ;
return 0 ;
}
V_13 -> V_36 -> V_38 = V_140 + 2 ;
* V_41 ++ = V_45 ;
* V_41 ++ = V_140 ;
memcpy ( V_41 , V_10 -> V_46 , V_10 -> V_44 ) ;
V_41 += V_10 -> V_44 ;
memcpy ( V_41 , V_18 , V_141 ) ;
V_21 = F_20 ( V_13 -> V_36 , V_39 ) ;
if ( V_21 == 0 ) {
V_10 -> V_30 = 1 ;
V_21 = V_141 ;
V_10 -> V_44 = 0 ;
}
F_4 ( & V_10 -> V_15 , V_4 ) ;
if ( V_21 < 0 )
F_40 ( V_13 ,
L_4 ,
V_40 , V_21 , V_10 -> V_29 ) ;
F_17 ( & V_13 -> V_28 , L_10 , V_21 ) ;
return V_21 ;
}
static void F_41 ( struct V_143 * V_143 )
{
struct V_12 * V_13 = V_143 -> V_144 ;
struct V_145 * V_25 ;
struct V_9 * V_10 ;
struct V_24 * V_146 ;
int V_21 = 0 ;
int V_147 = V_143 -> V_147 ;
if ( V_13 == NULL || ( V_10 = F_16 ( V_13 ) ) == NULL ) {
F_42 ( L_11 ,
V_40 , V_147 ) ;
return;
}
V_25 = V_13 -> V_25 ;
if ( V_25 == NULL || ( V_146 = F_15 ( V_25 ) ) == NULL ) {
F_21 ( & V_13 -> V_28 ,
L_12 ,
V_40 , V_147 ) ;
return;
}
if ( V_10 -> V_29 == V_146 -> V_148 ) {
F_17 ( & V_13 -> V_28 , L_13 ) ;
F_25 ( & V_10 -> V_15 ) ;
V_10 -> V_30 = 0 ;
F_43 ( & V_13 -> V_31 ) ;
F_26 ( & V_10 -> V_15 ) ;
return;
}
F_25 ( & V_10 -> V_15 ) ;
V_10 -> V_30 = 0 ;
if ( V_10 -> V_44 > 0 ) {
* ( ( unsigned char * ) ( V_13 -> V_36 -> V_37 ) )
= ( unsigned char ) V_45 ;
* ( ( unsigned char * ) ( V_13 -> V_36 -> V_37 ) + 1 )
= ( unsigned char ) V_10 -> V_44 ;
V_13 -> V_36 -> V_38 =
V_10 -> V_44 + 2 ;
memcpy ( V_13 -> V_36 -> V_37 + 2 , V_10 -> V_46 ,
V_10 -> V_44 ) ;
V_21 = F_20 ( V_13 -> V_36 , V_39 ) ;
if ( V_21 == 0 ) {
V_10 -> V_30 = 1 ;
V_10 -> V_44 = 0 ;
}
}
F_10 ( V_13 ) ;
F_44 ( & V_10 -> V_11 ) ;
F_26 ( & V_10 -> V_15 ) ;
if ( V_21 && V_21 != - V_149 )
F_40 ( V_13 ,
L_4 ,
V_40 , V_21 , V_10 -> V_29 ) ;
}
static int F_45 ( struct V_16 * V_17 )
{
struct V_12 * V_13 = V_17 -> V_61 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
int V_150 ;
unsigned long V_4 = 0 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
if ( V_10 -> V_30 )
V_150 = 0 ;
else
V_150 = V_13 -> V_35 - 2 - V_10 -> V_44 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
F_17 ( & V_13 -> V_28 , L_14 , V_10 -> V_29 , V_150 ) ;
return V_150 ;
}
static int F_46 ( struct V_16 * V_17 )
{
struct V_12 * V_13 = V_17 -> V_61 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
if ( V_10 -> V_30 ) {
F_17 ( & V_13 -> V_28 , L_15 ,
V_10 -> V_29 , V_13 -> V_35 - 2 ) ;
return 256 ;
} else {
F_17 ( & V_13 -> V_28 , L_15 ,
V_10 -> V_29 , V_10 -> V_44 ) ;
return V_10 -> V_44 ;
}
}
static void F_47 ( struct V_12 * V_13 , int V_151 )
{
F_24 ( V_13 , V_151 * ( V_50 | V_54 ) , 1 ) ;
}
static int F_48 ( struct V_16 * V_17 , struct V_12 * V_13 )
{
int V_21 ;
unsigned char V_18 [ 32 ] ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
struct V_65 V_152 ;
if ( F_49 ( V_13 -> V_25 ) != 0 )
return - V_153 ;
V_18 [ 0 ] = V_154 ;
V_18 [ 1 ] = V_10 -> V_29 ;
V_18 [ 2 ] = V_132 ;
V_18 [ 3 ] = 0 ;
V_18 [ 4 ] = V_155 ;
V_18 [ 5 ] = V_10 -> V_29 ;
V_18 [ 6 ] = V_156 | V_157 ;
V_18 [ 7 ] = 0 ;
V_21 = F_14 ( V_13 , V_18 , 8 , 1 ) ;
if ( V_21 != 0 )
F_17 ( & V_13 -> V_28 , L_16 , V_21 ) ;
if ( V_17 ) {
V_152 . V_72 = ~ V_17 -> V_69 . V_72 ;
V_152 . V_70 = ~ V_17 -> V_69 . V_70 ;
F_30 ( V_17 , V_13 , & V_152 ) ;
}
return 0 ;
}
static void F_50 ( struct V_12 * V_13 )
{
F_2 ( V_5 ) ;
int V_21 ;
unsigned char V_18 [ 32 ] ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
F_51 ( & V_13 -> V_25 -> V_158 ) ;
if ( V_13 -> V_25 -> V_159 )
goto exit;
if ( V_13 -> V_25 -> V_28 ) {
F_27 ( V_13 , V_160 ) ;
V_18 [ 0 ] = V_125 ;
V_18 [ 1 ] = V_10 -> V_29 ;
V_18 [ 2 ] = V_133 ;
V_18 [ 3 ] = 0 ;
V_18 [ 4 ] = V_130 ;
V_18 [ 5 ] = V_10 -> V_29 ;
V_18 [ 6 ] = V_133 ;
V_18 [ 7 ] = 0 ;
V_18 [ 8 ] = V_154 ;
V_18 [ 9 ] = V_10 -> V_29 ;
V_18 [ 10 ] = V_133 ;
V_18 [ 11 ] = 0 ;
V_18 [ 12 ] = V_134 ;
V_18 [ 13 ] = V_10 -> V_29 ;
V_18 [ 14 ] = V_133 ;
V_18 [ 15 ] = 0 ;
V_18 [ 16 ] = V_155 ;
V_18 [ 17 ] = V_10 -> V_29 ;
V_18 [ 18 ] = V_156 | V_157 ;
V_18 [ 19 ] = 0 ;
V_21 = F_14 ( V_13 , V_18 , 20 , 0 ) ;
if ( V_21 != 0 )
F_17 ( & V_13 -> V_28 , L_17 , V_21 ) ;
F_3 ( & V_10 -> V_161 , & V_5 ,
V_6 ) ;
F_5 ( V_160 ) ;
F_6 ( & V_10 -> V_161 , & V_5 ) ;
F_52 ( V_13 -> V_36 ) ;
}
exit:
F_53 ( & V_10 -> V_15 ) ;
V_10 -> V_30 = 0 ;
F_43 ( & V_10 -> V_162 ) ;
F_54 ( & V_10 -> V_15 ) ;
F_55 ( & V_13 -> V_25 -> V_158 ) ;
}
static int F_49 ( struct V_145 * V_25 )
{
int V_76 , V_21 = 0 ;
struct V_24 * V_146 = F_15 ( V_25 ) ;
struct V_12 * V_13 ;
F_25 ( & V_146 -> V_163 ) ;
if ( V_146 -> V_164 ) {
F_26 ( & V_146 -> V_163 ) ;
return 0 ;
}
V_146 -> V_164 = 1 ;
F_26 ( & V_146 -> V_163 ) ;
for ( V_76 = 0 ; V_76 < V_25 -> type -> V_165 + 1 ; V_76 ++ ) {
V_13 = V_25 -> V_13 [ V_76 ] ;
V_21 = F_20 ( V_13 -> V_64 , V_166 ) ;
if ( V_21 != 0 ) {
F_21 ( & V_13 -> V_28 ,
L_4 ,
V_40 , V_21 , V_76 ) ;
break;
}
}
return V_21 ;
}
static int F_56 ( struct V_12 * V_13 , unsigned V_167 )
{
struct V_9 * V_10 ;
V_10 = F_57 ( sizeof( * V_10 ) , V_166 ) ;
if ( ! V_10 )
return - V_168 ;
F_58 ( & V_10 -> V_15 ) ;
V_10 -> V_29 = V_167 ;
F_59 ( & V_10 -> V_169 ) ;
F_59 ( & V_10 -> V_60 ) ;
F_59 ( & V_10 -> V_161 ) ;
F_59 ( & V_10 -> V_162 ) ;
F_60 ( & V_10 -> V_11 , F_7 ) ;
V_10 -> V_14 = V_13 ;
F_59 ( & V_13 -> V_31 ) ;
F_61 ( V_13 , V_10 ) ;
return 0 ;
}
static int F_62 ( struct V_145 * V_25 )
{
struct V_24 * V_146 ;
int V_21 ;
V_146 = F_57 ( sizeof( * V_146 ) , V_166 ) ;
if ( ! V_146 )
return - V_168 ;
F_58 ( & V_146 -> V_163 ) ;
V_146 -> V_148 = V_25 -> type -> V_165 ;
V_146 -> V_26 = V_25 -> V_13 [ V_146 -> V_148 ] ;
V_21 = F_56 ( V_146 -> V_26 ,
V_146 -> V_148 ) ;
if ( V_21 ) {
F_63 ( V_146 ) ;
return V_21 ;
}
F_64 ( V_25 , V_146 ) ;
return 0 ;
}
static void F_65 ( struct V_145 * V_25 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_25 -> type -> V_165 + 1 ; V_76 ++ ) {
F_52 ( V_25 -> V_13 [ V_76 ] -> V_64 ) ;
F_52 ( V_25 -> V_13 [ V_76 ] -> V_36 ) ;
}
}
static void F_66 ( struct V_145 * V_25 )
{
struct V_24 * V_146 ;
struct V_9 * V_10 ;
V_146 = F_15 ( V_25 ) ;
V_10 = F_16 ( V_146 -> V_26 ) ;
F_63 ( V_10 ) ;
F_63 ( V_146 ) ;
}
static int F_67 ( struct V_12 * V_13 )
{
unsigned V_167 ;
V_167 = V_13 -> V_170 - V_13 -> V_25 -> V_171 ;
return F_56 ( V_13 , V_167 ) ;
}
static int F_68 ( struct V_12 * V_13 )
{
struct V_9 * V_10 ;
V_10 = F_16 ( V_13 ) ;
F_63 ( V_10 ) ;
return 0 ;
}
static void F_69 ( struct V_143 * V_143 )
{
struct V_12 * V_13 = V_143 -> V_144 ;
struct V_9 * V_10 ;
struct V_24 * V_146 ;
int V_21 ;
int V_147 = V_143 -> V_147 ;
if ( V_13 == NULL )
return;
V_10 = F_16 ( V_13 ) ;
if ( V_10 == NULL ) {
F_21 ( & V_13 -> V_28 , L_18 ,
V_40 , V_147 ) ;
return;
}
if ( V_13 -> V_25 == NULL ||
( V_146 = F_15 ( V_13 -> V_25 ) ) == NULL ) {
F_21 ( & V_13 -> V_28 , L_19
L_20 , V_40 , V_147 ) ;
return;
}
if ( V_147 ) {
F_21 ( & V_13 -> V_28 ,
L_21 ,
V_40 , V_147 , V_10 -> V_29 ) ;
return;
}
if ( V_10 -> V_29 == V_146 -> V_148 ) {
if ( F_70 ( V_143 ) != 0 )
return;
} else {
if ( F_71 ( V_143 ) != 0 )
return;
}
V_21 = F_20 ( V_143 , V_39 ) ;
if ( V_21 != 0 && V_21 != - V_149 ) {
F_21 ( & V_13 -> V_28 ,
L_22 ,
V_40 , V_21 , V_10 -> V_29 ) ;
}
}
static int F_71 ( struct V_143 * V_143 )
{
struct V_12 * V_13 = V_143 -> V_144 ;
struct V_16 * V_17 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
int V_172 = ( ( unsigned char * ) V_143 -> V_37 ) [ 0 ] ;
int V_22 = ( ( unsigned char * ) V_143 -> V_37 ) [ 1 ] ;
int V_173 = ( ( unsigned char * ) V_143 -> V_37 ) [ 2 ] ;
unsigned char * V_41 = ( ( unsigned char * ) V_143 -> V_37 ) + 3 ;
int V_174 , V_175 ;
int V_147 = V_143 -> V_147 ;
if ( V_143 -> V_147 == - V_176 )
return 0 ;
if ( V_143 -> V_177 != V_22 + 2 ) {
F_21 ( & V_13 -> V_28 , L_23
L_24
L_25 , V_40 , V_147 ,
V_10 -> V_29 , V_172 , V_22 , V_143 -> V_177 ,
V_173 ) ;
return - 1 ;
}
V_17 = F_11 ( & V_13 -> V_13 ) ;
F_25 ( & V_10 -> V_15 ) ;
V_175 = V_10 -> V_62 ;
if ( V_175 )
V_10 -> V_63 = 1 ;
if ( V_17 && V_172 == V_178 ) {
V_174 = 0 ;
if ( V_173 & V_179 )
F_72 ( V_17 , 0 , V_180 ) ;
if ( V_173 & V_181 )
V_174 = V_182 ;
else if ( V_173 & V_183 )
V_174 = V_184 ;
else if ( V_173 & V_185 )
V_174 = V_186 ;
-- V_22 ;
if ( V_22 > 0 ) {
F_73 ( V_17 , V_41 , V_174 ,
V_22 ) ;
F_74 ( V_17 ) ;
}
}
F_26 ( & V_10 -> V_15 ) ;
F_13 ( V_17 ) ;
if ( V_172 == V_187 )
F_17 ( & V_13 -> V_28 , L_26 , V_40 ) ;
else if ( V_172 != V_178 )
F_17 ( & V_13 -> V_28 , L_27 , V_40 , V_172 ) ;
return V_175 ? 1 : 0 ;
}
static int F_70 ( struct V_143 * V_143 )
{
struct V_12 * V_13 = V_143 -> V_144 ;
struct V_145 * V_25 = V_13 -> V_25 ;
struct V_16 * V_17 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
int V_172 , line , V_147 , V_137 ;
int V_76 ;
unsigned int V_188 ;
for ( V_76 = 0 ; V_76 < V_143 -> V_177 - 3 ; ) {
V_172 = ( ( unsigned char * ) V_143 -> V_37 ) [ V_76 ++ ] ;
line = ( ( unsigned char * ) V_143 -> V_37 ) [ V_76 ++ ] ;
V_147 = ( ( unsigned char * ) V_143 -> V_37 ) [ V_76 ++ ] ;
V_137 = ( ( unsigned char * ) V_143 -> V_37 ) [ V_76 ++ ] ;
F_17 ( & V_13 -> V_28 , L_28 ,
V_172 , line , V_147 , V_137 ) ;
if ( V_147 != 0 || line >= V_25 -> type -> V_165 )
continue;
V_13 = V_25 -> V_13 [ line ] ;
V_10 = F_16 ( V_13 ) ;
if ( V_10 == NULL )
return - 1 ;
V_17 = F_11 ( & V_13 -> V_13 ) ;
V_188 = 0 ;
if ( V_17 )
V_188 = V_17 -> V_69 . V_72 & V_80 ;
if ( V_17 && V_172 == V_154 ) {
F_25 ( & V_10 -> V_15 ) ;
if ( V_137 & V_189 ) {
V_10 -> V_57 |= V_190 ;
if ( V_188 ) {
V_17 -> V_129 = 0 ;
F_10 ( V_13 ) ;
}
} else {
V_10 -> V_57 &= ~ V_190 ;
if ( V_188 )
V_17 -> V_129 = 1 ;
}
if ( V_137 & V_191 )
V_10 -> V_57 |= V_192 ;
else
V_10 -> V_57 &= ~ V_192 ;
if ( V_137 & V_193 )
V_10 -> V_57 |= V_194 ;
else
V_10 -> V_57 &= ~ V_194 ;
if ( V_137 & V_195 )
V_10 -> V_57 |= V_196 ;
else
V_10 -> V_57 &= ~ V_196 ;
F_43 ( & V_10 -> V_169 ) ;
F_26 ( & V_10 -> V_15 ) ;
} else if ( V_172 == V_59 ) {
F_25 ( & V_10 -> V_15 ) ;
V_10 -> V_58 = 1 ;
F_43 ( & V_10 -> V_60 ) ;
F_26 ( & V_10 -> V_15 ) ;
} else if ( V_172 == V_155 ) {
F_43 ( & V_10 -> V_161 ) ;
}
F_13 ( V_17 ) ;
}
return 0 ;
}
