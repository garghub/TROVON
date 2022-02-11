static inline struct V_1 * F_1 ( void * V_2 )
{
return ( void * ) ( ( unsigned long ) V_2 & ~ V_3 ) ;
}
static inline void * F_2 ( void * V_2 )
{
return ( void * ) ( ( unsigned long ) V_2 | V_3 ) ;
}
static inline bool F_3 ( struct V_1 * V_4 , void * V_5 )
{
void * * V_2 = V_5 ;
return ( V_4 -> V_6 <= V_2 ) &&
( V_2 < V_4 -> V_6 + V_7 ) ;
}
static inline bool F_3 ( struct V_1 * V_4 , void * V_5 )
{
return false ;
}
static inline unsigned long F_4 ( struct V_1 * V_4 ,
void * * V_8 )
{
return V_8 - V_4 -> V_6 ;
}
static unsigned int F_5 ( struct V_1 * V_4 ,
struct V_1 * * V_9 , unsigned long V_10 )
{
unsigned int V_11 = ( V_10 >> V_4 -> V_12 ) & V_13 ;
void * * V_14 = F_6 ( V_4 -> V_6 [ V_11 ] ) ;
#ifdef F_7
if ( F_8 ( V_14 ) ) {
if ( F_3 ( V_4 , V_14 ) ) {
void * * V_15 = ( void * * ) F_1 ( V_14 ) ;
V_11 = F_4 ( V_4 , V_15 ) ;
V_14 = F_6 ( * V_15 ) ;
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
static inline void F_10 ( struct V_1 * V_5 , unsigned int V_20 ,
int V_11 )
{
F_11 ( V_11 , V_5 -> V_21 [ V_20 ] ) ;
}
static inline void F_12 ( struct V_1 * V_5 , unsigned int V_20 ,
int V_11 )
{
F_13 ( V_11 , V_5 -> V_21 [ V_20 ] ) ;
}
static inline int F_14 ( struct V_1 * V_5 , unsigned int V_20 ,
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
static inline int F_21 ( struct V_1 * V_5 , unsigned int V_20 )
{
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( V_5 -> V_21 [ V_20 ] [ V_24 ] )
return 1 ;
}
return 0 ;
}
static T_2 unsigned long
F_22 ( struct V_1 * V_5 , unsigned int V_20 ,
unsigned long V_11 )
{
const unsigned long * V_26 = V_5 -> V_21 [ V_20 ] ;
if ( V_11 < V_7 ) {
unsigned long V_27 ;
V_26 += V_11 / V_28 ;
V_27 = * V_26 >> ( V_11 % V_28 ) ;
if ( V_27 )
return F_23 ( V_27 ) + V_11 ;
V_11 = ( V_11 + V_28 ) & ~ ( V_28 - 1 ) ;
while ( V_11 < V_7 ) {
V_27 = * ++ V_26 ;
if ( V_27 )
return F_23 ( V_27 ) + V_11 ;
V_11 += V_28 ;
}
}
return V_7 ;
}
static unsigned int F_24 ( const struct V_29 * V_30 )
{
return ( V_30 -> V_10 >> F_25 ( V_30 ) ) & V_13 ;
}
static inline unsigned long F_26 ( unsigned int V_12 )
{
return ( V_7 << V_12 ) - 1 ;
}
static inline unsigned long F_27 ( struct V_1 * V_5 )
{
return F_26 ( V_5 -> V_12 ) ;
}
static void F_28 ( struct V_1 * V_5 , unsigned long V_10 )
{
unsigned long V_31 ;
F_29 ( L_1 ,
V_5 , V_5 -> V_11 , V_10 , V_10 | F_27 ( V_5 ) ,
V_5 -> V_4 ,
V_5 -> V_21 [ 0 ] [ 0 ] , V_5 -> V_21 [ 1 ] [ 0 ] , V_5 -> V_21 [ 2 ] [ 0 ] ,
V_5 -> V_12 , V_5 -> V_32 , V_5 -> V_33 ) ;
for ( V_31 = 0 ; V_31 < V_7 ; V_31 ++ ) {
unsigned long V_34 = V_10 | ( V_31 << V_5 -> V_12 ) ;
unsigned long V_35 = V_34 | ( ( 1UL << V_5 -> V_12 ) - 1 ) ;
void * V_14 = V_5 -> V_6 [ V_31 ] ;
if ( ! V_14 )
continue;
if ( V_14 == V_36 ) {
F_29 ( L_2 ,
V_31 , V_34 , V_35 , V_5 ) ;
} else if ( ! F_8 ( V_14 ) ) {
F_29 ( L_3 ,
V_14 , V_31 , V_34 , V_35 , V_5 ) ;
} else if ( F_3 ( V_5 , V_14 ) ) {
F_29 ( L_4 ,
V_14 , V_31 , V_34 , V_35 , V_5 ,
* ( void * * ) F_1 ( V_14 ) ) ;
} else {
F_28 ( F_1 ( V_14 ) , V_34 ) ;
}
}
}
static void F_30 ( struct V_16 * V_17 )
{
F_29 ( L_5 ,
V_17 , V_17 -> V_37 ,
V_17 -> V_18 >> V_23 ) ;
if ( ! F_8 ( V_17 -> V_37 ) )
return;
F_28 ( F_1 ( V_17 -> V_37 ) , 0 ) ;
}
static struct V_1 *
F_31 ( struct V_16 * V_17 ,
struct V_1 * V_4 ,
unsigned int V_12 , unsigned int V_11 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_1 * V_38 = NULL ;
T_1 V_18 = F_9 ( V_17 ) ;
if ( ! F_32 ( V_18 ) && ! F_33 () ) {
struct V_39 * V_40 ;
V_38 = F_34 ( V_41 ,
V_18 | V_42 ) ;
if ( V_38 )
goto V_43;
V_40 = F_35 ( & V_44 ) ;
if ( V_40 -> V_45 ) {
V_38 = V_40 -> V_46 ;
V_40 -> V_46 = V_38 -> V_47 ;
V_38 -> V_47 = NULL ;
V_40 -> V_45 -- ;
}
F_36 ( V_38 ) ;
goto V_43;
}
V_38 = F_34 ( V_41 , V_18 ) ;
V_43:
F_37 ( F_8 ( V_38 ) ) ;
if ( V_38 ) {
V_38 -> V_4 = V_4 ;
V_38 -> V_12 = V_12 ;
V_38 -> V_11 = V_11 ;
V_38 -> V_32 = V_32 ;
V_38 -> V_33 = V_33 ;
}
return V_38 ;
}
static void F_38 ( struct V_48 * V_49 )
{
struct V_1 * V_5 =
F_39 ( V_49 , struct V_1 , V_48 ) ;
memset ( V_5 -> V_6 , 0 , sizeof( V_5 -> V_6 ) ) ;
memset ( V_5 -> V_21 , 0 , sizeof( V_5 -> V_21 ) ) ;
F_40 ( & V_5 -> V_50 ) ;
F_41 ( V_41 , V_5 ) ;
}
static inline void
F_42 ( struct V_1 * V_5 )
{
F_43 ( & V_5 -> V_48 , F_38 ) ;
}
static int F_44 ( T_1 V_18 , unsigned V_45 )
{
struct V_39 * V_40 ;
struct V_1 * V_5 ;
int V_38 = - V_51 ;
V_18 &= ~ V_52 ;
F_45 () ;
V_40 = F_35 ( & V_44 ) ;
while ( V_40 -> V_45 < V_45 ) {
F_46 () ;
V_5 = F_34 ( V_41 , V_18 ) ;
if ( V_5 == NULL )
goto V_43;
F_45 () ;
V_40 = F_35 ( & V_44 ) ;
if ( V_40 -> V_45 < V_45 ) {
V_5 -> V_47 = V_40 -> V_46 ;
V_40 -> V_46 = V_5 ;
V_40 -> V_45 ++ ;
} else {
F_41 ( V_41 , V_5 ) ;
}
}
V_38 = 0 ;
V_43:
return V_38 ;
}
int V_39 ( T_1 V_18 )
{
F_47 ( ! F_32 ( V_18 ) ) ;
return F_44 ( V_18 , V_53 ) ;
}
int F_48 ( T_1 V_18 )
{
if ( F_32 ( V_18 ) )
return F_44 ( V_18 , V_53 ) ;
F_45 () ;
return 0 ;
}
int F_49 ( unsigned int V_54 , unsigned int V_55 ,
T_1 V_18 )
{
unsigned V_56 = 1 << ( V_54 % V_57 ) ;
unsigned V_58 = ( V_54 / V_57 ) -
( V_55 / V_57 ) ;
unsigned V_45 = 0 ;
F_47 ( ! F_32 ( V_18 ) ) ;
F_37 ( V_55 >= V_54 ) ;
while ( V_58 -- )
V_45 = V_45 * V_7 + 1 ;
return F_44 ( V_18 , V_56 * V_45 ) ;
}
int F_50 ( T_1 V_18 , int V_59 )
{
unsigned long V_60 ;
int V_61 , V_62 ;
if ( ! F_32 ( V_18 ) ) {
F_45 () ;
return 0 ;
}
V_60 = 1 << V_59 ;
for ( V_62 = 0 ; V_60 > V_7 ;
V_62 ++ )
V_60 >>= V_57 ;
V_61 = V_63 ;
V_61 += V_63 - V_62 ;
V_61 -- ;
V_61 += V_60 * V_64 [ V_62 ] ;
return F_44 ( V_18 , V_61 ) ;
}
static unsigned F_51 ( struct V_16 * V_17 ,
struct V_1 * * V_9 , unsigned long * V_65 )
{
struct V_1 * V_5 = F_6 ( V_17 -> V_37 ) ;
* V_9 = V_5 ;
if ( F_52 ( F_8 ( V_5 ) ) ) {
V_5 = F_1 ( V_5 ) ;
* V_65 = F_27 ( V_5 ) ;
return V_5 -> V_12 + V_57 ;
}
* V_65 = 0 ;
return 0 ;
}
static int F_53 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_12 )
{
struct V_1 * V_8 ;
unsigned int V_66 ;
int V_20 ;
V_66 = V_12 ;
while ( V_10 > F_26 ( V_66 ) )
V_66 += V_57 ;
V_8 = V_17 -> V_37 ;
if ( ! V_8 )
goto V_43;
do {
struct V_1 * V_5 = F_31 ( V_17 ,
NULL , V_12 , 0 , 1 , 0 ) ;
if ( ! V_5 )
return - V_51 ;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ ) {
if ( F_19 ( V_17 , V_20 ) )
F_10 ( V_5 , V_20 , 0 ) ;
}
F_37 ( V_12 > V_28 ) ;
if ( F_8 ( V_8 ) ) {
F_1 ( V_8 ) -> V_4 = V_5 ;
} else if ( F_54 ( V_8 ) ) {
V_5 -> V_33 = 1 ;
}
V_5 -> V_6 [ 0 ] = V_8 ;
V_8 = F_2 ( V_5 ) ;
F_55 ( V_17 -> V_37 , V_8 ) ;
V_12 += V_57 ;
} while ( V_12 <= V_66 );
V_43:
return V_66 + V_57 ;
}
static inline void F_56 ( struct V_16 * V_17 ,
T_3 V_68 ,
void * V_69 )
{
for (; ; ) {
struct V_1 * V_5 = V_17 -> V_37 ;
struct V_1 * V_70 ;
if ( ! F_8 ( V_5 ) )
break;
V_5 = F_1 ( V_5 ) ;
if ( V_5 -> V_32 != 1 )
break;
V_70 = V_5 -> V_6 [ 0 ] ;
if ( ! V_70 )
break;
if ( ! F_8 ( V_70 ) && V_5 -> V_12 )
break;
if ( F_8 ( V_70 ) )
F_1 ( V_70 ) -> V_4 = NULL ;
V_17 -> V_37 = V_70 ;
V_5 -> V_32 = 0 ;
if ( ! F_8 ( V_70 ) ) {
V_5 -> V_6 [ 0 ] = V_36 ;
if ( V_68 )
V_68 ( V_5 , V_69 ) ;
}
F_47 ( ! F_57 ( & V_5 -> V_50 ) ) ;
F_42 ( V_5 ) ;
}
}
static void F_58 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
T_3 V_68 , void * V_69 )
{
do {
struct V_1 * V_4 ;
if ( V_5 -> V_32 ) {
if ( V_5 == F_1 ( V_17 -> V_37 ) )
F_56 ( V_17 , V_68 , V_69 ) ;
return;
}
V_4 = V_5 -> V_4 ;
if ( V_4 ) {
V_4 -> V_6 [ V_5 -> V_11 ] = NULL ;
V_4 -> V_32 -- ;
} else {
F_18 ( V_17 ) ;
V_17 -> V_37 = NULL ;
}
F_47 ( ! F_57 ( & V_5 -> V_50 ) ) ;
F_42 ( V_5 ) ;
V_5 = V_4 ;
} while ( V_5 );
}
int F_59 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_59 , struct V_1 * * V_9 ,
void * * * V_71 )
{
struct V_1 * V_5 = NULL , * V_70 ;
void * * V_8 = ( void * * ) & V_17 -> V_37 ;
unsigned long V_65 ;
unsigned int V_12 , V_11 = 0 ;
unsigned long V_72 = V_10 | ( ( 1UL << V_59 ) - 1 ) ;
V_12 = F_51 ( V_17 , & V_70 , & V_65 ) ;
if ( V_59 > 0 && V_72 == ( ( 1UL << V_59 ) - 1 ) )
V_72 ++ ;
if ( V_72 > V_65 ) {
int error = F_53 ( V_17 , V_72 , V_12 ) ;
if ( error < 0 )
return error ;
V_12 = error ;
V_70 = V_17 -> V_37 ;
}
while ( V_12 > V_59 ) {
V_12 -= V_57 ;
if ( V_70 == NULL ) {
V_70 = F_31 ( V_17 , V_5 , V_12 ,
V_11 , 0 , 0 ) ;
if ( ! V_70 )
return - V_51 ;
F_55 ( * V_8 , F_2 ( V_70 ) ) ;
if ( V_5 )
V_5 -> V_32 ++ ;
} else if ( ! F_8 ( V_70 ) )
break;
V_5 = F_1 ( V_70 ) ;
V_11 = F_5 ( V_5 , & V_70 , V_10 ) ;
V_8 = & V_5 -> V_6 [ V_11 ] ;
}
if ( V_9 )
* V_9 = V_5 ;
if ( V_71 )
* V_71 = V_8 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_5 )
{
unsigned V_11 = 0 ;
struct V_1 * V_70 = F_1 ( V_5 ) ;
for (; ; ) {
void * V_14 = V_70 -> V_6 [ V_11 ] ;
if ( F_8 ( V_14 ) &&
! F_3 ( V_70 , V_14 ) ) {
V_70 = F_1 ( V_14 ) ;
V_11 = 0 ;
continue;
}
V_11 ++ ;
while ( V_11 == V_7 ) {
struct V_1 * V_73 = V_70 ;
V_11 = V_70 -> V_11 + 1 ;
V_70 = V_70 -> V_4 ;
F_47 ( ! F_57 ( & V_73 -> V_50 ) ) ;
F_42 ( V_73 ) ;
if ( V_73 == F_1 ( V_5 ) )
return;
}
}
}
static inline int F_61 ( struct V_1 * V_5 , void * * V_8 ,
void * V_74 , unsigned V_59 , bool V_75 )
{
struct V_1 * V_70 ;
unsigned V_31 , V_76 , V_20 , V_11 , V_21 = 0 ;
if ( V_5 ) {
if ( V_59 > V_5 -> V_12 )
V_76 = 1 << ( V_59 - V_5 -> V_12 ) ;
else
V_76 = 1 ;
V_11 = F_4 ( V_5 , V_8 ) ;
} else {
V_76 = 1 ;
V_11 = 0 ;
}
if ( V_76 > 1 ) {
V_11 = V_11 & ~ ( V_76 - 1 ) ;
V_8 = & V_5 -> V_6 [ V_11 ] ;
}
V_70 = F_2 ( V_8 ) ;
for ( V_31 = 0 ; V_31 < V_76 ; V_31 ++ ) {
if ( V_8 [ V_31 ] ) {
if ( V_75 ) {
V_5 -> V_32 -- ;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ )
if ( F_14 ( V_5 , V_20 , V_11 + V_31 ) )
V_21 |= 1 << V_20 ;
} else
return - V_77 ;
}
}
for ( V_31 = 0 ; V_31 < V_76 ; V_31 ++ ) {
struct V_1 * V_73 = V_8 [ V_31 ] ;
if ( V_31 ) {
F_55 ( V_8 [ V_31 ] , V_70 ) ;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ )
if ( V_21 & ( 1 << V_20 ) )
F_12 ( V_5 , V_20 , V_11 + V_31 ) ;
} else {
F_55 ( V_8 [ V_31 ] , V_74 ) ;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ )
if ( V_21 & ( 1 << V_20 ) )
F_10 ( V_5 , V_20 , V_11 ) ;
}
if ( F_8 ( V_73 ) &&
! F_3 ( V_5 , V_73 ) &&
( V_73 != V_36 ) )
F_60 ( V_73 ) ;
if ( F_54 ( V_73 ) )
V_5 -> V_33 -- ;
}
if ( V_5 ) {
V_5 -> V_32 += V_76 ;
if ( F_54 ( V_74 ) )
V_5 -> V_33 += V_76 ;
}
return V_76 ;
}
static inline int F_61 ( struct V_1 * V_5 , void * * V_8 ,
void * V_74 , unsigned V_59 , bool V_75 )
{
if ( * V_8 )
return - V_77 ;
F_55 ( * V_8 , V_74 ) ;
if ( V_5 ) {
V_5 -> V_32 ++ ;
if ( F_54 ( V_74 ) )
V_5 -> V_33 ++ ;
}
return 1 ;
}
int F_62 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_59 , void * V_74 )
{
struct V_1 * V_5 ;
void * * V_8 ;
int error ;
F_37 ( F_8 ( V_74 ) ) ;
error = F_59 ( V_17 , V_10 , V_59 , & V_5 , & V_8 ) ;
if ( error )
return error ;
error = F_61 ( V_5 , V_8 , V_74 , V_59 , false ) ;
if ( error < 0 )
return error ;
if ( V_5 ) {
unsigned V_11 = F_4 ( V_5 , V_8 ) ;
F_37 ( F_14 ( V_5 , 0 , V_11 ) ) ;
F_37 ( F_14 ( V_5 , 1 , V_11 ) ) ;
F_37 ( F_14 ( V_5 , 2 , V_11 ) ) ;
} else {
F_37 ( F_20 ( V_17 ) ) ;
}
return 0 ;
}
void * F_63 ( struct V_16 * V_17 , unsigned long V_10 ,
struct V_1 * * V_9 , void * * * V_71 )
{
struct V_1 * V_5 , * V_4 ;
unsigned long V_65 ;
void * * V_8 ;
V_78:
V_4 = NULL ;
V_8 = ( void * * ) & V_17 -> V_37 ;
F_51 ( V_17 , & V_5 , & V_65 ) ;
if ( V_10 > V_65 )
return NULL ;
while ( F_8 ( V_5 ) ) {
unsigned V_11 ;
if ( V_5 == V_36 )
goto V_78;
V_4 = F_1 ( V_5 ) ;
V_11 = F_5 ( V_4 , & V_5 , V_10 ) ;
V_8 = V_4 -> V_6 + V_11 ;
}
if ( V_9 )
* V_9 = V_4 ;
if ( V_71 )
* V_71 = V_8 ;
return V_5 ;
}
void * * F_64 ( struct V_16 * V_17 , unsigned long V_10 )
{
void * * V_8 ;
if ( ! F_63 ( V_17 , V_10 , NULL , & V_8 ) )
return NULL ;
return V_8 ;
}
void * F_65 ( struct V_16 * V_17 , unsigned long V_10 )
{
return F_63 ( V_17 , V_10 , NULL , NULL ) ;
}
static inline int F_66 ( struct V_1 * V_5 ,
void * * V_8 )
{
int V_76 = 1 ;
#ifdef F_7
void * V_2 = F_2 ( V_8 ) ;
unsigned V_11 = F_4 ( V_5 , V_8 ) ;
int V_31 ;
for ( V_31 = 1 ; V_11 + V_31 < V_7 ; V_31 ++ ) {
if ( V_5 -> V_6 [ V_11 + V_31 ] != V_2 )
break;
V_76 ++ ;
}
#endif
return V_76 ;
}
static void F_67 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
void * * V_8 , void * V_74 ,
bool V_79 )
{
void * V_73 = F_6 ( * V_8 ) ;
int V_32 , V_33 ;
F_47 ( F_8 ( V_74 ) ) ;
V_32 = ! ! V_74 - ! ! V_73 ;
V_33 = ! ! F_54 ( V_74 ) -
! ! F_54 ( V_73 ) ;
F_47 ( V_79 && ( V_32 || V_33 ) ) ;
if ( V_5 ) {
V_5 -> V_32 += V_32 ;
if ( V_33 ) {
V_33 *= F_66 ( V_5 , V_8 ) ;
V_5 -> V_33 += V_33 ;
}
}
F_55 ( * V_8 , V_74 ) ;
}
static inline void F_68 ( struct V_1 * V_5 ,
void * * V_8 )
{
#ifdef F_7
bool V_33 = F_54 ( * V_8 ) ;
void * V_2 = F_2 ( V_8 ) ;
unsigned V_11 = F_4 ( V_5 , V_8 ) ;
int V_31 ;
for ( V_31 = 1 ; V_11 + V_31 < V_7 ; V_31 ++ ) {
if ( V_5 -> V_6 [ V_11 + V_31 ] != V_2 )
break;
V_5 -> V_6 [ V_11 + V_31 ] = NULL ;
V_5 -> V_32 -- ;
if ( V_33 )
V_5 -> V_33 -- ;
}
#endif
}
void F_69 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
void * * V_8 , void * V_74 ,
T_3 V_68 , void * V_69 )
{
if ( ! V_74 )
F_68 ( V_5 , V_8 ) ;
F_67 ( V_17 , V_5 , V_8 , V_74 ,
! V_5 && V_8 != ( void * * ) & V_17 -> V_37 ) ;
if ( ! V_5 )
return;
if ( V_68 )
V_68 ( V_5 , V_69 ) ;
F_58 ( V_17 , V_5 , V_68 , V_69 ) ;
}
void F_70 ( struct V_16 * V_17 ,
void * * V_8 , void * V_74 )
{
F_67 ( V_17 , NULL , V_8 , V_74 , true ) ;
}
void F_71 ( struct V_16 * V_17 ,
const struct V_29 * V_30 , void * * V_8 , void * V_74 )
{
F_69 ( V_17 , V_30 -> V_5 , V_8 , V_74 , NULL , NULL ) ;
}
int F_72 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_59 , void * V_74 )
{
struct V_1 * V_5 ;
void * * V_8 ;
int error ;
F_37 ( F_8 ( V_74 ) ) ;
error = F_59 ( V_17 , V_10 , V_59 , & V_5 , & V_8 ) ;
if ( ! error )
error = F_61 ( V_5 , V_8 , V_74 , V_59 , true ) ;
if ( error > 0 )
error = 0 ;
return error ;
}
int F_73 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_59 )
{
struct V_1 * V_4 , * V_5 , * V_70 ;
void * * V_8 ;
unsigned int V_11 , V_80 ;
unsigned V_76 , V_20 , V_21 = 0 ;
if ( ! F_63 ( V_17 , V_10 , & V_4 , & V_8 ) )
return - V_81 ;
if ( ! V_4 )
return - V_81 ;
V_11 = F_4 ( V_4 , V_8 ) ;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ )
if ( F_14 ( V_4 , V_20 , V_11 ) )
V_21 |= 1 << V_20 ;
for ( V_80 = V_11 + 1 ; V_80 < V_7 ; V_80 ++ ) {
if ( ! F_3 ( V_4 , V_4 -> V_6 [ V_80 ] ) )
break;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ )
if ( V_21 & ( 1 << V_20 ) )
F_10 ( V_4 , V_20 , V_80 ) ;
F_55 ( V_4 -> V_6 [ V_80 ] , V_36 ) ;
}
F_55 ( V_4 -> V_6 [ V_11 ] , V_36 ) ;
V_4 -> V_33 -= ( V_80 - V_11 ) ;
if ( V_59 == V_4 -> V_12 )
return 0 ;
if ( V_59 > V_4 -> V_12 ) {
while ( V_11 < V_80 )
V_11 += F_61 ( V_4 , & V_4 -> V_6 [ V_11 ] ,
V_36 , V_59 , true ) ;
return 0 ;
}
V_5 = V_4 ;
for (; ; ) {
if ( V_5 -> V_12 > V_59 ) {
V_70 = F_31 ( V_17 , V_5 ,
V_5 -> V_12 - V_57 ,
V_11 , 0 , 0 ) ;
if ( ! V_70 )
goto V_82;
if ( V_5 != V_4 ) {
V_5 -> V_32 ++ ;
V_5 -> V_6 [ V_11 ] = F_2 ( V_70 ) ;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ )
if ( V_21 & ( 1 << V_20 ) )
F_10 ( V_5 , V_20 , V_11 ) ;
}
V_5 = V_70 ;
V_11 = 0 ;
continue;
}
V_76 = F_61 ( V_5 , & V_5 -> V_6 [ V_11 ] ,
V_36 , V_59 , false ) ;
F_37 ( V_76 > V_7 ) ;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ )
if ( V_21 & ( 1 << V_20 ) )
F_10 ( V_5 , V_20 , V_11 ) ;
V_11 += V_76 ;
while ( V_11 == V_7 ) {
if ( V_5 == V_4 )
break;
V_11 = V_5 -> V_11 ;
V_70 = V_5 ;
V_5 = V_5 -> V_4 ;
F_55 ( V_5 -> V_6 [ V_11 ] ,
F_2 ( V_70 ) ) ;
V_11 ++ ;
}
if ( ( V_5 == V_4 ) && ( V_11 == V_80 ) )
return 0 ;
}
V_82:
F_74 ( 1 ) ;
return - V_51 ;
}
void * F_75 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_1 * V_5 , * V_4 ;
unsigned long V_65 ;
F_51 ( V_17 , & V_5 , & V_65 ) ;
F_37 ( V_10 > V_65 ) ;
while ( F_8 ( V_5 ) ) {
unsigned V_11 ;
V_4 = F_1 ( V_5 ) ;
V_11 = F_5 ( V_4 , & V_5 , V_10 ) ;
F_37 ( ! V_5 ) ;
if ( ! F_14 ( V_4 , V_20 , V_11 ) )
F_10 ( V_4 , V_20 , V_11 ) ;
}
if ( ! F_19 ( V_17 , V_20 ) )
F_16 ( V_17 , V_20 ) ;
return V_5 ;
}
static void F_76 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
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
static void F_77 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
unsigned int V_20 , unsigned int V_11 )
{
while ( V_5 ) {
if ( F_14 ( V_5 , V_20 , V_11 ) )
return;
F_10 ( V_5 , V_20 , V_11 ) ;
V_11 = V_5 -> V_11 ;
V_5 = V_5 -> V_4 ;
}
if ( ! F_19 ( V_17 , V_20 ) )
F_16 ( V_17 , V_20 ) ;
}
void F_78 ( struct V_16 * V_17 ,
const struct V_29 * V_30 , unsigned int V_20 )
{
F_77 ( V_17 , V_30 -> V_5 , V_20 , F_24 ( V_30 ) ) ;
}
void * F_79 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_1 * V_5 , * V_4 ;
unsigned long V_65 ;
int V_83 ( V_11 ) ;
F_51 ( V_17 , & V_5 , & V_65 ) ;
if ( V_10 > V_65 )
return NULL ;
V_4 = NULL ;
while ( F_8 ( V_5 ) ) {
V_4 = F_1 ( V_5 ) ;
V_11 = F_5 ( V_4 , & V_5 , V_10 ) ;
}
if ( V_5 )
F_76 ( V_17 , V_4 , V_20 , V_11 ) ;
return V_5 ;
}
int F_80 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_1 * V_5 , * V_4 ;
unsigned long V_65 ;
if ( ! F_19 ( V_17 , V_20 ) )
return 0 ;
F_51 ( V_17 , & V_5 , & V_65 ) ;
if ( V_10 > V_65 )
return 0 ;
if ( V_5 == NULL )
return 0 ;
while ( F_8 ( V_5 ) ) {
unsigned V_11 ;
V_4 = F_1 ( V_5 ) ;
V_11 = F_5 ( V_4 , & V_5 , V_10 ) ;
if ( ! V_5 )
return 0 ;
if ( ! F_14 ( V_4 , V_20 , V_11 ) )
return 0 ;
if ( V_5 == V_36 )
break;
}
return 1 ;
}
static inline void F_81 ( struct V_29 * V_30 ,
unsigned int V_12 )
{
#ifdef F_7
V_30 -> V_12 = V_12 ;
#endif
}
static void F_82 ( struct V_29 * V_30 ,
struct V_1 * V_5 , unsigned V_11 ,
unsigned V_20 )
{
unsigned V_84 = V_11 / V_28 ;
unsigned V_85 = V_11 % V_28 ;
V_30 -> V_21 = V_5 -> V_21 [ V_20 ] [ V_84 ] >> V_85 ;
if ( V_84 < V_25 - 1 ) {
if ( V_85 )
V_30 -> V_21 |= V_5 -> V_21 [ V_20 ] [ V_84 + 1 ] <<
( V_28 - V_85 ) ;
V_30 -> V_86 = F_83 ( V_30 , V_28 ) ;
}
}
static void * * F_84 ( struct V_1 * * V_9 ,
void * * V_8 , struct V_29 * V_30 )
{
void * V_87 = F_2 ( V_8 - 1 ) ;
while ( V_30 -> V_10 < V_30 -> V_86 ) {
* V_9 = F_6 ( * V_8 ) ;
if ( * V_9 && * V_9 != V_87 )
return V_8 ;
V_8 ++ ;
V_30 -> V_10 = F_83 ( V_30 , 1 ) ;
V_30 -> V_21 >>= 1 ;
}
* V_9 = NULL ;
return NULL ;
}
void * * F_85 ( void * * V_8 , struct V_29 * V_30 ,
unsigned V_88 )
{
unsigned V_20 = V_88 & V_89 ;
struct V_1 * V_5 = F_6 ( * V_8 ) ;
V_8 = F_84 ( & V_5 , V_8 , V_30 ) ;
while ( F_8 ( V_5 ) ) {
unsigned V_11 ;
unsigned long V_86 ;
if ( V_5 == V_36 )
return V_8 ;
V_5 = F_1 ( V_5 ) ;
V_30 -> V_5 = V_5 ;
V_30 -> V_12 = V_5 -> V_12 ;
if ( V_88 & V_90 ) {
V_11 = F_22 ( V_5 , V_20 , 0 ) ;
if ( V_11 == V_7 )
return NULL ;
V_8 = & V_5 -> V_6 [ V_11 ] ;
V_30 -> V_10 = F_83 ( V_30 , V_11 ) ;
F_82 ( V_30 , V_5 , V_11 , V_20 ) ;
V_5 = F_6 ( * V_8 ) ;
} else {
V_11 = 0 ;
V_8 = & V_5 -> V_6 [ 0 ] ;
for (; ; ) {
V_5 = F_6 ( * V_8 ) ;
if ( V_5 )
break;
V_8 ++ ;
V_11 ++ ;
if ( V_11 == V_7 )
return NULL ;
}
V_30 -> V_10 = F_83 ( V_30 , V_11 ) ;
}
if ( ( V_88 & V_91 ) && ( V_11 > 0 ) )
goto V_92;
V_86 = ( V_30 -> V_10 | F_26 ( V_30 -> V_12 ) ) + 1 ;
if ( V_86 < V_30 -> V_86 )
V_30 -> V_86 = V_86 ;
}
return V_8 ;
V_92:
V_30 -> V_86 = 0 ;
return NULL ;
}
static void * * F_84 ( struct V_1 * * V_9 ,
void * * V_8 , struct V_29 * V_30 )
{
return V_8 ;
}
void * * F_86 ( void * * V_8 , struct V_29 * V_30 )
{
struct V_1 * V_5 ;
V_8 ++ ;
V_30 -> V_10 = F_83 ( V_30 , 1 ) ;
V_5 = F_6 ( * V_8 ) ;
F_84 ( & V_5 , V_8 , V_30 ) ;
V_30 -> V_86 = V_30 -> V_10 ;
V_30 -> V_21 = 0 ;
return NULL ;
}
void * * F_87 ( struct V_16 * V_17 ,
struct V_29 * V_30 , unsigned V_88 )
{
unsigned V_20 = V_88 & V_89 ;
struct V_1 * V_5 , * V_70 ;
unsigned long V_10 , V_11 , V_65 ;
if ( ( V_88 & V_90 ) && ! F_19 ( V_17 , V_20 ) )
return NULL ;
V_10 = V_30 -> V_86 ;
if ( ! V_10 && V_30 -> V_10 )
return NULL ;
V_78:
F_51 ( V_17 , & V_70 , & V_65 ) ;
if ( V_10 > V_65 )
return NULL ;
if ( ! V_70 )
return NULL ;
if ( ! F_8 ( V_70 ) ) {
V_30 -> V_10 = V_10 ;
V_30 -> V_86 = V_65 + 1 ;
V_30 -> V_21 = 1 ;
V_30 -> V_5 = NULL ;
F_81 ( V_30 , 0 ) ;
return ( void * * ) & V_17 -> V_37 ;
}
do {
V_5 = F_1 ( V_70 ) ;
V_11 = F_5 ( V_5 , & V_70 , V_10 ) ;
if ( ( V_88 & V_90 ) ?
! F_14 ( V_5 , V_20 , V_11 ) : ! V_70 ) {
if ( V_88 & V_91 )
return NULL ;
if ( V_88 & V_90 )
V_11 = F_22 ( V_5 , V_20 ,
V_11 + 1 ) ;
else
while ( ++ V_11 < V_7 ) {
void * V_8 = V_5 -> V_6 [ V_11 ] ;
if ( F_3 ( V_5 , V_8 ) )
continue;
if ( V_8 )
break;
}
V_10 &= ~ F_27 ( V_5 ) ;
V_10 += V_11 << V_5 -> V_12 ;
if ( ! V_10 )
return NULL ;
if ( V_11 == V_7 )
goto V_78;
V_70 = F_6 ( V_5 -> V_6 [ V_11 ] ) ;
}
if ( ! V_70 )
goto V_78;
if ( V_70 == V_36 )
break;
} while ( F_8 ( V_70 ) );
V_30 -> V_10 = ( V_10 & ~ F_27 ( V_5 ) ) | ( V_11 << V_5 -> V_12 ) ;
V_30 -> V_86 = ( V_10 | F_27 ( V_5 ) ) + 1 ;
V_30 -> V_5 = V_5 ;
F_81 ( V_30 , V_5 -> V_12 ) ;
if ( V_88 & V_90 )
F_82 ( V_30 , V_5 , V_11 , V_20 ) ;
return V_5 -> V_6 + V_11 ;
}
unsigned int
F_88 ( struct V_16 * V_17 , void * * V_93 ,
unsigned long V_94 , unsigned int V_95 )
{
struct V_29 V_30 ;
void * * V_8 ;
unsigned int V_38 = 0 ;
if ( F_89 ( ! V_95 ) )
return 0 ;
F_90 (slot, root, &iter, first_index) {
V_93 [ V_38 ] = F_6 ( * V_8 ) ;
if ( ! V_93 [ V_38 ] )
continue;
if ( F_8 ( V_93 [ V_38 ] ) ) {
V_8 = F_91 ( & V_30 ) ;
continue;
}
if ( ++ V_38 == V_95 )
break;
}
return V_38 ;
}
unsigned int
F_92 ( struct V_16 * V_17 ,
void * * * V_93 , unsigned long * V_96 ,
unsigned long V_94 , unsigned int V_95 )
{
struct V_29 V_30 ;
void * * V_8 ;
unsigned int V_38 = 0 ;
if ( F_89 ( ! V_95 ) )
return 0 ;
F_90 (slot, root, &iter, first_index) {
V_93 [ V_38 ] = V_8 ;
if ( V_96 )
V_96 [ V_38 ] = V_30 . V_10 ;
if ( ++ V_38 == V_95 )
break;
}
return V_38 ;
}
unsigned int
F_93 ( struct V_16 * V_17 , void * * V_93 ,
unsigned long V_94 , unsigned int V_95 ,
unsigned int V_20 )
{
struct V_29 V_30 ;
void * * V_8 ;
unsigned int V_38 = 0 ;
if ( F_89 ( ! V_95 ) )
return 0 ;
F_94 (slot, root, &iter, first_index, tag) {
V_93 [ V_38 ] = F_6 ( * V_8 ) ;
if ( ! V_93 [ V_38 ] )
continue;
if ( F_8 ( V_93 [ V_38 ] ) ) {
V_8 = F_91 ( & V_30 ) ;
continue;
}
if ( ++ V_38 == V_95 )
break;
}
return V_38 ;
}
unsigned int
F_95 ( struct V_16 * V_17 , void * * * V_93 ,
unsigned long V_94 , unsigned int V_95 ,
unsigned int V_20 )
{
struct V_29 V_30 ;
void * * V_8 ;
unsigned int V_38 = 0 ;
if ( F_89 ( ! V_95 ) )
return 0 ;
F_94 (slot, root, &iter, first_index, tag) {
V_93 [ V_38 ] = V_8 ;
if ( ++ V_38 == V_95 )
break;
}
return V_38 ;
}
void F_96 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
T_3 V_68 ,
void * V_69 )
{
F_58 ( V_17 , V_5 , V_68 , V_69 ) ;
}
void * F_97 ( struct V_16 * V_17 ,
unsigned long V_10 , void * V_74 )
{
struct V_1 * V_5 ;
unsigned int V_11 ;
void * * V_8 ;
void * V_14 ;
int V_20 ;
V_14 = F_63 ( V_17 , V_10 , & V_5 , & V_8 ) ;
if ( ! V_14 )
return NULL ;
if ( V_74 && V_14 != V_74 )
return NULL ;
if ( ! V_5 ) {
F_18 ( V_17 ) ;
V_17 -> V_37 = NULL ;
return V_14 ;
}
V_11 = F_4 ( V_5 , V_8 ) ;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ )
F_76 ( V_17 , V_5 , V_20 , V_11 ) ;
F_69 ( V_17 , V_5 , V_8 , NULL , NULL , NULL ) ;
return V_14 ;
}
void * F_98 ( struct V_16 * V_17 , unsigned long V_10 )
{
return F_97 ( V_17 , V_10 , NULL ) ;
}
void F_99 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
void * * V_8 )
{
if ( V_5 ) {
unsigned int V_20 , V_11 = F_4 ( V_5 , V_8 ) ;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ )
F_76 ( V_17 , V_5 , V_20 , V_11 ) ;
} else {
V_17 -> V_18 &= V_19 ;
}
}
int F_100 ( struct V_16 * V_17 , unsigned int V_20 )
{
return F_19 ( V_17 , V_20 ) ;
}
static void
F_101 ( void * V_97 )
{
struct V_1 * V_5 = V_97 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_40 ( & V_5 -> V_50 ) ;
}
static T_4 unsigned long F_102 ( unsigned int V_98 )
{
unsigned int V_99 = V_98 * V_57 ;
int V_12 = V_100 - V_99 ;
if ( V_12 < 0 )
return ~ 0UL ;
if ( V_12 >= V_28 )
return 0UL ;
return ~ 0UL >> V_12 ;
}
static T_4 void F_103 ( void )
{
unsigned long V_101 [ V_63 + 1 ] ;
unsigned int V_31 , V_102 ;
for ( V_31 = 0 ; V_31 < F_104 ( V_101 ) ; V_31 ++ )
V_101 [ V_31 ] = F_102 ( V_31 ) ;
for ( V_31 = 0 ; V_31 < F_104 ( V_64 ) ; V_31 ++ ) {
for ( V_102 = V_31 ; V_102 > 0 ; V_102 -- )
V_64 [ V_31 ] += V_101 [ V_102 - 1 ] + 1 ;
}
}
static int F_105 ( unsigned int V_103 )
{
struct V_39 * V_40 ;
struct V_1 * V_5 ;
V_40 = & F_106 ( V_44 , V_103 ) ;
while ( V_40 -> V_45 ) {
V_5 = V_40 -> V_46 ;
V_40 -> V_46 = V_5 -> V_47 ;
F_41 ( V_41 , V_5 ) ;
V_40 -> V_45 -- ;
}
return 0 ;
}
void T_4 F_107 ( void )
{
int V_38 ;
V_41 = F_108 ( L_6 ,
sizeof( struct V_1 ) , 0 ,
V_104 | V_105 ,
F_101 ) ;
F_103 () ;
V_38 = F_109 ( V_106 , L_7 ,
NULL , F_105 ) ;
F_74 ( V_38 < 0 ) ;
}
