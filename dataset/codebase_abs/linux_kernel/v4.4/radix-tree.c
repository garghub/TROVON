static inline void * F_1 ( void * V_1 )
{
return ( void * ) ( ( unsigned long ) V_1 | V_2 ) ;
}
static inline void * F_2 ( void * V_1 )
{
return ( void * ) ( ( unsigned long ) V_1 & ~ V_2 ) ;
}
static inline T_1 F_3 ( struct V_3 * V_4 )
{
return V_4 -> V_5 & V_6 ;
}
static inline void F_4 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_10 )
{
F_5 ( V_10 , V_8 -> V_11 [ V_9 ] ) ;
}
static inline void F_6 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_10 )
{
F_7 ( V_10 , V_8 -> V_11 [ V_9 ] ) ;
}
static inline int F_8 ( struct V_7 * V_8 , unsigned int V_9 ,
int V_10 )
{
return F_9 ( V_10 , V_8 -> V_11 [ V_9 ] ) ;
}
static inline void F_10 ( struct V_3 * V_4 , unsigned int V_9 )
{
V_4 -> V_5 |= ( V_12 T_1 ) ( 1 << ( V_9 + V_13 ) ) ;
}
static inline void F_11 ( struct V_3 * V_4 , unsigned int V_9 )
{
V_4 -> V_5 &= ( V_12 T_1 ) ~ ( 1 << ( V_9 + V_13 ) ) ;
}
static inline void F_12 ( struct V_3 * V_4 )
{
V_4 -> V_5 &= V_6 ;
}
static inline int F_13 ( struct V_3 * V_4 , unsigned int V_9 )
{
return ( V_12 unsigned ) V_4 -> V_5 & ( 1 << ( V_9 + V_13 ) ) ;
}
static inline int F_14 ( struct V_7 * V_8 , unsigned int V_9 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( V_8 -> V_11 [ V_9 ] [ V_14 ] )
return 1 ;
}
return 0 ;
}
static T_2 unsigned long
F_15 ( const unsigned long * V_16 ,
unsigned long V_17 , unsigned long V_10 )
{
if ( ! F_16 ( V_17 ) )
return F_17 ( V_16 , V_17 , V_10 ) ;
if ( V_10 < V_17 ) {
unsigned long V_18 ;
V_16 += V_10 / V_19 ;
V_18 = * V_16 >> ( V_10 % V_19 ) ;
if ( V_18 )
return F_18 ( V_18 ) + V_10 ;
V_10 = ( V_10 + V_19 ) & ~ ( V_19 - 1 ) ;
while ( V_10 < V_17 ) {
V_18 = * ++ V_16 ;
if ( V_18 )
return F_18 ( V_18 ) + V_10 ;
V_10 += V_19 ;
}
}
return V_17 ;
}
static struct V_7 *
F_19 ( struct V_3 * V_4 )
{
struct V_7 * V_20 = NULL ;
T_1 V_5 = F_3 ( V_4 ) ;
if ( ! F_20 ( V_5 ) && ! F_21 () ) {
struct V_21 * V_22 ;
V_22 = F_22 ( & V_23 ) ;
if ( V_22 -> V_24 ) {
V_20 = V_22 -> V_25 ;
V_22 -> V_25 = V_20 -> V_26 ;
V_20 -> V_26 = NULL ;
V_22 -> V_24 -- ;
}
F_23 ( V_20 ) ;
}
if ( V_20 == NULL )
V_20 = F_24 ( V_27 , V_5 ) ;
F_25 ( F_26 ( V_20 ) ) ;
return V_20 ;
}
static void F_27 ( struct V_28 * V_29 )
{
struct V_7 * V_8 =
F_28 ( V_29 , struct V_7 , V_28 ) ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
F_6 ( V_8 , V_30 , 0 ) ;
V_8 -> V_32 [ 0 ] = NULL ;
V_8 -> V_33 = 0 ;
F_29 ( V_27 , V_8 ) ;
}
static inline void
F_30 ( struct V_7 * V_8 )
{
F_31 ( & V_8 -> V_28 , F_27 ) ;
}
static int F_32 ( T_1 V_5 )
{
struct V_21 * V_22 ;
struct V_7 * V_8 ;
int V_20 = - V_34 ;
F_33 () ;
V_22 = F_22 ( & V_23 ) ;
while ( V_22 -> V_24 < V_35 ) {
F_34 () ;
V_8 = F_24 ( V_27 , V_5 ) ;
if ( V_8 == NULL )
goto V_36;
F_33 () ;
V_22 = F_22 ( & V_23 ) ;
if ( V_22 -> V_24 < V_35 ) {
V_8 -> V_26 = V_22 -> V_25 ;
V_22 -> V_25 = V_8 ;
V_22 -> V_24 ++ ;
} else {
F_29 ( V_27 , V_8 ) ;
}
}
V_20 = 0 ;
V_36:
return V_20 ;
}
int V_21 ( T_1 V_5 )
{
F_35 ( ! F_20 ( V_5 ) ) ;
return F_32 ( V_5 ) ;
}
int F_36 ( T_1 V_5 )
{
if ( F_20 ( V_5 ) )
return F_32 ( V_5 ) ;
F_33 () ;
return 0 ;
}
static inline unsigned long F_37 ( unsigned int V_37 )
{
return V_38 [ V_37 ] ;
}
static int F_38 ( struct V_3 * V_4 , unsigned long V_39 )
{
struct V_7 * V_8 ;
struct V_7 * V_40 ;
unsigned int V_37 ;
int V_9 ;
V_37 = V_4 -> V_37 + 1 ;
while ( V_39 > F_37 ( V_37 ) )
V_37 ++ ;
if ( V_4 -> V_41 == NULL ) {
V_4 -> V_37 = V_37 ;
goto V_36;
}
do {
unsigned int V_42 ;
if ( ! ( V_8 = F_19 ( V_4 ) ) )
return - V_34 ;
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ ) {
if ( F_13 ( V_4 , V_9 ) )
F_4 ( V_8 , V_9 , 0 ) ;
}
V_42 = V_4 -> V_37 + 1 ;
F_25 ( V_42 & ~ V_43 ) ;
V_8 -> V_44 = V_42 ;
V_8 -> V_33 = 1 ;
V_8 -> V_45 = NULL ;
V_40 = V_4 -> V_41 ;
if ( V_42 > 1 ) {
V_40 = F_2 ( V_40 ) ;
V_40 -> V_45 = V_8 ;
}
V_8 -> V_32 [ 0 ] = V_40 ;
V_8 = F_1 ( V_8 ) ;
F_39 ( V_4 -> V_41 , V_8 ) ;
V_4 -> V_37 = V_42 ;
} while ( V_37 > V_4 -> V_37 );
V_36:
return 0 ;
}
int F_40 ( struct V_3 * V_4 , unsigned long V_39 ,
struct V_7 * * V_46 , void * * * V_47 )
{
struct V_7 * V_8 = NULL , * V_40 ;
unsigned int V_37 , V_48 , V_10 ;
int error ;
if ( V_39 > F_37 ( V_4 -> V_37 ) ) {
error = F_38 ( V_4 , V_39 ) ;
if ( error )
return error ;
}
V_40 = F_2 ( V_4 -> V_41 ) ;
V_37 = V_4 -> V_37 ;
V_48 = ( V_37 - 1 ) * V_49 ;
V_10 = 0 ;
while ( V_37 > 0 ) {
if ( V_40 == NULL ) {
if ( ! ( V_40 = F_19 ( V_4 ) ) )
return - V_34 ;
V_40 -> V_44 = V_37 ;
V_40 -> V_45 = V_8 ;
if ( V_8 ) {
F_39 ( V_8 -> V_32 [ V_10 ] , V_40 ) ;
V_8 -> V_33 ++ ;
V_40 -> V_44 |= V_10 << V_50 ;
} else
F_39 ( V_4 -> V_41 , F_1 ( V_40 ) ) ;
}
V_10 = ( V_39 >> V_48 ) & V_51 ;
V_8 = V_40 ;
V_40 = V_8 -> V_32 [ V_10 ] ;
V_48 -= V_49 ;
V_37 -- ;
}
if ( V_46 )
* V_46 = V_8 ;
if ( V_47 )
* V_47 = V_8 ? V_8 -> V_32 + V_10 : ( void * * ) & V_4 -> V_41 ;
return 0 ;
}
int F_41 ( struct V_3 * V_4 ,
unsigned long V_39 , void * V_52 )
{
struct V_7 * V_8 ;
void * * V_40 ;
int error ;
F_25 ( F_26 ( V_52 ) ) ;
error = F_40 ( V_4 , V_39 , & V_8 , & V_40 ) ;
if ( error )
return error ;
if ( * V_40 != NULL )
return - V_53 ;
F_39 ( * V_40 , V_52 ) ;
if ( V_8 ) {
V_8 -> V_33 ++ ;
F_25 ( F_8 ( V_8 , 0 , V_39 & V_51 ) ) ;
F_25 ( F_8 ( V_8 , 1 , V_39 & V_51 ) ) ;
} else {
F_25 ( F_13 ( V_4 , 0 ) ) ;
F_25 ( F_13 ( V_4 , 1 ) ) ;
}
return 0 ;
}
void * F_42 ( struct V_3 * V_4 , unsigned long V_39 ,
struct V_7 * * V_46 , void * * * V_47 )
{
struct V_7 * V_8 , * V_45 ;
unsigned int V_37 , V_48 ;
void * * V_40 ;
V_8 = F_43 ( V_4 -> V_41 ) ;
if ( V_8 == NULL )
return NULL ;
if ( ! F_26 ( V_8 ) ) {
if ( V_39 > 0 )
return NULL ;
if ( V_46 )
* V_46 = NULL ;
if ( V_47 )
* V_47 = ( void * * ) & V_4 -> V_41 ;
return V_8 ;
}
V_8 = F_2 ( V_8 ) ;
V_37 = V_8 -> V_44 & V_43 ;
if ( V_39 > F_37 ( V_37 ) )
return NULL ;
V_48 = ( V_37 - 1 ) * V_49 ;
do {
V_45 = V_8 ;
V_40 = V_8 -> V_32 + ( ( V_39 >> V_48 ) & V_51 ) ;
V_8 = F_43 ( * V_40 ) ;
if ( V_8 == NULL )
return NULL ;
V_48 -= V_49 ;
V_37 -- ;
} while ( V_37 > 0 );
if ( V_46 )
* V_46 = V_45 ;
if ( V_47 )
* V_47 = V_40 ;
return V_8 ;
}
void * * F_44 ( struct V_3 * V_4 , unsigned long V_39 )
{
void * * V_40 ;
if ( ! F_42 ( V_4 , V_39 , NULL , & V_40 ) )
return NULL ;
return V_40 ;
}
void * F_45 ( struct V_3 * V_4 , unsigned long V_39 )
{
return F_42 ( V_4 , V_39 , NULL , NULL ) ;
}
void * F_46 ( struct V_3 * V_4 ,
unsigned long V_39 , unsigned int V_9 )
{
unsigned int V_37 , V_48 ;
struct V_7 * V_40 ;
V_37 = V_4 -> V_37 ;
F_25 ( V_39 > F_37 ( V_37 ) ) ;
V_40 = F_2 ( V_4 -> V_41 ) ;
V_48 = ( V_37 - 1 ) * V_49 ;
while ( V_37 > 0 ) {
int V_10 ;
V_10 = ( V_39 >> V_48 ) & V_51 ;
if ( ! F_8 ( V_40 , V_9 , V_10 ) )
F_4 ( V_40 , V_9 , V_10 ) ;
V_40 = V_40 -> V_32 [ V_10 ] ;
F_25 ( V_40 == NULL ) ;
V_48 -= V_49 ;
V_37 -- ;
}
if ( V_40 && ! F_13 ( V_4 , V_9 ) )
F_10 ( V_4 , V_9 ) ;
return V_40 ;
}
void * F_47 ( struct V_3 * V_4 ,
unsigned long V_39 , unsigned int V_9 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_40 = NULL ;
unsigned int V_37 , V_48 ;
int V_54 ( V_10 ) ;
V_37 = V_4 -> V_37 ;
if ( V_39 > F_37 ( V_37 ) )
goto V_36;
V_48 = V_37 * V_49 ;
V_40 = F_2 ( V_4 -> V_41 ) ;
while ( V_48 ) {
if ( V_40 == NULL )
goto V_36;
V_48 -= V_49 ;
V_10 = ( V_39 >> V_48 ) & V_51 ;
V_8 = V_40 ;
V_40 = V_40 -> V_32 [ V_10 ] ;
}
if ( V_40 == NULL )
goto V_36;
while ( V_8 ) {
if ( ! F_8 ( V_8 , V_9 , V_10 ) )
goto V_36;
F_6 ( V_8 , V_9 , V_10 ) ;
if ( F_14 ( V_8 , V_9 ) )
goto V_36;
V_39 >>= V_49 ;
V_10 = V_39 & V_51 ;
V_8 = V_8 -> V_45 ;
}
if ( F_13 ( V_4 , V_9 ) )
F_11 ( V_4 , V_9 ) ;
V_36:
return V_40 ;
}
int F_48 ( struct V_3 * V_4 ,
unsigned long V_39 , unsigned int V_9 )
{
unsigned int V_37 , V_48 ;
struct V_7 * V_8 ;
if ( ! F_13 ( V_4 , V_9 ) )
return 0 ;
V_8 = F_43 ( V_4 -> V_41 ) ;
if ( V_8 == NULL )
return 0 ;
if ( ! F_26 ( V_8 ) )
return ( V_39 == 0 ) ;
V_8 = F_2 ( V_8 ) ;
V_37 = V_8 -> V_44 & V_43 ;
if ( V_39 > F_37 ( V_37 ) )
return 0 ;
V_48 = ( V_37 - 1 ) * V_49 ;
for ( ; ; ) {
int V_10 ;
if ( V_8 == NULL )
return 0 ;
V_10 = ( V_39 >> V_48 ) & V_51 ;
if ( ! F_8 ( V_8 , V_9 , V_10 ) )
return 0 ;
if ( V_37 == 1 )
return 1 ;
V_8 = F_43 ( V_8 -> V_32 [ V_10 ] ) ;
V_48 -= V_49 ;
V_37 -- ;
}
}
void * * F_49 ( struct V_3 * V_4 ,
struct V_55 * V_56 , unsigned V_57 )
{
unsigned V_48 , V_9 = V_57 & V_58 ;
struct V_7 * V_41 , * V_8 ;
unsigned long V_39 , V_10 , V_37 ;
if ( ( V_57 & V_59 ) && ! F_13 ( V_4 , V_9 ) )
return NULL ;
V_39 = V_56 -> V_60 ;
if ( ! V_39 && V_56 -> V_39 )
return NULL ;
V_41 = F_43 ( V_4 -> V_41 ) ;
if ( F_26 ( V_41 ) ) {
V_41 = F_2 ( V_41 ) ;
} else if ( V_41 && ! V_39 ) {
V_56 -> V_39 = 0 ;
V_56 -> V_60 = 1 ;
V_56 -> V_11 = 1 ;
return ( void * * ) & V_4 -> V_41 ;
} else
return NULL ;
V_61:
V_37 = V_41 -> V_44 & V_43 ;
V_48 = ( V_37 - 1 ) * V_49 ;
V_10 = V_39 >> V_48 ;
if ( V_10 >= V_62 )
return NULL ;
V_8 = V_41 ;
while ( 1 ) {
if ( ( V_57 & V_59 ) ?
! F_9 ( V_10 , V_8 -> V_11 [ V_9 ] ) :
! V_8 -> V_32 [ V_10 ] ) {
if ( V_57 & V_63 )
return NULL ;
if ( V_57 & V_59 )
V_10 = F_15 (
V_8 -> V_11 [ V_9 ] ,
V_62 ,
V_10 + 1 ) ;
else
while ( ++ V_10 < V_62 ) {
if ( V_8 -> V_32 [ V_10 ] )
break;
}
V_39 &= ~ ( ( V_62 << V_48 ) - 1 ) ;
V_39 += V_10 << V_48 ;
if ( ! V_39 )
return NULL ;
if ( V_10 == V_62 )
goto V_61;
}
if ( ! V_48 )
break;
V_8 = F_43 ( V_8 -> V_32 [ V_10 ] ) ;
if ( V_8 == NULL )
goto V_61;
V_48 -= V_49 ;
V_10 = ( V_39 >> V_48 ) & V_51 ;
}
V_56 -> V_39 = V_39 ;
V_56 -> V_60 = ( V_39 | V_51 ) + 1 ;
if ( V_57 & V_59 ) {
unsigned V_64 , V_65 ;
V_64 = V_10 / V_19 ;
V_65 = V_10 % V_19 ;
V_56 -> V_11 = V_8 -> V_11 [ V_9 ] [ V_64 ] >> V_65 ;
if ( V_64 < V_15 - 1 ) {
if ( V_65 )
V_56 -> V_11 |= V_8 -> V_11 [ V_9 ] [ V_64 + 1 ] <<
( V_19 - V_65 ) ;
V_56 -> V_60 = V_39 + V_19 ;
}
}
return V_8 -> V_32 + V_10 ;
}
unsigned long F_50 ( struct V_3 * V_4 ,
unsigned long * V_66 , unsigned long V_67 ,
unsigned long V_68 ,
unsigned int V_69 , unsigned int V_70 )
{
unsigned int V_37 = V_4 -> V_37 ;
struct V_7 * V_8 = NULL ;
struct V_7 * V_40 ;
unsigned int V_48 ;
unsigned long V_71 = 0 ;
unsigned long V_39 = * V_66 ;
V_67 = F_51 ( V_67 , F_37 ( V_37 ) ) ;
if ( V_39 > V_67 )
return 0 ;
if ( ! V_68 )
return 0 ;
if ( ! F_13 ( V_4 , V_69 ) ) {
* V_66 = V_67 + 1 ;
return 0 ;
}
if ( V_37 == 0 ) {
* V_66 = V_67 + 1 ;
F_10 ( V_4 , V_70 ) ;
return 1 ;
}
V_48 = ( V_37 - 1 ) * V_49 ;
V_40 = F_2 ( V_4 -> V_41 ) ;
for (; ; ) {
unsigned long V_72 ;
int V_10 ;
V_10 = ( V_39 >> V_48 ) & V_51 ;
if ( ! V_40 -> V_32 [ V_10 ] )
goto V_73;
if ( ! F_8 ( V_40 , V_69 , V_10 ) )
goto V_73;
if ( V_48 ) {
V_48 -= V_49 ;
V_8 = V_40 ;
V_40 = V_40 -> V_32 [ V_10 ] ;
continue;
}
V_71 ++ ;
F_4 ( V_40 , V_70 , V_10 ) ;
V_72 = V_39 ;
while ( V_8 ) {
V_72 >>= V_49 ;
V_10 = V_72 & V_51 ;
if ( F_8 ( V_8 , V_70 , V_10 ) )
break;
F_4 ( V_8 , V_70 , V_10 ) ;
V_8 = V_8 -> V_45 ;
}
V_8 = NULL ;
V_73:
V_39 = ( ( V_39 >> V_48 ) + 1 ) << V_48 ;
if ( V_39 > V_67 || ! V_39 )
break;
if ( V_71 >= V_68 )
break;
while ( ( ( V_39 >> V_48 ) & V_51 ) == 0 ) {
V_40 = V_40 -> V_45 ;
V_48 += V_49 ;
}
}
if ( V_71 > 0 )
F_10 ( V_4 , V_70 ) ;
* V_66 = V_39 ;
return V_71 ;
}
unsigned int
F_52 ( struct V_3 * V_4 , void * * V_74 ,
unsigned long V_75 , unsigned int V_76 )
{
struct V_55 V_56 ;
void * * V_40 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_76 ) )
return 0 ;
F_54 (slot, root, &iter, first_index) {
V_74 [ V_20 ] = F_2 ( F_43 ( * V_40 ) ) ;
if ( ! V_74 [ V_20 ] )
continue;
if ( ++ V_20 == V_76 )
break;
}
return V_20 ;
}
unsigned int
F_55 ( struct V_3 * V_4 ,
void * * * V_74 , unsigned long * V_77 ,
unsigned long V_75 , unsigned int V_76 )
{
struct V_55 V_56 ;
void * * V_40 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_76 ) )
return 0 ;
F_54 (slot, root, &iter, first_index) {
V_74 [ V_20 ] = V_40 ;
if ( V_77 )
V_77 [ V_20 ] = V_56 . V_39 ;
if ( ++ V_20 == V_76 )
break;
}
return V_20 ;
}
unsigned int
F_56 ( struct V_3 * V_4 , void * * V_74 ,
unsigned long V_75 , unsigned int V_76 ,
unsigned int V_9 )
{
struct V_55 V_56 ;
void * * V_40 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_76 ) )
return 0 ;
F_57 (slot, root, &iter, first_index, tag) {
V_74 [ V_20 ] = F_2 ( F_43 ( * V_40 ) ) ;
if ( ! V_74 [ V_20 ] )
continue;
if ( ++ V_20 == V_76 )
break;
}
return V_20 ;
}
unsigned int
F_58 ( struct V_3 * V_4 , void * * * V_74 ,
unsigned long V_75 , unsigned int V_76 ,
unsigned int V_9 )
{
struct V_55 V_56 ;
void * * V_40 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_76 ) )
return 0 ;
F_57 (slot, root, &iter, first_index, tag) {
V_74 [ V_20 ] = V_40 ;
if ( ++ V_20 == V_76 )
break;
}
return V_20 ;
}
static unsigned long F_59 ( struct V_7 * V_40 , void * V_52 ,
unsigned long V_39 , unsigned long * V_78 )
{
unsigned int V_48 , V_37 ;
unsigned long V_30 ;
V_37 = V_40 -> V_44 & V_43 ;
V_48 = ( V_37 - 1 ) * V_49 ;
for ( ; V_37 > 1 ; V_37 -- ) {
V_30 = ( V_39 >> V_48 ) & V_51 ;
for (; ; ) {
if ( V_40 -> V_32 [ V_30 ] != NULL )
break;
V_39 &= ~ ( ( 1UL << V_48 ) - 1 ) ;
V_39 += 1UL << V_48 ;
if ( V_39 == 0 )
goto V_36;
V_30 ++ ;
if ( V_30 == V_62 )
goto V_36;
}
V_48 -= V_49 ;
V_40 = F_43 ( V_40 -> V_32 [ V_30 ] ) ;
if ( V_40 == NULL )
goto V_36;
}
for ( V_30 = 0 ; V_30 < V_62 ; V_30 ++ ) {
if ( V_40 -> V_32 [ V_30 ] == V_52 ) {
* V_78 = V_39 + V_30 ;
V_39 = 0 ;
goto V_36;
}
}
V_39 += V_62 ;
V_36:
return V_39 ;
}
unsigned long F_60 ( struct V_3 * V_4 , void * V_52 )
{
struct V_7 * V_8 ;
unsigned long V_79 ;
unsigned long V_80 = 0 ;
unsigned long V_78 = - 1 ;
do {
F_61 () ;
V_8 = F_43 ( V_4 -> V_41 ) ;
if ( ! F_26 ( V_8 ) ) {
F_62 () ;
if ( V_8 == V_52 )
V_78 = 0 ;
break;
}
V_8 = F_2 ( V_8 ) ;
V_79 = F_37 ( V_8 -> V_44 &
V_43 ) ;
if ( V_80 > V_79 ) {
F_62 () ;
break;
}
V_80 = F_59 ( V_8 , V_52 , V_80 , & V_78 ) ;
F_62 () ;
F_63 () ;
} while ( V_80 != 0 && V_80 <= V_79 );
return V_78 ;
}
unsigned long F_60 ( struct V_3 * V_4 , void * V_52 )
{
return - 1 ;
}
static inline void F_64 ( struct V_3 * V_4 )
{
while ( V_4 -> V_37 > 0 ) {
struct V_7 * V_81 = V_4 -> V_41 ;
struct V_7 * V_40 ;
F_25 ( ! F_26 ( V_81 ) ) ;
V_81 = F_2 ( V_81 ) ;
if ( V_81 -> V_33 != 1 )
break;
if ( ! V_81 -> V_32 [ 0 ] )
break;
V_40 = V_81 -> V_32 [ 0 ] ;
if ( V_4 -> V_37 > 1 ) {
V_40 -> V_45 = NULL ;
V_40 = F_1 ( V_40 ) ;
}
V_4 -> V_41 = V_40 ;
V_4 -> V_37 -- ;
if ( V_4 -> V_37 == 0 )
* ( ( unsigned long * ) & V_81 -> V_32 [ 0 ] ) |=
V_2 ;
F_30 ( V_81 ) ;
}
}
bool F_65 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
bool V_82 = false ;
do {
struct V_7 * V_45 ;
if ( V_8 -> V_33 ) {
if ( V_8 == F_2 ( V_4 -> V_41 ) ) {
F_64 ( V_4 ) ;
if ( V_4 -> V_37 == 0 )
V_82 = true ;
}
return V_82 ;
}
V_45 = V_8 -> V_45 ;
if ( V_45 ) {
unsigned int V_10 ;
V_10 = V_8 -> V_44 >> V_50 ;
V_45 -> V_32 [ V_10 ] = NULL ;
V_45 -> V_33 -- ;
} else {
F_12 ( V_4 ) ;
V_4 -> V_37 = 0 ;
V_4 -> V_41 = NULL ;
}
F_30 ( V_8 ) ;
V_82 = true ;
V_8 = V_45 ;
} while ( V_8 );
return V_82 ;
}
void * F_66 ( struct V_3 * V_4 ,
unsigned long V_39 , void * V_52 )
{
struct V_7 * V_8 ;
unsigned int V_10 ;
void * * V_40 ;
void * V_83 ;
int V_9 ;
V_83 = F_42 ( V_4 , V_39 , & V_8 , & V_40 ) ;
if ( ! V_83 )
return NULL ;
if ( V_52 && V_83 != V_52 )
return NULL ;
if ( ! V_8 ) {
F_12 ( V_4 ) ;
V_4 -> V_41 = NULL ;
return V_83 ;
}
V_10 = V_39 & V_51 ;
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ ) {
if ( F_8 ( V_8 , V_9 , V_10 ) )
F_47 ( V_4 , V_39 , V_9 ) ;
}
V_8 -> V_32 [ V_10 ] = NULL ;
V_8 -> V_33 -- ;
F_65 ( V_4 , V_8 ) ;
return V_83 ;
}
void * F_67 ( struct V_3 * V_4 , unsigned long V_39 )
{
return F_66 ( V_4 , V_39 , NULL ) ;
}
int F_68 ( struct V_3 * V_4 , unsigned int V_9 )
{
return F_13 ( V_4 , V_9 ) ;
}
static void
F_69 ( void * V_84 )
{
struct V_7 * V_8 = V_84 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_70 ( & V_8 -> V_85 ) ;
}
static T_3 unsigned long F_71 ( unsigned int V_37 )
{
unsigned int V_86 = V_37 * V_49 ;
int V_48 = V_87 - V_86 ;
if ( V_48 < 0 )
return ~ 0UL ;
if ( V_48 >= V_19 )
return 0UL ;
return ~ 0UL >> V_48 ;
}
static T_3 void F_72 ( void )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < F_73 ( V_38 ) ; V_30 ++ )
V_38 [ V_30 ] = F_71 ( V_30 ) ;
}
static int F_74 ( struct V_88 * V_89 ,
unsigned long V_90 ,
void * V_91 )
{
int V_92 = ( long ) V_91 ;
struct V_21 * V_22 ;
struct V_7 * V_8 ;
if ( V_90 == V_93 || V_90 == V_94 ) {
V_22 = & F_75 ( V_23 , V_92 ) ;
while ( V_22 -> V_24 ) {
V_8 = V_22 -> V_25 ;
V_22 -> V_25 = V_8 -> V_26 ;
F_29 ( V_27 , V_8 ) ;
V_22 -> V_24 -- ;
}
}
return V_95 ;
}
void T_3 F_76 ( void )
{
V_27 = F_77 ( L_1 ,
sizeof( struct V_7 ) , 0 ,
V_96 | V_97 ,
F_69 ) ;
F_72 () ;
F_78 ( F_74 , 0 ) ;
}
