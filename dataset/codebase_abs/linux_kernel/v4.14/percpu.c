static void F_1 ( void )
{
if ( V_1 )
F_2 ( & V_2 ) ;
}
static bool F_3 ( struct V_3 * V_4 , void * V_5 )
{
void * V_6 , * V_7 ;
if ( ! V_4 )
return false ;
V_6 = V_4 -> V_8 + V_4 -> V_9 ;
V_7 = V_4 -> V_8 + V_4 -> V_10 * V_11 -
V_4 -> V_12 ;
return V_5 >= V_6 && V_5 < V_7 ;
}
static int F_4 ( int V_13 )
{
int V_14 = F_5 ( V_13 ) ;
return F_6 ( V_14 - V_15 + 2 , 1 ) ;
}
static int F_7 ( int V_13 )
{
if ( V_13 == V_16 )
return V_17 - 1 ;
return F_4 ( V_13 ) ;
}
static int F_8 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_18 < V_19 || V_4 -> V_20 == 0 )
return 0 ;
return F_7 ( V_4 -> V_18 ) ;
}
static void F_9 ( struct V_21 * V_21 , struct V_3 * V_22 )
{
V_21 -> V_23 = ( unsigned long ) V_22 ;
}
static struct V_3 * F_10 ( struct V_21 * V_21 )
{
return (struct V_3 * ) V_21 -> V_23 ;
}
static int T_1 F_11 ( unsigned int V_24 , int V_25 )
{
return V_26 [ V_24 ] * V_27 + V_25 ;
}
static unsigned long F_12 ( unsigned int V_24 , int V_25 )
{
return V_28 [ V_24 ] + ( V_25 << V_29 ) ;
}
static unsigned long F_13 ( struct V_3 * V_4 ,
unsigned int V_24 , int V_25 )
{
return ( unsigned long ) V_4 -> V_8 +
F_12 ( V_24 , V_25 ) ;
}
static void F_14 ( unsigned long * V_30 , int * V_31 , int * V_32 , int V_33 )
{
* V_31 = F_15 ( V_30 , V_33 , * V_31 ) ;
* V_32 = F_16 ( V_30 , V_33 , * V_31 + 1 ) ;
}
static void F_17 ( unsigned long * V_30 , int * V_31 , int * V_32 , int V_33 )
{
* V_31 = F_16 ( V_30 , V_33 , * V_31 ) ;
* V_32 = F_15 ( V_30 , V_33 , * V_31 + 1 ) ;
}
static unsigned long * F_18 ( struct V_3 * V_4 , int V_23 )
{
return V_4 -> V_34 +
( V_23 * V_35 / V_36 ) ;
}
static unsigned long F_19 ( int V_37 )
{
return V_37 / V_35 ;
}
static unsigned long F_20 ( int V_37 )
{
return V_37 & ( V_35 - 1 ) ;
}
static unsigned long F_21 ( int V_23 , int V_37 )
{
return V_23 * V_35 + V_37 ;
}
static void F_22 ( struct V_3 * V_4 , int * V_38 ,
int * V_39 )
{
int V_40 = F_19 ( * V_38 ) ;
int V_41 = F_20 ( * V_38 ) ;
struct V_42 * V_43 ;
* V_39 = 0 ;
for ( V_43 = V_4 -> V_44 + V_40 ; V_40 < F_23 ( V_4 ) ;
V_43 ++ , V_40 ++ ) {
if ( * V_39 ) {
* V_39 += V_43 -> V_45 ;
if ( V_43 -> V_45 == V_35 )
continue;
return;
}
* V_39 = V_43 -> V_46 ;
if ( * V_39 && V_43 -> V_47 >= V_41 &&
* V_39 + V_43 -> V_47 < V_35 ) {
* V_38 = F_21 ( V_40 ,
V_43 -> V_47 ) ;
return;
}
V_41 = 0 ;
* V_39 = V_43 -> V_48 ;
* V_38 = ( V_40 + 1 ) * V_35 - V_43 -> V_48 ;
}
}
static void F_24 ( struct V_3 * V_4 , int V_49 ,
int V_50 , int * V_38 , int * V_39 )
{
int V_40 = F_19 ( * V_38 ) ;
int V_41 = F_20 ( * V_38 ) ;
struct V_42 * V_43 ;
* V_39 = 0 ;
for ( V_43 = V_4 -> V_44 + V_40 ; V_40 < F_23 ( V_4 ) ;
V_43 ++ , V_40 ++ ) {
if ( * V_39 ) {
* V_39 += V_43 -> V_45 ;
if ( * V_39 >= V_49 )
return;
if ( V_43 -> V_45 == V_35 )
continue;
}
* V_39 = F_25 ( V_43 -> V_47 , V_50 ) -
V_43 -> V_47 ;
if ( V_43 -> V_46 &&
V_43 -> V_47 >= V_41 &&
V_43 -> V_46 >= * V_39 + V_49 ) {
* V_39 += V_49 + V_43 -> V_47 -
V_43 -> V_51 ;
* V_38 = F_21 ( V_40 , V_43 -> V_51 ) ;
return;
}
V_41 = 0 ;
* V_38 = F_25 ( V_35 - V_43 -> V_48 ,
V_50 ) ;
* V_39 = V_35 - * V_38 ;
* V_38 = F_21 ( V_40 , * V_38 ) ;
if ( * V_39 >= V_49 )
return;
}
* V_38 = F_26 ( V_4 ) ;
}
static void * F_27 ( T_2 V_13 )
{
if ( F_28 ( ! F_29 () ) )
return NULL ;
if ( V_13 <= V_11 )
return F_30 ( V_13 , V_52 ) ;
else
return F_31 ( V_13 ) ;
}
static void F_32 ( void * V_53 )
{
F_33 ( V_53 ) ;
}
static void F_34 ( struct V_3 * V_4 , int V_54 )
{
int V_55 = F_8 ( V_4 ) ;
if ( V_4 != V_56 && V_54 != V_55 ) {
if ( V_54 < V_55 )
F_35 ( & V_4 -> V_57 , & V_58 [ V_55 ] ) ;
else
F_36 ( & V_4 -> V_57 , & V_58 [ V_55 ] ) ;
}
}
static inline int F_37 ( struct V_3 * V_4 , int V_38 ,
int V_39 )
{
int V_59 = F_38 ( V_38 * V_19 ) ;
int V_60 = F_39 ( ( V_38 + V_39 ) * V_19 ) ;
if ( V_59 >= V_60 )
return 0 ;
return F_40 ( V_4 -> V_61 , V_60 ) -
F_40 ( V_4 -> V_61 , V_59 ) ;
}
static void F_41 ( struct V_3 * V_4 , int V_38 , int V_39 )
{
if ( V_39 > V_4 -> V_20 ) {
V_4 -> V_62 = V_38 ;
V_4 -> V_20 = V_39 ;
} else if ( V_39 == V_4 -> V_20 && V_4 -> V_62 &&
( ! V_38 ||
F_42 ( V_38 ) > F_42 ( V_4 -> V_62 ) ) ) {
V_4 -> V_62 = V_38 ;
}
}
static void F_43 ( struct V_3 * V_4 )
{
int V_38 , V_39 , V_63 ;
V_4 -> V_20 = 0 ;
V_38 = V_4 -> V_64 ;
V_39 = V_63 = 0 ;
F_44 (chunk, bit_off, bits) {
F_41 ( V_4 , V_38 , V_39 ) ;
V_63 += F_37 ( V_4 , V_38 , V_39 ) ;
}
if ( V_4 != V_56 )
V_65 +=
( V_63 - V_4 -> V_63 ) ;
V_4 -> V_63 = V_63 ;
}
static void F_45 ( struct V_42 * V_43 , int V_66 , int V_33 )
{
int V_67 = V_33 - V_66 ;
V_43 -> V_51 = F_46 ( V_43 -> V_51 , V_66 ) ;
if ( V_66 == 0 )
V_43 -> V_45 = V_67 ;
if ( V_33 == V_35 )
V_43 -> V_48 = V_67 ;
if ( V_67 > V_43 -> V_46 ) {
V_43 -> V_47 = V_66 ;
V_43 -> V_46 = V_67 ;
} else if ( V_43 -> V_47 && V_67 == V_43 -> V_46 &&
( ! V_66 || F_42 ( V_66 ) > F_42 ( V_43 -> V_47 ) ) ) {
V_43 -> V_47 = V_66 ;
}
}
static void F_47 ( struct V_3 * V_4 , int V_23 )
{
struct V_42 * V_43 = V_4 -> V_44 + V_23 ;
unsigned long * V_34 = F_18 ( V_4 , V_23 ) ;
int V_31 , V_32 ;
V_43 -> V_46 = 0 ;
V_43 -> V_45 = V_43 -> V_48 = 0 ;
F_48 (alloc_map, rs, re, block->first_free,
PCPU_BITMAP_BLOCK_BITS) {
F_45 ( V_43 , V_31 , V_32 ) ;
}
}
static void F_49 ( struct V_3 * V_4 , int V_38 ,
int V_39 )
{
struct V_42 * V_68 , * V_69 , * V_43 ;
int V_70 , V_71 ;
int V_72 , V_73 ;
V_70 = F_19 ( V_38 ) ;
V_71 = F_19 ( V_38 + V_39 - 1 ) ;
V_72 = F_20 ( V_38 ) ;
V_73 = F_20 ( V_38 + V_39 - 1 ) + 1 ;
V_68 = V_4 -> V_44 + V_70 ;
V_69 = V_4 -> V_44 + V_71 ;
if ( V_72 == V_68 -> V_51 )
V_68 -> V_51 = F_15 (
F_18 ( V_4 , V_70 ) ,
V_35 ,
V_72 + V_39 ) ;
if ( V_72 >= V_68 -> V_47 &&
V_72 < V_68 -> V_47 + V_68 -> V_46 ) {
F_47 ( V_4 , V_70 ) ;
} else {
V_68 -> V_45 = F_46 ( V_68 -> V_45 , V_72 ) ;
if ( V_70 == V_71 )
V_68 -> V_48 = F_50 ( int , V_68 -> V_48 ,
V_35 - V_73 ) ;
else
V_68 -> V_48 = 0 ;
}
if ( V_70 != V_71 ) {
V_69 -> V_51 = F_15 (
F_18 ( V_4 , V_71 ) ,
V_35 , V_73 ) ;
if ( V_73 == V_35 ) {
V_69 ++ ;
} else {
if ( V_73 > V_69 -> V_47 ) {
F_47 ( V_4 , V_71 ) ;
} else {
V_69 -> V_45 = 0 ;
V_69 -> V_48 =
F_50 ( int , V_69 -> V_48 ,
V_35 - V_73 ) ;
}
}
for ( V_43 = V_68 + 1 ; V_43 < V_69 ; V_43 ++ ) {
V_43 -> V_46 = 0 ;
V_43 -> V_45 = 0 ;
V_43 -> V_48 = 0 ;
}
}
if ( V_38 >= V_4 -> V_62 &&
V_38 < V_4 -> V_62 + V_4 -> V_20 )
F_43 ( V_4 ) ;
}
static void F_51 ( struct V_3 * V_4 , int V_38 ,
int V_39 )
{
struct V_42 * V_68 , * V_69 , * V_43 ;
int V_70 , V_71 ;
int V_72 , V_73 ;
int V_66 , V_33 ;
V_70 = F_19 ( V_38 ) ;
V_71 = F_19 ( V_38 + V_39 - 1 ) ;
V_72 = F_20 ( V_38 ) ;
V_73 = F_20 ( V_38 + V_39 - 1 ) + 1 ;
V_68 = V_4 -> V_44 + V_70 ;
V_69 = V_4 -> V_44 + V_71 ;
V_66 = V_72 ;
if ( V_72 == V_68 -> V_46 + V_68 -> V_47 ) {
V_66 = V_68 -> V_47 ;
} else {
int V_74 = F_52 ( F_18 ( V_4 , V_70 ) ,
V_66 ) ;
V_66 = ( V_66 == V_74 ) ? 0 : V_74 + 1 ;
}
V_33 = V_73 ;
if ( V_73 == V_69 -> V_47 )
V_33 = V_69 -> V_47 + V_69 -> V_46 ;
else
V_33 = F_16 ( F_18 ( V_4 , V_71 ) ,
V_35 , V_33 ) ;
V_73 = ( V_70 == V_71 ) ? V_33 : V_35 ;
F_45 ( V_68 , V_66 , V_73 ) ;
if ( V_70 != V_71 ) {
F_45 ( V_69 , 0 , V_33 ) ;
for ( V_43 = V_68 + 1 ; V_43 < V_69 ; V_43 ++ ) {
V_43 -> V_51 = 0 ;
V_43 -> V_47 = 0 ;
V_43 -> V_46 = V_35 ;
V_43 -> V_45 = V_35 ;
V_43 -> V_48 = V_35 ;
}
}
if ( ( F_53 ( V_33 , F_46 ( V_75 , V_35 ) ) >
F_25 ( V_66 , F_46 ( V_75 , V_35 ) ) ) ||
V_70 != V_71 )
F_43 ( V_4 ) ;
else
F_41 ( V_4 , F_21 ( V_70 , V_66 ) ,
V_68 -> V_46 ) ;
}
static bool F_54 ( struct V_3 * V_4 , int V_38 , int V_39 ,
int * V_76 )
{
int V_59 , V_60 , V_31 , V_32 ;
V_59 = F_39 ( V_38 * V_19 ) ;
V_60 = F_38 ( ( V_38 + V_39 ) * V_19 ) ;
V_31 = V_59 ;
F_14 ( V_4 -> V_61 , & V_31 , & V_32 , V_60 ) ;
if ( V_31 >= V_60 )
return true ;
* V_76 = V_32 * V_11 / V_19 ;
return false ;
}
static int F_55 ( struct V_3 * V_4 , int V_49 ,
T_2 V_50 , bool V_77 )
{
int V_38 , V_39 , V_76 ;
V_38 = F_25 ( V_4 -> V_62 , V_50 ) -
V_4 -> V_62 ;
if ( V_38 + V_49 > V_4 -> V_20 )
return - 1 ;
V_38 = V_4 -> V_64 ;
V_39 = 0 ;
F_56 (chunk, alloc_bits, align, bit_off, bits) {
if ( ! V_77 || F_54 ( V_4 , V_38 , V_39 ,
& V_76 ) )
break;
V_38 = V_76 ;
V_39 = 0 ;
}
if ( V_38 == F_26 ( V_4 ) )
return - 1 ;
return V_38 ;
}
static int F_57 ( struct V_3 * V_4 , int V_49 ,
T_2 V_50 , int V_66 )
{
T_2 V_78 = ( V_50 ) ? ( V_50 - 1 ) : 0 ;
int V_38 , V_33 , V_54 ;
F_58 ( & V_79 ) ;
V_54 = F_8 ( V_4 ) ;
V_33 = V_66 + V_49 + V_35 ;
V_38 = F_59 ( V_4 -> V_34 , V_33 , V_66 ,
V_49 , V_78 ) ;
if ( V_38 >= V_33 )
return - 1 ;
F_60 ( V_4 -> V_34 , V_38 , V_49 ) ;
F_61 ( V_38 , V_4 -> V_80 ) ;
F_62 ( V_4 -> V_80 , V_38 + 1 , V_49 - 1 ) ;
F_61 ( V_38 + V_49 , V_4 -> V_80 ) ;
V_4 -> V_18 -= V_49 * V_19 ;
if ( V_38 == V_4 -> V_64 )
V_4 -> V_64 = F_15 (
V_4 -> V_34 ,
F_26 ( V_4 ) ,
V_38 + V_49 ) ;
F_49 ( V_4 , V_38 , V_49 ) ;
F_34 ( V_4 , V_54 ) ;
return V_38 * V_19 ;
}
static void F_63 ( struct V_3 * V_4 , int V_37 )
{
int V_38 , V_39 , V_33 , V_54 ;
F_58 ( & V_79 ) ;
F_64 ( V_4 ) ;
V_54 = F_8 ( V_4 ) ;
V_38 = V_37 / V_19 ;
V_33 = F_16 ( V_4 -> V_80 , F_26 ( V_4 ) ,
V_38 + 1 ) ;
V_39 = V_33 - V_38 ;
F_62 ( V_4 -> V_34 , V_38 , V_39 ) ;
V_4 -> V_18 += V_39 * V_19 ;
V_4 -> V_64 = F_46 ( V_4 -> V_64 , V_38 ) ;
F_51 ( V_4 , V_38 , V_39 ) ;
F_34 ( V_4 , V_54 ) ;
}
static void F_65 ( struct V_3 * V_4 )
{
struct V_42 * V_81 ;
for ( V_81 = V_4 -> V_44 ;
V_81 != V_4 -> V_44 + F_23 ( V_4 ) ;
V_81 ++ ) {
V_81 -> V_46 = V_35 ;
V_81 -> V_45 = V_35 ;
V_81 -> V_48 = V_35 ;
}
}
static struct V_3 * T_3 F_66 ( unsigned long V_82 ,
int V_83 )
{
struct V_3 * V_4 ;
unsigned long V_84 , V_85 ;
int V_9 , V_86 , V_87 , V_88 ;
V_84 = V_82 & V_89 ;
V_9 = V_82 - V_84 ;
V_85 = F_67 ( V_11 , V_90 ) ;
V_87 = F_25 ( V_9 + V_83 , V_85 ) ;
V_4 = F_68 ( sizeof( struct V_3 ) +
F_69 ( V_87 >> V_29 ) ,
0 ) ;
F_70 ( & V_4 -> V_57 ) ;
V_4 -> V_8 = ( void * ) V_84 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_12 = V_87 - V_4 -> V_9 - V_83 ;
V_4 -> V_10 = V_87 >> V_29 ;
V_88 = F_26 ( V_4 ) ;
V_4 -> V_34 = F_68 ( F_69 ( V_88 ) *
sizeof( V_4 -> V_34 [ 0 ] ) , 0 ) ;
V_4 -> V_80 = F_68 ( F_69 ( V_88 + 1 ) *
sizeof( V_4 -> V_80 [ 0 ] ) , 0 ) ;
V_4 -> V_44 = F_68 ( F_23 ( V_4 ) *
sizeof( V_4 -> V_44 [ 0 ] ) , 0 ) ;
F_65 ( V_4 ) ;
V_4 -> V_91 = true ;
F_71 ( V_4 -> V_61 , V_4 -> V_10 ) ;
V_4 -> V_92 = V_4 -> V_10 ;
V_4 -> V_63 =
F_37 ( V_4 , V_9 / V_19 ,
V_83 / V_19 ) ;
V_4 -> V_20 = V_83 / V_19 ;
V_4 -> V_18 = V_83 ;
if ( V_4 -> V_9 ) {
V_86 = V_4 -> V_9 / V_19 ;
F_60 ( V_4 -> V_34 , 0 , V_86 ) ;
F_61 ( 0 , V_4 -> V_80 ) ;
F_61 ( V_86 , V_4 -> V_80 ) ;
V_4 -> V_64 = V_86 ;
F_49 ( V_4 , 0 , V_86 ) ;
}
if ( V_4 -> V_12 ) {
V_86 = V_4 -> V_12 / V_19 ;
F_60 ( V_4 -> V_34 ,
F_26 ( V_4 ) - V_86 ,
V_86 ) ;
F_61 ( ( V_9 + V_83 ) / V_19 ,
V_4 -> V_80 ) ;
F_61 ( V_88 , V_4 -> V_80 ) ;
F_49 ( V_4 , F_26 ( V_4 )
- V_86 , V_86 ) ;
}
return V_4 ;
}
static struct V_3 * F_72 ( void )
{
struct V_3 * V_4 ;
int V_88 ;
V_4 = F_27 ( V_93 ) ;
if ( ! V_4 )
return NULL ;
F_70 ( & V_4 -> V_57 ) ;
V_4 -> V_10 = V_27 ;
V_88 = F_26 ( V_4 ) ;
V_4 -> V_34 = F_27 ( F_69 ( V_88 ) *
sizeof( V_4 -> V_34 [ 0 ] ) ) ;
if ( ! V_4 -> V_34 )
goto V_94;
V_4 -> V_80 = F_27 ( F_69 ( V_88 + 1 ) *
sizeof( V_4 -> V_80 [ 0 ] ) ) ;
if ( ! V_4 -> V_80 )
goto V_95;
V_4 -> V_44 = F_27 ( F_23 ( V_4 ) *
sizeof( V_4 -> V_44 [ 0 ] ) ) ;
if ( ! V_4 -> V_44 )
goto V_96;
F_65 ( V_4 ) ;
V_4 -> V_20 = V_88 ;
V_4 -> V_18 = V_4 -> V_10 * V_11 ;
return V_4 ;
V_96:
F_32 ( V_4 -> V_80 ) ;
V_95:
F_32 ( V_4 -> V_34 ) ;
V_94:
F_32 ( V_4 ) ;
return NULL ;
}
static void F_73 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
F_32 ( V_4 -> V_80 ) ;
F_32 ( V_4 -> V_34 ) ;
F_32 ( V_4 ) ;
}
static void F_74 ( struct V_3 * V_4 , int V_59 ,
int V_60 , bool V_97 )
{
int V_98 = V_60 - V_59 ;
F_58 ( & V_79 ) ;
F_60 ( V_4 -> V_61 , V_59 , V_98 ) ;
V_4 -> V_92 += V_98 ;
if ( ! V_97 ) {
V_4 -> V_63 += V_98 ;
V_65 += V_98 ;
}
}
static void F_75 ( struct V_3 * V_4 ,
int V_59 , int V_60 )
{
int V_98 = V_60 - V_59 ;
F_58 ( & V_79 ) ;
F_62 ( V_4 -> V_61 , V_59 , V_98 ) ;
V_4 -> V_92 -= V_98 ;
V_4 -> V_63 -= V_98 ;
V_65 -= V_98 ;
}
static struct V_3 * F_76 ( void * V_5 )
{
if ( F_3 ( V_99 , V_5 ) )
return V_99 ;
if ( F_3 ( V_56 , V_5 ) )
return V_56 ;
V_5 += V_28 [ F_77 () ] ;
return F_10 ( F_78 ( V_5 ) ) ;
}
static void T_4 * F_79 ( T_2 V_13 , T_2 V_50 , bool V_100 ,
T_5 V_101 )
{
bool V_102 = ( V_101 & V_52 ) != V_52 ;
bool V_103 = ! ( V_101 & V_104 ) ;
static int V_105 = 10 ;
struct V_3 * V_4 ;
const char * V_106 ;
int V_107 , V_37 , V_24 , V_108 ;
unsigned long V_109 ;
void T_4 * V_53 ;
T_2 V_39 , V_110 ;
if ( F_80 ( V_50 < V_19 ) )
V_50 = V_19 ;
V_13 = F_25 ( V_13 , V_19 ) ;
V_39 = V_13 >> V_111 ;
V_110 = V_50 >> V_111 ;
if ( F_80 ( ! V_13 || V_13 > V_112 || V_50 > V_11 ||
! F_81 ( V_50 ) ) ) {
F_82 ( V_103 , L_1 ,
V_13 , V_50 ) ;
return NULL ;
}
if ( ! V_102 )
F_83 ( & V_113 ) ;
F_84 ( & V_79 , V_109 ) ;
if ( V_100 && V_56 ) {
V_4 = V_56 ;
V_37 = F_55 ( V_4 , V_39 , V_110 , V_102 ) ;
if ( V_37 < 0 ) {
V_106 = L_2 ;
goto V_114;
}
V_37 = F_57 ( V_4 , V_39 , V_110 , V_37 ) ;
if ( V_37 >= 0 )
goto V_115;
V_106 = L_2 ;
goto V_114;
}
V_116:
for ( V_107 = F_7 ( V_13 ) ; V_107 < V_17 ; V_107 ++ ) {
F_85 (chunk, &pcpu_slot[slot], list) {
V_37 = F_55 ( V_4 , V_39 , V_110 ,
V_102 ) ;
if ( V_37 < 0 )
continue;
V_37 = F_57 ( V_4 , V_39 , V_110 , V_37 ) ;
if ( V_37 >= 0 )
goto V_115;
}
}
F_86 ( & V_79 , V_109 ) ;
if ( V_102 ) {
V_106 = L_3 ;
goto V_117;
}
if ( F_87 ( & V_58 [ V_17 - 1 ] ) ) {
V_4 = F_88 () ;
if ( ! V_4 ) {
V_106 = L_4 ;
goto V_117;
}
F_84 ( & V_79 , V_109 ) ;
F_34 ( V_4 , - 1 ) ;
} else {
F_84 ( & V_79 , V_109 ) ;
}
goto V_116;
V_115:
F_89 ( V_4 , V_13 ) ;
F_86 ( & V_79 , V_109 ) ;
if ( ! V_102 ) {
int V_59 , V_60 , V_31 , V_32 ;
V_59 = F_39 ( V_37 ) ;
V_60 = F_38 ( V_37 + V_13 ) ;
F_48 (chunk->populated, rs, re,
page_start, page_end) {
F_90 ( V_4 -> V_91 ) ;
V_108 = F_91 ( V_4 , V_31 , V_32 ) ;
F_84 ( & V_79 , V_109 ) ;
if ( V_108 ) {
F_63 ( V_4 , V_37 ) ;
V_106 = L_5 ;
goto V_114;
}
F_74 ( V_4 , V_31 , V_32 , true ) ;
F_86 ( & V_79 , V_109 ) ;
}
F_92 ( & V_113 ) ;
}
if ( V_65 < V_118 )
F_1 () ;
F_93 (cpu)
memset ( ( void * ) F_13 ( V_4 , V_24 , 0 ) + V_37 , 0 , V_13 ) ;
V_53 = F_94 ( V_4 -> V_8 + V_37 ) ;
F_95 ( V_53 , V_13 , V_101 ) ;
F_96 ( V_100 , V_102 , V_13 , V_50 ,
V_4 -> V_8 , V_37 , V_53 ) ;
return V_53 ;
V_114:
F_86 ( & V_79 , V_109 ) ;
V_117:
F_97 ( V_100 , V_102 , V_13 , V_50 ) ;
if ( ! V_102 && V_103 && V_105 ) {
F_98 ( L_6 ,
V_13 , V_50 , V_102 , V_106 ) ;
F_99 () ;
if ( ! -- V_105 )
F_100 ( L_7 ) ;
}
if ( V_102 ) {
V_119 = true ;
F_1 () ;
} else {
F_92 ( & V_113 ) ;
}
return NULL ;
}
void T_4 * F_101 ( T_2 V_13 , T_2 V_50 , T_5 V_101 )
{
return F_79 ( V_13 , V_50 , false , V_101 ) ;
}
void T_4 * F_102 ( T_2 V_13 , T_2 V_50 )
{
return F_79 ( V_13 , V_50 , false , V_52 ) ;
}
void T_4 * F_103 ( T_2 V_13 , T_2 V_50 )
{
return F_79 ( V_13 , V_50 , true , V_52 ) ;
}
static void F_104 ( struct V_120 * V_121 )
{
F_105 ( V_122 ) ;
struct V_123 * V_124 = & V_58 [ V_17 - 1 ] ;
struct V_3 * V_4 , * V_125 ;
int V_107 , V_126 , V_108 ;
F_83 ( & V_113 ) ;
F_106 ( & V_79 ) ;
F_107 (chunk, next, free_head, list) {
F_90 ( V_4 -> V_91 ) ;
if ( V_4 == F_108 ( V_124 , struct V_3 , V_57 ) )
continue;
F_35 ( & V_4 -> V_57 , & V_122 ) ;
}
F_109 ( & V_79 ) ;
F_107 (chunk, next, &to_free, list) {
int V_31 , V_32 ;
F_110 (chunk->populated, rs, re, 0 ,
chunk->nr_pages) {
F_111 ( V_4 , V_31 , V_32 ) ;
F_106 ( & V_79 ) ;
F_75 ( V_4 , V_31 , V_32 ) ;
F_109 ( & V_79 ) ;
}
F_112 ( V_4 ) ;
}
V_127:
if ( V_119 ) {
V_126 = V_128 ;
V_119 = false ;
} else {
V_126 = F_113 ( V_128 -
V_65 ,
0 , V_128 ) ;
}
for ( V_107 = F_7 ( V_11 ) ; V_107 < V_17 ; V_107 ++ ) {
int V_129 = 0 , V_31 , V_32 ;
if ( ! V_126 )
break;
F_106 ( & V_79 ) ;
F_85 (chunk, &pcpu_slot[slot], list) {
V_129 = V_4 -> V_10 - V_4 -> V_92 ;
if ( V_129 )
break;
}
F_109 ( & V_79 ) ;
if ( ! V_129 )
continue;
F_48 (chunk->populated, rs, re, 0 ,
chunk->nr_pages) {
int V_98 = F_46 ( V_32 - V_31 , V_126 ) ;
V_108 = F_91 ( V_4 , V_31 , V_31 + V_98 ) ;
if ( ! V_108 ) {
V_126 -= V_98 ;
F_106 ( & V_79 ) ;
F_74 ( V_4 , V_31 , V_31 + V_98 , false ) ;
F_109 ( & V_79 ) ;
} else {
V_126 = 0 ;
}
if ( ! V_126 )
break;
}
}
if ( V_126 ) {
V_4 = F_88 () ;
if ( V_4 ) {
F_106 ( & V_79 ) ;
F_34 ( V_4 , - 1 ) ;
F_109 ( & V_79 ) ;
goto V_127;
}
}
F_92 ( & V_113 ) ;
}
void F_114 ( void T_4 * V_53 )
{
void * V_5 ;
struct V_3 * V_4 ;
unsigned long V_109 ;
int V_37 ;
if ( ! V_53 )
return;
F_115 ( V_53 ) ;
V_5 = F_116 ( V_53 ) ;
F_84 ( & V_79 , V_109 ) ;
V_4 = F_76 ( V_5 ) ;
V_37 = V_5 - V_4 -> V_8 ;
F_63 ( V_4 , V_37 ) ;
if ( V_4 -> V_18 == V_16 ) {
struct V_3 * V_130 ;
F_85 (pos, &pcpu_slot[pcpu_nr_slots - 1], list)
if ( V_130 != V_4 ) {
F_1 () ;
break;
}
}
F_117 ( V_4 -> V_8 , V_37 , V_53 ) ;
F_86 ( & V_79 , V_109 ) ;
}
bool F_118 ( unsigned long V_5 , unsigned long * V_131 )
{
#ifdef F_119
const T_2 V_132 = V_133 - V_134 ;
void T_4 * V_135 = F_94 ( V_136 ) ;
unsigned int V_24 ;
F_93 (cpu) {
void * V_66 = F_120 ( V_135 , V_24 ) ;
void * V_137 = ( void * ) V_5 ;
if ( V_137 >= V_66 && V_137 < V_66 + V_132 ) {
if ( V_131 ) {
* V_131 = ( unsigned long ) ( V_137 - V_66 ) ;
* V_131 += ( unsigned long )
F_120 ( V_135 , F_121 () ) ;
}
return true ;
}
}
#endif
return false ;
}
bool F_122 ( unsigned long V_5 )
{
return F_118 ( V_5 , NULL ) ;
}
T_6 F_123 ( void * V_5 )
{
void T_4 * V_135 = F_94 ( V_136 ) ;
bool V_138 = false ;
unsigned long V_139 , V_140 ;
unsigned int V_24 ;
V_139 = ( unsigned long ) V_136 +
F_12 ( V_141 , 0 ) ;
V_140 = ( unsigned long ) V_136 +
F_12 ( V_142 , V_27 ) ;
if ( ( unsigned long ) V_5 >= V_139 &&
( unsigned long ) V_5 < V_140 ) {
F_93 (cpu) {
void * V_66 = F_120 ( V_135 , V_24 ) ;
if ( V_5 >= V_66 && V_5 < V_66 + V_16 ) {
V_138 = true ;
break;
}
}
}
if ( V_138 ) {
if ( ! F_124 ( V_5 ) )
return F_125 ( V_5 ) ;
else
return F_126 ( F_127 ( V_5 ) ) +
F_128 ( V_5 ) ;
} else
return F_126 ( F_78 ( V_5 ) ) +
F_128 ( V_5 ) ;
}
struct V_143 * T_3 F_129 ( int V_144 ,
int V_145 )
{
struct V_143 * V_146 ;
T_2 V_147 , V_148 ;
void * V_53 ;
int V_149 ;
V_147 = F_25 ( sizeof( * V_146 ) + V_144 * sizeof( V_146 -> V_150 [ 0 ] ) ,
F_130 ( V_146 -> V_150 [ 0 ] . V_151 [ 0 ] ) ) ;
V_148 = V_147 + V_145 * sizeof( V_146 -> V_150 [ 0 ] . V_151 [ 0 ] ) ;
V_53 = F_131 ( F_132 ( V_148 ) , 0 ) ;
if ( ! V_53 )
return NULL ;
V_146 = V_53 ;
V_53 += V_147 ;
V_146 -> V_150 [ 0 ] . V_151 = V_53 ;
for ( V_149 = 0 ; V_149 < V_145 ; V_149 ++ )
V_146 -> V_150 [ 0 ] . V_151 [ V_149 ] = V_152 ;
V_146 -> V_144 = V_144 ;
V_146 -> V_153 = F_132 ( V_148 ) ;
return V_146 ;
}
void T_3 F_133 ( struct V_143 * V_146 )
{
F_134 ( F_125 ( V_146 ) , V_146 -> V_153 ) ;
}
static void F_135 ( const char * V_154 ,
const struct V_143 * V_146 )
{
int V_155 = 1 , V_156 = 1 , V_157 ;
char V_158 [] = L_8 ;
int V_159 = 0 , V_160 = 0 ;
int V_161 , V_162 ;
int V_163 , V_164 ;
V_162 = V_146 -> V_144 ;
while ( V_162 /= 10 )
V_155 ++ ;
V_162 = F_136 () ;
while ( V_162 /= 10 )
V_156 ++ ;
V_158 [ F_50 ( int , V_156 , sizeof( V_158 ) - 1 ) ] = '\0' ;
V_163 = V_146 -> V_165 / V_146 -> V_166 ;
V_157 = V_163 * ( V_156 + 1 ) + V_155 + 3 ;
V_164 = F_137 ( F_6 ( 60 / V_157 , 1 ) ) ;
F_138 ( L_9 ,
V_154 , V_146 -> V_132 , V_146 -> V_167 , V_146 -> V_168 ,
V_146 -> V_166 , V_146 -> V_165 / V_146 -> V_169 , V_146 -> V_169 ) ;
for ( V_161 = 0 ; V_161 < V_146 -> V_144 ; V_161 ++ ) {
const struct V_170 * V_171 = & V_146 -> V_150 [ V_161 ] ;
int V_149 = 0 , V_172 = 0 ;
F_139 ( V_171 -> V_145 % V_163 ) ;
for ( V_160 += V_171 -> V_145 / V_163 ;
V_159 < V_160 ; V_159 ++ ) {
if ( ! ( V_159 % V_164 ) ) {
F_140 ( L_10 ) ;
F_138 ( L_11 , V_154 ) ;
}
F_140 ( L_12 , V_155 , V_161 ) ;
for ( V_172 += V_163 ; V_149 < V_172 ; V_149 ++ )
if ( V_171 -> V_151 [ V_149 ] != V_152 )
F_140 ( L_13 ,
V_156 , V_171 -> V_151 [ V_149 ] ) ;
else
F_140 ( L_14 , V_158 ) ;
}
}
F_140 ( L_10 ) ;
}
int T_3 F_141 ( const struct V_143 * V_146 ,
void * V_8 )
{
T_2 V_173 = V_146 -> V_132 + V_146 -> V_167 + V_146 -> V_168 ;
T_2 V_132 , V_168 ;
struct V_3 * V_4 ;
unsigned long * V_174 ;
T_2 * V_175 ;
unsigned long * V_176 ;
unsigned int V_24 ;
int * V_177 ;
int V_161 , V_149 , V_40 ;
int V_83 ;
unsigned long V_82 ;
#define F_142 ( T_7 ) do { \
if (unlikely(cond)) { \
pr_emerg("failed to initialize, %s\n", #cond); \
pr_emerg("cpu_possible_mask=%*pb\n", \
cpumask_pr_args(cpu_possible_mask)); \
pcpu_dump_alloc_info(KERN_EMERG, ai); \
BUG(); \
} \
} while (0)
F_142 ( V_146 -> V_144 <= 0 ) ;
#ifdef F_119
F_142 ( ! V_146 -> V_132 ) ;
F_142 ( F_128 ( V_134 ) ) ;
#endif
F_142 ( ! V_8 ) ;
F_142 ( F_128 ( V_8 ) ) ;
F_142 ( V_146 -> V_166 < V_173 ) ;
F_142 ( F_128 ( V_146 -> V_166 ) ) ;
F_142 ( V_146 -> V_166 < V_112 ) ;
F_142 ( ! F_143 ( V_146 -> V_166 , V_90 ) ) ;
F_142 ( V_146 -> V_168 < V_178 ) ;
F_142 ( ! V_146 -> V_168 ) ;
F_142 ( ! F_143 ( V_146 -> V_167 , V_19 ) ) ;
F_142 ( ! ( F_143 ( V_90 , V_11 ) ||
F_143 ( V_11 , V_90 ) ) ) ;
F_142 ( F_144 ( V_146 ) < 0 ) ;
V_174 = F_68 ( V_146 -> V_144 *
sizeof( V_174 [ 0 ] ) , 0 ) ;
V_175 = F_68 ( V_146 -> V_144 *
sizeof( V_175 [ 0 ] ) , 0 ) ;
V_177 = F_68 ( V_179 * sizeof( V_177 [ 0 ] ) , 0 ) ;
V_176 = F_68 ( V_179 * sizeof( V_176 [ 0 ] ) , 0 ) ;
for ( V_24 = 0 ; V_24 < V_179 ; V_24 ++ )
V_177 [ V_24 ] = V_180 ;
V_141 = V_152 ;
V_142 = V_152 ;
for ( V_161 = 0 , V_149 = 0 ; V_161 < V_146 -> V_144 ; V_161 ++ , V_149 += V_40 ) {
const struct V_170 * V_171 = & V_146 -> V_150 [ V_161 ] ;
V_174 [ V_161 ] = V_171 -> V_181 ;
V_175 [ V_161 ] = V_171 -> V_145 * V_146 -> V_166 ;
for ( V_40 = 0 ; V_40 < V_171 -> V_145 ; V_40 ++ ) {
V_24 = V_171 -> V_151 [ V_40 ] ;
if ( V_24 == V_152 )
continue;
F_142 ( V_24 >= V_179 ) ;
F_142 ( ! F_145 ( V_24 ) ) ;
F_142 ( V_177 [ V_24 ] != V_180 ) ;
V_177 [ V_24 ] = V_149 + V_40 ;
V_176 [ V_24 ] = V_171 -> V_181 + V_40 * V_146 -> V_166 ;
if ( V_141 == V_152 ||
V_176 [ V_24 ] < V_176 [ V_141 ] )
V_141 = V_24 ;
if ( V_142 == V_152 ||
V_176 [ V_24 ] > V_176 [ V_142 ] )
V_142 = V_24 ;
}
}
V_182 = V_149 ;
F_93 (cpu)
F_142 ( V_177 [ V_24 ] == V_180 ) ;
#undef F_142
F_135 ( V_183 , V_146 ) ;
V_184 = V_146 -> V_144 ;
V_185 = V_174 ;
V_186 = V_175 ;
V_26 = V_177 ;
V_28 = V_176 ;
V_27 = V_146 -> V_166 >> V_29 ;
V_16 = V_27 << V_29 ;
V_187 = V_146 -> V_169 ;
V_93 = sizeof( struct V_3 ) +
F_69 ( V_27 ) * sizeof( unsigned long ) ;
F_146 ( V_146 ) ;
V_17 = F_4 ( V_16 ) + 2 ;
V_58 = F_68 (
V_17 * sizeof( V_58 [ 0 ] ) , 0 ) ;
for ( V_40 = 0 ; V_40 < V_17 ; V_40 ++ )
F_70 ( & V_58 [ V_40 ] ) ;
V_132 = F_25 ( V_146 -> V_132 , V_19 ) ;
V_168 = V_146 -> V_168 - ( V_132 - V_146 -> V_132 ) ;
V_82 = ( unsigned long ) V_8 + V_132 ;
V_83 = V_146 -> V_167 ? : V_168 ;
V_4 = F_66 ( V_82 , V_83 ) ;
if ( V_146 -> V_167 ) {
V_56 = V_4 ;
V_82 = ( unsigned long ) V_8 + V_132 +
V_146 -> V_167 ;
V_83 = V_168 ;
V_4 = F_66 ( V_82 , V_83 ) ;
}
V_99 = V_4 ;
V_65 = V_99 -> V_63 ;
F_34 ( V_99 , - 1 ) ;
F_147 () ;
F_148 ( V_8 ) ;
V_136 = V_8 ;
return 0 ;
}
static int T_3 F_149 ( char * V_188 )
{
if ( ! V_188 )
return - V_189 ;
if ( 0 )
;
#ifdef F_150
else if ( ! strcmp ( V_188 , L_15 ) )
V_190 = V_191 ;
#endif
#ifdef F_151
else if ( ! strcmp ( V_188 , L_16 ) )
V_190 = V_192 ;
#endif
else
F_98 ( L_17 , V_188 ) ;
return 0 ;
}
static struct V_143 * T_3 F_152 (
T_2 V_167 , T_2 V_168 ,
T_2 V_169 ,
T_8 V_193 )
{
static int V_194 [ V_152 ] V_195 ;
static int V_196 [ V_152 ] V_195 ;
const T_2 V_132 = V_133 - V_134 ;
int V_144 = 1 , V_145 = 0 ;
T_2 V_173 , V_197 , V_165 ;
int V_163 , V_198 , V_199 ( V_200 ) ;
int V_201 , V_161 , V_149 ;
unsigned int V_24 , V_202 ;
struct V_143 * V_146 ;
unsigned int * V_151 ;
memset ( V_194 , 0 , sizeof( V_194 ) ) ;
memset ( V_196 , 0 , sizeof( V_196 ) ) ;
V_173 = F_132 ( V_132 + V_167 +
F_153 ( T_2 , V_168 , V_178 ) ) ;
V_168 = V_173 - V_132 - V_167 ;
V_197 = F_153 ( T_2 , V_173 , V_112 ) ;
V_165 = F_154 ( V_197 , V_169 ) ;
V_163 = V_165 / V_197 ;
while ( V_165 % V_163 || ( F_128 ( V_165 / V_163 ) ) )
V_163 -- ;
V_198 = V_163 ;
F_93 (cpu) {
V_161 = 0 ;
V_203:
F_93 (tcpu) {
if ( V_24 == V_202 )
break;
if ( V_194 [ V_202 ] == V_161 && V_193 &&
( V_193 ( V_24 , V_202 ) > V_204 ||
V_193 ( V_202 , V_24 ) > V_204 ) ) {
V_161 ++ ;
V_144 = F_6 ( V_144 , V_161 + 1 ) ;
goto V_203;
}
}
V_194 [ V_24 ] = V_161 ;
V_196 [ V_161 ] ++ ;
}
V_201 = V_205 ;
for ( V_163 = V_198 ; V_163 ; V_163 -- ) {
int V_206 = 0 , V_207 = 0 ;
if ( V_165 % V_163 || ( F_128 ( V_165 / V_163 ) ) )
continue;
for ( V_161 = 0 ; V_161 < V_144 ; V_161 ++ ) {
int V_208 = F_155 ( V_196 [ V_161 ] , V_163 ) ;
V_206 += V_208 ;
V_207 += V_208 * V_163 - V_196 [ V_161 ] ;
}
if ( V_207 > F_136 () / 3 )
continue;
if ( V_206 > V_201 )
break;
V_201 = V_206 ;
V_200 = V_163 ;
}
V_163 = V_200 ;
for ( V_161 = 0 ; V_161 < V_144 ; V_161 ++ )
V_145 += F_154 ( V_196 [ V_161 ] , V_163 ) ;
V_146 = F_129 ( V_144 , V_145 ) ;
if ( ! V_146 )
return F_156 ( - V_209 ) ;
V_151 = V_146 -> V_150 [ 0 ] . V_151 ;
for ( V_161 = 0 ; V_161 < V_144 ; V_161 ++ ) {
V_146 -> V_150 [ V_161 ] . V_151 = V_151 ;
V_151 += F_154 ( V_196 [ V_161 ] , V_163 ) ;
}
V_146 -> V_132 = V_132 ;
V_146 -> V_167 = V_167 ;
V_146 -> V_168 = V_168 ;
V_146 -> V_166 = V_165 / V_163 ;
V_146 -> V_169 = V_169 ;
V_146 -> V_165 = V_165 ;
for ( V_161 = 0 , V_149 = 0 ; V_196 [ V_161 ] ; V_161 ++ ) {
struct V_170 * V_171 = & V_146 -> V_150 [ V_161 ] ;
V_171 -> V_181 = V_149 * V_146 -> V_166 ;
F_93 (cpu)
if ( V_194 [ V_24 ] == V_161 )
V_171 -> V_151 [ V_171 -> V_145 ++ ] = V_24 ;
V_171 -> V_145 = F_154 ( V_171 -> V_145 , V_163 ) ;
V_149 += V_171 -> V_145 ;
}
F_139 ( V_149 != V_145 ) ;
return V_146 ;
}
int T_3 F_157 ( T_2 V_167 , T_2 V_168 ,
T_2 V_169 ,
T_8 V_193 ,
T_9 V_210 ,
T_10 V_211 )
{
void * V_135 = ( void * ) V_212 ;
void * * V_213 = NULL ;
struct V_143 * V_146 ;
T_2 V_173 , V_214 ;
unsigned long V_215 ;
int V_161 , V_40 , V_216 , V_217 ;
V_146 = F_152 ( V_167 , V_168 , V_169 ,
V_193 ) ;
if ( F_158 ( V_146 ) )
return F_159 ( V_146 ) ;
V_173 = V_146 -> V_132 + V_146 -> V_167 + V_146 -> V_168 ;
V_214 = F_132 ( V_146 -> V_144 * sizeof( void * ) ) ;
V_213 = F_131 ( V_214 , 0 ) ;
if ( ! V_213 ) {
V_217 = - V_209 ;
goto V_218;
}
V_216 = 0 ;
for ( V_161 = 0 ; V_161 < V_146 -> V_144 ; V_161 ++ ) {
struct V_170 * V_171 = & V_146 -> V_150 [ V_161 ] ;
unsigned int V_24 = V_152 ;
void * V_53 ;
for ( V_40 = 0 ; V_40 < V_171 -> V_145 && V_24 == V_152 ; V_40 ++ )
V_24 = V_171 -> V_151 [ V_40 ] ;
F_139 ( V_24 == V_152 ) ;
V_53 = V_210 ( V_24 , V_171 -> V_145 * V_146 -> V_166 , V_169 ) ;
if ( ! V_53 ) {
V_217 = - V_209 ;
goto V_219;
}
F_160 ( V_53 ) ;
V_213 [ V_161 ] = V_53 ;
V_135 = F_46 ( V_53 , V_135 ) ;
if ( V_53 > V_213 [ V_216 ] )
V_216 = V_161 ;
}
V_215 = V_213 [ V_216 ] - V_135 ;
V_215 += V_146 -> V_166 * V_146 -> V_150 [ V_216 ] . V_145 ;
if ( V_215 > V_220 * 3 / 4 ) {
F_98 ( L_18 ,
V_215 , V_220 ) ;
#ifdef F_151
V_217 = - V_189 ;
goto V_219;
#endif
}
for ( V_161 = 0 ; V_161 < V_146 -> V_144 ; V_161 ++ ) {
struct V_170 * V_171 = & V_146 -> V_150 [ V_161 ] ;
void * V_53 = V_213 [ V_161 ] ;
for ( V_40 = 0 ; V_40 < V_171 -> V_145 ; V_40 ++ , V_53 += V_146 -> V_166 ) {
if ( V_171 -> V_151 [ V_40 ] == V_152 ) {
V_211 ( V_53 , V_146 -> V_166 ) ;
continue;
}
memcpy ( V_53 , V_221 , V_146 -> V_132 ) ;
V_211 ( V_53 + V_173 , V_146 -> V_166 - V_173 ) ;
}
}
for ( V_161 = 0 ; V_161 < V_146 -> V_144 ; V_161 ++ ) {
V_146 -> V_150 [ V_161 ] . V_181 = V_213 [ V_161 ] - V_135 ;
}
F_100 ( L_19 ,
F_39 ( V_173 ) , V_135 , V_146 -> V_132 , V_146 -> V_167 ,
V_146 -> V_168 , V_146 -> V_166 ) ;
V_217 = F_141 ( V_146 , V_135 ) ;
goto V_218;
V_219:
for ( V_161 = 0 ; V_161 < V_146 -> V_144 ; V_161 ++ )
if ( V_213 [ V_161 ] )
V_211 ( V_213 [ V_161 ] ,
V_146 -> V_150 [ V_161 ] . V_145 * V_146 -> V_166 ) ;
V_218:
F_133 ( V_146 ) ;
if ( V_213 )
F_134 ( F_125 ( V_213 ) , V_214 ) ;
return V_217 ;
}
int T_3 F_161 ( T_2 V_167 ,
T_9 V_210 ,
T_10 V_211 ,
T_11 V_222 )
{
static struct V_223 V_224 ;
struct V_143 * V_146 ;
char V_225 [ 16 ] ;
int V_226 ;
T_2 V_227 ;
struct V_21 * * V_228 ;
int V_149 , V_40 , V_229 , V_217 ;
int V_163 ;
int V_230 ;
snprintf ( V_225 , sizeof( V_225 ) , L_20 , V_11 >> 10 ) ;
V_146 = F_152 ( V_167 , 0 , V_11 , NULL ) ;
if ( F_158 ( V_146 ) )
return F_159 ( V_146 ) ;
F_139 ( V_146 -> V_144 != 1 ) ;
V_163 = V_146 -> V_165 / V_146 -> V_166 ;
V_230 = F_154 ( F_136 () , V_163 ) ;
if ( F_80 ( F_90 ( V_146 -> V_150 [ 0 ] . V_145 != V_230 ) ) ) {
F_133 ( V_146 ) ;
return - V_189 ;
}
V_226 = V_146 -> V_166 >> V_29 ;
V_227 = F_132 ( V_226 * F_136 () *
sizeof( V_228 [ 0 ] ) ) ;
V_228 = F_68 ( V_227 , 0 ) ;
V_229 = 0 ;
for ( V_149 = 0 ; V_149 < F_136 () ; V_149 ++ ) {
unsigned int V_24 = V_146 -> V_150 [ 0 ] . V_151 [ V_149 ] ;
for ( V_40 = 0 ; V_40 < V_226 ; V_40 ++ ) {
void * V_53 ;
V_53 = V_210 ( V_24 , V_11 , V_11 ) ;
if ( ! V_53 ) {
F_98 ( L_21 ,
V_225 , V_24 ) ;
goto V_231;
}
F_160 ( V_53 ) ;
V_228 [ V_229 ++ ] = F_162 ( V_53 ) ;
}
}
V_224 . V_109 = V_232 ;
V_224 . V_13 = F_136 () * V_146 -> V_166 ;
F_163 ( & V_224 , V_11 ) ;
for ( V_149 = 0 ; V_149 < F_136 () ; V_149 ++ ) {
unsigned long V_233 =
( unsigned long ) V_224 . V_5 + V_149 * V_146 -> V_166 ;
for ( V_40 = 0 ; V_40 < V_226 ; V_40 ++ )
V_222 ( V_233 + ( V_40 << V_29 ) ) ;
V_217 = F_164 ( V_233 , & V_228 [ V_149 * V_226 ] ,
V_226 ) ;
if ( V_217 < 0 )
F_165 ( L_22 , V_217 ) ;
memcpy ( ( void * ) V_233 , V_221 , V_146 -> V_132 ) ;
}
F_100 ( L_23 ,
V_226 , V_225 , V_224 . V_5 , V_146 -> V_132 ,
V_146 -> V_167 , V_146 -> V_168 ) ;
V_217 = F_141 ( V_146 , V_224 . V_5 ) ;
goto V_234;
V_231:
while ( -- V_229 >= 0 )
V_211 ( F_166 ( V_228 [ V_229 ] ) , V_11 ) ;
V_217 = - V_209 ;
V_234:
F_134 ( F_125 ( V_228 ) , V_227 ) ;
F_133 ( V_146 ) ;
return V_217 ;
}
static void * T_3 F_167 ( unsigned int V_24 , T_2 V_13 ,
T_2 V_50 )
{
return F_168 (
V_13 , V_50 , F_125 ( V_235 ) ) ;
}
static void T_3 F_169 ( void * V_53 , T_2 V_13 )
{
F_134 ( F_125 ( V_53 ) , V_13 ) ;
}
void T_3 F_170 ( void )
{
unsigned long V_236 ;
unsigned int V_24 ;
int V_217 ;
V_217 = F_157 ( V_237 ,
V_238 , V_11 , NULL ,
F_167 , F_169 ) ;
if ( V_217 < 0 )
F_165 ( L_24 ) ;
V_236 = ( unsigned long ) V_136 - ( unsigned long ) V_134 ;
F_93 (cpu)
V_239 [ V_24 ] = V_236 + V_28 [ V_24 ] ;
}
void T_3 F_170 ( void )
{
const T_2 V_166 =
F_171 ( F_153 ( T_2 , V_112 ,
V_238 ) ) ;
struct V_143 * V_146 ;
void * V_240 ;
V_146 = F_129 ( 1 , 1 ) ;
V_240 = F_168 ( V_166 ,
V_11 ,
F_125 ( V_235 ) ) ;
if ( ! V_146 || ! V_240 )
F_165 ( L_25 ) ;
F_160 ( V_240 ) ;
V_146 -> V_168 = V_166 ;
V_146 -> V_166 = V_166 ;
V_146 -> V_169 = V_166 ;
V_146 -> V_165 = V_166 ;
V_146 -> V_150 [ 0 ] . V_145 = 1 ;
V_146 -> V_150 [ 0 ] . V_151 [ 0 ] = 0 ;
if ( F_141 ( V_146 , V_240 ) < 0 )
F_165 ( L_24 ) ;
}
static int T_3 F_172 ( void )
{
V_1 = true ;
return 0 ;
}
