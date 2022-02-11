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
void T_2 F_15 ( int V_4 , unsigned long V_22 , unsigned long V_23 )
{
unsigned long V_24 ;
V_22 &= V_25 ;
F_12 ( & V_22 , & V_23 ) ;
for ( V_24 = V_22 ; V_24 < V_23 ; V_24 += V_26 ) {
unsigned long V_7 = F_16 ( V_24 ) ;
struct V_6 * V_10 ;
F_4 ( V_7 , V_4 ) ;
F_3 ( V_7 , V_4 ) ;
V_10 = F_8 ( V_7 ) ;
if ( ! V_10 -> V_15 )
V_10 -> V_15 = F_10 ( V_4 ) |
V_27 ;
}
}
unsigned long T_2 F_17 ( int V_4 , unsigned long V_16 ,
unsigned long V_17 )
{
unsigned long V_24 ;
unsigned long V_28 = 0 ;
F_12 ( & V_16 , & V_17 ) ;
for ( V_24 = V_16 ; V_24 < V_17 ; V_24 += V_26 ) {
if ( V_4 != F_18 ( V_24 ) )
continue;
if ( F_19 ( V_24 ) )
V_28 += V_26 ;
}
return V_28 * sizeof( struct V_1 ) ;
}
static unsigned long F_20 ( struct V_1 * V_29 , unsigned long V_30 )
{
return ( unsigned long ) ( V_29 - ( F_21 ( V_30 ) ) ) ;
}
struct V_1 * F_22 ( unsigned long V_31 , unsigned long V_30 )
{
V_31 &= V_32 ;
return ( (struct V_1 * ) V_31 ) + F_21 ( V_30 ) ;
}
static int T_1 F_23 ( struct V_6 * V_10 ,
unsigned long V_30 , struct V_1 * V_29 ,
unsigned long * V_33 )
{
if ( ! F_24 ( V_10 ) )
return - V_34 ;
V_10 -> V_15 &= ~ V_32 ;
V_10 -> V_15 |= F_20 ( V_29 , V_30 ) |
V_35 ;
V_10 -> V_36 = V_33 ;
return 1 ;
}
unsigned long F_25 ( void )
{
return F_26 ( V_37 ) * sizeof( unsigned long ) ;
}
static unsigned long * F_27 ( void )
{
return F_28 ( F_25 () , V_38 ) ;
}
static unsigned long * T_2
F_29 ( struct V_39 * V_40 ,
unsigned long V_41 )
{
unsigned long V_42 , V_43 ;
unsigned long * V_44 ;
int V_4 ;
V_42 = F_30 ( V_40 ) & ( V_25 << V_20 ) ;
V_43 = V_42 + ( 1UL << V_45 ) ;
V_4 = F_18 ( V_42 >> V_20 ) ;
V_46:
V_44 = F_31 ( V_41 ,
V_47 , V_42 , V_43 ,
V_4 ) ;
if ( ! V_44 && V_43 ) {
V_43 = 0 ;
goto V_46;
}
return V_44 ;
}
static void T_2 F_32 ( int V_4 , unsigned long * V_48 )
{
unsigned long V_49 , V_50 ;
static unsigned long V_51 = V_52 ;
static unsigned long V_53 = V_52 ;
struct V_39 * V_40 = F_33 ( V_4 ) ;
int V_54 ;
V_49 = F_16 ( F_30 ( V_48 ) >> V_20 ) ;
V_50 = F_16 ( F_30 ( V_40 ) >> V_20 ) ;
if ( V_49 == V_50 )
return;
if ( V_51 == V_49 && V_53 == V_50 )
return;
V_51 = V_49 ;
V_53 = V_50 ;
V_54 = F_11 ( F_8 ( V_49 ) ) ;
if ( V_54 != V_4 ) {
F_34 ( L_4 ,
V_4 , V_49 ) ;
return;
}
F_34 ( L_5 ,
V_49 , V_50 , V_4 ) ;
}
static unsigned long * T_2
F_29 ( struct V_39 * V_40 ,
unsigned long V_41 )
{
return F_35 ( V_41 , V_40 -> V_55 ) ;
}
static void T_2 F_32 ( int V_4 , unsigned long * V_48 )
{
}
static void T_2 F_36 ( void * V_56 ,
unsigned long V_57 ,
unsigned long V_58 ,
unsigned long V_59 , int V_60 )
{
void * V_48 ;
unsigned long V_30 ;
unsigned long * * V_61 = ( unsigned long * * ) V_56 ;
int V_41 = F_25 () ;
V_48 = F_29 ( F_33 ( V_60 ) ,
V_41 * V_59 ) ;
if ( ! V_48 ) {
F_37 ( L_6 , V_62 ) ;
return;
}
for ( V_30 = V_57 ; V_30 < V_58 ; V_30 ++ ) {
if ( ! F_38 ( V_30 ) )
continue;
V_61 [ V_30 ] = V_48 ;
V_48 += V_41 ;
F_32 ( V_60 , V_61 [ V_30 ] ) ;
}
}
struct V_1 T_2 * F_39 ( unsigned long V_30 , int V_4 )
{
struct V_1 * V_63 ;
unsigned long V_41 ;
V_63 = F_40 ( V_4 , sizeof( struct V_1 ) * V_26 ) ;
if ( V_63 )
return V_63 ;
V_41 = F_41 ( sizeof( struct V_1 ) * V_26 ) ;
V_63 = F_42 ( V_41 ,
V_64 , F_30 ( V_65 ) ,
V_66 , V_4 ) ;
return V_63 ;
}
void T_2 F_43 ( struct V_1 * * V_67 ,
unsigned long V_57 ,
unsigned long V_58 ,
unsigned long V_68 , int V_60 )
{
void * V_63 ;
unsigned long V_30 ;
unsigned long V_41 = sizeof( struct V_1 ) * V_26 ;
V_63 = F_40 ( V_60 , V_41 * V_68 ) ;
if ( V_63 ) {
for ( V_30 = V_57 ; V_30 < V_58 ; V_30 ++ ) {
if ( ! F_38 ( V_30 ) )
continue;
V_67 [ V_30 ] = V_63 ;
V_63 += V_41 ;
}
return;
}
V_41 = F_41 ( V_41 ) ;
V_63 = F_42 ( V_41 * V_68 ,
V_64 , F_30 ( V_65 ) ,
V_66 , V_60 ) ;
if ( V_63 ) {
for ( V_30 = V_57 ; V_30 < V_58 ; V_30 ++ ) {
if ( ! F_38 ( V_30 ) )
continue;
V_67 [ V_30 ] = V_63 ;
V_63 += V_41 ;
}
return;
}
for ( V_30 = V_57 ; V_30 < V_58 ; V_30 ++ ) {
struct V_6 * V_10 ;
if ( ! F_38 ( V_30 ) )
continue;
V_67 [ V_30 ] = F_39 ( V_30 , V_60 ) ;
if ( V_67 [ V_30 ] )
continue;
V_10 = F_8 ( V_30 ) ;
F_44 ( L_7 ,
V_62 ) ;
V_10 -> V_15 = 0 ;
}
}
static void T_2 F_45 ( void * V_56 ,
unsigned long V_57 ,
unsigned long V_58 ,
unsigned long V_68 , int V_60 )
{
struct V_1 * * V_67 = (struct V_1 * * ) V_56 ;
F_43 ( V_67 , V_57 , V_58 ,
V_68 , V_60 ) ;
}
static struct V_1 T_2 * F_46 ( unsigned long V_30 )
{
struct V_1 * V_63 ;
struct V_6 * V_10 = F_8 ( V_30 ) ;
int V_4 = F_11 ( V_10 ) ;
V_63 = F_39 ( V_30 , V_4 ) ;
if ( V_63 )
return V_63 ;
F_44 ( L_7 ,
V_62 ) ;
V_10 -> V_15 = 0 ;
return NULL ;
}
void __weak T_1 F_47 ( void )
{
}
static void T_2 F_48 ( void (* F_49)
( void * , unsigned long , unsigned long ,
unsigned long , int ) , void * V_56 )
{
unsigned long V_30 ;
unsigned long V_68 ;
int V_69 = 0 ;
unsigned long V_57 = 0 ;
for ( V_30 = 0 ; V_30 < V_52 ; V_30 ++ ) {
struct V_6 * V_10 ;
if ( ! F_38 ( V_30 ) )
continue;
V_10 = F_8 ( V_30 ) ;
V_69 = F_11 ( V_10 ) ;
V_57 = V_30 ;
break;
}
V_68 = 1 ;
for ( V_30 = V_57 + 1 ; V_30 < V_52 ; V_30 ++ ) {
struct V_6 * V_10 ;
int V_60 ;
if ( ! F_38 ( V_30 ) )
continue;
V_10 = F_8 ( V_30 ) ;
V_60 = F_11 ( V_10 ) ;
if ( V_60 == V_69 ) {
V_68 ++ ;
continue;
}
F_49 ( V_56 , V_57 , V_30 ,
V_68 , V_69 ) ;
V_69 = V_60 ;
V_57 = V_30 ;
V_68 = 1 ;
}
F_49 ( V_56 , V_57 , V_52 ,
V_68 , V_69 ) ;
}
void T_2 F_50 ( void )
{
unsigned long V_30 ;
struct V_1 * V_63 ;
unsigned long * V_48 ;
unsigned long * * V_61 ;
int V_41 ;
#ifdef F_51
int V_70 ;
struct V_1 * * V_67 ;
#endif
F_52 ( ! F_53 ( sizeof( struct V_6 ) ) ) ;
F_54 () ;
V_41 = sizeof( unsigned long * ) * V_52 ;
V_61 = F_55 ( V_41 , 0 ) ;
if ( ! V_61 )
F_56 ( L_8 ) ;
F_48 ( F_36 ,
( void * ) V_61 ) ;
#ifdef F_51
V_70 = sizeof( struct V_1 * ) * V_52 ;
V_67 = F_55 ( V_70 , 0 ) ;
if ( ! V_67 )
F_56 ( L_9 ) ;
F_48 ( F_45 ,
( void * ) V_67 ) ;
#endif
for ( V_30 = 0 ; V_30 < V_52 ; V_30 ++ ) {
if ( ! F_38 ( V_30 ) )
continue;
V_48 = V_61 [ V_30 ] ;
if ( ! V_48 )
continue;
#ifdef F_51
V_63 = V_67 [ V_30 ] ;
#else
V_63 = F_46 ( V_30 ) ;
#endif
if ( ! V_63 )
continue;
F_23 ( F_8 ( V_30 ) , V_30 , V_63 ,
V_48 ) ;
}
F_47 () ;
#ifdef F_51
F_57 ( F_30 ( V_67 ) , V_70 ) ;
#endif
F_57 ( F_30 ( V_61 ) , V_41 ) ;
}
static inline struct V_1 * F_58 ( unsigned long V_30 , int V_4 )
{
return F_39 ( V_30 , V_4 ) ;
}
static void F_59 ( struct V_1 * V_71 )
{
unsigned long V_22 = ( unsigned long ) V_71 ;
unsigned long V_23 = ( unsigned long ) ( V_71 + V_26 ) ;
F_60 ( V_22 , V_23 ) ;
}
static void F_61 ( struct V_1 * V_71 )
{
unsigned long V_22 = ( unsigned long ) V_71 ;
unsigned long V_23 = ( unsigned long ) ( V_71 + V_26 ) ;
F_60 ( V_22 , V_23 ) ;
}
static struct V_1 * F_62 ( void )
{
struct V_1 * V_1 , * V_72 ;
unsigned long V_73 = sizeof( struct V_1 ) * V_26 ;
V_1 = F_63 ( V_38 | V_74 , F_64 ( V_73 ) ) ;
if ( V_1 )
goto V_75;
V_72 = F_65 ( V_73 ) ;
if ( V_72 )
goto V_76;
return NULL ;
V_75:
V_72 = (struct V_1 * ) F_66 ( F_67 ( V_1 ) ) ;
V_76:
return V_72 ;
}
static inline struct V_1 * F_58 ( unsigned long V_30 , int V_4 )
{
return F_62 () ;
}
static void F_59 ( struct V_1 * V_71 )
{
if ( F_68 ( V_71 ) )
F_69 ( V_71 ) ;
else
F_70 ( ( unsigned long ) V_71 ,
F_64 ( sizeof( struct V_1 ) * V_26 ) ) ;
}
static void F_61 ( struct V_1 * V_71 )
{
unsigned long V_77 , V_78 , V_79 ;
unsigned long V_80 , V_28 ;
struct V_1 * V_1 = F_71 ( V_71 ) ;
V_28 = F_41 ( V_26 * sizeof( struct V_1 ) )
>> V_20 ;
for ( V_79 = 0 ; V_79 < V_28 ; V_79 ++ , V_1 ++ ) {
V_80 = ( unsigned long ) V_1 -> V_81 ;
F_72 ( V_80 == V_82 ) ;
V_77 = F_16 ( F_67 ( V_1 ) ) ;
V_78 = F_73 ( V_1 ) ;
if ( V_77 != V_78 )
F_74 ( V_1 ) ;
}
}
int T_1 F_75 ( struct V_83 * V_83 , unsigned long V_16 )
{
unsigned long V_3 = F_16 ( V_16 ) ;
struct V_39 * V_40 = V_83 -> V_84 ;
struct V_6 * V_10 ;
struct V_1 * V_71 ;
unsigned long * V_48 ;
unsigned long V_85 ;
int V_72 ;
V_72 = F_4 ( V_3 , V_40 -> V_55 ) ;
if ( V_72 < 0 && V_72 != - V_8 )
return V_72 ;
V_71 = F_58 ( V_3 , V_40 -> V_55 ) ;
if ( ! V_71 )
return - V_9 ;
V_48 = F_27 () ;
if ( ! V_48 ) {
F_59 ( V_71 ) ;
return - V_9 ;
}
F_76 ( V_40 , & V_85 ) ;
V_10 = F_77 ( V_16 ) ;
if ( V_10 -> V_15 & V_27 ) {
V_72 = - V_8 ;
goto V_86;
}
memset ( V_71 , 0 , sizeof( struct V_1 ) * V_26 ) ;
V_10 -> V_15 |= V_27 ;
V_72 = F_23 ( V_10 , V_3 , V_71 , V_48 ) ;
V_86:
F_78 ( V_40 , & V_85 ) ;
if ( V_72 <= 0 ) {
F_79 ( V_48 ) ;
F_59 ( V_71 ) ;
}
return V_72 ;
}
static void F_80 ( struct V_1 * V_71 , int V_28 )
{
int V_79 ;
if ( ! V_71 )
return;
for ( V_79 = 0 ; V_79 < V_28 ; V_79 ++ ) {
if ( F_81 ( & V_71 [ V_79 ] ) ) {
F_82 ( 1 , & V_87 ) ;
F_83 ( & V_71 [ V_79 ] ) ;
}
}
}
static inline void F_80 ( struct V_1 * V_71 , int V_28 )
{
}
static void F_84 ( struct V_1 * V_71 , unsigned long * V_48 )
{
struct V_1 * V_88 ;
if ( ! V_48 )
return;
V_88 = F_71 ( V_48 ) ;
if ( F_85 ( V_88 ) || F_86 ( V_88 ) ) {
F_79 ( V_48 ) ;
if ( V_71 )
F_59 ( V_71 ) ;
return;
}
if ( V_71 )
F_61 ( V_71 ) ;
}
void F_87 ( struct V_83 * V_83 , struct V_6 * V_10 ,
unsigned long V_89 )
{
struct V_1 * V_71 = NULL ;
unsigned long * V_48 = NULL , V_85 ;
struct V_39 * V_40 = V_83 -> V_84 ;
F_76 ( V_40 , & V_85 ) ;
if ( V_10 -> V_15 ) {
V_48 = V_10 -> V_36 ;
V_71 = F_22 ( V_10 -> V_15 ,
F_7 ( V_10 ) ) ;
V_10 -> V_15 = 0 ;
V_10 -> V_36 = NULL ;
}
F_78 ( V_40 , & V_85 ) ;
F_80 ( V_71 + V_89 ,
V_26 - V_89 ) ;
F_84 ( V_71 , V_48 ) ;
}
