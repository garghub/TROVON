static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static const inline struct V_4 * F_3 (
const struct V_5 * V_6 ,
const char * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_9 ; V_8 ++ ) {
if ( ! strcmp ( V_6 -> V_10 [ V_8 ] . V_7 , V_7 ) )
return & V_6 -> V_10 [ V_8 ] ;
}
return NULL ;
}
static struct V_1 * F_4 ( struct V_5 * V_6 ,
unsigned V_11 )
{
struct V_1 * V_12 = V_6 -> V_13 -> V_14 ;
while ( V_11 >= ( V_12 -> V_15 + V_12 -> V_16 ) )
V_12 ++ ;
return V_12 ;
}
static struct V_1 * F_5 (
struct V_5 * V_6 ,
unsigned V_17 )
{
struct V_1 * V_12 = V_6 -> V_13 -> V_14 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_13 -> V_18 ; V_8 ++ , V_12 ++ ) {
if ( V_12 -> V_19 == V_17 )
return V_12 ;
}
return F_6 ( - V_20 ) ;
}
static int F_7 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_9 ;
}
static const char * F_9 ( struct V_21 * V_22 ,
unsigned V_23 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_10 [ V_23 ] . V_7 ;
}
static int F_10 ( struct V_21 * V_22 ,
unsigned V_23 , const unsigned * * V_24 ,
unsigned * V_25 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
if ( V_23 >= V_6 -> V_9 )
return - V_20 ;
* V_24 = V_6 -> V_10 [ V_23 ] . V_24 ;
* V_25 = V_6 -> V_10 [ V_23 ] . V_25 ;
return 0 ;
}
static int F_11 ( struct V_21 * V_22 ,
struct V_26 * V_27 ,
struct V_28 * * V_29 , unsigned * V_30 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
const struct V_4 * V_31 ;
struct V_28 * V_32 ;
struct V_26 * V_33 ;
int V_34 = 1 ;
int V_8 ;
V_31 = F_3 ( V_6 , V_27 -> V_7 ) ;
if ( ! V_31 ) {
F_12 ( V_6 -> V_35 , L_1 ,
V_27 -> V_7 ) ;
return - V_20 ;
}
V_34 += V_31 -> V_25 ;
V_32 = F_13 ( V_22 -> V_35 , sizeof( * V_32 ) * V_34 ,
V_36 ) ;
if ( ! V_32 )
return - V_37 ;
* V_29 = V_32 ;
* V_30 = V_34 ;
V_33 = F_14 ( V_27 ) ;
if ( ! V_33 ) {
F_15 ( V_22 -> V_35 , V_32 ) ;
return - V_20 ;
}
V_32 [ 0 ] . type = V_38 ;
V_32 [ 0 ] . V_39 . V_40 . V_41 = V_33 -> V_7 ;
V_32 [ 0 ] . V_39 . V_40 . V_42 = V_27 -> V_7 ;
F_16 ( V_33 ) ;
V_32 ++ ;
for ( V_8 = 0 ; V_8 < V_31 -> V_25 ; V_8 ++ ) {
V_32 [ V_8 ] . type = V_43 ;
V_32 [ V_8 ] . V_39 . V_44 . V_45 =
F_17 ( V_22 , V_31 -> V_24 [ V_8 ] ) ;
V_32 [ V_8 ] . V_39 . V_44 . V_44 = V_31 -> V_39 [ V_8 ] . V_44 ;
V_32 [ V_8 ] . V_39 . V_44 . V_46 = V_31 -> V_39 [ V_8 ] . V_47 ;
}
F_18 ( V_22 -> V_35 , L_2 ,
( * V_29 ) -> V_39 . V_40 . V_41 , ( * V_29 ) -> V_39 . V_40 . V_42 , V_34 ) ;
return 0 ;
}
static void F_19 ( struct V_21 * V_22 ,
struct V_28 * V_29 , unsigned V_30 )
{
}
static int F_20 ( struct V_1 * V_48 , int V_11 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
int V_50 = ( V_11 / 8 ) ;
struct V_51 * V_51 ;
unsigned int V_52 ;
int V_53 , V_54 , V_55 ;
T_1 V_56 ;
if ( V_50 > 3 )
return - V_20 ;
if ( V_48 -> V_57 [ V_50 ] . type & V_58 ) {
F_12 ( V_6 -> V_35 , L_3 , V_11 ) ;
return - V_20 ;
}
if ( V_48 -> V_57 [ V_50 ] . type & V_59 )
return V_60 ;
V_51 = ( V_48 -> V_57 [ V_50 ] . type & V_61 )
? V_6 -> V_62 : V_6 -> V_63 ;
V_55 = ( V_48 -> V_57 [ V_50 ] . type & V_64 ) ? 0xf : 0x3 ;
V_53 = V_48 -> V_57 [ V_50 ] . V_65 ;
if ( V_48 -> V_57 [ V_50 ] . type & V_64 ) {
if ( ( V_11 % 8 ) >= 4 )
V_53 += 0x4 ;
V_56 = ( V_11 % 4 ) * 4 ;
} else {
V_56 = ( V_11 % 8 ) * 2 ;
}
V_54 = F_21 ( V_51 , V_53 , & V_52 ) ;
if ( V_54 )
return V_54 ;
return ( ( V_52 >> V_56 ) & V_55 ) ;
}
static int F_22 ( struct V_1 * V_48 , int V_11 , int V_40 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
int V_50 = ( V_11 / 8 ) ;
struct V_51 * V_51 ;
int V_53 , V_54 , V_55 ;
unsigned long V_66 ;
T_1 V_56 ;
T_2 V_39 , V_67 ;
if ( V_50 > 3 )
return - V_20 ;
if ( V_48 -> V_57 [ V_50 ] . type & V_58 ) {
F_12 ( V_6 -> V_35 , L_3 , V_11 ) ;
return - V_20 ;
}
if ( V_48 -> V_57 [ V_50 ] . type & V_59 ) {
if ( V_40 != V_60 ) {
F_12 ( V_6 -> V_35 ,
L_4 , V_11 ) ;
return - V_68 ;
} else {
return 0 ;
}
}
F_18 ( V_6 -> V_35 , L_5 ,
V_48 -> V_19 , V_11 , V_40 ) ;
V_51 = ( V_48 -> V_57 [ V_50 ] . type & V_61 )
? V_6 -> V_62 : V_6 -> V_63 ;
V_55 = ( V_48 -> V_57 [ V_50 ] . type & V_64 ) ? 0xf : 0x3 ;
V_53 = V_48 -> V_57 [ V_50 ] . V_65 ;
if ( V_48 -> V_57 [ V_50 ] . type & V_64 ) {
if ( ( V_11 % 8 ) >= 4 )
V_53 += 0x4 ;
V_56 = ( V_11 % 4 ) * 4 ;
} else {
V_56 = ( V_11 % 8 ) * 2 ;
}
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = ( V_55 << ( V_56 + 16 ) ) ;
V_67 = V_39 | ( V_39 >> 16 ) ;
V_39 |= ( V_40 & V_55 ) << V_56 ;
V_54 = F_24 ( V_51 , V_53 , V_67 , V_39 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
return V_54 ;
}
static void F_26 ( struct V_1 * V_48 ,
int V_70 , struct V_51 * * V_51 ,
int * V_53 , T_1 * V_56 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
* V_51 = V_6 -> V_63 ;
* V_53 = V_71 ;
* V_53 += V_48 -> V_19 * V_72 ;
* V_53 += ( V_70 / V_73 ) * 4 ;
* V_56 = V_70 % V_73 ;
}
static void F_27 ( struct V_1 * V_48 ,
int V_70 , struct V_51 * * V_51 ,
int * V_53 , T_1 * V_56 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
if ( V_48 -> V_19 == 0 && V_70 < 12 ) {
* V_51 = V_6 -> V_62 ? V_6 -> V_62
: V_48 -> V_74 ;
* V_53 = V_6 -> V_62 ? V_75 : 0 ;
* V_53 += ( ( V_70 / V_76 ) * 4 ) ;
* V_56 = V_70 % V_76 ;
* V_56 *= V_77 ;
} else {
* V_51 = V_6 -> V_74 ? V_6 -> V_74
: V_6 -> V_63 ;
* V_53 = V_6 -> V_74 ? 0 : V_78 ;
* V_53 -= 4 ;
* V_53 += V_48 -> V_19 * V_79 ;
* V_53 += ( ( V_70 / V_76 ) * 4 ) ;
* V_56 = 7 - ( V_70 % V_76 ) ;
* V_56 *= V_77 ;
}
}
static void F_28 ( struct V_1 * V_48 ,
int V_70 , struct V_51 * * V_51 ,
int * V_53 , T_1 * V_56 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
if ( V_48 -> V_19 == 0 ) {
* V_51 = V_6 -> V_62 ;
* V_53 = V_75 ;
* V_53 += ( ( V_70 / V_76 ) * 4 ) ;
* V_56 = V_70 % V_76 ;
* V_56 *= V_77 ;
} else {
* V_51 = V_6 -> V_63 ;
* V_53 = V_80 ;
* V_53 -= 0x10 ;
* V_53 += V_48 -> V_19 * V_79 ;
* V_53 += ( ( V_70 / V_76 ) * 4 ) ;
* V_56 = ( V_70 % V_76 ) ;
* V_56 *= V_77 ;
}
}
static void F_29 ( struct V_1 * V_48 ,
int V_70 , struct V_51 * * V_51 ,
int * V_53 , T_1 * V_56 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
if ( V_48 -> V_19 == 0 ) {
* V_51 = V_6 -> V_62 ;
* V_53 = V_81 ;
* V_53 += ( ( V_70 / V_82 ) * 4 ) ;
* V_56 = V_70 % V_82 ;
* V_56 *= V_83 ;
} else {
* V_51 = V_6 -> V_63 ;
* V_53 = V_84 ;
* V_53 -= 0x10 ;
* V_53 += V_48 -> V_19 * V_85 ;
* V_53 += ( ( V_70 / V_82 ) * 4 ) ;
* V_56 = ( V_70 % V_82 ) ;
* V_56 *= V_83 ;
}
}
static void F_30 ( struct V_1 * V_48 ,
int V_70 , struct V_51 * * V_51 ,
int * V_53 , T_1 * V_56 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
if ( V_48 -> V_19 == 0 ) {
* V_51 = V_6 -> V_62 ;
* V_53 = V_86 ;
* V_53 += ( ( V_70 / V_76 ) * 4 ) ;
* V_56 = V_70 % V_76 ;
* V_56 *= V_77 ;
} else {
* V_51 = V_6 -> V_63 ;
* V_53 = V_87 ;
* V_53 -= 0x10 ;
* V_53 += V_48 -> V_19 * V_79 ;
* V_53 += ( ( V_70 / V_76 ) * 4 ) ;
* V_56 = ( V_70 % V_76 ) ;
* V_56 *= V_77 ;
}
}
static void F_31 ( struct V_1 * V_48 ,
int V_70 , struct V_51 * * V_51 ,
int * V_53 , T_1 * V_56 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
if ( V_48 -> V_19 == 0 ) {
* V_51 = V_6 -> V_62 ;
* V_53 = V_88 ;
* V_53 += ( ( V_70 / V_82 ) * 4 ) ;
* V_56 = V_70 % V_82 ;
* V_56 *= V_83 ;
} else {
* V_51 = V_6 -> V_63 ;
* V_53 = V_89 ;
* V_53 -= 0x10 ;
* V_53 += V_48 -> V_19 * V_85 ;
* V_53 += ( ( V_70 / V_82 ) * 4 ) ;
* V_56 = ( V_70 % V_82 ) ;
* V_56 *= V_83 ;
}
}
static int F_32 ( struct V_1 * V_48 ,
int V_70 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_90 * V_13 = V_6 -> V_13 ;
struct V_51 * V_51 ;
int V_53 , V_54 ;
T_2 V_39 ;
T_1 V_56 ;
V_13 -> V_91 ( V_48 , V_70 , & V_51 , & V_53 , & V_56 ) ;
V_54 = F_21 ( V_51 , V_53 , & V_39 ) ;
if ( V_54 )
return V_54 ;
V_39 >>= V_56 ;
V_39 &= ( 1 << V_83 ) - 1 ;
return V_92 [ V_39 ] ;
}
static int F_33 ( struct V_1 * V_48 ,
int V_70 , int V_93 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_90 * V_13 = V_6 -> V_13 ;
struct V_51 * V_51 ;
unsigned long V_66 ;
int V_53 , V_54 , V_8 ;
T_2 V_39 , V_67 ;
T_1 V_56 ;
V_13 -> V_91 ( V_48 , V_70 , & V_51 , & V_53 , & V_56 ) ;
V_54 = - V_20 ;
for ( V_8 = 0 ; V_8 < F_34 ( V_92 ) ; V_8 ++ ) {
if ( V_92 [ V_8 ] == V_93 ) {
V_54 = V_8 ;
break;
}
}
if ( V_54 < 0 ) {
F_12 ( V_6 -> V_35 , L_6 ,
V_93 ) ;
return V_54 ;
}
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = ( ( 1 << V_83 ) - 1 ) << ( V_56 + 16 ) ;
V_67 = V_39 | ( V_39 >> 16 ) ;
V_39 |= ( V_54 << V_56 ) ;
V_54 = F_24 ( V_51 , V_53 , V_67 , V_39 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
return V_54 ;
}
static int F_35 ( struct V_1 * V_48 , int V_70 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_90 * V_13 = V_6 -> V_13 ;
struct V_51 * V_51 ;
int V_53 , V_54 ;
T_1 V_56 ;
T_2 V_39 ;
if ( V_13 -> type == V_94 )
return V_95 ;
V_13 -> V_96 ( V_48 , V_70 , & V_51 , & V_53 , & V_56 ) ;
V_54 = F_21 ( V_51 , V_53 , & V_39 ) ;
if ( V_54 )
return V_54 ;
switch ( V_13 -> type ) {
case V_97 :
return ! ( V_39 & F_36 ( V_56 ) )
? V_98
: V_95 ;
case V_99 :
case V_100 :
case V_101 :
V_39 >>= V_56 ;
V_39 &= ( 1 << V_77 ) - 1 ;
switch ( V_39 ) {
case 0 :
return V_95 ;
case 1 :
return V_102 ;
case 2 :
return V_103 ;
case 3 :
return V_104 ;
}
F_12 ( V_6 -> V_35 , L_7 ) ;
return - V_105 ;
default:
F_12 ( V_6 -> V_35 , L_8 ) ;
return - V_20 ;
} ;
}
static int F_37 ( struct V_1 * V_48 ,
int V_70 , int V_106 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_90 * V_13 = V_6 -> V_13 ;
struct V_51 * V_51 ;
int V_53 , V_54 ;
unsigned long V_66 ;
T_1 V_56 ;
T_2 V_39 , V_67 ;
F_18 ( V_6 -> V_35 , L_9 ,
V_48 -> V_19 , V_70 , V_106 ) ;
if ( V_13 -> type == V_94 )
return V_106 ? - V_20 : 0 ;
V_13 -> V_96 ( V_48 , V_70 , & V_51 , & V_53 , & V_56 ) ;
switch ( V_13 -> type ) {
case V_97 :
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = F_36 ( V_56 + 16 ) ;
if ( V_106 == V_95 )
V_39 |= F_36 ( V_56 ) ;
V_54 = F_38 ( V_51 , V_53 , V_39 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
break;
case V_99 :
case V_100 :
case V_101 :
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = ( ( 1 << V_77 ) - 1 ) << ( V_56 + 16 ) ;
V_67 = V_39 | ( V_39 >> 16 ) ;
switch ( V_106 ) {
case V_95 :
break;
case V_102 :
V_39 |= ( 1 << V_56 ) ;
break;
case V_103 :
V_39 |= ( 2 << V_56 ) ;
break;
case V_104 :
V_39 |= ( 3 << V_56 ) ;
break;
default:
F_25 ( & V_48 -> V_69 , V_66 ) ;
F_12 ( V_6 -> V_35 , L_10 ,
V_106 ) ;
return - V_20 ;
}
V_54 = F_24 ( V_51 , V_53 , V_67 , V_39 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
break;
default:
F_12 ( V_6 -> V_35 , L_8 ) ;
return - V_20 ;
}
return V_54 ;
}
static int F_39 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_107 ;
}
static const char * F_40 ( struct V_21 * V_22 ,
unsigned V_23 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_108 [ V_23 ] . V_7 ;
}
static int F_41 ( struct V_21 * V_22 ,
unsigned V_23 , const char * const * * V_10 ,
unsigned * const V_109 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
* V_10 = V_6 -> V_108 [ V_23 ] . V_10 ;
* V_109 = V_6 -> V_108 [ V_23 ] . V_9 ;
return 0 ;
}
static int F_42 ( struct V_21 * V_22 , unsigned V_23 ,
unsigned V_42 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
const unsigned int * V_24 = V_6 -> V_10 [ V_42 ] . V_24 ;
const struct V_110 * V_39 = V_6 -> V_10 [ V_42 ] . V_39 ;
struct V_1 * V_48 ;
int V_111 , V_54 = 0 ;
F_18 ( V_6 -> V_35 , L_11 ,
V_6 -> V_108 [ V_23 ] . V_7 , V_6 -> V_10 [ V_42 ] . V_7 ) ;
for ( V_111 = 0 ; V_111 < V_6 -> V_10 [ V_42 ] . V_25 ; V_111 ++ ) {
V_48 = F_4 ( V_6 , V_24 [ V_111 ] ) ;
V_54 = F_22 ( V_48 , V_24 [ V_111 ] - V_48 -> V_15 ,
V_39 [ V_111 ] . V_112 ) ;
if ( V_54 )
break;
}
if ( V_54 ) {
for ( V_111 -- ; V_111 >= 0 ; V_111 -- )
F_22 ( V_48 , V_24 [ V_111 ] - V_48 -> V_15 , 0 ) ;
return V_54 ;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_113 ,
int V_11 , bool V_114 )
{
struct V_1 * V_48 ;
int V_54 ;
unsigned long V_66 ;
T_2 V_39 ;
V_48 = F_1 ( V_113 ) ;
V_54 = F_22 ( V_48 , V_11 , V_60 ) ;
if ( V_54 < 0 )
return V_54 ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = F_44 ( V_48 -> V_115 + V_116 ) ;
if ( ! V_114 )
V_39 |= F_36 ( V_11 ) ;
else
V_39 &= ~ F_36 ( V_11 ) ;
F_45 ( V_39 , V_48 -> V_115 + V_116 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
return 0 ;
}
static int F_46 ( struct V_21 * V_22 ,
struct V_117 * V_118 ,
unsigned V_65 , bool V_114 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_2 * V_113 ;
int V_11 ;
V_113 = V_118 -> V_3 ;
V_11 = V_65 - V_113 -> V_119 ;
F_18 ( V_6 -> V_35 , L_12 ,
V_65 , V_118 -> V_7 , V_11 , V_114 ? L_13 : L_14 ) ;
return F_43 ( V_113 , V_65 - V_113 -> V_119 ,
V_114 ) ;
}
static bool F_47 ( struct V_90 * V_13 ,
enum V_120 V_106 )
{
switch ( V_13 -> type ) {
case V_97 :
return ( V_106 == V_98 ||
V_106 == V_95 ) ;
case V_94 :
return V_106 ? false : true ;
case V_99 :
case V_100 :
case V_101 :
return ( V_106 != V_98 ) ;
}
return false ;
}
static int F_48 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_44 , unsigned V_46 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_120 V_121 ;
T_3 V_122 ;
int V_8 ;
int V_123 ;
for ( V_8 = 0 ; V_8 < V_46 ; V_8 ++ ) {
V_121 = F_49 ( V_44 [ V_8 ] ) ;
V_122 = F_50 ( V_44 [ V_8 ] ) ;
switch ( V_121 ) {
case V_95 :
V_123 = F_37 ( V_48 , V_11 - V_48 -> V_15 ,
V_121 ) ;
if ( V_123 )
return V_123 ;
break;
case V_102 :
case V_103 :
case V_98 :
case V_104 :
if ( ! F_47 ( V_6 -> V_13 , V_121 ) )
return - V_68 ;
if ( ! V_122 )
return - V_20 ;
V_123 = F_37 ( V_48 , V_11 - V_48 -> V_15 ,
V_121 ) ;
if ( V_123 )
return V_123 ;
break;
case V_124 :
F_51 ( & V_48 -> V_2 ,
V_11 - V_48 -> V_15 , V_122 ) ;
V_123 = F_43 ( & V_48 -> V_2 ,
V_11 - V_48 -> V_15 , false ) ;
if ( V_123 )
return V_123 ;
break;
case V_125 :
if ( ! V_6 -> V_13 -> V_91 )
return - V_68 ;
V_123 = F_33 ( V_48 ,
V_11 - V_48 -> V_15 , V_122 ) ;
if ( V_123 < 0 )
return V_123 ;
break;
default:
return - V_68 ;
break;
}
}
return 0 ;
}
static int F_52 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_126 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_120 V_121 = F_49 ( * V_126 ) ;
T_3 V_122 ;
int V_123 ;
switch ( V_121 ) {
case V_95 :
if ( F_35 ( V_48 , V_11 - V_48 -> V_15 ) != V_121 )
return - V_20 ;
V_122 = 0 ;
break;
case V_102 :
case V_103 :
case V_98 :
case V_104 :
if ( ! F_47 ( V_6 -> V_13 , V_121 ) )
return - V_68 ;
if ( F_35 ( V_48 , V_11 - V_48 -> V_15 ) != V_121 )
return - V_20 ;
V_122 = 1 ;
break;
case V_124 :
V_123 = F_20 ( V_48 , V_11 - V_48 -> V_15 ) ;
if ( V_123 != V_60 )
return - V_20 ;
V_123 = F_53 ( & V_48 -> V_2 , V_11 - V_48 -> V_15 ) ;
if ( V_123 < 0 )
return V_123 ;
V_122 = V_123 ? 1 : 0 ;
break;
case V_125 :
if ( ! V_6 -> V_13 -> V_91 )
return - V_68 ;
V_123 = F_32 ( V_48 , V_11 - V_48 -> V_15 ) ;
if ( V_123 < 0 )
return V_123 ;
V_122 = V_123 ;
break;
default:
return - V_68 ;
break;
}
* V_126 = F_54 ( V_121 , V_122 ) ;
return 0 ;
}
static void F_55 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
struct V_26 * V_127 ;
F_56 (np, child) {
if ( F_57 ( V_128 , V_127 ) )
continue;
V_6 -> V_107 ++ ;
V_6 -> V_9 += F_58 ( V_127 ) ;
}
}
static int F_59 ( struct V_26 * V_27 ,
struct V_4 * V_31 ,
struct V_5 * V_6 ,
T_2 V_129 )
{
struct V_1 * V_48 ;
int V_130 ;
const T_4 * V_131 ;
int V_17 ;
int V_8 , V_132 ;
int V_54 ;
F_18 ( V_6 -> V_35 , L_15 , V_129 , V_27 -> V_7 ) ;
V_31 -> V_7 = V_27 -> V_7 ;
V_131 = F_60 ( V_27 , L_16 , & V_130 ) ;
V_130 /= sizeof( * V_131 ) ;
if ( ! V_130 || V_130 % 4 ) {
F_12 ( V_6 -> V_35 , L_17 ) ;
return - V_20 ;
}
V_31 -> V_25 = V_130 / 4 ;
V_31 -> V_24 = F_13 ( V_6 -> V_35 , V_31 -> V_25 * sizeof( unsigned int ) ,
V_36 ) ;
V_31 -> V_39 = F_13 ( V_6 -> V_35 , V_31 -> V_25 *
sizeof( struct V_110 ) ,
V_36 ) ;
if ( ! V_31 -> V_24 || ! V_31 -> V_39 )
return - V_37 ;
for ( V_8 = 0 , V_132 = 0 ; V_8 < V_130 ; V_8 += 4 , V_132 ++ ) {
const T_4 * V_133 ;
struct V_26 * V_134 ;
V_17 = F_61 ( * V_131 ++ ) ;
V_48 = F_5 ( V_6 , V_17 ) ;
if ( F_62 ( V_48 ) )
return F_63 ( V_48 ) ;
V_31 -> V_24 [ V_132 ] = V_48 -> V_15 + F_61 ( * V_131 ++ ) ;
V_31 -> V_39 [ V_132 ] . V_112 = F_61 ( * V_131 ++ ) ;
V_133 = V_131 ++ ;
if ( ! V_133 )
return - V_20 ;
V_134 = F_64 ( F_65 ( V_133 ) ) ;
V_54 = F_66 ( V_134 , NULL ,
& V_31 -> V_39 [ V_132 ] . V_44 , & V_31 -> V_39 [ V_132 ] . V_47 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_67 ( struct V_26 * V_27 ,
struct V_5 * V_6 ,
T_2 V_129 )
{
struct V_26 * V_127 ;
struct V_135 * V_112 ;
struct V_4 * V_31 ;
int V_54 ;
static T_2 V_136 ;
T_2 V_8 = 0 ;
F_18 ( V_6 -> V_35 , L_18 , V_129 , V_27 -> V_7 ) ;
V_112 = & V_6 -> V_108 [ V_129 ] ;
V_112 -> V_7 = V_27 -> V_7 ;
V_112 -> V_9 = F_58 ( V_27 ) ;
if ( V_112 -> V_9 <= 0 )
return 0 ;
V_112 -> V_10 = F_13 ( V_6 -> V_35 ,
V_112 -> V_9 * sizeof( char * ) , V_36 ) ;
if ( ! V_112 -> V_10 )
return - V_37 ;
F_56 (np, child) {
V_112 -> V_10 [ V_8 ] = V_127 -> V_7 ;
V_31 = & V_6 -> V_10 [ V_136 ++ ] ;
V_54 = F_59 ( V_127 , V_31 , V_6 , V_8 ++ ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_68 ( struct V_137 * V_138 ,
struct V_5 * V_6 )
{
struct V_139 * V_35 = & V_138 -> V_35 ;
struct V_26 * V_27 = V_35 -> V_140 ;
struct V_26 * V_127 ;
int V_54 ;
int V_8 ;
F_55 ( V_6 , V_27 ) ;
F_18 ( & V_138 -> V_35 , L_19 , V_6 -> V_107 ) ;
F_18 ( & V_138 -> V_35 , L_20 , V_6 -> V_9 ) ;
V_6 -> V_108 = F_13 ( V_35 , V_6 -> V_107 *
sizeof( struct V_135 ) ,
V_36 ) ;
if ( ! V_6 -> V_108 ) {
F_12 ( V_35 , L_21 ) ;
return - V_20 ;
}
V_6 -> V_10 = F_13 ( V_35 , V_6 -> V_9 *
sizeof( struct V_4 ) ,
V_36 ) ;
if ( ! V_6 -> V_10 ) {
F_12 ( V_35 , L_22 ) ;
return - V_20 ;
}
V_8 = 0 ;
F_56 (np, child) {
if ( F_57 ( V_128 , V_127 ) )
continue;
V_54 = F_67 ( V_127 , V_6 , V_8 ++ ) ;
if ( V_54 ) {
F_12 ( & V_138 -> V_35 , L_23 ) ;
return V_54 ;
}
}
return 0 ;
}
static int F_69 ( struct V_137 * V_138 ,
struct V_5 * V_6 )
{
struct V_141 * V_142 = & V_6 -> V_143 ;
struct V_144 * V_145 , * V_146 ;
struct V_1 * V_147 ;
int V_11 , V_48 , V_54 ;
int V_148 ;
V_142 -> V_7 = L_24 ;
V_142 -> V_149 = V_150 ;
V_142 -> V_151 = & V_152 ;
V_142 -> V_153 = & V_154 ;
V_142 -> V_155 = & V_156 ;
V_145 = F_13 ( & V_138 -> V_35 , sizeof( * V_145 ) *
V_6 -> V_13 -> V_16 , V_36 ) ;
if ( ! V_145 ) {
F_12 ( & V_138 -> V_35 , L_25 ) ;
return - V_37 ;
}
V_142 -> V_24 = V_145 ;
V_142 -> V_25 = V_6 -> V_13 -> V_16 ;
V_146 = V_145 ;
for ( V_48 = 0 , V_148 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; V_48 ++ ) {
V_147 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
for ( V_11 = 0 ; V_11 < V_147 -> V_16 ; V_11 ++ , V_148 ++ ) {
V_146 -> V_157 = V_148 ;
V_146 -> V_7 = F_70 ( V_36 , L_26 ,
V_147 -> V_7 , V_11 ) ;
V_146 ++ ;
}
}
V_54 = F_68 ( V_138 , V_6 ) ;
if ( V_54 )
return V_54 ;
V_6 -> V_158 = F_71 ( V_142 , & V_138 -> V_35 , V_6 ) ;
if ( F_62 ( V_6 -> V_158 ) ) {
F_12 ( & V_138 -> V_35 , L_27 ) ;
return F_63 ( V_6 -> V_158 ) ;
}
for ( V_48 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; ++ V_48 ) {
V_147 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
V_147 -> V_159 . V_7 = V_147 -> V_7 ;
V_147 -> V_159 . V_160 = V_48 ;
V_147 -> V_159 . V_15 = V_147 -> V_15 ;
V_147 -> V_159 . V_119 = V_147 -> V_2 . V_119 ;
V_147 -> V_159 . V_25 = V_147 -> V_2 . V_161 ;
V_147 -> V_159 . V_3 = & V_147 -> V_2 ;
F_72 ( V_6 -> V_158 , & V_147 -> V_159 ) ;
}
return 0 ;
}
static int F_73 ( struct V_2 * V_113 , unsigned V_65 )
{
return F_74 ( V_113 -> V_119 + V_65 ) ;
}
static void F_75 ( struct V_2 * V_113 , unsigned V_65 )
{
F_76 ( V_113 -> V_119 + V_65 ) ;
}
static void F_51 ( struct V_2 * V_3 , unsigned V_65 , int V_162 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
void T_5 * V_53 = V_48 -> V_115 + V_163 ;
unsigned long V_66 ;
T_2 V_39 ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = F_77 ( V_53 ) ;
V_39 &= ~ F_36 ( V_65 ) ;
if ( V_162 )
V_39 |= F_36 ( V_65 ) ;
F_78 ( V_39 , V_53 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
}
static int F_53 ( struct V_2 * V_3 , unsigned V_65 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
T_2 V_39 ;
V_39 = F_77 ( V_48 -> V_115 + V_164 ) ;
V_39 >>= V_65 ;
V_39 &= 1 ;
return V_39 ;
}
static int F_79 ( struct V_2 * V_3 , unsigned V_65 )
{
return F_80 ( V_3 -> V_119 + V_65 ) ;
}
static int F_81 ( struct V_2 * V_3 ,
unsigned V_65 , int V_162 )
{
F_51 ( V_3 , V_65 , V_162 ) ;
return F_82 ( V_3 -> V_119 + V_65 ) ;
}
static int F_83 ( struct V_2 * V_3 , unsigned V_65 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
unsigned int V_165 ;
if ( ! V_48 -> V_166 )
return - V_167 ;
V_165 = F_84 ( V_48 -> V_166 , V_65 ) ;
return ( V_165 ) ? : - V_167 ;
}
static void F_85 ( unsigned int V_168 , struct V_169 * V_170 )
{
struct V_171 * V_113 = F_86 ( V_168 ) ;
struct V_1 * V_48 = F_87 ( V_168 ) ;
T_2 V_172 ;
F_18 ( V_48 -> V_49 -> V_35 , L_28 , V_48 -> V_7 ) ;
F_88 ( V_113 , V_170 ) ;
V_172 = F_44 ( V_48 -> V_115 + V_173 ) ;
while ( V_172 ) {
unsigned int V_165 ;
V_168 = F_89 ( V_172 ) ;
V_172 &= ~ F_36 ( V_168 ) ;
V_165 = F_90 ( V_48 -> V_166 , V_168 ) ;
if ( ! V_165 ) {
F_12 ( V_48 -> V_49 -> V_35 , L_29 , V_168 ) ;
continue;
}
F_18 ( V_48 -> V_49 -> V_35 , L_30 , V_168 ) ;
if ( V_48 -> V_174 & F_36 ( V_168 ) ) {
T_2 V_39 , V_175 , V_176 ;
unsigned long V_66 ;
V_39 = F_44 ( V_48 -> V_115 + V_164 ) ;
do {
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_176 = F_44 ( V_48 -> V_115 +
V_177 ) ;
if ( V_39 & F_36 ( V_168 ) )
V_176 &= ~ F_36 ( V_168 ) ;
else
V_176 |= F_36 ( V_168 ) ;
F_78 ( V_176 ,
V_48 -> V_115 + V_177 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
V_175 = V_39 ;
V_39 = F_44 ( V_48 -> V_115 +
V_164 ) ;
} while ( ( V_39 & F_36 ( V_168 ) ) != ( V_175 & F_36 ( V_168 ) ) );
}
F_91 ( V_165 ) ;
}
F_92 ( V_113 , V_170 ) ;
}
static int F_93 ( struct V_178 * V_179 , unsigned int type )
{
struct V_180 * V_3 = F_94 ( V_179 ) ;
struct V_1 * V_48 = V_3 -> V_181 ;
T_2 V_55 = F_36 ( V_179 -> V_182 ) ;
T_2 V_176 ;
T_2 V_183 ;
T_2 V_39 ;
unsigned long V_66 ;
int V_54 ;
V_54 = F_22 ( V_48 , V_179 -> V_182 , V_60 ) ;
if ( V_54 < 0 )
return V_54 ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = F_44 ( V_48 -> V_115 + V_116 ) ;
V_39 &= ~ V_55 ;
F_45 ( V_39 , V_48 -> V_115 + V_116 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
if ( type & V_184 )
F_95 ( V_179 -> V_168 , V_185 ) ;
else
F_95 ( V_179 -> V_168 , V_186 ) ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
F_96 ( V_3 ) ;
V_183 = F_44 ( V_3 -> V_115 + V_187 ) ;
V_176 = F_44 ( V_3 -> V_115 + V_177 ) ;
switch ( type ) {
case V_184 :
V_48 -> V_174 |= V_55 ;
V_183 |= V_55 ;
V_39 = F_77 ( V_48 -> V_115 + V_164 ) ;
if ( V_39 & V_55 )
V_176 &= ~ V_55 ;
else
V_176 |= V_55 ;
break;
case V_188 :
V_48 -> V_174 &= ~ V_55 ;
V_183 |= V_55 ;
V_176 |= V_55 ;
break;
case V_189 :
V_48 -> V_174 &= ~ V_55 ;
V_183 |= V_55 ;
V_176 &= ~ V_55 ;
break;
case V_190 :
V_48 -> V_174 &= ~ V_55 ;
V_183 &= ~ V_55 ;
V_176 |= V_55 ;
break;
case V_191 :
V_48 -> V_174 &= ~ V_55 ;
V_183 &= ~ V_55 ;
V_176 &= ~ V_55 ;
break;
default:
F_97 ( V_3 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
return - V_20 ;
}
F_45 ( V_183 , V_3 -> V_115 + V_187 ) ;
F_45 ( V_176 , V_3 -> V_115 + V_177 ) ;
F_97 ( V_3 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
return 0 ;
}
static void F_98 ( struct V_178 * V_179 )
{
struct V_180 * V_3 = F_94 ( V_179 ) ;
struct V_1 * V_48 = V_3 -> V_181 ;
V_48 -> V_192 = F_99 ( V_3 , V_193 ) ;
F_100 ( V_3 , ~ V_3 -> V_194 , V_193 ) ;
}
static void F_101 ( struct V_178 * V_179 )
{
struct V_180 * V_3 = F_94 ( V_179 ) ;
struct V_1 * V_48 = V_3 -> V_181 ;
F_100 ( V_3 , V_48 -> V_192 , V_193 ) ;
}
static int F_102 ( struct V_137 * V_138 ,
struct V_5 * V_6 )
{
struct V_90 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
unsigned int V_195 = V_196 | V_197 | V_198 ;
struct V_180 * V_3 ;
int V_54 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_199 ) {
F_103 ( & V_138 -> V_35 , L_31 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_166 = F_104 ( V_48 -> V_140 , 32 ,
& V_200 , NULL ) ;
if ( ! V_48 -> V_166 ) {
F_103 ( & V_138 -> V_35 , L_32 ,
V_48 -> V_7 ) ;
continue;
}
V_54 = F_105 ( V_48 -> V_166 , 32 , 1 ,
L_33 , V_186 ,
V_195 , 0 , V_201 ) ;
if ( V_54 ) {
F_12 ( & V_138 -> V_35 , L_34 ,
V_48 -> V_7 ) ;
F_106 ( V_48 -> V_166 ) ;
continue;
}
F_45 ( 0xffffffff , V_48 -> V_115 + V_193 ) ;
F_45 ( 0xffffffff , V_48 -> V_115 + V_202 ) ;
V_3 = F_107 ( V_48 -> V_166 , 0 ) ;
V_3 -> V_115 = V_48 -> V_115 ;
V_3 -> V_181 = V_48 ;
V_3 -> V_203 [ 0 ] . V_204 . V_55 = V_193 ;
V_3 -> V_203 [ 0 ] . V_204 . V_205 = V_206 ;
V_3 -> V_203 [ 0 ] . V_113 . V_207 = V_208 ;
V_3 -> V_203 [ 0 ] . V_113 . V_209 = V_210 ;
V_3 -> V_203 [ 0 ] . V_113 . V_211 = V_212 ;
V_3 -> V_203 [ 0 ] . V_113 . V_213 = V_214 ;
V_3 -> V_203 [ 0 ] . V_113 . V_215 = F_98 ;
V_3 -> V_203 [ 0 ] . V_113 . V_216 = F_101 ;
V_3 -> V_203 [ 0 ] . V_113 . V_217 = F_93 ;
V_3 -> V_218 = F_108 ( V_48 -> V_16 ) ;
F_109 ( V_48 -> V_168 , V_48 ) ;
F_110 ( V_48 -> V_168 , F_85 ) ;
}
return 0 ;
}
static int F_111 ( struct V_137 * V_138 ,
struct V_5 * V_6 )
{
struct V_90 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
struct V_2 * V_3 ;
int V_54 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_199 ) {
F_103 ( & V_138 -> V_35 , L_31 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_2 = V_219 ;
V_3 = & V_48 -> V_2 ;
V_3 -> V_119 = V_48 -> V_15 ;
V_3 -> V_161 = V_48 -> V_16 ;
V_3 -> V_35 = & V_138 -> V_35 ;
V_3 -> V_140 = V_48 -> V_140 ;
V_3 -> V_220 = V_48 -> V_7 ;
V_54 = F_112 ( V_3 ) ;
if ( V_54 ) {
F_12 ( & V_138 -> V_35 , L_35 ,
V_3 -> V_220 , V_54 ) ;
goto V_221;
}
}
F_102 ( V_138 , V_6 ) ;
return 0 ;
V_221:
for ( -- V_8 , -- V_48 ; V_8 >= 0 ; -- V_8 , -- V_48 ) {
if ( ! V_48 -> V_199 )
continue;
F_113 ( & V_48 -> V_2 ) ;
}
return V_54 ;
}
static int F_114 ( struct V_137 * V_138 ,
struct V_5 * V_6 )
{
struct V_90 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_199 )
continue;
F_113 ( & V_48 -> V_2 ) ;
}
return 0 ;
}
static int F_115 ( struct V_1 * V_48 ,
struct V_5 * V_6 )
{
struct V_222 V_223 ;
void T_5 * V_119 ;
if ( F_116 ( V_48 -> V_140 , 0 , & V_223 ) ) {
F_12 ( V_6 -> V_35 , L_36 ) ;
return - V_224 ;
}
V_48 -> V_115 = F_117 ( V_6 -> V_35 , & V_223 ) ;
if ( F_62 ( V_48 -> V_115 ) )
return F_63 ( V_48 -> V_115 ) ;
if ( F_118 ( V_48 -> V_140 ,
L_37 ) ) {
struct V_26 * V_225 ;
V_225 = F_119 ( V_48 -> V_140 -> V_33 ,
L_38 , 0 ) ;
if ( ! V_225 ) {
if ( F_116 ( V_48 -> V_140 , 1 , & V_223 ) ) {
F_12 ( V_6 -> V_35 , L_36 ) ;
return - V_224 ;
}
V_119 = F_117 ( V_6 -> V_35 , & V_223 ) ;
if ( F_62 ( V_119 ) )
return F_63 ( V_119 ) ;
V_226 . V_227 =
F_120 ( & V_223 ) - 4 ;
V_226 . V_7 =
L_39 ;
V_48 -> V_74 = F_121 ( V_6 -> V_35 ,
V_119 ,
& V_226 ) ;
}
}
V_48 -> V_168 = F_122 ( V_48 -> V_140 , 0 ) ;
V_48 -> V_228 = F_123 ( V_48 -> V_140 , 0 ) ;
if ( F_62 ( V_48 -> V_228 ) )
return F_63 ( V_48 -> V_228 ) ;
return F_124 ( V_48 -> V_228 ) ;
}
static struct V_90 * F_125 (
struct V_5 * V_179 ,
struct V_137 * V_138 )
{
const struct V_229 * V_230 ;
struct V_26 * V_225 = V_138 -> V_35 . V_140 ;
struct V_26 * V_27 ;
struct V_90 * V_13 ;
struct V_1 * V_48 ;
int V_231 , V_232 , V_8 , V_132 ;
V_230 = F_57 ( V_233 , V_225 ) ;
V_13 = (struct V_90 * ) V_230 -> V_39 ;
F_56 (node, np) {
if ( ! F_126 ( V_27 , L_40 , NULL ) )
continue;
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! strcmp ( V_48 -> V_7 , V_27 -> V_7 ) ) {
V_48 -> V_140 = V_27 ;
if ( ! F_115 ( V_48 , V_179 ) )
V_48 -> V_199 = true ;
break;
}
}
}
V_231 = V_13 -> V_234 ;
V_232 = V_13 -> V_235 ;
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
int V_236 = 0 ;
F_127 ( & V_48 -> V_69 ) ;
V_48 -> V_49 = V_179 ;
V_48 -> V_15 = V_13 -> V_16 ;
V_13 -> V_16 += V_48 -> V_16 ;
for ( V_132 = 0 ; V_132 < 4 ; V_132 ++ ) {
struct V_237 * V_238 = & V_48 -> V_57 [ V_132 ] ;
int V_239 ;
if ( V_236 >= V_48 -> V_16 )
break;
if ( V_238 -> V_65 >= 0 ) {
if ( V_238 -> type & V_61 )
V_232 = V_238 -> V_65 ;
else
V_231 = V_238 -> V_65 ;
} else {
V_238 -> V_65 = ( V_238 -> type & V_61 ) ?
V_232 : V_231 ;
}
F_18 ( V_179 -> V_35 , L_41 ,
V_8 , V_132 , V_238 -> V_65 ) ;
V_239 = ( V_238 -> type & V_64 ) ? 8 : 4 ;
if ( V_238 -> type & V_61 )
V_232 += V_239 ;
else
V_231 += V_239 ;
V_236 += 8 ;
}
}
return V_13 ;
}
static int T_6 F_128 ( struct V_139 * V_35 )
{
struct V_5 * V_6 = F_129 ( V_35 ) ;
int V_54 = F_130 ( V_6 -> V_158 ) ;
if ( V_54 )
return V_54 ;
if ( V_6 -> V_13 -> type == V_100 ) {
V_54 = F_21 ( V_6 -> V_63 , V_240 ,
& V_241 ) ;
if ( V_54 ) {
F_131 ( V_6 -> V_158 ) ;
return V_54 ;
}
}
return 0 ;
}
static int T_6 F_132 ( struct V_139 * V_35 )
{
struct V_5 * V_6 = F_129 ( V_35 ) ;
int V_54 = F_38 ( V_6 -> V_63 , V_240 ,
V_241 |
V_242 ) ;
if ( V_54 )
return V_54 ;
return F_131 ( V_6 -> V_158 ) ;
}
static int F_133 ( struct V_137 * V_138 )
{
struct V_5 * V_6 ;
struct V_139 * V_35 = & V_138 -> V_35 ;
struct V_90 * V_13 ;
struct V_26 * V_27 = V_138 -> V_35 . V_140 , * V_225 ;
struct V_222 * V_223 ;
void T_5 * V_119 ;
int V_54 ;
if ( ! V_35 -> V_140 ) {
F_12 ( V_35 , L_42 ) ;
return - V_243 ;
}
V_6 = F_13 ( V_35 , sizeof( struct V_5 ) , V_36 ) ;
if ( ! V_6 )
return - V_37 ;
V_6 -> V_35 = V_35 ;
V_13 = F_125 ( V_6 , V_138 ) ;
if ( ! V_13 ) {
F_12 ( V_35 , L_43 ) ;
return - V_20 ;
}
V_6 -> V_13 = V_13 ;
V_225 = F_119 ( V_27 , L_44 , 0 ) ;
if ( V_225 ) {
V_6 -> V_63 = F_134 ( V_225 ) ;
if ( F_62 ( V_6 -> V_63 ) )
return F_63 ( V_6 -> V_63 ) ;
} else {
V_223 = F_135 ( V_138 , V_244 , 0 ) ;
V_119 = F_117 ( & V_138 -> V_35 , V_223 ) ;
if ( F_62 ( V_119 ) )
return F_63 ( V_119 ) ;
V_226 . V_227 = F_120 ( V_223 ) - 4 ;
V_226 . V_7 = L_45 ;
V_6 -> V_63 = F_121 ( & V_138 -> V_35 , V_119 ,
& V_226 ) ;
V_6 -> V_245 = F_120 ( V_223 ) ;
if ( V_13 -> type == V_99 && V_6 -> V_245 < 0x200 ) {
V_223 = F_135 ( V_138 , V_244 , 1 ) ;
V_119 = F_117 ( & V_138 -> V_35 , V_223 ) ;
if ( F_62 ( V_119 ) )
return F_63 ( V_119 ) ;
V_226 . V_227 =
F_120 ( V_223 ) - 4 ;
V_226 . V_7 = L_46 ;
V_6 -> V_74 = F_121 ( & V_138 -> V_35 ,
V_119 ,
& V_226 ) ;
}
}
V_225 = F_119 ( V_27 , L_38 , 0 ) ;
if ( V_225 ) {
V_6 -> V_62 = F_134 ( V_225 ) ;
if ( F_62 ( V_6 -> V_62 ) )
return F_63 ( V_6 -> V_62 ) ;
}
V_54 = F_111 ( V_138 , V_6 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_69 ( V_138 , V_6 ) ;
if ( V_54 ) {
F_114 ( V_138 , V_6 ) ;
return V_54 ;
}
F_136 ( V_138 , V_6 ) ;
return 0 ;
}
static int T_7 F_137 ( void )
{
return F_138 ( & V_246 ) ;
}
