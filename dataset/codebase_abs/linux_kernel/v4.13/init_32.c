static T_1 * T_2 F_1 ( T_3 * V_1 )
{
T_4 * V_2 ;
T_5 * V_3 ;
T_1 * V_4 ;
#ifdef F_2
if ( ! ( F_3 ( * V_1 ) & V_5 ) ) {
V_4 = ( T_1 * ) F_4 () ;
F_5 ( & V_6 , F_6 ( V_4 ) >> V_7 ) ;
F_7 ( V_1 , F_8 ( F_6 ( V_4 ) | V_5 ) ) ;
V_2 = F_9 ( V_1 , 0 ) ;
V_3 = F_10 ( V_2 , 0 ) ;
F_11 ( V_4 != F_12 ( V_3 , 0 ) ) ;
return V_4 ;
}
#endif
V_2 = F_9 ( V_1 , 0 ) ;
V_3 = F_10 ( V_2 , 0 ) ;
V_4 = F_12 ( V_3 , 0 ) ;
return V_4 ;
}
static T_6 * T_2 F_13 ( T_1 * V_8 )
{
if ( ! ( F_14 ( * V_8 ) & V_5 ) ) {
T_6 * V_9 = ( T_6 * ) F_4 () ;
F_15 ( & V_6 , F_6 ( V_9 ) >> V_7 ) ;
F_16 ( V_8 , F_17 ( F_6 ( V_9 ) | V_10 ) ) ;
F_11 ( V_9 != F_18 ( V_8 , 0 ) ) ;
}
return F_18 ( V_8 , 0 ) ;
}
T_1 * T_2 F_19 ( unsigned long V_11 )
{
int V_12 = F_20 ( V_11 ) ;
int V_13 = F_21 ( V_11 ) ;
return F_1 ( V_14 + V_12 ) + V_13 ;
}
T_6 * T_2 F_22 ( unsigned long V_11 )
{
int V_15 = F_23 ( V_11 ) ;
T_1 * V_8 ;
V_8 = F_19 ( V_11 ) ;
return F_13 ( V_8 ) + V_15 ;
}
static unsigned long T_2
F_24 ( unsigned long V_16 , unsigned long V_17 )
{
unsigned long V_18 = 0 ;
#ifdef F_25
int V_19 = F_26 ( V_20 ) >> V_21 ;
int V_22 = F_26 ( V_23 ) >> V_21 ;
int V_12 , V_13 ;
unsigned long V_11 ;
if ( V_19 == V_22 )
return 0 ;
V_11 = V_16 ;
V_12 = F_20 ( V_11 ) ;
V_13 = F_21 ( V_11 ) ;
for ( ; ( V_12 < V_24 ) && ( V_11 != V_17 ) ; V_12 ++ ) {
for (; ( V_13 < V_25 ) && ( V_11 != V_17 ) ;
V_13 ++ ) {
if ( ( V_11 >> V_21 ) >= V_19 &&
( V_11 >> V_21 ) <= V_22 )
V_18 ++ ;
V_11 += V_26 ;
}
V_13 = 0 ;
}
#endif
return V_18 ;
}
static T_6 * T_2 F_27 ( T_6 * V_27 , T_1 * V_8 ,
unsigned long V_11 , T_6 * V_28 ,
void * * V_29 )
{
#ifdef F_25
int V_19 = F_26 ( V_20 ) >> V_21 ;
int V_22 = F_26 ( V_23 ) >> V_21 ;
if ( V_19 != V_22
&& ( V_11 >> V_21 ) >= V_19
&& ( V_11 >> V_21 ) <= V_22 ) {
T_6 * V_30 ;
int V_31 ;
F_11 ( V_32 ) ;
V_30 = * V_29 ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ )
F_28 ( V_30 + V_31 , V_27 [ V_31 ] ) ;
* V_29 = ( void * ) ( ( ( unsigned long ) ( * V_29 ) ) + V_34 ) ;
F_15 ( & V_6 , F_6 ( V_30 ) >> V_7 ) ;
F_16 ( V_8 , F_17 ( F_6 ( V_30 ) | V_10 ) ) ;
F_11 ( V_30 != F_18 ( V_8 , 0 ) ) ;
F_29 () ;
F_30 ( F_6 ( V_27 ) >> V_7 ) ;
V_27 = V_30 ;
}
F_11 ( V_11 < F_26 ( V_23 - 1 )
&& V_11 > F_26 ( V_20 )
&& V_28 && V_28 + V_33 != V_27 ) ;
#endif
return V_27 ;
}
static void T_2
F_31 ( unsigned long V_16 , unsigned long V_17 , T_3 * V_35 )
{
int V_12 , V_13 ;
unsigned long V_11 ;
T_3 * V_1 ;
T_1 * V_8 ;
T_6 * V_27 = NULL ;
unsigned long V_18 = F_24 ( V_16 , V_17 ) ;
void * V_29 = NULL ;
if ( V_18 )
V_29 = F_32 ( V_18 ) ;
V_11 = V_16 ;
V_12 = F_20 ( V_11 ) ;
V_13 = F_21 ( V_11 ) ;
V_1 = V_35 + V_12 ;
for ( ; ( V_12 < V_24 ) && ( V_11 != V_17 ) ; V_1 ++ , V_12 ++ ) {
V_8 = F_1 ( V_1 ) ;
V_8 = V_8 + F_21 ( V_11 ) ;
for (; ( V_13 < V_25 ) && ( V_11 != V_17 ) ;
V_8 ++ , V_13 ++ ) {
V_27 = F_27 ( F_13 ( V_8 ) ,
V_8 , V_11 , V_27 , & V_29 ) ;
V_11 += V_26 ;
}
V_13 = 0 ;
}
}
static inline int F_33 ( unsigned long V_36 )
{
if ( V_36 >= ( unsigned long ) V_37 && V_36 <= ( unsigned long ) V_38 )
return 1 ;
return 0 ;
}
unsigned long T_2
F_34 ( unsigned long V_16 ,
unsigned long V_17 ,
unsigned long V_39 )
{
int V_40 = V_39 == ( 1 << V_41 ) ;
unsigned long V_42 = V_17 ;
unsigned long V_43 , V_44 ;
T_3 * V_35 = V_14 ;
int V_12 , V_13 , V_45 ;
unsigned long V_46 ;
T_3 * V_1 ;
T_1 * V_8 ;
T_6 * V_27 ;
unsigned V_47 , V_48 ;
int V_49 ;
V_43 = V_16 >> V_7 ;
V_44 = V_17 >> V_7 ;
V_49 = 1 ;
if ( ! F_35 ( V_50 ) )
V_40 = 0 ;
V_51:
V_47 = V_48 = 0 ;
V_46 = V_43 ;
V_12 = F_20 ( ( V_46 << V_7 ) + V_52 ) ;
V_1 = V_35 + V_12 ;
for (; V_12 < V_24 ; V_1 ++ , V_12 ++ ) {
V_8 = F_1 ( V_1 ) ;
if ( V_46 >= V_44 )
continue;
#ifdef F_2
V_13 = F_21 ( ( V_46 << V_7 ) + V_52 ) ;
V_8 += V_13 ;
#else
V_13 = 0 ;
#endif
for (; V_13 < V_25 && V_46 < V_44 ;
V_8 ++ , V_13 ++ ) {
unsigned int V_36 = V_46 * V_34 + V_52 ;
if ( V_40 ) {
unsigned int V_53 ;
T_7 V_54 = V_55 ;
T_7 V_56 =
F_36 ( V_57 |
V_58 ) ;
V_46 &= V_59 >> V_7 ;
V_53 = ( V_46 + V_33 - 1 ) * V_34 +
V_52 + V_34 - 1 ;
if ( F_33 ( V_36 ) ||
F_33 ( V_53 ) )
V_54 = V_60 ;
V_47 ++ ;
if ( V_49 == 1 )
F_16 ( V_8 , F_37 ( V_46 , V_56 ) ) ;
else
F_16 ( V_8 , F_37 ( V_46 , V_54 ) ) ;
V_46 += V_33 ;
continue;
}
V_27 = F_13 ( V_8 ) ;
V_45 = F_23 ( ( V_46 << V_7 ) + V_52 ) ;
V_27 += V_45 ;
for (; V_45 < V_33 && V_46 < V_44 ;
V_27 ++ , V_46 ++ , V_45 ++ , V_36 += V_34 ) {
T_7 V_54 = V_61 ;
T_7 V_56 = F_36 ( V_57 ) ;
if ( F_33 ( V_36 ) )
V_54 = V_62 ;
V_48 ++ ;
if ( V_49 == 1 ) {
F_28 ( V_27 , F_38 ( V_46 , V_56 ) ) ;
V_42 = ( V_46 << V_7 ) + V_34 ;
} else
F_28 ( V_27 , F_38 ( V_46 , V_54 ) ) ;
}
}
}
if ( V_49 == 1 ) {
F_39 ( V_41 , V_47 ) ;
F_39 ( V_63 , V_48 ) ;
F_29 () ;
V_49 = 2 ;
goto V_51;
}
return V_42 ;
}
static inline T_6 * F_40 ( unsigned long V_11 )
{
T_3 * V_1 = F_41 ( V_11 ) ;
T_4 * V_2 = F_9 ( V_1 , V_11 ) ;
T_5 * V_3 = F_10 ( V_2 , V_11 ) ;
T_1 * V_8 = F_12 ( V_3 , V_11 ) ;
return F_18 ( V_8 , V_11 ) ;
}
static void T_2 F_42 ( void )
{
unsigned long V_64 ;
V_64 = F_43 ( V_23 ) ;
V_65 = F_40 ( V_64 ) ;
}
static void T_2 F_44 ( T_3 * V_35 )
{
unsigned long V_11 ;
T_3 * V_1 ;
T_4 * V_2 ;
T_5 * V_3 ;
T_1 * V_8 ;
T_6 * V_27 ;
V_11 = V_66 ;
F_31 ( V_11 , V_11 + V_34 * V_67 , V_35 ) ;
V_1 = V_14 + F_20 ( V_11 ) ;
V_2 = F_9 ( V_1 , V_11 ) ;
V_3 = F_10 ( V_2 , V_11 ) ;
V_8 = F_12 ( V_3 , V_11 ) ;
V_27 = F_18 ( V_8 , V_11 ) ;
V_68 = V_27 ;
}
void T_2 F_45 ( int V_69 ,
unsigned long V_43 , unsigned long V_44 )
{
T_8 V_16 , V_17 ;
T_9 V_31 ;
F_46 (i, nid, MEMBLOCK_NONE, &start, &end, NULL) {
unsigned long V_46 = F_47 (unsigned long, PFN_UP(start),
start_pfn, end_pfn) ;
unsigned long V_70 = F_47 (unsigned long, PFN_DOWN(end),
start_pfn, end_pfn) ;
for ( ; V_46 < V_70 ; V_46 ++ )
if ( F_48 ( V_46 ) )
F_49 ( F_50 ( V_46 ) ) ;
}
}
static inline void F_44 ( T_3 * V_35 )
{
}
void T_2 F_51 ( void )
{
unsigned long V_46 , V_71 ;
T_3 * V_1 , * V_72 = V_14 ;
T_4 * V_2 ;
T_5 * V_3 ;
T_1 * V_8 ;
T_6 * V_27 ;
for ( V_46 = V_73 ; V_46 < 1 << ( 32 - V_7 ) ; V_46 ++ ) {
V_71 = V_52 + ( V_46 << V_7 ) ;
V_1 = V_72 + F_20 ( V_71 ) ;
if ( ! F_52 ( * V_1 ) )
break;
V_2 = F_9 ( V_1 , V_71 ) ;
V_3 = F_10 ( V_2 , V_71 ) ;
V_8 = F_12 ( V_3 , V_71 ) ;
if ( ! F_53 ( * V_8 ) )
break;
if ( F_54 ( * V_8 ) ) {
F_55 ( L_1 ,
V_46 , V_8 , F_6 ( V_8 ) ) ;
F_11 ( 1 ) ;
}
V_27 = F_18 ( V_8 , V_71 ) ;
if ( ! F_56 ( * V_27 ) )
break;
F_57 ( V_74 L_2 ,
V_46 , V_8 , F_6 ( V_8 ) , V_27 , F_6 ( V_27 ) ) ;
F_58 ( NULL , V_71 , V_27 ) ;
}
F_5 ( & V_6 , F_6 ( V_72 ) >> V_7 ) ;
F_59 () ;
}
void T_2 F_60 ( void )
{
T_3 * V_35 = V_14 ;
unsigned long V_11 , V_17 ;
V_11 = F_43 ( V_75 - 1 ) & V_59 ;
V_17 = ( V_76 + V_26 - 1 ) & V_59 ;
F_31 ( V_11 , V_17 , V_35 ) ;
F_61 () ;
}
static void T_2 F_62 ( void )
{
T_3 * V_35 = V_14 ;
F_44 ( V_35 ) ;
}
static int T_2 F_63 ( char * V_77 )
{
if ( ! V_77 )
return - V_78 ;
V_79 = F_64 ( V_77 , & V_77 ) >> V_7 ;
return 0 ;
}
static void T_2 F_65 ( void )
{
V_73 = V_80 ;
if ( V_79 == - 1 )
V_79 = 0 ;
#ifdef F_25
if ( V_79 >= V_80 ) {
F_57 (KERN_ERR MSG_HIGHMEM_TOO_BIG,
pages_to_mb(highmem_pages), pages_to_mb(max_pfn)) ;
V_79 = 0 ;
}
if ( V_79 ) {
if ( V_73 - V_79 < 64 * 1024 * 1024 / V_34 ) {
F_57 (KERN_ERR MSG_LOWMEM_TOO_SMALL,
pages_to_mb(highmem_pages)) ;
V_79 = 0 ;
}
V_73 -= V_79 ;
}
#else
if ( V_79 )
F_57 ( V_81 L_3 ) ;
#endif
}
static void T_2 F_66 ( void )
{
V_73 = V_82 ;
if ( V_79 == - 1 )
V_79 = V_80 - V_82 ;
if ( V_79 + V_82 < V_80 )
V_80 = V_82 + V_79 ;
if ( V_79 + V_82 > V_80 ) {
F_57 (KERN_WARNING MSG_HIGHMEM_TOO_SMALL,
pages_to_mb(max_pfn - MAXMEM_PFN),
pages_to_mb(highmem_pages)) ;
V_79 = 0 ;
}
#ifndef F_25
F_57 ( V_83 L_4 , V_84 >> 20 ) ;
if ( V_80 > V_85 )
F_57 ( V_83 L_5 ) ;
else
F_57 ( V_83 L_6 ) ;
V_80 = V_82 ;
#else
#ifndef F_67
if ( V_80 > V_85 ) {
V_80 = V_85 ;
F_57 (KERN_WARNING MSG_HIGHMEM_TRIMMED) ;
}
#endif
#endif
}
void T_2 F_68 ( void )
{
if ( V_80 <= V_82 )
F_65 () ;
else
F_66 () ;
}
void T_2 F_69 ( void )
{
#ifdef F_25
V_86 = V_87 = V_80 ;
if ( V_80 > V_73 )
V_86 = V_73 ;
F_57 ( V_88 L_7 ,
F_70 ( V_87 - V_86 ) ) ;
V_89 = ( void * ) F_71 ( V_86 * V_34 - 1 ) + 1 ;
#else
V_89 = ( void * ) F_71 ( V_73 * V_34 - 1 ) + 1 ;
#endif
F_72 ( 0 , ( T_8 ) V_90 , & V_91 . V_92 , 0 ) ;
F_73 ( 0 ) ;
#ifdef F_74
V_93 = F_75 ( F_25 ) ? V_87 : V_73 ;
#endif
V_94 = true ;
F_57 ( V_88 L_8 ,
F_70 ( V_73 ) ) ;
F_76 () ;
}
void T_2 F_76 ( void )
{
F_57 ( V_95 L_9 ,
V_96 << V_7 ) ;
F_57 ( V_95 L_10 , V_73 << V_7 ) ;
}
void T_2 F_59 ( void )
{
F_62 () ;
F_29 () ;
F_42 () ;
F_77 () ;
F_73 ( V_97 ) ;
F_78 () ;
F_79 () ;
}
static void T_2 F_80 ( void )
{
char V_98 = 0 ;
F_57 ( V_95 L_11 ) ;
F_81 ( V_99 , F_82 ( V_100 ) , V_101 ) ;
if ( F_83 ( ( char * ) F_26 ( V_99 ) , & V_98 , 1 ) ) {
F_84 ( V_99 ) ;
F_57 ( V_102 L_12 ) ;
return;
}
F_57 ( V_102 L_13 ) ;
F_85 ( L_14 ) ;
}
void T_2 F_86 ( void )
{
F_87 () ;
#ifdef F_74
F_11 ( ! V_103 ) ;
#endif
F_88 () ;
F_89 () ;
V_32 = 1 ;
F_90 ( NULL ) ;
F_57 ( V_95 L_15
L_16
#ifdef F_25
L_17
#endif
L_18
L_19
L_20
L_21
L_22 ,
V_104 , V_76 ,
( V_76 - V_104 ) >> 10 ,
#ifdef F_25
V_66 , V_66 + V_67 * V_34 ,
( V_67 * V_34 ) >> 10 ,
#endif
V_105 , V_106 ,
( V_106 - V_105 ) >> 20 ,
( unsigned long ) F_71 ( 0 ) , ( unsigned long ) V_89 ,
( ( unsigned long ) V_89 - ( unsigned long ) F_71 ( 0 ) ) >> 20 ,
( unsigned long ) & V_107 , ( unsigned long ) & V_38 ,
( ( unsigned long ) & V_38 -
( unsigned long ) & V_107 ) >> 10 ,
( unsigned long ) & V_108 , ( unsigned long ) & V_109 ,
( ( unsigned long ) & V_109 - ( unsigned long ) & V_108 ) >> 10 ,
( unsigned long ) & V_37 , ( unsigned long ) & V_108 ,
( ( unsigned long ) & V_108 - ( unsigned long ) & V_37 ) >> 10 ) ;
#define F_91 (-PAGE_SIZE)
#ifdef F_25
F_92 ( V_66 + V_67 * V_34 > V_104 ) ;
F_92 ( V_106 > V_66 ) ;
#endif
#define V_89 (-128UL << 20)
F_92 ( V_105 >= V_106 ) ;
#undef V_89
#undef F_91
#ifdef F_25
F_11 ( V_66 + V_67 * V_34 > V_104 ) ;
F_11 ( V_106 > V_66 ) ;
#endif
F_11 ( V_105 >= V_106 ) ;
F_11 ( ( unsigned long ) V_89 > V_105 ) ;
F_80 () ;
}
int F_93 ( int V_69 , T_9 V_16 , T_9 V_110 , bool V_111 )
{
unsigned long V_43 = V_16 >> V_7 ;
unsigned long V_112 = V_110 >> V_7 ;
return F_94 ( V_69 , V_43 , V_112 , V_111 ) ;
}
int F_95 ( T_9 V_16 , T_9 V_110 )
{
unsigned long V_43 = V_16 >> V_7 ;
unsigned long V_112 = V_110 >> V_7 ;
struct V_113 * V_113 ;
V_113 = F_96 ( F_50 ( V_43 ) ) ;
return F_97 ( V_113 , V_43 , V_112 ) ;
}
void F_98 ( void )
{
unsigned long V_16 = F_99 ( V_37 ) ;
unsigned long V_110 = F_99 ( V_108 ) - V_16 ;
if ( ! V_114 )
return;
F_100 ( L_23 ,
V_16 , V_16 + V_110 ) ;
F_101 ( F_102 ( V_16 ) , V_110 >> V_7 ) ;
}
void F_103 ( void )
{
unsigned long V_16 = F_99 ( V_37 ) ;
unsigned long V_110 = F_99 ( V_108 ) - V_16 ;
if ( ! V_114 )
return;
F_100 ( L_24 ,
V_16 , V_16 + V_110 ) ;
F_104 ( F_102 ( V_16 ) , V_110 >> V_7 ) ;
}
static void F_105 ( void )
{
unsigned long V_16 = F_99 ( V_108 ) ;
unsigned long V_110 = ( ( ( unsigned long ) V_38 + V_115 ) & V_116 ) - V_16 ;
if ( V_117 & V_118 )
F_57 ( V_95 L_25 , V_110 >> 10 ) ;
F_106 ( F_102 ( V_16 ) , V_110 >> V_7 ) ;
}
void F_107 ( void )
{
unsigned long V_16 = F_99 ( V_37 ) ;
unsigned long V_110 = F_99 ( V_108 ) - V_16 ;
F_104 ( F_102 ( V_16 ) , V_110 >> V_7 ) ;
F_57 ( V_95 L_26 ,
V_110 >> 10 ) ;
V_114 = 1 ;
#ifdef F_108
F_57 ( V_95 L_27 ,
V_16 , V_16 + V_110 ) ;
F_101 ( F_102 ( V_16 ) , V_110 >> V_7 ) ;
F_57 ( V_95 L_28 ) ;
F_104 ( F_102 ( V_16 ) , V_110 >> V_7 ) ;
#endif
V_16 += V_110 ;
V_110 = ( unsigned long ) V_119 - V_16 ;
F_104 ( F_102 ( V_16 ) , V_110 >> V_7 ) ;
F_57 ( V_95 L_29 ,
V_110 >> 10 ) ;
#ifdef F_108
F_57 ( V_95 L_30 , V_16 , V_16 + V_110 ) ;
F_101 ( F_102 ( V_16 ) , V_110 >> V_7 ) ;
F_57 ( V_95 L_28 ) ;
F_104 ( F_102 ( V_16 ) , V_110 >> V_7 ) ;
#endif
F_105 () ;
if ( V_117 & V_118 )
F_109 () ;
}
