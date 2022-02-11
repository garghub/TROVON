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
V_20 = F_22 ( V_23 ,
V_5 | V_24 | V_25 ) ;
if ( V_20 )
goto V_26;
V_22 = F_23 ( & V_27 ) ;
if ( V_22 -> V_28 ) {
V_20 = V_22 -> V_29 ;
V_22 -> V_29 = V_20 -> V_30 ;
V_20 -> V_30 = NULL ;
V_22 -> V_28 -- ;
}
F_24 ( V_20 ) ;
goto V_26;
}
V_20 = F_22 ( V_23 ,
V_5 | V_24 ) ;
V_26:
F_25 ( F_26 ( V_20 ) ) ;
return V_20 ;
}
static void F_27 ( struct V_31 * V_32 )
{
struct V_7 * V_8 =
F_28 ( V_32 , struct V_7 , V_31 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ )
F_6 ( V_8 , V_33 , 0 ) ;
V_8 -> V_35 [ 0 ] = NULL ;
V_8 -> V_36 = 0 ;
F_29 ( V_23 , V_8 ) ;
}
static inline void
F_30 ( struct V_7 * V_8 )
{
F_31 ( & V_8 -> V_31 , F_27 ) ;
}
static int F_32 ( T_1 V_5 )
{
struct V_21 * V_22 ;
struct V_7 * V_8 ;
int V_20 = - V_37 ;
F_33 () ;
V_22 = F_23 ( & V_27 ) ;
while ( V_22 -> V_28 < V_38 ) {
F_34 () ;
V_8 = F_22 ( V_23 , V_5 ) ;
if ( V_8 == NULL )
goto V_26;
F_33 () ;
V_22 = F_23 ( & V_27 ) ;
if ( V_22 -> V_28 < V_38 ) {
V_8 -> V_30 = V_22 -> V_29 ;
V_22 -> V_29 = V_8 ;
V_22 -> V_28 ++ ;
} else {
F_29 ( V_23 , V_8 ) ;
}
}
V_20 = 0 ;
V_26:
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
static inline unsigned long F_37 ( unsigned int V_39 )
{
return V_40 [ V_39 ] ;
}
static int F_38 ( struct V_3 * V_4 ,
unsigned long V_41 , unsigned V_42 )
{
struct V_7 * V_8 ;
struct V_7 * V_43 ;
unsigned int V_39 ;
int V_9 ;
V_39 = V_4 -> V_39 + 1 ;
while ( V_41 > F_37 ( V_39 ) )
V_39 ++ ;
if ( ( V_4 -> V_44 == NULL ) && ( V_42 == 0 ) ) {
V_4 -> V_39 = V_39 ;
goto V_26;
}
do {
unsigned int V_45 ;
if ( ! ( V_8 = F_19 ( V_4 ) ) )
return - V_37 ;
for ( V_9 = 0 ; V_9 < V_34 ; V_9 ++ ) {
if ( F_13 ( V_4 , V_9 ) )
F_4 ( V_8 , V_9 , 0 ) ;
}
V_45 = V_4 -> V_39 + 1 ;
F_25 ( V_45 & ~ V_46 ) ;
V_8 -> V_47 = V_45 ;
V_8 -> V_36 = 1 ;
V_8 -> V_48 = NULL ;
V_43 = V_4 -> V_44 ;
if ( F_26 ( V_43 ) && V_45 > 1 ) {
V_43 = F_2 ( V_43 ) ;
V_43 -> V_48 = V_8 ;
V_43 = F_1 ( V_43 ) ;
}
V_8 -> V_35 [ 0 ] = V_43 ;
V_8 = F_1 ( V_8 ) ;
F_39 ( V_4 -> V_44 , V_8 ) ;
V_4 -> V_39 = V_45 ;
} while ( V_39 > V_4 -> V_39 );
V_26:
return 0 ;
}
int F_40 ( struct V_3 * V_4 , unsigned long V_41 ,
unsigned V_42 , struct V_7 * * V_49 ,
void * * * V_50 )
{
struct V_7 * V_8 = NULL , * V_43 ;
unsigned int V_39 , V_51 , V_10 ;
int error ;
F_25 ( ( 0 < V_42 ) && ( V_42 < V_52 ) ) ;
if ( V_41 > F_37 ( V_4 -> V_39 ) ) {
error = F_38 ( V_4 , V_41 , V_42 ) ;
if ( error )
return error ;
}
V_43 = V_4 -> V_44 ;
V_39 = V_4 -> V_39 ;
V_51 = V_39 * V_52 ;
V_10 = 0 ;
while ( V_51 > V_42 ) {
if ( V_43 == NULL ) {
if ( ! ( V_43 = F_19 ( V_4 ) ) )
return - V_37 ;
V_43 -> V_47 = V_39 ;
V_43 -> V_48 = V_8 ;
if ( V_8 ) {
F_39 ( V_8 -> V_35 [ V_10 ] ,
F_1 ( V_43 ) ) ;
V_8 -> V_36 ++ ;
V_43 -> V_47 |= V_10 << V_53 ;
} else
F_39 ( V_4 -> V_44 ,
F_1 ( V_43 ) ) ;
} else if ( ! F_26 ( V_43 ) )
break;
V_39 -- ;
V_51 -= V_52 ;
V_10 = ( V_41 >> V_51 ) & V_54 ;
V_8 = F_2 ( V_43 ) ;
V_43 = V_8 -> V_35 [ V_10 ] ;
}
if ( ( V_51 - V_42 ) > 0 ) {
int V_33 , V_55 = 1 << ( V_51 - V_42 ) ;
V_10 = V_10 & ~ ( V_55 - 1 ) ;
V_43 = F_1 ( & V_8 -> V_35 [ V_10 ] ) ;
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ ) {
if ( V_8 -> V_35 [ V_10 + V_33 ] )
return - V_56 ;
}
for ( V_33 = 1 ; V_33 < V_55 ; V_33 ++ ) {
F_39 ( V_8 -> V_35 [ V_10 + V_33 ] , V_43 ) ;
V_8 -> V_36 ++ ;
}
}
if ( V_49 )
* V_49 = V_8 ;
if ( V_50 )
* V_50 = V_8 ? V_8 -> V_35 + V_10 : ( void * * ) & V_4 -> V_44 ;
return 0 ;
}
int F_41 ( struct V_3 * V_4 , unsigned long V_41 ,
unsigned V_42 , void * V_57 )
{
struct V_7 * V_8 ;
void * * V_43 ;
int error ;
F_25 ( F_26 ( V_57 ) ) ;
error = F_40 ( V_4 , V_41 , V_42 , & V_8 , & V_43 ) ;
if ( error )
return error ;
if ( * V_43 != NULL )
return - V_56 ;
F_39 ( * V_43 , V_57 ) ;
if ( V_8 ) {
V_8 -> V_36 ++ ;
F_25 ( F_8 ( V_8 , 0 , V_41 & V_54 ) ) ;
F_25 ( F_8 ( V_8 , 1 , V_41 & V_54 ) ) ;
} else {
F_25 ( F_13 ( V_4 , 0 ) ) ;
F_25 ( F_13 ( V_4 , 1 ) ) ;
}
return 0 ;
}
void * F_42 ( struct V_3 * V_4 , unsigned long V_41 ,
struct V_7 * * V_49 , void * * * V_50 )
{
struct V_7 * V_8 , * V_48 ;
unsigned int V_39 , V_51 ;
void * * V_43 ;
V_8 = F_43 ( V_4 -> V_44 ) ;
if ( V_8 == NULL )
return NULL ;
if ( ! F_26 ( V_8 ) ) {
if ( V_41 > 0 )
return NULL ;
if ( V_49 )
* V_49 = NULL ;
if ( V_50 )
* V_50 = ( void * * ) & V_4 -> V_44 ;
return V_8 ;
}
V_8 = F_2 ( V_8 ) ;
V_39 = V_8 -> V_47 & V_46 ;
if ( V_41 > F_37 ( V_39 ) )
return NULL ;
V_51 = ( V_39 - 1 ) * V_52 ;
do {
V_48 = V_8 ;
V_43 = V_8 -> V_35 + ( ( V_41 >> V_51 ) & V_54 ) ;
V_8 = F_43 ( * V_43 ) ;
if ( V_8 == NULL )
return NULL ;
if ( ! F_26 ( V_8 ) )
break;
V_8 = F_2 ( V_8 ) ;
V_51 -= V_52 ;
V_39 -- ;
} while ( V_39 > 0 );
if ( V_49 )
* V_49 = V_48 ;
if ( V_50 )
* V_50 = V_43 ;
return V_8 ;
}
void * * F_44 ( struct V_3 * V_4 , unsigned long V_41 )
{
void * * V_43 ;
if ( ! F_42 ( V_4 , V_41 , NULL , & V_43 ) )
return NULL ;
return V_43 ;
}
void * F_45 ( struct V_3 * V_4 , unsigned long V_41 )
{
return F_42 ( V_4 , V_41 , NULL , NULL ) ;
}
void * F_46 ( struct V_3 * V_4 ,
unsigned long V_41 , unsigned int V_9 )
{
unsigned int V_39 , V_51 ;
struct V_7 * V_43 ;
V_39 = V_4 -> V_39 ;
F_25 ( V_41 > F_37 ( V_39 ) ) ;
V_43 = F_2 ( V_4 -> V_44 ) ;
V_51 = ( V_39 - 1 ) * V_52 ;
while ( V_39 > 0 ) {
int V_10 ;
V_10 = ( V_41 >> V_51 ) & V_54 ;
if ( ! F_8 ( V_43 , V_9 , V_10 ) )
F_4 ( V_43 , V_9 , V_10 ) ;
V_43 = V_43 -> V_35 [ V_10 ] ;
F_25 ( V_43 == NULL ) ;
if ( ! F_26 ( V_43 ) )
break;
V_43 = F_2 ( V_43 ) ;
V_51 -= V_52 ;
V_39 -- ;
}
if ( V_43 && ! F_13 ( V_4 , V_9 ) )
F_10 ( V_4 , V_9 ) ;
return V_43 ;
}
void * F_47 ( struct V_3 * V_4 ,
unsigned long V_41 , unsigned int V_9 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_43 = NULL ;
unsigned int V_39 , V_51 ;
int V_58 ( V_10 ) ;
V_39 = V_4 -> V_39 ;
if ( V_41 > F_37 ( V_39 ) )
goto V_26;
V_51 = V_39 * V_52 ;
V_43 = V_4 -> V_44 ;
while ( V_51 ) {
if ( V_43 == NULL )
goto V_26;
if ( ! F_26 ( V_43 ) )
break;
V_43 = F_2 ( V_43 ) ;
V_51 -= V_52 ;
V_10 = ( V_41 >> V_51 ) & V_54 ;
V_8 = V_43 ;
V_43 = V_43 -> V_35 [ V_10 ] ;
}
if ( V_43 == NULL )
goto V_26;
while ( V_8 ) {
if ( ! F_8 ( V_8 , V_9 , V_10 ) )
goto V_26;
F_6 ( V_8 , V_9 , V_10 ) ;
if ( F_14 ( V_8 , V_9 ) )
goto V_26;
V_41 >>= V_52 ;
V_10 = V_41 & V_54 ;
V_8 = V_8 -> V_48 ;
}
if ( F_13 ( V_4 , V_9 ) )
F_11 ( V_4 , V_9 ) ;
V_26:
return V_43 ;
}
int F_48 ( struct V_3 * V_4 ,
unsigned long V_41 , unsigned int V_9 )
{
unsigned int V_39 , V_51 ;
struct V_7 * V_8 ;
if ( ! F_13 ( V_4 , V_9 ) )
return 0 ;
V_8 = F_43 ( V_4 -> V_44 ) ;
if ( V_8 == NULL )
return 0 ;
if ( ! F_26 ( V_8 ) )
return ( V_41 == 0 ) ;
V_8 = F_2 ( V_8 ) ;
V_39 = V_8 -> V_47 & V_46 ;
if ( V_41 > F_37 ( V_39 ) )
return 0 ;
V_51 = ( V_39 - 1 ) * V_52 ;
for ( ; ; ) {
int V_10 ;
if ( V_8 == NULL )
return 0 ;
V_8 = F_2 ( V_8 ) ;
V_10 = ( V_41 >> V_51 ) & V_54 ;
if ( ! F_8 ( V_8 , V_9 , V_10 ) )
return 0 ;
if ( V_39 == 1 )
return 1 ;
V_8 = F_43 ( V_8 -> V_35 [ V_10 ] ) ;
if ( ! F_26 ( V_8 ) )
return 1 ;
V_51 -= V_52 ;
V_39 -- ;
}
}
void * * F_49 ( struct V_3 * V_4 ,
struct V_59 * V_60 , unsigned V_61 )
{
unsigned V_51 , V_9 = V_61 & V_62 ;
struct V_7 * V_44 , * V_8 ;
unsigned long V_41 , V_10 , V_39 ;
if ( ( V_61 & V_63 ) && ! F_13 ( V_4 , V_9 ) )
return NULL ;
V_41 = V_60 -> V_64 ;
if ( ! V_41 && V_60 -> V_41 )
return NULL ;
V_44 = F_43 ( V_4 -> V_44 ) ;
if ( F_26 ( V_44 ) ) {
V_44 = F_2 ( V_44 ) ;
} else if ( V_44 && ! V_41 ) {
V_60 -> V_41 = 0 ;
V_60 -> V_64 = 1 ;
V_60 -> V_11 = 1 ;
return ( void * * ) & V_4 -> V_44 ;
} else
return NULL ;
V_65:
V_39 = V_44 -> V_47 & V_46 ;
V_51 = ( V_39 - 1 ) * V_52 ;
V_10 = V_41 >> V_51 ;
if ( V_10 >= V_66 )
return NULL ;
V_8 = V_44 ;
while ( 1 ) {
struct V_7 * V_43 ;
if ( ( V_61 & V_63 ) ?
! F_9 ( V_10 , V_8 -> V_11 [ V_9 ] ) :
! V_8 -> V_35 [ V_10 ] ) {
if ( V_61 & V_67 )
return NULL ;
if ( V_61 & V_63 )
V_10 = F_15 (
V_8 -> V_11 [ V_9 ] ,
V_66 ,
V_10 + 1 ) ;
else
while ( ++ V_10 < V_66 ) {
if ( V_8 -> V_35 [ V_10 ] )
break;
}
V_41 &= ~ ( ( V_66 << V_51 ) - 1 ) ;
V_41 += V_10 << V_51 ;
if ( ! V_41 )
return NULL ;
if ( V_10 == V_66 )
goto V_65;
}
if ( ! V_51 )
break;
V_43 = F_43 ( V_8 -> V_35 [ V_10 ] ) ;
if ( V_43 == NULL )
goto V_65;
if ( ! F_26 ( V_43 ) )
break;
V_8 = F_2 ( V_43 ) ;
V_51 -= V_52 ;
V_10 = ( V_41 >> V_51 ) & V_54 ;
}
V_60 -> V_41 = V_41 ;
V_60 -> V_64 = ( V_41 | V_54 ) + 1 ;
if ( V_61 & V_63 ) {
unsigned V_68 , V_69 ;
V_68 = V_10 / V_19 ;
V_69 = V_10 % V_19 ;
V_60 -> V_11 = V_8 -> V_11 [ V_9 ] [ V_68 ] >> V_69 ;
if ( V_68 < V_15 - 1 ) {
if ( V_69 )
V_60 -> V_11 |= V_8 -> V_11 [ V_9 ] [ V_68 + 1 ] <<
( V_19 - V_69 ) ;
V_60 -> V_64 = V_41 + V_19 ;
}
}
return V_8 -> V_35 + V_10 ;
}
unsigned long F_50 ( struct V_3 * V_4 ,
unsigned long * V_70 , unsigned long V_71 ,
unsigned long V_72 ,
unsigned int V_73 , unsigned int V_74 )
{
unsigned int V_39 = V_4 -> V_39 ;
struct V_7 * V_8 = NULL ;
struct V_7 * V_43 ;
unsigned int V_51 ;
unsigned long V_75 = 0 ;
unsigned long V_41 = * V_70 ;
V_71 = F_51 ( V_71 , F_37 ( V_39 ) ) ;
if ( V_41 > V_71 )
return 0 ;
if ( ! V_72 )
return 0 ;
if ( ! F_13 ( V_4 , V_73 ) ) {
* V_70 = V_71 + 1 ;
return 0 ;
}
if ( V_39 == 0 ) {
* V_70 = V_71 + 1 ;
F_10 ( V_4 , V_74 ) ;
return 1 ;
}
V_51 = ( V_39 - 1 ) * V_52 ;
V_43 = F_2 ( V_4 -> V_44 ) ;
for (; ; ) {
unsigned long V_76 ;
int V_10 ;
V_10 = ( V_41 >> V_51 ) & V_54 ;
if ( ! V_43 -> V_35 [ V_10 ] )
goto V_77;
if ( ! F_8 ( V_43 , V_73 , V_10 ) )
goto V_77;
if ( V_51 ) {
V_8 = V_43 ;
V_43 = V_43 -> V_35 [ V_10 ] ;
if ( F_26 ( V_43 ) ) {
V_43 = F_2 ( V_43 ) ;
V_51 -= V_52 ;
continue;
} else {
V_43 = V_8 ;
V_8 = V_8 -> V_48 ;
}
}
V_75 += 1 << V_51 ;
F_4 ( V_43 , V_74 , V_10 ) ;
V_76 = V_41 ;
while ( V_8 ) {
V_76 >>= V_52 ;
V_10 = V_76 & V_54 ;
if ( F_8 ( V_8 , V_74 , V_10 ) )
break;
F_4 ( V_8 , V_74 , V_10 ) ;
V_8 = V_8 -> V_48 ;
}
V_8 = NULL ;
V_77:
V_41 = ( ( V_41 >> V_51 ) + 1 ) << V_51 ;
if ( V_41 > V_71 || ! V_41 )
break;
if ( V_75 >= V_72 )
break;
while ( ( ( V_41 >> V_51 ) & V_54 ) == 0 ) {
V_43 = V_43 -> V_48 ;
V_51 += V_52 ;
}
}
if ( V_75 > 0 )
F_10 ( V_4 , V_74 ) ;
* V_70 = V_41 ;
return V_75 ;
}
unsigned int
F_52 ( struct V_3 * V_4 , void * * V_78 ,
unsigned long V_79 , unsigned int V_80 )
{
struct V_59 V_60 ;
void * * V_43 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_80 ) )
return 0 ;
F_54 (slot, root, &iter, first_index) {
V_78 [ V_20 ] = F_43 ( * V_43 ) ;
if ( ! V_78 [ V_20 ] )
continue;
if ( F_26 ( V_78 [ V_20 ] ) ) {
V_43 = F_55 ( & V_60 ) ;
continue;
}
if ( ++ V_20 == V_80 )
break;
}
return V_20 ;
}
unsigned int
F_56 ( struct V_3 * V_4 ,
void * * * V_78 , unsigned long * V_81 ,
unsigned long V_79 , unsigned int V_80 )
{
struct V_59 V_60 ;
void * * V_43 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_80 ) )
return 0 ;
F_54 (slot, root, &iter, first_index) {
V_78 [ V_20 ] = V_43 ;
if ( V_81 )
V_81 [ V_20 ] = V_60 . V_41 ;
if ( ++ V_20 == V_80 )
break;
}
return V_20 ;
}
unsigned int
F_57 ( struct V_3 * V_4 , void * * V_78 ,
unsigned long V_79 , unsigned int V_80 ,
unsigned int V_9 )
{
struct V_59 V_60 ;
void * * V_43 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_80 ) )
return 0 ;
F_58 (slot, root, &iter, first_index, tag) {
V_78 [ V_20 ] = F_43 ( * V_43 ) ;
if ( ! V_78 [ V_20 ] )
continue;
if ( F_26 ( V_78 [ V_20 ] ) ) {
V_43 = F_55 ( & V_60 ) ;
continue;
}
if ( ++ V_20 == V_80 )
break;
}
return V_20 ;
}
unsigned int
F_59 ( struct V_3 * V_4 , void * * * V_78 ,
unsigned long V_79 , unsigned int V_80 ,
unsigned int V_9 )
{
struct V_59 V_60 ;
void * * V_43 ;
unsigned int V_20 = 0 ;
if ( F_53 ( ! V_80 ) )
return 0 ;
F_58 (slot, root, &iter, first_index, tag) {
V_78 [ V_20 ] = V_43 ;
if ( ++ V_20 == V_80 )
break;
}
return V_20 ;
}
static unsigned long F_60 ( struct V_7 * V_43 , void * V_57 ,
unsigned long V_41 , unsigned long * V_82 )
{
unsigned int V_51 , V_39 ;
unsigned long V_33 ;
V_39 = V_43 -> V_47 & V_46 ;
V_51 = ( V_39 - 1 ) * V_52 ;
for ( ; V_39 > 1 ; V_39 -- ) {
V_33 = ( V_41 >> V_51 ) & V_54 ;
for (; ; ) {
if ( V_43 -> V_35 [ V_33 ] != NULL )
break;
V_41 &= ~ ( ( 1UL << V_51 ) - 1 ) ;
V_41 += 1UL << V_51 ;
if ( V_41 == 0 )
goto V_26;
V_33 ++ ;
if ( V_33 == V_66 )
goto V_26;
}
V_43 = F_43 ( V_43 -> V_35 [ V_33 ] ) ;
if ( V_43 == NULL )
goto V_26;
if ( ! F_26 ( V_43 ) ) {
if ( V_43 == V_57 ) {
* V_82 = V_41 + V_33 ;
V_41 = 0 ;
} else {
V_41 += V_51 ;
}
goto V_26;
}
V_43 = F_2 ( V_43 ) ;
V_51 -= V_52 ;
}
for ( V_33 = 0 ; V_33 < V_66 ; V_33 ++ ) {
if ( V_43 -> V_35 [ V_33 ] == V_57 ) {
* V_82 = V_41 + V_33 ;
V_41 = 0 ;
goto V_26;
}
}
V_41 += V_66 ;
V_26:
return V_41 ;
}
unsigned long F_61 ( struct V_3 * V_4 , void * V_57 )
{
struct V_7 * V_8 ;
unsigned long V_83 ;
unsigned long V_84 = 0 ;
unsigned long V_82 = - 1 ;
do {
F_62 () ;
V_8 = F_43 ( V_4 -> V_44 ) ;
if ( ! F_26 ( V_8 ) ) {
F_63 () ;
if ( V_8 == V_57 )
V_82 = 0 ;
break;
}
V_8 = F_2 ( V_8 ) ;
V_83 = F_37 ( V_8 -> V_47 &
V_46 ) ;
if ( V_84 > V_83 ) {
F_63 () ;
break;
}
V_84 = F_60 ( V_8 , V_57 , V_84 , & V_82 ) ;
F_63 () ;
F_64 () ;
} while ( V_84 != 0 && V_84 <= V_83 );
return V_82 ;
}
unsigned long F_61 ( struct V_3 * V_4 , void * V_57 )
{
return - 1 ;
}
static inline void F_65 ( struct V_3 * V_4 )
{
while ( V_4 -> V_39 > 0 ) {
struct V_7 * V_85 = V_4 -> V_44 ;
struct V_7 * V_43 ;
F_25 ( ! F_26 ( V_85 ) ) ;
V_85 = F_2 ( V_85 ) ;
if ( V_85 -> V_36 != 1 )
break;
V_43 = V_85 -> V_35 [ 0 ] ;
if ( ! V_43 )
break;
if ( V_4 -> V_39 > 1 ) {
if ( ! F_26 ( V_43 ) )
break;
V_43 = F_2 ( V_43 ) ;
V_43 -> V_48 = NULL ;
V_43 = F_1 ( V_43 ) ;
}
V_4 -> V_44 = V_43 ;
V_4 -> V_39 -- ;
if ( V_4 -> V_39 == 0 )
* ( ( unsigned long * ) & V_85 -> V_35 [ 0 ] ) |=
V_2 ;
F_30 ( V_85 ) ;
}
}
bool F_66 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
bool V_86 = false ;
do {
struct V_7 * V_48 ;
if ( V_8 -> V_36 ) {
if ( V_8 == F_2 ( V_4 -> V_44 ) ) {
F_65 ( V_4 ) ;
if ( V_4 -> V_39 == 0 )
V_86 = true ;
}
return V_86 ;
}
V_48 = V_8 -> V_48 ;
if ( V_48 ) {
unsigned int V_10 ;
V_10 = V_8 -> V_47 >> V_53 ;
V_48 -> V_35 [ V_10 ] = NULL ;
V_48 -> V_36 -- ;
} else {
F_12 ( V_4 ) ;
V_4 -> V_39 = 0 ;
V_4 -> V_44 = NULL ;
}
F_30 ( V_8 ) ;
V_86 = true ;
V_8 = V_48 ;
} while ( V_8 );
return V_86 ;
}
void * F_67 ( struct V_3 * V_4 ,
unsigned long V_41 , void * V_57 )
{
struct V_7 * V_8 ;
unsigned int V_10 , V_33 ;
void * * V_43 ;
void * V_87 ;
int V_9 ;
V_87 = F_42 ( V_4 , V_41 , & V_8 , & V_43 ) ;
if ( ! V_87 )
return NULL ;
if ( V_57 && V_87 != V_57 )
return NULL ;
if ( ! V_8 ) {
F_12 ( V_4 ) ;
V_4 -> V_44 = NULL ;
return V_87 ;
}
V_10 = V_41 & V_54 ;
for ( V_9 = 0 ; V_9 < V_34 ; V_9 ++ ) {
if ( F_8 ( V_8 , V_9 , V_10 ) )
F_47 ( V_4 , V_41 , V_9 ) ;
}
for ( V_33 = 1 ; V_10 + V_33 < V_66 ; V_33 ++ ) {
if ( V_8 -> V_35 [ V_10 + V_33 ] != F_1 ( V_43 ) )
break;
V_8 -> V_35 [ V_10 + V_33 ] = NULL ;
V_8 -> V_36 -- ;
}
V_8 -> V_35 [ V_10 ] = NULL ;
V_8 -> V_36 -- ;
F_66 ( V_4 , V_8 ) ;
return V_87 ;
}
void * F_68 ( struct V_3 * V_4 , unsigned long V_41 )
{
return F_67 ( V_4 , V_41 , NULL ) ;
}
int F_69 ( struct V_3 * V_4 , unsigned int V_9 )
{
return F_13 ( V_4 , V_9 ) ;
}
static void
F_70 ( void * V_88 )
{
struct V_7 * V_8 = V_88 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_71 ( & V_8 -> V_89 ) ;
}
static T_3 unsigned long F_72 ( unsigned int V_39 )
{
unsigned int V_90 = V_39 * V_52 ;
int V_51 = V_91 - V_90 ;
if ( V_51 < 0 )
return ~ 0UL ;
if ( V_51 >= V_19 )
return 0UL ;
return ~ 0UL >> V_51 ;
}
static T_3 void F_73 ( void )
{
unsigned int V_33 ;
for ( V_33 = 0 ; V_33 < F_74 ( V_40 ) ; V_33 ++ )
V_40 [ V_33 ] = F_72 ( V_33 ) ;
}
static int F_75 ( struct V_92 * V_93 ,
unsigned long V_94 ,
void * V_95 )
{
int V_96 = ( long ) V_95 ;
struct V_21 * V_22 ;
struct V_7 * V_8 ;
if ( V_94 == V_97 || V_94 == V_98 ) {
V_22 = & F_76 ( V_27 , V_96 ) ;
while ( V_22 -> V_28 ) {
V_8 = V_22 -> V_29 ;
V_22 -> V_29 = V_8 -> V_30 ;
F_29 ( V_23 , V_8 ) ;
V_22 -> V_28 -- ;
}
}
return V_99 ;
}
void T_3 F_77 ( void )
{
V_23 = F_78 ( L_1 ,
sizeof( struct V_7 ) , 0 ,
V_100 | V_101 ,
F_70 ) ;
F_73 () ;
F_79 ( F_75 , 0 ) ;
}
