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
static void F_20 ( struct V_1 * V_48 , int V_11 , int V_40 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
void T_1 * V_50 = V_6 -> V_51 + V_6 -> V_13 -> V_52 ;
unsigned long V_53 ;
T_2 V_54 ;
T_3 V_39 ;
F_18 ( V_6 -> V_35 , L_3 ,
V_48 -> V_19 , V_11 , V_40 ) ;
V_50 += V_48 -> V_19 * 0x10 ;
V_50 += ( V_11 / 8 ) * 4 ;
V_54 = ( V_11 % 8 ) * 2 ;
F_21 ( & V_48 -> V_55 , V_53 ) ;
V_39 = ( 3 << ( V_54 + 16 ) ) ;
V_39 |= ( V_40 & 3 ) << V_54 ;
F_22 ( V_39 , V_50 ) ;
F_23 ( & V_48 -> V_55 , V_53 ) ;
}
static int F_24 ( struct V_1 * V_48 , int V_56 )
{
struct V_5 * V_6 = V_48 -> V_49 ;
struct V_57 * V_13 = V_6 -> V_13 ;
void T_1 * V_50 ;
T_2 V_54 ;
if ( ! V_13 -> V_58 )
return V_59 ;
V_50 = V_6 -> V_51 + V_13 -> V_58 ;
if ( V_13 -> V_60 ) {
V_50 += V_48 -> V_19 * V_13 -> V_61 ;
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
struct V_57 * V_13 = V_6 -> V_13 ;
void T_1 * V_50 ;
unsigned long V_53 ;
T_2 V_54 ;
T_3 V_39 ;
F_18 ( V_6 -> V_35 , L_5 ,
V_48 -> V_19 , V_56 , V_64 ) ;
if ( ! V_13 -> V_58 )
return V_64 ? - V_20 : 0 ;
V_50 = V_6 -> V_51 + V_13 -> V_58 ;
if ( V_13 -> V_60 ) {
if ( V_64 != V_62 &&
V_64 != V_59 ) {
F_12 ( V_6 -> V_35 , L_6 ) ;
return - V_20 ;
}
V_50 += V_48 -> V_19 * V_13 -> V_61 ;
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
return - V_20 ;
}
F_12 ( V_6 -> V_35 , L_4 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_28 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_65 ;
}
static const char * F_29 ( struct V_21 * V_22 ,
unsigned V_23 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
return V_6 -> V_66 [ V_23 ] . V_7 ;
}
static int F_30 ( struct V_21 * V_22 ,
unsigned V_23 , const char * const * * V_10 ,
unsigned * const V_67 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
* V_10 = V_6 -> V_66 [ V_23 ] . V_10 ;
* V_67 = V_6 -> V_66 [ V_23 ] . V_9 ;
return 0 ;
}
static int F_31 ( struct V_21 * V_22 , unsigned V_23 ,
unsigned V_42 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
const unsigned int * V_24 = V_6 -> V_10 [ V_42 ] . V_24 ;
const struct V_68 * V_39 = V_6 -> V_10 [ V_42 ] . V_39 ;
struct V_1 * V_48 ;
int V_69 ;
F_18 ( V_6 -> V_35 , L_8 ,
V_6 -> V_66 [ V_23 ] . V_7 , V_6 -> V_10 [ V_42 ] . V_7 ) ;
for ( V_69 = 0 ; V_69 < V_6 -> V_10 [ V_42 ] . V_25 ; V_69 ++ ) {
V_48 = F_4 ( V_6 , V_24 [ V_69 ] ) ;
F_20 ( V_48 , V_24 [ V_69 ] - V_48 -> V_15 ,
V_39 [ V_69 ] . V_70 ) ;
}
return 0 ;
}
static void F_32 ( struct V_21 * V_22 ,
unsigned V_23 , unsigned V_42 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
const unsigned int * V_24 = V_6 -> V_10 [ V_42 ] . V_24 ;
struct V_1 * V_48 ;
int V_69 ;
F_18 ( V_6 -> V_35 , L_9 ,
V_6 -> V_66 [ V_23 ] . V_7 , V_6 -> V_10 [ V_42 ] . V_7 ) ;
for ( V_69 = 0 ; V_69 < V_6 -> V_10 [ V_42 ] . V_25 ; V_69 ++ ) {
V_48 = F_4 ( V_6 , V_24 [ V_69 ] ) ;
F_20 ( V_48 , V_24 [ V_69 ] - V_48 -> V_15 , 0 ) ;
}
}
static int F_33 ( struct V_21 * V_22 ,
struct V_71 * V_72 ,
unsigned V_73 , bool V_74 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 ;
struct V_2 * V_75 ;
int V_11 ;
T_3 V_39 ;
V_75 = V_72 -> V_3 ;
V_48 = F_1 ( V_75 ) ;
V_11 = V_73 - V_75 -> V_76 ;
F_18 ( V_6 -> V_35 , L_10 ,
V_73 , V_72 -> V_7 , V_11 , V_74 ? L_11 : L_12 ) ;
F_20 ( V_48 , V_11 , V_77 ) ;
V_39 = F_25 ( V_48 -> V_51 + V_78 ) ;
if ( ! V_74 )
V_39 |= F_26 ( V_11 ) ;
else
V_39 &= ~ F_26 ( V_11 ) ;
F_34 ( V_39 , V_48 -> V_51 + V_78 ) ;
return 0 ;
}
static bool F_35 ( struct V_57 * V_13 ,
enum V_79 V_64 )
{
if ( ! V_13 -> V_58 )
return V_64 ? false : true ;
if ( V_13 -> V_60 ) {
if ( V_64 != V_62 &&
V_64 != V_59 )
return false ;
} else {
if ( V_64 == V_62 )
return false ;
}
return true ;
}
static int F_36 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_44 , unsigned V_46 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_79 V_80 ;
T_4 V_81 ;
int V_8 ;
int V_82 ;
for ( V_8 = 0 ; V_8 < V_46 ; V_8 ++ ) {
V_80 = F_37 ( V_44 [ V_8 ] ) ;
V_81 = F_38 ( V_44 [ V_8 ] ) ;
switch ( V_80 ) {
case V_59 :
V_82 = F_27 ( V_48 , V_11 - V_48 -> V_15 ,
V_80 ) ;
if ( V_82 )
return V_82 ;
break;
case V_83 :
case V_84 :
case V_62 :
if ( ! F_35 ( V_6 -> V_13 , V_80 ) )
return - V_85 ;
if ( ! V_81 )
return - V_20 ;
V_82 = F_27 ( V_48 , V_11 - V_48 -> V_15 ,
V_80 ) ;
if ( V_82 )
return V_82 ;
break;
default:
return - V_85 ;
break;
}
}
return 0 ;
}
static int F_39 ( struct V_21 * V_22 , unsigned int V_11 ,
unsigned long * V_86 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_1 * V_48 = F_4 ( V_6 , V_11 ) ;
enum V_79 V_80 = F_37 ( * V_86 ) ;
switch ( V_80 ) {
case V_59 :
if ( F_24 ( V_48 , V_11 - V_48 -> V_15 ) != V_80 )
return - V_20 ;
* V_86 = 0 ;
break;
case V_83 :
case V_84 :
case V_62 :
if ( ! F_35 ( V_6 -> V_13 , V_80 ) )
return - V_85 ;
if ( F_24 ( V_48 , V_11 - V_48 -> V_15 ) != V_80 )
return - V_20 ;
* V_86 = 1 ;
break;
default:
return - V_85 ;
break;
}
return 0 ;
}
static void F_40 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
struct V_26 * V_87 ;
F_41 (np, child) {
if ( F_42 ( V_87 , V_88 ) )
continue;
V_6 -> V_65 ++ ;
V_6 -> V_9 += F_43 ( V_87 ) ;
}
}
static int F_44 ( struct V_26 * V_27 ,
struct V_4 * V_31 ,
struct V_5 * V_6 ,
T_3 V_89 )
{
struct V_1 * V_48 ;
int V_90 ;
const T_5 * V_91 ;
int V_17 ;
int V_8 , V_92 ;
int V_93 ;
F_18 ( V_6 -> V_35 , L_13 , V_89 , V_27 -> V_7 ) ;
V_31 -> V_7 = V_27 -> V_7 ;
V_91 = F_45 ( V_27 , L_14 , & V_90 ) ;
V_90 /= sizeof( * V_91 ) ;
if ( ! V_90 || V_90 % 4 ) {
F_12 ( V_6 -> V_35 , L_15 ) ;
return - V_20 ;
}
V_31 -> V_25 = V_90 / 4 ;
V_31 -> V_24 = F_13 ( V_6 -> V_35 , V_31 -> V_25 * sizeof( unsigned int ) ,
V_36 ) ;
V_31 -> V_39 = F_13 ( V_6 -> V_35 , V_31 -> V_25 *
sizeof( struct V_68 ) ,
V_36 ) ;
if ( ! V_31 -> V_24 || ! V_31 -> V_39 )
return - V_37 ;
for ( V_8 = 0 , V_92 = 0 ; V_8 < V_90 ; V_8 += 4 , V_92 ++ ) {
const T_5 * V_94 ;
struct V_26 * V_95 ;
V_17 = F_46 ( * V_91 ++ ) ;
V_48 = F_5 ( V_6 , V_17 ) ;
if ( F_47 ( V_48 ) )
return F_48 ( V_48 ) ;
V_31 -> V_24 [ V_92 ] = V_48 -> V_15 + F_46 ( * V_91 ++ ) ;
V_31 -> V_39 [ V_92 ] . V_70 = F_46 ( * V_91 ++ ) ;
V_94 = V_91 ++ ;
if ( ! V_94 )
return - V_20 ;
V_95 = F_49 ( F_50 ( V_94 ) ) ;
V_93 = F_51 ( V_95 ,
& V_31 -> V_39 [ V_92 ] . V_44 , & V_31 -> V_39 [ V_92 ] . V_47 ) ;
if ( V_93 )
return V_93 ;
}
return 0 ;
}
static int F_52 ( struct V_26 * V_27 ,
struct V_5 * V_6 ,
T_3 V_89 )
{
struct V_26 * V_87 ;
struct V_96 * V_70 ;
struct V_4 * V_31 ;
int V_93 ;
static T_3 V_97 ;
T_3 V_8 = 0 ;
F_18 ( V_6 -> V_35 , L_16 , V_89 , V_27 -> V_7 ) ;
V_70 = & V_6 -> V_66 [ V_89 ] ;
V_70 -> V_7 = V_27 -> V_7 ;
V_70 -> V_9 = F_43 ( V_27 ) ;
if ( V_70 -> V_9 <= 0 )
return 0 ;
V_70 -> V_10 = F_13 ( V_6 -> V_35 ,
V_70 -> V_9 * sizeof( char * ) , V_36 ) ;
if ( ! V_70 -> V_10 )
return - V_37 ;
F_41 (np, child) {
V_70 -> V_10 [ V_8 ] = V_87 -> V_7 ;
V_31 = & V_6 -> V_10 [ V_97 ++ ] ;
V_93 = F_44 ( V_87 , V_31 , V_6 , V_8 ++ ) ;
if ( V_93 )
return V_93 ;
}
return 0 ;
}
static int F_53 ( struct V_98 * V_99 ,
struct V_5 * V_6 )
{
struct V_100 * V_35 = & V_99 -> V_35 ;
struct V_26 * V_27 = V_35 -> V_101 ;
struct V_26 * V_87 ;
int V_93 ;
int V_8 ;
F_40 ( V_6 , V_27 ) ;
F_18 ( & V_99 -> V_35 , L_17 , V_6 -> V_65 ) ;
F_18 ( & V_99 -> V_35 , L_18 , V_6 -> V_9 ) ;
V_6 -> V_66 = F_13 ( V_35 , V_6 -> V_65 *
sizeof( struct V_96 ) ,
V_36 ) ;
if ( ! V_6 -> V_66 ) {
F_12 ( V_35 , L_19 ) ;
return - V_20 ;
}
V_6 -> V_10 = F_13 ( V_35 , V_6 -> V_9 *
sizeof( struct V_4 ) ,
V_36 ) ;
if ( ! V_6 -> V_10 ) {
F_12 ( V_35 , L_20 ) ;
return - V_20 ;
}
V_8 = 0 ;
F_41 (np, child) {
if ( F_42 ( V_87 , V_88 ) )
continue;
V_93 = F_52 ( V_87 , V_6 , V_8 ++ ) ;
if ( V_93 ) {
F_12 ( & V_99 -> V_35 , L_21 ) ;
return V_93 ;
}
}
return 0 ;
}
static int F_54 ( struct V_98 * V_99 ,
struct V_5 * V_6 )
{
struct V_102 * V_103 = & V_6 -> V_104 ;
struct V_105 * V_106 , * V_107 ;
struct V_1 * V_108 ;
int V_11 , V_48 , V_93 ;
int V_109 ;
V_103 -> V_7 = L_22 ;
V_103 -> V_110 = V_111 ;
V_103 -> V_112 = & V_113 ;
V_103 -> V_114 = & V_115 ;
V_103 -> V_116 = & V_117 ;
V_106 = F_13 ( & V_99 -> V_35 , sizeof( * V_106 ) *
V_6 -> V_13 -> V_16 , V_36 ) ;
if ( ! V_106 ) {
F_12 ( & V_99 -> V_35 , L_23 ) ;
return - V_37 ;
}
V_103 -> V_24 = V_106 ;
V_103 -> V_25 = V_6 -> V_13 -> V_16 ;
V_107 = V_106 ;
for ( V_48 = 0 , V_109 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; V_48 ++ ) {
V_108 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
for ( V_11 = 0 ; V_11 < V_108 -> V_16 ; V_11 ++ , V_109 ++ ) {
V_107 -> V_118 = V_109 ;
V_107 -> V_7 = F_55 ( V_36 , L_24 ,
V_108 -> V_7 , V_11 ) ;
V_107 ++ ;
}
}
V_6 -> V_119 = F_56 ( V_103 , & V_99 -> V_35 , V_6 ) ;
if ( ! V_6 -> V_119 ) {
F_12 ( & V_99 -> V_35 , L_25 ) ;
return - V_20 ;
}
for ( V_48 = 0 ; V_48 < V_6 -> V_13 -> V_18 ; ++ V_48 ) {
V_108 = & V_6 -> V_13 -> V_14 [ V_48 ] ;
V_108 -> V_120 . V_7 = V_108 -> V_7 ;
V_108 -> V_120 . V_121 = V_48 ;
V_108 -> V_120 . V_15 = V_108 -> V_15 ;
V_108 -> V_120 . V_76 = V_108 -> V_2 . V_76 ;
V_108 -> V_120 . V_25 = V_108 -> V_2 . V_122 ;
V_108 -> V_120 . V_3 = & V_108 -> V_2 ;
F_57 ( V_6 -> V_119 , & V_108 -> V_120 ) ;
}
V_93 = F_53 ( V_99 , V_6 ) ;
if ( V_93 ) {
F_58 ( V_6 -> V_119 ) ;
return V_93 ;
}
return 0 ;
}
static int F_59 ( struct V_2 * V_75 , unsigned V_73 )
{
return F_60 ( V_75 -> V_76 + V_73 ) ;
}
static void F_61 ( struct V_2 * V_75 , unsigned V_73 )
{
F_62 ( V_75 -> V_76 + V_73 ) ;
}
static void F_63 ( struct V_2 * V_3 , unsigned V_73 , int V_123 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
void T_1 * V_50 = V_48 -> V_51 + V_124 ;
unsigned long V_53 ;
T_3 V_39 ;
F_21 ( & V_48 -> V_55 , V_53 ) ;
V_39 = F_64 ( V_50 ) ;
V_39 &= ~ F_26 ( V_73 ) ;
if ( V_123 )
V_39 |= F_26 ( V_73 ) ;
F_22 ( V_39 , V_50 ) ;
F_23 ( & V_48 -> V_55 , V_53 ) ;
}
static int F_65 ( struct V_2 * V_3 , unsigned V_73 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
T_3 V_39 ;
V_39 = F_64 ( V_48 -> V_51 + V_125 ) ;
V_39 >>= V_73 ;
V_39 &= 1 ;
return V_39 ;
}
static int F_66 ( struct V_2 * V_3 , unsigned V_73 )
{
return F_67 ( V_3 -> V_76 + V_73 ) ;
}
static int F_68 ( struct V_2 * V_3 ,
unsigned V_73 , int V_123 )
{
F_63 ( V_3 , V_73 , V_123 ) ;
return F_69 ( V_3 -> V_76 + V_73 ) ;
}
static int F_70 ( struct V_2 * V_3 , unsigned V_73 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
unsigned int V_126 ;
if ( ! V_48 -> V_127 )
return - V_128 ;
V_126 = F_71 ( V_48 -> V_127 , V_73 ) ;
return ( V_126 ) ? : - V_128 ;
}
static void F_72 ( unsigned int V_129 , struct V_130 * V_131 )
{
struct V_132 * V_75 = F_73 ( V_129 ) ;
struct V_1 * V_48 = F_74 ( V_129 ) ;
T_3 V_133 ;
F_18 ( V_48 -> V_49 -> V_35 , L_26 , V_48 -> V_7 ) ;
F_75 ( V_75 , V_131 ) ;
V_133 = F_25 ( V_48 -> V_51 + V_134 ) ;
while ( V_133 ) {
unsigned int V_126 ;
V_129 = F_76 ( V_133 ) ;
V_133 &= ~ F_26 ( V_129 ) ;
V_126 = F_77 ( V_48 -> V_127 , V_129 ) ;
if ( ! V_126 ) {
F_12 ( V_48 -> V_49 -> V_35 , L_27 , V_129 ) ;
continue;
}
F_18 ( V_48 -> V_49 -> V_35 , L_28 , V_129 ) ;
F_78 ( V_126 ) ;
}
F_79 ( V_75 , V_131 ) ;
}
static int F_80 ( struct V_135 * V_136 , unsigned int type )
{
struct V_137 * V_3 = F_81 ( V_136 ) ;
struct V_1 * V_48 = V_3 -> V_138 ;
T_3 V_139 = F_26 ( V_136 -> V_140 ) ;
T_3 V_141 ;
T_3 V_142 ;
T_3 V_39 ;
if ( type & V_143 )
F_82 ( V_136 -> V_129 , V_144 ) ;
else
F_82 ( V_136 -> V_129 , V_145 ) ;
F_83 ( V_3 ) ;
V_142 = F_25 ( V_3 -> V_51 + V_146 ) ;
V_141 = F_25 ( V_3 -> V_51 + V_147 ) ;
switch ( type ) {
case V_148 :
V_142 |= V_139 ;
V_141 |= V_139 ;
break;
case V_149 :
V_142 |= V_139 ;
V_141 &= ~ V_139 ;
break;
case V_150 :
V_142 &= ~ V_139 ;
V_141 |= V_139 ;
break;
case V_151 :
V_142 &= ~ V_139 ;
V_141 &= ~ V_139 ;
break;
default:
F_84 ( V_3 ) ;
return - V_20 ;
}
F_34 ( V_142 , V_3 -> V_51 + V_146 ) ;
F_34 ( V_141 , V_3 -> V_51 + V_147 ) ;
F_84 ( V_3 ) ;
F_20 ( V_48 , V_136 -> V_140 , V_77 ) ;
V_39 = F_25 ( V_48 -> V_51 + V_78 ) ;
V_39 &= ~ V_139 ;
F_34 ( V_39 , V_48 -> V_51 + V_78 ) ;
return 0 ;
}
static int F_85 ( struct V_98 * V_99 ,
struct V_5 * V_6 )
{
struct V_57 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
unsigned int V_152 = V_153 | V_154 | V_155 ;
struct V_137 * V_3 ;
int V_93 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_156 ) {
F_86 ( & V_99 -> V_35 , L_29 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_127 = F_87 ( V_48 -> V_101 , 32 ,
& V_157 , NULL ) ;
if ( ! V_48 -> V_127 ) {
F_86 ( & V_99 -> V_35 , L_30 ,
V_48 -> V_7 ) ;
continue;
}
V_93 = F_88 ( V_48 -> V_127 , 32 , 1 ,
L_31 , V_145 ,
V_152 , 0 , V_158 ) ;
if ( V_93 ) {
F_12 ( & V_99 -> V_35 , L_32 ,
V_48 -> V_7 ) ;
F_89 ( V_48 -> V_127 ) ;
continue;
}
V_3 = F_90 ( V_48 -> V_127 , 0 ) ;
V_3 -> V_51 = V_48 -> V_51 ;
V_3 -> V_138 = V_48 ;
V_3 -> V_159 [ 0 ] . V_160 . V_139 = V_161 ;
V_3 -> V_159 [ 0 ] . V_160 . V_162 = V_163 ;
V_3 -> V_159 [ 0 ] . V_75 . V_164 = V_165 ;
V_3 -> V_159 [ 0 ] . V_75 . V_166 = V_167 ;
V_3 -> V_159 [ 0 ] . V_75 . V_168 = V_169 ;
V_3 -> V_159 [ 0 ] . V_75 . V_170 = V_171 ;
V_3 -> V_159 [ 0 ] . V_75 . V_172 = F_80 ;
F_91 ( V_48 -> V_129 , V_48 ) ;
F_92 ( V_48 -> V_129 , F_72 ) ;
}
return 0 ;
}
static int F_93 ( struct V_98 * V_99 ,
struct V_5 * V_6 )
{
struct V_57 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
struct V_2 * V_3 ;
int V_93 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_156 ) {
F_86 ( & V_99 -> V_35 , L_29 ,
V_48 -> V_7 ) ;
continue;
}
V_48 -> V_2 = V_173 ;
V_3 = & V_48 -> V_2 ;
V_3 -> V_76 = V_48 -> V_15 ;
V_3 -> V_122 = V_48 -> V_16 ;
V_3 -> V_35 = & V_99 -> V_35 ;
V_3 -> V_101 = V_48 -> V_101 ;
V_3 -> V_174 = V_48 -> V_7 ;
V_93 = F_94 ( V_3 ) ;
if ( V_93 ) {
F_12 ( & V_99 -> V_35 , L_33 ,
V_3 -> V_174 , V_93 ) ;
goto V_175;
}
}
F_85 ( V_99 , V_6 ) ;
return 0 ;
V_175:
for ( -- V_8 , -- V_48 ; V_8 >= 0 ; -- V_8 , -- V_48 ) {
if ( ! V_48 -> V_156 )
continue;
if ( F_95 ( & V_48 -> V_2 ) )
F_12 ( & V_99 -> V_35 , L_34 ,
V_48 -> V_2 . V_174 ) ;
}
return V_93 ;
}
static int F_96 ( struct V_98 * V_99 ,
struct V_5 * V_6 )
{
struct V_57 * V_13 = V_6 -> V_13 ;
struct V_1 * V_48 = V_13 -> V_14 ;
int V_93 = 0 ;
int V_8 ;
for ( V_8 = 0 ; ! V_93 && V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! V_48 -> V_156 )
continue;
V_93 = F_95 ( & V_48 -> V_2 ) ;
}
if ( V_93 )
F_12 ( & V_99 -> V_35 , L_35 ) ;
return V_93 ;
}
static int F_97 ( struct V_1 * V_48 ,
struct V_100 * V_35 )
{
struct V_176 V_177 ;
if ( F_98 ( V_48 -> V_101 , 0 , & V_177 ) ) {
F_12 ( V_35 , L_36 ) ;
return - V_178 ;
}
V_48 -> V_51 = F_99 ( V_35 , & V_177 ) ;
if ( F_47 ( V_48 -> V_51 ) )
return F_48 ( V_48 -> V_51 ) ;
V_48 -> V_129 = F_100 ( V_48 -> V_101 , 0 ) ;
V_48 -> V_179 = F_101 ( V_48 -> V_101 , 0 ) ;
if ( F_47 ( V_48 -> V_179 ) )
return F_48 ( V_48 -> V_179 ) ;
return F_102 ( V_48 -> V_179 ) ;
}
static struct V_57 * F_103 (
struct V_5 * V_136 ,
struct V_98 * V_99 )
{
const struct V_180 * V_181 ;
struct V_26 * V_182 = V_99 -> V_35 . V_101 ;
struct V_26 * V_27 ;
struct V_57 * V_13 ;
struct V_1 * V_48 ;
int V_8 ;
V_181 = F_104 ( V_183 , V_182 ) ;
V_13 = (struct V_57 * ) V_181 -> V_39 ;
F_41 (node, np) {
if ( ! F_105 ( V_27 , L_37 , NULL ) )
continue;
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
if ( ! strcmp ( V_48 -> V_7 , V_27 -> V_7 ) ) {
V_48 -> V_101 = V_27 ;
if ( ! F_97 ( V_48 , & V_99 -> V_35 ) )
V_48 -> V_156 = true ;
break;
}
}
}
V_48 = V_13 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_13 -> V_18 ; ++ V_8 , ++ V_48 ) {
F_106 ( & V_48 -> V_55 ) ;
V_48 -> V_49 = V_136 ;
V_48 -> V_15 = V_13 -> V_16 ;
V_13 -> V_16 += V_48 -> V_16 ;
}
return V_13 ;
}
static int F_107 ( struct V_98 * V_99 )
{
struct V_5 * V_6 ;
struct V_100 * V_35 = & V_99 -> V_35 ;
struct V_57 * V_13 ;
struct V_176 * V_177 ;
int V_93 ;
if ( ! V_35 -> V_101 ) {
F_12 ( V_35 , L_38 ) ;
return - V_184 ;
}
V_6 = F_13 ( V_35 , sizeof( struct V_5 ) , V_36 ) ;
if ( ! V_6 )
return - V_37 ;
V_13 = F_103 ( V_6 , V_99 ) ;
if ( ! V_13 ) {
F_12 ( V_35 , L_39 ) ;
return - V_20 ;
}
V_6 -> V_13 = V_13 ;
V_6 -> V_35 = V_35 ;
V_177 = F_108 ( V_99 , V_185 , 0 ) ;
V_6 -> V_51 = F_99 ( & V_99 -> V_35 , V_177 ) ;
if ( F_47 ( V_6 -> V_51 ) )
return F_48 ( V_6 -> V_51 ) ;
V_93 = F_93 ( V_99 , V_6 ) ;
if ( V_93 )
return V_93 ;
V_93 = F_54 ( V_99 , V_6 ) ;
if ( V_93 ) {
F_96 ( V_99 , V_6 ) ;
return V_93 ;
}
F_109 ( V_99 , V_6 ) ;
return 0 ;
}
static int T_6 F_110 ( void )
{
return F_111 ( & V_186 ) ;
}
