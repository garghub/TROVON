static T_1 * F_1 ( struct V_1 * V_2 , T_2 V_3 , unsigned long V_4 )
{
unsigned int V_5 = F_2 ( V_4 ) ;
return & V_2 -> V_6 -> V_7 [ V_3 ] . V_8 [ V_5 ] ;
}
static T_3 * F_3 ( struct V_1 * V_2 , T_1 V_9 , unsigned long V_4 )
{
unsigned int V_5 = F_4 ( V_4 ) ;
T_3 * V_10 ;
F_5 ( ! ( F_6 ( V_9 ) & V_11 ) ) ;
V_10 = F_7 ( F_8 ( V_9 ) << V_12 ) ;
return & V_10 [ V_5 ] ;
}
static T_4 * F_9 ( struct V_1 * V_2 , T_1 V_9 , unsigned long V_4 )
{
#ifdef F_10
T_3 * V_13 = F_3 ( V_2 , V_9 , V_4 ) ;
T_4 * V_10 = F_7 ( F_11 ( * V_13 ) << V_12 ) ;
F_5 ( ! ( F_12 ( * V_13 ) & V_11 ) ) ;
#else
T_4 * V_10 = F_7 ( F_8 ( V_9 ) << V_12 ) ;
F_5 ( ! ( F_6 ( V_9 ) & V_11 ) ) ;
#endif
return & V_10 [ F_13 ( V_4 ) ] ;
}
static unsigned long F_14 ( struct V_1 * V_2 , unsigned long V_4 )
{
unsigned int V_5 = V_4 >> ( V_14 ) ;
return V_2 -> V_6 -> V_7 [ V_2 -> V_15 ] . V_16 + V_5 * sizeof( T_1 ) ;
}
static unsigned long F_15 ( T_1 V_17 , unsigned long V_4 )
{
unsigned long V_18 = F_8 ( V_17 ) << V_12 ;
F_5 ( ! ( F_6 ( V_17 ) & V_11 ) ) ;
return V_18 + F_4 ( V_4 ) * sizeof( T_3 ) ;
}
static unsigned long F_16 ( struct V_1 * V_2 ,
T_3 V_19 , unsigned long V_4 )
{
unsigned long V_18 = F_11 ( V_19 ) << V_12 ;
F_5 ( ! ( F_12 ( V_19 ) & V_11 ) ) ;
return V_18 + F_13 ( V_4 ) * sizeof( T_4 ) ;
}
static unsigned long F_16 ( struct V_1 * V_2 ,
T_1 V_17 , unsigned long V_4 )
{
unsigned long V_18 = F_8 ( V_17 ) << V_12 ;
F_5 ( ! ( F_6 ( V_17 ) & V_11 ) ) ;
return V_18 + F_13 ( V_4 ) * sizeof( T_4 ) ;
}
static unsigned long F_17 ( unsigned long V_20 , int V_21 )
{
struct V_10 * V_10 ;
if ( F_18 ( V_20 << V_12 , 1 , V_21 , & V_10 ) == 1 )
return F_19 ( V_10 ) ;
return - 1UL ;
}
static T_4 F_20 ( struct V_1 * V_2 , T_4 V_22 , int V_21 )
{
unsigned long V_23 , V_24 , V_25 ;
V_25 = ( F_21 ( V_22 ) & ~ V_26 ) ;
V_24 = ( unsigned long ) V_2 -> V_6 -> V_27 / V_28 ;
V_23 = F_17 ( V_24 + F_22 ( V_22 ) , V_21 ) ;
if ( V_23 == - 1UL ) {
F_23 ( V_2 , L_1 , F_22 ( V_22 ) ) ;
V_25 = 0 ;
}
return F_24 ( V_23 , F_25 ( V_25 ) ) ;
}
static void F_26 ( T_4 V_29 )
{
if ( F_21 ( V_29 ) & V_11 )
F_27 ( F_28 ( V_29 ) ) ;
}
static bool F_29 ( struct V_1 * V_2 , T_4 V_22 )
{
if ( ( F_21 ( V_22 ) & V_30 ) ||
F_22 ( V_22 ) >= V_2 -> V_6 -> V_31 ) {
F_23 ( V_2 , L_2 ) ;
return false ;
}
return true ;
}
static bool F_30 ( struct V_1 * V_2 , T_1 V_17 )
{
if ( ( F_6 ( V_17 ) & ~ V_32 ) ||
( F_8 ( V_17 ) >= V_2 -> V_6 -> V_31 ) ) {
F_23 ( V_2 , L_3 ) ;
return false ;
}
return true ;
}
static bool F_31 ( struct V_1 * V_2 , T_3 V_19 )
{
if ( ( F_12 ( V_19 ) & ~ V_33 ) ||
( F_11 ( V_19 ) >= V_2 -> V_6 -> V_31 ) ) {
F_23 ( V_2 , L_4 ) ;
return false ;
}
return true ;
}
static T_4 * F_32 ( struct V_1 * V_2 , unsigned long V_4 , bool V_34 ,
int F_6 , int F_12 )
{
T_1 * V_9 ;
#ifdef F_10
T_3 * V_35 ;
#endif
V_9 = F_1 ( V_2 , V_2 -> V_15 , V_4 ) ;
if ( ! ( F_6 ( * V_9 ) & V_11 ) ) {
unsigned long V_36 ;
if ( ! V_34 )
return NULL ;
V_36 = F_33 ( V_37 ) ;
if ( ! V_36 ) {
F_23 ( V_2 , L_5 ) ;
return NULL ;
}
F_34 ( V_9 , F_35 ( F_36 ( V_36 ) | F_6 ) ) ;
}
#ifdef F_10
V_35 = F_3 ( V_2 , * V_9 , V_4 ) ;
if ( ! ( F_12 ( * V_35 ) & V_11 ) ) {
unsigned long V_36 ;
if ( ! V_34 )
return NULL ;
V_36 = F_33 ( V_37 ) ;
if ( ! V_36 ) {
F_23 ( V_2 , L_6 ) ;
return NULL ;
}
F_37 ( V_35 , F_38 ( F_36 ( V_36 ) | F_12 ) ) ;
}
#endif
return F_9 ( V_2 , * V_9 , V_4 ) ;
}
bool F_39 ( struct V_1 * V_2 , unsigned long V_4 , int V_38 )
{
unsigned long V_39 ;
T_4 V_22 ;
T_4 * V_40 ;
T_3 V_19 ;
T_1 V_17 ;
if ( V_4 >= V_41 )
return false ;
if ( F_40 ( V_2 -> V_42 ) ) {
V_17 = F_35 ( V_32 ) ;
} else {
V_17 = F_41 ( V_2 , F_14 ( V_2 , V_4 ) , T_1 ) ;
if ( ! ( F_6 ( V_17 ) & V_11 ) )
return false ;
if ( ! F_30 ( V_2 , V_17 ) )
return false ;
}
V_19 = F_38 ( V_33 ) ;
#ifdef F_10
if ( F_42 ( ! V_2 -> V_42 ) ) {
V_19 = F_41 ( V_2 , F_15 ( V_17 , V_4 ) , T_3 ) ;
if ( ! ( F_12 ( V_19 ) & V_11 ) )
return false ;
if ( ! F_31 ( V_2 , V_19 ) )
return false ;
}
V_39 = F_16 ( V_2 , V_19 , V_4 ) ;
#else
V_39 = F_16 ( V_2 , V_17 , V_4 ) ;
#endif
if ( F_40 ( V_2 -> V_42 ) ) {
V_22 = F_43 ( ( V_4 & V_43 ) | V_44 | V_11 ) ;
} else {
V_22 = F_41 ( V_2 , V_39 , T_4 ) ;
}
if ( ! ( F_21 ( V_22 ) & V_11 ) )
return false ;
if ( ( V_38 & 2 ) && ! ( F_21 ( V_22 ) & V_44 ) )
return false ;
if ( ( V_38 & 4 ) && ! ( F_21 ( V_22 ) & V_45 ) )
return false ;
if ( ! F_29 ( V_2 , V_22 ) )
return false ;
V_22 = F_44 ( V_22 ) ;
if ( V_38 & 2 )
V_22 = F_45 ( V_22 ) ;
V_40 = F_32 ( V_2 , V_4 , true , F_6 ( V_17 ) , F_12 ( V_19 ) ) ;
if ( ! V_40 )
return false ;
F_26 ( * V_40 ) ;
if ( F_46 ( V_22 ) )
* V_40 = F_20 ( V_2 , V_22 , 1 ) ;
else
F_47 ( V_40 , F_20 ( V_2 , F_48 ( V_22 ) , 0 ) ) ;
if ( F_42 ( ! V_2 -> V_42 ) )
F_49 ( V_2 , V_39 , T_4 , V_22 ) ;
return true ;
}
static bool F_50 ( struct V_1 * V_2 , unsigned long V_4 )
{
T_4 * V_40 ;
unsigned long V_25 ;
if ( V_4 >= V_41 )
return false ;
V_40 = F_32 ( V_2 , V_4 , false , 0 , 0 ) ;
if ( ! V_40 )
return false ;
V_25 = F_21 ( * V_40 ) ;
return ( V_25 & ( V_11 | V_44 ) ) == ( V_11 | V_44 ) ;
}
void F_51 ( struct V_1 * V_2 , unsigned long V_4 )
{
if ( ! F_50 ( V_2 , V_4 ) && ! F_39 ( V_2 , V_4 , 2 ) )
F_23 ( V_2 , L_7 , V_4 ) ;
}
static void F_52 ( T_3 * V_35 )
{
if ( F_12 ( * V_35 ) & V_11 ) {
unsigned int V_3 ;
T_4 * V_36 = F_7 ( F_11 ( * V_35 ) << V_12 ) ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ )
F_26 ( V_36 [ V_3 ] ) ;
F_53 ( ( long ) V_36 ) ;
F_37 ( V_35 , F_38 ( 0 ) ) ;
}
}
static void F_54 ( T_1 * V_9 )
{
if ( F_6 ( * V_9 ) & V_11 ) {
unsigned int V_3 ;
T_3 * V_47 = F_7 ( F_8 ( * V_9 ) << V_12 ) ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ )
F_52 ( & V_47 [ V_3 ] ) ;
F_53 ( ( long ) V_47 ) ;
F_34 ( V_9 , F_35 ( 0 ) ) ;
}
}
static void F_54 ( T_1 * V_9 )
{
if ( F_6 ( * V_9 ) & V_11 ) {
unsigned int V_3 ;
T_4 * V_36 = F_7 ( F_8 ( * V_9 ) << V_12 ) ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ )
F_26 ( V_36 [ V_3 ] ) ;
F_53 ( ( long ) V_36 ) ;
* V_9 = F_35 ( 0 ) ;
}
}
static void F_55 ( struct V_49 * V_6 , int V_50 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_6 -> V_51 ) ; V_3 ++ )
F_54 ( V_6 -> V_7 [ V_50 ] . V_8 + V_3 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
F_55 ( V_2 -> V_6 , V_2 -> V_15 ) ;
}
unsigned long F_57 ( struct V_1 * V_2 , unsigned long V_4 )
{
T_1 V_17 ;
T_4 V_22 ;
#ifdef F_10
T_3 V_19 ;
#endif
if ( F_40 ( V_2 -> V_42 ) )
return V_4 ;
V_17 = F_41 ( V_2 , F_14 ( V_2 , V_4 ) , T_1 ) ;
if ( ! ( F_6 ( V_17 ) & V_11 ) ) {
F_23 ( V_2 , L_8 , V_4 ) ;
return - 1UL ;
}
#ifdef F_10
V_19 = F_41 ( V_2 , F_15 ( V_17 , V_4 ) , T_3 ) ;
if ( ! ( F_12 ( V_19 ) & V_11 ) ) {
F_23 ( V_2 , L_8 , V_4 ) ;
return - 1UL ;
}
V_22 = F_41 ( V_2 , F_16 ( V_2 , V_19 , V_4 ) , T_4 ) ;
#else
V_22 = F_41 ( V_2 , F_16 ( V_2 , V_17 , V_4 ) , T_4 ) ;
#endif
if ( ! ( F_21 ( V_22 ) & V_11 ) )
F_23 ( V_2 , L_8 , V_4 ) ;
return F_22 ( V_22 ) * V_28 | ( V_4 & ~ V_43 ) ;
}
static unsigned int F_58 ( struct V_49 * V_6 , unsigned long V_52 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_59 ( V_6 -> V_7 ) ; V_3 ++ )
if ( V_6 -> V_7 [ V_3 ] . V_8 && V_6 -> V_7 [ V_3 ] . V_16 == V_52 )
break;
return V_3 ;
}
static unsigned int F_60 ( struct V_1 * V_2 ,
unsigned long V_16 ,
int * V_53 )
{
unsigned int V_54 ;
V_54 = F_61 () % F_59 ( V_2 -> V_6 -> V_7 ) ;
if ( ! V_2 -> V_6 -> V_7 [ V_54 ] . V_8 ) {
V_2 -> V_6 -> V_7 [ V_54 ] . V_8 =
( T_1 * ) F_33 ( V_37 ) ;
if ( ! V_2 -> V_6 -> V_7 [ V_54 ] . V_8 )
V_54 = V_2 -> V_15 ;
else {
* V_53 = 1 ;
}
}
V_2 -> V_6 -> V_7 [ V_54 ] . V_16 = V_16 ;
F_55 ( V_2 -> V_6 , V_54 ) ;
V_2 -> V_6 -> V_7 [ V_54 ] . V_55 = - 1 ;
return V_54 ;
}
static bool F_62 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_56 ; V_3 ++ ) {
T_4 * V_29 = F_32 ( V_2 , V_41 + V_3 * V_28 , true ,
V_32 , V_33 ) ;
if ( ! V_29 )
return false ;
if ( V_3 == 0 && ! ( F_21 ( * V_29 ) & V_11 ) ) {
F_63 ( V_57 [ 0 ] ) ;
F_47 ( V_29 ,
F_64 ( V_57 [ 0 ] , V_58 ) ) ;
}
}
V_2 -> V_6 -> V_7 [ V_2 -> V_15 ] . V_59 = true ;
return true ;
}
static void F_65 ( struct V_49 * V_6 )
{
unsigned int V_3 , V_60 ;
for ( V_3 = 0 ; V_3 < F_59 ( V_6 -> V_7 ) ; V_3 ++ ) {
if ( ! V_6 -> V_7 [ V_3 ] . V_8 )
continue;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ )
F_54 ( V_6 -> V_7 [ V_3 ] . V_8 + V_60 ) ;
V_6 -> V_7 [ V_3 ] . V_59 = false ;
V_6 -> V_7 [ V_3 ] . V_55 = - 1 ;
}
}
void F_66 ( struct V_1 * V_2 )
{
F_65 ( V_2 -> V_6 ) ;
F_67 ( V_2 ) ;
if ( ! F_62 ( V_2 ) )
F_23 ( V_2 , L_9 ) ;
}
void F_68 ( struct V_1 * V_2 , unsigned long V_52 )
{
int V_62 , V_63 = 0 ;
if ( F_40 ( V_2 -> V_42 ) ) {
F_65 ( V_2 -> V_6 ) ;
V_2 -> V_42 = false ;
V_62 = F_59 ( V_2 -> V_6 -> V_7 ) ;
} else {
V_62 = F_58 ( V_2 -> V_6 , V_52 ) ;
}
if ( V_62 == F_59 ( V_2 -> V_6 -> V_7 ) )
V_62 = F_60 ( V_2 , V_52 , & V_63 ) ;
V_2 -> V_15 = V_62 ;
if ( V_63 )
F_67 ( V_2 ) ;
if ( ! V_2 -> V_6 -> V_7 [ V_2 -> V_15 ] . V_59 ) {
if ( ! F_62 ( V_2 ) )
F_23 ( V_2 , L_9 ) ;
}
}
static void F_69 ( struct V_1 * V_2 , int V_50 ,
unsigned long V_4 , T_4 V_22 )
{
T_1 * V_9 = F_1 ( V_2 , V_50 , V_4 ) ;
#ifdef F_10
T_3 * V_35 ;
#endif
if ( F_6 ( * V_9 ) & V_11 ) {
#ifdef F_10
V_35 = F_3 ( V_2 , * V_9 , V_4 ) ;
if ( F_12 ( * V_35 ) & V_11 ) {
#endif
T_4 * V_40 = F_9 ( V_2 , * V_9 , V_4 ) ;
F_26 ( * V_40 ) ;
if ( F_21 ( V_22 ) & ( V_64 | V_65 ) ) {
if ( ! F_29 ( V_2 , V_22 ) )
return;
F_47 ( V_40 ,
F_20 ( V_2 , V_22 ,
F_21 ( V_22 ) & V_64 ) ) ;
} else {
F_47 ( V_40 , F_43 ( 0 ) ) ;
}
#ifdef F_10
}
#endif
}
}
void F_70 ( struct V_1 * V_2 ,
unsigned long V_16 , unsigned long V_4 , T_4 V_22 )
{
if ( V_4 >= V_41 ) {
F_23 ( V_2 , L_10 ) ;
return;
}
if ( V_4 >= V_2 -> V_6 -> V_51 ) {
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_59 ( V_2 -> V_6 -> V_7 ) ; V_3 ++ )
if ( V_2 -> V_6 -> V_7 [ V_3 ] . V_8 )
F_69 ( V_2 , V_3 , V_4 , V_22 ) ;
} else {
int V_8 = F_58 ( V_2 -> V_6 , V_16 ) ;
if ( V_8 != F_59 ( V_2 -> V_6 -> V_7 ) )
F_69 ( V_2 , V_8 , V_4 , V_22 ) ;
}
}
void F_71 ( struct V_49 * V_6 , unsigned long V_16 , T_2 V_50 )
{
int V_8 ;
if ( V_50 > V_61 ) {
F_23 ( & V_6 -> V_66 [ 0 ] , L_11 ,
V_50 , V_61 ) ;
return;
}
V_8 = F_58 ( V_6 , V_16 ) ;
if ( V_8 < F_59 ( V_6 -> V_7 ) ) {
F_54 ( V_6 -> V_7 [ V_8 ] . V_8 + V_50 ) ;
if ( ! F_62 ( & V_6 -> V_66 [ 0 ] ) ) {
F_23 ( & V_6 -> V_66 [ 0 ] ,
L_9 ) ;
}
V_6 -> V_7 [ V_8 ] . V_55 = - 1 ;
}
}
void F_72 ( struct V_49 * V_6 , unsigned long V_67 , T_2 V_50 )
{
F_66 ( & V_6 -> V_66 [ 0 ] ) ;
}
int F_73 ( struct V_49 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_66 [ 0 ] ;
int V_68 = 0 ;
V_2 -> V_15 = F_60 ( V_2 , 0 , & V_68 ) ;
if ( ! V_68 )
return - V_69 ;
V_2 -> V_42 = true ;
if ( ! F_62 ( V_2 ) ) {
F_65 ( V_6 ) ;
return - V_69 ;
}
return 0 ;
}
void F_74 ( struct V_1 * V_2 )
{
T_2 V_70 = ~ V_41 + 1 ;
if ( F_75 ( V_2 -> V_6 -> V_51 ,
& V_2 -> V_6 -> V_71 -> V_51 )
|| F_76 ( V_70 , & V_2 -> V_6 -> V_71 -> V_72 ) ) {
F_23 ( V_2 , L_12 , V_2 -> V_6 -> V_71 ) ;
return;
}
if ( V_2 -> V_6 -> V_51 >= V_41 )
F_23 ( V_2 , L_13 ,
V_2 -> V_6 -> V_51 ) ;
}
void F_77 ( struct V_49 * V_6 )
{
unsigned int V_3 ;
F_65 ( V_6 ) ;
for ( V_3 = 0 ; V_3 < F_59 ( V_6 -> V_7 ) ; V_3 ++ )
F_53 ( ( long ) V_6 -> V_7 [ V_3 ] . V_8 ) ;
}
static void F_78 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_24 = V_41 + V_28 + V_3 * V_28 * 2 ;
T_4 * V_29 ;
V_29 = F_32 ( V_2 , V_24 , false , 0 , 0 ) ;
F_26 ( * V_29 ) ;
F_47 ( V_29 , F_43 ( 0 ) ) ;
V_29 = F_32 ( V_2 , V_24 + V_28 , false , 0 , 0 ) ;
F_26 ( * V_29 ) ;
F_47 ( V_29 , F_43 ( 0 ) ) ;
}
void F_79 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
unsigned long V_24 ;
struct V_10 * V_75 , * V_76 ;
T_4 * V_29 ;
struct V_8 * V_8 = & V_2 -> V_6 -> V_7 [ V_2 -> V_15 ] ;
F_5 ( ! V_8 -> V_59 ) ;
if ( V_8 -> V_55 == F_80 () )
return;
if ( V_8 -> V_55 == - 1 ) {
unsigned int V_3 ;
F_81 (i)
F_78 ( V_2 , V_3 ) ;
} else {
F_78 ( V_2 , V_8 -> V_55 ) ;
}
V_24 = V_41 + V_28
+ F_80 () * sizeof( struct V_73 ) ;
V_29 = F_32 ( V_2 , V_24 , false , 0 , 0 ) ;
V_76 = F_82 ( F_36 ( V_2 -> V_76 ) >> V_12 ) ;
F_63 ( V_76 ) ;
F_47 ( V_29 , F_64 ( V_76 , F_25 ( V_77 & ~ V_26 ) ) ) ;
V_29 = F_32 ( V_2 , V_24 + V_28 , false , 0 , 0 ) ;
V_75
= V_57 [ 1 + F_80 () * 2 + 1 ] ;
F_63 ( V_75 ) ;
F_47 ( V_29 , F_64 ( V_75 ,
F_25 ( V_78 & ~ V_26 ) ) ) ;
V_8 -> V_55 = F_80 () ;
}
