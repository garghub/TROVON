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
if ( F_21 ( V_22 ) & V_30 )
return false ;
return ( F_22 ( V_22 ) >= V_2 -> V_6 -> V_31
&& F_22 ( V_22 ) < V_2 -> V_6 -> V_32 ) ;
}
static bool F_30 ( struct V_1 * V_2 , T_4 V_22 )
{
if ( ( F_21 ( V_22 ) & V_30 ) ||
F_22 ( V_22 ) >= V_2 -> V_6 -> V_31 ) {
F_23 ( V_2 , L_2 ) ;
return false ;
}
return true ;
}
static bool F_31 ( struct V_1 * V_2 , T_1 V_17 )
{
if ( ( F_6 ( V_17 ) & ~ V_33 ) ||
( F_8 ( V_17 ) >= V_2 -> V_6 -> V_31 ) ) {
F_23 ( V_2 , L_3 ) ;
return false ;
}
return true ;
}
static bool F_32 ( struct V_1 * V_2 , T_3 V_19 )
{
if ( ( F_12 ( V_19 ) & ~ V_34 ) ||
( F_11 ( V_19 ) >= V_2 -> V_6 -> V_31 ) ) {
F_23 ( V_2 , L_4 ) ;
return false ;
}
return true ;
}
static T_4 * F_33 ( struct V_1 * V_2 , unsigned long V_4 , bool V_35 ,
int F_6 , int F_12 )
{
T_1 * V_9 ;
#ifdef F_10
T_3 * V_36 ;
#endif
V_9 = F_1 ( V_2 , V_2 -> V_15 , V_4 ) ;
if ( ! ( F_6 ( * V_9 ) & V_11 ) ) {
unsigned long V_37 ;
if ( ! V_35 )
return NULL ;
V_37 = F_34 ( V_38 ) ;
if ( ! V_37 ) {
F_23 ( V_2 , L_5 ) ;
return NULL ;
}
F_35 ( V_9 , F_36 ( F_37 ( V_37 ) | F_6 ) ) ;
}
#ifdef F_10
V_36 = F_3 ( V_2 , * V_9 , V_4 ) ;
if ( ! ( F_12 ( * V_36 ) & V_11 ) ) {
unsigned long V_37 ;
if ( ! V_35 )
return NULL ;
V_37 = F_34 ( V_38 ) ;
if ( ! V_37 ) {
F_23 ( V_2 , L_6 ) ;
return NULL ;
}
F_38 ( V_36 , F_39 ( F_37 ( V_37 ) | F_12 ) ) ;
}
#endif
return F_9 ( V_2 , * V_9 , V_4 ) ;
}
bool F_40 ( struct V_1 * V_2 , unsigned long V_4 , int V_39 ,
unsigned long * V_40 )
{
unsigned long V_41 ;
T_4 V_22 ;
T_4 * V_42 ;
T_3 V_19 ;
T_1 V_17 ;
* V_40 = 0 ;
if ( V_4 >= V_43 )
return false ;
if ( F_41 ( V_2 -> V_44 ) ) {
V_17 = F_36 ( V_33 ) ;
} else {
V_17 = F_42 ( V_2 , F_14 ( V_2 , V_4 ) , T_1 ) ;
if ( ! ( F_6 ( V_17 ) & V_11 ) )
return false ;
if ( ! F_31 ( V_2 , V_17 ) )
return false ;
}
V_19 = F_39 ( V_34 ) ;
#ifdef F_10
if ( F_43 ( ! V_2 -> V_44 ) ) {
V_19 = F_42 ( V_2 , F_15 ( V_17 , V_4 ) , T_3 ) ;
if ( ! ( F_12 ( V_19 ) & V_11 ) )
return false ;
if ( ! F_32 ( V_2 , V_19 ) )
return false ;
}
V_41 = F_16 ( V_2 , V_19 , V_4 ) ;
#else
V_41 = F_16 ( V_2 , V_17 , V_4 ) ;
#endif
if ( F_41 ( V_2 -> V_44 ) ) {
V_22 = F_44 ( ( V_4 & V_45 ) | V_46 | V_11 ) ;
} else {
V_22 = F_42 ( V_2 , V_41 , T_4 ) ;
}
if ( ! ( F_21 ( V_22 ) & V_11 ) )
return false ;
if ( ( V_39 & 2 ) && ! ( F_21 ( V_22 ) & V_46 ) )
return false ;
if ( ( V_39 & 4 ) && ! ( F_21 ( V_22 ) & V_47 ) )
return false ;
if ( F_29 ( V_2 , V_22 ) ) {
* V_40 = ( F_22 ( V_22 ) << V_12 ) | ( V_4 & ~ V_45 ) ;
return false ;
}
if ( ! F_30 ( V_2 , V_22 ) )
return false ;
V_22 = F_45 ( V_22 ) ;
if ( V_39 & 2 )
V_22 = F_46 ( V_22 ) ;
V_42 = F_33 ( V_2 , V_4 , true , F_6 ( V_17 ) , F_12 ( V_19 ) ) ;
if ( ! V_42 )
return false ;
F_26 ( * V_42 ) ;
if ( F_47 ( V_22 ) )
* V_42 = F_20 ( V_2 , V_22 , 1 ) ;
else
F_48 ( V_42 , F_20 ( V_2 , F_49 ( V_22 ) , 0 ) ) ;
if ( F_43 ( ! V_2 -> V_44 ) )
F_50 ( V_2 , V_41 , T_4 , V_22 ) ;
return true ;
}
static bool F_51 ( struct V_1 * V_2 , unsigned long V_4 )
{
T_4 * V_42 ;
unsigned long V_25 ;
if ( V_4 >= V_43 )
return false ;
V_42 = F_33 ( V_2 , V_4 , false , 0 , 0 ) ;
if ( ! V_42 )
return false ;
V_25 = F_21 ( * V_42 ) ;
return ( V_25 & ( V_11 | V_46 ) ) == ( V_11 | V_46 ) ;
}
void F_52 ( struct V_1 * V_2 , unsigned long V_4 )
{
unsigned long V_40 ;
if ( ! F_51 ( V_2 , V_4 ) && ! F_40 ( V_2 , V_4 , 2 , & V_40 ) )
F_23 ( V_2 , L_7 , V_4 ) ;
}
static void F_53 ( T_3 * V_36 )
{
if ( F_12 ( * V_36 ) & V_11 ) {
unsigned int V_3 ;
T_4 * V_37 = F_7 ( F_11 ( * V_36 ) << V_12 ) ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ )
F_26 ( V_37 [ V_3 ] ) ;
F_54 ( ( long ) V_37 ) ;
F_38 ( V_36 , F_39 ( 0 ) ) ;
}
}
static void F_55 ( T_1 * V_9 )
{
if ( F_6 ( * V_9 ) & V_11 ) {
unsigned int V_3 ;
T_3 * V_49 = F_7 ( F_8 ( * V_9 ) << V_12 ) ;
for ( V_3 = 0 ; V_3 < V_50 ; V_3 ++ )
F_53 ( & V_49 [ V_3 ] ) ;
F_54 ( ( long ) V_49 ) ;
F_35 ( V_9 , F_36 ( 0 ) ) ;
}
}
static void F_55 ( T_1 * V_9 )
{
if ( F_6 ( * V_9 ) & V_11 ) {
unsigned int V_3 ;
T_4 * V_37 = F_7 ( F_8 ( * V_9 ) << V_12 ) ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ )
F_26 ( V_37 [ V_3 ] ) ;
F_54 ( ( long ) V_37 ) ;
* V_9 = F_36 ( 0 ) ;
}
}
static void F_56 ( struct V_51 * V_6 , int V_52 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_6 -> V_53 ) ; V_3 ++ )
F_55 ( V_6 -> V_7 [ V_52 ] . V_8 + V_3 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
F_56 ( V_2 -> V_6 , V_2 -> V_15 ) ;
}
bool F_58 ( struct V_1 * V_2 , unsigned long V_4 , unsigned long * V_54 )
{
T_1 V_17 ;
T_4 V_22 ;
#ifdef F_10
T_3 V_19 ;
#endif
if ( F_41 ( V_2 -> V_44 ) ) {
* V_54 = V_4 ;
return true ;
}
V_17 = F_42 ( V_2 , F_14 ( V_2 , V_4 ) , T_1 ) ;
if ( ! ( F_6 ( V_17 ) & V_11 ) )
goto V_55;
#ifdef F_10
V_19 = F_42 ( V_2 , F_15 ( V_17 , V_4 ) , T_3 ) ;
if ( ! ( F_12 ( V_19 ) & V_11 ) )
goto V_55;
V_22 = F_42 ( V_2 , F_16 ( V_2 , V_19 , V_4 ) , T_4 ) ;
#else
V_22 = F_42 ( V_2 , F_16 ( V_2 , V_17 , V_4 ) , T_4 ) ;
#endif
if ( ! ( F_21 ( V_22 ) & V_11 ) )
goto V_55;
* V_54 = F_22 ( V_22 ) * V_28 | ( V_4 & ~ V_45 ) ;
return true ;
V_55:
* V_54 = - 1UL ;
return false ;
}
unsigned long F_59 ( struct V_1 * V_2 , unsigned long V_4 )
{
unsigned long V_54 ;
if ( ! F_58 ( V_2 , V_4 , & V_54 ) )
F_23 ( V_2 , L_8 , V_4 ) ;
return V_54 ;
}
static unsigned int F_60 ( struct V_51 * V_6 , unsigned long V_56 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_61 ( V_6 -> V_7 ) ; V_3 ++ )
if ( V_6 -> V_7 [ V_3 ] . V_8 && V_6 -> V_7 [ V_3 ] . V_16 == V_56 )
break;
return V_3 ;
}
static unsigned int F_62 ( struct V_1 * V_2 ,
unsigned long V_16 ,
int * V_57 )
{
unsigned int V_58 ;
V_58 = F_63 () % F_61 ( V_2 -> V_6 -> V_7 ) ;
if ( ! V_2 -> V_6 -> V_7 [ V_58 ] . V_8 ) {
V_2 -> V_6 -> V_7 [ V_58 ] . V_8 =
( T_1 * ) F_34 ( V_38 ) ;
if ( ! V_2 -> V_6 -> V_7 [ V_58 ] . V_8 )
V_58 = V_2 -> V_15 ;
else {
* V_57 = 1 ;
}
}
V_2 -> V_6 -> V_7 [ V_58 ] . V_16 = V_16 ;
F_56 ( V_2 -> V_6 , V_58 ) ;
V_2 -> V_6 -> V_7 [ V_58 ] . V_59 = - 1 ;
return V_58 ;
}
static bool F_64 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_60 ; V_3 ++ ) {
T_4 * V_29 = F_33 ( V_2 , V_43 + V_3 * V_28 , true ,
V_33 , V_34 ) ;
if ( ! V_29 )
return false ;
if ( V_3 == 0 && ! ( F_21 ( * V_29 ) & V_11 ) ) {
F_65 ( V_61 [ 0 ] ) ;
F_48 ( V_29 ,
F_66 ( V_61 [ 0 ] , V_62 ) ) ;
}
}
V_2 -> V_6 -> V_7 [ V_2 -> V_15 ] . V_63 = true ;
return true ;
}
static void F_67 ( struct V_51 * V_6 )
{
unsigned int V_3 , V_64 ;
for ( V_3 = 0 ; V_3 < F_61 ( V_6 -> V_7 ) ; V_3 ++ ) {
if ( ! V_6 -> V_7 [ V_3 ] . V_8 )
continue;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ )
F_55 ( V_6 -> V_7 [ V_3 ] . V_8 + V_64 ) ;
V_6 -> V_7 [ V_3 ] . V_63 = false ;
V_6 -> V_7 [ V_3 ] . V_59 = - 1 ;
}
}
void F_68 ( struct V_1 * V_2 )
{
F_67 ( V_2 -> V_6 ) ;
F_69 ( V_2 ) ;
if ( ! F_64 ( V_2 ) )
F_23 ( V_2 , L_9 ) ;
}
void F_70 ( struct V_1 * V_2 , unsigned long V_56 )
{
int V_66 , V_67 = 0 ;
if ( F_41 ( V_2 -> V_44 ) ) {
F_67 ( V_2 -> V_6 ) ;
V_2 -> V_44 = false ;
V_66 = F_61 ( V_2 -> V_6 -> V_7 ) ;
} else {
V_66 = F_60 ( V_2 -> V_6 , V_56 ) ;
}
if ( V_66 == F_61 ( V_2 -> V_6 -> V_7 ) )
V_66 = F_62 ( V_2 , V_56 , & V_67 ) ;
V_2 -> V_15 = V_66 ;
if ( V_67 )
F_69 ( V_2 ) ;
if ( ! V_2 -> V_6 -> V_7 [ V_2 -> V_15 ] . V_63 ) {
if ( ! F_64 ( V_2 ) )
F_23 ( V_2 , L_9 ) ;
}
}
static void F_71 ( struct V_1 * V_2 , int V_52 ,
unsigned long V_4 , T_4 V_22 )
{
T_1 * V_9 = F_1 ( V_2 , V_52 , V_4 ) ;
#ifdef F_10
T_3 * V_36 ;
#endif
if ( F_6 ( * V_9 ) & V_11 ) {
#ifdef F_10
V_36 = F_3 ( V_2 , * V_9 , V_4 ) ;
if ( F_12 ( * V_36 ) & V_11 ) {
#endif
T_4 * V_42 = F_9 ( V_2 , * V_9 , V_4 ) ;
F_26 ( * V_42 ) ;
if ( ( F_21 ( V_22 ) & ( V_68 | V_69 ) )
&& ! F_29 ( V_2 , V_22 ) ) {
if ( ! F_30 ( V_2 , V_22 ) )
return;
F_48 ( V_42 ,
F_20 ( V_2 , V_22 ,
F_21 ( V_22 ) & V_68 ) ) ;
} else {
F_48 ( V_42 , F_44 ( 0 ) ) ;
}
#ifdef F_10
}
#endif
}
}
void F_72 ( struct V_1 * V_2 ,
unsigned long V_16 , unsigned long V_4 , T_4 V_22 )
{
if ( V_4 >= V_43 ) {
F_23 ( V_2 , L_10 ) ;
return;
}
if ( V_4 >= V_2 -> V_6 -> V_53 ) {
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_61 ( V_2 -> V_6 -> V_7 ) ; V_3 ++ )
if ( V_2 -> V_6 -> V_7 [ V_3 ] . V_8 )
F_71 ( V_2 , V_3 , V_4 , V_22 ) ;
} else {
int V_8 = F_60 ( V_2 -> V_6 , V_16 ) ;
if ( V_8 != F_61 ( V_2 -> V_6 -> V_7 ) )
F_71 ( V_2 , V_8 , V_4 , V_22 ) ;
}
}
void F_73 ( struct V_51 * V_6 , unsigned long V_16 , T_2 V_52 )
{
int V_8 ;
if ( V_52 > V_65 ) {
F_23 ( & V_6 -> V_70 [ 0 ] , L_11 ,
V_52 , V_65 ) ;
return;
}
V_8 = F_60 ( V_6 , V_16 ) ;
if ( V_8 < F_61 ( V_6 -> V_7 ) ) {
F_55 ( V_6 -> V_7 [ V_8 ] . V_8 + V_52 ) ;
if ( ! F_64 ( & V_6 -> V_70 [ 0 ] ) ) {
F_23 ( & V_6 -> V_70 [ 0 ] ,
L_9 ) ;
}
V_6 -> V_7 [ V_8 ] . V_59 = - 1 ;
}
}
void F_74 ( struct V_51 * V_6 , unsigned long V_71 , T_2 V_52 )
{
F_68 ( & V_6 -> V_70 [ 0 ] ) ;
}
int F_75 ( struct V_51 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_70 [ 0 ] ;
int V_72 = 0 ;
V_2 -> V_15 = F_62 ( V_2 , 0 , & V_72 ) ;
if ( ! V_72 )
return - V_73 ;
V_2 -> V_44 = true ;
if ( ! F_64 ( V_2 ) ) {
F_67 ( V_6 ) ;
return - V_73 ;
}
return 0 ;
}
void F_76 ( struct V_1 * V_2 )
{
T_2 V_74 = ~ V_43 + 1 ;
if ( F_77 ( V_2 -> V_6 -> V_53 ,
& V_2 -> V_6 -> V_75 -> V_53 )
|| F_78 ( V_74 , & V_2 -> V_6 -> V_75 -> V_76 ) ) {
F_23 ( V_2 , L_12 , V_2 -> V_6 -> V_75 ) ;
return;
}
if ( V_2 -> V_6 -> V_53 >= V_43 )
F_23 ( V_2 , L_13 ,
V_2 -> V_6 -> V_53 ) ;
}
void F_79 ( struct V_51 * V_6 )
{
unsigned int V_3 ;
F_67 ( V_6 ) ;
for ( V_3 = 0 ; V_3 < F_61 ( V_6 -> V_7 ) ; V_3 ++ )
F_54 ( ( long ) V_6 -> V_7 [ V_3 ] . V_8 ) ;
}
static void F_80 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_24 = V_43 + V_28 + V_3 * V_28 * 2 ;
T_4 * V_29 ;
V_29 = F_33 ( V_2 , V_24 , false , 0 , 0 ) ;
F_26 ( * V_29 ) ;
F_48 ( V_29 , F_44 ( 0 ) ) ;
V_29 = F_33 ( V_2 , V_24 + V_28 , false , 0 , 0 ) ;
F_26 ( * V_29 ) ;
F_48 ( V_29 , F_44 ( 0 ) ) ;
}
void F_81 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
unsigned long V_24 ;
struct V_10 * V_79 , * V_80 ;
T_4 * V_29 ;
struct V_8 * V_8 = & V_2 -> V_6 -> V_7 [ V_2 -> V_15 ] ;
F_5 ( ! V_8 -> V_63 ) ;
if ( V_8 -> V_59 == F_82 () )
return;
if ( V_8 -> V_59 == - 1 ) {
unsigned int V_3 ;
F_83 (i)
F_80 ( V_2 , V_3 ) ;
} else {
F_80 ( V_2 , V_8 -> V_59 ) ;
}
V_24 = V_43 + V_28
+ F_82 () * sizeof( struct V_77 ) ;
V_29 = F_33 ( V_2 , V_24 , false , 0 , 0 ) ;
V_80 = F_84 ( F_37 ( V_2 -> V_80 ) >> V_12 ) ;
F_65 ( V_80 ) ;
F_48 ( V_29 , F_66 ( V_80 , F_25 ( V_81 & ~ V_26 ) ) ) ;
V_29 = F_33 ( V_2 , V_24 + V_28 , false , 0 , 0 ) ;
V_79
= V_61 [ 1 + F_82 () * 2 + 1 ] ;
F_65 ( V_79 ) ;
F_48 ( V_29 , F_66 ( V_79 ,
F_25 ( V_82 & ~ V_26 ) ) ) ;
V_8 -> V_59 = F_82 () ;
}
