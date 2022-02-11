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
static struct V_7 *
F_15 ( struct V_3 * V_4 )
{
struct V_7 * V_16 = NULL ;
T_1 V_5 = F_3 ( V_4 ) ;
if ( ! ( V_5 & V_17 ) ) {
struct V_18 * V_19 ;
V_19 = & F_16 ( V_20 ) ;
if ( V_19 -> V_21 ) {
V_16 = V_19 -> V_22 [ V_19 -> V_21 - 1 ] ;
V_19 -> V_22 [ V_19 -> V_21 - 1 ] = NULL ;
V_19 -> V_21 -- ;
}
}
if ( V_16 == NULL )
V_16 = F_17 ( V_23 , V_5 ) ;
F_18 ( F_19 ( V_16 ) ) ;
return V_16 ;
}
static void F_20 ( struct V_24 * V_25 )
{
struct V_7 * V_8 =
F_21 ( V_25 , struct V_7 , V_24 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
F_6 ( V_8 , V_26 , 0 ) ;
V_8 -> V_28 [ 0 ] = NULL ;
V_8 -> V_29 = 0 ;
F_22 ( V_23 , V_8 ) ;
}
static inline void
F_23 ( struct V_7 * V_8 )
{
F_24 ( & V_8 -> V_24 , F_20 ) ;
}
int V_18 ( T_1 V_5 )
{
struct V_18 * V_19 ;
struct V_7 * V_8 ;
int V_16 = - V_30 ;
F_25 () ;
V_19 = & F_16 ( V_20 ) ;
while ( V_19 -> V_21 < F_26 ( V_19 -> V_22 ) ) {
F_27 () ;
V_8 = F_17 ( V_23 , V_5 ) ;
if ( V_8 == NULL )
goto V_31;
F_25 () ;
V_19 = & F_16 ( V_20 ) ;
if ( V_19 -> V_21 < F_26 ( V_19 -> V_22 ) )
V_19 -> V_22 [ V_19 -> V_21 ++ ] = V_8 ;
else
F_22 ( V_23 , V_8 ) ;
}
V_16 = 0 ;
V_31:
return V_16 ;
}
static inline unsigned long F_28 ( unsigned int V_32 )
{
return V_33 [ V_32 ] ;
}
static int F_29 ( struct V_3 * V_4 , unsigned long V_34 )
{
struct V_7 * V_8 ;
struct V_7 * V_35 ;
unsigned int V_32 ;
int V_9 ;
V_32 = V_4 -> V_32 + 1 ;
while ( V_34 > F_28 ( V_32 ) )
V_32 ++ ;
if ( V_4 -> V_36 == NULL ) {
V_4 -> V_32 = V_32 ;
goto V_31;
}
do {
unsigned int V_37 ;
if ( ! ( V_8 = F_15 ( V_4 ) ) )
return - V_30 ;
for ( V_9 = 0 ; V_9 < V_27 ; V_9 ++ ) {
if ( F_13 ( V_4 , V_9 ) )
F_4 ( V_8 , V_9 , 0 ) ;
}
V_37 = V_4 -> V_32 + 1 ;
V_8 -> V_32 = V_37 ;
V_8 -> V_29 = 1 ;
V_8 -> V_38 = NULL ;
V_35 = V_4 -> V_36 ;
if ( V_37 > 1 ) {
V_35 = F_2 ( V_35 ) ;
V_35 -> V_38 = V_8 ;
}
V_8 -> V_28 [ 0 ] = V_35 ;
V_8 = F_1 ( V_8 ) ;
F_30 ( V_4 -> V_36 , V_8 ) ;
V_4 -> V_32 = V_37 ;
} while ( V_32 > V_4 -> V_32 );
V_31:
return 0 ;
}
int F_31 ( struct V_3 * V_4 ,
unsigned long V_34 , void * V_39 )
{
struct V_7 * V_8 = NULL , * V_35 ;
unsigned int V_32 , V_40 ;
int V_10 ;
int error ;
F_18 ( F_19 ( V_39 ) ) ;
if ( V_34 > F_28 ( V_4 -> V_32 ) ) {
error = F_29 ( V_4 , V_34 ) ;
if ( error )
return error ;
}
V_35 = F_2 ( V_4 -> V_36 ) ;
V_32 = V_4 -> V_32 ;
V_40 = ( V_32 - 1 ) * V_41 ;
V_10 = 0 ;
while ( V_32 > 0 ) {
if ( V_35 == NULL ) {
if ( ! ( V_35 = F_15 ( V_4 ) ) )
return - V_30 ;
V_35 -> V_32 = V_32 ;
V_35 -> V_38 = V_8 ;
if ( V_8 ) {
F_30 ( V_8 -> V_28 [ V_10 ] , V_35 ) ;
V_8 -> V_29 ++ ;
} else
F_30 ( V_4 -> V_36 , F_1 ( V_35 ) ) ;
}
V_10 = ( V_34 >> V_40 ) & V_42 ;
V_8 = V_35 ;
V_35 = V_8 -> V_28 [ V_10 ] ;
V_40 -= V_41 ;
V_32 -- ;
}
if ( V_35 != NULL )
return - V_43 ;
if ( V_8 ) {
V_8 -> V_29 ++ ;
F_30 ( V_8 -> V_28 [ V_10 ] , V_39 ) ;
F_18 ( F_8 ( V_8 , 0 , V_10 ) ) ;
F_18 ( F_8 ( V_8 , 1 , V_10 ) ) ;
} else {
F_30 ( V_4 -> V_36 , V_39 ) ;
F_18 ( F_13 ( V_4 , 0 ) ) ;
F_18 ( F_13 ( V_4 , 1 ) ) ;
}
return 0 ;
}
static void * F_32 ( struct V_3 * V_4 ,
unsigned long V_34 , int V_44 )
{
unsigned int V_32 , V_40 ;
struct V_7 * V_8 , * * V_35 ;
V_8 = F_33 ( V_4 -> V_36 ) ;
if ( V_8 == NULL )
return NULL ;
if ( ! F_19 ( V_8 ) ) {
if ( V_34 > 0 )
return NULL ;
return V_44 ? ( void * ) & V_4 -> V_36 : V_8 ;
}
V_8 = F_2 ( V_8 ) ;
V_32 = V_8 -> V_32 ;
if ( V_34 > F_28 ( V_32 ) )
return NULL ;
V_40 = ( V_32 - 1 ) * V_41 ;
do {
V_35 = (struct V_7 * * )
( V_8 -> V_28 + ( ( V_34 >> V_40 ) & V_42 ) ) ;
V_8 = F_33 ( * V_35 ) ;
if ( V_8 == NULL )
return NULL ;
V_40 -= V_41 ;
V_32 -- ;
} while ( V_32 > 0 );
return V_44 ? ( void * ) V_35 : F_2 ( V_8 ) ;
}
void * * F_34 ( struct V_3 * V_4 , unsigned long V_34 )
{
return ( void * * ) F_32 ( V_4 , V_34 , 1 ) ;
}
void * F_35 ( struct V_3 * V_4 , unsigned long V_34 )
{
return F_32 ( V_4 , V_34 , 0 ) ;
}
void * F_36 ( struct V_3 * V_4 ,
unsigned long V_34 , unsigned int V_9 )
{
unsigned int V_32 , V_40 ;
struct V_7 * V_35 ;
V_32 = V_4 -> V_32 ;
F_18 ( V_34 > F_28 ( V_32 ) ) ;
V_35 = F_2 ( V_4 -> V_36 ) ;
V_40 = ( V_32 - 1 ) * V_41 ;
while ( V_32 > 0 ) {
int V_10 ;
V_10 = ( V_34 >> V_40 ) & V_42 ;
if ( ! F_8 ( V_35 , V_9 , V_10 ) )
F_4 ( V_35 , V_9 , V_10 ) ;
V_35 = V_35 -> V_28 [ V_10 ] ;
F_18 ( V_35 == NULL ) ;
V_40 -= V_41 ;
V_32 -- ;
}
if ( V_35 && ! F_13 ( V_4 , V_9 ) )
F_10 ( V_4 , V_9 ) ;
return V_35 ;
}
void * F_37 ( struct V_3 * V_4 ,
unsigned long V_34 , unsigned int V_9 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_35 = NULL ;
unsigned int V_32 , V_40 ;
int V_45 ( V_10 ) ;
V_32 = V_4 -> V_32 ;
if ( V_34 > F_28 ( V_32 ) )
goto V_31;
V_40 = V_32 * V_41 ;
V_35 = F_2 ( V_4 -> V_36 ) ;
while ( V_40 ) {
if ( V_35 == NULL )
goto V_31;
V_40 -= V_41 ;
V_10 = ( V_34 >> V_40 ) & V_42 ;
V_8 = V_35 ;
V_35 = V_35 -> V_28 [ V_10 ] ;
}
if ( V_35 == NULL )
goto V_31;
while ( V_8 ) {
if ( ! F_8 ( V_8 , V_9 , V_10 ) )
goto V_31;
F_6 ( V_8 , V_9 , V_10 ) ;
if ( F_14 ( V_8 , V_9 ) )
goto V_31;
V_34 >>= V_41 ;
V_10 = V_34 & V_42 ;
V_8 = V_8 -> V_38 ;
}
if ( F_13 ( V_4 , V_9 ) )
F_11 ( V_4 , V_9 ) ;
V_31:
return V_35 ;
}
int F_38 ( struct V_3 * V_4 ,
unsigned long V_34 , unsigned int V_9 )
{
unsigned int V_32 , V_40 ;
struct V_7 * V_8 ;
if ( ! F_13 ( V_4 , V_9 ) )
return 0 ;
V_8 = F_33 ( V_4 -> V_36 ) ;
if ( V_8 == NULL )
return 0 ;
if ( ! F_19 ( V_8 ) )
return ( V_34 == 0 ) ;
V_8 = F_2 ( V_8 ) ;
V_32 = V_8 -> V_32 ;
if ( V_34 > F_28 ( V_32 ) )
return 0 ;
V_40 = ( V_32 - 1 ) * V_41 ;
for ( ; ; ) {
int V_10 ;
if ( V_8 == NULL )
return 0 ;
V_10 = ( V_34 >> V_40 ) & V_42 ;
if ( ! F_8 ( V_8 , V_9 , V_10 ) )
return 0 ;
if ( V_32 == 1 )
return 1 ;
V_8 = F_33 ( V_8 -> V_28 [ V_10 ] ) ;
V_40 -= V_41 ;
V_32 -- ;
}
}
unsigned long F_39 ( struct V_3 * V_4 ,
unsigned long * V_46 , unsigned long V_47 ,
unsigned long V_48 ,
unsigned int V_49 , unsigned int V_50 )
{
unsigned int V_32 = V_4 -> V_32 ;
struct V_7 * V_8 = NULL ;
struct V_7 * V_35 ;
unsigned int V_40 ;
unsigned long V_51 = 0 ;
unsigned long V_34 = * V_46 ;
V_47 = F_40 ( V_47 , F_28 ( V_32 ) ) ;
if ( V_34 > V_47 )
return 0 ;
if ( ! V_48 )
return 0 ;
if ( ! F_13 ( V_4 , V_49 ) ) {
* V_46 = V_47 + 1 ;
return 0 ;
}
if ( V_32 == 0 ) {
* V_46 = V_47 + 1 ;
F_10 ( V_4 , V_50 ) ;
return 1 ;
}
V_40 = ( V_32 - 1 ) * V_41 ;
V_35 = F_2 ( V_4 -> V_36 ) ;
for (; ; ) {
unsigned long V_52 ;
int V_10 ;
V_10 = ( V_34 >> V_40 ) & V_42 ;
if ( ! V_35 -> V_28 [ V_10 ] )
goto V_53;
if ( ! F_8 ( V_35 , V_49 , V_10 ) )
goto V_53;
if ( V_40 ) {
V_40 -= V_41 ;
V_8 = V_35 ;
V_35 = V_35 -> V_28 [ V_10 ] ;
continue;
}
V_51 ++ ;
F_4 ( V_35 , V_50 , V_10 ) ;
V_52 = V_34 ;
while ( V_8 ) {
V_52 >>= V_41 ;
V_10 = V_52 & V_42 ;
if ( F_8 ( V_8 , V_50 , V_10 ) )
break;
F_4 ( V_8 , V_50 , V_10 ) ;
V_8 = V_8 -> V_38 ;
}
V_8 = NULL ;
V_53:
V_34 = ( ( V_34 >> V_40 ) + 1 ) << V_40 ;
if ( V_34 > V_47 || ! V_34 )
break;
if ( V_51 >= V_48 )
break;
while ( ( ( V_34 >> V_40 ) & V_42 ) == 0 ) {
V_35 = V_35 -> V_38 ;
V_40 += V_41 ;
}
}
if ( V_51 > 0 )
F_10 ( V_4 , V_50 ) ;
* V_46 = V_34 ;
return V_51 ;
}
unsigned long F_41 ( struct V_3 * V_4 ,
unsigned long V_34 , unsigned long V_54 )
{
unsigned long V_26 ;
for ( V_26 = 0 ; V_26 < V_54 ; V_26 ++ ) {
if ( ! F_35 ( V_4 , V_34 ) )
break;
V_34 ++ ;
if ( V_34 == 0 )
break;
}
return V_34 ;
}
unsigned long F_42 ( struct V_3 * V_4 ,
unsigned long V_34 , unsigned long V_54 )
{
unsigned long V_26 ;
for ( V_26 = 0 ; V_26 < V_54 ; V_26 ++ ) {
if ( ! F_35 ( V_4 , V_34 ) )
break;
V_34 -- ;
if ( V_34 == V_55 )
break;
}
return V_34 ;
}
static unsigned int
F_43 ( struct V_7 * V_35 , void * * * V_56 , unsigned long * V_57 ,
unsigned long V_34 , unsigned int V_58 , unsigned long * V_59 )
{
unsigned int V_60 = 0 ;
unsigned int V_40 , V_32 ;
unsigned long V_26 ;
V_32 = V_35 -> V_32 ;
if ( V_32 == 0 )
goto V_31;
V_40 = ( V_32 - 1 ) * V_41 ;
for ( ; V_32 > 1 ; V_32 -- ) {
V_26 = ( V_34 >> V_40 ) & V_42 ;
for (; ; ) {
if ( V_35 -> V_28 [ V_26 ] != NULL )
break;
V_34 &= ~ ( ( 1UL << V_40 ) - 1 ) ;
V_34 += 1UL << V_40 ;
if ( V_34 == 0 )
goto V_31;
V_26 ++ ;
if ( V_26 == V_61 )
goto V_31;
}
V_40 -= V_41 ;
V_35 = F_33 ( V_35 -> V_28 [ V_26 ] ) ;
if ( V_35 == NULL )
goto V_31;
}
for ( V_26 = V_34 & V_42 ; V_26 < V_61 ; V_26 ++ ) {
if ( V_35 -> V_28 [ V_26 ] ) {
V_56 [ V_60 ] = & ( V_35 -> V_28 [ V_26 ] ) ;
if ( V_57 )
V_57 [ V_60 ] = V_34 ;
if ( ++ V_60 == V_58 ) {
V_34 ++ ;
goto V_31;
}
}
V_34 ++ ;
}
V_31:
* V_59 = V_34 ;
return V_60 ;
}
unsigned int
F_44 ( struct V_3 * V_4 , void * * V_56 ,
unsigned long V_62 , unsigned int V_58 )
{
unsigned long V_63 ;
struct V_7 * V_8 ;
unsigned long V_64 = V_62 ;
unsigned int V_16 ;
V_8 = F_33 ( V_4 -> V_36 ) ;
if ( ! V_8 )
return 0 ;
if ( ! F_19 ( V_8 ) ) {
if ( V_62 > 0 )
return 0 ;
V_56 [ 0 ] = V_8 ;
return 1 ;
}
V_8 = F_2 ( V_8 ) ;
V_63 = F_28 ( V_8 -> V_32 ) ;
V_16 = 0 ;
while ( V_16 < V_58 ) {
unsigned int V_60 , V_65 , V_26 ;
unsigned long V_59 ;
if ( V_64 > V_63 )
break;
V_65 = F_43 ( V_8 , ( void * * * ) V_56 + V_16 , NULL ,
V_64 , V_58 - V_16 , & V_59 ) ;
V_60 = 0 ;
for ( V_26 = 0 ; V_26 < V_65 ; V_26 ++ ) {
struct V_7 * V_35 ;
V_35 = * ( ( ( void * * * ) V_56 ) [ V_16 + V_26 ] ) ;
if ( ! V_35 )
continue;
V_56 [ V_16 + V_60 ] =
F_2 ( F_33 ( V_35 ) ) ;
V_60 ++ ;
}
V_16 += V_60 ;
if ( V_59 == 0 )
break;
V_64 = V_59 ;
}
return V_16 ;
}
unsigned int
F_45 ( struct V_3 * V_4 ,
void * * * V_56 , unsigned long * V_57 ,
unsigned long V_62 , unsigned int V_58 )
{
unsigned long V_63 ;
struct V_7 * V_8 ;
unsigned long V_64 = V_62 ;
unsigned int V_16 ;
V_8 = F_33 ( V_4 -> V_36 ) ;
if ( ! V_8 )
return 0 ;
if ( ! F_19 ( V_8 ) ) {
if ( V_62 > 0 )
return 0 ;
V_56 [ 0 ] = ( void * * ) & V_4 -> V_36 ;
if ( V_57 )
V_57 [ 0 ] = 0 ;
return 1 ;
}
V_8 = F_2 ( V_8 ) ;
V_63 = F_28 ( V_8 -> V_32 ) ;
V_16 = 0 ;
while ( V_16 < V_58 ) {
unsigned int V_65 ;
unsigned long V_59 ;
if ( V_64 > V_63 )
break;
V_65 = F_43 ( V_8 , V_56 + V_16 ,
V_57 ? V_57 + V_16 : NULL ,
V_64 , V_58 - V_16 , & V_59 ) ;
V_16 += V_65 ;
if ( V_59 == 0 )
break;
V_64 = V_59 ;
}
return V_16 ;
}
static unsigned int
F_46 ( struct V_7 * V_35 , void * * * V_56 , unsigned long V_34 ,
unsigned int V_58 , unsigned long * V_59 , unsigned int V_9 )
{
unsigned int V_60 = 0 ;
unsigned int V_40 , V_32 ;
V_32 = V_35 -> V_32 ;
if ( V_32 == 0 )
goto V_31;
V_40 = ( V_32 - 1 ) * V_41 ;
while ( V_32 > 0 ) {
unsigned long V_26 = ( V_34 >> V_40 ) & V_42 ;
for (; ; ) {
if ( F_8 ( V_35 , V_9 , V_26 ) )
break;
V_34 &= ~ ( ( 1UL << V_40 ) - 1 ) ;
V_34 += 1UL << V_40 ;
if ( V_34 == 0 )
goto V_31;
V_26 ++ ;
if ( V_26 == V_61 )
goto V_31;
}
V_32 -- ;
if ( V_32 == 0 ) {
unsigned long V_66 = V_34 & V_42 ;
for ( ; V_66 < V_61 ; V_66 ++ ) {
V_34 ++ ;
if ( ! F_8 ( V_35 , V_9 , V_66 ) )
continue;
if ( V_35 -> V_28 [ V_66 ] ) {
V_56 [ V_60 ++ ] = & ( V_35 -> V_28 [ V_66 ] ) ;
if ( V_60 == V_58 )
goto V_31;
}
}
}
V_40 -= V_41 ;
V_35 = F_33 ( V_35 -> V_28 [ V_26 ] ) ;
if ( V_35 == NULL )
break;
}
V_31:
* V_59 = V_34 ;
return V_60 ;
}
unsigned int
F_47 ( struct V_3 * V_4 , void * * V_56 ,
unsigned long V_62 , unsigned int V_58 ,
unsigned int V_9 )
{
struct V_7 * V_8 ;
unsigned long V_63 ;
unsigned long V_64 = V_62 ;
unsigned int V_16 ;
if ( ! F_13 ( V_4 , V_9 ) )
return 0 ;
V_8 = F_33 ( V_4 -> V_36 ) ;
if ( ! V_8 )
return 0 ;
if ( ! F_19 ( V_8 ) ) {
if ( V_62 > 0 )
return 0 ;
V_56 [ 0 ] = V_8 ;
return 1 ;
}
V_8 = F_2 ( V_8 ) ;
V_63 = F_28 ( V_8 -> V_32 ) ;
V_16 = 0 ;
while ( V_16 < V_58 ) {
unsigned int V_60 , V_65 , V_26 ;
unsigned long V_59 ;
if ( V_64 > V_63 )
break;
V_65 = F_46 ( V_8 , ( void * * * ) V_56 + V_16 ,
V_64 , V_58 - V_16 , & V_59 , V_9 ) ;
V_60 = 0 ;
for ( V_26 = 0 ; V_26 < V_65 ; V_26 ++ ) {
struct V_7 * V_35 ;
V_35 = * ( ( ( void * * * ) V_56 ) [ V_16 + V_26 ] ) ;
if ( ! V_35 )
continue;
V_56 [ V_16 + V_60 ] =
F_2 ( F_33 ( V_35 ) ) ;
V_60 ++ ;
}
V_16 += V_60 ;
if ( V_59 == 0 )
break;
V_64 = V_59 ;
}
return V_16 ;
}
unsigned int
F_48 ( struct V_3 * V_4 , void * * * V_56 ,
unsigned long V_62 , unsigned int V_58 ,
unsigned int V_9 )
{
struct V_7 * V_8 ;
unsigned long V_63 ;
unsigned long V_64 = V_62 ;
unsigned int V_16 ;
if ( ! F_13 ( V_4 , V_9 ) )
return 0 ;
V_8 = F_33 ( V_4 -> V_36 ) ;
if ( ! V_8 )
return 0 ;
if ( ! F_19 ( V_8 ) ) {
if ( V_62 > 0 )
return 0 ;
V_56 [ 0 ] = ( void * * ) & V_4 -> V_36 ;
return 1 ;
}
V_8 = F_2 ( V_8 ) ;
V_63 = F_28 ( V_8 -> V_32 ) ;
V_16 = 0 ;
while ( V_16 < V_58 ) {
unsigned int V_65 ;
unsigned long V_59 ;
if ( V_64 > V_63 )
break;
V_65 = F_46 ( V_8 , V_56 + V_16 ,
V_64 , V_58 - V_16 , & V_59 , V_9 ) ;
V_16 += V_65 ;
if ( V_59 == 0 )
break;
V_64 = V_59 ;
}
return V_16 ;
}
static unsigned long F_49 ( struct V_7 * V_35 , void * V_39 ,
unsigned long V_34 , unsigned long * V_67 )
{
unsigned int V_40 , V_32 ;
unsigned long V_26 ;
V_32 = V_35 -> V_32 ;
V_40 = ( V_32 - 1 ) * V_41 ;
for ( ; V_32 > 1 ; V_32 -- ) {
V_26 = ( V_34 >> V_40 ) & V_42 ;
for (; ; ) {
if ( V_35 -> V_28 [ V_26 ] != NULL )
break;
V_34 &= ~ ( ( 1UL << V_40 ) - 1 ) ;
V_34 += 1UL << V_40 ;
if ( V_34 == 0 )
goto V_31;
V_26 ++ ;
if ( V_26 == V_61 )
goto V_31;
}
V_40 -= V_41 ;
V_35 = F_33 ( V_35 -> V_28 [ V_26 ] ) ;
if ( V_35 == NULL )
goto V_31;
}
for ( V_26 = 0 ; V_26 < V_61 ; V_26 ++ ) {
if ( V_35 -> V_28 [ V_26 ] == V_39 ) {
* V_67 = V_34 + V_26 ;
V_34 = 0 ;
goto V_31;
}
}
V_34 += V_61 ;
V_31:
return V_34 ;
}
unsigned long F_50 ( struct V_3 * V_4 , void * V_39 )
{
struct V_7 * V_8 ;
unsigned long V_63 ;
unsigned long V_64 = 0 ;
unsigned long V_67 = - 1 ;
do {
F_51 () ;
V_8 = F_33 ( V_4 -> V_36 ) ;
if ( ! F_19 ( V_8 ) ) {
F_52 () ;
if ( V_8 == V_39 )
V_67 = 0 ;
break;
}
V_8 = F_2 ( V_8 ) ;
V_63 = F_28 ( V_8 -> V_32 ) ;
if ( V_64 > V_63 )
break;
V_64 = F_49 ( V_8 , V_39 , V_64 , & V_67 ) ;
F_52 () ;
F_53 () ;
} while ( V_64 != 0 && V_64 <= V_63 );
return V_67 ;
}
unsigned long F_50 ( struct V_3 * V_4 , void * V_39 )
{
return - 1 ;
}
static inline void F_54 ( struct V_3 * V_4 )
{
while ( V_4 -> V_32 > 0 ) {
struct V_7 * V_68 = V_4 -> V_36 ;
struct V_7 * V_35 ;
F_18 ( ! F_19 ( V_68 ) ) ;
V_68 = F_2 ( V_68 ) ;
if ( V_68 -> V_29 != 1 )
break;
if ( ! V_68 -> V_28 [ 0 ] )
break;
V_35 = V_68 -> V_28 [ 0 ] ;
if ( V_4 -> V_32 > 1 ) {
V_35 -> V_38 = NULL ;
V_35 = F_1 ( V_35 ) ;
}
V_4 -> V_36 = V_35 ;
V_4 -> V_32 -- ;
if ( V_4 -> V_32 == 0 )
* ( ( unsigned long * ) & V_68 -> V_28 [ 0 ] ) |=
V_2 ;
F_23 ( V_68 ) ;
}
}
void * F_55 ( struct V_3 * V_4 , unsigned long V_34 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_35 = NULL ;
struct V_7 * V_68 ;
unsigned int V_32 , V_40 ;
int V_9 ;
int V_45 ( V_10 ) ;
V_32 = V_4 -> V_32 ;
if ( V_34 > F_28 ( V_32 ) )
goto V_31;
V_35 = V_4 -> V_36 ;
if ( V_32 == 0 ) {
F_12 ( V_4 ) ;
V_4 -> V_36 = NULL ;
goto V_31;
}
V_35 = F_2 ( V_35 ) ;
V_40 = V_32 * V_41 ;
do {
if ( V_35 == NULL )
goto V_31;
V_40 -= V_41 ;
V_10 = ( V_34 >> V_40 ) & V_42 ;
V_8 = V_35 ;
V_35 = V_35 -> V_28 [ V_10 ] ;
} while ( V_40 );
if ( V_35 == NULL )
goto V_31;
for ( V_9 = 0 ; V_9 < V_27 ; V_9 ++ ) {
if ( F_8 ( V_8 , V_9 , V_10 ) )
F_37 ( V_4 , V_34 , V_9 ) ;
}
V_68 = NULL ;
while ( V_8 ) {
V_8 -> V_28 [ V_10 ] = NULL ;
V_8 -> V_29 -- ;
if ( V_68 )
F_23 ( V_68 ) ;
if ( V_8 -> V_29 ) {
if ( V_8 == F_2 ( V_4 -> V_36 ) )
F_54 ( V_4 ) ;
goto V_31;
}
V_68 = V_8 ;
V_34 >>= V_41 ;
V_10 = V_34 & V_42 ;
V_8 = V_8 -> V_38 ;
}
F_12 ( V_4 ) ;
V_4 -> V_32 = 0 ;
V_4 -> V_36 = NULL ;
if ( V_68 )
F_23 ( V_68 ) ;
V_31:
return V_35 ;
}
int F_56 ( struct V_3 * V_4 , unsigned int V_9 )
{
return F_13 ( V_4 , V_9 ) ;
}
static void
F_57 ( void * V_8 )
{
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
}
static T_2 unsigned long F_58 ( unsigned int V_32 )
{
unsigned int V_69 = V_32 * V_41 ;
int V_40 = V_70 - V_69 ;
if ( V_40 < 0 )
return ~ 0UL ;
if ( V_40 >= V_71 )
return 0UL ;
return ~ 0UL >> V_40 ;
}
static T_2 void F_59 ( void )
{
unsigned int V_26 ;
for ( V_26 = 0 ; V_26 < F_26 ( V_33 ) ; V_26 ++ )
V_33 [ V_26 ] = F_58 ( V_26 ) ;
}
static int F_60 ( struct V_72 * V_73 ,
unsigned long V_74 ,
void * V_75 )
{
int V_76 = ( long ) V_75 ;
struct V_18 * V_19 ;
if ( V_74 == V_77 || V_74 == V_78 ) {
V_19 = & F_61 ( V_20 , V_76 ) ;
while ( V_19 -> V_21 ) {
F_22 ( V_23 ,
V_19 -> V_22 [ V_19 -> V_21 - 1 ] ) ;
V_19 -> V_22 [ V_19 -> V_21 - 1 ] = NULL ;
V_19 -> V_21 -- ;
}
}
return V_79 ;
}
void T_2 F_62 ( void )
{
V_23 = F_63 ( L_1 ,
sizeof( struct V_7 ) , 0 ,
V_80 | V_81 ,
F_57 ) ;
F_59 () ;
F_64 ( F_60 , 0 ) ;
}
