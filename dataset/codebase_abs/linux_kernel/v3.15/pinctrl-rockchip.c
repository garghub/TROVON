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
static int F_20 ( struct V_1 * V_48 , int V_11 , int V_40 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
void T_1 * V_50 = V_6 -> V_51 + V_6 -> V_13 -> V_52 ;
unsigned long V_53 ;
T_2 V_54 ;
T_3 V_39 ;
if ( V_48 -> V_55 == V_56 && V_11 < 16 ) {
if ( V_40 != V_57 ) {
F_12 ( V_6 -> V_35 ,
L_3 , V_11 ) ;
return - V_58 ;
} else {
return 0 ;
}
}
F_18 ( V_6 -> V_35 , L_4 ,
V_48 -> V_19 , V_11 , V_40 ) ;
V_50 += V_48 -> V_19 * 0x10 ;
V_50 += ( V_11 / 8 ) * 4 ;
V_54 = ( V_11 % 8 ) * 2 ;
F_21 ( & V_48 -> V_59 , V_53 ) ;
V_39 = ( 3 << ( V_54 + 16 ) ) ;
V_39 |= ( V_40 & 3 ) << V_54 ;
F_22 ( V_39 , V_50 ) ;
F_23 ( & V_48 -> V_59 , V_53 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_48 ,
int V_60 , void T_1 * * V_50 , T_2 * V_54 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
* V_50 = V_6 -> V_51 + V_61 ;
* V_50 += V_48 -> V_19 * V_62 ;
* V_50 += ( V_60 / V_63 ) * 4 ;
* V_54 = V_60 % V_63 ;
}
static void F_25 ( struct V_1 * V_48 ,
int V_60 , void T_1 * * V_50 , T_2 * V_54 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
if ( V_48 -> V_55 == V_56 && V_60 < 12 ) {
* V_50 = V_48 -> V_64 +
( ( V_60 / V_65 ) * 4 ) ;
* V_54 = V_60 % V_65 ;
* V_54 *= V_66 ;
} else {
* V_50 = V_6 -> V_64 - 4 ;
* V_50 += V_48 -> V_19 * V_67 ;
* V_50 += ( ( V_60 / V_65 ) * 4 ) ;
* V_54 = 7 - ( V_60 % V_65 ) ;
* V_54 *= V_66 ;
}
}
static int F_26 ( struct V_1 * V_48 , int V_60 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_68 * V_13 = V_6 -> V_13 ;
void T_1 * V_50 ;
T_2 V_54 ;
T_3 V_39 ;
if ( V_13 -> type == V_69 )
return V_70 ;
V_13 -> V_71 ( V_48 , V_60 , & V_50 , & V_54 ) ;
switch ( V_13 -> type ) {
case V_72 :
return ! ( F_27 ( V_50 ) & F_28 ( V_54 ) )
? V_73
: V_70 ;
case V_74 :
V_39 = F_27 ( V_50 ) >> V_54 ;
V_39 &= ( 1 << V_66 ) - 1 ;
switch ( V_39 ) {
case 0 :
return V_70 ;
case 1 :
return V_75 ;
case 2 :
return V_76 ;
case 3 :
return V_77 ;
}
F_12 ( V_6 -> V_35 , L_5 ) ;
return - V_78 ;
default:
F_12 ( V_6 -> V_35 , L_6 ) ;
return - V_20 ;
} ;
}
static int F_29 ( struct V_1 * V_48 ,
int V_60 , int V_79 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_68 * V_13 = V_6 -> V_13 ;
void T_1 * V_50 ;
unsigned long V_53 ;
T_2 V_54 ;
T_3 V_39 ;
F_18 ( V_6 -> V_35 , L_7 ,
V_48 -> V_19 , V_60 , V_79 ) ;
if ( V_13 -> type == V_69 )
return V_79 ? - V_20 : 0 ;
V_13 -> V_71 ( V_48 , V_60 , & V_50 , & V_54 ) ;
switch ( V_13 -> type ) {
case V_72 :
F_21 ( & V_48 -> V_59 , V_53 ) ;
V_39 = F_28 ( V_54 + 16 ) ;
if ( V_79 == V_70 )
V_39 |= F_28 ( V_54 ) ;
F_22 ( V_39 , V_50 ) ;
F_23 ( & V_48 -> V_59 , V_53 ) ;
break;
case V_74 :
F_21 ( & V_48 -> V_59 , V_53 ) ;
V_39 = ( ( 1 << V_66 ) - 1 ) << ( V_54 + 16 ) ;
switch ( V_79 ) {
case V_70 :
break;
case V_75 :
V_39 |= ( 1 << V_54 ) ;
break;
case V_76 :
V_39 |= ( 2 << V_54 ) ;
break;
case V_77 :
V_39 |= ( 3 << V_54 ) ;
break;
default:
F_23 ( & V_48 -> V_59 , V_53 ) ;
F_12 ( V_6 -> V_35 , L_8 ,
V_79 ) ;
return - V_20 ;
}
F_22 ( V_39 , V_50 ) ;
F_23 ( & V_48 -> V_59 , V_53 ) ;
break;
default:
F_12 ( V_6 -> V_35 , L_6 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_30 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_80 ;
}
static const char * F_31 ( struct V_21 * V_22 ,
unsigned V_23 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_81 [ V_23 ] . V_7 ;
}
static int F_32 ( struct V_21 * V_22 ,
unsigned V_23 , const char * const * * V_10 ,
unsigned * const V_82 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
* V_10 = V_6 -> V_81 [ V_23 ] . V_10 ;
* V_82 = V_6 -> V_81 [ V_23 ] . V_9 ;
return 0 ;
}
static int F_33 ( struct V_21 * V_22 , unsigned V_23 ,
unsigned V_42 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
const unsigned int * V_24 = V_6 -> V_10 [ V_42 ] . V_24 ;
const struct V_83 * V_39 = V_6 -> V_10 [ V_42 ] . V_39 ;
struct V_1 * V_48 ;
int V_84 , V_85 = 0 ;
F_18 ( V_6 -> V_35 , L_9 ,
V_6 -> V_81 [ V_23 ] . V_7 , V_6 -> V_10 [ V_42 ] . V_7 ) ;
for ( V_84 = 0 ; V_84 < V_6 -> V_10 [ V_42 ] . V_25 ; V_84 ++ ) {
V_48 = F_4 ( V_6 , V_24 [ V_84 ] ) ;
V_85 = F_20 ( V_48 , V_24 [ V_84 ] - V_48 -> V_15 ,
V_39 [ V_84 ] . V_86 ) ;
if ( V_85 )
break;
}
if ( V_85 ) {
for ( V_84 -- ; V_84 >= 0 ; V_84 -- )
F_20 ( V_48 , V_24 [ V_84 ] - V_48 -> V_15 , 0 ) ;
return V_85 ;
}
return 0 ;
}
static void F_34 ( struct V_21 * V_22 ,
unsigned V_23 , unsigned V_42 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
const unsigned int * V_24 = V_6 -> V_10 [ V_42 ] . V_24 ;
struct V_1 * V_48 ;
int V_84 ;
F_18 ( V_6 -> V_35 , L_10 ,
V_6 -> V_81 [ V_23 ] . V_7 , V_6 -> V_10 [ V_42 ] . V_7 ) ;
for ( V_84 = 0 ; V_84 < V_6 -> V_10 [ V_42 ] . V_25 ; V_84 ++ ) {
V_48 = F_4 ( V_6 , V_24 [ V_84 ] ) ;
F_20 ( V_48 , V_24 [ V_84 ] - V_48 -> V_15 , 0 ) ;
}
}
static int F_35 ( struct V_21 * V_22 ,
struct V_87 * V_88 ,
unsigned V_89 , bool V_90 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 ;
struct V_2 * V_91 ;
int V_11 , V_85 ;
T_3 V_39 ;
V_91 = V_88 -> V_3 ;
V_48 = F_1 ( V_91 ) ;
V_11 = V_89 - V_91 -> V_92 ;
F_18 ( V_6 -> V_35 , L_11 ,
V_89 , V_88 -> V_7 , V_11 , V_90 ? L_12 : L_13 ) ;
V_85 = F_20 ( V_48 , V_11 , V_57 ) ;
if ( V_85 < 0 )
return V_85 ;
V_39 = F_27 ( V_48 -> V_51 + V_93 ) ;
if ( ! V_90 )
V_39 |= F_28 ( V_11 ) ;
else
V_39 &= ~ F_28 ( V_11 ) ;
F_36 ( V_39 , V_48 -> V_51 + V_93 ) ;
return 0 ;
}
static bool F_37 ( struct V_68 * V_13 ,
enum V_94 V_79 )
{
switch ( V_13 -> type ) {
case V_72 :
return ( V_79 == V_73 ||
V_79 == V_70 ) ;
case V_69 :
return V_79 ? false : true ;
case V_74 :
return ( V_79 != V_73 ) ;
}
return false ;
}
static int F_38 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_44 , unsigned V_46 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_94 V_95 ;
T_4 V_96 ;
int V_8 ;
int V_97 ;
for ( V_8 = 0 ; V_8 < V_46 ; V_8 ++ ) {
V_95 = F_39 ( V_44 [ V_8 ] ) ;
V_96 = F_40 ( V_44 [ V_8 ] ) ;
switch ( V_95 ) {
case V_70 :
V_97 = F_29 ( V_48 , V_11 - V_48 -> V_15 ,
V_95 ) ;
if ( V_97 )
return V_97 ;
break;
case V_75 :
case V_76 :
case V_73 :
case V_77 :
if ( ! F_37 ( V_6 -> V_13 , V_95 ) )
return - V_58 ;
if ( ! V_96 )
return - V_20 ;
V_97 = F_29 ( V_48 , V_11 - V_48 -> V_15 ,
V_95 ) ;
if ( V_97 )
return V_97 ;
break;
default:
return - V_58 ;
break;
}
}
return 0 ;
}
static int F_41 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_98 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_94 V_95 = F_39 ( * V_98 ) ;
switch ( V_95 ) {
case V_70 :
if ( F_26 ( V_48 , V_11 - V_48 -> V_15 ) != V_95 )
return - V_20 ;
* V_98 = 0 ;
break;
case V_75 :
case V_76 :
case V_73 :
case V_77 :
if ( ! F_37 ( V_6 -> V_13 , V_95 ) )
return - V_58 ;
if ( F_26 ( V_48 , V_11 - V_48 -> V_15 ) != V_95 )
return - V_20 ;
* V_98 = 1 ;
break;
default:
return - V_58 ;
break;
}
return 0 ;
}
static void F_42 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
struct V_26 * V_99 ;
F_43 (np, child) {
if ( F_44 ( V_100 , V_99 ) )
continue;
V_6 -> V_80 ++ ;
V_6 -> V_9 += F_45 ( V_99 ) ;
}
}
static int F_46 ( struct V_26 * V_27 ,
struct V_4 * V_31 ,
struct V_5 * V_6 ,
T_3 V_101 )
{
struct V_1 * V_48 ;
int V_102 ;
const T_5 * V_103 ;
int V_17 ;
int V_8 , V_104 ;
int V_85 ;
F_18 ( V_6 -> V_35 , L_14 , V_101 , V_27 -> V_7 ) ;
V_31 -> V_7 = V_27 -> V_7 ;
V_103 = F_47 ( V_27 , L_15 , & V_102 ) ;
V_102 /= sizeof( * V_103 ) ;
if ( ! V_102 || V_102 % 4 ) {
F_12 ( V_6 -> V_35 , L_16 ) ;
return - V_20 ;
}
V_31 -> V_25 = V_102 / 4 ;
V_31 -> V_24 = F_13 ( V_6 -> V_35 , V_31 -> V_25 * sizeof( unsigned int ) ,
V_36 ) ;
V_31 -> V_39 = F_13 ( V_6 -> V_35 , V_31 -> V_25 *
sizeof( struct V_83 ) ,
V_36 ) ;
if ( ! V_31 -> V_24 || ! V_31 -> V_39 )
return - V_37 ;
for ( V_8 = 0 , V_104 = 0 ; V_8 < V_102 ; V_8 += 4 , V_104 ++ ) {
const T_5 * V_105 ;
struct V_26 * V_106 ;
V_17 = F_48 ( * V_103 ++ ) ;
V_48 = F_5 ( V_6 , V_17 ) ;
if ( F_49 ( V_48 ) )
return F_50 ( V_48 ) ;
V_31 -> V_24 [ V_104 ] = V_48 -> V_15 + F_48 ( * V_103 ++ ) ;
V_31 -> V_39 [ V_104 ] . V_86 = F_48 ( * V_103 ++ ) ;
V_105 = V_103 ++ ;
if ( ! V_105 )
return - V_20 ;
V_106 = F_51 ( F_52 ( V_105 ) ) ;
V_85 = F_53 ( V_106 ,
& V_31 -> V_39 [ V_104 ] . V_44 , & V_31 -> V_39 [ V_104 ] . V_47 ) ;
if ( V_85 )
return V_85 ;
}
return 0 ;
}
static int F_54 ( struct V_26 * V_27 ,
struct V_5 * V_6 ,
T_3 V_101 )
{
struct V_26 * V_99 ;
struct V_107 * V_86 ;
struct V_4 * V_31 ;
int V_85 ;
static T_3 V_108 ;
T_3 V_8 = 0 ;
F_18 ( V_6 -> V_35 , L_17 , V_101 , V_27 -> V_7 ) ;
V_86 = & V_6 -> V_81 [ V_101 ] ;
V_86 -> V_7 = V_27 -> V_7 ;
V_86 -> V_9 = F_45 ( V_27 ) ;
if ( V_86 -> V_9 <= 0 )
return 0 ;
V_86 -> V_10 = F_13 ( V_6 -> V_35 ,
V_86 -> V_9 * sizeof( char * ) , V_36 ) ;
if ( ! V_86 -> V_10 )
return - V_37 ;
F_43 (np, child) {
V_86 -> V_10 [ V_8 ] = V_99 -> V_7 ;
V_31 = & V_6 -> V_10 [ V_108 ++ ] ;
V_85 = F_46 ( V_99 , V_31 , V_6 , V_8 ++ ) ;
if ( V_85 )
return V_85 ;
}
return 0 ;
}
static int F_55 ( struct V_109 * V_110 ,
struct V_5 * V_6 )
{
struct V_111 * V_35 = & V_110 -> V_35 ;
struct V_26 * V_27 = V_35 -> V_112 ;
struct V_26 * V_99 ;
int V_85 ;
int V_8 ;
F_42 ( V_6 , V_27 ) ;
F_18 ( & V_110 -> V_35 , L_18 , V_6 -> V_80 ) ;
F_18 ( & V_110 -> V_35 , L_19 , V_6 -> V_9 ) ;
V_6 -> V_81 = F_13 ( V_35 , V_6 -> V_80 *
sizeof( struct V_107 ) ,
V_36 ) ;
if ( ! V_6 -> V_81 ) {
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
F_43 (np, child) {
if ( F_44 ( V_100 , V_99 ) )
continue;
V_85 = F_54 ( V_99 , V_6 , V_8 ++ ) ;
if ( V_85 ) {
F_12 ( & V_110 -> V_35 , L_22 ) ;
return V_85 ;
}
}
return 0 ;
}
static int F_56 ( struct V_109 * V_110 ,
struct V_5 * V_6 )
{
struct V_113 * V_114 = & V_6 -> V_115 ;
struct V_116 * V_117 , * V_118 ;
struct V_1 * V_119 ;
int V_11 , V_48 , V_85 ;
int V_120 ;
V_114 -> V_7 = L_23 ;
V_114 -> V_121 = V_122 ;
V_114 -> V_123 = & V_124 ;
V_114 -> V_125 = & V_126 ;
V_114 -> V_127 = & V_128 ;
V_117 = F_13 ( & V_110 -> V_35 , sizeof( * V_117 ) *
V_6 -> V_13 -> V_16 , V_36 ) ;
if ( ! V_117 ) {
F_12 ( & V_110 -> V_35 , L_24 ) ;
return - V_37 ;
}
V_114 -> V_24 = V_117 ;
V_114 -> V_25 = V_6 -> V_13 -> V_16 ;
V_118 = V_117 ;
for ( V_48 = 0 , V_120 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; V_48 ++ ) {
V_119 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
for ( V_11 = 0 ; V_11 < V_119 -> V_16 ; V_11 ++ , V_120 ++ ) {
V_118 -> V_129 = V_120 ;
V_118 -> V_7 = F_57 ( V_36 , L_25 ,
V_119 -> V_7 , V_11 ) ;
V_118 ++ ;
}
}
V_6 -> V_130 = F_58 ( V_114 , & V_110 -> V_35 , V_6 ) ;
if ( ! V_6 -> V_130 ) {
F_12 ( & V_110 -> V_35 , L_26 ) ;
return - V_20 ;
}
for ( V_48 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; ++ V_48 ) {
V_119 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
V_119 -> V_131 . V_7 = V_119 -> V_7 ;
V_119 -> V_131 . V_132 = V_48 ;
V_119 -> V_131 . V_15 = V_119 -> V_15 ;
V_119 -> V_131 . V_92 = V_119 -> V_2 . V_92 ;
V_119 -> V_131 . V_25 = V_119 -> V_2 . V_133 ;
V_119 -> V_131 . V_3 = & V_119 -> V_2 ;
F_59 ( V_6 -> V_130 , & V_119 -> V_131 ) ;
}
V_85 = F_55 ( V_110 , V_6 ) ;
if ( V_85 ) {
F_60 ( V_6 -> V_130 ) ;
return V_85 ;
}
return 0 ;
}
static int F_61 ( struct V_2 * V_91 , unsigned V_89 )
{
return F_62 ( V_91 -> V_92 + V_89 ) ;
}
static void F_63 ( struct V_2 * V_91 , unsigned V_89 )
{
F_64 ( V_91 -> V_92 + V_89 ) ;
}
static void F_65 ( struct V_2 * V_3 , unsigned V_89 , int V_134 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
void T_1 * V_50 = V_48 -> V_51 + V_135 ;
unsigned long V_53 ;
T_3 V_39 ;
F_21 ( & V_48 -> V_59 , V_53 ) ;
V_39 = F_66 ( V_50 ) ;
V_39 &= ~ F_28 ( V_89 ) ;
if ( V_134 )
V_39 |= F_28 ( V_89 ) ;
F_22 ( V_39 , V_50 ) ;
F_23 ( & V_48 -> V_59 , V_53 ) ;
}
static int F_67 ( struct V_2 * V_3 , unsigned V_89 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
T_3 V_39 ;
V_39 = F_66 ( V_48 -> V_51 + V_136 ) ;
V_39 >>= V_89 ;
V_39 &= 1 ;
return V_39 ;
}
static int F_68 ( struct V_2 * V_3 , unsigned V_89 )
{
return F_69 ( V_3 -> V_92 + V_89 ) ;
}
static int F_70 ( struct V_2 * V_3 ,
unsigned V_89 , int V_134 )
{
F_65 ( V_3 , V_89 , V_134 ) ;
return F_71 ( V_3 -> V_92 + V_89 ) ;
}
static int F_72 ( struct V_2 * V_3 , unsigned V_89 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
unsigned int V_137 ;
if ( ! V_48 -> V_138 )
return - V_139 ;
V_137 = F_73 ( V_48 -> V_138 , V_89 ) ;
return ( V_137 ) ? : - V_139 ;
}
static void F_74 ( unsigned int V_140 , struct V_141 * V_142 )
{
struct V_143 * V_91 = F_75 ( V_140 ) ;
struct V_1 * V_48 = F_76 ( V_140 ) ;
T_3 V_144 = 0 , V_39 = 0 ;
T_3 V_145 ;
bool V_146 = false ;
F_18 ( V_48 -> V_49 -> V_35 , L_27 , V_48 -> V_7 ) ;
F_77 ( V_91 , V_142 ) ;
V_145 = F_27 ( V_48 -> V_51 + V_147 ) ;
if ( V_48 -> V_148 ) {
V_144 = F_27 ( V_48 -> V_51 +
V_149 ) ;
V_39 = F_27 ( V_48 -> V_51 + V_136 ) ;
}
while ( V_145 ) {
unsigned int V_137 ;
V_140 = F_78 ( V_145 ) ;
V_145 &= ~ F_28 ( V_140 ) ;
V_137 = F_79 ( V_48 -> V_138 , V_140 ) ;
if ( ! V_137 ) {
F_12 ( V_48 -> V_49 -> V_35 , L_28 , V_140 ) ;
continue;
}
F_18 ( V_48 -> V_49 -> V_35 , L_29 , V_140 ) ;
if ( V_48 -> V_148 & F_28 ( V_140 ) ) {
if ( V_39 & F_28 ( V_140 ) )
V_144 &= ~ F_28 ( V_140 ) ;
else
V_144 |= F_28 ( V_140 ) ;
V_146 = true ;
}
F_80 ( V_137 ) ;
}
if ( V_48 -> V_148 && V_146 ) {
V_39 = F_27 ( V_48 -> V_51 + V_150 ) ;
F_36 ( 0 , V_48 -> V_51 + V_150 ) ;
F_22 ( V_144 , V_48 -> V_51 + V_149 ) ;
F_22 ( V_39 , V_48 -> V_51 + V_150 ) ;
}
F_81 ( V_91 , V_142 ) ;
}
static int F_82 ( struct V_151 * V_152 , unsigned int type )
{
struct V_153 * V_3 = F_83 ( V_152 ) ;
struct V_1 * V_48 = V_3 -> V_154 ;
T_3 V_155 = F_28 ( V_152 -> V_156 ) ;
T_3 V_144 ;
T_3 V_157 ;
T_3 V_39 ;
int V_85 ;
V_85 = F_20 ( V_48 , V_152 -> V_156 , V_57 ) ;
if ( V_85 < 0 )
return V_85 ;
V_39 = F_27 ( V_48 -> V_51 + V_93 ) ;
V_39 &= ~ V_155 ;
F_36 ( V_39 , V_48 -> V_51 + V_93 ) ;
if ( type & V_158 )
F_84 ( V_152 -> V_140 , V_159 ) ;
else
F_84 ( V_152 -> V_140 , V_160 ) ;
F_85 ( V_3 ) ;
V_157 = F_27 ( V_3 -> V_51 + V_161 ) ;
V_144 = F_27 ( V_3 -> V_51 + V_149 ) ;
switch ( type ) {
case V_158 :
V_48 -> V_148 |= V_155 ;
V_157 |= V_155 ;
V_39 = F_66 ( V_48 -> V_51 + V_136 ) ;
if ( V_39 & V_155 )
V_144 &= ~ V_155 ;
else
V_144 |= V_155 ;
break;
case V_162 :
V_48 -> V_148 &= ~ V_155 ;
V_157 |= V_155 ;
V_144 |= V_155 ;
break;
case V_163 :
V_48 -> V_148 &= ~ V_155 ;
V_157 |= V_155 ;
V_144 &= ~ V_155 ;
break;
case V_164 :
V_48 -> V_148 &= ~ V_155 ;
V_157 &= ~ V_155 ;
V_144 |= V_155 ;
break;
case V_165 :
V_48 -> V_148 &= ~ V_155 ;
V_157 &= ~ V_155 ;
V_144 &= ~ V_155 ;
break;
default:
F_86 ( V_3 ) ;
return - V_20 ;
}
F_36 ( V_157 , V_3 -> V_51 + V_161 ) ;
F_36 ( V_144 , V_3 -> V_51 + V_149 ) ;
F_86 ( V_3 ) ;
return 0 ;
}
static int F_87 ( struct V_109 * V_110 ,
struct V_5 * V_6 )
{
struct V_68 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
unsigned int V_166 = V_167 | V_168 | V_169 ;
struct V_153 * V_3 ;
int V_85 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_170 ) {
F_88 ( & V_110 -> V_35 , L_30 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_138 = F_89 ( V_48 -> V_112 , 32 ,
& V_171 , NULL ) ;
if ( ! V_48 -> V_138 ) {
F_88 ( & V_110 -> V_35 , L_31 ,
V_48 -> V_7 ) ;
continue;
}
V_85 = F_90 ( V_48 -> V_138 , 32 , 1 ,
L_32 , V_160 ,
V_166 , 0 , V_172 ) ;
if ( V_85 ) {
F_12 ( & V_110 -> V_35 , L_33 ,
V_48 -> V_7 ) ;
F_91 ( V_48 -> V_138 ) ;
continue;
}
V_3 = F_92 ( V_48 -> V_138 , 0 ) ;
V_3 -> V_51 = V_48 -> V_51 ;
V_3 -> V_154 = V_48 ;
V_3 -> V_173 [ 0 ] . V_174 . V_155 = V_150 ;
V_3 -> V_173 [ 0 ] . V_174 . V_175 = V_176 ;
V_3 -> V_173 [ 0 ] . V_91 . V_177 = V_178 ;
V_3 -> V_173 [ 0 ] . V_91 . V_179 = V_180 ;
V_3 -> V_173 [ 0 ] . V_91 . V_181 = V_182 ;
V_3 -> V_173 [ 0 ] . V_91 . V_183 = V_184 ;
V_3 -> V_173 [ 0 ] . V_91 . V_185 = F_82 ;
F_93 ( V_48 -> V_140 , V_48 ) ;
F_94 ( V_48 -> V_140 , F_74 ) ;
}
return 0 ;
}
static int F_95 ( struct V_109 * V_110 ,
struct V_5 * V_6 )
{
struct V_68 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
struct V_2 * V_3 ;
int V_85 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_170 ) {
F_88 ( & V_110 -> V_35 , L_30 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_2 = V_186 ;
V_3 = & V_48 -> V_2 ;
V_3 -> V_92 = V_48 -> V_15 ;
V_3 -> V_133 = V_48 -> V_16 ;
V_3 -> V_35 = & V_110 -> V_35 ;
V_3 -> V_112 = V_48 -> V_112 ;
V_3 -> V_187 = V_48 -> V_7 ;
V_85 = F_96 ( V_3 ) ;
if ( V_85 ) {
F_12 ( & V_110 -> V_35 , L_34 ,
V_3 -> V_187 , V_85 ) ;
goto V_188;
}
}
F_87 ( V_110 , V_6 ) ;
return 0 ;
V_188:
for ( -- V_8 , -- V_48 ; V_8 >= 0 ; -- V_8 , -- V_48 ) {
if ( ! V_48 -> V_170 )
continue;
if ( F_97 ( & V_48 -> V_2 ) )
F_12 ( & V_110 -> V_35 , L_35 ,
V_48 -> V_2 . V_187 ) ;
}
return V_85 ;
}
static int F_98 ( struct V_109 * V_110 ,
struct V_5 * V_6 )
{
struct V_68 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
int V_85 = 0 ;
int V_8 ;
for ( V_8 = 0 ; ! V_85 && V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_170 )
continue;
V_85 = F_97 ( & V_48 -> V_2 ) ;
}
if ( V_85 )
F_12 ( & V_110 -> V_35 , L_36 ) ;
return V_85 ;
}
static int F_99 ( struct V_1 * V_48 ,
struct V_111 * V_35 )
{
struct V_189 V_190 ;
if ( F_100 ( V_48 -> V_112 , 0 , & V_190 ) ) {
F_12 ( V_35 , L_37 ) ;
return - V_191 ;
}
V_48 -> V_51 = F_101 ( V_35 , & V_190 ) ;
if ( F_49 ( V_48 -> V_51 ) )
return F_50 ( V_48 -> V_51 ) ;
if ( F_102 ( V_48 -> V_112 ,
L_38 ) ) {
V_48 -> V_55 = V_56 ;
if ( F_100 ( V_48 -> V_112 , 1 , & V_190 ) ) {
F_12 ( V_35 , L_37 ) ;
return - V_191 ;
}
V_48 -> V_64 = F_101 ( V_35 , & V_190 ) ;
if ( F_49 ( V_48 -> V_64 ) )
return F_50 ( V_48 -> V_64 ) ;
} else {
V_48 -> V_55 = V_192 ;
}
V_48 -> V_140 = F_103 ( V_48 -> V_112 , 0 ) ;
V_48 -> V_193 = F_104 ( V_48 -> V_112 , 0 ) ;
if ( F_49 ( V_48 -> V_193 ) )
return F_50 ( V_48 -> V_193 ) ;
return F_105 ( V_48 -> V_193 ) ;
}
static struct V_68 * F_106 (
struct V_5 * V_152 ,
struct V_109 * V_110 )
{
const struct V_194 * V_195 ;
struct V_26 * V_196 = V_110 -> V_35 . V_112 ;
struct V_26 * V_27 ;
struct V_68 * V_13 ;
struct V_1 * V_48 ;
int V_8 ;
V_195 = F_44 ( V_197 , V_196 ) ;
V_13 = (struct V_68 * ) V_195 -> V_39 ;
F_43 (node, np) {
if ( ! F_107 ( V_27 , L_39 , NULL ) )
continue;
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! strcmp ( V_48 -> V_7 , V_27 -> V_7 ) ) {
V_48 -> V_112 = V_27 ;
if ( ! F_99 ( V_48 , & V_110 -> V_35 ) )
V_48 -> V_170 = true ;
break;
}
}
}
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
F_108 ( & V_48 -> V_59 ) ;
V_48 -> V_49 = V_152 ;
V_48 -> V_15 = V_13 -> V_16 ;
V_13 -> V_16 += V_48 -> V_16 ;
}
return V_13 ;
}
static int F_109 ( struct V_109 * V_110 )
{
struct V_5 * V_6 ;
struct V_111 * V_35 = & V_110 -> V_35 ;
struct V_68 * V_13 ;
struct V_189 * V_190 ;
int V_85 ;
if ( ! V_35 -> V_112 ) {
F_12 ( V_35 , L_40 ) ;
return - V_198 ;
}
V_6 = F_13 ( V_35 , sizeof( struct V_5 ) , V_36 ) ;
if ( ! V_6 )
return - V_37 ;
V_13 = F_106 ( V_6 , V_110 ) ;
if ( ! V_13 ) {
F_12 ( V_35 , L_41 ) ;
return - V_20 ;
}
V_6 -> V_13 = V_13 ;
V_6 -> V_35 = V_35 ;
V_190 = F_110 ( V_110 , V_199 , 0 ) ;
V_6 -> V_51 = F_101 ( & V_110 -> V_35 , V_190 ) ;
if ( F_49 ( V_6 -> V_51 ) )
return F_50 ( V_6 -> V_51 ) ;
if ( V_13 -> type == V_74 ) {
V_190 = F_110 ( V_110 , V_199 , 1 ) ;
V_6 -> V_64 = F_101 ( & V_110 -> V_35 , V_190 ) ;
if ( F_49 ( V_6 -> V_64 ) )
return F_50 ( V_6 -> V_64 ) ;
}
V_85 = F_95 ( V_110 , V_6 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_56 ( V_110 , V_6 ) ;
if ( V_85 ) {
F_98 ( V_110 , V_6 ) ;
return V_85 ;
}
F_111 ( V_110 , V_6 ) ;
return 0 ;
}
static int T_6 F_112 ( void )
{
return F_113 ( & V_200 ) ;
}
