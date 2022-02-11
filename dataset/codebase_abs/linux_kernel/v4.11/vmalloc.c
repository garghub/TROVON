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
static void F_22 ( T_5 * V_19 , unsigned long V_10 , unsigned long V_11 )
{
T_4 * V_18 ;
unsigned long V_17 ;
V_18 = F_23 ( V_19 , V_10 ) ;
do {
V_17 = F_24 ( V_10 , V_11 ) ;
if ( F_25 ( V_18 ) )
continue;
if ( F_26 ( V_18 ) )
continue;
F_17 ( V_18 , V_10 , V_17 ) ;
} while ( V_18 ++ , V_10 = V_17 , V_10 != V_11 );
}
static void F_27 ( unsigned long V_10 , unsigned long V_11 )
{
T_5 * V_19 ;
unsigned long V_17 ;
F_28 ( V_10 >= V_11 ) ;
V_19 = F_29 ( V_10 ) ;
do {
V_17 = F_30 ( V_10 , V_11 ) ;
if ( F_31 ( V_19 ) )
continue;
F_22 ( V_19 , V_10 , V_17 ) ;
} while ( V_19 ++ , V_10 = V_17 , V_10 != V_11 );
}
static int F_32 ( T_1 * V_9 , unsigned long V_10 ,
unsigned long V_11 , T_6 V_20 , struct V_21 * * V_22 , int * V_23 )
{
T_2 * V_12 ;
V_12 = F_33 ( V_9 , V_10 ) ;
if ( ! V_12 )
return - V_24 ;
do {
struct V_21 * V_21 = V_22 [ * V_23 ] ;
if ( F_9 ( ! F_10 ( * V_12 ) ) )
return - V_25 ;
if ( F_9 ( ! V_21 ) )
return - V_24 ;
F_34 ( & V_14 , V_10 , V_12 , F_35 ( V_21 , V_20 ) ) ;
( * V_23 ) ++ ;
} while ( V_12 ++ , V_10 += V_15 , V_10 != V_11 );
return 0 ;
}
static int F_36 ( T_3 * V_16 , unsigned long V_10 ,
unsigned long V_11 , T_6 V_20 , struct V_21 * * V_22 , int * V_23 )
{
T_1 * V_9 ;
unsigned long V_17 ;
V_9 = F_37 ( & V_14 , V_16 , V_10 ) ;
if ( ! V_9 )
return - V_24 ;
do {
V_17 = F_14 ( V_10 , V_11 ) ;
if ( F_32 ( V_9 , V_10 , V_17 , V_20 , V_22 , V_23 ) )
return - V_24 ;
} while ( V_9 ++ , V_10 = V_17 , V_10 != V_11 );
return 0 ;
}
static int F_38 ( T_4 * V_18 , unsigned long V_10 ,
unsigned long V_11 , T_6 V_20 , struct V_21 * * V_22 , int * V_23 )
{
T_3 * V_16 ;
unsigned long V_17 ;
V_16 = F_39 ( & V_14 , V_18 , V_10 ) ;
if ( ! V_16 )
return - V_24 ;
do {
V_17 = F_19 ( V_10 , V_11 ) ;
if ( F_36 ( V_16 , V_10 , V_17 , V_20 , V_22 , V_23 ) )
return - V_24 ;
} while ( V_16 ++ , V_10 = V_17 , V_10 != V_11 );
return 0 ;
}
static int F_40 ( T_5 * V_19 , unsigned long V_10 ,
unsigned long V_11 , T_6 V_20 , struct V_21 * * V_22 , int * V_23 )
{
T_4 * V_18 ;
unsigned long V_17 ;
V_18 = F_41 ( & V_14 , V_19 , V_10 ) ;
if ( ! V_18 )
return - V_24 ;
do {
V_17 = F_24 ( V_10 , V_11 ) ;
if ( F_38 ( V_18 , V_10 , V_17 , V_20 , V_22 , V_23 ) )
return - V_24 ;
} while ( V_18 ++ , V_10 = V_17 , V_10 != V_11 );
return 0 ;
}
static int F_42 ( unsigned long V_26 , unsigned long V_11 ,
T_6 V_20 , struct V_21 * * V_22 )
{
T_5 * V_19 ;
unsigned long V_17 ;
unsigned long V_10 = V_26 ;
int V_27 = 0 ;
int V_23 = 0 ;
F_28 ( V_10 >= V_11 ) ;
V_19 = F_29 ( V_10 ) ;
do {
V_17 = F_30 ( V_10 , V_11 ) ;
V_27 = F_40 ( V_19 , V_10 , V_17 , V_20 , V_22 , & V_23 ) ;
if ( V_27 )
return V_27 ;
} while ( V_19 ++ , V_10 = V_17 , V_10 != V_11 );
return V_23 ;
}
static int F_43 ( unsigned long V_26 , unsigned long V_11 ,
T_6 V_20 , struct V_21 * * V_22 )
{
int V_28 ;
V_28 = F_42 ( V_26 , V_11 , V_20 , V_22 ) ;
F_44 ( V_26 , V_11 ) ;
return V_28 ;
}
int F_45 ( const void * V_29 )
{
#if F_46 ( V_30 ) && F_46 ( V_31 )
unsigned long V_10 = ( unsigned long ) V_29 ;
if ( V_10 >= V_31 && V_10 < V_32 )
return 1 ;
#endif
return F_47 ( V_29 ) ;
}
struct V_21 * F_48 ( const void * V_33 )
{
unsigned long V_10 = ( unsigned long ) V_33 ;
struct V_21 * V_21 = NULL ;
T_5 * V_19 = F_29 ( V_10 ) ;
T_4 * V_18 ;
T_3 * V_16 ;
T_1 * V_9 ;
T_2 * V_34 , V_12 ;
F_49 ( ! F_45 ( V_33 ) ) ;
if ( F_50 ( * V_19 ) )
return NULL ;
V_18 = F_23 ( V_19 , V_10 ) ;
if ( F_51 ( * V_18 ) )
return NULL ;
V_16 = F_18 ( V_18 , V_10 ) ;
if ( F_52 ( * V_16 ) )
return NULL ;
V_9 = F_13 ( V_16 , V_10 ) ;
if ( F_53 ( * V_9 ) )
return NULL ;
V_34 = F_54 ( V_9 , V_10 ) ;
V_12 = * V_34 ;
if ( F_11 ( V_12 ) )
V_21 = F_55 ( V_12 ) ;
F_56 ( V_34 ) ;
return V_21 ;
}
unsigned long F_57 ( const void * V_33 )
{
return F_58 ( F_48 ( V_33 ) ) ;
}
static struct V_35 * F_59 ( unsigned long V_10 )
{
struct V_36 * V_37 = V_38 . V_36 ;
while ( V_37 ) {
struct V_35 * V_39 ;
V_39 = F_60 ( V_37 , struct V_35 , V_36 ) ;
if ( V_10 < V_39 -> va_start )
V_37 = V_37 -> V_40 ;
else if ( V_10 >= V_39 -> va_end )
V_37 = V_37 -> V_41 ;
else
return V_39 ;
}
return NULL ;
}
static void F_61 ( struct V_35 * V_39 )
{
struct V_36 * * V_4 = & V_38 . V_36 ;
struct V_36 * V_42 = NULL ;
struct V_36 * V_43 ;
while ( * V_4 ) {
struct V_35 * V_44 ;
V_42 = * V_4 ;
V_44 = F_60 ( V_42 , struct V_35 , V_36 ) ;
if ( V_39 -> va_start < V_44 -> va_end )
V_4 = & ( * V_4 ) -> V_40 ;
else if ( V_39 -> va_end > V_44 -> va_start )
V_4 = & ( * V_4 ) -> V_41 ;
else
F_62 () ;
}
F_63 ( & V_39 -> V_36 , V_42 , V_4 ) ;
F_64 ( & V_39 -> V_36 , & V_38 ) ;
V_43 = F_65 ( & V_39 -> V_36 ) ;
if ( V_43 ) {
struct V_35 * V_45 ;
V_45 = F_60 ( V_43 , struct V_35 , V_36 ) ;
F_66 ( & V_39 -> V_8 , & V_45 -> V_8 ) ;
} else
F_66 ( & V_39 -> V_8 , & V_46 ) ;
}
static struct V_35 * F_67 ( unsigned long V_47 ,
unsigned long V_48 ,
unsigned long V_49 , unsigned long V_50 ,
int V_51 , T_7 V_52 )
{
struct V_35 * V_39 ;
struct V_36 * V_37 ;
unsigned long V_10 ;
int V_53 = 0 ;
struct V_35 * V_54 ;
F_28 ( ! V_47 ) ;
F_28 ( F_68 ( V_47 ) ) ;
F_28 ( ! F_69 ( V_48 ) ) ;
F_70 () ;
V_39 = F_71 ( sizeof( struct V_35 ) ,
V_52 & V_55 , V_51 ) ;
if ( F_72 ( ! V_39 ) )
return F_73 ( - V_24 ) ;
F_74 ( & V_39 -> V_36 , V_56 , V_52 & V_55 ) ;
V_57:
F_75 ( & V_58 ) ;
if ( ! V_59 ||
V_47 < V_60 ||
V_49 < V_61 ||
V_48 < V_62 ) {
V_63:
V_60 = 0 ;
V_59 = NULL ;
}
V_61 = V_49 ;
V_62 = V_48 ;
if ( V_59 ) {
V_54 = F_60 ( V_59 , struct V_35 , V_36 ) ;
V_10 = F_76 ( V_54 -> va_end , V_48 ) ;
if ( V_10 < V_49 )
goto V_63;
if ( V_10 + V_47 < V_10 )
goto V_64;
} else {
V_10 = F_76 ( V_49 , V_48 ) ;
if ( V_10 + V_47 < V_10 )
goto V_64;
V_37 = V_38 . V_36 ;
V_54 = NULL ;
while ( V_37 ) {
struct V_35 * V_43 ;
V_43 = F_60 ( V_37 , struct V_35 , V_36 ) ;
if ( V_43 -> va_end >= V_10 ) {
V_54 = V_43 ;
if ( V_43 -> va_start <= V_10 )
break;
V_37 = V_37 -> V_40 ;
} else
V_37 = V_37 -> V_41 ;
}
if ( ! V_54 )
goto V_65;
}
while ( V_10 + V_47 > V_54 -> va_start && V_10 + V_47 <= V_50 ) {
if ( V_10 + V_60 < V_54 -> va_start )
V_60 = V_54 -> va_start - V_10 ;
V_10 = F_76 ( V_54 -> va_end , V_48 ) ;
if ( V_10 + V_47 < V_10 )
goto V_64;
if ( F_77 ( & V_54 -> V_8 , & V_46 ) )
goto V_65;
V_54 = F_78 ( V_54 , V_8 ) ;
}
V_65:
if ( V_10 + V_47 > V_50 )
goto V_64;
V_39 -> va_start = V_10 ;
V_39 -> va_end = V_10 + V_47 ;
V_39 -> V_66 = 0 ;
F_61 ( V_39 ) ;
V_59 = & V_39 -> V_36 ;
F_79 ( & V_58 ) ;
F_28 ( ! F_80 ( V_39 -> va_start , V_48 ) ) ;
F_28 ( V_39 -> va_start < V_49 ) ;
F_28 ( V_39 -> va_end > V_50 ) ;
return V_39 ;
V_64:
F_79 ( & V_58 ) ;
if ( ! V_53 ) {
F_81 () ;
V_53 = 1 ;
goto V_57;
}
if ( F_82 ( V_52 ) ) {
unsigned long V_67 = 0 ;
F_83 ( & V_68 , 0 , & V_67 ) ;
if ( V_67 > 0 ) {
V_53 = 0 ;
goto V_57;
}
}
if ( F_84 () )
F_85 ( L_1 ,
V_47 ) ;
F_86 ( V_39 ) ;
return F_73 ( - V_25 ) ;
}
int F_87 ( struct V_69 * V_70 )
{
return F_88 ( & V_68 , V_70 ) ;
}
int F_89 ( struct V_69 * V_70 )
{
return F_90 ( & V_68 , V_70 ) ;
}
static void F_91 ( struct V_35 * V_39 )
{
F_28 ( F_92 ( & V_39 -> V_36 ) ) ;
if ( V_59 ) {
if ( V_39 -> va_end < V_61 ) {
V_59 = NULL ;
} else {
struct V_35 * V_71 ;
V_71 = F_60 ( V_59 , struct V_35 , V_36 ) ;
if ( V_39 -> va_start <= V_71 -> va_start ) {
V_59 = F_65 ( & V_39 -> V_36 ) ;
}
}
}
F_93 ( & V_39 -> V_36 , & V_38 ) ;
F_94 ( & V_39 -> V_36 ) ;
F_95 ( & V_39 -> V_8 ) ;
if ( V_39 -> va_end > V_72 && V_39 -> va_end <= V_73 )
V_74 = F_96 ( V_74 , V_39 -> va_end ) ;
F_97 ( V_39 , V_75 ) ;
}
static void F_98 ( struct V_35 * V_39 )
{
F_75 ( & V_58 ) ;
F_91 ( V_39 ) ;
F_79 ( & V_58 ) ;
}
static void F_99 ( struct V_35 * V_39 )
{
F_27 ( V_39 -> va_start , V_39 -> va_end ) ;
}
static void F_100 ( unsigned long V_26 , unsigned long V_11 )
{
if ( F_101 () ) {
F_27 ( V_26 , V_11 ) ;
F_102 ( V_26 , V_11 ) ;
}
}
static unsigned long F_103 ( void )
{
unsigned int log ;
log = F_104 ( F_105 () ) ;
return log * ( 32UL * 1024 * 1024 / V_15 ) ;
}
void F_106 ( void )
{
F_107 ( & V_76 , F_103 () + 1 ) ;
}
static bool F_108 ( unsigned long V_26 , unsigned long V_11 )
{
struct V_6 * V_77 ;
struct V_35 * V_39 ;
struct V_35 * V_78 ;
bool V_79 = false ;
F_109 ( & V_80 ) ;
V_77 = F_3 ( & V_81 ) ;
F_110 (va, valist, purge_list) {
if ( V_39 -> va_start < V_26 )
V_26 = V_39 -> va_start ;
if ( V_39 -> va_end > V_11 )
V_11 = V_39 -> va_end ;
V_79 = true ;
}
if ( ! V_79 )
return false ;
F_102 ( V_26 , V_11 ) ;
F_75 ( & V_58 ) ;
F_111 (va, n_va, valist, purge_list) {
int V_23 = ( V_39 -> va_end - V_39 -> va_start ) >> V_82 ;
F_91 ( V_39 ) ;
F_112 ( V_23 , & V_76 ) ;
F_113 ( & V_58 ) ;
}
F_79 ( & V_58 ) ;
return true ;
}
static void F_114 ( void )
{
if ( F_115 ( & V_80 ) ) {
F_108 ( V_83 , 0 ) ;
F_116 ( & V_80 ) ;
}
}
static void F_81 ( void )
{
F_117 ( & V_80 ) ;
F_118 () ;
F_108 ( V_83 , 0 ) ;
F_116 ( & V_80 ) ;
}
static void F_119 ( struct V_35 * V_39 )
{
int V_84 ;
V_84 = F_120 ( ( V_39 -> va_end - V_39 -> va_start ) >> V_82 ,
& V_76 ) ;
F_121 ( & V_39 -> V_85 , & V_81 ) ;
if ( F_72 ( V_84 > F_103 () ) )
F_114 () ;
}
static void F_122 ( struct V_35 * V_39 )
{
F_123 ( V_39 -> va_start , V_39 -> va_end ) ;
F_99 ( V_39 ) ;
F_119 ( V_39 ) ;
}
static struct V_35 * F_124 ( unsigned long V_10 )
{
struct V_35 * V_39 ;
F_75 ( & V_58 ) ;
V_39 = F_59 ( V_10 ) ;
F_79 ( & V_58 ) ;
return V_39 ;
}
static unsigned long F_125 ( unsigned long V_10 )
{
V_10 -= V_72 & ~ ( V_86 - 1 ) ;
V_10 /= V_86 ;
return V_10 ;
}
static void * F_126 ( unsigned long va_start , unsigned long V_87 )
{
unsigned long V_10 ;
V_10 = va_start + ( V_87 << V_82 ) ;
F_28 ( F_125 ( V_10 ) != F_125 ( va_start ) ) ;
return ( void * ) V_10 ;
}
static void * F_127 ( unsigned int V_88 , T_7 V_52 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 ;
struct V_35 * V_39 ;
unsigned long V_93 ;
int V_51 , V_27 ;
void * V_94 ;
V_51 = F_128 () ;
V_92 = F_71 ( sizeof( struct V_91 ) ,
V_52 & V_55 , V_51 ) ;
if ( F_72 ( ! V_92 ) )
return F_73 ( - V_24 ) ;
V_39 = F_67 ( V_86 , V_86 ,
V_72 , V_73 ,
V_51 , V_52 ) ;
if ( F_129 ( V_39 ) ) {
F_86 ( V_92 ) ;
return F_130 ( V_39 ) ;
}
V_27 = F_131 ( V_52 ) ;
if ( F_72 ( V_27 ) ) {
F_86 ( V_92 ) ;
F_98 ( V_39 ) ;
return F_73 ( V_27 ) ;
}
V_94 = F_126 ( V_39 -> va_start , 0 ) ;
F_132 ( & V_92 -> V_95 ) ;
V_92 -> V_39 = V_39 ;
F_28 ( V_96 <= ( 1UL << V_88 ) ) ;
V_92 -> free = V_96 - ( 1UL << V_88 ) ;
V_92 -> V_97 = 0 ;
V_92 -> V_98 = V_96 ;
V_92 -> V_99 = 0 ;
F_133 ( & V_92 -> V_100 ) ;
V_93 = F_125 ( V_39 -> va_start ) ;
F_75 ( & V_101 ) ;
V_27 = F_134 ( & V_102 , V_93 , V_92 ) ;
F_79 ( & V_101 ) ;
F_28 ( V_27 ) ;
F_135 () ;
V_90 = & F_136 ( V_89 ) ;
F_75 ( & V_90 -> V_95 ) ;
F_137 ( & V_92 -> V_100 , & V_90 -> free ) ;
F_79 ( & V_90 -> V_95 ) ;
F_138 ( V_89 ) ;
return V_94 ;
}
static void F_139 ( struct V_91 * V_92 )
{
struct V_91 * V_43 ;
unsigned long V_93 ;
V_93 = F_125 ( V_92 -> V_39 -> va_start ) ;
F_75 ( & V_101 ) ;
V_43 = F_140 ( & V_102 , V_93 ) ;
F_79 ( & V_101 ) ;
F_28 ( V_43 != V_92 ) ;
F_119 ( V_92 -> V_39 ) ;
F_97 ( V_92 , V_75 ) ;
}
static void F_141 ( int V_103 )
{
F_142 ( V_104 ) ;
struct V_91 * V_92 ;
struct V_91 * V_105 ;
struct V_89 * V_90 = & F_143 ( V_89 , V_103 ) ;
F_144 () ;
F_145 (vb, &vbq->free, free_list) {
if ( ! ( V_92 -> free + V_92 -> V_97 == V_96 && V_92 -> V_97 != V_96 ) )
continue;
F_75 ( & V_92 -> V_95 ) ;
if ( V_92 -> free + V_92 -> V_97 == V_96 && V_92 -> V_97 != V_96 ) {
V_92 -> free = 0 ;
V_92 -> V_97 = V_96 ;
V_92 -> V_98 = 0 ;
V_92 -> V_99 = V_96 ;
F_75 ( & V_90 -> V_95 ) ;
F_95 ( & V_92 -> V_100 ) ;
F_79 ( & V_90 -> V_95 ) ;
F_79 ( & V_92 -> V_95 ) ;
F_146 ( & V_92 -> V_104 , & V_104 ) ;
} else
F_79 ( & V_92 -> V_95 ) ;
}
F_147 () ;
F_148 (vb, n_vb, &purge, purge) {
F_149 ( & V_92 -> V_104 ) ;
F_139 ( V_92 ) ;
}
}
static void F_118 ( void )
{
int V_103 ;
F_150 (cpu)
F_141 ( V_103 ) ;
}
static void * F_151 ( unsigned long V_47 , T_7 V_52 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 ;
void * V_94 = NULL ;
unsigned int V_88 ;
F_28 ( F_68 ( V_47 ) ) ;
F_28 ( V_47 > V_15 * V_106 ) ;
if ( F_9 ( V_47 == 0 ) ) {
return NULL ;
}
V_88 = F_152 ( V_47 ) ;
F_144 () ;
V_90 = & F_136 ( V_89 ) ;
F_145 (vb, &vbq->free, free_list) {
unsigned long V_87 ;
F_75 ( & V_92 -> V_95 ) ;
if ( V_92 -> free < ( 1UL << V_88 ) ) {
F_79 ( & V_92 -> V_95 ) ;
continue;
}
V_87 = V_96 - V_92 -> free ;
V_94 = F_126 ( V_92 -> V_39 -> va_start , V_87 ) ;
V_92 -> free -= 1UL << V_88 ;
if ( V_92 -> free == 0 ) {
F_75 ( & V_90 -> V_95 ) ;
F_95 ( & V_92 -> V_100 ) ;
F_79 ( & V_90 -> V_95 ) ;
}
F_79 ( & V_92 -> V_95 ) ;
break;
}
F_138 ( V_89 ) ;
F_147 () ;
if ( ! V_94 )
V_94 = F_127 ( V_88 , V_52 ) ;
return V_94 ;
}
static void F_153 ( const void * V_10 , unsigned long V_47 )
{
unsigned long V_107 ;
unsigned long V_93 ;
unsigned int V_88 ;
struct V_91 * V_92 ;
F_28 ( F_68 ( V_47 ) ) ;
F_28 ( V_47 > V_15 * V_106 ) ;
F_123 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_47 ) ;
V_88 = F_152 ( V_47 ) ;
V_107 = ( unsigned long ) V_10 & ( V_86 - 1 ) ;
V_107 >>= V_82 ;
V_93 = F_125 ( ( unsigned long ) V_10 ) ;
F_144 () ;
V_92 = F_154 ( & V_102 , V_93 ) ;
F_147 () ;
F_28 ( ! V_92 ) ;
F_27 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_47 ) ;
F_75 ( & V_92 -> V_95 ) ;
V_92 -> V_98 = F_155 ( V_92 -> V_98 , V_107 ) ;
V_92 -> V_99 = F_96 ( V_92 -> V_99 , V_107 + ( 1UL << V_88 ) ) ;
V_92 -> V_97 += 1UL << V_88 ;
if ( V_92 -> V_97 == V_96 ) {
F_28 ( V_92 -> free ) ;
F_79 ( & V_92 -> V_95 ) ;
F_139 ( V_92 ) ;
} else
F_79 ( & V_92 -> V_95 ) ;
}
void F_156 ( void )
{
unsigned long V_26 = V_83 , V_11 = 0 ;
int V_103 ;
int V_108 = 0 ;
if ( F_72 ( ! V_109 ) )
return;
F_70 () ;
F_150 (cpu) {
struct V_89 * V_90 = & F_143 ( V_89 , V_103 ) ;
struct V_91 * V_92 ;
F_144 () ;
F_145 (vb, &vbq->free, free_list) {
F_75 ( & V_92 -> V_95 ) ;
if ( V_92 -> V_97 ) {
unsigned long va_start = V_92 -> V_39 -> va_start ;
unsigned long V_110 , V_111 ;
V_110 = va_start + ( V_92 -> V_98 << V_82 ) ;
V_111 = va_start + ( V_92 -> V_99 << V_82 ) ;
V_26 = F_155 ( V_110 , V_26 ) ;
V_11 = F_96 ( V_111 , V_11 ) ;
V_108 = 1 ;
}
F_79 ( & V_92 -> V_95 ) ;
}
F_147 () ;
}
F_117 ( & V_80 ) ;
F_118 () ;
if ( ! F_108 ( V_26 , V_11 ) && V_108 )
F_102 ( V_26 , V_11 ) ;
F_116 ( & V_80 ) ;
}
void F_157 ( const void * V_112 , unsigned int V_113 )
{
unsigned long V_47 = ( unsigned long ) V_113 << V_82 ;
unsigned long V_10 = ( unsigned long ) V_112 ;
struct V_35 * V_39 ;
F_70 () ;
F_28 ( ! V_10 ) ;
F_28 ( V_10 < V_72 ) ;
F_28 ( V_10 > V_73 ) ;
F_28 ( ! F_158 ( V_10 ) ) ;
F_159 ( V_112 , V_47 ) ;
F_100 ( V_10 , V_10 + V_47 ) ;
if ( F_160 ( V_113 <= V_106 ) ) {
F_153 ( V_112 , V_47 ) ;
return;
}
V_39 = F_124 ( V_10 ) ;
F_28 ( ! V_39 ) ;
F_122 ( V_39 ) ;
}
void * F_161 ( struct V_21 * * V_22 , unsigned int V_113 , int V_51 , T_6 V_20 )
{
unsigned long V_47 = ( unsigned long ) V_113 << V_82 ;
unsigned long V_10 ;
void * V_112 ;
if ( F_160 ( V_113 <= V_106 ) ) {
V_112 = F_151 ( V_47 , V_114 ) ;
if ( F_129 ( V_112 ) )
return NULL ;
V_10 = ( unsigned long ) V_112 ;
} else {
struct V_35 * V_39 ;
V_39 = F_67 ( V_47 , V_15 ,
V_72 , V_73 , V_51 , V_114 ) ;
if ( F_129 ( V_39 ) )
return NULL ;
V_10 = V_39 -> va_start ;
V_112 = ( void * ) V_10 ;
}
if ( F_43 ( V_10 , V_10 + V_47 , V_20 , V_22 ) < 0 ) {
F_157 ( V_112 , V_113 ) ;
return NULL ;
}
return V_112 ;
}
void T_8 F_162 ( struct V_115 * V_116 )
{
struct V_115 * V_43 , * * V_4 ;
F_28 ( V_109 ) ;
for ( V_4 = & V_117 ; ( V_43 = * V_4 ) != NULL ; V_4 = & V_43 -> V_17 ) {
if ( V_43 -> V_10 >= V_116 -> V_10 ) {
F_28 ( V_43 -> V_10 < V_116 -> V_10 + V_116 -> V_47 ) ;
break;
} else
F_28 ( V_43 -> V_10 + V_43 -> V_47 > V_116 -> V_10 ) ;
}
V_116 -> V_17 = * V_4 ;
* V_4 = V_116 ;
}
void T_8 F_163 ( struct V_115 * V_116 , T_9 V_48 )
{
static T_9 T_10 V_118 ;
unsigned long V_10 ;
V_10 = F_76 ( V_72 + T_10 , V_48 ) ;
T_10 = F_164 ( V_10 + V_116 -> V_47 ) - V_72 ;
V_116 -> V_10 = ( void * ) V_10 ;
F_162 ( V_116 ) ;
}
void T_8 F_165 ( void )
{
struct V_35 * V_39 ;
struct V_115 * V_43 ;
int V_119 ;
F_150 (i) {
struct V_89 * V_90 ;
struct V_3 * V_4 ;
V_90 = & F_143 ( V_89 , V_119 ) ;
F_132 ( & V_90 -> V_95 ) ;
F_133 ( & V_90 -> free ) ;
V_4 = & F_143 ( V_3 , V_119 ) ;
F_166 ( & V_4 -> V_8 ) ;
F_167 ( & V_4 -> V_5 , F_1 ) ;
}
for ( V_43 = V_117 ; V_43 ; V_43 = V_43 -> V_17 ) {
V_39 = F_168 ( sizeof( struct V_35 ) , V_120 ) ;
V_39 -> V_66 = V_121 ;
V_39 -> va_start = ( unsigned long ) V_43 -> V_10 ;
V_39 -> va_end = V_39 -> va_start + V_43 -> V_47 ;
V_39 -> V_116 = V_43 ;
F_61 ( V_39 ) ;
}
V_74 = V_73 ;
V_109 = true ;
}
int F_169 ( unsigned long V_10 , unsigned long V_47 ,
T_6 V_20 , struct V_21 * * V_22 )
{
return F_42 ( V_10 , V_10 + V_47 , V_20 , V_22 ) ;
}
void F_170 ( unsigned long V_10 , unsigned long V_47 )
{
F_27 ( V_10 , V_10 + V_47 ) ;
}
void F_171 ( unsigned long V_10 , unsigned long V_47 )
{
unsigned long V_11 = V_10 + V_47 ;
F_123 ( V_10 , V_11 ) ;
F_27 ( V_10 , V_11 ) ;
F_102 ( V_10 , V_11 ) ;
}
int F_172 ( struct V_115 * V_122 , T_6 V_20 , struct V_21 * * V_22 )
{
unsigned long V_10 = ( unsigned long ) V_122 -> V_10 ;
unsigned long V_11 = V_10 + F_173 ( V_122 ) ;
int V_27 ;
V_27 = F_43 ( V_10 , V_11 , V_20 , V_22 ) ;
return V_27 > 0 ? 0 : V_27 ;
}
static void F_174 ( struct V_115 * V_116 , struct V_35 * V_39 ,
unsigned long V_66 , const void * V_123 )
{
F_75 ( & V_58 ) ;
V_116 -> V_66 = V_66 ;
V_116 -> V_10 = ( void * ) V_39 -> va_start ;
V_116 -> V_47 = V_39 -> va_end - V_39 -> va_start ;
V_116 -> V_123 = V_123 ;
V_39 -> V_116 = V_116 ;
V_39 -> V_66 |= V_121 ;
F_79 ( & V_58 ) ;
}
static void F_175 ( struct V_115 * V_116 )
{
F_176 () ;
V_116 -> V_66 &= ~ V_124 ;
}
static struct V_115 * F_177 ( unsigned long V_47 ,
unsigned long V_48 , unsigned long V_66 , unsigned long V_26 ,
unsigned long V_11 , int V_51 , T_7 V_52 , const void * V_123 )
{
struct V_35 * V_39 ;
struct V_115 * V_122 ;
F_28 ( F_178 () ) ;
V_47 = F_179 ( V_47 ) ;
if ( F_72 ( ! V_47 ) )
return NULL ;
if ( V_66 & V_125 )
V_48 = 1ul << F_180 ( int , F_181 ( V_47 ) ,
V_82 , V_126 ) ;
V_122 = F_182 ( sizeof( * V_122 ) , V_52 & V_55 , V_51 ) ;
if ( F_72 ( ! V_122 ) )
return NULL ;
if ( ! ( V_66 & V_127 ) )
V_47 += V_15 ;
V_39 = F_67 ( V_47 , V_48 , V_26 , V_11 , V_51 , V_52 ) ;
if ( F_129 ( V_39 ) ) {
F_86 ( V_122 ) ;
return NULL ;
}
F_174 ( V_122 , V_39 , V_66 , V_123 ) ;
return V_122 ;
}
struct V_115 * F_183 ( unsigned long V_47 , unsigned long V_66 ,
unsigned long V_26 , unsigned long V_11 )
{
return F_177 ( V_47 , 1 , V_66 , V_26 , V_11 , V_128 ,
V_114 , F_184 ( 0 ) ) ;
}
struct V_115 * F_185 ( unsigned long V_47 , unsigned long V_66 ,
unsigned long V_26 , unsigned long V_11 ,
const void * V_123 )
{
return F_177 ( V_47 , 1 , V_66 , V_26 , V_11 , V_128 ,
V_114 , V_123 ) ;
}
struct V_115 * F_186 ( unsigned long V_47 , unsigned long V_66 )
{
return F_177 ( V_47 , 1 , V_66 , V_72 , V_73 ,
V_128 , V_114 ,
F_184 ( 0 ) ) ;
}
struct V_115 * F_187 ( unsigned long V_47 , unsigned long V_66 ,
const void * V_123 )
{
return F_177 ( V_47 , 1 , V_66 , V_72 , V_73 ,
V_128 , V_114 , V_123 ) ;
}
struct V_115 * F_188 ( const void * V_10 )
{
struct V_35 * V_39 ;
V_39 = F_124 ( ( unsigned long ) V_10 ) ;
if ( V_39 && V_39 -> V_66 & V_121 )
return V_39 -> V_116 ;
return NULL ;
}
struct V_115 * F_189 ( const void * V_10 )
{
struct V_35 * V_39 ;
F_70 () ;
V_39 = F_124 ( ( unsigned long ) V_10 ) ;
if ( V_39 && V_39 -> V_66 & V_121 ) {
struct V_115 * V_116 = V_39 -> V_116 ;
F_75 ( & V_58 ) ;
V_39 -> V_116 = NULL ;
V_39 -> V_66 &= ~ V_121 ;
F_79 ( & V_58 ) ;
F_100 ( V_39 -> va_start , V_39 -> va_end ) ;
F_190 ( V_116 ) ;
F_122 ( V_39 ) ;
return V_116 ;
}
return NULL ;
}
static void F_5 ( const void * V_10 , int V_129 )
{
struct V_115 * V_122 ;
if ( ! V_10 )
return;
if ( F_191 ( ! F_158 ( V_10 ) , L_2 ,
V_10 ) )
return;
V_122 = F_189 ( V_10 ) ;
if ( F_72 ( ! V_122 ) ) {
F_191 ( 1 , V_130 L_3 ,
V_10 ) ;
return;
}
F_159 ( V_10 , F_173 ( V_122 ) ) ;
F_192 ( V_10 , F_173 ( V_122 ) ) ;
if ( V_129 ) {
int V_119 ;
for ( V_119 = 0 ; V_119 < V_122 -> V_131 ; V_119 ++ ) {
struct V_21 * V_21 = V_122 -> V_22 [ V_119 ] ;
F_28 ( ! V_21 ) ;
F_193 ( V_21 , 0 ) ;
}
F_194 ( V_122 -> V_22 ) ;
}
F_86 ( V_122 ) ;
return;
}
static inline void F_195 ( const void * V_10 )
{
struct V_3 * V_4 = F_196 ( & V_3 ) ;
if ( F_121 ( (struct V_6 * ) V_10 , & V_4 -> V_8 ) )
F_197 ( & V_4 -> V_5 ) ;
}
void F_198 ( const void * V_10 )
{
F_28 ( F_199 () ) ;
F_200 ( V_10 ) ;
if ( ! V_10 )
return;
F_195 ( V_10 ) ;
}
void F_201 ( const void * V_10 )
{
F_28 ( F_199 () ) ;
F_200 ( V_10 ) ;
if ( ! V_10 )
return;
if ( F_72 ( F_178 () ) )
F_195 ( V_10 ) ;
else
F_5 ( V_10 , 1 ) ;
}
void F_202 ( const void * V_10 )
{
F_28 ( F_178 () ) ;
F_70 () ;
if ( V_10 )
F_5 ( V_10 , 0 ) ;
}
void * F_203 ( struct V_21 * * V_22 , unsigned int V_113 ,
unsigned long V_66 , T_6 V_20 )
{
struct V_115 * V_122 ;
unsigned long V_47 ;
F_70 () ;
if ( V_113 > V_132 )
return NULL ;
V_47 = ( unsigned long ) V_113 << V_82 ;
V_122 = F_187 ( V_47 , V_66 , F_184 ( 0 ) ) ;
if ( ! V_122 )
return NULL ;
if ( F_172 ( V_122 , V_20 , V_22 ) ) {
F_202 ( V_122 -> V_10 ) ;
return NULL ;
}
return V_122 -> V_10 ;
}
static void * F_204 ( struct V_115 * V_122 , T_7 V_52 ,
T_6 V_20 , int V_51 )
{
struct V_21 * * V_22 ;
unsigned int V_131 , V_133 , V_119 ;
const T_7 V_134 = ( V_52 & V_55 ) | V_135 ;
const T_7 V_136 = V_52 | V_137 ;
V_131 = F_173 ( V_122 ) >> V_82 ;
V_133 = ( V_131 * sizeof( struct V_21 * ) ) ;
V_122 -> V_131 = V_131 ;
if ( V_133 > V_15 ) {
V_22 = F_205 ( V_133 , 1 , V_134 | V_138 ,
V_139 , V_51 , V_122 -> V_123 ) ;
} else {
V_22 = F_71 ( V_133 , V_134 , V_51 ) ;
}
V_122 -> V_22 = V_22 ;
if ( ! V_122 -> V_22 ) {
F_189 ( V_122 -> V_10 ) ;
F_86 ( V_122 ) ;
return NULL ;
}
for ( V_119 = 0 ; V_119 < V_122 -> V_131 ; V_119 ++ ) {
struct V_21 * V_21 ;
if ( F_206 ( V_140 ) ) {
V_122 -> V_131 = V_119 ;
goto V_141;
}
if ( V_51 == V_128 )
V_21 = F_207 ( V_136 ) ;
else
V_21 = F_208 ( V_51 , V_136 , 0 ) ;
if ( F_72 ( ! V_21 ) ) {
V_122 -> V_131 = V_119 ;
goto V_142;
}
V_122 -> V_22 [ V_119 ] = V_21 ;
if ( F_82 ( V_52 ) )
F_209 () ;
}
if ( F_172 ( V_122 , V_20 , V_22 ) )
goto V_142;
return V_122 -> V_10 ;
V_142:
F_210 ( V_52 , NULL ,
L_4 ,
( V_122 -> V_131 * V_15 ) , V_122 -> V_47 ) ;
V_141:
F_201 ( V_122 -> V_10 ) ;
return NULL ;
}
void * F_211 ( unsigned long V_47 , unsigned long V_48 ,
unsigned long V_26 , unsigned long V_11 , T_7 V_52 ,
T_6 V_20 , unsigned long V_143 , int V_51 ,
const void * V_123 )
{
struct V_115 * V_122 ;
void * V_10 ;
unsigned long V_144 = V_47 ;
V_47 = F_179 ( V_47 ) ;
if ( ! V_47 || ( V_47 >> V_82 ) > V_132 )
goto V_142;
V_122 = F_177 ( V_47 , V_48 , V_145 | V_124 |
V_143 , V_26 , V_11 , V_51 , V_52 , V_123 ) ;
if ( ! V_122 )
goto V_142;
V_10 = F_204 ( V_122 , V_52 , V_20 , V_51 ) ;
if ( ! V_10 )
return NULL ;
F_175 ( V_122 ) ;
F_212 ( V_10 , V_144 , 2 , V_52 ) ;
return V_10 ;
V_142:
F_210 ( V_52 , NULL ,
L_5 , V_144 ) ;
return NULL ;
}
static void * F_205 ( unsigned long V_47 , unsigned long V_48 ,
T_7 V_52 , T_6 V_20 ,
int V_51 , const void * V_123 )
{
return F_211 ( V_47 , V_48 , V_72 , V_73 ,
V_52 , V_20 , 0 , V_51 , V_123 ) ;
}
void * F_213 ( unsigned long V_47 , T_7 V_52 , T_6 V_20 )
{
return F_205 ( V_47 , 1 , V_52 , V_20 , V_128 ,
F_184 ( 0 ) ) ;
}
static inline void * F_214 ( unsigned long V_47 ,
int V_51 , T_7 V_66 )
{
return F_205 ( V_47 , 1 , V_66 , V_139 ,
V_51 , F_184 ( 0 ) ) ;
}
void * F_215 ( unsigned long V_47 )
{
return F_214 ( V_47 , V_128 ,
V_114 | V_138 ) ;
}
void * F_216 ( unsigned long V_47 )
{
return F_214 ( V_47 , V_128 ,
V_114 | V_138 | V_135 ) ;
}
void * F_217 ( unsigned long V_47 )
{
struct V_115 * V_122 ;
void * V_28 ;
V_28 = F_205 ( V_47 , V_146 ,
V_114 | V_138 | V_135 ,
V_139 , V_128 ,
F_184 ( 0 ) ) ;
if ( V_28 ) {
V_122 = F_188 ( V_28 ) ;
V_122 -> V_66 |= V_147 ;
}
return V_28 ;
}
void * F_218 ( unsigned long V_47 , int V_51 )
{
return F_205 ( V_47 , 1 , V_114 | V_138 , V_139 ,
V_51 , F_184 ( 0 ) ) ;
}
void * F_219 ( unsigned long V_47 , int V_51 )
{
return F_214 ( V_47 , V_51 ,
V_114 | V_138 | V_135 ) ;
}
void * F_220 ( unsigned long V_47 )
{
return F_205 ( V_47 , 1 , V_114 | V_138 , V_148 ,
V_128 , F_184 ( 0 ) ) ;
}
void * F_221 ( unsigned long V_47 )
{
return F_205 ( V_47 , 1 , V_149 , V_139 ,
V_128 , F_184 ( 0 ) ) ;
}
void * F_222 ( unsigned long V_47 )
{
struct V_115 * V_122 ;
void * V_28 ;
V_28 = F_205 ( V_47 , 1 , V_149 | V_135 , V_139 ,
V_128 , F_184 ( 0 ) ) ;
if ( V_28 ) {
V_122 = F_188 ( V_28 ) ;
V_122 -> V_66 |= V_147 ;
}
return V_28 ;
}
static int F_223 ( char * V_150 , char * V_10 , unsigned long V_113 )
{
struct V_21 * V_4 ;
int V_151 = 0 ;
while ( V_113 ) {
unsigned long V_107 , V_152 ;
V_107 = F_68 ( V_10 ) ;
V_152 = V_15 - V_107 ;
if ( V_152 > V_113 )
V_152 = V_113 ;
V_4 = F_48 ( V_10 ) ;
if ( V_4 ) {
void * V_153 = F_224 ( V_4 ) ;
memcpy ( V_150 , V_153 + V_107 , V_152 ) ;
F_225 ( V_153 ) ;
} else
memset ( V_150 , 0 , V_152 ) ;
V_10 += V_152 ;
V_150 += V_152 ;
V_151 += V_152 ;
V_113 -= V_152 ;
}
return V_151 ;
}
static int F_226 ( char * V_150 , char * V_10 , unsigned long V_113 )
{
struct V_21 * V_4 ;
int V_151 = 0 ;
while ( V_113 ) {
unsigned long V_107 , V_152 ;
V_107 = F_68 ( V_10 ) ;
V_152 = V_15 - V_107 ;
if ( V_152 > V_113 )
V_152 = V_113 ;
V_4 = F_48 ( V_10 ) ;
if ( V_4 ) {
void * V_153 = F_224 ( V_4 ) ;
memcpy ( V_153 + V_107 , V_150 , V_152 ) ;
F_225 ( V_153 ) ;
}
V_10 += V_152 ;
V_150 += V_152 ;
V_151 += V_152 ;
V_113 -= V_152 ;
}
return V_151 ;
}
long F_227 ( char * V_150 , char * V_10 , unsigned long V_113 )
{
struct V_35 * V_39 ;
struct V_115 * V_116 ;
char * V_94 , * V_154 = V_150 ;
unsigned long V_155 = V_113 ;
unsigned long V_37 ;
if ( ( unsigned long ) V_10 + V_113 < V_113 )
V_113 = - ( unsigned long ) V_10 ;
F_75 ( & V_58 ) ;
F_228 (va, &vmap_area_list, list) {
if ( ! V_113 )
break;
if ( ! ( V_39 -> V_66 & V_121 ) )
continue;
V_116 = V_39 -> V_116 ;
V_94 = ( char * ) V_116 -> V_10 ;
if ( V_10 >= V_94 + F_173 ( V_116 ) )
continue;
while ( V_10 < V_94 ) {
if ( V_113 == 0 )
goto V_156;
* V_150 = '\0' ;
V_150 ++ ;
V_10 ++ ;
V_113 -- ;
}
V_37 = V_94 + F_173 ( V_116 ) - V_10 ;
if ( V_37 > V_113 )
V_37 = V_113 ;
if ( ! ( V_116 -> V_66 & V_125 ) )
F_223 ( V_150 , V_10 , V_37 ) ;
else
memset ( V_150 , 0 , V_37 ) ;
V_150 += V_37 ;
V_10 += V_37 ;
V_113 -= V_37 ;
}
V_156:
F_79 ( & V_58 ) ;
if ( V_150 == V_154 )
return 0 ;
if ( V_150 != V_154 + V_155 )
memset ( V_150 , 0 , V_155 - ( V_150 - V_154 ) ) ;
return V_155 ;
}
long F_229 ( char * V_150 , char * V_10 , unsigned long V_113 )
{
struct V_35 * V_39 ;
struct V_115 * V_116 ;
char * V_94 ;
unsigned long V_37 , V_155 ;
int V_151 = 0 ;
if ( ( unsigned long ) V_10 + V_113 < V_113 )
V_113 = - ( unsigned long ) V_10 ;
V_155 = V_113 ;
F_75 ( & V_58 ) ;
F_228 (va, &vmap_area_list, list) {
if ( ! V_113 )
break;
if ( ! ( V_39 -> V_66 & V_121 ) )
continue;
V_116 = V_39 -> V_116 ;
V_94 = ( char * ) V_116 -> V_10 ;
if ( V_10 >= V_94 + F_173 ( V_116 ) )
continue;
while ( V_10 < V_94 ) {
if ( V_113 == 0 )
goto V_156;
V_150 ++ ;
V_10 ++ ;
V_113 -- ;
}
V_37 = V_94 + F_173 ( V_116 ) - V_10 ;
if ( V_37 > V_113 )
V_37 = V_113 ;
if ( ! ( V_116 -> V_66 & V_125 ) ) {
F_226 ( V_150 , V_10 , V_37 ) ;
V_151 ++ ;
}
V_150 += V_37 ;
V_10 += V_37 ;
V_113 -= V_37 ;
}
V_156:
F_79 ( & V_58 ) ;
if ( ! V_151 )
return 0 ;
return V_155 ;
}
int F_230 ( struct V_157 * V_158 , unsigned long V_159 ,
void * V_160 , unsigned long V_47 )
{
struct V_115 * V_122 ;
V_47 = F_179 ( V_47 ) ;
if ( ! F_158 ( V_159 ) || ! F_158 ( V_160 ) )
return - V_161 ;
V_122 = F_188 ( V_160 ) ;
if ( ! V_122 )
return - V_161 ;
if ( ! ( V_122 -> V_66 & V_147 ) )
return - V_161 ;
if ( V_160 + V_47 > V_122 -> V_10 + V_122 -> V_47 )
return - V_161 ;
do {
struct V_21 * V_21 = F_48 ( V_160 ) ;
int V_28 ;
V_28 = F_231 ( V_158 , V_159 , V_21 ) ;
if ( V_28 )
return V_28 ;
V_159 += V_15 ;
V_160 += V_15 ;
V_47 -= V_15 ;
} while ( V_47 > 0 );
V_158 -> V_143 |= V_162 | V_163 ;
return 0 ;
}
int F_232 ( struct V_157 * V_158 , void * V_10 ,
unsigned long V_164 )
{
return F_230 ( V_158 , V_158 -> V_165 ,
V_10 + ( V_164 << V_82 ) ,
V_158 -> V_166 - V_158 -> V_165 ) ;
}
void __weak F_233 ( void )
{
}
static int F_234 ( T_2 * V_12 , T_11 V_167 , unsigned long V_10 , void * V_168 )
{
T_2 * * * V_4 = V_168 ;
if ( V_4 ) {
* ( * V_4 ) = V_12 ;
( * V_4 ) ++ ;
}
return 0 ;
}
struct V_115 * F_235 ( T_9 V_47 , T_2 * * V_169 )
{
struct V_115 * V_122 ;
V_122 = F_187 ( V_47 , V_125 ,
F_184 ( 0 ) ) ;
if ( V_122 == NULL )
return NULL ;
if ( F_236 ( & V_14 , ( unsigned long ) V_122 -> V_10 ,
V_47 , F_234 , V_169 ? & V_169 : NULL ) ) {
F_237 ( V_122 ) ;
return NULL ;
}
return V_122 ;
}
void F_237 ( struct V_115 * V_122 )
{
struct V_115 * V_28 ;
V_28 = F_189 ( V_122 -> V_10 ) ;
F_28 ( V_28 != V_122 ) ;
F_86 ( V_122 ) ;
}
static struct V_35 * F_238 ( struct V_36 * V_37 )
{
return F_239 ( V_37 , struct V_35 , V_36 ) ;
}
static bool F_240 ( unsigned long V_11 ,
struct V_35 * * V_170 ,
struct V_35 * * V_171 )
{
struct V_36 * V_37 = V_38 . V_36 ;
struct V_35 * V_39 = NULL ;
while ( V_37 ) {
V_39 = F_60 ( V_37 , struct V_35 , V_36 ) ;
if ( V_11 < V_39 -> va_end )
V_37 = V_37 -> V_40 ;
else if ( V_11 > V_39 -> va_end )
V_37 = V_37 -> V_41 ;
else
break;
}
if ( ! V_39 )
return false ;
if ( V_39 -> va_end > V_11 ) {
* V_170 = V_39 ;
* V_171 = F_238 ( F_65 ( & ( * V_170 ) -> V_36 ) ) ;
} else {
* V_171 = V_39 ;
* V_170 = F_238 ( F_241 ( & ( * V_171 ) -> V_36 ) ) ;
}
return true ;
}
static unsigned long F_242 ( struct V_35 * * V_170 ,
struct V_35 * * V_171 ,
unsigned long V_48 )
{
const unsigned long V_172 = V_73 & ~ ( V_48 - 1 ) ;
unsigned long V_10 ;
if ( * V_170 )
V_10 = F_155 ( ( * V_170 ) -> va_start & ~ ( V_48 - 1 ) , V_172 ) ;
else
V_10 = V_172 ;
while ( * V_171 && ( * V_171 ) -> va_end > V_10 ) {
* V_170 = * V_171 ;
* V_171 = F_238 ( F_65 ( & ( * V_170 ) -> V_36 ) ) ;
}
return V_10 ;
}
struct V_115 * * F_243 ( const unsigned long * V_173 ,
const T_9 * V_174 , int V_175 ,
T_9 V_48 )
{
const unsigned long V_176 = F_76 ( V_72 , V_48 ) ;
const unsigned long V_172 = V_73 & ~ ( V_48 - 1 ) ;
struct V_35 * * V_177 , * V_45 , * V_17 ;
struct V_115 * * V_178 ;
int V_122 , V_179 , V_180 , V_181 ;
unsigned long V_182 , V_26 , V_11 , V_183 ;
bool V_53 = false ;
F_28 ( F_68 ( V_48 ) || ! F_69 ( V_48 ) ) ;
for ( V_180 = 0 , V_122 = 0 ; V_122 < V_175 ; V_122 ++ ) {
V_26 = V_173 [ V_122 ] ;
V_11 = V_26 + V_174 [ V_122 ] ;
F_28 ( ! F_80 ( V_173 [ V_122 ] , V_48 ) ) ;
F_28 ( ! F_80 ( V_174 [ V_122 ] , V_48 ) ) ;
if ( V_26 > V_173 [ V_180 ] )
V_180 = V_122 ;
for ( V_179 = 0 ; V_179 < V_175 ; V_179 ++ ) {
unsigned long V_184 = V_173 [ V_179 ] ;
unsigned long V_185 = V_184 + V_174 [ V_179 ] ;
if ( V_179 == V_122 )
continue;
F_28 ( V_184 >= V_26 && V_184 < V_11 ) ;
F_28 ( V_185 <= V_11 && V_185 > V_26 ) ;
}
}
V_183 = V_173 [ V_180 ] + V_174 [ V_180 ] ;
if ( V_172 - V_176 < V_183 ) {
F_9 ( true ) ;
return NULL ;
}
V_178 = F_244 ( V_175 , sizeof( V_178 [ 0 ] ) , V_114 ) ;
V_177 = F_244 ( V_175 , sizeof( V_177 [ 0 ] ) , V_114 ) ;
if ( ! V_177 || ! V_178 )
goto V_186;
for ( V_122 = 0 ; V_122 < V_175 ; V_122 ++ ) {
V_177 [ V_122 ] = F_168 ( sizeof( struct V_35 ) , V_114 ) ;
V_178 [ V_122 ] = F_168 ( sizeof( struct V_115 ) , V_114 ) ;
if ( ! V_177 [ V_122 ] || ! V_178 [ V_122 ] )
goto V_187;
}
V_57:
F_75 ( & V_58 ) ;
V_122 = V_181 = V_180 ;
V_26 = V_173 [ V_122 ] ;
V_11 = V_26 + V_174 [ V_122 ] ;
if ( ! F_240 ( V_74 , & V_17 , & V_45 ) ) {
V_182 = V_172 - V_183 ;
goto V_65;
}
V_182 = F_242 ( & V_17 , & V_45 , V_48 ) - V_11 ;
while ( true ) {
F_28 ( V_17 && V_17 -> va_end <= V_182 + V_11 ) ;
F_28 ( V_45 && V_45 -> va_end > V_182 + V_11 ) ;
if ( V_182 + V_183 < V_176 + V_183 ) {
F_79 ( & V_58 ) ;
if ( ! V_53 ) {
F_81 () ;
V_53 = true ;
goto V_57;
}
goto V_187;
}
if ( V_17 && V_17 -> va_start < V_182 + V_11 ) {
V_182 = F_242 ( & V_17 , & V_45 , V_48 ) - V_11 ;
V_181 = V_122 ;
continue;
}
if ( V_45 && V_45 -> va_end > V_182 + V_26 ) {
V_17 = V_45 ;
V_45 = F_238 ( F_65 ( & V_17 -> V_36 ) ) ;
V_182 = F_242 ( & V_17 , & V_45 , V_48 ) - V_11 ;
V_181 = V_122 ;
continue;
}
V_122 = ( V_122 + V_175 - 1 ) % V_175 ;
if ( V_122 == V_181 )
break;
V_26 = V_173 [ V_122 ] ;
V_11 = V_26 + V_174 [ V_122 ] ;
F_240 ( V_182 + V_11 , & V_17 , & V_45 ) ;
}
V_65:
for ( V_122 = 0 ; V_122 < V_175 ; V_122 ++ ) {
struct V_35 * V_39 = V_177 [ V_122 ] ;
V_39 -> va_start = V_182 + V_173 [ V_122 ] ;
V_39 -> va_end = V_39 -> va_start + V_174 [ V_122 ] ;
F_61 ( V_39 ) ;
}
V_74 = V_182 + V_173 [ V_180 ] ;
F_79 ( & V_58 ) ;
for ( V_122 = 0 ; V_122 < V_175 ; V_122 ++ )
F_174 ( V_178 [ V_122 ] , V_177 [ V_122 ] , V_145 ,
F_243 ) ;
F_86 ( V_177 ) ;
return V_178 ;
V_187:
for ( V_122 = 0 ; V_122 < V_175 ; V_122 ++ ) {
F_86 ( V_177 [ V_122 ] ) ;
F_86 ( V_178 [ V_122 ] ) ;
}
V_186:
F_86 ( V_177 ) ;
F_86 ( V_178 ) ;
return NULL ;
}
void F_245 ( struct V_115 * * V_178 , int V_175 )
{
int V_119 ;
for ( V_119 = 0 ; V_119 < V_175 ; V_119 ++ )
F_237 ( V_178 [ V_119 ] ) ;
F_86 ( V_178 ) ;
}
static void * F_246 ( struct V_188 * V_189 , T_12 * V_190 )
__acquires( &vmap_area_lock
static void * F_247 ( struct V_188 * V_189 , void * V_4 , T_12 * V_190 )
{
return F_248 ( V_4 , & V_46 , V_190 ) ;
}
static void F_249 ( struct V_188 * V_189 , void * V_4 )
__releases( &vmap_area_lock
static void F_250 ( struct V_188 * V_189 , struct V_115 * V_191 )
{
if ( F_251 ( V_192 ) ) {
unsigned int V_23 , * V_193 = V_189 -> V_194 ;
if ( ! V_193 )
return;
if ( V_191 -> V_66 & V_124 )
return;
F_252 () ;
memset ( V_193 , 0 , V_195 * sizeof( unsigned int ) ) ;
for ( V_23 = 0 ; V_23 < V_191 -> V_131 ; V_23 ++ )
V_193 [ F_253 ( V_191 -> V_22 [ V_23 ] ) ] ++ ;
F_254 (nr, N_HIGH_MEMORY)
if ( V_193 [ V_23 ] )
F_255 ( V_189 , L_6 , V_23 , V_193 [ V_23 ] ) ;
}
}
static int F_256 ( struct V_188 * V_189 , void * V_4 )
{
struct V_35 * V_39 ;
struct V_115 * V_191 ;
V_39 = F_257 ( V_4 , struct V_35 , V_8 ) ;
if ( ! ( V_39 -> V_66 & V_121 ) )
return 0 ;
V_191 = V_39 -> V_116 ;
F_255 ( V_189 , L_7 ,
V_191 -> V_10 , V_191 -> V_10 + V_191 -> V_47 , V_191 -> V_47 ) ;
if ( V_191 -> V_123 )
F_255 ( V_189 , L_8 , V_191 -> V_123 ) ;
if ( V_191 -> V_131 )
F_255 ( V_189 , L_9 , V_191 -> V_131 ) ;
if ( V_191 -> V_196 )
F_255 ( V_189 , L_10 , & V_191 -> V_196 ) ;
if ( V_191 -> V_66 & V_125 )
F_258 ( V_189 , L_11 ) ;
if ( V_191 -> V_66 & V_145 )
F_258 ( V_189 , L_12 ) ;
if ( V_191 -> V_66 & V_197 )
F_258 ( V_189 , L_13 ) ;
if ( V_191 -> V_66 & V_147 )
F_258 ( V_189 , L_14 ) ;
if ( F_47 ( V_191 -> V_22 ) )
F_258 ( V_189 , L_15 ) ;
F_250 ( V_189 , V_191 ) ;
F_259 ( V_189 , '\n' ) ;
return 0 ;
}
static int F_260 ( struct V_198 * V_198 , struct V_199 * V_199 )
{
if ( F_251 ( V_192 ) )
return F_261 ( V_199 , & V_200 ,
V_195 * sizeof( unsigned int ) ) ;
else
return F_262 ( V_199 , & V_200 ) ;
}
static int T_8 F_263 ( void )
{
F_264 ( L_16 , V_201 , NULL , & V_202 ) ;
return 0 ;
}
