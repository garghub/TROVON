static inline void * F_1 ( void * V_1 )
{
return ( void * ) ( ( unsigned long ) V_1 | V_2 ) ;
}
static inline bool F_2 ( struct V_3 * V_4 , void * V_5 )
{
void * * V_1 = V_5 ;
return ( V_4 -> V_6 <= V_1 ) &&
( V_1 < V_4 -> V_6 + V_7 ) ;
}
static inline bool F_2 ( struct V_3 * V_4 , void * V_5 )
{
return false ;
}
static inline unsigned long F_3 ( struct V_3 * V_4 ,
void * * V_8 )
{
return V_8 - V_4 -> V_6 ;
}
static unsigned int F_4 ( struct V_3 * V_4 ,
struct V_3 * * V_9 , unsigned long V_10 )
{
unsigned int V_11 = ( V_10 >> V_4 -> V_12 ) & V_13 ;
void * * V_14 = F_5 ( V_4 -> V_6 [ V_11 ] ) ;
#ifdef F_6
if ( F_7 ( V_14 ) ) {
if ( F_2 ( V_4 , V_14 ) ) {
void * * V_15 = ( void * * ) F_8 ( V_14 ) ;
V_11 = F_3 ( V_4 , V_15 ) ;
V_14 = F_5 ( * V_15 ) ;
}
}
#endif
* V_9 = ( void * ) V_14 ;
return V_11 ;
}
static inline T_1 F_9 ( struct V_16 * V_17 )
{
return V_17 -> V_18 & V_19 ;
}
static inline void F_10 ( struct V_3 * V_5 , unsigned int V_20 ,
int V_11 )
{
F_11 ( V_11 , V_5 -> V_21 [ V_20 ] ) ;
}
static inline void F_12 ( struct V_3 * V_5 , unsigned int V_20 ,
int V_11 )
{
F_13 ( V_11 , V_5 -> V_21 [ V_20 ] ) ;
}
static inline int F_14 ( struct V_3 * V_5 , unsigned int V_20 ,
int V_11 )
{
return F_15 ( V_11 , V_5 -> V_21 [ V_20 ] ) ;
}
static inline void F_16 ( struct V_16 * V_17 , unsigned int V_20 )
{
V_17 -> V_18 |= ( V_22 T_1 ) ( 1 << ( V_20 + V_23 ) ) ;
}
static inline void F_17 ( struct V_16 * V_17 , unsigned V_20 )
{
V_17 -> V_18 &= ( V_22 T_1 ) ~ ( 1 << ( V_20 + V_23 ) ) ;
}
static inline void F_18 ( struct V_16 * V_17 )
{
V_17 -> V_18 &= V_19 ;
}
static inline int F_19 ( struct V_16 * V_17 , unsigned int V_20 )
{
return ( V_22 int ) V_17 -> V_18 & ( 1 << ( V_20 + V_23 ) ) ;
}
static inline unsigned F_20 ( struct V_16 * V_17 )
{
return ( V_22 unsigned ) V_17 -> V_18 >> V_23 ;
}
static inline int F_21 ( struct V_3 * V_5 , unsigned int V_20 )
{
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( V_5 -> V_21 [ V_20 ] [ V_24 ] )
return 1 ;
}
return 0 ;
}
static T_2 unsigned long
F_22 ( const unsigned long * V_26 ,
unsigned long V_27 , unsigned long V_11 )
{
if ( ! F_23 ( V_27 ) )
return F_24 ( V_26 , V_27 , V_11 ) ;
if ( V_11 < V_27 ) {
unsigned long V_28 ;
V_26 += V_11 / V_29 ;
V_28 = * V_26 >> ( V_11 % V_29 ) ;
if ( V_28 )
return F_25 ( V_28 ) + V_11 ;
V_11 = ( V_11 + V_29 ) & ~ ( V_29 - 1 ) ;
while ( V_11 < V_27 ) {
V_28 = * ++ V_26 ;
if ( V_28 )
return F_25 ( V_28 ) + V_11 ;
V_11 += V_29 ;
}
}
return V_27 ;
}
static void F_26 ( struct V_3 * V_5 , unsigned long V_10 )
{
unsigned long V_30 ;
F_27 ( L_1 ,
V_5 , V_5 -> V_11 ,
V_5 -> V_21 [ 0 ] [ 0 ] , V_5 -> V_21 [ 1 ] [ 0 ] , V_5 -> V_21 [ 2 ] [ 0 ] ,
V_5 -> V_12 , V_5 -> V_31 , V_5 -> V_4 ) ;
for ( V_30 = 0 ; V_30 < V_7 ; V_30 ++ ) {
unsigned long V_32 = V_10 | ( V_30 << V_5 -> V_12 ) ;
unsigned long V_33 = V_32 | ( ( 1UL << V_5 -> V_12 ) - 1 ) ;
void * V_14 = V_5 -> V_6 [ V_30 ] ;
if ( ! V_14 )
continue;
if ( F_2 ( V_5 , V_14 ) ) {
F_27 ( L_2 ,
V_14 , V_30 ,
* ( void * * ) F_8 ( V_14 ) ,
V_32 , V_33 ) ;
} else if ( ! F_7 ( V_14 ) ) {
F_27 ( L_3 ,
V_14 , V_30 , V_32 , V_33 ) ;
} else {
F_26 ( F_8 ( V_14 ) , V_32 ) ;
}
}
}
static void F_28 ( struct V_16 * V_17 )
{
F_27 ( L_4 ,
V_17 , V_17 -> V_34 ,
V_17 -> V_18 >> V_23 ) ;
if ( ! F_7 ( V_17 -> V_34 ) )
return;
F_26 ( F_8 ( V_17 -> V_34 ) , 0 ) ;
}
static struct V_3 *
F_29 ( struct V_16 * V_17 )
{
struct V_3 * V_35 = NULL ;
T_1 V_18 = F_9 ( V_17 ) ;
if ( ! F_30 ( V_18 ) && ! F_31 () ) {
struct V_36 * V_37 ;
V_35 = F_32 ( V_38 ,
V_18 | V_39 ) ;
if ( V_35 )
goto V_40;
V_37 = F_33 ( & V_41 ) ;
if ( V_37 -> V_42 ) {
V_35 = V_37 -> V_43 ;
V_37 -> V_43 = V_35 -> V_44 ;
V_35 -> V_44 = NULL ;
V_37 -> V_42 -- ;
}
F_34 ( V_35 ) ;
goto V_40;
}
V_35 = F_32 ( V_38 , V_18 ) ;
V_40:
F_35 ( F_7 ( V_35 ) ) ;
return V_35 ;
}
static void F_36 ( struct V_45 * V_46 )
{
struct V_3 * V_5 =
F_37 ( V_46 , struct V_3 , V_45 ) ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_47 ; V_30 ++ )
F_12 ( V_5 , V_30 , 0 ) ;
V_5 -> V_6 [ 0 ] = NULL ;
V_5 -> V_31 = 0 ;
F_38 ( V_38 , V_5 ) ;
}
static inline void
F_39 ( struct V_3 * V_5 )
{
F_40 ( & V_5 -> V_45 , F_36 ) ;
}
static int F_41 ( T_1 V_18 , int V_42 )
{
struct V_36 * V_37 ;
struct V_3 * V_5 ;
int V_35 = - V_48 ;
V_18 &= ~ V_49 ;
F_42 () ;
V_37 = F_33 ( & V_41 ) ;
while ( V_37 -> V_42 < V_42 ) {
F_43 () ;
V_5 = F_32 ( V_38 , V_18 ) ;
if ( V_5 == NULL )
goto V_40;
F_42 () ;
V_37 = F_33 ( & V_41 ) ;
if ( V_37 -> V_42 < V_42 ) {
V_5 -> V_44 = V_37 -> V_43 ;
V_37 -> V_43 = V_5 ;
V_37 -> V_42 ++ ;
} else {
F_38 ( V_38 , V_5 ) ;
}
}
V_35 = 0 ;
V_40:
return V_35 ;
}
int V_36 ( T_1 V_18 )
{
F_44 ( ! F_30 ( V_18 ) ) ;
return F_41 ( V_18 , V_50 ) ;
}
int F_45 ( T_1 V_18 )
{
if ( F_30 ( V_18 ) )
return F_41 ( V_18 , V_50 ) ;
F_42 () ;
return 0 ;
}
int F_46 ( T_1 V_18 , int V_51 )
{
unsigned long V_52 ;
int V_53 , V_54 ;
if ( ! F_30 ( V_18 ) ) {
F_42 () ;
return 0 ;
}
V_52 = 1 << V_51 ;
for ( V_54 = 0 ; V_52 > V_7 ;
V_54 ++ )
V_52 >>= V_55 ;
V_53 = V_56 ;
V_53 += V_56 - V_54 ;
V_53 -- ;
V_53 += V_52 * V_57 [ V_54 ] ;
return F_41 ( V_18 , V_53 ) ;
}
static inline unsigned long F_47 ( unsigned int V_12 )
{
return ( V_7 << V_12 ) - 1 ;
}
static inline unsigned long F_48 ( struct V_3 * V_5 )
{
return F_47 ( V_5 -> V_12 ) ;
}
static unsigned F_49 ( struct V_16 * V_17 ,
struct V_3 * * V_9 , unsigned long * V_58 )
{
struct V_3 * V_5 = F_5 ( V_17 -> V_34 ) ;
* V_9 = V_5 ;
if ( F_50 ( F_7 ( V_5 ) ) ) {
V_5 = F_8 ( V_5 ) ;
* V_58 = F_48 ( V_5 ) ;
return V_5 -> V_12 + V_55 ;
}
* V_58 = 0 ;
return 0 ;
}
static int F_51 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_12 )
{
struct V_3 * V_8 ;
unsigned int V_59 ;
int V_20 ;
V_59 = V_12 ;
while ( V_10 > F_47 ( V_59 ) )
V_59 += V_55 ;
V_8 = V_17 -> V_34 ;
if ( ! V_8 )
goto V_40;
do {
struct V_3 * V_5 = F_29 ( V_17 ) ;
if ( ! V_5 )
return - V_48 ;
for ( V_20 = 0 ; V_20 < V_47 ; V_20 ++ ) {
if ( F_19 ( V_17 , V_20 ) )
F_10 ( V_5 , V_20 , 0 ) ;
}
F_35 ( V_12 > V_29 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_11 = 0 ;
V_5 -> V_31 = 1 ;
V_5 -> V_4 = NULL ;
if ( F_7 ( V_8 ) )
F_8 ( V_8 ) -> V_4 = V_5 ;
V_5 -> V_6 [ 0 ] = V_8 ;
V_8 = F_1 ( V_5 ) ;
F_52 ( V_17 -> V_34 , V_8 ) ;
V_12 += V_55 ;
} while ( V_12 <= V_59 );
V_40:
return V_59 + V_55 ;
}
int F_53 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_51 , struct V_3 * * V_9 ,
void * * * V_60 )
{
struct V_3 * V_5 = NULL , * V_61 ;
void * * V_8 = ( void * * ) & V_17 -> V_34 ;
unsigned long V_58 ;
unsigned int V_12 , V_11 = 0 ;
unsigned long V_62 = V_10 | ( ( 1UL << V_51 ) - 1 ) ;
V_12 = F_49 ( V_17 , & V_61 , & V_58 ) ;
if ( V_62 > V_58 ) {
int error = F_51 ( V_17 , V_62 , V_12 ) ;
if ( error < 0 )
return error ;
V_12 = error ;
V_61 = V_17 -> V_34 ;
if ( V_51 == V_12 )
V_12 += V_55 ;
}
while ( V_12 > V_51 ) {
V_12 -= V_55 ;
if ( V_61 == NULL ) {
V_61 = F_29 ( V_17 ) ;
if ( ! V_61 )
return - V_48 ;
V_61 -> V_12 = V_12 ;
V_61 -> V_11 = V_11 ;
V_61 -> V_4 = V_5 ;
F_52 ( * V_8 , F_1 ( V_61 ) ) ;
if ( V_5 )
V_5 -> V_31 ++ ;
} else if ( ! F_7 ( V_61 ) )
break;
V_5 = F_8 ( V_61 ) ;
V_11 = F_4 ( V_5 , & V_61 , V_10 ) ;
V_8 = & V_5 -> V_6 [ V_11 ] ;
}
#ifdef F_6
if ( V_51 > V_12 ) {
unsigned V_30 , V_63 = 1 << ( V_51 - V_12 ) ;
V_11 = V_11 & ~ ( V_63 - 1 ) ;
V_8 = & V_5 -> V_6 [ V_11 ] ;
V_61 = F_1 ( V_8 ) ;
for ( V_30 = 0 ; V_30 < V_63 ; V_30 ++ ) {
if ( V_8 [ V_30 ] )
return - V_64 ;
}
for ( V_30 = 1 ; V_30 < V_63 ; V_30 ++ ) {
F_52 ( V_8 [ V_30 ] , V_61 ) ;
V_5 -> V_31 ++ ;
}
}
#endif
if ( V_9 )
* V_9 = V_5 ;
if ( V_60 )
* V_60 = V_8 ;
return 0 ;
}
int F_54 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_51 , void * V_65 )
{
struct V_3 * V_5 ;
void * * V_8 ;
int error ;
F_35 ( F_7 ( V_65 ) ) ;
error = F_53 ( V_17 , V_10 , V_51 , & V_5 , & V_8 ) ;
if ( error )
return error ;
if ( * V_8 != NULL )
return - V_64 ;
F_52 ( * V_8 , V_65 ) ;
if ( V_5 ) {
unsigned V_11 = F_3 ( V_5 , V_8 ) ;
V_5 -> V_31 ++ ;
F_35 ( F_14 ( V_5 , 0 , V_11 ) ) ;
F_35 ( F_14 ( V_5 , 1 , V_11 ) ) ;
F_35 ( F_14 ( V_5 , 2 , V_11 ) ) ;
} else {
F_35 ( F_20 ( V_17 ) ) ;
}
return 0 ;
}
void * F_55 ( struct V_16 * V_17 , unsigned long V_10 ,
struct V_3 * * V_9 , void * * * V_60 )
{
struct V_3 * V_5 , * V_4 ;
unsigned long V_58 ;
void * * V_8 ;
V_66:
V_4 = NULL ;
V_8 = ( void * * ) & V_17 -> V_34 ;
F_49 ( V_17 , & V_5 , & V_58 ) ;
if ( V_10 > V_58 )
return NULL ;
while ( F_7 ( V_5 ) ) {
unsigned V_11 ;
if ( V_5 == V_67 )
goto V_66;
V_4 = F_8 ( V_5 ) ;
V_11 = F_4 ( V_4 , & V_5 , V_10 ) ;
V_8 = V_4 -> V_6 + V_11 ;
}
if ( V_9 )
* V_9 = V_4 ;
if ( V_60 )
* V_60 = V_8 ;
return V_5 ;
}
void * * F_56 ( struct V_16 * V_17 , unsigned long V_10 )
{
void * * V_8 ;
if ( ! F_55 ( V_17 , V_10 , NULL , & V_8 ) )
return NULL ;
return V_8 ;
}
void * F_57 ( struct V_16 * V_17 , unsigned long V_10 )
{
return F_55 ( V_17 , V_10 , NULL , NULL ) ;
}
void * F_58 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_3 * V_5 , * V_4 ;
unsigned long V_58 ;
F_49 ( V_17 , & V_5 , & V_58 ) ;
F_35 ( V_10 > V_58 ) ;
while ( F_7 ( V_5 ) ) {
unsigned V_11 ;
V_4 = F_8 ( V_5 ) ;
V_11 = F_4 ( V_4 , & V_5 , V_10 ) ;
F_35 ( ! V_5 ) ;
if ( ! F_14 ( V_4 , V_20 , V_11 ) )
F_10 ( V_4 , V_20 , V_11 ) ;
}
if ( ! F_19 ( V_17 , V_20 ) )
F_16 ( V_17 , V_20 ) ;
return V_5 ;
}
static void F_59 ( struct V_16 * V_17 ,
struct V_3 * V_5 ,
unsigned int V_20 , unsigned int V_11 )
{
while ( V_5 ) {
if ( ! F_14 ( V_5 , V_20 , V_11 ) )
return;
F_12 ( V_5 , V_20 , V_11 ) ;
if ( F_21 ( V_5 , V_20 ) )
return;
V_11 = V_5 -> V_11 ;
V_5 = V_5 -> V_4 ;
}
if ( F_19 ( V_17 , V_20 ) )
F_17 ( V_17 , V_20 ) ;
}
void * F_60 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_3 * V_5 , * V_4 ;
unsigned long V_58 ;
int V_68 ( V_11 ) ;
F_49 ( V_17 , & V_5 , & V_58 ) ;
if ( V_10 > V_58 )
return NULL ;
V_4 = NULL ;
while ( F_7 ( V_5 ) ) {
V_4 = F_8 ( V_5 ) ;
V_11 = F_4 ( V_4 , & V_5 , V_10 ) ;
}
if ( V_5 )
F_59 ( V_17 , V_4 , V_20 , V_11 ) ;
return V_5 ;
}
int F_61 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_3 * V_5 , * V_4 ;
unsigned long V_58 ;
if ( ! F_19 ( V_17 , V_20 ) )
return 0 ;
F_49 ( V_17 , & V_5 , & V_58 ) ;
if ( V_10 > V_58 )
return 0 ;
if ( V_5 == NULL )
return 0 ;
while ( F_7 ( V_5 ) ) {
unsigned V_11 ;
V_4 = F_8 ( V_5 ) ;
V_11 = F_4 ( V_4 , & V_5 , V_10 ) ;
if ( ! V_5 )
return 0 ;
if ( ! F_14 ( V_4 , V_20 , V_11 ) )
return 0 ;
if ( V_5 == V_67 )
break;
}
return 1 ;
}
static inline void F_62 ( struct V_69 * V_70 ,
unsigned int V_12 )
{
#ifdef F_6
V_70 -> V_12 = V_12 ;
#endif
}
void * * F_63 ( struct V_16 * V_17 ,
struct V_69 * V_70 , unsigned V_71 )
{
unsigned V_20 = V_71 & V_72 ;
struct V_3 * V_5 , * V_61 ;
unsigned long V_10 , V_11 , V_58 ;
if ( ( V_71 & V_73 ) && ! F_19 ( V_17 , V_20 ) )
return NULL ;
V_10 = V_70 -> V_74 ;
if ( ! V_10 && V_70 -> V_10 )
return NULL ;
V_66:
F_49 ( V_17 , & V_61 , & V_58 ) ;
if ( V_10 > V_58 )
return NULL ;
if ( ! V_61 )
return NULL ;
if ( ! F_7 ( V_61 ) ) {
V_70 -> V_10 = V_10 ;
V_70 -> V_74 = V_58 + 1 ;
V_70 -> V_21 = 1 ;
F_62 ( V_70 , 0 ) ;
return ( void * * ) & V_17 -> V_34 ;
}
do {
V_5 = F_8 ( V_61 ) ;
V_11 = F_4 ( V_5 , & V_61 , V_10 ) ;
if ( ( V_71 & V_73 ) ?
! F_14 ( V_5 , V_20 , V_11 ) : ! V_61 ) {
if ( V_71 & V_75 )
return NULL ;
if ( V_71 & V_73 )
V_11 = F_22 (
V_5 -> V_21 [ V_20 ] ,
V_7 ,
V_11 + 1 ) ;
else
while ( ++ V_11 < V_7 ) {
void * V_8 = V_5 -> V_6 [ V_11 ] ;
if ( F_2 ( V_5 , V_8 ) )
continue;
if ( V_8 )
break;
}
V_10 &= ~ F_48 ( V_5 ) ;
V_10 += V_11 << V_5 -> V_12 ;
if ( ! V_10 )
return NULL ;
if ( V_11 == V_7 )
goto V_66;
V_61 = F_5 ( V_5 -> V_6 [ V_11 ] ) ;
}
if ( ( V_61 == NULL ) || ( V_61 == V_67 ) )
goto V_66;
} while ( F_7 ( V_61 ) );
V_70 -> V_10 = ( V_10 & ~ F_48 ( V_5 ) ) | ( V_11 << V_5 -> V_12 ) ;
V_70 -> V_74 = ( V_10 | F_48 ( V_5 ) ) + 1 ;
F_62 ( V_70 , V_5 -> V_12 ) ;
if ( V_71 & V_73 ) {
unsigned V_76 , V_77 ;
V_76 = V_11 / V_29 ;
V_77 = V_11 % V_29 ;
V_70 -> V_21 = V_5 -> V_21 [ V_20 ] [ V_76 ] >> V_77 ;
if ( V_76 < V_25 - 1 ) {
if ( V_77 )
V_70 -> V_21 |= V_5 -> V_21 [ V_20 ] [ V_76 + 1 ] <<
( V_29 - V_77 ) ;
V_70 -> V_74 = V_10 + V_29 ;
}
}
return V_5 -> V_6 + V_11 ;
}
unsigned long F_64 ( struct V_16 * V_17 ,
unsigned long * V_78 , unsigned long V_79 ,
unsigned long V_80 ,
unsigned int V_81 , unsigned int V_82 )
{
struct V_3 * V_4 , * V_5 , * V_61 ;
unsigned long V_58 ;
unsigned long V_83 = 0 ;
unsigned long V_10 = * V_78 ;
F_49 ( V_17 , & V_61 , & V_58 ) ;
V_79 = F_65 ( V_79 , V_58 ) ;
if ( V_10 > V_79 )
return 0 ;
if ( ! V_80 )
return 0 ;
if ( ! F_19 ( V_17 , V_81 ) ) {
* V_78 = V_79 + 1 ;
return 0 ;
}
if ( ! F_7 ( V_61 ) ) {
* V_78 = V_79 + 1 ;
F_16 ( V_17 , V_82 ) ;
return 1 ;
}
V_5 = F_8 ( V_61 ) ;
for (; ; ) {
unsigned V_11 = F_4 ( V_5 , & V_61 , V_10 ) ;
if ( ! V_61 )
goto V_84;
if ( ! F_14 ( V_5 , V_81 , V_11 ) )
goto V_84;
if ( F_7 ( V_61 ) ) {
V_5 = F_8 ( V_61 ) ;
continue;
}
V_83 ++ ;
F_10 ( V_5 , V_82 , V_11 ) ;
V_4 = V_5 ;
for (; ; ) {
V_11 = V_4 -> V_11 ;
V_4 = V_4 -> V_4 ;
if ( ! V_4 )
break;
if ( F_14 ( V_4 , V_82 , V_11 ) )
break;
F_10 ( V_4 , V_82 , V_11 ) ;
}
V_84:
V_10 = ( ( V_10 >> V_5 -> V_12 ) + 1 ) << V_5 -> V_12 ;
if ( V_10 > V_79 || ! V_10 )
break;
V_11 = ( V_10 >> V_5 -> V_12 ) & V_13 ;
while ( V_11 == 0 ) {
V_5 = V_5 -> V_4 ;
V_11 = ( V_10 >> V_5 -> V_12 ) & V_13 ;
}
if ( F_2 ( V_5 , V_5 -> V_6 [ V_11 ] ) )
goto V_84;
if ( V_83 >= V_80 )
break;
}
if ( V_83 > 0 )
F_16 ( V_17 , V_82 ) ;
* V_78 = V_10 ;
return V_83 ;
}
unsigned int
F_66 ( struct V_16 * V_17 , void * * V_85 ,
unsigned long V_86 , unsigned int V_87 )
{
struct V_69 V_70 ;
void * * V_8 ;
unsigned int V_35 = 0 ;
if ( F_67 ( ! V_87 ) )
return 0 ;
F_68 (slot, root, &iter, first_index) {
V_85 [ V_35 ] = F_5 ( * V_8 ) ;
if ( ! V_85 [ V_35 ] )
continue;
if ( F_7 ( V_85 [ V_35 ] ) ) {
V_8 = F_69 ( & V_70 ) ;
continue;
}
if ( ++ V_35 == V_87 )
break;
}
return V_35 ;
}
unsigned int
F_70 ( struct V_16 * V_17 ,
void * * * V_85 , unsigned long * V_88 ,
unsigned long V_86 , unsigned int V_87 )
{
struct V_69 V_70 ;
void * * V_8 ;
unsigned int V_35 = 0 ;
if ( F_67 ( ! V_87 ) )
return 0 ;
F_68 (slot, root, &iter, first_index) {
V_85 [ V_35 ] = V_8 ;
if ( V_88 )
V_88 [ V_35 ] = V_70 . V_10 ;
if ( ++ V_35 == V_87 )
break;
}
return V_35 ;
}
unsigned int
F_71 ( struct V_16 * V_17 , void * * V_85 ,
unsigned long V_86 , unsigned int V_87 ,
unsigned int V_20 )
{
struct V_69 V_70 ;
void * * V_8 ;
unsigned int V_35 = 0 ;
if ( F_67 ( ! V_87 ) )
return 0 ;
F_72 (slot, root, &iter, first_index, tag) {
V_85 [ V_35 ] = F_5 ( * V_8 ) ;
if ( ! V_85 [ V_35 ] )
continue;
if ( F_7 ( V_85 [ V_35 ] ) ) {
V_8 = F_69 ( & V_70 ) ;
continue;
}
if ( ++ V_35 == V_87 )
break;
}
return V_35 ;
}
unsigned int
F_73 ( struct V_16 * V_17 , void * * * V_85 ,
unsigned long V_86 , unsigned int V_87 ,
unsigned int V_20 )
{
struct V_69 V_70 ;
void * * V_8 ;
unsigned int V_35 = 0 ;
if ( F_67 ( ! V_87 ) )
return 0 ;
F_72 (slot, root, &iter, first_index, tag) {
V_85 [ V_35 ] = V_8 ;
if ( ++ V_35 == V_87 )
break;
}
return V_35 ;
}
static unsigned long F_74 ( struct V_3 * V_8 , void * V_65 ,
unsigned long V_10 , struct V_89 * V_90 )
{
unsigned long V_30 ;
do {
unsigned int V_12 = V_8 -> V_12 ;
for ( V_30 = ( V_10 >> V_12 ) & V_13 ;
V_30 < V_7 ;
V_30 ++ , V_10 += ( 1UL << V_12 ) ) {
struct V_3 * V_5 =
F_5 ( V_8 -> V_6 [ V_30 ] ) ;
if ( V_5 == V_67 )
goto V_40;
if ( ! F_7 ( V_5 ) ) {
if ( V_5 == V_65 ) {
V_90 -> V_91 = V_10 ;
V_90 -> V_92 = true ;
goto V_40;
}
continue;
}
V_5 = F_8 ( V_5 ) ;
if ( F_2 ( V_8 , V_5 ) )
continue;
V_8 = V_5 ;
break;
}
} while ( V_30 < V_7 );
V_40:
if ( ( V_10 == 0 ) && ( V_30 == V_7 ) )
V_90 -> V_92 = true ;
return V_10 ;
}
unsigned long F_75 ( struct V_16 * V_17 , void * V_65 )
{
struct V_3 * V_5 ;
unsigned long V_93 ;
unsigned long V_94 = 0 ;
struct V_89 V_90 = {
. V_91 = - 1 ,
. V_92 = false ,
} ;
do {
F_76 () ;
V_5 = F_5 ( V_17 -> V_34 ) ;
if ( ! F_7 ( V_5 ) ) {
F_77 () ;
if ( V_5 == V_65 )
V_90 . V_91 = 0 ;
break;
}
V_5 = F_8 ( V_5 ) ;
V_93 = F_48 ( V_5 ) ;
if ( V_94 > V_93 ) {
F_77 () ;
break;
}
V_94 = F_74 ( V_5 , V_65 , V_94 , & V_90 ) ;
F_77 () ;
F_78 () ;
} while ( ! V_90 . V_92 && V_94 <= V_93 );
return V_90 . V_91 ;
}
unsigned long F_75 ( struct V_16 * V_17 , void * V_65 )
{
return - 1 ;
}
static inline bool F_79 ( struct V_16 * V_17 )
{
bool V_95 = false ;
for (; ; ) {
struct V_3 * V_5 = V_17 -> V_34 ;
struct V_3 * V_61 ;
if ( ! F_7 ( V_5 ) )
break;
V_5 = F_8 ( V_5 ) ;
if ( V_5 -> V_31 != 1 )
break;
V_61 = V_5 -> V_6 [ 0 ] ;
if ( ! V_61 )
break;
if ( ! F_7 ( V_61 ) && V_5 -> V_12 )
break;
if ( F_7 ( V_61 ) )
F_8 ( V_61 ) -> V_4 = NULL ;
V_17 -> V_34 = V_61 ;
if ( ! F_7 ( V_61 ) )
V_5 -> V_6 [ 0 ] = V_67 ;
F_39 ( V_5 ) ;
V_95 = true ;
}
return V_95 ;
}
bool F_80 ( struct V_16 * V_17 ,
struct V_3 * V_5 )
{
bool V_96 = false ;
do {
struct V_3 * V_4 ;
if ( V_5 -> V_31 ) {
if ( V_5 == F_8 ( V_17 -> V_34 ) )
V_96 |= F_79 ( V_17 ) ;
return V_96 ;
}
V_4 = V_5 -> V_4 ;
if ( V_4 ) {
V_4 -> V_6 [ V_5 -> V_11 ] = NULL ;
V_4 -> V_31 -- ;
} else {
F_18 ( V_17 ) ;
V_17 -> V_34 = NULL ;
}
F_39 ( V_5 ) ;
V_96 = true ;
V_5 = V_4 ;
} while ( V_5 );
return V_96 ;
}
static inline void F_81 ( struct V_3 * V_5 ,
void * V_1 , unsigned V_11 )
{
#ifdef F_6
int V_30 ;
for ( V_30 = 1 ; V_11 + V_30 < V_7 ; V_30 ++ ) {
if ( V_5 -> V_6 [ V_11 + V_30 ] != V_1 )
break;
V_5 -> V_6 [ V_11 + V_30 ] = NULL ;
V_5 -> V_31 -- ;
}
#endif
}
void * F_82 ( struct V_16 * V_17 ,
unsigned long V_10 , void * V_65 )
{
struct V_3 * V_5 ;
unsigned int V_11 ;
void * * V_8 ;
void * V_14 ;
int V_20 ;
V_14 = F_55 ( V_17 , V_10 , & V_5 , & V_8 ) ;
if ( ! V_14 )
return NULL ;
if ( V_65 && V_14 != V_65 )
return NULL ;
if ( ! V_5 ) {
F_18 ( V_17 ) ;
V_17 -> V_34 = NULL ;
return V_14 ;
}
V_11 = F_3 ( V_5 , V_8 ) ;
for ( V_20 = 0 ; V_20 < V_47 ; V_20 ++ )
F_59 ( V_17 , V_5 , V_20 , V_11 ) ;
F_81 ( V_5 , F_1 ( V_8 ) , V_11 ) ;
V_5 -> V_6 [ V_11 ] = NULL ;
V_5 -> V_31 -- ;
F_80 ( V_17 , V_5 ) ;
return V_14 ;
}
void * F_83 ( struct V_16 * V_17 , unsigned long V_10 )
{
return F_82 ( V_17 , V_10 , NULL ) ;
}
void F_84 ( struct V_16 * V_17 ,
struct V_3 * V_5 ,
void * * V_8 )
{
if ( V_5 ) {
unsigned int V_20 , V_11 = F_3 ( V_5 , V_8 ) ;
for ( V_20 = 0 ; V_20 < V_47 ; V_20 ++ )
F_59 ( V_17 , V_5 , V_20 , V_11 ) ;
} else {
V_17 -> V_18 &= V_19 ;
}
}
int F_85 ( struct V_16 * V_17 , unsigned int V_20 )
{
return F_19 ( V_17 , V_20 ) ;
}
static void
F_86 ( void * V_97 )
{
struct V_3 * V_5 = V_97 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_87 ( & V_5 -> V_98 ) ;
}
static T_3 unsigned long F_88 ( unsigned int V_99 )
{
unsigned int V_100 = V_99 * V_55 ;
int V_12 = V_101 - V_100 ;
if ( V_12 < 0 )
return ~ 0UL ;
if ( V_12 >= V_29 )
return 0UL ;
return ~ 0UL >> V_12 ;
}
static T_3 void F_89 ( void )
{
unsigned long V_102 [ V_56 + 1 ] ;
unsigned int V_30 , V_103 ;
for ( V_30 = 0 ; V_30 < F_90 ( V_102 ) ; V_30 ++ )
V_102 [ V_30 ] = F_88 ( V_30 ) ;
for ( V_30 = 0 ; V_30 < F_90 ( V_57 ) ; V_30 ++ ) {
for ( V_103 = V_30 ; V_103 > 0 ; V_103 -- )
V_57 [ V_30 ] += V_102 [ V_103 - 1 ] + 1 ;
}
}
static int F_91 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_107 )
{
int V_108 = ( long ) V_107 ;
struct V_36 * V_37 ;
struct V_3 * V_5 ;
if ( V_106 == V_109 || V_106 == V_110 ) {
V_37 = & F_92 ( V_41 , V_108 ) ;
while ( V_37 -> V_42 ) {
V_5 = V_37 -> V_43 ;
V_37 -> V_43 = V_5 -> V_44 ;
F_38 ( V_38 , V_5 ) ;
V_37 -> V_42 -- ;
}
}
return V_111 ;
}
void T_3 F_93 ( void )
{
V_38 = F_94 ( L_5 ,
sizeof( struct V_3 ) , 0 ,
V_112 | V_113 ,
F_86 ) ;
F_89 () ;
F_95 ( F_91 , 0 ) ;
}
