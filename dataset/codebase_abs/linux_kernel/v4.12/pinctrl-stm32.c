static inline int F_1 ( int V_1 )
{
return V_1 % V_2 ;
}
static inline T_1 F_2 ( T_1 V_3 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
case F_3 ( 0 ) ... F_3 ( 15 ) :
return 2 ;
case V_5 :
return 3 ;
}
return 0 ;
}
static inline T_1 F_4 ( T_1 V_3 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
case F_3 ( 0 ) ... F_3 ( 15 ) :
return V_3 - 1 ;
case V_5 :
return 0 ;
}
return 0 ;
}
static inline void F_5 ( struct V_6 * V_7 ,
unsigned V_8 , int V_9 )
{
if ( ! V_9 )
V_8 += V_2 ;
F_6 ( V_7 -> V_10 ) ;
F_7 ( F_8 ( V_8 ) , V_7 -> V_11 + V_12 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static int F_10 ( struct V_13 * V_14 , unsigned V_8 )
{
struct V_6 * V_7 = F_11 ( V_14 ) ;
struct V_15 * V_16 = F_12 ( V_7 -> V_13 . V_17 ) ;
struct V_18 * V_19 ;
int V_20 = V_8 + ( V_7 -> V_21 * V_2 ) ;
V_19 = F_13 ( V_16 -> V_22 , V_20 ) ;
if ( ! V_19 ) {
F_14 ( V_16 -> V_23 , L_1 , V_20 ) ;
return - V_24 ;
}
return F_15 ( V_14 -> V_11 + V_8 ) ;
}
static void F_16 ( struct V_13 * V_14 , unsigned V_8 )
{
F_17 ( V_14 -> V_11 + V_8 ) ;
}
static int F_18 ( struct V_13 * V_14 , unsigned V_8 )
{
struct V_6 * V_7 = F_11 ( V_14 ) ;
int V_25 ;
F_6 ( V_7 -> V_10 ) ;
V_25 = ! ! ( F_19 ( V_7 -> V_11 + V_26 ) & F_8 ( V_8 ) ) ;
F_9 ( V_7 -> V_10 ) ;
return V_25 ;
}
static void F_20 ( struct V_13 * V_14 , unsigned V_8 , int V_9 )
{
struct V_6 * V_7 = F_11 ( V_14 ) ;
F_5 ( V_7 , V_8 , V_9 ) ;
}
static int F_21 ( struct V_13 * V_14 , unsigned V_8 )
{
return F_22 ( V_14 -> V_11 + V_8 ) ;
}
static int F_23 ( struct V_13 * V_14 ,
unsigned V_8 , int V_9 )
{
struct V_6 * V_7 = F_11 ( V_14 ) ;
F_5 ( V_7 , V_8 , V_9 ) ;
F_24 ( V_14 -> V_11 + V_8 ) ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 , unsigned int V_8 )
{
struct V_6 * V_7 = F_11 ( V_14 ) ;
struct V_27 V_28 ;
V_28 . V_29 = V_7 -> V_29 ;
V_28 . V_30 = 2 ;
V_28 . V_31 [ 0 ] = V_8 ;
V_28 . V_31 [ 1 ] = V_32 ;
return F_26 ( & V_28 ) ;
}
static int F_27 ( struct V_33 * V_34 ,
struct V_27 * V_28 ,
unsigned long * V_35 ,
unsigned int * type )
{
if ( ( V_28 -> V_30 != 2 ) ||
( V_28 -> V_31 [ 0 ] >= V_36 ) )
return - V_24 ;
* V_35 = V_28 -> V_31 [ 0 ] ;
* type = V_28 -> V_31 [ 1 ] ;
return 0 ;
}
static void F_28 ( struct V_33 * V_34 ,
struct V_37 * V_37 )
{
struct V_6 * V_7 = V_34 -> V_38 ;
struct V_15 * V_16 = F_12 ( V_7 -> V_13 . V_17 ) ;
F_29 ( V_16 -> V_39 [ V_37 -> V_35 ] , V_7 -> V_21 ) ;
F_30 ( & V_7 -> V_13 , V_37 -> V_35 ) ;
}
static void F_31 ( struct V_33 * V_34 ,
struct V_37 * V_37 )
{
struct V_6 * V_7 = V_34 -> V_38 ;
F_32 ( & V_7 -> V_13 , V_37 -> V_35 ) ;
}
static int F_33 ( struct V_33 * V_34 ,
unsigned int V_40 ,
unsigned int V_41 , void * V_42 )
{
struct V_6 * V_7 = V_34 -> V_38 ;
struct V_27 * V_28 = V_42 ;
struct V_27 V_43 ;
T_2 V_35 ;
V_35 = V_28 -> V_31 [ 0 ] ;
V_43 . V_29 = V_34 -> V_17 -> V_29 ;
V_43 . V_30 = 2 ;
V_43 . V_31 [ 0 ] = V_28 -> V_31 [ 0 ] ;
V_43 . V_31 [ 1 ] = V_28 -> V_31 [ 1 ] ;
F_34 ( V_34 , V_40 , V_35 , & V_44 ,
V_7 ) ;
return F_35 ( V_34 , V_40 , V_41 , & V_43 ) ;
}
static struct V_45 *
F_36 ( struct V_15 * V_16 , T_1 V_20 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_16 -> V_47 ; V_46 ++ ) {
struct V_45 * V_48 = V_16 -> V_49 + V_46 ;
if ( V_48 -> V_20 == V_20 )
return V_48 ;
}
return NULL ;
}
static bool F_37 ( struct V_15 * V_16 ,
T_1 V_50 , T_1 V_51 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_16 -> V_52 -> V_53 ; V_46 ++ ) {
const struct V_54 * V_20 = V_16 -> V_52 -> V_55 + V_46 ;
const struct V_56 * V_57 = V_20 -> V_58 ;
if ( V_20 -> V_20 . V_59 != V_50 )
continue;
while ( V_57 && V_57 -> V_60 ) {
if ( V_57 -> V_61 == V_51 )
return true ;
V_57 ++ ;
}
break;
}
return false ;
}
static int F_38 ( struct V_15 * V_16 ,
T_1 V_20 , T_1 V_51 , struct V_45 * V_48 ,
struct V_62 * * V_63 , unsigned * V_64 ,
unsigned * V_65 )
{
if ( * V_65 == * V_64 )
return - V_66 ;
( * V_63 ) [ * V_65 ] . type = V_67 ;
( * V_63 ) [ * V_65 ] . V_42 . V_68 . V_69 = V_48 -> V_60 ;
if ( ! F_37 ( V_16 , V_20 , V_51 ) ) {
F_14 ( V_16 -> V_23 , L_2 ,
V_51 , V_20 ) ;
return - V_24 ;
}
( * V_63 ) [ * V_65 ] . V_42 . V_68 . V_3 = V_70 [ V_51 ] ;
( * V_65 ) ++ ;
return 0 ;
}
static int F_39 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_62 * * V_63 ,
unsigned * V_64 ,
unsigned * V_65 )
{
struct V_15 * V_16 ;
struct V_45 * V_48 ;
struct V_75 * V_55 ;
T_1 V_76 , V_20 , V_57 ;
unsigned long * V_77 ;
unsigned int V_78 ;
bool V_79 = 0 ;
unsigned V_80 = 0 ;
int V_81 , V_82 , V_83 , V_46 , V_84 ;
V_16 = F_40 ( V_72 ) ;
V_55 = F_41 ( V_74 , L_3 , NULL ) ;
if ( ! V_55 ) {
F_14 ( V_16 -> V_23 , L_4 ,
V_74 -> V_60 ) ;
return - V_24 ;
}
V_84 = F_42 ( V_74 , V_72 , & V_77 ,
& V_78 ) ;
if ( V_84 )
return V_84 ;
if ( V_78 )
V_79 = 1 ;
V_81 = V_55 -> V_85 / sizeof( T_1 ) ;
V_82 = V_81 ;
V_83 = 0 ;
if ( V_82 )
V_83 ++ ;
if ( V_79 && V_81 >= 1 )
V_83 ++ ;
if ( ! V_81 || ! V_83 )
return - V_24 ;
V_80 = V_81 * V_83 ;
V_84 = F_43 ( V_72 , V_63 ,
V_64 , V_65 , V_80 ) ;
if ( V_84 )
return V_84 ;
for ( V_46 = 0 ; V_46 < V_81 ; V_46 ++ ) {
V_84 = F_44 ( V_74 , L_3 ,
V_46 , & V_76 ) ;
if ( V_84 )
return V_84 ;
V_20 = F_45 ( V_76 ) ;
V_57 = F_46 ( V_76 ) ;
if ( V_20 >= V_16 -> V_52 -> V_53 ) {
F_14 ( V_16 -> V_23 , L_5 ) ;
return - V_24 ;
}
if ( ! F_37 ( V_16 , V_20 , V_57 ) ) {
F_14 ( V_16 -> V_23 , L_6 ) ;
return - V_24 ;
}
V_48 = F_36 ( V_16 , V_20 ) ;
if ( ! V_48 ) {
F_14 ( V_16 -> V_23 , L_7 ,
V_20 ) ;
return - V_24 ;
}
V_84 = F_38 ( V_16 , V_20 , V_57 , V_48 , V_63 ,
V_64 , V_65 ) ;
if ( V_84 )
return V_84 ;
if ( V_79 ) {
V_84 = F_47 ( V_72 , V_63 ,
V_64 , V_65 , V_48 -> V_60 ,
V_77 , V_78 ,
V_86 ) ;
if ( V_84 )
return V_84 ;
}
}
return 0 ;
}
static int F_48 ( struct V_71 * V_72 ,
struct V_73 * V_87 ,
struct V_62 * * V_63 , unsigned * V_65 )
{
struct V_73 * V_88 ;
unsigned V_64 ;
int V_25 ;
* V_63 = NULL ;
* V_65 = 0 ;
V_64 = 0 ;
F_49 (np_config, np) {
V_25 = F_39 ( V_72 , V_88 , V_63 ,
& V_64 , V_65 ) ;
if ( V_25 < 0 ) {
F_50 ( V_72 , * V_63 , * V_65 ) ;
return V_25 ;
}
}
return 0 ;
}
static int F_51 ( struct V_71 * V_72 )
{
struct V_15 * V_16 = F_40 ( V_72 ) ;
return V_16 -> V_47 ;
}
static const char * F_52 ( struct V_71 * V_72 ,
unsigned V_69 )
{
struct V_15 * V_16 = F_40 ( V_72 ) ;
return V_16 -> V_49 [ V_69 ] . V_60 ;
}
static int F_53 ( struct V_71 * V_72 ,
unsigned V_69 ,
const unsigned * * V_55 ,
unsigned * V_81 )
{
struct V_15 * V_16 = F_40 ( V_72 ) ;
* V_55 = ( unsigned * ) & V_16 -> V_49 [ V_69 ] . V_20 ;
* V_81 = 1 ;
return 0 ;
}
static int F_54 ( struct V_71 * V_72 )
{
return F_55 ( V_70 ) ;
}
static const char * F_56 ( struct V_71 * V_72 ,
unsigned V_89 )
{
return V_70 [ V_89 ] ;
}
static int F_57 ( struct V_71 * V_72 ,
unsigned V_3 ,
const char * const * * V_49 ,
unsigned * const V_90 )
{
struct V_15 * V_16 = F_40 ( V_72 ) ;
* V_49 = V_16 -> V_91 ;
* V_90 = V_16 -> V_47 ;
return 0 ;
}
static void F_58 ( struct V_6 * V_7 ,
int V_20 , T_1 V_92 , T_1 V_93 )
{
T_1 V_94 ;
int V_95 = ( V_20 % 8 ) * 4 ;
int V_96 = V_97 + ( V_20 / 8 ) * 4 ;
unsigned long V_98 ;
F_6 ( V_7 -> V_10 ) ;
F_59 ( & V_7 -> V_99 , V_98 ) ;
V_94 = F_19 ( V_7 -> V_11 + V_96 ) ;
V_94 &= ~ F_60 ( V_95 + 3 , V_95 ) ;
V_94 |= ( V_93 << V_95 ) ;
F_7 ( V_94 , V_7 -> V_11 + V_96 ) ;
V_94 = F_19 ( V_7 -> V_11 + V_100 ) ;
V_94 &= ~ F_60 ( V_20 * 2 + 1 , V_20 * 2 ) ;
V_94 |= V_92 << ( V_20 * 2 ) ;
F_7 ( V_94 , V_7 -> V_11 + V_100 ) ;
F_61 ( & V_7 -> V_99 , V_98 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static void F_62 ( struct V_6 * V_7 ,
int V_20 , T_1 * V_92 , T_1 * V_93 )
{
T_1 V_94 ;
int V_95 = ( V_20 % 8 ) * 4 ;
int V_96 = V_97 + ( V_20 / 8 ) * 4 ;
unsigned long V_98 ;
F_6 ( V_7 -> V_10 ) ;
F_59 ( & V_7 -> V_99 , V_98 ) ;
V_94 = F_19 ( V_7 -> V_11 + V_96 ) ;
V_94 &= F_60 ( V_95 + 3 , V_95 ) ;
* V_93 = V_94 >> V_95 ;
V_94 = F_19 ( V_7 -> V_11 + V_100 ) ;
V_94 &= F_60 ( V_20 * 2 + 1 , V_20 * 2 ) ;
* V_92 = V_94 >> ( V_20 * 2 ) ;
F_61 ( & V_7 -> V_99 , V_98 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static int F_63 ( struct V_71 * V_72 ,
unsigned V_3 ,
unsigned V_69 )
{
bool V_25 ;
struct V_15 * V_16 = F_40 ( V_72 ) ;
struct V_45 * V_101 = V_16 -> V_49 + V_69 ;
struct V_18 * V_19 ;
struct V_6 * V_7 ;
T_1 V_92 , V_93 ;
int V_20 ;
V_25 = F_37 ( V_16 , V_101 -> V_20 , V_3 ) ;
if ( ! V_25 ) {
F_14 ( V_16 -> V_23 , L_8 ,
V_3 , V_69 ) ;
return - V_24 ;
}
V_19 = F_64 ( V_72 , V_101 -> V_20 ) ;
V_7 = F_11 ( V_19 -> V_102 ) ;
V_20 = F_1 ( V_101 -> V_20 ) ;
V_92 = F_2 ( V_3 ) ;
V_93 = F_4 ( V_3 ) ;
F_58 ( V_7 , V_20 , V_92 , V_93 ) ;
return 0 ;
}
static int F_65 ( struct V_71 * V_72 ,
struct V_18 * V_19 , unsigned V_1 ,
bool V_103 )
{
struct V_6 * V_7 = F_11 ( V_19 -> V_102 ) ;
int V_20 = F_1 ( V_1 ) ;
F_58 ( V_7 , V_20 , ! V_103 , 0 ) ;
return 0 ;
}
static void F_66 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_104 )
{
unsigned long V_98 ;
T_1 V_94 ;
F_6 ( V_7 -> V_10 ) ;
F_59 ( & V_7 -> V_99 , V_98 ) ;
V_94 = F_19 ( V_7 -> V_11 + V_105 ) ;
V_94 &= ~ F_8 ( V_8 ) ;
V_94 |= V_104 << V_8 ;
F_7 ( V_94 , V_7 -> V_11 + V_105 ) ;
F_61 ( & V_7 -> V_99 , V_98 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_67 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_98 ;
T_1 V_94 ;
F_6 ( V_7 -> V_10 ) ;
F_59 ( & V_7 -> V_99 , V_98 ) ;
V_94 = F_19 ( V_7 -> V_11 + V_105 ) ;
V_94 &= F_8 ( V_8 ) ;
F_61 ( & V_7 -> V_99 , V_98 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_94 >> V_8 ) ;
}
static void F_68 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_106 )
{
unsigned long V_98 ;
T_1 V_94 ;
F_6 ( V_7 -> V_10 ) ;
F_59 ( & V_7 -> V_99 , V_98 ) ;
V_94 = F_19 ( V_7 -> V_11 + V_107 ) ;
V_94 &= ~ F_60 ( V_8 * 2 + 1 , V_8 * 2 ) ;
V_94 |= V_106 << ( V_8 * 2 ) ;
F_7 ( V_94 , V_7 -> V_11 + V_107 ) ;
F_61 ( & V_7 -> V_99 , V_98 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_69 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_98 ;
T_1 V_94 ;
F_6 ( V_7 -> V_10 ) ;
F_59 ( & V_7 -> V_99 , V_98 ) ;
V_94 = F_19 ( V_7 -> V_11 + V_107 ) ;
V_94 &= F_60 ( V_8 * 2 + 1 , V_8 * 2 ) ;
F_61 ( & V_7 -> V_99 , V_98 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_94 >> ( V_8 * 2 ) ) ;
}
static void F_70 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_108 )
{
unsigned long V_98 ;
T_1 V_94 ;
F_6 ( V_7 -> V_10 ) ;
F_59 ( & V_7 -> V_99 , V_98 ) ;
V_94 = F_19 ( V_7 -> V_11 + V_109 ) ;
V_94 &= ~ F_60 ( V_8 * 2 + 1 , V_8 * 2 ) ;
V_94 |= V_108 << ( V_8 * 2 ) ;
F_7 ( V_94 , V_7 -> V_11 + V_109 ) ;
F_61 ( & V_7 -> V_99 , V_98 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_71 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_98 ;
T_1 V_94 ;
F_6 ( V_7 -> V_10 ) ;
F_59 ( & V_7 -> V_99 , V_98 ) ;
V_94 = F_19 ( V_7 -> V_11 + V_109 ) ;
V_94 &= F_60 ( V_8 * 2 + 1 , V_8 * 2 ) ;
F_61 ( & V_7 -> V_99 , V_98 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_94 >> ( V_8 * 2 ) ) ;
}
static bool F_72 ( struct V_6 * V_7 ,
unsigned int V_8 , bool V_110 )
{
unsigned long V_98 ;
T_1 V_94 ;
F_6 ( V_7 -> V_10 ) ;
F_59 ( & V_7 -> V_99 , V_98 ) ;
if ( V_110 )
V_94 = ! ! ( F_19 ( V_7 -> V_11 + V_26 ) &
F_8 ( V_8 ) ) ;
else
V_94 = ! ! ( F_19 ( V_7 -> V_11 + V_111 ) &
F_8 ( V_8 ) ) ;
F_61 ( & V_7 -> V_99 , V_98 ) ;
F_9 ( V_7 -> V_10 ) ;
return V_94 ;
}
static int F_73 ( struct V_71 * V_72 ,
unsigned int V_20 , enum V_112 V_31 ,
enum V_112 V_113 )
{
struct V_18 * V_19 ;
struct V_6 * V_7 ;
int V_8 , V_25 = 0 ;
V_19 = F_64 ( V_72 , V_20 ) ;
V_7 = F_11 ( V_19 -> V_102 ) ;
V_8 = F_1 ( V_20 ) ;
switch ( V_31 ) {
case V_114 :
F_66 ( V_7 , V_8 , 0 ) ;
break;
case V_115 :
F_66 ( V_7 , V_8 , 1 ) ;
break;
case V_116 :
F_68 ( V_7 , V_8 , V_113 ) ;
break;
case V_117 :
F_70 ( V_7 , V_8 , 0 ) ;
break;
case V_118 :
F_70 ( V_7 , V_8 , 1 ) ;
break;
case V_119 :
F_70 ( V_7 , V_8 , 2 ) ;
break;
case V_120 :
F_5 ( V_7 , V_8 , V_113 ) ;
V_25 = F_65 ( V_72 , V_19 , V_20 , false ) ;
break;
default:
V_25 = - V_24 ;
}
return V_25 ;
}
static int F_74 ( struct V_71 * V_72 ,
unsigned V_69 ,
unsigned long * V_121 )
{
struct V_15 * V_16 = F_40 ( V_72 ) ;
* V_121 = V_16 -> V_49 [ V_69 ] . V_121 ;
return 0 ;
}
static int F_75 ( struct V_71 * V_72 , unsigned V_69 ,
unsigned long * V_77 , unsigned V_78 )
{
struct V_15 * V_16 = F_40 ( V_72 ) ;
struct V_45 * V_101 = & V_16 -> V_49 [ V_69 ] ;
int V_46 , V_25 ;
for ( V_46 = 0 ; V_46 < V_78 ; V_46 ++ ) {
V_25 = F_73 ( V_72 , V_101 -> V_20 ,
F_76 ( V_77 [ V_46 ] ) ,
F_77 ( V_77 [ V_46 ] ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_101 -> V_121 = V_77 [ V_46 ] ;
}
return 0 ;
}
static void F_78 ( struct V_71 * V_72 ,
struct V_122 * V_123 ,
unsigned int V_20 )
{
struct V_18 * V_19 ;
struct V_6 * V_7 ;
int V_8 ;
T_1 V_92 , V_93 , V_104 , V_106 , V_108 ;
static const char * const V_124 [] = {
L_9 , L_10 , L_11 , L_12 } ;
static const char * const V_125 [] = {
L_13 , L_14 , L_15 , L_16 } ;
static const char * const V_126 [] = {
L_17 , L_18 , L_19 , L_20 } ;
bool V_94 ;
V_19 = F_13 ( V_72 , V_20 ) ;
V_7 = F_11 ( V_19 -> V_102 ) ;
V_8 = F_1 ( V_20 ) ;
F_62 ( V_7 , V_8 , & V_92 , & V_93 ) ;
V_108 = F_71 ( V_7 , V_8 ) ;
F_79 ( V_123 , L_21 , V_124 [ V_92 ] ) ;
switch ( V_92 ) {
case 0 :
V_94 = F_72 ( V_7 , V_8 , true ) ;
F_79 ( V_123 , L_22 ,
V_94 ? L_15 : L_13 ,
V_126 [ V_108 ] ) ;
break;
case 1 :
V_104 = F_67 ( V_7 , V_8 ) ;
V_106 = F_69 ( V_7 , V_8 ) ;
V_94 = F_72 ( V_7 , V_8 , false ) ;
F_79 ( V_123 , L_23 ,
V_94 ? L_15 : L_13 ,
V_104 ? L_24 : L_25 ,
V_126 [ V_108 ] ,
V_125 [ V_106 ] , L_26 ) ;
break;
case 2 :
V_104 = F_67 ( V_7 , V_8 ) ;
V_106 = F_69 ( V_7 , V_8 ) ;
F_79 ( V_123 , L_27 , V_93 ,
V_104 ? L_24 : L_25 ,
V_126 [ V_108 ] ,
V_125 [ V_106 ] , L_26 ) ;
break;
case 3 :
break;
}
}
static int F_80 ( struct V_15 * V_16 ,
struct V_73 * V_88 )
{
struct V_6 * V_7 = & V_16 -> V_127 [ V_16 -> V_128 ] ;
struct V_18 * V_19 = & V_7 -> V_19 ;
struct V_129 args ;
struct V_130 * V_23 = V_16 -> V_23 ;
struct V_131 V_132 ;
struct V_133 * V_134 ;
int V_53 = V_2 ;
int V_21 , V_84 ;
V_134 = F_81 ( V_88 , NULL ) ;
if ( ! F_82 ( V_134 ) )
F_83 ( V_134 ) ;
if ( F_84 ( V_88 , 0 , & V_132 ) )
return - V_135 ;
V_7 -> V_11 = F_85 ( V_23 , & V_132 ) ;
if ( F_82 ( V_7 -> V_11 ) )
return F_86 ( V_7 -> V_11 ) ;
V_7 -> V_10 = F_87 ( V_88 , NULL ) ;
if ( F_82 ( V_7 -> V_10 ) ) {
F_14 ( V_23 , L_28 , F_86 ( V_7 -> V_10 ) ) ;
return F_86 ( V_7 -> V_10 ) ;
}
V_84 = F_88 ( V_7 -> V_10 ) ;
if ( V_84 ) {
F_14 ( V_23 , L_29 , V_84 ) ;
return V_84 ;
}
V_7 -> V_13 = V_136 ;
F_89 ( V_88 , L_30 , & V_7 -> V_13 . V_137 ) ;
if ( ! F_90 ( V_88 , L_31 , 3 , 0 , & args ) ) {
V_21 = args . args [ 1 ] / V_2 ;
V_7 -> V_13 . V_11 = args . args [ 1 ] ;
} else {
V_21 = V_16 -> V_128 ;
V_7 -> V_13 . V_11 = V_21 * V_2 ;
V_19 -> V_60 = V_7 -> V_13 . V_137 ;
V_19 -> V_138 = V_21 ;
V_19 -> V_139 = V_19 -> V_138 * V_2 ;
V_19 -> V_11 = V_19 -> V_138 * V_2 ;
V_19 -> V_53 = V_53 ;
V_19 -> V_102 = & V_7 -> V_13 ;
F_91 ( V_16 -> V_22 ,
& V_16 -> V_127 [ V_21 ] . V_19 ) ;
}
V_7 -> V_13 . V_11 = V_21 * V_2 ;
V_7 -> V_13 . V_140 = V_53 ;
V_7 -> V_13 . V_141 = V_88 ;
V_7 -> V_13 . V_17 = V_23 ;
V_7 -> V_21 = V_21 ;
F_92 ( & V_7 -> V_99 ) ;
V_7 -> V_29 = F_93 ( V_88 ) ;
V_7 -> V_142 = F_94 ( V_16 -> V_142 , 0 ,
V_36 , V_7 -> V_29 ,
& V_143 , V_7 ) ;
if ( ! V_7 -> V_142 )
return - V_135 ;
V_84 = F_95 ( & V_7 -> V_13 , V_7 ) ;
if ( V_84 ) {
F_14 ( V_23 , L_32 , V_21 ) ;
return V_84 ;
}
F_96 ( V_23 , L_33 , V_7 -> V_13 . V_137 ) ;
return 0 ;
}
static int F_97 ( struct V_144 * V_145 ,
struct V_15 * V_16 )
{
struct V_73 * V_88 = V_145 -> V_23 . V_141 , * V_17 ;
struct V_130 * V_23 = & V_145 -> V_23 ;
struct V_146 * V_147 ;
int V_8 , V_25 , V_46 ;
V_17 = F_98 ( V_88 ) ;
if ( ! V_17 )
return - V_148 ;
V_16 -> V_142 = F_99 ( V_17 ) ;
if ( ! V_16 -> V_142 )
return - V_148 ;
V_16 -> V_146 = F_100 ( V_88 , L_34 ) ;
if ( F_82 ( V_16 -> V_146 ) )
return F_86 ( V_16 -> V_146 ) ;
V_147 = V_16 -> V_146 ;
V_25 = F_44 ( V_88 , L_34 , 1 , & V_8 ) ;
if ( V_25 )
return V_25 ;
for ( V_46 = 0 ; V_46 < V_2 ; V_46 ++ ) {
struct V_149 V_68 ;
V_68 . V_150 = V_8 + ( V_46 / 4 ) * 4 ;
V_68 . V_151 = ( V_46 % 4 ) * 4 ;
V_68 . V_152 = V_68 . V_151 + 3 ;
V_16 -> V_39 [ V_46 ] = F_101 ( V_23 , V_147 , V_68 ) ;
if ( F_82 ( V_16 -> V_39 [ V_46 ] ) )
return F_86 ( V_16 -> V_39 [ V_46 ] ) ;
}
return 0 ;
}
static int F_102 ( struct V_144 * V_145 )
{
struct V_15 * V_16 = F_103 ( V_145 ) ;
int V_46 ;
V_16 -> V_47 = V_16 -> V_52 -> V_53 ;
V_16 -> V_49 = F_104 ( & V_145 -> V_23 , V_16 -> V_47 ,
sizeof( * V_16 -> V_49 ) , V_153 ) ;
if ( ! V_16 -> V_49 )
return - V_154 ;
V_16 -> V_91 = F_104 ( & V_145 -> V_23 , V_16 -> V_47 ,
sizeof( * V_16 -> V_91 ) , V_153 ) ;
if ( ! V_16 -> V_91 )
return - V_154 ;
for ( V_46 = 0 ; V_46 < V_16 -> V_52 -> V_53 ; V_46 ++ ) {
const struct V_54 * V_20 = V_16 -> V_52 -> V_55 + V_46 ;
struct V_45 * V_69 = V_16 -> V_49 + V_46 ;
V_69 -> V_60 = V_20 -> V_20 . V_60 ;
V_69 -> V_20 = V_20 -> V_20 . V_59 ;
V_16 -> V_91 [ V_46 ] = V_20 -> V_20 . V_60 ;
}
return 0 ;
}
int F_105 ( struct V_144 * V_145 )
{
struct V_73 * V_88 = V_145 -> V_23 . V_141 ;
struct V_73 * V_155 ;
const struct V_156 * V_157 ;
struct V_130 * V_23 = & V_145 -> V_23 ;
struct V_15 * V_16 ;
struct V_158 * V_55 ;
int V_46 , V_25 , V_127 = 0 ;
if ( ! V_88 )
return - V_24 ;
V_157 = F_106 ( V_23 -> V_159 -> V_160 , V_23 ) ;
if ( ! V_157 || ! V_157 -> V_42 )
return - V_24 ;
if ( ! F_41 ( V_88 , L_35 , NULL ) ) {
F_14 ( V_23 , L_36 ) ;
return - V_24 ;
}
V_16 = F_107 ( V_23 , sizeof( * V_16 ) , V_153 ) ;
if ( ! V_16 )
return - V_154 ;
F_108 ( V_145 , V_16 ) ;
V_16 -> V_23 = V_23 ;
V_16 -> V_52 = V_157 -> V_42 ;
V_25 = F_102 ( V_145 ) ;
if ( V_25 ) {
F_14 ( V_23 , L_37 , V_25 ) ;
return - V_24 ;
}
if ( F_41 ( V_88 , L_38 , NULL ) ) {
V_25 = F_97 ( V_145 , V_16 ) ;
if ( V_25 )
return V_25 ;
}
V_55 = F_104 ( & V_145 -> V_23 , V_16 -> V_52 -> V_53 , sizeof( * V_55 ) ,
V_153 ) ;
if ( ! V_55 )
return - V_154 ;
for ( V_46 = 0 ; V_46 < V_16 -> V_52 -> V_53 ; V_46 ++ )
V_55 [ V_46 ] = V_16 -> V_52 -> V_55 [ V_46 ] . V_20 ;
V_16 -> V_161 . V_60 = F_109 ( & V_145 -> V_23 ) ;
V_16 -> V_161 . V_162 = V_163 ;
V_16 -> V_161 . V_55 = V_55 ;
V_16 -> V_161 . V_53 = V_16 -> V_52 -> V_53 ;
V_16 -> V_161 . V_164 = & V_165 ;
V_16 -> V_161 . V_166 = & V_167 ;
V_16 -> V_161 . V_168 = & V_169 ;
V_16 -> V_23 = & V_145 -> V_23 ;
V_16 -> V_22 = F_110 ( & V_145 -> V_23 , & V_16 -> V_161 ,
V_16 ) ;
if ( F_82 ( V_16 -> V_22 ) ) {
F_14 ( & V_145 -> V_23 , L_39 ) ;
return F_86 ( V_16 -> V_22 ) ;
}
F_49 (np, child)
if ( F_111 ( V_155 , L_40 ) )
V_127 ++ ;
if ( ! V_127 ) {
F_14 ( V_23 , L_41 ) ;
return - V_24 ;
}
V_16 -> V_127 = F_104 ( V_23 , V_127 , sizeof( * V_16 -> V_127 ) ,
V_153 ) ;
if ( ! V_16 -> V_127 )
return - V_154 ;
F_49 (np, child) {
if ( F_111 ( V_155 , L_40 ) ) {
V_25 = F_80 ( V_16 , V_155 ) ;
if ( V_25 )
return V_25 ;
V_16 -> V_128 ++ ;
}
}
F_96 ( V_23 , L_42 ) ;
return 0 ;
}
