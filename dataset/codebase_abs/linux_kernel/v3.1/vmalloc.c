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
static void F_65 ( struct V_26 * V_30 )
{
F_16 ( F_66 ( & V_30 -> V_27 ) ) ;
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
F_67 ( & V_30 -> V_27 , & V_29 ) ;
F_68 ( & V_30 -> V_27 ) ;
F_69 ( & V_30 -> V_38 ) ;
if ( V_30 -> va_end > V_62 && V_30 -> va_end <= V_63 )
V_64 = F_70 ( V_64 , V_30 -> va_end ) ;
F_71 ( V_30 , V_65 ) ;
}
static void F_72 ( struct V_26 * V_30 )
{
F_57 ( & V_51 ) ;
F_65 ( V_30 ) ;
F_60 ( & V_51 ) ;
}
static void F_73 ( struct V_26 * V_30 )
{
F_15 ( V_30 -> va_start , V_30 -> va_end ) ;
}
static void F_74 ( unsigned long V_17 , unsigned long V_3 )
{
#ifdef F_75
F_15 ( V_17 , V_3 ) ;
F_76 ( V_17 , V_3 ) ;
#endif
}
static unsigned long F_77 ( void )
{
unsigned int log ;
log = F_78 ( F_79 () ) ;
return log * ( 32UL * 1024 * 1024 / V_7 ) ;
}
void F_80 ( void )
{
F_81 ( & V_66 , F_77 () + 1 ) ;
}
static void F_82 ( unsigned long * V_17 , unsigned long * V_3 ,
int V_67 , int V_68 )
{
static F_83 ( V_69 ) ;
F_84 ( V_70 ) ;
struct V_26 * V_30 ;
struct V_26 * V_71 ;
int V_14 = 0 ;
if ( ! V_67 && ! V_68 ) {
if ( ! F_85 ( & V_69 ) )
return;
} else
F_57 ( & V_69 ) ;
if ( V_67 )
F_86 () ;
F_87 () ;
F_88 (va, &vmap_area_list, list) {
if ( V_30 -> V_59 & V_72 ) {
if ( V_30 -> va_start < * V_17 )
* V_17 = V_30 -> va_start ;
if ( V_30 -> va_end > * V_3 )
* V_3 = V_30 -> va_end ;
V_14 += ( V_30 -> va_end - V_30 -> va_start ) >> V_73 ;
F_89 ( & V_30 -> V_74 , & V_70 ) ;
V_30 -> V_59 |= V_75 ;
V_30 -> V_59 &= ~ V_72 ;
}
}
F_90 () ;
if ( V_14 )
F_91 ( V_14 , & V_66 ) ;
if ( V_14 || V_68 )
F_76 ( * V_17 , * V_3 ) ;
if ( V_14 ) {
F_57 ( & V_51 ) ;
F_92 (va, n_va, &valist, purge_list)
F_65 ( V_30 ) ;
F_60 ( & V_51 ) ;
}
F_60 ( & V_69 ) ;
}
static void F_93 ( void )
{
unsigned long V_17 = V_76 , V_3 = 0 ;
F_82 ( & V_17 , & V_3 , 0 , 0 ) ;
}
static void F_61 ( void )
{
unsigned long V_17 = V_76 , V_3 = 0 ;
F_82 ( & V_17 , & V_3 , 1 , 0 ) ;
}
static void F_94 ( struct V_26 * V_30 )
{
V_30 -> V_59 |= V_72 ;
F_95 ( ( V_30 -> va_end - V_30 -> va_start ) >> V_73 , & V_66 ) ;
if ( F_55 ( F_96 ( & V_66 ) > F_77 () ) )
F_93 () ;
}
static void F_97 ( struct V_26 * V_30 )
{
F_73 ( V_30 ) ;
F_94 ( V_30 ) ;
}
static void F_98 ( struct V_26 * V_30 )
{
F_99 ( V_30 -> va_start , V_30 -> va_end ) ;
F_97 ( V_30 ) ;
}
static struct V_26 * F_100 ( unsigned long V_2 )
{
struct V_26 * V_30 ;
F_57 ( & V_51 ) ;
V_30 = F_44 ( V_2 ) ;
F_60 ( & V_51 ) ;
return V_30 ;
}
static void F_101 ( unsigned long V_2 )
{
struct V_26 * V_30 ;
V_30 = F_100 ( V_2 ) ;
F_16 ( ! V_30 ) ;
F_98 ( V_30 ) ;
}
static unsigned long F_102 ( unsigned long V_2 )
{
V_2 -= V_62 & ~ ( V_77 - 1 ) ;
V_2 /= V_77 ;
return V_2 ;
}
static struct V_78 * F_103 ( T_6 V_45 )
{
struct V_79 * V_80 ;
struct V_78 * V_81 ;
struct V_26 * V_30 ;
unsigned long V_82 ;
int V_44 , V_18 ;
V_44 = F_104 () ;
V_81 = F_54 ( sizeof( struct V_78 ) ,
V_45 & V_49 , V_44 ) ;
if ( F_55 ( ! V_81 ) )
return F_56 ( - V_15 ) ;
V_30 = F_52 ( V_77 , V_77 ,
V_62 , V_63 ,
V_44 , V_45 ) ;
if ( F_105 ( V_30 ) ) {
F_64 ( V_81 ) ;
return F_106 ( V_30 ) ;
}
V_18 = F_107 ( V_45 ) ;
if ( F_55 ( V_18 ) ) {
F_64 ( V_81 ) ;
F_72 ( V_30 ) ;
return F_56 ( V_18 ) ;
}
F_108 ( & V_81 -> V_83 ) ;
V_81 -> V_30 = V_30 ;
V_81 -> free = V_84 ;
V_81 -> V_85 = 0 ;
F_109 ( V_81 -> V_86 , V_84 ) ;
F_109 ( V_81 -> V_87 , V_84 ) ;
F_110 ( & V_81 -> V_88 ) ;
V_82 = F_102 ( V_30 -> va_start ) ;
F_57 ( & V_89 ) ;
V_18 = F_111 ( & V_90 , V_82 , V_81 ) ;
F_60 ( & V_89 ) ;
F_16 ( V_18 ) ;
F_112 () ;
V_80 = & F_113 ( V_79 ) ;
V_81 -> V_80 = V_80 ;
F_57 ( & V_80 -> V_83 ) ;
F_51 ( & V_81 -> V_88 , & V_80 -> free ) ;
F_60 ( & V_80 -> V_83 ) ;
F_114 ( V_79 ) ;
return V_81 ;
}
static void F_115 ( struct V_78 * V_81 )
{
struct V_78 * V_35 ;
unsigned long V_82 ;
V_82 = F_102 ( V_81 -> V_30 -> va_start ) ;
F_57 ( & V_89 ) ;
V_35 = F_116 ( & V_90 , V_82 ) ;
F_60 ( & V_89 ) ;
F_16 ( V_35 != V_81 ) ;
F_94 ( V_81 -> V_30 ) ;
F_71 ( V_81 , V_65 ) ;
}
static void F_117 ( int V_91 )
{
F_84 ( V_92 ) ;
struct V_78 * V_81 ;
struct V_78 * V_93 ;
struct V_79 * V_80 = & F_118 ( V_79 , V_91 ) ;
F_87 () ;
F_88 (vb, &vbq->free, free_list) {
if ( ! ( V_81 -> free + V_81 -> V_85 == V_84 && V_81 -> V_85 != V_84 ) )
continue;
F_57 ( & V_81 -> V_83 ) ;
if ( V_81 -> free + V_81 -> V_85 == V_84 && V_81 -> V_85 != V_84 ) {
V_81 -> free = 0 ;
V_81 -> V_85 = V_84 ;
F_119 ( V_81 -> V_86 , V_84 ) ;
F_119 ( V_81 -> V_87 , V_84 ) ;
F_57 ( & V_80 -> V_83 ) ;
F_69 ( & V_81 -> V_88 ) ;
F_60 ( & V_80 -> V_83 ) ;
F_60 ( & V_81 -> V_83 ) ;
F_89 ( & V_81 -> V_92 , & V_92 ) ;
} else
F_60 ( & V_81 -> V_83 ) ;
}
F_90 () ;
F_92 (vb, n_vb, &purge, purge) {
F_120 ( & V_81 -> V_92 ) ;
F_115 ( V_81 ) ;
}
}
static void F_121 ( void )
{
F_117 ( F_122 () ) ;
}
static void F_86 ( void )
{
int V_91 ;
F_123 (cpu)
F_117 ( V_91 ) ;
}
static void * F_124 ( unsigned long V_40 , T_6 V_45 )
{
struct V_79 * V_80 ;
struct V_78 * V_81 ;
unsigned long V_2 = 0 ;
unsigned int V_94 ;
int V_92 = 0 ;
F_16 ( V_40 & ~ V_48 ) ;
F_16 ( V_40 > V_7 * V_95 ) ;
V_94 = F_125 ( V_40 ) ;
V_96:
F_87 () ;
V_80 = & F_113 ( V_79 ) ;
F_88 (vb, &vbq->free, free_list) {
int V_97 ;
F_57 ( & V_81 -> V_83 ) ;
if ( V_81 -> free < 1UL << V_94 )
goto V_9;
V_97 = F_126 ( V_81 -> V_86 ,
V_84 , V_94 ) ;
if ( V_97 < 0 ) {
if ( V_81 -> free + V_81 -> V_85 == V_84 ) {
F_16 ( V_81 -> V_85 != V_84 ) ;
V_92 = 1 ;
}
goto V_9;
}
V_2 = V_81 -> V_30 -> va_start + ( V_97 << V_73 ) ;
F_16 ( F_102 ( V_2 ) !=
F_102 ( V_81 -> V_30 -> va_start ) ) ;
V_81 -> free -= 1UL << V_94 ;
if ( V_81 -> free == 0 ) {
F_57 ( & V_80 -> V_83 ) ;
F_69 ( & V_81 -> V_88 ) ;
F_60 ( & V_80 -> V_83 ) ;
}
F_60 ( & V_81 -> V_83 ) ;
break;
V_9:
F_60 ( & V_81 -> V_83 ) ;
}
if ( V_92 )
F_121 () ;
F_114 ( V_79 ) ;
F_90 () ;
if ( ! V_2 ) {
V_81 = F_103 ( V_45 ) ;
if ( F_105 ( V_81 ) )
return V_81 ;
goto V_96;
}
return ( void * ) V_2 ;
}
static void F_127 ( const void * V_2 , unsigned long V_40 )
{
unsigned long V_98 ;
unsigned long V_82 ;
unsigned int V_94 ;
struct V_78 * V_81 ;
F_16 ( V_40 & ~ V_48 ) ;
F_16 ( V_40 > V_7 * V_95 ) ;
F_99 ( ( unsigned long ) V_2 , ( unsigned long ) V_2 + V_40 ) ;
V_94 = F_125 ( V_40 ) ;
V_98 = ( unsigned long ) V_2 & ( V_77 - 1 ) ;
V_82 = F_102 ( ( unsigned long ) V_2 ) ;
F_87 () ;
V_81 = F_128 ( & V_90 , V_82 ) ;
F_90 () ;
F_16 ( ! V_81 ) ;
F_15 ( ( unsigned long ) V_2 , ( unsigned long ) V_2 + V_40 ) ;
F_57 ( & V_81 -> V_83 ) ;
F_16 ( F_129 ( V_81 -> V_87 , V_98 >> V_73 , V_94 ) ) ;
V_81 -> V_85 += 1UL << V_94 ;
if ( V_81 -> V_85 == V_84 ) {
F_16 ( V_81 -> free ) ;
F_60 ( & V_81 -> V_83 ) ;
F_115 ( V_81 ) ;
} else
F_60 ( & V_81 -> V_83 ) ;
}
void F_130 ( void )
{
unsigned long V_17 = V_76 , V_3 = 0 ;
int V_91 ;
int V_99 = 0 ;
if ( F_55 ( ! V_100 ) )
return;
F_123 (cpu) {
struct V_79 * V_80 = & F_118 ( V_79 , V_91 ) ;
struct V_78 * V_81 ;
F_87 () ;
F_88 (vb, &vbq->free, free_list) {
int V_97 ;
F_57 ( & V_81 -> V_83 ) ;
V_97 = F_131 ( V_81 -> V_87 , V_84 ) ;
while ( V_97 < V_84 ) {
unsigned long V_101 , V_102 ;
int V_103 ;
V_103 = F_132 ( V_81 -> V_87 ,
V_84 , V_97 ) ;
V_101 = V_81 -> V_30 -> va_start + ( V_97 << V_73 ) ;
V_102 = V_81 -> V_30 -> va_start + ( V_103 << V_73 ) ;
V_99 = 1 ;
if ( V_101 < V_17 )
V_17 = V_101 ;
if ( V_102 > V_3 )
V_3 = V_102 ;
V_97 = V_103 ;
V_97 = F_133 ( V_81 -> V_87 ,
V_84 , V_97 ) ;
}
F_60 ( & V_81 -> V_83 ) ;
}
F_90 () ;
}
F_82 ( & V_17 , & V_3 , 1 , V_99 ) ;
}
void F_134 ( const void * V_104 , unsigned int V_105 )
{
unsigned long V_40 = V_105 << V_73 ;
unsigned long V_2 = ( unsigned long ) V_104 ;
F_16 ( ! V_2 ) ;
F_16 ( V_2 < V_62 ) ;
F_16 ( V_2 > V_63 ) ;
F_16 ( V_2 & ( V_7 - 1 ) ) ;
F_135 ( V_104 , V_40 ) ;
F_74 ( V_2 , V_2 + V_40 ) ;
if ( F_136 ( V_105 <= V_95 ) )
F_127 ( V_104 , V_40 ) ;
else
F_101 ( V_2 ) ;
}
void * F_137 ( struct V_12 * * V_13 , unsigned int V_105 , int V_44 , T_5 V_11 )
{
unsigned long V_40 = V_105 << V_73 ;
unsigned long V_2 ;
void * V_104 ;
if ( F_136 ( V_105 <= V_95 ) ) {
V_104 = F_124 ( V_40 , V_106 ) ;
if ( F_105 ( V_104 ) )
return NULL ;
V_2 = ( unsigned long ) V_104 ;
} else {
struct V_26 * V_30 ;
V_30 = F_52 ( V_40 , V_7 ,
V_62 , V_63 , V_44 , V_106 ) ;
if ( F_105 ( V_30 ) )
return NULL ;
V_2 = V_30 -> va_start ;
V_104 = ( void * ) V_2 ;
}
if ( F_29 ( V_2 , V_2 + V_40 , V_11 , V_13 ) < 0 ) {
F_134 ( V_104 , V_105 ) ;
return NULL ;
}
return V_104 ;
}
void T_7 F_138 ( struct V_107 * V_108 , T_8 V_41 )
{
static T_8 T_9 V_109 ;
unsigned long V_2 ;
V_2 = F_58 ( V_62 + T_9 , V_41 ) ;
T_9 = F_139 ( V_2 + V_108 -> V_40 ) - V_62 ;
V_108 -> V_2 = ( void * ) V_2 ;
V_108 -> V_9 = V_110 ;
V_110 = V_108 ;
}
void T_7 F_140 ( void )
{
struct V_26 * V_30 ;
struct V_107 * V_35 ;
int V_97 ;
F_123 (i) {
struct V_79 * V_80 ;
V_80 = & F_118 ( V_79 , V_97 ) ;
F_108 ( & V_80 -> V_83 ) ;
F_110 ( & V_80 -> free ) ;
}
for ( V_35 = V_110 ; V_35 ; V_35 = V_35 -> V_9 ) {
V_30 = F_141 ( sizeof( struct V_26 ) , V_111 ) ;
V_30 -> V_59 = V_35 -> V_59 | V_112 ;
V_30 -> va_start = ( unsigned long ) V_35 -> V_2 ;
V_30 -> va_end = V_30 -> va_start + V_35 -> V_40 ;
F_46 ( V_30 ) ;
}
V_64 = V_63 ;
V_100 = true ;
}
int F_142 ( unsigned long V_2 , unsigned long V_40 ,
T_5 V_11 , struct V_12 * * V_13 )
{
return F_28 ( V_2 , V_2 + V_40 , V_11 , V_13 ) ;
}
void F_143 ( unsigned long V_2 , unsigned long V_40 )
{
F_15 ( V_2 , V_2 + V_40 ) ;
}
void F_144 ( unsigned long V_2 , unsigned long V_40 )
{
unsigned long V_3 = V_2 + V_40 ;
F_99 ( V_2 , V_3 ) ;
F_15 ( V_2 , V_3 ) ;
F_76 ( V_2 , V_3 ) ;
}
int F_145 ( struct V_107 * V_113 , T_5 V_11 , struct V_12 * * * V_13 )
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
static void F_146 ( struct V_107 * V_108 , struct V_26 * V_30 ,
unsigned long V_59 , void * V_114 )
{
struct V_107 * V_35 , * * V_33 ;
V_108 -> V_59 = V_59 ;
V_108 -> V_2 = ( void * ) V_30 -> va_start ;
V_108 -> V_40 = V_30 -> va_end - V_30 -> va_start ;
V_108 -> V_114 = V_114 ;
V_30 -> V_115 = V_108 ;
V_30 -> V_59 |= V_112 ;
F_147 ( & V_116 ) ;
for ( V_33 = & V_110 ; ( V_35 = * V_33 ) != NULL ; V_33 = & V_35 -> V_9 ) {
if ( V_35 -> V_2 >= V_108 -> V_2 )
break;
}
V_108 -> V_9 = * V_33 ;
* V_33 = V_108 ;
F_148 ( & V_116 ) ;
}
static struct V_107 * F_149 ( unsigned long V_40 ,
unsigned long V_41 , unsigned long V_59 , unsigned long V_17 ,
unsigned long V_3 , int V_44 , T_6 V_45 , void * V_114 )
{
static struct V_26 * V_30 ;
struct V_107 * V_113 ;
F_16 ( F_150 () ) ;
if ( V_59 & V_117 ) {
int V_118 = F_78 ( V_40 ) ;
if ( V_118 > V_119 )
V_118 = V_119 ;
else if ( V_118 < V_73 )
V_118 = V_73 ;
V_41 = 1ul << V_118 ;
}
V_40 = F_151 ( V_40 ) ;
if ( F_55 ( ! V_40 ) )
return NULL ;
V_113 = F_152 ( sizeof( * V_113 ) , V_45 & V_49 , V_44 ) ;
if ( F_55 ( ! V_113 ) )
return NULL ;
V_40 += V_7 ;
V_30 = F_52 ( V_40 , V_41 , V_17 , V_3 , V_44 , V_45 ) ;
if ( F_105 ( V_30 ) ) {
F_64 ( V_113 ) ;
return NULL ;
}
F_146 ( V_113 , V_30 , V_59 , V_114 ) ;
return V_113 ;
}
struct V_107 * F_153 ( unsigned long V_40 , unsigned long V_59 ,
unsigned long V_17 , unsigned long V_3 )
{
return F_149 ( V_40 , 1 , V_59 , V_17 , V_3 , - 1 , V_106 ,
F_154 ( 0 ) ) ;
}
struct V_107 * F_155 ( unsigned long V_40 , unsigned long V_59 ,
unsigned long V_17 , unsigned long V_3 ,
void * V_114 )
{
return F_149 ( V_40 , 1 , V_59 , V_17 , V_3 , - 1 , V_106 ,
V_114 ) ;
}
struct V_107 * F_156 ( unsigned long V_40 , unsigned long V_59 )
{
return F_149 ( V_40 , 1 , V_59 , V_62 , V_63 ,
- 1 , V_106 , F_154 ( 0 ) ) ;
}
struct V_107 * F_157 ( unsigned long V_40 , unsigned long V_59 ,
void * V_114 )
{
return F_149 ( V_40 , 1 , V_59 , V_62 , V_63 ,
- 1 , V_106 , V_114 ) ;
}
static struct V_107 * F_158 ( const void * V_2 )
{
struct V_26 * V_30 ;
V_30 = F_100 ( ( unsigned long ) V_2 ) ;
if ( V_30 && V_30 -> V_59 & V_112 )
return V_30 -> V_115 ;
return NULL ;
}
struct V_107 * F_159 ( const void * V_2 )
{
struct V_26 * V_30 ;
V_30 = F_100 ( ( unsigned long ) V_2 ) ;
if ( V_30 && V_30 -> V_59 & V_112 ) {
struct V_107 * V_108 = V_30 -> V_115 ;
struct V_107 * V_35 , * * V_33 ;
F_147 ( & V_116 ) ;
for ( V_33 = & V_110 ; ( V_35 = * V_33 ) != V_108 ; V_33 = & V_35 -> V_9 )
;
* V_33 = V_35 -> V_9 ;
F_148 ( & V_116 ) ;
F_74 ( V_30 -> va_start , V_30 -> va_end ) ;
F_98 ( V_30 ) ;
V_108 -> V_40 -= V_7 ;
return V_108 ;
}
return NULL ;
}
static void F_160 ( const void * V_2 , int V_120 )
{
struct V_107 * V_113 ;
if ( ! V_2 )
return;
if ( ( V_7 - 1 ) & ( unsigned long ) V_2 ) {
F_161 ( 1 , V_121 L_3 , V_2 ) ;
return;
}
V_113 = F_159 ( V_2 ) ;
if ( F_55 ( ! V_113 ) ) {
F_161 ( 1 , V_121 L_4 ,
V_2 ) ;
return;
}
F_135 ( V_2 , V_113 -> V_40 ) ;
F_162 ( V_2 , V_113 -> V_40 ) ;
if ( V_120 ) {
int V_97 ;
for ( V_97 = 0 ; V_97 < V_113 -> V_122 ; V_97 ++ ) {
struct V_12 * V_12 = V_113 -> V_13 [ V_97 ] ;
F_16 ( ! V_12 ) ;
F_163 ( V_12 ) ;
}
if ( V_113 -> V_59 & V_123 )
F_164 ( V_113 -> V_13 ) ;
else
F_64 ( V_113 -> V_13 ) ;
}
F_64 ( V_113 ) ;
return;
}
void F_164 ( const void * V_2 )
{
F_16 ( F_150 () ) ;
F_165 ( V_2 ) ;
F_160 ( V_2 , 1 ) ;
}
void F_166 ( const void * V_2 )
{
F_16 ( F_150 () ) ;
F_167 () ;
F_160 ( V_2 , 0 ) ;
}
void * F_168 ( struct V_12 * * V_13 , unsigned int V_105 ,
unsigned long V_59 , T_5 V_11 )
{
struct V_107 * V_113 ;
F_167 () ;
if ( V_105 > V_124 )
return NULL ;
V_113 = F_157 ( ( V_105 << V_73 ) , V_59 ,
F_154 ( 0 ) ) ;
if ( ! V_113 )
return NULL ;
if ( F_145 ( V_113 , V_11 , & V_13 ) ) {
F_166 ( V_113 -> V_2 ) ;
return NULL ;
}
return V_113 -> V_2 ;
}
static void * F_169 ( struct V_107 * V_113 , T_6 V_45 ,
T_5 V_11 , int V_44 , void * V_114 )
{
const int V_94 = 0 ;
struct V_12 * * V_13 ;
unsigned int V_122 , V_125 , V_97 ;
T_6 V_126 = ( V_45 & V_49 ) | V_127 ;
V_122 = ( V_113 -> V_40 - V_7 ) >> V_73 ;
V_125 = ( V_122 * sizeof( struct V_12 * ) ) ;
V_113 -> V_122 = V_122 ;
if ( V_125 > V_7 ) {
V_13 = F_170 ( V_125 , 1 , V_126 | V_128 ,
V_129 , V_44 , V_114 ) ;
V_113 -> V_59 |= V_123 ;
} else {
V_13 = F_54 ( V_125 , V_126 , V_44 ) ;
}
V_113 -> V_13 = V_13 ;
V_113 -> V_114 = V_114 ;
if ( ! V_113 -> V_13 ) {
F_159 ( V_113 -> V_2 ) ;
F_64 ( V_113 ) ;
return NULL ;
}
for ( V_97 = 0 ; V_97 < V_113 -> V_122 ; V_97 ++ ) {
struct V_12 * V_12 ;
T_6 V_130 = V_45 | V_131 ;
if ( V_44 < 0 )
V_12 = F_171 ( V_130 ) ;
else
V_12 = F_172 ( V_44 , V_130 , V_94 ) ;
if ( F_55 ( ! V_12 ) ) {
V_113 -> V_122 = V_97 ;
goto V_132;
}
V_113 -> V_13 [ V_97 ] = V_12 ;
}
if ( F_145 ( V_113 , V_11 , & V_13 ) )
goto V_132;
return V_113 -> V_2 ;
V_132:
F_173 ( V_45 , V_94 , L_5
L_6 ,
( V_113 -> V_122 * V_7 ) , V_113 -> V_40 ) ;
F_164 ( V_113 -> V_2 ) ;
return NULL ;
}
void * F_174 ( unsigned long V_40 , unsigned long V_41 ,
unsigned long V_17 , unsigned long V_3 , T_6 V_45 ,
T_5 V_11 , int V_44 , void * V_114 )
{
struct V_107 * V_113 ;
void * V_2 ;
unsigned long V_133 = V_40 ;
V_40 = F_151 ( V_40 ) ;
if ( ! V_40 || ( V_40 >> V_73 ) > V_124 )
return NULL ;
V_113 = F_149 ( V_40 , V_41 , V_134 , V_17 , V_3 , V_44 ,
V_45 , V_114 ) ;
if ( ! V_113 )
return NULL ;
V_2 = F_169 ( V_113 , V_45 , V_11 , V_44 , V_114 ) ;
F_175 ( V_2 , V_133 , 3 , V_45 ) ;
return V_2 ;
}
static void * F_170 ( unsigned long V_40 , unsigned long V_41 ,
T_6 V_45 , T_5 V_11 ,
int V_44 , void * V_114 )
{
return F_174 ( V_40 , V_41 , V_62 , V_63 ,
V_45 , V_11 , V_44 , V_114 ) ;
}
void * F_176 ( unsigned long V_40 , T_6 V_45 , T_5 V_11 )
{
return F_170 ( V_40 , 1 , V_45 , V_11 , - 1 ,
F_154 ( 0 ) ) ;
}
static inline void * F_177 ( unsigned long V_40 ,
int V_44 , T_6 V_59 )
{
return F_170 ( V_40 , 1 , V_59 , V_129 ,
V_44 , F_154 ( 0 ) ) ;
}
void * F_178 ( unsigned long V_40 )
{
return F_177 ( V_40 , - 1 , V_106 | V_128 ) ;
}
void * F_179 ( unsigned long V_40 )
{
return F_177 ( V_40 , - 1 ,
V_106 | V_128 | V_127 ) ;
}
void * F_180 ( unsigned long V_40 )
{
struct V_107 * V_113 ;
void * V_19 ;
V_19 = F_170 ( V_40 , V_135 ,
V_106 | V_128 | V_127 ,
V_129 , - 1 , F_154 ( 0 ) ) ;
if ( V_19 ) {
V_113 = F_158 ( V_19 ) ;
V_113 -> V_59 |= V_136 ;
}
return V_19 ;
}
void * F_181 ( unsigned long V_40 , int V_44 )
{
return F_170 ( V_40 , 1 , V_106 | V_128 , V_129 ,
V_44 , F_154 ( 0 ) ) ;
}
void * F_182 ( unsigned long V_40 , int V_44 )
{
return F_177 ( V_40 , V_44 ,
V_106 | V_128 | V_127 ) ;
}
void * F_183 ( unsigned long V_40 )
{
return F_170 ( V_40 , 1 , V_106 | V_128 , V_137 ,
- 1 , F_154 ( 0 ) ) ;
}
void * F_184 ( unsigned long V_40 )
{
return F_170 ( V_40 , 1 , V_138 , V_129 ,
- 1 , F_154 ( 0 ) ) ;
}
void * F_185 ( unsigned long V_40 )
{
struct V_107 * V_113 ;
void * V_19 ;
V_19 = F_170 ( V_40 , 1 , V_138 | V_127 , V_129 ,
- 1 , F_154 ( 0 ) ) ;
if ( V_19 ) {
V_113 = F_158 ( V_19 ) ;
V_113 -> V_59 |= V_136 ;
}
return V_19 ;
}
static int F_186 ( char * V_139 , char * V_2 , unsigned long V_105 )
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
void * V_142 = F_187 ( V_33 , V_143 ) ;
memcpy ( V_139 , V_142 + V_98 , V_141 ) ;
F_188 ( V_142 , V_143 ) ;
} else
memset ( V_139 , 0 , V_141 ) ;
V_2 += V_141 ;
V_139 += V_141 ;
V_140 += V_141 ;
V_105 -= V_141 ;
}
return V_140 ;
}
static int F_189 ( char * V_139 , char * V_2 , unsigned long V_105 )
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
void * V_142 = F_187 ( V_33 , V_143 ) ;
memcpy ( V_142 + V_98 , V_139 , V_141 ) ;
F_188 ( V_142 , V_143 ) ;
}
V_2 += V_141 ;
V_139 += V_141 ;
V_140 += V_141 ;
V_105 -= V_141 ;
}
return V_140 ;
}
long F_190 ( char * V_139 , char * V_2 , unsigned long V_105 )
{
struct V_107 * V_35 ;
char * V_144 , * V_145 = V_139 ;
unsigned long V_146 = V_105 ;
unsigned long V_28 ;
if ( ( unsigned long ) V_2 + V_105 < V_105 )
V_105 = - ( unsigned long ) V_2 ;
F_191 ( & V_116 ) ;
for ( V_35 = V_110 ; V_105 && V_35 ; V_35 = V_35 -> V_9 ) {
V_144 = ( char * ) V_35 -> V_2 ;
if ( V_2 >= V_144 + V_35 -> V_40 - V_7 )
continue;
while ( V_2 < V_144 ) {
if ( V_105 == 0 )
goto V_147;
* V_139 = '\0' ;
V_139 ++ ;
V_2 ++ ;
V_105 -- ;
}
V_28 = V_144 + V_35 -> V_40 - V_7 - V_2 ;
if ( V_28 > V_105 )
V_28 = V_105 ;
if ( ! ( V_35 -> V_59 & V_117 ) )
F_186 ( V_139 , V_2 , V_28 ) ;
else
memset ( V_139 , 0 , V_28 ) ;
V_139 += V_28 ;
V_2 += V_28 ;
V_105 -= V_28 ;
}
V_147:
F_192 ( & V_116 ) ;
if ( V_139 == V_145 )
return 0 ;
if ( V_139 != V_145 + V_146 )
memset ( V_139 , 0 , V_146 - ( V_139 - V_145 ) ) ;
return V_146 ;
}
long F_193 ( char * V_139 , char * V_2 , unsigned long V_105 )
{
struct V_107 * V_35 ;
char * V_144 ;
unsigned long V_28 , V_146 ;
int V_140 = 0 ;
if ( ( unsigned long ) V_2 + V_105 < V_105 )
V_105 = - ( unsigned long ) V_2 ;
V_146 = V_105 ;
F_191 ( & V_116 ) ;
for ( V_35 = V_110 ; V_105 && V_35 ; V_35 = V_35 -> V_9 ) {
V_144 = ( char * ) V_35 -> V_2 ;
if ( V_2 >= V_144 + V_35 -> V_40 - V_7 )
continue;
while ( V_2 < V_144 ) {
if ( V_105 == 0 )
goto V_147;
V_139 ++ ;
V_2 ++ ;
V_105 -- ;
}
V_28 = V_144 + V_35 -> V_40 - V_7 - V_2 ;
if ( V_28 > V_105 )
V_28 = V_105 ;
if ( ! ( V_35 -> V_59 & V_117 ) ) {
F_189 ( V_139 , V_2 , V_28 ) ;
V_140 ++ ;
}
V_139 += V_28 ;
V_2 += V_28 ;
V_105 -= V_28 ;
}
V_147:
F_192 ( & V_116 ) ;
if ( ! V_140 )
return 0 ;
return V_146 ;
}
int F_194 ( struct V_148 * V_149 , void * V_2 ,
unsigned long V_150 )
{
struct V_107 * V_113 ;
unsigned long V_151 = V_149 -> V_152 ;
unsigned long V_153 = V_149 -> V_154 - V_149 -> V_152 ;
if ( ( V_7 - 1 ) & ( unsigned long ) V_2 )
return - V_155 ;
V_113 = F_158 ( V_2 ) ;
if ( ! V_113 )
return - V_155 ;
if ( ! ( V_113 -> V_59 & V_136 ) )
return - V_155 ;
if ( V_153 + ( V_150 << V_73 ) > V_113 -> V_40 - V_7 )
return - V_155 ;
V_2 += V_150 << V_73 ;
do {
struct V_12 * V_12 = F_34 ( V_2 ) ;
int V_19 ;
V_19 = F_195 ( V_149 , V_151 , V_12 ) ;
if ( V_19 )
return V_19 ;
V_151 += V_7 ;
V_2 += V_7 ;
V_153 -= V_7 ;
} while ( V_153 > 0 );
V_149 -> V_156 |= V_157 ;
return 0 ;
}
static int F_196 ( T_2 * V_4 , T_10 V_158 , unsigned long V_2 , void * V_159 )
{
return 0 ;
}
struct V_107 * F_197 ( T_8 V_40 )
{
struct V_107 * V_113 ;
V_113 = F_157 ( V_40 , V_117 ,
F_154 ( 0 ) ) ;
if ( V_113 == NULL )
return NULL ;
if ( F_198 ( & V_6 , ( unsigned long ) V_113 -> V_2 ,
V_113 -> V_40 , F_196 , NULL ) ) {
F_199 ( V_113 ) ;
return NULL ;
}
F_200 () ;
return V_113 ;
}
void F_199 ( struct V_107 * V_113 )
{
struct V_107 * V_19 ;
V_19 = F_159 ( V_113 -> V_2 ) ;
F_16 ( V_19 != V_113 ) ;
F_64 ( V_113 ) ;
}
static struct V_26 * F_201 ( struct V_27 * V_28 )
{
return V_28 ? F_45 ( V_28 , struct V_26 , V_27 ) : NULL ;
}
static bool F_202 ( unsigned long V_3 ,
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
* V_161 = F_201 ( F_50 ( & ( * V_160 ) -> V_27 ) ) ;
} else {
* V_161 = V_30 ;
* V_160 = F_201 ( F_59 ( & ( * V_161 ) -> V_27 ) ) ;
}
return true ;
}
static unsigned long F_203 ( struct V_26 * * V_160 ,
struct V_26 * * V_161 ,
unsigned long V_41 )
{
const unsigned long V_162 = V_63 & ~ ( V_41 - 1 ) ;
unsigned long V_2 ;
if ( * V_160 )
V_2 = F_204 ( ( * V_160 ) -> va_start & ~ ( V_41 - 1 ) , V_162 ) ;
else
V_2 = V_162 ;
while ( * V_161 && ( * V_161 ) -> va_end > V_2 ) {
* V_160 = * V_161 ;
* V_161 = F_201 ( F_50 ( & ( * V_160 ) -> V_27 ) ) ;
}
return V_2 ;
}
struct V_107 * * F_205 ( const unsigned long * V_163 ,
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
F_16 ( ! F_206 ( V_163 [ V_113 ] , V_41 ) ) ;
F_16 ( ! F_206 ( V_164 [ V_113 ] , V_41 ) ) ;
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
V_168 = F_141 ( sizeof( V_168 [ 0 ] ) * V_165 , V_106 ) ;
V_167 = F_141 ( sizeof( V_167 [ 0 ] ) * V_165 , V_106 ) ;
if ( ! V_167 || ! V_168 )
goto V_176;
for ( V_113 = 0 ; V_113 < V_165 ; V_113 ++ ) {
V_167 [ V_113 ] = F_141 ( sizeof( struct V_26 ) , V_106 ) ;
V_168 [ V_113 ] = F_141 ( sizeof( struct V_107 ) , V_106 ) ;
if ( ! V_167 [ V_113 ] || ! V_168 [ V_113 ] )
goto V_176;
}
V_50:
F_57 ( & V_51 ) ;
V_113 = V_171 = V_170 ;
V_17 = V_163 [ V_113 ] ;
V_3 = V_17 + V_164 [ V_113 ] ;
if ( ! F_202 ( V_64 , & V_9 , & V_37 ) ) {
V_172 = V_162 - V_173 ;
goto V_58;
}
V_172 = F_203 ( & V_9 , & V_37 , V_41 ) - V_3 ;
while ( true ) {
F_16 ( V_9 && V_9 -> va_end <= V_172 + V_3 ) ;
F_16 ( V_37 && V_37 -> va_end > V_172 + V_3 ) ;
if ( V_172 + V_173 < V_166 + V_173 ) {
F_60 ( & V_51 ) ;
if ( ! V_46 ) {
F_61 () ;
V_46 = true ;
goto V_50;
}
goto V_176;
}
if ( V_9 && V_9 -> va_start < V_172 + V_3 ) {
V_172 = F_203 ( & V_9 , & V_37 , V_41 ) - V_3 ;
V_171 = V_113 ;
continue;
}
if ( V_37 && V_37 -> va_end > V_172 + V_17 ) {
V_9 = V_37 ;
V_37 = F_201 ( F_50 ( & V_9 -> V_27 ) ) ;
V_172 = F_203 ( & V_9 , & V_37 , V_41 ) - V_3 ;
V_171 = V_113 ;
continue;
}
V_113 = ( V_113 + V_165 - 1 ) % V_165 ;
if ( V_113 == V_171 )
break;
V_17 = V_163 [ V_113 ] ;
V_3 = V_17 + V_164 [ V_113 ] ;
F_202 ( V_172 + V_3 , & V_9 , & V_37 ) ;
}
V_58:
for ( V_113 = 0 ; V_113 < V_165 ; V_113 ++ ) {
struct V_26 * V_30 = V_167 [ V_113 ] ;
V_30 -> va_start = V_172 + V_163 [ V_113 ] ;
V_30 -> va_end = V_30 -> va_start + V_164 [ V_113 ] ;
F_46 ( V_30 ) ;
}
V_64 = V_172 + V_163 [ V_170 ] ;
F_60 ( & V_51 ) ;
for ( V_113 = 0 ; V_113 < V_165 ; V_113 ++ )
F_146 ( V_168 [ V_113 ] , V_167 [ V_113 ] , V_134 ,
F_205 ) ;
F_64 ( V_167 ) ;
return V_168 ;
V_176:
for ( V_113 = 0 ; V_113 < V_165 ; V_113 ++ ) {
if ( V_167 )
F_64 ( V_167 [ V_113 ] ) ;
if ( V_168 )
F_64 ( V_168 [ V_113 ] ) ;
}
F_64 ( V_167 ) ;
F_64 ( V_168 ) ;
return NULL ;
}
void F_207 ( struct V_107 * * V_168 , int V_165 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_165 ; V_97 ++ )
F_199 ( V_168 [ V_97 ] ) ;
F_64 ( V_168 ) ;
}
static void * F_208 ( struct V_177 * V_178 , T_11 * V_179 )
__acquires( &vmlist_lock
static void * F_209 ( struct V_177 * V_178 , void * V_33 , T_11 * V_179 )
{
struct V_107 * V_180 = V_33 ;
++ * V_179 ;
return V_180 -> V_9 ;
}
static void F_210 ( struct V_177 * V_178 , void * V_33 )
__releases( &vmlist_lock
static void F_211 ( struct V_177 * V_178 , struct V_107 * V_180 )
{
if ( V_181 ) {
unsigned int V_14 , * V_182 = V_178 -> V_115 ;
if ( ! V_182 )
return;
memset ( V_182 , 0 , V_183 * sizeof( unsigned int ) ) ;
for ( V_14 = 0 ; V_14 < V_180 -> V_122 ; V_14 ++ )
V_182 [ F_212 ( V_180 -> V_13 [ V_14 ] ) ] ++ ;
F_213 (nr, N_HIGH_MEMORY)
if ( V_182 [ V_14 ] )
F_214 ( V_178 , L_7 , V_14 , V_182 [ V_14 ] ) ;
}
}
static int F_215 ( struct V_177 * V_178 , void * V_33 )
{
struct V_107 * V_180 = V_33 ;
F_214 ( V_178 , L_8 ,
V_180 -> V_2 , V_180 -> V_2 + V_180 -> V_40 , V_180 -> V_40 ) ;
if ( V_180 -> V_114 )
F_214 ( V_178 , L_9 , V_180 -> V_114 ) ;
if ( V_180 -> V_122 )
F_214 ( V_178 , L_10 , V_180 -> V_122 ) ;
if ( V_180 -> V_184 )
F_214 ( V_178 , L_11 , ( unsigned long long ) V_180 -> V_184 ) ;
if ( V_180 -> V_59 & V_117 )
F_214 ( V_178 , L_12 ) ;
if ( V_180 -> V_59 & V_134 )
F_214 ( V_178 , L_13 ) ;
if ( V_180 -> V_59 & V_185 )
F_214 ( V_178 , L_14 ) ;
if ( V_180 -> V_59 & V_136 )
F_214 ( V_178 , L_15 ) ;
if ( V_180 -> V_59 & V_123 )
F_214 ( V_178 , L_16 ) ;
F_211 ( V_178 , V_180 ) ;
F_216 ( V_178 , '\n' ) ;
return 0 ;
}
static int F_217 ( struct V_186 * V_186 , struct V_187 * V_187 )
{
unsigned int * V_188 = NULL ;
int V_19 ;
if ( V_181 ) {
V_188 = F_218 ( V_183 * sizeof( unsigned int ) , V_106 ) ;
if ( V_188 == NULL )
return - V_15 ;
}
V_19 = F_219 ( V_187 , & V_189 ) ;
if ( ! V_19 ) {
struct V_177 * V_178 = V_187 -> V_190 ;
V_178 -> V_115 = V_188 ;
} else
F_64 ( V_188 ) ;
return V_19 ;
}
static int T_7 F_220 ( void )
{
F_221 ( L_17 , V_191 , NULL , & V_192 ) ;
return 0 ;
}
