static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static const inline struct V_4 * F_3 (
const struct V_5 * V_6 ,
const char * V_7 )
{
const struct V_4 * V_8 = NULL ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_10 ; V_9 ++ ) {
if ( strcmp ( V_6 -> V_11 [ V_9 ] . V_7 , V_7 ) )
continue;
V_8 = & V_6 -> V_11 [ V_9 ] ;
break;
}
return V_8 ;
}
static struct V_1 * F_4 ( struct V_5 * V_6 ,
unsigned V_12 )
{
struct V_1 * V_13 = V_6 -> V_14 -> V_15 ;
while ( ( V_12 >= V_13 -> V_16 ) &&
( ( V_13 -> V_16 + V_13 -> V_17 - 1 ) < V_12 ) )
V_13 ++ ;
return V_13 ;
}
static struct V_1 * F_5 (
struct V_5 * V_6 ,
unsigned V_18 )
{
struct V_1 * V_13 = V_6 -> V_14 -> V_15 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_14 -> V_19 ; V_9 ++ ) {
if ( V_13 -> V_20 == V_18 )
break;
V_13 ++ ;
}
if ( V_13 -> V_20 != V_18 )
return F_6 ( - V_21 ) ;
return V_13 ;
}
static int F_7 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
return V_6 -> V_10 ;
}
static const char * F_9 ( struct V_22 * V_23 ,
unsigned V_24 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
return V_6 -> V_11 [ V_24 ] . V_7 ;
}
static int F_10 ( struct V_22 * V_23 ,
unsigned V_24 , const unsigned * * V_25 ,
unsigned * V_26 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
if ( V_24 >= V_6 -> V_10 )
return - V_21 ;
* V_25 = V_6 -> V_11 [ V_24 ] . V_25 ;
* V_26 = V_6 -> V_11 [ V_24 ] . V_26 ;
return 0 ;
}
static int F_11 ( struct V_22 * V_23 ,
struct V_27 * V_28 ,
struct V_29 * * V_30 , unsigned * V_31 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
const struct V_4 * V_8 ;
struct V_29 * V_32 ;
struct V_27 * V_33 ;
int V_34 = 1 ;
int V_9 ;
V_8 = F_3 ( V_6 , V_28 -> V_7 ) ;
if ( ! V_8 ) {
F_12 ( V_6 -> V_35 , L_1 ,
V_28 -> V_7 ) ;
return - V_21 ;
}
V_34 += V_8 -> V_26 ;
V_32 = F_13 ( V_23 -> V_35 , sizeof( * V_32 ) * V_34 ,
V_36 ) ;
if ( ! V_32 )
return - V_37 ;
* V_30 = V_32 ;
* V_31 = V_34 ;
V_33 = F_14 ( V_28 ) ;
if ( ! V_33 ) {
F_15 ( V_23 -> V_35 , V_32 ) ;
return - V_21 ;
}
V_32 [ 0 ] . type = V_38 ;
V_32 [ 0 ] . V_39 . V_40 . V_41 = V_33 -> V_7 ;
V_32 [ 0 ] . V_39 . V_40 . V_42 = V_28 -> V_7 ;
F_16 ( V_33 ) ;
V_32 ++ ;
for ( V_9 = 0 ; V_9 < V_8 -> V_26 ; V_9 ++ ) {
V_32 [ V_9 ] . type = V_43 ;
V_32 [ V_9 ] . V_39 . V_44 . V_45 =
F_17 ( V_23 , V_8 -> V_25 [ V_9 ] ) ;
V_32 [ V_9 ] . V_39 . V_44 . V_44 = V_8 -> V_39 [ V_9 ] . V_44 ;
V_32 [ V_9 ] . V_39 . V_44 . V_46 = V_8 -> V_39 [ V_9 ] . V_47 ;
}
F_18 ( V_23 -> V_35 , L_2 ,
( * V_30 ) -> V_39 . V_40 . V_41 , ( * V_30 ) -> V_39 . V_40 . V_42 , V_34 ) ;
return 0 ;
}
static void F_19 ( struct V_22 * V_23 ,
struct V_29 * V_30 , unsigned V_31 )
{
}
static void F_20 ( struct V_1 * V_48 , int V_12 , int V_40 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
void T_1 * V_50 = V_6 -> V_51 + V_6 -> V_14 -> V_52 ;
unsigned long V_53 ;
T_2 V_54 ;
T_3 V_39 ;
F_18 ( V_6 -> V_35 , L_3 ,
V_48 -> V_20 , V_12 , V_40 ) ;
V_50 += V_48 -> V_20 * 0x10 ;
V_50 += ( V_12 / 8 ) * 4 ;
V_54 = ( V_12 % 8 ) * 2 ;
F_21 ( & V_48 -> V_55 , V_53 ) ;
V_39 = ( 3 << ( V_54 + 16 ) ) ;
V_39 |= ( V_40 & 3 ) << V_54 ;
F_22 ( V_39 , V_50 ) ;
F_23 ( & V_48 -> V_55 , V_53 ) ;
}
static int F_24 ( struct V_1 * V_48 , int V_56 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_57 * V_14 = V_6 -> V_14 ;
void T_1 * V_50 ;
T_2 V_54 ;
if ( ! V_14 -> V_58 )
return V_59 ;
V_50 = V_6 -> V_51 + V_14 -> V_58 ;
if ( V_14 -> V_60 ) {
V_50 += V_48 -> V_20 * V_14 -> V_61 ;
V_50 += ( V_56 / 16 ) * 4 ;
V_54 = V_56 % 16 ;
return ! ( F_25 ( V_50 ) & F_26 ( V_54 ) )
? V_62
: V_59 ;
} else {
F_12 ( V_6 -> V_35 , L_4 ) ;
return - V_63 ;
}
}
static int F_27 ( struct V_1 * V_48 ,
int V_56 , int V_64 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_57 * V_14 = V_6 -> V_14 ;
void T_1 * V_50 ;
unsigned long V_53 ;
T_2 V_54 ;
T_3 V_39 ;
F_18 ( V_6 -> V_35 , L_5 ,
V_48 -> V_20 , V_56 , V_64 ) ;
if ( ! V_14 -> V_58 )
return V_64 ? - V_21 : 0 ;
V_50 = V_6 -> V_51 + V_14 -> V_58 ;
if ( V_14 -> V_60 ) {
if ( V_64 != V_62 &&
V_64 != V_59 ) {
F_12 ( V_6 -> V_35 , L_6 ) ;
return - V_21 ;
}
V_50 += V_48 -> V_20 * V_14 -> V_61 ;
V_50 += ( V_56 / 16 ) * 4 ;
V_54 = V_56 % 16 ;
F_21 ( & V_48 -> V_55 , V_53 ) ;
V_39 = F_26 ( V_54 + 16 ) ;
if ( V_64 == V_59 )
V_39 |= F_26 ( V_54 ) ;
F_22 ( V_39 , V_50 ) ;
F_23 ( & V_48 -> V_55 , V_53 ) ;
} else {
if ( V_64 == V_62 ) {
F_12 ( V_6 -> V_35 , L_7 ) ;
return - V_21 ;
}
F_12 ( V_6 -> V_35 , L_4 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_28 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
return V_6 -> V_65 ;
}
static const char * F_29 ( struct V_22 * V_23 ,
unsigned V_24 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
return V_6 -> V_66 [ V_24 ] . V_7 ;
}
static int F_30 ( struct V_22 * V_23 ,
unsigned V_24 , const char * const * * V_11 ,
unsigned * const V_67 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
* V_11 = V_6 -> V_66 [ V_24 ] . V_11 ;
* V_67 = V_6 -> V_66 [ V_24 ] . V_10 ;
return 0 ;
}
static int F_31 ( struct V_22 * V_23 , unsigned V_24 ,
unsigned V_42 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
const unsigned int * V_25 = V_6 -> V_11 [ V_42 ] . V_25 ;
const struct V_68 * V_39 = V_6 -> V_11 [ V_42 ] . V_39 ;
struct V_1 * V_48 ;
int V_69 ;
F_18 ( V_6 -> V_35 , L_8 ,
V_6 -> V_66 [ V_24 ] . V_7 , V_6 -> V_11 [ V_42 ] . V_7 ) ;
for ( V_69 = 0 ; V_69 < V_6 -> V_11 [ V_42 ] . V_26 ; V_69 ++ ) {
V_48 = F_4 ( V_6 , V_25 [ V_69 ] ) ;
F_20 ( V_48 , V_25 [ V_69 ] - V_48 -> V_16 ,
V_39 [ V_69 ] . V_70 ) ;
}
return 0 ;
}
static void F_32 ( struct V_22 * V_23 ,
unsigned V_24 , unsigned V_42 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
const unsigned int * V_25 = V_6 -> V_11 [ V_42 ] . V_25 ;
struct V_1 * V_48 ;
int V_69 ;
F_18 ( V_6 -> V_35 , L_9 ,
V_6 -> V_66 [ V_24 ] . V_7 , V_6 -> V_11 [ V_42 ] . V_7 ) ;
for ( V_69 = 0 ; V_69 < V_6 -> V_11 [ V_42 ] . V_26 ; V_69 ++ ) {
V_48 = F_4 ( V_6 , V_25 [ V_69 ] ) ;
F_20 ( V_48 , V_25 [ V_69 ] - V_48 -> V_16 , 0 ) ;
}
}
static int F_33 ( struct V_22 * V_23 ,
struct V_71 * V_72 ,
unsigned V_73 , bool V_74 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
struct V_1 * V_48 ;
struct V_2 * V_75 ;
int V_12 ;
T_3 V_39 ;
V_75 = V_72 -> V_3 ;
V_48 = F_1 ( V_75 ) ;
V_12 = V_73 - V_75 -> V_76 ;
F_18 ( V_6 -> V_35 , L_10 ,
V_73 , V_72 -> V_7 , V_12 , V_74 ? L_11 : L_12 ) ;
F_20 ( V_48 , V_12 , V_77 ) ;
V_39 = F_25 ( V_48 -> V_51 + V_78 ) ;
if ( ! V_74 )
V_39 |= F_26 ( V_12 ) ;
else
V_39 &= ~ F_26 ( V_12 ) ;
F_34 ( V_39 , V_48 -> V_51 + V_78 ) ;
return 0 ;
}
static bool F_35 ( struct V_57 * V_14 ,
enum V_79 V_64 )
{
if ( ! V_14 -> V_58 )
return V_64 ? false : true ;
if ( V_14 -> V_60 ) {
if ( V_64 != V_62 &&
V_64 != V_59 )
return false ;
} else {
if ( V_64 == V_62 )
return false ;
}
return true ;
}
static int F_36 ( struct V_22 * V_23 , unsigned int V_12 ,
unsigned long V_80 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_12 ) ;
enum V_79 V_81 = F_37 ( V_80 ) ;
T_4 V_82 = F_38 ( V_80 ) ;
switch ( V_81 ) {
case V_59 :
return F_27 ( V_48 , V_12 - V_48 -> V_16 , V_81 ) ;
break;
case V_83 :
case V_84 :
case V_62 :
if ( ! F_35 ( V_6 -> V_14 , V_81 ) )
return - V_85 ;
if ( ! V_82 )
return - V_21 ;
return F_27 ( V_48 , V_12 - V_48 -> V_16 , V_81 ) ;
break;
default:
return - V_85 ;
break;
}
return 0 ;
}
static int F_39 ( struct V_22 * V_23 , unsigned int V_12 ,
unsigned long * V_80 )
{
struct V_5 * V_6 = F_8 ( V_23 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_12 ) ;
enum V_79 V_81 = F_37 ( * V_80 ) ;
switch ( V_81 ) {
case V_59 :
if ( F_24 ( V_48 , V_12 - V_48 -> V_16 ) != V_81 )
return - V_21 ;
* V_80 = 0 ;
break;
case V_83 :
case V_84 :
case V_62 :
if ( ! F_35 ( V_6 -> V_14 , V_81 ) )
return - V_85 ;
if ( F_24 ( V_48 , V_12 - V_48 -> V_16 ) != V_81 )
return - V_21 ;
* V_80 = 1 ;
break;
default:
return - V_85 ;
break;
}
return 0 ;
}
static void F_40 ( struct V_5 * V_6 ,
struct V_27 * V_28 )
{
struct V_27 * V_86 ;
F_41 (np, child) {
if ( F_42 ( V_86 , V_87 ) )
continue;
V_6 -> V_65 ++ ;
V_6 -> V_10 += F_43 ( V_86 ) ;
}
}
static int F_44 ( struct V_27 * V_28 ,
struct V_4 * V_8 ,
struct V_5 * V_6 ,
T_3 V_88 )
{
struct V_1 * V_48 ;
int V_89 ;
const T_5 * V_90 ;
int V_18 ;
int V_9 , V_91 ;
int V_92 ;
F_18 ( V_6 -> V_35 , L_13 , V_88 , V_28 -> V_7 ) ;
V_8 -> V_7 = V_28 -> V_7 ;
V_90 = F_45 ( V_28 , L_14 , & V_89 ) ;
V_89 /= sizeof( * V_90 ) ;
if ( ! V_89 || V_89 % 4 ) {
F_12 ( V_6 -> V_35 , L_15 ) ;
return - V_21 ;
}
V_8 -> V_26 = V_89 / 4 ;
V_8 -> V_25 = F_13 ( V_6 -> V_35 , V_8 -> V_26 * sizeof( unsigned int ) ,
V_36 ) ;
V_8 -> V_39 = F_13 ( V_6 -> V_35 , V_8 -> V_26 *
sizeof( struct V_68 ) ,
V_36 ) ;
if ( ! V_8 -> V_25 || ! V_8 -> V_39 )
return - V_37 ;
for ( V_9 = 0 , V_91 = 0 ; V_9 < V_89 ; V_9 += 4 , V_91 ++ ) {
const T_5 * V_93 ;
struct V_27 * V_94 ;
V_18 = F_46 ( * V_90 ++ ) ;
V_48 = F_5 ( V_6 , V_18 ) ;
if ( F_47 ( V_48 ) )
return F_48 ( V_48 ) ;
V_8 -> V_25 [ V_91 ] = V_48 -> V_16 + F_46 ( * V_90 ++ ) ;
V_8 -> V_39 [ V_91 ] . V_70 = F_46 ( * V_90 ++ ) ;
V_93 = V_90 ++ ;
if ( ! V_93 )
return - V_21 ;
V_94 = F_49 ( F_50 ( V_93 ) ) ;
V_92 = F_51 ( V_94 ,
& V_8 -> V_39 [ V_91 ] . V_44 , & V_8 -> V_39 [ V_91 ] . V_47 ) ;
if ( V_92 )
return V_92 ;
}
return 0 ;
}
static int F_52 ( struct V_27 * V_28 ,
struct V_5 * V_6 ,
T_3 V_88 )
{
struct V_27 * V_86 ;
struct V_95 * V_70 ;
struct V_4 * V_8 ;
int V_92 ;
static T_3 V_96 ;
T_3 V_9 = 0 ;
F_18 ( V_6 -> V_35 , L_16 , V_88 , V_28 -> V_7 ) ;
V_70 = & V_6 -> V_66 [ V_88 ] ;
V_70 -> V_7 = V_28 -> V_7 ;
V_70 -> V_10 = F_43 ( V_28 ) ;
if ( V_70 -> V_10 <= 0 )
return 0 ;
V_70 -> V_11 = F_13 ( V_6 -> V_35 ,
V_70 -> V_10 * sizeof( char * ) , V_36 ) ;
if ( ! V_70 -> V_11 )
return - V_37 ;
F_41 (np, child) {
V_70 -> V_11 [ V_9 ] = V_86 -> V_7 ;
V_8 = & V_6 -> V_11 [ V_96 ++ ] ;
V_92 = F_44 ( V_86 , V_8 , V_6 , V_9 ++ ) ;
if ( V_92 )
return V_92 ;
}
return 0 ;
}
static int F_53 ( struct V_97 * V_98 ,
struct V_5 * V_6 )
{
struct V_99 * V_35 = & V_98 -> V_35 ;
struct V_27 * V_28 = V_35 -> V_100 ;
struct V_27 * V_86 ;
int V_92 ;
int V_9 ;
F_40 ( V_6 , V_28 ) ;
F_18 ( & V_98 -> V_35 , L_17 , V_6 -> V_65 ) ;
F_18 ( & V_98 -> V_35 , L_18 , V_6 -> V_10 ) ;
V_6 -> V_66 = F_13 ( V_35 , V_6 -> V_65 *
sizeof( struct V_95 ) ,
V_36 ) ;
if ( ! V_6 -> V_66 ) {
F_12 ( V_35 , L_19 ) ;
return - V_21 ;
}
V_6 -> V_11 = F_13 ( V_35 , V_6 -> V_10 *
sizeof( struct V_4 ) ,
V_36 ) ;
if ( ! V_6 -> V_11 ) {
F_12 ( V_35 , L_20 ) ;
return - V_21 ;
}
V_9 = 0 ;
F_41 (np, child) {
if ( F_42 ( V_86 , V_87 ) )
continue;
V_92 = F_52 ( V_86 , V_6 , V_9 ++ ) ;
if ( V_92 ) {
F_12 ( & V_98 -> V_35 , L_21 ) ;
return V_92 ;
}
}
return 0 ;
}
static int F_54 ( struct V_97 * V_98 ,
struct V_5 * V_6 )
{
struct V_101 * V_102 = & V_6 -> V_103 ;
struct V_104 * V_105 , * V_106 ;
struct V_1 * V_107 ;
int V_12 , V_48 , V_92 ;
int V_108 ;
V_102 -> V_7 = L_22 ;
V_102 -> V_109 = V_110 ;
V_102 -> V_111 = & V_112 ;
V_102 -> V_113 = & V_114 ;
V_102 -> V_115 = & V_116 ;
V_105 = F_13 ( & V_98 -> V_35 , sizeof( * V_105 ) *
V_6 -> V_14 -> V_17 , V_36 ) ;
if ( ! V_105 ) {
F_12 ( & V_98 -> V_35 , L_23 ) ;
return - V_37 ;
}
V_102 -> V_25 = V_105 ;
V_102 -> V_26 = V_6 -> V_14 -> V_17 ;
V_106 = V_105 ;
for ( V_48 = 0 , V_108 = 0 ; V_48 < V_6 -> V_14 -> V_19 ; V_48 ++ ) {
V_107 = & V_6 -> V_14 -> V_15 [ V_48 ] ;
for ( V_12 = 0 ; V_12 < V_107 -> V_17 ; V_12 ++ , V_108 ++ ) {
V_106 -> V_117 = V_108 ;
V_106 -> V_7 = F_55 ( V_36 , L_24 ,
V_107 -> V_7 , V_12 ) ;
V_106 ++ ;
}
}
V_6 -> V_118 = F_56 ( V_102 , & V_98 -> V_35 , V_6 ) ;
if ( ! V_6 -> V_118 ) {
F_12 ( & V_98 -> V_35 , L_25 ) ;
return - V_21 ;
}
for ( V_48 = 0 ; V_48 < V_6 -> V_14 -> V_19 ; ++ V_48 ) {
V_107 = & V_6 -> V_14 -> V_15 [ V_48 ] ;
V_107 -> V_119 . V_7 = V_107 -> V_7 ;
V_107 -> V_119 . V_120 = V_48 ;
V_107 -> V_119 . V_16 = V_107 -> V_16 ;
V_107 -> V_119 . V_76 = V_107 -> V_2 . V_76 ;
V_107 -> V_119 . V_26 = V_107 -> V_2 . V_121 ;
V_107 -> V_119 . V_3 = & V_107 -> V_2 ;
F_57 ( V_6 -> V_118 , & V_107 -> V_119 ) ;
}
V_92 = F_53 ( V_98 , V_6 ) ;
if ( V_92 ) {
F_58 ( V_6 -> V_118 ) ;
return V_92 ;
}
return 0 ;
}
static void F_59 ( struct V_2 * V_3 , unsigned V_73 , int V_122 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
void T_1 * V_50 = V_48 -> V_51 + V_123 ;
unsigned long V_53 ;
T_3 V_39 ;
F_21 ( & V_48 -> V_55 , V_53 ) ;
V_39 = F_60 ( V_50 ) ;
V_39 &= ~ F_26 ( V_73 ) ;
if ( V_122 )
V_39 |= F_26 ( V_73 ) ;
F_22 ( V_39 , V_50 ) ;
F_23 ( & V_48 -> V_55 , V_53 ) ;
}
static int F_61 ( struct V_2 * V_3 , unsigned V_73 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
T_3 V_39 ;
V_39 = F_60 ( V_48 -> V_51 + V_124 ) ;
V_39 >>= V_73 ;
V_39 &= 1 ;
return V_39 ;
}
static int F_62 ( struct V_2 * V_3 , unsigned V_73 )
{
return F_63 ( V_3 -> V_76 + V_73 ) ;
}
static int F_64 ( struct V_2 * V_3 ,
unsigned V_73 , int V_122 )
{
F_59 ( V_3 , V_73 , V_122 ) ;
return F_65 ( V_3 -> V_76 + V_73 ) ;
}
static int F_66 ( struct V_2 * V_3 , unsigned V_73 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
unsigned int V_125 ;
if ( ! V_48 -> V_126 )
return - V_127 ;
V_125 = F_67 ( V_48 -> V_126 , V_73 ) ;
return ( V_125 ) ? : - V_127 ;
}
static void F_68 ( unsigned int V_128 , struct V_129 * V_130 )
{
struct V_131 * V_75 = F_69 ( V_128 ) ;
struct V_1 * V_48 = F_70 ( V_128 ) ;
T_3 V_132 ;
F_18 ( V_48 -> V_49 -> V_35 , L_26 , V_48 -> V_7 ) ;
F_71 ( V_75 , V_130 ) ;
V_132 = F_25 ( V_48 -> V_51 + V_133 ) ;
while ( V_132 ) {
unsigned int V_125 ;
V_128 = F_72 ( V_132 ) ;
V_132 &= ~ F_26 ( V_128 ) ;
V_125 = F_73 ( V_48 -> V_126 , V_128 ) ;
if ( ! V_125 ) {
F_12 ( V_48 -> V_49 -> V_35 , L_27 , V_128 ) ;
continue;
}
F_18 ( V_48 -> V_49 -> V_35 , L_28 , V_128 ) ;
F_74 ( V_125 ) ;
}
F_75 ( V_75 , V_130 ) ;
}
static int F_76 ( struct V_134 * V_135 , unsigned int type )
{
struct V_136 * V_3 = F_77 ( V_135 ) ;
struct V_1 * V_48 = V_3 -> V_137 ;
T_3 V_138 = F_26 ( V_135 -> V_139 ) ;
T_3 V_140 ;
T_3 V_141 ;
T_3 V_39 ;
if ( type & V_142 )
F_78 ( V_135 -> V_128 , V_143 ) ;
else
F_78 ( V_135 -> V_128 , V_144 ) ;
F_79 ( V_3 ) ;
V_141 = F_25 ( V_3 -> V_51 + V_145 ) ;
V_140 = F_25 ( V_3 -> V_51 + V_146 ) ;
switch ( type ) {
case V_147 :
V_141 |= V_138 ;
V_140 |= V_138 ;
break;
case V_148 :
V_141 |= V_138 ;
V_140 &= ~ V_138 ;
break;
case V_149 :
V_141 &= ~ V_138 ;
V_140 |= V_138 ;
break;
case V_150 :
V_141 &= ~ V_138 ;
V_140 &= ~ V_138 ;
break;
default:
F_80 ( V_3 ) ;
return - V_21 ;
}
F_34 ( V_141 , V_3 -> V_51 + V_145 ) ;
F_34 ( V_140 , V_3 -> V_51 + V_146 ) ;
F_80 ( V_3 ) ;
F_20 ( V_48 , V_135 -> V_139 , V_77 ) ;
V_39 = F_25 ( V_48 -> V_51 + V_78 ) ;
V_39 &= ~ V_138 ;
F_34 ( V_39 , V_48 -> V_51 + V_78 ) ;
return 0 ;
}
static int F_81 ( struct V_97 * V_98 ,
struct V_5 * V_6 )
{
struct V_57 * V_14 = V_6 -> V_14 ;
struct V_1 * V_48 = V_14 -> V_15 ;
unsigned int V_151 = V_152 | V_153 | V_154 ;
struct V_136 * V_3 ;
int V_92 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_14 -> V_19 ; ++ V_9 , ++ V_48 ) {
if ( ! V_48 -> V_155 ) {
F_82 ( & V_98 -> V_35 , L_29 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_126 = F_83 ( V_48 -> V_100 , 32 ,
& V_156 , NULL ) ;
if ( ! V_48 -> V_126 ) {
F_82 ( & V_98 -> V_35 , L_30 ,
V_48 -> V_7 ) ;
continue;
}
V_92 = F_84 ( V_48 -> V_126 , 32 , 1 ,
L_31 , V_144 ,
V_151 , 0 , V_157 ) ;
if ( V_92 ) {
F_12 ( & V_98 -> V_35 , L_32 ,
V_48 -> V_7 ) ;
F_85 ( V_48 -> V_126 ) ;
continue;
}
V_3 = F_86 ( V_48 -> V_126 , 0 ) ;
V_3 -> V_51 = V_48 -> V_51 ;
V_3 -> V_137 = V_48 ;
V_3 -> V_158 [ 0 ] . V_159 . V_138 = V_160 ;
V_3 -> V_158 [ 0 ] . V_159 . V_161 = V_162 ;
V_3 -> V_158 [ 0 ] . V_75 . V_163 = V_164 ;
V_3 -> V_158 [ 0 ] . V_75 . V_165 = V_166 ;
V_3 -> V_158 [ 0 ] . V_75 . V_167 = V_168 ;
V_3 -> V_158 [ 0 ] . V_75 . V_169 = V_170 ;
V_3 -> V_158 [ 0 ] . V_75 . V_171 = F_76 ;
F_87 ( V_48 -> V_128 , V_48 ) ;
F_88 ( V_48 -> V_128 , F_68 ) ;
}
return 0 ;
}
static int F_89 ( struct V_97 * V_98 ,
struct V_5 * V_6 )
{
struct V_57 * V_14 = V_6 -> V_14 ;
struct V_1 * V_48 = V_14 -> V_15 ;
struct V_2 * V_3 ;
int V_92 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_14 -> V_19 ; ++ V_9 , ++ V_48 ) {
if ( ! V_48 -> V_155 ) {
F_82 ( & V_98 -> V_35 , L_29 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_2 = V_172 ;
V_3 = & V_48 -> V_2 ;
V_3 -> V_76 = V_48 -> V_16 ;
V_3 -> V_121 = V_48 -> V_17 ;
V_3 -> V_35 = & V_98 -> V_35 ;
V_3 -> V_100 = V_48 -> V_100 ;
V_3 -> V_173 = V_48 -> V_7 ;
V_92 = F_90 ( V_3 ) ;
if ( V_92 ) {
F_12 ( & V_98 -> V_35 , L_33 ,
V_3 -> V_173 , V_92 ) ;
goto V_174;
}
}
F_81 ( V_98 , V_6 ) ;
return 0 ;
V_174:
for ( -- V_9 , -- V_48 ; V_9 >= 0 ; -- V_9 , -- V_48 ) {
if ( ! V_48 -> V_155 )
continue;
if ( F_91 ( & V_48 -> V_2 ) )
F_12 ( & V_98 -> V_35 , L_34 ,
V_48 -> V_2 . V_173 ) ;
}
return V_92 ;
}
static int F_92 ( struct V_97 * V_98 ,
struct V_5 * V_6 )
{
struct V_57 * V_14 = V_6 -> V_14 ;
struct V_1 * V_48 = V_14 -> V_15 ;
int V_92 = 0 ;
int V_9 ;
for ( V_9 = 0 ; ! V_92 && V_9 < V_14 -> V_19 ; ++ V_9 , ++ V_48 ) {
if ( ! V_48 -> V_155 )
continue;
V_92 = F_91 ( & V_48 -> V_2 ) ;
}
if ( V_92 )
F_12 ( & V_98 -> V_35 , L_35 ) ;
return V_92 ;
}
static int F_93 ( struct V_1 * V_48 ,
struct V_99 * V_35 )
{
struct V_175 V_176 ;
if ( F_94 ( V_48 -> V_100 , 0 , & V_176 ) ) {
F_12 ( V_35 , L_36 ) ;
return - V_177 ;
}
V_48 -> V_51 = F_95 ( V_35 , & V_176 ) ;
if ( F_47 ( V_48 -> V_51 ) )
return F_48 ( V_48 -> V_51 ) ;
V_48 -> V_128 = F_96 ( V_48 -> V_100 , 0 ) ;
V_48 -> V_178 = F_97 ( V_48 -> V_100 , 0 ) ;
if ( F_47 ( V_48 -> V_178 ) )
return F_48 ( V_48 -> V_178 ) ;
return F_98 ( V_48 -> V_178 ) ;
}
static struct V_57 * F_99 (
struct V_5 * V_135 ,
struct V_97 * V_98 )
{
const struct V_179 * V_180 ;
struct V_27 * V_181 = V_98 -> V_35 . V_100 ;
struct V_27 * V_28 ;
struct V_57 * V_14 ;
struct V_1 * V_48 ;
int V_9 ;
V_180 = F_100 ( V_182 , V_181 ) ;
V_14 = (struct V_57 * ) V_180 -> V_39 ;
F_41 (node, np) {
if ( ! F_101 ( V_28 , L_37 , NULL ) )
continue;
V_48 = V_14 -> V_15 ;
for ( V_9 = 0 ; V_9 < V_14 -> V_19 ; ++ V_9 , ++ V_48 ) {
if ( ! strcmp ( V_48 -> V_7 , V_28 -> V_7 ) ) {
V_48 -> V_100 = V_28 ;
if ( ! F_93 ( V_48 , & V_98 -> V_35 ) )
V_48 -> V_155 = true ;
break;
}
}
}
V_48 = V_14 -> V_15 ;
for ( V_9 = 0 ; V_9 < V_14 -> V_19 ; ++ V_9 , ++ V_48 ) {
F_102 ( & V_48 -> V_55 ) ;
V_48 -> V_49 = V_135 ;
V_48 -> V_16 = V_14 -> V_17 ;
V_14 -> V_17 += V_48 -> V_17 ;
}
return V_14 ;
}
static int F_103 ( struct V_97 * V_98 )
{
struct V_5 * V_6 ;
struct V_99 * V_35 = & V_98 -> V_35 ;
struct V_57 * V_14 ;
struct V_175 * V_176 ;
int V_92 ;
if ( ! V_35 -> V_100 ) {
F_12 ( V_35 , L_38 ) ;
return - V_183 ;
}
V_6 = F_13 ( V_35 , sizeof( struct V_5 ) , V_36 ) ;
if ( ! V_6 )
return - V_37 ;
V_14 = F_99 ( V_6 , V_98 ) ;
if ( ! V_14 ) {
F_12 ( V_35 , L_39 ) ;
return - V_21 ;
}
V_6 -> V_14 = V_14 ;
V_6 -> V_35 = V_35 ;
V_176 = F_104 ( V_98 , V_184 , 0 ) ;
if ( ! V_176 ) {
F_12 ( V_35 , L_40 ) ;
return - V_177 ;
}
V_6 -> V_51 = F_95 ( & V_98 -> V_35 , V_176 ) ;
if ( F_47 ( V_6 -> V_51 ) )
return F_48 ( V_6 -> V_51 ) ;
V_92 = F_89 ( V_98 , V_6 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_54 ( V_98 , V_6 ) ;
if ( V_92 ) {
F_92 ( V_98 , V_6 ) ;
return V_92 ;
}
F_105 ( V_98 , V_6 ) ;
return 0 ;
}
static int T_6 F_106 ( void )
{
return F_107 ( & V_185 ) ;
}
