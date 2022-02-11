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
V_20 = V_23 -> V_26 ;
V_23 -> V_26 = V_20 -> V_27 ;
V_20 -> V_27 = NULL ;
V_23 -> V_25 -- ;
}
F_22 ( V_20 ) ;
}
if ( V_20 == NULL )
V_20 = F_23 ( V_28 , V_5 ) ;
F_24 ( F_25 ( V_20 ) ) ;
return V_20 ;
}
static void F_26 ( struct V_29 * V_30 )
{
struct V_7 * V_8 =
F_27 ( V_30 , struct V_7 , V_29 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ )
F_6 ( V_8 , V_31 , 0 ) ;
V_8 -> V_33 [ 0 ] = NULL ;
V_8 -> V_34 = 0 ;
F_28 ( V_28 , V_8 ) ;
}
static inline void
F_29 ( struct V_7 * V_8 )
{
F_30 ( & V_8 -> V_29 , F_26 ) ;
}
static int F_31 ( T_1 V_5 )
{
struct V_22 * V_23 ;
struct V_7 * V_8 ;
int V_20 = - V_35 ;
F_32 () ;
V_23 = F_21 ( & V_24 ) ;
while ( V_23 -> V_25 < V_36 ) {
F_33 () ;
V_8 = F_23 ( V_28 , V_5 ) ;
if ( V_8 == NULL )
goto V_37;
F_32 () ;
V_23 = F_21 ( & V_24 ) ;
if ( V_23 -> V_25 < V_36 ) {
V_8 -> V_27 = V_23 -> V_26 ;
V_23 -> V_26 = V_8 ;
V_23 -> V_25 ++ ;
} else {
F_28 ( V_28 , V_8 ) ;
}
}
V_20 = 0 ;
V_37:
return V_20 ;
}
int V_22 ( T_1 V_5 )
{
F_34 ( ! ( V_5 & V_21 ) ) ;
return F_31 ( V_5 ) ;
}
int F_35 ( T_1 V_5 )
{
if ( V_5 & V_21 )
return F_31 ( V_5 ) ;
F_32 () ;
return 0 ;
}
static inline unsigned long F_36 ( unsigned int V_38 )
{
return V_39 [ V_38 ] ;
}
static int F_37 ( struct V_3 * V_4 , unsigned long V_40 )
{
struct V_7 * V_8 ;
struct V_7 * V_41 ;
unsigned int V_38 ;
int V_9 ;
V_38 = V_4 -> V_38 + 1 ;
while ( V_40 > F_36 ( V_38 ) )
V_38 ++ ;
if ( V_4 -> V_42 == NULL ) {
V_4 -> V_38 = V_38 ;
goto V_37;
}
do {
unsigned int V_43 ;
if ( ! ( V_8 = F_19 ( V_4 ) ) )
return - V_35 ;
for ( V_9 = 0 ; V_9 < V_32 ; V_9 ++ ) {
if ( F_13 ( V_4 , V_9 ) )
F_4 ( V_8 , V_9 , 0 ) ;
}
V_43 = V_4 -> V_38 + 1 ;
F_24 ( V_43 & ~ V_44 ) ;
V_8 -> V_45 = V_43 ;
V_8 -> V_34 = 1 ;
V_8 -> V_46 = NULL ;
V_41 = V_4 -> V_42 ;
if ( V_43 > 1 ) {
V_41 = F_2 ( V_41 ) ;
V_41 -> V_46 = V_8 ;
}
V_8 -> V_33 [ 0 ] = V_41 ;
V_8 = F_1 ( V_8 ) ;
F_38 ( V_4 -> V_42 , V_8 ) ;
V_4 -> V_38 = V_43 ;
} while ( V_38 > V_4 -> V_38 );
V_37:
return 0 ;
}
int F_39 ( struct V_3 * V_4 , unsigned long V_40 ,
struct V_7 * * V_47 , void * * * V_48 )
{
struct V_7 * V_8 = NULL , * V_41 ;
unsigned int V_38 , V_49 , V_10 ;
int error ;
if ( V_40 > F_36 ( V_4 -> V_38 ) ) {
error = F_37 ( V_4 , V_40 ) ;
if ( error )
return error ;
}
V_41 = F_2 ( V_4 -> V_42 ) ;
V_38 = V_4 -> V_38 ;
V_49 = ( V_38 - 1 ) * V_50 ;
V_10 = 0 ;
while ( V_38 > 0 ) {
if ( V_41 == NULL ) {
if ( ! ( V_41 = F_19 ( V_4 ) ) )
return - V_35 ;
V_41 -> V_45 = V_38 ;
V_41 -> V_46 = V_8 ;
if ( V_8 ) {
F_38 ( V_8 -> V_33 [ V_10 ] , V_41 ) ;
V_8 -> V_34 ++ ;
V_41 -> V_45 |= V_10 << V_51 ;
} else
F_38 ( V_4 -> V_42 , F_1 ( V_41 ) ) ;
}
V_10 = ( V_40 >> V_49 ) & V_52 ;
V_8 = V_41 ;
V_41 = V_8 -> V_33 [ V_10 ] ;
V_49 -= V_50 ;
V_38 -- ;
}
if ( V_47 )
* V_47 = V_8 ;
if ( V_48 )
* V_48 = V_8 ? V_8 -> V_33 + V_10 : ( void * * ) & V_4 -> V_42 ;
return 0 ;
}
int F_40 ( struct V_3 * V_4 ,
unsigned long V_40 , void * V_53 )
{
struct V_7 * V_8 ;
void * * V_41 ;
int error ;
F_24 ( F_25 ( V_53 ) ) ;
error = F_39 ( V_4 , V_40 , & V_8 , & V_41 ) ;
if ( error )
return error ;
if ( * V_41 != NULL )
return - V_54 ;
F_38 ( * V_41 , V_53 ) ;
if ( V_8 ) {
V_8 -> V_34 ++ ;
F_24 ( F_8 ( V_8 , 0 , V_40 & V_52 ) ) ;
F_24 ( F_8 ( V_8 , 1 , V_40 & V_52 ) ) ;
} else {
F_24 ( F_13 ( V_4 , 0 ) ) ;
F_24 ( F_13 ( V_4 , 1 ) ) ;
}
return 0 ;
}
void * F_41 ( struct V_3 * V_4 , unsigned long V_40 ,
struct V_7 * * V_47 , void * * * V_48 )
{
struct V_7 * V_8 , * V_46 ;
unsigned int V_38 , V_49 ;
void * * V_41 ;
V_8 = F_42 ( V_4 -> V_42 ) ;
if ( V_8 == NULL )
return NULL ;
if ( ! F_25 ( V_8 ) ) {
if ( V_40 > 0 )
return NULL ;
if ( V_47 )
* V_47 = NULL ;
if ( V_48 )
* V_48 = ( void * * ) & V_4 -> V_42 ;
return V_8 ;
}
V_8 = F_2 ( V_8 ) ;
V_38 = V_8 -> V_45 & V_44 ;
if ( V_40 > F_36 ( V_38 ) )
return NULL ;
V_49 = ( V_38 - 1 ) * V_50 ;
do {
V_46 = V_8 ;
V_41 = V_8 -> V_33 + ( ( V_40 >> V_49 ) & V_52 ) ;
V_8 = F_42 ( * V_41 ) ;
if ( V_8 == NULL )
return NULL ;
V_49 -= V_50 ;
V_38 -- ;
} while ( V_38 > 0 );
if ( V_47 )
* V_47 = V_46 ;
if ( V_48 )
* V_48 = V_41 ;
return V_8 ;
}
void * * F_43 ( struct V_3 * V_4 , unsigned long V_40 )
{
void * * V_41 ;
if ( ! F_41 ( V_4 , V_40 , NULL , & V_41 ) )
return NULL ;
return V_41 ;
}
void * F_44 ( struct V_3 * V_4 , unsigned long V_40 )
{
return F_41 ( V_4 , V_40 , NULL , NULL ) ;
}
void * F_45 ( struct V_3 * V_4 ,
unsigned long V_40 , unsigned int V_9 )
{
unsigned int V_38 , V_49 ;
struct V_7 * V_41 ;
V_38 = V_4 -> V_38 ;
F_24 ( V_40 > F_36 ( V_38 ) ) ;
V_41 = F_2 ( V_4 -> V_42 ) ;
V_49 = ( V_38 - 1 ) * V_50 ;
while ( V_38 > 0 ) {
int V_10 ;
V_10 = ( V_40 >> V_49 ) & V_52 ;
if ( ! F_8 ( V_41 , V_9 , V_10 ) )
F_4 ( V_41 , V_9 , V_10 ) ;
V_41 = V_41 -> V_33 [ V_10 ] ;
F_24 ( V_41 == NULL ) ;
V_49 -= V_50 ;
V_38 -- ;
}
if ( V_41 && ! F_13 ( V_4 , V_9 ) )
F_10 ( V_4 , V_9 ) ;
return V_41 ;
}
void * F_46 ( struct V_3 * V_4 ,
unsigned long V_40 , unsigned int V_9 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_41 = NULL ;
unsigned int V_38 , V_49 ;
int V_55 ( V_10 ) ;
V_38 = V_4 -> V_38 ;
if ( V_40 > F_36 ( V_38 ) )
goto V_37;
V_49 = V_38 * V_50 ;
V_41 = F_2 ( V_4 -> V_42 ) ;
while ( V_49 ) {
if ( V_41 == NULL )
goto V_37;
V_49 -= V_50 ;
V_10 = ( V_40 >> V_49 ) & V_52 ;
V_8 = V_41 ;
V_41 = V_41 -> V_33 [ V_10 ] ;
}
if ( V_41 == NULL )
goto V_37;
while ( V_8 ) {
if ( ! F_8 ( V_8 , V_9 , V_10 ) )
goto V_37;
F_6 ( V_8 , V_9 , V_10 ) ;
if ( F_14 ( V_8 , V_9 ) )
goto V_37;
V_40 >>= V_50 ;
V_10 = V_40 & V_52 ;
V_8 = V_8 -> V_46 ;
}
if ( F_13 ( V_4 , V_9 ) )
F_11 ( V_4 , V_9 ) ;
V_37:
return V_41 ;
}
int F_47 ( struct V_3 * V_4 ,
unsigned long V_40 , unsigned int V_9 )
{
unsigned int V_38 , V_49 ;
struct V_7 * V_8 ;
if ( ! F_13 ( V_4 , V_9 ) )
return 0 ;
V_8 = F_42 ( V_4 -> V_42 ) ;
if ( V_8 == NULL )
return 0 ;
if ( ! F_25 ( V_8 ) )
return ( V_40 == 0 ) ;
V_8 = F_2 ( V_8 ) ;
V_38 = V_8 -> V_45 & V_44 ;
if ( V_40 > F_36 ( V_38 ) )
return 0 ;
V_49 = ( V_38 - 1 ) * V_50 ;
for ( ; ; ) {
int V_10 ;
if ( V_8 == NULL )
return 0 ;
V_10 = ( V_40 >> V_49 ) & V_52 ;
if ( ! F_8 ( V_8 , V_9 , V_10 ) )
return 0 ;
if ( V_38 == 1 )
return 1 ;
V_8 = F_42 ( V_8 -> V_33 [ V_10 ] ) ;
V_49 -= V_50 ;
V_38 -- ;
}
}
void * * F_48 ( struct V_3 * V_4 ,
struct V_56 * V_57 , unsigned V_58 )
{
unsigned V_49 , V_9 = V_58 & V_59 ;
struct V_7 * V_42 , * V_8 ;
unsigned long V_40 , V_10 , V_38 ;
if ( ( V_58 & V_60 ) && ! F_13 ( V_4 , V_9 ) )
return NULL ;
V_40 = V_57 -> V_61 ;
if ( ! V_40 && V_57 -> V_40 )
return NULL ;
V_42 = F_42 ( V_4 -> V_42 ) ;
if ( F_25 ( V_42 ) ) {
V_42 = F_2 ( V_42 ) ;
} else if ( V_42 && ! V_40 ) {
V_57 -> V_40 = 0 ;
V_57 -> V_61 = 1 ;
V_57 -> V_11 = 1 ;
return ( void * * ) & V_4 -> V_42 ;
} else
return NULL ;
V_62:
V_38 = V_42 -> V_45 & V_44 ;
V_49 = ( V_38 - 1 ) * V_50 ;
V_10 = V_40 >> V_49 ;
if ( V_10 >= V_63 )
return NULL ;
V_8 = V_42 ;
while ( 1 ) {
if ( ( V_58 & V_60 ) ?
! F_9 ( V_10 , V_8 -> V_11 [ V_9 ] ) :
! V_8 -> V_33 [ V_10 ] ) {
if ( V_58 & V_64 )
return NULL ;
if ( V_58 & V_60 )
V_10 = F_15 (
V_8 -> V_11 [ V_9 ] ,
V_63 ,
V_10 + 1 ) ;
else
while ( ++ V_10 < V_63 ) {
if ( V_8 -> V_33 [ V_10 ] )
break;
}
V_40 &= ~ ( ( V_63 << V_49 ) - 1 ) ;
V_40 += V_10 << V_49 ;
if ( ! V_40 )
return NULL ;
if ( V_10 == V_63 )
goto V_62;
}
if ( ! V_49 )
break;
V_8 = F_42 ( V_8 -> V_33 [ V_10 ] ) ;
if ( V_8 == NULL )
goto V_62;
V_49 -= V_50 ;
V_10 = ( V_40 >> V_49 ) & V_52 ;
}
V_57 -> V_40 = V_40 ;
V_57 -> V_61 = ( V_40 | V_52 ) + 1 ;
if ( V_58 & V_60 ) {
unsigned V_65 , V_66 ;
V_65 = V_10 / V_19 ;
V_66 = V_10 % V_19 ;
V_57 -> V_11 = V_8 -> V_11 [ V_9 ] [ V_65 ] >> V_66 ;
if ( V_65 < V_15 - 1 ) {
if ( V_66 )
V_57 -> V_11 |= V_8 -> V_11 [ V_9 ] [ V_65 + 1 ] <<
( V_19 - V_66 ) ;
V_57 -> V_61 = V_40 + V_19 ;
}
}
return V_8 -> V_33 + V_10 ;
}
unsigned long F_49 ( struct V_3 * V_4 ,
unsigned long * V_67 , unsigned long V_68 ,
unsigned long V_69 ,
unsigned int V_70 , unsigned int V_71 )
{
unsigned int V_38 = V_4 -> V_38 ;
struct V_7 * V_8 = NULL ;
struct V_7 * V_41 ;
unsigned int V_49 ;
unsigned long V_72 = 0 ;
unsigned long V_40 = * V_67 ;
V_68 = F_50 ( V_68 , F_36 ( V_38 ) ) ;
if ( V_40 > V_68 )
return 0 ;
if ( ! V_69 )
return 0 ;
if ( ! F_13 ( V_4 , V_70 ) ) {
* V_67 = V_68 + 1 ;
return 0 ;
}
if ( V_38 == 0 ) {
* V_67 = V_68 + 1 ;
F_10 ( V_4 , V_71 ) ;
return 1 ;
}
V_49 = ( V_38 - 1 ) * V_50 ;
V_41 = F_2 ( V_4 -> V_42 ) ;
for (; ; ) {
unsigned long V_73 ;
int V_10 ;
V_10 = ( V_40 >> V_49 ) & V_52 ;
if ( ! V_41 -> V_33 [ V_10 ] )
goto V_74;
if ( ! F_8 ( V_41 , V_70 , V_10 ) )
goto V_74;
if ( V_49 ) {
V_49 -= V_50 ;
V_8 = V_41 ;
V_41 = V_41 -> V_33 [ V_10 ] ;
continue;
}
V_72 ++ ;
F_4 ( V_41 , V_71 , V_10 ) ;
V_73 = V_40 ;
while ( V_8 ) {
V_73 >>= V_50 ;
V_10 = V_73 & V_52 ;
if ( F_8 ( V_8 , V_71 , V_10 ) )
break;
F_4 ( V_8 , V_71 , V_10 ) ;
V_8 = V_8 -> V_46 ;
}
V_8 = NULL ;
V_74:
V_40 = ( ( V_40 >> V_49 ) + 1 ) << V_49 ;
if ( V_40 > V_68 || ! V_40 )
break;
if ( V_72 >= V_69 )
break;
while ( ( ( V_40 >> V_49 ) & V_52 ) == 0 ) {
V_41 = V_41 -> V_46 ;
V_49 += V_50 ;
}
}
if ( V_72 > 0 )
F_10 ( V_4 , V_71 ) ;
* V_67 = V_40 ;
return V_72 ;
}
unsigned int
F_51 ( struct V_3 * V_4 , void * * V_75 ,
unsigned long V_76 , unsigned int V_77 )
{
struct V_56 V_57 ;
void * * V_41 ;
unsigned int V_20 = 0 ;
if ( F_52 ( ! V_77 ) )
return 0 ;
F_53 (slot, root, &iter, first_index) {
V_75 [ V_20 ] = F_2 ( F_42 ( * V_41 ) ) ;
if ( ! V_75 [ V_20 ] )
continue;
if ( ++ V_20 == V_77 )
break;
}
return V_20 ;
}
unsigned int
F_54 ( struct V_3 * V_4 ,
void * * * V_75 , unsigned long * V_78 ,
unsigned long V_76 , unsigned int V_77 )
{
struct V_56 V_57 ;
void * * V_41 ;
unsigned int V_20 = 0 ;
if ( F_52 ( ! V_77 ) )
return 0 ;
F_53 (slot, root, &iter, first_index) {
V_75 [ V_20 ] = V_41 ;
if ( V_78 )
V_78 [ V_20 ] = V_57 . V_40 ;
if ( ++ V_20 == V_77 )
break;
}
return V_20 ;
}
unsigned int
F_55 ( struct V_3 * V_4 , void * * V_75 ,
unsigned long V_76 , unsigned int V_77 ,
unsigned int V_9 )
{
struct V_56 V_57 ;
void * * V_41 ;
unsigned int V_20 = 0 ;
if ( F_52 ( ! V_77 ) )
return 0 ;
F_56 (slot, root, &iter, first_index, tag) {
V_75 [ V_20 ] = F_2 ( F_42 ( * V_41 ) ) ;
if ( ! V_75 [ V_20 ] )
continue;
if ( ++ V_20 == V_77 )
break;
}
return V_20 ;
}
unsigned int
F_57 ( struct V_3 * V_4 , void * * * V_75 ,
unsigned long V_76 , unsigned int V_77 ,
unsigned int V_9 )
{
struct V_56 V_57 ;
void * * V_41 ;
unsigned int V_20 = 0 ;
if ( F_52 ( ! V_77 ) )
return 0 ;
F_56 (slot, root, &iter, first_index, tag) {
V_75 [ V_20 ] = V_41 ;
if ( ++ V_20 == V_77 )
break;
}
return V_20 ;
}
static unsigned long F_58 ( struct V_7 * V_41 , void * V_53 ,
unsigned long V_40 , unsigned long * V_79 )
{
unsigned int V_49 , V_38 ;
unsigned long V_31 ;
V_38 = V_41 -> V_45 & V_44 ;
V_49 = ( V_38 - 1 ) * V_50 ;
for ( ; V_38 > 1 ; V_38 -- ) {
V_31 = ( V_40 >> V_49 ) & V_52 ;
for (; ; ) {
if ( V_41 -> V_33 [ V_31 ] != NULL )
break;
V_40 &= ~ ( ( 1UL << V_49 ) - 1 ) ;
V_40 += 1UL << V_49 ;
if ( V_40 == 0 )
goto V_37;
V_31 ++ ;
if ( V_31 == V_63 )
goto V_37;
}
V_49 -= V_50 ;
V_41 = F_42 ( V_41 -> V_33 [ V_31 ] ) ;
if ( V_41 == NULL )
goto V_37;
}
for ( V_31 = 0 ; V_31 < V_63 ; V_31 ++ ) {
if ( V_41 -> V_33 [ V_31 ] == V_53 ) {
* V_79 = V_40 + V_31 ;
V_40 = 0 ;
goto V_37;
}
}
V_40 += V_63 ;
V_37:
return V_40 ;
}
unsigned long F_59 ( struct V_3 * V_4 , void * V_53 )
{
struct V_7 * V_8 ;
unsigned long V_80 ;
unsigned long V_81 = 0 ;
unsigned long V_79 = - 1 ;
do {
F_60 () ;
V_8 = F_42 ( V_4 -> V_42 ) ;
if ( ! F_25 ( V_8 ) ) {
F_61 () ;
if ( V_8 == V_53 )
V_79 = 0 ;
break;
}
V_8 = F_2 ( V_8 ) ;
V_80 = F_36 ( V_8 -> V_45 &
V_44 ) ;
if ( V_81 > V_80 ) {
F_61 () ;
break;
}
V_81 = F_58 ( V_8 , V_53 , V_81 , & V_79 ) ;
F_61 () ;
F_62 () ;
} while ( V_81 != 0 && V_81 <= V_80 );
return V_79 ;
}
unsigned long F_59 ( struct V_3 * V_4 , void * V_53 )
{
return - 1 ;
}
static inline void F_63 ( struct V_3 * V_4 )
{
while ( V_4 -> V_38 > 0 ) {
struct V_7 * V_82 = V_4 -> V_42 ;
struct V_7 * V_41 ;
F_24 ( ! F_25 ( V_82 ) ) ;
V_82 = F_2 ( V_82 ) ;
if ( V_82 -> V_34 != 1 )
break;
if ( ! V_82 -> V_33 [ 0 ] )
break;
V_41 = V_82 -> V_33 [ 0 ] ;
if ( V_4 -> V_38 > 1 ) {
V_41 -> V_46 = NULL ;
V_41 = F_1 ( V_41 ) ;
}
V_4 -> V_42 = V_41 ;
V_4 -> V_38 -- ;
if ( V_4 -> V_38 == 0 )
* ( ( unsigned long * ) & V_82 -> V_33 [ 0 ] ) |=
V_2 ;
F_29 ( V_82 ) ;
}
}
bool F_64 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
bool V_83 = false ;
do {
struct V_7 * V_46 ;
if ( V_8 -> V_34 ) {
if ( V_8 == F_2 ( V_4 -> V_42 ) ) {
F_63 ( V_4 ) ;
if ( V_4 -> V_38 == 0 )
V_83 = true ;
}
return V_83 ;
}
V_46 = V_8 -> V_46 ;
if ( V_46 ) {
unsigned int V_10 ;
V_10 = V_8 -> V_45 >> V_51 ;
V_46 -> V_33 [ V_10 ] = NULL ;
V_46 -> V_34 -- ;
} else {
F_12 ( V_4 ) ;
V_4 -> V_38 = 0 ;
V_4 -> V_42 = NULL ;
}
F_29 ( V_8 ) ;
V_83 = true ;
V_8 = V_46 ;
} while ( V_8 );
return V_83 ;
}
void * F_65 ( struct V_3 * V_4 ,
unsigned long V_40 , void * V_53 )
{
struct V_7 * V_8 ;
unsigned int V_10 ;
void * * V_41 ;
void * V_84 ;
int V_9 ;
V_84 = F_41 ( V_4 , V_40 , & V_8 , & V_41 ) ;
if ( ! V_84 )
return NULL ;
if ( V_53 && V_84 != V_53 )
return NULL ;
if ( ! V_8 ) {
F_12 ( V_4 ) ;
V_4 -> V_42 = NULL ;
return V_84 ;
}
V_10 = V_40 & V_52 ;
for ( V_9 = 0 ; V_9 < V_32 ; V_9 ++ ) {
if ( F_8 ( V_8 , V_9 , V_10 ) )
F_46 ( V_4 , V_40 , V_9 ) ;
}
V_8 -> V_33 [ V_10 ] = NULL ;
V_8 -> V_34 -- ;
F_64 ( V_4 , V_8 ) ;
return V_84 ;
}
void * F_66 ( struct V_3 * V_4 , unsigned long V_40 )
{
return F_65 ( V_4 , V_40 , NULL ) ;
}
int F_67 ( struct V_3 * V_4 , unsigned int V_9 )
{
return F_13 ( V_4 , V_9 ) ;
}
static void
F_68 ( void * V_85 )
{
struct V_7 * V_8 = V_85 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_69 ( & V_8 -> V_86 ) ;
}
static T_3 unsigned long F_70 ( unsigned int V_38 )
{
unsigned int V_87 = V_38 * V_50 ;
int V_49 = V_88 - V_87 ;
if ( V_49 < 0 )
return ~ 0UL ;
if ( V_49 >= V_19 )
return 0UL ;
return ~ 0UL >> V_49 ;
}
static T_3 void F_71 ( void )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < F_72 ( V_39 ) ; V_31 ++ )
V_39 [ V_31 ] = F_70 ( V_31 ) ;
}
static int F_73 ( struct V_89 * V_90 ,
unsigned long V_91 ,
void * V_92 )
{
int V_93 = ( long ) V_92 ;
struct V_22 * V_23 ;
struct V_7 * V_8 ;
if ( V_91 == V_94 || V_91 == V_95 ) {
V_23 = & F_74 ( V_24 , V_93 ) ;
while ( V_23 -> V_25 ) {
V_8 = V_23 -> V_26 ;
V_23 -> V_26 = V_8 -> V_27 ;
F_28 ( V_28 , V_8 ) ;
V_23 -> V_25 -- ;
}
}
return V_96 ;
}
void T_3 F_75 ( void )
{
V_28 = F_76 ( L_1 ,
sizeof( struct V_7 ) , 0 ,
V_97 | V_98 ,
F_68 ) ;
F_71 () ;
F_77 ( F_73 , 0 ) ;
}
