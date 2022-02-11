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
static struct V_5 T_1 T_2 * F_4 ( int V_4 )
{
struct V_5 * V_6 = NULL ;
unsigned long V_7 = V_8 *
sizeof( struct V_5 ) ;
if ( F_5 () ) {
if ( F_6 ( V_4 , V_9 ) )
V_6 = F_7 ( V_7 , V_10 , V_4 ) ;
else
V_6 = F_8 ( V_7 , V_10 ) ;
} else {
V_6 = F_9 ( V_7 , V_4 ) ;
}
return V_6 ;
}
static int T_3 F_10 ( unsigned long V_3 , int V_4 )
{
unsigned long V_11 = F_11 ( V_3 ) ;
struct V_5 * V_6 ;
if ( V_5 [ V_11 ] )
return - V_12 ;
V_6 = F_4 ( V_4 ) ;
if ( ! V_6 )
return - V_13 ;
V_5 [ V_11 ] = V_6 ;
return 0 ;
}
static inline int F_10 ( unsigned long V_3 , int V_4 )
{
return 0 ;
}
int F_12 ( struct V_5 * V_14 )
{
unsigned long V_15 ;
struct V_5 * V_11 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_11 = F_13 ( V_15 * V_8 ) ;
if ( ! V_11 )
continue;
if ( ( V_14 >= V_11 ) && ( V_14 < ( V_11 + V_8 ) ) )
break;
}
F_14 ( V_15 == V_16 ) ;
return ( V_15 * V_8 ) + ( V_14 - V_11 ) ;
}
static inline unsigned long F_15 ( int V_4 )
{
return ( V_4 << V_17 ) ;
}
static inline int F_16 ( struct V_5 * V_6 )
{
return ( V_6 -> V_18 >> V_17 ) ;
}
void T_3 F_17 ( unsigned long * V_19 ,
unsigned long * V_20 )
{
unsigned long V_21 = 1UL << ( V_22 - V_23 ) ;
if ( * V_19 > V_21 ) {
F_18 ( V_24 , L_1 ,
L_2 ,
* V_19 , * V_20 , V_21 ) ;
F_19 ( 1 ) ;
* V_19 = V_21 ;
* V_20 = V_21 ;
} else if ( * V_20 > V_21 ) {
F_18 ( V_24 , L_1 ,
L_3 ,
* V_19 , * V_20 , V_21 ) ;
F_19 ( 1 ) ;
* V_20 = V_21 ;
}
}
void T_4 F_20 ( int V_4 , unsigned long V_25 , unsigned long V_26 )
{
unsigned long V_27 ;
V_25 &= V_28 ;
F_17 ( & V_25 , & V_26 ) ;
for ( V_27 = V_25 ; V_27 < V_26 ; V_27 += V_29 ) {
unsigned long V_6 = F_21 ( V_27 ) ;
struct V_5 * V_14 ;
F_10 ( V_6 , V_4 ) ;
F_3 ( V_6 , V_4 ) ;
V_14 = F_13 ( V_6 ) ;
if ( ! V_14 -> V_18 )
V_14 -> V_18 = F_15 ( V_4 ) |
V_30 ;
}
}
unsigned long T_4 F_22 ( int V_4 , unsigned long V_19 ,
unsigned long V_20 )
{
unsigned long V_27 ;
unsigned long V_31 = 0 ;
F_17 ( & V_19 , & V_20 ) ;
for ( V_27 = V_19 ; V_27 < V_20 ; V_27 += V_29 ) {
if ( V_4 != F_23 ( V_27 ) )
continue;
if ( F_24 ( V_27 ) )
V_31 += V_29 ;
}
return V_31 * sizeof( struct V_1 ) ;
}
static unsigned long F_25 ( struct V_1 * V_32 , unsigned long V_33 )
{
return ( unsigned long ) ( V_32 - ( F_26 ( V_33 ) ) ) ;
}
struct V_1 * F_27 ( unsigned long V_34 , unsigned long V_33 )
{
V_34 &= V_35 ;
return ( (struct V_1 * ) V_34 ) + F_26 ( V_33 ) ;
}
static int T_3 F_28 ( struct V_5 * V_14 ,
unsigned long V_33 , struct V_1 * V_32 ,
unsigned long * V_36 )
{
if ( ! F_29 ( V_14 ) )
return - V_37 ;
V_14 -> V_18 &= ~ V_35 ;
V_14 -> V_18 |= F_25 ( V_32 , V_33 ) |
V_38 ;
V_14 -> V_39 = V_36 ;
return 1 ;
}
unsigned long F_30 ( void )
{
unsigned long V_40 ;
V_40 = F_31 ( V_41 , 8 ) / 8 ;
V_40 = F_31 ( V_40 , sizeof( unsigned long ) ) ;
return V_40 ;
}
static unsigned long * F_32 ( void )
{
return F_33 ( F_30 () , V_10 ) ;
}
static unsigned long * T_4
F_34 ( struct V_42 * V_43 ,
unsigned long V_44 )
{
unsigned long V_45 , V_46 ;
unsigned long * V_47 ;
int V_4 ;
V_45 = F_35 ( V_43 ) & ( V_28 << V_23 ) ;
V_46 = V_45 + ( 1UL << V_48 ) ;
V_4 = F_23 ( V_45 >> V_23 ) ;
V_49:
V_47 = F_36 ( V_44 ,
V_50 , V_45 , V_46 ,
V_4 ) ;
if ( ! V_47 && V_46 ) {
V_46 = 0 ;
goto V_49;
}
return V_47 ;
}
static void T_4 F_37 ( int V_4 , unsigned long * V_51 )
{
unsigned long V_52 , V_53 ;
static unsigned long V_54 = V_55 ;
static unsigned long V_56 = V_55 ;
struct V_42 * V_43 = F_38 ( V_4 ) ;
int V_57 ;
V_52 = F_21 ( F_35 ( V_51 ) >> V_23 ) ;
V_53 = F_21 ( F_35 ( V_43 ) >> V_23 ) ;
if ( V_52 == V_53 )
return;
if ( V_54 == V_52 && V_56 == V_53 )
return;
V_54 = V_52 ;
V_56 = V_53 ;
V_57 = F_16 ( F_13 ( V_52 ) ) ;
if ( V_57 != V_4 ) {
F_39 ( L_4 ,
V_4 , V_52 ) ;
return;
}
F_39 ( L_5 ,
V_52 , V_53 , V_4 ) ;
}
static unsigned long * T_4
F_34 ( struct V_42 * V_43 ,
unsigned long V_44 )
{
return F_40 ( V_44 , V_43 -> V_58 ) ;
}
static void T_4 F_37 ( int V_4 , unsigned long * V_51 )
{
}
static void T_4 F_41 ( void * V_59 ,
unsigned long V_60 ,
unsigned long V_61 ,
unsigned long V_62 , int V_63 )
{
void * V_51 ;
unsigned long V_33 ;
unsigned long * * V_64 = ( unsigned long * * ) V_59 ;
int V_44 = F_30 () ;
V_51 = F_34 ( F_38 ( V_63 ) ,
V_44 * V_62 ) ;
if ( ! V_51 ) {
F_42 ( L_6 , V_65 ) ;
return;
}
for ( V_33 = V_60 ; V_33 < V_61 ; V_33 ++ ) {
if ( ! F_43 ( V_33 ) )
continue;
V_64 [ V_33 ] = V_51 ;
V_51 += V_44 ;
F_37 ( V_63 , V_64 [ V_33 ] ) ;
}
}
struct V_1 T_4 * F_44 ( unsigned long V_33 , int V_4 )
{
struct V_1 * V_66 ;
unsigned long V_44 ;
V_66 = F_45 ( V_4 , sizeof( struct V_1 ) * V_29 ) ;
if ( V_66 )
return V_66 ;
V_44 = F_46 ( sizeof( struct V_1 ) * V_29 ) ;
V_66 = F_47 ( V_44 ,
V_67 , F_35 ( V_68 ) ,
V_69 , V_4 ) ;
return V_66 ;
}
void T_4 F_48 ( struct V_1 * * V_70 ,
unsigned long V_60 ,
unsigned long V_61 ,
unsigned long V_71 , int V_63 )
{
void * V_66 ;
unsigned long V_33 ;
unsigned long V_44 = sizeof( struct V_1 ) * V_29 ;
V_66 = F_45 ( V_63 , V_44 * V_71 ) ;
if ( V_66 ) {
for ( V_33 = V_60 ; V_33 < V_61 ; V_33 ++ ) {
if ( ! F_43 ( V_33 ) )
continue;
V_70 [ V_33 ] = V_66 ;
V_66 += V_44 ;
}
return;
}
V_44 = F_46 ( V_44 ) ;
V_66 = F_47 ( V_44 * V_71 ,
V_67 , F_35 ( V_68 ) ,
V_69 , V_63 ) ;
if ( V_66 ) {
for ( V_33 = V_60 ; V_33 < V_61 ; V_33 ++ ) {
if ( ! F_43 ( V_33 ) )
continue;
V_70 [ V_33 ] = V_66 ;
V_66 += V_44 ;
}
return;
}
for ( V_33 = V_60 ; V_33 < V_61 ; V_33 ++ ) {
struct V_5 * V_14 ;
if ( ! F_43 ( V_33 ) )
continue;
V_70 [ V_33 ] = F_44 ( V_33 , V_63 ) ;
if ( V_70 [ V_33 ] )
continue;
V_14 = F_13 ( V_33 ) ;
F_49 ( L_7 ,
V_65 ) ;
V_14 -> V_18 = 0 ;
}
}
static void T_4 F_50 ( void * V_59 ,
unsigned long V_60 ,
unsigned long V_61 ,
unsigned long V_71 , int V_63 )
{
struct V_1 * * V_70 = (struct V_1 * * ) V_59 ;
F_48 ( V_70 , V_60 , V_61 ,
V_71 , V_63 ) ;
}
static struct V_1 T_4 * F_51 ( unsigned long V_33 )
{
struct V_1 * V_66 ;
struct V_5 * V_14 = F_13 ( V_33 ) ;
int V_4 = F_16 ( V_14 ) ;
V_66 = F_44 ( V_33 , V_4 ) ;
if ( V_66 )
return V_66 ;
F_49 ( L_7 ,
V_65 ) ;
V_14 -> V_18 = 0 ;
return NULL ;
}
void __weak T_3 F_52 ( void )
{
}
static void T_4 F_53 ( void (* F_54)
( void * , unsigned long , unsigned long ,
unsigned long , int ) , void * V_59 )
{
unsigned long V_33 ;
unsigned long V_71 ;
int V_72 = 0 ;
unsigned long V_60 = 0 ;
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ ) {
struct V_5 * V_14 ;
if ( ! F_43 ( V_33 ) )
continue;
V_14 = F_13 ( V_33 ) ;
V_72 = F_16 ( V_14 ) ;
V_60 = V_33 ;
break;
}
V_71 = 1 ;
for ( V_33 = V_60 + 1 ; V_33 < V_55 ; V_33 ++ ) {
struct V_5 * V_14 ;
int V_63 ;
if ( ! F_43 ( V_33 ) )
continue;
V_14 = F_13 ( V_33 ) ;
V_63 = F_16 ( V_14 ) ;
if ( V_63 == V_72 ) {
V_71 ++ ;
continue;
}
F_54 ( V_59 , V_60 , V_33 ,
V_71 , V_72 ) ;
V_72 = V_63 ;
V_60 = V_33 ;
V_71 = 1 ;
}
F_54 ( V_59 , V_60 , V_55 ,
V_71 , V_72 ) ;
}
void T_4 F_55 ( void )
{
unsigned long V_33 ;
struct V_1 * V_66 ;
unsigned long * V_51 ;
unsigned long * * V_64 ;
int V_44 ;
#ifdef F_56
int V_73 ;
struct V_1 * * V_70 ;
#endif
F_57 ( ! F_58 ( sizeof( struct V_5 ) ) ) ;
F_59 () ;
V_44 = sizeof( unsigned long * ) * V_55 ;
V_64 = F_60 ( V_44 , 0 ) ;
if ( ! V_64 )
F_61 ( L_8 ) ;
F_53 ( F_41 ,
( void * ) V_64 ) ;
#ifdef F_56
V_73 = sizeof( struct V_1 * ) * V_55 ;
V_70 = F_60 ( V_73 , 0 ) ;
if ( ! V_70 )
F_61 ( L_9 ) ;
F_53 ( F_50 ,
( void * ) V_70 ) ;
#endif
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ ) {
if ( ! F_43 ( V_33 ) )
continue;
V_51 = V_64 [ V_33 ] ;
if ( ! V_51 )
continue;
#ifdef F_56
V_66 = V_70 [ V_33 ] ;
#else
V_66 = F_51 ( V_33 ) ;
#endif
if ( ! V_66 )
continue;
F_28 ( F_13 ( V_33 ) , V_33 , V_66 ,
V_51 ) ;
}
F_52 () ;
#ifdef F_56
F_62 ( F_35 ( V_70 ) , V_73 ) ;
#endif
F_62 ( F_35 ( V_64 ) , V_44 ) ;
}
static inline struct V_1 * F_63 ( unsigned long V_33 , int V_4 )
{
return F_44 ( V_33 , V_4 ) ;
}
static void F_64 ( struct V_1 * V_74 )
{
unsigned long V_25 = ( unsigned long ) V_74 ;
unsigned long V_26 = ( unsigned long ) ( V_74 + V_29 ) ;
F_65 ( V_25 , V_26 ) ;
}
static void F_66 ( struct V_1 * V_74 )
{
unsigned long V_25 = ( unsigned long ) V_74 ;
unsigned long V_26 = ( unsigned long ) ( V_74 + V_29 ) ;
F_65 ( V_25 , V_26 ) ;
}
static struct V_1 * F_67 ( void )
{
struct V_1 * V_1 , * V_75 ;
unsigned long V_76 = sizeof( struct V_1 ) * V_29 ;
V_1 = F_68 ( V_10 | V_77 , F_69 ( V_76 ) ) ;
if ( V_1 )
goto V_78;
V_75 = F_70 ( V_76 ) ;
if ( V_75 )
goto V_79;
return NULL ;
V_78:
V_75 = (struct V_1 * ) F_71 ( F_72 ( V_1 ) ) ;
V_79:
return V_75 ;
}
static inline struct V_1 * F_63 ( unsigned long V_33 , int V_4 )
{
return F_67 () ;
}
static void F_64 ( struct V_1 * V_74 )
{
if ( F_73 ( V_74 ) )
F_74 ( V_74 ) ;
else
F_75 ( ( unsigned long ) V_74 ,
F_69 ( sizeof( struct V_1 ) * V_29 ) ) ;
}
static void F_66 ( struct V_1 * V_74 )
{
unsigned long V_80 , V_81 , V_82 ;
unsigned long V_83 , V_31 ;
struct V_1 * V_1 = F_76 ( V_74 ) ;
V_31 = F_46 ( V_29 * sizeof( struct V_1 ) )
>> V_23 ;
for ( V_82 = 0 ; V_82 < V_31 ; V_82 ++ , V_1 ++ ) {
V_83 = ( unsigned long ) V_1 -> V_84 . V_85 ;
F_77 ( V_83 == V_86 ) ;
V_80 = F_21 ( F_72 ( V_1 ) ) ;
V_81 = V_1 -> V_87 ;
if ( V_80 != V_81 )
F_78 ( V_1 ) ;
}
}
int T_3 F_79 ( struct V_88 * V_88 , unsigned long V_19 )
{
unsigned long V_3 = F_21 ( V_19 ) ;
struct V_42 * V_43 = V_88 -> V_89 ;
struct V_5 * V_14 ;
struct V_1 * V_74 ;
unsigned long * V_51 ;
unsigned long V_90 ;
int V_75 ;
V_75 = F_10 ( V_3 , V_43 -> V_58 ) ;
if ( V_75 < 0 && V_75 != - V_12 )
return V_75 ;
V_74 = F_63 ( V_3 , V_43 -> V_58 ) ;
if ( ! V_74 )
return - V_13 ;
V_51 = F_32 () ;
if ( ! V_51 ) {
F_64 ( V_74 ) ;
return - V_13 ;
}
F_80 ( V_43 , & V_90 ) ;
V_14 = F_81 ( V_19 ) ;
if ( V_14 -> V_18 & V_30 ) {
V_75 = - V_12 ;
goto V_91;
}
memset ( V_74 , 0 , sizeof( struct V_1 ) * V_29 ) ;
V_14 -> V_18 |= V_30 ;
V_75 = F_28 ( V_14 , V_3 , V_74 , V_51 ) ;
V_91:
F_82 ( V_43 , & V_90 ) ;
if ( V_75 <= 0 ) {
F_83 ( V_51 ) ;
F_64 ( V_74 ) ;
}
return V_75 ;
}
static void F_84 ( struct V_1 * V_74 , int V_31 )
{
int V_82 ;
if ( ! V_74 )
return;
for ( V_82 = 0 ; V_82 < V_31 ; V_82 ++ ) {
if ( F_85 ( & V_74 [ V_82 ] ) ) {
F_86 ( 1 , & V_92 ) ;
F_87 ( & V_74 [ V_82 ] ) ;
}
}
}
static inline void F_84 ( struct V_1 * V_74 , int V_31 )
{
}
static void F_88 ( struct V_1 * V_74 , unsigned long * V_51 )
{
struct V_1 * V_93 ;
if ( ! V_51 )
return;
V_93 = F_76 ( V_51 ) ;
if ( F_89 ( V_93 ) || F_90 ( V_93 ) ) {
F_83 ( V_51 ) ;
if ( V_74 )
F_64 ( V_74 ) ;
return;
}
if ( V_74 )
F_66 ( V_74 ) ;
}
void F_91 ( struct V_88 * V_88 , struct V_5 * V_14 ,
unsigned long V_94 )
{
struct V_1 * V_74 = NULL ;
unsigned long * V_51 = NULL , V_90 ;
struct V_42 * V_43 = V_88 -> V_89 ;
F_80 ( V_43 , & V_90 ) ;
if ( V_14 -> V_18 ) {
V_51 = V_14 -> V_39 ;
V_74 = F_27 ( V_14 -> V_18 ,
F_12 ( V_14 ) ) ;
V_14 -> V_18 = 0 ;
V_14 -> V_39 = NULL ;
}
F_82 ( V_43 , & V_90 ) ;
F_84 ( V_74 + V_94 ,
V_29 - V_94 ) ;
F_88 ( V_74 , V_51 ) ;
}
