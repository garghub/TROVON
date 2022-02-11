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
unsigned long V_15 = F_3 ( V_4 , V_14 ) ;
if ( V_15 < V_7 ) {
V_11 = V_15 ;
V_14 = F_5 ( V_4 -> V_6 [ V_11 ] ) ;
}
}
#endif
* V_9 = ( void * ) V_14 ;
return V_11 ;
}
static inline T_1 F_8 ( struct V_16 * V_17 )
{
return V_17 -> V_18 & V_19 ;
}
static inline void F_9 ( struct V_3 * V_5 , unsigned int V_20 ,
int V_11 )
{
F_10 ( V_11 , V_5 -> V_21 [ V_20 ] ) ;
}
static inline void F_11 ( struct V_3 * V_5 , unsigned int V_20 ,
int V_11 )
{
F_12 ( V_11 , V_5 -> V_21 [ V_20 ] ) ;
}
static inline int F_13 ( struct V_3 * V_5 , unsigned int V_20 ,
int V_11 )
{
return F_14 ( V_11 , V_5 -> V_21 [ V_20 ] ) ;
}
static inline void F_15 ( struct V_16 * V_17 , unsigned int V_20 )
{
V_17 -> V_18 |= ( V_22 T_1 ) ( 1 << ( V_20 + V_23 ) ) ;
}
static inline void F_16 ( struct V_16 * V_17 , unsigned V_20 )
{
V_17 -> V_18 &= ( V_22 T_1 ) ~ ( 1 << ( V_20 + V_23 ) ) ;
}
static inline void F_17 ( struct V_16 * V_17 )
{
V_17 -> V_18 &= V_19 ;
}
static inline int F_18 ( struct V_16 * V_17 , unsigned int V_20 )
{
return ( V_22 int ) V_17 -> V_18 & ( 1 << ( V_20 + V_23 ) ) ;
}
static inline unsigned F_19 ( struct V_16 * V_17 )
{
return ( V_22 unsigned ) V_17 -> V_18 >> V_23 ;
}
static inline int F_20 ( struct V_3 * V_5 , unsigned int V_20 )
{
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( V_5 -> V_21 [ V_20 ] [ V_24 ] )
return 1 ;
}
return 0 ;
}
static T_2 unsigned long
F_21 ( const unsigned long * V_26 ,
unsigned long V_27 , unsigned long V_11 )
{
if ( ! F_22 ( V_27 ) )
return F_23 ( V_26 , V_27 , V_11 ) ;
if ( V_11 < V_27 ) {
unsigned long V_28 ;
V_26 += V_11 / V_29 ;
V_28 = * V_26 >> ( V_11 % V_29 ) ;
if ( V_28 )
return F_24 ( V_28 ) + V_11 ;
V_11 = ( V_11 + V_29 ) & ~ ( V_29 - 1 ) ;
while ( V_11 < V_27 ) {
V_28 = * ++ V_26 ;
if ( V_28 )
return F_24 ( V_28 ) + V_11 ;
V_11 += V_29 ;
}
}
return V_27 ;
}
static void F_25 ( struct V_3 * V_5 , unsigned long V_10 )
{
unsigned long V_30 ;
F_26 ( L_1 ,
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
F_26 ( L_2 ,
V_14 , V_30 ,
* ( void * * ) F_27 ( V_14 ) ,
V_32 , V_33 ) ;
} else if ( ! F_7 ( V_14 ) ) {
F_26 ( L_3 ,
V_14 , V_30 , V_32 , V_33 ) ;
} else {
F_25 ( F_27 ( V_14 ) , V_32 ) ;
}
}
}
static void F_28 ( struct V_16 * V_17 )
{
F_26 ( L_4 ,
V_17 , V_17 -> V_34 ,
V_17 -> V_18 >> V_23 ) ;
if ( ! F_7 ( V_17 -> V_34 ) )
return;
F_25 ( F_27 ( V_17 -> V_34 ) , 0 ) ;
}
static struct V_3 *
F_29 ( struct V_16 * V_17 )
{
struct V_3 * V_35 = NULL ;
T_1 V_18 = F_8 ( V_17 ) ;
if ( ! F_30 ( V_18 ) && ! F_31 () ) {
struct V_36 * V_37 ;
V_35 = F_32 ( V_38 ,
V_18 | V_39 | V_40 ) ;
if ( V_35 )
goto V_41;
V_37 = F_33 ( & V_42 ) ;
if ( V_37 -> V_43 ) {
V_35 = V_37 -> V_44 ;
V_37 -> V_44 = V_35 -> V_45 ;
V_35 -> V_45 = NULL ;
V_37 -> V_43 -- ;
}
F_34 ( V_35 ) ;
goto V_41;
}
V_35 = F_32 ( V_38 ,
V_18 | V_39 ) ;
V_41:
F_35 ( F_7 ( V_35 ) ) ;
return V_35 ;
}
static void F_36 ( struct V_46 * V_47 )
{
struct V_3 * V_5 =
F_37 ( V_47 , struct V_3 , V_46 ) ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_48 ; V_30 ++ )
F_11 ( V_5 , V_30 , 0 ) ;
V_5 -> V_6 [ 0 ] = NULL ;
V_5 -> V_31 = 0 ;
F_38 ( V_38 , V_5 ) ;
}
static inline void
F_39 ( struct V_3 * V_5 )
{
F_40 ( & V_5 -> V_46 , F_36 ) ;
}
static int F_41 ( T_1 V_18 )
{
struct V_36 * V_37 ;
struct V_3 * V_5 ;
int V_35 = - V_49 ;
F_42 () ;
V_37 = F_33 ( & V_42 ) ;
while ( V_37 -> V_43 < V_50 ) {
F_43 () ;
V_5 = F_32 ( V_38 , V_18 ) ;
if ( V_5 == NULL )
goto V_41;
F_42 () ;
V_37 = F_33 ( & V_42 ) ;
if ( V_37 -> V_43 < V_50 ) {
V_5 -> V_45 = V_37 -> V_44 ;
V_37 -> V_44 = V_5 ;
V_37 -> V_43 ++ ;
} else {
F_38 ( V_38 , V_5 ) ;
}
}
V_35 = 0 ;
V_41:
return V_35 ;
}
int V_36 ( T_1 V_18 )
{
F_44 ( ! F_30 ( V_18 ) ) ;
return F_41 ( V_18 ) ;
}
int F_45 ( T_1 V_18 )
{
if ( F_30 ( V_18 ) )
return F_41 ( V_18 ) ;
F_42 () ;
return 0 ;
}
static inline unsigned long F_46 ( unsigned int V_12 )
{
return ( V_7 << V_12 ) - 1 ;
}
static inline unsigned long F_47 ( struct V_3 * V_5 )
{
return F_46 ( V_5 -> V_12 ) ;
}
static unsigned F_48 ( struct V_16 * V_17 ,
struct V_3 * * V_9 , unsigned long * V_51 )
{
struct V_3 * V_5 = F_5 ( V_17 -> V_34 ) ;
* V_9 = V_5 ;
if ( F_49 ( F_7 ( V_5 ) ) ) {
V_5 = F_27 ( V_5 ) ;
* V_51 = F_47 ( V_5 ) ;
return V_5 -> V_12 + V_52 ;
}
* V_51 = 0 ;
return 0 ;
}
static int F_50 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_12 )
{
struct V_3 * V_8 ;
unsigned int V_53 ;
int V_20 ;
V_53 = V_12 ;
while ( V_10 > F_46 ( V_53 ) )
V_53 += V_52 ;
V_8 = V_17 -> V_34 ;
if ( ! V_8 )
goto V_41;
do {
struct V_3 * V_5 = F_29 ( V_17 ) ;
if ( ! V_5 )
return - V_49 ;
for ( V_20 = 0 ; V_20 < V_48 ; V_20 ++ ) {
if ( F_18 ( V_17 , V_20 ) )
F_9 ( V_5 , V_20 , 0 ) ;
}
F_35 ( V_12 > V_29 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_11 = 0 ;
V_5 -> V_31 = 1 ;
V_5 -> V_4 = NULL ;
if ( F_7 ( V_8 ) )
F_27 ( V_8 ) -> V_4 = V_5 ;
V_5 -> V_6 [ 0 ] = V_8 ;
V_8 = F_1 ( V_5 ) ;
F_51 ( V_17 -> V_34 , V_8 ) ;
V_12 += V_52 ;
} while ( V_12 <= V_53 );
V_41:
return V_53 + V_52 ;
}
int F_52 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_54 , struct V_3 * * V_9 ,
void * * * V_55 )
{
struct V_3 * V_5 = NULL , * V_56 ;
void * * V_8 = ( void * * ) & V_17 -> V_34 ;
unsigned long V_51 ;
unsigned int V_12 , V_11 = 0 ;
unsigned long V_57 = V_10 | ( ( 1UL << V_54 ) - 1 ) ;
V_12 = F_48 ( V_17 , & V_56 , & V_51 ) ;
if ( V_57 > V_51 ) {
int error = F_50 ( V_17 , V_57 , V_12 ) ;
if ( error < 0 )
return error ;
V_12 = error ;
V_56 = V_17 -> V_34 ;
if ( V_54 == V_12 )
V_12 += V_52 ;
}
while ( V_12 > V_54 ) {
V_12 -= V_52 ;
if ( V_56 == NULL ) {
V_56 = F_29 ( V_17 ) ;
if ( ! V_56 )
return - V_49 ;
V_56 -> V_12 = V_12 ;
V_56 -> V_11 = V_11 ;
V_56 -> V_4 = V_5 ;
F_51 ( * V_8 , F_1 ( V_56 ) ) ;
if ( V_5 )
V_5 -> V_31 ++ ;
} else if ( ! F_7 ( V_56 ) )
break;
V_5 = F_27 ( V_56 ) ;
V_11 = F_4 ( V_5 , & V_56 , V_10 ) ;
V_8 = & V_5 -> V_6 [ V_11 ] ;
}
#ifdef F_6
if ( V_54 > V_12 ) {
unsigned V_30 , V_58 = 1 << ( V_54 - V_12 ) ;
V_11 = V_11 & ~ ( V_58 - 1 ) ;
V_8 = & V_5 -> V_6 [ V_11 ] ;
V_56 = F_1 ( V_8 ) ;
for ( V_30 = 0 ; V_30 < V_58 ; V_30 ++ ) {
if ( V_8 [ V_30 ] )
return - V_59 ;
}
for ( V_30 = 1 ; V_30 < V_58 ; V_30 ++ ) {
F_51 ( V_8 [ V_30 ] , V_56 ) ;
V_5 -> V_31 ++ ;
}
}
#endif
if ( V_9 )
* V_9 = V_5 ;
if ( V_55 )
* V_55 = V_8 ;
return 0 ;
}
int F_53 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_54 , void * V_60 )
{
struct V_3 * V_5 ;
void * * V_8 ;
int error ;
F_35 ( F_7 ( V_60 ) ) ;
error = F_52 ( V_17 , V_10 , V_54 , & V_5 , & V_8 ) ;
if ( error )
return error ;
if ( * V_8 != NULL )
return - V_59 ;
F_51 ( * V_8 , V_60 ) ;
if ( V_5 ) {
unsigned V_11 = F_3 ( V_5 , V_8 ) ;
V_5 -> V_31 ++ ;
F_35 ( F_13 ( V_5 , 0 , V_11 ) ) ;
F_35 ( F_13 ( V_5 , 1 , V_11 ) ) ;
F_35 ( F_13 ( V_5 , 2 , V_11 ) ) ;
} else {
F_35 ( F_19 ( V_17 ) ) ;
}
return 0 ;
}
void * F_54 ( struct V_16 * V_17 , unsigned long V_10 ,
struct V_3 * * V_9 , void * * * V_55 )
{
struct V_3 * V_5 , * V_4 ;
unsigned long V_51 ;
void * * V_8 ;
V_61:
V_4 = NULL ;
V_8 = ( void * * ) & V_17 -> V_34 ;
F_48 ( V_17 , & V_5 , & V_51 ) ;
if ( V_10 > V_51 )
return NULL ;
while ( F_7 ( V_5 ) ) {
unsigned V_11 ;
if ( V_5 == V_62 )
goto V_61;
V_4 = F_27 ( V_5 ) ;
V_11 = F_4 ( V_4 , & V_5 , V_10 ) ;
V_8 = V_4 -> V_6 + V_11 ;
}
if ( V_9 )
* V_9 = V_4 ;
if ( V_55 )
* V_55 = V_8 ;
return V_5 ;
}
void * * F_55 ( struct V_16 * V_17 , unsigned long V_10 )
{
void * * V_8 ;
if ( ! F_54 ( V_17 , V_10 , NULL , & V_8 ) )
return NULL ;
return V_8 ;
}
void * F_56 ( struct V_16 * V_17 , unsigned long V_10 )
{
return F_54 ( V_17 , V_10 , NULL , NULL ) ;
}
void * F_57 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_3 * V_5 , * V_4 ;
unsigned long V_51 ;
F_48 ( V_17 , & V_5 , & V_51 ) ;
F_35 ( V_10 > V_51 ) ;
while ( F_7 ( V_5 ) ) {
unsigned V_11 ;
V_4 = F_27 ( V_5 ) ;
V_11 = F_4 ( V_4 , & V_5 , V_10 ) ;
F_35 ( ! V_5 ) ;
if ( ! F_13 ( V_4 , V_20 , V_11 ) )
F_9 ( V_4 , V_20 , V_11 ) ;
}
if ( ! F_18 ( V_17 , V_20 ) )
F_15 ( V_17 , V_20 ) ;
return V_5 ;
}
static void F_58 ( struct V_16 * V_17 ,
struct V_3 * V_5 ,
unsigned int V_20 , unsigned int V_11 )
{
while ( V_5 ) {
if ( ! F_13 ( V_5 , V_20 , V_11 ) )
return;
F_11 ( V_5 , V_20 , V_11 ) ;
if ( F_20 ( V_5 , V_20 ) )
return;
V_11 = V_5 -> V_11 ;
V_5 = V_5 -> V_4 ;
}
if ( F_18 ( V_17 , V_20 ) )
F_16 ( V_17 , V_20 ) ;
}
void * F_59 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_3 * V_5 , * V_4 ;
unsigned long V_51 ;
int V_63 ( V_11 ) ;
F_48 ( V_17 , & V_5 , & V_51 ) ;
if ( V_10 > V_51 )
return NULL ;
V_4 = NULL ;
while ( F_7 ( V_5 ) ) {
V_4 = F_27 ( V_5 ) ;
V_11 = F_4 ( V_4 , & V_5 , V_10 ) ;
}
if ( V_5 )
F_58 ( V_17 , V_4 , V_20 , V_11 ) ;
return V_5 ;
}
int F_60 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_3 * V_5 , * V_4 ;
unsigned long V_51 ;
if ( ! F_18 ( V_17 , V_20 ) )
return 0 ;
F_48 ( V_17 , & V_5 , & V_51 ) ;
if ( V_10 > V_51 )
return 0 ;
if ( V_5 == NULL )
return 0 ;
while ( F_7 ( V_5 ) ) {
unsigned V_11 ;
V_4 = F_27 ( V_5 ) ;
V_11 = F_4 ( V_4 , & V_5 , V_10 ) ;
if ( ! V_5 )
return 0 ;
if ( ! F_13 ( V_4 , V_20 , V_11 ) )
return 0 ;
if ( V_5 == V_62 )
break;
}
return 1 ;
}
static inline void F_61 ( struct V_64 * V_65 ,
unsigned int V_12 )
{
#ifdef F_6
V_65 -> V_12 = V_12 ;
#endif
}
void * * F_62 ( struct V_16 * V_17 ,
struct V_64 * V_65 , unsigned V_66 )
{
unsigned V_20 = V_66 & V_67 ;
struct V_3 * V_5 , * V_56 ;
unsigned long V_10 , V_11 , V_51 ;
if ( ( V_66 & V_68 ) && ! F_18 ( V_17 , V_20 ) )
return NULL ;
V_10 = V_65 -> V_69 ;
if ( ! V_10 && V_65 -> V_10 )
return NULL ;
V_61:
F_48 ( V_17 , & V_56 , & V_51 ) ;
if ( V_10 > V_51 )
return NULL ;
if ( ! V_56 )
return NULL ;
if ( ! F_7 ( V_56 ) ) {
V_65 -> V_10 = V_10 ;
V_65 -> V_69 = V_51 + 1 ;
V_65 -> V_21 = 1 ;
F_61 ( V_65 , 0 ) ;
return ( void * * ) & V_17 -> V_34 ;
}
do {
V_5 = F_27 ( V_56 ) ;
V_11 = F_4 ( V_5 , & V_56 , V_10 ) ;
if ( ( V_66 & V_68 ) ?
! F_13 ( V_5 , V_20 , V_11 ) : ! V_56 ) {
if ( V_66 & V_70 )
return NULL ;
if ( V_66 & V_68 )
V_11 = F_21 (
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
V_10 &= ~ F_47 ( V_5 ) ;
V_10 += V_11 << V_5 -> V_12 ;
if ( ! V_10 )
return NULL ;
if ( V_11 == V_7 )
goto V_61;
V_56 = F_5 ( V_5 -> V_6 [ V_11 ] ) ;
}
if ( ( V_56 == NULL ) || ( V_56 == V_62 ) )
goto V_61;
} while ( F_7 ( V_56 ) );
V_65 -> V_10 = ( V_10 & ~ F_47 ( V_5 ) ) | ( V_11 << V_5 -> V_12 ) ;
V_65 -> V_69 = ( V_10 | F_47 ( V_5 ) ) + 1 ;
F_61 ( V_65 , V_5 -> V_12 ) ;
if ( V_66 & V_68 ) {
unsigned V_71 , V_72 ;
V_71 = V_11 / V_29 ;
V_72 = V_11 % V_29 ;
V_65 -> V_21 = V_5 -> V_21 [ V_20 ] [ V_71 ] >> V_72 ;
if ( V_71 < V_25 - 1 ) {
if ( V_72 )
V_65 -> V_21 |= V_5 -> V_21 [ V_20 ] [ V_71 + 1 ] <<
( V_29 - V_72 ) ;
V_65 -> V_69 = V_10 + V_29 ;
}
}
return V_5 -> V_6 + V_11 ;
}
unsigned long F_63 ( struct V_16 * V_17 ,
unsigned long * V_73 , unsigned long V_74 ,
unsigned long V_75 ,
unsigned int V_76 , unsigned int V_77 )
{
struct V_3 * V_4 , * V_5 , * V_56 ;
unsigned long V_51 ;
unsigned long V_78 = 0 ;
unsigned long V_10 = * V_73 ;
F_48 ( V_17 , & V_56 , & V_51 ) ;
V_74 = F_64 ( V_74 , V_51 ) ;
if ( V_10 > V_74 )
return 0 ;
if ( ! V_75 )
return 0 ;
if ( ! F_18 ( V_17 , V_76 ) ) {
* V_73 = V_74 + 1 ;
return 0 ;
}
if ( ! F_7 ( V_56 ) ) {
* V_73 = V_74 + 1 ;
F_15 ( V_17 , V_77 ) ;
return 1 ;
}
V_5 = F_27 ( V_56 ) ;
for (; ; ) {
unsigned V_11 = F_4 ( V_5 , & V_56 , V_10 ) ;
if ( ! V_56 )
goto V_79;
if ( ! F_13 ( V_5 , V_76 , V_11 ) )
goto V_79;
if ( F_7 ( V_56 ) ) {
V_5 = F_27 ( V_56 ) ;
continue;
}
V_78 ++ ;
F_9 ( V_5 , V_77 , V_11 ) ;
V_4 = V_5 ;
for (; ; ) {
V_11 = V_4 -> V_11 ;
V_4 = V_4 -> V_4 ;
if ( ! V_4 )
break;
if ( F_13 ( V_4 , V_77 , V_11 ) )
break;
F_9 ( V_4 , V_77 , V_11 ) ;
}
V_79:
V_10 = ( ( V_10 >> V_5 -> V_12 ) + 1 ) << V_5 -> V_12 ;
if ( V_10 > V_74 || ! V_10 )
break;
V_11 = ( V_10 >> V_5 -> V_12 ) & V_13 ;
while ( V_11 == 0 ) {
V_5 = V_5 -> V_4 ;
V_11 = ( V_10 >> V_5 -> V_12 ) & V_13 ;
}
if ( F_2 ( V_5 , V_5 -> V_6 [ V_11 ] ) )
goto V_79;
if ( V_78 >= V_75 )
break;
}
if ( V_78 > 0 )
F_15 ( V_17 , V_77 ) ;
* V_73 = V_10 ;
return V_78 ;
}
unsigned int
F_65 ( struct V_16 * V_17 , void * * V_80 ,
unsigned long V_81 , unsigned int V_82 )
{
struct V_64 V_65 ;
void * * V_8 ;
unsigned int V_35 = 0 ;
if ( F_66 ( ! V_82 ) )
return 0 ;
F_67 (slot, root, &iter, first_index) {
V_80 [ V_35 ] = F_5 ( * V_8 ) ;
if ( ! V_80 [ V_35 ] )
continue;
if ( F_7 ( V_80 [ V_35 ] ) ) {
V_8 = F_68 ( & V_65 ) ;
continue;
}
if ( ++ V_35 == V_82 )
break;
}
return V_35 ;
}
unsigned int
F_69 ( struct V_16 * V_17 ,
void * * * V_80 , unsigned long * V_83 ,
unsigned long V_81 , unsigned int V_82 )
{
struct V_64 V_65 ;
void * * V_8 ;
unsigned int V_35 = 0 ;
if ( F_66 ( ! V_82 ) )
return 0 ;
F_67 (slot, root, &iter, first_index) {
V_80 [ V_35 ] = V_8 ;
if ( V_83 )
V_83 [ V_35 ] = V_65 . V_10 ;
if ( ++ V_35 == V_82 )
break;
}
return V_35 ;
}
unsigned int
F_70 ( struct V_16 * V_17 , void * * V_80 ,
unsigned long V_81 , unsigned int V_82 ,
unsigned int V_20 )
{
struct V_64 V_65 ;
void * * V_8 ;
unsigned int V_35 = 0 ;
if ( F_66 ( ! V_82 ) )
return 0 ;
F_71 (slot, root, &iter, first_index, tag) {
V_80 [ V_35 ] = F_5 ( * V_8 ) ;
if ( ! V_80 [ V_35 ] )
continue;
if ( F_7 ( V_80 [ V_35 ] ) ) {
V_8 = F_68 ( & V_65 ) ;
continue;
}
if ( ++ V_35 == V_82 )
break;
}
return V_35 ;
}
unsigned int
F_72 ( struct V_16 * V_17 , void * * * V_80 ,
unsigned long V_81 , unsigned int V_82 ,
unsigned int V_20 )
{
struct V_64 V_65 ;
void * * V_8 ;
unsigned int V_35 = 0 ;
if ( F_66 ( ! V_82 ) )
return 0 ;
F_71 (slot, root, &iter, first_index, tag) {
V_80 [ V_35 ] = V_8 ;
if ( ++ V_35 == V_82 )
break;
}
return V_35 ;
}
static unsigned long F_73 ( struct V_3 * V_8 , void * V_60 ,
unsigned long V_10 , struct V_84 * V_85 )
{
unsigned long V_30 ;
do {
unsigned int V_12 = V_8 -> V_12 ;
for ( V_30 = ( V_10 >> V_12 ) & V_13 ;
V_30 < V_7 ;
V_30 ++ , V_10 += ( 1UL << V_12 ) ) {
struct V_3 * V_5 =
F_5 ( V_8 -> V_6 [ V_30 ] ) ;
if ( V_5 == V_62 )
goto V_41;
if ( ! F_7 ( V_5 ) ) {
if ( V_5 == V_60 ) {
V_85 -> V_86 = V_10 ;
V_85 -> V_87 = true ;
goto V_41;
}
continue;
}
V_5 = F_27 ( V_5 ) ;
if ( F_2 ( V_8 , V_5 ) )
continue;
V_8 = V_5 ;
break;
}
} while ( V_30 < V_7 );
V_41:
if ( ( V_10 == 0 ) && ( V_30 == V_7 ) )
V_85 -> V_87 = true ;
return V_10 ;
}
unsigned long F_74 ( struct V_16 * V_17 , void * V_60 )
{
struct V_3 * V_5 ;
unsigned long V_88 ;
unsigned long V_89 = 0 ;
struct V_84 V_85 = {
. V_86 = - 1 ,
. V_87 = false ,
} ;
do {
F_75 () ;
V_5 = F_5 ( V_17 -> V_34 ) ;
if ( ! F_7 ( V_5 ) ) {
F_76 () ;
if ( V_5 == V_60 )
V_85 . V_86 = 0 ;
break;
}
V_5 = F_27 ( V_5 ) ;
V_88 = F_47 ( V_5 ) ;
if ( V_89 > V_88 ) {
F_76 () ;
break;
}
V_89 = F_73 ( V_5 , V_60 , V_89 , & V_85 ) ;
F_76 () ;
F_77 () ;
} while ( ! V_85 . V_87 && V_89 <= V_88 );
return V_85 . V_86 ;
}
unsigned long F_74 ( struct V_16 * V_17 , void * V_60 )
{
return - 1 ;
}
static inline bool F_78 ( struct V_16 * V_17 )
{
bool V_90 = false ;
for (; ; ) {
struct V_3 * V_5 = V_17 -> V_34 ;
struct V_3 * V_56 ;
if ( ! F_7 ( V_5 ) )
break;
V_5 = F_27 ( V_5 ) ;
if ( V_5 -> V_31 != 1 )
break;
V_56 = V_5 -> V_6 [ 0 ] ;
if ( ! V_56 )
break;
if ( ! F_7 ( V_56 ) && V_5 -> V_12 )
break;
if ( F_7 ( V_56 ) )
F_27 ( V_56 ) -> V_4 = NULL ;
V_17 -> V_34 = V_56 ;
if ( ! F_7 ( V_56 ) )
V_5 -> V_6 [ 0 ] = V_62 ;
F_39 ( V_5 ) ;
V_90 = true ;
}
return V_90 ;
}
bool F_79 ( struct V_16 * V_17 ,
struct V_3 * V_5 )
{
bool V_91 = false ;
do {
struct V_3 * V_4 ;
if ( V_5 -> V_31 ) {
if ( V_5 == F_27 ( V_17 -> V_34 ) )
V_91 |= F_78 ( V_17 ) ;
return V_91 ;
}
V_4 = V_5 -> V_4 ;
if ( V_4 ) {
V_4 -> V_6 [ V_5 -> V_11 ] = NULL ;
V_4 -> V_31 -- ;
} else {
F_17 ( V_17 ) ;
V_17 -> V_34 = NULL ;
}
F_39 ( V_5 ) ;
V_91 = true ;
V_5 = V_4 ;
} while ( V_5 );
return V_91 ;
}
static inline void F_80 ( struct V_3 * V_5 ,
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
void * F_81 ( struct V_16 * V_17 ,
unsigned long V_10 , void * V_60 )
{
struct V_3 * V_5 ;
unsigned int V_11 ;
void * * V_8 ;
void * V_14 ;
int V_20 ;
V_14 = F_54 ( V_17 , V_10 , & V_5 , & V_8 ) ;
if ( ! V_14 )
return NULL ;
if ( V_60 && V_14 != V_60 )
return NULL ;
if ( ! V_5 ) {
F_17 ( V_17 ) ;
V_17 -> V_34 = NULL ;
return V_14 ;
}
V_11 = F_3 ( V_5 , V_8 ) ;
for ( V_20 = 0 ; V_20 < V_48 ; V_20 ++ )
F_58 ( V_17 , V_5 , V_20 , V_11 ) ;
F_80 ( V_5 , F_1 ( V_8 ) , V_11 ) ;
V_5 -> V_6 [ V_11 ] = NULL ;
V_5 -> V_31 -- ;
F_79 ( V_17 , V_5 ) ;
return V_14 ;
}
void * F_82 ( struct V_16 * V_17 , unsigned long V_10 )
{
return F_81 ( V_17 , V_10 , NULL ) ;
}
struct V_3 * F_83 (
struct V_16 * V_17 ,
unsigned long V_10 , void * V_14 )
{
struct V_3 * V_5 ;
void * * V_8 ;
F_54 ( V_17 , V_10 , & V_5 , & V_8 ) ;
if ( V_5 ) {
unsigned int V_20 , V_11 = F_3 ( V_5 , V_8 ) ;
for ( V_20 = 0 ; V_20 < V_48 ; V_20 ++ )
F_58 ( V_17 , V_5 , V_20 , V_11 ) ;
} else {
V_17 -> V_18 &= V_19 ;
}
F_84 ( V_8 , V_14 ) ;
return V_5 ;
}
int F_85 ( struct V_16 * V_17 , unsigned int V_20 )
{
return F_18 ( V_17 , V_20 ) ;
}
static void
F_86 ( void * V_92 )
{
struct V_3 * V_5 = V_92 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_87 ( & V_5 -> V_93 ) ;
}
static int F_88 ( struct V_94 * V_95 ,
unsigned long V_96 , void * V_97 )
{
int V_98 = ( long ) V_97 ;
struct V_36 * V_37 ;
struct V_3 * V_5 ;
if ( V_96 == V_99 || V_96 == V_100 ) {
V_37 = & F_89 ( V_42 , V_98 ) ;
while ( V_37 -> V_43 ) {
V_5 = V_37 -> V_44 ;
V_37 -> V_44 = V_5 -> V_45 ;
F_38 ( V_38 , V_5 ) ;
V_37 -> V_43 -- ;
}
}
return V_101 ;
}
void T_3 F_90 ( void )
{
V_38 = F_91 ( L_5 ,
sizeof( struct V_3 ) , 0 ,
V_102 | V_103 ,
F_86 ) ;
F_92 ( F_88 , 0 ) ;
}
