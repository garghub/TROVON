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
F_62 () ;
V_38 = F_63 ( sizeof( struct V_34 ) ,
V_51 & V_54 , V_50 ) ;
if ( F_64 ( ! V_38 ) )
return F_65 ( - V_23 ) ;
F_66 ( & V_38 -> V_35 , V_55 , V_51 & V_54 ) ;
V_56:
F_67 ( & V_57 ) ;
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
V_10 = F_68 ( V_53 -> va_end , V_47 ) ;
if ( V_10 < V_48 )
goto V_62;
if ( V_10 + V_46 < V_10 )
goto V_63;
} else {
V_10 = F_68 ( V_48 , V_47 ) ;
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
V_10 = F_68 ( V_53 -> va_end , V_47 ) ;
if ( V_10 + V_46 < V_10 )
goto V_63;
if ( F_69 ( & V_53 -> V_8 , & V_45 ) )
goto V_64;
V_53 = F_70 ( V_53 , V_8 ) ;
}
V_64:
if ( V_10 + V_46 > V_49 )
goto V_63;
V_38 -> va_start = V_10 ;
V_38 -> va_end = V_10 + V_46 ;
V_38 -> V_65 = 0 ;
F_53 ( V_38 ) ;
V_58 = & V_38 -> V_35 ;
F_71 ( & V_57 ) ;
F_23 ( ! F_72 ( V_38 -> va_start , V_47 ) ) ;
F_23 ( V_38 -> va_start < V_48 ) ;
F_23 ( V_38 -> va_end > V_49 ) ;
return V_38 ;
V_63:
F_71 ( & V_57 ) ;
if ( ! V_52 ) {
F_73 () ;
V_52 = 1 ;
goto V_56;
}
if ( F_74 ( V_51 ) ) {
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
return F_65 ( - V_24 ) ;
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
F_67 ( & V_57 ) ;
F_83 ( V_38 ) ;
F_71 ( & V_57 ) ;
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
static bool F_100 ( unsigned long V_25 , unsigned long V_11 )
{
struct V_6 * V_76 ;
struct V_34 * V_38 ;
struct V_34 * V_77 ;
bool V_78 = false ;
F_101 ( & V_79 ) ;
V_76 = F_3 ( & V_80 ) ;
F_102 (va, valist, purge_list) {
if ( V_38 -> va_start < V_25 )
V_25 = V_38 -> va_start ;
if ( V_38 -> va_end > V_11 )
V_11 = V_38 -> va_end ;
V_78 = true ;
}
if ( ! V_78 )
return false ;
F_94 ( V_25 , V_11 ) ;
F_67 ( & V_57 ) ;
F_103 (va, n_va, valist, purge_list) {
int V_22 = ( V_38 -> va_end - V_38 -> va_start ) >> V_81 ;
F_83 ( V_38 ) ;
F_104 ( V_22 , & V_75 ) ;
F_105 ( & V_57 ) ;
}
F_71 ( & V_57 ) ;
return true ;
}
static void F_106 ( void )
{
if ( F_107 ( & V_79 ) ) {
F_100 ( V_82 , 0 ) ;
F_108 ( & V_79 ) ;
}
}
static void F_73 ( void )
{
F_109 ( & V_79 ) ;
F_110 () ;
F_100 ( V_82 , 0 ) ;
F_108 ( & V_79 ) ;
}
static void F_111 ( struct V_34 * V_38 )
{
int V_83 ;
V_83 = F_112 ( ( V_38 -> va_end - V_38 -> va_start ) >> V_81 ,
& V_75 ) ;
F_113 ( & V_38 -> V_84 , & V_80 ) ;
if ( F_64 ( V_83 > F_95 () ) )
F_106 () ;
}
static void F_114 ( struct V_34 * V_38 )
{
F_115 ( V_38 -> va_start , V_38 -> va_end ) ;
F_91 ( V_38 ) ;
F_111 ( V_38 ) ;
}
static struct V_34 * F_116 ( unsigned long V_10 )
{
struct V_34 * V_38 ;
F_67 ( & V_57 ) ;
V_38 = F_51 ( V_10 ) ;
F_71 ( & V_57 ) ;
return V_38 ;
}
static unsigned long F_117 ( unsigned long V_10 )
{
V_10 -= V_71 & ~ ( V_85 - 1 ) ;
V_10 /= V_85 ;
return V_10 ;
}
static void * F_118 ( unsigned long va_start , unsigned long V_86 )
{
unsigned long V_10 ;
V_10 = va_start + ( V_86 << V_81 ) ;
F_23 ( F_117 ( V_10 ) != F_117 ( va_start ) ) ;
return ( void * ) V_10 ;
}
static void * F_119 ( unsigned int V_87 , T_6 V_51 )
{
struct V_88 * V_89 ;
struct V_90 * V_91 ;
struct V_34 * V_38 ;
unsigned long V_92 ;
int V_50 , V_26 ;
void * V_93 ;
V_50 = F_120 () ;
V_91 = F_63 ( sizeof( struct V_90 ) ,
V_51 & V_54 , V_50 ) ;
if ( F_64 ( ! V_91 ) )
return F_65 ( - V_23 ) ;
V_38 = F_59 ( V_85 , V_85 ,
V_71 , V_72 ,
V_50 , V_51 ) ;
if ( F_121 ( V_38 ) ) {
F_78 ( V_91 ) ;
return F_122 ( V_38 ) ;
}
V_26 = F_123 ( V_51 ) ;
if ( F_64 ( V_26 ) ) {
F_78 ( V_91 ) ;
F_90 ( V_38 ) ;
return F_65 ( V_26 ) ;
}
V_93 = F_118 ( V_38 -> va_start , 0 ) ;
F_124 ( & V_91 -> V_94 ) ;
V_91 -> V_38 = V_38 ;
F_23 ( V_95 <= ( 1UL << V_87 ) ) ;
V_91 -> free = V_95 - ( 1UL << V_87 ) ;
V_91 -> V_96 = 0 ;
V_91 -> V_97 = V_95 ;
V_91 -> V_98 = 0 ;
F_125 ( & V_91 -> V_99 ) ;
V_92 = F_117 ( V_38 -> va_start ) ;
F_67 ( & V_100 ) ;
V_26 = F_126 ( & V_101 , V_92 , V_91 ) ;
F_71 ( & V_100 ) ;
F_23 ( V_26 ) ;
F_127 () ;
V_89 = & F_128 ( V_88 ) ;
F_67 ( & V_89 -> V_94 ) ;
F_129 ( & V_91 -> V_99 , & V_89 -> free ) ;
F_71 ( & V_89 -> V_94 ) ;
F_130 ( V_88 ) ;
return V_93 ;
}
static void F_131 ( struct V_90 * V_91 )
{
struct V_90 * V_42 ;
unsigned long V_92 ;
V_92 = F_117 ( V_91 -> V_38 -> va_start ) ;
F_67 ( & V_100 ) ;
V_42 = F_132 ( & V_101 , V_92 ) ;
F_71 ( & V_100 ) ;
F_23 ( V_42 != V_91 ) ;
F_111 ( V_91 -> V_38 ) ;
F_89 ( V_91 , V_74 ) ;
}
static void F_133 ( int V_102 )
{
F_134 ( V_103 ) ;
struct V_90 * V_91 ;
struct V_90 * V_104 ;
struct V_88 * V_89 = & F_135 ( V_88 , V_102 ) ;
F_136 () ;
F_137 (vb, &vbq->free, free_list) {
if ( ! ( V_91 -> free + V_91 -> V_96 == V_95 && V_91 -> V_96 != V_95 ) )
continue;
F_67 ( & V_91 -> V_94 ) ;
if ( V_91 -> free + V_91 -> V_96 == V_95 && V_91 -> V_96 != V_95 ) {
V_91 -> free = 0 ;
V_91 -> V_96 = V_95 ;
V_91 -> V_97 = 0 ;
V_91 -> V_98 = V_95 ;
F_67 ( & V_89 -> V_94 ) ;
F_87 ( & V_91 -> V_99 ) ;
F_71 ( & V_89 -> V_94 ) ;
F_71 ( & V_91 -> V_94 ) ;
F_138 ( & V_91 -> V_103 , & V_103 ) ;
} else
F_71 ( & V_91 -> V_94 ) ;
}
F_139 () ;
F_140 (vb, n_vb, &purge, purge) {
F_141 ( & V_91 -> V_103 ) ;
F_131 ( V_91 ) ;
}
}
static void F_110 ( void )
{
int V_102 ;
F_142 (cpu)
F_133 ( V_102 ) ;
}
static void * F_143 ( unsigned long V_46 , T_6 V_51 )
{
struct V_88 * V_89 ;
struct V_90 * V_91 ;
void * V_93 = NULL ;
unsigned int V_87 ;
F_23 ( F_60 ( V_46 ) ) ;
F_23 ( V_46 > V_15 * V_105 ) ;
if ( F_9 ( V_46 == 0 ) ) {
return NULL ;
}
V_87 = F_144 ( V_46 ) ;
F_136 () ;
V_89 = & F_128 ( V_88 ) ;
F_137 (vb, &vbq->free, free_list) {
unsigned long V_86 ;
F_67 ( & V_91 -> V_94 ) ;
if ( V_91 -> free < ( 1UL << V_87 ) ) {
F_71 ( & V_91 -> V_94 ) ;
continue;
}
V_86 = V_95 - V_91 -> free ;
V_93 = F_118 ( V_91 -> V_38 -> va_start , V_86 ) ;
V_91 -> free -= 1UL << V_87 ;
if ( V_91 -> free == 0 ) {
F_67 ( & V_89 -> V_94 ) ;
F_87 ( & V_91 -> V_99 ) ;
F_71 ( & V_89 -> V_94 ) ;
}
F_71 ( & V_91 -> V_94 ) ;
break;
}
F_130 ( V_88 ) ;
F_139 () ;
if ( ! V_93 )
V_93 = F_119 ( V_87 , V_51 ) ;
return V_93 ;
}
static void F_145 ( const void * V_10 , unsigned long V_46 )
{
unsigned long V_106 ;
unsigned long V_92 ;
unsigned int V_87 ;
struct V_90 * V_91 ;
F_23 ( F_60 ( V_46 ) ) ;
F_23 ( V_46 > V_15 * V_105 ) ;
F_115 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
V_87 = F_144 ( V_46 ) ;
V_106 = ( unsigned long ) V_10 & ( V_85 - 1 ) ;
V_106 >>= V_81 ;
V_92 = F_117 ( ( unsigned long ) V_10 ) ;
F_136 () ;
V_91 = F_146 ( & V_101 , V_92 ) ;
F_139 () ;
F_23 ( ! V_91 ) ;
F_22 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_46 ) ;
F_67 ( & V_91 -> V_94 ) ;
V_91 -> V_97 = F_147 ( V_91 -> V_97 , V_106 ) ;
V_91 -> V_98 = F_88 ( V_91 -> V_98 , V_106 + ( 1UL << V_87 ) ) ;
V_91 -> V_96 += 1UL << V_87 ;
if ( V_91 -> V_96 == V_95 ) {
F_23 ( V_91 -> free ) ;
F_71 ( & V_91 -> V_94 ) ;
F_131 ( V_91 ) ;
} else
F_71 ( & V_91 -> V_94 ) ;
}
void F_148 ( void )
{
unsigned long V_25 = V_82 , V_11 = 0 ;
int V_102 ;
int V_107 = 0 ;
if ( F_64 ( ! V_108 ) )
return;
F_62 () ;
F_142 (cpu) {
struct V_88 * V_89 = & F_135 ( V_88 , V_102 ) ;
struct V_90 * V_91 ;
F_136 () ;
F_137 (vb, &vbq->free, free_list) {
F_67 ( & V_91 -> V_94 ) ;
if ( V_91 -> V_96 ) {
unsigned long va_start = V_91 -> V_38 -> va_start ;
unsigned long V_109 , V_110 ;
V_109 = va_start + ( V_91 -> V_97 << V_81 ) ;
V_110 = va_start + ( V_91 -> V_98 << V_81 ) ;
V_25 = F_147 ( V_109 , V_25 ) ;
V_11 = F_88 ( V_110 , V_11 ) ;
V_107 = 1 ;
}
F_71 ( & V_91 -> V_94 ) ;
}
F_139 () ;
}
F_109 ( & V_79 ) ;
F_110 () ;
if ( ! F_100 ( V_25 , V_11 ) && V_107 )
F_94 ( V_25 , V_11 ) ;
F_108 ( & V_79 ) ;
}
void F_149 ( const void * V_111 , unsigned int V_112 )
{
unsigned long V_46 = ( unsigned long ) V_112 << V_81 ;
unsigned long V_10 = ( unsigned long ) V_111 ;
struct V_34 * V_38 ;
F_62 () ;
F_23 ( ! V_10 ) ;
F_23 ( V_10 < V_71 ) ;
F_23 ( V_10 > V_72 ) ;
F_23 ( ! F_150 ( V_10 ) ) ;
F_151 ( V_111 , V_46 ) ;
F_92 ( V_10 , V_10 + V_46 ) ;
if ( F_152 ( V_112 <= V_105 ) ) {
F_145 ( V_111 , V_46 ) ;
return;
}
V_38 = F_116 ( V_10 ) ;
F_23 ( ! V_38 ) ;
F_114 ( V_38 ) ;
}
void * F_153 ( struct V_20 * * V_21 , unsigned int V_112 , int V_50 , T_5 V_19 )
{
unsigned long V_46 = ( unsigned long ) V_112 << V_81 ;
unsigned long V_10 ;
void * V_111 ;
if ( F_152 ( V_112 <= V_105 ) ) {
V_111 = F_143 ( V_46 , V_113 ) ;
if ( F_121 ( V_111 ) )
return NULL ;
V_10 = ( unsigned long ) V_111 ;
} else {
struct V_34 * V_38 ;
V_38 = F_59 ( V_46 , V_15 ,
V_71 , V_72 , V_50 , V_113 ) ;
if ( F_121 ( V_38 ) )
return NULL ;
V_10 = V_38 -> va_start ;
V_111 = ( void * ) V_10 ;
}
if ( F_36 ( V_10 , V_10 + V_46 , V_19 , V_21 ) < 0 ) {
F_149 ( V_111 , V_112 ) ;
return NULL ;
}
return V_111 ;
}
void T_7 F_154 ( struct V_114 * V_115 )
{
struct V_114 * V_42 , * * V_4 ;
F_23 ( V_108 ) ;
for ( V_4 = & V_116 ; ( V_42 = * V_4 ) != NULL ; V_4 = & V_42 -> V_17 ) {
if ( V_42 -> V_10 >= V_115 -> V_10 ) {
F_23 ( V_42 -> V_10 < V_115 -> V_10 + V_115 -> V_46 ) ;
break;
} else
F_23 ( V_42 -> V_10 + V_42 -> V_46 > V_115 -> V_10 ) ;
}
V_115 -> V_17 = * V_4 ;
* V_4 = V_115 ;
}
void T_7 F_155 ( struct V_114 * V_115 , T_8 V_47 )
{
static T_8 T_9 V_117 ;
unsigned long V_10 ;
V_10 = F_68 ( V_71 + T_9 , V_47 ) ;
T_9 = F_156 ( V_10 + V_115 -> V_46 ) - V_71 ;
V_115 -> V_10 = ( void * ) V_10 ;
F_154 ( V_115 ) ;
}
void T_7 F_157 ( void )
{
struct V_34 * V_38 ;
struct V_114 * V_42 ;
int V_118 ;
F_142 (i) {
struct V_88 * V_89 ;
struct V_3 * V_4 ;
V_89 = & F_135 ( V_88 , V_118 ) ;
F_124 ( & V_89 -> V_94 ) ;
F_125 ( & V_89 -> free ) ;
V_4 = & F_135 ( V_3 , V_118 ) ;
F_158 ( & V_4 -> V_8 ) ;
F_159 ( & V_4 -> V_5 , F_1 ) ;
}
for ( V_42 = V_116 ; V_42 ; V_42 = V_42 -> V_17 ) {
V_38 = F_160 ( sizeof( struct V_34 ) , V_119 ) ;
V_38 -> V_65 = V_120 ;
V_38 -> va_start = ( unsigned long ) V_42 -> V_10 ;
V_38 -> va_end = V_38 -> va_start + V_42 -> V_46 ;
V_38 -> V_115 = V_42 ;
F_53 ( V_38 ) ;
}
V_73 = V_72 ;
V_108 = true ;
}
int F_161 ( unsigned long V_10 , unsigned long V_46 ,
T_5 V_19 , struct V_20 * * V_21 )
{
return F_35 ( V_10 , V_10 + V_46 , V_19 , V_21 ) ;
}
void F_162 ( unsigned long V_10 , unsigned long V_46 )
{
F_22 ( V_10 , V_10 + V_46 ) ;
}
void F_163 ( unsigned long V_10 , unsigned long V_46 )
{
unsigned long V_11 = V_10 + V_46 ;
F_115 ( V_10 , V_11 ) ;
F_22 ( V_10 , V_11 ) ;
F_94 ( V_10 , V_11 ) ;
}
int F_164 ( struct V_114 * V_121 , T_5 V_19 , struct V_20 * * V_21 )
{
unsigned long V_10 = ( unsigned long ) V_121 -> V_10 ;
unsigned long V_11 = V_10 + F_165 ( V_121 ) ;
int V_26 ;
V_26 = F_36 ( V_10 , V_11 , V_19 , V_21 ) ;
return V_26 > 0 ? 0 : V_26 ;
}
static void F_166 ( struct V_114 * V_115 , struct V_34 * V_38 ,
unsigned long V_65 , const void * V_122 )
{
F_67 ( & V_57 ) ;
V_115 -> V_65 = V_65 ;
V_115 -> V_10 = ( void * ) V_38 -> va_start ;
V_115 -> V_46 = V_38 -> va_end - V_38 -> va_start ;
V_115 -> V_122 = V_122 ;
V_38 -> V_115 = V_115 ;
V_38 -> V_65 |= V_120 ;
F_71 ( & V_57 ) ;
}
static void F_167 ( struct V_114 * V_115 )
{
F_168 () ;
V_115 -> V_65 &= ~ V_123 ;
}
static struct V_114 * F_169 ( unsigned long V_46 ,
unsigned long V_47 , unsigned long V_65 , unsigned long V_25 ,
unsigned long V_11 , int V_50 , T_6 V_51 , const void * V_122 )
{
struct V_34 * V_38 ;
struct V_114 * V_121 ;
F_23 ( F_170 () ) ;
V_46 = F_171 ( V_46 ) ;
if ( F_64 ( ! V_46 ) )
return NULL ;
if ( V_65 & V_124 )
V_47 = 1ul << F_172 ( int , F_173 ( V_46 ) ,
V_81 , V_125 ) ;
V_121 = F_174 ( sizeof( * V_121 ) , V_51 & V_54 , V_50 ) ;
if ( F_64 ( ! V_121 ) )
return NULL ;
if ( ! ( V_65 & V_126 ) )
V_46 += V_15 ;
V_38 = F_59 ( V_46 , V_47 , V_25 , V_11 , V_50 , V_51 ) ;
if ( F_121 ( V_38 ) ) {
F_78 ( V_121 ) ;
return NULL ;
}
F_166 ( V_121 , V_38 , V_65 , V_122 ) ;
return V_121 ;
}
struct V_114 * F_175 ( unsigned long V_46 , unsigned long V_65 ,
unsigned long V_25 , unsigned long V_11 )
{
return F_169 ( V_46 , 1 , V_65 , V_25 , V_11 , V_127 ,
V_113 , F_176 ( 0 ) ) ;
}
struct V_114 * F_177 ( unsigned long V_46 , unsigned long V_65 ,
unsigned long V_25 , unsigned long V_11 ,
const void * V_122 )
{
return F_169 ( V_46 , 1 , V_65 , V_25 , V_11 , V_127 ,
V_113 , V_122 ) ;
}
struct V_114 * F_178 ( unsigned long V_46 , unsigned long V_65 )
{
return F_169 ( V_46 , 1 , V_65 , V_71 , V_72 ,
V_127 , V_113 ,
F_176 ( 0 ) ) ;
}
struct V_114 * F_179 ( unsigned long V_46 , unsigned long V_65 ,
const void * V_122 )
{
return F_169 ( V_46 , 1 , V_65 , V_71 , V_72 ,
V_127 , V_113 , V_122 ) ;
}
struct V_114 * F_180 ( const void * V_10 )
{
struct V_34 * V_38 ;
V_38 = F_116 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_65 & V_120 )
return V_38 -> V_115 ;
return NULL ;
}
struct V_114 * F_181 ( const void * V_10 )
{
struct V_34 * V_38 ;
F_62 () ;
V_38 = F_116 ( ( unsigned long ) V_10 ) ;
if ( V_38 && V_38 -> V_65 & V_120 ) {
struct V_114 * V_115 = V_38 -> V_115 ;
F_67 ( & V_57 ) ;
V_38 -> V_115 = NULL ;
V_38 -> V_65 &= ~ V_120 ;
F_71 ( & V_57 ) ;
F_92 ( V_38 -> va_start , V_38 -> va_end ) ;
F_182 ( V_115 ) ;
F_114 ( V_38 ) ;
return V_115 ;
}
return NULL ;
}
static void F_5 ( const void * V_10 , int V_128 )
{
struct V_114 * V_121 ;
if ( ! V_10 )
return;
if ( F_183 ( ! F_150 ( V_10 ) , L_2 ,
V_10 ) )
return;
V_121 = F_181 ( V_10 ) ;
if ( F_64 ( ! V_121 ) ) {
F_183 ( 1 , V_129 L_3 ,
V_10 ) ;
return;
}
F_151 ( V_10 , F_165 ( V_121 ) ) ;
F_184 ( V_10 , F_165 ( V_121 ) ) ;
if ( V_128 ) {
int V_118 ;
for ( V_118 = 0 ; V_118 < V_121 -> V_130 ; V_118 ++ ) {
struct V_20 * V_20 = V_121 -> V_21 [ V_118 ] ;
F_23 ( ! V_20 ) ;
F_185 ( V_20 , 0 ) ;
}
F_186 ( V_121 -> V_21 ) ;
}
F_78 ( V_121 ) ;
return;
}
static inline void F_187 ( const void * V_10 )
{
struct V_3 * V_4 = F_188 ( & V_3 ) ;
if ( F_113 ( (struct V_6 * ) V_10 , & V_4 -> V_8 ) )
F_189 ( & V_4 -> V_5 ) ;
}
void F_190 ( const void * V_10 )
{
F_23 ( F_191 () ) ;
F_192 ( V_10 ) ;
if ( ! V_10 )
return;
F_187 ( V_10 ) ;
}
void F_193 ( const void * V_10 )
{
F_23 ( F_191 () ) ;
F_192 ( V_10 ) ;
if ( ! V_10 )
return;
if ( F_64 ( F_170 () ) )
F_187 ( V_10 ) ;
else
F_5 ( V_10 , 1 ) ;
}
void F_194 ( const void * V_10 )
{
F_23 ( F_170 () ) ;
F_62 () ;
if ( V_10 )
F_5 ( V_10 , 0 ) ;
}
void * F_195 ( struct V_20 * * V_21 , unsigned int V_112 ,
unsigned long V_65 , T_5 V_19 )
{
struct V_114 * V_121 ;
unsigned long V_46 ;
F_62 () ;
if ( V_112 > V_131 )
return NULL ;
V_46 = ( unsigned long ) V_112 << V_81 ;
V_121 = F_179 ( V_46 , V_65 , F_176 ( 0 ) ) ;
if ( ! V_121 )
return NULL ;
if ( F_164 ( V_121 , V_19 , V_21 ) ) {
F_194 ( V_121 -> V_10 ) ;
return NULL ;
}
return V_121 -> V_10 ;
}
static void * F_196 ( struct V_114 * V_121 , T_6 V_51 ,
T_5 V_19 , int V_50 )
{
struct V_20 * * V_21 ;
unsigned int V_130 , V_132 , V_118 ;
const T_6 V_133 = ( V_51 & V_54 ) | V_134 ;
const T_6 V_135 = V_51 | V_136 ;
V_130 = F_165 ( V_121 ) >> V_81 ;
V_132 = ( V_130 * sizeof( struct V_20 * ) ) ;
V_121 -> V_130 = V_130 ;
if ( V_132 > V_15 ) {
V_21 = F_197 ( V_132 , 1 , V_133 | V_137 ,
V_138 , V_50 , V_121 -> V_122 ) ;
} else {
V_21 = F_63 ( V_132 , V_133 , V_50 ) ;
}
V_121 -> V_21 = V_21 ;
if ( ! V_121 -> V_21 ) {
F_181 ( V_121 -> V_10 ) ;
F_78 ( V_121 ) ;
return NULL ;
}
for ( V_118 = 0 ; V_118 < V_121 -> V_130 ; V_118 ++ ) {
struct V_20 * V_20 ;
if ( V_50 == V_127 )
V_20 = F_198 ( V_135 ) ;
else
V_20 = F_199 ( V_50 , V_135 , 0 ) ;
if ( F_64 ( ! V_20 ) ) {
V_121 -> V_130 = V_118 ;
goto V_139;
}
V_121 -> V_21 [ V_118 ] = V_20 ;
if ( F_74 ( V_51 ) )
F_200 () ;
}
if ( F_164 ( V_121 , V_19 , V_21 ) )
goto V_139;
return V_121 -> V_10 ;
V_139:
F_201 ( V_51 ,
L_4 ,
( V_121 -> V_130 * V_15 ) , V_121 -> V_46 ) ;
F_193 ( V_121 -> V_10 ) ;
return NULL ;
}
void * F_202 ( unsigned long V_46 , unsigned long V_47 ,
unsigned long V_25 , unsigned long V_11 , T_6 V_51 ,
T_5 V_19 , unsigned long V_140 , int V_50 ,
const void * V_122 )
{
struct V_114 * V_121 ;
void * V_10 ;
unsigned long V_141 = V_46 ;
V_46 = F_171 ( V_46 ) ;
if ( ! V_46 || ( V_46 >> V_81 ) > V_131 )
goto V_139;
V_121 = F_169 ( V_46 , V_47 , V_142 | V_123 |
V_140 , V_25 , V_11 , V_50 , V_51 , V_122 ) ;
if ( ! V_121 )
goto V_139;
V_10 = F_196 ( V_121 , V_51 , V_19 , V_50 ) ;
if ( ! V_10 )
return NULL ;
F_167 ( V_121 ) ;
F_203 ( V_10 , V_141 , 2 , V_51 ) ;
return V_10 ;
V_139:
F_201 ( V_51 ,
L_5 , V_141 ) ;
return NULL ;
}
static void * F_197 ( unsigned long V_46 , unsigned long V_47 ,
T_6 V_51 , T_5 V_19 ,
int V_50 , const void * V_122 )
{
return F_202 ( V_46 , V_47 , V_71 , V_72 ,
V_51 , V_19 , 0 , V_50 , V_122 ) ;
}
void * F_204 ( unsigned long V_46 , T_6 V_51 , T_5 V_19 )
{
return F_197 ( V_46 , 1 , V_51 , V_19 , V_127 ,
F_176 ( 0 ) ) ;
}
static inline void * F_205 ( unsigned long V_46 ,
int V_50 , T_6 V_65 )
{
return F_197 ( V_46 , 1 , V_65 , V_138 ,
V_50 , F_176 ( 0 ) ) ;
}
void * F_206 ( unsigned long V_46 )
{
return F_205 ( V_46 , V_127 ,
V_113 | V_137 ) ;
}
void * F_207 ( unsigned long V_46 )
{
return F_205 ( V_46 , V_127 ,
V_113 | V_137 | V_134 ) ;
}
void * F_208 ( unsigned long V_46 )
{
struct V_114 * V_121 ;
void * V_27 ;
V_27 = F_197 ( V_46 , V_143 ,
V_113 | V_137 | V_134 ,
V_138 , V_127 ,
F_176 ( 0 ) ) ;
if ( V_27 ) {
V_121 = F_180 ( V_27 ) ;
V_121 -> V_65 |= V_144 ;
}
return V_27 ;
}
void * F_209 ( unsigned long V_46 , int V_50 )
{
return F_197 ( V_46 , 1 , V_113 | V_137 , V_138 ,
V_50 , F_176 ( 0 ) ) ;
}
void * F_210 ( unsigned long V_46 , int V_50 )
{
return F_205 ( V_46 , V_50 ,
V_113 | V_137 | V_134 ) ;
}
void * F_211 ( unsigned long V_46 )
{
return F_197 ( V_46 , 1 , V_113 | V_137 , V_145 ,
V_127 , F_176 ( 0 ) ) ;
}
void * F_212 ( unsigned long V_46 )
{
return F_197 ( V_46 , 1 , V_146 , V_138 ,
V_127 , F_176 ( 0 ) ) ;
}
void * F_213 ( unsigned long V_46 )
{
struct V_114 * V_121 ;
void * V_27 ;
V_27 = F_197 ( V_46 , 1 , V_146 | V_134 , V_138 ,
V_127 , F_176 ( 0 ) ) ;
if ( V_27 ) {
V_121 = F_180 ( V_27 ) ;
V_121 -> V_65 |= V_144 ;
}
return V_27 ;
}
static int F_214 ( char * V_147 , char * V_10 , unsigned long V_112 )
{
struct V_20 * V_4 ;
int V_148 = 0 ;
while ( V_112 ) {
unsigned long V_106 , V_149 ;
V_106 = F_60 ( V_10 ) ;
V_149 = V_15 - V_106 ;
if ( V_149 > V_112 )
V_149 = V_112 ;
V_4 = F_41 ( V_10 ) ;
if ( V_4 ) {
void * V_150 = F_215 ( V_4 ) ;
memcpy ( V_147 , V_150 + V_106 , V_149 ) ;
F_216 ( V_150 ) ;
} else
memset ( V_147 , 0 , V_149 ) ;
V_10 += V_149 ;
V_147 += V_149 ;
V_148 += V_149 ;
V_112 -= V_149 ;
}
return V_148 ;
}
static int F_217 ( char * V_147 , char * V_10 , unsigned long V_112 )
{
struct V_20 * V_4 ;
int V_148 = 0 ;
while ( V_112 ) {
unsigned long V_106 , V_149 ;
V_106 = F_60 ( V_10 ) ;
V_149 = V_15 - V_106 ;
if ( V_149 > V_112 )
V_149 = V_112 ;
V_4 = F_41 ( V_10 ) ;
if ( V_4 ) {
void * V_150 = F_215 ( V_4 ) ;
memcpy ( V_150 + V_106 , V_147 , V_149 ) ;
F_216 ( V_150 ) ;
}
V_10 += V_149 ;
V_147 += V_149 ;
V_148 += V_149 ;
V_112 -= V_149 ;
}
return V_148 ;
}
long F_218 ( char * V_147 , char * V_10 , unsigned long V_112 )
{
struct V_34 * V_38 ;
struct V_114 * V_115 ;
char * V_93 , * V_151 = V_147 ;
unsigned long V_152 = V_112 ;
unsigned long V_36 ;
if ( ( unsigned long ) V_10 + V_112 < V_112 )
V_112 = - ( unsigned long ) V_10 ;
F_67 ( & V_57 ) ;
F_219 (va, &vmap_area_list, list) {
if ( ! V_112 )
break;
if ( ! ( V_38 -> V_65 & V_120 ) )
continue;
V_115 = V_38 -> V_115 ;
V_93 = ( char * ) V_115 -> V_10 ;
if ( V_10 >= V_93 + F_165 ( V_115 ) )
continue;
while ( V_10 < V_93 ) {
if ( V_112 == 0 )
goto V_153;
* V_147 = '\0' ;
V_147 ++ ;
V_10 ++ ;
V_112 -- ;
}
V_36 = V_93 + F_165 ( V_115 ) - V_10 ;
if ( V_36 > V_112 )
V_36 = V_112 ;
if ( ! ( V_115 -> V_65 & V_124 ) )
F_214 ( V_147 , V_10 , V_36 ) ;
else
memset ( V_147 , 0 , V_36 ) ;
V_147 += V_36 ;
V_10 += V_36 ;
V_112 -= V_36 ;
}
V_153:
F_71 ( & V_57 ) ;
if ( V_147 == V_151 )
return 0 ;
if ( V_147 != V_151 + V_152 )
memset ( V_147 , 0 , V_152 - ( V_147 - V_151 ) ) ;
return V_152 ;
}
long F_220 ( char * V_147 , char * V_10 , unsigned long V_112 )
{
struct V_34 * V_38 ;
struct V_114 * V_115 ;
char * V_93 ;
unsigned long V_36 , V_152 ;
int V_148 = 0 ;
if ( ( unsigned long ) V_10 + V_112 < V_112 )
V_112 = - ( unsigned long ) V_10 ;
V_152 = V_112 ;
F_67 ( & V_57 ) ;
F_219 (va, &vmap_area_list, list) {
if ( ! V_112 )
break;
if ( ! ( V_38 -> V_65 & V_120 ) )
continue;
V_115 = V_38 -> V_115 ;
V_93 = ( char * ) V_115 -> V_10 ;
if ( V_10 >= V_93 + F_165 ( V_115 ) )
continue;
while ( V_10 < V_93 ) {
if ( V_112 == 0 )
goto V_153;
V_147 ++ ;
V_10 ++ ;
V_112 -- ;
}
V_36 = V_93 + F_165 ( V_115 ) - V_10 ;
if ( V_36 > V_112 )
V_36 = V_112 ;
if ( ! ( V_115 -> V_65 & V_124 ) ) {
F_217 ( V_147 , V_10 , V_36 ) ;
V_148 ++ ;
}
V_147 += V_36 ;
V_10 += V_36 ;
V_112 -= V_36 ;
}
V_153:
F_71 ( & V_57 ) ;
if ( ! V_148 )
return 0 ;
return V_152 ;
}
int F_221 ( struct V_154 * V_155 , unsigned long V_156 ,
void * V_157 , unsigned long V_46 )
{
struct V_114 * V_121 ;
V_46 = F_171 ( V_46 ) ;
if ( ! F_150 ( V_156 ) || ! F_150 ( V_157 ) )
return - V_158 ;
V_121 = F_180 ( V_157 ) ;
if ( ! V_121 )
return - V_158 ;
if ( ! ( V_121 -> V_65 & V_144 ) )
return - V_158 ;
if ( V_157 + V_46 > V_121 -> V_10 + V_121 -> V_46 )
return - V_158 ;
do {
struct V_20 * V_20 = F_41 ( V_157 ) ;
int V_27 ;
V_27 = F_222 ( V_155 , V_156 , V_20 ) ;
if ( V_27 )
return V_27 ;
V_156 += V_15 ;
V_157 += V_15 ;
V_46 -= V_15 ;
} while ( V_46 > 0 );
V_155 -> V_140 |= V_159 | V_160 ;
return 0 ;
}
int F_223 ( struct V_154 * V_155 , void * V_10 ,
unsigned long V_161 )
{
return F_221 ( V_155 , V_155 -> V_162 ,
V_10 + ( V_161 << V_81 ) ,
V_155 -> V_163 - V_155 -> V_162 ) ;
}
void __weak F_224 ( void )
{
}
static int F_225 ( T_2 * V_12 , T_10 V_164 , unsigned long V_10 , void * V_165 )
{
T_2 * * * V_4 = V_165 ;
if ( V_4 ) {
* ( * V_4 ) = V_12 ;
( * V_4 ) ++ ;
}
return 0 ;
}
struct V_114 * F_226 ( T_8 V_46 , T_2 * * V_166 )
{
struct V_114 * V_121 ;
V_121 = F_179 ( V_46 , V_124 ,
F_176 ( 0 ) ) ;
if ( V_121 == NULL )
return NULL ;
if ( F_227 ( & V_14 , ( unsigned long ) V_121 -> V_10 ,
V_46 , F_225 , V_166 ? & V_166 : NULL ) ) {
F_228 ( V_121 ) ;
return NULL ;
}
return V_121 ;
}
void F_228 ( struct V_114 * V_121 )
{
struct V_114 * V_27 ;
V_27 = F_181 ( V_121 -> V_10 ) ;
F_23 ( V_27 != V_121 ) ;
F_78 ( V_121 ) ;
}
static struct V_34 * F_229 ( struct V_35 * V_36 )
{
return V_36 ? F_52 ( V_36 , struct V_34 , V_35 ) : NULL ;
}
static bool F_230 ( unsigned long V_11 ,
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
* V_168 = F_229 ( F_57 ( & ( * V_167 ) -> V_35 ) ) ;
} else {
* V_168 = V_38 ;
* V_167 = F_229 ( F_231 ( & ( * V_168 ) -> V_35 ) ) ;
}
return true ;
}
static unsigned long F_232 ( struct V_34 * * V_167 ,
struct V_34 * * V_168 ,
unsigned long V_47 )
{
const unsigned long V_169 = V_72 & ~ ( V_47 - 1 ) ;
unsigned long V_10 ;
if ( * V_167 )
V_10 = F_147 ( ( * V_167 ) -> va_start & ~ ( V_47 - 1 ) , V_169 ) ;
else
V_10 = V_169 ;
while ( * V_168 && ( * V_168 ) -> va_end > V_10 ) {
* V_167 = * V_168 ;
* V_168 = F_229 ( F_57 ( & ( * V_167 ) -> V_35 ) ) ;
}
return V_10 ;
}
struct V_114 * * F_233 ( const unsigned long * V_170 ,
const T_8 * V_171 , int V_172 ,
T_8 V_47 )
{
const unsigned long V_173 = F_68 ( V_71 , V_47 ) ;
const unsigned long V_169 = V_72 & ~ ( V_47 - 1 ) ;
struct V_34 * * V_174 , * V_44 , * V_17 ;
struct V_114 * * V_175 ;
int V_121 , V_176 , V_177 , V_178 ;
unsigned long V_179 , V_25 , V_11 , V_180 ;
bool V_52 = false ;
F_23 ( F_60 ( V_47 ) || ! F_61 ( V_47 ) ) ;
for ( V_177 = 0 , V_121 = 0 ; V_121 < V_172 ; V_121 ++ ) {
V_25 = V_170 [ V_121 ] ;
V_11 = V_25 + V_171 [ V_121 ] ;
F_23 ( ! F_72 ( V_170 [ V_121 ] , V_47 ) ) ;
F_23 ( ! F_72 ( V_171 [ V_121 ] , V_47 ) ) ;
if ( V_25 > V_170 [ V_177 ] )
V_177 = V_121 ;
for ( V_176 = 0 ; V_176 < V_172 ; V_176 ++ ) {
unsigned long V_181 = V_170 [ V_176 ] ;
unsigned long V_182 = V_181 + V_171 [ V_176 ] ;
if ( V_176 == V_121 )
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
V_175 = F_234 ( V_172 , sizeof( V_175 [ 0 ] ) , V_113 ) ;
V_174 = F_234 ( V_172 , sizeof( V_174 [ 0 ] ) , V_113 ) ;
if ( ! V_174 || ! V_175 )
goto V_183;
for ( V_121 = 0 ; V_121 < V_172 ; V_121 ++ ) {
V_174 [ V_121 ] = F_160 ( sizeof( struct V_34 ) , V_113 ) ;
V_175 [ V_121 ] = F_160 ( sizeof( struct V_114 ) , V_113 ) ;
if ( ! V_174 [ V_121 ] || ! V_175 [ V_121 ] )
goto V_184;
}
V_56:
F_67 ( & V_57 ) ;
V_121 = V_178 = V_177 ;
V_25 = V_170 [ V_121 ] ;
V_11 = V_25 + V_171 [ V_121 ] ;
if ( ! F_230 ( V_73 , & V_17 , & V_44 ) ) {
V_179 = V_169 - V_180 ;
goto V_64;
}
V_179 = F_232 ( & V_17 , & V_44 , V_47 ) - V_11 ;
while ( true ) {
F_23 ( V_17 && V_17 -> va_end <= V_179 + V_11 ) ;
F_23 ( V_44 && V_44 -> va_end > V_179 + V_11 ) ;
if ( V_179 + V_180 < V_173 + V_180 ) {
F_71 ( & V_57 ) ;
if ( ! V_52 ) {
F_73 () ;
V_52 = true ;
goto V_56;
}
goto V_184;
}
if ( V_17 && V_17 -> va_start < V_179 + V_11 ) {
V_179 = F_232 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_178 = V_121 ;
continue;
}
if ( V_44 && V_44 -> va_end > V_179 + V_25 ) {
V_17 = V_44 ;
V_44 = F_229 ( F_57 ( & V_17 -> V_35 ) ) ;
V_179 = F_232 ( & V_17 , & V_44 , V_47 ) - V_11 ;
V_178 = V_121 ;
continue;
}
V_121 = ( V_121 + V_172 - 1 ) % V_172 ;
if ( V_121 == V_178 )
break;
V_25 = V_170 [ V_121 ] ;
V_11 = V_25 + V_171 [ V_121 ] ;
F_230 ( V_179 + V_11 , & V_17 , & V_44 ) ;
}
V_64:
for ( V_121 = 0 ; V_121 < V_172 ; V_121 ++ ) {
struct V_34 * V_38 = V_174 [ V_121 ] ;
V_38 -> va_start = V_179 + V_170 [ V_121 ] ;
V_38 -> va_end = V_38 -> va_start + V_171 [ V_121 ] ;
F_53 ( V_38 ) ;
}
V_73 = V_179 + V_170 [ V_177 ] ;
F_71 ( & V_57 ) ;
for ( V_121 = 0 ; V_121 < V_172 ; V_121 ++ )
F_166 ( V_175 [ V_121 ] , V_174 [ V_121 ] , V_142 ,
F_233 ) ;
F_78 ( V_174 ) ;
return V_175 ;
V_184:
for ( V_121 = 0 ; V_121 < V_172 ; V_121 ++ ) {
F_78 ( V_174 [ V_121 ] ) ;
F_78 ( V_175 [ V_121 ] ) ;
}
V_183:
F_78 ( V_174 ) ;
F_78 ( V_175 ) ;
return NULL ;
}
void F_235 ( struct V_114 * * V_175 , int V_172 )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < V_172 ; V_118 ++ )
F_228 ( V_175 [ V_118 ] ) ;
F_78 ( V_175 ) ;
}
static void * F_236 ( struct V_185 * V_186 , T_11 * V_187 )
__acquires( &vmap_area_lock
static void * F_237 ( struct V_185 * V_186 , void * V_4 , T_11 * V_187 )
{
return F_238 ( V_4 , & V_45 , V_187 ) ;
}
static void F_239 ( struct V_185 * V_186 , void * V_4 )
__releases( &vmap_area_lock
static void F_240 ( struct V_185 * V_186 , struct V_114 * V_188 )
{
if ( F_241 ( V_189 ) ) {
unsigned int V_22 , * V_190 = V_186 -> V_191 ;
if ( ! V_190 )
return;
if ( V_188 -> V_65 & V_123 )
return;
F_242 () ;
memset ( V_190 , 0 , V_192 * sizeof( unsigned int ) ) ;
for ( V_22 = 0 ; V_22 < V_188 -> V_130 ; V_22 ++ )
V_190 [ F_243 ( V_188 -> V_21 [ V_22 ] ) ] ++ ;
F_244 (nr, N_HIGH_MEMORY)
if ( V_190 [ V_22 ] )
F_245 ( V_186 , L_6 , V_22 , V_190 [ V_22 ] ) ;
}
}
static int F_246 ( struct V_185 * V_186 , void * V_4 )
{
struct V_34 * V_38 ;
struct V_114 * V_188 ;
V_38 = F_247 ( V_4 , struct V_34 , V_8 ) ;
if ( ! ( V_38 -> V_65 & V_120 ) )
return 0 ;
V_188 = V_38 -> V_115 ;
F_245 ( V_186 , L_7 ,
V_188 -> V_10 , V_188 -> V_10 + V_188 -> V_46 , V_188 -> V_46 ) ;
if ( V_188 -> V_122 )
F_245 ( V_186 , L_8 , V_188 -> V_122 ) ;
if ( V_188 -> V_130 )
F_245 ( V_186 , L_9 , V_188 -> V_130 ) ;
if ( V_188 -> V_193 )
F_245 ( V_186 , L_10 , ( unsigned long long ) V_188 -> V_193 ) ;
if ( V_188 -> V_65 & V_124 )
F_248 ( V_186 , L_11 ) ;
if ( V_188 -> V_65 & V_142 )
F_248 ( V_186 , L_12 ) ;
if ( V_188 -> V_65 & V_194 )
F_248 ( V_186 , L_13 ) ;
if ( V_188 -> V_65 & V_144 )
F_248 ( V_186 , L_14 ) ;
if ( F_40 ( V_188 -> V_21 ) )
F_248 ( V_186 , L_15 ) ;
F_240 ( V_186 , V_188 ) ;
F_249 ( V_186 , '\n' ) ;
return 0 ;
}
static int F_250 ( struct V_195 * V_195 , struct V_196 * V_196 )
{
if ( F_241 ( V_189 ) )
return F_251 ( V_196 , & V_197 ,
V_192 * sizeof( unsigned int ) ) ;
else
return F_252 ( V_196 , & V_197 ) ;
}
static int T_7 F_253 ( void )
{
F_254 ( L_16 , V_198 , NULL , & V_199 ) ;
return 0 ;
}
