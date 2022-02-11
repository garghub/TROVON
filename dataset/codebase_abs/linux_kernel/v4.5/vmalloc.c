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
F_23 ( F_60 ( V_46 ) ) ;
F_23 ( ! F_61 ( V_47 ) ) ;
V_38 = F_62 ( sizeof( struct V_34 ) ,
V_51 & V_54 , V_50 ) ;
if ( F_63 ( ! V_38 ) )
return F_64 ( - V_23 ) ;
F_65 ( & V_38 -> V_35 , V_55 , V_51 & V_54 ) ;
V_56:
F_66 ( & V_57 ) ;
if ( ! V_58 ||
V_46 < V_59 ||
V_48 < V_60 ||
V_47 < V_61 ) {
V_62:
V_59 = 0 ;
V_58 = NULL ;
}
V_60 = V_48 ;
V_61 = V_47 ;
if ( V_58 ) {
V_53 = F_52 ( V_58 , struct V_34 , V_35 ) ;
V_10 = F_67 ( V_53 -> va_end , V_47 ) ;
if ( V_10 < V_48 )
goto V_62;
if ( V_10 + V_46 < V_10 )
goto V_63;
} else {
V_10 = F_67 ( V_48 , V_47 ) ;
if ( V_10 + V_46 < V_10 )
goto V_63;
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
goto V_64;
}
while ( V_10 + V_46 > V_53 -> va_start && V_10 + V_46 <= V_49 ) {
if ( V_10 + V_59 < V_53 -> va_start )
V_59 = V_53 -> va_start - V_10 ;
V_10 = F_67 ( V_53 -> va_end , V_47 ) ;
if ( V_10 + V_46 < V_10 )
goto V_63;
if ( F_68 ( & V_53 -> V_8 , & V_45 ) )
goto V_64;
V_53 = F_69 ( V_53 , V_8 ) ;
}
V_64:
if ( V_10 + V_46 > V_49 )
goto V_63;
V_38 -> va_start = V_10 ;
V_38 -> va_end = V_10 + V_46 ;
V_38 -> V_65 = 0 ;
F_53 ( V_38 ) ;
V_58 = & V_38 -> V_35 ;
F_70 ( & V_57 ) ;
F_23 ( ! F_71 ( V_38 -> va_start , V_47 ) ) ;
F_23 ( V_38 -> va_start < V_48 ) ;
F_23 ( V_38 -> va_end > V_49 ) ;
return V_38 ;
V_63:
F_70 ( & V_57 ) ;
if ( ! V_52 ) {
F_72 () ;
V_52 = 1 ;
goto V_56;
}
if ( F_73 () )
F_74 ( L_1
L_2 , V_46 ) ;
F_75 ( V_38 ) ;
return F_64 ( - V_24 ) ;
}
static void F_76 ( struct V_34 * V_38 )
{
F_23 ( F_77 ( & V_38 -> V_35 ) ) ;
if ( V_58 ) {
if ( V_38 -> va_end < V_60 ) {
V_58 = NULL ;
} else {
struct V_34 * V_66 ;
V_66 = F_52 ( V_58 , struct V_34 , V_35 ) ;
if ( V_38 -> va_start <= V_66 -> va_start ) {
V_58 = F_57 ( & V_38 -> V_35 ) ;
}
}
}
F_78 ( & V_38 -> V_35 , & V_37 ) ;
F_79 ( & V_38 -> V_35 ) ;
F_80 ( & V_38 -> V_8 ) ;
if ( V_38 -> va_end > V_67 && V_38 -> va_end <= V_68 )
V_69 = F_81 ( V_69 , V_38 -> va_end ) ;
F_82 ( V_38 , V_70 ) ;
}
static void F_83 ( struct V_34 * V_38 )
{
F_66 ( & V_57 ) ;
F_76 ( V_38 ) ;
F_70 ( & V_57 ) ;
}
static void F_84 ( struct V_34 * V_38 )
{
F_22 ( V_38 -> va_start , V_38 -> va_end ) ;
}
static void F_85 ( unsigned long V_25 , unsigned long V_11 )
{
#ifdef F_86
F_22 ( V_25 , V_11 ) ;
F_87 ( V_25 , V_11 ) ;
#endif
}
static unsigned long F_88 ( void )
{
unsigned int log ;
log = F_89 ( F_90 () ) ;
return log * ( 32UL * 1024 * 1024 / V_15 ) ;
}
void F_91 ( void )
{
F_92 ( & V_71 , F_88 () + 1 ) ;
}
static void F_93 ( unsigned long * V_25 , unsigned long * V_11 ,
int V_72 , int V_73 )
{
static F_94 ( V_74 ) ;
F_95 ( V_75 ) ;
struct V_34 * V_38 ;
struct V_34 * V_76 ;
int V_22 = 0 ;
if ( ! V_72 && ! V_73 ) {
if ( ! F_96 ( & V_74 ) )
return;
} else
F_66 ( & V_74 ) ;
if ( V_72 )
F_97 () ;
F_98 () ;
F_99 (va, &vmap_area_list, list) {
if ( V_38 -> V_65 & V_77 ) {
if ( V_38 -> va_start < * V_25 )
* V_25 = V_38 -> va_start ;
if ( V_38 -> va_end > * V_11 )
* V_11 = V_38 -> va_end ;
V_22 += ( V_38 -> va_end - V_38 -> va_start ) >> V_78 ;
F_100 ( & V_38 -> V_79 , & V_75 ) ;
V_38 -> V_65 |= V_80 ;
V_38 -> V_65 &= ~ V_77 ;
}
}
F_101 () ;
if ( V_22 )
F_102 ( V_22 , & V_71 ) ;
if ( V_22 || V_73 )
F_87 ( * V_25 , * V_11 ) ;
if ( V_22 ) {
F_66 ( & V_57 ) ;
F_103 (va, n_va, &valist, purge_list)
F_76 ( V_38 ) ;
F_70 ( & V_57 ) ;
}
F_70 ( & V_74 ) ;
}
static void F_104 ( void )
{
unsigned long V_25 = V_81 , V_11 = 0 ;
F_93 ( & V_25 , & V_11 , 0 , 0 ) ;
}
static void F_72 ( void )
{
unsigned long V_25 = V_81 , V_11 = 0 ;
F_93 ( & V_25 , & V_11 , 1 , 0 ) ;
}
static void F_105 ( struct V_34 * V_38 )
{
V_38 -> V_65 |= V_77 ;
F_106 ( ( V_38 -> va_end - V_38 -> va_start ) >> V_78 , & V_71 ) ;
if ( F_63 ( F_107 ( & V_71 ) > F_88 () ) )
F_104 () ;
}
static void F_108 ( struct V_34 * V_38 )
{
F_84 ( V_38 ) ;
F_105 ( V_38 ) ;
}
static void F_109 ( struct V_34 * V_38 )
{
F_110 ( V_38 -> va_start , V_38 -> va_end ) ;
F_108 ( V_38 ) ;
}
static struct V_34 * F_111 ( unsigned long V_10 )
{
struct V_34 * V_38 ;
F_66 ( & V_57 ) ;
V_38 = F_51 ( V_10 ) ;
F_70 ( & V_57 ) ;
return V_38 ;
}
static void F_112 ( unsigned long V_10 )
{
struct V_34 * V_38 ;
V_38 = F_111 ( V_10 ) ;
F_23 ( ! V_38 ) ;
F_109 ( V_38 ) ;
}
static unsigned long F_113 ( unsigned long V_10 )
{
V_10 -= V_67 & ~ ( V_82 - 1 ) ;
V_10 /= V_82 ;
return V_10 ;
}
static void * F_114 ( unsigned long va_start , unsigned long V_83 )
{
unsigned long V_10 ;
V_10 = va_start + ( V_83 << V_78 ) ;
F_23 ( F_113 ( V_10 ) != F_113 ( va_start ) ) ;
return ( void * ) V_10 ;
}
static void * F_115 ( unsigned int V_84 , T_6 V_51 )
{
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_34 * V_38 ;
unsigned long V_89 ;
int V_50 , V_26 ;
void * V_90 ;
V_50 = F_116 () ;
V_88 = F_62 ( sizeof( struct V_87 ) ,
V_51 & V_54 , V_50 ) ;
if ( F_63 ( ! V_88 ) )
return F_64 ( - V_23 ) ;
V_38 = F_59 ( V_82 , V_82 ,
V_67 , V_68 ,
V_50 , V_51 ) ;
if ( F_117 ( V_38 ) ) {
F_75 ( V_88 ) ;
return F_118 ( V_38 ) ;
}
V_26 = F_119 ( V_51 ) ;
if ( F_63 ( V_26 ) ) {
F_75 ( V_88 ) ;
F_83 ( V_38 ) ;
return F_64 ( V_26 ) ;
}
V_90 = F_114 ( V_38 -> va_start , 0 ) ;
F_120 ( & V_88 -> V_91 ) ;
V_88 -> V_38 = V_38 ;
F_23 ( V_92 <= ( 1UL << V_84 ) ) ;
V_88 -> free = V_92 - ( 1UL << V_84 ) ;
V_88 -> V_93 = 0 ;
V_88 -> V_94 = V_92 ;
V_88 -> V_95 = 0 ;
F_121 ( & V_88 -> V_96 ) ;
V_89 = F_113 ( V_38 -> va_start ) ;
F_66 ( & V_97 ) ;
V_26 = F_122 ( & V_98 , V_89 , V_88 ) ;
F_70 ( & V_97 ) ;
F_23 ( V_26 ) ;
F_123 () ;
V_86 = & F_124 ( V_85 ) ;
F_66 ( & V_86 -> V_91 ) ;
F_125 ( & V_88 -> V_96 , & V_86 -> free ) ;
F_70 ( & V_86 -> V_91 ) ;
F_126 ( V_85 ) ;
return V_90 ;
}
static void F_127 ( struct V_87 * V_88 )
{
struct V_87 * V_42 ;
unsigned long V_89 ;
V_89 = F_113 ( V_88 -> V_38 -> va_start ) ;
F_66 ( & V_97 ) ;
V_42 = F_128 ( & V_98 , V_89 ) ;
F_70 ( & V_97 ) ;
F_23 ( V_42 != V_88 ) ;
F_105 ( V_88 -> V_38 ) ;
F_82 ( V_88 , V_70 ) ;
}
static void F_129 ( int V_99 )
{
F_95 ( V_100 ) ;
struct V_87 * V_88 ;
struct V_87 * V_101 ;
struct V_85 * V_86 = & F_130 ( V_85 , V_99 ) ;
F_98 () ;
F_99 (vb, &vbq->free, free_list) {
if ( ! ( V_88 -> free + V_88 -> V_93 == V_92 && V_88 -> V_93 != V_92 ) )
continue;
F_66 ( & V_88 -> V_91 ) ;
if ( V_88 -> free + V_88 -> V_93 == V_92 && V_88 -> V_93 != V_92 ) {
V_88 -> free = 0 ;
V_88 -> V_93 = V_92 ;
V_88 -> V_94 = 0 ;
V_88 -> V_95 = V_92 ;
F_66 ( & V_86 -> V_91 ) ;
F_80 ( & V_88 -> V_96 ) ;
F_70 ( & V_86 -> V_91 ) ;
F_70 ( & V_88 -> V_91 ) ;
F_100 ( & V_88 -> V_100 , & V_100 ) ;
} else
F_70 ( & V_88 -> V_91 ) ;
}
F_101 () ;
F_103 (vb, n_vb, &purge, purge) {
F_131 ( & V_88 -> V_100 ) ;
F_127 ( V_88 ) ;
}
}
static void F_97 ( void )
{
int V_99 ;
F_132 (cpu)
F_129 ( V_99 ) ;
}
static void * F_133 ( unsigned long V_46 , T_6 V_51 )
{
struct V_85 * V_86 ;
struct V_87 * V_88 ;
void * V_90 = NULL ;
unsigned int V_84 ;
F_23 ( F_60 ( V_46 ) ) ;
F_23 ( V_46 > V_15 * V_102 ) ;
if ( F_9 ( V_46 == 0 ) ) {
return NULL ;
}
V_84 = F_134 ( V_46 ) ;
F_98 () ;
V_86 = & F_124 ( V_85 ) ;
F_99 (vb, &vbq->free, free_list) {
unsigned long V_83 ;
F_66 ( & V_88 -> V_91 ) ;
if ( V_88 -> free < ( 1UL << V_84 ) ) {
F_70 ( & V_88 -> V_91 ) ;
continue;
}
V_83 = V_92 - V_88 -> free ;
V_90 = F_114 ( V_88 -> V_38 -> va_start , V_83 ) ;
V_88 -> free -= 1UL << V_84 ;
if ( V_88 -> free == 0 ) {
F_66 ( & V_86 -> V_91 ) ;
F_80 ( & V_88 -> V_96 ) ;
F_70 ( & V_86 -> V_91 ) ;
}
F_70 ( & V_88 -> V_91 ) ;
break;
}
F_126 ( V_85 ) ;
F_101 () ;
if ( ! V_90 )
V_90 = F_115 ( V_84 , V_51 ) ;
return V_90 ;
}
static void F_135 ( const void * V_10 , unsigned long V_46 )
{
unsigned long V_103 ;
unsigned long V_89 ;
unsigned int V_84 ;
struct V_87 * V_88 ;
F_23 ( F_60 ( V_46 ) ) ;
F_23 ( V_46 > V_15 * V_102 ) ;
F_110 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
V_84 = F_134 ( V_46 ) ;
V_103 = ( unsigned long ) V_10 & ( V_82 - 1 ) ;
V_103 >>= V_78 ;
V_89 = F_113 ( ( unsigned long ) V_10 ) ;
F_98 () ;
V_88 = F_136 ( & V_98 , V_89 ) ;
F_101 () ;
F_23 ( ! V_88 ) ;
F_22 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
F_66 ( & V_88 -> V_91 ) ;
V_88 -> V_94 = F_137 ( V_88 -> V_94 , V_103 ) ;
V_88 -> V_95 = F_81 ( V_88 -> V_95 , V_103 + ( 1UL << V_84 ) ) ;
V_88 -> V_93 += 1UL << V_84 ;
if ( V_88 -> V_93 == V_92 ) {
F_23 ( V_88 -> free ) ;
F_70 ( & V_88 -> V_91 ) ;
F_127 ( V_88 ) ;
} else
F_70 ( & V_88 -> V_91 ) ;
}
void F_138 ( void )
{
unsigned long V_25 = V_81 , V_11 = 0 ;
int V_99 ;
int V_104 = 0 ;
if ( F_63 ( ! V_105 ) )
return;
F_132 (cpu) {
struct V_85 * V_86 = & F_130 ( V_85 , V_99 ) ;
struct V_87 * V_88 ;
F_98 () ;
F_99 (vb, &vbq->free, free_list) {
F_66 ( & V_88 -> V_91 ) ;
if ( V_88 -> V_93 ) {
unsigned long va_start = V_88 -> V_38 -> va_start ;
unsigned long V_106 , V_107 ;
V_106 = va_start + ( V_88 -> V_94 << V_78 ) ;
V_107 = va_start + ( V_88 -> V_95 << V_78 ) ;
V_25 = F_137 ( V_106 , V_25 ) ;
V_11 = F_81 ( V_107 , V_11 ) ;
V_104 = 1 ;
}
F_70 ( & V_88 -> V_91 ) ;
}
F_101 () ;
}
F_93 ( & V_25 , & V_11 , 1 , V_104 ) ;
}
void F_139 ( const void * V_108 , unsigned int V_109 )
{
unsigned long V_46 = V_109 << V_78 ;
unsigned long V_10 = ( unsigned long ) V_108 ;
F_23 ( ! V_10 ) ;
F_23 ( V_10 < V_67 ) ;
F_23 ( V_10 > V_68 ) ;
F_23 ( ! F_71 ( V_10 , V_15 ) ) ;
F_140 ( V_108 , V_46 ) ;
F_85 ( V_10 , V_10 + V_46 ) ;
if ( F_141 ( V_109 <= V_102 ) )
F_135 ( V_108 , V_46 ) ;
else
F_112 ( V_10 ) ;
}
void * F_142 ( struct V_20 * * V_21 , unsigned int V_109 , int V_50 , T_5 V_19 )
{
unsigned long V_46 = V_109 << V_78 ;
unsigned long V_10 ;
void * V_108 ;
if ( F_141 ( V_109 <= V_102 ) ) {
V_108 = F_133 ( V_46 , V_110 ) ;
if ( F_117 ( V_108 ) )
return NULL ;
V_10 = ( unsigned long ) V_108 ;
} else {
struct V_34 * V_38 ;
V_38 = F_59 ( V_46 , V_15 ,
V_67 , V_68 , V_50 , V_110 ) ;
if ( F_117 ( V_38 ) )
return NULL ;
V_10 = V_38 -> va_start ;
V_108 = ( void * ) V_10 ;
}
if ( F_36 ( V_10 , V_10 + V_46 , V_19 , V_21 ) < 0 ) {
F_139 ( V_108 , V_109 ) ;
return NULL ;
}
return V_108 ;
}
void T_7 F_143 ( struct V_111 * V_112 )
{
struct V_111 * V_42 , * * V_4 ;
F_23 ( V_105 ) ;
for ( V_4 = & V_113 ; ( V_42 = * V_4 ) != NULL ; V_4 = & V_42 -> V_17 ) {
if ( V_42 -> V_10 >= V_112 -> V_10 ) {
F_23 ( V_42 -> V_10 < V_112 -> V_10 + V_112 -> V_46 ) ;
break;
} else
F_23 ( V_42 -> V_10 + V_42 -> V_46 > V_112 -> V_10 ) ;
}
V_112 -> V_17 = * V_4 ;
* V_4 = V_112 ;
}
void T_7 F_144 ( struct V_111 * V_112 , T_8 V_47 )
{
static T_8 T_9 V_114 ;
unsigned long V_10 ;
V_10 = F_67 ( V_67 + T_9 , V_47 ) ;
T_9 = F_145 ( V_10 + V_112 -> V_46 ) - V_67 ;
V_112 -> V_10 = ( void * ) V_10 ;
F_143 ( V_112 ) ;
}
void T_7 F_146 ( void )
{
struct V_34 * V_38 ;
struct V_111 * V_42 ;
int V_115 ;
F_132 (i) {
struct V_85 * V_86 ;
struct V_3 * V_4 ;
V_86 = & F_130 ( V_85 , V_115 ) ;
F_120 ( & V_86 -> V_91 ) ;
F_121 ( & V_86 -> free ) ;
V_4 = & F_130 ( V_3 , V_115 ) ;
F_147 ( & V_4 -> V_8 ) ;
F_148 ( & V_4 -> V_5 , F_1 ) ;
}
for ( V_42 = V_113 ; V_42 ; V_42 = V_42 -> V_17 ) {
V_38 = F_149 ( sizeof( struct V_34 ) , V_116 ) ;
V_38 -> V_65 = V_117 ;
V_38 -> va_start = ( unsigned long ) V_42 -> V_10 ;
V_38 -> va_end = V_38 -> va_start + V_42 -> V_46 ;
V_38 -> V_112 = V_42 ;
F_53 ( V_38 ) ;
}
V_69 = V_68 ;
V_105 = true ;
}
int F_150 ( unsigned long V_10 , unsigned long V_46 ,
T_5 V_19 , struct V_20 * * V_21 )
{
return F_35 ( V_10 , V_10 + V_46 , V_19 , V_21 ) ;
}
void F_151 ( unsigned long V_10 , unsigned long V_46 )
{
F_22 ( V_10 , V_10 + V_46 ) ;
}
void F_152 ( unsigned long V_10 , unsigned long V_46 )
{
unsigned long V_11 = V_10 + V_46 ;
F_110 ( V_10 , V_11 ) ;
F_22 ( V_10 , V_11 ) ;
F_87 ( V_10 , V_11 ) ;
}
int F_153 ( struct V_111 * V_118 , T_5 V_19 , struct V_20 * * V_21 )
{
unsigned long V_10 = ( unsigned long ) V_118 -> V_10 ;
unsigned long V_11 = V_10 + F_154 ( V_118 ) ;
int V_26 ;
V_26 = F_36 ( V_10 , V_11 , V_19 , V_21 ) ;
return V_26 > 0 ? 0 : V_26 ;
}
static void F_155 ( struct V_111 * V_112 , struct V_34 * V_38 ,
unsigned long V_65 , const void * V_119 )
{
F_66 ( & V_57 ) ;
V_112 -> V_65 = V_65 ;
V_112 -> V_10 = ( void * ) V_38 -> va_start ;
V_112 -> V_46 = V_38 -> va_end - V_38 -> va_start ;
V_112 -> V_119 = V_119 ;
V_38 -> V_112 = V_112 ;
V_38 -> V_65 |= V_117 ;
F_70 ( & V_57 ) ;
}
static void F_156 ( struct V_111 * V_112 )
{
F_157 () ;
V_112 -> V_65 &= ~ V_120 ;
}
static struct V_111 * F_158 ( unsigned long V_46 ,
unsigned long V_47 , unsigned long V_65 , unsigned long V_25 ,
unsigned long V_11 , int V_50 , T_6 V_51 , const void * V_119 )
{
struct V_34 * V_38 ;
struct V_111 * V_118 ;
F_23 ( F_159 () ) ;
if ( V_65 & V_121 )
V_47 = 1ul << F_160 ( int , F_161 ( V_46 ) ,
V_78 , V_122 ) ;
V_46 = F_162 ( V_46 ) ;
if ( F_63 ( ! V_46 ) )
return NULL ;
V_118 = F_163 ( sizeof( * V_118 ) , V_51 & V_54 , V_50 ) ;
if ( F_63 ( ! V_118 ) )
return NULL ;
if ( ! ( V_65 & V_123 ) )
V_46 += V_15 ;
V_38 = F_59 ( V_46 , V_47 , V_25 , V_11 , V_50 , V_51 ) ;
if ( F_117 ( V_38 ) ) {
F_75 ( V_118 ) ;
return NULL ;
}
F_155 ( V_118 , V_38 , V_65 , V_119 ) ;
return V_118 ;
}
struct V_111 * F_164 ( unsigned long V_46 , unsigned long V_65 ,
unsigned long V_25 , unsigned long V_11 )
{
return F_158 ( V_46 , 1 , V_65 , V_25 , V_11 , V_124 ,
V_110 , F_165 ( 0 ) ) ;
}
struct V_111 * F_166 ( unsigned long V_46 , unsigned long V_65 ,
unsigned long V_25 , unsigned long V_11 ,
const void * V_119 )
{
return F_158 ( V_46 , 1 , V_65 , V_25 , V_11 , V_124 ,
V_110 , V_119 ) ;
}
struct V_111 * F_167 ( unsigned long V_46 , unsigned long V_65 )
{
return F_158 ( V_46 , 1 , V_65 , V_67 , V_68 ,
V_124 , V_110 ,
F_165 ( 0 ) ) ;
}
struct V_111 * F_168 ( unsigned long V_46 , unsigned long V_65 ,
const void * V_119 )
{
return F_158 ( V_46 , 1 , V_65 , V_67 , V_68 ,
V_124 , V_110 , V_119 ) ;
}
struct V_111 * F_169 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_111 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_65 & V_117 )
return V_38 -> V_112 ;
return NULL ;
}
struct V_111 * F_170 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_111 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_65 & V_117 ) {
struct V_111 * V_112 = V_38 -> V_112 ;
F_66 ( & V_57 ) ;
V_38 -> V_112 = NULL ;
V_38 -> V_65 &= ~ V_117 ;
F_70 ( & V_57 ) ;
F_85 ( V_38 -> va_start , V_38 -> va_end ) ;
F_171 ( V_112 ) ;
F_109 ( V_38 ) ;
return V_112 ;
}
return NULL ;
}
static void F_5 ( const void * V_10 , int V_125 )
{
struct V_111 * V_118 ;
if ( ! V_10 )
return;
if ( F_172 ( ! F_173 ( V_10 ) , L_3 ,
V_10 ) )
return;
V_118 = F_170 ( V_10 ) ;
if ( F_63 ( ! V_118 ) ) {
F_172 ( 1 , V_126 L_4 ,
V_10 ) ;
return;
}
F_140 ( V_10 , F_154 ( V_118 ) ) ;
F_174 ( V_10 , F_154 ( V_118 ) ) ;
if ( V_125 ) {
int V_115 ;
for ( V_115 = 0 ; V_115 < V_118 -> V_127 ; V_115 ++ ) {
struct V_20 * V_20 = V_118 -> V_21 [ V_115 ] ;
F_23 ( ! V_20 ) ;
F_175 ( V_20 , 0 ) ;
}
F_176 ( V_118 -> V_21 ) ;
}
F_75 ( V_118 ) ;
return;
}
void F_177 ( const void * V_10 )
{
F_23 ( F_178 () ) ;
F_179 ( V_10 ) ;
if ( ! V_10 )
return;
if ( F_63 ( F_159 () ) ) {
struct V_3 * V_4 = F_180 ( & V_3 ) ;
if ( F_181 ( (struct V_6 * ) V_10 , & V_4 -> V_8 ) )
F_182 ( & V_4 -> V_5 ) ;
} else
F_5 ( V_10 , 1 ) ;
}
void F_183 ( const void * V_10 )
{
F_23 ( F_159 () ) ;
F_184 () ;
if ( V_10 )
F_5 ( V_10 , 0 ) ;
}
void * F_185 ( struct V_20 * * V_21 , unsigned int V_109 ,
unsigned long V_65 , T_5 V_19 )
{
struct V_111 * V_118 ;
F_184 () ;
if ( V_109 > V_128 )
return NULL ;
V_118 = F_168 ( ( V_109 << V_78 ) , V_65 ,
F_165 ( 0 ) ) ;
if ( ! V_118 )
return NULL ;
if ( F_153 ( V_118 , V_19 , V_21 ) ) {
F_183 ( V_118 -> V_10 ) ;
return NULL ;
}
return V_118 -> V_10 ;
}
static void * F_186 ( struct V_111 * V_118 , T_6 V_51 ,
T_5 V_19 , int V_50 )
{
const int V_84 = 0 ;
struct V_20 * * V_21 ;
unsigned int V_127 , V_129 , V_115 ;
const T_6 V_130 = ( V_51 & V_54 ) | V_131 ;
const T_6 V_132 = V_51 | V_133 ;
V_127 = F_154 ( V_118 ) >> V_78 ;
V_129 = ( V_127 * sizeof( struct V_20 * ) ) ;
V_118 -> V_127 = V_127 ;
if ( V_129 > V_15 ) {
V_21 = F_187 ( V_129 , 1 , V_130 | V_134 ,
V_135 , V_50 , V_118 -> V_119 ) ;
} else {
V_21 = F_62 ( V_129 , V_130 , V_50 ) ;
}
V_118 -> V_21 = V_21 ;
if ( ! V_118 -> V_21 ) {
F_170 ( V_118 -> V_10 ) ;
F_75 ( V_118 ) ;
return NULL ;
}
for ( V_115 = 0 ; V_115 < V_118 -> V_127 ; V_115 ++ ) {
struct V_20 * V_20 ;
if ( V_50 == V_124 )
V_20 = F_188 ( V_132 , V_84 ) ;
else
V_20 = F_189 ( V_50 , V_132 , V_84 ) ;
if ( F_63 ( ! V_20 ) ) {
V_118 -> V_127 = V_115 ;
goto V_136;
}
V_118 -> V_21 [ V_115 ] = V_20 ;
if ( F_190 ( V_51 ) )
F_191 () ;
}
if ( F_153 ( V_118 , V_19 , V_21 ) )
goto V_136;
return V_118 -> V_10 ;
V_136:
F_192 ( V_51 , V_84 ,
L_5 ,
( V_118 -> V_127 * V_15 ) , V_118 -> V_46 ) ;
F_177 ( V_118 -> V_10 ) ;
return NULL ;
}
void * F_193 ( unsigned long V_46 , unsigned long V_47 ,
unsigned long V_25 , unsigned long V_11 , T_6 V_51 ,
T_5 V_19 , unsigned long V_137 , int V_50 ,
const void * V_119 )
{
struct V_111 * V_118 ;
void * V_10 ;
unsigned long V_138 = V_46 ;
V_46 = F_162 ( V_46 ) ;
if ( ! V_46 || ( V_46 >> V_78 ) > V_128 )
goto V_136;
V_118 = F_158 ( V_46 , V_47 , V_139 | V_120 |
V_137 , V_25 , V_11 , V_50 , V_51 , V_119 ) ;
if ( ! V_118 )
goto V_136;
V_10 = F_186 ( V_118 , V_51 , V_19 , V_50 ) ;
if ( ! V_10 )
return NULL ;
F_156 ( V_118 ) ;
F_194 ( V_10 , V_138 , 2 , V_51 ) ;
return V_10 ;
V_136:
F_192 ( V_51 , 0 ,
L_6 ,
V_138 ) ;
return NULL ;
}
static void * F_187 ( unsigned long V_46 , unsigned long V_47 ,
T_6 V_51 , T_5 V_19 ,
int V_50 , const void * V_119 )
{
return F_193 ( V_46 , V_47 , V_67 , V_68 ,
V_51 , V_19 , 0 , V_50 , V_119 ) ;
}
void * F_195 ( unsigned long V_46 , T_6 V_51 , T_5 V_19 )
{
return F_187 ( V_46 , 1 , V_51 , V_19 , V_124 ,
F_165 ( 0 ) ) ;
}
static inline void * F_196 ( unsigned long V_46 ,
int V_50 , T_6 V_65 )
{
return F_187 ( V_46 , 1 , V_65 , V_135 ,
V_50 , F_165 ( 0 ) ) ;
}
void * F_197 ( unsigned long V_46 )
{
return F_196 ( V_46 , V_124 ,
V_110 | V_134 ) ;
}
void * F_198 ( unsigned long V_46 )
{
return F_196 ( V_46 , V_124 ,
V_110 | V_134 | V_131 ) ;
}
void * F_199 ( unsigned long V_46 )
{
struct V_111 * V_118 ;
void * V_27 ;
V_27 = F_187 ( V_46 , V_140 ,
V_110 | V_134 | V_131 ,
V_135 , V_124 ,
F_165 ( 0 ) ) ;
if ( V_27 ) {
V_118 = F_169 ( V_27 ) ;
V_118 -> V_65 |= V_141 ;
}
return V_27 ;
}
void * F_200 ( unsigned long V_46 , int V_50 )
{
return F_187 ( V_46 , 1 , V_110 | V_134 , V_135 ,
V_50 , F_165 ( 0 ) ) ;
}
void * F_201 ( unsigned long V_46 , int V_50 )
{
return F_196 ( V_46 , V_50 ,
V_110 | V_134 | V_131 ) ;
}
void * F_202 ( unsigned long V_46 )
{
return F_187 ( V_46 , 1 , V_110 | V_134 , V_142 ,
V_124 , F_165 ( 0 ) ) ;
}
void * F_203 ( unsigned long V_46 )
{
return F_187 ( V_46 , 1 , V_143 , V_135 ,
V_124 , F_165 ( 0 ) ) ;
}
void * F_204 ( unsigned long V_46 )
{
struct V_111 * V_118 ;
void * V_27 ;
V_27 = F_187 ( V_46 , 1 , V_143 | V_131 , V_135 ,
V_124 , F_165 ( 0 ) ) ;
if ( V_27 ) {
V_118 = F_169 ( V_27 ) ;
V_118 -> V_65 |= V_141 ;
}
return V_27 ;
}
static int F_205 ( char * V_144 , char * V_10 , unsigned long V_109 )
{
struct V_20 * V_4 ;
int V_145 = 0 ;
while ( V_109 ) {
unsigned long V_103 , V_146 ;
V_103 = F_60 ( V_10 ) ;
V_146 = V_15 - V_103 ;
if ( V_146 > V_109 )
V_146 = V_109 ;
V_4 = F_41 ( V_10 ) ;
if ( V_4 ) {
void * V_147 = F_206 ( V_4 ) ;
memcpy ( V_144 , V_147 + V_103 , V_146 ) ;
F_207 ( V_147 ) ;
} else
memset ( V_144 , 0 , V_146 ) ;
V_10 += V_146 ;
V_144 += V_146 ;
V_145 += V_146 ;
V_109 -= V_146 ;
}
return V_145 ;
}
static int F_208 ( char * V_144 , char * V_10 , unsigned long V_109 )
{
struct V_20 * V_4 ;
int V_145 = 0 ;
while ( V_109 ) {
unsigned long V_103 , V_146 ;
V_103 = F_60 ( V_10 ) ;
V_146 = V_15 - V_103 ;
if ( V_146 > V_109 )
V_146 = V_109 ;
V_4 = F_41 ( V_10 ) ;
if ( V_4 ) {
void * V_147 = F_206 ( V_4 ) ;
memcpy ( V_147 + V_103 , V_144 , V_146 ) ;
F_207 ( V_147 ) ;
}
V_10 += V_146 ;
V_144 += V_146 ;
V_145 += V_146 ;
V_109 -= V_146 ;
}
return V_145 ;
}
long F_209 ( char * V_144 , char * V_10 , unsigned long V_109 )
{
struct V_34 * V_38 ;
struct V_111 * V_112 ;
char * V_90 , * V_148 = V_144 ;
unsigned long V_149 = V_109 ;
unsigned long V_36 ;
if ( ( unsigned long ) V_10 + V_109 < V_109 )
V_109 = - ( unsigned long ) V_10 ;
F_66 ( & V_57 ) ;
F_210 (va, &vmap_area_list, list) {
if ( ! V_109 )
break;
if ( ! ( V_38 -> V_65 & V_117 ) )
continue;
V_112 = V_38 -> V_112 ;
V_90 = ( char * ) V_112 -> V_10 ;
if ( V_10 >= V_90 + F_154 ( V_112 ) )
continue;
while ( V_10 < V_90 ) {
if ( V_109 == 0 )
goto V_150;
* V_144 = '\0' ;
V_144 ++ ;
V_10 ++ ;
V_109 -- ;
}
V_36 = V_90 + F_154 ( V_112 ) - V_10 ;
if ( V_36 > V_109 )
V_36 = V_109 ;
if ( ! ( V_112 -> V_65 & V_121 ) )
F_205 ( V_144 , V_10 , V_36 ) ;
else
memset ( V_144 , 0 , V_36 ) ;
V_144 += V_36 ;
V_10 += V_36 ;
V_109 -= V_36 ;
}
V_150:
F_70 ( & V_57 ) ;
if ( V_144 == V_148 )
return 0 ;
if ( V_144 != V_148 + V_149 )
memset ( V_144 , 0 , V_149 - ( V_144 - V_148 ) ) ;
return V_149 ;
}
long F_211 ( char * V_144 , char * V_10 , unsigned long V_109 )
{
struct V_34 * V_38 ;
struct V_111 * V_112 ;
char * V_90 ;
unsigned long V_36 , V_149 ;
int V_145 = 0 ;
if ( ( unsigned long ) V_10 + V_109 < V_109 )
V_109 = - ( unsigned long ) V_10 ;
V_149 = V_109 ;
F_66 ( & V_57 ) ;
F_210 (va, &vmap_area_list, list) {
if ( ! V_109 )
break;
if ( ! ( V_38 -> V_65 & V_117 ) )
continue;
V_112 = V_38 -> V_112 ;
V_90 = ( char * ) V_112 -> V_10 ;
if ( V_10 >= V_90 + F_154 ( V_112 ) )
continue;
while ( V_10 < V_90 ) {
if ( V_109 == 0 )
goto V_150;
V_144 ++ ;
V_10 ++ ;
V_109 -- ;
}
V_36 = V_90 + F_154 ( V_112 ) - V_10 ;
if ( V_36 > V_109 )
V_36 = V_109 ;
if ( ! ( V_112 -> V_65 & V_121 ) ) {
F_208 ( V_144 , V_10 , V_36 ) ;
V_145 ++ ;
}
V_144 += V_36 ;
V_10 += V_36 ;
V_109 -= V_36 ;
}
V_150:
F_70 ( & V_57 ) ;
if ( ! V_145 )
return 0 ;
return V_149 ;
}
int F_212 ( struct V_151 * V_152 , unsigned long V_153 ,
void * V_154 , unsigned long V_46 )
{
struct V_111 * V_118 ;
V_46 = F_162 ( V_46 ) ;
if ( ! F_173 ( V_153 ) || ! F_173 ( V_154 ) )
return - V_155 ;
V_118 = F_169 ( V_154 ) ;
if ( ! V_118 )
return - V_155 ;
if ( ! ( V_118 -> V_65 & V_141 ) )
return - V_155 ;
if ( V_154 + V_46 > V_118 -> V_10 + V_118 -> V_46 )
return - V_155 ;
do {
struct V_20 * V_20 = F_41 ( V_154 ) ;
int V_27 ;
V_27 = F_213 ( V_152 , V_153 , V_20 ) ;
if ( V_27 )
return V_27 ;
V_153 += V_15 ;
V_154 += V_15 ;
V_46 -= V_15 ;
} while ( V_46 > 0 );
V_152 -> V_137 |= V_156 | V_157 ;
return 0 ;
}
int F_214 ( struct V_151 * V_152 , void * V_10 ,
unsigned long V_158 )
{
return F_212 ( V_152 , V_152 -> V_159 ,
V_10 + ( V_158 << V_78 ) ,
V_152 -> V_160 - V_152 -> V_159 ) ;
}
void __weak F_215 ( void )
{
}
static int F_216 ( T_2 * V_12 , T_10 V_161 , unsigned long V_10 , void * V_162 )
{
T_2 * * * V_4 = V_162 ;
if ( V_4 ) {
* ( * V_4 ) = V_12 ;
( * V_4 ) ++ ;
}
return 0 ;
}
struct V_111 * F_217 ( T_8 V_46 , T_2 * * V_163 )
{
struct V_111 * V_118 ;
V_118 = F_168 ( V_46 , V_121 ,
F_165 ( 0 ) ) ;
if ( V_118 == NULL )
return NULL ;
if ( F_218 ( & V_14 , ( unsigned long ) V_118 -> V_10 ,
V_46 , F_216 , V_163 ? & V_163 : NULL ) ) {
F_219 ( V_118 ) ;
return NULL ;
}
return V_118 ;
}
void F_219 ( struct V_111 * V_118 )
{
struct V_111 * V_27 ;
V_27 = F_170 ( V_118 -> V_10 ) ;
F_23 ( V_27 != V_118 ) ;
F_75 ( V_118 ) ;
}
static struct V_34 * F_220 ( struct V_35 * V_36 )
{
return V_36 ? F_52 ( V_36 , struct V_34 , V_35 ) : NULL ;
}
static bool F_221 ( unsigned long V_11 ,
struct V_34 * * V_164 ,
struct V_34 * * V_165 )
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
* V_164 = V_38 ;
* V_165 = F_220 ( F_57 ( & ( * V_164 ) -> V_35 ) ) ;
} else {
* V_165 = V_38 ;
* V_164 = F_220 ( F_222 ( & ( * V_165 ) -> V_35 ) ) ;
}
return true ;
}
static unsigned long F_223 ( struct V_34 * * V_164 ,
struct V_34 * * V_165 ,
unsigned long V_47 )
{
const unsigned long V_166 = V_68 & ~ ( V_47 - 1 ) ;
unsigned long V_10 ;
if ( * V_164 )
V_10 = F_137 ( ( * V_164 ) -> va_start & ~ ( V_47 - 1 ) , V_166 ) ;
else
V_10 = V_166 ;
while ( * V_165 && ( * V_165 ) -> va_end > V_10 ) {
* V_164 = * V_165 ;
* V_165 = F_220 ( F_57 ( & ( * V_164 ) -> V_35 ) ) ;
}
return V_10 ;
}
struct V_111 * * F_224 ( const unsigned long * V_167 ,
const T_8 * V_168 , int V_169 ,
T_8 V_47 )
{
const unsigned long V_170 = F_67 ( V_67 , V_47 ) ;
const unsigned long V_166 = V_68 & ~ ( V_47 - 1 ) ;
struct V_34 * * V_171 , * V_44 , * V_17 ;
struct V_111 * * V_172 ;
int V_118 , V_173 , V_174 , V_175 ;
unsigned long V_176 , V_25 , V_11 , V_177 ;
bool V_52 = false ;
F_23 ( F_60 ( V_47 ) || ! F_61 ( V_47 ) ) ;
for ( V_174 = 0 , V_118 = 0 ; V_118 < V_169 ; V_118 ++ ) {
V_25 = V_167 [ V_118 ] ;
V_11 = V_25 + V_168 [ V_118 ] ;
F_23 ( ! F_71 ( V_167 [ V_118 ] , V_47 ) ) ;
F_23 ( ! F_71 ( V_168 [ V_118 ] , V_47 ) ) ;
if ( V_25 > V_167 [ V_174 ] )
V_174 = V_118 ;
for ( V_173 = 0 ; V_173 < V_169 ; V_173 ++ ) {
unsigned long V_178 = V_167 [ V_173 ] ;
unsigned long V_179 = V_178 + V_168 [ V_173 ] ;
if ( V_173 == V_118 )
continue;
F_23 ( V_178 >= V_25 && V_178 < V_11 ) ;
F_23 ( V_179 <= V_11 && V_179 > V_25 ) ;
}
}
V_177 = V_167 [ V_174 ] + V_168 [ V_174 ] ;
if ( V_166 - V_170 < V_177 ) {
F_9 ( true ) ;
return NULL ;
}
V_172 = F_225 ( V_169 , sizeof( V_172 [ 0 ] ) , V_110 ) ;
V_171 = F_225 ( V_169 , sizeof( V_171 [ 0 ] ) , V_110 ) ;
if ( ! V_171 || ! V_172 )
goto V_180;
for ( V_118 = 0 ; V_118 < V_169 ; V_118 ++ ) {
V_171 [ V_118 ] = F_149 ( sizeof( struct V_34 ) , V_110 ) ;
V_172 [ V_118 ] = F_149 ( sizeof( struct V_111 ) , V_110 ) ;
if ( ! V_171 [ V_118 ] || ! V_172 [ V_118 ] )
goto V_181;
}
V_56:
F_66 ( & V_57 ) ;
V_118 = V_175 = V_174 ;
V_25 = V_167 [ V_118 ] ;
V_11 = V_25 + V_168 [ V_118 ] ;
if ( ! F_221 ( V_69 , & V_17 , & V_44 ) ) {
V_176 = V_166 - V_177 ;
goto V_64;
}
V_176 = F_223 ( & V_17 , & V_44 , V_47 ) - V_11 ;
while ( true ) {
F_23 ( V_17 && V_17 -> va_end <= V_176 + V_11 ) ;
F_23 ( V_44 && V_44 -> va_end > V_176 + V_11 ) ;
if ( V_176 + V_177 < V_170 + V_177 ) {
F_70 ( & V_57 ) ;
if ( ! V_52 ) {
F_72 () ;
V_52 = true ;
goto V_56;
}
goto V_181;
}
if ( V_17 && V_17 -> va_start < V_176 + V_11 ) {
V_176 = F_223 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_175 = V_118 ;
continue;
}
if ( V_44 && V_44 -> va_end > V_176 + V_25 ) {
V_17 = V_44 ;
V_44 = F_220 ( F_57 ( & V_17 -> V_35 ) ) ;
V_176 = F_223 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_175 = V_118 ;
continue;
}
V_118 = ( V_118 + V_169 - 1 ) % V_169 ;
if ( V_118 == V_175 )
break;
V_25 = V_167 [ V_118 ] ;
V_11 = V_25 + V_168 [ V_118 ] ;
F_221 ( V_176 + V_11 , & V_17 , & V_44 ) ;
}
V_64:
for ( V_118 = 0 ; V_118 < V_169 ; V_118 ++ ) {
struct V_34 * V_38 = V_171 [ V_118 ] ;
V_38 -> va_start = V_176 + V_167 [ V_118 ] ;
V_38 -> va_end = V_38 -> va_start + V_168 [ V_118 ] ;
F_53 ( V_38 ) ;
}
V_69 = V_176 + V_167 [ V_174 ] ;
F_70 ( & V_57 ) ;
for ( V_118 = 0 ; V_118 < V_169 ; V_118 ++ )
F_155 ( V_172 [ V_118 ] , V_171 [ V_118 ] , V_139 ,
F_224 ) ;
F_75 ( V_171 ) ;
return V_172 ;
V_181:
for ( V_118 = 0 ; V_118 < V_169 ; V_118 ++ ) {
F_75 ( V_171 [ V_118 ] ) ;
F_75 ( V_172 [ V_118 ] ) ;
}
V_180:
F_75 ( V_171 ) ;
F_75 ( V_172 ) ;
return NULL ;
}
void F_226 ( struct V_111 * * V_172 , int V_169 )
{
int V_115 ;
for ( V_115 = 0 ; V_115 < V_169 ; V_115 ++ )
F_219 ( V_172 [ V_115 ] ) ;
F_75 ( V_172 ) ;
}
static void * F_227 ( struct V_182 * V_183 , T_11 * V_184 )
__acquires( &vmap_area_lock
static void * F_228 ( struct V_182 * V_183 , void * V_4 , T_11 * V_184 )
{
struct V_34 * V_38 = V_4 , * V_17 ;
++ * V_184 ;
V_17 = F_69 ( V_38 , V_8 ) ;
if ( & V_17 -> V_8 != & V_45 )
return V_17 ;
return NULL ;
}
static void F_229 ( struct V_182 * V_183 , void * V_4 )
__releases( &vmap_area_lock
static void F_230 ( struct V_182 * V_183 , struct V_111 * V_185 )
{
if ( F_231 ( V_186 ) ) {
unsigned int V_22 , * V_187 = V_183 -> V_188 ;
if ( ! V_187 )
return;
if ( V_185 -> V_65 & V_120 )
return;
F_232 () ;
memset ( V_187 , 0 , V_189 * sizeof( unsigned int ) ) ;
for ( V_22 = 0 ; V_22 < V_185 -> V_127 ; V_22 ++ )
V_187 [ F_233 ( V_185 -> V_21 [ V_22 ] ) ] ++ ;
F_234 (nr, N_HIGH_MEMORY)
if ( V_187 [ V_22 ] )
F_235 ( V_183 , L_7 , V_22 , V_187 [ V_22 ] ) ;
}
}
static int F_236 ( struct V_182 * V_183 , void * V_4 )
{
struct V_34 * V_38 = V_4 ;
struct V_111 * V_185 ;
if ( ! ( V_38 -> V_65 & V_117 ) )
return 0 ;
V_185 = V_38 -> V_112 ;
F_235 ( V_183 , L_8 ,
V_185 -> V_10 , V_185 -> V_10 + V_185 -> V_46 , V_185 -> V_46 ) ;
if ( V_185 -> V_119 )
F_235 ( V_183 , L_9 , V_185 -> V_119 ) ;
if ( V_185 -> V_127 )
F_235 ( V_183 , L_10 , V_185 -> V_127 ) ;
if ( V_185 -> V_190 )
F_235 ( V_183 , L_11 , ( unsigned long long ) V_185 -> V_190 ) ;
if ( V_185 -> V_65 & V_121 )
F_237 ( V_183 , L_12 ) ;
if ( V_185 -> V_65 & V_139 )
F_237 ( V_183 , L_13 ) ;
if ( V_185 -> V_65 & V_191 )
F_237 ( V_183 , L_14 ) ;
if ( V_185 -> V_65 & V_141 )
F_237 ( V_183 , L_15 ) ;
if ( F_40 ( V_185 -> V_21 ) )
F_237 ( V_183 , L_16 ) ;
F_230 ( V_183 , V_185 ) ;
F_238 ( V_183 , '\n' ) ;
return 0 ;
}
static int F_239 ( struct V_192 * V_192 , struct V_193 * V_193 )
{
if ( F_231 ( V_186 ) )
return F_240 ( V_193 , & V_194 ,
V_189 * sizeof( unsigned int ) ) ;
else
return F_241 ( V_193 , & V_194 ) ;
}
static int T_7 F_242 ( void )
{
F_243 ( L_17 , V_195 , NULL , & V_196 ) ;
return 0 ;
}
