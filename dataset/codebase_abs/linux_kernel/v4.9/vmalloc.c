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
F_62 ( F_63 ( V_51 ) ) ;
V_38 = F_64 ( sizeof( struct V_34 ) ,
V_51 & V_54 , V_50 ) ;
if ( F_65 ( ! V_38 ) )
return F_66 ( - V_23 ) ;
F_67 ( & V_38 -> V_35 , V_55 , V_51 & V_54 ) ;
V_56:
F_68 ( & V_57 ) ;
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
V_10 = F_69 ( V_53 -> va_end , V_47 ) ;
if ( V_10 < V_48 )
goto V_62;
if ( V_10 + V_46 < V_10 )
goto V_63;
} else {
V_10 = F_69 ( V_48 , V_47 ) ;
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
V_10 = F_69 ( V_53 -> va_end , V_47 ) ;
if ( V_10 + V_46 < V_10 )
goto V_63;
if ( F_70 ( & V_53 -> V_8 , & V_45 ) )
goto V_64;
V_53 = F_71 ( V_53 , V_8 ) ;
}
V_64:
if ( V_10 + V_46 > V_49 )
goto V_63;
V_38 -> va_start = V_10 ;
V_38 -> va_end = V_10 + V_46 ;
V_38 -> V_65 = 0 ;
F_53 ( V_38 ) ;
V_58 = & V_38 -> V_35 ;
F_72 ( & V_57 ) ;
F_23 ( ! F_73 ( V_38 -> va_start , V_47 ) ) ;
F_23 ( V_38 -> va_start < V_48 ) ;
F_23 ( V_38 -> va_end > V_49 ) ;
return V_38 ;
V_63:
F_72 ( & V_57 ) ;
if ( ! V_52 ) {
F_74 () ;
V_52 = 1 ;
goto V_56;
}
if ( F_63 ( V_51 ) ) {
unsigned long V_66 = 0 ;
F_75 ( & V_67 , 0 , & V_66 ) ;
if ( V_66 > 0 ) {
V_52 = 0 ;
goto V_56;
}
}
if ( F_76 () )
F_77 ( L_1 ,
V_46 ) ;
F_78 ( V_38 ) ;
return F_66 ( - V_24 ) ;
}
int F_79 ( struct V_68 * V_69 )
{
return F_80 ( & V_67 , V_69 ) ;
}
int F_81 ( struct V_68 * V_69 )
{
return F_82 ( & V_67 , V_69 ) ;
}
static void F_83 ( struct V_34 * V_38 )
{
F_23 ( F_84 ( & V_38 -> V_35 ) ) ;
if ( V_58 ) {
if ( V_38 -> va_end < V_60 ) {
V_58 = NULL ;
} else {
struct V_34 * V_70 ;
V_70 = F_52 ( V_58 , struct V_34 , V_35 ) ;
if ( V_38 -> va_start <= V_70 -> va_start ) {
V_58 = F_57 ( & V_38 -> V_35 ) ;
}
}
}
F_85 ( & V_38 -> V_35 , & V_37 ) ;
F_86 ( & V_38 -> V_35 ) ;
F_87 ( & V_38 -> V_8 ) ;
if ( V_38 -> va_end > V_71 && V_38 -> va_end <= V_72 )
V_73 = F_88 ( V_73 , V_38 -> va_end ) ;
F_89 ( V_38 , V_74 ) ;
}
static void F_90 ( struct V_34 * V_38 )
{
F_68 ( & V_57 ) ;
F_83 ( V_38 ) ;
F_72 ( & V_57 ) ;
}
static void F_91 ( struct V_34 * V_38 )
{
F_22 ( V_38 -> va_start , V_38 -> va_end ) ;
}
static void F_92 ( unsigned long V_25 , unsigned long V_11 )
{
if ( F_93 () ) {
F_22 ( V_25 , V_11 ) ;
F_94 ( V_25 , V_11 ) ;
}
}
static unsigned long F_95 ( void )
{
unsigned int log ;
log = F_96 ( F_97 () ) ;
return log * ( 32UL * 1024 * 1024 / V_15 ) ;
}
void F_98 ( void )
{
F_99 ( & V_75 , F_95 () + 1 ) ;
}
static void F_100 ( unsigned long * V_25 , unsigned long * V_11 ,
int V_76 , int V_77 )
{
static F_101 ( V_78 ) ;
struct V_6 * V_79 ;
struct V_34 * V_38 ;
struct V_34 * V_80 ;
int V_22 = 0 ;
if ( ! V_76 && ! V_77 ) {
if ( ! F_102 ( & V_78 ) )
return;
} else
F_68 ( & V_78 ) ;
if ( V_76 )
F_103 () ;
V_79 = F_3 ( & V_81 ) ;
F_104 (va, valist, purge_list) {
if ( V_38 -> va_start < * V_25 )
* V_25 = V_38 -> va_start ;
if ( V_38 -> va_end > * V_11 )
* V_11 = V_38 -> va_end ;
V_22 += ( V_38 -> va_end - V_38 -> va_start ) >> V_82 ;
}
if ( V_22 )
F_105 ( V_22 , & V_75 ) ;
if ( V_22 || V_77 )
F_94 ( * V_25 , * V_11 ) ;
if ( V_22 ) {
F_68 ( & V_57 ) ;
F_106 (va, n_va, valist, purge_list)
F_83 ( V_38 ) ;
F_72 ( & V_57 ) ;
}
F_72 ( & V_78 ) ;
}
static void F_107 ( void )
{
unsigned long V_25 = V_83 , V_11 = 0 ;
F_100 ( & V_25 , & V_11 , 0 , 0 ) ;
}
static void F_74 ( void )
{
unsigned long V_25 = V_83 , V_11 = 0 ;
F_100 ( & V_25 , & V_11 , 1 , 0 ) ;
}
static void F_108 ( struct V_34 * V_38 )
{
int V_84 ;
V_84 = F_109 ( ( V_38 -> va_end - V_38 -> va_start ) >> V_82 ,
& V_75 ) ;
F_110 ( & V_38 -> V_85 , & V_81 ) ;
if ( F_65 ( V_84 > F_95 () ) )
F_107 () ;
}
static void F_111 ( struct V_34 * V_38 )
{
F_91 ( V_38 ) ;
F_108 ( V_38 ) ;
}
static void F_112 ( struct V_34 * V_38 )
{
F_113 ( V_38 -> va_start , V_38 -> va_end ) ;
F_111 ( V_38 ) ;
}
static struct V_34 * F_114 ( unsigned long V_10 )
{
struct V_34 * V_38 ;
F_68 ( & V_57 ) ;
V_38 = F_51 ( V_10 ) ;
F_72 ( & V_57 ) ;
return V_38 ;
}
static void F_115 ( unsigned long V_10 )
{
struct V_34 * V_38 ;
V_38 = F_114 ( V_10 ) ;
F_23 ( ! V_38 ) ;
F_112 ( V_38 ) ;
}
static unsigned long F_116 ( unsigned long V_10 )
{
V_10 -= V_71 & ~ ( V_86 - 1 ) ;
V_10 /= V_86 ;
return V_10 ;
}
static void * F_117 ( unsigned long va_start , unsigned long V_87 )
{
unsigned long V_10 ;
V_10 = va_start + ( V_87 << V_82 ) ;
F_23 ( F_116 ( V_10 ) != F_116 ( va_start ) ) ;
return ( void * ) V_10 ;
}
static void * F_118 ( unsigned int V_88 , T_6 V_51 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 ;
struct V_34 * V_38 ;
unsigned long V_93 ;
int V_50 , V_26 ;
void * V_94 ;
V_50 = F_119 () ;
V_92 = F_64 ( sizeof( struct V_91 ) ,
V_51 & V_54 , V_50 ) ;
if ( F_65 ( ! V_92 ) )
return F_66 ( - V_23 ) ;
V_38 = F_59 ( V_86 , V_86 ,
V_71 , V_72 ,
V_50 , V_51 ) ;
if ( F_120 ( V_38 ) ) {
F_78 ( V_92 ) ;
return F_121 ( V_38 ) ;
}
V_26 = F_122 ( V_51 ) ;
if ( F_65 ( V_26 ) ) {
F_78 ( V_92 ) ;
F_90 ( V_38 ) ;
return F_66 ( V_26 ) ;
}
V_94 = F_117 ( V_38 -> va_start , 0 ) ;
F_123 ( & V_92 -> V_95 ) ;
V_92 -> V_38 = V_38 ;
F_23 ( V_96 <= ( 1UL << V_88 ) ) ;
V_92 -> free = V_96 - ( 1UL << V_88 ) ;
V_92 -> V_97 = 0 ;
V_92 -> V_98 = V_96 ;
V_92 -> V_99 = 0 ;
F_124 ( & V_92 -> V_100 ) ;
V_93 = F_116 ( V_38 -> va_start ) ;
F_68 ( & V_101 ) ;
V_26 = F_125 ( & V_102 , V_93 , V_92 ) ;
F_72 ( & V_101 ) ;
F_23 ( V_26 ) ;
F_126 () ;
V_90 = & F_127 ( V_89 ) ;
F_68 ( & V_90 -> V_95 ) ;
F_128 ( & V_92 -> V_100 , & V_90 -> free ) ;
F_72 ( & V_90 -> V_95 ) ;
F_129 ( V_89 ) ;
return V_94 ;
}
static void F_130 ( struct V_91 * V_92 )
{
struct V_91 * V_42 ;
unsigned long V_93 ;
V_93 = F_116 ( V_92 -> V_38 -> va_start ) ;
F_68 ( & V_101 ) ;
V_42 = F_131 ( & V_102 , V_93 ) ;
F_72 ( & V_101 ) ;
F_23 ( V_42 != V_92 ) ;
F_108 ( V_92 -> V_38 ) ;
F_89 ( V_92 , V_74 ) ;
}
static void F_132 ( int V_103 )
{
F_133 ( V_104 ) ;
struct V_91 * V_92 ;
struct V_91 * V_105 ;
struct V_89 * V_90 = & F_134 ( V_89 , V_103 ) ;
F_135 () ;
F_136 (vb, &vbq->free, free_list) {
if ( ! ( V_92 -> free + V_92 -> V_97 == V_96 && V_92 -> V_97 != V_96 ) )
continue;
F_68 ( & V_92 -> V_95 ) ;
if ( V_92 -> free + V_92 -> V_97 == V_96 && V_92 -> V_97 != V_96 ) {
V_92 -> free = 0 ;
V_92 -> V_97 = V_96 ;
V_92 -> V_98 = 0 ;
V_92 -> V_99 = V_96 ;
F_68 ( & V_90 -> V_95 ) ;
F_87 ( & V_92 -> V_100 ) ;
F_72 ( & V_90 -> V_95 ) ;
F_72 ( & V_92 -> V_95 ) ;
F_137 ( & V_92 -> V_104 , & V_104 ) ;
} else
F_72 ( & V_92 -> V_95 ) ;
}
F_138 () ;
F_139 (vb, n_vb, &purge, purge) {
F_140 ( & V_92 -> V_104 ) ;
F_130 ( V_92 ) ;
}
}
static void F_103 ( void )
{
int V_103 ;
F_141 (cpu)
F_132 ( V_103 ) ;
}
static void * F_142 ( unsigned long V_46 , T_6 V_51 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 ;
void * V_94 = NULL ;
unsigned int V_88 ;
F_23 ( F_60 ( V_46 ) ) ;
F_23 ( V_46 > V_15 * V_106 ) ;
if ( F_9 ( V_46 == 0 ) ) {
return NULL ;
}
V_88 = F_143 ( V_46 ) ;
F_135 () ;
V_90 = & F_127 ( V_89 ) ;
F_136 (vb, &vbq->free, free_list) {
unsigned long V_87 ;
F_68 ( & V_92 -> V_95 ) ;
if ( V_92 -> free < ( 1UL << V_88 ) ) {
F_72 ( & V_92 -> V_95 ) ;
continue;
}
V_87 = V_96 - V_92 -> free ;
V_94 = F_117 ( V_92 -> V_38 -> va_start , V_87 ) ;
V_92 -> free -= 1UL << V_88 ;
if ( V_92 -> free == 0 ) {
F_68 ( & V_90 -> V_95 ) ;
F_87 ( & V_92 -> V_100 ) ;
F_72 ( & V_90 -> V_95 ) ;
}
F_72 ( & V_92 -> V_95 ) ;
break;
}
F_129 ( V_89 ) ;
F_138 () ;
if ( ! V_94 )
V_94 = F_118 ( V_88 , V_51 ) ;
return V_94 ;
}
static void F_144 ( const void * V_10 , unsigned long V_46 )
{
unsigned long V_107 ;
unsigned long V_93 ;
unsigned int V_88 ;
struct V_91 * V_92 ;
F_23 ( F_60 ( V_46 ) ) ;
F_23 ( V_46 > V_15 * V_106 ) ;
F_113 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
V_88 = F_143 ( V_46 ) ;
V_107 = ( unsigned long ) V_10 & ( V_86 - 1 ) ;
V_107 >>= V_82 ;
V_93 = F_116 ( ( unsigned long ) V_10 ) ;
F_135 () ;
V_92 = F_145 ( & V_102 , V_93 ) ;
F_138 () ;
F_23 ( ! V_92 ) ;
F_22 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
F_68 ( & V_92 -> V_95 ) ;
V_92 -> V_98 = F_146 ( V_92 -> V_98 , V_107 ) ;
V_92 -> V_99 = F_88 ( V_92 -> V_99 , V_107 + ( 1UL << V_88 ) ) ;
V_92 -> V_97 += 1UL << V_88 ;
if ( V_92 -> V_97 == V_96 ) {
F_23 ( V_92 -> free ) ;
F_72 ( & V_92 -> V_95 ) ;
F_130 ( V_92 ) ;
} else
F_72 ( & V_92 -> V_95 ) ;
}
void F_147 ( void )
{
unsigned long V_25 = V_83 , V_11 = 0 ;
int V_103 ;
int V_108 = 0 ;
if ( F_65 ( ! V_109 ) )
return;
F_141 (cpu) {
struct V_89 * V_90 = & F_134 ( V_89 , V_103 ) ;
struct V_91 * V_92 ;
F_135 () ;
F_136 (vb, &vbq->free, free_list) {
F_68 ( & V_92 -> V_95 ) ;
if ( V_92 -> V_97 ) {
unsigned long va_start = V_92 -> V_38 -> va_start ;
unsigned long V_110 , V_111 ;
V_110 = va_start + ( V_92 -> V_98 << V_82 ) ;
V_111 = va_start + ( V_92 -> V_99 << V_82 ) ;
V_25 = F_146 ( V_110 , V_25 ) ;
V_11 = F_88 ( V_111 , V_11 ) ;
V_108 = 1 ;
}
F_72 ( & V_92 -> V_95 ) ;
}
F_138 () ;
}
F_100 ( & V_25 , & V_11 , 1 , V_108 ) ;
}
void F_148 ( const void * V_112 , unsigned int V_113 )
{
unsigned long V_46 = ( unsigned long ) V_113 << V_82 ;
unsigned long V_10 = ( unsigned long ) V_112 ;
F_23 ( ! V_10 ) ;
F_23 ( V_10 < V_71 ) ;
F_23 ( V_10 > V_72 ) ;
F_23 ( ! F_149 ( V_10 ) ) ;
F_150 ( V_112 , V_46 ) ;
F_92 ( V_10 , V_10 + V_46 ) ;
if ( F_151 ( V_113 <= V_106 ) )
F_144 ( V_112 , V_46 ) ;
else
F_115 ( V_10 ) ;
}
void * F_152 ( struct V_20 * * V_21 , unsigned int V_113 , int V_50 , T_5 V_19 )
{
unsigned long V_46 = ( unsigned long ) V_113 << V_82 ;
unsigned long V_10 ;
void * V_112 ;
if ( F_151 ( V_113 <= V_106 ) ) {
V_112 = F_142 ( V_46 , V_114 ) ;
if ( F_120 ( V_112 ) )
return NULL ;
V_10 = ( unsigned long ) V_112 ;
} else {
struct V_34 * V_38 ;
V_38 = F_59 ( V_46 , V_15 ,
V_71 , V_72 , V_50 , V_114 ) ;
if ( F_120 ( V_38 ) )
return NULL ;
V_10 = V_38 -> va_start ;
V_112 = ( void * ) V_10 ;
}
if ( F_36 ( V_10 , V_10 + V_46 , V_19 , V_21 ) < 0 ) {
F_148 ( V_112 , V_113 ) ;
return NULL ;
}
return V_112 ;
}
void T_7 F_153 ( struct V_115 * V_116 )
{
struct V_115 * V_42 , * * V_4 ;
F_23 ( V_109 ) ;
for ( V_4 = & V_117 ; ( V_42 = * V_4 ) != NULL ; V_4 = & V_42 -> V_17 ) {
if ( V_42 -> V_10 >= V_116 -> V_10 ) {
F_23 ( V_42 -> V_10 < V_116 -> V_10 + V_116 -> V_46 ) ;
break;
} else
F_23 ( V_42 -> V_10 + V_42 -> V_46 > V_116 -> V_10 ) ;
}
V_116 -> V_17 = * V_4 ;
* V_4 = V_116 ;
}
void T_7 F_154 ( struct V_115 * V_116 , T_8 V_47 )
{
static T_8 T_9 V_118 ;
unsigned long V_10 ;
V_10 = F_69 ( V_71 + T_9 , V_47 ) ;
T_9 = F_155 ( V_10 + V_116 -> V_46 ) - V_71 ;
V_116 -> V_10 = ( void * ) V_10 ;
F_153 ( V_116 ) ;
}
void T_7 F_156 ( void )
{
struct V_34 * V_38 ;
struct V_115 * V_42 ;
int V_119 ;
F_141 (i) {
struct V_89 * V_90 ;
struct V_3 * V_4 ;
V_90 = & F_134 ( V_89 , V_119 ) ;
F_123 ( & V_90 -> V_95 ) ;
F_124 ( & V_90 -> free ) ;
V_4 = & F_134 ( V_3 , V_119 ) ;
F_157 ( & V_4 -> V_8 ) ;
F_158 ( & V_4 -> V_5 , F_1 ) ;
}
for ( V_42 = V_117 ; V_42 ; V_42 = V_42 -> V_17 ) {
V_38 = F_159 ( sizeof( struct V_34 ) , V_120 ) ;
V_38 -> V_65 = V_121 ;
V_38 -> va_start = ( unsigned long ) V_42 -> V_10 ;
V_38 -> va_end = V_38 -> va_start + V_42 -> V_46 ;
V_38 -> V_116 = V_42 ;
F_53 ( V_38 ) ;
}
V_73 = V_72 ;
V_109 = true ;
}
int F_160 ( unsigned long V_10 , unsigned long V_46 ,
T_5 V_19 , struct V_20 * * V_21 )
{
return F_35 ( V_10 , V_10 + V_46 , V_19 , V_21 ) ;
}
void F_161 ( unsigned long V_10 , unsigned long V_46 )
{
F_22 ( V_10 , V_10 + V_46 ) ;
}
void F_162 ( unsigned long V_10 , unsigned long V_46 )
{
unsigned long V_11 = V_10 + V_46 ;
F_113 ( V_10 , V_11 ) ;
F_22 ( V_10 , V_11 ) ;
F_94 ( V_10 , V_11 ) ;
}
int F_163 ( struct V_115 * V_122 , T_5 V_19 , struct V_20 * * V_21 )
{
unsigned long V_10 = ( unsigned long ) V_122 -> V_10 ;
unsigned long V_11 = V_10 + F_164 ( V_122 ) ;
int V_26 ;
V_26 = F_36 ( V_10 , V_11 , V_19 , V_21 ) ;
return V_26 > 0 ? 0 : V_26 ;
}
static void F_165 ( struct V_115 * V_116 , struct V_34 * V_38 ,
unsigned long V_65 , const void * V_123 )
{
F_68 ( & V_57 ) ;
V_116 -> V_65 = V_65 ;
V_116 -> V_10 = ( void * ) V_38 -> va_start ;
V_116 -> V_46 = V_38 -> va_end - V_38 -> va_start ;
V_116 -> V_123 = V_123 ;
V_38 -> V_116 = V_116 ;
V_38 -> V_65 |= V_121 ;
F_72 ( & V_57 ) ;
}
static void F_166 ( struct V_115 * V_116 )
{
F_167 () ;
V_116 -> V_65 &= ~ V_124 ;
}
static struct V_115 * F_168 ( unsigned long V_46 ,
unsigned long V_47 , unsigned long V_65 , unsigned long V_25 ,
unsigned long V_11 , int V_50 , T_6 V_51 , const void * V_123 )
{
struct V_34 * V_38 ;
struct V_115 * V_122 ;
F_23 ( F_169 () ) ;
V_46 = F_170 ( V_46 ) ;
if ( F_65 ( ! V_46 ) )
return NULL ;
if ( V_65 & V_125 )
V_47 = 1ul << F_171 ( int , F_172 ( V_46 ) ,
V_82 , V_126 ) ;
V_122 = F_173 ( sizeof( * V_122 ) , V_51 & V_54 , V_50 ) ;
if ( F_65 ( ! V_122 ) )
return NULL ;
if ( ! ( V_65 & V_127 ) )
V_46 += V_15 ;
V_38 = F_59 ( V_46 , V_47 , V_25 , V_11 , V_50 , V_51 ) ;
if ( F_120 ( V_38 ) ) {
F_78 ( V_122 ) ;
return NULL ;
}
F_165 ( V_122 , V_38 , V_65 , V_123 ) ;
return V_122 ;
}
struct V_115 * F_174 ( unsigned long V_46 , unsigned long V_65 ,
unsigned long V_25 , unsigned long V_11 )
{
return F_168 ( V_46 , 1 , V_65 , V_25 , V_11 , V_128 ,
V_114 , F_175 ( 0 ) ) ;
}
struct V_115 * F_176 ( unsigned long V_46 , unsigned long V_65 ,
unsigned long V_25 , unsigned long V_11 ,
const void * V_123 )
{
return F_168 ( V_46 , 1 , V_65 , V_25 , V_11 , V_128 ,
V_114 , V_123 ) ;
}
struct V_115 * F_177 ( unsigned long V_46 , unsigned long V_65 )
{
return F_168 ( V_46 , 1 , V_65 , V_71 , V_72 ,
V_128 , V_114 ,
F_175 ( 0 ) ) ;
}
struct V_115 * F_178 ( unsigned long V_46 , unsigned long V_65 ,
const void * V_123 )
{
return F_168 ( V_46 , 1 , V_65 , V_71 , V_72 ,
V_128 , V_114 , V_123 ) ;
}
struct V_115 * F_179 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_114 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_65 & V_121 )
return V_38 -> V_116 ;
return NULL ;
}
struct V_115 * F_180 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_114 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_65 & V_121 ) {
struct V_115 * V_116 = V_38 -> V_116 ;
F_68 ( & V_57 ) ;
V_38 -> V_116 = NULL ;
V_38 -> V_65 &= ~ V_121 ;
F_72 ( & V_57 ) ;
F_92 ( V_38 -> va_start , V_38 -> va_end ) ;
F_181 ( V_116 ) ;
F_112 ( V_38 ) ;
return V_116 ;
}
return NULL ;
}
static void F_5 ( const void * V_10 , int V_129 )
{
struct V_115 * V_122 ;
if ( ! V_10 )
return;
if ( F_182 ( ! F_149 ( V_10 ) , L_2 ,
V_10 ) )
return;
V_122 = F_180 ( V_10 ) ;
if ( F_65 ( ! V_122 ) ) {
F_182 ( 1 , V_130 L_3 ,
V_10 ) ;
return;
}
F_150 ( V_10 , F_164 ( V_122 ) ) ;
F_183 ( V_10 , F_164 ( V_122 ) ) ;
if ( V_129 ) {
int V_119 ;
for ( V_119 = 0 ; V_119 < V_122 -> V_131 ; V_119 ++ ) {
struct V_20 * V_20 = V_122 -> V_21 [ V_119 ] ;
F_23 ( ! V_20 ) ;
F_184 ( V_20 , 0 ) ;
}
F_185 ( V_122 -> V_21 ) ;
}
F_78 ( V_122 ) ;
return;
}
void F_186 ( const void * V_10 )
{
F_23 ( F_187 () ) ;
F_188 ( V_10 ) ;
if ( ! V_10 )
return;
if ( F_65 ( F_169 () ) ) {
struct V_3 * V_4 = F_189 ( & V_3 ) ;
if ( F_110 ( (struct V_6 * ) V_10 , & V_4 -> V_8 ) )
F_190 ( & V_4 -> V_5 ) ;
} else
F_5 ( V_10 , 1 ) ;
}
void F_191 ( const void * V_10 )
{
F_23 ( F_169 () ) ;
F_192 () ;
if ( V_10 )
F_5 ( V_10 , 0 ) ;
}
void * F_193 ( struct V_20 * * V_21 , unsigned int V_113 ,
unsigned long V_65 , T_5 V_19 )
{
struct V_115 * V_122 ;
unsigned long V_46 ;
F_192 () ;
if ( V_113 > V_132 )
return NULL ;
V_46 = ( unsigned long ) V_113 << V_82 ;
V_122 = F_178 ( V_46 , V_65 , F_175 ( 0 ) ) ;
if ( ! V_122 )
return NULL ;
if ( F_163 ( V_122 , V_19 , V_21 ) ) {
F_191 ( V_122 -> V_10 ) ;
return NULL ;
}
return V_122 -> V_10 ;
}
static void * F_194 ( struct V_115 * V_122 , T_6 V_51 ,
T_5 V_19 , int V_50 )
{
struct V_20 * * V_21 ;
unsigned int V_131 , V_133 , V_119 ;
const T_6 V_134 = ( V_51 & V_54 ) | V_135 ;
const T_6 V_136 = V_51 | V_137 ;
V_131 = F_164 ( V_122 ) >> V_82 ;
V_133 = ( V_131 * sizeof( struct V_20 * ) ) ;
V_122 -> V_131 = V_131 ;
if ( V_133 > V_15 ) {
V_21 = F_195 ( V_133 , 1 , V_134 | V_138 ,
V_139 , V_50 , V_122 -> V_123 ) ;
} else {
V_21 = F_64 ( V_133 , V_134 , V_50 ) ;
}
V_122 -> V_21 = V_21 ;
if ( ! V_122 -> V_21 ) {
F_180 ( V_122 -> V_10 ) ;
F_78 ( V_122 ) ;
return NULL ;
}
for ( V_119 = 0 ; V_119 < V_122 -> V_131 ; V_119 ++ ) {
struct V_20 * V_20 ;
if ( V_50 == V_128 )
V_20 = F_196 ( V_136 ) ;
else
V_20 = F_197 ( V_50 , V_136 , 0 ) ;
if ( F_65 ( ! V_20 ) ) {
V_122 -> V_131 = V_119 ;
goto V_140;
}
V_122 -> V_21 [ V_119 ] = V_20 ;
if ( F_63 ( V_51 ) )
F_198 () ;
}
if ( F_163 ( V_122 , V_19 , V_21 ) )
goto V_140;
return V_122 -> V_10 ;
V_140:
F_199 ( V_51 ,
L_4 ,
( V_122 -> V_131 * V_15 ) , V_122 -> V_46 ) ;
F_186 ( V_122 -> V_10 ) ;
return NULL ;
}
void * F_200 ( unsigned long V_46 , unsigned long V_47 ,
unsigned long V_25 , unsigned long V_11 , T_6 V_51 ,
T_5 V_19 , unsigned long V_141 , int V_50 ,
const void * V_123 )
{
struct V_115 * V_122 ;
void * V_10 ;
unsigned long V_142 = V_46 ;
V_46 = F_170 ( V_46 ) ;
if ( ! V_46 || ( V_46 >> V_82 ) > V_132 )
goto V_140;
V_122 = F_168 ( V_46 , V_47 , V_143 | V_124 |
V_141 , V_25 , V_11 , V_50 , V_51 , V_123 ) ;
if ( ! V_122 )
goto V_140;
V_10 = F_194 ( V_122 , V_51 , V_19 , V_50 ) ;
if ( ! V_10 )
return NULL ;
F_166 ( V_122 ) ;
F_201 ( V_10 , V_142 , 2 , V_51 ) ;
return V_10 ;
V_140:
F_199 ( V_51 ,
L_5 , V_142 ) ;
return NULL ;
}
static void * F_195 ( unsigned long V_46 , unsigned long V_47 ,
T_6 V_51 , T_5 V_19 ,
int V_50 , const void * V_123 )
{
return F_200 ( V_46 , V_47 , V_71 , V_72 ,
V_51 , V_19 , 0 , V_50 , V_123 ) ;
}
void * F_202 ( unsigned long V_46 , T_6 V_51 , T_5 V_19 )
{
return F_195 ( V_46 , 1 , V_51 , V_19 , V_128 ,
F_175 ( 0 ) ) ;
}
static inline void * F_203 ( unsigned long V_46 ,
int V_50 , T_6 V_65 )
{
return F_195 ( V_46 , 1 , V_65 , V_139 ,
V_50 , F_175 ( 0 ) ) ;
}
void * F_204 ( unsigned long V_46 )
{
return F_203 ( V_46 , V_128 ,
V_114 | V_138 ) ;
}
void * F_205 ( unsigned long V_46 )
{
return F_203 ( V_46 , V_128 ,
V_114 | V_138 | V_135 ) ;
}
void * F_206 ( unsigned long V_46 )
{
struct V_115 * V_122 ;
void * V_27 ;
V_27 = F_195 ( V_46 , V_144 ,
V_114 | V_138 | V_135 ,
V_139 , V_128 ,
F_175 ( 0 ) ) ;
if ( V_27 ) {
V_122 = F_179 ( V_27 ) ;
V_122 -> V_65 |= V_145 ;
}
return V_27 ;
}
void * F_207 ( unsigned long V_46 , int V_50 )
{
return F_195 ( V_46 , 1 , V_114 | V_138 , V_139 ,
V_50 , F_175 ( 0 ) ) ;
}
void * F_208 ( unsigned long V_46 , int V_50 )
{
return F_203 ( V_46 , V_50 ,
V_114 | V_138 | V_135 ) ;
}
void * F_209 ( unsigned long V_46 )
{
return F_195 ( V_46 , 1 , V_114 | V_138 , V_146 ,
V_128 , F_175 ( 0 ) ) ;
}
void * F_210 ( unsigned long V_46 )
{
return F_195 ( V_46 , 1 , V_147 , V_139 ,
V_128 , F_175 ( 0 ) ) ;
}
void * F_211 ( unsigned long V_46 )
{
struct V_115 * V_122 ;
void * V_27 ;
V_27 = F_195 ( V_46 , 1 , V_147 | V_135 , V_139 ,
V_128 , F_175 ( 0 ) ) ;
if ( V_27 ) {
V_122 = F_179 ( V_27 ) ;
V_122 -> V_65 |= V_145 ;
}
return V_27 ;
}
static int F_212 ( char * V_148 , char * V_10 , unsigned long V_113 )
{
struct V_20 * V_4 ;
int V_149 = 0 ;
while ( V_113 ) {
unsigned long V_107 , V_150 ;
V_107 = F_60 ( V_10 ) ;
V_150 = V_15 - V_107 ;
if ( V_150 > V_113 )
V_150 = V_113 ;
V_4 = F_41 ( V_10 ) ;
if ( V_4 ) {
void * V_151 = F_213 ( V_4 ) ;
memcpy ( V_148 , V_151 + V_107 , V_150 ) ;
F_214 ( V_151 ) ;
} else
memset ( V_148 , 0 , V_150 ) ;
V_10 += V_150 ;
V_148 += V_150 ;
V_149 += V_150 ;
V_113 -= V_150 ;
}
return V_149 ;
}
static int F_215 ( char * V_148 , char * V_10 , unsigned long V_113 )
{
struct V_20 * V_4 ;
int V_149 = 0 ;
while ( V_113 ) {
unsigned long V_107 , V_150 ;
V_107 = F_60 ( V_10 ) ;
V_150 = V_15 - V_107 ;
if ( V_150 > V_113 )
V_150 = V_113 ;
V_4 = F_41 ( V_10 ) ;
if ( V_4 ) {
void * V_151 = F_213 ( V_4 ) ;
memcpy ( V_151 + V_107 , V_148 , V_150 ) ;
F_214 ( V_151 ) ;
}
V_10 += V_150 ;
V_148 += V_150 ;
V_149 += V_150 ;
V_113 -= V_150 ;
}
return V_149 ;
}
long F_216 ( char * V_148 , char * V_10 , unsigned long V_113 )
{
struct V_34 * V_38 ;
struct V_115 * V_116 ;
char * V_94 , * V_152 = V_148 ;
unsigned long V_153 = V_113 ;
unsigned long V_36 ;
if ( ( unsigned long ) V_10 + V_113 < V_113 )
V_113 = - ( unsigned long ) V_10 ;
F_68 ( & V_57 ) ;
F_217 (va, &vmap_area_list, list) {
if ( ! V_113 )
break;
if ( ! ( V_38 -> V_65 & V_121 ) )
continue;
V_116 = V_38 -> V_116 ;
V_94 = ( char * ) V_116 -> V_10 ;
if ( V_10 >= V_94 + F_164 ( V_116 ) )
continue;
while ( V_10 < V_94 ) {
if ( V_113 == 0 )
goto V_154;
* V_148 = '\0' ;
V_148 ++ ;
V_10 ++ ;
V_113 -- ;
}
V_36 = V_94 + F_164 ( V_116 ) - V_10 ;
if ( V_36 > V_113 )
V_36 = V_113 ;
if ( ! ( V_116 -> V_65 & V_125 ) )
F_212 ( V_148 , V_10 , V_36 ) ;
else
memset ( V_148 , 0 , V_36 ) ;
V_148 += V_36 ;
V_10 += V_36 ;
V_113 -= V_36 ;
}
V_154:
F_72 ( & V_57 ) ;
if ( V_148 == V_152 )
return 0 ;
if ( V_148 != V_152 + V_153 )
memset ( V_148 , 0 , V_153 - ( V_148 - V_152 ) ) ;
return V_153 ;
}
long F_218 ( char * V_148 , char * V_10 , unsigned long V_113 )
{
struct V_34 * V_38 ;
struct V_115 * V_116 ;
char * V_94 ;
unsigned long V_36 , V_153 ;
int V_149 = 0 ;
if ( ( unsigned long ) V_10 + V_113 < V_113 )
V_113 = - ( unsigned long ) V_10 ;
V_153 = V_113 ;
F_68 ( & V_57 ) ;
F_217 (va, &vmap_area_list, list) {
if ( ! V_113 )
break;
if ( ! ( V_38 -> V_65 & V_121 ) )
continue;
V_116 = V_38 -> V_116 ;
V_94 = ( char * ) V_116 -> V_10 ;
if ( V_10 >= V_94 + F_164 ( V_116 ) )
continue;
while ( V_10 < V_94 ) {
if ( V_113 == 0 )
goto V_154;
V_148 ++ ;
V_10 ++ ;
V_113 -- ;
}
V_36 = V_94 + F_164 ( V_116 ) - V_10 ;
if ( V_36 > V_113 )
V_36 = V_113 ;
if ( ! ( V_116 -> V_65 & V_125 ) ) {
F_215 ( V_148 , V_10 , V_36 ) ;
V_149 ++ ;
}
V_148 += V_36 ;
V_10 += V_36 ;
V_113 -= V_36 ;
}
V_154:
F_72 ( & V_57 ) ;
if ( ! V_149 )
return 0 ;
return V_153 ;
}
int F_219 ( struct V_155 * V_156 , unsigned long V_157 ,
void * V_158 , unsigned long V_46 )
{
struct V_115 * V_122 ;
V_46 = F_170 ( V_46 ) ;
if ( ! F_149 ( V_157 ) || ! F_149 ( V_158 ) )
return - V_159 ;
V_122 = F_179 ( V_158 ) ;
if ( ! V_122 )
return - V_159 ;
if ( ! ( V_122 -> V_65 & V_145 ) )
return - V_159 ;
if ( V_158 + V_46 > V_122 -> V_10 + V_122 -> V_46 )
return - V_159 ;
do {
struct V_20 * V_20 = F_41 ( V_158 ) ;
int V_27 ;
V_27 = F_220 ( V_156 , V_157 , V_20 ) ;
if ( V_27 )
return V_27 ;
V_157 += V_15 ;
V_158 += V_15 ;
V_46 -= V_15 ;
} while ( V_46 > 0 );
V_156 -> V_141 |= V_160 | V_161 ;
return 0 ;
}
int F_221 ( struct V_155 * V_156 , void * V_10 ,
unsigned long V_162 )
{
return F_219 ( V_156 , V_156 -> V_163 ,
V_10 + ( V_162 << V_82 ) ,
V_156 -> V_164 - V_156 -> V_163 ) ;
}
void __weak F_222 ( void )
{
}
static int F_223 ( T_2 * V_12 , T_10 V_165 , unsigned long V_10 , void * V_166 )
{
T_2 * * * V_4 = V_166 ;
if ( V_4 ) {
* ( * V_4 ) = V_12 ;
( * V_4 ) ++ ;
}
return 0 ;
}
struct V_115 * F_224 ( T_8 V_46 , T_2 * * V_167 )
{
struct V_115 * V_122 ;
V_122 = F_178 ( V_46 , V_125 ,
F_175 ( 0 ) ) ;
if ( V_122 == NULL )
return NULL ;
if ( F_225 ( & V_14 , ( unsigned long ) V_122 -> V_10 ,
V_46 , F_223 , V_167 ? & V_167 : NULL ) ) {
F_226 ( V_122 ) ;
return NULL ;
}
return V_122 ;
}
void F_226 ( struct V_115 * V_122 )
{
struct V_115 * V_27 ;
V_27 = F_180 ( V_122 -> V_10 ) ;
F_23 ( V_27 != V_122 ) ;
F_78 ( V_122 ) ;
}
static struct V_34 * F_227 ( struct V_35 * V_36 )
{
return V_36 ? F_52 ( V_36 , struct V_34 , V_35 ) : NULL ;
}
static bool F_228 ( unsigned long V_11 ,
struct V_34 * * V_168 ,
struct V_34 * * V_169 )
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
* V_168 = V_38 ;
* V_169 = F_227 ( F_57 ( & ( * V_168 ) -> V_35 ) ) ;
} else {
* V_169 = V_38 ;
* V_168 = F_227 ( F_229 ( & ( * V_169 ) -> V_35 ) ) ;
}
return true ;
}
static unsigned long F_230 ( struct V_34 * * V_168 ,
struct V_34 * * V_169 ,
unsigned long V_47 )
{
const unsigned long V_170 = V_72 & ~ ( V_47 - 1 ) ;
unsigned long V_10 ;
if ( * V_168 )
V_10 = F_146 ( ( * V_168 ) -> va_start & ~ ( V_47 - 1 ) , V_170 ) ;
else
V_10 = V_170 ;
while ( * V_169 && ( * V_169 ) -> va_end > V_10 ) {
* V_168 = * V_169 ;
* V_169 = F_227 ( F_57 ( & ( * V_168 ) -> V_35 ) ) ;
}
return V_10 ;
}
struct V_115 * * F_231 ( const unsigned long * V_171 ,
const T_8 * V_172 , int V_173 ,
T_8 V_47 )
{
const unsigned long V_174 = F_69 ( V_71 , V_47 ) ;
const unsigned long V_170 = V_72 & ~ ( V_47 - 1 ) ;
struct V_34 * * V_175 , * V_44 , * V_17 ;
struct V_115 * * V_176 ;
int V_122 , V_177 , V_178 , V_179 ;
unsigned long V_180 , V_25 , V_11 , V_181 ;
bool V_52 = false ;
F_23 ( F_60 ( V_47 ) || ! F_61 ( V_47 ) ) ;
for ( V_178 = 0 , V_122 = 0 ; V_122 < V_173 ; V_122 ++ ) {
V_25 = V_171 [ V_122 ] ;
V_11 = V_25 + V_172 [ V_122 ] ;
F_23 ( ! F_73 ( V_171 [ V_122 ] , V_47 ) ) ;
F_23 ( ! F_73 ( V_172 [ V_122 ] , V_47 ) ) ;
if ( V_25 > V_171 [ V_178 ] )
V_178 = V_122 ;
for ( V_177 = 0 ; V_177 < V_173 ; V_177 ++ ) {
unsigned long V_182 = V_171 [ V_177 ] ;
unsigned long V_183 = V_182 + V_172 [ V_177 ] ;
if ( V_177 == V_122 )
continue;
F_23 ( V_182 >= V_25 && V_182 < V_11 ) ;
F_23 ( V_183 <= V_11 && V_183 > V_25 ) ;
}
}
V_181 = V_171 [ V_178 ] + V_172 [ V_178 ] ;
if ( V_170 - V_174 < V_181 ) {
F_9 ( true ) ;
return NULL ;
}
V_176 = F_232 ( V_173 , sizeof( V_176 [ 0 ] ) , V_114 ) ;
V_175 = F_232 ( V_173 , sizeof( V_175 [ 0 ] ) , V_114 ) ;
if ( ! V_175 || ! V_176 )
goto V_184;
for ( V_122 = 0 ; V_122 < V_173 ; V_122 ++ ) {
V_175 [ V_122 ] = F_159 ( sizeof( struct V_34 ) , V_114 ) ;
V_176 [ V_122 ] = F_159 ( sizeof( struct V_115 ) , V_114 ) ;
if ( ! V_175 [ V_122 ] || ! V_176 [ V_122 ] )
goto V_185;
}
V_56:
F_68 ( & V_57 ) ;
V_122 = V_179 = V_178 ;
V_25 = V_171 [ V_122 ] ;
V_11 = V_25 + V_172 [ V_122 ] ;
if ( ! F_228 ( V_73 , & V_17 , & V_44 ) ) {
V_180 = V_170 - V_181 ;
goto V_64;
}
V_180 = F_230 ( & V_17 , & V_44 , V_47 ) - V_11 ;
while ( true ) {
F_23 ( V_17 && V_17 -> va_end <= V_180 + V_11 ) ;
F_23 ( V_44 && V_44 -> va_end > V_180 + V_11 ) ;
if ( V_180 + V_181 < V_174 + V_181 ) {
F_72 ( & V_57 ) ;
if ( ! V_52 ) {
F_74 () ;
V_52 = true ;
goto V_56;
}
goto V_185;
}
if ( V_17 && V_17 -> va_start < V_180 + V_11 ) {
V_180 = F_230 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_179 = V_122 ;
continue;
}
if ( V_44 && V_44 -> va_end > V_180 + V_25 ) {
V_17 = V_44 ;
V_44 = F_227 ( F_57 ( & V_17 -> V_35 ) ) ;
V_180 = F_230 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_179 = V_122 ;
continue;
}
V_122 = ( V_122 + V_173 - 1 ) % V_173 ;
if ( V_122 == V_179 )
break;
V_25 = V_171 [ V_122 ] ;
V_11 = V_25 + V_172 [ V_122 ] ;
F_228 ( V_180 + V_11 , & V_17 , & V_44 ) ;
}
V_64:
for ( V_122 = 0 ; V_122 < V_173 ; V_122 ++ ) {
struct V_34 * V_38 = V_175 [ V_122 ] ;
V_38 -> va_start = V_180 + V_171 [ V_122 ] ;
V_38 -> va_end = V_38 -> va_start + V_172 [ V_122 ] ;
F_53 ( V_38 ) ;
}
V_73 = V_180 + V_171 [ V_178 ] ;
F_72 ( & V_57 ) ;
for ( V_122 = 0 ; V_122 < V_173 ; V_122 ++ )
F_165 ( V_176 [ V_122 ] , V_175 [ V_122 ] , V_143 ,
F_231 ) ;
F_78 ( V_175 ) ;
return V_176 ;
V_185:
for ( V_122 = 0 ; V_122 < V_173 ; V_122 ++ ) {
F_78 ( V_175 [ V_122 ] ) ;
F_78 ( V_176 [ V_122 ] ) ;
}
V_184:
F_78 ( V_175 ) ;
F_78 ( V_176 ) ;
return NULL ;
}
void F_233 ( struct V_115 * * V_176 , int V_173 )
{
int V_119 ;
for ( V_119 = 0 ; V_119 < V_173 ; V_119 ++ )
F_226 ( V_176 [ V_119 ] ) ;
F_78 ( V_176 ) ;
}
static void * F_234 ( struct V_186 * V_187 , T_11 * V_188 )
__acquires( &vmap_area_lock
static void * F_235 ( struct V_186 * V_187 , void * V_4 , T_11 * V_188 )
{
struct V_34 * V_38 = V_4 , * V_17 ;
++ * V_188 ;
V_17 = F_71 ( V_38 , V_8 ) ;
if ( & V_17 -> V_8 != & V_45 )
return V_17 ;
return NULL ;
}
static void F_236 ( struct V_186 * V_187 , void * V_4 )
__releases( &vmap_area_lock
static void F_237 ( struct V_186 * V_187 , struct V_115 * V_189 )
{
if ( F_238 ( V_190 ) ) {
unsigned int V_22 , * V_191 = V_187 -> V_192 ;
if ( ! V_191 )
return;
if ( V_189 -> V_65 & V_124 )
return;
F_239 () ;
memset ( V_191 , 0 , V_193 * sizeof( unsigned int ) ) ;
for ( V_22 = 0 ; V_22 < V_189 -> V_131 ; V_22 ++ )
V_191 [ F_240 ( V_189 -> V_21 [ V_22 ] ) ] ++ ;
F_241 (nr, N_HIGH_MEMORY)
if ( V_191 [ V_22 ] )
F_242 ( V_187 , L_6 , V_22 , V_191 [ V_22 ] ) ;
}
}
static int F_243 ( struct V_186 * V_187 , void * V_4 )
{
struct V_34 * V_38 = V_4 ;
struct V_115 * V_189 ;
if ( ! ( V_38 -> V_65 & V_121 ) )
return 0 ;
V_189 = V_38 -> V_116 ;
F_242 ( V_187 , L_7 ,
V_189 -> V_10 , V_189 -> V_10 + V_189 -> V_46 , V_189 -> V_46 ) ;
if ( V_189 -> V_123 )
F_242 ( V_187 , L_8 , V_189 -> V_123 ) ;
if ( V_189 -> V_131 )
F_242 ( V_187 , L_9 , V_189 -> V_131 ) ;
if ( V_189 -> V_194 )
F_242 ( V_187 , L_10 , ( unsigned long long ) V_189 -> V_194 ) ;
if ( V_189 -> V_65 & V_125 )
F_244 ( V_187 , L_11 ) ;
if ( V_189 -> V_65 & V_143 )
F_244 ( V_187 , L_12 ) ;
if ( V_189 -> V_65 & V_195 )
F_244 ( V_187 , L_13 ) ;
if ( V_189 -> V_65 & V_145 )
F_244 ( V_187 , L_14 ) ;
if ( F_40 ( V_189 -> V_21 ) )
F_244 ( V_187 , L_15 ) ;
F_237 ( V_187 , V_189 ) ;
F_245 ( V_187 , '\n' ) ;
return 0 ;
}
static int F_246 ( struct V_196 * V_196 , struct V_197 * V_197 )
{
if ( F_238 ( V_190 ) )
return F_247 ( V_197 , & V_198 ,
V_193 * sizeof( unsigned int ) ) ;
else
return F_248 ( V_197 , & V_198 ) ;
}
static int T_7 F_249 ( void )
{
F_250 ( L_16 , V_199 , NULL , & V_200 ) ;
return 0 ;
}
