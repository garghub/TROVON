int F_1 ( struct V_1 * V_1 )
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
unsigned long V_3 ;
V_3 = F_24 ( F_37 ( V_46 ) >> V_26 ) ;
return F_38 ( F_33 () * V_47 , V_3 ) ;
}
static void T_4 F_39 ( int V_4 , unsigned long * V_48 )
{
unsigned long V_49 , V_50 ;
static unsigned long V_51 = V_52 ;
static unsigned long V_53 = V_52 ;
struct V_45 * V_46 = F_10 ( V_4 ) ;
int V_54 ;
V_49 = F_24 ( F_37 ( V_48 ) >> V_26 ) ;
V_50 = F_24 ( F_37 ( V_46 ) >> V_26 ) ;
if ( V_49 == V_50 )
return;
if ( V_51 == V_49 && V_53 == V_50 )
return;
V_51 = V_49 ;
V_53 = V_50 ;
V_54 = F_19 ( F_17 ( V_49 ) ) ;
if ( V_54 != V_4 ) {
F_40 ( V_55
L_4 ,
V_4 , V_49 ) ;
return;
}
F_40 ( V_55 L_5 , V_49 ,
V_50 , V_4 ) ;
F_40 ( V_56
L_6 ) ;
}
static unsigned long * T_4
F_36 ( struct V_45 * V_46 ,
unsigned long V_47 )
{
return NULL ;
}
static void T_4 F_39 ( int V_4 , unsigned long * V_48 )
{
}
static void T_4 F_41 ( unsigned long * * V_57 ,
unsigned long V_58 ,
unsigned long V_59 ,
unsigned long V_60 , int V_61 )
{
void * V_48 ;
unsigned long V_36 ;
int V_62 = F_33 () ;
V_48 = F_36 ( F_10 ( V_61 ) ,
V_60 ) ;
if ( V_48 ) {
for ( V_36 = V_58 ; V_36 < V_59 ; V_36 ++ ) {
if ( ! F_42 ( V_36 ) )
continue;
V_57 [ V_36 ] = V_48 ;
V_48 += V_62 ;
}
return;
}
V_48 = F_9 ( F_10 ( V_61 ) , V_62 * V_60 ) ;
if ( V_48 ) {
for ( V_36 = V_58 ; V_36 < V_59 ; V_36 ++ ) {
if ( ! F_42 ( V_36 ) )
continue;
V_57 [ V_36 ] = V_48 ;
V_48 += V_62 ;
F_39 ( V_61 , V_57 [ V_36 ] ) ;
}
return;
}
F_40 ( V_63 L_7 , V_64 ) ;
}
struct V_1 T_4 * F_43 ( unsigned long V_36 , int V_4 )
{
struct V_1 * V_65 ;
unsigned long V_62 ;
V_65 = F_44 ( V_4 , sizeof( struct V_1 ) * V_32 ) ;
if ( V_65 )
return V_65 ;
V_62 = F_45 ( sizeof( struct V_1 ) * V_32 ) ;
V_65 = F_46 ( F_10 ( V_4 ) , V_62 ,
V_66 , F_37 ( V_67 ) ) ;
return V_65 ;
}
void T_4 F_47 ( struct V_1 * * V_68 ,
unsigned long V_58 ,
unsigned long V_59 ,
unsigned long V_69 , int V_61 )
{
void * V_65 ;
unsigned long V_36 ;
unsigned long V_62 = sizeof( struct V_1 ) * V_32 ;
V_65 = F_44 ( V_61 , V_62 * V_69 ) ;
if ( V_65 ) {
for ( V_36 = V_58 ; V_36 < V_59 ; V_36 ++ ) {
if ( ! F_42 ( V_36 ) )
continue;
V_68 [ V_36 ] = V_65 ;
V_65 += V_62 ;
}
return;
}
V_62 = F_45 ( V_62 ) ;
V_65 = F_46 ( F_10 ( V_61 ) , V_62 * V_69 ,
V_66 , F_37 ( V_67 ) ) ;
if ( V_65 ) {
for ( V_36 = V_58 ; V_36 < V_59 ; V_36 ++ ) {
if ( ! F_42 ( V_36 ) )
continue;
V_68 [ V_36 ] = V_65 ;
V_65 += V_62 ;
}
return;
}
for ( V_36 = V_58 ; V_36 < V_59 ; V_36 ++ ) {
struct V_5 * V_17 ;
if ( ! F_42 ( V_36 ) )
continue;
V_68 [ V_36 ] = F_43 ( V_36 , V_61 ) ;
if ( V_68 [ V_36 ] )
continue;
V_17 = F_17 ( V_36 ) ;
F_40 ( V_70 L_8
L_9 , V_64 ) ;
V_17 -> V_21 = 0 ;
}
}
static void T_4 F_48 ( struct V_1 * * V_68 ,
unsigned long V_58 ,
unsigned long V_59 ,
unsigned long V_69 , int V_61 )
{
F_47 ( V_68 , V_58 , V_59 ,
V_69 , V_61 ) ;
}
static struct V_1 T_4 * F_49 ( unsigned long V_36 )
{
struct V_1 * V_65 ;
struct V_5 * V_17 = F_17 ( V_36 ) ;
int V_4 = F_19 ( V_17 ) ;
V_65 = F_43 ( V_36 , V_4 ) ;
if ( V_65 )
return V_65 ;
F_40 ( V_70 L_8
L_9 , V_64 ) ;
V_17 -> V_21 = 0 ;
return NULL ;
}
void T_4 F_50 ( void )
{
unsigned long V_36 ;
struct V_1 * V_65 ;
unsigned long * V_48 ;
unsigned long * * V_57 ;
int V_62 ;
int V_71 = 0 ;
unsigned long V_58 = 0 ;
unsigned long V_60 ;
#ifdef F_51
unsigned long V_69 ;
int V_72 ;
struct V_1 * * V_68 ;
#endif
V_62 = sizeof( unsigned long * ) * V_52 ;
V_57 = F_52 ( V_62 ) ;
if ( ! V_57 )
F_53 ( L_10 ) ;
for ( V_36 = 0 ; V_36 < V_52 ; V_36 ++ ) {
struct V_5 * V_17 ;
if ( ! F_42 ( V_36 ) )
continue;
V_17 = F_17 ( V_36 ) ;
V_71 = F_19 ( V_17 ) ;
V_58 = V_36 ;
break;
}
V_60 = 1 ;
for ( V_36 = V_58 + 1 ; V_36 < V_52 ; V_36 ++ ) {
struct V_5 * V_17 ;
int V_61 ;
if ( ! F_42 ( V_36 ) )
continue;
V_17 = F_17 ( V_36 ) ;
V_61 = F_19 ( V_17 ) ;
if ( V_61 == V_71 ) {
V_60 ++ ;
continue;
}
F_41 ( V_57 , V_58 , V_36 ,
V_60 , V_71 ) ;
V_71 = V_61 ;
V_58 = V_36 ;
V_60 = 1 ;
}
F_41 ( V_57 , V_58 , V_52 ,
V_60 , V_71 ) ;
#ifdef F_51
V_72 = sizeof( struct V_1 * ) * V_52 ;
V_68 = F_52 ( V_72 ) ;
if ( ! V_68 )
F_53 ( L_11 ) ;
for ( V_36 = 0 ; V_36 < V_52 ; V_36 ++ ) {
struct V_5 * V_17 ;
if ( ! F_42 ( V_36 ) )
continue;
V_17 = F_17 ( V_36 ) ;
V_71 = F_19 ( V_17 ) ;
V_58 = V_36 ;
break;
}
V_69 = 1 ;
for ( V_36 = V_58 + 1 ; V_36 < V_52 ; V_36 ++ ) {
struct V_5 * V_17 ;
int V_61 ;
if ( ! F_42 ( V_36 ) )
continue;
V_17 = F_17 ( V_36 ) ;
V_61 = F_19 ( V_17 ) ;
if ( V_61 == V_71 ) {
V_69 ++ ;
continue;
}
F_48 ( V_68 , V_58 , V_36 ,
V_69 , V_71 ) ;
V_71 = V_61 ;
V_58 = V_36 ;
V_69 = 1 ;
}
F_48 ( V_68 , V_58 , V_52 ,
V_69 , V_71 ) ;
#endif
for ( V_36 = 0 ; V_36 < V_52 ; V_36 ++ ) {
if ( ! F_42 ( V_36 ) )
continue;
V_48 = V_57 [ V_36 ] ;
if ( ! V_48 )
continue;
#ifdef F_51
V_65 = V_68 [ V_36 ] ;
#else
V_65 = F_49 ( V_36 ) ;
#endif
if ( ! V_65 )
continue;
F_31 ( F_17 ( V_36 ) , V_36 , V_65 ,
V_48 ) ;
}
F_54 () ;
#ifdef F_51
F_55 ( F_37 ( V_68 ) , V_72 ) ;
#endif
F_55 ( F_37 ( V_57 ) , V_62 ) ;
}
static inline struct V_1 * F_56 ( unsigned long V_36 , int V_4 ,
unsigned long V_34 )
{
return F_43 ( V_36 , V_4 ) ;
}
static void F_57 ( struct V_1 * V_73 , unsigned long V_34 )
{
return;
}
static void F_58 ( struct V_1 * V_1 , unsigned long V_34 )
{
}
static struct V_1 * F_59 ( unsigned long V_34 )
{
struct V_1 * V_1 , * V_13 ;
unsigned long V_74 = sizeof( struct V_1 ) * V_34 ;
V_1 = F_60 ( V_10 | V_75 , F_61 ( V_74 ) ) ;
if ( V_1 )
goto V_76;
V_13 = F_62 ( V_74 ) ;
if ( V_13 )
goto V_77;
return NULL ;
V_76:
V_13 = (struct V_1 * ) F_63 ( F_64 ( V_1 ) ) ;
V_77:
memset ( V_13 , 0 , V_74 ) ;
return V_13 ;
}
static inline struct V_1 * F_56 ( unsigned long V_36 , int V_4 ,
unsigned long V_34 )
{
return F_59 ( V_34 ) ;
}
static void F_57 ( struct V_1 * V_73 , unsigned long V_34 )
{
if ( F_65 ( V_73 ) )
F_66 ( V_73 ) ;
else
F_67 ( ( unsigned long ) V_73 ,
F_61 ( sizeof( struct V_1 ) * V_34 ) ) ;
}
static void F_58 ( struct V_1 * V_1 , unsigned long V_34 )
{
unsigned long V_78 , V_79 , V_80 ;
unsigned long V_81 ;
for ( V_80 = 0 ; V_80 < V_34 ; V_80 ++ , V_1 ++ ) {
V_81 = ( unsigned long ) V_1 -> V_82 . V_83 ;
F_68 ( V_81 == V_84 ) ;
V_78 = F_24 ( F_64 ( V_1 ) ) ;
V_79 = V_1 -> V_85 ;
if ( V_78 != V_79 )
F_69 ( V_1 ) ;
}
}
static void F_70 ( struct V_1 * V_73 , unsigned long * V_48 )
{
struct V_1 * V_86 ;
unsigned long V_34 ;
if ( ! V_48 )
return;
V_86 = F_71 ( V_48 ) ;
if ( F_72 ( V_86 ) ) {
F_73 ( V_48 ) ;
if ( V_73 )
F_57 ( V_73 , V_32 ) ;
return;
}
if ( V_73 ) {
struct V_1 * V_87 ;
V_87 = F_71 ( V_73 ) ;
V_34 = F_45 ( V_32 * sizeof( struct V_1 ) )
>> V_26 ;
F_58 ( V_87 , V_34 ) ;
}
}
int T_3 F_74 ( struct V_88 * V_88 , unsigned long V_22 ,
int V_34 )
{
unsigned long V_3 = F_24 ( V_22 ) ;
struct V_45 * V_46 = V_88 -> V_89 ;
struct V_5 * V_17 ;
struct V_1 * V_73 ;
unsigned long * V_48 ;
unsigned long V_90 ;
int V_13 ;
V_13 = F_11 ( V_3 , V_46 -> V_91 ) ;
if ( V_13 < 0 && V_13 != - V_14 )
return V_13 ;
V_73 = F_56 ( V_3 , V_46 -> V_91 , V_34 ) ;
if ( ! V_73 )
return - V_15 ;
V_48 = F_35 () ;
if ( ! V_48 ) {
F_57 ( V_73 , V_34 ) ;
return - V_15 ;
}
F_75 ( V_46 , & V_90 ) ;
V_17 = F_76 ( V_22 ) ;
if ( V_17 -> V_21 & V_33 ) {
V_13 = - V_14 ;
goto V_16;
}
V_17 -> V_21 |= V_33 ;
V_13 = F_31 ( V_17 , V_3 , V_73 , V_48 ) ;
V_16:
F_77 ( V_46 , & V_90 ) ;
if ( V_13 <= 0 ) {
F_73 ( V_48 ) ;
F_57 ( V_73 , V_34 ) ;
}
return V_13 ;
}
void F_78 ( struct V_88 * V_88 , struct V_5 * V_17 )
{
struct V_1 * V_73 = NULL ;
unsigned long * V_48 = NULL ;
if ( V_17 -> V_21 ) {
V_48 = V_17 -> V_42 ;
V_73 = F_30 ( V_17 -> V_21 ,
F_16 ( V_17 ) ) ;
V_17 -> V_21 = 0 ;
V_17 -> V_42 = NULL ;
}
F_70 ( V_73 , V_48 ) ;
}
