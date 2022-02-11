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
if ( ! V_31 ) {
F_4 ( V_30 ) ;
return - V_14 ;
}
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
if ( V_29 -> V_33 <= V_23 && ( V_29 -> V_33 != V_29 -> V_35 || V_29 -> V_33 != V_23 ) )
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
unsigned int V_101 )
{
int V_102 ;
int V_103 = 1 << V_101 ;
struct V_75 * V_104 = V_75 + 1 ;
for ( V_102 = 1 ; V_102 < V_103 ; V_102 ++ , V_104 = F_82 ( V_104 , V_75 , V_102 ) ) {
F_83 ( V_104 ) ;
F_61 ( V_104 ) ;
}
F_84 ( V_75 , 0 ) ;
F_85 ( V_75 ) ;
}
static void F_86 ( struct V_75 * V_75 , unsigned int V_101 )
{
F_87 ( F_88 ( V_75 ) , 1 << V_101 ) ;
}
static int F_89 ( unsigned long V_105 ,
unsigned long V_103 )
{
unsigned long V_106 = V_105 + V_103 ;
return F_90 ( V_105 , V_106 , V_107 ) ;
}
static bool F_91 ( unsigned long V_105 ,
unsigned long V_103 )
{
unsigned long V_102 , V_106 = V_105 + V_103 ;
struct V_75 * V_75 ;
for ( V_102 = V_105 ; V_102 < V_106 ; V_102 ++ ) {
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
unsigned long V_105 , unsigned long V_103 )
{
unsigned long V_108 = V_105 + V_103 - 1 ;
return F_98 ( V_90 , V_108 ) ;
}
static struct V_75 * F_99 ( int V_76 , unsigned int V_101 )
{
unsigned long V_103 = 1 << V_101 ;
unsigned long V_13 , V_109 , V_71 ;
struct V_90 * V_92 ;
V_92 = F_100 ( V_76 ) -> V_110 ;
for (; V_92 - F_100 ( V_76 ) -> V_110 < V_111 ; V_92 ++ ) {
F_101 ( & V_92 -> V_5 , V_71 ) ;
V_109 = F_102 ( V_92 -> V_112 , V_103 ) ;
while ( F_97 ( V_92 , V_109 , V_103 ) ) {
if ( F_91 ( V_109 , V_103 ) ) {
F_103 ( & V_92 -> V_5 , V_71 ) ;
V_13 = F_89 ( V_109 , V_103 ) ;
if ( ! V_13 )
return F_93 ( V_109 ) ;
F_101 ( & V_92 -> V_5 , V_71 ) ;
}
V_109 += V_103 ;
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
int V_113 , V_114 ;
F_108 (h, nr_nodes, node, nodes_allowed) {
V_75 = F_104 ( V_8 , V_114 ) ;
if ( V_75 )
return 1 ;
}
return 0 ;
}
static inline bool F_109 ( void ) { return true ; }
static inline bool F_109 ( void ) { return false ; }
static inline void F_86 ( struct V_75 * V_75 , unsigned int V_101 ) { }
static inline void F_81 ( struct V_75 * V_75 ,
unsigned int V_101 ) { }
static inline int F_107 ( struct V_7 * V_8 ,
T_3 * V_97 ) { return 0 ; }
static void F_110 ( struct V_7 * V_8 , struct V_75 * V_75 )
{
int V_102 ;
if ( F_111 ( V_8 ) && ! F_109 () )
return;
V_8 -> V_115 -- ;
V_8 -> V_116 [ F_57 ( V_75 ) ] -- ;
for ( V_102 = 0 ; V_102 < F_112 ( V_8 ) ; V_102 ++ ) {
V_75 [ V_102 ] . V_71 &= ~ ( 1 << V_117 | 1 << V_118 |
1 << V_119 | 1 << V_120 |
1 << V_121 | 1 << V_122 |
1 << V_123 ) ;
}
F_113 ( F_114 ( V_75 ) , V_75 ) ;
F_115 ( V_75 , V_124 ) ;
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
F_113 ( F_95 ( V_75 ) , V_75 ) ;
F_113 ( F_131 ( V_75 ) , V_75 ) ;
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
F_115 ( V_75 , V_129 ) ;
F_9 ( & V_126 ) ;
F_135 ( V_75 , NULL ) ;
V_8 -> V_115 ++ ;
V_8 -> V_116 [ V_76 ] ++ ;
F_2 ( & V_126 ) ;
F_136 ( V_75 ) ;
}
static void F_105 ( struct V_75 * V_75 , unsigned int V_101 )
{
int V_102 ;
int V_103 = 1 << V_101 ;
struct V_75 * V_104 = V_75 + 1 ;
F_84 ( V_75 , V_101 ) ;
F_137 ( V_75 ) ;
F_138 ( V_75 ) ;
for ( V_102 = 1 ; V_102 < V_103 ; V_102 ++ , V_104 = F_82 ( V_104 , V_75 , V_102 ) ) {
F_137 ( V_104 ) ;
F_139 ( V_104 , 0 ) ;
F_140 ( V_104 , V_75 ) ;
}
F_141 ( F_142 ( V_75 ) , - 1 ) ;
}
int F_96 ( struct V_75 * V_75 )
{
if ( ! F_143 ( V_75 ) )
return 0 ;
V_75 = F_144 ( V_75 ) ;
return V_75 [ 1 ] . V_130 == V_129 ;
}
int F_124 ( struct V_75 * V_131 )
{
if ( ! F_121 ( V_131 ) )
return 0 ;
return F_145 ( V_131 ) == F_127 ;
}
T_1 F_146 ( struct V_75 * V_75 )
{
struct V_75 * V_131 = F_144 ( V_75 ) ;
T_1 V_132 = F_147 ( V_131 ) ;
unsigned long V_133 ;
if ( ! F_96 ( V_131 ) )
return F_147 ( V_75 ) ;
if ( F_148 ( V_131 ) >= V_134 )
V_133 = F_88 ( V_75 ) - F_88 ( V_131 ) ;
else
V_133 = V_75 - V_131 ;
return ( V_132 << F_148 ( V_131 ) ) + V_133 ;
}
static struct V_75 * F_149 ( struct V_7 * V_8 , int V_76 )
{
struct V_75 * V_75 ;
V_75 = F_150 ( V_76 ,
F_62 ( V_8 ) | V_135 | V_136 |
V_137 | V_138 ,
F_36 ( V_8 ) ) ;
if ( V_75 ) {
F_106 ( V_8 , V_75 , V_76 ) ;
}
return V_75 ;
}
static int F_151 ( struct V_7 * V_8 , T_3 * V_97 )
{
struct V_75 * V_75 ;
int V_113 , V_114 ;
int V_13 = 0 ;
F_108 (h, nr_nodes, node, nodes_allowed) {
V_75 = F_149 ( V_8 , V_114 ) ;
if ( V_75 ) {
V_13 = 1 ;
break;
}
}
if ( V_13 )
F_152 ( V_139 ) ;
else
F_152 ( V_140 ) ;
return V_13 ;
}
static int F_153 ( struct V_7 * V_8 , T_3 * V_97 ,
bool V_141 )
{
int V_113 , V_114 ;
int V_13 = 0 ;
F_154 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_141 || V_8 -> V_127 [ V_114 ] ) &&
! F_155 ( & V_8 -> V_78 [ V_114 ] ) ) {
struct V_75 * V_75 =
F_156 ( V_8 -> V_78 [ V_114 ] . V_142 ,
struct V_75 , V_77 ) ;
F_21 ( & V_75 -> V_77 ) ;
V_8 -> V_79 -- ;
V_8 -> V_80 [ V_114 ] -- ;
if ( V_141 ) {
V_8 -> V_128 -- ;
V_8 -> V_127 [ V_114 ] -- ;
}
F_110 ( V_8 , V_75 ) ;
V_13 = 1 ;
break;
}
}
return V_13 ;
}
static void F_157 ( struct V_75 * V_75 )
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
void F_158 ( unsigned long V_105 , unsigned long V_106 )
{
unsigned long V_109 ;
if ( ! F_159 () )
return;
F_19 ( ! F_160 ( V_105 , 1 << V_143 ) ) ;
for ( V_109 = V_105 ; V_109 < V_106 ; V_109 += 1 << V_143 )
F_157 ( F_93 ( V_109 ) ) ;
}
static struct V_75 * F_161 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_144 , int V_76 )
{
int V_101 = F_36 ( V_8 ) ;
T_2 V_145 = F_62 ( V_8 ) | V_135 | V_137 | V_138 ;
unsigned int V_93 ;
if ( ! F_162 ( V_146 ) || ! V_19 ) {
if ( V_76 != V_147 )
V_145 |= V_136 ;
return F_163 ( V_76 , V_145 , V_101 ) ;
}
do {
struct V_75 * V_75 ;
struct V_86 * V_87 ;
struct V_89 * V_148 ;
T_3 * V_88 ;
V_93 = F_65 () ;
V_148 = F_66 ( V_19 , V_144 , V_145 , & V_87 , & V_88 ) ;
F_71 ( V_87 ) ;
V_75 = F_164 ( V_145 , V_101 , V_148 , V_88 ) ;
if ( V_75 )
return V_75 ;
} while ( F_73 ( V_93 ) );
return NULL ;
}
static struct V_75 * F_165 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_144 , int V_76 )
{
struct V_75 * V_75 ;
unsigned int V_149 ;
if ( F_111 ( V_8 ) )
return NULL ;
if ( V_19 || ( V_144 != - 1 ) ) {
F_166 ( V_144 == - 1 ) ;
F_166 ( V_76 != V_147 ) ;
}
F_9 ( & V_126 ) ;
if ( V_8 -> V_128 >= V_8 -> V_150 ) {
F_2 ( & V_126 ) ;
return NULL ;
} else {
V_8 -> V_115 ++ ;
V_8 -> V_128 ++ ;
}
F_2 ( & V_126 ) ;
V_75 = F_161 ( V_8 , V_19 , V_144 , V_76 ) ;
F_9 ( & V_126 ) ;
if ( V_75 ) {
F_26 ( & V_75 -> V_77 ) ;
V_149 = F_57 ( V_75 ) ;
F_115 ( V_75 , V_129 ) ;
F_135 ( V_75 , NULL ) ;
V_8 -> V_116 [ V_149 ] ++ ;
V_8 -> V_127 [ V_149 ] ++ ;
F_167 ( V_139 ) ;
} else {
V_8 -> V_115 -- ;
V_8 -> V_128 -- ;
F_167 ( V_140 ) ;
}
F_2 ( & V_126 ) ;
return V_75 ;
}
static
struct V_75 * F_168 ( struct V_7 * V_8 , int V_76 )
{
unsigned long V_144 = - 1 ;
return F_165 ( V_8 , NULL , V_144 , V_76 ) ;
}
static
struct V_75 * F_169 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_144 )
{
return F_165 ( V_8 , V_19 , V_144 , V_147 ) ;
}
struct V_75 * F_170 ( struct V_7 * V_8 , int V_76 )
{
struct V_75 * V_75 = NULL ;
F_9 ( & V_126 ) ;
if ( V_8 -> V_79 - V_8 -> V_94 > 0 )
V_75 = F_59 ( V_8 , V_76 ) ;
F_2 ( & V_126 ) ;
if ( ! V_75 )
V_75 = F_168 ( V_8 , V_76 ) ;
return V_75 ;
}
static int F_171 ( struct V_7 * V_8 , int V_12 )
{
struct V_25 V_151 ;
struct V_75 * V_75 , * V_152 ;
int V_13 , V_102 ;
int V_153 , V_154 ;
bool V_155 = true ;
V_153 = ( V_8 -> V_94 + V_12 ) - V_8 -> V_79 ;
if ( V_153 <= 0 ) {
V_8 -> V_94 += V_12 ;
return 0 ;
}
V_154 = 0 ;
F_26 ( & V_151 ) ;
V_13 = - V_14 ;
V_42:
F_2 ( & V_126 ) ;
for ( V_102 = 0 ; V_102 < V_153 ; V_102 ++ ) {
V_75 = F_168 ( V_8 , V_147 ) ;
if ( ! V_75 ) {
V_155 = false ;
break;
}
F_22 ( & V_75 -> V_77 , & V_151 ) ;
}
V_154 += V_102 ;
F_9 ( & V_126 ) ;
V_153 = ( V_8 -> V_94 + V_12 ) -
( V_8 -> V_79 + V_154 ) ;
if ( V_153 > 0 ) {
if ( V_155 )
goto V_42;
goto free;
}
V_153 += V_154 ;
V_8 -> V_94 += V_12 ;
V_13 = 0 ;
F_23 (page, tmp, &surplus_list, lru) {
if ( ( -- V_153 ) < 0 )
break;
F_172 ( V_75 ) ;
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
static void F_173 ( struct V_7 * V_8 ,
unsigned long V_156 )
{
unsigned long V_103 ;
V_8 -> V_94 -= V_156 ;
if ( F_111 ( V_8 ) )
return;
V_103 = F_33 ( V_156 , V_8 -> V_128 ) ;
while ( V_103 -- ) {
if ( ! F_153 ( V_8 , & V_157 [ V_158 ] , 1 ) )
break;
F_174 ( & V_126 ) ;
}
}
static long F_175 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_144 ,
enum V_159 V_160 )
{
struct V_21 * V_22 ;
T_1 V_161 ;
long V_13 ;
V_22 = F_49 ( V_19 ) ;
if ( ! V_22 )
return 1 ;
V_161 = F_34 ( V_8 , V_19 , V_144 ) ;
switch ( V_160 ) {
case V_162 :
V_13 = F_24 ( V_22 , V_161 , V_161 + 1 ) ;
break;
case V_163 :
V_13 = F_17 ( V_22 , V_161 , V_161 + 1 ) ;
break;
case V_164 :
F_27 ( V_22 , V_161 , V_161 + 1 ) ;
V_13 = 0 ;
break;
default:
F_176 () ;
}
if ( V_19 -> V_63 & V_64 )
return V_13 ;
else
return V_13 < 0 ? V_13 : 0 ;
}
static long F_177 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_144 )
{
return F_175 ( V_8 , V_19 , V_144 , V_162 ) ;
}
static long F_178 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_144 )
{
return F_175 ( V_8 , V_19 , V_144 , V_163 ) ;
}
static void F_179 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_144 )
{
( void ) F_175 ( V_8 , V_19 , V_144 , V_164 ) ;
}
struct V_75 * F_180 ( struct V_18 * V_19 ,
unsigned long V_144 , int V_85 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_75 * V_75 ;
long V_165 , V_166 ;
long V_167 ;
int V_13 , V_161 ;
struct V_168 * V_169 ;
V_161 = F_133 ( V_8 ) ;
V_165 = V_167 = F_177 ( V_8 , V_19 , V_144 ) ;
if ( V_165 < 0 )
return F_181 ( - V_14 ) ;
if ( V_165 || V_85 ) {
V_167 = F_11 ( V_2 , 1 ) ;
if ( V_167 < 0 ) {
F_179 ( V_8 , V_19 , V_144 ) ;
return F_181 ( - V_170 ) ;
}
if ( V_85 )
V_167 = 1 ;
}
V_13 = F_182 ( V_161 , F_112 ( V_8 ) , & V_169 ) ;
if ( V_13 )
goto V_171;
F_9 ( & V_126 ) ;
V_75 = F_64 ( V_8 , V_19 , V_144 , V_85 , V_167 ) ;
if ( ! V_75 ) {
F_2 ( & V_126 ) ;
V_75 = F_169 ( V_8 , V_19 , V_144 ) ;
if ( ! V_75 )
goto V_172;
if ( ! V_85 && F_55 ( V_19 , V_167 ) ) {
F_70 ( V_75 ) ;
V_8 -> V_94 -- ;
}
F_9 ( & V_126 ) ;
F_58 ( & V_75 -> V_77 , & V_8 -> V_81 ) ;
}
F_183 ( V_161 , F_112 ( V_8 ) , V_169 , V_75 ) ;
F_2 ( & V_126 ) ;
F_130 ( V_75 , ( unsigned long ) V_2 ) ;
V_166 = F_178 ( V_8 , V_19 , V_144 ) ;
if ( F_72 ( V_165 > V_166 ) ) {
long V_48 ;
V_48 = F_12 ( V_2 , 1 ) ;
F_3 ( V_8 , - V_48 ) ;
}
return V_75 ;
V_172:
F_184 ( V_161 , F_112 ( V_8 ) , V_169 ) ;
V_171:
if ( V_165 || V_85 )
F_12 ( V_2 , 1 ) ;
F_179 ( V_8 , V_19 , V_144 ) ;
return F_181 ( - V_170 ) ;
}
struct V_75 * F_185 ( struct V_18 * V_19 ,
unsigned long V_144 , int V_85 )
{
struct V_75 * V_75 = F_180 ( V_19 , V_144 , V_85 ) ;
if ( F_186 ( V_75 ) )
V_75 = NULL ;
return V_75 ;
}
int __weak F_187 ( struct V_7 * V_8 )
{
struct V_173 * V_174 ;
int V_113 , V_114 ;
F_108 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_144 ;
V_144 = F_188 (
F_119 ( V_8 ) , F_119 ( V_8 ) ,
0 , V_175 , V_114 ) ;
if ( V_144 ) {
V_174 = V_144 ;
goto V_176;
}
}
return 0 ;
V_176:
F_10 ( ! F_160 ( F_189 ( V_174 ) , F_119 ( V_8 ) ) ) ;
F_22 ( & V_174 -> V_177 , & V_178 ) ;
V_174 -> V_7 = V_8 ;
return 1 ;
}
static void T_4 F_190 ( struct V_75 * V_75 ,
unsigned int V_101 )
{
if ( F_72 ( V_101 > ( V_134 - 1 ) ) )
F_105 ( V_75 , V_101 ) ;
else
F_191 ( V_75 , V_101 ) ;
}
static void T_4 F_192 ( void )
{
struct V_173 * V_174 ;
F_18 (m, &huge_boot_pages, list) {
struct V_7 * V_8 = V_174 -> V_7 ;
struct V_75 * V_75 ;
#ifdef F_193
V_75 = F_93 ( V_174 -> V_179 >> V_180 ) ;
F_194 ( F_195 ( V_174 ) ,
sizeof( struct V_173 ) ) ;
#else
V_75 = F_196 ( V_174 ) ;
#endif
F_197 ( F_95 ( V_75 ) != 1 ) ;
F_190 ( V_75 , V_8 -> V_101 ) ;
F_197 ( F_94 ( V_75 ) ) ;
F_106 ( V_8 , V_75 , F_57 ( V_75 ) ) ;
if ( F_111 ( V_8 ) )
F_198 ( V_75 , 1 << V_8 -> V_101 ) ;
}
}
static void T_4 F_199 ( struct V_7 * V_8 )
{
unsigned long V_102 ;
for ( V_102 = 0 ; V_102 < V_8 -> V_181 ; ++ V_102 ) {
if ( F_111 ( V_8 ) ) {
if ( ! F_187 ( V_8 ) )
break;
} else if ( ! F_151 ( V_8 ,
& V_157 [ V_158 ] ) )
break;
}
V_8 -> V_181 = V_102 ;
}
static void T_4 F_200 ( void )
{
struct V_7 * V_8 ;
F_118 (h) {
if ( V_143 > F_36 ( V_8 ) )
V_143 = F_36 ( V_8 ) ;
if ( ! F_111 ( V_8 ) )
F_199 ( V_8 ) ;
}
F_19 ( V_143 == V_182 ) ;
}
static char * T_4 F_201 ( char * V_183 , unsigned long V_184 )
{
if ( V_184 >= ( 1UL << 30 ) )
sprintf ( V_183 , L_1 , V_184 >> 30 ) ;
else if ( V_184 >= ( 1UL << 20 ) )
sprintf ( V_183 , L_2 , V_184 >> 20 ) ;
else
sprintf ( V_183 , L_3 , V_184 >> 10 ) ;
return V_183 ;
}
static void T_4 F_202 ( void )
{
struct V_7 * V_8 ;
F_118 (h) {
char V_183 [ 32 ] ;
F_203 ( L_4 ,
F_201 ( V_183 , F_119 ( V_8 ) ) ,
V_8 -> V_79 ) ;
}
}
static void F_204 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_97 )
{
int V_102 ;
if ( F_111 ( V_8 ) )
return;
F_205 (i, *nodes_allowed) {
struct V_75 * V_75 , * V_142 ;
struct V_25 * V_185 = & V_8 -> V_78 [ V_102 ] ;
F_23 (page, next, freel, lru) {
if ( V_3 >= V_8 -> V_115 )
return;
if ( F_206 ( V_75 ) )
continue;
F_21 ( & V_75 -> V_77 ) ;
F_110 ( V_8 , V_75 ) ;
V_8 -> V_79 -- ;
V_8 -> V_80 [ F_57 ( V_75 ) ] -- ;
}
}
}
static inline void F_204 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_97 )
{
}
static int F_207 ( struct V_7 * V_8 , T_3 * V_97 ,
int V_12 )
{
int V_113 , V_114 ;
F_19 ( V_12 != - 1 && V_12 != 1 ) ;
if ( V_12 < 0 ) {
F_108 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_127 [ V_114 ] )
goto V_176;
}
} else {
F_154 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_127 [ V_114 ] <
V_8 -> V_116 [ V_114 ] )
goto V_176;
}
}
return 0 ;
V_176:
V_8 -> V_128 += V_12 ;
V_8 -> V_127 [ V_114 ] += V_12 ;
return 1 ;
}
static unsigned long F_208 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_97 )
{
unsigned long V_186 , V_13 ;
if ( F_111 ( V_8 ) && ! F_109 () )
return V_8 -> V_181 ;
F_9 ( & V_126 ) ;
while ( V_8 -> V_128 && V_3 > F_209 ( V_8 ) ) {
if ( ! F_207 ( V_8 , V_97 , - 1 ) )
break;
}
while ( V_3 > F_209 ( V_8 ) ) {
F_2 ( & V_126 ) ;
if ( F_111 ( V_8 ) )
V_13 = F_107 ( V_8 , V_97 ) ;
else
V_13 = F_151 ( V_8 , V_97 ) ;
F_9 ( & V_126 ) ;
if ( ! V_13 )
goto V_45;
if ( F_210 ( V_187 ) )
goto V_45;
}
V_186 = V_8 -> V_94 + V_8 -> V_115 - V_8 -> V_79 ;
V_186 = F_32 ( V_3 , V_186 ) ;
F_204 ( V_8 , V_186 , V_97 ) ;
while ( V_186 < F_209 ( V_8 ) ) {
if ( ! F_153 ( V_8 , V_97 , 0 ) )
break;
F_174 ( & V_126 ) ;
}
while ( V_3 < F_209 ( V_8 ) ) {
if ( ! F_207 ( V_8 , V_97 , 1 ) )
break;
}
V_45:
V_13 = F_209 ( V_8 ) ;
F_2 ( & V_126 ) ;
return V_13 ;
}
static struct V_7 * F_211 ( struct V_188 * V_189 , int * V_190 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_191 ; V_102 ++ )
if ( V_192 [ V_102 ] == V_189 ) {
if ( V_190 )
* V_190 = V_147 ;
return & V_193 [ V_102 ] ;
}
return F_212 ( V_189 , V_190 ) ;
}
static T_5 F_213 ( struct V_188 * V_189 ,
struct V_194 * V_195 , char * V_183 )
{
struct V_7 * V_8 ;
unsigned long V_115 ;
int V_76 ;
V_8 = F_211 ( V_189 , & V_76 ) ;
if ( V_76 == V_147 )
V_115 = V_8 -> V_115 ;
else
V_115 = V_8 -> V_116 [ V_76 ] ;
return sprintf ( V_183 , L_5 , V_115 ) ;
}
static T_5 F_214 ( bool V_196 ,
struct V_7 * V_8 , int V_76 ,
unsigned long V_3 , T_6 V_197 )
{
int V_95 ;
F_215 ( T_3 , V_97 , V_10 | V_198 ) ;
if ( F_111 ( V_8 ) && ! F_109 () ) {
V_95 = - V_199 ;
goto V_45;
}
if ( V_76 == V_147 ) {
if ( ! ( V_196 &&
F_216 ( V_97 ) ) ) {
F_217 ( V_97 ) ;
V_97 = & V_157 [ V_158 ] ;
}
} else if ( V_97 ) {
V_3 += V_8 -> V_115 - V_8 -> V_116 [ V_76 ] ;
F_218 ( V_97 , V_76 ) ;
} else
V_97 = & V_157 [ V_158 ] ;
V_8 -> V_181 = F_208 ( V_8 , V_3 , V_97 ) ;
if ( V_97 != & V_157 [ V_158 ] )
F_217 ( V_97 ) ;
return V_197 ;
V_45:
F_217 ( V_97 ) ;
return V_95 ;
}
static T_5 F_219 ( bool V_196 ,
struct V_188 * V_189 , const char * V_183 ,
T_6 V_197 )
{
struct V_7 * V_8 ;
unsigned long V_3 ;
int V_76 ;
int V_95 ;
V_95 = F_220 ( V_183 , 10 , & V_3 ) ;
if ( V_95 )
return V_95 ;
V_8 = F_211 ( V_189 , & V_76 ) ;
return F_214 ( V_196 , V_8 , V_76 , V_3 , V_197 ) ;
}
static T_5 F_221 ( struct V_188 * V_189 ,
struct V_194 * V_195 , char * V_183 )
{
return F_213 ( V_189 , V_195 , V_183 ) ;
}
static T_5 F_222 ( struct V_188 * V_189 ,
struct V_194 * V_195 , const char * V_183 , T_6 V_197 )
{
return F_219 ( false , V_189 , V_183 , V_197 ) ;
}
static T_5 F_223 ( struct V_188 * V_189 ,
struct V_194 * V_195 , char * V_183 )
{
return F_213 ( V_189 , V_195 , V_183 ) ;
}
static T_5 F_224 ( struct V_188 * V_189 ,
struct V_194 * V_195 , const char * V_183 , T_6 V_197 )
{
return F_219 ( true , V_189 , V_183 , V_197 ) ;
}
static T_5 F_225 ( struct V_188 * V_189 ,
struct V_194 * V_195 , char * V_183 )
{
struct V_7 * V_8 = F_211 ( V_189 , NULL ) ;
return sprintf ( V_183 , L_5 , V_8 -> V_150 ) ;
}
static T_5 F_226 ( struct V_188 * V_189 ,
struct V_194 * V_195 , const char * V_183 , T_6 V_3 )
{
int V_95 ;
unsigned long V_200 ;
struct V_7 * V_8 = F_211 ( V_189 , NULL ) ;
if ( F_111 ( V_8 ) )
return - V_199 ;
V_95 = F_220 ( V_183 , 10 , & V_200 ) ;
if ( V_95 )
return V_95 ;
F_9 ( & V_126 ) ;
V_8 -> V_150 = V_200 ;
F_2 ( & V_126 ) ;
return V_3 ;
}
static T_5 F_227 ( struct V_188 * V_189 ,
struct V_194 * V_195 , char * V_183 )
{
struct V_7 * V_8 ;
unsigned long V_79 ;
int V_76 ;
V_8 = F_211 ( V_189 , & V_76 ) ;
if ( V_76 == V_147 )
V_79 = V_8 -> V_79 ;
else
V_79 = V_8 -> V_80 [ V_76 ] ;
return sprintf ( V_183 , L_5 , V_79 ) ;
}
static T_5 F_228 ( struct V_188 * V_189 ,
struct V_194 * V_195 , char * V_183 )
{
struct V_7 * V_8 = F_211 ( V_189 , NULL ) ;
return sprintf ( V_183 , L_5 , V_8 -> V_94 ) ;
}
static T_5 F_229 ( struct V_188 * V_189 ,
struct V_194 * V_195 , char * V_183 )
{
struct V_7 * V_8 ;
unsigned long V_128 ;
int V_76 ;
V_8 = F_211 ( V_189 , & V_76 ) ;
if ( V_76 == V_147 )
V_128 = V_8 -> V_128 ;
else
V_128 = V_8 -> V_127 [ V_76 ] ;
return sprintf ( V_183 , L_5 , V_128 ) ;
}
static int F_230 ( struct V_7 * V_8 , struct V_188 * V_201 ,
struct V_188 * * V_192 ,
struct V_202 * V_203 )
{
int V_204 ;
int V_205 = F_133 ( V_8 ) ;
V_192 [ V_205 ] = F_231 ( V_8 -> V_206 , V_201 ) ;
if ( ! V_192 [ V_205 ] )
return - V_14 ;
V_204 = F_232 ( V_192 [ V_205 ] , V_203 ) ;
if ( V_204 )
F_233 ( V_192 [ V_205 ] ) ;
return V_204 ;
}
static void T_4 F_234 ( void )
{
struct V_7 * V_8 ;
int V_95 ;
V_207 = F_231 ( L_6 , V_208 ) ;
if ( ! V_207 )
return;
F_118 (h) {
V_95 = F_230 ( V_8 , V_207 ,
V_192 , & V_203 ) ;
if ( V_95 )
F_235 ( L_7 , V_8 -> V_206 ) ;
}
}
static struct V_7 * F_212 ( struct V_188 * V_189 , int * V_190 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_209 ; V_76 ++ ) {
struct V_210 * V_211 = & V_212 [ V_76 ] ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_191 ; V_102 ++ )
if ( V_211 -> V_192 [ V_102 ] == V_189 ) {
if ( V_190 )
* V_190 = V_76 ;
return & V_193 [ V_102 ] ;
}
}
F_176 () ;
return NULL ;
}
static void F_236 ( struct V_114 * V_114 )
{
struct V_7 * V_8 ;
struct V_210 * V_211 = & V_212 [ V_114 -> V_213 . V_214 ] ;
if ( ! V_211 -> V_207 )
return;
F_118 (h) {
int V_161 = F_133 ( V_8 ) ;
if ( V_211 -> V_192 [ V_161 ] ) {
F_233 ( V_211 -> V_192 [ V_161 ] ) ;
V_211 -> V_192 [ V_161 ] = NULL ;
}
}
F_233 ( V_211 -> V_207 ) ;
V_211 -> V_207 = NULL ;
}
static void F_237 ( struct V_114 * V_114 )
{
struct V_7 * V_8 ;
struct V_210 * V_211 = & V_212 [ V_114 -> V_213 . V_214 ] ;
int V_95 ;
if ( V_211 -> V_207 )
return;
V_211 -> V_207 = F_231 ( L_6 ,
& V_114 -> V_213 . V_189 ) ;
if ( ! V_211 -> V_207 )
return;
F_118 (h) {
V_95 = F_230 ( V_8 , V_211 -> V_207 ,
V_211 -> V_192 ,
& V_215 ) ;
if ( V_95 ) {
F_235 ( L_8 ,
V_8 -> V_206 , V_114 -> V_213 . V_214 ) ;
F_236 ( V_114 ) ;
break;
}
}
}
static void T_4 F_238 ( void )
{
int V_76 ;
F_239 (nid, N_MEMORY) {
struct V_114 * V_114 = V_216 [ V_76 ] ;
if ( V_114 -> V_213 . V_214 == V_76 )
F_237 ( V_114 ) ;
}
F_240 ( F_237 ,
F_236 ) ;
}
static struct V_7 * F_212 ( struct V_188 * V_189 , int * V_190 )
{
F_176 () ;
if ( V_190 )
* V_190 = - 1 ;
return NULL ;
}
static void F_238 ( void ) { }
static int T_4 F_241 ( void )
{
int V_102 ;
if ( ! F_159 () )
return 0 ;
if ( ! F_117 ( V_217 ) ) {
V_217 = V_218 ;
if ( ! F_117 ( V_217 ) )
F_242 ( V_219 ) ;
}
V_220 = F_133 ( F_117 ( V_217 ) ) ;
if ( V_221 ) {
if ( ! V_222 . V_181 )
V_222 . V_181 = V_221 ;
}
F_200 () ;
F_192 () ;
F_202 () ;
F_234 () ;
F_238 () ;
F_243 () ;
#ifdef F_244
V_223 = F_245 ( 8 * F_246 () ) ;
#else
V_223 = 1 ;
#endif
V_224 =
F_25 ( sizeof( struct V_225 ) * V_223 , V_10 ) ;
F_10 ( ! V_224 ) ;
for ( V_102 = 0 ; V_102 < V_223 ; V_102 ++ )
F_247 ( & V_224 [ V_102 ] ) ;
return 0 ;
}
void T_4 F_242 ( unsigned int V_101 )
{
struct V_7 * V_8 ;
unsigned long V_102 ;
if ( F_117 ( V_54 << V_101 ) ) {
F_248 ( L_9 ) ;
return;
}
F_10 ( V_226 >= V_191 ) ;
F_10 ( V_101 == 0 ) ;
V_8 = & V_193 [ V_226 ++ ] ;
V_8 -> V_101 = V_101 ;
V_8 -> V_227 = ~ ( ( 1ULL << ( V_101 + V_180 ) ) - 1 ) ;
V_8 -> V_115 = 0 ;
V_8 -> V_79 = 0 ;
for ( V_102 = 0 ; V_102 < V_98 ; ++ V_102 )
F_26 ( & V_8 -> V_78 [ V_102 ] ) ;
F_26 ( & V_8 -> V_81 ) ;
V_8 -> V_99 = F_76 ( V_157 [ V_158 ] ) ;
V_8 -> V_100 = F_76 ( V_157 [ V_158 ] ) ;
snprintf ( V_8 -> V_206 , V_228 , L_10 ,
F_119 ( V_8 ) / 1024 ) ;
V_229 = V_8 ;
}
static int T_4 F_249 ( char * V_230 )
{
unsigned long * V_231 ;
static unsigned long * V_232 ;
if ( ! V_226 )
V_231 = & V_221 ;
else
V_231 = & V_229 -> V_181 ;
if ( V_231 == V_232 ) {
F_248 ( L_11 ) ;
return 1 ;
}
if ( sscanf ( V_230 , L_12 , V_231 ) <= 0 )
* V_231 = 0 ;
if ( V_226 && V_229 -> V_101 >= V_134 )
F_199 ( V_229 ) ;
V_232 = V_231 ;
return 1 ;
}
static int T_4 F_250 ( char * V_230 )
{
V_217 = F_251 ( V_230 , & V_230 ) ;
return 1 ;
}
static unsigned int F_252 ( unsigned int * V_233 )
{
int V_114 ;
unsigned int V_234 = 0 ;
F_205 (node, cpuset_current_mems_allowed)
V_234 += V_233 [ V_114 ] ;
return V_234 ;
}
static int F_253 ( bool V_196 ,
struct V_235 * V_236 , int V_237 ,
void T_7 * V_238 , T_6 * V_239 , T_8 * V_240 )
{
struct V_7 * V_8 = & V_222 ;
unsigned long V_152 = V_8 -> V_181 ;
int V_13 ;
if ( ! F_159 () )
return - V_241 ;
V_236 -> V_242 = & V_152 ;
V_236 -> V_243 = sizeof( unsigned long ) ;
V_13 = F_254 ( V_236 , V_237 , V_238 , V_239 , V_240 ) ;
if ( V_13 )
goto V_45;
if ( V_237 )
V_13 = F_214 ( V_196 , V_8 ,
V_147 , V_152 , * V_239 ) ;
V_45:
return V_13 ;
}
int F_255 ( struct V_235 * V_236 , int V_237 ,
void T_7 * V_238 , T_6 * V_239 , T_8 * V_240 )
{
return F_253 ( false , V_236 , V_237 ,
V_238 , V_239 , V_240 ) ;
}
int F_256 ( struct V_235 * V_236 , int V_237 ,
void T_7 * V_238 , T_6 * V_239 , T_8 * V_240 )
{
return F_253 ( true , V_236 , V_237 ,
V_238 , V_239 , V_240 ) ;
}
int F_257 ( struct V_235 * V_236 , int V_237 ,
void T_7 * V_238 ,
T_6 * V_239 , T_8 * V_240 )
{
struct V_7 * V_8 = & V_222 ;
unsigned long V_152 ;
int V_13 ;
if ( ! F_159 () )
return - V_241 ;
V_152 = V_8 -> V_150 ;
if ( V_237 && F_111 ( V_8 ) )
return - V_199 ;
V_236 -> V_242 = & V_152 ;
V_236 -> V_243 = sizeof( unsigned long ) ;
V_13 = F_254 ( V_236 , V_237 , V_238 , V_239 , V_240 ) ;
if ( V_13 )
goto V_45;
if ( V_237 ) {
F_9 ( & V_126 ) ;
V_8 -> V_150 = V_152 ;
F_2 ( & V_126 ) ;
}
V_45:
return V_13 ;
}
void F_258 ( struct V_244 * V_174 )
{
struct V_7 * V_8 = & V_222 ;
if ( ! F_159 () )
return;
F_259 ( V_174 ,
L_13
L_14
L_15
L_16
L_17 ,
V_8 -> V_115 ,
V_8 -> V_79 ,
V_8 -> V_94 ,
V_8 -> V_128 ,
1UL << ( F_36 ( V_8 ) + V_180 - 10 ) ) ;
}
int F_260 ( int V_76 , char * V_183 )
{
struct V_7 * V_8 = & V_222 ;
if ( ! F_159 () )
return 0 ;
return sprintf ( V_183 ,
L_18
L_19
L_20 ,
V_76 , V_8 -> V_116 [ V_76 ] ,
V_76 , V_8 -> V_80 [ V_76 ] ,
V_76 , V_8 -> V_127 [ V_76 ] ) ;
}
void F_261 ( void )
{
struct V_7 * V_8 ;
int V_76 ;
if ( ! F_159 () )
return;
F_239 (nid, N_MEMORY)
F_118 (h)
F_203 ( L_21 ,
V_76 ,
V_8 -> V_116 [ V_76 ] ,
V_8 -> V_80 [ V_76 ] ,
V_8 -> V_127 [ V_76 ] ,
1UL << ( F_36 ( V_8 ) + V_180 - 10 ) ) ;
}
void F_262 ( struct V_244 * V_174 , struct V_245 * V_246 )
{
F_259 ( V_174 , L_22 ,
F_263 ( & V_246 -> V_247 ) << ( V_180 - 10 ) ) ;
}
unsigned long F_264 ( void )
{
struct V_7 * V_8 ;
unsigned long V_248 = 0 ;
F_118 (h)
V_248 += V_8 -> V_115 * F_112 ( V_8 ) ;
return V_248 ;
}
static int F_3 ( struct V_7 * V_8 , long V_12 )
{
int V_13 = - V_14 ;
F_9 ( & V_126 ) ;
if ( V_12 > 0 ) {
if ( F_171 ( V_8 , V_12 ) < 0 )
goto V_45;
if ( V_12 > F_252 ( V_8 -> V_80 ) ) {
F_173 ( V_8 , V_12 ) ;
goto V_45;
}
}
V_13 = 0 ;
if ( V_12 < 0 )
F_173 ( V_8 , ( unsigned long ) - V_12 ) ;
V_45:
F_2 ( & V_126 ) ;
return V_13 ;
}
static void F_265 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_49 ( V_19 ) ;
if ( V_22 && F_53 ( V_19 , V_74 ) )
F_266 ( & V_22 -> V_57 ) ;
}
static void F_267 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_21 * V_22 = F_49 ( V_19 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
unsigned long V_249 , V_250 , V_251 ;
long V_252 ;
if ( ! V_22 || ! F_53 ( V_19 , V_74 ) )
return;
V_250 = F_34 ( V_8 , V_19 , V_19 -> V_52 ) ;
V_251 = F_34 ( V_8 , V_19 , V_19 -> V_253 ) ;
V_249 = ( V_251 - V_250 ) - F_31 ( V_22 , V_250 , V_251 ) ;
F_268 ( & V_22 -> V_57 , F_46 ) ;
if ( V_249 ) {
V_252 = F_12 ( V_2 , V_249 ) ;
F_3 ( V_8 , - V_252 ) ;
}
}
static int F_269 ( struct V_18 * V_19 , struct V_254 * V_255 )
{
F_176 () ;
return 0 ;
}
static T_9 F_270 ( struct V_18 * V_19 , struct V_75 * V_75 ,
int V_256 )
{
T_9 V_257 ;
if ( V_256 ) {
V_257 = F_271 ( F_272 ( F_273 ( V_75 ,
V_19 -> V_258 ) ) ) ;
} else {
V_257 = F_274 ( F_273 ( V_75 ,
V_19 -> V_258 ) ) ;
}
V_257 = F_275 ( V_257 ) ;
V_257 = F_276 ( V_257 ) ;
V_257 = F_277 ( V_257 , V_19 , V_75 , V_256 ) ;
return V_257 ;
}
static void F_278 ( struct V_18 * V_19 ,
unsigned long V_51 , T_9 * V_259 )
{
T_9 V_257 ;
V_257 = F_271 ( F_272 ( F_279 ( V_259 ) ) ) ;
if ( F_280 ( V_19 , V_51 , V_259 , V_257 , 1 ) )
F_281 ( V_19 , V_51 , V_259 ) ;
}
static int F_282 ( T_9 V_260 )
{
T_10 V_261 ;
if ( F_283 ( V_260 ) || F_284 ( V_260 ) )
return 0 ;
V_261 = F_285 ( V_260 ) ;
if ( F_286 ( V_261 ) && F_287 ( V_261 ) )
return 1 ;
else
return 0 ;
}
static int F_288 ( T_9 V_260 )
{
T_10 V_261 ;
if ( F_283 ( V_260 ) || F_284 ( V_260 ) )
return 0 ;
V_261 = F_285 ( V_260 ) ;
if ( F_286 ( V_261 ) && F_289 ( V_261 ) )
return 1 ;
else
return 0 ;
}
int F_290 ( struct V_245 * V_262 , struct V_245 * V_263 ,
struct V_18 * V_19 )
{
T_9 * V_264 , * V_265 , V_257 ;
struct V_75 * V_266 ;
unsigned long V_144 ;
int V_267 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_268 = F_119 ( V_8 ) ;
unsigned long V_269 ;
unsigned long V_270 ;
int V_13 = 0 ;
V_267 = ( V_19 -> V_63 & ( V_271 | V_272 ) ) == V_272 ;
V_269 = V_19 -> V_52 ;
V_270 = V_19 -> V_253 ;
if ( V_267 )
F_291 ( V_263 , V_269 , V_270 ) ;
for ( V_144 = V_19 -> V_52 ; V_144 < V_19 -> V_253 ; V_144 += V_268 ) {
T_11 * V_273 , * V_274 ;
V_264 = F_292 ( V_263 , V_144 ) ;
if ( ! V_264 )
continue;
V_265 = F_293 ( V_262 , V_144 , V_268 ) ;
if ( ! V_265 ) {
V_13 = - V_14 ;
break;
}
if ( V_265 == V_264 )
continue;
V_274 = F_294 ( V_8 , V_262 , V_265 ) ;
V_273 = F_295 ( V_8 , V_263 , V_264 ) ;
F_296 ( V_273 , V_275 ) ;
V_257 = F_279 ( V_264 ) ;
if ( F_283 ( V_257 ) ) {
;
} else if ( F_72 ( F_282 ( V_257 ) ||
F_288 ( V_257 ) ) ) {
T_10 V_276 = F_285 ( V_257 ) ;
if ( F_297 ( V_276 ) && V_267 ) {
F_298 ( & V_276 ) ;
V_257 = F_299 ( V_276 ) ;
F_300 ( V_263 , V_144 , V_264 , V_257 ) ;
}
F_300 ( V_262 , V_144 , V_265 , V_257 ) ;
} else {
if ( V_267 ) {
F_301 ( V_263 , V_144 , V_264 ) ;
F_302 ( V_263 , V_269 ,
V_270 ) ;
}
V_257 = F_279 ( V_264 ) ;
V_266 = F_303 ( V_257 ) ;
F_304 ( V_266 ) ;
F_305 ( V_266 , true ) ;
F_300 ( V_262 , V_144 , V_265 , V_257 ) ;
F_306 ( F_112 ( V_8 ) , V_262 ) ;
}
F_2 ( V_273 ) ;
F_2 ( V_274 ) ;
}
if ( V_267 )
F_307 ( V_263 , V_269 , V_270 ) ;
return V_13 ;
}
void F_308 ( struct V_277 * V_278 , struct V_18 * V_19 ,
unsigned long V_250 , unsigned long V_251 ,
struct V_75 * V_279 )
{
int V_280 = 0 ;
struct V_245 * V_246 = V_19 -> V_281 ;
unsigned long V_51 ;
T_9 * V_259 ;
T_9 V_260 ;
T_11 * V_282 ;
struct V_75 * V_75 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_268 = F_119 ( V_8 ) ;
const unsigned long V_269 = V_250 ;
const unsigned long V_270 = V_251 ;
F_197 ( ! F_40 ( V_19 ) ) ;
F_10 ( V_250 & ~ F_309 ( V_8 ) ) ;
F_10 ( V_251 & ~ F_309 ( V_8 ) ) ;
F_310 ( V_278 , V_19 ) ;
F_291 ( V_246 , V_269 , V_270 ) ;
V_51 = V_250 ;
V_283:
for (; V_51 < V_251 ; V_51 += V_268 ) {
V_259 = F_292 ( V_246 , V_51 ) ;
if ( ! V_259 )
continue;
V_282 = F_294 ( V_8 , V_246 , V_259 ) ;
if ( F_311 ( V_246 , & V_51 , V_259 ) )
goto V_284;
V_260 = F_279 ( V_259 ) ;
if ( F_283 ( V_260 ) )
goto V_284;
if ( F_72 ( ! F_284 ( V_260 ) ) ) {
F_312 ( V_246 , V_51 , V_259 ) ;
goto V_284;
}
V_75 = F_303 ( V_260 ) ;
if ( V_279 ) {
if ( V_75 != V_279 )
goto V_284;
F_52 ( V_19 , V_285 ) ;
}
V_260 = F_313 ( V_246 , V_51 , V_259 ) ;
F_314 ( V_278 , V_259 , V_51 ) ;
if ( F_315 ( V_260 ) )
F_316 ( V_75 ) ;
F_317 ( F_112 ( V_8 ) , V_246 ) ;
F_318 ( V_75 , true ) ;
V_280 = ! F_319 ( V_278 , V_75 ) ;
if ( V_280 ) {
V_51 += V_268 ;
F_2 ( V_282 ) ;
break;
}
if ( V_279 ) {
F_2 ( V_282 ) ;
break;
}
V_284:
F_2 ( V_282 ) ;
}
if ( V_280 ) {
V_280 = 0 ;
F_320 ( V_278 ) ;
if ( V_51 < V_251 && ! V_279 )
goto V_283;
}
F_307 ( V_246 , V_269 , V_270 ) ;
F_321 ( V_278 , V_19 ) ;
}
void F_322 ( struct V_277 * V_278 ,
struct V_18 * V_19 , unsigned long V_250 ,
unsigned long V_251 , struct V_75 * V_279 )
{
F_308 ( V_278 , V_19 , V_250 , V_251 , V_279 ) ;
V_19 -> V_63 &= ~ V_64 ;
}
void F_323 ( struct V_18 * V_19 , unsigned long V_250 ,
unsigned long V_251 , struct V_75 * V_279 )
{
struct V_245 * V_246 ;
struct V_277 V_278 ;
V_246 = V_19 -> V_281 ;
F_324 ( & V_278 , V_246 , V_250 , V_251 ) ;
F_308 ( & V_278 , V_19 , V_250 , V_251 , V_279 ) ;
F_325 ( & V_278 , V_250 , V_251 ) ;
}
static void F_326 ( struct V_245 * V_246 , struct V_18 * V_19 ,
struct V_75 * V_75 , unsigned long V_51 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_18 * V_286 ;
struct V_65 * V_66 ;
T_1 V_287 ;
V_51 = V_51 & F_309 ( V_8 ) ;
V_287 = ( ( V_51 - V_19 -> V_52 ) >> V_180 ) +
V_19 -> V_53 ;
V_66 = F_16 ( V_19 -> V_20 ) -> V_61 ;
F_327 ( V_66 ) ;
F_328 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_286 == V_19 )
continue;
if ( V_286 -> V_63 & V_64 )
continue;
if ( ! F_53 ( V_286 , V_74 ) )
F_323 ( V_286 , V_51 ,
V_51 + F_119 ( V_8 ) , V_75 ) ;
}
F_329 ( V_66 ) ;
}
static int F_330 ( struct V_245 * V_246 , struct V_18 * V_19 ,
unsigned long V_51 , T_9 * V_259 , T_9 V_260 ,
struct V_75 * V_288 , T_11 * V_282 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_75 * V_289 , * V_290 ;
int V_13 = 0 , V_291 = 0 ;
unsigned long V_269 ;
unsigned long V_270 ;
V_289 = F_303 ( V_260 ) ;
V_292:
if ( F_131 ( V_289 ) == 1 && F_331 ( V_289 ) ) {
F_332 ( V_289 , V_19 , V_51 ) ;
F_278 ( V_19 , V_51 , V_259 ) ;
return 0 ;
}
if ( F_53 ( V_19 , V_74 ) &&
V_289 != V_288 )
V_291 = 1 ;
F_304 ( V_289 ) ;
F_2 ( V_282 ) ;
V_290 = F_180 ( V_19 , V_51 , V_291 ) ;
if ( F_186 ( V_290 ) ) {
if ( V_291 ) {
F_136 ( V_289 ) ;
F_10 ( F_283 ( V_260 ) ) ;
F_326 ( V_246 , V_19 , V_289 , V_51 ) ;
F_10 ( F_283 ( V_260 ) ) ;
F_9 ( V_282 ) ;
V_259 = F_292 ( V_246 , V_51 & F_309 ( V_8 ) ) ;
if ( F_333 ( V_259 &&
F_334 ( F_279 ( V_259 ) , V_260 ) ) )
goto V_292;
return 0 ;
}
V_13 = ( F_335 ( V_290 ) == - V_14 ) ?
V_293 : V_294 ;
goto V_295;
}
if ( F_72 ( F_336 ( V_19 ) ) ) {
V_13 = V_293 ;
goto V_296;
}
F_337 ( V_290 , V_289 , V_51 , V_19 ,
F_112 ( V_8 ) ) ;
F_338 ( V_290 ) ;
F_123 ( V_290 ) ;
V_269 = V_51 & F_309 ( V_8 ) ;
V_270 = V_269 + F_119 ( V_8 ) ;
F_291 ( V_246 , V_269 , V_270 ) ;
F_9 ( V_282 ) ;
V_259 = F_292 ( V_246 , V_51 & F_309 ( V_8 ) ) ;
if ( F_333 ( V_259 && F_334 ( F_279 ( V_259 ) , V_260 ) ) ) {
F_126 ( V_290 ) ;
F_339 ( V_19 , V_51 , V_259 ) ;
F_302 ( V_246 , V_269 , V_270 ) ;
F_300 ( V_246 , V_51 , V_259 ,
F_270 ( V_19 , V_290 , 1 ) ) ;
F_318 ( V_289 , true ) ;
F_340 ( V_290 , V_19 , V_51 ) ;
V_290 = V_289 ;
}
F_2 ( V_282 ) ;
F_307 ( V_246 , V_269 , V_270 ) ;
V_296:
F_136 ( V_290 ) ;
V_295:
F_136 ( V_289 ) ;
F_9 ( V_282 ) ;
return V_13 ;
}
static struct V_75 * F_341 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_51 )
{
struct V_65 * V_66 ;
T_1 V_161 ;
V_66 = V_19 -> V_20 -> V_67 ;
V_161 = F_34 ( V_8 , V_19 , V_51 ) ;
return F_342 ( V_66 , V_161 ) ;
}
static bool F_343 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_51 )
{
struct V_65 * V_66 ;
T_1 V_161 ;
struct V_75 * V_75 ;
V_66 = V_19 -> V_20 -> V_67 ;
V_161 = F_34 ( V_8 , V_19 , V_51 ) ;
V_75 = F_344 ( V_66 , V_161 ) ;
if ( V_75 )
F_136 ( V_75 ) ;
return V_75 != NULL ;
}
int F_345 ( struct V_75 * V_75 , struct V_65 * V_66 ,
T_1 V_161 )
{
struct V_16 * V_16 = V_66 -> V_68 ;
struct V_7 * V_8 = F_30 ( V_16 ) ;
int V_95 = F_346 ( V_75 , V_66 , V_161 , V_10 ) ;
if ( V_95 )
return V_95 ;
F_126 ( V_75 ) ;
F_9 ( & V_16 -> V_297 ) ;
V_16 -> V_298 += F_347 ( V_8 ) ;
F_2 ( & V_16 -> V_297 ) ;
return 0 ;
}
static int F_348 ( struct V_245 * V_246 , struct V_18 * V_19 ,
struct V_65 * V_66 , T_1 V_161 ,
unsigned long V_51 , T_9 * V_259 , unsigned int V_71 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
int V_13 = V_294 ;
int V_299 = 0 ;
unsigned long V_125 ;
struct V_75 * V_75 ;
T_9 V_300 ;
T_11 * V_282 ;
if ( F_53 ( V_19 , V_285 ) ) {
F_349 ( L_23 ,
V_187 -> V_301 ) ;
return V_13 ;
}
V_42:
V_75 = F_342 ( V_66 , V_161 ) ;
if ( ! V_75 ) {
V_125 = F_350 ( V_66 -> V_68 ) >> F_35 ( V_8 ) ;
if ( V_161 >= V_125 )
goto V_45;
V_75 = F_180 ( V_19 , V_51 , 0 ) ;
if ( F_186 ( V_75 ) ) {
V_13 = F_335 ( V_75 ) ;
if ( V_13 == - V_14 )
V_13 = V_293 ;
else
V_13 = V_294 ;
goto V_45;
}
F_351 ( V_75 , V_51 , F_112 ( V_8 ) ) ;
F_338 ( V_75 ) ;
F_123 ( V_75 ) ;
if ( V_19 -> V_63 & V_64 ) {
int V_95 = F_345 ( V_75 , V_66 , V_161 ) ;
if ( V_95 ) {
F_136 ( V_75 ) ;
if ( V_95 == - V_302 )
goto V_42;
goto V_45;
}
} else {
F_352 ( V_75 ) ;
if ( F_72 ( F_336 ( V_19 ) ) ) {
V_13 = V_293 ;
goto V_303;
}
V_299 = 1 ;
}
} else {
if ( F_72 ( F_353 ( V_75 ) ) ) {
V_13 = V_304 |
F_354 ( F_133 ( V_8 ) ) ;
goto V_303;
}
}
if ( ( V_71 & V_305 ) && ! ( V_19 -> V_63 & V_271 ) ) {
if ( F_177 ( V_8 , V_19 , V_51 ) < 0 ) {
V_13 = V_293 ;
goto V_303;
}
F_179 ( V_8 , V_19 , V_51 ) ;
}
V_282 = F_295 ( V_8 , V_246 , V_259 ) ;
F_9 ( V_282 ) ;
V_125 = F_350 ( V_66 -> V_68 ) >> F_35 ( V_8 ) ;
if ( V_161 >= V_125 )
goto V_306;
V_13 = 0 ;
if ( ! F_283 ( F_279 ( V_259 ) ) )
goto V_306;
if ( V_299 ) {
F_126 ( V_75 ) ;
F_340 ( V_75 , V_19 , V_51 ) ;
} else
F_305 ( V_75 , true ) ;
V_300 = F_270 ( V_19 , V_75 , ( ( V_19 -> V_63 & V_307 )
&& ( V_19 -> V_63 & V_271 ) ) ) ;
F_300 ( V_246 , V_51 , V_259 , V_300 ) ;
F_306 ( F_112 ( V_8 ) , V_246 ) ;
if ( ( V_71 & V_305 ) && ! ( V_19 -> V_63 & V_271 ) ) {
V_13 = F_330 ( V_246 , V_19 , V_51 , V_259 , V_300 , V_75 , V_282 ) ;
}
F_2 ( V_282 ) ;
F_355 ( V_75 ) ;
V_45:
return V_13 ;
V_306:
F_2 ( V_282 ) ;
V_303:
F_355 ( V_75 ) ;
F_136 ( V_75 ) ;
goto V_45;
}
T_12 F_356 ( struct V_7 * V_8 , struct V_245 * V_246 ,
struct V_18 * V_19 ,
struct V_65 * V_66 ,
T_1 V_161 , unsigned long V_51 )
{
unsigned long V_308 [ 2 ] ;
T_12 V_309 ;
if ( V_19 -> V_63 & V_271 ) {
V_308 [ 0 ] = ( unsigned long ) V_66 ;
V_308 [ 1 ] = V_161 ;
} else {
V_308 [ 0 ] = ( unsigned long ) V_246 ;
V_308 [ 1 ] = V_51 >> F_35 ( V_8 ) ;
}
V_309 = F_357 ( ( T_12 * ) & V_308 , sizeof( V_308 ) / sizeof( T_12 ) , 0 ) ;
return V_309 & ( V_223 - 1 ) ;
}
T_12 F_356 ( struct V_7 * V_8 , struct V_245 * V_246 ,
struct V_18 * V_19 ,
struct V_65 * V_66 ,
T_1 V_161 , unsigned long V_51 )
{
return 0 ;
}
int F_358 ( struct V_245 * V_246 , struct V_18 * V_19 ,
unsigned long V_51 , unsigned int V_71 )
{
T_9 * V_259 , V_257 ;
T_11 * V_282 ;
int V_13 ;
T_12 V_309 ;
T_1 V_161 ;
struct V_75 * V_75 = NULL ;
struct V_75 * V_288 = NULL ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_65 * V_66 ;
int V_310 = 0 ;
V_51 &= F_309 ( V_8 ) ;
V_259 = F_292 ( V_246 , V_51 ) ;
if ( V_259 ) {
V_257 = F_279 ( V_259 ) ;
if ( F_72 ( F_282 ( V_257 ) ) ) {
F_359 ( V_19 , V_246 , V_259 ) ;
return 0 ;
} else if ( F_72 ( F_288 ( V_257 ) ) )
return V_311 |
F_354 ( F_133 ( V_8 ) ) ;
} else {
V_259 = F_293 ( V_246 , V_51 , F_119 ( V_8 ) ) ;
if ( ! V_259 )
return V_293 ;
}
V_66 = V_19 -> V_20 -> V_67 ;
V_161 = F_34 ( V_8 , V_19 , V_51 ) ;
V_309 = F_356 ( V_8 , V_246 , V_19 , V_66 , V_161 , V_51 ) ;
F_360 ( & V_224 [ V_309 ] ) ;
V_257 = F_279 ( V_259 ) ;
if ( F_283 ( V_257 ) ) {
V_13 = F_348 ( V_246 , V_19 , V_66 , V_161 , V_51 , V_259 , V_71 ) ;
goto V_312;
}
V_13 = 0 ;
if ( ! F_284 ( V_257 ) )
goto V_312;
if ( ( V_71 & V_305 ) && ! F_361 ( V_257 ) ) {
if ( F_177 ( V_8 , V_19 , V_51 ) < 0 ) {
V_13 = V_293 ;
goto V_312;
}
F_179 ( V_8 , V_19 , V_51 ) ;
if ( ! ( V_19 -> V_63 & V_64 ) )
V_288 = F_341 ( V_8 ,
V_19 , V_51 ) ;
}
V_282 = F_294 ( V_8 , V_246 , V_259 ) ;
if ( F_72 ( ! F_334 ( V_257 , F_279 ( V_259 ) ) ) )
goto V_313;
V_75 = F_303 ( V_257 ) ;
if ( V_75 != V_288 )
if ( ! F_362 ( V_75 ) ) {
V_310 = 1 ;
goto V_313;
}
F_304 ( V_75 ) ;
if ( V_71 & V_305 ) {
if ( ! F_361 ( V_257 ) ) {
V_13 = F_330 ( V_246 , V_19 , V_51 , V_259 , V_257 ,
V_288 , V_282 ) ;
goto V_314;
}
V_257 = F_272 ( V_257 ) ;
}
V_257 = F_275 ( V_257 ) ;
if ( F_280 ( V_19 , V_51 , V_259 , V_257 ,
V_71 & V_305 ) )
F_281 ( V_19 , V_51 , V_259 ) ;
V_314:
if ( V_75 != V_288 )
F_355 ( V_75 ) ;
F_136 ( V_75 ) ;
V_313:
F_2 ( V_282 ) ;
if ( V_288 ) {
F_355 ( V_288 ) ;
F_136 ( V_288 ) ;
}
V_312:
F_363 ( & V_224 [ V_309 ] ) ;
if ( V_310 )
F_364 ( V_75 ) ;
return V_13 ;
}
long F_365 ( struct V_245 * V_246 , struct V_18 * V_19 ,
struct V_75 * * V_315 , struct V_18 * * V_316 ,
unsigned long * V_317 , unsigned long * V_103 ,
long V_102 , unsigned int V_71 )
{
unsigned long V_318 ;
unsigned long V_319 = * V_317 ;
unsigned long V_320 = * V_103 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
while ( V_319 < V_19 -> V_253 && V_320 ) {
T_9 * V_260 ;
T_11 * V_282 = NULL ;
int V_321 ;
struct V_75 * V_75 ;
if ( F_72 ( F_366 ( V_187 ) ) ) {
V_320 = 0 ;
break;
}
V_260 = F_292 ( V_246 , V_319 & F_309 ( V_8 ) ) ;
if ( V_260 )
V_282 = F_294 ( V_8 , V_246 , V_260 ) ;
V_321 = ! V_260 || F_283 ( F_279 ( V_260 ) ) ;
if ( V_321 && ( V_71 & V_322 ) &&
! F_343 ( V_8 , V_19 , V_319 ) ) {
if ( V_260 )
F_2 ( V_282 ) ;
V_320 = 0 ;
break;
}
if ( V_321 || F_367 ( F_279 ( V_260 ) ) ||
( ( V_71 & V_323 ) &&
! F_361 ( F_279 ( V_260 ) ) ) ) {
int V_13 ;
if ( V_260 )
F_2 ( V_282 ) ;
V_13 = F_358 ( V_246 , V_19 , V_319 ,
( V_71 & V_323 ) ? V_305 : 0 ) ;
if ( ! ( V_13 & V_324 ) )
continue;
V_320 = 0 ;
break;
}
V_318 = ( V_319 & ~ F_309 ( V_8 ) ) >> V_180 ;
V_75 = F_303 ( F_279 ( V_260 ) ) ;
V_325:
if ( V_315 ) {
V_315 [ V_102 ] = F_368 ( V_75 , V_318 ) ;
F_304 ( V_315 [ V_102 ] ) ;
}
if ( V_316 )
V_316 [ V_102 ] = V_19 ;
V_319 += V_54 ;
++ V_318 ;
-- V_320 ;
++ V_102 ;
if ( V_319 < V_19 -> V_253 && V_320 &&
V_318 < F_112 ( V_8 ) ) {
goto V_325;
}
F_2 ( V_282 ) ;
}
* V_103 = V_320 ;
* V_317 = V_319 ;
return V_102 ? V_102 : - V_326 ;
}
unsigned long F_369 ( struct V_18 * V_19 ,
unsigned long V_51 , unsigned long V_251 , T_13 V_327 )
{
struct V_245 * V_246 = V_19 -> V_281 ;
unsigned long V_250 = V_51 ;
T_9 * V_259 ;
T_9 V_260 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_315 = 0 ;
F_10 ( V_51 >= V_251 ) ;
F_370 ( V_19 , V_51 , V_251 ) ;
F_291 ( V_246 , V_250 , V_251 ) ;
F_327 ( V_19 -> V_20 -> V_67 ) ;
for (; V_51 < V_251 ; V_51 += F_119 ( V_8 ) ) {
T_11 * V_282 ;
V_259 = F_292 ( V_246 , V_51 ) ;
if ( ! V_259 )
continue;
V_282 = F_294 ( V_8 , V_246 , V_259 ) ;
if ( F_311 ( V_246 , & V_51 , V_259 ) ) {
V_315 ++ ;
F_2 ( V_282 ) ;
continue;
}
V_260 = F_279 ( V_259 ) ;
if ( F_72 ( F_288 ( V_260 ) ) ) {
F_2 ( V_282 ) ;
continue;
}
if ( F_72 ( F_282 ( V_260 ) ) ) {
T_10 V_257 = F_285 ( V_260 ) ;
if ( F_297 ( V_257 ) ) {
T_9 V_328 ;
F_298 ( & V_257 ) ;
V_328 = F_299 ( V_257 ) ;
F_300 ( V_246 , V_51 , V_259 , V_328 ) ;
V_315 ++ ;
}
F_2 ( V_282 ) ;
continue;
}
if ( ! F_283 ( V_260 ) ) {
V_260 = F_313 ( V_246 , V_51 , V_259 ) ;
V_260 = F_276 ( F_371 ( V_260 , V_327 ) ) ;
V_260 = F_277 ( V_260 , V_19 , NULL , 0 ) ;
F_300 ( V_246 , V_51 , V_259 , V_260 ) ;
V_315 ++ ;
}
F_2 ( V_282 ) ;
}
F_372 ( V_19 , V_250 , V_251 ) ;
F_302 ( V_246 , V_250 , V_251 ) ;
F_329 ( V_19 -> V_20 -> V_67 ) ;
F_307 ( V_246 , V_250 , V_251 ) ;
return V_315 << V_8 -> V_101 ;
}
int F_373 ( struct V_16 * V_16 ,
long V_35 , long V_33 ,
struct V_18 * V_19 ,
T_14 V_63 )
{
long V_13 , V_41 ;
struct V_7 * V_8 = F_30 ( V_16 ) ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
struct V_21 * V_21 ;
long V_252 ;
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
goto V_329;
}
V_252 = F_11 ( V_2 , V_41 ) ;
if ( V_252 < 0 ) {
V_13 = - V_170 ;
goto V_329;
}
V_13 = F_3 ( V_8 , V_252 ) ;
if ( V_13 < 0 ) {
( void ) F_12 ( V_2 , V_41 ) ;
goto V_329;
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
V_329:
if ( ! V_19 || V_19 -> V_63 & V_64 )
F_27 ( V_21 , V_35 , V_33 ) ;
if ( V_19 && F_53 ( V_19 , V_74 ) )
F_268 ( & V_21 -> V_57 , F_46 ) ;
return V_13 ;
}
long F_374 ( struct V_16 * V_16 , long V_250 , long V_251 ,
long V_330 )
{
struct V_7 * V_8 = F_30 ( V_16 ) ;
struct V_21 * V_21 = F_48 ( V_16 ) ;
long V_41 = 0 ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
long V_252 ;
if ( V_21 ) {
V_41 = F_28 ( V_21 , V_250 , V_251 ) ;
if ( V_41 < 0 )
return V_41 ;
}
F_9 ( & V_16 -> V_297 ) ;
V_16 -> V_298 -= ( F_347 ( V_8 ) * V_330 ) ;
F_2 ( & V_16 -> V_297 ) ;
V_252 = F_12 ( V_2 , ( V_41 - V_330 ) ) ;
F_3 ( V_8 , - V_252 ) ;
return 0 ;
}
static unsigned long F_375 ( struct V_18 * V_331 ,
struct V_18 * V_19 ,
unsigned long V_144 , T_1 V_161 )
{
unsigned long V_332 = ( ( V_161 - V_331 -> V_53 ) << V_180 ) +
V_331 -> V_52 ;
unsigned long V_333 = V_332 & V_334 ;
unsigned long V_335 = V_333 + V_336 ;
unsigned long V_63 = V_19 -> V_63 & V_337 ;
unsigned long V_338 = V_331 -> V_63 & V_337 ;
if ( F_376 ( V_144 ) != F_376 ( V_332 ) ||
V_63 != V_338 ||
V_333 < V_331 -> V_52 || V_331 -> V_253 < V_335 )
return 0 ;
return V_332 ;
}
static bool F_377 ( struct V_18 * V_19 , unsigned long V_144 )
{
unsigned long V_339 = V_144 & V_334 ;
unsigned long V_251 = V_339 + V_336 ;
if ( V_19 -> V_63 & V_64 &&
V_19 -> V_52 <= V_339 && V_251 <= V_19 -> V_253 )
return true ;
return false ;
}
T_9 * F_378 ( struct V_245 * V_246 , unsigned long V_144 , T_15 * V_340 )
{
struct V_18 * V_19 = F_379 ( V_246 , V_144 ) ;
struct V_65 * V_66 = V_19 -> V_20 -> V_67 ;
T_1 V_161 = ( ( V_144 - V_19 -> V_52 ) >> V_180 ) +
V_19 -> V_53 ;
struct V_18 * V_331 ;
unsigned long V_332 ;
T_9 * V_341 = NULL ;
T_9 * V_260 ;
T_11 * V_282 ;
if ( ! F_377 ( V_19 , V_144 ) )
return ( T_9 * ) F_380 ( V_246 , V_340 , V_144 ) ;
F_327 ( V_66 ) ;
F_328 (svma, &mapping->i_mmap, idx, idx) {
if ( V_331 == V_19 )
continue;
V_332 = F_375 ( V_331 , V_19 , V_144 , V_161 ) ;
if ( V_332 ) {
V_341 = F_292 ( V_331 -> V_281 , V_332 ) ;
if ( V_341 ) {
F_381 ( V_246 ) ;
F_304 ( F_196 ( V_341 ) ) ;
break;
}
}
}
if ( ! V_341 )
goto V_45;
V_282 = F_295 ( F_38 ( V_19 ) , V_246 , V_341 ) ;
F_9 ( V_282 ) ;
if ( F_382 ( * V_340 ) ) {
F_383 ( V_246 , V_340 ,
( V_342 * ) ( ( unsigned long ) V_341 & V_343 ) ) ;
} else {
F_136 ( F_196 ( V_341 ) ) ;
F_381 ( V_246 ) ;
}
F_2 ( V_282 ) ;
V_45:
V_260 = ( T_9 * ) F_380 ( V_246 , V_340 , V_144 ) ;
F_329 ( V_66 ) ;
return V_260 ;
}
int F_311 ( struct V_245 * V_246 , unsigned long * V_144 , T_9 * V_259 )
{
T_16 * V_344 = F_384 ( V_246 , * V_144 ) ;
T_15 * V_340 = F_385 ( V_344 , * V_144 ) ;
F_10 ( F_95 ( F_196 ( V_259 ) ) == 0 ) ;
if ( F_95 ( F_196 ( V_259 ) ) == 1 )
return 0 ;
F_386 ( V_340 ) ;
F_136 ( F_196 ( V_259 ) ) ;
F_387 ( V_246 ) ;
* V_144 = F_102 ( * V_144 , V_218 * V_345 ) - V_218 ;
return 1 ;
}
T_9 * F_378 ( struct V_245 * V_246 , unsigned long V_144 , T_15 * V_340 )
{
return NULL ;
}
int F_311 ( struct V_245 * V_246 , unsigned long * V_144 , T_9 * V_259 )
{
return 0 ;
}
T_9 * F_293 ( struct V_245 * V_246 ,
unsigned long V_144 , unsigned long V_268 )
{
T_16 * V_344 ;
T_15 * V_340 ;
T_9 * V_260 = NULL ;
V_344 = F_384 ( V_246 , V_144 ) ;
V_340 = F_388 ( V_246 , V_344 , V_144 ) ;
if ( V_340 ) {
if ( V_268 == V_336 ) {
V_260 = ( T_9 * ) V_340 ;
} else {
F_10 ( V_268 != V_346 ) ;
if ( F_389 () && F_382 ( * V_340 ) )
V_260 = F_378 ( V_246 , V_144 , V_340 ) ;
else
V_260 = ( T_9 * ) F_380 ( V_246 , V_340 , V_144 ) ;
}
}
F_10 ( V_260 && ! F_390 ( * V_260 ) && ! F_391 ( * V_260 ) ) ;
return V_260 ;
}
T_9 * F_292 ( struct V_245 * V_246 , unsigned long V_144 )
{
T_16 * V_344 ;
T_15 * V_340 ;
V_342 * V_347 = NULL ;
V_344 = F_384 ( V_246 , V_144 ) ;
if ( F_392 ( * V_344 ) ) {
V_340 = F_385 ( V_344 , V_144 ) ;
if ( F_393 ( * V_340 ) ) {
if ( F_394 ( * V_340 ) )
return ( T_9 * ) V_340 ;
V_347 = F_395 ( V_340 , V_144 ) ;
}
}
return ( T_9 * ) V_347 ;
}
struct V_75 * __weak
F_396 ( struct V_245 * V_246 , unsigned long V_51 ,
int V_237 )
{
return F_181 ( - V_199 ) ;
}
struct V_75 * __weak
F_397 ( struct V_245 * V_246 , unsigned long V_51 ,
V_342 * V_347 , int V_71 )
{
struct V_75 * V_75 = NULL ;
T_11 * V_282 ;
V_42:
V_282 = F_398 ( V_246 , V_347 ) ;
F_9 ( V_282 ) ;
if ( ! F_399 ( * V_347 ) )
goto V_45;
if ( F_400 ( * V_347 ) ) {
V_75 = F_401 ( * V_347 ) + ( ( V_51 & ~ V_348 ) >> V_180 ) ;
if ( V_71 & V_349 )
F_304 ( V_75 ) ;
} else {
if ( F_282 ( F_279 ( ( T_9 * ) V_347 ) ) ) {
F_2 ( V_282 ) ;
F_402 ( V_246 , ( T_9 * ) V_347 , V_282 ) ;
goto V_42;
}
}
V_45:
F_2 ( V_282 ) ;
return V_75 ;
}
struct V_75 * __weak
F_403 ( struct V_245 * V_246 , unsigned long V_51 ,
T_15 * V_340 , int V_71 )
{
if ( V_71 & V_349 )
return NULL ;
return F_303 ( * ( T_9 * ) V_340 ) + ( ( V_51 & ~ V_334 ) >> V_180 ) ;
}
int F_404 ( struct V_75 * V_350 )
{
struct V_7 * V_8 = F_128 ( V_350 ) ;
int V_76 = F_57 ( V_350 ) ;
int V_13 = - V_351 ;
F_9 ( & V_126 ) ;
if ( ! F_120 ( V_350 ) && ! F_95 ( V_350 ) ) {
F_405 ( & V_350 -> V_77 ) ;
F_61 ( V_350 ) ;
V_8 -> V_79 -- ;
V_8 -> V_80 [ V_76 ] -- ;
V_13 = 0 ;
}
F_2 ( & V_126 ) ;
return V_13 ;
}
bool F_406 ( struct V_75 * V_75 , struct V_25 * V_177 )
{
bool V_13 = true ;
F_113 ( ! F_121 ( V_75 ) , V_75 ) ;
F_9 ( & V_126 ) ;
if ( ! F_120 ( V_75 ) || ! F_407 ( V_75 ) ) {
V_13 = false ;
goto V_284;
}
F_125 ( V_75 ) ;
F_408 ( & V_75 -> V_77 , V_177 ) ;
V_284:
F_2 ( & V_126 ) ;
return V_13 ;
}
void F_409 ( struct V_75 * V_75 )
{
F_113 ( ! F_121 ( V_75 ) , V_75 ) ;
F_9 ( & V_126 ) ;
F_123 ( V_75 ) ;
F_408 ( & V_75 -> V_77 , & ( F_128 ( V_75 ) ) -> V_81 ) ;
F_2 ( & V_126 ) ;
F_136 ( V_75 ) ;
}
