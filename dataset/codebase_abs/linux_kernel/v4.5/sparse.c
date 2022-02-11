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
F_39 ( V_58
L_4 ,
V_4 , V_52 ) ;
return;
}
F_39 ( V_58 L_5 , V_52 ,
V_53 , V_4 ) ;
F_39 ( V_59
L_6 ) ;
}
static unsigned long * T_4
F_34 ( struct V_42 * V_43 ,
unsigned long V_44 )
{
return F_40 ( V_44 , V_43 -> V_60 ) ;
}
static void T_4 F_37 ( int V_4 , unsigned long * V_51 )
{
}
static void T_4 F_41 ( void * V_61 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_64 , int V_65 )
{
void * V_51 ;
unsigned long V_33 ;
unsigned long * * V_66 = ( unsigned long * * ) V_61 ;
int V_44 = F_30 () ;
V_51 = F_34 ( F_38 ( V_65 ) ,
V_44 * V_64 ) ;
if ( ! V_51 ) {
F_39 ( V_67 L_7 , V_68 ) ;
return;
}
for ( V_33 = V_62 ; V_33 < V_63 ; V_33 ++ ) {
if ( ! F_42 ( V_33 ) )
continue;
V_66 [ V_33 ] = V_51 ;
V_51 += V_44 ;
F_37 ( V_65 , V_66 [ V_33 ] ) ;
}
}
struct V_1 T_4 * F_43 ( unsigned long V_33 , int V_4 )
{
struct V_1 * V_69 ;
unsigned long V_44 ;
V_69 = F_44 ( V_4 , sizeof( struct V_1 ) * V_29 ) ;
if ( V_69 )
return V_69 ;
V_44 = F_45 ( sizeof( struct V_1 ) * V_29 ) ;
V_69 = F_46 ( V_44 ,
V_70 , F_35 ( V_71 ) ,
V_72 , V_4 ) ;
return V_69 ;
}
void T_4 F_47 ( struct V_1 * * V_73 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_74 , int V_65 )
{
void * V_69 ;
unsigned long V_33 ;
unsigned long V_44 = sizeof( struct V_1 ) * V_29 ;
V_69 = F_44 ( V_65 , V_44 * V_74 ) ;
if ( V_69 ) {
for ( V_33 = V_62 ; V_33 < V_63 ; V_33 ++ ) {
if ( ! F_42 ( V_33 ) )
continue;
V_73 [ V_33 ] = V_69 ;
V_69 += V_44 ;
}
return;
}
V_44 = F_45 ( V_44 ) ;
V_69 = F_46 ( V_44 * V_74 ,
V_70 , F_35 ( V_71 ) ,
V_72 , V_65 ) ;
if ( V_69 ) {
for ( V_33 = V_62 ; V_33 < V_63 ; V_33 ++ ) {
if ( ! F_42 ( V_33 ) )
continue;
V_73 [ V_33 ] = V_69 ;
V_69 += V_44 ;
}
return;
}
for ( V_33 = V_62 ; V_33 < V_63 ; V_33 ++ ) {
struct V_5 * V_14 ;
if ( ! F_42 ( V_33 ) )
continue;
V_73 [ V_33 ] = F_43 ( V_33 , V_65 ) ;
if ( V_73 [ V_33 ] )
continue;
V_14 = F_13 ( V_33 ) ;
F_39 ( V_75 L_8
L_9 , V_68 ) ;
V_14 -> V_18 = 0 ;
}
}
static void T_4 F_48 ( void * V_61 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_74 , int V_65 )
{
struct V_1 * * V_73 = (struct V_1 * * ) V_61 ;
F_47 ( V_73 , V_62 , V_63 ,
V_74 , V_65 ) ;
}
static struct V_1 T_4 * F_49 ( unsigned long V_33 )
{
struct V_1 * V_69 ;
struct V_5 * V_14 = F_13 ( V_33 ) ;
int V_4 = F_16 ( V_14 ) ;
V_69 = F_43 ( V_33 , V_4 ) ;
if ( V_69 )
return V_69 ;
F_39 ( V_75 L_8
L_9 , V_68 ) ;
V_14 -> V_18 = 0 ;
return NULL ;
}
void __weak T_3 F_50 ( void )
{
}
static void T_4 F_51 ( void (* F_52)
( void * , unsigned long , unsigned long ,
unsigned long , int ) , void * V_61 )
{
unsigned long V_33 ;
unsigned long V_74 ;
int V_76 = 0 ;
unsigned long V_62 = 0 ;
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ ) {
struct V_5 * V_14 ;
if ( ! F_42 ( V_33 ) )
continue;
V_14 = F_13 ( V_33 ) ;
V_76 = F_16 ( V_14 ) ;
V_62 = V_33 ;
break;
}
V_74 = 1 ;
for ( V_33 = V_62 + 1 ; V_33 < V_55 ; V_33 ++ ) {
struct V_5 * V_14 ;
int V_65 ;
if ( ! F_42 ( V_33 ) )
continue;
V_14 = F_13 ( V_33 ) ;
V_65 = F_16 ( V_14 ) ;
if ( V_65 == V_76 ) {
V_74 ++ ;
continue;
}
F_52 ( V_61 , V_62 , V_33 ,
V_74 , V_76 ) ;
V_76 = V_65 ;
V_62 = V_33 ;
V_74 = 1 ;
}
F_52 ( V_61 , V_62 , V_55 ,
V_74 , V_76 ) ;
}
void T_4 F_53 ( void )
{
unsigned long V_33 ;
struct V_1 * V_69 ;
unsigned long * V_51 ;
unsigned long * * V_66 ;
int V_44 ;
#ifdef F_54
int V_77 ;
struct V_1 * * V_73 ;
#endif
F_55 ( ! F_56 ( sizeof( struct V_5 ) ) ) ;
F_57 () ;
V_44 = sizeof( unsigned long * ) * V_55 ;
V_66 = F_58 ( V_44 , 0 ) ;
if ( ! V_66 )
F_59 ( L_10 ) ;
F_51 ( F_41 ,
( void * ) V_66 ) ;
#ifdef F_54
V_77 = sizeof( struct V_1 * ) * V_55 ;
V_73 = F_58 ( V_77 , 0 ) ;
if ( ! V_73 )
F_59 ( L_11 ) ;
F_51 ( F_48 ,
( void * ) V_73 ) ;
#endif
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ ) {
if ( ! F_42 ( V_33 ) )
continue;
V_51 = V_66 [ V_33 ] ;
if ( ! V_51 )
continue;
#ifdef F_54
V_69 = V_73 [ V_33 ] ;
#else
V_69 = F_49 ( V_33 ) ;
#endif
if ( ! V_69 )
continue;
F_28 ( F_13 ( V_33 ) , V_33 , V_69 ,
V_51 ) ;
}
F_50 () ;
#ifdef F_54
F_60 ( F_35 ( V_73 ) , V_77 ) ;
#endif
F_60 ( F_35 ( V_66 ) , V_44 ) ;
}
static inline struct V_1 * F_61 ( unsigned long V_33 , int V_4 )
{
return F_43 ( V_33 , V_4 ) ;
}
static void F_62 ( struct V_1 * V_78 )
{
unsigned long V_25 = ( unsigned long ) V_78 ;
unsigned long V_26 = ( unsigned long ) ( V_78 + V_29 ) ;
F_63 ( V_25 , V_26 ) ;
}
static void F_64 ( struct V_1 * V_78 )
{
unsigned long V_25 = ( unsigned long ) V_78 ;
unsigned long V_26 = ( unsigned long ) ( V_78 + V_29 ) ;
F_63 ( V_25 , V_26 ) ;
}
static struct V_1 * F_65 ( void )
{
struct V_1 * V_1 , * V_79 ;
unsigned long V_80 = sizeof( struct V_1 ) * V_29 ;
V_1 = F_66 ( V_10 | V_81 , F_67 ( V_80 ) ) ;
if ( V_1 )
goto V_82;
V_79 = F_68 ( V_80 ) ;
if ( V_79 )
goto V_83;
return NULL ;
V_82:
V_79 = (struct V_1 * ) F_69 ( F_70 ( V_1 ) ) ;
V_83:
return V_79 ;
}
static inline struct V_1 * F_61 ( unsigned long V_33 , int V_4 )
{
return F_65 () ;
}
static void F_62 ( struct V_1 * V_78 )
{
if ( F_71 ( V_78 ) )
F_72 ( V_78 ) ;
else
F_73 ( ( unsigned long ) V_78 ,
F_67 ( sizeof( struct V_1 ) * V_29 ) ) ;
}
static void F_64 ( struct V_1 * V_78 )
{
unsigned long V_84 , V_85 , V_86 ;
unsigned long V_87 , V_31 ;
struct V_1 * V_1 = F_74 ( V_78 ) ;
V_31 = F_45 ( V_29 * sizeof( struct V_1 ) )
>> V_23 ;
for ( V_86 = 0 ; V_86 < V_31 ; V_86 ++ , V_1 ++ ) {
V_87 = ( unsigned long ) V_1 -> V_88 . V_89 ;
F_75 ( V_87 == V_90 ) ;
V_84 = F_21 ( F_70 ( V_1 ) ) ;
V_85 = V_1 -> V_91 ;
if ( V_84 != V_85 )
F_76 ( V_1 ) ;
}
}
int T_3 F_77 ( struct V_92 * V_92 , unsigned long V_19 )
{
unsigned long V_3 = F_21 ( V_19 ) ;
struct V_42 * V_43 = V_92 -> V_93 ;
struct V_5 * V_14 ;
struct V_1 * V_78 ;
unsigned long * V_51 ;
unsigned long V_94 ;
int V_79 ;
V_79 = F_10 ( V_3 , V_43 -> V_60 ) ;
if ( V_79 < 0 && V_79 != - V_12 )
return V_79 ;
V_78 = F_61 ( V_3 , V_43 -> V_60 ) ;
if ( ! V_78 )
return - V_13 ;
V_51 = F_32 () ;
if ( ! V_51 ) {
F_62 ( V_78 ) ;
return - V_13 ;
}
F_78 ( V_43 , & V_94 ) ;
V_14 = F_79 ( V_19 ) ;
if ( V_14 -> V_18 & V_30 ) {
V_79 = - V_12 ;
goto V_95;
}
memset ( V_78 , 0 , sizeof( struct V_1 ) * V_29 ) ;
V_14 -> V_18 |= V_30 ;
V_79 = F_28 ( V_14 , V_3 , V_78 , V_51 ) ;
V_95:
F_80 ( V_43 , & V_94 ) ;
if ( V_79 <= 0 ) {
F_81 ( V_51 ) ;
F_62 ( V_78 ) ;
}
return V_79 ;
}
static void F_82 ( struct V_1 * V_78 , int V_31 )
{
int V_86 ;
if ( ! V_78 )
return;
for ( V_86 = 0 ; V_86 < V_31 ; V_86 ++ ) {
if ( F_83 ( & V_78 [ V_86 ] ) ) {
F_84 ( 1 , & V_96 ) ;
F_85 ( & V_78 [ V_86 ] ) ;
}
}
}
static inline void F_82 ( struct V_1 * V_78 , int V_31 )
{
}
static void F_86 ( struct V_1 * V_78 , unsigned long * V_51 )
{
struct V_1 * V_97 ;
if ( ! V_51 )
return;
V_97 = F_74 ( V_51 ) ;
if ( F_87 ( V_97 ) || F_88 ( V_97 ) ) {
F_81 ( V_51 ) ;
if ( V_78 )
F_62 ( V_78 ) ;
return;
}
if ( V_78 )
F_64 ( V_78 ) ;
}
void F_89 ( struct V_92 * V_92 , struct V_5 * V_14 ,
unsigned long V_98 )
{
struct V_1 * V_78 = NULL ;
unsigned long * V_51 = NULL , V_94 ;
struct V_42 * V_43 = V_92 -> V_93 ;
F_78 ( V_43 , & V_94 ) ;
if ( V_14 -> V_18 ) {
V_51 = V_14 -> V_39 ;
V_78 = F_27 ( V_14 -> V_18 ,
F_12 ( V_14 ) ) ;
V_14 -> V_18 = 0 ;
V_14 -> V_39 = NULL ;
}
F_80 ( V_43 , & V_94 ) ;
F_82 ( V_78 + V_98 ,
V_29 - V_98 ) ;
F_86 ( V_78 , V_51 ) ;
}
