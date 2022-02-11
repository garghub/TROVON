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
unsigned int V_50 ;
int V_51 , V_52 ;
T_1 V_53 ;
if ( V_48 -> V_54 == V_55 && V_11 < 16 )
return V_56 ;
V_51 = V_6 -> V_13 -> V_57 ;
V_51 += V_48 -> V_19 * 0x10 ;
V_51 += ( V_11 / 8 ) * 4 ;
V_53 = ( V_11 % 8 ) * 2 ;
V_52 = F_21 ( V_6 -> V_58 , V_51 , & V_50 ) ;
if ( V_52 )
return V_52 ;
return ( ( V_50 >> V_53 ) & 3 ) ;
}
static int F_22 ( struct V_1 * V_48 , int V_11 , int V_40 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
int V_51 , V_52 ;
unsigned long V_59 ;
T_1 V_53 ;
T_2 V_39 ;
if ( V_48 -> V_54 == V_55 && V_11 < 16 ) {
if ( V_40 != V_56 ) {
F_12 ( V_6 -> V_35 ,
L_3 , V_11 ) ;
return - V_60 ;
} else {
return 0 ;
}
}
F_18 ( V_6 -> V_35 , L_4 ,
V_48 -> V_19 , V_11 , V_40 ) ;
V_51 = V_6 -> V_13 -> V_57 ;
V_51 += V_48 -> V_19 * 0x10 ;
V_51 += ( V_11 / 8 ) * 4 ;
V_53 = ( V_11 % 8 ) * 2 ;
F_23 ( & V_48 -> V_61 , V_59 ) ;
V_39 = ( 3 << ( V_53 + 16 ) ) ;
V_39 |= ( V_40 & 3 ) << V_53 ;
V_52 = F_24 ( V_6 -> V_58 , V_51 , V_39 ) ;
F_25 ( & V_48 -> V_61 , V_59 ) ;
return V_52 ;
}
static void F_26 ( struct V_1 * V_48 ,
int V_62 , struct V_63 * * V_63 ,
int * V_51 , T_1 * V_53 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
* V_63 = V_6 -> V_58 ;
* V_51 = V_64 ;
* V_51 += V_48 -> V_19 * V_65 ;
* V_51 += ( V_62 / V_66 ) * 4 ;
* V_53 = V_62 % V_66 ;
}
static void F_27 ( struct V_1 * V_48 ,
int V_62 , struct V_63 * * V_63 ,
int * V_51 , T_1 * V_53 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
if ( V_48 -> V_54 == V_55 && V_62 < 12 ) {
* V_63 = V_6 -> V_67 ? V_6 -> V_67
: V_48 -> V_68 ;
* V_51 = V_6 -> V_67 ? V_69 : 0 ;
* V_51 += ( ( V_62 / V_70 ) * 4 ) ;
* V_53 = V_62 % V_70 ;
* V_53 *= V_71 ;
} else {
* V_63 = V_6 -> V_68 ? V_6 -> V_68
: V_6 -> V_58 ;
* V_51 = V_6 -> V_68 ? 0 : V_72 ;
* V_51 -= 4 ;
* V_51 += V_48 -> V_19 * V_73 ;
* V_51 += ( ( V_62 / V_70 ) * 4 ) ;
* V_53 = 7 - ( V_62 % V_70 ) ;
* V_53 *= V_71 ;
}
}
static int F_28 ( struct V_1 * V_48 , int V_62 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_74 * V_13 = V_6 -> V_13 ;
struct V_63 * V_63 ;
int V_51 , V_52 ;
T_1 V_53 ;
T_2 V_39 ;
if ( V_13 -> type == V_75 )
return V_76 ;
V_13 -> V_77 ( V_48 , V_62 , & V_63 , & V_51 , & V_53 ) ;
V_52 = F_21 ( V_63 , V_51 , & V_39 ) ;
if ( V_52 )
return V_52 ;
switch ( V_13 -> type ) {
case V_78 :
return ! ( V_39 & F_29 ( V_53 ) )
? V_79
: V_76 ;
case V_80 :
V_39 >>= V_53 ;
V_39 &= ( 1 << V_71 ) - 1 ;
switch ( V_39 ) {
case 0 :
return V_76 ;
case 1 :
return V_81 ;
case 2 :
return V_82 ;
case 3 :
return V_83 ;
}
F_12 ( V_6 -> V_35 , L_5 ) ;
return - V_84 ;
default:
F_12 ( V_6 -> V_35 , L_6 ) ;
return - V_20 ;
} ;
}
static int F_30 ( struct V_1 * V_48 ,
int V_62 , int V_85 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_74 * V_13 = V_6 -> V_13 ;
struct V_63 * V_63 ;
int V_51 , V_52 ;
unsigned long V_59 ;
T_1 V_53 ;
T_2 V_39 ;
F_18 ( V_6 -> V_35 , L_7 ,
V_48 -> V_19 , V_62 , V_85 ) ;
if ( V_13 -> type == V_75 )
return V_85 ? - V_20 : 0 ;
V_13 -> V_77 ( V_48 , V_62 , & V_63 , & V_51 , & V_53 ) ;
switch ( V_13 -> type ) {
case V_78 :
F_23 ( & V_48 -> V_61 , V_59 ) ;
V_39 = F_29 ( V_53 + 16 ) ;
if ( V_85 == V_76 )
V_39 |= F_29 ( V_53 ) ;
V_52 = F_24 ( V_63 , V_51 , V_39 ) ;
F_25 ( & V_48 -> V_61 , V_59 ) ;
break;
case V_80 :
F_23 ( & V_48 -> V_61 , V_59 ) ;
V_39 = ( ( 1 << V_71 ) - 1 ) << ( V_53 + 16 ) ;
switch ( V_85 ) {
case V_76 :
break;
case V_81 :
V_39 |= ( 1 << V_53 ) ;
break;
case V_82 :
V_39 |= ( 2 << V_53 ) ;
break;
case V_83 :
V_39 |= ( 3 << V_53 ) ;
break;
default:
F_25 ( & V_48 -> V_61 , V_59 ) ;
F_12 ( V_6 -> V_35 , L_8 ,
V_85 ) ;
return - V_20 ;
}
V_52 = F_24 ( V_63 , V_51 , V_39 ) ;
F_25 ( & V_48 -> V_61 , V_59 ) ;
break;
default:
F_12 ( V_6 -> V_35 , L_6 ) ;
return - V_20 ;
}
return V_52 ;
}
static int F_31 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_86 ;
}
static const char * F_32 ( struct V_21 * V_22 ,
unsigned V_23 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_87 [ V_23 ] . V_7 ;
}
static int F_33 ( struct V_21 * V_22 ,
unsigned V_23 , const char * const * * V_10 ,
unsigned * const V_88 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
* V_10 = V_6 -> V_87 [ V_23 ] . V_10 ;
* V_88 = V_6 -> V_87 [ V_23 ] . V_9 ;
return 0 ;
}
static int F_34 ( struct V_21 * V_22 , unsigned V_23 ,
unsigned V_42 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
const unsigned int * V_24 = V_6 -> V_10 [ V_42 ] . V_24 ;
const struct V_89 * V_39 = V_6 -> V_10 [ V_42 ] . V_39 ;
struct V_1 * V_48 ;
int V_90 , V_52 = 0 ;
F_18 ( V_6 -> V_35 , L_9 ,
V_6 -> V_87 [ V_23 ] . V_7 , V_6 -> V_10 [ V_42 ] . V_7 ) ;
for ( V_90 = 0 ; V_90 < V_6 -> V_10 [ V_42 ] . V_25 ; V_90 ++ ) {
V_48 = F_4 ( V_6 , V_24 [ V_90 ] ) ;
V_52 = F_22 ( V_48 , V_24 [ V_90 ] - V_48 -> V_15 ,
V_39 [ V_90 ] . V_91 ) ;
if ( V_52 )
break;
}
if ( V_52 ) {
for ( V_90 -- ; V_90 >= 0 ; V_90 -- )
F_22 ( V_48 , V_24 [ V_90 ] - V_48 -> V_15 , 0 ) ;
return V_52 ;
}
return 0 ;
}
static void F_35 ( struct V_21 * V_22 ,
unsigned V_23 , unsigned V_42 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
const unsigned int * V_24 = V_6 -> V_10 [ V_42 ] . V_24 ;
struct V_1 * V_48 ;
int V_90 ;
F_18 ( V_6 -> V_35 , L_10 ,
V_6 -> V_87 [ V_23 ] . V_7 , V_6 -> V_10 [ V_42 ] . V_7 ) ;
for ( V_90 = 0 ; V_90 < V_6 -> V_10 [ V_42 ] . V_25 ; V_90 ++ ) {
V_48 = F_4 ( V_6 , V_24 [ V_90 ] ) ;
F_22 ( V_48 , V_24 [ V_90 ] - V_48 -> V_15 , 0 ) ;
}
}
static int F_36 ( struct V_21 * V_22 ,
struct V_92 * V_93 ,
unsigned V_94 , bool V_95 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 ;
struct V_2 * V_96 ;
int V_11 , V_52 ;
T_2 V_39 ;
V_96 = V_93 -> V_3 ;
V_48 = F_1 ( V_96 ) ;
V_11 = V_94 - V_96 -> V_97 ;
F_18 ( V_6 -> V_35 , L_11 ,
V_94 , V_93 -> V_7 , V_11 , V_95 ? L_12 : L_13 ) ;
V_52 = F_22 ( V_48 , V_11 , V_56 ) ;
if ( V_52 < 0 )
return V_52 ;
V_39 = F_37 ( V_48 -> V_98 + V_99 ) ;
if ( ! V_95 )
V_39 |= F_29 ( V_11 ) ;
else
V_39 &= ~ F_29 ( V_11 ) ;
F_38 ( V_39 , V_48 -> V_98 + V_99 ) ;
return 0 ;
}
static bool F_39 ( struct V_74 * V_13 ,
enum V_100 V_85 )
{
switch ( V_13 -> type ) {
case V_78 :
return ( V_85 == V_79 ||
V_85 == V_76 ) ;
case V_75 :
return V_85 ? false : true ;
case V_80 :
return ( V_85 != V_79 ) ;
}
return false ;
}
static int F_40 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_44 , unsigned V_46 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_100 V_101 ;
T_3 V_102 ;
int V_8 ;
int V_103 ;
for ( V_8 = 0 ; V_8 < V_46 ; V_8 ++ ) {
V_101 = F_41 ( V_44 [ V_8 ] ) ;
V_102 = F_42 ( V_44 [ V_8 ] ) ;
switch ( V_101 ) {
case V_76 :
V_103 = F_30 ( V_48 , V_11 - V_48 -> V_15 ,
V_101 ) ;
if ( V_103 )
return V_103 ;
break;
case V_81 :
case V_82 :
case V_79 :
case V_83 :
if ( ! F_39 ( V_6 -> V_13 , V_101 ) )
return - V_60 ;
if ( ! V_102 )
return - V_20 ;
V_103 = F_30 ( V_48 , V_11 - V_48 -> V_15 ,
V_101 ) ;
if ( V_103 )
return V_103 ;
break;
case V_104 :
V_103 = F_43 ( & V_48 -> V_2 ,
V_11 - V_48 -> V_15 ,
V_102 ) ;
if ( V_103 )
return V_103 ;
break;
default:
return - V_60 ;
break;
}
}
return 0 ;
}
static int F_44 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_105 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_100 V_101 = F_41 ( * V_105 ) ;
T_3 V_102 ;
int V_103 ;
switch ( V_101 ) {
case V_76 :
if ( F_28 ( V_48 , V_11 - V_48 -> V_15 ) != V_101 )
return - V_20 ;
V_102 = 0 ;
break;
case V_81 :
case V_82 :
case V_79 :
case V_83 :
if ( ! F_39 ( V_6 -> V_13 , V_101 ) )
return - V_60 ;
if ( F_28 ( V_48 , V_11 - V_48 -> V_15 ) != V_101 )
return - V_20 ;
V_102 = 1 ;
break;
case V_104 :
V_103 = F_20 ( V_48 , V_11 - V_48 -> V_15 ) ;
if ( V_103 != V_56 )
return - V_20 ;
V_103 = F_45 ( & V_48 -> V_2 , V_11 - V_48 -> V_15 ) ;
if ( V_103 < 0 )
return V_103 ;
V_102 = V_103 ? 1 : 0 ;
break;
default:
return - V_60 ;
break;
}
* V_105 = F_46 ( V_101 , V_102 ) ;
return 0 ;
}
static void F_47 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
struct V_26 * V_106 ;
F_48 (np, child) {
if ( F_49 ( V_107 , V_106 ) )
continue;
V_6 -> V_86 ++ ;
V_6 -> V_9 += F_50 ( V_106 ) ;
}
}
static int F_51 ( struct V_26 * V_27 ,
struct V_4 * V_31 ,
struct V_5 * V_6 ,
T_2 V_108 )
{
struct V_1 * V_48 ;
int V_109 ;
const T_4 * V_110 ;
int V_17 ;
int V_8 , V_111 ;
int V_52 ;
F_18 ( V_6 -> V_35 , L_14 , V_108 , V_27 -> V_7 ) ;
V_31 -> V_7 = V_27 -> V_7 ;
V_110 = F_52 ( V_27 , L_15 , & V_109 ) ;
V_109 /= sizeof( * V_110 ) ;
if ( ! V_109 || V_109 % 4 ) {
F_12 ( V_6 -> V_35 , L_16 ) ;
return - V_20 ;
}
V_31 -> V_25 = V_109 / 4 ;
V_31 -> V_24 = F_13 ( V_6 -> V_35 , V_31 -> V_25 * sizeof( unsigned int ) ,
V_36 ) ;
V_31 -> V_39 = F_13 ( V_6 -> V_35 , V_31 -> V_25 *
sizeof( struct V_89 ) ,
V_36 ) ;
if ( ! V_31 -> V_24 || ! V_31 -> V_39 )
return - V_37 ;
for ( V_8 = 0 , V_111 = 0 ; V_8 < V_109 ; V_8 += 4 , V_111 ++ ) {
const T_4 * V_112 ;
struct V_26 * V_113 ;
V_17 = F_53 ( * V_110 ++ ) ;
V_48 = F_5 ( V_6 , V_17 ) ;
if ( F_54 ( V_48 ) )
return F_55 ( V_48 ) ;
V_31 -> V_24 [ V_111 ] = V_48 -> V_15 + F_53 ( * V_110 ++ ) ;
V_31 -> V_39 [ V_111 ] . V_91 = F_53 ( * V_110 ++ ) ;
V_112 = V_110 ++ ;
if ( ! V_112 )
return - V_20 ;
V_113 = F_56 ( F_57 ( V_112 ) ) ;
V_52 = F_58 ( V_113 ,
& V_31 -> V_39 [ V_111 ] . V_44 , & V_31 -> V_39 [ V_111 ] . V_47 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static int F_59 ( struct V_26 * V_27 ,
struct V_5 * V_6 ,
T_2 V_108 )
{
struct V_26 * V_106 ;
struct V_114 * V_91 ;
struct V_4 * V_31 ;
int V_52 ;
static T_2 V_115 ;
T_2 V_8 = 0 ;
F_18 ( V_6 -> V_35 , L_17 , V_108 , V_27 -> V_7 ) ;
V_91 = & V_6 -> V_87 [ V_108 ] ;
V_91 -> V_7 = V_27 -> V_7 ;
V_91 -> V_9 = F_50 ( V_27 ) ;
if ( V_91 -> V_9 <= 0 )
return 0 ;
V_91 -> V_10 = F_13 ( V_6 -> V_35 ,
V_91 -> V_9 * sizeof( char * ) , V_36 ) ;
if ( ! V_91 -> V_10 )
return - V_37 ;
F_48 (np, child) {
V_91 -> V_10 [ V_8 ] = V_106 -> V_7 ;
V_31 = & V_6 -> V_10 [ V_115 ++ ] ;
V_52 = F_51 ( V_106 , V_31 , V_6 , V_8 ++ ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static int F_60 ( struct V_116 * V_117 ,
struct V_5 * V_6 )
{
struct V_118 * V_35 = & V_117 -> V_35 ;
struct V_26 * V_27 = V_35 -> V_119 ;
struct V_26 * V_106 ;
int V_52 ;
int V_8 ;
F_47 ( V_6 , V_27 ) ;
F_18 ( & V_117 -> V_35 , L_18 , V_6 -> V_86 ) ;
F_18 ( & V_117 -> V_35 , L_19 , V_6 -> V_9 ) ;
V_6 -> V_87 = F_13 ( V_35 , V_6 -> V_86 *
sizeof( struct V_114 ) ,
V_36 ) ;
if ( ! V_6 -> V_87 ) {
F_12 ( V_35 , L_20 ) ;
return - V_20 ;
}
V_6 -> V_10 = F_13 ( V_35 , V_6 -> V_9 *
sizeof( struct V_4 ) ,
V_36 ) ;
if ( ! V_6 -> V_10 ) {
F_12 ( V_35 , L_21 ) ;
return - V_20 ;
}
V_8 = 0 ;
F_48 (np, child) {
if ( F_49 ( V_107 , V_106 ) )
continue;
V_52 = F_59 ( V_106 , V_6 , V_8 ++ ) ;
if ( V_52 ) {
F_12 ( & V_117 -> V_35 , L_22 ) ;
return V_52 ;
}
}
return 0 ;
}
static int F_61 ( struct V_116 * V_117 ,
struct V_5 * V_6 )
{
struct V_120 * V_121 = & V_6 -> V_122 ;
struct V_123 * V_124 , * V_125 ;
struct V_1 * V_126 ;
int V_11 , V_48 , V_52 ;
int V_127 ;
V_121 -> V_7 = L_23 ;
V_121 -> V_128 = V_129 ;
V_121 -> V_130 = & V_131 ;
V_121 -> V_132 = & V_133 ;
V_121 -> V_134 = & V_135 ;
V_124 = F_13 ( & V_117 -> V_35 , sizeof( * V_124 ) *
V_6 -> V_13 -> V_16 , V_36 ) ;
if ( ! V_124 ) {
F_12 ( & V_117 -> V_35 , L_24 ) ;
return - V_37 ;
}
V_121 -> V_24 = V_124 ;
V_121 -> V_25 = V_6 -> V_13 -> V_16 ;
V_125 = V_124 ;
for ( V_48 = 0 , V_127 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; V_48 ++ ) {
V_126 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
for ( V_11 = 0 ; V_11 < V_126 -> V_16 ; V_11 ++ , V_127 ++ ) {
V_125 -> V_136 = V_127 ;
V_125 -> V_7 = F_62 ( V_36 , L_25 ,
V_126 -> V_7 , V_11 ) ;
V_125 ++ ;
}
}
V_6 -> V_137 = F_63 ( V_121 , & V_117 -> V_35 , V_6 ) ;
if ( ! V_6 -> V_137 ) {
F_12 ( & V_117 -> V_35 , L_26 ) ;
return - V_20 ;
}
for ( V_48 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; ++ V_48 ) {
V_126 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
V_126 -> V_138 . V_7 = V_126 -> V_7 ;
V_126 -> V_138 . V_139 = V_48 ;
V_126 -> V_138 . V_15 = V_126 -> V_15 ;
V_126 -> V_138 . V_97 = V_126 -> V_2 . V_97 ;
V_126 -> V_138 . V_25 = V_126 -> V_2 . V_140 ;
V_126 -> V_138 . V_3 = & V_126 -> V_2 ;
F_64 ( V_6 -> V_137 , & V_126 -> V_138 ) ;
}
V_52 = F_60 ( V_117 , V_6 ) ;
if ( V_52 ) {
F_65 ( V_6 -> V_137 ) ;
return V_52 ;
}
return 0 ;
}
static int F_66 ( struct V_2 * V_96 , unsigned V_94 )
{
return F_67 ( V_96 -> V_97 + V_94 ) ;
}
static void F_68 ( struct V_2 * V_96 , unsigned V_94 )
{
F_69 ( V_96 -> V_97 + V_94 ) ;
}
static void F_70 ( struct V_2 * V_3 , unsigned V_94 , int V_141 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
void T_5 * V_51 = V_48 -> V_98 + V_142 ;
unsigned long V_59 ;
T_2 V_39 ;
F_23 ( & V_48 -> V_61 , V_59 ) ;
V_39 = F_71 ( V_51 ) ;
V_39 &= ~ F_29 ( V_94 ) ;
if ( V_141 )
V_39 |= F_29 ( V_94 ) ;
F_72 ( V_39 , V_51 ) ;
F_25 ( & V_48 -> V_61 , V_59 ) ;
}
static int F_45 ( struct V_2 * V_3 , unsigned V_94 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
T_2 V_39 ;
V_39 = F_71 ( V_48 -> V_98 + V_143 ) ;
V_39 >>= V_94 ;
V_39 &= 1 ;
return V_39 ;
}
static int F_73 ( struct V_2 * V_3 , unsigned V_94 )
{
return F_74 ( V_3 -> V_97 + V_94 ) ;
}
static int F_43 ( struct V_2 * V_3 ,
unsigned V_94 , int V_141 )
{
F_70 ( V_3 , V_94 , V_141 ) ;
return F_75 ( V_3 -> V_97 + V_94 ) ;
}
static int F_76 ( struct V_2 * V_3 , unsigned V_94 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
unsigned int V_144 ;
if ( ! V_48 -> V_145 )
return - V_146 ;
V_144 = F_77 ( V_48 -> V_145 , V_94 ) ;
return ( V_144 ) ? : - V_146 ;
}
static void F_78 ( unsigned int V_147 , struct V_148 * V_149 )
{
struct V_150 * V_96 = F_79 ( V_147 ) ;
struct V_1 * V_48 = F_80 ( V_147 ) ;
T_2 V_151 = 0 , V_39 = 0 ;
T_2 V_152 ;
bool V_153 = false ;
F_18 ( V_48 -> V_49 -> V_35 , L_27 , V_48 -> V_7 ) ;
F_81 ( V_96 , V_149 ) ;
V_152 = F_37 ( V_48 -> V_98 + V_154 ) ;
if ( V_48 -> V_155 ) {
V_151 = F_37 ( V_48 -> V_98 +
V_156 ) ;
V_39 = F_37 ( V_48 -> V_98 + V_143 ) ;
}
while ( V_152 ) {
unsigned int V_144 ;
V_147 = F_82 ( V_152 ) ;
V_152 &= ~ F_29 ( V_147 ) ;
V_144 = F_83 ( V_48 -> V_145 , V_147 ) ;
if ( ! V_144 ) {
F_12 ( V_48 -> V_49 -> V_35 , L_28 , V_147 ) ;
continue;
}
F_18 ( V_48 -> V_49 -> V_35 , L_29 , V_147 ) ;
if ( V_48 -> V_155 & F_29 ( V_147 ) ) {
if ( V_39 & F_29 ( V_147 ) )
V_151 &= ~ F_29 ( V_147 ) ;
else
V_151 |= F_29 ( V_147 ) ;
V_153 = true ;
}
F_84 ( V_144 ) ;
}
if ( V_48 -> V_155 && V_153 ) {
V_39 = F_37 ( V_48 -> V_98 + V_157 ) ;
F_38 ( 0 , V_48 -> V_98 + V_157 ) ;
F_72 ( V_151 , V_48 -> V_98 + V_156 ) ;
F_72 ( V_39 , V_48 -> V_98 + V_157 ) ;
}
F_85 ( V_96 , V_149 ) ;
}
static int F_86 ( struct V_158 * V_159 , unsigned int type )
{
struct V_160 * V_3 = F_87 ( V_159 ) ;
struct V_1 * V_48 = V_3 -> V_161 ;
T_2 V_162 = F_29 ( V_159 -> V_163 ) ;
T_2 V_151 ;
T_2 V_164 ;
T_2 V_39 ;
int V_52 ;
V_52 = F_22 ( V_48 , V_159 -> V_163 , V_56 ) ;
if ( V_52 < 0 )
return V_52 ;
V_39 = F_37 ( V_48 -> V_98 + V_99 ) ;
V_39 &= ~ V_162 ;
F_38 ( V_39 , V_48 -> V_98 + V_99 ) ;
if ( type & V_165 )
F_88 ( V_159 -> V_147 , V_166 ) ;
else
F_88 ( V_159 -> V_147 , V_167 ) ;
F_89 ( V_3 ) ;
V_164 = F_37 ( V_3 -> V_98 + V_168 ) ;
V_151 = F_37 ( V_3 -> V_98 + V_156 ) ;
switch ( type ) {
case V_165 :
V_48 -> V_155 |= V_162 ;
V_164 |= V_162 ;
V_39 = F_71 ( V_48 -> V_98 + V_143 ) ;
if ( V_39 & V_162 )
V_151 &= ~ V_162 ;
else
V_151 |= V_162 ;
break;
case V_169 :
V_48 -> V_155 &= ~ V_162 ;
V_164 |= V_162 ;
V_151 |= V_162 ;
break;
case V_170 :
V_48 -> V_155 &= ~ V_162 ;
V_164 |= V_162 ;
V_151 &= ~ V_162 ;
break;
case V_171 :
V_48 -> V_155 &= ~ V_162 ;
V_164 &= ~ V_162 ;
V_151 |= V_162 ;
break;
case V_172 :
V_48 -> V_155 &= ~ V_162 ;
V_164 &= ~ V_162 ;
V_151 &= ~ V_162 ;
break;
default:
F_90 ( V_3 ) ;
return - V_20 ;
}
F_38 ( V_164 , V_3 -> V_98 + V_168 ) ;
F_38 ( V_151 , V_3 -> V_98 + V_156 ) ;
F_90 ( V_3 ) ;
return 0 ;
}
static int F_91 ( struct V_116 * V_117 ,
struct V_5 * V_6 )
{
struct V_74 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
unsigned int V_173 = V_174 | V_175 | V_176 ;
struct V_160 * V_3 ;
int V_52 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_177 ) {
F_92 ( & V_117 -> V_35 , L_30 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_145 = F_93 ( V_48 -> V_119 , 32 ,
& V_178 , NULL ) ;
if ( ! V_48 -> V_145 ) {
F_92 ( & V_117 -> V_35 , L_31 ,
V_48 -> V_7 ) ;
continue;
}
V_52 = F_94 ( V_48 -> V_145 , 32 , 1 ,
L_32 , V_167 ,
V_173 , 0 , V_179 ) ;
if ( V_52 ) {
F_12 ( & V_117 -> V_35 , L_33 ,
V_48 -> V_7 ) ;
F_95 ( V_48 -> V_145 ) ;
continue;
}
V_3 = F_96 ( V_48 -> V_145 , 0 ) ;
V_3 -> V_98 = V_48 -> V_98 ;
V_3 -> V_161 = V_48 ;
V_3 -> V_180 [ 0 ] . V_181 . V_162 = V_157 ;
V_3 -> V_180 [ 0 ] . V_181 . V_182 = V_183 ;
V_3 -> V_180 [ 0 ] . V_96 . V_184 = V_185 ;
V_3 -> V_180 [ 0 ] . V_96 . V_186 = V_187 ;
V_3 -> V_180 [ 0 ] . V_96 . V_188 = V_189 ;
V_3 -> V_180 [ 0 ] . V_96 . V_190 = V_191 ;
V_3 -> V_180 [ 0 ] . V_96 . V_192 = F_86 ;
F_97 ( V_48 -> V_147 , V_48 ) ;
F_98 ( V_48 -> V_147 , F_78 ) ;
}
return 0 ;
}
static int F_99 ( struct V_116 * V_117 ,
struct V_5 * V_6 )
{
struct V_74 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
struct V_2 * V_3 ;
int V_52 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_177 ) {
F_92 ( & V_117 -> V_35 , L_30 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_2 = V_193 ;
V_3 = & V_48 -> V_2 ;
V_3 -> V_97 = V_48 -> V_15 ;
V_3 -> V_140 = V_48 -> V_16 ;
V_3 -> V_35 = & V_117 -> V_35 ;
V_3 -> V_119 = V_48 -> V_119 ;
V_3 -> V_194 = V_48 -> V_7 ;
V_52 = F_100 ( V_3 ) ;
if ( V_52 ) {
F_12 ( & V_117 -> V_35 , L_34 ,
V_3 -> V_194 , V_52 ) ;
goto V_195;
}
}
F_91 ( V_117 , V_6 ) ;
return 0 ;
V_195:
for ( -- V_8 , -- V_48 ; V_8 >= 0 ; -- V_8 , -- V_48 ) {
if ( ! V_48 -> V_177 )
continue;
if ( F_101 ( & V_48 -> V_2 ) )
F_12 ( & V_117 -> V_35 , L_35 ,
V_48 -> V_2 . V_194 ) ;
}
return V_52 ;
}
static int F_102 ( struct V_116 * V_117 ,
struct V_5 * V_6 )
{
struct V_74 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
int V_52 = 0 ;
int V_8 ;
for ( V_8 = 0 ; ! V_52 && V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_177 )
continue;
V_52 = F_101 ( & V_48 -> V_2 ) ;
}
if ( V_52 )
F_12 ( & V_117 -> V_35 , L_36 ) ;
return V_52 ;
}
static int F_103 ( struct V_1 * V_48 ,
struct V_5 * V_6 )
{
struct V_196 V_197 ;
void T_5 * V_97 ;
if ( F_104 ( V_48 -> V_119 , 0 , & V_197 ) ) {
F_12 ( V_6 -> V_35 , L_37 ) ;
return - V_198 ;
}
V_48 -> V_98 = F_105 ( V_6 -> V_35 , & V_197 ) ;
if ( F_54 ( V_48 -> V_98 ) )
return F_55 ( V_48 -> V_98 ) ;
if ( F_106 ( V_48 -> V_119 ,
L_38 ) ) {
struct V_26 * V_199 ;
V_48 -> V_54 = V_55 ;
V_199 = F_107 ( V_48 -> V_119 -> V_33 ,
L_39 , 0 ) ;
if ( ! V_199 ) {
if ( F_104 ( V_48 -> V_119 , 1 , & V_197 ) ) {
F_12 ( V_6 -> V_35 , L_37 ) ;
return - V_198 ;
}
V_97 = F_105 ( V_6 -> V_35 , & V_197 ) ;
if ( F_54 ( V_97 ) )
return F_55 ( V_97 ) ;
V_200 . V_201 =
F_108 ( & V_197 ) - 4 ;
V_200 . V_7 =
L_40 ;
V_48 -> V_68 = F_109 ( V_6 -> V_35 ,
V_97 ,
& V_200 ) ;
}
} else {
V_48 -> V_54 = V_202 ;
}
V_48 -> V_147 = F_110 ( V_48 -> V_119 , 0 ) ;
V_48 -> V_203 = F_111 ( V_48 -> V_119 , 0 ) ;
if ( F_54 ( V_48 -> V_203 ) )
return F_55 ( V_48 -> V_203 ) ;
return F_112 ( V_48 -> V_203 ) ;
}
static struct V_74 * F_113 (
struct V_5 * V_159 ,
struct V_116 * V_117 )
{
const struct V_204 * V_205 ;
struct V_26 * V_199 = V_117 -> V_35 . V_119 ;
struct V_26 * V_27 ;
struct V_74 * V_13 ;
struct V_1 * V_48 ;
int V_8 ;
V_205 = F_49 ( V_206 , V_199 ) ;
V_13 = (struct V_74 * ) V_205 -> V_39 ;
F_48 (node, np) {
if ( ! F_114 ( V_27 , L_41 , NULL ) )
continue;
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! strcmp ( V_48 -> V_7 , V_27 -> V_7 ) ) {
V_48 -> V_119 = V_27 ;
if ( ! F_103 ( V_48 , V_159 ) )
V_48 -> V_177 = true ;
break;
}
}
}
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
F_115 ( & V_48 -> V_61 ) ;
V_48 -> V_49 = V_159 ;
V_48 -> V_15 = V_13 -> V_16 ;
V_13 -> V_16 += V_48 -> V_16 ;
}
return V_13 ;
}
static int F_116 ( struct V_116 * V_117 )
{
struct V_5 * V_6 ;
struct V_118 * V_35 = & V_117 -> V_35 ;
struct V_74 * V_13 ;
struct V_26 * V_27 = V_117 -> V_35 . V_119 , * V_199 ;
struct V_196 * V_197 ;
void T_5 * V_97 ;
int V_52 ;
if ( ! V_35 -> V_119 ) {
F_12 ( V_35 , L_42 ) ;
return - V_207 ;
}
V_6 = F_13 ( V_35 , sizeof( struct V_5 ) , V_36 ) ;
if ( ! V_6 )
return - V_37 ;
V_6 -> V_35 = V_35 ;
V_13 = F_113 ( V_6 , V_117 ) ;
if ( ! V_13 ) {
F_12 ( V_35 , L_43 ) ;
return - V_20 ;
}
V_6 -> V_13 = V_13 ;
V_199 = F_107 ( V_27 , L_44 , 0 ) ;
if ( V_199 ) {
V_6 -> V_58 = F_117 ( V_199 ) ;
if ( F_54 ( V_6 -> V_58 ) )
return F_55 ( V_6 -> V_58 ) ;
} else {
V_197 = F_118 ( V_117 , V_208 , 0 ) ;
V_97 = F_105 ( & V_117 -> V_35 , V_197 ) ;
if ( F_54 ( V_97 ) )
return F_55 ( V_97 ) ;
V_200 . V_201 = F_108 ( V_197 ) - 4 ;
V_200 . V_7 = L_45 ;
V_6 -> V_58 = F_109 ( & V_117 -> V_35 , V_97 ,
& V_200 ) ;
V_6 -> V_209 = F_108 ( V_197 ) ;
if ( V_13 -> type == V_80 && V_6 -> V_209 < 0x200 ) {
V_197 = F_118 ( V_117 , V_208 , 1 ) ;
V_97 = F_105 ( & V_117 -> V_35 , V_197 ) ;
if ( F_54 ( V_97 ) )
return F_55 ( V_97 ) ;
V_200 . V_201 =
F_108 ( V_197 ) - 4 ;
V_200 . V_7 = L_46 ;
V_6 -> V_68 = F_109 ( & V_117 -> V_35 ,
V_97 ,
& V_200 ) ;
}
}
V_199 = F_107 ( V_27 , L_39 , 0 ) ;
if ( V_199 ) {
V_6 -> V_67 = F_117 ( V_199 ) ;
if ( F_54 ( V_6 -> V_67 ) )
return F_55 ( V_6 -> V_67 ) ;
}
V_52 = F_99 ( V_117 , V_6 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_61 ( V_117 , V_6 ) ;
if ( V_52 ) {
F_102 ( V_117 , V_6 ) ;
return V_52 ;
}
F_119 ( V_117 , V_6 ) ;
return 0 ;
}
static int T_6 F_120 ( void )
{
return F_121 ( & V_210 ) ;
}
