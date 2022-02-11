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
if ( F_59 ( & V_47 -> V_38 , & V_39 ) )
goto V_58;
V_47 = F_60 ( V_47 -> V_38 . V_9 ,
struct V_26 , V_38 ) ;
}
V_58:
if ( V_2 + V_40 > V_43 )
goto V_57;
V_30 -> va_start = V_2 ;
V_30 -> va_end = V_2 + V_40 ;
V_30 -> V_59 = 0 ;
F_46 ( V_30 ) ;
V_52 = & V_30 -> V_27 ;
F_61 ( & V_51 ) ;
F_16 ( V_30 -> va_start & ( V_41 - 1 ) ) ;
F_16 ( V_30 -> va_start < V_42 ) ;
F_16 ( V_30 -> va_end > V_43 ) ;
return V_30 ;
V_57:
F_61 ( & V_51 ) ;
if ( ! V_46 ) {
F_62 () ;
V_46 = 1 ;
goto V_50;
}
if ( F_63 () )
F_64 ( V_60
L_1
L_2 , V_40 ) ;
F_65 ( V_30 ) ;
return F_56 ( - V_16 ) ;
}
static void F_66 ( struct V_26 * V_30 )
{
F_16 ( F_67 ( & V_30 -> V_27 ) ) ;
if ( V_52 ) {
if ( V_30 -> va_end < V_54 ) {
V_52 = NULL ;
} else {
struct V_26 * V_61 ;
V_61 = F_45 ( V_52 , struct V_26 , V_27 ) ;
if ( V_30 -> va_start <= V_61 -> va_start ) {
V_52 = F_50 ( & V_30 -> V_27 ) ;
}
}
}
F_68 ( & V_30 -> V_27 , & V_29 ) ;
F_69 ( & V_30 -> V_27 ) ;
F_70 ( & V_30 -> V_38 ) ;
if ( V_30 -> va_end > V_62 && V_30 -> va_end <= V_63 )
V_64 = F_71 ( V_64 , V_30 -> va_end ) ;
F_72 ( V_30 , V_65 ) ;
}
static void F_73 ( struct V_26 * V_30 )
{
F_57 ( & V_51 ) ;
F_66 ( V_30 ) ;
F_61 ( & V_51 ) ;
}
static void F_74 ( struct V_26 * V_30 )
{
F_15 ( V_30 -> va_start , V_30 -> va_end ) ;
}
static void F_75 ( unsigned long V_17 , unsigned long V_3 )
{
#ifdef F_76
F_15 ( V_17 , V_3 ) ;
F_77 ( V_17 , V_3 ) ;
#endif
}
static unsigned long F_78 ( void )
{
unsigned int log ;
log = F_79 ( F_80 () ) ;
return log * ( 32UL * 1024 * 1024 / V_7 ) ;
}
void F_81 ( void )
{
F_82 ( & V_66 , F_78 () + 1 ) ;
}
static void F_83 ( unsigned long * V_17 , unsigned long * V_3 ,
int V_67 , int V_68 )
{
static F_84 ( V_69 ) ;
F_85 ( V_70 ) ;
struct V_26 * V_30 ;
struct V_26 * V_71 ;
int V_14 = 0 ;
if ( ! V_67 && ! V_68 ) {
if ( ! F_86 ( & V_69 ) )
return;
} else
F_57 ( & V_69 ) ;
if ( V_67 )
F_87 () ;
F_88 () ;
F_89 (va, &vmap_area_list, list) {
if ( V_30 -> V_59 & V_72 ) {
if ( V_30 -> va_start < * V_17 )
* V_17 = V_30 -> va_start ;
if ( V_30 -> va_end > * V_3 )
* V_3 = V_30 -> va_end ;
V_14 += ( V_30 -> va_end - V_30 -> va_start ) >> V_73 ;
F_90 ( & V_30 -> V_74 , & V_70 ) ;
V_30 -> V_59 |= V_75 ;
V_30 -> V_59 &= ~ V_72 ;
}
}
F_91 () ;
if ( V_14 )
F_92 ( V_14 , & V_66 ) ;
if ( V_14 || V_68 )
F_77 ( * V_17 , * V_3 ) ;
if ( V_14 ) {
F_57 ( & V_51 ) ;
F_93 (va, n_va, &valist, purge_list)
F_66 ( V_30 ) ;
F_61 ( & V_51 ) ;
}
F_61 ( & V_69 ) ;
}
static void F_94 ( void )
{
unsigned long V_17 = V_76 , V_3 = 0 ;
F_83 ( & V_17 , & V_3 , 0 , 0 ) ;
}
static void F_62 ( void )
{
unsigned long V_17 = V_76 , V_3 = 0 ;
F_83 ( & V_17 , & V_3 , 1 , 0 ) ;
}
static void F_95 ( struct V_26 * V_30 )
{
V_30 -> V_59 |= V_72 ;
F_96 ( ( V_30 -> va_end - V_30 -> va_start ) >> V_73 , & V_66 ) ;
if ( F_55 ( F_97 ( & V_66 ) > F_78 () ) )
F_94 () ;
}
static void F_98 ( struct V_26 * V_30 )
{
F_74 ( V_30 ) ;
F_95 ( V_30 ) ;
}
static void F_99 ( struct V_26 * V_30 )
{
F_100 ( V_30 -> va_start , V_30 -> va_end ) ;
F_98 ( V_30 ) ;
}
static struct V_26 * F_101 ( unsigned long V_2 )
{
struct V_26 * V_30 ;
F_57 ( & V_51 ) ;
V_30 = F_44 ( V_2 ) ;
F_61 ( & V_51 ) ;
return V_30 ;
}
static void F_102 ( unsigned long V_2 )
{
struct V_26 * V_30 ;
V_30 = F_101 ( V_2 ) ;
F_16 ( ! V_30 ) ;
F_99 ( V_30 ) ;
}
static unsigned long F_103 ( unsigned long V_2 )
{
V_2 -= V_62 & ~ ( V_77 - 1 ) ;
V_2 /= V_77 ;
return V_2 ;
}
static struct V_78 * F_104 ( T_6 V_45 )
{
struct V_79 * V_80 ;
struct V_78 * V_81 ;
struct V_26 * V_30 ;
unsigned long V_82 ;
int V_44 , V_18 ;
V_44 = F_105 () ;
V_81 = F_54 ( sizeof( struct V_78 ) ,
V_45 & V_49 , V_44 ) ;
if ( F_55 ( ! V_81 ) )
return F_56 ( - V_15 ) ;
V_30 = F_52 ( V_77 , V_77 ,
V_62 , V_63 ,
V_44 , V_45 ) ;
if ( F_106 ( V_30 ) ) {
F_65 ( V_81 ) ;
return F_107 ( V_30 ) ;
}
V_18 = F_108 ( V_45 ) ;
if ( F_55 ( V_18 ) ) {
F_65 ( V_81 ) ;
F_73 ( V_30 ) ;
return F_56 ( V_18 ) ;
}
F_109 ( & V_81 -> V_83 ) ;
V_81 -> V_30 = V_30 ;
V_81 -> free = V_84 ;
V_81 -> V_85 = 0 ;
F_110 ( V_81 -> V_86 , V_84 ) ;
F_110 ( V_81 -> V_87 , V_84 ) ;
F_111 ( & V_81 -> V_88 ) ;
V_82 = F_103 ( V_30 -> va_start ) ;
F_57 ( & V_89 ) ;
V_18 = F_112 ( & V_90 , V_82 , V_81 ) ;
F_61 ( & V_89 ) ;
F_16 ( V_18 ) ;
F_113 () ;
V_80 = & F_114 ( V_79 ) ;
V_81 -> V_80 = V_80 ;
F_57 ( & V_80 -> V_83 ) ;
F_51 ( & V_81 -> V_88 , & V_80 -> free ) ;
F_61 ( & V_80 -> V_83 ) ;
F_115 ( V_79 ) ;
return V_81 ;
}
static void F_116 ( struct V_78 * V_81 )
{
struct V_78 * V_35 ;
unsigned long V_82 ;
V_82 = F_103 ( V_81 -> V_30 -> va_start ) ;
F_57 ( & V_89 ) ;
V_35 = F_117 ( & V_90 , V_82 ) ;
F_61 ( & V_89 ) ;
F_16 ( V_35 != V_81 ) ;
F_95 ( V_81 -> V_30 ) ;
F_72 ( V_81 , V_65 ) ;
}
static void F_118 ( int V_91 )
{
F_85 ( V_92 ) ;
struct V_78 * V_81 ;
struct V_78 * V_93 ;
struct V_79 * V_80 = & F_119 ( V_79 , V_91 ) ;
F_88 () ;
F_89 (vb, &vbq->free, free_list) {
if ( ! ( V_81 -> free + V_81 -> V_85 == V_84 && V_81 -> V_85 != V_84 ) )
continue;
F_57 ( & V_81 -> V_83 ) ;
if ( V_81 -> free + V_81 -> V_85 == V_84 && V_81 -> V_85 != V_84 ) {
V_81 -> free = 0 ;
V_81 -> V_85 = V_84 ;
F_120 ( V_81 -> V_86 , V_84 ) ;
F_120 ( V_81 -> V_87 , V_84 ) ;
F_57 ( & V_80 -> V_83 ) ;
F_70 ( & V_81 -> V_88 ) ;
F_61 ( & V_80 -> V_83 ) ;
F_61 ( & V_81 -> V_83 ) ;
F_90 ( & V_81 -> V_92 , & V_92 ) ;
} else
F_61 ( & V_81 -> V_83 ) ;
}
F_91 () ;
F_93 (vb, n_vb, &purge, purge) {
F_121 ( & V_81 -> V_92 ) ;
F_116 ( V_81 ) ;
}
}
static void F_122 ( void )
{
F_118 ( F_123 () ) ;
}
static void F_87 ( void )
{
int V_91 ;
F_124 (cpu)
F_118 ( V_91 ) ;
}
static void * F_125 ( unsigned long V_40 , T_6 V_45 )
{
struct V_79 * V_80 ;
struct V_78 * V_81 ;
unsigned long V_2 = 0 ;
unsigned int V_94 ;
int V_92 = 0 ;
F_16 ( V_40 & ~ V_48 ) ;
F_16 ( V_40 > V_7 * V_95 ) ;
if ( F_4 ( V_40 == 0 ) ) {
return NULL ;
}
V_94 = F_126 ( V_40 ) ;
V_96:
F_88 () ;
V_80 = & F_114 ( V_79 ) ;
F_89 (vb, &vbq->free, free_list) {
int V_97 ;
F_57 ( & V_81 -> V_83 ) ;
if ( V_81 -> free < 1UL << V_94 )
goto V_9;
V_97 = F_127 ( V_81 -> V_86 ,
V_84 , V_94 ) ;
if ( V_97 < 0 ) {
if ( V_81 -> free + V_81 -> V_85 == V_84 ) {
F_16 ( V_81 -> V_85 != V_84 ) ;
V_92 = 1 ;
}
goto V_9;
}
V_2 = V_81 -> V_30 -> va_start + ( V_97 << V_73 ) ;
F_16 ( F_103 ( V_2 ) !=
F_103 ( V_81 -> V_30 -> va_start ) ) ;
V_81 -> free -= 1UL << V_94 ;
if ( V_81 -> free == 0 ) {
F_57 ( & V_80 -> V_83 ) ;
F_70 ( & V_81 -> V_88 ) ;
F_61 ( & V_80 -> V_83 ) ;
}
F_61 ( & V_81 -> V_83 ) ;
break;
V_9:
F_61 ( & V_81 -> V_83 ) ;
}
if ( V_92 )
F_122 () ;
F_115 ( V_79 ) ;
F_91 () ;
if ( ! V_2 ) {
V_81 = F_104 ( V_45 ) ;
if ( F_106 ( V_81 ) )
return V_81 ;
goto V_96;
}
return ( void * ) V_2 ;
}
static void F_128 ( const void * V_2 , unsigned long V_40 )
{
unsigned long V_98 ;
unsigned long V_82 ;
unsigned int V_94 ;
struct V_78 * V_81 ;
F_16 ( V_40 & ~ V_48 ) ;
F_16 ( V_40 > V_7 * V_95 ) ;
F_100 ( ( unsigned long ) V_2 , ( unsigned long ) V_2 + V_40 ) ;
V_94 = F_126 ( V_40 ) ;
V_98 = ( unsigned long ) V_2 & ( V_77 - 1 ) ;
V_82 = F_103 ( ( unsigned long ) V_2 ) ;
F_88 () ;
V_81 = F_129 ( & V_90 , V_82 ) ;
F_91 () ;
F_16 ( ! V_81 ) ;
F_15 ( ( unsigned long ) V_2 , ( unsigned long ) V_2 + V_40 ) ;
F_57 ( & V_81 -> V_83 ) ;
F_16 ( F_130 ( V_81 -> V_87 , V_98 >> V_73 , V_94 ) ) ;
V_81 -> V_85 += 1UL << V_94 ;
if ( V_81 -> V_85 == V_84 ) {
F_16 ( V_81 -> free ) ;
F_61 ( & V_81 -> V_83 ) ;
F_116 ( V_81 ) ;
} else
F_61 ( & V_81 -> V_83 ) ;
}
void F_131 ( void )
{
unsigned long V_17 = V_76 , V_3 = 0 ;
int V_91 ;
int V_99 = 0 ;
if ( F_55 ( ! V_100 ) )
return;
F_124 (cpu) {
struct V_79 * V_80 = & F_119 ( V_79 , V_91 ) ;
struct V_78 * V_81 ;
F_88 () ;
F_89 (vb, &vbq->free, free_list) {
int V_97 ;
F_57 ( & V_81 -> V_83 ) ;
V_97 = F_132 ( V_81 -> V_87 , V_84 ) ;
while ( V_97 < V_84 ) {
unsigned long V_101 , V_102 ;
int V_103 ;
V_103 = F_133 ( V_81 -> V_87 ,
V_84 , V_97 ) ;
V_101 = V_81 -> V_30 -> va_start + ( V_97 << V_73 ) ;
V_102 = V_81 -> V_30 -> va_start + ( V_103 << V_73 ) ;
V_99 = 1 ;
if ( V_101 < V_17 )
V_17 = V_101 ;
if ( V_102 > V_3 )
V_3 = V_102 ;
V_97 = V_103 ;
V_97 = F_134 ( V_81 -> V_87 ,
V_84 , V_97 ) ;
}
F_61 ( & V_81 -> V_83 ) ;
}
F_91 () ;
}
F_83 ( & V_17 , & V_3 , 1 , V_99 ) ;
}
void F_135 ( const void * V_104 , unsigned int V_105 )
{
unsigned long V_40 = V_105 << V_73 ;
unsigned long V_2 = ( unsigned long ) V_104 ;
F_16 ( ! V_2 ) ;
F_16 ( V_2 < V_62 ) ;
F_16 ( V_2 > V_63 ) ;
F_16 ( V_2 & ( V_7 - 1 ) ) ;
F_136 ( V_104 , V_40 ) ;
F_75 ( V_2 , V_2 + V_40 ) ;
if ( F_137 ( V_105 <= V_95 ) )
F_128 ( V_104 , V_40 ) ;
else
F_102 ( V_2 ) ;
}
void * F_138 ( struct V_12 * * V_13 , unsigned int V_105 , int V_44 , T_5 V_11 )
{
unsigned long V_40 = V_105 << V_73 ;
unsigned long V_2 ;
void * V_104 ;
if ( F_137 ( V_105 <= V_95 ) ) {
V_104 = F_125 ( V_40 , V_106 ) ;
if ( F_106 ( V_104 ) )
return NULL ;
V_2 = ( unsigned long ) V_104 ;
} else {
struct V_26 * V_30 ;
V_30 = F_52 ( V_40 , V_7 ,
V_62 , V_63 , V_44 , V_106 ) ;
if ( F_106 ( V_30 ) )
return NULL ;
V_2 = V_30 -> va_start ;
V_104 = ( void * ) V_2 ;
}
if ( F_29 ( V_2 , V_2 + V_40 , V_11 , V_13 ) < 0 ) {
F_135 ( V_104 , V_105 ) ;
return NULL ;
}
return V_104 ;
}
void T_7 F_139 ( struct V_107 * V_108 )
{
struct V_107 * V_35 , * * V_33 ;
F_16 ( V_100 ) ;
for ( V_33 = & V_109 ; ( V_35 = * V_33 ) != NULL ; V_33 = & V_35 -> V_9 ) {
if ( V_35 -> V_2 >= V_108 -> V_2 ) {
F_16 ( V_35 -> V_2 < V_108 -> V_2 + V_108 -> V_40 ) ;
break;
} else
F_16 ( V_35 -> V_2 + V_35 -> V_40 > V_108 -> V_2 ) ;
}
V_108 -> V_9 = * V_33 ;
* V_33 = V_108 ;
}
void T_7 F_140 ( struct V_107 * V_108 , T_8 V_41 )
{
static T_8 T_9 V_110 ;
unsigned long V_2 ;
V_2 = F_58 ( V_62 + T_9 , V_41 ) ;
T_9 = F_141 ( V_2 + V_108 -> V_40 ) - V_62 ;
V_108 -> V_2 = ( void * ) V_2 ;
F_139 ( V_108 ) ;
}
void T_7 F_142 ( void )
{
struct V_26 * V_30 ;
struct V_107 * V_35 ;
int V_97 ;
F_124 (i) {
struct V_79 * V_80 ;
V_80 = & F_119 ( V_79 , V_97 ) ;
F_109 ( & V_80 -> V_83 ) ;
F_111 ( & V_80 -> free ) ;
}
for ( V_35 = V_109 ; V_35 ; V_35 = V_35 -> V_9 ) {
V_30 = F_143 ( sizeof( struct V_26 ) , V_111 ) ;
V_30 -> V_59 = V_112 ;
V_30 -> va_start = ( unsigned long ) V_35 -> V_2 ;
V_30 -> va_end = V_30 -> va_start + V_35 -> V_40 ;
V_30 -> V_108 = V_35 ;
F_46 ( V_30 ) ;
}
V_64 = V_63 ;
V_100 = true ;
}
int F_144 ( unsigned long V_2 , unsigned long V_40 ,
T_5 V_11 , struct V_12 * * V_13 )
{
return F_28 ( V_2 , V_2 + V_40 , V_11 , V_13 ) ;
}
void F_145 ( unsigned long V_2 , unsigned long V_40 )
{
F_15 ( V_2 , V_2 + V_40 ) ;
}
void F_146 ( unsigned long V_2 , unsigned long V_40 )
{
unsigned long V_3 = V_2 + V_40 ;
F_100 ( V_2 , V_3 ) ;
F_15 ( V_2 , V_3 ) ;
F_77 ( V_2 , V_3 ) ;
}
int F_147 ( struct V_107 * V_113 , T_5 V_11 , struct V_12 * * * V_13 )
{
unsigned long V_2 = ( unsigned long ) V_113 -> V_2 ;
unsigned long V_3 = V_2 + V_113 -> V_40 - V_7 ;
int V_18 ;
V_18 = F_29 ( V_2 , V_3 , V_11 , * V_13 ) ;
if ( V_18 > 0 ) {
* V_13 += V_18 ;
V_18 = 0 ;
}
return V_18 ;
}
static void F_148 ( struct V_107 * V_108 , struct V_26 * V_30 ,
unsigned long V_59 , const void * V_114 )
{
V_108 -> V_59 = V_59 ;
V_108 -> V_2 = ( void * ) V_30 -> va_start ;
V_108 -> V_40 = V_30 -> va_end - V_30 -> va_start ;
V_108 -> V_114 = V_114 ;
V_30 -> V_108 = V_108 ;
V_30 -> V_59 |= V_112 ;
}
static void F_149 ( struct V_107 * V_108 )
{
struct V_107 * V_35 , * * V_33 ;
V_108 -> V_59 &= ~ V_115 ;
F_150 ( & V_116 ) ;
for ( V_33 = & V_109 ; ( V_35 = * V_33 ) != NULL ; V_33 = & V_35 -> V_9 ) {
if ( V_35 -> V_2 >= V_108 -> V_2 )
break;
}
V_108 -> V_9 = * V_33 ;
* V_33 = V_108 ;
F_151 ( & V_116 ) ;
}
static void F_152 ( struct V_107 * V_108 , struct V_26 * V_30 ,
unsigned long V_59 , const void * V_114 )
{
F_148 ( V_108 , V_30 , V_59 , V_114 ) ;
F_149 ( V_108 ) ;
}
static struct V_107 * F_153 ( unsigned long V_40 ,
unsigned long V_41 , unsigned long V_59 , unsigned long V_17 ,
unsigned long V_3 , int V_44 , T_6 V_45 , const void * V_114 )
{
struct V_26 * V_30 ;
struct V_107 * V_113 ;
F_16 ( F_154 () ) ;
if ( V_59 & V_117 ) {
int V_118 = F_79 ( V_40 ) ;
if ( V_118 > V_119 )
V_118 = V_119 ;
else if ( V_118 < V_73 )
V_118 = V_73 ;
V_41 = 1ul << V_118 ;
}
V_40 = F_155 ( V_40 ) ;
if ( F_55 ( ! V_40 ) )
return NULL ;
V_113 = F_156 ( sizeof( * V_113 ) , V_45 & V_49 , V_44 ) ;
if ( F_55 ( ! V_113 ) )
return NULL ;
V_40 += V_7 ;
V_30 = F_52 ( V_40 , V_41 , V_17 , V_3 , V_44 , V_45 ) ;
if ( F_106 ( V_30 ) ) {
F_65 ( V_113 ) ;
return NULL ;
}
if ( V_59 & V_115 )
F_148 ( V_113 , V_30 , V_59 , V_114 ) ;
else
F_152 ( V_113 , V_30 , V_59 , V_114 ) ;
return V_113 ;
}
struct V_107 * F_157 ( unsigned long V_40 , unsigned long V_59 ,
unsigned long V_17 , unsigned long V_3 )
{
return F_153 ( V_40 , 1 , V_59 , V_17 , V_3 , - 1 , V_106 ,
F_158 ( 0 ) ) ;
}
struct V_107 * F_159 ( unsigned long V_40 , unsigned long V_59 ,
unsigned long V_17 , unsigned long V_3 ,
const void * V_114 )
{
return F_153 ( V_40 , 1 , V_59 , V_17 , V_3 , - 1 , V_106 ,
V_114 ) ;
}
struct V_107 * F_160 ( unsigned long V_40 , unsigned long V_59 )
{
return F_153 ( V_40 , 1 , V_59 , V_62 , V_63 ,
- 1 , V_106 , F_158 ( 0 ) ) ;
}
struct V_107 * F_161 ( unsigned long V_40 , unsigned long V_59 ,
const void * V_114 )
{
return F_153 ( V_40 , 1 , V_59 , V_62 , V_63 ,
- 1 , V_106 , V_114 ) ;
}
struct V_107 * F_162 ( const void * V_2 )
{
struct V_26 * V_30 ;
V_30 = F_101 ( ( unsigned long ) V_2 ) ;
if ( V_30 && V_30 -> V_59 & V_112 )
return V_30 -> V_108 ;
return NULL ;
}
struct V_107 * F_163 ( const void * V_2 )
{
struct V_26 * V_30 ;
V_30 = F_101 ( ( unsigned long ) V_2 ) ;
if ( V_30 && V_30 -> V_59 & V_112 ) {
struct V_107 * V_108 = V_30 -> V_108 ;
if ( ! ( V_108 -> V_59 & V_115 ) ) {
struct V_107 * V_35 , * * V_33 ;
F_150 ( & V_116 ) ;
for ( V_33 = & V_109 ; ( V_35 = * V_33 ) != V_108 ; V_33 = & V_35 -> V_9 )
;
* V_33 = V_35 -> V_9 ;
F_151 ( & V_116 ) ;
}
F_75 ( V_30 -> va_start , V_30 -> va_end ) ;
F_99 ( V_30 ) ;
V_108 -> V_40 -= V_7 ;
return V_108 ;
}
return NULL ;
}
static void F_164 ( const void * V_2 , int V_120 )
{
struct V_107 * V_113 ;
if ( ! V_2 )
return;
if ( ( V_7 - 1 ) & ( unsigned long ) V_2 ) {
F_165 ( 1 , V_121 L_3 , V_2 ) ;
return;
}
V_113 = F_163 ( V_2 ) ;
if ( F_55 ( ! V_113 ) ) {
F_165 ( 1 , V_121 L_4 ,
V_2 ) ;
return;
}
F_136 ( V_2 , V_113 -> V_40 ) ;
F_166 ( V_2 , V_113 -> V_40 ) ;
if ( V_120 ) {
int V_97 ;
for ( V_97 = 0 ; V_97 < V_113 -> V_122 ; V_97 ++ ) {
struct V_12 * V_12 = V_113 -> V_13 [ V_97 ] ;
F_16 ( ! V_12 ) ;
F_167 ( V_12 ) ;
}
if ( V_113 -> V_59 & V_123 )
F_168 ( V_113 -> V_13 ) ;
else
F_65 ( V_113 -> V_13 ) ;
}
F_65 ( V_113 ) ;
return;
}
void F_168 ( const void * V_2 )
{
F_16 ( F_154 () ) ;
F_169 ( V_2 ) ;
F_164 ( V_2 , 1 ) ;
}
void F_170 ( const void * V_2 )
{
F_16 ( F_154 () ) ;
F_171 () ;
F_164 ( V_2 , 0 ) ;
}
void * F_172 ( struct V_12 * * V_13 , unsigned int V_105 ,
unsigned long V_59 , T_5 V_11 )
{
struct V_107 * V_113 ;
F_171 () ;
if ( V_105 > V_124 )
return NULL ;
V_113 = F_161 ( ( V_105 << V_73 ) , V_59 ,
F_158 ( 0 ) ) ;
if ( ! V_113 )
return NULL ;
if ( F_147 ( V_113 , V_11 , & V_13 ) ) {
F_170 ( V_113 -> V_2 ) ;
return NULL ;
}
return V_113 -> V_2 ;
}
static void * F_173 ( struct V_107 * V_113 , T_6 V_45 ,
T_5 V_11 , int V_44 , const void * V_114 )
{
const int V_94 = 0 ;
struct V_12 * * V_13 ;
unsigned int V_122 , V_125 , V_97 ;
T_6 V_126 = ( V_45 & V_49 ) | V_127 ;
V_122 = ( V_113 -> V_40 - V_7 ) >> V_73 ;
V_125 = ( V_122 * sizeof( struct V_12 * ) ) ;
V_113 -> V_122 = V_122 ;
if ( V_125 > V_7 ) {
V_13 = F_174 ( V_125 , 1 , V_126 | V_128 ,
V_129 , V_44 , V_114 ) ;
V_113 -> V_59 |= V_123 ;
} else {
V_13 = F_54 ( V_125 , V_126 , V_44 ) ;
}
V_113 -> V_13 = V_13 ;
V_113 -> V_114 = V_114 ;
if ( ! V_113 -> V_13 ) {
F_163 ( V_113 -> V_2 ) ;
F_65 ( V_113 ) ;
return NULL ;
}
for ( V_97 = 0 ; V_97 < V_113 -> V_122 ; V_97 ++ ) {
struct V_12 * V_12 ;
T_6 V_130 = V_45 | V_131 ;
if ( V_44 < 0 )
V_12 = F_175 ( V_130 ) ;
else
V_12 = F_176 ( V_44 , V_130 , V_94 ) ;
if ( F_55 ( ! V_12 ) ) {
V_113 -> V_122 = V_97 ;
goto V_132;
}
V_113 -> V_13 [ V_97 ] = V_12 ;
}
if ( F_147 ( V_113 , V_11 , & V_13 ) )
goto V_132;
return V_113 -> V_2 ;
V_132:
F_177 ( V_45 , V_94 ,
L_5 ,
( V_113 -> V_122 * V_7 ) , V_113 -> V_40 ) ;
F_168 ( V_113 -> V_2 ) ;
return NULL ;
}
void * F_178 ( unsigned long V_40 , unsigned long V_41 ,
unsigned long V_17 , unsigned long V_3 , T_6 V_45 ,
T_5 V_11 , int V_44 , const void * V_114 )
{
struct V_107 * V_113 ;
void * V_2 ;
unsigned long V_133 = V_40 ;
V_40 = F_155 ( V_40 ) ;
if ( ! V_40 || ( V_40 >> V_73 ) > V_124 )
goto V_132;
V_113 = F_153 ( V_40 , V_41 , V_134 | V_115 ,
V_17 , V_3 , V_44 , V_45 , V_114 ) ;
if ( ! V_113 )
goto V_132;
V_2 = F_173 ( V_113 , V_45 , V_11 , V_44 , V_114 ) ;
if ( ! V_2 )
return NULL ;
F_149 ( V_113 ) ;
F_179 ( V_2 , V_133 , 3 , V_45 ) ;
return V_2 ;
V_132:
F_177 ( V_45 , 0 ,
L_6 ,
V_133 ) ;
return NULL ;
}
static void * F_174 ( unsigned long V_40 , unsigned long V_41 ,
T_6 V_45 , T_5 V_11 ,
int V_44 , const void * V_114 )
{
return F_178 ( V_40 , V_41 , V_62 , V_63 ,
V_45 , V_11 , V_44 , V_114 ) ;
}
void * F_180 ( unsigned long V_40 , T_6 V_45 , T_5 V_11 )
{
return F_174 ( V_40 , 1 , V_45 , V_11 , - 1 ,
F_158 ( 0 ) ) ;
}
static inline void * F_181 ( unsigned long V_40 ,
int V_44 , T_6 V_59 )
{
return F_174 ( V_40 , 1 , V_59 , V_129 ,
V_44 , F_158 ( 0 ) ) ;
}
void * F_182 ( unsigned long V_40 )
{
return F_181 ( V_40 , - 1 , V_106 | V_128 ) ;
}
void * F_183 ( unsigned long V_40 )
{
return F_181 ( V_40 , - 1 ,
V_106 | V_128 | V_127 ) ;
}
void * F_184 ( unsigned long V_40 )
{
struct V_107 * V_113 ;
void * V_19 ;
V_19 = F_174 ( V_40 , V_135 ,
V_106 | V_128 | V_127 ,
V_129 , - 1 , F_158 ( 0 ) ) ;
if ( V_19 ) {
V_113 = F_162 ( V_19 ) ;
V_113 -> V_59 |= V_136 ;
}
return V_19 ;
}
void * F_185 ( unsigned long V_40 , int V_44 )
{
return F_174 ( V_40 , 1 , V_106 | V_128 , V_129 ,
V_44 , F_158 ( 0 ) ) ;
}
void * F_186 ( unsigned long V_40 , int V_44 )
{
return F_181 ( V_40 , V_44 ,
V_106 | V_128 | V_127 ) ;
}
void * F_187 ( unsigned long V_40 )
{
return F_174 ( V_40 , 1 , V_106 | V_128 , V_137 ,
- 1 , F_158 ( 0 ) ) ;
}
void * F_188 ( unsigned long V_40 )
{
return F_174 ( V_40 , 1 , V_138 , V_129 ,
- 1 , F_158 ( 0 ) ) ;
}
void * F_189 ( unsigned long V_40 )
{
struct V_107 * V_113 ;
void * V_19 ;
V_19 = F_174 ( V_40 , 1 , V_138 | V_127 , V_129 ,
- 1 , F_158 ( 0 ) ) ;
if ( V_19 ) {
V_113 = F_162 ( V_19 ) ;
V_113 -> V_59 |= V_136 ;
}
return V_19 ;
}
static int F_190 ( char * V_139 , char * V_2 , unsigned long V_105 )
{
struct V_12 * V_33 ;
int V_140 = 0 ;
while ( V_105 ) {
unsigned long V_98 , V_141 ;
V_98 = ( unsigned long ) V_2 & ~ V_48 ;
V_141 = V_7 - V_98 ;
if ( V_141 > V_105 )
V_141 = V_105 ;
V_33 = F_34 ( V_2 ) ;
if ( V_33 ) {
void * V_142 = F_191 ( V_33 ) ;
memcpy ( V_139 , V_142 + V_98 , V_141 ) ;
F_192 ( V_142 ) ;
} else
memset ( V_139 , 0 , V_141 ) ;
V_2 += V_141 ;
V_139 += V_141 ;
V_140 += V_141 ;
V_105 -= V_141 ;
}
return V_140 ;
}
static int F_193 ( char * V_139 , char * V_2 , unsigned long V_105 )
{
struct V_12 * V_33 ;
int V_140 = 0 ;
while ( V_105 ) {
unsigned long V_98 , V_141 ;
V_98 = ( unsigned long ) V_2 & ~ V_48 ;
V_141 = V_7 - V_98 ;
if ( V_141 > V_105 )
V_141 = V_105 ;
V_33 = F_34 ( V_2 ) ;
if ( V_33 ) {
void * V_142 = F_191 ( V_33 ) ;
memcpy ( V_142 + V_98 , V_139 , V_141 ) ;
F_192 ( V_142 ) ;
}
V_2 += V_141 ;
V_139 += V_141 ;
V_140 += V_141 ;
V_105 -= V_141 ;
}
return V_140 ;
}
long F_194 ( char * V_139 , char * V_2 , unsigned long V_105 )
{
struct V_107 * V_35 ;
char * V_143 , * V_144 = V_139 ;
unsigned long V_145 = V_105 ;
unsigned long V_28 ;
if ( ( unsigned long ) V_2 + V_105 < V_105 )
V_105 = - ( unsigned long ) V_2 ;
F_195 ( & V_116 ) ;
for ( V_35 = V_109 ; V_105 && V_35 ; V_35 = V_35 -> V_9 ) {
V_143 = ( char * ) V_35 -> V_2 ;
if ( V_2 >= V_143 + V_35 -> V_40 - V_7 )
continue;
while ( V_2 < V_143 ) {
if ( V_105 == 0 )
goto V_146;
* V_139 = '\0' ;
V_139 ++ ;
V_2 ++ ;
V_105 -- ;
}
V_28 = V_143 + V_35 -> V_40 - V_7 - V_2 ;
if ( V_28 > V_105 )
V_28 = V_105 ;
if ( ! ( V_35 -> V_59 & V_117 ) )
F_190 ( V_139 , V_2 , V_28 ) ;
else
memset ( V_139 , 0 , V_28 ) ;
V_139 += V_28 ;
V_2 += V_28 ;
V_105 -= V_28 ;
}
V_146:
F_196 ( & V_116 ) ;
if ( V_139 == V_144 )
return 0 ;
if ( V_139 != V_144 + V_145 )
memset ( V_139 , 0 , V_145 - ( V_139 - V_144 ) ) ;
return V_145 ;
}
long F_197 ( char * V_139 , char * V_2 , unsigned long V_105 )
{
struct V_107 * V_35 ;
char * V_143 ;
unsigned long V_28 , V_145 ;
int V_140 = 0 ;
if ( ( unsigned long ) V_2 + V_105 < V_105 )
V_105 = - ( unsigned long ) V_2 ;
V_145 = V_105 ;
F_195 ( & V_116 ) ;
for ( V_35 = V_109 ; V_105 && V_35 ; V_35 = V_35 -> V_9 ) {
V_143 = ( char * ) V_35 -> V_2 ;
if ( V_2 >= V_143 + V_35 -> V_40 - V_7 )
continue;
while ( V_2 < V_143 ) {
if ( V_105 == 0 )
goto V_146;
V_139 ++ ;
V_2 ++ ;
V_105 -- ;
}
V_28 = V_143 + V_35 -> V_40 - V_7 - V_2 ;
if ( V_28 > V_105 )
V_28 = V_105 ;
if ( ! ( V_35 -> V_59 & V_117 ) ) {
F_193 ( V_139 , V_2 , V_28 ) ;
V_140 ++ ;
}
V_139 += V_28 ;
V_2 += V_28 ;
V_105 -= V_28 ;
}
V_146:
F_196 ( & V_116 ) ;
if ( ! V_140 )
return 0 ;
return V_145 ;
}
int F_198 ( struct V_147 * V_148 , void * V_2 ,
unsigned long V_149 )
{
struct V_107 * V_113 ;
unsigned long V_150 = V_148 -> V_151 ;
unsigned long V_152 = V_148 -> V_153 - V_148 -> V_151 ;
if ( ( V_7 - 1 ) & ( unsigned long ) V_2 )
return - V_154 ;
V_113 = F_162 ( V_2 ) ;
if ( ! V_113 )
return - V_154 ;
if ( ! ( V_113 -> V_59 & V_136 ) )
return - V_154 ;
if ( V_152 + ( V_149 << V_73 ) > V_113 -> V_40 - V_7 )
return - V_154 ;
V_2 += V_149 << V_73 ;
do {
struct V_12 * V_12 = F_34 ( V_2 ) ;
int V_19 ;
V_19 = F_199 ( V_148 , V_150 , V_12 ) ;
if ( V_19 )
return V_19 ;
V_150 += V_7 ;
V_2 += V_7 ;
V_152 -= V_7 ;
} while ( V_152 > 0 );
V_148 -> V_155 |= V_156 ;
return 0 ;
}
static int F_200 ( T_2 * V_4 , T_10 V_157 , unsigned long V_2 , void * V_158 )
{
T_2 * * * V_33 = V_158 ;
if ( V_33 ) {
* ( * V_33 ) = V_4 ;
( * V_33 ) ++ ;
}
return 0 ;
}
struct V_107 * F_201 ( T_8 V_40 , T_2 * * V_159 )
{
struct V_107 * V_113 ;
V_113 = F_161 ( V_40 , V_117 ,
F_158 ( 0 ) ) ;
if ( V_113 == NULL )
return NULL ;
if ( F_202 ( & V_6 , ( unsigned long ) V_113 -> V_2 ,
V_40 , F_200 , V_159 ? & V_159 : NULL ) ) {
F_203 ( V_113 ) ;
return NULL ;
}
return V_113 ;
}
void F_203 ( struct V_107 * V_113 )
{
struct V_107 * V_19 ;
V_19 = F_163 ( V_113 -> V_2 ) ;
F_16 ( V_19 != V_113 ) ;
F_65 ( V_113 ) ;
}
static struct V_26 * F_204 ( struct V_27 * V_28 )
{
return V_28 ? F_45 ( V_28 , struct V_26 , V_27 ) : NULL ;
}
static bool F_205 ( unsigned long V_3 ,
struct V_26 * * V_160 ,
struct V_26 * * V_161 )
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
* V_160 = V_30 ;
* V_161 = F_204 ( F_50 ( & ( * V_160 ) -> V_27 ) ) ;
} else {
* V_161 = V_30 ;
* V_160 = F_204 ( F_206 ( & ( * V_161 ) -> V_27 ) ) ;
}
return true ;
}
static unsigned long F_207 ( struct V_26 * * V_160 ,
struct V_26 * * V_161 ,
unsigned long V_41 )
{
const unsigned long V_162 = V_63 & ~ ( V_41 - 1 ) ;
unsigned long V_2 ;
if ( * V_160 )
V_2 = F_208 ( ( * V_160 ) -> va_start & ~ ( V_41 - 1 ) , V_162 ) ;
else
V_2 = V_162 ;
while ( * V_161 && ( * V_161 ) -> va_end > V_2 ) {
* V_160 = * V_161 ;
* V_161 = F_204 ( F_50 ( & ( * V_160 ) -> V_27 ) ) ;
}
return V_2 ;
}
struct V_107 * * F_209 ( const unsigned long * V_163 ,
const T_8 * V_164 , int V_165 ,
T_8 V_41 )
{
const unsigned long V_166 = F_58 ( V_62 , V_41 ) ;
const unsigned long V_162 = V_63 & ~ ( V_41 - 1 ) ;
struct V_26 * * V_167 , * V_37 , * V_9 ;
struct V_107 * * V_168 ;
int V_113 , V_169 , V_170 , V_171 ;
unsigned long V_172 , V_17 , V_3 , V_173 ;
bool V_46 = false ;
F_16 ( V_41 & ~ V_48 || ! F_53 ( V_41 ) ) ;
for ( V_170 = 0 , V_113 = 0 ; V_113 < V_165 ; V_113 ++ ) {
V_17 = V_163 [ V_113 ] ;
V_3 = V_17 + V_164 [ V_113 ] ;
F_16 ( ! F_210 ( V_163 [ V_113 ] , V_41 ) ) ;
F_16 ( ! F_210 ( V_164 [ V_113 ] , V_41 ) ) ;
if ( V_17 > V_163 [ V_170 ] )
V_170 = V_113 ;
for ( V_169 = 0 ; V_169 < V_165 ; V_169 ++ ) {
unsigned long V_174 = V_163 [ V_169 ] ;
unsigned long V_175 = V_174 + V_164 [ V_169 ] ;
if ( V_169 == V_113 )
continue;
F_16 ( V_174 >= V_17 && V_174 < V_3 ) ;
F_16 ( V_175 <= V_3 && V_175 > V_17 ) ;
}
}
V_173 = V_163 [ V_170 ] + V_164 [ V_170 ] ;
if ( V_162 - V_166 < V_173 ) {
F_4 ( true ) ;
return NULL ;
}
V_168 = F_211 ( V_165 , sizeof( V_168 [ 0 ] ) , V_106 ) ;
V_167 = F_211 ( V_165 , sizeof( V_167 [ 0 ] ) , V_106 ) ;
if ( ! V_167 || ! V_168 )
goto V_176;
for ( V_113 = 0 ; V_113 < V_165 ; V_113 ++ ) {
V_167 [ V_113 ] = F_143 ( sizeof( struct V_26 ) , V_106 ) ;
V_168 [ V_113 ] = F_143 ( sizeof( struct V_107 ) , V_106 ) ;
if ( ! V_167 [ V_113 ] || ! V_168 [ V_113 ] )
goto V_177;
}
V_50:
F_57 ( & V_51 ) ;
V_113 = V_171 = V_170 ;
V_17 = V_163 [ V_113 ] ;
V_3 = V_17 + V_164 [ V_113 ] ;
if ( ! F_205 ( V_64 , & V_9 , & V_37 ) ) {
V_172 = V_162 - V_173 ;
goto V_58;
}
V_172 = F_207 ( & V_9 , & V_37 , V_41 ) - V_3 ;
while ( true ) {
F_16 ( V_9 && V_9 -> va_end <= V_172 + V_3 ) ;
F_16 ( V_37 && V_37 -> va_end > V_172 + V_3 ) ;
if ( V_172 + V_173 < V_166 + V_173 ) {
F_61 ( & V_51 ) ;
if ( ! V_46 ) {
F_62 () ;
V_46 = true ;
goto V_50;
}
goto V_177;
}
if ( V_9 && V_9 -> va_start < V_172 + V_3 ) {
V_172 = F_207 ( & V_9 , & V_37 , V_41 ) - V_3 ;
V_171 = V_113 ;
continue;
}
if ( V_37 && V_37 -> va_end > V_172 + V_17 ) {
V_9 = V_37 ;
V_37 = F_204 ( F_50 ( & V_9 -> V_27 ) ) ;
V_172 = F_207 ( & V_9 , & V_37 , V_41 ) - V_3 ;
V_171 = V_113 ;
continue;
}
V_113 = ( V_113 + V_165 - 1 ) % V_165 ;
if ( V_113 == V_171 )
break;
V_17 = V_163 [ V_113 ] ;
V_3 = V_17 + V_164 [ V_113 ] ;
F_205 ( V_172 + V_3 , & V_9 , & V_37 ) ;
}
V_58:
for ( V_113 = 0 ; V_113 < V_165 ; V_113 ++ ) {
struct V_26 * V_30 = V_167 [ V_113 ] ;
V_30 -> va_start = V_172 + V_163 [ V_113 ] ;
V_30 -> va_end = V_30 -> va_start + V_164 [ V_113 ] ;
F_46 ( V_30 ) ;
}
V_64 = V_172 + V_163 [ V_170 ] ;
F_61 ( & V_51 ) ;
for ( V_113 = 0 ; V_113 < V_165 ; V_113 ++ )
F_152 ( V_168 [ V_113 ] , V_167 [ V_113 ] , V_134 ,
F_209 ) ;
F_65 ( V_167 ) ;
return V_168 ;
V_177:
for ( V_113 = 0 ; V_113 < V_165 ; V_113 ++ ) {
F_65 ( V_167 [ V_113 ] ) ;
F_65 ( V_168 [ V_113 ] ) ;
}
V_176:
F_65 ( V_167 ) ;
F_65 ( V_168 ) ;
return NULL ;
}
void F_212 ( struct V_107 * * V_168 , int V_165 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_165 ; V_97 ++ )
F_203 ( V_168 [ V_97 ] ) ;
F_65 ( V_168 ) ;
}
static void * F_213 ( struct V_178 * V_179 , T_11 * V_180 )
__acquires( &vmlist_lock
static void * F_214 ( struct V_178 * V_179 , void * V_33 , T_11 * V_180 )
{
struct V_107 * V_181 = V_33 ;
++ * V_180 ;
return V_181 -> V_9 ;
}
static void F_215 ( struct V_178 * V_179 , void * V_33 )
__releases( &vmlist_lock
static void F_216 ( struct V_178 * V_179 , struct V_107 * V_181 )
{
if ( V_182 ) {
unsigned int V_14 , * V_183 = V_179 -> V_184 ;
if ( ! V_183 )
return;
memset ( V_183 , 0 , V_185 * sizeof( unsigned int ) ) ;
for ( V_14 = 0 ; V_14 < V_181 -> V_122 ; V_14 ++ )
V_183 [ F_217 ( V_181 -> V_13 [ V_14 ] ) ] ++ ;
F_218 (nr, N_HIGH_MEMORY)
if ( V_183 [ V_14 ] )
F_219 ( V_179 , L_7 , V_14 , V_183 [ V_14 ] ) ;
}
}
static int F_220 ( struct V_178 * V_179 , void * V_33 )
{
struct V_107 * V_181 = V_33 ;
F_219 ( V_179 , L_8 ,
V_181 -> V_2 , V_181 -> V_2 + V_181 -> V_40 , V_181 -> V_40 ) ;
if ( V_181 -> V_114 )
F_219 ( V_179 , L_9 , V_181 -> V_114 ) ;
if ( V_181 -> V_122 )
F_219 ( V_179 , L_10 , V_181 -> V_122 ) ;
if ( V_181 -> V_186 )
F_219 ( V_179 , L_11 , ( unsigned long long ) V_181 -> V_186 ) ;
if ( V_181 -> V_59 & V_117 )
F_219 ( V_179 , L_12 ) ;
if ( V_181 -> V_59 & V_134 )
F_219 ( V_179 , L_13 ) ;
if ( V_181 -> V_59 & V_187 )
F_219 ( V_179 , L_14 ) ;
if ( V_181 -> V_59 & V_136 )
F_219 ( V_179 , L_15 ) ;
if ( V_181 -> V_59 & V_123 )
F_219 ( V_179 , L_16 ) ;
F_216 ( V_179 , V_181 ) ;
F_221 ( V_179 , '\n' ) ;
return 0 ;
}
static int F_222 ( struct V_188 * V_188 , struct V_189 * V_189 )
{
unsigned int * V_190 = NULL ;
int V_19 ;
if ( V_182 ) {
V_190 = F_223 ( V_185 * sizeof( unsigned int ) , V_106 ) ;
if ( V_190 == NULL )
return - V_15 ;
}
V_19 = F_224 ( V_189 , & V_191 ) ;
if ( ! V_19 ) {
struct V_178 * V_179 = V_189 -> V_192 ;
V_179 -> V_184 = V_190 ;
} else
F_65 ( V_190 ) ;
return V_19 ;
}
static int T_7 F_225 ( void )
{
F_226 ( L_17 , V_193 , NULL , & V_194 ) ;
return 0 ;
}
