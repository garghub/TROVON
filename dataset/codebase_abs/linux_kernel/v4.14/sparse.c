int F_1 ( const struct V_1 * V_1 )
{
return V_2 [ F_2 ( V_1 ) ] ;
}
static void F_3 ( unsigned long V_3 , int V_4 )
{
V_2 [ V_3 ] = V_4 ;
}
static inline void F_3 ( unsigned long V_3 , int V_4 )
{
}
int T_1 F_4 ( unsigned long V_3 , int V_4 )
{
unsigned long V_5 = F_5 ( V_3 ) ;
struct V_6 * V_7 ;
if ( V_6 [ V_5 ] )
return - V_8 ;
V_7 = F_6 ( V_4 ) ;
if ( ! V_7 )
return - V_9 ;
V_6 [ V_5 ] = V_7 ;
return 0 ;
}
static inline int F_4 ( unsigned long V_3 , int V_4 )
{
return 0 ;
}
int F_7 ( struct V_6 * V_10 )
{
unsigned long V_11 ;
struct V_6 * V_5 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
V_5 = F_8 ( V_11 * V_13 ) ;
if ( ! V_5 )
continue;
if ( ( V_10 >= V_5 ) && ( V_10 < ( V_5 + V_13 ) ) )
break;
}
F_9 ( V_11 == V_12 ) ;
return ( V_11 * V_13 ) + ( V_10 - V_5 ) ;
}
int F_7 ( struct V_6 * V_10 )
{
return ( int ) ( V_10 - V_6 [ 0 ] ) ;
}
static inline unsigned long F_10 ( int V_4 )
{
return ( V_4 << V_14 ) ;
}
static inline int F_11 ( struct V_6 * V_7 )
{
return ( V_7 -> V_15 >> V_14 ) ;
}
void T_1 F_12 ( unsigned long * V_16 ,
unsigned long * V_17 )
{
unsigned long V_18 = 1UL << ( V_19 - V_20 ) ;
if ( * V_16 > V_18 ) {
F_13 ( V_21 , L_1 ,
L_2 ,
* V_16 , * V_17 , V_18 ) ;
F_14 ( 1 ) ;
* V_16 = V_18 ;
* V_17 = V_18 ;
} else if ( * V_17 > V_18 ) {
F_13 ( V_21 , L_1 ,
L_3 ,
* V_16 , * V_17 , V_18 ) ;
F_14 ( 1 ) ;
* V_17 = V_18 ;
}
}
static void F_15 ( struct V_6 * V_10 )
{
int V_3 = F_7 ( V_10 ) ;
if ( V_3 > V_22 )
V_22 = V_3 ;
V_10 -> V_15 |= V_23 ;
}
static inline int F_16 ( int V_3 )
{
do {
V_3 ++ ;
if ( F_17 ( V_3 ) )
return V_3 ;
} while ( ( V_3 < V_24 ) &&
( V_3 <= V_22 ) );
return - 1 ;
}
void T_2 F_18 ( int V_4 , unsigned long V_25 , unsigned long V_26 )
{
unsigned long V_27 ;
V_25 &= V_28 ;
F_12 ( & V_25 , & V_26 ) ;
for ( V_27 = V_25 ; V_27 < V_26 ; V_27 += V_29 ) {
unsigned long V_7 = F_19 ( V_27 ) ;
struct V_6 * V_10 ;
F_4 ( V_7 , V_4 ) ;
F_3 ( V_7 , V_4 ) ;
V_10 = F_8 ( V_7 ) ;
if ( ! V_10 -> V_15 ) {
V_10 -> V_15 = F_10 ( V_4 ) |
V_30 ;
F_15 ( V_10 ) ;
}
}
}
unsigned long T_2 F_20 ( int V_4 , unsigned long V_16 ,
unsigned long V_17 )
{
unsigned long V_27 ;
unsigned long V_31 = 0 ;
F_12 ( & V_16 , & V_17 ) ;
for ( V_27 = V_16 ; V_27 < V_17 ; V_27 += V_29 ) {
if ( V_4 != F_21 ( V_27 ) )
continue;
if ( F_22 ( V_27 ) )
V_31 += V_29 ;
}
return V_31 * sizeof( struct V_1 ) ;
}
static unsigned long F_23 ( struct V_1 * V_32 , unsigned long V_33 )
{
return ( unsigned long ) ( V_32 - ( F_24 ( V_33 ) ) ) ;
}
struct V_1 * F_25 ( unsigned long V_34 , unsigned long V_33 )
{
V_34 &= V_35 ;
return ( (struct V_1 * ) V_34 ) + F_24 ( V_33 ) ;
}
static int T_1 F_26 ( struct V_6 * V_10 ,
unsigned long V_33 , struct V_1 * V_32 ,
unsigned long * V_36 )
{
if ( ! F_27 ( V_10 ) )
return - V_37 ;
V_10 -> V_15 &= ~ V_35 ;
V_10 -> V_15 |= F_23 ( V_32 , V_33 ) |
V_38 ;
V_10 -> V_39 = V_36 ;
return 1 ;
}
unsigned long F_28 ( void )
{
return F_29 ( V_40 ) * sizeof( unsigned long ) ;
}
static unsigned long * F_30 ( void )
{
return F_31 ( F_28 () , V_41 ) ;
}
static unsigned long * T_2
F_32 ( struct V_42 * V_43 ,
unsigned long V_44 )
{
unsigned long V_45 , V_46 ;
unsigned long * V_47 ;
int V_4 ;
V_45 = F_33 ( V_43 ) & ( V_28 << V_20 ) ;
V_46 = V_45 + ( 1UL << V_48 ) ;
V_4 = F_21 ( V_45 >> V_20 ) ;
V_49:
V_47 = F_34 ( V_44 ,
V_50 , V_45 , V_46 ,
V_4 ) ;
if ( ! V_47 && V_46 ) {
V_46 = 0 ;
goto V_49;
}
return V_47 ;
}
static void T_2 F_35 ( int V_4 , unsigned long * V_51 )
{
unsigned long V_52 , V_53 ;
static unsigned long V_54 = V_24 ;
static unsigned long V_55 = V_24 ;
struct V_42 * V_43 = F_36 ( V_4 ) ;
int V_56 ;
V_52 = F_19 ( F_33 ( V_51 ) >> V_20 ) ;
V_53 = F_19 ( F_33 ( V_43 ) >> V_20 ) ;
if ( V_52 == V_53 )
return;
if ( V_54 == V_52 && V_55 == V_53 )
return;
V_54 = V_52 ;
V_55 = V_53 ;
V_56 = F_11 ( F_8 ( V_52 ) ) ;
if ( V_56 != V_4 ) {
F_37 ( L_4 ,
V_4 , V_52 ) ;
return;
}
F_37 ( L_5 ,
V_52 , V_53 , V_4 ) ;
}
static unsigned long * T_2
F_32 ( struct V_42 * V_43 ,
unsigned long V_44 )
{
return F_38 ( V_44 , V_43 -> V_57 ) ;
}
static void T_2 F_35 ( int V_4 , unsigned long * V_51 )
{
}
static void T_2 F_39 ( void * V_58 ,
unsigned long V_59 ,
unsigned long V_60 ,
unsigned long V_61 , int V_62 )
{
void * V_51 ;
unsigned long V_33 ;
unsigned long * * V_63 = ( unsigned long * * ) V_58 ;
int V_44 = F_28 () ;
V_51 = F_32 ( F_36 ( V_62 ) ,
V_44 * V_61 ) ;
if ( ! V_51 ) {
F_40 ( L_6 , V_64 ) ;
return;
}
for ( V_33 = V_59 ; V_33 < V_60 ; V_33 ++ ) {
if ( ! F_17 ( V_33 ) )
continue;
V_63 [ V_33 ] = V_51 ;
V_51 += V_44 ;
F_35 ( V_62 , V_63 [ V_33 ] ) ;
}
}
struct V_1 T_2 * F_41 ( unsigned long V_33 , int V_4 )
{
struct V_1 * V_65 ;
unsigned long V_44 ;
V_65 = F_42 ( V_4 , sizeof( struct V_1 ) * V_29 ) ;
if ( V_65 )
return V_65 ;
V_44 = F_43 ( sizeof( struct V_1 ) * V_29 ) ;
V_65 = F_44 ( V_44 ,
V_66 , F_33 ( V_67 ) ,
V_68 , V_4 ) ;
return V_65 ;
}
void T_2 F_45 ( struct V_1 * * V_69 ,
unsigned long V_59 ,
unsigned long V_60 ,
unsigned long V_70 , int V_62 )
{
void * V_65 ;
unsigned long V_33 ;
unsigned long V_44 = sizeof( struct V_1 ) * V_29 ;
V_65 = F_42 ( V_62 , V_44 * V_70 ) ;
if ( V_65 ) {
for ( V_33 = V_59 ; V_33 < V_60 ; V_33 ++ ) {
if ( ! F_17 ( V_33 ) )
continue;
V_69 [ V_33 ] = V_65 ;
V_65 += V_44 ;
}
return;
}
V_44 = F_43 ( V_44 ) ;
V_65 = F_44 ( V_44 * V_70 ,
V_66 , F_33 ( V_67 ) ,
V_68 , V_62 ) ;
if ( V_65 ) {
for ( V_33 = V_59 ; V_33 < V_60 ; V_33 ++ ) {
if ( ! F_17 ( V_33 ) )
continue;
V_69 [ V_33 ] = V_65 ;
V_65 += V_44 ;
}
return;
}
for ( V_33 = V_59 ; V_33 < V_60 ; V_33 ++ ) {
struct V_6 * V_10 ;
if ( ! F_17 ( V_33 ) )
continue;
V_69 [ V_33 ] = F_41 ( V_33 , V_62 ) ;
if ( V_69 [ V_33 ] )
continue;
V_10 = F_8 ( V_33 ) ;
F_46 ( L_7 ,
V_64 ) ;
V_10 -> V_15 = 0 ;
}
}
static void T_2 F_47 ( void * V_58 ,
unsigned long V_59 ,
unsigned long V_60 ,
unsigned long V_70 , int V_62 )
{
struct V_1 * * V_69 = (struct V_1 * * ) V_58 ;
F_45 ( V_69 , V_59 , V_60 ,
V_70 , V_62 ) ;
}
static struct V_1 T_2 * F_48 ( unsigned long V_33 )
{
struct V_1 * V_65 ;
struct V_6 * V_10 = F_8 ( V_33 ) ;
int V_4 = F_11 ( V_10 ) ;
V_65 = F_41 ( V_33 , V_4 ) ;
if ( V_65 )
return V_65 ;
F_46 ( L_7 ,
V_64 ) ;
V_10 -> V_15 = 0 ;
return NULL ;
}
void __weak T_1 F_49 ( void )
{
}
static void T_2 F_50 ( void (* F_51)
( void * , unsigned long , unsigned long ,
unsigned long , int ) , void * V_58 )
{
unsigned long V_33 ;
unsigned long V_70 ;
int V_71 = 0 ;
unsigned long V_59 = 0 ;
F_52 ( 0 , pnum) {
struct V_6 * V_10 ;
V_10 = F_8 ( V_33 ) ;
V_71 = F_11 ( V_10 ) ;
V_59 = V_33 ;
break;
}
V_70 = 1 ;
F_52 (pnum_begin + 1 , pnum) {
struct V_6 * V_10 ;
int V_62 ;
V_10 = F_8 ( V_33 ) ;
V_62 = F_11 ( V_10 ) ;
if ( V_62 == V_71 ) {
V_70 ++ ;
continue;
}
F_51 ( V_58 , V_59 , V_33 ,
V_70 , V_71 ) ;
V_71 = V_62 ;
V_59 = V_33 ;
V_70 = 1 ;
}
F_51 ( V_58 , V_59 , V_24 ,
V_70 , V_71 ) ;
}
void T_2 F_53 ( void )
{
unsigned long V_33 ;
struct V_1 * V_65 ;
unsigned long * V_51 ;
unsigned long * * V_63 ;
int V_44 ;
#ifdef F_54
int V_72 ;
struct V_1 * * V_69 ;
#endif
F_55 ( ! F_56 ( sizeof( struct V_6 ) ) ) ;
F_57 () ;
V_44 = sizeof( unsigned long * ) * V_24 ;
V_63 = F_58 ( V_44 , 0 ) ;
if ( ! V_63 )
F_59 ( L_8 ) ;
F_50 ( F_39 ,
( void * ) V_63 ) ;
#ifdef F_54
V_72 = sizeof( struct V_1 * ) * V_24 ;
V_69 = F_58 ( V_72 , 0 ) ;
if ( ! V_69 )
F_59 ( L_9 ) ;
F_50 ( F_47 ,
( void * ) V_69 ) ;
#endif
F_52 ( 0 , pnum) {
V_51 = V_63 [ V_33 ] ;
if ( ! V_51 )
continue;
#ifdef F_54
V_65 = V_69 [ V_33 ] ;
#else
V_65 = F_48 ( V_33 ) ;
#endif
if ( ! V_65 )
continue;
F_26 ( F_8 ( V_33 ) , V_33 , V_65 ,
V_51 ) ;
}
F_49 () ;
#ifdef F_54
F_60 ( F_33 ( V_69 ) , V_72 ) ;
#endif
F_60 ( F_33 ( V_63 ) , V_44 ) ;
}
void F_61 ( unsigned long V_16 , unsigned long V_17 )
{
unsigned long V_27 ;
for ( V_27 = V_16 ; V_27 < V_17 ; V_27 += V_29 ) {
unsigned long V_3 = F_19 ( V_27 ) ;
struct V_6 * V_10 ;
if ( F_62 ( ! F_63 ( V_3 ) ) )
continue;
V_10 = F_8 ( V_3 ) ;
V_10 -> V_15 |= V_30 ;
}
}
void F_64 ( unsigned long V_16 , unsigned long V_17 )
{
unsigned long V_27 ;
for ( V_27 = V_16 ; V_27 < V_17 ; V_27 += V_29 ) {
unsigned long V_3 = F_19 ( V_16 ) ;
struct V_6 * V_10 ;
if ( F_62 ( ! F_63 ( V_3 ) ) )
continue;
V_10 = F_8 ( V_3 ) ;
V_10 -> V_15 &= ~ V_30 ;
}
}
static inline struct V_1 * F_65 ( unsigned long V_33 , int V_4 )
{
return F_41 ( V_33 , V_4 ) ;
}
static void F_66 ( struct V_1 * V_73 )
{
unsigned long V_25 = ( unsigned long ) V_73 ;
unsigned long V_26 = ( unsigned long ) ( V_73 + V_29 ) ;
F_67 ( V_25 , V_26 ) ;
}
static void F_68 ( struct V_1 * V_73 )
{
unsigned long V_25 = ( unsigned long ) V_73 ;
unsigned long V_26 = ( unsigned long ) ( V_73 + V_29 ) ;
F_67 ( V_25 , V_26 ) ;
}
static struct V_1 * F_69 ( void )
{
struct V_1 * V_1 , * V_74 ;
unsigned long V_75 = sizeof( struct V_1 ) * V_29 ;
V_1 = F_70 ( V_41 | V_76 , F_71 ( V_75 ) ) ;
if ( V_1 )
goto V_77;
V_74 = F_72 ( V_75 ) ;
if ( V_74 )
goto V_78;
return NULL ;
V_77:
V_74 = (struct V_1 * ) F_73 ( F_74 ( V_1 ) ) ;
V_78:
return V_74 ;
}
static inline struct V_1 * F_65 ( unsigned long V_33 , int V_4 )
{
return F_69 () ;
}
static void F_66 ( struct V_1 * V_73 )
{
if ( F_75 ( V_73 ) )
F_76 ( V_73 ) ;
else
F_77 ( ( unsigned long ) V_73 ,
F_71 ( sizeof( struct V_1 ) * V_29 ) ) ;
}
static void F_68 ( struct V_1 * V_73 )
{
unsigned long V_79 , V_80 , V_81 ;
unsigned long V_82 , V_31 ;
struct V_1 * V_1 = F_78 ( V_73 ) ;
V_31 = F_43 ( V_29 * sizeof( struct V_1 ) )
>> V_20 ;
for ( V_81 = 0 ; V_81 < V_31 ; V_81 ++ , V_1 ++ ) {
V_82 = ( unsigned long ) V_1 -> V_83 ;
F_79 ( V_82 == V_84 ) ;
V_79 = F_19 ( F_74 ( V_1 ) ) ;
V_80 = F_80 ( V_1 ) ;
if ( V_79 != V_80 )
F_81 ( V_1 ) ;
}
}
int T_1 F_82 ( struct V_42 * V_43 , unsigned long V_16 )
{
unsigned long V_3 = F_19 ( V_16 ) ;
struct V_6 * V_10 ;
struct V_1 * V_73 ;
unsigned long * V_51 ;
unsigned long V_85 ;
int V_74 ;
V_74 = F_4 ( V_3 , V_43 -> V_57 ) ;
if ( V_74 < 0 && V_74 != - V_8 )
return V_74 ;
V_73 = F_65 ( V_3 , V_43 -> V_57 ) ;
if ( ! V_73 )
return - V_9 ;
V_51 = F_30 () ;
if ( ! V_51 ) {
F_66 ( V_73 ) ;
return - V_9 ;
}
F_83 ( V_43 , & V_85 ) ;
V_10 = F_84 ( V_16 ) ;
if ( V_10 -> V_15 & V_23 ) {
V_74 = - V_8 ;
goto V_86;
}
memset ( V_73 , 0 , sizeof( struct V_1 ) * V_29 ) ;
F_15 ( V_10 ) ;
V_74 = F_26 ( V_10 , V_3 , V_73 , V_51 ) ;
V_86:
F_85 ( V_43 , & V_85 ) ;
if ( V_74 <= 0 ) {
F_86 ( V_51 ) ;
F_66 ( V_73 ) ;
}
return V_74 ;
}
static void F_87 ( struct V_1 * V_73 , int V_31 )
{
int V_81 ;
if ( ! V_73 )
return;
for ( V_81 = 0 ; V_81 < V_31 ; V_81 ++ ) {
if ( F_88 ( & V_73 [ V_81 ] ) ) {
F_89 ( 1 , & V_87 ) ;
F_90 ( & V_73 [ V_81 ] ) ;
}
}
}
static inline void F_87 ( struct V_1 * V_73 , int V_31 )
{
}
static void F_91 ( struct V_1 * V_73 , unsigned long * V_51 )
{
struct V_1 * V_88 ;
if ( ! V_51 )
return;
V_88 = F_78 ( V_51 ) ;
if ( F_92 ( V_88 ) || F_93 ( V_88 ) ) {
F_86 ( V_51 ) ;
if ( V_73 )
F_66 ( V_73 ) ;
return;
}
if ( V_73 )
F_68 ( V_73 ) ;
}
void F_94 ( struct V_89 * V_89 , struct V_6 * V_10 ,
unsigned long V_90 )
{
struct V_1 * V_73 = NULL ;
unsigned long * V_51 = NULL , V_85 ;
struct V_42 * V_43 = V_89 -> V_91 ;
F_83 ( V_43 , & V_85 ) ;
if ( V_10 -> V_15 ) {
V_51 = V_10 -> V_39 ;
V_73 = F_25 ( V_10 -> V_15 ,
F_7 ( V_10 ) ) ;
V_10 -> V_15 = 0 ;
V_10 -> V_39 = NULL ;
}
F_85 ( V_43 , & V_85 ) ;
F_87 ( V_73 + V_90 ,
V_29 - V_90 ) ;
F_91 ( V_73 , V_51 ) ;
}
