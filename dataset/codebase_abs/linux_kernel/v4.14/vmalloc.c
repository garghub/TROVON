static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 , * V_8 ;
F_3 (llnode, t, llist_del_all(&p->list))
F_4 ( ( void * ) V_8 , 1 ) ;
}
static void F_5 ( T_1 * V_9 , unsigned long V_10 , unsigned long V_11 )
{
T_2 * V_12 ;
V_12 = F_6 ( V_9 , V_10 ) ;
do {
T_2 V_13 = F_7 ( & V_14 , V_10 , V_12 ) ;
F_8 ( ! F_9 ( V_13 ) && ! F_10 ( V_13 ) ) ;
} while ( V_12 ++ , V_10 += V_15 , V_10 != V_11 );
}
static void F_11 ( T_3 * V_16 , unsigned long V_10 , unsigned long V_11 )
{
T_1 * V_9 ;
unsigned long V_17 ;
V_9 = F_12 ( V_16 , V_10 ) ;
do {
V_17 = F_13 ( V_10 , V_11 ) ;
if ( F_14 ( V_9 ) )
continue;
if ( F_15 ( V_9 ) )
continue;
F_5 ( V_9 , V_10 , V_17 ) ;
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
if ( F_20 ( V_16 ) )
continue;
F_11 ( V_16 , V_10 , V_17 ) ;
} while ( V_16 ++ , V_10 = V_17 , V_10 != V_11 );
}
static void F_21 ( T_5 * V_19 , unsigned long V_10 , unsigned long V_11 )
{
T_4 * V_18 ;
unsigned long V_17 ;
V_18 = F_22 ( V_19 , V_10 ) ;
do {
V_17 = F_23 ( V_10 , V_11 ) ;
if ( F_24 ( V_18 ) )
continue;
if ( F_25 ( V_18 ) )
continue;
F_16 ( V_18 , V_10 , V_17 ) ;
} while ( V_18 ++ , V_10 = V_17 , V_10 != V_11 );
}
static void F_26 ( unsigned long V_10 , unsigned long V_11 )
{
T_5 * V_19 ;
unsigned long V_17 ;
F_27 ( V_10 >= V_11 ) ;
V_19 = F_28 ( V_10 ) ;
do {
V_17 = F_29 ( V_10 , V_11 ) ;
if ( F_30 ( V_19 ) )
continue;
F_21 ( V_19 , V_10 , V_17 ) ;
} while ( V_19 ++ , V_10 = V_17 , V_10 != V_11 );
}
static int F_31 ( T_1 * V_9 , unsigned long V_10 ,
unsigned long V_11 , T_6 V_20 , struct V_21 * * V_22 , int * V_23 )
{
T_2 * V_12 ;
V_12 = F_32 ( V_9 , V_10 ) ;
if ( ! V_12 )
return - V_24 ;
do {
struct V_21 * V_21 = V_22 [ * V_23 ] ;
if ( F_8 ( ! F_9 ( * V_12 ) ) )
return - V_25 ;
if ( F_8 ( ! V_21 ) )
return - V_24 ;
F_33 ( & V_14 , V_10 , V_12 , F_34 ( V_21 , V_20 ) ) ;
( * V_23 ) ++ ;
} while ( V_12 ++ , V_10 += V_15 , V_10 != V_11 );
return 0 ;
}
static int F_35 ( T_3 * V_16 , unsigned long V_10 ,
unsigned long V_11 , T_6 V_20 , struct V_21 * * V_22 , int * V_23 )
{
T_1 * V_9 ;
unsigned long V_17 ;
V_9 = F_36 ( & V_14 , V_16 , V_10 ) ;
if ( ! V_9 )
return - V_24 ;
do {
V_17 = F_13 ( V_10 , V_11 ) ;
if ( F_31 ( V_9 , V_10 , V_17 , V_20 , V_22 , V_23 ) )
return - V_24 ;
} while ( V_9 ++ , V_10 = V_17 , V_10 != V_11 );
return 0 ;
}
static int F_37 ( T_4 * V_18 , unsigned long V_10 ,
unsigned long V_11 , T_6 V_20 , struct V_21 * * V_22 , int * V_23 )
{
T_3 * V_16 ;
unsigned long V_17 ;
V_16 = F_38 ( & V_14 , V_18 , V_10 ) ;
if ( ! V_16 )
return - V_24 ;
do {
V_17 = F_18 ( V_10 , V_11 ) ;
if ( F_35 ( V_16 , V_10 , V_17 , V_20 , V_22 , V_23 ) )
return - V_24 ;
} while ( V_16 ++ , V_10 = V_17 , V_10 != V_11 );
return 0 ;
}
static int F_39 ( T_5 * V_19 , unsigned long V_10 ,
unsigned long V_11 , T_6 V_20 , struct V_21 * * V_22 , int * V_23 )
{
T_4 * V_18 ;
unsigned long V_17 ;
V_18 = F_40 ( & V_14 , V_19 , V_10 ) ;
if ( ! V_18 )
return - V_24 ;
do {
V_17 = F_23 ( V_10 , V_11 ) ;
if ( F_37 ( V_18 , V_10 , V_17 , V_20 , V_22 , V_23 ) )
return - V_24 ;
} while ( V_18 ++ , V_10 = V_17 , V_10 != V_11 );
return 0 ;
}
static int F_41 ( unsigned long V_26 , unsigned long V_11 ,
T_6 V_20 , struct V_21 * * V_22 )
{
T_5 * V_19 ;
unsigned long V_17 ;
unsigned long V_10 = V_26 ;
int V_27 = 0 ;
int V_23 = 0 ;
F_27 ( V_10 >= V_11 ) ;
V_19 = F_28 ( V_10 ) ;
do {
V_17 = F_29 ( V_10 , V_11 ) ;
V_27 = F_39 ( V_19 , V_10 , V_17 , V_20 , V_22 , & V_23 ) ;
if ( V_27 )
return V_27 ;
} while ( V_19 ++ , V_10 = V_17 , V_10 != V_11 );
return V_23 ;
}
static int F_42 ( unsigned long V_26 , unsigned long V_11 ,
T_6 V_20 , struct V_21 * * V_22 )
{
int V_28 ;
V_28 = F_41 ( V_26 , V_11 , V_20 , V_22 ) ;
F_43 ( V_26 , V_11 ) ;
return V_28 ;
}
int F_44 ( const void * V_29 )
{
#if F_45 ( V_30 ) && F_45 ( V_31 )
unsigned long V_10 = ( unsigned long ) V_29 ;
if ( V_10 >= V_31 && V_10 < V_32 )
return 1 ;
#endif
return F_46 ( V_29 ) ;
}
struct V_21 * F_47 ( const void * V_33 )
{
unsigned long V_10 = ( unsigned long ) V_33 ;
struct V_21 * V_21 = NULL ;
T_5 * V_19 = F_28 ( V_10 ) ;
T_4 * V_18 ;
T_3 * V_16 ;
T_1 * V_9 ;
T_2 * V_34 , V_12 ;
F_48 ( ! F_44 ( V_33 ) ) ;
if ( F_49 ( * V_19 ) )
return NULL ;
V_18 = F_22 ( V_19 , V_10 ) ;
if ( F_50 ( * V_18 ) )
return NULL ;
V_16 = F_17 ( V_18 , V_10 ) ;
F_51 ( F_52 ( * V_16 ) ) ;
if ( F_53 ( * V_16 ) || F_52 ( * V_16 ) )
return NULL ;
V_9 = F_12 ( V_16 , V_10 ) ;
F_51 ( F_54 ( * V_9 ) ) ;
if ( F_55 ( * V_9 ) || F_54 ( * V_9 ) )
return NULL ;
V_34 = F_56 ( V_9 , V_10 ) ;
V_12 = * V_34 ;
if ( F_10 ( V_12 ) )
V_21 = F_57 ( V_12 ) ;
F_58 ( V_34 ) ;
return V_21 ;
}
unsigned long F_59 ( const void * V_33 )
{
return F_60 ( F_47 ( V_33 ) ) ;
}
static struct V_35 * F_61 ( unsigned long V_10 )
{
struct V_36 * V_37 = V_38 . V_36 ;
while ( V_37 ) {
struct V_35 * V_39 ;
V_39 = F_62 ( V_37 , struct V_35 , V_36 ) ;
if ( V_10 < V_39 -> va_start )
V_37 = V_37 -> V_40 ;
else if ( V_10 >= V_39 -> va_end )
V_37 = V_37 -> V_41 ;
else
return V_39 ;
}
return NULL ;
}
static void F_63 ( struct V_35 * V_39 )
{
struct V_36 * * V_4 = & V_38 . V_36 ;
struct V_36 * V_42 = NULL ;
struct V_36 * V_43 ;
while ( * V_4 ) {
struct V_35 * V_44 ;
V_42 = * V_4 ;
V_44 = F_62 ( V_42 , struct V_35 , V_36 ) ;
if ( V_39 -> va_start < V_44 -> va_end )
V_4 = & ( * V_4 ) -> V_40 ;
else if ( V_39 -> va_end > V_44 -> va_start )
V_4 = & ( * V_4 ) -> V_41 ;
else
F_64 () ;
}
F_65 ( & V_39 -> V_36 , V_42 , V_4 ) ;
F_66 ( & V_39 -> V_36 , & V_38 ) ;
V_43 = F_67 ( & V_39 -> V_36 ) ;
if ( V_43 ) {
struct V_35 * V_45 ;
V_45 = F_62 ( V_43 , struct V_35 , V_36 ) ;
F_68 ( & V_39 -> V_46 , & V_45 -> V_46 ) ;
} else
F_68 ( & V_39 -> V_46 , & V_47 ) ;
}
static struct V_35 * F_69 ( unsigned long V_48 ,
unsigned long V_49 ,
unsigned long V_50 , unsigned long V_51 ,
int V_52 , T_7 V_53 )
{
struct V_35 * V_39 ;
struct V_36 * V_37 ;
unsigned long V_10 ;
int V_54 = 0 ;
struct V_35 * V_55 ;
F_27 ( ! V_48 ) ;
F_27 ( F_70 ( V_48 ) ) ;
F_27 ( ! F_71 ( V_49 ) ) ;
F_72 () ;
V_39 = F_73 ( sizeof( struct V_35 ) ,
V_53 & V_56 , V_52 ) ;
if ( F_74 ( ! V_39 ) )
return F_75 ( - V_24 ) ;
F_76 ( & V_39 -> V_36 , V_57 , V_53 & V_56 ) ;
V_58:
F_77 ( & V_59 ) ;
if ( ! V_60 ||
V_48 < V_61 ||
V_50 < V_62 ||
V_49 < V_63 ) {
V_64:
V_61 = 0 ;
V_60 = NULL ;
}
V_62 = V_50 ;
V_63 = V_49 ;
if ( V_60 ) {
V_55 = F_62 ( V_60 , struct V_35 , V_36 ) ;
V_10 = F_78 ( V_55 -> va_end , V_49 ) ;
if ( V_10 < V_50 )
goto V_64;
if ( V_10 + V_48 < V_10 )
goto V_65;
} else {
V_10 = F_78 ( V_50 , V_49 ) ;
if ( V_10 + V_48 < V_10 )
goto V_65;
V_37 = V_38 . V_36 ;
V_55 = NULL ;
while ( V_37 ) {
struct V_35 * V_43 ;
V_43 = F_62 ( V_37 , struct V_35 , V_36 ) ;
if ( V_43 -> va_end >= V_10 ) {
V_55 = V_43 ;
if ( V_43 -> va_start <= V_10 )
break;
V_37 = V_37 -> V_40 ;
} else
V_37 = V_37 -> V_41 ;
}
if ( ! V_55 )
goto V_66;
}
while ( V_10 + V_48 > V_55 -> va_start && V_10 + V_48 <= V_51 ) {
if ( V_10 + V_61 < V_55 -> va_start )
V_61 = V_55 -> va_start - V_10 ;
V_10 = F_78 ( V_55 -> va_end , V_49 ) ;
if ( V_10 + V_48 < V_10 )
goto V_65;
if ( F_79 ( & V_55 -> V_46 , & V_47 ) )
goto V_66;
V_55 = F_80 ( V_55 , V_46 ) ;
}
V_66:
if ( V_10 + V_48 > V_51 )
goto V_65;
V_39 -> va_start = V_10 ;
V_39 -> va_end = V_10 + V_48 ;
V_39 -> V_67 = 0 ;
F_63 ( V_39 ) ;
V_60 = & V_39 -> V_36 ;
F_81 ( & V_59 ) ;
F_27 ( ! F_82 ( V_39 -> va_start , V_49 ) ) ;
F_27 ( V_39 -> va_start < V_50 ) ;
F_27 ( V_39 -> va_end > V_51 ) ;
return V_39 ;
V_65:
F_81 ( & V_59 ) ;
if ( ! V_54 ) {
F_83 () ;
V_54 = 1 ;
goto V_58;
}
if ( F_84 ( V_53 ) ) {
unsigned long V_68 = 0 ;
F_85 ( & V_69 , 0 , & V_68 ) ;
if ( V_68 > 0 ) {
V_54 = 0 ;
goto V_58;
}
}
if ( ! ( V_53 & V_70 ) && F_86 () )
F_87 ( L_1 ,
V_48 ) ;
F_88 ( V_39 ) ;
return F_75 ( - V_25 ) ;
}
int F_89 ( struct V_71 * V_72 )
{
return F_90 ( & V_69 , V_72 ) ;
}
int F_91 ( struct V_71 * V_72 )
{
return F_92 ( & V_69 , V_72 ) ;
}
static void F_93 ( struct V_35 * V_39 )
{
F_27 ( F_94 ( & V_39 -> V_36 ) ) ;
if ( V_60 ) {
if ( V_39 -> va_end < V_62 ) {
V_60 = NULL ;
} else {
struct V_35 * V_73 ;
V_73 = F_62 ( V_60 , struct V_35 , V_36 ) ;
if ( V_39 -> va_start <= V_73 -> va_start ) {
V_60 = F_67 ( & V_39 -> V_36 ) ;
}
}
}
F_95 ( & V_39 -> V_36 , & V_38 ) ;
F_96 ( & V_39 -> V_36 ) ;
F_97 ( & V_39 -> V_46 ) ;
if ( V_39 -> va_end > V_74 && V_39 -> va_end <= V_75 )
V_76 = F_98 ( V_76 , V_39 -> va_end ) ;
F_99 ( V_39 , V_77 ) ;
}
static void F_100 ( struct V_35 * V_39 )
{
F_77 ( & V_59 ) ;
F_93 ( V_39 ) ;
F_81 ( & V_59 ) ;
}
static void F_101 ( struct V_35 * V_39 )
{
F_26 ( V_39 -> va_start , V_39 -> va_end ) ;
}
static void F_102 ( unsigned long V_26 , unsigned long V_11 )
{
if ( F_103 () ) {
F_26 ( V_26 , V_11 ) ;
F_104 ( V_26 , V_11 ) ;
}
}
static unsigned long F_105 ( void )
{
unsigned int log ;
log = F_106 ( F_107 () ) ;
return log * ( 32UL * 1024 * 1024 / V_15 ) ;
}
void F_108 ( void )
{
F_109 ( & V_78 , F_105 () + 1 ) ;
}
static bool F_110 ( unsigned long V_26 , unsigned long V_11 )
{
struct V_6 * V_79 ;
struct V_35 * V_39 ;
struct V_35 * V_80 ;
bool V_81 = false ;
F_111 ( & V_82 ) ;
V_79 = F_112 ( & V_83 ) ;
F_113 (va, valist, purge_list) {
if ( V_39 -> va_start < V_26 )
V_26 = V_39 -> va_start ;
if ( V_39 -> va_end > V_11 )
V_11 = V_39 -> va_end ;
V_81 = true ;
}
if ( ! V_81 )
return false ;
F_104 ( V_26 , V_11 ) ;
F_77 ( & V_59 ) ;
F_114 (va, n_va, valist, purge_list) {
int V_23 = ( V_39 -> va_end - V_39 -> va_start ) >> V_84 ;
F_93 ( V_39 ) ;
F_115 ( V_23 , & V_78 ) ;
F_116 ( & V_59 ) ;
}
F_81 ( & V_59 ) ;
return true ;
}
static void F_117 ( void )
{
if ( F_118 ( & V_82 ) ) {
F_110 ( V_85 , 0 ) ;
F_119 ( & V_82 ) ;
}
}
static void F_83 ( void )
{
F_120 ( & V_82 ) ;
F_121 () ;
F_110 ( V_85 , 0 ) ;
F_119 ( & V_82 ) ;
}
static void F_122 ( struct V_35 * V_39 )
{
int V_86 ;
V_86 = F_123 ( ( V_39 -> va_end - V_39 -> va_start ) >> V_84 ,
& V_78 ) ;
F_124 ( & V_39 -> V_87 , & V_83 ) ;
if ( F_74 ( V_86 > F_105 () ) )
F_117 () ;
}
static void F_125 ( struct V_35 * V_39 )
{
F_126 ( V_39 -> va_start , V_39 -> va_end ) ;
F_101 ( V_39 ) ;
F_122 ( V_39 ) ;
}
static struct V_35 * F_127 ( unsigned long V_10 )
{
struct V_35 * V_39 ;
F_77 ( & V_59 ) ;
V_39 = F_61 ( V_10 ) ;
F_81 ( & V_59 ) ;
return V_39 ;
}
static unsigned long F_128 ( unsigned long V_10 )
{
V_10 -= V_74 & ~ ( V_88 - 1 ) ;
V_10 /= V_88 ;
return V_10 ;
}
static void * F_129 ( unsigned long va_start , unsigned long V_89 )
{
unsigned long V_10 ;
V_10 = va_start + ( V_89 << V_84 ) ;
F_27 ( F_128 ( V_10 ) != F_128 ( va_start ) ) ;
return ( void * ) V_10 ;
}
static void * F_130 ( unsigned int V_90 , T_7 V_53 )
{
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_35 * V_39 ;
unsigned long V_95 ;
int V_52 , V_27 ;
void * V_96 ;
V_52 = F_131 () ;
V_94 = F_73 ( sizeof( struct V_93 ) ,
V_53 & V_56 , V_52 ) ;
if ( F_74 ( ! V_94 ) )
return F_75 ( - V_24 ) ;
V_39 = F_69 ( V_88 , V_88 ,
V_74 , V_75 ,
V_52 , V_53 ) ;
if ( F_132 ( V_39 ) ) {
F_88 ( V_94 ) ;
return F_133 ( V_39 ) ;
}
V_27 = F_134 ( V_53 ) ;
if ( F_74 ( V_27 ) ) {
F_88 ( V_94 ) ;
F_100 ( V_39 ) ;
return F_75 ( V_27 ) ;
}
V_96 = F_129 ( V_39 -> va_start , 0 ) ;
F_135 ( & V_94 -> V_97 ) ;
V_94 -> V_39 = V_39 ;
F_27 ( V_98 <= ( 1UL << V_90 ) ) ;
V_94 -> free = V_98 - ( 1UL << V_90 ) ;
V_94 -> V_99 = 0 ;
V_94 -> V_100 = V_98 ;
V_94 -> V_101 = 0 ;
F_136 ( & V_94 -> V_102 ) ;
V_95 = F_128 ( V_39 -> va_start ) ;
F_77 ( & V_103 ) ;
V_27 = F_137 ( & V_104 , V_95 , V_94 ) ;
F_81 ( & V_103 ) ;
F_27 ( V_27 ) ;
F_138 () ;
V_92 = & F_139 ( V_91 ) ;
F_77 ( & V_92 -> V_97 ) ;
F_140 ( & V_94 -> V_102 , & V_92 -> free ) ;
F_81 ( & V_92 -> V_97 ) ;
F_141 ( V_91 ) ;
return V_96 ;
}
static void F_142 ( struct V_93 * V_94 )
{
struct V_93 * V_43 ;
unsigned long V_95 ;
V_95 = F_128 ( V_94 -> V_39 -> va_start ) ;
F_77 ( & V_103 ) ;
V_43 = F_143 ( & V_104 , V_95 ) ;
F_81 ( & V_103 ) ;
F_27 ( V_43 != V_94 ) ;
F_122 ( V_94 -> V_39 ) ;
F_99 ( V_94 , V_77 ) ;
}
static void F_144 ( int V_105 )
{
F_145 ( V_106 ) ;
struct V_93 * V_94 ;
struct V_93 * V_107 ;
struct V_91 * V_92 = & F_146 ( V_91 , V_105 ) ;
F_147 () ;
F_148 (vb, &vbq->free, free_list) {
if ( ! ( V_94 -> free + V_94 -> V_99 == V_98 && V_94 -> V_99 != V_98 ) )
continue;
F_77 ( & V_94 -> V_97 ) ;
if ( V_94 -> free + V_94 -> V_99 == V_98 && V_94 -> V_99 != V_98 ) {
V_94 -> free = 0 ;
V_94 -> V_99 = V_98 ;
V_94 -> V_100 = 0 ;
V_94 -> V_101 = V_98 ;
F_77 ( & V_92 -> V_97 ) ;
F_97 ( & V_94 -> V_102 ) ;
F_81 ( & V_92 -> V_97 ) ;
F_81 ( & V_94 -> V_97 ) ;
F_149 ( & V_94 -> V_106 , & V_106 ) ;
} else
F_81 ( & V_94 -> V_97 ) ;
}
F_150 () ;
F_151 (vb, n_vb, &purge, purge) {
F_152 ( & V_94 -> V_106 ) ;
F_142 ( V_94 ) ;
}
}
static void F_121 ( void )
{
int V_105 ;
F_153 (cpu)
F_144 ( V_105 ) ;
}
static void * F_154 ( unsigned long V_48 , T_7 V_53 )
{
struct V_91 * V_92 ;
struct V_93 * V_94 ;
void * V_96 = NULL ;
unsigned int V_90 ;
F_27 ( F_70 ( V_48 ) ) ;
F_27 ( V_48 > V_15 * V_108 ) ;
if ( F_8 ( V_48 == 0 ) ) {
return NULL ;
}
V_90 = F_155 ( V_48 ) ;
F_147 () ;
V_92 = & F_139 ( V_91 ) ;
F_148 (vb, &vbq->free, free_list) {
unsigned long V_89 ;
F_77 ( & V_94 -> V_97 ) ;
if ( V_94 -> free < ( 1UL << V_90 ) ) {
F_81 ( & V_94 -> V_97 ) ;
continue;
}
V_89 = V_98 - V_94 -> free ;
V_96 = F_129 ( V_94 -> V_39 -> va_start , V_89 ) ;
V_94 -> free -= 1UL << V_90 ;
if ( V_94 -> free == 0 ) {
F_77 ( & V_92 -> V_97 ) ;
F_97 ( & V_94 -> V_102 ) ;
F_81 ( & V_92 -> V_97 ) ;
}
F_81 ( & V_94 -> V_97 ) ;
break;
}
F_141 ( V_91 ) ;
F_150 () ;
if ( ! V_96 )
V_96 = F_130 ( V_90 , V_53 ) ;
return V_96 ;
}
static void F_156 ( const void * V_10 , unsigned long V_48 )
{
unsigned long V_109 ;
unsigned long V_95 ;
unsigned int V_90 ;
struct V_93 * V_94 ;
F_27 ( F_70 ( V_48 ) ) ;
F_27 ( V_48 > V_15 * V_108 ) ;
F_126 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_48 ) ;
V_90 = F_155 ( V_48 ) ;
V_109 = ( unsigned long ) V_10 & ( V_88 - 1 ) ;
V_109 >>= V_84 ;
V_95 = F_128 ( ( unsigned long ) V_10 ) ;
F_147 () ;
V_94 = F_157 ( & V_104 , V_95 ) ;
F_150 () ;
F_27 ( ! V_94 ) ;
F_26 ( ( unsigned long ) V_10 , ( unsigned long ) V_10 + V_48 ) ;
F_77 ( & V_94 -> V_97 ) ;
V_94 -> V_100 = F_158 ( V_94 -> V_100 , V_109 ) ;
V_94 -> V_101 = F_98 ( V_94 -> V_101 , V_109 + ( 1UL << V_90 ) ) ;
V_94 -> V_99 += 1UL << V_90 ;
if ( V_94 -> V_99 == V_98 ) {
F_27 ( V_94 -> free ) ;
F_81 ( & V_94 -> V_97 ) ;
F_142 ( V_94 ) ;
} else
F_81 ( & V_94 -> V_97 ) ;
}
void F_159 ( void )
{
unsigned long V_26 = V_85 , V_11 = 0 ;
int V_105 ;
int V_110 = 0 ;
if ( F_74 ( ! V_111 ) )
return;
F_72 () ;
F_153 (cpu) {
struct V_91 * V_92 = & F_146 ( V_91 , V_105 ) ;
struct V_93 * V_94 ;
F_147 () ;
F_148 (vb, &vbq->free, free_list) {
F_77 ( & V_94 -> V_97 ) ;
if ( V_94 -> V_99 ) {
unsigned long va_start = V_94 -> V_39 -> va_start ;
unsigned long V_112 , V_113 ;
V_112 = va_start + ( V_94 -> V_100 << V_84 ) ;
V_113 = va_start + ( V_94 -> V_101 << V_84 ) ;
V_26 = F_158 ( V_112 , V_26 ) ;
V_11 = F_98 ( V_113 , V_11 ) ;
V_110 = 1 ;
}
F_81 ( & V_94 -> V_97 ) ;
}
F_150 () ;
}
F_120 ( & V_82 ) ;
F_121 () ;
if ( ! F_110 ( V_26 , V_11 ) && V_110 )
F_104 ( V_26 , V_11 ) ;
F_119 ( & V_82 ) ;
}
void F_160 ( const void * V_114 , unsigned int V_115 )
{
unsigned long V_48 = ( unsigned long ) V_115 << V_84 ;
unsigned long V_10 = ( unsigned long ) V_114 ;
struct V_35 * V_39 ;
F_72 () ;
F_27 ( ! V_10 ) ;
F_27 ( V_10 < V_74 ) ;
F_27 ( V_10 > V_75 ) ;
F_27 ( ! F_161 ( V_10 ) ) ;
F_162 ( V_114 , V_48 ) ;
F_102 ( V_10 , V_10 + V_48 ) ;
if ( F_163 ( V_115 <= V_108 ) ) {
F_156 ( V_114 , V_48 ) ;
return;
}
V_39 = F_127 ( V_10 ) ;
F_27 ( ! V_39 ) ;
F_125 ( V_39 ) ;
}
void * F_164 ( struct V_21 * * V_22 , unsigned int V_115 , int V_52 , T_6 V_20 )
{
unsigned long V_48 = ( unsigned long ) V_115 << V_84 ;
unsigned long V_10 ;
void * V_114 ;
if ( F_163 ( V_115 <= V_108 ) ) {
V_114 = F_154 ( V_48 , V_116 ) ;
if ( F_132 ( V_114 ) )
return NULL ;
V_10 = ( unsigned long ) V_114 ;
} else {
struct V_35 * V_39 ;
V_39 = F_69 ( V_48 , V_15 ,
V_74 , V_75 , V_52 , V_116 ) ;
if ( F_132 ( V_39 ) )
return NULL ;
V_10 = V_39 -> va_start ;
V_114 = ( void * ) V_10 ;
}
if ( F_42 ( V_10 , V_10 + V_48 , V_20 , V_22 ) < 0 ) {
F_160 ( V_114 , V_115 ) ;
return NULL ;
}
return V_114 ;
}
void T_8 F_165 ( struct V_117 * V_118 )
{
struct V_117 * V_43 , * * V_4 ;
F_27 ( V_111 ) ;
for ( V_4 = & V_119 ; ( V_43 = * V_4 ) != NULL ; V_4 = & V_43 -> V_17 ) {
if ( V_43 -> V_10 >= V_118 -> V_10 ) {
F_27 ( V_43 -> V_10 < V_118 -> V_10 + V_118 -> V_48 ) ;
break;
} else
F_27 ( V_43 -> V_10 + V_43 -> V_48 > V_118 -> V_10 ) ;
}
V_118 -> V_17 = * V_4 ;
* V_4 = V_118 ;
}
void T_8 F_166 ( struct V_117 * V_118 , T_9 V_49 )
{
static T_9 T_10 V_120 ;
unsigned long V_10 ;
V_10 = F_78 ( V_74 + T_10 , V_49 ) ;
T_10 = F_167 ( V_10 + V_118 -> V_48 ) - V_74 ;
V_118 -> V_10 = ( void * ) V_10 ;
F_165 ( V_118 ) ;
}
void T_8 F_168 ( void )
{
struct V_35 * V_39 ;
struct V_117 * V_43 ;
int V_121 ;
F_153 (i) {
struct V_91 * V_92 ;
struct V_3 * V_4 ;
V_92 = & F_146 ( V_91 , V_121 ) ;
F_135 ( & V_92 -> V_97 ) ;
F_136 ( & V_92 -> free ) ;
V_4 = & F_146 ( V_3 , V_121 ) ;
F_169 ( & V_4 -> V_46 ) ;
F_170 ( & V_4 -> V_5 , F_1 ) ;
}
for ( V_43 = V_119 ; V_43 ; V_43 = V_43 -> V_17 ) {
V_39 = F_171 ( sizeof( struct V_35 ) , V_122 ) ;
V_39 -> V_67 = V_123 ;
V_39 -> va_start = ( unsigned long ) V_43 -> V_10 ;
V_39 -> va_end = V_39 -> va_start + V_43 -> V_48 ;
V_39 -> V_118 = V_43 ;
F_63 ( V_39 ) ;
}
V_76 = V_75 ;
V_111 = true ;
}
int F_172 ( unsigned long V_10 , unsigned long V_48 ,
T_6 V_20 , struct V_21 * * V_22 )
{
return F_41 ( V_10 , V_10 + V_48 , V_20 , V_22 ) ;
}
void F_173 ( unsigned long V_10 , unsigned long V_48 )
{
F_26 ( V_10 , V_10 + V_48 ) ;
}
void F_174 ( unsigned long V_10 , unsigned long V_48 )
{
unsigned long V_11 = V_10 + V_48 ;
F_126 ( V_10 , V_11 ) ;
F_26 ( V_10 , V_11 ) ;
F_104 ( V_10 , V_11 ) ;
}
int F_175 ( struct V_117 * V_124 , T_6 V_20 , struct V_21 * * V_22 )
{
unsigned long V_10 = ( unsigned long ) V_124 -> V_10 ;
unsigned long V_11 = V_10 + F_176 ( V_124 ) ;
int V_27 ;
V_27 = F_42 ( V_10 , V_11 , V_20 , V_22 ) ;
return V_27 > 0 ? 0 : V_27 ;
}
static void F_177 ( struct V_117 * V_118 , struct V_35 * V_39 ,
unsigned long V_67 , const void * V_125 )
{
F_77 ( & V_59 ) ;
V_118 -> V_67 = V_67 ;
V_118 -> V_10 = ( void * ) V_39 -> va_start ;
V_118 -> V_48 = V_39 -> va_end - V_39 -> va_start ;
V_118 -> V_125 = V_125 ;
V_39 -> V_118 = V_118 ;
V_39 -> V_67 |= V_123 ;
F_81 ( & V_59 ) ;
}
static void F_178 ( struct V_117 * V_118 )
{
F_179 () ;
V_118 -> V_67 &= ~ V_126 ;
}
static struct V_117 * F_180 ( unsigned long V_48 ,
unsigned long V_49 , unsigned long V_67 , unsigned long V_26 ,
unsigned long V_11 , int V_52 , T_7 V_53 , const void * V_125 )
{
struct V_35 * V_39 ;
struct V_117 * V_124 ;
F_27 ( F_181 () ) ;
V_48 = F_182 ( V_48 ) ;
if ( F_74 ( ! V_48 ) )
return NULL ;
if ( V_67 & V_127 )
V_49 = 1ul << F_183 ( int , F_184 ( V_48 ) ,
V_84 , V_128 ) ;
V_124 = F_185 ( sizeof( * V_124 ) , V_53 & V_56 , V_52 ) ;
if ( F_74 ( ! V_124 ) )
return NULL ;
if ( ! ( V_67 & V_129 ) )
V_48 += V_15 ;
V_39 = F_69 ( V_48 , V_49 , V_26 , V_11 , V_52 , V_53 ) ;
if ( F_132 ( V_39 ) ) {
F_88 ( V_124 ) ;
return NULL ;
}
F_177 ( V_124 , V_39 , V_67 , V_125 ) ;
return V_124 ;
}
struct V_117 * F_186 ( unsigned long V_48 , unsigned long V_67 ,
unsigned long V_26 , unsigned long V_11 )
{
return F_180 ( V_48 , 1 , V_67 , V_26 , V_11 , V_130 ,
V_116 , F_187 ( 0 ) ) ;
}
struct V_117 * F_188 ( unsigned long V_48 , unsigned long V_67 ,
unsigned long V_26 , unsigned long V_11 ,
const void * V_125 )
{
return F_180 ( V_48 , 1 , V_67 , V_26 , V_11 , V_130 ,
V_116 , V_125 ) ;
}
struct V_117 * F_189 ( unsigned long V_48 , unsigned long V_67 )
{
return F_180 ( V_48 , 1 , V_67 , V_74 , V_75 ,
V_130 , V_116 ,
F_187 ( 0 ) ) ;
}
struct V_117 * F_190 ( unsigned long V_48 , unsigned long V_67 ,
const void * V_125 )
{
return F_180 ( V_48 , 1 , V_67 , V_74 , V_75 ,
V_130 , V_116 , V_125 ) ;
}
struct V_117 * F_191 ( const void * V_10 )
{
struct V_35 * V_39 ;
V_39 = F_127 ( ( unsigned long ) V_10 ) ;
if ( V_39 && V_39 -> V_67 & V_123 )
return V_39 -> V_118 ;
return NULL ;
}
struct V_117 * F_192 ( const void * V_10 )
{
struct V_35 * V_39 ;
F_72 () ;
V_39 = F_127 ( ( unsigned long ) V_10 ) ;
if ( V_39 && V_39 -> V_67 & V_123 ) {
struct V_117 * V_118 = V_39 -> V_118 ;
F_77 ( & V_59 ) ;
V_39 -> V_118 = NULL ;
V_39 -> V_67 &= ~ V_123 ;
V_39 -> V_67 |= V_131 ;
F_81 ( & V_59 ) ;
F_102 ( V_39 -> va_start , V_39 -> va_end ) ;
F_193 ( V_118 ) ;
F_125 ( V_39 ) ;
return V_118 ;
}
return NULL ;
}
static void F_4 ( const void * V_10 , int V_132 )
{
struct V_117 * V_124 ;
if ( ! V_10 )
return;
if ( F_194 ( ! F_161 ( V_10 ) , L_2 ,
V_10 ) )
return;
V_124 = F_192 ( V_10 ) ;
if ( F_74 ( ! V_124 ) ) {
F_194 ( 1 , V_133 L_3 ,
V_10 ) ;
return;
}
F_162 ( V_10 , F_176 ( V_124 ) ) ;
F_195 ( V_10 , F_176 ( V_124 ) ) ;
if ( V_132 ) {
int V_121 ;
for ( V_121 = 0 ; V_121 < V_124 -> V_134 ; V_121 ++ ) {
struct V_21 * V_21 = V_124 -> V_22 [ V_121 ] ;
F_27 ( ! V_21 ) ;
F_196 ( V_21 , 0 ) ;
}
F_197 ( V_124 -> V_22 ) ;
}
F_88 ( V_124 ) ;
return;
}
static inline void F_198 ( const void * V_10 )
{
struct V_3 * V_4 = F_199 ( & V_3 ) ;
if ( F_124 ( (struct V_6 * ) V_10 , & V_4 -> V_46 ) )
F_200 ( & V_4 -> V_5 ) ;
}
void F_201 ( const void * V_10 )
{
F_27 ( F_202 () ) ;
F_203 ( V_10 ) ;
if ( ! V_10 )
return;
F_198 ( V_10 ) ;
}
void F_204 ( const void * V_10 )
{
F_27 ( F_202 () ) ;
F_203 ( V_10 ) ;
if ( ! V_10 )
return;
if ( F_74 ( F_181 () ) )
F_198 ( V_10 ) ;
else
F_4 ( V_10 , 1 ) ;
}
void F_205 ( const void * V_10 )
{
F_27 ( F_181 () ) ;
F_72 () ;
if ( V_10 )
F_4 ( V_10 , 0 ) ;
}
void * F_206 ( struct V_21 * * V_22 , unsigned int V_115 ,
unsigned long V_67 , T_6 V_20 )
{
struct V_117 * V_124 ;
unsigned long V_48 ;
F_72 () ;
if ( V_115 > V_135 )
return NULL ;
V_48 = ( unsigned long ) V_115 << V_84 ;
V_124 = F_190 ( V_48 , V_67 , F_187 ( 0 ) ) ;
if ( ! V_124 )
return NULL ;
if ( F_175 ( V_124 , V_20 , V_22 ) ) {
F_205 ( V_124 -> V_10 ) ;
return NULL ;
}
return V_124 -> V_10 ;
}
static void * F_207 ( struct V_117 * V_124 , T_7 V_53 ,
T_6 V_20 , int V_52 )
{
struct V_21 * * V_22 ;
unsigned int V_134 , V_136 , V_121 ;
const T_7 V_137 = ( V_53 & V_56 ) | V_138 ;
const T_7 V_139 = V_53 | V_70 ;
const T_7 V_140 = ( V_53 & ( V_141 | V_142 ) ) ?
0 :
V_143 ;
V_134 = F_176 ( V_124 ) >> V_84 ;
V_136 = ( V_134 * sizeof( struct V_21 * ) ) ;
V_124 -> V_134 = V_134 ;
if ( V_136 > V_15 ) {
V_22 = F_208 ( V_136 , 1 , V_137 | V_140 ,
V_144 , V_52 , V_124 -> V_125 ) ;
} else {
V_22 = F_73 ( V_136 , V_137 , V_52 ) ;
}
V_124 -> V_22 = V_22 ;
if ( ! V_124 -> V_22 ) {
F_192 ( V_124 -> V_10 ) ;
F_88 ( V_124 ) ;
return NULL ;
}
for ( V_121 = 0 ; V_121 < V_124 -> V_134 ; V_121 ++ ) {
struct V_21 * V_21 ;
if ( V_52 == V_130 )
V_21 = F_209 ( V_139 | V_140 ) ;
else
V_21 = F_210 ( V_52 , V_139 | V_140 , 0 ) ;
if ( F_74 ( ! V_21 ) ) {
V_124 -> V_134 = V_121 ;
goto V_145;
}
V_124 -> V_22 [ V_121 ] = V_21 ;
if ( F_84 ( V_53 | V_140 ) )
F_211 () ;
}
if ( F_175 ( V_124 , V_20 , V_22 ) )
goto V_145;
return V_124 -> V_10 ;
V_145:
F_212 ( V_53 , NULL ,
L_4 ,
( V_124 -> V_134 * V_15 ) , V_124 -> V_48 ) ;
F_204 ( V_124 -> V_10 ) ;
return NULL ;
}
void * F_213 ( unsigned long V_48 , unsigned long V_49 ,
unsigned long V_26 , unsigned long V_11 , T_7 V_53 ,
T_6 V_20 , unsigned long V_146 , int V_52 ,
const void * V_125 )
{
struct V_117 * V_124 ;
void * V_10 ;
unsigned long V_147 = V_48 ;
V_48 = F_182 ( V_48 ) ;
if ( ! V_48 || ( V_48 >> V_84 ) > V_135 )
goto V_145;
V_124 = F_180 ( V_48 , V_49 , V_148 | V_126 |
V_146 , V_26 , V_11 , V_52 , V_53 , V_125 ) ;
if ( ! V_124 )
goto V_145;
V_10 = F_207 ( V_124 , V_53 , V_20 , V_52 ) ;
if ( ! V_10 )
return NULL ;
F_178 ( V_124 ) ;
F_214 ( V_124 , V_48 , V_53 ) ;
return V_10 ;
V_145:
F_212 ( V_53 , NULL ,
L_5 , V_147 ) ;
return NULL ;
}
static void * F_208 ( unsigned long V_48 , unsigned long V_49 ,
T_7 V_53 , T_6 V_20 ,
int V_52 , const void * V_125 )
{
return F_213 ( V_48 , V_49 , V_74 , V_75 ,
V_53 , V_20 , 0 , V_52 , V_125 ) ;
}
void * F_215 ( unsigned long V_48 , T_7 V_53 , T_6 V_20 )
{
return F_208 ( V_48 , 1 , V_53 , V_20 , V_130 ,
F_187 ( 0 ) ) ;
}
static inline void * F_216 ( unsigned long V_48 ,
int V_52 , T_7 V_67 )
{
return F_208 ( V_48 , 1 , V_67 , V_144 ,
V_52 , F_187 ( 0 ) ) ;
}
void * F_217 ( unsigned long V_48 , int V_52 , T_7 V_67 ,
void * V_125 )
{
return F_208 ( V_48 , 1 , V_67 , V_144 , V_52 , V_125 ) ;
}
void * F_218 ( unsigned long V_48 )
{
return F_216 ( V_48 , V_130 ,
V_116 ) ;
}
void * F_219 ( unsigned long V_48 )
{
return F_216 ( V_48 , V_130 ,
V_116 | V_138 ) ;
}
void * F_220 ( unsigned long V_48 )
{
struct V_117 * V_124 ;
void * V_28 ;
V_28 = F_208 ( V_48 , V_149 ,
V_116 | V_138 ,
V_144 , V_130 ,
F_187 ( 0 ) ) ;
if ( V_28 ) {
V_124 = F_191 ( V_28 ) ;
V_124 -> V_67 |= V_150 ;
}
return V_28 ;
}
void * F_221 ( unsigned long V_48 , int V_52 )
{
return F_208 ( V_48 , 1 , V_116 , V_144 ,
V_52 , F_187 ( 0 ) ) ;
}
void * F_222 ( unsigned long V_48 , int V_52 )
{
return F_216 ( V_48 , V_52 ,
V_116 | V_138 ) ;
}
void * F_223 ( unsigned long V_48 )
{
return F_208 ( V_48 , 1 , V_116 , V_151 ,
V_130 , F_187 ( 0 ) ) ;
}
void * F_224 ( unsigned long V_48 )
{
return F_208 ( V_48 , 1 , V_152 , V_144 ,
V_130 , F_187 ( 0 ) ) ;
}
void * F_225 ( unsigned long V_48 )
{
struct V_117 * V_124 ;
void * V_28 ;
V_28 = F_208 ( V_48 , 1 , V_152 | V_138 , V_144 ,
V_130 , F_187 ( 0 ) ) ;
if ( V_28 ) {
V_124 = F_191 ( V_28 ) ;
V_124 -> V_67 |= V_150 ;
}
return V_28 ;
}
static int F_226 ( char * V_153 , char * V_10 , unsigned long V_115 )
{
struct V_21 * V_4 ;
int V_154 = 0 ;
while ( V_115 ) {
unsigned long V_109 , V_155 ;
V_109 = F_70 ( V_10 ) ;
V_155 = V_15 - V_109 ;
if ( V_155 > V_115 )
V_155 = V_115 ;
V_4 = F_47 ( V_10 ) ;
if ( V_4 ) {
void * V_156 = F_227 ( V_4 ) ;
memcpy ( V_153 , V_156 + V_109 , V_155 ) ;
F_228 ( V_156 ) ;
} else
memset ( V_153 , 0 , V_155 ) ;
V_10 += V_155 ;
V_153 += V_155 ;
V_154 += V_155 ;
V_115 -= V_155 ;
}
return V_154 ;
}
static int F_229 ( char * V_153 , char * V_10 , unsigned long V_115 )
{
struct V_21 * V_4 ;
int V_154 = 0 ;
while ( V_115 ) {
unsigned long V_109 , V_155 ;
V_109 = F_70 ( V_10 ) ;
V_155 = V_15 - V_109 ;
if ( V_155 > V_115 )
V_155 = V_115 ;
V_4 = F_47 ( V_10 ) ;
if ( V_4 ) {
void * V_156 = F_227 ( V_4 ) ;
memcpy ( V_156 + V_109 , V_153 , V_155 ) ;
F_228 ( V_156 ) ;
}
V_10 += V_155 ;
V_153 += V_155 ;
V_154 += V_155 ;
V_115 -= V_155 ;
}
return V_154 ;
}
long F_230 ( char * V_153 , char * V_10 , unsigned long V_115 )
{
struct V_35 * V_39 ;
struct V_117 * V_118 ;
char * V_96 , * V_157 = V_153 ;
unsigned long V_158 = V_115 ;
unsigned long V_37 ;
if ( ( unsigned long ) V_10 + V_115 < V_115 )
V_115 = - ( unsigned long ) V_10 ;
F_77 ( & V_59 ) ;
F_231 (va, &vmap_area_list, list) {
if ( ! V_115 )
break;
if ( ! ( V_39 -> V_67 & V_123 ) )
continue;
V_118 = V_39 -> V_118 ;
V_96 = ( char * ) V_118 -> V_10 ;
if ( V_10 >= V_96 + F_176 ( V_118 ) )
continue;
while ( V_10 < V_96 ) {
if ( V_115 == 0 )
goto V_159;
* V_153 = '\0' ;
V_153 ++ ;
V_10 ++ ;
V_115 -- ;
}
V_37 = V_96 + F_176 ( V_118 ) - V_10 ;
if ( V_37 > V_115 )
V_37 = V_115 ;
if ( ! ( V_118 -> V_67 & V_127 ) )
F_226 ( V_153 , V_10 , V_37 ) ;
else
memset ( V_153 , 0 , V_37 ) ;
V_153 += V_37 ;
V_10 += V_37 ;
V_115 -= V_37 ;
}
V_159:
F_81 ( & V_59 ) ;
if ( V_153 == V_157 )
return 0 ;
if ( V_153 != V_157 + V_158 )
memset ( V_153 , 0 , V_158 - ( V_153 - V_157 ) ) ;
return V_158 ;
}
long F_232 ( char * V_153 , char * V_10 , unsigned long V_115 )
{
struct V_35 * V_39 ;
struct V_117 * V_118 ;
char * V_96 ;
unsigned long V_37 , V_158 ;
int V_154 = 0 ;
if ( ( unsigned long ) V_10 + V_115 < V_115 )
V_115 = - ( unsigned long ) V_10 ;
V_158 = V_115 ;
F_77 ( & V_59 ) ;
F_231 (va, &vmap_area_list, list) {
if ( ! V_115 )
break;
if ( ! ( V_39 -> V_67 & V_123 ) )
continue;
V_118 = V_39 -> V_118 ;
V_96 = ( char * ) V_118 -> V_10 ;
if ( V_10 >= V_96 + F_176 ( V_118 ) )
continue;
while ( V_10 < V_96 ) {
if ( V_115 == 0 )
goto V_159;
V_153 ++ ;
V_10 ++ ;
V_115 -- ;
}
V_37 = V_96 + F_176 ( V_118 ) - V_10 ;
if ( V_37 > V_115 )
V_37 = V_115 ;
if ( ! ( V_118 -> V_67 & V_127 ) ) {
F_229 ( V_153 , V_10 , V_37 ) ;
V_154 ++ ;
}
V_153 += V_37 ;
V_10 += V_37 ;
V_115 -= V_37 ;
}
V_159:
F_81 ( & V_59 ) ;
if ( ! V_154 )
return 0 ;
return V_158 ;
}
int F_233 ( struct V_160 * V_161 , unsigned long V_162 ,
void * V_163 , unsigned long V_48 )
{
struct V_117 * V_124 ;
V_48 = F_182 ( V_48 ) ;
if ( ! F_161 ( V_162 ) || ! F_161 ( V_163 ) )
return - V_164 ;
V_124 = F_191 ( V_163 ) ;
if ( ! V_124 )
return - V_164 ;
if ( ! ( V_124 -> V_67 & V_150 ) )
return - V_164 ;
if ( V_163 + V_48 > V_124 -> V_10 + V_124 -> V_48 )
return - V_164 ;
do {
struct V_21 * V_21 = F_47 ( V_163 ) ;
int V_28 ;
V_28 = F_234 ( V_161 , V_162 , V_21 ) ;
if ( V_28 )
return V_28 ;
V_162 += V_15 ;
V_163 += V_15 ;
V_48 -= V_15 ;
} while ( V_48 > 0 );
V_161 -> V_146 |= V_165 | V_166 ;
return 0 ;
}
int F_235 ( struct V_160 * V_161 , void * V_10 ,
unsigned long V_167 )
{
return F_233 ( V_161 , V_161 -> V_168 ,
V_10 + ( V_167 << V_84 ) ,
V_161 -> V_169 - V_161 -> V_168 ) ;
}
void __weak F_236 ( void )
{
}
static int F_237 ( T_2 * V_12 , T_11 V_170 , unsigned long V_10 , void * V_171 )
{
T_2 * * * V_4 = V_171 ;
if ( V_4 ) {
* ( * V_4 ) = V_12 ;
( * V_4 ) ++ ;
}
return 0 ;
}
struct V_117 * F_238 ( T_9 V_48 , T_2 * * V_172 )
{
struct V_117 * V_124 ;
V_124 = F_190 ( V_48 , V_127 ,
F_187 ( 0 ) ) ;
if ( V_124 == NULL )
return NULL ;
if ( F_239 ( & V_14 , ( unsigned long ) V_124 -> V_10 ,
V_48 , F_237 , V_172 ? & V_172 : NULL ) ) {
F_240 ( V_124 ) ;
return NULL ;
}
return V_124 ;
}
void F_240 ( struct V_117 * V_124 )
{
struct V_117 * V_28 ;
V_28 = F_192 ( V_124 -> V_10 ) ;
F_27 ( V_28 != V_124 ) ;
F_88 ( V_124 ) ;
}
static struct V_35 * F_241 ( struct V_36 * V_37 )
{
return F_242 ( V_37 , struct V_35 , V_36 ) ;
}
static bool F_243 ( unsigned long V_11 ,
struct V_35 * * V_173 ,
struct V_35 * * V_174 )
{
struct V_36 * V_37 = V_38 . V_36 ;
struct V_35 * V_39 = NULL ;
while ( V_37 ) {
V_39 = F_62 ( V_37 , struct V_35 , V_36 ) ;
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
* V_173 = V_39 ;
* V_174 = F_241 ( F_67 ( & ( * V_173 ) -> V_36 ) ) ;
} else {
* V_174 = V_39 ;
* V_173 = F_241 ( F_244 ( & ( * V_174 ) -> V_36 ) ) ;
}
return true ;
}
static unsigned long F_245 ( struct V_35 * * V_173 ,
struct V_35 * * V_174 ,
unsigned long V_49 )
{
const unsigned long V_175 = V_75 & ~ ( V_49 - 1 ) ;
unsigned long V_10 ;
if ( * V_173 )
V_10 = F_158 ( ( * V_173 ) -> va_start & ~ ( V_49 - 1 ) , V_175 ) ;
else
V_10 = V_175 ;
while ( * V_174 && ( * V_174 ) -> va_end > V_10 ) {
* V_173 = * V_174 ;
* V_174 = F_241 ( F_67 ( & ( * V_173 ) -> V_36 ) ) ;
}
return V_10 ;
}
struct V_117 * * F_246 ( const unsigned long * V_176 ,
const T_9 * V_177 , int V_178 ,
T_9 V_49 )
{
const unsigned long V_179 = F_78 ( V_74 , V_49 ) ;
const unsigned long V_175 = V_75 & ~ ( V_49 - 1 ) ;
struct V_35 * * V_180 , * V_45 , * V_17 ;
struct V_117 * * V_181 ;
int V_124 , V_182 , V_183 , V_184 ;
unsigned long V_185 , V_26 , V_11 , V_186 ;
bool V_54 = false ;
F_27 ( F_70 ( V_49 ) || ! F_71 ( V_49 ) ) ;
for ( V_183 = 0 , V_124 = 0 ; V_124 < V_178 ; V_124 ++ ) {
V_26 = V_176 [ V_124 ] ;
V_11 = V_26 + V_177 [ V_124 ] ;
F_27 ( ! F_82 ( V_176 [ V_124 ] , V_49 ) ) ;
F_27 ( ! F_82 ( V_177 [ V_124 ] , V_49 ) ) ;
if ( V_26 > V_176 [ V_183 ] )
V_183 = V_124 ;
for ( V_182 = V_124 + 1 ; V_182 < V_178 ; V_182 ++ ) {
unsigned long V_187 = V_176 [ V_182 ] ;
unsigned long V_188 = V_187 + V_177 [ V_182 ] ;
F_27 ( V_187 < V_11 && V_26 < V_188 ) ;
}
}
V_186 = V_176 [ V_183 ] + V_177 [ V_183 ] ;
if ( V_175 - V_179 < V_186 ) {
F_8 ( true ) ;
return NULL ;
}
V_181 = F_247 ( V_178 , sizeof( V_181 [ 0 ] ) , V_116 ) ;
V_180 = F_247 ( V_178 , sizeof( V_180 [ 0 ] ) , V_116 ) ;
if ( ! V_180 || ! V_181 )
goto V_189;
for ( V_124 = 0 ; V_124 < V_178 ; V_124 ++ ) {
V_180 [ V_124 ] = F_171 ( sizeof( struct V_35 ) , V_116 ) ;
V_181 [ V_124 ] = F_171 ( sizeof( struct V_117 ) , V_116 ) ;
if ( ! V_180 [ V_124 ] || ! V_181 [ V_124 ] )
goto V_190;
}
V_58:
F_77 ( & V_59 ) ;
V_124 = V_184 = V_183 ;
V_26 = V_176 [ V_124 ] ;
V_11 = V_26 + V_177 [ V_124 ] ;
if ( ! F_243 ( V_76 , & V_17 , & V_45 ) ) {
V_185 = V_175 - V_186 ;
goto V_66;
}
V_185 = F_245 ( & V_17 , & V_45 , V_49 ) - V_11 ;
while ( true ) {
F_27 ( V_17 && V_17 -> va_end <= V_185 + V_11 ) ;
F_27 ( V_45 && V_45 -> va_end > V_185 + V_11 ) ;
if ( V_185 + V_186 < V_179 + V_186 ) {
F_81 ( & V_59 ) ;
if ( ! V_54 ) {
F_83 () ;
V_54 = true ;
goto V_58;
}
goto V_190;
}
if ( V_17 && V_17 -> va_start < V_185 + V_11 ) {
V_185 = F_245 ( & V_17 , & V_45 , V_49 ) - V_11 ;
V_184 = V_124 ;
continue;
}
if ( V_45 && V_45 -> va_end > V_185 + V_26 ) {
V_17 = V_45 ;
V_45 = F_241 ( F_67 ( & V_17 -> V_36 ) ) ;
V_185 = F_245 ( & V_17 , & V_45 , V_49 ) - V_11 ;
V_184 = V_124 ;
continue;
}
V_124 = ( V_124 + V_178 - 1 ) % V_178 ;
if ( V_124 == V_184 )
break;
V_26 = V_176 [ V_124 ] ;
V_11 = V_26 + V_177 [ V_124 ] ;
F_243 ( V_185 + V_11 , & V_17 , & V_45 ) ;
}
V_66:
for ( V_124 = 0 ; V_124 < V_178 ; V_124 ++ ) {
struct V_35 * V_39 = V_180 [ V_124 ] ;
V_39 -> va_start = V_185 + V_176 [ V_124 ] ;
V_39 -> va_end = V_39 -> va_start + V_177 [ V_124 ] ;
F_63 ( V_39 ) ;
}
V_76 = V_185 + V_176 [ V_183 ] ;
F_81 ( & V_59 ) ;
for ( V_124 = 0 ; V_124 < V_178 ; V_124 ++ )
F_177 ( V_181 [ V_124 ] , V_180 [ V_124 ] , V_148 ,
F_246 ) ;
F_88 ( V_180 ) ;
return V_181 ;
V_190:
for ( V_124 = 0 ; V_124 < V_178 ; V_124 ++ ) {
F_88 ( V_180 [ V_124 ] ) ;
F_88 ( V_181 [ V_124 ] ) ;
}
V_189:
F_88 ( V_180 ) ;
F_88 ( V_181 ) ;
return NULL ;
}
void F_248 ( struct V_117 * * V_181 , int V_178 )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_178 ; V_121 ++ )
F_240 ( V_181 [ V_121 ] ) ;
F_88 ( V_181 ) ;
}
static void * F_249 ( struct V_191 * V_192 , T_12 * V_193 )
__acquires( &vmap_area_lock
static void * F_250 ( struct V_191 * V_192 , void * V_4 , T_12 * V_193 )
{
return F_251 ( V_4 , & V_47 , V_193 ) ;
}
static void F_252 ( struct V_191 * V_192 , void * V_4 )
__releases( &vmap_area_lock
static void F_253 ( struct V_191 * V_192 , struct V_117 * V_194 )
{
if ( F_254 ( V_195 ) ) {
unsigned int V_23 , * V_196 = V_192 -> V_197 ;
if ( ! V_196 )
return;
if ( V_194 -> V_67 & V_126 )
return;
F_255 () ;
memset ( V_196 , 0 , V_198 * sizeof( unsigned int ) ) ;
for ( V_23 = 0 ; V_23 < V_194 -> V_134 ; V_23 ++ )
V_196 [ F_256 ( V_194 -> V_22 [ V_23 ] ) ] ++ ;
F_257 (nr, N_HIGH_MEMORY)
if ( V_196 [ V_23 ] )
F_258 ( V_192 , L_6 , V_23 , V_196 [ V_23 ] ) ;
}
}
static int F_259 ( struct V_191 * V_192 , void * V_4 )
{
struct V_35 * V_39 ;
struct V_117 * V_194 ;
V_39 = F_260 ( V_4 , struct V_35 , V_46 ) ;
if ( ! ( V_39 -> V_67 & V_123 ) ) {
F_258 ( V_192 , L_7 ,
( void * ) V_39 -> va_start , ( void * ) V_39 -> va_end ,
V_39 -> va_end - V_39 -> va_start ,
V_39 -> V_67 & V_131 ? L_8 : L_9 ) ;
return 0 ;
}
V_194 = V_39 -> V_118 ;
F_258 ( V_192 , L_10 ,
V_194 -> V_10 , V_194 -> V_10 + V_194 -> V_48 , V_194 -> V_48 ) ;
if ( V_194 -> V_125 )
F_258 ( V_192 , L_11 , V_194 -> V_125 ) ;
if ( V_194 -> V_134 )
F_258 ( V_192 , L_12 , V_194 -> V_134 ) ;
if ( V_194 -> V_199 )
F_258 ( V_192 , L_13 , & V_194 -> V_199 ) ;
if ( V_194 -> V_67 & V_127 )
F_261 ( V_192 , L_14 ) ;
if ( V_194 -> V_67 & V_148 )
F_261 ( V_192 , L_15 ) ;
if ( V_194 -> V_67 & V_200 )
F_261 ( V_192 , L_16 ) ;
if ( V_194 -> V_67 & V_150 )
F_261 ( V_192 , L_17 ) ;
if ( F_46 ( V_194 -> V_22 ) )
F_261 ( V_192 , L_18 ) ;
F_253 ( V_192 , V_194 ) ;
F_262 ( V_192 , '\n' ) ;
return 0 ;
}
static int F_263 ( struct V_201 * V_201 , struct V_202 * V_202 )
{
if ( F_254 ( V_195 ) )
return F_264 ( V_202 , & V_203 ,
V_198 * sizeof( unsigned int ) ) ;
else
return F_265 ( V_202 , & V_203 ) ;
}
static int T_8 F_266 ( void )
{
F_267 ( L_19 , V_204 , NULL , & V_205 ) ;
return 0 ;
}
