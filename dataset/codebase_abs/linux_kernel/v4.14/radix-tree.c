static inline struct V_1 * F_1 ( void * V_2 )
{
return ( void * ) ( ( unsigned long ) V_2 & ~ V_3 ) ;
}
static inline void * F_2 ( void * V_2 )
{
return ( void * ) ( ( unsigned long ) V_2 | V_3 ) ;
}
static inline
bool F_3 ( const struct V_1 * V_4 , void * V_5 )
{
void T_1 * * V_2 = V_5 ;
return ( V_4 -> V_6 <= V_2 ) &&
( V_2 < V_4 -> V_6 + V_7 ) ;
}
static inline
bool F_3 ( const struct V_1 * V_4 , void * V_5 )
{
return false ;
}
static inline unsigned long
F_4 ( const struct V_1 * V_4 , void T_1 * * V_8 )
{
return V_8 - V_4 -> V_6 ;
}
static unsigned int F_5 ( const struct V_1 * V_4 ,
struct V_1 * * V_9 , unsigned long V_10 )
{
unsigned int V_11 = ( V_10 >> V_4 -> V_12 ) & V_13 ;
void T_1 * * V_14 = F_6 ( V_4 -> V_6 [ V_11 ] ) ;
#ifdef F_7
if ( F_8 ( V_14 ) ) {
if ( F_3 ( V_4 , V_14 ) ) {
void T_1 * * V_15 ;
V_15 = ( void T_1 * * ) F_1 ( V_14 ) ;
V_11 = F_4 ( V_4 , V_15 ) ;
V_14 = F_6 ( * V_15 ) ;
}
}
#endif
* V_9 = ( void * ) V_14 ;
return V_11 ;
}
static inline T_2 F_9 ( const struct V_16 * V_17 )
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
static inline int F_14 ( const struct V_1 * V_5 , unsigned int V_20 ,
int V_11 )
{
return F_15 ( V_11 , V_5 -> V_21 [ V_20 ] ) ;
}
static inline void F_16 ( struct V_16 * V_17 , unsigned V_20 )
{
V_17 -> V_18 |= ( V_22 T_2 ) ( 1 << ( V_20 + V_23 ) ) ;
}
static inline void F_17 ( struct V_16 * V_17 , unsigned V_20 )
{
V_17 -> V_18 &= ( V_22 T_2 ) ~ ( 1 << ( V_20 + V_23 ) ) ;
}
static inline void F_18 ( struct V_16 * V_17 )
{
V_17 -> V_18 &= ( 1 << V_23 ) - 1 ;
}
static inline int F_19 ( const struct V_16 * V_17 , unsigned V_20 )
{
return ( V_22 int ) V_17 -> V_18 & ( 1 << ( V_20 + V_23 ) ) ;
}
static inline unsigned F_20 ( const struct V_16 * V_17 )
{
return ( V_22 unsigned ) V_17 -> V_18 >> V_23 ;
}
static inline bool F_21 ( const struct V_16 * V_17 )
{
return ! ! ( V_17 -> V_18 & V_24 ) ;
}
static inline int F_22 ( const struct V_1 * V_5 ,
unsigned int V_20 )
{
unsigned V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_5 -> V_21 [ V_20 ] [ V_25 ] )
return 1 ;
}
return 0 ;
}
static inline void F_23 ( struct V_1 * V_5 , unsigned int V_20 )
{
F_24 ( V_5 -> V_21 [ V_20 ] , V_7 ) ;
}
static T_3 unsigned long
F_25 ( struct V_1 * V_5 , unsigned int V_20 ,
unsigned long V_11 )
{
const unsigned long * V_27 = V_5 -> V_21 [ V_20 ] ;
if ( V_11 < V_7 ) {
unsigned long V_28 ;
V_27 += V_11 / V_29 ;
V_28 = * V_27 >> ( V_11 % V_29 ) ;
if ( V_28 )
return F_26 ( V_28 ) + V_11 ;
V_11 = ( V_11 + V_29 ) & ~ ( V_29 - 1 ) ;
while ( V_11 < V_7 ) {
V_28 = * ++ V_27 ;
if ( V_28 )
return F_26 ( V_28 ) + V_11 ;
V_11 += V_29 ;
}
}
return V_7 ;
}
static unsigned int F_27 ( const struct V_30 * V_31 )
{
return ( V_31 -> V_10 >> F_28 ( V_31 ) ) & V_13 ;
}
static inline unsigned long F_29 ( unsigned int V_12 )
{
return ( V_7 << V_12 ) - 1 ;
}
static inline unsigned long F_30 ( const struct V_1 * V_5 )
{
return F_29 ( V_5 -> V_12 ) ;
}
static unsigned long F_31 ( unsigned long V_10 ,
const struct V_1 * V_5 ,
unsigned long V_11 )
{
return ( V_10 & ~ F_30 ( V_5 ) ) + ( V_11 << V_5 -> V_12 ) ;
}
static void F_32 ( struct V_1 * V_5 , unsigned long V_10 )
{
unsigned long V_32 ;
F_33 ( L_1 ,
V_5 , V_5 -> V_11 , V_10 , V_10 | F_30 ( V_5 ) ,
V_5 -> V_4 ,
V_5 -> V_21 [ 0 ] [ 0 ] , V_5 -> V_21 [ 1 ] [ 0 ] , V_5 -> V_21 [ 2 ] [ 0 ] ,
V_5 -> V_12 , V_5 -> V_33 , V_5 -> V_34 ) ;
for ( V_32 = 0 ; V_32 < V_7 ; V_32 ++ ) {
unsigned long V_35 = V_10 | ( V_32 << V_5 -> V_12 ) ;
unsigned long V_36 = V_35 | ( ( 1UL << V_5 -> V_12 ) - 1 ) ;
void * V_14 = V_5 -> V_6 [ V_32 ] ;
if ( ! V_14 )
continue;
if ( V_14 == V_37 ) {
F_33 ( L_2 ,
V_32 , V_35 , V_36 , V_5 ) ;
} else if ( ! F_8 ( V_14 ) ) {
F_33 ( L_3 ,
V_14 , V_32 , V_35 , V_36 , V_5 ) ;
} else if ( F_3 ( V_5 , V_14 ) ) {
F_33 ( L_4 ,
V_14 , V_32 , V_35 , V_36 , V_5 ,
* ( void * * ) F_1 ( V_14 ) ) ;
} else {
F_32 ( F_1 ( V_14 ) , V_35 ) ;
}
}
}
static void F_34 ( struct V_16 * V_17 )
{
F_33 ( L_5 ,
V_17 , V_17 -> V_38 ,
V_17 -> V_18 >> V_23 ) ;
if ( ! F_8 ( V_17 -> V_38 ) )
return;
F_32 ( F_1 ( V_17 -> V_38 ) , 0 ) ;
}
static void F_35 ( void * V_14 , unsigned long V_10 )
{
unsigned long V_32 ;
if ( ! V_14 )
return;
if ( F_8 ( V_14 ) ) {
struct V_1 * V_5 = F_1 ( V_14 ) ;
F_33 ( L_6 ,
V_5 , V_5 -> V_11 , V_10 * V_39 ,
( ( V_10 | F_30 ( V_5 ) ) + 1 ) *
V_39 - 1 ,
V_5 -> V_4 , V_5 -> V_21 [ 0 ] [ 0 ] , V_5 -> V_12 ,
V_5 -> V_33 ) ;
for ( V_32 = 0 ; V_32 < V_7 ; V_32 ++ )
F_35 ( V_5 -> V_6 [ V_32 ] ,
V_10 | ( V_32 << V_5 -> V_12 ) ) ;
} else if ( F_36 ( V_14 ) ) {
F_33 ( L_7 ,
V_14 , ( int ) ( V_10 & V_13 ) ,
V_10 * V_39 ,
V_10 * V_39 + V_29 -
V_40 ,
( unsigned long ) V_14 >>
V_40 ) ;
} else {
struct V_41 * V_42 = V_14 ;
F_33 ( L_8 , V_42 ,
( int ) ( V_10 & V_13 ) ,
V_10 * V_39 ,
( V_10 + 1 ) * V_39 - 1 ) ;
for ( V_32 = 0 ; V_32 < V_43 ; V_32 ++ )
F_37 ( L_9 , V_42 -> V_42 [ V_32 ] ) ;
F_37 ( L_10 ) ;
}
}
static void F_38 ( struct V_44 * V_44 )
{
struct V_16 * V_17 = & V_44 -> V_45 ;
F_33 ( L_11 , V_44 , V_17 -> V_38 ,
V_17 -> V_18 >> V_23 ) ;
F_35 ( V_17 -> V_38 , 0 ) ;
}
static struct V_1 *
F_39 ( T_2 V_18 , struct V_1 * V_4 ,
struct V_16 * V_17 ,
unsigned int V_12 , unsigned int V_11 ,
unsigned int V_33 , unsigned int V_34 )
{
struct V_1 * V_46 = NULL ;
if ( ! F_40 ( V_18 ) && ! F_41 () ) {
struct V_47 * V_48 ;
V_46 = F_42 ( V_49 ,
V_18 | V_50 ) ;
if ( V_46 )
goto V_51;
V_48 = F_43 ( & V_52 ) ;
if ( V_48 -> V_53 ) {
V_46 = V_48 -> V_54 ;
V_48 -> V_54 = V_46 -> V_4 ;
V_48 -> V_53 -- ;
}
F_44 ( V_46 ) ;
goto V_51;
}
V_46 = F_42 ( V_49 , V_18 ) ;
V_51:
F_45 ( F_8 ( V_46 ) ) ;
if ( V_46 ) {
V_46 -> V_12 = V_12 ;
V_46 -> V_11 = V_11 ;
V_46 -> V_33 = V_33 ;
V_46 -> V_34 = V_34 ;
V_46 -> V_4 = V_4 ;
V_46 -> V_17 = V_17 ;
}
return V_46 ;
}
static void F_46 ( struct V_55 * V_56 )
{
struct V_1 * V_5 =
F_47 ( V_56 , struct V_1 , V_55 ) ;
memset ( V_5 -> V_6 , 0 , sizeof( V_5 -> V_6 ) ) ;
memset ( V_5 -> V_21 , 0 , sizeof( V_5 -> V_21 ) ) ;
F_48 ( & V_5 -> V_57 ) ;
F_49 ( V_49 , V_5 ) ;
}
static inline void
F_50 ( struct V_1 * V_5 )
{
F_51 ( & V_5 -> V_55 , F_46 ) ;
}
static T_4 int F_52 ( T_2 V_18 , unsigned V_53 )
{
struct V_47 * V_48 ;
struct V_1 * V_5 ;
int V_46 = - V_58 ;
V_18 &= ~ V_59 ;
F_53 () ;
V_48 = F_43 ( & V_52 ) ;
while ( V_48 -> V_53 < V_53 ) {
F_54 () ;
V_5 = F_42 ( V_49 , V_18 ) ;
if ( V_5 == NULL )
goto V_51;
F_53 () ;
V_48 = F_43 ( & V_52 ) ;
if ( V_48 -> V_53 < V_53 ) {
V_5 -> V_4 = V_48 -> V_54 ;
V_48 -> V_54 = V_5 ;
V_48 -> V_53 ++ ;
} else {
F_49 ( V_49 , V_5 ) ;
}
}
V_46 = 0 ;
V_51:
return V_46 ;
}
int V_47 ( T_2 V_18 )
{
F_55 ( ! F_40 ( V_18 ) ) ;
return F_52 ( V_18 , V_60 ) ;
}
int F_56 ( T_2 V_18 )
{
if ( F_40 ( V_18 ) )
return F_52 ( V_18 , V_60 ) ;
F_53 () ;
return 0 ;
}
int F_57 ( unsigned int V_61 , unsigned int V_62 ,
T_2 V_18 )
{
unsigned V_63 = 1 << ( V_61 % V_64 ) ;
unsigned V_65 = ( V_61 / V_64 ) -
( V_62 / V_64 ) ;
unsigned V_53 = 0 ;
F_55 ( ! F_40 ( V_18 ) ) ;
F_45 ( V_62 >= V_61 ) ;
while ( V_65 -- )
V_53 = V_53 * V_7 + 1 ;
return F_52 ( V_18 , V_63 * V_53 ) ;
}
int F_58 ( T_2 V_18 , int V_66 )
{
unsigned long V_67 ;
int V_68 , V_69 ;
if ( ! F_40 ( V_18 ) ) {
F_53 () ;
return 0 ;
}
V_67 = 1 << V_66 ;
for ( V_69 = 0 ; V_67 > V_7 ;
V_69 ++ )
V_67 >>= V_64 ;
V_68 = V_70 ;
V_68 += V_70 - V_69 ;
V_68 -- ;
V_68 += V_67 * V_71 [ V_69 ] ;
return F_52 ( V_18 , V_68 ) ;
}
static unsigned F_59 ( const struct V_16 * V_17 ,
struct V_1 * * V_9 , unsigned long * V_72 )
{
struct V_1 * V_5 = F_6 ( V_17 -> V_38 ) ;
* V_9 = V_5 ;
if ( F_60 ( F_8 ( V_5 ) ) ) {
V_5 = F_1 ( V_5 ) ;
* V_72 = F_30 ( V_5 ) ;
return V_5 -> V_12 + V_64 ;
}
* V_72 = 0 ;
return 0 ;
}
static int F_61 ( struct V_16 * V_17 , T_2 V_73 ,
unsigned long V_10 , unsigned int V_12 )
{
void * V_14 ;
unsigned int V_74 ;
int V_20 ;
V_74 = V_12 ;
while ( V_10 > F_29 ( V_74 ) )
V_74 += V_64 ;
V_14 = F_6 ( V_17 -> V_38 ) ;
if ( ! V_14 && ( ! F_21 ( V_17 ) || F_19 ( V_17 , V_75 ) ) )
goto V_51;
do {
struct V_1 * V_5 = F_39 ( V_73 , NULL ,
V_17 , V_12 , 0 , 1 , 0 ) ;
if ( ! V_5 )
return - V_58 ;
if ( F_21 ( V_17 ) ) {
F_23 ( V_5 , V_75 ) ;
if ( ! F_19 ( V_17 , V_75 ) ) {
F_12 ( V_5 , V_75 , 0 ) ;
F_16 ( V_17 , V_75 ) ;
}
} else {
for ( V_20 = 0 ; V_20 < V_76 ; V_20 ++ ) {
if ( F_19 ( V_17 , V_20 ) )
F_10 ( V_5 , V_20 , 0 ) ;
}
}
F_45 ( V_12 > V_29 ) ;
if ( F_8 ( V_14 ) ) {
F_1 ( V_14 ) -> V_4 = V_5 ;
} else if ( F_36 ( V_14 ) ) {
V_5 -> V_34 = 1 ;
}
V_5 -> V_6 [ 0 ] = ( void T_1 * ) V_14 ;
V_14 = F_2 ( V_5 ) ;
F_62 ( V_17 -> V_38 , V_14 ) ;
V_12 += V_64 ;
} while ( V_12 <= V_74 );
V_51:
return V_74 + V_64 ;
}
static inline bool F_63 ( struct V_16 * V_17 ,
T_5 V_77 ,
void * V_78 )
{
bool V_79 = false ;
for (; ; ) {
struct V_1 * V_5 = F_6 ( V_17 -> V_38 ) ;
struct V_1 * V_80 ;
if ( ! F_8 ( V_5 ) )
break;
V_5 = F_1 ( V_5 ) ;
if ( V_5 -> V_33 != 1 )
break;
V_80 = F_6 ( V_5 -> V_6 [ 0 ] ) ;
if ( ! V_80 )
break;
if ( ! F_8 ( V_80 ) && V_5 -> V_12 )
break;
if ( F_8 ( V_80 ) )
F_1 ( V_80 ) -> V_4 = NULL ;
V_17 -> V_38 = ( void T_1 * ) V_80 ;
if ( F_21 ( V_17 ) && ! F_14 ( V_5 , V_75 , 0 ) )
F_17 ( V_17 , V_75 ) ;
V_5 -> V_33 = 0 ;
if ( ! F_8 ( V_80 ) ) {
V_5 -> V_6 [ 0 ] = ( void T_1 * ) V_37 ;
if ( V_77 )
V_77 ( V_5 , V_78 ) ;
}
F_55 ( ! F_64 ( & V_5 -> V_57 ) ) ;
F_50 ( V_5 ) ;
V_79 = true ;
}
return V_79 ;
}
static bool F_65 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
T_5 V_77 , void * V_78 )
{
bool V_81 = false ;
do {
struct V_1 * V_4 ;
if ( V_5 -> V_33 ) {
if ( F_2 ( V_5 ) ==
F_6 ( V_17 -> V_38 ) )
V_81 |= F_63 ( V_17 , V_77 ,
V_78 ) ;
return V_81 ;
}
V_4 = V_5 -> V_4 ;
if ( V_4 ) {
V_4 -> V_6 [ V_5 -> V_11 ] = NULL ;
V_4 -> V_33 -- ;
} else {
if ( ! F_21 ( V_17 ) )
F_18 ( V_17 ) ;
V_17 -> V_38 = NULL ;
}
F_55 ( ! F_64 ( & V_5 -> V_57 ) ) ;
F_50 ( V_5 ) ;
V_81 = true ;
V_5 = V_4 ;
} while ( V_5 );
return V_81 ;
}
int F_66 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_66 , struct V_1 * * V_9 ,
void T_1 * * * V_82 )
{
struct V_1 * V_5 = NULL , * V_80 ;
void T_1 * * V_8 = ( void T_1 * * ) & V_17 -> V_38 ;
unsigned long V_72 ;
unsigned int V_12 , V_11 = 0 ;
unsigned long V_83 = V_10 | ( ( 1UL << V_66 ) - 1 ) ;
T_2 V_73 = F_9 ( V_17 ) ;
V_12 = F_59 ( V_17 , & V_80 , & V_72 ) ;
if ( V_66 > 0 && V_83 == ( ( 1UL << V_66 ) - 1 ) )
V_83 ++ ;
if ( V_83 > V_72 ) {
int error = F_61 ( V_17 , V_73 , V_83 , V_12 ) ;
if ( error < 0 )
return error ;
V_12 = error ;
V_80 = F_6 ( V_17 -> V_38 ) ;
}
while ( V_12 > V_66 ) {
V_12 -= V_64 ;
if ( V_80 == NULL ) {
V_80 = F_39 ( V_73 , V_5 , V_17 , V_12 ,
V_11 , 0 , 0 ) ;
if ( ! V_80 )
return - V_58 ;
F_62 ( * V_8 , F_2 ( V_80 ) ) ;
if ( V_5 )
V_5 -> V_33 ++ ;
} else if ( ! F_8 ( V_80 ) )
break;
V_5 = F_1 ( V_80 ) ;
V_11 = F_5 ( V_5 , & V_80 , V_10 ) ;
V_8 = & V_5 -> V_6 [ V_11 ] ;
}
if ( V_9 )
* V_9 = V_5 ;
if ( V_82 )
* V_82 = V_8 ;
return 0 ;
}
static void F_67 ( struct V_1 * V_5 )
{
unsigned V_11 = 0 ;
struct V_1 * V_80 = F_1 ( V_5 ) ;
for (; ; ) {
void * V_14 = F_6 ( V_80 -> V_6 [ V_11 ] ) ;
if ( F_8 ( V_14 ) &&
! F_3 ( V_80 , V_14 ) ) {
V_80 = F_1 ( V_14 ) ;
V_11 = 0 ;
continue;
}
V_11 ++ ;
while ( V_11 == V_7 ) {
struct V_1 * V_84 = V_80 ;
V_11 = V_80 -> V_11 + 1 ;
V_80 = V_80 -> V_4 ;
F_55 ( ! F_64 ( & V_84 -> V_57 ) ) ;
F_50 ( V_84 ) ;
if ( V_84 == F_1 ( V_5 ) )
return;
}
}
}
static inline int F_68 ( struct V_1 * V_5 ,
void T_1 * * V_8 , void * V_85 , unsigned V_66 , bool V_86 )
{
struct V_1 * V_80 ;
unsigned V_32 , V_87 , V_20 , V_11 , V_21 = 0 ;
if ( V_5 ) {
if ( V_66 > V_5 -> V_12 )
V_87 = 1 << ( V_66 - V_5 -> V_12 ) ;
else
V_87 = 1 ;
V_11 = F_4 ( V_5 , V_8 ) ;
} else {
V_87 = 1 ;
V_11 = 0 ;
}
if ( V_87 > 1 ) {
V_11 = V_11 & ~ ( V_87 - 1 ) ;
V_8 = & V_5 -> V_6 [ V_11 ] ;
}
V_80 = F_2 ( V_8 ) ;
for ( V_32 = 0 ; V_32 < V_87 ; V_32 ++ ) {
if ( V_8 [ V_32 ] ) {
if ( V_86 ) {
V_5 -> V_33 -- ;
for ( V_20 = 0 ; V_20 < V_76 ; V_20 ++ )
if ( F_14 ( V_5 , V_20 , V_11 + V_32 ) )
V_21 |= 1 << V_20 ;
} else
return - V_88 ;
}
}
for ( V_32 = 0 ; V_32 < V_87 ; V_32 ++ ) {
struct V_1 * V_84 = F_6 ( V_8 [ V_32 ] ) ;
if ( V_32 ) {
F_62 ( V_8 [ V_32 ] , V_80 ) ;
for ( V_20 = 0 ; V_20 < V_76 ; V_20 ++ )
if ( V_21 & ( 1 << V_20 ) )
F_12 ( V_5 , V_20 , V_11 + V_32 ) ;
} else {
F_62 ( V_8 [ V_32 ] , V_85 ) ;
for ( V_20 = 0 ; V_20 < V_76 ; V_20 ++ )
if ( V_21 & ( 1 << V_20 ) )
F_10 ( V_5 , V_20 , V_11 ) ;
}
if ( F_8 ( V_84 ) &&
! F_3 ( V_5 , V_84 ) &&
( V_84 != V_37 ) )
F_67 ( V_84 ) ;
if ( F_36 ( V_84 ) )
V_5 -> V_34 -- ;
}
if ( V_5 ) {
V_5 -> V_33 += V_87 ;
if ( F_36 ( V_85 ) )
V_5 -> V_34 += V_87 ;
}
return V_87 ;
}
static inline int F_68 ( struct V_1 * V_5 ,
void T_1 * * V_8 , void * V_85 , unsigned V_66 , bool V_86 )
{
if ( * V_8 )
return - V_88 ;
F_62 ( * V_8 , V_85 ) ;
if ( V_5 ) {
V_5 -> V_33 ++ ;
if ( F_36 ( V_85 ) )
V_5 -> V_34 ++ ;
}
return 1 ;
}
int F_69 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_66 , void * V_85 )
{
struct V_1 * V_5 ;
void T_1 * * V_8 ;
int error ;
F_45 ( F_8 ( V_85 ) ) ;
error = F_66 ( V_17 , V_10 , V_66 , & V_5 , & V_8 ) ;
if ( error )
return error ;
error = F_68 ( V_5 , V_8 , V_85 , V_66 , false ) ;
if ( error < 0 )
return error ;
if ( V_5 ) {
unsigned V_11 = F_4 ( V_5 , V_8 ) ;
F_45 ( F_14 ( V_5 , 0 , V_11 ) ) ;
F_45 ( F_14 ( V_5 , 1 , V_11 ) ) ;
F_45 ( F_14 ( V_5 , 2 , V_11 ) ) ;
} else {
F_45 ( F_20 ( V_17 ) ) ;
}
return 0 ;
}
void * F_70 ( const struct V_16 * V_17 ,
unsigned long V_10 , struct V_1 * * V_9 ,
void T_1 * * * V_82 )
{
struct V_1 * V_5 , * V_4 ;
unsigned long V_72 ;
void T_1 * * V_8 ;
V_89:
V_4 = NULL ;
V_8 = ( void T_1 * * ) & V_17 -> V_38 ;
F_59 ( V_17 , & V_5 , & V_72 ) ;
if ( V_10 > V_72 )
return NULL ;
while ( F_8 ( V_5 ) ) {
unsigned V_11 ;
if ( V_5 == V_37 )
goto V_89;
V_4 = F_1 ( V_5 ) ;
V_11 = F_5 ( V_4 , & V_5 , V_10 ) ;
V_8 = V_4 -> V_6 + V_11 ;
}
if ( V_9 )
* V_9 = V_4 ;
if ( V_82 )
* V_82 = V_8 ;
return V_5 ;
}
void T_1 * * F_71 ( const struct V_16 * V_17 ,
unsigned long V_10 )
{
void T_1 * * V_8 ;
if ( ! F_70 ( V_17 , V_10 , NULL , & V_8 ) )
return NULL ;
return V_8 ;
}
void * F_72 ( const struct V_16 * V_17 , unsigned long V_10 )
{
return F_70 ( V_17 , V_10 , NULL , NULL ) ;
}
static inline void F_73 ( struct V_1 * V_5 ,
void T_1 * * V_8 , int V_33 , int V_34 )
{
#ifdef F_7
void * V_2 = F_2 ( V_8 ) ;
unsigned V_11 = F_4 ( V_5 , V_8 ) + 1 ;
while ( V_11 < V_7 ) {
if ( F_6 ( V_5 -> V_6 [ V_11 ] ) != V_2 )
break;
if ( V_33 < 0 ) {
V_5 -> V_6 [ V_11 ] = NULL ;
V_5 -> V_33 -- ;
}
V_5 -> V_34 += V_34 ;
V_11 ++ ;
}
#endif
}
static void F_74 ( void T_1 * * V_8 , void * V_85 ,
struct V_1 * V_5 , int V_33 , int V_34 )
{
if ( F_55 ( F_8 ( V_85 ) ) )
return;
if ( V_5 && ( V_33 || V_34 ) ) {
V_5 -> V_33 += V_33 ;
V_5 -> V_34 += V_34 ;
F_73 ( V_5 , V_8 , V_33 , V_34 ) ;
}
F_62 ( * V_8 , V_85 ) ;
}
static bool F_75 ( const struct V_16 * V_17 ,
const struct V_1 * V_5 ,
unsigned int V_20 , unsigned int V_11 )
{
if ( V_5 )
return F_14 ( V_5 , V_20 , V_11 ) ;
return F_19 ( V_17 , V_20 ) ;
}
static int F_76 ( struct V_16 * V_17 ,
struct V_1 * V_5 , void T_1 * * V_8 ,
void * V_85 , void * V_84 )
{
if ( F_21 ( V_17 ) ) {
unsigned V_11 = F_4 ( V_5 , V_8 ) ;
bool free = F_75 ( V_17 , V_5 , V_75 , V_11 ) ;
if ( ! free )
return 0 ;
if ( ! V_84 )
return 1 ;
}
return ! ! V_85 - ! ! V_84 ;
}
void F_77 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
void T_1 * * V_8 , void * V_85 ,
T_5 V_77 , void * V_78 )
{
void * V_84 = F_6 ( * V_8 ) ;
int V_34 = ! ! F_36 ( V_85 ) -
! ! F_36 ( V_84 ) ;
int V_33 = F_76 ( V_17 , V_5 , V_8 , V_85 , V_84 ) ;
F_55 ( ! V_5 && ( V_8 != ( void T_1 * * ) & V_17 -> V_38 ) &&
( V_33 || V_34 ) ) ;
F_74 ( V_8 , V_85 , V_5 , V_33 , V_34 ) ;
if ( ! V_5 )
return;
if ( V_77 )
V_77 ( V_5 , V_78 ) ;
F_65 ( V_17 , V_5 , V_77 , V_78 ) ;
}
void F_78 ( struct V_16 * V_17 ,
void T_1 * * V_8 , void * V_85 )
{
F_77 ( V_17 , NULL , V_8 , V_85 , NULL , NULL ) ;
}
void F_79 ( struct V_16 * V_17 ,
const struct V_30 * V_31 ,
void T_1 * * V_8 , void * V_85 )
{
F_77 ( V_17 , V_31 -> V_5 , V_8 , V_85 , NULL , NULL ) ;
}
int F_80 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_66 , void * V_85 )
{
struct V_1 * V_5 ;
void T_1 * * V_8 ;
int error ;
F_45 ( F_8 ( V_85 ) ) ;
error = F_66 ( V_17 , V_10 , V_66 , & V_5 , & V_8 ) ;
if ( ! error )
error = F_68 ( V_5 , V_8 , V_85 , V_66 , true ) ;
if ( error > 0 )
error = 0 ;
return error ;
}
int F_81 ( struct V_16 * V_17 , unsigned long V_10 ,
unsigned V_66 )
{
struct V_1 * V_4 , * V_5 , * V_80 ;
void T_1 * * V_8 ;
unsigned int V_11 , V_90 ;
unsigned V_87 , V_20 , V_21 = 0 ;
T_2 V_73 = F_9 ( V_17 ) ;
if ( ! F_70 ( V_17 , V_10 , & V_4 , & V_8 ) )
return - V_91 ;
if ( ! V_4 )
return - V_91 ;
V_11 = F_4 ( V_4 , V_8 ) ;
for ( V_20 = 0 ; V_20 < V_76 ; V_20 ++ )
if ( F_14 ( V_4 , V_20 , V_11 ) )
V_21 |= 1 << V_20 ;
for ( V_90 = V_11 + 1 ; V_90 < V_7 ; V_90 ++ ) {
if ( ! F_3 ( V_4 ,
F_6 ( V_4 -> V_6 [ V_90 ] ) ) )
break;
for ( V_20 = 0 ; V_20 < V_76 ; V_20 ++ )
if ( V_21 & ( 1 << V_20 ) )
F_10 ( V_4 , V_20 , V_90 ) ;
F_62 ( V_4 -> V_6 [ V_90 ] , V_37 ) ;
}
F_62 ( V_4 -> V_6 [ V_11 ] , V_37 ) ;
V_4 -> V_34 -= ( V_90 - V_11 ) ;
if ( V_66 == V_4 -> V_12 )
return 0 ;
if ( V_66 > V_4 -> V_12 ) {
while ( V_11 < V_90 )
V_11 += F_68 ( V_4 , & V_4 -> V_6 [ V_11 ] ,
V_37 , V_66 , true ) ;
return 0 ;
}
V_5 = V_4 ;
for (; ; ) {
if ( V_5 -> V_12 > V_66 ) {
V_80 = F_39 ( V_73 , V_5 , V_17 ,
V_5 -> V_12 - V_64 ,
V_11 , 0 , 0 ) ;
if ( ! V_80 )
goto V_92;
if ( V_5 != V_4 ) {
V_5 -> V_33 ++ ;
F_62 ( V_5 -> V_6 [ V_11 ] ,
F_2 ( V_80 ) ) ;
for ( V_20 = 0 ; V_20 < V_76 ; V_20 ++ )
if ( V_21 & ( 1 << V_20 ) )
F_10 ( V_5 , V_20 , V_11 ) ;
}
V_5 = V_80 ;
V_11 = 0 ;
continue;
}
V_87 = F_68 ( V_5 , & V_5 -> V_6 [ V_11 ] ,
V_37 , V_66 , false ) ;
F_45 ( V_87 > V_7 ) ;
for ( V_20 = 0 ; V_20 < V_76 ; V_20 ++ )
if ( V_21 & ( 1 << V_20 ) )
F_10 ( V_5 , V_20 , V_11 ) ;
V_11 += V_87 ;
while ( V_11 == V_7 ) {
if ( V_5 == V_4 )
break;
V_11 = V_5 -> V_11 ;
V_80 = V_5 ;
V_5 = V_5 -> V_4 ;
F_62 ( V_5 -> V_6 [ V_11 ] ,
F_2 ( V_80 ) ) ;
V_11 ++ ;
}
if ( ( V_5 == V_4 ) && ( V_11 == V_90 ) )
return 0 ;
}
V_92:
F_82 ( 1 ) ;
return - V_58 ;
}
static void F_83 ( struct V_16 * V_17 ,
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
void * F_84 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_1 * V_5 , * V_4 ;
unsigned long V_72 ;
F_59 ( V_17 , & V_5 , & V_72 ) ;
F_45 ( V_10 > V_72 ) ;
while ( F_8 ( V_5 ) ) {
unsigned V_11 ;
V_4 = F_1 ( V_5 ) ;
V_11 = F_5 ( V_4 , & V_5 , V_10 ) ;
F_45 ( ! V_5 ) ;
if ( ! F_14 ( V_4 , V_20 , V_11 ) )
F_10 ( V_4 , V_20 , V_11 ) ;
}
if ( ! F_19 ( V_17 , V_20 ) )
F_16 ( V_17 , V_20 ) ;
return V_5 ;
}
void F_85 ( struct V_16 * V_17 ,
const struct V_30 * V_31 , unsigned int V_20 )
{
F_83 ( V_17 , V_31 -> V_5 , V_20 , F_27 ( V_31 ) ) ;
}
static void F_86 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
unsigned int V_20 , unsigned int V_11 )
{
while ( V_5 ) {
if ( ! F_14 ( V_5 , V_20 , V_11 ) )
return;
F_12 ( V_5 , V_20 , V_11 ) ;
if ( F_22 ( V_5 , V_20 ) )
return;
V_11 = V_5 -> V_11 ;
V_5 = V_5 -> V_4 ;
}
if ( F_19 ( V_17 , V_20 ) )
F_17 ( V_17 , V_20 ) ;
}
void * F_87 ( struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_1 * V_5 , * V_4 ;
unsigned long V_72 ;
int V_93 ( V_11 ) ;
F_59 ( V_17 , & V_5 , & V_72 ) ;
if ( V_10 > V_72 )
return NULL ;
V_4 = NULL ;
while ( F_8 ( V_5 ) ) {
V_4 = F_1 ( V_5 ) ;
V_11 = F_5 ( V_4 , & V_5 , V_10 ) ;
}
if ( V_5 )
F_86 ( V_17 , V_4 , V_20 , V_11 ) ;
return V_5 ;
}
void F_88 ( struct V_16 * V_17 ,
const struct V_30 * V_31 , unsigned int V_20 )
{
F_86 ( V_17 , V_31 -> V_5 , V_20 , F_27 ( V_31 ) ) ;
}
int F_89 ( const struct V_16 * V_17 ,
unsigned long V_10 , unsigned int V_20 )
{
struct V_1 * V_5 , * V_4 ;
unsigned long V_72 ;
if ( ! F_19 ( V_17 , V_20 ) )
return 0 ;
F_59 ( V_17 , & V_5 , & V_72 ) ;
if ( V_10 > V_72 )
return 0 ;
while ( F_8 ( V_5 ) ) {
unsigned V_11 ;
V_4 = F_1 ( V_5 ) ;
V_11 = F_5 ( V_4 , & V_5 , V_10 ) ;
if ( ! F_14 ( V_4 , V_20 , V_11 ) )
return 0 ;
if ( V_5 == V_37 )
break;
}
return 1 ;
}
static inline void F_90 ( struct V_30 * V_31 ,
unsigned int V_12 )
{
#ifdef F_7
V_31 -> V_12 = V_12 ;
#endif
}
static void F_91 ( struct V_30 * V_31 ,
struct V_1 * V_5 , unsigned V_11 ,
unsigned V_20 )
{
unsigned V_94 = V_11 / V_29 ;
unsigned V_95 = V_11 % V_29 ;
if ( ! V_5 ) {
V_31 -> V_21 = 1 ;
return;
}
V_31 -> V_21 = V_5 -> V_21 [ V_20 ] [ V_94 ] >> V_95 ;
if ( V_94 < V_26 - 1 ) {
if ( V_95 )
V_31 -> V_21 |= V_5 -> V_21 [ V_20 ] [ V_94 + 1 ] <<
( V_29 - V_95 ) ;
V_31 -> F_31 = F_92 ( V_31 , V_29 ) ;
}
}
static void T_1 * * F_93 ( struct V_1 * * V_9 ,
void T_1 * * V_8 , struct V_30 * V_31 )
{
void * V_96 = F_2 ( V_8 - 1 ) ;
while ( V_31 -> V_10 < V_31 -> F_31 ) {
* V_9 = F_6 ( * V_8 ) ;
if ( * V_9 && * V_9 != V_96 )
return V_8 ;
V_8 ++ ;
V_31 -> V_10 = F_92 ( V_31 , 1 ) ;
V_31 -> V_21 >>= 1 ;
}
* V_9 = NULL ;
return NULL ;
}
void T_1 * * F_94 ( void T_1 * * V_8 ,
struct V_30 * V_31 , unsigned V_97 )
{
unsigned V_20 = V_97 & V_98 ;
struct V_1 * V_5 = F_6 ( * V_8 ) ;
V_8 = F_93 ( & V_5 , V_8 , V_31 ) ;
while ( F_8 ( V_5 ) ) {
unsigned V_11 ;
unsigned long F_31 ;
if ( V_5 == V_37 )
return V_8 ;
V_5 = F_1 ( V_5 ) ;
V_31 -> V_5 = V_5 ;
V_31 -> V_12 = V_5 -> V_12 ;
if ( V_97 & V_99 ) {
V_11 = F_25 ( V_5 , V_20 , 0 ) ;
if ( V_11 == V_7 )
return NULL ;
V_8 = & V_5 -> V_6 [ V_11 ] ;
V_31 -> V_10 = F_92 ( V_31 , V_11 ) ;
F_91 ( V_31 , V_5 , V_11 , V_20 ) ;
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
V_31 -> V_10 = F_92 ( V_31 , V_11 ) ;
}
if ( ( V_97 & V_100 ) && ( V_11 > 0 ) )
goto V_101;
F_31 = ( V_31 -> V_10 | F_29 ( V_31 -> V_12 ) ) + 1 ;
if ( F_31 < V_31 -> F_31 )
V_31 -> F_31 = F_31 ;
}
return V_8 ;
V_101:
V_31 -> F_31 = 0 ;
return NULL ;
}
static void T_1 * * F_93 ( struct V_1 * * V_9 ,
void T_1 * * V_8 , struct V_30 * V_31 )
{
return V_8 ;
}
void T_1 * * F_95 ( void T_1 * * V_8 ,
struct V_30 * V_31 )
{
struct V_1 * V_5 ;
V_8 ++ ;
V_31 -> V_10 = F_92 ( V_31 , 1 ) ;
F_93 ( & V_5 , V_8 , V_31 ) ;
V_31 -> F_31 = V_31 -> V_10 ;
V_31 -> V_21 = 0 ;
return NULL ;
}
void T_1 * * F_96 ( const struct V_16 * V_17 ,
struct V_30 * V_31 , unsigned V_97 )
{
unsigned V_20 = V_97 & V_98 ;
struct V_1 * V_5 , * V_80 ;
unsigned long V_10 , V_11 , V_72 ;
if ( ( V_97 & V_99 ) && ! F_19 ( V_17 , V_20 ) )
return NULL ;
V_10 = V_31 -> F_31 ;
if ( ! V_10 && V_31 -> V_10 )
return NULL ;
V_89:
F_59 ( V_17 , & V_80 , & V_72 ) ;
if ( V_10 > V_72 )
return NULL ;
if ( ! V_80 )
return NULL ;
if ( ! F_8 ( V_80 ) ) {
V_31 -> V_10 = V_10 ;
V_31 -> F_31 = V_72 + 1 ;
V_31 -> V_21 = 1 ;
V_31 -> V_5 = NULL ;
F_90 ( V_31 , 0 ) ;
return ( void T_1 * * ) & V_17 -> V_38 ;
}
do {
V_5 = F_1 ( V_80 ) ;
V_11 = F_5 ( V_5 , & V_80 , V_10 ) ;
if ( ( V_97 & V_99 ) ?
! F_14 ( V_5 , V_20 , V_11 ) : ! V_80 ) {
if ( V_97 & V_100 )
return NULL ;
if ( V_97 & V_99 )
V_11 = F_25 ( V_5 , V_20 ,
V_11 + 1 ) ;
else
while ( ++ V_11 < V_7 ) {
void * V_8 = F_6 (
V_5 -> V_6 [ V_11 ] ) ;
if ( F_3 ( V_5 , V_8 ) )
continue;
if ( V_8 )
break;
}
V_10 &= ~ F_30 ( V_5 ) ;
V_10 += V_11 << V_5 -> V_12 ;
if ( ! V_10 )
return NULL ;
if ( V_11 == V_7 )
goto V_89;
V_80 = F_6 ( V_5 -> V_6 [ V_11 ] ) ;
}
if ( ! V_80 )
goto V_89;
if ( V_80 == V_37 )
break;
} while ( F_8 ( V_80 ) );
V_31 -> V_10 = ( V_10 & ~ F_30 ( V_5 ) ) | ( V_11 << V_5 -> V_12 ) ;
V_31 -> F_31 = ( V_10 | F_30 ( V_5 ) ) + 1 ;
V_31 -> V_5 = V_5 ;
F_90 ( V_31 , V_5 -> V_12 ) ;
if ( V_97 & V_99 )
F_91 ( V_31 , V_5 , V_11 , V_20 ) ;
return V_5 -> V_6 + V_11 ;
}
unsigned int
F_97 ( const struct V_16 * V_17 , void * * V_102 ,
unsigned long V_103 , unsigned int V_104 )
{
struct V_30 V_31 ;
void T_1 * * V_8 ;
unsigned int V_46 = 0 ;
if ( F_98 ( ! V_104 ) )
return 0 ;
F_99 (slot, root, &iter, first_index) {
V_102 [ V_46 ] = F_6 ( * V_8 ) ;
if ( ! V_102 [ V_46 ] )
continue;
if ( F_8 ( V_102 [ V_46 ] ) ) {
V_8 = F_100 ( & V_31 ) ;
continue;
}
if ( ++ V_46 == V_104 )
break;
}
return V_46 ;
}
unsigned int
F_101 ( const struct V_16 * V_17 ,
void T_1 * * * V_102 , unsigned long * V_105 ,
unsigned long V_103 , unsigned int V_104 )
{
struct V_30 V_31 ;
void T_1 * * V_8 ;
unsigned int V_46 = 0 ;
if ( F_98 ( ! V_104 ) )
return 0 ;
F_99 (slot, root, &iter, first_index) {
V_102 [ V_46 ] = V_8 ;
if ( V_105 )
V_105 [ V_46 ] = V_31 . V_10 ;
if ( ++ V_46 == V_104 )
break;
}
return V_46 ;
}
unsigned int
F_102 ( const struct V_16 * V_17 , void * * V_102 ,
unsigned long V_103 , unsigned int V_104 ,
unsigned int V_20 )
{
struct V_30 V_31 ;
void T_1 * * V_8 ;
unsigned int V_46 = 0 ;
if ( F_98 ( ! V_104 ) )
return 0 ;
F_103 (slot, root, &iter, first_index, tag) {
V_102 [ V_46 ] = F_6 ( * V_8 ) ;
if ( ! V_102 [ V_46 ] )
continue;
if ( F_8 ( V_102 [ V_46 ] ) ) {
V_8 = F_100 ( & V_31 ) ;
continue;
}
if ( ++ V_46 == V_104 )
break;
}
return V_46 ;
}
unsigned int
F_104 ( const struct V_16 * V_17 ,
void T_1 * * * V_102 , unsigned long V_103 ,
unsigned int V_104 , unsigned int V_20 )
{
struct V_30 V_31 ;
void T_1 * * V_8 ;
unsigned int V_46 = 0 ;
if ( F_98 ( ! V_104 ) )
return 0 ;
F_103 (slot, root, &iter, first_index, tag) {
V_102 [ V_46 ] = V_8 ;
if ( ++ V_46 == V_104 )
break;
}
return V_46 ;
}
void F_105 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
T_5 V_77 ,
void * V_78 )
{
F_65 ( V_17 , V_5 , V_77 , V_78 ) ;
}
static bool F_106 ( struct V_16 * V_17 ,
struct V_1 * V_5 , void T_1 * * V_8 )
{
void * V_84 = F_6 ( * V_8 ) ;
int V_34 = F_36 ( V_84 ) ? - 1 : 0 ;
unsigned V_11 = F_4 ( V_5 , V_8 ) ;
int V_20 ;
if ( F_21 ( V_17 ) )
F_83 ( V_17 , V_5 , V_75 , V_11 ) ;
else
for ( V_20 = 0 ; V_20 < V_76 ; V_20 ++ )
F_86 ( V_17 , V_5 , V_20 , V_11 ) ;
F_74 ( V_8 , NULL , V_5 , - 1 , V_34 ) ;
return V_5 && F_65 ( V_17 , V_5 , NULL , NULL ) ;
}
void F_107 ( struct V_16 * V_17 ,
struct V_30 * V_31 , void T_1 * * V_8 )
{
if ( F_106 ( V_17 , V_31 -> V_5 , V_8 ) )
V_31 -> V_10 = V_31 -> F_31 ;
}
void * F_108 ( struct V_16 * V_17 ,
unsigned long V_10 , void * V_85 )
{
struct V_1 * V_5 = NULL ;
void T_1 * * V_8 ;
void * V_14 ;
V_14 = F_70 ( V_17 , V_10 , & V_5 , & V_8 ) ;
if ( ! V_14 && ( ! F_21 ( V_17 ) || F_75 ( V_17 , V_5 , V_75 ,
F_4 ( V_5 , V_8 ) ) ) )
return NULL ;
if ( V_85 && V_14 != V_85 )
return NULL ;
F_106 ( V_17 , V_5 , V_8 ) ;
return V_14 ;
}
void * F_109 ( struct V_16 * V_17 , unsigned long V_10 )
{
return F_108 ( V_17 , V_10 , NULL ) ;
}
void F_110 ( struct V_16 * V_17 ,
struct V_1 * V_5 ,
void T_1 * * V_8 )
{
if ( V_5 ) {
unsigned int V_20 , V_11 = F_4 ( V_5 , V_8 ) ;
for ( V_20 = 0 ; V_20 < V_76 ; V_20 ++ )
F_86 ( V_17 , V_5 , V_20 , V_11 ) ;
} else {
F_18 ( V_17 ) ;
}
}
int F_111 ( const struct V_16 * V_17 , unsigned int V_20 )
{
return F_19 ( V_17 , V_20 ) ;
}
void F_112 ( T_2 V_18 )
{
if ( F_52 ( V_18 , V_106 ) )
F_53 () ;
}
int F_113 ( struct V_44 * V_44 , T_2 V_73 )
{
if ( ! F_52 ( V_73 , V_107 ) )
F_54 () ;
if ( ! F_114 ( V_41 ) ) {
struct V_41 * V_42 = F_115 ( sizeof( * V_42 ) , V_73 ) ;
if ( ! V_42 )
return 0 ;
if ( F_116 ( V_41 , NULL , V_42 ) )
F_117 ( V_42 ) ;
}
return 1 ;
}
void T_1 * * F_118 ( struct V_16 * V_17 ,
struct V_30 * V_31 , T_2 V_73 ,
unsigned long V_83 )
{
struct V_1 * V_5 = NULL , * V_80 ;
void T_1 * * V_8 = ( void T_1 * * ) & V_17 -> V_38 ;
unsigned long V_72 , V_108 = V_31 -> F_31 ;
unsigned int V_12 , V_11 = 0 ;
V_109:
V_12 = F_59 ( V_17 , & V_80 , & V_72 ) ;
if ( ! F_111 ( V_17 , V_75 ) )
V_108 = V_83 ( V_108 , V_72 + 1 ) ;
if ( V_108 > V_83 )
return F_119 ( - V_110 ) ;
if ( V_108 > V_72 ) {
int error = F_61 ( V_17 , V_73 , V_108 , V_12 ) ;
if ( error < 0 )
return F_119 ( error ) ;
V_12 = error ;
V_80 = F_6 ( V_17 -> V_38 ) ;
}
while ( V_12 ) {
V_12 -= V_64 ;
if ( V_80 == NULL ) {
V_80 = F_39 ( V_73 , V_5 , V_17 , V_12 ,
V_11 , 0 , 0 ) ;
if ( ! V_80 )
return F_119 ( - V_58 ) ;
F_23 ( V_80 , V_75 ) ;
F_62 ( * V_8 , F_2 ( V_80 ) ) ;
if ( V_5 )
V_5 -> V_33 ++ ;
} else if ( ! F_8 ( V_80 ) )
break;
V_5 = F_1 ( V_80 ) ;
V_11 = F_5 ( V_5 , & V_80 , V_108 ) ;
if ( ! F_14 ( V_5 , V_75 , V_11 ) ) {
V_11 = F_25 ( V_5 , V_75 ,
V_11 + 1 ) ;
V_108 = F_31 ( V_108 , V_5 , V_11 ) ;
if ( V_108 > V_83 )
return F_119 ( - V_110 ) ;
while ( V_11 == V_7 ) {
V_11 = V_5 -> V_11 + 1 ;
V_5 = V_5 -> V_4 ;
if ( ! V_5 )
goto V_109;
V_12 = V_5 -> V_12 ;
}
V_80 = F_6 ( V_5 -> V_6 [ V_11 ] ) ;
}
V_8 = & V_5 -> V_6 [ V_11 ] ;
}
V_31 -> V_10 = V_108 ;
if ( V_5 )
V_31 -> F_31 = 1 + F_120 ( V_83 , ( V_108 | F_30 ( V_5 ) ) ) ;
else
V_31 -> F_31 = 1 ;
V_31 -> V_5 = V_5 ;
F_90 ( V_31 , V_12 ) ;
F_91 ( V_31 , V_5 , V_11 , V_75 ) ;
return V_8 ;
}
void F_121 ( struct V_111 * V_111 )
{
struct V_1 * V_5 = F_6 ( V_111 -> V_112 . V_38 ) ;
if ( F_8 ( V_5 ) )
F_67 ( V_5 ) ;
V_111 -> V_112 . V_38 = NULL ;
F_16 ( & V_111 -> V_112 , V_75 ) ;
}
static void
F_122 ( void * V_113 )
{
struct V_1 * V_5 = V_113 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_48 ( & V_5 -> V_57 ) ;
}
static T_6 unsigned long F_123 ( unsigned int V_114 )
{
unsigned int V_115 = V_114 * V_64 ;
int V_12 = V_116 - V_115 ;
if ( V_12 < 0 )
return ~ 0UL ;
if ( V_12 >= V_29 )
return 0UL ;
return ~ 0UL >> V_12 ;
}
static T_6 void F_124 ( void )
{
unsigned long V_117 [ V_70 + 1 ] ;
unsigned int V_32 , V_118 ;
for ( V_32 = 0 ; V_32 < F_125 ( V_117 ) ; V_32 ++ )
V_117 [ V_32 ] = F_123 ( V_32 ) ;
for ( V_32 = 0 ; V_32 < F_125 ( V_71 ) ; V_32 ++ ) {
for ( V_118 = V_32 ; V_118 > 0 ; V_118 -- )
V_71 [ V_32 ] += V_117 [ V_118 - 1 ] + 1 ;
}
}
static int F_126 ( unsigned int V_119 )
{
struct V_47 * V_48 ;
struct V_1 * V_5 ;
V_48 = & F_127 ( V_52 , V_119 ) ;
while ( V_48 -> V_53 ) {
V_5 = V_48 -> V_54 ;
V_48 -> V_54 = V_5 -> V_4 ;
F_49 ( V_49 , V_5 ) ;
V_48 -> V_53 -- ;
}
F_117 ( F_127 ( V_41 , V_119 ) ) ;
F_127 ( V_41 , V_119 ) = NULL ;
return 0 ;
}
void T_6 F_128 ( void )
{
int V_46 ;
F_129 ( V_76 + V_120 > 32 ) ;
V_49 = F_130 ( L_12 ,
sizeof( struct V_1 ) , 0 ,
V_121 | V_122 ,
F_122 ) ;
F_124 () ;
V_46 = F_131 ( V_123 , L_13 ,
NULL , F_126 ) ;
F_82 ( V_46 < 0 ) ;
}
