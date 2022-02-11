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
F_44 ( V_48 -> V_115 ) ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = F_45 ( V_48 -> V_116 + V_117 ) ;
if ( ! V_114 )
V_39 |= F_36 ( V_11 ) ;
else
V_39 &= ~ F_36 ( V_11 ) ;
F_46 ( V_39 , V_48 -> V_116 + V_117 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
F_47 ( V_48 -> V_115 ) ;
return 0 ;
}
static int F_48 ( struct V_21 * V_22 ,
struct V_118 * V_119 ,
unsigned V_65 , bool V_114 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_2 * V_113 ;
int V_11 ;
V_113 = V_119 -> V_3 ;
V_11 = V_65 - V_113 -> V_120 ;
F_18 ( V_6 -> V_35 , L_12 ,
V_65 , V_119 -> V_7 , V_11 , V_114 ? L_13 : L_14 ) ;
return F_43 ( V_113 , V_65 - V_113 -> V_120 ,
V_114 ) ;
}
static bool F_49 ( struct V_90 * V_13 ,
enum V_121 V_106 )
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
static int F_50 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_44 , unsigned V_46 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_121 V_122 ;
T_3 V_123 ;
int V_8 ;
int V_124 ;
for ( V_8 = 0 ; V_8 < V_46 ; V_8 ++ ) {
V_122 = F_51 ( V_44 [ V_8 ] ) ;
V_123 = F_52 ( V_44 [ V_8 ] ) ;
switch ( V_122 ) {
case V_95 :
V_124 = F_37 ( V_48 , V_11 - V_48 -> V_15 ,
V_122 ) ;
if ( V_124 )
return V_124 ;
break;
case V_102 :
case V_103 :
case V_98 :
case V_104 :
if ( ! F_49 ( V_6 -> V_13 , V_122 ) )
return - V_68 ;
if ( ! V_123 )
return - V_20 ;
V_124 = F_37 ( V_48 , V_11 - V_48 -> V_15 ,
V_122 ) ;
if ( V_124 )
return V_124 ;
break;
case V_125 :
F_53 ( & V_48 -> V_2 ,
V_11 - V_48 -> V_15 , V_123 ) ;
V_124 = F_43 ( & V_48 -> V_2 ,
V_11 - V_48 -> V_15 , false ) ;
if ( V_124 )
return V_124 ;
break;
case V_126 :
if ( ! V_6 -> V_13 -> V_91 )
return - V_68 ;
V_124 = F_33 ( V_48 ,
V_11 - V_48 -> V_15 , V_123 ) ;
if ( V_124 < 0 )
return V_124 ;
break;
default:
return - V_68 ;
break;
}
}
return 0 ;
}
static int F_54 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_127 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_121 V_122 = F_51 ( * V_127 ) ;
T_3 V_123 ;
int V_124 ;
switch ( V_122 ) {
case V_95 :
if ( F_35 ( V_48 , V_11 - V_48 -> V_15 ) != V_122 )
return - V_20 ;
V_123 = 0 ;
break;
case V_102 :
case V_103 :
case V_98 :
case V_104 :
if ( ! F_49 ( V_6 -> V_13 , V_122 ) )
return - V_68 ;
if ( F_35 ( V_48 , V_11 - V_48 -> V_15 ) != V_122 )
return - V_20 ;
V_123 = 1 ;
break;
case V_125 :
V_124 = F_20 ( V_48 , V_11 - V_48 -> V_15 ) ;
if ( V_124 != V_60 )
return - V_20 ;
V_124 = F_55 ( & V_48 -> V_2 , V_11 - V_48 -> V_15 ) ;
if ( V_124 < 0 )
return V_124 ;
V_123 = V_124 ? 1 : 0 ;
break;
case V_126 :
if ( ! V_6 -> V_13 -> V_91 )
return - V_68 ;
V_124 = F_32 ( V_48 , V_11 - V_48 -> V_15 ) ;
if ( V_124 < 0 )
return V_124 ;
V_123 = V_124 ;
break;
default:
return - V_68 ;
break;
}
* V_127 = F_56 ( V_122 , V_123 ) ;
return 0 ;
}
static void F_57 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
struct V_26 * V_128 ;
F_58 (np, child) {
if ( F_59 ( V_129 , V_128 ) )
continue;
V_6 -> V_107 ++ ;
V_6 -> V_9 += F_60 ( V_128 ) ;
}
}
static int F_61 ( struct V_26 * V_27 ,
struct V_4 * V_31 ,
struct V_5 * V_6 ,
T_2 V_130 )
{
struct V_1 * V_48 ;
int V_131 ;
const T_4 * V_132 ;
int V_17 ;
int V_8 , V_133 ;
int V_54 ;
F_18 ( V_6 -> V_35 , L_15 , V_130 , V_27 -> V_7 ) ;
V_31 -> V_7 = V_27 -> V_7 ;
V_132 = F_62 ( V_27 , L_16 , & V_131 ) ;
V_131 /= sizeof( * V_132 ) ;
if ( ! V_131 || V_131 % 4 ) {
F_12 ( V_6 -> V_35 , L_17 ) ;
return - V_20 ;
}
V_31 -> V_25 = V_131 / 4 ;
V_31 -> V_24 = F_13 ( V_6 -> V_35 , V_31 -> V_25 * sizeof( unsigned int ) ,
V_36 ) ;
V_31 -> V_39 = F_13 ( V_6 -> V_35 , V_31 -> V_25 *
sizeof( struct V_110 ) ,
V_36 ) ;
if ( ! V_31 -> V_24 || ! V_31 -> V_39 )
return - V_37 ;
for ( V_8 = 0 , V_133 = 0 ; V_8 < V_131 ; V_8 += 4 , V_133 ++ ) {
const T_4 * V_134 ;
struct V_26 * V_135 ;
V_17 = F_63 ( * V_132 ++ ) ;
V_48 = F_5 ( V_6 , V_17 ) ;
if ( F_64 ( V_48 ) )
return F_65 ( V_48 ) ;
V_31 -> V_24 [ V_133 ] = V_48 -> V_15 + F_63 ( * V_132 ++ ) ;
V_31 -> V_39 [ V_133 ] . V_112 = F_63 ( * V_132 ++ ) ;
V_134 = V_132 ++ ;
if ( ! V_134 )
return - V_20 ;
V_135 = F_66 ( F_67 ( V_134 ) ) ;
V_54 = F_68 ( V_135 , NULL ,
& V_31 -> V_39 [ V_133 ] . V_44 , & V_31 -> V_39 [ V_133 ] . V_47 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_69 ( struct V_26 * V_27 ,
struct V_5 * V_6 ,
T_2 V_130 )
{
struct V_26 * V_128 ;
struct V_136 * V_112 ;
struct V_4 * V_31 ;
int V_54 ;
static T_2 V_137 ;
T_2 V_8 = 0 ;
F_18 ( V_6 -> V_35 , L_18 , V_130 , V_27 -> V_7 ) ;
V_112 = & V_6 -> V_108 [ V_130 ] ;
V_112 -> V_7 = V_27 -> V_7 ;
V_112 -> V_9 = F_60 ( V_27 ) ;
if ( V_112 -> V_9 <= 0 )
return 0 ;
V_112 -> V_10 = F_13 ( V_6 -> V_35 ,
V_112 -> V_9 * sizeof( char * ) , V_36 ) ;
if ( ! V_112 -> V_10 )
return - V_37 ;
F_58 (np, child) {
V_112 -> V_10 [ V_8 ] = V_128 -> V_7 ;
V_31 = & V_6 -> V_10 [ V_137 ++ ] ;
V_54 = F_61 ( V_128 , V_31 , V_6 , V_8 ++ ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_70 ( struct V_138 * V_139 ,
struct V_5 * V_6 )
{
struct V_140 * V_35 = & V_139 -> V_35 ;
struct V_26 * V_27 = V_35 -> V_141 ;
struct V_26 * V_128 ;
int V_54 ;
int V_8 ;
F_57 ( V_6 , V_27 ) ;
F_18 ( & V_139 -> V_35 , L_19 , V_6 -> V_107 ) ;
F_18 ( & V_139 -> V_35 , L_20 , V_6 -> V_9 ) ;
V_6 -> V_108 = F_13 ( V_35 , V_6 -> V_107 *
sizeof( struct V_136 ) ,
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
F_58 (np, child) {
if ( F_59 ( V_129 , V_128 ) )
continue;
V_54 = F_69 ( V_128 , V_6 , V_8 ++ ) ;
if ( V_54 ) {
F_12 ( & V_139 -> V_35 , L_23 ) ;
return V_54 ;
}
}
return 0 ;
}
static int F_71 ( struct V_138 * V_139 ,
struct V_5 * V_6 )
{
struct V_142 * V_143 = & V_6 -> V_144 ;
struct V_145 * V_146 , * V_147 ;
struct V_1 * V_148 ;
int V_11 , V_48 , V_54 ;
int V_149 ;
V_143 -> V_7 = L_24 ;
V_143 -> V_150 = V_151 ;
V_143 -> V_152 = & V_153 ;
V_143 -> V_154 = & V_155 ;
V_143 -> V_156 = & V_157 ;
V_146 = F_13 ( & V_139 -> V_35 , sizeof( * V_146 ) *
V_6 -> V_13 -> V_16 , V_36 ) ;
if ( ! V_146 ) {
F_12 ( & V_139 -> V_35 , L_25 ) ;
return - V_37 ;
}
V_143 -> V_24 = V_146 ;
V_143 -> V_25 = V_6 -> V_13 -> V_16 ;
V_147 = V_146 ;
for ( V_48 = 0 , V_149 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; V_48 ++ ) {
V_148 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
for ( V_11 = 0 ; V_11 < V_148 -> V_16 ; V_11 ++ , V_149 ++ ) {
V_147 -> V_158 = V_149 ;
V_147 -> V_7 = F_72 ( V_36 , L_26 ,
V_148 -> V_7 , V_11 ) ;
V_147 ++ ;
}
}
V_54 = F_70 ( V_139 , V_6 ) ;
if ( V_54 )
return V_54 ;
V_6 -> V_159 = F_73 ( V_143 , & V_139 -> V_35 , V_6 ) ;
if ( F_64 ( V_6 -> V_159 ) ) {
F_12 ( & V_139 -> V_35 , L_27 ) ;
return F_65 ( V_6 -> V_159 ) ;
}
for ( V_48 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; ++ V_48 ) {
V_148 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
V_148 -> V_160 . V_7 = V_148 -> V_7 ;
V_148 -> V_160 . V_161 = V_48 ;
V_148 -> V_160 . V_15 = V_148 -> V_15 ;
V_148 -> V_160 . V_120 = V_148 -> V_2 . V_120 ;
V_148 -> V_160 . V_25 = V_148 -> V_2 . V_162 ;
V_148 -> V_160 . V_3 = & V_148 -> V_2 ;
F_74 ( V_6 -> V_159 , & V_148 -> V_160 ) ;
}
return 0 ;
}
static int F_75 ( struct V_2 * V_113 , unsigned V_65 )
{
return F_76 ( V_113 -> V_120 + V_65 ) ;
}
static void F_77 ( struct V_2 * V_113 , unsigned V_65 )
{
F_78 ( V_113 -> V_120 + V_65 ) ;
}
static void F_53 ( struct V_2 * V_3 , unsigned V_65 , int V_163 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
void T_5 * V_53 = V_48 -> V_116 + V_164 ;
unsigned long V_66 ;
T_2 V_39 ;
F_44 ( V_48 -> V_115 ) ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = F_79 ( V_53 ) ;
V_39 &= ~ F_36 ( V_65 ) ;
if ( V_163 )
V_39 |= F_36 ( V_65 ) ;
F_80 ( V_39 , V_53 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
F_47 ( V_48 -> V_115 ) ;
}
static int F_55 ( struct V_2 * V_3 , unsigned V_65 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
T_2 V_39 ;
F_44 ( V_48 -> V_115 ) ;
V_39 = F_79 ( V_48 -> V_116 + V_165 ) ;
F_47 ( V_48 -> V_115 ) ;
V_39 >>= V_65 ;
V_39 &= 1 ;
return V_39 ;
}
static int F_81 ( struct V_2 * V_3 , unsigned V_65 )
{
return F_82 ( V_3 -> V_120 + V_65 ) ;
}
static int F_83 ( struct V_2 * V_3 ,
unsigned V_65 , int V_163 )
{
F_53 ( V_3 , V_65 , V_163 ) ;
return F_84 ( V_3 -> V_120 + V_65 ) ;
}
static int F_85 ( struct V_2 * V_3 , unsigned V_65 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
unsigned int V_166 ;
if ( ! V_48 -> V_167 )
return - V_168 ;
V_166 = F_86 ( V_48 -> V_167 , V_65 ) ;
return ( V_166 ) ? : - V_168 ;
}
static void F_87 ( struct V_169 * V_170 )
{
struct V_171 * V_113 = F_88 ( V_170 ) ;
struct V_1 * V_48 = F_89 ( V_170 ) ;
T_2 V_172 ;
F_18 ( V_48 -> V_49 -> V_35 , L_28 , V_48 -> V_7 ) ;
F_90 ( V_113 , V_170 ) ;
V_172 = F_45 ( V_48 -> V_116 + V_173 ) ;
while ( V_172 ) {
unsigned int V_174 , V_166 ;
V_174 = F_91 ( V_172 ) ;
V_172 &= ~ F_36 ( V_174 ) ;
V_166 = F_92 ( V_48 -> V_167 , V_174 ) ;
if ( ! V_166 ) {
F_12 ( V_48 -> V_49 -> V_35 , L_29 , V_174 ) ;
continue;
}
F_18 ( V_48 -> V_49 -> V_35 , L_30 , V_174 ) ;
if ( V_48 -> V_175 & F_36 ( V_174 ) ) {
T_2 V_39 , V_176 , V_177 ;
unsigned long V_66 ;
V_39 = F_45 ( V_48 -> V_116 + V_165 ) ;
do {
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_177 = F_45 ( V_48 -> V_116 +
V_178 ) ;
if ( V_39 & F_36 ( V_174 ) )
V_177 &= ~ F_36 ( V_174 ) ;
else
V_177 |= F_36 ( V_174 ) ;
F_80 ( V_177 ,
V_48 -> V_116 + V_178 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
V_176 = V_39 ;
V_39 = F_45 ( V_48 -> V_116 +
V_165 ) ;
} while ( ( V_39 & F_36 ( V_174 ) ) != ( V_176 & F_36 ( V_174 ) ) );
}
F_93 ( V_166 ) ;
}
F_94 ( V_113 , V_170 ) ;
}
static int F_95 ( struct V_179 * V_180 , unsigned int type )
{
struct V_181 * V_3 = F_96 ( V_180 ) ;
struct V_1 * V_48 = V_3 -> V_182 ;
T_2 V_55 = F_36 ( V_180 -> V_183 ) ;
T_2 V_177 ;
T_2 V_184 ;
T_2 V_39 ;
unsigned long V_66 ;
int V_54 ;
V_54 = F_22 ( V_48 , V_180 -> V_183 , V_60 ) ;
if ( V_54 < 0 )
return V_54 ;
F_44 ( V_48 -> V_115 ) ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = F_45 ( V_48 -> V_116 + V_117 ) ;
V_39 &= ~ V_55 ;
F_46 ( V_39 , V_48 -> V_116 + V_117 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
if ( type & V_185 )
F_97 ( V_180 , V_186 ) ;
else
F_97 ( V_180 , V_187 ) ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
F_98 ( V_3 ) ;
V_184 = F_45 ( V_3 -> V_116 + V_188 ) ;
V_177 = F_45 ( V_3 -> V_116 + V_178 ) ;
switch ( type ) {
case V_185 :
V_48 -> V_175 |= V_55 ;
V_184 |= V_55 ;
V_39 = F_79 ( V_48 -> V_116 + V_165 ) ;
if ( V_39 & V_55 )
V_177 &= ~ V_55 ;
else
V_177 |= V_55 ;
break;
case V_189 :
V_48 -> V_175 &= ~ V_55 ;
V_184 |= V_55 ;
V_177 |= V_55 ;
break;
case V_190 :
V_48 -> V_175 &= ~ V_55 ;
V_184 |= V_55 ;
V_177 &= ~ V_55 ;
break;
case V_191 :
V_48 -> V_175 &= ~ V_55 ;
V_184 &= ~ V_55 ;
V_177 |= V_55 ;
break;
case V_192 :
V_48 -> V_175 &= ~ V_55 ;
V_184 &= ~ V_55 ;
V_177 &= ~ V_55 ;
break;
default:
F_99 ( V_3 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
F_47 ( V_48 -> V_115 ) ;
return - V_20 ;
}
F_46 ( V_184 , V_3 -> V_116 + V_188 ) ;
F_46 ( V_177 , V_3 -> V_116 + V_178 ) ;
F_99 ( V_3 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
F_47 ( V_48 -> V_115 ) ;
return 0 ;
}
static void F_100 ( struct V_179 * V_180 )
{
struct V_181 * V_3 = F_96 ( V_180 ) ;
struct V_1 * V_48 = V_3 -> V_182 ;
F_44 ( V_48 -> V_115 ) ;
V_48 -> V_193 = F_101 ( V_3 , V_194 ) ;
F_102 ( V_3 , ~ V_3 -> V_195 , V_194 ) ;
F_47 ( V_48 -> V_115 ) ;
}
static void F_103 ( struct V_179 * V_180 )
{
struct V_181 * V_3 = F_96 ( V_180 ) ;
struct V_1 * V_48 = V_3 -> V_182 ;
F_44 ( V_48 -> V_115 ) ;
F_102 ( V_3 , V_48 -> V_193 , V_194 ) ;
F_47 ( V_48 -> V_115 ) ;
}
static void F_104 ( struct V_179 * V_180 )
{
struct V_181 * V_3 = F_96 ( V_180 ) ;
struct V_1 * V_48 = V_3 -> V_182 ;
F_44 ( V_48 -> V_115 ) ;
F_105 ( V_180 ) ;
}
void F_106 ( struct V_179 * V_180 )
{
struct V_181 * V_3 = F_96 ( V_180 ) ;
struct V_1 * V_48 = V_3 -> V_182 ;
F_107 ( V_180 ) ;
F_47 ( V_48 -> V_115 ) ;
}
static int F_108 ( struct V_138 * V_139 ,
struct V_5 * V_6 )
{
struct V_90 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
unsigned int V_196 = V_197 | V_198 | V_199 ;
struct V_181 * V_3 ;
int V_54 ;
int V_8 , V_133 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_200 ) {
F_109 ( & V_139 -> V_35 , L_31 ,
V_48 -> V_7 ) ;
continue;
}
V_54 = F_44 ( V_48 -> V_115 ) ;
if ( V_54 ) {
F_12 ( & V_139 -> V_35 , L_32 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_167 = F_110 ( V_48 -> V_141 , 32 ,
& V_201 , NULL ) ;
if ( ! V_48 -> V_167 ) {
F_109 ( & V_139 -> V_35 , L_33 ,
V_48 -> V_7 ) ;
F_47 ( V_48 -> V_115 ) ;
continue;
}
V_54 = F_111 ( V_48 -> V_167 , 32 , 1 ,
L_34 , V_187 ,
V_196 , 0 , V_202 ) ;
if ( V_54 ) {
F_12 ( & V_139 -> V_35 , L_35 ,
V_48 -> V_7 ) ;
F_112 ( V_48 -> V_167 ) ;
F_47 ( V_48 -> V_115 ) ;
continue;
}
F_46 ( 0xffffffff , V_48 -> V_116 + V_194 ) ;
F_46 ( 0xffffffff , V_48 -> V_116 + V_203 ) ;
V_3 = F_113 ( V_48 -> V_167 , 0 ) ;
V_3 -> V_116 = V_48 -> V_116 ;
V_3 -> V_182 = V_48 ;
V_3 -> V_204 [ 0 ] . V_205 . V_55 = V_194 ;
V_3 -> V_204 [ 0 ] . V_205 . V_206 = V_207 ;
V_3 -> V_204 [ 0 ] . V_113 . V_208 = V_209 ;
V_3 -> V_204 [ 0 ] . V_113 . V_210 = F_106 ;
V_3 -> V_204 [ 0 ] . V_113 . V_211 =
F_104 ;
V_3 -> V_204 [ 0 ] . V_113 . V_212 = V_213 ;
V_3 -> V_204 [ 0 ] . V_113 . V_214 = F_100 ;
V_3 -> V_204 [ 0 ] . V_113 . V_215 = F_103 ;
V_3 -> V_204 [ 0 ] . V_113 . V_216 = F_95 ;
V_3 -> V_217 = F_114 ( V_48 -> V_16 ) ;
F_115 ( V_48 -> V_174 ,
F_87 , V_48 ) ;
for ( V_133 = 0 ; V_133 < 32 ; V_133 ++ )
F_86 ( V_48 -> V_167 , V_133 ) ;
F_47 ( V_48 -> V_115 ) ;
}
return 0 ;
}
static int F_116 ( struct V_138 * V_139 ,
struct V_5 * V_6 )
{
struct V_90 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
struct V_2 * V_3 ;
int V_54 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_200 ) {
F_109 ( & V_139 -> V_35 , L_31 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_2 = V_218 ;
V_3 = & V_48 -> V_2 ;
V_3 -> V_120 = V_48 -> V_15 ;
V_3 -> V_162 = V_48 -> V_16 ;
V_3 -> V_35 = & V_139 -> V_35 ;
V_3 -> V_141 = V_48 -> V_141 ;
V_3 -> V_219 = V_48 -> V_7 ;
V_54 = F_117 ( V_3 ) ;
if ( V_54 ) {
F_12 ( & V_139 -> V_35 , L_36 ,
V_3 -> V_219 , V_54 ) ;
goto V_220;
}
}
F_108 ( V_139 , V_6 ) ;
return 0 ;
V_220:
for ( -- V_8 , -- V_48 ; V_8 >= 0 ; -- V_8 , -- V_48 ) {
if ( ! V_48 -> V_200 )
continue;
F_118 ( & V_48 -> V_2 ) ;
}
return V_54 ;
}
static int F_119 ( struct V_138 * V_139 ,
struct V_5 * V_6 )
{
struct V_90 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_200 )
continue;
F_118 ( & V_48 -> V_2 ) ;
}
return 0 ;
}
static int F_120 ( struct V_1 * V_48 ,
struct V_5 * V_6 )
{
struct V_221 V_222 ;
void T_5 * V_120 ;
if ( F_121 ( V_48 -> V_141 , 0 , & V_222 ) ) {
F_12 ( V_6 -> V_35 , L_37 ) ;
return - V_223 ;
}
V_48 -> V_116 = F_122 ( V_6 -> V_35 , & V_222 ) ;
if ( F_64 ( V_48 -> V_116 ) )
return F_65 ( V_48 -> V_116 ) ;
if ( F_123 ( V_48 -> V_141 ,
L_38 ) ) {
struct V_26 * V_224 ;
V_224 = F_124 ( V_48 -> V_141 -> V_33 ,
L_39 , 0 ) ;
if ( ! V_224 ) {
if ( F_121 ( V_48 -> V_141 , 1 , & V_222 ) ) {
F_12 ( V_6 -> V_35 , L_37 ) ;
return - V_223 ;
}
V_120 = F_122 ( V_6 -> V_35 , & V_222 ) ;
if ( F_64 ( V_120 ) )
return F_65 ( V_120 ) ;
V_225 . V_226 =
F_125 ( & V_222 ) - 4 ;
V_225 . V_7 =
L_40 ;
V_48 -> V_74 = F_126 ( V_6 -> V_35 ,
V_120 ,
& V_225 ) ;
}
}
V_48 -> V_174 = F_127 ( V_48 -> V_141 , 0 ) ;
V_48 -> V_115 = F_128 ( V_48 -> V_141 , 0 ) ;
if ( F_64 ( V_48 -> V_115 ) )
return F_65 ( V_48 -> V_115 ) ;
return F_129 ( V_48 -> V_115 ) ;
}
static struct V_90 * F_130 (
struct V_5 * V_180 ,
struct V_138 * V_139 )
{
const struct V_227 * V_228 ;
struct V_26 * V_224 = V_139 -> V_35 . V_141 ;
struct V_26 * V_27 ;
struct V_90 * V_13 ;
struct V_1 * V_48 ;
int V_229 , V_230 , V_8 , V_133 ;
V_228 = F_59 ( V_231 , V_224 ) ;
V_13 = (struct V_90 * ) V_228 -> V_39 ;
F_58 (node, np) {
if ( ! F_131 ( V_27 , L_41 , NULL ) )
continue;
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! strcmp ( V_48 -> V_7 , V_27 -> V_7 ) ) {
V_48 -> V_141 = V_27 ;
if ( ! F_120 ( V_48 , V_180 ) )
V_48 -> V_200 = true ;
break;
}
}
}
V_229 = V_13 -> V_232 ;
V_230 = V_13 -> V_233 ;
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
int V_234 = 0 ;
F_132 ( & V_48 -> V_69 ) ;
V_48 -> V_49 = V_180 ;
V_48 -> V_15 = V_13 -> V_16 ;
V_13 -> V_16 += V_48 -> V_16 ;
for ( V_133 = 0 ; V_133 < 4 ; V_133 ++ ) {
struct V_235 * V_236 = & V_48 -> V_57 [ V_133 ] ;
int V_237 ;
if ( V_234 >= V_48 -> V_16 )
break;
if ( V_236 -> V_65 >= 0 ) {
if ( V_236 -> type & V_61 )
V_230 = V_236 -> V_65 ;
else
V_229 = V_236 -> V_65 ;
} else {
V_236 -> V_65 = ( V_236 -> type & V_61 ) ?
V_230 : V_229 ;
}
F_18 ( V_180 -> V_35 , L_42 ,
V_8 , V_133 , V_236 -> V_65 ) ;
V_237 = ( V_236 -> type & V_64 ) ? 8 : 4 ;
if ( V_236 -> type & V_61 )
V_230 += V_237 ;
else
V_229 += V_237 ;
V_234 += 8 ;
}
}
return V_13 ;
}
static int T_6 F_133 ( struct V_140 * V_35 )
{
struct V_5 * V_6 = F_134 ( V_35 ) ;
int V_54 = F_135 ( V_6 -> V_159 ) ;
if ( V_54 )
return V_54 ;
if ( V_6 -> V_13 -> type == V_100 ) {
V_54 = F_21 ( V_6 -> V_63 , V_238 ,
& V_239 ) ;
if ( V_54 ) {
F_136 ( V_6 -> V_159 ) ;
return V_54 ;
}
}
return 0 ;
}
static int T_6 F_137 ( struct V_140 * V_35 )
{
struct V_5 * V_6 = F_134 ( V_35 ) ;
int V_54 = F_38 ( V_6 -> V_63 , V_238 ,
V_239 |
V_240 ) ;
if ( V_54 )
return V_54 ;
return F_136 ( V_6 -> V_159 ) ;
}
static int F_138 ( struct V_138 * V_139 )
{
struct V_5 * V_6 ;
struct V_140 * V_35 = & V_139 -> V_35 ;
struct V_90 * V_13 ;
struct V_26 * V_27 = V_139 -> V_35 . V_141 , * V_224 ;
struct V_221 * V_222 ;
void T_5 * V_120 ;
int V_54 ;
if ( ! V_35 -> V_141 ) {
F_12 ( V_35 , L_43 ) ;
return - V_241 ;
}
V_6 = F_13 ( V_35 , sizeof( struct V_5 ) , V_36 ) ;
if ( ! V_6 )
return - V_37 ;
V_6 -> V_35 = V_35 ;
V_13 = F_130 ( V_6 , V_139 ) ;
if ( ! V_13 ) {
F_12 ( V_35 , L_44 ) ;
return - V_20 ;
}
V_6 -> V_13 = V_13 ;
V_224 = F_124 ( V_27 , L_45 , 0 ) ;
if ( V_224 ) {
V_6 -> V_63 = F_139 ( V_224 ) ;
if ( F_64 ( V_6 -> V_63 ) )
return F_65 ( V_6 -> V_63 ) ;
} else {
V_222 = F_140 ( V_139 , V_242 , 0 ) ;
V_120 = F_122 ( & V_139 -> V_35 , V_222 ) ;
if ( F_64 ( V_120 ) )
return F_65 ( V_120 ) ;
V_225 . V_226 = F_125 ( V_222 ) - 4 ;
V_225 . V_7 = L_46 ;
V_6 -> V_63 = F_126 ( & V_139 -> V_35 , V_120 ,
& V_225 ) ;
V_6 -> V_243 = F_125 ( V_222 ) ;
if ( V_13 -> type == V_99 && V_6 -> V_243 < 0x200 ) {
V_222 = F_140 ( V_139 , V_242 , 1 ) ;
V_120 = F_122 ( & V_139 -> V_35 , V_222 ) ;
if ( F_64 ( V_120 ) )
return F_65 ( V_120 ) ;
V_225 . V_226 =
F_125 ( V_222 ) - 4 ;
V_225 . V_7 = L_47 ;
V_6 -> V_74 = F_126 ( & V_139 -> V_35 ,
V_120 ,
& V_225 ) ;
}
}
V_224 = F_124 ( V_27 , L_39 , 0 ) ;
if ( V_224 ) {
V_6 -> V_62 = F_139 ( V_224 ) ;
if ( F_64 ( V_6 -> V_62 ) )
return F_65 ( V_6 -> V_62 ) ;
}
V_54 = F_116 ( V_139 , V_6 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_71 ( V_139 , V_6 ) ;
if ( V_54 ) {
F_119 ( V_139 , V_6 ) ;
return V_54 ;
}
F_141 ( V_139 , V_6 ) ;
return 0 ;
}
static int T_7 F_142 ( void )
{
return F_143 ( & V_244 ) ;
}
