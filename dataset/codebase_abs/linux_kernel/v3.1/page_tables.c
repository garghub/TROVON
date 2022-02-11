static T_1 * F_1 ( struct V_1 * V_2 , T_2 V_3 , unsigned long V_4 )
{
unsigned int V_5 = F_2 ( V_4 ) ;
#ifndef F_3
if ( V_5 >= V_6 ) {
F_4 ( V_2 , L_1 ) ;
V_5 = 0 ;
}
#endif
return & V_2 -> V_7 -> V_8 [ V_3 ] . V_9 [ V_5 ] ;
}
static T_3 * F_5 ( struct V_1 * V_2 , T_1 V_10 , unsigned long V_4 )
{
unsigned int V_5 = F_6 ( V_4 ) ;
T_3 * V_11 ;
if ( F_2 ( V_4 ) == V_6 &&
V_5 >= V_12 ) {
F_4 ( V_2 , L_1 ) ;
V_5 = 0 ;
}
F_7 ( ! ( F_8 ( V_10 ) & V_13 ) ) ;
V_11 = F_9 ( F_10 ( V_10 ) << V_14 ) ;
return & V_11 [ V_5 ] ;
}
static T_4 * F_11 ( struct V_1 * V_2 , T_1 V_10 , unsigned long V_4 )
{
#ifdef F_3
T_3 * V_15 = F_5 ( V_2 , V_10 , V_4 ) ;
T_4 * V_11 = F_9 ( F_12 ( * V_15 ) << V_14 ) ;
F_7 ( ! ( F_13 ( * V_15 ) & V_13 ) ) ;
#else
T_4 * V_11 = F_9 ( F_10 ( V_10 ) << V_14 ) ;
F_7 ( ! ( F_8 ( V_10 ) & V_13 ) ) ;
#endif
return & V_11 [ F_14 ( V_4 ) ] ;
}
static unsigned long F_15 ( struct V_1 * V_2 , unsigned long V_4 )
{
unsigned int V_5 = V_4 >> ( V_16 ) ;
return V_2 -> V_7 -> V_8 [ V_2 -> V_17 ] . V_18 + V_5 * sizeof( T_1 ) ;
}
static unsigned long F_16 ( T_1 V_19 , unsigned long V_4 )
{
unsigned long V_20 = F_10 ( V_19 ) << V_14 ;
F_7 ( ! ( F_8 ( V_19 ) & V_13 ) ) ;
return V_20 + F_6 ( V_4 ) * sizeof( T_3 ) ;
}
static unsigned long F_17 ( struct V_1 * V_2 ,
T_3 V_21 , unsigned long V_4 )
{
unsigned long V_20 = F_12 ( V_21 ) << V_14 ;
F_7 ( ! ( F_13 ( V_21 ) & V_13 ) ) ;
return V_20 + F_14 ( V_4 ) * sizeof( T_4 ) ;
}
static unsigned long F_17 ( struct V_1 * V_2 ,
T_1 V_19 , unsigned long V_4 )
{
unsigned long V_20 = F_10 ( V_19 ) << V_14 ;
F_7 ( ! ( F_8 ( V_19 ) & V_13 ) ) ;
return V_20 + F_14 ( V_4 ) * sizeof( T_4 ) ;
}
static unsigned long F_18 ( unsigned long V_22 , int V_23 )
{
struct V_11 * V_11 ;
if ( F_19 ( V_22 << V_14 , 1 , V_23 , & V_11 ) == 1 )
return F_20 ( V_11 ) ;
return - 1UL ;
}
static T_4 F_21 ( struct V_1 * V_2 , T_4 V_24 , int V_23 )
{
unsigned long V_25 , V_26 , V_27 ;
V_27 = ( F_22 ( V_24 ) & ~ V_28 ) ;
V_26 = ( unsigned long ) V_2 -> V_7 -> V_29 / V_30 ;
V_25 = F_18 ( V_26 + F_23 ( V_24 ) , V_23 ) ;
if ( V_25 == - 1UL ) {
F_4 ( V_2 , L_2 , F_23 ( V_24 ) ) ;
V_27 = 0 ;
}
return F_24 ( V_25 , F_25 ( V_27 ) ) ;
}
static void F_26 ( T_4 V_31 )
{
if ( F_22 ( V_31 ) & V_13 )
F_27 ( F_28 ( V_31 ) ) ;
}
static void F_29 ( struct V_1 * V_2 , T_4 V_24 )
{
if ( ( F_22 ( V_24 ) & V_32 ) ||
F_23 ( V_24 ) >= V_2 -> V_7 -> V_33 )
F_4 ( V_2 , L_3 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_1 V_19 )
{
if ( ( F_8 ( V_19 ) & ~ V_34 ) ||
( F_10 ( V_19 ) >= V_2 -> V_7 -> V_33 ) )
F_4 ( V_2 , L_4 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_3 V_21 )
{
if ( ( F_13 ( V_21 ) & ~ V_35 ) ||
( F_12 ( V_21 ) >= V_2 -> V_7 -> V_33 ) )
F_4 ( V_2 , L_5 ) ;
}
bool F_32 ( struct V_1 * V_2 , unsigned long V_4 , int V_36 )
{
T_1 V_19 ;
T_1 * V_10 ;
unsigned long V_37 ;
T_4 V_24 ;
T_4 * V_38 ;
#ifdef F_3
T_3 * V_39 ;
T_3 V_21 ;
#endif
if ( F_33 ( V_2 -> V_40 ) ) {
V_19 = F_34 ( V_34 ) ;
} else {
V_19 = F_35 ( V_2 , F_15 ( V_2 , V_4 ) , T_1 ) ;
if ( ! ( F_8 ( V_19 ) & V_13 ) )
return false ;
}
V_10 = F_1 ( V_2 , V_2 -> V_17 , V_4 ) ;
if ( ! ( F_8 ( * V_10 ) & V_13 ) ) {
unsigned long V_41 = F_36 ( V_42 ) ;
if ( ! V_41 ) {
F_4 ( V_2 , L_6 ) ;
return false ;
}
F_30 ( V_2 , V_19 ) ;
F_37 ( V_10 , F_34 ( F_38 ( V_41 ) | F_8 ( V_19 ) ) ) ;
}
#ifdef F_3
if ( F_33 ( V_2 -> V_40 ) ) {
V_21 = F_39 ( V_35 ) ;
} else {
V_21 = F_35 ( V_2 , F_16 ( V_19 , V_4 ) , T_3 ) ;
if ( ! ( F_13 ( V_21 ) & V_13 ) )
return false ;
}
V_39 = F_5 ( V_2 , * V_10 , V_4 ) ;
if ( ! ( F_13 ( * V_39 ) & V_13 ) ) {
unsigned long V_41 = F_36 ( V_42 ) ;
if ( ! V_41 ) {
F_4 ( V_2 , L_6 ) ;
return false ;
}
F_31 ( V_2 , V_21 ) ;
F_40 ( V_39 , F_39 ( F_38 ( V_41 ) | F_13 ( V_21 ) ) ) ;
}
V_37 = F_17 ( V_2 , V_21 , V_4 ) ;
#else
V_37 = F_17 ( V_2 , V_19 , V_4 ) ;
#endif
if ( F_33 ( V_2 -> V_40 ) ) {
V_24 = F_41 ( ( V_4 & V_43 ) | V_44 | V_13 ) ;
} else {
V_24 = F_35 ( V_2 , V_37 , T_4 ) ;
}
if ( ! ( F_22 ( V_24 ) & V_13 ) )
return false ;
if ( ( V_36 & 2 ) && ! ( F_22 ( V_24 ) & V_44 ) )
return false ;
if ( ( V_36 & 4 ) && ! ( F_22 ( V_24 ) & V_45 ) )
return false ;
F_29 ( V_2 , V_24 ) ;
V_24 = F_42 ( V_24 ) ;
if ( V_36 & 2 )
V_24 = F_43 ( V_24 ) ;
V_38 = F_11 ( V_2 , * V_10 , V_4 ) ;
F_26 ( * V_38 ) ;
if ( F_44 ( V_24 ) )
* V_38 = F_21 ( V_2 , V_24 , 1 ) ;
else
F_45 ( V_38 , F_21 ( V_2 , F_46 ( V_24 ) , 0 ) ) ;
if ( F_47 ( ! V_2 -> V_40 ) )
F_48 ( V_2 , V_37 , T_4 , V_24 ) ;
return true ;
}
static bool F_49 ( struct V_1 * V_2 , unsigned long V_4 )
{
T_1 * V_10 ;
unsigned long V_27 ;
#ifdef F_3
T_3 * V_39 ;
#endif
V_10 = F_1 ( V_2 , V_2 -> V_17 , V_4 ) ;
if ( ! ( F_8 ( * V_10 ) & V_13 ) )
return false ;
#ifdef F_3
V_39 = F_5 ( V_2 , * V_10 , V_4 ) ;
if ( ! ( F_13 ( * V_39 ) & V_13 ) )
return false ;
#endif
V_27 = F_22 ( * ( F_11 ( V_2 , * V_10 , V_4 ) ) ) ;
return ( V_27 & ( V_13 | V_44 ) ) == ( V_13 | V_44 ) ;
}
void F_50 ( struct V_1 * V_2 , unsigned long V_4 )
{
if ( ! F_49 ( V_2 , V_4 ) && ! F_32 ( V_2 , V_4 , 2 ) )
F_4 ( V_2 , L_7 , V_4 ) ;
}
static void F_51 ( T_3 * V_39 )
{
if ( F_13 ( * V_39 ) & V_13 ) {
unsigned int V_3 ;
T_4 * V_41 = F_9 ( F_12 ( * V_39 ) << V_14 ) ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ )
F_26 ( V_41 [ V_3 ] ) ;
F_52 ( ( long ) V_41 ) ;
F_40 ( V_39 , F_39 ( 0 ) ) ;
}
}
static void F_53 ( T_1 * V_10 )
{
if ( F_8 ( * V_10 ) & V_13 ) {
unsigned int V_3 ;
T_3 * V_47 = F_9 ( F_10 ( * V_10 ) << V_14 ) ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ )
F_51 ( & V_47 [ V_3 ] ) ;
F_52 ( ( long ) V_47 ) ;
F_37 ( V_10 , F_34 ( 0 ) ) ;
}
}
static void F_53 ( T_1 * V_10 )
{
if ( F_8 ( * V_10 ) & V_13 ) {
unsigned int V_3 ;
T_4 * V_41 = F_9 ( F_10 ( * V_10 ) << V_14 ) ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ )
F_26 ( V_41 [ V_3 ] ) ;
F_52 ( ( long ) V_41 ) ;
* V_10 = F_34 ( 0 ) ;
}
}
static void F_54 ( struct V_49 * V_7 , int V_50 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_51 ) ; V_3 ++ )
F_53 ( V_7 -> V_8 [ V_50 ] . V_9 + V_3 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_54 ( V_2 -> V_7 , V_2 -> V_17 ) ;
}
unsigned long F_56 ( struct V_1 * V_2 , unsigned long V_4 )
{
T_1 V_19 ;
T_4 V_24 ;
#ifdef F_3
T_3 V_21 ;
#endif
if ( F_33 ( V_2 -> V_40 ) )
return V_4 ;
V_19 = F_35 ( V_2 , F_15 ( V_2 , V_4 ) , T_1 ) ;
if ( ! ( F_8 ( V_19 ) & V_13 ) ) {
F_4 ( V_2 , L_8 , V_4 ) ;
return - 1UL ;
}
#ifdef F_3
V_21 = F_35 ( V_2 , F_16 ( V_19 , V_4 ) , T_3 ) ;
if ( ! ( F_13 ( V_21 ) & V_13 ) )
F_4 ( V_2 , L_8 , V_4 ) ;
V_24 = F_35 ( V_2 , F_17 ( V_2 , V_21 , V_4 ) , T_4 ) ;
#else
V_24 = F_35 ( V_2 , F_17 ( V_2 , V_19 , V_4 ) , T_4 ) ;
#endif
if ( ! ( F_22 ( V_24 ) & V_13 ) )
F_4 ( V_2 , L_8 , V_4 ) ;
return F_23 ( V_24 ) * V_30 | ( V_4 & ~ V_43 ) ;
}
static unsigned int F_57 ( struct V_49 * V_7 , unsigned long V_52 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_58 ( V_7 -> V_8 ) ; V_3 ++ )
if ( V_7 -> V_8 [ V_3 ] . V_9 && V_7 -> V_8 [ V_3 ] . V_18 == V_52 )
break;
return V_3 ;
}
static unsigned int F_59 ( struct V_1 * V_2 ,
unsigned long V_18 ,
int * V_53 )
{
unsigned int V_54 ;
#ifdef F_3
T_3 * V_55 ;
#endif
V_54 = F_60 () % F_58 ( V_2 -> V_7 -> V_8 ) ;
if ( ! V_2 -> V_7 -> V_8 [ V_54 ] . V_9 ) {
V_2 -> V_7 -> V_8 [ V_54 ] . V_9 =
( T_1 * ) F_36 ( V_42 ) ;
if ( ! V_2 -> V_7 -> V_8 [ V_54 ] . V_9 )
V_54 = V_2 -> V_17 ;
else {
#ifdef F_3
V_55 = ( T_3 * ) F_36 ( V_42 ) ;
if ( ! V_55 ) {
F_52 ( ( long ) V_2 -> V_7 -> V_8 [ V_54 ] . V_9 ) ;
F_37 ( V_2 -> V_7 -> V_8 [ V_54 ] . V_9 , F_34 ( 0 ) ) ;
V_54 = V_2 -> V_17 ;
} else {
F_37 ( V_2 -> V_7 -> V_8 [ V_54 ] . V_9 +
V_6 ,
F_34 ( F_38 ( V_55 ) | V_13 ) ) ;
* V_53 = 1 ;
}
#else
* V_53 = 1 ;
#endif
}
}
V_2 -> V_7 -> V_8 [ V_54 ] . V_18 = V_18 ;
F_54 ( V_2 -> V_7 , V_54 ) ;
return V_54 ;
}
static void F_61 ( struct V_49 * V_7 )
{
unsigned int V_3 , V_56 ;
for ( V_3 = 0 ; V_3 < F_58 ( V_7 -> V_8 ) ; V_3 ++ )
if ( V_7 -> V_8 [ V_3 ] . V_9 ) {
#ifdef F_3
T_1 * V_10 ;
T_3 * V_47 ;
unsigned int V_57 ;
V_10 = V_7 -> V_8 [ V_3 ] . V_9 + V_6 ;
V_47 = F_9 ( F_10 ( * V_10 ) << V_14 ) ;
for ( V_57 = 0 ; V_57 < V_12 ; V_57 ++ )
F_51 ( & V_47 [ V_57 ] ) ;
#endif
for ( V_56 = 0 ; V_56 < V_6 ; V_56 ++ )
F_53 ( V_7 -> V_8 [ V_3 ] . V_9 + V_56 ) ;
}
}
void F_62 ( struct V_1 * V_2 )
{
F_61 ( V_2 -> V_7 ) ;
F_63 ( V_2 ) ;
}
void F_64 ( struct V_1 * V_2 , unsigned long V_52 )
{
int V_58 , V_59 = 0 ;
if ( F_33 ( V_2 -> V_40 ) ) {
F_61 ( V_2 -> V_7 ) ;
V_2 -> V_40 = false ;
V_58 = F_58 ( V_2 -> V_7 -> V_8 ) ;
} else {
V_58 = F_57 ( V_2 -> V_7 , V_52 ) ;
}
if ( V_58 == F_58 ( V_2 -> V_7 -> V_8 ) )
V_58 = F_59 ( V_2 , V_52 , & V_59 ) ;
V_2 -> V_17 = V_58 ;
if ( V_59 )
F_63 ( V_2 ) ;
}
static void F_65 ( struct V_1 * V_2 , int V_50 ,
unsigned long V_4 , T_4 V_24 )
{
T_1 * V_10 = F_1 ( V_2 , V_50 , V_4 ) ;
#ifdef F_3
T_3 * V_39 ;
#endif
if ( F_8 ( * V_10 ) & V_13 ) {
#ifdef F_3
V_39 = F_5 ( V_2 , * V_10 , V_4 ) ;
if ( F_13 ( * V_39 ) & V_13 ) {
#endif
T_4 * V_38 = F_11 ( V_2 , * V_10 , V_4 ) ;
F_26 ( * V_38 ) ;
if ( F_22 ( V_24 ) & ( V_60 | V_61 ) ) {
F_29 ( V_2 , V_24 ) ;
F_45 ( V_38 ,
F_21 ( V_2 , V_24 ,
F_22 ( V_24 ) & V_60 ) ) ;
} else {
F_45 ( V_38 , F_41 ( 0 ) ) ;
}
#ifdef F_3
}
#endif
}
}
void F_66 ( struct V_1 * V_2 ,
unsigned long V_18 , unsigned long V_4 , T_4 V_24 )
{
if ( V_4 >= V_2 -> V_7 -> V_51 ) {
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_58 ( V_2 -> V_7 -> V_8 ) ; V_3 ++ )
if ( V_2 -> V_7 -> V_8 [ V_3 ] . V_9 )
F_65 ( V_2 , V_3 , V_4 , V_24 ) ;
} else {
int V_9 = F_57 ( V_2 -> V_7 , V_18 ) ;
if ( V_9 != F_58 ( V_2 -> V_7 -> V_8 ) )
F_65 ( V_2 , V_9 , V_4 , V_24 ) ;
}
}
void F_67 ( struct V_49 * V_7 , unsigned long V_18 , T_2 V_50 )
{
int V_9 ;
if ( V_50 >= V_6 )
return;
V_9 = F_57 ( V_7 , V_18 ) ;
if ( V_9 < F_58 ( V_7 -> V_8 ) )
F_53 ( V_7 -> V_8 [ V_9 ] . V_9 + V_50 ) ;
}
void F_68 ( struct V_49 * V_7 , unsigned long V_62 , T_2 V_50 )
{
F_62 ( & V_7 -> V_63 [ 0 ] ) ;
}
int F_69 ( struct V_49 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_63 [ 0 ] ;
int V_64 = 0 ;
V_2 -> V_17 = F_59 ( V_2 , 0 , & V_64 ) ;
if ( ! V_64 )
return - V_65 ;
V_2 -> V_40 = true ;
return 0 ;
}
void F_70 ( struct V_1 * V_2 )
{
if ( F_71 ( V_2 -> V_7 -> V_51 ,
& V_2 -> V_7 -> V_66 -> V_51 )
|| F_72 ( V_67 * 1024 * 1024 ,
& V_2 -> V_7 -> V_66 -> V_68 ) ) {
F_4 ( V_2 , L_9 , V_2 -> V_7 -> V_66 ) ;
return;
}
#ifdef F_3
if ( F_2 ( V_2 -> V_7 -> V_51 ) == V_6 &&
F_6 ( V_2 -> V_7 -> V_51 ) == V_12 )
#else
if ( F_2 ( V_2 -> V_7 -> V_51 ) >= V_6 )
#endif
F_4 ( V_2 , L_10 ,
V_2 -> V_7 -> V_51 ) ;
}
void F_73 ( struct V_49 * V_7 )
{
unsigned int V_3 ;
F_61 ( V_7 ) ;
for ( V_3 = 0 ; V_3 < F_58 ( V_7 -> V_8 ) ; V_3 ++ )
F_52 ( ( long ) V_7 -> V_8 [ V_3 ] . V_9 ) ;
}
void F_74 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
T_4 * V_71 = F_75 ( V_72 ) ;
T_4 V_73 ;
#ifdef F_3
T_3 V_74 ;
T_3 * V_55 ;
V_74 = F_76 ( F_38 ( V_71 ) >> V_14 ,
V_75 ) ;
V_55 = F_9 ( F_10 ( V_2 -> V_7 ->
V_8 [ V_2 -> V_17 ] . V_9 [ V_6 ] )
<< V_14 ) ;
F_40 ( & V_55 [ V_12 ] , V_74 ) ;
#else
T_1 V_76 ;
V_76 = F_34 ( F_38 ( V_71 ) | V_77 ) ;
V_2 -> V_7 -> V_8 [ V_2 -> V_17 ] . V_9 [ V_6 ] = V_76 ;
#endif
V_73 = F_24 ( F_38 ( V_2 -> V_78 ) >> V_14 , V_79 ) ;
F_45 ( & V_71 [ F_14 ( ( unsigned long ) V_70 ) ] , V_73 ) ;
}
static void F_77 ( void )
{
unsigned int V_3 ;
F_78 (i)
F_52 ( ( long ) V_71 ( V_3 ) ) ;
}
static T_5 void F_79 ( unsigned int V_2 ,
struct V_11 * V_80 [] ,
unsigned int V_70 )
{
unsigned int V_3 ;
T_4 * V_31 = V_71 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_70 ; V_3 ++ ) {
F_45 ( & V_31 [ V_3 ] , F_80 ( V_80 [ V_3 ] ,
F_25 ( V_13 | V_61 ) ) ) ;
}
V_3 = V_70 + V_2 * 2 ;
F_45 ( & V_31 [ V_3 ] , F_24 ( F_20 ( V_80 [ V_3 ] ) ,
F_25 ( V_13 | V_61 | V_44 ) ) ) ;
F_45 ( & V_31 [ V_3 + 1 ] , F_24 ( F_20 ( V_80 [ V_3 + 1 ] ) ,
F_25 ( V_13 | V_61 ) ) ) ;
}
T_5 int F_81 ( struct V_11 * * V_80 , unsigned int V_70 )
{
unsigned int V_3 ;
F_78 (i) {
V_71 ( V_3 ) = ( T_4 * ) F_36 ( V_42 ) ;
if ( ! V_71 ( V_3 ) ) {
F_77 () ;
return - V_65 ;
}
F_79 ( V_3 , V_80 , V_70 ) ;
}
return 0 ;
}
void F_82 ( void )
{
F_77 () ;
}
