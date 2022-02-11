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
static void F_18 ( struct V_8 * V_46 , int V_9 ,
int * V_47 , T_1 * V_48 , int * V_49 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
struct V_51 * V_11 = V_3 -> V_11 ;
struct V_52 * V_37 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_53 ; V_5 ++ ) {
V_37 = & V_11 -> V_54 [ V_5 ] ;
if ( V_37 -> V_15 == V_46 -> V_17 &&
V_37 -> V_9 == V_9 )
break;
}
if ( V_5 >= V_11 -> V_53 )
return;
* V_47 = V_37 -> V_47 ;
* V_49 = V_37 -> V_49 ;
* V_48 = V_37 -> V_48 ;
}
static bool F_19 ( struct V_8 * V_46 , int V_9 ,
int V_38 , T_2 * V_47 , T_2 * V_55 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
struct V_51 * V_11 = V_3 -> V_11 ;
struct V_56 * V_37 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_57 ; V_5 ++ ) {
V_37 = & V_11 -> V_58 [ V_5 ] ;
if ( ( V_37 -> V_17 == V_46 -> V_17 ) &&
( V_37 -> V_9 == V_9 ) && ( V_37 -> V_59 == V_38 ) )
break;
}
if ( V_5 >= V_11 -> V_57 )
return false ;
* V_47 = V_37 -> V_60 ;
* V_55 = V_37 -> V_61 ;
return true ;
}
static int F_20 ( struct V_8 * V_46 , int V_9 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
int V_62 = ( V_9 / 8 ) ;
struct V_63 * V_63 ;
unsigned int V_64 ;
int V_47 , V_65 , V_49 , V_66 ;
T_1 V_48 ;
if ( V_62 > 3 )
return - V_18 ;
if ( V_46 -> V_67 [ V_62 ] . type & V_68 ) {
F_10 ( V_3 -> V_33 , L_3 , V_9 ) ;
return - V_18 ;
}
if ( V_46 -> V_67 [ V_62 ] . type & V_69 )
return V_70 ;
V_63 = ( V_46 -> V_67 [ V_62 ] . type & V_71 )
? V_3 -> V_72 : V_3 -> V_73 ;
V_66 = V_46 -> V_67 [ V_62 ] . type ;
V_47 = V_46 -> V_67 [ V_62 ] . V_74 ;
if ( V_66 & V_75 ) {
if ( ( V_9 % 8 ) >= 4 )
V_47 += 0x4 ;
V_48 = ( V_9 % 4 ) * 4 ;
V_49 = 0xf ;
} else if ( V_66 & V_76 ) {
if ( ( V_9 % 8 ) >= 5 )
V_47 += 0x4 ;
V_48 = ( V_9 % 8 % 5 ) * 3 ;
V_49 = 0x7 ;
} else {
V_48 = ( V_9 % 8 ) * 2 ;
V_49 = 0x3 ;
}
if ( V_46 -> V_77 & F_21 ( V_9 ) )
F_18 ( V_46 , V_9 , & V_47 , & V_48 , & V_49 ) ;
V_65 = F_22 ( V_63 , V_47 , & V_64 ) ;
if ( V_65 )
return V_65 ;
return ( ( V_64 >> V_48 ) & V_49 ) ;
}
static int F_23 ( struct V_8 * V_46 ,
int V_9 , int V_38 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
int V_62 = ( V_9 / 8 ) ;
if ( V_62 > 3 )
return - V_18 ;
if ( V_46 -> V_67 [ V_62 ] . type & V_68 ) {
F_10 ( V_3 -> V_33 , L_3 , V_9 ) ;
return - V_18 ;
}
if ( V_46 -> V_67 [ V_62 ] . type & V_69 ) {
if ( V_38 != V_70 ) {
F_10 ( V_3 -> V_33 ,
L_4 , V_9 ) ;
return - V_78 ;
}
}
return 0 ;
}
static int F_24 ( struct V_8 * V_46 , int V_9 , int V_38 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
int V_62 = ( V_9 / 8 ) ;
struct V_63 * V_63 ;
int V_47 , V_65 , V_49 , V_66 ;
T_1 V_48 ;
T_2 V_37 , V_79 , V_80 , V_61 ;
V_65 = F_23 ( V_46 , V_9 , V_38 ) ;
if ( V_65 < 0 )
return V_65 ;
if ( V_46 -> V_67 [ V_62 ] . type & V_69 )
return 0 ;
F_16 ( V_3 -> V_33 , L_5 ,
V_46 -> V_17 , V_9 , V_38 ) ;
V_63 = ( V_46 -> V_67 [ V_62 ] . type & V_71 )
? V_3 -> V_72 : V_3 -> V_73 ;
V_66 = V_46 -> V_67 [ V_62 ] . type ;
V_47 = V_46 -> V_67 [ V_62 ] . V_74 ;
if ( V_66 & V_75 ) {
if ( ( V_9 % 8 ) >= 4 )
V_47 += 0x4 ;
V_48 = ( V_9 % 4 ) * 4 ;
V_49 = 0xf ;
} else if ( V_66 & V_76 ) {
if ( ( V_9 % 8 ) >= 5 )
V_47 += 0x4 ;
V_48 = ( V_9 % 8 % 5 ) * 3 ;
V_49 = 0x7 ;
} else {
V_48 = ( V_9 % 8 ) * 2 ;
V_49 = 0x3 ;
}
if ( V_46 -> V_77 & F_21 ( V_9 ) )
F_18 ( V_46 , V_9 , & V_47 , & V_48 , & V_49 ) ;
if ( V_46 -> V_81 & F_21 ( V_9 ) ) {
if ( F_19 ( V_46 , V_9 , V_38 , & V_80 ,
& V_61 ) ) {
V_65 = F_25 ( V_63 , V_80 , V_61 ) ;
if ( V_65 )
return V_65 ;
}
}
V_37 = ( V_49 << ( V_48 + 16 ) ) ;
V_79 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_38 & V_49 ) << V_48 ;
V_65 = F_26 ( V_63 , V_47 , V_79 , V_37 ) ;
return V_65 ;
}
static void F_27 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
if ( V_46 -> V_17 == 0 ) {
* V_63 = V_3 -> V_72 ;
* V_47 = V_83 ;
} else {
* V_47 = V_84 ;
* V_63 = V_3 -> V_73 ;
* V_47 -= 0x10 ;
* V_47 += V_46 -> V_17 * V_85 ;
}
* V_47 += ( ( V_82 / V_86 ) * 4 ) ;
* V_48 = ( V_82 % V_86 ) ;
* V_48 *= V_87 ;
}
static void F_28 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
if ( V_46 -> V_17 == 0 ) {
* V_63 = V_3 -> V_72 ;
* V_47 = V_88 ;
} else {
* V_63 = V_3 -> V_73 ;
* V_47 = V_89 ;
* V_47 -= 0x10 ;
* V_47 += V_46 -> V_17 * V_90 ;
}
* V_47 += ( ( V_82 / V_91 ) * 4 ) ;
* V_48 = V_82 % V_91 ;
* V_48 *= V_92 ;
}
static int F_29 ( struct V_8 * V_46 ,
int V_82 ,
struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
int V_93 ;
if ( V_46 -> V_17 == 0 ) {
* V_63 = V_3 -> V_72 ;
* V_47 = V_94 ;
V_93 = V_95 ;
} else {
* V_63 = V_3 -> V_73 ;
* V_47 = V_96 ;
V_93 = V_97 ;
* V_47 += ( V_46 -> V_17 - 1 ) * V_98 ;
}
* V_47 += ( ( V_82 / V_93 ) * 4 ) ;
* V_48 = V_82 % V_93 ;
return 0 ;
}
static void F_30 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
* V_63 = V_3 -> V_73 ;
* V_47 = V_99 ;
* V_47 += V_46 -> V_17 * V_100 ;
* V_47 += ( V_82 / V_101 ) * 4 ;
* V_48 = V_82 % V_101 ;
}
static void F_31 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
* V_63 = V_3 -> V_73 ;
* V_47 = V_102 ;
* V_47 += V_46 -> V_17 * V_100 ;
* V_47 += ( ( V_82 / V_101 ) * 4 ) ;
* V_48 = V_82 % V_101 ;
}
static void F_32 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
if ( V_46 -> V_17 == 0 && V_82 < 12 ) {
* V_63 = V_3 -> V_72 ? V_3 -> V_72
: V_46 -> V_103 ;
* V_47 = V_3 -> V_72 ? V_104 : 0 ;
* V_47 += ( ( V_82 / V_105 ) * 4 ) ;
* V_48 = V_82 % V_105 ;
* V_48 *= V_106 ;
} else {
* V_63 = V_3 -> V_103 ? V_3 -> V_103
: V_3 -> V_73 ;
* V_47 = V_3 -> V_103 ? 0 : V_107 ;
* V_47 -= 4 ;
* V_47 += V_46 -> V_17 * V_108 ;
* V_47 += ( ( V_82 / V_105 ) * 4 ) ;
* V_48 = 7 - ( V_82 % V_105 ) ;
* V_48 *= V_106 ;
}
}
static void F_33 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
if ( V_46 -> V_17 == 0 ) {
* V_63 = V_3 -> V_72 ;
* V_47 = V_104 ;
* V_47 += ( ( V_82 / V_105 ) * 4 ) ;
* V_48 = V_82 % V_105 ;
* V_48 *= V_106 ;
} else {
* V_63 = V_3 -> V_73 ;
* V_47 = V_109 ;
* V_47 -= 0x10 ;
* V_47 += V_46 -> V_17 * V_108 ;
* V_47 += ( ( V_82 / V_105 ) * 4 ) ;
* V_48 = ( V_82 % V_105 ) ;
* V_48 *= V_106 ;
}
}
static void F_34 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
if ( V_46 -> V_17 == 0 ) {
* V_63 = V_3 -> V_72 ;
* V_47 = V_110 ;
* V_47 += ( ( V_82 / V_111 ) * 4 ) ;
* V_48 = V_82 % V_111 ;
* V_48 *= V_112 ;
} else {
* V_63 = V_3 -> V_73 ;
* V_47 = V_113 ;
* V_47 -= 0x10 ;
* V_47 += V_46 -> V_17 * V_114 ;
* V_47 += ( ( V_82 / V_111 ) * 4 ) ;
* V_48 = ( V_82 % V_111 ) ;
* V_48 *= V_112 ;
}
}
static void F_35 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
* V_63 = V_3 -> V_73 ;
* V_47 = V_115 ;
* V_47 += V_46 -> V_17 * V_108 ;
* V_47 += ( ( V_82 / V_105 ) * 4 ) ;
* V_48 = ( V_82 % V_105 ) ;
* V_48 *= V_106 ;
}
static void F_36 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
* V_63 = V_3 -> V_73 ;
* V_47 = V_116 ;
* V_47 += V_46 -> V_17 * V_114 ;
* V_47 += ( ( V_82 / V_111 ) * 4 ) ;
* V_48 = ( V_82 % V_111 ) ;
* V_48 *= V_112 ;
}
static void F_37 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
if ( V_46 -> V_17 == 0 ) {
* V_63 = V_3 -> V_72 ;
* V_47 = V_117 ;
* V_47 += ( ( V_82 / V_105 ) * 4 ) ;
* V_48 = V_82 % V_105 ;
* V_48 *= V_106 ;
} else {
* V_63 = V_3 -> V_73 ;
* V_47 = V_118 ;
* V_47 -= 0x10 ;
* V_47 += V_46 -> V_17 * V_108 ;
* V_47 += ( ( V_82 / V_105 ) * 4 ) ;
* V_48 = ( V_82 % V_105 ) ;
* V_48 *= V_106 ;
}
}
static void F_38 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
if ( V_46 -> V_17 == 0 ) {
* V_63 = V_3 -> V_72 ;
* V_47 = V_119 ;
* V_47 += ( ( V_82 / V_111 ) * 4 ) ;
* V_48 = V_82 % V_111 ;
* V_48 *= V_112 ;
} else {
* V_63 = V_3 -> V_73 ;
* V_47 = V_120 ;
* V_47 -= 0x10 ;
* V_47 += V_46 -> V_17 * V_114 ;
* V_47 += ( ( V_82 / V_111 ) * 4 ) ;
* V_48 = ( V_82 % V_111 ) ;
* V_48 *= V_112 ;
}
}
static void F_39 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
if ( ( V_46 -> V_17 == 0 ) || ( V_46 -> V_17 == 1 ) ) {
* V_63 = V_3 -> V_72 ;
* V_47 = V_121 ;
* V_47 += V_46 -> V_17 * V_108 ;
* V_47 += ( ( V_82 / V_105 ) * 4 ) ;
* V_48 = V_82 % V_105 ;
* V_48 *= V_106 ;
} else {
* V_63 = V_3 -> V_73 ;
* V_47 = V_122 ;
* V_47 -= 0x20 ;
* V_47 += V_46 -> V_17 * V_108 ;
* V_47 += ( ( V_82 / V_105 ) * 4 ) ;
* V_48 = ( V_82 % V_105 ) ;
* V_48 *= V_106 ;
}
}
static void F_40 ( struct V_8 * V_46 ,
int V_82 , struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
int V_123 = ( V_82 / 8 ) ;
if ( ( V_46 -> V_17 == 0 ) || ( V_46 -> V_17 == 1 ) )
* V_63 = V_3 -> V_72 ;
else
* V_63 = V_3 -> V_73 ;
* V_47 = V_46 -> V_124 [ V_123 ] . V_74 ;
if ( ( V_46 -> V_124 [ V_123 ] . V_125 == V_126 ) ||
( V_46 -> V_124 [ V_123 ] . V_125 == V_127 ) )
* V_48 = ( V_82 % 8 ) * 3 ;
else
* V_48 = ( V_82 % 8 ) * 2 ;
}
static int F_41 ( struct V_8 * V_46 ,
int V_82 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
struct V_51 * V_11 = V_3 -> V_11 ;
struct V_63 * V_63 ;
int V_47 , V_65 ;
T_2 V_37 , V_128 , V_129 ;
T_1 V_48 ;
int V_125 = V_46 -> V_124 [ V_82 / 8 ] . V_125 ;
V_11 -> V_130 ( V_46 , V_82 , & V_63 , & V_47 , & V_48 ) ;
switch ( V_125 ) {
case V_126 :
case V_127 :
V_129 = V_131 ;
switch ( V_48 ) {
case 0 ... 12 :
break;
case 15 :
V_65 = F_22 ( V_63 , V_47 , & V_37 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_22 ( V_63 , V_47 + 0x4 , & V_128 ) ;
if ( V_65 )
return V_65 ;
V_37 >>= 15 ;
V_128 &= 0x3 ;
V_128 <<= 1 ;
V_37 |= V_128 ;
return V_132 [ V_125 ] [ V_37 ] ;
case 18 ... 21 :
V_47 += 4 ;
V_48 -= 16 ;
break;
default:
F_10 ( V_3 -> V_33 , L_6 ,
V_48 , V_125 ) ;
return - V_18 ;
}
break;
case V_133 :
case V_134 :
case V_135 :
V_129 = V_112 ;
break;
default:
F_10 ( V_3 -> V_33 , L_7 ,
V_125 ) ;
return - V_18 ;
}
V_65 = F_22 ( V_63 , V_47 , & V_37 ) ;
if ( V_65 )
return V_65 ;
V_37 >>= V_48 ;
V_37 &= ( 1 << V_129 ) - 1 ;
return V_132 [ V_125 ] [ V_37 ] ;
}
static int F_42 ( struct V_8 * V_46 ,
int V_82 , int V_136 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
struct V_51 * V_11 = V_3 -> V_11 ;
struct V_63 * V_63 ;
int V_47 , V_65 , V_5 ;
T_2 V_37 , V_79 , V_129 , V_128 ;
T_1 V_48 ;
int V_125 = V_46 -> V_124 [ V_82 / 8 ] . V_125 ;
F_16 ( V_3 -> V_33 , L_8 ,
V_46 -> V_17 , V_82 , V_136 ) ;
V_11 -> V_130 ( V_46 , V_82 , & V_63 , & V_47 , & V_48 ) ;
V_65 = - V_18 ;
for ( V_5 = 0 ; V_5 < F_43 ( V_132 [ V_125 ] ) ; V_5 ++ ) {
if ( V_132 [ V_125 ] [ V_5 ] == V_136 ) {
V_65 = V_5 ;
break;
} else if ( V_132 [ V_125 ] [ V_5 ] < 0 ) {
V_65 = V_132 [ V_125 ] [ V_5 ] ;
break;
}
}
if ( V_65 < 0 ) {
F_10 ( V_3 -> V_33 , L_9 ,
V_136 ) ;
return V_65 ;
}
switch ( V_125 ) {
case V_126 :
case V_127 :
V_129 = V_131 ;
switch ( V_48 ) {
case 0 ... 12 :
break;
case 15 :
V_37 = ( V_65 & 0x1 ) << 15 ;
V_128 = ( V_65 >> 0x1 ) & 0x3 ;
V_79 = F_21 ( 15 ) | F_21 ( 31 ) ;
V_37 |= F_21 ( 31 ) ;
V_65 = F_26 ( V_63 , V_47 , V_79 , V_37 ) ;
if ( V_65 )
return V_65 ;
V_79 = 0x3 | ( 0x3 << 16 ) ;
V_128 |= ( 0x3 << 16 ) ;
V_47 += 0x4 ;
V_65 = F_26 ( V_63 , V_47 , V_79 , V_128 ) ;
return V_65 ;
case 18 ... 21 :
V_47 += 4 ;
V_48 -= 16 ;
break;
default:
F_10 ( V_3 -> V_33 , L_6 ,
V_48 , V_125 ) ;
return - V_18 ;
}
break;
case V_133 :
case V_134 :
case V_135 :
V_129 = V_112 ;
break;
default:
F_10 ( V_3 -> V_33 , L_7 ,
V_125 ) ;
return - V_18 ;
}
V_37 = ( ( 1 << V_129 ) - 1 ) << ( V_48 + 16 ) ;
V_79 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_65 << V_48 ) ;
V_65 = F_26 ( V_63 , V_47 , V_79 , V_37 ) ;
return V_65 ;
}
static int F_44 ( struct V_8 * V_46 , int V_82 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
struct V_51 * V_11 = V_3 -> V_11 ;
struct V_63 * V_63 ;
int V_47 , V_65 , V_137 ;
T_1 V_48 ;
T_2 V_37 ;
if ( V_11 -> type == V_138 )
return V_139 ;
V_11 -> V_140 ( V_46 , V_82 , & V_63 , & V_47 , & V_48 ) ;
V_65 = F_22 ( V_63 , V_47 , & V_37 ) ;
if ( V_65 )
return V_65 ;
switch ( V_11 -> type ) {
case V_141 :
case V_142 :
return ! ( V_37 & F_21 ( V_48 ) )
? V_143
: V_139 ;
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
V_137 = V_46 -> V_137 [ V_82 / 8 ] ;
V_37 >>= V_48 ;
V_37 &= ( 1 << V_106 ) - 1 ;
return V_149 [ V_137 ] [ V_37 ] ;
default:
F_10 ( V_3 -> V_33 , L_10 ) ;
return - V_18 ;
} ;
}
static int F_45 ( struct V_8 * V_46 ,
int V_82 , int V_150 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
struct V_51 * V_11 = V_3 -> V_11 ;
struct V_63 * V_63 ;
int V_47 , V_65 , V_5 , V_137 ;
T_1 V_48 ;
T_2 V_37 , V_79 ;
F_16 ( V_3 -> V_33 , L_11 ,
V_46 -> V_17 , V_82 , V_150 ) ;
if ( V_11 -> type == V_138 )
return V_150 ? - V_18 : 0 ;
V_11 -> V_140 ( V_46 , V_82 , & V_63 , & V_47 , & V_48 ) ;
switch ( V_11 -> type ) {
case V_141 :
case V_142 :
V_37 = F_21 ( V_48 + 16 ) ;
if ( V_150 == V_139 )
V_37 |= F_21 ( V_48 ) ;
V_65 = F_25 ( V_63 , V_47 , V_37 ) ;
break;
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
V_137 = V_46 -> V_137 [ V_82 / 8 ] ;
V_65 = - V_18 ;
for ( V_5 = 0 ; V_5 < F_43 ( V_149 [ V_137 ] ) ;
V_5 ++ ) {
if ( V_149 [ V_137 ] [ V_5 ] == V_150 ) {
V_65 = V_5 ;
break;
}
}
if ( V_65 < 0 ) {
F_10 ( V_3 -> V_33 , L_12 ,
V_150 ) ;
return V_65 ;
}
V_37 = ( ( 1 << V_106 ) - 1 ) << ( V_48 + 16 ) ;
V_79 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_65 << V_48 ) ;
V_65 = F_26 ( V_63 , V_47 , V_79 , V_37 ) ;
break;
default:
F_10 ( V_3 -> V_33 , L_10 ) ;
return - V_18 ;
}
return V_65 ;
}
static int F_46 ( struct V_8 * V_46 ,
int V_82 ,
struct V_63 * * V_63 ,
int * V_47 , T_1 * V_48 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
* V_63 = V_3 -> V_73 ;
* V_47 = V_151 ;
* V_47 += V_46 -> V_17 * V_152 ;
* V_47 += ( ( V_82 / V_153 ) * 4 ) ;
* V_48 = V_82 % V_153 ;
return 0 ;
}
static int F_47 ( struct V_8 * V_46 , int V_82 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
struct V_51 * V_11 = V_3 -> V_11 ;
struct V_63 * V_63 ;
int V_47 , V_65 ;
T_1 V_48 ;
T_2 V_37 ;
V_65 = V_11 -> V_154 ( V_46 , V_82 , & V_63 , & V_47 , & V_48 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_22 ( V_63 , V_47 , & V_37 ) ;
if ( V_65 )
return V_65 ;
V_37 >>= V_48 ;
return V_37 & 0x1 ;
}
static int F_48 ( struct V_8 * V_46 ,
int V_82 , int V_155 )
{
struct V_2 * V_3 = V_46 -> V_50 ;
struct V_51 * V_11 = V_3 -> V_11 ;
struct V_63 * V_63 ;
int V_47 , V_65 ;
T_1 V_48 ;
T_2 V_37 , V_79 ;
F_16 ( V_3 -> V_33 , L_13 ,
V_46 -> V_17 , V_82 , V_155 ) ;
V_65 = V_11 -> V_154 ( V_46 , V_82 , & V_63 , & V_47 , & V_48 ) ;
if ( V_65 )
return V_65 ;
V_37 = F_21 ( V_48 + 16 ) | ( V_155 << V_48 ) ;
V_79 = F_21 ( V_48 + 16 ) | F_21 ( V_48 ) ;
return F_26 ( V_63 , V_47 , V_79 , V_37 ) ;
}
static int F_49 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_156 ;
}
static const char * F_50 ( struct V_19 * V_20 ,
unsigned V_21 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_157 [ V_21 ] . V_4 ;
}
static int F_51 ( struct V_19 * V_20 ,
unsigned V_21 , const char * const * * V_7 ,
unsigned * const V_158 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
* V_7 = V_3 -> V_157 [ V_21 ] . V_7 ;
* V_158 = V_3 -> V_157 [ V_21 ] . V_6 ;
return 0 ;
}
static int F_52 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_40 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
const unsigned int * V_22 = V_3 -> V_7 [ V_40 ] . V_22 ;
const struct V_159 * V_37 = V_3 -> V_7 [ V_40 ] . V_37 ;
struct V_8 * V_46 ;
int V_160 , V_65 = 0 ;
F_16 ( V_3 -> V_33 , L_14 ,
V_3 -> V_157 [ V_21 ] . V_4 , V_3 -> V_7 [ V_40 ] . V_4 ) ;
for ( V_160 = 0 ; V_160 < V_3 -> V_7 [ V_40 ] . V_23 ; V_160 ++ ) {
V_46 = F_2 ( V_3 , V_22 [ V_160 ] ) ;
V_65 = F_24 ( V_46 , V_22 [ V_160 ] - V_46 -> V_13 ,
V_37 [ V_160 ] . V_59 ) ;
if ( V_65 )
break;
}
if ( V_65 ) {
for ( V_160 -- ; V_160 >= 0 ; V_160 -- )
F_24 ( V_46 , V_22 [ V_160 ] - V_46 -> V_13 , 0 ) ;
return V_65 ;
}
return 0 ;
}
static int F_53 ( struct V_161 * V_162 , unsigned V_74 )
{
struct V_8 * V_46 = F_54 ( V_162 ) ;
T_2 V_37 ;
V_37 = F_55 ( V_46 -> V_163 + V_164 ) ;
return ! ( V_37 & F_21 ( V_74 ) ) ;
}
static int F_56 ( struct V_161 * V_162 ,
int V_9 , bool V_165 )
{
struct V_8 * V_46 ;
int V_65 ;
unsigned long V_166 ;
T_2 V_37 ;
V_46 = F_54 ( V_162 ) ;
V_65 = F_24 ( V_46 , V_9 , V_70 ) ;
if ( V_65 < 0 )
return V_65 ;
F_57 ( V_46 -> V_167 ) ;
F_58 ( & V_46 -> V_168 , V_166 ) ;
V_37 = F_55 ( V_46 -> V_163 + V_164 ) ;
if ( ! V_165 )
V_37 |= F_21 ( V_9 ) ;
else
V_37 &= ~ F_21 ( V_9 ) ;
F_59 ( V_37 , V_46 -> V_163 + V_164 ) ;
F_60 ( & V_46 -> V_168 , V_166 ) ;
F_61 ( V_46 -> V_167 ) ;
return 0 ;
}
static int F_62 ( struct V_19 * V_20 ,
struct V_169 * V_170 ,
unsigned V_74 , bool V_165 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_161 * V_162 ;
int V_9 ;
V_162 = V_170 -> V_171 ;
V_9 = V_74 - V_162 -> V_172 ;
F_16 ( V_3 -> V_33 , L_15 ,
V_74 , V_170 -> V_4 , V_9 , V_165 ? L_16 : L_17 ) ;
return F_56 ( V_162 , V_74 - V_162 -> V_172 ,
V_165 ) ;
}
static bool F_63 ( struct V_51 * V_11 ,
enum V_173 V_150 )
{
switch ( V_11 -> type ) {
case V_141 :
case V_142 :
return ( V_150 == V_143 ||
V_150 == V_139 ) ;
case V_138 :
return V_150 ? false : true ;
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
return ( V_150 != V_143 ) ;
}
return false ;
}
static int F_64 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_42 , unsigned V_44 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_46 = F_2 ( V_3 , V_9 ) ;
enum V_173 V_174 ;
T_2 V_175 ;
int V_5 ;
int V_176 ;
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ ) {
V_174 = F_65 ( V_42 [ V_5 ] ) ;
V_175 = F_66 ( V_42 [ V_5 ] ) ;
switch ( V_174 ) {
case V_139 :
V_176 = F_45 ( V_46 , V_9 - V_46 -> V_13 ,
V_174 ) ;
if ( V_176 )
return V_176 ;
break;
case V_177 :
case V_178 :
case V_143 :
case V_179 :
if ( ! F_63 ( V_3 -> V_11 , V_174 ) )
return - V_78 ;
if ( ! V_175 )
return - V_18 ;
V_176 = F_45 ( V_46 , V_9 - V_46 -> V_13 ,
V_174 ) ;
if ( V_176 )
return V_176 ;
break;
case V_180 :
F_67 ( & V_46 -> V_161 ,
V_9 - V_46 -> V_13 , V_175 ) ;
V_176 = F_56 ( & V_46 -> V_161 ,
V_9 - V_46 -> V_13 , false ) ;
if ( V_176 )
return V_176 ;
break;
case V_181 :
if ( ! V_3 -> V_11 -> V_130 )
return - V_78 ;
V_176 = F_42 ( V_46 ,
V_9 - V_46 -> V_13 , V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
break;
case V_182 :
if ( ! V_3 -> V_11 -> V_154 )
return - V_78 ;
V_176 = F_48 ( V_46 ,
V_9 - V_46 -> V_13 , V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
break;
default:
return - V_78 ;
break;
}
}
return 0 ;
}
static int F_68 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_183 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_46 = F_2 ( V_3 , V_9 ) ;
enum V_173 V_174 = F_65 ( * V_183 ) ;
T_3 V_175 ;
int V_176 ;
switch ( V_174 ) {
case V_139 :
if ( F_44 ( V_46 , V_9 - V_46 -> V_13 ) != V_174 )
return - V_18 ;
V_175 = 0 ;
break;
case V_177 :
case V_178 :
case V_143 :
case V_179 :
if ( ! F_63 ( V_3 -> V_11 , V_174 ) )
return - V_78 ;
if ( F_44 ( V_46 , V_9 - V_46 -> V_13 ) != V_174 )
return - V_18 ;
V_175 = 1 ;
break;
case V_180 :
V_176 = F_20 ( V_46 , V_9 - V_46 -> V_13 ) ;
if ( V_176 != V_70 )
return - V_18 ;
V_176 = F_69 ( & V_46 -> V_161 , V_9 - V_46 -> V_13 ) ;
if ( V_176 < 0 )
return V_176 ;
V_175 = V_176 ? 1 : 0 ;
break;
case V_181 :
if ( ! V_3 -> V_11 -> V_130 )
return - V_78 ;
V_176 = F_41 ( V_46 , V_9 - V_46 -> V_13 ) ;
if ( V_176 < 0 )
return V_176 ;
V_175 = V_176 ;
break;
case V_182 :
if ( ! V_3 -> V_11 -> V_154 )
return - V_78 ;
V_176 = F_47 ( V_46 , V_9 - V_46 -> V_13 ) ;
if ( V_176 < 0 )
return V_176 ;
V_175 = V_176 ;
break;
default:
return - V_78 ;
break;
}
* V_183 = F_70 ( V_174 , V_175 ) ;
return 0 ;
}
static void F_71 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_24 * V_184 ;
F_72 (np, child) {
if ( F_73 ( V_185 , V_184 ) )
continue;
V_3 -> V_156 ++ ;
V_3 -> V_6 += F_74 ( V_184 ) ;
}
}
static int F_75 ( struct V_24 * V_25 ,
struct V_1 * V_29 ,
struct V_2 * V_3 ,
T_2 V_186 )
{
struct V_8 * V_46 ;
int V_187 ;
const T_4 * V_188 ;
int V_15 ;
int V_5 , V_189 ;
int V_65 ;
F_16 ( V_3 -> V_33 , L_18 , V_186 , V_25 -> V_4 ) ;
V_29 -> V_4 = V_25 -> V_4 ;
V_188 = F_76 ( V_25 , L_19 , & V_187 ) ;
V_187 /= sizeof( * V_188 ) ;
if ( ! V_187 || V_187 % 4 ) {
F_10 ( V_3 -> V_33 , L_20 ) ;
return - V_18 ;
}
V_29 -> V_23 = V_187 / 4 ;
V_29 -> V_22 = F_11 ( V_3 -> V_33 , V_29 -> V_23 * sizeof( unsigned int ) ,
V_34 ) ;
V_29 -> V_37 = F_11 ( V_3 -> V_33 , V_29 -> V_23 *
sizeof( struct V_159 ) ,
V_34 ) ;
if ( ! V_29 -> V_22 || ! V_29 -> V_37 )
return - V_35 ;
for ( V_5 = 0 , V_189 = 0 ; V_5 < V_187 ; V_5 += 4 , V_189 ++ ) {
const T_4 * V_190 ;
struct V_24 * V_191 ;
V_15 = F_77 ( * V_188 ++ ) ;
V_46 = F_3 ( V_3 , V_15 ) ;
if ( F_78 ( V_46 ) )
return F_79 ( V_46 ) ;
V_29 -> V_22 [ V_189 ] = V_46 -> V_13 + F_77 ( * V_188 ++ ) ;
V_29 -> V_37 [ V_189 ] . V_59 = F_77 ( * V_188 ++ ) ;
V_190 = V_188 ++ ;
if ( ! V_190 )
return - V_18 ;
V_191 = F_80 ( F_81 ( V_190 ) ) ;
V_65 = F_82 ( V_191 , NULL ,
& V_29 -> V_37 [ V_189 ] . V_42 , & V_29 -> V_37 [ V_189 ] . V_45 ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
static int F_83 ( struct V_24 * V_25 ,
struct V_2 * V_3 ,
T_2 V_186 )
{
struct V_24 * V_184 ;
struct V_192 * V_59 ;
struct V_1 * V_29 ;
int V_65 ;
static T_2 V_193 ;
T_2 V_5 = 0 ;
F_16 ( V_3 -> V_33 , L_21 , V_186 , V_25 -> V_4 ) ;
V_59 = & V_3 -> V_157 [ V_186 ] ;
V_59 -> V_4 = V_25 -> V_4 ;
V_59 -> V_6 = F_74 ( V_25 ) ;
if ( V_59 -> V_6 <= 0 )
return 0 ;
V_59 -> V_7 = F_11 ( V_3 -> V_33 ,
V_59 -> V_6 * sizeof( char * ) , V_34 ) ;
if ( ! V_59 -> V_7 )
return - V_35 ;
F_72 (np, child) {
V_59 -> V_7 [ V_5 ] = V_184 -> V_4 ;
V_29 = & V_3 -> V_7 [ V_193 ++ ] ;
V_65 = F_75 ( V_184 , V_29 , V_3 , V_5 ++ ) ;
if ( V_65 ) {
F_14 ( V_184 ) ;
return V_65 ;
}
}
return 0 ;
}
static int F_84 ( struct V_194 * V_195 ,
struct V_2 * V_3 )
{
struct V_196 * V_33 = & V_195 -> V_33 ;
struct V_24 * V_25 = V_33 -> V_197 ;
struct V_24 * V_184 ;
int V_65 ;
int V_5 ;
F_71 ( V_3 , V_25 ) ;
F_16 ( & V_195 -> V_33 , L_22 , V_3 -> V_156 ) ;
F_16 ( & V_195 -> V_33 , L_23 , V_3 -> V_6 ) ;
V_3 -> V_157 = F_11 ( V_33 , V_3 -> V_156 *
sizeof( struct V_192 ) ,
V_34 ) ;
if ( ! V_3 -> V_157 ) {
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
F_72 (np, child) {
if ( F_73 ( V_185 , V_184 ) )
continue;
V_65 = F_83 ( V_184 , V_3 , V_5 ++ ) ;
if ( V_65 ) {
F_10 ( & V_195 -> V_33 , L_26 ) ;
F_14 ( V_184 ) ;
return V_65 ;
}
}
return 0 ;
}
static int F_85 ( struct V_194 * V_195 ,
struct V_2 * V_3 )
{
struct V_198 * V_199 = & V_3 -> V_200 ;
struct V_201 * V_202 , * V_203 ;
struct V_8 * V_204 ;
int V_9 , V_46 , V_65 ;
int V_205 ;
V_199 -> V_4 = L_27 ;
V_199 -> V_206 = V_207 ;
V_199 -> V_208 = & V_209 ;
V_199 -> V_210 = & V_211 ;
V_199 -> V_212 = & V_213 ;
V_202 = F_11 ( & V_195 -> V_33 , sizeof( * V_202 ) *
V_3 -> V_11 -> V_14 , V_34 ) ;
if ( ! V_202 ) {
F_10 ( & V_195 -> V_33 , L_28 ) ;
return - V_35 ;
}
V_199 -> V_22 = V_202 ;
V_199 -> V_23 = V_3 -> V_11 -> V_14 ;
V_203 = V_202 ;
for ( V_46 = 0 , V_205 = 0 ; V_46 < V_3 -> V_11 -> V_16 ; V_46 ++ ) {
V_204 = & V_3 -> V_11 -> V_12 [ V_46 ] ;
for ( V_9 = 0 ; V_9 < V_204 -> V_14 ; V_9 ++ , V_205 ++ ) {
V_203 -> V_214 = V_205 ;
V_203 -> V_4 = F_86 ( V_34 , L_29 ,
V_204 -> V_4 , V_9 ) ;
V_203 ++ ;
}
}
V_65 = F_84 ( V_195 , V_3 ) ;
if ( V_65 )
return V_65 ;
V_3 -> V_215 = F_87 ( & V_195 -> V_33 , V_199 , V_3 ) ;
if ( F_78 ( V_3 -> V_215 ) ) {
F_10 ( & V_195 -> V_33 , L_30 ) ;
return F_79 ( V_3 -> V_215 ) ;
}
for ( V_46 = 0 ; V_46 < V_3 -> V_11 -> V_16 ; ++ V_46 ) {
V_204 = & V_3 -> V_11 -> V_12 [ V_46 ] ;
V_204 -> V_216 . V_4 = V_204 -> V_4 ;
V_204 -> V_216 . V_217 = V_46 ;
V_204 -> V_216 . V_13 = V_204 -> V_13 ;
V_204 -> V_216 . V_172 = V_204 -> V_161 . V_172 ;
V_204 -> V_216 . V_23 = V_204 -> V_161 . V_218 ;
V_204 -> V_216 . V_171 = & V_204 -> V_161 ;
F_88 ( V_3 -> V_215 , & V_204 -> V_216 ) ;
}
return 0 ;
}
static void F_67 ( struct V_161 * V_171 , unsigned V_74 , int V_55 )
{
struct V_8 * V_46 = F_54 ( V_171 ) ;
void T_5 * V_47 = V_46 -> V_163 + V_219 ;
unsigned long V_166 ;
T_2 V_37 ;
F_57 ( V_46 -> V_167 ) ;
F_58 ( & V_46 -> V_168 , V_166 ) ;
V_37 = F_89 ( V_47 ) ;
V_37 &= ~ F_21 ( V_74 ) ;
if ( V_55 )
V_37 |= F_21 ( V_74 ) ;
F_90 ( V_37 , V_47 ) ;
F_60 ( & V_46 -> V_168 , V_166 ) ;
F_61 ( V_46 -> V_167 ) ;
}
static int F_69 ( struct V_161 * V_171 , unsigned V_74 )
{
struct V_8 * V_46 = F_54 ( V_171 ) ;
T_2 V_37 ;
F_57 ( V_46 -> V_167 ) ;
V_37 = F_89 ( V_46 -> V_163 + V_220 ) ;
F_61 ( V_46 -> V_167 ) ;
V_37 >>= V_74 ;
V_37 &= 1 ;
return V_37 ;
}
static int F_91 ( struct V_161 * V_171 , unsigned V_74 )
{
return F_92 ( V_171 -> V_172 + V_74 ) ;
}
static int F_93 ( struct V_161 * V_171 ,
unsigned V_74 , int V_55 )
{
F_67 ( V_171 , V_74 , V_55 ) ;
return F_94 ( V_171 -> V_172 + V_74 ) ;
}
static int F_95 ( struct V_161 * V_171 , unsigned V_74 )
{
struct V_8 * V_46 = F_54 ( V_171 ) ;
unsigned int V_221 ;
if ( ! V_46 -> V_222 )
return - V_223 ;
V_221 = F_96 ( V_46 -> V_222 , V_74 ) ;
return ( V_221 ) ? : - V_223 ;
}
static void F_97 ( struct V_224 * V_225 )
{
struct V_226 * V_162 = F_98 ( V_225 ) ;
struct V_8 * V_46 = F_99 ( V_225 ) ;
T_2 V_227 ;
F_16 ( V_46 -> V_50 -> V_33 , L_31 , V_46 -> V_4 ) ;
F_100 ( V_162 , V_225 ) ;
V_227 = F_55 ( V_46 -> V_163 + V_228 ) ;
while ( V_227 ) {
unsigned int V_229 , V_221 ;
V_229 = F_101 ( V_227 ) ;
V_227 &= ~ F_21 ( V_229 ) ;
V_221 = F_102 ( V_46 -> V_222 , V_229 ) ;
if ( ! V_221 ) {
F_10 ( V_46 -> V_50 -> V_33 , L_32 , V_229 ) ;
continue;
}
F_16 ( V_46 -> V_50 -> V_33 , L_33 , V_229 ) ;
if ( V_46 -> V_230 & F_21 ( V_229 ) ) {
T_2 V_37 , V_231 , V_232 ;
unsigned long V_166 ;
V_37 = F_55 ( V_46 -> V_163 + V_220 ) ;
do {
F_58 ( & V_46 -> V_168 , V_166 ) ;
V_232 = F_55 ( V_46 -> V_163 +
V_233 ) ;
if ( V_37 & F_21 ( V_229 ) )
V_232 &= ~ F_21 ( V_229 ) ;
else
V_232 |= F_21 ( V_229 ) ;
F_90 ( V_232 ,
V_46 -> V_163 + V_233 ) ;
F_60 ( & V_46 -> V_168 , V_166 ) ;
V_231 = V_37 ;
V_37 = F_55 ( V_46 -> V_163 +
V_220 ) ;
} while ( ( V_37 & F_21 ( V_229 ) ) != ( V_231 & F_21 ( V_229 ) ) );
}
F_103 ( V_221 ) ;
}
F_104 ( V_162 , V_225 ) ;
}
static int F_105 ( struct V_234 * V_235 , unsigned int type )
{
struct V_236 * V_171 = F_106 ( V_235 ) ;
struct V_8 * V_46 = V_171 -> V_237 ;
T_2 V_49 = F_21 ( V_235 -> V_238 ) ;
T_2 V_232 ;
T_2 V_239 ;
T_2 V_37 ;
unsigned long V_166 ;
int V_65 ;
V_65 = F_24 ( V_46 , V_235 -> V_238 , V_70 ) ;
if ( V_65 < 0 )
return V_65 ;
F_57 ( V_46 -> V_167 ) ;
F_58 ( & V_46 -> V_168 , V_166 ) ;
V_37 = F_55 ( V_46 -> V_163 + V_164 ) ;
V_37 &= ~ V_49 ;
F_59 ( V_37 , V_46 -> V_163 + V_164 ) ;
F_60 ( & V_46 -> V_168 , V_166 ) ;
if ( type & V_240 )
F_107 ( V_235 , V_241 ) ;
else
F_107 ( V_235 , V_242 ) ;
F_58 ( & V_46 -> V_168 , V_166 ) ;
F_108 ( V_171 ) ;
V_239 = F_55 ( V_171 -> V_163 + V_243 ) ;
V_232 = F_55 ( V_171 -> V_163 + V_233 ) ;
switch ( type ) {
case V_240 :
V_46 -> V_230 |= V_49 ;
V_239 |= V_49 ;
V_37 = F_89 ( V_46 -> V_163 + V_220 ) ;
if ( V_37 & V_49 )
V_232 &= ~ V_49 ;
else
V_232 |= V_49 ;
break;
case V_244 :
V_46 -> V_230 &= ~ V_49 ;
V_239 |= V_49 ;
V_232 |= V_49 ;
break;
case V_245 :
V_46 -> V_230 &= ~ V_49 ;
V_239 |= V_49 ;
V_232 &= ~ V_49 ;
break;
case V_246 :
V_46 -> V_230 &= ~ V_49 ;
V_239 &= ~ V_49 ;
V_232 |= V_49 ;
break;
case V_247 :
V_46 -> V_230 &= ~ V_49 ;
V_239 &= ~ V_49 ;
V_232 &= ~ V_49 ;
break;
default:
F_109 ( V_171 ) ;
F_60 ( & V_46 -> V_168 , V_166 ) ;
F_61 ( V_46 -> V_167 ) ;
return - V_18 ;
}
F_59 ( V_239 , V_171 -> V_163 + V_243 ) ;
F_59 ( V_232 , V_171 -> V_163 + V_233 ) ;
F_109 ( V_171 ) ;
F_60 ( & V_46 -> V_168 , V_166 ) ;
F_61 ( V_46 -> V_167 ) ;
return 0 ;
}
static void F_110 ( struct V_234 * V_235 )
{
struct V_236 * V_171 = F_106 ( V_235 ) ;
struct V_8 * V_46 = V_171 -> V_237 ;
F_57 ( V_46 -> V_167 ) ;
V_46 -> V_248 = F_111 ( V_171 , V_249 ) ;
F_112 ( V_171 , ~ V_171 -> V_250 , V_249 ) ;
F_61 ( V_46 -> V_167 ) ;
}
static void F_113 ( struct V_234 * V_235 )
{
struct V_236 * V_171 = F_106 ( V_235 ) ;
struct V_8 * V_46 = V_171 -> V_237 ;
F_57 ( V_46 -> V_167 ) ;
F_112 ( V_171 , V_46 -> V_248 , V_249 ) ;
F_61 ( V_46 -> V_167 ) ;
}
static void F_114 ( struct V_234 * V_235 )
{
struct V_236 * V_171 = F_106 ( V_235 ) ;
struct V_8 * V_46 = V_171 -> V_237 ;
F_57 ( V_46 -> V_167 ) ;
F_115 ( V_235 ) ;
}
static void F_116 ( struct V_234 * V_235 )
{
struct V_236 * V_171 = F_106 ( V_235 ) ;
struct V_8 * V_46 = V_171 -> V_237 ;
F_117 ( V_235 ) ;
F_61 ( V_46 -> V_167 ) ;
}
static int F_118 ( struct V_194 * V_195 ,
struct V_2 * V_3 )
{
struct V_51 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
unsigned int V_251 = V_252 | V_253 | V_254 ;
struct V_236 * V_171 ;
int V_65 ;
int V_5 , V_189 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_255 ) {
F_119 ( & V_195 -> V_33 , L_34 ,
V_46 -> V_4 ) ;
continue;
}
V_65 = F_57 ( V_46 -> V_167 ) ;
if ( V_65 ) {
F_10 ( & V_195 -> V_33 , L_35 ,
V_46 -> V_4 ) ;
continue;
}
V_46 -> V_222 = F_120 ( V_46 -> V_197 , 32 ,
& V_256 , NULL ) ;
if ( ! V_46 -> V_222 ) {
F_119 ( & V_195 -> V_33 , L_36 ,
V_46 -> V_4 ) ;
F_61 ( V_46 -> V_167 ) ;
continue;
}
V_65 = F_121 ( V_46 -> V_222 , 32 , 1 ,
L_37 , V_242 ,
V_251 , 0 , V_257 ) ;
if ( V_65 ) {
F_10 ( & V_195 -> V_33 , L_38 ,
V_46 -> V_4 ) ;
F_122 ( V_46 -> V_222 ) ;
F_61 ( V_46 -> V_167 ) ;
continue;
}
F_59 ( 0xffffffff , V_46 -> V_163 + V_249 ) ;
F_59 ( 0xffffffff , V_46 -> V_163 + V_258 ) ;
V_171 = F_123 ( V_46 -> V_222 , 0 ) ;
V_171 -> V_163 = V_46 -> V_163 ;
V_171 -> V_237 = V_46 ;
V_171 -> V_259 [ 0 ] . V_260 . V_49 = V_249 ;
V_171 -> V_259 [ 0 ] . V_260 . V_261 = V_262 ;
V_171 -> V_259 [ 0 ] . V_162 . V_263 = V_264 ;
V_171 -> V_259 [ 0 ] . V_162 . V_265 = F_117 ;
V_171 -> V_259 [ 0 ] . V_162 . V_266 = F_115 ;
V_171 -> V_259 [ 0 ] . V_162 . V_267 = F_114 ;
V_171 -> V_259 [ 0 ] . V_162 . V_268 = F_116 ;
V_171 -> V_259 [ 0 ] . V_162 . V_269 = V_270 ;
V_171 -> V_259 [ 0 ] . V_162 . V_271 = F_110 ;
V_171 -> V_259 [ 0 ] . V_162 . V_272 = F_113 ;
V_171 -> V_259 [ 0 ] . V_162 . V_273 = F_105 ;
V_171 -> V_274 = F_124 ( V_46 -> V_14 ) ;
F_125 ( V_46 -> V_229 ,
F_97 , V_46 ) ;
for ( V_189 = 0 ; V_189 < 32 ; V_189 ++ )
F_96 ( V_46 -> V_222 , V_189 ) ;
F_61 ( V_46 -> V_167 ) ;
}
return 0 ;
}
static int F_126 ( struct V_194 * V_195 ,
struct V_2 * V_3 )
{
struct V_51 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
struct V_161 * V_171 ;
int V_65 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_255 ) {
F_119 ( & V_195 -> V_33 , L_34 ,
V_46 -> V_4 ) ;
continue;
}
V_46 -> V_161 = V_275 ;
V_171 = & V_46 -> V_161 ;
V_171 -> V_172 = V_46 -> V_13 ;
V_171 -> V_218 = V_46 -> V_14 ;
V_171 -> V_31 = & V_195 -> V_33 ;
V_171 -> V_197 = V_46 -> V_197 ;
V_171 -> V_276 = V_46 -> V_4 ;
V_65 = F_127 ( V_171 , V_46 ) ;
if ( V_65 ) {
F_10 ( & V_195 -> V_33 , L_39 ,
V_171 -> V_276 , V_65 ) ;
goto V_277;
}
}
F_118 ( V_195 , V_3 ) ;
return 0 ;
V_277:
for ( -- V_5 , -- V_46 ; V_5 >= 0 ; -- V_5 , -- V_46 ) {
if ( ! V_46 -> V_255 )
continue;
F_128 ( & V_46 -> V_161 ) ;
}
return V_65 ;
}
static int F_129 ( struct V_194 * V_195 ,
struct V_2 * V_3 )
{
struct V_51 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_255 )
continue;
F_128 ( & V_46 -> V_161 ) ;
}
return 0 ;
}
static int F_130 ( struct V_8 * V_46 ,
struct V_2 * V_3 )
{
struct V_278 V_279 ;
void T_5 * V_172 ;
if ( F_131 ( V_46 -> V_197 , 0 , & V_279 ) ) {
F_10 ( V_3 -> V_33 , L_40 ) ;
return - V_280 ;
}
V_46 -> V_163 = F_132 ( V_3 -> V_33 , & V_279 ) ;
if ( F_78 ( V_46 -> V_163 ) )
return F_79 ( V_46 -> V_163 ) ;
if ( F_133 ( V_46 -> V_197 ,
L_41 ) ) {
struct V_24 * V_281 ;
V_281 = F_134 ( V_46 -> V_197 -> V_31 ,
L_42 , 0 ) ;
if ( ! V_281 ) {
if ( F_131 ( V_46 -> V_197 , 1 , & V_279 ) ) {
F_10 ( V_3 -> V_33 , L_40 ) ;
return - V_280 ;
}
V_172 = F_132 ( V_3 -> V_33 , & V_279 ) ;
if ( F_78 ( V_172 ) )
return F_79 ( V_172 ) ;
V_282 . V_283 =
F_135 ( & V_279 ) - 4 ;
V_282 . V_4 =
L_43 ;
V_46 -> V_103 = F_136 ( V_3 -> V_33 ,
V_172 ,
& V_282 ) ;
}
}
V_46 -> V_229 = F_137 ( V_46 -> V_197 , 0 ) ;
V_46 -> V_167 = F_138 ( V_46 -> V_197 , 0 ) ;
if ( F_78 ( V_46 -> V_167 ) )
return F_79 ( V_46 -> V_167 ) ;
return F_139 ( V_46 -> V_167 ) ;
}
static struct V_51 * F_140 (
struct V_2 * V_235 ,
struct V_194 * V_195 )
{
const struct V_284 * V_285 ;
struct V_24 * V_281 = V_195 -> V_33 . V_197 ;
struct V_24 * V_25 ;
struct V_51 * V_11 ;
struct V_8 * V_46 ;
int V_286 , V_287 , V_288 , V_289 , V_5 , V_189 ;
V_285 = F_73 ( V_290 , V_281 ) ;
V_11 = (struct V_51 * ) V_285 -> V_37 ;
F_72 (node, np) {
if ( ! F_141 ( V_25 , L_44 , NULL ) )
continue;
V_46 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! strcmp ( V_46 -> V_4 , V_25 -> V_4 ) ) {
V_46 -> V_197 = V_25 ;
if ( ! F_130 ( V_46 , V_235 ) )
V_46 -> V_255 = true ;
break;
}
}
}
V_286 = V_11 -> V_291 ;
V_287 = V_11 -> V_292 ;
V_289 = V_11 -> V_293 ;
V_288 = V_11 -> V_294 ;
V_46 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
int V_295 = 0 ;
F_142 ( & V_46 -> V_168 ) ;
V_46 -> V_50 = V_235 ;
V_46 -> V_13 = V_11 -> V_14 ;
V_11 -> V_14 += V_46 -> V_14 ;
for ( V_189 = 0 ; V_189 < 4 ; V_189 ++ ) {
struct V_296 * V_297 = & V_46 -> V_67 [ V_189 ] ;
struct V_298 * V_124 = & V_46 -> V_124 [ V_189 ] ;
int V_299 ;
if ( V_295 >= V_46 -> V_14 )
break;
if ( V_297 -> V_74 >= 0 ) {
if ( V_297 -> type & V_71 )
V_287 = V_297 -> V_74 ;
else
V_286 = V_297 -> V_74 ;
} else {
V_297 -> V_74 = ( V_297 -> type & V_71 ) ?
V_287 : V_286 ;
}
if ( V_124 -> V_74 >= 0 ) {
if ( V_297 -> type & V_71 )
V_289 = V_124 -> V_74 ;
else
V_288 = V_124 -> V_74 ;
} else {
V_124 -> V_74 = ( V_297 -> type & V_71 ) ?
V_289 : V_288 ;
}
F_16 ( V_235 -> V_33 , L_45 ,
V_5 , V_189 , V_297 -> V_74 , V_124 -> V_74 ) ;
V_299 = ( V_297 -> type & ( V_75 |
V_76 ) ) ? 8 : 4 ;
if ( V_297 -> type & V_71 )
V_287 += V_299 ;
else
V_286 += V_299 ;
if ( ( V_124 -> V_125 == V_126 ) ||
( V_124 -> V_125 == V_127 ) )
V_299 = 8 ;
else
V_299 = 4 ;
if ( V_297 -> type & V_71 )
V_289 += V_299 ;
else
V_288 += V_299 ;
V_295 += 8 ;
}
for ( V_189 = 0 ; V_189 < V_11 -> V_53 ; V_189 ++ ) {
int V_9 = 0 ;
if ( V_11 -> V_54 [ V_189 ] . V_15 == V_46 -> V_17 ) {
V_9 = V_11 -> V_54 [ V_189 ] . V_9 ;
V_46 -> V_77 |= F_21 ( V_9 ) ;
}
}
for ( V_189 = 0 ; V_189 < V_11 -> V_57 ; V_189 ++ ) {
int V_9 = 0 ;
if ( V_11 -> V_58 [ V_189 ] . V_17 == V_46 -> V_17 ) {
V_9 = V_11 -> V_58 [ V_189 ] . V_9 ;
V_46 -> V_81 |= F_21 ( V_9 ) ;
}
}
}
return V_11 ;
}
static int T_6 F_143 ( struct V_196 * V_33 )
{
struct V_2 * V_3 = F_144 ( V_33 ) ;
int V_65 = F_145 ( V_3 -> V_215 ) ;
if ( V_65 )
return V_65 ;
if ( V_3 -> V_11 -> type == V_146 ) {
V_65 = F_22 ( V_3 -> V_73 , V_300 ,
& V_301 ) ;
if ( V_65 ) {
F_146 ( V_3 -> V_215 ) ;
return V_65 ;
}
}
return 0 ;
}
static int T_6 F_147 ( struct V_196 * V_33 )
{
struct V_2 * V_3 = F_144 ( V_33 ) ;
int V_65 = F_25 ( V_3 -> V_73 , V_300 ,
V_301 |
V_302 ) ;
if ( V_65 )
return V_65 ;
return F_146 ( V_3 -> V_215 ) ;
}
static int F_148 ( struct V_194 * V_195 )
{
struct V_2 * V_3 ;
struct V_196 * V_33 = & V_195 -> V_33 ;
struct V_51 * V_11 ;
struct V_24 * V_25 = V_195 -> V_33 . V_197 , * V_281 ;
struct V_278 * V_279 ;
void T_5 * V_172 ;
int V_65 ;
if ( ! V_33 -> V_197 ) {
F_10 ( V_33 , L_46 ) ;
return - V_303 ;
}
V_3 = F_11 ( V_33 , sizeof( struct V_2 ) , V_34 ) ;
if ( ! V_3 )
return - V_35 ;
V_3 -> V_33 = V_33 ;
V_11 = F_140 ( V_3 , V_195 ) ;
if ( ! V_11 ) {
F_10 ( V_33 , L_47 ) ;
return - V_18 ;
}
V_3 -> V_11 = V_11 ;
V_281 = F_134 ( V_25 , L_48 , 0 ) ;
if ( V_281 ) {
V_3 -> V_73 = F_149 ( V_281 ) ;
if ( F_78 ( V_3 -> V_73 ) )
return F_79 ( V_3 -> V_73 ) ;
} else {
V_279 = F_150 ( V_195 , V_304 , 0 ) ;
V_172 = F_132 ( & V_195 -> V_33 , V_279 ) ;
if ( F_78 ( V_172 ) )
return F_79 ( V_172 ) ;
V_282 . V_283 = F_135 ( V_279 ) - 4 ;
V_282 . V_4 = L_49 ;
V_3 -> V_73 = F_136 ( & V_195 -> V_33 , V_172 ,
& V_282 ) ;
V_3 -> V_305 = F_135 ( V_279 ) ;
if ( V_11 -> type == V_145 && V_3 -> V_305 < 0x200 ) {
V_279 = F_150 ( V_195 , V_304 , 1 ) ;
V_172 = F_132 ( & V_195 -> V_33 , V_279 ) ;
if ( F_78 ( V_172 ) )
return F_79 ( V_172 ) ;
V_282 . V_283 =
F_135 ( V_279 ) - 4 ;
V_282 . V_4 = L_50 ;
V_3 -> V_103 = F_136 ( & V_195 -> V_33 ,
V_172 ,
& V_282 ) ;
}
}
V_281 = F_134 ( V_25 , L_42 , 0 ) ;
if ( V_281 ) {
V_3 -> V_72 = F_149 ( V_281 ) ;
if ( F_78 ( V_3 -> V_72 ) )
return F_79 ( V_3 -> V_72 ) ;
}
V_65 = F_126 ( V_195 , V_3 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_85 ( V_195 , V_3 ) ;
if ( V_65 ) {
F_129 ( V_195 , V_3 ) ;
return V_65 ;
}
F_151 ( V_195 , V_3 ) ;
return 0 ;
}
static int T_7 F_152 ( void )
{
return F_153 ( & V_306 ) ;
}
