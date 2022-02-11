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
V_56:
F_62 ( & V_57 ) ;
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
V_53 = F_50 ( V_58 , struct V_34 , V_35 ) ;
V_10 = F_63 ( V_53 -> va_end , V_47 ) ;
if ( V_10 < V_48 )
goto V_62;
if ( V_10 + V_46 < V_10 )
goto V_63;
} else {
V_10 = F_63 ( V_48 , V_47 ) ;
if ( V_10 + V_46 < V_10 )
goto V_63;
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
goto V_64;
}
while ( V_10 + V_46 > V_53 -> va_start && V_10 + V_46 <= V_49 ) {
if ( V_10 + V_59 < V_53 -> va_start )
V_59 = V_53 -> va_start - V_10 ;
V_10 = F_63 ( V_53 -> va_end , V_47 ) ;
if ( V_10 + V_46 < V_10 )
goto V_63;
if ( F_64 ( & V_53 -> V_8 , & V_45 ) )
goto V_64;
V_53 = F_65 ( V_53 -> V_8 . V_17 ,
struct V_34 , V_8 ) ;
}
V_64:
if ( V_10 + V_46 > V_49 )
goto V_63;
V_38 -> va_start = V_10 ;
V_38 -> va_end = V_10 + V_46 ;
V_38 -> V_65 = 0 ;
F_51 ( V_38 ) ;
V_58 = & V_38 -> V_35 ;
F_66 ( & V_57 ) ;
F_21 ( V_38 -> va_start & ( V_47 - 1 ) ) ;
F_21 ( V_38 -> va_start < V_48 ) ;
F_21 ( V_38 -> va_end > V_49 ) ;
return V_38 ;
V_63:
F_66 ( & V_57 ) ;
if ( ! V_52 ) {
F_67 () ;
V_52 = 1 ;
goto V_56;
}
if ( F_68 () )
F_69 ( V_66
L_1
L_2 , V_46 ) ;
F_70 ( V_38 ) ;
return F_61 ( - V_24 ) ;
}
static void F_71 ( struct V_34 * V_38 )
{
F_21 ( F_72 ( & V_38 -> V_35 ) ) ;
if ( V_58 ) {
if ( V_38 -> va_end < V_60 ) {
V_58 = NULL ;
} else {
struct V_34 * V_67 ;
V_67 = F_50 ( V_58 , struct V_34 , V_35 ) ;
if ( V_38 -> va_start <= V_67 -> va_start ) {
V_58 = F_55 ( & V_38 -> V_35 ) ;
}
}
}
F_73 ( & V_38 -> V_35 , & V_37 ) ;
F_74 ( & V_38 -> V_35 ) ;
F_75 ( & V_38 -> V_8 ) ;
if ( V_38 -> va_end > V_68 && V_38 -> va_end <= V_69 )
V_70 = F_76 ( V_70 , V_38 -> va_end ) ;
F_77 ( V_38 , V_71 ) ;
}
static void F_78 ( struct V_34 * V_38 )
{
F_62 ( & V_57 ) ;
F_71 ( V_38 ) ;
F_66 ( & V_57 ) ;
}
static void F_79 ( struct V_34 * V_38 )
{
F_20 ( V_38 -> va_start , V_38 -> va_end ) ;
}
static void F_80 ( unsigned long V_25 , unsigned long V_11 )
{
#ifdef F_81
F_20 ( V_25 , V_11 ) ;
F_82 ( V_25 , V_11 ) ;
#endif
}
static unsigned long F_83 ( void )
{
unsigned int log ;
log = F_84 ( F_85 () ) ;
return log * ( 32UL * 1024 * 1024 / V_15 ) ;
}
void F_86 ( void )
{
F_87 ( & V_72 , F_83 () + 1 ) ;
}
static void F_88 ( unsigned long * V_25 , unsigned long * V_11 ,
int V_73 , int V_74 )
{
static F_89 ( V_75 ) ;
F_90 ( V_76 ) ;
struct V_34 * V_38 ;
struct V_34 * V_77 ;
int V_22 = 0 ;
if ( ! V_73 && ! V_74 ) {
if ( ! F_91 ( & V_75 ) )
return;
} else
F_62 ( & V_75 ) ;
if ( V_73 )
F_92 () ;
F_93 () ;
F_94 (va, &vmap_area_list, list) {
if ( V_38 -> V_65 & V_78 ) {
if ( V_38 -> va_start < * V_25 )
* V_25 = V_38 -> va_start ;
if ( V_38 -> va_end > * V_11 )
* V_11 = V_38 -> va_end ;
V_22 += ( V_38 -> va_end - V_38 -> va_start ) >> V_79 ;
F_95 ( & V_38 -> V_80 , & V_76 ) ;
V_38 -> V_65 |= V_81 ;
V_38 -> V_65 &= ~ V_78 ;
}
}
F_96 () ;
if ( V_22 )
F_97 ( V_22 , & V_72 ) ;
if ( V_22 || V_74 )
F_82 ( * V_25 , * V_11 ) ;
if ( V_22 ) {
F_62 ( & V_57 ) ;
F_98 (va, n_va, &valist, purge_list)
F_71 ( V_38 ) ;
F_66 ( & V_57 ) ;
}
F_66 ( & V_75 ) ;
}
static void F_99 ( void )
{
unsigned long V_25 = V_82 , V_11 = 0 ;
F_88 ( & V_25 , & V_11 , 0 , 0 ) ;
}
static void F_67 ( void )
{
unsigned long V_25 = V_82 , V_11 = 0 ;
F_88 ( & V_25 , & V_11 , 1 , 0 ) ;
}
static void F_100 ( struct V_34 * V_38 )
{
V_38 -> V_65 |= V_78 ;
F_101 ( ( V_38 -> va_end - V_38 -> va_start ) >> V_79 , & V_72 ) ;
if ( F_60 ( F_102 ( & V_72 ) > F_83 () ) )
F_99 () ;
}
static void F_103 ( struct V_34 * V_38 )
{
F_79 ( V_38 ) ;
F_100 ( V_38 ) ;
}
static void F_104 ( struct V_34 * V_38 )
{
F_105 ( V_38 -> va_start , V_38 -> va_end ) ;
F_103 ( V_38 ) ;
}
static struct V_34 * F_106 ( unsigned long V_10 )
{
struct V_34 * V_38 ;
F_62 ( & V_57 ) ;
V_38 = F_49 ( V_10 ) ;
F_66 ( & V_57 ) ;
return V_38 ;
}
static void F_107 ( unsigned long V_10 )
{
struct V_34 * V_38 ;
V_38 = F_106 ( V_10 ) ;
F_21 ( ! V_38 ) ;
F_104 ( V_38 ) ;
}
static unsigned long F_108 ( unsigned long V_10 )
{
V_10 -= V_68 & ~ ( V_83 - 1 ) ;
V_10 /= V_83 ;
return V_10 ;
}
static struct V_84 * F_109 ( T_6 V_51 )
{
struct V_85 * V_86 ;
struct V_84 * V_87 ;
struct V_34 * V_38 ;
unsigned long V_88 ;
int V_50 , V_26 ;
V_50 = F_110 () ;
V_87 = F_59 ( sizeof( struct V_84 ) ,
V_51 & V_55 , V_50 ) ;
if ( F_60 ( ! V_87 ) )
return F_61 ( - V_23 ) ;
V_38 = F_57 ( V_83 , V_83 ,
V_68 , V_69 ,
V_50 , V_51 ) ;
if ( F_111 ( V_38 ) ) {
F_70 ( V_87 ) ;
return F_112 ( V_38 ) ;
}
V_26 = F_113 ( V_51 ) ;
if ( F_60 ( V_26 ) ) {
F_70 ( V_87 ) ;
F_78 ( V_38 ) ;
return F_61 ( V_26 ) ;
}
F_114 ( & V_87 -> V_89 ) ;
V_87 -> V_38 = V_38 ;
V_87 -> free = V_90 ;
V_87 -> V_91 = 0 ;
F_115 ( V_87 -> V_92 , V_90 ) ;
F_116 ( & V_87 -> V_93 ) ;
V_88 = F_108 ( V_38 -> va_start ) ;
F_62 ( & V_94 ) ;
V_26 = F_117 ( & V_95 , V_88 , V_87 ) ;
F_66 ( & V_94 ) ;
F_21 ( V_26 ) ;
F_118 () ;
V_86 = & F_119 ( V_85 ) ;
V_87 -> V_86 = V_86 ;
F_62 ( & V_86 -> V_89 ) ;
F_56 ( & V_87 -> V_93 , & V_86 -> free ) ;
F_66 ( & V_86 -> V_89 ) ;
F_120 ( V_85 ) ;
return V_87 ;
}
static void F_121 ( struct V_84 * V_87 )
{
struct V_84 * V_42 ;
unsigned long V_88 ;
V_88 = F_108 ( V_87 -> V_38 -> va_start ) ;
F_62 ( & V_94 ) ;
V_42 = F_122 ( & V_95 , V_88 ) ;
F_66 ( & V_94 ) ;
F_21 ( V_42 != V_87 ) ;
F_100 ( V_87 -> V_38 ) ;
F_77 ( V_87 , V_71 ) ;
}
static void F_123 ( int V_96 )
{
F_90 ( V_97 ) ;
struct V_84 * V_87 ;
struct V_84 * V_98 ;
struct V_85 * V_86 = & F_124 ( V_85 , V_96 ) ;
F_93 () ;
F_94 (vb, &vbq->free, free_list) {
if ( ! ( V_87 -> free + V_87 -> V_91 == V_90 && V_87 -> V_91 != V_90 ) )
continue;
F_62 ( & V_87 -> V_89 ) ;
if ( V_87 -> free + V_87 -> V_91 == V_90 && V_87 -> V_91 != V_90 ) {
V_87 -> free = 0 ;
V_87 -> V_91 = V_90 ;
F_125 ( V_87 -> V_92 , V_90 ) ;
F_62 ( & V_86 -> V_89 ) ;
F_75 ( & V_87 -> V_93 ) ;
F_66 ( & V_86 -> V_89 ) ;
F_66 ( & V_87 -> V_89 ) ;
F_95 ( & V_87 -> V_97 , & V_97 ) ;
} else
F_66 ( & V_87 -> V_89 ) ;
}
F_96 () ;
F_98 (vb, n_vb, &purge, purge) {
F_126 ( & V_87 -> V_97 ) ;
F_121 ( V_87 ) ;
}
}
static void F_92 ( void )
{
int V_96 ;
F_127 (cpu)
F_123 ( V_96 ) ;
}
static void * F_128 ( unsigned long V_46 , T_6 V_51 )
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
V_99 = F_129 ( V_46 ) ;
V_101:
F_93 () ;
V_86 = & F_119 ( V_85 ) ;
F_94 (vb, &vbq->free, free_list) {
int V_102 ;
F_62 ( & V_87 -> V_89 ) ;
if ( V_87 -> free < 1UL << V_99 )
goto V_17;
V_102 = V_90 - V_87 -> free ;
V_10 = V_87 -> V_38 -> va_start + ( V_102 << V_79 ) ;
F_21 ( F_108 ( V_10 ) !=
F_108 ( V_87 -> V_38 -> va_start ) ) ;
V_87 -> free -= 1UL << V_99 ;
if ( V_87 -> free == 0 ) {
F_62 ( & V_86 -> V_89 ) ;
F_75 ( & V_87 -> V_93 ) ;
F_66 ( & V_86 -> V_89 ) ;
}
F_66 ( & V_87 -> V_89 ) ;
break;
V_17:
F_66 ( & V_87 -> V_89 ) ;
}
F_120 ( V_85 ) ;
F_96 () ;
if ( ! V_10 ) {
V_87 = F_109 ( V_51 ) ;
if ( F_111 ( V_87 ) )
return V_87 ;
goto V_101;
}
return ( void * ) V_10 ;
}
static void F_130 ( const void * V_10 , unsigned long V_46 )
{
unsigned long V_103 ;
unsigned long V_88 ;
unsigned int V_99 ;
struct V_84 * V_87 ;
F_21 ( V_46 & ~ V_54 ) ;
F_21 ( V_46 > V_15 * V_100 ) ;
F_105 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
V_99 = F_129 ( V_46 ) ;
V_103 = ( unsigned long ) V_10 & ( V_83 - 1 ) ;
V_88 = F_108 ( ( unsigned long ) V_10 ) ;
F_93 () ;
V_87 = F_131 ( & V_95 , V_88 ) ;
F_96 () ;
F_21 ( ! V_87 ) ;
F_20 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
F_62 ( & V_87 -> V_89 ) ;
F_21 ( F_132 ( V_87 -> V_92 , V_103 >> V_79 , V_99 ) ) ;
V_87 -> V_91 += 1UL << V_99 ;
if ( V_87 -> V_91 == V_90 ) {
F_21 ( V_87 -> free ) ;
F_66 ( & V_87 -> V_89 ) ;
F_121 ( V_87 ) ;
} else
F_66 ( & V_87 -> V_89 ) ;
}
void F_133 ( void )
{
unsigned long V_25 = V_82 , V_11 = 0 ;
int V_96 ;
int V_104 = 0 ;
if ( F_60 ( ! V_105 ) )
return;
F_127 (cpu) {
struct V_85 * V_86 = & F_124 ( V_85 , V_96 ) ;
struct V_84 * V_87 ;
F_93 () ;
F_94 (vb, &vbq->free, free_list) {
int V_102 ;
F_62 ( & V_87 -> V_89 ) ;
V_102 = F_134 ( V_87 -> V_92 , V_90 ) ;
while ( V_102 < V_90 ) {
unsigned long V_106 , V_107 ;
int V_108 ;
V_108 = F_135 ( V_87 -> V_92 ,
V_90 , V_102 ) ;
V_106 = V_87 -> V_38 -> va_start + ( V_102 << V_79 ) ;
V_107 = V_87 -> V_38 -> va_start + ( V_108 << V_79 ) ;
V_104 = 1 ;
if ( V_106 < V_25 )
V_25 = V_106 ;
if ( V_107 > V_11 )
V_11 = V_107 ;
V_102 = V_108 ;
V_102 = F_136 ( V_87 -> V_92 ,
V_90 , V_102 ) ;
}
F_66 ( & V_87 -> V_89 ) ;
}
F_96 () ;
}
F_88 ( & V_25 , & V_11 , 1 , V_104 ) ;
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
F_80 ( V_10 , V_10 + V_46 ) ;
if ( F_139 ( V_110 <= V_100 ) )
F_130 ( V_109 , V_46 ) ;
else
F_107 ( V_10 ) ;
}
void * F_140 ( struct V_20 * * V_21 , unsigned int V_110 , int V_50 , T_5 V_19 )
{
unsigned long V_46 = V_110 << V_79 ;
unsigned long V_10 ;
void * V_109 ;
if ( F_139 ( V_110 <= V_100 ) ) {
V_109 = F_128 ( V_46 , V_111 ) ;
if ( F_111 ( V_109 ) )
return NULL ;
V_10 = ( unsigned long ) V_109 ;
} else {
struct V_34 * V_38 ;
V_38 = F_57 ( V_46 , V_15 ,
V_68 , V_69 , V_50 , V_111 ) ;
if ( F_111 ( V_38 ) )
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
V_10 = F_63 ( V_68 + T_9 , V_47 ) ;
T_9 = F_143 ( V_10 + V_113 -> V_46 ) - V_68 ;
V_113 -> V_10 = ( void * ) V_10 ;
F_141 ( V_113 ) ;
}
void T_7 F_144 ( void )
{
struct V_34 * V_38 ;
struct V_112 * V_42 ;
int V_102 ;
F_127 (i) {
struct V_85 * V_86 ;
struct V_3 * V_4 ;
V_86 = & F_124 ( V_85 , V_102 ) ;
F_114 ( & V_86 -> V_89 ) ;
F_116 ( & V_86 -> free ) ;
V_4 = & F_124 ( V_3 , V_102 ) ;
F_145 ( & V_4 -> V_8 ) ;
F_146 ( & V_4 -> V_5 , F_1 ) ;
}
for ( V_42 = V_114 ; V_42 ; V_42 = V_42 -> V_17 ) {
V_38 = F_147 ( sizeof( struct V_34 ) , V_116 ) ;
V_38 -> V_65 = V_117 ;
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
F_105 ( V_10 , V_11 ) ;
F_20 ( V_10 , V_11 ) ;
F_82 ( V_10 , V_11 ) ;
}
int F_151 ( struct V_112 * V_118 , T_5 V_19 , struct V_20 * * * V_21 )
{
unsigned long V_10 = ( unsigned long ) V_118 -> V_10 ;
unsigned long V_11 = V_10 + V_118 -> V_46 - V_15 ;
int V_26 ;
V_26 = F_34 ( V_10 , V_11 , V_19 , * V_21 ) ;
if ( V_26 > 0 ) {
* V_21 += V_26 ;
V_26 = 0 ;
}
return V_26 ;
}
static void F_152 ( struct V_112 * V_113 , struct V_34 * V_38 ,
unsigned long V_65 , const void * V_119 )
{
F_62 ( & V_57 ) ;
V_113 -> V_65 = V_65 ;
V_113 -> V_10 = ( void * ) V_38 -> va_start ;
V_113 -> V_46 = V_38 -> va_end - V_38 -> va_start ;
V_113 -> V_119 = V_119 ;
V_38 -> V_113 = V_113 ;
V_38 -> V_65 |= V_117 ;
F_66 ( & V_57 ) ;
}
static void F_153 ( struct V_112 * V_113 )
{
F_154 () ;
V_113 -> V_65 &= ~ V_120 ;
}
static struct V_112 * F_155 ( unsigned long V_46 ,
unsigned long V_47 , unsigned long V_65 , unsigned long V_25 ,
unsigned long V_11 , int V_50 , T_6 V_51 , const void * V_119 )
{
struct V_34 * V_38 ;
struct V_112 * V_118 ;
F_21 ( F_156 () ) ;
if ( V_65 & V_121 )
V_47 = 1ul << F_157 ( F_84 ( V_46 ) , V_79 , V_122 ) ;
V_46 = F_158 ( V_46 ) ;
if ( F_60 ( ! V_46 ) )
return NULL ;
V_118 = F_159 ( sizeof( * V_118 ) , V_51 & V_55 , V_50 ) ;
if ( F_60 ( ! V_118 ) )
return NULL ;
V_46 += V_15 ;
V_38 = F_57 ( V_46 , V_47 , V_25 , V_11 , V_50 , V_51 ) ;
if ( F_111 ( V_38 ) ) {
F_70 ( V_118 ) ;
return NULL ;
}
F_152 ( V_118 , V_38 , V_65 , V_119 ) ;
return V_118 ;
}
struct V_112 * F_160 ( unsigned long V_46 , unsigned long V_65 ,
unsigned long V_25 , unsigned long V_11 )
{
return F_155 ( V_46 , 1 , V_65 , V_25 , V_11 , V_123 ,
V_111 , F_161 ( 0 ) ) ;
}
struct V_112 * F_162 ( unsigned long V_46 , unsigned long V_65 ,
unsigned long V_25 , unsigned long V_11 ,
const void * V_119 )
{
return F_155 ( V_46 , 1 , V_65 , V_25 , V_11 , V_123 ,
V_111 , V_119 ) ;
}
struct V_112 * F_163 ( unsigned long V_46 , unsigned long V_65 )
{
return F_155 ( V_46 , 1 , V_65 , V_68 , V_69 ,
V_123 , V_111 ,
F_161 ( 0 ) ) ;
}
struct V_112 * F_164 ( unsigned long V_46 , unsigned long V_65 ,
const void * V_119 )
{
return F_155 ( V_46 , 1 , V_65 , V_68 , V_69 ,
V_123 , V_111 , V_119 ) ;
}
struct V_112 * F_165 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_106 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_65 & V_117 )
return V_38 -> V_113 ;
return NULL ;
}
struct V_112 * F_166 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_106 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_65 & V_117 ) {
struct V_112 * V_113 = V_38 -> V_113 ;
F_62 ( & V_57 ) ;
V_38 -> V_113 = NULL ;
V_38 -> V_65 &= ~ V_117 ;
F_66 ( & V_57 ) ;
F_80 ( V_38 -> va_start , V_38 -> va_end ) ;
F_104 ( V_38 ) ;
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
if ( F_167 ( ! F_168 ( V_10 ) , L_3 ,
V_10 ) )
return;
V_118 = F_166 ( V_10 ) ;
if ( F_60 ( ! V_118 ) ) {
F_167 ( 1 , V_125 L_4 ,
V_10 ) ;
return;
}
F_138 ( V_10 , V_118 -> V_46 ) ;
F_169 ( V_10 , V_118 -> V_46 ) ;
if ( V_124 ) {
int V_102 ;
for ( V_102 = 0 ; V_102 < V_118 -> V_126 ; V_102 ++ ) {
struct V_20 * V_20 = V_118 -> V_21 [ V_102 ] ;
F_21 ( ! V_20 ) ;
F_170 ( V_20 ) ;
}
if ( V_118 -> V_65 & V_127 )
F_171 ( V_118 -> V_21 ) ;
else
F_70 ( V_118 -> V_21 ) ;
}
F_70 ( V_118 ) ;
return;
}
void F_171 ( const void * V_10 )
{
F_21 ( F_172 () ) ;
F_173 ( V_10 ) ;
if ( ! V_10 )
return;
if ( F_60 ( F_156 () ) ) {
struct V_3 * V_4 = & F_174 ( V_3 ) ;
if ( F_175 ( (struct V_6 * ) V_10 , & V_4 -> V_8 ) )
F_176 ( & V_4 -> V_5 ) ;
} else
F_5 ( V_10 , 1 ) ;
}
void F_177 ( const void * V_10 )
{
F_21 ( F_156 () ) ;
F_178 () ;
if ( V_10 )
F_5 ( V_10 , 0 ) ;
}
void * F_179 ( struct V_20 * * V_21 , unsigned int V_110 ,
unsigned long V_65 , T_5 V_19 )
{
struct V_112 * V_118 ;
F_178 () ;
if ( V_110 > V_128 )
return NULL ;
V_118 = F_164 ( ( V_110 << V_79 ) , V_65 ,
F_161 ( 0 ) ) ;
if ( ! V_118 )
return NULL ;
if ( F_151 ( V_118 , V_19 , & V_21 ) ) {
F_177 ( V_118 -> V_10 ) ;
return NULL ;
}
return V_118 -> V_10 ;
}
static void * F_180 ( struct V_112 * V_118 , T_6 V_51 ,
T_5 V_19 , int V_50 , const void * V_119 )
{
const int V_99 = 0 ;
struct V_20 * * V_21 ;
unsigned int V_126 , V_129 , V_102 ;
T_6 V_130 = ( V_51 & V_55 ) | V_131 ;
V_126 = ( V_118 -> V_46 - V_15 ) >> V_79 ;
V_129 = ( V_126 * sizeof( struct V_20 * ) ) ;
V_118 -> V_126 = V_126 ;
if ( V_129 > V_15 ) {
V_21 = F_181 ( V_129 , 1 , V_130 | V_132 ,
V_133 , V_50 , V_119 ) ;
V_118 -> V_65 |= V_127 ;
} else {
V_21 = F_59 ( V_129 , V_130 , V_50 ) ;
}
V_118 -> V_21 = V_21 ;
V_118 -> V_119 = V_119 ;
if ( ! V_118 -> V_21 ) {
F_166 ( V_118 -> V_10 ) ;
F_70 ( V_118 ) ;
return NULL ;
}
for ( V_102 = 0 ; V_102 < V_118 -> V_126 ; V_102 ++ ) {
struct V_20 * V_20 ;
T_6 V_134 = V_51 | V_135 ;
if ( V_50 < 0 )
V_20 = F_182 ( V_134 ) ;
else
V_20 = F_183 ( V_50 , V_134 , V_99 ) ;
if ( F_60 ( ! V_20 ) ) {
V_118 -> V_126 = V_102 ;
goto V_136;
}
V_118 -> V_21 [ V_102 ] = V_20 ;
}
if ( F_151 ( V_118 , V_19 , & V_21 ) )
goto V_136;
return V_118 -> V_10 ;
V_136:
F_184 ( V_51 , V_99 ,
L_5 ,
( V_118 -> V_126 * V_15 ) , V_118 -> V_46 ) ;
F_171 ( V_118 -> V_10 ) ;
return NULL ;
}
void * F_185 ( unsigned long V_46 , unsigned long V_47 ,
unsigned long V_25 , unsigned long V_11 , T_6 V_51 ,
T_5 V_19 , int V_50 , const void * V_119 )
{
struct V_112 * V_118 ;
void * V_10 ;
unsigned long V_137 = V_46 ;
V_46 = F_158 ( V_46 ) ;
if ( ! V_46 || ( V_46 >> V_79 ) > V_128 )
goto V_136;
V_118 = F_155 ( V_46 , V_47 , V_138 | V_120 ,
V_25 , V_11 , V_50 , V_51 , V_119 ) ;
if ( ! V_118 )
goto V_136;
V_10 = F_180 ( V_118 , V_51 , V_19 , V_50 , V_119 ) ;
if ( ! V_10 )
goto V_136;
F_153 ( V_118 ) ;
F_186 ( V_10 , V_137 , 3 , V_51 ) ;
return V_10 ;
V_136:
F_184 ( V_51 , 0 ,
L_6 ,
V_137 ) ;
return NULL ;
}
static void * F_181 ( unsigned long V_46 , unsigned long V_47 ,
T_6 V_51 , T_5 V_19 ,
int V_50 , const void * V_119 )
{
return F_185 ( V_46 , V_47 , V_68 , V_69 ,
V_51 , V_19 , V_50 , V_119 ) ;
}
void * F_187 ( unsigned long V_46 , T_6 V_51 , T_5 V_19 )
{
return F_181 ( V_46 , 1 , V_51 , V_19 , V_123 ,
F_161 ( 0 ) ) ;
}
static inline void * F_188 ( unsigned long V_46 ,
int V_50 , T_6 V_65 )
{
return F_181 ( V_46 , 1 , V_65 , V_133 ,
V_50 , F_161 ( 0 ) ) ;
}
void * F_189 ( unsigned long V_46 )
{
return F_188 ( V_46 , V_123 ,
V_111 | V_132 ) ;
}
void * F_190 ( unsigned long V_46 )
{
return F_188 ( V_46 , V_123 ,
V_111 | V_132 | V_131 ) ;
}
void * F_191 ( unsigned long V_46 )
{
struct V_112 * V_118 ;
void * V_27 ;
V_27 = F_181 ( V_46 , V_139 ,
V_111 | V_132 | V_131 ,
V_133 , V_123 ,
F_161 ( 0 ) ) ;
if ( V_27 ) {
V_118 = F_165 ( V_27 ) ;
V_118 -> V_65 |= V_140 ;
}
return V_27 ;
}
void * F_192 ( unsigned long V_46 , int V_50 )
{
return F_181 ( V_46 , 1 , V_111 | V_132 , V_133 ,
V_50 , F_161 ( 0 ) ) ;
}
void * F_193 ( unsigned long V_46 , int V_50 )
{
return F_188 ( V_46 , V_50 ,
V_111 | V_132 | V_131 ) ;
}
void * F_194 ( unsigned long V_46 )
{
return F_181 ( V_46 , 1 , V_111 | V_132 , V_141 ,
V_123 , F_161 ( 0 ) ) ;
}
void * F_195 ( unsigned long V_46 )
{
return F_181 ( V_46 , 1 , V_142 , V_133 ,
V_123 , F_161 ( 0 ) ) ;
}
void * F_196 ( unsigned long V_46 )
{
struct V_112 * V_118 ;
void * V_27 ;
V_27 = F_181 ( V_46 , 1 , V_142 | V_131 , V_133 ,
V_123 , F_161 ( 0 ) ) ;
if ( V_27 ) {
V_118 = F_165 ( V_27 ) ;
V_118 -> V_65 |= V_140 ;
}
return V_27 ;
}
static int F_197 ( char * V_143 , char * V_10 , unsigned long V_110 )
{
struct V_20 * V_4 ;
int V_144 = 0 ;
while ( V_110 ) {
unsigned long V_103 , V_145 ;
V_103 = ( unsigned long ) V_10 & ~ V_54 ;
V_145 = V_15 - V_103 ;
if ( V_145 > V_110 )
V_145 = V_110 ;
V_4 = F_39 ( V_10 ) ;
if ( V_4 ) {
void * V_146 = F_198 ( V_4 ) ;
memcpy ( V_143 , V_146 + V_103 , V_145 ) ;
F_199 ( V_146 ) ;
} else
memset ( V_143 , 0 , V_145 ) ;
V_10 += V_145 ;
V_143 += V_145 ;
V_144 += V_145 ;
V_110 -= V_145 ;
}
return V_144 ;
}
static int F_200 ( char * V_143 , char * V_10 , unsigned long V_110 )
{
struct V_20 * V_4 ;
int V_144 = 0 ;
while ( V_110 ) {
unsigned long V_103 , V_145 ;
V_103 = ( unsigned long ) V_10 & ~ V_54 ;
V_145 = V_15 - V_103 ;
if ( V_145 > V_110 )
V_145 = V_110 ;
V_4 = F_39 ( V_10 ) ;
if ( V_4 ) {
void * V_146 = F_198 ( V_4 ) ;
memcpy ( V_146 + V_103 , V_143 , V_145 ) ;
F_199 ( V_146 ) ;
}
V_10 += V_145 ;
V_143 += V_145 ;
V_144 += V_145 ;
V_110 -= V_145 ;
}
return V_144 ;
}
long F_201 ( char * V_143 , char * V_10 , unsigned long V_110 )
{
struct V_34 * V_38 ;
struct V_112 * V_113 ;
char * V_147 , * V_148 = V_143 ;
unsigned long V_149 = V_110 ;
unsigned long V_36 ;
if ( ( unsigned long ) V_10 + V_110 < V_110 )
V_110 = - ( unsigned long ) V_10 ;
F_62 ( & V_57 ) ;
F_202 (va, &vmap_area_list, list) {
if ( ! V_110 )
break;
if ( ! ( V_38 -> V_65 & V_117 ) )
continue;
V_113 = V_38 -> V_113 ;
V_147 = ( char * ) V_113 -> V_10 ;
if ( V_10 >= V_147 + V_113 -> V_46 - V_15 )
continue;
while ( V_10 < V_147 ) {
if ( V_110 == 0 )
goto V_150;
* V_143 = '\0' ;
V_143 ++ ;
V_10 ++ ;
V_110 -- ;
}
V_36 = V_147 + V_113 -> V_46 - V_15 - V_10 ;
if ( V_36 > V_110 )
V_36 = V_110 ;
if ( ! ( V_113 -> V_65 & V_121 ) )
F_197 ( V_143 , V_10 , V_36 ) ;
else
memset ( V_143 , 0 , V_36 ) ;
V_143 += V_36 ;
V_10 += V_36 ;
V_110 -= V_36 ;
}
V_150:
F_66 ( & V_57 ) ;
if ( V_143 == V_148 )
return 0 ;
if ( V_143 != V_148 + V_149 )
memset ( V_143 , 0 , V_149 - ( V_143 - V_148 ) ) ;
return V_149 ;
}
long F_203 ( char * V_143 , char * V_10 , unsigned long V_110 )
{
struct V_34 * V_38 ;
struct V_112 * V_113 ;
char * V_147 ;
unsigned long V_36 , V_149 ;
int V_144 = 0 ;
if ( ( unsigned long ) V_10 + V_110 < V_110 )
V_110 = - ( unsigned long ) V_10 ;
V_149 = V_110 ;
F_62 ( & V_57 ) ;
F_202 (va, &vmap_area_list, list) {
if ( ! V_110 )
break;
if ( ! ( V_38 -> V_65 & V_117 ) )
continue;
V_113 = V_38 -> V_113 ;
V_147 = ( char * ) V_113 -> V_10 ;
if ( V_10 >= V_147 + V_113 -> V_46 - V_15 )
continue;
while ( V_10 < V_147 ) {
if ( V_110 == 0 )
goto V_150;
V_143 ++ ;
V_10 ++ ;
V_110 -- ;
}
V_36 = V_147 + V_113 -> V_46 - V_15 - V_10 ;
if ( V_36 > V_110 )
V_36 = V_110 ;
if ( ! ( V_113 -> V_65 & V_121 ) ) {
F_200 ( V_143 , V_10 , V_36 ) ;
V_144 ++ ;
}
V_143 += V_36 ;
V_10 += V_36 ;
V_110 -= V_36 ;
}
V_150:
F_66 ( & V_57 ) ;
if ( ! V_144 )
return 0 ;
return V_149 ;
}
int F_204 ( struct V_151 * V_152 , unsigned long V_153 ,
void * V_154 , unsigned long V_46 )
{
struct V_112 * V_118 ;
V_46 = F_158 ( V_46 ) ;
if ( ! F_168 ( V_153 ) || ! F_168 ( V_154 ) )
return - V_155 ;
V_118 = F_165 ( V_154 ) ;
if ( ! V_118 )
return - V_155 ;
if ( ! ( V_118 -> V_65 & V_140 ) )
return - V_155 ;
if ( V_154 + V_46 > V_118 -> V_10 + V_118 -> V_46 )
return - V_155 ;
do {
struct V_20 * V_20 = F_39 ( V_154 ) ;
int V_27 ;
V_27 = F_205 ( V_152 , V_153 , V_20 ) ;
if ( V_27 )
return V_27 ;
V_153 += V_15 ;
V_154 += V_15 ;
V_46 -= V_15 ;
} while ( V_46 > 0 );
V_152 -> V_156 |= V_157 | V_158 ;
return 0 ;
}
int F_206 ( struct V_151 * V_152 , void * V_10 ,
unsigned long V_159 )
{
return F_204 ( V_152 , V_152 -> V_160 ,
V_10 + ( V_159 << V_79 ) ,
V_152 -> V_161 - V_152 -> V_160 ) ;
}
static int F_207 ( T_2 * V_12 , T_10 V_162 , unsigned long V_10 , void * V_163 )
{
T_2 * * * V_4 = V_163 ;
if ( V_4 ) {
* ( * V_4 ) = V_12 ;
( * V_4 ) ++ ;
}
return 0 ;
}
struct V_112 * F_208 ( T_8 V_46 , T_2 * * V_164 )
{
struct V_112 * V_118 ;
V_118 = F_164 ( V_46 , V_121 ,
F_161 ( 0 ) ) ;
if ( V_118 == NULL )
return NULL ;
if ( F_209 ( & V_14 , ( unsigned long ) V_118 -> V_10 ,
V_46 , F_207 , V_164 ? & V_164 : NULL ) ) {
F_210 ( V_118 ) ;
return NULL ;
}
return V_118 ;
}
void F_210 ( struct V_112 * V_118 )
{
struct V_112 * V_27 ;
V_27 = F_166 ( V_118 -> V_10 ) ;
F_21 ( V_27 != V_118 ) ;
F_70 ( V_118 ) ;
}
static struct V_34 * F_211 ( struct V_35 * V_36 )
{
return V_36 ? F_50 ( V_36 , struct V_34 , V_35 ) : NULL ;
}
static bool F_212 ( unsigned long V_11 ,
struct V_34 * * V_165 ,
struct V_34 * * V_166 )
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
* V_165 = V_38 ;
* V_166 = F_211 ( F_55 ( & ( * V_165 ) -> V_35 ) ) ;
} else {
* V_166 = V_38 ;
* V_165 = F_211 ( F_213 ( & ( * V_166 ) -> V_35 ) ) ;
}
return true ;
}
static unsigned long F_214 ( struct V_34 * * V_165 ,
struct V_34 * * V_166 ,
unsigned long V_47 )
{
const unsigned long V_167 = V_69 & ~ ( V_47 - 1 ) ;
unsigned long V_10 ;
if ( * V_165 )
V_10 = F_215 ( ( * V_165 ) -> va_start & ~ ( V_47 - 1 ) , V_167 ) ;
else
V_10 = V_167 ;
while ( * V_166 && ( * V_166 ) -> va_end > V_10 ) {
* V_165 = * V_166 ;
* V_166 = F_211 ( F_55 ( & ( * V_165 ) -> V_35 ) ) ;
}
return V_10 ;
}
struct V_112 * * F_216 ( const unsigned long * V_168 ,
const T_8 * V_169 , int V_170 ,
T_8 V_47 )
{
const unsigned long V_171 = F_63 ( V_68 , V_47 ) ;
const unsigned long V_167 = V_69 & ~ ( V_47 - 1 ) ;
struct V_34 * * V_172 , * V_44 , * V_17 ;
struct V_112 * * V_173 ;
int V_118 , V_174 , V_175 , V_176 ;
unsigned long V_177 , V_25 , V_11 , V_178 ;
bool V_52 = false ;
F_21 ( V_47 & ~ V_54 || ! F_58 ( V_47 ) ) ;
for ( V_175 = 0 , V_118 = 0 ; V_118 < V_170 ; V_118 ++ ) {
V_25 = V_168 [ V_118 ] ;
V_11 = V_25 + V_169 [ V_118 ] ;
F_21 ( ! F_217 ( V_168 [ V_118 ] , V_47 ) ) ;
F_21 ( ! F_217 ( V_169 [ V_118 ] , V_47 ) ) ;
if ( V_25 > V_168 [ V_175 ] )
V_175 = V_118 ;
for ( V_174 = 0 ; V_174 < V_170 ; V_174 ++ ) {
unsigned long V_179 = V_168 [ V_174 ] ;
unsigned long V_180 = V_179 + V_169 [ V_174 ] ;
if ( V_174 == V_118 )
continue;
F_21 ( V_179 >= V_25 && V_179 < V_11 ) ;
F_21 ( V_180 <= V_11 && V_180 > V_25 ) ;
}
}
V_178 = V_168 [ V_175 ] + V_169 [ V_175 ] ;
if ( V_167 - V_171 < V_178 ) {
F_9 ( true ) ;
return NULL ;
}
V_173 = F_218 ( V_170 , sizeof( V_173 [ 0 ] ) , V_111 ) ;
V_172 = F_218 ( V_170 , sizeof( V_172 [ 0 ] ) , V_111 ) ;
if ( ! V_172 || ! V_173 )
goto V_181;
for ( V_118 = 0 ; V_118 < V_170 ; V_118 ++ ) {
V_172 [ V_118 ] = F_147 ( sizeof( struct V_34 ) , V_111 ) ;
V_173 [ V_118 ] = F_147 ( sizeof( struct V_112 ) , V_111 ) ;
if ( ! V_172 [ V_118 ] || ! V_173 [ V_118 ] )
goto V_182;
}
V_56:
F_62 ( & V_57 ) ;
V_118 = V_176 = V_175 ;
V_25 = V_168 [ V_118 ] ;
V_11 = V_25 + V_169 [ V_118 ] ;
if ( ! F_212 ( V_70 , & V_17 , & V_44 ) ) {
V_177 = V_167 - V_178 ;
goto V_64;
}
V_177 = F_214 ( & V_17 , & V_44 , V_47 ) - V_11 ;
while ( true ) {
F_21 ( V_17 && V_17 -> va_end <= V_177 + V_11 ) ;
F_21 ( V_44 && V_44 -> va_end > V_177 + V_11 ) ;
if ( V_177 + V_178 < V_171 + V_178 ) {
F_66 ( & V_57 ) ;
if ( ! V_52 ) {
F_67 () ;
V_52 = true ;
goto V_56;
}
goto V_182;
}
if ( V_17 && V_17 -> va_start < V_177 + V_11 ) {
V_177 = F_214 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_176 = V_118 ;
continue;
}
if ( V_44 && V_44 -> va_end > V_177 + V_25 ) {
V_17 = V_44 ;
V_44 = F_211 ( F_55 ( & V_17 -> V_35 ) ) ;
V_177 = F_214 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_176 = V_118 ;
continue;
}
V_118 = ( V_118 + V_170 - 1 ) % V_170 ;
if ( V_118 == V_176 )
break;
V_25 = V_168 [ V_118 ] ;
V_11 = V_25 + V_169 [ V_118 ] ;
F_212 ( V_177 + V_11 , & V_17 , & V_44 ) ;
}
V_64:
for ( V_118 = 0 ; V_118 < V_170 ; V_118 ++ ) {
struct V_34 * V_38 = V_172 [ V_118 ] ;
V_38 -> va_start = V_177 + V_168 [ V_118 ] ;
V_38 -> va_end = V_38 -> va_start + V_169 [ V_118 ] ;
F_51 ( V_38 ) ;
}
V_70 = V_177 + V_168 [ V_175 ] ;
F_66 ( & V_57 ) ;
for ( V_118 = 0 ; V_118 < V_170 ; V_118 ++ )
F_152 ( V_173 [ V_118 ] , V_172 [ V_118 ] , V_138 ,
F_216 ) ;
F_70 ( V_172 ) ;
return V_173 ;
V_182:
for ( V_118 = 0 ; V_118 < V_170 ; V_118 ++ ) {
F_70 ( V_172 [ V_118 ] ) ;
F_70 ( V_173 [ V_118 ] ) ;
}
V_181:
F_70 ( V_172 ) ;
F_70 ( V_173 ) ;
return NULL ;
}
void F_219 ( struct V_112 * * V_173 , int V_170 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_170 ; V_102 ++ )
F_210 ( V_173 [ V_102 ] ) ;
F_70 ( V_173 ) ;
}
static void * F_220 ( struct V_183 * V_184 , T_11 * V_185 )
__acquires( &vmap_area_lock
static void * F_221 ( struct V_183 * V_184 , void * V_4 , T_11 * V_185 )
{
struct V_34 * V_38 = V_4 , * V_17 ;
++ * V_185 ;
V_17 = F_65 ( V_38 -> V_8 . V_17 , F_222 ( * V_38 ) , V_8 ) ;
if ( & V_17 -> V_8 != & V_45 )
return V_17 ;
return NULL ;
}
static void F_223 ( struct V_183 * V_184 , void * V_4 )
__releases( &vmap_area_lock
static void F_224 ( struct V_183 * V_184 , struct V_112 * V_186 )
{
if ( F_225 ( V_187 ) ) {
unsigned int V_22 , * V_188 = V_184 -> V_189 ;
if ( ! V_188 )
return;
memset ( V_188 , 0 , V_190 * sizeof( unsigned int ) ) ;
for ( V_22 = 0 ; V_22 < V_186 -> V_126 ; V_22 ++ )
V_188 [ F_226 ( V_186 -> V_21 [ V_22 ] ) ] ++ ;
F_227 (nr, N_HIGH_MEMORY)
if ( V_188 [ V_22 ] )
F_228 ( V_184 , L_7 , V_22 , V_188 [ V_22 ] ) ;
}
}
static int F_229 ( struct V_183 * V_184 , void * V_4 )
{
struct V_34 * V_38 = V_4 ;
struct V_112 * V_186 ;
if ( V_38 -> V_65 & ( V_78 | V_81 ) )
return 0 ;
if ( ! ( V_38 -> V_65 & V_117 ) ) {
F_228 ( V_184 , L_8 ,
( void * ) V_38 -> va_start , ( void * ) V_38 -> va_end ,
V_38 -> va_end - V_38 -> va_start ) ;
return 0 ;
}
V_186 = V_38 -> V_113 ;
F_230 () ;
if ( V_186 -> V_65 & V_120 )
return 0 ;
F_228 ( V_184 , L_9 ,
V_186 -> V_10 , V_186 -> V_10 + V_186 -> V_46 , V_186 -> V_46 ) ;
if ( V_186 -> V_119 )
F_228 ( V_184 , L_10 , V_186 -> V_119 ) ;
if ( V_186 -> V_126 )
F_228 ( V_184 , L_11 , V_186 -> V_126 ) ;
if ( V_186 -> V_191 )
F_228 ( V_184 , L_12 , ( unsigned long long ) V_186 -> V_191 ) ;
if ( V_186 -> V_65 & V_121 )
F_228 ( V_184 , L_13 ) ;
if ( V_186 -> V_65 & V_138 )
F_228 ( V_184 , L_14 ) ;
if ( V_186 -> V_65 & V_192 )
F_228 ( V_184 , L_15 ) ;
if ( V_186 -> V_65 & V_140 )
F_228 ( V_184 , L_16 ) ;
if ( V_186 -> V_65 & V_127 )
F_228 ( V_184 , L_17 ) ;
F_224 ( V_184 , V_186 ) ;
F_231 ( V_184 , '\n' ) ;
return 0 ;
}
static int F_232 ( struct V_193 * V_193 , struct V_194 * V_194 )
{
unsigned int * V_195 = NULL ;
int V_27 ;
if ( F_225 ( V_187 ) ) {
V_195 = F_233 ( V_190 * sizeof( unsigned int ) , V_111 ) ;
if ( V_195 == NULL )
return - V_23 ;
}
V_27 = F_234 ( V_194 , & V_196 ) ;
if ( ! V_27 ) {
struct V_183 * V_184 = V_194 -> V_197 ;
V_184 -> V_189 = V_195 ;
} else
F_70 ( V_195 ) ;
return V_27 ;
}
static int T_7 F_235 ( void )
{
F_236 ( L_18 , V_198 , NULL , & V_199 ) ;
return 0 ;
}
void F_237 ( struct V_200 * V_201 )
{
struct V_34 * V_38 ;
unsigned long V_202 ;
unsigned long V_203 ;
V_201 -> V_204 = 0 ;
V_201 -> V_205 = 0 ;
V_203 = V_68 ;
F_62 ( & V_57 ) ;
if ( F_238 ( & V_45 ) ) {
V_201 -> V_205 = V_206 ;
goto V_207;
}
F_202 (va, &vmap_area_list, list) {
unsigned long V_10 = V_38 -> va_start ;
if ( V_10 < V_68 )
continue;
if ( V_10 >= V_69 )
break;
if ( V_38 -> V_65 & ( V_78 | V_81 ) )
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
F_66 ( & V_57 ) ;
}
