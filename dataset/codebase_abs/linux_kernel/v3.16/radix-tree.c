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
if ( ! ( V_5 & V_21 ) && ! F_20 () ) {
struct V_22 * V_23 ;
V_23 = F_21 ( & V_24 ) ;
if ( V_23 -> V_25 ) {
V_20 = V_23 -> V_26 [ V_23 -> V_25 - 1 ] ;
V_23 -> V_26 [ V_23 -> V_25 - 1 ] = NULL ;
V_23 -> V_25 -- ;
}
F_22 ( V_20 ) ;
}
if ( V_20 == NULL )
V_20 = F_23 ( V_27 , V_5 ) ;
F_24 ( F_25 ( V_20 ) ) ;
return V_20 ;
}
static void F_26 ( struct V_28 * V_29 )
{
struct V_7 * V_8 =
F_27 ( V_29 , struct V_7 , V_28 ) ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
F_6 ( V_8 , V_30 , 0 ) ;
V_8 -> V_32 [ 0 ] = NULL ;
V_8 -> V_33 = 0 ;
F_28 ( V_27 , V_8 ) ;
}
static inline void
F_29 ( struct V_7 * V_8 )
{
F_30 ( & V_8 -> V_28 , F_26 ) ;
}
static int F_31 ( T_1 V_5 )
{
struct V_22 * V_23 ;
struct V_7 * V_8 ;
int V_20 = - V_34 ;
F_32 () ;
V_23 = F_21 ( & V_24 ) ;
while ( V_23 -> V_25 < F_33 ( V_23 -> V_26 ) ) {
F_34 () ;
V_8 = F_23 ( V_27 , V_5 ) ;
if ( V_8 == NULL )
goto V_35;
F_32 () ;
V_23 = F_21 ( & V_24 ) ;
if ( V_23 -> V_25 < F_33 ( V_23 -> V_26 ) )
V_23 -> V_26 [ V_23 -> V_25 ++ ] = V_8 ;
else
F_28 ( V_27 , V_8 ) ;
}
V_20 = 0 ;
V_35:
return V_20 ;
}
int V_22 ( T_1 V_5 )
{
F_35 ( ! ( V_5 & V_21 ) ) ;
return F_31 ( V_5 ) ;
}
int F_36 ( T_1 V_5 )
{
if ( V_5 & V_21 )
return F_31 ( V_5 ) ;
F_32 () ;
return 0 ;
}
static inline unsigned long F_37 ( unsigned int V_36 )
{
return V_37 [ V_36 ] ;
}
static int F_38 ( struct V_3 * V_4 , unsigned long V_38 )
{
struct V_7 * V_8 ;
struct V_7 * V_39 ;
unsigned int V_36 ;
int V_9 ;
V_36 = V_4 -> V_36 + 1 ;
while ( V_38 > F_37 ( V_36 ) )
V_36 ++ ;
if ( V_4 -> V_40 == NULL ) {
V_4 -> V_36 = V_36 ;
goto V_35;
}
do {
unsigned int V_41 ;
if ( ! ( V_8 = F_19 ( V_4 ) ) )
return - V_34 ;
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ ) {
if ( F_13 ( V_4 , V_9 ) )
F_4 ( V_8 , V_9 , 0 ) ;
}
V_41 = V_4 -> V_36 + 1 ;
F_24 ( V_41 & ~ V_42 ) ;
V_8 -> V_43 = V_41 ;
V_8 -> V_33 = 1 ;
V_8 -> V_44 = NULL ;
V_39 = V_4 -> V_40 ;
if ( V_41 > 1 ) {
V_39 = F_2 ( V_39 ) ;
V_39 -> V_44 = V_8 ;
}
V_8 -> V_32 [ 0 ] = V_39 ;
V_8 = F_1 ( V_8 ) ;
F_39 ( V_4 -> V_40 , V_8 ) ;
V_4 -> V_36 = V_41 ;
} while ( V_36 > V_4 -> V_36 );
V_35:
return 0 ;
}
int F_40 ( struct V_3 * V_4 , unsigned long V_38 ,
struct V_7 * * V_45 , void * * * V_46 )
{
struct V_7 * V_8 = NULL , * V_39 ;
unsigned int V_36 , V_47 , V_10 ;
int error ;
if ( V_38 > F_37 ( V_4 -> V_36 ) ) {
error = F_38 ( V_4 , V_38 ) ;
if ( error )
return error ;
}
V_39 = F_2 ( V_4 -> V_40 ) ;
V_36 = V_4 -> V_36 ;
V_47 = ( V_36 - 1 ) * V_48 ;
V_10 = 0 ;
while ( V_36 > 0 ) {
if ( V_39 == NULL ) {
if ( ! ( V_39 = F_19 ( V_4 ) ) )
return - V_34 ;
V_39 -> V_43 = V_36 ;
V_39 -> V_44 = V_8 ;
if ( V_8 ) {
F_39 ( V_8 -> V_32 [ V_10 ] , V_39 ) ;
V_8 -> V_33 ++ ;
V_39 -> V_43 |= V_10 << V_49 ;
} else
F_39 ( V_4 -> V_40 , F_1 ( V_39 ) ) ;
}
V_10 = ( V_38 >> V_47 ) & V_50 ;
V_8 = V_39 ;
V_39 = V_8 -> V_32 [ V_10 ] ;
V_47 -= V_48 ;
V_36 -- ;
}
if ( V_45 )
* V_45 = V_8 ;
if ( V_46 )
* V_46 = V_8 ? V_8 -> V_32 + V_10 : ( void * * ) & V_4 -> V_40 ;
return 0 ;
}
int F_41 ( struct V_3 * V_4 ,
unsigned long V_38 , void * V_51 )
{
struct V_7 * V_8 ;
void * * V_39 ;
int error ;
F_24 ( F_25 ( V_51 ) ) ;
error = F_40 ( V_4 , V_38 , & V_8 , & V_39 ) ;
if ( error )
return error ;
if ( * V_39 != NULL )
return - V_52 ;
F_39 ( * V_39 , V_51 ) ;
if ( V_8 ) {
V_8 -> V_33 ++ ;
F_24 ( F_8 ( V_8 , 0 , V_38 & V_50 ) ) ;
F_24 ( F_8 ( V_8 , 1 , V_38 & V_50 ) ) ;
} else {
F_24 ( F_13 ( V_4 , 0 ) ) ;
F_24 ( F_13 ( V_4 , 1 ) ) ;
}
return 0 ;
}
void * F_42 ( struct V_3 * V_4 , unsigned long V_38 ,
struct V_7 * * V_45 , void * * * V_46 )
{
struct V_7 * V_8 , * V_44 ;
unsigned int V_36 , V_47 ;
void * * V_39 ;
V_8 = F_43 ( V_4 -> V_40 ) ;
if ( V_8 == NULL )
return NULL ;
if ( ! F_25 ( V_8 ) ) {
if ( V_38 > 0 )
return NULL ;
if ( V_45 )
* V_45 = NULL ;
if ( V_46 )
* V_46 = ( void * * ) & V_4 -> V_40 ;
return V_8 ;
}
V_8 = F_2 ( V_8 ) ;
V_36 = V_8 -> V_43 & V_42 ;
if ( V_38 > F_37 ( V_36 ) )
return NULL ;
V_47 = ( V_36 - 1 ) * V_48 ;
do {
V_44 = V_8 ;
V_39 = V_8 -> V_32 + ( ( V_38 >> V_47 ) & V_50 ) ;
V_8 = F_43 ( * V_39 ) ;
if ( V_8 == NULL )
return NULL ;
V_47 -= V_48 ;
V_36 -- ;
} while ( V_36 > 0 );
if ( V_45 )
* V_45 = V_44 ;
if ( V_46 )
* V_46 = V_39 ;
return V_8 ;
}
void * * F_44 ( struct V_3 * V_4 , unsigned long V_38 )
{
void * * V_39 ;
if ( ! F_42 ( V_4 , V_38 , NULL , & V_39 ) )
return NULL ;
return V_39 ;
}
void * F_45 ( struct V_3 * V_4 , unsigned long V_38 )
{
return F_42 ( V_4 , V_38 , NULL , NULL ) ;
}
void * F_46 ( struct V_3 * V_4 ,
unsigned long V_38 , unsigned int V_9 )
{
unsigned int V_36 , V_47 ;
struct V_7 * V_39 ;
V_36 = V_4 -> V_36 ;
F_24 ( V_38 > F_37 ( V_36 ) ) ;
V_39 = F_2 ( V_4 -> V_40 ) ;
V_47 = ( V_36 - 1 ) * V_48 ;
while ( V_36 > 0 ) {
int V_10 ;
V_10 = ( V_38 >> V_47 ) & V_50 ;
if ( ! F_8 ( V_39 , V_9 , V_10 ) )
F_4 ( V_39 , V_9 , V_10 ) ;
V_39 = V_39 -> V_32 [ V_10 ] ;
F_24 ( V_39 == NULL ) ;
V_47 -= V_48 ;
V_36 -- ;
}
if ( V_39 && ! F_13 ( V_4 , V_9 ) )
F_10 ( V_4 , V_9 ) ;
return V_39 ;
}
void * F_47 ( struct V_3 * V_4 ,
unsigned long V_38 , unsigned int V_9 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_39 = NULL ;
unsigned int V_36 , V_47 ;
int V_53 ( V_10 ) ;
V_36 = V_4 -> V_36 ;
if ( V_38 > F_37 ( V_36 ) )
goto V_35;
V_47 = V_36 * V_48 ;
V_39 = F_2 ( V_4 -> V_40 ) ;
while ( V_47 ) {
if ( V_39 == NULL )
goto V_35;
V_47 -= V_48 ;
V_10 = ( V_38 >> V_47 ) & V_50 ;
V_8 = V_39 ;
V_39 = V_39 -> V_32 [ V_10 ] ;
}
if ( V_39 == NULL )
goto V_35;
while ( V_8 ) {
if ( ! F_8 ( V_8 , V_9 , V_10 ) )
goto V_35;
F_6 ( V_8 , V_9 , V_10 ) ;
if ( F_14 ( V_8 , V_9 ) )
goto V_35;
V_38 >>= V_48 ;
V_10 = V_38 & V_50 ;
V_8 = V_8 -> V_44 ;
}
if ( F_13 ( V_4 , V_9 ) )
F_11 ( V_4 , V_9 ) ;
V_35:
return V_39 ;
}
int F_48 ( struct V_3 * V_4 ,
unsigned long V_38 , unsigned int V_9 )
{
unsigned int V_36 , V_47 ;
struct V_7 * V_8 ;
if ( ! F_13 ( V_4 , V_9 ) )
return 0 ;
V_8 = F_43 ( V_4 -> V_40 ) ;
if ( V_8 == NULL )
return 0 ;
if ( ! F_25 ( V_8 ) )
return ( V_38 == 0 ) ;
V_8 = F_2 ( V_8 ) ;
V_36 = V_8 -> V_43 & V_42 ;
if ( V_38 > F_37 ( V_36 ) )
return 0 ;
V_47 = ( V_36 - 1 ) * V_48 ;
for ( ; ; ) {
int V_10 ;
if ( V_8 == NULL )
return 0 ;
V_10 = ( V_38 >> V_47 ) & V_50 ;
if ( ! F_8 ( V_8 , V_9 , V_10 ) )
return 0 ;
if ( V_36 == 1 )
return 1 ;
V_8 = F_43 ( V_8 -> V_32 [ V_10 ] ) ;
V_47 -= V_48 ;
V_36 -- ;
}
}
void * * F_49 ( struct V_3 * V_4 ,
struct V_54 * V_55 , unsigned V_56 )
{
unsigned V_47 , V_9 = V_56 & V_57 ;
struct V_7 * V_40 , * V_8 ;
unsigned long V_38 , V_10 , V_36 ;
if ( ( V_56 & V_58 ) && ! F_13 ( V_4 , V_9 ) )
return NULL ;
V_38 = V_55 -> V_59 ;
if ( ! V_38 && V_55 -> V_38 )
return NULL ;
V_40 = F_43 ( V_4 -> V_40 ) ;
if ( F_25 ( V_40 ) ) {
V_40 = F_2 ( V_40 ) ;
} else if ( V_40 && ! V_38 ) {
V_55 -> V_38 = 0 ;
V_55 -> V_59 = 1 ;
V_55 -> V_11 = 1 ;
return ( void * * ) & V_4 -> V_40 ;
} else
return NULL ;
V_60:
V_36 = V_40 -> V_43 & V_42 ;
V_47 = ( V_36 - 1 ) * V_48 ;
V_10 = V_38 >> V_47 ;
if ( V_10 >= V_61 )
return NULL ;
V_8 = V_40 ;
while ( 1 ) {
if ( ( V_56 & V_58 ) ?
! F_9 ( V_10 , V_8 -> V_11 [ V_9 ] ) :
! V_8 -> V_32 [ V_10 ] ) {
if ( V_56 & V_62 )
return NULL ;
if ( V_56 & V_58 )
V_10 = F_15 (
V_8 -> V_11 [ V_9 ] ,
V_61 ,
V_10 + 1 ) ;
else
while ( ++ V_10 < V_61 ) {
if ( V_8 -> V_32 [ V_10 ] )
break;
}
V_38 &= ~ ( ( V_61 << V_47 ) - 1 ) ;
V_38 += V_10 << V_47 ;
if ( ! V_38 )
return NULL ;
if ( V_10 == V_61 )
goto V_60;
}
if ( ! V_47 )
break;
V_8 = F_43 ( V_8 -> V_32 [ V_10 ] ) ;
if ( V_8 == NULL )
goto V_60;
V_47 -= V_48 ;
V_10 = ( V_38 >> V_47 ) & V_50 ;
}
V_55 -> V_38 = V_38 ;
V_55 -> V_59 = ( V_38 | V_50 ) + 1 ;
if ( V_56 & V_58 ) {
unsigned V_63 , V_64 ;
V_63 = V_10 / V_19 ;
V_64 = V_10 % V_19 ;
V_55 -> V_11 = V_8 -> V_11 [ V_9 ] [ V_63 ] >> V_64 ;
if ( V_63 < V_15 - 1 ) {
if ( V_64 )
V_55 -> V_11 |= V_8 -> V_11 [ V_9 ] [ V_63 + 1 ] <<
( V_19 - V_64 ) ;
V_55 -> V_59 = V_38 + V_19 ;
}
}
return V_8 -> V_32 + V_10 ;
}
unsigned long F_50 ( struct V_3 * V_4 ,
unsigned long * V_65 , unsigned long V_66 ,
unsigned long V_67 ,
unsigned int V_68 , unsigned int V_69 )
{
unsigned int V_36 = V_4 -> V_36 ;
struct V_7 * V_8 = NULL ;
struct V_7 * V_39 ;
unsigned int V_47 ;
unsigned long V_70 = 0 ;
unsigned long V_38 = * V_65 ;
V_66 = F_51 ( V_66 , F_37 ( V_36 ) ) ;
if ( V_38 > V_66 )
return 0 ;
if ( ! V_67 )
return 0 ;
if ( ! F_13 ( V_4 , V_68 ) ) {
* V_65 = V_66 + 1 ;
return 0 ;
}
if ( V_36 == 0 ) {
* V_65 = V_66 + 1 ;
F_10 ( V_4 , V_69 ) ;
return 1 ;
}
V_47 = ( V_36 - 1 ) * V_48 ;
V_39 = F_2 ( V_4 -> V_40 ) ;
for (; ; ) {
unsigned long V_71 ;
int V_10 ;
V_10 = ( V_38 >> V_47 ) & V_50 ;
if ( ! V_39 -> V_32 [ V_10 ] )
goto V_72;
if ( ! F_8 ( V_39 , V_68 , V_10 ) )
goto V_72;
if ( V_47 ) {
V_47 -= V_48 ;
V_8 = V_39 ;
V_39 = V_39 -> V_32 [ V_10 ] ;
continue;
}
V_70 ++ ;
F_4 ( V_39 , V_69 , V_10 ) ;
V_71 = V_38 ;
while ( V_8 ) {
V_71 >>= V_48 ;
V_10 = V_71 & V_50 ;
if ( F_8 ( V_8 , V_69 , V_10 ) )
break;
F_4 ( V_8 , V_69 , V_10 ) ;
V_8 = V_8 -> V_44 ;
}
V_8 = NULL ;
V_72:
V_38 = ( ( V_38 >> V_47 ) + 1 ) << V_47 ;
if ( V_38 > V_66 || ! V_38 )
break;
if ( V_70 >= V_67 )
break;
while ( ( ( V_38 >> V_47 ) & V_50 ) == 0 ) {
V_39 = V_39 -> V_44 ;
V_47 += V_48 ;
}
}
if ( V_70 > 0 )
F_10 ( V_4 , V_69 ) ;
* V_65 = V_38 ;
return V_70 ;
}
unsigned int
F_52 ( struct V_3 * V_4 , void * * V_73 ,
unsigned long V_74 , unsigned int V_75 )
{
struct V_54 V_55 ;
void * * V_39 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_75 ) )
return 0 ;
F_54 (slot, root, &iter, first_index) {
V_73 [ V_20 ] = F_2 ( F_43 ( * V_39 ) ) ;
if ( ! V_73 [ V_20 ] )
continue;
if ( ++ V_20 == V_75 )
break;
}
return V_20 ;
}
unsigned int
F_55 ( struct V_3 * V_4 ,
void * * * V_73 , unsigned long * V_76 ,
unsigned long V_74 , unsigned int V_75 )
{
struct V_54 V_55 ;
void * * V_39 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_75 ) )
return 0 ;
F_54 (slot, root, &iter, first_index) {
V_73 [ V_20 ] = V_39 ;
if ( V_76 )
V_76 [ V_20 ] = V_55 . V_38 ;
if ( ++ V_20 == V_75 )
break;
}
return V_20 ;
}
unsigned int
F_56 ( struct V_3 * V_4 , void * * V_73 ,
unsigned long V_74 , unsigned int V_75 ,
unsigned int V_9 )
{
struct V_54 V_55 ;
void * * V_39 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_75 ) )
return 0 ;
F_57 (slot, root, &iter, first_index, tag) {
V_73 [ V_20 ] = F_2 ( F_43 ( * V_39 ) ) ;
if ( ! V_73 [ V_20 ] )
continue;
if ( ++ V_20 == V_75 )
break;
}
return V_20 ;
}
unsigned int
F_58 ( struct V_3 * V_4 , void * * * V_73 ,
unsigned long V_74 , unsigned int V_75 ,
unsigned int V_9 )
{
struct V_54 V_55 ;
void * * V_39 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_75 ) )
return 0 ;
F_57 (slot, root, &iter, first_index, tag) {
V_73 [ V_20 ] = V_39 ;
if ( ++ V_20 == V_75 )
break;
}
return V_20 ;
}
static unsigned long F_59 ( struct V_7 * V_39 , void * V_51 ,
unsigned long V_38 , unsigned long * V_77 )
{
unsigned int V_47 , V_36 ;
unsigned long V_30 ;
V_36 = V_39 -> V_43 & V_42 ;
V_47 = ( V_36 - 1 ) * V_48 ;
for ( ; V_36 > 1 ; V_36 -- ) {
V_30 = ( V_38 >> V_47 ) & V_50 ;
for (; ; ) {
if ( V_39 -> V_32 [ V_30 ] != NULL )
break;
V_38 &= ~ ( ( 1UL << V_47 ) - 1 ) ;
V_38 += 1UL << V_47 ;
if ( V_38 == 0 )
goto V_35;
V_30 ++ ;
if ( V_30 == V_61 )
goto V_35;
}
V_47 -= V_48 ;
V_39 = F_43 ( V_39 -> V_32 [ V_30 ] ) ;
if ( V_39 == NULL )
goto V_35;
}
for ( V_30 = 0 ; V_30 < V_61 ; V_30 ++ ) {
if ( V_39 -> V_32 [ V_30 ] == V_51 ) {
* V_77 = V_38 + V_30 ;
V_38 = 0 ;
goto V_35;
}
}
V_38 += V_61 ;
V_35:
return V_38 ;
}
unsigned long F_60 ( struct V_3 * V_4 , void * V_51 )
{
struct V_7 * V_8 ;
unsigned long V_78 ;
unsigned long V_79 = 0 ;
unsigned long V_77 = - 1 ;
do {
F_61 () ;
V_8 = F_43 ( V_4 -> V_40 ) ;
if ( ! F_25 ( V_8 ) ) {
F_62 () ;
if ( V_8 == V_51 )
V_77 = 0 ;
break;
}
V_8 = F_2 ( V_8 ) ;
V_78 = F_37 ( V_8 -> V_43 &
V_42 ) ;
if ( V_79 > V_78 ) {
F_62 () ;
break;
}
V_79 = F_59 ( V_8 , V_51 , V_79 , & V_77 ) ;
F_62 () ;
F_63 () ;
} while ( V_79 != 0 && V_79 <= V_78 );
return V_77 ;
}
unsigned long F_60 ( struct V_3 * V_4 , void * V_51 )
{
return - 1 ;
}
static inline void F_64 ( struct V_3 * V_4 )
{
while ( V_4 -> V_36 > 0 ) {
struct V_7 * V_80 = V_4 -> V_40 ;
struct V_7 * V_39 ;
F_24 ( ! F_25 ( V_80 ) ) ;
V_80 = F_2 ( V_80 ) ;
if ( V_80 -> V_33 != 1 )
break;
if ( ! V_80 -> V_32 [ 0 ] )
break;
V_39 = V_80 -> V_32 [ 0 ] ;
if ( V_4 -> V_36 > 1 ) {
V_39 -> V_44 = NULL ;
V_39 = F_1 ( V_39 ) ;
}
V_4 -> V_40 = V_39 ;
V_4 -> V_36 -- ;
if ( V_4 -> V_36 == 0 )
* ( ( unsigned long * ) & V_80 -> V_32 [ 0 ] ) |=
V_2 ;
F_29 ( V_80 ) ;
}
}
bool F_65 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
bool V_81 = false ;
do {
struct V_7 * V_44 ;
if ( V_8 -> V_33 ) {
if ( V_8 == F_2 ( V_4 -> V_40 ) ) {
F_64 ( V_4 ) ;
if ( V_4 -> V_36 == 0 )
V_81 = true ;
}
return V_81 ;
}
V_44 = V_8 -> V_44 ;
if ( V_44 ) {
unsigned int V_10 ;
V_10 = V_8 -> V_43 >> V_49 ;
V_44 -> V_32 [ V_10 ] = NULL ;
V_44 -> V_33 -- ;
} else {
F_12 ( V_4 ) ;
V_4 -> V_36 = 0 ;
V_4 -> V_40 = NULL ;
}
F_29 ( V_8 ) ;
V_81 = true ;
V_8 = V_44 ;
} while ( V_8 );
return V_81 ;
}
void * F_66 ( struct V_3 * V_4 ,
unsigned long V_38 , void * V_51 )
{
struct V_7 * V_8 ;
unsigned int V_10 ;
void * * V_39 ;
void * V_82 ;
int V_9 ;
V_82 = F_42 ( V_4 , V_38 , & V_8 , & V_39 ) ;
if ( ! V_82 )
return NULL ;
if ( V_51 && V_82 != V_51 )
return NULL ;
if ( ! V_8 ) {
F_12 ( V_4 ) ;
V_4 -> V_40 = NULL ;
return V_82 ;
}
V_10 = V_38 & V_50 ;
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ ) {
if ( F_8 ( V_8 , V_9 , V_10 ) )
F_47 ( V_4 , V_38 , V_9 ) ;
}
V_8 -> V_32 [ V_10 ] = NULL ;
V_8 -> V_33 -- ;
F_65 ( V_4 , V_8 ) ;
return V_82 ;
}
void * F_67 ( struct V_3 * V_4 , unsigned long V_38 )
{
return F_66 ( V_4 , V_38 , NULL ) ;
}
int F_68 ( struct V_3 * V_4 , unsigned int V_9 )
{
return F_13 ( V_4 , V_9 ) ;
}
static void
F_69 ( void * V_83 )
{
struct V_7 * V_8 = V_83 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_70 ( & V_8 -> V_84 ) ;
}
static T_3 unsigned long F_71 ( unsigned int V_36 )
{
unsigned int V_85 = V_36 * V_48 ;
int V_47 = V_86 - V_85 ;
if ( V_47 < 0 )
return ~ 0UL ;
if ( V_47 >= V_19 )
return 0UL ;
return ~ 0UL >> V_47 ;
}
static T_3 void F_72 ( void )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < F_33 ( V_37 ) ; V_30 ++ )
V_37 [ V_30 ] = F_71 ( V_30 ) ;
}
static int F_73 ( struct V_87 * V_88 ,
unsigned long V_89 ,
void * V_90 )
{
int V_91 = ( long ) V_90 ;
struct V_22 * V_23 ;
if ( V_89 == V_92 || V_89 == V_93 ) {
V_23 = & F_74 ( V_24 , V_91 ) ;
while ( V_23 -> V_25 ) {
F_28 ( V_27 ,
V_23 -> V_26 [ V_23 -> V_25 - 1 ] ) ;
V_23 -> V_26 [ V_23 -> V_25 - 1 ] = NULL ;
V_23 -> V_25 -- ;
}
}
return V_94 ;
}
void T_3 F_75 ( void )
{
V_27 = F_76 ( L_1 ,
sizeof( struct V_7 ) , 0 ,
V_95 | V_96 ,
F_69 ) ;
F_72 () ;
F_77 ( F_73 , 0 ) ;
}
