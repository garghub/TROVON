static inline void F_1 ( struct V_1 * V_2 )
{
bool free = ( V_2 -> V_3 == 0 ) && ( V_2 -> V_4 == 0 ) ;
F_2 ( & V_2 -> V_5 ) ;
if ( free )
F_3 ( V_2 ) ;
}
struct V_1 * F_4 ( long V_6 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( sizeof( * V_2 ) , V_7 ) ;
if ( ! V_2 )
return NULL ;
F_6 ( & V_2 -> V_5 ) ;
V_2 -> V_3 = 1 ;
V_2 -> V_8 = V_6 ;
V_2 -> V_4 = 0 ;
return V_2 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_5 ) ;
F_9 ( ! V_2 -> V_3 ) ;
V_2 -> V_3 -- ;
F_1 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
long V_9 )
{
int V_10 = 0 ;
if ( ! V_2 )
return 0 ;
F_8 ( & V_2 -> V_5 ) ;
if ( ( V_2 -> V_4 + V_9 ) <= V_2 -> V_8 ) {
V_2 -> V_4 += V_9 ;
} else {
V_10 = - V_11 ;
}
F_2 ( & V_2 -> V_5 ) ;
return V_10 ;
}
static void F_11 ( struct V_1 * V_2 ,
long V_9 )
{
if ( ! V_2 )
return;
F_8 ( & V_2 -> V_5 ) ;
V_2 -> V_4 -= V_9 ;
F_1 ( V_2 ) ;
}
static inline struct V_1 * F_12 ( struct V_12 * V_12 )
{
return F_13 ( V_12 -> V_13 ) -> V_2 ;
}
static inline struct V_1 * F_14 ( struct V_14 * V_15 )
{
return F_12 ( F_15 ( V_15 -> V_16 ) ) ;
}
static long F_16 ( struct V_17 * V_18 , long V_19 , long V_20 )
{
struct V_21 * V_22 = & V_18 -> V_23 ;
struct V_24 * V_25 , * V_26 , * V_27 ;
F_8 ( & V_18 -> V_5 ) ;
F_17 (rg, head, link)
if ( V_19 <= V_25 -> V_28 )
break;
if ( V_19 > V_25 -> V_29 )
V_19 = V_25 -> V_29 ;
V_26 = V_25 ;
F_18 (rg, trg, rg->link.prev, link) {
if ( & V_25 -> V_30 == V_22 )
break;
if ( V_25 -> V_29 > V_20 )
break;
if ( V_25 -> V_28 > V_20 )
V_20 = V_25 -> V_28 ;
if ( V_25 != V_26 ) {
F_19 ( & V_25 -> V_30 ) ;
F_3 ( V_25 ) ;
}
}
V_26 -> V_29 = V_19 ;
V_26 -> V_28 = V_20 ;
F_2 ( & V_18 -> V_5 ) ;
return 0 ;
}
static long F_20 ( struct V_17 * V_18 , long V_19 , long V_20 )
{
struct V_21 * V_22 = & V_18 -> V_23 ;
struct V_24 * V_25 , * V_26 = NULL ;
long V_31 = 0 ;
V_32:
F_8 ( & V_18 -> V_5 ) ;
F_17 (rg, head, link)
if ( V_19 <= V_25 -> V_28 )
break;
if ( & V_25 -> V_30 == V_22 || V_20 < V_25 -> V_29 ) {
if ( ! V_26 ) {
F_2 ( & V_18 -> V_5 ) ;
V_26 = F_5 ( sizeof( * V_26 ) , V_7 ) ;
if ( ! V_26 )
return - V_11 ;
V_26 -> V_29 = V_19 ;
V_26 -> V_28 = V_19 ;
F_21 ( & V_26 -> V_30 ) ;
goto V_32;
}
F_22 ( & V_26 -> V_30 , V_25 -> V_30 . V_33 ) ;
V_31 = V_20 - V_19 ;
goto V_34;
}
if ( V_19 > V_25 -> V_29 )
V_19 = V_25 -> V_29 ;
V_31 = V_20 - V_19 ;
F_17 (rg, rg->link.prev, link) {
if ( & V_25 -> V_30 == V_22 )
break;
if ( V_25 -> V_29 > V_20 )
goto V_35;
if ( V_25 -> V_28 > V_20 ) {
V_31 += V_25 -> V_28 - V_20 ;
V_20 = V_25 -> V_28 ;
}
V_31 -= V_25 -> V_28 - V_25 -> V_29 ;
}
V_35:
F_2 ( & V_18 -> V_5 ) ;
F_3 ( V_26 ) ;
return V_31 ;
V_34:
F_2 ( & V_18 -> V_5 ) ;
return V_31 ;
}
static long F_23 ( struct V_17 * V_18 , long V_36 )
{
struct V_21 * V_22 = & V_18 -> V_23 ;
struct V_24 * V_25 , * V_27 ;
long V_31 = 0 ;
F_8 ( & V_18 -> V_5 ) ;
F_17 (rg, head, link)
if ( V_36 <= V_25 -> V_28 )
break;
if ( & V_25 -> V_30 == V_22 )
goto V_35;
if ( V_36 > V_25 -> V_29 ) {
V_31 = V_25 -> V_28 - V_36 ;
V_25 -> V_28 = V_36 ;
V_25 = F_24 ( V_25 -> V_30 . V_37 , F_25 ( * V_25 ) , V_30 ) ;
}
F_18 (rg, trg, rg->link.prev, link) {
if ( & V_25 -> V_30 == V_22 )
break;
V_31 += V_25 -> V_28 - V_25 -> V_29 ;
F_19 ( & V_25 -> V_30 ) ;
F_3 ( V_25 ) ;
}
V_35:
F_2 ( & V_18 -> V_5 ) ;
return V_31 ;
}
static long F_26 ( struct V_17 * V_18 , long V_19 , long V_20 )
{
struct V_21 * V_22 = & V_18 -> V_23 ;
struct V_24 * V_25 ;
long V_31 = 0 ;
F_8 ( & V_18 -> V_5 ) ;
F_17 (rg, head, link) {
long V_38 ;
long V_39 ;
if ( V_25 -> V_28 <= V_19 )
continue;
if ( V_25 -> V_29 >= V_20 )
break;
V_38 = F_27 ( V_25 -> V_29 , V_19 ) ;
V_39 = F_28 ( V_25 -> V_28 , V_20 ) ;
V_31 += V_39 - V_38 ;
}
F_2 ( & V_18 -> V_5 ) ;
return V_31 ;
}
static T_1 F_29 ( struct V_40 * V_41 ,
struct V_14 * V_15 , unsigned long V_42 )
{
return ( ( V_42 - V_15 -> V_43 ) >> F_30 ( V_41 ) ) +
( V_15 -> V_44 >> F_31 ( V_41 ) ) ;
}
T_1 F_32 ( struct V_14 * V_15 ,
unsigned long V_42 )
{
return F_29 ( F_33 ( V_15 ) , V_15 , V_42 ) ;
}
unsigned long F_34 ( struct V_14 * V_15 )
{
struct V_40 * V_40 ;
if ( ! F_35 ( V_15 ) )
return V_45 ;
V_40 = F_33 ( V_15 ) ;
return 1UL << F_30 ( V_40 ) ;
}
unsigned long F_36 ( struct V_14 * V_15 )
{
return F_34 ( V_15 ) ;
}
static unsigned long F_37 ( struct V_14 * V_15 )
{
return ( unsigned long ) V_15 -> V_46 ;
}
static void F_38 ( struct V_14 * V_15 ,
unsigned long V_47 )
{
V_15 -> V_46 = ( void * ) V_47 ;
}
struct V_17 * F_39 ( void )
{
struct V_17 * V_17 = F_5 ( sizeof( * V_17 ) , V_7 ) ;
if ( ! V_17 )
return NULL ;
F_40 ( & V_17 -> V_48 ) ;
F_6 ( & V_17 -> V_5 ) ;
F_21 ( & V_17 -> V_23 ) ;
return V_17 ;
}
void F_41 ( struct V_49 * V_50 )
{
struct V_17 * V_17 = F_42 ( V_50 , struct V_17 , V_48 ) ;
F_23 ( V_17 , 0 ) ;
F_3 ( V_17 ) ;
}
static inline struct V_17 * F_43 ( struct V_12 * V_12 )
{
return V_12 -> V_51 -> V_52 ;
}
static struct V_17 * F_44 ( struct V_14 * V_15 )
{
F_45 ( ! F_35 ( V_15 ) ) ;
if ( V_15 -> V_53 & V_54 ) {
struct V_55 * V_56 = V_15 -> V_16 -> V_57 ;
struct V_12 * V_12 = V_56 -> V_58 ;
return F_43 ( V_12 ) ;
} else {
return (struct V_17 * ) ( F_37 ( V_15 ) &
~ V_59 ) ;
}
}
static void F_46 ( struct V_14 * V_15 , struct V_17 * V_60 )
{
F_45 ( ! F_35 ( V_15 ) ) ;
F_45 ( V_15 -> V_53 & V_54 ) ;
F_38 ( V_15 , ( F_37 ( V_15 ) &
V_59 ) | ( unsigned long ) V_60 ) ;
}
static void F_47 ( struct V_14 * V_15 , unsigned long V_61 )
{
F_45 ( ! F_35 ( V_15 ) ) ;
F_45 ( V_15 -> V_53 & V_54 ) ;
F_38 ( V_15 , F_37 ( V_15 ) | V_61 ) ;
}
static int F_48 ( struct V_14 * V_15 , unsigned long V_62 )
{
F_45 ( ! F_35 ( V_15 ) ) ;
return ( F_37 ( V_15 ) & V_62 ) != 0 ;
}
void F_49 ( struct V_14 * V_15 )
{
F_45 ( ! F_35 ( V_15 ) ) ;
if ( ! ( V_15 -> V_53 & V_54 ) )
V_15 -> V_46 = ( void * ) 0 ;
}
static int F_50 ( struct V_14 * V_15 , long V_31 )
{
if ( V_15 -> V_53 & V_63 ) {
if ( V_15 -> V_53 & V_54 && V_31 == 0 )
return 1 ;
else
return 0 ;
}
if ( V_15 -> V_53 & V_54 )
return 1 ;
if ( F_48 ( V_15 , V_64 ) )
return 1 ;
return 0 ;
}
static void F_51 ( struct V_40 * V_41 , struct V_65 * V_65 )
{
int V_66 = F_52 ( V_65 ) ;
F_53 ( & V_65 -> V_67 , & V_41 -> V_68 [ V_66 ] ) ;
V_41 -> V_69 ++ ;
V_41 -> V_70 [ V_66 ] ++ ;
}
static struct V_65 * F_54 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 ;
F_17 (page, &h->hugepage_freelists[nid], lru)
if ( ! F_55 ( V_65 ) )
break;
if ( & V_41 -> V_68 [ V_66 ] == & V_65 -> V_67 )
return NULL ;
F_53 ( & V_65 -> V_67 , & V_41 -> V_71 ) ;
F_56 ( V_65 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ V_66 ] -- ;
return V_65 ;
}
static inline T_2 F_57 ( struct V_40 * V_41 )
{
if ( V_72 || F_58 ( V_41 ) )
return V_73 ;
else
return V_74 ;
}
static struct V_65 * F_59 ( struct V_40 * V_41 ,
struct V_14 * V_15 ,
unsigned long V_42 , int V_75 ,
long V_31 )
{
struct V_65 * V_65 = NULL ;
struct V_76 * V_77 ;
T_3 * V_78 ;
struct V_79 * V_79 ;
struct V_80 * V_80 ;
struct V_81 * V_82 ;
unsigned int V_83 ;
if ( ! F_50 ( V_15 , V_31 ) &&
V_41 -> V_69 - V_41 -> V_84 == 0 )
goto V_85;
if ( V_75 && V_41 -> V_69 - V_41 -> V_84 == 0 )
goto V_85;
V_86:
V_83 = F_60 () ;
V_79 = F_61 ( V_15 , V_42 ,
F_57 ( V_41 ) , & V_77 , & V_78 ) ;
F_62 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_63 ( V_80 , F_57 ( V_41 ) ) ) {
V_65 = F_54 ( V_41 , F_64 ( V_80 ) ) ;
if ( V_65 ) {
if ( V_75 )
break;
if ( ! F_50 ( V_15 , V_31 ) )
break;
F_65 ( V_65 ) ;
V_41 -> V_84 -- ;
break;
}
}
}
F_66 ( V_77 ) ;
if ( F_67 ( ! V_65 && F_68 ( V_83 ) ) )
goto V_86;
return V_65 ;
V_85:
return NULL ;
}
static int F_69 ( int V_66 , T_3 * V_87 )
{
V_66 = F_70 ( V_66 , * V_87 ) ;
if ( V_66 == V_88 )
V_66 = F_71 ( * V_87 ) ;
F_45 ( V_66 >= V_88 ) ;
return V_66 ;
}
static int F_72 ( int V_66 , T_3 * V_87 )
{
if ( ! F_73 ( V_66 , * V_87 ) )
V_66 = F_69 ( V_66 , V_87 ) ;
return V_66 ;
}
static int F_74 ( struct V_40 * V_41 ,
T_3 * V_87 )
{
int V_66 ;
F_45 ( ! V_87 ) ;
V_66 = F_72 ( V_41 -> V_89 , V_87 ) ;
V_41 -> V_89 = F_69 ( V_66 , V_87 ) ;
return V_66 ;
}
static int F_75 ( struct V_40 * V_41 , T_3 * V_87 )
{
int V_66 ;
F_45 ( ! V_87 ) ;
V_66 = F_72 ( V_41 -> V_90 , V_87 ) ;
V_41 -> V_90 = F_69 ( V_66 , V_87 ) ;
return V_66 ;
}
static void F_76 ( struct V_65 * V_65 ,
unsigned long V_91 )
{
int V_92 ;
int V_93 = 1 << V_91 ;
struct V_65 * V_94 = V_65 + 1 ;
for ( V_92 = 1 ; V_92 < V_93 ; V_92 ++ , V_94 = F_77 ( V_94 , V_65 , V_92 ) ) {
F_78 ( V_94 ) ;
F_56 ( V_94 ) ;
V_94 -> V_95 = NULL ;
}
F_79 ( V_65 , 0 ) ;
F_80 ( V_65 ) ;
}
static void F_81 ( struct V_65 * V_65 , unsigned V_91 )
{
F_82 ( F_83 ( V_65 ) , 1 << V_91 ) ;
}
static int F_84 ( unsigned long V_96 ,
unsigned long V_93 )
{
unsigned long V_97 = V_96 + V_93 ;
return F_85 ( V_96 , V_97 , V_98 ) ;
}
static bool F_86 ( unsigned long V_96 ,
unsigned long V_93 )
{
unsigned long V_92 , V_97 = V_96 + V_93 ;
struct V_65 * V_65 ;
for ( V_92 = V_96 ; V_92 < V_97 ; V_92 ++ ) {
if ( ! F_87 ( V_92 ) )
return false ;
V_65 = F_88 ( V_92 ) ;
if ( F_89 ( V_65 ) )
return false ;
if ( F_90 ( V_65 ) > 0 )
return false ;
if ( F_91 ( V_65 ) )
return false ;
}
return true ;
}
static bool F_92 ( const struct V_80 * V_80 ,
unsigned long V_96 , unsigned long V_93 )
{
unsigned long V_99 = V_96 + V_93 - 1 ;
return F_93 ( V_80 , V_99 ) ;
}
static struct V_65 * F_94 ( int V_66 , unsigned V_91 )
{
unsigned long V_93 = 1 << V_91 ;
unsigned long V_10 , V_100 , V_61 ;
struct V_80 * V_82 ;
V_82 = F_95 ( V_66 ) -> V_101 ;
for (; V_82 - F_95 ( V_66 ) -> V_101 < V_102 ; V_82 ++ ) {
F_96 ( & V_82 -> V_5 , V_61 ) ;
V_100 = F_97 ( V_82 -> V_103 , V_93 ) ;
while ( F_92 ( V_82 , V_100 , V_93 ) ) {
if ( F_86 ( V_100 , V_93 ) ) {
F_98 ( & V_82 -> V_5 , V_61 ) ;
V_10 = F_84 ( V_100 , V_93 ) ;
if ( ! V_10 )
return F_88 ( V_100 ) ;
F_96 ( & V_82 -> V_5 , V_61 ) ;
}
V_100 += V_93 ;
}
F_98 ( & V_82 -> V_5 , V_61 ) ;
}
return NULL ;
}
static struct V_65 * F_99 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 ;
V_65 = F_94 ( V_66 , F_31 ( V_41 ) ) ;
if ( V_65 ) {
F_100 ( V_65 , F_31 ( V_41 ) ) ;
F_101 ( V_41 , V_65 , V_66 ) ;
}
return V_65 ;
}
static int F_102 ( struct V_40 * V_41 ,
T_3 * V_87 )
{
struct V_65 * V_65 = NULL ;
int V_104 , V_105 ;
F_103 (h, nr_nodes, node, nodes_allowed) {
V_65 = F_99 ( V_41 , V_105 ) ;
if ( V_65 )
return 1 ;
}
return 0 ;
}
static inline bool F_104 ( void ) { return true ; }
static inline bool F_104 ( void ) { return false ; }
static inline void F_81 ( struct V_65 * V_65 , unsigned V_91 ) { }
static inline void F_76 ( struct V_65 * V_65 ,
unsigned long V_91 ) { }
static inline int F_102 ( struct V_40 * V_41 ,
T_3 * V_87 ) { return 0 ; }
static void F_105 ( struct V_40 * V_41 , struct V_65 * V_65 )
{
int V_92 ;
if ( F_106 ( V_41 ) && ! F_104 () )
return;
V_41 -> V_106 -- ;
V_41 -> V_107 [ F_52 ( V_65 ) ] -- ;
for ( V_92 = 0 ; V_92 < F_107 ( V_41 ) ; V_92 ++ ) {
V_65 [ V_92 ] . V_61 &= ~ ( 1 << V_108 | 1 << V_109 |
1 << V_110 | 1 << V_111 |
1 << V_112 | 1 << V_113 |
1 << V_114 ) ;
}
F_108 ( F_109 ( V_65 ) , V_65 ) ;
F_110 ( V_65 , NULL ) ;
F_56 ( V_65 ) ;
if ( F_106 ( V_41 ) ) {
F_76 ( V_65 , F_31 ( V_41 ) ) ;
F_81 ( V_65 , F_31 ( V_41 ) ) ;
} else {
F_111 ( V_65 ) ;
F_112 ( V_65 , F_31 ( V_41 ) ) ;
}
}
struct V_40 * F_113 ( unsigned long V_115 )
{
struct V_40 * V_41 ;
F_114 (h) {
if ( F_115 ( V_41 ) == V_115 )
return V_41 ;
}
return NULL ;
}
void F_116 ( struct V_65 * V_65 )
{
struct V_40 * V_41 = F_117 ( V_65 ) ;
int V_66 = F_52 ( V_65 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_118 ( V_65 ) ;
bool V_116 ;
F_119 ( V_65 , 0 ) ;
V_65 -> V_56 = NULL ;
F_9 ( F_90 ( V_65 ) ) ;
F_9 ( F_120 ( V_65 ) ) ;
V_116 = F_121 ( V_65 ) ;
F_122 ( V_65 ) ;
F_8 ( & V_117 ) ;
F_123 ( F_124 ( V_41 ) ,
F_107 ( V_41 ) , V_65 ) ;
if ( V_116 )
V_41 -> V_84 ++ ;
if ( V_41 -> V_118 [ V_66 ] ) {
F_19 ( & V_65 -> V_67 ) ;
F_105 ( V_41 , V_65 ) ;
V_41 -> V_119 -- ;
V_41 -> V_118 [ V_66 ] -- ;
} else {
F_125 ( V_65 ) ;
F_51 ( V_41 , V_65 ) ;
}
F_2 ( & V_117 ) ;
F_11 ( V_2 , 1 ) ;
}
static void F_101 ( struct V_40 * V_41 , struct V_65 * V_65 , int V_66 )
{
F_21 ( & V_65 -> V_67 ) ;
F_110 ( V_65 , F_116 ) ;
F_8 ( & V_117 ) ;
F_126 ( V_65 , NULL ) ;
V_41 -> V_106 ++ ;
V_41 -> V_107 [ V_66 ] ++ ;
F_2 ( & V_117 ) ;
F_127 ( V_65 ) ;
}
static void F_100 ( struct V_65 * V_65 , unsigned long V_91 )
{
int V_92 ;
int V_93 = 1 << V_91 ;
struct V_65 * V_94 = V_65 + 1 ;
F_79 ( V_65 , V_91 ) ;
F_128 ( V_65 ) ;
F_129 ( V_65 ) ;
for ( V_92 = 1 ; V_92 < V_93 ; V_92 ++ , V_94 = F_77 ( V_94 , V_65 , V_92 ) ) {
F_130 ( V_94 ) ;
F_129 ( V_94 ) ;
F_131 ( V_94 , 0 ) ;
V_94 -> V_95 = V_65 ;
}
}
int F_91 ( struct V_65 * V_65 )
{
if ( ! F_132 ( V_65 ) )
return 0 ;
V_65 = F_133 ( V_65 ) ;
return F_134 ( V_65 ) == F_116 ;
}
int F_135 ( struct V_65 * V_120 )
{
if ( ! F_136 ( V_120 ) )
return 0 ;
return F_134 ( V_120 ) == F_116 ;
}
T_1 F_137 ( struct V_65 * V_65 )
{
struct V_65 * V_120 = F_133 ( V_65 ) ;
T_1 V_121 = F_138 ( V_120 ) ;
unsigned long V_122 ;
if ( ! F_91 ( V_120 ) )
return F_138 ( V_65 ) ;
if ( F_139 ( V_120 ) >= V_123 )
V_122 = F_83 ( V_65 ) - F_83 ( V_120 ) ;
else
V_122 = V_65 - V_120 ;
return ( V_121 << F_139 ( V_120 ) ) + V_122 ;
}
static struct V_65 * F_140 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 ;
V_65 = F_141 ( V_66 ,
F_57 ( V_41 ) | V_124 | V_125 |
V_126 | V_127 ,
F_31 ( V_41 ) ) ;
if ( V_65 ) {
if ( F_142 ( V_65 ) ) {
F_112 ( V_65 , F_31 ( V_41 ) ) ;
return NULL ;
}
F_101 ( V_41 , V_65 , V_66 ) ;
}
return V_65 ;
}
static int F_143 ( struct V_40 * V_41 , T_3 * V_87 )
{
struct V_65 * V_65 ;
int V_104 , V_105 ;
int V_10 = 0 ;
F_103 (h, nr_nodes, node, nodes_allowed) {
V_65 = F_140 ( V_41 , V_105 ) ;
if ( V_65 ) {
V_10 = 1 ;
break;
}
}
if ( V_10 )
F_144 ( V_128 ) ;
else
F_144 ( V_129 ) ;
return V_10 ;
}
static int F_145 ( struct V_40 * V_41 , T_3 * V_87 ,
bool V_130 )
{
int V_104 , V_105 ;
int V_10 = 0 ;
F_146 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_130 || V_41 -> V_118 [ V_105 ] ) &&
! F_147 ( & V_41 -> V_68 [ V_105 ] ) ) {
struct V_65 * V_65 =
F_24 ( V_41 -> V_68 [ V_105 ] . V_37 ,
struct V_65 , V_67 ) ;
F_19 ( & V_65 -> V_67 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ V_105 ] -- ;
if ( V_130 ) {
V_41 -> V_119 -- ;
V_41 -> V_118 [ V_105 ] -- ;
}
F_105 ( V_41 , V_65 ) ;
V_10 = 1 ;
break;
}
}
return V_10 ;
}
static void F_148 ( struct V_65 * V_65 )
{
F_8 ( & V_117 ) ;
if ( F_91 ( V_65 ) && ! F_90 ( V_65 ) ) {
struct V_40 * V_41 = F_117 ( V_65 ) ;
int V_66 = F_52 ( V_65 ) ;
F_19 ( & V_65 -> V_67 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ V_66 ] -- ;
F_105 ( V_41 , V_65 ) ;
}
F_2 ( & V_117 ) ;
}
void F_149 ( unsigned long V_96 , unsigned long V_97 )
{
unsigned int V_91 = 8 * sizeof( void * ) ;
unsigned long V_100 ;
struct V_40 * V_41 ;
F_114 (h)
if ( V_91 > F_31 ( V_41 ) )
V_91 = F_31 ( V_41 ) ;
F_45 ( ! F_150 ( V_96 , 1 << V_91 ) ) ;
for ( V_100 = V_96 ; V_100 < V_97 ; V_100 += 1 << V_91 )
F_148 ( F_88 ( V_100 ) ) ;
}
static struct V_65 * F_151 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 ;
unsigned int V_131 ;
if ( F_106 ( V_41 ) )
return NULL ;
F_8 ( & V_117 ) ;
if ( V_41 -> V_119 >= V_41 -> V_132 ) {
F_2 ( & V_117 ) ;
return NULL ;
} else {
V_41 -> V_106 ++ ;
V_41 -> V_119 ++ ;
}
F_2 ( & V_117 ) ;
if ( V_66 == V_133 )
V_65 = F_152 ( F_57 ( V_41 ) | V_124 |
V_126 | V_127 ,
F_31 ( V_41 ) ) ;
else
V_65 = F_141 ( V_66 ,
F_57 ( V_41 ) | V_124 | V_125 |
V_126 | V_127 , F_31 ( V_41 ) ) ;
if ( V_65 && F_142 ( V_65 ) ) {
F_112 ( V_65 , F_31 ( V_41 ) ) ;
V_65 = NULL ;
}
F_8 ( & V_117 ) ;
if ( V_65 ) {
F_21 ( & V_65 -> V_67 ) ;
V_131 = F_52 ( V_65 ) ;
F_110 ( V_65 , F_116 ) ;
F_126 ( V_65 , NULL ) ;
V_41 -> V_107 [ V_131 ] ++ ;
V_41 -> V_118 [ V_131 ] ++ ;
F_153 ( V_128 ) ;
} else {
V_41 -> V_106 -- ;
V_41 -> V_119 -- ;
F_153 ( V_129 ) ;
}
F_2 ( & V_117 ) ;
return V_65 ;
}
struct V_65 * F_154 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 = NULL ;
F_8 ( & V_117 ) ;
if ( V_41 -> V_69 - V_41 -> V_84 > 0 )
V_65 = F_54 ( V_41 , V_66 ) ;
F_2 ( & V_117 ) ;
if ( ! V_65 )
V_65 = F_151 ( V_41 , V_66 ) ;
return V_65 ;
}
static int F_155 ( struct V_40 * V_41 , int V_9 )
{
struct V_21 V_134 ;
struct V_65 * V_65 , * V_135 ;
int V_10 , V_92 ;
int V_136 , V_137 ;
bool V_138 = true ;
V_136 = ( V_41 -> V_84 + V_9 ) - V_41 -> V_69 ;
if ( V_136 <= 0 ) {
V_41 -> V_84 += V_9 ;
return 0 ;
}
V_137 = 0 ;
F_21 ( & V_134 ) ;
V_10 = - V_11 ;
V_32:
F_2 ( & V_117 ) ;
for ( V_92 = 0 ; V_92 < V_136 ; V_92 ++ ) {
V_65 = F_151 ( V_41 , V_133 ) ;
if ( ! V_65 ) {
V_138 = false ;
break;
}
F_22 ( & V_65 -> V_67 , & V_134 ) ;
}
V_137 += V_92 ;
F_8 ( & V_117 ) ;
V_136 = ( V_41 -> V_84 + V_9 ) -
( V_41 -> V_69 + V_137 ) ;
if ( V_136 > 0 ) {
if ( V_138 )
goto V_32;
goto free;
}
V_136 += V_137 ;
V_41 -> V_84 += V_9 ;
V_10 = 0 ;
F_18 (page, tmp, &surplus_list, lru) {
if ( ( -- V_136 ) < 0 )
break;
F_156 ( V_65 ) ;
F_108 ( F_90 ( V_65 ) , V_65 ) ;
F_51 ( V_41 , V_65 ) ;
}
free:
F_2 ( & V_117 ) ;
F_18 (page, tmp, &surplus_list, lru)
F_127 ( V_65 ) ;
F_8 ( & V_117 ) ;
return V_10 ;
}
static void F_157 ( struct V_40 * V_41 ,
unsigned long V_139 )
{
unsigned long V_93 ;
V_41 -> V_84 -= V_139 ;
if ( F_106 ( V_41 ) )
return;
V_93 = F_28 ( V_139 , V_41 -> V_119 ) ;
while ( V_93 -- ) {
if ( ! F_145 ( V_41 , & V_140 [ V_141 ] , 1 ) )
break;
F_158 ( & V_117 ) ;
}
}
static long F_159 ( struct V_40 * V_41 ,
struct V_14 * V_15 , unsigned long V_142 )
{
struct V_17 * V_18 ;
T_1 V_143 ;
long V_31 ;
V_18 = F_44 ( V_15 ) ;
if ( ! V_18 )
return 1 ;
V_143 = F_29 ( V_41 , V_15 , V_142 ) ;
V_31 = F_20 ( V_18 , V_143 , V_143 + 1 ) ;
if ( V_15 -> V_53 & V_54 )
return V_31 ;
else
return V_31 < 0 ? V_31 : 0 ;
}
static void F_160 ( struct V_40 * V_41 ,
struct V_14 * V_15 , unsigned long V_142 )
{
struct V_17 * V_18 ;
T_1 V_143 ;
V_18 = F_44 ( V_15 ) ;
if ( ! V_18 )
return;
V_143 = F_29 ( V_41 , V_15 , V_142 ) ;
F_16 ( V_18 , V_143 , V_143 + 1 ) ;
}
static struct V_65 * F_161 ( struct V_14 * V_15 ,
unsigned long V_142 , int V_75 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_65 * V_65 ;
long V_31 ;
int V_10 , V_143 ;
struct V_144 * V_145 ;
V_143 = F_124 ( V_41 ) ;
V_31 = F_159 ( V_41 , V_15 , V_142 ) ;
if ( V_31 < 0 )
return F_162 ( - V_11 ) ;
if ( V_31 || V_75 )
if ( F_10 ( V_2 , 1 ) )
return F_162 ( - V_146 ) ;
V_10 = F_163 ( V_143 , F_107 ( V_41 ) , & V_145 ) ;
if ( V_10 )
goto V_147;
F_8 ( & V_117 ) ;
V_65 = F_59 ( V_41 , V_15 , V_142 , V_75 , V_31 ) ;
if ( ! V_65 ) {
F_2 ( & V_117 ) ;
V_65 = F_151 ( V_41 , V_133 ) ;
if ( ! V_65 )
goto V_148;
F_8 ( & V_117 ) ;
F_53 ( & V_65 -> V_67 , & V_41 -> V_71 ) ;
}
F_164 ( V_143 , F_107 ( V_41 ) , V_145 , V_65 ) ;
F_2 ( & V_117 ) ;
F_119 ( V_65 , ( unsigned long ) V_2 ) ;
F_160 ( V_41 , V_15 , V_142 ) ;
return V_65 ;
V_148:
F_165 ( V_143 , F_107 ( V_41 ) , V_145 ) ;
V_147:
if ( V_31 || V_75 )
F_11 ( V_2 , 1 ) ;
return F_162 ( - V_146 ) ;
}
struct V_65 * F_166 ( struct V_14 * V_15 ,
unsigned long V_142 , int V_75 )
{
struct V_65 * V_65 = F_161 ( V_15 , V_142 , V_75 ) ;
if ( F_167 ( V_65 ) )
V_65 = NULL ;
return V_65 ;
}
int __weak F_168 ( struct V_40 * V_41 )
{
struct V_149 * V_150 ;
int V_104 , V_105 ;
F_103 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_142 ;
V_142 = F_169 (
F_115 ( V_41 ) , F_115 ( V_41 ) ,
0 , V_151 , V_105 ) ;
if ( V_142 ) {
V_150 = V_142 ;
goto V_152;
}
}
return 0 ;
V_152:
F_9 ( ( unsigned long ) F_170 ( V_150 ) & ( F_115 ( V_41 ) - 1 ) ) ;
F_22 ( & V_150 -> V_153 , & V_154 ) ;
V_150 -> V_40 = V_41 ;
return 1 ;
}
static void T_4 F_171 ( struct V_65 * V_65 , int V_91 )
{
if ( F_67 ( V_91 > ( V_123 - 1 ) ) )
F_100 ( V_65 , V_91 ) ;
else
F_172 ( V_65 , V_91 ) ;
}
static void T_4 F_173 ( void )
{
struct V_149 * V_150 ;
F_17 (m, &huge_boot_pages, list) {
struct V_40 * V_41 = V_150 -> V_40 ;
struct V_65 * V_65 ;
#ifdef F_174
V_65 = F_88 ( V_150 -> V_155 >> V_156 ) ;
F_175 ( F_176 ( V_150 ) ,
sizeof( struct V_149 ) ) ;
#else
V_65 = F_177 ( V_150 ) ;
#endif
F_178 ( F_90 ( V_65 ) != 1 ) ;
F_171 ( V_65 , V_41 -> V_91 ) ;
F_178 ( F_89 ( V_65 ) ) ;
F_101 ( V_41 , V_65 , F_52 ( V_65 ) ) ;
if ( F_106 ( V_41 ) )
F_179 ( V_65 , 1 << V_41 -> V_91 ) ;
}
}
static void T_4 F_180 ( struct V_40 * V_41 )
{
unsigned long V_92 ;
for ( V_92 = 0 ; V_92 < V_41 -> V_157 ; ++ V_92 ) {
if ( F_106 ( V_41 ) ) {
if ( ! F_168 ( V_41 ) )
break;
} else if ( ! F_143 ( V_41 ,
& V_140 [ V_141 ] ) )
break;
}
V_41 -> V_157 = V_92 ;
}
static void T_4 F_181 ( void )
{
struct V_40 * V_41 ;
F_114 (h) {
if ( ! F_106 ( V_41 ) )
F_180 ( V_41 ) ;
}
}
static char * T_4 F_182 ( char * V_158 , unsigned long V_159 )
{
if ( V_159 >= ( 1UL << 30 ) )
sprintf ( V_158 , L_1 , V_159 >> 30 ) ;
else if ( V_159 >= ( 1UL << 20 ) )
sprintf ( V_158 , L_2 , V_159 >> 20 ) ;
else
sprintf ( V_158 , L_3 , V_159 >> 10 ) ;
return V_158 ;
}
static void T_4 F_183 ( void )
{
struct V_40 * V_41 ;
F_114 (h) {
char V_158 [ 32 ] ;
F_184 ( L_4 ,
F_182 ( V_158 , F_115 ( V_41 ) ) ,
V_41 -> V_69 ) ;
}
}
static void F_185 ( struct V_40 * V_41 , unsigned long V_3 ,
T_3 * V_87 )
{
int V_92 ;
if ( F_106 ( V_41 ) )
return;
F_186 (i, *nodes_allowed) {
struct V_65 * V_65 , * V_37 ;
struct V_21 * V_160 = & V_41 -> V_68 [ V_92 ] ;
F_18 (page, next, freel, lru) {
if ( V_3 >= V_41 -> V_106 )
return;
if ( F_187 ( V_65 ) )
continue;
F_19 ( & V_65 -> V_67 ) ;
F_105 ( V_41 , V_65 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ F_52 ( V_65 ) ] -- ;
}
}
}
static inline void F_185 ( struct V_40 * V_41 , unsigned long V_3 ,
T_3 * V_87 )
{
}
static int F_188 ( struct V_40 * V_41 , T_3 * V_87 ,
int V_9 )
{
int V_104 , V_105 ;
F_45 ( V_9 != - 1 && V_9 != 1 ) ;
if ( V_9 < 0 ) {
F_103 (h, nr_nodes, node, nodes_allowed) {
if ( V_41 -> V_118 [ V_105 ] )
goto V_152;
}
} else {
F_146 (h, nr_nodes, node, nodes_allowed) {
if ( V_41 -> V_118 [ V_105 ] <
V_41 -> V_107 [ V_105 ] )
goto V_152;
}
}
return 0 ;
V_152:
V_41 -> V_119 += V_9 ;
V_41 -> V_118 [ V_105 ] += V_9 ;
return 1 ;
}
static unsigned long F_189 ( struct V_40 * V_41 , unsigned long V_3 ,
T_3 * V_87 )
{
unsigned long V_161 , V_10 ;
if ( F_106 ( V_41 ) && ! F_104 () )
return V_41 -> V_157 ;
F_8 ( & V_117 ) ;
while ( V_41 -> V_119 && V_3 > F_190 ( V_41 ) ) {
if ( ! F_188 ( V_41 , V_87 , - 1 ) )
break;
}
while ( V_3 > F_190 ( V_41 ) ) {
F_2 ( & V_117 ) ;
if ( F_106 ( V_41 ) )
V_10 = F_102 ( V_41 , V_87 ) ;
else
V_10 = F_143 ( V_41 , V_87 ) ;
F_8 ( & V_117 ) ;
if ( ! V_10 )
goto V_35;
if ( F_191 ( V_162 ) )
goto V_35;
}
V_161 = V_41 -> V_84 + V_41 -> V_106 - V_41 -> V_69 ;
V_161 = F_27 ( V_3 , V_161 ) ;
F_185 ( V_41 , V_161 , V_87 ) ;
while ( V_161 < F_190 ( V_41 ) ) {
if ( ! F_145 ( V_41 , V_87 , 0 ) )
break;
F_158 ( & V_117 ) ;
}
while ( V_3 < F_190 ( V_41 ) ) {
if ( ! F_188 ( V_41 , V_87 , 1 ) )
break;
}
V_35:
V_10 = F_190 ( V_41 ) ;
F_2 ( & V_117 ) ;
return V_10 ;
}
static struct V_40 * F_192 ( struct V_163 * V_164 , int * V_165 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_166 ; V_92 ++ )
if ( V_167 [ V_92 ] == V_164 ) {
if ( V_165 )
* V_165 = V_133 ;
return & V_168 [ V_92 ] ;
}
return F_193 ( V_164 , V_165 ) ;
}
static T_5 F_194 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
struct V_40 * V_41 ;
unsigned long V_106 ;
int V_66 ;
V_41 = F_192 ( V_164 , & V_66 ) ;
if ( V_66 == V_133 )
V_106 = V_41 -> V_106 ;
else
V_106 = V_41 -> V_107 [ V_66 ] ;
return sprintf ( V_158 , L_5 , V_106 ) ;
}
static T_5 F_195 ( bool V_171 ,
struct V_163 * V_164 , struct V_169 * V_170 ,
const char * V_158 , T_6 V_172 )
{
int V_85 ;
int V_66 ;
unsigned long V_3 ;
struct V_40 * V_41 ;
F_196 ( T_3 , V_87 , V_7 | V_173 ) ;
V_85 = F_197 ( V_158 , 10 , & V_3 ) ;
if ( V_85 )
goto V_35;
V_41 = F_192 ( V_164 , & V_66 ) ;
if ( F_106 ( V_41 ) && ! F_104 () ) {
V_85 = - V_174 ;
goto V_35;
}
if ( V_66 == V_133 ) {
if ( ! ( V_171 &&
F_198 ( V_87 ) ) ) {
F_199 ( V_87 ) ;
V_87 = & V_140 [ V_141 ] ;
}
} else if ( V_87 ) {
V_3 += V_41 -> V_106 - V_41 -> V_107 [ V_66 ] ;
F_200 ( V_87 , V_66 ) ;
} else
V_87 = & V_140 [ V_141 ] ;
V_41 -> V_157 = F_189 ( V_41 , V_3 , V_87 ) ;
if ( V_87 != & V_140 [ V_141 ] )
F_199 ( V_87 ) ;
return V_172 ;
V_35:
F_199 ( V_87 ) ;
return V_85 ;
}
static T_5 F_201 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
return F_194 ( V_164 , V_170 , V_158 ) ;
}
static T_5 F_202 ( struct V_163 * V_164 ,
struct V_169 * V_170 , const char * V_158 , T_6 V_172 )
{
return F_195 ( false , V_164 , V_170 , V_158 , V_172 ) ;
}
static T_5 F_203 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
return F_194 ( V_164 , V_170 , V_158 ) ;
}
static T_5 F_204 ( struct V_163 * V_164 ,
struct V_169 * V_170 , const char * V_158 , T_6 V_172 )
{
return F_195 ( true , V_164 , V_170 , V_158 , V_172 ) ;
}
static T_5 F_205 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
struct V_40 * V_41 = F_192 ( V_164 , NULL ) ;
return sprintf ( V_158 , L_5 , V_41 -> V_132 ) ;
}
static T_5 F_206 ( struct V_163 * V_164 ,
struct V_169 * V_170 , const char * V_158 , T_6 V_3 )
{
int V_85 ;
unsigned long V_175 ;
struct V_40 * V_41 = F_192 ( V_164 , NULL ) ;
if ( F_106 ( V_41 ) )
return - V_174 ;
V_85 = F_197 ( V_158 , 10 , & V_175 ) ;
if ( V_85 )
return V_85 ;
F_8 ( & V_117 ) ;
V_41 -> V_132 = V_175 ;
F_2 ( & V_117 ) ;
return V_3 ;
}
static T_5 F_207 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
struct V_40 * V_41 ;
unsigned long V_69 ;
int V_66 ;
V_41 = F_192 ( V_164 , & V_66 ) ;
if ( V_66 == V_133 )
V_69 = V_41 -> V_69 ;
else
V_69 = V_41 -> V_70 [ V_66 ] ;
return sprintf ( V_158 , L_5 , V_69 ) ;
}
static T_5 F_208 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
struct V_40 * V_41 = F_192 ( V_164 , NULL ) ;
return sprintf ( V_158 , L_5 , V_41 -> V_84 ) ;
}
static T_5 F_209 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
struct V_40 * V_41 ;
unsigned long V_119 ;
int V_66 ;
V_41 = F_192 ( V_164 , & V_66 ) ;
if ( V_66 == V_133 )
V_119 = V_41 -> V_119 ;
else
V_119 = V_41 -> V_118 [ V_66 ] ;
return sprintf ( V_158 , L_5 , V_119 ) ;
}
static int F_210 ( struct V_40 * V_41 , struct V_163 * V_176 ,
struct V_163 * * V_167 ,
struct V_177 * V_178 )
{
int V_179 ;
int V_180 = F_124 ( V_41 ) ;
V_167 [ V_180 ] = F_211 ( V_41 -> V_181 , V_176 ) ;
if ( ! V_167 [ V_180 ] )
return - V_11 ;
V_179 = F_212 ( V_167 [ V_180 ] , V_178 ) ;
if ( V_179 )
F_213 ( V_167 [ V_180 ] ) ;
return V_179 ;
}
static void T_4 F_214 ( void )
{
struct V_40 * V_41 ;
int V_85 ;
V_182 = F_211 ( L_6 , V_183 ) ;
if ( ! V_182 )
return;
F_114 (h) {
V_85 = F_210 ( V_41 , V_182 ,
V_167 , & V_178 ) ;
if ( V_85 )
F_215 ( L_7 , V_41 -> V_181 ) ;
}
}
static struct V_40 * F_193 ( struct V_163 * V_164 , int * V_165 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_184 ; V_66 ++ ) {
struct V_185 * V_186 = & V_187 [ V_66 ] ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_166 ; V_92 ++ )
if ( V_186 -> V_167 [ V_92 ] == V_164 ) {
if ( V_165 )
* V_165 = V_66 ;
return & V_168 [ V_92 ] ;
}
}
F_216 () ;
return NULL ;
}
static void F_217 ( struct V_105 * V_105 )
{
struct V_40 * V_41 ;
struct V_185 * V_186 = & V_187 [ V_105 -> V_188 . V_189 ] ;
if ( ! V_186 -> V_182 )
return;
F_114 (h) {
int V_143 = F_124 ( V_41 ) ;
if ( V_186 -> V_167 [ V_143 ] ) {
F_213 ( V_186 -> V_167 [ V_143 ] ) ;
V_186 -> V_167 [ V_143 ] = NULL ;
}
}
F_213 ( V_186 -> V_182 ) ;
V_186 -> V_182 = NULL ;
}
static void F_218 ( void )
{
int V_66 ;
F_219 ( NULL , NULL ) ;
for ( V_66 = 0 ; V_66 < V_184 ; V_66 ++ )
F_217 ( V_190 [ V_66 ] ) ;
}
static void F_220 ( struct V_105 * V_105 )
{
struct V_40 * V_41 ;
struct V_185 * V_186 = & V_187 [ V_105 -> V_188 . V_189 ] ;
int V_85 ;
if ( V_186 -> V_182 )
return;
V_186 -> V_182 = F_211 ( L_6 ,
& V_105 -> V_188 . V_164 ) ;
if ( ! V_186 -> V_182 )
return;
F_114 (h) {
V_85 = F_210 ( V_41 , V_186 -> V_182 ,
V_186 -> V_167 ,
& V_191 ) ;
if ( V_85 ) {
F_215 ( L_8 ,
V_41 -> V_181 , V_105 -> V_188 . V_189 ) ;
F_217 ( V_105 ) ;
break;
}
}
}
static void F_221 ( void )
{
int V_66 ;
F_222 (nid, N_MEMORY) {
struct V_105 * V_105 = V_190 [ V_66 ] ;
if ( V_105 -> V_188 . V_189 == V_66 )
F_220 ( V_105 ) ;
}
F_219 ( F_220 ,
F_217 ) ;
}
static struct V_40 * F_193 ( struct V_163 * V_164 , int * V_165 )
{
F_216 () ;
if ( V_165 )
* V_165 = - 1 ;
return NULL ;
}
static void F_218 ( void ) { }
static void F_221 ( void ) { }
static void T_7 F_223 ( void )
{
struct V_40 * V_41 ;
F_218 () ;
F_114 (h) {
F_213 ( V_167 [ F_124 ( V_41 ) ] ) ;
}
F_213 ( V_182 ) ;
F_3 ( V_192 ) ;
}
static int T_4 F_224 ( void )
{
int V_92 ;
if ( ! F_225 () )
return 0 ;
if ( ! F_113 ( V_193 ) ) {
V_193 = V_194 ;
if ( ! F_113 ( V_193 ) )
F_226 ( V_195 ) ;
}
V_196 = F_124 ( F_113 ( V_193 ) ) ;
if ( V_197 )
V_198 . V_157 = V_197 ;
F_181 () ;
F_173 () ;
F_183 () ;
F_214 () ;
F_221 () ;
F_227 () ;
#ifdef F_228
V_199 = F_229 ( 8 * F_230 () ) ;
#else
V_199 = 1 ;
#endif
V_192 =
F_5 ( sizeof( struct V_200 ) * V_199 , V_7 ) ;
F_9 ( ! V_192 ) ;
for ( V_92 = 0 ; V_92 < V_199 ; V_92 ++ )
F_231 ( & V_192 [ V_92 ] ) ;
return 0 ;
}
void T_4 F_226 ( unsigned V_91 )
{
struct V_40 * V_41 ;
unsigned long V_92 ;
if ( F_113 ( V_45 << V_91 ) ) {
F_232 ( L_9 ) ;
return;
}
F_9 ( V_201 >= V_166 ) ;
F_9 ( V_91 == 0 ) ;
V_41 = & V_168 [ V_201 ++ ] ;
V_41 -> V_91 = V_91 ;
V_41 -> V_202 = ~ ( ( 1ULL << ( V_91 + V_156 ) ) - 1 ) ;
V_41 -> V_106 = 0 ;
V_41 -> V_69 = 0 ;
for ( V_92 = 0 ; V_92 < V_88 ; ++ V_92 )
F_21 ( & V_41 -> V_68 [ V_92 ] ) ;
F_21 ( & V_41 -> V_71 ) ;
V_41 -> V_89 = F_71 ( V_140 [ V_141 ] ) ;
V_41 -> V_90 = F_71 ( V_140 [ V_141 ] ) ;
snprintf ( V_41 -> V_181 , V_203 , L_10 ,
F_115 ( V_41 ) / 1024 ) ;
V_204 = V_41 ;
}
static int T_4 F_233 ( char * V_205 )
{
unsigned long * V_206 ;
static unsigned long * V_207 ;
if ( ! V_201 )
V_206 = & V_197 ;
else
V_206 = & V_204 -> V_157 ;
if ( V_206 == V_207 ) {
F_232 ( L_11
L_12 ) ;
return 1 ;
}
if ( sscanf ( V_205 , L_13 , V_206 ) <= 0 )
* V_206 = 0 ;
if ( V_201 && V_204 -> V_91 >= V_123 )
F_180 ( V_204 ) ;
V_207 = V_206 ;
return 1 ;
}
static int T_4 F_234 ( char * V_205 )
{
V_193 = F_235 ( V_205 , & V_205 ) ;
return 1 ;
}
static unsigned int F_236 ( unsigned int * V_208 )
{
int V_105 ;
unsigned int V_209 = 0 ;
F_186 (node, cpuset_current_mems_allowed)
V_209 += V_208 [ V_105 ] ;
return V_209 ;
}
static int F_237 ( bool V_171 ,
struct V_210 * V_211 , int V_212 ,
void T_8 * V_213 , T_6 * V_214 , T_9 * V_215 )
{
struct V_40 * V_41 = & V_198 ;
unsigned long V_135 ;
int V_10 ;
if ( ! F_225 () )
return - V_216 ;
V_135 = V_41 -> V_157 ;
if ( V_212 && F_106 ( V_41 ) && ! F_104 () )
return - V_174 ;
V_211 -> V_217 = & V_135 ;
V_211 -> V_218 = sizeof( unsigned long ) ;
V_10 = F_238 ( V_211 , V_212 , V_213 , V_214 , V_215 ) ;
if ( V_10 )
goto V_35;
if ( V_212 ) {
F_196 ( T_3 , V_87 ,
V_7 | V_173 ) ;
if ( ! ( V_171 &&
F_198 ( V_87 ) ) ) {
F_199 ( V_87 ) ;
V_87 = & V_140 [ V_141 ] ;
}
V_41 -> V_157 = F_189 ( V_41 , V_135 , V_87 ) ;
if ( V_87 != & V_140 [ V_141 ] )
F_199 ( V_87 ) ;
}
V_35:
return V_10 ;
}
int F_239 ( struct V_210 * V_211 , int V_212 ,
void T_8 * V_213 , T_6 * V_214 , T_9 * V_215 )
{
return F_237 ( false , V_211 , V_212 ,
V_213 , V_214 , V_215 ) ;
}
int F_240 ( struct V_210 * V_211 , int V_212 ,
void T_8 * V_213 , T_6 * V_214 , T_9 * V_215 )
{
return F_237 ( true , V_211 , V_212 ,
V_213 , V_214 , V_215 ) ;
}
int F_241 ( struct V_210 * V_211 , int V_212 ,
void T_8 * V_213 ,
T_6 * V_214 , T_9 * V_215 )
{
struct V_40 * V_41 = & V_198 ;
unsigned long V_135 ;
int V_10 ;
if ( ! F_225 () )
return - V_216 ;
V_135 = V_41 -> V_132 ;
if ( V_212 && F_106 ( V_41 ) )
return - V_174 ;
V_211 -> V_217 = & V_135 ;
V_211 -> V_218 = sizeof( unsigned long ) ;
V_10 = F_238 ( V_211 , V_212 , V_213 , V_214 , V_215 ) ;
if ( V_10 )
goto V_35;
if ( V_212 ) {
F_8 ( & V_117 ) ;
V_41 -> V_132 = V_135 ;
F_2 ( & V_117 ) ;
}
V_35:
return V_10 ;
}
void F_242 ( struct V_219 * V_150 )
{
struct V_40 * V_41 = & V_198 ;
if ( ! F_225 () )
return;
F_243 ( V_150 ,
L_14
L_15
L_16
L_17
L_18 ,
V_41 -> V_106 ,
V_41 -> V_69 ,
V_41 -> V_84 ,
V_41 -> V_119 ,
1UL << ( F_31 ( V_41 ) + V_156 - 10 ) ) ;
}
int F_244 ( int V_66 , char * V_158 )
{
struct V_40 * V_41 = & V_198 ;
if ( ! F_225 () )
return 0 ;
return sprintf ( V_158 ,
L_19
L_20
L_21 ,
V_66 , V_41 -> V_107 [ V_66 ] ,
V_66 , V_41 -> V_70 [ V_66 ] ,
V_66 , V_41 -> V_118 [ V_66 ] ) ;
}
void F_245 ( void )
{
struct V_40 * V_41 ;
int V_66 ;
if ( ! F_225 () )
return;
F_222 (nid, N_MEMORY)
F_114 (h)
F_184 ( L_22 ,
V_66 ,
V_41 -> V_107 [ V_66 ] ,
V_41 -> V_70 [ V_66 ] ,
V_41 -> V_118 [ V_66 ] ,
1UL << ( F_31 ( V_41 ) + V_156 - 10 ) ) ;
}
unsigned long F_246 ( void )
{
struct V_40 * V_41 ;
unsigned long V_220 = 0 ;
F_114 (h)
V_220 += V_41 -> V_106 * F_107 ( V_41 ) ;
return V_220 ;
}
static int F_247 ( struct V_40 * V_41 , long V_9 )
{
int V_10 = - V_11 ;
F_8 ( & V_117 ) ;
if ( V_9 > 0 ) {
if ( F_155 ( V_41 , V_9 ) < 0 )
goto V_35;
if ( V_9 > F_236 ( V_41 -> V_70 ) ) {
F_157 ( V_41 , V_9 ) ;
goto V_35;
}
}
V_10 = 0 ;
if ( V_9 < 0 )
F_157 ( V_41 , ( unsigned long ) - V_9 ) ;
V_35:
F_2 ( & V_117 ) ;
return V_10 ;
}
static void F_248 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_44 ( V_15 ) ;
if ( V_18 && F_48 ( V_15 , V_64 ) )
F_249 ( & V_18 -> V_48 ) ;
}
static void F_250 ( struct V_14 * V_15 )
{
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_17 * V_18 = F_44 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_15 ) ;
unsigned long V_221 , V_222 , V_36 ;
if ( ! V_18 || ! F_48 ( V_15 , V_64 ) )
return;
V_222 = F_29 ( V_41 , V_15 , V_15 -> V_43 ) ;
V_36 = F_29 ( V_41 , V_15 , V_15 -> V_223 ) ;
V_221 = ( V_36 - V_222 ) - F_26 ( V_18 , V_222 , V_36 ) ;
F_251 ( & V_18 -> V_48 , F_41 ) ;
if ( V_221 ) {
F_247 ( V_41 , - V_221 ) ;
F_11 ( V_2 , V_221 ) ;
}
}
static int F_252 ( struct V_14 * V_15 , struct V_224 * V_225 )
{
F_216 () ;
return 0 ;
}
static T_10 F_253 ( struct V_14 * V_15 , struct V_65 * V_65 ,
int V_226 )
{
T_10 V_227 ;
if ( V_226 ) {
V_227 = F_254 ( F_255 ( F_256 ( V_65 ,
V_15 -> V_228 ) ) ) ;
} else {
V_227 = F_257 ( F_256 ( V_65 ,
V_15 -> V_228 ) ) ;
}
V_227 = F_258 ( V_227 ) ;
V_227 = F_259 ( V_227 ) ;
V_227 = F_260 ( V_227 , V_15 , V_65 , V_226 ) ;
return V_227 ;
}
static void F_261 ( struct V_14 * V_15 ,
unsigned long V_42 , T_10 * V_229 )
{
T_10 V_227 ;
V_227 = F_254 ( F_255 ( F_262 ( V_229 ) ) ) ;
if ( F_263 ( V_15 , V_42 , V_229 , V_227 , 1 ) )
F_264 ( V_15 , V_42 , V_229 ) ;
}
static int F_265 ( T_10 V_230 )
{
T_11 V_231 ;
if ( F_266 ( V_230 ) || F_267 ( V_230 ) )
return 0 ;
V_231 = F_268 ( V_230 ) ;
if ( F_269 ( V_231 ) && F_270 ( V_231 ) )
return 1 ;
else
return 0 ;
}
static int F_271 ( T_10 V_230 )
{
T_11 V_231 ;
if ( F_266 ( V_230 ) || F_267 ( V_230 ) )
return 0 ;
V_231 = F_268 ( V_230 ) ;
if ( F_269 ( V_231 ) && F_272 ( V_231 ) )
return 1 ;
else
return 0 ;
}
int F_273 ( struct V_232 * V_233 , struct V_232 * V_234 ,
struct V_14 * V_15 )
{
T_10 * V_235 , * V_236 , V_227 ;
struct V_65 * V_237 ;
unsigned long V_142 ;
int V_238 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
unsigned long V_239 = F_115 ( V_41 ) ;
unsigned long V_240 ;
unsigned long V_241 ;
int V_10 = 0 ;
V_238 = ( V_15 -> V_53 & ( V_242 | V_243 ) ) == V_243 ;
V_240 = V_15 -> V_43 ;
V_241 = V_15 -> V_223 ;
if ( V_238 )
F_274 ( V_234 , V_240 , V_241 ) ;
for ( V_142 = V_15 -> V_43 ; V_142 < V_15 -> V_223 ; V_142 += V_239 ) {
T_12 * V_244 , * V_245 ;
V_235 = F_275 ( V_234 , V_142 ) ;
if ( ! V_235 )
continue;
V_236 = F_276 ( V_233 , V_142 , V_239 ) ;
if ( ! V_236 ) {
V_10 = - V_11 ;
break;
}
if ( V_236 == V_235 )
continue;
V_245 = F_277 ( V_41 , V_233 , V_236 ) ;
V_244 = F_278 ( V_41 , V_234 , V_235 ) ;
F_279 ( V_244 , V_246 ) ;
V_227 = F_262 ( V_235 ) ;
if ( F_266 ( V_227 ) ) {
;
} else if ( F_67 ( F_265 ( V_227 ) ||
F_271 ( V_227 ) ) ) {
T_11 V_247 = F_268 ( V_227 ) ;
if ( F_280 ( V_247 ) && V_238 ) {
F_281 ( & V_247 ) ;
V_227 = F_282 ( V_247 ) ;
F_283 ( V_234 , V_142 , V_235 , V_227 ) ;
}
F_283 ( V_233 , V_142 , V_236 , V_227 ) ;
} else {
if ( V_238 )
F_284 ( V_234 , V_142 , V_235 ) ;
V_227 = F_262 ( V_235 ) ;
V_237 = F_285 ( V_227 ) ;
F_286 ( V_237 ) ;
F_287 ( V_237 ) ;
F_283 ( V_233 , V_142 , V_236 , V_227 ) ;
}
F_2 ( V_244 ) ;
F_2 ( V_245 ) ;
}
if ( V_238 )
F_288 ( V_234 , V_240 , V_241 ) ;
return V_10 ;
}
void F_289 ( struct V_248 * V_249 , struct V_14 * V_15 ,
unsigned long V_222 , unsigned long V_36 ,
struct V_65 * V_250 )
{
int V_251 = 0 ;
struct V_232 * V_252 = V_15 -> V_253 ;
unsigned long V_42 ;
T_10 * V_229 ;
T_10 V_230 ;
T_12 * V_254 ;
struct V_65 * V_65 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
unsigned long V_239 = F_115 ( V_41 ) ;
const unsigned long V_240 = V_222 ;
const unsigned long V_241 = V_36 ;
F_178 ( ! F_35 ( V_15 ) ) ;
F_9 ( V_222 & ~ F_290 ( V_41 ) ) ;
F_9 ( V_36 & ~ F_290 ( V_41 ) ) ;
F_291 ( V_249 , V_15 ) ;
F_274 ( V_252 , V_240 , V_241 ) ;
V_255:
for ( V_42 = V_222 ; V_42 < V_36 ; V_42 += V_239 ) {
V_229 = F_275 ( V_252 , V_42 ) ;
if ( ! V_229 )
continue;
V_254 = F_277 ( V_41 , V_252 , V_229 ) ;
if ( F_292 ( V_252 , & V_42 , V_229 ) )
goto V_256;
V_230 = F_262 ( V_229 ) ;
if ( F_266 ( V_230 ) )
goto V_256;
if ( F_67 ( F_271 ( V_230 ) ) ) {
F_293 ( V_252 , V_42 , V_229 ) ;
goto V_256;
}
V_65 = F_285 ( V_230 ) ;
if ( V_250 ) {
if ( V_65 != V_250 )
goto V_256;
F_47 ( V_15 , V_257 ) ;
}
V_230 = F_294 ( V_252 , V_42 , V_229 ) ;
F_295 ( V_249 , V_229 , V_42 ) ;
if ( F_296 ( V_230 ) )
F_297 ( V_65 ) ;
F_298 ( V_65 ) ;
V_251 = ! F_299 ( V_249 , V_65 ) ;
if ( V_251 ) {
F_2 ( V_254 ) ;
break;
}
if ( V_250 ) {
F_2 ( V_254 ) ;
break;
}
V_256:
F_2 ( V_254 ) ;
}
if ( V_251 ) {
V_251 = 0 ;
F_300 ( V_249 ) ;
if ( V_42 < V_36 && ! V_250 )
goto V_255;
}
F_288 ( V_252 , V_240 , V_241 ) ;
F_301 ( V_249 , V_15 ) ;
}
void F_302 ( struct V_248 * V_249 ,
struct V_14 * V_15 , unsigned long V_222 ,
unsigned long V_36 , struct V_65 * V_250 )
{
F_289 ( V_249 , V_15 , V_222 , V_36 , V_250 ) ;
V_15 -> V_53 &= ~ V_54 ;
}
void F_303 ( struct V_14 * V_15 , unsigned long V_222 ,
unsigned long V_36 , struct V_65 * V_250 )
{
struct V_232 * V_252 ;
struct V_248 V_249 ;
V_252 = V_15 -> V_253 ;
F_304 ( & V_249 , V_252 , V_222 , V_36 ) ;
F_289 ( & V_249 , V_15 , V_222 , V_36 , V_250 ) ;
F_305 ( & V_249 , V_222 , V_36 ) ;
}
static int F_306 ( struct V_232 * V_252 , struct V_14 * V_15 ,
struct V_65 * V_65 , unsigned long V_42 )
{
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_14 * V_258 ;
struct V_55 * V_56 ;
T_1 V_259 ;
V_42 = V_42 & F_290 ( V_41 ) ;
V_259 = ( ( V_42 - V_15 -> V_43 ) >> V_156 ) +
V_15 -> V_44 ;
V_56 = F_15 ( V_15 -> V_16 ) -> V_51 ;
F_307 ( & V_56 -> V_260 ) ;
F_308 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_258 == V_15 )
continue;
if ( ! F_48 ( V_258 , V_64 ) )
F_303 ( V_258 , V_42 ,
V_42 + F_115 ( V_41 ) , V_65 ) ;
}
F_309 ( & V_56 -> V_260 ) ;
return 1 ;
}
static int F_310 ( struct V_232 * V_252 , struct V_14 * V_15 ,
unsigned long V_42 , T_10 * V_229 , T_10 V_230 ,
struct V_65 * V_261 , T_12 * V_254 )
{
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_65 * V_262 , * V_263 ;
int V_264 = 0 ;
unsigned long V_240 ;
unsigned long V_241 ;
V_262 = F_285 ( V_230 ) ;
V_265:
if ( F_120 ( V_262 ) == 1 && F_311 ( V_262 ) ) {
F_312 ( V_262 , V_15 , V_42 ) ;
F_261 ( V_15 , V_42 , V_229 ) ;
return 0 ;
}
if ( F_48 ( V_15 , V_64 ) &&
V_262 != V_261 )
V_264 = 1 ;
F_313 ( V_262 ) ;
F_2 ( V_254 ) ;
V_263 = F_161 ( V_15 , V_42 , V_264 ) ;
if ( F_167 ( V_263 ) ) {
long V_85 = F_314 ( V_263 ) ;
F_315 ( V_262 ) ;
if ( V_264 ) {
F_9 ( F_266 ( V_230 ) ) ;
if ( F_306 ( V_252 , V_15 , V_262 , V_42 ) ) {
F_9 ( F_266 ( V_230 ) ) ;
F_8 ( V_254 ) ;
V_229 = F_275 ( V_252 , V_42 & F_290 ( V_41 ) ) ;
if ( F_316 ( V_229 &&
F_317 ( F_262 ( V_229 ) , V_230 ) ) )
goto V_265;
return 0 ;
}
F_318 ( 1 ) ;
}
F_8 ( V_254 ) ;
if ( V_85 == - V_11 )
return V_266 ;
else
return V_267 ;
}
if ( F_67 ( F_319 ( V_15 ) ) ) {
F_315 ( V_263 ) ;
F_315 ( V_262 ) ;
F_8 ( V_254 ) ;
return V_266 ;
}
F_320 ( V_263 , V_262 , V_42 , V_15 ,
F_107 ( V_41 ) ) ;
F_321 ( V_263 ) ;
V_240 = V_42 & F_290 ( V_41 ) ;
V_241 = V_240 + F_115 ( V_41 ) ;
F_274 ( V_252 , V_240 , V_241 ) ;
F_8 ( V_254 ) ;
V_229 = F_275 ( V_252 , V_42 & F_290 ( V_41 ) ) ;
if ( F_316 ( V_229 && F_317 ( F_262 ( V_229 ) , V_230 ) ) ) {
F_122 ( V_263 ) ;
F_322 ( V_15 , V_42 , V_229 ) ;
F_283 ( V_252 , V_42 , V_229 ,
F_253 ( V_15 , V_263 , 1 ) ) ;
F_298 ( V_262 ) ;
F_323 ( V_263 , V_15 , V_42 ) ;
V_263 = V_262 ;
}
F_2 ( V_254 ) ;
F_288 ( V_252 , V_240 , V_241 ) ;
F_315 ( V_263 ) ;
F_315 ( V_262 ) ;
F_8 ( V_254 ) ;
return 0 ;
}
static struct V_65 * F_324 ( struct V_40 * V_41 ,
struct V_14 * V_15 , unsigned long V_42 )
{
struct V_55 * V_56 ;
T_1 V_143 ;
V_56 = V_15 -> V_16 -> V_57 ;
V_143 = F_29 ( V_41 , V_15 , V_42 ) ;
return F_325 ( V_56 , V_143 ) ;
}
static bool F_326 ( struct V_40 * V_41 ,
struct V_14 * V_15 , unsigned long V_42 )
{
struct V_55 * V_56 ;
T_1 V_143 ;
struct V_65 * V_65 ;
V_56 = V_15 -> V_16 -> V_57 ;
V_143 = F_29 ( V_41 , V_15 , V_42 ) ;
V_65 = F_327 ( V_56 , V_143 ) ;
if ( V_65 )
F_127 ( V_65 ) ;
return V_65 != NULL ;
}
static int F_328 ( struct V_232 * V_252 , struct V_14 * V_15 ,
struct V_55 * V_56 , T_1 V_143 ,
unsigned long V_42 , T_10 * V_229 , unsigned int V_61 )
{
struct V_40 * V_41 = F_33 ( V_15 ) ;
int V_10 = V_267 ;
int V_268 = 0 ;
unsigned long V_115 ;
struct V_65 * V_65 ;
T_10 V_269 ;
T_12 * V_254 ;
if ( F_48 ( V_15 , V_257 ) ) {
F_232 ( L_23 ,
V_162 -> V_270 ) ;
return V_10 ;
}
V_32:
V_65 = F_325 ( V_56 , V_143 ) ;
if ( ! V_65 ) {
V_115 = F_329 ( V_56 -> V_58 ) >> F_30 ( V_41 ) ;
if ( V_143 >= V_115 )
goto V_35;
V_65 = F_161 ( V_15 , V_42 , 0 ) ;
if ( F_167 ( V_65 ) ) {
V_10 = F_314 ( V_65 ) ;
if ( V_10 == - V_11 )
V_10 = V_266 ;
else
V_10 = V_267 ;
goto V_35;
}
F_330 ( V_65 , V_42 , F_107 ( V_41 ) ) ;
F_321 ( V_65 ) ;
if ( V_15 -> V_53 & V_54 ) {
int V_85 ;
struct V_12 * V_12 = V_56 -> V_58 ;
V_85 = F_331 ( V_65 , V_56 , V_143 , V_7 ) ;
if ( V_85 ) {
F_127 ( V_65 ) ;
if ( V_85 == - V_271 )
goto V_32;
goto V_35;
}
F_122 ( V_65 ) ;
F_8 ( & V_12 -> V_272 ) ;
V_12 -> V_273 += F_332 ( V_41 ) ;
F_2 ( & V_12 -> V_272 ) ;
} else {
F_333 ( V_65 ) ;
if ( F_67 ( F_319 ( V_15 ) ) ) {
V_10 = V_266 ;
goto V_274;
}
V_268 = 1 ;
}
} else {
if ( F_67 ( F_334 ( V_65 ) ) ) {
V_10 = V_275 |
F_335 ( F_124 ( V_41 ) ) ;
goto V_274;
}
}
if ( ( V_61 & V_276 ) && ! ( V_15 -> V_53 & V_242 ) )
if ( F_159 ( V_41 , V_15 , V_42 ) < 0 ) {
V_10 = V_266 ;
goto V_274;
}
V_254 = F_278 ( V_41 , V_252 , V_229 ) ;
F_8 ( V_254 ) ;
V_115 = F_329 ( V_56 -> V_58 ) >> F_30 ( V_41 ) ;
if ( V_143 >= V_115 )
goto V_277;
V_10 = 0 ;
if ( ! F_266 ( F_262 ( V_229 ) ) )
goto V_277;
if ( V_268 ) {
F_122 ( V_65 ) ;
F_323 ( V_65 , V_15 , V_42 ) ;
} else
F_287 ( V_65 ) ;
V_269 = F_253 ( V_15 , V_65 , ( ( V_15 -> V_53 & V_278 )
&& ( V_15 -> V_53 & V_242 ) ) ) ;
F_283 ( V_252 , V_42 , V_229 , V_269 ) ;
if ( ( V_61 & V_276 ) && ! ( V_15 -> V_53 & V_242 ) ) {
V_10 = F_310 ( V_252 , V_15 , V_42 , V_229 , V_269 , V_65 , V_254 ) ;
}
F_2 ( V_254 ) ;
F_336 ( V_65 ) ;
V_35:
return V_10 ;
V_277:
F_2 ( V_254 ) ;
V_274:
F_336 ( V_65 ) ;
F_127 ( V_65 ) ;
goto V_35;
}
static T_13 F_337 ( struct V_40 * V_41 , struct V_232 * V_252 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
T_1 V_143 , unsigned long V_42 )
{
unsigned long V_279 [ 2 ] ;
T_13 V_280 ;
if ( V_15 -> V_53 & V_242 ) {
V_279 [ 0 ] = ( unsigned long ) V_56 ;
V_279 [ 1 ] = V_143 ;
} else {
V_279 [ 0 ] = ( unsigned long ) V_252 ;
V_279 [ 1 ] = V_42 >> F_30 ( V_41 ) ;
}
V_280 = F_338 ( ( T_13 * ) & V_279 , sizeof( V_279 ) / sizeof( T_13 ) , 0 ) ;
return V_280 & ( V_199 - 1 ) ;
}
static T_13 F_337 ( struct V_40 * V_41 , struct V_232 * V_252 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
T_1 V_143 , unsigned long V_42 )
{
return 0 ;
}
int F_339 ( struct V_232 * V_252 , struct V_14 * V_15 ,
unsigned long V_42 , unsigned int V_61 )
{
T_10 * V_229 , V_227 ;
T_12 * V_254 ;
int V_10 ;
T_13 V_280 ;
T_1 V_143 ;
struct V_65 * V_65 = NULL ;
struct V_65 * V_261 = NULL ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_55 * V_56 ;
V_42 &= F_290 ( V_41 ) ;
V_229 = F_275 ( V_252 , V_42 ) ;
if ( V_229 ) {
V_227 = F_262 ( V_229 ) ;
if ( F_67 ( F_265 ( V_227 ) ) ) {
F_340 ( V_15 , V_252 , V_229 ) ;
return 0 ;
} else if ( F_67 ( F_271 ( V_227 ) ) )
return V_281 |
F_335 ( F_124 ( V_41 ) ) ;
}
V_229 = F_276 ( V_252 , V_42 , F_115 ( V_41 ) ) ;
if ( ! V_229 )
return V_266 ;
V_56 = V_15 -> V_16 -> V_57 ;
V_143 = F_29 ( V_41 , V_15 , V_42 ) ;
V_280 = F_337 ( V_41 , V_252 , V_15 , V_56 , V_143 , V_42 ) ;
F_307 ( & V_192 [ V_280 ] ) ;
V_227 = F_262 ( V_229 ) ;
if ( F_266 ( V_227 ) ) {
V_10 = F_328 ( V_252 , V_15 , V_56 , V_143 , V_42 , V_229 , V_61 ) ;
goto V_282;
}
V_10 = 0 ;
if ( ( V_61 & V_276 ) && ! F_341 ( V_227 ) ) {
if ( F_159 ( V_41 , V_15 , V_42 ) < 0 ) {
V_10 = V_266 ;
goto V_282;
}
if ( ! ( V_15 -> V_53 & V_54 ) )
V_261 = F_324 ( V_41 ,
V_15 , V_42 ) ;
}
V_65 = F_285 ( V_227 ) ;
F_286 ( V_65 ) ;
if ( V_65 != V_261 )
F_333 ( V_65 ) ;
V_254 = F_278 ( V_41 , V_252 , V_229 ) ;
F_8 ( V_254 ) ;
if ( F_67 ( ! F_317 ( V_227 , F_262 ( V_229 ) ) ) )
goto V_283;
if ( V_61 & V_276 ) {
if ( ! F_341 ( V_227 ) ) {
V_10 = F_310 ( V_252 , V_15 , V_42 , V_229 , V_227 ,
V_261 , V_254 ) ;
goto V_283;
}
V_227 = F_255 ( V_227 ) ;
}
V_227 = F_258 ( V_227 ) ;
if ( F_263 ( V_15 , V_42 , V_229 , V_227 ,
V_61 & V_276 ) )
F_264 ( V_15 , V_42 , V_229 ) ;
V_283:
F_2 ( V_254 ) ;
if ( V_261 ) {
F_336 ( V_261 ) ;
F_127 ( V_261 ) ;
}
if ( V_65 != V_261 )
F_336 ( V_65 ) ;
F_127 ( V_65 ) ;
V_282:
F_309 ( & V_192 [ V_280 ] ) ;
return V_10 ;
}
long F_342 ( struct V_232 * V_252 , struct V_14 * V_15 ,
struct V_65 * * V_284 , struct V_14 * * V_285 ,
unsigned long * V_286 , unsigned long * V_93 ,
long V_92 , unsigned int V_61 )
{
unsigned long V_287 ;
unsigned long V_288 = * V_286 ;
unsigned long V_289 = * V_93 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
while ( V_288 < V_15 -> V_223 && V_289 ) {
T_10 * V_230 ;
T_12 * V_254 = NULL ;
int V_290 ;
struct V_65 * V_65 ;
V_230 = F_275 ( V_252 , V_288 & F_290 ( V_41 ) ) ;
if ( V_230 )
V_254 = F_277 ( V_41 , V_252 , V_230 ) ;
V_290 = ! V_230 || F_266 ( F_262 ( V_230 ) ) ;
if ( V_290 && ( V_61 & V_291 ) &&
! F_326 ( V_41 , V_15 , V_288 ) ) {
if ( V_230 )
F_2 ( V_254 ) ;
V_289 = 0 ;
break;
}
if ( V_290 || F_343 ( F_262 ( V_230 ) ) ||
( ( V_61 & V_292 ) &&
! F_341 ( F_262 ( V_230 ) ) ) ) {
int V_10 ;
if ( V_230 )
F_2 ( V_254 ) ;
V_10 = F_339 ( V_252 , V_15 , V_288 ,
( V_61 & V_292 ) ? V_276 : 0 ) ;
if ( ! ( V_10 & V_293 ) )
continue;
V_289 = 0 ;
break;
}
V_287 = ( V_288 & ~ F_290 ( V_41 ) ) >> V_156 ;
V_65 = F_285 ( F_262 ( V_230 ) ) ;
V_294:
if ( V_284 ) {
V_284 [ V_92 ] = F_344 ( V_65 , V_287 ) ;
F_345 ( V_284 [ V_92 ] ) ;
}
if ( V_285 )
V_285 [ V_92 ] = V_15 ;
V_288 += V_45 ;
++ V_287 ;
-- V_289 ;
++ V_92 ;
if ( V_288 < V_15 -> V_223 && V_289 &&
V_287 < F_107 ( V_41 ) ) {
goto V_294;
}
F_2 ( V_254 ) ;
}
* V_93 = V_289 ;
* V_286 = V_288 ;
return V_92 ? V_92 : - V_295 ;
}
unsigned long F_346 ( struct V_14 * V_15 ,
unsigned long V_42 , unsigned long V_36 , T_14 V_296 )
{
struct V_232 * V_252 = V_15 -> V_253 ;
unsigned long V_222 = V_42 ;
T_10 * V_229 ;
T_10 V_230 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
unsigned long V_284 = 0 ;
F_9 ( V_42 >= V_36 ) ;
F_347 ( V_15 , V_42 , V_36 ) ;
F_274 ( V_252 , V_222 , V_36 ) ;
F_307 ( & V_15 -> V_16 -> V_57 -> V_260 ) ;
for (; V_42 < V_36 ; V_42 += F_115 ( V_41 ) ) {
T_12 * V_254 ;
V_229 = F_275 ( V_252 , V_42 ) ;
if ( ! V_229 )
continue;
V_254 = F_277 ( V_41 , V_252 , V_229 ) ;
if ( F_292 ( V_252 , & V_42 , V_229 ) ) {
V_284 ++ ;
F_2 ( V_254 ) ;
continue;
}
if ( ! F_266 ( F_262 ( V_229 ) ) ) {
V_230 = F_294 ( V_252 , V_42 , V_229 ) ;
V_230 = F_259 ( F_348 ( V_230 , V_296 ) ) ;
V_230 = F_260 ( V_230 , V_15 , NULL , 0 ) ;
F_283 ( V_252 , V_42 , V_229 , V_230 ) ;
V_284 ++ ;
}
F_2 ( V_254 ) ;
}
F_349 ( V_15 , V_222 , V_36 ) ;
F_309 ( & V_15 -> V_16 -> V_57 -> V_260 ) ;
F_288 ( V_252 , V_222 , V_36 ) ;
return V_284 << V_41 -> V_91 ;
}
int F_350 ( struct V_12 * V_12 ,
long V_29 , long V_28 ,
struct V_14 * V_15 ,
T_15 V_53 )
{
long V_10 , V_31 ;
struct V_40 * V_41 = F_351 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
struct V_17 * V_17 ;
if ( V_53 & V_63 )
return 0 ;
if ( ! V_15 || V_15 -> V_53 & V_54 ) {
V_17 = F_43 ( V_12 ) ;
V_31 = F_20 ( V_17 , V_29 , V_28 ) ;
} else {
V_17 = F_39 () ;
if ( ! V_17 )
return - V_11 ;
V_31 = V_28 - V_29 ;
F_46 ( V_15 , V_17 ) ;
F_47 ( V_15 , V_64 ) ;
}
if ( V_31 < 0 ) {
V_10 = V_31 ;
goto V_297;
}
if ( F_10 ( V_2 , V_31 ) ) {
V_10 = - V_146 ;
goto V_297;
}
V_10 = F_247 ( V_41 , V_31 ) ;
if ( V_10 < 0 ) {
F_11 ( V_2 , V_31 ) ;
goto V_297;
}
if ( ! V_15 || V_15 -> V_53 & V_54 )
F_16 ( V_17 , V_29 , V_28 ) ;
return 0 ;
V_297:
if ( V_15 && F_48 ( V_15 , V_64 ) )
F_251 ( & V_17 -> V_48 , F_41 ) ;
return V_10 ;
}
void F_352 ( struct V_12 * V_12 , long V_298 , long V_299 )
{
struct V_40 * V_41 = F_351 ( V_12 ) ;
struct V_17 * V_17 = F_43 ( V_12 ) ;
long V_31 = 0 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( V_17 )
V_31 = F_23 ( V_17 , V_298 ) ;
F_8 ( & V_12 -> V_272 ) ;
V_12 -> V_273 -= ( F_332 ( V_41 ) * V_299 ) ;
F_2 ( & V_12 -> V_272 ) ;
F_11 ( V_2 , ( V_31 - V_299 ) ) ;
F_247 ( V_41 , - ( V_31 - V_299 ) ) ;
}
static unsigned long F_353 ( struct V_14 * V_300 ,
struct V_14 * V_15 ,
unsigned long V_142 , T_1 V_143 )
{
unsigned long V_301 = ( ( V_143 - V_300 -> V_44 ) << V_156 ) +
V_300 -> V_43 ;
unsigned long V_302 = V_301 & V_303 ;
unsigned long V_304 = V_302 + V_305 ;
unsigned long V_53 = V_15 -> V_53 & ~ V_306 ;
unsigned long V_307 = V_300 -> V_53 & ~ V_306 ;
if ( F_354 ( V_142 ) != F_354 ( V_301 ) ||
V_53 != V_307 ||
V_302 < V_300 -> V_43 || V_300 -> V_223 < V_304 )
return 0 ;
return V_301 ;
}
static int F_355 ( struct V_14 * V_15 , unsigned long V_142 )
{
unsigned long V_308 = V_142 & V_303 ;
unsigned long V_36 = V_308 + V_305 ;
if ( V_15 -> V_53 & V_54 &&
V_15 -> V_43 <= V_308 && V_36 <= V_15 -> V_223 )
return 1 ;
return 0 ;
}
T_10 * F_356 ( struct V_232 * V_252 , unsigned long V_142 , T_16 * V_309 )
{
struct V_14 * V_15 = F_357 ( V_252 , V_142 ) ;
struct V_55 * V_56 = V_15 -> V_16 -> V_57 ;
T_1 V_143 = ( ( V_142 - V_15 -> V_43 ) >> V_156 ) +
V_15 -> V_44 ;
struct V_14 * V_300 ;
unsigned long V_301 ;
T_10 * V_310 = NULL ;
T_10 * V_230 ;
T_12 * V_254 ;
if ( ! F_355 ( V_15 , V_142 ) )
return ( T_10 * ) F_358 ( V_252 , V_309 , V_142 ) ;
F_307 ( & V_56 -> V_260 ) ;
F_308 (svma, &mapping->i_mmap, idx, idx) {
if ( V_300 == V_15 )
continue;
V_301 = F_353 ( V_300 , V_15 , V_142 , V_143 ) ;
if ( V_301 ) {
V_310 = F_275 ( V_300 -> V_253 , V_301 ) ;
if ( V_310 ) {
F_286 ( F_177 ( V_310 ) ) ;
break;
}
}
}
if ( ! V_310 )
goto V_35;
V_254 = F_278 ( F_33 ( V_15 ) , V_252 , V_310 ) ;
F_8 ( V_254 ) ;
if ( F_359 ( * V_309 ) )
F_360 ( V_252 , V_309 ,
( V_311 * ) ( ( unsigned long ) V_310 & V_312 ) ) ;
else
F_127 ( F_177 ( V_310 ) ) ;
F_2 ( V_254 ) ;
V_35:
V_230 = ( T_10 * ) F_358 ( V_252 , V_309 , V_142 ) ;
F_309 ( & V_56 -> V_260 ) ;
return V_230 ;
}
int F_292 ( struct V_232 * V_252 , unsigned long * V_142 , T_10 * V_229 )
{
T_17 * V_313 = F_361 ( V_252 , * V_142 ) ;
T_16 * V_309 = F_362 ( V_313 , * V_142 ) ;
F_9 ( F_90 ( F_177 ( V_229 ) ) == 0 ) ;
if ( F_90 ( F_177 ( V_229 ) ) == 1 )
return 0 ;
F_363 ( V_309 ) ;
F_127 ( F_177 ( V_229 ) ) ;
* V_142 = F_97 ( * V_142 , V_194 * V_314 ) - V_194 ;
return 1 ;
}
T_10 * F_356 ( struct V_232 * V_252 , unsigned long V_142 , T_16 * V_309 )
{
return NULL ;
}
T_10 * F_276 ( struct V_232 * V_252 ,
unsigned long V_142 , unsigned long V_239 )
{
T_17 * V_313 ;
T_16 * V_309 ;
T_10 * V_230 = NULL ;
V_313 = F_361 ( V_252 , V_142 ) ;
V_309 = F_364 ( V_252 , V_313 , V_142 ) ;
if ( V_309 ) {
if ( V_239 == V_305 ) {
V_230 = ( T_10 * ) V_309 ;
} else {
F_9 ( V_239 != V_315 ) ;
if ( F_365 () && F_359 ( * V_309 ) )
V_230 = F_356 ( V_252 , V_142 , V_309 ) ;
else
V_230 = ( T_10 * ) F_358 ( V_252 , V_309 , V_142 ) ;
}
}
F_9 ( V_230 && ! F_366 ( * V_230 ) && ! F_367 ( * V_230 ) ) ;
return V_230 ;
}
T_10 * F_275 ( struct V_232 * V_252 , unsigned long V_142 )
{
T_17 * V_313 ;
T_16 * V_309 ;
V_311 * V_316 = NULL ;
V_313 = F_361 ( V_252 , V_142 ) ;
if ( F_368 ( * V_313 ) ) {
V_309 = F_362 ( V_313 , V_142 ) ;
if ( F_369 ( * V_309 ) ) {
if ( F_370 ( * V_309 ) )
return ( T_10 * ) V_309 ;
V_316 = F_371 ( V_309 , V_142 ) ;
}
}
return ( T_10 * ) V_316 ;
}
struct V_65 *
F_372 ( struct V_232 * V_252 , unsigned long V_42 ,
V_311 * V_316 , int V_212 )
{
struct V_65 * V_65 ;
V_65 = F_285 ( * ( T_10 * ) V_316 ) ;
if ( V_65 )
V_65 += ( ( V_42 & ~ V_317 ) >> V_156 ) ;
return V_65 ;
}
struct V_65 *
F_373 ( struct V_232 * V_252 , unsigned long V_42 ,
T_16 * V_309 , int V_212 )
{
struct V_65 * V_65 ;
V_65 = F_285 ( * ( T_10 * ) V_309 ) ;
if ( V_65 )
V_65 += ( ( V_42 & ~ V_303 ) >> V_156 ) ;
return V_65 ;
}
struct V_65 * __weak
F_373 ( struct V_232 * V_252 , unsigned long V_42 ,
T_16 * V_309 , int V_212 )
{
F_216 () ;
return NULL ;
}
static int F_374 ( struct V_65 * V_318 )
{
struct V_65 * V_65 ;
struct V_65 * V_135 ;
struct V_40 * V_41 = F_117 ( V_318 ) ;
int V_66 = F_52 ( V_318 ) ;
F_18 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_65 == V_318 )
return 1 ;
return 0 ;
}
int F_375 ( struct V_65 * V_318 )
{
struct V_40 * V_41 = F_117 ( V_318 ) ;
int V_66 = F_52 ( V_318 ) ;
int V_10 = - V_319 ;
F_8 ( & V_117 ) ;
if ( F_374 ( V_318 ) ) {
F_376 ( & V_318 -> V_67 ) ;
F_56 ( V_318 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ V_66 ] -- ;
V_10 = 0 ;
}
F_2 ( & V_117 ) ;
return V_10 ;
}
bool F_377 ( struct V_65 * V_65 , struct V_21 * V_153 )
{
F_108 ( ! F_136 ( V_65 ) , V_65 ) ;
if ( ! F_378 ( V_65 ) )
return false ;
F_8 ( & V_117 ) ;
F_379 ( & V_65 -> V_67 , V_153 ) ;
F_2 ( & V_117 ) ;
return true ;
}
void F_380 ( struct V_65 * V_65 )
{
F_108 ( ! F_136 ( V_65 ) , V_65 ) ;
F_8 ( & V_117 ) ;
F_379 ( & V_65 -> V_67 , & ( F_117 ( V_65 ) ) -> V_71 ) ;
F_2 ( & V_117 ) ;
F_127 ( V_65 ) ;
}
bool F_381 ( struct V_65 * V_65 )
{
F_108 ( ! F_91 ( V_65 ) , V_65 ) ;
if ( F_382 ( V_65 ) )
return false ;
if ( F_67 ( F_334 ( V_65 ) ) )
return false ;
return F_90 ( V_65 ) > 0 ;
}
