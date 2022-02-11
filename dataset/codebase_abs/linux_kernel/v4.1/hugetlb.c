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
F_9 ( & V_22 -> V_5 ) ;
F_18 (rg, head, link)
if ( V_23 <= V_29 -> V_32 )
break;
if ( V_23 > V_29 -> V_33 )
V_23 = V_29 -> V_33 ;
V_30 = V_29 ;
F_19 (rg, trg, rg->link.prev, link) {
if ( & V_29 -> V_34 == V_26 )
break;
if ( V_29 -> V_33 > V_24 )
break;
if ( V_29 -> V_32 > V_24 )
V_24 = V_29 -> V_32 ;
if ( V_29 != V_30 ) {
F_20 ( & V_29 -> V_34 ) ;
F_4 ( V_29 ) ;
}
}
V_30 -> V_33 = V_23 ;
V_30 -> V_32 = V_24 ;
F_2 ( & V_22 -> V_5 ) ;
return 0 ;
}
static long F_21 ( struct V_21 * V_22 , long V_23 , long V_24 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_28 * V_29 , * V_30 = NULL ;
long V_35 = 0 ;
V_36:
F_9 ( & V_22 -> V_5 ) ;
F_18 (rg, head, link)
if ( V_23 <= V_29 -> V_32 )
break;
if ( & V_29 -> V_34 == V_26 || V_24 < V_29 -> V_33 ) {
if ( ! V_30 ) {
F_2 ( & V_22 -> V_5 ) ;
V_30 = F_22 ( sizeof( * V_30 ) , V_10 ) ;
if ( ! V_30 )
return - V_14 ;
V_30 -> V_33 = V_23 ;
V_30 -> V_32 = V_23 ;
F_23 ( & V_30 -> V_34 ) ;
goto V_36;
}
F_24 ( & V_30 -> V_34 , V_29 -> V_34 . V_37 ) ;
V_35 = V_24 - V_23 ;
goto V_38;
}
if ( V_23 > V_29 -> V_33 )
V_23 = V_29 -> V_33 ;
V_35 = V_24 - V_23 ;
F_18 (rg, rg->link.prev, link) {
if ( & V_29 -> V_34 == V_26 )
break;
if ( V_29 -> V_33 > V_24 )
goto V_39;
if ( V_29 -> V_32 > V_24 ) {
V_35 += V_29 -> V_32 - V_24 ;
V_24 = V_29 -> V_32 ;
}
V_35 -= V_29 -> V_32 - V_29 -> V_33 ;
}
V_39:
F_2 ( & V_22 -> V_5 ) ;
F_4 ( V_30 ) ;
return V_35 ;
V_38:
F_2 ( & V_22 -> V_5 ) ;
return V_35 ;
}
static long F_25 ( struct V_21 * V_22 , long V_40 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_28 * V_29 , * V_31 ;
long V_35 = 0 ;
F_9 ( & V_22 -> V_5 ) ;
F_18 (rg, head, link)
if ( V_40 <= V_29 -> V_32 )
break;
if ( & V_29 -> V_34 == V_26 )
goto V_39;
if ( V_40 > V_29 -> V_33 ) {
V_35 = V_29 -> V_32 - V_40 ;
V_29 -> V_32 = V_40 ;
V_29 = F_26 ( V_29 -> V_34 . V_41 , F_27 ( * V_29 ) , V_34 ) ;
}
F_19 (rg, trg, rg->link.prev, link) {
if ( & V_29 -> V_34 == V_26 )
break;
V_35 += V_29 -> V_32 - V_29 -> V_33 ;
F_20 ( & V_29 -> V_34 ) ;
F_4 ( V_29 ) ;
}
V_39:
F_2 ( & V_22 -> V_5 ) ;
return V_35 ;
}
static long F_28 ( struct V_21 * V_22 , long V_23 , long V_24 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_28 * V_29 ;
long V_35 = 0 ;
F_9 ( & V_22 -> V_5 ) ;
F_18 (rg, head, link) {
long V_42 ;
long V_43 ;
if ( V_29 -> V_32 <= V_23 )
continue;
if ( V_29 -> V_33 >= V_24 )
break;
V_42 = F_29 ( V_29 -> V_33 , V_23 ) ;
V_43 = F_30 ( V_29 -> V_32 , V_24 ) ;
V_35 += V_43 - V_42 ;
}
F_2 ( & V_22 -> V_5 ) ;
return V_35 ;
}
static T_1 F_31 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_44 )
{
return ( ( V_44 - V_19 -> V_45 ) >> F_32 ( V_8 ) ) +
( V_19 -> V_46 >> F_33 ( V_8 ) ) ;
}
T_1 F_34 ( struct V_18 * V_19 ,
unsigned long V_44 )
{
return F_31 ( F_35 ( V_19 ) , V_19 , V_44 ) ;
}
unsigned long F_36 ( struct V_18 * V_19 )
{
struct V_7 * V_7 ;
if ( ! F_37 ( V_19 ) )
return V_47 ;
V_7 = F_35 ( V_19 ) ;
return 1UL << F_32 ( V_7 ) ;
}
unsigned long F_38 ( struct V_18 * V_19 )
{
return F_36 ( V_19 ) ;
}
static unsigned long F_39 ( struct V_18 * V_19 )
{
return ( unsigned long ) V_19 -> V_48 ;
}
static void F_40 ( struct V_18 * V_19 ,
unsigned long V_49 )
{
V_19 -> V_48 = ( void * ) V_49 ;
}
struct V_21 * F_41 ( void )
{
struct V_21 * V_21 = F_22 ( sizeof( * V_21 ) , V_10 ) ;
if ( ! V_21 )
return NULL ;
F_42 ( & V_21 -> V_50 ) ;
F_7 ( & V_21 -> V_5 ) ;
F_23 ( & V_21 -> V_27 ) ;
return V_21 ;
}
void F_43 ( struct V_51 * V_52 )
{
struct V_21 * V_21 = F_44 ( V_52 , struct V_21 , V_50 ) ;
F_25 ( V_21 , 0 ) ;
F_4 ( V_21 ) ;
}
static inline struct V_21 * F_45 ( struct V_16 * V_16 )
{
return V_16 -> V_53 -> V_54 ;
}
static struct V_21 * F_46 ( struct V_18 * V_19 )
{
F_47 ( ! F_37 ( V_19 ) , V_19 ) ;
if ( V_19 -> V_55 & V_56 ) {
struct V_57 * V_58 = V_19 -> V_20 -> V_59 ;
struct V_16 * V_16 = V_58 -> V_60 ;
return F_45 ( V_16 ) ;
} else {
return (struct V_21 * ) ( F_39 ( V_19 ) &
~ V_61 ) ;
}
}
static void F_48 ( struct V_18 * V_19 , struct V_21 * V_62 )
{
F_47 ( ! F_37 ( V_19 ) , V_19 ) ;
F_47 ( V_19 -> V_55 & V_56 , V_19 ) ;
F_40 ( V_19 , ( F_39 ( V_19 ) &
V_61 ) | ( unsigned long ) V_62 ) ;
}
static void F_49 ( struct V_18 * V_19 , unsigned long V_63 )
{
F_47 ( ! F_37 ( V_19 ) , V_19 ) ;
F_47 ( V_19 -> V_55 & V_56 , V_19 ) ;
F_40 ( V_19 , F_39 ( V_19 ) | V_63 ) ;
}
static int F_50 ( struct V_18 * V_19 , unsigned long V_64 )
{
F_47 ( ! F_37 ( V_19 ) , V_19 ) ;
return ( F_39 ( V_19 ) & V_64 ) != 0 ;
}
void F_51 ( struct V_18 * V_19 )
{
F_47 ( ! F_37 ( V_19 ) , V_19 ) ;
if ( ! ( V_19 -> V_55 & V_56 ) )
V_19 -> V_48 = ( void * ) 0 ;
}
static int F_52 ( struct V_18 * V_19 , long V_35 )
{
if ( V_19 -> V_55 & V_65 ) {
if ( V_19 -> V_55 & V_56 && V_35 == 0 )
return 1 ;
else
return 0 ;
}
if ( V_19 -> V_55 & V_56 )
return 1 ;
if ( F_50 ( V_19 , V_66 ) )
return 1 ;
return 0 ;
}
static void F_53 ( struct V_7 * V_8 , struct V_67 * V_67 )
{
int V_68 = F_54 ( V_67 ) ;
F_55 ( & V_67 -> V_69 , & V_8 -> V_70 [ V_68 ] ) ;
V_8 -> V_71 ++ ;
V_8 -> V_72 [ V_68 ] ++ ;
}
static struct V_67 * F_56 ( struct V_7 * V_8 , int V_68 )
{
struct V_67 * V_67 ;
F_18 (page, &h->hugepage_freelists[nid], lru)
if ( ! F_57 ( V_67 ) )
break;
if ( & V_8 -> V_70 [ V_68 ] == & V_67 -> V_69 )
return NULL ;
F_55 ( & V_67 -> V_69 , & V_8 -> V_73 ) ;
F_58 ( V_67 ) ;
V_8 -> V_71 -- ;
V_8 -> V_72 [ V_68 ] -- ;
return V_67 ;
}
static inline T_2 F_59 ( struct V_7 * V_8 )
{
if ( V_74 || F_60 ( V_8 ) )
return V_75 ;
else
return V_76 ;
}
static struct V_67 * F_61 ( struct V_7 * V_8 ,
struct V_18 * V_19 ,
unsigned long V_44 , int V_77 ,
long V_35 )
{
struct V_67 * V_67 = NULL ;
struct V_78 * V_79 ;
T_3 * V_80 ;
struct V_81 * V_81 ;
struct V_82 * V_82 ;
struct V_83 * V_84 ;
unsigned int V_85 ;
if ( ! F_52 ( V_19 , V_35 ) &&
V_8 -> V_71 - V_8 -> V_86 == 0 )
goto V_87;
if ( V_77 && V_8 -> V_71 - V_8 -> V_86 == 0 )
goto V_87;
V_88:
V_85 = F_62 () ;
V_81 = F_63 ( V_19 , V_44 ,
F_59 ( V_8 ) , & V_79 , & V_80 ) ;
F_64 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_65 ( V_82 , F_59 ( V_8 ) ) ) {
V_67 = F_56 ( V_8 , F_66 ( V_82 ) ) ;
if ( V_67 ) {
if ( V_77 )
break;
if ( ! F_52 ( V_19 , V_35 ) )
break;
F_67 ( V_67 ) ;
V_8 -> V_86 -- ;
break;
}
}
}
F_68 ( V_79 ) ;
if ( F_69 ( ! V_67 && F_70 ( V_85 ) ) )
goto V_88;
return V_67 ;
V_87:
return NULL ;
}
static int F_71 ( int V_68 , T_3 * V_89 )
{
V_68 = F_72 ( V_68 , * V_89 ) ;
if ( V_68 == V_90 )
V_68 = F_73 ( * V_89 ) ;
F_74 ( V_68 >= V_90 ) ;
return V_68 ;
}
static int F_75 ( int V_68 , T_3 * V_89 )
{
if ( ! F_76 ( V_68 , * V_89 ) )
V_68 = F_71 ( V_68 , V_89 ) ;
return V_68 ;
}
static int F_77 ( struct V_7 * V_8 ,
T_3 * V_89 )
{
int V_68 ;
F_74 ( ! V_89 ) ;
V_68 = F_75 ( V_8 -> V_91 , V_89 ) ;
V_8 -> V_91 = F_71 ( V_68 , V_89 ) ;
return V_68 ;
}
static int F_78 ( struct V_7 * V_8 , T_3 * V_89 )
{
int V_68 ;
F_74 ( ! V_89 ) ;
V_68 = F_75 ( V_8 -> V_92 , V_89 ) ;
V_8 -> V_92 = F_71 ( V_68 , V_89 ) ;
return V_68 ;
}
static void F_79 ( struct V_67 * V_67 ,
unsigned long V_93 )
{
int V_94 ;
int V_95 = 1 << V_93 ;
struct V_67 * V_96 = V_67 + 1 ;
for ( V_94 = 1 ; V_94 < V_95 ; V_94 ++ , V_96 = F_80 ( V_96 , V_67 , V_94 ) ) {
F_81 ( V_96 ) ;
F_58 ( V_96 ) ;
V_96 -> V_97 = NULL ;
}
F_82 ( V_67 , 0 ) ;
F_83 ( V_67 ) ;
}
static void F_84 ( struct V_67 * V_67 , unsigned V_93 )
{
F_85 ( F_86 ( V_67 ) , 1 << V_93 ) ;
}
static int F_87 ( unsigned long V_98 ,
unsigned long V_95 )
{
unsigned long V_99 = V_98 + V_95 ;
return F_88 ( V_98 , V_99 , V_100 ) ;
}
static bool F_89 ( unsigned long V_98 ,
unsigned long V_95 )
{
unsigned long V_94 , V_99 = V_98 + V_95 ;
struct V_67 * V_67 ;
for ( V_94 = V_98 ; V_94 < V_99 ; V_94 ++ ) {
if ( ! F_90 ( V_94 ) )
return false ;
V_67 = F_91 ( V_94 ) ;
if ( F_92 ( V_67 ) )
return false ;
if ( F_93 ( V_67 ) > 0 )
return false ;
if ( F_94 ( V_67 ) )
return false ;
}
return true ;
}
static bool F_95 ( const struct V_82 * V_82 ,
unsigned long V_98 , unsigned long V_95 )
{
unsigned long V_101 = V_98 + V_95 - 1 ;
return F_96 ( V_82 , V_101 ) ;
}
static struct V_67 * F_97 ( int V_68 , unsigned V_93 )
{
unsigned long V_95 = 1 << V_93 ;
unsigned long V_13 , V_102 , V_63 ;
struct V_82 * V_84 ;
V_84 = F_98 ( V_68 ) -> V_103 ;
for (; V_84 - F_98 ( V_68 ) -> V_103 < V_104 ; V_84 ++ ) {
F_99 ( & V_84 -> V_5 , V_63 ) ;
V_102 = F_100 ( V_84 -> V_105 , V_95 ) ;
while ( F_95 ( V_84 , V_102 , V_95 ) ) {
if ( F_89 ( V_102 , V_95 ) ) {
F_101 ( & V_84 -> V_5 , V_63 ) ;
V_13 = F_87 ( V_102 , V_95 ) ;
if ( ! V_13 )
return F_91 ( V_102 ) ;
F_99 ( & V_84 -> V_5 , V_63 ) ;
}
V_102 += V_95 ;
}
F_101 ( & V_84 -> V_5 , V_63 ) ;
}
return NULL ;
}
static struct V_67 * F_102 ( struct V_7 * V_8 , int V_68 )
{
struct V_67 * V_67 ;
V_67 = F_97 ( V_68 , F_33 ( V_8 ) ) ;
if ( V_67 ) {
F_103 ( V_67 , F_33 ( V_8 ) ) ;
F_104 ( V_8 , V_67 , V_68 ) ;
}
return V_67 ;
}
static int F_105 ( struct V_7 * V_8 ,
T_3 * V_89 )
{
struct V_67 * V_67 = NULL ;
int V_106 , V_107 ;
F_106 (h, nr_nodes, node, nodes_allowed) {
V_67 = F_102 ( V_8 , V_107 ) ;
if ( V_67 )
return 1 ;
}
return 0 ;
}
static inline bool F_107 ( void ) { return true ; }
static inline bool F_107 ( void ) { return false ; }
static inline void F_84 ( struct V_67 * V_67 , unsigned V_93 ) { }
static inline void F_79 ( struct V_67 * V_67 ,
unsigned long V_93 ) { }
static inline int F_105 ( struct V_7 * V_8 ,
T_3 * V_89 ) { return 0 ; }
static void F_108 ( struct V_7 * V_8 , struct V_67 * V_67 )
{
int V_94 ;
if ( F_109 ( V_8 ) && ! F_107 () )
return;
V_8 -> V_108 -- ;
V_8 -> V_109 [ F_54 ( V_67 ) ] -- ;
for ( V_94 = 0 ; V_94 < F_110 ( V_8 ) ; V_94 ++ ) {
V_67 [ V_94 ] . V_63 &= ~ ( 1 << V_110 | 1 << V_111 |
1 << V_112 | 1 << V_113 |
1 << V_114 | 1 << V_115 |
1 << V_116 ) ;
}
F_111 ( F_112 ( V_67 ) , V_67 ) ;
F_113 ( V_67 , NULL ) ;
F_58 ( V_67 ) ;
if ( F_109 ( V_8 ) ) {
F_79 ( V_67 , F_33 ( V_8 ) ) ;
F_84 ( V_67 , F_33 ( V_8 ) ) ;
} else {
F_114 ( V_67 ) ;
F_115 ( V_67 , F_33 ( V_8 ) ) ;
}
}
struct V_7 * F_116 ( unsigned long V_117 )
{
struct V_7 * V_8 ;
F_117 (h) {
if ( F_118 ( V_8 ) == V_117 )
return V_8 ;
}
return NULL ;
}
bool F_119 ( struct V_67 * V_67 )
{
F_111 ( ! F_94 ( V_67 ) , V_67 ) ;
return F_120 ( V_67 ) && F_121 ( & V_67 [ 1 ] ) ;
}
static void F_122 ( struct V_67 * V_67 )
{
F_111 ( ! F_123 ( V_67 ) , V_67 ) ;
F_67 ( & V_67 [ 1 ] ) ;
}
static void F_124 ( struct V_67 * V_67 )
{
F_111 ( ! F_123 ( V_67 ) , V_67 ) ;
F_125 ( & V_67 [ 1 ] ) ;
}
void F_126 ( struct V_67 * V_67 )
{
struct V_7 * V_8 = F_127 ( V_67 ) ;
int V_68 = F_54 ( V_67 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_128 ( V_67 ) ;
bool V_118 ;
F_129 ( V_67 , 0 ) ;
V_67 -> V_58 = NULL ;
F_10 ( F_93 ( V_67 ) ) ;
F_10 ( F_130 ( V_67 ) ) ;
V_118 = F_121 ( V_67 ) ;
F_125 ( V_67 ) ;
if ( F_12 ( V_2 , 1 ) == 0 )
V_118 = true ;
F_9 ( & V_119 ) ;
F_124 ( V_67 ) ;
F_131 ( F_132 ( V_8 ) ,
F_110 ( V_8 ) , V_67 ) ;
if ( V_118 )
V_8 -> V_86 ++ ;
if ( V_8 -> V_120 [ V_68 ] ) {
F_20 ( & V_67 -> V_69 ) ;
F_108 ( V_8 , V_67 ) ;
V_8 -> V_121 -- ;
V_8 -> V_120 [ V_68 ] -- ;
} else {
F_133 ( V_67 ) ;
F_53 ( V_8 , V_67 ) ;
}
F_2 ( & V_119 ) ;
}
static void F_104 ( struct V_7 * V_8 , struct V_67 * V_67 , int V_68 )
{
F_23 ( & V_67 -> V_69 ) ;
F_113 ( V_67 , F_126 ) ;
F_9 ( & V_119 ) ;
F_134 ( V_67 , NULL ) ;
V_8 -> V_108 ++ ;
V_8 -> V_109 [ V_68 ] ++ ;
F_2 ( & V_119 ) ;
F_135 ( V_67 ) ;
}
static void F_103 ( struct V_67 * V_67 , unsigned long V_93 )
{
int V_94 ;
int V_95 = 1 << V_93 ;
struct V_67 * V_96 = V_67 + 1 ;
F_82 ( V_67 , V_93 ) ;
F_136 ( V_67 ) ;
F_137 ( V_67 ) ;
for ( V_94 = 1 ; V_94 < V_95 ; V_94 ++ , V_96 = F_80 ( V_96 , V_67 , V_94 ) ) {
F_137 ( V_96 ) ;
F_138 ( V_96 , 0 ) ;
V_96 -> V_97 = V_67 ;
F_139 () ;
F_140 ( V_96 ) ;
}
}
int F_94 ( struct V_67 * V_67 )
{
if ( ! F_141 ( V_67 ) )
return 0 ;
V_67 = F_142 ( V_67 ) ;
return F_143 ( V_67 ) == F_126 ;
}
int F_123 ( struct V_67 * V_122 )
{
if ( ! F_120 ( V_122 ) )
return 0 ;
return F_143 ( V_122 ) == F_126 ;
}
T_1 F_144 ( struct V_67 * V_67 )
{
struct V_67 * V_122 = F_142 ( V_67 ) ;
T_1 V_123 = F_145 ( V_122 ) ;
unsigned long V_124 ;
if ( ! F_94 ( V_122 ) )
return F_145 ( V_67 ) ;
if ( F_146 ( V_122 ) >= V_125 )
V_124 = F_86 ( V_67 ) - F_86 ( V_122 ) ;
else
V_124 = V_67 - V_122 ;
return ( V_123 << F_146 ( V_122 ) ) + V_124 ;
}
static struct V_67 * F_147 ( struct V_7 * V_8 , int V_68 )
{
struct V_67 * V_67 ;
V_67 = F_148 ( V_68 ,
F_59 ( V_8 ) | V_126 | V_127 |
V_128 | V_129 ,
F_33 ( V_8 ) ) ;
if ( V_67 ) {
if ( F_149 ( V_67 ) ) {
F_115 ( V_67 , F_33 ( V_8 ) ) ;
return NULL ;
}
F_104 ( V_8 , V_67 , V_68 ) ;
}
return V_67 ;
}
static int F_150 ( struct V_7 * V_8 , T_3 * V_89 )
{
struct V_67 * V_67 ;
int V_106 , V_107 ;
int V_13 = 0 ;
F_106 (h, nr_nodes, node, nodes_allowed) {
V_67 = F_147 ( V_8 , V_107 ) ;
if ( V_67 ) {
V_13 = 1 ;
break;
}
}
if ( V_13 )
F_151 ( V_130 ) ;
else
F_151 ( V_131 ) ;
return V_13 ;
}
static int F_152 ( struct V_7 * V_8 , T_3 * V_89 ,
bool V_132 )
{
int V_106 , V_107 ;
int V_13 = 0 ;
F_153 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_132 || V_8 -> V_120 [ V_107 ] ) &&
! F_154 ( & V_8 -> V_70 [ V_107 ] ) ) {
struct V_67 * V_67 =
F_26 ( V_8 -> V_70 [ V_107 ] . V_41 ,
struct V_67 , V_69 ) ;
F_20 ( & V_67 -> V_69 ) ;
V_8 -> V_71 -- ;
V_8 -> V_72 [ V_107 ] -- ;
if ( V_132 ) {
V_8 -> V_121 -- ;
V_8 -> V_120 [ V_107 ] -- ;
}
F_108 ( V_8 , V_67 ) ;
V_13 = 1 ;
break;
}
}
return V_13 ;
}
static void F_155 ( struct V_67 * V_67 )
{
F_9 ( & V_119 ) ;
if ( F_94 ( V_67 ) && ! F_93 ( V_67 ) ) {
struct V_7 * V_8 = F_127 ( V_67 ) ;
int V_68 = F_54 ( V_67 ) ;
F_20 ( & V_67 -> V_69 ) ;
V_8 -> V_71 -- ;
V_8 -> V_72 [ V_68 ] -- ;
F_108 ( V_8 , V_67 ) ;
}
F_2 ( & V_119 ) ;
}
void F_156 ( unsigned long V_98 , unsigned long V_99 )
{
unsigned int V_93 = 8 * sizeof( void * ) ;
unsigned long V_102 ;
struct V_7 * V_8 ;
if ( ! F_157 () )
return;
F_117 (h)
if ( V_93 > F_33 ( V_8 ) )
V_93 = F_33 ( V_8 ) ;
F_74 ( ! F_158 ( V_98 , 1 << V_93 ) ) ;
for ( V_102 = V_98 ; V_102 < V_99 ; V_102 += 1 << V_93 )
F_155 ( F_91 ( V_102 ) ) ;
}
static struct V_67 * F_159 ( struct V_7 * V_8 , int V_68 )
{
struct V_67 * V_67 ;
unsigned int V_133 ;
if ( F_109 ( V_8 ) )
return NULL ;
F_9 ( & V_119 ) ;
if ( V_8 -> V_121 >= V_8 -> V_134 ) {
F_2 ( & V_119 ) ;
return NULL ;
} else {
V_8 -> V_108 ++ ;
V_8 -> V_121 ++ ;
}
F_2 ( & V_119 ) ;
if ( V_68 == V_135 )
V_67 = F_160 ( F_59 ( V_8 ) | V_126 |
V_128 | V_129 ,
F_33 ( V_8 ) ) ;
else
V_67 = F_148 ( V_68 ,
F_59 ( V_8 ) | V_126 | V_127 |
V_128 | V_129 , F_33 ( V_8 ) ) ;
if ( V_67 && F_149 ( V_67 ) ) {
F_115 ( V_67 , F_33 ( V_8 ) ) ;
V_67 = NULL ;
}
F_9 ( & V_119 ) ;
if ( V_67 ) {
F_23 ( & V_67 -> V_69 ) ;
V_133 = F_54 ( V_67 ) ;
F_113 ( V_67 , F_126 ) ;
F_134 ( V_67 , NULL ) ;
V_8 -> V_109 [ V_133 ] ++ ;
V_8 -> V_120 [ V_133 ] ++ ;
F_161 ( V_130 ) ;
} else {
V_8 -> V_108 -- ;
V_8 -> V_121 -- ;
F_161 ( V_131 ) ;
}
F_2 ( & V_119 ) ;
return V_67 ;
}
struct V_67 * F_162 ( struct V_7 * V_8 , int V_68 )
{
struct V_67 * V_67 = NULL ;
F_9 ( & V_119 ) ;
if ( V_8 -> V_71 - V_8 -> V_86 > 0 )
V_67 = F_56 ( V_8 , V_68 ) ;
F_2 ( & V_119 ) ;
if ( ! V_67 )
V_67 = F_159 ( V_8 , V_68 ) ;
return V_67 ;
}
static int F_163 ( struct V_7 * V_8 , int V_12 )
{
struct V_25 V_136 ;
struct V_67 * V_67 , * V_137 ;
int V_13 , V_94 ;
int V_138 , V_139 ;
bool V_140 = true ;
V_138 = ( V_8 -> V_86 + V_12 ) - V_8 -> V_71 ;
if ( V_138 <= 0 ) {
V_8 -> V_86 += V_12 ;
return 0 ;
}
V_139 = 0 ;
F_23 ( & V_136 ) ;
V_13 = - V_14 ;
V_36:
F_2 ( & V_119 ) ;
for ( V_94 = 0 ; V_94 < V_138 ; V_94 ++ ) {
V_67 = F_159 ( V_8 , V_135 ) ;
if ( ! V_67 ) {
V_140 = false ;
break;
}
F_24 ( & V_67 -> V_69 , & V_136 ) ;
}
V_139 += V_94 ;
F_9 ( & V_119 ) ;
V_138 = ( V_8 -> V_86 + V_12 ) -
( V_8 -> V_71 + V_139 ) ;
if ( V_138 > 0 ) {
if ( V_140 )
goto V_36;
goto free;
}
V_138 += V_139 ;
V_8 -> V_86 += V_12 ;
V_13 = 0 ;
F_19 (page, tmp, &surplus_list, lru) {
if ( ( -- V_138 ) < 0 )
break;
F_164 ( V_67 ) ;
F_111 ( F_93 ( V_67 ) , V_67 ) ;
F_53 ( V_8 , V_67 ) ;
}
free:
F_2 ( & V_119 ) ;
F_19 (page, tmp, &surplus_list, lru)
F_135 ( V_67 ) ;
F_9 ( & V_119 ) ;
return V_13 ;
}
static void F_165 ( struct V_7 * V_8 ,
unsigned long V_141 )
{
unsigned long V_95 ;
V_8 -> V_86 -= V_141 ;
if ( F_109 ( V_8 ) )
return;
V_95 = F_30 ( V_141 , V_8 -> V_121 ) ;
while ( V_95 -- ) {
if ( ! F_152 ( V_8 , & V_142 [ V_143 ] , 1 ) )
break;
F_166 ( & V_119 ) ;
}
}
static long F_167 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_144 )
{
struct V_21 * V_22 ;
T_1 V_145 ;
long V_35 ;
V_22 = F_46 ( V_19 ) ;
if ( ! V_22 )
return 1 ;
V_145 = F_31 ( V_8 , V_19 , V_144 ) ;
V_35 = F_21 ( V_22 , V_145 , V_145 + 1 ) ;
if ( V_19 -> V_55 & V_56 )
return V_35 ;
else
return V_35 < 0 ? V_35 : 0 ;
}
static void F_168 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_144 )
{
struct V_21 * V_22 ;
T_1 V_145 ;
V_22 = F_46 ( V_19 ) ;
if ( ! V_22 )
return;
V_145 = F_31 ( V_8 , V_19 , V_144 ) ;
F_17 ( V_22 , V_145 , V_145 + 1 ) ;
}
static struct V_67 * F_169 ( struct V_18 * V_19 ,
unsigned long V_144 , int V_77 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
struct V_7 * V_8 = F_35 ( V_19 ) ;
struct V_67 * V_67 ;
long V_35 ;
int V_13 , V_145 ;
struct V_146 * V_147 ;
V_145 = F_132 ( V_8 ) ;
V_35 = F_167 ( V_8 , V_19 , V_144 ) ;
if ( V_35 < 0 )
return F_170 ( - V_14 ) ;
if ( V_35 || V_77 )
if ( F_11 ( V_2 , 1 ) < 0 )
return F_170 ( - V_148 ) ;
V_13 = F_171 ( V_145 , F_110 ( V_8 ) , & V_147 ) ;
if ( V_13 )
goto V_149;
F_9 ( & V_119 ) ;
V_67 = F_61 ( V_8 , V_19 , V_144 , V_77 , V_35 ) ;
if ( ! V_67 ) {
F_2 ( & V_119 ) ;
V_67 = F_159 ( V_8 , V_135 ) ;
if ( ! V_67 )
goto V_150;
F_9 ( & V_119 ) ;
F_55 ( & V_67 -> V_69 , & V_8 -> V_73 ) ;
}
F_172 ( V_145 , F_110 ( V_8 ) , V_147 , V_67 ) ;
F_2 ( & V_119 ) ;
F_129 ( V_67 , ( unsigned long ) V_2 ) ;
F_168 ( V_8 , V_19 , V_144 ) ;
return V_67 ;
V_150:
F_173 ( V_145 , F_110 ( V_8 ) , V_147 ) ;
V_149:
if ( V_35 || V_77 )
F_12 ( V_2 , 1 ) ;
return F_170 ( - V_148 ) ;
}
struct V_67 * F_174 ( struct V_18 * V_19 ,
unsigned long V_144 , int V_77 )
{
struct V_67 * V_67 = F_169 ( V_19 , V_144 , V_77 ) ;
if ( F_175 ( V_67 ) )
V_67 = NULL ;
return V_67 ;
}
int __weak F_176 ( struct V_7 * V_8 )
{
struct V_151 * V_152 ;
int V_106 , V_107 ;
F_106 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_144 ;
V_144 = F_177 (
F_118 ( V_8 ) , F_118 ( V_8 ) ,
0 , V_153 , V_107 ) ;
if ( V_144 ) {
V_152 = V_144 ;
goto V_154;
}
}
return 0 ;
V_154:
F_10 ( ! F_158 ( F_178 ( V_152 ) , F_118 ( V_8 ) ) ) ;
F_24 ( & V_152 -> V_155 , & V_156 ) ;
V_152 -> V_7 = V_8 ;
return 1 ;
}
static void T_4 F_179 ( struct V_67 * V_67 , int V_93 )
{
if ( F_69 ( V_93 > ( V_125 - 1 ) ) )
F_103 ( V_67 , V_93 ) ;
else
F_180 ( V_67 , V_93 ) ;
}
static void T_4 F_181 ( void )
{
struct V_151 * V_152 ;
F_18 (m, &huge_boot_pages, list) {
struct V_7 * V_8 = V_152 -> V_7 ;
struct V_67 * V_67 ;
#ifdef F_182
V_67 = F_91 ( V_152 -> V_157 >> V_158 ) ;
F_183 ( F_184 ( V_152 ) ,
sizeof( struct V_151 ) ) ;
#else
V_67 = F_185 ( V_152 ) ;
#endif
F_186 ( F_93 ( V_67 ) != 1 ) ;
F_179 ( V_67 , V_8 -> V_93 ) ;
F_186 ( F_92 ( V_67 ) ) ;
F_104 ( V_8 , V_67 , F_54 ( V_67 ) ) ;
if ( F_109 ( V_8 ) )
F_187 ( V_67 , 1 << V_8 -> V_93 ) ;
}
}
static void T_4 F_188 ( struct V_7 * V_8 )
{
unsigned long V_94 ;
for ( V_94 = 0 ; V_94 < V_8 -> V_159 ; ++ V_94 ) {
if ( F_109 ( V_8 ) ) {
if ( ! F_176 ( V_8 ) )
break;
} else if ( ! F_150 ( V_8 ,
& V_142 [ V_143 ] ) )
break;
}
V_8 -> V_159 = V_94 ;
}
static void T_4 F_189 ( void )
{
struct V_7 * V_8 ;
F_117 (h) {
if ( ! F_109 ( V_8 ) )
F_188 ( V_8 ) ;
}
}
static char * T_4 F_190 ( char * V_160 , unsigned long V_161 )
{
if ( V_161 >= ( 1UL << 30 ) )
sprintf ( V_160 , L_1 , V_161 >> 30 ) ;
else if ( V_161 >= ( 1UL << 20 ) )
sprintf ( V_160 , L_2 , V_161 >> 20 ) ;
else
sprintf ( V_160 , L_3 , V_161 >> 10 ) ;
return V_160 ;
}
static void T_4 F_191 ( void )
{
struct V_7 * V_8 ;
F_117 (h) {
char V_160 [ 32 ] ;
F_192 ( L_4 ,
F_190 ( V_160 , F_118 ( V_8 ) ) ,
V_8 -> V_71 ) ;
}
}
static void F_193 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_89 )
{
int V_94 ;
if ( F_109 ( V_8 ) )
return;
F_194 (i, *nodes_allowed) {
struct V_67 * V_67 , * V_41 ;
struct V_25 * V_162 = & V_8 -> V_70 [ V_94 ] ;
F_19 (page, next, freel, lru) {
if ( V_3 >= V_8 -> V_108 )
return;
if ( F_195 ( V_67 ) )
continue;
F_20 ( & V_67 -> V_69 ) ;
F_108 ( V_8 , V_67 ) ;
V_8 -> V_71 -- ;
V_8 -> V_72 [ F_54 ( V_67 ) ] -- ;
}
}
}
static inline void F_193 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_89 )
{
}
static int F_196 ( struct V_7 * V_8 , T_3 * V_89 ,
int V_12 )
{
int V_106 , V_107 ;
F_74 ( V_12 != - 1 && V_12 != 1 ) ;
if ( V_12 < 0 ) {
F_106 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_120 [ V_107 ] )
goto V_154;
}
} else {
F_153 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_120 [ V_107 ] <
V_8 -> V_109 [ V_107 ] )
goto V_154;
}
}
return 0 ;
V_154:
V_8 -> V_121 += V_12 ;
V_8 -> V_120 [ V_107 ] += V_12 ;
return 1 ;
}
static unsigned long F_197 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_89 )
{
unsigned long V_163 , V_13 ;
if ( F_109 ( V_8 ) && ! F_107 () )
return V_8 -> V_159 ;
F_9 ( & V_119 ) ;
while ( V_8 -> V_121 && V_3 > F_198 ( V_8 ) ) {
if ( ! F_196 ( V_8 , V_89 , - 1 ) )
break;
}
while ( V_3 > F_198 ( V_8 ) ) {
F_2 ( & V_119 ) ;
if ( F_109 ( V_8 ) )
V_13 = F_105 ( V_8 , V_89 ) ;
else
V_13 = F_150 ( V_8 , V_89 ) ;
F_9 ( & V_119 ) ;
if ( ! V_13 )
goto V_39;
if ( F_199 ( V_164 ) )
goto V_39;
}
V_163 = V_8 -> V_86 + V_8 -> V_108 - V_8 -> V_71 ;
V_163 = F_29 ( V_3 , V_163 ) ;
F_193 ( V_8 , V_163 , V_89 ) ;
while ( V_163 < F_198 ( V_8 ) ) {
if ( ! F_152 ( V_8 , V_89 , 0 ) )
break;
F_166 ( & V_119 ) ;
}
while ( V_3 < F_198 ( V_8 ) ) {
if ( ! F_196 ( V_8 , V_89 , 1 ) )
break;
}
V_39:
V_13 = F_198 ( V_8 ) ;
F_2 ( & V_119 ) ;
return V_13 ;
}
static struct V_7 * F_200 ( struct V_165 * V_166 , int * V_167 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < V_168 ; V_94 ++ )
if ( V_169 [ V_94 ] == V_166 ) {
if ( V_167 )
* V_167 = V_135 ;
return & V_170 [ V_94 ] ;
}
return F_201 ( V_166 , V_167 ) ;
}
static T_5 F_202 ( struct V_165 * V_166 ,
struct V_171 * V_172 , char * V_160 )
{
struct V_7 * V_8 ;
unsigned long V_108 ;
int V_68 ;
V_8 = F_200 ( V_166 , & V_68 ) ;
if ( V_68 == V_135 )
V_108 = V_8 -> V_108 ;
else
V_108 = V_8 -> V_109 [ V_68 ] ;
return sprintf ( V_160 , L_5 , V_108 ) ;
}
static T_5 F_203 ( bool V_173 ,
struct V_7 * V_8 , int V_68 ,
unsigned long V_3 , T_6 V_174 )
{
int V_87 ;
F_204 ( T_3 , V_89 , V_10 | V_175 ) ;
if ( F_109 ( V_8 ) && ! F_107 () ) {
V_87 = - V_176 ;
goto V_39;
}
if ( V_68 == V_135 ) {
if ( ! ( V_173 &&
F_205 ( V_89 ) ) ) {
F_206 ( V_89 ) ;
V_89 = & V_142 [ V_143 ] ;
}
} else if ( V_89 ) {
V_3 += V_8 -> V_108 - V_8 -> V_109 [ V_68 ] ;
F_207 ( V_89 , V_68 ) ;
} else
V_89 = & V_142 [ V_143 ] ;
V_8 -> V_159 = F_197 ( V_8 , V_3 , V_89 ) ;
if ( V_89 != & V_142 [ V_143 ] )
F_206 ( V_89 ) ;
return V_174 ;
V_39:
F_206 ( V_89 ) ;
return V_87 ;
}
static T_5 F_208 ( bool V_173 ,
struct V_165 * V_166 , const char * V_160 ,
T_6 V_174 )
{
struct V_7 * V_8 ;
unsigned long V_3 ;
int V_68 ;
int V_87 ;
V_87 = F_209 ( V_160 , 10 , & V_3 ) ;
if ( V_87 )
return V_87 ;
V_8 = F_200 ( V_166 , & V_68 ) ;
return F_203 ( V_173 , V_8 , V_68 , V_3 , V_174 ) ;
}
static T_5 F_210 ( struct V_165 * V_166 ,
struct V_171 * V_172 , char * V_160 )
{
return F_202 ( V_166 , V_172 , V_160 ) ;
}
static T_5 F_211 ( struct V_165 * V_166 ,
struct V_171 * V_172 , const char * V_160 , T_6 V_174 )
{
return F_208 ( false , V_166 , V_160 , V_174 ) ;
}
static T_5 F_212 ( struct V_165 * V_166 ,
struct V_171 * V_172 , char * V_160 )
{
return F_202 ( V_166 , V_172 , V_160 ) ;
}
static T_5 F_213 ( struct V_165 * V_166 ,
struct V_171 * V_172 , const char * V_160 , T_6 V_174 )
{
return F_208 ( true , V_166 , V_160 , V_174 ) ;
}
static T_5 F_214 ( struct V_165 * V_166 ,
struct V_171 * V_172 , char * V_160 )
{
struct V_7 * V_8 = F_200 ( V_166 , NULL ) ;
return sprintf ( V_160 , L_5 , V_8 -> V_134 ) ;
}
static T_5 F_215 ( struct V_165 * V_166 ,
struct V_171 * V_172 , const char * V_160 , T_6 V_3 )
{
int V_87 ;
unsigned long V_177 ;
struct V_7 * V_8 = F_200 ( V_166 , NULL ) ;
if ( F_109 ( V_8 ) )
return - V_176 ;
V_87 = F_209 ( V_160 , 10 , & V_177 ) ;
if ( V_87 )
return V_87 ;
F_9 ( & V_119 ) ;
V_8 -> V_134 = V_177 ;
F_2 ( & V_119 ) ;
return V_3 ;
}
static T_5 F_216 ( struct V_165 * V_166 ,
struct V_171 * V_172 , char * V_160 )
{
struct V_7 * V_8 ;
unsigned long V_71 ;
int V_68 ;
V_8 = F_200 ( V_166 , & V_68 ) ;
if ( V_68 == V_135 )
V_71 = V_8 -> V_71 ;
else
V_71 = V_8 -> V_72 [ V_68 ] ;
return sprintf ( V_160 , L_5 , V_71 ) ;
}
static T_5 F_217 ( struct V_165 * V_166 ,
struct V_171 * V_172 , char * V_160 )
{
struct V_7 * V_8 = F_200 ( V_166 , NULL ) ;
return sprintf ( V_160 , L_5 , V_8 -> V_86 ) ;
}
static T_5 F_218 ( struct V_165 * V_166 ,
struct V_171 * V_172 , char * V_160 )
{
struct V_7 * V_8 ;
unsigned long V_121 ;
int V_68 ;
V_8 = F_200 ( V_166 , & V_68 ) ;
if ( V_68 == V_135 )
V_121 = V_8 -> V_121 ;
else
V_121 = V_8 -> V_120 [ V_68 ] ;
return sprintf ( V_160 , L_5 , V_121 ) ;
}
static int F_219 ( struct V_7 * V_8 , struct V_165 * V_178 ,
struct V_165 * * V_169 ,
struct V_179 * V_180 )
{
int V_181 ;
int V_182 = F_132 ( V_8 ) ;
V_169 [ V_182 ] = F_220 ( V_8 -> V_183 , V_178 ) ;
if ( ! V_169 [ V_182 ] )
return - V_14 ;
V_181 = F_221 ( V_169 [ V_182 ] , V_180 ) ;
if ( V_181 )
F_222 ( V_169 [ V_182 ] ) ;
return V_181 ;
}
static void T_4 F_223 ( void )
{
struct V_7 * V_8 ;
int V_87 ;
V_184 = F_220 ( L_6 , V_185 ) ;
if ( ! V_184 )
return;
F_117 (h) {
V_87 = F_219 ( V_8 , V_184 ,
V_169 , & V_180 ) ;
if ( V_87 )
F_224 ( L_7 , V_8 -> V_183 ) ;
}
}
static struct V_7 * F_201 ( struct V_165 * V_166 , int * V_167 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_186 ; V_68 ++ ) {
struct V_187 * V_188 = & V_189 [ V_68 ] ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_168 ; V_94 ++ )
if ( V_188 -> V_169 [ V_94 ] == V_166 ) {
if ( V_167 )
* V_167 = V_68 ;
return & V_170 [ V_94 ] ;
}
}
F_225 () ;
return NULL ;
}
static void F_226 ( struct V_107 * V_107 )
{
struct V_7 * V_8 ;
struct V_187 * V_188 = & V_189 [ V_107 -> V_190 . V_191 ] ;
if ( ! V_188 -> V_184 )
return;
F_117 (h) {
int V_145 = F_132 ( V_8 ) ;
if ( V_188 -> V_169 [ V_145 ] ) {
F_222 ( V_188 -> V_169 [ V_145 ] ) ;
V_188 -> V_169 [ V_145 ] = NULL ;
}
}
F_222 ( V_188 -> V_184 ) ;
V_188 -> V_184 = NULL ;
}
static void F_227 ( void )
{
int V_68 ;
F_228 ( NULL , NULL ) ;
for ( V_68 = 0 ; V_68 < V_186 ; V_68 ++ )
F_226 ( V_192 [ V_68 ] ) ;
}
static void F_229 ( struct V_107 * V_107 )
{
struct V_7 * V_8 ;
struct V_187 * V_188 = & V_189 [ V_107 -> V_190 . V_191 ] ;
int V_87 ;
if ( V_188 -> V_184 )
return;
V_188 -> V_184 = F_220 ( L_6 ,
& V_107 -> V_190 . V_166 ) ;
if ( ! V_188 -> V_184 )
return;
F_117 (h) {
V_87 = F_219 ( V_8 , V_188 -> V_184 ,
V_188 -> V_169 ,
& V_193 ) ;
if ( V_87 ) {
F_224 ( L_8 ,
V_8 -> V_183 , V_107 -> V_190 . V_191 ) ;
F_226 ( V_107 ) ;
break;
}
}
}
static void T_4 F_230 ( void )
{
int V_68 ;
F_231 (nid, N_MEMORY) {
struct V_107 * V_107 = V_192 [ V_68 ] ;
if ( V_107 -> V_190 . V_191 == V_68 )
F_229 ( V_107 ) ;
}
F_228 ( F_229 ,
F_226 ) ;
}
static struct V_7 * F_201 ( struct V_165 * V_166 , int * V_167 )
{
F_225 () ;
if ( V_167 )
* V_167 = - 1 ;
return NULL ;
}
static void F_227 ( void ) { }
static void F_230 ( void ) { }
static void T_7 F_232 ( void )
{
struct V_7 * V_8 ;
F_227 () ;
F_117 (h) {
F_222 ( V_169 [ F_132 ( V_8 ) ] ) ;
}
F_222 ( V_184 ) ;
F_4 ( V_194 ) ;
}
static int T_4 F_233 ( void )
{
int V_94 ;
if ( ! F_157 () )
return 0 ;
if ( ! F_116 ( V_195 ) ) {
V_195 = V_196 ;
if ( ! F_116 ( V_195 ) )
F_234 ( V_197 ) ;
}
V_198 = F_132 ( F_116 ( V_195 ) ) ;
if ( V_199 )
V_200 . V_159 = V_199 ;
F_189 () ;
F_181 () ;
F_191 () ;
F_223 () ;
F_230 () ;
F_235 () ;
#ifdef F_236
V_201 = F_237 ( 8 * F_238 () ) ;
#else
V_201 = 1 ;
#endif
V_194 =
F_22 ( sizeof( struct V_202 ) * V_201 , V_10 ) ;
F_10 ( ! V_194 ) ;
for ( V_94 = 0 ; V_94 < V_201 ; V_94 ++ )
F_239 ( & V_194 [ V_94 ] ) ;
return 0 ;
}
void T_4 F_234 ( unsigned V_93 )
{
struct V_7 * V_8 ;
unsigned long V_94 ;
if ( F_116 ( V_47 << V_93 ) ) {
F_240 ( L_9 ) ;
return;
}
F_10 ( V_203 >= V_168 ) ;
F_10 ( V_93 == 0 ) ;
V_8 = & V_170 [ V_203 ++ ] ;
V_8 -> V_93 = V_93 ;
V_8 -> V_204 = ~ ( ( 1ULL << ( V_93 + V_158 ) ) - 1 ) ;
V_8 -> V_108 = 0 ;
V_8 -> V_71 = 0 ;
for ( V_94 = 0 ; V_94 < V_90 ; ++ V_94 )
F_23 ( & V_8 -> V_70 [ V_94 ] ) ;
F_23 ( & V_8 -> V_73 ) ;
V_8 -> V_91 = F_73 ( V_142 [ V_143 ] ) ;
V_8 -> V_92 = F_73 ( V_142 [ V_143 ] ) ;
snprintf ( V_8 -> V_183 , V_205 , L_10 ,
F_118 ( V_8 ) / 1024 ) ;
V_206 = V_8 ;
}
static int T_4 F_241 ( char * V_207 )
{
unsigned long * V_208 ;
static unsigned long * V_209 ;
if ( ! V_203 )
V_208 = & V_199 ;
else
V_208 = & V_206 -> V_159 ;
if ( V_208 == V_209 ) {
F_240 ( L_11
L_12 ) ;
return 1 ;
}
if ( sscanf ( V_207 , L_13 , V_208 ) <= 0 )
* V_208 = 0 ;
if ( V_203 && V_206 -> V_93 >= V_125 )
F_188 ( V_206 ) ;
V_209 = V_208 ;
return 1 ;
}
static int T_4 F_242 ( char * V_207 )
{
V_195 = F_243 ( V_207 , & V_207 ) ;
return 1 ;
}
static unsigned int F_244 ( unsigned int * V_210 )
{
int V_107 ;
unsigned int V_211 = 0 ;
F_194 (node, cpuset_current_mems_allowed)
V_211 += V_210 [ V_107 ] ;
return V_211 ;
}
static int F_245 ( bool V_173 ,
struct V_212 * V_213 , int V_214 ,
void T_8 * V_215 , T_6 * V_216 , T_9 * V_217 )
{
struct V_7 * V_8 = & V_200 ;
unsigned long V_137 = V_8 -> V_159 ;
int V_13 ;
if ( ! F_157 () )
return - V_218 ;
V_213 -> V_219 = & V_137 ;
V_213 -> V_220 = sizeof( unsigned long ) ;
V_13 = F_246 ( V_213 , V_214 , V_215 , V_216 , V_217 ) ;
if ( V_13 )
goto V_39;
if ( V_214 )
V_13 = F_203 ( V_173 , V_8 ,
V_135 , V_137 , * V_216 ) ;
V_39:
return V_13 ;
}
int F_247 ( struct V_212 * V_213 , int V_214 ,
void T_8 * V_215 , T_6 * V_216 , T_9 * V_217 )
{
return F_245 ( false , V_213 , V_214 ,
V_215 , V_216 , V_217 ) ;
}
int F_248 ( struct V_212 * V_213 , int V_214 ,
void T_8 * V_215 , T_6 * V_216 , T_9 * V_217 )
{
return F_245 ( true , V_213 , V_214 ,
V_215 , V_216 , V_217 ) ;
}
int F_249 ( struct V_212 * V_213 , int V_214 ,
void T_8 * V_215 ,
T_6 * V_216 , T_9 * V_217 )
{
struct V_7 * V_8 = & V_200 ;
unsigned long V_137 ;
int V_13 ;
if ( ! F_157 () )
return - V_218 ;
V_137 = V_8 -> V_134 ;
if ( V_214 && F_109 ( V_8 ) )
return - V_176 ;
V_213 -> V_219 = & V_137 ;
V_213 -> V_220 = sizeof( unsigned long ) ;
V_13 = F_246 ( V_213 , V_214 , V_215 , V_216 , V_217 ) ;
if ( V_13 )
goto V_39;
if ( V_214 ) {
F_9 ( & V_119 ) ;
V_8 -> V_134 = V_137 ;
F_2 ( & V_119 ) ;
}
V_39:
return V_13 ;
}
void F_250 ( struct V_221 * V_152 )
{
struct V_7 * V_8 = & V_200 ;
if ( ! F_157 () )
return;
F_251 ( V_152 ,
L_14
L_15
L_16
L_17
L_18 ,
V_8 -> V_108 ,
V_8 -> V_71 ,
V_8 -> V_86 ,
V_8 -> V_121 ,
1UL << ( F_33 ( V_8 ) + V_158 - 10 ) ) ;
}
int F_252 ( int V_68 , char * V_160 )
{
struct V_7 * V_8 = & V_200 ;
if ( ! F_157 () )
return 0 ;
return sprintf ( V_160 ,
L_19
L_20
L_21 ,
V_68 , V_8 -> V_109 [ V_68 ] ,
V_68 , V_8 -> V_72 [ V_68 ] ,
V_68 , V_8 -> V_120 [ V_68 ] ) ;
}
void F_253 ( void )
{
struct V_7 * V_8 ;
int V_68 ;
if ( ! F_157 () )
return;
F_231 (nid, N_MEMORY)
F_117 (h)
F_192 ( L_22 ,
V_68 ,
V_8 -> V_109 [ V_68 ] ,
V_8 -> V_72 [ V_68 ] ,
V_8 -> V_120 [ V_68 ] ,
1UL << ( F_33 ( V_8 ) + V_158 - 10 ) ) ;
}
unsigned long F_254 ( void )
{
struct V_7 * V_8 ;
unsigned long V_222 = 0 ;
F_117 (h)
V_222 += V_8 -> V_108 * F_110 ( V_8 ) ;
return V_222 ;
}
static int F_3 ( struct V_7 * V_8 , long V_12 )
{
int V_13 = - V_14 ;
F_9 ( & V_119 ) ;
if ( V_12 > 0 ) {
if ( F_163 ( V_8 , V_12 ) < 0 )
goto V_39;
if ( V_12 > F_244 ( V_8 -> V_72 ) ) {
F_165 ( V_8 , V_12 ) ;
goto V_39;
}
}
V_13 = 0 ;
if ( V_12 < 0 )
F_165 ( V_8 , ( unsigned long ) - V_12 ) ;
V_39:
F_2 ( & V_119 ) ;
return V_13 ;
}
static void F_255 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_46 ( V_19 ) ;
if ( V_22 && F_50 ( V_19 , V_66 ) )
F_256 ( & V_22 -> V_50 ) ;
}
static void F_257 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = F_35 ( V_19 ) ;
struct V_21 * V_22 = F_46 ( V_19 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
unsigned long V_223 , V_224 , V_40 ;
long V_225 ;
if ( ! V_22 || ! F_50 ( V_19 , V_66 ) )
return;
V_224 = F_31 ( V_8 , V_19 , V_19 -> V_45 ) ;
V_40 = F_31 ( V_8 , V_19 , V_19 -> V_226 ) ;
V_223 = ( V_40 - V_224 ) - F_28 ( V_22 , V_224 , V_40 ) ;
F_258 ( & V_22 -> V_50 , F_43 ) ;
if ( V_223 ) {
V_225 = F_12 ( V_2 , V_223 ) ;
F_3 ( V_8 , - V_225 ) ;
}
}
static int F_259 ( struct V_18 * V_19 , struct V_227 * V_228 )
{
F_225 () ;
return 0 ;
}
static T_10 F_260 ( struct V_18 * V_19 , struct V_67 * V_67 ,
int V_229 )
{
T_10 V_230 ;
if ( V_229 ) {
V_230 = F_261 ( F_262 ( F_263 ( V_67 ,
V_19 -> V_231 ) ) ) ;
} else {
V_230 = F_264 ( F_263 ( V_67 ,
V_19 -> V_231 ) ) ;
}
V_230 = F_265 ( V_230 ) ;
V_230 = F_266 ( V_230 ) ;
V_230 = F_267 ( V_230 , V_19 , V_67 , V_229 ) ;
return V_230 ;
}
static void F_268 ( struct V_18 * V_19 ,
unsigned long V_44 , T_10 * V_232 )
{
T_10 V_230 ;
V_230 = F_261 ( F_262 ( F_269 ( V_232 ) ) ) ;
if ( F_270 ( V_19 , V_44 , V_232 , V_230 , 1 ) )
F_271 ( V_19 , V_44 , V_232 ) ;
}
static int F_272 ( T_10 V_233 )
{
T_11 V_234 ;
if ( F_273 ( V_233 ) || F_274 ( V_233 ) )
return 0 ;
V_234 = F_275 ( V_233 ) ;
if ( F_276 ( V_234 ) && F_277 ( V_234 ) )
return 1 ;
else
return 0 ;
}
static int F_278 ( T_10 V_233 )
{
T_11 V_234 ;
if ( F_273 ( V_233 ) || F_274 ( V_233 ) )
return 0 ;
V_234 = F_275 ( V_233 ) ;
if ( F_276 ( V_234 ) && F_279 ( V_234 ) )
return 1 ;
else
return 0 ;
}
int F_280 ( struct V_235 * V_236 , struct V_235 * V_237 ,
struct V_18 * V_19 )
{
T_10 * V_238 , * V_239 , V_230 ;
struct V_67 * V_240 ;
unsigned long V_144 ;
int V_241 ;
struct V_7 * V_8 = F_35 ( V_19 ) ;
unsigned long V_242 = F_118 ( V_8 ) ;
unsigned long V_243 ;
unsigned long V_244 ;
int V_13 = 0 ;
V_241 = ( V_19 -> V_55 & ( V_245 | V_246 ) ) == V_246 ;
V_243 = V_19 -> V_45 ;
V_244 = V_19 -> V_226 ;
if ( V_241 )
F_281 ( V_237 , V_243 , V_244 ) ;
for ( V_144 = V_19 -> V_45 ; V_144 < V_19 -> V_226 ; V_144 += V_242 ) {
T_12 * V_247 , * V_248 ;
V_238 = F_282 ( V_237 , V_144 ) ;
if ( ! V_238 )
continue;
V_239 = F_283 ( V_236 , V_144 , V_242 ) ;
if ( ! V_239 ) {
V_13 = - V_14 ;
break;
}
if ( V_239 == V_238 )
continue;
V_248 = F_284 ( V_8 , V_236 , V_239 ) ;
V_247 = F_285 ( V_8 , V_237 , V_238 ) ;
F_286 ( V_247 , V_249 ) ;
V_230 = F_269 ( V_238 ) ;
if ( F_273 ( V_230 ) ) {
;
} else if ( F_69 ( F_272 ( V_230 ) ||
F_278 ( V_230 ) ) ) {
T_11 V_250 = F_275 ( V_230 ) ;
if ( F_287 ( V_250 ) && V_241 ) {
F_288 ( & V_250 ) ;
V_230 = F_289 ( V_250 ) ;
F_290 ( V_237 , V_144 , V_238 , V_230 ) ;
}
F_290 ( V_236 , V_144 , V_239 , V_230 ) ;
} else {
if ( V_241 ) {
F_291 ( V_237 , V_144 , V_238 ) ;
F_292 ( V_237 , V_243 ,
V_244 ) ;
}
V_230 = F_269 ( V_238 ) ;
V_240 = F_293 ( V_230 ) ;
F_294 ( V_240 ) ;
F_295 ( V_240 ) ;
F_290 ( V_236 , V_144 , V_239 , V_230 ) ;
}
F_2 ( V_247 ) ;
F_2 ( V_248 ) ;
}
if ( V_241 )
F_296 ( V_237 , V_243 , V_244 ) ;
return V_13 ;
}
void F_297 ( struct V_251 * V_252 , struct V_18 * V_19 ,
unsigned long V_224 , unsigned long V_40 ,
struct V_67 * V_253 )
{
int V_254 = 0 ;
struct V_235 * V_255 = V_19 -> V_256 ;
unsigned long V_44 ;
T_10 * V_232 ;
T_10 V_233 ;
T_12 * V_257 ;
struct V_67 * V_67 ;
struct V_7 * V_8 = F_35 ( V_19 ) ;
unsigned long V_242 = F_118 ( V_8 ) ;
const unsigned long V_243 = V_224 ;
const unsigned long V_244 = V_40 ;
F_186 ( ! F_37 ( V_19 ) ) ;
F_10 ( V_224 & ~ F_298 ( V_8 ) ) ;
F_10 ( V_40 & ~ F_298 ( V_8 ) ) ;
F_299 ( V_252 , V_19 ) ;
F_281 ( V_255 , V_243 , V_244 ) ;
V_44 = V_224 ;
V_258:
for (; V_44 < V_40 ; V_44 += V_242 ) {
V_232 = F_282 ( V_255 , V_44 ) ;
if ( ! V_232 )
continue;
V_257 = F_284 ( V_8 , V_255 , V_232 ) ;
if ( F_300 ( V_255 , & V_44 , V_232 ) )
goto V_259;
V_233 = F_269 ( V_232 ) ;
if ( F_273 ( V_233 ) )
goto V_259;
if ( F_69 ( ! F_274 ( V_233 ) ) ) {
F_301 ( V_255 , V_44 , V_232 ) ;
goto V_259;
}
V_67 = F_293 ( V_233 ) ;
if ( V_253 ) {
if ( V_67 != V_253 )
goto V_259;
F_49 ( V_19 , V_260 ) ;
}
V_233 = F_302 ( V_255 , V_44 , V_232 ) ;
F_303 ( V_252 , V_232 , V_44 ) ;
if ( F_304 ( V_233 ) )
F_305 ( V_67 ) ;
F_306 ( V_67 ) ;
V_254 = ! F_307 ( V_252 , V_67 ) ;
if ( V_254 ) {
V_44 += V_242 ;
F_2 ( V_257 ) ;
break;
}
if ( V_253 ) {
F_2 ( V_257 ) ;
break;
}
V_259:
F_2 ( V_257 ) ;
}
if ( V_254 ) {
V_254 = 0 ;
F_308 ( V_252 ) ;
if ( V_44 < V_40 && ! V_253 )
goto V_258;
}
F_296 ( V_255 , V_243 , V_244 ) ;
F_309 ( V_252 , V_19 ) ;
}
void F_310 ( struct V_251 * V_252 ,
struct V_18 * V_19 , unsigned long V_224 ,
unsigned long V_40 , struct V_67 * V_253 )
{
F_297 ( V_252 , V_19 , V_224 , V_40 , V_253 ) ;
V_19 -> V_55 &= ~ V_56 ;
}
void F_311 ( struct V_18 * V_19 , unsigned long V_224 ,
unsigned long V_40 , struct V_67 * V_253 )
{
struct V_235 * V_255 ;
struct V_251 V_252 ;
V_255 = V_19 -> V_256 ;
F_312 ( & V_252 , V_255 , V_224 , V_40 ) ;
F_297 ( & V_252 , V_19 , V_224 , V_40 , V_253 ) ;
F_313 ( & V_252 , V_224 , V_40 ) ;
}
static void F_314 ( struct V_235 * V_255 , struct V_18 * V_19 ,
struct V_67 * V_67 , unsigned long V_44 )
{
struct V_7 * V_8 = F_35 ( V_19 ) ;
struct V_18 * V_261 ;
struct V_57 * V_58 ;
T_1 V_262 ;
V_44 = V_44 & F_298 ( V_8 ) ;
V_262 = ( ( V_44 - V_19 -> V_45 ) >> V_158 ) +
V_19 -> V_46 ;
V_58 = F_16 ( V_19 -> V_20 ) -> V_53 ;
F_315 ( V_58 ) ;
F_316 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_261 == V_19 )
continue;
if ( ! F_50 ( V_261 , V_66 ) )
F_311 ( V_261 , V_44 ,
V_44 + F_118 ( V_8 ) , V_67 ) ;
}
F_317 ( V_58 ) ;
}
static int F_318 ( struct V_235 * V_255 , struct V_18 * V_19 ,
unsigned long V_44 , T_10 * V_232 , T_10 V_233 ,
struct V_67 * V_263 , T_12 * V_257 )
{
struct V_7 * V_8 = F_35 ( V_19 ) ;
struct V_67 * V_264 , * V_265 ;
int V_13 = 0 , V_266 = 0 ;
unsigned long V_243 ;
unsigned long V_244 ;
V_264 = F_293 ( V_233 ) ;
V_267:
if ( F_130 ( V_264 ) == 1 && F_319 ( V_264 ) ) {
F_320 ( V_264 , V_19 , V_44 ) ;
F_268 ( V_19 , V_44 , V_232 ) ;
return 0 ;
}
if ( F_50 ( V_19 , V_66 ) &&
V_264 != V_263 )
V_266 = 1 ;
F_321 ( V_264 ) ;
F_2 ( V_257 ) ;
V_265 = F_169 ( V_19 , V_44 , V_266 ) ;
if ( F_175 ( V_265 ) ) {
if ( V_266 ) {
F_322 ( V_264 ) ;
F_10 ( F_273 ( V_233 ) ) ;
F_314 ( V_255 , V_19 , V_264 , V_44 ) ;
F_10 ( F_273 ( V_233 ) ) ;
F_9 ( V_257 ) ;
V_232 = F_282 ( V_255 , V_44 & F_298 ( V_8 ) ) ;
if ( F_323 ( V_232 &&
F_324 ( F_269 ( V_232 ) , V_233 ) ) )
goto V_267;
return 0 ;
}
V_13 = ( F_325 ( V_265 ) == - V_14 ) ?
V_268 : V_269 ;
goto V_270;
}
if ( F_69 ( F_326 ( V_19 ) ) ) {
V_13 = V_268 ;
goto V_271;
}
F_327 ( V_265 , V_264 , V_44 , V_19 ,
F_110 ( V_8 ) ) ;
F_328 ( V_265 ) ;
F_122 ( V_265 ) ;
V_243 = V_44 & F_298 ( V_8 ) ;
V_244 = V_243 + F_118 ( V_8 ) ;
F_281 ( V_255 , V_243 , V_244 ) ;
F_9 ( V_257 ) ;
V_232 = F_282 ( V_255 , V_44 & F_298 ( V_8 ) ) ;
if ( F_323 ( V_232 && F_324 ( F_269 ( V_232 ) , V_233 ) ) ) {
F_125 ( V_265 ) ;
F_329 ( V_19 , V_44 , V_232 ) ;
F_292 ( V_255 , V_243 , V_244 ) ;
F_290 ( V_255 , V_44 , V_232 ,
F_260 ( V_19 , V_265 , 1 ) ) ;
F_306 ( V_264 ) ;
F_330 ( V_265 , V_19 , V_44 ) ;
V_265 = V_264 ;
}
F_2 ( V_257 ) ;
F_296 ( V_255 , V_243 , V_244 ) ;
V_271:
F_322 ( V_265 ) ;
V_270:
F_322 ( V_264 ) ;
F_9 ( V_257 ) ;
return V_13 ;
}
static struct V_67 * F_331 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_44 )
{
struct V_57 * V_58 ;
T_1 V_145 ;
V_58 = V_19 -> V_20 -> V_59 ;
V_145 = F_31 ( V_8 , V_19 , V_44 ) ;
return F_332 ( V_58 , V_145 ) ;
}
static bool F_333 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_44 )
{
struct V_57 * V_58 ;
T_1 V_145 ;
struct V_67 * V_67 ;
V_58 = V_19 -> V_20 -> V_59 ;
V_145 = F_31 ( V_8 , V_19 , V_44 ) ;
V_67 = F_334 ( V_58 , V_145 ) ;
if ( V_67 )
F_135 ( V_67 ) ;
return V_67 != NULL ;
}
static int F_335 ( struct V_235 * V_255 , struct V_18 * V_19 ,
struct V_57 * V_58 , T_1 V_145 ,
unsigned long V_44 , T_10 * V_232 , unsigned int V_63 )
{
struct V_7 * V_8 = F_35 ( V_19 ) ;
int V_13 = V_269 ;
int V_272 = 0 ;
unsigned long V_117 ;
struct V_67 * V_67 ;
T_10 V_273 ;
T_12 * V_257 ;
if ( F_50 ( V_19 , V_260 ) ) {
F_240 ( L_23 ,
V_164 -> V_274 ) ;
return V_13 ;
}
V_36:
V_67 = F_332 ( V_58 , V_145 ) ;
if ( ! V_67 ) {
V_117 = F_336 ( V_58 -> V_60 ) >> F_32 ( V_8 ) ;
if ( V_145 >= V_117 )
goto V_39;
V_67 = F_169 ( V_19 , V_44 , 0 ) ;
if ( F_175 ( V_67 ) ) {
V_13 = F_325 ( V_67 ) ;
if ( V_13 == - V_14 )
V_13 = V_268 ;
else
V_13 = V_269 ;
goto V_39;
}
F_337 ( V_67 , V_44 , F_110 ( V_8 ) ) ;
F_328 ( V_67 ) ;
F_122 ( V_67 ) ;
if ( V_19 -> V_55 & V_56 ) {
int V_87 ;
struct V_16 * V_16 = V_58 -> V_60 ;
V_87 = F_338 ( V_67 , V_58 , V_145 , V_10 ) ;
if ( V_87 ) {
F_135 ( V_67 ) ;
if ( V_87 == - V_275 )
goto V_36;
goto V_39;
}
F_125 ( V_67 ) ;
F_9 ( & V_16 -> V_276 ) ;
V_16 -> V_277 += F_339 ( V_8 ) ;
F_2 ( & V_16 -> V_276 ) ;
} else {
F_340 ( V_67 ) ;
if ( F_69 ( F_326 ( V_19 ) ) ) {
V_13 = V_268 ;
goto V_278;
}
V_272 = 1 ;
}
} else {
if ( F_69 ( F_341 ( V_67 ) ) ) {
V_13 = V_279 |
F_342 ( F_132 ( V_8 ) ) ;
goto V_278;
}
}
if ( ( V_63 & V_280 ) && ! ( V_19 -> V_55 & V_245 ) )
if ( F_167 ( V_8 , V_19 , V_44 ) < 0 ) {
V_13 = V_268 ;
goto V_278;
}
V_257 = F_285 ( V_8 , V_255 , V_232 ) ;
F_9 ( V_257 ) ;
V_117 = F_336 ( V_58 -> V_60 ) >> F_32 ( V_8 ) ;
if ( V_145 >= V_117 )
goto V_281;
V_13 = 0 ;
if ( ! F_273 ( F_269 ( V_232 ) ) )
goto V_281;
if ( V_272 ) {
F_125 ( V_67 ) ;
F_330 ( V_67 , V_19 , V_44 ) ;
} else
F_295 ( V_67 ) ;
V_273 = F_260 ( V_19 , V_67 , ( ( V_19 -> V_55 & V_282 )
&& ( V_19 -> V_55 & V_245 ) ) ) ;
F_290 ( V_255 , V_44 , V_232 , V_273 ) ;
if ( ( V_63 & V_280 ) && ! ( V_19 -> V_55 & V_245 ) ) {
V_13 = F_318 ( V_255 , V_19 , V_44 , V_232 , V_273 , V_67 , V_257 ) ;
}
F_2 ( V_257 ) ;
F_343 ( V_67 ) ;
V_39:
return V_13 ;
V_281:
F_2 ( V_257 ) ;
V_278:
F_343 ( V_67 ) ;
F_135 ( V_67 ) ;
goto V_39;
}
static T_13 F_344 ( struct V_7 * V_8 , struct V_235 * V_255 ,
struct V_18 * V_19 ,
struct V_57 * V_58 ,
T_1 V_145 , unsigned long V_44 )
{
unsigned long V_283 [ 2 ] ;
T_13 V_284 ;
if ( V_19 -> V_55 & V_245 ) {
V_283 [ 0 ] = ( unsigned long ) V_58 ;
V_283 [ 1 ] = V_145 ;
} else {
V_283 [ 0 ] = ( unsigned long ) V_255 ;
V_283 [ 1 ] = V_44 >> F_32 ( V_8 ) ;
}
V_284 = F_345 ( ( T_13 * ) & V_283 , sizeof( V_283 ) / sizeof( T_13 ) , 0 ) ;
return V_284 & ( V_201 - 1 ) ;
}
static T_13 F_344 ( struct V_7 * V_8 , struct V_235 * V_255 ,
struct V_18 * V_19 ,
struct V_57 * V_58 ,
T_1 V_145 , unsigned long V_44 )
{
return 0 ;
}
int F_346 ( struct V_235 * V_255 , struct V_18 * V_19 ,
unsigned long V_44 , unsigned int V_63 )
{
T_10 * V_232 , V_230 ;
T_12 * V_257 ;
int V_13 ;
T_13 V_284 ;
T_1 V_145 ;
struct V_67 * V_67 = NULL ;
struct V_67 * V_263 = NULL ;
struct V_7 * V_8 = F_35 ( V_19 ) ;
struct V_57 * V_58 ;
int V_285 = 0 ;
V_44 &= F_298 ( V_8 ) ;
V_232 = F_282 ( V_255 , V_44 ) ;
if ( V_232 ) {
V_230 = F_269 ( V_232 ) ;
if ( F_69 ( F_272 ( V_230 ) ) ) {
F_347 ( V_19 , V_255 , V_232 ) ;
return 0 ;
} else if ( F_69 ( F_278 ( V_230 ) ) )
return V_286 |
F_342 ( F_132 ( V_8 ) ) ;
}
V_232 = F_283 ( V_255 , V_44 , F_118 ( V_8 ) ) ;
if ( ! V_232 )
return V_268 ;
V_58 = V_19 -> V_20 -> V_59 ;
V_145 = F_31 ( V_8 , V_19 , V_44 ) ;
V_284 = F_344 ( V_8 , V_255 , V_19 , V_58 , V_145 , V_44 ) ;
F_348 ( & V_194 [ V_284 ] ) ;
V_230 = F_269 ( V_232 ) ;
if ( F_273 ( V_230 ) ) {
V_13 = F_335 ( V_255 , V_19 , V_58 , V_145 , V_44 , V_232 , V_63 ) ;
goto V_287;
}
V_13 = 0 ;
if ( ! F_274 ( V_230 ) )
goto V_287;
if ( ( V_63 & V_280 ) && ! F_349 ( V_230 ) ) {
if ( F_167 ( V_8 , V_19 , V_44 ) < 0 ) {
V_13 = V_268 ;
goto V_287;
}
if ( ! ( V_19 -> V_55 & V_56 ) )
V_263 = F_331 ( V_8 ,
V_19 , V_44 ) ;
}
V_257 = F_284 ( V_8 , V_255 , V_232 ) ;
if ( F_69 ( ! F_324 ( V_230 , F_269 ( V_232 ) ) ) )
goto V_288;
V_67 = F_293 ( V_230 ) ;
if ( V_67 != V_263 )
if ( ! F_350 ( V_67 ) ) {
V_285 = 1 ;
goto V_288;
}
F_294 ( V_67 ) ;
if ( V_63 & V_280 ) {
if ( ! F_349 ( V_230 ) ) {
V_13 = F_318 ( V_255 , V_19 , V_44 , V_232 , V_230 ,
V_263 , V_257 ) ;
goto V_289;
}
V_230 = F_262 ( V_230 ) ;
}
V_230 = F_265 ( V_230 ) ;
if ( F_270 ( V_19 , V_44 , V_232 , V_230 ,
V_63 & V_280 ) )
F_271 ( V_19 , V_44 , V_232 ) ;
V_289:
if ( V_67 != V_263 )
F_343 ( V_67 ) ;
F_135 ( V_67 ) ;
V_288:
F_2 ( V_257 ) ;
if ( V_263 ) {
F_343 ( V_263 ) ;
F_135 ( V_263 ) ;
}
V_287:
F_351 ( & V_194 [ V_284 ] ) ;
if ( V_285 )
F_352 ( V_67 ) ;
return V_13 ;
}
long F_353 ( struct V_235 * V_255 , struct V_18 * V_19 ,
struct V_67 * * V_290 , struct V_18 * * V_291 ,
unsigned long * V_292 , unsigned long * V_95 ,
long V_94 , unsigned int V_63 )
{
unsigned long V_293 ;
unsigned long V_294 = * V_292 ;
unsigned long V_295 = * V_95 ;
struct V_7 * V_8 = F_35 ( V_19 ) ;
while ( V_294 < V_19 -> V_226 && V_295 ) {
T_10 * V_233 ;
T_12 * V_257 = NULL ;
int V_296 ;
struct V_67 * V_67 ;
if ( F_69 ( F_354 ( V_164 ) ) ) {
V_295 = 0 ;
break;
}
V_233 = F_282 ( V_255 , V_294 & F_298 ( V_8 ) ) ;
if ( V_233 )
V_257 = F_284 ( V_8 , V_255 , V_233 ) ;
V_296 = ! V_233 || F_273 ( F_269 ( V_233 ) ) ;
if ( V_296 && ( V_63 & V_297 ) &&
! F_333 ( V_8 , V_19 , V_294 ) ) {
if ( V_233 )
F_2 ( V_257 ) ;
V_295 = 0 ;
break;
}
if ( V_296 || F_355 ( F_269 ( V_233 ) ) ||
( ( V_63 & V_298 ) &&
! F_349 ( F_269 ( V_233 ) ) ) ) {
int V_13 ;
if ( V_233 )
F_2 ( V_257 ) ;
V_13 = F_346 ( V_255 , V_19 , V_294 ,
( V_63 & V_298 ) ? V_280 : 0 ) ;
if ( ! ( V_13 & V_299 ) )
continue;
V_295 = 0 ;
break;
}
V_293 = ( V_294 & ~ F_298 ( V_8 ) ) >> V_158 ;
V_67 = F_293 ( F_269 ( V_233 ) ) ;
V_300:
if ( V_290 ) {
V_290 [ V_94 ] = F_356 ( V_67 , V_293 ) ;
F_357 ( V_290 [ V_94 ] ) ;
}
if ( V_291 )
V_291 [ V_94 ] = V_19 ;
V_294 += V_47 ;
++ V_293 ;
-- V_295 ;
++ V_94 ;
if ( V_294 < V_19 -> V_226 && V_295 &&
V_293 < F_110 ( V_8 ) ) {
goto V_300;
}
F_2 ( V_257 ) ;
}
* V_95 = V_295 ;
* V_292 = V_294 ;
return V_94 ? V_94 : - V_301 ;
}
unsigned long F_358 ( struct V_18 * V_19 ,
unsigned long V_44 , unsigned long V_40 , T_14 V_302 )
{
struct V_235 * V_255 = V_19 -> V_256 ;
unsigned long V_224 = V_44 ;
T_10 * V_232 ;
T_10 V_233 ;
struct V_7 * V_8 = F_35 ( V_19 ) ;
unsigned long V_290 = 0 ;
F_10 ( V_44 >= V_40 ) ;
F_359 ( V_19 , V_44 , V_40 ) ;
F_281 ( V_255 , V_224 , V_40 ) ;
F_315 ( V_19 -> V_20 -> V_59 ) ;
for (; V_44 < V_40 ; V_44 += F_118 ( V_8 ) ) {
T_12 * V_257 ;
V_232 = F_282 ( V_255 , V_44 ) ;
if ( ! V_232 )
continue;
V_257 = F_284 ( V_8 , V_255 , V_232 ) ;
if ( F_300 ( V_255 , & V_44 , V_232 ) ) {
V_290 ++ ;
F_2 ( V_257 ) ;
continue;
}
V_233 = F_269 ( V_232 ) ;
if ( F_69 ( F_278 ( V_233 ) ) ) {
F_2 ( V_257 ) ;
continue;
}
if ( F_69 ( F_272 ( V_233 ) ) ) {
T_11 V_230 = F_275 ( V_233 ) ;
if ( F_287 ( V_230 ) ) {
T_10 V_303 ;
F_288 ( & V_230 ) ;
V_303 = F_289 ( V_230 ) ;
F_290 ( V_255 , V_44 , V_232 , V_303 ) ;
V_290 ++ ;
}
F_2 ( V_257 ) ;
continue;
}
if ( ! F_273 ( V_233 ) ) {
V_233 = F_302 ( V_255 , V_44 , V_232 ) ;
V_233 = F_266 ( F_360 ( V_233 , V_302 ) ) ;
V_233 = F_267 ( V_233 , V_19 , NULL , 0 ) ;
F_290 ( V_255 , V_44 , V_232 , V_233 ) ;
V_290 ++ ;
}
F_2 ( V_257 ) ;
}
F_361 ( V_19 , V_224 , V_40 ) ;
F_292 ( V_255 , V_224 , V_40 ) ;
F_317 ( V_19 -> V_20 -> V_59 ) ;
F_296 ( V_255 , V_224 , V_40 ) ;
return V_290 << V_8 -> V_93 ;
}
int F_362 ( struct V_16 * V_16 ,
long V_33 , long V_32 ,
struct V_18 * V_19 ,
T_15 V_55 )
{
long V_13 , V_35 ;
struct V_7 * V_8 = F_363 ( V_16 ) ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
struct V_21 * V_21 ;
long V_225 ;
if ( V_55 & V_65 )
return 0 ;
if ( ! V_19 || V_19 -> V_55 & V_56 ) {
V_21 = F_45 ( V_16 ) ;
V_35 = F_21 ( V_21 , V_33 , V_32 ) ;
} else {
V_21 = F_41 () ;
if ( ! V_21 )
return - V_14 ;
V_35 = V_32 - V_33 ;
F_48 ( V_19 , V_21 ) ;
F_49 ( V_19 , V_66 ) ;
}
if ( V_35 < 0 ) {
V_13 = V_35 ;
goto V_304;
}
V_225 = F_11 ( V_2 , V_35 ) ;
if ( V_225 < 0 ) {
V_13 = - V_148 ;
goto V_304;
}
V_13 = F_3 ( V_8 , V_225 ) ;
if ( V_13 < 0 ) {
( void ) F_12 ( V_2 , V_35 ) ;
goto V_304;
}
if ( ! V_19 || V_19 -> V_55 & V_56 )
F_17 ( V_21 , V_33 , V_32 ) ;
return 0 ;
V_304:
if ( V_19 && F_50 ( V_19 , V_66 ) )
F_258 ( & V_21 -> V_50 , F_43 ) ;
return V_13 ;
}
void F_364 ( struct V_16 * V_16 , long V_305 , long V_306 )
{
struct V_7 * V_8 = F_363 ( V_16 ) ;
struct V_21 * V_21 = F_45 ( V_16 ) ;
long V_35 = 0 ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
long V_225 ;
if ( V_21 )
V_35 = F_25 ( V_21 , V_305 ) ;
F_9 ( & V_16 -> V_276 ) ;
V_16 -> V_277 -= ( F_339 ( V_8 ) * V_306 ) ;
F_2 ( & V_16 -> V_276 ) ;
V_225 = F_12 ( V_2 , ( V_35 - V_306 ) ) ;
F_3 ( V_8 , - V_225 ) ;
}
static unsigned long F_365 ( struct V_18 * V_307 ,
struct V_18 * V_19 ,
unsigned long V_144 , T_1 V_145 )
{
unsigned long V_308 = ( ( V_145 - V_307 -> V_46 ) << V_158 ) +
V_307 -> V_45 ;
unsigned long V_309 = V_308 & V_310 ;
unsigned long V_311 = V_309 + V_312 ;
unsigned long V_55 = V_19 -> V_55 & ~ V_313 ;
unsigned long V_314 = V_307 -> V_55 & ~ V_313 ;
if ( F_366 ( V_144 ) != F_366 ( V_308 ) ||
V_55 != V_314 ||
V_309 < V_307 -> V_45 || V_307 -> V_226 < V_311 )
return 0 ;
return V_308 ;
}
static int F_367 ( struct V_18 * V_19 , unsigned long V_144 )
{
unsigned long V_315 = V_144 & V_310 ;
unsigned long V_40 = V_315 + V_312 ;
if ( V_19 -> V_55 & V_56 &&
V_19 -> V_45 <= V_315 && V_40 <= V_19 -> V_226 )
return 1 ;
return 0 ;
}
T_10 * F_368 ( struct V_235 * V_255 , unsigned long V_144 , T_16 * V_316 )
{
struct V_18 * V_19 = F_369 ( V_255 , V_144 ) ;
struct V_57 * V_58 = V_19 -> V_20 -> V_59 ;
T_1 V_145 = ( ( V_144 - V_19 -> V_45 ) >> V_158 ) +
V_19 -> V_46 ;
struct V_18 * V_307 ;
unsigned long V_308 ;
T_10 * V_317 = NULL ;
T_10 * V_233 ;
T_12 * V_257 ;
if ( ! F_367 ( V_19 , V_144 ) )
return ( T_10 * ) F_370 ( V_255 , V_316 , V_144 ) ;
F_315 ( V_58 ) ;
F_316 (svma, &mapping->i_mmap, idx, idx) {
if ( V_307 == V_19 )
continue;
V_308 = F_365 ( V_307 , V_19 , V_144 , V_145 ) ;
if ( V_308 ) {
V_317 = F_282 ( V_307 -> V_256 , V_308 ) ;
if ( V_317 ) {
F_371 ( V_255 ) ;
F_294 ( F_185 ( V_317 ) ) ;
break;
}
}
}
if ( ! V_317 )
goto V_39;
V_257 = F_285 ( F_35 ( V_19 ) , V_255 , V_317 ) ;
F_9 ( V_257 ) ;
if ( F_372 ( * V_316 ) ) {
F_373 ( V_255 , V_316 ,
( V_318 * ) ( ( unsigned long ) V_317 & V_319 ) ) ;
} else {
F_135 ( F_185 ( V_317 ) ) ;
F_371 ( V_255 ) ;
}
F_2 ( V_257 ) ;
V_39:
V_233 = ( T_10 * ) F_370 ( V_255 , V_316 , V_144 ) ;
F_317 ( V_58 ) ;
return V_233 ;
}
int F_300 ( struct V_235 * V_255 , unsigned long * V_144 , T_10 * V_232 )
{
T_17 * V_320 = F_374 ( V_255 , * V_144 ) ;
T_16 * V_316 = F_375 ( V_320 , * V_144 ) ;
F_10 ( F_93 ( F_185 ( V_232 ) ) == 0 ) ;
if ( F_93 ( F_185 ( V_232 ) ) == 1 )
return 0 ;
F_376 ( V_316 ) ;
F_135 ( F_185 ( V_232 ) ) ;
F_377 ( V_255 ) ;
* V_144 = F_100 ( * V_144 , V_196 * V_321 ) - V_196 ;
return 1 ;
}
T_10 * F_368 ( struct V_235 * V_255 , unsigned long V_144 , T_16 * V_316 )
{
return NULL ;
}
T_10 * F_283 ( struct V_235 * V_255 ,
unsigned long V_144 , unsigned long V_242 )
{
T_17 * V_320 ;
T_16 * V_316 ;
T_10 * V_233 = NULL ;
V_320 = F_374 ( V_255 , V_144 ) ;
V_316 = F_378 ( V_255 , V_320 , V_144 ) ;
if ( V_316 ) {
if ( V_242 == V_312 ) {
V_233 = ( T_10 * ) V_316 ;
} else {
F_10 ( V_242 != V_322 ) ;
if ( F_379 () && F_372 ( * V_316 ) )
V_233 = F_368 ( V_255 , V_144 , V_316 ) ;
else
V_233 = ( T_10 * ) F_370 ( V_255 , V_316 , V_144 ) ;
}
}
F_10 ( V_233 && ! F_380 ( * V_233 ) && ! F_381 ( * V_233 ) ) ;
return V_233 ;
}
T_10 * F_282 ( struct V_235 * V_255 , unsigned long V_144 )
{
T_17 * V_320 ;
T_16 * V_316 ;
V_318 * V_323 = NULL ;
V_320 = F_374 ( V_255 , V_144 ) ;
if ( F_382 ( * V_320 ) ) {
V_316 = F_375 ( V_320 , V_144 ) ;
if ( F_383 ( * V_316 ) ) {
if ( F_384 ( * V_316 ) )
return ( T_10 * ) V_316 ;
V_323 = F_385 ( V_316 , V_144 ) ;
}
}
return ( T_10 * ) V_323 ;
}
struct V_67 * __weak
F_386 ( struct V_235 * V_255 , unsigned long V_44 ,
int V_214 )
{
return F_170 ( - V_176 ) ;
}
struct V_67 * __weak
F_387 ( struct V_235 * V_255 , unsigned long V_44 ,
V_318 * V_323 , int V_63 )
{
struct V_67 * V_67 = NULL ;
T_12 * V_257 ;
V_36:
V_257 = F_388 ( V_255 , V_323 ) ;
F_9 ( V_257 ) ;
if ( ! F_389 ( * V_323 ) )
goto V_39;
if ( F_390 ( * V_323 ) ) {
V_67 = F_391 ( * V_323 ) + ( ( V_44 & ~ V_324 ) >> V_158 ) ;
if ( V_63 & V_325 )
F_294 ( V_67 ) ;
} else {
if ( F_272 ( F_269 ( ( T_10 * ) V_323 ) ) ) {
F_2 ( V_257 ) ;
F_392 ( V_255 , ( T_10 * ) V_323 , V_257 ) ;
goto V_36;
}
}
V_39:
F_2 ( V_257 ) ;
return V_67 ;
}
struct V_67 * __weak
F_393 ( struct V_235 * V_255 , unsigned long V_44 ,
T_16 * V_316 , int V_63 )
{
if ( V_63 & V_325 )
return NULL ;
return F_293 ( * ( T_10 * ) V_316 ) + ( ( V_44 & ~ V_310 ) >> V_158 ) ;
}
int F_394 ( struct V_67 * V_326 )
{
struct V_7 * V_8 = F_127 ( V_326 ) ;
int V_68 = F_54 ( V_326 ) ;
int V_13 = - V_327 ;
F_9 ( & V_119 ) ;
if ( ! F_119 ( V_326 ) && ! F_93 ( V_326 ) ) {
F_395 ( & V_326 -> V_69 ) ;
F_58 ( V_326 ) ;
V_8 -> V_71 -- ;
V_8 -> V_72 [ V_68 ] -- ;
V_13 = 0 ;
}
F_2 ( & V_119 ) ;
return V_13 ;
}
bool F_396 ( struct V_67 * V_67 , struct V_25 * V_155 )
{
bool V_13 = true ;
F_111 ( ! F_120 ( V_67 ) , V_67 ) ;
F_9 ( & V_119 ) ;
if ( ! F_119 ( V_67 ) || ! F_397 ( V_67 ) ) {
V_13 = false ;
goto V_259;
}
F_124 ( V_67 ) ;
F_398 ( & V_67 -> V_69 , V_155 ) ;
V_259:
F_2 ( & V_119 ) ;
return V_13 ;
}
void F_399 ( struct V_67 * V_67 )
{
F_111 ( ! F_120 ( V_67 ) , V_67 ) ;
F_9 ( & V_119 ) ;
F_122 ( V_67 ) ;
F_398 ( & V_67 -> V_69 , & ( F_127 ( V_67 ) ) -> V_73 ) ;
F_2 ( & V_119 ) ;
F_135 ( V_67 ) ;
}
