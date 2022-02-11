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
if ( ! ( V_5 & V_21 ) ) {
struct V_22 * V_23 ;
V_23 = & F_20 ( V_24 ) ;
if ( V_23 -> V_25 ) {
V_20 = V_23 -> V_26 [ V_23 -> V_25 - 1 ] ;
V_23 -> V_26 [ V_23 -> V_25 - 1 ] = NULL ;
V_23 -> V_25 -- ;
}
}
if ( V_20 == NULL )
V_20 = F_21 ( V_27 , V_5 ) ;
F_22 ( F_23 ( V_20 ) ) ;
return V_20 ;
}
static void F_24 ( struct V_28 * V_29 )
{
struct V_7 * V_8 =
F_25 ( V_29 , struct V_7 , V_28 ) ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
F_6 ( V_8 , V_30 , 0 ) ;
V_8 -> V_32 [ 0 ] = NULL ;
V_8 -> V_33 = 0 ;
F_26 ( V_27 , V_8 ) ;
}
static inline void
F_27 ( struct V_7 * V_8 )
{
F_28 ( & V_8 -> V_28 , F_24 ) ;
}
int V_22 ( T_1 V_5 )
{
struct V_22 * V_23 ;
struct V_7 * V_8 ;
int V_20 = - V_34 ;
F_29 () ;
V_23 = & F_20 ( V_24 ) ;
while ( V_23 -> V_25 < F_30 ( V_23 -> V_26 ) ) {
F_31 () ;
V_8 = F_21 ( V_27 , V_5 ) ;
if ( V_8 == NULL )
goto V_35;
F_29 () ;
V_23 = & F_20 ( V_24 ) ;
if ( V_23 -> V_25 < F_30 ( V_23 -> V_26 ) )
V_23 -> V_26 [ V_23 -> V_25 ++ ] = V_8 ;
else
F_26 ( V_27 , V_8 ) ;
}
V_20 = 0 ;
V_35:
return V_20 ;
}
static inline unsigned long F_32 ( unsigned int V_36 )
{
return V_37 [ V_36 ] ;
}
static int F_33 ( struct V_3 * V_4 , unsigned long V_38 )
{
struct V_7 * V_8 ;
struct V_7 * V_39 ;
unsigned int V_36 ;
int V_9 ;
V_36 = V_4 -> V_36 + 1 ;
while ( V_38 > F_32 ( V_36 ) )
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
V_8 -> V_36 = V_41 ;
V_8 -> V_33 = 1 ;
V_8 -> V_42 = NULL ;
V_39 = V_4 -> V_40 ;
if ( V_41 > 1 ) {
V_39 = F_2 ( V_39 ) ;
V_39 -> V_42 = V_8 ;
}
V_8 -> V_32 [ 0 ] = V_39 ;
V_8 = F_1 ( V_8 ) ;
F_34 ( V_4 -> V_40 , V_8 ) ;
V_4 -> V_36 = V_41 ;
} while ( V_36 > V_4 -> V_36 );
V_35:
return 0 ;
}
int F_35 ( struct V_3 * V_4 ,
unsigned long V_38 , void * V_43 )
{
struct V_7 * V_8 = NULL , * V_39 ;
unsigned int V_36 , V_44 ;
int V_10 ;
int error ;
F_22 ( F_23 ( V_43 ) ) ;
if ( V_38 > F_32 ( V_4 -> V_36 ) ) {
error = F_33 ( V_4 , V_38 ) ;
if ( error )
return error ;
}
V_39 = F_2 ( V_4 -> V_40 ) ;
V_36 = V_4 -> V_36 ;
V_44 = ( V_36 - 1 ) * V_45 ;
V_10 = 0 ;
while ( V_36 > 0 ) {
if ( V_39 == NULL ) {
if ( ! ( V_39 = F_19 ( V_4 ) ) )
return - V_34 ;
V_39 -> V_36 = V_36 ;
V_39 -> V_42 = V_8 ;
if ( V_8 ) {
F_34 ( V_8 -> V_32 [ V_10 ] , V_39 ) ;
V_8 -> V_33 ++ ;
} else
F_34 ( V_4 -> V_40 , F_1 ( V_39 ) ) ;
}
V_10 = ( V_38 >> V_44 ) & V_46 ;
V_8 = V_39 ;
V_39 = V_8 -> V_32 [ V_10 ] ;
V_44 -= V_45 ;
V_36 -- ;
}
if ( V_39 != NULL )
return - V_47 ;
if ( V_8 ) {
V_8 -> V_33 ++ ;
F_34 ( V_8 -> V_32 [ V_10 ] , V_43 ) ;
F_22 ( F_8 ( V_8 , 0 , V_10 ) ) ;
F_22 ( F_8 ( V_8 , 1 , V_10 ) ) ;
} else {
F_34 ( V_4 -> V_40 , V_43 ) ;
F_22 ( F_13 ( V_4 , 0 ) ) ;
F_22 ( F_13 ( V_4 , 1 ) ) ;
}
return 0 ;
}
static void * F_36 ( struct V_3 * V_4 ,
unsigned long V_38 , int V_48 )
{
unsigned int V_36 , V_44 ;
struct V_7 * V_8 , * * V_39 ;
V_8 = F_37 ( V_4 -> V_40 ) ;
if ( V_8 == NULL )
return NULL ;
if ( ! F_23 ( V_8 ) ) {
if ( V_38 > 0 )
return NULL ;
return V_48 ? ( void * ) & V_4 -> V_40 : V_8 ;
}
V_8 = F_2 ( V_8 ) ;
V_36 = V_8 -> V_36 ;
if ( V_38 > F_32 ( V_36 ) )
return NULL ;
V_44 = ( V_36 - 1 ) * V_45 ;
do {
V_39 = (struct V_7 * * )
( V_8 -> V_32 + ( ( V_38 >> V_44 ) & V_46 ) ) ;
V_8 = F_37 ( * V_39 ) ;
if ( V_8 == NULL )
return NULL ;
V_44 -= V_45 ;
V_36 -- ;
} while ( V_36 > 0 );
return V_48 ? ( void * ) V_39 : F_2 ( V_8 ) ;
}
void * * F_38 ( struct V_3 * V_4 , unsigned long V_38 )
{
return ( void * * ) F_36 ( V_4 , V_38 , 1 ) ;
}
void * F_39 ( struct V_3 * V_4 , unsigned long V_38 )
{
return F_36 ( V_4 , V_38 , 0 ) ;
}
void * F_40 ( struct V_3 * V_4 ,
unsigned long V_38 , unsigned int V_9 )
{
unsigned int V_36 , V_44 ;
struct V_7 * V_39 ;
V_36 = V_4 -> V_36 ;
F_22 ( V_38 > F_32 ( V_36 ) ) ;
V_39 = F_2 ( V_4 -> V_40 ) ;
V_44 = ( V_36 - 1 ) * V_45 ;
while ( V_36 > 0 ) {
int V_10 ;
V_10 = ( V_38 >> V_44 ) & V_46 ;
if ( ! F_8 ( V_39 , V_9 , V_10 ) )
F_4 ( V_39 , V_9 , V_10 ) ;
V_39 = V_39 -> V_32 [ V_10 ] ;
F_22 ( V_39 == NULL ) ;
V_44 -= V_45 ;
V_36 -- ;
}
if ( V_39 && ! F_13 ( V_4 , V_9 ) )
F_10 ( V_4 , V_9 ) ;
return V_39 ;
}
void * F_41 ( struct V_3 * V_4 ,
unsigned long V_38 , unsigned int V_9 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_39 = NULL ;
unsigned int V_36 , V_44 ;
int V_49 ( V_10 ) ;
V_36 = V_4 -> V_36 ;
if ( V_38 > F_32 ( V_36 ) )
goto V_35;
V_44 = V_36 * V_45 ;
V_39 = F_2 ( V_4 -> V_40 ) ;
while ( V_44 ) {
if ( V_39 == NULL )
goto V_35;
V_44 -= V_45 ;
V_10 = ( V_38 >> V_44 ) & V_46 ;
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
V_38 >>= V_45 ;
V_10 = V_38 & V_46 ;
V_8 = V_8 -> V_42 ;
}
if ( F_13 ( V_4 , V_9 ) )
F_11 ( V_4 , V_9 ) ;
V_35:
return V_39 ;
}
int F_42 ( struct V_3 * V_4 ,
unsigned long V_38 , unsigned int V_9 )
{
unsigned int V_36 , V_44 ;
struct V_7 * V_8 ;
if ( ! F_13 ( V_4 , V_9 ) )
return 0 ;
V_8 = F_37 ( V_4 -> V_40 ) ;
if ( V_8 == NULL )
return 0 ;
if ( ! F_23 ( V_8 ) )
return ( V_38 == 0 ) ;
V_8 = F_2 ( V_8 ) ;
V_36 = V_8 -> V_36 ;
if ( V_38 > F_32 ( V_36 ) )
return 0 ;
V_44 = ( V_36 - 1 ) * V_45 ;
for ( ; ; ) {
int V_10 ;
if ( V_8 == NULL )
return 0 ;
V_10 = ( V_38 >> V_44 ) & V_46 ;
if ( ! F_8 ( V_8 , V_9 , V_10 ) )
return 0 ;
if ( V_36 == 1 )
return 1 ;
V_8 = F_37 ( V_8 -> V_32 [ V_10 ] ) ;
V_44 -= V_45 ;
V_36 -- ;
}
}
void * * F_43 ( struct V_3 * V_4 ,
struct V_50 * V_51 , unsigned V_52 )
{
unsigned V_44 , V_9 = V_52 & V_53 ;
struct V_7 * V_40 , * V_8 ;
unsigned long V_38 , V_10 ;
if ( ( V_52 & V_54 ) && ! F_13 ( V_4 , V_9 ) )
return NULL ;
V_38 = V_51 -> V_55 ;
if ( ! V_38 && V_51 -> V_38 )
return NULL ;
V_40 = F_37 ( V_4 -> V_40 ) ;
if ( F_23 ( V_40 ) ) {
V_40 = F_2 ( V_40 ) ;
} else if ( V_40 && ! V_38 ) {
V_51 -> V_38 = 0 ;
V_51 -> V_55 = 1 ;
V_51 -> V_11 = 1 ;
return ( void * * ) & V_4 -> V_40 ;
} else
return NULL ;
V_56:
V_44 = ( V_40 -> V_36 - 1 ) * V_45 ;
V_10 = V_38 >> V_44 ;
if ( V_10 >= V_57 )
return NULL ;
V_8 = V_40 ;
while ( 1 ) {
if ( ( V_52 & V_54 ) ?
! F_9 ( V_10 , V_8 -> V_11 [ V_9 ] ) :
! V_8 -> V_32 [ V_10 ] ) {
if ( V_52 & V_58 )
return NULL ;
if ( V_52 & V_54 )
V_10 = F_15 (
V_8 -> V_11 [ V_9 ] ,
V_57 ,
V_10 + 1 ) ;
else
while ( ++ V_10 < V_57 ) {
if ( V_8 -> V_32 [ V_10 ] )
break;
}
V_38 &= ~ ( ( V_57 << V_44 ) - 1 ) ;
V_38 += V_10 << V_44 ;
if ( ! V_38 )
return NULL ;
if ( V_10 == V_57 )
goto V_56;
}
if ( ! V_44 )
break;
V_8 = F_37 ( V_8 -> V_32 [ V_10 ] ) ;
if ( V_8 == NULL )
goto V_56;
V_44 -= V_45 ;
V_10 = ( V_38 >> V_44 ) & V_46 ;
}
V_51 -> V_38 = V_38 ;
V_51 -> V_55 = ( V_38 | V_46 ) + 1 ;
if ( V_52 & V_54 ) {
unsigned V_59 , V_60 ;
V_59 = V_10 / V_19 ;
V_60 = V_10 % V_19 ;
V_51 -> V_11 = V_8 -> V_11 [ V_9 ] [ V_59 ] >> V_60 ;
if ( V_59 < V_15 - 1 ) {
if ( V_60 )
V_51 -> V_11 |= V_8 -> V_11 [ V_9 ] [ V_59 + 1 ] <<
( V_19 - V_60 ) ;
V_51 -> V_55 = V_38 + V_19 ;
}
}
return V_8 -> V_32 + V_10 ;
}
unsigned long F_44 ( struct V_3 * V_4 ,
unsigned long * V_61 , unsigned long V_62 ,
unsigned long V_63 ,
unsigned int V_64 , unsigned int V_65 )
{
unsigned int V_36 = V_4 -> V_36 ;
struct V_7 * V_8 = NULL ;
struct V_7 * V_39 ;
unsigned int V_44 ;
unsigned long V_66 = 0 ;
unsigned long V_38 = * V_61 ;
V_62 = F_45 ( V_62 , F_32 ( V_36 ) ) ;
if ( V_38 > V_62 )
return 0 ;
if ( ! V_63 )
return 0 ;
if ( ! F_13 ( V_4 , V_64 ) ) {
* V_61 = V_62 + 1 ;
return 0 ;
}
if ( V_36 == 0 ) {
* V_61 = V_62 + 1 ;
F_10 ( V_4 , V_65 ) ;
return 1 ;
}
V_44 = ( V_36 - 1 ) * V_45 ;
V_39 = F_2 ( V_4 -> V_40 ) ;
for (; ; ) {
unsigned long V_67 ;
int V_10 ;
V_10 = ( V_38 >> V_44 ) & V_46 ;
if ( ! V_39 -> V_32 [ V_10 ] )
goto V_68;
if ( ! F_8 ( V_39 , V_64 , V_10 ) )
goto V_68;
if ( V_44 ) {
V_44 -= V_45 ;
V_8 = V_39 ;
V_39 = V_39 -> V_32 [ V_10 ] ;
continue;
}
V_66 ++ ;
F_4 ( V_39 , V_65 , V_10 ) ;
V_67 = V_38 ;
while ( V_8 ) {
V_67 >>= V_45 ;
V_10 = V_67 & V_46 ;
if ( F_8 ( V_8 , V_65 , V_10 ) )
break;
F_4 ( V_8 , V_65 , V_10 ) ;
V_8 = V_8 -> V_42 ;
}
V_8 = NULL ;
V_68:
V_38 = ( ( V_38 >> V_44 ) + 1 ) << V_44 ;
if ( V_38 > V_62 || ! V_38 )
break;
if ( V_66 >= V_63 )
break;
while ( ( ( V_38 >> V_44 ) & V_46 ) == 0 ) {
V_39 = V_39 -> V_42 ;
V_44 += V_45 ;
}
}
if ( V_66 > 0 )
F_10 ( V_4 , V_65 ) ;
* V_61 = V_38 ;
return V_66 ;
}
unsigned long F_46 ( struct V_3 * V_4 ,
unsigned long V_38 , unsigned long V_69 )
{
unsigned long V_30 ;
for ( V_30 = 0 ; V_30 < V_69 ; V_30 ++ ) {
if ( ! F_39 ( V_4 , V_38 ) )
break;
V_38 ++ ;
if ( V_38 == 0 )
break;
}
return V_38 ;
}
unsigned long F_47 ( struct V_3 * V_4 ,
unsigned long V_38 , unsigned long V_69 )
{
unsigned long V_30 ;
for ( V_30 = 0 ; V_30 < V_69 ; V_30 ++ ) {
if ( ! F_39 ( V_4 , V_38 ) )
break;
V_38 -- ;
if ( V_38 == V_70 )
break;
}
return V_38 ;
}
unsigned int
F_48 ( struct V_3 * V_4 , void * * V_71 ,
unsigned long V_72 , unsigned int V_73 )
{
struct V_50 V_51 ;
void * * V_39 ;
unsigned int V_20 = 0 ;
if ( F_49 ( ! V_73 ) )
return 0 ;
F_50 (slot, root, &iter, first_index) {
V_71 [ V_20 ] = F_2 ( F_37 ( * V_39 ) ) ;
if ( ! V_71 [ V_20 ] )
continue;
if ( ++ V_20 == V_73 )
break;
}
return V_20 ;
}
unsigned int
F_51 ( struct V_3 * V_4 ,
void * * * V_71 , unsigned long * V_74 ,
unsigned long V_72 , unsigned int V_73 )
{
struct V_50 V_51 ;
void * * V_39 ;
unsigned int V_20 = 0 ;
if ( F_49 ( ! V_73 ) )
return 0 ;
F_50 (slot, root, &iter, first_index) {
V_71 [ V_20 ] = V_39 ;
if ( V_74 )
V_74 [ V_20 ] = V_51 . V_38 ;
if ( ++ V_20 == V_73 )
break;
}
return V_20 ;
}
unsigned int
F_52 ( struct V_3 * V_4 , void * * V_71 ,
unsigned long V_72 , unsigned int V_73 ,
unsigned int V_9 )
{
struct V_50 V_51 ;
void * * V_39 ;
unsigned int V_20 = 0 ;
if ( F_49 ( ! V_73 ) )
return 0 ;
F_53 (slot, root, &iter, first_index, tag) {
V_71 [ V_20 ] = F_2 ( F_37 ( * V_39 ) ) ;
if ( ! V_71 [ V_20 ] )
continue;
if ( ++ V_20 == V_73 )
break;
}
return V_20 ;
}
unsigned int
F_54 ( struct V_3 * V_4 , void * * * V_71 ,
unsigned long V_72 , unsigned int V_73 ,
unsigned int V_9 )
{
struct V_50 V_51 ;
void * * V_39 ;
unsigned int V_20 = 0 ;
if ( F_49 ( ! V_73 ) )
return 0 ;
F_53 (slot, root, &iter, first_index, tag) {
V_71 [ V_20 ] = V_39 ;
if ( ++ V_20 == V_73 )
break;
}
return V_20 ;
}
static unsigned long F_55 ( struct V_7 * V_39 , void * V_43 ,
unsigned long V_38 , unsigned long * V_75 )
{
unsigned int V_44 , V_36 ;
unsigned long V_30 ;
V_36 = V_39 -> V_36 ;
V_44 = ( V_36 - 1 ) * V_45 ;
for ( ; V_36 > 1 ; V_36 -- ) {
V_30 = ( V_38 >> V_44 ) & V_46 ;
for (; ; ) {
if ( V_39 -> V_32 [ V_30 ] != NULL )
break;
V_38 &= ~ ( ( 1UL << V_44 ) - 1 ) ;
V_38 += 1UL << V_44 ;
if ( V_38 == 0 )
goto V_35;
V_30 ++ ;
if ( V_30 == V_57 )
goto V_35;
}
V_44 -= V_45 ;
V_39 = F_37 ( V_39 -> V_32 [ V_30 ] ) ;
if ( V_39 == NULL )
goto V_35;
}
for ( V_30 = 0 ; V_30 < V_57 ; V_30 ++ ) {
if ( V_39 -> V_32 [ V_30 ] == V_43 ) {
* V_75 = V_38 + V_30 ;
V_38 = 0 ;
goto V_35;
}
}
V_38 += V_57 ;
V_35:
return V_38 ;
}
unsigned long F_56 ( struct V_3 * V_4 , void * V_43 )
{
struct V_7 * V_8 ;
unsigned long V_76 ;
unsigned long V_77 = 0 ;
unsigned long V_75 = - 1 ;
do {
F_57 () ;
V_8 = F_37 ( V_4 -> V_40 ) ;
if ( ! F_23 ( V_8 ) ) {
F_58 () ;
if ( V_8 == V_43 )
V_75 = 0 ;
break;
}
V_8 = F_2 ( V_8 ) ;
V_76 = F_32 ( V_8 -> V_36 ) ;
if ( V_77 > V_76 )
break;
V_77 = F_55 ( V_8 , V_43 , V_77 , & V_75 ) ;
F_58 () ;
F_59 () ;
} while ( V_77 != 0 && V_77 <= V_76 );
return V_75 ;
}
unsigned long F_56 ( struct V_3 * V_4 , void * V_43 )
{
return - 1 ;
}
static inline void F_60 ( struct V_3 * V_4 )
{
while ( V_4 -> V_36 > 0 ) {
struct V_7 * V_78 = V_4 -> V_40 ;
struct V_7 * V_39 ;
F_22 ( ! F_23 ( V_78 ) ) ;
V_78 = F_2 ( V_78 ) ;
if ( V_78 -> V_33 != 1 )
break;
if ( ! V_78 -> V_32 [ 0 ] )
break;
V_39 = V_78 -> V_32 [ 0 ] ;
if ( V_4 -> V_36 > 1 ) {
V_39 -> V_42 = NULL ;
V_39 = F_1 ( V_39 ) ;
}
V_4 -> V_40 = V_39 ;
V_4 -> V_36 -- ;
if ( V_4 -> V_36 == 0 )
* ( ( unsigned long * ) & V_78 -> V_32 [ 0 ] ) |=
V_2 ;
F_27 ( V_78 ) ;
}
}
void * F_61 ( struct V_3 * V_4 , unsigned long V_38 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_39 = NULL ;
struct V_7 * V_78 ;
unsigned int V_36 , V_44 ;
int V_9 ;
int V_49 ( V_10 ) ;
V_36 = V_4 -> V_36 ;
if ( V_38 > F_32 ( V_36 ) )
goto V_35;
V_39 = V_4 -> V_40 ;
if ( V_36 == 0 ) {
F_12 ( V_4 ) ;
V_4 -> V_40 = NULL ;
goto V_35;
}
V_39 = F_2 ( V_39 ) ;
V_44 = V_36 * V_45 ;
do {
if ( V_39 == NULL )
goto V_35;
V_44 -= V_45 ;
V_10 = ( V_38 >> V_44 ) & V_46 ;
V_8 = V_39 ;
V_39 = V_39 -> V_32 [ V_10 ] ;
} while ( V_44 );
if ( V_39 == NULL )
goto V_35;
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ ) {
if ( F_8 ( V_8 , V_9 , V_10 ) )
F_41 ( V_4 , V_38 , V_9 ) ;
}
V_78 = NULL ;
while ( V_8 ) {
V_8 -> V_32 [ V_10 ] = NULL ;
V_8 -> V_33 -- ;
if ( V_78 )
F_27 ( V_78 ) ;
if ( V_8 -> V_33 ) {
if ( V_8 == F_2 ( V_4 -> V_40 ) )
F_60 ( V_4 ) ;
goto V_35;
}
V_78 = V_8 ;
V_38 >>= V_45 ;
V_10 = V_38 & V_46 ;
V_8 = V_8 -> V_42 ;
}
F_12 ( V_4 ) ;
V_4 -> V_36 = 0 ;
V_4 -> V_40 = NULL ;
if ( V_78 )
F_27 ( V_78 ) ;
V_35:
return V_39 ;
}
int F_62 ( struct V_3 * V_4 , unsigned int V_9 )
{
return F_13 ( V_4 , V_9 ) ;
}
static void
F_63 ( void * V_8 )
{
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
}
static T_3 unsigned long F_64 ( unsigned int V_36 )
{
unsigned int V_79 = V_36 * V_45 ;
int V_44 = V_80 - V_79 ;
if ( V_44 < 0 )
return ~ 0UL ;
if ( V_44 >= V_19 )
return 0UL ;
return ~ 0UL >> V_44 ;
}
static T_3 void F_65 ( void )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < F_30 ( V_37 ) ; V_30 ++ )
V_37 [ V_30 ] = F_64 ( V_30 ) ;
}
static int F_66 ( struct V_81 * V_82 ,
unsigned long V_83 ,
void * V_84 )
{
int V_85 = ( long ) V_84 ;
struct V_22 * V_23 ;
if ( V_83 == V_86 || V_83 == V_87 ) {
V_23 = & F_67 ( V_24 , V_85 ) ;
while ( V_23 -> V_25 ) {
F_26 ( V_27 ,
V_23 -> V_26 [ V_23 -> V_25 - 1 ] ) ;
V_23 -> V_26 [ V_23 -> V_25 - 1 ] = NULL ;
V_23 -> V_25 -- ;
}
}
return V_88 ;
}
void T_3 F_68 ( void )
{
V_27 = F_69 ( L_1 ,
sizeof( struct V_7 ) , 0 ,
V_89 | V_90 ,
F_63 ) ;
F_65 () ;
F_70 ( F_66 , 0 ) ;
}
