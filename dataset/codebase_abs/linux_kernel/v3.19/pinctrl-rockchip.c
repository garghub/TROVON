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
static int F_30 ( struct V_1 * V_48 , int V_70 )
{
struct V_51 * V_51 ;
int V_53 , V_54 ;
T_2 V_39 ;
T_1 V_56 ;
F_29 ( V_48 , V_70 , & V_51 , & V_53 , & V_56 ) ;
V_54 = F_21 ( V_51 , V_53 , & V_39 ) ;
if ( V_54 )
return V_54 ;
V_39 >>= V_56 ;
V_39 &= ( 1 << V_83 ) - 1 ;
return V_86 [ V_39 ] ;
}
static int F_31 ( struct V_1 * V_48 , int V_70 ,
int V_87 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_51 * V_51 ;
unsigned long V_66 ;
int V_53 , V_54 , V_8 ;
T_2 V_39 , V_67 ;
T_1 V_56 ;
F_29 ( V_48 , V_70 , & V_51 , & V_53 , & V_56 ) ;
V_54 = - V_20 ;
for ( V_8 = 0 ; V_8 < F_32 ( V_86 ) ; V_8 ++ ) {
if ( V_86 [ V_8 ] == V_87 ) {
V_54 = V_8 ;
break;
}
}
if ( V_54 < 0 ) {
F_12 ( V_6 -> V_35 , L_6 ,
V_87 ) ;
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
static int F_33 ( struct V_1 * V_48 , int V_70 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_88 * V_13 = V_6 -> V_13 ;
struct V_51 * V_51 ;
int V_53 , V_54 ;
T_1 V_56 ;
T_2 V_39 ;
if ( V_13 -> type == V_89 )
return V_90 ;
V_13 -> V_91 ( V_48 , V_70 , & V_51 , & V_53 , & V_56 ) ;
V_54 = F_21 ( V_51 , V_53 , & V_39 ) ;
if ( V_54 )
return V_54 ;
switch ( V_13 -> type ) {
case V_92 :
return ! ( V_39 & F_34 ( V_56 ) )
? V_93
: V_90 ;
case V_94 :
case V_95 :
V_39 >>= V_56 ;
V_39 &= ( 1 << V_77 ) - 1 ;
switch ( V_39 ) {
case 0 :
return V_90 ;
case 1 :
return V_96 ;
case 2 :
return V_97 ;
case 3 :
return V_98 ;
}
F_12 ( V_6 -> V_35 , L_7 ) ;
return - V_99 ;
default:
F_12 ( V_6 -> V_35 , L_8 ) ;
return - V_20 ;
} ;
}
static int F_35 ( struct V_1 * V_48 ,
int V_70 , int V_100 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_88 * V_13 = V_6 -> V_13 ;
struct V_51 * V_51 ;
int V_53 , V_54 ;
unsigned long V_66 ;
T_1 V_56 ;
T_2 V_39 , V_67 ;
F_18 ( V_6 -> V_35 , L_9 ,
V_48 -> V_19 , V_70 , V_100 ) ;
if ( V_13 -> type == V_89 )
return V_100 ? - V_20 : 0 ;
V_13 -> V_91 ( V_48 , V_70 , & V_51 , & V_53 , & V_56 ) ;
switch ( V_13 -> type ) {
case V_92 :
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = F_34 ( V_56 + 16 ) ;
if ( V_100 == V_90 )
V_39 |= F_34 ( V_56 ) ;
V_54 = F_36 ( V_51 , V_53 , V_39 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
break;
case V_94 :
case V_95 :
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = ( ( 1 << V_77 ) - 1 ) << ( V_56 + 16 ) ;
V_67 = V_39 | ( V_39 >> 16 ) ;
switch ( V_100 ) {
case V_90 :
break;
case V_96 :
V_39 |= ( 1 << V_56 ) ;
break;
case V_97 :
V_39 |= ( 2 << V_56 ) ;
break;
case V_98 :
V_39 |= ( 3 << V_56 ) ;
break;
default:
F_25 ( & V_48 -> V_69 , V_66 ) ;
F_12 ( V_6 -> V_35 , L_10 ,
V_100 ) ;
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
static int F_37 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_101 ;
}
static const char * F_38 ( struct V_21 * V_22 ,
unsigned V_23 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_102 [ V_23 ] . V_7 ;
}
static int F_39 ( struct V_21 * V_22 ,
unsigned V_23 , const char * const * * V_10 ,
unsigned * const V_103 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
* V_10 = V_6 -> V_102 [ V_23 ] . V_10 ;
* V_103 = V_6 -> V_102 [ V_23 ] . V_9 ;
return 0 ;
}
static int F_40 ( struct V_21 * V_22 , unsigned V_23 ,
unsigned V_42 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
const unsigned int * V_24 = V_6 -> V_10 [ V_42 ] . V_24 ;
const struct V_104 * V_39 = V_6 -> V_10 [ V_42 ] . V_39 ;
struct V_1 * V_48 ;
int V_105 , V_54 = 0 ;
F_18 ( V_6 -> V_35 , L_11 ,
V_6 -> V_102 [ V_23 ] . V_7 , V_6 -> V_10 [ V_42 ] . V_7 ) ;
for ( V_105 = 0 ; V_105 < V_6 -> V_10 [ V_42 ] . V_25 ; V_105 ++ ) {
V_48 = F_4 ( V_6 , V_24 [ V_105 ] ) ;
V_54 = F_22 ( V_48 , V_24 [ V_105 ] - V_48 -> V_15 ,
V_39 [ V_105 ] . V_106 ) ;
if ( V_54 )
break;
}
if ( V_54 ) {
for ( V_105 -- ; V_105 >= 0 ; V_105 -- )
F_22 ( V_48 , V_24 [ V_105 ] - V_48 -> V_15 , 0 ) ;
return V_54 ;
}
return 0 ;
}
static int F_41 ( struct V_2 * V_107 ,
int V_11 , bool V_108 )
{
struct V_1 * V_48 ;
int V_54 ;
unsigned long V_66 ;
T_2 V_39 ;
V_48 = F_1 ( V_107 ) ;
V_54 = F_22 ( V_48 , V_11 , V_60 ) ;
if ( V_54 < 0 )
return V_54 ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = F_42 ( V_48 -> V_109 + V_110 ) ;
if ( ! V_108 )
V_39 |= F_34 ( V_11 ) ;
else
V_39 &= ~ F_34 ( V_11 ) ;
F_43 ( V_39 , V_48 -> V_109 + V_110 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
return 0 ;
}
static int F_44 ( struct V_21 * V_22 ,
struct V_111 * V_112 ,
unsigned V_65 , bool V_108 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_2 * V_107 ;
int V_11 ;
V_107 = V_112 -> V_3 ;
V_11 = V_65 - V_107 -> V_113 ;
F_18 ( V_6 -> V_35 , L_12 ,
V_65 , V_112 -> V_7 , V_11 , V_108 ? L_13 : L_14 ) ;
return F_41 ( V_107 , V_65 - V_107 -> V_113 ,
V_108 ) ;
}
static bool F_45 ( struct V_88 * V_13 ,
enum V_114 V_100 )
{
switch ( V_13 -> type ) {
case V_92 :
return ( V_100 == V_93 ||
V_100 == V_90 ) ;
case V_89 :
return V_100 ? false : true ;
case V_94 :
case V_95 :
return ( V_100 != V_93 ) ;
}
return false ;
}
static int F_46 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_44 , unsigned V_46 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_114 V_115 ;
T_3 V_116 ;
int V_8 ;
int V_117 ;
for ( V_8 = 0 ; V_8 < V_46 ; V_8 ++ ) {
V_115 = F_47 ( V_44 [ V_8 ] ) ;
V_116 = F_48 ( V_44 [ V_8 ] ) ;
switch ( V_115 ) {
case V_90 :
V_117 = F_35 ( V_48 , V_11 - V_48 -> V_15 ,
V_115 ) ;
if ( V_117 )
return V_117 ;
break;
case V_96 :
case V_97 :
case V_93 :
case V_98 :
if ( ! F_45 ( V_6 -> V_13 , V_115 ) )
return - V_68 ;
if ( ! V_116 )
return - V_20 ;
V_117 = F_35 ( V_48 , V_11 - V_48 -> V_15 ,
V_115 ) ;
if ( V_117 )
return V_117 ;
break;
case V_118 :
F_49 ( & V_48 -> V_2 ,
V_11 - V_48 -> V_15 , V_116 ) ;
V_117 = F_41 ( & V_48 -> V_2 ,
V_11 - V_48 -> V_15 , false ) ;
if ( V_117 )
return V_117 ;
break;
case V_119 :
if ( V_6 -> V_13 -> type != V_95 )
return - V_68 ;
V_117 = F_31 ( V_48 , V_11 - V_48 -> V_15 , V_116 ) ;
if ( V_117 < 0 )
return V_117 ;
break;
default:
return - V_68 ;
break;
}
}
return 0 ;
}
static int F_50 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_120 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_114 V_115 = F_47 ( * V_120 ) ;
T_3 V_116 ;
int V_117 ;
switch ( V_115 ) {
case V_90 :
if ( F_33 ( V_48 , V_11 - V_48 -> V_15 ) != V_115 )
return - V_20 ;
V_116 = 0 ;
break;
case V_96 :
case V_97 :
case V_93 :
case V_98 :
if ( ! F_45 ( V_6 -> V_13 , V_115 ) )
return - V_68 ;
if ( F_33 ( V_48 , V_11 - V_48 -> V_15 ) != V_115 )
return - V_20 ;
V_116 = 1 ;
break;
case V_118 :
V_117 = F_20 ( V_48 , V_11 - V_48 -> V_15 ) ;
if ( V_117 != V_60 )
return - V_20 ;
V_117 = F_51 ( & V_48 -> V_2 , V_11 - V_48 -> V_15 ) ;
if ( V_117 < 0 )
return V_117 ;
V_116 = V_117 ? 1 : 0 ;
break;
case V_119 :
if ( V_6 -> V_13 -> type != V_95 )
return - V_68 ;
V_117 = F_30 ( V_48 , V_11 - V_48 -> V_15 ) ;
if ( V_117 < 0 )
return V_117 ;
V_116 = V_117 ;
break;
default:
return - V_68 ;
break;
}
* V_120 = F_52 ( V_115 , V_116 ) ;
return 0 ;
}
static void F_53 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
struct V_26 * V_121 ;
F_54 (np, child) {
if ( F_55 ( V_122 , V_121 ) )
continue;
V_6 -> V_101 ++ ;
V_6 -> V_9 += F_56 ( V_121 ) ;
}
}
static int F_57 ( struct V_26 * V_27 ,
struct V_4 * V_31 ,
struct V_5 * V_6 ,
T_2 V_123 )
{
struct V_1 * V_48 ;
int V_124 ;
const T_4 * V_125 ;
int V_17 ;
int V_8 , V_126 ;
int V_54 ;
F_18 ( V_6 -> V_35 , L_15 , V_123 , V_27 -> V_7 ) ;
V_31 -> V_7 = V_27 -> V_7 ;
V_125 = F_58 ( V_27 , L_16 , & V_124 ) ;
V_124 /= sizeof( * V_125 ) ;
if ( ! V_124 || V_124 % 4 ) {
F_12 ( V_6 -> V_35 , L_17 ) ;
return - V_20 ;
}
V_31 -> V_25 = V_124 / 4 ;
V_31 -> V_24 = F_13 ( V_6 -> V_35 , V_31 -> V_25 * sizeof( unsigned int ) ,
V_36 ) ;
V_31 -> V_39 = F_13 ( V_6 -> V_35 , V_31 -> V_25 *
sizeof( struct V_104 ) ,
V_36 ) ;
if ( ! V_31 -> V_24 || ! V_31 -> V_39 )
return - V_37 ;
for ( V_8 = 0 , V_126 = 0 ; V_8 < V_124 ; V_8 += 4 , V_126 ++ ) {
const T_4 * V_127 ;
struct V_26 * V_128 ;
V_17 = F_59 ( * V_125 ++ ) ;
V_48 = F_5 ( V_6 , V_17 ) ;
if ( F_60 ( V_48 ) )
return F_61 ( V_48 ) ;
V_31 -> V_24 [ V_126 ] = V_48 -> V_15 + F_59 ( * V_125 ++ ) ;
V_31 -> V_39 [ V_126 ] . V_106 = F_59 ( * V_125 ++ ) ;
V_127 = V_125 ++ ;
if ( ! V_127 )
return - V_20 ;
V_128 = F_62 ( F_63 ( V_127 ) ) ;
V_54 = F_64 ( V_128 ,
& V_31 -> V_39 [ V_126 ] . V_44 , & V_31 -> V_39 [ V_126 ] . V_47 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_65 ( struct V_26 * V_27 ,
struct V_5 * V_6 ,
T_2 V_123 )
{
struct V_26 * V_121 ;
struct V_129 * V_106 ;
struct V_4 * V_31 ;
int V_54 ;
static T_2 V_130 ;
T_2 V_8 = 0 ;
F_18 ( V_6 -> V_35 , L_18 , V_123 , V_27 -> V_7 ) ;
V_106 = & V_6 -> V_102 [ V_123 ] ;
V_106 -> V_7 = V_27 -> V_7 ;
V_106 -> V_9 = F_56 ( V_27 ) ;
if ( V_106 -> V_9 <= 0 )
return 0 ;
V_106 -> V_10 = F_13 ( V_6 -> V_35 ,
V_106 -> V_9 * sizeof( char * ) , V_36 ) ;
if ( ! V_106 -> V_10 )
return - V_37 ;
F_54 (np, child) {
V_106 -> V_10 [ V_8 ] = V_121 -> V_7 ;
V_31 = & V_6 -> V_10 [ V_130 ++ ] ;
V_54 = F_57 ( V_121 , V_31 , V_6 , V_8 ++ ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_66 ( struct V_131 * V_132 ,
struct V_5 * V_6 )
{
struct V_133 * V_35 = & V_132 -> V_35 ;
struct V_26 * V_27 = V_35 -> V_134 ;
struct V_26 * V_121 ;
int V_54 ;
int V_8 ;
F_53 ( V_6 , V_27 ) ;
F_18 ( & V_132 -> V_35 , L_19 , V_6 -> V_101 ) ;
F_18 ( & V_132 -> V_35 , L_20 , V_6 -> V_9 ) ;
V_6 -> V_102 = F_13 ( V_35 , V_6 -> V_101 *
sizeof( struct V_129 ) ,
V_36 ) ;
if ( ! V_6 -> V_102 ) {
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
F_54 (np, child) {
if ( F_55 ( V_122 , V_121 ) )
continue;
V_54 = F_65 ( V_121 , V_6 , V_8 ++ ) ;
if ( V_54 ) {
F_12 ( & V_132 -> V_35 , L_23 ) ;
return V_54 ;
}
}
return 0 ;
}
static int F_67 ( struct V_131 * V_132 ,
struct V_5 * V_6 )
{
struct V_135 * V_136 = & V_6 -> V_137 ;
struct V_138 * V_139 , * V_140 ;
struct V_1 * V_141 ;
int V_11 , V_48 , V_54 ;
int V_142 ;
V_136 -> V_7 = L_24 ;
V_136 -> V_143 = V_144 ;
V_136 -> V_145 = & V_146 ;
V_136 -> V_147 = & V_148 ;
V_136 -> V_149 = & V_150 ;
V_139 = F_13 ( & V_132 -> V_35 , sizeof( * V_139 ) *
V_6 -> V_13 -> V_16 , V_36 ) ;
if ( ! V_139 ) {
F_12 ( & V_132 -> V_35 , L_25 ) ;
return - V_37 ;
}
V_136 -> V_24 = V_139 ;
V_136 -> V_25 = V_6 -> V_13 -> V_16 ;
V_140 = V_139 ;
for ( V_48 = 0 , V_142 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; V_48 ++ ) {
V_141 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
for ( V_11 = 0 ; V_11 < V_141 -> V_16 ; V_11 ++ , V_142 ++ ) {
V_140 -> V_151 = V_142 ;
V_140 -> V_7 = F_68 ( V_36 , L_26 ,
V_141 -> V_7 , V_11 ) ;
V_140 ++ ;
}
}
V_54 = F_66 ( V_132 , V_6 ) ;
if ( V_54 )
return V_54 ;
V_6 -> V_152 = F_69 ( V_136 , & V_132 -> V_35 , V_6 ) ;
if ( ! V_6 -> V_152 ) {
F_12 ( & V_132 -> V_35 , L_27 ) ;
return - V_20 ;
}
for ( V_48 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; ++ V_48 ) {
V_141 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
V_141 -> V_153 . V_7 = V_141 -> V_7 ;
V_141 -> V_153 . V_154 = V_48 ;
V_141 -> V_153 . V_15 = V_141 -> V_15 ;
V_141 -> V_153 . V_113 = V_141 -> V_2 . V_113 ;
V_141 -> V_153 . V_25 = V_141 -> V_2 . V_155 ;
V_141 -> V_153 . V_3 = & V_141 -> V_2 ;
F_70 ( V_6 -> V_152 , & V_141 -> V_153 ) ;
}
return 0 ;
}
static int F_71 ( struct V_2 * V_107 , unsigned V_65 )
{
return F_72 ( V_107 -> V_113 + V_65 ) ;
}
static void F_73 ( struct V_2 * V_107 , unsigned V_65 )
{
F_74 ( V_107 -> V_113 + V_65 ) ;
}
static void F_49 ( struct V_2 * V_3 , unsigned V_65 , int V_156 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
void T_5 * V_53 = V_48 -> V_109 + V_157 ;
unsigned long V_66 ;
T_2 V_39 ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = F_75 ( V_53 ) ;
V_39 &= ~ F_34 ( V_65 ) ;
if ( V_156 )
V_39 |= F_34 ( V_65 ) ;
F_76 ( V_39 , V_53 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
}
static int F_51 ( struct V_2 * V_3 , unsigned V_65 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
T_2 V_39 ;
V_39 = F_75 ( V_48 -> V_109 + V_158 ) ;
V_39 >>= V_65 ;
V_39 &= 1 ;
return V_39 ;
}
static int F_77 ( struct V_2 * V_3 , unsigned V_65 )
{
return F_78 ( V_3 -> V_113 + V_65 ) ;
}
static int F_79 ( struct V_2 * V_3 ,
unsigned V_65 , int V_156 )
{
F_49 ( V_3 , V_65 , V_156 ) ;
return F_80 ( V_3 -> V_113 + V_65 ) ;
}
static int F_81 ( struct V_2 * V_3 , unsigned V_65 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
unsigned int V_159 ;
if ( ! V_48 -> V_160 )
return - V_161 ;
V_159 = F_82 ( V_48 -> V_160 , V_65 ) ;
return ( V_159 ) ? : - V_161 ;
}
static void F_83 ( unsigned int V_162 , struct V_163 * V_164 )
{
struct V_165 * V_107 = F_84 ( V_162 ) ;
struct V_1 * V_48 = F_85 ( V_162 ) ;
T_2 V_166 ;
F_18 ( V_48 -> V_49 -> V_35 , L_28 , V_48 -> V_7 ) ;
F_86 ( V_107 , V_164 ) ;
V_166 = F_42 ( V_48 -> V_109 + V_167 ) ;
while ( V_166 ) {
unsigned int V_159 ;
V_162 = F_87 ( V_166 ) ;
V_166 &= ~ F_34 ( V_162 ) ;
V_159 = F_88 ( V_48 -> V_160 , V_162 ) ;
if ( ! V_159 ) {
F_12 ( V_48 -> V_49 -> V_35 , L_29 , V_162 ) ;
continue;
}
F_18 ( V_48 -> V_49 -> V_35 , L_30 , V_162 ) ;
if ( V_48 -> V_168 & F_34 ( V_162 ) ) {
T_2 V_39 , V_169 , V_170 ;
unsigned long V_66 ;
V_39 = F_42 ( V_48 -> V_109 + V_158 ) ;
do {
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_170 = F_42 ( V_48 -> V_109 +
V_171 ) ;
if ( V_39 & F_34 ( V_162 ) )
V_170 &= ~ F_34 ( V_162 ) ;
else
V_170 |= F_34 ( V_162 ) ;
F_76 ( V_170 ,
V_48 -> V_109 + V_171 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
V_169 = V_39 ;
V_39 = F_42 ( V_48 -> V_109 +
V_158 ) ;
} while ( ( V_39 & F_34 ( V_162 ) ) != ( V_169 & F_34 ( V_162 ) ) );
}
F_89 ( V_159 ) ;
}
F_90 ( V_107 , V_164 ) ;
}
static int F_91 ( struct V_172 * V_173 , unsigned int type )
{
struct V_174 * V_3 = F_92 ( V_173 ) ;
struct V_1 * V_48 = V_3 -> V_175 ;
T_2 V_55 = F_34 ( V_173 -> V_176 ) ;
T_2 V_170 ;
T_2 V_177 ;
T_2 V_39 ;
unsigned long V_66 ;
int V_54 ;
V_54 = F_22 ( V_48 , V_173 -> V_176 , V_60 ) ;
if ( V_54 < 0 )
return V_54 ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
V_39 = F_42 ( V_48 -> V_109 + V_110 ) ;
V_39 &= ~ V_55 ;
F_43 ( V_39 , V_48 -> V_109 + V_110 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
if ( type & V_178 )
F_93 ( V_173 -> V_162 , V_179 ) ;
else
F_93 ( V_173 -> V_162 , V_180 ) ;
F_23 ( & V_48 -> V_69 , V_66 ) ;
F_94 ( V_3 ) ;
V_177 = F_42 ( V_3 -> V_109 + V_181 ) ;
V_170 = F_42 ( V_3 -> V_109 + V_171 ) ;
switch ( type ) {
case V_178 :
V_48 -> V_168 |= V_55 ;
V_177 |= V_55 ;
V_39 = F_75 ( V_48 -> V_109 + V_158 ) ;
if ( V_39 & V_55 )
V_170 &= ~ V_55 ;
else
V_170 |= V_55 ;
break;
case V_182 :
V_48 -> V_168 &= ~ V_55 ;
V_177 |= V_55 ;
V_170 |= V_55 ;
break;
case V_183 :
V_48 -> V_168 &= ~ V_55 ;
V_177 |= V_55 ;
V_170 &= ~ V_55 ;
break;
case V_184 :
V_48 -> V_168 &= ~ V_55 ;
V_177 &= ~ V_55 ;
V_170 |= V_55 ;
break;
case V_185 :
V_48 -> V_168 &= ~ V_55 ;
V_177 &= ~ V_55 ;
V_170 &= ~ V_55 ;
break;
default:
F_95 ( V_3 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
return - V_20 ;
}
F_43 ( V_177 , V_3 -> V_109 + V_181 ) ;
F_43 ( V_170 , V_3 -> V_109 + V_171 ) ;
F_95 ( V_3 ) ;
F_25 ( & V_48 -> V_69 , V_66 ) ;
return 0 ;
}
static void F_96 ( struct V_172 * V_173 )
{
struct V_174 * V_3 = F_92 ( V_173 ) ;
struct V_1 * V_48 = V_3 -> V_175 ;
V_48 -> V_186 = F_97 ( V_3 , V_187 ) ;
F_98 ( V_3 , V_3 -> V_188 , V_187 ) ;
}
static void F_99 ( struct V_172 * V_173 )
{
struct V_174 * V_3 = F_92 ( V_173 ) ;
struct V_1 * V_48 = V_3 -> V_175 ;
F_98 ( V_3 , V_48 -> V_186 , V_187 ) ;
}
static void F_100 ( struct V_172 * V_173 )
{
struct V_174 * V_3 = F_92 ( V_173 ) ;
T_2 V_52 ;
F_94 ( V_3 ) ;
V_52 = F_97 ( V_3 , V_187 ) ;
V_52 &= ~ V_173 -> V_55 ;
F_98 ( V_3 , V_52 , V_187 ) ;
F_95 ( V_3 ) ;
}
static void F_101 ( struct V_172 * V_173 )
{
struct V_174 * V_3 = F_92 ( V_173 ) ;
T_2 V_52 ;
F_94 ( V_3 ) ;
V_52 = F_97 ( V_3 , V_187 ) ;
V_52 |= V_173 -> V_55 ;
F_98 ( V_3 , V_52 , V_187 ) ;
F_95 ( V_3 ) ;
}
static int F_102 ( struct V_131 * V_132 ,
struct V_5 * V_6 )
{
struct V_88 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
unsigned int V_189 = V_190 | V_191 | V_192 ;
struct V_174 * V_3 ;
int V_54 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_193 ) {
F_103 ( & V_132 -> V_35 , L_31 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_160 = F_104 ( V_48 -> V_134 , 32 ,
& V_194 , NULL ) ;
if ( ! V_48 -> V_160 ) {
F_103 ( & V_132 -> V_35 , L_32 ,
V_48 -> V_7 ) ;
continue;
}
V_54 = F_105 ( V_48 -> V_160 , 32 , 1 ,
L_33 , V_180 ,
V_189 , 0 , V_195 ) ;
if ( V_54 ) {
F_12 ( & V_132 -> V_35 , L_34 ,
V_48 -> V_7 ) ;
F_106 ( V_48 -> V_160 ) ;
continue;
}
V_3 = F_107 ( V_48 -> V_160 , 0 ) ;
V_3 -> V_109 = V_48 -> V_109 ;
V_3 -> V_175 = V_48 ;
V_3 -> V_196 [ 0 ] . V_197 . V_55 = V_198 ;
V_3 -> V_196 [ 0 ] . V_197 . V_199 = V_200 ;
V_3 -> V_196 [ 0 ] . V_107 . V_201 = V_202 ;
V_3 -> V_196 [ 0 ] . V_107 . V_203 = V_204 ;
V_3 -> V_196 [ 0 ] . V_107 . V_205 = V_206 ;
V_3 -> V_196 [ 0 ] . V_107 . V_207 = F_101 ;
V_3 -> V_196 [ 0 ] . V_107 . V_208 = F_100 ;
V_3 -> V_196 [ 0 ] . V_107 . V_209 = V_210 ;
V_3 -> V_196 [ 0 ] . V_107 . V_211 = F_96 ;
V_3 -> V_196 [ 0 ] . V_107 . V_212 = F_99 ;
V_3 -> V_196 [ 0 ] . V_107 . V_213 = F_91 ;
V_3 -> V_214 = F_108 ( V_48 -> V_16 ) ;
F_109 ( V_48 -> V_162 , V_48 ) ;
F_110 ( V_48 -> V_162 , F_83 ) ;
}
return 0 ;
}
static int F_111 ( struct V_131 * V_132 ,
struct V_5 * V_6 )
{
struct V_88 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
struct V_2 * V_3 ;
int V_54 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_193 ) {
F_103 ( & V_132 -> V_35 , L_31 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_2 = V_215 ;
V_3 = & V_48 -> V_2 ;
V_3 -> V_113 = V_48 -> V_15 ;
V_3 -> V_155 = V_48 -> V_16 ;
V_3 -> V_35 = & V_132 -> V_35 ;
V_3 -> V_134 = V_48 -> V_134 ;
V_3 -> V_216 = V_48 -> V_7 ;
V_54 = F_112 ( V_3 ) ;
if ( V_54 ) {
F_12 ( & V_132 -> V_35 , L_35 ,
V_3 -> V_216 , V_54 ) ;
goto V_217;
}
}
F_102 ( V_132 , V_6 ) ;
return 0 ;
V_217:
for ( -- V_8 , -- V_48 ; V_8 >= 0 ; -- V_8 , -- V_48 ) {
if ( ! V_48 -> V_193 )
continue;
F_113 ( & V_48 -> V_2 ) ;
}
return V_54 ;
}
static int F_114 ( struct V_131 * V_132 ,
struct V_5 * V_6 )
{
struct V_88 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_193 )
continue;
F_113 ( & V_48 -> V_2 ) ;
}
return 0 ;
}
static int F_115 ( struct V_1 * V_48 ,
struct V_5 * V_6 )
{
struct V_218 V_219 ;
void T_5 * V_113 ;
if ( F_116 ( V_48 -> V_134 , 0 , & V_219 ) ) {
F_12 ( V_6 -> V_35 , L_36 ) ;
return - V_220 ;
}
V_48 -> V_109 = F_117 ( V_6 -> V_35 , & V_219 ) ;
if ( F_60 ( V_48 -> V_109 ) )
return F_61 ( V_48 -> V_109 ) ;
if ( F_118 ( V_48 -> V_134 ,
L_37 ) ) {
struct V_26 * V_221 ;
V_221 = F_119 ( V_48 -> V_134 -> V_33 ,
L_38 , 0 ) ;
if ( ! V_221 ) {
if ( F_116 ( V_48 -> V_134 , 1 , & V_219 ) ) {
F_12 ( V_6 -> V_35 , L_36 ) ;
return - V_220 ;
}
V_113 = F_117 ( V_6 -> V_35 , & V_219 ) ;
if ( F_60 ( V_113 ) )
return F_61 ( V_113 ) ;
V_222 . V_223 =
F_120 ( & V_219 ) - 4 ;
V_222 . V_7 =
L_39 ;
V_48 -> V_74 = F_121 ( V_6 -> V_35 ,
V_113 ,
& V_222 ) ;
}
}
V_48 -> V_162 = F_122 ( V_48 -> V_134 , 0 ) ;
V_48 -> V_224 = F_123 ( V_48 -> V_134 , 0 ) ;
if ( F_60 ( V_48 -> V_224 ) )
return F_61 ( V_48 -> V_224 ) ;
return F_124 ( V_48 -> V_224 ) ;
}
static struct V_88 * F_125 (
struct V_5 * V_173 ,
struct V_131 * V_132 )
{
const struct V_225 * V_226 ;
struct V_26 * V_221 = V_132 -> V_35 . V_134 ;
struct V_26 * V_27 ;
struct V_88 * V_13 ;
struct V_1 * V_48 ;
int V_227 , V_228 , V_8 , V_126 ;
V_226 = F_55 ( V_229 , V_221 ) ;
V_13 = (struct V_88 * ) V_226 -> V_39 ;
F_54 (node, np) {
if ( ! F_126 ( V_27 , L_40 , NULL ) )
continue;
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! strcmp ( V_48 -> V_7 , V_27 -> V_7 ) ) {
V_48 -> V_134 = V_27 ;
if ( ! F_115 ( V_48 , V_173 ) )
V_48 -> V_193 = true ;
break;
}
}
}
V_227 = V_13 -> V_230 ;
V_228 = V_13 -> V_231 ;
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
int V_232 = 0 ;
F_127 ( & V_48 -> V_69 ) ;
V_48 -> V_49 = V_173 ;
V_48 -> V_15 = V_13 -> V_16 ;
V_13 -> V_16 += V_48 -> V_16 ;
for ( V_126 = 0 ; V_126 < 4 ; V_126 ++ ) {
struct V_233 * V_234 = & V_48 -> V_57 [ V_126 ] ;
int V_235 ;
if ( V_232 >= V_48 -> V_16 )
break;
if ( V_234 -> V_65 >= 0 ) {
if ( V_234 -> type & V_61 )
V_228 = V_234 -> V_65 ;
else
V_227 = V_234 -> V_65 ;
} else {
V_234 -> V_65 = ( V_234 -> type & V_61 ) ?
V_228 : V_227 ;
}
F_18 ( V_173 -> V_35 , L_41 ,
V_8 , V_126 , V_234 -> V_65 ) ;
V_235 = ( V_234 -> type & V_64 ) ? 8 : 4 ;
if ( V_234 -> type & V_61 )
V_228 += V_235 ;
else
V_227 += V_235 ;
V_232 += 8 ;
}
}
return V_13 ;
}
static int T_6 F_128 ( struct V_133 * V_35 )
{
struct V_5 * V_6 = F_129 ( V_35 ) ;
int V_54 = F_130 ( V_6 -> V_152 ) ;
if ( V_54 )
return V_54 ;
if ( V_6 -> V_13 -> type == V_95 ) {
V_54 = F_21 ( V_6 -> V_63 , V_236 ,
& V_237 ) ;
if ( V_54 ) {
F_131 ( V_6 -> V_152 ) ;
return V_54 ;
}
}
return 0 ;
}
static int T_6 F_132 ( struct V_133 * V_35 )
{
struct V_5 * V_6 = F_129 ( V_35 ) ;
int V_54 = F_36 ( V_6 -> V_63 , V_236 ,
V_237 |
V_238 ) ;
if ( V_54 )
return V_54 ;
return F_131 ( V_6 -> V_152 ) ;
}
static int F_133 ( struct V_131 * V_132 )
{
struct V_5 * V_6 ;
struct V_133 * V_35 = & V_132 -> V_35 ;
struct V_88 * V_13 ;
struct V_26 * V_27 = V_132 -> V_35 . V_134 , * V_221 ;
struct V_218 * V_219 ;
void T_5 * V_113 ;
int V_54 ;
if ( ! V_35 -> V_134 ) {
F_12 ( V_35 , L_42 ) ;
return - V_239 ;
}
V_6 = F_13 ( V_35 , sizeof( struct V_5 ) , V_36 ) ;
if ( ! V_6 )
return - V_37 ;
V_6 -> V_35 = V_35 ;
V_13 = F_125 ( V_6 , V_132 ) ;
if ( ! V_13 ) {
F_12 ( V_35 , L_43 ) ;
return - V_20 ;
}
V_6 -> V_13 = V_13 ;
V_221 = F_119 ( V_27 , L_44 , 0 ) ;
if ( V_221 ) {
V_6 -> V_63 = F_134 ( V_221 ) ;
if ( F_60 ( V_6 -> V_63 ) )
return F_61 ( V_6 -> V_63 ) ;
} else {
V_219 = F_135 ( V_132 , V_240 , 0 ) ;
V_113 = F_117 ( & V_132 -> V_35 , V_219 ) ;
if ( F_60 ( V_113 ) )
return F_61 ( V_113 ) ;
V_222 . V_223 = F_120 ( V_219 ) - 4 ;
V_222 . V_7 = L_45 ;
V_6 -> V_63 = F_121 ( & V_132 -> V_35 , V_113 ,
& V_222 ) ;
V_6 -> V_241 = F_120 ( V_219 ) ;
if ( V_13 -> type == V_94 && V_6 -> V_241 < 0x200 ) {
V_219 = F_135 ( V_132 , V_240 , 1 ) ;
V_113 = F_117 ( & V_132 -> V_35 , V_219 ) ;
if ( F_60 ( V_113 ) )
return F_61 ( V_113 ) ;
V_222 . V_223 =
F_120 ( V_219 ) - 4 ;
V_222 . V_7 = L_46 ;
V_6 -> V_74 = F_121 ( & V_132 -> V_35 ,
V_113 ,
& V_222 ) ;
}
}
V_221 = F_119 ( V_27 , L_38 , 0 ) ;
if ( V_221 ) {
V_6 -> V_62 = F_134 ( V_221 ) ;
if ( F_60 ( V_6 -> V_62 ) )
return F_61 ( V_6 -> V_62 ) ;
}
V_54 = F_111 ( V_132 , V_6 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_67 ( V_132 , V_6 ) ;
if ( V_54 ) {
F_114 ( V_132 , V_6 ) ;
return V_54 ;
}
F_136 ( V_132 , V_6 ) ;
return 0 ;
}
static int T_7 F_137 ( void )
{
return F_138 ( & V_242 ) ;
}
