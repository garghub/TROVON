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
F_6 ( V_9 , V_10 , V_17 ) ;
} while ( V_9 ++ , V_10 = V_17 , V_10 != V_11 );
}
static void F_16 ( T_4 * V_18 , unsigned long V_10 , unsigned long V_11 )
{
T_3 * V_16 ;
unsigned long V_17 ;
V_16 = F_17 ( V_18 , V_10 ) ;
do {
V_17 = F_18 ( V_10 , V_11 ) ;
if ( F_19 ( V_16 ) )
continue;
F_12 ( V_16 , V_10 , V_17 ) ;
} while ( V_16 ++ , V_10 = V_17 , V_10 != V_11 );
}
static void F_20 ( unsigned long V_10 , unsigned long V_11 )
{
T_4 * V_18 ;
unsigned long V_17 ;
F_21 ( V_10 >= V_11 ) ;
V_18 = F_22 ( V_10 ) ;
do {
V_17 = F_23 ( V_10 , V_11 ) ;
if ( F_24 ( V_18 ) )
continue;
F_16 ( V_18 , V_10 , V_17 ) ;
} while ( V_18 ++ , V_10 = V_17 , V_10 != V_11 );
}
static int F_25 ( T_1 * V_9 , unsigned long V_10 ,
unsigned long V_11 , T_5 V_19 , struct V_20 * * V_21 , int * V_22 )
{
T_2 * V_12 ;
V_12 = F_26 ( V_9 , V_10 ) ;
if ( ! V_12 )
return - V_23 ;
do {
struct V_20 * V_20 = V_21 [ * V_22 ] ;
if ( F_9 ( ! F_10 ( * V_12 ) ) )
return - V_24 ;
if ( F_9 ( ! V_20 ) )
return - V_23 ;
F_27 ( & V_14 , V_10 , V_12 , F_28 ( V_20 , V_19 ) ) ;
( * V_22 ) ++ ;
} while ( V_12 ++ , V_10 += V_15 , V_10 != V_11 );
return 0 ;
}
static int F_29 ( T_3 * V_16 , unsigned long V_10 ,
unsigned long V_11 , T_5 V_19 , struct V_20 * * V_21 , int * V_22 )
{
T_1 * V_9 ;
unsigned long V_17 ;
V_9 = F_30 ( & V_14 , V_16 , V_10 ) ;
if ( ! V_9 )
return - V_23 ;
do {
V_17 = F_14 ( V_10 , V_11 ) ;
if ( F_25 ( V_9 , V_10 , V_17 , V_19 , V_21 , V_22 ) )
return - V_23 ;
} while ( V_9 ++ , V_10 = V_17 , V_10 != V_11 );
return 0 ;
}
static int F_31 ( T_4 * V_18 , unsigned long V_10 ,
unsigned long V_11 , T_5 V_19 , struct V_20 * * V_21 , int * V_22 )
{
T_3 * V_16 ;
unsigned long V_17 ;
V_16 = F_32 ( & V_14 , V_18 , V_10 ) ;
if ( ! V_16 )
return - V_23 ;
do {
V_17 = F_18 ( V_10 , V_11 ) ;
if ( F_29 ( V_16 , V_10 , V_17 , V_19 , V_21 , V_22 ) )
return - V_23 ;
} while ( V_16 ++ , V_10 = V_17 , V_10 != V_11 );
return 0 ;
}
static int F_33 ( unsigned long V_25 , unsigned long V_11 ,
T_5 V_19 , struct V_20 * * V_21 )
{
T_4 * V_18 ;
unsigned long V_17 ;
unsigned long V_10 = V_25 ;
int V_26 = 0 ;
int V_22 = 0 ;
F_21 ( V_10 >= V_11 ) ;
V_18 = F_22 ( V_10 ) ;
do {
V_17 = F_23 ( V_10 , V_11 ) ;
V_26 = F_31 ( V_18 , V_10 , V_17 , V_19 , V_21 , & V_22 ) ;
if ( V_26 )
return V_26 ;
} while ( V_18 ++ , V_10 = V_17 , V_10 != V_11 );
return V_22 ;
}
static int F_34 ( unsigned long V_25 , unsigned long V_11 ,
T_5 V_19 , struct V_20 * * V_21 )
{
int V_27 ;
V_27 = F_33 ( V_25 , V_11 , V_19 , V_21 ) ;
F_35 ( V_25 , V_11 ) ;
return V_27 ;
}
int F_36 ( const void * V_28 )
{
#if F_37 ( V_29 ) && F_37 ( V_30 )
unsigned long V_10 = ( unsigned long ) V_28 ;
if ( V_10 >= V_30 && V_10 < V_31 )
return 1 ;
#endif
return F_38 ( V_28 ) ;
}
struct V_20 * F_39 ( const void * V_32 )
{
unsigned long V_10 = ( unsigned long ) V_32 ;
struct V_20 * V_20 = NULL ;
T_4 * V_18 = F_22 ( V_10 ) ;
F_40 ( ! F_36 ( V_32 ) ) ;
if ( ! F_41 ( * V_18 ) ) {
T_3 * V_16 = F_17 ( V_18 , V_10 ) ;
if ( ! F_42 ( * V_16 ) ) {
T_1 * V_9 = F_13 ( V_16 , V_10 ) ;
if ( ! F_43 ( * V_9 ) ) {
T_2 * V_33 , V_12 ;
V_33 = F_44 ( V_9 , V_10 ) ;
V_12 = * V_33 ;
if ( F_11 ( V_12 ) )
V_20 = F_45 ( V_12 ) ;
F_46 ( V_33 ) ;
}
}
}
return V_20 ;
}
unsigned long F_47 ( const void * V_32 )
{
return F_48 ( F_39 ( V_32 ) ) ;
}
static struct V_34 * F_49 ( unsigned long V_10 )
{
struct V_35 * V_36 = V_37 . V_35 ;
while ( V_36 ) {
struct V_34 * V_38 ;
V_38 = F_50 ( V_36 , struct V_34 , V_35 ) ;
if ( V_10 < V_38 -> va_start )
V_36 = V_36 -> V_39 ;
else if ( V_10 >= V_38 -> va_end )
V_36 = V_36 -> V_40 ;
else
return V_38 ;
}
return NULL ;
}
static void F_51 ( struct V_34 * V_38 )
{
struct V_35 * * V_4 = & V_37 . V_35 ;
struct V_35 * V_41 = NULL ;
struct V_35 * V_42 ;
while ( * V_4 ) {
struct V_34 * V_43 ;
V_41 = * V_4 ;
V_43 = F_50 ( V_41 , struct V_34 , V_35 ) ;
if ( V_38 -> va_start < V_43 -> va_end )
V_4 = & ( * V_4 ) -> V_39 ;
else if ( V_38 -> va_end > V_43 -> va_start )
V_4 = & ( * V_4 ) -> V_40 ;
else
F_52 () ;
}
F_53 ( & V_38 -> V_35 , V_41 , V_4 ) ;
F_54 ( & V_38 -> V_35 , & V_37 ) ;
V_42 = F_55 ( & V_38 -> V_35 ) ;
if ( V_42 ) {
struct V_34 * V_44 ;
V_44 = F_50 ( V_42 , struct V_34 , V_35 ) ;
F_56 ( & V_38 -> V_8 , & V_44 -> V_8 ) ;
} else
F_56 ( & V_38 -> V_8 , & V_45 ) ;
}
static struct V_34 * F_57 ( unsigned long V_46 ,
unsigned long V_47 ,
unsigned long V_48 , unsigned long V_49 ,
int V_50 , T_6 V_51 )
{
struct V_34 * V_38 ;
struct V_35 * V_36 ;
unsigned long V_10 ;
int V_52 = 0 ;
struct V_34 * V_53 ;
F_21 ( ! V_46 ) ;
F_21 ( V_46 & ~ V_54 ) ;
F_21 ( ! F_58 ( V_47 ) ) ;
V_38 = F_59 ( sizeof( struct V_34 ) ,
V_51 & V_55 , V_50 ) ;
if ( F_60 ( ! V_38 ) )
return F_61 ( - V_23 ) ;
F_62 ( & V_38 -> V_35 , V_56 , V_51 & V_55 ) ;
V_57:
F_63 ( & V_58 ) ;
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
V_53 = F_50 ( V_59 , struct V_34 , V_35 ) ;
V_10 = F_64 ( V_53 -> va_end , V_47 ) ;
if ( V_10 < V_48 )
goto V_63;
if ( V_10 + V_46 < V_10 )
goto V_64;
} else {
V_10 = F_64 ( V_48 , V_47 ) ;
if ( V_10 + V_46 < V_10 )
goto V_64;
V_36 = V_37 . V_35 ;
V_53 = NULL ;
while ( V_36 ) {
struct V_34 * V_42 ;
V_42 = F_50 ( V_36 , struct V_34 , V_35 ) ;
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
V_10 = F_64 ( V_53 -> va_end , V_47 ) ;
if ( V_10 + V_46 < V_10 )
goto V_64;
if ( F_65 ( & V_53 -> V_8 , & V_45 ) )
goto V_65;
V_53 = F_66 ( V_53 -> V_8 . V_17 ,
struct V_34 , V_8 ) ;
}
V_65:
if ( V_10 + V_46 > V_49 )
goto V_64;
V_38 -> va_start = V_10 ;
V_38 -> va_end = V_10 + V_46 ;
V_38 -> V_66 = 0 ;
F_51 ( V_38 ) ;
V_59 = & V_38 -> V_35 ;
F_67 ( & V_58 ) ;
F_21 ( V_38 -> va_start & ( V_47 - 1 ) ) ;
F_21 ( V_38 -> va_start < V_48 ) ;
F_21 ( V_38 -> va_end > V_49 ) ;
return V_38 ;
V_64:
F_67 ( & V_58 ) ;
if ( ! V_52 ) {
F_68 () ;
V_52 = 1 ;
goto V_57;
}
if ( F_69 () )
F_70 ( L_1
L_2 , V_46 ) ;
F_71 ( V_38 ) ;
return F_61 ( - V_24 ) ;
}
static void F_72 ( struct V_34 * V_38 )
{
F_21 ( F_73 ( & V_38 -> V_35 ) ) ;
if ( V_59 ) {
if ( V_38 -> va_end < V_61 ) {
V_59 = NULL ;
} else {
struct V_34 * V_67 ;
V_67 = F_50 ( V_59 , struct V_34 , V_35 ) ;
if ( V_38 -> va_start <= V_67 -> va_start ) {
V_59 = F_55 ( & V_38 -> V_35 ) ;
}
}
}
F_74 ( & V_38 -> V_35 , & V_37 ) ;
F_75 ( & V_38 -> V_35 ) ;
F_76 ( & V_38 -> V_8 ) ;
if ( V_38 -> va_end > V_68 && V_38 -> va_end <= V_69 )
V_70 = F_77 ( V_70 , V_38 -> va_end ) ;
F_78 ( V_38 , V_71 ) ;
}
static void F_79 ( struct V_34 * V_38 )
{
F_63 ( & V_58 ) ;
F_72 ( V_38 ) ;
F_67 ( & V_58 ) ;
}
static void F_80 ( struct V_34 * V_38 )
{
F_20 ( V_38 -> va_start , V_38 -> va_end ) ;
}
static void F_81 ( unsigned long V_25 , unsigned long V_11 )
{
#ifdef F_82
F_20 ( V_25 , V_11 ) ;
F_83 ( V_25 , V_11 ) ;
#endif
}
static unsigned long F_84 ( void )
{
unsigned int log ;
log = F_85 ( F_86 () ) ;
return log * ( 32UL * 1024 * 1024 / V_15 ) ;
}
void F_87 ( void )
{
F_88 ( & V_72 , F_84 () + 1 ) ;
}
static void F_89 ( unsigned long * V_25 , unsigned long * V_11 ,
int V_73 , int V_74 )
{
static F_90 ( V_75 ) ;
F_91 ( V_76 ) ;
struct V_34 * V_38 ;
struct V_34 * V_77 ;
int V_22 = 0 ;
if ( ! V_73 && ! V_74 ) {
if ( ! F_92 ( & V_75 ) )
return;
} else
F_63 ( & V_75 ) ;
if ( V_73 )
F_93 () ;
F_94 () ;
F_95 (va, &vmap_area_list, list) {
if ( V_38 -> V_66 & V_78 ) {
if ( V_38 -> va_start < * V_25 )
* V_25 = V_38 -> va_start ;
if ( V_38 -> va_end > * V_11 )
* V_11 = V_38 -> va_end ;
V_22 += ( V_38 -> va_end - V_38 -> va_start ) >> V_79 ;
F_96 ( & V_38 -> V_80 , & V_76 ) ;
V_38 -> V_66 |= V_81 ;
V_38 -> V_66 &= ~ V_78 ;
}
}
F_97 () ;
if ( V_22 )
F_98 ( V_22 , & V_72 ) ;
if ( V_22 || V_74 )
F_83 ( * V_25 , * V_11 ) ;
if ( V_22 ) {
F_63 ( & V_58 ) ;
F_99 (va, n_va, &valist, purge_list)
F_72 ( V_38 ) ;
F_67 ( & V_58 ) ;
}
F_67 ( & V_75 ) ;
}
static void F_100 ( void )
{
unsigned long V_25 = V_82 , V_11 = 0 ;
F_89 ( & V_25 , & V_11 , 0 , 0 ) ;
}
static void F_68 ( void )
{
unsigned long V_25 = V_82 , V_11 = 0 ;
F_89 ( & V_25 , & V_11 , 1 , 0 ) ;
}
static void F_101 ( struct V_34 * V_38 )
{
V_38 -> V_66 |= V_78 ;
F_102 ( ( V_38 -> va_end - V_38 -> va_start ) >> V_79 , & V_72 ) ;
if ( F_60 ( F_103 ( & V_72 ) > F_84 () ) )
F_100 () ;
}
static void F_104 ( struct V_34 * V_38 )
{
F_80 ( V_38 ) ;
F_101 ( V_38 ) ;
}
static void F_105 ( struct V_34 * V_38 )
{
F_106 ( V_38 -> va_start , V_38 -> va_end ) ;
F_104 ( V_38 ) ;
}
static struct V_34 * F_107 ( unsigned long V_10 )
{
struct V_34 * V_38 ;
F_63 ( & V_58 ) ;
V_38 = F_49 ( V_10 ) ;
F_67 ( & V_58 ) ;
return V_38 ;
}
static void F_108 ( unsigned long V_10 )
{
struct V_34 * V_38 ;
V_38 = F_107 ( V_10 ) ;
F_21 ( ! V_38 ) ;
F_105 ( V_38 ) ;
}
static unsigned long F_109 ( unsigned long V_10 )
{
V_10 -= V_68 & ~ ( V_83 - 1 ) ;
V_10 /= V_83 ;
return V_10 ;
}
static struct V_84 * F_110 ( T_6 V_51 )
{
struct V_85 * V_86 ;
struct V_84 * V_87 ;
struct V_34 * V_38 ;
unsigned long V_88 ;
int V_50 , V_26 ;
V_50 = F_111 () ;
V_87 = F_59 ( sizeof( struct V_84 ) ,
V_51 & V_55 , V_50 ) ;
if ( F_60 ( ! V_87 ) )
return F_61 ( - V_23 ) ;
V_38 = F_57 ( V_83 , V_83 ,
V_68 , V_69 ,
V_50 , V_51 ) ;
if ( F_112 ( V_38 ) ) {
F_71 ( V_87 ) ;
return F_113 ( V_38 ) ;
}
V_26 = F_114 ( V_51 ) ;
if ( F_60 ( V_26 ) ) {
F_71 ( V_87 ) ;
F_79 ( V_38 ) ;
return F_61 ( V_26 ) ;
}
F_115 ( & V_87 -> V_89 ) ;
V_87 -> V_38 = V_38 ;
V_87 -> free = V_90 ;
V_87 -> V_91 = 0 ;
F_116 ( V_87 -> V_92 , V_90 ) ;
F_117 ( & V_87 -> V_93 ) ;
V_88 = F_109 ( V_38 -> va_start ) ;
F_63 ( & V_94 ) ;
V_26 = F_118 ( & V_95 , V_88 , V_87 ) ;
F_67 ( & V_94 ) ;
F_21 ( V_26 ) ;
F_119 () ;
V_86 = & F_120 ( V_85 ) ;
F_63 ( & V_86 -> V_89 ) ;
F_56 ( & V_87 -> V_93 , & V_86 -> free ) ;
F_67 ( & V_86 -> V_89 ) ;
F_121 ( V_85 ) ;
return V_87 ;
}
static void F_122 ( struct V_84 * V_87 )
{
struct V_84 * V_42 ;
unsigned long V_88 ;
V_88 = F_109 ( V_87 -> V_38 -> va_start ) ;
F_63 ( & V_94 ) ;
V_42 = F_123 ( & V_95 , V_88 ) ;
F_67 ( & V_94 ) ;
F_21 ( V_42 != V_87 ) ;
F_101 ( V_87 -> V_38 ) ;
F_78 ( V_87 , V_71 ) ;
}
static void F_124 ( int V_96 )
{
F_91 ( V_97 ) ;
struct V_84 * V_87 ;
struct V_84 * V_98 ;
struct V_85 * V_86 = & F_125 ( V_85 , V_96 ) ;
F_94 () ;
F_95 (vb, &vbq->free, free_list) {
if ( ! ( V_87 -> free + V_87 -> V_91 == V_90 && V_87 -> V_91 != V_90 ) )
continue;
F_63 ( & V_87 -> V_89 ) ;
if ( V_87 -> free + V_87 -> V_91 == V_90 && V_87 -> V_91 != V_90 ) {
V_87 -> free = 0 ;
V_87 -> V_91 = V_90 ;
F_126 ( V_87 -> V_92 , V_90 ) ;
F_63 ( & V_86 -> V_89 ) ;
F_76 ( & V_87 -> V_93 ) ;
F_67 ( & V_86 -> V_89 ) ;
F_67 ( & V_87 -> V_89 ) ;
F_96 ( & V_87 -> V_97 , & V_97 ) ;
} else
F_67 ( & V_87 -> V_89 ) ;
}
F_97 () ;
F_99 (vb, n_vb, &purge, purge) {
F_127 ( & V_87 -> V_97 ) ;
F_122 ( V_87 ) ;
}
}
static void F_93 ( void )
{
int V_96 ;
F_128 (cpu)
F_124 ( V_96 ) ;
}
static void * F_129 ( unsigned long V_46 , T_6 V_51 )
{
struct V_85 * V_86 ;
struct V_84 * V_87 ;
unsigned long V_10 = 0 ;
unsigned int V_99 ;
F_21 ( V_46 & ~ V_54 ) ;
F_21 ( V_46 > V_15 * V_100 ) ;
if ( F_9 ( V_46 == 0 ) ) {
return NULL ;
}
V_99 = F_130 ( V_46 ) ;
V_101:
F_94 () ;
V_86 = & F_120 ( V_85 ) ;
F_95 (vb, &vbq->free, free_list) {
int V_102 ;
F_63 ( & V_87 -> V_89 ) ;
if ( V_87 -> free < 1UL << V_99 )
goto V_17;
V_102 = V_90 - V_87 -> free ;
V_10 = V_87 -> V_38 -> va_start + ( V_102 << V_79 ) ;
F_21 ( F_109 ( V_10 ) !=
F_109 ( V_87 -> V_38 -> va_start ) ) ;
V_87 -> free -= 1UL << V_99 ;
if ( V_87 -> free == 0 ) {
F_63 ( & V_86 -> V_89 ) ;
F_76 ( & V_87 -> V_93 ) ;
F_67 ( & V_86 -> V_89 ) ;
}
F_67 ( & V_87 -> V_89 ) ;
break;
V_17:
F_67 ( & V_87 -> V_89 ) ;
}
F_121 ( V_85 ) ;
F_97 () ;
if ( ! V_10 ) {
V_87 = F_110 ( V_51 ) ;
if ( F_112 ( V_87 ) )
return V_87 ;
goto V_101;
}
return ( void * ) V_10 ;
}
static void F_131 ( const void * V_10 , unsigned long V_46 )
{
unsigned long V_103 ;
unsigned long V_88 ;
unsigned int V_99 ;
struct V_84 * V_87 ;
F_21 ( V_46 & ~ V_54 ) ;
F_21 ( V_46 > V_15 * V_100 ) ;
F_106 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
V_99 = F_130 ( V_46 ) ;
V_103 = ( unsigned long ) V_10 & ( V_83 - 1 ) ;
V_88 = F_109 ( ( unsigned long ) V_10 ) ;
F_94 () ;
V_87 = F_132 ( & V_95 , V_88 ) ;
F_97 () ;
F_21 ( ! V_87 ) ;
F_20 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
F_63 ( & V_87 -> V_89 ) ;
F_21 ( F_133 ( V_87 -> V_92 , V_103 >> V_79 , V_99 ) ) ;
V_87 -> V_91 += 1UL << V_99 ;
if ( V_87 -> V_91 == V_90 ) {
F_21 ( V_87 -> free ) ;
F_67 ( & V_87 -> V_89 ) ;
F_122 ( V_87 ) ;
} else
F_67 ( & V_87 -> V_89 ) ;
}
void F_134 ( void )
{
unsigned long V_25 = V_82 , V_11 = 0 ;
int V_96 ;
int V_104 = 0 ;
if ( F_60 ( ! V_105 ) )
return;
F_128 (cpu) {
struct V_85 * V_86 = & F_125 ( V_85 , V_96 ) ;
struct V_84 * V_87 ;
F_94 () ;
F_95 (vb, &vbq->free, free_list) {
int V_102 , V_106 ;
F_63 ( & V_87 -> V_89 ) ;
V_102 = F_135 ( V_87 -> V_92 , V_90 ) ;
if ( V_102 < V_90 ) {
unsigned long V_107 , V_108 ;
V_106 = F_136 ( V_87 -> V_92 ,
V_90 ) ;
V_106 = V_106 + 1 ;
V_107 = V_87 -> V_38 -> va_start + ( V_102 << V_79 ) ;
V_108 = V_87 -> V_38 -> va_start + ( V_106 << V_79 ) ;
V_104 = 1 ;
if ( V_107 < V_25 )
V_25 = V_107 ;
if ( V_108 > V_11 )
V_11 = V_108 ;
}
F_67 ( & V_87 -> V_89 ) ;
}
F_97 () ;
}
F_89 ( & V_25 , & V_11 , 1 , V_104 ) ;
}
void F_137 ( const void * V_109 , unsigned int V_110 )
{
unsigned long V_46 = V_110 << V_79 ;
unsigned long V_10 = ( unsigned long ) V_109 ;
F_21 ( ! V_10 ) ;
F_21 ( V_10 < V_68 ) ;
F_21 ( V_10 > V_69 ) ;
F_21 ( V_10 & ( V_15 - 1 ) ) ;
F_138 ( V_109 , V_46 ) ;
F_81 ( V_10 , V_10 + V_46 ) ;
if ( F_139 ( V_110 <= V_100 ) )
F_131 ( V_109 , V_46 ) ;
else
F_108 ( V_10 ) ;
}
void * F_140 ( struct V_20 * * V_21 , unsigned int V_110 , int V_50 , T_5 V_19 )
{
unsigned long V_46 = V_110 << V_79 ;
unsigned long V_10 ;
void * V_109 ;
if ( F_139 ( V_110 <= V_100 ) ) {
V_109 = F_129 ( V_46 , V_111 ) ;
if ( F_112 ( V_109 ) )
return NULL ;
V_10 = ( unsigned long ) V_109 ;
} else {
struct V_34 * V_38 ;
V_38 = F_57 ( V_46 , V_15 ,
V_68 , V_69 , V_50 , V_111 ) ;
if ( F_112 ( V_38 ) )
return NULL ;
V_10 = V_38 -> va_start ;
V_109 = ( void * ) V_10 ;
}
if ( F_34 ( V_10 , V_10 + V_46 , V_19 , V_21 ) < 0 ) {
F_137 ( V_109 , V_110 ) ;
return NULL ;
}
return V_109 ;
}
void T_7 F_141 ( struct V_112 * V_113 )
{
struct V_112 * V_42 , * * V_4 ;
F_21 ( V_105 ) ;
for ( V_4 = & V_114 ; ( V_42 = * V_4 ) != NULL ; V_4 = & V_42 -> V_17 ) {
if ( V_42 -> V_10 >= V_113 -> V_10 ) {
F_21 ( V_42 -> V_10 < V_113 -> V_10 + V_113 -> V_46 ) ;
break;
} else
F_21 ( V_42 -> V_10 + V_42 -> V_46 > V_113 -> V_10 ) ;
}
V_113 -> V_17 = * V_4 ;
* V_4 = V_113 ;
}
void T_7 F_142 ( struct V_112 * V_113 , T_8 V_47 )
{
static T_8 T_9 V_115 ;
unsigned long V_10 ;
V_10 = F_64 ( V_68 + T_9 , V_47 ) ;
T_9 = F_143 ( V_10 + V_113 -> V_46 ) - V_68 ;
V_113 -> V_10 = ( void * ) V_10 ;
F_141 ( V_113 ) ;
}
void T_7 F_144 ( void )
{
struct V_34 * V_38 ;
struct V_112 * V_42 ;
int V_102 ;
F_128 (i) {
struct V_85 * V_86 ;
struct V_3 * V_4 ;
V_86 = & F_125 ( V_85 , V_102 ) ;
F_115 ( & V_86 -> V_89 ) ;
F_117 ( & V_86 -> free ) ;
V_4 = & F_125 ( V_3 , V_102 ) ;
F_145 ( & V_4 -> V_8 ) ;
F_146 ( & V_4 -> V_5 , F_1 ) ;
}
for ( V_42 = V_114 ; V_42 ; V_42 = V_42 -> V_17 ) {
V_38 = F_147 ( sizeof( struct V_34 ) , V_116 ) ;
V_38 -> V_66 = V_117 ;
V_38 -> va_start = ( unsigned long ) V_42 -> V_10 ;
V_38 -> va_end = V_38 -> va_start + V_42 -> V_46 ;
V_38 -> V_113 = V_42 ;
F_51 ( V_38 ) ;
}
V_70 = V_69 ;
V_105 = true ;
}
int F_148 ( unsigned long V_10 , unsigned long V_46 ,
T_5 V_19 , struct V_20 * * V_21 )
{
return F_33 ( V_10 , V_10 + V_46 , V_19 , V_21 ) ;
}
void F_149 ( unsigned long V_10 , unsigned long V_46 )
{
F_20 ( V_10 , V_10 + V_46 ) ;
}
void F_150 ( unsigned long V_10 , unsigned long V_46 )
{
unsigned long V_11 = V_10 + V_46 ;
F_106 ( V_10 , V_11 ) ;
F_20 ( V_10 , V_11 ) ;
F_83 ( V_10 , V_11 ) ;
}
int F_151 ( struct V_112 * V_118 , T_5 V_19 , struct V_20 * * V_21 )
{
unsigned long V_10 = ( unsigned long ) V_118 -> V_10 ;
unsigned long V_11 = V_10 + F_152 ( V_118 ) ;
int V_26 ;
V_26 = F_34 ( V_10 , V_11 , V_19 , V_21 ) ;
return V_26 > 0 ? 0 : V_26 ;
}
static void F_153 ( struct V_112 * V_113 , struct V_34 * V_38 ,
unsigned long V_66 , const void * V_119 )
{
F_63 ( & V_58 ) ;
V_113 -> V_66 = V_66 ;
V_113 -> V_10 = ( void * ) V_38 -> va_start ;
V_113 -> V_46 = V_38 -> va_end - V_38 -> va_start ;
V_113 -> V_119 = V_119 ;
V_38 -> V_113 = V_113 ;
V_38 -> V_66 |= V_117 ;
F_67 ( & V_58 ) ;
}
static void F_154 ( struct V_112 * V_113 )
{
F_155 () ;
V_113 -> V_66 &= ~ V_120 ;
}
static struct V_112 * F_156 ( unsigned long V_46 ,
unsigned long V_47 , unsigned long V_66 , unsigned long V_25 ,
unsigned long V_11 , int V_50 , T_6 V_51 , const void * V_119 )
{
struct V_34 * V_38 ;
struct V_112 * V_118 ;
F_21 ( F_157 () ) ;
if ( V_66 & V_121 )
V_47 = 1ul << F_158 ( F_85 ( V_46 ) , V_79 , V_122 ) ;
V_46 = F_159 ( V_46 ) ;
if ( F_60 ( ! V_46 ) )
return NULL ;
V_118 = F_160 ( sizeof( * V_118 ) , V_51 & V_55 , V_50 ) ;
if ( F_60 ( ! V_118 ) )
return NULL ;
V_46 += V_15 ;
V_38 = F_57 ( V_46 , V_47 , V_25 , V_11 , V_50 , V_51 ) ;
if ( F_112 ( V_38 ) ) {
F_71 ( V_118 ) ;
return NULL ;
}
F_153 ( V_118 , V_38 , V_66 , V_119 ) ;
return V_118 ;
}
struct V_112 * F_161 ( unsigned long V_46 , unsigned long V_66 ,
unsigned long V_25 , unsigned long V_11 )
{
return F_156 ( V_46 , 1 , V_66 , V_25 , V_11 , V_123 ,
V_111 , F_162 ( 0 ) ) ;
}
struct V_112 * F_163 ( unsigned long V_46 , unsigned long V_66 ,
unsigned long V_25 , unsigned long V_11 ,
const void * V_119 )
{
return F_156 ( V_46 , 1 , V_66 , V_25 , V_11 , V_123 ,
V_111 , V_119 ) ;
}
struct V_112 * F_164 ( unsigned long V_46 , unsigned long V_66 )
{
return F_156 ( V_46 , 1 , V_66 , V_68 , V_69 ,
V_123 , V_111 ,
F_162 ( 0 ) ) ;
}
struct V_112 * F_165 ( unsigned long V_46 , unsigned long V_66 ,
const void * V_119 )
{
return F_156 ( V_46 , 1 , V_66 , V_68 , V_69 ,
V_123 , V_111 , V_119 ) ;
}
struct V_112 * F_166 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_107 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_66 & V_117 )
return V_38 -> V_113 ;
return NULL ;
}
struct V_112 * F_167 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_107 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_66 & V_117 ) {
struct V_112 * V_113 = V_38 -> V_113 ;
F_63 ( & V_58 ) ;
V_38 -> V_113 = NULL ;
V_38 -> V_66 &= ~ V_117 ;
F_67 ( & V_58 ) ;
F_81 ( V_38 -> va_start , V_38 -> va_end ) ;
F_105 ( V_38 ) ;
V_113 -> V_46 -= V_15 ;
return V_113 ;
}
return NULL ;
}
static void F_5 ( const void * V_10 , int V_124 )
{
struct V_112 * V_118 ;
if ( ! V_10 )
return;
if ( F_168 ( ! F_169 ( V_10 ) , L_3 ,
V_10 ) )
return;
V_118 = F_167 ( V_10 ) ;
if ( F_60 ( ! V_118 ) ) {
F_168 ( 1 , V_125 L_4 ,
V_10 ) ;
return;
}
F_138 ( V_10 , V_118 -> V_46 ) ;
F_170 ( V_10 , V_118 -> V_46 ) ;
if ( V_124 ) {
int V_102 ;
for ( V_102 = 0 ; V_102 < V_118 -> V_126 ; V_102 ++ ) {
struct V_20 * V_20 = V_118 -> V_21 [ V_102 ] ;
F_21 ( ! V_20 ) ;
F_171 ( V_20 ) ;
}
if ( V_118 -> V_66 & V_127 )
F_172 ( V_118 -> V_21 ) ;
else
F_71 ( V_118 -> V_21 ) ;
}
F_71 ( V_118 ) ;
return;
}
void F_172 ( const void * V_10 )
{
F_21 ( F_173 () ) ;
F_174 ( V_10 ) ;
if ( ! V_10 )
return;
if ( F_60 ( F_157 () ) ) {
struct V_3 * V_4 = F_175 ( & V_3 ) ;
if ( F_176 ( (struct V_6 * ) V_10 , & V_4 -> V_8 ) )
F_177 ( & V_4 -> V_5 ) ;
} else
F_5 ( V_10 , 1 ) ;
}
void F_178 ( const void * V_10 )
{
F_21 ( F_157 () ) ;
F_179 () ;
if ( V_10 )
F_5 ( V_10 , 0 ) ;
}
void * F_180 ( struct V_20 * * V_21 , unsigned int V_110 ,
unsigned long V_66 , T_5 V_19 )
{
struct V_112 * V_118 ;
F_179 () ;
if ( V_110 > V_128 )
return NULL ;
V_118 = F_165 ( ( V_110 << V_79 ) , V_66 ,
F_162 ( 0 ) ) ;
if ( ! V_118 )
return NULL ;
if ( F_151 ( V_118 , V_19 , V_21 ) ) {
F_178 ( V_118 -> V_10 ) ;
return NULL ;
}
return V_118 -> V_10 ;
}
static void * F_181 ( struct V_112 * V_118 , T_6 V_51 ,
T_5 V_19 , int V_50 )
{
const int V_99 = 0 ;
struct V_20 * * V_21 ;
unsigned int V_126 , V_129 , V_102 ;
const T_6 V_130 = ( V_51 & V_55 ) | V_131 ;
const T_6 V_132 = V_51 | V_133 ;
V_126 = F_152 ( V_118 ) >> V_79 ;
V_129 = ( V_126 * sizeof( struct V_20 * ) ) ;
V_118 -> V_126 = V_126 ;
if ( V_129 > V_15 ) {
V_21 = F_182 ( V_129 , 1 , V_130 | V_134 ,
V_135 , V_50 , V_118 -> V_119 ) ;
V_118 -> V_66 |= V_127 ;
} else {
V_21 = F_59 ( V_129 , V_130 , V_50 ) ;
}
V_118 -> V_21 = V_21 ;
if ( ! V_118 -> V_21 ) {
F_167 ( V_118 -> V_10 ) ;
F_71 ( V_118 ) ;
return NULL ;
}
for ( V_102 = 0 ; V_102 < V_118 -> V_126 ; V_102 ++ ) {
struct V_20 * V_20 ;
if ( V_50 == V_123 )
V_20 = F_183 ( V_132 ) ;
else
V_20 = F_184 ( V_50 , V_132 , V_99 ) ;
if ( F_60 ( ! V_20 ) ) {
V_118 -> V_126 = V_102 ;
goto V_136;
}
V_118 -> V_21 [ V_102 ] = V_20 ;
if ( V_51 & V_137 )
F_185 () ;
}
if ( F_151 ( V_118 , V_19 , V_21 ) )
goto V_136;
return V_118 -> V_10 ;
V_136:
F_186 ( V_51 , V_99 ,
L_5 ,
( V_118 -> V_126 * V_15 ) , V_118 -> V_46 ) ;
F_172 ( V_118 -> V_10 ) ;
return NULL ;
}
void * F_187 ( unsigned long V_46 , unsigned long V_47 ,
unsigned long V_25 , unsigned long V_11 , T_6 V_51 ,
T_5 V_19 , int V_50 , const void * V_119 )
{
struct V_112 * V_118 ;
void * V_10 ;
unsigned long V_138 = V_46 ;
V_46 = F_159 ( V_46 ) ;
if ( ! V_46 || ( V_46 >> V_79 ) > V_128 )
goto V_136;
V_118 = F_156 ( V_46 , V_47 , V_139 | V_120 ,
V_25 , V_11 , V_50 , V_51 , V_119 ) ;
if ( ! V_118 )
goto V_136;
V_10 = F_181 ( V_118 , V_51 , V_19 , V_50 ) ;
if ( ! V_10 )
return NULL ;
F_154 ( V_118 ) ;
F_188 ( V_10 , V_138 , 2 , V_51 ) ;
return V_10 ;
V_136:
F_186 ( V_51 , 0 ,
L_6 ,
V_138 ) ;
return NULL ;
}
static void * F_182 ( unsigned long V_46 , unsigned long V_47 ,
T_6 V_51 , T_5 V_19 ,
int V_50 , const void * V_119 )
{
return F_187 ( V_46 , V_47 , V_68 , V_69 ,
V_51 , V_19 , V_50 , V_119 ) ;
}
void * F_189 ( unsigned long V_46 , T_6 V_51 , T_5 V_19 )
{
return F_182 ( V_46 , 1 , V_51 , V_19 , V_123 ,
F_162 ( 0 ) ) ;
}
static inline void * F_190 ( unsigned long V_46 ,
int V_50 , T_6 V_66 )
{
return F_182 ( V_46 , 1 , V_66 , V_135 ,
V_50 , F_162 ( 0 ) ) ;
}
void * F_191 ( unsigned long V_46 )
{
return F_190 ( V_46 , V_123 ,
V_111 | V_134 ) ;
}
void * F_192 ( unsigned long V_46 )
{
return F_190 ( V_46 , V_123 ,
V_111 | V_134 | V_131 ) ;
}
void * F_193 ( unsigned long V_46 )
{
struct V_112 * V_118 ;
void * V_27 ;
V_27 = F_182 ( V_46 , V_140 ,
V_111 | V_134 | V_131 ,
V_135 , V_123 ,
F_162 ( 0 ) ) ;
if ( V_27 ) {
V_118 = F_166 ( V_27 ) ;
V_118 -> V_66 |= V_141 ;
}
return V_27 ;
}
void * F_194 ( unsigned long V_46 , int V_50 )
{
return F_182 ( V_46 , 1 , V_111 | V_134 , V_135 ,
V_50 , F_162 ( 0 ) ) ;
}
void * F_195 ( unsigned long V_46 , int V_50 )
{
return F_190 ( V_46 , V_50 ,
V_111 | V_134 | V_131 ) ;
}
void * F_196 ( unsigned long V_46 )
{
return F_182 ( V_46 , 1 , V_111 | V_134 , V_142 ,
V_123 , F_162 ( 0 ) ) ;
}
void * F_197 ( unsigned long V_46 )
{
return F_182 ( V_46 , 1 , V_143 , V_135 ,
V_123 , F_162 ( 0 ) ) ;
}
void * F_198 ( unsigned long V_46 )
{
struct V_112 * V_118 ;
void * V_27 ;
V_27 = F_182 ( V_46 , 1 , V_143 | V_131 , V_135 ,
V_123 , F_162 ( 0 ) ) ;
if ( V_27 ) {
V_118 = F_166 ( V_27 ) ;
V_118 -> V_66 |= V_141 ;
}
return V_27 ;
}
static int F_199 ( char * V_144 , char * V_10 , unsigned long V_110 )
{
struct V_20 * V_4 ;
int V_145 = 0 ;
while ( V_110 ) {
unsigned long V_103 , V_146 ;
V_103 = ( unsigned long ) V_10 & ~ V_54 ;
V_146 = V_15 - V_103 ;
if ( V_146 > V_110 )
V_146 = V_110 ;
V_4 = F_39 ( V_10 ) ;
if ( V_4 ) {
void * V_147 = F_200 ( V_4 ) ;
memcpy ( V_144 , V_147 + V_103 , V_146 ) ;
F_201 ( V_147 ) ;
} else
memset ( V_144 , 0 , V_146 ) ;
V_10 += V_146 ;
V_144 += V_146 ;
V_145 += V_146 ;
V_110 -= V_146 ;
}
return V_145 ;
}
static int F_202 ( char * V_144 , char * V_10 , unsigned long V_110 )
{
struct V_20 * V_4 ;
int V_145 = 0 ;
while ( V_110 ) {
unsigned long V_103 , V_146 ;
V_103 = ( unsigned long ) V_10 & ~ V_54 ;
V_146 = V_15 - V_103 ;
if ( V_146 > V_110 )
V_146 = V_110 ;
V_4 = F_39 ( V_10 ) ;
if ( V_4 ) {
void * V_147 = F_200 ( V_4 ) ;
memcpy ( V_147 + V_103 , V_144 , V_146 ) ;
F_201 ( V_147 ) ;
}
V_10 += V_146 ;
V_144 += V_146 ;
V_145 += V_146 ;
V_110 -= V_146 ;
}
return V_145 ;
}
long F_203 ( char * V_144 , char * V_10 , unsigned long V_110 )
{
struct V_34 * V_38 ;
struct V_112 * V_113 ;
char * V_148 , * V_149 = V_144 ;
unsigned long V_150 = V_110 ;
unsigned long V_36 ;
if ( ( unsigned long ) V_10 + V_110 < V_110 )
V_110 = - ( unsigned long ) V_10 ;
F_63 ( & V_58 ) ;
F_204 (va, &vmap_area_list, list) {
if ( ! V_110 )
break;
if ( ! ( V_38 -> V_66 & V_117 ) )
continue;
V_113 = V_38 -> V_113 ;
V_148 = ( char * ) V_113 -> V_10 ;
if ( V_10 >= V_148 + F_152 ( V_113 ) )
continue;
while ( V_10 < V_148 ) {
if ( V_110 == 0 )
goto V_151;
* V_144 = '\0' ;
V_144 ++ ;
V_10 ++ ;
V_110 -- ;
}
V_36 = V_148 + F_152 ( V_113 ) - V_10 ;
if ( V_36 > V_110 )
V_36 = V_110 ;
if ( ! ( V_113 -> V_66 & V_121 ) )
F_199 ( V_144 , V_10 , V_36 ) ;
else
memset ( V_144 , 0 , V_36 ) ;
V_144 += V_36 ;
V_10 += V_36 ;
V_110 -= V_36 ;
}
V_151:
F_67 ( & V_58 ) ;
if ( V_144 == V_149 )
return 0 ;
if ( V_144 != V_149 + V_150 )
memset ( V_144 , 0 , V_150 - ( V_144 - V_149 ) ) ;
return V_150 ;
}
long F_205 ( char * V_144 , char * V_10 , unsigned long V_110 )
{
struct V_34 * V_38 ;
struct V_112 * V_113 ;
char * V_148 ;
unsigned long V_36 , V_150 ;
int V_145 = 0 ;
if ( ( unsigned long ) V_10 + V_110 < V_110 )
V_110 = - ( unsigned long ) V_10 ;
V_150 = V_110 ;
F_63 ( & V_58 ) ;
F_204 (va, &vmap_area_list, list) {
if ( ! V_110 )
break;
if ( ! ( V_38 -> V_66 & V_117 ) )
continue;
V_113 = V_38 -> V_113 ;
V_148 = ( char * ) V_113 -> V_10 ;
if ( V_10 >= V_148 + F_152 ( V_113 ) )
continue;
while ( V_10 < V_148 ) {
if ( V_110 == 0 )
goto V_151;
V_144 ++ ;
V_10 ++ ;
V_110 -- ;
}
V_36 = V_148 + F_152 ( V_113 ) - V_10 ;
if ( V_36 > V_110 )
V_36 = V_110 ;
if ( ! ( V_113 -> V_66 & V_121 ) ) {
F_202 ( V_144 , V_10 , V_36 ) ;
V_145 ++ ;
}
V_144 += V_36 ;
V_10 += V_36 ;
V_110 -= V_36 ;
}
V_151:
F_67 ( & V_58 ) ;
if ( ! V_145 )
return 0 ;
return V_150 ;
}
int F_206 ( struct V_152 * V_153 , unsigned long V_154 ,
void * V_155 , unsigned long V_46 )
{
struct V_112 * V_118 ;
V_46 = F_159 ( V_46 ) ;
if ( ! F_169 ( V_154 ) || ! F_169 ( V_155 ) )
return - V_156 ;
V_118 = F_166 ( V_155 ) ;
if ( ! V_118 )
return - V_156 ;
if ( ! ( V_118 -> V_66 & V_141 ) )
return - V_156 ;
if ( V_155 + V_46 > V_118 -> V_10 + V_118 -> V_46 )
return - V_156 ;
do {
struct V_20 * V_20 = F_39 ( V_155 ) ;
int V_27 ;
V_27 = F_207 ( V_153 , V_154 , V_20 ) ;
if ( V_27 )
return V_27 ;
V_154 += V_15 ;
V_155 += V_15 ;
V_46 -= V_15 ;
} while ( V_46 > 0 );
V_153 -> V_157 |= V_158 | V_159 ;
return 0 ;
}
int F_208 ( struct V_152 * V_153 , void * V_10 ,
unsigned long V_160 )
{
return F_206 ( V_153 , V_153 -> V_161 ,
V_10 + ( V_160 << V_79 ) ,
V_153 -> V_162 - V_153 -> V_161 ) ;
}
void __weak F_209 ( void )
{
}
static int F_210 ( T_2 * V_12 , T_10 V_163 , unsigned long V_10 , void * V_164 )
{
T_2 * * * V_4 = V_164 ;
if ( V_4 ) {
* ( * V_4 ) = V_12 ;
( * V_4 ) ++ ;
}
return 0 ;
}
struct V_112 * F_211 ( T_8 V_46 , T_2 * * V_165 )
{
struct V_112 * V_118 ;
V_118 = F_165 ( V_46 , V_121 ,
F_162 ( 0 ) ) ;
if ( V_118 == NULL )
return NULL ;
if ( F_212 ( & V_14 , ( unsigned long ) V_118 -> V_10 ,
V_46 , F_210 , V_165 ? & V_165 : NULL ) ) {
F_213 ( V_118 ) ;
return NULL ;
}
return V_118 ;
}
void F_213 ( struct V_112 * V_118 )
{
struct V_112 * V_27 ;
V_27 = F_167 ( V_118 -> V_10 ) ;
F_21 ( V_27 != V_118 ) ;
F_71 ( V_118 ) ;
}
static struct V_34 * F_214 ( struct V_35 * V_36 )
{
return V_36 ? F_50 ( V_36 , struct V_34 , V_35 ) : NULL ;
}
static bool F_215 ( unsigned long V_11 ,
struct V_34 * * V_166 ,
struct V_34 * * V_167 )
{
struct V_35 * V_36 = V_37 . V_35 ;
struct V_34 * V_38 = NULL ;
while ( V_36 ) {
V_38 = F_50 ( V_36 , struct V_34 , V_35 ) ;
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
* V_166 = V_38 ;
* V_167 = F_214 ( F_55 ( & ( * V_166 ) -> V_35 ) ) ;
} else {
* V_167 = V_38 ;
* V_166 = F_214 ( F_216 ( & ( * V_167 ) -> V_35 ) ) ;
}
return true ;
}
static unsigned long F_217 ( struct V_34 * * V_166 ,
struct V_34 * * V_167 ,
unsigned long V_47 )
{
const unsigned long V_168 = V_69 & ~ ( V_47 - 1 ) ;
unsigned long V_10 ;
if ( * V_166 )
V_10 = F_218 ( ( * V_166 ) -> va_start & ~ ( V_47 - 1 ) , V_168 ) ;
else
V_10 = V_168 ;
while ( * V_167 && ( * V_167 ) -> va_end > V_10 ) {
* V_166 = * V_167 ;
* V_167 = F_214 ( F_55 ( & ( * V_166 ) -> V_35 ) ) ;
}
return V_10 ;
}
struct V_112 * * F_219 ( const unsigned long * V_169 ,
const T_8 * V_170 , int V_171 ,
T_8 V_47 )
{
const unsigned long V_172 = F_64 ( V_68 , V_47 ) ;
const unsigned long V_168 = V_69 & ~ ( V_47 - 1 ) ;
struct V_34 * * V_173 , * V_44 , * V_17 ;
struct V_112 * * V_174 ;
int V_118 , V_175 , V_176 , V_177 ;
unsigned long V_178 , V_25 , V_11 , V_179 ;
bool V_52 = false ;
F_21 ( V_47 & ~ V_54 || ! F_58 ( V_47 ) ) ;
for ( V_176 = 0 , V_118 = 0 ; V_118 < V_171 ; V_118 ++ ) {
V_25 = V_169 [ V_118 ] ;
V_11 = V_25 + V_170 [ V_118 ] ;
F_21 ( ! F_220 ( V_169 [ V_118 ] , V_47 ) ) ;
F_21 ( ! F_220 ( V_170 [ V_118 ] , V_47 ) ) ;
if ( V_25 > V_169 [ V_176 ] )
V_176 = V_118 ;
for ( V_175 = 0 ; V_175 < V_171 ; V_175 ++ ) {
unsigned long V_180 = V_169 [ V_175 ] ;
unsigned long V_181 = V_180 + V_170 [ V_175 ] ;
if ( V_175 == V_118 )
continue;
F_21 ( V_180 >= V_25 && V_180 < V_11 ) ;
F_21 ( V_181 <= V_11 && V_181 > V_25 ) ;
}
}
V_179 = V_169 [ V_176 ] + V_170 [ V_176 ] ;
if ( V_168 - V_172 < V_179 ) {
F_9 ( true ) ;
return NULL ;
}
V_174 = F_221 ( V_171 , sizeof( V_174 [ 0 ] ) , V_111 ) ;
V_173 = F_221 ( V_171 , sizeof( V_173 [ 0 ] ) , V_111 ) ;
if ( ! V_173 || ! V_174 )
goto V_182;
for ( V_118 = 0 ; V_118 < V_171 ; V_118 ++ ) {
V_173 [ V_118 ] = F_147 ( sizeof( struct V_34 ) , V_111 ) ;
V_174 [ V_118 ] = F_147 ( sizeof( struct V_112 ) , V_111 ) ;
if ( ! V_173 [ V_118 ] || ! V_174 [ V_118 ] )
goto V_183;
}
V_57:
F_63 ( & V_58 ) ;
V_118 = V_177 = V_176 ;
V_25 = V_169 [ V_118 ] ;
V_11 = V_25 + V_170 [ V_118 ] ;
if ( ! F_215 ( V_70 , & V_17 , & V_44 ) ) {
V_178 = V_168 - V_179 ;
goto V_65;
}
V_178 = F_217 ( & V_17 , & V_44 , V_47 ) - V_11 ;
while ( true ) {
F_21 ( V_17 && V_17 -> va_end <= V_178 + V_11 ) ;
F_21 ( V_44 && V_44 -> va_end > V_178 + V_11 ) ;
if ( V_178 + V_179 < V_172 + V_179 ) {
F_67 ( & V_58 ) ;
if ( ! V_52 ) {
F_68 () ;
V_52 = true ;
goto V_57;
}
goto V_183;
}
if ( V_17 && V_17 -> va_start < V_178 + V_11 ) {
V_178 = F_217 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_177 = V_118 ;
continue;
}
if ( V_44 && V_44 -> va_end > V_178 + V_25 ) {
V_17 = V_44 ;
V_44 = F_214 ( F_55 ( & V_17 -> V_35 ) ) ;
V_178 = F_217 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_177 = V_118 ;
continue;
}
V_118 = ( V_118 + V_171 - 1 ) % V_171 ;
if ( V_118 == V_177 )
break;
V_25 = V_169 [ V_118 ] ;
V_11 = V_25 + V_170 [ V_118 ] ;
F_215 ( V_178 + V_11 , & V_17 , & V_44 ) ;
}
V_65:
for ( V_118 = 0 ; V_118 < V_171 ; V_118 ++ ) {
struct V_34 * V_38 = V_173 [ V_118 ] ;
V_38 -> va_start = V_178 + V_169 [ V_118 ] ;
V_38 -> va_end = V_38 -> va_start + V_170 [ V_118 ] ;
F_51 ( V_38 ) ;
}
V_70 = V_178 + V_169 [ V_176 ] ;
F_67 ( & V_58 ) ;
for ( V_118 = 0 ; V_118 < V_171 ; V_118 ++ )
F_153 ( V_174 [ V_118 ] , V_173 [ V_118 ] , V_139 ,
F_219 ) ;
F_71 ( V_173 ) ;
return V_174 ;
V_183:
for ( V_118 = 0 ; V_118 < V_171 ; V_118 ++ ) {
F_71 ( V_173 [ V_118 ] ) ;
F_71 ( V_174 [ V_118 ] ) ;
}
V_182:
F_71 ( V_173 ) ;
F_71 ( V_174 ) ;
return NULL ;
}
void F_222 ( struct V_112 * * V_174 , int V_171 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_171 ; V_102 ++ )
F_213 ( V_174 [ V_102 ] ) ;
F_71 ( V_174 ) ;
}
static void * F_223 ( struct V_184 * V_185 , T_11 * V_186 )
__acquires( &vmap_area_lock
static void * F_224 ( struct V_184 * V_185 , void * V_4 , T_11 * V_186 )
{
struct V_34 * V_38 = V_4 , * V_17 ;
++ * V_186 ;
V_17 = F_66 ( V_38 -> V_8 . V_17 , F_225 ( * V_38 ) , V_8 ) ;
if ( & V_17 -> V_8 != & V_45 )
return V_17 ;
return NULL ;
}
static void F_226 ( struct V_184 * V_185 , void * V_4 )
__releases( &vmap_area_lock
static void F_227 ( struct V_184 * V_185 , struct V_112 * V_187 )
{
if ( F_228 ( V_188 ) ) {
unsigned int V_22 , * V_189 = V_185 -> V_190 ;
if ( ! V_189 )
return;
if ( V_187 -> V_66 & V_120 )
return;
F_229 () ;
memset ( V_189 , 0 , V_191 * sizeof( unsigned int ) ) ;
for ( V_22 = 0 ; V_22 < V_187 -> V_126 ; V_22 ++ )
V_189 [ F_230 ( V_187 -> V_21 [ V_22 ] ) ] ++ ;
F_231 (nr, N_HIGH_MEMORY)
if ( V_189 [ V_22 ] )
F_232 ( V_185 , L_7 , V_22 , V_189 [ V_22 ] ) ;
}
}
static int F_233 ( struct V_184 * V_185 , void * V_4 )
{
struct V_34 * V_38 = V_4 ;
struct V_112 * V_187 ;
if ( ! ( V_38 -> V_66 & V_117 ) )
return 0 ;
V_187 = V_38 -> V_113 ;
F_232 ( V_185 , L_8 ,
V_187 -> V_10 , V_187 -> V_10 + V_187 -> V_46 , V_187 -> V_46 ) ;
if ( V_187 -> V_119 )
F_232 ( V_185 , L_9 , V_187 -> V_119 ) ;
if ( V_187 -> V_126 )
F_232 ( V_185 , L_10 , V_187 -> V_126 ) ;
if ( V_187 -> V_192 )
F_232 ( V_185 , L_11 , ( unsigned long long ) V_187 -> V_192 ) ;
if ( V_187 -> V_66 & V_121 )
F_234 ( V_185 , L_12 ) ;
if ( V_187 -> V_66 & V_139 )
F_234 ( V_185 , L_13 ) ;
if ( V_187 -> V_66 & V_193 )
F_234 ( V_185 , L_14 ) ;
if ( V_187 -> V_66 & V_141 )
F_234 ( V_185 , L_15 ) ;
if ( V_187 -> V_66 & V_127 )
F_234 ( V_185 , L_16 ) ;
F_227 ( V_185 , V_187 ) ;
F_235 ( V_185 , '\n' ) ;
return 0 ;
}
static int F_236 ( struct V_194 * V_194 , struct V_195 * V_195 )
{
if ( F_228 ( V_188 ) )
return F_237 ( V_195 , & V_196 ,
V_191 * sizeof( unsigned int ) ) ;
else
return F_238 ( V_195 , & V_196 ) ;
}
static int T_7 F_239 ( void )
{
F_240 ( L_17 , V_197 , NULL , & V_198 ) ;
return 0 ;
}
void F_241 ( struct V_199 * V_200 )
{
struct V_34 * V_38 ;
unsigned long V_201 ;
unsigned long V_202 ;
V_200 -> V_203 = 0 ;
V_200 -> V_204 = 0 ;
V_202 = V_68 ;
F_94 () ;
if ( F_242 ( & V_45 ) ) {
V_200 -> V_204 = V_205 ;
goto V_206;
}
F_95 (va, &vmap_area_list, list) {
unsigned long V_10 = V_38 -> va_start ;
if ( V_10 < V_68 )
continue;
if ( V_10 >= V_69 )
break;
if ( V_38 -> V_66 & ( V_78 | V_81 ) )
continue;
V_200 -> V_203 += ( V_38 -> va_end - V_38 -> va_start ) ;
V_201 = V_10 - V_202 ;
if ( V_200 -> V_204 < V_201 )
V_200 -> V_204 = V_201 ;
V_202 = V_38 -> va_end ;
}
if ( V_69 - V_202 > V_200 -> V_204 )
V_200 -> V_204 = V_69 - V_202 ;
V_206:
F_97 () ;
}
