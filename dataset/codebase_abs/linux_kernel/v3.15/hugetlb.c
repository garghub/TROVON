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
static void F_69 ( struct V_40 * V_41 , struct V_65 * V_65 )
{
int V_87 ;
F_45 ( V_41 -> V_88 >= V_89 ) ;
V_41 -> V_90 -- ;
V_41 -> V_91 [ F_52 ( V_65 ) ] -- ;
for ( V_87 = 0 ; V_87 < F_70 ( V_41 ) ; V_87 ++ ) {
V_65 [ V_87 ] . V_61 &= ~ ( 1 << V_92 | 1 << V_93 |
1 << V_94 | 1 << V_95 |
1 << V_96 | 1 << V_97 |
1 << V_98 | 1 << V_99 ) ;
}
F_71 ( F_72 ( V_65 ) , V_65 ) ;
F_73 ( V_65 , NULL ) ;
F_56 ( V_65 ) ;
F_74 ( V_65 ) ;
F_75 ( V_65 , F_31 ( V_41 ) ) ;
}
struct V_40 * F_76 ( unsigned long V_100 )
{
struct V_40 * V_41 ;
F_77 (h) {
if ( F_78 ( V_41 ) == V_100 )
return V_41 ;
}
return NULL ;
}
static void F_79 ( struct V_65 * V_65 )
{
struct V_40 * V_41 = F_80 ( V_65 ) ;
int V_66 = F_52 ( V_65 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_81 ( V_65 ) ;
bool V_101 ;
F_82 ( V_65 , 0 ) ;
V_65 -> V_56 = NULL ;
F_9 ( F_83 ( V_65 ) ) ;
F_9 ( F_84 ( V_65 ) ) ;
V_101 = F_85 ( V_65 ) ;
F_86 ( V_65 ) ;
F_8 ( & V_102 ) ;
F_87 ( F_88 ( V_41 ) ,
F_70 ( V_41 ) , V_65 ) ;
if ( V_101 )
V_41 -> V_84 ++ ;
if ( V_41 -> V_103 [ V_66 ] && F_31 ( V_41 ) < V_89 ) {
F_19 ( & V_65 -> V_67 ) ;
F_69 ( V_41 , V_65 ) ;
V_41 -> V_104 -- ;
V_41 -> V_103 [ V_66 ] -- ;
} else {
F_89 ( V_65 ) ;
F_51 ( V_41 , V_65 ) ;
}
F_2 ( & V_102 ) ;
F_11 ( V_2 , 1 ) ;
}
static void F_90 ( struct V_40 * V_41 , struct V_65 * V_65 , int V_66 )
{
F_21 ( & V_65 -> V_67 ) ;
F_73 ( V_65 , F_79 ) ;
F_8 ( & V_102 ) ;
F_91 ( V_65 , NULL ) ;
V_41 -> V_90 ++ ;
V_41 -> V_91 [ V_66 ] ++ ;
F_2 ( & V_102 ) ;
F_92 ( V_65 ) ;
}
static void T_4 F_93 ( struct V_65 * V_65 ,
unsigned long V_88 )
{
int V_87 ;
int V_105 = 1 << V_88 ;
struct V_65 * V_106 = V_65 + 1 ;
F_94 ( V_65 , V_88 ) ;
F_95 ( V_65 ) ;
F_96 ( V_65 ) ;
for ( V_87 = 1 ; V_87 < V_105 ; V_87 ++ , V_106 = F_97 ( V_106 , V_65 , V_87 ) ) {
F_98 ( V_106 ) ;
F_96 ( V_106 ) ;
F_99 ( V_106 , 0 ) ;
V_106 -> V_107 = V_65 ;
}
}
int F_100 ( struct V_65 * V_65 )
{
if ( ! F_101 ( V_65 ) )
return 0 ;
V_65 = F_102 ( V_65 ) ;
return F_103 ( V_65 ) == F_79 ;
}
int F_104 ( struct V_65 * V_108 )
{
if ( ! F_105 ( V_108 ) )
return 0 ;
return F_103 ( V_108 ) == F_79 ;
}
T_1 F_106 ( struct V_65 * V_65 )
{
struct V_65 * V_108 = F_102 ( V_65 ) ;
T_1 V_109 = F_107 ( V_108 ) ;
unsigned long V_110 ;
if ( ! F_100 ( V_108 ) )
return F_107 ( V_65 ) ;
if ( F_108 ( V_108 ) >= V_89 )
V_110 = F_109 ( V_65 ) - F_109 ( V_108 ) ;
else
V_110 = V_65 - V_108 ;
return ( V_109 << F_108 ( V_108 ) ) + V_110 ;
}
static struct V_65 * F_110 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 ;
if ( V_41 -> V_88 >= V_89 )
return NULL ;
V_65 = F_111 ( V_66 ,
F_57 ( V_41 ) | V_111 | V_112 |
V_113 | V_114 ,
F_31 ( V_41 ) ) ;
if ( V_65 ) {
if ( F_112 ( V_65 ) ) {
F_75 ( V_65 , F_31 ( V_41 ) ) ;
return NULL ;
}
F_90 ( V_41 , V_65 , V_66 ) ;
}
return V_65 ;
}
static int F_113 ( int V_66 , T_3 * V_115 )
{
V_66 = F_114 ( V_66 , * V_115 ) ;
if ( V_66 == V_116 )
V_66 = F_115 ( * V_115 ) ;
F_45 ( V_66 >= V_116 ) ;
return V_66 ;
}
static int F_116 ( int V_66 , T_3 * V_115 )
{
if ( ! F_117 ( V_66 , * V_115 ) )
V_66 = F_113 ( V_66 , V_115 ) ;
return V_66 ;
}
static int F_118 ( struct V_40 * V_41 ,
T_3 * V_115 )
{
int V_66 ;
F_45 ( ! V_115 ) ;
V_66 = F_116 ( V_41 -> V_117 , V_115 ) ;
V_41 -> V_117 = F_113 ( V_66 , V_115 ) ;
return V_66 ;
}
static int F_119 ( struct V_40 * V_41 , T_3 * V_115 )
{
int V_66 ;
F_45 ( ! V_115 ) ;
V_66 = F_116 ( V_41 -> V_118 , V_115 ) ;
V_41 -> V_118 = F_113 ( V_66 , V_115 ) ;
return V_66 ;
}
static int F_120 ( struct V_40 * V_41 , T_3 * V_115 )
{
struct V_65 * V_65 ;
int V_119 , V_120 ;
int V_10 = 0 ;
F_121 (h, nr_nodes, node, nodes_allowed) {
V_65 = F_110 ( V_41 , V_120 ) ;
if ( V_65 ) {
V_10 = 1 ;
break;
}
}
if ( V_10 )
F_122 ( V_121 ) ;
else
F_122 ( V_122 ) ;
return V_10 ;
}
static int F_123 ( struct V_40 * V_41 , T_3 * V_115 ,
bool V_123 )
{
int V_119 , V_120 ;
int V_10 = 0 ;
F_124 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_123 || V_41 -> V_103 [ V_120 ] ) &&
! F_125 ( & V_41 -> V_68 [ V_120 ] ) ) {
struct V_65 * V_65 =
F_24 ( V_41 -> V_68 [ V_120 ] . V_37 ,
struct V_65 , V_67 ) ;
F_19 ( & V_65 -> V_67 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ V_120 ] -- ;
if ( V_123 ) {
V_41 -> V_104 -- ;
V_41 -> V_103 [ V_120 ] -- ;
}
F_69 ( V_41 , V_65 ) ;
V_10 = 1 ;
break;
}
}
return V_10 ;
}
static void F_126 ( struct V_65 * V_65 )
{
F_8 ( & V_102 ) ;
if ( F_100 ( V_65 ) && ! F_83 ( V_65 ) ) {
struct V_40 * V_41 = F_80 ( V_65 ) ;
int V_66 = F_52 ( V_65 ) ;
F_19 ( & V_65 -> V_67 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ V_66 ] -- ;
F_69 ( V_41 , V_65 ) ;
}
F_2 ( & V_102 ) ;
}
void F_127 ( unsigned long V_124 , unsigned long V_125 )
{
unsigned int V_88 = 8 * sizeof( void * ) ;
unsigned long V_126 ;
struct V_40 * V_41 ;
F_77 (h)
if ( V_88 > F_31 ( V_41 ) )
V_88 = F_31 ( V_41 ) ;
F_45 ( ! F_128 ( V_124 , 1 << V_88 ) ) ;
for ( V_126 = V_124 ; V_126 < V_125 ; V_126 += 1 << V_88 )
F_126 ( F_129 ( V_126 ) ) ;
}
static struct V_65 * F_130 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 ;
unsigned int V_127 ;
if ( V_41 -> V_88 >= V_89 )
return NULL ;
F_8 ( & V_102 ) ;
if ( V_41 -> V_104 >= V_41 -> V_128 ) {
F_2 ( & V_102 ) ;
return NULL ;
} else {
V_41 -> V_90 ++ ;
V_41 -> V_104 ++ ;
}
F_2 ( & V_102 ) ;
if ( V_66 == V_129 )
V_65 = F_131 ( F_57 ( V_41 ) | V_111 |
V_113 | V_114 ,
F_31 ( V_41 ) ) ;
else
V_65 = F_111 ( V_66 ,
F_57 ( V_41 ) | V_111 | V_112 |
V_113 | V_114 , F_31 ( V_41 ) ) ;
if ( V_65 && F_112 ( V_65 ) ) {
F_75 ( V_65 , F_31 ( V_41 ) ) ;
V_65 = NULL ;
}
F_8 ( & V_102 ) ;
if ( V_65 ) {
F_21 ( & V_65 -> V_67 ) ;
V_127 = F_52 ( V_65 ) ;
F_73 ( V_65 , F_79 ) ;
F_91 ( V_65 , NULL ) ;
V_41 -> V_91 [ V_127 ] ++ ;
V_41 -> V_103 [ V_127 ] ++ ;
F_132 ( V_121 ) ;
} else {
V_41 -> V_90 -- ;
V_41 -> V_104 -- ;
F_132 ( V_122 ) ;
}
F_2 ( & V_102 ) ;
return V_65 ;
}
struct V_65 * F_133 ( struct V_40 * V_41 , int V_66 )
{
struct V_65 * V_65 = NULL ;
F_8 ( & V_102 ) ;
if ( V_41 -> V_69 - V_41 -> V_84 > 0 )
V_65 = F_54 ( V_41 , V_66 ) ;
F_2 ( & V_102 ) ;
if ( ! V_65 )
V_65 = F_130 ( V_41 , V_66 ) ;
return V_65 ;
}
static int F_134 ( struct V_40 * V_41 , int V_9 )
{
struct V_21 V_130 ;
struct V_65 * V_65 , * V_131 ;
int V_10 , V_87 ;
int V_132 , V_133 ;
bool V_134 = true ;
V_132 = ( V_41 -> V_84 + V_9 ) - V_41 -> V_69 ;
if ( V_132 <= 0 ) {
V_41 -> V_84 += V_9 ;
return 0 ;
}
V_133 = 0 ;
F_21 ( & V_130 ) ;
V_10 = - V_11 ;
V_32:
F_2 ( & V_102 ) ;
for ( V_87 = 0 ; V_87 < V_132 ; V_87 ++ ) {
V_65 = F_130 ( V_41 , V_129 ) ;
if ( ! V_65 ) {
V_134 = false ;
break;
}
F_22 ( & V_65 -> V_67 , & V_130 ) ;
}
V_133 += V_87 ;
F_8 ( & V_102 ) ;
V_132 = ( V_41 -> V_84 + V_9 ) -
( V_41 -> V_69 + V_133 ) ;
if ( V_132 > 0 ) {
if ( V_134 )
goto V_32;
goto free;
}
V_132 += V_133 ;
V_41 -> V_84 += V_9 ;
V_10 = 0 ;
F_18 (page, tmp, &surplus_list, lru) {
if ( ( -- V_132 ) < 0 )
break;
F_135 ( V_65 ) ;
F_71 ( F_83 ( V_65 ) , V_65 ) ;
F_51 ( V_41 , V_65 ) ;
}
free:
F_2 ( & V_102 ) ;
F_18 (page, tmp, &surplus_list, lru)
F_92 ( V_65 ) ;
F_8 ( & V_102 ) ;
return V_10 ;
}
static void F_136 ( struct V_40 * V_41 ,
unsigned long V_135 )
{
unsigned long V_105 ;
V_41 -> V_84 -= V_135 ;
if ( V_41 -> V_88 >= V_89 )
return;
V_105 = F_28 ( V_135 , V_41 -> V_104 ) ;
while ( V_105 -- ) {
if ( ! F_123 ( V_41 , & V_136 [ V_137 ] , 1 ) )
break;
F_137 ( & V_102 ) ;
}
}
static long F_138 ( struct V_40 * V_41 ,
struct V_14 * V_15 , unsigned long V_138 )
{
struct V_17 * V_18 ;
T_1 V_139 ;
long V_31 ;
V_18 = F_44 ( V_15 ) ;
if ( ! V_18 )
return 1 ;
V_139 = F_29 ( V_41 , V_15 , V_138 ) ;
V_31 = F_20 ( V_18 , V_139 , V_139 + 1 ) ;
if ( V_15 -> V_53 & V_54 )
return V_31 ;
else
return V_31 < 0 ? V_31 : 0 ;
}
static void F_139 ( struct V_40 * V_41 ,
struct V_14 * V_15 , unsigned long V_138 )
{
struct V_17 * V_18 ;
T_1 V_139 ;
V_18 = F_44 ( V_15 ) ;
if ( ! V_18 )
return;
V_139 = F_29 ( V_41 , V_15 , V_138 ) ;
F_16 ( V_18 , V_139 , V_139 + 1 ) ;
}
static struct V_65 * F_140 ( struct V_14 * V_15 ,
unsigned long V_138 , int V_75 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_65 * V_65 ;
long V_31 ;
int V_10 , V_139 ;
struct V_140 * V_141 ;
V_139 = F_88 ( V_41 ) ;
V_31 = F_138 ( V_41 , V_15 , V_138 ) ;
if ( V_31 < 0 )
return F_141 ( - V_11 ) ;
if ( V_31 || V_75 )
if ( F_10 ( V_2 , 1 ) )
return F_141 ( - V_142 ) ;
V_10 = F_142 ( V_139 , F_70 ( V_41 ) , & V_141 ) ;
if ( V_10 ) {
if ( V_31 || V_75 )
F_11 ( V_2 , 1 ) ;
return F_141 ( - V_142 ) ;
}
F_8 ( & V_102 ) ;
V_65 = F_59 ( V_41 , V_15 , V_138 , V_75 , V_31 ) ;
if ( ! V_65 ) {
F_2 ( & V_102 ) ;
V_65 = F_130 ( V_41 , V_129 ) ;
if ( ! V_65 ) {
F_143 ( V_139 ,
F_70 ( V_41 ) ,
V_141 ) ;
if ( V_31 || V_75 )
F_11 ( V_2 , 1 ) ;
return F_141 ( - V_142 ) ;
}
F_8 ( & V_102 ) ;
F_53 ( & V_65 -> V_67 , & V_41 -> V_71 ) ;
}
F_144 ( V_139 , F_70 ( V_41 ) , V_141 , V_65 ) ;
F_2 ( & V_102 ) ;
F_82 ( V_65 , ( unsigned long ) V_2 ) ;
F_139 ( V_41 , V_15 , V_138 ) ;
return V_65 ;
}
struct V_65 * F_145 ( struct V_14 * V_15 ,
unsigned long V_138 , int V_75 )
{
struct V_65 * V_65 = F_140 ( V_15 , V_138 , V_75 ) ;
if ( F_146 ( V_65 ) )
V_65 = NULL ;
return V_65 ;
}
int __weak F_147 ( struct V_40 * V_41 )
{
struct V_143 * V_144 ;
int V_119 , V_120 ;
F_121 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_138 ;
V_138 = F_148 (
F_78 ( V_41 ) , F_78 ( V_41 ) ,
0 , V_145 , V_120 ) ;
if ( V_138 ) {
V_144 = V_138 ;
goto V_146;
}
}
return 0 ;
V_146:
F_9 ( ( unsigned long ) F_149 ( V_144 ) & ( F_78 ( V_41 ) - 1 ) ) ;
F_22 ( & V_144 -> V_147 , & V_148 ) ;
V_144 -> V_40 = V_41 ;
return 1 ;
}
static void T_4 F_150 ( struct V_65 * V_65 , int V_88 )
{
if ( F_67 ( V_88 > ( V_89 - 1 ) ) )
F_93 ( V_65 , V_88 ) ;
else
F_151 ( V_65 , V_88 ) ;
}
static void T_4 F_152 ( void )
{
struct V_143 * V_144 ;
F_17 (m, &huge_boot_pages, list) {
struct V_40 * V_41 = V_144 -> V_40 ;
struct V_65 * V_65 ;
#ifdef F_153
V_65 = F_129 ( V_144 -> V_149 >> V_150 ) ;
F_154 ( F_155 ( V_144 ) ,
sizeof( struct V_143 ) ) ;
#else
V_65 = F_156 ( V_144 ) ;
#endif
F_157 ( F_83 ( V_65 ) != 1 ) ;
F_150 ( V_65 , V_41 -> V_88 ) ;
F_157 ( F_158 ( V_65 ) ) ;
F_90 ( V_41 , V_65 , F_52 ( V_65 ) ) ;
if ( V_41 -> V_88 > ( V_89 - 1 ) )
F_159 ( V_65 , 1 << V_41 -> V_88 ) ;
}
}
static void T_4 F_160 ( struct V_40 * V_41 )
{
unsigned long V_87 ;
for ( V_87 = 0 ; V_87 < V_41 -> V_151 ; ++ V_87 ) {
if ( V_41 -> V_88 >= V_89 ) {
if ( ! F_147 ( V_41 ) )
break;
} else if ( ! F_120 ( V_41 ,
& V_136 [ V_137 ] ) )
break;
}
V_41 -> V_151 = V_87 ;
}
static void T_4 F_161 ( void )
{
struct V_40 * V_41 ;
F_77 (h) {
if ( V_41 -> V_88 < V_89 )
F_160 ( V_41 ) ;
}
}
static char * T_4 F_162 ( char * V_152 , unsigned long V_153 )
{
if ( V_153 >= ( 1UL << 30 ) )
sprintf ( V_152 , L_1 , V_153 >> 30 ) ;
else if ( V_153 >= ( 1UL << 20 ) )
sprintf ( V_152 , L_2 , V_153 >> 20 ) ;
else
sprintf ( V_152 , L_3 , V_153 >> 10 ) ;
return V_152 ;
}
static void T_4 F_163 ( void )
{
struct V_40 * V_41 ;
F_77 (h) {
char V_152 [ 32 ] ;
F_164 ( L_4 ,
F_162 ( V_152 , F_78 ( V_41 ) ) ,
V_41 -> V_69 ) ;
}
}
static void F_165 ( struct V_40 * V_41 , unsigned long V_3 ,
T_3 * V_115 )
{
int V_87 ;
if ( V_41 -> V_88 >= V_89 )
return;
F_166 (i, *nodes_allowed) {
struct V_65 * V_65 , * V_37 ;
struct V_21 * V_154 = & V_41 -> V_68 [ V_87 ] ;
F_18 (page, next, freel, lru) {
if ( V_3 >= V_41 -> V_90 )
return;
if ( F_167 ( V_65 ) )
continue;
F_19 ( & V_65 -> V_67 ) ;
F_69 ( V_41 , V_65 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ F_52 ( V_65 ) ] -- ;
}
}
}
static inline void F_165 ( struct V_40 * V_41 , unsigned long V_3 ,
T_3 * V_115 )
{
}
static int F_168 ( struct V_40 * V_41 , T_3 * V_115 ,
int V_9 )
{
int V_119 , V_120 ;
F_45 ( V_9 != - 1 && V_9 != 1 ) ;
if ( V_9 < 0 ) {
F_121 (h, nr_nodes, node, nodes_allowed) {
if ( V_41 -> V_103 [ V_120 ] )
goto V_146;
}
} else {
F_124 (h, nr_nodes, node, nodes_allowed) {
if ( V_41 -> V_103 [ V_120 ] <
V_41 -> V_91 [ V_120 ] )
goto V_146;
}
}
return 0 ;
V_146:
V_41 -> V_104 += V_9 ;
V_41 -> V_103 [ V_120 ] += V_9 ;
return 1 ;
}
static unsigned long F_169 ( struct V_40 * V_41 , unsigned long V_3 ,
T_3 * V_115 )
{
unsigned long V_155 , V_10 ;
if ( V_41 -> V_88 >= V_89 )
return V_41 -> V_151 ;
F_8 ( & V_102 ) ;
while ( V_41 -> V_104 && V_3 > F_170 ( V_41 ) ) {
if ( ! F_168 ( V_41 , V_115 , - 1 ) )
break;
}
while ( V_3 > F_170 ( V_41 ) ) {
F_2 ( & V_102 ) ;
V_10 = F_120 ( V_41 , V_115 ) ;
F_8 ( & V_102 ) ;
if ( ! V_10 )
goto V_35;
if ( F_171 ( V_156 ) )
goto V_35;
}
V_155 = V_41 -> V_84 + V_41 -> V_90 - V_41 -> V_69 ;
V_155 = F_27 ( V_3 , V_155 ) ;
F_165 ( V_41 , V_155 , V_115 ) ;
while ( V_155 < F_170 ( V_41 ) ) {
if ( ! F_123 ( V_41 , V_115 , 0 ) )
break;
F_137 ( & V_102 ) ;
}
while ( V_3 < F_170 ( V_41 ) ) {
if ( ! F_168 ( V_41 , V_115 , 1 ) )
break;
}
V_35:
V_10 = F_170 ( V_41 ) ;
F_2 ( & V_102 ) ;
return V_10 ;
}
static struct V_40 * F_172 ( struct V_157 * V_158 , int * V_159 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_160 ; V_87 ++ )
if ( V_161 [ V_87 ] == V_158 ) {
if ( V_159 )
* V_159 = V_129 ;
return & V_162 [ V_87 ] ;
}
return F_173 ( V_158 , V_159 ) ;
}
static T_5 F_174 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_152 )
{
struct V_40 * V_41 ;
unsigned long V_90 ;
int V_66 ;
V_41 = F_172 ( V_158 , & V_66 ) ;
if ( V_66 == V_129 )
V_90 = V_41 -> V_90 ;
else
V_90 = V_41 -> V_91 [ V_66 ] ;
return sprintf ( V_152 , L_5 , V_90 ) ;
}
static T_5 F_175 ( bool V_165 ,
struct V_157 * V_158 , struct V_163 * V_164 ,
const char * V_152 , T_6 V_166 )
{
int V_85 ;
int V_66 ;
unsigned long V_3 ;
struct V_40 * V_41 ;
F_176 ( T_3 , V_115 , V_7 | V_167 ) ;
V_85 = F_177 ( V_152 , 10 , & V_3 ) ;
if ( V_85 )
goto V_35;
V_41 = F_172 ( V_158 , & V_66 ) ;
if ( V_41 -> V_88 >= V_89 ) {
V_85 = - V_168 ;
goto V_35;
}
if ( V_66 == V_129 ) {
if ( ! ( V_165 &&
F_178 ( V_115 ) ) ) {
F_179 ( V_115 ) ;
V_115 = & V_136 [ V_137 ] ;
}
} else if ( V_115 ) {
V_3 += V_41 -> V_90 - V_41 -> V_91 [ V_66 ] ;
F_180 ( V_115 , V_66 ) ;
} else
V_115 = & V_136 [ V_137 ] ;
V_41 -> V_151 = F_169 ( V_41 , V_3 , V_115 ) ;
if ( V_115 != & V_136 [ V_137 ] )
F_179 ( V_115 ) ;
return V_166 ;
V_35:
F_179 ( V_115 ) ;
return V_85 ;
}
static T_5 F_181 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_152 )
{
return F_174 ( V_158 , V_164 , V_152 ) ;
}
static T_5 F_182 ( struct V_157 * V_158 ,
struct V_163 * V_164 , const char * V_152 , T_6 V_166 )
{
return F_175 ( false , V_158 , V_164 , V_152 , V_166 ) ;
}
static T_5 F_183 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_152 )
{
return F_174 ( V_158 , V_164 , V_152 ) ;
}
static T_5 F_184 ( struct V_157 * V_158 ,
struct V_163 * V_164 , const char * V_152 , T_6 V_166 )
{
return F_175 ( true , V_158 , V_164 , V_152 , V_166 ) ;
}
static T_5 F_185 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_152 )
{
struct V_40 * V_41 = F_172 ( V_158 , NULL ) ;
return sprintf ( V_152 , L_5 , V_41 -> V_128 ) ;
}
static T_5 F_186 ( struct V_157 * V_158 ,
struct V_163 * V_164 , const char * V_152 , T_6 V_3 )
{
int V_85 ;
unsigned long V_169 ;
struct V_40 * V_41 = F_172 ( V_158 , NULL ) ;
if ( V_41 -> V_88 >= V_89 )
return - V_168 ;
V_85 = F_177 ( V_152 , 10 , & V_169 ) ;
if ( V_85 )
return V_85 ;
F_8 ( & V_102 ) ;
V_41 -> V_128 = V_169 ;
F_2 ( & V_102 ) ;
return V_3 ;
}
static T_5 F_187 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_152 )
{
struct V_40 * V_41 ;
unsigned long V_69 ;
int V_66 ;
V_41 = F_172 ( V_158 , & V_66 ) ;
if ( V_66 == V_129 )
V_69 = V_41 -> V_69 ;
else
V_69 = V_41 -> V_70 [ V_66 ] ;
return sprintf ( V_152 , L_5 , V_69 ) ;
}
static T_5 F_188 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_152 )
{
struct V_40 * V_41 = F_172 ( V_158 , NULL ) ;
return sprintf ( V_152 , L_5 , V_41 -> V_84 ) ;
}
static T_5 F_189 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_152 )
{
struct V_40 * V_41 ;
unsigned long V_104 ;
int V_66 ;
V_41 = F_172 ( V_158 , & V_66 ) ;
if ( V_66 == V_129 )
V_104 = V_41 -> V_104 ;
else
V_104 = V_41 -> V_103 [ V_66 ] ;
return sprintf ( V_152 , L_5 , V_104 ) ;
}
static int F_190 ( struct V_40 * V_41 , struct V_157 * V_170 ,
struct V_157 * * V_161 ,
struct V_171 * V_172 )
{
int V_173 ;
int V_174 = F_88 ( V_41 ) ;
V_161 [ V_174 ] = F_191 ( V_41 -> V_175 , V_170 ) ;
if ( ! V_161 [ V_174 ] )
return - V_11 ;
V_173 = F_192 ( V_161 [ V_174 ] , V_172 ) ;
if ( V_173 )
F_193 ( V_161 [ V_174 ] ) ;
return V_173 ;
}
static void T_4 F_194 ( void )
{
struct V_40 * V_41 ;
int V_85 ;
V_176 = F_191 ( L_6 , V_177 ) ;
if ( ! V_176 )
return;
F_77 (h) {
V_85 = F_190 ( V_41 , V_176 ,
V_161 , & V_172 ) ;
if ( V_85 )
F_195 ( L_7 , V_41 -> V_175 ) ;
}
}
static struct V_40 * F_173 ( struct V_157 * V_158 , int * V_159 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_178 ; V_66 ++ ) {
struct V_179 * V_180 = & V_181 [ V_66 ] ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_160 ; V_87 ++ )
if ( V_180 -> V_161 [ V_87 ] == V_158 ) {
if ( V_159 )
* V_159 = V_66 ;
return & V_162 [ V_87 ] ;
}
}
F_196 () ;
return NULL ;
}
static void F_197 ( struct V_120 * V_120 )
{
struct V_40 * V_41 ;
struct V_179 * V_180 = & V_181 [ V_120 -> V_182 . V_183 ] ;
if ( ! V_180 -> V_176 )
return;
F_77 (h) {
int V_139 = F_88 ( V_41 ) ;
if ( V_180 -> V_161 [ V_139 ] ) {
F_193 ( V_180 -> V_161 [ V_139 ] ) ;
V_180 -> V_161 [ V_139 ] = NULL ;
}
}
F_193 ( V_180 -> V_176 ) ;
V_180 -> V_176 = NULL ;
}
static void F_198 ( void )
{
int V_66 ;
F_199 ( NULL , NULL ) ;
for ( V_66 = 0 ; V_66 < V_178 ; V_66 ++ )
F_197 ( V_184 [ V_66 ] ) ;
}
static void F_200 ( struct V_120 * V_120 )
{
struct V_40 * V_41 ;
struct V_179 * V_180 = & V_181 [ V_120 -> V_182 . V_183 ] ;
int V_85 ;
if ( V_180 -> V_176 )
return;
V_180 -> V_176 = F_191 ( L_6 ,
& V_120 -> V_182 . V_158 ) ;
if ( ! V_180 -> V_176 )
return;
F_77 (h) {
V_85 = F_190 ( V_41 , V_180 -> V_176 ,
V_180 -> V_161 ,
& V_185 ) ;
if ( V_85 ) {
F_195 ( L_8 ,
V_41 -> V_175 , V_120 -> V_182 . V_183 ) ;
F_197 ( V_120 ) ;
break;
}
}
}
static void F_201 ( void )
{
int V_66 ;
F_202 (nid, N_MEMORY) {
struct V_120 * V_120 = V_184 [ V_66 ] ;
if ( V_120 -> V_182 . V_183 == V_66 )
F_200 ( V_120 ) ;
}
F_199 ( F_200 ,
F_197 ) ;
}
static struct V_40 * F_173 ( struct V_157 * V_158 , int * V_159 )
{
F_196 () ;
if ( V_159 )
* V_159 = - 1 ;
return NULL ;
}
static void F_198 ( void ) { }
static void F_201 ( void ) { }
static void T_7 F_203 ( void )
{
struct V_40 * V_41 ;
F_198 () ;
F_77 (h) {
F_193 ( V_161 [ F_88 ( V_41 ) ] ) ;
}
F_193 ( V_176 ) ;
F_3 ( V_186 ) ;
}
static int T_4 F_204 ( void )
{
int V_87 ;
if ( ! F_205 () )
return 0 ;
if ( ! F_76 ( V_187 ) ) {
V_187 = V_188 ;
if ( ! F_76 ( V_187 ) )
F_206 ( V_189 ) ;
}
V_190 = F_88 ( F_76 ( V_187 ) ) ;
if ( V_191 )
V_192 . V_151 = V_191 ;
F_161 () ;
F_152 () ;
F_163 () ;
F_194 () ;
F_201 () ;
F_207 () ;
#ifdef F_208
V_193 = F_209 ( 8 * F_210 () ) ;
#else
V_193 = 1 ;
#endif
V_186 =
F_5 ( sizeof( struct V_194 ) * V_193 , V_7 ) ;
F_9 ( ! V_186 ) ;
for ( V_87 = 0 ; V_87 < V_193 ; V_87 ++ )
F_211 ( & V_186 [ V_87 ] ) ;
return 0 ;
}
void T_4 F_206 ( unsigned V_88 )
{
struct V_40 * V_41 ;
unsigned long V_87 ;
if ( F_76 ( V_45 << V_88 ) ) {
F_212 ( L_9 ) ;
return;
}
F_9 ( V_195 >= V_160 ) ;
F_9 ( V_88 == 0 ) ;
V_41 = & V_162 [ V_195 ++ ] ;
V_41 -> V_88 = V_88 ;
V_41 -> V_196 = ~ ( ( 1ULL << ( V_88 + V_150 ) ) - 1 ) ;
V_41 -> V_90 = 0 ;
V_41 -> V_69 = 0 ;
for ( V_87 = 0 ; V_87 < V_116 ; ++ V_87 )
F_21 ( & V_41 -> V_68 [ V_87 ] ) ;
F_21 ( & V_41 -> V_71 ) ;
V_41 -> V_117 = F_115 ( V_136 [ V_137 ] ) ;
V_41 -> V_118 = F_115 ( V_136 [ V_137 ] ) ;
snprintf ( V_41 -> V_175 , V_197 , L_10 ,
F_78 ( V_41 ) / 1024 ) ;
V_198 = V_41 ;
}
static int T_4 F_213 ( char * V_199 )
{
unsigned long * V_200 ;
static unsigned long * V_201 ;
if ( ! V_195 )
V_200 = & V_191 ;
else
V_200 = & V_198 -> V_151 ;
if ( V_200 == V_201 ) {
F_212 ( L_11
L_12 ) ;
return 1 ;
}
if ( sscanf ( V_199 , L_13 , V_200 ) <= 0 )
* V_200 = 0 ;
if ( V_195 && V_198 -> V_88 >= V_89 )
F_160 ( V_198 ) ;
V_201 = V_200 ;
return 1 ;
}
static int T_4 F_214 ( char * V_199 )
{
V_187 = F_215 ( V_199 , & V_199 ) ;
return 1 ;
}
static unsigned int F_216 ( unsigned int * V_202 )
{
int V_120 ;
unsigned int V_203 = 0 ;
F_166 (node, cpuset_current_mems_allowed)
V_203 += V_202 [ V_120 ] ;
return V_203 ;
}
static int F_217 ( bool V_165 ,
struct V_204 * V_205 , int V_206 ,
void T_8 * V_207 , T_6 * V_208 , T_9 * V_209 )
{
struct V_40 * V_41 = & V_192 ;
unsigned long V_131 ;
int V_10 ;
if ( ! F_205 () )
return - V_210 ;
V_131 = V_41 -> V_151 ;
if ( V_206 && V_41 -> V_88 >= V_89 )
return - V_168 ;
V_205 -> V_211 = & V_131 ;
V_205 -> V_212 = sizeof( unsigned long ) ;
V_10 = F_218 ( V_205 , V_206 , V_207 , V_208 , V_209 ) ;
if ( V_10 )
goto V_35;
if ( V_206 ) {
F_176 ( T_3 , V_115 ,
V_7 | V_167 ) ;
if ( ! ( V_165 &&
F_178 ( V_115 ) ) ) {
F_179 ( V_115 ) ;
V_115 = & V_136 [ V_137 ] ;
}
V_41 -> V_151 = F_169 ( V_41 , V_131 , V_115 ) ;
if ( V_115 != & V_136 [ V_137 ] )
F_179 ( V_115 ) ;
}
V_35:
return V_10 ;
}
int F_219 ( struct V_204 * V_205 , int V_206 ,
void T_8 * V_207 , T_6 * V_208 , T_9 * V_209 )
{
return F_217 ( false , V_205 , V_206 ,
V_207 , V_208 , V_209 ) ;
}
int F_220 ( struct V_204 * V_205 , int V_206 ,
void T_8 * V_207 , T_6 * V_208 , T_9 * V_209 )
{
return F_217 ( true , V_205 , V_206 ,
V_207 , V_208 , V_209 ) ;
}
int F_221 ( struct V_204 * V_205 , int V_206 ,
void T_8 * V_207 ,
T_6 * V_208 , T_9 * V_209 )
{
struct V_40 * V_41 = & V_192 ;
unsigned long V_131 ;
int V_10 ;
if ( ! F_205 () )
return - V_210 ;
V_131 = V_41 -> V_128 ;
if ( V_206 && V_41 -> V_88 >= V_89 )
return - V_168 ;
V_205 -> V_211 = & V_131 ;
V_205 -> V_212 = sizeof( unsigned long ) ;
V_10 = F_218 ( V_205 , V_206 , V_207 , V_208 , V_209 ) ;
if ( V_10 )
goto V_35;
if ( V_206 ) {
F_8 ( & V_102 ) ;
V_41 -> V_128 = V_131 ;
F_2 ( & V_102 ) ;
}
V_35:
return V_10 ;
}
void F_222 ( struct V_213 * V_144 )
{
struct V_40 * V_41 = & V_192 ;
if ( ! F_205 () )
return;
F_223 ( V_144 ,
L_14
L_15
L_16
L_17
L_18 ,
V_41 -> V_90 ,
V_41 -> V_69 ,
V_41 -> V_84 ,
V_41 -> V_104 ,
1UL << ( F_31 ( V_41 ) + V_150 - 10 ) ) ;
}
int F_224 ( int V_66 , char * V_152 )
{
struct V_40 * V_41 = & V_192 ;
if ( ! F_205 () )
return 0 ;
return sprintf ( V_152 ,
L_19
L_20
L_21 ,
V_66 , V_41 -> V_91 [ V_66 ] ,
V_66 , V_41 -> V_70 [ V_66 ] ,
V_66 , V_41 -> V_103 [ V_66 ] ) ;
}
void F_225 ( void )
{
struct V_40 * V_41 ;
int V_66 ;
if ( ! F_205 () )
return;
F_202 (nid, N_MEMORY)
F_77 (h)
F_164 ( L_22 ,
V_66 ,
V_41 -> V_91 [ V_66 ] ,
V_41 -> V_70 [ V_66 ] ,
V_41 -> V_103 [ V_66 ] ,
1UL << ( F_31 ( V_41 ) + V_150 - 10 ) ) ;
}
unsigned long F_226 ( void )
{
struct V_40 * V_41 ;
unsigned long V_214 = 0 ;
F_77 (h)
V_214 += V_41 -> V_90 * F_70 ( V_41 ) ;
return V_214 ;
}
static int F_227 ( struct V_40 * V_41 , long V_9 )
{
int V_10 = - V_11 ;
F_8 ( & V_102 ) ;
if ( V_9 > 0 ) {
if ( F_134 ( V_41 , V_9 ) < 0 )
goto V_35;
if ( V_9 > F_216 ( V_41 -> V_70 ) ) {
F_136 ( V_41 , V_9 ) ;
goto V_35;
}
}
V_10 = 0 ;
if ( V_9 < 0 )
F_136 ( V_41 , ( unsigned long ) - V_9 ) ;
V_35:
F_2 ( & V_102 ) ;
return V_10 ;
}
static void F_228 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_44 ( V_15 ) ;
if ( V_18 && F_48 ( V_15 , V_64 ) )
F_229 ( & V_18 -> V_48 ) ;
}
static void F_230 ( struct V_14 * V_15 )
{
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_17 * V_18 = F_44 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_15 ) ;
unsigned long V_215 , V_216 , V_36 ;
if ( ! V_18 || ! F_48 ( V_15 , V_64 ) )
return;
V_216 = F_29 ( V_41 , V_15 , V_15 -> V_43 ) ;
V_36 = F_29 ( V_41 , V_15 , V_15 -> V_217 ) ;
V_215 = ( V_36 - V_216 ) - F_26 ( V_18 , V_216 , V_36 ) ;
F_231 ( & V_18 -> V_48 , F_41 ) ;
if ( V_215 ) {
F_227 ( V_41 , - V_215 ) ;
F_11 ( V_2 , V_215 ) ;
}
}
static int F_232 ( struct V_14 * V_15 , struct V_218 * V_219 )
{
F_196 () ;
return 0 ;
}
static T_10 F_233 ( struct V_14 * V_15 , struct V_65 * V_65 ,
int V_220 )
{
T_10 V_221 ;
if ( V_220 ) {
V_221 = F_234 ( F_235 ( F_236 ( V_65 ,
V_15 -> V_222 ) ) ) ;
} else {
V_221 = F_237 ( F_236 ( V_65 ,
V_15 -> V_222 ) ) ;
}
V_221 = F_238 ( V_221 ) ;
V_221 = F_239 ( V_221 ) ;
V_221 = F_240 ( V_221 , V_15 , V_65 , V_220 ) ;
return V_221 ;
}
static void F_241 ( struct V_14 * V_15 ,
unsigned long V_42 , T_10 * V_223 )
{
T_10 V_221 ;
V_221 = F_234 ( F_235 ( F_242 ( V_223 ) ) ) ;
if ( F_243 ( V_15 , V_42 , V_223 , V_221 , 1 ) )
F_244 ( V_15 , V_42 , V_223 ) ;
}
int F_245 ( struct V_224 * V_225 , struct V_224 * V_226 ,
struct V_14 * V_15 )
{
T_10 * V_227 , * V_228 , V_221 ;
struct V_65 * V_229 ;
unsigned long V_138 ;
int V_230 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
unsigned long V_231 = F_78 ( V_41 ) ;
unsigned long V_232 ;
unsigned long V_233 ;
int V_10 = 0 ;
V_230 = ( V_15 -> V_53 & ( V_234 | V_235 ) ) == V_235 ;
V_232 = V_15 -> V_43 ;
V_233 = V_15 -> V_217 ;
if ( V_230 )
F_246 ( V_226 , V_232 , V_233 ) ;
for ( V_138 = V_15 -> V_43 ; V_138 < V_15 -> V_217 ; V_138 += V_231 ) {
T_11 * V_236 , * V_237 ;
V_227 = F_247 ( V_226 , V_138 ) ;
if ( ! V_227 )
continue;
V_228 = F_248 ( V_225 , V_138 , V_231 ) ;
if ( ! V_228 ) {
V_10 = - V_11 ;
break;
}
if ( V_228 == V_227 )
continue;
V_237 = F_249 ( V_41 , V_225 , V_228 ) ;
V_236 = F_250 ( V_41 , V_226 , V_227 ) ;
F_251 ( V_236 , V_238 ) ;
if ( ! F_252 ( F_242 ( V_227 ) ) ) {
if ( V_230 )
F_253 ( V_226 , V_138 , V_227 ) ;
V_221 = F_242 ( V_227 ) ;
V_229 = F_254 ( V_221 ) ;
F_255 ( V_229 ) ;
F_256 ( V_229 ) ;
F_257 ( V_225 , V_138 , V_228 , V_221 ) ;
}
F_2 ( V_236 ) ;
F_2 ( V_237 ) ;
}
if ( V_230 )
F_258 ( V_226 , V_232 , V_233 ) ;
return V_10 ;
}
static int F_259 ( T_10 V_239 )
{
T_12 V_240 ;
if ( F_252 ( V_239 ) || F_260 ( V_239 ) )
return 0 ;
V_240 = F_261 ( V_239 ) ;
if ( F_262 ( V_240 ) && F_263 ( V_240 ) )
return 1 ;
else
return 0 ;
}
static int F_264 ( T_10 V_239 )
{
T_12 V_240 ;
if ( F_252 ( V_239 ) || F_260 ( V_239 ) )
return 0 ;
V_240 = F_261 ( V_239 ) ;
if ( F_262 ( V_240 ) && F_265 ( V_240 ) )
return 1 ;
else
return 0 ;
}
void F_266 ( struct V_241 * V_242 , struct V_14 * V_15 ,
unsigned long V_216 , unsigned long V_36 ,
struct V_65 * V_243 )
{
int V_244 = 0 ;
struct V_224 * V_245 = V_15 -> V_246 ;
unsigned long V_42 ;
T_10 * V_223 ;
T_10 V_239 ;
T_11 * V_247 ;
struct V_65 * V_65 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
unsigned long V_231 = F_78 ( V_41 ) ;
const unsigned long V_232 = V_216 ;
const unsigned long V_233 = V_36 ;
F_157 ( ! F_35 ( V_15 ) ) ;
F_9 ( V_216 & ~ F_267 ( V_41 ) ) ;
F_9 ( V_36 & ~ F_267 ( V_41 ) ) ;
F_268 ( V_242 , V_15 ) ;
F_246 ( V_245 , V_232 , V_233 ) ;
V_248:
for ( V_42 = V_216 ; V_42 < V_36 ; V_42 += V_231 ) {
V_223 = F_247 ( V_245 , V_42 ) ;
if ( ! V_223 )
continue;
V_247 = F_249 ( V_41 , V_245 , V_223 ) ;
if ( F_269 ( V_245 , & V_42 , V_223 ) )
goto V_249;
V_239 = F_242 ( V_223 ) ;
if ( F_252 ( V_239 ) )
goto V_249;
if ( F_67 ( F_264 ( V_239 ) ) ) {
F_270 ( V_245 , V_42 , V_223 ) ;
goto V_249;
}
V_65 = F_254 ( V_239 ) ;
if ( V_243 ) {
if ( V_65 != V_243 )
goto V_249;
F_47 ( V_15 , V_250 ) ;
}
V_239 = F_271 ( V_245 , V_42 , V_223 ) ;
F_272 ( V_242 , V_223 , V_42 ) ;
if ( F_273 ( V_239 ) )
F_274 ( V_65 ) ;
F_275 ( V_65 ) ;
V_244 = ! F_276 ( V_242 , V_65 ) ;
if ( V_244 ) {
F_2 ( V_247 ) ;
break;
}
if ( V_243 ) {
F_2 ( V_247 ) ;
break;
}
V_249:
F_2 ( V_247 ) ;
}
if ( V_244 ) {
V_244 = 0 ;
F_277 ( V_242 ) ;
if ( V_42 < V_36 && ! V_243 )
goto V_248;
}
F_258 ( V_245 , V_232 , V_233 ) ;
F_278 ( V_242 , V_15 ) ;
}
void F_279 ( struct V_241 * V_242 ,
struct V_14 * V_15 , unsigned long V_216 ,
unsigned long V_36 , struct V_65 * V_243 )
{
F_266 ( V_242 , V_15 , V_216 , V_36 , V_243 ) ;
V_15 -> V_53 &= ~ V_54 ;
}
void F_280 ( struct V_14 * V_15 , unsigned long V_216 ,
unsigned long V_36 , struct V_65 * V_243 )
{
struct V_224 * V_245 ;
struct V_241 V_242 ;
V_245 = V_15 -> V_246 ;
F_281 ( & V_242 , V_245 , V_216 , V_36 ) ;
F_266 ( & V_242 , V_15 , V_216 , V_36 , V_243 ) ;
F_282 ( & V_242 , V_216 , V_36 ) ;
}
static int F_283 ( struct V_224 * V_245 , struct V_14 * V_15 ,
struct V_65 * V_65 , unsigned long V_42 )
{
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_14 * V_251 ;
struct V_55 * V_56 ;
T_1 V_252 ;
V_42 = V_42 & F_267 ( V_41 ) ;
V_252 = ( ( V_42 - V_15 -> V_43 ) >> V_150 ) +
V_15 -> V_44 ;
V_56 = F_15 ( V_15 -> V_16 ) -> V_51 ;
F_284 ( & V_56 -> V_253 ) ;
F_285 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_251 == V_15 )
continue;
if ( ! F_48 ( V_251 , V_64 ) )
F_280 ( V_251 , V_42 ,
V_42 + F_78 ( V_41 ) , V_65 ) ;
}
F_286 ( & V_56 -> V_253 ) ;
return 1 ;
}
static int F_287 ( struct V_224 * V_245 , struct V_14 * V_15 ,
unsigned long V_42 , T_10 * V_223 , T_10 V_239 ,
struct V_65 * V_254 , T_11 * V_247 )
{
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_65 * V_255 , * V_256 ;
int V_257 = 0 ;
unsigned long V_232 ;
unsigned long V_233 ;
V_255 = F_254 ( V_239 ) ;
V_258:
if ( F_84 ( V_255 ) == 1 && F_288 ( V_255 ) ) {
F_289 ( V_255 , V_15 , V_42 ) ;
F_241 ( V_15 , V_42 , V_223 ) ;
return 0 ;
}
if ( F_48 ( V_15 , V_64 ) &&
V_255 != V_254 )
V_257 = 1 ;
F_290 ( V_255 ) ;
F_2 ( V_247 ) ;
V_256 = F_140 ( V_15 , V_42 , V_257 ) ;
if ( F_146 ( V_256 ) ) {
long V_85 = F_291 ( V_256 ) ;
F_292 ( V_255 ) ;
if ( V_257 ) {
F_9 ( F_252 ( V_239 ) ) ;
if ( F_283 ( V_245 , V_15 , V_255 , V_42 ) ) {
F_9 ( F_252 ( V_239 ) ) ;
F_8 ( V_247 ) ;
V_223 = F_247 ( V_245 , V_42 & F_267 ( V_41 ) ) ;
if ( F_293 ( V_223 &&
F_294 ( F_242 ( V_223 ) , V_239 ) ) )
goto V_258;
return 0 ;
}
F_295 ( 1 ) ;
}
F_8 ( V_247 ) ;
if ( V_85 == - V_11 )
return V_259 ;
else
return V_260 ;
}
if ( F_67 ( F_296 ( V_15 ) ) ) {
F_292 ( V_256 ) ;
F_292 ( V_255 ) ;
F_8 ( V_247 ) ;
return V_259 ;
}
F_297 ( V_256 , V_255 , V_42 , V_15 ,
F_70 ( V_41 ) ) ;
F_298 ( V_256 ) ;
V_232 = V_42 & F_267 ( V_41 ) ;
V_233 = V_232 + F_78 ( V_41 ) ;
F_246 ( V_245 , V_232 , V_233 ) ;
F_8 ( V_247 ) ;
V_223 = F_247 ( V_245 , V_42 & F_267 ( V_41 ) ) ;
if ( F_293 ( V_223 && F_294 ( F_242 ( V_223 ) , V_239 ) ) ) {
F_86 ( V_256 ) ;
F_299 ( V_15 , V_42 , V_223 ) ;
F_257 ( V_245 , V_42 , V_223 ,
F_233 ( V_15 , V_256 , 1 ) ) ;
F_275 ( V_255 ) ;
F_300 ( V_256 , V_15 , V_42 ) ;
V_256 = V_255 ;
}
F_2 ( V_247 ) ;
F_258 ( V_245 , V_232 , V_233 ) ;
F_292 ( V_256 ) ;
F_292 ( V_255 ) ;
F_8 ( V_247 ) ;
return 0 ;
}
static struct V_65 * F_301 ( struct V_40 * V_41 ,
struct V_14 * V_15 , unsigned long V_42 )
{
struct V_55 * V_56 ;
T_1 V_139 ;
V_56 = V_15 -> V_16 -> V_57 ;
V_139 = F_29 ( V_41 , V_15 , V_42 ) ;
return F_302 ( V_56 , V_139 ) ;
}
static bool F_303 ( struct V_40 * V_41 ,
struct V_14 * V_15 , unsigned long V_42 )
{
struct V_55 * V_56 ;
T_1 V_139 ;
struct V_65 * V_65 ;
V_56 = V_15 -> V_16 -> V_57 ;
V_139 = F_29 ( V_41 , V_15 , V_42 ) ;
V_65 = F_304 ( V_56 , V_139 ) ;
if ( V_65 )
F_92 ( V_65 ) ;
return V_65 != NULL ;
}
static int F_305 ( struct V_224 * V_245 , struct V_14 * V_15 ,
struct V_55 * V_56 , T_1 V_139 ,
unsigned long V_42 , T_10 * V_223 , unsigned int V_61 )
{
struct V_40 * V_41 = F_33 ( V_15 ) ;
int V_10 = V_260 ;
int V_261 = 0 ;
unsigned long V_100 ;
struct V_65 * V_65 ;
T_10 V_262 ;
T_11 * V_247 ;
if ( F_48 ( V_15 , V_250 ) ) {
F_212 ( L_23 ,
V_156 -> V_263 ) ;
return V_10 ;
}
V_32:
V_65 = F_302 ( V_56 , V_139 ) ;
if ( ! V_65 ) {
V_100 = F_306 ( V_56 -> V_58 ) >> F_30 ( V_41 ) ;
if ( V_139 >= V_100 )
goto V_35;
V_65 = F_140 ( V_15 , V_42 , 0 ) ;
if ( F_146 ( V_65 ) ) {
V_10 = F_291 ( V_65 ) ;
if ( V_10 == - V_11 )
V_10 = V_259 ;
else
V_10 = V_260 ;
goto V_35;
}
F_307 ( V_65 , V_42 , F_70 ( V_41 ) ) ;
F_298 ( V_65 ) ;
if ( V_15 -> V_53 & V_54 ) {
int V_85 ;
struct V_12 * V_12 = V_56 -> V_58 ;
V_85 = F_308 ( V_65 , V_56 , V_139 , V_7 ) ;
if ( V_85 ) {
F_92 ( V_65 ) ;
if ( V_85 == - V_264 )
goto V_32;
goto V_35;
}
F_86 ( V_65 ) ;
F_8 ( & V_12 -> V_265 ) ;
V_12 -> V_266 += F_309 ( V_41 ) ;
F_2 ( & V_12 -> V_265 ) ;
} else {
F_310 ( V_65 ) ;
if ( F_67 ( F_296 ( V_15 ) ) ) {
V_10 = V_259 ;
goto V_267;
}
V_261 = 1 ;
}
} else {
if ( F_67 ( F_311 ( V_65 ) ) ) {
V_10 = V_268 |
F_312 ( F_88 ( V_41 ) ) ;
goto V_267;
}
}
if ( ( V_61 & V_269 ) && ! ( V_15 -> V_53 & V_234 ) )
if ( F_138 ( V_41 , V_15 , V_42 ) < 0 ) {
V_10 = V_259 ;
goto V_267;
}
V_247 = F_250 ( V_41 , V_245 , V_223 ) ;
F_8 ( V_247 ) ;
V_100 = F_306 ( V_56 -> V_58 ) >> F_30 ( V_41 ) ;
if ( V_139 >= V_100 )
goto V_270;
V_10 = 0 ;
if ( ! F_252 ( F_242 ( V_223 ) ) )
goto V_270;
if ( V_261 ) {
F_86 ( V_65 ) ;
F_300 ( V_65 , V_15 , V_42 ) ;
} else
F_256 ( V_65 ) ;
V_262 = F_233 ( V_15 , V_65 , ( ( V_15 -> V_53 & V_271 )
&& ( V_15 -> V_53 & V_234 ) ) ) ;
F_257 ( V_245 , V_42 , V_223 , V_262 ) ;
if ( ( V_61 & V_269 ) && ! ( V_15 -> V_53 & V_234 ) ) {
V_10 = F_287 ( V_245 , V_15 , V_42 , V_223 , V_262 , V_65 , V_247 ) ;
}
F_2 ( V_247 ) ;
F_313 ( V_65 ) ;
V_35:
return V_10 ;
V_270:
F_2 ( V_247 ) ;
V_267:
F_313 ( V_65 ) ;
F_92 ( V_65 ) ;
goto V_35;
}
static T_13 F_314 ( struct V_40 * V_41 , struct V_224 * V_245 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
T_1 V_139 , unsigned long V_42 )
{
unsigned long V_272 [ 2 ] ;
T_13 V_273 ;
if ( V_15 -> V_53 & V_234 ) {
V_272 [ 0 ] = ( unsigned long ) V_56 ;
V_272 [ 1 ] = V_139 ;
} else {
V_272 [ 0 ] = ( unsigned long ) V_245 ;
V_272 [ 1 ] = V_42 >> F_30 ( V_41 ) ;
}
V_273 = F_315 ( ( T_13 * ) & V_272 , sizeof( V_272 ) / sizeof( T_13 ) , 0 ) ;
return V_273 & ( V_193 - 1 ) ;
}
static T_13 F_314 ( struct V_40 * V_41 , struct V_224 * V_245 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
T_1 V_139 , unsigned long V_42 )
{
return 0 ;
}
int F_316 ( struct V_224 * V_245 , struct V_14 * V_15 ,
unsigned long V_42 , unsigned int V_61 )
{
T_10 * V_223 , V_221 ;
T_11 * V_247 ;
int V_10 ;
T_13 V_273 ;
T_1 V_139 ;
struct V_65 * V_65 = NULL ;
struct V_65 * V_254 = NULL ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
struct V_55 * V_56 ;
V_42 &= F_267 ( V_41 ) ;
V_223 = F_247 ( V_245 , V_42 ) ;
if ( V_223 ) {
V_221 = F_242 ( V_223 ) ;
if ( F_67 ( F_259 ( V_221 ) ) ) {
F_317 ( V_15 , V_245 , V_223 ) ;
return 0 ;
} else if ( F_67 ( F_264 ( V_221 ) ) )
return V_274 |
F_312 ( F_88 ( V_41 ) ) ;
}
V_223 = F_248 ( V_245 , V_42 , F_78 ( V_41 ) ) ;
if ( ! V_223 )
return V_259 ;
V_56 = V_15 -> V_16 -> V_57 ;
V_139 = F_29 ( V_41 , V_15 , V_42 ) ;
V_273 = F_314 ( V_41 , V_245 , V_15 , V_56 , V_139 , V_42 ) ;
F_284 ( & V_186 [ V_273 ] ) ;
V_221 = F_242 ( V_223 ) ;
if ( F_252 ( V_221 ) ) {
V_10 = F_305 ( V_245 , V_15 , V_56 , V_139 , V_42 , V_223 , V_61 ) ;
goto V_275;
}
V_10 = 0 ;
if ( ( V_61 & V_269 ) && ! F_318 ( V_221 ) ) {
if ( F_138 ( V_41 , V_15 , V_42 ) < 0 ) {
V_10 = V_259 ;
goto V_275;
}
if ( ! ( V_15 -> V_53 & V_54 ) )
V_254 = F_301 ( V_41 ,
V_15 , V_42 ) ;
}
V_65 = F_254 ( V_221 ) ;
F_255 ( V_65 ) ;
if ( V_65 != V_254 )
F_310 ( V_65 ) ;
V_247 = F_250 ( V_41 , V_245 , V_223 ) ;
F_8 ( V_247 ) ;
if ( F_67 ( ! F_294 ( V_221 , F_242 ( V_223 ) ) ) )
goto V_276;
if ( V_61 & V_269 ) {
if ( ! F_318 ( V_221 ) ) {
V_10 = F_287 ( V_245 , V_15 , V_42 , V_223 , V_221 ,
V_254 , V_247 ) ;
goto V_276;
}
V_221 = F_235 ( V_221 ) ;
}
V_221 = F_238 ( V_221 ) ;
if ( F_243 ( V_15 , V_42 , V_223 , V_221 ,
V_61 & V_269 ) )
F_244 ( V_15 , V_42 , V_223 ) ;
V_276:
F_2 ( V_247 ) ;
if ( V_254 ) {
F_313 ( V_254 ) ;
F_92 ( V_254 ) ;
}
if ( V_65 != V_254 )
F_313 ( V_65 ) ;
F_92 ( V_65 ) ;
V_275:
F_286 ( & V_186 [ V_273 ] ) ;
return V_10 ;
}
long F_319 ( struct V_224 * V_245 , struct V_14 * V_15 ,
struct V_65 * * V_277 , struct V_14 * * V_278 ,
unsigned long * V_279 , unsigned long * V_105 ,
long V_87 , unsigned int V_61 )
{
unsigned long V_280 ;
unsigned long V_281 = * V_279 ;
unsigned long V_282 = * V_105 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
while ( V_281 < V_15 -> V_217 && V_282 ) {
T_10 * V_239 ;
T_11 * V_247 = NULL ;
int V_283 ;
struct V_65 * V_65 ;
V_239 = F_247 ( V_245 , V_281 & F_267 ( V_41 ) ) ;
if ( V_239 )
V_247 = F_249 ( V_41 , V_245 , V_239 ) ;
V_283 = ! V_239 || F_252 ( F_242 ( V_239 ) ) ;
if ( V_283 && ( V_61 & V_284 ) &&
! F_303 ( V_41 , V_15 , V_281 ) ) {
if ( V_239 )
F_2 ( V_247 ) ;
V_282 = 0 ;
break;
}
if ( V_283 || F_320 ( F_242 ( V_239 ) ) ||
( ( V_61 & V_285 ) &&
! F_318 ( F_242 ( V_239 ) ) ) ) {
int V_10 ;
if ( V_239 )
F_2 ( V_247 ) ;
V_10 = F_316 ( V_245 , V_15 , V_281 ,
( V_61 & V_285 ) ? V_269 : 0 ) ;
if ( ! ( V_10 & V_286 ) )
continue;
V_282 = 0 ;
break;
}
V_280 = ( V_281 & ~ F_267 ( V_41 ) ) >> V_150 ;
V_65 = F_254 ( F_242 ( V_239 ) ) ;
V_287:
if ( V_277 ) {
V_277 [ V_87 ] = F_321 ( V_65 , V_280 ) ;
F_322 ( V_277 [ V_87 ] ) ;
}
if ( V_278 )
V_278 [ V_87 ] = V_15 ;
V_281 += V_45 ;
++ V_280 ;
-- V_282 ;
++ V_87 ;
if ( V_281 < V_15 -> V_217 && V_282 &&
V_280 < F_70 ( V_41 ) ) {
goto V_287;
}
F_2 ( V_247 ) ;
}
* V_105 = V_282 ;
* V_279 = V_281 ;
return V_87 ? V_87 : - V_288 ;
}
unsigned long F_323 ( struct V_14 * V_15 ,
unsigned long V_42 , unsigned long V_36 , T_14 V_289 )
{
struct V_224 * V_245 = V_15 -> V_246 ;
unsigned long V_216 = V_42 ;
T_10 * V_223 ;
T_10 V_239 ;
struct V_40 * V_41 = F_33 ( V_15 ) ;
unsigned long V_277 = 0 ;
F_9 ( V_42 >= V_36 ) ;
F_324 ( V_15 , V_42 , V_36 ) ;
F_246 ( V_245 , V_216 , V_36 ) ;
F_284 ( & V_15 -> V_16 -> V_57 -> V_253 ) ;
for (; V_42 < V_36 ; V_42 += F_78 ( V_41 ) ) {
T_11 * V_247 ;
V_223 = F_247 ( V_245 , V_42 ) ;
if ( ! V_223 )
continue;
V_247 = F_249 ( V_41 , V_245 , V_223 ) ;
if ( F_269 ( V_245 , & V_42 , V_223 ) ) {
V_277 ++ ;
F_2 ( V_247 ) ;
continue;
}
if ( ! F_252 ( F_242 ( V_223 ) ) ) {
V_239 = F_271 ( V_245 , V_42 , V_223 ) ;
V_239 = F_239 ( F_325 ( V_239 , V_289 ) ) ;
V_239 = F_240 ( V_239 , V_15 , NULL , 0 ) ;
F_257 ( V_245 , V_42 , V_223 , V_239 ) ;
V_277 ++ ;
}
F_2 ( V_247 ) ;
}
F_326 ( V_15 , V_216 , V_36 ) ;
F_286 ( & V_15 -> V_16 -> V_57 -> V_253 ) ;
F_258 ( V_245 , V_216 , V_36 ) ;
return V_277 << V_41 -> V_88 ;
}
int F_327 ( struct V_12 * V_12 ,
long V_29 , long V_28 ,
struct V_14 * V_15 ,
T_15 V_53 )
{
long V_10 , V_31 ;
struct V_40 * V_41 = F_328 ( V_12 ) ;
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
goto V_290;
}
if ( F_10 ( V_2 , V_31 ) ) {
V_10 = - V_142 ;
goto V_290;
}
V_10 = F_227 ( V_41 , V_31 ) ;
if ( V_10 < 0 ) {
F_11 ( V_2 , V_31 ) ;
goto V_290;
}
if ( ! V_15 || V_15 -> V_53 & V_54 )
F_16 ( V_17 , V_29 , V_28 ) ;
return 0 ;
V_290:
if ( V_15 && F_48 ( V_15 , V_64 ) )
F_231 ( & V_17 -> V_48 , F_41 ) ;
return V_10 ;
}
void F_329 ( struct V_12 * V_12 , long V_291 , long V_292 )
{
struct V_40 * V_41 = F_328 ( V_12 ) ;
struct V_17 * V_17 = F_43 ( V_12 ) ;
long V_31 = 0 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( V_17 )
V_31 = F_23 ( V_17 , V_291 ) ;
F_8 ( & V_12 -> V_265 ) ;
V_12 -> V_266 -= ( F_309 ( V_41 ) * V_292 ) ;
F_2 ( & V_12 -> V_265 ) ;
F_11 ( V_2 , ( V_31 - V_292 ) ) ;
F_227 ( V_41 , - ( V_31 - V_292 ) ) ;
}
static unsigned long F_330 ( struct V_14 * V_293 ,
struct V_14 * V_15 ,
unsigned long V_138 , T_1 V_139 )
{
unsigned long V_294 = ( ( V_139 - V_293 -> V_44 ) << V_150 ) +
V_293 -> V_43 ;
unsigned long V_295 = V_294 & V_296 ;
unsigned long V_297 = V_295 + V_298 ;
unsigned long V_53 = V_15 -> V_53 & ~ V_299 ;
unsigned long V_300 = V_293 -> V_53 & ~ V_299 ;
if ( F_331 ( V_138 ) != F_331 ( V_294 ) ||
V_53 != V_300 ||
V_295 < V_293 -> V_43 || V_293 -> V_217 < V_297 )
return 0 ;
return V_294 ;
}
static int F_332 ( struct V_14 * V_15 , unsigned long V_138 )
{
unsigned long V_301 = V_138 & V_296 ;
unsigned long V_36 = V_301 + V_298 ;
if ( V_15 -> V_53 & V_54 &&
V_15 -> V_43 <= V_301 && V_36 <= V_15 -> V_217 )
return 1 ;
return 0 ;
}
T_10 * F_333 ( struct V_224 * V_245 , unsigned long V_138 , T_16 * V_302 )
{
struct V_14 * V_15 = F_334 ( V_245 , V_138 ) ;
struct V_55 * V_56 = V_15 -> V_16 -> V_57 ;
T_1 V_139 = ( ( V_138 - V_15 -> V_43 ) >> V_150 ) +
V_15 -> V_44 ;
struct V_14 * V_293 ;
unsigned long V_294 ;
T_10 * V_303 = NULL ;
T_10 * V_239 ;
T_11 * V_247 ;
if ( ! F_332 ( V_15 , V_138 ) )
return ( T_10 * ) F_335 ( V_245 , V_302 , V_138 ) ;
F_284 ( & V_56 -> V_253 ) ;
F_285 (svma, &mapping->i_mmap, idx, idx) {
if ( V_293 == V_15 )
continue;
V_294 = F_330 ( V_293 , V_15 , V_138 , V_139 ) ;
if ( V_294 ) {
V_303 = F_247 ( V_293 -> V_246 , V_294 ) ;
if ( V_303 ) {
F_255 ( F_156 ( V_303 ) ) ;
break;
}
}
}
if ( ! V_303 )
goto V_35;
V_247 = F_250 ( F_33 ( V_15 ) , V_245 , V_303 ) ;
F_8 ( V_247 ) ;
if ( F_336 ( * V_302 ) )
F_337 ( V_245 , V_302 ,
( V_304 * ) ( ( unsigned long ) V_303 & V_305 ) ) ;
else
F_92 ( F_156 ( V_303 ) ) ;
F_2 ( V_247 ) ;
V_35:
V_239 = ( T_10 * ) F_335 ( V_245 , V_302 , V_138 ) ;
F_286 ( & V_56 -> V_253 ) ;
return V_239 ;
}
int F_269 ( struct V_224 * V_245 , unsigned long * V_138 , T_10 * V_223 )
{
T_17 * V_306 = F_338 ( V_245 , * V_138 ) ;
T_16 * V_302 = F_339 ( V_306 , * V_138 ) ;
F_9 ( F_83 ( F_156 ( V_223 ) ) == 0 ) ;
if ( F_83 ( F_156 ( V_223 ) ) == 1 )
return 0 ;
F_340 ( V_302 ) ;
F_92 ( F_156 ( V_223 ) ) ;
* V_138 = F_341 ( * V_138 , V_188 * V_307 ) - V_188 ;
return 1 ;
}
T_10 * F_333 ( struct V_224 * V_245 , unsigned long V_138 , T_16 * V_302 )
{
return NULL ;
}
T_10 * F_248 ( struct V_224 * V_245 ,
unsigned long V_138 , unsigned long V_231 )
{
T_17 * V_306 ;
T_16 * V_302 ;
T_10 * V_239 = NULL ;
V_306 = F_338 ( V_245 , V_138 ) ;
V_302 = F_342 ( V_245 , V_306 , V_138 ) ;
if ( V_302 ) {
if ( V_231 == V_298 ) {
V_239 = ( T_10 * ) V_302 ;
} else {
F_9 ( V_231 != V_308 ) ;
if ( F_343 () && F_336 ( * V_302 ) )
V_239 = F_333 ( V_245 , V_138 , V_302 ) ;
else
V_239 = ( T_10 * ) F_335 ( V_245 , V_302 , V_138 ) ;
}
}
F_9 ( V_239 && ! F_344 ( * V_239 ) && ! F_345 ( * V_239 ) ) ;
return V_239 ;
}
T_10 * F_247 ( struct V_224 * V_245 , unsigned long V_138 )
{
T_17 * V_306 ;
T_16 * V_302 ;
V_304 * V_309 = NULL ;
V_306 = F_338 ( V_245 , V_138 ) ;
if ( F_346 ( * V_306 ) ) {
V_302 = F_339 ( V_306 , V_138 ) ;
if ( F_347 ( * V_302 ) ) {
if ( F_348 ( * V_302 ) )
return ( T_10 * ) V_302 ;
V_309 = F_349 ( V_302 , V_138 ) ;
}
}
return ( T_10 * ) V_309 ;
}
struct V_65 *
F_350 ( struct V_224 * V_245 , unsigned long V_42 ,
V_304 * V_309 , int V_206 )
{
struct V_65 * V_65 ;
V_65 = F_254 ( * ( T_10 * ) V_309 ) ;
if ( V_65 )
V_65 += ( ( V_42 & ~ V_310 ) >> V_150 ) ;
return V_65 ;
}
struct V_65 *
F_351 ( struct V_224 * V_245 , unsigned long V_42 ,
T_16 * V_302 , int V_206 )
{
struct V_65 * V_65 ;
V_65 = F_254 ( * ( T_10 * ) V_302 ) ;
if ( V_65 )
V_65 += ( ( V_42 & ~ V_296 ) >> V_150 ) ;
return V_65 ;
}
struct V_65 * __weak
F_351 ( struct V_224 * V_245 , unsigned long V_42 ,
T_16 * V_302 , int V_206 )
{
F_196 () ;
return NULL ;
}
static int F_352 ( struct V_65 * V_311 )
{
struct V_65 * V_65 ;
struct V_65 * V_131 ;
struct V_40 * V_41 = F_80 ( V_311 ) ;
int V_66 = F_52 ( V_311 ) ;
F_18 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_65 == V_311 )
return 1 ;
return 0 ;
}
int F_353 ( struct V_65 * V_311 )
{
struct V_40 * V_41 = F_80 ( V_311 ) ;
int V_66 = F_52 ( V_311 ) ;
int V_10 = - V_312 ;
F_8 ( & V_102 ) ;
if ( F_352 ( V_311 ) ) {
F_354 ( & V_311 -> V_67 ) ;
F_56 ( V_311 ) ;
V_41 -> V_69 -- ;
V_41 -> V_70 [ V_66 ] -- ;
V_10 = 0 ;
}
F_2 ( & V_102 ) ;
return V_10 ;
}
bool F_355 ( struct V_65 * V_65 , struct V_21 * V_147 )
{
F_71 ( ! F_105 ( V_65 ) , V_65 ) ;
if ( ! F_356 ( V_65 ) )
return false ;
F_8 ( & V_102 ) ;
F_357 ( & V_65 -> V_67 , V_147 ) ;
F_2 ( & V_102 ) ;
return true ;
}
void F_358 ( struct V_65 * V_65 )
{
F_71 ( ! F_105 ( V_65 ) , V_65 ) ;
F_8 ( & V_102 ) ;
F_357 ( & V_65 -> V_67 , & ( F_80 ( V_65 ) ) -> V_71 ) ;
F_2 ( & V_102 ) ;
F_92 ( V_65 ) ;
}
bool F_359 ( struct V_65 * V_65 )
{
F_71 ( ! F_100 ( V_65 ) , V_65 ) ;
if ( F_360 ( V_65 ) )
return false ;
if ( F_67 ( F_311 ( V_65 ) ) )
return false ;
return F_83 ( V_65 ) > 0 ;
}
