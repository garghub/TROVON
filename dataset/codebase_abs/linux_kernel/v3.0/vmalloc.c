static void F_1 ( T_1 * V_1 , unsigned long V_2 , unsigned long V_3 )
{
T_2 * V_4 ;
V_4 = F_2 ( V_1 , V_2 ) ;
do {
T_2 V_5 = F_3 ( & V_6 , V_2 , V_4 ) ;
F_4 ( ! F_5 ( V_5 ) && ! F_6 ( V_5 ) ) ;
} while ( V_4 ++ , V_2 += V_7 , V_2 != V_3 );
}
static void F_7 ( T_3 * V_8 , unsigned long V_2 , unsigned long V_3 )
{
T_1 * V_1 ;
unsigned long V_9 ;
V_1 = F_8 ( V_8 , V_2 ) ;
do {
V_9 = F_9 ( V_2 , V_3 ) ;
if ( F_10 ( V_1 ) )
continue;
F_1 ( V_1 , V_2 , V_9 ) ;
} while ( V_1 ++ , V_2 = V_9 , V_2 != V_3 );
}
static void F_11 ( T_4 * V_10 , unsigned long V_2 , unsigned long V_3 )
{
T_3 * V_8 ;
unsigned long V_9 ;
V_8 = F_12 ( V_10 , V_2 ) ;
do {
V_9 = F_13 ( V_2 , V_3 ) ;
if ( F_14 ( V_8 ) )
continue;
F_7 ( V_8 , V_2 , V_9 ) ;
} while ( V_8 ++ , V_2 = V_9 , V_2 != V_3 );
}
static void F_15 ( unsigned long V_2 , unsigned long V_3 )
{
T_4 * V_10 ;
unsigned long V_9 ;
F_16 ( V_2 >= V_3 ) ;
V_10 = F_17 ( V_2 ) ;
do {
V_9 = F_18 ( V_2 , V_3 ) ;
if ( F_19 ( V_10 ) )
continue;
F_11 ( V_10 , V_2 , V_9 ) ;
} while ( V_10 ++ , V_2 = V_9 , V_2 != V_3 );
}
static int F_20 ( T_1 * V_1 , unsigned long V_2 ,
unsigned long V_3 , T_5 V_11 , struct V_12 * * V_13 , int * V_14 )
{
T_2 * V_4 ;
V_4 = F_21 ( V_1 , V_2 ) ;
if ( ! V_4 )
return - V_15 ;
do {
struct V_12 * V_12 = V_13 [ * V_14 ] ;
if ( F_4 ( ! F_5 ( * V_4 ) ) )
return - V_16 ;
if ( F_4 ( ! V_12 ) )
return - V_15 ;
F_22 ( & V_6 , V_2 , V_4 , F_23 ( V_12 , V_11 ) ) ;
( * V_14 ) ++ ;
} while ( V_4 ++ , V_2 += V_7 , V_2 != V_3 );
return 0 ;
}
static int F_24 ( T_3 * V_8 , unsigned long V_2 ,
unsigned long V_3 , T_5 V_11 , struct V_12 * * V_13 , int * V_14 )
{
T_1 * V_1 ;
unsigned long V_9 ;
V_1 = F_25 ( & V_6 , V_8 , V_2 ) ;
if ( ! V_1 )
return - V_15 ;
do {
V_9 = F_9 ( V_2 , V_3 ) ;
if ( F_20 ( V_1 , V_2 , V_9 , V_11 , V_13 , V_14 ) )
return - V_15 ;
} while ( V_1 ++ , V_2 = V_9 , V_2 != V_3 );
return 0 ;
}
static int F_26 ( T_4 * V_10 , unsigned long V_2 ,
unsigned long V_3 , T_5 V_11 , struct V_12 * * V_13 , int * V_14 )
{
T_3 * V_8 ;
unsigned long V_9 ;
V_8 = F_27 ( & V_6 , V_10 , V_2 ) ;
if ( ! V_8 )
return - V_15 ;
do {
V_9 = F_13 ( V_2 , V_3 ) ;
if ( F_24 ( V_8 , V_2 , V_9 , V_11 , V_13 , V_14 ) )
return - V_15 ;
} while ( V_8 ++ , V_2 = V_9 , V_2 != V_3 );
return 0 ;
}
static int F_28 ( unsigned long V_17 , unsigned long V_3 ,
T_5 V_11 , struct V_12 * * V_13 )
{
T_4 * V_10 ;
unsigned long V_9 ;
unsigned long V_2 = V_17 ;
int V_18 = 0 ;
int V_14 = 0 ;
F_16 ( V_2 >= V_3 ) ;
V_10 = F_17 ( V_2 ) ;
do {
V_9 = F_18 ( V_2 , V_3 ) ;
V_18 = F_26 ( V_10 , V_2 , V_9 , V_11 , V_13 , & V_14 ) ;
if ( V_18 )
return V_18 ;
} while ( V_10 ++ , V_2 = V_9 , V_2 != V_3 );
return V_14 ;
}
static int F_29 ( unsigned long V_17 , unsigned long V_3 ,
T_5 V_11 , struct V_12 * * V_13 )
{
int V_19 ;
V_19 = F_28 ( V_17 , V_3 , V_11 , V_13 ) ;
F_30 ( V_17 , V_3 ) ;
return V_19 ;
}
int F_31 ( const void * V_20 )
{
#if F_32 ( V_21 ) && F_32 ( V_22 )
unsigned long V_2 = ( unsigned long ) V_20 ;
if ( V_2 >= V_22 && V_2 < V_23 )
return 1 ;
#endif
return F_33 ( V_20 ) ;
}
struct V_12 * F_34 ( const void * V_24 )
{
unsigned long V_2 = ( unsigned long ) V_24 ;
struct V_12 * V_12 = NULL ;
T_4 * V_10 = F_17 ( V_2 ) ;
F_35 ( ! F_31 ( V_24 ) ) ;
if ( ! F_36 ( * V_10 ) ) {
T_3 * V_8 = F_12 ( V_10 , V_2 ) ;
if ( ! F_37 ( * V_8 ) ) {
T_1 * V_1 = F_8 ( V_8 , V_2 ) ;
if ( ! F_38 ( * V_1 ) ) {
T_2 * V_25 , V_4 ;
V_25 = F_39 ( V_1 , V_2 ) ;
V_4 = * V_25 ;
if ( F_6 ( V_4 ) )
V_12 = F_40 ( V_4 ) ;
F_41 ( V_25 ) ;
}
}
}
return V_12 ;
}
unsigned long F_42 ( const void * V_24 )
{
return F_43 ( F_34 ( V_24 ) ) ;
}
static struct V_26 * F_44 ( unsigned long V_2 )
{
struct V_27 * V_28 = V_29 . V_27 ;
while ( V_28 ) {
struct V_26 * V_30 ;
V_30 = F_45 ( V_28 , struct V_26 , V_27 ) ;
if ( V_2 < V_30 -> va_start )
V_28 = V_28 -> V_31 ;
else if ( V_2 > V_30 -> va_start )
V_28 = V_28 -> V_32 ;
else
return V_30 ;
}
return NULL ;
}
static void F_46 ( struct V_26 * V_30 )
{
struct V_27 * * V_33 = & V_29 . V_27 ;
struct V_27 * V_34 = NULL ;
struct V_27 * V_35 ;
while ( * V_33 ) {
struct V_26 * V_36 ;
V_34 = * V_33 ;
V_36 = F_45 ( V_34 , struct V_26 , V_27 ) ;
if ( V_30 -> va_start < V_36 -> va_end )
V_33 = & ( * V_33 ) -> V_31 ;
else if ( V_30 -> va_end > V_36 -> va_start )
V_33 = & ( * V_33 ) -> V_32 ;
else
F_47 () ;
}
F_48 ( & V_30 -> V_27 , V_34 , V_33 ) ;
F_49 ( & V_30 -> V_27 , & V_29 ) ;
V_35 = F_50 ( & V_30 -> V_27 ) ;
if ( V_35 ) {
struct V_26 * V_37 ;
V_37 = F_45 ( V_35 , struct V_26 , V_27 ) ;
F_51 ( & V_30 -> V_38 , & V_37 -> V_38 ) ;
} else
F_51 ( & V_30 -> V_38 , & V_39 ) ;
}
static struct V_26 * F_52 ( unsigned long V_40 ,
unsigned long V_41 ,
unsigned long V_42 , unsigned long V_43 ,
int V_44 , T_6 V_45 )
{
struct V_26 * V_30 ;
struct V_27 * V_28 ;
unsigned long V_2 ;
int V_46 = 0 ;
struct V_26 * V_47 ;
F_16 ( ! V_40 ) ;
F_16 ( V_40 & ~ V_48 ) ;
F_16 ( ! F_53 ( V_41 ) ) ;
V_30 = F_54 ( sizeof( struct V_26 ) ,
V_45 & V_49 , V_44 ) ;
if ( F_55 ( ! V_30 ) )
return F_56 ( - V_15 ) ;
V_50:
F_57 ( & V_51 ) ;
if ( ! V_52 ||
V_40 < V_53 ||
V_42 < V_54 ||
V_41 < V_55 ) {
V_56:
V_53 = 0 ;
V_52 = NULL ;
}
V_54 = V_42 ;
V_55 = V_41 ;
if ( V_52 ) {
V_47 = F_45 ( V_52 , struct V_26 , V_27 ) ;
V_2 = F_58 ( V_47 -> va_end , V_41 ) ;
if ( V_2 < V_42 )
goto V_56;
if ( V_2 + V_40 - 1 < V_2 )
goto V_57;
} else {
V_2 = F_58 ( V_42 , V_41 ) ;
if ( V_2 + V_40 - 1 < V_2 )
goto V_57;
V_28 = V_29 . V_27 ;
V_47 = NULL ;
while ( V_28 ) {
struct V_26 * V_35 ;
V_35 = F_45 ( V_28 , struct V_26 , V_27 ) ;
if ( V_35 -> va_end >= V_2 ) {
V_47 = V_35 ;
if ( V_35 -> va_start <= V_2 )
break;
V_28 = V_28 -> V_31 ;
} else
V_28 = V_28 -> V_32 ;
}
if ( ! V_47 )
goto V_58;
}
while ( V_2 + V_40 > V_47 -> va_start && V_2 + V_40 <= V_43 ) {
if ( V_2 + V_53 < V_47 -> va_start )
V_53 = V_47 -> va_start - V_2 ;
V_2 = F_58 ( V_47 -> va_end , V_41 ) ;
if ( V_2 + V_40 - 1 < V_2 )
goto V_57;
V_28 = F_59 ( & V_47 -> V_27 ) ;
if ( V_28 )
V_47 = F_45 ( V_28 , struct V_26 , V_27 ) ;
else
goto V_58;
}
V_58:
if ( V_2 + V_40 > V_43 )
goto V_57;
V_30 -> va_start = V_2 ;
V_30 -> va_end = V_2 + V_40 ;
V_30 -> V_59 = 0 ;
F_46 ( V_30 ) ;
V_52 = & V_30 -> V_27 ;
F_60 ( & V_51 ) ;
F_16 ( V_30 -> va_start & ( V_41 - 1 ) ) ;
F_16 ( V_30 -> va_start < V_42 ) ;
F_16 ( V_30 -> va_end > V_43 ) ;
return V_30 ;
V_57:
F_60 ( & V_51 ) ;
if ( ! V_46 ) {
F_61 () ;
V_46 = 1 ;
goto V_50;
}
if ( F_62 () )
F_63 ( V_60
L_1
L_2 , V_40 ) ;
F_64 ( V_30 ) ;
return F_56 ( - V_16 ) ;
}
static void F_65 ( struct V_61 * V_62 )
{
struct V_26 * V_30 = F_66 ( V_62 , struct V_26 , V_61 ) ;
F_64 ( V_30 ) ;
}
static void F_67 ( struct V_26 * V_30 )
{
F_16 ( F_68 ( & V_30 -> V_27 ) ) ;
if ( V_52 ) {
if ( V_30 -> va_end < V_54 ) {
V_52 = NULL ;
} else {
struct V_26 * V_63 ;
V_63 = F_45 ( V_52 , struct V_26 , V_27 ) ;
if ( V_30 -> va_start <= V_63 -> va_start ) {
V_52 = F_50 ( & V_30 -> V_27 ) ;
}
}
}
F_69 ( & V_30 -> V_27 , & V_29 ) ;
F_70 ( & V_30 -> V_27 ) ;
F_71 ( & V_30 -> V_38 ) ;
if ( V_30 -> va_end > V_64 && V_30 -> va_end <= V_65 )
V_66 = F_72 ( V_66 , V_30 -> va_end ) ;
F_73 ( & V_30 -> V_61 , F_65 ) ;
}
static void F_74 ( struct V_26 * V_30 )
{
F_57 ( & V_51 ) ;
F_67 ( V_30 ) ;
F_60 ( & V_51 ) ;
}
static void F_75 ( struct V_26 * V_30 )
{
F_15 ( V_30 -> va_start , V_30 -> va_end ) ;
}
static void F_76 ( unsigned long V_17 , unsigned long V_3 )
{
#ifdef F_77
F_15 ( V_17 , V_3 ) ;
F_78 ( V_17 , V_3 ) ;
#endif
}
static unsigned long F_79 ( void )
{
unsigned int log ;
log = F_80 ( F_81 () ) ;
return log * ( 32UL * 1024 * 1024 / V_7 ) ;
}
void F_82 ( void )
{
F_83 ( & V_67 , F_79 () + 1 ) ;
}
static void F_84 ( unsigned long * V_17 , unsigned long * V_3 ,
int V_68 , int V_69 )
{
static F_85 ( V_70 ) ;
F_86 ( V_71 ) ;
struct V_26 * V_30 ;
struct V_26 * V_72 ;
int V_14 = 0 ;
if ( ! V_68 && ! V_69 ) {
if ( ! F_87 ( & V_70 ) )
return;
} else
F_57 ( & V_70 ) ;
if ( V_68 )
F_88 () ;
F_89 () ;
F_90 (va, &vmap_area_list, list) {
if ( V_30 -> V_59 & V_73 ) {
if ( V_30 -> va_start < * V_17 )
* V_17 = V_30 -> va_start ;
if ( V_30 -> va_end > * V_3 )
* V_3 = V_30 -> va_end ;
V_14 += ( V_30 -> va_end - V_30 -> va_start ) >> V_74 ;
F_91 ( & V_30 -> V_75 , & V_71 ) ;
V_30 -> V_59 |= V_76 ;
V_30 -> V_59 &= ~ V_73 ;
}
}
F_92 () ;
if ( V_14 )
F_93 ( V_14 , & V_67 ) ;
if ( V_14 || V_69 )
F_78 ( * V_17 , * V_3 ) ;
if ( V_14 ) {
F_57 ( & V_51 ) ;
F_94 (va, n_va, &valist, purge_list)
F_67 ( V_30 ) ;
F_60 ( & V_51 ) ;
}
F_60 ( & V_70 ) ;
}
static void F_95 ( void )
{
unsigned long V_17 = V_77 , V_3 = 0 ;
F_84 ( & V_17 , & V_3 , 0 , 0 ) ;
}
static void F_61 ( void )
{
unsigned long V_17 = V_77 , V_3 = 0 ;
F_84 ( & V_17 , & V_3 , 1 , 0 ) ;
}
static void F_96 ( struct V_26 * V_30 )
{
V_30 -> V_59 |= V_73 ;
F_97 ( ( V_30 -> va_end - V_30 -> va_start ) >> V_74 , & V_67 ) ;
if ( F_55 ( F_98 ( & V_67 ) > F_79 () ) )
F_95 () ;
}
static void F_99 ( struct V_26 * V_30 )
{
F_75 ( V_30 ) ;
F_96 ( V_30 ) ;
}
static void F_100 ( struct V_26 * V_30 )
{
F_101 ( V_30 -> va_start , V_30 -> va_end ) ;
F_99 ( V_30 ) ;
}
static struct V_26 * F_102 ( unsigned long V_2 )
{
struct V_26 * V_30 ;
F_57 ( & V_51 ) ;
V_30 = F_44 ( V_2 ) ;
F_60 ( & V_51 ) ;
return V_30 ;
}
static void F_103 ( unsigned long V_2 )
{
struct V_26 * V_30 ;
V_30 = F_102 ( V_2 ) ;
F_16 ( ! V_30 ) ;
F_100 ( V_30 ) ;
}
static unsigned long F_104 ( unsigned long V_2 )
{
V_2 -= V_64 & ~ ( V_78 - 1 ) ;
V_2 /= V_78 ;
return V_2 ;
}
static struct V_79 * F_105 ( T_6 V_45 )
{
struct V_80 * V_81 ;
struct V_79 * V_82 ;
struct V_26 * V_30 ;
unsigned long V_83 ;
int V_44 , V_18 ;
V_44 = F_106 () ;
V_82 = F_54 ( sizeof( struct V_79 ) ,
V_45 & V_49 , V_44 ) ;
if ( F_55 ( ! V_82 ) )
return F_56 ( - V_15 ) ;
V_30 = F_52 ( V_78 , V_78 ,
V_64 , V_65 ,
V_44 , V_45 ) ;
if ( F_107 ( V_30 ) ) {
F_64 ( V_82 ) ;
return F_108 ( V_30 ) ;
}
V_18 = F_109 ( V_45 ) ;
if ( F_55 ( V_18 ) ) {
F_64 ( V_82 ) ;
F_74 ( V_30 ) ;
return F_56 ( V_18 ) ;
}
F_110 ( & V_82 -> V_84 ) ;
V_82 -> V_30 = V_30 ;
V_82 -> free = V_85 ;
V_82 -> V_86 = 0 ;
F_111 ( V_82 -> V_87 , V_85 ) ;
F_111 ( V_82 -> V_88 , V_85 ) ;
F_112 ( & V_82 -> V_89 ) ;
V_83 = F_104 ( V_30 -> va_start ) ;
F_57 ( & V_90 ) ;
V_18 = F_113 ( & V_91 , V_83 , V_82 ) ;
F_60 ( & V_90 ) ;
F_16 ( V_18 ) ;
F_114 () ;
V_81 = & F_115 ( V_80 ) ;
V_82 -> V_81 = V_81 ;
F_57 ( & V_81 -> V_84 ) ;
F_51 ( & V_82 -> V_89 , & V_81 -> free ) ;
F_60 ( & V_81 -> V_84 ) ;
F_116 ( V_80 ) ;
return V_82 ;
}
static void F_117 ( struct V_61 * V_62 )
{
struct V_79 * V_82 = F_66 ( V_62 , struct V_79 , V_61 ) ;
F_64 ( V_82 ) ;
}
static void F_118 ( struct V_79 * V_82 )
{
struct V_79 * V_35 ;
unsigned long V_83 ;
V_83 = F_104 ( V_82 -> V_30 -> va_start ) ;
F_57 ( & V_90 ) ;
V_35 = F_119 ( & V_91 , V_83 ) ;
F_60 ( & V_90 ) ;
F_16 ( V_35 != V_82 ) ;
F_96 ( V_82 -> V_30 ) ;
F_73 ( & V_82 -> V_61 , F_117 ) ;
}
static void F_120 ( int V_92 )
{
F_86 ( V_93 ) ;
struct V_79 * V_82 ;
struct V_79 * V_94 ;
struct V_80 * V_81 = & F_121 ( V_80 , V_92 ) ;
F_89 () ;
F_90 (vb, &vbq->free, free_list) {
if ( ! ( V_82 -> free + V_82 -> V_86 == V_85 && V_82 -> V_86 != V_85 ) )
continue;
F_57 ( & V_82 -> V_84 ) ;
if ( V_82 -> free + V_82 -> V_86 == V_85 && V_82 -> V_86 != V_85 ) {
V_82 -> free = 0 ;
V_82 -> V_86 = V_85 ;
F_122 ( V_82 -> V_87 , V_85 ) ;
F_122 ( V_82 -> V_88 , V_85 ) ;
F_57 ( & V_81 -> V_84 ) ;
F_71 ( & V_82 -> V_89 ) ;
F_60 ( & V_81 -> V_84 ) ;
F_60 ( & V_82 -> V_84 ) ;
F_91 ( & V_82 -> V_93 , & V_93 ) ;
} else
F_60 ( & V_82 -> V_84 ) ;
}
F_92 () ;
F_94 (vb, n_vb, &purge, purge) {
F_123 ( & V_82 -> V_93 ) ;
F_118 ( V_82 ) ;
}
}
static void F_124 ( void )
{
F_120 ( F_125 () ) ;
}
static void F_88 ( void )
{
int V_92 ;
F_126 (cpu)
F_120 ( V_92 ) ;
}
static void * F_127 ( unsigned long V_40 , T_6 V_45 )
{
struct V_80 * V_81 ;
struct V_79 * V_82 ;
unsigned long V_2 = 0 ;
unsigned int V_95 ;
int V_93 = 0 ;
F_16 ( V_40 & ~ V_48 ) ;
F_16 ( V_40 > V_7 * V_96 ) ;
V_95 = F_128 ( V_40 ) ;
V_97:
F_89 () ;
V_81 = & F_115 ( V_80 ) ;
F_90 (vb, &vbq->free, free_list) {
int V_98 ;
F_57 ( & V_82 -> V_84 ) ;
if ( V_82 -> free < 1UL << V_95 )
goto V_9;
V_98 = F_129 ( V_82 -> V_87 ,
V_85 , V_95 ) ;
if ( V_98 < 0 ) {
if ( V_82 -> free + V_82 -> V_86 == V_85 ) {
F_16 ( V_82 -> V_86 != V_85 ) ;
V_93 = 1 ;
}
goto V_9;
}
V_2 = V_82 -> V_30 -> va_start + ( V_98 << V_74 ) ;
F_16 ( F_104 ( V_2 ) !=
F_104 ( V_82 -> V_30 -> va_start ) ) ;
V_82 -> free -= 1UL << V_95 ;
if ( V_82 -> free == 0 ) {
F_57 ( & V_81 -> V_84 ) ;
F_71 ( & V_82 -> V_89 ) ;
F_60 ( & V_81 -> V_84 ) ;
}
F_60 ( & V_82 -> V_84 ) ;
break;
V_9:
F_60 ( & V_82 -> V_84 ) ;
}
if ( V_93 )
F_124 () ;
F_116 ( V_80 ) ;
F_92 () ;
if ( ! V_2 ) {
V_82 = F_105 ( V_45 ) ;
if ( F_107 ( V_82 ) )
return V_82 ;
goto V_97;
}
return ( void * ) V_2 ;
}
static void F_130 ( const void * V_2 , unsigned long V_40 )
{
unsigned long V_99 ;
unsigned long V_83 ;
unsigned int V_95 ;
struct V_79 * V_82 ;
F_16 ( V_40 & ~ V_48 ) ;
F_16 ( V_40 > V_7 * V_96 ) ;
F_101 ( ( unsigned long ) V_2 , ( unsigned long ) V_2 + V_40 ) ;
V_95 = F_128 ( V_40 ) ;
V_99 = ( unsigned long ) V_2 & ( V_78 - 1 ) ;
V_83 = F_104 ( ( unsigned long ) V_2 ) ;
F_89 () ;
V_82 = F_131 ( & V_91 , V_83 ) ;
F_92 () ;
F_16 ( ! V_82 ) ;
F_15 ( ( unsigned long ) V_2 , ( unsigned long ) V_2 + V_40 ) ;
F_57 ( & V_82 -> V_84 ) ;
F_16 ( F_132 ( V_82 -> V_88 , V_99 >> V_74 , V_95 ) ) ;
V_82 -> V_86 += 1UL << V_95 ;
if ( V_82 -> V_86 == V_85 ) {
F_16 ( V_82 -> free ) ;
F_60 ( & V_82 -> V_84 ) ;
F_118 ( V_82 ) ;
} else
F_60 ( & V_82 -> V_84 ) ;
}
void F_133 ( void )
{
unsigned long V_17 = V_77 , V_3 = 0 ;
int V_92 ;
int V_100 = 0 ;
if ( F_55 ( ! V_101 ) )
return;
F_126 (cpu) {
struct V_80 * V_81 = & F_121 ( V_80 , V_92 ) ;
struct V_79 * V_82 ;
F_89 () ;
F_90 (vb, &vbq->free, free_list) {
int V_98 ;
F_57 ( & V_82 -> V_84 ) ;
V_98 = F_134 ( V_82 -> V_88 , V_85 ) ;
while ( V_98 < V_85 ) {
unsigned long V_102 , V_103 ;
int V_104 ;
V_104 = F_135 ( V_82 -> V_88 ,
V_85 , V_98 ) ;
V_102 = V_82 -> V_30 -> va_start + ( V_98 << V_74 ) ;
V_103 = V_82 -> V_30 -> va_start + ( V_104 << V_74 ) ;
V_100 = 1 ;
if ( V_102 < V_17 )
V_17 = V_102 ;
if ( V_103 > V_3 )
V_3 = V_103 ;
V_98 = V_104 ;
V_98 = F_136 ( V_82 -> V_88 ,
V_85 , V_98 ) ;
}
F_60 ( & V_82 -> V_84 ) ;
}
F_92 () ;
}
F_84 ( & V_17 , & V_3 , 1 , V_100 ) ;
}
void F_137 ( const void * V_105 , unsigned int V_106 )
{
unsigned long V_40 = V_106 << V_74 ;
unsigned long V_2 = ( unsigned long ) V_105 ;
F_16 ( ! V_2 ) ;
F_16 ( V_2 < V_64 ) ;
F_16 ( V_2 > V_65 ) ;
F_16 ( V_2 & ( V_7 - 1 ) ) ;
F_138 ( V_105 , V_40 ) ;
F_76 ( V_2 , V_2 + V_40 ) ;
if ( F_139 ( V_106 <= V_96 ) )
F_130 ( V_105 , V_40 ) ;
else
F_103 ( V_2 ) ;
}
void * F_140 ( struct V_12 * * V_13 , unsigned int V_106 , int V_44 , T_5 V_11 )
{
unsigned long V_40 = V_106 << V_74 ;
unsigned long V_2 ;
void * V_105 ;
if ( F_139 ( V_106 <= V_96 ) ) {
V_105 = F_127 ( V_40 , V_107 ) ;
if ( F_107 ( V_105 ) )
return NULL ;
V_2 = ( unsigned long ) V_105 ;
} else {
struct V_26 * V_30 ;
V_30 = F_52 ( V_40 , V_7 ,
V_64 , V_65 , V_44 , V_107 ) ;
if ( F_107 ( V_30 ) )
return NULL ;
V_2 = V_30 -> va_start ;
V_105 = ( void * ) V_2 ;
}
if ( F_29 ( V_2 , V_2 + V_40 , V_11 , V_13 ) < 0 ) {
F_137 ( V_105 , V_106 ) ;
return NULL ;
}
return V_105 ;
}
void T_7 F_141 ( struct V_108 * V_109 , T_8 V_41 )
{
static T_8 T_9 V_110 ;
unsigned long V_2 ;
V_2 = F_58 ( V_64 + T_9 , V_41 ) ;
T_9 = F_142 ( V_2 + V_109 -> V_40 ) - V_64 ;
V_109 -> V_2 = ( void * ) V_2 ;
V_109 -> V_9 = V_111 ;
V_111 = V_109 ;
}
void T_7 F_143 ( void )
{
struct V_26 * V_30 ;
struct V_108 * V_35 ;
int V_98 ;
F_126 (i) {
struct V_80 * V_81 ;
V_81 = & F_121 ( V_80 , V_98 ) ;
F_110 ( & V_81 -> V_84 ) ;
F_112 ( & V_81 -> free ) ;
}
for ( V_35 = V_111 ; V_35 ; V_35 = V_35 -> V_9 ) {
V_30 = F_144 ( sizeof( struct V_26 ) , V_112 ) ;
V_30 -> V_59 = V_35 -> V_59 | V_113 ;
V_30 -> va_start = ( unsigned long ) V_35 -> V_2 ;
V_30 -> va_end = V_30 -> va_start + V_35 -> V_40 ;
F_46 ( V_30 ) ;
}
V_66 = V_65 ;
V_101 = true ;
}
int F_145 ( unsigned long V_2 , unsigned long V_40 ,
T_5 V_11 , struct V_12 * * V_13 )
{
return F_28 ( V_2 , V_2 + V_40 , V_11 , V_13 ) ;
}
void F_146 ( unsigned long V_2 , unsigned long V_40 )
{
F_15 ( V_2 , V_2 + V_40 ) ;
}
void F_147 ( unsigned long V_2 , unsigned long V_40 )
{
unsigned long V_3 = V_2 + V_40 ;
F_101 ( V_2 , V_3 ) ;
F_15 ( V_2 , V_3 ) ;
F_78 ( V_2 , V_3 ) ;
}
int F_148 ( struct V_108 * V_114 , T_5 V_11 , struct V_12 * * * V_13 )
{
unsigned long V_2 = ( unsigned long ) V_114 -> V_2 ;
unsigned long V_3 = V_2 + V_114 -> V_40 - V_7 ;
int V_18 ;
V_18 = F_29 ( V_2 , V_3 , V_11 , * V_13 ) ;
if ( V_18 > 0 ) {
* V_13 += V_18 ;
V_18 = 0 ;
}
return V_18 ;
}
static void F_149 ( struct V_108 * V_109 , struct V_26 * V_30 ,
unsigned long V_59 , void * V_115 )
{
struct V_108 * V_35 , * * V_33 ;
V_109 -> V_59 = V_59 ;
V_109 -> V_2 = ( void * ) V_30 -> va_start ;
V_109 -> V_40 = V_30 -> va_end - V_30 -> va_start ;
V_109 -> V_115 = V_115 ;
V_30 -> V_116 = V_109 ;
V_30 -> V_59 |= V_113 ;
F_150 ( & V_117 ) ;
for ( V_33 = & V_111 ; ( V_35 = * V_33 ) != NULL ; V_33 = & V_35 -> V_9 ) {
if ( V_35 -> V_2 >= V_109 -> V_2 )
break;
}
V_109 -> V_9 = * V_33 ;
* V_33 = V_109 ;
F_151 ( & V_117 ) ;
}
static struct V_108 * F_152 ( unsigned long V_40 ,
unsigned long V_41 , unsigned long V_59 , unsigned long V_17 ,
unsigned long V_3 , int V_44 , T_6 V_45 , void * V_115 )
{
static struct V_26 * V_30 ;
struct V_108 * V_114 ;
F_16 ( F_153 () ) ;
if ( V_59 & V_118 ) {
int V_119 = F_80 ( V_40 ) ;
if ( V_119 > V_120 )
V_119 = V_120 ;
else if ( V_119 < V_74 )
V_119 = V_74 ;
V_41 = 1ul << V_119 ;
}
V_40 = F_154 ( V_40 ) ;
if ( F_55 ( ! V_40 ) )
return NULL ;
V_114 = F_155 ( sizeof( * V_114 ) , V_45 & V_49 , V_44 ) ;
if ( F_55 ( ! V_114 ) )
return NULL ;
V_40 += V_7 ;
V_30 = F_52 ( V_40 , V_41 , V_17 , V_3 , V_44 , V_45 ) ;
if ( F_107 ( V_30 ) ) {
F_64 ( V_114 ) ;
return NULL ;
}
F_149 ( V_114 , V_30 , V_59 , V_115 ) ;
return V_114 ;
}
struct V_108 * F_156 ( unsigned long V_40 , unsigned long V_59 ,
unsigned long V_17 , unsigned long V_3 )
{
return F_152 ( V_40 , 1 , V_59 , V_17 , V_3 , - 1 , V_107 ,
F_157 ( 0 ) ) ;
}
struct V_108 * F_158 ( unsigned long V_40 , unsigned long V_59 ,
unsigned long V_17 , unsigned long V_3 ,
void * V_115 )
{
return F_152 ( V_40 , 1 , V_59 , V_17 , V_3 , - 1 , V_107 ,
V_115 ) ;
}
struct V_108 * F_159 ( unsigned long V_40 , unsigned long V_59 )
{
return F_152 ( V_40 , 1 , V_59 , V_64 , V_65 ,
- 1 , V_107 , F_157 ( 0 ) ) ;
}
struct V_108 * F_160 ( unsigned long V_40 , unsigned long V_59 ,
void * V_115 )
{
return F_152 ( V_40 , 1 , V_59 , V_64 , V_65 ,
- 1 , V_107 , V_115 ) ;
}
static struct V_108 * F_161 ( const void * V_2 )
{
struct V_26 * V_30 ;
V_30 = F_102 ( ( unsigned long ) V_2 ) ;
if ( V_30 && V_30 -> V_59 & V_113 )
return V_30 -> V_116 ;
return NULL ;
}
struct V_108 * F_162 ( const void * V_2 )
{
struct V_26 * V_30 ;
V_30 = F_102 ( ( unsigned long ) V_2 ) ;
if ( V_30 && V_30 -> V_59 & V_113 ) {
struct V_108 * V_109 = V_30 -> V_116 ;
struct V_108 * V_35 , * * V_33 ;
F_150 ( & V_117 ) ;
for ( V_33 = & V_111 ; ( V_35 = * V_33 ) != V_109 ; V_33 = & V_35 -> V_9 )
;
* V_33 = V_35 -> V_9 ;
F_151 ( & V_117 ) ;
F_76 ( V_30 -> va_start , V_30 -> va_end ) ;
F_100 ( V_30 ) ;
V_109 -> V_40 -= V_7 ;
return V_109 ;
}
return NULL ;
}
static void F_163 ( const void * V_2 , int V_121 )
{
struct V_108 * V_114 ;
if ( ! V_2 )
return;
if ( ( V_7 - 1 ) & ( unsigned long ) V_2 ) {
F_164 ( 1 , V_122 L_3 , V_2 ) ;
return;
}
V_114 = F_162 ( V_2 ) ;
if ( F_55 ( ! V_114 ) ) {
F_164 ( 1 , V_122 L_4 ,
V_2 ) ;
return;
}
F_138 ( V_2 , V_114 -> V_40 ) ;
F_165 ( V_2 , V_114 -> V_40 ) ;
if ( V_121 ) {
int V_98 ;
for ( V_98 = 0 ; V_98 < V_114 -> V_123 ; V_98 ++ ) {
struct V_12 * V_12 = V_114 -> V_13 [ V_98 ] ;
F_16 ( ! V_12 ) ;
F_166 ( V_12 ) ;
}
if ( V_114 -> V_59 & V_124 )
F_167 ( V_114 -> V_13 ) ;
else
F_64 ( V_114 -> V_13 ) ;
}
F_64 ( V_114 ) ;
return;
}
void F_167 ( const void * V_2 )
{
F_16 ( F_153 () ) ;
F_168 ( V_2 ) ;
F_163 ( V_2 , 1 ) ;
}
void F_169 ( const void * V_2 )
{
F_16 ( F_153 () ) ;
F_170 () ;
F_163 ( V_2 , 0 ) ;
}
void * F_171 ( struct V_12 * * V_13 , unsigned int V_106 ,
unsigned long V_59 , T_5 V_11 )
{
struct V_108 * V_114 ;
F_170 () ;
if ( V_106 > V_125 )
return NULL ;
V_114 = F_160 ( ( V_106 << V_74 ) , V_59 ,
F_157 ( 0 ) ) ;
if ( ! V_114 )
return NULL ;
if ( F_148 ( V_114 , V_11 , & V_13 ) ) {
F_169 ( V_114 -> V_2 ) ;
return NULL ;
}
return V_114 -> V_2 ;
}
static void * F_172 ( struct V_108 * V_114 , T_6 V_45 ,
T_5 V_11 , int V_44 , void * V_115 )
{
const int V_95 = 0 ;
struct V_12 * * V_13 ;
unsigned int V_123 , V_126 , V_98 ;
T_6 V_127 = ( V_45 & V_49 ) | V_128 ;
V_123 = ( V_114 -> V_40 - V_7 ) >> V_74 ;
V_126 = ( V_123 * sizeof( struct V_12 * ) ) ;
V_114 -> V_123 = V_123 ;
if ( V_126 > V_7 ) {
V_13 = F_173 ( V_126 , 1 , V_127 | V_129 ,
V_130 , V_44 , V_115 ) ;
V_114 -> V_59 |= V_124 ;
} else {
V_13 = F_54 ( V_126 , V_127 , V_44 ) ;
}
V_114 -> V_13 = V_13 ;
V_114 -> V_115 = V_115 ;
if ( ! V_114 -> V_13 ) {
F_162 ( V_114 -> V_2 ) ;
F_64 ( V_114 ) ;
return NULL ;
}
for ( V_98 = 0 ; V_98 < V_114 -> V_123 ; V_98 ++ ) {
struct V_12 * V_12 ;
T_6 V_131 = V_45 | V_132 ;
if ( V_44 < 0 )
V_12 = F_174 ( V_131 ) ;
else
V_12 = F_175 ( V_44 , V_131 , V_95 ) ;
if ( F_55 ( ! V_12 ) ) {
V_114 -> V_123 = V_98 ;
goto V_133;
}
V_114 -> V_13 [ V_98 ] = V_12 ;
}
if ( F_148 ( V_114 , V_11 , & V_13 ) )
goto V_133;
return V_114 -> V_2 ;
V_133:
F_176 ( V_45 , V_95 , L_5
L_6 ,
( V_114 -> V_123 * V_7 ) , V_114 -> V_40 ) ;
F_167 ( V_114 -> V_2 ) ;
return NULL ;
}
void * F_177 ( unsigned long V_40 , unsigned long V_41 ,
unsigned long V_17 , unsigned long V_3 , T_6 V_45 ,
T_5 V_11 , int V_44 , void * V_115 )
{
struct V_108 * V_114 ;
void * V_2 ;
unsigned long V_134 = V_40 ;
V_40 = F_154 ( V_40 ) ;
if ( ! V_40 || ( V_40 >> V_74 ) > V_125 )
return NULL ;
V_114 = F_152 ( V_40 , V_41 , V_135 , V_17 , V_3 , V_44 ,
V_45 , V_115 ) ;
if ( ! V_114 )
return NULL ;
V_2 = F_172 ( V_114 , V_45 , V_11 , V_44 , V_115 ) ;
F_178 ( V_2 , V_134 , 3 , V_45 ) ;
return V_2 ;
}
static void * F_173 ( unsigned long V_40 , unsigned long V_41 ,
T_6 V_45 , T_5 V_11 ,
int V_44 , void * V_115 )
{
return F_177 ( V_40 , V_41 , V_64 , V_65 ,
V_45 , V_11 , V_44 , V_115 ) ;
}
void * F_179 ( unsigned long V_40 , T_6 V_45 , T_5 V_11 )
{
return F_173 ( V_40 , 1 , V_45 , V_11 , - 1 ,
F_157 ( 0 ) ) ;
}
static inline void * F_180 ( unsigned long V_40 ,
int V_44 , T_6 V_59 )
{
return F_173 ( V_40 , 1 , V_59 , V_130 ,
V_44 , F_157 ( 0 ) ) ;
}
void * F_181 ( unsigned long V_40 )
{
return F_180 ( V_40 , - 1 , V_107 | V_129 ) ;
}
void * F_182 ( unsigned long V_40 )
{
return F_180 ( V_40 , - 1 ,
V_107 | V_129 | V_128 ) ;
}
void * F_183 ( unsigned long V_40 )
{
struct V_108 * V_114 ;
void * V_19 ;
V_19 = F_173 ( V_40 , V_136 ,
V_107 | V_129 | V_128 ,
V_130 , - 1 , F_157 ( 0 ) ) ;
if ( V_19 ) {
V_114 = F_161 ( V_19 ) ;
V_114 -> V_59 |= V_137 ;
}
return V_19 ;
}
void * F_184 ( unsigned long V_40 , int V_44 )
{
return F_173 ( V_40 , 1 , V_107 | V_129 , V_130 ,
V_44 , F_157 ( 0 ) ) ;
}
void * F_185 ( unsigned long V_40 , int V_44 )
{
return F_180 ( V_40 , V_44 ,
V_107 | V_129 | V_128 ) ;
}
void * F_186 ( unsigned long V_40 )
{
return F_173 ( V_40 , 1 , V_107 | V_129 , V_138 ,
- 1 , F_157 ( 0 ) ) ;
}
void * F_187 ( unsigned long V_40 )
{
return F_173 ( V_40 , 1 , V_139 , V_130 ,
- 1 , F_157 ( 0 ) ) ;
}
void * F_188 ( unsigned long V_40 )
{
struct V_108 * V_114 ;
void * V_19 ;
V_19 = F_173 ( V_40 , 1 , V_139 | V_128 , V_130 ,
- 1 , F_157 ( 0 ) ) ;
if ( V_19 ) {
V_114 = F_161 ( V_19 ) ;
V_114 -> V_59 |= V_137 ;
}
return V_19 ;
}
static int F_189 ( char * V_140 , char * V_2 , unsigned long V_106 )
{
struct V_12 * V_33 ;
int V_141 = 0 ;
while ( V_106 ) {
unsigned long V_99 , V_142 ;
V_99 = ( unsigned long ) V_2 & ~ V_48 ;
V_142 = V_7 - V_99 ;
if ( V_142 > V_106 )
V_142 = V_106 ;
V_33 = F_34 ( V_2 ) ;
if ( V_33 ) {
void * V_143 = F_190 ( V_33 , V_144 ) ;
memcpy ( V_140 , V_143 + V_99 , V_142 ) ;
F_191 ( V_143 , V_144 ) ;
} else
memset ( V_140 , 0 , V_142 ) ;
V_2 += V_142 ;
V_140 += V_142 ;
V_141 += V_142 ;
V_106 -= V_142 ;
}
return V_141 ;
}
static int F_192 ( char * V_140 , char * V_2 , unsigned long V_106 )
{
struct V_12 * V_33 ;
int V_141 = 0 ;
while ( V_106 ) {
unsigned long V_99 , V_142 ;
V_99 = ( unsigned long ) V_2 & ~ V_48 ;
V_142 = V_7 - V_99 ;
if ( V_142 > V_106 )
V_142 = V_106 ;
V_33 = F_34 ( V_2 ) ;
if ( V_33 ) {
void * V_143 = F_190 ( V_33 , V_144 ) ;
memcpy ( V_143 + V_99 , V_140 , V_142 ) ;
F_191 ( V_143 , V_144 ) ;
}
V_2 += V_142 ;
V_140 += V_142 ;
V_141 += V_142 ;
V_106 -= V_142 ;
}
return V_141 ;
}
long F_193 ( char * V_140 , char * V_2 , unsigned long V_106 )
{
struct V_108 * V_35 ;
char * V_145 , * V_146 = V_140 ;
unsigned long V_147 = V_106 ;
unsigned long V_28 ;
if ( ( unsigned long ) V_2 + V_106 < V_106 )
V_106 = - ( unsigned long ) V_2 ;
F_194 ( & V_117 ) ;
for ( V_35 = V_111 ; V_106 && V_35 ; V_35 = V_35 -> V_9 ) {
V_145 = ( char * ) V_35 -> V_2 ;
if ( V_2 >= V_145 + V_35 -> V_40 - V_7 )
continue;
while ( V_2 < V_145 ) {
if ( V_106 == 0 )
goto V_148;
* V_140 = '\0' ;
V_140 ++ ;
V_2 ++ ;
V_106 -- ;
}
V_28 = V_145 + V_35 -> V_40 - V_7 - V_2 ;
if ( V_28 > V_106 )
V_28 = V_106 ;
if ( ! ( V_35 -> V_59 & V_118 ) )
F_189 ( V_140 , V_2 , V_28 ) ;
else
memset ( V_140 , 0 , V_28 ) ;
V_140 += V_28 ;
V_2 += V_28 ;
V_106 -= V_28 ;
}
V_148:
F_195 ( & V_117 ) ;
if ( V_140 == V_146 )
return 0 ;
if ( V_140 != V_146 + V_147 )
memset ( V_140 , 0 , V_147 - ( V_140 - V_146 ) ) ;
return V_147 ;
}
long F_196 ( char * V_140 , char * V_2 , unsigned long V_106 )
{
struct V_108 * V_35 ;
char * V_145 ;
unsigned long V_28 , V_147 ;
int V_141 = 0 ;
if ( ( unsigned long ) V_2 + V_106 < V_106 )
V_106 = - ( unsigned long ) V_2 ;
V_147 = V_106 ;
F_194 ( & V_117 ) ;
for ( V_35 = V_111 ; V_106 && V_35 ; V_35 = V_35 -> V_9 ) {
V_145 = ( char * ) V_35 -> V_2 ;
if ( V_2 >= V_145 + V_35 -> V_40 - V_7 )
continue;
while ( V_2 < V_145 ) {
if ( V_106 == 0 )
goto V_148;
V_140 ++ ;
V_2 ++ ;
V_106 -- ;
}
V_28 = V_145 + V_35 -> V_40 - V_7 - V_2 ;
if ( V_28 > V_106 )
V_28 = V_106 ;
if ( ! ( V_35 -> V_59 & V_118 ) ) {
F_192 ( V_140 , V_2 , V_28 ) ;
V_141 ++ ;
}
V_140 += V_28 ;
V_2 += V_28 ;
V_106 -= V_28 ;
}
V_148:
F_195 ( & V_117 ) ;
if ( ! V_141 )
return 0 ;
return V_147 ;
}
int F_197 ( struct V_149 * V_150 , void * V_2 ,
unsigned long V_151 )
{
struct V_108 * V_114 ;
unsigned long V_152 = V_150 -> V_153 ;
unsigned long V_154 = V_150 -> V_155 - V_150 -> V_153 ;
if ( ( V_7 - 1 ) & ( unsigned long ) V_2 )
return - V_156 ;
V_114 = F_161 ( V_2 ) ;
if ( ! V_114 )
return - V_156 ;
if ( ! ( V_114 -> V_59 & V_137 ) )
return - V_156 ;
if ( V_154 + ( V_151 << V_74 ) > V_114 -> V_40 - V_7 )
return - V_156 ;
V_2 += V_151 << V_74 ;
do {
struct V_12 * V_12 = F_34 ( V_2 ) ;
int V_19 ;
V_19 = F_198 ( V_150 , V_152 , V_12 ) ;
if ( V_19 )
return V_19 ;
V_152 += V_7 ;
V_2 += V_7 ;
V_154 -= V_7 ;
} while ( V_154 > 0 );
V_150 -> V_157 |= V_158 ;
return 0 ;
}
static int F_199 ( T_2 * V_4 , T_10 V_159 , unsigned long V_2 , void * V_160 )
{
return 0 ;
}
struct V_108 * F_200 ( T_8 V_40 )
{
struct V_108 * V_114 ;
V_114 = F_160 ( V_40 , V_118 ,
F_157 ( 0 ) ) ;
if ( V_114 == NULL )
return NULL ;
if ( F_201 ( & V_6 , ( unsigned long ) V_114 -> V_2 ,
V_114 -> V_40 , F_199 , NULL ) ) {
F_202 ( V_114 ) ;
return NULL ;
}
return V_114 ;
}
void F_202 ( struct V_108 * V_114 )
{
struct V_108 * V_19 ;
V_19 = F_162 ( V_114 -> V_2 ) ;
F_16 ( V_19 != V_114 ) ;
F_64 ( V_114 ) ;
}
static struct V_26 * F_203 ( struct V_27 * V_28 )
{
return V_28 ? F_45 ( V_28 , struct V_26 , V_27 ) : NULL ;
}
static bool F_204 ( unsigned long V_3 ,
struct V_26 * * V_161 ,
struct V_26 * * V_162 )
{
struct V_27 * V_28 = V_29 . V_27 ;
struct V_26 * V_30 = NULL ;
while ( V_28 ) {
V_30 = F_45 ( V_28 , struct V_26 , V_27 ) ;
if ( V_3 < V_30 -> va_end )
V_28 = V_28 -> V_31 ;
else if ( V_3 > V_30 -> va_end )
V_28 = V_28 -> V_32 ;
else
break;
}
if ( ! V_30 )
return false ;
if ( V_30 -> va_end > V_3 ) {
* V_161 = V_30 ;
* V_162 = F_203 ( F_50 ( & ( * V_161 ) -> V_27 ) ) ;
} else {
* V_162 = V_30 ;
* V_161 = F_203 ( F_59 ( & ( * V_162 ) -> V_27 ) ) ;
}
return true ;
}
static unsigned long F_205 ( struct V_26 * * V_161 ,
struct V_26 * * V_162 ,
unsigned long V_41 )
{
const unsigned long V_163 = V_65 & ~ ( V_41 - 1 ) ;
unsigned long V_2 ;
if ( * V_161 )
V_2 = F_206 ( ( * V_161 ) -> va_start & ~ ( V_41 - 1 ) , V_163 ) ;
else
V_2 = V_163 ;
while ( * V_162 && ( * V_162 ) -> va_end > V_2 ) {
* V_161 = * V_162 ;
* V_162 = F_203 ( F_50 ( & ( * V_161 ) -> V_27 ) ) ;
}
return V_2 ;
}
struct V_108 * * F_207 ( const unsigned long * V_164 ,
const T_8 * V_165 , int V_166 ,
T_8 V_41 )
{
const unsigned long V_167 = F_58 ( V_64 , V_41 ) ;
const unsigned long V_163 = V_65 & ~ ( V_41 - 1 ) ;
struct V_26 * * V_168 , * V_37 , * V_9 ;
struct V_108 * * V_169 ;
int V_114 , V_170 , V_171 , V_172 ;
unsigned long V_173 , V_17 , V_3 , V_174 ;
bool V_46 = false ;
F_16 ( V_41 & ~ V_48 || ! F_53 ( V_41 ) ) ;
for ( V_171 = 0 , V_114 = 0 ; V_114 < V_166 ; V_114 ++ ) {
V_17 = V_164 [ V_114 ] ;
V_3 = V_17 + V_165 [ V_114 ] ;
F_16 ( ! F_208 ( V_164 [ V_114 ] , V_41 ) ) ;
F_16 ( ! F_208 ( V_165 [ V_114 ] , V_41 ) ) ;
if ( V_17 > V_164 [ V_171 ] )
V_171 = V_114 ;
for ( V_170 = 0 ; V_170 < V_166 ; V_170 ++ ) {
unsigned long V_175 = V_164 [ V_170 ] ;
unsigned long V_176 = V_175 + V_165 [ V_170 ] ;
if ( V_170 == V_114 )
continue;
F_16 ( V_175 >= V_17 && V_175 < V_3 ) ;
F_16 ( V_176 <= V_3 && V_176 > V_17 ) ;
}
}
V_174 = V_164 [ V_171 ] + V_165 [ V_171 ] ;
if ( V_163 - V_167 < V_174 ) {
F_4 ( true ) ;
return NULL ;
}
V_169 = F_144 ( sizeof( V_169 [ 0 ] ) * V_166 , V_107 ) ;
V_168 = F_144 ( sizeof( V_168 [ 0 ] ) * V_166 , V_107 ) ;
if ( ! V_168 || ! V_169 )
goto V_177;
for ( V_114 = 0 ; V_114 < V_166 ; V_114 ++ ) {
V_168 [ V_114 ] = F_144 ( sizeof( struct V_26 ) , V_107 ) ;
V_169 [ V_114 ] = F_144 ( sizeof( struct V_108 ) , V_107 ) ;
if ( ! V_168 [ V_114 ] || ! V_169 [ V_114 ] )
goto V_177;
}
V_50:
F_57 ( & V_51 ) ;
V_114 = V_172 = V_171 ;
V_17 = V_164 [ V_114 ] ;
V_3 = V_17 + V_165 [ V_114 ] ;
if ( ! F_204 ( V_66 , & V_9 , & V_37 ) ) {
V_173 = V_163 - V_174 ;
goto V_58;
}
V_173 = F_205 ( & V_9 , & V_37 , V_41 ) - V_3 ;
while ( true ) {
F_16 ( V_9 && V_9 -> va_end <= V_173 + V_3 ) ;
F_16 ( V_37 && V_37 -> va_end > V_173 + V_3 ) ;
if ( V_173 + V_174 < V_167 + V_174 ) {
F_60 ( & V_51 ) ;
if ( ! V_46 ) {
F_61 () ;
V_46 = true ;
goto V_50;
}
goto V_177;
}
if ( V_9 && V_9 -> va_start < V_173 + V_3 ) {
V_173 = F_205 ( & V_9 , & V_37 , V_41 ) - V_3 ;
V_172 = V_114 ;
continue;
}
if ( V_37 && V_37 -> va_end > V_173 + V_17 ) {
V_9 = V_37 ;
V_37 = F_203 ( F_50 ( & V_9 -> V_27 ) ) ;
V_173 = F_205 ( & V_9 , & V_37 , V_41 ) - V_3 ;
V_172 = V_114 ;
continue;
}
V_114 = ( V_114 + V_166 - 1 ) % V_166 ;
if ( V_114 == V_172 )
break;
V_17 = V_164 [ V_114 ] ;
V_3 = V_17 + V_165 [ V_114 ] ;
F_204 ( V_173 + V_3 , & V_9 , & V_37 ) ;
}
V_58:
for ( V_114 = 0 ; V_114 < V_166 ; V_114 ++ ) {
struct V_26 * V_30 = V_168 [ V_114 ] ;
V_30 -> va_start = V_173 + V_164 [ V_114 ] ;
V_30 -> va_end = V_30 -> va_start + V_165 [ V_114 ] ;
F_46 ( V_30 ) ;
}
V_66 = V_173 + V_164 [ V_171 ] ;
F_60 ( & V_51 ) ;
for ( V_114 = 0 ; V_114 < V_166 ; V_114 ++ )
F_149 ( V_169 [ V_114 ] , V_168 [ V_114 ] , V_135 ,
F_207 ) ;
F_64 ( V_168 ) ;
return V_169 ;
V_177:
for ( V_114 = 0 ; V_114 < V_166 ; V_114 ++ ) {
if ( V_168 )
F_64 ( V_168 [ V_114 ] ) ;
if ( V_169 )
F_64 ( V_169 [ V_114 ] ) ;
}
F_64 ( V_168 ) ;
F_64 ( V_169 ) ;
return NULL ;
}
void F_209 ( struct V_108 * * V_169 , int V_166 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_166 ; V_98 ++ )
F_202 ( V_169 [ V_98 ] ) ;
F_64 ( V_169 ) ;
}
static void * F_210 ( struct V_178 * V_179 , T_11 * V_180 )
__acquires( &vmlist_lock
static void * F_211 ( struct V_178 * V_179 , void * V_33 , T_11 * V_180 )
{
struct V_108 * V_181 = V_33 ;
++ * V_180 ;
return V_181 -> V_9 ;
}
static void F_212 ( struct V_178 * V_179 , void * V_33 )
__releases( &vmlist_lock
static void F_213 ( struct V_178 * V_179 , struct V_108 * V_181 )
{
if ( V_182 ) {
unsigned int V_14 , * V_183 = V_179 -> V_116 ;
if ( ! V_183 )
return;
memset ( V_183 , 0 , V_184 * sizeof( unsigned int ) ) ;
for ( V_14 = 0 ; V_14 < V_181 -> V_123 ; V_14 ++ )
V_183 [ F_214 ( V_181 -> V_13 [ V_14 ] ) ] ++ ;
F_215 (nr, N_HIGH_MEMORY)
if ( V_183 [ V_14 ] )
F_216 ( V_179 , L_7 , V_14 , V_183 [ V_14 ] ) ;
}
}
static int F_217 ( struct V_178 * V_179 , void * V_33 )
{
struct V_108 * V_181 = V_33 ;
F_216 ( V_179 , L_8 ,
V_181 -> V_2 , V_181 -> V_2 + V_181 -> V_40 , V_181 -> V_40 ) ;
if ( V_181 -> V_115 )
F_216 ( V_179 , L_9 , V_181 -> V_115 ) ;
if ( V_181 -> V_123 )
F_216 ( V_179 , L_10 , V_181 -> V_123 ) ;
if ( V_181 -> V_185 )
F_216 ( V_179 , L_11 , ( unsigned long long ) V_181 -> V_185 ) ;
if ( V_181 -> V_59 & V_118 )
F_216 ( V_179 , L_12 ) ;
if ( V_181 -> V_59 & V_135 )
F_216 ( V_179 , L_13 ) ;
if ( V_181 -> V_59 & V_186 )
F_216 ( V_179 , L_14 ) ;
if ( V_181 -> V_59 & V_137 )
F_216 ( V_179 , L_15 ) ;
if ( V_181 -> V_59 & V_124 )
F_216 ( V_179 , L_16 ) ;
F_213 ( V_179 , V_181 ) ;
F_218 ( V_179 , '\n' ) ;
return 0 ;
}
static int F_219 ( struct V_187 * V_187 , struct V_188 * V_188 )
{
unsigned int * V_189 = NULL ;
int V_19 ;
if ( V_182 ) {
V_189 = F_220 ( V_184 * sizeof( unsigned int ) , V_107 ) ;
if ( V_189 == NULL )
return - V_15 ;
}
V_19 = F_221 ( V_188 , & V_190 ) ;
if ( ! V_19 ) {
struct V_178 * V_179 = V_188 -> V_191 ;
V_179 -> V_116 = V_189 ;
} else
F_64 ( V_189 ) ;
return V_19 ;
}
static int T_7 F_222 ( void )
{
F_223 ( L_17 , V_192 , NULL , & V_193 ) ;
return 0 ;
}
