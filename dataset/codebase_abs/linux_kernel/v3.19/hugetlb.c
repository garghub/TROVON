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
F_45 ( ! F_35 ( V_15 ) , V_15 ) ;
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
F_45 ( ! F_35 ( V_15 ) , V_15 ) ;
F_45 ( V_15 -> V_53 & V_54 , V_15 ) ;
F_38 ( V_15 , ( F_37 ( V_15 ) &
V_59 ) | ( unsigned long ) V_60 ) ;
}
static void F_47 ( struct V_14 * V_15 , unsigned long V_61 )
{
F_45 ( ! F_35 ( V_15 ) , V_15 ) ;
F_45 ( V_15 -> V_53 & V_54 , V_15 ) ;
F_38 ( V_15 , F_37 ( V_15 ) | V_61 ) ;
}
static int F_48 ( struct V_14 * V_15 , unsigned long V_62 )
{
F_45 ( ! F_35 ( V_15 ) , V_15 ) ;
return ( F_37 ( V_15 ) & V_62 ) != 0 ;
}
void F_49 ( struct V_14 * V_15 )
{
F_45 ( ! F_35 ( V_15 ) , V_15 ) ;
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
F_72 ( V_66 >= V_88 ) ;
return V_66 ;
}
static int F_73 ( int V_66 , T_3 * V_87 )
{
if ( ! F_74 ( V_66 , * V_87 ) )
V_66 = F_69 ( V_66 , V_87 ) ;
return V_66 ;
}
static int F_75 ( struct V_40 * V_41 ,
T_3 * V_87 )
{
int V_66 ;
F_72 ( ! V_87 ) ;
V_66 = F_73 ( V_41 -> V_89 , V_87 ) ;
V_41 -> V_89 = F_69 ( V_66 , V_87 ) ;
return V_66 ;
}
static int F_76 ( struct V_40 * V_41 , T_3 * V_87 )
{
int V_66 ;
F_72 ( ! V_87 ) ;
V_66 = F_73 ( V_41 -> V_90 , V_87 ) ;
V_41 -> V_90 = F_69 ( V_66 , V_87 ) ;
return V_66 ;
}
static void F_77 ( struct V_65 * V_65 ,
unsigned long V_91 )
{
int V_92 ;
int V_93 = 1 << V_91 ;
struct V_65 * V_94 = V_65 + 1 ;
for ( V_92 = 1 ; V_92 < V_93 ; V_92 ++ , V_94 = F_78 ( V_94 , V_65 , V_92 ) ) {
F_79 ( V_94 ) ;
F_56 ( V_94 ) ;
V_94 -> V_95 = NULL ;
}
F_80 ( V_65 , 0 ) ;
F_81 ( V_65 ) ;
}
static void F_82 ( struct V_65 * V_65 , unsigned V_91 )
{
F_83 ( F_84 ( V_65 ) , 1 << V_91 ) ;
}
static int F_85 ( unsigned long V_96 ,
unsigned long V_93 )
{
unsigned long V_97 = V_96 + V_93 ;
return F_86 ( V_96 , V_97 , V_98 ) ;
}
static bool F_87 ( unsigned long V_96 ,
unsigned long V_93 )
{
unsigned long V_92 , V_97 = V_96 + V_93 ;
struct V_65 * V_65 ;
for ( V_92 = V_96 ; V_92 < V_97 ; V_92 ++ ) {
if ( ! F_88 ( V_92 ) )
return false ;
V_65 = F_89 ( V_92 ) ;
if ( F_90 ( V_65 ) )
return false ;
if ( F_91 ( V_65 ) > 0 )
return false ;
if ( F_92 ( V_65 ) )
return false ;
}
return true ;
}
static bool F_93 ( const struct V_80 * V_80 ,
unsigned long V_96 , unsigned long V_93 )
{
unsigned long V_99 = V_96 + V_93 - 1 ;
return F_94 ( V_80 , V_99 ) ;
}
static struct V_65 * F_95 ( int V_66 , unsigned V_91 )
{
unsigned long V_93 = 1 << V_91 ;
unsigned long V_10 , V_100 , V_61 ;
struct V_80 * V_82 ;
V_82 = F_96 ( V_66 ) -> V_101 ;
for (; V_82 - F_96 ( V_66 ) -> V_101 < V_102 ; V_82 ++ ) {
F_97 ( & V_82 -> V_5 , V_61 ) ;
V_100 = F_98 ( V_82 -> V_103 , V_93 ) ;
while ( F_93 ( V_82 , V_100 , V_93 ) ) {
if ( F_87 ( V_100 , V_93 ) ) {
F_99 ( & V_82 -> V_5 , V_61 ) ;
V_10 = F_85 ( V_100 , V_93 ) ;
if ( ! V_10 )
return F_89 ( V_100 ) ;
F_97 ( & V_82 -> V_5 , V_61 ) ;
}
V_100 += V_93 ;
}
F_99 ( & V_82 -> V_5 , V_61 ) ;
}
return NULL ;
}
static struct V_65 * F_100 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 ;
V_65 = F_95 ( V_66 , F_31 ( V_41 ) ) ;
if ( V_65 ) {
F_101 ( V_65 , F_31 ( V_41 ) ) ;
F_102 ( V_41 , V_65 , V_66 ) ;
}
return V_65 ;
}
static int F_103 ( struct V_40 * V_41 ,
T_3 * V_87 )
{
struct V_65 * V_65 = NULL ;
int V_104 , V_105 ;
F_104 (h, nr_nodes, node, nodes_allowed) {
V_65 = F_100 ( V_41 , V_105 ) ;
if ( V_65 )
return 1 ;
}
return 0 ;
}
static inline bool F_105 ( void ) { return true ; }
static inline bool F_105 ( void ) { return false ; }
static inline void F_82 ( struct V_65 * V_65 , unsigned V_91 ) { }
static inline void F_77 ( struct V_65 * V_65 ,
unsigned long V_91 ) { }
static inline int F_103 ( struct V_40 * V_41 ,
T_3 * V_87 ) { return 0 ; }
static void F_106 ( struct V_40 * V_41 , struct V_65 * V_65 )
{
int V_92 ;
if ( F_107 ( V_41 ) && ! F_105 () )
return;
V_41 -> V_106 -- ;
V_41 -> V_107 [ F_52 ( V_65 ) ] -- ;
for ( V_92 = 0 ; V_92 < F_108 ( V_41 ) ; V_92 ++ ) {
V_65 [ V_92 ] . V_61 &= ~ ( 1 << V_108 | 1 << V_109 |
1 << V_110 | 1 << V_111 |
1 << V_112 | 1 << V_113 |
1 << V_114 ) ;
}
F_109 ( F_110 ( V_65 ) , V_65 ) ;
F_111 ( V_65 , NULL ) ;
F_56 ( V_65 ) ;
if ( F_107 ( V_41 ) ) {
F_77 ( V_65 , F_31 ( V_41 ) ) ;
F_82 ( V_65 , F_31 ( V_41 ) ) ;
} else {
F_112 ( V_65 ) ;
F_113 ( V_65 , F_31 ( V_41 ) ) ;
}
}
struct V_40 * F_114 ( unsigned long V_115 )
{
struct V_40 * V_41 ;
F_115 (h) {
if ( F_116 ( V_41 ) == V_115 )
return V_41 ;
}
return NULL ;
}
void F_117 ( struct V_65 * V_65 )
{
struct V_40 * V_41 = F_118 ( V_65 ) ;
int V_66 = F_52 ( V_65 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_119 ( V_65 ) ;
bool V_116 ;
F_120 ( V_65 , 0 ) ;
V_65 -> V_56 = NULL ;
F_9 ( F_91 ( V_65 ) ) ;
F_9 ( F_121 ( V_65 ) ) ;
V_116 = F_122 ( V_65 ) ;
F_123 ( V_65 ) ;
F_8 ( & V_117 ) ;
F_124 ( F_125 ( V_41 ) ,
F_108 ( V_41 ) , V_65 ) ;
if ( V_116 )
V_41 -> V_84 ++ ;
if ( V_41 -> V_118 [ V_66 ] ) {
F_19 ( & V_65 -> V_67 ) ;
F_106 ( V_41 , V_65 ) ;
V_41 -> V_119 -- ;
V_41 -> V_118 [ V_66 ] -- ;
} else {
F_126 ( V_65 ) ;
F_51 ( V_41 , V_65 ) ;
}
F_2 ( & V_117 ) ;
F_11 ( V_2 , 1 ) ;
}
static void F_102 ( struct V_40 * V_41 , struct V_65 * V_65 , int V_66 )
{
F_21 ( & V_65 -> V_67 ) ;
F_111 ( V_65 , F_117 ) ;
F_8 ( & V_117 ) ;
F_127 ( V_65 , NULL ) ;
V_41 -> V_106 ++ ;
V_41 -> V_107 [ V_66 ] ++ ;
F_2 ( & V_117 ) ;
F_128 ( V_65 ) ;
}
static void F_101 ( struct V_65 * V_65 , unsigned long V_91 )
{
int V_92 ;
int V_93 = 1 << V_91 ;
struct V_65 * V_94 = V_65 + 1 ;
F_80 ( V_65 , V_91 ) ;
F_129 ( V_65 ) ;
F_130 ( V_65 ) ;
for ( V_92 = 1 ; V_92 < V_93 ; V_92 ++ , V_94 = F_78 ( V_94 , V_65 , V_92 ) ) {
F_131 ( V_94 ) ;
F_130 ( V_94 ) ;
F_132 ( V_94 , 0 ) ;
V_94 -> V_95 = V_65 ;
}
}
int F_92 ( struct V_65 * V_65 )
{
if ( ! F_133 ( V_65 ) )
return 0 ;
V_65 = F_134 ( V_65 ) ;
return F_135 ( V_65 ) == F_117 ;
}
int F_136 ( struct V_65 * V_120 )
{
if ( ! F_137 ( V_120 ) )
return 0 ;
return F_135 ( V_120 ) == F_117 ;
}
T_1 F_138 ( struct V_65 * V_65 )
{
struct V_65 * V_120 = F_134 ( V_65 ) ;
T_1 V_121 = F_139 ( V_120 ) ;
unsigned long V_122 ;
if ( ! F_92 ( V_120 ) )
return F_139 ( V_65 ) ;
if ( F_140 ( V_120 ) >= V_123 )
V_122 = F_84 ( V_65 ) - F_84 ( V_120 ) ;
else
V_122 = V_65 - V_120 ;
return ( V_121 << F_140 ( V_120 ) ) + V_122 ;
}
static struct V_65 * F_141 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 ;
V_65 = F_142 ( V_66 ,
F_57 ( V_41 ) | V_124 | V_125 |
V_126 | V_127 ,
F_31 ( V_41 ) ) ;
if ( V_65 ) {
if ( F_143 ( V_65 ) ) {
F_113 ( V_65 , F_31 ( V_41 ) ) ;
return NULL ;
}
F_102 ( V_41 , V_65 , V_66 ) ;
}
return V_65 ;
}
static int F_144 ( struct V_40 * V_41 , T_3 * V_87 )
{
struct V_65 * V_65 ;
int V_104 , V_105 ;
int V_10 = 0 ;
F_104 (h, nr_nodes, node, nodes_allowed) {
V_65 = F_141 ( V_41 , V_105 ) ;
if ( V_65 ) {
V_10 = 1 ;
break;
}
}
if ( V_10 )
F_145 ( V_128 ) ;
else
F_145 ( V_129 ) ;
return V_10 ;
}
static int F_146 ( struct V_40 * V_41 , T_3 * V_87 ,
bool V_130 )
{
int V_104 , V_105 ;
int V_10 = 0 ;
F_147 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_130 || V_41 -> V_118 [ V_105 ] ) &&
! F_148 ( & V_41 -> V_68 [ V_105 ] ) ) {
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
F_106 ( V_41 , V_65 ) ;
V_10 = 1 ;
break;
}
}
return V_10 ;
}
static void F_149 ( struct V_65 * V_65 )
{
F_8 ( & V_117 ) ;
if ( F_92 ( V_65 ) && ! F_91 ( V_65 ) ) {
struct V_40 * V_41 = F_118 ( V_65 ) ;
int V_66 = F_52 ( V_65 ) ;
F_19 ( & V_65 -> V_67 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ V_66 ] -- ;
F_106 ( V_41 , V_65 ) ;
}
F_2 ( & V_117 ) ;
}
void F_150 ( unsigned long V_96 , unsigned long V_97 )
{
unsigned int V_91 = 8 * sizeof( void * ) ;
unsigned long V_100 ;
struct V_40 * V_41 ;
if ( ! F_151 () )
return;
F_115 (h)
if ( V_91 > F_31 ( V_41 ) )
V_91 = F_31 ( V_41 ) ;
F_72 ( ! F_152 ( V_96 , 1 << V_91 ) ) ;
for ( V_100 = V_96 ; V_100 < V_97 ; V_100 += 1 << V_91 )
F_149 ( F_89 ( V_100 ) ) ;
}
static struct V_65 * F_153 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 ;
unsigned int V_131 ;
if ( F_107 ( V_41 ) )
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
V_65 = F_154 ( F_57 ( V_41 ) | V_124 |
V_126 | V_127 ,
F_31 ( V_41 ) ) ;
else
V_65 = F_142 ( V_66 ,
F_57 ( V_41 ) | V_124 | V_125 |
V_126 | V_127 , F_31 ( V_41 ) ) ;
if ( V_65 && F_143 ( V_65 ) ) {
F_113 ( V_65 , F_31 ( V_41 ) ) ;
V_65 = NULL ;
}
F_8 ( & V_117 ) ;
if ( V_65 ) {
F_21 ( & V_65 -> V_67 ) ;
V_131 = F_52 ( V_65 ) ;
F_111 ( V_65 , F_117 ) ;
F_127 ( V_65 , NULL ) ;
V_41 -> V_107 [ V_131 ] ++ ;
V_41 -> V_118 [ V_131 ] ++ ;
F_155 ( V_128 ) ;
} else {
V_41 -> V_106 -- ;
V_41 -> V_119 -- ;
F_155 ( V_129 ) ;
}
F_2 ( & V_117 ) ;
return V_65 ;
}
struct V_65 * F_156 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 = NULL ;
F_8 ( & V_117 ) ;
if ( V_41 -> V_69 - V_41 -> V_84 > 0 )
V_65 = F_54 ( V_41 , V_66 ) ;
F_2 ( & V_117 ) ;
if ( ! V_65 )
V_65 = F_153 ( V_41 , V_66 ) ;
return V_65 ;
}
static int F_157 ( struct V_40 * V_41 , int V_9 )
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
V_65 = F_153 ( V_41 , V_133 ) ;
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
F_158 ( V_65 ) ;
F_109 ( F_91 ( V_65 ) , V_65 ) ;
F_51 ( V_41 , V_65 ) ;
}
free:
F_2 ( & V_117 ) ;
F_18 (page, tmp, &surplus_list, lru)
F_128 ( V_65 ) ;
F_8 ( & V_117 ) ;
return V_10 ;
}
static void F_159 ( struct V_40 * V_41 ,
unsigned long V_139 )
{
unsigned long V_93 ;
V_41 -> V_84 -= V_139 ;
if ( F_107 ( V_41 ) )
return;
V_93 = F_28 ( V_139 , V_41 -> V_119 ) ;
while ( V_93 -- ) {
if ( ! F_146 ( V_41 , & V_140 [ V_141 ] , 1 ) )
break;
F_160 ( & V_117 ) ;
}
}
static long F_161 ( struct V_40 * V_41 ,
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
static void F_162 ( struct V_40 * V_41 ,
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
static struct V_65 * F_163 ( struct V_14 * V_15 ,
unsigned long V_142 , int V_75 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_65 * V_65 ;
long V_31 ;
int V_10 , V_143 ;
struct V_144 * V_145 ;
V_143 = F_125 ( V_41 ) ;
V_31 = F_161 ( V_41 , V_15 , V_142 ) ;
if ( V_31 < 0 )
return F_164 ( - V_11 ) ;
if ( V_31 || V_75 )
if ( F_10 ( V_2 , 1 ) )
return F_164 ( - V_146 ) ;
V_10 = F_165 ( V_143 , F_108 ( V_41 ) , & V_145 ) ;
if ( V_10 )
goto V_147;
F_8 ( & V_117 ) ;
V_65 = F_59 ( V_41 , V_15 , V_142 , V_75 , V_31 ) ;
if ( ! V_65 ) {
F_2 ( & V_117 ) ;
V_65 = F_153 ( V_41 , V_133 ) ;
if ( ! V_65 )
goto V_148;
F_8 ( & V_117 ) ;
F_53 ( & V_65 -> V_67 , & V_41 -> V_71 ) ;
}
F_166 ( V_143 , F_108 ( V_41 ) , V_145 , V_65 ) ;
F_2 ( & V_117 ) ;
F_120 ( V_65 , ( unsigned long ) V_2 ) ;
F_162 ( V_41 , V_15 , V_142 ) ;
return V_65 ;
V_148:
F_167 ( V_143 , F_108 ( V_41 ) , V_145 ) ;
V_147:
if ( V_31 || V_75 )
F_11 ( V_2 , 1 ) ;
return F_164 ( - V_146 ) ;
}
struct V_65 * F_168 ( struct V_14 * V_15 ,
unsigned long V_142 , int V_75 )
{
struct V_65 * V_65 = F_163 ( V_15 , V_142 , V_75 ) ;
if ( F_169 ( V_65 ) )
V_65 = NULL ;
return V_65 ;
}
int __weak F_170 ( struct V_40 * V_41 )
{
struct V_149 * V_150 ;
int V_104 , V_105 ;
F_104 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_142 ;
V_142 = F_171 (
F_116 ( V_41 ) , F_116 ( V_41 ) ,
0 , V_151 , V_105 ) ;
if ( V_142 ) {
V_150 = V_142 ;
goto V_152;
}
}
return 0 ;
V_152:
F_9 ( ! F_152 ( F_172 ( V_150 ) , F_116 ( V_41 ) ) ) ;
F_22 ( & V_150 -> V_153 , & V_154 ) ;
V_150 -> V_40 = V_41 ;
return 1 ;
}
static void T_4 F_173 ( struct V_65 * V_65 , int V_91 )
{
if ( F_67 ( V_91 > ( V_123 - 1 ) ) )
F_101 ( V_65 , V_91 ) ;
else
F_174 ( V_65 , V_91 ) ;
}
static void T_4 F_175 ( void )
{
struct V_149 * V_150 ;
F_17 (m, &huge_boot_pages, list) {
struct V_40 * V_41 = V_150 -> V_40 ;
struct V_65 * V_65 ;
#ifdef F_176
V_65 = F_89 ( V_150 -> V_155 >> V_156 ) ;
F_177 ( F_178 ( V_150 ) ,
sizeof( struct V_149 ) ) ;
#else
V_65 = F_179 ( V_150 ) ;
#endif
F_180 ( F_91 ( V_65 ) != 1 ) ;
F_173 ( V_65 , V_41 -> V_91 ) ;
F_180 ( F_90 ( V_65 ) ) ;
F_102 ( V_41 , V_65 , F_52 ( V_65 ) ) ;
if ( F_107 ( V_41 ) )
F_181 ( V_65 , 1 << V_41 -> V_91 ) ;
}
}
static void T_4 F_182 ( struct V_40 * V_41 )
{
unsigned long V_92 ;
for ( V_92 = 0 ; V_92 < V_41 -> V_157 ; ++ V_92 ) {
if ( F_107 ( V_41 ) ) {
if ( ! F_170 ( V_41 ) )
break;
} else if ( ! F_144 ( V_41 ,
& V_140 [ V_141 ] ) )
break;
}
V_41 -> V_157 = V_92 ;
}
static void T_4 F_183 ( void )
{
struct V_40 * V_41 ;
F_115 (h) {
if ( ! F_107 ( V_41 ) )
F_182 ( V_41 ) ;
}
}
static char * T_4 F_184 ( char * V_158 , unsigned long V_159 )
{
if ( V_159 >= ( 1UL << 30 ) )
sprintf ( V_158 , L_1 , V_159 >> 30 ) ;
else if ( V_159 >= ( 1UL << 20 ) )
sprintf ( V_158 , L_2 , V_159 >> 20 ) ;
else
sprintf ( V_158 , L_3 , V_159 >> 10 ) ;
return V_158 ;
}
static void T_4 F_185 ( void )
{
struct V_40 * V_41 ;
F_115 (h) {
char V_158 [ 32 ] ;
F_186 ( L_4 ,
F_184 ( V_158 , F_116 ( V_41 ) ) ,
V_41 -> V_69 ) ;
}
}
static void F_187 ( struct V_40 * V_41 , unsigned long V_3 ,
T_3 * V_87 )
{
int V_92 ;
if ( F_107 ( V_41 ) )
return;
F_188 (i, *nodes_allowed) {
struct V_65 * V_65 , * V_37 ;
struct V_21 * V_160 = & V_41 -> V_68 [ V_92 ] ;
F_18 (page, next, freel, lru) {
if ( V_3 >= V_41 -> V_106 )
return;
if ( F_189 ( V_65 ) )
continue;
F_19 ( & V_65 -> V_67 ) ;
F_106 ( V_41 , V_65 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ F_52 ( V_65 ) ] -- ;
}
}
}
static inline void F_187 ( struct V_40 * V_41 , unsigned long V_3 ,
T_3 * V_87 )
{
}
static int F_190 ( struct V_40 * V_41 , T_3 * V_87 ,
int V_9 )
{
int V_104 , V_105 ;
F_72 ( V_9 != - 1 && V_9 != 1 ) ;
if ( V_9 < 0 ) {
F_104 (h, nr_nodes, node, nodes_allowed) {
if ( V_41 -> V_118 [ V_105 ] )
goto V_152;
}
} else {
F_147 (h, nr_nodes, node, nodes_allowed) {
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
static unsigned long F_191 ( struct V_40 * V_41 , unsigned long V_3 ,
T_3 * V_87 )
{
unsigned long V_161 , V_10 ;
if ( F_107 ( V_41 ) && ! F_105 () )
return V_41 -> V_157 ;
F_8 ( & V_117 ) ;
while ( V_41 -> V_119 && V_3 > F_192 ( V_41 ) ) {
if ( ! F_190 ( V_41 , V_87 , - 1 ) )
break;
}
while ( V_3 > F_192 ( V_41 ) ) {
F_2 ( & V_117 ) ;
if ( F_107 ( V_41 ) )
V_10 = F_103 ( V_41 , V_87 ) ;
else
V_10 = F_144 ( V_41 , V_87 ) ;
F_8 ( & V_117 ) ;
if ( ! V_10 )
goto V_35;
if ( F_193 ( V_162 ) )
goto V_35;
}
V_161 = V_41 -> V_84 + V_41 -> V_106 - V_41 -> V_69 ;
V_161 = F_27 ( V_3 , V_161 ) ;
F_187 ( V_41 , V_161 , V_87 ) ;
while ( V_161 < F_192 ( V_41 ) ) {
if ( ! F_146 ( V_41 , V_87 , 0 ) )
break;
F_160 ( & V_117 ) ;
}
while ( V_3 < F_192 ( V_41 ) ) {
if ( ! F_190 ( V_41 , V_87 , 1 ) )
break;
}
V_35:
V_10 = F_192 ( V_41 ) ;
F_2 ( & V_117 ) ;
return V_10 ;
}
static struct V_40 * F_194 ( struct V_163 * V_164 , int * V_165 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_166 ; V_92 ++ )
if ( V_167 [ V_92 ] == V_164 ) {
if ( V_165 )
* V_165 = V_133 ;
return & V_168 [ V_92 ] ;
}
return F_195 ( V_164 , V_165 ) ;
}
static T_5 F_196 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
struct V_40 * V_41 ;
unsigned long V_106 ;
int V_66 ;
V_41 = F_194 ( V_164 , & V_66 ) ;
if ( V_66 == V_133 )
V_106 = V_41 -> V_106 ;
else
V_106 = V_41 -> V_107 [ V_66 ] ;
return sprintf ( V_158 , L_5 , V_106 ) ;
}
static T_5 F_197 ( bool V_171 ,
struct V_40 * V_41 , int V_66 ,
unsigned long V_3 , T_6 V_172 )
{
int V_85 ;
F_198 ( T_3 , V_87 , V_7 | V_173 ) ;
if ( F_107 ( V_41 ) && ! F_105 () ) {
V_85 = - V_174 ;
goto V_35;
}
if ( V_66 == V_133 ) {
if ( ! ( V_171 &&
F_199 ( V_87 ) ) ) {
F_200 ( V_87 ) ;
V_87 = & V_140 [ V_141 ] ;
}
} else if ( V_87 ) {
V_3 += V_41 -> V_106 - V_41 -> V_107 [ V_66 ] ;
F_201 ( V_87 , V_66 ) ;
} else
V_87 = & V_140 [ V_141 ] ;
V_41 -> V_157 = F_191 ( V_41 , V_3 , V_87 ) ;
if ( V_87 != & V_140 [ V_141 ] )
F_200 ( V_87 ) ;
return V_172 ;
V_35:
F_200 ( V_87 ) ;
return V_85 ;
}
static T_5 F_202 ( bool V_171 ,
struct V_163 * V_164 , const char * V_158 ,
T_6 V_172 )
{
struct V_40 * V_41 ;
unsigned long V_3 ;
int V_66 ;
int V_85 ;
V_85 = F_203 ( V_158 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
V_41 = F_194 ( V_164 , & V_66 ) ;
return F_197 ( V_171 , V_41 , V_66 , V_3 , V_172 ) ;
}
static T_5 F_204 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
return F_196 ( V_164 , V_170 , V_158 ) ;
}
static T_5 F_205 ( struct V_163 * V_164 ,
struct V_169 * V_170 , const char * V_158 , T_6 V_172 )
{
return F_202 ( false , V_164 , V_158 , V_172 ) ;
}
static T_5 F_206 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
return F_196 ( V_164 , V_170 , V_158 ) ;
}
static T_5 F_207 ( struct V_163 * V_164 ,
struct V_169 * V_170 , const char * V_158 , T_6 V_172 )
{
return F_202 ( true , V_164 , V_158 , V_172 ) ;
}
static T_5 F_208 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
struct V_40 * V_41 = F_194 ( V_164 , NULL ) ;
return sprintf ( V_158 , L_5 , V_41 -> V_132 ) ;
}
static T_5 F_209 ( struct V_163 * V_164 ,
struct V_169 * V_170 , const char * V_158 , T_6 V_3 )
{
int V_85 ;
unsigned long V_175 ;
struct V_40 * V_41 = F_194 ( V_164 , NULL ) ;
if ( F_107 ( V_41 ) )
return - V_174 ;
V_85 = F_203 ( V_158 , 10 , & V_175 ) ;
if ( V_85 )
return V_85 ;
F_8 ( & V_117 ) ;
V_41 -> V_132 = V_175 ;
F_2 ( & V_117 ) ;
return V_3 ;
}
static T_5 F_210 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
struct V_40 * V_41 ;
unsigned long V_69 ;
int V_66 ;
V_41 = F_194 ( V_164 , & V_66 ) ;
if ( V_66 == V_133 )
V_69 = V_41 -> V_69 ;
else
V_69 = V_41 -> V_70 [ V_66 ] ;
return sprintf ( V_158 , L_5 , V_69 ) ;
}
static T_5 F_211 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
struct V_40 * V_41 = F_194 ( V_164 , NULL ) ;
return sprintf ( V_158 , L_5 , V_41 -> V_84 ) ;
}
static T_5 F_212 ( struct V_163 * V_164 ,
struct V_169 * V_170 , char * V_158 )
{
struct V_40 * V_41 ;
unsigned long V_119 ;
int V_66 ;
V_41 = F_194 ( V_164 , & V_66 ) ;
if ( V_66 == V_133 )
V_119 = V_41 -> V_119 ;
else
V_119 = V_41 -> V_118 [ V_66 ] ;
return sprintf ( V_158 , L_5 , V_119 ) ;
}
static int F_213 ( struct V_40 * V_41 , struct V_163 * V_176 ,
struct V_163 * * V_167 ,
struct V_177 * V_178 )
{
int V_179 ;
int V_180 = F_125 ( V_41 ) ;
V_167 [ V_180 ] = F_214 ( V_41 -> V_181 , V_176 ) ;
if ( ! V_167 [ V_180 ] )
return - V_11 ;
V_179 = F_215 ( V_167 [ V_180 ] , V_178 ) ;
if ( V_179 )
F_216 ( V_167 [ V_180 ] ) ;
return V_179 ;
}
static void T_4 F_217 ( void )
{
struct V_40 * V_41 ;
int V_85 ;
V_182 = F_214 ( L_6 , V_183 ) ;
if ( ! V_182 )
return;
F_115 (h) {
V_85 = F_213 ( V_41 , V_182 ,
V_167 , & V_178 ) ;
if ( V_85 )
F_218 ( L_7 , V_41 -> V_181 ) ;
}
}
static struct V_40 * F_195 ( struct V_163 * V_164 , int * V_165 )
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
F_219 () ;
return NULL ;
}
static void F_220 ( struct V_105 * V_105 )
{
struct V_40 * V_41 ;
struct V_185 * V_186 = & V_187 [ V_105 -> V_188 . V_189 ] ;
if ( ! V_186 -> V_182 )
return;
F_115 (h) {
int V_143 = F_125 ( V_41 ) ;
if ( V_186 -> V_167 [ V_143 ] ) {
F_216 ( V_186 -> V_167 [ V_143 ] ) ;
V_186 -> V_167 [ V_143 ] = NULL ;
}
}
F_216 ( V_186 -> V_182 ) ;
V_186 -> V_182 = NULL ;
}
static void F_221 ( void )
{
int V_66 ;
F_222 ( NULL , NULL ) ;
for ( V_66 = 0 ; V_66 < V_184 ; V_66 ++ )
F_220 ( V_190 [ V_66 ] ) ;
}
static void F_223 ( struct V_105 * V_105 )
{
struct V_40 * V_41 ;
struct V_185 * V_186 = & V_187 [ V_105 -> V_188 . V_189 ] ;
int V_85 ;
if ( V_186 -> V_182 )
return;
V_186 -> V_182 = F_214 ( L_6 ,
& V_105 -> V_188 . V_164 ) ;
if ( ! V_186 -> V_182 )
return;
F_115 (h) {
V_85 = F_213 ( V_41 , V_186 -> V_182 ,
V_186 -> V_167 ,
& V_191 ) ;
if ( V_85 ) {
F_218 ( L_8 ,
V_41 -> V_181 , V_105 -> V_188 . V_189 ) ;
F_220 ( V_105 ) ;
break;
}
}
}
static void T_4 F_224 ( void )
{
int V_66 ;
F_225 (nid, N_MEMORY) {
struct V_105 * V_105 = V_190 [ V_66 ] ;
if ( V_105 -> V_188 . V_189 == V_66 )
F_223 ( V_105 ) ;
}
F_222 ( F_223 ,
F_220 ) ;
}
static struct V_40 * F_195 ( struct V_163 * V_164 , int * V_165 )
{
F_219 () ;
if ( V_165 )
* V_165 = - 1 ;
return NULL ;
}
static void F_221 ( void ) { }
static void F_224 ( void ) { }
static void T_7 F_226 ( void )
{
struct V_40 * V_41 ;
F_221 () ;
F_115 (h) {
F_216 ( V_167 [ F_125 ( V_41 ) ] ) ;
}
F_216 ( V_182 ) ;
F_3 ( V_192 ) ;
}
static int T_4 F_227 ( void )
{
int V_92 ;
if ( ! F_151 () )
return 0 ;
if ( ! F_114 ( V_193 ) ) {
V_193 = V_194 ;
if ( ! F_114 ( V_193 ) )
F_228 ( V_195 ) ;
}
V_196 = F_125 ( F_114 ( V_193 ) ) ;
if ( V_197 )
V_198 . V_157 = V_197 ;
F_183 () ;
F_175 () ;
F_185 () ;
F_217 () ;
F_224 () ;
F_229 () ;
#ifdef F_230
V_199 = F_231 ( 8 * F_232 () ) ;
#else
V_199 = 1 ;
#endif
V_192 =
F_5 ( sizeof( struct V_200 ) * V_199 , V_7 ) ;
F_9 ( ! V_192 ) ;
for ( V_92 = 0 ; V_92 < V_199 ; V_92 ++ )
F_233 ( & V_192 [ V_92 ] ) ;
return 0 ;
}
void T_4 F_228 ( unsigned V_91 )
{
struct V_40 * V_41 ;
unsigned long V_92 ;
if ( F_114 ( V_45 << V_91 ) ) {
F_234 ( L_9 ) ;
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
F_116 ( V_41 ) / 1024 ) ;
V_204 = V_41 ;
}
static int T_4 F_235 ( char * V_205 )
{
unsigned long * V_206 ;
static unsigned long * V_207 ;
if ( ! V_201 )
V_206 = & V_197 ;
else
V_206 = & V_204 -> V_157 ;
if ( V_206 == V_207 ) {
F_234 ( L_11
L_12 ) ;
return 1 ;
}
if ( sscanf ( V_205 , L_13 , V_206 ) <= 0 )
* V_206 = 0 ;
if ( V_201 && V_204 -> V_91 >= V_123 )
F_182 ( V_204 ) ;
V_207 = V_206 ;
return 1 ;
}
static int T_4 F_236 ( char * V_205 )
{
V_193 = F_237 ( V_205 , & V_205 ) ;
return 1 ;
}
static unsigned int F_238 ( unsigned int * V_208 )
{
int V_105 ;
unsigned int V_209 = 0 ;
F_188 (node, cpuset_current_mems_allowed)
V_209 += V_208 [ V_105 ] ;
return V_209 ;
}
static int F_239 ( bool V_171 ,
struct V_210 * V_211 , int V_212 ,
void T_8 * V_213 , T_6 * V_214 , T_9 * V_215 )
{
struct V_40 * V_41 = & V_198 ;
unsigned long V_135 = V_41 -> V_157 ;
int V_10 ;
if ( ! F_151 () )
return - V_216 ;
V_211 -> V_217 = & V_135 ;
V_211 -> V_218 = sizeof( unsigned long ) ;
V_10 = F_240 ( V_211 , V_212 , V_213 , V_214 , V_215 ) ;
if ( V_10 )
goto V_35;
if ( V_212 )
V_10 = F_197 ( V_171 , V_41 ,
V_133 , V_135 , * V_214 ) ;
V_35:
return V_10 ;
}
int F_241 ( struct V_210 * V_211 , int V_212 ,
void T_8 * V_213 , T_6 * V_214 , T_9 * V_215 )
{
return F_239 ( false , V_211 , V_212 ,
V_213 , V_214 , V_215 ) ;
}
int F_242 ( struct V_210 * V_211 , int V_212 ,
void T_8 * V_213 , T_6 * V_214 , T_9 * V_215 )
{
return F_239 ( true , V_211 , V_212 ,
V_213 , V_214 , V_215 ) ;
}
int F_243 ( struct V_210 * V_211 , int V_212 ,
void T_8 * V_213 ,
T_6 * V_214 , T_9 * V_215 )
{
struct V_40 * V_41 = & V_198 ;
unsigned long V_135 ;
int V_10 ;
if ( ! F_151 () )
return - V_216 ;
V_135 = V_41 -> V_132 ;
if ( V_212 && F_107 ( V_41 ) )
return - V_174 ;
V_211 -> V_217 = & V_135 ;
V_211 -> V_218 = sizeof( unsigned long ) ;
V_10 = F_240 ( V_211 , V_212 , V_213 , V_214 , V_215 ) ;
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
void F_244 ( struct V_219 * V_150 )
{
struct V_40 * V_41 = & V_198 ;
if ( ! F_151 () )
return;
F_245 ( V_150 ,
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
int F_246 ( int V_66 , char * V_158 )
{
struct V_40 * V_41 = & V_198 ;
if ( ! F_151 () )
return 0 ;
return sprintf ( V_158 ,
L_19
L_20
L_21 ,
V_66 , V_41 -> V_107 [ V_66 ] ,
V_66 , V_41 -> V_70 [ V_66 ] ,
V_66 , V_41 -> V_118 [ V_66 ] ) ;
}
void F_247 ( void )
{
struct V_40 * V_41 ;
int V_66 ;
if ( ! F_151 () )
return;
F_225 (nid, N_MEMORY)
F_115 (h)
F_186 ( L_22 ,
V_66 ,
V_41 -> V_107 [ V_66 ] ,
V_41 -> V_70 [ V_66 ] ,
V_41 -> V_118 [ V_66 ] ,
1UL << ( F_31 ( V_41 ) + V_156 - 10 ) ) ;
}
unsigned long F_248 ( void )
{
struct V_40 * V_41 ;
unsigned long V_220 = 0 ;
F_115 (h)
V_220 += V_41 -> V_106 * F_108 ( V_41 ) ;
return V_220 ;
}
static int F_249 ( struct V_40 * V_41 , long V_9 )
{
int V_10 = - V_11 ;
F_8 ( & V_117 ) ;
if ( V_9 > 0 ) {
if ( F_157 ( V_41 , V_9 ) < 0 )
goto V_35;
if ( V_9 > F_238 ( V_41 -> V_70 ) ) {
F_159 ( V_41 , V_9 ) ;
goto V_35;
}
}
V_10 = 0 ;
if ( V_9 < 0 )
F_159 ( V_41 , ( unsigned long ) - V_9 ) ;
V_35:
F_2 ( & V_117 ) ;
return V_10 ;
}
static void F_250 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_44 ( V_15 ) ;
if ( V_18 && F_48 ( V_15 , V_64 ) )
F_251 ( & V_18 -> V_48 ) ;
}
static void F_252 ( struct V_14 * V_15 )
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
F_253 ( & V_18 -> V_48 , F_41 ) ;
if ( V_221 ) {
F_249 ( V_41 , - V_221 ) ;
F_11 ( V_2 , V_221 ) ;
}
}
static int F_254 ( struct V_14 * V_15 , struct V_224 * V_225 )
{
F_219 () ;
return 0 ;
}
static T_10 F_255 ( struct V_14 * V_15 , struct V_65 * V_65 ,
int V_226 )
{
T_10 V_227 ;
if ( V_226 ) {
V_227 = F_256 ( F_257 ( F_258 ( V_65 ,
V_15 -> V_228 ) ) ) ;
} else {
V_227 = F_259 ( F_258 ( V_65 ,
V_15 -> V_228 ) ) ;
}
V_227 = F_260 ( V_227 ) ;
V_227 = F_261 ( V_227 ) ;
V_227 = F_262 ( V_227 , V_15 , V_65 , V_226 ) ;
return V_227 ;
}
static void F_263 ( struct V_14 * V_15 ,
unsigned long V_42 , T_10 * V_229 )
{
T_10 V_227 ;
V_227 = F_256 ( F_257 ( F_264 ( V_229 ) ) ) ;
if ( F_265 ( V_15 , V_42 , V_229 , V_227 , 1 ) )
F_266 ( V_15 , V_42 , V_229 ) ;
}
static int F_267 ( T_10 V_230 )
{
T_11 V_231 ;
if ( F_268 ( V_230 ) || F_269 ( V_230 ) )
return 0 ;
V_231 = F_270 ( V_230 ) ;
if ( F_271 ( V_231 ) && F_272 ( V_231 ) )
return 1 ;
else
return 0 ;
}
static int F_273 ( T_10 V_230 )
{
T_11 V_231 ;
if ( F_268 ( V_230 ) || F_269 ( V_230 ) )
return 0 ;
V_231 = F_270 ( V_230 ) ;
if ( F_271 ( V_231 ) && F_274 ( V_231 ) )
return 1 ;
else
return 0 ;
}
int F_275 ( struct V_232 * V_233 , struct V_232 * V_234 ,
struct V_14 * V_15 )
{
T_10 * V_235 , * V_236 , V_227 ;
struct V_65 * V_237 ;
unsigned long V_142 ;
int V_238 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
unsigned long V_239 = F_116 ( V_41 ) ;
unsigned long V_240 ;
unsigned long V_241 ;
int V_10 = 0 ;
V_238 = ( V_15 -> V_53 & ( V_242 | V_243 ) ) == V_243 ;
V_240 = V_15 -> V_43 ;
V_241 = V_15 -> V_223 ;
if ( V_238 )
F_276 ( V_234 , V_240 , V_241 ) ;
for ( V_142 = V_15 -> V_43 ; V_142 < V_15 -> V_223 ; V_142 += V_239 ) {
T_12 * V_244 , * V_245 ;
V_235 = F_277 ( V_234 , V_142 ) ;
if ( ! V_235 )
continue;
V_236 = F_278 ( V_233 , V_142 , V_239 ) ;
if ( ! V_236 ) {
V_10 = - V_11 ;
break;
}
if ( V_236 == V_235 )
continue;
V_245 = F_279 ( V_41 , V_233 , V_236 ) ;
V_244 = F_280 ( V_41 , V_234 , V_235 ) ;
F_281 ( V_244 , V_246 ) ;
V_227 = F_264 ( V_235 ) ;
if ( F_268 ( V_227 ) ) {
;
} else if ( F_67 ( F_267 ( V_227 ) ||
F_273 ( V_227 ) ) ) {
T_11 V_247 = F_270 ( V_227 ) ;
if ( F_282 ( V_247 ) && V_238 ) {
F_283 ( & V_247 ) ;
V_227 = F_284 ( V_247 ) ;
F_285 ( V_234 , V_142 , V_235 , V_227 ) ;
}
F_285 ( V_233 , V_142 , V_236 , V_227 ) ;
} else {
if ( V_238 ) {
F_286 ( V_234 , V_142 , V_235 ) ;
F_287 ( V_234 , V_240 ,
V_241 ) ;
}
V_227 = F_264 ( V_235 ) ;
V_237 = F_288 ( V_227 ) ;
F_289 ( V_237 ) ;
F_290 ( V_237 ) ;
F_285 ( V_233 , V_142 , V_236 , V_227 ) ;
}
F_2 ( V_244 ) ;
F_2 ( V_245 ) ;
}
if ( V_238 )
F_291 ( V_234 , V_240 , V_241 ) ;
return V_10 ;
}
void F_292 ( struct V_248 * V_249 , struct V_14 * V_15 ,
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
unsigned long V_239 = F_116 ( V_41 ) ;
const unsigned long V_240 = V_222 ;
const unsigned long V_241 = V_36 ;
F_180 ( ! F_35 ( V_15 ) ) ;
F_9 ( V_222 & ~ F_293 ( V_41 ) ) ;
F_9 ( V_36 & ~ F_293 ( V_41 ) ) ;
F_294 ( V_249 , V_15 ) ;
F_276 ( V_252 , V_240 , V_241 ) ;
V_42 = V_222 ;
V_255:
for (; V_42 < V_36 ; V_42 += V_239 ) {
V_229 = F_277 ( V_252 , V_42 ) ;
if ( ! V_229 )
continue;
V_254 = F_279 ( V_41 , V_252 , V_229 ) ;
if ( F_295 ( V_252 , & V_42 , V_229 ) )
goto V_256;
V_230 = F_264 ( V_229 ) ;
if ( F_268 ( V_230 ) )
goto V_256;
if ( F_67 ( F_273 ( V_230 ) ) ) {
F_296 ( V_252 , V_42 , V_229 ) ;
goto V_256;
}
V_65 = F_288 ( V_230 ) ;
if ( V_250 ) {
if ( V_65 != V_250 )
goto V_256;
F_47 ( V_15 , V_257 ) ;
}
V_230 = F_297 ( V_252 , V_42 , V_229 ) ;
F_298 ( V_249 , V_229 , V_42 ) ;
if ( F_299 ( V_230 ) )
F_300 ( V_65 ) ;
F_301 ( V_65 ) ;
V_251 = ! F_302 ( V_249 , V_65 ) ;
if ( V_251 ) {
V_42 += V_239 ;
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
F_303 ( V_249 ) ;
if ( V_42 < V_36 && ! V_250 )
goto V_255;
}
F_291 ( V_252 , V_240 , V_241 ) ;
F_304 ( V_249 , V_15 ) ;
}
void F_305 ( struct V_248 * V_249 ,
struct V_14 * V_15 , unsigned long V_222 ,
unsigned long V_36 , struct V_65 * V_250 )
{
F_292 ( V_249 , V_15 , V_222 , V_36 , V_250 ) ;
V_15 -> V_53 &= ~ V_54 ;
}
void F_306 ( struct V_14 * V_15 , unsigned long V_222 ,
unsigned long V_36 , struct V_65 * V_250 )
{
struct V_232 * V_252 ;
struct V_248 V_249 ;
V_252 = V_15 -> V_253 ;
F_307 ( & V_249 , V_252 , V_222 , V_36 ) ;
F_292 ( & V_249 , V_15 , V_222 , V_36 , V_250 ) ;
F_308 ( & V_249 , V_222 , V_36 ) ;
}
static void F_309 ( struct V_232 * V_252 , struct V_14 * V_15 ,
struct V_65 * V_65 , unsigned long V_42 )
{
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_14 * V_258 ;
struct V_55 * V_56 ;
T_1 V_259 ;
V_42 = V_42 & F_293 ( V_41 ) ;
V_259 = ( ( V_42 - V_15 -> V_43 ) >> V_156 ) +
V_15 -> V_44 ;
V_56 = F_15 ( V_15 -> V_16 ) -> V_51 ;
F_310 ( V_56 ) ;
F_311 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_258 == V_15 )
continue;
if ( ! F_48 ( V_258 , V_64 ) )
F_306 ( V_258 , V_42 ,
V_42 + F_116 ( V_41 ) , V_65 ) ;
}
F_312 ( V_56 ) ;
}
static int F_313 ( struct V_232 * V_252 , struct V_14 * V_15 ,
unsigned long V_42 , T_10 * V_229 , T_10 V_230 ,
struct V_65 * V_260 , T_12 * V_254 )
{
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_65 * V_261 , * V_262 ;
int V_10 = 0 , V_263 = 0 ;
unsigned long V_240 ;
unsigned long V_241 ;
V_261 = F_288 ( V_230 ) ;
V_264:
if ( F_121 ( V_261 ) == 1 && F_314 ( V_261 ) ) {
F_315 ( V_261 , V_15 , V_42 ) ;
F_263 ( V_15 , V_42 , V_229 ) ;
return 0 ;
}
if ( F_48 ( V_15 , V_64 ) &&
V_261 != V_260 )
V_263 = 1 ;
F_316 ( V_261 ) ;
F_2 ( V_254 ) ;
V_262 = F_163 ( V_15 , V_42 , V_263 ) ;
if ( F_169 ( V_262 ) ) {
if ( V_263 ) {
F_317 ( V_261 ) ;
F_9 ( F_268 ( V_230 ) ) ;
F_309 ( V_252 , V_15 , V_261 , V_42 ) ;
F_9 ( F_268 ( V_230 ) ) ;
F_8 ( V_254 ) ;
V_229 = F_277 ( V_252 , V_42 & F_293 ( V_41 ) ) ;
if ( F_318 ( V_229 &&
F_319 ( F_264 ( V_229 ) , V_230 ) ) )
goto V_264;
return 0 ;
}
V_10 = ( F_320 ( V_262 ) == - V_11 ) ?
V_265 : V_266 ;
goto V_267;
}
if ( F_67 ( F_321 ( V_15 ) ) ) {
V_10 = V_265 ;
goto V_268;
}
F_322 ( V_262 , V_261 , V_42 , V_15 ,
F_108 ( V_41 ) ) ;
F_323 ( V_262 ) ;
V_240 = V_42 & F_293 ( V_41 ) ;
V_241 = V_240 + F_116 ( V_41 ) ;
F_276 ( V_252 , V_240 , V_241 ) ;
F_8 ( V_254 ) ;
V_229 = F_277 ( V_252 , V_42 & F_293 ( V_41 ) ) ;
if ( F_318 ( V_229 && F_319 ( F_264 ( V_229 ) , V_230 ) ) ) {
F_123 ( V_262 ) ;
F_324 ( V_15 , V_42 , V_229 ) ;
F_287 ( V_252 , V_240 , V_241 ) ;
F_285 ( V_252 , V_42 , V_229 ,
F_255 ( V_15 , V_262 , 1 ) ) ;
F_301 ( V_261 ) ;
F_325 ( V_262 , V_15 , V_42 ) ;
V_262 = V_261 ;
}
F_2 ( V_254 ) ;
F_291 ( V_252 , V_240 , V_241 ) ;
V_268:
F_317 ( V_262 ) ;
V_267:
F_317 ( V_261 ) ;
F_8 ( V_254 ) ;
return V_10 ;
}
static struct V_65 * F_326 ( struct V_40 * V_41 ,
struct V_14 * V_15 , unsigned long V_42 )
{
struct V_55 * V_56 ;
T_1 V_143 ;
V_56 = V_15 -> V_16 -> V_57 ;
V_143 = F_29 ( V_41 , V_15 , V_42 ) ;
return F_327 ( V_56 , V_143 ) ;
}
static bool F_328 ( struct V_40 * V_41 ,
struct V_14 * V_15 , unsigned long V_42 )
{
struct V_55 * V_56 ;
T_1 V_143 ;
struct V_65 * V_65 ;
V_56 = V_15 -> V_16 -> V_57 ;
V_143 = F_29 ( V_41 , V_15 , V_42 ) ;
V_65 = F_329 ( V_56 , V_143 ) ;
if ( V_65 )
F_128 ( V_65 ) ;
return V_65 != NULL ;
}
static int F_330 ( struct V_232 * V_252 , struct V_14 * V_15 ,
struct V_55 * V_56 , T_1 V_143 ,
unsigned long V_42 , T_10 * V_229 , unsigned int V_61 )
{
struct V_40 * V_41 = F_33 ( V_15 ) ;
int V_10 = V_266 ;
int V_269 = 0 ;
unsigned long V_115 ;
struct V_65 * V_65 ;
T_10 V_270 ;
T_12 * V_254 ;
if ( F_48 ( V_15 , V_257 ) ) {
F_234 ( L_23 ,
V_162 -> V_271 ) ;
return V_10 ;
}
V_32:
V_65 = F_327 ( V_56 , V_143 ) ;
if ( ! V_65 ) {
V_115 = F_331 ( V_56 -> V_58 ) >> F_30 ( V_41 ) ;
if ( V_143 >= V_115 )
goto V_35;
V_65 = F_163 ( V_15 , V_42 , 0 ) ;
if ( F_169 ( V_65 ) ) {
V_10 = F_320 ( V_65 ) ;
if ( V_10 == - V_11 )
V_10 = V_265 ;
else
V_10 = V_266 ;
goto V_35;
}
F_332 ( V_65 , V_42 , F_108 ( V_41 ) ) ;
F_323 ( V_65 ) ;
if ( V_15 -> V_53 & V_54 ) {
int V_85 ;
struct V_12 * V_12 = V_56 -> V_58 ;
V_85 = F_333 ( V_65 , V_56 , V_143 , V_7 ) ;
if ( V_85 ) {
F_128 ( V_65 ) ;
if ( V_85 == - V_272 )
goto V_32;
goto V_35;
}
F_123 ( V_65 ) ;
F_8 ( & V_12 -> V_273 ) ;
V_12 -> V_274 += F_334 ( V_41 ) ;
F_2 ( & V_12 -> V_273 ) ;
} else {
F_335 ( V_65 ) ;
if ( F_67 ( F_321 ( V_15 ) ) ) {
V_10 = V_265 ;
goto V_275;
}
V_269 = 1 ;
}
} else {
if ( F_67 ( F_336 ( V_65 ) ) ) {
V_10 = V_276 |
F_337 ( F_125 ( V_41 ) ) ;
goto V_275;
}
}
if ( ( V_61 & V_277 ) && ! ( V_15 -> V_53 & V_242 ) )
if ( F_161 ( V_41 , V_15 , V_42 ) < 0 ) {
V_10 = V_265 ;
goto V_275;
}
V_254 = F_280 ( V_41 , V_252 , V_229 ) ;
F_8 ( V_254 ) ;
V_115 = F_331 ( V_56 -> V_58 ) >> F_30 ( V_41 ) ;
if ( V_143 >= V_115 )
goto V_278;
V_10 = 0 ;
if ( ! F_268 ( F_264 ( V_229 ) ) )
goto V_278;
if ( V_269 ) {
F_123 ( V_65 ) ;
F_325 ( V_65 , V_15 , V_42 ) ;
} else
F_290 ( V_65 ) ;
V_270 = F_255 ( V_15 , V_65 , ( ( V_15 -> V_53 & V_279 )
&& ( V_15 -> V_53 & V_242 ) ) ) ;
F_285 ( V_252 , V_42 , V_229 , V_270 ) ;
if ( ( V_61 & V_277 ) && ! ( V_15 -> V_53 & V_242 ) ) {
V_10 = F_313 ( V_252 , V_15 , V_42 , V_229 , V_270 , V_65 , V_254 ) ;
}
F_2 ( V_254 ) ;
F_338 ( V_65 ) ;
V_35:
return V_10 ;
V_278:
F_2 ( V_254 ) ;
V_275:
F_338 ( V_65 ) ;
F_128 ( V_65 ) ;
goto V_35;
}
static T_13 F_339 ( struct V_40 * V_41 , struct V_232 * V_252 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
T_1 V_143 , unsigned long V_42 )
{
unsigned long V_280 [ 2 ] ;
T_13 V_281 ;
if ( V_15 -> V_53 & V_242 ) {
V_280 [ 0 ] = ( unsigned long ) V_56 ;
V_280 [ 1 ] = V_143 ;
} else {
V_280 [ 0 ] = ( unsigned long ) V_252 ;
V_280 [ 1 ] = V_42 >> F_30 ( V_41 ) ;
}
V_281 = F_340 ( ( T_13 * ) & V_280 , sizeof( V_280 ) / sizeof( T_13 ) , 0 ) ;
return V_281 & ( V_199 - 1 ) ;
}
static T_13 F_339 ( struct V_40 * V_41 , struct V_232 * V_252 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
T_1 V_143 , unsigned long V_42 )
{
return 0 ;
}
int F_341 ( struct V_232 * V_252 , struct V_14 * V_15 ,
unsigned long V_42 , unsigned int V_61 )
{
T_10 * V_229 , V_227 ;
T_12 * V_254 ;
int V_10 ;
T_13 V_281 ;
T_1 V_143 ;
struct V_65 * V_65 = NULL ;
struct V_65 * V_260 = NULL ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_55 * V_56 ;
V_42 &= F_293 ( V_41 ) ;
V_229 = F_277 ( V_252 , V_42 ) ;
if ( V_229 ) {
V_227 = F_264 ( V_229 ) ;
if ( F_67 ( F_267 ( V_227 ) ) ) {
F_342 ( V_15 , V_252 , V_229 ) ;
return 0 ;
} else if ( F_67 ( F_273 ( V_227 ) ) )
return V_282 |
F_337 ( F_125 ( V_41 ) ) ;
}
V_229 = F_278 ( V_252 , V_42 , F_116 ( V_41 ) ) ;
if ( ! V_229 )
return V_265 ;
V_56 = V_15 -> V_16 -> V_57 ;
V_143 = F_29 ( V_41 , V_15 , V_42 ) ;
V_281 = F_339 ( V_41 , V_252 , V_15 , V_56 , V_143 , V_42 ) ;
F_343 ( & V_192 [ V_281 ] ) ;
V_227 = F_264 ( V_229 ) ;
if ( F_268 ( V_227 ) ) {
V_10 = F_330 ( V_252 , V_15 , V_56 , V_143 , V_42 , V_229 , V_61 ) ;
goto V_283;
}
V_10 = 0 ;
if ( ( V_61 & V_277 ) && ! F_344 ( V_227 ) ) {
if ( F_161 ( V_41 , V_15 , V_42 ) < 0 ) {
V_10 = V_265 ;
goto V_283;
}
if ( ! ( V_15 -> V_53 & V_54 ) )
V_260 = F_326 ( V_41 ,
V_15 , V_42 ) ;
}
V_65 = F_288 ( V_227 ) ;
F_289 ( V_65 ) ;
if ( V_65 != V_260 )
F_335 ( V_65 ) ;
V_254 = F_280 ( V_41 , V_252 , V_229 ) ;
F_8 ( V_254 ) ;
if ( F_67 ( ! F_319 ( V_227 , F_264 ( V_229 ) ) ) )
goto V_284;
if ( V_61 & V_277 ) {
if ( ! F_344 ( V_227 ) ) {
V_10 = F_313 ( V_252 , V_15 , V_42 , V_229 , V_227 ,
V_260 , V_254 ) ;
goto V_284;
}
V_227 = F_257 ( V_227 ) ;
}
V_227 = F_260 ( V_227 ) ;
if ( F_265 ( V_15 , V_42 , V_229 , V_227 ,
V_61 & V_277 ) )
F_266 ( V_15 , V_42 , V_229 ) ;
V_284:
F_2 ( V_254 ) ;
if ( V_260 ) {
F_338 ( V_260 ) ;
F_128 ( V_260 ) ;
}
if ( V_65 != V_260 )
F_338 ( V_65 ) ;
F_128 ( V_65 ) ;
V_283:
F_345 ( & V_192 [ V_281 ] ) ;
return V_10 ;
}
long F_346 ( struct V_232 * V_252 , struct V_14 * V_15 ,
struct V_65 * * V_285 , struct V_14 * * V_286 ,
unsigned long * V_287 , unsigned long * V_93 ,
long V_92 , unsigned int V_61 )
{
unsigned long V_288 ;
unsigned long V_289 = * V_287 ;
unsigned long V_290 = * V_93 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
while ( V_289 < V_15 -> V_223 && V_290 ) {
T_10 * V_230 ;
T_12 * V_254 = NULL ;
int V_291 ;
struct V_65 * V_65 ;
V_230 = F_277 ( V_252 , V_289 & F_293 ( V_41 ) ) ;
if ( V_230 )
V_254 = F_279 ( V_41 , V_252 , V_230 ) ;
V_291 = ! V_230 || F_268 ( F_264 ( V_230 ) ) ;
if ( V_291 && ( V_61 & V_292 ) &&
! F_328 ( V_41 , V_15 , V_289 ) ) {
if ( V_230 )
F_2 ( V_254 ) ;
V_290 = 0 ;
break;
}
if ( V_291 || F_347 ( F_264 ( V_230 ) ) ||
( ( V_61 & V_293 ) &&
! F_344 ( F_264 ( V_230 ) ) ) ) {
int V_10 ;
if ( V_230 )
F_2 ( V_254 ) ;
V_10 = F_341 ( V_252 , V_15 , V_289 ,
( V_61 & V_293 ) ? V_277 : 0 ) ;
if ( ! ( V_10 & V_294 ) )
continue;
V_290 = 0 ;
break;
}
V_288 = ( V_289 & ~ F_293 ( V_41 ) ) >> V_156 ;
V_65 = F_288 ( F_264 ( V_230 ) ) ;
V_295:
if ( V_285 ) {
V_285 [ V_92 ] = F_348 ( V_65 , V_288 ) ;
F_349 ( V_285 [ V_92 ] ) ;
}
if ( V_286 )
V_286 [ V_92 ] = V_15 ;
V_289 += V_45 ;
++ V_288 ;
-- V_290 ;
++ V_92 ;
if ( V_289 < V_15 -> V_223 && V_290 &&
V_288 < F_108 ( V_41 ) ) {
goto V_295;
}
F_2 ( V_254 ) ;
}
* V_93 = V_290 ;
* V_287 = V_289 ;
return V_92 ? V_92 : - V_296 ;
}
unsigned long F_350 ( struct V_14 * V_15 ,
unsigned long V_42 , unsigned long V_36 , T_14 V_297 )
{
struct V_232 * V_252 = V_15 -> V_253 ;
unsigned long V_222 = V_42 ;
T_10 * V_229 ;
T_10 V_230 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
unsigned long V_285 = 0 ;
F_9 ( V_42 >= V_36 ) ;
F_351 ( V_15 , V_42 , V_36 ) ;
F_276 ( V_252 , V_222 , V_36 ) ;
F_310 ( V_15 -> V_16 -> V_57 ) ;
for (; V_42 < V_36 ; V_42 += F_116 ( V_41 ) ) {
T_12 * V_254 ;
V_229 = F_277 ( V_252 , V_42 ) ;
if ( ! V_229 )
continue;
V_254 = F_279 ( V_41 , V_252 , V_229 ) ;
if ( F_295 ( V_252 , & V_42 , V_229 ) ) {
V_285 ++ ;
F_2 ( V_254 ) ;
continue;
}
if ( ! F_268 ( F_264 ( V_229 ) ) ) {
V_230 = F_297 ( V_252 , V_42 , V_229 ) ;
V_230 = F_261 ( F_352 ( V_230 , V_297 ) ) ;
V_230 = F_262 ( V_230 , V_15 , NULL , 0 ) ;
F_285 ( V_252 , V_42 , V_229 , V_230 ) ;
V_285 ++ ;
}
F_2 ( V_254 ) ;
}
F_353 ( V_15 , V_222 , V_36 ) ;
F_287 ( V_252 , V_222 , V_36 ) ;
F_312 ( V_15 -> V_16 -> V_57 ) ;
F_291 ( V_252 , V_222 , V_36 ) ;
return V_285 << V_41 -> V_91 ;
}
int F_354 ( struct V_12 * V_12 ,
long V_29 , long V_28 ,
struct V_14 * V_15 ,
T_15 V_53 )
{
long V_10 , V_31 ;
struct V_40 * V_41 = F_355 ( V_12 ) ;
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
goto V_298;
}
if ( F_10 ( V_2 , V_31 ) ) {
V_10 = - V_146 ;
goto V_298;
}
V_10 = F_249 ( V_41 , V_31 ) ;
if ( V_10 < 0 ) {
F_11 ( V_2 , V_31 ) ;
goto V_298;
}
if ( ! V_15 || V_15 -> V_53 & V_54 )
F_16 ( V_17 , V_29 , V_28 ) ;
return 0 ;
V_298:
if ( V_15 && F_48 ( V_15 , V_64 ) )
F_253 ( & V_17 -> V_48 , F_41 ) ;
return V_10 ;
}
void F_356 ( struct V_12 * V_12 , long V_299 , long V_300 )
{
struct V_40 * V_41 = F_355 ( V_12 ) ;
struct V_17 * V_17 = F_43 ( V_12 ) ;
long V_31 = 0 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( V_17 )
V_31 = F_23 ( V_17 , V_299 ) ;
F_8 ( & V_12 -> V_273 ) ;
V_12 -> V_274 -= ( F_334 ( V_41 ) * V_300 ) ;
F_2 ( & V_12 -> V_273 ) ;
F_11 ( V_2 , ( V_31 - V_300 ) ) ;
F_249 ( V_41 , - ( V_31 - V_300 ) ) ;
}
static unsigned long F_357 ( struct V_14 * V_301 ,
struct V_14 * V_15 ,
unsigned long V_142 , T_1 V_143 )
{
unsigned long V_302 = ( ( V_143 - V_301 -> V_44 ) << V_156 ) +
V_301 -> V_43 ;
unsigned long V_303 = V_302 & V_304 ;
unsigned long V_305 = V_303 + V_306 ;
unsigned long V_53 = V_15 -> V_53 & ~ V_307 ;
unsigned long V_308 = V_301 -> V_53 & ~ V_307 ;
if ( F_358 ( V_142 ) != F_358 ( V_302 ) ||
V_53 != V_308 ||
V_303 < V_301 -> V_43 || V_301 -> V_223 < V_305 )
return 0 ;
return V_302 ;
}
static int F_359 ( struct V_14 * V_15 , unsigned long V_142 )
{
unsigned long V_309 = V_142 & V_304 ;
unsigned long V_36 = V_309 + V_306 ;
if ( V_15 -> V_53 & V_54 &&
V_15 -> V_43 <= V_309 && V_36 <= V_15 -> V_223 )
return 1 ;
return 0 ;
}
T_10 * F_360 ( struct V_232 * V_252 , unsigned long V_142 , T_16 * V_310 )
{
struct V_14 * V_15 = F_361 ( V_252 , V_142 ) ;
struct V_55 * V_56 = V_15 -> V_16 -> V_57 ;
T_1 V_143 = ( ( V_142 - V_15 -> V_43 ) >> V_156 ) +
V_15 -> V_44 ;
struct V_14 * V_301 ;
unsigned long V_302 ;
T_10 * V_311 = NULL ;
T_10 * V_230 ;
T_12 * V_254 ;
if ( ! F_359 ( V_15 , V_142 ) )
return ( T_10 * ) F_362 ( V_252 , V_310 , V_142 ) ;
F_310 ( V_56 ) ;
F_311 (svma, &mapping->i_mmap, idx, idx) {
if ( V_301 == V_15 )
continue;
V_302 = F_357 ( V_301 , V_15 , V_142 , V_143 ) ;
if ( V_302 ) {
V_311 = F_277 ( V_301 -> V_253 , V_302 ) ;
if ( V_311 ) {
F_289 ( F_179 ( V_311 ) ) ;
break;
}
}
}
if ( ! V_311 )
goto V_35;
V_254 = F_280 ( F_33 ( V_15 ) , V_252 , V_311 ) ;
F_8 ( V_254 ) ;
if ( F_363 ( * V_310 ) )
F_364 ( V_252 , V_310 ,
( V_312 * ) ( ( unsigned long ) V_311 & V_313 ) ) ;
else
F_128 ( F_179 ( V_311 ) ) ;
F_2 ( V_254 ) ;
V_35:
V_230 = ( T_10 * ) F_362 ( V_252 , V_310 , V_142 ) ;
F_312 ( V_56 ) ;
return V_230 ;
}
int F_295 ( struct V_232 * V_252 , unsigned long * V_142 , T_10 * V_229 )
{
T_17 * V_314 = F_365 ( V_252 , * V_142 ) ;
T_16 * V_310 = F_366 ( V_314 , * V_142 ) ;
F_9 ( F_91 ( F_179 ( V_229 ) ) == 0 ) ;
if ( F_91 ( F_179 ( V_229 ) ) == 1 )
return 0 ;
F_367 ( V_310 ) ;
F_128 ( F_179 ( V_229 ) ) ;
* V_142 = F_98 ( * V_142 , V_194 * V_315 ) - V_194 ;
return 1 ;
}
T_10 * F_360 ( struct V_232 * V_252 , unsigned long V_142 , T_16 * V_310 )
{
return NULL ;
}
T_10 * F_278 ( struct V_232 * V_252 ,
unsigned long V_142 , unsigned long V_239 )
{
T_17 * V_314 ;
T_16 * V_310 ;
T_10 * V_230 = NULL ;
V_314 = F_365 ( V_252 , V_142 ) ;
V_310 = F_368 ( V_252 , V_314 , V_142 ) ;
if ( V_310 ) {
if ( V_239 == V_306 ) {
V_230 = ( T_10 * ) V_310 ;
} else {
F_9 ( V_239 != V_316 ) ;
if ( F_369 () && F_363 ( * V_310 ) )
V_230 = F_360 ( V_252 , V_142 , V_310 ) ;
else
V_230 = ( T_10 * ) F_362 ( V_252 , V_310 , V_142 ) ;
}
}
F_9 ( V_230 && ! F_370 ( * V_230 ) && ! F_371 ( * V_230 ) ) ;
return V_230 ;
}
T_10 * F_277 ( struct V_232 * V_252 , unsigned long V_142 )
{
T_17 * V_314 ;
T_16 * V_310 ;
V_312 * V_317 = NULL ;
V_314 = F_365 ( V_252 , V_142 ) ;
if ( F_372 ( * V_314 ) ) {
V_310 = F_366 ( V_314 , V_142 ) ;
if ( F_373 ( * V_310 ) ) {
if ( F_374 ( * V_310 ) )
return ( T_10 * ) V_310 ;
V_317 = F_375 ( V_310 , V_142 ) ;
}
}
return ( T_10 * ) V_317 ;
}
struct V_65 *
F_376 ( struct V_232 * V_252 , unsigned long V_42 ,
V_312 * V_317 , int V_212 )
{
struct V_65 * V_65 ;
V_65 = F_288 ( * ( T_10 * ) V_317 ) ;
if ( V_65 )
V_65 += ( ( V_42 & ~ V_318 ) >> V_156 ) ;
return V_65 ;
}
struct V_65 *
F_377 ( struct V_232 * V_252 , unsigned long V_42 ,
T_16 * V_310 , int V_212 )
{
struct V_65 * V_65 ;
V_65 = F_288 ( * ( T_10 * ) V_310 ) ;
if ( V_65 )
V_65 += ( ( V_42 & ~ V_304 ) >> V_156 ) ;
return V_65 ;
}
struct V_65 * __weak
F_377 ( struct V_232 * V_252 , unsigned long V_42 ,
T_16 * V_310 , int V_212 )
{
F_219 () ;
return NULL ;
}
static int F_378 ( struct V_65 * V_319 )
{
struct V_65 * V_65 ;
struct V_65 * V_135 ;
struct V_40 * V_41 = F_118 ( V_319 ) ;
int V_66 = F_52 ( V_319 ) ;
F_18 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_65 == V_319 )
return 1 ;
return 0 ;
}
int F_379 ( struct V_65 * V_319 )
{
struct V_40 * V_41 = F_118 ( V_319 ) ;
int V_66 = F_52 ( V_319 ) ;
int V_10 = - V_320 ;
F_8 ( & V_117 ) ;
if ( F_378 ( V_319 ) ) {
F_380 ( & V_319 -> V_67 ) ;
F_56 ( V_319 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ V_66 ] -- ;
V_10 = 0 ;
}
F_2 ( & V_117 ) ;
return V_10 ;
}
bool F_381 ( struct V_65 * V_65 , struct V_21 * V_153 )
{
F_109 ( ! F_137 ( V_65 ) , V_65 ) ;
if ( ! F_382 ( V_65 ) )
return false ;
F_8 ( & V_117 ) ;
F_383 ( & V_65 -> V_67 , V_153 ) ;
F_2 ( & V_117 ) ;
return true ;
}
void F_384 ( struct V_65 * V_65 )
{
F_109 ( ! F_137 ( V_65 ) , V_65 ) ;
F_8 ( & V_117 ) ;
F_383 ( & V_65 -> V_67 , & ( F_118 ( V_65 ) ) -> V_71 ) ;
F_2 ( & V_117 ) ;
F_128 ( V_65 ) ;
}
bool F_385 ( struct V_65 * V_65 )
{
F_109 ( ! F_92 ( V_65 ) , V_65 ) ;
if ( F_386 ( V_65 ) )
return false ;
if ( F_67 ( F_336 ( V_65 ) ) )
return false ;
return F_91 ( V_65 ) > 0 ;
}
