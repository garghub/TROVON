static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = F_3 ( & V_4 -> V_8 ) ;
while ( V_7 ) {
void * V_4 = V_7 ;
V_7 = F_4 ( V_7 ) ;
F_5 ( V_4 , 1 ) ;
}
}
static void F_6 ( T_1 * V_9 , unsigned long V_10 , unsigned long V_11 )
{
T_2 * V_12 ;
V_12 = F_7 ( V_9 , V_10 ) ;
do {
T_2 V_13 = F_8 ( & V_14 , V_10 , V_12 ) ;
F_9 ( ! F_10 ( V_13 ) && ! F_11 ( V_13 ) ) ;
} while ( V_12 ++ , V_10 += V_15 , V_10 != V_11 );
}
static void F_12 ( T_3 * V_16 , unsigned long V_10 , unsigned long V_11 )
{
T_1 * V_9 ;
unsigned long V_17 ;
V_9 = F_13 ( V_16 , V_10 ) ;
do {
V_17 = F_14 ( V_10 , V_11 ) ;
if ( F_15 ( V_9 ) )
continue;
if ( F_16 ( V_9 ) )
continue;
F_6 ( V_9 , V_10 , V_17 ) ;
} while ( V_9 ++ , V_10 = V_17 , V_10 != V_11 );
}
static void F_17 ( T_4 * V_18 , unsigned long V_10 , unsigned long V_11 )
{
T_3 * V_16 ;
unsigned long V_17 ;
V_16 = F_18 ( V_18 , V_10 ) ;
do {
V_17 = F_19 ( V_10 , V_11 ) ;
if ( F_20 ( V_16 ) )
continue;
if ( F_21 ( V_16 ) )
continue;
F_12 ( V_16 , V_10 , V_17 ) ;
} while ( V_16 ++ , V_10 = V_17 , V_10 != V_11 );
}
static void F_22 ( unsigned long V_10 , unsigned long V_11 )
{
T_4 * V_18 ;
unsigned long V_17 ;
F_23 ( V_10 >= V_11 ) ;
V_18 = F_24 ( V_10 ) ;
do {
V_17 = F_25 ( V_10 , V_11 ) ;
if ( F_26 ( V_18 ) )
continue;
F_17 ( V_18 , V_10 , V_17 ) ;
} while ( V_18 ++ , V_10 = V_17 , V_10 != V_11 );
}
static int F_27 ( T_1 * V_9 , unsigned long V_10 ,
unsigned long V_11 , T_5 V_19 , struct V_20 * * V_21 , int * V_22 )
{
T_2 * V_12 ;
V_12 = F_28 ( V_9 , V_10 ) ;
if ( ! V_12 )
return - V_23 ;
do {
struct V_20 * V_20 = V_21 [ * V_22 ] ;
if ( F_9 ( ! F_10 ( * V_12 ) ) )
return - V_24 ;
if ( F_9 ( ! V_20 ) )
return - V_23 ;
F_29 ( & V_14 , V_10 , V_12 , F_30 ( V_20 , V_19 ) ) ;
( * V_22 ) ++ ;
} while ( V_12 ++ , V_10 += V_15 , V_10 != V_11 );
return 0 ;
}
static int F_31 ( T_3 * V_16 , unsigned long V_10 ,
unsigned long V_11 , T_5 V_19 , struct V_20 * * V_21 , int * V_22 )
{
T_1 * V_9 ;
unsigned long V_17 ;
V_9 = F_32 ( & V_14 , V_16 , V_10 ) ;
if ( ! V_9 )
return - V_23 ;
do {
V_17 = F_14 ( V_10 , V_11 ) ;
if ( F_27 ( V_9 , V_10 , V_17 , V_19 , V_21 , V_22 ) )
return - V_23 ;
} while ( V_9 ++ , V_10 = V_17 , V_10 != V_11 );
return 0 ;
}
static int F_33 ( T_4 * V_18 , unsigned long V_10 ,
unsigned long V_11 , T_5 V_19 , struct V_20 * * V_21 , int * V_22 )
{
T_3 * V_16 ;
unsigned long V_17 ;
V_16 = F_34 ( & V_14 , V_18 , V_10 ) ;
if ( ! V_16 )
return - V_23 ;
do {
V_17 = F_19 ( V_10 , V_11 ) ;
if ( F_31 ( V_16 , V_10 , V_17 , V_19 , V_21 , V_22 ) )
return - V_23 ;
} while ( V_16 ++ , V_10 = V_17 , V_10 != V_11 );
return 0 ;
}
static int F_35 ( unsigned long V_25 , unsigned long V_11 ,
T_5 V_19 , struct V_20 * * V_21 )
{
T_4 * V_18 ;
unsigned long V_17 ;
unsigned long V_10 = V_25 ;
int V_26 = 0 ;
int V_22 = 0 ;
F_23 ( V_10 >= V_11 ) ;
V_18 = F_24 ( V_10 ) ;
do {
V_17 = F_25 ( V_10 , V_11 ) ;
V_26 = F_33 ( V_18 , V_10 , V_17 , V_19 , V_21 , & V_22 ) ;
if ( V_26 )
return V_26 ;
} while ( V_18 ++ , V_10 = V_17 , V_10 != V_11 );
return V_22 ;
}
static int F_36 ( unsigned long V_25 , unsigned long V_11 ,
T_5 V_19 , struct V_20 * * V_21 )
{
int V_27 ;
V_27 = F_35 ( V_25 , V_11 , V_19 , V_21 ) ;
F_37 ( V_25 , V_11 ) ;
return V_27 ;
}
int F_38 ( const void * V_28 )
{
#if F_39 ( V_29 ) && F_39 ( V_30 )
unsigned long V_10 = ( unsigned long ) V_28 ;
if ( V_10 >= V_30 && V_10 < V_31 )
return 1 ;
#endif
return F_40 ( V_28 ) ;
}
struct V_20 * F_41 ( const void * V_32 )
{
unsigned long V_10 = ( unsigned long ) V_32 ;
struct V_20 * V_20 = NULL ;
T_4 * V_18 = F_24 ( V_10 ) ;
F_42 ( ! F_38 ( V_32 ) ) ;
if ( ! F_43 ( * V_18 ) ) {
T_3 * V_16 = F_18 ( V_18 , V_10 ) ;
if ( ! F_44 ( * V_16 ) ) {
T_1 * V_9 = F_13 ( V_16 , V_10 ) ;
if ( ! F_45 ( * V_9 ) ) {
T_2 * V_33 , V_12 ;
V_33 = F_46 ( V_9 , V_10 ) ;
V_12 = * V_33 ;
if ( F_11 ( V_12 ) )
V_20 = F_47 ( V_12 ) ;
F_48 ( V_33 ) ;
}
}
}
return V_20 ;
}
unsigned long F_49 ( const void * V_32 )
{
return F_50 ( F_41 ( V_32 ) ) ;
}
static struct V_34 * F_51 ( unsigned long V_10 )
{
struct V_35 * V_36 = V_37 . V_35 ;
while ( V_36 ) {
struct V_34 * V_38 ;
V_38 = F_52 ( V_36 , struct V_34 , V_35 ) ;
if ( V_10 < V_38 -> va_start )
V_36 = V_36 -> V_39 ;
else if ( V_10 >= V_38 -> va_end )
V_36 = V_36 -> V_40 ;
else
return V_38 ;
}
return NULL ;
}
static void F_53 ( struct V_34 * V_38 )
{
struct V_35 * * V_4 = & V_37 . V_35 ;
struct V_35 * V_41 = NULL ;
struct V_35 * V_42 ;
while ( * V_4 ) {
struct V_34 * V_43 ;
V_41 = * V_4 ;
V_43 = F_52 ( V_41 , struct V_34 , V_35 ) ;
if ( V_38 -> va_start < V_43 -> va_end )
V_4 = & ( * V_4 ) -> V_39 ;
else if ( V_38 -> va_end > V_43 -> va_start )
V_4 = & ( * V_4 ) -> V_40 ;
else
F_54 () ;
}
F_55 ( & V_38 -> V_35 , V_41 , V_4 ) ;
F_56 ( & V_38 -> V_35 , & V_37 ) ;
V_42 = F_57 ( & V_38 -> V_35 ) ;
if ( V_42 ) {
struct V_34 * V_44 ;
V_44 = F_52 ( V_42 , struct V_34 , V_35 ) ;
F_58 ( & V_38 -> V_8 , & V_44 -> V_8 ) ;
} else
F_58 ( & V_38 -> V_8 , & V_45 ) ;
}
static struct V_34 * F_59 ( unsigned long V_46 ,
unsigned long V_47 ,
unsigned long V_48 , unsigned long V_49 ,
int V_50 , T_6 V_51 )
{
struct V_34 * V_38 ;
struct V_35 * V_36 ;
unsigned long V_10 ;
int V_52 = 0 ;
struct V_34 * V_53 ;
F_23 ( ! V_46 ) ;
F_23 ( V_46 & ~ V_54 ) ;
F_23 ( ! F_60 ( V_47 ) ) ;
V_38 = F_61 ( sizeof( struct V_34 ) ,
V_51 & V_55 , V_50 ) ;
if ( F_62 ( ! V_38 ) )
return F_63 ( - V_23 ) ;
F_64 ( & V_38 -> V_35 , V_56 , V_51 & V_55 ) ;
V_57:
F_65 ( & V_58 ) ;
if ( ! V_59 ||
V_46 < V_60 ||
V_48 < V_61 ||
V_47 < V_62 ) {
V_63:
V_60 = 0 ;
V_59 = NULL ;
}
V_61 = V_48 ;
V_62 = V_47 ;
if ( V_59 ) {
V_53 = F_52 ( V_59 , struct V_34 , V_35 ) ;
V_10 = F_66 ( V_53 -> va_end , V_47 ) ;
if ( V_10 < V_48 )
goto V_63;
if ( V_10 + V_46 < V_10 )
goto V_64;
} else {
V_10 = F_66 ( V_48 , V_47 ) ;
if ( V_10 + V_46 < V_10 )
goto V_64;
V_36 = V_37 . V_35 ;
V_53 = NULL ;
while ( V_36 ) {
struct V_34 * V_42 ;
V_42 = F_52 ( V_36 , struct V_34 , V_35 ) ;
if ( V_42 -> va_end >= V_10 ) {
V_53 = V_42 ;
if ( V_42 -> va_start <= V_10 )
break;
V_36 = V_36 -> V_39 ;
} else
V_36 = V_36 -> V_40 ;
}
if ( ! V_53 )
goto V_65;
}
while ( V_10 + V_46 > V_53 -> va_start && V_10 + V_46 <= V_49 ) {
if ( V_10 + V_60 < V_53 -> va_start )
V_60 = V_53 -> va_start - V_10 ;
V_10 = F_66 ( V_53 -> va_end , V_47 ) ;
if ( V_10 + V_46 < V_10 )
goto V_64;
if ( F_67 ( & V_53 -> V_8 , & V_45 ) )
goto V_65;
V_53 = F_68 ( V_53 -> V_8 . V_17 ,
struct V_34 , V_8 ) ;
}
V_65:
if ( V_10 + V_46 > V_49 )
goto V_64;
V_38 -> va_start = V_10 ;
V_38 -> va_end = V_10 + V_46 ;
V_38 -> V_66 = 0 ;
F_53 ( V_38 ) ;
V_59 = & V_38 -> V_35 ;
F_69 ( & V_58 ) ;
F_23 ( V_38 -> va_start & ( V_47 - 1 ) ) ;
F_23 ( V_38 -> va_start < V_48 ) ;
F_23 ( V_38 -> va_end > V_49 ) ;
return V_38 ;
V_64:
F_69 ( & V_58 ) ;
if ( ! V_52 ) {
F_70 () ;
V_52 = 1 ;
goto V_57;
}
if ( F_71 () )
F_72 ( L_1
L_2 , V_46 ) ;
F_73 ( V_38 ) ;
return F_63 ( - V_24 ) ;
}
static void F_74 ( struct V_34 * V_38 )
{
F_23 ( F_75 ( & V_38 -> V_35 ) ) ;
if ( V_59 ) {
if ( V_38 -> va_end < V_61 ) {
V_59 = NULL ;
} else {
struct V_34 * V_67 ;
V_67 = F_52 ( V_59 , struct V_34 , V_35 ) ;
if ( V_38 -> va_start <= V_67 -> va_start ) {
V_59 = F_57 ( & V_38 -> V_35 ) ;
}
}
}
F_76 ( & V_38 -> V_35 , & V_37 ) ;
F_77 ( & V_38 -> V_35 ) ;
F_78 ( & V_38 -> V_8 ) ;
if ( V_38 -> va_end > V_68 && V_38 -> va_end <= V_69 )
V_70 = F_79 ( V_70 , V_38 -> va_end ) ;
F_80 ( V_38 , V_71 ) ;
}
static void F_81 ( struct V_34 * V_38 )
{
F_65 ( & V_58 ) ;
F_74 ( V_38 ) ;
F_69 ( & V_58 ) ;
}
static void F_82 ( struct V_34 * V_38 )
{
F_22 ( V_38 -> va_start , V_38 -> va_end ) ;
}
static void F_83 ( unsigned long V_25 , unsigned long V_11 )
{
#ifdef F_84
F_22 ( V_25 , V_11 ) ;
F_85 ( V_25 , V_11 ) ;
#endif
}
static unsigned long F_86 ( void )
{
unsigned int log ;
log = F_87 ( F_88 () ) ;
return log * ( 32UL * 1024 * 1024 / V_15 ) ;
}
void F_89 ( void )
{
F_90 ( & V_72 , F_86 () + 1 ) ;
}
static void F_91 ( unsigned long * V_25 , unsigned long * V_11 ,
int V_73 , int V_74 )
{
static F_92 ( V_75 ) ;
F_93 ( V_76 ) ;
struct V_34 * V_38 ;
struct V_34 * V_77 ;
int V_22 = 0 ;
if ( ! V_73 && ! V_74 ) {
if ( ! F_94 ( & V_75 ) )
return;
} else
F_65 ( & V_75 ) ;
if ( V_73 )
F_95 () ;
F_96 () ;
F_97 (va, &vmap_area_list, list) {
if ( V_38 -> V_66 & V_78 ) {
if ( V_38 -> va_start < * V_25 )
* V_25 = V_38 -> va_start ;
if ( V_38 -> va_end > * V_11 )
* V_11 = V_38 -> va_end ;
V_22 += ( V_38 -> va_end - V_38 -> va_start ) >> V_79 ;
F_98 ( & V_38 -> V_80 , & V_76 ) ;
V_38 -> V_66 |= V_81 ;
V_38 -> V_66 &= ~ V_78 ;
}
}
F_99 () ;
if ( V_22 )
F_100 ( V_22 , & V_72 ) ;
if ( V_22 || V_74 )
F_85 ( * V_25 , * V_11 ) ;
if ( V_22 ) {
F_65 ( & V_58 ) ;
F_101 (va, n_va, &valist, purge_list)
F_74 ( V_38 ) ;
F_69 ( & V_58 ) ;
}
F_69 ( & V_75 ) ;
}
static void F_102 ( void )
{
unsigned long V_25 = V_82 , V_11 = 0 ;
F_91 ( & V_25 , & V_11 , 0 , 0 ) ;
}
static void F_70 ( void )
{
unsigned long V_25 = V_82 , V_11 = 0 ;
F_91 ( & V_25 , & V_11 , 1 , 0 ) ;
}
static void F_103 ( struct V_34 * V_38 )
{
V_38 -> V_66 |= V_78 ;
F_104 ( ( V_38 -> va_end - V_38 -> va_start ) >> V_79 , & V_72 ) ;
if ( F_62 ( F_105 ( & V_72 ) > F_86 () ) )
F_102 () ;
}
static void F_106 ( struct V_34 * V_38 )
{
F_82 ( V_38 ) ;
F_103 ( V_38 ) ;
}
static void F_107 ( struct V_34 * V_38 )
{
F_108 ( V_38 -> va_start , V_38 -> va_end ) ;
F_106 ( V_38 ) ;
}
static struct V_34 * F_109 ( unsigned long V_10 )
{
struct V_34 * V_38 ;
F_65 ( & V_58 ) ;
V_38 = F_51 ( V_10 ) ;
F_69 ( & V_58 ) ;
return V_38 ;
}
static void F_110 ( unsigned long V_10 )
{
struct V_34 * V_38 ;
V_38 = F_109 ( V_10 ) ;
F_23 ( ! V_38 ) ;
F_107 ( V_38 ) ;
}
static unsigned long F_111 ( unsigned long V_10 )
{
V_10 -= V_68 & ~ ( V_83 - 1 ) ;
V_10 /= V_83 ;
return V_10 ;
}
static void * F_112 ( unsigned long va_start , unsigned long V_84 )
{
unsigned long V_10 ;
V_10 = va_start + ( V_84 << V_79 ) ;
F_23 ( F_111 ( V_10 ) != F_111 ( va_start ) ) ;
return ( void * ) V_10 ;
}
static void * F_113 ( unsigned int V_85 , T_6 V_51 )
{
struct V_86 * V_87 ;
struct V_88 * V_89 ;
struct V_34 * V_38 ;
unsigned long V_90 ;
int V_50 , V_26 ;
void * V_91 ;
V_50 = F_114 () ;
V_89 = F_61 ( sizeof( struct V_88 ) ,
V_51 & V_55 , V_50 ) ;
if ( F_62 ( ! V_89 ) )
return F_63 ( - V_23 ) ;
V_38 = F_59 ( V_83 , V_83 ,
V_68 , V_69 ,
V_50 , V_51 ) ;
if ( F_115 ( V_38 ) ) {
F_73 ( V_89 ) ;
return F_116 ( V_38 ) ;
}
V_26 = F_117 ( V_51 ) ;
if ( F_62 ( V_26 ) ) {
F_73 ( V_89 ) ;
F_81 ( V_38 ) ;
return F_63 ( V_26 ) ;
}
V_91 = F_112 ( V_38 -> va_start , 0 ) ;
F_118 ( & V_89 -> V_92 ) ;
V_89 -> V_38 = V_38 ;
F_23 ( V_93 <= ( 1UL << V_85 ) ) ;
V_89 -> free = V_93 - ( 1UL << V_85 ) ;
V_89 -> V_94 = 0 ;
V_89 -> V_95 = V_93 ;
V_89 -> V_96 = 0 ;
F_119 ( & V_89 -> V_97 ) ;
V_90 = F_111 ( V_38 -> va_start ) ;
F_65 ( & V_98 ) ;
V_26 = F_120 ( & V_99 , V_90 , V_89 ) ;
F_69 ( & V_98 ) ;
F_23 ( V_26 ) ;
F_121 () ;
V_87 = & F_122 ( V_86 ) ;
F_65 ( & V_87 -> V_92 ) ;
F_123 ( & V_89 -> V_97 , & V_87 -> free ) ;
F_69 ( & V_87 -> V_92 ) ;
F_124 ( V_86 ) ;
return V_91 ;
}
static void F_125 ( struct V_88 * V_89 )
{
struct V_88 * V_42 ;
unsigned long V_90 ;
V_90 = F_111 ( V_89 -> V_38 -> va_start ) ;
F_65 ( & V_98 ) ;
V_42 = F_126 ( & V_99 , V_90 ) ;
F_69 ( & V_98 ) ;
F_23 ( V_42 != V_89 ) ;
F_103 ( V_89 -> V_38 ) ;
F_80 ( V_89 , V_71 ) ;
}
static void F_127 ( int V_100 )
{
F_93 ( V_101 ) ;
struct V_88 * V_89 ;
struct V_88 * V_102 ;
struct V_86 * V_87 = & F_128 ( V_86 , V_100 ) ;
F_96 () ;
F_97 (vb, &vbq->free, free_list) {
if ( ! ( V_89 -> free + V_89 -> V_94 == V_93 && V_89 -> V_94 != V_93 ) )
continue;
F_65 ( & V_89 -> V_92 ) ;
if ( V_89 -> free + V_89 -> V_94 == V_93 && V_89 -> V_94 != V_93 ) {
V_89 -> free = 0 ;
V_89 -> V_94 = V_93 ;
V_89 -> V_95 = 0 ;
V_89 -> V_96 = V_93 ;
F_65 ( & V_87 -> V_92 ) ;
F_78 ( & V_89 -> V_97 ) ;
F_69 ( & V_87 -> V_92 ) ;
F_69 ( & V_89 -> V_92 ) ;
F_98 ( & V_89 -> V_101 , & V_101 ) ;
} else
F_69 ( & V_89 -> V_92 ) ;
}
F_99 () ;
F_101 (vb, n_vb, &purge, purge) {
F_129 ( & V_89 -> V_101 ) ;
F_125 ( V_89 ) ;
}
}
static void F_95 ( void )
{
int V_100 ;
F_130 (cpu)
F_127 ( V_100 ) ;
}
static void * F_131 ( unsigned long V_46 , T_6 V_51 )
{
struct V_86 * V_87 ;
struct V_88 * V_89 ;
void * V_91 = NULL ;
unsigned int V_85 ;
F_23 ( V_46 & ~ V_54 ) ;
F_23 ( V_46 > V_15 * V_103 ) ;
if ( F_9 ( V_46 == 0 ) ) {
return NULL ;
}
V_85 = F_132 ( V_46 ) ;
F_96 () ;
V_87 = & F_122 ( V_86 ) ;
F_97 (vb, &vbq->free, free_list) {
unsigned long V_84 ;
F_65 ( & V_89 -> V_92 ) ;
if ( V_89 -> free < ( 1UL << V_85 ) ) {
F_69 ( & V_89 -> V_92 ) ;
continue;
}
V_84 = V_93 - V_89 -> free ;
V_91 = F_112 ( V_89 -> V_38 -> va_start , V_84 ) ;
V_89 -> free -= 1UL << V_85 ;
if ( V_89 -> free == 0 ) {
F_65 ( & V_87 -> V_92 ) ;
F_78 ( & V_89 -> V_97 ) ;
F_69 ( & V_87 -> V_92 ) ;
}
F_69 ( & V_89 -> V_92 ) ;
break;
}
F_124 ( V_86 ) ;
F_99 () ;
if ( ! V_91 )
V_91 = F_113 ( V_85 , V_51 ) ;
return V_91 ;
}
static void F_133 ( const void * V_10 , unsigned long V_46 )
{
unsigned long V_104 ;
unsigned long V_90 ;
unsigned int V_85 ;
struct V_88 * V_89 ;
F_23 ( V_46 & ~ V_54 ) ;
F_23 ( V_46 > V_15 * V_103 ) ;
F_108 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
V_85 = F_132 ( V_46 ) ;
V_104 = ( unsigned long ) V_10 & ( V_83 - 1 ) ;
V_104 >>= V_79 ;
V_90 = F_111 ( ( unsigned long ) V_10 ) ;
F_96 () ;
V_89 = F_134 ( & V_99 , V_90 ) ;
F_99 () ;
F_23 ( ! V_89 ) ;
F_22 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
F_65 ( & V_89 -> V_92 ) ;
V_89 -> V_95 = F_135 ( V_89 -> V_95 , V_104 ) ;
V_89 -> V_96 = F_79 ( V_89 -> V_96 , V_104 + ( 1UL << V_85 ) ) ;
V_89 -> V_94 += 1UL << V_85 ;
if ( V_89 -> V_94 == V_93 ) {
F_23 ( V_89 -> free ) ;
F_69 ( & V_89 -> V_92 ) ;
F_125 ( V_89 ) ;
} else
F_69 ( & V_89 -> V_92 ) ;
}
void F_136 ( void )
{
unsigned long V_25 = V_82 , V_11 = 0 ;
int V_100 ;
int V_105 = 0 ;
if ( F_62 ( ! V_106 ) )
return;
F_130 (cpu) {
struct V_86 * V_87 = & F_128 ( V_86 , V_100 ) ;
struct V_88 * V_89 ;
F_96 () ;
F_97 (vb, &vbq->free, free_list) {
F_65 ( & V_89 -> V_92 ) ;
if ( V_89 -> V_94 ) {
unsigned long va_start = V_89 -> V_38 -> va_start ;
unsigned long V_107 , V_108 ;
V_107 = va_start + ( V_89 -> V_95 << V_79 ) ;
V_108 = va_start + ( V_89 -> V_96 << V_79 ) ;
V_25 = F_135 ( V_107 , V_25 ) ;
V_11 = F_79 ( V_108 , V_11 ) ;
V_105 = 1 ;
}
F_69 ( & V_89 -> V_92 ) ;
}
F_99 () ;
}
F_91 ( & V_25 , & V_11 , 1 , V_105 ) ;
}
void F_137 ( const void * V_109 , unsigned int V_110 )
{
unsigned long V_46 = V_110 << V_79 ;
unsigned long V_10 = ( unsigned long ) V_109 ;
F_23 ( ! V_10 ) ;
F_23 ( V_10 < V_68 ) ;
F_23 ( V_10 > V_69 ) ;
F_23 ( V_10 & ( V_15 - 1 ) ) ;
F_138 ( V_109 , V_46 ) ;
F_83 ( V_10 , V_10 + V_46 ) ;
if ( F_139 ( V_110 <= V_103 ) )
F_133 ( V_109 , V_46 ) ;
else
F_110 ( V_10 ) ;
}
void * F_140 ( struct V_20 * * V_21 , unsigned int V_110 , int V_50 , T_5 V_19 )
{
unsigned long V_46 = V_110 << V_79 ;
unsigned long V_10 ;
void * V_109 ;
if ( F_139 ( V_110 <= V_103 ) ) {
V_109 = F_131 ( V_46 , V_111 ) ;
if ( F_115 ( V_109 ) )
return NULL ;
V_10 = ( unsigned long ) V_109 ;
} else {
struct V_34 * V_38 ;
V_38 = F_59 ( V_46 , V_15 ,
V_68 , V_69 , V_50 , V_111 ) ;
if ( F_115 ( V_38 ) )
return NULL ;
V_10 = V_38 -> va_start ;
V_109 = ( void * ) V_10 ;
}
if ( F_36 ( V_10 , V_10 + V_46 , V_19 , V_21 ) < 0 ) {
F_137 ( V_109 , V_110 ) ;
return NULL ;
}
return V_109 ;
}
void T_7 F_141 ( struct V_112 * V_113 )
{
struct V_112 * V_42 , * * V_4 ;
F_23 ( V_106 ) ;
for ( V_4 = & V_114 ; ( V_42 = * V_4 ) != NULL ; V_4 = & V_42 -> V_17 ) {
if ( V_42 -> V_10 >= V_113 -> V_10 ) {
F_23 ( V_42 -> V_10 < V_113 -> V_10 + V_113 -> V_46 ) ;
break;
} else
F_23 ( V_42 -> V_10 + V_42 -> V_46 > V_113 -> V_10 ) ;
}
V_113 -> V_17 = * V_4 ;
* V_4 = V_113 ;
}
void T_7 F_142 ( struct V_112 * V_113 , T_8 V_47 )
{
static T_8 T_9 V_115 ;
unsigned long V_10 ;
V_10 = F_66 ( V_68 + T_9 , V_47 ) ;
T_9 = F_143 ( V_10 + V_113 -> V_46 ) - V_68 ;
V_113 -> V_10 = ( void * ) V_10 ;
F_141 ( V_113 ) ;
}
void T_7 F_144 ( void )
{
struct V_34 * V_38 ;
struct V_112 * V_42 ;
int V_116 ;
F_130 (i) {
struct V_86 * V_87 ;
struct V_3 * V_4 ;
V_87 = & F_128 ( V_86 , V_116 ) ;
F_118 ( & V_87 -> V_92 ) ;
F_119 ( & V_87 -> free ) ;
V_4 = & F_128 ( V_3 , V_116 ) ;
F_145 ( & V_4 -> V_8 ) ;
F_146 ( & V_4 -> V_5 , F_1 ) ;
}
for ( V_42 = V_114 ; V_42 ; V_42 = V_42 -> V_17 ) {
V_38 = F_147 ( sizeof( struct V_34 ) , V_117 ) ;
V_38 -> V_66 = V_118 ;
V_38 -> va_start = ( unsigned long ) V_42 -> V_10 ;
V_38 -> va_end = V_38 -> va_start + V_42 -> V_46 ;
V_38 -> V_113 = V_42 ;
F_53 ( V_38 ) ;
}
V_70 = V_69 ;
V_106 = true ;
}
int F_148 ( unsigned long V_10 , unsigned long V_46 ,
T_5 V_19 , struct V_20 * * V_21 )
{
return F_35 ( V_10 , V_10 + V_46 , V_19 , V_21 ) ;
}
void F_149 ( unsigned long V_10 , unsigned long V_46 )
{
F_22 ( V_10 , V_10 + V_46 ) ;
}
void F_150 ( unsigned long V_10 , unsigned long V_46 )
{
unsigned long V_11 = V_10 + V_46 ;
F_108 ( V_10 , V_11 ) ;
F_22 ( V_10 , V_11 ) ;
F_85 ( V_10 , V_11 ) ;
}
int F_151 ( struct V_112 * V_119 , T_5 V_19 , struct V_20 * * V_21 )
{
unsigned long V_10 = ( unsigned long ) V_119 -> V_10 ;
unsigned long V_11 = V_10 + F_152 ( V_119 ) ;
int V_26 ;
V_26 = F_36 ( V_10 , V_11 , V_19 , V_21 ) ;
return V_26 > 0 ? 0 : V_26 ;
}
static void F_153 ( struct V_112 * V_113 , struct V_34 * V_38 ,
unsigned long V_66 , const void * V_120 )
{
F_65 ( & V_58 ) ;
V_113 -> V_66 = V_66 ;
V_113 -> V_10 = ( void * ) V_38 -> va_start ;
V_113 -> V_46 = V_38 -> va_end - V_38 -> va_start ;
V_113 -> V_120 = V_120 ;
V_38 -> V_113 = V_113 ;
V_38 -> V_66 |= V_118 ;
F_69 ( & V_58 ) ;
}
static void F_154 ( struct V_112 * V_113 )
{
F_155 () ;
V_113 -> V_66 &= ~ V_121 ;
}
static struct V_112 * F_156 ( unsigned long V_46 ,
unsigned long V_47 , unsigned long V_66 , unsigned long V_25 ,
unsigned long V_11 , int V_50 , T_6 V_51 , const void * V_120 )
{
struct V_34 * V_38 ;
struct V_112 * V_119 ;
F_23 ( F_157 () ) ;
if ( V_66 & V_122 )
V_47 = 1ul << F_158 ( int , F_159 ( V_46 ) ,
V_79 , V_123 ) ;
V_46 = F_160 ( V_46 ) ;
if ( F_62 ( ! V_46 ) )
return NULL ;
V_119 = F_161 ( sizeof( * V_119 ) , V_51 & V_55 , V_50 ) ;
if ( F_62 ( ! V_119 ) )
return NULL ;
if ( ! ( V_66 & V_124 ) )
V_46 += V_15 ;
V_38 = F_59 ( V_46 , V_47 , V_25 , V_11 , V_50 , V_51 ) ;
if ( F_115 ( V_38 ) ) {
F_73 ( V_119 ) ;
return NULL ;
}
F_153 ( V_119 , V_38 , V_66 , V_120 ) ;
return V_119 ;
}
struct V_112 * F_162 ( unsigned long V_46 , unsigned long V_66 ,
unsigned long V_25 , unsigned long V_11 )
{
return F_156 ( V_46 , 1 , V_66 , V_25 , V_11 , V_125 ,
V_111 , F_163 ( 0 ) ) ;
}
struct V_112 * F_164 ( unsigned long V_46 , unsigned long V_66 ,
unsigned long V_25 , unsigned long V_11 ,
const void * V_120 )
{
return F_156 ( V_46 , 1 , V_66 , V_25 , V_11 , V_125 ,
V_111 , V_120 ) ;
}
struct V_112 * F_165 ( unsigned long V_46 , unsigned long V_66 )
{
return F_156 ( V_46 , 1 , V_66 , V_68 , V_69 ,
V_125 , V_111 ,
F_163 ( 0 ) ) ;
}
struct V_112 * F_166 ( unsigned long V_46 , unsigned long V_66 ,
const void * V_120 )
{
return F_156 ( V_46 , 1 , V_66 , V_68 , V_69 ,
V_125 , V_111 , V_120 ) ;
}
struct V_112 * F_167 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_109 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_66 & V_118 )
return V_38 -> V_113 ;
return NULL ;
}
struct V_112 * F_168 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_109 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_66 & V_118 ) {
struct V_112 * V_113 = V_38 -> V_113 ;
F_65 ( & V_58 ) ;
V_38 -> V_113 = NULL ;
V_38 -> V_66 &= ~ V_118 ;
F_69 ( & V_58 ) ;
F_83 ( V_38 -> va_start , V_38 -> va_end ) ;
F_169 ( V_113 ) ;
F_107 ( V_38 ) ;
V_113 -> V_46 -= V_15 ;
return V_113 ;
}
return NULL ;
}
static void F_5 ( const void * V_10 , int V_126 )
{
struct V_112 * V_119 ;
if ( ! V_10 )
return;
if ( F_170 ( ! F_171 ( V_10 ) , L_3 ,
V_10 ) )
return;
V_119 = F_168 ( V_10 ) ;
if ( F_62 ( ! V_119 ) ) {
F_170 ( 1 , V_127 L_4 ,
V_10 ) ;
return;
}
F_138 ( V_10 , V_119 -> V_46 ) ;
F_172 ( V_10 , V_119 -> V_46 ) ;
if ( V_126 ) {
int V_116 ;
for ( V_116 = 0 ; V_116 < V_119 -> V_128 ; V_116 ++ ) {
struct V_20 * V_20 = V_119 -> V_21 [ V_116 ] ;
F_23 ( ! V_20 ) ;
F_173 ( V_20 ) ;
}
if ( V_119 -> V_66 & V_129 )
F_174 ( V_119 -> V_21 ) ;
else
F_73 ( V_119 -> V_21 ) ;
}
F_73 ( V_119 ) ;
return;
}
void F_174 ( const void * V_10 )
{
F_23 ( F_175 () ) ;
F_176 ( V_10 ) ;
if ( ! V_10 )
return;
if ( F_62 ( F_157 () ) ) {
struct V_3 * V_4 = F_177 ( & V_3 ) ;
if ( F_178 ( (struct V_6 * ) V_10 , & V_4 -> V_8 ) )
F_179 ( & V_4 -> V_5 ) ;
} else
F_5 ( V_10 , 1 ) ;
}
void F_180 ( const void * V_10 )
{
F_23 ( F_157 () ) ;
F_181 () ;
if ( V_10 )
F_5 ( V_10 , 0 ) ;
}
void * F_182 ( struct V_20 * * V_21 , unsigned int V_110 ,
unsigned long V_66 , T_5 V_19 )
{
struct V_112 * V_119 ;
F_181 () ;
if ( V_110 > V_130 )
return NULL ;
V_119 = F_166 ( ( V_110 << V_79 ) , V_66 ,
F_163 ( 0 ) ) ;
if ( ! V_119 )
return NULL ;
if ( F_151 ( V_119 , V_19 , V_21 ) ) {
F_180 ( V_119 -> V_10 ) ;
return NULL ;
}
return V_119 -> V_10 ;
}
static void * F_183 ( struct V_112 * V_119 , T_6 V_51 ,
T_5 V_19 , int V_50 )
{
const int V_85 = 0 ;
struct V_20 * * V_21 ;
unsigned int V_128 , V_131 , V_116 ;
const T_6 V_132 = ( V_51 & V_55 ) | V_133 ;
const T_6 V_134 = V_51 | V_135 ;
V_128 = F_152 ( V_119 ) >> V_79 ;
V_131 = ( V_128 * sizeof( struct V_20 * ) ) ;
V_119 -> V_128 = V_128 ;
if ( V_131 > V_15 ) {
V_21 = F_184 ( V_131 , 1 , V_132 | V_136 ,
V_137 , V_50 , V_119 -> V_120 ) ;
V_119 -> V_66 |= V_129 ;
} else {
V_21 = F_61 ( V_131 , V_132 , V_50 ) ;
}
V_119 -> V_21 = V_21 ;
if ( ! V_119 -> V_21 ) {
F_168 ( V_119 -> V_10 ) ;
F_73 ( V_119 ) ;
return NULL ;
}
for ( V_116 = 0 ; V_116 < V_119 -> V_128 ; V_116 ++ ) {
struct V_20 * V_20 ;
if ( V_50 == V_125 )
V_20 = F_185 ( V_134 ) ;
else
V_20 = F_186 ( V_50 , V_134 , V_85 ) ;
if ( F_62 ( ! V_20 ) ) {
V_119 -> V_128 = V_116 ;
goto V_138;
}
V_119 -> V_21 [ V_116 ] = V_20 ;
if ( V_51 & V_139 )
F_187 () ;
}
if ( F_151 ( V_119 , V_19 , V_21 ) )
goto V_138;
return V_119 -> V_10 ;
V_138:
F_188 ( V_51 , V_85 ,
L_5 ,
( V_119 -> V_128 * V_15 ) , V_119 -> V_46 ) ;
F_174 ( V_119 -> V_10 ) ;
return NULL ;
}
void * F_189 ( unsigned long V_46 , unsigned long V_47 ,
unsigned long V_25 , unsigned long V_11 , T_6 V_51 ,
T_5 V_19 , unsigned long V_140 , int V_50 ,
const void * V_120 )
{
struct V_112 * V_119 ;
void * V_10 ;
unsigned long V_141 = V_46 ;
V_46 = F_160 ( V_46 ) ;
if ( ! V_46 || ( V_46 >> V_79 ) > V_130 )
goto V_138;
V_119 = F_156 ( V_46 , V_47 , V_142 | V_121 |
V_140 , V_25 , V_11 , V_50 , V_51 , V_120 ) ;
if ( ! V_119 )
goto V_138;
V_10 = F_183 ( V_119 , V_51 , V_19 , V_50 ) ;
if ( ! V_10 )
return NULL ;
F_154 ( V_119 ) ;
F_190 ( V_10 , V_141 , 2 , V_51 ) ;
return V_10 ;
V_138:
F_188 ( V_51 , 0 ,
L_6 ,
V_141 ) ;
return NULL ;
}
static void * F_184 ( unsigned long V_46 , unsigned long V_47 ,
T_6 V_51 , T_5 V_19 ,
int V_50 , const void * V_120 )
{
return F_189 ( V_46 , V_47 , V_68 , V_69 ,
V_51 , V_19 , 0 , V_50 , V_120 ) ;
}
void * F_191 ( unsigned long V_46 , T_6 V_51 , T_5 V_19 )
{
return F_184 ( V_46 , 1 , V_51 , V_19 , V_125 ,
F_163 ( 0 ) ) ;
}
static inline void * F_192 ( unsigned long V_46 ,
int V_50 , T_6 V_66 )
{
return F_184 ( V_46 , 1 , V_66 , V_137 ,
V_50 , F_163 ( 0 ) ) ;
}
void * F_193 ( unsigned long V_46 )
{
return F_192 ( V_46 , V_125 ,
V_111 | V_136 ) ;
}
void * F_194 ( unsigned long V_46 )
{
return F_192 ( V_46 , V_125 ,
V_111 | V_136 | V_133 ) ;
}
void * F_195 ( unsigned long V_46 )
{
struct V_112 * V_119 ;
void * V_27 ;
V_27 = F_184 ( V_46 , V_143 ,
V_111 | V_136 | V_133 ,
V_137 , V_125 ,
F_163 ( 0 ) ) ;
if ( V_27 ) {
V_119 = F_167 ( V_27 ) ;
V_119 -> V_66 |= V_144 ;
}
return V_27 ;
}
void * F_196 ( unsigned long V_46 , int V_50 )
{
return F_184 ( V_46 , 1 , V_111 | V_136 , V_137 ,
V_50 , F_163 ( 0 ) ) ;
}
void * F_197 ( unsigned long V_46 , int V_50 )
{
return F_192 ( V_46 , V_50 ,
V_111 | V_136 | V_133 ) ;
}
void * F_198 ( unsigned long V_46 )
{
return F_184 ( V_46 , 1 , V_111 | V_136 , V_145 ,
V_125 , F_163 ( 0 ) ) ;
}
void * F_199 ( unsigned long V_46 )
{
return F_184 ( V_46 , 1 , V_146 , V_137 ,
V_125 , F_163 ( 0 ) ) ;
}
void * F_200 ( unsigned long V_46 )
{
struct V_112 * V_119 ;
void * V_27 ;
V_27 = F_184 ( V_46 , 1 , V_146 | V_133 , V_137 ,
V_125 , F_163 ( 0 ) ) ;
if ( V_27 ) {
V_119 = F_167 ( V_27 ) ;
V_119 -> V_66 |= V_144 ;
}
return V_27 ;
}
static int F_201 ( char * V_147 , char * V_10 , unsigned long V_110 )
{
struct V_20 * V_4 ;
int V_148 = 0 ;
while ( V_110 ) {
unsigned long V_104 , V_149 ;
V_104 = ( unsigned long ) V_10 & ~ V_54 ;
V_149 = V_15 - V_104 ;
if ( V_149 > V_110 )
V_149 = V_110 ;
V_4 = F_41 ( V_10 ) ;
if ( V_4 ) {
void * V_150 = F_202 ( V_4 ) ;
memcpy ( V_147 , V_150 + V_104 , V_149 ) ;
F_203 ( V_150 ) ;
} else
memset ( V_147 , 0 , V_149 ) ;
V_10 += V_149 ;
V_147 += V_149 ;
V_148 += V_149 ;
V_110 -= V_149 ;
}
return V_148 ;
}
static int F_204 ( char * V_147 , char * V_10 , unsigned long V_110 )
{
struct V_20 * V_4 ;
int V_148 = 0 ;
while ( V_110 ) {
unsigned long V_104 , V_149 ;
V_104 = ( unsigned long ) V_10 & ~ V_54 ;
V_149 = V_15 - V_104 ;
if ( V_149 > V_110 )
V_149 = V_110 ;
V_4 = F_41 ( V_10 ) ;
if ( V_4 ) {
void * V_150 = F_202 ( V_4 ) ;
memcpy ( V_150 + V_104 , V_147 , V_149 ) ;
F_203 ( V_150 ) ;
}
V_10 += V_149 ;
V_147 += V_149 ;
V_148 += V_149 ;
V_110 -= V_149 ;
}
return V_148 ;
}
long F_205 ( char * V_147 , char * V_10 , unsigned long V_110 )
{
struct V_34 * V_38 ;
struct V_112 * V_113 ;
char * V_91 , * V_151 = V_147 ;
unsigned long V_152 = V_110 ;
unsigned long V_36 ;
if ( ( unsigned long ) V_10 + V_110 < V_110 )
V_110 = - ( unsigned long ) V_10 ;
F_65 ( & V_58 ) ;
F_206 (va, &vmap_area_list, list) {
if ( ! V_110 )
break;
if ( ! ( V_38 -> V_66 & V_118 ) )
continue;
V_113 = V_38 -> V_113 ;
V_91 = ( char * ) V_113 -> V_10 ;
if ( V_10 >= V_91 + F_152 ( V_113 ) )
continue;
while ( V_10 < V_91 ) {
if ( V_110 == 0 )
goto V_153;
* V_147 = '\0' ;
V_147 ++ ;
V_10 ++ ;
V_110 -- ;
}
V_36 = V_91 + F_152 ( V_113 ) - V_10 ;
if ( V_36 > V_110 )
V_36 = V_110 ;
if ( ! ( V_113 -> V_66 & V_122 ) )
F_201 ( V_147 , V_10 , V_36 ) ;
else
memset ( V_147 , 0 , V_36 ) ;
V_147 += V_36 ;
V_10 += V_36 ;
V_110 -= V_36 ;
}
V_153:
F_69 ( & V_58 ) ;
if ( V_147 == V_151 )
return 0 ;
if ( V_147 != V_151 + V_152 )
memset ( V_147 , 0 , V_152 - ( V_147 - V_151 ) ) ;
return V_152 ;
}
long F_207 ( char * V_147 , char * V_10 , unsigned long V_110 )
{
struct V_34 * V_38 ;
struct V_112 * V_113 ;
char * V_91 ;
unsigned long V_36 , V_152 ;
int V_148 = 0 ;
if ( ( unsigned long ) V_10 + V_110 < V_110 )
V_110 = - ( unsigned long ) V_10 ;
V_152 = V_110 ;
F_65 ( & V_58 ) ;
F_206 (va, &vmap_area_list, list) {
if ( ! V_110 )
break;
if ( ! ( V_38 -> V_66 & V_118 ) )
continue;
V_113 = V_38 -> V_113 ;
V_91 = ( char * ) V_113 -> V_10 ;
if ( V_10 >= V_91 + F_152 ( V_113 ) )
continue;
while ( V_10 < V_91 ) {
if ( V_110 == 0 )
goto V_153;
V_147 ++ ;
V_10 ++ ;
V_110 -- ;
}
V_36 = V_91 + F_152 ( V_113 ) - V_10 ;
if ( V_36 > V_110 )
V_36 = V_110 ;
if ( ! ( V_113 -> V_66 & V_122 ) ) {
F_204 ( V_147 , V_10 , V_36 ) ;
V_148 ++ ;
}
V_147 += V_36 ;
V_10 += V_36 ;
V_110 -= V_36 ;
}
V_153:
F_69 ( & V_58 ) ;
if ( ! V_148 )
return 0 ;
return V_152 ;
}
int F_208 ( struct V_154 * V_155 , unsigned long V_156 ,
void * V_157 , unsigned long V_46 )
{
struct V_112 * V_119 ;
V_46 = F_160 ( V_46 ) ;
if ( ! F_171 ( V_156 ) || ! F_171 ( V_157 ) )
return - V_158 ;
V_119 = F_167 ( V_157 ) ;
if ( ! V_119 )
return - V_158 ;
if ( ! ( V_119 -> V_66 & V_144 ) )
return - V_158 ;
if ( V_157 + V_46 > V_119 -> V_10 + V_119 -> V_46 )
return - V_158 ;
do {
struct V_20 * V_20 = F_41 ( V_157 ) ;
int V_27 ;
V_27 = F_209 ( V_155 , V_156 , V_20 ) ;
if ( V_27 )
return V_27 ;
V_156 += V_15 ;
V_157 += V_15 ;
V_46 -= V_15 ;
} while ( V_46 > 0 );
V_155 -> V_140 |= V_159 | V_160 ;
return 0 ;
}
int F_210 ( struct V_154 * V_155 , void * V_10 ,
unsigned long V_161 )
{
return F_208 ( V_155 , V_155 -> V_162 ,
V_10 + ( V_161 << V_79 ) ,
V_155 -> V_163 - V_155 -> V_162 ) ;
}
void __weak F_211 ( void )
{
}
static int F_212 ( T_2 * V_12 , T_10 V_164 , unsigned long V_10 , void * V_165 )
{
T_2 * * * V_4 = V_165 ;
if ( V_4 ) {
* ( * V_4 ) = V_12 ;
( * V_4 ) ++ ;
}
return 0 ;
}
struct V_112 * F_213 ( T_8 V_46 , T_2 * * V_166 )
{
struct V_112 * V_119 ;
V_119 = F_166 ( V_46 , V_122 ,
F_163 ( 0 ) ) ;
if ( V_119 == NULL )
return NULL ;
if ( F_214 ( & V_14 , ( unsigned long ) V_119 -> V_10 ,
V_46 , F_212 , V_166 ? & V_166 : NULL ) ) {
F_215 ( V_119 ) ;
return NULL ;
}
return V_119 ;
}
void F_215 ( struct V_112 * V_119 )
{
struct V_112 * V_27 ;
V_27 = F_168 ( V_119 -> V_10 ) ;
F_23 ( V_27 != V_119 ) ;
F_73 ( V_119 ) ;
}
static struct V_34 * F_216 ( struct V_35 * V_36 )
{
return V_36 ? F_52 ( V_36 , struct V_34 , V_35 ) : NULL ;
}
static bool F_217 ( unsigned long V_11 ,
struct V_34 * * V_167 ,
struct V_34 * * V_168 )
{
struct V_35 * V_36 = V_37 . V_35 ;
struct V_34 * V_38 = NULL ;
while ( V_36 ) {
V_38 = F_52 ( V_36 , struct V_34 , V_35 ) ;
if ( V_11 < V_38 -> va_end )
V_36 = V_36 -> V_39 ;
else if ( V_11 > V_38 -> va_end )
V_36 = V_36 -> V_40 ;
else
break;
}
if ( ! V_38 )
return false ;
if ( V_38 -> va_end > V_11 ) {
* V_167 = V_38 ;
* V_168 = F_216 ( F_57 ( & ( * V_167 ) -> V_35 ) ) ;
} else {
* V_168 = V_38 ;
* V_167 = F_216 ( F_218 ( & ( * V_168 ) -> V_35 ) ) ;
}
return true ;
}
static unsigned long F_219 ( struct V_34 * * V_167 ,
struct V_34 * * V_168 ,
unsigned long V_47 )
{
const unsigned long V_169 = V_69 & ~ ( V_47 - 1 ) ;
unsigned long V_10 ;
if ( * V_167 )
V_10 = F_135 ( ( * V_167 ) -> va_start & ~ ( V_47 - 1 ) , V_169 ) ;
else
V_10 = V_169 ;
while ( * V_168 && ( * V_168 ) -> va_end > V_10 ) {
* V_167 = * V_168 ;
* V_168 = F_216 ( F_57 ( & ( * V_167 ) -> V_35 ) ) ;
}
return V_10 ;
}
struct V_112 * * F_220 ( const unsigned long * V_170 ,
const T_8 * V_171 , int V_172 ,
T_8 V_47 )
{
const unsigned long V_173 = F_66 ( V_68 , V_47 ) ;
const unsigned long V_169 = V_69 & ~ ( V_47 - 1 ) ;
struct V_34 * * V_174 , * V_44 , * V_17 ;
struct V_112 * * V_175 ;
int V_119 , V_176 , V_177 , V_178 ;
unsigned long V_179 , V_25 , V_11 , V_180 ;
bool V_52 = false ;
F_23 ( V_47 & ~ V_54 || ! F_60 ( V_47 ) ) ;
for ( V_177 = 0 , V_119 = 0 ; V_119 < V_172 ; V_119 ++ ) {
V_25 = V_170 [ V_119 ] ;
V_11 = V_25 + V_171 [ V_119 ] ;
F_23 ( ! F_221 ( V_170 [ V_119 ] , V_47 ) ) ;
F_23 ( ! F_221 ( V_171 [ V_119 ] , V_47 ) ) ;
if ( V_25 > V_170 [ V_177 ] )
V_177 = V_119 ;
for ( V_176 = 0 ; V_176 < V_172 ; V_176 ++ ) {
unsigned long V_181 = V_170 [ V_176 ] ;
unsigned long V_182 = V_181 + V_171 [ V_176 ] ;
if ( V_176 == V_119 )
continue;
F_23 ( V_181 >= V_25 && V_181 < V_11 ) ;
F_23 ( V_182 <= V_11 && V_182 > V_25 ) ;
}
}
V_180 = V_170 [ V_177 ] + V_171 [ V_177 ] ;
if ( V_169 - V_173 < V_180 ) {
F_9 ( true ) ;
return NULL ;
}
V_175 = F_222 ( V_172 , sizeof( V_175 [ 0 ] ) , V_111 ) ;
V_174 = F_222 ( V_172 , sizeof( V_174 [ 0 ] ) , V_111 ) ;
if ( ! V_174 || ! V_175 )
goto V_183;
for ( V_119 = 0 ; V_119 < V_172 ; V_119 ++ ) {
V_174 [ V_119 ] = F_147 ( sizeof( struct V_34 ) , V_111 ) ;
V_175 [ V_119 ] = F_147 ( sizeof( struct V_112 ) , V_111 ) ;
if ( ! V_174 [ V_119 ] || ! V_175 [ V_119 ] )
goto V_184;
}
V_57:
F_65 ( & V_58 ) ;
V_119 = V_178 = V_177 ;
V_25 = V_170 [ V_119 ] ;
V_11 = V_25 + V_171 [ V_119 ] ;
if ( ! F_217 ( V_70 , & V_17 , & V_44 ) ) {
V_179 = V_169 - V_180 ;
goto V_65;
}
V_179 = F_219 ( & V_17 , & V_44 , V_47 ) - V_11 ;
while ( true ) {
F_23 ( V_17 && V_17 -> va_end <= V_179 + V_11 ) ;
F_23 ( V_44 && V_44 -> va_end > V_179 + V_11 ) ;
if ( V_179 + V_180 < V_173 + V_180 ) {
F_69 ( & V_58 ) ;
if ( ! V_52 ) {
F_70 () ;
V_52 = true ;
goto V_57;
}
goto V_184;
}
if ( V_17 && V_17 -> va_start < V_179 + V_11 ) {
V_179 = F_219 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_178 = V_119 ;
continue;
}
if ( V_44 && V_44 -> va_end > V_179 + V_25 ) {
V_17 = V_44 ;
V_44 = F_216 ( F_57 ( & V_17 -> V_35 ) ) ;
V_179 = F_219 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_178 = V_119 ;
continue;
}
V_119 = ( V_119 + V_172 - 1 ) % V_172 ;
if ( V_119 == V_178 )
break;
V_25 = V_170 [ V_119 ] ;
V_11 = V_25 + V_171 [ V_119 ] ;
F_217 ( V_179 + V_11 , & V_17 , & V_44 ) ;
}
V_65:
for ( V_119 = 0 ; V_119 < V_172 ; V_119 ++ ) {
struct V_34 * V_38 = V_174 [ V_119 ] ;
V_38 -> va_start = V_179 + V_170 [ V_119 ] ;
V_38 -> va_end = V_38 -> va_start + V_171 [ V_119 ] ;
F_53 ( V_38 ) ;
}
V_70 = V_179 + V_170 [ V_177 ] ;
F_69 ( & V_58 ) ;
for ( V_119 = 0 ; V_119 < V_172 ; V_119 ++ )
F_153 ( V_175 [ V_119 ] , V_174 [ V_119 ] , V_142 ,
F_220 ) ;
F_73 ( V_174 ) ;
return V_175 ;
V_184:
for ( V_119 = 0 ; V_119 < V_172 ; V_119 ++ ) {
F_73 ( V_174 [ V_119 ] ) ;
F_73 ( V_175 [ V_119 ] ) ;
}
V_183:
F_73 ( V_174 ) ;
F_73 ( V_175 ) ;
return NULL ;
}
void F_223 ( struct V_112 * * V_175 , int V_172 )
{
int V_116 ;
for ( V_116 = 0 ; V_116 < V_172 ; V_116 ++ )
F_215 ( V_175 [ V_116 ] ) ;
F_73 ( V_175 ) ;
}
static void * F_224 ( struct V_185 * V_186 , T_11 * V_187 )
__acquires( &vmap_area_lock
static void * F_225 ( struct V_185 * V_186 , void * V_4 , T_11 * V_187 )
{
struct V_34 * V_38 = V_4 , * V_17 ;
++ * V_187 ;
V_17 = F_68 ( V_38 -> V_8 . V_17 , F_226 ( * V_38 ) , V_8 ) ;
if ( & V_17 -> V_8 != & V_45 )
return V_17 ;
return NULL ;
}
static void F_227 ( struct V_185 * V_186 , void * V_4 )
__releases( &vmap_area_lock
static void F_228 ( struct V_185 * V_186 , struct V_112 * V_188 )
{
if ( F_229 ( V_189 ) ) {
unsigned int V_22 , * V_190 = V_186 -> V_191 ;
if ( ! V_190 )
return;
if ( V_188 -> V_66 & V_121 )
return;
F_230 () ;
memset ( V_190 , 0 , V_192 * sizeof( unsigned int ) ) ;
for ( V_22 = 0 ; V_22 < V_188 -> V_128 ; V_22 ++ )
V_190 [ F_231 ( V_188 -> V_21 [ V_22 ] ) ] ++ ;
F_232 (nr, N_HIGH_MEMORY)
if ( V_190 [ V_22 ] )
F_233 ( V_186 , L_7 , V_22 , V_190 [ V_22 ] ) ;
}
}
static int F_234 ( struct V_185 * V_186 , void * V_4 )
{
struct V_34 * V_38 = V_4 ;
struct V_112 * V_188 ;
if ( ! ( V_38 -> V_66 & V_118 ) )
return 0 ;
V_188 = V_38 -> V_113 ;
F_233 ( V_186 , L_8 ,
V_188 -> V_10 , V_188 -> V_10 + V_188 -> V_46 , V_188 -> V_46 ) ;
if ( V_188 -> V_120 )
F_233 ( V_186 , L_9 , V_188 -> V_120 ) ;
if ( V_188 -> V_128 )
F_233 ( V_186 , L_10 , V_188 -> V_128 ) ;
if ( V_188 -> V_193 )
F_233 ( V_186 , L_11 , ( unsigned long long ) V_188 -> V_193 ) ;
if ( V_188 -> V_66 & V_122 )
F_235 ( V_186 , L_12 ) ;
if ( V_188 -> V_66 & V_142 )
F_235 ( V_186 , L_13 ) ;
if ( V_188 -> V_66 & V_194 )
F_235 ( V_186 , L_14 ) ;
if ( V_188 -> V_66 & V_144 )
F_235 ( V_186 , L_15 ) ;
if ( V_188 -> V_66 & V_129 )
F_235 ( V_186 , L_16 ) ;
F_228 ( V_186 , V_188 ) ;
F_236 ( V_186 , '\n' ) ;
return 0 ;
}
static int F_237 ( struct V_195 * V_195 , struct V_196 * V_196 )
{
if ( F_229 ( V_189 ) )
return F_238 ( V_196 , & V_197 ,
V_192 * sizeof( unsigned int ) ) ;
else
return F_239 ( V_196 , & V_197 ) ;
}
static int T_7 F_240 ( void )
{
F_241 ( L_17 , V_198 , NULL , & V_199 ) ;
return 0 ;
}
void F_242 ( struct V_200 * V_201 )
{
struct V_34 * V_38 ;
unsigned long V_202 ;
unsigned long V_203 ;
V_201 -> V_204 = 0 ;
V_201 -> V_205 = 0 ;
V_203 = V_68 ;
F_96 () ;
if ( F_243 ( & V_45 ) ) {
V_201 -> V_205 = V_206 ;
goto V_207;
}
F_97 (va, &vmap_area_list, list) {
unsigned long V_10 = V_38 -> va_start ;
if ( V_10 < V_68 )
continue;
if ( V_10 >= V_69 )
break;
if ( V_38 -> V_66 & ( V_78 | V_81 ) )
continue;
V_201 -> V_204 += ( V_38 -> va_end - V_38 -> va_start ) ;
V_202 = V_10 - V_203 ;
if ( V_201 -> V_205 < V_202 )
V_201 -> V_205 = V_202 ;
V_203 = V_38 -> va_end ;
}
if ( V_69 - V_203 > V_201 -> V_205 )
V_201 -> V_205 = V_69 - V_203 ;
V_207:
F_99 () ;
}
