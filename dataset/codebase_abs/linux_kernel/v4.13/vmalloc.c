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
F_52 ( F_53 ( * V_16 ) ) ;
if ( F_54 ( * V_16 ) || F_53 ( * V_16 ) )
return NULL ;
V_9 = F_13 ( V_16 , V_10 ) ;
F_52 ( F_55 ( * V_9 ) ) ;
if ( F_56 ( * V_9 ) || F_55 ( * V_9 ) )
return NULL ;
V_34 = F_57 ( V_9 , V_10 ) ;
V_12 = * V_34 ;
if ( F_11 ( V_12 ) )
V_21 = F_58 ( V_12 ) ;
F_59 ( V_34 ) ;
return V_21 ;
}
unsigned long F_60 ( const void * V_33 )
{
return F_61 ( F_48 ( V_33 ) ) ;
}
static struct V_35 * F_62 ( unsigned long V_10 )
{
struct V_36 * V_37 = V_38 . V_36 ;
while ( V_37 ) {
struct V_35 * V_39 ;
V_39 = F_63 ( V_37 , struct V_35 , V_36 ) ;
if ( V_10 < V_39 -> va_start )
V_37 = V_37 -> V_40 ;
else if ( V_10 >= V_39 -> va_end )
V_37 = V_37 -> V_41 ;
else
return V_39 ;
}
return NULL ;
}
static void F_64 ( struct V_35 * V_39 )
{
struct V_36 * * V_4 = & V_38 . V_36 ;
struct V_36 * V_42 = NULL ;
struct V_36 * V_43 ;
while ( * V_4 ) {
struct V_35 * V_44 ;
V_42 = * V_4 ;
V_44 = F_63 ( V_42 , struct V_35 , V_36 ) ;
if ( V_39 -> va_start < V_44 -> va_end )
V_4 = & ( * V_4 ) -> V_40 ;
else if ( V_39 -> va_end > V_44 -> va_start )
V_4 = & ( * V_4 ) -> V_41 ;
else
F_65 () ;
}
F_66 ( & V_39 -> V_36 , V_42 , V_4 ) ;
F_67 ( & V_39 -> V_36 , & V_38 ) ;
V_43 = F_68 ( & V_39 -> V_36 ) ;
if ( V_43 ) {
struct V_35 * V_45 ;
V_45 = F_63 ( V_43 , struct V_35 , V_36 ) ;
F_69 ( & V_39 -> V_8 , & V_45 -> V_8 ) ;
} else
F_69 ( & V_39 -> V_8 , & V_46 ) ;
}
static struct V_35 * F_70 ( unsigned long V_47 ,
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
F_28 ( F_71 ( V_47 ) ) ;
F_28 ( ! F_72 ( V_48 ) ) ;
F_73 () ;
V_39 = F_74 ( sizeof( struct V_35 ) ,
V_52 & V_55 , V_51 ) ;
if ( F_75 ( ! V_39 ) )
return F_76 ( - V_24 ) ;
F_77 ( & V_39 -> V_36 , V_56 , V_52 & V_55 ) ;
V_57:
F_78 ( & V_58 ) ;
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
V_54 = F_63 ( V_59 , struct V_35 , V_36 ) ;
V_10 = F_79 ( V_54 -> va_end , V_48 ) ;
if ( V_10 < V_49 )
goto V_63;
if ( V_10 + V_47 < V_10 )
goto V_64;
} else {
V_10 = F_79 ( V_49 , V_48 ) ;
if ( V_10 + V_47 < V_10 )
goto V_64;
V_37 = V_38 . V_36 ;
V_54 = NULL ;
while ( V_37 ) {
struct V_35 * V_43 ;
V_43 = F_63 ( V_37 , struct V_35 , V_36 ) ;
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
V_10 = F_79 ( V_54 -> va_end , V_48 ) ;
if ( V_10 + V_47 < V_10 )
goto V_64;
if ( F_80 ( & V_54 -> V_8 , & V_46 ) )
goto V_65;
V_54 = F_81 ( V_54 , V_8 ) ;
}
V_65:
if ( V_10 + V_47 > V_50 )
goto V_64;
V_39 -> va_start = V_10 ;
V_39 -> va_end = V_10 + V_47 ;
V_39 -> V_66 = 0 ;
F_64 ( V_39 ) ;
V_59 = & V_39 -> V_36 ;
F_82 ( & V_58 ) ;
F_28 ( ! F_83 ( V_39 -> va_start , V_48 ) ) ;
F_28 ( V_39 -> va_start < V_49 ) ;
F_28 ( V_39 -> va_end > V_50 ) ;
return V_39 ;
V_64:
F_82 ( & V_58 ) ;
if ( ! V_53 ) {
F_84 () ;
V_53 = 1 ;
goto V_57;
}
if ( F_85 ( V_52 ) ) {
unsigned long V_67 = 0 ;
F_86 ( & V_68 , 0 , & V_67 ) ;
if ( V_67 > 0 ) {
V_53 = 0 ;
goto V_57;
}
}
if ( ! ( V_52 & V_69 ) && F_87 () )
F_88 ( L_1 ,
V_47 ) ;
F_89 ( V_39 ) ;
return F_76 ( - V_25 ) ;
}
int F_90 ( struct V_70 * V_71 )
{
return F_91 ( & V_68 , V_71 ) ;
}
int F_92 ( struct V_70 * V_71 )
{
return F_93 ( & V_68 , V_71 ) ;
}
static void F_94 ( struct V_35 * V_39 )
{
F_28 ( F_95 ( & V_39 -> V_36 ) ) ;
if ( V_59 ) {
if ( V_39 -> va_end < V_61 ) {
V_59 = NULL ;
} else {
struct V_35 * V_72 ;
V_72 = F_63 ( V_59 , struct V_35 , V_36 ) ;
if ( V_39 -> va_start <= V_72 -> va_start ) {
V_59 = F_68 ( & V_39 -> V_36 ) ;
}
}
}
F_96 ( & V_39 -> V_36 , & V_38 ) ;
F_97 ( & V_39 -> V_36 ) ;
F_98 ( & V_39 -> V_8 ) ;
if ( V_39 -> va_end > V_73 && V_39 -> va_end <= V_74 )
V_75 = F_99 ( V_75 , V_39 -> va_end ) ;
F_100 ( V_39 , V_76 ) ;
}
static void F_101 ( struct V_35 * V_39 )
{
F_78 ( & V_58 ) ;
F_94 ( V_39 ) ;
F_82 ( & V_58 ) ;
}
static void F_102 ( struct V_35 * V_39 )
{
F_27 ( V_39 -> va_start , V_39 -> va_end ) ;
}
static void F_103 ( unsigned long V_26 , unsigned long V_11 )
{
if ( F_104 () ) {
F_27 ( V_26 , V_11 ) ;
F_105 ( V_26 , V_11 ) ;
}
}
static unsigned long F_106 ( void )
{
unsigned int log ;
log = F_107 ( F_108 () ) ;
return log * ( 32UL * 1024 * 1024 / V_15 ) ;
}
void F_109 ( void )
{
F_110 ( & V_77 , F_106 () + 1 ) ;
}
static bool F_111 ( unsigned long V_26 , unsigned long V_11 )
{
struct V_6 * V_78 ;
struct V_35 * V_39 ;
struct V_35 * V_79 ;
bool V_80 = false ;
F_112 ( & V_81 ) ;
V_78 = F_3 ( & V_82 ) ;
F_113 (va, valist, purge_list) {
if ( V_39 -> va_start < V_26 )
V_26 = V_39 -> va_start ;
if ( V_39 -> va_end > V_11 )
V_11 = V_39 -> va_end ;
V_80 = true ;
}
if ( ! V_80 )
return false ;
F_105 ( V_26 , V_11 ) ;
F_78 ( & V_58 ) ;
F_114 (va, n_va, valist, purge_list) {
int V_23 = ( V_39 -> va_end - V_39 -> va_start ) >> V_83 ;
F_94 ( V_39 ) ;
F_115 ( V_23 , & V_77 ) ;
F_116 ( & V_58 ) ;
}
F_82 ( & V_58 ) ;
return true ;
}
static void F_117 ( void )
{
if ( F_118 ( & V_81 ) ) {
F_111 ( V_84 , 0 ) ;
F_119 ( & V_81 ) ;
}
}
static void F_84 ( void )
{
F_120 ( & V_81 ) ;
F_121 () ;
F_111 ( V_84 , 0 ) ;
F_119 ( & V_81 ) ;
}
static void F_122 ( struct V_35 * V_39 )
{
int V_85 ;
V_85 = F_123 ( ( V_39 -> va_end - V_39 -> va_start ) >> V_83 ,
& V_77 ) ;
F_124 ( & V_39 -> V_86 , & V_82 ) ;
if ( F_75 ( V_85 > F_106 () ) )
F_117 () ;
}
static void F_125 ( struct V_35 * V_39 )
{
F_126 ( V_39 -> va_start , V_39 -> va_end ) ;
F_102 ( V_39 ) ;
F_122 ( V_39 ) ;
}
static struct V_35 * F_127 ( unsigned long V_10 )
{
struct V_35 * V_39 ;
F_78 ( & V_58 ) ;
V_39 = F_62 ( V_10 ) ;
F_82 ( & V_58 ) ;
return V_39 ;
}
static unsigned long F_128 ( unsigned long V_10 )
{
V_10 -= V_73 & ~ ( V_87 - 1 ) ;
V_10 /= V_87 ;
return V_10 ;
}
static void * F_129 ( unsigned long va_start , unsigned long V_88 )
{
unsigned long V_10 ;
V_10 = va_start + ( V_88 << V_83 ) ;
F_28 ( F_128 ( V_10 ) != F_128 ( va_start ) ) ;
return ( void * ) V_10 ;
}
static void * F_130 ( unsigned int V_89 , T_7 V_52 )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_35 * V_39 ;
unsigned long V_94 ;
int V_51 , V_27 ;
void * V_95 ;
V_51 = F_131 () ;
V_93 = F_74 ( sizeof( struct V_92 ) ,
V_52 & V_55 , V_51 ) ;
if ( F_75 ( ! V_93 ) )
return F_76 ( - V_24 ) ;
V_39 = F_70 ( V_87 , V_87 ,
V_73 , V_74 ,
V_51 , V_52 ) ;
if ( F_132 ( V_39 ) ) {
F_89 ( V_93 ) ;
return F_133 ( V_39 ) ;
}
V_27 = F_134 ( V_52 ) ;
if ( F_75 ( V_27 ) ) {
F_89 ( V_93 ) ;
F_101 ( V_39 ) ;
return F_76 ( V_27 ) ;
}
V_95 = F_129 ( V_39 -> va_start , 0 ) ;
F_135 ( & V_93 -> V_96 ) ;
V_93 -> V_39 = V_39 ;
F_28 ( V_97 <= ( 1UL << V_89 ) ) ;
V_93 -> free = V_97 - ( 1UL << V_89 ) ;
V_93 -> V_98 = 0 ;
V_93 -> V_99 = V_97 ;
V_93 -> V_100 = 0 ;
F_136 ( & V_93 -> V_101 ) ;
V_94 = F_128 ( V_39 -> va_start ) ;
F_78 ( & V_102 ) ;
V_27 = F_137 ( & V_103 , V_94 , V_93 ) ;
F_82 ( & V_102 ) ;
F_28 ( V_27 ) ;
F_138 () ;
V_91 = & F_139 ( V_90 ) ;
F_78 ( & V_91 -> V_96 ) ;
F_140 ( & V_93 -> V_101 , & V_91 -> free ) ;
F_82 ( & V_91 -> V_96 ) ;
F_141 ( V_90 ) ;
return V_95 ;
}
static void F_142 ( struct V_92 * V_93 )
{
struct V_92 * V_43 ;
unsigned long V_94 ;
V_94 = F_128 ( V_93 -> V_39 -> va_start ) ;
F_78 ( & V_102 ) ;
V_43 = F_143 ( & V_103 , V_94 ) ;
F_82 ( & V_102 ) ;
F_28 ( V_43 != V_93 ) ;
F_122 ( V_93 -> V_39 ) ;
F_100 ( V_93 , V_76 ) ;
}
static void F_144 ( int V_104 )
{
F_145 ( V_105 ) ;
struct V_92 * V_93 ;
struct V_92 * V_106 ;
struct V_90 * V_91 = & F_146 ( V_90 , V_104 ) ;
F_147 () ;
F_148 (vb, &vbq->free, free_list) {
if ( ! ( V_93 -> free + V_93 -> V_98 == V_97 && V_93 -> V_98 != V_97 ) )
continue;
F_78 ( & V_93 -> V_96 ) ;
if ( V_93 -> free + V_93 -> V_98 == V_97 && V_93 -> V_98 != V_97 ) {
V_93 -> free = 0 ;
V_93 -> V_98 = V_97 ;
V_93 -> V_99 = 0 ;
V_93 -> V_100 = V_97 ;
F_78 ( & V_91 -> V_96 ) ;
F_98 ( & V_93 -> V_101 ) ;
F_82 ( & V_91 -> V_96 ) ;
F_82 ( & V_93 -> V_96 ) ;
F_149 ( & V_93 -> V_105 , & V_105 ) ;
} else
F_82 ( & V_93 -> V_96 ) ;
}
F_150 () ;
F_151 (vb, n_vb, &purge, purge) {
F_152 ( & V_93 -> V_105 ) ;
F_142 ( V_93 ) ;
}
}
static void F_121 ( void )
{
int V_104 ;
F_153 (cpu)
F_144 ( V_104 ) ;
}
static void * F_154 ( unsigned long V_47 , T_7 V_52 )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
void * V_95 = NULL ;
unsigned int V_89 ;
F_28 ( F_71 ( V_47 ) ) ;
F_28 ( V_47 > V_15 * V_107 ) ;
if ( F_9 ( V_47 == 0 ) ) {
return NULL ;
}
V_89 = F_155 ( V_47 ) ;
F_147 () ;
V_91 = & F_139 ( V_90 ) ;
F_148 (vb, &vbq->free, free_list) {
unsigned long V_88 ;
F_78 ( & V_93 -> V_96 ) ;
if ( V_93 -> free < ( 1UL << V_89 ) ) {
F_82 ( & V_93 -> V_96 ) ;
continue;
}
V_88 = V_97 - V_93 -> free ;
V_95 = F_129 ( V_93 -> V_39 -> va_start , V_88 ) ;
V_93 -> free -= 1UL << V_89 ;
if ( V_93 -> free == 0 ) {
F_78 ( & V_91 -> V_96 ) ;
F_98 ( & V_93 -> V_101 ) ;
F_82 ( & V_91 -> V_96 ) ;
}
F_82 ( & V_93 -> V_96 ) ;
break;
}
F_141 ( V_90 ) ;
F_150 () ;
if ( ! V_95 )
V_95 = F_130 ( V_89 , V_52 ) ;
return V_95 ;
}
static void F_156 ( const void * V_10 , unsigned long V_47 )
{
unsigned long V_108 ;
unsigned long V_94 ;
unsigned int V_89 ;
struct V_92 * V_93 ;
F_28 ( F_71 ( V_47 ) ) ;
F_28 ( V_47 > V_15 * V_107 ) ;
F_126 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_47 ) ;
V_89 = F_155 ( V_47 ) ;
V_108 = ( unsigned long ) V_10 & ( V_87 - 1 ) ;
V_108 >>= V_83 ;
V_94 = F_128 ( ( unsigned long ) V_10 ) ;
F_147 () ;
V_93 = F_157 ( & V_103 , V_94 ) ;
F_150 () ;
F_28 ( ! V_93 ) ;
F_27 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_47 ) ;
F_78 ( & V_93 -> V_96 ) ;
V_93 -> V_99 = F_158 ( V_93 -> V_99 , V_108 ) ;
V_93 -> V_100 = F_99 ( V_93 -> V_100 , V_108 + ( 1UL << V_89 ) ) ;
V_93 -> V_98 += 1UL << V_89 ;
if ( V_93 -> V_98 == V_97 ) {
F_28 ( V_93 -> free ) ;
F_82 ( & V_93 -> V_96 ) ;
F_142 ( V_93 ) ;
} else
F_82 ( & V_93 -> V_96 ) ;
}
void F_159 ( void )
{
unsigned long V_26 = V_84 , V_11 = 0 ;
int V_104 ;
int V_109 = 0 ;
if ( F_75 ( ! V_110 ) )
return;
F_73 () ;
F_153 (cpu) {
struct V_90 * V_91 = & F_146 ( V_90 , V_104 ) ;
struct V_92 * V_93 ;
F_147 () ;
F_148 (vb, &vbq->free, free_list) {
F_78 ( & V_93 -> V_96 ) ;
if ( V_93 -> V_98 ) {
unsigned long va_start = V_93 -> V_39 -> va_start ;
unsigned long V_111 , V_112 ;
V_111 = va_start + ( V_93 -> V_99 << V_83 ) ;
V_112 = va_start + ( V_93 -> V_100 << V_83 ) ;
V_26 = F_158 ( V_111 , V_26 ) ;
V_11 = F_99 ( V_112 , V_11 ) ;
V_109 = 1 ;
}
F_82 ( & V_93 -> V_96 ) ;
}
F_150 () ;
}
F_120 ( & V_81 ) ;
F_121 () ;
if ( ! F_111 ( V_26 , V_11 ) && V_109 )
F_105 ( V_26 , V_11 ) ;
F_119 ( & V_81 ) ;
}
void F_160 ( const void * V_113 , unsigned int V_114 )
{
unsigned long V_47 = ( unsigned long ) V_114 << V_83 ;
unsigned long V_10 = ( unsigned long ) V_113 ;
struct V_35 * V_39 ;
F_73 () ;
F_28 ( ! V_10 ) ;
F_28 ( V_10 < V_73 ) ;
F_28 ( V_10 > V_74 ) ;
F_28 ( ! F_161 ( V_10 ) ) ;
F_162 ( V_113 , V_47 ) ;
F_103 ( V_10 , V_10 + V_47 ) ;
if ( F_163 ( V_114 <= V_107 ) ) {
F_156 ( V_113 , V_47 ) ;
return;
}
V_39 = F_127 ( V_10 ) ;
F_28 ( ! V_39 ) ;
F_125 ( V_39 ) ;
}
void * F_164 ( struct V_21 * * V_22 , unsigned int V_114 , int V_51 , T_6 V_20 )
{
unsigned long V_47 = ( unsigned long ) V_114 << V_83 ;
unsigned long V_10 ;
void * V_113 ;
if ( F_163 ( V_114 <= V_107 ) ) {
V_113 = F_154 ( V_47 , V_115 ) ;
if ( F_132 ( V_113 ) )
return NULL ;
V_10 = ( unsigned long ) V_113 ;
} else {
struct V_35 * V_39 ;
V_39 = F_70 ( V_47 , V_15 ,
V_73 , V_74 , V_51 , V_115 ) ;
if ( F_132 ( V_39 ) )
return NULL ;
V_10 = V_39 -> va_start ;
V_113 = ( void * ) V_10 ;
}
if ( F_43 ( V_10 , V_10 + V_47 , V_20 , V_22 ) < 0 ) {
F_160 ( V_113 , V_114 ) ;
return NULL ;
}
return V_113 ;
}
void T_8 F_165 ( struct V_116 * V_117 )
{
struct V_116 * V_43 , * * V_4 ;
F_28 ( V_110 ) ;
for ( V_4 = & V_118 ; ( V_43 = * V_4 ) != NULL ; V_4 = & V_43 -> V_17 ) {
if ( V_43 -> V_10 >= V_117 -> V_10 ) {
F_28 ( V_43 -> V_10 < V_117 -> V_10 + V_117 -> V_47 ) ;
break;
} else
F_28 ( V_43 -> V_10 + V_43 -> V_47 > V_117 -> V_10 ) ;
}
V_117 -> V_17 = * V_4 ;
* V_4 = V_117 ;
}
void T_8 F_166 ( struct V_116 * V_117 , T_9 V_48 )
{
static T_9 T_10 V_119 ;
unsigned long V_10 ;
V_10 = F_79 ( V_73 + T_10 , V_48 ) ;
T_10 = F_167 ( V_10 + V_117 -> V_47 ) - V_73 ;
V_117 -> V_10 = ( void * ) V_10 ;
F_165 ( V_117 ) ;
}
void T_8 F_168 ( void )
{
struct V_35 * V_39 ;
struct V_116 * V_43 ;
int V_120 ;
F_153 (i) {
struct V_90 * V_91 ;
struct V_3 * V_4 ;
V_91 = & F_146 ( V_90 , V_120 ) ;
F_135 ( & V_91 -> V_96 ) ;
F_136 ( & V_91 -> free ) ;
V_4 = & F_146 ( V_3 , V_120 ) ;
F_169 ( & V_4 -> V_8 ) ;
F_170 ( & V_4 -> V_5 , F_1 ) ;
}
for ( V_43 = V_118 ; V_43 ; V_43 = V_43 -> V_17 ) {
V_39 = F_171 ( sizeof( struct V_35 ) , V_121 ) ;
V_39 -> V_66 = V_122 ;
V_39 -> va_start = ( unsigned long ) V_43 -> V_10 ;
V_39 -> va_end = V_39 -> va_start + V_43 -> V_47 ;
V_39 -> V_117 = V_43 ;
F_64 ( V_39 ) ;
}
V_75 = V_74 ;
V_110 = true ;
}
int F_172 ( unsigned long V_10 , unsigned long V_47 ,
T_6 V_20 , struct V_21 * * V_22 )
{
return F_42 ( V_10 , V_10 + V_47 , V_20 , V_22 ) ;
}
void F_173 ( unsigned long V_10 , unsigned long V_47 )
{
F_27 ( V_10 , V_10 + V_47 ) ;
}
void F_174 ( unsigned long V_10 , unsigned long V_47 )
{
unsigned long V_11 = V_10 + V_47 ;
F_126 ( V_10 , V_11 ) ;
F_27 ( V_10 , V_11 ) ;
F_105 ( V_10 , V_11 ) ;
}
int F_175 ( struct V_116 * V_123 , T_6 V_20 , struct V_21 * * V_22 )
{
unsigned long V_10 = ( unsigned long ) V_123 -> V_10 ;
unsigned long V_11 = V_10 + F_176 ( V_123 ) ;
int V_27 ;
V_27 = F_43 ( V_10 , V_11 , V_20 , V_22 ) ;
return V_27 > 0 ? 0 : V_27 ;
}
static void F_177 ( struct V_116 * V_117 , struct V_35 * V_39 ,
unsigned long V_66 , const void * V_124 )
{
F_78 ( & V_58 ) ;
V_117 -> V_66 = V_66 ;
V_117 -> V_10 = ( void * ) V_39 -> va_start ;
V_117 -> V_47 = V_39 -> va_end - V_39 -> va_start ;
V_117 -> V_124 = V_124 ;
V_39 -> V_117 = V_117 ;
V_39 -> V_66 |= V_122 ;
F_82 ( & V_58 ) ;
}
static void F_178 ( struct V_116 * V_117 )
{
F_179 () ;
V_117 -> V_66 &= ~ V_125 ;
}
static struct V_116 * F_180 ( unsigned long V_47 ,
unsigned long V_48 , unsigned long V_66 , unsigned long V_26 ,
unsigned long V_11 , int V_51 , T_7 V_52 , const void * V_124 )
{
struct V_35 * V_39 ;
struct V_116 * V_123 ;
F_28 ( F_181 () ) ;
V_47 = F_182 ( V_47 ) ;
if ( F_75 ( ! V_47 ) )
return NULL ;
if ( V_66 & V_126 )
V_48 = 1ul << F_183 ( int , F_184 ( V_47 ) ,
V_83 , V_127 ) ;
V_123 = F_185 ( sizeof( * V_123 ) , V_52 & V_55 , V_51 ) ;
if ( F_75 ( ! V_123 ) )
return NULL ;
if ( ! ( V_66 & V_128 ) )
V_47 += V_15 ;
V_39 = F_70 ( V_47 , V_48 , V_26 , V_11 , V_51 , V_52 ) ;
if ( F_132 ( V_39 ) ) {
F_89 ( V_123 ) ;
return NULL ;
}
F_177 ( V_123 , V_39 , V_66 , V_124 ) ;
return V_123 ;
}
struct V_116 * F_186 ( unsigned long V_47 , unsigned long V_66 ,
unsigned long V_26 , unsigned long V_11 )
{
return F_180 ( V_47 , 1 , V_66 , V_26 , V_11 , V_129 ,
V_115 , F_187 ( 0 ) ) ;
}
struct V_116 * F_188 ( unsigned long V_47 , unsigned long V_66 ,
unsigned long V_26 , unsigned long V_11 ,
const void * V_124 )
{
return F_180 ( V_47 , 1 , V_66 , V_26 , V_11 , V_129 ,
V_115 , V_124 ) ;
}
struct V_116 * F_189 ( unsigned long V_47 , unsigned long V_66 )
{
return F_180 ( V_47 , 1 , V_66 , V_73 , V_74 ,
V_129 , V_115 ,
F_187 ( 0 ) ) ;
}
struct V_116 * F_190 ( unsigned long V_47 , unsigned long V_66 ,
const void * V_124 )
{
return F_180 ( V_47 , 1 , V_66 , V_73 , V_74 ,
V_129 , V_115 , V_124 ) ;
}
struct V_116 * F_191 ( const void * V_10 )
{
struct V_35 * V_39 ;
V_39 = F_127 ( ( unsigned long ) V_10 ) ;
if ( V_39 && V_39 -> V_66 & V_122 )
return V_39 -> V_117 ;
return NULL ;
}
struct V_116 * F_192 ( const void * V_10 )
{
struct V_35 * V_39 ;
F_73 () ;
V_39 = F_127 ( ( unsigned long ) V_10 ) ;
if ( V_39 && V_39 -> V_66 & V_122 ) {
struct V_116 * V_117 = V_39 -> V_117 ;
F_78 ( & V_58 ) ;
V_39 -> V_117 = NULL ;
V_39 -> V_66 &= ~ V_122 ;
V_39 -> V_66 |= V_130 ;
F_82 ( & V_58 ) ;
F_103 ( V_39 -> va_start , V_39 -> va_end ) ;
F_193 ( V_117 ) ;
F_125 ( V_39 ) ;
return V_117 ;
}
return NULL ;
}
static void F_5 ( const void * V_10 , int V_131 )
{
struct V_116 * V_123 ;
if ( ! V_10 )
return;
if ( F_194 ( ! F_161 ( V_10 ) , L_2 ,
V_10 ) )
return;
V_123 = F_192 ( V_10 ) ;
if ( F_75 ( ! V_123 ) ) {
F_194 ( 1 , V_132 L_3 ,
V_10 ) ;
return;
}
F_162 ( V_10 , F_176 ( V_123 ) ) ;
F_195 ( V_10 , F_176 ( V_123 ) ) ;
if ( V_131 ) {
int V_120 ;
for ( V_120 = 0 ; V_120 < V_123 -> V_133 ; V_120 ++ ) {
struct V_21 * V_21 = V_123 -> V_22 [ V_120 ] ;
F_28 ( ! V_21 ) ;
F_196 ( V_21 , 0 ) ;
}
F_197 ( V_123 -> V_22 ) ;
}
F_89 ( V_123 ) ;
return;
}
static inline void F_198 ( const void * V_10 )
{
struct V_3 * V_4 = F_199 ( & V_3 ) ;
if ( F_124 ( (struct V_6 * ) V_10 , & V_4 -> V_8 ) )
F_200 ( & V_4 -> V_5 ) ;
}
void F_201 ( const void * V_10 )
{
F_28 ( F_202 () ) ;
F_203 ( V_10 ) ;
if ( ! V_10 )
return;
F_198 ( V_10 ) ;
}
void F_204 ( const void * V_10 )
{
F_28 ( F_202 () ) ;
F_203 ( V_10 ) ;
if ( ! V_10 )
return;
if ( F_75 ( F_181 () ) )
F_198 ( V_10 ) ;
else
F_5 ( V_10 , 1 ) ;
}
void F_205 ( const void * V_10 )
{
F_28 ( F_181 () ) ;
F_73 () ;
if ( V_10 )
F_5 ( V_10 , 0 ) ;
}
void * F_206 ( struct V_21 * * V_22 , unsigned int V_114 ,
unsigned long V_66 , T_6 V_20 )
{
struct V_116 * V_123 ;
unsigned long V_47 ;
F_73 () ;
if ( V_114 > V_134 )
return NULL ;
V_47 = ( unsigned long ) V_114 << V_83 ;
V_123 = F_190 ( V_47 , V_66 , F_187 ( 0 ) ) ;
if ( ! V_123 )
return NULL ;
if ( F_175 ( V_123 , V_20 , V_22 ) ) {
F_205 ( V_123 -> V_10 ) ;
return NULL ;
}
return V_123 -> V_10 ;
}
static void * F_207 ( struct V_116 * V_123 , T_7 V_52 ,
T_6 V_20 , int V_51 )
{
struct V_21 * * V_22 ;
unsigned int V_133 , V_135 , V_120 ;
const T_7 V_136 = ( V_52 & V_55 ) | V_137 ;
const T_7 V_138 = V_52 | V_69 ;
const T_7 V_139 = ( V_52 & ( V_140 | V_141 ) ) ?
0 :
V_142 ;
V_133 = F_176 ( V_123 ) >> V_83 ;
V_135 = ( V_133 * sizeof( struct V_21 * ) ) ;
V_123 -> V_133 = V_133 ;
if ( V_135 > V_15 ) {
V_22 = F_208 ( V_135 , 1 , V_136 | V_139 ,
V_143 , V_51 , V_123 -> V_124 ) ;
} else {
V_22 = F_74 ( V_135 , V_136 , V_51 ) ;
}
V_123 -> V_22 = V_22 ;
if ( ! V_123 -> V_22 ) {
F_192 ( V_123 -> V_10 ) ;
F_89 ( V_123 ) ;
return NULL ;
}
for ( V_120 = 0 ; V_120 < V_123 -> V_133 ; V_120 ++ ) {
struct V_21 * V_21 ;
if ( F_209 ( V_144 ) ) {
V_123 -> V_133 = V_120 ;
goto V_145;
}
if ( V_51 == V_129 )
V_21 = F_210 ( V_138 | V_139 ) ;
else
V_21 = F_211 ( V_51 , V_138 | V_139 , 0 ) ;
if ( F_75 ( ! V_21 ) ) {
V_123 -> V_133 = V_120 ;
goto V_146;
}
V_123 -> V_22 [ V_120 ] = V_21 ;
if ( F_85 ( V_52 | V_139 ) )
F_212 () ;
}
if ( F_175 ( V_123 , V_20 , V_22 ) )
goto V_146;
return V_123 -> V_10 ;
V_146:
F_213 ( V_52 , NULL ,
L_4 ,
( V_123 -> V_133 * V_15 ) , V_123 -> V_47 ) ;
V_145:
F_204 ( V_123 -> V_10 ) ;
return NULL ;
}
void * F_214 ( unsigned long V_47 , unsigned long V_48 ,
unsigned long V_26 , unsigned long V_11 , T_7 V_52 ,
T_6 V_20 , unsigned long V_147 , int V_51 ,
const void * V_124 )
{
struct V_116 * V_123 ;
void * V_10 ;
unsigned long V_148 = V_47 ;
V_47 = F_182 ( V_47 ) ;
if ( ! V_47 || ( V_47 >> V_83 ) > V_134 )
goto V_146;
V_123 = F_180 ( V_47 , V_48 , V_149 | V_125 |
V_147 , V_26 , V_11 , V_51 , V_52 , V_124 ) ;
if ( ! V_123 )
goto V_146;
V_10 = F_207 ( V_123 , V_52 , V_20 , V_51 ) ;
if ( ! V_10 )
return NULL ;
F_178 ( V_123 ) ;
F_215 ( V_123 , V_47 , V_52 ) ;
return V_10 ;
V_146:
F_213 ( V_52 , NULL ,
L_5 , V_148 ) ;
return NULL ;
}
static void * F_208 ( unsigned long V_47 , unsigned long V_48 ,
T_7 V_52 , T_6 V_20 ,
int V_51 , const void * V_124 )
{
return F_214 ( V_47 , V_48 , V_73 , V_74 ,
V_52 , V_20 , 0 , V_51 , V_124 ) ;
}
void * F_216 ( unsigned long V_47 , T_7 V_52 , T_6 V_20 )
{
return F_208 ( V_47 , 1 , V_52 , V_20 , V_129 ,
F_187 ( 0 ) ) ;
}
static inline void * F_217 ( unsigned long V_47 ,
int V_51 , T_7 V_66 )
{
return F_208 ( V_47 , 1 , V_66 , V_143 ,
V_51 , F_187 ( 0 ) ) ;
}
void * F_218 ( unsigned long V_47 , int V_51 , T_7 V_66 ,
void * V_124 )
{
return F_208 ( V_47 , 1 , V_66 , V_143 , V_51 , V_124 ) ;
}
void * F_219 ( unsigned long V_47 )
{
return F_217 ( V_47 , V_129 ,
V_115 ) ;
}
void * F_220 ( unsigned long V_47 )
{
return F_217 ( V_47 , V_129 ,
V_115 | V_137 ) ;
}
void * F_221 ( unsigned long V_47 )
{
struct V_116 * V_123 ;
void * V_28 ;
V_28 = F_208 ( V_47 , V_150 ,
V_115 | V_137 ,
V_143 , V_129 ,
F_187 ( 0 ) ) ;
if ( V_28 ) {
V_123 = F_191 ( V_28 ) ;
V_123 -> V_66 |= V_151 ;
}
return V_28 ;
}
void * F_222 ( unsigned long V_47 , int V_51 )
{
return F_208 ( V_47 , 1 , V_115 , V_143 ,
V_51 , F_187 ( 0 ) ) ;
}
void * F_223 ( unsigned long V_47 , int V_51 )
{
return F_217 ( V_47 , V_51 ,
V_115 | V_137 ) ;
}
void * F_224 ( unsigned long V_47 )
{
return F_208 ( V_47 , 1 , V_115 , V_152 ,
V_129 , F_187 ( 0 ) ) ;
}
void * F_225 ( unsigned long V_47 )
{
return F_208 ( V_47 , 1 , V_153 , V_143 ,
V_129 , F_187 ( 0 ) ) ;
}
void * F_226 ( unsigned long V_47 )
{
struct V_116 * V_123 ;
void * V_28 ;
V_28 = F_208 ( V_47 , 1 , V_153 | V_137 , V_143 ,
V_129 , F_187 ( 0 ) ) ;
if ( V_28 ) {
V_123 = F_191 ( V_28 ) ;
V_123 -> V_66 |= V_151 ;
}
return V_28 ;
}
static int F_227 ( char * V_154 , char * V_10 , unsigned long V_114 )
{
struct V_21 * V_4 ;
int V_155 = 0 ;
while ( V_114 ) {
unsigned long V_108 , V_156 ;
V_108 = F_71 ( V_10 ) ;
V_156 = V_15 - V_108 ;
if ( V_156 > V_114 )
V_156 = V_114 ;
V_4 = F_48 ( V_10 ) ;
if ( V_4 ) {
void * V_157 = F_228 ( V_4 ) ;
memcpy ( V_154 , V_157 + V_108 , V_156 ) ;
F_229 ( V_157 ) ;
} else
memset ( V_154 , 0 , V_156 ) ;
V_10 += V_156 ;
V_154 += V_156 ;
V_155 += V_156 ;
V_114 -= V_156 ;
}
return V_155 ;
}
static int F_230 ( char * V_154 , char * V_10 , unsigned long V_114 )
{
struct V_21 * V_4 ;
int V_155 = 0 ;
while ( V_114 ) {
unsigned long V_108 , V_156 ;
V_108 = F_71 ( V_10 ) ;
V_156 = V_15 - V_108 ;
if ( V_156 > V_114 )
V_156 = V_114 ;
V_4 = F_48 ( V_10 ) ;
if ( V_4 ) {
void * V_157 = F_228 ( V_4 ) ;
memcpy ( V_157 + V_108 , V_154 , V_156 ) ;
F_229 ( V_157 ) ;
}
V_10 += V_156 ;
V_154 += V_156 ;
V_155 += V_156 ;
V_114 -= V_156 ;
}
return V_155 ;
}
long F_231 ( char * V_154 , char * V_10 , unsigned long V_114 )
{
struct V_35 * V_39 ;
struct V_116 * V_117 ;
char * V_95 , * V_158 = V_154 ;
unsigned long V_159 = V_114 ;
unsigned long V_37 ;
if ( ( unsigned long ) V_10 + V_114 < V_114 )
V_114 = - ( unsigned long ) V_10 ;
F_78 ( & V_58 ) ;
F_232 (va, &vmap_area_list, list) {
if ( ! V_114 )
break;
if ( ! ( V_39 -> V_66 & V_122 ) )
continue;
V_117 = V_39 -> V_117 ;
V_95 = ( char * ) V_117 -> V_10 ;
if ( V_10 >= V_95 + F_176 ( V_117 ) )
continue;
while ( V_10 < V_95 ) {
if ( V_114 == 0 )
goto V_160;
* V_154 = '\0' ;
V_154 ++ ;
V_10 ++ ;
V_114 -- ;
}
V_37 = V_95 + F_176 ( V_117 ) - V_10 ;
if ( V_37 > V_114 )
V_37 = V_114 ;
if ( ! ( V_117 -> V_66 & V_126 ) )
F_227 ( V_154 , V_10 , V_37 ) ;
else
memset ( V_154 , 0 , V_37 ) ;
V_154 += V_37 ;
V_10 += V_37 ;
V_114 -= V_37 ;
}
V_160:
F_82 ( & V_58 ) ;
if ( V_154 == V_158 )
return 0 ;
if ( V_154 != V_158 + V_159 )
memset ( V_154 , 0 , V_159 - ( V_154 - V_158 ) ) ;
return V_159 ;
}
long F_233 ( char * V_154 , char * V_10 , unsigned long V_114 )
{
struct V_35 * V_39 ;
struct V_116 * V_117 ;
char * V_95 ;
unsigned long V_37 , V_159 ;
int V_155 = 0 ;
if ( ( unsigned long ) V_10 + V_114 < V_114 )
V_114 = - ( unsigned long ) V_10 ;
V_159 = V_114 ;
F_78 ( & V_58 ) ;
F_232 (va, &vmap_area_list, list) {
if ( ! V_114 )
break;
if ( ! ( V_39 -> V_66 & V_122 ) )
continue;
V_117 = V_39 -> V_117 ;
V_95 = ( char * ) V_117 -> V_10 ;
if ( V_10 >= V_95 + F_176 ( V_117 ) )
continue;
while ( V_10 < V_95 ) {
if ( V_114 == 0 )
goto V_160;
V_154 ++ ;
V_10 ++ ;
V_114 -- ;
}
V_37 = V_95 + F_176 ( V_117 ) - V_10 ;
if ( V_37 > V_114 )
V_37 = V_114 ;
if ( ! ( V_117 -> V_66 & V_126 ) ) {
F_230 ( V_154 , V_10 , V_37 ) ;
V_155 ++ ;
}
V_154 += V_37 ;
V_10 += V_37 ;
V_114 -= V_37 ;
}
V_160:
F_82 ( & V_58 ) ;
if ( ! V_155 )
return 0 ;
return V_159 ;
}
int F_234 ( struct V_161 * V_162 , unsigned long V_163 ,
void * V_164 , unsigned long V_47 )
{
struct V_116 * V_123 ;
V_47 = F_182 ( V_47 ) ;
if ( ! F_161 ( V_163 ) || ! F_161 ( V_164 ) )
return - V_165 ;
V_123 = F_191 ( V_164 ) ;
if ( ! V_123 )
return - V_165 ;
if ( ! ( V_123 -> V_66 & V_151 ) )
return - V_165 ;
if ( V_164 + V_47 > V_123 -> V_10 + V_123 -> V_47 )
return - V_165 ;
do {
struct V_21 * V_21 = F_48 ( V_164 ) ;
int V_28 ;
V_28 = F_235 ( V_162 , V_163 , V_21 ) ;
if ( V_28 )
return V_28 ;
V_163 += V_15 ;
V_164 += V_15 ;
V_47 -= V_15 ;
} while ( V_47 > 0 );
V_162 -> V_147 |= V_166 | V_167 ;
return 0 ;
}
int F_236 ( struct V_161 * V_162 , void * V_10 ,
unsigned long V_168 )
{
return F_234 ( V_162 , V_162 -> V_169 ,
V_10 + ( V_168 << V_83 ) ,
V_162 -> V_170 - V_162 -> V_169 ) ;
}
void __weak F_237 ( void )
{
}
static int F_238 ( T_2 * V_12 , T_11 V_171 , unsigned long V_10 , void * V_172 )
{
T_2 * * * V_4 = V_172 ;
if ( V_4 ) {
* ( * V_4 ) = V_12 ;
( * V_4 ) ++ ;
}
return 0 ;
}
struct V_116 * F_239 ( T_9 V_47 , T_2 * * V_173 )
{
struct V_116 * V_123 ;
V_123 = F_190 ( V_47 , V_126 ,
F_187 ( 0 ) ) ;
if ( V_123 == NULL )
return NULL ;
if ( F_240 ( & V_14 , ( unsigned long ) V_123 -> V_10 ,
V_47 , F_238 , V_173 ? & V_173 : NULL ) ) {
F_241 ( V_123 ) ;
return NULL ;
}
return V_123 ;
}
void F_241 ( struct V_116 * V_123 )
{
struct V_116 * V_28 ;
V_28 = F_192 ( V_123 -> V_10 ) ;
F_28 ( V_28 != V_123 ) ;
F_89 ( V_123 ) ;
}
static struct V_35 * F_242 ( struct V_36 * V_37 )
{
return F_243 ( V_37 , struct V_35 , V_36 ) ;
}
static bool F_244 ( unsigned long V_11 ,
struct V_35 * * V_174 ,
struct V_35 * * V_175 )
{
struct V_36 * V_37 = V_38 . V_36 ;
struct V_35 * V_39 = NULL ;
while ( V_37 ) {
V_39 = F_63 ( V_37 , struct V_35 , V_36 ) ;
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
* V_174 = V_39 ;
* V_175 = F_242 ( F_68 ( & ( * V_174 ) -> V_36 ) ) ;
} else {
* V_175 = V_39 ;
* V_174 = F_242 ( F_245 ( & ( * V_175 ) -> V_36 ) ) ;
}
return true ;
}
static unsigned long F_246 ( struct V_35 * * V_174 ,
struct V_35 * * V_175 ,
unsigned long V_48 )
{
const unsigned long V_176 = V_74 & ~ ( V_48 - 1 ) ;
unsigned long V_10 ;
if ( * V_174 )
V_10 = F_158 ( ( * V_174 ) -> va_start & ~ ( V_48 - 1 ) , V_176 ) ;
else
V_10 = V_176 ;
while ( * V_175 && ( * V_175 ) -> va_end > V_10 ) {
* V_174 = * V_175 ;
* V_175 = F_242 ( F_68 ( & ( * V_174 ) -> V_36 ) ) ;
}
return V_10 ;
}
struct V_116 * * F_247 ( const unsigned long * V_177 ,
const T_9 * V_178 , int V_179 ,
T_9 V_48 )
{
const unsigned long V_180 = F_79 ( V_73 , V_48 ) ;
const unsigned long V_176 = V_74 & ~ ( V_48 - 1 ) ;
struct V_35 * * V_181 , * V_45 , * V_17 ;
struct V_116 * * V_182 ;
int V_123 , V_183 , V_184 , V_185 ;
unsigned long V_186 , V_26 , V_11 , V_187 ;
bool V_53 = false ;
F_28 ( F_71 ( V_48 ) || ! F_72 ( V_48 ) ) ;
for ( V_184 = 0 , V_123 = 0 ; V_123 < V_179 ; V_123 ++ ) {
V_26 = V_177 [ V_123 ] ;
V_11 = V_26 + V_178 [ V_123 ] ;
F_28 ( ! F_83 ( V_177 [ V_123 ] , V_48 ) ) ;
F_28 ( ! F_83 ( V_178 [ V_123 ] , V_48 ) ) ;
if ( V_26 > V_177 [ V_184 ] )
V_184 = V_123 ;
for ( V_183 = 0 ; V_183 < V_179 ; V_183 ++ ) {
unsigned long V_188 = V_177 [ V_183 ] ;
unsigned long V_189 = V_188 + V_178 [ V_183 ] ;
if ( V_183 == V_123 )
continue;
F_28 ( V_188 >= V_26 && V_188 < V_11 ) ;
F_28 ( V_189 <= V_11 && V_189 > V_26 ) ;
}
}
V_187 = V_177 [ V_184 ] + V_178 [ V_184 ] ;
if ( V_176 - V_180 < V_187 ) {
F_9 ( true ) ;
return NULL ;
}
V_182 = F_248 ( V_179 , sizeof( V_182 [ 0 ] ) , V_115 ) ;
V_181 = F_248 ( V_179 , sizeof( V_181 [ 0 ] ) , V_115 ) ;
if ( ! V_181 || ! V_182 )
goto V_190;
for ( V_123 = 0 ; V_123 < V_179 ; V_123 ++ ) {
V_181 [ V_123 ] = F_171 ( sizeof( struct V_35 ) , V_115 ) ;
V_182 [ V_123 ] = F_171 ( sizeof( struct V_116 ) , V_115 ) ;
if ( ! V_181 [ V_123 ] || ! V_182 [ V_123 ] )
goto V_191;
}
V_57:
F_78 ( & V_58 ) ;
V_123 = V_185 = V_184 ;
V_26 = V_177 [ V_123 ] ;
V_11 = V_26 + V_178 [ V_123 ] ;
if ( ! F_244 ( V_75 , & V_17 , & V_45 ) ) {
V_186 = V_176 - V_187 ;
goto V_65;
}
V_186 = F_246 ( & V_17 , & V_45 , V_48 ) - V_11 ;
while ( true ) {
F_28 ( V_17 && V_17 -> va_end <= V_186 + V_11 ) ;
F_28 ( V_45 && V_45 -> va_end > V_186 + V_11 ) ;
if ( V_186 + V_187 < V_180 + V_187 ) {
F_82 ( & V_58 ) ;
if ( ! V_53 ) {
F_84 () ;
V_53 = true ;
goto V_57;
}
goto V_191;
}
if ( V_17 && V_17 -> va_start < V_186 + V_11 ) {
V_186 = F_246 ( & V_17 , & V_45 , V_48 ) - V_11 ;
V_185 = V_123 ;
continue;
}
if ( V_45 && V_45 -> va_end > V_186 + V_26 ) {
V_17 = V_45 ;
V_45 = F_242 ( F_68 ( & V_17 -> V_36 ) ) ;
V_186 = F_246 ( & V_17 , & V_45 , V_48 ) - V_11 ;
V_185 = V_123 ;
continue;
}
V_123 = ( V_123 + V_179 - 1 ) % V_179 ;
if ( V_123 == V_185 )
break;
V_26 = V_177 [ V_123 ] ;
V_11 = V_26 + V_178 [ V_123 ] ;
F_244 ( V_186 + V_11 , & V_17 , & V_45 ) ;
}
V_65:
for ( V_123 = 0 ; V_123 < V_179 ; V_123 ++ ) {
struct V_35 * V_39 = V_181 [ V_123 ] ;
V_39 -> va_start = V_186 + V_177 [ V_123 ] ;
V_39 -> va_end = V_39 -> va_start + V_178 [ V_123 ] ;
F_64 ( V_39 ) ;
}
V_75 = V_186 + V_177 [ V_184 ] ;
F_82 ( & V_58 ) ;
for ( V_123 = 0 ; V_123 < V_179 ; V_123 ++ )
F_177 ( V_182 [ V_123 ] , V_181 [ V_123 ] , V_149 ,
F_247 ) ;
F_89 ( V_181 ) ;
return V_182 ;
V_191:
for ( V_123 = 0 ; V_123 < V_179 ; V_123 ++ ) {
F_89 ( V_181 [ V_123 ] ) ;
F_89 ( V_182 [ V_123 ] ) ;
}
V_190:
F_89 ( V_181 ) ;
F_89 ( V_182 ) ;
return NULL ;
}
void F_249 ( struct V_116 * * V_182 , int V_179 )
{
int V_120 ;
for ( V_120 = 0 ; V_120 < V_179 ; V_120 ++ )
F_241 ( V_182 [ V_120 ] ) ;
F_89 ( V_182 ) ;
}
static void * F_250 ( struct V_192 * V_193 , T_12 * V_194 )
__acquires( &vmap_area_lock
static void * F_251 ( struct V_192 * V_193 , void * V_4 , T_12 * V_194 )
{
return F_252 ( V_4 , & V_46 , V_194 ) ;
}
static void F_253 ( struct V_192 * V_193 , void * V_4 )
__releases( &vmap_area_lock
static void F_254 ( struct V_192 * V_193 , struct V_116 * V_195 )
{
if ( F_255 ( V_196 ) ) {
unsigned int V_23 , * V_197 = V_193 -> V_198 ;
if ( ! V_197 )
return;
if ( V_195 -> V_66 & V_125 )
return;
F_256 () ;
memset ( V_197 , 0 , V_199 * sizeof( unsigned int ) ) ;
for ( V_23 = 0 ; V_23 < V_195 -> V_133 ; V_23 ++ )
V_197 [ F_257 ( V_195 -> V_22 [ V_23 ] ) ] ++ ;
F_258 (nr, N_HIGH_MEMORY)
if ( V_197 [ V_23 ] )
F_259 ( V_193 , L_6 , V_23 , V_197 [ V_23 ] ) ;
}
}
static int F_260 ( struct V_192 * V_193 , void * V_4 )
{
struct V_35 * V_39 ;
struct V_116 * V_195 ;
V_39 = F_261 ( V_4 , struct V_35 , V_8 ) ;
if ( ! ( V_39 -> V_66 & V_122 ) ) {
F_259 ( V_193 , L_7 ,
( void * ) V_39 -> va_start , ( void * ) V_39 -> va_end ,
V_39 -> va_end - V_39 -> va_start ,
V_39 -> V_66 & V_130 ? L_8 : L_9 ) ;
return 0 ;
}
V_195 = V_39 -> V_117 ;
F_259 ( V_193 , L_10 ,
V_195 -> V_10 , V_195 -> V_10 + V_195 -> V_47 , V_195 -> V_47 ) ;
if ( V_195 -> V_124 )
F_259 ( V_193 , L_11 , V_195 -> V_124 ) ;
if ( V_195 -> V_133 )
F_259 ( V_193 , L_12 , V_195 -> V_133 ) ;
if ( V_195 -> V_200 )
F_259 ( V_193 , L_13 , & V_195 -> V_200 ) ;
if ( V_195 -> V_66 & V_126 )
F_262 ( V_193 , L_14 ) ;
if ( V_195 -> V_66 & V_149 )
F_262 ( V_193 , L_15 ) ;
if ( V_195 -> V_66 & V_201 )
F_262 ( V_193 , L_16 ) ;
if ( V_195 -> V_66 & V_151 )
F_262 ( V_193 , L_17 ) ;
if ( F_47 ( V_195 -> V_22 ) )
F_262 ( V_193 , L_18 ) ;
F_254 ( V_193 , V_195 ) ;
F_263 ( V_193 , '\n' ) ;
return 0 ;
}
static int F_264 ( struct V_202 * V_202 , struct V_203 * V_203 )
{
if ( F_255 ( V_196 ) )
return F_265 ( V_203 , & V_204 ,
V_199 * sizeof( unsigned int ) ) ;
else
return F_266 ( V_203 , & V_204 ) ;
}
static int T_8 F_267 ( void )
{
F_268 ( L_19 , V_205 , NULL , & V_206 ) ;
return 0 ;
}
