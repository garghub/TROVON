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
if ( V_2 -> V_6 != - 1 && V_2 -> V_11 ) {
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
if ( V_2 -> V_6 != - 1 && V_2 -> V_4 < V_2 -> V_6 ) {
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
if ( F_53 ( V_19 , V_74 ) ) {
if ( V_41 )
return false ;
else
return true ;
}
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
F_19 ( V_76 >= V_98 ) ;
return V_76 ;
}
static int F_76 ( int V_76 , T_3 * V_97 )
{
if ( ! F_77 ( V_76 , * V_97 ) )
V_76 = F_74 ( V_76 , V_97 ) ;
return V_76 ;
}
static int F_78 ( struct V_7 * V_8 ,
T_3 * V_97 )
{
int V_76 ;
F_19 ( ! V_97 ) ;
V_76 = F_76 ( V_8 -> V_99 , V_97 ) ;
V_8 -> V_99 = F_74 ( V_76 , V_97 ) ;
return V_76 ;
}
static int F_79 ( struct V_7 * V_8 , T_3 * V_97 )
{
int V_76 ;
F_19 ( ! V_97 ) ;
V_76 = F_76 ( V_8 -> V_100 , V_97 ) ;
V_8 -> V_100 = F_74 ( V_76 , V_97 ) ;
return V_76 ;
}
static void F_80 ( struct V_75 * V_75 ,
unsigned int V_101 )
{
int V_102 ;
int V_103 = 1 << V_101 ;
struct V_75 * V_104 = V_75 + 1 ;
F_81 ( F_82 ( V_75 ) , 0 ) ;
for ( V_102 = 1 ; V_102 < V_103 ; V_102 ++ , V_104 = F_83 ( V_104 , V_75 , V_102 ) ) {
F_84 ( V_104 ) ;
F_61 ( V_104 ) ;
}
F_85 ( V_75 , 0 ) ;
F_86 ( V_75 ) ;
}
static void F_87 ( struct V_75 * V_75 , unsigned int V_101 )
{
F_88 ( F_89 ( V_75 ) , 1 << V_101 ) ;
}
static int F_90 ( unsigned long V_105 ,
unsigned long V_103 )
{
unsigned long V_106 = V_105 + V_103 ;
return F_91 ( V_105 , V_106 , V_107 ) ;
}
static bool F_92 ( struct V_90 * V_92 ,
unsigned long V_105 , unsigned long V_103 )
{
unsigned long V_102 , V_106 = V_105 + V_103 ;
struct V_75 * V_75 ;
for ( V_102 = V_105 ; V_102 < V_106 ; V_102 ++ ) {
if ( ! F_93 ( V_102 ) )
return false ;
V_75 = F_94 ( V_102 ) ;
if ( F_95 ( V_75 ) != V_92 )
return false ;
if ( F_96 ( V_75 ) )
return false ;
if ( F_97 ( V_75 ) > 0 )
return false ;
if ( F_98 ( V_75 ) )
return false ;
}
return true ;
}
static bool F_99 ( const struct V_90 * V_90 ,
unsigned long V_105 , unsigned long V_103 )
{
unsigned long V_108 = V_105 + V_103 - 1 ;
return F_100 ( V_90 , V_108 ) ;
}
static struct V_75 * F_101 ( int V_76 , unsigned int V_101 )
{
unsigned long V_103 = 1 << V_101 ;
unsigned long V_13 , V_109 , V_71 ;
struct V_90 * V_92 ;
V_92 = F_102 ( V_76 ) -> V_110 ;
for (; V_92 - F_102 ( V_76 ) -> V_110 < V_111 ; V_92 ++ ) {
F_103 ( & V_92 -> V_5 , V_71 ) ;
V_109 = F_104 ( V_92 -> V_112 , V_103 ) ;
while ( F_99 ( V_92 , V_109 , V_103 ) ) {
if ( F_92 ( V_92 , V_109 , V_103 ) ) {
F_105 ( & V_92 -> V_5 , V_71 ) ;
V_13 = F_90 ( V_109 , V_103 ) ;
if ( ! V_13 )
return F_94 ( V_109 ) ;
F_103 ( & V_92 -> V_5 , V_71 ) ;
}
V_109 += V_103 ;
}
F_105 ( & V_92 -> V_5 , V_71 ) ;
}
return NULL ;
}
static struct V_75 * F_106 ( struct V_7 * V_8 , int V_76 )
{
struct V_75 * V_75 ;
V_75 = F_101 ( V_76 , F_36 ( V_8 ) ) ;
if ( V_75 ) {
F_107 ( V_75 , F_36 ( V_8 ) ) ;
F_108 ( V_8 , V_75 , V_76 ) ;
}
return V_75 ;
}
static int F_109 ( struct V_7 * V_8 ,
T_3 * V_97 )
{
struct V_75 * V_75 = NULL ;
int V_113 , V_114 ;
F_110 (h, nr_nodes, node, nodes_allowed) {
V_75 = F_106 ( V_8 , V_114 ) ;
if ( V_75 )
return 1 ;
}
return 0 ;
}
static inline bool F_111 ( void ) { return true ; }
static inline bool F_111 ( void ) { return false ; }
static inline void F_87 ( struct V_75 * V_75 , unsigned int V_101 ) { }
static inline void F_80 ( struct V_75 * V_75 ,
unsigned int V_101 ) { }
static inline int F_109 ( struct V_7 * V_8 ,
T_3 * V_97 ) { return 0 ; }
static void F_112 ( struct V_7 * V_8 , struct V_75 * V_75 )
{
int V_102 ;
if ( F_113 ( V_8 ) && ! F_111 () )
return;
V_8 -> V_115 -- ;
V_8 -> V_116 [ F_57 ( V_75 ) ] -- ;
for ( V_102 = 0 ; V_102 < F_114 ( V_8 ) ; V_102 ++ ) {
V_75 [ V_102 ] . V_71 &= ~ ( 1 << V_117 | 1 << V_118 |
1 << V_119 | 1 << V_120 |
1 << V_121 | 1 << V_122 |
1 << V_123 ) ;
}
F_115 ( F_116 ( V_75 ) , V_75 ) ;
F_117 ( V_75 , V_124 ) ;
F_61 ( V_75 ) ;
if ( F_113 ( V_8 ) ) {
F_80 ( V_75 , F_36 ( V_8 ) ) ;
F_87 ( V_75 , F_36 ( V_8 ) ) ;
} else {
F_118 ( V_75 , F_36 ( V_8 ) ) ;
}
}
struct V_7 * F_119 ( unsigned long V_125 )
{
struct V_7 * V_8 ;
F_120 (h) {
if ( F_121 ( V_8 ) == V_125 )
return V_8 ;
}
return NULL ;
}
bool F_122 ( struct V_75 * V_75 )
{
F_115 ( ! F_98 ( V_75 ) , V_75 ) ;
return F_123 ( V_75 ) && F_124 ( & V_75 [ 1 ] ) ;
}
static void F_125 ( struct V_75 * V_75 )
{
F_115 ( ! F_126 ( V_75 ) , V_75 ) ;
F_70 ( & V_75 [ 1 ] ) ;
}
static void F_127 ( struct V_75 * V_75 )
{
F_115 ( ! F_126 ( V_75 ) , V_75 ) ;
F_128 ( & V_75 [ 1 ] ) ;
}
void F_129 ( struct V_75 * V_75 )
{
struct V_7 * V_8 = F_130 ( V_75 ) ;
int V_76 = F_57 ( V_75 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_131 ( V_75 ) ;
bool V_47 ;
F_132 ( V_75 , 0 ) ;
V_75 -> V_66 = NULL ;
F_115 ( F_97 ( V_75 ) , V_75 ) ;
F_115 ( F_133 ( V_75 ) , V_75 ) ;
V_47 = F_124 ( V_75 ) ;
F_128 ( V_75 ) ;
if ( F_12 ( V_2 , 1 ) == 0 )
V_47 = true ;
F_9 ( & V_126 ) ;
F_127 ( V_75 ) ;
F_134 ( F_135 ( V_8 ) ,
F_114 ( V_8 ) , V_75 ) ;
if ( V_47 )
V_8 -> V_94 ++ ;
if ( V_8 -> V_127 [ V_76 ] ) {
F_21 ( & V_75 -> V_77 ) ;
F_112 ( V_8 , V_75 ) ;
V_8 -> V_128 -- ;
V_8 -> V_127 [ V_76 ] -- ;
} else {
F_136 ( V_75 ) ;
F_56 ( V_8 , V_75 ) ;
}
F_2 ( & V_126 ) ;
}
static void F_108 ( struct V_7 * V_8 , struct V_75 * V_75 , int V_76 )
{
F_26 ( & V_75 -> V_77 ) ;
F_117 ( V_75 , V_129 ) ;
F_9 ( & V_126 ) ;
F_137 ( V_75 , NULL ) ;
V_8 -> V_115 ++ ;
V_8 -> V_116 [ V_76 ] ++ ;
F_2 ( & V_126 ) ;
F_138 ( V_75 ) ;
}
static void F_107 ( struct V_75 * V_75 , unsigned int V_101 )
{
int V_102 ;
int V_103 = 1 << V_101 ;
struct V_75 * V_104 = V_75 + 1 ;
F_85 ( V_75 , V_101 ) ;
F_139 ( V_75 ) ;
F_140 ( V_75 ) ;
for ( V_102 = 1 ; V_102 < V_103 ; V_102 ++ , V_104 = F_83 ( V_104 , V_75 , V_102 ) ) {
F_139 ( V_104 ) ;
F_141 ( V_104 , 0 ) ;
F_142 ( V_104 , V_75 ) ;
}
F_81 ( F_82 ( V_75 ) , - 1 ) ;
}
int F_98 ( struct V_75 * V_75 )
{
if ( ! F_143 ( V_75 ) )
return 0 ;
V_75 = F_144 ( V_75 ) ;
return V_75 [ 1 ] . V_130 == V_129 ;
}
int F_126 ( struct V_75 * V_131 )
{
if ( ! F_123 ( V_131 ) )
return 0 ;
return F_145 ( V_131 ) == F_129 ;
}
T_1 F_146 ( struct V_75 * V_75 )
{
struct V_75 * V_131 = F_144 ( V_75 ) ;
T_1 V_132 = F_147 ( V_131 ) ;
unsigned long V_133 ;
if ( ! F_98 ( V_131 ) )
return F_147 ( V_75 ) ;
if ( F_148 ( V_131 ) >= V_134 )
V_133 = F_89 ( V_75 ) - F_89 ( V_131 ) ;
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
F_108 ( V_8 , V_75 , V_76 ) ;
}
return V_75 ;
}
static int F_151 ( struct V_7 * V_8 , T_3 * V_97 )
{
struct V_75 * V_75 ;
int V_113 , V_114 ;
int V_13 = 0 ;
F_110 (h, nr_nodes, node, nodes_allowed) {
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
F_112 ( V_8 , V_75 ) ;
V_13 = 1 ;
break;
}
}
return V_13 ;
}
static void F_157 ( struct V_75 * V_75 )
{
F_9 ( & V_126 ) ;
if ( F_98 ( V_75 ) && ! F_97 ( V_75 ) ) {
struct V_7 * V_8 = F_130 ( V_75 ) ;
int V_76 = F_57 ( V_75 ) ;
F_21 ( & V_75 -> V_77 ) ;
V_8 -> V_79 -- ;
V_8 -> V_80 [ V_76 ] -- ;
F_112 ( V_8 , V_75 ) ;
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
F_157 ( F_94 ( V_109 ) ) ;
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
if ( F_113 ( V_8 ) )
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
F_117 ( V_75 , V_129 ) ;
F_137 ( V_75 , NULL ) ;
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
F_115 ( F_97 ( V_75 ) , V_75 ) ;
F_56 ( V_8 , V_75 ) ;
}
free:
F_2 ( & V_126 ) ;
F_23 (page, tmp, &surplus_list, lru)
F_138 ( V_75 ) ;
F_9 ( & V_126 ) ;
return V_13 ;
}
static void F_173 ( struct V_7 * V_8 ,
unsigned long V_156 )
{
unsigned long V_103 ;
V_8 -> V_94 -= V_156 ;
if ( F_113 ( V_8 ) )
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
else if ( F_53 ( V_19 , V_74 ) && V_13 >= 0 ) {
if ( V_13 )
return 0 ;
else
return 1 ;
}
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
V_161 = F_135 ( V_8 ) ;
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
V_13 = F_182 ( V_161 , F_114 ( V_8 ) , & V_169 ) ;
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
F_183 ( V_161 , F_114 ( V_8 ) , V_169 , V_75 ) ;
F_2 ( & V_126 ) ;
F_132 ( V_75 , ( unsigned long ) V_2 ) ;
V_166 = F_178 ( V_8 , V_19 , V_144 ) ;
if ( F_72 ( V_165 > V_166 ) ) {
long V_48 ;
V_48 = F_12 ( V_2 , 1 ) ;
F_3 ( V_8 , - V_48 ) ;
}
return V_75 ;
V_172:
F_184 ( V_161 , F_114 ( V_8 ) , V_169 ) ;
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
F_110 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_144 ;
V_144 = F_188 (
F_121 ( V_8 ) , F_121 ( V_8 ) ,
0 , V_175 , V_114 ) ;
if ( V_144 ) {
V_174 = V_144 ;
goto V_176;
}
}
return 0 ;
V_176:
F_10 ( ! F_160 ( F_189 ( V_174 ) , F_121 ( V_8 ) ) ) ;
F_22 ( & V_174 -> V_177 , & V_178 ) ;
V_174 -> V_7 = V_8 ;
return 1 ;
}
static void T_4 F_190 ( struct V_75 * V_75 ,
unsigned int V_101 )
{
if ( F_72 ( V_101 > ( V_134 - 1 ) ) )
F_107 ( V_75 , V_101 ) ;
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
V_75 = F_94 ( V_174 -> V_179 >> V_180 ) ;
F_194 ( F_195 ( V_174 ) ,
sizeof( struct V_173 ) ) ;
#else
V_75 = F_196 ( V_174 ) ;
#endif
F_197 ( F_97 ( V_75 ) != 1 ) ;
F_190 ( V_75 , V_8 -> V_101 ) ;
F_197 ( F_96 ( V_75 ) ) ;
F_108 ( V_8 , V_75 , F_57 ( V_75 ) ) ;
if ( F_113 ( V_8 ) )
F_198 ( V_75 , 1 << V_8 -> V_101 ) ;
}
}
static void T_4 F_199 ( struct V_7 * V_8 )
{
unsigned long V_102 ;
for ( V_102 = 0 ; V_102 < V_8 -> V_181 ; ++ V_102 ) {
if ( F_113 ( V_8 ) ) {
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
F_120 (h) {
if ( V_143 > F_36 ( V_8 ) )
V_143 = F_36 ( V_8 ) ;
if ( ! F_113 ( V_8 ) )
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
F_120 (h) {
char V_183 [ 32 ] ;
F_203 ( L_4 ,
F_201 ( V_183 , F_121 ( V_8 ) ) ,
V_8 -> V_79 ) ;
}
}
static void F_204 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_97 )
{
int V_102 ;
if ( F_113 ( V_8 ) )
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
F_112 ( V_8 , V_75 ) ;
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
F_110 (h, nr_nodes, node, nodes_allowed) {
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
if ( F_113 ( V_8 ) && ! F_111 () )
return V_8 -> V_181 ;
F_9 ( & V_126 ) ;
while ( V_8 -> V_128 && V_3 > F_209 ( V_8 ) ) {
if ( ! F_207 ( V_8 , V_97 , - 1 ) )
break;
}
while ( V_3 > F_209 ( V_8 ) ) {
F_2 ( & V_126 ) ;
if ( F_113 ( V_8 ) )
V_13 = F_109 ( V_8 , V_97 ) ;
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
if ( F_113 ( V_8 ) && ! F_111 () ) {
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
if ( F_113 ( V_8 ) )
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
int V_205 = F_135 ( V_8 ) ;
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
F_120 (h) {
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
F_120 (h) {
int V_161 = F_135 ( V_8 ) ;
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
F_120 (h) {
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
if ( ! F_119 ( V_217 ) ) {
V_217 = V_218 ;
if ( ! F_119 ( V_217 ) )
F_242 ( V_219 ) ;
}
V_220 = F_135 ( F_119 ( V_217 ) ) ;
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
void T_4 F_248 ( void )
{
V_226 = false ;
}
void T_4 F_242 ( unsigned int V_101 )
{
struct V_7 * V_8 ;
unsigned long V_102 ;
if ( F_119 ( V_54 << V_101 ) ) {
F_249 ( L_9 ) ;
return;
}
F_10 ( V_227 >= V_191 ) ;
F_10 ( V_101 == 0 ) ;
V_8 = & V_193 [ V_227 ++ ] ;
V_8 -> V_101 = V_101 ;
V_8 -> V_228 = ~ ( ( 1ULL << ( V_101 + V_180 ) ) - 1 ) ;
V_8 -> V_115 = 0 ;
V_8 -> V_79 = 0 ;
for ( V_102 = 0 ; V_102 < V_98 ; ++ V_102 )
F_26 ( & V_8 -> V_78 [ V_102 ] ) ;
F_26 ( & V_8 -> V_81 ) ;
V_8 -> V_99 = V_229 ;
V_8 -> V_100 = V_229 ;
snprintf ( V_8 -> V_206 , V_230 , L_10 ,
F_121 ( V_8 ) / 1024 ) ;
V_231 = V_8 ;
}
static int T_4 F_250 ( char * V_232 )
{
unsigned long * V_233 ;
static unsigned long * V_234 ;
if ( ! V_226 ) {
F_249 ( L_11
L_12 , V_232 ) ;
V_226 = true ;
return 1 ;
}
else if ( ! V_227 )
V_233 = & V_221 ;
else
V_233 = & V_231 -> V_181 ;
if ( V_233 == V_234 ) {
F_249 ( L_13 ) ;
return 1 ;
}
if ( sscanf ( V_232 , L_14 , V_233 ) <= 0 )
* V_233 = 0 ;
if ( V_227 && V_231 -> V_101 >= V_134 )
F_199 ( V_231 ) ;
V_234 = V_233 ;
return 1 ;
}
static int T_4 F_251 ( char * V_232 )
{
V_217 = F_252 ( V_232 , & V_232 ) ;
return 1 ;
}
static unsigned int F_253 ( unsigned int * V_235 )
{
int V_114 ;
unsigned int V_236 = 0 ;
F_205 (node, cpuset_current_mems_allowed)
V_236 += V_235 [ V_114 ] ;
return V_236 ;
}
static int F_254 ( bool V_196 ,
struct V_237 * V_238 , int V_239 ,
void T_7 * V_240 , T_6 * V_241 , T_8 * V_242 )
{
struct V_7 * V_8 = & V_222 ;
unsigned long V_152 = V_8 -> V_181 ;
int V_13 ;
if ( ! F_159 () )
return - V_243 ;
V_238 -> V_244 = & V_152 ;
V_238 -> V_245 = sizeof( unsigned long ) ;
V_13 = F_255 ( V_238 , V_239 , V_240 , V_241 , V_242 ) ;
if ( V_13 )
goto V_45;
if ( V_239 )
V_13 = F_214 ( V_196 , V_8 ,
V_147 , V_152 , * V_241 ) ;
V_45:
return V_13 ;
}
int F_256 ( struct V_237 * V_238 , int V_239 ,
void T_7 * V_240 , T_6 * V_241 , T_8 * V_242 )
{
return F_254 ( false , V_238 , V_239 ,
V_240 , V_241 , V_242 ) ;
}
int F_257 ( struct V_237 * V_238 , int V_239 ,
void T_7 * V_240 , T_6 * V_241 , T_8 * V_242 )
{
return F_254 ( true , V_238 , V_239 ,
V_240 , V_241 , V_242 ) ;
}
int F_258 ( struct V_237 * V_238 , int V_239 ,
void T_7 * V_240 ,
T_6 * V_241 , T_8 * V_242 )
{
struct V_7 * V_8 = & V_222 ;
unsigned long V_152 ;
int V_13 ;
if ( ! F_159 () )
return - V_243 ;
V_152 = V_8 -> V_150 ;
if ( V_239 && F_113 ( V_8 ) )
return - V_199 ;
V_238 -> V_244 = & V_152 ;
V_238 -> V_245 = sizeof( unsigned long ) ;
V_13 = F_255 ( V_238 , V_239 , V_240 , V_241 , V_242 ) ;
if ( V_13 )
goto V_45;
if ( V_239 ) {
F_9 ( & V_126 ) ;
V_8 -> V_150 = V_152 ;
F_2 ( & V_126 ) ;
}
V_45:
return V_13 ;
}
void F_259 ( struct V_246 * V_174 )
{
struct V_7 * V_8 = & V_222 ;
if ( ! F_159 () )
return;
F_260 ( V_174 ,
L_15
L_16
L_17
L_18
L_19 ,
V_8 -> V_115 ,
V_8 -> V_79 ,
V_8 -> V_94 ,
V_8 -> V_128 ,
1UL << ( F_36 ( V_8 ) + V_180 - 10 ) ) ;
}
int F_261 ( int V_76 , char * V_183 )
{
struct V_7 * V_8 = & V_222 ;
if ( ! F_159 () )
return 0 ;
return sprintf ( V_183 ,
L_20
L_21
L_22 ,
V_76 , V_8 -> V_116 [ V_76 ] ,
V_76 , V_8 -> V_80 [ V_76 ] ,
V_76 , V_8 -> V_127 [ V_76 ] ) ;
}
void F_262 ( void )
{
struct V_7 * V_8 ;
int V_76 ;
if ( ! F_159 () )
return;
F_239 (nid, N_MEMORY)
F_120 (h)
F_203 ( L_23 ,
V_76 ,
V_8 -> V_116 [ V_76 ] ,
V_8 -> V_80 [ V_76 ] ,
V_8 -> V_127 [ V_76 ] ,
1UL << ( F_36 ( V_8 ) + V_180 - 10 ) ) ;
}
void F_263 ( struct V_246 * V_174 , struct V_247 * V_248 )
{
F_260 ( V_174 , L_24 ,
F_264 ( & V_248 -> V_249 ) << ( V_180 - 10 ) ) ;
}
unsigned long F_265 ( void )
{
struct V_7 * V_8 ;
unsigned long V_250 = 0 ;
F_120 (h)
V_250 += V_8 -> V_115 * F_114 ( V_8 ) ;
return V_250 ;
}
static int F_3 ( struct V_7 * V_8 , long V_12 )
{
int V_13 = - V_14 ;
F_9 ( & V_126 ) ;
if ( V_12 > 0 ) {
if ( F_171 ( V_8 , V_12 ) < 0 )
goto V_45;
if ( V_12 > F_253 ( V_8 -> V_80 ) ) {
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
static void F_266 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_49 ( V_19 ) ;
if ( V_22 && F_53 ( V_19 , V_74 ) )
F_267 ( & V_22 -> V_57 ) ;
}
static void F_268 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_21 * V_22 = F_49 ( V_19 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
unsigned long V_251 , V_252 , V_253 ;
long V_254 ;
if ( ! V_22 || ! F_53 ( V_19 , V_74 ) )
return;
V_252 = F_34 ( V_8 , V_19 , V_19 -> V_52 ) ;
V_253 = F_34 ( V_8 , V_19 , V_19 -> V_255 ) ;
V_251 = ( V_253 - V_252 ) - F_31 ( V_22 , V_252 , V_253 ) ;
F_269 ( & V_22 -> V_57 , F_46 ) ;
if ( V_251 ) {
V_254 = F_12 ( V_2 , V_251 ) ;
F_3 ( V_8 , - V_254 ) ;
}
}
static int F_270 ( struct V_18 * V_19 , struct V_256 * V_257 )
{
F_176 () ;
return 0 ;
}
static T_9 F_271 ( struct V_18 * V_19 , struct V_75 * V_75 ,
int V_258 )
{
T_9 V_259 ;
if ( V_258 ) {
V_259 = F_272 ( F_273 ( F_274 ( V_75 ,
V_19 -> V_260 ) ) ) ;
} else {
V_259 = F_275 ( F_274 ( V_75 ,
V_19 -> V_260 ) ) ;
}
V_259 = F_276 ( V_259 ) ;
V_259 = F_277 ( V_259 ) ;
V_259 = F_278 ( V_259 , V_19 , V_75 , V_258 ) ;
return V_259 ;
}
static void F_279 ( struct V_18 * V_19 ,
unsigned long V_51 , T_9 * V_261 )
{
T_9 V_259 ;
V_259 = F_272 ( F_273 ( F_280 ( V_261 ) ) ) ;
if ( F_281 ( V_19 , V_51 , V_261 , V_259 , 1 ) )
F_282 ( V_19 , V_51 , V_261 ) ;
}
static int F_283 ( T_9 V_262 )
{
T_10 V_263 ;
if ( F_284 ( V_262 ) || F_285 ( V_262 ) )
return 0 ;
V_263 = F_286 ( V_262 ) ;
if ( F_287 ( V_263 ) && F_288 ( V_263 ) )
return 1 ;
else
return 0 ;
}
static int F_289 ( T_9 V_262 )
{
T_10 V_263 ;
if ( F_284 ( V_262 ) || F_285 ( V_262 ) )
return 0 ;
V_263 = F_286 ( V_262 ) ;
if ( F_287 ( V_263 ) && F_290 ( V_263 ) )
return 1 ;
else
return 0 ;
}
int F_291 ( struct V_247 * V_264 , struct V_247 * V_265 ,
struct V_18 * V_19 )
{
T_9 * V_266 , * V_267 , V_259 ;
struct V_75 * V_268 ;
unsigned long V_144 ;
int V_269 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_270 = F_121 ( V_8 ) ;
unsigned long V_271 ;
unsigned long V_272 ;
int V_13 = 0 ;
V_269 = ( V_19 -> V_63 & ( V_273 | V_274 ) ) == V_274 ;
V_271 = V_19 -> V_52 ;
V_272 = V_19 -> V_255 ;
if ( V_269 )
F_292 ( V_265 , V_271 , V_272 ) ;
for ( V_144 = V_19 -> V_52 ; V_144 < V_19 -> V_255 ; V_144 += V_270 ) {
T_11 * V_275 , * V_276 ;
V_266 = F_293 ( V_265 , V_144 ) ;
if ( ! V_266 )
continue;
V_267 = F_294 ( V_264 , V_144 , V_270 ) ;
if ( ! V_267 ) {
V_13 = - V_14 ;
break;
}
if ( V_267 == V_266 )
continue;
V_276 = F_295 ( V_8 , V_264 , V_267 ) ;
V_275 = F_296 ( V_8 , V_265 , V_266 ) ;
F_297 ( V_275 , V_277 ) ;
V_259 = F_280 ( V_266 ) ;
if ( F_284 ( V_259 ) ) {
;
} else if ( F_72 ( F_283 ( V_259 ) ||
F_289 ( V_259 ) ) ) {
T_10 V_278 = F_286 ( V_259 ) ;
if ( F_298 ( V_278 ) && V_269 ) {
F_299 ( & V_278 ) ;
V_259 = F_300 ( V_278 ) ;
F_301 ( V_265 , V_144 , V_266 , V_259 ) ;
}
F_301 ( V_264 , V_144 , V_267 , V_259 ) ;
} else {
if ( V_269 ) {
F_302 ( V_265 , V_144 , V_266 ) ;
F_303 ( V_265 , V_271 ,
V_272 ) ;
}
V_259 = F_280 ( V_266 ) ;
V_268 = F_304 ( V_259 ) ;
F_305 ( V_268 ) ;
F_306 ( V_268 , true ) ;
F_301 ( V_264 , V_144 , V_267 , V_259 ) ;
F_307 ( F_114 ( V_8 ) , V_264 ) ;
}
F_2 ( V_275 ) ;
F_2 ( V_276 ) ;
}
if ( V_269 )
F_308 ( V_265 , V_271 , V_272 ) ;
return V_13 ;
}
void F_309 ( struct V_279 * V_280 , struct V_18 * V_19 ,
unsigned long V_252 , unsigned long V_253 ,
struct V_75 * V_281 )
{
int V_282 = 0 ;
struct V_247 * V_248 = V_19 -> V_283 ;
unsigned long V_51 ;
T_9 * V_261 ;
T_9 V_262 ;
T_11 * V_284 ;
struct V_75 * V_75 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_270 = F_121 ( V_8 ) ;
const unsigned long V_271 = V_252 ;
const unsigned long V_272 = V_253 ;
F_197 ( ! F_40 ( V_19 ) ) ;
F_10 ( V_252 & ~ F_310 ( V_8 ) ) ;
F_10 ( V_253 & ~ F_310 ( V_8 ) ) ;
F_311 ( V_280 , V_19 ) ;
F_292 ( V_248 , V_271 , V_272 ) ;
V_51 = V_252 ;
V_285:
for (; V_51 < V_253 ; V_51 += V_270 ) {
V_261 = F_293 ( V_248 , V_51 ) ;
if ( ! V_261 )
continue;
V_284 = F_295 ( V_8 , V_248 , V_261 ) ;
if ( F_312 ( V_248 , & V_51 , V_261 ) )
goto V_286;
V_262 = F_280 ( V_261 ) ;
if ( F_284 ( V_262 ) )
goto V_286;
if ( F_72 ( ! F_285 ( V_262 ) ) ) {
F_313 ( V_248 , V_51 , V_261 ) ;
goto V_286;
}
V_75 = F_304 ( V_262 ) ;
if ( V_281 ) {
if ( V_75 != V_281 )
goto V_286;
F_52 ( V_19 , V_287 ) ;
}
V_262 = F_314 ( V_248 , V_51 , V_261 ) ;
F_315 ( V_280 , V_261 , V_51 ) ;
if ( F_316 ( V_262 ) )
F_317 ( V_75 ) ;
F_318 ( F_114 ( V_8 ) , V_248 ) ;
F_319 ( V_75 , true ) ;
V_282 = ! F_320 ( V_280 , V_75 ) ;
if ( V_282 ) {
V_51 += V_270 ;
F_2 ( V_284 ) ;
break;
}
if ( V_281 ) {
F_2 ( V_284 ) ;
break;
}
V_286:
F_2 ( V_284 ) ;
}
if ( V_282 ) {
V_282 = 0 ;
F_321 ( V_280 ) ;
if ( V_51 < V_253 && ! V_281 )
goto V_285;
}
F_308 ( V_248 , V_271 , V_272 ) ;
F_322 ( V_280 , V_19 ) ;
}
void F_323 ( struct V_279 * V_280 ,
struct V_18 * V_19 , unsigned long V_252 ,
unsigned long V_253 , struct V_75 * V_281 )
{
F_309 ( V_280 , V_19 , V_252 , V_253 , V_281 ) ;
V_19 -> V_63 &= ~ V_64 ;
}
void F_324 ( struct V_18 * V_19 , unsigned long V_252 ,
unsigned long V_253 , struct V_75 * V_281 )
{
struct V_247 * V_248 ;
struct V_279 V_280 ;
V_248 = V_19 -> V_283 ;
F_325 ( & V_280 , V_248 , V_252 , V_253 ) ;
F_309 ( & V_280 , V_19 , V_252 , V_253 , V_281 ) ;
F_326 ( & V_280 , V_252 , V_253 ) ;
}
static void F_327 ( struct V_247 * V_248 , struct V_18 * V_19 ,
struct V_75 * V_75 , unsigned long V_51 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_18 * V_288 ;
struct V_65 * V_66 ;
T_1 V_289 ;
V_51 = V_51 & F_310 ( V_8 ) ;
V_289 = ( ( V_51 - V_19 -> V_52 ) >> V_180 ) +
V_19 -> V_53 ;
V_66 = F_16 ( V_19 -> V_20 ) -> V_61 ;
F_328 ( V_66 ) ;
F_329 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_288 == V_19 )
continue;
if ( V_288 -> V_63 & V_64 )
continue;
if ( ! F_53 ( V_288 , V_74 ) )
F_324 ( V_288 , V_51 ,
V_51 + F_121 ( V_8 ) , V_75 ) ;
}
F_330 ( V_66 ) ;
}
static int F_331 ( struct V_247 * V_248 , struct V_18 * V_19 ,
unsigned long V_51 , T_9 * V_261 , T_9 V_262 ,
struct V_75 * V_290 , T_11 * V_284 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_75 * V_291 , * V_292 ;
int V_13 = 0 , V_293 = 0 ;
unsigned long V_271 ;
unsigned long V_272 ;
V_291 = F_304 ( V_262 ) ;
V_294:
if ( F_133 ( V_291 ) == 1 && F_332 ( V_291 ) ) {
F_333 ( V_291 , V_19 ) ;
F_279 ( V_19 , V_51 , V_261 ) ;
return 0 ;
}
if ( F_53 ( V_19 , V_74 ) &&
V_291 != V_290 )
V_293 = 1 ;
F_305 ( V_291 ) ;
F_2 ( V_284 ) ;
V_292 = F_180 ( V_19 , V_51 , V_293 ) ;
if ( F_186 ( V_292 ) ) {
if ( V_293 ) {
F_138 ( V_291 ) ;
F_10 ( F_284 ( V_262 ) ) ;
F_327 ( V_248 , V_19 , V_291 , V_51 ) ;
F_10 ( F_284 ( V_262 ) ) ;
F_9 ( V_284 ) ;
V_261 = F_293 ( V_248 , V_51 & F_310 ( V_8 ) ) ;
if ( F_334 ( V_261 &&
F_335 ( F_280 ( V_261 ) , V_262 ) ) )
goto V_294;
return 0 ;
}
V_13 = ( F_336 ( V_292 ) == - V_14 ) ?
V_295 : V_296 ;
goto V_297;
}
if ( F_72 ( F_337 ( V_19 ) ) ) {
V_13 = V_295 ;
goto V_298;
}
F_338 ( V_292 , V_291 , V_51 , V_19 ,
F_114 ( V_8 ) ) ;
F_339 ( V_292 ) ;
F_125 ( V_292 ) ;
V_271 = V_51 & F_310 ( V_8 ) ;
V_272 = V_271 + F_121 ( V_8 ) ;
F_292 ( V_248 , V_271 , V_272 ) ;
F_9 ( V_284 ) ;
V_261 = F_293 ( V_248 , V_51 & F_310 ( V_8 ) ) ;
if ( F_334 ( V_261 && F_335 ( F_280 ( V_261 ) , V_262 ) ) ) {
F_128 ( V_292 ) ;
F_340 ( V_19 , V_51 , V_261 ) ;
F_303 ( V_248 , V_271 , V_272 ) ;
F_301 ( V_248 , V_51 , V_261 ,
F_271 ( V_19 , V_292 , 1 ) ) ;
F_319 ( V_291 , true ) ;
F_341 ( V_292 , V_19 , V_51 ) ;
V_292 = V_291 ;
}
F_2 ( V_284 ) ;
F_308 ( V_248 , V_271 , V_272 ) ;
V_298:
F_138 ( V_292 ) ;
V_297:
F_138 ( V_291 ) ;
F_9 ( V_284 ) ;
return V_13 ;
}
static struct V_75 * F_342 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_51 )
{
struct V_65 * V_66 ;
T_1 V_161 ;
V_66 = V_19 -> V_20 -> V_67 ;
V_161 = F_34 ( V_8 , V_19 , V_51 ) ;
return F_343 ( V_66 , V_161 ) ;
}
static bool F_344 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_51 )
{
struct V_65 * V_66 ;
T_1 V_161 ;
struct V_75 * V_75 ;
V_66 = V_19 -> V_20 -> V_67 ;
V_161 = F_34 ( V_8 , V_19 , V_51 ) ;
V_75 = F_345 ( V_66 , V_161 ) ;
if ( V_75 )
F_138 ( V_75 ) ;
return V_75 != NULL ;
}
int F_346 ( struct V_75 * V_75 , struct V_65 * V_66 ,
T_1 V_161 )
{
struct V_16 * V_16 = V_66 -> V_68 ;
struct V_7 * V_8 = F_30 ( V_16 ) ;
int V_95 = F_347 ( V_75 , V_66 , V_161 , V_10 ) ;
if ( V_95 )
return V_95 ;
F_128 ( V_75 ) ;
F_9 ( & V_16 -> V_299 ) ;
V_16 -> V_300 += F_348 ( V_8 ) ;
F_2 ( & V_16 -> V_299 ) ;
return 0 ;
}
static int F_349 ( struct V_247 * V_248 , struct V_18 * V_19 ,
struct V_65 * V_66 , T_1 V_161 ,
unsigned long V_51 , T_9 * V_261 , unsigned int V_71 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
int V_13 = V_296 ;
int V_301 = 0 ;
unsigned long V_125 ;
struct V_75 * V_75 ;
T_9 V_302 ;
T_11 * V_284 ;
if ( F_53 ( V_19 , V_287 ) ) {
F_350 ( L_25 ,
V_187 -> V_303 ) ;
return V_13 ;
}
V_42:
V_75 = F_343 ( V_66 , V_161 ) ;
if ( ! V_75 ) {
V_125 = F_351 ( V_66 -> V_68 ) >> F_35 ( V_8 ) ;
if ( V_161 >= V_125 )
goto V_45;
V_75 = F_180 ( V_19 , V_51 , 0 ) ;
if ( F_186 ( V_75 ) ) {
V_13 = F_336 ( V_75 ) ;
if ( V_13 == - V_14 )
V_13 = V_295 ;
else
V_13 = V_296 ;
goto V_45;
}
F_352 ( V_75 , V_51 , F_114 ( V_8 ) ) ;
F_339 ( V_75 ) ;
F_125 ( V_75 ) ;
if ( V_19 -> V_63 & V_64 ) {
int V_95 = F_346 ( V_75 , V_66 , V_161 ) ;
if ( V_95 ) {
F_138 ( V_75 ) ;
if ( V_95 == - V_304 )
goto V_42;
goto V_45;
}
} else {
F_353 ( V_75 ) ;
if ( F_72 ( F_337 ( V_19 ) ) ) {
V_13 = V_295 ;
goto V_305;
}
V_301 = 1 ;
}
} else {
if ( F_72 ( F_354 ( V_75 ) ) ) {
V_13 = V_306 |
F_355 ( F_135 ( V_8 ) ) ;
goto V_305;
}
}
if ( ( V_71 & V_307 ) && ! ( V_19 -> V_63 & V_273 ) ) {
if ( F_177 ( V_8 , V_19 , V_51 ) < 0 ) {
V_13 = V_295 ;
goto V_305;
}
F_179 ( V_8 , V_19 , V_51 ) ;
}
V_284 = F_296 ( V_8 , V_248 , V_261 ) ;
F_9 ( V_284 ) ;
V_125 = F_351 ( V_66 -> V_68 ) >> F_35 ( V_8 ) ;
if ( V_161 >= V_125 )
goto V_308;
V_13 = 0 ;
if ( ! F_284 ( F_280 ( V_261 ) ) )
goto V_308;
if ( V_301 ) {
F_128 ( V_75 ) ;
F_341 ( V_75 , V_19 , V_51 ) ;
} else
F_306 ( V_75 , true ) ;
V_302 = F_271 ( V_19 , V_75 , ( ( V_19 -> V_63 & V_309 )
&& ( V_19 -> V_63 & V_273 ) ) ) ;
F_301 ( V_248 , V_51 , V_261 , V_302 ) ;
F_307 ( F_114 ( V_8 ) , V_248 ) ;
if ( ( V_71 & V_307 ) && ! ( V_19 -> V_63 & V_273 ) ) {
V_13 = F_331 ( V_248 , V_19 , V_51 , V_261 , V_302 , V_75 , V_284 ) ;
}
F_2 ( V_284 ) ;
F_356 ( V_75 ) ;
V_45:
return V_13 ;
V_308:
F_2 ( V_284 ) ;
V_305:
F_356 ( V_75 ) ;
F_138 ( V_75 ) ;
goto V_45;
}
T_12 F_357 ( struct V_7 * V_8 , struct V_247 * V_248 ,
struct V_18 * V_19 ,
struct V_65 * V_66 ,
T_1 V_161 , unsigned long V_51 )
{
unsigned long V_310 [ 2 ] ;
T_12 V_311 ;
if ( V_19 -> V_63 & V_273 ) {
V_310 [ 0 ] = ( unsigned long ) V_66 ;
V_310 [ 1 ] = V_161 ;
} else {
V_310 [ 0 ] = ( unsigned long ) V_248 ;
V_310 [ 1 ] = V_51 >> F_35 ( V_8 ) ;
}
V_311 = F_358 ( ( T_12 * ) & V_310 , sizeof( V_310 ) / sizeof( T_12 ) , 0 ) ;
return V_311 & ( V_223 - 1 ) ;
}
T_12 F_357 ( struct V_7 * V_8 , struct V_247 * V_248 ,
struct V_18 * V_19 ,
struct V_65 * V_66 ,
T_1 V_161 , unsigned long V_51 )
{
return 0 ;
}
int F_359 ( struct V_247 * V_248 , struct V_18 * V_19 ,
unsigned long V_51 , unsigned int V_71 )
{
T_9 * V_261 , V_259 ;
T_11 * V_284 ;
int V_13 ;
T_12 V_311 ;
T_1 V_161 ;
struct V_75 * V_75 = NULL ;
struct V_75 * V_290 = NULL ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_65 * V_66 ;
int V_312 = 0 ;
V_51 &= F_310 ( V_8 ) ;
V_261 = F_293 ( V_248 , V_51 ) ;
if ( V_261 ) {
V_259 = F_280 ( V_261 ) ;
if ( F_72 ( F_283 ( V_259 ) ) ) {
F_360 ( V_19 , V_248 , V_261 ) ;
return 0 ;
} else if ( F_72 ( F_289 ( V_259 ) ) )
return V_313 |
F_355 ( F_135 ( V_8 ) ) ;
} else {
V_261 = F_294 ( V_248 , V_51 , F_121 ( V_8 ) ) ;
if ( ! V_261 )
return V_295 ;
}
V_66 = V_19 -> V_20 -> V_67 ;
V_161 = F_34 ( V_8 , V_19 , V_51 ) ;
V_311 = F_357 ( V_8 , V_248 , V_19 , V_66 , V_161 , V_51 ) ;
F_361 ( & V_224 [ V_311 ] ) ;
V_259 = F_280 ( V_261 ) ;
if ( F_284 ( V_259 ) ) {
V_13 = F_349 ( V_248 , V_19 , V_66 , V_161 , V_51 , V_261 , V_71 ) ;
goto V_314;
}
V_13 = 0 ;
if ( ! F_285 ( V_259 ) )
goto V_314;
if ( ( V_71 & V_307 ) && ! F_362 ( V_259 ) ) {
if ( F_177 ( V_8 , V_19 , V_51 ) < 0 ) {
V_13 = V_295 ;
goto V_314;
}
F_179 ( V_8 , V_19 , V_51 ) ;
if ( ! ( V_19 -> V_63 & V_64 ) )
V_290 = F_342 ( V_8 ,
V_19 , V_51 ) ;
}
V_284 = F_295 ( V_8 , V_248 , V_261 ) ;
if ( F_72 ( ! F_335 ( V_259 , F_280 ( V_261 ) ) ) )
goto V_315;
V_75 = F_304 ( V_259 ) ;
if ( V_75 != V_290 )
if ( ! F_363 ( V_75 ) ) {
V_312 = 1 ;
goto V_315;
}
F_305 ( V_75 ) ;
if ( V_71 & V_307 ) {
if ( ! F_362 ( V_259 ) ) {
V_13 = F_331 ( V_248 , V_19 , V_51 , V_261 , V_259 ,
V_290 , V_284 ) ;
goto V_316;
}
V_259 = F_273 ( V_259 ) ;
}
V_259 = F_276 ( V_259 ) ;
if ( F_281 ( V_19 , V_51 , V_261 , V_259 ,
V_71 & V_307 ) )
F_282 ( V_19 , V_51 , V_261 ) ;
V_316:
if ( V_75 != V_290 )
F_356 ( V_75 ) ;
F_138 ( V_75 ) ;
V_315:
F_2 ( V_284 ) ;
if ( V_290 ) {
F_356 ( V_290 ) ;
F_138 ( V_290 ) ;
}
V_314:
F_364 ( & V_224 [ V_311 ] ) ;
if ( V_312 )
F_365 ( V_75 ) ;
return V_13 ;
}
long F_366 ( struct V_247 * V_248 , struct V_18 * V_19 ,
struct V_75 * * V_317 , struct V_18 * * V_318 ,
unsigned long * V_319 , unsigned long * V_103 ,
long V_102 , unsigned int V_71 )
{
unsigned long V_320 ;
unsigned long V_321 = * V_319 ;
unsigned long V_322 = * V_103 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
while ( V_321 < V_19 -> V_255 && V_322 ) {
T_9 * V_262 ;
T_11 * V_284 = NULL ;
int V_323 ;
struct V_75 * V_75 ;
if ( F_72 ( F_367 ( V_187 ) ) ) {
V_322 = 0 ;
break;
}
V_262 = F_293 ( V_248 , V_321 & F_310 ( V_8 ) ) ;
if ( V_262 )
V_284 = F_295 ( V_8 , V_248 , V_262 ) ;
V_323 = ! V_262 || F_284 ( F_280 ( V_262 ) ) ;
if ( V_323 && ( V_71 & V_324 ) &&
! F_344 ( V_8 , V_19 , V_321 ) ) {
if ( V_262 )
F_2 ( V_284 ) ;
V_322 = 0 ;
break;
}
if ( V_323 || F_368 ( F_280 ( V_262 ) ) ||
( ( V_71 & V_325 ) &&
! F_362 ( F_280 ( V_262 ) ) ) ) {
int V_13 ;
if ( V_262 )
F_2 ( V_284 ) ;
V_13 = F_359 ( V_248 , V_19 , V_321 ,
( V_71 & V_325 ) ? V_307 : 0 ) ;
if ( ! ( V_13 & V_326 ) )
continue;
V_322 = 0 ;
break;
}
V_320 = ( V_321 & ~ F_310 ( V_8 ) ) >> V_180 ;
V_75 = F_304 ( F_280 ( V_262 ) ) ;
V_327:
if ( V_317 ) {
V_317 [ V_102 ] = F_369 ( V_75 , V_320 ) ;
F_305 ( V_317 [ V_102 ] ) ;
}
if ( V_318 )
V_318 [ V_102 ] = V_19 ;
V_321 += V_54 ;
++ V_320 ;
-- V_322 ;
++ V_102 ;
if ( V_321 < V_19 -> V_255 && V_322 &&
V_320 < F_114 ( V_8 ) ) {
goto V_327;
}
F_2 ( V_284 ) ;
}
* V_103 = V_322 ;
* V_319 = V_321 ;
return V_102 ? V_102 : - V_328 ;
}
unsigned long F_370 ( struct V_18 * V_19 ,
unsigned long V_51 , unsigned long V_253 , T_13 V_329 )
{
struct V_247 * V_248 = V_19 -> V_283 ;
unsigned long V_252 = V_51 ;
T_9 * V_261 ;
T_9 V_262 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_317 = 0 ;
F_10 ( V_51 >= V_253 ) ;
F_371 ( V_19 , V_51 , V_253 ) ;
F_292 ( V_248 , V_252 , V_253 ) ;
F_328 ( V_19 -> V_20 -> V_67 ) ;
for (; V_51 < V_253 ; V_51 += F_121 ( V_8 ) ) {
T_11 * V_284 ;
V_261 = F_293 ( V_248 , V_51 ) ;
if ( ! V_261 )
continue;
V_284 = F_295 ( V_8 , V_248 , V_261 ) ;
if ( F_312 ( V_248 , & V_51 , V_261 ) ) {
V_317 ++ ;
F_2 ( V_284 ) ;
continue;
}
V_262 = F_280 ( V_261 ) ;
if ( F_72 ( F_289 ( V_262 ) ) ) {
F_2 ( V_284 ) ;
continue;
}
if ( F_72 ( F_283 ( V_262 ) ) ) {
T_10 V_259 = F_286 ( V_262 ) ;
if ( F_298 ( V_259 ) ) {
T_9 V_330 ;
F_299 ( & V_259 ) ;
V_330 = F_300 ( V_259 ) ;
F_301 ( V_248 , V_51 , V_261 , V_330 ) ;
V_317 ++ ;
}
F_2 ( V_284 ) ;
continue;
}
if ( ! F_284 ( V_262 ) ) {
V_262 = F_314 ( V_248 , V_51 , V_261 ) ;
V_262 = F_277 ( F_372 ( V_262 , V_329 ) ) ;
V_262 = F_278 ( V_262 , V_19 , NULL , 0 ) ;
F_301 ( V_248 , V_51 , V_261 , V_262 ) ;
V_317 ++ ;
}
F_2 ( V_284 ) ;
}
F_373 ( V_19 , V_252 , V_253 ) ;
F_303 ( V_248 , V_252 , V_253 ) ;
F_330 ( V_19 -> V_20 -> V_67 ) ;
F_308 ( V_248 , V_252 , V_253 ) ;
return V_317 << V_8 -> V_101 ;
}
int F_374 ( struct V_16 * V_16 ,
long V_35 , long V_33 ,
struct V_18 * V_19 ,
T_14 V_63 )
{
long V_13 , V_41 ;
struct V_7 * V_8 = F_30 ( V_16 ) ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
struct V_21 * V_21 ;
long V_254 ;
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
goto V_331;
}
V_254 = F_11 ( V_2 , V_41 ) ;
if ( V_254 < 0 ) {
V_13 = - V_170 ;
goto V_331;
}
V_13 = F_3 ( V_8 , V_254 ) ;
if ( V_13 < 0 ) {
( void ) F_12 ( V_2 , V_41 ) ;
goto V_331;
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
V_331:
if ( ! V_19 || V_19 -> V_63 & V_64 )
F_27 ( V_21 , V_35 , V_33 ) ;
if ( V_19 && F_53 ( V_19 , V_74 ) )
F_269 ( & V_21 -> V_57 , F_46 ) ;
return V_13 ;
}
long F_375 ( struct V_16 * V_16 , long V_252 , long V_253 ,
long V_332 )
{
struct V_7 * V_8 = F_30 ( V_16 ) ;
struct V_21 * V_21 = F_48 ( V_16 ) ;
long V_41 = 0 ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
long V_254 ;
if ( V_21 ) {
V_41 = F_28 ( V_21 , V_252 , V_253 ) ;
if ( V_41 < 0 )
return V_41 ;
}
F_9 ( & V_16 -> V_299 ) ;
V_16 -> V_300 -= ( F_348 ( V_8 ) * V_332 ) ;
F_2 ( & V_16 -> V_299 ) ;
V_254 = F_12 ( V_2 , ( V_41 - V_332 ) ) ;
F_3 ( V_8 , - V_254 ) ;
return 0 ;
}
static unsigned long F_376 ( struct V_18 * V_333 ,
struct V_18 * V_19 ,
unsigned long V_144 , T_1 V_161 )
{
unsigned long V_334 = ( ( V_161 - V_333 -> V_53 ) << V_180 ) +
V_333 -> V_52 ;
unsigned long V_335 = V_334 & V_336 ;
unsigned long V_337 = V_335 + V_338 ;
unsigned long V_63 = V_19 -> V_63 & V_339 ;
unsigned long V_340 = V_333 -> V_63 & V_339 ;
if ( F_377 ( V_144 ) != F_377 ( V_334 ) ||
V_63 != V_340 ||
V_335 < V_333 -> V_52 || V_333 -> V_255 < V_337 )
return 0 ;
return V_334 ;
}
static bool F_378 ( struct V_18 * V_19 , unsigned long V_144 )
{
unsigned long V_341 = V_144 & V_336 ;
unsigned long V_253 = V_341 + V_338 ;
if ( V_19 -> V_63 & V_64 &&
V_19 -> V_52 <= V_341 && V_253 <= V_19 -> V_255 )
return true ;
return false ;
}
T_9 * F_379 ( struct V_247 * V_248 , unsigned long V_144 , T_15 * V_342 )
{
struct V_18 * V_19 = F_380 ( V_248 , V_144 ) ;
struct V_65 * V_66 = V_19 -> V_20 -> V_67 ;
T_1 V_161 = ( ( V_144 - V_19 -> V_52 ) >> V_180 ) +
V_19 -> V_53 ;
struct V_18 * V_333 ;
unsigned long V_334 ;
T_9 * V_343 = NULL ;
T_9 * V_262 ;
T_11 * V_284 ;
if ( ! F_378 ( V_19 , V_144 ) )
return ( T_9 * ) F_381 ( V_248 , V_342 , V_144 ) ;
F_328 ( V_66 ) ;
F_329 (svma, &mapping->i_mmap, idx, idx) {
if ( V_333 == V_19 )
continue;
V_334 = F_376 ( V_333 , V_19 , V_144 , V_161 ) ;
if ( V_334 ) {
V_343 = F_293 ( V_333 -> V_283 , V_334 ) ;
if ( V_343 ) {
F_305 ( F_196 ( V_343 ) ) ;
break;
}
}
}
if ( ! V_343 )
goto V_45;
V_284 = F_296 ( F_38 ( V_19 ) , V_248 , V_343 ) ;
F_9 ( V_284 ) ;
if ( F_382 ( * V_342 ) ) {
F_383 ( V_248 , V_342 ,
( V_344 * ) ( ( unsigned long ) V_343 & V_345 ) ) ;
F_384 ( V_248 ) ;
} else {
F_138 ( F_196 ( V_343 ) ) ;
}
F_2 ( V_284 ) ;
V_45:
V_262 = ( T_9 * ) F_381 ( V_248 , V_342 , V_144 ) ;
F_330 ( V_66 ) ;
return V_262 ;
}
int F_312 ( struct V_247 * V_248 , unsigned long * V_144 , T_9 * V_261 )
{
T_16 * V_346 = F_385 ( V_248 , * V_144 ) ;
T_15 * V_342 = F_386 ( V_346 , * V_144 ) ;
F_10 ( F_97 ( F_196 ( V_261 ) ) == 0 ) ;
if ( F_97 ( F_196 ( V_261 ) ) == 1 )
return 0 ;
F_387 ( V_342 ) ;
F_138 ( F_196 ( V_261 ) ) ;
F_388 ( V_248 ) ;
* V_144 = F_104 ( * V_144 , V_218 * V_347 ) - V_218 ;
return 1 ;
}
T_9 * F_379 ( struct V_247 * V_248 , unsigned long V_144 , T_15 * V_342 )
{
return NULL ;
}
int F_312 ( struct V_247 * V_248 , unsigned long * V_144 , T_9 * V_261 )
{
return 0 ;
}
T_9 * F_294 ( struct V_247 * V_248 ,
unsigned long V_144 , unsigned long V_270 )
{
T_16 * V_346 ;
T_15 * V_342 ;
T_9 * V_262 = NULL ;
V_346 = F_385 ( V_248 , V_144 ) ;
V_342 = F_389 ( V_248 , V_346 , V_144 ) ;
if ( V_342 ) {
if ( V_270 == V_338 ) {
V_262 = ( T_9 * ) V_342 ;
} else {
F_10 ( V_270 != V_348 ) ;
if ( F_390 () && F_382 ( * V_342 ) )
V_262 = F_379 ( V_248 , V_144 , V_342 ) ;
else
V_262 = ( T_9 * ) F_381 ( V_248 , V_342 , V_144 ) ;
}
}
F_10 ( V_262 && ! F_391 ( * V_262 ) && ! F_392 ( * V_262 ) ) ;
return V_262 ;
}
T_9 * F_293 ( struct V_247 * V_248 , unsigned long V_144 )
{
T_16 * V_346 ;
T_15 * V_342 ;
V_344 * V_349 = NULL ;
V_346 = F_385 ( V_248 , V_144 ) ;
if ( F_393 ( * V_346 ) ) {
V_342 = F_386 ( V_346 , V_144 ) ;
if ( F_394 ( * V_342 ) ) {
if ( F_395 ( * V_342 ) )
return ( T_9 * ) V_342 ;
V_349 = F_396 ( V_342 , V_144 ) ;
}
}
return ( T_9 * ) V_349 ;
}
struct V_75 * __weak
F_397 ( struct V_247 * V_248 , unsigned long V_51 ,
int V_239 )
{
return F_181 ( - V_199 ) ;
}
struct V_75 * __weak
F_398 ( struct V_247 * V_248 , unsigned long V_51 ,
V_344 * V_349 , int V_71 )
{
struct V_75 * V_75 = NULL ;
T_11 * V_284 ;
V_42:
V_284 = F_399 ( V_248 , V_349 ) ;
F_9 ( V_284 ) ;
if ( ! F_400 ( * V_349 ) )
goto V_45;
if ( F_401 ( * V_349 ) ) {
V_75 = F_402 ( * V_349 ) + ( ( V_51 & ~ V_350 ) >> V_180 ) ;
if ( V_71 & V_351 )
F_305 ( V_75 ) ;
} else {
if ( F_283 ( F_280 ( ( T_9 * ) V_349 ) ) ) {
F_2 ( V_284 ) ;
F_403 ( V_248 , ( T_9 * ) V_349 , V_284 ) ;
goto V_42;
}
}
V_45:
F_2 ( V_284 ) ;
return V_75 ;
}
struct V_75 * __weak
F_404 ( struct V_247 * V_248 , unsigned long V_51 ,
T_15 * V_342 , int V_71 )
{
if ( V_71 & V_351 )
return NULL ;
return F_304 ( * ( T_9 * ) V_342 ) + ( ( V_51 & ~ V_336 ) >> V_180 ) ;
}
int F_405 ( struct V_75 * V_352 )
{
struct V_7 * V_8 = F_130 ( V_352 ) ;
int V_76 = F_57 ( V_352 ) ;
int V_13 = - V_353 ;
F_9 ( & V_126 ) ;
if ( ! F_122 ( V_352 ) && ! F_97 ( V_352 ) ) {
F_406 ( & V_352 -> V_77 ) ;
F_61 ( V_352 ) ;
V_8 -> V_79 -- ;
V_8 -> V_80 [ V_76 ] -- ;
V_13 = 0 ;
}
F_2 ( & V_126 ) ;
return V_13 ;
}
bool F_407 ( struct V_75 * V_75 , struct V_25 * V_177 )
{
bool V_13 = true ;
F_115 ( ! F_123 ( V_75 ) , V_75 ) ;
F_9 ( & V_126 ) ;
if ( ! F_122 ( V_75 ) || ! F_408 ( V_75 ) ) {
V_13 = false ;
goto V_286;
}
F_127 ( V_75 ) ;
F_409 ( & V_75 -> V_77 , V_177 ) ;
V_286:
F_2 ( & V_126 ) ;
return V_13 ;
}
void F_410 ( struct V_75 * V_75 )
{
F_115 ( ! F_123 ( V_75 ) , V_75 ) ;
F_9 ( & V_126 ) ;
F_125 ( V_75 ) ;
F_409 ( & V_75 -> V_77 , & ( F_130 ( V_75 ) ) -> V_81 ) ;
F_2 ( & V_126 ) ;
F_138 ( V_75 ) ;
}
