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
F_70 ( V_67
L_1
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
struct V_34 * V_68 ;
V_68 = F_50 ( V_59 , struct V_34 , V_35 ) ;
if ( V_38 -> va_start <= V_68 -> va_start ) {
V_59 = F_55 ( & V_38 -> V_35 ) ;
}
}
}
F_74 ( & V_38 -> V_35 , & V_37 ) ;
F_75 ( & V_38 -> V_35 ) ;
F_76 ( & V_38 -> V_8 ) ;
if ( V_38 -> va_end > V_69 && V_38 -> va_end <= V_70 )
V_71 = F_77 ( V_71 , V_38 -> va_end ) ;
F_78 ( V_38 , V_72 ) ;
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
F_88 ( & V_73 , F_84 () + 1 ) ;
}
static void F_89 ( unsigned long * V_25 , unsigned long * V_11 ,
int V_74 , int V_75 )
{
static F_90 ( V_76 ) ;
F_91 ( V_77 ) ;
struct V_34 * V_38 ;
struct V_34 * V_78 ;
int V_22 = 0 ;
if ( ! V_74 && ! V_75 ) {
if ( ! F_92 ( & V_76 ) )
return;
} else
F_63 ( & V_76 ) ;
if ( V_74 )
F_93 () ;
F_94 () ;
F_95 (va, &vmap_area_list, list) {
if ( V_38 -> V_66 & V_79 ) {
if ( V_38 -> va_start < * V_25 )
* V_25 = V_38 -> va_start ;
if ( V_38 -> va_end > * V_11 )
* V_11 = V_38 -> va_end ;
V_22 += ( V_38 -> va_end - V_38 -> va_start ) >> V_80 ;
F_96 ( & V_38 -> V_81 , & V_77 ) ;
V_38 -> V_66 |= V_82 ;
V_38 -> V_66 &= ~ V_79 ;
}
}
F_97 () ;
if ( V_22 )
F_98 ( V_22 , & V_73 ) ;
if ( V_22 || V_75 )
F_83 ( * V_25 , * V_11 ) ;
if ( V_22 ) {
F_63 ( & V_58 ) ;
F_99 (va, n_va, &valist, purge_list)
F_72 ( V_38 ) ;
F_67 ( & V_58 ) ;
}
F_67 ( & V_76 ) ;
}
static void F_100 ( void )
{
unsigned long V_25 = V_83 , V_11 = 0 ;
F_89 ( & V_25 , & V_11 , 0 , 0 ) ;
}
static void F_68 ( void )
{
unsigned long V_25 = V_83 , V_11 = 0 ;
F_89 ( & V_25 , & V_11 , 1 , 0 ) ;
}
static void F_101 ( struct V_34 * V_38 )
{
V_38 -> V_66 |= V_79 ;
F_102 ( ( V_38 -> va_end - V_38 -> va_start ) >> V_80 , & V_73 ) ;
if ( F_60 ( F_103 ( & V_73 ) > F_84 () ) )
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
V_10 -= V_69 & ~ ( V_84 - 1 ) ;
V_10 /= V_84 ;
return V_10 ;
}
static struct V_85 * F_110 ( T_6 V_51 )
{
struct V_86 * V_87 ;
struct V_85 * V_88 ;
struct V_34 * V_38 ;
unsigned long V_89 ;
int V_50 , V_26 ;
V_50 = F_111 () ;
V_88 = F_59 ( sizeof( struct V_85 ) ,
V_51 & V_55 , V_50 ) ;
if ( F_60 ( ! V_88 ) )
return F_61 ( - V_23 ) ;
V_38 = F_57 ( V_84 , V_84 ,
V_69 , V_70 ,
V_50 , V_51 ) ;
if ( F_112 ( V_38 ) ) {
F_71 ( V_88 ) ;
return F_113 ( V_38 ) ;
}
V_26 = F_114 ( V_51 ) ;
if ( F_60 ( V_26 ) ) {
F_71 ( V_88 ) ;
F_79 ( V_38 ) ;
return F_61 ( V_26 ) ;
}
F_115 ( & V_88 -> V_90 ) ;
V_88 -> V_38 = V_38 ;
V_88 -> free = V_91 ;
V_88 -> V_92 = 0 ;
F_116 ( V_88 -> V_93 , V_91 ) ;
F_117 ( & V_88 -> V_94 ) ;
V_89 = F_109 ( V_38 -> va_start ) ;
F_63 ( & V_95 ) ;
V_26 = F_118 ( & V_96 , V_89 , V_88 ) ;
F_67 ( & V_95 ) ;
F_21 ( V_26 ) ;
F_119 () ;
V_87 = & F_120 ( V_86 ) ;
F_63 ( & V_87 -> V_90 ) ;
F_56 ( & V_88 -> V_94 , & V_87 -> free ) ;
F_67 ( & V_87 -> V_90 ) ;
F_121 ( V_86 ) ;
return V_88 ;
}
static void F_122 ( struct V_85 * V_88 )
{
struct V_85 * V_42 ;
unsigned long V_89 ;
V_89 = F_109 ( V_88 -> V_38 -> va_start ) ;
F_63 ( & V_95 ) ;
V_42 = F_123 ( & V_96 , V_89 ) ;
F_67 ( & V_95 ) ;
F_21 ( V_42 != V_88 ) ;
F_101 ( V_88 -> V_38 ) ;
F_78 ( V_88 , V_72 ) ;
}
static void F_124 ( int V_97 )
{
F_91 ( V_98 ) ;
struct V_85 * V_88 ;
struct V_85 * V_99 ;
struct V_86 * V_87 = & F_125 ( V_86 , V_97 ) ;
F_94 () ;
F_95 (vb, &vbq->free, free_list) {
if ( ! ( V_88 -> free + V_88 -> V_92 == V_91 && V_88 -> V_92 != V_91 ) )
continue;
F_63 ( & V_88 -> V_90 ) ;
if ( V_88 -> free + V_88 -> V_92 == V_91 && V_88 -> V_92 != V_91 ) {
V_88 -> free = 0 ;
V_88 -> V_92 = V_91 ;
F_126 ( V_88 -> V_93 , V_91 ) ;
F_63 ( & V_87 -> V_90 ) ;
F_76 ( & V_88 -> V_94 ) ;
F_67 ( & V_87 -> V_90 ) ;
F_67 ( & V_88 -> V_90 ) ;
F_96 ( & V_88 -> V_98 , & V_98 ) ;
} else
F_67 ( & V_88 -> V_90 ) ;
}
F_97 () ;
F_99 (vb, n_vb, &purge, purge) {
F_127 ( & V_88 -> V_98 ) ;
F_122 ( V_88 ) ;
}
}
static void F_93 ( void )
{
int V_97 ;
F_128 (cpu)
F_124 ( V_97 ) ;
}
static void * F_129 ( unsigned long V_46 , T_6 V_51 )
{
struct V_86 * V_87 ;
struct V_85 * V_88 ;
unsigned long V_10 = 0 ;
unsigned int V_100 ;
F_21 ( V_46 & ~ V_54 ) ;
F_21 ( V_46 > V_15 * V_101 ) ;
if ( F_9 ( V_46 == 0 ) ) {
return NULL ;
}
V_100 = F_130 ( V_46 ) ;
V_102:
F_94 () ;
V_87 = & F_120 ( V_86 ) ;
F_95 (vb, &vbq->free, free_list) {
int V_103 ;
F_63 ( & V_88 -> V_90 ) ;
if ( V_88 -> free < 1UL << V_100 )
goto V_17;
V_103 = V_91 - V_88 -> free ;
V_10 = V_88 -> V_38 -> va_start + ( V_103 << V_80 ) ;
F_21 ( F_109 ( V_10 ) !=
F_109 ( V_88 -> V_38 -> va_start ) ) ;
V_88 -> free -= 1UL << V_100 ;
if ( V_88 -> free == 0 ) {
F_63 ( & V_87 -> V_90 ) ;
F_76 ( & V_88 -> V_94 ) ;
F_67 ( & V_87 -> V_90 ) ;
}
F_67 ( & V_88 -> V_90 ) ;
break;
V_17:
F_67 ( & V_88 -> V_90 ) ;
}
F_121 ( V_86 ) ;
F_97 () ;
if ( ! V_10 ) {
V_88 = F_110 ( V_51 ) ;
if ( F_112 ( V_88 ) )
return V_88 ;
goto V_102;
}
return ( void * ) V_10 ;
}
static void F_131 ( const void * V_10 , unsigned long V_46 )
{
unsigned long V_104 ;
unsigned long V_89 ;
unsigned int V_100 ;
struct V_85 * V_88 ;
F_21 ( V_46 & ~ V_54 ) ;
F_21 ( V_46 > V_15 * V_101 ) ;
F_106 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
V_100 = F_130 ( V_46 ) ;
V_104 = ( unsigned long ) V_10 & ( V_84 - 1 ) ;
V_89 = F_109 ( ( unsigned long ) V_10 ) ;
F_94 () ;
V_88 = F_132 ( & V_96 , V_89 ) ;
F_97 () ;
F_21 ( ! V_88 ) ;
F_20 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
F_63 ( & V_88 -> V_90 ) ;
F_21 ( F_133 ( V_88 -> V_93 , V_104 >> V_80 , V_100 ) ) ;
V_88 -> V_92 += 1UL << V_100 ;
if ( V_88 -> V_92 == V_91 ) {
F_21 ( V_88 -> free ) ;
F_67 ( & V_88 -> V_90 ) ;
F_122 ( V_88 ) ;
} else
F_67 ( & V_88 -> V_90 ) ;
}
void F_134 ( void )
{
unsigned long V_25 = V_83 , V_11 = 0 ;
int V_97 ;
int V_105 = 0 ;
if ( F_60 ( ! V_106 ) )
return;
F_128 (cpu) {
struct V_86 * V_87 = & F_125 ( V_86 , V_97 ) ;
struct V_85 * V_88 ;
F_94 () ;
F_95 (vb, &vbq->free, free_list) {
int V_103 , V_107 ;
F_63 ( & V_88 -> V_90 ) ;
V_103 = F_135 ( V_88 -> V_93 , V_91 ) ;
if ( V_103 < V_91 ) {
unsigned long V_108 , V_109 ;
V_107 = F_136 ( V_88 -> V_93 ,
V_91 ) ;
V_107 = V_107 + 1 ;
V_108 = V_88 -> V_38 -> va_start + ( V_103 << V_80 ) ;
V_109 = V_88 -> V_38 -> va_start + ( V_107 << V_80 ) ;
V_105 = 1 ;
if ( V_108 < V_25 )
V_25 = V_108 ;
if ( V_109 > V_11 )
V_11 = V_109 ;
}
F_67 ( & V_88 -> V_90 ) ;
}
F_97 () ;
}
F_89 ( & V_25 , & V_11 , 1 , V_105 ) ;
}
void F_137 ( const void * V_110 , unsigned int V_111 )
{
unsigned long V_46 = V_111 << V_80 ;
unsigned long V_10 = ( unsigned long ) V_110 ;
F_21 ( ! V_10 ) ;
F_21 ( V_10 < V_69 ) ;
F_21 ( V_10 > V_70 ) ;
F_21 ( V_10 & ( V_15 - 1 ) ) ;
F_138 ( V_110 , V_46 ) ;
F_81 ( V_10 , V_10 + V_46 ) ;
if ( F_139 ( V_111 <= V_101 ) )
F_131 ( V_110 , V_46 ) ;
else
F_108 ( V_10 ) ;
}
void * F_140 ( struct V_20 * * V_21 , unsigned int V_111 , int V_50 , T_5 V_19 )
{
unsigned long V_46 = V_111 << V_80 ;
unsigned long V_10 ;
void * V_110 ;
if ( F_139 ( V_111 <= V_101 ) ) {
V_110 = F_129 ( V_46 , V_112 ) ;
if ( F_112 ( V_110 ) )
return NULL ;
V_10 = ( unsigned long ) V_110 ;
} else {
struct V_34 * V_38 ;
V_38 = F_57 ( V_46 , V_15 ,
V_69 , V_70 , V_50 , V_112 ) ;
if ( F_112 ( V_38 ) )
return NULL ;
V_10 = V_38 -> va_start ;
V_110 = ( void * ) V_10 ;
}
if ( F_34 ( V_10 , V_10 + V_46 , V_19 , V_21 ) < 0 ) {
F_137 ( V_110 , V_111 ) ;
return NULL ;
}
return V_110 ;
}
void T_7 F_141 ( struct V_113 * V_114 )
{
struct V_113 * V_42 , * * V_4 ;
F_21 ( V_106 ) ;
for ( V_4 = & V_115 ; ( V_42 = * V_4 ) != NULL ; V_4 = & V_42 -> V_17 ) {
if ( V_42 -> V_10 >= V_114 -> V_10 ) {
F_21 ( V_42 -> V_10 < V_114 -> V_10 + V_114 -> V_46 ) ;
break;
} else
F_21 ( V_42 -> V_10 + V_42 -> V_46 > V_114 -> V_10 ) ;
}
V_114 -> V_17 = * V_4 ;
* V_4 = V_114 ;
}
void T_7 F_142 ( struct V_113 * V_114 , T_8 V_47 )
{
static T_8 T_9 V_116 ;
unsigned long V_10 ;
V_10 = F_64 ( V_69 + T_9 , V_47 ) ;
T_9 = F_143 ( V_10 + V_114 -> V_46 ) - V_69 ;
V_114 -> V_10 = ( void * ) V_10 ;
F_141 ( V_114 ) ;
}
void T_7 F_144 ( void )
{
struct V_34 * V_38 ;
struct V_113 * V_42 ;
int V_103 ;
F_128 (i) {
struct V_86 * V_87 ;
struct V_3 * V_4 ;
V_87 = & F_125 ( V_86 , V_103 ) ;
F_115 ( & V_87 -> V_90 ) ;
F_117 ( & V_87 -> free ) ;
V_4 = & F_125 ( V_3 , V_103 ) ;
F_145 ( & V_4 -> V_8 ) ;
F_146 ( & V_4 -> V_5 , F_1 ) ;
}
for ( V_42 = V_115 ; V_42 ; V_42 = V_42 -> V_17 ) {
V_38 = F_147 ( sizeof( struct V_34 ) , V_117 ) ;
V_38 -> V_66 = V_118 ;
V_38 -> va_start = ( unsigned long ) V_42 -> V_10 ;
V_38 -> va_end = V_38 -> va_start + V_42 -> V_46 ;
V_38 -> V_114 = V_42 ;
F_51 ( V_38 ) ;
}
V_71 = V_70 ;
V_106 = true ;
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
int F_151 ( struct V_113 * V_119 , T_5 V_19 , struct V_20 * * V_21 )
{
unsigned long V_10 = ( unsigned long ) V_119 -> V_10 ;
unsigned long V_11 = V_10 + F_152 ( V_119 ) ;
int V_26 ;
V_26 = F_34 ( V_10 , V_11 , V_19 , V_21 ) ;
return V_26 > 0 ? 0 : V_26 ;
}
static void F_153 ( struct V_113 * V_114 , struct V_34 * V_38 ,
unsigned long V_66 , const void * V_120 )
{
F_63 ( & V_58 ) ;
V_114 -> V_66 = V_66 ;
V_114 -> V_10 = ( void * ) V_38 -> va_start ;
V_114 -> V_46 = V_38 -> va_end - V_38 -> va_start ;
V_114 -> V_120 = V_120 ;
V_38 -> V_114 = V_114 ;
V_38 -> V_66 |= V_118 ;
F_67 ( & V_58 ) ;
}
static void F_154 ( struct V_113 * V_114 )
{
F_155 () ;
V_114 -> V_66 &= ~ V_121 ;
}
static struct V_113 * F_156 ( unsigned long V_46 ,
unsigned long V_47 , unsigned long V_66 , unsigned long V_25 ,
unsigned long V_11 , int V_50 , T_6 V_51 , const void * V_120 )
{
struct V_34 * V_38 ;
struct V_113 * V_119 ;
F_21 ( F_157 () ) ;
if ( V_66 & V_122 )
V_47 = 1ul << F_158 ( F_85 ( V_46 ) , V_80 , V_123 ) ;
V_46 = F_159 ( V_46 ) ;
if ( F_60 ( ! V_46 ) )
return NULL ;
V_119 = F_160 ( sizeof( * V_119 ) , V_51 & V_55 , V_50 ) ;
if ( F_60 ( ! V_119 ) )
return NULL ;
V_46 += V_15 ;
V_38 = F_57 ( V_46 , V_47 , V_25 , V_11 , V_50 , V_51 ) ;
if ( F_112 ( V_38 ) ) {
F_71 ( V_119 ) ;
return NULL ;
}
F_153 ( V_119 , V_38 , V_66 , V_120 ) ;
return V_119 ;
}
struct V_113 * F_161 ( unsigned long V_46 , unsigned long V_66 ,
unsigned long V_25 , unsigned long V_11 )
{
return F_156 ( V_46 , 1 , V_66 , V_25 , V_11 , V_124 ,
V_112 , F_162 ( 0 ) ) ;
}
struct V_113 * F_163 ( unsigned long V_46 , unsigned long V_66 ,
unsigned long V_25 , unsigned long V_11 ,
const void * V_120 )
{
return F_156 ( V_46 , 1 , V_66 , V_25 , V_11 , V_124 ,
V_112 , V_120 ) ;
}
struct V_113 * F_164 ( unsigned long V_46 , unsigned long V_66 )
{
return F_156 ( V_46 , 1 , V_66 , V_69 , V_70 ,
V_124 , V_112 ,
F_162 ( 0 ) ) ;
}
struct V_113 * F_165 ( unsigned long V_46 , unsigned long V_66 ,
const void * V_120 )
{
return F_156 ( V_46 , 1 , V_66 , V_69 , V_70 ,
V_124 , V_112 , V_120 ) ;
}
struct V_113 * F_166 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_107 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_66 & V_118 )
return V_38 -> V_114 ;
return NULL ;
}
struct V_113 * F_167 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_107 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_66 & V_118 ) {
struct V_113 * V_114 = V_38 -> V_114 ;
F_63 ( & V_58 ) ;
V_38 -> V_114 = NULL ;
V_38 -> V_66 &= ~ V_118 ;
F_67 ( & V_58 ) ;
F_81 ( V_38 -> va_start , V_38 -> va_end ) ;
F_105 ( V_38 ) ;
V_114 -> V_46 -= V_15 ;
return V_114 ;
}
return NULL ;
}
static void F_5 ( const void * V_10 , int V_125 )
{
struct V_113 * V_119 ;
if ( ! V_10 )
return;
if ( F_168 ( ! F_169 ( V_10 ) , L_3 ,
V_10 ) )
return;
V_119 = F_167 ( V_10 ) ;
if ( F_60 ( ! V_119 ) ) {
F_168 ( 1 , V_126 L_4 ,
V_10 ) ;
return;
}
F_138 ( V_10 , V_119 -> V_46 ) ;
F_170 ( V_10 , V_119 -> V_46 ) ;
if ( V_125 ) {
int V_103 ;
for ( V_103 = 0 ; V_103 < V_119 -> V_127 ; V_103 ++ ) {
struct V_20 * V_20 = V_119 -> V_21 [ V_103 ] ;
F_21 ( ! V_20 ) ;
F_171 ( V_20 ) ;
}
if ( V_119 -> V_66 & V_128 )
F_172 ( V_119 -> V_21 ) ;
else
F_71 ( V_119 -> V_21 ) ;
}
F_71 ( V_119 ) ;
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
void * F_180 ( struct V_20 * * V_21 , unsigned int V_111 ,
unsigned long V_66 , T_5 V_19 )
{
struct V_113 * V_119 ;
F_179 () ;
if ( V_111 > V_129 )
return NULL ;
V_119 = F_165 ( ( V_111 << V_80 ) , V_66 ,
F_162 ( 0 ) ) ;
if ( ! V_119 )
return NULL ;
if ( F_151 ( V_119 , V_19 , V_21 ) ) {
F_178 ( V_119 -> V_10 ) ;
return NULL ;
}
return V_119 -> V_10 ;
}
static void * F_181 ( struct V_113 * V_119 , T_6 V_51 ,
T_5 V_19 , int V_50 )
{
const int V_100 = 0 ;
struct V_20 * * V_21 ;
unsigned int V_127 , V_130 , V_103 ;
const T_6 V_131 = ( V_51 & V_55 ) | V_132 ;
const T_6 V_133 = V_51 | V_134 ;
V_127 = F_152 ( V_119 ) >> V_80 ;
V_130 = ( V_127 * sizeof( struct V_20 * ) ) ;
V_119 -> V_127 = V_127 ;
if ( V_130 > V_15 ) {
V_21 = F_182 ( V_130 , 1 , V_131 | V_135 ,
V_136 , V_50 , V_119 -> V_120 ) ;
V_119 -> V_66 |= V_128 ;
} else {
V_21 = F_59 ( V_130 , V_131 , V_50 ) ;
}
V_119 -> V_21 = V_21 ;
if ( ! V_119 -> V_21 ) {
F_167 ( V_119 -> V_10 ) ;
F_71 ( V_119 ) ;
return NULL ;
}
for ( V_103 = 0 ; V_103 < V_119 -> V_127 ; V_103 ++ ) {
struct V_20 * V_20 ;
if ( V_50 == V_124 )
V_20 = F_183 ( V_133 ) ;
else
V_20 = F_184 ( V_50 , V_133 , V_100 ) ;
if ( F_60 ( ! V_20 ) ) {
V_119 -> V_127 = V_103 ;
goto V_137;
}
V_119 -> V_21 [ V_103 ] = V_20 ;
if ( V_51 & V_138 )
F_185 () ;
}
if ( F_151 ( V_119 , V_19 , V_21 ) )
goto V_137;
return V_119 -> V_10 ;
V_137:
F_186 ( V_51 , V_100 ,
L_5 ,
( V_119 -> V_127 * V_15 ) , V_119 -> V_46 ) ;
F_172 ( V_119 -> V_10 ) ;
return NULL ;
}
void * F_187 ( unsigned long V_46 , unsigned long V_47 ,
unsigned long V_25 , unsigned long V_11 , T_6 V_51 ,
T_5 V_19 , int V_50 , const void * V_120 )
{
struct V_113 * V_119 ;
void * V_10 ;
unsigned long V_139 = V_46 ;
V_46 = F_159 ( V_46 ) ;
if ( ! V_46 || ( V_46 >> V_80 ) > V_129 )
goto V_137;
V_119 = F_156 ( V_46 , V_47 , V_140 | V_121 ,
V_25 , V_11 , V_50 , V_51 , V_120 ) ;
if ( ! V_119 )
goto V_137;
V_10 = F_181 ( V_119 , V_51 , V_19 , V_50 ) ;
if ( ! V_10 )
return NULL ;
F_154 ( V_119 ) ;
F_188 ( V_10 , V_139 , 2 , V_51 ) ;
return V_10 ;
V_137:
F_186 ( V_51 , 0 ,
L_6 ,
V_139 ) ;
return NULL ;
}
static void * F_182 ( unsigned long V_46 , unsigned long V_47 ,
T_6 V_51 , T_5 V_19 ,
int V_50 , const void * V_120 )
{
return F_187 ( V_46 , V_47 , V_69 , V_70 ,
V_51 , V_19 , V_50 , V_120 ) ;
}
void * F_189 ( unsigned long V_46 , T_6 V_51 , T_5 V_19 )
{
return F_182 ( V_46 , 1 , V_51 , V_19 , V_124 ,
F_162 ( 0 ) ) ;
}
static inline void * F_190 ( unsigned long V_46 ,
int V_50 , T_6 V_66 )
{
return F_182 ( V_46 , 1 , V_66 , V_136 ,
V_50 , F_162 ( 0 ) ) ;
}
void * F_191 ( unsigned long V_46 )
{
return F_190 ( V_46 , V_124 ,
V_112 | V_135 ) ;
}
void * F_192 ( unsigned long V_46 )
{
return F_190 ( V_46 , V_124 ,
V_112 | V_135 | V_132 ) ;
}
void * F_193 ( unsigned long V_46 )
{
struct V_113 * V_119 ;
void * V_27 ;
V_27 = F_182 ( V_46 , V_141 ,
V_112 | V_135 | V_132 ,
V_136 , V_124 ,
F_162 ( 0 ) ) ;
if ( V_27 ) {
V_119 = F_166 ( V_27 ) ;
V_119 -> V_66 |= V_142 ;
}
return V_27 ;
}
void * F_194 ( unsigned long V_46 , int V_50 )
{
return F_182 ( V_46 , 1 , V_112 | V_135 , V_136 ,
V_50 , F_162 ( 0 ) ) ;
}
void * F_195 ( unsigned long V_46 , int V_50 )
{
return F_190 ( V_46 , V_50 ,
V_112 | V_135 | V_132 ) ;
}
void * F_196 ( unsigned long V_46 )
{
return F_182 ( V_46 , 1 , V_112 | V_135 , V_143 ,
V_124 , F_162 ( 0 ) ) ;
}
void * F_197 ( unsigned long V_46 )
{
return F_182 ( V_46 , 1 , V_144 , V_136 ,
V_124 , F_162 ( 0 ) ) ;
}
void * F_198 ( unsigned long V_46 )
{
struct V_113 * V_119 ;
void * V_27 ;
V_27 = F_182 ( V_46 , 1 , V_144 | V_132 , V_136 ,
V_124 , F_162 ( 0 ) ) ;
if ( V_27 ) {
V_119 = F_166 ( V_27 ) ;
V_119 -> V_66 |= V_142 ;
}
return V_27 ;
}
static int F_199 ( char * V_145 , char * V_10 , unsigned long V_111 )
{
struct V_20 * V_4 ;
int V_146 = 0 ;
while ( V_111 ) {
unsigned long V_104 , V_147 ;
V_104 = ( unsigned long ) V_10 & ~ V_54 ;
V_147 = V_15 - V_104 ;
if ( V_147 > V_111 )
V_147 = V_111 ;
V_4 = F_39 ( V_10 ) ;
if ( V_4 ) {
void * V_148 = F_200 ( V_4 ) ;
memcpy ( V_145 , V_148 + V_104 , V_147 ) ;
F_201 ( V_148 ) ;
} else
memset ( V_145 , 0 , V_147 ) ;
V_10 += V_147 ;
V_145 += V_147 ;
V_146 += V_147 ;
V_111 -= V_147 ;
}
return V_146 ;
}
static int F_202 ( char * V_145 , char * V_10 , unsigned long V_111 )
{
struct V_20 * V_4 ;
int V_146 = 0 ;
while ( V_111 ) {
unsigned long V_104 , V_147 ;
V_104 = ( unsigned long ) V_10 & ~ V_54 ;
V_147 = V_15 - V_104 ;
if ( V_147 > V_111 )
V_147 = V_111 ;
V_4 = F_39 ( V_10 ) ;
if ( V_4 ) {
void * V_148 = F_200 ( V_4 ) ;
memcpy ( V_148 + V_104 , V_145 , V_147 ) ;
F_201 ( V_148 ) ;
}
V_10 += V_147 ;
V_145 += V_147 ;
V_146 += V_147 ;
V_111 -= V_147 ;
}
return V_146 ;
}
long F_203 ( char * V_145 , char * V_10 , unsigned long V_111 )
{
struct V_34 * V_38 ;
struct V_113 * V_114 ;
char * V_149 , * V_150 = V_145 ;
unsigned long V_151 = V_111 ;
unsigned long V_36 ;
if ( ( unsigned long ) V_10 + V_111 < V_111 )
V_111 = - ( unsigned long ) V_10 ;
F_63 ( & V_58 ) ;
F_204 (va, &vmap_area_list, list) {
if ( ! V_111 )
break;
if ( ! ( V_38 -> V_66 & V_118 ) )
continue;
V_114 = V_38 -> V_114 ;
V_149 = ( char * ) V_114 -> V_10 ;
if ( V_10 >= V_149 + F_152 ( V_114 ) )
continue;
while ( V_10 < V_149 ) {
if ( V_111 == 0 )
goto V_152;
* V_145 = '\0' ;
V_145 ++ ;
V_10 ++ ;
V_111 -- ;
}
V_36 = V_149 + F_152 ( V_114 ) - V_10 ;
if ( V_36 > V_111 )
V_36 = V_111 ;
if ( ! ( V_114 -> V_66 & V_122 ) )
F_199 ( V_145 , V_10 , V_36 ) ;
else
memset ( V_145 , 0 , V_36 ) ;
V_145 += V_36 ;
V_10 += V_36 ;
V_111 -= V_36 ;
}
V_152:
F_67 ( & V_58 ) ;
if ( V_145 == V_150 )
return 0 ;
if ( V_145 != V_150 + V_151 )
memset ( V_145 , 0 , V_151 - ( V_145 - V_150 ) ) ;
return V_151 ;
}
long F_205 ( char * V_145 , char * V_10 , unsigned long V_111 )
{
struct V_34 * V_38 ;
struct V_113 * V_114 ;
char * V_149 ;
unsigned long V_36 , V_151 ;
int V_146 = 0 ;
if ( ( unsigned long ) V_10 + V_111 < V_111 )
V_111 = - ( unsigned long ) V_10 ;
V_151 = V_111 ;
F_63 ( & V_58 ) ;
F_204 (va, &vmap_area_list, list) {
if ( ! V_111 )
break;
if ( ! ( V_38 -> V_66 & V_118 ) )
continue;
V_114 = V_38 -> V_114 ;
V_149 = ( char * ) V_114 -> V_10 ;
if ( V_10 >= V_149 + F_152 ( V_114 ) )
continue;
while ( V_10 < V_149 ) {
if ( V_111 == 0 )
goto V_152;
V_145 ++ ;
V_10 ++ ;
V_111 -- ;
}
V_36 = V_149 + F_152 ( V_114 ) - V_10 ;
if ( V_36 > V_111 )
V_36 = V_111 ;
if ( ! ( V_114 -> V_66 & V_122 ) ) {
F_202 ( V_145 , V_10 , V_36 ) ;
V_146 ++ ;
}
V_145 += V_36 ;
V_10 += V_36 ;
V_111 -= V_36 ;
}
V_152:
F_67 ( & V_58 ) ;
if ( ! V_146 )
return 0 ;
return V_151 ;
}
int F_206 ( struct V_153 * V_154 , unsigned long V_155 ,
void * V_156 , unsigned long V_46 )
{
struct V_113 * V_119 ;
V_46 = F_159 ( V_46 ) ;
if ( ! F_169 ( V_155 ) || ! F_169 ( V_156 ) )
return - V_157 ;
V_119 = F_166 ( V_156 ) ;
if ( ! V_119 )
return - V_157 ;
if ( ! ( V_119 -> V_66 & V_142 ) )
return - V_157 ;
if ( V_156 + V_46 > V_119 -> V_10 + V_119 -> V_46 )
return - V_157 ;
do {
struct V_20 * V_20 = F_39 ( V_156 ) ;
int V_27 ;
V_27 = F_207 ( V_154 , V_155 , V_20 ) ;
if ( V_27 )
return V_27 ;
V_155 += V_15 ;
V_156 += V_15 ;
V_46 -= V_15 ;
} while ( V_46 > 0 );
V_154 -> V_158 |= V_159 | V_160 ;
return 0 ;
}
int F_208 ( struct V_153 * V_154 , void * V_10 ,
unsigned long V_161 )
{
return F_206 ( V_154 , V_154 -> V_162 ,
V_10 + ( V_161 << V_80 ) ,
V_154 -> V_163 - V_154 -> V_162 ) ;
}
void __weak F_209 ( void )
{
}
static int F_210 ( T_2 * V_12 , T_10 V_164 , unsigned long V_10 , void * V_165 )
{
T_2 * * * V_4 = V_165 ;
if ( V_4 ) {
* ( * V_4 ) = V_12 ;
( * V_4 ) ++ ;
}
return 0 ;
}
struct V_113 * F_211 ( T_8 V_46 , T_2 * * V_166 )
{
struct V_113 * V_119 ;
V_119 = F_165 ( V_46 , V_122 ,
F_162 ( 0 ) ) ;
if ( V_119 == NULL )
return NULL ;
if ( F_212 ( & V_14 , ( unsigned long ) V_119 -> V_10 ,
V_46 , F_210 , V_166 ? & V_166 : NULL ) ) {
F_213 ( V_119 ) ;
return NULL ;
}
return V_119 ;
}
void F_213 ( struct V_113 * V_119 )
{
struct V_113 * V_27 ;
V_27 = F_167 ( V_119 -> V_10 ) ;
F_21 ( V_27 != V_119 ) ;
F_71 ( V_119 ) ;
}
static struct V_34 * F_214 ( struct V_35 * V_36 )
{
return V_36 ? F_50 ( V_36 , struct V_34 , V_35 ) : NULL ;
}
static bool F_215 ( unsigned long V_11 ,
struct V_34 * * V_167 ,
struct V_34 * * V_168 )
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
* V_167 = V_38 ;
* V_168 = F_214 ( F_55 ( & ( * V_167 ) -> V_35 ) ) ;
} else {
* V_168 = V_38 ;
* V_167 = F_214 ( F_216 ( & ( * V_168 ) -> V_35 ) ) ;
}
return true ;
}
static unsigned long F_217 ( struct V_34 * * V_167 ,
struct V_34 * * V_168 ,
unsigned long V_47 )
{
const unsigned long V_169 = V_70 & ~ ( V_47 - 1 ) ;
unsigned long V_10 ;
if ( * V_167 )
V_10 = F_218 ( ( * V_167 ) -> va_start & ~ ( V_47 - 1 ) , V_169 ) ;
else
V_10 = V_169 ;
while ( * V_168 && ( * V_168 ) -> va_end > V_10 ) {
* V_167 = * V_168 ;
* V_168 = F_214 ( F_55 ( & ( * V_167 ) -> V_35 ) ) ;
}
return V_10 ;
}
struct V_113 * * F_219 ( const unsigned long * V_170 ,
const T_8 * V_171 , int V_172 ,
T_8 V_47 )
{
const unsigned long V_173 = F_64 ( V_69 , V_47 ) ;
const unsigned long V_169 = V_70 & ~ ( V_47 - 1 ) ;
struct V_34 * * V_174 , * V_44 , * V_17 ;
struct V_113 * * V_175 ;
int V_119 , V_176 , V_177 , V_178 ;
unsigned long V_179 , V_25 , V_11 , V_180 ;
bool V_52 = false ;
F_21 ( V_47 & ~ V_54 || ! F_58 ( V_47 ) ) ;
for ( V_177 = 0 , V_119 = 0 ; V_119 < V_172 ; V_119 ++ ) {
V_25 = V_170 [ V_119 ] ;
V_11 = V_25 + V_171 [ V_119 ] ;
F_21 ( ! F_220 ( V_170 [ V_119 ] , V_47 ) ) ;
F_21 ( ! F_220 ( V_171 [ V_119 ] , V_47 ) ) ;
if ( V_25 > V_170 [ V_177 ] )
V_177 = V_119 ;
for ( V_176 = 0 ; V_176 < V_172 ; V_176 ++ ) {
unsigned long V_181 = V_170 [ V_176 ] ;
unsigned long V_182 = V_181 + V_171 [ V_176 ] ;
if ( V_176 == V_119 )
continue;
F_21 ( V_181 >= V_25 && V_181 < V_11 ) ;
F_21 ( V_182 <= V_11 && V_182 > V_25 ) ;
}
}
V_180 = V_170 [ V_177 ] + V_171 [ V_177 ] ;
if ( V_169 - V_173 < V_180 ) {
F_9 ( true ) ;
return NULL ;
}
V_175 = F_221 ( V_172 , sizeof( V_175 [ 0 ] ) , V_112 ) ;
V_174 = F_221 ( V_172 , sizeof( V_174 [ 0 ] ) , V_112 ) ;
if ( ! V_174 || ! V_175 )
goto V_183;
for ( V_119 = 0 ; V_119 < V_172 ; V_119 ++ ) {
V_174 [ V_119 ] = F_147 ( sizeof( struct V_34 ) , V_112 ) ;
V_175 [ V_119 ] = F_147 ( sizeof( struct V_113 ) , V_112 ) ;
if ( ! V_174 [ V_119 ] || ! V_175 [ V_119 ] )
goto V_184;
}
V_57:
F_63 ( & V_58 ) ;
V_119 = V_178 = V_177 ;
V_25 = V_170 [ V_119 ] ;
V_11 = V_25 + V_171 [ V_119 ] ;
if ( ! F_215 ( V_71 , & V_17 , & V_44 ) ) {
V_179 = V_169 - V_180 ;
goto V_65;
}
V_179 = F_217 ( & V_17 , & V_44 , V_47 ) - V_11 ;
while ( true ) {
F_21 ( V_17 && V_17 -> va_end <= V_179 + V_11 ) ;
F_21 ( V_44 && V_44 -> va_end > V_179 + V_11 ) ;
if ( V_179 + V_180 < V_173 + V_180 ) {
F_67 ( & V_58 ) ;
if ( ! V_52 ) {
F_68 () ;
V_52 = true ;
goto V_57;
}
goto V_184;
}
if ( V_17 && V_17 -> va_start < V_179 + V_11 ) {
V_179 = F_217 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_178 = V_119 ;
continue;
}
if ( V_44 && V_44 -> va_end > V_179 + V_25 ) {
V_17 = V_44 ;
V_44 = F_214 ( F_55 ( & V_17 -> V_35 ) ) ;
V_179 = F_217 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_178 = V_119 ;
continue;
}
V_119 = ( V_119 + V_172 - 1 ) % V_172 ;
if ( V_119 == V_178 )
break;
V_25 = V_170 [ V_119 ] ;
V_11 = V_25 + V_171 [ V_119 ] ;
F_215 ( V_179 + V_11 , & V_17 , & V_44 ) ;
}
V_65:
for ( V_119 = 0 ; V_119 < V_172 ; V_119 ++ ) {
struct V_34 * V_38 = V_174 [ V_119 ] ;
V_38 -> va_start = V_179 + V_170 [ V_119 ] ;
V_38 -> va_end = V_38 -> va_start + V_171 [ V_119 ] ;
F_51 ( V_38 ) ;
}
V_71 = V_179 + V_170 [ V_177 ] ;
F_67 ( & V_58 ) ;
for ( V_119 = 0 ; V_119 < V_172 ; V_119 ++ )
F_153 ( V_175 [ V_119 ] , V_174 [ V_119 ] , V_140 ,
F_219 ) ;
F_71 ( V_174 ) ;
return V_175 ;
V_184:
for ( V_119 = 0 ; V_119 < V_172 ; V_119 ++ ) {
F_71 ( V_174 [ V_119 ] ) ;
F_71 ( V_175 [ V_119 ] ) ;
}
V_183:
F_71 ( V_174 ) ;
F_71 ( V_175 ) ;
return NULL ;
}
void F_222 ( struct V_113 * * V_175 , int V_172 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_172 ; V_103 ++ )
F_213 ( V_175 [ V_103 ] ) ;
F_71 ( V_175 ) ;
}
static void * F_223 ( struct V_185 * V_186 , T_11 * V_187 )
__acquires( &vmap_area_lock
static void * F_224 ( struct V_185 * V_186 , void * V_4 , T_11 * V_187 )
{
struct V_34 * V_38 = V_4 , * V_17 ;
++ * V_187 ;
V_17 = F_66 ( V_38 -> V_8 . V_17 , F_225 ( * V_38 ) , V_8 ) ;
if ( & V_17 -> V_8 != & V_45 )
return V_17 ;
return NULL ;
}
static void F_226 ( struct V_185 * V_186 , void * V_4 )
__releases( &vmap_area_lock
static void F_227 ( struct V_185 * V_186 , struct V_113 * V_188 )
{
if ( F_228 ( V_189 ) ) {
unsigned int V_22 , * V_190 = V_186 -> V_191 ;
if ( ! V_190 )
return;
F_229 () ;
if ( V_188 -> V_66 & V_121 )
return;
memset ( V_190 , 0 , V_192 * sizeof( unsigned int ) ) ;
for ( V_22 = 0 ; V_22 < V_188 -> V_127 ; V_22 ++ )
V_190 [ F_230 ( V_188 -> V_21 [ V_22 ] ) ] ++ ;
F_231 (nr, N_HIGH_MEMORY)
if ( V_190 [ V_22 ] )
F_232 ( V_186 , L_7 , V_22 , V_190 [ V_22 ] ) ;
}
}
static int F_233 ( struct V_185 * V_186 , void * V_4 )
{
struct V_34 * V_38 = V_4 ;
struct V_113 * V_188 ;
if ( ! ( V_38 -> V_66 & V_118 ) )
return 0 ;
V_188 = V_38 -> V_114 ;
F_232 ( V_186 , L_8 ,
V_188 -> V_10 , V_188 -> V_10 + V_188 -> V_46 , V_188 -> V_46 ) ;
if ( V_188 -> V_120 )
F_232 ( V_186 , L_9 , V_188 -> V_120 ) ;
if ( V_188 -> V_127 )
F_232 ( V_186 , L_10 , V_188 -> V_127 ) ;
if ( V_188 -> V_193 )
F_232 ( V_186 , L_11 , ( unsigned long long ) V_188 -> V_193 ) ;
if ( V_188 -> V_66 & V_122 )
F_234 ( V_186 , L_12 ) ;
if ( V_188 -> V_66 & V_140 )
F_234 ( V_186 , L_13 ) ;
if ( V_188 -> V_66 & V_194 )
F_234 ( V_186 , L_14 ) ;
if ( V_188 -> V_66 & V_142 )
F_234 ( V_186 , L_15 ) ;
if ( V_188 -> V_66 & V_128 )
F_234 ( V_186 , L_16 ) ;
F_227 ( V_186 , V_188 ) ;
F_235 ( V_186 , '\n' ) ;
return 0 ;
}
static int F_236 ( struct V_195 * V_195 , struct V_196 * V_196 )
{
unsigned int * V_197 = NULL ;
int V_27 ;
if ( F_228 ( V_189 ) ) {
V_197 = F_237 ( V_192 * sizeof( unsigned int ) , V_112 ) ;
if ( V_197 == NULL )
return - V_23 ;
}
V_27 = F_238 ( V_196 , & V_198 ) ;
if ( ! V_27 ) {
struct V_185 * V_186 = V_196 -> V_199 ;
V_186 -> V_191 = V_197 ;
} else
F_71 ( V_197 ) ;
return V_27 ;
}
static int T_7 F_239 ( void )
{
F_240 ( L_17 , V_200 , NULL , & V_201 ) ;
return 0 ;
}
void F_241 ( struct V_202 * V_203 )
{
struct V_34 * V_38 ;
unsigned long V_204 ;
unsigned long V_205 ;
V_203 -> V_206 = 0 ;
V_203 -> V_207 = 0 ;
V_205 = V_69 ;
F_94 () ;
if ( F_242 ( & V_45 ) ) {
V_203 -> V_207 = V_208 ;
goto V_209;
}
F_95 (va, &vmap_area_list, list) {
unsigned long V_10 = V_38 -> va_start ;
if ( V_10 < V_69 )
continue;
if ( V_10 >= V_70 )
break;
if ( V_38 -> V_66 & ( V_79 | V_82 ) )
continue;
V_203 -> V_206 += ( V_38 -> va_end - V_38 -> va_start ) ;
V_204 = V_10 - V_205 ;
if ( V_203 -> V_207 < V_204 )
V_203 -> V_207 = V_204 ;
V_205 = V_38 -> va_end ;
}
if ( V_70 - V_205 > V_203 -> V_207 )
V_203 -> V_207 = V_70 - V_205 ;
V_209:
F_97 () ;
}
