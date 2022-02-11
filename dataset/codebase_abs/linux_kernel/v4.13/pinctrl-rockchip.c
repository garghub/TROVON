static inline const struct V_1 * F_1 (
const struct V_2 * V_3 ,
const char * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
if ( ! strcmp ( V_3 -> V_7 [ V_5 ] . V_4 , V_4 ) )
return & V_3 -> V_7 [ V_5 ] ;
}
return NULL ;
}
static struct V_8 * F_2 ( struct V_2 * V_3 ,
unsigned V_9 )
{
struct V_8 * V_10 = V_3 -> V_11 -> V_12 ;
while ( V_9 >= ( V_10 -> V_13 + V_10 -> V_14 ) )
V_10 ++ ;
return V_10 ;
}
static struct V_8 * F_3 (
struct V_2 * V_3 ,
unsigned V_15 )
{
struct V_8 * V_10 = V_3 -> V_11 -> V_12 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_11 -> V_16 ; V_5 ++ , V_10 ++ ) {
if ( V_10 -> V_17 == V_15 )
return V_10 ;
}
return F_4 ( - V_18 ) ;
}
static int F_5 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_6 ;
}
static const char * F_7 ( struct V_19 * V_20 ,
unsigned V_21 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_7 [ V_21 ] . V_4 ;
}
static int F_8 ( struct V_19 * V_20 ,
unsigned V_21 , const unsigned * * V_22 ,
unsigned * V_23 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
if ( V_21 >= V_3 -> V_6 )
return - V_18 ;
* V_22 = V_3 -> V_7 [ V_21 ] . V_22 ;
* V_23 = V_3 -> V_7 [ V_21 ] . V_23 ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 ,
struct V_24 * V_25 ,
struct V_26 * * V_27 , unsigned * V_28 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
const struct V_1 * V_29 ;
struct V_26 * V_30 ;
struct V_24 * V_31 ;
int V_32 = 1 ;
int V_5 ;
V_29 = F_1 ( V_3 , V_25 -> V_4 ) ;
if ( ! V_29 ) {
F_10 ( V_3 -> V_33 , L_1 ,
V_25 -> V_4 ) ;
return - V_18 ;
}
V_32 += V_29 -> V_23 ;
V_30 = F_11 ( V_20 -> V_33 , sizeof( * V_30 ) * V_32 ,
V_34 ) ;
if ( ! V_30 )
return - V_35 ;
* V_27 = V_30 ;
* V_28 = V_32 ;
V_31 = F_12 ( V_25 ) ;
if ( ! V_31 ) {
F_13 ( V_20 -> V_33 , V_30 ) ;
return - V_18 ;
}
V_30 [ 0 ] . type = V_36 ;
V_30 [ 0 ] . V_37 . V_38 . V_39 = V_31 -> V_4 ;
V_30 [ 0 ] . V_37 . V_38 . V_40 = V_25 -> V_4 ;
F_14 ( V_31 ) ;
V_30 ++ ;
for ( V_5 = 0 ; V_5 < V_29 -> V_23 ; V_5 ++ ) {
V_30 [ V_5 ] . type = V_41 ;
V_30 [ V_5 ] . V_37 . V_42 . V_43 =
F_15 ( V_20 , V_29 -> V_22 [ V_5 ] ) ;
V_30 [ V_5 ] . V_37 . V_42 . V_42 = V_29 -> V_37 [ V_5 ] . V_42 ;
V_30 [ V_5 ] . V_37 . V_42 . V_44 = V_29 -> V_37 [ V_5 ] . V_45 ;
}
F_16 ( V_20 -> V_33 , L_2 ,
( * V_27 ) -> V_37 . V_38 . V_39 , ( * V_27 ) -> V_37 . V_38 . V_40 , V_32 ) ;
return 0 ;
}
static void F_17 ( struct V_19 * V_20 ,
struct V_26 * V_27 , unsigned V_28 )
{
}
static void F_18 ( T_1 V_17 , int V_9 , int * V_46 ,
T_1 * V_47 , int * V_48 )
{
const struct V_49 * V_37 = NULL ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_19 ( V_50 ) ; V_5 ++ )
if ( V_50 [ V_5 ] . V_15 == V_17 &&
V_50 [ V_5 ] . V_9 == V_9 ) {
V_37 = & V_50 [ V_5 ] ;
break;
}
if ( ! V_37 )
return;
* V_46 = V_37 -> V_46 ;
* V_48 = V_37 -> V_48 ;
* V_47 = V_37 -> V_47 ;
}
static bool F_20 ( struct V_8 * V_51 , int V_9 ,
int V_38 , T_2 * V_46 , T_2 * V_52 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
struct V_54 * V_11 = V_3 -> V_11 ;
struct V_55 * V_37 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_56 ; V_5 ++ ) {
V_37 = & V_11 -> V_57 [ V_5 ] ;
if ( ( V_37 -> V_17 == V_51 -> V_17 ) &&
( V_37 -> V_9 == V_9 ) && ( V_37 -> V_58 == V_38 ) )
break;
}
if ( V_5 >= V_11 -> V_56 )
return false ;
* V_46 = V_37 -> V_59 ;
* V_52 = V_37 -> V_60 ;
return true ;
}
static int F_21 ( struct V_8 * V_51 , int V_9 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
struct V_54 * V_11 = V_3 -> V_11 ;
int V_61 = ( V_9 / 8 ) ;
struct V_62 * V_62 ;
unsigned int V_63 ;
int V_46 , V_64 , V_48 , V_65 ;
T_1 V_47 ;
if ( V_61 > 3 )
return - V_18 ;
if ( V_51 -> V_66 [ V_61 ] . type & V_67 ) {
F_10 ( V_3 -> V_33 , L_3 , V_9 ) ;
return - V_18 ;
}
if ( V_51 -> V_66 [ V_61 ] . type & V_68 )
return V_69 ;
V_62 = ( V_51 -> V_66 [ V_61 ] . type & V_70 )
? V_3 -> V_71 : V_3 -> V_72 ;
V_65 = V_51 -> V_66 [ V_61 ] . type ;
V_46 = V_51 -> V_66 [ V_61 ] . V_73 ;
if ( V_65 & V_74 ) {
if ( ( V_9 % 8 ) >= 4 )
V_46 += 0x4 ;
V_47 = ( V_9 % 4 ) * 4 ;
V_48 = 0xf ;
} else if ( V_65 & V_75 ) {
if ( ( V_9 % 8 ) >= 5 )
V_46 += 0x4 ;
V_47 = ( V_9 % 8 % 5 ) * 3 ;
V_48 = 0x7 ;
} else {
V_47 = ( V_9 % 8 ) * 2 ;
V_48 = 0x3 ;
}
if ( V_11 -> V_76 && ( V_65 & V_77 ) )
V_11 -> V_76 ( V_51 -> V_17 , V_9 , & V_46 , & V_47 , & V_48 ) ;
V_64 = F_22 ( V_62 , V_46 , & V_63 ) ;
if ( V_64 )
return V_64 ;
return ( ( V_63 >> V_47 ) & V_48 ) ;
}
static int F_23 ( struct V_8 * V_51 ,
int V_9 , int V_38 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
int V_61 = ( V_9 / 8 ) ;
if ( V_61 > 3 )
return - V_18 ;
if ( V_51 -> V_66 [ V_61 ] . type & V_67 ) {
F_10 ( V_3 -> V_33 , L_3 , V_9 ) ;
return - V_18 ;
}
if ( V_51 -> V_66 [ V_61 ] . type & V_68 ) {
if ( V_38 != V_69 ) {
F_10 ( V_3 -> V_33 ,
L_4 , V_9 ) ;
return - V_78 ;
}
}
return 0 ;
}
static int F_24 ( struct V_8 * V_51 , int V_9 , int V_38 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
struct V_54 * V_11 = V_3 -> V_11 ;
int V_61 = ( V_9 / 8 ) ;
struct V_62 * V_62 ;
int V_46 , V_64 , V_48 , V_65 ;
T_1 V_47 ;
T_2 V_37 , V_79 , V_80 , V_60 ;
V_64 = F_23 ( V_51 , V_9 , V_38 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( V_51 -> V_66 [ V_61 ] . type & V_68 )
return 0 ;
F_16 ( V_3 -> V_33 , L_5 ,
V_51 -> V_17 , V_9 , V_38 ) ;
V_62 = ( V_51 -> V_66 [ V_61 ] . type & V_70 )
? V_3 -> V_71 : V_3 -> V_72 ;
V_65 = V_51 -> V_66 [ V_61 ] . type ;
V_46 = V_51 -> V_66 [ V_61 ] . V_73 ;
if ( V_65 & V_74 ) {
if ( ( V_9 % 8 ) >= 4 )
V_46 += 0x4 ;
V_47 = ( V_9 % 4 ) * 4 ;
V_48 = 0xf ;
} else if ( V_65 & V_75 ) {
if ( ( V_9 % 8 ) >= 5 )
V_46 += 0x4 ;
V_47 = ( V_9 % 8 % 5 ) * 3 ;
V_48 = 0x7 ;
} else {
V_47 = ( V_9 % 8 ) * 2 ;
V_48 = 0x3 ;
}
if ( V_11 -> V_76 && ( V_65 & V_77 ) )
V_11 -> V_76 ( V_51 -> V_17 , V_9 , & V_46 , & V_47 , & V_48 ) ;
if ( V_51 -> V_81 & F_25 ( V_9 ) ) {
if ( F_20 ( V_51 , V_9 , V_38 , & V_80 ,
& V_60 ) ) {
V_64 = F_26 ( V_62 , V_80 , V_60 ) ;
if ( V_64 )
return V_64 ;
}
}
V_37 = ( V_48 << ( V_47 + 16 ) ) ;
V_79 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_38 & V_48 ) << V_47 ;
V_64 = F_27 ( V_62 , V_46 , V_79 , V_37 ) ;
return V_64 ;
}
static void F_28 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
if ( V_51 -> V_17 == 0 ) {
* V_62 = V_3 -> V_71 ;
* V_46 = V_83 ;
} else {
* V_46 = V_84 ;
* V_62 = V_3 -> V_72 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_85 ;
}
* V_46 += ( ( V_82 / V_86 ) * 4 ) ;
* V_47 = ( V_82 % V_86 ) ;
* V_47 *= V_87 ;
}
static void F_29 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
if ( V_51 -> V_17 == 0 ) {
* V_62 = V_3 -> V_71 ;
* V_46 = V_88 ;
} else {
* V_62 = V_3 -> V_72 ;
* V_46 = V_89 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_90 ;
}
* V_46 += ( ( V_82 / V_91 ) * 4 ) ;
* V_47 = V_82 % V_91 ;
* V_47 *= V_92 ;
}
static void F_30 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
* V_62 = V_3 -> V_72 ;
* V_46 = V_93 ;
* V_46 += V_51 -> V_17 * V_94 ;
* V_46 += ( V_82 / V_95 ) * 4 ;
* V_47 = V_82 % V_95 ;
}
static void F_31 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
if ( V_51 -> V_17 == 0 && V_82 < 12 ) {
* V_62 = V_3 -> V_71 ? V_3 -> V_71
: V_51 -> V_96 ;
* V_46 = V_3 -> V_71 ? V_97 : 0 ;
* V_46 += ( ( V_82 / V_98 ) * 4 ) ;
* V_47 = V_82 % V_98 ;
* V_47 *= V_99 ;
} else {
* V_62 = V_3 -> V_96 ? V_3 -> V_96
: V_3 -> V_72 ;
* V_46 = V_3 -> V_96 ? 0 : V_100 ;
* V_46 -= 4 ;
* V_46 += V_51 -> V_17 * V_101 ;
* V_46 += ( ( V_82 / V_98 ) * 4 ) ;
* V_47 = 7 - ( V_82 % V_98 ) ;
* V_47 *= V_99 ;
}
}
static void F_32 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
if ( V_51 -> V_17 == 0 ) {
* V_62 = V_3 -> V_71 ;
* V_46 = V_97 ;
* V_46 += ( ( V_82 / V_98 ) * 4 ) ;
* V_47 = V_82 % V_98 ;
* V_47 *= V_99 ;
} else {
* V_62 = V_3 -> V_72 ;
* V_46 = V_102 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_101 ;
* V_46 += ( ( V_82 / V_98 ) * 4 ) ;
* V_47 = ( V_82 % V_98 ) ;
* V_47 *= V_99 ;
}
}
static void F_33 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
if ( V_51 -> V_17 == 0 ) {
* V_62 = V_3 -> V_71 ;
* V_46 = V_103 ;
* V_46 += ( ( V_82 / V_104 ) * 4 ) ;
* V_47 = V_82 % V_104 ;
* V_47 *= V_105 ;
} else {
* V_62 = V_3 -> V_72 ;
* V_46 = V_106 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_107 ;
* V_46 += ( ( V_82 / V_104 ) * 4 ) ;
* V_47 = ( V_82 % V_104 ) ;
* V_47 *= V_105 ;
}
}
static void F_34 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
* V_62 = V_3 -> V_72 ;
* V_46 = V_108 ;
* V_46 += V_51 -> V_17 * V_101 ;
* V_46 += ( ( V_82 / V_98 ) * 4 ) ;
* V_47 = ( V_82 % V_98 ) ;
* V_47 *= V_99 ;
}
static void F_35 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
* V_62 = V_3 -> V_72 ;
* V_46 = V_109 ;
* V_46 += V_51 -> V_17 * V_107 ;
* V_46 += ( ( V_82 / V_104 ) * 4 ) ;
* V_47 = ( V_82 % V_104 ) ;
* V_47 *= V_105 ;
}
static void F_36 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
if ( V_51 -> V_17 == 0 ) {
* V_62 = V_3 -> V_71 ;
* V_46 = V_110 ;
* V_46 += ( ( V_82 / V_98 ) * 4 ) ;
* V_47 = V_82 % V_98 ;
* V_47 *= V_99 ;
} else {
* V_62 = V_3 -> V_72 ;
* V_46 = V_111 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_101 ;
* V_46 += ( ( V_82 / V_98 ) * 4 ) ;
* V_47 = ( V_82 % V_98 ) ;
* V_47 *= V_99 ;
}
}
static void F_37 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
if ( V_51 -> V_17 == 0 ) {
* V_62 = V_3 -> V_71 ;
* V_46 = V_112 ;
* V_46 += ( ( V_82 / V_104 ) * 4 ) ;
* V_47 = V_82 % V_104 ;
* V_47 *= V_105 ;
} else {
* V_62 = V_3 -> V_72 ;
* V_46 = V_113 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_107 ;
* V_46 += ( ( V_82 / V_104 ) * 4 ) ;
* V_47 = ( V_82 % V_104 ) ;
* V_47 *= V_105 ;
}
}
static void F_38 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
if ( ( V_51 -> V_17 == 0 ) || ( V_51 -> V_17 == 1 ) ) {
* V_62 = V_3 -> V_71 ;
* V_46 = V_114 ;
* V_46 += V_51 -> V_17 * V_101 ;
* V_46 += ( ( V_82 / V_98 ) * 4 ) ;
* V_47 = V_82 % V_98 ;
* V_47 *= V_99 ;
} else {
* V_62 = V_3 -> V_72 ;
* V_46 = V_115 ;
* V_46 -= 0x20 ;
* V_46 += V_51 -> V_17 * V_101 ;
* V_46 += ( ( V_82 / V_98 ) * 4 ) ;
* V_47 = ( V_82 % V_98 ) ;
* V_47 *= V_99 ;
}
}
static void F_39 ( struct V_8 * V_51 ,
int V_82 , struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
int V_116 = ( V_82 / 8 ) ;
if ( ( V_51 -> V_17 == 0 ) || ( V_51 -> V_17 == 1 ) )
* V_62 = V_3 -> V_71 ;
else
* V_62 = V_3 -> V_72 ;
* V_46 = V_51 -> V_117 [ V_116 ] . V_73 ;
if ( ( V_51 -> V_117 [ V_116 ] . V_118 == V_119 ) ||
( V_51 -> V_117 [ V_116 ] . V_118 == V_120 ) )
* V_47 = ( V_82 % 8 ) * 3 ;
else
* V_47 = ( V_82 % 8 ) * 2 ;
}
static int F_40 ( struct V_8 * V_51 ,
int V_82 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
struct V_54 * V_11 = V_3 -> V_11 ;
struct V_62 * V_62 ;
int V_46 , V_64 ;
T_2 V_37 , V_121 , V_122 ;
T_1 V_47 ;
int V_118 = V_51 -> V_117 [ V_82 / 8 ] . V_118 ;
V_11 -> V_123 ( V_51 , V_82 , & V_62 , & V_46 , & V_47 ) ;
switch ( V_118 ) {
case V_119 :
case V_120 :
V_122 = V_124 ;
switch ( V_47 ) {
case 0 ... 12 :
break;
case 15 :
V_64 = F_22 ( V_62 , V_46 , & V_37 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_22 ( V_62 , V_46 + 0x4 , & V_121 ) ;
if ( V_64 )
return V_64 ;
V_37 >>= 15 ;
V_121 &= 0x3 ;
V_121 <<= 1 ;
V_37 |= V_121 ;
return V_125 [ V_118 ] [ V_37 ] ;
case 18 ... 21 :
V_46 += 4 ;
V_47 -= 16 ;
break;
default:
F_10 ( V_3 -> V_33 , L_6 ,
V_47 , V_118 ) ;
return - V_18 ;
}
break;
case V_126 :
case V_127 :
case V_128 :
V_122 = V_105 ;
break;
default:
F_10 ( V_3 -> V_33 , L_7 ,
V_118 ) ;
return - V_18 ;
}
V_64 = F_22 ( V_62 , V_46 , & V_37 ) ;
if ( V_64 )
return V_64 ;
V_37 >>= V_47 ;
V_37 &= ( 1 << V_122 ) - 1 ;
return V_125 [ V_118 ] [ V_37 ] ;
}
static int F_41 ( struct V_8 * V_51 ,
int V_82 , int V_129 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
struct V_54 * V_11 = V_3 -> V_11 ;
struct V_62 * V_62 ;
int V_46 , V_64 , V_5 ;
T_2 V_37 , V_79 , V_122 , V_121 ;
T_1 V_47 ;
int V_118 = V_51 -> V_117 [ V_82 / 8 ] . V_118 ;
F_16 ( V_3 -> V_33 , L_8 ,
V_51 -> V_17 , V_82 , V_129 ) ;
V_11 -> V_123 ( V_51 , V_82 , & V_62 , & V_46 , & V_47 ) ;
V_64 = - V_18 ;
for ( V_5 = 0 ; V_5 < F_19 ( V_125 [ V_118 ] ) ; V_5 ++ ) {
if ( V_125 [ V_118 ] [ V_5 ] == V_129 ) {
V_64 = V_5 ;
break;
} else if ( V_125 [ V_118 ] [ V_5 ] < 0 ) {
V_64 = V_125 [ V_118 ] [ V_5 ] ;
break;
}
}
if ( V_64 < 0 ) {
F_10 ( V_3 -> V_33 , L_9 ,
V_129 ) ;
return V_64 ;
}
switch ( V_118 ) {
case V_119 :
case V_120 :
V_122 = V_124 ;
switch ( V_47 ) {
case 0 ... 12 :
break;
case 15 :
V_37 = ( V_64 & 0x1 ) << 15 ;
V_121 = ( V_64 >> 0x1 ) & 0x3 ;
V_79 = F_25 ( 15 ) | F_25 ( 31 ) ;
V_37 |= F_25 ( 31 ) ;
V_64 = F_27 ( V_62 , V_46 , V_79 , V_37 ) ;
if ( V_64 )
return V_64 ;
V_79 = 0x3 | ( 0x3 << 16 ) ;
V_121 |= ( 0x3 << 16 ) ;
V_46 += 0x4 ;
V_64 = F_27 ( V_62 , V_46 , V_79 , V_121 ) ;
return V_64 ;
case 18 ... 21 :
V_46 += 4 ;
V_47 -= 16 ;
break;
default:
F_10 ( V_3 -> V_33 , L_6 ,
V_47 , V_118 ) ;
return - V_18 ;
}
break;
case V_126 :
case V_127 :
case V_128 :
V_122 = V_105 ;
break;
default:
F_10 ( V_3 -> V_33 , L_7 ,
V_118 ) ;
return - V_18 ;
}
V_37 = ( ( 1 << V_122 ) - 1 ) << ( V_47 + 16 ) ;
V_79 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_64 << V_47 ) ;
V_64 = F_27 ( V_62 , V_46 , V_79 , V_37 ) ;
return V_64 ;
}
static int F_42 ( struct V_8 * V_51 , int V_82 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
struct V_54 * V_11 = V_3 -> V_11 ;
struct V_62 * V_62 ;
int V_46 , V_64 , V_130 ;
T_1 V_47 ;
T_2 V_37 ;
if ( V_11 -> type == V_131 )
return V_132 ;
V_11 -> V_133 ( V_51 , V_82 , & V_62 , & V_46 , & V_47 ) ;
V_64 = F_22 ( V_62 , V_46 , & V_37 ) ;
if ( V_64 )
return V_64 ;
switch ( V_11 -> type ) {
case V_134 :
return ! ( V_37 & F_25 ( V_47 ) )
? V_135
: V_132 ;
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
V_130 = V_51 -> V_130 [ V_82 / 8 ] ;
V_37 >>= V_47 ;
V_37 &= ( 1 << V_99 ) - 1 ;
return V_141 [ V_130 ] [ V_37 ] ;
default:
F_10 ( V_3 -> V_33 , L_10 ) ;
return - V_18 ;
} ;
}
static int F_43 ( struct V_8 * V_51 ,
int V_82 , int V_142 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
struct V_54 * V_11 = V_3 -> V_11 ;
struct V_62 * V_62 ;
int V_46 , V_64 , V_5 , V_130 ;
T_1 V_47 ;
T_2 V_37 , V_79 ;
F_16 ( V_3 -> V_33 , L_11 ,
V_51 -> V_17 , V_82 , V_142 ) ;
if ( V_11 -> type == V_131 )
return V_142 ? - V_18 : 0 ;
V_11 -> V_133 ( V_51 , V_82 , & V_62 , & V_46 , & V_47 ) ;
switch ( V_11 -> type ) {
case V_134 :
V_37 = F_25 ( V_47 + 16 ) ;
if ( V_142 == V_132 )
V_37 |= F_25 ( V_47 ) ;
V_64 = F_26 ( V_62 , V_46 , V_37 ) ;
break;
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
V_130 = V_51 -> V_130 [ V_82 / 8 ] ;
V_64 = - V_18 ;
for ( V_5 = 0 ; V_5 < F_19 ( V_141 [ V_130 ] ) ;
V_5 ++ ) {
if ( V_141 [ V_130 ] [ V_5 ] == V_142 ) {
V_64 = V_5 ;
break;
}
}
if ( V_64 < 0 ) {
F_10 ( V_3 -> V_33 , L_12 ,
V_142 ) ;
return V_64 ;
}
V_37 = ( ( 1 << V_99 ) - 1 ) << ( V_47 + 16 ) ;
V_79 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_64 << V_47 ) ;
V_64 = F_27 ( V_62 , V_46 , V_79 , V_37 ) ;
break;
default:
F_10 ( V_3 -> V_33 , L_10 ) ;
return - V_18 ;
}
return V_64 ;
}
static int F_44 ( struct V_8 * V_51 ,
int V_82 ,
struct V_62 * * V_62 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
* V_62 = V_3 -> V_72 ;
* V_46 = V_143 ;
* V_46 += V_51 -> V_17 * V_144 ;
* V_46 += ( ( V_82 / V_145 ) * 4 ) ;
* V_47 = V_82 % V_145 ;
return 0 ;
}
static int F_45 ( struct V_8 * V_51 , int V_82 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
struct V_54 * V_11 = V_3 -> V_11 ;
struct V_62 * V_62 ;
int V_46 , V_64 ;
T_1 V_47 ;
T_2 V_37 ;
V_64 = V_11 -> V_146 ( V_51 , V_82 , & V_62 , & V_46 , & V_47 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_22 ( V_62 , V_46 , & V_37 ) ;
if ( V_64 )
return V_64 ;
V_37 >>= V_47 ;
return V_37 & 0x1 ;
}
static int F_46 ( struct V_8 * V_51 ,
int V_82 , int V_147 )
{
struct V_2 * V_3 = V_51 -> V_53 ;
struct V_54 * V_11 = V_3 -> V_11 ;
struct V_62 * V_62 ;
int V_46 , V_64 ;
T_1 V_47 ;
T_2 V_37 , V_79 ;
F_16 ( V_3 -> V_33 , L_13 ,
V_51 -> V_17 , V_82 , V_147 ) ;
V_64 = V_11 -> V_146 ( V_51 , V_82 , & V_62 , & V_46 , & V_47 ) ;
if ( V_64 )
return V_64 ;
V_37 = F_25 ( V_47 + 16 ) | ( V_147 << V_47 ) ;
V_79 = F_25 ( V_47 + 16 ) | F_25 ( V_47 ) ;
return F_27 ( V_62 , V_46 , V_79 , V_37 ) ;
}
static int F_47 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_148 ;
}
static const char * F_48 ( struct V_19 * V_20 ,
unsigned V_21 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_149 [ V_21 ] . V_4 ;
}
static int F_49 ( struct V_19 * V_20 ,
unsigned V_21 , const char * const * * V_7 ,
unsigned * const V_150 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
* V_7 = V_3 -> V_149 [ V_21 ] . V_7 ;
* V_150 = V_3 -> V_149 [ V_21 ] . V_6 ;
return 0 ;
}
static int F_50 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_40 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
const unsigned int * V_22 = V_3 -> V_7 [ V_40 ] . V_22 ;
const struct V_151 * V_37 = V_3 -> V_7 [ V_40 ] . V_37 ;
struct V_8 * V_51 ;
int V_152 , V_64 = 0 ;
F_16 ( V_3 -> V_33 , L_14 ,
V_3 -> V_149 [ V_21 ] . V_4 , V_3 -> V_7 [ V_40 ] . V_4 ) ;
for ( V_152 = 0 ; V_152 < V_3 -> V_7 [ V_40 ] . V_23 ; V_152 ++ ) {
V_51 = F_2 ( V_3 , V_22 [ V_152 ] ) ;
V_64 = F_24 ( V_51 , V_22 [ V_152 ] - V_51 -> V_13 ,
V_37 [ V_152 ] . V_58 ) ;
if ( V_64 )
break;
}
if ( V_64 ) {
for ( V_152 -- ; V_152 >= 0 ; V_152 -- )
F_24 ( V_51 , V_22 [ V_152 ] - V_51 -> V_13 , 0 ) ;
return V_64 ;
}
return 0 ;
}
static int F_51 ( struct V_153 * V_154 , unsigned V_73 )
{
struct V_8 * V_51 = F_52 ( V_154 ) ;
T_2 V_37 ;
V_37 = F_53 ( V_51 -> V_155 + V_156 ) ;
return ! ( V_37 & F_25 ( V_73 ) ) ;
}
static int F_54 ( struct V_153 * V_154 ,
int V_9 , bool V_157 )
{
struct V_8 * V_51 ;
int V_64 ;
unsigned long V_158 ;
T_2 V_37 ;
V_51 = F_52 ( V_154 ) ;
V_64 = F_24 ( V_51 , V_9 , V_69 ) ;
if ( V_64 < 0 )
return V_64 ;
F_55 ( V_51 -> V_159 ) ;
F_56 ( & V_51 -> V_160 , V_158 ) ;
V_37 = F_53 ( V_51 -> V_155 + V_156 ) ;
if ( ! V_157 )
V_37 |= F_25 ( V_9 ) ;
else
V_37 &= ~ F_25 ( V_9 ) ;
F_57 ( V_37 , V_51 -> V_155 + V_156 ) ;
F_58 ( & V_51 -> V_160 , V_158 ) ;
F_59 ( V_51 -> V_159 ) ;
return 0 ;
}
static int F_60 ( struct V_19 * V_20 ,
struct V_161 * V_162 ,
unsigned V_73 , bool V_157 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_153 * V_154 ;
int V_9 ;
V_154 = V_162 -> V_163 ;
V_9 = V_73 - V_154 -> V_164 ;
F_16 ( V_3 -> V_33 , L_15 ,
V_73 , V_162 -> V_4 , V_9 , V_157 ? L_16 : L_17 ) ;
return F_54 ( V_154 , V_73 - V_154 -> V_164 ,
V_157 ) ;
}
static bool F_61 ( struct V_54 * V_11 ,
enum V_165 V_142 )
{
switch ( V_11 -> type ) {
case V_134 :
return ( V_142 == V_135 ||
V_142 == V_132 ) ;
case V_131 :
return V_142 ? false : true ;
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
return ( V_142 != V_135 ) ;
}
return false ;
}
static int F_62 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_42 , unsigned V_44 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_51 = F_2 ( V_3 , V_9 ) ;
enum V_165 V_166 ;
T_2 V_167 ;
int V_5 ;
int V_168 ;
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ ) {
V_166 = F_63 ( V_42 [ V_5 ] ) ;
V_167 = F_64 ( V_42 [ V_5 ] ) ;
switch ( V_166 ) {
case V_132 :
V_168 = F_43 ( V_51 , V_9 - V_51 -> V_13 ,
V_166 ) ;
if ( V_168 )
return V_168 ;
break;
case V_169 :
case V_170 :
case V_135 :
case V_171 :
if ( ! F_61 ( V_3 -> V_11 , V_166 ) )
return - V_78 ;
if ( ! V_167 )
return - V_18 ;
V_168 = F_43 ( V_51 , V_9 - V_51 -> V_13 ,
V_166 ) ;
if ( V_168 )
return V_168 ;
break;
case V_172 :
F_65 ( & V_51 -> V_153 ,
V_9 - V_51 -> V_13 , V_167 ) ;
V_168 = F_54 ( & V_51 -> V_153 ,
V_9 - V_51 -> V_13 , false ) ;
if ( V_168 )
return V_168 ;
break;
case V_173 :
if ( ! V_3 -> V_11 -> V_123 )
return - V_78 ;
V_168 = F_41 ( V_51 ,
V_9 - V_51 -> V_13 , V_167 ) ;
if ( V_168 < 0 )
return V_168 ;
break;
case V_174 :
if ( ! V_3 -> V_11 -> V_146 )
return - V_78 ;
V_168 = F_46 ( V_51 ,
V_9 - V_51 -> V_13 , V_167 ) ;
if ( V_168 < 0 )
return V_168 ;
break;
default:
return - V_78 ;
break;
}
}
return 0 ;
}
static int F_66 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_175 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_51 = F_2 ( V_3 , V_9 ) ;
enum V_165 V_166 = F_63 ( * V_175 ) ;
T_3 V_167 ;
int V_168 ;
switch ( V_166 ) {
case V_132 :
if ( F_42 ( V_51 , V_9 - V_51 -> V_13 ) != V_166 )
return - V_18 ;
V_167 = 0 ;
break;
case V_169 :
case V_170 :
case V_135 :
case V_171 :
if ( ! F_61 ( V_3 -> V_11 , V_166 ) )
return - V_78 ;
if ( F_42 ( V_51 , V_9 - V_51 -> V_13 ) != V_166 )
return - V_18 ;
V_167 = 1 ;
break;
case V_172 :
V_168 = F_21 ( V_51 , V_9 - V_51 -> V_13 ) ;
if ( V_168 != V_69 )
return - V_18 ;
V_168 = F_67 ( & V_51 -> V_153 , V_9 - V_51 -> V_13 ) ;
if ( V_168 < 0 )
return V_168 ;
V_167 = V_168 ? 1 : 0 ;
break;
case V_173 :
if ( ! V_3 -> V_11 -> V_123 )
return - V_78 ;
V_168 = F_40 ( V_51 , V_9 - V_51 -> V_13 ) ;
if ( V_168 < 0 )
return V_168 ;
V_167 = V_168 ;
break;
case V_174 :
if ( ! V_3 -> V_11 -> V_146 )
return - V_78 ;
V_168 = F_45 ( V_51 , V_9 - V_51 -> V_13 ) ;
if ( V_168 < 0 )
return V_168 ;
V_167 = V_168 ;
break;
default:
return - V_78 ;
break;
}
* V_175 = F_68 ( V_166 , V_167 ) ;
return 0 ;
}
static void F_69 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_24 * V_176 ;
F_70 (np, child) {
if ( F_71 ( V_177 , V_176 ) )
continue;
V_3 -> V_148 ++ ;
V_3 -> V_6 += F_72 ( V_176 ) ;
}
}
static int F_73 ( struct V_24 * V_25 ,
struct V_1 * V_29 ,
struct V_2 * V_3 ,
T_2 V_178 )
{
struct V_8 * V_51 ;
int V_179 ;
const T_4 * V_180 ;
int V_15 ;
int V_5 , V_181 ;
int V_64 ;
F_16 ( V_3 -> V_33 , L_18 , V_178 , V_25 -> V_4 ) ;
V_29 -> V_4 = V_25 -> V_4 ;
V_180 = F_74 ( V_25 , L_19 , & V_179 ) ;
V_179 /= sizeof( * V_180 ) ;
if ( ! V_179 || V_179 % 4 ) {
F_10 ( V_3 -> V_33 , L_20 ) ;
return - V_18 ;
}
V_29 -> V_23 = V_179 / 4 ;
V_29 -> V_22 = F_11 ( V_3 -> V_33 , V_29 -> V_23 * sizeof( unsigned int ) ,
V_34 ) ;
V_29 -> V_37 = F_11 ( V_3 -> V_33 , V_29 -> V_23 *
sizeof( struct V_151 ) ,
V_34 ) ;
if ( ! V_29 -> V_22 || ! V_29 -> V_37 )
return - V_35 ;
for ( V_5 = 0 , V_181 = 0 ; V_5 < V_179 ; V_5 += 4 , V_181 ++ ) {
const T_4 * V_182 ;
struct V_24 * V_183 ;
V_15 = F_75 ( * V_180 ++ ) ;
V_51 = F_3 ( V_3 , V_15 ) ;
if ( F_76 ( V_51 ) )
return F_77 ( V_51 ) ;
V_29 -> V_22 [ V_181 ] = V_51 -> V_13 + F_75 ( * V_180 ++ ) ;
V_29 -> V_37 [ V_181 ] . V_58 = F_75 ( * V_180 ++ ) ;
V_182 = V_180 ++ ;
if ( ! V_182 )
return - V_18 ;
V_183 = F_78 ( F_79 ( V_182 ) ) ;
V_64 = F_80 ( V_183 , NULL ,
& V_29 -> V_37 [ V_181 ] . V_42 , & V_29 -> V_37 [ V_181 ] . V_45 ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
static int F_81 ( struct V_24 * V_25 ,
struct V_2 * V_3 ,
T_2 V_178 )
{
struct V_24 * V_176 ;
struct V_184 * V_58 ;
struct V_1 * V_29 ;
int V_64 ;
static T_2 V_185 ;
T_2 V_5 = 0 ;
F_16 ( V_3 -> V_33 , L_21 , V_178 , V_25 -> V_4 ) ;
V_58 = & V_3 -> V_149 [ V_178 ] ;
V_58 -> V_4 = V_25 -> V_4 ;
V_58 -> V_6 = F_72 ( V_25 ) ;
if ( V_58 -> V_6 <= 0 )
return 0 ;
V_58 -> V_7 = F_11 ( V_3 -> V_33 ,
V_58 -> V_6 * sizeof( char * ) , V_34 ) ;
if ( ! V_58 -> V_7 )
return - V_35 ;
F_70 (np, child) {
V_58 -> V_7 [ V_5 ] = V_176 -> V_4 ;
V_29 = & V_3 -> V_7 [ V_185 ++ ] ;
V_64 = F_73 ( V_176 , V_29 , V_3 , V_5 ++ ) ;
if ( V_64 ) {
F_14 ( V_176 ) ;
return V_64 ;
}
}
return 0 ;
}
static int F_82 ( struct V_186 * V_187 ,
struct V_2 * V_3 )
{
struct V_188 * V_33 = & V_187 -> V_33 ;
struct V_24 * V_25 = V_33 -> V_189 ;
struct V_24 * V_176 ;
int V_64 ;
int V_5 ;
F_69 ( V_3 , V_25 ) ;
F_16 ( & V_187 -> V_33 , L_22 , V_3 -> V_148 ) ;
F_16 ( & V_187 -> V_33 , L_23 , V_3 -> V_6 ) ;
V_3 -> V_149 = F_11 ( V_33 , V_3 -> V_148 *
sizeof( struct V_184 ) ,
V_34 ) ;
if ( ! V_3 -> V_149 ) {
F_10 ( V_33 , L_24 ) ;
return - V_18 ;
}
V_3 -> V_7 = F_11 ( V_33 , V_3 -> V_6 *
sizeof( struct V_1 ) ,
V_34 ) ;
if ( ! V_3 -> V_7 ) {
F_10 ( V_33 , L_25 ) ;
return - V_18 ;
}
V_5 = 0 ;
F_70 (np, child) {
if ( F_71 ( V_177 , V_176 ) )
continue;
V_64 = F_81 ( V_176 , V_3 , V_5 ++ ) ;
if ( V_64 ) {
F_10 ( & V_187 -> V_33 , L_26 ) ;
F_14 ( V_176 ) ;
return V_64 ;
}
}
return 0 ;
}
static int F_83 ( struct V_186 * V_187 ,
struct V_2 * V_3 )
{
struct V_190 * V_191 = & V_3 -> V_192 ;
struct V_193 * V_194 , * V_195 ;
struct V_8 * V_196 ;
int V_9 , V_51 , V_64 ;
int V_197 ;
V_191 -> V_4 = L_27 ;
V_191 -> V_198 = V_199 ;
V_191 -> V_200 = & V_201 ;
V_191 -> V_202 = & V_203 ;
V_191 -> V_204 = & V_205 ;
V_194 = F_11 ( & V_187 -> V_33 , sizeof( * V_194 ) *
V_3 -> V_11 -> V_14 , V_34 ) ;
if ( ! V_194 ) {
F_10 ( & V_187 -> V_33 , L_28 ) ;
return - V_35 ;
}
V_191 -> V_22 = V_194 ;
V_191 -> V_23 = V_3 -> V_11 -> V_14 ;
V_195 = V_194 ;
for ( V_51 = 0 , V_197 = 0 ; V_51 < V_3 -> V_11 -> V_16 ; V_51 ++ ) {
V_196 = & V_3 -> V_11 -> V_12 [ V_51 ] ;
for ( V_9 = 0 ; V_9 < V_196 -> V_14 ; V_9 ++ , V_197 ++ ) {
V_195 -> V_206 = V_197 ;
V_195 -> V_4 = F_84 ( V_34 , L_29 ,
V_196 -> V_4 , V_9 ) ;
V_195 ++ ;
}
}
V_64 = F_82 ( V_187 , V_3 ) ;
if ( V_64 )
return V_64 ;
V_3 -> V_207 = F_85 ( & V_187 -> V_33 , V_191 , V_3 ) ;
if ( F_76 ( V_3 -> V_207 ) ) {
F_10 ( & V_187 -> V_33 , L_30 ) ;
return F_77 ( V_3 -> V_207 ) ;
}
for ( V_51 = 0 ; V_51 < V_3 -> V_11 -> V_16 ; ++ V_51 ) {
V_196 = & V_3 -> V_11 -> V_12 [ V_51 ] ;
V_196 -> V_208 . V_4 = V_196 -> V_4 ;
V_196 -> V_208 . V_209 = V_51 ;
V_196 -> V_208 . V_13 = V_196 -> V_13 ;
V_196 -> V_208 . V_164 = V_196 -> V_153 . V_164 ;
V_196 -> V_208 . V_23 = V_196 -> V_153 . V_210 ;
V_196 -> V_208 . V_163 = & V_196 -> V_153 ;
F_86 ( V_3 -> V_207 , & V_196 -> V_208 ) ;
}
return 0 ;
}
static void F_65 ( struct V_153 * V_163 , unsigned V_73 , int V_52 )
{
struct V_8 * V_51 = F_52 ( V_163 ) ;
void T_5 * V_46 = V_51 -> V_155 + V_211 ;
unsigned long V_158 ;
T_2 V_37 ;
F_55 ( V_51 -> V_159 ) ;
F_56 ( & V_51 -> V_160 , V_158 ) ;
V_37 = F_87 ( V_46 ) ;
V_37 &= ~ F_25 ( V_73 ) ;
if ( V_52 )
V_37 |= F_25 ( V_73 ) ;
F_88 ( V_37 , V_46 ) ;
F_58 ( & V_51 -> V_160 , V_158 ) ;
F_59 ( V_51 -> V_159 ) ;
}
static int F_67 ( struct V_153 * V_163 , unsigned V_73 )
{
struct V_8 * V_51 = F_52 ( V_163 ) ;
T_2 V_37 ;
F_55 ( V_51 -> V_159 ) ;
V_37 = F_87 ( V_51 -> V_155 + V_212 ) ;
F_59 ( V_51 -> V_159 ) ;
V_37 >>= V_73 ;
V_37 &= 1 ;
return V_37 ;
}
static int F_89 ( struct V_153 * V_163 , unsigned V_73 )
{
return F_90 ( V_163 -> V_164 + V_73 ) ;
}
static int F_91 ( struct V_153 * V_163 ,
unsigned V_73 , int V_52 )
{
F_65 ( V_163 , V_73 , V_52 ) ;
return F_92 ( V_163 -> V_164 + V_73 ) ;
}
static int F_93 ( struct V_153 * V_163 , unsigned V_73 )
{
struct V_8 * V_51 = F_52 ( V_163 ) ;
unsigned int V_213 ;
if ( ! V_51 -> V_214 )
return - V_215 ;
V_213 = F_94 ( V_51 -> V_214 , V_73 ) ;
return ( V_213 ) ? : - V_215 ;
}
static void F_95 ( struct V_216 * V_217 )
{
struct V_218 * V_154 = F_96 ( V_217 ) ;
struct V_8 * V_51 = F_97 ( V_217 ) ;
T_2 V_219 ;
F_16 ( V_51 -> V_53 -> V_33 , L_31 , V_51 -> V_4 ) ;
F_98 ( V_154 , V_217 ) ;
V_219 = F_53 ( V_51 -> V_155 + V_220 ) ;
while ( V_219 ) {
unsigned int V_221 , V_213 ;
V_221 = F_99 ( V_219 ) ;
V_219 &= ~ F_25 ( V_221 ) ;
V_213 = F_100 ( V_51 -> V_214 , V_221 ) ;
if ( ! V_213 ) {
F_10 ( V_51 -> V_53 -> V_33 , L_32 , V_221 ) ;
continue;
}
F_16 ( V_51 -> V_53 -> V_33 , L_33 , V_221 ) ;
if ( V_51 -> V_222 & F_25 ( V_221 ) ) {
T_2 V_37 , V_223 , V_224 ;
unsigned long V_158 ;
V_37 = F_53 ( V_51 -> V_155 + V_212 ) ;
do {
F_56 ( & V_51 -> V_160 , V_158 ) ;
V_224 = F_53 ( V_51 -> V_155 +
V_225 ) ;
if ( V_37 & F_25 ( V_221 ) )
V_224 &= ~ F_25 ( V_221 ) ;
else
V_224 |= F_25 ( V_221 ) ;
F_88 ( V_224 ,
V_51 -> V_155 + V_225 ) ;
F_58 ( & V_51 -> V_160 , V_158 ) ;
V_223 = V_37 ;
V_37 = F_53 ( V_51 -> V_155 +
V_212 ) ;
} while ( ( V_37 & F_25 ( V_221 ) ) != ( V_223 & F_25 ( V_221 ) ) );
}
F_101 ( V_213 ) ;
}
F_102 ( V_154 , V_217 ) ;
}
static int F_103 ( struct V_226 * V_227 , unsigned int type )
{
struct V_228 * V_163 = F_104 ( V_227 ) ;
struct V_8 * V_51 = V_163 -> V_229 ;
T_2 V_48 = F_25 ( V_227 -> V_230 ) ;
T_2 V_224 ;
T_2 V_231 ;
T_2 V_37 ;
unsigned long V_158 ;
int V_64 ;
V_64 = F_24 ( V_51 , V_227 -> V_230 , V_69 ) ;
if ( V_64 < 0 )
return V_64 ;
F_55 ( V_51 -> V_159 ) ;
F_56 ( & V_51 -> V_160 , V_158 ) ;
V_37 = F_53 ( V_51 -> V_155 + V_156 ) ;
V_37 &= ~ V_48 ;
F_57 ( V_37 , V_51 -> V_155 + V_156 ) ;
F_58 ( & V_51 -> V_160 , V_158 ) ;
if ( type & V_232 )
F_105 ( V_227 , V_233 ) ;
else
F_105 ( V_227 , V_234 ) ;
F_56 ( & V_51 -> V_160 , V_158 ) ;
F_106 ( V_163 ) ;
V_231 = F_53 ( V_163 -> V_155 + V_235 ) ;
V_224 = F_53 ( V_163 -> V_155 + V_225 ) ;
switch ( type ) {
case V_232 :
V_51 -> V_222 |= V_48 ;
V_231 |= V_48 ;
V_37 = F_87 ( V_51 -> V_155 + V_212 ) ;
if ( V_37 & V_48 )
V_224 &= ~ V_48 ;
else
V_224 |= V_48 ;
break;
case V_236 :
V_51 -> V_222 &= ~ V_48 ;
V_231 |= V_48 ;
V_224 |= V_48 ;
break;
case V_237 :
V_51 -> V_222 &= ~ V_48 ;
V_231 |= V_48 ;
V_224 &= ~ V_48 ;
break;
case V_238 :
V_51 -> V_222 &= ~ V_48 ;
V_231 &= ~ V_48 ;
V_224 |= V_48 ;
break;
case V_239 :
V_51 -> V_222 &= ~ V_48 ;
V_231 &= ~ V_48 ;
V_224 &= ~ V_48 ;
break;
default:
F_107 ( V_163 ) ;
F_58 ( & V_51 -> V_160 , V_158 ) ;
F_59 ( V_51 -> V_159 ) ;
return - V_18 ;
}
F_57 ( V_231 , V_163 -> V_155 + V_235 ) ;
F_57 ( V_224 , V_163 -> V_155 + V_225 ) ;
F_107 ( V_163 ) ;
F_58 ( & V_51 -> V_160 , V_158 ) ;
F_59 ( V_51 -> V_159 ) ;
return 0 ;
}
static void F_108 ( struct V_226 * V_227 )
{
struct V_228 * V_163 = F_104 ( V_227 ) ;
struct V_8 * V_51 = V_163 -> V_229 ;
F_55 ( V_51 -> V_159 ) ;
V_51 -> V_240 = F_109 ( V_163 , V_241 ) ;
F_110 ( V_163 , ~ V_163 -> V_242 , V_241 ) ;
F_59 ( V_51 -> V_159 ) ;
}
static void F_111 ( struct V_226 * V_227 )
{
struct V_228 * V_163 = F_104 ( V_227 ) ;
struct V_8 * V_51 = V_163 -> V_229 ;
F_55 ( V_51 -> V_159 ) ;
F_110 ( V_163 , V_51 -> V_240 , V_241 ) ;
F_59 ( V_51 -> V_159 ) ;
}
static void F_112 ( struct V_226 * V_227 )
{
struct V_228 * V_163 = F_104 ( V_227 ) ;
struct V_8 * V_51 = V_163 -> V_229 ;
F_55 ( V_51 -> V_159 ) ;
F_113 ( V_227 ) ;
}
static void F_114 ( struct V_226 * V_227 )
{
struct V_228 * V_163 = F_104 ( V_227 ) ;
struct V_8 * V_51 = V_163 -> V_229 ;
F_115 ( V_227 ) ;
F_59 ( V_51 -> V_159 ) ;
}
static int F_116 ( struct V_186 * V_187 ,
struct V_2 * V_3 )
{
struct V_54 * V_11 = V_3 -> V_11 ;
struct V_8 * V_51 = V_11 -> V_12 ;
unsigned int V_243 = V_244 | V_245 | V_246 ;
struct V_228 * V_163 ;
int V_64 ;
int V_5 , V_181 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_51 ) {
if ( ! V_51 -> V_247 ) {
F_117 ( & V_187 -> V_33 , L_34 ,
V_51 -> V_4 ) ;
continue;
}
V_64 = F_55 ( V_51 -> V_159 ) ;
if ( V_64 ) {
F_10 ( & V_187 -> V_33 , L_35 ,
V_51 -> V_4 ) ;
continue;
}
V_51 -> V_214 = F_118 ( V_51 -> V_189 , 32 ,
& V_248 , NULL ) ;
if ( ! V_51 -> V_214 ) {
F_117 ( & V_187 -> V_33 , L_36 ,
V_51 -> V_4 ) ;
F_59 ( V_51 -> V_159 ) ;
continue;
}
V_64 = F_119 ( V_51 -> V_214 , 32 , 1 ,
L_37 , V_234 ,
V_243 , 0 , V_249 ) ;
if ( V_64 ) {
F_10 ( & V_187 -> V_33 , L_38 ,
V_51 -> V_4 ) ;
F_120 ( V_51 -> V_214 ) ;
F_59 ( V_51 -> V_159 ) ;
continue;
}
F_57 ( 0xffffffff , V_51 -> V_155 + V_241 ) ;
F_57 ( 0xffffffff , V_51 -> V_155 + V_250 ) ;
V_163 = F_121 ( V_51 -> V_214 , 0 ) ;
V_163 -> V_155 = V_51 -> V_155 ;
V_163 -> V_229 = V_51 ;
V_163 -> V_251 [ 0 ] . V_252 . V_48 = V_241 ;
V_163 -> V_251 [ 0 ] . V_252 . V_253 = V_254 ;
V_163 -> V_251 [ 0 ] . V_154 . V_255 = V_256 ;
V_163 -> V_251 [ 0 ] . V_154 . V_257 = F_115 ;
V_163 -> V_251 [ 0 ] . V_154 . V_258 = F_113 ;
V_163 -> V_251 [ 0 ] . V_154 . V_259 = F_112 ;
V_163 -> V_251 [ 0 ] . V_154 . V_260 = F_114 ;
V_163 -> V_251 [ 0 ] . V_154 . V_261 = V_262 ;
V_163 -> V_251 [ 0 ] . V_154 . V_263 = F_108 ;
V_163 -> V_251 [ 0 ] . V_154 . V_264 = F_111 ;
V_163 -> V_251 [ 0 ] . V_154 . V_265 = F_103 ;
V_163 -> V_266 = F_122 ( V_51 -> V_14 ) ;
F_123 ( V_51 -> V_221 ,
F_95 , V_51 ) ;
for ( V_181 = 0 ; V_181 < 32 ; V_181 ++ )
F_94 ( V_51 -> V_214 , V_181 ) ;
F_59 ( V_51 -> V_159 ) ;
}
return 0 ;
}
static int F_124 ( struct V_186 * V_187 ,
struct V_2 * V_3 )
{
struct V_54 * V_11 = V_3 -> V_11 ;
struct V_8 * V_51 = V_11 -> V_12 ;
struct V_153 * V_163 ;
int V_64 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_51 ) {
if ( ! V_51 -> V_247 ) {
F_117 ( & V_187 -> V_33 , L_34 ,
V_51 -> V_4 ) ;
continue;
}
V_51 -> V_153 = V_267 ;
V_163 = & V_51 -> V_153 ;
V_163 -> V_164 = V_51 -> V_13 ;
V_163 -> V_210 = V_51 -> V_14 ;
V_163 -> V_31 = & V_187 -> V_33 ;
V_163 -> V_189 = V_51 -> V_189 ;
V_163 -> V_268 = V_51 -> V_4 ;
V_64 = F_125 ( V_163 , V_51 ) ;
if ( V_64 ) {
F_10 ( & V_187 -> V_33 , L_39 ,
V_163 -> V_268 , V_64 ) ;
goto V_269;
}
}
F_116 ( V_187 , V_3 ) ;
return 0 ;
V_269:
for ( -- V_5 , -- V_51 ; V_5 >= 0 ; -- V_5 , -- V_51 ) {
if ( ! V_51 -> V_247 )
continue;
F_126 ( & V_51 -> V_153 ) ;
}
return V_64 ;
}
static int F_127 ( struct V_186 * V_187 ,
struct V_2 * V_3 )
{
struct V_54 * V_11 = V_3 -> V_11 ;
struct V_8 * V_51 = V_11 -> V_12 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_51 ) {
if ( ! V_51 -> V_247 )
continue;
F_126 ( & V_51 -> V_153 ) ;
}
return 0 ;
}
static int F_128 ( struct V_8 * V_51 ,
struct V_2 * V_3 )
{
struct V_270 V_271 ;
void T_5 * V_164 ;
if ( F_129 ( V_51 -> V_189 , 0 , & V_271 ) ) {
F_10 ( V_3 -> V_33 , L_40 ) ;
return - V_272 ;
}
V_51 -> V_155 = F_130 ( V_3 -> V_33 , & V_271 ) ;
if ( F_76 ( V_51 -> V_155 ) )
return F_77 ( V_51 -> V_155 ) ;
if ( F_131 ( V_51 -> V_189 ,
L_41 ) ) {
struct V_24 * V_273 ;
V_273 = F_132 ( V_51 -> V_189 -> V_31 ,
L_42 , 0 ) ;
if ( ! V_273 ) {
if ( F_129 ( V_51 -> V_189 , 1 , & V_271 ) ) {
F_10 ( V_3 -> V_33 , L_40 ) ;
return - V_272 ;
}
V_164 = F_130 ( V_3 -> V_33 , & V_271 ) ;
if ( F_76 ( V_164 ) )
return F_77 ( V_164 ) ;
V_274 . V_275 =
F_133 ( & V_271 ) - 4 ;
V_274 . V_4 =
L_43 ;
V_51 -> V_96 = F_134 ( V_3 -> V_33 ,
V_164 ,
& V_274 ) ;
}
}
V_51 -> V_221 = F_135 ( V_51 -> V_189 , 0 ) ;
V_51 -> V_159 = F_136 ( V_51 -> V_189 , 0 ) ;
if ( F_76 ( V_51 -> V_159 ) )
return F_77 ( V_51 -> V_159 ) ;
return F_137 ( V_51 -> V_159 ) ;
}
static struct V_54 * F_138 (
struct V_2 * V_227 ,
struct V_186 * V_187 )
{
const struct V_276 * V_277 ;
struct V_24 * V_273 = V_187 -> V_33 . V_189 ;
struct V_24 * V_25 ;
struct V_54 * V_11 ;
struct V_8 * V_51 ;
int V_278 , V_279 , V_280 , V_281 , V_5 , V_181 ;
V_277 = F_71 ( V_282 , V_273 ) ;
V_11 = (struct V_54 * ) V_277 -> V_37 ;
F_70 (node, np) {
if ( ! F_139 ( V_25 , L_44 , NULL ) )
continue;
V_51 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_51 ) {
if ( ! strcmp ( V_51 -> V_4 , V_25 -> V_4 ) ) {
V_51 -> V_189 = V_25 ;
if ( ! F_128 ( V_51 , V_227 ) )
V_51 -> V_247 = true ;
break;
}
}
}
V_278 = V_11 -> V_283 ;
V_279 = V_11 -> V_284 ;
V_281 = V_11 -> V_285 ;
V_280 = V_11 -> V_286 ;
V_51 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_51 ) {
int V_287 = 0 ;
F_140 ( & V_51 -> V_160 ) ;
V_51 -> V_53 = V_227 ;
V_51 -> V_13 = V_11 -> V_14 ;
V_11 -> V_14 += V_51 -> V_14 ;
for ( V_181 = 0 ; V_181 < 4 ; V_181 ++ ) {
struct V_288 * V_289 = & V_51 -> V_66 [ V_181 ] ;
struct V_290 * V_117 = & V_51 -> V_117 [ V_181 ] ;
int V_291 ;
if ( V_287 >= V_51 -> V_14 )
break;
if ( V_289 -> V_73 >= 0 ) {
if ( V_289 -> type & V_70 )
V_279 = V_289 -> V_73 ;
else
V_278 = V_289 -> V_73 ;
} else {
V_289 -> V_73 = ( V_289 -> type & V_70 ) ?
V_279 : V_278 ;
}
if ( V_117 -> V_73 >= 0 ) {
if ( V_289 -> type & V_70 )
V_281 = V_117 -> V_73 ;
else
V_280 = V_117 -> V_73 ;
} else {
V_117 -> V_73 = ( V_289 -> type & V_70 ) ?
V_281 : V_280 ;
}
F_16 ( V_227 -> V_33 , L_45 ,
V_5 , V_181 , V_289 -> V_73 , V_117 -> V_73 ) ;
V_291 = ( V_289 -> type & ( V_74 |
V_75 ) ) ? 8 : 4 ;
if ( V_289 -> type & V_70 )
V_279 += V_291 ;
else
V_278 += V_291 ;
if ( ( V_117 -> V_118 == V_119 ) ||
( V_117 -> V_118 == V_120 ) )
V_291 = 8 ;
else
V_291 = 4 ;
if ( V_289 -> type & V_70 )
V_281 += V_291 ;
else
V_280 += V_291 ;
V_287 += 8 ;
}
for ( V_181 = 0 ; V_181 < V_11 -> V_56 ; V_181 ++ ) {
int V_9 = 0 ;
if ( V_11 -> V_57 [ V_181 ] . V_17 == V_51 -> V_17 ) {
V_9 = V_11 -> V_57 [ V_181 ] . V_9 ;
V_51 -> V_81 |= F_25 ( V_9 ) ;
}
}
}
return V_11 ;
}
static int T_6 F_141 ( struct V_188 * V_33 )
{
struct V_2 * V_3 = F_142 ( V_33 ) ;
int V_64 = F_143 ( V_3 -> V_207 ) ;
if ( V_64 )
return V_64 ;
if ( V_3 -> V_11 -> type == V_138 ) {
V_64 = F_22 ( V_3 -> V_72 , V_292 ,
& V_293 ) ;
if ( V_64 ) {
F_144 ( V_3 -> V_207 ) ;
return V_64 ;
}
}
return 0 ;
}
static int T_6 F_145 ( struct V_188 * V_33 )
{
struct V_2 * V_3 = F_142 ( V_33 ) ;
int V_64 = F_26 ( V_3 -> V_72 , V_292 ,
V_293 |
V_294 ) ;
if ( V_64 )
return V_64 ;
return F_144 ( V_3 -> V_207 ) ;
}
static int F_146 ( struct V_186 * V_187 )
{
struct V_2 * V_3 ;
struct V_188 * V_33 = & V_187 -> V_33 ;
struct V_54 * V_11 ;
struct V_24 * V_25 = V_187 -> V_33 . V_189 , * V_273 ;
struct V_270 * V_271 ;
void T_5 * V_164 ;
int V_64 ;
if ( ! V_33 -> V_189 ) {
F_10 ( V_33 , L_46 ) ;
return - V_295 ;
}
V_3 = F_11 ( V_33 , sizeof( struct V_2 ) , V_34 ) ;
if ( ! V_3 )
return - V_35 ;
V_3 -> V_33 = V_33 ;
V_11 = F_138 ( V_3 , V_187 ) ;
if ( ! V_11 ) {
F_10 ( V_33 , L_47 ) ;
return - V_18 ;
}
V_3 -> V_11 = V_11 ;
V_273 = F_132 ( V_25 , L_48 , 0 ) ;
if ( V_273 ) {
V_3 -> V_72 = F_147 ( V_273 ) ;
if ( F_76 ( V_3 -> V_72 ) )
return F_77 ( V_3 -> V_72 ) ;
} else {
V_271 = F_148 ( V_187 , V_296 , 0 ) ;
V_164 = F_130 ( & V_187 -> V_33 , V_271 ) ;
if ( F_76 ( V_164 ) )
return F_77 ( V_164 ) ;
V_274 . V_275 = F_133 ( V_271 ) - 4 ;
V_274 . V_4 = L_49 ;
V_3 -> V_72 = F_134 ( & V_187 -> V_33 , V_164 ,
& V_274 ) ;
V_3 -> V_297 = F_133 ( V_271 ) ;
if ( V_11 -> type == V_137 && V_3 -> V_297 < 0x200 ) {
V_271 = F_148 ( V_187 , V_296 , 1 ) ;
V_164 = F_130 ( & V_187 -> V_33 , V_271 ) ;
if ( F_76 ( V_164 ) )
return F_77 ( V_164 ) ;
V_274 . V_275 =
F_133 ( V_271 ) - 4 ;
V_274 . V_4 = L_50 ;
V_3 -> V_96 = F_134 ( & V_187 -> V_33 ,
V_164 ,
& V_274 ) ;
}
}
V_273 = F_132 ( V_25 , L_42 , 0 ) ;
if ( V_273 ) {
V_3 -> V_71 = F_147 ( V_273 ) ;
if ( F_76 ( V_3 -> V_71 ) )
return F_77 ( V_3 -> V_71 ) ;
}
V_64 = F_124 ( V_187 , V_3 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_83 ( V_187 , V_3 ) ;
if ( V_64 ) {
F_127 ( V_187 , V_3 ) ;
return V_64 ;
}
F_149 ( V_187 , V_3 ) ;
return 0 ;
}
static int T_7 F_150 ( void )
{
return F_151 ( & V_298 ) ;
}
