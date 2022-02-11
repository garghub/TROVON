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
static int F_27 ( struct V_13 * V_14 , unsigned int V_8 )
{
struct V_6 * V_7 = F_11 ( V_14 ) ;
int V_20 = F_1 ( V_8 ) ;
int V_25 ;
T_1 V_33 , V_34 ;
F_28 ( V_7 , V_20 , & V_33 , & V_34 ) ;
if ( ( V_34 == 0 ) && ( V_33 == 0 ) )
V_25 = 1 ;
else if ( ( V_34 == 0 ) && ( V_33 == 1 ) )
V_25 = 0 ;
else
V_25 = - V_24 ;
return V_25 ;
}
static int F_29 ( struct V_35 * V_35 )
{
struct V_6 * V_7 = V_35 -> V_36 -> V_37 ;
struct V_15 * V_16 = F_12 ( V_7 -> V_13 . V_17 ) ;
int V_25 ;
V_25 = F_21 ( & V_7 -> V_13 , V_35 -> V_38 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_30 ( & V_7 -> V_13 , V_35 -> V_38 ) ;
if ( V_25 ) {
F_14 ( V_16 -> V_23 , L_2 ,
V_35 -> V_38 ) ;
return V_25 ;
}
return 0 ;
}
static void F_31 ( struct V_35 * V_35 )
{
struct V_6 * V_7 = V_35 -> V_36 -> V_37 ;
F_32 ( & V_7 -> V_13 , V_35 -> V_38 ) ;
}
static int F_33 ( struct V_39 * V_40 ,
struct V_27 * V_28 ,
unsigned long * V_38 ,
unsigned int * type )
{
if ( ( V_28 -> V_30 != 2 ) ||
( V_28 -> V_31 [ 0 ] >= V_41 ) )
return - V_24 ;
* V_38 = V_28 -> V_31 [ 0 ] ;
* type = V_28 -> V_31 [ 1 ] ;
return 0 ;
}
static void F_34 ( struct V_39 * V_40 ,
struct V_35 * V_35 )
{
struct V_6 * V_7 = V_40 -> V_37 ;
struct V_15 * V_16 = F_12 ( V_7 -> V_13 . V_17 ) ;
F_35 ( V_16 -> V_42 [ V_35 -> V_38 ] , V_7 -> V_21 ) ;
}
static int F_36 ( struct V_39 * V_40 ,
unsigned int V_43 ,
unsigned int V_44 , void * V_45 )
{
struct V_6 * V_7 = V_40 -> V_37 ;
struct V_27 * V_28 = V_45 ;
struct V_27 V_46 ;
T_2 V_38 ;
V_38 = V_28 -> V_31 [ 0 ] ;
V_46 . V_29 = V_40 -> V_17 -> V_29 ;
V_46 . V_30 = 2 ;
V_46 . V_31 [ 0 ] = V_28 -> V_31 [ 0 ] ;
V_46 . V_31 [ 1 ] = V_28 -> V_31 [ 1 ] ;
F_37 ( V_40 , V_43 , V_38 , & V_47 ,
V_7 ) ;
return F_38 ( V_40 , V_43 , V_44 , & V_46 ) ;
}
static struct V_48 *
F_39 ( struct V_15 * V_16 , T_1 V_20 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_16 -> V_50 ; V_49 ++ ) {
struct V_48 * V_51 = V_16 -> V_52 + V_49 ;
if ( V_51 -> V_20 == V_20 )
return V_51 ;
}
return NULL ;
}
static bool F_40 ( struct V_15 * V_16 ,
T_1 V_53 , T_1 V_54 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_16 -> V_55 -> V_56 ; V_49 ++ ) {
const struct V_57 * V_20 = V_16 -> V_55 -> V_58 + V_49 ;
const struct V_59 * V_60 = V_20 -> V_61 ;
if ( V_20 -> V_20 . V_62 != V_53 )
continue;
while ( V_60 && V_60 -> V_63 ) {
if ( V_60 -> V_64 == V_54 )
return true ;
V_60 ++ ;
}
break;
}
return false ;
}
static int F_41 ( struct V_15 * V_16 ,
T_1 V_20 , T_1 V_54 , struct V_48 * V_51 ,
struct V_65 * * V_66 , unsigned * V_67 ,
unsigned * V_68 )
{
if ( * V_68 == * V_67 )
return - V_69 ;
( * V_66 ) [ * V_68 ] . type = V_70 ;
( * V_66 ) [ * V_68 ] . V_45 . V_71 . V_72 = V_51 -> V_63 ;
if ( ! F_40 ( V_16 , V_20 , V_54 ) ) {
F_14 ( V_16 -> V_23 , L_3 ,
V_54 , V_20 ) ;
return - V_24 ;
}
( * V_66 ) [ * V_68 ] . V_45 . V_71 . V_3 = V_73 [ V_54 ] ;
( * V_68 ) ++ ;
return 0 ;
}
static int F_42 ( struct V_74 * V_75 ,
struct V_76 * V_77 ,
struct V_65 * * V_66 ,
unsigned * V_67 ,
unsigned * V_68 )
{
struct V_15 * V_16 ;
struct V_48 * V_51 ;
struct V_78 * V_58 ;
T_1 V_79 , V_20 , V_60 ;
unsigned long * V_80 ;
unsigned int V_81 ;
bool V_82 = 0 ;
unsigned V_83 = 0 ;
int V_84 , V_85 , V_86 , V_49 , V_87 ;
V_16 = F_43 ( V_75 ) ;
V_58 = F_44 ( V_77 , L_4 , NULL ) ;
if ( ! V_58 ) {
F_14 ( V_16 -> V_23 , L_5 ,
V_77 -> V_63 ) ;
return - V_24 ;
}
V_87 = F_45 ( V_77 , V_75 , & V_80 ,
& V_81 ) ;
if ( V_87 )
return V_87 ;
if ( V_81 )
V_82 = 1 ;
V_84 = V_58 -> V_88 / sizeof( T_1 ) ;
V_85 = V_84 ;
V_86 = 0 ;
if ( V_85 )
V_86 ++ ;
if ( V_82 && V_84 >= 1 )
V_86 ++ ;
if ( ! V_84 || ! V_86 )
return - V_24 ;
V_83 = V_84 * V_86 ;
V_87 = F_46 ( V_75 , V_66 ,
V_67 , V_68 , V_83 ) ;
if ( V_87 )
return V_87 ;
for ( V_49 = 0 ; V_49 < V_84 ; V_49 ++ ) {
V_87 = F_47 ( V_77 , L_4 ,
V_49 , & V_79 ) ;
if ( V_87 )
return V_87 ;
V_20 = F_48 ( V_79 ) ;
V_60 = F_49 ( V_79 ) ;
if ( ! F_40 ( V_16 , V_20 , V_60 ) ) {
F_14 ( V_16 -> V_23 , L_6 ) ;
return - V_24 ;
}
V_51 = F_39 ( V_16 , V_20 ) ;
if ( ! V_51 ) {
F_14 ( V_16 -> V_23 , L_7 ,
V_20 ) ;
return - V_24 ;
}
V_87 = F_41 ( V_16 , V_20 , V_60 , V_51 , V_66 ,
V_67 , V_68 ) ;
if ( V_87 )
return V_87 ;
if ( V_82 ) {
V_87 = F_50 ( V_75 , V_66 ,
V_67 , V_68 , V_51 -> V_63 ,
V_80 , V_81 ,
V_89 ) ;
if ( V_87 )
return V_87 ;
}
}
return 0 ;
}
static int F_51 ( struct V_74 * V_75 ,
struct V_76 * V_90 ,
struct V_65 * * V_66 , unsigned * V_68 )
{
struct V_76 * V_91 ;
unsigned V_67 ;
int V_25 ;
* V_66 = NULL ;
* V_68 = 0 ;
V_67 = 0 ;
F_52 (np_config, np) {
V_25 = F_42 ( V_75 , V_91 , V_66 ,
& V_67 , V_68 ) ;
if ( V_25 < 0 ) {
F_53 ( V_75 , * V_66 , * V_68 ) ;
return V_25 ;
}
}
return 0 ;
}
static int F_54 ( struct V_74 * V_75 )
{
struct V_15 * V_16 = F_43 ( V_75 ) ;
return V_16 -> V_50 ;
}
static const char * F_55 ( struct V_74 * V_75 ,
unsigned V_72 )
{
struct V_15 * V_16 = F_43 ( V_75 ) ;
return V_16 -> V_52 [ V_72 ] . V_63 ;
}
static int F_56 ( struct V_74 * V_75 ,
unsigned V_72 ,
const unsigned * * V_58 ,
unsigned * V_84 )
{
struct V_15 * V_16 = F_43 ( V_75 ) ;
* V_58 = ( unsigned * ) & V_16 -> V_52 [ V_72 ] . V_20 ;
* V_84 = 1 ;
return 0 ;
}
static int F_57 ( struct V_74 * V_75 )
{
return F_58 ( V_73 ) ;
}
static const char * F_59 ( struct V_74 * V_75 ,
unsigned V_92 )
{
return V_73 [ V_92 ] ;
}
static int F_60 ( struct V_74 * V_75 ,
unsigned V_3 ,
const char * const * * V_52 ,
unsigned * const V_93 )
{
struct V_15 * V_16 = F_43 ( V_75 ) ;
* V_52 = V_16 -> V_94 ;
* V_93 = V_16 -> V_50 ;
return 0 ;
}
static void F_61 ( struct V_6 * V_7 ,
int V_20 , T_1 V_33 , T_1 V_34 )
{
T_1 V_95 ;
int V_96 = ( V_20 % 8 ) * 4 ;
int V_97 = V_98 + ( V_20 / 8 ) * 4 ;
unsigned long V_99 ;
F_6 ( V_7 -> V_10 ) ;
F_62 ( & V_7 -> V_100 , V_99 ) ;
V_95 = F_19 ( V_7 -> V_11 + V_97 ) ;
V_95 &= ~ F_63 ( V_96 + 3 , V_96 ) ;
V_95 |= ( V_34 << V_96 ) ;
F_7 ( V_95 , V_7 -> V_11 + V_97 ) ;
V_95 = F_19 ( V_7 -> V_11 + V_101 ) ;
V_95 &= ~ F_63 ( V_20 * 2 + 1 , V_20 * 2 ) ;
V_95 |= V_33 << ( V_20 * 2 ) ;
F_7 ( V_95 , V_7 -> V_11 + V_101 ) ;
F_64 ( & V_7 -> V_100 , V_99 ) ;
F_9 ( V_7 -> V_10 ) ;
}
void F_28 ( struct V_6 * V_7 , int V_20 , T_1 * V_33 ,
T_1 * V_34 )
{
T_1 V_95 ;
int V_96 = ( V_20 % 8 ) * 4 ;
int V_97 = V_98 + ( V_20 / 8 ) * 4 ;
unsigned long V_99 ;
F_6 ( V_7 -> V_10 ) ;
F_62 ( & V_7 -> V_100 , V_99 ) ;
V_95 = F_19 ( V_7 -> V_11 + V_97 ) ;
V_95 &= F_63 ( V_96 + 3 , V_96 ) ;
* V_34 = V_95 >> V_96 ;
V_95 = F_19 ( V_7 -> V_11 + V_101 ) ;
V_95 &= F_63 ( V_20 * 2 + 1 , V_20 * 2 ) ;
* V_33 = V_95 >> ( V_20 * 2 ) ;
F_64 ( & V_7 -> V_100 , V_99 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static int F_65 ( struct V_74 * V_75 ,
unsigned V_3 ,
unsigned V_72 )
{
bool V_25 ;
struct V_15 * V_16 = F_43 ( V_75 ) ;
struct V_48 * V_102 = V_16 -> V_52 + V_72 ;
struct V_18 * V_19 ;
struct V_6 * V_7 ;
T_1 V_33 , V_34 ;
int V_20 ;
V_25 = F_40 ( V_16 , V_102 -> V_20 , V_3 ) ;
if ( ! V_25 ) {
F_14 ( V_16 -> V_23 , L_8 ,
V_3 , V_72 ) ;
return - V_24 ;
}
V_19 = F_66 ( V_75 , V_102 -> V_20 ) ;
V_7 = F_11 ( V_19 -> V_103 ) ;
V_20 = F_1 ( V_102 -> V_20 ) ;
V_33 = F_2 ( V_3 ) ;
V_34 = F_4 ( V_3 ) ;
F_61 ( V_7 , V_20 , V_33 , V_34 ) ;
return 0 ;
}
static int F_67 ( struct V_74 * V_75 ,
struct V_18 * V_19 , unsigned V_1 ,
bool V_104 )
{
struct V_6 * V_7 = F_11 ( V_19 -> V_103 ) ;
int V_20 = F_1 ( V_1 ) ;
F_61 ( V_7 , V_20 , ! V_104 , 0 ) ;
return 0 ;
}
static void F_68 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_105 )
{
unsigned long V_99 ;
T_1 V_95 ;
F_6 ( V_7 -> V_10 ) ;
F_62 ( & V_7 -> V_100 , V_99 ) ;
V_95 = F_19 ( V_7 -> V_11 + V_106 ) ;
V_95 &= ~ F_8 ( V_8 ) ;
V_95 |= V_105 << V_8 ;
F_7 ( V_95 , V_7 -> V_11 + V_106 ) ;
F_64 ( & V_7 -> V_100 , V_99 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_69 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_99 ;
T_1 V_95 ;
F_6 ( V_7 -> V_10 ) ;
F_62 ( & V_7 -> V_100 , V_99 ) ;
V_95 = F_19 ( V_7 -> V_11 + V_106 ) ;
V_95 &= F_8 ( V_8 ) ;
F_64 ( & V_7 -> V_100 , V_99 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_95 >> V_8 ) ;
}
static void F_70 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_107 )
{
unsigned long V_99 ;
T_1 V_95 ;
F_6 ( V_7 -> V_10 ) ;
F_62 ( & V_7 -> V_100 , V_99 ) ;
V_95 = F_19 ( V_7 -> V_11 + V_108 ) ;
V_95 &= ~ F_63 ( V_8 * 2 + 1 , V_8 * 2 ) ;
V_95 |= V_107 << ( V_8 * 2 ) ;
F_7 ( V_95 , V_7 -> V_11 + V_108 ) ;
F_64 ( & V_7 -> V_100 , V_99 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_71 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_99 ;
T_1 V_95 ;
F_6 ( V_7 -> V_10 ) ;
F_62 ( & V_7 -> V_100 , V_99 ) ;
V_95 = F_19 ( V_7 -> V_11 + V_108 ) ;
V_95 &= F_63 ( V_8 * 2 + 1 , V_8 * 2 ) ;
F_64 ( & V_7 -> V_100 , V_99 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_95 >> ( V_8 * 2 ) ) ;
}
static void F_72 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_109 )
{
unsigned long V_99 ;
T_1 V_95 ;
F_6 ( V_7 -> V_10 ) ;
F_62 ( & V_7 -> V_100 , V_99 ) ;
V_95 = F_19 ( V_7 -> V_11 + V_110 ) ;
V_95 &= ~ F_63 ( V_8 * 2 + 1 , V_8 * 2 ) ;
V_95 |= V_109 << ( V_8 * 2 ) ;
F_7 ( V_95 , V_7 -> V_11 + V_110 ) ;
F_64 ( & V_7 -> V_100 , V_99 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_73 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_99 ;
T_1 V_95 ;
F_6 ( V_7 -> V_10 ) ;
F_62 ( & V_7 -> V_100 , V_99 ) ;
V_95 = F_19 ( V_7 -> V_11 + V_110 ) ;
V_95 &= F_63 ( V_8 * 2 + 1 , V_8 * 2 ) ;
F_64 ( & V_7 -> V_100 , V_99 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_95 >> ( V_8 * 2 ) ) ;
}
static bool F_74 ( struct V_6 * V_7 ,
unsigned int V_8 , bool V_111 )
{
unsigned long V_99 ;
T_1 V_95 ;
F_6 ( V_7 -> V_10 ) ;
F_62 ( & V_7 -> V_100 , V_99 ) ;
if ( V_111 )
V_95 = ! ! ( F_19 ( V_7 -> V_11 + V_26 ) &
F_8 ( V_8 ) ) ;
else
V_95 = ! ! ( F_19 ( V_7 -> V_11 + V_112 ) &
F_8 ( V_8 ) ) ;
F_64 ( & V_7 -> V_100 , V_99 ) ;
F_9 ( V_7 -> V_10 ) ;
return V_95 ;
}
static int F_75 ( struct V_74 * V_75 ,
unsigned int V_20 , enum V_113 V_31 ,
enum V_113 V_114 )
{
struct V_18 * V_19 ;
struct V_6 * V_7 ;
int V_8 , V_25 = 0 ;
V_19 = F_66 ( V_75 , V_20 ) ;
V_7 = F_11 ( V_19 -> V_103 ) ;
V_8 = F_1 ( V_20 ) ;
switch ( V_31 ) {
case V_115 :
F_68 ( V_7 , V_8 , 0 ) ;
break;
case V_116 :
F_68 ( V_7 , V_8 , 1 ) ;
break;
case V_117 :
F_70 ( V_7 , V_8 , V_114 ) ;
break;
case V_118 :
F_72 ( V_7 , V_8 , 0 ) ;
break;
case V_119 :
F_72 ( V_7 , V_8 , 1 ) ;
break;
case V_120 :
F_72 ( V_7 , V_8 , 2 ) ;
break;
case V_121 :
F_5 ( V_7 , V_8 , V_114 ) ;
V_25 = F_67 ( V_75 , V_19 , V_20 , false ) ;
break;
default:
V_25 = - V_24 ;
}
return V_25 ;
}
static int F_76 ( struct V_74 * V_75 ,
unsigned V_72 ,
unsigned long * V_122 )
{
struct V_15 * V_16 = F_43 ( V_75 ) ;
* V_122 = V_16 -> V_52 [ V_72 ] . V_122 ;
return 0 ;
}
static int F_77 ( struct V_74 * V_75 , unsigned V_72 ,
unsigned long * V_80 , unsigned V_81 )
{
struct V_15 * V_16 = F_43 ( V_75 ) ;
struct V_48 * V_102 = & V_16 -> V_52 [ V_72 ] ;
int V_49 , V_25 ;
for ( V_49 = 0 ; V_49 < V_81 ; V_49 ++ ) {
V_25 = F_75 ( V_75 , V_102 -> V_20 ,
F_78 ( V_80 [ V_49 ] ) ,
F_79 ( V_80 [ V_49 ] ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_102 -> V_122 = V_80 [ V_49 ] ;
}
return 0 ;
}
static void F_80 ( struct V_74 * V_75 ,
struct V_123 * V_124 ,
unsigned int V_20 )
{
struct V_18 * V_19 ;
struct V_6 * V_7 ;
int V_8 ;
T_1 V_33 , V_34 , V_105 , V_107 , V_109 ;
static const char * const V_125 [] = {
L_9 , L_10 , L_11 , L_12 } ;
static const char * const V_126 [] = {
L_13 , L_14 , L_15 , L_16 } ;
static const char * const V_127 [] = {
L_17 , L_18 , L_19 , L_20 } ;
bool V_95 ;
V_19 = F_13 ( V_75 , V_20 ) ;
V_7 = F_11 ( V_19 -> V_103 ) ;
V_8 = F_1 ( V_20 ) ;
F_28 ( V_7 , V_8 , & V_33 , & V_34 ) ;
V_109 = F_73 ( V_7 , V_8 ) ;
F_81 ( V_124 , L_21 , V_125 [ V_33 ] ) ;
switch ( V_33 ) {
case 0 :
V_95 = F_74 ( V_7 , V_8 , true ) ;
F_81 ( V_124 , L_22 ,
V_95 ? L_15 : L_13 ,
V_127 [ V_109 ] ) ;
break;
case 1 :
V_105 = F_69 ( V_7 , V_8 ) ;
V_107 = F_71 ( V_7 , V_8 ) ;
V_95 = F_74 ( V_7 , V_8 , false ) ;
F_81 ( V_124 , L_23 ,
V_95 ? L_15 : L_13 ,
V_105 ? L_24 : L_25 ,
V_127 [ V_109 ] ,
V_126 [ V_107 ] , L_26 ) ;
break;
case 2 :
V_105 = F_69 ( V_7 , V_8 ) ;
V_107 = F_71 ( V_7 , V_8 ) ;
F_81 ( V_124 , L_27 , V_34 ,
V_105 ? L_24 : L_25 ,
V_127 [ V_109 ] ,
V_126 [ V_107 ] , L_26 ) ;
break;
case 3 :
break;
}
}
static int F_82 ( struct V_15 * V_16 ,
struct V_76 * V_91 )
{
struct V_6 * V_7 = & V_16 -> V_128 [ V_16 -> V_129 ] ;
struct V_18 * V_19 = & V_7 -> V_19 ;
struct V_130 args ;
struct V_131 * V_23 = V_16 -> V_23 ;
struct V_132 V_133 ;
struct V_134 * V_135 ;
int V_56 = V_2 ;
int V_21 , V_87 ;
V_135 = F_83 ( V_91 , NULL ) ;
if ( ! F_84 ( V_135 ) )
F_85 ( V_135 ) ;
if ( F_86 ( V_91 , 0 , & V_133 ) )
return - V_136 ;
V_7 -> V_11 = F_87 ( V_23 , & V_133 ) ;
if ( F_84 ( V_7 -> V_11 ) )
return F_88 ( V_7 -> V_11 ) ;
V_7 -> V_10 = F_89 ( V_91 , NULL ) ;
if ( F_84 ( V_7 -> V_10 ) ) {
F_14 ( V_23 , L_28 , F_88 ( V_7 -> V_10 ) ) ;
return F_88 ( V_7 -> V_10 ) ;
}
V_87 = F_90 ( V_7 -> V_10 ) ;
if ( V_87 ) {
F_14 ( V_23 , L_29 , V_87 ) ;
return V_87 ;
}
V_7 -> V_13 = V_137 ;
F_91 ( V_91 , L_30 , & V_7 -> V_13 . V_138 ) ;
if ( ! F_92 ( V_91 , L_31 , 3 , 0 , & args ) ) {
V_21 = args . args [ 1 ] / V_2 ;
V_7 -> V_13 . V_11 = args . args [ 1 ] ;
} else {
V_21 = V_16 -> V_129 ;
V_7 -> V_13 . V_11 = V_21 * V_2 ;
V_19 -> V_63 = V_7 -> V_13 . V_138 ;
V_19 -> V_139 = V_21 ;
V_19 -> V_140 = V_19 -> V_139 * V_2 ;
V_19 -> V_11 = V_19 -> V_139 * V_2 ;
V_19 -> V_56 = V_56 ;
V_19 -> V_103 = & V_7 -> V_13 ;
F_93 ( V_16 -> V_22 ,
& V_16 -> V_128 [ V_21 ] . V_19 ) ;
}
V_7 -> V_13 . V_11 = V_21 * V_2 ;
V_7 -> V_13 . V_141 = V_56 ;
V_7 -> V_13 . V_142 = V_91 ;
V_7 -> V_13 . V_17 = V_23 ;
V_7 -> V_21 = V_21 ;
F_94 ( & V_7 -> V_100 ) ;
V_7 -> V_29 = F_95 ( V_91 ) ;
V_7 -> V_36 = F_96 ( V_16 -> V_36 , 0 ,
V_41 , V_7 -> V_29 ,
& V_143 , V_7 ) ;
if ( ! V_7 -> V_36 )
return - V_136 ;
V_87 = F_97 ( & V_7 -> V_13 , V_7 ) ;
if ( V_87 ) {
F_14 ( V_23 , L_32 , V_21 ) ;
return V_87 ;
}
F_98 ( V_23 , L_33 , V_7 -> V_13 . V_138 ) ;
return 0 ;
}
static int F_99 ( struct V_144 * V_145 ,
struct V_15 * V_16 )
{
struct V_76 * V_91 = V_145 -> V_23 . V_142 , * V_17 ;
struct V_131 * V_23 = & V_145 -> V_23 ;
struct V_146 * V_147 ;
int V_8 , V_25 , V_49 ;
V_17 = F_100 ( V_91 ) ;
if ( ! V_17 )
return - V_148 ;
V_16 -> V_36 = F_101 ( V_17 ) ;
if ( ! V_16 -> V_36 )
return - V_148 ;
V_16 -> V_146 = F_102 ( V_91 , L_34 ) ;
if ( F_84 ( V_16 -> V_146 ) )
return F_88 ( V_16 -> V_146 ) ;
V_147 = V_16 -> V_146 ;
V_25 = F_47 ( V_91 , L_34 , 1 , & V_8 ) ;
if ( V_25 )
return V_25 ;
for ( V_49 = 0 ; V_49 < V_2 ; V_49 ++ ) {
struct V_149 V_71 ;
V_71 . V_150 = V_8 + ( V_49 / 4 ) * 4 ;
V_71 . V_151 = ( V_49 % 4 ) * 4 ;
V_71 . V_152 = V_71 . V_151 + 3 ;
V_16 -> V_42 [ V_49 ] = F_103 ( V_23 , V_147 , V_71 ) ;
if ( F_84 ( V_16 -> V_42 [ V_49 ] ) )
return F_88 ( V_16 -> V_42 [ V_49 ] ) ;
}
return 0 ;
}
static int F_104 ( struct V_144 * V_145 )
{
struct V_15 * V_16 = F_105 ( V_145 ) ;
int V_49 ;
V_16 -> V_50 = V_16 -> V_55 -> V_56 ;
V_16 -> V_52 = F_106 ( & V_145 -> V_23 , V_16 -> V_50 ,
sizeof( * V_16 -> V_52 ) , V_153 ) ;
if ( ! V_16 -> V_52 )
return - V_154 ;
V_16 -> V_94 = F_106 ( & V_145 -> V_23 , V_16 -> V_50 ,
sizeof( * V_16 -> V_94 ) , V_153 ) ;
if ( ! V_16 -> V_94 )
return - V_154 ;
for ( V_49 = 0 ; V_49 < V_16 -> V_55 -> V_56 ; V_49 ++ ) {
const struct V_57 * V_20 = V_16 -> V_55 -> V_58 + V_49 ;
struct V_48 * V_72 = V_16 -> V_52 + V_49 ;
V_72 -> V_63 = V_20 -> V_20 . V_63 ;
V_72 -> V_20 = V_20 -> V_20 . V_62 ;
V_16 -> V_94 [ V_49 ] = V_20 -> V_20 . V_63 ;
}
return 0 ;
}
int F_107 ( struct V_144 * V_145 )
{
struct V_76 * V_91 = V_145 -> V_23 . V_142 ;
struct V_76 * V_155 ;
const struct V_156 * V_157 ;
struct V_131 * V_23 = & V_145 -> V_23 ;
struct V_15 * V_16 ;
struct V_158 * V_58 ;
int V_49 , V_25 , V_128 = 0 ;
if ( ! V_91 )
return - V_24 ;
V_157 = F_108 ( V_23 -> V_159 -> V_160 , V_23 ) ;
if ( ! V_157 || ! V_157 -> V_45 )
return - V_24 ;
if ( ! F_44 ( V_91 , L_35 , NULL ) ) {
F_14 ( V_23 , L_36 ) ;
return - V_24 ;
}
V_16 = F_109 ( V_23 , sizeof( * V_16 ) , V_153 ) ;
if ( ! V_16 )
return - V_154 ;
F_110 ( V_145 , V_16 ) ;
V_16 -> V_23 = V_23 ;
V_16 -> V_55 = V_157 -> V_45 ;
V_25 = F_104 ( V_145 ) ;
if ( V_25 ) {
F_14 ( V_23 , L_37 , V_25 ) ;
return - V_24 ;
}
if ( F_44 ( V_91 , L_38 , NULL ) ) {
V_25 = F_99 ( V_145 , V_16 ) ;
if ( V_25 )
return V_25 ;
}
V_58 = F_106 ( & V_145 -> V_23 , V_16 -> V_55 -> V_56 , sizeof( * V_58 ) ,
V_153 ) ;
if ( ! V_58 )
return - V_154 ;
for ( V_49 = 0 ; V_49 < V_16 -> V_55 -> V_56 ; V_49 ++ )
V_58 [ V_49 ] = V_16 -> V_55 -> V_58 [ V_49 ] . V_20 ;
V_16 -> V_161 . V_63 = F_111 ( & V_145 -> V_23 ) ;
V_16 -> V_161 . V_162 = V_163 ;
V_16 -> V_161 . V_58 = V_58 ;
V_16 -> V_161 . V_56 = V_16 -> V_55 -> V_56 ;
V_16 -> V_161 . V_164 = & V_165 ;
V_16 -> V_161 . V_166 = & V_167 ;
V_16 -> V_161 . V_168 = & V_169 ;
V_16 -> V_23 = & V_145 -> V_23 ;
V_16 -> V_22 = F_112 ( & V_145 -> V_23 , & V_16 -> V_161 ,
V_16 ) ;
if ( F_84 ( V_16 -> V_22 ) ) {
F_14 ( & V_145 -> V_23 , L_39 ) ;
return F_88 ( V_16 -> V_22 ) ;
}
F_52 (np, child)
if ( F_113 ( V_155 , L_40 ) )
V_128 ++ ;
if ( ! V_128 ) {
F_14 ( V_23 , L_41 ) ;
return - V_24 ;
}
V_16 -> V_128 = F_106 ( V_23 , V_128 , sizeof( * V_16 -> V_128 ) ,
V_153 ) ;
if ( ! V_16 -> V_128 )
return - V_154 ;
F_52 (np, child) {
if ( F_113 ( V_155 , L_40 ) ) {
V_25 = F_82 ( V_16 , V_155 ) ;
if ( V_25 )
return V_25 ;
V_16 -> V_129 ++ ;
}
}
F_98 ( V_23 , L_42 ) ;
return 0 ;
}
