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
F_44 ( F_70 ( V_55 ) ) ;
F_71 ( V_55 , NULL ) ;
F_55 ( V_55 ) ;
F_72 ( V_55 ) ;
F_73 ( V_55 , F_31 ( V_35 ) ) ;
}
struct V_34 * F_74 ( unsigned long V_90 )
{
struct V_34 * V_35 ;
F_75 (h) {
if ( F_76 ( V_35 ) == V_90 )
return V_35 ;
}
return NULL ;
}
static void F_77 ( struct V_55 * V_55 )
{
struct V_34 * V_35 = F_78 ( V_55 ) ;
int V_56 = F_51 ( V_55 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_79 ( V_55 ) ;
bool V_91 ;
F_80 ( V_55 , 0 ) ;
V_55 -> V_92 = NULL ;
F_9 ( F_81 ( V_55 ) ) ;
F_9 ( F_82 ( V_55 ) ) ;
V_91 = F_83 ( V_55 ) ;
F_84 ( V_55 ) ;
F_8 ( & V_93 ) ;
F_85 ( F_86 ( V_35 ) ,
F_69 ( V_35 ) , V_55 ) ;
if ( V_91 )
V_35 -> V_74 ++ ;
if ( V_35 -> V_94 [ V_56 ] && F_31 ( V_35 ) < V_79 ) {
F_19 ( & V_55 -> V_57 ) ;
F_68 ( V_35 , V_55 ) ;
V_35 -> V_95 -- ;
V_35 -> V_94 [ V_56 ] -- ;
} else {
F_87 ( V_55 ) ;
F_50 ( V_35 , V_55 ) ;
}
F_2 ( & V_93 ) ;
F_11 ( V_2 , 1 ) ;
}
static void F_88 ( struct V_34 * V_35 , struct V_55 * V_55 , int V_56 )
{
F_21 ( & V_55 -> V_57 ) ;
F_71 ( V_55 , F_77 ) ;
F_8 ( & V_93 ) ;
F_89 ( V_55 , NULL ) ;
V_35 -> V_80 ++ ;
V_35 -> V_81 [ V_56 ] ++ ;
F_2 ( & V_93 ) ;
F_90 ( V_55 ) ;
}
static void F_91 ( struct V_55 * V_55 , unsigned long V_78 )
{
int V_77 ;
int V_96 = 1 << V_78 ;
struct V_55 * V_97 = V_55 + 1 ;
F_92 ( V_55 , V_78 ) ;
F_93 ( V_55 ) ;
F_94 ( V_55 ) ;
for ( V_77 = 1 ; V_77 < V_96 ; V_77 ++ , V_97 = F_95 ( V_97 , V_55 , V_77 ) ) {
F_96 ( V_97 ) ;
F_94 ( V_97 ) ;
F_97 ( V_97 , 0 ) ;
V_97 -> V_98 = V_55 ;
}
}
int F_98 ( struct V_55 * V_55 )
{
T_4 * V_99 ;
if ( ! F_99 ( V_55 ) )
return 0 ;
V_55 = F_100 ( V_55 ) ;
V_99 = F_101 ( V_55 ) ;
return V_99 == F_77 ;
}
int F_102 ( struct V_55 * V_100 )
{
T_4 * V_99 ;
if ( ! F_103 ( V_100 ) )
return 0 ;
V_99 = F_101 ( V_100 ) ;
return V_99 == F_77 ;
}
T_1 F_104 ( struct V_55 * V_55 )
{
struct V_55 * V_100 = F_100 ( V_55 ) ;
T_1 V_101 = F_105 ( V_100 ) ;
unsigned long V_102 ;
if ( ! F_98 ( V_100 ) )
return F_105 ( V_55 ) ;
if ( F_106 ( V_100 ) >= V_79 )
V_102 = F_107 ( V_55 ) - F_107 ( V_100 ) ;
else
V_102 = V_55 - V_100 ;
return ( V_101 << F_106 ( V_100 ) ) + V_102 ;
}
static struct V_55 * F_108 ( struct V_34 * V_35 , int V_56 )
{
struct V_55 * V_55 ;
if ( V_35 -> V_78 >= V_79 )
return NULL ;
V_55 = F_109 ( V_56 ,
F_56 ( V_35 ) | V_103 | V_104 |
V_105 | V_106 ,
F_31 ( V_35 ) ) ;
if ( V_55 ) {
if ( F_110 ( V_55 ) ) {
F_73 ( V_55 , F_31 ( V_35 ) ) ;
return NULL ;
}
F_88 ( V_35 , V_55 , V_56 ) ;
}
return V_55 ;
}
static int F_111 ( int V_56 , T_3 * V_107 )
{
V_56 = F_112 ( V_56 , * V_107 ) ;
if ( V_56 == V_108 )
V_56 = F_113 ( * V_107 ) ;
F_44 ( V_56 >= V_108 ) ;
return V_56 ;
}
static int F_114 ( int V_56 , T_3 * V_107 )
{
if ( ! F_115 ( V_56 , * V_107 ) )
V_56 = F_111 ( V_56 , V_107 ) ;
return V_56 ;
}
static int F_116 ( struct V_34 * V_35 ,
T_3 * V_107 )
{
int V_56 ;
F_44 ( ! V_107 ) ;
V_56 = F_114 ( V_35 -> V_109 , V_107 ) ;
V_35 -> V_109 = F_111 ( V_56 , V_107 ) ;
return V_56 ;
}
static int F_117 ( struct V_34 * V_35 , T_3 * V_107 )
{
int V_56 ;
F_44 ( ! V_107 ) ;
V_56 = F_114 ( V_35 -> V_110 , V_107 ) ;
V_35 -> V_110 = F_111 ( V_56 , V_107 ) ;
return V_56 ;
}
static int F_118 ( struct V_34 * V_35 , T_3 * V_107 )
{
struct V_55 * V_55 ;
int V_111 , V_112 ;
int V_10 = 0 ;
F_119 (h, nr_nodes, node, nodes_allowed) {
V_55 = F_108 ( V_35 , V_112 ) ;
if ( V_55 ) {
V_10 = 1 ;
break;
}
}
if ( V_10 )
F_120 ( V_113 ) ;
else
F_120 ( V_114 ) ;
return V_10 ;
}
static int F_121 ( struct V_34 * V_35 , T_3 * V_107 ,
bool V_115 )
{
int V_111 , V_112 ;
int V_10 = 0 ;
F_122 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_115 || V_35 -> V_94 [ V_112 ] ) &&
! F_123 ( & V_35 -> V_58 [ V_112 ] ) ) {
struct V_55 * V_55 =
F_24 ( V_35 -> V_58 [ V_112 ] . V_31 ,
struct V_55 , V_57 ) ;
F_19 ( & V_55 -> V_57 ) ;
V_35 -> V_59 -- ;
V_35 -> V_60 [ V_112 ] -- ;
if ( V_115 ) {
V_35 -> V_95 -- ;
V_35 -> V_94 [ V_112 ] -- ;
}
F_68 ( V_35 , V_55 ) ;
V_10 = 1 ;
break;
}
}
return V_10 ;
}
static void F_124 ( struct V_55 * V_55 )
{
F_8 ( & V_93 ) ;
if ( F_98 ( V_55 ) && ! F_81 ( V_55 ) ) {
struct V_34 * V_35 = F_78 ( V_55 ) ;
int V_56 = F_51 ( V_55 ) ;
F_19 ( & V_55 -> V_57 ) ;
V_35 -> V_59 -- ;
V_35 -> V_60 [ V_56 ] -- ;
F_68 ( V_35 , V_55 ) ;
}
F_2 ( & V_93 ) ;
}
void F_125 ( unsigned long V_116 , unsigned long V_117 )
{
unsigned int V_78 = 8 * sizeof( void * ) ;
unsigned long V_118 ;
struct V_34 * V_35 ;
F_75 (h)
if ( V_78 > F_31 ( V_35 ) )
V_78 = F_31 ( V_35 ) ;
F_44 ( ! F_126 ( V_116 , 1 << V_78 ) ) ;
for ( V_118 = V_116 ; V_118 < V_117 ; V_118 += 1 << V_78 )
F_124 ( F_127 ( V_118 ) ) ;
}
static struct V_55 * F_128 ( struct V_34 * V_35 , int V_56 )
{
struct V_55 * V_55 ;
unsigned int V_119 ;
if ( V_35 -> V_78 >= V_79 )
return NULL ;
F_8 ( & V_93 ) ;
if ( V_35 -> V_95 >= V_35 -> V_120 ) {
F_2 ( & V_93 ) ;
return NULL ;
} else {
V_35 -> V_80 ++ ;
V_35 -> V_95 ++ ;
}
F_2 ( & V_93 ) ;
if ( V_56 == V_121 )
V_55 = F_129 ( F_56 ( V_35 ) | V_103 |
V_105 | V_106 ,
F_31 ( V_35 ) ) ;
else
V_55 = F_109 ( V_56 ,
F_56 ( V_35 ) | V_103 | V_104 |
V_105 | V_106 , F_31 ( V_35 ) ) ;
if ( V_55 && F_110 ( V_55 ) ) {
F_73 ( V_55 , F_31 ( V_35 ) ) ;
V_55 = NULL ;
}
F_8 ( & V_93 ) ;
if ( V_55 ) {
F_21 ( & V_55 -> V_57 ) ;
V_119 = F_51 ( V_55 ) ;
F_71 ( V_55 , F_77 ) ;
F_89 ( V_55 , NULL ) ;
V_35 -> V_81 [ V_119 ] ++ ;
V_35 -> V_94 [ V_119 ] ++ ;
F_130 ( V_113 ) ;
} else {
V_35 -> V_80 -- ;
V_35 -> V_95 -- ;
F_130 ( V_114 ) ;
}
F_2 ( & V_93 ) ;
return V_55 ;
}
struct V_55 * F_131 ( struct V_34 * V_35 , int V_56 )
{
struct V_55 * V_55 = NULL ;
F_8 ( & V_93 ) ;
if ( V_35 -> V_59 - V_35 -> V_74 > 0 )
V_55 = F_53 ( V_35 , V_56 ) ;
F_2 ( & V_93 ) ;
if ( ! V_55 )
V_55 = F_128 ( V_35 , V_56 ) ;
return V_55 ;
}
static int F_132 ( struct V_34 * V_35 , int V_9 )
{
struct V_17 V_122 ;
struct V_55 * V_55 , * V_123 ;
int V_10 , V_77 ;
int V_124 , V_125 ;
bool V_126 = true ;
V_124 = ( V_35 -> V_74 + V_9 ) - V_35 -> V_59 ;
if ( V_124 <= 0 ) {
V_35 -> V_74 += V_9 ;
return 0 ;
}
V_125 = 0 ;
F_21 ( & V_122 ) ;
V_10 = - V_11 ;
V_127:
F_2 ( & V_93 ) ;
for ( V_77 = 0 ; V_77 < V_124 ; V_77 ++ ) {
V_55 = F_128 ( V_35 , V_121 ) ;
if ( ! V_55 ) {
V_126 = false ;
break;
}
F_22 ( & V_55 -> V_57 , & V_122 ) ;
}
V_125 += V_77 ;
F_8 ( & V_93 ) ;
V_124 = ( V_35 -> V_74 + V_9 ) -
( V_35 -> V_59 + V_125 ) ;
if ( V_124 > 0 ) {
if ( V_126 )
goto V_127;
goto free;
}
V_124 += V_125 ;
V_35 -> V_74 += V_9 ;
V_10 = 0 ;
F_18 (page, tmp, &surplus_list, lru) {
if ( ( -- V_124 ) < 0 )
break;
F_133 ( V_55 ) ;
F_44 ( F_81 ( V_55 ) ) ;
F_50 ( V_35 , V_55 ) ;
}
free:
F_2 ( & V_93 ) ;
F_18 (page, tmp, &surplus_list, lru)
F_90 ( V_55 ) ;
F_8 ( & V_93 ) ;
return V_10 ;
}
static void F_134 ( struct V_34 * V_35 ,
unsigned long V_128 )
{
unsigned long V_96 ;
V_35 -> V_74 -= V_128 ;
if ( V_35 -> V_78 >= V_79 )
return;
V_96 = F_28 ( V_128 , V_35 -> V_95 ) ;
while ( V_96 -- ) {
if ( ! F_121 ( V_35 , & V_129 [ V_130 ] , 1 ) )
break;
}
}
static long F_135 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_131 )
{
struct V_132 * V_92 = V_15 -> V_16 -> V_133 ;
struct V_12 * V_12 = V_92 -> V_134 ;
if ( V_15 -> V_47 & V_48 ) {
T_1 V_135 = F_29 ( V_35 , V_15 , V_131 ) ;
return F_20 ( & V_12 -> V_136 -> V_137 ,
V_135 , V_135 + 1 ) ;
} else if ( ! F_47 ( V_15 , V_54 ) ) {
return 1 ;
} else {
long V_75 ;
T_1 V_135 = F_29 ( V_35 , V_15 , V_131 ) ;
struct V_42 * V_138 = F_43 ( V_15 ) ;
V_75 = F_20 ( & V_138 -> V_44 , V_135 , V_135 + 1 ) ;
if ( V_75 < 0 )
return V_75 ;
return 0 ;
}
}
static void F_136 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_131 )
{
struct V_132 * V_92 = V_15 -> V_16 -> V_133 ;
struct V_12 * V_12 = V_92 -> V_134 ;
if ( V_15 -> V_47 & V_48 ) {
T_1 V_135 = F_29 ( V_35 , V_15 , V_131 ) ;
F_16 ( & V_12 -> V_136 -> V_137 , V_135 , V_135 + 1 ) ;
} else if ( F_47 ( V_15 , V_54 ) ) {
T_1 V_135 = F_29 ( V_35 , V_15 , V_131 ) ;
struct V_42 * V_138 = F_43 ( V_15 ) ;
F_16 ( & V_138 -> V_44 , V_135 , V_135 + 1 ) ;
}
}
static struct V_55 * F_137 ( struct V_14 * V_15 ,
unsigned long V_131 , int V_65 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_55 * V_55 ;
long V_28 ;
int V_10 , V_135 ;
struct V_139 * V_140 ;
V_135 = F_86 ( V_35 ) ;
V_28 = F_135 ( V_35 , V_15 , V_131 ) ;
if ( V_28 < 0 )
return F_138 ( - V_11 ) ;
if ( V_28 || V_65 )
if ( F_10 ( V_2 , 1 ) )
return F_138 ( - V_141 ) ;
V_10 = F_139 ( V_135 , F_69 ( V_35 ) , & V_140 ) ;
if ( V_10 ) {
if ( V_28 || V_65 )
F_11 ( V_2 , 1 ) ;
return F_138 ( - V_141 ) ;
}
F_8 ( & V_93 ) ;
V_55 = F_58 ( V_35 , V_15 , V_131 , V_65 , V_28 ) ;
if ( ! V_55 ) {
F_2 ( & V_93 ) ;
V_55 = F_128 ( V_35 , V_121 ) ;
if ( ! V_55 ) {
F_140 ( V_135 ,
F_69 ( V_35 ) ,
V_140 ) ;
if ( V_28 || V_65 )
F_11 ( V_2 , 1 ) ;
return F_138 ( - V_141 ) ;
}
F_8 ( & V_93 ) ;
F_52 ( & V_55 -> V_57 , & V_35 -> V_61 ) ;
}
F_141 ( V_135 , F_69 ( V_35 ) , V_140 , V_55 ) ;
F_2 ( & V_93 ) ;
F_80 ( V_55 , ( unsigned long ) V_2 ) ;
F_136 ( V_35 , V_15 , V_131 ) ;
return V_55 ;
}
struct V_55 * F_142 ( struct V_14 * V_15 ,
unsigned long V_131 , int V_65 )
{
struct V_55 * V_55 = F_137 ( V_15 , V_131 , V_65 ) ;
if ( F_143 ( V_55 ) )
V_55 = NULL ;
return V_55 ;
}
int __weak F_144 ( struct V_34 * V_35 )
{
struct V_142 * V_143 ;
int V_111 , V_112 ;
F_119 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_131 ;
V_131 = F_145 ( F_146 ( V_112 ) ,
F_76 ( V_35 ) , F_76 ( V_35 ) , 0 ) ;
if ( V_131 ) {
V_143 = V_131 ;
goto V_144;
}
}
return 0 ;
V_144:
F_9 ( ( unsigned long ) F_147 ( V_143 ) & ( F_76 ( V_35 ) - 1 ) ) ;
F_22 ( & V_143 -> V_145 , & V_146 ) ;
V_143 -> V_34 = V_35 ;
return 1 ;
}
static void F_148 ( struct V_55 * V_55 , int V_78 )
{
if ( F_66 ( V_78 > ( V_79 - 1 ) ) )
F_91 ( V_55 , V_78 ) ;
else
F_149 ( V_55 , V_78 ) ;
}
static void T_5 F_150 ( void )
{
struct V_142 * V_143 ;
F_17 (m, &huge_boot_pages, list) {
struct V_34 * V_35 = V_143 -> V_34 ;
struct V_55 * V_55 ;
#ifdef F_151
V_55 = F_127 ( V_143 -> V_147 >> V_148 ) ;
F_152 ( ( unsigned long ) V_143 ,
sizeof( struct V_142 ) ) ;
#else
V_55 = F_153 ( V_143 ) ;
#endif
F_154 ( F_81 ( V_55 ) != 1 ) ;
F_148 ( V_55 , V_35 -> V_78 ) ;
F_154 ( F_155 ( V_55 ) ) ;
F_88 ( V_35 , V_55 , F_51 ( V_55 ) ) ;
if ( V_35 -> V_78 > ( V_79 - 1 ) )
F_156 ( V_55 , 1 << V_35 -> V_78 ) ;
}
}
static void T_5 F_157 ( struct V_34 * V_35 )
{
unsigned long V_77 ;
for ( V_77 = 0 ; V_77 < V_35 -> V_149 ; ++ V_77 ) {
if ( V_35 -> V_78 >= V_79 ) {
if ( ! F_144 ( V_35 ) )
break;
} else if ( ! F_118 ( V_35 ,
& V_129 [ V_130 ] ) )
break;
}
V_35 -> V_149 = V_77 ;
}
static void T_5 F_158 ( void )
{
struct V_34 * V_35 ;
F_75 (h) {
if ( V_35 -> V_78 < V_79 )
F_157 ( V_35 ) ;
}
}
static char * T_5 F_159 ( char * V_150 , unsigned long V_151 )
{
if ( V_151 >= ( 1UL << 30 ) )
sprintf ( V_150 , L_1 , V_151 >> 30 ) ;
else if ( V_151 >= ( 1UL << 20 ) )
sprintf ( V_150 , L_2 , V_151 >> 20 ) ;
else
sprintf ( V_150 , L_3 , V_151 >> 10 ) ;
return V_150 ;
}
static void T_5 F_160 ( void )
{
struct V_34 * V_35 ;
F_75 (h) {
char V_150 [ 32 ] ;
F_161 ( L_4 ,
F_159 ( V_150 , F_76 ( V_35 ) ) ,
V_35 -> V_59 ) ;
}
}
static void F_162 ( struct V_34 * V_35 , unsigned long V_3 ,
T_3 * V_107 )
{
int V_77 ;
if ( V_35 -> V_78 >= V_79 )
return;
F_163 (i, *nodes_allowed) {
struct V_55 * V_55 , * V_31 ;
struct V_17 * V_152 = & V_35 -> V_58 [ V_77 ] ;
F_18 (page, next, freel, lru) {
if ( V_3 >= V_35 -> V_80 )
return;
if ( F_164 ( V_55 ) )
continue;
F_19 ( & V_55 -> V_57 ) ;
F_68 ( V_35 , V_55 ) ;
V_35 -> V_59 -- ;
V_35 -> V_60 [ F_51 ( V_55 ) ] -- ;
}
}
}
static inline void F_162 ( struct V_34 * V_35 , unsigned long V_3 ,
T_3 * V_107 )
{
}
static int F_165 ( struct V_34 * V_35 , T_3 * V_107 ,
int V_9 )
{
int V_111 , V_112 ;
F_44 ( V_9 != - 1 && V_9 != 1 ) ;
if ( V_9 < 0 ) {
F_119 (h, nr_nodes, node, nodes_allowed) {
if ( V_35 -> V_94 [ V_112 ] )
goto V_144;
}
} else {
F_122 (h, nr_nodes, node, nodes_allowed) {
if ( V_35 -> V_94 [ V_112 ] <
V_35 -> V_81 [ V_112 ] )
goto V_144;
}
}
return 0 ;
V_144:
V_35 -> V_95 += V_9 ;
V_35 -> V_94 [ V_112 ] += V_9 ;
return 1 ;
}
static unsigned long F_166 ( struct V_34 * V_35 , unsigned long V_3 ,
T_3 * V_107 )
{
unsigned long V_153 , V_10 ;
if ( V_35 -> V_78 >= V_79 )
return V_35 -> V_149 ;
F_8 ( & V_93 ) ;
while ( V_35 -> V_95 && V_3 > F_167 ( V_35 ) ) {
if ( ! F_165 ( V_35 , V_107 , - 1 ) )
break;
}
while ( V_3 > F_167 ( V_35 ) ) {
F_2 ( & V_93 ) ;
V_10 = F_118 ( V_35 , V_107 ) ;
F_8 ( & V_93 ) ;
if ( ! V_10 )
goto V_154;
if ( F_168 ( V_155 ) )
goto V_154;
}
V_153 = V_35 -> V_74 + V_35 -> V_80 - V_35 -> V_59 ;
V_153 = F_27 ( V_3 , V_153 ) ;
F_162 ( V_35 , V_153 , V_107 ) ;
while ( V_153 < F_167 ( V_35 ) ) {
if ( ! F_121 ( V_35 , V_107 , 0 ) )
break;
}
while ( V_3 < F_167 ( V_35 ) ) {
if ( ! F_165 ( V_35 , V_107 , 1 ) )
break;
}
V_154:
V_10 = F_167 ( V_35 ) ;
F_2 ( & V_93 ) ;
return V_10 ;
}
static struct V_34 * F_169 ( struct V_156 * V_157 , int * V_158 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_159 ; V_77 ++ )
if ( V_160 [ V_77 ] == V_157 ) {
if ( V_158 )
* V_158 = V_121 ;
return & V_161 [ V_77 ] ;
}
return F_170 ( V_157 , V_158 ) ;
}
static T_6 F_171 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 ;
unsigned long V_80 ;
int V_56 ;
V_35 = F_169 ( V_157 , & V_56 ) ;
if ( V_56 == V_121 )
V_80 = V_35 -> V_80 ;
else
V_80 = V_35 -> V_81 [ V_56 ] ;
return sprintf ( V_150 , L_5 , V_80 ) ;
}
static T_6 F_172 ( bool V_164 ,
struct V_156 * V_157 , struct V_162 * V_163 ,
const char * V_150 , T_7 V_165 )
{
int V_75 ;
int V_56 ;
unsigned long V_3 ;
struct V_34 * V_35 ;
F_173 ( T_3 , V_107 , V_7 | V_166 ) ;
V_75 = F_174 ( V_150 , 10 , & V_3 ) ;
if ( V_75 )
goto V_154;
V_35 = F_169 ( V_157 , & V_56 ) ;
if ( V_35 -> V_78 >= V_79 ) {
V_75 = - V_167 ;
goto V_154;
}
if ( V_56 == V_121 ) {
if ( ! ( V_164 &&
F_175 ( V_107 ) ) ) {
F_176 ( V_107 ) ;
V_107 = & V_129 [ V_130 ] ;
}
} else if ( V_107 ) {
V_3 += V_35 -> V_80 - V_35 -> V_81 [ V_56 ] ;
F_177 ( V_107 , V_56 ) ;
} else
V_107 = & V_129 [ V_130 ] ;
V_35 -> V_149 = F_166 ( V_35 , V_3 , V_107 ) ;
if ( V_107 != & V_129 [ V_130 ] )
F_176 ( V_107 ) ;
return V_165 ;
V_154:
F_176 ( V_107 ) ;
return V_75 ;
}
static T_6 F_178 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
return F_171 ( V_157 , V_163 , V_150 ) ;
}
static T_6 F_179 ( struct V_156 * V_157 ,
struct V_162 * V_163 , const char * V_150 , T_7 V_165 )
{
return F_172 ( false , V_157 , V_163 , V_150 , V_165 ) ;
}
static T_6 F_180 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
return F_171 ( V_157 , V_163 , V_150 ) ;
}
static T_6 F_181 ( struct V_156 * V_157 ,
struct V_162 * V_163 , const char * V_150 , T_7 V_165 )
{
return F_172 ( true , V_157 , V_163 , V_150 , V_165 ) ;
}
static T_6 F_182 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 = F_169 ( V_157 , NULL ) ;
return sprintf ( V_150 , L_5 , V_35 -> V_120 ) ;
}
static T_6 F_183 ( struct V_156 * V_157 ,
struct V_162 * V_163 , const char * V_150 , T_7 V_3 )
{
int V_75 ;
unsigned long V_168 ;
struct V_34 * V_35 = F_169 ( V_157 , NULL ) ;
if ( V_35 -> V_78 >= V_79 )
return - V_167 ;
V_75 = F_174 ( V_150 , 10 , & V_168 ) ;
if ( V_75 )
return V_75 ;
F_8 ( & V_93 ) ;
V_35 -> V_120 = V_168 ;
F_2 ( & V_93 ) ;
return V_3 ;
}
static T_6 F_184 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 ;
unsigned long V_59 ;
int V_56 ;
V_35 = F_169 ( V_157 , & V_56 ) ;
if ( V_56 == V_121 )
V_59 = V_35 -> V_59 ;
else
V_59 = V_35 -> V_60 [ V_56 ] ;
return sprintf ( V_150 , L_5 , V_59 ) ;
}
static T_6 F_185 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 = F_169 ( V_157 , NULL ) ;
return sprintf ( V_150 , L_5 , V_35 -> V_74 ) ;
}
static T_6 F_186 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 ;
unsigned long V_95 ;
int V_56 ;
V_35 = F_169 ( V_157 , & V_56 ) ;
if ( V_56 == V_121 )
V_95 = V_35 -> V_95 ;
else
V_95 = V_35 -> V_94 [ V_56 ] ;
return sprintf ( V_150 , L_5 , V_95 ) ;
}
static int F_187 ( struct V_34 * V_35 , struct V_156 * V_169 ,
struct V_156 * * V_160 ,
struct V_170 * V_171 )
{
int V_172 ;
int V_173 = F_86 ( V_35 ) ;
V_160 [ V_173 ] = F_188 ( V_35 -> V_174 , V_169 ) ;
if ( ! V_160 [ V_173 ] )
return - V_11 ;
V_172 = F_189 ( V_160 [ V_173 ] , V_171 ) ;
if ( V_172 )
F_190 ( V_160 [ V_173 ] ) ;
return V_172 ;
}
static void T_5 F_191 ( void )
{
struct V_34 * V_35 ;
int V_75 ;
V_175 = F_188 ( L_6 , V_176 ) ;
if ( ! V_175 )
return;
F_75 (h) {
V_75 = F_187 ( V_35 , V_175 ,
V_160 , & V_171 ) ;
if ( V_75 )
F_192 ( L_7 , V_35 -> V_174 ) ;
}
}
static struct V_34 * F_170 ( struct V_156 * V_157 , int * V_158 )
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
F_193 () ;
return NULL ;
}
static void F_194 ( struct V_112 * V_112 )
{
struct V_34 * V_35 ;
struct V_178 * V_179 = & V_180 [ V_112 -> V_181 . V_182 ] ;
if ( ! V_179 -> V_175 )
return;
F_75 (h) {
int V_135 = F_86 ( V_35 ) ;
if ( V_179 -> V_160 [ V_135 ] ) {
F_190 ( V_179 -> V_160 [ V_135 ] ) ;
V_179 -> V_160 [ V_135 ] = NULL ;
}
}
F_190 ( V_179 -> V_175 ) ;
V_179 -> V_175 = NULL ;
}
static void F_195 ( void )
{
int V_56 ;
F_196 ( NULL , NULL ) ;
for ( V_56 = 0 ; V_56 < V_177 ; V_56 ++ )
F_194 ( V_183 [ V_56 ] ) ;
}
static void F_197 ( struct V_112 * V_112 )
{
struct V_34 * V_35 ;
struct V_178 * V_179 = & V_180 [ V_112 -> V_181 . V_182 ] ;
int V_75 ;
if ( V_179 -> V_175 )
return;
V_179 -> V_175 = F_188 ( L_6 ,
& V_112 -> V_181 . V_157 ) ;
if ( ! V_179 -> V_175 )
return;
F_75 (h) {
V_75 = F_187 ( V_35 , V_179 -> V_175 ,
V_179 -> V_160 ,
& V_184 ) ;
if ( V_75 ) {
F_192 ( L_8 ,
V_35 -> V_174 , V_112 -> V_181 . V_182 ) ;
F_194 ( V_112 ) ;
break;
}
}
}
static void F_198 ( void )
{
int V_56 ;
F_199 (nid, N_MEMORY) {
struct V_112 * V_112 = V_183 [ V_56 ] ;
if ( V_112 -> V_181 . V_182 == V_56 )
F_197 ( V_112 ) ;
}
F_196 ( F_197 ,
F_194 ) ;
}
static struct V_34 * F_170 ( struct V_156 * V_157 , int * V_158 )
{
F_193 () ;
if ( V_158 )
* V_158 = - 1 ;
return NULL ;
}
static void F_195 ( void ) { }
static void F_198 ( void ) { }
static void T_8 F_200 ( void )
{
struct V_34 * V_35 ;
F_195 () ;
F_75 (h) {
F_190 ( V_160 [ F_86 ( V_35 ) ] ) ;
}
F_190 ( V_175 ) ;
}
static int T_5 F_201 ( void )
{
if ( V_185 == 0 )
return 0 ;
if ( ! F_74 ( V_186 ) ) {
V_186 = V_187 ;
if ( ! F_74 ( V_186 ) )
F_202 ( V_188 ) ;
}
V_189 = F_86 ( F_74 ( V_186 ) ) ;
if ( V_190 )
V_191 . V_149 = V_190 ;
F_158 () ;
F_150 () ;
F_160 () ;
F_191 () ;
F_198 () ;
F_203 () ;
return 0 ;
}
void T_5 F_202 ( unsigned V_78 )
{
struct V_34 * V_35 ;
unsigned long V_77 ;
if ( F_74 ( V_39 << V_78 ) ) {
F_204 ( L_9 ) ;
return;
}
F_9 ( V_192 >= V_159 ) ;
F_9 ( V_78 == 0 ) ;
V_35 = & V_161 [ V_192 ++ ] ;
V_35 -> V_78 = V_78 ;
V_35 -> V_193 = ~ ( ( 1ULL << ( V_78 + V_148 ) ) - 1 ) ;
V_35 -> V_80 = 0 ;
V_35 -> V_59 = 0 ;
for ( V_77 = 0 ; V_77 < V_108 ; ++ V_77 )
F_21 ( & V_35 -> V_58 [ V_77 ] ) ;
F_21 ( & V_35 -> V_61 ) ;
V_35 -> V_109 = F_113 ( V_129 [ V_130 ] ) ;
V_35 -> V_110 = F_113 ( V_129 [ V_130 ] ) ;
snprintf ( V_35 -> V_174 , V_194 , L_10 ,
F_76 ( V_35 ) / 1024 ) ;
V_195 = V_35 ;
}
static int T_5 F_205 ( char * V_196 )
{
unsigned long * V_197 ;
static unsigned long * V_198 ;
if ( ! V_192 )
V_197 = & V_190 ;
else
V_197 = & V_195 -> V_149 ;
if ( V_197 == V_198 ) {
F_204 ( L_11
L_12 ) ;
return 1 ;
}
if ( sscanf ( V_196 , L_13 , V_197 ) <= 0 )
* V_197 = 0 ;
if ( V_192 && V_195 -> V_78 >= V_79 )
F_157 ( V_195 ) ;
V_198 = V_197 ;
return 1 ;
}
static int T_5 F_206 ( char * V_196 )
{
V_186 = F_207 ( V_196 , & V_196 ) ;
return 1 ;
}
static unsigned int F_208 ( unsigned int * V_199 )
{
int V_112 ;
unsigned int V_200 = 0 ;
F_163 (node, cpuset_current_mems_allowed)
V_200 += V_199 [ V_112 ] ;
return V_200 ;
}
static int F_209 ( bool V_164 ,
struct V_201 * V_202 , int V_203 ,
void T_9 * V_204 , T_7 * V_205 , T_10 * V_206 )
{
struct V_34 * V_35 = & V_191 ;
unsigned long V_123 ;
int V_10 ;
V_123 = V_35 -> V_149 ;
if ( V_203 && V_35 -> V_78 >= V_79 )
return - V_167 ;
V_202 -> V_207 = & V_123 ;
V_202 -> V_208 = sizeof( unsigned long ) ;
V_10 = F_210 ( V_202 , V_203 , V_204 , V_205 , V_206 ) ;
if ( V_10 )
goto V_154;
if ( V_203 ) {
F_173 ( T_3 , V_107 ,
V_7 | V_166 ) ;
if ( ! ( V_164 &&
F_175 ( V_107 ) ) ) {
F_176 ( V_107 ) ;
V_107 = & V_129 [ V_130 ] ;
}
V_35 -> V_149 = F_166 ( V_35 , V_123 , V_107 ) ;
if ( V_107 != & V_129 [ V_130 ] )
F_176 ( V_107 ) ;
}
V_154:
return V_10 ;
}
int F_211 ( struct V_201 * V_202 , int V_203 ,
void T_9 * V_204 , T_7 * V_205 , T_10 * V_206 )
{
return F_209 ( false , V_202 , V_203 ,
V_204 , V_205 , V_206 ) ;
}
int F_212 ( struct V_201 * V_202 , int V_203 ,
void T_9 * V_204 , T_7 * V_205 , T_10 * V_206 )
{
return F_209 ( true , V_202 , V_203 ,
V_204 , V_205 , V_206 ) ;
}
int F_213 ( struct V_201 * V_202 , int V_203 ,
void T_9 * V_204 ,
T_7 * V_205 , T_10 * V_206 )
{
struct V_34 * V_35 = & V_191 ;
unsigned long V_123 ;
int V_10 ;
V_123 = V_35 -> V_120 ;
if ( V_203 && V_35 -> V_78 >= V_79 )
return - V_167 ;
V_202 -> V_207 = & V_123 ;
V_202 -> V_208 = sizeof( unsigned long ) ;
V_10 = F_210 ( V_202 , V_203 , V_204 , V_205 , V_206 ) ;
if ( V_10 )
goto V_154;
if ( V_203 ) {
F_8 ( & V_93 ) ;
V_35 -> V_120 = V_123 ;
F_2 ( & V_93 ) ;
}
V_154:
return V_10 ;
}
void F_214 ( struct V_209 * V_143 )
{
struct V_34 * V_35 = & V_191 ;
F_215 ( V_143 ,
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
int F_216 ( int V_56 , char * V_150 )
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
void F_217 ( void )
{
struct V_34 * V_35 ;
int V_56 ;
F_199 (nid, N_MEMORY)
F_75 (h)
F_161 ( L_22 ,
V_56 ,
V_35 -> V_81 [ V_56 ] ,
V_35 -> V_60 [ V_56 ] ,
V_35 -> V_94 [ V_56 ] ,
1UL << ( F_31 ( V_35 ) + V_148 - 10 ) ) ;
}
unsigned long F_218 ( void )
{
struct V_34 * V_35 ;
unsigned long V_210 = 0 ;
F_75 (h)
V_210 += V_35 -> V_80 * F_69 ( V_35 ) ;
return V_210 ;
}
static int F_219 ( struct V_34 * V_35 , long V_9 )
{
int V_10 = - V_11 ;
F_8 ( & V_93 ) ;
if ( V_9 > 0 ) {
if ( F_132 ( V_35 , V_9 ) < 0 )
goto V_154;
if ( V_9 > F_208 ( V_35 -> V_60 ) ) {
F_134 ( V_35 , V_9 ) ;
goto V_154;
}
}
V_10 = 0 ;
if ( V_9 < 0 )
F_134 ( V_35 , ( unsigned long ) - V_9 ) ;
V_154:
F_2 ( & V_93 ) ;
return V_10 ;
}
static void F_220 ( struct V_14 * V_15 )
{
struct V_42 * V_138 = F_43 ( V_15 ) ;
if ( V_138 )
F_221 ( & V_138 -> V_43 ) ;
}
static void F_222 ( struct V_14 * V_15 )
{
struct V_42 * V_138 = F_43 ( V_15 ) ;
if ( ! V_138 )
return;
F_223 ( & V_138 -> V_43 , F_41 ) ;
}
static void F_224 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_42 * V_138 = F_43 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_15 ) ;
unsigned long V_211 ;
unsigned long V_212 ;
unsigned long V_30 ;
if ( V_138 ) {
V_212 = F_29 ( V_35 , V_15 , V_15 -> V_37 ) ;
V_30 = F_29 ( V_35 , V_15 , V_15 -> V_213 ) ;
V_211 = ( V_30 - V_212 ) -
F_26 ( & V_138 -> V_44 , V_212 , V_30 ) ;
F_222 ( V_15 ) ;
if ( V_211 ) {
F_219 ( V_35 , - V_211 ) ;
F_11 ( V_2 , V_211 ) ;
}
}
}
static int F_225 ( struct V_14 * V_15 , struct V_214 * V_215 )
{
F_193 () ;
return 0 ;
}
static T_11 F_226 ( struct V_14 * V_15 , struct V_55 * V_55 ,
int V_216 )
{
T_11 V_217 ;
if ( V_216 ) {
V_217 = F_227 ( F_228 ( F_229 ( V_55 ,
V_15 -> V_218 ) ) ) ;
} else {
V_217 = F_230 ( F_229 ( V_55 ,
V_15 -> V_218 ) ) ;
}
V_217 = F_231 ( V_217 ) ;
V_217 = F_232 ( V_217 ) ;
V_217 = F_233 ( V_217 , V_15 , V_55 , V_216 ) ;
return V_217 ;
}
static void F_234 ( struct V_14 * V_15 ,
unsigned long V_36 , T_11 * V_219 )
{
T_11 V_217 ;
V_217 = F_227 ( F_228 ( F_235 ( V_219 ) ) ) ;
if ( F_236 ( V_15 , V_36 , V_219 , V_217 , 1 ) )
F_237 ( V_15 , V_36 , V_219 ) ;
}
int F_238 ( struct V_220 * V_221 , struct V_220 * V_222 ,
struct V_14 * V_15 )
{
T_11 * V_223 , * V_224 , V_217 ;
struct V_55 * V_225 ;
unsigned long V_131 ;
int V_226 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_227 = F_76 ( V_35 ) ;
V_226 = ( V_15 -> V_47 & ( V_228 | V_229 ) ) == V_229 ;
for ( V_131 = V_15 -> V_37 ; V_131 < V_15 -> V_213 ; V_131 += V_227 ) {
T_12 * V_230 , * V_231 ;
V_223 = F_239 ( V_222 , V_131 ) ;
if ( ! V_223 )
continue;
V_224 = F_240 ( V_221 , V_131 , V_227 ) ;
if ( ! V_224 )
goto V_232;
if ( V_224 == V_223 )
continue;
V_231 = F_241 ( V_35 , V_221 , V_224 ) ;
V_230 = F_242 ( V_35 , V_222 , V_223 ) ;
F_243 ( V_230 , V_233 ) ;
if ( ! F_244 ( F_235 ( V_223 ) ) ) {
if ( V_226 )
F_245 ( V_222 , V_131 , V_223 ) ;
V_217 = F_235 ( V_223 ) ;
V_225 = F_246 ( V_217 ) ;
F_247 ( V_225 ) ;
F_248 ( V_225 ) ;
F_249 ( V_221 , V_131 , V_224 , V_217 ) ;
}
F_2 ( V_230 ) ;
F_2 ( V_231 ) ;
}
return 0 ;
V_232:
return - V_11 ;
}
static int F_250 ( T_11 V_234 )
{
T_13 V_235 ;
if ( F_244 ( V_234 ) || F_251 ( V_234 ) )
return 0 ;
V_235 = F_252 ( V_234 ) ;
if ( F_253 ( V_235 ) && F_254 ( V_235 ) )
return 1 ;
else
return 0 ;
}
static int F_255 ( T_11 V_234 )
{
T_13 V_235 ;
if ( F_244 ( V_234 ) || F_251 ( V_234 ) )
return 0 ;
V_235 = F_252 ( V_234 ) ;
if ( F_253 ( V_235 ) && F_256 ( V_235 ) )
return 1 ;
else
return 0 ;
}
void F_257 ( struct V_236 * V_237 , struct V_14 * V_15 ,
unsigned long V_212 , unsigned long V_30 ,
struct V_55 * V_238 )
{
int V_239 = 0 ;
struct V_220 * V_240 = V_15 -> V_241 ;
unsigned long V_36 ;
T_11 * V_219 ;
T_11 V_234 ;
T_12 * V_242 ;
struct V_55 * V_55 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_227 = F_76 ( V_35 ) ;
const unsigned long V_243 = V_212 ;
const unsigned long V_244 = V_30 ;
F_154 ( ! F_35 ( V_15 ) ) ;
F_9 ( V_212 & ~ F_258 ( V_35 ) ) ;
F_9 ( V_30 & ~ F_258 ( V_35 ) ) ;
F_259 ( V_237 , V_15 ) ;
F_260 ( V_240 , V_243 , V_244 ) ;
V_245:
for ( V_36 = V_212 ; V_36 < V_30 ; V_36 += V_227 ) {
V_219 = F_239 ( V_240 , V_36 ) ;
if ( ! V_219 )
continue;
V_242 = F_241 ( V_35 , V_240 , V_219 ) ;
if ( F_261 ( V_240 , & V_36 , V_219 ) )
goto V_246;
V_234 = F_235 ( V_219 ) ;
if ( F_244 ( V_234 ) )
goto V_246;
if ( F_66 ( F_255 ( V_234 ) ) ) {
F_262 ( V_240 , V_36 , V_219 ) ;
goto V_246;
}
V_55 = F_246 ( V_234 ) ;
if ( V_238 ) {
if ( V_55 != V_238 )
goto V_246;
F_46 ( V_15 , V_247 ) ;
}
V_234 = F_263 ( V_240 , V_36 , V_219 ) ;
F_264 ( V_237 , V_219 , V_36 ) ;
if ( F_265 ( V_234 ) )
F_266 ( V_55 ) ;
F_267 ( V_55 ) ;
V_239 = ! F_268 ( V_237 , V_55 ) ;
if ( V_239 ) {
F_2 ( V_242 ) ;
break;
}
if ( V_238 ) {
F_2 ( V_242 ) ;
break;
}
V_246:
F_2 ( V_242 ) ;
}
if ( V_239 ) {
V_239 = 0 ;
F_269 ( V_237 ) ;
if ( V_36 < V_30 && ! V_238 )
goto V_245;
}
F_270 ( V_240 , V_243 , V_244 ) ;
F_271 ( V_237 , V_15 ) ;
}
void F_272 ( struct V_236 * V_237 ,
struct V_14 * V_15 , unsigned long V_212 ,
unsigned long V_30 , struct V_55 * V_238 )
{
F_257 ( V_237 , V_15 , V_212 , V_30 , V_238 ) ;
V_15 -> V_47 &= ~ V_48 ;
}
void F_273 ( struct V_14 * V_15 , unsigned long V_212 ,
unsigned long V_30 , struct V_55 * V_238 )
{
struct V_220 * V_240 ;
struct V_236 V_237 ;
V_240 = V_15 -> V_241 ;
F_274 ( & V_237 , V_240 , V_212 , V_30 ) ;
F_257 ( & V_237 , V_15 , V_212 , V_30 , V_238 ) ;
F_275 ( & V_237 , V_212 , V_30 ) ;
}
static int F_276 ( struct V_220 * V_240 , struct V_14 * V_15 ,
struct V_55 * V_55 , unsigned long V_36 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_14 * V_248 ;
struct V_132 * V_92 ;
T_1 V_249 ;
V_36 = V_36 & F_258 ( V_35 ) ;
V_249 = ( ( V_36 - V_15 -> V_37 ) >> V_148 ) +
V_15 -> V_38 ;
V_92 = F_15 ( V_15 -> V_16 ) -> V_136 ;
F_277 ( & V_92 -> V_250 ) ;
F_278 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_248 == V_15 )
continue;
if ( ! F_47 ( V_248 , V_54 ) )
F_273 ( V_248 , V_36 ,
V_36 + F_76 ( V_35 ) , V_55 ) ;
}
F_279 ( & V_92 -> V_250 ) ;
return 1 ;
}
static int F_280 ( struct V_220 * V_240 , struct V_14 * V_15 ,
unsigned long V_36 , T_11 * V_219 , T_11 V_234 ,
struct V_55 * V_251 , T_12 * V_242 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_55 * V_252 , * V_253 ;
int V_254 = 0 ;
unsigned long V_243 ;
unsigned long V_244 ;
V_252 = F_246 ( V_234 ) ;
V_255:
if ( F_82 ( V_252 ) == 1 && F_281 ( V_252 ) ) {
F_282 ( V_252 , V_15 , V_36 ) ;
F_234 ( V_15 , V_36 , V_219 ) ;
return 0 ;
}
if ( F_47 ( V_15 , V_54 ) &&
V_252 != V_251 )
V_254 = 1 ;
F_283 ( V_252 ) ;
F_2 ( V_242 ) ;
V_253 = F_137 ( V_15 , V_36 , V_254 ) ;
if ( F_143 ( V_253 ) ) {
long V_75 = F_284 ( V_253 ) ;
F_285 ( V_252 ) ;
if ( V_254 ) {
F_9 ( F_244 ( V_234 ) ) ;
if ( F_276 ( V_240 , V_15 , V_252 , V_36 ) ) {
F_9 ( F_244 ( V_234 ) ) ;
F_8 ( V_242 ) ;
V_219 = F_239 ( V_240 , V_36 & F_258 ( V_35 ) ) ;
if ( F_286 ( F_287 ( F_235 ( V_219 ) , V_234 ) ) )
goto V_255;
return 0 ;
}
F_288 ( 1 ) ;
}
F_8 ( V_242 ) ;
if ( V_75 == - V_11 )
return V_256 ;
else
return V_257 ;
}
if ( F_66 ( F_289 ( V_15 ) ) ) {
F_285 ( V_253 ) ;
F_285 ( V_252 ) ;
F_8 ( V_242 ) ;
return V_256 ;
}
F_290 ( V_253 , V_252 , V_36 , V_15 ,
F_69 ( V_35 ) ) ;
F_291 ( V_253 ) ;
V_243 = V_36 & F_258 ( V_35 ) ;
V_244 = V_243 + F_76 ( V_35 ) ;
F_260 ( V_240 , V_243 , V_244 ) ;
F_8 ( V_242 ) ;
V_219 = F_239 ( V_240 , V_36 & F_258 ( V_35 ) ) ;
if ( F_286 ( F_287 ( F_235 ( V_219 ) , V_234 ) ) ) {
F_84 ( V_253 ) ;
F_292 ( V_15 , V_36 , V_219 ) ;
F_249 ( V_240 , V_36 , V_219 ,
F_226 ( V_15 , V_253 , 1 ) ) ;
F_267 ( V_252 ) ;
F_293 ( V_253 , V_15 , V_36 ) ;
V_253 = V_252 ;
}
F_2 ( V_242 ) ;
F_270 ( V_240 , V_243 , V_244 ) ;
F_285 ( V_253 ) ;
F_285 ( V_252 ) ;
F_8 ( V_242 ) ;
return 0 ;
}
static struct V_55 * F_294 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_36 )
{
struct V_132 * V_92 ;
T_1 V_135 ;
V_92 = V_15 -> V_16 -> V_133 ;
V_135 = F_29 ( V_35 , V_15 , V_36 ) ;
return F_295 ( V_92 , V_135 ) ;
}
static bool F_296 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_36 )
{
struct V_132 * V_92 ;
T_1 V_135 ;
struct V_55 * V_55 ;
V_92 = V_15 -> V_16 -> V_133 ;
V_135 = F_29 ( V_35 , V_15 , V_36 ) ;
V_55 = F_297 ( V_92 , V_135 ) ;
if ( V_55 )
F_90 ( V_55 ) ;
return V_55 != NULL ;
}
static int F_298 ( struct V_220 * V_240 , struct V_14 * V_15 ,
unsigned long V_36 , T_11 * V_219 , unsigned int V_51 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
int V_10 = V_257 ;
int V_258 = 0 ;
T_1 V_135 ;
unsigned long V_90 ;
struct V_55 * V_55 ;
struct V_132 * V_92 ;
T_11 V_259 ;
T_12 * V_242 ;
if ( F_47 ( V_15 , V_247 ) ) {
F_204 ( L_23 ,
V_155 -> V_260 ) ;
return V_10 ;
}
V_92 = V_15 -> V_16 -> V_133 ;
V_135 = F_29 ( V_35 , V_15 , V_36 ) ;
V_127:
V_55 = F_295 ( V_92 , V_135 ) ;
if ( ! V_55 ) {
V_90 = F_299 ( V_92 -> V_134 ) >> F_30 ( V_35 ) ;
if ( V_135 >= V_90 )
goto V_154;
V_55 = F_137 ( V_15 , V_36 , 0 ) ;
if ( F_143 ( V_55 ) ) {
V_10 = F_284 ( V_55 ) ;
if ( V_10 == - V_11 )
V_10 = V_256 ;
else
V_10 = V_257 ;
goto V_154;
}
F_300 ( V_55 , V_36 , F_69 ( V_35 ) ) ;
F_291 ( V_55 ) ;
if ( V_15 -> V_47 & V_48 ) {
int V_75 ;
struct V_12 * V_12 = V_92 -> V_134 ;
V_75 = F_301 ( V_55 , V_92 , V_135 , V_7 ) ;
if ( V_75 ) {
F_90 ( V_55 ) ;
if ( V_75 == - V_261 )
goto V_127;
goto V_154;
}
F_84 ( V_55 ) ;
F_8 ( & V_12 -> V_262 ) ;
V_12 -> V_263 += F_302 ( V_35 ) ;
F_2 ( & V_12 -> V_262 ) ;
} else {
F_303 ( V_55 ) ;
if ( F_66 ( F_289 ( V_15 ) ) ) {
V_10 = V_256 ;
goto V_264;
}
V_258 = 1 ;
}
} else {
if ( F_66 ( F_304 ( V_55 ) ) ) {
V_10 = V_265 |
F_305 ( F_86 ( V_35 ) ) ;
goto V_264;
}
}
if ( ( V_51 & V_266 ) && ! ( V_15 -> V_47 & V_228 ) )
if ( F_135 ( V_35 , V_15 , V_36 ) < 0 ) {
V_10 = V_256 ;
goto V_264;
}
V_242 = F_242 ( V_35 , V_240 , V_219 ) ;
F_8 ( V_242 ) ;
V_90 = F_299 ( V_92 -> V_134 ) >> F_30 ( V_35 ) ;
if ( V_135 >= V_90 )
goto V_267;
V_10 = 0 ;
if ( ! F_244 ( F_235 ( V_219 ) ) )
goto V_267;
if ( V_258 ) {
F_84 ( V_55 ) ;
F_293 ( V_55 , V_15 , V_36 ) ;
}
else
F_248 ( V_55 ) ;
V_259 = F_226 ( V_15 , V_55 , ( ( V_15 -> V_47 & V_268 )
&& ( V_15 -> V_47 & V_228 ) ) ) ;
F_249 ( V_240 , V_36 , V_219 , V_259 ) ;
if ( ( V_51 & V_266 ) && ! ( V_15 -> V_47 & V_228 ) ) {
V_10 = F_280 ( V_240 , V_15 , V_36 , V_219 , V_259 , V_55 , V_242 ) ;
}
F_2 ( V_242 ) ;
F_306 ( V_55 ) ;
V_154:
return V_10 ;
V_267:
F_2 ( V_242 ) ;
V_264:
F_306 ( V_55 ) ;
F_90 ( V_55 ) ;
goto V_154;
}
int F_307 ( struct V_220 * V_240 , struct V_14 * V_15 ,
unsigned long V_36 , unsigned int V_51 )
{
T_11 * V_219 ;
T_11 V_217 ;
T_12 * V_242 ;
int V_10 ;
struct V_55 * V_55 = NULL ;
struct V_55 * V_251 = NULL ;
static F_308 ( V_269 ) ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
V_36 &= F_258 ( V_35 ) ;
V_219 = F_239 ( V_240 , V_36 ) ;
if ( V_219 ) {
V_217 = F_235 ( V_219 ) ;
if ( F_66 ( F_250 ( V_217 ) ) ) {
F_309 ( V_15 , V_240 , V_219 ) ;
return 0 ;
} else if ( F_66 ( F_255 ( V_217 ) ) )
return V_270 |
F_305 ( F_86 ( V_35 ) ) ;
}
V_219 = F_240 ( V_240 , V_36 , F_76 ( V_35 ) ) ;
if ( ! V_219 )
return V_256 ;
F_277 ( & V_269 ) ;
V_217 = F_235 ( V_219 ) ;
if ( F_244 ( V_217 ) ) {
V_10 = F_298 ( V_240 , V_15 , V_36 , V_219 , V_51 ) ;
goto V_271;
}
V_10 = 0 ;
if ( ( V_51 & V_266 ) && ! F_310 ( V_217 ) ) {
if ( F_135 ( V_35 , V_15 , V_36 ) < 0 ) {
V_10 = V_256 ;
goto V_271;
}
if ( ! ( V_15 -> V_47 & V_48 ) )
V_251 = F_294 ( V_35 ,
V_15 , V_36 ) ;
}
V_55 = F_246 ( V_217 ) ;
F_247 ( V_55 ) ;
if ( V_55 != V_251 )
F_303 ( V_55 ) ;
V_242 = F_242 ( V_35 , V_240 , V_219 ) ;
F_8 ( V_242 ) ;
if ( F_66 ( ! F_287 ( V_217 , F_235 ( V_219 ) ) ) )
goto V_272;
if ( V_51 & V_266 ) {
if ( ! F_310 ( V_217 ) ) {
V_10 = F_280 ( V_240 , V_15 , V_36 , V_219 , V_217 ,
V_251 , V_242 ) ;
goto V_272;
}
V_217 = F_228 ( V_217 ) ;
}
V_217 = F_231 ( V_217 ) ;
if ( F_236 ( V_15 , V_36 , V_219 , V_217 ,
V_51 & V_266 ) )
F_237 ( V_15 , V_36 , V_219 ) ;
V_272:
F_2 ( V_242 ) ;
if ( V_251 ) {
F_306 ( V_251 ) ;
F_90 ( V_251 ) ;
}
if ( V_55 != V_251 )
F_306 ( V_55 ) ;
F_90 ( V_55 ) ;
V_271:
F_279 ( & V_269 ) ;
return V_10 ;
}
long F_311 ( struct V_220 * V_240 , struct V_14 * V_15 ,
struct V_55 * * V_273 , struct V_14 * * V_274 ,
unsigned long * V_275 , unsigned long * V_96 ,
long V_77 , unsigned int V_51 )
{
unsigned long V_276 ;
unsigned long V_277 = * V_275 ;
unsigned long V_278 = * V_96 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
while ( V_277 < V_15 -> V_213 && V_278 ) {
T_11 * V_234 ;
T_12 * V_242 = NULL ;
int V_279 ;
struct V_55 * V_55 ;
V_234 = F_239 ( V_240 , V_277 & F_258 ( V_35 ) ) ;
if ( V_234 )
V_242 = F_241 ( V_35 , V_240 , V_234 ) ;
V_279 = ! V_234 || F_244 ( F_235 ( V_234 ) ) ;
if ( V_279 && ( V_51 & V_280 ) &&
! F_296 ( V_35 , V_15 , V_277 ) ) {
if ( V_234 )
F_2 ( V_242 ) ;
V_278 = 0 ;
break;
}
if ( V_279 || F_312 ( F_235 ( V_234 ) ) ||
( ( V_51 & V_281 ) &&
! F_310 ( F_235 ( V_234 ) ) ) ) {
int V_10 ;
if ( V_234 )
F_2 ( V_242 ) ;
V_10 = F_307 ( V_240 , V_15 , V_277 ,
( V_51 & V_281 ) ? V_266 : 0 ) ;
if ( ! ( V_10 & V_282 ) )
continue;
V_278 = 0 ;
break;
}
V_276 = ( V_277 & ~ F_258 ( V_35 ) ) >> V_148 ;
V_55 = F_246 ( F_235 ( V_234 ) ) ;
V_283:
if ( V_273 ) {
V_273 [ V_77 ] = F_313 ( V_55 , V_276 ) ;
F_247 ( V_273 [ V_77 ] ) ;
}
if ( V_274 )
V_274 [ V_77 ] = V_15 ;
V_277 += V_39 ;
++ V_276 ;
-- V_278 ;
++ V_77 ;
if ( V_277 < V_15 -> V_213 && V_278 &&
V_276 < F_69 ( V_35 ) ) {
goto V_283;
}
F_2 ( V_242 ) ;
}
* V_96 = V_278 ;
* V_275 = V_277 ;
return V_77 ? V_77 : - V_284 ;
}
unsigned long F_314 ( struct V_14 * V_15 ,
unsigned long V_36 , unsigned long V_30 , T_14 V_285 )
{
struct V_220 * V_240 = V_15 -> V_241 ;
unsigned long V_212 = V_36 ;
T_11 * V_219 ;
T_11 V_234 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_273 = 0 ;
F_9 ( V_36 >= V_30 ) ;
F_315 ( V_15 , V_36 , V_30 ) ;
F_277 ( & V_15 -> V_16 -> V_133 -> V_250 ) ;
for (; V_36 < V_30 ; V_36 += F_76 ( V_35 ) ) {
T_12 * V_242 ;
V_219 = F_239 ( V_240 , V_36 ) ;
if ( ! V_219 )
continue;
V_242 = F_241 ( V_35 , V_240 , V_219 ) ;
if ( F_261 ( V_240 , & V_36 , V_219 ) ) {
V_273 ++ ;
F_2 ( V_242 ) ;
continue;
}
if ( ! F_244 ( F_235 ( V_219 ) ) ) {
V_234 = F_263 ( V_240 , V_36 , V_219 ) ;
V_234 = F_232 ( F_316 ( V_234 , V_285 ) ) ;
V_234 = F_233 ( V_234 , V_15 , NULL , 0 ) ;
F_249 ( V_240 , V_36 , V_219 , V_234 ) ;
V_273 ++ ;
}
F_2 ( V_242 ) ;
}
F_317 ( V_15 , V_212 , V_30 ) ;
F_279 ( & V_15 -> V_16 -> V_133 -> V_250 ) ;
return V_273 << V_35 -> V_78 ;
}
int F_318 ( struct V_12 * V_12 ,
long V_26 , long V_25 ,
struct V_14 * V_15 ,
T_15 V_47 )
{
long V_10 , V_28 ;
struct V_34 * V_35 = F_319 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( V_47 & V_53 )
return 0 ;
if ( ! V_15 || V_15 -> V_47 & V_48 )
V_28 = F_20 ( & V_12 -> V_136 -> V_137 , V_26 , V_25 ) ;
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
goto V_286;
}
if ( F_10 ( V_2 , V_28 ) ) {
V_10 = - V_141 ;
goto V_286;
}
V_10 = F_219 ( V_35 , V_28 ) ;
if ( V_10 < 0 ) {
F_11 ( V_2 , V_28 ) ;
goto V_286;
}
if ( ! V_15 || V_15 -> V_47 & V_48 )
F_16 ( & V_12 -> V_136 -> V_137 , V_26 , V_25 ) ;
return 0 ;
V_286:
if ( V_15 )
F_222 ( V_15 ) ;
return V_10 ;
}
void F_320 ( struct V_12 * V_12 , long V_287 , long V_288 )
{
struct V_34 * V_35 = F_319 ( V_12 ) ;
long V_28 = F_23 ( & V_12 -> V_136 -> V_137 , V_287 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_8 ( & V_12 -> V_262 ) ;
V_12 -> V_263 -= ( F_302 ( V_35 ) * V_288 ) ;
F_2 ( & V_12 -> V_262 ) ;
F_11 ( V_2 , ( V_28 - V_288 ) ) ;
F_219 ( V_35 , - ( V_28 - V_288 ) ) ;
}
static unsigned long F_321 ( struct V_14 * V_289 ,
struct V_14 * V_15 ,
unsigned long V_131 , T_1 V_135 )
{
unsigned long V_290 = ( ( V_135 - V_289 -> V_38 ) << V_148 ) +
V_289 -> V_37 ;
unsigned long V_291 = V_290 & V_292 ;
unsigned long V_293 = V_291 + V_294 ;
unsigned long V_47 = V_15 -> V_47 & ~ V_295 ;
unsigned long V_296 = V_289 -> V_47 & ~ V_295 ;
if ( F_322 ( V_131 ) != F_322 ( V_290 ) ||
V_47 != V_296 ||
V_291 < V_289 -> V_37 || V_289 -> V_213 < V_293 )
return 0 ;
return V_290 ;
}
static int F_323 ( struct V_14 * V_15 , unsigned long V_131 )
{
unsigned long V_297 = V_131 & V_292 ;
unsigned long V_30 = V_297 + V_294 ;
if ( V_15 -> V_47 & V_48 &&
V_15 -> V_37 <= V_297 && V_30 <= V_15 -> V_213 )
return 1 ;
return 0 ;
}
T_11 * F_324 ( struct V_220 * V_240 , unsigned long V_131 , T_16 * V_298 )
{
struct V_14 * V_15 = F_325 ( V_240 , V_131 ) ;
struct V_132 * V_92 = V_15 -> V_16 -> V_133 ;
T_1 V_135 = ( ( V_131 - V_15 -> V_37 ) >> V_148 ) +
V_15 -> V_38 ;
struct V_14 * V_289 ;
unsigned long V_290 ;
T_11 * V_299 = NULL ;
T_11 * V_234 ;
T_12 * V_242 ;
if ( ! F_323 ( V_15 , V_131 ) )
return ( T_11 * ) F_326 ( V_240 , V_298 , V_131 ) ;
F_277 ( & V_92 -> V_250 ) ;
F_278 (svma, &mapping->i_mmap, idx, idx) {
if ( V_289 == V_15 )
continue;
V_290 = F_321 ( V_289 , V_15 , V_131 , V_135 ) ;
if ( V_290 ) {
V_299 = F_239 ( V_289 -> V_241 , V_290 ) ;
if ( V_299 ) {
F_247 ( F_153 ( V_299 ) ) ;
break;
}
}
}
if ( ! V_299 )
goto V_154;
V_242 = F_242 ( F_33 ( V_15 ) , V_240 , V_299 ) ;
F_8 ( V_242 ) ;
if ( F_327 ( * V_298 ) )
F_328 ( V_240 , V_298 ,
( V_300 * ) ( ( unsigned long ) V_299 & V_301 ) ) ;
else
F_90 ( F_153 ( V_299 ) ) ;
F_2 ( V_242 ) ;
V_154:
V_234 = ( T_11 * ) F_326 ( V_240 , V_298 , V_131 ) ;
F_279 ( & V_92 -> V_250 ) ;
return V_234 ;
}
int F_261 ( struct V_220 * V_240 , unsigned long * V_131 , T_11 * V_219 )
{
T_17 * V_302 = F_329 ( V_240 , * V_131 ) ;
T_16 * V_298 = F_330 ( V_302 , * V_131 ) ;
F_9 ( F_81 ( F_153 ( V_219 ) ) == 0 ) ;
if ( F_81 ( F_153 ( V_219 ) ) == 1 )
return 0 ;
F_331 ( V_298 ) ;
F_90 ( F_153 ( V_219 ) ) ;
* V_131 = F_332 ( * V_131 , V_187 * V_303 ) - V_187 ;
return 1 ;
}
T_11 * F_324 ( struct V_220 * V_240 , unsigned long V_131 , T_16 * V_298 )
{
return NULL ;
}
T_11 * F_240 ( struct V_220 * V_240 ,
unsigned long V_131 , unsigned long V_227 )
{
T_17 * V_302 ;
T_16 * V_298 ;
T_11 * V_234 = NULL ;
V_302 = F_329 ( V_240 , V_131 ) ;
V_298 = F_333 ( V_240 , V_302 , V_131 ) ;
if ( V_298 ) {
if ( V_227 == V_294 ) {
V_234 = ( T_11 * ) V_298 ;
} else {
F_9 ( V_227 != V_304 ) ;
if ( F_334 () && F_327 ( * V_298 ) )
V_234 = F_324 ( V_240 , V_131 , V_298 ) ;
else
V_234 = ( T_11 * ) F_326 ( V_240 , V_298 , V_131 ) ;
}
}
F_9 ( V_234 && ! F_335 ( * V_234 ) && ! F_336 ( * V_234 ) ) ;
return V_234 ;
}
T_11 * F_239 ( struct V_220 * V_240 , unsigned long V_131 )
{
T_17 * V_302 ;
T_16 * V_298 ;
V_300 * V_305 = NULL ;
V_302 = F_329 ( V_240 , V_131 ) ;
if ( F_337 ( * V_302 ) ) {
V_298 = F_330 ( V_302 , V_131 ) ;
if ( F_338 ( * V_298 ) ) {
if ( F_339 ( * V_298 ) )
return ( T_11 * ) V_298 ;
V_305 = F_340 ( V_298 , V_131 ) ;
}
}
return ( T_11 * ) V_305 ;
}
struct V_55 *
F_341 ( struct V_220 * V_240 , unsigned long V_36 ,
V_300 * V_305 , int V_203 )
{
struct V_55 * V_55 ;
V_55 = F_246 ( * ( T_11 * ) V_305 ) ;
if ( V_55 )
V_55 += ( ( V_36 & ~ V_306 ) >> V_148 ) ;
return V_55 ;
}
struct V_55 *
F_342 ( struct V_220 * V_240 , unsigned long V_36 ,
T_16 * V_298 , int V_203 )
{
struct V_55 * V_55 ;
V_55 = F_246 ( * ( T_11 * ) V_298 ) ;
if ( V_55 )
V_55 += ( ( V_36 & ~ V_292 ) >> V_148 ) ;
return V_55 ;
}
struct V_55 *
F_342 ( struct V_220 * V_240 , unsigned long V_36 ,
T_16 * V_298 , int V_203 )
{
F_193 () ;
return NULL ;
}
static int F_343 ( struct V_55 * V_307 )
{
struct V_55 * V_55 ;
struct V_55 * V_123 ;
struct V_34 * V_35 = F_78 ( V_307 ) ;
int V_56 = F_51 ( V_307 ) ;
F_18 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_55 == V_307 )
return 1 ;
return 0 ;
}
int F_344 ( struct V_55 * V_307 )
{
struct V_34 * V_35 = F_78 ( V_307 ) ;
int V_56 = F_51 ( V_307 ) ;
int V_10 = - V_308 ;
F_8 ( & V_93 ) ;
if ( F_343 ( V_307 ) ) {
F_345 ( & V_307 -> V_57 ) ;
F_55 ( V_307 ) ;
V_35 -> V_59 -- ;
V_35 -> V_60 [ V_56 ] -- ;
V_10 = 0 ;
}
F_2 ( & V_93 ) ;
return V_10 ;
}
bool F_346 ( struct V_55 * V_55 , struct V_17 * V_145 )
{
F_44 ( ! F_103 ( V_55 ) ) ;
if ( ! F_347 ( V_55 ) )
return false ;
F_8 ( & V_93 ) ;
F_348 ( & V_55 -> V_57 , V_145 ) ;
F_2 ( & V_93 ) ;
return true ;
}
void F_349 ( struct V_55 * V_55 )
{
F_44 ( ! F_103 ( V_55 ) ) ;
F_8 ( & V_93 ) ;
F_348 ( & V_55 -> V_57 , & ( F_78 ( V_55 ) ) -> V_61 ) ;
F_2 ( & V_93 ) ;
F_90 ( V_55 ) ;
}
bool F_350 ( struct V_55 * V_55 )
{
F_44 ( ! F_98 ( V_55 ) ) ;
if ( F_351 ( V_55 ) )
return false ;
if ( F_66 ( F_304 ( V_55 ) ) )
return false ;
return F_81 ( V_55 ) > 0 ;
}
