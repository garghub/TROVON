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
void F_29 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_13 ( V_16 ) ;
long V_47 ;
V_47 = F_11 ( V_2 , 1 ) ;
if ( V_47 ) {
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
long V_48 ;
long V_49 ;
if ( V_29 -> V_33 <= V_23 )
continue;
if ( V_29 -> V_35 >= V_24 )
break;
V_48 = F_32 ( V_29 -> V_35 , V_23 ) ;
V_49 = F_33 ( V_29 -> V_33 , V_24 ) ;
V_41 += V_49 - V_48 ;
}
F_2 ( & V_22 -> V_5 ) ;
return V_41 ;
}
static T_1 F_34 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_50 )
{
return ( ( V_50 - V_19 -> V_51 ) >> F_35 ( V_8 ) ) +
( V_19 -> V_52 >> F_36 ( V_8 ) ) ;
}
T_1 F_37 ( struct V_18 * V_19 ,
unsigned long V_50 )
{
return F_34 ( F_38 ( V_19 ) , V_19 , V_50 ) ;
}
unsigned long F_39 ( struct V_18 * V_19 )
{
struct V_7 * V_7 ;
if ( ! F_40 ( V_19 ) )
return V_53 ;
V_7 = F_38 ( V_19 ) ;
return 1UL << F_35 ( V_7 ) ;
}
unsigned long F_41 ( struct V_18 * V_19 )
{
return F_39 ( V_19 ) ;
}
static unsigned long F_42 ( struct V_18 * V_19 )
{
return ( unsigned long ) V_19 -> V_54 ;
}
static void F_43 ( struct V_18 * V_19 ,
unsigned long V_55 )
{
V_19 -> V_54 = ( void * ) V_55 ;
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
F_45 ( & V_21 -> V_56 ) ;
F_7 ( & V_21 -> V_5 ) ;
F_26 ( & V_21 -> V_27 ) ;
V_21 -> V_40 = 0 ;
F_26 ( & V_21 -> V_37 ) ;
F_22 ( & V_29 -> V_34 , & V_21 -> V_37 ) ;
V_21 -> V_36 = 1 ;
return V_21 ;
}
void F_46 ( struct V_57 * V_58 )
{
struct V_21 * V_21 = F_47 ( V_58 , struct V_21 , V_56 ) ;
struct V_25 * V_26 = & V_21 -> V_37 ;
struct V_28 * V_29 , * V_31 ;
F_28 ( V_21 , 0 , V_59 ) ;
F_23 (rg, trg, head, link) {
F_21 ( & V_29 -> V_34 ) ;
F_4 ( V_29 ) ;
}
F_19 ( V_21 -> V_40 ) ;
F_4 ( V_21 ) ;
}
static inline struct V_21 * F_48 ( struct V_16 * V_16 )
{
return V_16 -> V_60 -> V_61 ;
}
static struct V_21 * F_49 ( struct V_18 * V_19 )
{
F_50 ( ! F_40 ( V_19 ) , V_19 ) ;
if ( V_19 -> V_62 & V_63 ) {
struct V_64 * V_65 = V_19 -> V_20 -> V_66 ;
struct V_16 * V_16 = V_65 -> V_67 ;
return F_48 ( V_16 ) ;
} else {
return (struct V_21 * ) ( F_42 ( V_19 ) &
~ V_68 ) ;
}
}
static void F_51 ( struct V_18 * V_19 , struct V_21 * V_69 )
{
F_50 ( ! F_40 ( V_19 ) , V_19 ) ;
F_50 ( V_19 -> V_62 & V_63 , V_19 ) ;
F_43 ( V_19 , ( F_42 ( V_19 ) &
V_68 ) | ( unsigned long ) V_69 ) ;
}
static void F_52 ( struct V_18 * V_19 , unsigned long V_70 )
{
F_50 ( ! F_40 ( V_19 ) , V_19 ) ;
F_50 ( V_19 -> V_62 & V_63 , V_19 ) ;
F_43 ( V_19 , F_42 ( V_19 ) | V_70 ) ;
}
static int F_53 ( struct V_18 * V_19 , unsigned long V_71 )
{
F_50 ( ! F_40 ( V_19 ) , V_19 ) ;
return ( F_42 ( V_19 ) & V_71 ) != 0 ;
}
void F_54 ( struct V_18 * V_19 )
{
F_50 ( ! F_40 ( V_19 ) , V_19 ) ;
if ( ! ( V_19 -> V_62 & V_63 ) )
V_19 -> V_54 = ( void * ) 0 ;
}
static bool F_55 ( struct V_18 * V_19 , long V_41 )
{
if ( V_19 -> V_62 & V_72 ) {
if ( V_19 -> V_62 & V_63 && V_41 == 0 )
return true ;
else
return false ;
}
if ( V_19 -> V_62 & V_63 ) {
if ( V_41 )
return false ;
else
return true ;
}
if ( F_53 ( V_19 , V_73 ) ) {
if ( V_41 )
return false ;
else
return true ;
}
return false ;
}
static void F_56 ( struct V_7 * V_8 , struct V_74 * V_74 )
{
int V_75 = F_57 ( V_74 ) ;
F_58 ( & V_74 -> V_76 , & V_8 -> V_77 [ V_75 ] ) ;
V_8 -> V_78 ++ ;
V_8 -> V_79 [ V_75 ] ++ ;
}
static struct V_74 * F_59 ( struct V_7 * V_8 , int V_75 )
{
struct V_74 * V_74 ;
F_18 (page, &h->hugepage_freelists[nid], lru)
if ( ! F_60 ( V_74 ) )
break;
if ( & V_8 -> V_77 [ V_75 ] == & V_74 -> V_76 )
return NULL ;
F_58 ( & V_74 -> V_76 , & V_8 -> V_80 ) ;
F_61 ( V_74 ) ;
V_8 -> V_78 -- ;
V_8 -> V_79 [ V_75 ] -- ;
return V_74 ;
}
static inline T_2 F_62 ( struct V_7 * V_8 )
{
if ( V_81 || F_63 ( V_8 ) )
return V_82 ;
else
return V_83 ;
}
static struct V_74 * F_64 ( struct V_7 * V_8 ,
struct V_18 * V_19 ,
unsigned long V_50 , int V_84 ,
long V_41 )
{
struct V_74 * V_74 = NULL ;
struct V_85 * V_86 ;
T_3 * V_87 ;
struct V_88 * V_88 ;
struct V_89 * V_89 ;
struct V_90 * V_91 ;
unsigned int V_92 ;
if ( ! F_55 ( V_19 , V_41 ) &&
V_8 -> V_78 - V_8 -> V_93 == 0 )
goto V_94;
if ( V_84 && V_8 -> V_78 - V_8 -> V_93 == 0 )
goto V_94;
V_95:
V_92 = F_65 () ;
V_88 = F_66 ( V_19 , V_50 ,
F_62 ( V_8 ) , & V_86 , & V_87 ) ;
F_67 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_68 ( V_89 , F_62 ( V_8 ) ) ) {
V_74 = F_59 ( V_8 , F_69 ( V_89 ) ) ;
if ( V_74 ) {
if ( V_84 )
break;
if ( ! F_55 ( V_19 , V_41 ) )
break;
F_70 ( V_74 ) ;
V_8 -> V_93 -- ;
break;
}
}
}
F_71 ( V_86 ) ;
if ( F_72 ( ! V_74 && F_73 ( V_92 ) ) )
goto V_95;
return V_74 ;
V_94:
return NULL ;
}
static int F_74 ( int V_75 , T_3 * V_96 )
{
V_75 = F_75 ( V_75 , * V_96 ) ;
F_19 ( V_75 >= V_97 ) ;
return V_75 ;
}
static int F_76 ( int V_75 , T_3 * V_96 )
{
if ( ! F_77 ( V_75 , * V_96 ) )
V_75 = F_74 ( V_75 , V_96 ) ;
return V_75 ;
}
static int F_78 ( struct V_7 * V_8 ,
T_3 * V_96 )
{
int V_75 ;
F_19 ( ! V_96 ) ;
V_75 = F_76 ( V_8 -> V_98 , V_96 ) ;
V_8 -> V_98 = F_74 ( V_75 , V_96 ) ;
return V_75 ;
}
static int F_79 ( struct V_7 * V_8 , T_3 * V_96 )
{
int V_75 ;
F_19 ( ! V_96 ) ;
V_75 = F_76 ( V_8 -> V_99 , V_96 ) ;
V_8 -> V_99 = F_74 ( V_75 , V_96 ) ;
return V_75 ;
}
static void F_80 ( struct V_74 * V_74 ,
unsigned int V_100 )
{
int V_101 ;
int V_102 = 1 << V_100 ;
struct V_74 * V_103 = V_74 + 1 ;
F_81 ( F_82 ( V_74 ) , 0 ) ;
for ( V_101 = 1 ; V_101 < V_102 ; V_101 ++ , V_103 = F_83 ( V_103 , V_74 , V_101 ) ) {
F_84 ( V_103 ) ;
F_61 ( V_103 ) ;
}
F_85 ( V_74 , 0 ) ;
F_86 ( V_74 ) ;
}
static void F_87 ( struct V_74 * V_74 , unsigned int V_100 )
{
F_88 ( F_89 ( V_74 ) , 1 << V_100 ) ;
}
static int F_90 ( unsigned long V_104 ,
unsigned long V_102 )
{
unsigned long V_105 = V_104 + V_102 ;
return F_91 ( V_104 , V_105 , V_106 ,
V_10 ) ;
}
static bool F_92 ( struct V_89 * V_91 ,
unsigned long V_104 , unsigned long V_102 )
{
unsigned long V_101 , V_105 = V_104 + V_102 ;
struct V_74 * V_74 ;
for ( V_101 = V_104 ; V_101 < V_105 ; V_101 ++ ) {
if ( ! F_93 ( V_101 ) )
return false ;
V_74 = F_94 ( V_101 ) ;
if ( F_95 ( V_74 ) != V_91 )
return false ;
if ( F_96 ( V_74 ) )
return false ;
if ( F_97 ( V_74 ) > 0 )
return false ;
if ( F_98 ( V_74 ) )
return false ;
}
return true ;
}
static bool F_99 ( const struct V_89 * V_89 ,
unsigned long V_104 , unsigned long V_102 )
{
unsigned long V_107 = V_104 + V_102 - 1 ;
return F_100 ( V_89 , V_107 ) ;
}
static struct V_74 * F_101 ( int V_75 , unsigned int V_100 )
{
unsigned long V_102 = 1 << V_100 ;
unsigned long V_13 , V_108 , V_70 ;
struct V_89 * V_91 ;
V_91 = F_102 ( V_75 ) -> V_109 ;
for (; V_91 - F_102 ( V_75 ) -> V_109 < V_110 ; V_91 ++ ) {
F_103 ( & V_91 -> V_5 , V_70 ) ;
V_108 = F_104 ( V_91 -> V_111 , V_102 ) ;
while ( F_99 ( V_91 , V_108 , V_102 ) ) {
if ( F_92 ( V_91 , V_108 , V_102 ) ) {
F_105 ( & V_91 -> V_5 , V_70 ) ;
V_13 = F_90 ( V_108 , V_102 ) ;
if ( ! V_13 )
return F_94 ( V_108 ) ;
F_103 ( & V_91 -> V_5 , V_70 ) ;
}
V_108 += V_102 ;
}
F_105 ( & V_91 -> V_5 , V_70 ) ;
}
return NULL ;
}
static struct V_74 * F_106 ( struct V_7 * V_8 , int V_75 )
{
struct V_74 * V_74 ;
V_74 = F_101 ( V_75 , F_36 ( V_8 ) ) ;
if ( V_74 ) {
F_107 ( V_74 , F_36 ( V_8 ) ) ;
F_108 ( V_8 , V_74 , V_75 ) ;
}
return V_74 ;
}
static int F_109 ( struct V_7 * V_8 ,
T_3 * V_96 )
{
struct V_74 * V_74 = NULL ;
int V_112 , V_113 ;
F_110 (h, nr_nodes, node, nodes_allowed) {
V_74 = F_106 ( V_8 , V_113 ) ;
if ( V_74 )
return 1 ;
}
return 0 ;
}
static inline bool F_111 ( void ) { return true ; }
static inline bool F_111 ( void ) { return false ; }
static inline void F_87 ( struct V_74 * V_74 , unsigned int V_100 ) { }
static inline void F_80 ( struct V_74 * V_74 ,
unsigned int V_100 ) { }
static inline int F_109 ( struct V_7 * V_8 ,
T_3 * V_96 ) { return 0 ; }
static void F_112 ( struct V_7 * V_8 , struct V_74 * V_74 )
{
int V_101 ;
if ( F_113 ( V_8 ) && ! F_111 () )
return;
V_8 -> V_114 -- ;
V_8 -> V_115 [ F_57 ( V_74 ) ] -- ;
for ( V_101 = 0 ; V_101 < F_114 ( V_8 ) ; V_101 ++ ) {
V_74 [ V_101 ] . V_70 &= ~ ( 1 << V_116 | 1 << V_117 |
1 << V_118 | 1 << V_119 |
1 << V_120 | 1 << V_121 |
1 << V_122 ) ;
}
F_115 ( F_116 ( V_74 ) , V_74 ) ;
F_117 ( V_74 , V_123 ) ;
F_61 ( V_74 ) ;
if ( F_113 ( V_8 ) ) {
F_80 ( V_74 , F_36 ( V_8 ) ) ;
F_87 ( V_74 , F_36 ( V_8 ) ) ;
} else {
F_118 ( V_74 , F_36 ( V_8 ) ) ;
}
}
struct V_7 * F_119 ( unsigned long V_124 )
{
struct V_7 * V_8 ;
F_120 (h) {
if ( F_121 ( V_8 ) == V_124 )
return V_8 ;
}
return NULL ;
}
bool F_122 ( struct V_74 * V_74 )
{
F_115 ( ! F_98 ( V_74 ) , V_74 ) ;
return F_123 ( V_74 ) && F_124 ( & V_74 [ 1 ] ) ;
}
static void F_125 ( struct V_74 * V_74 )
{
F_115 ( ! F_126 ( V_74 ) , V_74 ) ;
F_70 ( & V_74 [ 1 ] ) ;
}
static void F_127 ( struct V_74 * V_74 )
{
F_115 ( ! F_126 ( V_74 ) , V_74 ) ;
F_128 ( & V_74 [ 1 ] ) ;
}
void F_129 ( struct V_74 * V_74 )
{
struct V_7 * V_8 = F_130 ( V_74 ) ;
int V_75 = F_57 ( V_74 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_131 ( V_74 ) ;
bool V_125 ;
F_132 ( V_74 , 0 ) ;
V_74 -> V_65 = NULL ;
F_115 ( F_97 ( V_74 ) , V_74 ) ;
F_115 ( F_133 ( V_74 ) , V_74 ) ;
V_125 = F_124 ( V_74 ) ;
F_128 ( V_74 ) ;
if ( F_12 ( V_2 , 1 ) == 0 )
V_125 = true ;
F_9 ( & V_126 ) ;
F_127 ( V_74 ) ;
F_134 ( F_135 ( V_8 ) ,
F_114 ( V_8 ) , V_74 ) ;
if ( V_125 )
V_8 -> V_93 ++ ;
if ( V_8 -> V_127 [ V_75 ] ) {
F_21 ( & V_74 -> V_76 ) ;
F_112 ( V_8 , V_74 ) ;
V_8 -> V_128 -- ;
V_8 -> V_127 [ V_75 ] -- ;
} else {
F_136 ( V_74 ) ;
F_56 ( V_8 , V_74 ) ;
}
F_2 ( & V_126 ) ;
}
static void F_108 ( struct V_7 * V_8 , struct V_74 * V_74 , int V_75 )
{
F_26 ( & V_74 -> V_76 ) ;
F_117 ( V_74 , V_129 ) ;
F_9 ( & V_126 ) ;
F_137 ( V_74 , NULL ) ;
V_8 -> V_114 ++ ;
V_8 -> V_115 [ V_75 ] ++ ;
F_2 ( & V_126 ) ;
F_138 ( V_74 ) ;
}
static void F_107 ( struct V_74 * V_74 , unsigned int V_100 )
{
int V_101 ;
int V_102 = 1 << V_100 ;
struct V_74 * V_103 = V_74 + 1 ;
F_85 ( V_74 , V_100 ) ;
F_139 ( V_74 ) ;
F_140 ( V_74 ) ;
for ( V_101 = 1 ; V_101 < V_102 ; V_101 ++ , V_103 = F_83 ( V_103 , V_74 , V_101 ) ) {
F_139 ( V_103 ) ;
F_141 ( V_103 , 0 ) ;
F_142 ( V_103 , V_74 ) ;
}
F_81 ( F_82 ( V_74 ) , - 1 ) ;
}
int F_98 ( struct V_74 * V_74 )
{
if ( ! F_143 ( V_74 ) )
return 0 ;
V_74 = F_144 ( V_74 ) ;
return V_74 [ 1 ] . V_130 == V_129 ;
}
int F_126 ( struct V_74 * V_131 )
{
if ( ! F_123 ( V_131 ) )
return 0 ;
return F_145 ( V_131 ) == F_129 ;
}
T_1 F_146 ( struct V_74 * V_74 )
{
struct V_74 * V_131 = F_144 ( V_74 ) ;
T_1 V_132 = F_147 ( V_131 ) ;
unsigned long V_133 ;
if ( ! F_98 ( V_131 ) )
return F_147 ( V_74 ) ;
if ( F_148 ( V_131 ) >= V_134 )
V_133 = F_89 ( V_74 ) - F_89 ( V_131 ) ;
else
V_133 = V_74 - V_131 ;
return ( V_132 << F_148 ( V_131 ) ) + V_133 ;
}
static struct V_74 * F_149 ( struct V_7 * V_8 , int V_75 )
{
struct V_74 * V_74 ;
V_74 = F_150 ( V_75 ,
F_62 ( V_8 ) | V_135 | V_136 |
V_137 | V_138 ,
F_36 ( V_8 ) ) ;
if ( V_74 ) {
F_108 ( V_8 , V_74 , V_75 ) ;
}
return V_74 ;
}
static int F_151 ( struct V_7 * V_8 , T_3 * V_96 )
{
struct V_74 * V_74 ;
int V_112 , V_113 ;
int V_13 = 0 ;
F_110 (h, nr_nodes, node, nodes_allowed) {
V_74 = F_149 ( V_8 , V_113 ) ;
if ( V_74 ) {
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
static int F_153 ( struct V_7 * V_8 , T_3 * V_96 ,
bool V_141 )
{
int V_112 , V_113 ;
int V_13 = 0 ;
F_154 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_141 || V_8 -> V_127 [ V_113 ] ) &&
! F_155 ( & V_8 -> V_77 [ V_113 ] ) ) {
struct V_74 * V_74 =
F_156 ( V_8 -> V_77 [ V_113 ] . V_142 ,
struct V_74 , V_76 ) ;
F_21 ( & V_74 -> V_76 ) ;
V_8 -> V_78 -- ;
V_8 -> V_79 [ V_113 ] -- ;
if ( V_141 ) {
V_8 -> V_128 -- ;
V_8 -> V_127 [ V_113 ] -- ;
}
F_112 ( V_8 , V_74 ) ;
V_13 = 1 ;
break;
}
}
return V_13 ;
}
static int F_157 ( struct V_74 * V_74 )
{
int V_143 = 0 ;
F_9 ( & V_126 ) ;
if ( F_98 ( V_74 ) && ! F_97 ( V_74 ) ) {
struct V_74 * V_26 = F_144 ( V_74 ) ;
struct V_7 * V_8 = F_130 ( V_26 ) ;
int V_75 = F_57 ( V_26 ) ;
if ( V_8 -> V_78 - V_8 -> V_93 == 0 ) {
V_143 = - V_144 ;
goto V_45;
}
F_21 ( & V_26 -> V_76 ) ;
V_8 -> V_78 -- ;
V_8 -> V_79 [ V_75 ] -- ;
V_8 -> V_145 -- ;
F_112 ( V_8 , V_26 ) ;
}
V_45:
F_2 ( & V_126 ) ;
return V_143 ;
}
int F_158 ( unsigned long V_104 , unsigned long V_105 )
{
unsigned long V_108 ;
struct V_74 * V_74 ;
int V_143 = 0 ;
if ( ! F_159 () )
return V_143 ;
for ( V_108 = V_104 ; V_108 < V_105 ; V_108 += 1 << V_146 ) {
V_74 = F_94 ( V_108 ) ;
if ( F_98 ( V_74 ) && ! F_97 ( V_74 ) ) {
V_143 = F_157 ( V_74 ) ;
if ( V_143 )
break;
}
}
return V_143 ;
}
static struct V_74 * F_160 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_147 , int V_75 )
{
int V_100 = F_36 ( V_8 ) ;
T_2 V_148 = F_62 ( V_8 ) | V_135 | V_137 | V_138 ;
unsigned int V_92 ;
if ( ! F_161 ( V_149 ) || ! V_19 ) {
if ( V_75 != V_150 )
V_148 |= V_136 ;
return F_162 ( V_75 , V_148 , V_100 ) ;
}
do {
struct V_74 * V_74 ;
struct V_85 * V_86 ;
struct V_88 * V_151 ;
T_3 * V_87 ;
V_92 = F_65 () ;
V_151 = F_66 ( V_19 , V_147 , V_148 , & V_86 , & V_87 ) ;
F_71 ( V_86 ) ;
V_74 = F_163 ( V_148 , V_100 , V_151 , V_87 ) ;
if ( V_74 )
return V_74 ;
} while ( F_73 ( V_92 ) );
return NULL ;
}
static struct V_74 * F_164 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_147 , int V_75 )
{
struct V_74 * V_74 ;
unsigned int V_152 ;
if ( F_113 ( V_8 ) )
return NULL ;
if ( V_19 || ( V_147 != - 1 ) ) {
F_165 ( V_147 == - 1 ) ;
F_165 ( V_75 != V_150 ) ;
}
F_9 ( & V_126 ) ;
if ( V_8 -> V_128 >= V_8 -> V_153 ) {
F_2 ( & V_126 ) ;
return NULL ;
} else {
V_8 -> V_114 ++ ;
V_8 -> V_128 ++ ;
}
F_2 ( & V_126 ) ;
V_74 = F_160 ( V_8 , V_19 , V_147 , V_75 ) ;
F_9 ( & V_126 ) ;
if ( V_74 ) {
F_26 ( & V_74 -> V_76 ) ;
V_152 = F_57 ( V_74 ) ;
F_117 ( V_74 , V_129 ) ;
F_137 ( V_74 , NULL ) ;
V_8 -> V_115 [ V_152 ] ++ ;
V_8 -> V_127 [ V_152 ] ++ ;
F_166 ( V_139 ) ;
} else {
V_8 -> V_114 -- ;
V_8 -> V_128 -- ;
F_166 ( V_140 ) ;
}
F_2 ( & V_126 ) ;
return V_74 ;
}
static
struct V_74 * F_167 ( struct V_7 * V_8 , int V_75 )
{
unsigned long V_147 = - 1 ;
return F_164 ( V_8 , NULL , V_147 , V_75 ) ;
}
static
struct V_74 * F_168 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_147 )
{
return F_164 ( V_8 , V_19 , V_147 , V_150 ) ;
}
struct V_74 * F_169 ( struct V_7 * V_8 , int V_75 )
{
struct V_74 * V_74 = NULL ;
F_9 ( & V_126 ) ;
if ( V_8 -> V_78 - V_8 -> V_93 > 0 )
V_74 = F_59 ( V_8 , V_75 ) ;
F_2 ( & V_126 ) ;
if ( ! V_74 )
V_74 = F_167 ( V_8 , V_75 ) ;
return V_74 ;
}
static int F_170 ( struct V_7 * V_8 , int V_12 )
{
struct V_25 V_154 ;
struct V_74 * V_74 , * V_155 ;
int V_13 , V_101 ;
int V_156 , V_157 ;
bool V_158 = true ;
V_156 = ( V_8 -> V_93 + V_12 ) - V_8 -> V_78 ;
if ( V_156 <= 0 ) {
V_8 -> V_93 += V_12 ;
return 0 ;
}
V_157 = 0 ;
F_26 ( & V_154 ) ;
V_13 = - V_14 ;
V_42:
F_2 ( & V_126 ) ;
for ( V_101 = 0 ; V_101 < V_156 ; V_101 ++ ) {
V_74 = F_167 ( V_8 , V_150 ) ;
if ( ! V_74 ) {
V_158 = false ;
break;
}
F_22 ( & V_74 -> V_76 , & V_154 ) ;
}
V_157 += V_101 ;
F_9 ( & V_126 ) ;
V_156 = ( V_8 -> V_93 + V_12 ) -
( V_8 -> V_78 + V_157 ) ;
if ( V_156 > 0 ) {
if ( V_158 )
goto V_42;
goto free;
}
V_156 += V_157 ;
V_8 -> V_93 += V_12 ;
V_13 = 0 ;
F_23 (page, tmp, &surplus_list, lru) {
if ( ( -- V_156 ) < 0 )
break;
F_171 ( V_74 ) ;
F_115 ( F_97 ( V_74 ) , V_74 ) ;
F_56 ( V_8 , V_74 ) ;
}
free:
F_2 ( & V_126 ) ;
F_23 (page, tmp, &surplus_list, lru)
F_138 ( V_74 ) ;
F_9 ( & V_126 ) ;
return V_13 ;
}
static void F_172 ( struct V_7 * V_8 ,
unsigned long V_159 )
{
unsigned long V_102 ;
if ( F_113 ( V_8 ) )
goto V_45;
V_102 = F_33 ( V_159 , V_8 -> V_128 ) ;
while ( V_102 -- ) {
V_8 -> V_93 -- ;
V_159 -- ;
if ( ! F_153 ( V_8 , & V_160 [ V_161 ] , 1 ) )
goto V_45;
F_173 ( & V_126 ) ;
}
V_45:
V_8 -> V_93 -= V_159 ;
}
static long F_174 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_147 ,
enum V_162 V_163 )
{
struct V_21 * V_22 ;
T_1 V_164 ;
long V_13 ;
V_22 = F_49 ( V_19 ) ;
if ( ! V_22 )
return 1 ;
V_164 = F_34 ( V_8 , V_19 , V_147 ) ;
switch ( V_163 ) {
case V_165 :
V_13 = F_24 ( V_22 , V_164 , V_164 + 1 ) ;
break;
case V_166 :
V_13 = F_17 ( V_22 , V_164 , V_164 + 1 ) ;
break;
case V_167 :
F_27 ( V_22 , V_164 , V_164 + 1 ) ;
V_13 = 0 ;
break;
case V_168 :
if ( V_19 -> V_62 & V_63 )
V_13 = F_17 ( V_22 , V_164 , V_164 + 1 ) ;
else {
F_27 ( V_22 , V_164 , V_164 + 1 ) ;
V_13 = F_28 ( V_22 , V_164 , V_164 + 1 ) ;
}
break;
default:
F_175 () ;
}
if ( V_19 -> V_62 & V_63 )
return V_13 ;
else if ( F_53 ( V_19 , V_73 ) && V_13 >= 0 ) {
if ( V_13 )
return 0 ;
else
return 1 ;
}
else
return V_13 < 0 ? V_13 : 0 ;
}
static long F_176 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_147 )
{
return F_174 ( V_8 , V_19 , V_147 , V_165 ) ;
}
static long F_177 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_147 )
{
return F_174 ( V_8 , V_19 , V_147 , V_166 ) ;
}
static void F_178 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_147 )
{
( void ) F_174 ( V_8 , V_19 , V_147 , V_167 ) ;
}
static long F_179 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_147 )
{
return F_174 ( V_8 , V_19 , V_147 , V_168 ) ;
}
static void F_180 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_50 ,
struct V_74 * V_74 )
{
if ( F_72 ( F_124 ( V_74 ) ) ) {
long V_143 = F_176 ( V_8 , V_19 , V_50 ) ;
if ( F_72 ( V_143 < 0 ) ) {
F_128 ( V_74 ) ;
} else if ( V_143 ) {
V_143 = F_179 ( V_8 , V_19 , V_50 ) ;
if ( F_72 ( V_143 < 0 ) )
F_128 ( V_74 ) ;
} else
F_178 ( V_8 , V_19 , V_50 ) ;
}
}
struct V_74 * F_181 ( struct V_18 * V_19 ,
unsigned long V_147 , int V_84 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_74 * V_74 ;
long V_169 , V_170 ;
long V_171 ;
int V_13 , V_164 ;
struct V_172 * V_173 ;
V_164 = F_135 ( V_8 ) ;
V_169 = V_171 = F_176 ( V_8 , V_19 , V_147 ) ;
if ( V_169 < 0 )
return F_182 ( - V_14 ) ;
if ( V_169 || V_84 ) {
V_171 = F_11 ( V_2 , 1 ) ;
if ( V_171 < 0 ) {
F_178 ( V_8 , V_19 , V_147 ) ;
return F_182 ( - V_174 ) ;
}
if ( V_84 )
V_171 = 1 ;
}
V_13 = F_183 ( V_164 , F_114 ( V_8 ) , & V_173 ) ;
if ( V_13 )
goto V_175;
F_9 ( & V_126 ) ;
V_74 = F_64 ( V_8 , V_19 , V_147 , V_84 , V_171 ) ;
if ( ! V_74 ) {
F_2 ( & V_126 ) ;
V_74 = F_168 ( V_8 , V_19 , V_147 ) ;
if ( ! V_74 )
goto V_176;
if ( ! V_84 && F_55 ( V_19 , V_171 ) ) {
F_70 ( V_74 ) ;
V_8 -> V_93 -- ;
}
F_9 ( & V_126 ) ;
F_58 ( & V_74 -> V_76 , & V_8 -> V_80 ) ;
}
F_184 ( V_164 , F_114 ( V_8 ) , V_173 , V_74 ) ;
F_2 ( & V_126 ) ;
F_132 ( V_74 , ( unsigned long ) V_2 ) ;
V_170 = F_177 ( V_8 , V_19 , V_147 ) ;
if ( F_72 ( V_169 > V_170 ) ) {
long V_47 ;
V_47 = F_12 ( V_2 , 1 ) ;
F_3 ( V_8 , - V_47 ) ;
}
return V_74 ;
V_176:
F_185 ( V_164 , F_114 ( V_8 ) , V_173 ) ;
V_175:
if ( V_169 || V_84 )
F_12 ( V_2 , 1 ) ;
F_178 ( V_8 , V_19 , V_147 ) ;
return F_182 ( - V_174 ) ;
}
struct V_74 * F_186 ( struct V_18 * V_19 ,
unsigned long V_147 , int V_84 )
{
struct V_74 * V_74 = F_181 ( V_19 , V_147 , V_84 ) ;
if ( F_187 ( V_74 ) )
V_74 = NULL ;
return V_74 ;
}
int __weak F_188 ( struct V_7 * V_8 )
{
struct V_177 * V_178 ;
int V_112 , V_113 ;
F_110 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_147 ;
V_147 = F_189 (
F_121 ( V_8 ) , F_121 ( V_8 ) ,
0 , V_179 , V_113 ) ;
if ( V_147 ) {
V_178 = V_147 ;
goto V_180;
}
}
return 0 ;
V_180:
F_10 ( ! F_190 ( F_191 ( V_178 ) , F_121 ( V_8 ) ) ) ;
F_22 ( & V_178 -> V_181 , & V_182 ) ;
V_178 -> V_7 = V_8 ;
return 1 ;
}
static void T_4 F_192 ( struct V_74 * V_74 ,
unsigned int V_100 )
{
if ( F_72 ( V_100 > ( V_134 - 1 ) ) )
F_107 ( V_74 , V_100 ) ;
else
F_193 ( V_74 , V_100 ) ;
}
static void T_4 F_194 ( void )
{
struct V_177 * V_178 ;
F_18 (m, &huge_boot_pages, list) {
struct V_7 * V_8 = V_178 -> V_7 ;
struct V_74 * V_74 ;
#ifdef F_195
V_74 = F_94 ( V_178 -> V_183 >> V_184 ) ;
F_196 ( F_197 ( V_178 ) ,
sizeof( struct V_177 ) ) ;
#else
V_74 = F_198 ( V_178 ) ;
#endif
F_199 ( F_97 ( V_74 ) != 1 ) ;
F_192 ( V_74 , V_8 -> V_100 ) ;
F_199 ( F_96 ( V_74 ) ) ;
F_108 ( V_8 , V_74 , F_57 ( V_74 ) ) ;
if ( F_113 ( V_8 ) )
F_200 ( V_74 , 1 << V_8 -> V_100 ) ;
}
}
static void T_4 F_201 ( struct V_7 * V_8 )
{
unsigned long V_101 ;
for ( V_101 = 0 ; V_101 < V_8 -> V_145 ; ++ V_101 ) {
if ( F_113 ( V_8 ) ) {
if ( ! F_188 ( V_8 ) )
break;
} else if ( ! F_151 ( V_8 ,
& V_160 [ V_161 ] ) )
break;
}
V_8 -> V_145 = V_101 ;
}
static void T_4 F_202 ( void )
{
struct V_7 * V_8 ;
F_120 (h) {
if ( V_146 > F_36 ( V_8 ) )
V_146 = F_36 ( V_8 ) ;
if ( ! F_113 ( V_8 ) )
F_201 ( V_8 ) ;
}
F_19 ( V_146 == V_185 ) ;
}
static char * T_4 F_203 ( char * V_186 , unsigned long V_187 )
{
if ( V_187 >= ( 1UL << 30 ) )
sprintf ( V_186 , L_1 , V_187 >> 30 ) ;
else if ( V_187 >= ( 1UL << 20 ) )
sprintf ( V_186 , L_2 , V_187 >> 20 ) ;
else
sprintf ( V_186 , L_3 , V_187 >> 10 ) ;
return V_186 ;
}
static void T_4 F_204 ( void )
{
struct V_7 * V_8 ;
F_120 (h) {
char V_186 [ 32 ] ;
F_205 ( L_4 ,
F_203 ( V_186 , F_121 ( V_8 ) ) ,
V_8 -> V_78 ) ;
}
}
static void F_206 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_96 )
{
int V_101 ;
if ( F_113 ( V_8 ) )
return;
F_207 (i, *nodes_allowed) {
struct V_74 * V_74 , * V_142 ;
struct V_25 * V_188 = & V_8 -> V_77 [ V_101 ] ;
F_23 (page, next, freel, lru) {
if ( V_3 >= V_8 -> V_114 )
return;
if ( F_208 ( V_74 ) )
continue;
F_21 ( & V_74 -> V_76 ) ;
F_112 ( V_8 , V_74 ) ;
V_8 -> V_78 -- ;
V_8 -> V_79 [ F_57 ( V_74 ) ] -- ;
}
}
}
static inline void F_206 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_96 )
{
}
static int F_209 ( struct V_7 * V_8 , T_3 * V_96 ,
int V_12 )
{
int V_112 , V_113 ;
F_19 ( V_12 != - 1 && V_12 != 1 ) ;
if ( V_12 < 0 ) {
F_110 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_127 [ V_113 ] )
goto V_180;
}
} else {
F_154 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_127 [ V_113 ] <
V_8 -> V_115 [ V_113 ] )
goto V_180;
}
}
return 0 ;
V_180:
V_8 -> V_128 += V_12 ;
V_8 -> V_127 [ V_113 ] += V_12 ;
return 1 ;
}
static unsigned long F_210 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_96 )
{
unsigned long V_189 , V_13 ;
if ( F_113 ( V_8 ) && ! F_111 () )
return V_8 -> V_145 ;
F_9 ( & V_126 ) ;
while ( V_8 -> V_128 && V_3 > F_211 ( V_8 ) ) {
if ( ! F_209 ( V_8 , V_96 , - 1 ) )
break;
}
while ( V_3 > F_211 ( V_8 ) ) {
F_2 ( & V_126 ) ;
F_212 () ;
if ( F_113 ( V_8 ) )
V_13 = F_109 ( V_8 , V_96 ) ;
else
V_13 = F_151 ( V_8 , V_96 ) ;
F_9 ( & V_126 ) ;
if ( ! V_13 )
goto V_45;
if ( F_213 ( V_190 ) )
goto V_45;
}
V_189 = V_8 -> V_93 + V_8 -> V_114 - V_8 -> V_78 ;
V_189 = F_32 ( V_3 , V_189 ) ;
F_206 ( V_8 , V_189 , V_96 ) ;
while ( V_189 < F_211 ( V_8 ) ) {
if ( ! F_153 ( V_8 , V_96 , 0 ) )
break;
F_173 ( & V_126 ) ;
}
while ( V_3 < F_211 ( V_8 ) ) {
if ( ! F_209 ( V_8 , V_96 , 1 ) )
break;
}
V_45:
V_13 = F_211 ( V_8 ) ;
F_2 ( & V_126 ) ;
return V_13 ;
}
static struct V_7 * F_214 ( struct V_191 * V_192 , int * V_193 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < V_194 ; V_101 ++ )
if ( V_195 [ V_101 ] == V_192 ) {
if ( V_193 )
* V_193 = V_150 ;
return & V_196 [ V_101 ] ;
}
return F_215 ( V_192 , V_193 ) ;
}
static T_5 F_216 ( struct V_191 * V_192 ,
struct V_197 * V_198 , char * V_186 )
{
struct V_7 * V_8 ;
unsigned long V_114 ;
int V_75 ;
V_8 = F_214 ( V_192 , & V_75 ) ;
if ( V_75 == V_150 )
V_114 = V_8 -> V_114 ;
else
V_114 = V_8 -> V_115 [ V_75 ] ;
return sprintf ( V_186 , L_5 , V_114 ) ;
}
static T_5 F_217 ( bool V_199 ,
struct V_7 * V_8 , int V_75 ,
unsigned long V_3 , T_6 V_200 )
{
int V_94 ;
F_218 ( T_3 , V_96 , V_10 | V_201 ) ;
if ( F_113 ( V_8 ) && ! F_111 () ) {
V_94 = - V_202 ;
goto V_45;
}
if ( V_75 == V_150 ) {
if ( ! ( V_199 &&
F_219 ( V_96 ) ) ) {
F_220 ( V_96 ) ;
V_96 = & V_160 [ V_161 ] ;
}
} else if ( V_96 ) {
V_3 += V_8 -> V_114 - V_8 -> V_115 [ V_75 ] ;
F_221 ( V_96 , V_75 ) ;
} else
V_96 = & V_160 [ V_161 ] ;
V_8 -> V_145 = F_210 ( V_8 , V_3 , V_96 ) ;
if ( V_96 != & V_160 [ V_161 ] )
F_220 ( V_96 ) ;
return V_200 ;
V_45:
F_220 ( V_96 ) ;
return V_94 ;
}
static T_5 F_222 ( bool V_199 ,
struct V_191 * V_192 , const char * V_186 ,
T_6 V_200 )
{
struct V_7 * V_8 ;
unsigned long V_3 ;
int V_75 ;
int V_94 ;
V_94 = F_223 ( V_186 , 10 , & V_3 ) ;
if ( V_94 )
return V_94 ;
V_8 = F_214 ( V_192 , & V_75 ) ;
return F_217 ( V_199 , V_8 , V_75 , V_3 , V_200 ) ;
}
static T_5 F_224 ( struct V_191 * V_192 ,
struct V_197 * V_198 , char * V_186 )
{
return F_216 ( V_192 , V_198 , V_186 ) ;
}
static T_5 F_225 ( struct V_191 * V_192 ,
struct V_197 * V_198 , const char * V_186 , T_6 V_200 )
{
return F_222 ( false , V_192 , V_186 , V_200 ) ;
}
static T_5 F_226 ( struct V_191 * V_192 ,
struct V_197 * V_198 , char * V_186 )
{
return F_216 ( V_192 , V_198 , V_186 ) ;
}
static T_5 F_227 ( struct V_191 * V_192 ,
struct V_197 * V_198 , const char * V_186 , T_6 V_200 )
{
return F_222 ( true , V_192 , V_186 , V_200 ) ;
}
static T_5 F_228 ( struct V_191 * V_192 ,
struct V_197 * V_198 , char * V_186 )
{
struct V_7 * V_8 = F_214 ( V_192 , NULL ) ;
return sprintf ( V_186 , L_5 , V_8 -> V_153 ) ;
}
static T_5 F_229 ( struct V_191 * V_192 ,
struct V_197 * V_198 , const char * V_186 , T_6 V_3 )
{
int V_94 ;
unsigned long V_203 ;
struct V_7 * V_8 = F_214 ( V_192 , NULL ) ;
if ( F_113 ( V_8 ) )
return - V_202 ;
V_94 = F_223 ( V_186 , 10 , & V_203 ) ;
if ( V_94 )
return V_94 ;
F_9 ( & V_126 ) ;
V_8 -> V_153 = V_203 ;
F_2 ( & V_126 ) ;
return V_3 ;
}
static T_5 F_230 ( struct V_191 * V_192 ,
struct V_197 * V_198 , char * V_186 )
{
struct V_7 * V_8 ;
unsigned long V_78 ;
int V_75 ;
V_8 = F_214 ( V_192 , & V_75 ) ;
if ( V_75 == V_150 )
V_78 = V_8 -> V_78 ;
else
V_78 = V_8 -> V_79 [ V_75 ] ;
return sprintf ( V_186 , L_5 , V_78 ) ;
}
static T_5 F_231 ( struct V_191 * V_192 ,
struct V_197 * V_198 , char * V_186 )
{
struct V_7 * V_8 = F_214 ( V_192 , NULL ) ;
return sprintf ( V_186 , L_5 , V_8 -> V_93 ) ;
}
static T_5 F_232 ( struct V_191 * V_192 ,
struct V_197 * V_198 , char * V_186 )
{
struct V_7 * V_8 ;
unsigned long V_128 ;
int V_75 ;
V_8 = F_214 ( V_192 , & V_75 ) ;
if ( V_75 == V_150 )
V_128 = V_8 -> V_128 ;
else
V_128 = V_8 -> V_127 [ V_75 ] ;
return sprintf ( V_186 , L_5 , V_128 ) ;
}
static int F_233 ( struct V_7 * V_8 , struct V_191 * V_204 ,
struct V_191 * * V_195 ,
struct V_205 * V_206 )
{
int V_207 ;
int V_208 = F_135 ( V_8 ) ;
V_195 [ V_208 ] = F_234 ( V_8 -> V_209 , V_204 ) ;
if ( ! V_195 [ V_208 ] )
return - V_14 ;
V_207 = F_235 ( V_195 [ V_208 ] , V_206 ) ;
if ( V_207 )
F_236 ( V_195 [ V_208 ] ) ;
return V_207 ;
}
static void T_4 F_237 ( void )
{
struct V_7 * V_8 ;
int V_94 ;
V_210 = F_234 ( L_6 , V_211 ) ;
if ( ! V_210 )
return;
F_120 (h) {
V_94 = F_233 ( V_8 , V_210 ,
V_195 , & V_206 ) ;
if ( V_94 )
F_238 ( L_7 , V_8 -> V_209 ) ;
}
}
static struct V_7 * F_215 ( struct V_191 * V_192 , int * V_193 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_212 ; V_75 ++ ) {
struct V_213 * V_214 = & V_215 [ V_75 ] ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_194 ; V_101 ++ )
if ( V_214 -> V_195 [ V_101 ] == V_192 ) {
if ( V_193 )
* V_193 = V_75 ;
return & V_196 [ V_101 ] ;
}
}
F_175 () ;
return NULL ;
}
static void F_239 ( struct V_113 * V_113 )
{
struct V_7 * V_8 ;
struct V_213 * V_214 = & V_215 [ V_113 -> V_216 . V_217 ] ;
if ( ! V_214 -> V_210 )
return;
F_120 (h) {
int V_164 = F_135 ( V_8 ) ;
if ( V_214 -> V_195 [ V_164 ] ) {
F_236 ( V_214 -> V_195 [ V_164 ] ) ;
V_214 -> V_195 [ V_164 ] = NULL ;
}
}
F_236 ( V_214 -> V_210 ) ;
V_214 -> V_210 = NULL ;
}
static void F_240 ( struct V_113 * V_113 )
{
struct V_7 * V_8 ;
struct V_213 * V_214 = & V_215 [ V_113 -> V_216 . V_217 ] ;
int V_94 ;
if ( V_214 -> V_210 )
return;
V_214 -> V_210 = F_234 ( L_6 ,
& V_113 -> V_216 . V_192 ) ;
if ( ! V_214 -> V_210 )
return;
F_120 (h) {
V_94 = F_233 ( V_8 , V_214 -> V_210 ,
V_214 -> V_195 ,
& V_218 ) ;
if ( V_94 ) {
F_238 ( L_8 ,
V_8 -> V_209 , V_113 -> V_216 . V_217 ) ;
F_239 ( V_113 ) ;
break;
}
}
}
static void T_4 F_241 ( void )
{
int V_75 ;
F_242 (nid, N_MEMORY) {
struct V_113 * V_113 = V_219 [ V_75 ] ;
if ( V_113 -> V_216 . V_217 == V_75 )
F_240 ( V_113 ) ;
}
F_243 ( F_240 ,
F_239 ) ;
}
static struct V_7 * F_215 ( struct V_191 * V_192 , int * V_193 )
{
F_175 () ;
if ( V_193 )
* V_193 = - 1 ;
return NULL ;
}
static void F_241 ( void ) { }
static int T_4 F_244 ( void )
{
int V_101 ;
if ( ! F_159 () )
return 0 ;
if ( ! F_119 ( V_220 ) ) {
V_220 = V_221 ;
if ( ! F_119 ( V_220 ) )
F_245 ( V_222 ) ;
}
V_223 = F_135 ( F_119 ( V_220 ) ) ;
if ( V_224 ) {
if ( ! V_225 . V_145 )
V_225 . V_145 = V_224 ;
}
F_202 () ;
F_194 () ;
F_204 () ;
F_237 () ;
F_241 () ;
F_246 () ;
#ifdef F_247
V_226 = F_248 ( 8 * F_249 () ) ;
#else
V_226 = 1 ;
#endif
V_227 =
F_25 ( sizeof( struct V_228 ) * V_226 , V_10 ) ;
F_10 ( ! V_227 ) ;
for ( V_101 = 0 ; V_101 < V_226 ; V_101 ++ )
F_250 ( & V_227 [ V_101 ] ) ;
return 0 ;
}
void T_4 F_251 ( void )
{
V_229 = false ;
}
void T_4 F_245 ( unsigned int V_100 )
{
struct V_7 * V_8 ;
unsigned long V_101 ;
if ( F_119 ( V_53 << V_100 ) ) {
F_252 ( L_9 ) ;
return;
}
F_10 ( V_230 >= V_194 ) ;
F_10 ( V_100 == 0 ) ;
V_8 = & V_196 [ V_230 ++ ] ;
V_8 -> V_100 = V_100 ;
V_8 -> V_231 = ~ ( ( 1ULL << ( V_100 + V_184 ) ) - 1 ) ;
V_8 -> V_114 = 0 ;
V_8 -> V_78 = 0 ;
for ( V_101 = 0 ; V_101 < V_97 ; ++ V_101 )
F_26 ( & V_8 -> V_77 [ V_101 ] ) ;
F_26 ( & V_8 -> V_80 ) ;
V_8 -> V_98 = V_232 ;
V_8 -> V_99 = V_232 ;
snprintf ( V_8 -> V_209 , V_233 , L_10 ,
F_121 ( V_8 ) / 1024 ) ;
V_234 = V_8 ;
}
static int T_4 F_253 ( char * V_235 )
{
unsigned long * V_236 ;
static unsigned long * V_237 ;
if ( ! V_229 ) {
F_252 ( L_11
L_12 , V_235 ) ;
V_229 = true ;
return 1 ;
}
else if ( ! V_230 )
V_236 = & V_224 ;
else
V_236 = & V_234 -> V_145 ;
if ( V_236 == V_237 ) {
F_252 ( L_13 ) ;
return 1 ;
}
if ( sscanf ( V_235 , L_14 , V_236 ) <= 0 )
* V_236 = 0 ;
if ( V_230 && V_234 -> V_100 >= V_134 )
F_201 ( V_234 ) ;
V_237 = V_236 ;
return 1 ;
}
static int T_4 F_254 ( char * V_235 )
{
V_220 = F_255 ( V_235 , & V_235 ) ;
return 1 ;
}
static unsigned int F_256 ( unsigned int * V_238 )
{
int V_113 ;
unsigned int V_239 = 0 ;
F_207 (node, cpuset_current_mems_allowed)
V_239 += V_238 [ V_113 ] ;
return V_239 ;
}
static int F_257 ( bool V_199 ,
struct V_240 * V_241 , int V_242 ,
void T_7 * V_243 , T_6 * V_244 , T_8 * V_245 )
{
struct V_7 * V_8 = & V_225 ;
unsigned long V_155 = V_8 -> V_145 ;
int V_13 ;
if ( ! F_159 () )
return - V_246 ;
V_241 -> V_247 = & V_155 ;
V_241 -> V_248 = sizeof( unsigned long ) ;
V_13 = F_258 ( V_241 , V_242 , V_243 , V_244 , V_245 ) ;
if ( V_13 )
goto V_45;
if ( V_242 )
V_13 = F_217 ( V_199 , V_8 ,
V_150 , V_155 , * V_244 ) ;
V_45:
return V_13 ;
}
int F_259 ( struct V_240 * V_241 , int V_242 ,
void T_7 * V_243 , T_6 * V_244 , T_8 * V_245 )
{
return F_257 ( false , V_241 , V_242 ,
V_243 , V_244 , V_245 ) ;
}
int F_260 ( struct V_240 * V_241 , int V_242 ,
void T_7 * V_243 , T_6 * V_244 , T_8 * V_245 )
{
return F_257 ( true , V_241 , V_242 ,
V_243 , V_244 , V_245 ) ;
}
int F_261 ( struct V_240 * V_241 , int V_242 ,
void T_7 * V_243 ,
T_6 * V_244 , T_8 * V_245 )
{
struct V_7 * V_8 = & V_225 ;
unsigned long V_155 ;
int V_13 ;
if ( ! F_159 () )
return - V_246 ;
V_155 = V_8 -> V_153 ;
if ( V_242 && F_113 ( V_8 ) )
return - V_202 ;
V_241 -> V_247 = & V_155 ;
V_241 -> V_248 = sizeof( unsigned long ) ;
V_13 = F_258 ( V_241 , V_242 , V_243 , V_244 , V_245 ) ;
if ( V_13 )
goto V_45;
if ( V_242 ) {
F_9 ( & V_126 ) ;
V_8 -> V_153 = V_155 ;
F_2 ( & V_126 ) ;
}
V_45:
return V_13 ;
}
void F_262 ( struct V_249 * V_178 )
{
struct V_7 * V_8 = & V_225 ;
if ( ! F_159 () )
return;
F_263 ( V_178 ,
L_15
L_16
L_17
L_18
L_19 ,
V_8 -> V_114 ,
V_8 -> V_78 ,
V_8 -> V_93 ,
V_8 -> V_128 ,
1UL << ( F_36 ( V_8 ) + V_184 - 10 ) ) ;
}
int F_264 ( int V_75 , char * V_186 )
{
struct V_7 * V_8 = & V_225 ;
if ( ! F_159 () )
return 0 ;
return sprintf ( V_186 ,
L_20
L_21
L_22 ,
V_75 , V_8 -> V_115 [ V_75 ] ,
V_75 , V_8 -> V_79 [ V_75 ] ,
V_75 , V_8 -> V_127 [ V_75 ] ) ;
}
void F_265 ( void )
{
struct V_7 * V_8 ;
int V_75 ;
if ( ! F_159 () )
return;
F_242 (nid, N_MEMORY)
F_120 (h)
F_205 ( L_23 ,
V_75 ,
V_8 -> V_115 [ V_75 ] ,
V_8 -> V_79 [ V_75 ] ,
V_8 -> V_127 [ V_75 ] ,
1UL << ( F_36 ( V_8 ) + V_184 - 10 ) ) ;
}
void F_266 ( struct V_249 * V_178 , struct V_250 * V_251 )
{
F_263 ( V_178 , L_24 ,
F_267 ( & V_251 -> V_252 ) << ( V_184 - 10 ) ) ;
}
unsigned long F_268 ( void )
{
struct V_7 * V_8 ;
unsigned long V_253 = 0 ;
F_120 (h)
V_253 += V_8 -> V_114 * F_114 ( V_8 ) ;
return V_253 ;
}
static int F_3 ( struct V_7 * V_8 , long V_12 )
{
int V_13 = - V_14 ;
F_9 ( & V_126 ) ;
if ( V_12 > 0 ) {
if ( F_170 ( V_8 , V_12 ) < 0 )
goto V_45;
if ( V_12 > F_256 ( V_8 -> V_79 ) ) {
F_172 ( V_8 , V_12 ) ;
goto V_45;
}
}
V_13 = 0 ;
if ( V_12 < 0 )
F_172 ( V_8 , ( unsigned long ) - V_12 ) ;
V_45:
F_2 ( & V_126 ) ;
return V_13 ;
}
static void F_269 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_49 ( V_19 ) ;
if ( V_22 && F_53 ( V_19 , V_73 ) )
F_270 ( & V_22 -> V_56 ) ;
}
static void F_271 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_21 * V_22 = F_49 ( V_19 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
unsigned long V_254 , V_255 , V_256 ;
long V_257 ;
if ( ! V_22 || ! F_53 ( V_19 , V_73 ) )
return;
V_255 = F_34 ( V_8 , V_19 , V_19 -> V_51 ) ;
V_256 = F_34 ( V_8 , V_19 , V_19 -> V_258 ) ;
V_254 = ( V_256 - V_255 ) - F_31 ( V_22 , V_255 , V_256 ) ;
F_272 ( & V_22 -> V_56 , F_46 ) ;
if ( V_254 ) {
V_257 = F_12 ( V_2 , V_254 ) ;
F_3 ( V_8 , - V_257 ) ;
}
}
static int F_273 ( struct V_259 * V_260 )
{
F_175 () ;
return 0 ;
}
static T_9 F_274 ( struct V_18 * V_19 , struct V_74 * V_74 ,
int V_261 )
{
T_9 V_262 ;
if ( V_261 ) {
V_262 = F_275 ( F_276 ( F_277 ( V_74 ,
V_19 -> V_263 ) ) ) ;
} else {
V_262 = F_278 ( F_277 ( V_74 ,
V_19 -> V_263 ) ) ;
}
V_262 = F_279 ( V_262 ) ;
V_262 = F_280 ( V_262 ) ;
V_262 = F_281 ( V_262 , V_19 , V_74 , V_261 ) ;
return V_262 ;
}
static void F_282 ( struct V_18 * V_19 ,
unsigned long V_50 , T_9 * V_264 )
{
T_9 V_262 ;
V_262 = F_275 ( F_276 ( F_283 ( V_264 ) ) ) ;
if ( F_284 ( V_19 , V_50 , V_264 , V_262 , 1 ) )
F_285 ( V_19 , V_50 , V_264 ) ;
}
static int F_286 ( T_9 V_265 )
{
T_10 V_266 ;
if ( F_287 ( V_265 ) || F_288 ( V_265 ) )
return 0 ;
V_266 = F_289 ( V_265 ) ;
if ( F_290 ( V_266 ) && F_291 ( V_266 ) )
return 1 ;
else
return 0 ;
}
static int F_292 ( T_9 V_265 )
{
T_10 V_266 ;
if ( F_287 ( V_265 ) || F_288 ( V_265 ) )
return 0 ;
V_266 = F_289 ( V_265 ) ;
if ( F_290 ( V_266 ) && F_293 ( V_266 ) )
return 1 ;
else
return 0 ;
}
int F_294 ( struct V_250 * V_267 , struct V_250 * V_268 ,
struct V_18 * V_19 )
{
T_9 * V_269 , * V_270 , V_262 ;
struct V_74 * V_271 ;
unsigned long V_147 ;
int V_272 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_273 = F_121 ( V_8 ) ;
unsigned long V_274 ;
unsigned long V_275 ;
int V_13 = 0 ;
V_272 = ( V_19 -> V_62 & ( V_276 | V_277 ) ) == V_277 ;
V_274 = V_19 -> V_51 ;
V_275 = V_19 -> V_258 ;
if ( V_272 )
F_295 ( V_268 , V_274 , V_275 ) ;
for ( V_147 = V_19 -> V_51 ; V_147 < V_19 -> V_258 ; V_147 += V_273 ) {
T_11 * V_278 , * V_279 ;
V_269 = F_296 ( V_268 , V_147 ) ;
if ( ! V_269 )
continue;
V_270 = F_297 ( V_267 , V_147 , V_273 ) ;
if ( ! V_270 ) {
V_13 = - V_14 ;
break;
}
if ( V_270 == V_269 )
continue;
V_279 = F_298 ( V_8 , V_267 , V_270 ) ;
V_278 = F_299 ( V_8 , V_268 , V_269 ) ;
F_300 ( V_278 , V_280 ) ;
V_262 = F_283 ( V_269 ) ;
if ( F_287 ( V_262 ) ) {
;
} else if ( F_72 ( F_286 ( V_262 ) ||
F_292 ( V_262 ) ) ) {
T_10 V_281 = F_289 ( V_262 ) ;
if ( F_301 ( V_281 ) && V_272 ) {
F_302 ( & V_281 ) ;
V_262 = F_303 ( V_281 ) ;
F_304 ( V_268 , V_147 , V_269 , V_262 ) ;
}
F_304 ( V_267 , V_147 , V_270 , V_262 ) ;
} else {
if ( V_272 ) {
F_305 ( V_268 , V_147 , V_269 ) ;
F_306 ( V_268 , V_274 ,
V_275 ) ;
}
V_262 = F_283 ( V_269 ) ;
V_271 = F_307 ( V_262 ) ;
F_308 ( V_271 ) ;
F_309 ( V_271 , true ) ;
F_304 ( V_267 , V_147 , V_270 , V_262 ) ;
F_310 ( F_114 ( V_8 ) , V_267 ) ;
}
F_2 ( V_278 ) ;
F_2 ( V_279 ) ;
}
if ( V_272 )
F_311 ( V_268 , V_274 , V_275 ) ;
return V_13 ;
}
void F_312 ( struct V_282 * V_283 , struct V_18 * V_19 ,
unsigned long V_255 , unsigned long V_256 ,
struct V_74 * V_284 )
{
struct V_250 * V_251 = V_19 -> V_285 ;
unsigned long V_50 ;
T_9 * V_264 ;
T_9 V_265 ;
T_11 * V_286 ;
struct V_74 * V_74 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_273 = F_121 ( V_8 ) ;
const unsigned long V_274 = V_255 ;
const unsigned long V_275 = V_256 ;
F_199 ( ! F_40 ( V_19 ) ) ;
F_10 ( V_255 & ~ F_313 ( V_8 ) ) ;
F_10 ( V_256 & ~ F_313 ( V_8 ) ) ;
F_314 ( V_283 , V_273 ) ;
F_315 ( V_283 , V_19 ) ;
F_295 ( V_251 , V_274 , V_275 ) ;
V_50 = V_255 ;
for (; V_50 < V_256 ; V_50 += V_273 ) {
V_264 = F_296 ( V_251 , V_50 ) ;
if ( ! V_264 )
continue;
V_286 = F_298 ( V_8 , V_251 , V_264 ) ;
if ( F_316 ( V_251 , & V_50 , V_264 ) ) {
F_2 ( V_286 ) ;
continue;
}
V_265 = F_283 ( V_264 ) ;
if ( F_287 ( V_265 ) ) {
F_2 ( V_286 ) ;
continue;
}
if ( F_72 ( ! F_288 ( V_265 ) ) ) {
F_317 ( V_251 , V_50 , V_264 ) ;
F_2 ( V_286 ) ;
continue;
}
V_74 = F_307 ( V_265 ) ;
if ( V_284 ) {
if ( V_74 != V_284 ) {
F_2 ( V_286 ) ;
continue;
}
F_52 ( V_19 , V_287 ) ;
}
V_265 = F_318 ( V_251 , V_50 , V_264 ) ;
F_319 ( V_8 , V_283 , V_264 , V_50 ) ;
if ( F_320 ( V_265 ) )
F_321 ( V_74 ) ;
F_322 ( F_114 ( V_8 ) , V_251 ) ;
F_323 ( V_74 , true ) ;
F_2 ( V_286 ) ;
F_324 ( V_283 , V_74 , F_121 ( V_8 ) ) ;
if ( V_284 )
break;
}
F_311 ( V_251 , V_274 , V_275 ) ;
F_325 ( V_283 , V_19 ) ;
}
void F_326 ( struct V_282 * V_283 ,
struct V_18 * V_19 , unsigned long V_255 ,
unsigned long V_256 , struct V_74 * V_284 )
{
F_312 ( V_283 , V_19 , V_255 , V_256 , V_284 ) ;
V_19 -> V_62 &= ~ V_63 ;
}
void F_327 ( struct V_18 * V_19 , unsigned long V_255 ,
unsigned long V_256 , struct V_74 * V_284 )
{
struct V_250 * V_251 ;
struct V_282 V_283 ;
V_251 = V_19 -> V_285 ;
F_328 ( & V_283 , V_251 , V_255 , V_256 ) ;
F_312 ( & V_283 , V_19 , V_255 , V_256 , V_284 ) ;
F_329 ( & V_283 , V_255 , V_256 ) ;
}
static void F_330 ( struct V_250 * V_251 , struct V_18 * V_19 ,
struct V_74 * V_74 , unsigned long V_50 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_18 * V_288 ;
struct V_64 * V_65 ;
T_1 V_289 ;
V_50 = V_50 & F_313 ( V_8 ) ;
V_289 = ( ( V_50 - V_19 -> V_51 ) >> V_184 ) +
V_19 -> V_52 ;
V_65 = V_19 -> V_20 -> V_66 ;
F_331 ( V_65 ) ;
F_332 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_288 == V_19 )
continue;
if ( V_288 -> V_62 & V_63 )
continue;
if ( ! F_53 ( V_288 , V_73 ) )
F_327 ( V_288 , V_50 ,
V_50 + F_121 ( V_8 ) , V_74 ) ;
}
F_333 ( V_65 ) ;
}
static int F_334 ( struct V_250 * V_251 , struct V_18 * V_19 ,
unsigned long V_50 , T_9 * V_264 ,
struct V_74 * V_290 , T_11 * V_286 )
{
T_9 V_265 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_74 * V_291 , * V_292 ;
int V_13 = 0 , V_293 = 0 ;
unsigned long V_274 ;
unsigned long V_275 ;
V_265 = F_283 ( V_264 ) ;
V_291 = F_307 ( V_265 ) ;
V_294:
if ( F_133 ( V_291 ) == 1 && F_335 ( V_291 ) ) {
F_336 ( V_291 , V_19 ) ;
F_282 ( V_19 , V_50 , V_264 ) ;
return 0 ;
}
if ( F_53 ( V_19 , V_73 ) &&
V_291 != V_290 )
V_293 = 1 ;
F_308 ( V_291 ) ;
F_2 ( V_286 ) ;
V_292 = F_181 ( V_19 , V_50 , V_293 ) ;
if ( F_187 ( V_292 ) ) {
if ( V_293 ) {
F_138 ( V_291 ) ;
F_10 ( F_287 ( V_265 ) ) ;
F_330 ( V_251 , V_19 , V_291 , V_50 ) ;
F_10 ( F_287 ( V_265 ) ) ;
F_9 ( V_286 ) ;
V_264 = F_296 ( V_251 , V_50 & F_313 ( V_8 ) ) ;
if ( F_337 ( V_264 &&
F_338 ( F_283 ( V_264 ) , V_265 ) ) )
goto V_294;
return 0 ;
}
V_13 = ( F_339 ( V_292 ) == - V_14 ) ?
V_295 : V_296 ;
goto V_297;
}
if ( F_72 ( F_340 ( V_19 ) ) ) {
V_13 = V_295 ;
goto V_298;
}
F_341 ( V_292 , V_291 , V_50 , V_19 ,
F_114 ( V_8 ) ) ;
F_342 ( V_292 ) ;
F_125 ( V_292 ) ;
V_274 = V_50 & F_313 ( V_8 ) ;
V_275 = V_274 + F_121 ( V_8 ) ;
F_295 ( V_251 , V_274 , V_275 ) ;
F_9 ( V_286 ) ;
V_264 = F_296 ( V_251 , V_50 & F_313 ( V_8 ) ) ;
if ( F_337 ( V_264 && F_338 ( F_283 ( V_264 ) , V_265 ) ) ) {
F_128 ( V_292 ) ;
F_343 ( V_19 , V_50 , V_264 ) ;
F_306 ( V_251 , V_274 , V_275 ) ;
F_304 ( V_251 , V_50 , V_264 ,
F_274 ( V_19 , V_292 , 1 ) ) ;
F_323 ( V_291 , true ) ;
F_344 ( V_292 , V_19 , V_50 ) ;
V_292 = V_291 ;
}
F_2 ( V_286 ) ;
F_311 ( V_251 , V_274 , V_275 ) ;
V_298:
F_180 ( V_8 , V_19 , V_50 , V_292 ) ;
F_138 ( V_292 ) ;
V_297:
F_138 ( V_291 ) ;
F_9 ( V_286 ) ;
return V_13 ;
}
static struct V_74 * F_345 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_50 )
{
struct V_64 * V_65 ;
T_1 V_164 ;
V_65 = V_19 -> V_20 -> V_66 ;
V_164 = F_34 ( V_8 , V_19 , V_50 ) ;
return F_346 ( V_65 , V_164 ) ;
}
static bool F_347 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_50 )
{
struct V_64 * V_65 ;
T_1 V_164 ;
struct V_74 * V_74 ;
V_65 = V_19 -> V_20 -> V_66 ;
V_164 = F_34 ( V_8 , V_19 , V_50 ) ;
V_74 = F_348 ( V_65 , V_164 ) ;
if ( V_74 )
F_138 ( V_74 ) ;
return V_74 != NULL ;
}
int F_349 ( struct V_74 * V_74 , struct V_64 * V_65 ,
T_1 V_164 )
{
struct V_16 * V_16 = V_65 -> V_67 ;
struct V_7 * V_8 = F_30 ( V_16 ) ;
int V_94 = F_350 ( V_74 , V_65 , V_164 , V_10 ) ;
if ( V_94 )
return V_94 ;
F_128 ( V_74 ) ;
F_9 ( & V_16 -> V_299 ) ;
V_16 -> V_300 += F_351 ( V_8 ) ;
F_2 ( & V_16 -> V_299 ) ;
return 0 ;
}
static int F_352 ( struct V_250 * V_251 , struct V_18 * V_19 ,
struct V_64 * V_65 , T_1 V_164 ,
unsigned long V_50 , T_9 * V_264 , unsigned int V_70 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
int V_13 = V_296 ;
int V_301 = 0 ;
unsigned long V_124 ;
struct V_74 * V_74 ;
T_9 V_302 ;
T_11 * V_286 ;
if ( F_53 ( V_19 , V_287 ) ) {
F_353 ( L_25 ,
V_190 -> V_303 ) ;
return V_13 ;
}
V_42:
V_74 = F_346 ( V_65 , V_164 ) ;
if ( ! V_74 ) {
V_124 = F_354 ( V_65 -> V_67 ) >> F_35 ( V_8 ) ;
if ( V_164 >= V_124 )
goto V_45;
if ( F_355 ( V_19 ) ) {
T_12 V_304 ;
struct V_259 V_260 = {
. V_19 = V_19 ,
. V_50 = V_50 ,
. V_70 = V_70 ,
} ;
V_304 = F_356 ( V_8 , V_251 , V_19 , V_65 ,
V_164 , V_50 ) ;
F_357 ( & V_227 [ V_304 ] ) ;
V_13 = F_358 ( & V_260 , V_305 ) ;
F_359 ( & V_227 [ V_304 ] ) ;
goto V_45;
}
V_74 = F_181 ( V_19 , V_50 , 0 ) ;
if ( F_187 ( V_74 ) ) {
V_13 = F_339 ( V_74 ) ;
if ( V_13 == - V_14 )
V_13 = V_295 ;
else
V_13 = V_296 ;
goto V_45;
}
F_360 ( V_74 , V_50 , F_114 ( V_8 ) ) ;
F_342 ( V_74 ) ;
F_125 ( V_74 ) ;
if ( V_19 -> V_62 & V_63 ) {
int V_94 = F_349 ( V_74 , V_65 , V_164 ) ;
if ( V_94 ) {
F_138 ( V_74 ) ;
if ( V_94 == - V_306 )
goto V_42;
goto V_45;
}
} else {
F_361 ( V_74 ) ;
if ( F_72 ( F_340 ( V_19 ) ) ) {
V_13 = V_295 ;
goto V_307;
}
V_301 = 1 ;
}
} else {
if ( F_72 ( F_362 ( V_74 ) ) ) {
V_13 = V_308 |
F_363 ( F_135 ( V_8 ) ) ;
goto V_307;
}
}
if ( ( V_70 & V_309 ) && ! ( V_19 -> V_62 & V_276 ) ) {
if ( F_176 ( V_8 , V_19 , V_50 ) < 0 ) {
V_13 = V_295 ;
goto V_307;
}
F_178 ( V_8 , V_19 , V_50 ) ;
}
V_286 = F_298 ( V_8 , V_251 , V_264 ) ;
V_124 = F_354 ( V_65 -> V_67 ) >> F_35 ( V_8 ) ;
if ( V_164 >= V_124 )
goto V_310;
V_13 = 0 ;
if ( ! F_287 ( F_283 ( V_264 ) ) )
goto V_310;
if ( V_301 ) {
F_128 ( V_74 ) ;
F_344 ( V_74 , V_19 , V_50 ) ;
} else
F_309 ( V_74 , true ) ;
V_302 = F_274 ( V_19 , V_74 , ( ( V_19 -> V_62 & V_311 )
&& ( V_19 -> V_62 & V_276 ) ) ) ;
F_304 ( V_251 , V_50 , V_264 , V_302 ) ;
F_310 ( F_114 ( V_8 ) , V_251 ) ;
if ( ( V_70 & V_309 ) && ! ( V_19 -> V_62 & V_276 ) ) {
V_13 = F_334 ( V_251 , V_19 , V_50 , V_264 , V_74 , V_286 ) ;
}
F_2 ( V_286 ) ;
F_364 ( V_74 ) ;
V_45:
return V_13 ;
V_310:
F_2 ( V_286 ) ;
V_307:
F_364 ( V_74 ) ;
F_180 ( V_8 , V_19 , V_50 , V_74 ) ;
F_138 ( V_74 ) ;
goto V_45;
}
T_12 F_356 ( struct V_7 * V_8 , struct V_250 * V_251 ,
struct V_18 * V_19 ,
struct V_64 * V_65 ,
T_1 V_164 , unsigned long V_50 )
{
unsigned long V_312 [ 2 ] ;
T_12 V_304 ;
if ( V_19 -> V_62 & V_276 ) {
V_312 [ 0 ] = ( unsigned long ) V_65 ;
V_312 [ 1 ] = V_164 ;
} else {
V_312 [ 0 ] = ( unsigned long ) V_251 ;
V_312 [ 1 ] = V_50 >> F_35 ( V_8 ) ;
}
V_304 = F_365 ( ( T_12 * ) & V_312 , sizeof( V_312 ) / sizeof( T_12 ) , 0 ) ;
return V_304 & ( V_226 - 1 ) ;
}
T_12 F_356 ( struct V_7 * V_8 , struct V_250 * V_251 ,
struct V_18 * V_19 ,
struct V_64 * V_65 ,
T_1 V_164 , unsigned long V_50 )
{
return 0 ;
}
int F_366 ( struct V_250 * V_251 , struct V_18 * V_19 ,
unsigned long V_50 , unsigned int V_70 )
{
T_9 * V_264 , V_262 ;
T_11 * V_286 ;
int V_13 ;
T_12 V_304 ;
T_1 V_164 ;
struct V_74 * V_74 = NULL ;
struct V_74 * V_290 = NULL ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_64 * V_65 ;
int V_313 = 0 ;
V_50 &= F_313 ( V_8 ) ;
V_264 = F_296 ( V_251 , V_50 ) ;
if ( V_264 ) {
V_262 = F_283 ( V_264 ) ;
if ( F_72 ( F_286 ( V_262 ) ) ) {
F_367 ( V_19 , V_251 , V_264 ) ;
return 0 ;
} else if ( F_72 ( F_292 ( V_262 ) ) )
return V_314 |
F_363 ( F_135 ( V_8 ) ) ;
} else {
V_264 = F_297 ( V_251 , V_50 , F_121 ( V_8 ) ) ;
if ( ! V_264 )
return V_295 ;
}
V_65 = V_19 -> V_20 -> V_66 ;
V_164 = F_34 ( V_8 , V_19 , V_50 ) ;
V_304 = F_356 ( V_8 , V_251 , V_19 , V_65 , V_164 , V_50 ) ;
F_359 ( & V_227 [ V_304 ] ) ;
V_262 = F_283 ( V_264 ) ;
if ( F_287 ( V_262 ) ) {
V_13 = F_352 ( V_251 , V_19 , V_65 , V_164 , V_50 , V_264 , V_70 ) ;
goto V_315;
}
V_13 = 0 ;
if ( ! F_288 ( V_262 ) )
goto V_315;
if ( ( V_70 & V_309 ) && ! F_368 ( V_262 ) ) {
if ( F_176 ( V_8 , V_19 , V_50 ) < 0 ) {
V_13 = V_295 ;
goto V_315;
}
F_178 ( V_8 , V_19 , V_50 ) ;
if ( ! ( V_19 -> V_62 & V_63 ) )
V_290 = F_345 ( V_8 ,
V_19 , V_50 ) ;
}
V_286 = F_298 ( V_8 , V_251 , V_264 ) ;
if ( F_72 ( ! F_338 ( V_262 , F_283 ( V_264 ) ) ) )
goto V_316;
V_74 = F_307 ( V_262 ) ;
if ( V_74 != V_290 )
if ( ! F_369 ( V_74 ) ) {
V_313 = 1 ;
goto V_316;
}
F_308 ( V_74 ) ;
if ( V_70 & V_309 ) {
if ( ! F_368 ( V_262 ) ) {
V_13 = F_334 ( V_251 , V_19 , V_50 , V_264 ,
V_290 , V_286 ) ;
goto V_317;
}
V_262 = F_276 ( V_262 ) ;
}
V_262 = F_279 ( V_262 ) ;
if ( F_284 ( V_19 , V_50 , V_264 , V_262 ,
V_70 & V_309 ) )
F_285 ( V_19 , V_50 , V_264 ) ;
V_317:
if ( V_74 != V_290 )
F_364 ( V_74 ) ;
F_138 ( V_74 ) ;
V_316:
F_2 ( V_286 ) ;
if ( V_290 ) {
F_364 ( V_290 ) ;
F_138 ( V_290 ) ;
}
V_315:
F_357 ( & V_227 [ V_304 ] ) ;
if ( V_313 )
F_370 ( V_74 ) ;
return V_13 ;
}
int F_371 ( struct V_250 * V_318 ,
T_9 * V_270 ,
struct V_18 * V_319 ,
unsigned long V_320 ,
unsigned long V_321 ,
struct V_74 * * V_322 )
{
int V_323 = V_319 -> V_62 & V_276 ;
struct V_7 * V_8 = F_38 ( V_319 ) ;
T_9 V_324 ;
T_11 * V_286 ;
int V_13 ;
struct V_74 * V_74 ;
if ( ! * V_322 ) {
V_13 = - V_14 ;
V_74 = F_181 ( V_319 , V_320 , 0 ) ;
if ( F_187 ( V_74 ) )
goto V_45;
V_13 = F_372 ( V_74 ,
( const void T_7 * ) V_321 ,
F_114 ( V_8 ) , false ) ;
if ( F_72 ( V_13 ) ) {
V_13 = - V_325 ;
* V_322 = V_74 ;
goto V_45;
}
} else {
V_74 = * V_322 ;
* V_322 = NULL ;
}
F_342 ( V_74 ) ;
F_125 ( V_74 ) ;
if ( V_323 ) {
struct V_64 * V_65 = V_319 -> V_20 -> V_66 ;
T_1 V_164 = F_34 ( V_8 , V_319 , V_320 ) ;
V_13 = F_349 ( V_74 , V_65 , V_164 ) ;
if ( V_13 )
goto V_326;
}
V_286 = F_299 ( V_8 , V_318 , V_270 ) ;
F_9 ( V_286 ) ;
V_13 = - V_306 ;
if ( ! F_287 ( F_283 ( V_270 ) ) )
goto V_327;
if ( V_323 ) {
F_309 ( V_74 , true ) ;
} else {
F_128 ( V_74 ) ;
F_344 ( V_74 , V_319 , V_320 ) ;
}
V_324 = F_274 ( V_319 , V_74 , V_319 -> V_62 & V_311 ) ;
if ( V_319 -> V_62 & V_311 )
V_324 = F_276 ( V_324 ) ;
V_324 = F_279 ( V_324 ) ;
F_304 ( V_318 , V_320 , V_270 , V_324 ) ;
( void ) F_284 ( V_319 , V_320 , V_270 , V_324 ,
V_319 -> V_62 & V_311 ) ;
F_310 ( F_114 ( V_8 ) , V_318 ) ;
F_285 ( V_319 , V_320 , V_270 ) ;
F_2 ( V_286 ) ;
if ( V_323 )
F_364 ( V_74 ) ;
V_13 = 0 ;
V_45:
return V_13 ;
V_327:
F_2 ( V_286 ) ;
V_326:
if ( V_323 )
F_364 ( V_74 ) ;
F_138 ( V_74 ) ;
goto V_45;
}
long F_373 ( struct V_250 * V_251 , struct V_18 * V_19 ,
struct V_74 * * V_328 , struct V_18 * * V_329 ,
unsigned long * V_330 , unsigned long * V_102 ,
long V_101 , unsigned int V_70 , int * V_331 )
{
unsigned long V_332 ;
unsigned long V_333 = * V_330 ;
unsigned long V_334 = * V_102 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
while ( V_333 < V_19 -> V_258 && V_334 ) {
T_9 * V_265 ;
T_11 * V_286 = NULL ;
int V_335 ;
struct V_74 * V_74 ;
if ( F_72 ( F_374 ( V_190 ) ) ) {
V_334 = 0 ;
break;
}
V_265 = F_296 ( V_251 , V_333 & F_313 ( V_8 ) ) ;
if ( V_265 )
V_286 = F_298 ( V_8 , V_251 , V_265 ) ;
V_335 = ! V_265 || F_287 ( F_283 ( V_265 ) ) ;
if ( V_335 && ( V_70 & V_336 ) &&
! F_347 ( V_8 , V_19 , V_333 ) ) {
if ( V_265 )
F_2 ( V_286 ) ;
V_334 = 0 ;
break;
}
if ( V_335 || F_375 ( F_283 ( V_265 ) ) ||
( ( V_70 & V_337 ) &&
! F_368 ( F_283 ( V_265 ) ) ) ) {
int V_13 ;
unsigned int V_338 = 0 ;
if ( V_265 )
F_2 ( V_286 ) ;
if ( V_70 & V_337 )
V_338 |= V_309 ;
if ( V_331 )
V_338 |= V_339 ;
if ( V_70 & V_340 )
V_338 |= V_339 |
V_341 ;
if ( V_70 & V_342 ) {
F_165 ( V_338 &
V_339 ) ;
V_338 |= V_343 ;
}
V_13 = F_366 ( V_251 , V_19 , V_333 , V_338 ) ;
if ( V_13 & V_344 ) {
int V_94 = F_376 ( V_13 , V_70 ) ;
if ( V_94 )
return V_94 ;
V_334 = 0 ;
break;
}
if ( V_13 & V_345 ) {
if ( V_331 )
* V_331 = 0 ;
* V_102 = 0 ;
return V_101 ;
}
continue;
}
V_332 = ( V_333 & ~ F_313 ( V_8 ) ) >> V_184 ;
V_74 = F_307 ( F_283 ( V_265 ) ) ;
V_346:
if ( V_328 ) {
V_328 [ V_101 ] = F_377 ( V_74 , V_332 ) ;
F_308 ( V_328 [ V_101 ] ) ;
}
if ( V_329 )
V_329 [ V_101 ] = V_19 ;
V_333 += V_53 ;
++ V_332 ;
-- V_334 ;
++ V_101 ;
if ( V_333 < V_19 -> V_258 && V_334 &&
V_332 < F_114 ( V_8 ) ) {
goto V_346;
}
F_2 ( V_286 ) ;
}
* V_102 = V_334 ;
* V_330 = V_333 ;
return V_101 ? V_101 : - V_325 ;
}
unsigned long F_378 ( struct V_18 * V_19 ,
unsigned long V_50 , unsigned long V_256 , T_13 V_347 )
{
struct V_250 * V_251 = V_19 -> V_285 ;
unsigned long V_255 = V_50 ;
T_9 * V_264 ;
T_9 V_265 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_328 = 0 ;
F_10 ( V_50 >= V_256 ) ;
F_379 ( V_19 , V_50 , V_256 ) ;
F_295 ( V_251 , V_255 , V_256 ) ;
F_331 ( V_19 -> V_20 -> V_66 ) ;
for (; V_50 < V_256 ; V_50 += F_121 ( V_8 ) ) {
T_11 * V_286 ;
V_264 = F_296 ( V_251 , V_50 ) ;
if ( ! V_264 )
continue;
V_286 = F_298 ( V_8 , V_251 , V_264 ) ;
if ( F_316 ( V_251 , & V_50 , V_264 ) ) {
V_328 ++ ;
F_2 ( V_286 ) ;
continue;
}
V_265 = F_283 ( V_264 ) ;
if ( F_72 ( F_292 ( V_265 ) ) ) {
F_2 ( V_286 ) ;
continue;
}
if ( F_72 ( F_286 ( V_265 ) ) ) {
T_10 V_262 = F_289 ( V_265 ) ;
if ( F_301 ( V_262 ) ) {
T_9 V_348 ;
F_302 ( & V_262 ) ;
V_348 = F_303 ( V_262 ) ;
F_304 ( V_251 , V_50 , V_264 , V_348 ) ;
V_328 ++ ;
}
F_2 ( V_286 ) ;
continue;
}
if ( ! F_287 ( V_265 ) ) {
V_265 = F_318 ( V_251 , V_50 , V_264 ) ;
V_265 = F_280 ( F_380 ( V_265 , V_347 ) ) ;
V_265 = F_281 ( V_265 , V_19 , NULL , 0 ) ;
F_304 ( V_251 , V_50 , V_264 , V_265 ) ;
V_328 ++ ;
}
F_2 ( V_286 ) ;
}
F_381 ( V_19 , V_255 , V_256 ) ;
F_306 ( V_251 , V_255 , V_256 ) ;
F_333 ( V_19 -> V_20 -> V_66 ) ;
F_311 ( V_251 , V_255 , V_256 ) ;
return V_328 << V_8 -> V_100 ;
}
int F_382 ( struct V_16 * V_16 ,
long V_35 , long V_33 ,
struct V_18 * V_19 ,
T_14 V_62 )
{
long V_13 , V_41 ;
struct V_7 * V_8 = F_30 ( V_16 ) ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
struct V_21 * V_21 ;
long V_257 ;
if ( V_62 & V_72 )
return 0 ;
if ( ! V_19 || V_19 -> V_62 & V_63 ) {
V_21 = F_48 ( V_16 ) ;
V_41 = F_24 ( V_21 , V_35 , V_33 ) ;
} else {
V_21 = F_44 () ;
if ( ! V_21 )
return - V_14 ;
V_41 = V_33 - V_35 ;
F_51 ( V_19 , V_21 ) ;
F_52 ( V_19 , V_73 ) ;
}
if ( V_41 < 0 ) {
V_13 = V_41 ;
goto V_349;
}
V_257 = F_11 ( V_2 , V_41 ) ;
if ( V_257 < 0 ) {
V_13 = - V_174 ;
goto V_349;
}
V_13 = F_3 ( V_8 , V_257 ) ;
if ( V_13 < 0 ) {
( void ) F_12 ( V_2 , V_41 ) ;
goto V_349;
}
if ( ! V_19 || V_19 -> V_62 & V_63 ) {
long V_32 = F_17 ( V_21 , V_35 , V_33 ) ;
if ( F_72 ( V_41 > V_32 ) ) {
long V_47 ;
V_47 = F_12 ( V_2 ,
V_41 - V_32 ) ;
F_3 ( V_8 , - V_47 ) ;
}
}
return 0 ;
V_349:
if ( ! V_19 || V_19 -> V_62 & V_63 )
if ( V_41 >= 0 )
F_27 ( V_21 , V_35 , V_33 ) ;
if ( V_19 && F_53 ( V_19 , V_73 ) )
F_272 ( & V_21 -> V_56 , F_46 ) ;
return V_13 ;
}
long F_383 ( struct V_16 * V_16 , long V_255 , long V_256 ,
long V_350 )
{
struct V_7 * V_8 = F_30 ( V_16 ) ;
struct V_21 * V_21 = F_48 ( V_16 ) ;
long V_41 = 0 ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
long V_257 ;
if ( V_21 ) {
V_41 = F_28 ( V_21 , V_255 , V_256 ) ;
if ( V_41 < 0 )
return V_41 ;
}
F_9 ( & V_16 -> V_299 ) ;
V_16 -> V_300 -= ( F_351 ( V_8 ) * V_350 ) ;
F_2 ( & V_16 -> V_299 ) ;
V_257 = F_12 ( V_2 , ( V_41 - V_350 ) ) ;
F_3 ( V_8 , - V_257 ) ;
return 0 ;
}
static unsigned long F_384 ( struct V_18 * V_351 ,
struct V_18 * V_19 ,
unsigned long V_147 , T_1 V_164 )
{
unsigned long V_352 = ( ( V_164 - V_351 -> V_52 ) << V_184 ) +
V_351 -> V_51 ;
unsigned long V_353 = V_352 & V_354 ;
unsigned long V_355 = V_353 + V_356 ;
unsigned long V_62 = V_19 -> V_62 & V_357 ;
unsigned long V_358 = V_351 -> V_62 & V_357 ;
if ( F_385 ( V_147 ) != F_385 ( V_352 ) ||
V_62 != V_358 ||
V_353 < V_351 -> V_51 || V_351 -> V_258 < V_355 )
return 0 ;
return V_352 ;
}
static bool F_386 ( struct V_18 * V_19 , unsigned long V_147 )
{
unsigned long V_359 = V_147 & V_354 ;
unsigned long V_256 = V_359 + V_356 ;
if ( V_19 -> V_62 & V_63 &&
V_19 -> V_51 <= V_359 && V_256 <= V_19 -> V_258 )
return true ;
return false ;
}
T_9 * F_387 ( struct V_250 * V_251 , unsigned long V_147 , T_15 * V_360 )
{
struct V_18 * V_19 = F_388 ( V_251 , V_147 ) ;
struct V_64 * V_65 = V_19 -> V_20 -> V_66 ;
T_1 V_164 = ( ( V_147 - V_19 -> V_51 ) >> V_184 ) +
V_19 -> V_52 ;
struct V_18 * V_351 ;
unsigned long V_352 ;
T_9 * V_361 = NULL ;
T_9 * V_265 ;
T_11 * V_286 ;
if ( ! F_386 ( V_19 , V_147 ) )
return ( T_9 * ) F_389 ( V_251 , V_360 , V_147 ) ;
F_331 ( V_65 ) ;
F_332 (svma, &mapping->i_mmap, idx, idx) {
if ( V_351 == V_19 )
continue;
V_352 = F_384 ( V_351 , V_19 , V_147 , V_164 ) ;
if ( V_352 ) {
V_361 = F_296 ( V_351 -> V_285 , V_352 ) ;
if ( V_361 ) {
F_308 ( F_198 ( V_361 ) ) ;
break;
}
}
}
if ( ! V_361 )
goto V_45;
V_286 = F_298 ( F_38 ( V_19 ) , V_251 , V_361 ) ;
if ( F_390 ( * V_360 ) ) {
F_391 ( V_251 , V_360 ,
( V_362 * ) ( ( unsigned long ) V_361 & V_363 ) ) ;
F_392 ( V_251 ) ;
} else {
F_138 ( F_198 ( V_361 ) ) ;
}
F_2 ( V_286 ) ;
V_45:
V_265 = ( T_9 * ) F_389 ( V_251 , V_360 , V_147 ) ;
F_333 ( V_65 ) ;
return V_265 ;
}
int F_316 ( struct V_250 * V_251 , unsigned long * V_147 , T_9 * V_264 )
{
T_16 * V_364 = F_393 ( V_251 , * V_147 ) ;
T_17 * V_365 = F_394 ( V_364 , * V_147 ) ;
T_15 * V_360 = F_395 ( V_365 , * V_147 ) ;
F_10 ( F_97 ( F_198 ( V_264 ) ) == 0 ) ;
if ( F_97 ( F_198 ( V_264 ) ) == 1 )
return 0 ;
F_396 ( V_360 ) ;
F_138 ( F_198 ( V_264 ) ) ;
F_397 ( V_251 ) ;
* V_147 = F_104 ( * V_147 , V_221 * V_366 ) - V_221 ;
return 1 ;
}
T_9 * F_387 ( struct V_250 * V_251 , unsigned long V_147 , T_15 * V_360 )
{
return NULL ;
}
int F_316 ( struct V_250 * V_251 , unsigned long * V_147 , T_9 * V_264 )
{
return 0 ;
}
T_9 * F_297 ( struct V_250 * V_251 ,
unsigned long V_147 , unsigned long V_273 )
{
T_16 * V_364 ;
T_17 * V_365 ;
T_15 * V_360 ;
T_9 * V_265 = NULL ;
V_364 = F_393 ( V_251 , V_147 ) ;
V_365 = F_394 ( V_364 , V_147 ) ;
V_360 = F_398 ( V_251 , V_365 , V_147 ) ;
if ( V_360 ) {
if ( V_273 == V_356 ) {
V_265 = ( T_9 * ) V_360 ;
} else {
F_10 ( V_273 != V_367 ) ;
if ( F_399 () && F_390 ( * V_360 ) )
V_265 = F_387 ( V_251 , V_147 , V_360 ) ;
else
V_265 = ( T_9 * ) F_389 ( V_251 , V_360 , V_147 ) ;
}
}
F_10 ( V_265 && F_288 ( * V_265 ) && ! F_400 ( * V_265 ) ) ;
return V_265 ;
}
T_9 * F_296 ( struct V_250 * V_251 , unsigned long V_147 )
{
T_16 * V_364 ;
T_17 * V_365 ;
T_15 * V_360 ;
V_362 * V_368 ;
V_364 = F_393 ( V_251 , V_147 ) ;
if ( ! F_401 ( * V_364 ) )
return NULL ;
V_365 = F_394 ( V_364 , V_147 ) ;
if ( ! F_402 ( * V_365 ) )
return NULL ;
V_360 = F_395 ( V_365 , V_147 ) ;
if ( ! F_403 ( * V_360 ) )
return NULL ;
if ( F_404 ( * V_360 ) )
return ( T_9 * ) V_360 ;
V_368 = F_405 ( V_360 , V_147 ) ;
return ( T_9 * ) V_368 ;
}
struct V_74 * __weak
F_406 ( struct V_250 * V_251 , unsigned long V_50 ,
int V_242 )
{
return F_182 ( - V_202 ) ;
}
struct V_74 * __weak
F_407 ( struct V_250 * V_251 , unsigned long V_50 ,
V_362 * V_368 , int V_70 )
{
struct V_74 * V_74 = NULL ;
T_11 * V_286 ;
T_9 V_265 ;
V_42:
V_286 = F_408 ( V_251 , V_368 ) ;
F_9 ( V_286 ) ;
if ( ! F_409 ( * V_368 ) )
goto V_45;
V_265 = F_283 ( ( T_9 * ) V_368 ) ;
if ( F_288 ( V_265 ) ) {
V_74 = F_410 ( * V_368 ) + ( ( V_50 & ~ V_369 ) >> V_184 ) ;
if ( V_70 & V_370 )
F_308 ( V_74 ) ;
} else {
if ( F_286 ( V_265 ) ) {
F_2 ( V_286 ) ;
F_411 ( V_251 , ( T_9 * ) V_368 , V_286 ) ;
goto V_42;
}
}
V_45:
F_2 ( V_286 ) ;
return V_74 ;
}
struct V_74 * __weak
F_412 ( struct V_250 * V_251 , unsigned long V_50 ,
T_15 * V_360 , int V_70 )
{
if ( V_70 & V_370 )
return NULL ;
return F_307 ( * ( T_9 * ) V_360 ) + ( ( V_50 & ~ V_354 ) >> V_184 ) ;
}
int F_413 ( struct V_74 * V_371 )
{
struct V_7 * V_8 = F_130 ( V_371 ) ;
int V_75 = F_57 ( V_371 ) ;
int V_13 = - V_144 ;
F_9 ( & V_126 ) ;
if ( ! F_122 ( V_371 ) && ! F_97 ( V_371 ) ) {
F_414 ( & V_371 -> V_76 ) ;
F_61 ( V_371 ) ;
V_8 -> V_78 -- ;
V_8 -> V_79 [ V_75 ] -- ;
V_13 = 0 ;
}
F_2 ( & V_126 ) ;
return V_13 ;
}
bool F_415 ( struct V_74 * V_74 , struct V_25 * V_181 )
{
bool V_13 = true ;
F_115 ( ! F_123 ( V_74 ) , V_74 ) ;
F_9 ( & V_126 ) ;
if ( ! F_122 ( V_74 ) || ! F_416 ( V_74 ) ) {
V_13 = false ;
goto V_372;
}
F_127 ( V_74 ) ;
F_417 ( & V_74 -> V_76 , V_181 ) ;
V_372:
F_2 ( & V_126 ) ;
return V_13 ;
}
void F_418 ( struct V_74 * V_74 )
{
F_115 ( ! F_123 ( V_74 ) , V_74 ) ;
F_9 ( & V_126 ) ;
F_125 ( V_74 ) ;
F_417 ( & V_74 -> V_76 , & ( F_130 ( V_74 ) ) -> V_80 ) ;
F_2 ( & V_126 ) ;
F_138 ( V_74 ) ;
}
