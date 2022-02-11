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
static int F_18 ( struct V_8 * V_46 , int V_9 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
int V_48 = ( V_9 / 8 ) ;
struct V_49 * V_49 ;
unsigned int V_50 ;
int V_51 , V_52 , V_53 ;
T_1 V_54 ;
if ( V_48 > 3 )
return - V_18 ;
if ( V_46 -> V_55 [ V_48 ] . type & V_56 ) {
F_10 ( V_3 -> V_33 , L_3 , V_9 ) ;
return - V_18 ;
}
if ( V_46 -> V_55 [ V_48 ] . type & V_57 )
return V_58 ;
V_49 = ( V_46 -> V_55 [ V_48 ] . type & V_59 )
? V_3 -> V_60 : V_3 -> V_61 ;
V_53 = ( V_46 -> V_55 [ V_48 ] . type & V_62 ) ? 0xf : 0x3 ;
V_51 = V_46 -> V_55 [ V_48 ] . V_63 ;
if ( V_46 -> V_55 [ V_48 ] . type & V_62 ) {
if ( ( V_9 % 8 ) >= 4 )
V_51 += 0x4 ;
V_54 = ( V_9 % 4 ) * 4 ;
} else {
V_54 = ( V_9 % 8 ) * 2 ;
}
V_52 = F_19 ( V_49 , V_51 , & V_50 ) ;
if ( V_52 )
return V_52 ;
return ( ( V_50 >> V_54 ) & V_53 ) ;
}
static int F_20 ( struct V_8 * V_46 , int V_9 , int V_38 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
int V_48 = ( V_9 / 8 ) ;
struct V_49 * V_49 ;
int V_51 , V_52 , V_53 ;
unsigned long V_64 ;
T_1 V_54 ;
T_2 V_37 , V_65 ;
if ( V_48 > 3 )
return - V_18 ;
if ( V_46 -> V_55 [ V_48 ] . type & V_56 ) {
F_10 ( V_3 -> V_33 , L_3 , V_9 ) ;
return - V_18 ;
}
if ( V_46 -> V_55 [ V_48 ] . type & V_57 ) {
if ( V_38 != V_58 ) {
F_10 ( V_3 -> V_33 ,
L_4 , V_9 ) ;
return - V_66 ;
} else {
return 0 ;
}
}
F_16 ( V_3 -> V_33 , L_5 ,
V_46 -> V_17 , V_9 , V_38 ) ;
V_49 = ( V_46 -> V_55 [ V_48 ] . type & V_59 )
? V_3 -> V_60 : V_3 -> V_61 ;
V_53 = ( V_46 -> V_55 [ V_48 ] . type & V_62 ) ? 0xf : 0x3 ;
V_51 = V_46 -> V_55 [ V_48 ] . V_63 ;
if ( V_46 -> V_55 [ V_48 ] . type & V_62 ) {
if ( ( V_9 % 8 ) >= 4 )
V_51 += 0x4 ;
V_54 = ( V_9 % 4 ) * 4 ;
} else {
V_54 = ( V_9 % 8 ) * 2 ;
}
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = ( V_53 << ( V_54 + 16 ) ) ;
V_65 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_38 & V_53 ) << V_54 ;
V_52 = F_22 ( V_49 , V_51 , V_65 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
return V_52 ;
}
static void F_24 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_69 ;
} else {
* V_51 = V_70 ;
* V_49 = V_3 -> V_61 ;
* V_51 -= 0x10 ;
* V_51 += V_46 -> V_17 * V_71 ;
}
* V_51 += ( ( V_68 / V_72 ) * 4 ) ;
* V_54 = ( V_68 % V_72 ) ;
* V_54 *= V_73 ;
}
static void F_25 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_74 ;
} else {
* V_49 = V_3 -> V_61 ;
* V_51 = V_75 ;
* V_51 -= 0x10 ;
* V_51 += V_46 -> V_17 * V_76 ;
}
* V_51 += ( ( V_68 / V_77 ) * 4 ) ;
* V_54 = V_68 % V_77 ;
* V_54 *= V_78 ;
}
static void F_26 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
* V_49 = V_3 -> V_61 ;
* V_51 = V_79 ;
* V_51 += V_46 -> V_17 * V_80 ;
* V_51 += ( V_68 / V_81 ) * 4 ;
* V_54 = V_68 % V_81 ;
}
static void F_27 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 && V_68 < 12 ) {
* V_49 = V_3 -> V_60 ? V_3 -> V_60
: V_46 -> V_82 ;
* V_51 = V_3 -> V_60 ? V_83 : 0 ;
* V_51 += ( ( V_68 / V_84 ) * 4 ) ;
* V_54 = V_68 % V_84 ;
* V_54 *= V_85 ;
} else {
* V_49 = V_3 -> V_82 ? V_3 -> V_82
: V_3 -> V_61 ;
* V_51 = V_3 -> V_82 ? 0 : V_86 ;
* V_51 -= 4 ;
* V_51 += V_46 -> V_17 * V_87 ;
* V_51 += ( ( V_68 / V_84 ) * 4 ) ;
* V_54 = 7 - ( V_68 % V_84 ) ;
* V_54 *= V_85 ;
}
}
static void F_28 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_83 ;
* V_51 += ( ( V_68 / V_84 ) * 4 ) ;
* V_54 = V_68 % V_84 ;
* V_54 *= V_85 ;
} else {
* V_49 = V_3 -> V_61 ;
* V_51 = V_88 ;
* V_51 -= 0x10 ;
* V_51 += V_46 -> V_17 * V_87 ;
* V_51 += ( ( V_68 / V_84 ) * 4 ) ;
* V_54 = ( V_68 % V_84 ) ;
* V_54 *= V_85 ;
}
}
static void F_29 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_89 ;
* V_51 += ( ( V_68 / V_90 ) * 4 ) ;
* V_54 = V_68 % V_90 ;
* V_54 *= V_91 ;
} else {
* V_49 = V_3 -> V_61 ;
* V_51 = V_92 ;
* V_51 -= 0x10 ;
* V_51 += V_46 -> V_17 * V_93 ;
* V_51 += ( ( V_68 / V_90 ) * 4 ) ;
* V_54 = ( V_68 % V_90 ) ;
* V_54 *= V_91 ;
}
}
static void F_30 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
* V_49 = V_3 -> V_61 ;
* V_51 = V_94 ;
* V_51 += V_46 -> V_17 * V_87 ;
* V_51 += ( ( V_68 / V_84 ) * 4 ) ;
* V_54 = ( V_68 % V_84 ) ;
* V_54 *= V_85 ;
}
static void F_31 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
* V_49 = V_3 -> V_61 ;
* V_51 = V_95 ;
* V_51 += V_46 -> V_17 * V_93 ;
* V_51 += ( ( V_68 / V_90 ) * 4 ) ;
* V_54 = ( V_68 % V_90 ) ;
* V_54 *= V_91 ;
}
static void F_32 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_96 ;
* V_51 += ( ( V_68 / V_84 ) * 4 ) ;
* V_54 = V_68 % V_84 ;
* V_54 *= V_85 ;
} else {
* V_49 = V_3 -> V_61 ;
* V_51 = V_97 ;
* V_51 -= 0x10 ;
* V_51 += V_46 -> V_17 * V_87 ;
* V_51 += ( ( V_68 / V_84 ) * 4 ) ;
* V_54 = ( V_68 % V_84 ) ;
* V_54 *= V_85 ;
}
}
static void F_33 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_98 ;
* V_51 += ( ( V_68 / V_90 ) * 4 ) ;
* V_54 = V_68 % V_90 ;
* V_54 *= V_91 ;
} else {
* V_49 = V_3 -> V_61 ;
* V_51 = V_99 ;
* V_51 -= 0x10 ;
* V_51 += V_46 -> V_17 * V_93 ;
* V_51 += ( ( V_68 / V_90 ) * 4 ) ;
* V_54 = ( V_68 % V_90 ) ;
* V_54 *= V_91 ;
}
}
static void F_34 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( ( V_46 -> V_17 == 0 ) || ( V_46 -> V_17 == 1 ) ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_100 ;
* V_51 += V_46 -> V_17 * V_87 ;
* V_51 += ( ( V_68 / V_84 ) * 4 ) ;
* V_54 = V_68 % V_84 ;
* V_54 *= V_85 ;
} else {
* V_49 = V_3 -> V_61 ;
* V_51 = V_101 ;
* V_51 -= 0x20 ;
* V_51 += V_46 -> V_17 * V_87 ;
* V_51 += ( ( V_68 / V_84 ) * 4 ) ;
* V_54 = ( V_68 % V_84 ) ;
* V_54 *= V_85 ;
}
}
static void F_35 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
int V_102 = ( V_68 / 8 ) ;
if ( ( V_46 -> V_17 == 0 ) || ( V_46 -> V_17 == 1 ) )
* V_49 = V_3 -> V_60 ;
else
* V_49 = V_3 -> V_61 ;
* V_51 = V_46 -> V_103 [ V_102 ] . V_63 ;
if ( ( V_46 -> V_103 [ V_102 ] . V_104 == V_105 ) ||
( V_46 -> V_103 [ V_102 ] . V_104 == V_106 ) )
* V_54 = ( V_68 % 8 ) * 3 ;
else
* V_54 = ( V_68 % 8 ) * 2 ;
}
static int F_36 ( struct V_8 * V_46 ,
int V_68 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_107 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
int V_51 , V_52 ;
T_2 V_37 , V_108 , V_109 ;
T_1 V_54 ;
int V_104 = V_46 -> V_103 [ V_68 / 8 ] . V_104 ;
V_11 -> V_110 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
switch ( V_104 ) {
case V_105 :
case V_106 :
V_109 = V_111 ;
switch ( V_54 ) {
case 0 ... 12 :
break;
case 15 :
V_52 = F_19 ( V_49 , V_51 , & V_37 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_19 ( V_49 , V_51 + 0x4 , & V_108 ) ;
if ( V_52 )
return V_52 ;
V_37 >>= 15 ;
V_108 &= 0x3 ;
V_108 <<= 1 ;
V_37 |= V_108 ;
return V_112 [ V_104 ] [ V_37 ] ;
case 18 ... 21 :
V_51 += 4 ;
V_54 -= 16 ;
break;
default:
F_10 ( V_3 -> V_33 , L_6 ,
V_54 , V_104 ) ;
return - V_18 ;
}
break;
case V_113 :
case V_114 :
case V_115 :
V_109 = V_91 ;
break;
default:
F_10 ( V_3 -> V_33 , L_7 ,
V_104 ) ;
return - V_18 ;
}
V_52 = F_19 ( V_49 , V_51 , & V_37 ) ;
if ( V_52 )
return V_52 ;
V_37 >>= V_54 ;
V_37 &= ( 1 << V_109 ) - 1 ;
return V_112 [ V_104 ] [ V_37 ] ;
}
static int F_37 ( struct V_8 * V_46 ,
int V_68 , int V_116 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_107 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
unsigned long V_64 ;
int V_51 , V_52 , V_5 ;
T_2 V_37 , V_65 , V_109 , V_108 ;
T_1 V_54 ;
int V_104 = V_46 -> V_103 [ V_68 / 8 ] . V_104 ;
F_16 ( V_3 -> V_33 , L_8 ,
V_46 -> V_17 , V_68 , V_116 ) ;
V_11 -> V_110 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
V_52 = - V_18 ;
for ( V_5 = 0 ; V_5 < F_38 ( V_112 [ V_104 ] ) ; V_5 ++ ) {
if ( V_112 [ V_104 ] [ V_5 ] == V_116 ) {
V_52 = V_5 ;
break;
} else if ( V_112 [ V_104 ] [ V_5 ] < 0 ) {
V_52 = V_112 [ V_104 ] [ V_5 ] ;
break;
}
}
if ( V_52 < 0 ) {
F_10 ( V_3 -> V_33 , L_9 ,
V_116 ) ;
return V_52 ;
}
F_21 ( & V_46 -> V_67 , V_64 ) ;
switch ( V_104 ) {
case V_105 :
case V_106 :
V_109 = V_111 ;
switch ( V_54 ) {
case 0 ... 12 :
break;
case 15 :
V_37 = ( V_52 & 0x1 ) << 15 ;
V_108 = ( V_52 >> 0x1 ) & 0x3 ;
V_65 = F_39 ( 15 ) | F_39 ( 31 ) ;
V_37 |= F_39 ( 31 ) ;
V_52 = F_22 ( V_49 , V_51 , V_65 , V_37 ) ;
if ( V_52 ) {
F_23 ( & V_46 -> V_67 , V_64 ) ;
return V_52 ;
}
V_65 = 0x3 | ( 0x3 << 16 ) ;
V_108 |= ( 0x3 << 16 ) ;
V_51 += 0x4 ;
V_52 = F_22 ( V_49 , V_51 , V_65 , V_108 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
return V_52 ;
case 18 ... 21 :
V_51 += 4 ;
V_54 -= 16 ;
break;
default:
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_10 ( V_3 -> V_33 , L_6 ,
V_54 , V_104 ) ;
return - V_18 ;
}
break;
case V_113 :
case V_114 :
case V_115 :
V_109 = V_91 ;
break;
default:
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_10 ( V_3 -> V_33 , L_7 ,
V_104 ) ;
return - V_18 ;
}
V_37 = ( ( 1 << V_109 ) - 1 ) << ( V_54 + 16 ) ;
V_65 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_52 << V_54 ) ;
V_52 = F_22 ( V_49 , V_51 , V_65 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
return V_52 ;
}
static int F_40 ( struct V_8 * V_46 , int V_68 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_107 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
int V_51 , V_52 , V_117 ;
T_1 V_54 ;
T_2 V_37 ;
if ( V_11 -> type == V_118 )
return V_119 ;
V_11 -> V_120 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
V_52 = F_19 ( V_49 , V_51 , & V_37 ) ;
if ( V_52 )
return V_52 ;
switch ( V_11 -> type ) {
case V_121 :
return ! ( V_37 & F_39 ( V_54 ) )
? V_122
: V_119 ;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
V_117 = V_46 -> V_117 [ V_68 / 8 ] ;
V_37 >>= V_54 ;
V_37 &= ( 1 << V_85 ) - 1 ;
return V_128 [ V_117 ] [ V_37 ] ;
default:
F_10 ( V_3 -> V_33 , L_10 ) ;
return - V_18 ;
} ;
}
static int F_41 ( struct V_8 * V_46 ,
int V_68 , int V_129 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_107 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
int V_51 , V_52 , V_5 , V_117 ;
unsigned long V_64 ;
T_1 V_54 ;
T_2 V_37 , V_65 ;
F_16 ( V_3 -> V_33 , L_11 ,
V_46 -> V_17 , V_68 , V_129 ) ;
if ( V_11 -> type == V_118 )
return V_129 ? - V_18 : 0 ;
V_11 -> V_120 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
switch ( V_11 -> type ) {
case V_121 :
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_39 ( V_54 + 16 ) ;
if ( V_129 == V_119 )
V_37 |= F_39 ( V_54 ) ;
V_52 = F_42 ( V_49 , V_51 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
V_117 = V_46 -> V_117 [ V_68 / 8 ] ;
V_52 = - V_18 ;
for ( V_5 = 0 ; V_5 < F_38 ( V_128 [ V_117 ] ) ;
V_5 ++ ) {
if ( V_128 [ V_117 ] [ V_5 ] == V_129 ) {
V_52 = V_5 ;
break;
}
}
if ( V_52 < 0 ) {
F_10 ( V_3 -> V_33 , L_12 ,
V_129 ) ;
return V_52 ;
}
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = ( ( 1 << V_85 ) - 1 ) << ( V_54 + 16 ) ;
V_65 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_52 << V_54 ) ;
V_52 = F_22 ( V_49 , V_51 , V_65 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
break;
default:
F_10 ( V_3 -> V_33 , L_10 ) ;
return - V_18 ;
}
return V_52 ;
}
static int F_43 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_130 ;
}
static const char * F_44 ( struct V_19 * V_20 ,
unsigned V_21 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_131 [ V_21 ] . V_4 ;
}
static int F_45 ( struct V_19 * V_20 ,
unsigned V_21 , const char * const * * V_7 ,
unsigned * const V_132 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
* V_7 = V_3 -> V_131 [ V_21 ] . V_7 ;
* V_132 = V_3 -> V_131 [ V_21 ] . V_6 ;
return 0 ;
}
static int F_46 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_40 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
const unsigned int * V_22 = V_3 -> V_7 [ V_40 ] . V_22 ;
const struct V_133 * V_37 = V_3 -> V_7 [ V_40 ] . V_37 ;
struct V_8 * V_46 ;
int V_134 , V_52 = 0 ;
F_16 ( V_3 -> V_33 , L_13 ,
V_3 -> V_131 [ V_21 ] . V_4 , V_3 -> V_7 [ V_40 ] . V_4 ) ;
for ( V_134 = 0 ; V_134 < V_3 -> V_7 [ V_40 ] . V_23 ; V_134 ++ ) {
V_46 = F_2 ( V_3 , V_22 [ V_134 ] ) ;
V_52 = F_20 ( V_46 , V_22 [ V_134 ] - V_46 -> V_13 ,
V_37 [ V_134 ] . V_135 ) ;
if ( V_52 )
break;
}
if ( V_52 ) {
for ( V_134 -- ; V_134 >= 0 ; V_134 -- )
F_20 ( V_46 , V_22 [ V_134 ] - V_46 -> V_13 , 0 ) ;
return V_52 ;
}
return 0 ;
}
static int F_47 ( struct V_136 * V_137 , unsigned V_63 )
{
struct V_8 * V_46 = F_48 ( V_137 ) ;
T_2 V_37 ;
V_37 = F_49 ( V_46 -> V_138 + V_139 ) ;
return ! ( V_37 & F_39 ( V_63 ) ) ;
}
static int F_50 ( struct V_136 * V_137 ,
int V_9 , bool V_140 )
{
struct V_8 * V_46 ;
int V_52 ;
unsigned long V_64 ;
T_2 V_37 ;
V_46 = F_48 ( V_137 ) ;
V_52 = F_20 ( V_46 , V_9 , V_58 ) ;
if ( V_52 < 0 )
return V_52 ;
F_51 ( V_46 -> V_141 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_49 ( V_46 -> V_138 + V_139 ) ;
if ( ! V_140 )
V_37 |= F_39 ( V_9 ) ;
else
V_37 &= ~ F_39 ( V_9 ) ;
F_52 ( V_37 , V_46 -> V_138 + V_139 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_53 ( V_46 -> V_141 ) ;
return 0 ;
}
static int F_54 ( struct V_19 * V_20 ,
struct V_142 * V_143 ,
unsigned V_63 , bool V_140 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_136 * V_137 ;
int V_9 ;
V_137 = V_143 -> V_144 ;
V_9 = V_63 - V_137 -> V_145 ;
F_16 ( V_3 -> V_33 , L_14 ,
V_63 , V_143 -> V_4 , V_9 , V_140 ? L_15 : L_16 ) ;
return F_50 ( V_137 , V_63 - V_137 -> V_145 ,
V_140 ) ;
}
static bool F_55 ( struct V_107 * V_11 ,
enum V_146 V_129 )
{
switch ( V_11 -> type ) {
case V_121 :
return ( V_129 == V_122 ||
V_129 == V_119 ) ;
case V_118 :
return V_129 ? false : true ;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
return ( V_129 != V_122 ) ;
}
return false ;
}
static int F_56 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_42 , unsigned V_44 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_46 = F_2 ( V_3 , V_9 ) ;
enum V_146 V_147 ;
T_3 V_148 ;
int V_5 ;
int V_149 ;
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ ) {
V_147 = F_57 ( V_42 [ V_5 ] ) ;
V_148 = F_58 ( V_42 [ V_5 ] ) ;
switch ( V_147 ) {
case V_119 :
V_149 = F_41 ( V_46 , V_9 - V_46 -> V_13 ,
V_147 ) ;
if ( V_149 )
return V_149 ;
break;
case V_150 :
case V_151 :
case V_122 :
case V_152 :
if ( ! F_55 ( V_3 -> V_11 , V_147 ) )
return - V_66 ;
if ( ! V_148 )
return - V_18 ;
V_149 = F_41 ( V_46 , V_9 - V_46 -> V_13 ,
V_147 ) ;
if ( V_149 )
return V_149 ;
break;
case V_153 :
F_59 ( & V_46 -> V_136 ,
V_9 - V_46 -> V_13 , V_148 ) ;
V_149 = F_50 ( & V_46 -> V_136 ,
V_9 - V_46 -> V_13 , false ) ;
if ( V_149 )
return V_149 ;
break;
case V_154 :
if ( ! V_3 -> V_11 -> V_110 )
return - V_66 ;
V_149 = F_37 ( V_46 ,
V_9 - V_46 -> V_13 , V_148 ) ;
if ( V_149 < 0 )
return V_149 ;
break;
default:
return - V_66 ;
break;
}
}
return 0 ;
}
static int F_60 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_155 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_46 = F_2 ( V_3 , V_9 ) ;
enum V_146 V_147 = F_57 ( * V_155 ) ;
T_3 V_148 ;
int V_149 ;
switch ( V_147 ) {
case V_119 :
if ( F_40 ( V_46 , V_9 - V_46 -> V_13 ) != V_147 )
return - V_18 ;
V_148 = 0 ;
break;
case V_150 :
case V_151 :
case V_122 :
case V_152 :
if ( ! F_55 ( V_3 -> V_11 , V_147 ) )
return - V_66 ;
if ( F_40 ( V_46 , V_9 - V_46 -> V_13 ) != V_147 )
return - V_18 ;
V_148 = 1 ;
break;
case V_153 :
V_149 = F_18 ( V_46 , V_9 - V_46 -> V_13 ) ;
if ( V_149 != V_58 )
return - V_18 ;
V_149 = F_61 ( & V_46 -> V_136 , V_9 - V_46 -> V_13 ) ;
if ( V_149 < 0 )
return V_149 ;
V_148 = V_149 ? 1 : 0 ;
break;
case V_154 :
if ( ! V_3 -> V_11 -> V_110 )
return - V_66 ;
V_149 = F_36 ( V_46 , V_9 - V_46 -> V_13 ) ;
if ( V_149 < 0 )
return V_149 ;
V_148 = V_149 ;
break;
default:
return - V_66 ;
break;
}
* V_155 = F_62 ( V_147 , V_148 ) ;
return 0 ;
}
static void F_63 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_24 * V_156 ;
F_64 (np, child) {
if ( F_65 ( V_157 , V_156 ) )
continue;
V_3 -> V_130 ++ ;
V_3 -> V_6 += F_66 ( V_156 ) ;
}
}
static int F_67 ( struct V_24 * V_25 ,
struct V_1 * V_29 ,
struct V_2 * V_3 ,
T_2 V_158 )
{
struct V_8 * V_46 ;
int V_159 ;
const T_4 * V_160 ;
int V_15 ;
int V_5 , V_161 ;
int V_52 ;
F_16 ( V_3 -> V_33 , L_17 , V_158 , V_25 -> V_4 ) ;
V_29 -> V_4 = V_25 -> V_4 ;
V_160 = F_68 ( V_25 , L_18 , & V_159 ) ;
V_159 /= sizeof( * V_160 ) ;
if ( ! V_159 || V_159 % 4 ) {
F_10 ( V_3 -> V_33 , L_19 ) ;
return - V_18 ;
}
V_29 -> V_23 = V_159 / 4 ;
V_29 -> V_22 = F_11 ( V_3 -> V_33 , V_29 -> V_23 * sizeof( unsigned int ) ,
V_34 ) ;
V_29 -> V_37 = F_11 ( V_3 -> V_33 , V_29 -> V_23 *
sizeof( struct V_133 ) ,
V_34 ) ;
if ( ! V_29 -> V_22 || ! V_29 -> V_37 )
return - V_35 ;
for ( V_5 = 0 , V_161 = 0 ; V_5 < V_159 ; V_5 += 4 , V_161 ++ ) {
const T_4 * V_162 ;
struct V_24 * V_163 ;
V_15 = F_69 ( * V_160 ++ ) ;
V_46 = F_3 ( V_3 , V_15 ) ;
if ( F_70 ( V_46 ) )
return F_71 ( V_46 ) ;
V_29 -> V_22 [ V_161 ] = V_46 -> V_13 + F_69 ( * V_160 ++ ) ;
V_29 -> V_37 [ V_161 ] . V_135 = F_69 ( * V_160 ++ ) ;
V_162 = V_160 ++ ;
if ( ! V_162 )
return - V_18 ;
V_163 = F_72 ( F_73 ( V_162 ) ) ;
V_52 = F_74 ( V_163 , NULL ,
& V_29 -> V_37 [ V_161 ] . V_42 , & V_29 -> V_37 [ V_161 ] . V_45 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static int F_75 ( struct V_24 * V_25 ,
struct V_2 * V_3 ,
T_2 V_158 )
{
struct V_24 * V_156 ;
struct V_164 * V_135 ;
struct V_1 * V_29 ;
int V_52 ;
static T_2 V_165 ;
T_2 V_5 = 0 ;
F_16 ( V_3 -> V_33 , L_20 , V_158 , V_25 -> V_4 ) ;
V_135 = & V_3 -> V_131 [ V_158 ] ;
V_135 -> V_4 = V_25 -> V_4 ;
V_135 -> V_6 = F_66 ( V_25 ) ;
if ( V_135 -> V_6 <= 0 )
return 0 ;
V_135 -> V_7 = F_11 ( V_3 -> V_33 ,
V_135 -> V_6 * sizeof( char * ) , V_34 ) ;
if ( ! V_135 -> V_7 )
return - V_35 ;
F_64 (np, child) {
V_135 -> V_7 [ V_5 ] = V_156 -> V_4 ;
V_29 = & V_3 -> V_7 [ V_165 ++ ] ;
V_52 = F_67 ( V_156 , V_29 , V_3 , V_5 ++ ) ;
if ( V_52 ) {
F_14 ( V_156 ) ;
return V_52 ;
}
}
return 0 ;
}
static int F_76 ( struct V_166 * V_167 ,
struct V_2 * V_3 )
{
struct V_168 * V_33 = & V_167 -> V_33 ;
struct V_24 * V_25 = V_33 -> V_169 ;
struct V_24 * V_156 ;
int V_52 ;
int V_5 ;
F_63 ( V_3 , V_25 ) ;
F_16 ( & V_167 -> V_33 , L_21 , V_3 -> V_130 ) ;
F_16 ( & V_167 -> V_33 , L_22 , V_3 -> V_6 ) ;
V_3 -> V_131 = F_11 ( V_33 , V_3 -> V_130 *
sizeof( struct V_164 ) ,
V_34 ) ;
if ( ! V_3 -> V_131 ) {
F_10 ( V_33 , L_23 ) ;
return - V_18 ;
}
V_3 -> V_7 = F_11 ( V_33 , V_3 -> V_6 *
sizeof( struct V_1 ) ,
V_34 ) ;
if ( ! V_3 -> V_7 ) {
F_10 ( V_33 , L_24 ) ;
return - V_18 ;
}
V_5 = 0 ;
F_64 (np, child) {
if ( F_65 ( V_157 , V_156 ) )
continue;
V_52 = F_75 ( V_156 , V_3 , V_5 ++ ) ;
if ( V_52 ) {
F_10 ( & V_167 -> V_33 , L_25 ) ;
F_14 ( V_156 ) ;
return V_52 ;
}
}
return 0 ;
}
static int F_77 ( struct V_166 * V_167 ,
struct V_2 * V_3 )
{
struct V_170 * V_171 = & V_3 -> V_172 ;
struct V_173 * V_174 , * V_175 ;
struct V_8 * V_176 ;
int V_9 , V_46 , V_52 ;
int V_177 ;
V_171 -> V_4 = L_26 ;
V_171 -> V_178 = V_179 ;
V_171 -> V_180 = & V_181 ;
V_171 -> V_182 = & V_183 ;
V_171 -> V_184 = & V_185 ;
V_174 = F_11 ( & V_167 -> V_33 , sizeof( * V_174 ) *
V_3 -> V_11 -> V_14 , V_34 ) ;
if ( ! V_174 ) {
F_10 ( & V_167 -> V_33 , L_27 ) ;
return - V_35 ;
}
V_171 -> V_22 = V_174 ;
V_171 -> V_23 = V_3 -> V_11 -> V_14 ;
V_175 = V_174 ;
for ( V_46 = 0 , V_177 = 0 ; V_46 < V_3 -> V_11 -> V_16 ; V_46 ++ ) {
V_176 = & V_3 -> V_11 -> V_12 [ V_46 ] ;
for ( V_9 = 0 ; V_9 < V_176 -> V_14 ; V_9 ++ , V_177 ++ ) {
V_175 -> V_186 = V_177 ;
V_175 -> V_4 = F_78 ( V_34 , L_28 ,
V_176 -> V_4 , V_9 ) ;
V_175 ++ ;
}
}
V_52 = F_76 ( V_167 , V_3 ) ;
if ( V_52 )
return V_52 ;
V_3 -> V_187 = F_79 ( & V_167 -> V_33 , V_171 , V_3 ) ;
if ( F_70 ( V_3 -> V_187 ) ) {
F_10 ( & V_167 -> V_33 , L_29 ) ;
return F_71 ( V_3 -> V_187 ) ;
}
for ( V_46 = 0 ; V_46 < V_3 -> V_11 -> V_16 ; ++ V_46 ) {
V_176 = & V_3 -> V_11 -> V_12 [ V_46 ] ;
V_176 -> V_188 . V_4 = V_176 -> V_4 ;
V_176 -> V_188 . V_189 = V_46 ;
V_176 -> V_188 . V_13 = V_176 -> V_13 ;
V_176 -> V_188 . V_145 = V_176 -> V_136 . V_145 ;
V_176 -> V_188 . V_23 = V_176 -> V_136 . V_190 ;
V_176 -> V_188 . V_144 = & V_176 -> V_136 ;
F_80 ( V_3 -> V_187 , & V_176 -> V_188 ) ;
}
return 0 ;
}
static void F_59 ( struct V_136 * V_144 , unsigned V_63 , int V_191 )
{
struct V_8 * V_46 = F_48 ( V_144 ) ;
void T_5 * V_51 = V_46 -> V_138 + V_192 ;
unsigned long V_64 ;
T_2 V_37 ;
F_51 ( V_46 -> V_141 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_81 ( V_51 ) ;
V_37 &= ~ F_39 ( V_63 ) ;
if ( V_191 )
V_37 |= F_39 ( V_63 ) ;
F_82 ( V_37 , V_51 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_53 ( V_46 -> V_141 ) ;
}
static int F_61 ( struct V_136 * V_144 , unsigned V_63 )
{
struct V_8 * V_46 = F_48 ( V_144 ) ;
T_2 V_37 ;
F_51 ( V_46 -> V_141 ) ;
V_37 = F_81 ( V_46 -> V_138 + V_193 ) ;
F_53 ( V_46 -> V_141 ) ;
V_37 >>= V_63 ;
V_37 &= 1 ;
return V_37 ;
}
static int F_83 ( struct V_136 * V_144 , unsigned V_63 )
{
return F_84 ( V_144 -> V_145 + V_63 ) ;
}
static int F_85 ( struct V_136 * V_144 ,
unsigned V_63 , int V_191 )
{
F_59 ( V_144 , V_63 , V_191 ) ;
return F_86 ( V_144 -> V_145 + V_63 ) ;
}
static int F_87 ( struct V_136 * V_144 , unsigned V_63 )
{
struct V_8 * V_46 = F_48 ( V_144 ) ;
unsigned int V_194 ;
if ( ! V_46 -> V_195 )
return - V_196 ;
V_194 = F_88 ( V_46 -> V_195 , V_63 ) ;
return ( V_194 ) ? : - V_196 ;
}
static void F_89 ( struct V_197 * V_198 )
{
struct V_199 * V_137 = F_90 ( V_198 ) ;
struct V_8 * V_46 = F_91 ( V_198 ) ;
T_2 V_200 ;
F_16 ( V_46 -> V_47 -> V_33 , L_30 , V_46 -> V_4 ) ;
F_92 ( V_137 , V_198 ) ;
V_200 = F_49 ( V_46 -> V_138 + V_201 ) ;
while ( V_200 ) {
unsigned int V_202 , V_194 ;
V_202 = F_93 ( V_200 ) ;
V_200 &= ~ F_39 ( V_202 ) ;
V_194 = F_94 ( V_46 -> V_195 , V_202 ) ;
if ( ! V_194 ) {
F_10 ( V_46 -> V_47 -> V_33 , L_31 , V_202 ) ;
continue;
}
F_16 ( V_46 -> V_47 -> V_33 , L_32 , V_202 ) ;
if ( V_46 -> V_203 & F_39 ( V_202 ) ) {
T_2 V_37 , V_204 , V_205 ;
unsigned long V_64 ;
V_37 = F_49 ( V_46 -> V_138 + V_193 ) ;
do {
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_205 = F_49 ( V_46 -> V_138 +
V_206 ) ;
if ( V_37 & F_39 ( V_202 ) )
V_205 &= ~ F_39 ( V_202 ) ;
else
V_205 |= F_39 ( V_202 ) ;
F_82 ( V_205 ,
V_46 -> V_138 + V_206 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
V_204 = V_37 ;
V_37 = F_49 ( V_46 -> V_138 +
V_193 ) ;
} while ( ( V_37 & F_39 ( V_202 ) ) != ( V_204 & F_39 ( V_202 ) ) );
}
F_95 ( V_194 ) ;
}
F_96 ( V_137 , V_198 ) ;
}
static int F_97 ( struct V_207 * V_208 , unsigned int type )
{
struct V_209 * V_144 = F_98 ( V_208 ) ;
struct V_8 * V_46 = V_144 -> V_210 ;
T_2 V_53 = F_39 ( V_208 -> V_211 ) ;
T_2 V_205 ;
T_2 V_212 ;
T_2 V_37 ;
unsigned long V_64 ;
int V_52 ;
V_52 = F_20 ( V_46 , V_208 -> V_211 , V_58 ) ;
if ( V_52 < 0 )
return V_52 ;
F_51 ( V_46 -> V_141 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_49 ( V_46 -> V_138 + V_139 ) ;
V_37 &= ~ V_53 ;
F_52 ( V_37 , V_46 -> V_138 + V_139 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
if ( type & V_213 )
F_99 ( V_208 , V_214 ) ;
else
F_99 ( V_208 , V_215 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
F_100 ( V_144 ) ;
V_212 = F_49 ( V_144 -> V_138 + V_216 ) ;
V_205 = F_49 ( V_144 -> V_138 + V_206 ) ;
switch ( type ) {
case V_213 :
V_46 -> V_203 |= V_53 ;
V_212 |= V_53 ;
V_37 = F_81 ( V_46 -> V_138 + V_193 ) ;
if ( V_37 & V_53 )
V_205 &= ~ V_53 ;
else
V_205 |= V_53 ;
break;
case V_217 :
V_46 -> V_203 &= ~ V_53 ;
V_212 |= V_53 ;
V_205 |= V_53 ;
break;
case V_218 :
V_46 -> V_203 &= ~ V_53 ;
V_212 |= V_53 ;
V_205 &= ~ V_53 ;
break;
case V_219 :
V_46 -> V_203 &= ~ V_53 ;
V_212 &= ~ V_53 ;
V_205 |= V_53 ;
break;
case V_220 :
V_46 -> V_203 &= ~ V_53 ;
V_212 &= ~ V_53 ;
V_205 &= ~ V_53 ;
break;
default:
F_101 ( V_144 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_53 ( V_46 -> V_141 ) ;
return - V_18 ;
}
F_52 ( V_212 , V_144 -> V_138 + V_216 ) ;
F_52 ( V_205 , V_144 -> V_138 + V_206 ) ;
F_101 ( V_144 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_53 ( V_46 -> V_141 ) ;
return 0 ;
}
static void F_102 ( struct V_207 * V_208 )
{
struct V_209 * V_144 = F_98 ( V_208 ) ;
struct V_8 * V_46 = V_144 -> V_210 ;
F_51 ( V_46 -> V_141 ) ;
V_46 -> V_221 = F_103 ( V_144 , V_222 ) ;
F_104 ( V_144 , ~ V_144 -> V_223 , V_222 ) ;
F_53 ( V_46 -> V_141 ) ;
}
static void F_105 ( struct V_207 * V_208 )
{
struct V_209 * V_144 = F_98 ( V_208 ) ;
struct V_8 * V_46 = V_144 -> V_210 ;
F_51 ( V_46 -> V_141 ) ;
F_104 ( V_144 , V_46 -> V_221 , V_222 ) ;
F_53 ( V_46 -> V_141 ) ;
}
static void F_106 ( struct V_207 * V_208 )
{
struct V_209 * V_144 = F_98 ( V_208 ) ;
struct V_8 * V_46 = V_144 -> V_210 ;
F_51 ( V_46 -> V_141 ) ;
F_107 ( V_208 ) ;
}
static void F_108 ( struct V_207 * V_208 )
{
struct V_209 * V_144 = F_98 ( V_208 ) ;
struct V_8 * V_46 = V_144 -> V_210 ;
F_109 ( V_208 ) ;
F_53 ( V_46 -> V_141 ) ;
}
static int F_110 ( struct V_166 * V_167 ,
struct V_2 * V_3 )
{
struct V_107 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
unsigned int V_224 = V_225 | V_226 | V_227 ;
struct V_209 * V_144 ;
int V_52 ;
int V_5 , V_161 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_228 ) {
F_111 ( & V_167 -> V_33 , L_33 ,
V_46 -> V_4 ) ;
continue;
}
V_52 = F_51 ( V_46 -> V_141 ) ;
if ( V_52 ) {
F_10 ( & V_167 -> V_33 , L_34 ,
V_46 -> V_4 ) ;
continue;
}
V_46 -> V_195 = F_112 ( V_46 -> V_169 , 32 ,
& V_229 , NULL ) ;
if ( ! V_46 -> V_195 ) {
F_111 ( & V_167 -> V_33 , L_35 ,
V_46 -> V_4 ) ;
F_53 ( V_46 -> V_141 ) ;
continue;
}
V_52 = F_113 ( V_46 -> V_195 , 32 , 1 ,
L_36 , V_215 ,
V_224 , 0 , V_230 ) ;
if ( V_52 ) {
F_10 ( & V_167 -> V_33 , L_37 ,
V_46 -> V_4 ) ;
F_114 ( V_46 -> V_195 ) ;
F_53 ( V_46 -> V_141 ) ;
continue;
}
F_52 ( 0xffffffff , V_46 -> V_138 + V_222 ) ;
F_52 ( 0xffffffff , V_46 -> V_138 + V_231 ) ;
V_144 = F_115 ( V_46 -> V_195 , 0 ) ;
V_144 -> V_138 = V_46 -> V_138 ;
V_144 -> V_210 = V_46 ;
V_144 -> V_232 [ 0 ] . V_233 . V_53 = V_222 ;
V_144 -> V_232 [ 0 ] . V_233 . V_234 = V_235 ;
V_144 -> V_232 [ 0 ] . V_137 . V_236 = V_237 ;
V_144 -> V_232 [ 0 ] . V_137 . V_238 = F_108 ;
V_144 -> V_232 [ 0 ] . V_137 . V_239 =
F_106 ;
V_144 -> V_232 [ 0 ] . V_137 . V_240 = V_241 ;
V_144 -> V_232 [ 0 ] . V_137 . V_242 = F_102 ;
V_144 -> V_232 [ 0 ] . V_137 . V_243 = F_105 ;
V_144 -> V_232 [ 0 ] . V_137 . V_244 = F_97 ;
V_144 -> V_245 = F_116 ( V_46 -> V_14 ) ;
F_117 ( V_46 -> V_202 ,
F_89 , V_46 ) ;
for ( V_161 = 0 ; V_161 < 32 ; V_161 ++ )
F_88 ( V_46 -> V_195 , V_161 ) ;
F_53 ( V_46 -> V_141 ) ;
}
return 0 ;
}
static int F_118 ( struct V_166 * V_167 ,
struct V_2 * V_3 )
{
struct V_107 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
struct V_136 * V_144 ;
int V_52 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_228 ) {
F_111 ( & V_167 -> V_33 , L_33 ,
V_46 -> V_4 ) ;
continue;
}
V_46 -> V_136 = V_246 ;
V_144 = & V_46 -> V_136 ;
V_144 -> V_145 = V_46 -> V_13 ;
V_144 -> V_190 = V_46 -> V_14 ;
V_144 -> V_31 = & V_167 -> V_33 ;
V_144 -> V_169 = V_46 -> V_169 ;
V_144 -> V_247 = V_46 -> V_4 ;
V_52 = F_119 ( V_144 , V_46 ) ;
if ( V_52 ) {
F_10 ( & V_167 -> V_33 , L_38 ,
V_144 -> V_247 , V_52 ) ;
goto V_248;
}
}
F_110 ( V_167 , V_3 ) ;
return 0 ;
V_248:
for ( -- V_5 , -- V_46 ; V_5 >= 0 ; -- V_5 , -- V_46 ) {
if ( ! V_46 -> V_228 )
continue;
F_120 ( & V_46 -> V_136 ) ;
}
return V_52 ;
}
static int F_121 ( struct V_166 * V_167 ,
struct V_2 * V_3 )
{
struct V_107 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_228 )
continue;
F_120 ( & V_46 -> V_136 ) ;
}
return 0 ;
}
static int F_122 ( struct V_8 * V_46 ,
struct V_2 * V_3 )
{
struct V_249 V_250 ;
void T_5 * V_145 ;
if ( F_123 ( V_46 -> V_169 , 0 , & V_250 ) ) {
F_10 ( V_3 -> V_33 , L_39 ) ;
return - V_251 ;
}
V_46 -> V_138 = F_124 ( V_3 -> V_33 , & V_250 ) ;
if ( F_70 ( V_46 -> V_138 ) )
return F_71 ( V_46 -> V_138 ) ;
if ( F_125 ( V_46 -> V_169 ,
L_40 ) ) {
struct V_24 * V_252 ;
V_252 = F_126 ( V_46 -> V_169 -> V_31 ,
L_41 , 0 ) ;
if ( ! V_252 ) {
if ( F_123 ( V_46 -> V_169 , 1 , & V_250 ) ) {
F_10 ( V_3 -> V_33 , L_39 ) ;
return - V_251 ;
}
V_145 = F_124 ( V_3 -> V_33 , & V_250 ) ;
if ( F_70 ( V_145 ) )
return F_71 ( V_145 ) ;
V_253 . V_254 =
F_127 ( & V_250 ) - 4 ;
V_253 . V_4 =
L_42 ;
V_46 -> V_82 = F_128 ( V_3 -> V_33 ,
V_145 ,
& V_253 ) ;
}
}
V_46 -> V_202 = F_129 ( V_46 -> V_169 , 0 ) ;
V_46 -> V_141 = F_130 ( V_46 -> V_169 , 0 ) ;
if ( F_70 ( V_46 -> V_141 ) )
return F_71 ( V_46 -> V_141 ) ;
return F_131 ( V_46 -> V_141 ) ;
}
static struct V_107 * F_132 (
struct V_2 * V_208 ,
struct V_166 * V_167 )
{
const struct V_255 * V_256 ;
struct V_24 * V_252 = V_167 -> V_33 . V_169 ;
struct V_24 * V_25 ;
struct V_107 * V_11 ;
struct V_8 * V_46 ;
int V_257 , V_258 , V_259 , V_260 , V_5 , V_161 ;
V_256 = F_65 ( V_261 , V_252 ) ;
V_11 = (struct V_107 * ) V_256 -> V_37 ;
F_64 (node, np) {
if ( ! F_133 ( V_25 , L_43 , NULL ) )
continue;
V_46 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! strcmp ( V_46 -> V_4 , V_25 -> V_4 ) ) {
V_46 -> V_169 = V_25 ;
if ( ! F_122 ( V_46 , V_208 ) )
V_46 -> V_228 = true ;
break;
}
}
}
V_257 = V_11 -> V_262 ;
V_258 = V_11 -> V_263 ;
V_260 = V_11 -> V_264 ;
V_259 = V_11 -> V_265 ;
V_46 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
int V_266 = 0 ;
F_134 ( & V_46 -> V_67 ) ;
V_46 -> V_47 = V_208 ;
V_46 -> V_13 = V_11 -> V_14 ;
V_11 -> V_14 += V_46 -> V_14 ;
for ( V_161 = 0 ; V_161 < 4 ; V_161 ++ ) {
struct V_267 * V_268 = & V_46 -> V_55 [ V_161 ] ;
struct V_269 * V_103 = & V_46 -> V_103 [ V_161 ] ;
int V_270 ;
if ( V_266 >= V_46 -> V_14 )
break;
if ( V_268 -> V_63 >= 0 ) {
if ( V_268 -> type & V_59 )
V_258 = V_268 -> V_63 ;
else
V_257 = V_268 -> V_63 ;
} else {
V_268 -> V_63 = ( V_268 -> type & V_59 ) ?
V_258 : V_257 ;
}
if ( V_103 -> V_63 >= 0 ) {
if ( V_268 -> type & V_59 )
V_260 = V_103 -> V_63 ;
else
V_259 = V_103 -> V_63 ;
} else {
V_103 -> V_63 = ( V_268 -> type & V_59 ) ?
V_260 : V_259 ;
}
F_16 ( V_208 -> V_33 , L_44 ,
V_5 , V_161 , V_268 -> V_63 , V_103 -> V_63 ) ;
V_270 = ( V_268 -> type & V_62 ) ? 8 : 4 ;
if ( V_268 -> type & V_59 )
V_258 += V_270 ;
else
V_257 += V_270 ;
if ( ( V_103 -> V_104 == V_105 ) ||
( V_103 -> V_104 == V_106 ) )
V_270 = 8 ;
else
V_270 = 4 ;
if ( V_268 -> type & V_59 )
V_260 += V_270 ;
else
V_259 += V_270 ;
V_266 += 8 ;
}
}
return V_11 ;
}
static int T_6 F_135 ( struct V_168 * V_33 )
{
struct V_2 * V_3 = F_136 ( V_33 ) ;
int V_52 = F_137 ( V_3 -> V_187 ) ;
if ( V_52 )
return V_52 ;
if ( V_3 -> V_11 -> type == V_125 ) {
V_52 = F_19 ( V_3 -> V_61 , V_271 ,
& V_272 ) ;
if ( V_52 ) {
F_138 ( V_3 -> V_187 ) ;
return V_52 ;
}
}
return 0 ;
}
static int T_6 F_139 ( struct V_168 * V_33 )
{
struct V_2 * V_3 = F_136 ( V_33 ) ;
int V_52 = F_42 ( V_3 -> V_61 , V_271 ,
V_272 |
V_273 ) ;
if ( V_52 )
return V_52 ;
return F_138 ( V_3 -> V_187 ) ;
}
static int F_140 ( struct V_166 * V_167 )
{
struct V_2 * V_3 ;
struct V_168 * V_33 = & V_167 -> V_33 ;
struct V_107 * V_11 ;
struct V_24 * V_25 = V_167 -> V_33 . V_169 , * V_252 ;
struct V_249 * V_250 ;
void T_5 * V_145 ;
int V_52 ;
if ( ! V_33 -> V_169 ) {
F_10 ( V_33 , L_45 ) ;
return - V_274 ;
}
V_3 = F_11 ( V_33 , sizeof( struct V_2 ) , V_34 ) ;
if ( ! V_3 )
return - V_35 ;
V_3 -> V_33 = V_33 ;
V_11 = F_132 ( V_3 , V_167 ) ;
if ( ! V_11 ) {
F_10 ( V_33 , L_46 ) ;
return - V_18 ;
}
V_3 -> V_11 = V_11 ;
V_252 = F_126 ( V_25 , L_47 , 0 ) ;
if ( V_252 ) {
V_3 -> V_61 = F_141 ( V_252 ) ;
if ( F_70 ( V_3 -> V_61 ) )
return F_71 ( V_3 -> V_61 ) ;
} else {
V_250 = F_142 ( V_167 , V_275 , 0 ) ;
V_145 = F_124 ( & V_167 -> V_33 , V_250 ) ;
if ( F_70 ( V_145 ) )
return F_71 ( V_145 ) ;
V_253 . V_254 = F_127 ( V_250 ) - 4 ;
V_253 . V_4 = L_48 ;
V_3 -> V_61 = F_128 ( & V_167 -> V_33 , V_145 ,
& V_253 ) ;
V_3 -> V_276 = F_127 ( V_250 ) ;
if ( V_11 -> type == V_124 && V_3 -> V_276 < 0x200 ) {
V_250 = F_142 ( V_167 , V_275 , 1 ) ;
V_145 = F_124 ( & V_167 -> V_33 , V_250 ) ;
if ( F_70 ( V_145 ) )
return F_71 ( V_145 ) ;
V_253 . V_254 =
F_127 ( V_250 ) - 4 ;
V_253 . V_4 = L_49 ;
V_3 -> V_82 = F_128 ( & V_167 -> V_33 ,
V_145 ,
& V_253 ) ;
}
}
V_252 = F_126 ( V_25 , L_41 , 0 ) ;
if ( V_252 ) {
V_3 -> V_60 = F_141 ( V_252 ) ;
if ( F_70 ( V_3 -> V_60 ) )
return F_71 ( V_3 -> V_60 ) ;
}
V_52 = F_118 ( V_167 , V_3 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_77 ( V_167 , V_3 ) ;
if ( V_52 ) {
F_121 ( V_167 , V_3 ) ;
return V_52 ;
}
F_143 ( V_167 , V_3 ) ;
return 0 ;
}
static int T_7 F_144 ( void )
{
return F_145 ( & V_277 ) ;
}
