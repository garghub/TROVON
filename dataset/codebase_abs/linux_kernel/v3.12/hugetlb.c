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
static void F_50 ( struct V_55 * V_56 , struct V_55 * V_57 )
{
int V_58 ;
struct V_34 * V_35 = F_51 ( V_57 ) ;
struct V_55 * V_59 = V_56 ;
struct V_55 * V_60 = V_57 ;
for ( V_58 = 0 ; V_58 < F_52 ( V_35 ) ; ) {
F_53 () ;
F_54 ( V_56 , V_57 ) ;
V_58 ++ ;
V_56 = F_55 ( V_56 , V_59 , V_58 ) ;
V_57 = F_55 ( V_57 , V_60 , V_58 ) ;
}
}
void F_56 ( struct V_55 * V_56 , struct V_55 * V_57 )
{
int V_58 ;
struct V_34 * V_35 = F_51 ( V_57 ) ;
if ( F_57 ( F_52 ( V_35 ) > V_61 ) ) {
F_50 ( V_56 , V_57 ) ;
return;
}
F_58 () ;
for ( V_58 = 0 ; V_58 < F_52 ( V_35 ) ; V_58 ++ ) {
F_53 () ;
F_54 ( V_56 + V_58 , V_57 + V_58 ) ;
}
}
static void F_59 ( struct V_34 * V_35 , struct V_55 * V_55 )
{
int V_62 = F_60 ( V_55 ) ;
F_61 ( & V_55 -> V_63 , & V_35 -> V_64 [ V_62 ] ) ;
V_35 -> V_65 ++ ;
V_35 -> V_66 [ V_62 ] ++ ;
}
static struct V_55 * F_62 ( struct V_34 * V_35 , int V_62 )
{
struct V_55 * V_55 ;
F_17 (page, &h->hugepage_freelists[nid], lru)
if ( ! F_63 ( V_55 ) )
break;
if ( & V_35 -> V_64 [ V_62 ] == & V_55 -> V_63 )
return NULL ;
F_61 ( & V_55 -> V_63 , & V_35 -> V_67 ) ;
F_64 ( V_55 ) ;
V_35 -> V_65 -- ;
V_35 -> V_66 [ V_62 ] -- ;
return V_55 ;
}
static inline T_2 F_65 ( struct V_34 * V_35 )
{
if ( V_68 || F_66 ( V_35 ) )
return V_69 ;
else
return V_70 ;
}
static struct V_55 * F_67 ( struct V_34 * V_35 ,
struct V_14 * V_15 ,
unsigned long V_36 , int V_71 ,
long V_28 )
{
struct V_55 * V_55 = NULL ;
struct V_72 * V_73 ;
T_3 * V_74 ;
struct V_75 * V_75 ;
struct V_76 * V_76 ;
struct V_77 * V_78 ;
unsigned int V_79 ;
if ( ! F_49 ( V_15 , V_28 ) &&
V_35 -> V_65 - V_35 -> V_80 == 0 )
goto V_81;
if ( V_71 && V_35 -> V_65 - V_35 -> V_80 == 0 )
goto V_81;
V_82:
V_79 = F_68 () ;
V_75 = F_69 ( V_15 , V_36 ,
F_65 ( V_35 ) , & V_73 , & V_74 ) ;
F_70 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_71 ( V_76 , F_65 ( V_35 ) ) ) {
V_55 = F_62 ( V_35 , F_72 ( V_76 ) ) ;
if ( V_55 ) {
if ( V_71 )
break;
if ( ! F_49 ( V_15 , V_28 ) )
break;
F_73 ( V_55 ) ;
V_35 -> V_80 -- ;
break;
}
}
}
F_74 ( V_73 ) ;
if ( F_57 ( ! F_75 ( V_79 ) && ! V_55 ) )
goto V_82;
return V_55 ;
V_81:
return NULL ;
}
static void F_76 ( struct V_34 * V_35 , struct V_55 * V_55 )
{
int V_58 ;
F_44 ( V_35 -> V_83 >= V_84 ) ;
V_35 -> V_85 -- ;
V_35 -> V_86 [ F_60 ( V_55 ) ] -- ;
for ( V_58 = 0 ; V_58 < F_52 ( V_35 ) ; V_58 ++ ) {
V_55 [ V_58 ] . V_51 &= ~ ( 1 << V_87 | 1 << V_88 |
1 << V_89 | 1 << V_90 |
1 << V_91 | 1 << V_92 |
1 << V_93 | 1 << V_94 ) ;
}
F_44 ( F_77 ( V_55 ) ) ;
F_78 ( V_55 , NULL ) ;
F_64 ( V_55 ) ;
F_79 ( V_55 ) ;
F_80 ( V_55 , F_31 ( V_35 ) ) ;
}
struct V_34 * F_81 ( unsigned long V_95 )
{
struct V_34 * V_35 ;
F_82 (h) {
if ( F_83 ( V_35 ) == V_95 )
return V_35 ;
}
return NULL ;
}
static void F_84 ( struct V_55 * V_55 )
{
struct V_34 * V_35 = F_51 ( V_55 ) ;
int V_62 = F_60 ( V_55 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_85 ( V_55 ) ;
bool V_96 ;
F_86 ( V_55 , 0 ) ;
V_55 -> V_97 = NULL ;
F_9 ( F_87 ( V_55 ) ) ;
F_9 ( F_88 ( V_55 ) ) ;
V_96 = F_89 ( V_55 ) ;
F_90 ( V_55 ) ;
F_8 ( & V_98 ) ;
F_91 ( F_92 ( V_35 ) ,
F_52 ( V_35 ) , V_55 ) ;
if ( V_96 )
V_35 -> V_80 ++ ;
if ( V_35 -> V_99 [ V_62 ] && F_31 ( V_35 ) < V_84 ) {
F_19 ( & V_55 -> V_63 ) ;
F_76 ( V_35 , V_55 ) ;
V_35 -> V_100 -- ;
V_35 -> V_99 [ V_62 ] -- ;
} else {
F_93 ( V_55 ) ;
F_59 ( V_35 , V_55 ) ;
}
F_2 ( & V_98 ) ;
F_11 ( V_2 , 1 ) ;
}
static void F_94 ( struct V_34 * V_35 , struct V_55 * V_55 , int V_62 )
{
F_21 ( & V_55 -> V_63 ) ;
F_78 ( V_55 , F_84 ) ;
F_8 ( & V_98 ) ;
F_95 ( V_55 , NULL ) ;
V_35 -> V_85 ++ ;
V_35 -> V_86 [ V_62 ] ++ ;
F_2 ( & V_98 ) ;
F_96 ( V_55 ) ;
}
static void F_97 ( struct V_55 * V_55 , unsigned long V_83 )
{
int V_58 ;
int V_101 = 1 << V_83 ;
struct V_55 * V_102 = V_55 + 1 ;
F_98 ( V_55 , V_83 ) ;
F_99 ( V_55 ) ;
F_100 ( V_55 ) ;
for ( V_58 = 1 ; V_58 < V_101 ; V_58 ++ , V_102 = F_55 ( V_102 , V_55 , V_58 ) ) {
F_101 ( V_102 ) ;
F_100 ( V_102 ) ;
F_102 ( V_102 , 0 ) ;
V_102 -> V_103 = V_55 ;
}
}
int F_103 ( struct V_55 * V_55 )
{
T_4 * V_104 ;
if ( ! F_104 ( V_55 ) )
return 0 ;
V_55 = F_105 ( V_55 ) ;
V_104 = F_106 ( V_55 ) ;
return V_104 == F_84 ;
}
T_1 F_107 ( struct V_55 * V_55 )
{
struct V_55 * V_105 = F_105 ( V_55 ) ;
T_1 V_106 = F_108 ( V_105 ) ;
unsigned long V_107 ;
if ( ! F_103 ( V_105 ) )
return F_108 ( V_55 ) ;
if ( F_109 ( V_105 ) >= V_84 )
V_107 = F_110 ( V_55 ) - F_110 ( V_105 ) ;
else
V_107 = V_55 - V_105 ;
return ( V_106 << F_109 ( V_105 ) ) + V_107 ;
}
static struct V_55 * F_111 ( struct V_34 * V_35 , int V_62 )
{
struct V_55 * V_55 ;
if ( V_35 -> V_83 >= V_84 )
return NULL ;
V_55 = F_112 ( V_62 ,
F_65 ( V_35 ) | V_108 | V_109 |
V_110 | V_111 ,
F_31 ( V_35 ) ) ;
if ( V_55 ) {
if ( F_113 ( V_55 ) ) {
F_80 ( V_55 , F_31 ( V_35 ) ) ;
return NULL ;
}
F_94 ( V_35 , V_55 , V_62 ) ;
}
return V_55 ;
}
static int F_114 ( int V_62 , T_3 * V_112 )
{
V_62 = F_115 ( V_62 , * V_112 ) ;
if ( V_62 == V_113 )
V_62 = F_116 ( * V_112 ) ;
F_44 ( V_62 >= V_113 ) ;
return V_62 ;
}
static int F_117 ( int V_62 , T_3 * V_112 )
{
if ( ! F_118 ( V_62 , * V_112 ) )
V_62 = F_114 ( V_62 , V_112 ) ;
return V_62 ;
}
static int F_119 ( struct V_34 * V_35 ,
T_3 * V_112 )
{
int V_62 ;
F_44 ( ! V_112 ) ;
V_62 = F_117 ( V_35 -> V_114 , V_112 ) ;
V_35 -> V_114 = F_114 ( V_62 , V_112 ) ;
return V_62 ;
}
static int F_120 ( struct V_34 * V_35 , T_3 * V_112 )
{
int V_62 ;
F_44 ( ! V_112 ) ;
V_62 = F_117 ( V_35 -> V_115 , V_112 ) ;
V_35 -> V_115 = F_114 ( V_62 , V_112 ) ;
return V_62 ;
}
static int F_121 ( struct V_34 * V_35 , T_3 * V_112 )
{
struct V_55 * V_55 ;
int V_116 , V_117 ;
int V_10 = 0 ;
F_122 (h, nr_nodes, node, nodes_allowed) {
V_55 = F_111 ( V_35 , V_117 ) ;
if ( V_55 ) {
V_10 = 1 ;
break;
}
}
if ( V_10 )
F_123 ( V_118 ) ;
else
F_123 ( V_119 ) ;
return V_10 ;
}
static int F_124 ( struct V_34 * V_35 , T_3 * V_112 ,
bool V_120 )
{
int V_116 , V_117 ;
int V_10 = 0 ;
F_125 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_120 || V_35 -> V_99 [ V_117 ] ) &&
! F_126 ( & V_35 -> V_64 [ V_117 ] ) ) {
struct V_55 * V_55 =
F_24 ( V_35 -> V_64 [ V_117 ] . V_31 ,
struct V_55 , V_63 ) ;
F_19 ( & V_55 -> V_63 ) ;
V_35 -> V_65 -- ;
V_35 -> V_66 [ V_117 ] -- ;
if ( V_120 ) {
V_35 -> V_100 -- ;
V_35 -> V_99 [ V_117 ] -- ;
}
F_76 ( V_35 , V_55 ) ;
V_10 = 1 ;
break;
}
}
return V_10 ;
}
static void F_127 ( struct V_55 * V_55 )
{
F_8 ( & V_98 ) ;
if ( F_103 ( V_55 ) && ! F_87 ( V_55 ) ) {
struct V_34 * V_35 = F_51 ( V_55 ) ;
int V_62 = F_60 ( V_55 ) ;
F_19 ( & V_55 -> V_63 ) ;
V_35 -> V_65 -- ;
V_35 -> V_66 [ V_62 ] -- ;
F_76 ( V_35 , V_55 ) ;
}
F_2 ( & V_98 ) ;
}
void F_128 ( unsigned long V_121 , unsigned long V_122 )
{
unsigned int V_83 = 8 * sizeof( void * ) ;
unsigned long V_123 ;
struct V_34 * V_35 ;
F_82 (h)
if ( V_83 > F_31 ( V_35 ) )
V_83 = F_31 ( V_35 ) ;
F_44 ( ! F_129 ( V_121 , 1 << V_83 ) ) ;
for ( V_123 = V_121 ; V_123 < V_122 ; V_123 += 1 << V_83 )
F_127 ( F_130 ( V_123 ) ) ;
}
static struct V_55 * F_131 ( struct V_34 * V_35 , int V_62 )
{
struct V_55 * V_55 ;
unsigned int V_124 ;
if ( V_35 -> V_83 >= V_84 )
return NULL ;
F_8 ( & V_98 ) ;
if ( V_35 -> V_100 >= V_35 -> V_125 ) {
F_2 ( & V_98 ) ;
return NULL ;
} else {
V_35 -> V_85 ++ ;
V_35 -> V_100 ++ ;
}
F_2 ( & V_98 ) ;
if ( V_62 == V_126 )
V_55 = F_132 ( F_65 ( V_35 ) | V_108 |
V_110 | V_111 ,
F_31 ( V_35 ) ) ;
else
V_55 = F_112 ( V_62 ,
F_65 ( V_35 ) | V_108 | V_109 |
V_110 | V_111 , F_31 ( V_35 ) ) ;
if ( V_55 && F_113 ( V_55 ) ) {
F_80 ( V_55 , F_31 ( V_35 ) ) ;
V_55 = NULL ;
}
F_8 ( & V_98 ) ;
if ( V_55 ) {
F_21 ( & V_55 -> V_63 ) ;
V_124 = F_60 ( V_55 ) ;
F_78 ( V_55 , F_84 ) ;
F_95 ( V_55 , NULL ) ;
V_35 -> V_86 [ V_124 ] ++ ;
V_35 -> V_99 [ V_124 ] ++ ;
F_133 ( V_118 ) ;
} else {
V_35 -> V_85 -- ;
V_35 -> V_100 -- ;
F_133 ( V_119 ) ;
}
F_2 ( & V_98 ) ;
return V_55 ;
}
struct V_55 * F_134 ( struct V_34 * V_35 , int V_62 )
{
struct V_55 * V_55 = NULL ;
F_8 ( & V_98 ) ;
if ( V_35 -> V_65 - V_35 -> V_80 > 0 )
V_55 = F_62 ( V_35 , V_62 ) ;
F_2 ( & V_98 ) ;
if ( ! V_55 )
V_55 = F_131 ( V_35 , V_62 ) ;
return V_55 ;
}
static int F_135 ( struct V_34 * V_35 , int V_9 )
{
struct V_17 V_127 ;
struct V_55 * V_55 , * V_128 ;
int V_10 , V_58 ;
int V_129 , V_130 ;
bool V_131 = true ;
V_129 = ( V_35 -> V_80 + V_9 ) - V_35 -> V_65 ;
if ( V_129 <= 0 ) {
V_35 -> V_80 += V_9 ;
return 0 ;
}
V_130 = 0 ;
F_21 ( & V_127 ) ;
V_10 = - V_11 ;
V_132:
F_2 ( & V_98 ) ;
for ( V_58 = 0 ; V_58 < V_129 ; V_58 ++ ) {
V_55 = F_131 ( V_35 , V_126 ) ;
if ( ! V_55 ) {
V_131 = false ;
break;
}
F_22 ( & V_55 -> V_63 , & V_127 ) ;
}
V_130 += V_58 ;
F_8 ( & V_98 ) ;
V_129 = ( V_35 -> V_80 + V_9 ) -
( V_35 -> V_65 + V_130 ) ;
if ( V_129 > 0 ) {
if ( V_131 )
goto V_132;
goto free;
}
V_129 += V_130 ;
V_35 -> V_80 += V_9 ;
V_10 = 0 ;
F_18 (page, tmp, &surplus_list, lru) {
if ( ( -- V_129 ) < 0 )
break;
F_136 ( V_55 ) ;
F_44 ( F_87 ( V_55 ) ) ;
F_59 ( V_35 , V_55 ) ;
}
free:
F_2 ( & V_98 ) ;
F_18 (page, tmp, &surplus_list, lru)
F_96 ( V_55 ) ;
F_8 ( & V_98 ) ;
return V_10 ;
}
static void F_137 ( struct V_34 * V_35 ,
unsigned long V_133 )
{
unsigned long V_101 ;
V_35 -> V_80 -= V_133 ;
if ( V_35 -> V_83 >= V_84 )
return;
V_101 = F_28 ( V_133 , V_35 -> V_100 ) ;
while ( V_101 -- ) {
if ( ! F_124 ( V_35 , & V_134 [ V_135 ] , 1 ) )
break;
}
}
static long F_138 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_136 )
{
struct V_137 * V_97 = V_15 -> V_16 -> V_138 ;
struct V_12 * V_12 = V_97 -> V_139 ;
if ( V_15 -> V_47 & V_48 ) {
T_1 V_140 = F_29 ( V_35 , V_15 , V_136 ) ;
return F_20 ( & V_12 -> V_141 -> V_142 ,
V_140 , V_140 + 1 ) ;
} else if ( ! F_47 ( V_15 , V_54 ) ) {
return 1 ;
} else {
long V_81 ;
T_1 V_140 = F_29 ( V_35 , V_15 , V_136 ) ;
struct V_42 * V_143 = F_43 ( V_15 ) ;
V_81 = F_20 ( & V_143 -> V_44 , V_140 , V_140 + 1 ) ;
if ( V_81 < 0 )
return V_81 ;
return 0 ;
}
}
static void F_139 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_136 )
{
struct V_137 * V_97 = V_15 -> V_16 -> V_138 ;
struct V_12 * V_12 = V_97 -> V_139 ;
if ( V_15 -> V_47 & V_48 ) {
T_1 V_140 = F_29 ( V_35 , V_15 , V_136 ) ;
F_16 ( & V_12 -> V_141 -> V_142 , V_140 , V_140 + 1 ) ;
} else if ( F_47 ( V_15 , V_54 ) ) {
T_1 V_140 = F_29 ( V_35 , V_15 , V_136 ) ;
struct V_42 * V_143 = F_43 ( V_15 ) ;
F_16 ( & V_143 -> V_44 , V_140 , V_140 + 1 ) ;
}
}
static struct V_55 * F_140 ( struct V_14 * V_15 ,
unsigned long V_136 , int V_71 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_55 * V_55 ;
long V_28 ;
int V_10 , V_140 ;
struct V_144 * V_145 ;
V_140 = F_92 ( V_35 ) ;
V_28 = F_138 ( V_35 , V_15 , V_136 ) ;
if ( V_28 < 0 )
return F_141 ( - V_11 ) ;
if ( V_28 || V_71 )
if ( F_10 ( V_2 , 1 ) )
return F_141 ( - V_146 ) ;
V_10 = F_142 ( V_140 , F_52 ( V_35 ) , & V_145 ) ;
if ( V_10 ) {
if ( V_28 || V_71 )
F_11 ( V_2 , 1 ) ;
return F_141 ( - V_146 ) ;
}
F_8 ( & V_98 ) ;
V_55 = F_67 ( V_35 , V_15 , V_136 , V_71 , V_28 ) ;
if ( ! V_55 ) {
F_2 ( & V_98 ) ;
V_55 = F_131 ( V_35 , V_126 ) ;
if ( ! V_55 ) {
F_143 ( V_140 ,
F_52 ( V_35 ) ,
V_145 ) ;
if ( V_28 || V_71 )
F_11 ( V_2 , 1 ) ;
return F_141 ( - V_146 ) ;
}
F_8 ( & V_98 ) ;
F_61 ( & V_55 -> V_63 , & V_35 -> V_67 ) ;
}
F_144 ( V_140 , F_52 ( V_35 ) , V_145 , V_55 ) ;
F_2 ( & V_98 ) ;
F_86 ( V_55 , ( unsigned long ) V_2 ) ;
F_139 ( V_35 , V_15 , V_136 ) ;
return V_55 ;
}
struct V_55 * F_145 ( struct V_14 * V_15 ,
unsigned long V_136 , int V_71 )
{
struct V_55 * V_55 = F_140 ( V_15 , V_136 , V_71 ) ;
if ( F_146 ( V_55 ) )
V_55 = NULL ;
return V_55 ;
}
int __weak F_147 ( struct V_34 * V_35 )
{
struct V_147 * V_148 ;
int V_116 , V_117 ;
F_122 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_136 ;
V_136 = F_148 ( F_149 ( V_117 ) ,
F_83 ( V_35 ) , F_83 ( V_35 ) , 0 ) ;
if ( V_136 ) {
V_148 = V_136 ;
goto V_149;
}
}
return 0 ;
V_149:
F_9 ( ( unsigned long ) F_150 ( V_148 ) & ( F_83 ( V_35 ) - 1 ) ) ;
F_22 ( & V_148 -> V_150 , & V_151 ) ;
V_148 -> V_34 = V_35 ;
return 1 ;
}
static void F_151 ( struct V_55 * V_55 , int V_83 )
{
if ( F_57 ( V_83 > ( V_84 - 1 ) ) )
F_97 ( V_55 , V_83 ) ;
else
F_152 ( V_55 , V_83 ) ;
}
static void T_5 F_153 ( void )
{
struct V_147 * V_148 ;
F_17 (m, &huge_boot_pages, list) {
struct V_34 * V_35 = V_148 -> V_34 ;
struct V_55 * V_55 ;
#ifdef F_154
V_55 = F_130 ( V_148 -> V_152 >> V_153 ) ;
F_155 ( ( unsigned long ) V_148 ,
sizeof( struct V_147 ) ) ;
#else
V_55 = F_156 ( V_148 ) ;
#endif
F_157 ( F_87 ( V_55 ) != 1 ) ;
F_151 ( V_55 , V_35 -> V_83 ) ;
F_157 ( F_158 ( V_55 ) ) ;
F_94 ( V_35 , V_55 , F_60 ( V_55 ) ) ;
if ( V_35 -> V_83 > ( V_84 - 1 ) )
F_159 ( V_55 , 1 << V_35 -> V_83 ) ;
}
}
static void T_5 F_160 ( struct V_34 * V_35 )
{
unsigned long V_58 ;
for ( V_58 = 0 ; V_58 < V_35 -> V_154 ; ++ V_58 ) {
if ( V_35 -> V_83 >= V_84 ) {
if ( ! F_147 ( V_35 ) )
break;
} else if ( ! F_121 ( V_35 ,
& V_134 [ V_135 ] ) )
break;
}
V_35 -> V_154 = V_58 ;
}
static void T_5 F_161 ( void )
{
struct V_34 * V_35 ;
F_82 (h) {
if ( V_35 -> V_83 < V_84 )
F_160 ( V_35 ) ;
}
}
static char * T_5 F_162 ( char * V_155 , unsigned long V_156 )
{
if ( V_156 >= ( 1UL << 30 ) )
sprintf ( V_155 , L_1 , V_156 >> 30 ) ;
else if ( V_156 >= ( 1UL << 20 ) )
sprintf ( V_155 , L_2 , V_156 >> 20 ) ;
else
sprintf ( V_155 , L_3 , V_156 >> 10 ) ;
return V_155 ;
}
static void T_5 F_163 ( void )
{
struct V_34 * V_35 ;
F_82 (h) {
char V_155 [ 32 ] ;
F_164 ( L_4 ,
F_162 ( V_155 , F_83 ( V_35 ) ) ,
V_35 -> V_65 ) ;
}
}
static void F_165 ( struct V_34 * V_35 , unsigned long V_3 ,
T_3 * V_112 )
{
int V_58 ;
if ( V_35 -> V_83 >= V_84 )
return;
F_166 (i, *nodes_allowed) {
struct V_55 * V_55 , * V_31 ;
struct V_17 * V_157 = & V_35 -> V_64 [ V_58 ] ;
F_18 (page, next, freel, lru) {
if ( V_3 >= V_35 -> V_85 )
return;
if ( F_167 ( V_55 ) )
continue;
F_19 ( & V_55 -> V_63 ) ;
F_76 ( V_35 , V_55 ) ;
V_35 -> V_65 -- ;
V_35 -> V_66 [ F_60 ( V_55 ) ] -- ;
}
}
}
static inline void F_165 ( struct V_34 * V_35 , unsigned long V_3 ,
T_3 * V_112 )
{
}
static int F_168 ( struct V_34 * V_35 , T_3 * V_112 ,
int V_9 )
{
int V_116 , V_117 ;
F_44 ( V_9 != - 1 && V_9 != 1 ) ;
if ( V_9 < 0 ) {
F_122 (h, nr_nodes, node, nodes_allowed) {
if ( V_35 -> V_99 [ V_117 ] )
goto V_149;
}
} else {
F_125 (h, nr_nodes, node, nodes_allowed) {
if ( V_35 -> V_99 [ V_117 ] <
V_35 -> V_86 [ V_117 ] )
goto V_149;
}
}
return 0 ;
V_149:
V_35 -> V_100 += V_9 ;
V_35 -> V_99 [ V_117 ] += V_9 ;
return 1 ;
}
static unsigned long F_169 ( struct V_34 * V_35 , unsigned long V_3 ,
T_3 * V_112 )
{
unsigned long V_158 , V_10 ;
if ( V_35 -> V_83 >= V_84 )
return V_35 -> V_154 ;
F_8 ( & V_98 ) ;
while ( V_35 -> V_100 && V_3 > F_170 ( V_35 ) ) {
if ( ! F_168 ( V_35 , V_112 , - 1 ) )
break;
}
while ( V_3 > F_170 ( V_35 ) ) {
F_2 ( & V_98 ) ;
V_10 = F_121 ( V_35 , V_112 ) ;
F_8 ( & V_98 ) ;
if ( ! V_10 )
goto V_159;
if ( F_171 ( V_160 ) )
goto V_159;
}
V_158 = V_35 -> V_80 + V_35 -> V_85 - V_35 -> V_65 ;
V_158 = F_27 ( V_3 , V_158 ) ;
F_165 ( V_35 , V_158 , V_112 ) ;
while ( V_158 < F_170 ( V_35 ) ) {
if ( ! F_124 ( V_35 , V_112 , 0 ) )
break;
}
while ( V_3 < F_170 ( V_35 ) ) {
if ( ! F_168 ( V_35 , V_112 , 1 ) )
break;
}
V_159:
V_10 = F_170 ( V_35 ) ;
F_2 ( & V_98 ) ;
return V_10 ;
}
static struct V_34 * F_172 ( struct V_161 * V_162 , int * V_163 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_164 ; V_58 ++ )
if ( V_165 [ V_58 ] == V_162 ) {
if ( V_163 )
* V_163 = V_126 ;
return & V_166 [ V_58 ] ;
}
return F_173 ( V_162 , V_163 ) ;
}
static T_6 F_174 ( struct V_161 * V_162 ,
struct V_167 * V_168 , char * V_155 )
{
struct V_34 * V_35 ;
unsigned long V_85 ;
int V_62 ;
V_35 = F_172 ( V_162 , & V_62 ) ;
if ( V_62 == V_126 )
V_85 = V_35 -> V_85 ;
else
V_85 = V_35 -> V_86 [ V_62 ] ;
return sprintf ( V_155 , L_5 , V_85 ) ;
}
static T_6 F_175 ( bool V_169 ,
struct V_161 * V_162 , struct V_167 * V_168 ,
const char * V_155 , T_7 V_170 )
{
int V_81 ;
int V_62 ;
unsigned long V_3 ;
struct V_34 * V_35 ;
F_176 ( T_3 , V_112 , V_7 | V_171 ) ;
V_81 = F_177 ( V_155 , 10 , & V_3 ) ;
if ( V_81 )
goto V_159;
V_35 = F_172 ( V_162 , & V_62 ) ;
if ( V_35 -> V_83 >= V_84 ) {
V_81 = - V_172 ;
goto V_159;
}
if ( V_62 == V_126 ) {
if ( ! ( V_169 &&
F_178 ( V_112 ) ) ) {
F_179 ( V_112 ) ;
V_112 = & V_134 [ V_135 ] ;
}
} else if ( V_112 ) {
V_3 += V_35 -> V_85 - V_35 -> V_86 [ V_62 ] ;
F_180 ( V_112 , V_62 ) ;
} else
V_112 = & V_134 [ V_135 ] ;
V_35 -> V_154 = F_169 ( V_35 , V_3 , V_112 ) ;
if ( V_112 != & V_134 [ V_135 ] )
F_179 ( V_112 ) ;
return V_170 ;
V_159:
F_179 ( V_112 ) ;
return V_81 ;
}
static T_6 F_181 ( struct V_161 * V_162 ,
struct V_167 * V_168 , char * V_155 )
{
return F_174 ( V_162 , V_168 , V_155 ) ;
}
static T_6 F_182 ( struct V_161 * V_162 ,
struct V_167 * V_168 , const char * V_155 , T_7 V_170 )
{
return F_175 ( false , V_162 , V_168 , V_155 , V_170 ) ;
}
static T_6 F_183 ( struct V_161 * V_162 ,
struct V_167 * V_168 , char * V_155 )
{
return F_174 ( V_162 , V_168 , V_155 ) ;
}
static T_6 F_184 ( struct V_161 * V_162 ,
struct V_167 * V_168 , const char * V_155 , T_7 V_170 )
{
return F_175 ( true , V_162 , V_168 , V_155 , V_170 ) ;
}
static T_6 F_185 ( struct V_161 * V_162 ,
struct V_167 * V_168 , char * V_155 )
{
struct V_34 * V_35 = F_172 ( V_162 , NULL ) ;
return sprintf ( V_155 , L_5 , V_35 -> V_125 ) ;
}
static T_6 F_186 ( struct V_161 * V_162 ,
struct V_167 * V_168 , const char * V_155 , T_7 V_3 )
{
int V_81 ;
unsigned long V_173 ;
struct V_34 * V_35 = F_172 ( V_162 , NULL ) ;
if ( V_35 -> V_83 >= V_84 )
return - V_172 ;
V_81 = F_177 ( V_155 , 10 , & V_173 ) ;
if ( V_81 )
return V_81 ;
F_8 ( & V_98 ) ;
V_35 -> V_125 = V_173 ;
F_2 ( & V_98 ) ;
return V_3 ;
}
static T_6 F_187 ( struct V_161 * V_162 ,
struct V_167 * V_168 , char * V_155 )
{
struct V_34 * V_35 ;
unsigned long V_65 ;
int V_62 ;
V_35 = F_172 ( V_162 , & V_62 ) ;
if ( V_62 == V_126 )
V_65 = V_35 -> V_65 ;
else
V_65 = V_35 -> V_66 [ V_62 ] ;
return sprintf ( V_155 , L_5 , V_65 ) ;
}
static T_6 F_188 ( struct V_161 * V_162 ,
struct V_167 * V_168 , char * V_155 )
{
struct V_34 * V_35 = F_172 ( V_162 , NULL ) ;
return sprintf ( V_155 , L_5 , V_35 -> V_80 ) ;
}
static T_6 F_189 ( struct V_161 * V_162 ,
struct V_167 * V_168 , char * V_155 )
{
struct V_34 * V_35 ;
unsigned long V_100 ;
int V_62 ;
V_35 = F_172 ( V_162 , & V_62 ) ;
if ( V_62 == V_126 )
V_100 = V_35 -> V_100 ;
else
V_100 = V_35 -> V_99 [ V_62 ] ;
return sprintf ( V_155 , L_5 , V_100 ) ;
}
static int F_190 ( struct V_34 * V_35 , struct V_161 * V_174 ,
struct V_161 * * V_165 ,
struct V_175 * V_176 )
{
int V_177 ;
int V_178 = F_92 ( V_35 ) ;
V_165 [ V_178 ] = F_191 ( V_35 -> V_179 , V_174 ) ;
if ( ! V_165 [ V_178 ] )
return - V_11 ;
V_177 = F_192 ( V_165 [ V_178 ] , V_176 ) ;
if ( V_177 )
F_193 ( V_165 [ V_178 ] ) ;
return V_177 ;
}
static void T_5 F_194 ( void )
{
struct V_34 * V_35 ;
int V_81 ;
V_180 = F_191 ( L_6 , V_181 ) ;
if ( ! V_180 )
return;
F_82 (h) {
V_81 = F_190 ( V_35 , V_180 ,
V_165 , & V_176 ) ;
if ( V_81 )
F_195 ( L_7 , V_35 -> V_179 ) ;
}
}
static struct V_34 * F_173 ( struct V_161 * V_162 , int * V_163 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_182 ; V_62 ++ ) {
struct V_183 * V_184 = & V_185 [ V_62 ] ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_164 ; V_58 ++ )
if ( V_184 -> V_165 [ V_58 ] == V_162 ) {
if ( V_163 )
* V_163 = V_62 ;
return & V_166 [ V_58 ] ;
}
}
F_196 () ;
return NULL ;
}
static void F_197 ( struct V_117 * V_117 )
{
struct V_34 * V_35 ;
struct V_183 * V_184 = & V_185 [ V_117 -> V_186 . V_187 ] ;
if ( ! V_184 -> V_180 )
return;
F_82 (h) {
int V_140 = F_92 ( V_35 ) ;
if ( V_184 -> V_165 [ V_140 ] ) {
F_193 ( V_184 -> V_165 [ V_140 ] ) ;
V_184 -> V_165 [ V_140 ] = NULL ;
}
}
F_193 ( V_184 -> V_180 ) ;
V_184 -> V_180 = NULL ;
}
static void F_198 ( void )
{
int V_62 ;
F_199 ( NULL , NULL ) ;
for ( V_62 = 0 ; V_62 < V_182 ; V_62 ++ )
F_197 ( V_188 [ V_62 ] ) ;
}
static void F_200 ( struct V_117 * V_117 )
{
struct V_34 * V_35 ;
struct V_183 * V_184 = & V_185 [ V_117 -> V_186 . V_187 ] ;
int V_81 ;
if ( V_184 -> V_180 )
return;
V_184 -> V_180 = F_191 ( L_6 ,
& V_117 -> V_186 . V_162 ) ;
if ( ! V_184 -> V_180 )
return;
F_82 (h) {
V_81 = F_190 ( V_35 , V_184 -> V_180 ,
V_184 -> V_165 ,
& V_189 ) ;
if ( V_81 ) {
F_195 ( L_8 ,
V_35 -> V_179 , V_117 -> V_186 . V_187 ) ;
F_197 ( V_117 ) ;
break;
}
}
}
static void F_201 ( void )
{
int V_62 ;
F_202 (nid, N_MEMORY) {
struct V_117 * V_117 = V_188 [ V_62 ] ;
if ( V_117 -> V_186 . V_187 == V_62 )
F_200 ( V_117 ) ;
}
F_199 ( F_200 ,
F_197 ) ;
}
static struct V_34 * F_173 ( struct V_161 * V_162 , int * V_163 )
{
F_196 () ;
if ( V_163 )
* V_163 = - 1 ;
return NULL ;
}
static void F_198 ( void ) { }
static void F_201 ( void ) { }
static void T_8 F_203 ( void )
{
struct V_34 * V_35 ;
F_198 () ;
F_82 (h) {
F_193 ( V_165 [ F_92 ( V_35 ) ] ) ;
}
F_193 ( V_180 ) ;
}
static int T_5 F_204 ( void )
{
if ( V_190 == 0 )
return 0 ;
if ( ! F_81 ( V_191 ) ) {
V_191 = V_192 ;
if ( ! F_81 ( V_191 ) )
F_205 ( V_193 ) ;
}
V_194 = F_92 ( F_81 ( V_191 ) ) ;
if ( V_195 )
V_196 . V_154 = V_195 ;
F_161 () ;
F_153 () ;
F_163 () ;
F_194 () ;
F_201 () ;
F_206 () ;
return 0 ;
}
void T_5 F_205 ( unsigned V_83 )
{
struct V_34 * V_35 ;
unsigned long V_58 ;
if ( F_81 ( V_39 << V_83 ) ) {
F_207 ( L_9 ) ;
return;
}
F_9 ( V_197 >= V_164 ) ;
F_9 ( V_83 == 0 ) ;
V_35 = & V_166 [ V_197 ++ ] ;
V_35 -> V_83 = V_83 ;
V_35 -> V_198 = ~ ( ( 1ULL << ( V_83 + V_153 ) ) - 1 ) ;
V_35 -> V_85 = 0 ;
V_35 -> V_65 = 0 ;
for ( V_58 = 0 ; V_58 < V_113 ; ++ V_58 )
F_21 ( & V_35 -> V_64 [ V_58 ] ) ;
F_21 ( & V_35 -> V_67 ) ;
V_35 -> V_114 = F_116 ( V_134 [ V_135 ] ) ;
V_35 -> V_115 = F_116 ( V_134 [ V_135 ] ) ;
snprintf ( V_35 -> V_179 , V_199 , L_10 ,
F_83 ( V_35 ) / 1024 ) ;
V_200 = V_35 ;
}
static int T_5 F_208 ( char * V_201 )
{
unsigned long * V_202 ;
static unsigned long * V_203 ;
if ( ! V_197 )
V_202 = & V_195 ;
else
V_202 = & V_200 -> V_154 ;
if ( V_202 == V_203 ) {
F_207 ( L_11
L_12 ) ;
return 1 ;
}
if ( sscanf ( V_201 , L_13 , V_202 ) <= 0 )
* V_202 = 0 ;
if ( V_197 && V_200 -> V_83 >= V_84 )
F_160 ( V_200 ) ;
V_203 = V_202 ;
return 1 ;
}
static int T_5 F_209 ( char * V_201 )
{
V_191 = F_210 ( V_201 , & V_201 ) ;
return 1 ;
}
static unsigned int F_211 ( unsigned int * V_204 )
{
int V_117 ;
unsigned int V_205 = 0 ;
F_166 (node, cpuset_current_mems_allowed)
V_205 += V_204 [ V_117 ] ;
return V_205 ;
}
static int F_212 ( bool V_169 ,
struct V_206 * V_207 , int V_208 ,
void T_9 * V_209 , T_7 * V_210 , T_10 * V_211 )
{
struct V_34 * V_35 = & V_196 ;
unsigned long V_128 ;
int V_10 ;
V_128 = V_35 -> V_154 ;
if ( V_208 && V_35 -> V_83 >= V_84 )
return - V_172 ;
V_207 -> V_212 = & V_128 ;
V_207 -> V_213 = sizeof( unsigned long ) ;
V_10 = F_213 ( V_207 , V_208 , V_209 , V_210 , V_211 ) ;
if ( V_10 )
goto V_159;
if ( V_208 ) {
F_176 ( T_3 , V_112 ,
V_7 | V_171 ) ;
if ( ! ( V_169 &&
F_178 ( V_112 ) ) ) {
F_179 ( V_112 ) ;
V_112 = & V_134 [ V_135 ] ;
}
V_35 -> V_154 = F_169 ( V_35 , V_128 , V_112 ) ;
if ( V_112 != & V_134 [ V_135 ] )
F_179 ( V_112 ) ;
}
V_159:
return V_10 ;
}
int F_214 ( struct V_206 * V_207 , int V_208 ,
void T_9 * V_209 , T_7 * V_210 , T_10 * V_211 )
{
return F_212 ( false , V_207 , V_208 ,
V_209 , V_210 , V_211 ) ;
}
int F_215 ( struct V_206 * V_207 , int V_208 ,
void T_9 * V_209 , T_7 * V_210 , T_10 * V_211 )
{
return F_212 ( true , V_207 , V_208 ,
V_209 , V_210 , V_211 ) ;
}
int F_216 ( struct V_206 * V_207 , int V_208 ,
void T_9 * V_209 ,
T_7 * V_210 , T_10 * V_211 )
{
struct V_34 * V_35 = & V_196 ;
unsigned long V_128 ;
int V_10 ;
V_128 = V_35 -> V_125 ;
if ( V_208 && V_35 -> V_83 >= V_84 )
return - V_172 ;
V_207 -> V_212 = & V_128 ;
V_207 -> V_213 = sizeof( unsigned long ) ;
V_10 = F_213 ( V_207 , V_208 , V_209 , V_210 , V_211 ) ;
if ( V_10 )
goto V_159;
if ( V_208 ) {
F_8 ( & V_98 ) ;
V_35 -> V_125 = V_128 ;
F_2 ( & V_98 ) ;
}
V_159:
return V_10 ;
}
void F_217 ( struct V_214 * V_148 )
{
struct V_34 * V_35 = & V_196 ;
F_218 ( V_148 ,
L_14
L_15
L_16
L_17
L_18 ,
V_35 -> V_85 ,
V_35 -> V_65 ,
V_35 -> V_80 ,
V_35 -> V_100 ,
1UL << ( F_31 ( V_35 ) + V_153 - 10 ) ) ;
}
int F_219 ( int V_62 , char * V_155 )
{
struct V_34 * V_35 = & V_196 ;
return sprintf ( V_155 ,
L_19
L_20
L_21 ,
V_62 , V_35 -> V_86 [ V_62 ] ,
V_62 , V_35 -> V_66 [ V_62 ] ,
V_62 , V_35 -> V_99 [ V_62 ] ) ;
}
void F_220 ( void )
{
struct V_34 * V_35 ;
int V_62 ;
F_202 (nid, N_MEMORY)
F_82 (h)
F_164 ( L_22 ,
V_62 ,
V_35 -> V_86 [ V_62 ] ,
V_35 -> V_66 [ V_62 ] ,
V_35 -> V_99 [ V_62 ] ,
1UL << ( F_31 ( V_35 ) + V_153 - 10 ) ) ;
}
unsigned long F_221 ( void )
{
struct V_34 * V_35 ;
unsigned long V_215 = 0 ;
F_82 (h)
V_215 += V_35 -> V_85 * F_52 ( V_35 ) ;
return V_215 ;
}
static int F_222 ( struct V_34 * V_35 , long V_9 )
{
int V_10 = - V_11 ;
F_8 ( & V_98 ) ;
if ( V_9 > 0 ) {
if ( F_135 ( V_35 , V_9 ) < 0 )
goto V_159;
if ( V_9 > F_211 ( V_35 -> V_66 ) ) {
F_137 ( V_35 , V_9 ) ;
goto V_159;
}
}
V_10 = 0 ;
if ( V_9 < 0 )
F_137 ( V_35 , ( unsigned long ) - V_9 ) ;
V_159:
F_2 ( & V_98 ) ;
return V_10 ;
}
static void F_223 ( struct V_14 * V_15 )
{
struct V_42 * V_143 = F_43 ( V_15 ) ;
if ( V_143 )
F_224 ( & V_143 -> V_43 ) ;
}
static void F_225 ( struct V_14 * V_15 )
{
struct V_42 * V_143 = F_43 ( V_15 ) ;
if ( ! V_143 )
return;
F_226 ( & V_143 -> V_43 , F_41 ) ;
}
static void F_227 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_42 * V_143 = F_43 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_15 ) ;
unsigned long V_216 ;
unsigned long V_217 ;
unsigned long V_30 ;
if ( V_143 ) {
V_217 = F_29 ( V_35 , V_15 , V_15 -> V_37 ) ;
V_30 = F_29 ( V_35 , V_15 , V_15 -> V_218 ) ;
V_216 = ( V_30 - V_217 ) -
F_26 ( & V_143 -> V_44 , V_217 , V_30 ) ;
F_225 ( V_15 ) ;
if ( V_216 ) {
F_222 ( V_35 , - V_216 ) ;
F_11 ( V_2 , V_216 ) ;
}
}
}
static int F_228 ( struct V_14 * V_15 , struct V_219 * V_220 )
{
F_196 () ;
return 0 ;
}
static T_11 F_229 ( struct V_14 * V_15 , struct V_55 * V_55 ,
int V_221 )
{
T_11 V_222 ;
if ( V_221 ) {
V_222 = F_230 ( F_231 ( F_232 ( V_55 ,
V_15 -> V_223 ) ) ) ;
} else {
V_222 = F_233 ( F_232 ( V_55 ,
V_15 -> V_223 ) ) ;
}
V_222 = F_234 ( V_222 ) ;
V_222 = F_235 ( V_222 ) ;
V_222 = F_236 ( V_222 , V_15 , V_55 , V_221 ) ;
return V_222 ;
}
static void F_237 ( struct V_14 * V_15 ,
unsigned long V_36 , T_11 * V_224 )
{
T_11 V_222 ;
V_222 = F_230 ( F_231 ( F_238 ( V_224 ) ) ) ;
if ( F_239 ( V_15 , V_36 , V_224 , V_222 , 1 ) )
F_240 ( V_15 , V_36 , V_224 ) ;
}
int F_241 ( struct V_225 * V_56 , struct V_225 * V_57 ,
struct V_14 * V_15 )
{
T_11 * V_226 , * V_227 , V_222 ;
struct V_55 * V_228 ;
unsigned long V_136 ;
int V_229 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_230 = F_83 ( V_35 ) ;
V_229 = ( V_15 -> V_47 & ( V_231 | V_232 ) ) == V_232 ;
for ( V_136 = V_15 -> V_37 ; V_136 < V_15 -> V_218 ; V_136 += V_230 ) {
V_226 = F_242 ( V_57 , V_136 ) ;
if ( ! V_226 )
continue;
V_227 = F_243 ( V_56 , V_136 , V_230 ) ;
if ( ! V_227 )
goto V_233;
if ( V_227 == V_226 )
continue;
F_8 ( & V_56 -> V_234 ) ;
F_244 ( & V_57 -> V_234 , V_235 ) ;
if ( ! F_245 ( F_238 ( V_226 ) ) ) {
if ( V_229 )
F_246 ( V_57 , V_136 , V_226 ) ;
V_222 = F_238 ( V_226 ) ;
V_228 = F_247 ( V_222 ) ;
F_248 ( V_228 ) ;
F_249 ( V_228 ) ;
F_250 ( V_56 , V_136 , V_227 , V_222 ) ;
}
F_2 ( & V_57 -> V_234 ) ;
F_2 ( & V_56 -> V_234 ) ;
}
return 0 ;
V_233:
return - V_11 ;
}
static int F_251 ( T_11 V_236 )
{
T_12 V_237 ;
if ( F_245 ( V_236 ) || F_252 ( V_236 ) )
return 0 ;
V_237 = F_253 ( V_236 ) ;
if ( F_254 ( V_237 ) && F_255 ( V_237 ) )
return 1 ;
else
return 0 ;
}
static int F_256 ( T_11 V_236 )
{
T_12 V_237 ;
if ( F_245 ( V_236 ) || F_252 ( V_236 ) )
return 0 ;
V_237 = F_253 ( V_236 ) ;
if ( F_254 ( V_237 ) && F_257 ( V_237 ) )
return 1 ;
else
return 0 ;
}
void F_258 ( struct V_238 * V_239 , struct V_14 * V_15 ,
unsigned long V_217 , unsigned long V_30 ,
struct V_55 * V_240 )
{
int V_241 = 0 ;
struct V_225 * V_242 = V_15 -> V_243 ;
unsigned long V_36 ;
T_11 * V_224 ;
T_11 V_236 ;
struct V_55 * V_55 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_230 = F_83 ( V_35 ) ;
const unsigned long V_244 = V_217 ;
const unsigned long V_245 = V_30 ;
F_157 ( ! F_35 ( V_15 ) ) ;
F_9 ( V_217 & ~ F_259 ( V_35 ) ) ;
F_9 ( V_30 & ~ F_259 ( V_35 ) ) ;
F_260 ( V_239 , V_15 ) ;
F_261 ( V_242 , V_244 , V_245 ) ;
V_246:
F_8 ( & V_242 -> V_234 ) ;
for ( V_36 = V_217 ; V_36 < V_30 ; V_36 += V_230 ) {
V_224 = F_242 ( V_242 , V_36 ) ;
if ( ! V_224 )
continue;
if ( F_262 ( V_242 , & V_36 , V_224 ) )
continue;
V_236 = F_238 ( V_224 ) ;
if ( F_245 ( V_236 ) )
continue;
if ( F_57 ( F_256 ( V_236 ) ) ) {
F_263 ( V_242 , V_36 , V_224 ) ;
continue;
}
V_55 = F_247 ( V_236 ) ;
if ( V_240 ) {
if ( V_55 != V_240 )
continue;
F_46 ( V_15 , V_247 ) ;
}
V_236 = F_264 ( V_242 , V_36 , V_224 ) ;
F_265 ( V_239 , V_224 , V_36 ) ;
if ( F_266 ( V_236 ) )
F_267 ( V_55 ) ;
F_268 ( V_55 ) ;
V_241 = ! F_269 ( V_239 , V_55 ) ;
if ( V_241 )
break;
if ( V_240 )
break;
}
F_2 ( & V_242 -> V_234 ) ;
if ( V_241 ) {
V_241 = 0 ;
F_270 ( V_239 ) ;
if ( V_36 < V_30 && ! V_240 )
goto V_246;
}
F_271 ( V_242 , V_244 , V_245 ) ;
F_272 ( V_239 , V_15 ) ;
}
void F_273 ( struct V_238 * V_239 ,
struct V_14 * V_15 , unsigned long V_217 ,
unsigned long V_30 , struct V_55 * V_240 )
{
F_258 ( V_239 , V_15 , V_217 , V_30 , V_240 ) ;
V_15 -> V_47 &= ~ V_48 ;
}
void F_274 ( struct V_14 * V_15 , unsigned long V_217 ,
unsigned long V_30 , struct V_55 * V_240 )
{
struct V_225 * V_242 ;
struct V_238 V_239 ;
V_242 = V_15 -> V_243 ;
F_275 ( & V_239 , V_242 , V_217 , V_30 ) ;
F_258 ( & V_239 , V_15 , V_217 , V_30 , V_240 ) ;
F_276 ( & V_239 , V_217 , V_30 ) ;
}
static int F_277 ( struct V_225 * V_242 , struct V_14 * V_15 ,
struct V_55 * V_55 , unsigned long V_36 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_14 * V_248 ;
struct V_137 * V_97 ;
T_1 V_249 ;
V_36 = V_36 & F_259 ( V_35 ) ;
V_249 = ( ( V_36 - V_15 -> V_37 ) >> V_153 ) +
V_15 -> V_38 ;
V_97 = F_15 ( V_15 -> V_16 ) -> V_141 ;
F_278 ( & V_97 -> V_250 ) ;
F_279 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_248 == V_15 )
continue;
if ( ! F_47 ( V_248 , V_54 ) )
F_274 ( V_248 , V_36 ,
V_36 + F_83 ( V_35 ) , V_55 ) ;
}
F_280 ( & V_97 -> V_250 ) ;
return 1 ;
}
static int F_281 ( struct V_225 * V_242 , struct V_14 * V_15 ,
unsigned long V_36 , T_11 * V_224 , T_11 V_236 ,
struct V_55 * V_251 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_55 * V_252 , * V_253 ;
int V_254 = 0 ;
unsigned long V_244 ;
unsigned long V_245 ;
V_252 = F_247 ( V_236 ) ;
V_255:
if ( F_88 ( V_252 ) == 1 && F_282 ( V_252 ) ) {
F_283 ( V_252 , V_15 , V_36 ) ;
F_237 ( V_15 , V_36 , V_224 ) ;
return 0 ;
}
if ( F_47 ( V_15 , V_54 ) &&
V_252 != V_251 )
V_254 = 1 ;
F_284 ( V_252 ) ;
F_2 ( & V_242 -> V_234 ) ;
V_253 = F_140 ( V_15 , V_36 , V_254 ) ;
if ( F_146 ( V_253 ) ) {
long V_81 = F_285 ( V_253 ) ;
F_286 ( V_252 ) ;
if ( V_254 ) {
F_9 ( F_245 ( V_236 ) ) ;
if ( F_277 ( V_242 , V_15 , V_252 , V_36 ) ) {
F_9 ( F_245 ( V_236 ) ) ;
F_8 ( & V_242 -> V_234 ) ;
V_224 = F_242 ( V_242 , V_36 & F_259 ( V_35 ) ) ;
if ( F_287 ( F_288 ( F_238 ( V_224 ) , V_236 ) ) )
goto V_255;
return 0 ;
}
F_289 ( 1 ) ;
}
F_8 ( & V_242 -> V_234 ) ;
if ( V_81 == - V_11 )
return V_256 ;
else
return V_257 ;
}
if ( F_57 ( F_290 ( V_15 ) ) ) {
F_286 ( V_253 ) ;
F_286 ( V_252 ) ;
F_8 ( & V_242 -> V_234 ) ;
return V_256 ;
}
F_291 ( V_253 , V_252 , V_36 , V_15 ,
F_52 ( V_35 ) ) ;
F_292 ( V_253 ) ;
V_244 = V_36 & F_259 ( V_35 ) ;
V_245 = V_244 + F_83 ( V_35 ) ;
F_261 ( V_242 , V_244 , V_245 ) ;
F_8 ( & V_242 -> V_234 ) ;
V_224 = F_242 ( V_242 , V_36 & F_259 ( V_35 ) ) ;
if ( F_287 ( F_288 ( F_238 ( V_224 ) , V_236 ) ) ) {
F_90 ( V_253 ) ;
F_293 ( V_15 , V_36 , V_224 ) ;
F_250 ( V_242 , V_36 , V_224 ,
F_229 ( V_15 , V_253 , 1 ) ) ;
F_268 ( V_252 ) ;
F_294 ( V_253 , V_15 , V_36 ) ;
V_253 = V_252 ;
}
F_2 ( & V_242 -> V_234 ) ;
F_271 ( V_242 , V_244 , V_245 ) ;
F_286 ( V_253 ) ;
F_286 ( V_252 ) ;
F_8 ( & V_242 -> V_234 ) ;
return 0 ;
}
static struct V_55 * F_295 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_36 )
{
struct V_137 * V_97 ;
T_1 V_140 ;
V_97 = V_15 -> V_16 -> V_138 ;
V_140 = F_29 ( V_35 , V_15 , V_36 ) ;
return F_296 ( V_97 , V_140 ) ;
}
static bool F_297 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_36 )
{
struct V_137 * V_97 ;
T_1 V_140 ;
struct V_55 * V_55 ;
V_97 = V_15 -> V_16 -> V_138 ;
V_140 = F_29 ( V_35 , V_15 , V_36 ) ;
V_55 = F_298 ( V_97 , V_140 ) ;
if ( V_55 )
F_96 ( V_55 ) ;
return V_55 != NULL ;
}
static int F_299 ( struct V_225 * V_242 , struct V_14 * V_15 ,
unsigned long V_36 , T_11 * V_224 , unsigned int V_51 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
int V_10 = V_257 ;
int V_258 = 0 ;
T_1 V_140 ;
unsigned long V_95 ;
struct V_55 * V_55 ;
struct V_137 * V_97 ;
T_11 V_259 ;
if ( F_47 ( V_15 , V_247 ) ) {
F_207 ( L_23 ,
V_160 -> V_260 ) ;
return V_10 ;
}
V_97 = V_15 -> V_16 -> V_138 ;
V_140 = F_29 ( V_35 , V_15 , V_36 ) ;
V_132:
V_55 = F_296 ( V_97 , V_140 ) ;
if ( ! V_55 ) {
V_95 = F_300 ( V_97 -> V_139 ) >> F_30 ( V_35 ) ;
if ( V_140 >= V_95 )
goto V_159;
V_55 = F_140 ( V_15 , V_36 , 0 ) ;
if ( F_146 ( V_55 ) ) {
V_10 = F_285 ( V_55 ) ;
if ( V_10 == - V_11 )
V_10 = V_256 ;
else
V_10 = V_257 ;
goto V_159;
}
F_301 ( V_55 , V_36 , F_52 ( V_35 ) ) ;
F_292 ( V_55 ) ;
if ( V_15 -> V_47 & V_48 ) {
int V_81 ;
struct V_12 * V_12 = V_97 -> V_139 ;
V_81 = F_302 ( V_55 , V_97 , V_140 , V_7 ) ;
if ( V_81 ) {
F_96 ( V_55 ) ;
if ( V_81 == - V_261 )
goto V_132;
goto V_159;
}
F_90 ( V_55 ) ;
F_8 ( & V_12 -> V_262 ) ;
V_12 -> V_263 += F_303 ( V_35 ) ;
F_2 ( & V_12 -> V_262 ) ;
} else {
F_304 ( V_55 ) ;
if ( F_57 ( F_290 ( V_15 ) ) ) {
V_10 = V_256 ;
goto V_264;
}
V_258 = 1 ;
}
} else {
if ( F_57 ( F_305 ( V_55 ) ) ) {
V_10 = V_265 |
F_306 ( F_92 ( V_35 ) ) ;
goto V_264;
}
}
if ( ( V_51 & V_266 ) && ! ( V_15 -> V_47 & V_231 ) )
if ( F_138 ( V_35 , V_15 , V_36 ) < 0 ) {
V_10 = V_256 ;
goto V_264;
}
F_8 ( & V_242 -> V_234 ) ;
V_95 = F_300 ( V_97 -> V_139 ) >> F_30 ( V_35 ) ;
if ( V_140 >= V_95 )
goto V_267;
V_10 = 0 ;
if ( ! F_245 ( F_238 ( V_224 ) ) )
goto V_267;
if ( V_258 ) {
F_90 ( V_55 ) ;
F_294 ( V_55 , V_15 , V_36 ) ;
}
else
F_249 ( V_55 ) ;
V_259 = F_229 ( V_15 , V_55 , ( ( V_15 -> V_47 & V_268 )
&& ( V_15 -> V_47 & V_231 ) ) ) ;
F_250 ( V_242 , V_36 , V_224 , V_259 ) ;
if ( ( V_51 & V_266 ) && ! ( V_15 -> V_47 & V_231 ) ) {
V_10 = F_281 ( V_242 , V_15 , V_36 , V_224 , V_259 , V_55 ) ;
}
F_2 ( & V_242 -> V_234 ) ;
F_307 ( V_55 ) ;
V_159:
return V_10 ;
V_267:
F_2 ( & V_242 -> V_234 ) ;
V_264:
F_307 ( V_55 ) ;
F_96 ( V_55 ) ;
goto V_159;
}
int F_308 ( struct V_225 * V_242 , struct V_14 * V_15 ,
unsigned long V_36 , unsigned int V_51 )
{
T_11 * V_224 ;
T_11 V_222 ;
int V_10 ;
struct V_55 * V_55 = NULL ;
struct V_55 * V_251 = NULL ;
static F_309 ( V_269 ) ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
V_36 &= F_259 ( V_35 ) ;
V_224 = F_242 ( V_242 , V_36 ) ;
if ( V_224 ) {
V_222 = F_238 ( V_224 ) ;
if ( F_57 ( F_251 ( V_222 ) ) ) {
F_310 ( V_242 , V_224 ) ;
return 0 ;
} else if ( F_57 ( F_256 ( V_222 ) ) )
return V_270 |
F_306 ( F_92 ( V_35 ) ) ;
}
V_224 = F_243 ( V_242 , V_36 , F_83 ( V_35 ) ) ;
if ( ! V_224 )
return V_256 ;
F_278 ( & V_269 ) ;
V_222 = F_238 ( V_224 ) ;
if ( F_245 ( V_222 ) ) {
V_10 = F_299 ( V_242 , V_15 , V_36 , V_224 , V_51 ) ;
goto V_271;
}
V_10 = 0 ;
if ( ( V_51 & V_266 ) && ! F_311 ( V_222 ) ) {
if ( F_138 ( V_35 , V_15 , V_36 ) < 0 ) {
V_10 = V_256 ;
goto V_271;
}
if ( ! ( V_15 -> V_47 & V_48 ) )
V_251 = F_295 ( V_35 ,
V_15 , V_36 ) ;
}
V_55 = F_247 ( V_222 ) ;
F_248 ( V_55 ) ;
if ( V_55 != V_251 )
F_304 ( V_55 ) ;
F_8 ( & V_242 -> V_234 ) ;
if ( F_57 ( ! F_288 ( V_222 , F_238 ( V_224 ) ) ) )
goto V_272;
if ( V_51 & V_266 ) {
if ( ! F_311 ( V_222 ) ) {
V_10 = F_281 ( V_242 , V_15 , V_36 , V_224 , V_222 ,
V_251 ) ;
goto V_272;
}
V_222 = F_231 ( V_222 ) ;
}
V_222 = F_234 ( V_222 ) ;
if ( F_239 ( V_15 , V_36 , V_224 , V_222 ,
V_51 & V_266 ) )
F_240 ( V_15 , V_36 , V_224 ) ;
V_272:
F_2 ( & V_242 -> V_234 ) ;
if ( V_251 ) {
F_307 ( V_251 ) ;
F_96 ( V_251 ) ;
}
if ( V_55 != V_251 )
F_307 ( V_55 ) ;
F_96 ( V_55 ) ;
V_271:
F_280 ( & V_269 ) ;
return V_10 ;
}
long F_312 ( struct V_225 * V_242 , struct V_14 * V_15 ,
struct V_55 * * V_273 , struct V_14 * * V_274 ,
unsigned long * V_275 , unsigned long * V_101 ,
long V_58 , unsigned int V_51 )
{
unsigned long V_276 ;
unsigned long V_277 = * V_275 ;
unsigned long V_278 = * V_101 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
F_8 ( & V_242 -> V_234 ) ;
while ( V_277 < V_15 -> V_218 && V_278 ) {
T_11 * V_236 ;
int V_279 ;
struct V_55 * V_55 ;
V_236 = F_242 ( V_242 , V_277 & F_259 ( V_35 ) ) ;
V_279 = ! V_236 || F_245 ( F_238 ( V_236 ) ) ;
if ( V_279 && ( V_51 & V_280 ) &&
! F_297 ( V_35 , V_15 , V_277 ) ) {
V_278 = 0 ;
break;
}
if ( V_279 || F_313 ( F_238 ( V_236 ) ) ||
( ( V_51 & V_281 ) &&
! F_311 ( F_238 ( V_236 ) ) ) ) {
int V_10 ;
F_2 ( & V_242 -> V_234 ) ;
V_10 = F_308 ( V_242 , V_15 , V_277 ,
( V_51 & V_281 ) ? V_266 : 0 ) ;
F_8 ( & V_242 -> V_234 ) ;
if ( ! ( V_10 & V_282 ) )
continue;
V_278 = 0 ;
break;
}
V_276 = ( V_277 & ~ F_259 ( V_35 ) ) >> V_153 ;
V_55 = F_247 ( F_238 ( V_236 ) ) ;
V_283:
if ( V_273 ) {
V_273 [ V_58 ] = F_314 ( V_55 , V_276 ) ;
F_248 ( V_273 [ V_58 ] ) ;
}
if ( V_274 )
V_274 [ V_58 ] = V_15 ;
V_277 += V_39 ;
++ V_276 ;
-- V_278 ;
++ V_58 ;
if ( V_277 < V_15 -> V_218 && V_278 &&
V_276 < F_52 ( V_35 ) ) {
goto V_283;
}
}
F_2 ( & V_242 -> V_234 ) ;
* V_101 = V_278 ;
* V_275 = V_277 ;
return V_58 ? V_58 : - V_284 ;
}
unsigned long F_315 ( struct V_14 * V_15 ,
unsigned long V_36 , unsigned long V_30 , T_13 V_285 )
{
struct V_225 * V_242 = V_15 -> V_243 ;
unsigned long V_217 = V_36 ;
T_11 * V_224 ;
T_11 V_236 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_273 = 0 ;
F_9 ( V_36 >= V_30 ) ;
F_316 ( V_15 , V_36 , V_30 ) ;
F_278 ( & V_15 -> V_16 -> V_138 -> V_250 ) ;
F_8 ( & V_242 -> V_234 ) ;
for (; V_36 < V_30 ; V_36 += F_83 ( V_35 ) ) {
V_224 = F_242 ( V_242 , V_36 ) ;
if ( ! V_224 )
continue;
if ( F_262 ( V_242 , & V_36 , V_224 ) ) {
V_273 ++ ;
continue;
}
if ( ! F_245 ( F_238 ( V_224 ) ) ) {
V_236 = F_264 ( V_242 , V_36 , V_224 ) ;
V_236 = F_235 ( F_317 ( V_236 , V_285 ) ) ;
V_236 = F_236 ( V_236 , V_15 , NULL , 0 ) ;
F_250 ( V_242 , V_36 , V_224 , V_236 ) ;
V_273 ++ ;
}
}
F_2 ( & V_242 -> V_234 ) ;
F_318 ( V_15 , V_217 , V_30 ) ;
F_280 ( & V_15 -> V_16 -> V_138 -> V_250 ) ;
return V_273 << V_35 -> V_83 ;
}
int F_319 ( struct V_12 * V_12 ,
long V_26 , long V_25 ,
struct V_14 * V_15 ,
T_14 V_47 )
{
long V_10 , V_28 ;
struct V_34 * V_35 = F_320 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( V_47 & V_53 )
return 0 ;
if ( ! V_15 || V_15 -> V_47 & V_48 )
V_28 = F_20 ( & V_12 -> V_141 -> V_142 , V_26 , V_25 ) ;
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
V_10 = - V_146 ;
goto V_286;
}
V_10 = F_222 ( V_35 , V_28 ) ;
if ( V_10 < 0 ) {
F_11 ( V_2 , V_28 ) ;
goto V_286;
}
if ( ! V_15 || V_15 -> V_47 & V_48 )
F_16 ( & V_12 -> V_141 -> V_142 , V_26 , V_25 ) ;
return 0 ;
V_286:
if ( V_15 )
F_225 ( V_15 ) ;
return V_10 ;
}
void F_321 ( struct V_12 * V_12 , long V_287 , long V_288 )
{
struct V_34 * V_35 = F_320 ( V_12 ) ;
long V_28 = F_23 ( & V_12 -> V_141 -> V_142 , V_287 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_8 ( & V_12 -> V_262 ) ;
V_12 -> V_263 -= ( F_303 ( V_35 ) * V_288 ) ;
F_2 ( & V_12 -> V_262 ) ;
F_11 ( V_2 , ( V_28 - V_288 ) ) ;
F_222 ( V_35 , - ( V_28 - V_288 ) ) ;
}
static unsigned long F_322 ( struct V_14 * V_289 ,
struct V_14 * V_15 ,
unsigned long V_136 , T_1 V_140 )
{
unsigned long V_290 = ( ( V_140 - V_289 -> V_38 ) << V_153 ) +
V_289 -> V_37 ;
unsigned long V_291 = V_290 & V_292 ;
unsigned long V_293 = V_291 + V_294 ;
unsigned long V_47 = V_15 -> V_47 & ~ V_295 ;
unsigned long V_296 = V_289 -> V_47 & ~ V_295 ;
if ( F_323 ( V_136 ) != F_323 ( V_290 ) ||
V_47 != V_296 ||
V_291 < V_289 -> V_37 || V_289 -> V_218 < V_293 )
return 0 ;
return V_290 ;
}
static int F_324 ( struct V_14 * V_15 , unsigned long V_136 )
{
unsigned long V_297 = V_136 & V_292 ;
unsigned long V_30 = V_297 + V_294 ;
if ( V_15 -> V_47 & V_48 &&
V_15 -> V_37 <= V_297 && V_30 <= V_15 -> V_218 )
return 1 ;
return 0 ;
}
T_11 * F_325 ( struct V_225 * V_242 , unsigned long V_136 , T_15 * V_298 )
{
struct V_14 * V_15 = F_326 ( V_242 , V_136 ) ;
struct V_137 * V_97 = V_15 -> V_16 -> V_138 ;
T_1 V_140 = ( ( V_136 - V_15 -> V_37 ) >> V_153 ) +
V_15 -> V_38 ;
struct V_14 * V_289 ;
unsigned long V_290 ;
T_11 * V_299 = NULL ;
T_11 * V_236 ;
if ( ! F_324 ( V_15 , V_136 ) )
return ( T_11 * ) F_327 ( V_242 , V_298 , V_136 ) ;
F_278 ( & V_97 -> V_250 ) ;
F_279 (svma, &mapping->i_mmap, idx, idx) {
if ( V_289 == V_15 )
continue;
V_290 = F_322 ( V_289 , V_15 , V_136 , V_140 ) ;
if ( V_290 ) {
V_299 = F_242 ( V_289 -> V_243 , V_290 ) ;
if ( V_299 ) {
F_248 ( F_156 ( V_299 ) ) ;
break;
}
}
}
if ( ! V_299 )
goto V_159;
F_8 ( & V_242 -> V_234 ) ;
if ( F_328 ( * V_298 ) )
F_329 ( V_242 , V_298 ,
( V_300 * ) ( ( unsigned long ) V_299 & V_301 ) ) ;
else
F_96 ( F_156 ( V_299 ) ) ;
F_2 ( & V_242 -> V_234 ) ;
V_159:
V_236 = ( T_11 * ) F_327 ( V_242 , V_298 , V_136 ) ;
F_280 ( & V_97 -> V_250 ) ;
return V_236 ;
}
int F_262 ( struct V_225 * V_242 , unsigned long * V_136 , T_11 * V_224 )
{
T_16 * V_302 = F_330 ( V_242 , * V_136 ) ;
T_15 * V_298 = F_331 ( V_302 , * V_136 ) ;
F_9 ( F_87 ( F_156 ( V_224 ) ) == 0 ) ;
if ( F_87 ( F_156 ( V_224 ) ) == 1 )
return 0 ;
F_332 ( V_298 ) ;
F_96 ( F_156 ( V_224 ) ) ;
* V_136 = F_333 ( * V_136 , V_192 * V_303 ) - V_192 ;
return 1 ;
}
T_11 * F_325 ( struct V_225 * V_242 , unsigned long V_136 , T_15 * V_298 )
{
return NULL ;
}
T_11 * F_243 ( struct V_225 * V_242 ,
unsigned long V_136 , unsigned long V_230 )
{
T_16 * V_302 ;
T_15 * V_298 ;
T_11 * V_236 = NULL ;
V_302 = F_330 ( V_242 , V_136 ) ;
V_298 = F_334 ( V_242 , V_302 , V_136 ) ;
if ( V_298 ) {
if ( V_230 == V_294 ) {
V_236 = ( T_11 * ) V_298 ;
} else {
F_9 ( V_230 != V_304 ) ;
if ( F_335 () && F_328 ( * V_298 ) )
V_236 = F_325 ( V_242 , V_136 , V_298 ) ;
else
V_236 = ( T_11 * ) F_327 ( V_242 , V_298 , V_136 ) ;
}
}
F_9 ( V_236 && ! F_336 ( * V_236 ) && ! F_337 ( * V_236 ) ) ;
return V_236 ;
}
T_11 * F_242 ( struct V_225 * V_242 , unsigned long V_136 )
{
T_16 * V_302 ;
T_15 * V_298 ;
V_300 * V_305 = NULL ;
V_302 = F_330 ( V_242 , V_136 ) ;
if ( F_338 ( * V_302 ) ) {
V_298 = F_331 ( V_302 , V_136 ) ;
if ( F_339 ( * V_298 ) ) {
if ( F_340 ( * V_298 ) )
return ( T_11 * ) V_298 ;
V_305 = F_341 ( V_298 , V_136 ) ;
}
}
return ( T_11 * ) V_305 ;
}
struct V_55 *
F_342 ( struct V_225 * V_242 , unsigned long V_36 ,
V_300 * V_305 , int V_208 )
{
struct V_55 * V_55 ;
V_55 = F_247 ( * ( T_11 * ) V_305 ) ;
if ( V_55 )
V_55 += ( ( V_36 & ~ V_306 ) >> V_153 ) ;
return V_55 ;
}
struct V_55 *
F_343 ( struct V_225 * V_242 , unsigned long V_36 ,
T_15 * V_298 , int V_208 )
{
struct V_55 * V_55 ;
V_55 = F_247 ( * ( T_11 * ) V_298 ) ;
if ( V_55 )
V_55 += ( ( V_36 & ~ V_292 ) >> V_153 ) ;
return V_55 ;
}
struct V_55 *
F_343 ( struct V_225 * V_242 , unsigned long V_36 ,
T_15 * V_298 , int V_208 )
{
F_196 () ;
return NULL ;
}
static int F_344 ( struct V_55 * V_307 )
{
struct V_55 * V_55 ;
struct V_55 * V_128 ;
struct V_34 * V_35 = F_51 ( V_307 ) ;
int V_62 = F_60 ( V_307 ) ;
F_18 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_55 == V_307 )
return 1 ;
return 0 ;
}
int F_345 ( struct V_55 * V_307 )
{
struct V_34 * V_35 = F_51 ( V_307 ) ;
int V_62 = F_60 ( V_307 ) ;
int V_10 = - V_308 ;
F_8 ( & V_98 ) ;
if ( F_344 ( V_307 ) ) {
F_346 ( & V_307 -> V_63 ) ;
F_64 ( V_307 ) ;
V_35 -> V_65 -- ;
V_35 -> V_66 [ V_62 ] -- ;
V_10 = 0 ;
}
F_2 ( & V_98 ) ;
return V_10 ;
}
bool F_347 ( struct V_55 * V_55 , struct V_17 * V_150 )
{
F_44 ( ! F_348 ( V_55 ) ) ;
if ( ! F_349 ( V_55 ) )
return false ;
F_8 ( & V_98 ) ;
F_350 ( & V_55 -> V_63 , V_150 ) ;
F_2 ( & V_98 ) ;
return true ;
}
void F_351 ( struct V_55 * V_55 )
{
F_44 ( ! F_348 ( V_55 ) ) ;
F_8 ( & V_98 ) ;
F_350 ( & V_55 -> V_63 , & ( F_51 ( V_55 ) ) -> V_67 ) ;
F_2 ( & V_98 ) ;
F_96 ( V_55 ) ;
}
bool F_352 ( struct V_55 * V_55 )
{
F_44 ( ! F_103 ( V_55 ) ) ;
if ( F_353 ( V_55 ) )
return false ;
if ( F_57 ( F_305 ( V_55 ) ) )
return false ;
return F_87 ( V_55 ) > 0 ;
}
