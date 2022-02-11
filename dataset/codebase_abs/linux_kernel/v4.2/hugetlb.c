static inline void F_1 ( struct V_1 * V_2 )
{
bool free = ( V_2 -> V_3 == 0 ) && ( V_2 -> V_4 == 0 ) ;
F_2 ( & V_2 -> V_5 ) ;
if ( free ) {
if ( V_2 -> V_6 != - 1 )
F_3 ( V_2 -> V_7 ,
- V_2 -> V_6 ) ;
F_4 ( V_2 ) ;
}
}
struct V_1 * F_5 ( struct V_7 * V_8 , long V_9 ,
long V_6 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_7 ( & V_2 -> V_5 ) ;
V_2 -> V_3 = 1 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_6 = V_6 ;
if ( V_6 != - 1 && F_3 ( V_8 , V_6 ) ) {
F_4 ( V_2 ) ;
return NULL ;
}
V_2 -> V_11 = V_6 ;
return V_2 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_5 ) ;
F_10 ( ! V_2 -> V_3 ) ;
V_2 -> V_3 -- ;
F_1 ( V_2 ) ;
}
static long F_11 ( struct V_1 * V_2 ,
long V_12 )
{
long V_13 = V_12 ;
if ( ! V_2 )
return V_13 ;
F_9 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_9 != - 1 ) {
if ( ( V_2 -> V_4 + V_12 ) <= V_2 -> V_9 )
V_2 -> V_4 += V_12 ;
else {
V_13 = - V_14 ;
goto V_15;
}
}
if ( V_2 -> V_6 != - 1 ) {
if ( V_12 > V_2 -> V_11 ) {
V_13 = V_12 - V_2 -> V_11 ;
V_2 -> V_11 = 0 ;
} else {
V_13 = 0 ;
V_2 -> V_11 -= V_12 ;
}
}
V_15:
F_2 ( & V_2 -> V_5 ) ;
return V_13 ;
}
static long F_12 ( struct V_1 * V_2 ,
long V_12 )
{
long V_13 = V_12 ;
if ( ! V_2 )
return V_12 ;
F_9 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_9 != - 1 )
V_2 -> V_4 -= V_12 ;
if ( V_2 -> V_6 != - 1 ) {
if ( V_2 -> V_11 + V_12 <= V_2 -> V_6 )
V_13 = 0 ;
else
V_13 = V_2 -> V_11 + V_12 - V_2 -> V_6 ;
V_2 -> V_11 += V_12 ;
if ( V_2 -> V_11 > V_2 -> V_6 )
V_2 -> V_11 = V_2 -> V_6 ;
}
F_1 ( V_2 ) ;
return V_13 ;
}
static inline struct V_1 * F_13 ( struct V_16 * V_16 )
{
return F_14 ( V_16 -> V_17 ) -> V_2 ;
}
static inline struct V_1 * F_15 ( struct V_18 * V_19 )
{
return F_13 ( F_16 ( V_19 -> V_20 ) ) ;
}
static long F_17 ( struct V_21 * V_22 , long V_23 , long V_24 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_28 * V_29 , * V_30 , * V_31 ;
long V_32 = 0 ;
F_9 ( & V_22 -> V_5 ) ;
F_18 (rg, head, link)
if ( V_23 <= V_29 -> V_33 )
break;
if ( V_23 > V_29 -> V_34 )
V_23 = V_29 -> V_34 ;
V_30 = V_29 ;
F_19 (rg, trg, rg->link.prev, link) {
if ( & V_29 -> V_35 == V_26 )
break;
if ( V_29 -> V_34 > V_24 )
break;
if ( V_29 -> V_33 > V_24 )
V_24 = V_29 -> V_33 ;
if ( V_29 != V_30 ) {
V_32 -= ( V_29 -> V_33 - V_29 -> V_34 ) ;
F_20 ( & V_29 -> V_35 ) ;
F_4 ( V_29 ) ;
}
}
V_32 += ( V_30 -> V_34 - V_23 ) ;
V_30 -> V_34 = V_23 ;
V_32 += V_24 - V_30 -> V_33 ;
V_30 -> V_33 = V_24 ;
F_2 ( & V_22 -> V_5 ) ;
F_21 ( V_32 < 0 ) ;
return V_32 ;
}
static long F_22 ( struct V_21 * V_22 , long V_23 , long V_24 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_28 * V_29 , * V_30 = NULL ;
long V_36 = 0 ;
V_37:
F_9 ( & V_22 -> V_5 ) ;
F_18 (rg, head, link)
if ( V_23 <= V_29 -> V_33 )
break;
if ( & V_29 -> V_35 == V_26 || V_24 < V_29 -> V_34 ) {
if ( ! V_30 ) {
F_2 ( & V_22 -> V_5 ) ;
V_30 = F_23 ( sizeof( * V_30 ) , V_10 ) ;
if ( ! V_30 )
return - V_14 ;
V_30 -> V_34 = V_23 ;
V_30 -> V_33 = V_23 ;
F_24 ( & V_30 -> V_35 ) ;
goto V_37;
}
F_25 ( & V_30 -> V_35 , V_29 -> V_35 . V_38 ) ;
V_36 = V_24 - V_23 ;
goto V_39;
}
if ( V_23 > V_29 -> V_34 )
V_23 = V_29 -> V_34 ;
V_36 = V_24 - V_23 ;
F_18 (rg, rg->link.prev, link) {
if ( & V_29 -> V_35 == V_26 )
break;
if ( V_29 -> V_34 > V_24 )
goto V_40;
if ( V_29 -> V_33 > V_24 ) {
V_36 += V_29 -> V_33 - V_24 ;
V_24 = V_29 -> V_33 ;
}
V_36 -= V_29 -> V_33 - V_29 -> V_34 ;
}
V_40:
F_2 ( & V_22 -> V_5 ) ;
F_4 ( V_30 ) ;
return V_36 ;
V_39:
F_2 ( & V_22 -> V_5 ) ;
return V_36 ;
}
static long F_26 ( struct V_21 * V_22 , long V_41 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_28 * V_29 , * V_31 ;
long V_36 = 0 ;
F_9 ( & V_22 -> V_5 ) ;
F_18 (rg, head, link)
if ( V_41 <= V_29 -> V_33 )
break;
if ( & V_29 -> V_35 == V_26 )
goto V_40;
if ( V_41 > V_29 -> V_34 ) {
V_36 = V_29 -> V_33 - V_41 ;
V_29 -> V_33 = V_41 ;
V_29 = F_27 ( V_29 -> V_35 . V_42 , F_28 ( * V_29 ) , V_35 ) ;
}
F_19 (rg, trg, rg->link.prev, link) {
if ( & V_29 -> V_35 == V_26 )
break;
V_36 += V_29 -> V_33 - V_29 -> V_34 ;
F_20 ( & V_29 -> V_35 ) ;
F_4 ( V_29 ) ;
}
V_40:
F_2 ( & V_22 -> V_5 ) ;
return V_36 ;
}
static long F_29 ( struct V_21 * V_22 , long V_23 , long V_24 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_28 * V_29 ;
long V_36 = 0 ;
F_9 ( & V_22 -> V_5 ) ;
F_18 (rg, head, link) {
long V_43 ;
long V_44 ;
if ( V_29 -> V_33 <= V_23 )
continue;
if ( V_29 -> V_34 >= V_24 )
break;
V_43 = F_30 ( V_29 -> V_34 , V_23 ) ;
V_44 = F_31 ( V_29 -> V_33 , V_24 ) ;
V_36 += V_44 - V_43 ;
}
F_2 ( & V_22 -> V_5 ) ;
return V_36 ;
}
static T_1 F_32 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_45 )
{
return ( ( V_45 - V_19 -> V_46 ) >> F_33 ( V_8 ) ) +
( V_19 -> V_47 >> F_34 ( V_8 ) ) ;
}
T_1 F_35 ( struct V_18 * V_19 ,
unsigned long V_45 )
{
return F_32 ( F_36 ( V_19 ) , V_19 , V_45 ) ;
}
unsigned long F_37 ( struct V_18 * V_19 )
{
struct V_7 * V_7 ;
if ( ! F_38 ( V_19 ) )
return V_48 ;
V_7 = F_36 ( V_19 ) ;
return 1UL << F_33 ( V_7 ) ;
}
unsigned long F_39 ( struct V_18 * V_19 )
{
return F_37 ( V_19 ) ;
}
static unsigned long F_40 ( struct V_18 * V_19 )
{
return ( unsigned long ) V_19 -> V_49 ;
}
static void F_41 ( struct V_18 * V_19 ,
unsigned long V_50 )
{
V_19 -> V_49 = ( void * ) V_50 ;
}
struct V_21 * F_42 ( void )
{
struct V_21 * V_21 = F_23 ( sizeof( * V_21 ) , V_10 ) ;
if ( ! V_21 )
return NULL ;
F_43 ( & V_21 -> V_51 ) ;
F_7 ( & V_21 -> V_5 ) ;
F_24 ( & V_21 -> V_27 ) ;
return V_21 ;
}
void F_44 ( struct V_52 * V_53 )
{
struct V_21 * V_21 = F_45 ( V_53 , struct V_21 , V_51 ) ;
F_26 ( V_21 , 0 ) ;
F_4 ( V_21 ) ;
}
static inline struct V_21 * F_46 ( struct V_16 * V_16 )
{
return V_16 -> V_54 -> V_55 ;
}
static struct V_21 * F_47 ( struct V_18 * V_19 )
{
F_48 ( ! F_38 ( V_19 ) , V_19 ) ;
if ( V_19 -> V_56 & V_57 ) {
struct V_58 * V_59 = V_19 -> V_20 -> V_60 ;
struct V_16 * V_16 = V_59 -> V_61 ;
return F_46 ( V_16 ) ;
} else {
return (struct V_21 * ) ( F_40 ( V_19 ) &
~ V_62 ) ;
}
}
static void F_49 ( struct V_18 * V_19 , struct V_21 * V_63 )
{
F_48 ( ! F_38 ( V_19 ) , V_19 ) ;
F_48 ( V_19 -> V_56 & V_57 , V_19 ) ;
F_41 ( V_19 , ( F_40 ( V_19 ) &
V_62 ) | ( unsigned long ) V_63 ) ;
}
static void F_50 ( struct V_18 * V_19 , unsigned long V_64 )
{
F_48 ( ! F_38 ( V_19 ) , V_19 ) ;
F_48 ( V_19 -> V_56 & V_57 , V_19 ) ;
F_41 ( V_19 , F_40 ( V_19 ) | V_64 ) ;
}
static int F_51 ( struct V_18 * V_19 , unsigned long V_65 )
{
F_48 ( ! F_38 ( V_19 ) , V_19 ) ;
return ( F_40 ( V_19 ) & V_65 ) != 0 ;
}
void F_52 ( struct V_18 * V_19 )
{
F_48 ( ! F_38 ( V_19 ) , V_19 ) ;
if ( ! ( V_19 -> V_56 & V_57 ) )
V_19 -> V_49 = ( void * ) 0 ;
}
static int F_53 ( struct V_18 * V_19 , long V_36 )
{
if ( V_19 -> V_56 & V_66 ) {
if ( V_19 -> V_56 & V_57 && V_36 == 0 )
return 1 ;
else
return 0 ;
}
if ( V_19 -> V_56 & V_57 )
return 1 ;
if ( F_51 ( V_19 , V_67 ) )
return 1 ;
return 0 ;
}
static void F_54 ( struct V_7 * V_8 , struct V_68 * V_68 )
{
int V_69 = F_55 ( V_68 ) ;
F_56 ( & V_68 -> V_70 , & V_8 -> V_71 [ V_69 ] ) ;
V_8 -> V_72 ++ ;
V_8 -> V_73 [ V_69 ] ++ ;
}
static struct V_68 * F_57 ( struct V_7 * V_8 , int V_69 )
{
struct V_68 * V_68 ;
F_18 (page, &h->hugepage_freelists[nid], lru)
if ( ! F_58 ( V_68 ) )
break;
if ( & V_8 -> V_71 [ V_69 ] == & V_68 -> V_70 )
return NULL ;
F_56 ( & V_68 -> V_70 , & V_8 -> V_74 ) ;
F_59 ( V_68 ) ;
V_8 -> V_72 -- ;
V_8 -> V_73 [ V_69 ] -- ;
return V_68 ;
}
static inline T_2 F_60 ( struct V_7 * V_8 )
{
if ( V_75 || F_61 ( V_8 ) )
return V_76 ;
else
return V_77 ;
}
static struct V_68 * F_62 ( struct V_7 * V_8 ,
struct V_18 * V_19 ,
unsigned long V_45 , int V_78 ,
long V_36 )
{
struct V_68 * V_68 = NULL ;
struct V_79 * V_80 ;
T_3 * V_81 ;
struct V_82 * V_82 ;
struct V_83 * V_83 ;
struct V_84 * V_85 ;
unsigned int V_86 ;
if ( ! F_53 ( V_19 , V_36 ) &&
V_8 -> V_72 - V_8 -> V_87 == 0 )
goto V_88;
if ( V_78 && V_8 -> V_72 - V_8 -> V_87 == 0 )
goto V_88;
V_89:
V_86 = F_63 () ;
V_82 = F_64 ( V_19 , V_45 ,
F_60 ( V_8 ) , & V_80 , & V_81 ) ;
F_65 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_66 ( V_83 , F_60 ( V_8 ) ) ) {
V_68 = F_57 ( V_8 , F_67 ( V_83 ) ) ;
if ( V_68 ) {
if ( V_78 )
break;
if ( ! F_53 ( V_19 , V_36 ) )
break;
F_68 ( V_68 ) ;
V_8 -> V_87 -- ;
break;
}
}
}
F_69 ( V_80 ) ;
if ( F_70 ( ! V_68 && F_71 ( V_86 ) ) )
goto V_89;
return V_68 ;
V_88:
return NULL ;
}
static int F_72 ( int V_69 , T_3 * V_90 )
{
V_69 = F_73 ( V_69 , * V_90 ) ;
if ( V_69 == V_91 )
V_69 = F_74 ( * V_90 ) ;
F_21 ( V_69 >= V_91 ) ;
return V_69 ;
}
static int F_75 ( int V_69 , T_3 * V_90 )
{
if ( ! F_76 ( V_69 , * V_90 ) )
V_69 = F_72 ( V_69 , V_90 ) ;
return V_69 ;
}
static int F_77 ( struct V_7 * V_8 ,
T_3 * V_90 )
{
int V_69 ;
F_21 ( ! V_90 ) ;
V_69 = F_75 ( V_8 -> V_92 , V_90 ) ;
V_8 -> V_92 = F_72 ( V_69 , V_90 ) ;
return V_69 ;
}
static int F_78 ( struct V_7 * V_8 , T_3 * V_90 )
{
int V_69 ;
F_21 ( ! V_90 ) ;
V_69 = F_75 ( V_8 -> V_93 , V_90 ) ;
V_8 -> V_93 = F_72 ( V_69 , V_90 ) ;
return V_69 ;
}
static void F_79 ( struct V_68 * V_68 ,
unsigned long V_94 )
{
int V_95 ;
int V_96 = 1 << V_94 ;
struct V_68 * V_97 = V_68 + 1 ;
for ( V_95 = 1 ; V_95 < V_96 ; V_95 ++ , V_97 = F_80 ( V_97 , V_68 , V_95 ) ) {
F_81 ( V_97 ) ;
F_59 ( V_97 ) ;
V_97 -> V_98 = NULL ;
}
F_82 ( V_68 , 0 ) ;
F_83 ( V_68 ) ;
}
static void F_84 ( struct V_68 * V_68 , unsigned V_94 )
{
F_85 ( F_86 ( V_68 ) , 1 << V_94 ) ;
}
static int F_87 ( unsigned long V_99 ,
unsigned long V_96 )
{
unsigned long V_100 = V_99 + V_96 ;
return F_88 ( V_99 , V_100 , V_101 ) ;
}
static bool F_89 ( unsigned long V_99 ,
unsigned long V_96 )
{
unsigned long V_95 , V_100 = V_99 + V_96 ;
struct V_68 * V_68 ;
for ( V_95 = V_99 ; V_95 < V_100 ; V_95 ++ ) {
if ( ! F_90 ( V_95 ) )
return false ;
V_68 = F_91 ( V_95 ) ;
if ( F_92 ( V_68 ) )
return false ;
if ( F_93 ( V_68 ) > 0 )
return false ;
if ( F_94 ( V_68 ) )
return false ;
}
return true ;
}
static bool F_95 ( const struct V_83 * V_83 ,
unsigned long V_99 , unsigned long V_96 )
{
unsigned long V_102 = V_99 + V_96 - 1 ;
return F_96 ( V_83 , V_102 ) ;
}
static struct V_68 * F_97 ( int V_69 , unsigned V_94 )
{
unsigned long V_96 = 1 << V_94 ;
unsigned long V_13 , V_103 , V_64 ;
struct V_83 * V_85 ;
V_85 = F_98 ( V_69 ) -> V_104 ;
for (; V_85 - F_98 ( V_69 ) -> V_104 < V_105 ; V_85 ++ ) {
F_99 ( & V_85 -> V_5 , V_64 ) ;
V_103 = F_100 ( V_85 -> V_106 , V_96 ) ;
while ( F_95 ( V_85 , V_103 , V_96 ) ) {
if ( F_89 ( V_103 , V_96 ) ) {
F_101 ( & V_85 -> V_5 , V_64 ) ;
V_13 = F_87 ( V_103 , V_96 ) ;
if ( ! V_13 )
return F_91 ( V_103 ) ;
F_99 ( & V_85 -> V_5 , V_64 ) ;
}
V_103 += V_96 ;
}
F_101 ( & V_85 -> V_5 , V_64 ) ;
}
return NULL ;
}
static struct V_68 * F_102 ( struct V_7 * V_8 , int V_69 )
{
struct V_68 * V_68 ;
V_68 = F_97 ( V_69 , F_34 ( V_8 ) ) ;
if ( V_68 ) {
F_103 ( V_68 , F_34 ( V_8 ) ) ;
F_104 ( V_8 , V_68 , V_69 ) ;
}
return V_68 ;
}
static int F_105 ( struct V_7 * V_8 ,
T_3 * V_90 )
{
struct V_68 * V_68 = NULL ;
int V_107 , V_108 ;
F_106 (h, nr_nodes, node, nodes_allowed) {
V_68 = F_102 ( V_8 , V_108 ) ;
if ( V_68 )
return 1 ;
}
return 0 ;
}
static inline bool F_107 ( void ) { return true ; }
static inline bool F_107 ( void ) { return false ; }
static inline void F_84 ( struct V_68 * V_68 , unsigned V_94 ) { }
static inline void F_79 ( struct V_68 * V_68 ,
unsigned long V_94 ) { }
static inline int F_105 ( struct V_7 * V_8 ,
T_3 * V_90 ) { return 0 ; }
static void F_108 ( struct V_7 * V_8 , struct V_68 * V_68 )
{
int V_95 ;
if ( F_109 ( V_8 ) && ! F_107 () )
return;
V_8 -> V_109 -- ;
V_8 -> V_110 [ F_55 ( V_68 ) ] -- ;
for ( V_95 = 0 ; V_95 < F_110 ( V_8 ) ; V_95 ++ ) {
V_68 [ V_95 ] . V_64 &= ~ ( 1 << V_111 | 1 << V_112 |
1 << V_113 | 1 << V_114 |
1 << V_115 | 1 << V_116 |
1 << V_117 ) ;
}
F_111 ( F_112 ( V_68 ) , V_68 ) ;
F_113 ( V_68 , NULL ) ;
F_59 ( V_68 ) ;
if ( F_109 ( V_8 ) ) {
F_79 ( V_68 , F_34 ( V_8 ) ) ;
F_84 ( V_68 , F_34 ( V_8 ) ) ;
} else {
F_114 ( V_68 , F_34 ( V_8 ) ) ;
}
}
struct V_7 * F_115 ( unsigned long V_118 )
{
struct V_7 * V_8 ;
F_116 (h) {
if ( F_117 ( V_8 ) == V_118 )
return V_8 ;
}
return NULL ;
}
bool F_118 ( struct V_68 * V_68 )
{
F_111 ( ! F_94 ( V_68 ) , V_68 ) ;
return F_119 ( V_68 ) && F_120 ( & V_68 [ 1 ] ) ;
}
static void F_121 ( struct V_68 * V_68 )
{
F_111 ( ! F_122 ( V_68 ) , V_68 ) ;
F_68 ( & V_68 [ 1 ] ) ;
}
static void F_123 ( struct V_68 * V_68 )
{
F_111 ( ! F_122 ( V_68 ) , V_68 ) ;
F_124 ( & V_68 [ 1 ] ) ;
}
void F_125 ( struct V_68 * V_68 )
{
struct V_7 * V_8 = F_126 ( V_68 ) ;
int V_69 = F_55 ( V_68 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_127 ( V_68 ) ;
bool V_119 ;
F_128 ( V_68 , 0 ) ;
V_68 -> V_59 = NULL ;
F_10 ( F_93 ( V_68 ) ) ;
F_10 ( F_129 ( V_68 ) ) ;
V_119 = F_120 ( V_68 ) ;
F_124 ( V_68 ) ;
if ( F_12 ( V_2 , 1 ) == 0 )
V_119 = true ;
F_9 ( & V_120 ) ;
F_123 ( V_68 ) ;
F_130 ( F_131 ( V_8 ) ,
F_110 ( V_8 ) , V_68 ) ;
if ( V_119 )
V_8 -> V_87 ++ ;
if ( V_8 -> V_121 [ V_69 ] ) {
F_20 ( & V_68 -> V_70 ) ;
F_108 ( V_8 , V_68 ) ;
V_8 -> V_122 -- ;
V_8 -> V_121 [ V_69 ] -- ;
} else {
F_132 ( V_68 ) ;
F_54 ( V_8 , V_68 ) ;
}
F_2 ( & V_120 ) ;
}
static void F_104 ( struct V_7 * V_8 , struct V_68 * V_68 , int V_69 )
{
F_24 ( & V_68 -> V_70 ) ;
F_113 ( V_68 , F_125 ) ;
F_9 ( & V_120 ) ;
F_133 ( V_68 , NULL ) ;
V_8 -> V_109 ++ ;
V_8 -> V_110 [ V_69 ] ++ ;
F_2 ( & V_120 ) ;
F_134 ( V_68 ) ;
}
static void F_103 ( struct V_68 * V_68 , unsigned long V_94 )
{
int V_95 ;
int V_96 = 1 << V_94 ;
struct V_68 * V_97 = V_68 + 1 ;
F_82 ( V_68 , V_94 ) ;
F_135 ( V_68 ) ;
F_136 ( V_68 ) ;
for ( V_95 = 1 ; V_95 < V_96 ; V_95 ++ , V_97 = F_80 ( V_97 , V_68 , V_95 ) ) {
F_136 ( V_97 ) ;
F_137 ( V_97 , 0 ) ;
V_97 -> V_98 = V_68 ;
F_138 () ;
F_139 ( V_97 ) ;
}
}
int F_94 ( struct V_68 * V_68 )
{
if ( ! F_140 ( V_68 ) )
return 0 ;
V_68 = F_141 ( V_68 ) ;
return F_142 ( V_68 ) == F_125 ;
}
int F_122 ( struct V_68 * V_123 )
{
if ( ! F_119 ( V_123 ) )
return 0 ;
return F_142 ( V_123 ) == F_125 ;
}
T_1 F_143 ( struct V_68 * V_68 )
{
struct V_68 * V_123 = F_141 ( V_68 ) ;
T_1 V_124 = F_144 ( V_123 ) ;
unsigned long V_125 ;
if ( ! F_94 ( V_123 ) )
return F_144 ( V_68 ) ;
if ( F_145 ( V_123 ) >= V_126 )
V_125 = F_86 ( V_68 ) - F_86 ( V_123 ) ;
else
V_125 = V_68 - V_123 ;
return ( V_124 << F_145 ( V_123 ) ) + V_125 ;
}
static struct V_68 * F_146 ( struct V_7 * V_8 , int V_69 )
{
struct V_68 * V_68 ;
V_68 = F_147 ( V_69 ,
F_60 ( V_8 ) | V_127 | V_128 |
V_129 | V_130 ,
F_34 ( V_8 ) ) ;
if ( V_68 ) {
F_104 ( V_8 , V_68 , V_69 ) ;
}
return V_68 ;
}
static int F_148 ( struct V_7 * V_8 , T_3 * V_90 )
{
struct V_68 * V_68 ;
int V_107 , V_108 ;
int V_13 = 0 ;
F_106 (h, nr_nodes, node, nodes_allowed) {
V_68 = F_146 ( V_8 , V_108 ) ;
if ( V_68 ) {
V_13 = 1 ;
break;
}
}
if ( V_13 )
F_149 ( V_131 ) ;
else
F_149 ( V_132 ) ;
return V_13 ;
}
static int F_150 ( struct V_7 * V_8 , T_3 * V_90 ,
bool V_133 )
{
int V_107 , V_108 ;
int V_13 = 0 ;
F_151 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_133 || V_8 -> V_121 [ V_108 ] ) &&
! F_152 ( & V_8 -> V_71 [ V_108 ] ) ) {
struct V_68 * V_68 =
F_27 ( V_8 -> V_71 [ V_108 ] . V_42 ,
struct V_68 , V_70 ) ;
F_20 ( & V_68 -> V_70 ) ;
V_8 -> V_72 -- ;
V_8 -> V_73 [ V_108 ] -- ;
if ( V_133 ) {
V_8 -> V_122 -- ;
V_8 -> V_121 [ V_108 ] -- ;
}
F_108 ( V_8 , V_68 ) ;
V_13 = 1 ;
break;
}
}
return V_13 ;
}
static void F_153 ( struct V_68 * V_68 )
{
F_9 ( & V_120 ) ;
if ( F_94 ( V_68 ) && ! F_93 ( V_68 ) ) {
struct V_7 * V_8 = F_126 ( V_68 ) ;
int V_69 = F_55 ( V_68 ) ;
F_20 ( & V_68 -> V_70 ) ;
V_8 -> V_72 -- ;
V_8 -> V_73 [ V_69 ] -- ;
F_108 ( V_8 , V_68 ) ;
}
F_2 ( & V_120 ) ;
}
void F_154 ( unsigned long V_99 , unsigned long V_100 )
{
unsigned long V_103 ;
if ( ! F_155 () )
return;
F_21 ( ! F_156 ( V_99 , 1 << V_134 ) ) ;
for ( V_103 = V_99 ; V_103 < V_100 ; V_103 += 1 << V_134 )
F_153 ( F_91 ( V_103 ) ) ;
}
static struct V_68 * F_157 ( struct V_7 * V_8 , int V_69 )
{
struct V_68 * V_68 ;
unsigned int V_135 ;
if ( F_109 ( V_8 ) )
return NULL ;
F_9 ( & V_120 ) ;
if ( V_8 -> V_122 >= V_8 -> V_136 ) {
F_2 ( & V_120 ) ;
return NULL ;
} else {
V_8 -> V_109 ++ ;
V_8 -> V_122 ++ ;
}
F_2 ( & V_120 ) ;
if ( V_69 == V_137 )
V_68 = F_158 ( F_60 ( V_8 ) | V_127 |
V_129 | V_130 ,
F_34 ( V_8 ) ) ;
else
V_68 = F_147 ( V_69 ,
F_60 ( V_8 ) | V_127 | V_128 |
V_129 | V_130 , F_34 ( V_8 ) ) ;
F_9 ( & V_120 ) ;
if ( V_68 ) {
F_24 ( & V_68 -> V_70 ) ;
V_135 = F_55 ( V_68 ) ;
F_113 ( V_68 , F_125 ) ;
F_133 ( V_68 , NULL ) ;
V_8 -> V_110 [ V_135 ] ++ ;
V_8 -> V_121 [ V_135 ] ++ ;
F_159 ( V_131 ) ;
} else {
V_8 -> V_109 -- ;
V_8 -> V_122 -- ;
F_159 ( V_132 ) ;
}
F_2 ( & V_120 ) ;
return V_68 ;
}
struct V_68 * F_160 ( struct V_7 * V_8 , int V_69 )
{
struct V_68 * V_68 = NULL ;
F_9 ( & V_120 ) ;
if ( V_8 -> V_72 - V_8 -> V_87 > 0 )
V_68 = F_57 ( V_8 , V_69 ) ;
F_2 ( & V_120 ) ;
if ( ! V_68 )
V_68 = F_157 ( V_8 , V_69 ) ;
return V_68 ;
}
static int F_161 ( struct V_7 * V_8 , int V_12 )
{
struct V_25 V_138 ;
struct V_68 * V_68 , * V_139 ;
int V_13 , V_95 ;
int V_140 , V_141 ;
bool V_142 = true ;
V_140 = ( V_8 -> V_87 + V_12 ) - V_8 -> V_72 ;
if ( V_140 <= 0 ) {
V_8 -> V_87 += V_12 ;
return 0 ;
}
V_141 = 0 ;
F_24 ( & V_138 ) ;
V_13 = - V_14 ;
V_37:
F_2 ( & V_120 ) ;
for ( V_95 = 0 ; V_95 < V_140 ; V_95 ++ ) {
V_68 = F_157 ( V_8 , V_137 ) ;
if ( ! V_68 ) {
V_142 = false ;
break;
}
F_25 ( & V_68 -> V_70 , & V_138 ) ;
}
V_141 += V_95 ;
F_9 ( & V_120 ) ;
V_140 = ( V_8 -> V_87 + V_12 ) -
( V_8 -> V_72 + V_141 ) ;
if ( V_140 > 0 ) {
if ( V_142 )
goto V_37;
goto free;
}
V_140 += V_141 ;
V_8 -> V_87 += V_12 ;
V_13 = 0 ;
F_19 (page, tmp, &surplus_list, lru) {
if ( ( -- V_140 ) < 0 )
break;
F_162 ( V_68 ) ;
F_111 ( F_93 ( V_68 ) , V_68 ) ;
F_54 ( V_8 , V_68 ) ;
}
free:
F_2 ( & V_120 ) ;
F_19 (page, tmp, &surplus_list, lru)
F_134 ( V_68 ) ;
F_9 ( & V_120 ) ;
return V_13 ;
}
static void F_163 ( struct V_7 * V_8 ,
unsigned long V_143 )
{
unsigned long V_96 ;
V_8 -> V_87 -= V_143 ;
if ( F_109 ( V_8 ) )
return;
V_96 = F_31 ( V_143 , V_8 -> V_122 ) ;
while ( V_96 -- ) {
if ( ! F_150 ( V_8 , & V_144 [ V_145 ] , 1 ) )
break;
F_164 ( & V_120 ) ;
}
}
static long F_165 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_146 ,
bool V_147 )
{
struct V_21 * V_22 ;
T_1 V_148 ;
long V_13 ;
V_22 = F_47 ( V_19 ) ;
if ( ! V_22 )
return 1 ;
V_148 = F_32 ( V_8 , V_19 , V_146 ) ;
if ( V_147 )
V_13 = F_17 ( V_22 , V_148 , V_148 + 1 ) ;
else
V_13 = F_22 ( V_22 , V_148 , V_148 + 1 ) ;
if ( V_19 -> V_56 & V_57 )
return V_13 ;
else
return V_13 < 0 ? V_13 : 0 ;
}
static long F_166 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_146 )
{
return F_165 ( V_8 , V_19 , V_146 , false ) ;
}
static long F_167 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_146 )
{
return F_165 ( V_8 , V_19 , V_146 , true ) ;
}
static struct V_68 * F_168 ( struct V_18 * V_19 ,
unsigned long V_146 , int V_78 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
struct V_7 * V_8 = F_36 ( V_19 ) ;
struct V_68 * V_68 ;
long V_36 , V_147 ;
int V_13 , V_148 ;
struct V_149 * V_150 ;
V_148 = F_131 ( V_8 ) ;
V_36 = F_166 ( V_8 , V_19 , V_146 ) ;
if ( V_36 < 0 )
return F_169 ( - V_14 ) ;
if ( V_36 || V_78 )
if ( F_11 ( V_2 , 1 ) < 0 )
return F_169 ( - V_151 ) ;
V_13 = F_170 ( V_148 , F_110 ( V_8 ) , & V_150 ) ;
if ( V_13 )
goto V_152;
F_9 ( & V_120 ) ;
V_68 = F_62 ( V_8 , V_19 , V_146 , V_78 , V_36 ) ;
if ( ! V_68 ) {
F_2 ( & V_120 ) ;
V_68 = F_157 ( V_8 , V_137 ) ;
if ( ! V_68 )
goto V_153;
F_9 ( & V_120 ) ;
F_56 ( & V_68 -> V_70 , & V_8 -> V_74 ) ;
}
F_171 ( V_148 , F_110 ( V_8 ) , V_150 , V_68 ) ;
F_2 ( & V_120 ) ;
F_128 ( V_68 , ( unsigned long ) V_2 ) ;
V_147 = F_167 ( V_8 , V_19 , V_146 ) ;
if ( F_70 ( V_36 > V_147 ) ) {
long V_154 ;
V_154 = F_12 ( V_2 , 1 ) ;
F_3 ( V_8 , - V_154 ) ;
}
return V_68 ;
V_153:
F_172 ( V_148 , F_110 ( V_8 ) , V_150 ) ;
V_152:
if ( V_36 || V_78 )
F_12 ( V_2 , 1 ) ;
return F_169 ( - V_151 ) ;
}
struct V_68 * F_173 ( struct V_18 * V_19 ,
unsigned long V_146 , int V_78 )
{
struct V_68 * V_68 = F_168 ( V_19 , V_146 , V_78 ) ;
if ( F_174 ( V_68 ) )
V_68 = NULL ;
return V_68 ;
}
int __weak F_175 ( struct V_7 * V_8 )
{
struct V_155 * V_156 ;
int V_107 , V_108 ;
F_106 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_146 ;
V_146 = F_176 (
F_117 ( V_8 ) , F_117 ( V_8 ) ,
0 , V_157 , V_108 ) ;
if ( V_146 ) {
V_156 = V_146 ;
goto V_158;
}
}
return 0 ;
V_158:
F_10 ( ! F_156 ( F_177 ( V_156 ) , F_117 ( V_8 ) ) ) ;
F_25 ( & V_156 -> V_159 , & V_160 ) ;
V_156 -> V_7 = V_8 ;
return 1 ;
}
static void T_4 F_178 ( struct V_68 * V_68 , int V_94 )
{
if ( F_70 ( V_94 > ( V_126 - 1 ) ) )
F_103 ( V_68 , V_94 ) ;
else
F_179 ( V_68 , V_94 ) ;
}
static void T_4 F_180 ( void )
{
struct V_155 * V_156 ;
F_18 (m, &huge_boot_pages, list) {
struct V_7 * V_8 = V_156 -> V_7 ;
struct V_68 * V_68 ;
#ifdef F_181
V_68 = F_91 ( V_156 -> V_161 >> V_162 ) ;
F_182 ( F_183 ( V_156 ) ,
sizeof( struct V_155 ) ) ;
#else
V_68 = F_184 ( V_156 ) ;
#endif
F_185 ( F_93 ( V_68 ) != 1 ) ;
F_178 ( V_68 , V_8 -> V_94 ) ;
F_185 ( F_92 ( V_68 ) ) ;
F_104 ( V_8 , V_68 , F_55 ( V_68 ) ) ;
if ( F_109 ( V_8 ) )
F_186 ( V_68 , 1 << V_8 -> V_94 ) ;
}
}
static void T_4 F_187 ( struct V_7 * V_8 )
{
unsigned long V_95 ;
for ( V_95 = 0 ; V_95 < V_8 -> V_163 ; ++ V_95 ) {
if ( F_109 ( V_8 ) ) {
if ( ! F_175 ( V_8 ) )
break;
} else if ( ! F_148 ( V_8 ,
& V_144 [ V_145 ] ) )
break;
}
V_8 -> V_163 = V_95 ;
}
static void T_4 F_188 ( void )
{
struct V_7 * V_8 ;
F_116 (h) {
if ( V_134 > F_34 ( V_8 ) )
V_134 = F_34 ( V_8 ) ;
if ( ! F_109 ( V_8 ) )
F_187 ( V_8 ) ;
}
F_21 ( V_134 == V_164 ) ;
}
static char * T_4 F_189 ( char * V_165 , unsigned long V_166 )
{
if ( V_166 >= ( 1UL << 30 ) )
sprintf ( V_165 , L_1 , V_166 >> 30 ) ;
else if ( V_166 >= ( 1UL << 20 ) )
sprintf ( V_165 , L_2 , V_166 >> 20 ) ;
else
sprintf ( V_165 , L_3 , V_166 >> 10 ) ;
return V_165 ;
}
static void T_4 F_190 ( void )
{
struct V_7 * V_8 ;
F_116 (h) {
char V_165 [ 32 ] ;
F_191 ( L_4 ,
F_189 ( V_165 , F_117 ( V_8 ) ) ,
V_8 -> V_72 ) ;
}
}
static void F_192 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_90 )
{
int V_95 ;
if ( F_109 ( V_8 ) )
return;
F_193 (i, *nodes_allowed) {
struct V_68 * V_68 , * V_42 ;
struct V_25 * V_167 = & V_8 -> V_71 [ V_95 ] ;
F_19 (page, next, freel, lru) {
if ( V_3 >= V_8 -> V_109 )
return;
if ( F_194 ( V_68 ) )
continue;
F_20 ( & V_68 -> V_70 ) ;
F_108 ( V_8 , V_68 ) ;
V_8 -> V_72 -- ;
V_8 -> V_73 [ F_55 ( V_68 ) ] -- ;
}
}
}
static inline void F_192 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_90 )
{
}
static int F_195 ( struct V_7 * V_8 , T_3 * V_90 ,
int V_12 )
{
int V_107 , V_108 ;
F_21 ( V_12 != - 1 && V_12 != 1 ) ;
if ( V_12 < 0 ) {
F_106 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_121 [ V_108 ] )
goto V_158;
}
} else {
F_151 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_121 [ V_108 ] <
V_8 -> V_110 [ V_108 ] )
goto V_158;
}
}
return 0 ;
V_158:
V_8 -> V_122 += V_12 ;
V_8 -> V_121 [ V_108 ] += V_12 ;
return 1 ;
}
static unsigned long F_196 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_90 )
{
unsigned long V_168 , V_13 ;
if ( F_109 ( V_8 ) && ! F_107 () )
return V_8 -> V_163 ;
F_9 ( & V_120 ) ;
while ( V_8 -> V_122 && V_3 > F_197 ( V_8 ) ) {
if ( ! F_195 ( V_8 , V_90 , - 1 ) )
break;
}
while ( V_3 > F_197 ( V_8 ) ) {
F_2 ( & V_120 ) ;
if ( F_109 ( V_8 ) )
V_13 = F_105 ( V_8 , V_90 ) ;
else
V_13 = F_148 ( V_8 , V_90 ) ;
F_9 ( & V_120 ) ;
if ( ! V_13 )
goto V_40;
if ( F_198 ( V_169 ) )
goto V_40;
}
V_168 = V_8 -> V_87 + V_8 -> V_109 - V_8 -> V_72 ;
V_168 = F_30 ( V_3 , V_168 ) ;
F_192 ( V_8 , V_168 , V_90 ) ;
while ( V_168 < F_197 ( V_8 ) ) {
if ( ! F_150 ( V_8 , V_90 , 0 ) )
break;
F_164 ( & V_120 ) ;
}
while ( V_3 < F_197 ( V_8 ) ) {
if ( ! F_195 ( V_8 , V_90 , 1 ) )
break;
}
V_40:
V_13 = F_197 ( V_8 ) ;
F_2 ( & V_120 ) ;
return V_13 ;
}
static struct V_7 * F_199 ( struct V_170 * V_171 , int * V_172 )
{
int V_95 ;
for ( V_95 = 0 ; V_95 < V_173 ; V_95 ++ )
if ( V_174 [ V_95 ] == V_171 ) {
if ( V_172 )
* V_172 = V_137 ;
return & V_175 [ V_95 ] ;
}
return F_200 ( V_171 , V_172 ) ;
}
static T_5 F_201 ( struct V_170 * V_171 ,
struct V_176 * V_177 , char * V_165 )
{
struct V_7 * V_8 ;
unsigned long V_109 ;
int V_69 ;
V_8 = F_199 ( V_171 , & V_69 ) ;
if ( V_69 == V_137 )
V_109 = V_8 -> V_109 ;
else
V_109 = V_8 -> V_110 [ V_69 ] ;
return sprintf ( V_165 , L_5 , V_109 ) ;
}
static T_5 F_202 ( bool V_178 ,
struct V_7 * V_8 , int V_69 ,
unsigned long V_3 , T_6 V_179 )
{
int V_88 ;
F_203 ( T_3 , V_90 , V_10 | V_180 ) ;
if ( F_109 ( V_8 ) && ! F_107 () ) {
V_88 = - V_181 ;
goto V_40;
}
if ( V_69 == V_137 ) {
if ( ! ( V_178 &&
F_204 ( V_90 ) ) ) {
F_205 ( V_90 ) ;
V_90 = & V_144 [ V_145 ] ;
}
} else if ( V_90 ) {
V_3 += V_8 -> V_109 - V_8 -> V_110 [ V_69 ] ;
F_206 ( V_90 , V_69 ) ;
} else
V_90 = & V_144 [ V_145 ] ;
V_8 -> V_163 = F_196 ( V_8 , V_3 , V_90 ) ;
if ( V_90 != & V_144 [ V_145 ] )
F_205 ( V_90 ) ;
return V_179 ;
V_40:
F_205 ( V_90 ) ;
return V_88 ;
}
static T_5 F_207 ( bool V_178 ,
struct V_170 * V_171 , const char * V_165 ,
T_6 V_179 )
{
struct V_7 * V_8 ;
unsigned long V_3 ;
int V_69 ;
int V_88 ;
V_88 = F_208 ( V_165 , 10 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_8 = F_199 ( V_171 , & V_69 ) ;
return F_202 ( V_178 , V_8 , V_69 , V_3 , V_179 ) ;
}
static T_5 F_209 ( struct V_170 * V_171 ,
struct V_176 * V_177 , char * V_165 )
{
return F_201 ( V_171 , V_177 , V_165 ) ;
}
static T_5 F_210 ( struct V_170 * V_171 ,
struct V_176 * V_177 , const char * V_165 , T_6 V_179 )
{
return F_207 ( false , V_171 , V_165 , V_179 ) ;
}
static T_5 F_211 ( struct V_170 * V_171 ,
struct V_176 * V_177 , char * V_165 )
{
return F_201 ( V_171 , V_177 , V_165 ) ;
}
static T_5 F_212 ( struct V_170 * V_171 ,
struct V_176 * V_177 , const char * V_165 , T_6 V_179 )
{
return F_207 ( true , V_171 , V_165 , V_179 ) ;
}
static T_5 F_213 ( struct V_170 * V_171 ,
struct V_176 * V_177 , char * V_165 )
{
struct V_7 * V_8 = F_199 ( V_171 , NULL ) ;
return sprintf ( V_165 , L_5 , V_8 -> V_136 ) ;
}
static T_5 F_214 ( struct V_170 * V_171 ,
struct V_176 * V_177 , const char * V_165 , T_6 V_3 )
{
int V_88 ;
unsigned long V_182 ;
struct V_7 * V_8 = F_199 ( V_171 , NULL ) ;
if ( F_109 ( V_8 ) )
return - V_181 ;
V_88 = F_208 ( V_165 , 10 , & V_182 ) ;
if ( V_88 )
return V_88 ;
F_9 ( & V_120 ) ;
V_8 -> V_136 = V_182 ;
F_2 ( & V_120 ) ;
return V_3 ;
}
static T_5 F_215 ( struct V_170 * V_171 ,
struct V_176 * V_177 , char * V_165 )
{
struct V_7 * V_8 ;
unsigned long V_72 ;
int V_69 ;
V_8 = F_199 ( V_171 , & V_69 ) ;
if ( V_69 == V_137 )
V_72 = V_8 -> V_72 ;
else
V_72 = V_8 -> V_73 [ V_69 ] ;
return sprintf ( V_165 , L_5 , V_72 ) ;
}
static T_5 F_216 ( struct V_170 * V_171 ,
struct V_176 * V_177 , char * V_165 )
{
struct V_7 * V_8 = F_199 ( V_171 , NULL ) ;
return sprintf ( V_165 , L_5 , V_8 -> V_87 ) ;
}
static T_5 F_217 ( struct V_170 * V_171 ,
struct V_176 * V_177 , char * V_165 )
{
struct V_7 * V_8 ;
unsigned long V_122 ;
int V_69 ;
V_8 = F_199 ( V_171 , & V_69 ) ;
if ( V_69 == V_137 )
V_122 = V_8 -> V_122 ;
else
V_122 = V_8 -> V_121 [ V_69 ] ;
return sprintf ( V_165 , L_5 , V_122 ) ;
}
static int F_218 ( struct V_7 * V_8 , struct V_170 * V_183 ,
struct V_170 * * V_174 ,
struct V_184 * V_185 )
{
int V_186 ;
int V_187 = F_131 ( V_8 ) ;
V_174 [ V_187 ] = F_219 ( V_8 -> V_188 , V_183 ) ;
if ( ! V_174 [ V_187 ] )
return - V_14 ;
V_186 = F_220 ( V_174 [ V_187 ] , V_185 ) ;
if ( V_186 )
F_221 ( V_174 [ V_187 ] ) ;
return V_186 ;
}
static void T_4 F_222 ( void )
{
struct V_7 * V_8 ;
int V_88 ;
V_189 = F_219 ( L_6 , V_190 ) ;
if ( ! V_189 )
return;
F_116 (h) {
V_88 = F_218 ( V_8 , V_189 ,
V_174 , & V_185 ) ;
if ( V_88 )
F_223 ( L_7 , V_8 -> V_188 ) ;
}
}
static struct V_7 * F_200 ( struct V_170 * V_171 , int * V_172 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_191 ; V_69 ++ ) {
struct V_192 * V_193 = & V_194 [ V_69 ] ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_173 ; V_95 ++ )
if ( V_193 -> V_174 [ V_95 ] == V_171 ) {
if ( V_172 )
* V_172 = V_69 ;
return & V_175 [ V_95 ] ;
}
}
F_224 () ;
return NULL ;
}
static void F_225 ( struct V_108 * V_108 )
{
struct V_7 * V_8 ;
struct V_192 * V_193 = & V_194 [ V_108 -> V_195 . V_196 ] ;
if ( ! V_193 -> V_189 )
return;
F_116 (h) {
int V_148 = F_131 ( V_8 ) ;
if ( V_193 -> V_174 [ V_148 ] ) {
F_221 ( V_193 -> V_174 [ V_148 ] ) ;
V_193 -> V_174 [ V_148 ] = NULL ;
}
}
F_221 ( V_193 -> V_189 ) ;
V_193 -> V_189 = NULL ;
}
static void F_226 ( void )
{
int V_69 ;
F_227 ( NULL , NULL ) ;
for ( V_69 = 0 ; V_69 < V_191 ; V_69 ++ )
F_225 ( V_197 [ V_69 ] ) ;
}
static void F_228 ( struct V_108 * V_108 )
{
struct V_7 * V_8 ;
struct V_192 * V_193 = & V_194 [ V_108 -> V_195 . V_196 ] ;
int V_88 ;
if ( V_193 -> V_189 )
return;
V_193 -> V_189 = F_219 ( L_6 ,
& V_108 -> V_195 . V_171 ) ;
if ( ! V_193 -> V_189 )
return;
F_116 (h) {
V_88 = F_218 ( V_8 , V_193 -> V_189 ,
V_193 -> V_174 ,
& V_198 ) ;
if ( V_88 ) {
F_223 ( L_8 ,
V_8 -> V_188 , V_108 -> V_195 . V_196 ) ;
F_225 ( V_108 ) ;
break;
}
}
}
static void T_4 F_229 ( void )
{
int V_69 ;
F_230 (nid, N_MEMORY) {
struct V_108 * V_108 = V_197 [ V_69 ] ;
if ( V_108 -> V_195 . V_196 == V_69 )
F_228 ( V_108 ) ;
}
F_227 ( F_228 ,
F_225 ) ;
}
static struct V_7 * F_200 ( struct V_170 * V_171 , int * V_172 )
{
F_224 () ;
if ( V_172 )
* V_172 = - 1 ;
return NULL ;
}
static void F_226 ( void ) { }
static void F_229 ( void ) { }
static void T_7 F_231 ( void )
{
struct V_7 * V_8 ;
F_226 () ;
F_116 (h) {
F_221 ( V_174 [ F_131 ( V_8 ) ] ) ;
}
F_221 ( V_189 ) ;
F_4 ( V_199 ) ;
}
static int T_4 F_232 ( void )
{
int V_95 ;
if ( ! F_155 () )
return 0 ;
if ( ! F_115 ( V_200 ) ) {
V_200 = V_201 ;
if ( ! F_115 ( V_200 ) )
F_233 ( V_202 ) ;
}
V_203 = F_131 ( F_115 ( V_200 ) ) ;
if ( V_204 )
V_205 . V_163 = V_204 ;
F_188 () ;
F_180 () ;
F_190 () ;
F_222 () ;
F_229 () ;
F_234 () ;
#ifdef F_235
V_206 = F_236 ( 8 * F_237 () ) ;
#else
V_206 = 1 ;
#endif
V_199 =
F_23 ( sizeof( struct V_207 ) * V_206 , V_10 ) ;
F_10 ( ! V_199 ) ;
for ( V_95 = 0 ; V_95 < V_206 ; V_95 ++ )
F_238 ( & V_199 [ V_95 ] ) ;
return 0 ;
}
void T_4 F_233 ( unsigned V_94 )
{
struct V_7 * V_8 ;
unsigned long V_95 ;
if ( F_115 ( V_48 << V_94 ) ) {
F_239 ( L_9 ) ;
return;
}
F_10 ( V_208 >= V_173 ) ;
F_10 ( V_94 == 0 ) ;
V_8 = & V_175 [ V_208 ++ ] ;
V_8 -> V_94 = V_94 ;
V_8 -> V_209 = ~ ( ( 1ULL << ( V_94 + V_162 ) ) - 1 ) ;
V_8 -> V_109 = 0 ;
V_8 -> V_72 = 0 ;
for ( V_95 = 0 ; V_95 < V_91 ; ++ V_95 )
F_24 ( & V_8 -> V_71 [ V_95 ] ) ;
F_24 ( & V_8 -> V_74 ) ;
V_8 -> V_92 = F_74 ( V_144 [ V_145 ] ) ;
V_8 -> V_93 = F_74 ( V_144 [ V_145 ] ) ;
snprintf ( V_8 -> V_188 , V_210 , L_10 ,
F_117 ( V_8 ) / 1024 ) ;
V_211 = V_8 ;
}
static int T_4 F_240 ( char * V_212 )
{
unsigned long * V_213 ;
static unsigned long * V_214 ;
if ( ! V_208 )
V_213 = & V_204 ;
else
V_213 = & V_211 -> V_163 ;
if ( V_213 == V_214 ) {
F_239 ( L_11
L_12 ) ;
return 1 ;
}
if ( sscanf ( V_212 , L_13 , V_213 ) <= 0 )
* V_213 = 0 ;
if ( V_208 && V_211 -> V_94 >= V_126 )
F_187 ( V_211 ) ;
V_214 = V_213 ;
return 1 ;
}
static int T_4 F_241 ( char * V_212 )
{
V_200 = F_242 ( V_212 , & V_212 ) ;
return 1 ;
}
static unsigned int F_243 ( unsigned int * V_215 )
{
int V_108 ;
unsigned int V_216 = 0 ;
F_193 (node, cpuset_current_mems_allowed)
V_216 += V_215 [ V_108 ] ;
return V_216 ;
}
static int F_244 ( bool V_178 ,
struct V_217 * V_218 , int V_219 ,
void T_8 * V_220 , T_6 * V_221 , T_9 * V_222 )
{
struct V_7 * V_8 = & V_205 ;
unsigned long V_139 = V_8 -> V_163 ;
int V_13 ;
if ( ! F_155 () )
return - V_223 ;
V_218 -> V_224 = & V_139 ;
V_218 -> V_225 = sizeof( unsigned long ) ;
V_13 = F_245 ( V_218 , V_219 , V_220 , V_221 , V_222 ) ;
if ( V_13 )
goto V_40;
if ( V_219 )
V_13 = F_202 ( V_178 , V_8 ,
V_137 , V_139 , * V_221 ) ;
V_40:
return V_13 ;
}
int F_246 ( struct V_217 * V_218 , int V_219 ,
void T_8 * V_220 , T_6 * V_221 , T_9 * V_222 )
{
return F_244 ( false , V_218 , V_219 ,
V_220 , V_221 , V_222 ) ;
}
int F_247 ( struct V_217 * V_218 , int V_219 ,
void T_8 * V_220 , T_6 * V_221 , T_9 * V_222 )
{
return F_244 ( true , V_218 , V_219 ,
V_220 , V_221 , V_222 ) ;
}
int F_248 ( struct V_217 * V_218 , int V_219 ,
void T_8 * V_220 ,
T_6 * V_221 , T_9 * V_222 )
{
struct V_7 * V_8 = & V_205 ;
unsigned long V_139 ;
int V_13 ;
if ( ! F_155 () )
return - V_223 ;
V_139 = V_8 -> V_136 ;
if ( V_219 && F_109 ( V_8 ) )
return - V_181 ;
V_218 -> V_224 = & V_139 ;
V_218 -> V_225 = sizeof( unsigned long ) ;
V_13 = F_245 ( V_218 , V_219 , V_220 , V_221 , V_222 ) ;
if ( V_13 )
goto V_40;
if ( V_219 ) {
F_9 ( & V_120 ) ;
V_8 -> V_136 = V_139 ;
F_2 ( & V_120 ) ;
}
V_40:
return V_13 ;
}
void F_249 ( struct V_226 * V_156 )
{
struct V_7 * V_8 = & V_205 ;
if ( ! F_155 () )
return;
F_250 ( V_156 ,
L_14
L_15
L_16
L_17
L_18 ,
V_8 -> V_109 ,
V_8 -> V_72 ,
V_8 -> V_87 ,
V_8 -> V_122 ,
1UL << ( F_34 ( V_8 ) + V_162 - 10 ) ) ;
}
int F_251 ( int V_69 , char * V_165 )
{
struct V_7 * V_8 = & V_205 ;
if ( ! F_155 () )
return 0 ;
return sprintf ( V_165 ,
L_19
L_20
L_21 ,
V_69 , V_8 -> V_110 [ V_69 ] ,
V_69 , V_8 -> V_73 [ V_69 ] ,
V_69 , V_8 -> V_121 [ V_69 ] ) ;
}
void F_252 ( void )
{
struct V_7 * V_8 ;
int V_69 ;
if ( ! F_155 () )
return;
F_230 (nid, N_MEMORY)
F_116 (h)
F_191 ( L_22 ,
V_69 ,
V_8 -> V_110 [ V_69 ] ,
V_8 -> V_73 [ V_69 ] ,
V_8 -> V_121 [ V_69 ] ,
1UL << ( F_34 ( V_8 ) + V_162 - 10 ) ) ;
}
unsigned long F_253 ( void )
{
struct V_7 * V_8 ;
unsigned long V_227 = 0 ;
F_116 (h)
V_227 += V_8 -> V_109 * F_110 ( V_8 ) ;
return V_227 ;
}
static int F_3 ( struct V_7 * V_8 , long V_12 )
{
int V_13 = - V_14 ;
F_9 ( & V_120 ) ;
if ( V_12 > 0 ) {
if ( F_161 ( V_8 , V_12 ) < 0 )
goto V_40;
if ( V_12 > F_243 ( V_8 -> V_73 ) ) {
F_163 ( V_8 , V_12 ) ;
goto V_40;
}
}
V_13 = 0 ;
if ( V_12 < 0 )
F_163 ( V_8 , ( unsigned long ) - V_12 ) ;
V_40:
F_2 ( & V_120 ) ;
return V_13 ;
}
static void F_254 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_47 ( V_19 ) ;
if ( V_22 && F_51 ( V_19 , V_67 ) )
F_255 ( & V_22 -> V_51 ) ;
}
static void F_256 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = F_36 ( V_19 ) ;
struct V_21 * V_22 = F_47 ( V_19 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
unsigned long V_228 , V_229 , V_41 ;
long V_230 ;
if ( ! V_22 || ! F_51 ( V_19 , V_67 ) )
return;
V_229 = F_32 ( V_8 , V_19 , V_19 -> V_46 ) ;
V_41 = F_32 ( V_8 , V_19 , V_19 -> V_231 ) ;
V_228 = ( V_41 - V_229 ) - F_29 ( V_22 , V_229 , V_41 ) ;
F_257 ( & V_22 -> V_51 , F_44 ) ;
if ( V_228 ) {
V_230 = F_12 ( V_2 , V_228 ) ;
F_3 ( V_8 , - V_230 ) ;
}
}
static int F_258 ( struct V_18 * V_19 , struct V_232 * V_233 )
{
F_224 () ;
return 0 ;
}
static T_10 F_259 ( struct V_18 * V_19 , struct V_68 * V_68 ,
int V_234 )
{
T_10 V_235 ;
if ( V_234 ) {
V_235 = F_260 ( F_261 ( F_262 ( V_68 ,
V_19 -> V_236 ) ) ) ;
} else {
V_235 = F_263 ( F_262 ( V_68 ,
V_19 -> V_236 ) ) ;
}
V_235 = F_264 ( V_235 ) ;
V_235 = F_265 ( V_235 ) ;
V_235 = F_266 ( V_235 , V_19 , V_68 , V_234 ) ;
return V_235 ;
}
static void F_267 ( struct V_18 * V_19 ,
unsigned long V_45 , T_10 * V_237 )
{
T_10 V_235 ;
V_235 = F_260 ( F_261 ( F_268 ( V_237 ) ) ) ;
if ( F_269 ( V_19 , V_45 , V_237 , V_235 , 1 ) )
F_270 ( V_19 , V_45 , V_237 ) ;
}
static int F_271 ( T_10 V_238 )
{
T_11 V_239 ;
if ( F_272 ( V_238 ) || F_273 ( V_238 ) )
return 0 ;
V_239 = F_274 ( V_238 ) ;
if ( F_275 ( V_239 ) && F_276 ( V_239 ) )
return 1 ;
else
return 0 ;
}
static int F_277 ( T_10 V_238 )
{
T_11 V_239 ;
if ( F_272 ( V_238 ) || F_273 ( V_238 ) )
return 0 ;
V_239 = F_274 ( V_238 ) ;
if ( F_275 ( V_239 ) && F_278 ( V_239 ) )
return 1 ;
else
return 0 ;
}
int F_279 ( struct V_240 * V_241 , struct V_240 * V_242 ,
struct V_18 * V_19 )
{
T_10 * V_243 , * V_244 , V_235 ;
struct V_68 * V_245 ;
unsigned long V_146 ;
int V_246 ;
struct V_7 * V_8 = F_36 ( V_19 ) ;
unsigned long V_247 = F_117 ( V_8 ) ;
unsigned long V_248 ;
unsigned long V_249 ;
int V_13 = 0 ;
V_246 = ( V_19 -> V_56 & ( V_250 | V_251 ) ) == V_251 ;
V_248 = V_19 -> V_46 ;
V_249 = V_19 -> V_231 ;
if ( V_246 )
F_280 ( V_242 , V_248 , V_249 ) ;
for ( V_146 = V_19 -> V_46 ; V_146 < V_19 -> V_231 ; V_146 += V_247 ) {
T_12 * V_252 , * V_253 ;
V_243 = F_281 ( V_242 , V_146 ) ;
if ( ! V_243 )
continue;
V_244 = F_282 ( V_241 , V_146 , V_247 ) ;
if ( ! V_244 ) {
V_13 = - V_14 ;
break;
}
if ( V_244 == V_243 )
continue;
V_253 = F_283 ( V_8 , V_241 , V_244 ) ;
V_252 = F_284 ( V_8 , V_242 , V_243 ) ;
F_285 ( V_252 , V_254 ) ;
V_235 = F_268 ( V_243 ) ;
if ( F_272 ( V_235 ) ) {
;
} else if ( F_70 ( F_271 ( V_235 ) ||
F_277 ( V_235 ) ) ) {
T_11 V_255 = F_274 ( V_235 ) ;
if ( F_286 ( V_255 ) && V_246 ) {
F_287 ( & V_255 ) ;
V_235 = F_288 ( V_255 ) ;
F_289 ( V_242 , V_146 , V_243 , V_235 ) ;
}
F_289 ( V_241 , V_146 , V_244 , V_235 ) ;
} else {
if ( V_246 ) {
F_290 ( V_242 , V_146 , V_243 ) ;
F_291 ( V_242 , V_248 ,
V_249 ) ;
}
V_235 = F_268 ( V_243 ) ;
V_245 = F_292 ( V_235 ) ;
F_293 ( V_245 ) ;
F_294 ( V_245 ) ;
F_289 ( V_241 , V_146 , V_244 , V_235 ) ;
}
F_2 ( V_252 ) ;
F_2 ( V_253 ) ;
}
if ( V_246 )
F_295 ( V_242 , V_248 , V_249 ) ;
return V_13 ;
}
void F_296 ( struct V_256 * V_257 , struct V_18 * V_19 ,
unsigned long V_229 , unsigned long V_41 ,
struct V_68 * V_258 )
{
int V_259 = 0 ;
struct V_240 * V_260 = V_19 -> V_261 ;
unsigned long V_45 ;
T_10 * V_237 ;
T_10 V_238 ;
T_12 * V_262 ;
struct V_68 * V_68 ;
struct V_7 * V_8 = F_36 ( V_19 ) ;
unsigned long V_247 = F_117 ( V_8 ) ;
const unsigned long V_248 = V_229 ;
const unsigned long V_249 = V_41 ;
F_185 ( ! F_38 ( V_19 ) ) ;
F_10 ( V_229 & ~ F_297 ( V_8 ) ) ;
F_10 ( V_41 & ~ F_297 ( V_8 ) ) ;
F_298 ( V_257 , V_19 ) ;
F_280 ( V_260 , V_248 , V_249 ) ;
V_45 = V_229 ;
V_263:
for (; V_45 < V_41 ; V_45 += V_247 ) {
V_237 = F_281 ( V_260 , V_45 ) ;
if ( ! V_237 )
continue;
V_262 = F_283 ( V_8 , V_260 , V_237 ) ;
if ( F_299 ( V_260 , & V_45 , V_237 ) )
goto V_264;
V_238 = F_268 ( V_237 ) ;
if ( F_272 ( V_238 ) )
goto V_264;
if ( F_70 ( ! F_273 ( V_238 ) ) ) {
F_300 ( V_260 , V_45 , V_237 ) ;
goto V_264;
}
V_68 = F_292 ( V_238 ) ;
if ( V_258 ) {
if ( V_68 != V_258 )
goto V_264;
F_50 ( V_19 , V_265 ) ;
}
V_238 = F_301 ( V_260 , V_45 , V_237 ) ;
F_302 ( V_257 , V_237 , V_45 ) ;
if ( F_303 ( V_238 ) )
F_304 ( V_68 ) ;
F_305 ( V_68 ) ;
V_259 = ! F_306 ( V_257 , V_68 ) ;
if ( V_259 ) {
V_45 += V_247 ;
F_2 ( V_262 ) ;
break;
}
if ( V_258 ) {
F_2 ( V_262 ) ;
break;
}
V_264:
F_2 ( V_262 ) ;
}
if ( V_259 ) {
V_259 = 0 ;
F_307 ( V_257 ) ;
if ( V_45 < V_41 && ! V_258 )
goto V_263;
}
F_295 ( V_260 , V_248 , V_249 ) ;
F_308 ( V_257 , V_19 ) ;
}
void F_309 ( struct V_256 * V_257 ,
struct V_18 * V_19 , unsigned long V_229 ,
unsigned long V_41 , struct V_68 * V_258 )
{
F_296 ( V_257 , V_19 , V_229 , V_41 , V_258 ) ;
V_19 -> V_56 &= ~ V_57 ;
}
void F_310 ( struct V_18 * V_19 , unsigned long V_229 ,
unsigned long V_41 , struct V_68 * V_258 )
{
struct V_240 * V_260 ;
struct V_256 V_257 ;
V_260 = V_19 -> V_261 ;
F_311 ( & V_257 , V_260 , V_229 , V_41 ) ;
F_296 ( & V_257 , V_19 , V_229 , V_41 , V_258 ) ;
F_312 ( & V_257 , V_229 , V_41 ) ;
}
static void F_313 ( struct V_240 * V_260 , struct V_18 * V_19 ,
struct V_68 * V_68 , unsigned long V_45 )
{
struct V_7 * V_8 = F_36 ( V_19 ) ;
struct V_18 * V_266 ;
struct V_58 * V_59 ;
T_1 V_267 ;
V_45 = V_45 & F_297 ( V_8 ) ;
V_267 = ( ( V_45 - V_19 -> V_46 ) >> V_162 ) +
V_19 -> V_47 ;
V_59 = F_16 ( V_19 -> V_20 ) -> V_54 ;
F_314 ( V_59 ) ;
F_315 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_266 == V_19 )
continue;
if ( ! F_51 ( V_266 , V_67 ) )
F_310 ( V_266 , V_45 ,
V_45 + F_117 ( V_8 ) , V_68 ) ;
}
F_316 ( V_59 ) ;
}
static int F_317 ( struct V_240 * V_260 , struct V_18 * V_19 ,
unsigned long V_45 , T_10 * V_237 , T_10 V_238 ,
struct V_68 * V_268 , T_12 * V_262 )
{
struct V_7 * V_8 = F_36 ( V_19 ) ;
struct V_68 * V_269 , * V_270 ;
int V_13 = 0 , V_271 = 0 ;
unsigned long V_248 ;
unsigned long V_249 ;
V_269 = F_292 ( V_238 ) ;
V_272:
if ( F_129 ( V_269 ) == 1 && F_318 ( V_269 ) ) {
F_319 ( V_269 , V_19 , V_45 ) ;
F_267 ( V_19 , V_45 , V_237 ) ;
return 0 ;
}
if ( F_51 ( V_19 , V_67 ) &&
V_269 != V_268 )
V_271 = 1 ;
F_320 ( V_269 ) ;
F_2 ( V_262 ) ;
V_270 = F_168 ( V_19 , V_45 , V_271 ) ;
if ( F_174 ( V_270 ) ) {
if ( V_271 ) {
F_321 ( V_269 ) ;
F_10 ( F_272 ( V_238 ) ) ;
F_313 ( V_260 , V_19 , V_269 , V_45 ) ;
F_10 ( F_272 ( V_238 ) ) ;
F_9 ( V_262 ) ;
V_237 = F_281 ( V_260 , V_45 & F_297 ( V_8 ) ) ;
if ( F_322 ( V_237 &&
F_323 ( F_268 ( V_237 ) , V_238 ) ) )
goto V_272;
return 0 ;
}
V_13 = ( F_324 ( V_270 ) == - V_14 ) ?
V_273 : V_274 ;
goto V_275;
}
if ( F_70 ( F_325 ( V_19 ) ) ) {
V_13 = V_273 ;
goto V_276;
}
F_326 ( V_270 , V_269 , V_45 , V_19 ,
F_110 ( V_8 ) ) ;
F_327 ( V_270 ) ;
F_121 ( V_270 ) ;
V_248 = V_45 & F_297 ( V_8 ) ;
V_249 = V_248 + F_117 ( V_8 ) ;
F_280 ( V_260 , V_248 , V_249 ) ;
F_9 ( V_262 ) ;
V_237 = F_281 ( V_260 , V_45 & F_297 ( V_8 ) ) ;
if ( F_322 ( V_237 && F_323 ( F_268 ( V_237 ) , V_238 ) ) ) {
F_124 ( V_270 ) ;
F_328 ( V_19 , V_45 , V_237 ) ;
F_291 ( V_260 , V_248 , V_249 ) ;
F_289 ( V_260 , V_45 , V_237 ,
F_259 ( V_19 , V_270 , 1 ) ) ;
F_305 ( V_269 ) ;
F_329 ( V_270 , V_19 , V_45 ) ;
V_270 = V_269 ;
}
F_2 ( V_262 ) ;
F_295 ( V_260 , V_248 , V_249 ) ;
V_276:
F_321 ( V_270 ) ;
V_275:
F_321 ( V_269 ) ;
F_9 ( V_262 ) ;
return V_13 ;
}
static struct V_68 * F_330 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_45 )
{
struct V_58 * V_59 ;
T_1 V_148 ;
V_59 = V_19 -> V_20 -> V_60 ;
V_148 = F_32 ( V_8 , V_19 , V_45 ) ;
return F_331 ( V_59 , V_148 ) ;
}
static bool F_332 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_45 )
{
struct V_58 * V_59 ;
T_1 V_148 ;
struct V_68 * V_68 ;
V_59 = V_19 -> V_20 -> V_60 ;
V_148 = F_32 ( V_8 , V_19 , V_45 ) ;
V_68 = F_333 ( V_59 , V_148 ) ;
if ( V_68 )
F_134 ( V_68 ) ;
return V_68 != NULL ;
}
static int F_334 ( struct V_240 * V_260 , struct V_18 * V_19 ,
struct V_58 * V_59 , T_1 V_148 ,
unsigned long V_45 , T_10 * V_237 , unsigned int V_64 )
{
struct V_7 * V_8 = F_36 ( V_19 ) ;
int V_13 = V_274 ;
int V_277 = 0 ;
unsigned long V_118 ;
struct V_68 * V_68 ;
T_10 V_278 ;
T_12 * V_262 ;
if ( F_51 ( V_19 , V_265 ) ) {
F_239 ( L_23 ,
V_169 -> V_279 ) ;
return V_13 ;
}
V_37:
V_68 = F_331 ( V_59 , V_148 ) ;
if ( ! V_68 ) {
V_118 = F_335 ( V_59 -> V_61 ) >> F_33 ( V_8 ) ;
if ( V_148 >= V_118 )
goto V_40;
V_68 = F_168 ( V_19 , V_45 , 0 ) ;
if ( F_174 ( V_68 ) ) {
V_13 = F_324 ( V_68 ) ;
if ( V_13 == - V_14 )
V_13 = V_273 ;
else
V_13 = V_274 ;
goto V_40;
}
F_336 ( V_68 , V_45 , F_110 ( V_8 ) ) ;
F_327 ( V_68 ) ;
F_121 ( V_68 ) ;
if ( V_19 -> V_56 & V_57 ) {
int V_88 ;
struct V_16 * V_16 = V_59 -> V_61 ;
V_88 = F_337 ( V_68 , V_59 , V_148 , V_10 ) ;
if ( V_88 ) {
F_134 ( V_68 ) ;
if ( V_88 == - V_280 )
goto V_37;
goto V_40;
}
F_124 ( V_68 ) ;
F_9 ( & V_16 -> V_281 ) ;
V_16 -> V_282 += F_338 ( V_8 ) ;
F_2 ( & V_16 -> V_281 ) ;
} else {
F_339 ( V_68 ) ;
if ( F_70 ( F_325 ( V_19 ) ) ) {
V_13 = V_273 ;
goto V_283;
}
V_277 = 1 ;
}
} else {
if ( F_70 ( F_340 ( V_68 ) ) ) {
V_13 = V_284 |
F_341 ( F_131 ( V_8 ) ) ;
goto V_283;
}
}
if ( ( V_64 & V_285 ) && ! ( V_19 -> V_56 & V_250 ) )
if ( F_166 ( V_8 , V_19 , V_45 ) < 0 ) {
V_13 = V_273 ;
goto V_283;
}
V_262 = F_284 ( V_8 , V_260 , V_237 ) ;
F_9 ( V_262 ) ;
V_118 = F_335 ( V_59 -> V_61 ) >> F_33 ( V_8 ) ;
if ( V_148 >= V_118 )
goto V_286;
V_13 = 0 ;
if ( ! F_272 ( F_268 ( V_237 ) ) )
goto V_286;
if ( V_277 ) {
F_124 ( V_68 ) ;
F_329 ( V_68 , V_19 , V_45 ) ;
} else
F_294 ( V_68 ) ;
V_278 = F_259 ( V_19 , V_68 , ( ( V_19 -> V_56 & V_287 )
&& ( V_19 -> V_56 & V_250 ) ) ) ;
F_289 ( V_260 , V_45 , V_237 , V_278 ) ;
if ( ( V_64 & V_285 ) && ! ( V_19 -> V_56 & V_250 ) ) {
V_13 = F_317 ( V_260 , V_19 , V_45 , V_237 , V_278 , V_68 , V_262 ) ;
}
F_2 ( V_262 ) ;
F_342 ( V_68 ) ;
V_40:
return V_13 ;
V_286:
F_2 ( V_262 ) ;
V_283:
F_342 ( V_68 ) ;
F_134 ( V_68 ) ;
goto V_40;
}
static T_13 F_343 ( struct V_7 * V_8 , struct V_240 * V_260 ,
struct V_18 * V_19 ,
struct V_58 * V_59 ,
T_1 V_148 , unsigned long V_45 )
{
unsigned long V_288 [ 2 ] ;
T_13 V_289 ;
if ( V_19 -> V_56 & V_250 ) {
V_288 [ 0 ] = ( unsigned long ) V_59 ;
V_288 [ 1 ] = V_148 ;
} else {
V_288 [ 0 ] = ( unsigned long ) V_260 ;
V_288 [ 1 ] = V_45 >> F_33 ( V_8 ) ;
}
V_289 = F_344 ( ( T_13 * ) & V_288 , sizeof( V_288 ) / sizeof( T_13 ) , 0 ) ;
return V_289 & ( V_206 - 1 ) ;
}
static T_13 F_343 ( struct V_7 * V_8 , struct V_240 * V_260 ,
struct V_18 * V_19 ,
struct V_58 * V_59 ,
T_1 V_148 , unsigned long V_45 )
{
return 0 ;
}
int F_345 ( struct V_240 * V_260 , struct V_18 * V_19 ,
unsigned long V_45 , unsigned int V_64 )
{
T_10 * V_237 , V_235 ;
T_12 * V_262 ;
int V_13 ;
T_13 V_289 ;
T_1 V_148 ;
struct V_68 * V_68 = NULL ;
struct V_68 * V_268 = NULL ;
struct V_7 * V_8 = F_36 ( V_19 ) ;
struct V_58 * V_59 ;
int V_290 = 0 ;
V_45 &= F_297 ( V_8 ) ;
V_237 = F_281 ( V_260 , V_45 ) ;
if ( V_237 ) {
V_235 = F_268 ( V_237 ) ;
if ( F_70 ( F_271 ( V_235 ) ) ) {
F_346 ( V_19 , V_260 , V_237 ) ;
return 0 ;
} else if ( F_70 ( F_277 ( V_235 ) ) )
return V_291 |
F_341 ( F_131 ( V_8 ) ) ;
}
V_237 = F_282 ( V_260 , V_45 , F_117 ( V_8 ) ) ;
if ( ! V_237 )
return V_273 ;
V_59 = V_19 -> V_20 -> V_60 ;
V_148 = F_32 ( V_8 , V_19 , V_45 ) ;
V_289 = F_343 ( V_8 , V_260 , V_19 , V_59 , V_148 , V_45 ) ;
F_347 ( & V_199 [ V_289 ] ) ;
V_235 = F_268 ( V_237 ) ;
if ( F_272 ( V_235 ) ) {
V_13 = F_334 ( V_260 , V_19 , V_59 , V_148 , V_45 , V_237 , V_64 ) ;
goto V_292;
}
V_13 = 0 ;
if ( ! F_273 ( V_235 ) )
goto V_292;
if ( ( V_64 & V_285 ) && ! F_348 ( V_235 ) ) {
if ( F_166 ( V_8 , V_19 , V_45 ) < 0 ) {
V_13 = V_273 ;
goto V_292;
}
if ( ! ( V_19 -> V_56 & V_57 ) )
V_268 = F_330 ( V_8 ,
V_19 , V_45 ) ;
}
V_262 = F_283 ( V_8 , V_260 , V_237 ) ;
if ( F_70 ( ! F_323 ( V_235 , F_268 ( V_237 ) ) ) )
goto V_293;
V_68 = F_292 ( V_235 ) ;
if ( V_68 != V_268 )
if ( ! F_349 ( V_68 ) ) {
V_290 = 1 ;
goto V_293;
}
F_293 ( V_68 ) ;
if ( V_64 & V_285 ) {
if ( ! F_348 ( V_235 ) ) {
V_13 = F_317 ( V_260 , V_19 , V_45 , V_237 , V_235 ,
V_268 , V_262 ) ;
goto V_294;
}
V_235 = F_261 ( V_235 ) ;
}
V_235 = F_264 ( V_235 ) ;
if ( F_269 ( V_19 , V_45 , V_237 , V_235 ,
V_64 & V_285 ) )
F_270 ( V_19 , V_45 , V_237 ) ;
V_294:
if ( V_68 != V_268 )
F_342 ( V_68 ) ;
F_134 ( V_68 ) ;
V_293:
F_2 ( V_262 ) ;
if ( V_268 ) {
F_342 ( V_268 ) ;
F_134 ( V_268 ) ;
}
V_292:
F_350 ( & V_199 [ V_289 ] ) ;
if ( V_290 )
F_351 ( V_68 ) ;
return V_13 ;
}
long F_352 ( struct V_240 * V_260 , struct V_18 * V_19 ,
struct V_68 * * V_295 , struct V_18 * * V_296 ,
unsigned long * V_297 , unsigned long * V_96 ,
long V_95 , unsigned int V_64 )
{
unsigned long V_298 ;
unsigned long V_299 = * V_297 ;
unsigned long V_300 = * V_96 ;
struct V_7 * V_8 = F_36 ( V_19 ) ;
while ( V_299 < V_19 -> V_231 && V_300 ) {
T_10 * V_238 ;
T_12 * V_262 = NULL ;
int V_301 ;
struct V_68 * V_68 ;
if ( F_70 ( F_353 ( V_169 ) ) ) {
V_300 = 0 ;
break;
}
V_238 = F_281 ( V_260 , V_299 & F_297 ( V_8 ) ) ;
if ( V_238 )
V_262 = F_283 ( V_8 , V_260 , V_238 ) ;
V_301 = ! V_238 || F_272 ( F_268 ( V_238 ) ) ;
if ( V_301 && ( V_64 & V_302 ) &&
! F_332 ( V_8 , V_19 , V_299 ) ) {
if ( V_238 )
F_2 ( V_262 ) ;
V_300 = 0 ;
break;
}
if ( V_301 || F_354 ( F_268 ( V_238 ) ) ||
( ( V_64 & V_303 ) &&
! F_348 ( F_268 ( V_238 ) ) ) ) {
int V_13 ;
if ( V_238 )
F_2 ( V_262 ) ;
V_13 = F_345 ( V_260 , V_19 , V_299 ,
( V_64 & V_303 ) ? V_285 : 0 ) ;
if ( ! ( V_13 & V_304 ) )
continue;
V_300 = 0 ;
break;
}
V_298 = ( V_299 & ~ F_297 ( V_8 ) ) >> V_162 ;
V_68 = F_292 ( F_268 ( V_238 ) ) ;
V_305:
if ( V_295 ) {
V_295 [ V_95 ] = F_355 ( V_68 , V_298 ) ;
F_356 ( V_295 [ V_95 ] ) ;
}
if ( V_296 )
V_296 [ V_95 ] = V_19 ;
V_299 += V_48 ;
++ V_298 ;
-- V_300 ;
++ V_95 ;
if ( V_299 < V_19 -> V_231 && V_300 &&
V_298 < F_110 ( V_8 ) ) {
goto V_305;
}
F_2 ( V_262 ) ;
}
* V_96 = V_300 ;
* V_297 = V_299 ;
return V_95 ? V_95 : - V_306 ;
}
unsigned long F_357 ( struct V_18 * V_19 ,
unsigned long V_45 , unsigned long V_41 , T_14 V_307 )
{
struct V_240 * V_260 = V_19 -> V_261 ;
unsigned long V_229 = V_45 ;
T_10 * V_237 ;
T_10 V_238 ;
struct V_7 * V_8 = F_36 ( V_19 ) ;
unsigned long V_295 = 0 ;
F_10 ( V_45 >= V_41 ) ;
F_358 ( V_19 , V_45 , V_41 ) ;
F_280 ( V_260 , V_229 , V_41 ) ;
F_314 ( V_19 -> V_20 -> V_60 ) ;
for (; V_45 < V_41 ; V_45 += F_117 ( V_8 ) ) {
T_12 * V_262 ;
V_237 = F_281 ( V_260 , V_45 ) ;
if ( ! V_237 )
continue;
V_262 = F_283 ( V_8 , V_260 , V_237 ) ;
if ( F_299 ( V_260 , & V_45 , V_237 ) ) {
V_295 ++ ;
F_2 ( V_262 ) ;
continue;
}
V_238 = F_268 ( V_237 ) ;
if ( F_70 ( F_277 ( V_238 ) ) ) {
F_2 ( V_262 ) ;
continue;
}
if ( F_70 ( F_271 ( V_238 ) ) ) {
T_11 V_235 = F_274 ( V_238 ) ;
if ( F_286 ( V_235 ) ) {
T_10 V_308 ;
F_287 ( & V_235 ) ;
V_308 = F_288 ( V_235 ) ;
F_289 ( V_260 , V_45 , V_237 , V_308 ) ;
V_295 ++ ;
}
F_2 ( V_262 ) ;
continue;
}
if ( ! F_272 ( V_238 ) ) {
V_238 = F_301 ( V_260 , V_45 , V_237 ) ;
V_238 = F_265 ( F_359 ( V_238 , V_307 ) ) ;
V_238 = F_266 ( V_238 , V_19 , NULL , 0 ) ;
F_289 ( V_260 , V_45 , V_237 , V_238 ) ;
V_295 ++ ;
}
F_2 ( V_262 ) ;
}
F_360 ( V_19 , V_229 , V_41 ) ;
F_291 ( V_260 , V_229 , V_41 ) ;
F_316 ( V_19 -> V_20 -> V_60 ) ;
F_295 ( V_260 , V_229 , V_41 ) ;
return V_295 << V_8 -> V_94 ;
}
int F_361 ( struct V_16 * V_16 ,
long V_34 , long V_33 ,
struct V_18 * V_19 ,
T_15 V_56 )
{
long V_13 , V_36 ;
struct V_7 * V_8 = F_362 ( V_16 ) ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
struct V_21 * V_21 ;
long V_230 ;
if ( V_56 & V_66 )
return 0 ;
if ( ! V_19 || V_19 -> V_56 & V_57 ) {
V_21 = F_46 ( V_16 ) ;
V_36 = F_22 ( V_21 , V_34 , V_33 ) ;
} else {
V_21 = F_42 () ;
if ( ! V_21 )
return - V_14 ;
V_36 = V_33 - V_34 ;
F_49 ( V_19 , V_21 ) ;
F_50 ( V_19 , V_67 ) ;
}
if ( V_36 < 0 ) {
V_13 = V_36 ;
goto V_309;
}
V_230 = F_11 ( V_2 , V_36 ) ;
if ( V_230 < 0 ) {
V_13 = - V_151 ;
goto V_309;
}
V_13 = F_3 ( V_8 , V_230 ) ;
if ( V_13 < 0 ) {
( void ) F_12 ( V_2 , V_36 ) ;
goto V_309;
}
if ( ! V_19 || V_19 -> V_56 & V_57 ) {
long V_32 = F_17 ( V_21 , V_34 , V_33 ) ;
if ( F_70 ( V_36 > V_32 ) ) {
long V_154 ;
V_154 = F_12 ( V_2 ,
V_36 - V_32 ) ;
F_3 ( V_8 , - V_154 ) ;
}
}
return 0 ;
V_309:
if ( V_19 && F_51 ( V_19 , V_67 ) )
F_257 ( & V_21 -> V_51 , F_44 ) ;
return V_13 ;
}
void F_363 ( struct V_16 * V_16 , long V_310 , long V_311 )
{
struct V_7 * V_8 = F_362 ( V_16 ) ;
struct V_21 * V_21 = F_46 ( V_16 ) ;
long V_36 = 0 ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
long V_230 ;
if ( V_21 )
V_36 = F_26 ( V_21 , V_310 ) ;
F_9 ( & V_16 -> V_281 ) ;
V_16 -> V_282 -= ( F_338 ( V_8 ) * V_311 ) ;
F_2 ( & V_16 -> V_281 ) ;
V_230 = F_12 ( V_2 , ( V_36 - V_311 ) ) ;
F_3 ( V_8 , - V_230 ) ;
}
static unsigned long F_364 ( struct V_18 * V_312 ,
struct V_18 * V_19 ,
unsigned long V_146 , T_1 V_148 )
{
unsigned long V_313 = ( ( V_148 - V_312 -> V_47 ) << V_162 ) +
V_312 -> V_46 ;
unsigned long V_314 = V_313 & V_315 ;
unsigned long V_316 = V_314 + V_317 ;
unsigned long V_56 = V_19 -> V_56 & ~ V_318 ;
unsigned long V_319 = V_312 -> V_56 & ~ V_318 ;
if ( F_365 ( V_146 ) != F_365 ( V_313 ) ||
V_56 != V_319 ||
V_314 < V_312 -> V_46 || V_312 -> V_231 < V_316 )
return 0 ;
return V_313 ;
}
static int F_366 ( struct V_18 * V_19 , unsigned long V_146 )
{
unsigned long V_320 = V_146 & V_315 ;
unsigned long V_41 = V_320 + V_317 ;
if ( V_19 -> V_56 & V_57 &&
V_19 -> V_46 <= V_320 && V_41 <= V_19 -> V_231 )
return 1 ;
return 0 ;
}
T_10 * F_367 ( struct V_240 * V_260 , unsigned long V_146 , T_16 * V_321 )
{
struct V_18 * V_19 = F_368 ( V_260 , V_146 ) ;
struct V_58 * V_59 = V_19 -> V_20 -> V_60 ;
T_1 V_148 = ( ( V_146 - V_19 -> V_46 ) >> V_162 ) +
V_19 -> V_47 ;
struct V_18 * V_312 ;
unsigned long V_313 ;
T_10 * V_322 = NULL ;
T_10 * V_238 ;
T_12 * V_262 ;
if ( ! F_366 ( V_19 , V_146 ) )
return ( T_10 * ) F_369 ( V_260 , V_321 , V_146 ) ;
F_314 ( V_59 ) ;
F_315 (svma, &mapping->i_mmap, idx, idx) {
if ( V_312 == V_19 )
continue;
V_313 = F_364 ( V_312 , V_19 , V_146 , V_148 ) ;
if ( V_313 ) {
V_322 = F_281 ( V_312 -> V_261 , V_313 ) ;
if ( V_322 ) {
F_370 ( V_260 ) ;
F_293 ( F_184 ( V_322 ) ) ;
break;
}
}
}
if ( ! V_322 )
goto V_40;
V_262 = F_284 ( F_36 ( V_19 ) , V_260 , V_322 ) ;
F_9 ( V_262 ) ;
if ( F_371 ( * V_321 ) ) {
F_372 ( V_260 , V_321 ,
( V_323 * ) ( ( unsigned long ) V_322 & V_324 ) ) ;
} else {
F_134 ( F_184 ( V_322 ) ) ;
F_370 ( V_260 ) ;
}
F_2 ( V_262 ) ;
V_40:
V_238 = ( T_10 * ) F_369 ( V_260 , V_321 , V_146 ) ;
F_316 ( V_59 ) ;
return V_238 ;
}
int F_299 ( struct V_240 * V_260 , unsigned long * V_146 , T_10 * V_237 )
{
T_17 * V_325 = F_373 ( V_260 , * V_146 ) ;
T_16 * V_321 = F_374 ( V_325 , * V_146 ) ;
F_10 ( F_93 ( F_184 ( V_237 ) ) == 0 ) ;
if ( F_93 ( F_184 ( V_237 ) ) == 1 )
return 0 ;
F_375 ( V_321 ) ;
F_134 ( F_184 ( V_237 ) ) ;
F_376 ( V_260 ) ;
* V_146 = F_100 ( * V_146 , V_201 * V_326 ) - V_201 ;
return 1 ;
}
T_10 * F_367 ( struct V_240 * V_260 , unsigned long V_146 , T_16 * V_321 )
{
return NULL ;
}
int F_299 ( struct V_240 * V_260 , unsigned long * V_146 , T_10 * V_237 )
{
return 0 ;
}
T_10 * F_282 ( struct V_240 * V_260 ,
unsigned long V_146 , unsigned long V_247 )
{
T_17 * V_325 ;
T_16 * V_321 ;
T_10 * V_238 = NULL ;
V_325 = F_373 ( V_260 , V_146 ) ;
V_321 = F_377 ( V_260 , V_325 , V_146 ) ;
if ( V_321 ) {
if ( V_247 == V_317 ) {
V_238 = ( T_10 * ) V_321 ;
} else {
F_10 ( V_247 != V_327 ) ;
if ( F_378 () && F_371 ( * V_321 ) )
V_238 = F_367 ( V_260 , V_146 , V_321 ) ;
else
V_238 = ( T_10 * ) F_369 ( V_260 , V_321 , V_146 ) ;
}
}
F_10 ( V_238 && ! F_379 ( * V_238 ) && ! F_380 ( * V_238 ) ) ;
return V_238 ;
}
T_10 * F_281 ( struct V_240 * V_260 , unsigned long V_146 )
{
T_17 * V_325 ;
T_16 * V_321 ;
V_323 * V_328 = NULL ;
V_325 = F_373 ( V_260 , V_146 ) ;
if ( F_381 ( * V_325 ) ) {
V_321 = F_374 ( V_325 , V_146 ) ;
if ( F_382 ( * V_321 ) ) {
if ( F_383 ( * V_321 ) )
return ( T_10 * ) V_321 ;
V_328 = F_384 ( V_321 , V_146 ) ;
}
}
return ( T_10 * ) V_328 ;
}
struct V_68 * __weak
F_385 ( struct V_240 * V_260 , unsigned long V_45 ,
int V_219 )
{
return F_169 ( - V_181 ) ;
}
struct V_68 * __weak
F_386 ( struct V_240 * V_260 , unsigned long V_45 ,
V_323 * V_328 , int V_64 )
{
struct V_68 * V_68 = NULL ;
T_12 * V_262 ;
V_37:
V_262 = F_387 ( V_260 , V_328 ) ;
F_9 ( V_262 ) ;
if ( ! F_388 ( * V_328 ) )
goto V_40;
if ( F_389 ( * V_328 ) ) {
V_68 = F_390 ( * V_328 ) + ( ( V_45 & ~ V_329 ) >> V_162 ) ;
if ( V_64 & V_330 )
F_293 ( V_68 ) ;
} else {
if ( F_271 ( F_268 ( ( T_10 * ) V_328 ) ) ) {
F_2 ( V_262 ) ;
F_391 ( V_260 , ( T_10 * ) V_328 , V_262 ) ;
goto V_37;
}
}
V_40:
F_2 ( V_262 ) ;
return V_68 ;
}
struct V_68 * __weak
F_392 ( struct V_240 * V_260 , unsigned long V_45 ,
T_16 * V_321 , int V_64 )
{
if ( V_64 & V_330 )
return NULL ;
return F_292 ( * ( T_10 * ) V_321 ) + ( ( V_45 & ~ V_315 ) >> V_162 ) ;
}
int F_393 ( struct V_68 * V_331 )
{
struct V_7 * V_8 = F_126 ( V_331 ) ;
int V_69 = F_55 ( V_331 ) ;
int V_13 = - V_332 ;
F_9 ( & V_120 ) ;
if ( ! F_118 ( V_331 ) && ! F_93 ( V_331 ) ) {
F_394 ( & V_331 -> V_70 ) ;
F_59 ( V_331 ) ;
V_8 -> V_72 -- ;
V_8 -> V_73 [ V_69 ] -- ;
V_13 = 0 ;
}
F_2 ( & V_120 ) ;
return V_13 ;
}
bool F_395 ( struct V_68 * V_68 , struct V_25 * V_159 )
{
bool V_13 = true ;
F_111 ( ! F_119 ( V_68 ) , V_68 ) ;
F_9 ( & V_120 ) ;
if ( ! F_118 ( V_68 ) || ! F_396 ( V_68 ) ) {
V_13 = false ;
goto V_264;
}
F_123 ( V_68 ) ;
F_397 ( & V_68 -> V_70 , V_159 ) ;
V_264:
F_2 ( & V_120 ) ;
return V_13 ;
}
void F_398 ( struct V_68 * V_68 )
{
F_111 ( ! F_119 ( V_68 ) , V_68 ) ;
F_9 ( & V_120 ) ;
F_121 ( V_68 ) ;
F_397 ( & V_68 -> V_70 , & ( F_126 ( V_68 ) ) -> V_74 ) ;
F_2 ( & V_120 ) ;
F_134 ( V_68 ) ;
}
