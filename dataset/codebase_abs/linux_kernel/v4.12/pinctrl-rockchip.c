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
static int F_20 ( struct V_8 * V_51 , int V_9 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
struct V_53 * V_11 = V_3 -> V_11 ;
int V_54 = ( V_9 / 8 ) ;
struct V_55 * V_55 ;
unsigned int V_56 ;
int V_46 , V_57 , V_48 , V_58 ;
T_1 V_47 ;
if ( V_54 > 3 )
return - V_18 ;
if ( V_51 -> V_59 [ V_54 ] . type & V_60 ) {
F_10 ( V_3 -> V_33 , L_3 , V_9 ) ;
return - V_18 ;
}
if ( V_51 -> V_59 [ V_54 ] . type & V_61 )
return V_62 ;
V_55 = ( V_51 -> V_59 [ V_54 ] . type & V_63 )
? V_3 -> V_64 : V_3 -> V_65 ;
V_58 = V_51 -> V_59 [ V_54 ] . type ;
V_46 = V_51 -> V_59 [ V_54 ] . V_66 ;
if ( V_58 & V_67 ) {
if ( ( V_9 % 8 ) >= 4 )
V_46 += 0x4 ;
V_47 = ( V_9 % 4 ) * 4 ;
V_48 = 0xf ;
} else if ( V_58 & V_68 ) {
if ( ( V_9 % 8 ) >= 5 )
V_46 += 0x4 ;
V_47 = ( V_9 % 8 % 5 ) * 3 ;
V_48 = 0x7 ;
} else {
V_47 = ( V_9 % 8 ) * 2 ;
V_48 = 0x3 ;
}
if ( V_11 -> V_69 && ( V_58 & V_70 ) )
V_11 -> V_69 ( V_51 -> V_17 , V_9 , & V_46 , & V_47 , & V_48 ) ;
V_57 = F_21 ( V_55 , V_46 , & V_56 ) ;
if ( V_57 )
return V_57 ;
return ( ( V_56 >> V_47 ) & V_48 ) ;
}
static int F_22 ( struct V_8 * V_51 ,
int V_9 , int V_38 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
int V_54 = ( V_9 / 8 ) ;
if ( V_54 > 3 )
return - V_18 ;
if ( V_51 -> V_59 [ V_54 ] . type & V_60 ) {
F_10 ( V_3 -> V_33 , L_3 , V_9 ) ;
return - V_18 ;
}
if ( V_51 -> V_59 [ V_54 ] . type & V_61 ) {
if ( V_38 != V_62 ) {
F_10 ( V_3 -> V_33 ,
L_4 , V_9 ) ;
return - V_71 ;
}
}
return 0 ;
}
static int F_23 ( struct V_8 * V_51 , int V_9 , int V_38 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
struct V_53 * V_11 = V_3 -> V_11 ;
int V_54 = ( V_9 / 8 ) ;
struct V_55 * V_55 ;
int V_46 , V_57 , V_48 , V_58 ;
T_1 V_47 ;
T_2 V_37 , V_72 ;
V_57 = F_22 ( V_51 , V_9 , V_38 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_51 -> V_59 [ V_54 ] . type & V_61 )
return 0 ;
F_16 ( V_3 -> V_33 , L_5 ,
V_51 -> V_17 , V_9 , V_38 ) ;
V_55 = ( V_51 -> V_59 [ V_54 ] . type & V_63 )
? V_3 -> V_64 : V_3 -> V_65 ;
V_58 = V_51 -> V_59 [ V_54 ] . type ;
V_46 = V_51 -> V_59 [ V_54 ] . V_66 ;
if ( V_58 & V_67 ) {
if ( ( V_9 % 8 ) >= 4 )
V_46 += 0x4 ;
V_47 = ( V_9 % 4 ) * 4 ;
V_48 = 0xf ;
} else if ( V_58 & V_68 ) {
if ( ( V_9 % 8 ) >= 5 )
V_46 += 0x4 ;
V_47 = ( V_9 % 8 % 5 ) * 3 ;
V_48 = 0x7 ;
} else {
V_47 = ( V_9 % 8 ) * 2 ;
V_48 = 0x3 ;
}
if ( V_11 -> V_69 && ( V_58 & V_70 ) )
V_11 -> V_69 ( V_51 -> V_17 , V_9 , & V_46 , & V_47 , & V_48 ) ;
V_37 = ( V_48 << ( V_47 + 16 ) ) ;
V_72 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_38 & V_48 ) << V_47 ;
V_57 = F_24 ( V_55 , V_46 , V_72 , V_37 ) ;
return V_57 ;
}
static void F_25 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
if ( V_51 -> V_17 == 0 ) {
* V_55 = V_3 -> V_64 ;
* V_46 = V_74 ;
} else {
* V_46 = V_75 ;
* V_55 = V_3 -> V_65 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_76 ;
}
* V_46 += ( ( V_73 / V_77 ) * 4 ) ;
* V_47 = ( V_73 % V_77 ) ;
* V_47 *= V_78 ;
}
static void F_26 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
if ( V_51 -> V_17 == 0 ) {
* V_55 = V_3 -> V_64 ;
* V_46 = V_79 ;
} else {
* V_55 = V_3 -> V_65 ;
* V_46 = V_80 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_81 ;
}
* V_46 += ( ( V_73 / V_82 ) * 4 ) ;
* V_47 = V_73 % V_82 ;
* V_47 *= V_83 ;
}
static void F_27 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
* V_55 = V_3 -> V_65 ;
* V_46 = V_84 ;
* V_46 += V_51 -> V_17 * V_85 ;
* V_46 += ( V_73 / V_86 ) * 4 ;
* V_47 = V_73 % V_86 ;
}
static void F_28 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
if ( V_51 -> V_17 == 0 && V_73 < 12 ) {
* V_55 = V_3 -> V_64 ? V_3 -> V_64
: V_51 -> V_87 ;
* V_46 = V_3 -> V_64 ? V_88 : 0 ;
* V_46 += ( ( V_73 / V_89 ) * 4 ) ;
* V_47 = V_73 % V_89 ;
* V_47 *= V_90 ;
} else {
* V_55 = V_3 -> V_87 ? V_3 -> V_87
: V_3 -> V_65 ;
* V_46 = V_3 -> V_87 ? 0 : V_91 ;
* V_46 -= 4 ;
* V_46 += V_51 -> V_17 * V_92 ;
* V_46 += ( ( V_73 / V_89 ) * 4 ) ;
* V_47 = 7 - ( V_73 % V_89 ) ;
* V_47 *= V_90 ;
}
}
static void F_29 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
if ( V_51 -> V_17 == 0 ) {
* V_55 = V_3 -> V_64 ;
* V_46 = V_88 ;
* V_46 += ( ( V_73 / V_89 ) * 4 ) ;
* V_47 = V_73 % V_89 ;
* V_47 *= V_90 ;
} else {
* V_55 = V_3 -> V_65 ;
* V_46 = V_93 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_92 ;
* V_46 += ( ( V_73 / V_89 ) * 4 ) ;
* V_47 = ( V_73 % V_89 ) ;
* V_47 *= V_90 ;
}
}
static void F_30 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
if ( V_51 -> V_17 == 0 ) {
* V_55 = V_3 -> V_64 ;
* V_46 = V_94 ;
* V_46 += ( ( V_73 / V_95 ) * 4 ) ;
* V_47 = V_73 % V_95 ;
* V_47 *= V_96 ;
} else {
* V_55 = V_3 -> V_65 ;
* V_46 = V_97 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_98 ;
* V_46 += ( ( V_73 / V_95 ) * 4 ) ;
* V_47 = ( V_73 % V_95 ) ;
* V_47 *= V_96 ;
}
}
static void F_31 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
* V_55 = V_3 -> V_65 ;
* V_46 = V_99 ;
* V_46 += V_51 -> V_17 * V_92 ;
* V_46 += ( ( V_73 / V_89 ) * 4 ) ;
* V_47 = ( V_73 % V_89 ) ;
* V_47 *= V_90 ;
}
static void F_32 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
* V_55 = V_3 -> V_65 ;
* V_46 = V_100 ;
* V_46 += V_51 -> V_17 * V_98 ;
* V_46 += ( ( V_73 / V_95 ) * 4 ) ;
* V_47 = ( V_73 % V_95 ) ;
* V_47 *= V_96 ;
}
static void F_33 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
if ( V_51 -> V_17 == 0 ) {
* V_55 = V_3 -> V_64 ;
* V_46 = V_101 ;
* V_46 += ( ( V_73 / V_89 ) * 4 ) ;
* V_47 = V_73 % V_89 ;
* V_47 *= V_90 ;
} else {
* V_55 = V_3 -> V_65 ;
* V_46 = V_102 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_92 ;
* V_46 += ( ( V_73 / V_89 ) * 4 ) ;
* V_47 = ( V_73 % V_89 ) ;
* V_47 *= V_90 ;
}
}
static void F_34 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
if ( V_51 -> V_17 == 0 ) {
* V_55 = V_3 -> V_64 ;
* V_46 = V_103 ;
* V_46 += ( ( V_73 / V_95 ) * 4 ) ;
* V_47 = V_73 % V_95 ;
* V_47 *= V_96 ;
} else {
* V_55 = V_3 -> V_65 ;
* V_46 = V_104 ;
* V_46 -= 0x10 ;
* V_46 += V_51 -> V_17 * V_98 ;
* V_46 += ( ( V_73 / V_95 ) * 4 ) ;
* V_47 = ( V_73 % V_95 ) ;
* V_47 *= V_96 ;
}
}
static void F_35 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
if ( ( V_51 -> V_17 == 0 ) || ( V_51 -> V_17 == 1 ) ) {
* V_55 = V_3 -> V_64 ;
* V_46 = V_105 ;
* V_46 += V_51 -> V_17 * V_92 ;
* V_46 += ( ( V_73 / V_89 ) * 4 ) ;
* V_47 = V_73 % V_89 ;
* V_47 *= V_90 ;
} else {
* V_55 = V_3 -> V_65 ;
* V_46 = V_106 ;
* V_46 -= 0x20 ;
* V_46 += V_51 -> V_17 * V_92 ;
* V_46 += ( ( V_73 / V_89 ) * 4 ) ;
* V_47 = ( V_73 % V_89 ) ;
* V_47 *= V_90 ;
}
}
static void F_36 ( struct V_8 * V_51 ,
int V_73 , struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
int V_107 = ( V_73 / 8 ) ;
if ( ( V_51 -> V_17 == 0 ) || ( V_51 -> V_17 == 1 ) )
* V_55 = V_3 -> V_64 ;
else
* V_55 = V_3 -> V_65 ;
* V_46 = V_51 -> V_108 [ V_107 ] . V_66 ;
if ( ( V_51 -> V_108 [ V_107 ] . V_109 == V_110 ) ||
( V_51 -> V_108 [ V_107 ] . V_109 == V_111 ) )
* V_47 = ( V_73 % 8 ) * 3 ;
else
* V_47 = ( V_73 % 8 ) * 2 ;
}
static int F_37 ( struct V_8 * V_51 ,
int V_73 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
struct V_53 * V_11 = V_3 -> V_11 ;
struct V_55 * V_55 ;
int V_46 , V_57 ;
T_2 V_37 , V_112 , V_113 ;
T_1 V_47 ;
int V_109 = V_51 -> V_108 [ V_73 / 8 ] . V_109 ;
V_11 -> V_114 ( V_51 , V_73 , & V_55 , & V_46 , & V_47 ) ;
switch ( V_109 ) {
case V_110 :
case V_111 :
V_113 = V_115 ;
switch ( V_47 ) {
case 0 ... 12 :
break;
case 15 :
V_57 = F_21 ( V_55 , V_46 , & V_37 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_21 ( V_55 , V_46 + 0x4 , & V_112 ) ;
if ( V_57 )
return V_57 ;
V_37 >>= 15 ;
V_112 &= 0x3 ;
V_112 <<= 1 ;
V_37 |= V_112 ;
return V_116 [ V_109 ] [ V_37 ] ;
case 18 ... 21 :
V_46 += 4 ;
V_47 -= 16 ;
break;
default:
F_10 ( V_3 -> V_33 , L_6 ,
V_47 , V_109 ) ;
return - V_18 ;
}
break;
case V_117 :
case V_118 :
case V_119 :
V_113 = V_96 ;
break;
default:
F_10 ( V_3 -> V_33 , L_7 ,
V_109 ) ;
return - V_18 ;
}
V_57 = F_21 ( V_55 , V_46 , & V_37 ) ;
if ( V_57 )
return V_57 ;
V_37 >>= V_47 ;
V_37 &= ( 1 << V_113 ) - 1 ;
return V_116 [ V_109 ] [ V_37 ] ;
}
static int F_38 ( struct V_8 * V_51 ,
int V_73 , int V_120 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
struct V_53 * V_11 = V_3 -> V_11 ;
struct V_55 * V_55 ;
int V_46 , V_57 , V_5 ;
T_2 V_37 , V_72 , V_113 , V_112 ;
T_1 V_47 ;
int V_109 = V_51 -> V_108 [ V_73 / 8 ] . V_109 ;
F_16 ( V_3 -> V_33 , L_8 ,
V_51 -> V_17 , V_73 , V_120 ) ;
V_11 -> V_114 ( V_51 , V_73 , & V_55 , & V_46 , & V_47 ) ;
V_57 = - V_18 ;
for ( V_5 = 0 ; V_5 < F_19 ( V_116 [ V_109 ] ) ; V_5 ++ ) {
if ( V_116 [ V_109 ] [ V_5 ] == V_120 ) {
V_57 = V_5 ;
break;
} else if ( V_116 [ V_109 ] [ V_5 ] < 0 ) {
V_57 = V_116 [ V_109 ] [ V_5 ] ;
break;
}
}
if ( V_57 < 0 ) {
F_10 ( V_3 -> V_33 , L_9 ,
V_120 ) ;
return V_57 ;
}
switch ( V_109 ) {
case V_110 :
case V_111 :
V_113 = V_115 ;
switch ( V_47 ) {
case 0 ... 12 :
break;
case 15 :
V_37 = ( V_57 & 0x1 ) << 15 ;
V_112 = ( V_57 >> 0x1 ) & 0x3 ;
V_72 = F_39 ( 15 ) | F_39 ( 31 ) ;
V_37 |= F_39 ( 31 ) ;
V_57 = F_24 ( V_55 , V_46 , V_72 , V_37 ) ;
if ( V_57 )
return V_57 ;
V_72 = 0x3 | ( 0x3 << 16 ) ;
V_112 |= ( 0x3 << 16 ) ;
V_46 += 0x4 ;
V_57 = F_24 ( V_55 , V_46 , V_72 , V_112 ) ;
return V_57 ;
case 18 ... 21 :
V_46 += 4 ;
V_47 -= 16 ;
break;
default:
F_10 ( V_3 -> V_33 , L_6 ,
V_47 , V_109 ) ;
return - V_18 ;
}
break;
case V_117 :
case V_118 :
case V_119 :
V_113 = V_96 ;
break;
default:
F_10 ( V_3 -> V_33 , L_7 ,
V_109 ) ;
return - V_18 ;
}
V_37 = ( ( 1 << V_113 ) - 1 ) << ( V_47 + 16 ) ;
V_72 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_57 << V_47 ) ;
V_57 = F_24 ( V_55 , V_46 , V_72 , V_37 ) ;
return V_57 ;
}
static int F_40 ( struct V_8 * V_51 , int V_73 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
struct V_53 * V_11 = V_3 -> V_11 ;
struct V_55 * V_55 ;
int V_46 , V_57 , V_121 ;
T_1 V_47 ;
T_2 V_37 ;
if ( V_11 -> type == V_122 )
return V_123 ;
V_11 -> V_124 ( V_51 , V_73 , & V_55 , & V_46 , & V_47 ) ;
V_57 = F_21 ( V_55 , V_46 , & V_37 ) ;
if ( V_57 )
return V_57 ;
switch ( V_11 -> type ) {
case V_125 :
return ! ( V_37 & F_39 ( V_47 ) )
? V_126
: V_123 ;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
V_121 = V_51 -> V_121 [ V_73 / 8 ] ;
V_37 >>= V_47 ;
V_37 &= ( 1 << V_90 ) - 1 ;
return V_132 [ V_121 ] [ V_37 ] ;
default:
F_10 ( V_3 -> V_33 , L_10 ) ;
return - V_18 ;
} ;
}
static int F_41 ( struct V_8 * V_51 ,
int V_73 , int V_133 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
struct V_53 * V_11 = V_3 -> V_11 ;
struct V_55 * V_55 ;
int V_46 , V_57 , V_5 , V_121 ;
T_1 V_47 ;
T_2 V_37 , V_72 ;
F_16 ( V_3 -> V_33 , L_11 ,
V_51 -> V_17 , V_73 , V_133 ) ;
if ( V_11 -> type == V_122 )
return V_133 ? - V_18 : 0 ;
V_11 -> V_124 ( V_51 , V_73 , & V_55 , & V_46 , & V_47 ) ;
switch ( V_11 -> type ) {
case V_125 :
V_37 = F_39 ( V_47 + 16 ) ;
if ( V_133 == V_123 )
V_37 |= F_39 ( V_47 ) ;
V_57 = F_42 ( V_55 , V_46 , V_37 ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
V_121 = V_51 -> V_121 [ V_73 / 8 ] ;
V_57 = - V_18 ;
for ( V_5 = 0 ; V_5 < F_19 ( V_132 [ V_121 ] ) ;
V_5 ++ ) {
if ( V_132 [ V_121 ] [ V_5 ] == V_133 ) {
V_57 = V_5 ;
break;
}
}
if ( V_57 < 0 ) {
F_10 ( V_3 -> V_33 , L_12 ,
V_133 ) ;
return V_57 ;
}
V_37 = ( ( 1 << V_90 ) - 1 ) << ( V_47 + 16 ) ;
V_72 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_57 << V_47 ) ;
V_57 = F_24 ( V_55 , V_46 , V_72 , V_37 ) ;
break;
default:
F_10 ( V_3 -> V_33 , L_10 ) ;
return - V_18 ;
}
return V_57 ;
}
static int F_43 ( struct V_8 * V_51 ,
int V_73 ,
struct V_55 * * V_55 ,
int * V_46 , T_1 * V_47 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
* V_55 = V_3 -> V_65 ;
* V_46 = V_134 ;
* V_46 += V_51 -> V_17 * V_135 ;
* V_46 += ( ( V_73 / V_136 ) * 4 ) ;
* V_47 = V_73 % V_136 ;
return 0 ;
}
static int F_44 ( struct V_8 * V_51 , int V_73 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
struct V_53 * V_11 = V_3 -> V_11 ;
struct V_55 * V_55 ;
int V_46 , V_57 ;
T_1 V_47 ;
T_2 V_37 ;
V_57 = V_11 -> V_137 ( V_51 , V_73 , & V_55 , & V_46 , & V_47 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_21 ( V_55 , V_46 , & V_37 ) ;
if ( V_57 )
return V_57 ;
V_37 >>= V_47 ;
return V_37 & 0x1 ;
}
static int F_45 ( struct V_8 * V_51 ,
int V_73 , int V_138 )
{
struct V_2 * V_3 = V_51 -> V_52 ;
struct V_53 * V_11 = V_3 -> V_11 ;
struct V_55 * V_55 ;
int V_46 , V_57 ;
T_1 V_47 ;
T_2 V_37 , V_72 ;
F_16 ( V_3 -> V_33 , L_13 ,
V_51 -> V_17 , V_73 , V_138 ) ;
V_57 = V_11 -> V_137 ( V_51 , V_73 , & V_55 , & V_46 , & V_47 ) ;
if ( V_57 )
return V_57 ;
V_37 = F_39 ( V_47 + 16 ) | ( V_138 << V_47 ) ;
V_72 = F_39 ( V_47 + 16 ) | F_39 ( V_47 ) ;
return F_24 ( V_55 , V_46 , V_72 , V_37 ) ;
}
static int F_46 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_139 ;
}
static const char * F_47 ( struct V_19 * V_20 ,
unsigned V_21 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_140 [ V_21 ] . V_4 ;
}
static int F_48 ( struct V_19 * V_20 ,
unsigned V_21 , const char * const * * V_7 ,
unsigned * const V_141 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
* V_7 = V_3 -> V_140 [ V_21 ] . V_7 ;
* V_141 = V_3 -> V_140 [ V_21 ] . V_6 ;
return 0 ;
}
static int F_49 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_40 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
const unsigned int * V_22 = V_3 -> V_7 [ V_40 ] . V_22 ;
const struct V_142 * V_37 = V_3 -> V_7 [ V_40 ] . V_37 ;
struct V_8 * V_51 ;
int V_143 , V_57 = 0 ;
F_16 ( V_3 -> V_33 , L_14 ,
V_3 -> V_140 [ V_21 ] . V_4 , V_3 -> V_7 [ V_40 ] . V_4 ) ;
for ( V_143 = 0 ; V_143 < V_3 -> V_7 [ V_40 ] . V_23 ; V_143 ++ ) {
V_51 = F_2 ( V_3 , V_22 [ V_143 ] ) ;
V_57 = F_23 ( V_51 , V_22 [ V_143 ] - V_51 -> V_13 ,
V_37 [ V_143 ] . V_144 ) ;
if ( V_57 )
break;
}
if ( V_57 ) {
for ( V_143 -- ; V_143 >= 0 ; V_143 -- )
F_23 ( V_51 , V_22 [ V_143 ] - V_51 -> V_13 , 0 ) ;
return V_57 ;
}
return 0 ;
}
static int F_50 ( struct V_145 * V_146 , unsigned V_66 )
{
struct V_8 * V_51 = F_51 ( V_146 ) ;
T_2 V_37 ;
V_37 = F_52 ( V_51 -> V_147 + V_148 ) ;
return ! ( V_37 & F_39 ( V_66 ) ) ;
}
static int F_53 ( struct V_145 * V_146 ,
int V_9 , bool V_149 )
{
struct V_8 * V_51 ;
int V_57 ;
unsigned long V_150 ;
T_2 V_37 ;
V_51 = F_51 ( V_146 ) ;
V_57 = F_23 ( V_51 , V_9 , V_62 ) ;
if ( V_57 < 0 )
return V_57 ;
F_54 ( V_51 -> V_151 ) ;
F_55 ( & V_51 -> V_152 , V_150 ) ;
V_37 = F_52 ( V_51 -> V_147 + V_148 ) ;
if ( ! V_149 )
V_37 |= F_39 ( V_9 ) ;
else
V_37 &= ~ F_39 ( V_9 ) ;
F_56 ( V_37 , V_51 -> V_147 + V_148 ) ;
F_57 ( & V_51 -> V_152 , V_150 ) ;
F_58 ( V_51 -> V_151 ) ;
return 0 ;
}
static int F_59 ( struct V_19 * V_20 ,
struct V_153 * V_154 ,
unsigned V_66 , bool V_149 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_145 * V_146 ;
int V_9 ;
V_146 = V_154 -> V_155 ;
V_9 = V_66 - V_146 -> V_156 ;
F_16 ( V_3 -> V_33 , L_15 ,
V_66 , V_154 -> V_4 , V_9 , V_149 ? L_16 : L_17 ) ;
return F_53 ( V_146 , V_66 - V_146 -> V_156 ,
V_149 ) ;
}
static bool F_60 ( struct V_53 * V_11 ,
enum V_157 V_133 )
{
switch ( V_11 -> type ) {
case V_125 :
return ( V_133 == V_126 ||
V_133 == V_123 ) ;
case V_122 :
return V_133 ? false : true ;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
return ( V_133 != V_126 ) ;
}
return false ;
}
static int F_61 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_42 , unsigned V_44 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_51 = F_2 ( V_3 , V_9 ) ;
enum V_157 V_158 ;
T_2 V_159 ;
int V_5 ;
int V_160 ;
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ ) {
V_158 = F_62 ( V_42 [ V_5 ] ) ;
V_159 = F_63 ( V_42 [ V_5 ] ) ;
switch ( V_158 ) {
case V_123 :
V_160 = F_41 ( V_51 , V_9 - V_51 -> V_13 ,
V_158 ) ;
if ( V_160 )
return V_160 ;
break;
case V_161 :
case V_162 :
case V_126 :
case V_163 :
if ( ! F_60 ( V_3 -> V_11 , V_158 ) )
return - V_71 ;
if ( ! V_159 )
return - V_18 ;
V_160 = F_41 ( V_51 , V_9 - V_51 -> V_13 ,
V_158 ) ;
if ( V_160 )
return V_160 ;
break;
case V_164 :
F_64 ( & V_51 -> V_145 ,
V_9 - V_51 -> V_13 , V_159 ) ;
V_160 = F_53 ( & V_51 -> V_145 ,
V_9 - V_51 -> V_13 , false ) ;
if ( V_160 )
return V_160 ;
break;
case V_165 :
if ( ! V_3 -> V_11 -> V_114 )
return - V_71 ;
V_160 = F_38 ( V_51 ,
V_9 - V_51 -> V_13 , V_159 ) ;
if ( V_160 < 0 )
return V_160 ;
break;
case V_166 :
if ( ! V_3 -> V_11 -> V_137 )
return - V_71 ;
V_160 = F_45 ( V_51 ,
V_9 - V_51 -> V_13 , V_159 ) ;
if ( V_160 < 0 )
return V_160 ;
break;
default:
return - V_71 ;
break;
}
}
return 0 ;
}
static int F_65 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_167 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_51 = F_2 ( V_3 , V_9 ) ;
enum V_157 V_158 = F_62 ( * V_167 ) ;
T_3 V_159 ;
int V_160 ;
switch ( V_158 ) {
case V_123 :
if ( F_40 ( V_51 , V_9 - V_51 -> V_13 ) != V_158 )
return - V_18 ;
V_159 = 0 ;
break;
case V_161 :
case V_162 :
case V_126 :
case V_163 :
if ( ! F_60 ( V_3 -> V_11 , V_158 ) )
return - V_71 ;
if ( F_40 ( V_51 , V_9 - V_51 -> V_13 ) != V_158 )
return - V_18 ;
V_159 = 1 ;
break;
case V_164 :
V_160 = F_20 ( V_51 , V_9 - V_51 -> V_13 ) ;
if ( V_160 != V_62 )
return - V_18 ;
V_160 = F_66 ( & V_51 -> V_145 , V_9 - V_51 -> V_13 ) ;
if ( V_160 < 0 )
return V_160 ;
V_159 = V_160 ? 1 : 0 ;
break;
case V_165 :
if ( ! V_3 -> V_11 -> V_114 )
return - V_71 ;
V_160 = F_37 ( V_51 , V_9 - V_51 -> V_13 ) ;
if ( V_160 < 0 )
return V_160 ;
V_159 = V_160 ;
break;
case V_166 :
if ( ! V_3 -> V_11 -> V_137 )
return - V_71 ;
V_160 = F_44 ( V_51 , V_9 - V_51 -> V_13 ) ;
if ( V_160 < 0 )
return V_160 ;
V_159 = V_160 ;
break;
default:
return - V_71 ;
break;
}
* V_167 = F_67 ( V_158 , V_159 ) ;
return 0 ;
}
static void F_68 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_24 * V_168 ;
F_69 (np, child) {
if ( F_70 ( V_169 , V_168 ) )
continue;
V_3 -> V_139 ++ ;
V_3 -> V_6 += F_71 ( V_168 ) ;
}
}
static int F_72 ( struct V_24 * V_25 ,
struct V_1 * V_29 ,
struct V_2 * V_3 ,
T_2 V_170 )
{
struct V_8 * V_51 ;
int V_171 ;
const T_4 * V_172 ;
int V_15 ;
int V_5 , V_173 ;
int V_57 ;
F_16 ( V_3 -> V_33 , L_18 , V_170 , V_25 -> V_4 ) ;
V_29 -> V_4 = V_25 -> V_4 ;
V_172 = F_73 ( V_25 , L_19 , & V_171 ) ;
V_171 /= sizeof( * V_172 ) ;
if ( ! V_171 || V_171 % 4 ) {
F_10 ( V_3 -> V_33 , L_20 ) ;
return - V_18 ;
}
V_29 -> V_23 = V_171 / 4 ;
V_29 -> V_22 = F_11 ( V_3 -> V_33 , V_29 -> V_23 * sizeof( unsigned int ) ,
V_34 ) ;
V_29 -> V_37 = F_11 ( V_3 -> V_33 , V_29 -> V_23 *
sizeof( struct V_142 ) ,
V_34 ) ;
if ( ! V_29 -> V_22 || ! V_29 -> V_37 )
return - V_35 ;
for ( V_5 = 0 , V_173 = 0 ; V_5 < V_171 ; V_5 += 4 , V_173 ++ ) {
const T_4 * V_174 ;
struct V_24 * V_175 ;
V_15 = F_74 ( * V_172 ++ ) ;
V_51 = F_3 ( V_3 , V_15 ) ;
if ( F_75 ( V_51 ) )
return F_76 ( V_51 ) ;
V_29 -> V_22 [ V_173 ] = V_51 -> V_13 + F_74 ( * V_172 ++ ) ;
V_29 -> V_37 [ V_173 ] . V_144 = F_74 ( * V_172 ++ ) ;
V_174 = V_172 ++ ;
if ( ! V_174 )
return - V_18 ;
V_175 = F_77 ( F_78 ( V_174 ) ) ;
V_57 = F_79 ( V_175 , NULL ,
& V_29 -> V_37 [ V_173 ] . V_42 , & V_29 -> V_37 [ V_173 ] . V_45 ) ;
if ( V_57 )
return V_57 ;
}
return 0 ;
}
static int F_80 ( struct V_24 * V_25 ,
struct V_2 * V_3 ,
T_2 V_170 )
{
struct V_24 * V_168 ;
struct V_176 * V_144 ;
struct V_1 * V_29 ;
int V_57 ;
static T_2 V_177 ;
T_2 V_5 = 0 ;
F_16 ( V_3 -> V_33 , L_21 , V_170 , V_25 -> V_4 ) ;
V_144 = & V_3 -> V_140 [ V_170 ] ;
V_144 -> V_4 = V_25 -> V_4 ;
V_144 -> V_6 = F_71 ( V_25 ) ;
if ( V_144 -> V_6 <= 0 )
return 0 ;
V_144 -> V_7 = F_11 ( V_3 -> V_33 ,
V_144 -> V_6 * sizeof( char * ) , V_34 ) ;
if ( ! V_144 -> V_7 )
return - V_35 ;
F_69 (np, child) {
V_144 -> V_7 [ V_5 ] = V_168 -> V_4 ;
V_29 = & V_3 -> V_7 [ V_177 ++ ] ;
V_57 = F_72 ( V_168 , V_29 , V_3 , V_5 ++ ) ;
if ( V_57 ) {
F_14 ( V_168 ) ;
return V_57 ;
}
}
return 0 ;
}
static int F_81 ( struct V_178 * V_179 ,
struct V_2 * V_3 )
{
struct V_180 * V_33 = & V_179 -> V_33 ;
struct V_24 * V_25 = V_33 -> V_181 ;
struct V_24 * V_168 ;
int V_57 ;
int V_5 ;
F_68 ( V_3 , V_25 ) ;
F_16 ( & V_179 -> V_33 , L_22 , V_3 -> V_139 ) ;
F_16 ( & V_179 -> V_33 , L_23 , V_3 -> V_6 ) ;
V_3 -> V_140 = F_11 ( V_33 , V_3 -> V_139 *
sizeof( struct V_176 ) ,
V_34 ) ;
if ( ! V_3 -> V_140 ) {
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
F_69 (np, child) {
if ( F_70 ( V_169 , V_168 ) )
continue;
V_57 = F_80 ( V_168 , V_3 , V_5 ++ ) ;
if ( V_57 ) {
F_10 ( & V_179 -> V_33 , L_26 ) ;
F_14 ( V_168 ) ;
return V_57 ;
}
}
return 0 ;
}
static int F_82 ( struct V_178 * V_179 ,
struct V_2 * V_3 )
{
struct V_182 * V_183 = & V_3 -> V_184 ;
struct V_185 * V_186 , * V_187 ;
struct V_8 * V_188 ;
int V_9 , V_51 , V_57 ;
int V_189 ;
V_183 -> V_4 = L_27 ;
V_183 -> V_190 = V_191 ;
V_183 -> V_192 = & V_193 ;
V_183 -> V_194 = & V_195 ;
V_183 -> V_196 = & V_197 ;
V_186 = F_11 ( & V_179 -> V_33 , sizeof( * V_186 ) *
V_3 -> V_11 -> V_14 , V_34 ) ;
if ( ! V_186 ) {
F_10 ( & V_179 -> V_33 , L_28 ) ;
return - V_35 ;
}
V_183 -> V_22 = V_186 ;
V_183 -> V_23 = V_3 -> V_11 -> V_14 ;
V_187 = V_186 ;
for ( V_51 = 0 , V_189 = 0 ; V_51 < V_3 -> V_11 -> V_16 ; V_51 ++ ) {
V_188 = & V_3 -> V_11 -> V_12 [ V_51 ] ;
for ( V_9 = 0 ; V_9 < V_188 -> V_14 ; V_9 ++ , V_189 ++ ) {
V_187 -> V_198 = V_189 ;
V_187 -> V_4 = F_83 ( V_34 , L_29 ,
V_188 -> V_4 , V_9 ) ;
V_187 ++ ;
}
}
V_57 = F_81 ( V_179 , V_3 ) ;
if ( V_57 )
return V_57 ;
V_3 -> V_199 = F_84 ( & V_179 -> V_33 , V_183 , V_3 ) ;
if ( F_75 ( V_3 -> V_199 ) ) {
F_10 ( & V_179 -> V_33 , L_30 ) ;
return F_76 ( V_3 -> V_199 ) ;
}
for ( V_51 = 0 ; V_51 < V_3 -> V_11 -> V_16 ; ++ V_51 ) {
V_188 = & V_3 -> V_11 -> V_12 [ V_51 ] ;
V_188 -> V_200 . V_4 = V_188 -> V_4 ;
V_188 -> V_200 . V_201 = V_51 ;
V_188 -> V_200 . V_13 = V_188 -> V_13 ;
V_188 -> V_200 . V_156 = V_188 -> V_145 . V_156 ;
V_188 -> V_200 . V_23 = V_188 -> V_145 . V_202 ;
V_188 -> V_200 . V_155 = & V_188 -> V_145 ;
F_85 ( V_3 -> V_199 , & V_188 -> V_200 ) ;
}
return 0 ;
}
static void F_64 ( struct V_145 * V_155 , unsigned V_66 , int V_203 )
{
struct V_8 * V_51 = F_51 ( V_155 ) ;
void T_5 * V_46 = V_51 -> V_147 + V_204 ;
unsigned long V_150 ;
T_2 V_37 ;
F_54 ( V_51 -> V_151 ) ;
F_55 ( & V_51 -> V_152 , V_150 ) ;
V_37 = F_86 ( V_46 ) ;
V_37 &= ~ F_39 ( V_66 ) ;
if ( V_203 )
V_37 |= F_39 ( V_66 ) ;
F_87 ( V_37 , V_46 ) ;
F_57 ( & V_51 -> V_152 , V_150 ) ;
F_58 ( V_51 -> V_151 ) ;
}
static int F_66 ( struct V_145 * V_155 , unsigned V_66 )
{
struct V_8 * V_51 = F_51 ( V_155 ) ;
T_2 V_37 ;
F_54 ( V_51 -> V_151 ) ;
V_37 = F_86 ( V_51 -> V_147 + V_205 ) ;
F_58 ( V_51 -> V_151 ) ;
V_37 >>= V_66 ;
V_37 &= 1 ;
return V_37 ;
}
static int F_88 ( struct V_145 * V_155 , unsigned V_66 )
{
return F_89 ( V_155 -> V_156 + V_66 ) ;
}
static int F_90 ( struct V_145 * V_155 ,
unsigned V_66 , int V_203 )
{
F_64 ( V_155 , V_66 , V_203 ) ;
return F_91 ( V_155 -> V_156 + V_66 ) ;
}
static int F_92 ( struct V_145 * V_155 , unsigned V_66 )
{
struct V_8 * V_51 = F_51 ( V_155 ) ;
unsigned int V_206 ;
if ( ! V_51 -> V_207 )
return - V_208 ;
V_206 = F_93 ( V_51 -> V_207 , V_66 ) ;
return ( V_206 ) ? : - V_208 ;
}
static void F_94 ( struct V_209 * V_210 )
{
struct V_211 * V_146 = F_95 ( V_210 ) ;
struct V_8 * V_51 = F_96 ( V_210 ) ;
T_2 V_212 ;
F_16 ( V_51 -> V_52 -> V_33 , L_31 , V_51 -> V_4 ) ;
F_97 ( V_146 , V_210 ) ;
V_212 = F_52 ( V_51 -> V_147 + V_213 ) ;
while ( V_212 ) {
unsigned int V_214 , V_206 ;
V_214 = F_98 ( V_212 ) ;
V_212 &= ~ F_39 ( V_214 ) ;
V_206 = F_99 ( V_51 -> V_207 , V_214 ) ;
if ( ! V_206 ) {
F_10 ( V_51 -> V_52 -> V_33 , L_32 , V_214 ) ;
continue;
}
F_16 ( V_51 -> V_52 -> V_33 , L_33 , V_214 ) ;
if ( V_51 -> V_215 & F_39 ( V_214 ) ) {
T_2 V_37 , V_216 , V_217 ;
unsigned long V_150 ;
V_37 = F_52 ( V_51 -> V_147 + V_205 ) ;
do {
F_55 ( & V_51 -> V_152 , V_150 ) ;
V_217 = F_52 ( V_51 -> V_147 +
V_218 ) ;
if ( V_37 & F_39 ( V_214 ) )
V_217 &= ~ F_39 ( V_214 ) ;
else
V_217 |= F_39 ( V_214 ) ;
F_87 ( V_217 ,
V_51 -> V_147 + V_218 ) ;
F_57 ( & V_51 -> V_152 , V_150 ) ;
V_216 = V_37 ;
V_37 = F_52 ( V_51 -> V_147 +
V_205 ) ;
} while ( ( V_37 & F_39 ( V_214 ) ) != ( V_216 & F_39 ( V_214 ) ) );
}
F_100 ( V_206 ) ;
}
F_101 ( V_146 , V_210 ) ;
}
static int F_102 ( struct V_219 * V_220 , unsigned int type )
{
struct V_221 * V_155 = F_103 ( V_220 ) ;
struct V_8 * V_51 = V_155 -> V_222 ;
T_2 V_48 = F_39 ( V_220 -> V_223 ) ;
T_2 V_217 ;
T_2 V_224 ;
T_2 V_37 ;
unsigned long V_150 ;
int V_57 ;
V_57 = F_23 ( V_51 , V_220 -> V_223 , V_62 ) ;
if ( V_57 < 0 )
return V_57 ;
F_54 ( V_51 -> V_151 ) ;
F_55 ( & V_51 -> V_152 , V_150 ) ;
V_37 = F_52 ( V_51 -> V_147 + V_148 ) ;
V_37 &= ~ V_48 ;
F_56 ( V_37 , V_51 -> V_147 + V_148 ) ;
F_57 ( & V_51 -> V_152 , V_150 ) ;
if ( type & V_225 )
F_104 ( V_220 , V_226 ) ;
else
F_104 ( V_220 , V_227 ) ;
F_55 ( & V_51 -> V_152 , V_150 ) ;
F_105 ( V_155 ) ;
V_224 = F_52 ( V_155 -> V_147 + V_228 ) ;
V_217 = F_52 ( V_155 -> V_147 + V_218 ) ;
switch ( type ) {
case V_225 :
V_51 -> V_215 |= V_48 ;
V_224 |= V_48 ;
V_37 = F_86 ( V_51 -> V_147 + V_205 ) ;
if ( V_37 & V_48 )
V_217 &= ~ V_48 ;
else
V_217 |= V_48 ;
break;
case V_229 :
V_51 -> V_215 &= ~ V_48 ;
V_224 |= V_48 ;
V_217 |= V_48 ;
break;
case V_230 :
V_51 -> V_215 &= ~ V_48 ;
V_224 |= V_48 ;
V_217 &= ~ V_48 ;
break;
case V_231 :
V_51 -> V_215 &= ~ V_48 ;
V_224 &= ~ V_48 ;
V_217 |= V_48 ;
break;
case V_232 :
V_51 -> V_215 &= ~ V_48 ;
V_224 &= ~ V_48 ;
V_217 &= ~ V_48 ;
break;
default:
F_106 ( V_155 ) ;
F_57 ( & V_51 -> V_152 , V_150 ) ;
F_58 ( V_51 -> V_151 ) ;
return - V_18 ;
}
F_56 ( V_224 , V_155 -> V_147 + V_228 ) ;
F_56 ( V_217 , V_155 -> V_147 + V_218 ) ;
F_106 ( V_155 ) ;
F_57 ( & V_51 -> V_152 , V_150 ) ;
F_58 ( V_51 -> V_151 ) ;
return 0 ;
}
static void F_107 ( struct V_219 * V_220 )
{
struct V_221 * V_155 = F_103 ( V_220 ) ;
struct V_8 * V_51 = V_155 -> V_222 ;
F_54 ( V_51 -> V_151 ) ;
V_51 -> V_233 = F_108 ( V_155 , V_234 ) ;
F_109 ( V_155 , ~ V_155 -> V_235 , V_234 ) ;
F_58 ( V_51 -> V_151 ) ;
}
static void F_110 ( struct V_219 * V_220 )
{
struct V_221 * V_155 = F_103 ( V_220 ) ;
struct V_8 * V_51 = V_155 -> V_222 ;
F_54 ( V_51 -> V_151 ) ;
F_109 ( V_155 , V_51 -> V_233 , V_234 ) ;
F_58 ( V_51 -> V_151 ) ;
}
static void F_111 ( struct V_219 * V_220 )
{
struct V_221 * V_155 = F_103 ( V_220 ) ;
struct V_8 * V_51 = V_155 -> V_222 ;
F_54 ( V_51 -> V_151 ) ;
F_112 ( V_220 ) ;
}
static void F_113 ( struct V_219 * V_220 )
{
struct V_221 * V_155 = F_103 ( V_220 ) ;
struct V_8 * V_51 = V_155 -> V_222 ;
F_114 ( V_220 ) ;
F_58 ( V_51 -> V_151 ) ;
}
static int F_115 ( struct V_178 * V_179 ,
struct V_2 * V_3 )
{
struct V_53 * V_11 = V_3 -> V_11 ;
struct V_8 * V_51 = V_11 -> V_12 ;
unsigned int V_236 = V_237 | V_238 | V_239 ;
struct V_221 * V_155 ;
int V_57 ;
int V_5 , V_173 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_51 ) {
if ( ! V_51 -> V_240 ) {
F_116 ( & V_179 -> V_33 , L_34 ,
V_51 -> V_4 ) ;
continue;
}
V_57 = F_54 ( V_51 -> V_151 ) ;
if ( V_57 ) {
F_10 ( & V_179 -> V_33 , L_35 ,
V_51 -> V_4 ) ;
continue;
}
V_51 -> V_207 = F_117 ( V_51 -> V_181 , 32 ,
& V_241 , NULL ) ;
if ( ! V_51 -> V_207 ) {
F_116 ( & V_179 -> V_33 , L_36 ,
V_51 -> V_4 ) ;
F_58 ( V_51 -> V_151 ) ;
continue;
}
V_57 = F_118 ( V_51 -> V_207 , 32 , 1 ,
L_37 , V_227 ,
V_236 , 0 , V_242 ) ;
if ( V_57 ) {
F_10 ( & V_179 -> V_33 , L_38 ,
V_51 -> V_4 ) ;
F_119 ( V_51 -> V_207 ) ;
F_58 ( V_51 -> V_151 ) ;
continue;
}
F_56 ( 0xffffffff , V_51 -> V_147 + V_234 ) ;
F_56 ( 0xffffffff , V_51 -> V_147 + V_243 ) ;
V_155 = F_120 ( V_51 -> V_207 , 0 ) ;
V_155 -> V_147 = V_51 -> V_147 ;
V_155 -> V_222 = V_51 ;
V_155 -> V_244 [ 0 ] . V_245 . V_48 = V_234 ;
V_155 -> V_244 [ 0 ] . V_245 . V_246 = V_247 ;
V_155 -> V_244 [ 0 ] . V_146 . V_248 = V_249 ;
V_155 -> V_244 [ 0 ] . V_146 . V_250 = F_114 ;
V_155 -> V_244 [ 0 ] . V_146 . V_251 = F_112 ;
V_155 -> V_244 [ 0 ] . V_146 . V_252 = F_111 ;
V_155 -> V_244 [ 0 ] . V_146 . V_253 = F_113 ;
V_155 -> V_244 [ 0 ] . V_146 . V_254 = V_255 ;
V_155 -> V_244 [ 0 ] . V_146 . V_256 = F_107 ;
V_155 -> V_244 [ 0 ] . V_146 . V_257 = F_110 ;
V_155 -> V_244 [ 0 ] . V_146 . V_258 = F_102 ;
V_155 -> V_259 = F_121 ( V_51 -> V_14 ) ;
F_122 ( V_51 -> V_214 ,
F_94 , V_51 ) ;
for ( V_173 = 0 ; V_173 < 32 ; V_173 ++ )
F_93 ( V_51 -> V_207 , V_173 ) ;
F_58 ( V_51 -> V_151 ) ;
}
return 0 ;
}
static int F_123 ( struct V_178 * V_179 ,
struct V_2 * V_3 )
{
struct V_53 * V_11 = V_3 -> V_11 ;
struct V_8 * V_51 = V_11 -> V_12 ;
struct V_145 * V_155 ;
int V_57 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_51 ) {
if ( ! V_51 -> V_240 ) {
F_116 ( & V_179 -> V_33 , L_34 ,
V_51 -> V_4 ) ;
continue;
}
V_51 -> V_145 = V_260 ;
V_155 = & V_51 -> V_145 ;
V_155 -> V_156 = V_51 -> V_13 ;
V_155 -> V_202 = V_51 -> V_14 ;
V_155 -> V_31 = & V_179 -> V_33 ;
V_155 -> V_181 = V_51 -> V_181 ;
V_155 -> V_261 = V_51 -> V_4 ;
V_57 = F_124 ( V_155 , V_51 ) ;
if ( V_57 ) {
F_10 ( & V_179 -> V_33 , L_39 ,
V_155 -> V_261 , V_57 ) ;
goto V_262;
}
}
F_115 ( V_179 , V_3 ) ;
return 0 ;
V_262:
for ( -- V_5 , -- V_51 ; V_5 >= 0 ; -- V_5 , -- V_51 ) {
if ( ! V_51 -> V_240 )
continue;
F_125 ( & V_51 -> V_145 ) ;
}
return V_57 ;
}
static int F_126 ( struct V_178 * V_179 ,
struct V_2 * V_3 )
{
struct V_53 * V_11 = V_3 -> V_11 ;
struct V_8 * V_51 = V_11 -> V_12 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_51 ) {
if ( ! V_51 -> V_240 )
continue;
F_125 ( & V_51 -> V_145 ) ;
}
return 0 ;
}
static int F_127 ( struct V_8 * V_51 ,
struct V_2 * V_3 )
{
struct V_263 V_264 ;
void T_5 * V_156 ;
if ( F_128 ( V_51 -> V_181 , 0 , & V_264 ) ) {
F_10 ( V_3 -> V_33 , L_40 ) ;
return - V_265 ;
}
V_51 -> V_147 = F_129 ( V_3 -> V_33 , & V_264 ) ;
if ( F_75 ( V_51 -> V_147 ) )
return F_76 ( V_51 -> V_147 ) ;
if ( F_130 ( V_51 -> V_181 ,
L_41 ) ) {
struct V_24 * V_266 ;
V_266 = F_131 ( V_51 -> V_181 -> V_31 ,
L_42 , 0 ) ;
if ( ! V_266 ) {
if ( F_128 ( V_51 -> V_181 , 1 , & V_264 ) ) {
F_10 ( V_3 -> V_33 , L_40 ) ;
return - V_265 ;
}
V_156 = F_129 ( V_3 -> V_33 , & V_264 ) ;
if ( F_75 ( V_156 ) )
return F_76 ( V_156 ) ;
V_267 . V_268 =
F_132 ( & V_264 ) - 4 ;
V_267 . V_4 =
L_43 ;
V_51 -> V_87 = F_133 ( V_3 -> V_33 ,
V_156 ,
& V_267 ) ;
}
}
V_51 -> V_214 = F_134 ( V_51 -> V_181 , 0 ) ;
V_51 -> V_151 = F_135 ( V_51 -> V_181 , 0 ) ;
if ( F_75 ( V_51 -> V_151 ) )
return F_76 ( V_51 -> V_151 ) ;
return F_136 ( V_51 -> V_151 ) ;
}
static struct V_53 * F_137 (
struct V_2 * V_220 ,
struct V_178 * V_179 )
{
const struct V_269 * V_270 ;
struct V_24 * V_266 = V_179 -> V_33 . V_181 ;
struct V_24 * V_25 ;
struct V_53 * V_11 ;
struct V_8 * V_51 ;
int V_271 , V_272 , V_273 , V_274 , V_5 , V_173 ;
V_270 = F_70 ( V_275 , V_266 ) ;
V_11 = (struct V_53 * ) V_270 -> V_37 ;
F_69 (node, np) {
if ( ! F_138 ( V_25 , L_44 , NULL ) )
continue;
V_51 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_51 ) {
if ( ! strcmp ( V_51 -> V_4 , V_25 -> V_4 ) ) {
V_51 -> V_181 = V_25 ;
if ( ! F_127 ( V_51 , V_220 ) )
V_51 -> V_240 = true ;
break;
}
}
}
V_271 = V_11 -> V_276 ;
V_272 = V_11 -> V_277 ;
V_274 = V_11 -> V_278 ;
V_273 = V_11 -> V_279 ;
V_51 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_51 ) {
int V_280 = 0 ;
F_139 ( & V_51 -> V_152 ) ;
V_51 -> V_52 = V_220 ;
V_51 -> V_13 = V_11 -> V_14 ;
V_11 -> V_14 += V_51 -> V_14 ;
for ( V_173 = 0 ; V_173 < 4 ; V_173 ++ ) {
struct V_281 * V_282 = & V_51 -> V_59 [ V_173 ] ;
struct V_283 * V_108 = & V_51 -> V_108 [ V_173 ] ;
int V_284 ;
if ( V_280 >= V_51 -> V_14 )
break;
if ( V_282 -> V_66 >= 0 ) {
if ( V_282 -> type & V_63 )
V_272 = V_282 -> V_66 ;
else
V_271 = V_282 -> V_66 ;
} else {
V_282 -> V_66 = ( V_282 -> type & V_63 ) ?
V_272 : V_271 ;
}
if ( V_108 -> V_66 >= 0 ) {
if ( V_282 -> type & V_63 )
V_274 = V_108 -> V_66 ;
else
V_273 = V_108 -> V_66 ;
} else {
V_108 -> V_66 = ( V_282 -> type & V_63 ) ?
V_274 : V_273 ;
}
F_16 ( V_220 -> V_33 , L_45 ,
V_5 , V_173 , V_282 -> V_66 , V_108 -> V_66 ) ;
V_284 = ( V_282 -> type & ( V_67 |
V_68 ) ) ? 8 : 4 ;
if ( V_282 -> type & V_63 )
V_272 += V_284 ;
else
V_271 += V_284 ;
if ( ( V_108 -> V_109 == V_110 ) ||
( V_108 -> V_109 == V_111 ) )
V_284 = 8 ;
else
V_284 = 4 ;
if ( V_282 -> type & V_63 )
V_274 += V_284 ;
else
V_273 += V_284 ;
V_280 += 8 ;
}
}
return V_11 ;
}
static int T_6 F_140 ( struct V_180 * V_33 )
{
struct V_2 * V_3 = F_141 ( V_33 ) ;
int V_57 = F_142 ( V_3 -> V_199 ) ;
if ( V_57 )
return V_57 ;
if ( V_3 -> V_11 -> type == V_129 ) {
V_57 = F_21 ( V_3 -> V_65 , V_285 ,
& V_286 ) ;
if ( V_57 ) {
F_143 ( V_3 -> V_199 ) ;
return V_57 ;
}
}
return 0 ;
}
static int T_6 F_144 ( struct V_180 * V_33 )
{
struct V_2 * V_3 = F_141 ( V_33 ) ;
int V_57 = F_42 ( V_3 -> V_65 , V_285 ,
V_286 |
V_287 ) ;
if ( V_57 )
return V_57 ;
return F_143 ( V_3 -> V_199 ) ;
}
static int F_145 ( struct V_178 * V_179 )
{
struct V_2 * V_3 ;
struct V_180 * V_33 = & V_179 -> V_33 ;
struct V_53 * V_11 ;
struct V_24 * V_25 = V_179 -> V_33 . V_181 , * V_266 ;
struct V_263 * V_264 ;
void T_5 * V_156 ;
int V_57 ;
if ( ! V_33 -> V_181 ) {
F_10 ( V_33 , L_46 ) ;
return - V_288 ;
}
V_3 = F_11 ( V_33 , sizeof( struct V_2 ) , V_34 ) ;
if ( ! V_3 )
return - V_35 ;
V_3 -> V_33 = V_33 ;
V_11 = F_137 ( V_3 , V_179 ) ;
if ( ! V_11 ) {
F_10 ( V_33 , L_47 ) ;
return - V_18 ;
}
V_3 -> V_11 = V_11 ;
V_266 = F_131 ( V_25 , L_48 , 0 ) ;
if ( V_266 ) {
V_3 -> V_65 = F_146 ( V_266 ) ;
if ( F_75 ( V_3 -> V_65 ) )
return F_76 ( V_3 -> V_65 ) ;
} else {
V_264 = F_147 ( V_179 , V_289 , 0 ) ;
V_156 = F_129 ( & V_179 -> V_33 , V_264 ) ;
if ( F_75 ( V_156 ) )
return F_76 ( V_156 ) ;
V_267 . V_268 = F_132 ( V_264 ) - 4 ;
V_267 . V_4 = L_49 ;
V_3 -> V_65 = F_133 ( & V_179 -> V_33 , V_156 ,
& V_267 ) ;
V_3 -> V_290 = F_132 ( V_264 ) ;
if ( V_11 -> type == V_128 && V_3 -> V_290 < 0x200 ) {
V_264 = F_147 ( V_179 , V_289 , 1 ) ;
V_156 = F_129 ( & V_179 -> V_33 , V_264 ) ;
if ( F_75 ( V_156 ) )
return F_76 ( V_156 ) ;
V_267 . V_268 =
F_132 ( V_264 ) - 4 ;
V_267 . V_4 = L_50 ;
V_3 -> V_87 = F_133 ( & V_179 -> V_33 ,
V_156 ,
& V_267 ) ;
}
}
V_266 = F_131 ( V_25 , L_42 , 0 ) ;
if ( V_266 ) {
V_3 -> V_64 = F_146 ( V_266 ) ;
if ( F_75 ( V_3 -> V_64 ) )
return F_76 ( V_3 -> V_64 ) ;
}
V_57 = F_123 ( V_179 , V_3 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_82 ( V_179 , V_3 ) ;
if ( V_57 ) {
F_126 ( V_179 , V_3 ) ;
return V_57 ;
}
F_148 ( V_179 , V_3 ) ;
return 0 ;
}
static int T_7 F_149 ( void )
{
return F_150 ( & V_291 ) ;
}
