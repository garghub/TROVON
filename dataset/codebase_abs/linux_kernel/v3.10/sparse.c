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
V_6 = F_9 ( F_10 ( V_4 ) , V_7 ) ;
}
return V_6 ;
}
static int T_3 F_11 ( unsigned long V_3 , int V_4 )
{
unsigned long V_11 = F_12 ( V_3 ) ;
struct V_5 * V_6 ;
int V_12 = 0 ;
if ( V_5 [ V_11 ] )
return - V_13 ;
V_6 = F_4 ( V_4 ) ;
if ( ! V_6 )
return - V_14 ;
V_5 [ V_11 ] = V_6 ;
return V_12 ;
}
static inline int F_11 ( unsigned long V_3 , int V_4 )
{
return 0 ;
}
int F_13 ( struct V_5 * V_15 )
{
unsigned long V_16 ;
struct V_5 * V_11 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_11 = F_14 ( V_16 * V_8 ) ;
if ( ! V_11 )
continue;
if ( ( V_15 >= V_11 ) && ( V_15 < ( V_11 + V_8 ) ) )
break;
}
F_15 ( V_16 == V_17 ) ;
return ( V_16 * V_8 ) + ( V_15 - V_11 ) ;
}
static inline unsigned long F_16 ( int V_4 )
{
return ( V_4 << V_18 ) ;
}
static inline int F_17 ( struct V_5 * V_6 )
{
return ( V_6 -> V_19 >> V_18 ) ;
}
void T_3 F_18 ( unsigned long * V_20 ,
unsigned long * V_21 )
{
unsigned long V_22 = 1UL << ( V_23 - V_24 ) ;
if ( * V_20 > V_22 ) {
F_19 ( V_25 , L_1 ,
L_2 ,
* V_20 , * V_21 , V_22 ) ;
F_20 ( 1 ) ;
* V_20 = V_22 ;
* V_21 = V_22 ;
} else if ( * V_21 > V_22 ) {
F_19 ( V_25 , L_1 ,
L_3 ,
* V_20 , * V_21 , V_22 ) ;
F_20 ( 1 ) ;
* V_21 = V_22 ;
}
}
void T_4 F_21 ( int V_4 , unsigned long V_26 , unsigned long V_27 )
{
unsigned long V_28 ;
V_26 &= V_29 ;
F_18 ( & V_26 , & V_27 ) ;
for ( V_28 = V_26 ; V_28 < V_27 ; V_28 += V_30 ) {
unsigned long V_6 = F_22 ( V_28 ) ;
struct V_5 * V_15 ;
F_11 ( V_6 , V_4 ) ;
F_3 ( V_6 , V_4 ) ;
V_15 = F_14 ( V_6 ) ;
if ( ! V_15 -> V_19 )
V_15 -> V_19 = F_16 ( V_4 ) |
V_31 ;
}
}
unsigned long T_4 F_23 ( int V_4 , unsigned long V_20 ,
unsigned long V_21 )
{
unsigned long V_28 ;
unsigned long V_32 = 0 ;
F_18 ( & V_20 , & V_21 ) ;
for ( V_28 = V_20 ; V_28 < V_21 ; V_28 += V_30 ) {
if ( V_4 != F_24 ( V_28 ) )
continue;
if ( F_25 ( V_28 ) )
V_32 += V_30 ;
}
return V_32 * sizeof( struct V_1 ) ;
}
static unsigned long F_26 ( struct V_1 * V_33 , unsigned long V_34 )
{
return ( unsigned long ) ( V_33 - ( F_27 ( V_34 ) ) ) ;
}
struct V_1 * F_28 ( unsigned long V_35 , unsigned long V_34 )
{
V_35 &= V_36 ;
return ( (struct V_1 * ) V_35 ) + F_27 ( V_34 ) ;
}
static int T_3 F_29 ( struct V_5 * V_15 ,
unsigned long V_34 , struct V_1 * V_33 ,
unsigned long * V_37 )
{
if ( ! F_30 ( V_15 ) )
return - V_38 ;
V_15 -> V_19 &= ~ V_36 ;
V_15 -> V_19 |= F_26 ( V_33 , V_34 ) |
V_39 ;
V_15 -> V_40 = V_37 ;
return 1 ;
}
unsigned long F_31 ( void )
{
unsigned long V_41 ;
V_41 = F_32 ( V_42 , 8 ) / 8 ;
V_41 = F_32 ( V_41 , sizeof( unsigned long ) ) ;
return V_41 ;
}
static unsigned long * F_33 ( void )
{
return F_34 ( F_31 () , V_10 ) ;
}
static unsigned long * T_4
F_35 ( struct V_43 * V_44 ,
unsigned long V_45 )
{
unsigned long V_46 , V_47 ;
unsigned long * V_48 ;
int V_4 ;
V_46 = F_36 ( V_44 ) & ( V_29 << V_24 ) ;
V_47 = V_46 + ( 1UL << V_49 ) ;
V_4 = F_24 ( V_46 >> V_24 ) ;
V_50:
V_48 = F_37 ( F_10 ( V_4 ) , V_45 ,
V_51 , V_46 , V_47 ) ;
if ( ! V_48 && V_47 ) {
V_47 = 0 ;
goto V_50;
}
return V_48 ;
}
static void T_4 F_38 ( int V_4 , unsigned long * V_52 )
{
unsigned long V_53 , V_54 ;
static unsigned long V_55 = V_56 ;
static unsigned long V_57 = V_56 ;
struct V_43 * V_44 = F_10 ( V_4 ) ;
int V_58 ;
V_53 = F_22 ( F_36 ( V_52 ) >> V_24 ) ;
V_54 = F_22 ( F_36 ( V_44 ) >> V_24 ) ;
if ( V_53 == V_54 )
return;
if ( V_55 == V_53 && V_57 == V_54 )
return;
V_55 = V_53 ;
V_57 = V_54 ;
V_58 = F_17 ( F_14 ( V_53 ) ) ;
if ( V_58 != V_4 ) {
F_39 ( V_59
L_4 ,
V_4 , V_53 ) ;
return;
}
F_39 ( V_59 L_5 , V_53 ,
V_54 , V_4 ) ;
F_39 ( V_60
L_6 ) ;
}
static unsigned long * T_4
F_35 ( struct V_43 * V_44 ,
unsigned long V_45 )
{
return F_40 ( V_44 , V_45 ) ;
}
static void T_4 F_38 ( int V_4 , unsigned long * V_52 )
{
}
static void T_4 F_41 ( unsigned long * * V_61 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_64 , int V_65 )
{
void * V_52 ;
unsigned long V_34 ;
int V_45 = F_31 () ;
V_52 = F_35 ( F_10 ( V_65 ) ,
V_45 * V_64 ) ;
if ( ! V_52 ) {
F_39 ( V_66 L_7 , V_67 ) ;
return;
}
for ( V_34 = V_62 ; V_34 < V_63 ; V_34 ++ ) {
if ( ! F_42 ( V_34 ) )
continue;
V_61 [ V_34 ] = V_52 ;
V_52 += V_45 ;
F_38 ( V_65 , V_61 [ V_34 ] ) ;
}
}
struct V_1 T_4 * F_43 ( unsigned long V_34 , int V_4 )
{
struct V_1 * V_68 ;
unsigned long V_45 ;
V_68 = F_44 ( V_4 , sizeof( struct V_1 ) * V_30 ) ;
if ( V_68 )
return V_68 ;
V_45 = F_45 ( sizeof( struct V_1 ) * V_30 ) ;
V_68 = F_46 ( F_10 ( V_4 ) , V_45 ,
V_69 , F_36 ( V_70 ) ) ;
return V_68 ;
}
void T_4 F_47 ( struct V_1 * * V_71 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_72 , int V_65 )
{
void * V_68 ;
unsigned long V_34 ;
unsigned long V_45 = sizeof( struct V_1 ) * V_30 ;
V_68 = F_44 ( V_65 , V_45 * V_72 ) ;
if ( V_68 ) {
for ( V_34 = V_62 ; V_34 < V_63 ; V_34 ++ ) {
if ( ! F_42 ( V_34 ) )
continue;
V_71 [ V_34 ] = V_68 ;
V_68 += V_45 ;
}
return;
}
V_45 = F_45 ( V_45 ) ;
V_68 = F_46 ( F_10 ( V_65 ) , V_45 * V_72 ,
V_69 , F_36 ( V_70 ) ) ;
if ( V_68 ) {
for ( V_34 = V_62 ; V_34 < V_63 ; V_34 ++ ) {
if ( ! F_42 ( V_34 ) )
continue;
V_71 [ V_34 ] = V_68 ;
V_68 += V_45 ;
}
return;
}
for ( V_34 = V_62 ; V_34 < V_63 ; V_34 ++ ) {
struct V_5 * V_15 ;
if ( ! F_42 ( V_34 ) )
continue;
V_71 [ V_34 ] = F_43 ( V_34 , V_65 ) ;
if ( V_71 [ V_34 ] )
continue;
V_15 = F_14 ( V_34 ) ;
F_39 ( V_73 L_8
L_9 , V_67 ) ;
V_15 -> V_19 = 0 ;
}
}
static void T_4 F_48 ( struct V_1 * * V_71 ,
unsigned long V_62 ,
unsigned long V_63 ,
unsigned long V_72 , int V_65 )
{
F_47 ( V_71 , V_62 , V_63 ,
V_72 , V_65 ) ;
}
static struct V_1 T_4 * F_49 ( unsigned long V_34 )
{
struct V_1 * V_68 ;
struct V_5 * V_15 = F_14 ( V_34 ) ;
int V_4 = F_17 ( V_15 ) ;
V_68 = F_43 ( V_34 , V_4 ) ;
if ( V_68 )
return V_68 ;
F_39 ( V_73 L_8
L_9 , V_67 ) ;
V_15 -> V_19 = 0 ;
return NULL ;
}
void T_4 F_50 ( void )
{
unsigned long V_34 ;
struct V_1 * V_68 ;
unsigned long * V_52 ;
unsigned long * * V_61 ;
int V_45 ;
int V_74 = 0 ;
unsigned long V_62 = 0 ;
unsigned long V_64 ;
#ifdef F_51
unsigned long V_72 ;
int V_75 ;
struct V_1 * * V_71 ;
#endif
F_52 () ;
V_45 = sizeof( unsigned long * ) * V_56 ;
V_61 = F_53 ( V_45 ) ;
if ( ! V_61 )
F_54 ( L_10 ) ;
for ( V_34 = 0 ; V_34 < V_56 ; V_34 ++ ) {
struct V_5 * V_15 ;
if ( ! F_42 ( V_34 ) )
continue;
V_15 = F_14 ( V_34 ) ;
V_74 = F_17 ( V_15 ) ;
V_62 = V_34 ;
break;
}
V_64 = 1 ;
for ( V_34 = V_62 + 1 ; V_34 < V_56 ; V_34 ++ ) {
struct V_5 * V_15 ;
int V_65 ;
if ( ! F_42 ( V_34 ) )
continue;
V_15 = F_14 ( V_34 ) ;
V_65 = F_17 ( V_15 ) ;
if ( V_65 == V_74 ) {
V_64 ++ ;
continue;
}
F_41 ( V_61 , V_62 , V_34 ,
V_64 , V_74 ) ;
V_74 = V_65 ;
V_62 = V_34 ;
V_64 = 1 ;
}
F_41 ( V_61 , V_62 , V_56 ,
V_64 , V_74 ) ;
#ifdef F_51
V_75 = sizeof( struct V_1 * ) * V_56 ;
V_71 = F_53 ( V_75 ) ;
if ( ! V_71 )
F_54 ( L_11 ) ;
for ( V_34 = 0 ; V_34 < V_56 ; V_34 ++ ) {
struct V_5 * V_15 ;
if ( ! F_42 ( V_34 ) )
continue;
V_15 = F_14 ( V_34 ) ;
V_74 = F_17 ( V_15 ) ;
V_62 = V_34 ;
break;
}
V_72 = 1 ;
for ( V_34 = V_62 + 1 ; V_34 < V_56 ; V_34 ++ ) {
struct V_5 * V_15 ;
int V_65 ;
if ( ! F_42 ( V_34 ) )
continue;
V_15 = F_14 ( V_34 ) ;
V_65 = F_17 ( V_15 ) ;
if ( V_65 == V_74 ) {
V_72 ++ ;
continue;
}
F_48 ( V_71 , V_62 , V_34 ,
V_72 , V_74 ) ;
V_74 = V_65 ;
V_62 = V_34 ;
V_72 = 1 ;
}
F_48 ( V_71 , V_62 , V_56 ,
V_72 , V_74 ) ;
#endif
for ( V_34 = 0 ; V_34 < V_56 ; V_34 ++ ) {
if ( ! F_42 ( V_34 ) )
continue;
V_52 = V_61 [ V_34 ] ;
if ( ! V_52 )
continue;
#ifdef F_51
V_68 = V_71 [ V_34 ] ;
#else
V_68 = F_49 ( V_34 ) ;
#endif
if ( ! V_68 )
continue;
F_29 ( F_14 ( V_34 ) , V_34 , V_68 ,
V_52 ) ;
}
F_55 () ;
#ifdef F_51
F_56 ( F_36 ( V_71 ) , V_75 ) ;
#endif
F_56 ( F_36 ( V_61 ) , V_45 ) ;
}
static inline struct V_1 * F_57 ( unsigned long V_34 , int V_4 ,
unsigned long V_32 )
{
return F_43 ( V_34 , V_4 ) ;
}
static void F_58 ( struct V_1 * V_76 , unsigned long V_32 )
{
unsigned long V_26 = ( unsigned long ) V_76 ;
unsigned long V_27 = ( unsigned long ) ( V_76 + V_32 ) ;
F_59 ( V_26 , V_27 ) ;
}
static void F_60 ( struct V_1 * V_76 , unsigned long V_32 )
{
unsigned long V_26 = ( unsigned long ) V_76 ;
unsigned long V_27 = ( unsigned long ) ( V_76 + V_32 ) ;
F_59 ( V_26 , V_27 ) ;
}
static struct V_1 * F_61 ( unsigned long V_32 )
{
struct V_1 * V_1 , * V_12 ;
unsigned long V_77 = sizeof( struct V_1 ) * V_32 ;
V_1 = F_62 ( V_10 | V_78 , F_63 ( V_77 ) ) ;
if ( V_1 )
goto V_79;
V_12 = F_64 ( V_77 ) ;
if ( V_12 )
goto V_80;
return NULL ;
V_79:
V_12 = (struct V_1 * ) F_65 ( F_66 ( V_1 ) ) ;
V_80:
return V_12 ;
}
static inline struct V_1 * F_57 ( unsigned long V_34 , int V_4 ,
unsigned long V_32 )
{
return F_61 ( V_32 ) ;
}
static void F_58 ( struct V_1 * V_76 , unsigned long V_32 )
{
if ( F_67 ( V_76 ) )
F_68 ( V_76 ) ;
else
F_69 ( ( unsigned long ) V_76 ,
F_63 ( sizeof( struct V_1 ) * V_32 ) ) ;
}
static void F_60 ( struct V_1 * V_76 , unsigned long V_32 )
{
unsigned long V_81 , V_82 , V_83 ;
unsigned long V_84 ;
struct V_1 * V_1 = F_70 ( V_76 ) ;
for ( V_83 = 0 ; V_83 < V_32 ; V_83 ++ , V_1 ++ ) {
V_84 = ( unsigned long ) V_1 -> V_85 . V_86 ;
F_71 ( V_84 == V_87 ) ;
V_81 = F_22 ( F_66 ( V_1 ) ) ;
V_82 = V_1 -> V_88 ;
if ( V_81 != V_82 )
F_72 ( V_1 ) ;
}
}
int T_3 F_73 ( struct V_89 * V_89 , unsigned long V_20 ,
int V_32 )
{
unsigned long V_3 = F_22 ( V_20 ) ;
struct V_43 * V_44 = V_89 -> V_90 ;
struct V_5 * V_15 ;
struct V_1 * V_76 ;
unsigned long * V_52 ;
unsigned long V_91 ;
int V_12 ;
V_12 = F_11 ( V_3 , V_44 -> V_92 ) ;
if ( V_12 < 0 && V_12 != - V_13 )
return V_12 ;
V_76 = F_57 ( V_3 , V_44 -> V_92 , V_32 ) ;
if ( ! V_76 )
return - V_14 ;
V_52 = F_33 () ;
if ( ! V_52 ) {
F_58 ( V_76 , V_32 ) ;
return - V_14 ;
}
F_74 ( V_44 , & V_91 ) ;
V_15 = F_75 ( V_20 ) ;
if ( V_15 -> V_19 & V_31 ) {
V_12 = - V_13 ;
goto V_93;
}
memset ( V_76 , 0 , sizeof( struct V_1 ) * V_32 ) ;
V_15 -> V_19 |= V_31 ;
V_12 = F_29 ( V_15 , V_3 , V_76 , V_52 ) ;
V_93:
F_76 ( V_44 , & V_91 ) ;
if ( V_12 <= 0 ) {
F_77 ( V_52 ) ;
F_58 ( V_76 , V_32 ) ;
}
return V_12 ;
}
static void F_78 ( struct V_1 * V_76 , int V_32 )
{
int V_83 ;
if ( ! V_76 )
return;
for ( V_83 = 0 ; V_83 < V_30 ; V_83 ++ ) {
if ( F_79 ( & V_76 [ V_83 ] ) ) {
F_80 ( 1 , & V_94 ) ;
F_81 ( & V_76 [ V_83 ] ) ;
}
}
}
static inline void F_78 ( struct V_1 * V_76 , int V_32 )
{
}
static void F_82 ( struct V_1 * V_76 , unsigned long * V_52 )
{
struct V_1 * V_95 ;
unsigned long V_32 ;
if ( ! V_52 )
return;
V_95 = F_70 ( V_52 ) ;
if ( F_83 ( V_95 ) || F_84 ( V_95 ) ) {
F_77 ( V_52 ) ;
if ( V_76 )
F_58 ( V_76 , V_30 ) ;
return;
}
if ( V_76 ) {
V_32 = F_45 ( V_30 * sizeof( struct V_1 ) )
>> V_24 ;
F_60 ( V_76 , V_32 ) ;
}
}
void F_85 ( struct V_89 * V_89 , struct V_5 * V_15 )
{
struct V_1 * V_76 = NULL ;
unsigned long * V_52 = NULL , V_91 ;
struct V_43 * V_44 = V_89 -> V_90 ;
F_74 ( V_44 , & V_91 ) ;
if ( V_15 -> V_19 ) {
V_52 = V_15 -> V_40 ;
V_76 = F_28 ( V_15 -> V_19 ,
F_13 ( V_15 ) ) ;
V_15 -> V_19 = 0 ;
V_15 -> V_40 = NULL ;
}
F_76 ( V_44 , & V_91 ) ;
F_78 ( V_76 , V_30 ) ;
F_82 ( V_76 , V_52 ) ;
}
