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
struct V_21 * V_22 , * V_23 , * V_24 ;
F_17 (rg, head, link)
if ( V_19 <= V_22 -> V_25 )
break;
if ( V_19 > V_22 -> V_26 )
V_19 = V_22 -> V_26 ;
V_23 = V_22 ;
F_18 (rg, trg, rg->link.prev, link) {
if ( & V_22 -> V_27 == V_18 )
break;
if ( V_22 -> V_26 > V_20 )
break;
if ( V_22 -> V_25 > V_20 )
V_20 = V_22 -> V_25 ;
if ( V_22 != V_23 ) {
F_19 ( & V_22 -> V_27 ) ;
F_3 ( V_22 ) ;
}
}
V_23 -> V_26 = V_19 ;
V_23 -> V_25 = V_20 ;
return 0 ;
}
static long F_20 ( struct V_17 * V_18 , long V_19 , long V_20 )
{
struct V_21 * V_22 , * V_23 ;
long V_28 = 0 ;
F_17 (rg, head, link)
if ( V_19 <= V_22 -> V_25 )
break;
if ( & V_22 -> V_27 == V_18 || V_20 < V_22 -> V_26 ) {
V_23 = F_5 ( sizeof( * V_23 ) , V_7 ) ;
if ( ! V_23 )
return - V_11 ;
V_23 -> V_26 = V_19 ;
V_23 -> V_25 = V_19 ;
F_21 ( & V_23 -> V_27 ) ;
F_22 ( & V_23 -> V_27 , V_22 -> V_27 . V_29 ) ;
return V_20 - V_19 ;
}
if ( V_19 > V_22 -> V_26 )
V_19 = V_22 -> V_26 ;
V_28 = V_20 - V_19 ;
F_17 (rg, rg->link.prev, link) {
if ( & V_22 -> V_27 == V_18 )
break;
if ( V_22 -> V_26 > V_20 )
return V_28 ;
if ( V_22 -> V_25 > V_20 ) {
V_28 += V_22 -> V_25 - V_20 ;
V_20 = V_22 -> V_25 ;
}
V_28 -= V_22 -> V_25 - V_22 -> V_26 ;
}
return V_28 ;
}
static long F_23 ( struct V_17 * V_18 , long V_30 )
{
struct V_21 * V_22 , * V_24 ;
long V_28 = 0 ;
F_17 (rg, head, link)
if ( V_30 <= V_22 -> V_25 )
break;
if ( & V_22 -> V_27 == V_18 )
return 0 ;
if ( V_30 > V_22 -> V_26 ) {
V_28 = V_22 -> V_25 - V_30 ;
V_22 -> V_25 = V_30 ;
V_22 = F_24 ( V_22 -> V_27 . V_31 , F_25 ( * V_22 ) , V_27 ) ;
}
F_18 (rg, trg, rg->link.prev, link) {
if ( & V_22 -> V_27 == V_18 )
break;
V_28 += V_22 -> V_25 - V_22 -> V_26 ;
F_19 ( & V_22 -> V_27 ) ;
F_3 ( V_22 ) ;
}
return V_28 ;
}
static long F_26 ( struct V_17 * V_18 , long V_19 , long V_20 )
{
struct V_21 * V_22 ;
long V_28 = 0 ;
F_17 (rg, head, link) {
long V_32 ;
long V_33 ;
if ( V_22 -> V_25 <= V_19 )
continue;
if ( V_22 -> V_26 >= V_20 )
break;
V_32 = F_27 ( V_22 -> V_26 , V_19 ) ;
V_33 = F_28 ( V_22 -> V_25 , V_20 ) ;
V_28 += V_33 - V_32 ;
}
return V_28 ;
}
static T_1 F_29 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_36 )
{
return ( ( V_36 - V_15 -> V_37 ) >> F_30 ( V_35 ) ) +
( V_15 -> V_38 >> F_31 ( V_35 ) ) ;
}
T_1 F_32 ( struct V_14 * V_15 ,
unsigned long V_36 )
{
return F_29 ( F_33 ( V_15 ) , V_15 , V_36 ) ;
}
unsigned long F_34 ( struct V_14 * V_15 )
{
struct V_34 * V_34 ;
if ( ! F_35 ( V_15 ) )
return V_39 ;
V_34 = F_33 ( V_15 ) ;
return 1UL << F_30 ( V_34 ) ;
}
unsigned long F_36 ( struct V_14 * V_15 )
{
return F_34 ( V_15 ) ;
}
static unsigned long F_37 ( struct V_14 * V_15 )
{
return ( unsigned long ) V_15 -> V_40 ;
}
static void F_38 ( struct V_14 * V_15 ,
unsigned long V_41 )
{
V_15 -> V_40 = ( void * ) V_41 ;
}
static struct V_42 * F_39 ( void )
{
struct V_42 * V_42 = F_5 ( sizeof( * V_42 ) , V_7 ) ;
if ( ! V_42 )
return NULL ;
F_40 ( & V_42 -> V_43 ) ;
F_21 ( & V_42 -> V_44 ) ;
return V_42 ;
}
static void F_41 ( struct V_45 * V_46 )
{
struct V_42 * V_42 = F_42 ( V_46 , struct V_42 , V_43 ) ;
F_23 ( & V_42 -> V_44 , 0 ) ;
F_3 ( V_42 ) ;
}
static struct V_42 * F_43 ( struct V_14 * V_15 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
if ( ! ( V_15 -> V_47 & V_48 ) )
return (struct V_42 * ) ( F_37 ( V_15 ) &
~ V_49 ) ;
return NULL ;
}
static void F_45 ( struct V_14 * V_15 , struct V_42 * V_50 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
F_44 ( V_15 -> V_47 & V_48 ) ;
F_38 ( V_15 , ( F_37 ( V_15 ) &
V_49 ) | ( unsigned long ) V_50 ) ;
}
static void F_46 ( struct V_14 * V_15 , unsigned long V_51 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
F_44 ( V_15 -> V_47 & V_48 ) ;
F_38 ( V_15 , F_37 ( V_15 ) | V_51 ) ;
}
static int F_47 ( struct V_14 * V_15 , unsigned long V_52 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
return ( F_37 ( V_15 ) & V_52 ) != 0 ;
}
void F_48 ( struct V_14 * V_15 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
if ( ! ( V_15 -> V_47 & V_48 ) )
V_15 -> V_40 = ( void * ) 0 ;
}
static int F_49 ( struct V_14 * V_15 , long V_28 )
{
if ( V_15 -> V_47 & V_53 ) {
if ( V_15 -> V_47 & V_48 && V_28 == 0 )
return 1 ;
else
return 0 ;
}
if ( V_15 -> V_47 & V_48 )
return 1 ;
if ( F_47 ( V_15 , V_54 ) )
return 1 ;
return 0 ;
}
static void F_50 ( struct V_34 * V_35 , struct V_55 * V_55 )
{
int V_56 = F_51 ( V_55 ) ;
F_52 ( & V_55 -> V_57 , & V_35 -> V_58 [ V_56 ] ) ;
V_35 -> V_59 ++ ;
V_35 -> V_60 [ V_56 ] ++ ;
}
static struct V_55 * F_53 ( struct V_34 * V_35 , int V_56 )
{
struct V_55 * V_55 ;
F_17 (page, &h->hugepage_freelists[nid], lru)
if ( ! F_54 ( V_55 ) )
break;
if ( & V_35 -> V_58 [ V_56 ] == & V_55 -> V_57 )
return NULL ;
F_52 ( & V_55 -> V_57 , & V_35 -> V_61 ) ;
F_55 ( V_55 ) ;
V_35 -> V_59 -- ;
V_35 -> V_60 [ V_56 ] -- ;
return V_55 ;
}
static inline T_2 F_56 ( struct V_34 * V_35 )
{
if ( V_62 || F_57 ( V_35 ) )
return V_63 ;
else
return V_64 ;
}
static struct V_55 * F_58 ( struct V_34 * V_35 ,
struct V_14 * V_15 ,
unsigned long V_36 , int V_65 ,
long V_28 )
{
struct V_55 * V_55 = NULL ;
struct V_66 * V_67 ;
T_3 * V_68 ;
struct V_69 * V_69 ;
struct V_70 * V_70 ;
struct V_71 * V_72 ;
unsigned int V_73 ;
if ( ! F_49 ( V_15 , V_28 ) &&
V_35 -> V_59 - V_35 -> V_74 == 0 )
goto V_75;
if ( V_65 && V_35 -> V_59 - V_35 -> V_74 == 0 )
goto V_75;
V_76:
V_73 = F_59 () ;
V_69 = F_60 ( V_15 , V_36 ,
F_56 ( V_35 ) , & V_67 , & V_68 ) ;
F_61 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_62 ( V_70 , F_56 ( V_35 ) ) ) {
V_55 = F_53 ( V_35 , F_63 ( V_70 ) ) ;
if ( V_55 ) {
if ( V_65 )
break;
if ( ! F_49 ( V_15 , V_28 ) )
break;
F_64 ( V_55 ) ;
V_35 -> V_74 -- ;
break;
}
}
}
F_65 ( V_67 ) ;
if ( F_66 ( ! F_67 ( V_73 ) && ! V_55 ) )
goto V_76;
return V_55 ;
V_75:
return NULL ;
}
static void F_68 ( struct V_34 * V_35 , struct V_55 * V_55 )
{
int V_77 ;
F_44 ( V_35 -> V_78 >= V_79 ) ;
V_35 -> V_80 -- ;
V_35 -> V_81 [ F_51 ( V_55 ) ] -- ;
for ( V_77 = 0 ; V_77 < F_69 ( V_35 ) ; V_77 ++ ) {
V_55 [ V_77 ] . V_51 &= ~ ( 1 << V_82 | 1 << V_83 |
1 << V_84 | 1 << V_85 |
1 << V_86 | 1 << V_87 |
1 << V_88 | 1 << V_89 ) ;
}
F_70 ( F_71 ( V_55 ) , V_55 ) ;
F_72 ( V_55 , NULL ) ;
F_55 ( V_55 ) ;
F_73 ( V_55 ) ;
F_74 ( V_55 , F_31 ( V_35 ) ) ;
}
struct V_34 * F_75 ( unsigned long V_90 )
{
struct V_34 * V_35 ;
F_76 (h) {
if ( F_77 ( V_35 ) == V_90 )
return V_35 ;
}
return NULL ;
}
static void F_78 ( struct V_55 * V_55 )
{
struct V_34 * V_35 = F_79 ( V_55 ) ;
int V_56 = F_51 ( V_55 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_80 ( V_55 ) ;
bool V_91 ;
F_81 ( V_55 , 0 ) ;
V_55 -> V_92 = NULL ;
F_9 ( F_82 ( V_55 ) ) ;
F_9 ( F_83 ( V_55 ) ) ;
V_91 = F_84 ( V_55 ) ;
F_85 ( V_55 ) ;
F_8 ( & V_93 ) ;
F_86 ( F_87 ( V_35 ) ,
F_69 ( V_35 ) , V_55 ) ;
if ( V_91 )
V_35 -> V_74 ++ ;
if ( V_35 -> V_94 [ V_56 ] && F_31 ( V_35 ) < V_79 ) {
F_19 ( & V_55 -> V_57 ) ;
F_68 ( V_35 , V_55 ) ;
V_35 -> V_95 -- ;
V_35 -> V_94 [ V_56 ] -- ;
} else {
F_88 ( V_55 ) ;
F_50 ( V_35 , V_55 ) ;
}
F_2 ( & V_93 ) ;
F_11 ( V_2 , 1 ) ;
}
static void F_89 ( struct V_34 * V_35 , struct V_55 * V_55 , int V_56 )
{
F_21 ( & V_55 -> V_57 ) ;
F_72 ( V_55 , F_78 ) ;
F_8 ( & V_93 ) ;
F_90 ( V_55 , NULL ) ;
V_35 -> V_80 ++ ;
V_35 -> V_81 [ V_56 ] ++ ;
F_2 ( & V_93 ) ;
F_91 ( V_55 ) ;
}
static void F_92 ( struct V_55 * V_55 , unsigned long V_78 )
{
int V_77 ;
int V_96 = 1 << V_78 ;
struct V_55 * V_97 = V_55 + 1 ;
F_93 ( V_55 , V_78 ) ;
F_94 ( V_55 ) ;
F_95 ( V_55 ) ;
for ( V_77 = 1 ; V_77 < V_96 ; V_77 ++ , V_97 = F_96 ( V_97 , V_55 , V_77 ) ) {
F_97 ( V_97 ) ;
F_95 ( V_97 ) ;
F_98 ( V_97 , 0 ) ;
V_97 -> V_98 = V_55 ;
}
}
int F_99 ( struct V_55 * V_55 )
{
if ( ! F_100 ( V_55 ) )
return 0 ;
V_55 = F_101 ( V_55 ) ;
return F_102 ( V_55 ) == F_78 ;
}
int F_103 ( struct V_55 * V_99 )
{
if ( ! F_104 ( V_99 ) )
return 0 ;
return F_102 ( V_99 ) == F_78 ;
}
T_1 F_105 ( struct V_55 * V_55 )
{
struct V_55 * V_99 = F_101 ( V_55 ) ;
T_1 V_100 = F_106 ( V_99 ) ;
unsigned long V_101 ;
if ( ! F_99 ( V_99 ) )
return F_106 ( V_55 ) ;
if ( F_107 ( V_99 ) >= V_79 )
V_101 = F_108 ( V_55 ) - F_108 ( V_99 ) ;
else
V_101 = V_55 - V_99 ;
return ( V_100 << F_107 ( V_99 ) ) + V_101 ;
}
static struct V_55 * F_109 ( struct V_34 * V_35 , int V_56 )
{
struct V_55 * V_55 ;
if ( V_35 -> V_78 >= V_79 )
return NULL ;
V_55 = F_110 ( V_56 ,
F_56 ( V_35 ) | V_102 | V_103 |
V_104 | V_105 ,
F_31 ( V_35 ) ) ;
if ( V_55 ) {
if ( F_111 ( V_55 ) ) {
F_74 ( V_55 , F_31 ( V_35 ) ) ;
return NULL ;
}
F_89 ( V_35 , V_55 , V_56 ) ;
}
return V_55 ;
}
static int F_112 ( int V_56 , T_3 * V_106 )
{
V_56 = F_113 ( V_56 , * V_106 ) ;
if ( V_56 == V_107 )
V_56 = F_114 ( * V_106 ) ;
F_44 ( V_56 >= V_107 ) ;
return V_56 ;
}
static int F_115 ( int V_56 , T_3 * V_106 )
{
if ( ! F_116 ( V_56 , * V_106 ) )
V_56 = F_112 ( V_56 , V_106 ) ;
return V_56 ;
}
static int F_117 ( struct V_34 * V_35 ,
T_3 * V_106 )
{
int V_56 ;
F_44 ( ! V_106 ) ;
V_56 = F_115 ( V_35 -> V_108 , V_106 ) ;
V_35 -> V_108 = F_112 ( V_56 , V_106 ) ;
return V_56 ;
}
static int F_118 ( struct V_34 * V_35 , T_3 * V_106 )
{
int V_56 ;
F_44 ( ! V_106 ) ;
V_56 = F_115 ( V_35 -> V_109 , V_106 ) ;
V_35 -> V_109 = F_112 ( V_56 , V_106 ) ;
return V_56 ;
}
static int F_119 ( struct V_34 * V_35 , T_3 * V_106 )
{
struct V_55 * V_55 ;
int V_110 , V_111 ;
int V_10 = 0 ;
F_120 (h, nr_nodes, node, nodes_allowed) {
V_55 = F_109 ( V_35 , V_111 ) ;
if ( V_55 ) {
V_10 = 1 ;
break;
}
}
if ( V_10 )
F_121 ( V_112 ) ;
else
F_121 ( V_113 ) ;
return V_10 ;
}
static int F_122 ( struct V_34 * V_35 , T_3 * V_106 ,
bool V_114 )
{
int V_110 , V_111 ;
int V_10 = 0 ;
F_123 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_114 || V_35 -> V_94 [ V_111 ] ) &&
! F_124 ( & V_35 -> V_58 [ V_111 ] ) ) {
struct V_55 * V_55 =
F_24 ( V_35 -> V_58 [ V_111 ] . V_31 ,
struct V_55 , V_57 ) ;
F_19 ( & V_55 -> V_57 ) ;
V_35 -> V_59 -- ;
V_35 -> V_60 [ V_111 ] -- ;
if ( V_114 ) {
V_35 -> V_95 -- ;
V_35 -> V_94 [ V_111 ] -- ;
}
F_68 ( V_35 , V_55 ) ;
V_10 = 1 ;
break;
}
}
return V_10 ;
}
static void F_125 ( struct V_55 * V_55 )
{
F_8 ( & V_93 ) ;
if ( F_99 ( V_55 ) && ! F_82 ( V_55 ) ) {
struct V_34 * V_35 = F_79 ( V_55 ) ;
int V_56 = F_51 ( V_55 ) ;
F_19 ( & V_55 -> V_57 ) ;
V_35 -> V_59 -- ;
V_35 -> V_60 [ V_56 ] -- ;
F_68 ( V_35 , V_55 ) ;
}
F_2 ( & V_93 ) ;
}
void F_126 ( unsigned long V_115 , unsigned long V_116 )
{
unsigned int V_78 = 8 * sizeof( void * ) ;
unsigned long V_117 ;
struct V_34 * V_35 ;
F_76 (h)
if ( V_78 > F_31 ( V_35 ) )
V_78 = F_31 ( V_35 ) ;
F_44 ( ! F_127 ( V_115 , 1 << V_78 ) ) ;
for ( V_117 = V_115 ; V_117 < V_116 ; V_117 += 1 << V_78 )
F_125 ( F_128 ( V_117 ) ) ;
}
static struct V_55 * F_129 ( struct V_34 * V_35 , int V_56 )
{
struct V_55 * V_55 ;
unsigned int V_118 ;
if ( V_35 -> V_78 >= V_79 )
return NULL ;
F_8 ( & V_93 ) ;
if ( V_35 -> V_95 >= V_35 -> V_119 ) {
F_2 ( & V_93 ) ;
return NULL ;
} else {
V_35 -> V_80 ++ ;
V_35 -> V_95 ++ ;
}
F_2 ( & V_93 ) ;
if ( V_56 == V_120 )
V_55 = F_130 ( F_56 ( V_35 ) | V_102 |
V_104 | V_105 ,
F_31 ( V_35 ) ) ;
else
V_55 = F_110 ( V_56 ,
F_56 ( V_35 ) | V_102 | V_103 |
V_104 | V_105 , F_31 ( V_35 ) ) ;
if ( V_55 && F_111 ( V_55 ) ) {
F_74 ( V_55 , F_31 ( V_35 ) ) ;
V_55 = NULL ;
}
F_8 ( & V_93 ) ;
if ( V_55 ) {
F_21 ( & V_55 -> V_57 ) ;
V_118 = F_51 ( V_55 ) ;
F_72 ( V_55 , F_78 ) ;
F_90 ( V_55 , NULL ) ;
V_35 -> V_81 [ V_118 ] ++ ;
V_35 -> V_94 [ V_118 ] ++ ;
F_131 ( V_112 ) ;
} else {
V_35 -> V_80 -- ;
V_35 -> V_95 -- ;
F_131 ( V_113 ) ;
}
F_2 ( & V_93 ) ;
return V_55 ;
}
struct V_55 * F_132 ( struct V_34 * V_35 , int V_56 )
{
struct V_55 * V_55 = NULL ;
F_8 ( & V_93 ) ;
if ( V_35 -> V_59 - V_35 -> V_74 > 0 )
V_55 = F_53 ( V_35 , V_56 ) ;
F_2 ( & V_93 ) ;
if ( ! V_55 )
V_55 = F_129 ( V_35 , V_56 ) ;
return V_55 ;
}
static int F_133 ( struct V_34 * V_35 , int V_9 )
{
struct V_17 V_121 ;
struct V_55 * V_55 , * V_122 ;
int V_10 , V_77 ;
int V_123 , V_124 ;
bool V_125 = true ;
V_123 = ( V_35 -> V_74 + V_9 ) - V_35 -> V_59 ;
if ( V_123 <= 0 ) {
V_35 -> V_74 += V_9 ;
return 0 ;
}
V_124 = 0 ;
F_21 ( & V_121 ) ;
V_10 = - V_11 ;
V_126:
F_2 ( & V_93 ) ;
for ( V_77 = 0 ; V_77 < V_123 ; V_77 ++ ) {
V_55 = F_129 ( V_35 , V_120 ) ;
if ( ! V_55 ) {
V_125 = false ;
break;
}
F_22 ( & V_55 -> V_57 , & V_121 ) ;
}
V_124 += V_77 ;
F_8 ( & V_93 ) ;
V_123 = ( V_35 -> V_74 + V_9 ) -
( V_35 -> V_59 + V_124 ) ;
if ( V_123 > 0 ) {
if ( V_125 )
goto V_126;
goto free;
}
V_123 += V_124 ;
V_35 -> V_74 += V_9 ;
V_10 = 0 ;
F_18 (page, tmp, &surplus_list, lru) {
if ( ( -- V_123 ) < 0 )
break;
F_134 ( V_55 ) ;
F_70 ( F_82 ( V_55 ) , V_55 ) ;
F_50 ( V_35 , V_55 ) ;
}
free:
F_2 ( & V_93 ) ;
F_18 (page, tmp, &surplus_list, lru)
F_91 ( V_55 ) ;
F_8 ( & V_93 ) ;
return V_10 ;
}
static void F_135 ( struct V_34 * V_35 ,
unsigned long V_127 )
{
unsigned long V_96 ;
V_35 -> V_74 -= V_127 ;
if ( V_35 -> V_78 >= V_79 )
return;
V_96 = F_28 ( V_127 , V_35 -> V_95 ) ;
while ( V_96 -- ) {
if ( ! F_122 ( V_35 , & V_128 [ V_129 ] , 1 ) )
break;
}
}
static long F_136 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_130 )
{
struct V_131 * V_92 = V_15 -> V_16 -> V_132 ;
struct V_12 * V_12 = V_92 -> V_133 ;
if ( V_15 -> V_47 & V_48 ) {
T_1 V_134 = F_29 ( V_35 , V_15 , V_130 ) ;
return F_20 ( & V_12 -> V_135 -> V_136 ,
V_134 , V_134 + 1 ) ;
} else if ( ! F_47 ( V_15 , V_54 ) ) {
return 1 ;
} else {
long V_75 ;
T_1 V_134 = F_29 ( V_35 , V_15 , V_130 ) ;
struct V_42 * V_137 = F_43 ( V_15 ) ;
V_75 = F_20 ( & V_137 -> V_44 , V_134 , V_134 + 1 ) ;
if ( V_75 < 0 )
return V_75 ;
return 0 ;
}
}
static void F_137 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_130 )
{
struct V_131 * V_92 = V_15 -> V_16 -> V_132 ;
struct V_12 * V_12 = V_92 -> V_133 ;
if ( V_15 -> V_47 & V_48 ) {
T_1 V_134 = F_29 ( V_35 , V_15 , V_130 ) ;
F_16 ( & V_12 -> V_135 -> V_136 , V_134 , V_134 + 1 ) ;
} else if ( F_47 ( V_15 , V_54 ) ) {
T_1 V_134 = F_29 ( V_35 , V_15 , V_130 ) ;
struct V_42 * V_137 = F_43 ( V_15 ) ;
F_16 ( & V_137 -> V_44 , V_134 , V_134 + 1 ) ;
}
}
static struct V_55 * F_138 ( struct V_14 * V_15 ,
unsigned long V_130 , int V_65 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_55 * V_55 ;
long V_28 ;
int V_10 , V_134 ;
struct V_138 * V_139 ;
V_134 = F_87 ( V_35 ) ;
V_28 = F_136 ( V_35 , V_15 , V_130 ) ;
if ( V_28 < 0 )
return F_139 ( - V_11 ) ;
if ( V_28 || V_65 )
if ( F_10 ( V_2 , 1 ) )
return F_139 ( - V_140 ) ;
V_10 = F_140 ( V_134 , F_69 ( V_35 ) , & V_139 ) ;
if ( V_10 ) {
if ( V_28 || V_65 )
F_11 ( V_2 , 1 ) ;
return F_139 ( - V_140 ) ;
}
F_8 ( & V_93 ) ;
V_55 = F_58 ( V_35 , V_15 , V_130 , V_65 , V_28 ) ;
if ( ! V_55 ) {
F_2 ( & V_93 ) ;
V_55 = F_129 ( V_35 , V_120 ) ;
if ( ! V_55 ) {
F_141 ( V_134 ,
F_69 ( V_35 ) ,
V_139 ) ;
if ( V_28 || V_65 )
F_11 ( V_2 , 1 ) ;
return F_139 ( - V_140 ) ;
}
F_8 ( & V_93 ) ;
F_52 ( & V_55 -> V_57 , & V_35 -> V_61 ) ;
}
F_142 ( V_134 , F_69 ( V_35 ) , V_139 , V_55 ) ;
F_2 ( & V_93 ) ;
F_81 ( V_55 , ( unsigned long ) V_2 ) ;
F_137 ( V_35 , V_15 , V_130 ) ;
return V_55 ;
}
struct V_55 * F_143 ( struct V_14 * V_15 ,
unsigned long V_130 , int V_65 )
{
struct V_55 * V_55 = F_138 ( V_15 , V_130 , V_65 ) ;
if ( F_144 ( V_55 ) )
V_55 = NULL ;
return V_55 ;
}
int __weak F_145 ( struct V_34 * V_35 )
{
struct V_141 * V_142 ;
int V_110 , V_111 ;
F_120 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_130 ;
V_130 = F_146 (
F_77 ( V_35 ) , F_77 ( V_35 ) ,
0 , V_143 , V_111 ) ;
if ( V_130 ) {
V_142 = V_130 ;
goto V_144;
}
}
return 0 ;
V_144:
F_9 ( ( unsigned long ) F_147 ( V_142 ) & ( F_77 ( V_35 ) - 1 ) ) ;
F_22 ( & V_142 -> V_145 , & V_146 ) ;
V_142 -> V_34 = V_35 ;
return 1 ;
}
static void F_148 ( struct V_55 * V_55 , int V_78 )
{
if ( F_66 ( V_78 > ( V_79 - 1 ) ) )
F_92 ( V_55 , V_78 ) ;
else
F_149 ( V_55 , V_78 ) ;
}
static void T_4 F_150 ( void )
{
struct V_141 * V_142 ;
F_17 (m, &huge_boot_pages, list) {
struct V_34 * V_35 = V_142 -> V_34 ;
struct V_55 * V_55 ;
#ifdef F_151
V_55 = F_128 ( V_142 -> V_147 >> V_148 ) ;
F_152 ( F_153 ( V_142 ) ,
sizeof( struct V_141 ) ) ;
#else
V_55 = F_154 ( V_142 ) ;
#endif
F_155 ( F_82 ( V_55 ) != 1 ) ;
F_148 ( V_55 , V_35 -> V_78 ) ;
F_155 ( F_156 ( V_55 ) ) ;
F_89 ( V_35 , V_55 , F_51 ( V_55 ) ) ;
if ( V_35 -> V_78 > ( V_79 - 1 ) )
F_157 ( V_55 , 1 << V_35 -> V_78 ) ;
}
}
static void T_4 F_158 ( struct V_34 * V_35 )
{
unsigned long V_77 ;
for ( V_77 = 0 ; V_77 < V_35 -> V_149 ; ++ V_77 ) {
if ( V_35 -> V_78 >= V_79 ) {
if ( ! F_145 ( V_35 ) )
break;
} else if ( ! F_119 ( V_35 ,
& V_128 [ V_129 ] ) )
break;
}
V_35 -> V_149 = V_77 ;
}
static void T_4 F_159 ( void )
{
struct V_34 * V_35 ;
F_76 (h) {
if ( V_35 -> V_78 < V_79 )
F_158 ( V_35 ) ;
}
}
static char * T_4 F_160 ( char * V_150 , unsigned long V_151 )
{
if ( V_151 >= ( 1UL << 30 ) )
sprintf ( V_150 , L_1 , V_151 >> 30 ) ;
else if ( V_151 >= ( 1UL << 20 ) )
sprintf ( V_150 , L_2 , V_151 >> 20 ) ;
else
sprintf ( V_150 , L_3 , V_151 >> 10 ) ;
return V_150 ;
}
static void T_4 F_161 ( void )
{
struct V_34 * V_35 ;
F_76 (h) {
char V_150 [ 32 ] ;
F_162 ( L_4 ,
F_160 ( V_150 , F_77 ( V_35 ) ) ,
V_35 -> V_59 ) ;
}
}
static void F_163 ( struct V_34 * V_35 , unsigned long V_3 ,
T_3 * V_106 )
{
int V_77 ;
if ( V_35 -> V_78 >= V_79 )
return;
F_164 (i, *nodes_allowed) {
struct V_55 * V_55 , * V_31 ;
struct V_17 * V_152 = & V_35 -> V_58 [ V_77 ] ;
F_18 (page, next, freel, lru) {
if ( V_3 >= V_35 -> V_80 )
return;
if ( F_165 ( V_55 ) )
continue;
F_19 ( & V_55 -> V_57 ) ;
F_68 ( V_35 , V_55 ) ;
V_35 -> V_59 -- ;
V_35 -> V_60 [ F_51 ( V_55 ) ] -- ;
}
}
}
static inline void F_163 ( struct V_34 * V_35 , unsigned long V_3 ,
T_3 * V_106 )
{
}
static int F_166 ( struct V_34 * V_35 , T_3 * V_106 ,
int V_9 )
{
int V_110 , V_111 ;
F_44 ( V_9 != - 1 && V_9 != 1 ) ;
if ( V_9 < 0 ) {
F_120 (h, nr_nodes, node, nodes_allowed) {
if ( V_35 -> V_94 [ V_111 ] )
goto V_144;
}
} else {
F_123 (h, nr_nodes, node, nodes_allowed) {
if ( V_35 -> V_94 [ V_111 ] <
V_35 -> V_81 [ V_111 ] )
goto V_144;
}
}
return 0 ;
V_144:
V_35 -> V_95 += V_9 ;
V_35 -> V_94 [ V_111 ] += V_9 ;
return 1 ;
}
static unsigned long F_167 ( struct V_34 * V_35 , unsigned long V_3 ,
T_3 * V_106 )
{
unsigned long V_153 , V_10 ;
if ( V_35 -> V_78 >= V_79 )
return V_35 -> V_149 ;
F_8 ( & V_93 ) ;
while ( V_35 -> V_95 && V_3 > F_168 ( V_35 ) ) {
if ( ! F_166 ( V_35 , V_106 , - 1 ) )
break;
}
while ( V_3 > F_168 ( V_35 ) ) {
F_2 ( & V_93 ) ;
V_10 = F_119 ( V_35 , V_106 ) ;
F_8 ( & V_93 ) ;
if ( ! V_10 )
goto V_154;
if ( F_169 ( V_155 ) )
goto V_154;
}
V_153 = V_35 -> V_74 + V_35 -> V_80 - V_35 -> V_59 ;
V_153 = F_27 ( V_3 , V_153 ) ;
F_163 ( V_35 , V_153 , V_106 ) ;
while ( V_153 < F_168 ( V_35 ) ) {
if ( ! F_122 ( V_35 , V_106 , 0 ) )
break;
}
while ( V_3 < F_168 ( V_35 ) ) {
if ( ! F_166 ( V_35 , V_106 , 1 ) )
break;
}
V_154:
V_10 = F_168 ( V_35 ) ;
F_2 ( & V_93 ) ;
return V_10 ;
}
static struct V_34 * F_170 ( struct V_156 * V_157 , int * V_158 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_159 ; V_77 ++ )
if ( V_160 [ V_77 ] == V_157 ) {
if ( V_158 )
* V_158 = V_120 ;
return & V_161 [ V_77 ] ;
}
return F_171 ( V_157 , V_158 ) ;
}
static T_5 F_172 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 ;
unsigned long V_80 ;
int V_56 ;
V_35 = F_170 ( V_157 , & V_56 ) ;
if ( V_56 == V_120 )
V_80 = V_35 -> V_80 ;
else
V_80 = V_35 -> V_81 [ V_56 ] ;
return sprintf ( V_150 , L_5 , V_80 ) ;
}
static T_5 F_173 ( bool V_164 ,
struct V_156 * V_157 , struct V_162 * V_163 ,
const char * V_150 , T_6 V_165 )
{
int V_75 ;
int V_56 ;
unsigned long V_3 ;
struct V_34 * V_35 ;
F_174 ( T_3 , V_106 , V_7 | V_166 ) ;
V_75 = F_175 ( V_150 , 10 , & V_3 ) ;
if ( V_75 )
goto V_154;
V_35 = F_170 ( V_157 , & V_56 ) ;
if ( V_35 -> V_78 >= V_79 ) {
V_75 = - V_167 ;
goto V_154;
}
if ( V_56 == V_120 ) {
if ( ! ( V_164 &&
F_176 ( V_106 ) ) ) {
F_177 ( V_106 ) ;
V_106 = & V_128 [ V_129 ] ;
}
} else if ( V_106 ) {
V_3 += V_35 -> V_80 - V_35 -> V_81 [ V_56 ] ;
F_178 ( V_106 , V_56 ) ;
} else
V_106 = & V_128 [ V_129 ] ;
V_35 -> V_149 = F_167 ( V_35 , V_3 , V_106 ) ;
if ( V_106 != & V_128 [ V_129 ] )
F_177 ( V_106 ) ;
return V_165 ;
V_154:
F_177 ( V_106 ) ;
return V_75 ;
}
static T_5 F_179 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
return F_172 ( V_157 , V_163 , V_150 ) ;
}
static T_5 F_180 ( struct V_156 * V_157 ,
struct V_162 * V_163 , const char * V_150 , T_6 V_165 )
{
return F_173 ( false , V_157 , V_163 , V_150 , V_165 ) ;
}
static T_5 F_181 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
return F_172 ( V_157 , V_163 , V_150 ) ;
}
static T_5 F_182 ( struct V_156 * V_157 ,
struct V_162 * V_163 , const char * V_150 , T_6 V_165 )
{
return F_173 ( true , V_157 , V_163 , V_150 , V_165 ) ;
}
static T_5 F_183 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 = F_170 ( V_157 , NULL ) ;
return sprintf ( V_150 , L_5 , V_35 -> V_119 ) ;
}
static T_5 F_184 ( struct V_156 * V_157 ,
struct V_162 * V_163 , const char * V_150 , T_6 V_3 )
{
int V_75 ;
unsigned long V_168 ;
struct V_34 * V_35 = F_170 ( V_157 , NULL ) ;
if ( V_35 -> V_78 >= V_79 )
return - V_167 ;
V_75 = F_175 ( V_150 , 10 , & V_168 ) ;
if ( V_75 )
return V_75 ;
F_8 ( & V_93 ) ;
V_35 -> V_119 = V_168 ;
F_2 ( & V_93 ) ;
return V_3 ;
}
static T_5 F_185 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 ;
unsigned long V_59 ;
int V_56 ;
V_35 = F_170 ( V_157 , & V_56 ) ;
if ( V_56 == V_120 )
V_59 = V_35 -> V_59 ;
else
V_59 = V_35 -> V_60 [ V_56 ] ;
return sprintf ( V_150 , L_5 , V_59 ) ;
}
static T_5 F_186 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 = F_170 ( V_157 , NULL ) ;
return sprintf ( V_150 , L_5 , V_35 -> V_74 ) ;
}
static T_5 F_187 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 ;
unsigned long V_95 ;
int V_56 ;
V_35 = F_170 ( V_157 , & V_56 ) ;
if ( V_56 == V_120 )
V_95 = V_35 -> V_95 ;
else
V_95 = V_35 -> V_94 [ V_56 ] ;
return sprintf ( V_150 , L_5 , V_95 ) ;
}
static int F_188 ( struct V_34 * V_35 , struct V_156 * V_169 ,
struct V_156 * * V_160 ,
struct V_170 * V_171 )
{
int V_172 ;
int V_173 = F_87 ( V_35 ) ;
V_160 [ V_173 ] = F_189 ( V_35 -> V_174 , V_169 ) ;
if ( ! V_160 [ V_173 ] )
return - V_11 ;
V_172 = F_190 ( V_160 [ V_173 ] , V_171 ) ;
if ( V_172 )
F_191 ( V_160 [ V_173 ] ) ;
return V_172 ;
}
static void T_4 F_192 ( void )
{
struct V_34 * V_35 ;
int V_75 ;
V_175 = F_189 ( L_6 , V_176 ) ;
if ( ! V_175 )
return;
F_76 (h) {
V_75 = F_188 ( V_35 , V_175 ,
V_160 , & V_171 ) ;
if ( V_75 )
F_193 ( L_7 , V_35 -> V_174 ) ;
}
}
static struct V_34 * F_171 ( struct V_156 * V_157 , int * V_158 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_177 ; V_56 ++ ) {
struct V_178 * V_179 = & V_180 [ V_56 ] ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_159 ; V_77 ++ )
if ( V_179 -> V_160 [ V_77 ] == V_157 ) {
if ( V_158 )
* V_158 = V_56 ;
return & V_161 [ V_77 ] ;
}
}
F_194 () ;
return NULL ;
}
static void F_195 ( struct V_111 * V_111 )
{
struct V_34 * V_35 ;
struct V_178 * V_179 = & V_180 [ V_111 -> V_181 . V_182 ] ;
if ( ! V_179 -> V_175 )
return;
F_76 (h) {
int V_134 = F_87 ( V_35 ) ;
if ( V_179 -> V_160 [ V_134 ] ) {
F_191 ( V_179 -> V_160 [ V_134 ] ) ;
V_179 -> V_160 [ V_134 ] = NULL ;
}
}
F_191 ( V_179 -> V_175 ) ;
V_179 -> V_175 = NULL ;
}
static void F_196 ( void )
{
int V_56 ;
F_197 ( NULL , NULL ) ;
for ( V_56 = 0 ; V_56 < V_177 ; V_56 ++ )
F_195 ( V_183 [ V_56 ] ) ;
}
static void F_198 ( struct V_111 * V_111 )
{
struct V_34 * V_35 ;
struct V_178 * V_179 = & V_180 [ V_111 -> V_181 . V_182 ] ;
int V_75 ;
if ( V_179 -> V_175 )
return;
V_179 -> V_175 = F_189 ( L_6 ,
& V_111 -> V_181 . V_157 ) ;
if ( ! V_179 -> V_175 )
return;
F_76 (h) {
V_75 = F_188 ( V_35 , V_179 -> V_175 ,
V_179 -> V_160 ,
& V_184 ) ;
if ( V_75 ) {
F_193 ( L_8 ,
V_35 -> V_174 , V_111 -> V_181 . V_182 ) ;
F_195 ( V_111 ) ;
break;
}
}
}
static void F_199 ( void )
{
int V_56 ;
F_200 (nid, N_MEMORY) {
struct V_111 * V_111 = V_183 [ V_56 ] ;
if ( V_111 -> V_181 . V_182 == V_56 )
F_198 ( V_111 ) ;
}
F_197 ( F_198 ,
F_195 ) ;
}
static struct V_34 * F_171 ( struct V_156 * V_157 , int * V_158 )
{
F_194 () ;
if ( V_158 )
* V_158 = - 1 ;
return NULL ;
}
static void F_196 ( void ) { }
static void F_199 ( void ) { }
static void T_7 F_201 ( void )
{
struct V_34 * V_35 ;
F_196 () ;
F_76 (h) {
F_191 ( V_160 [ F_87 ( V_35 ) ] ) ;
}
F_191 ( V_175 ) ;
}
static int T_4 F_202 ( void )
{
if ( V_185 == 0 )
return 0 ;
if ( ! F_75 ( V_186 ) ) {
V_186 = V_187 ;
if ( ! F_75 ( V_186 ) )
F_203 ( V_188 ) ;
}
V_189 = F_87 ( F_75 ( V_186 ) ) ;
if ( V_190 )
V_191 . V_149 = V_190 ;
F_159 () ;
F_150 () ;
F_161 () ;
F_192 () ;
F_199 () ;
F_204 () ;
return 0 ;
}
void T_4 F_203 ( unsigned V_78 )
{
struct V_34 * V_35 ;
unsigned long V_77 ;
if ( F_75 ( V_39 << V_78 ) ) {
F_205 ( L_9 ) ;
return;
}
F_9 ( V_192 >= V_159 ) ;
F_9 ( V_78 == 0 ) ;
V_35 = & V_161 [ V_192 ++ ] ;
V_35 -> V_78 = V_78 ;
V_35 -> V_193 = ~ ( ( 1ULL << ( V_78 + V_148 ) ) - 1 ) ;
V_35 -> V_80 = 0 ;
V_35 -> V_59 = 0 ;
for ( V_77 = 0 ; V_77 < V_107 ; ++ V_77 )
F_21 ( & V_35 -> V_58 [ V_77 ] ) ;
F_21 ( & V_35 -> V_61 ) ;
V_35 -> V_108 = F_114 ( V_128 [ V_129 ] ) ;
V_35 -> V_109 = F_114 ( V_128 [ V_129 ] ) ;
snprintf ( V_35 -> V_174 , V_194 , L_10 ,
F_77 ( V_35 ) / 1024 ) ;
V_195 = V_35 ;
}
static int T_4 F_206 ( char * V_196 )
{
unsigned long * V_197 ;
static unsigned long * V_198 ;
if ( ! V_192 )
V_197 = & V_190 ;
else
V_197 = & V_195 -> V_149 ;
if ( V_197 == V_198 ) {
F_205 ( L_11
L_12 ) ;
return 1 ;
}
if ( sscanf ( V_196 , L_13 , V_197 ) <= 0 )
* V_197 = 0 ;
if ( V_192 && V_195 -> V_78 >= V_79 )
F_158 ( V_195 ) ;
V_198 = V_197 ;
return 1 ;
}
static int T_4 F_207 ( char * V_196 )
{
V_186 = F_208 ( V_196 , & V_196 ) ;
return 1 ;
}
static unsigned int F_209 ( unsigned int * V_199 )
{
int V_111 ;
unsigned int V_200 = 0 ;
F_164 (node, cpuset_current_mems_allowed)
V_200 += V_199 [ V_111 ] ;
return V_200 ;
}
static int F_210 ( bool V_164 ,
struct V_201 * V_202 , int V_203 ,
void T_8 * V_204 , T_6 * V_205 , T_9 * V_206 )
{
struct V_34 * V_35 = & V_191 ;
unsigned long V_122 ;
int V_10 ;
V_122 = V_35 -> V_149 ;
if ( V_203 && V_35 -> V_78 >= V_79 )
return - V_167 ;
V_202 -> V_207 = & V_122 ;
V_202 -> V_208 = sizeof( unsigned long ) ;
V_10 = F_211 ( V_202 , V_203 , V_204 , V_205 , V_206 ) ;
if ( V_10 )
goto V_154;
if ( V_203 ) {
F_174 ( T_3 , V_106 ,
V_7 | V_166 ) ;
if ( ! ( V_164 &&
F_176 ( V_106 ) ) ) {
F_177 ( V_106 ) ;
V_106 = & V_128 [ V_129 ] ;
}
V_35 -> V_149 = F_167 ( V_35 , V_122 , V_106 ) ;
if ( V_106 != & V_128 [ V_129 ] )
F_177 ( V_106 ) ;
}
V_154:
return V_10 ;
}
int F_212 ( struct V_201 * V_202 , int V_203 ,
void T_8 * V_204 , T_6 * V_205 , T_9 * V_206 )
{
return F_210 ( false , V_202 , V_203 ,
V_204 , V_205 , V_206 ) ;
}
int F_213 ( struct V_201 * V_202 , int V_203 ,
void T_8 * V_204 , T_6 * V_205 , T_9 * V_206 )
{
return F_210 ( true , V_202 , V_203 ,
V_204 , V_205 , V_206 ) ;
}
int F_214 ( struct V_201 * V_202 , int V_203 ,
void T_8 * V_204 ,
T_6 * V_205 , T_9 * V_206 )
{
struct V_34 * V_35 = & V_191 ;
unsigned long V_122 ;
int V_10 ;
V_122 = V_35 -> V_119 ;
if ( V_203 && V_35 -> V_78 >= V_79 )
return - V_167 ;
V_202 -> V_207 = & V_122 ;
V_202 -> V_208 = sizeof( unsigned long ) ;
V_10 = F_211 ( V_202 , V_203 , V_204 , V_205 , V_206 ) ;
if ( V_10 )
goto V_154;
if ( V_203 ) {
F_8 ( & V_93 ) ;
V_35 -> V_119 = V_122 ;
F_2 ( & V_93 ) ;
}
V_154:
return V_10 ;
}
void F_215 ( struct V_209 * V_142 )
{
struct V_34 * V_35 = & V_191 ;
F_216 ( V_142 ,
L_14
L_15
L_16
L_17
L_18 ,
V_35 -> V_80 ,
V_35 -> V_59 ,
V_35 -> V_74 ,
V_35 -> V_95 ,
1UL << ( F_31 ( V_35 ) + V_148 - 10 ) ) ;
}
int F_217 ( int V_56 , char * V_150 )
{
struct V_34 * V_35 = & V_191 ;
return sprintf ( V_150 ,
L_19
L_20
L_21 ,
V_56 , V_35 -> V_81 [ V_56 ] ,
V_56 , V_35 -> V_60 [ V_56 ] ,
V_56 , V_35 -> V_94 [ V_56 ] ) ;
}
void F_218 ( void )
{
struct V_34 * V_35 ;
int V_56 ;
F_200 (nid, N_MEMORY)
F_76 (h)
F_162 ( L_22 ,
V_56 ,
V_35 -> V_81 [ V_56 ] ,
V_35 -> V_60 [ V_56 ] ,
V_35 -> V_94 [ V_56 ] ,
1UL << ( F_31 ( V_35 ) + V_148 - 10 ) ) ;
}
unsigned long F_219 ( void )
{
struct V_34 * V_35 ;
unsigned long V_210 = 0 ;
F_76 (h)
V_210 += V_35 -> V_80 * F_69 ( V_35 ) ;
return V_210 ;
}
static int F_220 ( struct V_34 * V_35 , long V_9 )
{
int V_10 = - V_11 ;
F_8 ( & V_93 ) ;
if ( V_9 > 0 ) {
if ( F_133 ( V_35 , V_9 ) < 0 )
goto V_154;
if ( V_9 > F_209 ( V_35 -> V_60 ) ) {
F_135 ( V_35 , V_9 ) ;
goto V_154;
}
}
V_10 = 0 ;
if ( V_9 < 0 )
F_135 ( V_35 , ( unsigned long ) - V_9 ) ;
V_154:
F_2 ( & V_93 ) ;
return V_10 ;
}
static void F_221 ( struct V_14 * V_15 )
{
struct V_42 * V_137 = F_43 ( V_15 ) ;
if ( V_137 )
F_222 ( & V_137 -> V_43 ) ;
}
static void F_223 ( struct V_14 * V_15 )
{
struct V_42 * V_137 = F_43 ( V_15 ) ;
if ( ! V_137 )
return;
F_224 ( & V_137 -> V_43 , F_41 ) ;
}
static void F_225 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_42 * V_137 = F_43 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_15 ) ;
unsigned long V_211 ;
unsigned long V_212 ;
unsigned long V_30 ;
if ( V_137 ) {
V_212 = F_29 ( V_35 , V_15 , V_15 -> V_37 ) ;
V_30 = F_29 ( V_35 , V_15 , V_15 -> V_213 ) ;
V_211 = ( V_30 - V_212 ) -
F_26 ( & V_137 -> V_44 , V_212 , V_30 ) ;
F_223 ( V_15 ) ;
if ( V_211 ) {
F_220 ( V_35 , - V_211 ) ;
F_11 ( V_2 , V_211 ) ;
}
}
}
static int F_226 ( struct V_14 * V_15 , struct V_214 * V_215 )
{
F_194 () ;
return 0 ;
}
static T_10 F_227 ( struct V_14 * V_15 , struct V_55 * V_55 ,
int V_216 )
{
T_10 V_217 ;
if ( V_216 ) {
V_217 = F_228 ( F_229 ( F_230 ( V_55 ,
V_15 -> V_218 ) ) ) ;
} else {
V_217 = F_231 ( F_230 ( V_55 ,
V_15 -> V_218 ) ) ;
}
V_217 = F_232 ( V_217 ) ;
V_217 = F_233 ( V_217 ) ;
V_217 = F_234 ( V_217 , V_15 , V_55 , V_216 ) ;
return V_217 ;
}
static void F_235 ( struct V_14 * V_15 ,
unsigned long V_36 , T_10 * V_219 )
{
T_10 V_217 ;
V_217 = F_228 ( F_229 ( F_236 ( V_219 ) ) ) ;
if ( F_237 ( V_15 , V_36 , V_219 , V_217 , 1 ) )
F_238 ( V_15 , V_36 , V_219 ) ;
}
int F_239 ( struct V_220 * V_221 , struct V_220 * V_222 ,
struct V_14 * V_15 )
{
T_10 * V_223 , * V_224 , V_217 ;
struct V_55 * V_225 ;
unsigned long V_130 ;
int V_226 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_227 = F_77 ( V_35 ) ;
unsigned long V_228 ;
unsigned long V_229 ;
int V_10 = 0 ;
V_226 = ( V_15 -> V_47 & ( V_230 | V_231 ) ) == V_231 ;
V_228 = V_15 -> V_37 ;
V_229 = V_15 -> V_213 ;
if ( V_226 )
F_240 ( V_222 , V_228 , V_229 ) ;
for ( V_130 = V_15 -> V_37 ; V_130 < V_15 -> V_213 ; V_130 += V_227 ) {
T_11 * V_232 , * V_233 ;
V_223 = F_241 ( V_222 , V_130 ) ;
if ( ! V_223 )
continue;
V_224 = F_242 ( V_221 , V_130 , V_227 ) ;
if ( ! V_224 ) {
V_10 = - V_11 ;
break;
}
if ( V_224 == V_223 )
continue;
V_233 = F_243 ( V_35 , V_221 , V_224 ) ;
V_232 = F_244 ( V_35 , V_222 , V_223 ) ;
F_245 ( V_232 , V_234 ) ;
if ( ! F_246 ( F_236 ( V_223 ) ) ) {
if ( V_226 )
F_247 ( V_222 , V_130 , V_223 ) ;
V_217 = F_236 ( V_223 ) ;
V_225 = F_248 ( V_217 ) ;
F_249 ( V_225 ) ;
F_250 ( V_225 ) ;
F_251 ( V_221 , V_130 , V_224 , V_217 ) ;
}
F_2 ( V_232 ) ;
F_2 ( V_233 ) ;
}
if ( V_226 )
F_252 ( V_222 , V_228 , V_229 ) ;
return V_10 ;
}
static int F_253 ( T_10 V_235 )
{
T_12 V_236 ;
if ( F_246 ( V_235 ) || F_254 ( V_235 ) )
return 0 ;
V_236 = F_255 ( V_235 ) ;
if ( F_256 ( V_236 ) && F_257 ( V_236 ) )
return 1 ;
else
return 0 ;
}
static int F_258 ( T_10 V_235 )
{
T_12 V_236 ;
if ( F_246 ( V_235 ) || F_254 ( V_235 ) )
return 0 ;
V_236 = F_255 ( V_235 ) ;
if ( F_256 ( V_236 ) && F_259 ( V_236 ) )
return 1 ;
else
return 0 ;
}
void F_260 ( struct V_237 * V_238 , struct V_14 * V_15 ,
unsigned long V_212 , unsigned long V_30 ,
struct V_55 * V_239 )
{
int V_240 = 0 ;
struct V_220 * V_241 = V_15 -> V_242 ;
unsigned long V_36 ;
T_10 * V_219 ;
T_10 V_235 ;
T_11 * V_243 ;
struct V_55 * V_55 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_227 = F_77 ( V_35 ) ;
const unsigned long V_228 = V_212 ;
const unsigned long V_229 = V_30 ;
F_155 ( ! F_35 ( V_15 ) ) ;
F_9 ( V_212 & ~ F_261 ( V_35 ) ) ;
F_9 ( V_30 & ~ F_261 ( V_35 ) ) ;
F_262 ( V_238 , V_15 ) ;
F_240 ( V_241 , V_228 , V_229 ) ;
V_244:
for ( V_36 = V_212 ; V_36 < V_30 ; V_36 += V_227 ) {
V_219 = F_241 ( V_241 , V_36 ) ;
if ( ! V_219 )
continue;
V_243 = F_243 ( V_35 , V_241 , V_219 ) ;
if ( F_263 ( V_241 , & V_36 , V_219 ) )
goto V_245;
V_235 = F_236 ( V_219 ) ;
if ( F_246 ( V_235 ) )
goto V_245;
if ( F_66 ( F_258 ( V_235 ) ) ) {
F_264 ( V_241 , V_36 , V_219 ) ;
goto V_245;
}
V_55 = F_248 ( V_235 ) ;
if ( V_239 ) {
if ( V_55 != V_239 )
goto V_245;
F_46 ( V_15 , V_246 ) ;
}
V_235 = F_265 ( V_241 , V_36 , V_219 ) ;
F_266 ( V_238 , V_219 , V_36 ) ;
if ( F_267 ( V_235 ) )
F_268 ( V_55 ) ;
F_269 ( V_55 ) ;
V_240 = ! F_270 ( V_238 , V_55 ) ;
if ( V_240 ) {
F_2 ( V_243 ) ;
break;
}
if ( V_239 ) {
F_2 ( V_243 ) ;
break;
}
V_245:
F_2 ( V_243 ) ;
}
if ( V_240 ) {
V_240 = 0 ;
F_271 ( V_238 ) ;
if ( V_36 < V_30 && ! V_239 )
goto V_244;
}
F_252 ( V_241 , V_228 , V_229 ) ;
F_272 ( V_238 , V_15 ) ;
}
void F_273 ( struct V_237 * V_238 ,
struct V_14 * V_15 , unsigned long V_212 ,
unsigned long V_30 , struct V_55 * V_239 )
{
F_260 ( V_238 , V_15 , V_212 , V_30 , V_239 ) ;
V_15 -> V_47 &= ~ V_48 ;
}
void F_274 ( struct V_14 * V_15 , unsigned long V_212 ,
unsigned long V_30 , struct V_55 * V_239 )
{
struct V_220 * V_241 ;
struct V_237 V_238 ;
V_241 = V_15 -> V_242 ;
F_275 ( & V_238 , V_241 , V_212 , V_30 ) ;
F_260 ( & V_238 , V_15 , V_212 , V_30 , V_239 ) ;
F_276 ( & V_238 , V_212 , V_30 ) ;
}
static int F_277 ( struct V_220 * V_241 , struct V_14 * V_15 ,
struct V_55 * V_55 , unsigned long V_36 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_14 * V_247 ;
struct V_131 * V_92 ;
T_1 V_248 ;
V_36 = V_36 & F_261 ( V_35 ) ;
V_248 = ( ( V_36 - V_15 -> V_37 ) >> V_148 ) +
V_15 -> V_38 ;
V_92 = F_15 ( V_15 -> V_16 ) -> V_135 ;
F_278 ( & V_92 -> V_249 ) ;
F_279 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_247 == V_15 )
continue;
if ( ! F_47 ( V_247 , V_54 ) )
F_274 ( V_247 , V_36 ,
V_36 + F_77 ( V_35 ) , V_55 ) ;
}
F_280 ( & V_92 -> V_249 ) ;
return 1 ;
}
static int F_281 ( struct V_220 * V_241 , struct V_14 * V_15 ,
unsigned long V_36 , T_10 * V_219 , T_10 V_235 ,
struct V_55 * V_250 , T_11 * V_243 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_55 * V_251 , * V_252 ;
int V_253 = 0 ;
unsigned long V_228 ;
unsigned long V_229 ;
V_251 = F_248 ( V_235 ) ;
V_254:
if ( F_83 ( V_251 ) == 1 && F_282 ( V_251 ) ) {
F_283 ( V_251 , V_15 , V_36 ) ;
F_235 ( V_15 , V_36 , V_219 ) ;
return 0 ;
}
if ( F_47 ( V_15 , V_54 ) &&
V_251 != V_250 )
V_253 = 1 ;
F_284 ( V_251 ) ;
F_2 ( V_243 ) ;
V_252 = F_138 ( V_15 , V_36 , V_253 ) ;
if ( F_144 ( V_252 ) ) {
long V_75 = F_285 ( V_252 ) ;
F_286 ( V_251 ) ;
if ( V_253 ) {
F_9 ( F_246 ( V_235 ) ) ;
if ( F_277 ( V_241 , V_15 , V_251 , V_36 ) ) {
F_9 ( F_246 ( V_235 ) ) ;
F_8 ( V_243 ) ;
V_219 = F_241 ( V_241 , V_36 & F_261 ( V_35 ) ) ;
if ( F_287 ( F_288 ( F_236 ( V_219 ) , V_235 ) ) )
goto V_254;
return 0 ;
}
F_289 ( 1 ) ;
}
F_8 ( V_243 ) ;
if ( V_75 == - V_11 )
return V_255 ;
else
return V_256 ;
}
if ( F_66 ( F_290 ( V_15 ) ) ) {
F_286 ( V_252 ) ;
F_286 ( V_251 ) ;
F_8 ( V_243 ) ;
return V_255 ;
}
F_291 ( V_252 , V_251 , V_36 , V_15 ,
F_69 ( V_35 ) ) ;
F_292 ( V_252 ) ;
V_228 = V_36 & F_261 ( V_35 ) ;
V_229 = V_228 + F_77 ( V_35 ) ;
F_240 ( V_241 , V_228 , V_229 ) ;
F_8 ( V_243 ) ;
V_219 = F_241 ( V_241 , V_36 & F_261 ( V_35 ) ) ;
if ( F_287 ( F_288 ( F_236 ( V_219 ) , V_235 ) ) ) {
F_85 ( V_252 ) ;
F_293 ( V_15 , V_36 , V_219 ) ;
F_251 ( V_241 , V_36 , V_219 ,
F_227 ( V_15 , V_252 , 1 ) ) ;
F_269 ( V_251 ) ;
F_294 ( V_252 , V_15 , V_36 ) ;
V_252 = V_251 ;
}
F_2 ( V_243 ) ;
F_252 ( V_241 , V_228 , V_229 ) ;
F_286 ( V_252 ) ;
F_286 ( V_251 ) ;
F_8 ( V_243 ) ;
return 0 ;
}
static struct V_55 * F_295 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_36 )
{
struct V_131 * V_92 ;
T_1 V_134 ;
V_92 = V_15 -> V_16 -> V_132 ;
V_134 = F_29 ( V_35 , V_15 , V_36 ) ;
return F_296 ( V_92 , V_134 ) ;
}
static bool F_297 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_36 )
{
struct V_131 * V_92 ;
T_1 V_134 ;
struct V_55 * V_55 ;
V_92 = V_15 -> V_16 -> V_132 ;
V_134 = F_29 ( V_35 , V_15 , V_36 ) ;
V_55 = F_298 ( V_92 , V_134 ) ;
if ( V_55 )
F_91 ( V_55 ) ;
return V_55 != NULL ;
}
static int F_299 ( struct V_220 * V_241 , struct V_14 * V_15 ,
unsigned long V_36 , T_10 * V_219 , unsigned int V_51 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
int V_10 = V_256 ;
int V_257 = 0 ;
T_1 V_134 ;
unsigned long V_90 ;
struct V_55 * V_55 ;
struct V_131 * V_92 ;
T_10 V_258 ;
T_11 * V_243 ;
if ( F_47 ( V_15 , V_246 ) ) {
F_205 ( L_23 ,
V_155 -> V_259 ) ;
return V_10 ;
}
V_92 = V_15 -> V_16 -> V_132 ;
V_134 = F_29 ( V_35 , V_15 , V_36 ) ;
V_126:
V_55 = F_296 ( V_92 , V_134 ) ;
if ( ! V_55 ) {
V_90 = F_300 ( V_92 -> V_133 ) >> F_30 ( V_35 ) ;
if ( V_134 >= V_90 )
goto V_154;
V_55 = F_138 ( V_15 , V_36 , 0 ) ;
if ( F_144 ( V_55 ) ) {
V_10 = F_285 ( V_55 ) ;
if ( V_10 == - V_11 )
V_10 = V_255 ;
else
V_10 = V_256 ;
goto V_154;
}
F_301 ( V_55 , V_36 , F_69 ( V_35 ) ) ;
F_292 ( V_55 ) ;
if ( V_15 -> V_47 & V_48 ) {
int V_75 ;
struct V_12 * V_12 = V_92 -> V_133 ;
V_75 = F_302 ( V_55 , V_92 , V_134 , V_7 ) ;
if ( V_75 ) {
F_91 ( V_55 ) ;
if ( V_75 == - V_260 )
goto V_126;
goto V_154;
}
F_85 ( V_55 ) ;
F_8 ( & V_12 -> V_261 ) ;
V_12 -> V_262 += F_303 ( V_35 ) ;
F_2 ( & V_12 -> V_261 ) ;
} else {
F_304 ( V_55 ) ;
if ( F_66 ( F_290 ( V_15 ) ) ) {
V_10 = V_255 ;
goto V_263;
}
V_257 = 1 ;
}
} else {
if ( F_66 ( F_305 ( V_55 ) ) ) {
V_10 = V_264 |
F_306 ( F_87 ( V_35 ) ) ;
goto V_263;
}
}
if ( ( V_51 & V_265 ) && ! ( V_15 -> V_47 & V_230 ) )
if ( F_136 ( V_35 , V_15 , V_36 ) < 0 ) {
V_10 = V_255 ;
goto V_263;
}
V_243 = F_244 ( V_35 , V_241 , V_219 ) ;
F_8 ( V_243 ) ;
V_90 = F_300 ( V_92 -> V_133 ) >> F_30 ( V_35 ) ;
if ( V_134 >= V_90 )
goto V_266;
V_10 = 0 ;
if ( ! F_246 ( F_236 ( V_219 ) ) )
goto V_266;
if ( V_257 ) {
F_85 ( V_55 ) ;
F_294 ( V_55 , V_15 , V_36 ) ;
}
else
F_250 ( V_55 ) ;
V_258 = F_227 ( V_15 , V_55 , ( ( V_15 -> V_47 & V_267 )
&& ( V_15 -> V_47 & V_230 ) ) ) ;
F_251 ( V_241 , V_36 , V_219 , V_258 ) ;
if ( ( V_51 & V_265 ) && ! ( V_15 -> V_47 & V_230 ) ) {
V_10 = F_281 ( V_241 , V_15 , V_36 , V_219 , V_258 , V_55 , V_243 ) ;
}
F_2 ( V_243 ) ;
F_307 ( V_55 ) ;
V_154:
return V_10 ;
V_266:
F_2 ( V_243 ) ;
V_263:
F_307 ( V_55 ) ;
F_91 ( V_55 ) ;
goto V_154;
}
int F_308 ( struct V_220 * V_241 , struct V_14 * V_15 ,
unsigned long V_36 , unsigned int V_51 )
{
T_10 * V_219 ;
T_10 V_217 ;
T_11 * V_243 ;
int V_10 ;
struct V_55 * V_55 = NULL ;
struct V_55 * V_250 = NULL ;
static F_309 ( V_268 ) ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
V_36 &= F_261 ( V_35 ) ;
V_219 = F_241 ( V_241 , V_36 ) ;
if ( V_219 ) {
V_217 = F_236 ( V_219 ) ;
if ( F_66 ( F_253 ( V_217 ) ) ) {
F_310 ( V_15 , V_241 , V_219 ) ;
return 0 ;
} else if ( F_66 ( F_258 ( V_217 ) ) )
return V_269 |
F_306 ( F_87 ( V_35 ) ) ;
}
V_219 = F_242 ( V_241 , V_36 , F_77 ( V_35 ) ) ;
if ( ! V_219 )
return V_255 ;
F_278 ( & V_268 ) ;
V_217 = F_236 ( V_219 ) ;
if ( F_246 ( V_217 ) ) {
V_10 = F_299 ( V_241 , V_15 , V_36 , V_219 , V_51 ) ;
goto V_270;
}
V_10 = 0 ;
if ( ( V_51 & V_265 ) && ! F_311 ( V_217 ) ) {
if ( F_136 ( V_35 , V_15 , V_36 ) < 0 ) {
V_10 = V_255 ;
goto V_270;
}
if ( ! ( V_15 -> V_47 & V_48 ) )
V_250 = F_295 ( V_35 ,
V_15 , V_36 ) ;
}
V_55 = F_248 ( V_217 ) ;
F_249 ( V_55 ) ;
if ( V_55 != V_250 )
F_304 ( V_55 ) ;
V_243 = F_244 ( V_35 , V_241 , V_219 ) ;
F_8 ( V_243 ) ;
if ( F_66 ( ! F_288 ( V_217 , F_236 ( V_219 ) ) ) )
goto V_271;
if ( V_51 & V_265 ) {
if ( ! F_311 ( V_217 ) ) {
V_10 = F_281 ( V_241 , V_15 , V_36 , V_219 , V_217 ,
V_250 , V_243 ) ;
goto V_271;
}
V_217 = F_229 ( V_217 ) ;
}
V_217 = F_232 ( V_217 ) ;
if ( F_237 ( V_15 , V_36 , V_219 , V_217 ,
V_51 & V_265 ) )
F_238 ( V_15 , V_36 , V_219 ) ;
V_271:
F_2 ( V_243 ) ;
if ( V_250 ) {
F_307 ( V_250 ) ;
F_91 ( V_250 ) ;
}
if ( V_55 != V_250 )
F_307 ( V_55 ) ;
F_91 ( V_55 ) ;
V_270:
F_280 ( & V_268 ) ;
return V_10 ;
}
long F_312 ( struct V_220 * V_241 , struct V_14 * V_15 ,
struct V_55 * * V_272 , struct V_14 * * V_273 ,
unsigned long * V_274 , unsigned long * V_96 ,
long V_77 , unsigned int V_51 )
{
unsigned long V_275 ;
unsigned long V_276 = * V_274 ;
unsigned long V_277 = * V_96 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
while ( V_276 < V_15 -> V_213 && V_277 ) {
T_10 * V_235 ;
T_11 * V_243 = NULL ;
int V_278 ;
struct V_55 * V_55 ;
V_235 = F_241 ( V_241 , V_276 & F_261 ( V_35 ) ) ;
if ( V_235 )
V_243 = F_243 ( V_35 , V_241 , V_235 ) ;
V_278 = ! V_235 || F_246 ( F_236 ( V_235 ) ) ;
if ( V_278 && ( V_51 & V_279 ) &&
! F_297 ( V_35 , V_15 , V_276 ) ) {
if ( V_235 )
F_2 ( V_243 ) ;
V_277 = 0 ;
break;
}
if ( V_278 || F_313 ( F_236 ( V_235 ) ) ||
( ( V_51 & V_280 ) &&
! F_311 ( F_236 ( V_235 ) ) ) ) {
int V_10 ;
if ( V_235 )
F_2 ( V_243 ) ;
V_10 = F_308 ( V_241 , V_15 , V_276 ,
( V_51 & V_280 ) ? V_265 : 0 ) ;
if ( ! ( V_10 & V_281 ) )
continue;
V_277 = 0 ;
break;
}
V_275 = ( V_276 & ~ F_261 ( V_35 ) ) >> V_148 ;
V_55 = F_248 ( F_236 ( V_235 ) ) ;
V_282:
if ( V_272 ) {
V_272 [ V_77 ] = F_314 ( V_55 , V_275 ) ;
F_315 ( V_272 [ V_77 ] ) ;
}
if ( V_273 )
V_273 [ V_77 ] = V_15 ;
V_276 += V_39 ;
++ V_275 ;
-- V_277 ;
++ V_77 ;
if ( V_276 < V_15 -> V_213 && V_277 &&
V_275 < F_69 ( V_35 ) ) {
goto V_282;
}
F_2 ( V_243 ) ;
}
* V_96 = V_277 ;
* V_274 = V_276 ;
return V_77 ? V_77 : - V_283 ;
}
unsigned long F_316 ( struct V_14 * V_15 ,
unsigned long V_36 , unsigned long V_30 , T_13 V_284 )
{
struct V_220 * V_241 = V_15 -> V_242 ;
unsigned long V_212 = V_36 ;
T_10 * V_219 ;
T_10 V_235 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_272 = 0 ;
F_9 ( V_36 >= V_30 ) ;
F_317 ( V_15 , V_36 , V_30 ) ;
F_278 ( & V_15 -> V_16 -> V_132 -> V_249 ) ;
for (; V_36 < V_30 ; V_36 += F_77 ( V_35 ) ) {
T_11 * V_243 ;
V_219 = F_241 ( V_241 , V_36 ) ;
if ( ! V_219 )
continue;
V_243 = F_243 ( V_35 , V_241 , V_219 ) ;
if ( F_263 ( V_241 , & V_36 , V_219 ) ) {
V_272 ++ ;
F_2 ( V_243 ) ;
continue;
}
if ( ! F_246 ( F_236 ( V_219 ) ) ) {
V_235 = F_265 ( V_241 , V_36 , V_219 ) ;
V_235 = F_233 ( F_318 ( V_235 , V_284 ) ) ;
V_235 = F_234 ( V_235 , V_15 , NULL , 0 ) ;
F_251 ( V_241 , V_36 , V_219 , V_235 ) ;
V_272 ++ ;
}
F_2 ( V_243 ) ;
}
F_319 ( V_15 , V_212 , V_30 ) ;
F_280 ( & V_15 -> V_16 -> V_132 -> V_249 ) ;
return V_272 << V_35 -> V_78 ;
}
int F_320 ( struct V_12 * V_12 ,
long V_26 , long V_25 ,
struct V_14 * V_15 ,
T_14 V_47 )
{
long V_10 , V_28 ;
struct V_34 * V_35 = F_321 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( V_47 & V_53 )
return 0 ;
if ( ! V_15 || V_15 -> V_47 & V_48 )
V_28 = F_20 ( & V_12 -> V_135 -> V_136 , V_26 , V_25 ) ;
else {
struct V_42 * V_42 = F_39 () ;
if ( ! V_42 )
return - V_11 ;
V_28 = V_25 - V_26 ;
F_45 ( V_15 , V_42 ) ;
F_46 ( V_15 , V_54 ) ;
}
if ( V_28 < 0 ) {
V_10 = V_28 ;
goto V_285;
}
if ( F_10 ( V_2 , V_28 ) ) {
V_10 = - V_140 ;
goto V_285;
}
V_10 = F_220 ( V_35 , V_28 ) ;
if ( V_10 < 0 ) {
F_11 ( V_2 , V_28 ) ;
goto V_285;
}
if ( ! V_15 || V_15 -> V_47 & V_48 )
F_16 ( & V_12 -> V_135 -> V_136 , V_26 , V_25 ) ;
return 0 ;
V_285:
if ( V_15 )
F_223 ( V_15 ) ;
return V_10 ;
}
void F_322 ( struct V_12 * V_12 , long V_286 , long V_287 )
{
struct V_34 * V_35 = F_321 ( V_12 ) ;
long V_28 = F_23 ( & V_12 -> V_135 -> V_136 , V_286 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_8 ( & V_12 -> V_261 ) ;
V_12 -> V_262 -= ( F_303 ( V_35 ) * V_287 ) ;
F_2 ( & V_12 -> V_261 ) ;
F_11 ( V_2 , ( V_28 - V_287 ) ) ;
F_220 ( V_35 , - ( V_28 - V_287 ) ) ;
}
static unsigned long F_323 ( struct V_14 * V_288 ,
struct V_14 * V_15 ,
unsigned long V_130 , T_1 V_134 )
{
unsigned long V_289 = ( ( V_134 - V_288 -> V_38 ) << V_148 ) +
V_288 -> V_37 ;
unsigned long V_290 = V_289 & V_291 ;
unsigned long V_292 = V_290 + V_293 ;
unsigned long V_47 = V_15 -> V_47 & ~ V_294 ;
unsigned long V_295 = V_288 -> V_47 & ~ V_294 ;
if ( F_324 ( V_130 ) != F_324 ( V_289 ) ||
V_47 != V_295 ||
V_290 < V_288 -> V_37 || V_288 -> V_213 < V_292 )
return 0 ;
return V_289 ;
}
static int F_325 ( struct V_14 * V_15 , unsigned long V_130 )
{
unsigned long V_296 = V_130 & V_291 ;
unsigned long V_30 = V_296 + V_293 ;
if ( V_15 -> V_47 & V_48 &&
V_15 -> V_37 <= V_296 && V_30 <= V_15 -> V_213 )
return 1 ;
return 0 ;
}
T_10 * F_326 ( struct V_220 * V_241 , unsigned long V_130 , T_15 * V_297 )
{
struct V_14 * V_15 = F_327 ( V_241 , V_130 ) ;
struct V_131 * V_92 = V_15 -> V_16 -> V_132 ;
T_1 V_134 = ( ( V_130 - V_15 -> V_37 ) >> V_148 ) +
V_15 -> V_38 ;
struct V_14 * V_288 ;
unsigned long V_289 ;
T_10 * V_298 = NULL ;
T_10 * V_235 ;
T_11 * V_243 ;
if ( ! F_325 ( V_15 , V_130 ) )
return ( T_10 * ) F_328 ( V_241 , V_297 , V_130 ) ;
F_278 ( & V_92 -> V_249 ) ;
F_279 (svma, &mapping->i_mmap, idx, idx) {
if ( V_288 == V_15 )
continue;
V_289 = F_323 ( V_288 , V_15 , V_130 , V_134 ) ;
if ( V_289 ) {
V_298 = F_241 ( V_288 -> V_242 , V_289 ) ;
if ( V_298 ) {
F_249 ( F_154 ( V_298 ) ) ;
break;
}
}
}
if ( ! V_298 )
goto V_154;
V_243 = F_244 ( F_33 ( V_15 ) , V_241 , V_298 ) ;
F_8 ( V_243 ) ;
if ( F_329 ( * V_297 ) )
F_330 ( V_241 , V_297 ,
( V_299 * ) ( ( unsigned long ) V_298 & V_300 ) ) ;
else
F_91 ( F_154 ( V_298 ) ) ;
F_2 ( V_243 ) ;
V_154:
V_235 = ( T_10 * ) F_328 ( V_241 , V_297 , V_130 ) ;
F_280 ( & V_92 -> V_249 ) ;
return V_235 ;
}
int F_263 ( struct V_220 * V_241 , unsigned long * V_130 , T_10 * V_219 )
{
T_16 * V_301 = F_331 ( V_241 , * V_130 ) ;
T_15 * V_297 = F_332 ( V_301 , * V_130 ) ;
F_9 ( F_82 ( F_154 ( V_219 ) ) == 0 ) ;
if ( F_82 ( F_154 ( V_219 ) ) == 1 )
return 0 ;
F_333 ( V_297 ) ;
F_91 ( F_154 ( V_219 ) ) ;
* V_130 = F_334 ( * V_130 , V_187 * V_302 ) - V_187 ;
return 1 ;
}
T_10 * F_326 ( struct V_220 * V_241 , unsigned long V_130 , T_15 * V_297 )
{
return NULL ;
}
T_10 * F_242 ( struct V_220 * V_241 ,
unsigned long V_130 , unsigned long V_227 )
{
T_16 * V_301 ;
T_15 * V_297 ;
T_10 * V_235 = NULL ;
V_301 = F_331 ( V_241 , V_130 ) ;
V_297 = F_335 ( V_241 , V_301 , V_130 ) ;
if ( V_297 ) {
if ( V_227 == V_293 ) {
V_235 = ( T_10 * ) V_297 ;
} else {
F_9 ( V_227 != V_303 ) ;
if ( F_336 () && F_329 ( * V_297 ) )
V_235 = F_326 ( V_241 , V_130 , V_297 ) ;
else
V_235 = ( T_10 * ) F_328 ( V_241 , V_297 , V_130 ) ;
}
}
F_9 ( V_235 && ! F_337 ( * V_235 ) && ! F_338 ( * V_235 ) ) ;
return V_235 ;
}
T_10 * F_241 ( struct V_220 * V_241 , unsigned long V_130 )
{
T_16 * V_301 ;
T_15 * V_297 ;
V_299 * V_304 = NULL ;
V_301 = F_331 ( V_241 , V_130 ) ;
if ( F_339 ( * V_301 ) ) {
V_297 = F_332 ( V_301 , V_130 ) ;
if ( F_340 ( * V_297 ) ) {
if ( F_341 ( * V_297 ) )
return ( T_10 * ) V_297 ;
V_304 = F_342 ( V_297 , V_130 ) ;
}
}
return ( T_10 * ) V_304 ;
}
struct V_55 *
F_343 ( struct V_220 * V_241 , unsigned long V_36 ,
V_299 * V_304 , int V_203 )
{
struct V_55 * V_55 ;
V_55 = F_248 ( * ( T_10 * ) V_304 ) ;
if ( V_55 )
V_55 += ( ( V_36 & ~ V_305 ) >> V_148 ) ;
return V_55 ;
}
struct V_55 *
F_344 ( struct V_220 * V_241 , unsigned long V_36 ,
T_15 * V_297 , int V_203 )
{
struct V_55 * V_55 ;
V_55 = F_248 ( * ( T_10 * ) V_297 ) ;
if ( V_55 )
V_55 += ( ( V_36 & ~ V_291 ) >> V_148 ) ;
return V_55 ;
}
struct V_55 *
F_344 ( struct V_220 * V_241 , unsigned long V_36 ,
T_15 * V_297 , int V_203 )
{
F_194 () ;
return NULL ;
}
static int F_345 ( struct V_55 * V_306 )
{
struct V_55 * V_55 ;
struct V_55 * V_122 ;
struct V_34 * V_35 = F_79 ( V_306 ) ;
int V_56 = F_51 ( V_306 ) ;
F_18 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_55 == V_306 )
return 1 ;
return 0 ;
}
int F_346 ( struct V_55 * V_306 )
{
struct V_34 * V_35 = F_79 ( V_306 ) ;
int V_56 = F_51 ( V_306 ) ;
int V_10 = - V_307 ;
F_8 ( & V_93 ) ;
if ( F_345 ( V_306 ) ) {
F_347 ( & V_306 -> V_57 ) ;
F_55 ( V_306 ) ;
V_35 -> V_59 -- ;
V_35 -> V_60 [ V_56 ] -- ;
V_10 = 0 ;
}
F_2 ( & V_93 ) ;
return V_10 ;
}
bool F_348 ( struct V_55 * V_55 , struct V_17 * V_145 )
{
F_70 ( ! F_104 ( V_55 ) , V_55 ) ;
if ( ! F_349 ( V_55 ) )
return false ;
F_8 ( & V_93 ) ;
F_350 ( & V_55 -> V_57 , V_145 ) ;
F_2 ( & V_93 ) ;
return true ;
}
void F_351 ( struct V_55 * V_55 )
{
F_70 ( ! F_104 ( V_55 ) , V_55 ) ;
F_8 ( & V_93 ) ;
F_350 ( & V_55 -> V_57 , & ( F_79 ( V_55 ) ) -> V_61 ) ;
F_2 ( & V_93 ) ;
F_91 ( V_55 ) ;
}
bool F_352 ( struct V_55 * V_55 )
{
F_70 ( ! F_99 ( V_55 ) , V_55 ) ;
if ( F_353 ( V_55 ) )
return false ;
if ( F_66 ( F_305 ( V_55 ) ) )
return false ;
return F_82 ( V_55 ) > 0 ;
}
