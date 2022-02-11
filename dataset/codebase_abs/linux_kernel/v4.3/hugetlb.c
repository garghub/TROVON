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
if ( & V_29 -> V_34 == V_26 || V_24 < V_29 -> V_35 ) {
F_19 ( V_22 -> V_36 <= 0 ) ;
V_22 -> V_36 -- ;
V_30 = F_20 ( & V_22 -> V_37 , struct V_28 ,
V_34 ) ;
F_21 ( & V_30 -> V_34 ) ;
V_30 -> V_35 = V_23 ;
V_30 -> V_33 = V_24 ;
F_22 ( & V_30 -> V_34 , V_29 -> V_34 . V_38 ) ;
V_32 += V_24 - V_23 ;
goto V_39;
}
if ( V_23 > V_29 -> V_35 )
V_23 = V_29 -> V_35 ;
V_30 = V_29 ;
F_23 (rg, trg, rg->link.prev, link) {
if ( & V_29 -> V_34 == V_26 )
break;
if ( V_29 -> V_35 > V_24 )
break;
if ( V_29 -> V_33 > V_24 )
V_24 = V_29 -> V_33 ;
if ( V_29 != V_30 ) {
V_32 -= ( V_29 -> V_33 - V_29 -> V_35 ) ;
F_21 ( & V_29 -> V_34 ) ;
F_4 ( V_29 ) ;
}
}
V_32 += ( V_30 -> V_35 - V_23 ) ;
V_30 -> V_35 = V_23 ;
V_32 += V_24 - V_30 -> V_33 ;
V_30 -> V_33 = V_24 ;
V_39:
V_22 -> V_40 -- ;
F_2 ( & V_22 -> V_5 ) ;
F_19 ( V_32 < 0 ) ;
return V_32 ;
}
static long F_24 ( struct V_21 * V_22 , long V_23 , long V_24 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_28 * V_29 , * V_30 = NULL ;
long V_41 = 0 ;
V_42:
F_9 ( & V_22 -> V_5 ) ;
V_43:
V_22 -> V_40 ++ ;
if ( V_22 -> V_40 > V_22 -> V_36 ) {
struct V_28 * V_31 ;
F_19 ( V_22 -> V_40 - V_22 -> V_36 > 1 ) ;
V_22 -> V_40 -- ;
F_2 ( & V_22 -> V_5 ) ;
V_31 = F_25 ( sizeof( * V_31 ) , V_10 ) ;
if ( ! V_31 )
return - V_14 ;
F_9 ( & V_22 -> V_5 ) ;
F_22 ( & V_31 -> V_34 , & V_22 -> V_37 ) ;
V_22 -> V_36 ++ ;
goto V_43;
}
F_18 (rg, head, link)
if ( V_23 <= V_29 -> V_33 )
break;
if ( & V_29 -> V_34 == V_26 || V_24 < V_29 -> V_35 ) {
if ( ! V_30 ) {
V_22 -> V_40 -- ;
F_2 ( & V_22 -> V_5 ) ;
V_30 = F_25 ( sizeof( * V_30 ) , V_10 ) ;
if ( ! V_30 )
return - V_14 ;
V_30 -> V_35 = V_23 ;
V_30 -> V_33 = V_23 ;
F_26 ( & V_30 -> V_34 ) ;
goto V_42;
}
F_22 ( & V_30 -> V_34 , V_29 -> V_34 . V_38 ) ;
V_41 = V_24 - V_23 ;
goto V_44;
}
if ( V_23 > V_29 -> V_35 )
V_23 = V_29 -> V_35 ;
V_41 = V_24 - V_23 ;
F_18 (rg, rg->link.prev, link) {
if ( & V_29 -> V_34 == V_26 )
break;
if ( V_29 -> V_35 > V_24 )
goto V_45;
if ( V_29 -> V_33 > V_24 ) {
V_41 += V_29 -> V_33 - V_24 ;
V_24 = V_29 -> V_33 ;
}
V_41 -= V_29 -> V_33 - V_29 -> V_35 ;
}
V_45:
F_2 ( & V_22 -> V_5 ) ;
F_4 ( V_30 ) ;
return V_41 ;
V_44:
F_2 ( & V_22 -> V_5 ) ;
return V_41 ;
}
static void F_27 ( struct V_21 * V_22 , long V_23 , long V_24 )
{
F_9 ( & V_22 -> V_5 ) ;
F_19 ( ! V_22 -> V_36 ) ;
V_22 -> V_40 -- ;
F_2 ( & V_22 -> V_5 ) ;
}
static long F_28 ( struct V_21 * V_22 , long V_23 , long V_24 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_28 * V_29 , * V_31 ;
struct V_28 * V_30 = NULL ;
long V_46 = 0 ;
V_42:
F_9 ( & V_22 -> V_5 ) ;
F_23 (rg, trg, head, link) {
if ( V_29 -> V_33 <= V_23 )
continue;
if ( V_29 -> V_35 >= V_24 )
break;
if ( V_23 > V_29 -> V_35 && V_24 < V_29 -> V_33 ) {
if ( ! V_30 &&
V_22 -> V_36 > V_22 -> V_40 ) {
V_30 = F_20 ( & V_22 -> V_37 ,
struct V_28 ,
V_34 ) ;
F_21 ( & V_30 -> V_34 ) ;
V_22 -> V_36 -- ;
}
if ( ! V_30 ) {
F_2 ( & V_22 -> V_5 ) ;
V_30 = F_25 ( sizeof( * V_30 ) , V_10 ) ;
if ( ! V_30 )
return - V_14 ;
goto V_42;
}
V_46 += V_24 - V_23 ;
V_30 -> V_35 = V_24 ;
V_30 -> V_33 = V_29 -> V_33 ;
F_26 ( & V_30 -> V_34 ) ;
V_29 -> V_33 = V_23 ;
F_22 ( & V_30 -> V_34 , & V_29 -> V_34 ) ;
V_30 = NULL ;
break;
}
if ( V_23 <= V_29 -> V_35 && V_24 >= V_29 -> V_33 ) {
V_46 += V_29 -> V_33 - V_29 -> V_35 ;
F_21 ( & V_29 -> V_34 ) ;
F_4 ( V_29 ) ;
continue;
}
if ( V_23 <= V_29 -> V_35 ) {
V_46 += V_24 - V_29 -> V_35 ;
V_29 -> V_35 = V_24 ;
} else {
V_46 += V_29 -> V_33 - V_23 ;
V_29 -> V_33 = V_23 ;
}
}
F_2 ( & V_22 -> V_5 ) ;
F_4 ( V_30 ) ;
return V_46 ;
}
void F_29 ( struct V_16 * V_16 , bool V_47 )
{
struct V_1 * V_2 = F_13 ( V_16 ) ;
long V_48 ;
V_48 = F_11 ( V_2 , 1 ) ;
if ( V_47 && V_48 ) {
struct V_7 * V_8 = F_30 ( V_16 ) ;
F_3 ( V_8 , 1 ) ;
}
}
static long F_31 ( struct V_21 * V_22 , long V_23 , long V_24 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_28 * V_29 ;
long V_41 = 0 ;
F_9 ( & V_22 -> V_5 ) ;
F_18 (rg, head, link) {
long V_49 ;
long V_50 ;
if ( V_29 -> V_33 <= V_23 )
continue;
if ( V_29 -> V_35 >= V_24 )
break;
V_49 = F_32 ( V_29 -> V_35 , V_23 ) ;
V_50 = F_33 ( V_29 -> V_33 , V_24 ) ;
V_41 += V_50 - V_49 ;
}
F_2 ( & V_22 -> V_5 ) ;
return V_41 ;
}
static T_1 F_34 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_51 )
{
return ( ( V_51 - V_19 -> V_52 ) >> F_35 ( V_8 ) ) +
( V_19 -> V_53 >> F_36 ( V_8 ) ) ;
}
T_1 F_37 ( struct V_18 * V_19 ,
unsigned long V_51 )
{
return F_34 ( F_38 ( V_19 ) , V_19 , V_51 ) ;
}
unsigned long F_39 ( struct V_18 * V_19 )
{
struct V_7 * V_7 ;
if ( ! F_40 ( V_19 ) )
return V_54 ;
V_7 = F_38 ( V_19 ) ;
return 1UL << F_35 ( V_7 ) ;
}
unsigned long F_41 ( struct V_18 * V_19 )
{
return F_39 ( V_19 ) ;
}
static unsigned long F_42 ( struct V_18 * V_19 )
{
return ( unsigned long ) V_19 -> V_55 ;
}
static void F_43 ( struct V_18 * V_19 ,
unsigned long V_56 )
{
V_19 -> V_55 = ( void * ) V_56 ;
}
struct V_21 * F_44 ( void )
{
struct V_21 * V_21 = F_25 ( sizeof( * V_21 ) , V_10 ) ;
struct V_28 * V_29 = F_25 ( sizeof( * V_29 ) , V_10 ) ;
if ( ! V_21 || ! V_29 ) {
F_4 ( V_21 ) ;
F_4 ( V_29 ) ;
return NULL ;
}
F_45 ( & V_21 -> V_57 ) ;
F_7 ( & V_21 -> V_5 ) ;
F_26 ( & V_21 -> V_27 ) ;
V_21 -> V_40 = 0 ;
F_26 ( & V_21 -> V_37 ) ;
F_22 ( & V_29 -> V_34 , & V_21 -> V_37 ) ;
V_21 -> V_36 = 1 ;
return V_21 ;
}
void F_46 ( struct V_58 * V_59 )
{
struct V_21 * V_21 = F_47 ( V_59 , struct V_21 , V_57 ) ;
struct V_25 * V_26 = & V_21 -> V_37 ;
struct V_28 * V_29 , * V_31 ;
F_28 ( V_21 , 0 , V_60 ) ;
F_23 (rg, trg, head, link) {
F_21 ( & V_29 -> V_34 ) ;
F_4 ( V_29 ) ;
}
F_19 ( V_21 -> V_40 ) ;
F_4 ( V_21 ) ;
}
static inline struct V_21 * F_48 ( struct V_16 * V_16 )
{
return V_16 -> V_61 -> V_62 ;
}
static struct V_21 * F_49 ( struct V_18 * V_19 )
{
F_50 ( ! F_40 ( V_19 ) , V_19 ) ;
if ( V_19 -> V_63 & V_64 ) {
struct V_65 * V_66 = V_19 -> V_20 -> V_67 ;
struct V_16 * V_16 = V_66 -> V_68 ;
return F_48 ( V_16 ) ;
} else {
return (struct V_21 * ) ( F_42 ( V_19 ) &
~ V_69 ) ;
}
}
static void F_51 ( struct V_18 * V_19 , struct V_21 * V_70 )
{
F_50 ( ! F_40 ( V_19 ) , V_19 ) ;
F_50 ( V_19 -> V_63 & V_64 , V_19 ) ;
F_43 ( V_19 , ( F_42 ( V_19 ) &
V_69 ) | ( unsigned long ) V_70 ) ;
}
static void F_52 ( struct V_18 * V_19 , unsigned long V_71 )
{
F_50 ( ! F_40 ( V_19 ) , V_19 ) ;
F_50 ( V_19 -> V_63 & V_64 , V_19 ) ;
F_43 ( V_19 , F_42 ( V_19 ) | V_71 ) ;
}
static int F_53 ( struct V_18 * V_19 , unsigned long V_72 )
{
F_50 ( ! F_40 ( V_19 ) , V_19 ) ;
return ( F_42 ( V_19 ) & V_72 ) != 0 ;
}
void F_54 ( struct V_18 * V_19 )
{
F_50 ( ! F_40 ( V_19 ) , V_19 ) ;
if ( ! ( V_19 -> V_63 & V_64 ) )
V_19 -> V_55 = ( void * ) 0 ;
}
static bool F_55 ( struct V_18 * V_19 , long V_41 )
{
if ( V_19 -> V_63 & V_73 ) {
if ( V_19 -> V_63 & V_64 && V_41 == 0 )
return true ;
else
return false ;
}
if ( V_19 -> V_63 & V_64 ) {
if ( V_41 )
return false ;
else
return true ;
}
if ( F_53 ( V_19 , V_74 ) )
return true ;
return false ;
}
static void F_56 ( struct V_7 * V_8 , struct V_75 * V_75 )
{
int V_76 = F_57 ( V_75 ) ;
F_58 ( & V_75 -> V_77 , & V_8 -> V_78 [ V_76 ] ) ;
V_8 -> V_79 ++ ;
V_8 -> V_80 [ V_76 ] ++ ;
}
static struct V_75 * F_59 ( struct V_7 * V_8 , int V_76 )
{
struct V_75 * V_75 ;
F_18 (page, &h->hugepage_freelists[nid], lru)
if ( ! F_60 ( V_75 ) )
break;
if ( & V_8 -> V_78 [ V_76 ] == & V_75 -> V_77 )
return NULL ;
F_58 ( & V_75 -> V_77 , & V_8 -> V_81 ) ;
F_61 ( V_75 ) ;
V_8 -> V_79 -- ;
V_8 -> V_80 [ V_76 ] -- ;
return V_75 ;
}
static inline T_2 F_62 ( struct V_7 * V_8 )
{
if ( V_82 || F_63 ( V_8 ) )
return V_83 ;
else
return V_84 ;
}
static struct V_75 * F_64 ( struct V_7 * V_8 ,
struct V_18 * V_19 ,
unsigned long V_51 , int V_85 ,
long V_41 )
{
struct V_75 * V_75 = NULL ;
struct V_86 * V_87 ;
T_3 * V_88 ;
struct V_89 * V_89 ;
struct V_90 * V_90 ;
struct V_91 * V_92 ;
unsigned int V_93 ;
if ( ! F_55 ( V_19 , V_41 ) &&
V_8 -> V_79 - V_8 -> V_94 == 0 )
goto V_95;
if ( V_85 && V_8 -> V_79 - V_8 -> V_94 == 0 )
goto V_95;
V_96:
V_93 = F_65 () ;
V_89 = F_66 ( V_19 , V_51 ,
F_62 ( V_8 ) , & V_87 , & V_88 ) ;
F_67 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_68 ( V_90 , F_62 ( V_8 ) ) ) {
V_75 = F_59 ( V_8 , F_69 ( V_90 ) ) ;
if ( V_75 ) {
if ( V_85 )
break;
if ( ! F_55 ( V_19 , V_41 ) )
break;
F_70 ( V_75 ) ;
V_8 -> V_94 -- ;
break;
}
}
}
F_71 ( V_87 ) ;
if ( F_72 ( ! V_75 && F_73 ( V_93 ) ) )
goto V_96;
return V_75 ;
V_95:
return NULL ;
}
static int F_74 ( int V_76 , T_3 * V_97 )
{
V_76 = F_75 ( V_76 , * V_97 ) ;
if ( V_76 == V_98 )
V_76 = F_76 ( * V_97 ) ;
F_19 ( V_76 >= V_98 ) ;
return V_76 ;
}
static int F_77 ( int V_76 , T_3 * V_97 )
{
if ( ! F_78 ( V_76 , * V_97 ) )
V_76 = F_74 ( V_76 , V_97 ) ;
return V_76 ;
}
static int F_79 ( struct V_7 * V_8 ,
T_3 * V_97 )
{
int V_76 ;
F_19 ( ! V_97 ) ;
V_76 = F_77 ( V_8 -> V_99 , V_97 ) ;
V_8 -> V_99 = F_74 ( V_76 , V_97 ) ;
return V_76 ;
}
static int F_80 ( struct V_7 * V_8 , T_3 * V_97 )
{
int V_76 ;
F_19 ( ! V_97 ) ;
V_76 = F_77 ( V_8 -> V_100 , V_97 ) ;
V_8 -> V_100 = F_74 ( V_76 , V_97 ) ;
return V_76 ;
}
static void F_81 ( struct V_75 * V_75 ,
unsigned long V_101 )
{
int V_102 ;
int V_103 = 1 << V_101 ;
struct V_75 * V_104 = V_75 + 1 ;
for ( V_102 = 1 ; V_102 < V_103 ; V_102 ++ , V_104 = F_82 ( V_104 , V_75 , V_102 ) ) {
F_83 ( V_104 ) ;
F_61 ( V_104 ) ;
V_104 -> V_105 = NULL ;
}
F_84 ( V_75 , 0 ) ;
F_85 ( V_75 ) ;
}
static void F_86 ( struct V_75 * V_75 , unsigned V_101 )
{
F_87 ( F_88 ( V_75 ) , 1 << V_101 ) ;
}
static int F_89 ( unsigned long V_106 ,
unsigned long V_103 )
{
unsigned long V_107 = V_106 + V_103 ;
return F_90 ( V_106 , V_107 , V_108 ) ;
}
static bool F_91 ( unsigned long V_106 ,
unsigned long V_103 )
{
unsigned long V_102 , V_107 = V_106 + V_103 ;
struct V_75 * V_75 ;
for ( V_102 = V_106 ; V_102 < V_107 ; V_102 ++ ) {
if ( ! F_92 ( V_102 ) )
return false ;
V_75 = F_93 ( V_102 ) ;
if ( F_94 ( V_75 ) )
return false ;
if ( F_95 ( V_75 ) > 0 )
return false ;
if ( F_96 ( V_75 ) )
return false ;
}
return true ;
}
static bool F_97 ( const struct V_90 * V_90 ,
unsigned long V_106 , unsigned long V_103 )
{
unsigned long V_109 = V_106 + V_103 - 1 ;
return F_98 ( V_90 , V_109 ) ;
}
static struct V_75 * F_99 ( int V_76 , unsigned V_101 )
{
unsigned long V_103 = 1 << V_101 ;
unsigned long V_13 , V_110 , V_71 ;
struct V_90 * V_92 ;
V_92 = F_100 ( V_76 ) -> V_111 ;
for (; V_92 - F_100 ( V_76 ) -> V_111 < V_112 ; V_92 ++ ) {
F_101 ( & V_92 -> V_5 , V_71 ) ;
V_110 = F_102 ( V_92 -> V_113 , V_103 ) ;
while ( F_97 ( V_92 , V_110 , V_103 ) ) {
if ( F_91 ( V_110 , V_103 ) ) {
F_103 ( & V_92 -> V_5 , V_71 ) ;
V_13 = F_89 ( V_110 , V_103 ) ;
if ( ! V_13 )
return F_93 ( V_110 ) ;
F_101 ( & V_92 -> V_5 , V_71 ) ;
}
V_110 += V_103 ;
}
F_103 ( & V_92 -> V_5 , V_71 ) ;
}
return NULL ;
}
static struct V_75 * F_104 ( struct V_7 * V_8 , int V_76 )
{
struct V_75 * V_75 ;
V_75 = F_99 ( V_76 , F_36 ( V_8 ) ) ;
if ( V_75 ) {
F_105 ( V_75 , F_36 ( V_8 ) ) ;
F_106 ( V_8 , V_75 , V_76 ) ;
}
return V_75 ;
}
static int F_107 ( struct V_7 * V_8 ,
T_3 * V_97 )
{
struct V_75 * V_75 = NULL ;
int V_114 , V_115 ;
F_108 (h, nr_nodes, node, nodes_allowed) {
V_75 = F_104 ( V_8 , V_115 ) ;
if ( V_75 )
return 1 ;
}
return 0 ;
}
static inline bool F_109 ( void ) { return true ; }
static inline bool F_109 ( void ) { return false ; }
static inline void F_86 ( struct V_75 * V_75 , unsigned V_101 ) { }
static inline void F_81 ( struct V_75 * V_75 ,
unsigned long V_101 ) { }
static inline int F_107 ( struct V_7 * V_8 ,
T_3 * V_97 ) { return 0 ; }
static void F_110 ( struct V_7 * V_8 , struct V_75 * V_75 )
{
int V_102 ;
if ( F_111 ( V_8 ) && ! F_109 () )
return;
V_8 -> V_116 -- ;
V_8 -> V_117 [ F_57 ( V_75 ) ] -- ;
for ( V_102 = 0 ; V_102 < F_112 ( V_8 ) ; V_102 ++ ) {
V_75 [ V_102 ] . V_71 &= ~ ( 1 << V_118 | 1 << V_119 |
1 << V_120 | 1 << V_121 |
1 << V_122 | 1 << V_123 |
1 << V_124 ) ;
}
F_113 ( F_114 ( V_75 ) , V_75 ) ;
F_115 ( V_75 , NULL ) ;
F_61 ( V_75 ) ;
if ( F_111 ( V_8 ) ) {
F_81 ( V_75 , F_36 ( V_8 ) ) ;
F_86 ( V_75 , F_36 ( V_8 ) ) ;
} else {
F_116 ( V_75 , F_36 ( V_8 ) ) ;
}
}
struct V_7 * F_117 ( unsigned long V_125 )
{
struct V_7 * V_8 ;
F_118 (h) {
if ( F_119 ( V_8 ) == V_125 )
return V_8 ;
}
return NULL ;
}
bool F_120 ( struct V_75 * V_75 )
{
F_113 ( ! F_96 ( V_75 ) , V_75 ) ;
return F_121 ( V_75 ) && F_122 ( & V_75 [ 1 ] ) ;
}
static void F_123 ( struct V_75 * V_75 )
{
F_113 ( ! F_124 ( V_75 ) , V_75 ) ;
F_70 ( & V_75 [ 1 ] ) ;
}
static void F_125 ( struct V_75 * V_75 )
{
F_113 ( ! F_124 ( V_75 ) , V_75 ) ;
F_126 ( & V_75 [ 1 ] ) ;
}
void F_127 ( struct V_75 * V_75 )
{
struct V_7 * V_8 = F_128 ( V_75 ) ;
int V_76 = F_57 ( V_75 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_129 ( V_75 ) ;
bool V_47 ;
F_130 ( V_75 , 0 ) ;
V_75 -> V_66 = NULL ;
F_10 ( F_95 ( V_75 ) ) ;
F_10 ( F_131 ( V_75 ) ) ;
V_47 = F_122 ( V_75 ) ;
F_126 ( V_75 ) ;
if ( F_12 ( V_2 , 1 ) == 0 )
V_47 = true ;
F_9 ( & V_126 ) ;
F_125 ( V_75 ) ;
F_132 ( F_133 ( V_8 ) ,
F_112 ( V_8 ) , V_75 ) ;
if ( V_47 )
V_8 -> V_94 ++ ;
if ( V_8 -> V_127 [ V_76 ] ) {
F_21 ( & V_75 -> V_77 ) ;
F_110 ( V_8 , V_75 ) ;
V_8 -> V_128 -- ;
V_8 -> V_127 [ V_76 ] -- ;
} else {
F_134 ( V_75 ) ;
F_56 ( V_8 , V_75 ) ;
}
F_2 ( & V_126 ) ;
}
static void F_106 ( struct V_7 * V_8 , struct V_75 * V_75 , int V_76 )
{
F_26 ( & V_75 -> V_77 ) ;
F_115 ( V_75 , F_127 ) ;
F_9 ( & V_126 ) ;
F_135 ( V_75 , NULL ) ;
V_8 -> V_116 ++ ;
V_8 -> V_117 [ V_76 ] ++ ;
F_2 ( & V_126 ) ;
F_136 ( V_75 ) ;
}
static void F_105 ( struct V_75 * V_75 , unsigned long V_101 )
{
int V_102 ;
int V_103 = 1 << V_101 ;
struct V_75 * V_104 = V_75 + 1 ;
F_84 ( V_75 , V_101 ) ;
F_137 ( V_75 ) ;
F_138 ( V_75 ) ;
for ( V_102 = 1 ; V_102 < V_103 ; V_102 ++ , V_104 = F_82 ( V_104 , V_75 , V_102 ) ) {
F_138 ( V_104 ) ;
F_139 ( V_104 , 0 ) ;
V_104 -> V_105 = V_75 ;
F_140 () ;
F_141 ( V_104 ) ;
}
}
int F_96 ( struct V_75 * V_75 )
{
if ( ! F_142 ( V_75 ) )
return 0 ;
V_75 = F_143 ( V_75 ) ;
return F_144 ( V_75 ) == F_127 ;
}
int F_124 ( struct V_75 * V_129 )
{
if ( ! F_121 ( V_129 ) )
return 0 ;
return F_144 ( V_129 ) == F_127 ;
}
T_1 F_145 ( struct V_75 * V_75 )
{
struct V_75 * V_129 = F_143 ( V_75 ) ;
T_1 V_130 = F_146 ( V_129 ) ;
unsigned long V_131 ;
if ( ! F_96 ( V_129 ) )
return F_146 ( V_75 ) ;
if ( F_147 ( V_129 ) >= V_132 )
V_131 = F_88 ( V_75 ) - F_88 ( V_129 ) ;
else
V_131 = V_75 - V_129 ;
return ( V_130 << F_147 ( V_129 ) ) + V_131 ;
}
static struct V_75 * F_148 ( struct V_7 * V_8 , int V_76 )
{
struct V_75 * V_75 ;
V_75 = F_149 ( V_76 ,
F_62 ( V_8 ) | V_133 | V_134 |
V_135 | V_136 ,
F_36 ( V_8 ) ) ;
if ( V_75 ) {
F_106 ( V_8 , V_75 , V_76 ) ;
}
return V_75 ;
}
static int F_150 ( struct V_7 * V_8 , T_3 * V_97 )
{
struct V_75 * V_75 ;
int V_114 , V_115 ;
int V_13 = 0 ;
F_108 (h, nr_nodes, node, nodes_allowed) {
V_75 = F_148 ( V_8 , V_115 ) ;
if ( V_75 ) {
V_13 = 1 ;
break;
}
}
if ( V_13 )
F_151 ( V_137 ) ;
else
F_151 ( V_138 ) ;
return V_13 ;
}
static int F_152 ( struct V_7 * V_8 , T_3 * V_97 ,
bool V_139 )
{
int V_114 , V_115 ;
int V_13 = 0 ;
F_153 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_139 || V_8 -> V_127 [ V_115 ] ) &&
! F_154 ( & V_8 -> V_78 [ V_115 ] ) ) {
struct V_75 * V_75 =
F_155 ( V_8 -> V_78 [ V_115 ] . V_140 ,
struct V_75 , V_77 ) ;
F_21 ( & V_75 -> V_77 ) ;
V_8 -> V_79 -- ;
V_8 -> V_80 [ V_115 ] -- ;
if ( V_139 ) {
V_8 -> V_128 -- ;
V_8 -> V_127 [ V_115 ] -- ;
}
F_110 ( V_8 , V_75 ) ;
V_13 = 1 ;
break;
}
}
return V_13 ;
}
static void F_156 ( struct V_75 * V_75 )
{
F_9 ( & V_126 ) ;
if ( F_96 ( V_75 ) && ! F_95 ( V_75 ) ) {
struct V_7 * V_8 = F_128 ( V_75 ) ;
int V_76 = F_57 ( V_75 ) ;
F_21 ( & V_75 -> V_77 ) ;
V_8 -> V_79 -- ;
V_8 -> V_80 [ V_76 ] -- ;
F_110 ( V_8 , V_75 ) ;
}
F_2 ( & V_126 ) ;
}
void F_157 ( unsigned long V_106 , unsigned long V_107 )
{
unsigned long V_110 ;
if ( ! F_158 () )
return;
F_19 ( ! F_159 ( V_106 , 1 << V_141 ) ) ;
for ( V_110 = V_106 ; V_110 < V_107 ; V_110 += 1 << V_141 )
F_156 ( F_93 ( V_110 ) ) ;
}
static struct V_75 * F_160 ( struct V_7 * V_8 , int V_76 )
{
struct V_75 * V_75 ;
unsigned int V_142 ;
if ( F_111 ( V_8 ) )
return NULL ;
F_9 ( & V_126 ) ;
if ( V_8 -> V_128 >= V_8 -> V_143 ) {
F_2 ( & V_126 ) ;
return NULL ;
} else {
V_8 -> V_116 ++ ;
V_8 -> V_128 ++ ;
}
F_2 ( & V_126 ) ;
if ( V_76 == V_144 )
V_75 = F_161 ( F_62 ( V_8 ) | V_133 |
V_135 | V_136 ,
F_36 ( V_8 ) ) ;
else
V_75 = F_149 ( V_76 ,
F_62 ( V_8 ) | V_133 | V_134 |
V_135 | V_136 , F_36 ( V_8 ) ) ;
F_9 ( & V_126 ) ;
if ( V_75 ) {
F_26 ( & V_75 -> V_77 ) ;
V_142 = F_57 ( V_75 ) ;
F_115 ( V_75 , F_127 ) ;
F_135 ( V_75 , NULL ) ;
V_8 -> V_117 [ V_142 ] ++ ;
V_8 -> V_127 [ V_142 ] ++ ;
F_162 ( V_137 ) ;
} else {
V_8 -> V_116 -- ;
V_8 -> V_128 -- ;
F_162 ( V_138 ) ;
}
F_2 ( & V_126 ) ;
return V_75 ;
}
struct V_75 * F_163 ( struct V_7 * V_8 , int V_76 )
{
struct V_75 * V_75 = NULL ;
F_9 ( & V_126 ) ;
if ( V_8 -> V_79 - V_8 -> V_94 > 0 )
V_75 = F_59 ( V_8 , V_76 ) ;
F_2 ( & V_126 ) ;
if ( ! V_75 )
V_75 = F_160 ( V_8 , V_76 ) ;
return V_75 ;
}
static int F_164 ( struct V_7 * V_8 , int V_12 )
{
struct V_25 V_145 ;
struct V_75 * V_75 , * V_146 ;
int V_13 , V_102 ;
int V_147 , V_148 ;
bool V_149 = true ;
V_147 = ( V_8 -> V_94 + V_12 ) - V_8 -> V_79 ;
if ( V_147 <= 0 ) {
V_8 -> V_94 += V_12 ;
return 0 ;
}
V_148 = 0 ;
F_26 ( & V_145 ) ;
V_13 = - V_14 ;
V_42:
F_2 ( & V_126 ) ;
for ( V_102 = 0 ; V_102 < V_147 ; V_102 ++ ) {
V_75 = F_160 ( V_8 , V_144 ) ;
if ( ! V_75 ) {
V_149 = false ;
break;
}
F_22 ( & V_75 -> V_77 , & V_145 ) ;
}
V_148 += V_102 ;
F_9 ( & V_126 ) ;
V_147 = ( V_8 -> V_94 + V_12 ) -
( V_8 -> V_79 + V_148 ) ;
if ( V_147 > 0 ) {
if ( V_149 )
goto V_42;
goto free;
}
V_147 += V_148 ;
V_8 -> V_94 += V_12 ;
V_13 = 0 ;
F_23 (page, tmp, &surplus_list, lru) {
if ( ( -- V_147 ) < 0 )
break;
F_165 ( V_75 ) ;
F_113 ( F_95 ( V_75 ) , V_75 ) ;
F_56 ( V_8 , V_75 ) ;
}
free:
F_2 ( & V_126 ) ;
F_23 (page, tmp, &surplus_list, lru)
F_136 ( V_75 ) ;
F_9 ( & V_126 ) ;
return V_13 ;
}
static void F_166 ( struct V_7 * V_8 ,
unsigned long V_150 )
{
unsigned long V_103 ;
V_8 -> V_94 -= V_150 ;
if ( F_111 ( V_8 ) )
return;
V_103 = F_33 ( V_150 , V_8 -> V_128 ) ;
while ( V_103 -- ) {
if ( ! F_152 ( V_8 , & V_151 [ V_152 ] , 1 ) )
break;
F_167 ( & V_126 ) ;
}
}
static long F_168 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_153 ,
enum V_154 V_155 )
{
struct V_21 * V_22 ;
T_1 V_156 ;
long V_13 ;
V_22 = F_49 ( V_19 ) ;
if ( ! V_22 )
return 1 ;
V_156 = F_34 ( V_8 , V_19 , V_153 ) ;
switch ( V_155 ) {
case V_157 :
V_13 = F_24 ( V_22 , V_156 , V_156 + 1 ) ;
break;
case V_158 :
V_13 = F_17 ( V_22 , V_156 , V_156 + 1 ) ;
break;
case V_159 :
F_27 ( V_22 , V_156 , V_156 + 1 ) ;
V_13 = 0 ;
break;
default:
F_169 () ;
}
if ( V_19 -> V_63 & V_64 )
return V_13 ;
else
return V_13 < 0 ? V_13 : 0 ;
}
static long F_170 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_153 )
{
return F_168 ( V_8 , V_19 , V_153 , V_157 ) ;
}
static long F_171 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_153 )
{
return F_168 ( V_8 , V_19 , V_153 , V_158 ) ;
}
static void F_172 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_153 )
{
( void ) F_168 ( V_8 , V_19 , V_153 , V_159 ) ;
}
struct V_75 * F_173 ( struct V_18 * V_19 ,
unsigned long V_153 , int V_85 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_75 * V_75 ;
long V_160 , V_161 ;
long V_162 ;
int V_13 , V_156 ;
struct V_163 * V_164 ;
V_156 = F_133 ( V_8 ) ;
V_160 = V_162 = F_170 ( V_8 , V_19 , V_153 ) ;
if ( V_160 < 0 )
return F_174 ( - V_14 ) ;
if ( V_160 || V_85 ) {
V_162 = F_11 ( V_2 , 1 ) ;
if ( V_162 < 0 ) {
F_172 ( V_8 , V_19 , V_153 ) ;
return F_174 ( - V_165 ) ;
}
if ( V_85 )
V_162 = 1 ;
}
V_13 = F_175 ( V_156 , F_112 ( V_8 ) , & V_164 ) ;
if ( V_13 )
goto V_166;
F_9 ( & V_126 ) ;
V_75 = F_64 ( V_8 , V_19 , V_153 , V_85 , V_162 ) ;
if ( ! V_75 ) {
F_2 ( & V_126 ) ;
V_75 = F_160 ( V_8 , V_144 ) ;
if ( ! V_75 )
goto V_167;
F_9 ( & V_126 ) ;
F_58 ( & V_75 -> V_77 , & V_8 -> V_81 ) ;
}
F_176 ( V_156 , F_112 ( V_8 ) , V_164 , V_75 ) ;
F_2 ( & V_126 ) ;
F_130 ( V_75 , ( unsigned long ) V_2 ) ;
V_161 = F_171 ( V_8 , V_19 , V_153 ) ;
if ( F_72 ( V_160 > V_161 ) ) {
long V_48 ;
V_48 = F_12 ( V_2 , 1 ) ;
F_3 ( V_8 , - V_48 ) ;
}
return V_75 ;
V_167:
F_177 ( V_156 , F_112 ( V_8 ) , V_164 ) ;
V_166:
if ( V_160 || V_85 )
F_12 ( V_2 , 1 ) ;
F_172 ( V_8 , V_19 , V_153 ) ;
return F_174 ( - V_165 ) ;
}
struct V_75 * F_178 ( struct V_18 * V_19 ,
unsigned long V_153 , int V_85 )
{
struct V_75 * V_75 = F_173 ( V_19 , V_153 , V_85 ) ;
if ( F_179 ( V_75 ) )
V_75 = NULL ;
return V_75 ;
}
int __weak F_180 ( struct V_7 * V_8 )
{
struct V_168 * V_169 ;
int V_114 , V_115 ;
F_108 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_153 ;
V_153 = F_181 (
F_119 ( V_8 ) , F_119 ( V_8 ) ,
0 , V_170 , V_115 ) ;
if ( V_153 ) {
V_169 = V_153 ;
goto V_171;
}
}
return 0 ;
V_171:
F_10 ( ! F_159 ( F_182 ( V_169 ) , F_119 ( V_8 ) ) ) ;
F_22 ( & V_169 -> V_172 , & V_173 ) ;
V_169 -> V_7 = V_8 ;
return 1 ;
}
static void T_4 F_183 ( struct V_75 * V_75 , int V_101 )
{
if ( F_72 ( V_101 > ( V_132 - 1 ) ) )
F_105 ( V_75 , V_101 ) ;
else
F_184 ( V_75 , V_101 ) ;
}
static void T_4 F_185 ( void )
{
struct V_168 * V_169 ;
F_18 (m, &huge_boot_pages, list) {
struct V_7 * V_8 = V_169 -> V_7 ;
struct V_75 * V_75 ;
#ifdef F_186
V_75 = F_93 ( V_169 -> V_174 >> V_175 ) ;
F_187 ( F_188 ( V_169 ) ,
sizeof( struct V_168 ) ) ;
#else
V_75 = F_189 ( V_169 ) ;
#endif
F_190 ( F_95 ( V_75 ) != 1 ) ;
F_183 ( V_75 , V_8 -> V_101 ) ;
F_190 ( F_94 ( V_75 ) ) ;
F_106 ( V_8 , V_75 , F_57 ( V_75 ) ) ;
if ( F_111 ( V_8 ) )
F_191 ( V_75 , 1 << V_8 -> V_101 ) ;
}
}
static void T_4 F_192 ( struct V_7 * V_8 )
{
unsigned long V_102 ;
for ( V_102 = 0 ; V_102 < V_8 -> V_176 ; ++ V_102 ) {
if ( F_111 ( V_8 ) ) {
if ( ! F_180 ( V_8 ) )
break;
} else if ( ! F_150 ( V_8 ,
& V_151 [ V_152 ] ) )
break;
}
V_8 -> V_176 = V_102 ;
}
static void T_4 F_193 ( void )
{
struct V_7 * V_8 ;
F_118 (h) {
if ( V_141 > F_36 ( V_8 ) )
V_141 = F_36 ( V_8 ) ;
if ( ! F_111 ( V_8 ) )
F_192 ( V_8 ) ;
}
F_19 ( V_141 == V_177 ) ;
}
static char * T_4 F_194 ( char * V_178 , unsigned long V_179 )
{
if ( V_179 >= ( 1UL << 30 ) )
sprintf ( V_178 , L_1 , V_179 >> 30 ) ;
else if ( V_179 >= ( 1UL << 20 ) )
sprintf ( V_178 , L_2 , V_179 >> 20 ) ;
else
sprintf ( V_178 , L_3 , V_179 >> 10 ) ;
return V_178 ;
}
static void T_4 F_195 ( void )
{
struct V_7 * V_8 ;
F_118 (h) {
char V_178 [ 32 ] ;
F_196 ( L_4 ,
F_194 ( V_178 , F_119 ( V_8 ) ) ,
V_8 -> V_79 ) ;
}
}
static void F_197 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_97 )
{
int V_102 ;
if ( F_111 ( V_8 ) )
return;
F_198 (i, *nodes_allowed) {
struct V_75 * V_75 , * V_140 ;
struct V_25 * V_180 = & V_8 -> V_78 [ V_102 ] ;
F_23 (page, next, freel, lru) {
if ( V_3 >= V_8 -> V_116 )
return;
if ( F_199 ( V_75 ) )
continue;
F_21 ( & V_75 -> V_77 ) ;
F_110 ( V_8 , V_75 ) ;
V_8 -> V_79 -- ;
V_8 -> V_80 [ F_57 ( V_75 ) ] -- ;
}
}
}
static inline void F_197 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_97 )
{
}
static int F_200 ( struct V_7 * V_8 , T_3 * V_97 ,
int V_12 )
{
int V_114 , V_115 ;
F_19 ( V_12 != - 1 && V_12 != 1 ) ;
if ( V_12 < 0 ) {
F_108 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_127 [ V_115 ] )
goto V_171;
}
} else {
F_153 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_127 [ V_115 ] <
V_8 -> V_117 [ V_115 ] )
goto V_171;
}
}
return 0 ;
V_171:
V_8 -> V_128 += V_12 ;
V_8 -> V_127 [ V_115 ] += V_12 ;
return 1 ;
}
static unsigned long F_201 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_97 )
{
unsigned long V_181 , V_13 ;
if ( F_111 ( V_8 ) && ! F_109 () )
return V_8 -> V_176 ;
F_9 ( & V_126 ) ;
while ( V_8 -> V_128 && V_3 > F_202 ( V_8 ) ) {
if ( ! F_200 ( V_8 , V_97 , - 1 ) )
break;
}
while ( V_3 > F_202 ( V_8 ) ) {
F_2 ( & V_126 ) ;
if ( F_111 ( V_8 ) )
V_13 = F_107 ( V_8 , V_97 ) ;
else
V_13 = F_150 ( V_8 , V_97 ) ;
F_9 ( & V_126 ) ;
if ( ! V_13 )
goto V_45;
if ( F_203 ( V_182 ) )
goto V_45;
}
V_181 = V_8 -> V_94 + V_8 -> V_116 - V_8 -> V_79 ;
V_181 = F_32 ( V_3 , V_181 ) ;
F_197 ( V_8 , V_181 , V_97 ) ;
while ( V_181 < F_202 ( V_8 ) ) {
if ( ! F_152 ( V_8 , V_97 , 0 ) )
break;
F_167 ( & V_126 ) ;
}
while ( V_3 < F_202 ( V_8 ) ) {
if ( ! F_200 ( V_8 , V_97 , 1 ) )
break;
}
V_45:
V_13 = F_202 ( V_8 ) ;
F_2 ( & V_126 ) ;
return V_13 ;
}
static struct V_7 * F_204 ( struct V_183 * V_184 , int * V_185 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_186 ; V_102 ++ )
if ( V_187 [ V_102 ] == V_184 ) {
if ( V_185 )
* V_185 = V_144 ;
return & V_188 [ V_102 ] ;
}
return F_205 ( V_184 , V_185 ) ;
}
static T_5 F_206 ( struct V_183 * V_184 ,
struct V_189 * V_190 , char * V_178 )
{
struct V_7 * V_8 ;
unsigned long V_116 ;
int V_76 ;
V_8 = F_204 ( V_184 , & V_76 ) ;
if ( V_76 == V_144 )
V_116 = V_8 -> V_116 ;
else
V_116 = V_8 -> V_117 [ V_76 ] ;
return sprintf ( V_178 , L_5 , V_116 ) ;
}
static T_5 F_207 ( bool V_191 ,
struct V_7 * V_8 , int V_76 ,
unsigned long V_3 , T_6 V_192 )
{
int V_95 ;
F_208 ( T_3 , V_97 , V_10 | V_193 ) ;
if ( F_111 ( V_8 ) && ! F_109 () ) {
V_95 = - V_194 ;
goto V_45;
}
if ( V_76 == V_144 ) {
if ( ! ( V_191 &&
F_209 ( V_97 ) ) ) {
F_210 ( V_97 ) ;
V_97 = & V_151 [ V_152 ] ;
}
} else if ( V_97 ) {
V_3 += V_8 -> V_116 - V_8 -> V_117 [ V_76 ] ;
F_211 ( V_97 , V_76 ) ;
} else
V_97 = & V_151 [ V_152 ] ;
V_8 -> V_176 = F_201 ( V_8 , V_3 , V_97 ) ;
if ( V_97 != & V_151 [ V_152 ] )
F_210 ( V_97 ) ;
return V_192 ;
V_45:
F_210 ( V_97 ) ;
return V_95 ;
}
static T_5 F_212 ( bool V_191 ,
struct V_183 * V_184 , const char * V_178 ,
T_6 V_192 )
{
struct V_7 * V_8 ;
unsigned long V_3 ;
int V_76 ;
int V_95 ;
V_95 = F_213 ( V_178 , 10 , & V_3 ) ;
if ( V_95 )
return V_95 ;
V_8 = F_204 ( V_184 , & V_76 ) ;
return F_207 ( V_191 , V_8 , V_76 , V_3 , V_192 ) ;
}
static T_5 F_214 ( struct V_183 * V_184 ,
struct V_189 * V_190 , char * V_178 )
{
return F_206 ( V_184 , V_190 , V_178 ) ;
}
static T_5 F_215 ( struct V_183 * V_184 ,
struct V_189 * V_190 , const char * V_178 , T_6 V_192 )
{
return F_212 ( false , V_184 , V_178 , V_192 ) ;
}
static T_5 F_216 ( struct V_183 * V_184 ,
struct V_189 * V_190 , char * V_178 )
{
return F_206 ( V_184 , V_190 , V_178 ) ;
}
static T_5 F_217 ( struct V_183 * V_184 ,
struct V_189 * V_190 , const char * V_178 , T_6 V_192 )
{
return F_212 ( true , V_184 , V_178 , V_192 ) ;
}
static T_5 F_218 ( struct V_183 * V_184 ,
struct V_189 * V_190 , char * V_178 )
{
struct V_7 * V_8 = F_204 ( V_184 , NULL ) ;
return sprintf ( V_178 , L_5 , V_8 -> V_143 ) ;
}
static T_5 F_219 ( struct V_183 * V_184 ,
struct V_189 * V_190 , const char * V_178 , T_6 V_3 )
{
int V_95 ;
unsigned long V_195 ;
struct V_7 * V_8 = F_204 ( V_184 , NULL ) ;
if ( F_111 ( V_8 ) )
return - V_194 ;
V_95 = F_213 ( V_178 , 10 , & V_195 ) ;
if ( V_95 )
return V_95 ;
F_9 ( & V_126 ) ;
V_8 -> V_143 = V_195 ;
F_2 ( & V_126 ) ;
return V_3 ;
}
static T_5 F_220 ( struct V_183 * V_184 ,
struct V_189 * V_190 , char * V_178 )
{
struct V_7 * V_8 ;
unsigned long V_79 ;
int V_76 ;
V_8 = F_204 ( V_184 , & V_76 ) ;
if ( V_76 == V_144 )
V_79 = V_8 -> V_79 ;
else
V_79 = V_8 -> V_80 [ V_76 ] ;
return sprintf ( V_178 , L_5 , V_79 ) ;
}
static T_5 F_221 ( struct V_183 * V_184 ,
struct V_189 * V_190 , char * V_178 )
{
struct V_7 * V_8 = F_204 ( V_184 , NULL ) ;
return sprintf ( V_178 , L_5 , V_8 -> V_94 ) ;
}
static T_5 F_222 ( struct V_183 * V_184 ,
struct V_189 * V_190 , char * V_178 )
{
struct V_7 * V_8 ;
unsigned long V_128 ;
int V_76 ;
V_8 = F_204 ( V_184 , & V_76 ) ;
if ( V_76 == V_144 )
V_128 = V_8 -> V_128 ;
else
V_128 = V_8 -> V_127 [ V_76 ] ;
return sprintf ( V_178 , L_5 , V_128 ) ;
}
static int F_223 ( struct V_7 * V_8 , struct V_183 * V_196 ,
struct V_183 * * V_187 ,
struct V_197 * V_198 )
{
int V_199 ;
int V_200 = F_133 ( V_8 ) ;
V_187 [ V_200 ] = F_224 ( V_8 -> V_201 , V_196 ) ;
if ( ! V_187 [ V_200 ] )
return - V_14 ;
V_199 = F_225 ( V_187 [ V_200 ] , V_198 ) ;
if ( V_199 )
F_226 ( V_187 [ V_200 ] ) ;
return V_199 ;
}
static void T_4 F_227 ( void )
{
struct V_7 * V_8 ;
int V_95 ;
V_202 = F_224 ( L_6 , V_203 ) ;
if ( ! V_202 )
return;
F_118 (h) {
V_95 = F_223 ( V_8 , V_202 ,
V_187 , & V_198 ) ;
if ( V_95 )
F_228 ( L_7 , V_8 -> V_201 ) ;
}
}
static struct V_7 * F_205 ( struct V_183 * V_184 , int * V_185 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_204 ; V_76 ++ ) {
struct V_205 * V_206 = & V_207 [ V_76 ] ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_186 ; V_102 ++ )
if ( V_206 -> V_187 [ V_102 ] == V_184 ) {
if ( V_185 )
* V_185 = V_76 ;
return & V_188 [ V_102 ] ;
}
}
F_169 () ;
return NULL ;
}
static void F_229 ( struct V_115 * V_115 )
{
struct V_7 * V_8 ;
struct V_205 * V_206 = & V_207 [ V_115 -> V_208 . V_209 ] ;
if ( ! V_206 -> V_202 )
return;
F_118 (h) {
int V_156 = F_133 ( V_8 ) ;
if ( V_206 -> V_187 [ V_156 ] ) {
F_226 ( V_206 -> V_187 [ V_156 ] ) ;
V_206 -> V_187 [ V_156 ] = NULL ;
}
}
F_226 ( V_206 -> V_202 ) ;
V_206 -> V_202 = NULL ;
}
static void F_230 ( void )
{
int V_76 ;
F_231 ( NULL , NULL ) ;
for ( V_76 = 0 ; V_76 < V_204 ; V_76 ++ )
F_229 ( V_210 [ V_76 ] ) ;
}
static void F_232 ( struct V_115 * V_115 )
{
struct V_7 * V_8 ;
struct V_205 * V_206 = & V_207 [ V_115 -> V_208 . V_209 ] ;
int V_95 ;
if ( V_206 -> V_202 )
return;
V_206 -> V_202 = F_224 ( L_6 ,
& V_115 -> V_208 . V_184 ) ;
if ( ! V_206 -> V_202 )
return;
F_118 (h) {
V_95 = F_223 ( V_8 , V_206 -> V_202 ,
V_206 -> V_187 ,
& V_211 ) ;
if ( V_95 ) {
F_228 ( L_8 ,
V_8 -> V_201 , V_115 -> V_208 . V_209 ) ;
F_229 ( V_115 ) ;
break;
}
}
}
static void T_4 F_233 ( void )
{
int V_76 ;
F_234 (nid, N_MEMORY) {
struct V_115 * V_115 = V_210 [ V_76 ] ;
if ( V_115 -> V_208 . V_209 == V_76 )
F_232 ( V_115 ) ;
}
F_231 ( F_232 ,
F_229 ) ;
}
static struct V_7 * F_205 ( struct V_183 * V_184 , int * V_185 )
{
F_169 () ;
if ( V_185 )
* V_185 = - 1 ;
return NULL ;
}
static void F_230 ( void ) { }
static void F_233 ( void ) { }
static void T_7 F_235 ( void )
{
struct V_7 * V_8 ;
F_230 () ;
F_118 (h) {
F_226 ( V_187 [ F_133 ( V_8 ) ] ) ;
}
F_226 ( V_202 ) ;
F_4 ( V_212 ) ;
}
static int T_4 F_236 ( void )
{
int V_102 ;
if ( ! F_158 () )
return 0 ;
if ( ! F_117 ( V_213 ) ) {
V_213 = V_214 ;
if ( ! F_117 ( V_213 ) )
F_237 ( V_215 ) ;
}
V_216 = F_133 ( F_117 ( V_213 ) ) ;
if ( V_217 )
V_218 . V_176 = V_217 ;
F_193 () ;
F_185 () ;
F_195 () ;
F_227 () ;
F_233 () ;
F_238 () ;
#ifdef F_239
V_219 = F_240 ( 8 * F_241 () ) ;
#else
V_219 = 1 ;
#endif
V_212 =
F_25 ( sizeof( struct V_220 ) * V_219 , V_10 ) ;
F_10 ( ! V_212 ) ;
for ( V_102 = 0 ; V_102 < V_219 ; V_102 ++ )
F_242 ( & V_212 [ V_102 ] ) ;
return 0 ;
}
void T_4 F_237 ( unsigned V_101 )
{
struct V_7 * V_8 ;
unsigned long V_102 ;
if ( F_117 ( V_54 << V_101 ) ) {
F_243 ( L_9 ) ;
return;
}
F_10 ( V_221 >= V_186 ) ;
F_10 ( V_101 == 0 ) ;
V_8 = & V_188 [ V_221 ++ ] ;
V_8 -> V_101 = V_101 ;
V_8 -> V_222 = ~ ( ( 1ULL << ( V_101 + V_175 ) ) - 1 ) ;
V_8 -> V_116 = 0 ;
V_8 -> V_79 = 0 ;
for ( V_102 = 0 ; V_102 < V_98 ; ++ V_102 )
F_26 ( & V_8 -> V_78 [ V_102 ] ) ;
F_26 ( & V_8 -> V_81 ) ;
V_8 -> V_99 = F_76 ( V_151 [ V_152 ] ) ;
V_8 -> V_100 = F_76 ( V_151 [ V_152 ] ) ;
snprintf ( V_8 -> V_201 , V_223 , L_10 ,
F_119 ( V_8 ) / 1024 ) ;
V_224 = V_8 ;
}
static int T_4 F_244 ( char * V_225 )
{
unsigned long * V_226 ;
static unsigned long * V_227 ;
if ( ! V_221 )
V_226 = & V_217 ;
else
V_226 = & V_224 -> V_176 ;
if ( V_226 == V_227 ) {
F_243 ( L_11
L_12 ) ;
return 1 ;
}
if ( sscanf ( V_225 , L_13 , V_226 ) <= 0 )
* V_226 = 0 ;
if ( V_221 && V_224 -> V_101 >= V_132 )
F_192 ( V_224 ) ;
V_227 = V_226 ;
return 1 ;
}
static int T_4 F_245 ( char * V_225 )
{
V_213 = F_246 ( V_225 , & V_225 ) ;
return 1 ;
}
static unsigned int F_247 ( unsigned int * V_228 )
{
int V_115 ;
unsigned int V_229 = 0 ;
F_198 (node, cpuset_current_mems_allowed)
V_229 += V_228 [ V_115 ] ;
return V_229 ;
}
static int F_248 ( bool V_191 ,
struct V_230 * V_231 , int V_232 ,
void T_8 * V_233 , T_6 * V_234 , T_9 * V_235 )
{
struct V_7 * V_8 = & V_218 ;
unsigned long V_146 = V_8 -> V_176 ;
int V_13 ;
if ( ! F_158 () )
return - V_236 ;
V_231 -> V_237 = & V_146 ;
V_231 -> V_238 = sizeof( unsigned long ) ;
V_13 = F_249 ( V_231 , V_232 , V_233 , V_234 , V_235 ) ;
if ( V_13 )
goto V_45;
if ( V_232 )
V_13 = F_207 ( V_191 , V_8 ,
V_144 , V_146 , * V_234 ) ;
V_45:
return V_13 ;
}
int F_250 ( struct V_230 * V_231 , int V_232 ,
void T_8 * V_233 , T_6 * V_234 , T_9 * V_235 )
{
return F_248 ( false , V_231 , V_232 ,
V_233 , V_234 , V_235 ) ;
}
int F_251 ( struct V_230 * V_231 , int V_232 ,
void T_8 * V_233 , T_6 * V_234 , T_9 * V_235 )
{
return F_248 ( true , V_231 , V_232 ,
V_233 , V_234 , V_235 ) ;
}
int F_252 ( struct V_230 * V_231 , int V_232 ,
void T_8 * V_233 ,
T_6 * V_234 , T_9 * V_235 )
{
struct V_7 * V_8 = & V_218 ;
unsigned long V_146 ;
int V_13 ;
if ( ! F_158 () )
return - V_236 ;
V_146 = V_8 -> V_143 ;
if ( V_232 && F_111 ( V_8 ) )
return - V_194 ;
V_231 -> V_237 = & V_146 ;
V_231 -> V_238 = sizeof( unsigned long ) ;
V_13 = F_249 ( V_231 , V_232 , V_233 , V_234 , V_235 ) ;
if ( V_13 )
goto V_45;
if ( V_232 ) {
F_9 ( & V_126 ) ;
V_8 -> V_143 = V_146 ;
F_2 ( & V_126 ) ;
}
V_45:
return V_13 ;
}
void F_253 ( struct V_239 * V_169 )
{
struct V_7 * V_8 = & V_218 ;
if ( ! F_158 () )
return;
F_254 ( V_169 ,
L_14
L_15
L_16
L_17
L_18 ,
V_8 -> V_116 ,
V_8 -> V_79 ,
V_8 -> V_94 ,
V_8 -> V_128 ,
1UL << ( F_36 ( V_8 ) + V_175 - 10 ) ) ;
}
int F_255 ( int V_76 , char * V_178 )
{
struct V_7 * V_8 = & V_218 ;
if ( ! F_158 () )
return 0 ;
return sprintf ( V_178 ,
L_19
L_20
L_21 ,
V_76 , V_8 -> V_117 [ V_76 ] ,
V_76 , V_8 -> V_80 [ V_76 ] ,
V_76 , V_8 -> V_127 [ V_76 ] ) ;
}
void F_256 ( void )
{
struct V_7 * V_8 ;
int V_76 ;
if ( ! F_158 () )
return;
F_234 (nid, N_MEMORY)
F_118 (h)
F_196 ( L_22 ,
V_76 ,
V_8 -> V_117 [ V_76 ] ,
V_8 -> V_80 [ V_76 ] ,
V_8 -> V_127 [ V_76 ] ,
1UL << ( F_36 ( V_8 ) + V_175 - 10 ) ) ;
}
unsigned long F_257 ( void )
{
struct V_7 * V_8 ;
unsigned long V_240 = 0 ;
F_118 (h)
V_240 += V_8 -> V_116 * F_112 ( V_8 ) ;
return V_240 ;
}
static int F_3 ( struct V_7 * V_8 , long V_12 )
{
int V_13 = - V_14 ;
F_9 ( & V_126 ) ;
if ( V_12 > 0 ) {
if ( F_164 ( V_8 , V_12 ) < 0 )
goto V_45;
if ( V_12 > F_247 ( V_8 -> V_80 ) ) {
F_166 ( V_8 , V_12 ) ;
goto V_45;
}
}
V_13 = 0 ;
if ( V_12 < 0 )
F_166 ( V_8 , ( unsigned long ) - V_12 ) ;
V_45:
F_2 ( & V_126 ) ;
return V_13 ;
}
static void F_258 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_49 ( V_19 ) ;
if ( V_22 && F_53 ( V_19 , V_74 ) )
F_259 ( & V_22 -> V_57 ) ;
}
static void F_260 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_21 * V_22 = F_49 ( V_19 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
unsigned long V_241 , V_242 , V_243 ;
long V_244 ;
if ( ! V_22 || ! F_53 ( V_19 , V_74 ) )
return;
V_242 = F_34 ( V_8 , V_19 , V_19 -> V_52 ) ;
V_243 = F_34 ( V_8 , V_19 , V_19 -> V_245 ) ;
V_241 = ( V_243 - V_242 ) - F_31 ( V_22 , V_242 , V_243 ) ;
F_261 ( & V_22 -> V_57 , F_46 ) ;
if ( V_241 ) {
V_244 = F_12 ( V_2 , V_241 ) ;
F_3 ( V_8 , - V_244 ) ;
}
}
static int F_262 ( struct V_18 * V_19 , struct V_246 * V_247 )
{
F_169 () ;
return 0 ;
}
static T_10 F_263 ( struct V_18 * V_19 , struct V_75 * V_75 ,
int V_248 )
{
T_10 V_249 ;
if ( V_248 ) {
V_249 = F_264 ( F_265 ( F_266 ( V_75 ,
V_19 -> V_250 ) ) ) ;
} else {
V_249 = F_267 ( F_266 ( V_75 ,
V_19 -> V_250 ) ) ;
}
V_249 = F_268 ( V_249 ) ;
V_249 = F_269 ( V_249 ) ;
V_249 = F_270 ( V_249 , V_19 , V_75 , V_248 ) ;
return V_249 ;
}
static void F_271 ( struct V_18 * V_19 ,
unsigned long V_51 , T_10 * V_251 )
{
T_10 V_249 ;
V_249 = F_264 ( F_265 ( F_272 ( V_251 ) ) ) ;
if ( F_273 ( V_19 , V_51 , V_251 , V_249 , 1 ) )
F_274 ( V_19 , V_51 , V_251 ) ;
}
static int F_275 ( T_10 V_252 )
{
T_11 V_253 ;
if ( F_276 ( V_252 ) || F_277 ( V_252 ) )
return 0 ;
V_253 = F_278 ( V_252 ) ;
if ( F_279 ( V_253 ) && F_280 ( V_253 ) )
return 1 ;
else
return 0 ;
}
static int F_281 ( T_10 V_252 )
{
T_11 V_253 ;
if ( F_276 ( V_252 ) || F_277 ( V_252 ) )
return 0 ;
V_253 = F_278 ( V_252 ) ;
if ( F_279 ( V_253 ) && F_282 ( V_253 ) )
return 1 ;
else
return 0 ;
}
int F_283 ( struct V_254 * V_255 , struct V_254 * V_256 ,
struct V_18 * V_19 )
{
T_10 * V_257 , * V_258 , V_249 ;
struct V_75 * V_259 ;
unsigned long V_153 ;
int V_260 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_261 = F_119 ( V_8 ) ;
unsigned long V_262 ;
unsigned long V_263 ;
int V_13 = 0 ;
V_260 = ( V_19 -> V_63 & ( V_264 | V_265 ) ) == V_265 ;
V_262 = V_19 -> V_52 ;
V_263 = V_19 -> V_245 ;
if ( V_260 )
F_284 ( V_256 , V_262 , V_263 ) ;
for ( V_153 = V_19 -> V_52 ; V_153 < V_19 -> V_245 ; V_153 += V_261 ) {
T_12 * V_266 , * V_267 ;
V_257 = F_285 ( V_256 , V_153 ) ;
if ( ! V_257 )
continue;
V_258 = F_286 ( V_255 , V_153 , V_261 ) ;
if ( ! V_258 ) {
V_13 = - V_14 ;
break;
}
if ( V_258 == V_257 )
continue;
V_267 = F_287 ( V_8 , V_255 , V_258 ) ;
V_266 = F_288 ( V_8 , V_256 , V_257 ) ;
F_289 ( V_266 , V_268 ) ;
V_249 = F_272 ( V_257 ) ;
if ( F_276 ( V_249 ) ) {
;
} else if ( F_72 ( F_275 ( V_249 ) ||
F_281 ( V_249 ) ) ) {
T_11 V_269 = F_278 ( V_249 ) ;
if ( F_290 ( V_269 ) && V_260 ) {
F_291 ( & V_269 ) ;
V_249 = F_292 ( V_269 ) ;
F_293 ( V_256 , V_153 , V_257 , V_249 ) ;
}
F_293 ( V_255 , V_153 , V_258 , V_249 ) ;
} else {
if ( V_260 ) {
F_294 ( V_256 , V_153 , V_257 ) ;
F_295 ( V_256 , V_262 ,
V_263 ) ;
}
V_249 = F_272 ( V_257 ) ;
V_259 = F_296 ( V_249 ) ;
F_297 ( V_259 ) ;
F_298 ( V_259 ) ;
F_293 ( V_255 , V_153 , V_258 , V_249 ) ;
}
F_2 ( V_266 ) ;
F_2 ( V_267 ) ;
}
if ( V_260 )
F_299 ( V_256 , V_262 , V_263 ) ;
return V_13 ;
}
void F_300 ( struct V_270 * V_271 , struct V_18 * V_19 ,
unsigned long V_242 , unsigned long V_243 ,
struct V_75 * V_272 )
{
int V_273 = 0 ;
struct V_254 * V_274 = V_19 -> V_275 ;
unsigned long V_51 ;
T_10 * V_251 ;
T_10 V_252 ;
T_12 * V_276 ;
struct V_75 * V_75 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_261 = F_119 ( V_8 ) ;
const unsigned long V_262 = V_242 ;
const unsigned long V_263 = V_243 ;
F_190 ( ! F_40 ( V_19 ) ) ;
F_10 ( V_242 & ~ F_301 ( V_8 ) ) ;
F_10 ( V_243 & ~ F_301 ( V_8 ) ) ;
F_302 ( V_271 , V_19 ) ;
F_284 ( V_274 , V_262 , V_263 ) ;
V_51 = V_242 ;
V_277:
for (; V_51 < V_243 ; V_51 += V_261 ) {
V_251 = F_285 ( V_274 , V_51 ) ;
if ( ! V_251 )
continue;
V_276 = F_287 ( V_8 , V_274 , V_251 ) ;
if ( F_303 ( V_274 , & V_51 , V_251 ) )
goto V_278;
V_252 = F_272 ( V_251 ) ;
if ( F_276 ( V_252 ) )
goto V_278;
if ( F_72 ( ! F_277 ( V_252 ) ) ) {
F_304 ( V_274 , V_51 , V_251 ) ;
goto V_278;
}
V_75 = F_296 ( V_252 ) ;
if ( V_272 ) {
if ( V_75 != V_272 )
goto V_278;
F_52 ( V_19 , V_279 ) ;
}
V_252 = F_305 ( V_274 , V_51 , V_251 ) ;
F_306 ( V_271 , V_251 , V_51 ) ;
if ( F_307 ( V_252 ) )
F_308 ( V_75 ) ;
F_309 ( V_75 ) ;
V_273 = ! F_310 ( V_271 , V_75 ) ;
if ( V_273 ) {
V_51 += V_261 ;
F_2 ( V_276 ) ;
break;
}
if ( V_272 ) {
F_2 ( V_276 ) ;
break;
}
V_278:
F_2 ( V_276 ) ;
}
if ( V_273 ) {
V_273 = 0 ;
F_311 ( V_271 ) ;
if ( V_51 < V_243 && ! V_272 )
goto V_277;
}
F_299 ( V_274 , V_262 , V_263 ) ;
F_312 ( V_271 , V_19 ) ;
}
void F_313 ( struct V_270 * V_271 ,
struct V_18 * V_19 , unsigned long V_242 ,
unsigned long V_243 , struct V_75 * V_272 )
{
F_300 ( V_271 , V_19 , V_242 , V_243 , V_272 ) ;
V_19 -> V_63 &= ~ V_64 ;
}
void F_314 ( struct V_18 * V_19 , unsigned long V_242 ,
unsigned long V_243 , struct V_75 * V_272 )
{
struct V_254 * V_274 ;
struct V_270 V_271 ;
V_274 = V_19 -> V_275 ;
F_315 ( & V_271 , V_274 , V_242 , V_243 ) ;
F_300 ( & V_271 , V_19 , V_242 , V_243 , V_272 ) ;
F_316 ( & V_271 , V_242 , V_243 ) ;
}
static void F_317 ( struct V_254 * V_274 , struct V_18 * V_19 ,
struct V_75 * V_75 , unsigned long V_51 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_18 * V_280 ;
struct V_65 * V_66 ;
T_1 V_281 ;
V_51 = V_51 & F_301 ( V_8 ) ;
V_281 = ( ( V_51 - V_19 -> V_52 ) >> V_175 ) +
V_19 -> V_53 ;
V_66 = F_16 ( V_19 -> V_20 ) -> V_61 ;
F_318 ( V_66 ) ;
F_319 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_280 == V_19 )
continue;
if ( V_280 -> V_63 & V_64 )
continue;
if ( ! F_53 ( V_280 , V_74 ) )
F_314 ( V_280 , V_51 ,
V_51 + F_119 ( V_8 ) , V_75 ) ;
}
F_320 ( V_66 ) ;
}
static int F_321 ( struct V_254 * V_274 , struct V_18 * V_19 ,
unsigned long V_51 , T_10 * V_251 , T_10 V_252 ,
struct V_75 * V_282 , T_12 * V_276 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_75 * V_283 , * V_284 ;
int V_13 = 0 , V_285 = 0 ;
unsigned long V_262 ;
unsigned long V_263 ;
V_283 = F_296 ( V_252 ) ;
V_286:
if ( F_131 ( V_283 ) == 1 && F_322 ( V_283 ) ) {
F_323 ( V_283 , V_19 , V_51 ) ;
F_271 ( V_19 , V_51 , V_251 ) ;
return 0 ;
}
if ( F_53 ( V_19 , V_74 ) &&
V_283 != V_282 )
V_285 = 1 ;
F_324 ( V_283 ) ;
F_2 ( V_276 ) ;
V_284 = F_173 ( V_19 , V_51 , V_285 ) ;
if ( F_179 ( V_284 ) ) {
if ( V_285 ) {
F_325 ( V_283 ) ;
F_10 ( F_276 ( V_252 ) ) ;
F_317 ( V_274 , V_19 , V_283 , V_51 ) ;
F_10 ( F_276 ( V_252 ) ) ;
F_9 ( V_276 ) ;
V_251 = F_285 ( V_274 , V_51 & F_301 ( V_8 ) ) ;
if ( F_326 ( V_251 &&
F_327 ( F_272 ( V_251 ) , V_252 ) ) )
goto V_286;
return 0 ;
}
V_13 = ( F_328 ( V_284 ) == - V_14 ) ?
V_287 : V_288 ;
goto V_289;
}
if ( F_72 ( F_329 ( V_19 ) ) ) {
V_13 = V_287 ;
goto V_290;
}
F_330 ( V_284 , V_283 , V_51 , V_19 ,
F_112 ( V_8 ) ) ;
F_331 ( V_284 ) ;
F_123 ( V_284 ) ;
V_262 = V_51 & F_301 ( V_8 ) ;
V_263 = V_262 + F_119 ( V_8 ) ;
F_284 ( V_274 , V_262 , V_263 ) ;
F_9 ( V_276 ) ;
V_251 = F_285 ( V_274 , V_51 & F_301 ( V_8 ) ) ;
if ( F_326 ( V_251 && F_327 ( F_272 ( V_251 ) , V_252 ) ) ) {
F_126 ( V_284 ) ;
F_332 ( V_19 , V_51 , V_251 ) ;
F_295 ( V_274 , V_262 , V_263 ) ;
F_293 ( V_274 , V_51 , V_251 ,
F_263 ( V_19 , V_284 , 1 ) ) ;
F_309 ( V_283 ) ;
F_333 ( V_284 , V_19 , V_51 ) ;
V_284 = V_283 ;
}
F_2 ( V_276 ) ;
F_299 ( V_274 , V_262 , V_263 ) ;
V_290:
F_325 ( V_284 ) ;
V_289:
F_325 ( V_283 ) ;
F_9 ( V_276 ) ;
return V_13 ;
}
static struct V_75 * F_334 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_51 )
{
struct V_65 * V_66 ;
T_1 V_156 ;
V_66 = V_19 -> V_20 -> V_67 ;
V_156 = F_34 ( V_8 , V_19 , V_51 ) ;
return F_335 ( V_66 , V_156 ) ;
}
static bool F_336 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_51 )
{
struct V_65 * V_66 ;
T_1 V_156 ;
struct V_75 * V_75 ;
V_66 = V_19 -> V_20 -> V_67 ;
V_156 = F_34 ( V_8 , V_19 , V_51 ) ;
V_75 = F_337 ( V_66 , V_156 ) ;
if ( V_75 )
F_136 ( V_75 ) ;
return V_75 != NULL ;
}
int F_338 ( struct V_75 * V_75 , struct V_65 * V_66 ,
T_1 V_156 )
{
struct V_16 * V_16 = V_66 -> V_68 ;
struct V_7 * V_8 = F_30 ( V_16 ) ;
int V_95 = F_339 ( V_75 , V_66 , V_156 , V_10 ) ;
if ( V_95 )
return V_95 ;
F_126 ( V_75 ) ;
F_9 ( & V_16 -> V_291 ) ;
V_16 -> V_292 += F_340 ( V_8 ) ;
F_2 ( & V_16 -> V_291 ) ;
return 0 ;
}
static int F_341 ( struct V_254 * V_274 , struct V_18 * V_19 ,
struct V_65 * V_66 , T_1 V_156 ,
unsigned long V_51 , T_10 * V_251 , unsigned int V_71 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
int V_13 = V_288 ;
int V_293 = 0 ;
unsigned long V_125 ;
struct V_75 * V_75 ;
T_10 V_294 ;
T_12 * V_276 ;
if ( F_53 ( V_19 , V_279 ) ) {
F_243 ( L_23 ,
V_182 -> V_295 ) ;
return V_13 ;
}
V_42:
V_75 = F_335 ( V_66 , V_156 ) ;
if ( ! V_75 ) {
V_125 = F_342 ( V_66 -> V_68 ) >> F_35 ( V_8 ) ;
if ( V_156 >= V_125 )
goto V_45;
V_75 = F_173 ( V_19 , V_51 , 0 ) ;
if ( F_179 ( V_75 ) ) {
V_13 = F_328 ( V_75 ) ;
if ( V_13 == - V_14 )
V_13 = V_287 ;
else
V_13 = V_288 ;
goto V_45;
}
F_343 ( V_75 , V_51 , F_112 ( V_8 ) ) ;
F_331 ( V_75 ) ;
F_123 ( V_75 ) ;
if ( V_19 -> V_63 & V_64 ) {
int V_95 = F_338 ( V_75 , V_66 , V_156 ) ;
if ( V_95 ) {
F_136 ( V_75 ) ;
if ( V_95 == - V_296 )
goto V_42;
goto V_45;
}
} else {
F_344 ( V_75 ) ;
if ( F_72 ( F_329 ( V_19 ) ) ) {
V_13 = V_287 ;
goto V_297;
}
V_293 = 1 ;
}
} else {
if ( F_72 ( F_345 ( V_75 ) ) ) {
V_13 = V_298 |
F_346 ( F_133 ( V_8 ) ) ;
goto V_297;
}
}
if ( ( V_71 & V_299 ) && ! ( V_19 -> V_63 & V_264 ) ) {
if ( F_170 ( V_8 , V_19 , V_51 ) < 0 ) {
V_13 = V_287 ;
goto V_297;
}
F_172 ( V_8 , V_19 , V_51 ) ;
}
V_276 = F_288 ( V_8 , V_274 , V_251 ) ;
F_9 ( V_276 ) ;
V_125 = F_342 ( V_66 -> V_68 ) >> F_35 ( V_8 ) ;
if ( V_156 >= V_125 )
goto V_300;
V_13 = 0 ;
if ( ! F_276 ( F_272 ( V_251 ) ) )
goto V_300;
if ( V_293 ) {
F_126 ( V_75 ) ;
F_333 ( V_75 , V_19 , V_51 ) ;
} else
F_298 ( V_75 ) ;
V_294 = F_263 ( V_19 , V_75 , ( ( V_19 -> V_63 & V_301 )
&& ( V_19 -> V_63 & V_264 ) ) ) ;
F_293 ( V_274 , V_51 , V_251 , V_294 ) ;
if ( ( V_71 & V_299 ) && ! ( V_19 -> V_63 & V_264 ) ) {
V_13 = F_321 ( V_274 , V_19 , V_51 , V_251 , V_294 , V_75 , V_276 ) ;
}
F_2 ( V_276 ) ;
F_347 ( V_75 ) ;
V_45:
return V_13 ;
V_300:
F_2 ( V_276 ) ;
V_297:
F_347 ( V_75 ) ;
F_136 ( V_75 ) ;
goto V_45;
}
T_13 F_348 ( struct V_7 * V_8 , struct V_254 * V_274 ,
struct V_18 * V_19 ,
struct V_65 * V_66 ,
T_1 V_156 , unsigned long V_51 )
{
unsigned long V_302 [ 2 ] ;
T_13 V_303 ;
if ( V_19 -> V_63 & V_264 ) {
V_302 [ 0 ] = ( unsigned long ) V_66 ;
V_302 [ 1 ] = V_156 ;
} else {
V_302 [ 0 ] = ( unsigned long ) V_274 ;
V_302 [ 1 ] = V_51 >> F_35 ( V_8 ) ;
}
V_303 = F_349 ( ( T_13 * ) & V_302 , sizeof( V_302 ) / sizeof( T_13 ) , 0 ) ;
return V_303 & ( V_219 - 1 ) ;
}
T_13 F_348 ( struct V_7 * V_8 , struct V_254 * V_274 ,
struct V_18 * V_19 ,
struct V_65 * V_66 ,
T_1 V_156 , unsigned long V_51 )
{
return 0 ;
}
int F_350 ( struct V_254 * V_274 , struct V_18 * V_19 ,
unsigned long V_51 , unsigned int V_71 )
{
T_10 * V_251 , V_249 ;
T_12 * V_276 ;
int V_13 ;
T_13 V_303 ;
T_1 V_156 ;
struct V_75 * V_75 = NULL ;
struct V_75 * V_282 = NULL ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_65 * V_66 ;
int V_304 = 0 ;
V_51 &= F_301 ( V_8 ) ;
V_251 = F_285 ( V_274 , V_51 ) ;
if ( V_251 ) {
V_249 = F_272 ( V_251 ) ;
if ( F_72 ( F_275 ( V_249 ) ) ) {
F_351 ( V_19 , V_274 , V_251 ) ;
return 0 ;
} else if ( F_72 ( F_281 ( V_249 ) ) )
return V_305 |
F_346 ( F_133 ( V_8 ) ) ;
}
V_251 = F_286 ( V_274 , V_51 , F_119 ( V_8 ) ) ;
if ( ! V_251 )
return V_287 ;
V_66 = V_19 -> V_20 -> V_67 ;
V_156 = F_34 ( V_8 , V_19 , V_51 ) ;
V_303 = F_348 ( V_8 , V_274 , V_19 , V_66 , V_156 , V_51 ) ;
F_352 ( & V_212 [ V_303 ] ) ;
V_249 = F_272 ( V_251 ) ;
if ( F_276 ( V_249 ) ) {
V_13 = F_341 ( V_274 , V_19 , V_66 , V_156 , V_51 , V_251 , V_71 ) ;
goto V_306;
}
V_13 = 0 ;
if ( ! F_277 ( V_249 ) )
goto V_306;
if ( ( V_71 & V_299 ) && ! F_353 ( V_249 ) ) {
if ( F_170 ( V_8 , V_19 , V_51 ) < 0 ) {
V_13 = V_287 ;
goto V_306;
}
F_172 ( V_8 , V_19 , V_51 ) ;
if ( ! ( V_19 -> V_63 & V_64 ) )
V_282 = F_334 ( V_8 ,
V_19 , V_51 ) ;
}
V_276 = F_287 ( V_8 , V_274 , V_251 ) ;
if ( F_72 ( ! F_327 ( V_249 , F_272 ( V_251 ) ) ) )
goto V_307;
V_75 = F_296 ( V_249 ) ;
if ( V_75 != V_282 )
if ( ! F_354 ( V_75 ) ) {
V_304 = 1 ;
goto V_307;
}
F_297 ( V_75 ) ;
if ( V_71 & V_299 ) {
if ( ! F_353 ( V_249 ) ) {
V_13 = F_321 ( V_274 , V_19 , V_51 , V_251 , V_249 ,
V_282 , V_276 ) ;
goto V_308;
}
V_249 = F_265 ( V_249 ) ;
}
V_249 = F_268 ( V_249 ) ;
if ( F_273 ( V_19 , V_51 , V_251 , V_249 ,
V_71 & V_299 ) )
F_274 ( V_19 , V_51 , V_251 ) ;
V_308:
if ( V_75 != V_282 )
F_347 ( V_75 ) ;
F_136 ( V_75 ) ;
V_307:
F_2 ( V_276 ) ;
if ( V_282 ) {
F_347 ( V_282 ) ;
F_136 ( V_282 ) ;
}
V_306:
F_355 ( & V_212 [ V_303 ] ) ;
if ( V_304 )
F_356 ( V_75 ) ;
return V_13 ;
}
long F_357 ( struct V_254 * V_274 , struct V_18 * V_19 ,
struct V_75 * * V_309 , struct V_18 * * V_310 ,
unsigned long * V_311 , unsigned long * V_103 ,
long V_102 , unsigned int V_71 )
{
unsigned long V_312 ;
unsigned long V_313 = * V_311 ;
unsigned long V_314 = * V_103 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
while ( V_313 < V_19 -> V_245 && V_314 ) {
T_10 * V_252 ;
T_12 * V_276 = NULL ;
int V_315 ;
struct V_75 * V_75 ;
if ( F_72 ( F_358 ( V_182 ) ) ) {
V_314 = 0 ;
break;
}
V_252 = F_285 ( V_274 , V_313 & F_301 ( V_8 ) ) ;
if ( V_252 )
V_276 = F_287 ( V_8 , V_274 , V_252 ) ;
V_315 = ! V_252 || F_276 ( F_272 ( V_252 ) ) ;
if ( V_315 && ( V_71 & V_316 ) &&
! F_336 ( V_8 , V_19 , V_313 ) ) {
if ( V_252 )
F_2 ( V_276 ) ;
V_314 = 0 ;
break;
}
if ( V_315 || F_359 ( F_272 ( V_252 ) ) ||
( ( V_71 & V_317 ) &&
! F_353 ( F_272 ( V_252 ) ) ) ) {
int V_13 ;
if ( V_252 )
F_2 ( V_276 ) ;
V_13 = F_350 ( V_274 , V_19 , V_313 ,
( V_71 & V_317 ) ? V_299 : 0 ) ;
if ( ! ( V_13 & V_318 ) )
continue;
V_314 = 0 ;
break;
}
V_312 = ( V_313 & ~ F_301 ( V_8 ) ) >> V_175 ;
V_75 = F_296 ( F_272 ( V_252 ) ) ;
V_319:
if ( V_309 ) {
V_309 [ V_102 ] = F_360 ( V_75 , V_312 ) ;
F_361 ( V_309 [ V_102 ] ) ;
}
if ( V_310 )
V_310 [ V_102 ] = V_19 ;
V_313 += V_54 ;
++ V_312 ;
-- V_314 ;
++ V_102 ;
if ( V_313 < V_19 -> V_245 && V_314 &&
V_312 < F_112 ( V_8 ) ) {
goto V_319;
}
F_2 ( V_276 ) ;
}
* V_103 = V_314 ;
* V_311 = V_313 ;
return V_102 ? V_102 : - V_320 ;
}
unsigned long F_362 ( struct V_18 * V_19 ,
unsigned long V_51 , unsigned long V_243 , T_14 V_321 )
{
struct V_254 * V_274 = V_19 -> V_275 ;
unsigned long V_242 = V_51 ;
T_10 * V_251 ;
T_10 V_252 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_309 = 0 ;
F_10 ( V_51 >= V_243 ) ;
F_363 ( V_19 , V_51 , V_243 ) ;
F_284 ( V_274 , V_242 , V_243 ) ;
F_318 ( V_19 -> V_20 -> V_67 ) ;
for (; V_51 < V_243 ; V_51 += F_119 ( V_8 ) ) {
T_12 * V_276 ;
V_251 = F_285 ( V_274 , V_51 ) ;
if ( ! V_251 )
continue;
V_276 = F_287 ( V_8 , V_274 , V_251 ) ;
if ( F_303 ( V_274 , & V_51 , V_251 ) ) {
V_309 ++ ;
F_2 ( V_276 ) ;
continue;
}
V_252 = F_272 ( V_251 ) ;
if ( F_72 ( F_281 ( V_252 ) ) ) {
F_2 ( V_276 ) ;
continue;
}
if ( F_72 ( F_275 ( V_252 ) ) ) {
T_11 V_249 = F_278 ( V_252 ) ;
if ( F_290 ( V_249 ) ) {
T_10 V_322 ;
F_291 ( & V_249 ) ;
V_322 = F_292 ( V_249 ) ;
F_293 ( V_274 , V_51 , V_251 , V_322 ) ;
V_309 ++ ;
}
F_2 ( V_276 ) ;
continue;
}
if ( ! F_276 ( V_252 ) ) {
V_252 = F_305 ( V_274 , V_51 , V_251 ) ;
V_252 = F_269 ( F_364 ( V_252 , V_321 ) ) ;
V_252 = F_270 ( V_252 , V_19 , NULL , 0 ) ;
F_293 ( V_274 , V_51 , V_251 , V_252 ) ;
V_309 ++ ;
}
F_2 ( V_276 ) ;
}
F_365 ( V_19 , V_242 , V_243 ) ;
F_295 ( V_274 , V_242 , V_243 ) ;
F_320 ( V_19 -> V_20 -> V_67 ) ;
F_299 ( V_274 , V_242 , V_243 ) ;
return V_309 << V_8 -> V_101 ;
}
int F_366 ( struct V_16 * V_16 ,
long V_35 , long V_33 ,
struct V_18 * V_19 ,
T_15 V_63 )
{
long V_13 , V_41 ;
struct V_7 * V_8 = F_30 ( V_16 ) ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
struct V_21 * V_21 ;
long V_244 ;
if ( V_63 & V_73 )
return 0 ;
if ( ! V_19 || V_19 -> V_63 & V_64 ) {
V_21 = F_48 ( V_16 ) ;
V_41 = F_24 ( V_21 , V_35 , V_33 ) ;
} else {
V_21 = F_44 () ;
if ( ! V_21 )
return - V_14 ;
V_41 = V_33 - V_35 ;
F_51 ( V_19 , V_21 ) ;
F_52 ( V_19 , V_74 ) ;
}
if ( V_41 < 0 ) {
V_13 = V_41 ;
goto V_323;
}
V_244 = F_11 ( V_2 , V_41 ) ;
if ( V_244 < 0 ) {
V_13 = - V_165 ;
goto V_323;
}
V_13 = F_3 ( V_8 , V_244 ) ;
if ( V_13 < 0 ) {
( void ) F_12 ( V_2 , V_41 ) ;
goto V_323;
}
if ( ! V_19 || V_19 -> V_63 & V_64 ) {
long V_32 = F_17 ( V_21 , V_35 , V_33 ) ;
if ( F_72 ( V_41 > V_32 ) ) {
long V_48 ;
V_48 = F_12 ( V_2 ,
V_41 - V_32 ) ;
F_3 ( V_8 , - V_48 ) ;
}
}
return 0 ;
V_323:
if ( ! V_19 || V_19 -> V_63 & V_64 )
F_27 ( V_21 , V_35 , V_33 ) ;
if ( V_19 && F_53 ( V_19 , V_74 ) )
F_261 ( & V_21 -> V_57 , F_46 ) ;
return V_13 ;
}
long F_367 ( struct V_16 * V_16 , long V_242 , long V_243 ,
long V_324 )
{
struct V_7 * V_8 = F_30 ( V_16 ) ;
struct V_21 * V_21 = F_48 ( V_16 ) ;
long V_41 = 0 ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
long V_244 ;
if ( V_21 ) {
V_41 = F_28 ( V_21 , V_242 , V_243 ) ;
if ( V_41 < 0 )
return V_41 ;
}
F_9 ( & V_16 -> V_291 ) ;
V_16 -> V_292 -= ( F_340 ( V_8 ) * V_324 ) ;
F_2 ( & V_16 -> V_291 ) ;
V_244 = F_12 ( V_2 , ( V_41 - V_324 ) ) ;
F_3 ( V_8 , - V_244 ) ;
return 0 ;
}
static unsigned long F_368 ( struct V_18 * V_325 ,
struct V_18 * V_19 ,
unsigned long V_153 , T_1 V_156 )
{
unsigned long V_326 = ( ( V_156 - V_325 -> V_53 ) << V_175 ) +
V_325 -> V_52 ;
unsigned long V_327 = V_326 & V_328 ;
unsigned long V_329 = V_327 + V_330 ;
unsigned long V_63 = V_19 -> V_63 & ~ V_331 ;
unsigned long V_332 = V_325 -> V_63 & ~ V_331 ;
if ( F_369 ( V_153 ) != F_369 ( V_326 ) ||
V_63 != V_332 ||
V_327 < V_325 -> V_52 || V_325 -> V_245 < V_329 )
return 0 ;
return V_326 ;
}
static bool F_370 ( struct V_18 * V_19 , unsigned long V_153 )
{
unsigned long V_333 = V_153 & V_328 ;
unsigned long V_243 = V_333 + V_330 ;
if ( V_19 -> V_63 & V_64 &&
V_19 -> V_52 <= V_333 && V_243 <= V_19 -> V_245 )
return true ;
return false ;
}
T_10 * F_371 ( struct V_254 * V_274 , unsigned long V_153 , T_16 * V_334 )
{
struct V_18 * V_19 = F_372 ( V_274 , V_153 ) ;
struct V_65 * V_66 = V_19 -> V_20 -> V_67 ;
T_1 V_156 = ( ( V_153 - V_19 -> V_52 ) >> V_175 ) +
V_19 -> V_53 ;
struct V_18 * V_325 ;
unsigned long V_326 ;
T_10 * V_335 = NULL ;
T_10 * V_252 ;
T_12 * V_276 ;
if ( ! F_370 ( V_19 , V_153 ) )
return ( T_10 * ) F_373 ( V_274 , V_334 , V_153 ) ;
F_318 ( V_66 ) ;
F_319 (svma, &mapping->i_mmap, idx, idx) {
if ( V_325 == V_19 )
continue;
V_326 = F_368 ( V_325 , V_19 , V_153 , V_156 ) ;
if ( V_326 ) {
V_335 = F_285 ( V_325 -> V_275 , V_326 ) ;
if ( V_335 ) {
F_374 ( V_274 ) ;
F_297 ( F_189 ( V_335 ) ) ;
break;
}
}
}
if ( ! V_335 )
goto V_45;
V_276 = F_288 ( F_38 ( V_19 ) , V_274 , V_335 ) ;
F_9 ( V_276 ) ;
if ( F_375 ( * V_334 ) ) {
F_376 ( V_274 , V_334 ,
( V_336 * ) ( ( unsigned long ) V_335 & V_337 ) ) ;
} else {
F_136 ( F_189 ( V_335 ) ) ;
F_374 ( V_274 ) ;
}
F_2 ( V_276 ) ;
V_45:
V_252 = ( T_10 * ) F_373 ( V_274 , V_334 , V_153 ) ;
F_320 ( V_66 ) ;
return V_252 ;
}
int F_303 ( struct V_254 * V_274 , unsigned long * V_153 , T_10 * V_251 )
{
T_17 * V_338 = F_377 ( V_274 , * V_153 ) ;
T_16 * V_334 = F_378 ( V_338 , * V_153 ) ;
F_10 ( F_95 ( F_189 ( V_251 ) ) == 0 ) ;
if ( F_95 ( F_189 ( V_251 ) ) == 1 )
return 0 ;
F_379 ( V_334 ) ;
F_136 ( F_189 ( V_251 ) ) ;
F_380 ( V_274 ) ;
* V_153 = F_102 ( * V_153 , V_214 * V_339 ) - V_214 ;
return 1 ;
}
T_10 * F_371 ( struct V_254 * V_274 , unsigned long V_153 , T_16 * V_334 )
{
return NULL ;
}
int F_303 ( struct V_254 * V_274 , unsigned long * V_153 , T_10 * V_251 )
{
return 0 ;
}
T_10 * F_286 ( struct V_254 * V_274 ,
unsigned long V_153 , unsigned long V_261 )
{
T_17 * V_338 ;
T_16 * V_334 ;
T_10 * V_252 = NULL ;
V_338 = F_377 ( V_274 , V_153 ) ;
V_334 = F_381 ( V_274 , V_338 , V_153 ) ;
if ( V_334 ) {
if ( V_261 == V_330 ) {
V_252 = ( T_10 * ) V_334 ;
} else {
F_10 ( V_261 != V_340 ) ;
if ( F_382 () && F_375 ( * V_334 ) )
V_252 = F_371 ( V_274 , V_153 , V_334 ) ;
else
V_252 = ( T_10 * ) F_373 ( V_274 , V_334 , V_153 ) ;
}
}
F_10 ( V_252 && ! F_383 ( * V_252 ) && ! F_384 ( * V_252 ) ) ;
return V_252 ;
}
T_10 * F_285 ( struct V_254 * V_274 , unsigned long V_153 )
{
T_17 * V_338 ;
T_16 * V_334 ;
V_336 * V_341 = NULL ;
V_338 = F_377 ( V_274 , V_153 ) ;
if ( F_385 ( * V_338 ) ) {
V_334 = F_378 ( V_338 , V_153 ) ;
if ( F_386 ( * V_334 ) ) {
if ( F_387 ( * V_334 ) )
return ( T_10 * ) V_334 ;
V_341 = F_388 ( V_334 , V_153 ) ;
}
}
return ( T_10 * ) V_341 ;
}
struct V_75 * __weak
F_389 ( struct V_254 * V_274 , unsigned long V_51 ,
int V_232 )
{
return F_174 ( - V_194 ) ;
}
struct V_75 * __weak
F_390 ( struct V_254 * V_274 , unsigned long V_51 ,
V_336 * V_341 , int V_71 )
{
struct V_75 * V_75 = NULL ;
T_12 * V_276 ;
V_42:
V_276 = F_391 ( V_274 , V_341 ) ;
F_9 ( V_276 ) ;
if ( ! F_392 ( * V_341 ) )
goto V_45;
if ( F_393 ( * V_341 ) ) {
V_75 = F_394 ( * V_341 ) + ( ( V_51 & ~ V_342 ) >> V_175 ) ;
if ( V_71 & V_343 )
F_297 ( V_75 ) ;
} else {
if ( F_275 ( F_272 ( ( T_10 * ) V_341 ) ) ) {
F_2 ( V_276 ) ;
F_395 ( V_274 , ( T_10 * ) V_341 , V_276 ) ;
goto V_42;
}
}
V_45:
F_2 ( V_276 ) ;
return V_75 ;
}
struct V_75 * __weak
F_396 ( struct V_254 * V_274 , unsigned long V_51 ,
T_16 * V_334 , int V_71 )
{
if ( V_71 & V_343 )
return NULL ;
return F_296 ( * ( T_10 * ) V_334 ) + ( ( V_51 & ~ V_328 ) >> V_175 ) ;
}
int F_397 ( struct V_75 * V_344 )
{
struct V_7 * V_8 = F_128 ( V_344 ) ;
int V_76 = F_57 ( V_344 ) ;
int V_13 = - V_345 ;
F_9 ( & V_126 ) ;
if ( ! F_120 ( V_344 ) && ! F_95 ( V_344 ) ) {
F_398 ( & V_344 -> V_77 ) ;
F_61 ( V_344 ) ;
V_8 -> V_79 -- ;
V_8 -> V_80 [ V_76 ] -- ;
V_13 = 0 ;
}
F_2 ( & V_126 ) ;
return V_13 ;
}
bool F_399 ( struct V_75 * V_75 , struct V_25 * V_172 )
{
bool V_13 = true ;
F_113 ( ! F_121 ( V_75 ) , V_75 ) ;
F_9 ( & V_126 ) ;
if ( ! F_120 ( V_75 ) || ! F_400 ( V_75 ) ) {
V_13 = false ;
goto V_278;
}
F_125 ( V_75 ) ;
F_401 ( & V_75 -> V_77 , V_172 ) ;
V_278:
F_2 ( & V_126 ) ;
return V_13 ;
}
void F_402 ( struct V_75 * V_75 )
{
F_113 ( ! F_121 ( V_75 ) , V_75 ) ;
F_9 ( & V_126 ) ;
F_123 ( V_75 ) ;
F_401 ( & V_75 -> V_77 , & ( F_128 ( V_75 ) ) -> V_81 ) ;
F_2 ( & V_126 ) ;
F_136 ( V_75 ) ;
}
