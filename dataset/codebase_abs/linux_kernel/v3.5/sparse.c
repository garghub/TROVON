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
} else
V_6 = F_9 ( F_10 ( V_4 ) , V_7 ) ;
if ( V_6 )
memset ( V_6 , 0 , V_7 ) ;
return V_6 ;
}
static int T_3 F_11 ( unsigned long V_3 , int V_4 )
{
static F_12 ( V_11 ) ;
unsigned long V_12 = F_13 ( V_3 ) ;
struct V_5 * V_6 ;
int V_13 = 0 ;
if ( V_5 [ V_12 ] )
return - V_14 ;
V_6 = F_4 ( V_4 ) ;
if ( ! V_6 )
return - V_15 ;
F_14 ( & V_11 ) ;
if ( V_5 [ V_12 ] ) {
V_13 = - V_14 ;
goto V_16;
}
V_5 [ V_12 ] = V_6 ;
V_16:
F_15 ( & V_11 ) ;
return V_13 ;
}
static inline int F_11 ( unsigned long V_3 , int V_4 )
{
return 0 ;
}
int F_16 ( struct V_5 * V_17 )
{
unsigned long V_18 ;
struct V_5 * V_12 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
V_12 = F_17 ( V_18 * V_8 ) ;
if ( ! V_12 )
continue;
if ( ( V_17 >= V_12 ) && ( V_17 < ( V_12 + V_8 ) ) )
break;
}
return ( V_18 * V_8 ) + ( V_17 - V_12 ) ;
}
static inline unsigned long F_18 ( int V_4 )
{
return ( V_4 << V_20 ) ;
}
static inline int F_19 ( struct V_5 * V_6 )
{
return ( V_6 -> V_21 >> V_20 ) ;
}
void T_3 F_20 ( unsigned long * V_22 ,
unsigned long * V_23 )
{
unsigned long V_24 = 1UL << ( V_25 - V_26 ) ;
if ( * V_22 > V_24 ) {
F_21 ( V_27 , L_1 ,
L_2 ,
* V_22 , * V_23 , V_24 ) ;
F_22 ( 1 ) ;
* V_22 = V_24 ;
* V_23 = V_24 ;
} else if ( * V_23 > V_24 ) {
F_21 ( V_27 , L_1 ,
L_3 ,
* V_22 , * V_23 , V_24 ) ;
F_22 ( 1 ) ;
* V_23 = V_24 ;
}
}
void T_4 F_23 ( int V_4 , unsigned long V_28 , unsigned long V_29 )
{
unsigned long V_30 ;
V_28 &= V_31 ;
F_20 ( & V_28 , & V_29 ) ;
for ( V_30 = V_28 ; V_30 < V_29 ; V_30 += V_32 ) {
unsigned long V_6 = F_24 ( V_30 ) ;
struct V_5 * V_17 ;
F_11 ( V_6 , V_4 ) ;
F_3 ( V_6 , V_4 ) ;
V_17 = F_17 ( V_6 ) ;
if ( ! V_17 -> V_21 )
V_17 -> V_21 = F_18 ( V_4 ) |
V_33 ;
}
}
unsigned long T_4 F_25 ( int V_4 , unsigned long V_22 ,
unsigned long V_23 )
{
unsigned long V_30 ;
unsigned long V_34 = 0 ;
F_20 ( & V_22 , & V_23 ) ;
for ( V_30 = V_22 ; V_30 < V_23 ; V_30 += V_32 ) {
if ( V_4 != F_26 ( V_30 ) )
continue;
if ( F_27 ( V_30 ) )
V_34 += V_32 ;
}
return V_34 * sizeof( struct V_1 ) ;
}
static unsigned long F_28 ( struct V_1 * V_35 , unsigned long V_36 )
{
return ( unsigned long ) ( V_35 - ( F_29 ( V_36 ) ) ) ;
}
struct V_1 * F_30 ( unsigned long V_37 , unsigned long V_36 )
{
V_37 &= V_38 ;
return ( (struct V_1 * ) V_37 ) + F_29 ( V_36 ) ;
}
static int T_3 F_31 ( struct V_5 * V_17 ,
unsigned long V_36 , struct V_1 * V_35 ,
unsigned long * V_39 )
{
if ( ! F_32 ( V_17 ) )
return - V_40 ;
V_17 -> V_21 &= ~ V_38 ;
V_17 -> V_21 |= F_28 ( V_35 , V_36 ) |
V_41 ;
V_17 -> V_42 = V_39 ;
return 1 ;
}
unsigned long F_33 ( void )
{
unsigned long V_43 ;
V_43 = F_34 ( V_44 , 8 ) / 8 ;
V_43 = F_34 ( V_43 , sizeof( unsigned long ) ) ;
return V_43 ;
}
static unsigned long * F_35 ( void )
{
return F_8 ( F_33 () , V_10 ) ;
}
static unsigned long * T_4
F_36 ( struct V_45 * V_46 ,
unsigned long V_47 )
{
unsigned long V_48 , V_49 ;
unsigned long * V_50 ;
int V_4 ;
V_48 = F_37 ( V_46 ) & ( V_31 << V_26 ) ;
V_49 = V_48 + ( 1UL << V_51 ) ;
V_4 = F_26 ( V_48 >> V_26 ) ;
V_52:
V_50 = F_38 ( F_10 ( V_4 ) , V_47 ,
V_53 , V_48 , V_49 ) ;
if ( ! V_50 && V_49 ) {
V_49 = 0 ;
goto V_52;
}
return V_50 ;
}
static void T_4 F_39 ( int V_4 , unsigned long * V_54 )
{
unsigned long V_55 , V_56 ;
static unsigned long V_57 = V_58 ;
static unsigned long V_59 = V_58 ;
struct V_45 * V_46 = F_10 ( V_4 ) ;
int V_60 ;
V_55 = F_24 ( F_37 ( V_54 ) >> V_26 ) ;
V_56 = F_24 ( F_37 ( V_46 ) >> V_26 ) ;
if ( V_55 == V_56 )
return;
if ( V_57 == V_55 && V_59 == V_56 )
return;
V_57 = V_55 ;
V_59 = V_56 ;
V_60 = F_19 ( F_17 ( V_55 ) ) ;
if ( V_60 != V_4 ) {
F_40 ( V_61
L_4 ,
V_4 , V_55 ) ;
return;
}
F_40 ( V_61 L_5 , V_55 ,
V_56 , V_4 ) ;
F_40 ( V_62
L_6 ) ;
}
static unsigned long * T_4
F_36 ( struct V_45 * V_46 ,
unsigned long V_47 )
{
return F_41 ( V_46 , V_47 ) ;
}
static void T_4 F_39 ( int V_4 , unsigned long * V_54 )
{
}
static void T_4 F_42 ( unsigned long * * V_63 ,
unsigned long V_64 ,
unsigned long V_65 ,
unsigned long V_66 , int V_67 )
{
void * V_54 ;
unsigned long V_36 ;
int V_47 = F_33 () ;
V_54 = F_36 ( F_10 ( V_67 ) ,
V_47 * V_66 ) ;
if ( ! V_54 ) {
F_40 ( V_68 L_7 , V_69 ) ;
return;
}
for ( V_36 = V_64 ; V_36 < V_65 ; V_36 ++ ) {
if ( ! F_43 ( V_36 ) )
continue;
V_63 [ V_36 ] = V_54 ;
V_54 += V_47 ;
F_39 ( V_67 , V_63 [ V_36 ] ) ;
}
}
struct V_1 T_4 * F_44 ( unsigned long V_36 , int V_4 )
{
struct V_1 * V_70 ;
unsigned long V_47 ;
V_70 = F_45 ( V_4 , sizeof( struct V_1 ) * V_32 ) ;
if ( V_70 )
return V_70 ;
V_47 = F_46 ( sizeof( struct V_1 ) * V_32 ) ;
V_70 = F_47 ( F_10 ( V_4 ) , V_47 ,
V_71 , F_37 ( V_72 ) ) ;
return V_70 ;
}
void T_4 F_48 ( struct V_1 * * V_73 ,
unsigned long V_64 ,
unsigned long V_65 ,
unsigned long V_74 , int V_67 )
{
void * V_70 ;
unsigned long V_36 ;
unsigned long V_47 = sizeof( struct V_1 ) * V_32 ;
V_70 = F_45 ( V_67 , V_47 * V_74 ) ;
if ( V_70 ) {
for ( V_36 = V_64 ; V_36 < V_65 ; V_36 ++ ) {
if ( ! F_43 ( V_36 ) )
continue;
V_73 [ V_36 ] = V_70 ;
V_70 += V_47 ;
}
return;
}
V_47 = F_46 ( V_47 ) ;
V_70 = F_47 ( F_10 ( V_67 ) , V_47 * V_74 ,
V_71 , F_37 ( V_72 ) ) ;
if ( V_70 ) {
for ( V_36 = V_64 ; V_36 < V_65 ; V_36 ++ ) {
if ( ! F_43 ( V_36 ) )
continue;
V_73 [ V_36 ] = V_70 ;
V_70 += V_47 ;
}
return;
}
for ( V_36 = V_64 ; V_36 < V_65 ; V_36 ++ ) {
struct V_5 * V_17 ;
if ( ! F_43 ( V_36 ) )
continue;
V_73 [ V_36 ] = F_44 ( V_36 , V_67 ) ;
if ( V_73 [ V_36 ] )
continue;
V_17 = F_17 ( V_36 ) ;
F_40 ( V_75 L_8
L_9 , V_69 ) ;
V_17 -> V_21 = 0 ;
}
}
static void T_4 F_49 ( struct V_1 * * V_73 ,
unsigned long V_64 ,
unsigned long V_65 ,
unsigned long V_74 , int V_67 )
{
F_48 ( V_73 , V_64 , V_65 ,
V_74 , V_67 ) ;
}
static struct V_1 T_4 * F_50 ( unsigned long V_36 )
{
struct V_1 * V_70 ;
struct V_5 * V_17 = F_17 ( V_36 ) ;
int V_4 = F_19 ( V_17 ) ;
V_70 = F_44 ( V_36 , V_4 ) ;
if ( V_70 )
return V_70 ;
F_40 ( V_75 L_8
L_9 , V_69 ) ;
V_17 -> V_21 = 0 ;
return NULL ;
}
void T_4 F_51 ( void )
{
unsigned long V_36 ;
struct V_1 * V_70 ;
unsigned long * V_54 ;
unsigned long * * V_63 ;
int V_47 ;
int V_76 = 0 ;
unsigned long V_64 = 0 ;
unsigned long V_66 ;
#ifdef F_52
unsigned long V_74 ;
int V_77 ;
struct V_1 * * V_73 ;
#endif
V_47 = sizeof( unsigned long * ) * V_58 ;
V_63 = F_53 ( V_47 ) ;
if ( ! V_63 )
F_54 ( L_10 ) ;
for ( V_36 = 0 ; V_36 < V_58 ; V_36 ++ ) {
struct V_5 * V_17 ;
if ( ! F_43 ( V_36 ) )
continue;
V_17 = F_17 ( V_36 ) ;
V_76 = F_19 ( V_17 ) ;
V_64 = V_36 ;
break;
}
V_66 = 1 ;
for ( V_36 = V_64 + 1 ; V_36 < V_58 ; V_36 ++ ) {
struct V_5 * V_17 ;
int V_67 ;
if ( ! F_43 ( V_36 ) )
continue;
V_17 = F_17 ( V_36 ) ;
V_67 = F_19 ( V_17 ) ;
if ( V_67 == V_76 ) {
V_66 ++ ;
continue;
}
F_42 ( V_63 , V_64 , V_36 ,
V_66 , V_76 ) ;
V_76 = V_67 ;
V_64 = V_36 ;
V_66 = 1 ;
}
F_42 ( V_63 , V_64 , V_58 ,
V_66 , V_76 ) ;
#ifdef F_52
V_77 = sizeof( struct V_1 * ) * V_58 ;
V_73 = F_53 ( V_77 ) ;
if ( ! V_73 )
F_54 ( L_11 ) ;
for ( V_36 = 0 ; V_36 < V_58 ; V_36 ++ ) {
struct V_5 * V_17 ;
if ( ! F_43 ( V_36 ) )
continue;
V_17 = F_17 ( V_36 ) ;
V_76 = F_19 ( V_17 ) ;
V_64 = V_36 ;
break;
}
V_74 = 1 ;
for ( V_36 = V_64 + 1 ; V_36 < V_58 ; V_36 ++ ) {
struct V_5 * V_17 ;
int V_67 ;
if ( ! F_43 ( V_36 ) )
continue;
V_17 = F_17 ( V_36 ) ;
V_67 = F_19 ( V_17 ) ;
if ( V_67 == V_76 ) {
V_74 ++ ;
continue;
}
F_49 ( V_73 , V_64 , V_36 ,
V_74 , V_76 ) ;
V_76 = V_67 ;
V_64 = V_36 ;
V_74 = 1 ;
}
F_49 ( V_73 , V_64 , V_58 ,
V_74 , V_76 ) ;
#endif
for ( V_36 = 0 ; V_36 < V_58 ; V_36 ++ ) {
if ( ! F_43 ( V_36 ) )
continue;
V_54 = V_63 [ V_36 ] ;
if ( ! V_54 )
continue;
#ifdef F_52
V_70 = V_73 [ V_36 ] ;
#else
V_70 = F_50 ( V_36 ) ;
#endif
if ( ! V_70 )
continue;
F_31 ( F_17 ( V_36 ) , V_36 , V_70 ,
V_54 ) ;
}
F_55 () ;
#ifdef F_52
F_56 ( F_37 ( V_73 ) , V_77 ) ;
#endif
F_56 ( F_37 ( V_63 ) , V_47 ) ;
}
static inline struct V_1 * F_57 ( unsigned long V_36 , int V_4 ,
unsigned long V_34 )
{
return F_44 ( V_36 , V_4 ) ;
}
static void F_58 ( struct V_1 * V_78 , unsigned long V_34 )
{
return;
}
static void F_59 ( struct V_1 * V_1 , unsigned long V_34 )
{
}
static struct V_1 * F_60 ( unsigned long V_34 )
{
struct V_1 * V_1 , * V_13 ;
unsigned long V_79 = sizeof( struct V_1 ) * V_34 ;
V_1 = F_61 ( V_10 | V_80 , F_62 ( V_79 ) ) ;
if ( V_1 )
goto V_81;
V_13 = F_63 ( V_79 ) ;
if ( V_13 )
goto V_82;
return NULL ;
V_81:
V_13 = (struct V_1 * ) F_64 ( F_65 ( V_1 ) ) ;
V_82:
memset ( V_13 , 0 , V_79 ) ;
return V_13 ;
}
static inline struct V_1 * F_57 ( unsigned long V_36 , int V_4 ,
unsigned long V_34 )
{
return F_60 ( V_34 ) ;
}
static void F_58 ( struct V_1 * V_78 , unsigned long V_34 )
{
if ( F_66 ( V_78 ) )
F_67 ( V_78 ) ;
else
F_68 ( ( unsigned long ) V_78 ,
F_62 ( sizeof( struct V_1 ) * V_34 ) ) ;
}
static void F_59 ( struct V_1 * V_1 , unsigned long V_34 )
{
unsigned long V_83 , V_84 , V_85 ;
unsigned long V_86 ;
for ( V_85 = 0 ; V_85 < V_34 ; V_85 ++ , V_1 ++ ) {
V_86 = ( unsigned long ) V_1 -> V_87 . V_88 ;
F_69 ( V_86 == V_89 ) ;
V_83 = F_24 ( F_65 ( V_1 ) ) ;
V_84 = V_1 -> V_90 ;
if ( V_83 != V_84 )
F_70 ( V_1 ) ;
}
}
static void F_71 ( struct V_1 * V_78 , unsigned long * V_54 )
{
struct V_1 * V_91 ;
unsigned long V_34 ;
if ( ! V_54 )
return;
V_91 = F_72 ( V_54 ) ;
if ( F_73 ( V_91 ) ) {
F_74 ( V_54 ) ;
if ( V_78 )
F_58 ( V_78 , V_32 ) ;
return;
}
if ( V_78 ) {
struct V_1 * V_92 ;
V_92 = F_72 ( V_78 ) ;
V_34 = F_46 ( V_32 * sizeof( struct V_1 ) )
>> V_26 ;
F_59 ( V_92 , V_34 ) ;
}
}
int T_3 F_75 ( struct V_93 * V_93 , unsigned long V_22 ,
int V_34 )
{
unsigned long V_3 = F_24 ( V_22 ) ;
struct V_45 * V_46 = V_93 -> V_94 ;
struct V_5 * V_17 ;
struct V_1 * V_78 ;
unsigned long * V_54 ;
unsigned long V_95 ;
int V_13 ;
V_13 = F_11 ( V_3 , V_46 -> V_96 ) ;
if ( V_13 < 0 && V_13 != - V_14 )
return V_13 ;
V_78 = F_57 ( V_3 , V_46 -> V_96 , V_34 ) ;
if ( ! V_78 )
return - V_15 ;
V_54 = F_35 () ;
if ( ! V_54 ) {
F_58 ( V_78 , V_34 ) ;
return - V_15 ;
}
F_76 ( V_46 , & V_95 ) ;
V_17 = F_77 ( V_22 ) ;
if ( V_17 -> V_21 & V_33 ) {
V_13 = - V_14 ;
goto V_16;
}
V_17 -> V_21 |= V_33 ;
V_13 = F_31 ( V_17 , V_3 , V_78 , V_54 ) ;
V_16:
F_78 ( V_46 , & V_95 ) ;
if ( V_13 <= 0 ) {
F_74 ( V_54 ) ;
F_58 ( V_78 , V_34 ) ;
}
return V_13 ;
}
void F_79 ( struct V_93 * V_93 , struct V_5 * V_17 )
{
struct V_1 * V_78 = NULL ;
unsigned long * V_54 = NULL ;
if ( V_17 -> V_21 ) {
V_54 = V_17 -> V_42 ;
V_78 = F_30 ( V_17 -> V_21 ,
F_16 ( V_17 ) ) ;
V_17 -> V_21 = 0 ;
V_17 -> V_42 = NULL ;
}
F_71 ( V_78 , V_54 ) ;
}
