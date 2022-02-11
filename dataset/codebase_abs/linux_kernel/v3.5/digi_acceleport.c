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
F_17 ( L_1 , V_27 -> V_28 , V_19 ) ;
F_9 ( & V_27 -> V_15 , V_4 ) ;
while ( V_19 > 0 ) {
while ( V_27 -> V_29 ) {
F_1 (
& V_23 -> V_30 , V_31 ,
& V_27 -> V_15 , V_4 ) ;
if ( V_20 && F_18 ( V_32 ) )
return - V_33 ;
F_9 ( & V_27 -> V_15 , V_4 ) ;
}
V_22 = F_19 ( V_19 , V_23 -> V_34 ) ;
if ( V_22 > 4 )
V_22 &= ~ 3 ;
memcpy ( V_23 -> V_35 -> V_36 , V_18 , V_22 ) ;
V_23 -> V_35 -> V_37 = V_22 ;
V_21 = F_20 ( V_23 -> V_35 , V_38 ) ;
if ( V_21 == 0 ) {
V_27 -> V_29 = 1 ;
V_19 -= V_22 ;
V_18 += V_22 ;
}
}
F_4 ( & V_27 -> V_15 , V_4 ) ;
if ( V_21 )
F_21 ( & V_13 -> V_39 , L_2 ,
V_40 , V_21 ) ;
return V_21 ;
}
static int F_22 ( struct V_12 * V_13 ,
unsigned char * V_18 , int V_19 , unsigned long V_2 )
{
int V_21 = 0 ;
int V_22 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
unsigned char * V_41 = V_13 -> V_35 -> V_36 ;
unsigned long V_4 = 0 ;
F_17 ( L_3 ,
V_10 -> V_28 , V_19 ) ;
if ( V_2 )
V_2 += V_42 ;
else
V_2 = V_43 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
while ( V_19 > 0 && V_21 == 0 ) {
while ( V_10 -> V_29 &&
F_23 ( V_42 , V_2 ) ) {
F_1 (
& V_13 -> V_30 , V_31 ,
& V_10 -> V_15 , V_4 ) ;
if ( F_18 ( V_32 ) )
return - V_33 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
}
V_22 = F_19 ( V_19 , V_13 -> V_34 - 2 - V_10 -> V_44 ) ;
if ( V_22 > 4 )
V_22 &= ~ 3 ;
if ( V_10 -> V_44 > 0 ) {
V_41 [ 0 ] = V_45 ;
V_41 [ 1 ] = V_10 -> V_44 ;
memcpy ( V_41 + 2 , V_10 -> V_46 ,
V_10 -> V_44 ) ;
memcpy ( V_41 + 2 + V_10 -> V_44 , V_18 , V_22 ) ;
V_13 -> V_35 -> V_37
= V_10 -> V_44 + 2 + V_22 ;
} else {
memcpy ( V_41 , V_18 , V_22 ) ;
V_13 -> V_35 -> V_37 = V_22 ;
}
V_21 = F_20 ( V_13 -> V_35 , V_38 ) ;
if ( V_21 == 0 ) {
V_10 -> V_29 = 1 ;
V_10 -> V_44 = 0 ;
V_19 -= V_22 ;
V_18 += V_22 ;
}
}
F_4 ( & V_10 -> V_15 , V_4 ) ;
if ( V_21 )
F_21 ( & V_13 -> V_39 ,
L_4 ,
V_40 , V_21 , V_10 -> V_28 ) ;
return V_21 ;
}
static int F_24 ( struct V_12 * V_13 ,
unsigned int V_47 , int V_20 )
{
int V_21 ;
struct V_9 * V_48 = F_16 ( V_13 ) ;
struct V_12 * V_23 = (struct V_12 * ) ( (struct V_24 * ) ( F_15 ( V_13 -> V_25 ) ) ) -> V_26 ;
struct V_9 * V_27 = F_16 ( V_23 ) ;
unsigned char * V_41 = V_23 -> V_35 -> V_36 ;
unsigned long V_4 = 0 ;
F_17 ( L_5 ,
V_48 -> V_28 , V_47 ) ;
F_9 ( & V_27 -> V_15 , V_4 ) ;
F_25 ( & V_48 -> V_15 ) ;
while ( V_27 -> V_29 ) {
F_26 ( & V_48 -> V_15 ) ;
F_1 (
& V_23 -> V_30 , V_31 ,
& V_27 -> V_15 , V_4 ) ;
if ( V_20 && F_18 ( V_32 ) )
return - V_33 ;
F_9 ( & V_27 -> V_15 , V_4 ) ;
F_25 ( & V_48 -> V_15 ) ;
}
V_41 [ 0 ] = V_49 ;
V_41 [ 1 ] = V_48 -> V_28 ;
V_41 [ 2 ] = ( V_47 & V_50 ) ?
V_51 : V_52 ;
V_41 [ 3 ] = 0 ;
V_41 [ 4 ] = V_53 ;
V_41 [ 5 ] = V_48 -> V_28 ;
V_41 [ 6 ] = ( V_47 & V_54 ) ?
V_55 : V_56 ;
V_41 [ 7 ] = 0 ;
V_23 -> V_35 -> V_37 = 8 ;
V_21 = F_20 ( V_23 -> V_35 , V_38 ) ;
if ( V_21 == 0 ) {
V_27 -> V_29 = 1 ;
V_48 -> V_57 =
( V_48 -> V_57 & ~ ( V_50 | V_54 ) )
| ( V_47 & ( V_50 | V_54 ) ) ;
}
F_26 ( & V_48 -> V_15 ) ;
F_4 ( & V_27 -> V_15 , V_4 ) ;
if ( V_21 )
F_21 ( & V_13 -> V_39 , L_2 ,
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
& V_10 -> V_60 , V_31 ,
& V_10 -> V_15 , V_4 ) ;
if ( F_18 ( V_32 ) )
return - V_33 ;
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
V_21 = F_20 ( V_13 -> V_64 , V_38 ) ;
V_10 -> V_62 = 0 ;
V_10 -> V_63 = 0 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
if ( V_21 )
F_21 ( & V_13 -> V_39 ,
L_4 ,
V_40 , V_21 , V_10 -> V_28 ) ;
}
static void F_30 ( struct V_16 * V_17 ,
struct V_12 * V_13 , struct V_65 * V_66 )
{
struct V_9 * V_10 = F_16 ( V_13 ) ;
unsigned int V_67 = V_17 -> V_68 -> V_69 ;
unsigned int V_70 = V_17 -> V_68 -> V_71 ;
unsigned int V_72 = V_66 -> V_69 ;
unsigned int V_73 = V_66 -> V_71 ;
unsigned char V_18 [ 32 ] ;
unsigned int V_47 ;
int V_74 , V_21 ;
int V_75 = 0 ;
T_3 V_76 ;
F_17 ( L_6 , V_10 -> V_28 , V_67 , V_72 , V_70 , V_73 ) ;
V_76 = F_31 ( V_17 ) ;
if ( V_76 != F_32 ( V_66 ) ) {
V_74 = - 1 ;
if ( ( V_73 & V_77 ) == V_78 ) {
V_47 = V_50 ;
if ( ! ( V_17 -> V_68 -> V_71 & V_79 ) ||
! F_33 ( V_80 , & V_17 -> V_4 ) )
V_47 |= V_54 ;
F_24 ( V_13 , V_47 , 1 ) ;
}
switch ( V_76 ) {
case 0 : F_24 ( V_13 , 0 , 1 ) ; break;
case 50 : V_74 = V_81 ; break;
case 75 : V_74 = V_82 ; break;
case 110 : V_74 = V_83 ; break;
case 150 : V_74 = V_84 ; break;
case 200 : V_74 = V_85 ; break;
case 300 : V_74 = V_86 ; break;
case 600 : V_74 = V_87 ; break;
case 1200 : V_74 = V_88 ; break;
case 1800 : V_74 = V_89 ; break;
case 2400 : V_74 = V_90 ; break;
case 4800 : V_74 = V_91 ; break;
case 9600 : V_74 = V_92 ; break;
case 19200 : V_74 = V_93 ; break;
case 38400 : V_74 = V_94 ; break;
case 57600 : V_74 = V_95 ; break;
case 115200 : V_74 = V_96 ; break;
case 230400 : V_74 = V_97 ; break;
case 460800 : V_74 = V_98 ; break;
default:
V_74 = V_92 ;
V_76 = 9600 ;
break;
}
if ( V_74 != - 1 ) {
V_18 [ V_75 ++ ] = V_99 ;
V_18 [ V_75 ++ ] = V_10 -> V_28 ;
V_18 [ V_75 ++ ] = V_74 ;
V_18 [ V_75 ++ ] = 0 ;
}
}
V_17 -> V_68 -> V_71 &= ~ V_100 ;
if ( ( V_70 & ( V_101 | V_102 ) ) != ( V_73 & ( V_101 | V_102 ) ) ) {
if ( V_70 & V_101 ) {
if ( V_70 & V_102 )
V_74 = V_103 ;
else
V_74 = V_104 ;
} else {
V_74 = V_105 ;
}
V_18 [ V_75 ++ ] = V_106 ;
V_18 [ V_75 ++ ] = V_10 -> V_28 ;
V_18 [ V_75 ++ ] = V_74 ;
V_18 [ V_75 ++ ] = 0 ;
}
if ( ( V_70 & V_107 ) != ( V_73 & V_107 ) ) {
V_74 = - 1 ;
switch ( V_70 & V_107 ) {
case V_108 : V_74 = V_109 ; break;
case V_110 : V_74 = V_111 ; break;
case V_112 : V_74 = V_113 ; break;
case V_114 : V_74 = V_115 ; break;
default:
F_17 ( L_7 ,
( V_70 & V_107 ) ) ;
break;
}
if ( V_74 != - 1 ) {
V_18 [ V_75 ++ ] = V_116 ;
V_18 [ V_75 ++ ] = V_10 -> V_28 ;
V_18 [ V_75 ++ ] = V_74 ;
V_18 [ V_75 ++ ] = 0 ;
}
}
if ( ( V_70 & V_117 ) != ( V_73 & V_117 ) ) {
if ( ( V_70 & V_117 ) )
V_74 = V_118 ;
else
V_74 = V_119 ;
V_18 [ V_75 ++ ] = V_120 ;
V_18 [ V_75 ++ ] = V_10 -> V_28 ;
V_18 [ V_75 ++ ] = V_74 ;
V_18 [ V_75 ++ ] = 0 ;
}
if ( ( V_67 & V_121 ) != ( V_72 & V_121 )
|| ( V_70 & V_79 ) != ( V_73 & V_79 ) ) {
V_74 = 0 ;
if ( V_67 & V_121 )
V_74 |= V_122 ;
else
V_74 &= ~ V_122 ;
if ( V_70 & V_79 ) {
V_74 |= V_123 ;
V_18 [ V_75 ++ ] = V_53 ;
V_18 [ V_75 ++ ] = V_10 -> V_28 ;
V_18 [ V_75 ++ ] = V_55 ;
V_18 [ V_75 ++ ] = 0 ;
} else {
V_74 &= ~ V_123 ;
}
V_18 [ V_75 ++ ] = V_124 ;
V_18 [ V_75 ++ ] = V_10 -> V_28 ;
V_18 [ V_75 ++ ] = V_74 ;
V_18 [ V_75 ++ ] = 0 ;
}
if ( ( V_67 & V_125 ) != ( V_72 & V_125 )
|| ( V_70 & V_79 ) != ( V_73 & V_79 ) ) {
V_74 = 0 ;
if ( V_67 & V_125 )
V_74 |= V_126 ;
else
V_74 &= ~ V_126 ;
if ( V_70 & V_79 ) {
V_74 |= V_127 ;
} else {
V_74 &= ~ V_127 ;
V_17 -> V_128 = 0 ;
}
V_18 [ V_75 ++ ] = V_129 ;
V_18 [ V_75 ++ ] = V_10 -> V_28 ;
V_18 [ V_75 ++ ] = V_74 ;
V_18 [ V_75 ++ ] = 0 ;
}
if ( ( V_70 & V_130 ) != ( V_73 & V_130 ) ) {
if ( V_70 & V_130 )
V_74 = V_131 ;
else
V_74 = V_132 ;
V_18 [ V_75 ++ ] = V_133 ;
V_18 [ V_75 ++ ] = V_10 -> V_28 ;
V_18 [ V_75 ++ ] = V_74 ;
V_18 [ V_75 ++ ] = 0 ;
}
V_21 = F_14 ( V_13 , V_18 , V_75 , 1 ) ;
if ( V_21 != 0 )
F_17 ( L_8 , V_21 ) ;
F_34 ( V_17 , V_76 , V_76 ) ;
}
static void F_35 ( struct V_16 * V_17 , int V_134 )
{
struct V_12 * V_13 = V_17 -> V_61 ;
unsigned char V_18 [ 4 ] ;
V_18 [ 0 ] = V_135 ;
V_18 [ 1 ] = 2 ;
V_18 [ 2 ] = V_134 ? 1 : 0 ;
V_18 [ 3 ] = 0 ;
F_22 ( V_13 , V_18 , 4 , 0 ) ;
}
static int F_36 ( struct V_16 * V_17 )
{
struct V_12 * V_13 = V_17 -> V_61 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
unsigned int V_136 ;
unsigned long V_4 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
V_136 = V_10 -> V_57 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
return V_136 ;
}
static int F_37 ( struct V_16 * V_17 ,
unsigned int V_137 , unsigned int V_138 )
{
struct V_12 * V_13 = V_17 -> V_61 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
unsigned int V_136 ;
unsigned long V_4 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
V_136 = ( V_10 -> V_57 & ~ V_138 ) | V_137 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
return F_24 ( V_13 , V_136 , 1 ) ;
}
static int F_38 ( struct V_16 * V_17 , struct V_12 * V_13 ,
const unsigned char * V_18 , int V_19 )
{
int V_21 , V_139 , V_140 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
unsigned char * V_41 = V_13 -> V_35 -> V_36 ;
unsigned long V_4 = 0 ;
F_17 ( L_9 ,
V_10 -> V_28 , V_19 , F_39 () ) ;
V_19 = F_19 ( V_19 , V_13 -> V_34 - 2 ) ;
V_19 = F_19 ( 64 , V_19 ) ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
if ( V_10 -> V_29 ) {
if ( V_19 == 1 && V_10 -> V_44 < V_141 ) {
V_10 -> V_46 [ V_10 -> V_44 ++ ] = * V_18 ;
V_140 = 1 ;
} else {
V_140 = 0 ;
}
F_4 ( & V_10 -> V_15 , V_4 ) ;
return V_140 ;
}
V_140 = F_19 ( V_19 , V_13 -> V_34 - 2 - V_10 -> V_44 ) ;
V_139 = V_140 + V_10 -> V_44 ;
if ( V_139 == 0 ) {
F_4 ( & V_10 -> V_15 , V_4 ) ;
return 0 ;
}
V_13 -> V_35 -> V_37 = V_139 + 2 ;
* V_41 ++ = V_45 ;
* V_41 ++ = V_139 ;
memcpy ( V_41 , V_10 -> V_46 , V_10 -> V_44 ) ;
V_41 += V_10 -> V_44 ;
memcpy ( V_41 , V_18 , V_140 ) ;
V_21 = F_20 ( V_13 -> V_35 , V_38 ) ;
if ( V_21 == 0 ) {
V_10 -> V_29 = 1 ;
V_21 = V_140 ;
V_10 -> V_44 = 0 ;
}
F_4 ( & V_10 -> V_15 , V_4 ) ;
if ( V_21 < 0 )
F_40 ( V_13 ,
L_4 ,
V_40 , V_21 , V_10 -> V_28 ) ;
F_17 ( L_10 , V_21 ) ;
return V_21 ;
}
static void F_41 ( struct V_142 * V_142 )
{
struct V_12 * V_13 = V_142 -> V_143 ;
struct V_144 * V_25 ;
struct V_9 * V_10 ;
struct V_24 * V_145 ;
int V_21 = 0 ;
int V_146 = V_142 -> V_146 ;
if ( V_13 == NULL || ( V_10 = F_16 ( V_13 ) ) == NULL ) {
F_42 ( L_11 ,
V_40 , V_146 ) ;
return;
}
V_25 = V_13 -> V_25 ;
if ( V_25 == NULL || ( V_145 = F_15 ( V_25 ) ) == NULL ) {
F_21 ( & V_13 -> V_39 ,
L_12 ,
V_40 , V_146 ) ;
return;
}
if ( V_10 -> V_28 == V_145 -> V_147 ) {
F_17 ( L_13 ) ;
F_25 ( & V_10 -> V_15 ) ;
V_10 -> V_29 = 0 ;
F_43 ( & V_13 -> V_30 ) ;
F_26 ( & V_10 -> V_15 ) ;
return;
}
F_25 ( & V_10 -> V_15 ) ;
V_10 -> V_29 = 0 ;
if ( V_10 -> V_44 > 0 ) {
* ( ( unsigned char * ) ( V_13 -> V_35 -> V_36 ) )
= ( unsigned char ) V_45 ;
* ( ( unsigned char * ) ( V_13 -> V_35 -> V_36 ) + 1 )
= ( unsigned char ) V_10 -> V_44 ;
V_13 -> V_35 -> V_37 =
V_10 -> V_44 + 2 ;
memcpy ( V_13 -> V_35 -> V_36 + 2 , V_10 -> V_46 ,
V_10 -> V_44 ) ;
V_21 = F_20 ( V_13 -> V_35 , V_38 ) ;
if ( V_21 == 0 ) {
V_10 -> V_29 = 1 ;
V_10 -> V_44 = 0 ;
}
}
F_10 ( V_13 ) ;
F_44 ( & V_10 -> V_11 ) ;
F_26 ( & V_10 -> V_15 ) ;
if ( V_21 && V_21 != - V_148 )
F_40 ( V_13 ,
L_4 ,
V_40 , V_21 , V_10 -> V_28 ) ;
}
static int F_45 ( struct V_16 * V_17 )
{
struct V_12 * V_13 = V_17 -> V_61 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
int V_149 ;
unsigned long V_4 = 0 ;
F_9 ( & V_10 -> V_15 , V_4 ) ;
if ( V_10 -> V_29 )
V_149 = 0 ;
else
V_149 = V_13 -> V_34 - 2 - V_10 -> V_44 ;
F_4 ( & V_10 -> V_15 , V_4 ) ;
F_17 ( L_14 , V_10 -> V_28 , V_149 ) ;
return V_149 ;
}
static int F_46 ( struct V_16 * V_17 )
{
struct V_12 * V_13 = V_17 -> V_61 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
if ( V_10 -> V_29 ) {
F_17 ( L_15 ,
V_10 -> V_28 , V_13 -> V_34 - 2 ) ;
return 256 ;
} else {
F_17 ( L_15 ,
V_10 -> V_28 , V_10 -> V_44 ) ;
return V_10 -> V_44 ;
}
}
static void F_47 ( struct V_12 * V_13 , int V_150 )
{
F_24 ( V_13 , V_150 * ( V_50 | V_54 ) , 1 ) ;
}
static int F_48 ( struct V_16 * V_17 , struct V_12 * V_13 )
{
int V_21 ;
unsigned char V_18 [ 32 ] ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
struct V_65 V_151 ;
if ( F_49 ( V_13 -> V_25 ) != 0 )
return - V_152 ;
V_18 [ 0 ] = V_153 ;
V_18 [ 1 ] = V_10 -> V_28 ;
V_18 [ 2 ] = V_131 ;
V_18 [ 3 ] = 0 ;
V_18 [ 4 ] = V_154 ;
V_18 [ 5 ] = V_10 -> V_28 ;
V_18 [ 6 ] = V_155 | V_156 ;
V_18 [ 7 ] = 0 ;
V_21 = F_14 ( V_13 , V_18 , 8 , 1 ) ;
if ( V_21 != 0 )
F_17 ( L_16 , V_21 ) ;
if ( V_17 ) {
V_151 . V_71 = ~ V_17 -> V_68 -> V_71 ;
V_151 . V_69 = ~ V_17 -> V_68 -> V_69 ;
F_30 ( V_17 , V_13 , & V_151 ) ;
}
return 0 ;
}
static void F_50 ( struct V_12 * V_13 )
{
F_2 ( V_5 ) ;
int V_21 ;
unsigned char V_18 [ 32 ] ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
F_51 ( & V_13 -> V_25 -> V_157 ) ;
if ( V_13 -> V_25 -> V_158 )
goto exit;
if ( V_13 -> V_25 -> V_39 ) {
F_27 ( V_13 , V_159 ) ;
V_18 [ 0 ] = V_124 ;
V_18 [ 1 ] = V_10 -> V_28 ;
V_18 [ 2 ] = V_132 ;
V_18 [ 3 ] = 0 ;
V_18 [ 4 ] = V_129 ;
V_18 [ 5 ] = V_10 -> V_28 ;
V_18 [ 6 ] = V_132 ;
V_18 [ 7 ] = 0 ;
V_18 [ 8 ] = V_153 ;
V_18 [ 9 ] = V_10 -> V_28 ;
V_18 [ 10 ] = V_132 ;
V_18 [ 11 ] = 0 ;
V_18 [ 12 ] = V_133 ;
V_18 [ 13 ] = V_10 -> V_28 ;
V_18 [ 14 ] = V_132 ;
V_18 [ 15 ] = 0 ;
V_18 [ 16 ] = V_154 ;
V_18 [ 17 ] = V_10 -> V_28 ;
V_18 [ 18 ] = V_155 | V_156 ;
V_18 [ 19 ] = 0 ;
V_21 = F_14 ( V_13 , V_18 , 20 , 0 ) ;
if ( V_21 != 0 )
F_17 ( L_17 , V_21 ) ;
F_3 ( & V_10 -> V_160 , & V_5 ,
V_6 ) ;
F_5 ( V_159 ) ;
F_6 ( & V_10 -> V_160 , & V_5 ) ;
F_52 ( V_13 -> V_35 ) ;
}
exit:
F_53 ( & V_10 -> V_15 ) ;
V_10 -> V_29 = 0 ;
F_43 ( & V_10 -> V_161 ) ;
F_54 ( & V_10 -> V_15 ) ;
F_55 ( & V_13 -> V_25 -> V_157 ) ;
}
static int F_49 ( struct V_144 * V_25 )
{
int V_75 , V_21 = 0 ;
struct V_24 * V_145 = F_15 ( V_25 ) ;
struct V_12 * V_13 ;
F_25 ( & V_145 -> V_162 ) ;
if ( V_145 -> V_163 ) {
F_26 ( & V_145 -> V_162 ) ;
return 0 ;
}
V_145 -> V_163 = 1 ;
F_26 ( & V_145 -> V_162 ) ;
for ( V_75 = 0 ; V_75 < V_25 -> type -> V_164 + 1 ; V_75 ++ ) {
V_13 = V_25 -> V_13 [ V_75 ] ;
V_21 = F_20 ( V_13 -> V_64 , V_165 ) ;
if ( V_21 != 0 ) {
F_21 ( & V_13 -> V_39 ,
L_4 ,
V_40 , V_21 , V_75 ) ;
break;
}
}
return V_21 ;
}
static int F_56 ( struct V_144 * V_25 )
{
int V_75 ;
struct V_9 * V_10 ;
struct V_24 * V_145 ;
for ( V_75 = 0 ; V_75 < V_25 -> type -> V_164 + 1 ; V_75 ++ ) {
V_10 = F_57 ( sizeof( struct V_9 ) , V_165 ) ;
if ( V_10 == NULL ) {
while ( -- V_75 >= 0 )
F_58 ( F_16 ( V_25 -> V_13 [ V_75 ] ) ) ;
return 1 ;
}
F_59 ( & V_10 -> V_15 ) ;
V_10 -> V_28 = V_75 ;
V_10 -> V_44 = 0 ;
V_10 -> V_29 = 0 ;
V_10 -> V_57 = 0 ;
F_60 ( & V_10 -> V_166 ) ;
V_10 -> V_58 = 0 ;
F_60 ( & V_10 -> V_60 ) ;
V_10 -> V_62 = 0 ;
V_10 -> V_63 = 0 ;
F_60 ( & V_10 -> V_160 ) ;
F_60 ( & V_10 -> V_161 ) ;
F_61 ( & V_10 -> V_11 , F_7 ) ;
V_10 -> V_14 = V_25 -> V_13 [ V_75 ] ;
F_60 ( & V_25 -> V_13 [ V_75 ] -> V_30 ) ;
F_62 ( V_25 -> V_13 [ V_75 ] , V_10 ) ;
}
V_145 = F_57 ( sizeof( struct V_24 ) , V_165 ) ;
if ( V_145 == NULL ) {
for ( V_75 = 0 ; V_75 < V_25 -> type -> V_164 + 1 ; V_75 ++ )
F_58 ( F_16 ( V_25 -> V_13 [ V_75 ] ) ) ;
return 1 ;
}
F_59 ( & V_145 -> V_162 ) ;
V_145 -> V_147 = V_25 -> type -> V_164 ;
V_145 -> V_26 = V_25 -> V_13 [ V_145 -> V_147 ] ;
V_145 -> V_163 = 0 ;
F_63 ( V_25 , V_145 ) ;
return 0 ;
}
static void F_64 ( struct V_144 * V_25 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_25 -> type -> V_164 + 1 ; V_75 ++ ) {
F_52 ( V_25 -> V_13 [ V_75 ] -> V_64 ) ;
F_52 ( V_25 -> V_13 [ V_75 ] -> V_35 ) ;
}
}
static void F_65 ( struct V_144 * V_25 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_25 -> type -> V_164 + 1 ; V_75 ++ )
F_58 ( F_16 ( V_25 -> V_13 [ V_75 ] ) ) ;
F_58 ( F_15 ( V_25 ) ) ;
}
static void F_66 ( struct V_142 * V_142 )
{
struct V_12 * V_13 = V_142 -> V_143 ;
struct V_9 * V_10 ;
struct V_24 * V_145 ;
int V_21 ;
int V_146 = V_142 -> V_146 ;
if ( V_13 == NULL )
return;
V_10 = F_16 ( V_13 ) ;
if ( V_10 == NULL ) {
F_21 ( & V_13 -> V_39 , L_18 ,
V_40 , V_146 ) ;
return;
}
if ( V_13 -> V_25 == NULL ||
( V_145 = F_15 ( V_13 -> V_25 ) ) == NULL ) {
F_21 ( & V_13 -> V_39 , L_19
L_20 , V_40 , V_146 ) ;
return;
}
if ( V_146 ) {
F_21 ( & V_13 -> V_39 ,
L_21 ,
V_40 , V_146 , V_10 -> V_28 ) ;
return;
}
if ( V_10 -> V_28 == V_145 -> V_147 ) {
if ( F_67 ( V_142 ) != 0 )
return;
} else {
if ( F_68 ( V_142 ) != 0 )
return;
}
V_21 = F_20 ( V_142 , V_38 ) ;
if ( V_21 != 0 && V_21 != - V_148 ) {
F_21 ( & V_13 -> V_39 ,
L_22 ,
V_40 , V_21 , V_10 -> V_28 ) ;
}
}
static int F_68 ( struct V_142 * V_142 )
{
struct V_12 * V_13 = V_142 -> V_143 ;
struct V_16 * V_17 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
int V_167 = ( ( unsigned char * ) V_142 -> V_36 ) [ 0 ] ;
int V_22 = ( ( unsigned char * ) V_142 -> V_36 ) [ 1 ] ;
int V_168 = ( ( unsigned char * ) V_142 -> V_36 ) [ 2 ] ;
unsigned char * V_41 = ( ( unsigned char * ) V_142 -> V_36 ) + 3 ;
int V_169 , V_170 ;
int V_146 = V_142 -> V_146 ;
if ( V_142 -> V_146 == - V_171 )
return 0 ;
if ( V_142 -> V_172 != V_22 + 2 ) {
F_21 ( & V_13 -> V_39 , L_23
L_24
L_25 , V_40 , V_146 ,
V_10 -> V_28 , V_167 , V_22 , V_142 -> V_172 ,
V_168 ) ;
return - 1 ;
}
V_17 = F_11 ( & V_13 -> V_13 ) ;
F_25 ( & V_10 -> V_15 ) ;
V_170 = V_10 -> V_62 ;
if ( V_170 )
V_10 -> V_63 = 1 ;
if ( V_17 && V_167 == V_173 ) {
V_169 = 0 ;
if ( V_168 & V_174 )
F_69 ( V_17 , 0 , V_175 ) ;
if ( V_168 & V_176 )
V_169 = V_177 ;
else if ( V_168 & V_178 )
V_169 = V_179 ;
else if ( V_168 & V_180 )
V_169 = V_181 ;
-- V_22 ;
if ( V_22 > 0 ) {
F_70 ( V_17 , V_41 , V_169 ,
V_22 ) ;
F_71 ( V_17 ) ;
}
}
F_26 ( & V_10 -> V_15 ) ;
F_13 ( V_17 ) ;
if ( V_167 == V_182 )
F_17 ( L_26 , V_40 ) ;
else if ( V_167 != V_173 )
F_17 ( L_27 , V_40 , V_167 ) ;
return V_170 ? 1 : 0 ;
}
static int F_67 ( struct V_142 * V_142 )
{
struct V_12 * V_13 = V_142 -> V_143 ;
struct V_144 * V_25 = V_13 -> V_25 ;
struct V_16 * V_17 ;
struct V_9 * V_10 = F_16 ( V_13 ) ;
int V_167 , line , V_146 , V_136 ;
int V_75 ;
unsigned int V_183 ;
for ( V_75 = 0 ; V_75 < V_142 -> V_172 - 3 ; ) {
V_167 = ( ( unsigned char * ) V_142 -> V_36 ) [ V_75 ++ ] ;
line = ( ( unsigned char * ) V_142 -> V_36 ) [ V_75 ++ ] ;
V_146 = ( ( unsigned char * ) V_142 -> V_36 ) [ V_75 ++ ] ;
V_136 = ( ( unsigned char * ) V_142 -> V_36 ) [ V_75 ++ ] ;
F_17 ( L_28 ,
V_167 , line , V_146 , V_136 ) ;
if ( V_146 != 0 || line >= V_25 -> type -> V_164 )
continue;
V_13 = V_25 -> V_13 [ line ] ;
V_10 = F_16 ( V_13 ) ;
if ( V_10 == NULL )
return - 1 ;
V_17 = F_11 ( & V_13 -> V_13 ) ;
V_183 = 0 ;
if ( V_17 )
V_183 = V_17 -> V_68 -> V_71 & V_79 ;
if ( V_17 && V_167 == V_153 ) {
F_25 ( & V_10 -> V_15 ) ;
if ( V_136 & V_184 ) {
V_10 -> V_57 |= V_185 ;
if ( V_183 ) {
V_17 -> V_128 = 0 ;
F_10 ( V_13 ) ;
}
} else {
V_10 -> V_57 &= ~ V_185 ;
if ( V_183 )
V_17 -> V_128 = 1 ;
}
if ( V_136 & V_186 )
V_10 -> V_57 |= V_187 ;
else
V_10 -> V_57 &= ~ V_187 ;
if ( V_136 & V_188 )
V_10 -> V_57 |= V_189 ;
else
V_10 -> V_57 &= ~ V_189 ;
if ( V_136 & V_190 )
V_10 -> V_57 |= V_191 ;
else
V_10 -> V_57 &= ~ V_191 ;
F_43 ( & V_10 -> V_166 ) ;
F_26 ( & V_10 -> V_15 ) ;
} else if ( V_167 == V_59 ) {
F_25 ( & V_10 -> V_15 ) ;
V_10 -> V_58 = 1 ;
F_43 ( & V_10 -> V_60 ) ;
F_26 ( & V_10 -> V_15 ) ;
} else if ( V_167 == V_154 ) {
F_43 ( & V_10 -> V_160 ) ;
}
F_13 ( V_17 ) ;
}
return 0 ;
}
