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
V_19 = F_33 ( V_2 , F_15 ( V_2 , V_4 ) , T_1 ) ;
if ( ! ( F_8 ( V_19 ) & V_13 ) )
return false ;
V_10 = F_1 ( V_2 , V_2 -> V_17 , V_4 ) ;
if ( ! ( F_8 ( * V_10 ) & V_13 ) ) {
unsigned long V_40 = F_34 ( V_41 ) ;
if ( ! V_40 ) {
F_4 ( V_2 , L_6 ) ;
return false ;
}
F_30 ( V_2 , V_19 ) ;
F_35 ( V_10 , F_36 ( F_37 ( V_40 ) | F_8 ( V_19 ) ) ) ;
}
#ifdef F_3
V_21 = F_33 ( V_2 , F_16 ( V_19 , V_4 ) , T_3 ) ;
if ( ! ( F_13 ( V_21 ) & V_13 ) )
return false ;
V_39 = F_5 ( V_2 , * V_10 , V_4 ) ;
if ( ! ( F_13 ( * V_39 ) & V_13 ) ) {
unsigned long V_40 = F_34 ( V_41 ) ;
if ( ! V_40 ) {
F_4 ( V_2 , L_6 ) ;
return false ;
}
F_31 ( V_2 , V_21 ) ;
F_38 ( V_39 , F_39 ( F_37 ( V_40 ) | F_13 ( V_21 ) ) ) ;
}
V_37 = F_17 ( V_2 , V_21 , V_4 ) ;
#else
V_37 = F_17 ( V_2 , V_19 , V_4 ) ;
#endif
V_24 = F_33 ( V_2 , V_37 , T_4 ) ;
if ( ! ( F_22 ( V_24 ) & V_13 ) )
return false ;
if ( ( V_36 & 2 ) && ! ( F_22 ( V_24 ) & V_42 ) )
return false ;
if ( ( V_36 & 4 ) && ! ( F_22 ( V_24 ) & V_43 ) )
return false ;
F_29 ( V_2 , V_24 ) ;
V_24 = F_40 ( V_24 ) ;
if ( V_36 & 2 )
V_24 = F_41 ( V_24 ) ;
V_38 = F_11 ( V_2 , * V_10 , V_4 ) ;
F_26 ( * V_38 ) ;
if ( F_42 ( V_24 ) )
* V_38 = F_21 ( V_2 , V_24 , 1 ) ;
else
F_43 ( V_38 , F_21 ( V_2 , F_44 ( V_24 ) , 0 ) ) ;
F_45 ( V_2 , V_37 , T_4 , V_24 ) ;
return true ;
}
static bool F_46 ( struct V_1 * V_2 , unsigned long V_4 )
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
return ( V_27 & ( V_13 | V_42 ) ) == ( V_13 | V_42 ) ;
}
void F_47 ( struct V_1 * V_2 , unsigned long V_4 )
{
if ( ! F_46 ( V_2 , V_4 ) && ! F_32 ( V_2 , V_4 , 2 ) )
F_4 ( V_2 , L_7 , V_4 ) ;
}
static void F_48 ( T_3 * V_39 )
{
if ( F_13 ( * V_39 ) & V_13 ) {
unsigned int V_3 ;
T_4 * V_40 = F_9 ( F_12 ( * V_39 ) << V_14 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
F_26 ( V_40 [ V_3 ] ) ;
F_49 ( ( long ) V_40 ) ;
F_38 ( V_39 , F_39 ( 0 ) ) ;
}
}
static void F_50 ( T_1 * V_10 )
{
if ( F_8 ( * V_10 ) & V_13 ) {
unsigned int V_3 ;
T_3 * V_45 = F_9 ( F_10 ( * V_10 ) << V_14 ) ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ )
F_48 ( & V_45 [ V_3 ] ) ;
F_49 ( ( long ) V_45 ) ;
F_35 ( V_10 , F_36 ( 0 ) ) ;
}
}
static void F_50 ( T_1 * V_10 )
{
if ( F_8 ( * V_10 ) & V_13 ) {
unsigned int V_3 ;
T_4 * V_40 = F_9 ( F_10 ( * V_10 ) << V_14 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
F_26 ( V_40 [ V_3 ] ) ;
F_49 ( ( long ) V_40 ) ;
* V_10 = F_36 ( 0 ) ;
}
}
static void F_51 ( struct V_47 * V_7 , int V_48 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_7 -> V_49 ) ; V_3 ++ )
F_50 ( V_7 -> V_8 [ V_48 ] . V_9 + V_3 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
F_51 ( V_2 -> V_7 , V_2 -> V_17 ) ;
}
unsigned long F_53 ( struct V_1 * V_2 , unsigned long V_4 )
{
T_1 V_19 ;
T_4 V_24 ;
#ifdef F_3
T_3 V_21 ;
#endif
V_19 = F_33 ( V_2 , F_15 ( V_2 , V_4 ) , T_1 ) ;
if ( ! ( F_8 ( V_19 ) & V_13 ) ) {
F_4 ( V_2 , L_8 , V_4 ) ;
return - 1UL ;
}
#ifdef F_3
V_21 = F_33 ( V_2 , F_16 ( V_19 , V_4 ) , T_3 ) ;
if ( ! ( F_13 ( V_21 ) & V_13 ) )
F_4 ( V_2 , L_8 , V_4 ) ;
V_24 = F_33 ( V_2 , F_17 ( V_2 , V_21 , V_4 ) , T_4 ) ;
#else
V_24 = F_33 ( V_2 , F_17 ( V_2 , V_19 , V_4 ) , T_4 ) ;
#endif
if ( ! ( F_22 ( V_24 ) & V_13 ) )
F_4 ( V_2 , L_8 , V_4 ) ;
return F_23 ( V_24 ) * V_30 | ( V_4 & ~ V_50 ) ;
}
static unsigned int F_54 ( struct V_47 * V_7 , unsigned long V_51 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_55 ( V_7 -> V_8 ) ; V_3 ++ )
if ( V_7 -> V_8 [ V_3 ] . V_9 && V_7 -> V_8 [ V_3 ] . V_18 == V_51 )
break;
return V_3 ;
}
static unsigned int F_56 ( struct V_1 * V_2 ,
unsigned long V_18 ,
int * V_52 )
{
unsigned int V_53 ;
#ifdef F_3
T_3 * V_54 ;
#endif
V_53 = F_57 () % F_55 ( V_2 -> V_7 -> V_8 ) ;
if ( ! V_2 -> V_7 -> V_8 [ V_53 ] . V_9 ) {
V_2 -> V_7 -> V_8 [ V_53 ] . V_9 =
( T_1 * ) F_34 ( V_41 ) ;
if ( ! V_2 -> V_7 -> V_8 [ V_53 ] . V_9 )
V_53 = V_2 -> V_17 ;
else {
#ifdef F_3
V_54 = ( T_3 * ) F_34 ( V_41 ) ;
if ( ! V_54 ) {
F_49 ( ( long ) V_2 -> V_7 -> V_8 [ V_53 ] . V_9 ) ;
F_35 ( V_2 -> V_7 -> V_8 [ V_53 ] . V_9 , F_36 ( 0 ) ) ;
V_53 = V_2 -> V_17 ;
} else {
F_35 ( V_2 -> V_7 -> V_8 [ V_53 ] . V_9 +
V_6 ,
F_36 ( F_37 ( V_54 ) | V_13 ) ) ;
* V_52 = 1 ;
}
#else
* V_52 = 1 ;
#endif
}
}
V_2 -> V_7 -> V_8 [ V_53 ] . V_18 = V_18 ;
F_51 ( V_2 -> V_7 , V_53 ) ;
return V_53 ;
}
void F_58 ( struct V_1 * V_2 , unsigned long V_51 )
{
int V_55 , V_56 = 0 ;
V_55 = F_54 ( V_2 -> V_7 , V_51 ) ;
if ( V_55 == F_55 ( V_2 -> V_7 -> V_8 ) )
V_55 = F_56 ( V_2 , V_51 , & V_56 ) ;
V_2 -> V_17 = V_55 ;
if ( V_56 )
F_59 ( V_2 ) ;
}
static void F_60 ( struct V_47 * V_7 )
{
unsigned int V_3 , V_57 ;
for ( V_3 = 0 ; V_3 < F_55 ( V_7 -> V_8 ) ; V_3 ++ )
if ( V_7 -> V_8 [ V_3 ] . V_9 ) {
#ifdef F_3
T_1 * V_10 ;
T_3 * V_45 ;
unsigned int V_58 ;
V_10 = V_7 -> V_8 [ V_3 ] . V_9 + V_6 ;
V_45 = F_9 ( F_10 ( * V_10 ) << V_14 ) ;
for ( V_58 = 0 ; V_58 < V_12 ; V_58 ++ )
F_48 ( & V_45 [ V_58 ] ) ;
#endif
for ( V_57 = 0 ; V_57 < V_6 ; V_57 ++ )
F_50 ( V_7 -> V_8 [ V_3 ] . V_9 + V_57 ) ;
}
}
void F_61 ( struct V_1 * V_2 )
{
F_60 ( V_2 -> V_7 ) ;
F_59 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 , int V_48 ,
unsigned long V_4 , T_4 V_24 )
{
T_1 * V_10 = F_1 ( V_2 , V_48 , V_4 ) ;
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
if ( F_22 ( V_24 ) & ( V_59 | V_60 ) ) {
F_29 ( V_2 , V_24 ) ;
F_43 ( V_38 ,
F_21 ( V_2 , V_24 ,
F_22 ( V_24 ) & V_59 ) ) ;
} else {
F_43 ( V_38 , F_63 ( 0 ) ) ;
}
#ifdef F_3
}
#endif
}
}
void F_64 ( struct V_1 * V_2 ,
unsigned long V_18 , unsigned long V_4 , T_4 V_24 )
{
if ( V_4 >= V_2 -> V_7 -> V_49 ) {
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_55 ( V_2 -> V_7 -> V_8 ) ; V_3 ++ )
if ( V_2 -> V_7 -> V_8 [ V_3 ] . V_9 )
F_62 ( V_2 , V_3 , V_4 , V_24 ) ;
} else {
int V_9 = F_54 ( V_2 -> V_7 , V_18 ) ;
if ( V_9 != F_55 ( V_2 -> V_7 -> V_8 ) )
F_62 ( V_2 , V_9 , V_4 , V_24 ) ;
}
}
void F_65 ( struct V_47 * V_7 , unsigned long V_18 , T_2 V_48 )
{
int V_9 ;
if ( V_48 >= V_6 )
return;
V_9 = F_54 ( V_7 , V_18 ) ;
if ( V_9 < F_55 ( V_7 -> V_8 ) )
F_50 ( V_7 -> V_8 [ V_9 ] . V_9 + V_48 ) ;
}
void F_66 ( struct V_47 * V_7 , unsigned long V_61 , T_2 V_48 )
{
F_61 ( & V_7 -> V_62 [ 0 ] ) ;
}
static unsigned long F_67 ( struct V_47 * V_7 ,
unsigned long V_63 ,
unsigned long V_64 )
{
T_1 T_5 * V_9 ;
T_4 T_5 * V_65 ;
unsigned long V_29 = ( unsigned long ) V_7 -> V_29 ;
unsigned int V_66 , V_3 , V_67 ;
#ifdef F_3
T_3 T_5 * V_68 ;
unsigned int V_57 ;
T_1 V_69 ;
T_3 V_15 ;
#else
unsigned int V_70 ;
#endif
V_66 = V_63 / V_30 ;
V_67 = ( V_66 + V_44 - 1 ) / V_44 ;
V_9 = ( T_1 * ) ( V_63 + V_29 - V_64 - V_30 ) ;
V_65 = ( void * ) V_9 - V_67 * V_30 ;
#ifdef F_3
V_68 = ( void * ) V_65 - V_30 ;
#endif
for ( V_3 = 0 ; V_3 < V_66 ; V_3 ++ ) {
T_4 V_31 ;
V_31 = F_24 ( V_3 , F_25 ( V_13 | V_42 | V_43 ) ) ;
if ( F_68 ( & V_65 [ V_3 ] , & V_31 , sizeof( V_31 ) ) != 0 )
return - V_71 ;
}
#ifdef F_3
for ( V_3 = V_57 = 0 ; V_3 < V_66 && V_57 < V_46 ;
V_3 += V_44 , V_57 ++ ) {
V_15 = F_69 ( ( ( unsigned long ) & V_65 [ V_3 ] - V_29 ) / V_30 ,
F_25 ( V_13 | V_42 | V_43 ) ) ;
if ( F_68 ( & V_68 [ V_57 ] , & V_15 , sizeof( V_15 ) ) != 0 )
return - V_71 ;
}
V_69 = F_36 ( ( ( unsigned long ) V_68 - V_29 ) | V_13 ) ;
if ( F_68 ( & V_9 [ 0 ] , & V_69 , sizeof( V_69 ) ) != 0 )
return - V_71 ;
if ( F_68 ( & V_9 [ V_72 ] , & V_69 , sizeof( V_69 ) ) )
return - V_71 ;
#else
V_70 = ( unsigned long ) V_65 - V_29 ;
for ( V_3 = 0 ; V_3 < V_66 ; V_3 += V_44 ) {
T_1 V_69 ;
V_69 = F_36 ( ( V_70 + V_3 * sizeof( T_4 ) ) |
( V_13 | V_42 | V_43 ) ) ;
if ( F_68 ( & V_9 [ V_3 / V_44 ] , & V_69 , sizeof( V_69 ) )
|| F_68 ( & V_9 [ F_2 ( V_73 )
+ V_3 / V_44 ] ,
& V_69 , sizeof( V_69 ) ) )
return - V_71 ;
}
#endif
return ( unsigned long ) V_9 - V_29 ;
}
int F_70 ( struct V_47 * V_7 )
{
T_6 V_63 ;
T_2 V_64 ;
struct V_74 T_5 * V_75 = (struct V_74 * ) V_7 -> V_29 ;
#ifdef F_3
T_1 * V_69 ;
T_3 * V_54 ;
#endif
if ( F_71 ( & V_63 , & V_75 -> V_76 [ 0 ] . V_77 , sizeof( V_63 ) )
|| F_72 ( V_64 , & V_75 -> V_78 . V_79 ) )
return - V_71 ;
V_7 -> V_8 [ 0 ] . V_18 = F_67 ( V_7 , V_63 , V_64 ) ;
if ( F_73 ( V_7 -> V_8 [ 0 ] . V_18 ) )
return V_7 -> V_8 [ 0 ] . V_18 ;
V_7 -> V_8 [ 0 ] . V_9 = ( T_1 * ) F_34 ( V_41 ) ;
if ( ! V_7 -> V_8 [ 0 ] . V_9 )
return - V_80 ;
#ifdef F_3
V_69 = V_7 -> V_8 [ 0 ] . V_9 ;
V_54 = ( T_3 * ) F_34 ( V_41 ) ;
if ( ! V_54 )
return - V_80 ;
F_35 ( V_69 + V_6 ,
F_36 ( F_37 ( V_54 ) | V_13 ) ) ;
#endif
V_7 -> V_62 [ 0 ] . V_17 = 0 ;
return 0 ;
}
void F_74 ( struct V_1 * V_2 )
{
if ( F_72 ( V_2 -> V_7 -> V_49 ,
& V_2 -> V_7 -> V_81 -> V_49 )
|| F_75 ( V_82 * 1024 * 1024 ,
& V_2 -> V_7 -> V_81 -> V_83 )
|| F_75 ( V_2 -> V_7 -> V_8 [ 0 ] . V_18 ,
& V_2 -> V_7 -> V_81 -> V_9 ) )
F_4 ( V_2 , L_9 , V_2 -> V_7 -> V_81 ) ;
#ifdef F_3
if ( F_2 ( V_2 -> V_7 -> V_49 ) == V_6 &&
F_6 ( V_2 -> V_7 -> V_49 ) == V_12 )
#else
if ( F_2 ( V_2 -> V_7 -> V_49 ) >= V_6 )
#endif
F_4 ( V_2 , L_10 ,
V_2 -> V_7 -> V_49 ) ;
}
void F_76 ( struct V_47 * V_7 )
{
unsigned int V_3 ;
F_60 ( V_7 ) ;
for ( V_3 = 0 ; V_3 < F_55 ( V_7 -> V_8 ) ; V_3 ++ )
F_49 ( ( long ) V_7 -> V_8 [ V_3 ] . V_9 ) ;
}
void F_77 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
T_4 * V_86 = F_78 ( V_87 ) ;
T_4 V_88 ;
#ifdef F_3
T_3 V_89 ;
T_3 * V_54 ;
V_89 = F_69 ( F_37 ( V_86 ) >> V_14 ,
V_90 ) ;
V_54 = F_9 ( F_10 ( V_2 -> V_7 ->
V_8 [ V_2 -> V_17 ] . V_9 [ V_6 ] )
<< V_14 ) ;
F_38 ( & V_54 [ V_12 ] , V_89 ) ;
#else
T_1 V_91 ;
V_91 = F_36 ( F_37 ( V_86 ) | V_92 ) ;
V_2 -> V_7 -> V_8 [ V_2 -> V_17 ] . V_9 [ V_6 ] = V_91 ;
#endif
V_88 = F_24 ( F_37 ( V_2 -> V_93 ) >> V_14 , V_94 ) ;
F_43 ( & V_86 [ F_14 ( ( unsigned long ) V_85 ) ] , V_88 ) ;
}
static void F_79 ( void )
{
unsigned int V_3 ;
F_80 (i)
F_49 ( ( long ) V_86 ( V_3 ) ) ;
}
static T_7 void F_81 ( unsigned int V_2 ,
struct V_11 * V_95 [] ,
unsigned int V_85 )
{
unsigned int V_3 ;
T_4 * V_31 = V_86 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_85 ; V_3 ++ ) {
F_43 ( & V_31 [ V_3 ] , F_82 ( V_95 [ V_3 ] ,
F_25 ( V_13 | V_60 ) ) ) ;
}
V_3 = V_85 + V_2 * 2 ;
F_43 ( & V_31 [ V_3 ] , F_24 ( F_20 ( V_95 [ V_3 ] ) ,
F_25 ( V_13 | V_60 | V_42 ) ) ) ;
F_43 ( & V_31 [ V_3 + 1 ] , F_24 ( F_20 ( V_95 [ V_3 + 1 ] ) ,
F_25 ( V_13 | V_60 ) ) ) ;
}
T_7 int F_83 ( struct V_11 * * V_95 , unsigned int V_85 )
{
unsigned int V_3 ;
F_80 (i) {
V_86 ( V_3 ) = ( T_4 * ) F_34 ( V_41 ) ;
if ( ! V_86 ( V_3 ) ) {
F_79 () ;
return - V_80 ;
}
F_81 ( V_3 , V_95 , V_85 ) ;
}
return 0 ;
}
void F_84 ( void )
{
F_79 () ;
}
