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
if ( V_5 [ V_11 ] )
return - V_12 ;
V_6 = F_4 ( V_4 ) ;
if ( ! V_6 )
return - V_13 ;
V_5 [ V_11 ] = V_6 ;
return 0 ;
}
static inline int F_11 ( unsigned long V_3 , int V_4 )
{
return 0 ;
}
int F_13 ( struct V_5 * V_14 )
{
unsigned long V_15 ;
struct V_5 * V_11 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_11 = F_14 ( V_15 * V_8 ) ;
if ( ! V_11 )
continue;
if ( ( V_14 >= V_11 ) && ( V_14 < ( V_11 + V_8 ) ) )
break;
}
F_15 ( V_15 == V_16 ) ;
return ( V_15 * V_8 ) + ( V_14 - V_11 ) ;
}
static inline unsigned long F_16 ( int V_4 )
{
return ( V_4 << V_17 ) ;
}
static inline int F_17 ( struct V_5 * V_6 )
{
return ( V_6 -> V_18 >> V_17 ) ;
}
void T_3 F_18 ( unsigned long * V_19 ,
unsigned long * V_20 )
{
unsigned long V_21 = 1UL << ( V_22 - V_23 ) ;
if ( * V_19 > V_21 ) {
F_19 ( V_24 , L_1 ,
L_2 ,
* V_19 , * V_20 , V_21 ) ;
F_20 ( 1 ) ;
* V_19 = V_21 ;
* V_20 = V_21 ;
} else if ( * V_20 > V_21 ) {
F_19 ( V_24 , L_1 ,
L_3 ,
* V_19 , * V_20 , V_21 ) ;
F_20 ( 1 ) ;
* V_20 = V_21 ;
}
}
void T_4 F_21 ( int V_4 , unsigned long V_25 , unsigned long V_26 )
{
unsigned long V_27 ;
V_25 &= V_28 ;
F_18 ( & V_25 , & V_26 ) ;
for ( V_27 = V_25 ; V_27 < V_26 ; V_27 += V_29 ) {
unsigned long V_6 = F_22 ( V_27 ) ;
struct V_5 * V_14 ;
F_11 ( V_6 , V_4 ) ;
F_3 ( V_6 , V_4 ) ;
V_14 = F_14 ( V_6 ) ;
if ( ! V_14 -> V_18 )
V_14 -> V_18 = F_16 ( V_4 ) |
V_30 ;
}
}
unsigned long T_4 F_23 ( int V_4 , unsigned long V_19 ,
unsigned long V_20 )
{
unsigned long V_27 ;
unsigned long V_31 = 0 ;
F_18 ( & V_19 , & V_20 ) ;
for ( V_27 = V_19 ; V_27 < V_20 ; V_27 += V_29 ) {
if ( V_4 != F_24 ( V_27 ) )
continue;
if ( F_25 ( V_27 ) )
V_31 += V_29 ;
}
return V_31 * sizeof( struct V_1 ) ;
}
static unsigned long F_26 ( struct V_1 * V_32 , unsigned long V_33 )
{
return ( unsigned long ) ( V_32 - ( F_27 ( V_33 ) ) ) ;
}
struct V_1 * F_28 ( unsigned long V_34 , unsigned long V_33 )
{
V_34 &= V_35 ;
return ( (struct V_1 * ) V_34 ) + F_27 ( V_33 ) ;
}
static int T_3 F_29 ( struct V_5 * V_14 ,
unsigned long V_33 , struct V_1 * V_32 ,
unsigned long * V_36 )
{
if ( ! F_30 ( V_14 ) )
return - V_37 ;
V_14 -> V_18 &= ~ V_35 ;
V_14 -> V_18 |= F_26 ( V_32 , V_33 ) |
V_38 ;
V_14 -> V_39 = V_36 ;
return 1 ;
}
unsigned long F_31 ( void )
{
unsigned long V_40 ;
V_40 = F_32 ( V_41 , 8 ) / 8 ;
V_40 = F_32 ( V_40 , sizeof( unsigned long ) ) ;
return V_40 ;
}
static unsigned long * F_33 ( void )
{
return F_34 ( F_31 () , V_10 ) ;
}
static unsigned long * T_4
F_35 ( struct V_42 * V_43 ,
unsigned long V_44 )
{
unsigned long V_45 , V_46 ;
unsigned long * V_47 ;
int V_4 ;
V_45 = F_36 ( V_43 ) & ( V_28 << V_23 ) ;
V_46 = V_45 + ( 1UL << V_48 ) ;
V_4 = F_24 ( V_45 >> V_23 ) ;
V_49:
V_47 = F_37 ( F_10 ( V_4 ) , V_44 ,
V_50 , V_45 , V_46 ) ;
if ( ! V_47 && V_46 ) {
V_46 = 0 ;
goto V_49;
}
return V_47 ;
}
static void T_4 F_38 ( int V_4 , unsigned long * V_51 )
{
unsigned long V_52 , V_53 ;
static unsigned long V_54 = V_55 ;
static unsigned long V_56 = V_55 ;
struct V_42 * V_43 = F_10 ( V_4 ) ;
int V_57 ;
V_52 = F_22 ( F_36 ( V_51 ) >> V_23 ) ;
V_53 = F_22 ( F_36 ( V_43 ) >> V_23 ) ;
if ( V_52 == V_53 )
return;
if ( V_54 == V_52 && V_56 == V_53 )
return;
V_54 = V_52 ;
V_56 = V_53 ;
V_57 = F_17 ( F_14 ( V_52 ) ) ;
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
F_35 ( struct V_42 * V_43 ,
unsigned long V_44 )
{
return F_40 ( V_43 , V_44 ) ;
}
static void T_4 F_38 ( int V_4 , unsigned long * V_51 )
{
}
static void T_4 F_41 ( unsigned long * * V_60 ,
unsigned long V_61 ,
unsigned long V_62 ,
unsigned long V_63 , int V_64 )
{
void * V_51 ;
unsigned long V_33 ;
int V_44 = F_31 () ;
V_51 = F_35 ( F_10 ( V_64 ) ,
V_44 * V_63 ) ;
if ( ! V_51 ) {
F_39 ( V_65 L_7 , V_66 ) ;
return;
}
for ( V_33 = V_61 ; V_33 < V_62 ; V_33 ++ ) {
if ( ! F_42 ( V_33 ) )
continue;
V_60 [ V_33 ] = V_51 ;
V_51 += V_44 ;
F_38 ( V_64 , V_60 [ V_33 ] ) ;
}
}
struct V_1 T_4 * F_43 ( unsigned long V_33 , int V_4 )
{
struct V_1 * V_67 ;
unsigned long V_44 ;
V_67 = F_44 ( V_4 , sizeof( struct V_1 ) * V_29 ) ;
if ( V_67 )
return V_67 ;
V_44 = F_45 ( sizeof( struct V_1 ) * V_29 ) ;
V_67 = F_46 ( F_10 ( V_4 ) , V_44 ,
V_68 , F_36 ( V_69 ) ) ;
return V_67 ;
}
void T_4 F_47 ( struct V_1 * * V_70 ,
unsigned long V_61 ,
unsigned long V_62 ,
unsigned long V_71 , int V_64 )
{
void * V_67 ;
unsigned long V_33 ;
unsigned long V_44 = sizeof( struct V_1 ) * V_29 ;
V_67 = F_44 ( V_64 , V_44 * V_71 ) ;
if ( V_67 ) {
for ( V_33 = V_61 ; V_33 < V_62 ; V_33 ++ ) {
if ( ! F_42 ( V_33 ) )
continue;
V_70 [ V_33 ] = V_67 ;
V_67 += V_44 ;
}
return;
}
V_44 = F_45 ( V_44 ) ;
V_67 = F_46 ( F_10 ( V_64 ) , V_44 * V_71 ,
V_68 , F_36 ( V_69 ) ) ;
if ( V_67 ) {
for ( V_33 = V_61 ; V_33 < V_62 ; V_33 ++ ) {
if ( ! F_42 ( V_33 ) )
continue;
V_70 [ V_33 ] = V_67 ;
V_67 += V_44 ;
}
return;
}
for ( V_33 = V_61 ; V_33 < V_62 ; V_33 ++ ) {
struct V_5 * V_14 ;
if ( ! F_42 ( V_33 ) )
continue;
V_70 [ V_33 ] = F_43 ( V_33 , V_64 ) ;
if ( V_70 [ V_33 ] )
continue;
V_14 = F_14 ( V_33 ) ;
F_39 ( V_72 L_8
L_9 , V_66 ) ;
V_14 -> V_18 = 0 ;
}
}
static void T_4 F_48 ( struct V_1 * * V_70 ,
unsigned long V_61 ,
unsigned long V_62 ,
unsigned long V_71 , int V_64 )
{
F_47 ( V_70 , V_61 , V_62 ,
V_71 , V_64 ) ;
}
static struct V_1 T_4 * F_49 ( unsigned long V_33 )
{
struct V_1 * V_67 ;
struct V_5 * V_14 = F_14 ( V_33 ) ;
int V_4 = F_17 ( V_14 ) ;
V_67 = F_43 ( V_33 , V_4 ) ;
if ( V_67 )
return V_67 ;
F_39 ( V_72 L_8
L_9 , V_66 ) ;
V_14 -> V_18 = 0 ;
return NULL ;
}
void T_4 F_50 ( void )
{
unsigned long V_33 ;
struct V_1 * V_67 ;
unsigned long * V_51 ;
unsigned long * * V_60 ;
int V_44 ;
int V_73 = 0 ;
unsigned long V_61 = 0 ;
unsigned long V_63 ;
#ifdef F_51
unsigned long V_71 ;
int V_74 ;
struct V_1 * * V_70 ;
#endif
F_52 ( ! F_53 ( sizeof( struct V_5 ) ) ) ;
F_54 () ;
V_44 = sizeof( unsigned long * ) * V_55 ;
V_60 = F_55 ( V_44 ) ;
if ( ! V_60 )
F_56 ( L_10 ) ;
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ ) {
struct V_5 * V_14 ;
if ( ! F_42 ( V_33 ) )
continue;
V_14 = F_14 ( V_33 ) ;
V_73 = F_17 ( V_14 ) ;
V_61 = V_33 ;
break;
}
V_63 = 1 ;
for ( V_33 = V_61 + 1 ; V_33 < V_55 ; V_33 ++ ) {
struct V_5 * V_14 ;
int V_64 ;
if ( ! F_42 ( V_33 ) )
continue;
V_14 = F_14 ( V_33 ) ;
V_64 = F_17 ( V_14 ) ;
if ( V_64 == V_73 ) {
V_63 ++ ;
continue;
}
F_41 ( V_60 , V_61 , V_33 ,
V_63 , V_73 ) ;
V_73 = V_64 ;
V_61 = V_33 ;
V_63 = 1 ;
}
F_41 ( V_60 , V_61 , V_55 ,
V_63 , V_73 ) ;
#ifdef F_51
V_74 = sizeof( struct V_1 * ) * V_55 ;
V_70 = F_55 ( V_74 ) ;
if ( ! V_70 )
F_56 ( L_11 ) ;
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ ) {
struct V_5 * V_14 ;
if ( ! F_42 ( V_33 ) )
continue;
V_14 = F_14 ( V_33 ) ;
V_73 = F_17 ( V_14 ) ;
V_61 = V_33 ;
break;
}
V_71 = 1 ;
for ( V_33 = V_61 + 1 ; V_33 < V_55 ; V_33 ++ ) {
struct V_5 * V_14 ;
int V_64 ;
if ( ! F_42 ( V_33 ) )
continue;
V_14 = F_14 ( V_33 ) ;
V_64 = F_17 ( V_14 ) ;
if ( V_64 == V_73 ) {
V_71 ++ ;
continue;
}
F_48 ( V_70 , V_61 , V_33 ,
V_71 , V_73 ) ;
V_73 = V_64 ;
V_61 = V_33 ;
V_71 = 1 ;
}
F_48 ( V_70 , V_61 , V_55 ,
V_71 , V_73 ) ;
#endif
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ ) {
if ( ! F_42 ( V_33 ) )
continue;
V_51 = V_60 [ V_33 ] ;
if ( ! V_51 )
continue;
#ifdef F_51
V_67 = V_70 [ V_33 ] ;
#else
V_67 = F_49 ( V_33 ) ;
#endif
if ( ! V_67 )
continue;
F_29 ( F_14 ( V_33 ) , V_33 , V_67 ,
V_51 ) ;
}
F_57 () ;
#ifdef F_51
F_58 ( F_36 ( V_70 ) , V_74 ) ;
#endif
F_58 ( F_36 ( V_60 ) , V_44 ) ;
}
static inline struct V_1 * F_59 ( unsigned long V_33 , int V_4 ,
unsigned long V_31 )
{
return F_43 ( V_33 , V_4 ) ;
}
static void F_60 ( struct V_1 * V_75 , unsigned long V_31 )
{
unsigned long V_25 = ( unsigned long ) V_75 ;
unsigned long V_26 = ( unsigned long ) ( V_75 + V_31 ) ;
F_61 ( V_25 , V_26 ) ;
}
static void F_62 ( struct V_1 * V_75 , unsigned long V_31 )
{
unsigned long V_25 = ( unsigned long ) V_75 ;
unsigned long V_26 = ( unsigned long ) ( V_75 + V_31 ) ;
F_61 ( V_25 , V_26 ) ;
}
static struct V_1 * F_63 ( unsigned long V_31 )
{
struct V_1 * V_1 , * V_76 ;
unsigned long V_77 = sizeof( struct V_1 ) * V_31 ;
V_1 = F_64 ( V_10 | V_78 , F_65 ( V_77 ) ) ;
if ( V_1 )
goto V_79;
V_76 = F_66 ( V_77 ) ;
if ( V_76 )
goto V_80;
return NULL ;
V_79:
V_76 = (struct V_1 * ) F_67 ( F_68 ( V_1 ) ) ;
V_80:
return V_76 ;
}
static inline struct V_1 * F_59 ( unsigned long V_33 , int V_4 ,
unsigned long V_31 )
{
return F_63 ( V_31 ) ;
}
static void F_60 ( struct V_1 * V_75 , unsigned long V_31 )
{
if ( F_69 ( V_75 ) )
F_70 ( V_75 ) ;
else
F_71 ( ( unsigned long ) V_75 ,
F_65 ( sizeof( struct V_1 ) * V_31 ) ) ;
}
static void F_62 ( struct V_1 * V_75 , unsigned long V_31 )
{
unsigned long V_81 , V_82 , V_83 ;
unsigned long V_84 ;
struct V_1 * V_1 = F_72 ( V_75 ) ;
for ( V_83 = 0 ; V_83 < V_31 ; V_83 ++ , V_1 ++ ) {
V_84 = ( unsigned long ) V_1 -> V_85 . V_86 ;
F_73 ( V_84 == V_87 ) ;
V_81 = F_22 ( F_68 ( V_1 ) ) ;
V_82 = V_1 -> V_88 ;
if ( V_81 != V_82 )
F_74 ( V_1 ) ;
}
}
int T_3 F_75 ( struct V_89 * V_89 , unsigned long V_19 ,
int V_31 )
{
unsigned long V_3 = F_22 ( V_19 ) ;
struct V_42 * V_43 = V_89 -> V_90 ;
struct V_5 * V_14 ;
struct V_1 * V_75 ;
unsigned long * V_51 ;
unsigned long V_91 ;
int V_76 ;
V_76 = F_11 ( V_3 , V_43 -> V_92 ) ;
if ( V_76 < 0 && V_76 != - V_12 )
return V_76 ;
V_75 = F_59 ( V_3 , V_43 -> V_92 , V_31 ) ;
if ( ! V_75 )
return - V_13 ;
V_51 = F_33 () ;
if ( ! V_51 ) {
F_60 ( V_75 , V_31 ) ;
return - V_13 ;
}
F_76 ( V_43 , & V_91 ) ;
V_14 = F_77 ( V_19 ) ;
if ( V_14 -> V_18 & V_30 ) {
V_76 = - V_12 ;
goto V_93;
}
memset ( V_75 , 0 , sizeof( struct V_1 ) * V_31 ) ;
V_14 -> V_18 |= V_30 ;
V_76 = F_29 ( V_14 , V_3 , V_75 , V_51 ) ;
V_93:
F_78 ( V_43 , & V_91 ) ;
if ( V_76 <= 0 ) {
F_79 ( V_51 ) ;
F_60 ( V_75 , V_31 ) ;
}
return V_76 ;
}
static void F_80 ( struct V_1 * V_75 , int V_31 )
{
int V_83 ;
if ( ! V_75 )
return;
for ( V_83 = 0 ; V_83 < V_29 ; V_83 ++ ) {
if ( F_81 ( & V_75 [ V_83 ] ) ) {
F_82 ( 1 , & V_94 ) ;
F_83 ( & V_75 [ V_83 ] ) ;
}
}
}
static inline void F_80 ( struct V_1 * V_75 , int V_31 )
{
}
static void F_84 ( struct V_1 * V_75 , unsigned long * V_51 )
{
struct V_1 * V_95 ;
unsigned long V_31 ;
if ( ! V_51 )
return;
V_95 = F_72 ( V_51 ) ;
if ( F_85 ( V_95 ) || F_86 ( V_95 ) ) {
F_79 ( V_51 ) ;
if ( V_75 )
F_60 ( V_75 , V_29 ) ;
return;
}
if ( V_75 ) {
V_31 = F_45 ( V_29 * sizeof( struct V_1 ) )
>> V_23 ;
F_62 ( V_75 , V_31 ) ;
}
}
void F_87 ( struct V_89 * V_89 , struct V_5 * V_14 )
{
struct V_1 * V_75 = NULL ;
unsigned long * V_51 = NULL , V_91 ;
struct V_42 * V_43 = V_89 -> V_90 ;
F_76 ( V_43 , & V_91 ) ;
if ( V_14 -> V_18 ) {
V_51 = V_14 -> V_39 ;
V_75 = F_28 ( V_14 -> V_18 ,
F_13 ( V_14 ) ) ;
V_14 -> V_18 = 0 ;
V_14 -> V_39 = NULL ;
}
F_78 ( V_43 , & V_91 ) ;
F_80 ( V_75 , V_29 ) ;
F_84 ( V_75 , V_51 ) ;
}
