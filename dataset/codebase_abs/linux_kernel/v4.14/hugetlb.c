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
static struct V_74 * F_62 ( struct V_7 * V_8 , T_2 V_81 , int V_75 ,
T_3 * V_82 )
{
unsigned int V_83 ;
struct V_84 * V_84 ;
struct V_85 * V_85 ;
struct V_86 * V_87 ;
int V_88 = - 1 ;
V_84 = F_63 ( V_75 , V_81 ) ;
V_89:
V_83 = F_64 () ;
F_65 (zone, z, zonelist, gfp_zone(gfp_mask), nmask) {
struct V_74 * V_74 ;
if ( ! F_66 ( V_85 , V_81 ) )
continue;
if ( F_67 ( V_85 ) == V_88 )
continue;
V_88 = F_67 ( V_85 ) ;
V_74 = F_59 ( V_8 , V_88 ) ;
if ( V_74 )
return V_74 ;
}
if ( F_68 ( F_69 ( V_83 ) ) )
goto V_89;
return NULL ;
}
static inline T_2 F_70 ( struct V_7 * V_8 )
{
if ( V_90 || F_71 ( V_8 ) )
return V_91 ;
else
return V_92 ;
}
static struct V_74 * F_72 ( struct V_7 * V_8 ,
struct V_18 * V_19 ,
unsigned long V_50 , int V_93 ,
long V_41 )
{
struct V_74 * V_74 ;
struct V_94 * V_95 ;
T_2 V_81 ;
T_3 * V_96 ;
int V_75 ;
if ( ! F_55 ( V_19 , V_41 ) &&
V_8 -> V_78 - V_8 -> V_97 == 0 )
goto V_98;
if ( V_93 && V_8 -> V_78 - V_8 -> V_97 == 0 )
goto V_98;
V_81 = F_70 ( V_8 ) ;
V_75 = F_73 ( V_19 , V_50 , V_81 , & V_95 , & V_96 ) ;
V_74 = F_62 ( V_8 , V_81 , V_75 , V_96 ) ;
if ( V_74 && ! V_93 && F_55 ( V_19 , V_41 ) ) {
F_74 ( V_74 ) ;
V_8 -> V_97 -- ;
}
F_75 ( V_95 ) ;
return V_74 ;
V_98:
return NULL ;
}
static int F_76 ( int V_75 , T_3 * V_99 )
{
V_75 = F_77 ( V_75 , * V_99 ) ;
F_19 ( V_75 >= V_100 ) ;
return V_75 ;
}
static int F_78 ( int V_75 , T_3 * V_99 )
{
if ( ! F_79 ( V_75 , * V_99 ) )
V_75 = F_76 ( V_75 , V_99 ) ;
return V_75 ;
}
static int F_80 ( struct V_7 * V_8 ,
T_3 * V_99 )
{
int V_75 ;
F_19 ( ! V_99 ) ;
V_75 = F_78 ( V_8 -> V_101 , V_99 ) ;
V_8 -> V_101 = F_76 ( V_75 , V_99 ) ;
return V_75 ;
}
static int F_81 ( struct V_7 * V_8 , T_3 * V_99 )
{
int V_75 ;
F_19 ( ! V_99 ) ;
V_75 = F_78 ( V_8 -> V_102 , V_99 ) ;
V_8 -> V_102 = F_76 ( V_75 , V_99 ) ;
return V_75 ;
}
static void F_82 ( struct V_74 * V_74 ,
unsigned int V_103 )
{
int V_104 ;
int V_105 = 1 << V_103 ;
struct V_74 * V_106 = V_74 + 1 ;
F_83 ( F_84 ( V_74 ) , 0 ) ;
for ( V_104 = 1 ; V_104 < V_105 ; V_104 ++ , V_106 = F_85 ( V_106 , V_74 , V_104 ) ) {
F_86 ( V_106 ) ;
F_61 ( V_106 ) ;
}
F_87 ( V_74 , 0 ) ;
F_88 ( V_74 ) ;
}
static void F_89 ( struct V_74 * V_74 , unsigned int V_103 )
{
F_90 ( F_91 ( V_74 ) , 1 << V_103 ) ;
}
static int F_92 ( unsigned long V_107 ,
unsigned long V_105 , T_2 V_81 )
{
unsigned long V_108 = V_107 + V_105 ;
return F_93 ( V_107 , V_108 , V_109 ,
V_81 ) ;
}
static bool F_94 ( struct V_85 * V_87 ,
unsigned long V_107 , unsigned long V_105 )
{
unsigned long V_104 , V_108 = V_107 + V_105 ;
struct V_74 * V_74 ;
for ( V_104 = V_107 ; V_104 < V_108 ; V_104 ++ ) {
if ( ! F_95 ( V_104 ) )
return false ;
V_74 = F_96 ( V_104 ) ;
if ( F_97 ( V_74 ) != V_87 )
return false ;
if ( F_98 ( V_74 ) )
return false ;
if ( F_99 ( V_74 ) > 0 )
return false ;
if ( F_100 ( V_74 ) )
return false ;
}
return true ;
}
static bool F_101 ( const struct V_85 * V_85 ,
unsigned long V_107 , unsigned long V_105 )
{
unsigned long V_110 = V_107 + V_105 - 1 ;
return F_102 ( V_85 , V_110 ) ;
}
static struct V_74 * F_103 ( int V_75 , struct V_7 * V_8 )
{
unsigned int V_103 = F_36 ( V_8 ) ;
unsigned long V_105 = 1 << V_103 ;
unsigned long V_13 , V_111 , V_70 ;
struct V_84 * V_84 ;
struct V_85 * V_85 ;
struct V_86 * V_87 ;
T_2 V_81 ;
V_81 = F_70 ( V_8 ) | V_112 ;
V_84 = F_63 ( V_75 , V_81 ) ;
F_65 (zone, z, zonelist, gfp_zone(gfp_mask), NULL) {
F_104 ( & V_85 -> V_5 , V_70 ) ;
V_111 = F_105 ( V_85 -> V_113 , V_105 ) ;
while ( F_101 ( V_85 , V_111 , V_105 ) ) {
if ( F_94 ( V_85 , V_111 , V_105 ) ) {
F_106 ( & V_85 -> V_5 , V_70 ) ;
V_13 = F_92 ( V_111 , V_105 , V_81 ) ;
if ( ! V_13 )
return F_96 ( V_111 ) ;
F_104 ( & V_85 -> V_5 , V_70 ) ;
}
V_111 += V_105 ;
}
F_106 ( & V_85 -> V_5 , V_70 ) ;
}
return NULL ;
}
static struct V_74 * F_107 ( struct V_7 * V_8 , int V_75 )
{
struct V_74 * V_74 ;
V_74 = F_103 ( V_75 , V_8 ) ;
if ( V_74 ) {
F_108 ( V_74 , F_36 ( V_8 ) ) ;
F_109 ( V_8 , V_74 , V_75 ) ;
}
return V_74 ;
}
static int F_110 ( struct V_7 * V_8 ,
T_3 * V_99 )
{
struct V_74 * V_74 = NULL ;
int V_114 , V_88 ;
F_111 (h, nr_nodes, node, nodes_allowed) {
V_74 = F_107 ( V_8 , V_88 ) ;
if ( V_74 )
return 1 ;
}
return 0 ;
}
static inline bool F_112 ( void ) { return false ; }
static inline void F_89 ( struct V_74 * V_74 , unsigned int V_103 ) { }
static inline void F_82 ( struct V_74 * V_74 ,
unsigned int V_103 ) { }
static inline int F_110 ( struct V_7 * V_8 ,
T_3 * V_99 ) { return 0 ; }
static void F_113 ( struct V_7 * V_8 , struct V_74 * V_74 )
{
int V_104 ;
if ( F_114 ( V_8 ) && ! F_112 () )
return;
V_8 -> V_115 -- ;
V_8 -> V_116 [ F_57 ( V_74 ) ] -- ;
for ( V_104 = 0 ; V_104 < F_115 ( V_8 ) ; V_104 ++ ) {
V_74 [ V_104 ] . V_70 &= ~ ( 1 << V_117 | 1 << V_118 |
1 << V_119 | 1 << V_120 |
1 << V_121 | 1 << V_122 |
1 << V_123 ) ;
}
F_116 ( F_117 ( V_74 ) , V_74 ) ;
F_118 ( V_74 , V_124 ) ;
F_61 ( V_74 ) ;
if ( F_114 ( V_8 ) ) {
F_82 ( V_74 , F_36 ( V_8 ) ) ;
F_89 ( V_74 , F_36 ( V_8 ) ) ;
} else {
F_119 ( V_74 , F_36 ( V_8 ) ) ;
}
}
struct V_7 * F_120 ( unsigned long V_125 )
{
struct V_7 * V_8 ;
F_121 (h) {
if ( F_122 ( V_8 ) == V_125 )
return V_8 ;
}
return NULL ;
}
bool F_123 ( struct V_74 * V_74 )
{
F_116 ( ! F_100 ( V_74 ) , V_74 ) ;
return F_124 ( V_74 ) && F_125 ( & V_74 [ 1 ] ) ;
}
static void F_126 ( struct V_74 * V_74 )
{
F_116 ( ! F_127 ( V_74 ) , V_74 ) ;
F_74 ( & V_74 [ 1 ] ) ;
}
static void F_128 ( struct V_74 * V_74 )
{
F_116 ( ! F_127 ( V_74 ) , V_74 ) ;
F_129 ( & V_74 [ 1 ] ) ;
}
void F_130 ( struct V_74 * V_74 )
{
struct V_7 * V_8 = F_131 ( V_74 ) ;
int V_75 = F_57 ( V_74 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_132 ( V_74 ) ;
bool V_126 ;
F_133 ( V_74 , 0 ) ;
V_74 -> V_65 = NULL ;
F_116 ( F_99 ( V_74 ) , V_74 ) ;
F_116 ( F_134 ( V_74 ) , V_74 ) ;
V_126 = F_125 ( V_74 ) ;
F_129 ( V_74 ) ;
if ( F_12 ( V_2 , 1 ) == 0 )
V_126 = true ;
F_9 ( & V_127 ) ;
F_128 ( V_74 ) ;
F_135 ( F_136 ( V_8 ) ,
F_115 ( V_8 ) , V_74 ) ;
if ( V_126 )
V_8 -> V_97 ++ ;
if ( V_8 -> V_128 [ V_75 ] ) {
F_21 ( & V_74 -> V_76 ) ;
F_113 ( V_8 , V_74 ) ;
V_8 -> V_129 -- ;
V_8 -> V_128 [ V_75 ] -- ;
} else {
F_137 ( V_74 ) ;
F_56 ( V_8 , V_74 ) ;
}
F_2 ( & V_127 ) ;
}
static void F_109 ( struct V_7 * V_8 , struct V_74 * V_74 , int V_75 )
{
F_26 ( & V_74 -> V_76 ) ;
F_118 ( V_74 , V_130 ) ;
F_9 ( & V_127 ) ;
F_138 ( V_74 , NULL ) ;
V_8 -> V_115 ++ ;
V_8 -> V_116 [ V_75 ] ++ ;
F_2 ( & V_127 ) ;
F_139 ( V_74 ) ;
}
static void F_108 ( struct V_74 * V_74 , unsigned int V_103 )
{
int V_104 ;
int V_105 = 1 << V_103 ;
struct V_74 * V_106 = V_74 + 1 ;
F_87 ( V_74 , V_103 ) ;
F_140 ( V_74 ) ;
F_141 ( V_74 ) ;
for ( V_104 = 1 ; V_104 < V_105 ; V_104 ++ , V_106 = F_85 ( V_106 , V_74 , V_104 ) ) {
F_140 ( V_106 ) ;
F_142 ( V_106 , 0 ) ;
F_143 ( V_106 , V_74 ) ;
}
F_83 ( F_84 ( V_74 ) , - 1 ) ;
}
int F_100 ( struct V_74 * V_74 )
{
if ( ! F_144 ( V_74 ) )
return 0 ;
V_74 = F_145 ( V_74 ) ;
return V_74 [ 1 ] . V_131 == V_130 ;
}
int F_127 ( struct V_74 * V_132 )
{
if ( ! F_124 ( V_132 ) )
return 0 ;
return F_146 ( V_132 ) == F_130 ;
}
T_1 F_147 ( struct V_74 * V_74 )
{
struct V_74 * V_132 = F_145 ( V_74 ) ;
T_1 V_133 = F_148 ( V_132 ) ;
unsigned long V_134 ;
if ( ! F_100 ( V_132 ) )
return F_148 ( V_74 ) ;
if ( F_149 ( V_132 ) >= V_135 )
V_134 = F_91 ( V_74 ) - F_91 ( V_132 ) ;
else
V_134 = V_74 - V_132 ;
return ( V_133 << F_149 ( V_132 ) ) + V_134 ;
}
static struct V_74 * F_150 ( struct V_7 * V_8 , int V_75 )
{
struct V_74 * V_74 ;
V_74 = F_151 ( V_75 ,
F_70 ( V_8 ) | V_136 | V_112 |
V_137 | V_138 ,
F_36 ( V_8 ) ) ;
if ( V_74 ) {
F_109 ( V_8 , V_74 , V_75 ) ;
}
return V_74 ;
}
static int F_152 ( struct V_7 * V_8 , T_3 * V_99 )
{
struct V_74 * V_74 ;
int V_114 , V_88 ;
int V_13 = 0 ;
F_111 (h, nr_nodes, node, nodes_allowed) {
V_74 = F_150 ( V_8 , V_88 ) ;
if ( V_74 ) {
V_13 = 1 ;
break;
}
}
if ( V_13 )
F_153 ( V_139 ) ;
else
F_153 ( V_140 ) ;
return V_13 ;
}
static int F_154 ( struct V_7 * V_8 , T_3 * V_99 ,
bool V_141 )
{
int V_114 , V_88 ;
int V_13 = 0 ;
F_155 (h, nr_nodes, node, nodes_allowed) {
if ( ( ! V_141 || V_8 -> V_128 [ V_88 ] ) &&
! F_156 ( & V_8 -> V_77 [ V_88 ] ) ) {
struct V_74 * V_74 =
F_157 ( V_8 -> V_77 [ V_88 ] . V_142 ,
struct V_74 , V_76 ) ;
F_21 ( & V_74 -> V_76 ) ;
V_8 -> V_78 -- ;
V_8 -> V_79 [ V_88 ] -- ;
if ( V_141 ) {
V_8 -> V_129 -- ;
V_8 -> V_128 [ V_88 ] -- ;
}
F_113 ( V_8 , V_74 ) ;
V_13 = 1 ;
break;
}
}
return V_13 ;
}
int F_158 ( struct V_74 * V_74 )
{
int V_143 = 0 ;
F_9 ( & V_127 ) ;
if ( F_100 ( V_74 ) && ! F_99 ( V_74 ) ) {
struct V_74 * V_26 = F_145 ( V_74 ) ;
struct V_7 * V_8 = F_131 ( V_26 ) ;
int V_75 = F_57 ( V_26 ) ;
if ( V_8 -> V_78 - V_8 -> V_97 == 0 ) {
V_143 = - V_144 ;
goto V_45;
}
if ( F_60 ( V_26 ) && V_74 != V_26 ) {
F_159 ( V_74 ) ;
F_160 ( V_26 ) ;
}
F_21 ( & V_26 -> V_76 ) ;
V_8 -> V_78 -- ;
V_8 -> V_79 [ V_75 ] -- ;
V_8 -> V_145 -- ;
F_113 ( V_8 , V_26 ) ;
}
V_45:
F_2 ( & V_127 ) ;
return V_143 ;
}
int F_161 ( unsigned long V_107 , unsigned long V_108 )
{
unsigned long V_111 ;
struct V_74 * V_74 ;
int V_143 = 0 ;
if ( ! F_162 () )
return V_143 ;
for ( V_111 = V_107 ; V_111 < V_108 ; V_111 += 1 << V_146 ) {
V_74 = F_96 ( V_111 ) ;
if ( F_100 ( V_74 ) && ! F_99 ( V_74 ) ) {
V_143 = F_158 ( V_74 ) ;
if ( V_143 )
break;
}
}
return V_143 ;
}
static struct V_74 * F_163 ( struct V_7 * V_8 ,
T_2 V_81 , int V_75 , T_3 * V_82 )
{
int V_103 = F_36 ( V_8 ) ;
V_81 |= V_136 | V_137 | V_138 ;
if ( V_75 == V_147 )
V_75 = F_164 () ;
return F_165 ( V_81 , V_103 , V_75 , V_82 ) ;
}
static struct V_74 * F_166 ( struct V_7 * V_8 , T_2 V_81 ,
int V_75 , T_3 * V_82 )
{
struct V_74 * V_74 ;
unsigned int V_148 ;
if ( F_114 ( V_8 ) )
return NULL ;
F_9 ( & V_127 ) ;
if ( V_8 -> V_129 >= V_8 -> V_149 ) {
F_2 ( & V_127 ) ;
return NULL ;
} else {
V_8 -> V_115 ++ ;
V_8 -> V_129 ++ ;
}
F_2 ( & V_127 ) ;
V_74 = F_163 ( V_8 , V_81 , V_75 , V_82 ) ;
F_9 ( & V_127 ) ;
if ( V_74 ) {
F_26 ( & V_74 -> V_76 ) ;
V_148 = F_57 ( V_74 ) ;
F_118 ( V_74 , V_130 ) ;
F_138 ( V_74 , NULL ) ;
V_8 -> V_116 [ V_148 ] ++ ;
V_8 -> V_128 [ V_148 ] ++ ;
F_167 ( V_139 ) ;
} else {
V_8 -> V_115 -- ;
V_8 -> V_129 -- ;
F_167 ( V_140 ) ;
}
F_2 ( & V_127 ) ;
return V_74 ;
}
static
struct V_74 * F_168 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_150 )
{
struct V_74 * V_74 ;
struct V_94 * V_95 ;
T_2 V_81 = F_70 ( V_8 ) ;
int V_75 ;
T_3 * V_96 ;
V_75 = F_73 ( V_19 , V_150 , V_81 , & V_95 , & V_96 ) ;
V_74 = F_166 ( V_8 , V_81 , V_75 , V_96 ) ;
F_75 ( V_95 ) ;
return V_74 ;
}
struct V_74 * F_169 ( struct V_7 * V_8 , int V_75 )
{
T_2 V_81 = F_70 ( V_8 ) ;
struct V_74 * V_74 = NULL ;
if ( V_75 != V_147 )
V_81 |= V_112 ;
F_9 ( & V_127 ) ;
if ( V_8 -> V_78 - V_8 -> V_97 > 0 )
V_74 = F_62 ( V_8 , V_81 , V_75 , NULL ) ;
F_2 ( & V_127 ) ;
if ( ! V_74 )
V_74 = F_166 ( V_8 , V_81 , V_75 , NULL ) ;
return V_74 ;
}
struct V_74 * F_170 ( struct V_7 * V_8 , int V_151 ,
T_3 * V_82 )
{
T_2 V_81 = F_70 ( V_8 ) ;
F_9 ( & V_127 ) ;
if ( V_8 -> V_78 - V_8 -> V_97 > 0 ) {
struct V_74 * V_74 ;
V_74 = F_62 ( V_8 , V_81 , V_151 , V_82 ) ;
if ( V_74 ) {
F_2 ( & V_127 ) ;
return V_74 ;
}
}
F_2 ( & V_127 ) ;
return F_166 ( V_8 , V_81 , V_151 , V_82 ) ;
}
static int F_171 ( struct V_7 * V_8 , int V_12 )
{
struct V_25 V_152 ;
struct V_74 * V_74 , * V_153 ;
int V_13 , V_104 ;
int V_154 , V_155 ;
bool V_156 = true ;
V_154 = ( V_8 -> V_97 + V_12 ) - V_8 -> V_78 ;
if ( V_154 <= 0 ) {
V_8 -> V_97 += V_12 ;
return 0 ;
}
V_155 = 0 ;
F_26 ( & V_152 ) ;
V_13 = - V_14 ;
V_42:
F_2 ( & V_127 ) ;
for ( V_104 = 0 ; V_104 < V_154 ; V_104 ++ ) {
V_74 = F_166 ( V_8 , F_70 ( V_8 ) ,
V_147 , NULL ) ;
if ( ! V_74 ) {
V_156 = false ;
break;
}
F_22 ( & V_74 -> V_76 , & V_152 ) ;
F_172 () ;
}
V_155 += V_104 ;
F_9 ( & V_127 ) ;
V_154 = ( V_8 -> V_97 + V_12 ) -
( V_8 -> V_78 + V_155 ) ;
if ( V_154 > 0 ) {
if ( V_156 )
goto V_42;
goto free;
}
V_154 += V_155 ;
V_8 -> V_97 += V_12 ;
V_13 = 0 ;
F_23 (page, tmp, &surplus_list, lru) {
if ( ( -- V_154 ) < 0 )
break;
F_173 ( V_74 ) ;
F_116 ( F_99 ( V_74 ) , V_74 ) ;
F_56 ( V_8 , V_74 ) ;
}
free:
F_2 ( & V_127 ) ;
F_23 (page, tmp, &surplus_list, lru)
F_139 ( V_74 ) ;
F_9 ( & V_127 ) ;
return V_13 ;
}
static void F_174 ( struct V_7 * V_8 ,
unsigned long V_157 )
{
unsigned long V_105 ;
if ( F_114 ( V_8 ) )
goto V_45;
V_105 = F_33 ( V_157 , V_8 -> V_129 ) ;
while ( V_105 -- ) {
V_8 -> V_97 -- ;
V_157 -- ;
if ( ! F_154 ( V_8 , & V_158 [ V_159 ] , 1 ) )
goto V_45;
F_175 ( & V_127 ) ;
}
V_45:
V_8 -> V_97 -= V_157 ;
}
static long F_176 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_150 ,
enum V_160 V_161 )
{
struct V_21 * V_22 ;
T_1 V_162 ;
long V_13 ;
V_22 = F_49 ( V_19 ) ;
if ( ! V_22 )
return 1 ;
V_162 = F_34 ( V_8 , V_19 , V_150 ) ;
switch ( V_161 ) {
case V_163 :
V_13 = F_24 ( V_22 , V_162 , V_162 + 1 ) ;
break;
case V_164 :
V_13 = F_17 ( V_22 , V_162 , V_162 + 1 ) ;
break;
case V_165 :
F_27 ( V_22 , V_162 , V_162 + 1 ) ;
V_13 = 0 ;
break;
case V_166 :
if ( V_19 -> V_62 & V_63 )
V_13 = F_17 ( V_22 , V_162 , V_162 + 1 ) ;
else {
F_27 ( V_22 , V_162 , V_162 + 1 ) ;
V_13 = F_28 ( V_22 , V_162 , V_162 + 1 ) ;
}
break;
default:
F_177 () ;
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
static long F_178 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_150 )
{
return F_176 ( V_8 , V_19 , V_150 , V_163 ) ;
}
static long F_179 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_150 )
{
return F_176 ( V_8 , V_19 , V_150 , V_164 ) ;
}
static void F_180 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_150 )
{
( void ) F_176 ( V_8 , V_19 , V_150 , V_165 ) ;
}
static long F_181 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_150 )
{
return F_176 ( V_8 , V_19 , V_150 , V_166 ) ;
}
static void F_182 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_50 ,
struct V_74 * V_74 )
{
if ( F_68 ( F_125 ( V_74 ) ) ) {
long V_143 = F_178 ( V_8 , V_19 , V_50 ) ;
if ( F_68 ( V_143 < 0 ) ) {
F_129 ( V_74 ) ;
} else if ( V_143 ) {
V_143 = F_181 ( V_8 , V_19 , V_50 ) ;
if ( F_68 ( V_143 < 0 ) )
F_129 ( V_74 ) ;
} else
F_180 ( V_8 , V_19 , V_50 ) ;
}
}
struct V_74 * F_183 ( struct V_18 * V_19 ,
unsigned long V_150 , int V_93 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_74 * V_74 ;
long V_167 , V_168 ;
long V_169 ;
int V_13 , V_162 ;
struct V_170 * V_171 ;
V_162 = F_136 ( V_8 ) ;
V_167 = V_169 = F_178 ( V_8 , V_19 , V_150 ) ;
if ( V_167 < 0 )
return F_184 ( - V_14 ) ;
if ( V_167 || V_93 ) {
V_169 = F_11 ( V_2 , 1 ) ;
if ( V_169 < 0 ) {
F_180 ( V_8 , V_19 , V_150 ) ;
return F_184 ( - V_172 ) ;
}
if ( V_93 )
V_169 = 1 ;
}
V_13 = F_185 ( V_162 , F_115 ( V_8 ) , & V_171 ) ;
if ( V_13 )
goto V_173;
F_9 ( & V_127 ) ;
V_74 = F_72 ( V_8 , V_19 , V_150 , V_93 , V_169 ) ;
if ( ! V_74 ) {
F_2 ( & V_127 ) ;
V_74 = F_168 ( V_8 , V_19 , V_150 ) ;
if ( ! V_74 )
goto V_174;
if ( ! V_93 && F_55 ( V_19 , V_169 ) ) {
F_74 ( V_74 ) ;
V_8 -> V_97 -- ;
}
F_9 ( & V_127 ) ;
F_58 ( & V_74 -> V_76 , & V_8 -> V_80 ) ;
}
F_186 ( V_162 , F_115 ( V_8 ) , V_171 , V_74 ) ;
F_2 ( & V_127 ) ;
F_133 ( V_74 , ( unsigned long ) V_2 ) ;
V_168 = F_179 ( V_8 , V_19 , V_150 ) ;
if ( F_68 ( V_167 > V_168 ) ) {
long V_47 ;
V_47 = F_12 ( V_2 , 1 ) ;
F_3 ( V_8 , - V_47 ) ;
}
return V_74 ;
V_174:
F_187 ( V_162 , F_115 ( V_8 ) , V_171 ) ;
V_173:
if ( V_167 || V_93 )
F_12 ( V_2 , 1 ) ;
F_180 ( V_8 , V_19 , V_150 ) ;
return F_184 ( - V_172 ) ;
}
struct V_74 * F_188 ( struct V_18 * V_19 ,
unsigned long V_150 , int V_93 )
{
struct V_74 * V_74 = F_183 ( V_19 , V_150 , V_93 ) ;
if ( F_189 ( V_74 ) )
V_74 = NULL ;
return V_74 ;
}
int F_190 ( struct V_7 * V_8 )
{
struct V_175 * V_176 ;
int V_114 , V_88 ;
F_111 (h, nr_nodes, node, &node_states[N_MEMORY]) {
void * V_150 ;
V_150 = F_191 (
F_122 ( V_8 ) , F_122 ( V_8 ) ,
0 , V_177 , V_88 ) ;
if ( V_150 ) {
V_176 = V_150 ;
goto V_178;
}
}
return 0 ;
V_178:
F_10 ( ! F_192 ( F_193 ( V_176 ) , F_122 ( V_8 ) ) ) ;
F_22 ( & V_176 -> V_179 , & V_180 ) ;
V_176 -> V_7 = V_8 ;
return 1 ;
}
static void T_4 F_194 ( struct V_74 * V_74 ,
unsigned int V_103 )
{
if ( F_68 ( V_103 > ( V_135 - 1 ) ) )
F_108 ( V_74 , V_103 ) ;
else
F_195 ( V_74 , V_103 ) ;
}
static void T_4 F_196 ( void )
{
struct V_175 * V_176 ;
F_18 (m, &huge_boot_pages, list) {
struct V_7 * V_8 = V_176 -> V_7 ;
struct V_74 * V_74 ;
#ifdef F_197
V_74 = F_96 ( V_176 -> V_181 >> V_182 ) ;
F_198 ( F_199 ( V_176 ) ,
sizeof( struct V_175 ) ) ;
#else
V_74 = F_200 ( V_176 ) ;
#endif
F_201 ( F_99 ( V_74 ) != 1 ) ;
F_194 ( V_74 , V_8 -> V_103 ) ;
F_201 ( F_98 ( V_74 ) ) ;
F_109 ( V_8 , V_74 , F_57 ( V_74 ) ) ;
if ( F_114 ( V_8 ) )
F_202 ( V_74 , 1 << V_8 -> V_103 ) ;
}
}
static void T_4 F_203 ( struct V_7 * V_8 )
{
unsigned long V_104 ;
for ( V_104 = 0 ; V_104 < V_8 -> V_145 ; ++ V_104 ) {
if ( F_114 ( V_8 ) ) {
if ( ! F_204 ( V_8 ) )
break;
} else if ( ! F_152 ( V_8 ,
& V_158 [ V_159 ] ) )
break;
F_172 () ;
}
if ( V_104 < V_8 -> V_145 ) {
char V_183 [ 32 ] ;
F_205 ( F_122 ( V_8 ) , 1 , V_184 , V_183 , 32 ) ;
F_206 ( L_1 ,
V_8 -> V_145 , V_183 , V_104 ) ;
V_8 -> V_145 = V_104 ;
}
}
static void T_4 F_207 ( void )
{
struct V_7 * V_8 ;
F_121 (h) {
if ( V_146 > F_36 ( V_8 ) )
V_146 = F_36 ( V_8 ) ;
if ( ! F_114 ( V_8 ) )
F_203 ( V_8 ) ;
}
F_19 ( V_146 == V_185 ) ;
}
static void T_4 F_208 ( void )
{
struct V_7 * V_8 ;
F_121 (h) {
char V_183 [ 32 ] ;
F_205 ( F_122 ( V_8 ) , 1 , V_184 , V_183 , 32 ) ;
F_209 ( L_2 ,
V_183 , V_8 -> V_78 ) ;
}
}
static void F_210 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_99 )
{
int V_104 ;
if ( F_114 ( V_8 ) )
return;
F_211 (i, *nodes_allowed) {
struct V_74 * V_74 , * V_142 ;
struct V_25 * V_186 = & V_8 -> V_77 [ V_104 ] ;
F_23 (page, next, freel, lru) {
if ( V_3 >= V_8 -> V_115 )
return;
if ( F_212 ( V_74 ) )
continue;
F_21 ( & V_74 -> V_76 ) ;
F_113 ( V_8 , V_74 ) ;
V_8 -> V_78 -- ;
V_8 -> V_79 [ F_57 ( V_74 ) ] -- ;
}
}
}
static inline void F_210 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_99 )
{
}
static int F_213 ( struct V_7 * V_8 , T_3 * V_99 ,
int V_12 )
{
int V_114 , V_88 ;
F_19 ( V_12 != - 1 && V_12 != 1 ) ;
if ( V_12 < 0 ) {
F_111 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_128 [ V_88 ] )
goto V_178;
}
} else {
F_155 (h, nr_nodes, node, nodes_allowed) {
if ( V_8 -> V_128 [ V_88 ] <
V_8 -> V_116 [ V_88 ] )
goto V_178;
}
}
return 0 ;
V_178:
V_8 -> V_129 += V_12 ;
V_8 -> V_128 [ V_88 ] += V_12 ;
return 1 ;
}
static unsigned long F_214 ( struct V_7 * V_8 , unsigned long V_3 ,
T_3 * V_99 )
{
unsigned long V_187 , V_13 ;
if ( F_114 ( V_8 ) && ! F_112 () )
return V_8 -> V_145 ;
F_9 ( & V_127 ) ;
while ( V_8 -> V_129 && V_3 > F_215 ( V_8 ) ) {
if ( ! F_213 ( V_8 , V_99 , - 1 ) )
break;
}
while ( V_3 > F_215 ( V_8 ) ) {
F_2 ( & V_127 ) ;
F_172 () ;
if ( F_114 ( V_8 ) )
V_13 = F_110 ( V_8 , V_99 ) ;
else
V_13 = F_152 ( V_8 , V_99 ) ;
F_9 ( & V_127 ) ;
if ( ! V_13 )
goto V_45;
if ( F_216 ( V_188 ) )
goto V_45;
}
V_187 = V_8 -> V_97 + V_8 -> V_115 - V_8 -> V_78 ;
V_187 = F_32 ( V_3 , V_187 ) ;
F_210 ( V_8 , V_187 , V_99 ) ;
while ( V_187 < F_215 ( V_8 ) ) {
if ( ! F_154 ( V_8 , V_99 , 0 ) )
break;
F_175 ( & V_127 ) ;
}
while ( V_3 < F_215 ( V_8 ) ) {
if ( ! F_213 ( V_8 , V_99 , 1 ) )
break;
}
V_45:
V_13 = F_215 ( V_8 ) ;
F_2 ( & V_127 ) ;
return V_13 ;
}
static struct V_7 * F_217 ( struct V_189 * V_190 , int * V_191 )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < V_192 ; V_104 ++ )
if ( V_193 [ V_104 ] == V_190 ) {
if ( V_191 )
* V_191 = V_147 ;
return & V_194 [ V_104 ] ;
}
return F_218 ( V_190 , V_191 ) ;
}
static T_5 F_219 ( struct V_189 * V_190 ,
struct V_195 * V_196 , char * V_183 )
{
struct V_7 * V_8 ;
unsigned long V_115 ;
int V_75 ;
V_8 = F_217 ( V_190 , & V_75 ) ;
if ( V_75 == V_147 )
V_115 = V_8 -> V_115 ;
else
V_115 = V_8 -> V_116 [ V_75 ] ;
return sprintf ( V_183 , L_3 , V_115 ) ;
}
static T_5 F_220 ( bool V_197 ,
struct V_7 * V_8 , int V_75 ,
unsigned long V_3 , T_6 V_198 )
{
int V_98 ;
F_221 ( T_3 , V_99 , V_10 | V_199 ) ;
if ( F_114 ( V_8 ) && ! F_112 () ) {
V_98 = - V_200 ;
goto V_45;
}
if ( V_75 == V_147 ) {
if ( ! ( V_197 &&
F_222 ( V_99 ) ) ) {
F_223 ( V_99 ) ;
V_99 = & V_158 [ V_159 ] ;
}
} else if ( V_99 ) {
V_3 += V_8 -> V_115 - V_8 -> V_116 [ V_75 ] ;
F_224 ( V_99 , V_75 ) ;
} else
V_99 = & V_158 [ V_159 ] ;
V_8 -> V_145 = F_214 ( V_8 , V_3 , V_99 ) ;
if ( V_99 != & V_158 [ V_159 ] )
F_223 ( V_99 ) ;
return V_198 ;
V_45:
F_223 ( V_99 ) ;
return V_98 ;
}
static T_5 F_225 ( bool V_197 ,
struct V_189 * V_190 , const char * V_183 ,
T_6 V_198 )
{
struct V_7 * V_8 ;
unsigned long V_3 ;
int V_75 ;
int V_98 ;
V_98 = F_226 ( V_183 , 10 , & V_3 ) ;
if ( V_98 )
return V_98 ;
V_8 = F_217 ( V_190 , & V_75 ) ;
return F_220 ( V_197 , V_8 , V_75 , V_3 , V_198 ) ;
}
static T_5 F_227 ( struct V_189 * V_190 ,
struct V_195 * V_196 , char * V_183 )
{
return F_219 ( V_190 , V_196 , V_183 ) ;
}
static T_5 F_228 ( struct V_189 * V_190 ,
struct V_195 * V_196 , const char * V_183 , T_6 V_198 )
{
return F_225 ( false , V_190 , V_183 , V_198 ) ;
}
static T_5 F_229 ( struct V_189 * V_190 ,
struct V_195 * V_196 , char * V_183 )
{
return F_219 ( V_190 , V_196 , V_183 ) ;
}
static T_5 F_230 ( struct V_189 * V_190 ,
struct V_195 * V_196 , const char * V_183 , T_6 V_198 )
{
return F_225 ( true , V_190 , V_183 , V_198 ) ;
}
static T_5 F_231 ( struct V_189 * V_190 ,
struct V_195 * V_196 , char * V_183 )
{
struct V_7 * V_8 = F_217 ( V_190 , NULL ) ;
return sprintf ( V_183 , L_3 , V_8 -> V_149 ) ;
}
static T_5 F_232 ( struct V_189 * V_190 ,
struct V_195 * V_196 , const char * V_183 , T_6 V_3 )
{
int V_98 ;
unsigned long V_201 ;
struct V_7 * V_8 = F_217 ( V_190 , NULL ) ;
if ( F_114 ( V_8 ) )
return - V_200 ;
V_98 = F_226 ( V_183 , 10 , & V_201 ) ;
if ( V_98 )
return V_98 ;
F_9 ( & V_127 ) ;
V_8 -> V_149 = V_201 ;
F_2 ( & V_127 ) ;
return V_3 ;
}
static T_5 F_233 ( struct V_189 * V_190 ,
struct V_195 * V_196 , char * V_183 )
{
struct V_7 * V_8 ;
unsigned long V_78 ;
int V_75 ;
V_8 = F_217 ( V_190 , & V_75 ) ;
if ( V_75 == V_147 )
V_78 = V_8 -> V_78 ;
else
V_78 = V_8 -> V_79 [ V_75 ] ;
return sprintf ( V_183 , L_3 , V_78 ) ;
}
static T_5 F_234 ( struct V_189 * V_190 ,
struct V_195 * V_196 , char * V_183 )
{
struct V_7 * V_8 = F_217 ( V_190 , NULL ) ;
return sprintf ( V_183 , L_3 , V_8 -> V_97 ) ;
}
static T_5 F_235 ( struct V_189 * V_190 ,
struct V_195 * V_196 , char * V_183 )
{
struct V_7 * V_8 ;
unsigned long V_129 ;
int V_75 ;
V_8 = F_217 ( V_190 , & V_75 ) ;
if ( V_75 == V_147 )
V_129 = V_8 -> V_129 ;
else
V_129 = V_8 -> V_128 [ V_75 ] ;
return sprintf ( V_183 , L_3 , V_129 ) ;
}
static int F_236 ( struct V_7 * V_8 , struct V_189 * V_202 ,
struct V_189 * * V_193 ,
const struct V_203 * V_204 )
{
int V_205 ;
int V_206 = F_136 ( V_8 ) ;
V_193 [ V_206 ] = F_237 ( V_8 -> V_207 , V_202 ) ;
if ( ! V_193 [ V_206 ] )
return - V_14 ;
V_205 = F_238 ( V_193 [ V_206 ] , V_204 ) ;
if ( V_205 )
F_239 ( V_193 [ V_206 ] ) ;
return V_205 ;
}
static void T_4 F_240 ( void )
{
struct V_7 * V_8 ;
int V_98 ;
V_208 = F_237 ( L_4 , V_209 ) ;
if ( ! V_208 )
return;
F_121 (h) {
V_98 = F_236 ( V_8 , V_208 ,
V_193 , & V_204 ) ;
if ( V_98 )
F_241 ( L_5 , V_8 -> V_207 ) ;
}
}
static struct V_7 * F_218 ( struct V_189 * V_190 , int * V_191 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_210 ; V_75 ++ ) {
struct V_211 * V_212 = & V_213 [ V_75 ] ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_192 ; V_104 ++ )
if ( V_212 -> V_193 [ V_104 ] == V_190 ) {
if ( V_191 )
* V_191 = V_75 ;
return & V_194 [ V_104 ] ;
}
}
F_177 () ;
return NULL ;
}
static void F_242 ( struct V_88 * V_88 )
{
struct V_7 * V_8 ;
struct V_211 * V_212 = & V_213 [ V_88 -> V_214 . V_215 ] ;
if ( ! V_212 -> V_208 )
return;
F_121 (h) {
int V_162 = F_136 ( V_8 ) ;
if ( V_212 -> V_193 [ V_162 ] ) {
F_239 ( V_212 -> V_193 [ V_162 ] ) ;
V_212 -> V_193 [ V_162 ] = NULL ;
}
}
F_239 ( V_212 -> V_208 ) ;
V_212 -> V_208 = NULL ;
}
static void F_243 ( struct V_88 * V_88 )
{
struct V_7 * V_8 ;
struct V_211 * V_212 = & V_213 [ V_88 -> V_214 . V_215 ] ;
int V_98 ;
if ( V_212 -> V_208 )
return;
V_212 -> V_208 = F_237 ( L_4 ,
& V_88 -> V_214 . V_190 ) ;
if ( ! V_212 -> V_208 )
return;
F_121 (h) {
V_98 = F_236 ( V_8 , V_212 -> V_208 ,
V_212 -> V_193 ,
& V_216 ) ;
if ( V_98 ) {
F_241 ( L_6 ,
V_8 -> V_207 , V_88 -> V_214 . V_215 ) ;
F_242 ( V_88 ) ;
break;
}
}
}
static void T_4 F_244 ( void )
{
int V_75 ;
F_245 (nid, N_MEMORY) {
struct V_88 * V_88 = V_217 [ V_75 ] ;
if ( V_88 -> V_214 . V_215 == V_75 )
F_243 ( V_88 ) ;
}
F_246 ( F_243 ,
F_242 ) ;
}
static struct V_7 * F_218 ( struct V_189 * V_190 , int * V_191 )
{
F_177 () ;
if ( V_191 )
* V_191 = - 1 ;
return NULL ;
}
static void F_244 ( void ) { }
static int T_4 F_247 ( void )
{
int V_104 ;
if ( ! F_162 () )
return 0 ;
if ( ! F_120 ( V_218 ) ) {
if ( V_218 != 0 ) {
F_241 ( L_7 ,
V_218 , V_219 ) ;
}
V_218 = V_219 ;
if ( ! F_120 ( V_218 ) )
F_248 ( V_220 ) ;
}
V_221 = F_136 ( F_120 ( V_218 ) ) ;
if ( V_222 ) {
if ( ! V_223 . V_145 )
V_223 . V_145 = V_222 ;
}
F_207 () ;
F_196 () ;
F_208 () ;
F_240 () ;
F_244 () ;
F_249 () ;
#ifdef F_250
V_224 = F_251 ( 8 * F_252 () ) ;
#else
V_224 = 1 ;
#endif
V_225 =
F_25 ( sizeof( struct V_226 ) * V_224 , V_10 ) ;
F_10 ( ! V_225 ) ;
for ( V_104 = 0 ; V_104 < V_224 ; V_104 ++ )
F_253 ( & V_225 [ V_104 ] ) ;
return 0 ;
}
void T_4 F_254 ( void )
{
V_227 = false ;
}
void T_4 F_248 ( unsigned int V_103 )
{
struct V_7 * V_8 ;
unsigned long V_104 ;
if ( F_120 ( V_53 << V_103 ) ) {
F_206 ( L_8 ) ;
return;
}
F_10 ( V_228 >= V_192 ) ;
F_10 ( V_103 == 0 ) ;
V_8 = & V_194 [ V_228 ++ ] ;
V_8 -> V_103 = V_103 ;
V_8 -> V_229 = ~ ( ( 1ULL << ( V_103 + V_182 ) ) - 1 ) ;
V_8 -> V_115 = 0 ;
V_8 -> V_78 = 0 ;
for ( V_104 = 0 ; V_104 < V_100 ; ++ V_104 )
F_26 ( & V_8 -> V_77 [ V_104 ] ) ;
F_26 ( & V_8 -> V_80 ) ;
V_8 -> V_101 = V_230 ;
V_8 -> V_102 = V_230 ;
snprintf ( V_8 -> V_207 , V_231 , L_9 ,
F_122 ( V_8 ) / 1024 ) ;
V_232 = V_8 ;
}
static int T_4 F_255 ( char * V_233 )
{
unsigned long * V_234 ;
static unsigned long * V_235 ;
if ( ! V_227 ) {
F_206 ( L_10
L_11 , V_233 ) ;
V_227 = true ;
return 1 ;
}
else if ( ! V_228 )
V_234 = & V_222 ;
else
V_234 = & V_232 -> V_145 ;
if ( V_234 == V_235 ) {
F_206 ( L_12 ) ;
return 1 ;
}
if ( sscanf ( V_233 , L_13 , V_234 ) <= 0 )
* V_234 = 0 ;
if ( V_228 && V_232 -> V_103 >= V_135 )
F_203 ( V_232 ) ;
V_235 = V_234 ;
return 1 ;
}
static int T_4 F_256 ( char * V_233 )
{
V_218 = F_257 ( V_233 , & V_233 ) ;
return 1 ;
}
static unsigned int F_258 ( unsigned int * V_236 )
{
int V_88 ;
unsigned int V_237 = 0 ;
F_211 (node, cpuset_current_mems_allowed)
V_237 += V_236 [ V_88 ] ;
return V_237 ;
}
static int F_259 ( bool V_197 ,
struct V_238 * V_239 , int V_240 ,
void T_7 * V_241 , T_6 * V_242 , T_8 * V_243 )
{
struct V_7 * V_8 = & V_223 ;
unsigned long V_153 = V_8 -> V_145 ;
int V_13 ;
if ( ! F_162 () )
return - V_244 ;
V_239 -> V_245 = & V_153 ;
V_239 -> V_246 = sizeof( unsigned long ) ;
V_13 = F_260 ( V_239 , V_240 , V_241 , V_242 , V_243 ) ;
if ( V_13 )
goto V_45;
if ( V_240 )
V_13 = F_220 ( V_197 , V_8 ,
V_147 , V_153 , * V_242 ) ;
V_45:
return V_13 ;
}
int F_261 ( struct V_238 * V_239 , int V_240 ,
void T_7 * V_241 , T_6 * V_242 , T_8 * V_243 )
{
return F_259 ( false , V_239 , V_240 ,
V_241 , V_242 , V_243 ) ;
}
int F_262 ( struct V_238 * V_239 , int V_240 ,
void T_7 * V_241 , T_6 * V_242 , T_8 * V_243 )
{
return F_259 ( true , V_239 , V_240 ,
V_241 , V_242 , V_243 ) ;
}
int F_263 ( struct V_238 * V_239 , int V_240 ,
void T_7 * V_241 ,
T_6 * V_242 , T_8 * V_243 )
{
struct V_7 * V_8 = & V_223 ;
unsigned long V_153 ;
int V_13 ;
if ( ! F_162 () )
return - V_244 ;
V_153 = V_8 -> V_149 ;
if ( V_240 && F_114 ( V_8 ) )
return - V_200 ;
V_239 -> V_245 = & V_153 ;
V_239 -> V_246 = sizeof( unsigned long ) ;
V_13 = F_260 ( V_239 , V_240 , V_241 , V_242 , V_243 ) ;
if ( V_13 )
goto V_45;
if ( V_240 ) {
F_9 ( & V_127 ) ;
V_8 -> V_149 = V_153 ;
F_2 ( & V_127 ) ;
}
V_45:
return V_13 ;
}
void F_264 ( struct V_247 * V_176 )
{
struct V_7 * V_8 = & V_223 ;
if ( ! F_162 () )
return;
F_265 ( V_176 ,
L_14
L_15
L_16
L_17
L_18 ,
V_8 -> V_115 ,
V_8 -> V_78 ,
V_8 -> V_97 ,
V_8 -> V_129 ,
1UL << ( F_36 ( V_8 ) + V_182 - 10 ) ) ;
}
int F_266 ( int V_75 , char * V_183 )
{
struct V_7 * V_8 = & V_223 ;
if ( ! F_162 () )
return 0 ;
return sprintf ( V_183 ,
L_19
L_20
L_21 ,
V_75 , V_8 -> V_116 [ V_75 ] ,
V_75 , V_8 -> V_79 [ V_75 ] ,
V_75 , V_8 -> V_128 [ V_75 ] ) ;
}
void F_267 ( void )
{
struct V_7 * V_8 ;
int V_75 ;
if ( ! F_162 () )
return;
F_245 (nid, N_MEMORY)
F_121 (h)
F_209 ( L_22 ,
V_75 ,
V_8 -> V_116 [ V_75 ] ,
V_8 -> V_79 [ V_75 ] ,
V_8 -> V_128 [ V_75 ] ,
1UL << ( F_36 ( V_8 ) + V_182 - 10 ) ) ;
}
void F_268 ( struct V_247 * V_176 , struct V_248 * V_249 )
{
F_265 ( V_176 , L_23 ,
F_269 ( & V_249 -> V_250 ) << ( V_182 - 10 ) ) ;
}
unsigned long F_270 ( void )
{
struct V_7 * V_8 ;
unsigned long V_251 = 0 ;
F_121 (h)
V_251 += V_8 -> V_115 * F_115 ( V_8 ) ;
return V_251 ;
}
static int F_3 ( struct V_7 * V_8 , long V_12 )
{
int V_13 = - V_14 ;
F_9 ( & V_127 ) ;
if ( V_12 > 0 ) {
if ( F_171 ( V_8 , V_12 ) < 0 )
goto V_45;
if ( V_12 > F_258 ( V_8 -> V_79 ) ) {
F_174 ( V_8 , V_12 ) ;
goto V_45;
}
}
V_13 = 0 ;
if ( V_12 < 0 )
F_174 ( V_8 , ( unsigned long ) - V_12 ) ;
V_45:
F_2 ( & V_127 ) ;
return V_13 ;
}
static void F_271 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_49 ( V_19 ) ;
if ( V_22 && F_53 ( V_19 , V_73 ) )
F_272 ( & V_22 -> V_56 ) ;
}
static void F_273 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_21 * V_22 = F_49 ( V_19 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
unsigned long V_252 , V_253 , V_254 ;
long V_255 ;
if ( ! V_22 || ! F_53 ( V_19 , V_73 ) )
return;
V_253 = F_34 ( V_8 , V_19 , V_19 -> V_51 ) ;
V_254 = F_34 ( V_8 , V_19 , V_19 -> V_256 ) ;
V_252 = ( V_254 - V_253 ) - F_31 ( V_22 , V_253 , V_254 ) ;
F_274 ( & V_22 -> V_56 , F_46 ) ;
if ( V_252 ) {
V_255 = F_12 ( V_2 , V_252 ) ;
F_3 ( V_8 , - V_255 ) ;
}
}
static int F_275 ( struct V_257 * V_258 )
{
F_177 () ;
return 0 ;
}
static T_9 F_276 ( struct V_18 * V_19 , struct V_74 * V_74 ,
int V_259 )
{
T_9 V_260 ;
if ( V_259 ) {
V_260 = F_277 ( F_278 ( F_279 ( V_74 ,
V_19 -> V_261 ) ) ) ;
} else {
V_260 = F_280 ( F_279 ( V_74 ,
V_19 -> V_261 ) ) ;
}
V_260 = F_281 ( V_260 ) ;
V_260 = F_282 ( V_260 ) ;
V_260 = F_283 ( V_260 , V_19 , V_74 , V_259 ) ;
return V_260 ;
}
static void F_284 ( struct V_18 * V_19 ,
unsigned long V_50 , T_9 * V_262 )
{
T_9 V_260 ;
V_260 = F_277 ( F_278 ( F_285 ( V_262 ) ) ) ;
if ( F_286 ( V_19 , V_50 , V_262 , V_260 , 1 ) )
F_287 ( V_19 , V_50 , V_262 ) ;
}
bool F_288 ( T_9 V_263 )
{
T_10 V_264 ;
if ( F_289 ( V_263 ) || F_290 ( V_263 ) )
return false ;
V_264 = F_291 ( V_263 ) ;
if ( F_292 ( V_264 ) && F_293 ( V_264 ) )
return true ;
else
return false ;
}
static int F_294 ( T_9 V_263 )
{
T_10 V_264 ;
if ( F_289 ( V_263 ) || F_290 ( V_263 ) )
return 0 ;
V_264 = F_291 ( V_263 ) ;
if ( F_292 ( V_264 ) && F_295 ( V_264 ) )
return 1 ;
else
return 0 ;
}
int F_296 ( struct V_248 * V_265 , struct V_248 * V_266 ,
struct V_18 * V_19 )
{
T_9 * V_267 , * V_268 , V_260 ;
struct V_74 * V_269 ;
unsigned long V_150 ;
int V_270 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_271 = F_122 ( V_8 ) ;
unsigned long V_272 ;
unsigned long V_273 ;
int V_13 = 0 ;
V_270 = ( V_19 -> V_62 & ( V_274 | V_275 ) ) == V_275 ;
V_272 = V_19 -> V_51 ;
V_273 = V_19 -> V_256 ;
if ( V_270 )
F_297 ( V_266 , V_272 , V_273 ) ;
for ( V_150 = V_19 -> V_51 ; V_150 < V_19 -> V_256 ; V_150 += V_271 ) {
T_11 * V_276 , * V_277 ;
V_267 = F_298 ( V_266 , V_150 , V_271 ) ;
if ( ! V_267 )
continue;
V_268 = F_299 ( V_265 , V_150 , V_271 ) ;
if ( ! V_268 ) {
V_13 = - V_14 ;
break;
}
if ( V_268 == V_267 )
continue;
V_277 = F_300 ( V_8 , V_265 , V_268 ) ;
V_276 = F_301 ( V_8 , V_266 , V_267 ) ;
F_302 ( V_276 , V_278 ) ;
V_260 = F_285 ( V_267 ) ;
if ( F_289 ( V_260 ) ) {
;
} else if ( F_68 ( F_288 ( V_260 ) ||
F_294 ( V_260 ) ) ) {
T_10 V_279 = F_291 ( V_260 ) ;
if ( F_303 ( V_279 ) && V_270 ) {
F_304 ( & V_279 ) ;
V_260 = F_305 ( V_279 ) ;
F_306 ( V_266 , V_150 , V_267 ,
V_260 , V_271 ) ;
}
F_306 ( V_265 , V_150 , V_268 , V_260 , V_271 ) ;
} else {
if ( V_270 ) {
F_307 ( V_266 , V_150 , V_267 ) ;
F_308 ( V_266 , V_272 ,
V_273 ) ;
}
V_260 = F_285 ( V_267 ) ;
V_269 = F_309 ( V_260 ) ;
F_310 ( V_269 ) ;
F_311 ( V_269 , true ) ;
F_312 ( V_265 , V_150 , V_268 , V_260 ) ;
F_313 ( F_115 ( V_8 ) , V_265 ) ;
}
F_2 ( V_276 ) ;
F_2 ( V_277 ) ;
}
if ( V_270 )
F_314 ( V_266 , V_272 , V_273 ) ;
return V_13 ;
}
void F_315 ( struct V_280 * V_281 , struct V_18 * V_19 ,
unsigned long V_253 , unsigned long V_254 ,
struct V_74 * V_282 )
{
struct V_248 * V_249 = V_19 -> V_283 ;
unsigned long V_50 ;
T_9 * V_262 ;
T_9 V_263 ;
T_11 * V_284 ;
struct V_74 * V_74 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_271 = F_122 ( V_8 ) ;
const unsigned long V_272 = V_253 ;
const unsigned long V_273 = V_254 ;
F_201 ( ! F_40 ( V_19 ) ) ;
F_10 ( V_253 & ~ F_316 ( V_8 ) ) ;
F_10 ( V_254 & ~ F_316 ( V_8 ) ) ;
F_317 ( V_281 , V_271 ) ;
F_318 ( V_281 , V_19 ) ;
F_297 ( V_249 , V_272 , V_273 ) ;
V_50 = V_253 ;
for (; V_50 < V_254 ; V_50 += V_271 ) {
V_262 = F_298 ( V_249 , V_50 , V_271 ) ;
if ( ! V_262 )
continue;
V_284 = F_300 ( V_8 , V_249 , V_262 ) ;
if ( F_319 ( V_249 , & V_50 , V_262 ) ) {
F_2 ( V_284 ) ;
continue;
}
V_263 = F_285 ( V_262 ) ;
if ( F_289 ( V_263 ) ) {
F_2 ( V_284 ) ;
continue;
}
if ( F_68 ( ! F_290 ( V_263 ) ) ) {
F_320 ( V_249 , V_50 , V_262 , V_271 ) ;
F_2 ( V_284 ) ;
continue;
}
V_74 = F_309 ( V_263 ) ;
if ( V_282 ) {
if ( V_74 != V_282 ) {
F_2 ( V_284 ) ;
continue;
}
F_52 ( V_19 , V_285 ) ;
}
V_263 = F_321 ( V_249 , V_50 , V_262 ) ;
F_322 ( V_8 , V_281 , V_262 , V_50 ) ;
if ( F_323 ( V_263 ) )
F_324 ( V_74 ) ;
F_325 ( F_115 ( V_8 ) , V_249 ) ;
F_326 ( V_74 , true ) ;
F_2 ( V_284 ) ;
F_327 ( V_281 , V_74 , F_122 ( V_8 ) ) ;
if ( V_282 )
break;
}
F_314 ( V_249 , V_272 , V_273 ) ;
F_328 ( V_281 , V_19 ) ;
}
void F_329 ( struct V_280 * V_281 ,
struct V_18 * V_19 , unsigned long V_253 ,
unsigned long V_254 , struct V_74 * V_282 )
{
F_315 ( V_281 , V_19 , V_253 , V_254 , V_282 ) ;
V_19 -> V_62 &= ~ V_63 ;
}
void F_330 ( struct V_18 * V_19 , unsigned long V_253 ,
unsigned long V_254 , struct V_74 * V_282 )
{
struct V_248 * V_249 ;
struct V_280 V_281 ;
V_249 = V_19 -> V_283 ;
F_331 ( & V_281 , V_249 , V_253 , V_254 ) ;
F_315 ( & V_281 , V_19 , V_253 , V_254 , V_282 ) ;
F_332 ( & V_281 , V_253 , V_254 ) ;
}
static void F_333 ( struct V_248 * V_249 , struct V_18 * V_19 ,
struct V_74 * V_74 , unsigned long V_50 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_18 * V_286 ;
struct V_64 * V_65 ;
T_1 V_287 ;
V_50 = V_50 & F_316 ( V_8 ) ;
V_287 = ( ( V_50 - V_19 -> V_51 ) >> V_182 ) +
V_19 -> V_52 ;
V_65 = V_19 -> V_20 -> V_66 ;
F_334 ( V_65 ) ;
F_335 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_286 == V_19 )
continue;
if ( V_286 -> V_62 & V_63 )
continue;
if ( ! F_53 ( V_286 , V_73 ) )
F_330 ( V_286 , V_50 ,
V_50 + F_122 ( V_8 ) , V_74 ) ;
}
F_336 ( V_65 ) ;
}
static int F_337 ( struct V_248 * V_249 , struct V_18 * V_19 ,
unsigned long V_50 , T_9 * V_262 ,
struct V_74 * V_288 , T_11 * V_284 )
{
T_9 V_263 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_74 * V_289 , * V_290 ;
int V_13 = 0 , V_291 = 0 ;
unsigned long V_272 ;
unsigned long V_273 ;
V_263 = F_285 ( V_262 ) ;
V_289 = F_309 ( V_263 ) ;
V_292:
if ( F_134 ( V_289 ) == 1 && F_338 ( V_289 ) ) {
F_339 ( V_289 , V_19 ) ;
F_284 ( V_19 , V_50 , V_262 ) ;
return 0 ;
}
if ( F_53 ( V_19 , V_73 ) &&
V_289 != V_288 )
V_291 = 1 ;
F_310 ( V_289 ) ;
F_2 ( V_284 ) ;
V_290 = F_183 ( V_19 , V_50 , V_291 ) ;
if ( F_189 ( V_290 ) ) {
if ( V_291 ) {
F_139 ( V_289 ) ;
F_10 ( F_289 ( V_263 ) ) ;
F_333 ( V_249 , V_19 , V_289 , V_50 ) ;
F_10 ( F_289 ( V_263 ) ) ;
F_9 ( V_284 ) ;
V_262 = F_298 ( V_249 , V_50 & F_316 ( V_8 ) ,
F_122 ( V_8 ) ) ;
if ( F_340 ( V_262 &&
F_341 ( F_285 ( V_262 ) , V_263 ) ) )
goto V_292;
return 0 ;
}
V_13 = ( F_342 ( V_290 ) == - V_14 ) ?
V_293 : V_294 ;
goto V_295;
}
if ( F_68 ( F_343 ( V_19 ) ) ) {
V_13 = V_293 ;
goto V_296;
}
F_344 ( V_290 , V_289 , V_50 , V_19 ,
F_115 ( V_8 ) ) ;
F_345 ( V_290 ) ;
F_126 ( V_290 ) ;
V_272 = V_50 & F_316 ( V_8 ) ;
V_273 = V_272 + F_122 ( V_8 ) ;
F_297 ( V_249 , V_272 , V_273 ) ;
F_9 ( V_284 ) ;
V_262 = F_298 ( V_249 , V_50 & F_316 ( V_8 ) ,
F_122 ( V_8 ) ) ;
if ( F_340 ( V_262 && F_341 ( F_285 ( V_262 ) , V_263 ) ) ) {
F_129 ( V_290 ) ;
F_346 ( V_19 , V_50 , V_262 ) ;
F_308 ( V_249 , V_272 , V_273 ) ;
F_312 ( V_249 , V_50 , V_262 ,
F_276 ( V_19 , V_290 , 1 ) ) ;
F_326 ( V_289 , true ) ;
F_347 ( V_290 , V_19 , V_50 ) ;
V_290 = V_289 ;
}
F_2 ( V_284 ) ;
F_314 ( V_249 , V_272 , V_273 ) ;
V_296:
F_182 ( V_8 , V_19 , V_50 , V_290 ) ;
F_139 ( V_290 ) ;
V_295:
F_139 ( V_289 ) ;
F_9 ( V_284 ) ;
return V_13 ;
}
static struct V_74 * F_348 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_50 )
{
struct V_64 * V_65 ;
T_1 V_162 ;
V_65 = V_19 -> V_20 -> V_66 ;
V_162 = F_34 ( V_8 , V_19 , V_50 ) ;
return F_349 ( V_65 , V_162 ) ;
}
static bool F_350 ( struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned long V_50 )
{
struct V_64 * V_65 ;
T_1 V_162 ;
struct V_74 * V_74 ;
V_65 = V_19 -> V_20 -> V_66 ;
V_162 = F_34 ( V_8 , V_19 , V_50 ) ;
V_74 = F_351 ( V_65 , V_162 ) ;
if ( V_74 )
F_139 ( V_74 ) ;
return V_74 != NULL ;
}
int F_352 ( struct V_74 * V_74 , struct V_64 * V_65 ,
T_1 V_162 )
{
struct V_16 * V_16 = V_65 -> V_67 ;
struct V_7 * V_8 = F_30 ( V_16 ) ;
int V_98 = F_353 ( V_74 , V_65 , V_162 , V_10 ) ;
if ( V_98 )
return V_98 ;
F_129 ( V_74 ) ;
F_9 ( & V_16 -> V_297 ) ;
V_16 -> V_298 += F_354 ( V_8 ) ;
F_2 ( & V_16 -> V_297 ) ;
return 0 ;
}
static int F_355 ( struct V_248 * V_249 , struct V_18 * V_19 ,
struct V_64 * V_65 , T_1 V_162 ,
unsigned long V_50 , T_9 * V_262 , unsigned int V_70 )
{
struct V_7 * V_8 = F_38 ( V_19 ) ;
int V_13 = V_294 ;
int V_299 = 0 ;
unsigned long V_125 ;
struct V_74 * V_74 ;
T_9 V_300 ;
T_11 * V_284 ;
if ( F_53 ( V_19 , V_285 ) ) {
F_356 ( L_24 ,
V_188 -> V_301 ) ;
return V_13 ;
}
V_42:
V_74 = F_349 ( V_65 , V_162 ) ;
if ( ! V_74 ) {
V_125 = F_357 ( V_65 -> V_67 ) >> F_35 ( V_8 ) ;
if ( V_162 >= V_125 )
goto V_45;
if ( F_358 ( V_19 ) ) {
T_12 V_302 ;
struct V_257 V_258 = {
. V_19 = V_19 ,
. V_50 = V_50 ,
. V_70 = V_70 ,
} ;
V_302 = F_359 ( V_8 , V_249 , V_19 , V_65 ,
V_162 , V_50 ) ;
F_360 ( & V_225 [ V_302 ] ) ;
V_13 = F_361 ( & V_258 , V_303 ) ;
F_362 ( & V_225 [ V_302 ] ) ;
goto V_45;
}
V_74 = F_183 ( V_19 , V_50 , 0 ) ;
if ( F_189 ( V_74 ) ) {
V_13 = F_342 ( V_74 ) ;
if ( V_13 == - V_14 )
V_13 = V_293 ;
else
V_13 = V_294 ;
goto V_45;
}
F_363 ( V_74 , V_50 , F_115 ( V_8 ) ) ;
F_345 ( V_74 ) ;
F_126 ( V_74 ) ;
if ( V_19 -> V_62 & V_63 ) {
int V_98 = F_352 ( V_74 , V_65 , V_162 ) ;
if ( V_98 ) {
F_139 ( V_74 ) ;
if ( V_98 == - V_304 )
goto V_42;
goto V_45;
}
} else {
F_364 ( V_74 ) ;
if ( F_68 ( F_343 ( V_19 ) ) ) {
V_13 = V_293 ;
goto V_305;
}
V_299 = 1 ;
}
} else {
if ( F_68 ( F_60 ( V_74 ) ) ) {
V_13 = V_306 |
F_365 ( F_136 ( V_8 ) ) ;
goto V_305;
}
}
if ( ( V_70 & V_307 ) && ! ( V_19 -> V_62 & V_274 ) ) {
if ( F_178 ( V_8 , V_19 , V_50 ) < 0 ) {
V_13 = V_293 ;
goto V_305;
}
F_180 ( V_8 , V_19 , V_50 ) ;
}
V_284 = F_300 ( V_8 , V_249 , V_262 ) ;
V_125 = F_357 ( V_65 -> V_67 ) >> F_35 ( V_8 ) ;
if ( V_162 >= V_125 )
goto V_308;
V_13 = 0 ;
if ( ! F_289 ( F_285 ( V_262 ) ) )
goto V_308;
if ( V_299 ) {
F_129 ( V_74 ) ;
F_347 ( V_74 , V_19 , V_50 ) ;
} else
F_311 ( V_74 , true ) ;
V_300 = F_276 ( V_19 , V_74 , ( ( V_19 -> V_62 & V_309 )
&& ( V_19 -> V_62 & V_274 ) ) ) ;
F_312 ( V_249 , V_50 , V_262 , V_300 ) ;
F_313 ( F_115 ( V_8 ) , V_249 ) ;
if ( ( V_70 & V_307 ) && ! ( V_19 -> V_62 & V_274 ) ) {
V_13 = F_337 ( V_249 , V_19 , V_50 , V_262 , V_74 , V_284 ) ;
}
F_2 ( V_284 ) ;
F_366 ( V_74 ) ;
V_45:
return V_13 ;
V_308:
F_2 ( V_284 ) ;
V_305:
F_366 ( V_74 ) ;
F_182 ( V_8 , V_19 , V_50 , V_74 ) ;
F_139 ( V_74 ) ;
goto V_45;
}
T_12 F_359 ( struct V_7 * V_8 , struct V_248 * V_249 ,
struct V_18 * V_19 ,
struct V_64 * V_65 ,
T_1 V_162 , unsigned long V_50 )
{
unsigned long V_310 [ 2 ] ;
T_12 V_302 ;
if ( V_19 -> V_62 & V_274 ) {
V_310 [ 0 ] = ( unsigned long ) V_65 ;
V_310 [ 1 ] = V_162 ;
} else {
V_310 [ 0 ] = ( unsigned long ) V_249 ;
V_310 [ 1 ] = V_50 >> F_35 ( V_8 ) ;
}
V_302 = F_367 ( ( T_12 * ) & V_310 , sizeof( V_310 ) / sizeof( T_12 ) , 0 ) ;
return V_302 & ( V_224 - 1 ) ;
}
T_12 F_359 ( struct V_7 * V_8 , struct V_248 * V_249 ,
struct V_18 * V_19 ,
struct V_64 * V_65 ,
T_1 V_162 , unsigned long V_50 )
{
return 0 ;
}
int F_368 ( struct V_248 * V_249 , struct V_18 * V_19 ,
unsigned long V_50 , unsigned int V_70 )
{
T_9 * V_262 , V_260 ;
T_11 * V_284 ;
int V_13 ;
T_12 V_302 ;
T_1 V_162 ;
struct V_74 * V_74 = NULL ;
struct V_74 * V_288 = NULL ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
struct V_64 * V_65 ;
int V_311 = 0 ;
V_50 &= F_316 ( V_8 ) ;
V_262 = F_298 ( V_249 , V_50 , F_122 ( V_8 ) ) ;
if ( V_262 ) {
V_260 = F_285 ( V_262 ) ;
if ( F_68 ( F_288 ( V_260 ) ) ) {
F_369 ( V_19 , V_249 , V_262 ) ;
return 0 ;
} else if ( F_68 ( F_294 ( V_260 ) ) )
return V_312 |
F_365 ( F_136 ( V_8 ) ) ;
} else {
V_262 = F_299 ( V_249 , V_50 , F_122 ( V_8 ) ) ;
if ( ! V_262 )
return V_293 ;
}
V_65 = V_19 -> V_20 -> V_66 ;
V_162 = F_34 ( V_8 , V_19 , V_50 ) ;
V_302 = F_359 ( V_8 , V_249 , V_19 , V_65 , V_162 , V_50 ) ;
F_362 ( & V_225 [ V_302 ] ) ;
V_260 = F_285 ( V_262 ) ;
if ( F_289 ( V_260 ) ) {
V_13 = F_355 ( V_249 , V_19 , V_65 , V_162 , V_50 , V_262 , V_70 ) ;
goto V_313;
}
V_13 = 0 ;
if ( ! F_290 ( V_260 ) )
goto V_313;
if ( ( V_70 & V_307 ) && ! F_370 ( V_260 ) ) {
if ( F_178 ( V_8 , V_19 , V_50 ) < 0 ) {
V_13 = V_293 ;
goto V_313;
}
F_180 ( V_8 , V_19 , V_50 ) ;
if ( ! ( V_19 -> V_62 & V_63 ) )
V_288 = F_348 ( V_8 ,
V_19 , V_50 ) ;
}
V_284 = F_300 ( V_8 , V_249 , V_262 ) ;
if ( F_68 ( ! F_341 ( V_260 , F_285 ( V_262 ) ) ) )
goto V_314;
V_74 = F_309 ( V_260 ) ;
if ( V_74 != V_288 )
if ( ! F_371 ( V_74 ) ) {
V_311 = 1 ;
goto V_314;
}
F_310 ( V_74 ) ;
if ( V_70 & V_307 ) {
if ( ! F_370 ( V_260 ) ) {
V_13 = F_337 ( V_249 , V_19 , V_50 , V_262 ,
V_288 , V_284 ) ;
goto V_315;
}
V_260 = F_278 ( V_260 ) ;
}
V_260 = F_281 ( V_260 ) ;
if ( F_286 ( V_19 , V_50 , V_262 , V_260 ,
V_70 & V_307 ) )
F_287 ( V_19 , V_50 , V_262 ) ;
V_315:
if ( V_74 != V_288 )
F_366 ( V_74 ) ;
F_139 ( V_74 ) ;
V_314:
F_2 ( V_284 ) ;
if ( V_288 ) {
F_366 ( V_288 ) ;
F_139 ( V_288 ) ;
}
V_313:
F_360 ( & V_225 [ V_302 ] ) ;
if ( V_311 )
F_372 ( V_74 ) ;
return V_13 ;
}
int F_373 ( struct V_248 * V_316 ,
T_9 * V_268 ,
struct V_18 * V_317 ,
unsigned long V_318 ,
unsigned long V_319 ,
struct V_74 * * V_320 )
{
struct V_64 * V_65 ;
T_1 V_162 ;
unsigned long V_125 ;
int V_321 = V_317 -> V_62 & V_274 ;
struct V_7 * V_8 = F_38 ( V_317 ) ;
T_9 V_322 ;
T_11 * V_284 ;
int V_13 ;
struct V_74 * V_74 ;
if ( ! * V_320 ) {
V_13 = - V_14 ;
V_74 = F_183 ( V_317 , V_318 , 0 ) ;
if ( F_189 ( V_74 ) )
goto V_45;
V_13 = F_374 ( V_74 ,
( const void T_7 * ) V_319 ,
F_115 ( V_8 ) , false ) ;
if ( F_68 ( V_13 ) ) {
V_13 = - V_323 ;
* V_320 = V_74 ;
goto V_45;
}
} else {
V_74 = * V_320 ;
* V_320 = NULL ;
}
F_345 ( V_74 ) ;
F_126 ( V_74 ) ;
V_65 = V_317 -> V_20 -> V_66 ;
V_162 = F_34 ( V_8 , V_317 , V_318 ) ;
if ( V_321 ) {
V_125 = F_357 ( V_65 -> V_67 ) >> F_35 ( V_8 ) ;
V_13 = - V_323 ;
if ( V_162 >= V_125 )
goto V_324;
V_13 = F_352 ( V_74 , V_65 , V_162 ) ;
if ( V_13 )
goto V_324;
}
V_284 = F_301 ( V_8 , V_316 , V_268 ) ;
F_9 ( V_284 ) ;
V_125 = F_357 ( V_65 -> V_67 ) >> F_35 ( V_8 ) ;
V_13 = - V_323 ;
if ( V_162 >= V_125 )
goto V_325;
V_13 = - V_304 ;
if ( ! F_289 ( F_285 ( V_268 ) ) )
goto V_325;
if ( V_321 ) {
F_311 ( V_74 , true ) ;
} else {
F_129 ( V_74 ) ;
F_347 ( V_74 , V_317 , V_318 ) ;
}
V_322 = F_276 ( V_317 , V_74 , V_317 -> V_62 & V_309 ) ;
if ( V_317 -> V_62 & V_309 )
V_322 = F_278 ( V_322 ) ;
V_322 = F_281 ( V_322 ) ;
F_312 ( V_316 , V_318 , V_268 , V_322 ) ;
( void ) F_286 ( V_317 , V_318 , V_268 , V_322 ,
V_317 -> V_62 & V_309 ) ;
F_313 ( F_115 ( V_8 ) , V_316 ) ;
F_287 ( V_317 , V_318 , V_268 ) ;
F_2 ( V_284 ) ;
if ( V_321 )
F_366 ( V_74 ) ;
V_13 = 0 ;
V_45:
return V_13 ;
V_325:
F_2 ( V_284 ) ;
if ( V_321 )
F_366 ( V_74 ) ;
V_324:
F_139 ( V_74 ) ;
goto V_45;
}
long F_375 ( struct V_248 * V_249 , struct V_18 * V_19 ,
struct V_74 * * V_326 , struct V_18 * * V_327 ,
unsigned long * V_328 , unsigned long * V_105 ,
long V_104 , unsigned int V_70 , int * V_329 )
{
unsigned long V_330 ;
unsigned long V_331 = * V_328 ;
unsigned long V_332 = * V_105 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
int V_98 = - V_323 ;
while ( V_331 < V_19 -> V_256 && V_332 ) {
T_9 * V_263 ;
T_11 * V_284 = NULL ;
int V_333 ;
struct V_74 * V_74 ;
if ( F_68 ( F_376 ( V_188 ) ) ) {
V_332 = 0 ;
break;
}
V_263 = F_298 ( V_249 , V_331 & F_316 ( V_8 ) ,
F_122 ( V_8 ) ) ;
if ( V_263 )
V_284 = F_300 ( V_8 , V_249 , V_263 ) ;
V_333 = ! V_263 || F_289 ( F_285 ( V_263 ) ) ;
if ( V_333 && ( V_70 & V_334 ) &&
! F_350 ( V_8 , V_19 , V_331 ) ) {
if ( V_263 )
F_2 ( V_284 ) ;
V_332 = 0 ;
break;
}
if ( V_333 || F_377 ( F_285 ( V_263 ) ) ||
( ( V_70 & V_335 ) &&
! F_370 ( F_285 ( V_263 ) ) ) ) {
int V_13 ;
unsigned int V_336 = 0 ;
if ( V_263 )
F_2 ( V_284 ) ;
if ( V_70 & V_335 )
V_336 |= V_307 ;
if ( V_329 )
V_336 |= V_337 ;
if ( V_70 & V_338 )
V_336 |= V_337 |
V_339 ;
if ( V_70 & V_340 ) {
F_378 ( V_336 &
V_337 ) ;
V_336 |= V_341 ;
}
V_13 = F_368 ( V_249 , V_19 , V_331 , V_336 ) ;
if ( V_13 & V_342 ) {
V_98 = F_379 ( V_13 , V_70 ) ;
V_332 = 0 ;
break;
}
if ( V_13 & V_343 ) {
if ( V_329 )
* V_329 = 0 ;
* V_105 = 0 ;
return V_104 ;
}
continue;
}
V_330 = ( V_331 & ~ F_316 ( V_8 ) ) >> V_182 ;
V_74 = F_309 ( F_285 ( V_263 ) ) ;
V_344:
if ( V_326 ) {
V_326 [ V_104 ] = F_380 ( V_74 , V_330 ) ;
F_310 ( V_326 [ V_104 ] ) ;
}
if ( V_327 )
V_327 [ V_104 ] = V_19 ;
V_331 += V_53 ;
++ V_330 ;
-- V_332 ;
++ V_104 ;
if ( V_331 < V_19 -> V_256 && V_332 &&
V_330 < F_115 ( V_8 ) ) {
goto V_344;
}
F_2 ( V_284 ) ;
}
* V_105 = V_332 ;
* V_328 = V_331 ;
return V_104 ? V_104 : V_98 ;
}
unsigned long F_381 ( struct V_18 * V_19 ,
unsigned long V_50 , unsigned long V_254 , T_13 V_345 )
{
struct V_248 * V_249 = V_19 -> V_283 ;
unsigned long V_253 = V_50 ;
T_9 * V_262 ;
T_9 V_263 ;
struct V_7 * V_8 = F_38 ( V_19 ) ;
unsigned long V_326 = 0 ;
F_10 ( V_50 >= V_254 ) ;
F_382 ( V_19 , V_50 , V_254 ) ;
F_297 ( V_249 , V_253 , V_254 ) ;
F_334 ( V_19 -> V_20 -> V_66 ) ;
for (; V_50 < V_254 ; V_50 += F_122 ( V_8 ) ) {
T_11 * V_284 ;
V_262 = F_298 ( V_249 , V_50 , F_122 ( V_8 ) ) ;
if ( ! V_262 )
continue;
V_284 = F_300 ( V_8 , V_249 , V_262 ) ;
if ( F_319 ( V_249 , & V_50 , V_262 ) ) {
V_326 ++ ;
F_2 ( V_284 ) ;
continue;
}
V_263 = F_285 ( V_262 ) ;
if ( F_68 ( F_294 ( V_263 ) ) ) {
F_2 ( V_284 ) ;
continue;
}
if ( F_68 ( F_288 ( V_263 ) ) ) {
T_10 V_260 = F_291 ( V_263 ) ;
if ( F_303 ( V_260 ) ) {
T_9 V_346 ;
F_304 ( & V_260 ) ;
V_346 = F_305 ( V_260 ) ;
F_306 ( V_249 , V_50 , V_262 ,
V_346 , F_122 ( V_8 ) ) ;
V_326 ++ ;
}
F_2 ( V_284 ) ;
continue;
}
if ( ! F_289 ( V_263 ) ) {
V_263 = F_321 ( V_249 , V_50 , V_262 ) ;
V_263 = F_282 ( F_383 ( V_263 , V_345 ) ) ;
V_263 = F_283 ( V_263 , V_19 , NULL , 0 ) ;
F_312 ( V_249 , V_50 , V_262 , V_263 ) ;
V_326 ++ ;
}
F_2 ( V_284 ) ;
}
F_384 ( V_19 , V_253 , V_254 ) ;
F_308 ( V_249 , V_253 , V_254 ) ;
F_336 ( V_19 -> V_20 -> V_66 ) ;
F_314 ( V_249 , V_253 , V_254 ) ;
return V_326 << V_8 -> V_103 ;
}
int F_385 ( struct V_16 * V_16 ,
long V_35 , long V_33 ,
struct V_18 * V_19 ,
T_14 V_62 )
{
long V_13 , V_41 ;
struct V_7 * V_8 = F_30 ( V_16 ) ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
struct V_21 * V_21 ;
long V_255 ;
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
goto V_347;
}
V_255 = F_11 ( V_2 , V_41 ) ;
if ( V_255 < 0 ) {
V_13 = - V_172 ;
goto V_347;
}
V_13 = F_3 ( V_8 , V_255 ) ;
if ( V_13 < 0 ) {
( void ) F_12 ( V_2 , V_41 ) ;
goto V_347;
}
if ( ! V_19 || V_19 -> V_62 & V_63 ) {
long V_32 = F_17 ( V_21 , V_35 , V_33 ) ;
if ( F_68 ( V_41 > V_32 ) ) {
long V_47 ;
V_47 = F_12 ( V_2 ,
V_41 - V_32 ) ;
F_3 ( V_8 , - V_47 ) ;
}
}
return 0 ;
V_347:
if ( ! V_19 || V_19 -> V_62 & V_63 )
if ( V_41 >= 0 )
F_27 ( V_21 , V_35 , V_33 ) ;
if ( V_19 && F_53 ( V_19 , V_73 ) )
F_274 ( & V_21 -> V_56 , F_46 ) ;
return V_13 ;
}
long F_386 ( struct V_16 * V_16 , long V_253 , long V_254 ,
long V_348 )
{
struct V_7 * V_8 = F_30 ( V_16 ) ;
struct V_21 * V_21 = F_48 ( V_16 ) ;
long V_41 = 0 ;
struct V_1 * V_2 = F_13 ( V_16 ) ;
long V_255 ;
if ( V_21 ) {
V_41 = F_28 ( V_21 , V_253 , V_254 ) ;
if ( V_41 < 0 )
return V_41 ;
}
F_9 ( & V_16 -> V_297 ) ;
V_16 -> V_298 -= ( F_354 ( V_8 ) * V_348 ) ;
F_2 ( & V_16 -> V_297 ) ;
V_255 = F_12 ( V_2 , ( V_41 - V_348 ) ) ;
F_3 ( V_8 , - V_255 ) ;
return 0 ;
}
static unsigned long F_387 ( struct V_18 * V_349 ,
struct V_18 * V_19 ,
unsigned long V_150 , T_1 V_162 )
{
unsigned long V_350 = ( ( V_162 - V_349 -> V_52 ) << V_182 ) +
V_349 -> V_51 ;
unsigned long V_351 = V_350 & V_352 ;
unsigned long V_353 = V_351 + V_354 ;
unsigned long V_62 = V_19 -> V_62 & V_355 ;
unsigned long V_356 = V_349 -> V_62 & V_355 ;
if ( F_388 ( V_150 ) != F_388 ( V_350 ) ||
V_62 != V_356 ||
V_351 < V_349 -> V_51 || V_349 -> V_256 < V_353 )
return 0 ;
return V_350 ;
}
static bool F_389 ( struct V_18 * V_19 , unsigned long V_150 )
{
unsigned long V_357 = V_150 & V_352 ;
unsigned long V_254 = V_357 + V_354 ;
if ( V_19 -> V_62 & V_63 &&
V_19 -> V_51 <= V_357 && V_254 <= V_19 -> V_256 )
return true ;
return false ;
}
T_9 * F_390 ( struct V_248 * V_249 , unsigned long V_150 , T_15 * V_358 )
{
struct V_18 * V_19 = F_391 ( V_249 , V_150 ) ;
struct V_64 * V_65 = V_19 -> V_20 -> V_66 ;
T_1 V_162 = ( ( V_150 - V_19 -> V_51 ) >> V_182 ) +
V_19 -> V_52 ;
struct V_18 * V_349 ;
unsigned long V_350 ;
T_9 * V_359 = NULL ;
T_9 * V_263 ;
T_11 * V_284 ;
if ( ! F_389 ( V_19 , V_150 ) )
return ( T_9 * ) F_392 ( V_249 , V_358 , V_150 ) ;
F_334 ( V_65 ) ;
F_335 (svma, &mapping->i_mmap, idx, idx) {
if ( V_349 == V_19 )
continue;
V_350 = F_387 ( V_349 , V_19 , V_150 , V_162 ) ;
if ( V_350 ) {
V_359 = F_298 ( V_349 -> V_283 , V_350 ,
F_41 ( V_349 ) ) ;
if ( V_359 ) {
F_310 ( F_200 ( V_359 ) ) ;
break;
}
}
}
if ( ! V_359 )
goto V_45;
V_284 = F_300 ( F_38 ( V_19 ) , V_249 , V_359 ) ;
if ( F_393 ( * V_358 ) ) {
F_394 ( V_249 , V_358 ,
( V_360 * ) ( ( unsigned long ) V_359 & V_361 ) ) ;
F_395 ( V_249 ) ;
} else {
F_139 ( F_200 ( V_359 ) ) ;
}
F_2 ( V_284 ) ;
V_45:
V_263 = ( T_9 * ) F_392 ( V_249 , V_358 , V_150 ) ;
F_336 ( V_65 ) ;
return V_263 ;
}
int F_319 ( struct V_248 * V_249 , unsigned long * V_150 , T_9 * V_262 )
{
T_16 * V_362 = F_396 ( V_249 , * V_150 ) ;
T_17 * V_363 = F_397 ( V_362 , * V_150 ) ;
T_15 * V_358 = F_398 ( V_363 , * V_150 ) ;
F_10 ( F_99 ( F_200 ( V_262 ) ) == 0 ) ;
if ( F_99 ( F_200 ( V_262 ) ) == 1 )
return 0 ;
F_399 ( V_358 ) ;
F_139 ( F_200 ( V_262 ) ) ;
F_400 ( V_249 ) ;
* V_150 = F_105 ( * V_150 , V_219 * V_364 ) - V_219 ;
return 1 ;
}
T_9 * F_390 ( struct V_248 * V_249 , unsigned long V_150 , T_15 * V_358 )
{
return NULL ;
}
int F_319 ( struct V_248 * V_249 , unsigned long * V_150 , T_9 * V_262 )
{
return 0 ;
}
T_9 * F_299 ( struct V_248 * V_249 ,
unsigned long V_150 , unsigned long V_271 )
{
T_16 * V_362 ;
T_17 * V_363 ;
T_15 * V_358 ;
T_9 * V_263 = NULL ;
V_362 = F_396 ( V_249 , V_150 ) ;
V_363 = F_397 ( V_362 , V_150 ) ;
V_358 = F_401 ( V_249 , V_363 , V_150 ) ;
if ( V_358 ) {
if ( V_271 == V_354 ) {
V_263 = ( T_9 * ) V_358 ;
} else {
F_10 ( V_271 != V_365 ) ;
if ( F_402 () && F_393 ( * V_358 ) )
V_263 = F_390 ( V_249 , V_150 , V_358 ) ;
else
V_263 = ( T_9 * ) F_392 ( V_249 , V_358 , V_150 ) ;
}
}
F_10 ( V_263 && F_290 ( * V_263 ) && ! F_403 ( * V_263 ) ) ;
return V_263 ;
}
T_9 * F_298 ( struct V_248 * V_249 ,
unsigned long V_150 , unsigned long V_271 )
{
T_16 * V_362 ;
T_17 * V_363 ;
T_15 * V_358 ;
V_360 * V_366 ;
V_362 = F_396 ( V_249 , V_150 ) ;
if ( ! F_404 ( * V_362 ) )
return NULL ;
V_363 = F_397 ( V_362 , V_150 ) ;
if ( ! F_405 ( * V_363 ) )
return NULL ;
V_358 = F_398 ( V_363 , V_150 ) ;
if ( V_271 != V_354 && F_393 ( * V_358 ) )
return NULL ;
if ( F_406 ( * V_358 ) || ! F_407 ( * V_358 ) )
return ( T_9 * ) V_358 ;
V_366 = F_408 ( V_358 , V_150 ) ;
if ( V_271 != V_365 && F_409 ( * V_366 ) )
return NULL ;
if ( F_410 ( * V_366 ) || ! F_411 ( * V_366 ) )
return ( T_9 * ) V_366 ;
return NULL ;
}
struct V_74 * __weak
F_412 ( struct V_248 * V_249 , unsigned long V_50 ,
int V_240 )
{
return F_184 ( - V_200 ) ;
}
struct V_74 * __weak
F_413 ( struct V_18 * V_19 ,
unsigned long V_50 , T_18 V_367 , int V_70 , int V_368 )
{
F_414 ( 1 , L_25 ) ;
return NULL ;
}
struct V_74 * __weak
F_415 ( struct V_248 * V_249 , unsigned long V_50 ,
V_360 * V_366 , int V_70 )
{
struct V_74 * V_74 = NULL ;
T_11 * V_284 ;
T_9 V_263 ;
V_42:
V_284 = F_416 ( V_249 , V_366 ) ;
F_9 ( V_284 ) ;
if ( ! F_410 ( * V_366 ) )
goto V_45;
V_263 = F_285 ( ( T_9 * ) V_366 ) ;
if ( F_290 ( V_263 ) ) {
V_74 = F_417 ( * V_366 ) + ( ( V_50 & ~ V_369 ) >> V_182 ) ;
if ( V_70 & V_370 )
F_310 ( V_74 ) ;
} else {
if ( F_288 ( V_263 ) ) {
F_2 ( V_284 ) ;
F_418 ( V_249 , ( T_9 * ) V_366 , V_284 ) ;
goto V_42;
}
}
V_45:
F_2 ( V_284 ) ;
return V_74 ;
}
struct V_74 * __weak
F_419 ( struct V_248 * V_249 , unsigned long V_50 ,
T_15 * V_358 , int V_70 )
{
if ( V_70 & V_370 )
return NULL ;
return F_309 ( * ( T_9 * ) V_358 ) + ( ( V_50 & ~ V_352 ) >> V_182 ) ;
}
struct V_74 * __weak
F_420 ( struct V_248 * V_249 , unsigned long V_50 , T_16 * V_362 , int V_70 )
{
if ( V_70 & V_370 )
return NULL ;
return F_309 ( * ( T_9 * ) V_362 ) + ( ( V_50 & ~ V_371 ) >> V_182 ) ;
}
bool F_421 ( struct V_74 * V_74 , struct V_25 * V_179 )
{
bool V_13 = true ;
F_116 ( ! F_124 ( V_74 ) , V_74 ) ;
F_9 ( & V_127 ) ;
if ( ! F_123 ( V_74 ) || ! F_422 ( V_74 ) ) {
V_13 = false ;
goto V_372;
}
F_128 ( V_74 ) ;
F_423 ( & V_74 -> V_76 , V_179 ) ;
V_372:
F_2 ( & V_127 ) ;
return V_13 ;
}
void F_424 ( struct V_74 * V_74 )
{
F_116 ( ! F_124 ( V_74 ) , V_74 ) ;
F_9 ( & V_127 ) ;
F_126 ( V_74 ) ;
F_423 ( & V_74 -> V_76 , & ( F_131 ( V_74 ) ) -> V_80 ) ;
F_2 ( & V_127 ) ;
F_139 ( V_74 ) ;
}
