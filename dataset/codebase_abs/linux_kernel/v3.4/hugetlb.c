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
return F_12 ( V_15 -> V_16 -> V_17 -> V_18 ) ;
}
static long F_15 ( struct V_19 * V_20 , long V_21 , long V_22 )
{
struct V_23 * V_24 , * V_25 , * V_26 ;
F_16 (rg, head, link)
if ( V_21 <= V_24 -> V_27 )
break;
if ( V_21 > V_24 -> V_28 )
V_21 = V_24 -> V_28 ;
V_25 = V_24 ;
F_17 (rg, trg, rg->link.prev, link) {
if ( & V_24 -> V_29 == V_20 )
break;
if ( V_24 -> V_28 > V_22 )
break;
if ( V_24 -> V_27 > V_22 )
V_22 = V_24 -> V_27 ;
if ( V_24 != V_25 ) {
F_18 ( & V_24 -> V_29 ) ;
F_3 ( V_24 ) ;
}
}
V_25 -> V_28 = V_21 ;
V_25 -> V_27 = V_22 ;
return 0 ;
}
static long F_19 ( struct V_19 * V_20 , long V_21 , long V_22 )
{
struct V_23 * V_24 , * V_25 ;
long V_30 = 0 ;
F_16 (rg, head, link)
if ( V_21 <= V_24 -> V_27 )
break;
if ( & V_24 -> V_29 == V_20 || V_22 < V_24 -> V_28 ) {
V_25 = F_5 ( sizeof( * V_25 ) , V_7 ) ;
if ( ! V_25 )
return - V_11 ;
V_25 -> V_28 = V_21 ;
V_25 -> V_27 = V_21 ;
F_20 ( & V_25 -> V_29 ) ;
F_21 ( & V_25 -> V_29 , V_24 -> V_29 . V_31 ) ;
return V_22 - V_21 ;
}
if ( V_21 > V_24 -> V_28 )
V_21 = V_24 -> V_28 ;
V_30 = V_22 - V_21 ;
F_16 (rg, rg->link.prev, link) {
if ( & V_24 -> V_29 == V_20 )
break;
if ( V_24 -> V_28 > V_22 )
return V_30 ;
if ( V_24 -> V_27 > V_22 ) {
V_30 += V_24 -> V_27 - V_22 ;
V_22 = V_24 -> V_27 ;
}
V_30 -= V_24 -> V_27 - V_24 -> V_28 ;
}
return V_30 ;
}
static long F_22 ( struct V_19 * V_20 , long V_32 )
{
struct V_23 * V_24 , * V_26 ;
long V_30 = 0 ;
F_16 (rg, head, link)
if ( V_32 <= V_24 -> V_27 )
break;
if ( & V_24 -> V_29 == V_20 )
return 0 ;
if ( V_32 > V_24 -> V_28 ) {
V_30 = V_24 -> V_27 - V_32 ;
V_24 -> V_27 = V_32 ;
V_24 = F_23 ( V_24 -> V_29 . V_33 , F_24 ( * V_24 ) , V_29 ) ;
}
F_17 (rg, trg, rg->link.prev, link) {
if ( & V_24 -> V_29 == V_20 )
break;
V_30 += V_24 -> V_27 - V_24 -> V_28 ;
F_18 ( & V_24 -> V_29 ) ;
F_3 ( V_24 ) ;
}
return V_30 ;
}
static long F_25 ( struct V_19 * V_20 , long V_21 , long V_22 )
{
struct V_23 * V_24 ;
long V_30 = 0 ;
F_16 (rg, head, link) {
int V_34 ;
int V_35 ;
if ( V_24 -> V_27 <= V_21 )
continue;
if ( V_24 -> V_28 >= V_22 )
break;
V_34 = F_26 ( V_24 -> V_28 , V_21 ) ;
V_35 = F_27 ( V_24 -> V_27 , V_22 ) ;
V_30 += V_35 - V_34 ;
}
return V_30 ;
}
static T_1 F_28 ( struct V_36 * V_37 ,
struct V_14 * V_15 , unsigned long V_38 )
{
return ( ( V_38 - V_15 -> V_39 ) >> F_29 ( V_37 ) ) +
( V_15 -> V_40 >> F_30 ( V_37 ) ) ;
}
T_1 F_31 ( struct V_14 * V_15 ,
unsigned long V_38 )
{
return F_28 ( F_32 ( V_15 ) , V_15 , V_38 ) ;
}
unsigned long F_33 ( struct V_14 * V_15 )
{
struct V_36 * V_36 ;
if ( ! F_34 ( V_15 ) )
return V_41 ;
V_36 = F_32 ( V_15 ) ;
return 1UL << ( V_36 -> V_42 + V_43 ) ;
}
unsigned long F_35 ( struct V_14 * V_15 )
{
return F_33 ( V_15 ) ;
}
static unsigned long F_36 ( struct V_14 * V_15 )
{
return ( unsigned long ) V_15 -> V_44 ;
}
static void F_37 ( struct V_14 * V_15 ,
unsigned long V_45 )
{
V_15 -> V_44 = ( void * ) V_45 ;
}
static struct V_46 * F_38 ( void )
{
struct V_46 * V_46 = F_5 ( sizeof( * V_46 ) , V_7 ) ;
if ( ! V_46 )
return NULL ;
F_39 ( & V_46 -> V_47 ) ;
F_20 ( & V_46 -> V_48 ) ;
return V_46 ;
}
static void F_40 ( struct V_49 * V_50 )
{
struct V_46 * V_46 = F_41 ( V_50 , struct V_46 , V_47 ) ;
F_22 ( & V_46 -> V_48 , 0 ) ;
F_3 ( V_46 ) ;
}
static struct V_46 * F_42 ( struct V_14 * V_15 )
{
F_43 ( ! F_34 ( V_15 ) ) ;
if ( ! ( V_15 -> V_51 & V_52 ) )
return (struct V_46 * ) ( F_36 ( V_15 ) &
~ V_53 ) ;
return NULL ;
}
static void F_44 ( struct V_14 * V_15 , struct V_46 * V_54 )
{
F_43 ( ! F_34 ( V_15 ) ) ;
F_43 ( V_15 -> V_51 & V_52 ) ;
F_37 ( V_15 , ( F_36 ( V_15 ) &
V_53 ) | ( unsigned long ) V_54 ) ;
}
static void F_45 ( struct V_14 * V_15 , unsigned long V_55 )
{
F_43 ( ! F_34 ( V_15 ) ) ;
F_43 ( V_15 -> V_51 & V_52 ) ;
F_37 ( V_15 , F_36 ( V_15 ) | V_55 ) ;
}
static int F_46 ( struct V_14 * V_15 , unsigned long V_56 )
{
F_43 ( ! F_34 ( V_15 ) ) ;
return ( F_36 ( V_15 ) & V_56 ) != 0 ;
}
static void F_47 ( struct V_36 * V_37 ,
struct V_14 * V_15 )
{
if ( V_15 -> V_51 & V_57 )
return;
if ( V_15 -> V_51 & V_52 ) {
V_37 -> V_58 -- ;
} else if ( F_46 ( V_15 , V_59 ) ) {
V_37 -> V_58 -- ;
}
}
void F_48 ( struct V_14 * V_15 )
{
F_43 ( ! F_34 ( V_15 ) ) ;
if ( ! ( V_15 -> V_51 & V_52 ) )
V_15 -> V_44 = ( void * ) 0 ;
}
static int F_49 ( struct V_14 * V_15 )
{
if ( V_15 -> V_51 & V_52 )
return 1 ;
if ( F_46 ( V_15 , V_59 ) )
return 1 ;
return 0 ;
}
static void F_50 ( struct V_60 * V_61 , struct V_60 * V_62 )
{
int V_63 ;
struct V_36 * V_37 = F_51 ( V_62 ) ;
struct V_60 * V_64 = V_61 ;
struct V_60 * V_65 = V_62 ;
for ( V_63 = 0 ; V_63 < F_52 ( V_37 ) ; ) {
F_53 () ;
F_54 ( V_61 , V_62 ) ;
V_63 ++ ;
V_61 = F_55 ( V_61 , V_64 , V_63 ) ;
V_62 = F_55 ( V_62 , V_65 , V_63 ) ;
}
}
void F_56 ( struct V_60 * V_61 , struct V_60 * V_62 )
{
int V_63 ;
struct V_36 * V_37 = F_51 ( V_62 ) ;
if ( F_57 ( F_52 ( V_37 ) > V_66 ) ) {
F_50 ( V_61 , V_62 ) ;
return;
}
F_58 () ;
for ( V_63 = 0 ; V_63 < F_52 ( V_37 ) ; V_63 ++ ) {
F_53 () ;
F_54 ( V_61 + V_63 , V_62 + V_63 ) ;
}
}
static void F_59 ( struct V_36 * V_37 , struct V_60 * V_60 )
{
int V_67 = F_60 ( V_60 ) ;
F_21 ( & V_60 -> V_68 , & V_37 -> V_69 [ V_67 ] ) ;
V_37 -> V_70 ++ ;
V_37 -> V_71 [ V_67 ] ++ ;
}
static struct V_60 * F_61 ( struct V_36 * V_37 , int V_67 )
{
struct V_60 * V_60 ;
if ( F_62 ( & V_37 -> V_69 [ V_67 ] ) )
return NULL ;
V_60 = F_23 ( V_37 -> V_69 [ V_67 ] . V_33 , struct V_60 , V_68 ) ;
F_18 ( & V_60 -> V_68 ) ;
F_63 ( V_60 ) ;
V_37 -> V_70 -- ;
V_37 -> V_71 [ V_67 ] -- ;
return V_60 ;
}
static struct V_60 * F_64 ( struct V_36 * V_37 ,
struct V_14 * V_15 ,
unsigned long V_38 , int V_72 )
{
struct V_60 * V_60 = NULL ;
struct V_73 * V_74 ;
T_2 * V_75 ;
struct V_76 * V_76 ;
struct V_77 * V_77 ;
struct V_78 * V_79 ;
unsigned int V_80 ;
V_81:
V_80 = F_65 () ;
V_76 = F_66 ( V_15 , V_38 ,
V_82 , & V_74 , & V_75 ) ;
if ( ! F_49 ( V_15 ) &&
V_37 -> V_70 - V_37 -> V_58 == 0 )
goto V_83;
if ( V_72 && V_37 -> V_70 - V_37 -> V_58 == 0 )
goto V_83;
F_67 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_68 ( V_77 , V_82 ) ) {
V_60 = F_61 ( V_37 , F_69 ( V_77 ) ) ;
if ( V_60 ) {
if ( ! V_72 )
F_47 ( V_37 , V_15 ) ;
break;
}
}
}
F_70 ( V_74 ) ;
if ( F_57 ( ! F_71 ( V_80 ) && ! V_60 ) )
goto V_81;
return V_60 ;
V_83:
F_70 ( V_74 ) ;
return NULL ;
}
static void F_72 ( struct V_36 * V_37 , struct V_60 * V_60 )
{
int V_63 ;
F_43 ( V_37 -> V_42 >= V_84 ) ;
V_37 -> V_85 -- ;
V_37 -> V_86 [ F_60 ( V_60 ) ] -- ;
for ( V_63 = 0 ; V_63 < F_52 ( V_37 ) ; V_63 ++ ) {
V_60 [ V_63 ] . V_55 &= ~ ( 1 << V_87 | 1 << V_88 |
1 << V_89 | 1 << V_90 |
1 << V_91 | 1 << V_92 |
1 << V_93 | 1 << V_94 ) ;
}
F_73 ( V_60 , NULL ) ;
F_63 ( V_60 ) ;
F_74 ( V_60 ) ;
F_75 ( V_60 , F_30 ( V_37 ) ) ;
}
struct V_36 * F_76 ( unsigned long V_95 )
{
struct V_36 * V_37 ;
F_77 (h) {
if ( F_78 ( V_37 ) == V_95 )
return V_37 ;
}
return NULL ;
}
static void F_79 ( struct V_60 * V_60 )
{
struct V_36 * V_37 = F_51 ( V_60 ) ;
int V_67 = F_60 ( V_60 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_80 ( V_60 ) ;
F_81 ( V_60 , 0 ) ;
V_60 -> V_96 = NULL ;
F_9 ( F_82 ( V_60 ) ) ;
F_9 ( F_83 ( V_60 ) ) ;
F_20 ( & V_60 -> V_68 ) ;
F_8 ( & V_97 ) ;
if ( V_37 -> V_98 [ V_67 ] && F_30 ( V_37 ) < V_84 ) {
F_72 ( V_37 , V_60 ) ;
V_37 -> V_99 -- ;
V_37 -> V_98 [ V_67 ] -- ;
} else {
F_59 ( V_37 , V_60 ) ;
}
F_2 ( & V_97 ) ;
F_11 ( V_2 , 1 ) ;
}
static void F_84 ( struct V_36 * V_37 , struct V_60 * V_60 , int V_67 )
{
F_73 ( V_60 , F_79 ) ;
F_8 ( & V_97 ) ;
V_37 -> V_85 ++ ;
V_37 -> V_86 [ V_67 ] ++ ;
F_2 ( & V_97 ) ;
F_85 ( V_60 ) ;
}
static void F_86 ( struct V_60 * V_60 , unsigned long V_42 )
{
int V_63 ;
int V_100 = 1 << V_42 ;
struct V_60 * V_101 = V_60 + 1 ;
F_87 ( V_60 , V_42 ) ;
F_88 ( V_60 ) ;
for ( V_63 = 1 ; V_63 < V_100 ; V_63 ++ , V_101 = F_55 ( V_101 , V_60 , V_63 ) ) {
F_89 ( V_101 ) ;
F_90 ( V_101 , 0 ) ;
V_101 -> V_102 = V_60 ;
}
}
int F_91 ( struct V_60 * V_60 )
{
T_3 * V_103 ;
if ( ! F_92 ( V_60 ) )
return 0 ;
V_60 = F_93 ( V_60 ) ;
V_103 = F_94 ( V_60 ) ;
return V_103 == F_79 ;
}
static struct V_60 * F_95 ( struct V_36 * V_37 , int V_67 )
{
struct V_60 * V_60 ;
if ( V_37 -> V_42 >= V_84 )
return NULL ;
V_60 = F_96 ( V_67 ,
V_82 | V_104 | V_105 |
V_106 | V_107 ,
F_30 ( V_37 ) ) ;
if ( V_60 ) {
if ( F_97 ( V_60 ) ) {
F_75 ( V_60 , F_30 ( V_37 ) ) ;
return NULL ;
}
F_84 ( V_37 , V_60 , V_67 ) ;
}
return V_60 ;
}
static int F_98 ( int V_67 , T_2 * V_108 )
{
V_67 = F_99 ( V_67 , * V_108 ) ;
if ( V_67 == V_109 )
V_67 = F_100 ( * V_108 ) ;
F_43 ( V_67 >= V_109 ) ;
return V_67 ;
}
static int F_101 ( int V_67 , T_2 * V_108 )
{
if ( ! F_102 ( V_67 , * V_108 ) )
V_67 = F_98 ( V_67 , V_108 ) ;
return V_67 ;
}
static int F_103 ( struct V_36 * V_37 ,
T_2 * V_108 )
{
int V_67 ;
F_43 ( ! V_108 ) ;
V_67 = F_101 ( V_37 -> V_110 , V_108 ) ;
V_37 -> V_110 = F_98 ( V_67 , V_108 ) ;
return V_67 ;
}
static int F_104 ( struct V_36 * V_37 , T_2 * V_108 )
{
struct V_60 * V_60 ;
int V_111 ;
int V_112 ;
int V_10 = 0 ;
V_111 = F_103 ( V_37 , V_108 ) ;
V_112 = V_111 ;
do {
V_60 = F_95 ( V_37 , V_112 ) ;
if ( V_60 ) {
V_10 = 1 ;
break;
}
V_112 = F_103 ( V_37 , V_108 ) ;
} while ( V_112 != V_111 );
if ( V_10 )
F_105 ( V_113 ) ;
else
F_105 ( V_114 ) ;
return V_10 ;
}
static int F_106 ( struct V_36 * V_37 , T_2 * V_108 )
{
int V_67 ;
F_43 ( ! V_108 ) ;
V_67 = F_101 ( V_37 -> V_115 , V_108 ) ;
V_37 -> V_115 = F_98 ( V_67 , V_108 ) ;
return V_67 ;
}
static int F_107 ( struct V_36 * V_37 , T_2 * V_108 ,
bool V_116 )
{
int V_111 ;
int V_112 ;
int V_10 = 0 ;
V_111 = F_106 ( V_37 , V_108 ) ;
V_112 = V_111 ;
do {
if ( ( ! V_116 || V_37 -> V_98 [ V_112 ] ) &&
! F_62 ( & V_37 -> V_69 [ V_112 ] ) ) {
struct V_60 * V_60 =
F_23 ( V_37 -> V_69 [ V_112 ] . V_33 ,
struct V_60 , V_68 ) ;
F_18 ( & V_60 -> V_68 ) ;
V_37 -> V_70 -- ;
V_37 -> V_71 [ V_112 ] -- ;
if ( V_116 ) {
V_37 -> V_99 -- ;
V_37 -> V_98 [ V_112 ] -- ;
}
F_72 ( V_37 , V_60 ) ;
V_10 = 1 ;
break;
}
V_112 = F_106 ( V_37 , V_108 ) ;
} while ( V_112 != V_111 );
return V_10 ;
}
static struct V_60 * F_108 ( struct V_36 * V_37 , int V_67 )
{
struct V_60 * V_60 ;
unsigned int V_117 ;
if ( V_37 -> V_42 >= V_84 )
return NULL ;
F_8 ( & V_97 ) ;
if ( V_37 -> V_99 >= V_37 -> V_118 ) {
F_2 ( & V_97 ) ;
return NULL ;
} else {
V_37 -> V_85 ++ ;
V_37 -> V_99 ++ ;
}
F_2 ( & V_97 ) ;
if ( V_67 == V_119 )
V_60 = F_109 ( V_82 | V_104 |
V_106 | V_107 ,
F_30 ( V_37 ) ) ;
else
V_60 = F_96 ( V_67 ,
V_82 | V_104 | V_105 |
V_106 | V_107 , F_30 ( V_37 ) ) ;
if ( V_60 && F_97 ( V_60 ) ) {
F_75 ( V_60 , F_30 ( V_37 ) ) ;
V_60 = NULL ;
}
F_8 ( & V_97 ) ;
if ( V_60 ) {
V_117 = F_60 ( V_60 ) ;
F_73 ( V_60 , F_79 ) ;
V_37 -> V_86 [ V_117 ] ++ ;
V_37 -> V_98 [ V_117 ] ++ ;
F_110 ( V_113 ) ;
} else {
V_37 -> V_85 -- ;
V_37 -> V_99 -- ;
F_110 ( V_114 ) ;
}
F_2 ( & V_97 ) ;
return V_60 ;
}
struct V_60 * F_111 ( struct V_36 * V_37 , int V_67 )
{
struct V_60 * V_60 ;
F_8 ( & V_97 ) ;
V_60 = F_61 ( V_37 , V_67 ) ;
F_2 ( & V_97 ) ;
if ( ! V_60 )
V_60 = F_108 ( V_37 , V_67 ) ;
return V_60 ;
}
static int F_112 ( struct V_36 * V_37 , int V_9 )
{
struct V_19 V_120 ;
struct V_60 * V_60 , * V_121 ;
int V_10 , V_63 ;
int V_122 , V_123 ;
bool V_124 = true ;
V_122 = ( V_37 -> V_58 + V_9 ) - V_37 -> V_70 ;
if ( V_122 <= 0 ) {
V_37 -> V_58 += V_9 ;
return 0 ;
}
V_123 = 0 ;
F_20 ( & V_120 ) ;
V_10 = - V_11 ;
V_125:
F_2 ( & V_97 ) ;
for ( V_63 = 0 ; V_63 < V_122 ; V_63 ++ ) {
V_60 = F_108 ( V_37 , V_119 ) ;
if ( ! V_60 ) {
V_124 = false ;
break;
}
F_21 ( & V_60 -> V_68 , & V_120 ) ;
}
V_123 += V_63 ;
F_8 ( & V_97 ) ;
V_122 = ( V_37 -> V_58 + V_9 ) -
( V_37 -> V_70 + V_123 ) ;
if ( V_122 > 0 ) {
if ( V_124 )
goto V_125;
goto free;
}
V_122 += V_123 ;
V_37 -> V_58 += V_9 ;
V_10 = 0 ;
F_17 (page, tmp, &surplus_list, lru) {
if ( ( -- V_122 ) < 0 )
break;
F_18 ( & V_60 -> V_68 ) ;
F_113 ( V_60 ) ;
F_43 ( F_82 ( V_60 ) ) ;
F_59 ( V_37 , V_60 ) ;
}
free:
F_2 ( & V_97 ) ;
if ( ! F_62 ( & V_120 ) ) {
F_17 (page, tmp, &surplus_list, lru) {
F_18 ( & V_60 -> V_68 ) ;
F_85 ( V_60 ) ;
}
}
F_8 ( & V_97 ) ;
return V_10 ;
}
static void F_114 ( struct V_36 * V_37 ,
unsigned long V_126 )
{
unsigned long V_100 ;
V_37 -> V_58 -= V_126 ;
if ( V_37 -> V_42 >= V_84 )
return;
V_100 = F_27 ( V_126 , V_37 -> V_99 ) ;
while ( V_100 -- ) {
if ( ! F_107 ( V_37 , & V_127 [ V_128 ] , 1 ) )
break;
}
}
static long F_115 ( struct V_36 * V_37 ,
struct V_14 * V_15 , unsigned long V_129 )
{
struct V_130 * V_96 = V_15 -> V_16 -> V_131 ;
struct V_12 * V_12 = V_96 -> V_132 ;
if ( V_15 -> V_51 & V_52 ) {
T_1 V_133 = F_28 ( V_37 , V_15 , V_129 ) ;
return F_19 ( & V_12 -> V_134 -> V_135 ,
V_133 , V_133 + 1 ) ;
} else if ( ! F_46 ( V_15 , V_59 ) ) {
return 1 ;
} else {
long V_83 ;
T_1 V_133 = F_28 ( V_37 , V_15 , V_129 ) ;
struct V_46 * V_136 = F_42 ( V_15 ) ;
V_83 = F_19 ( & V_136 -> V_48 , V_133 , V_133 + 1 ) ;
if ( V_83 < 0 )
return V_83 ;
return 0 ;
}
}
static void F_116 ( struct V_36 * V_37 ,
struct V_14 * V_15 , unsigned long V_129 )
{
struct V_130 * V_96 = V_15 -> V_16 -> V_131 ;
struct V_12 * V_12 = V_96 -> V_132 ;
if ( V_15 -> V_51 & V_52 ) {
T_1 V_133 = F_28 ( V_37 , V_15 , V_129 ) ;
F_15 ( & V_12 -> V_134 -> V_135 , V_133 , V_133 + 1 ) ;
} else if ( F_46 ( V_15 , V_59 ) ) {
T_1 V_133 = F_28 ( V_37 , V_15 , V_129 ) ;
struct V_46 * V_136 = F_42 ( V_15 ) ;
F_15 ( & V_136 -> V_48 , V_133 , V_133 + 1 ) ;
}
}
static struct V_60 * F_117 ( struct V_14 * V_15 ,
unsigned long V_129 , int V_72 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
struct V_60 * V_60 ;
long V_30 ;
V_30 = F_115 ( V_37 , V_15 , V_129 ) ;
if ( V_30 < 0 )
return F_118 ( - V_137 ) ;
if ( V_30 )
if ( F_10 ( V_2 , V_30 ) )
return F_118 ( - V_138 ) ;
F_8 ( & V_97 ) ;
V_60 = F_64 ( V_37 , V_15 , V_129 , V_72 ) ;
F_2 ( & V_97 ) ;
if ( ! V_60 ) {
V_60 = F_108 ( V_37 , V_119 ) ;
if ( ! V_60 ) {
F_11 ( V_2 , V_30 ) ;
return F_118 ( - V_138 ) ;
}
}
F_81 ( V_60 , ( unsigned long ) V_2 ) ;
F_116 ( V_37 , V_15 , V_129 ) ;
return V_60 ;
}
int __weak F_119 ( struct V_36 * V_37 )
{
struct V_139 * V_140 ;
int V_141 = F_120 ( V_127 [ V_128 ] ) ;
while ( V_141 ) {
void * V_129 ;
V_129 = F_121 (
F_122 ( F_103 ( V_37 ,
& V_127 [ V_128 ] ) ) ,
F_78 ( V_37 ) , F_78 ( V_37 ) , 0 ) ;
if ( V_129 ) {
V_140 = V_129 ;
goto V_142;
}
V_141 -- ;
}
return 0 ;
V_142:
F_9 ( ( unsigned long ) F_123 ( V_140 ) & ( F_78 ( V_37 ) - 1 ) ) ;
F_21 ( & V_140 -> V_143 , & V_144 ) ;
V_140 -> V_36 = V_37 ;
return 1 ;
}
static void F_124 ( struct V_60 * V_60 , int V_42 )
{
if ( F_57 ( V_42 > ( V_84 - 1 ) ) )
F_86 ( V_60 , V_42 ) ;
else
F_125 ( V_60 , V_42 ) ;
}
static void T_4 F_126 ( void )
{
struct V_139 * V_140 ;
F_16 (m, &huge_boot_pages, list) {
struct V_36 * V_37 = V_140 -> V_36 ;
struct V_60 * V_60 ;
#ifdef F_127
V_60 = F_128 ( V_140 -> V_145 >> V_43 ) ;
F_129 ( ( unsigned long ) V_140 ,
sizeof( struct V_139 ) ) ;
#else
V_60 = F_130 ( V_140 ) ;
#endif
F_131 ( V_60 ) ;
F_132 ( F_82 ( V_60 ) != 1 ) ;
F_124 ( V_60 , V_37 -> V_42 ) ;
F_84 ( V_37 , V_60 , F_60 ( V_60 ) ) ;
if ( V_37 -> V_42 > ( V_84 - 1 ) )
V_146 += 1 << V_37 -> V_42 ;
}
}
static void T_4 F_133 ( struct V_36 * V_37 )
{
unsigned long V_63 ;
for ( V_63 = 0 ; V_63 < V_37 -> V_147 ; ++ V_63 ) {
if ( V_37 -> V_42 >= V_84 ) {
if ( ! F_119 ( V_37 ) )
break;
} else if ( ! F_104 ( V_37 ,
& V_127 [ V_128 ] ) )
break;
}
V_37 -> V_147 = V_63 ;
}
static void T_4 F_134 ( void )
{
struct V_36 * V_37 ;
F_77 (h) {
if ( V_37 -> V_42 < V_84 )
F_133 ( V_37 ) ;
}
}
static char * T_4 F_135 ( char * V_148 , unsigned long V_149 )
{
if ( V_149 >= ( 1UL << 30 ) )
sprintf ( V_148 , L_1 , V_149 >> 30 ) ;
else if ( V_149 >= ( 1UL << 20 ) )
sprintf ( V_148 , L_2 , V_149 >> 20 ) ;
else
sprintf ( V_148 , L_3 , V_149 >> 10 ) ;
return V_148 ;
}
static void T_4 F_136 ( void )
{
struct V_36 * V_37 ;
F_77 (h) {
char V_148 [ 32 ] ;
F_137 ( V_150 L_4
L_5 ,
F_135 ( V_148 , F_78 ( V_37 ) ) ,
V_37 -> V_70 ) ;
}
}
static void F_138 ( struct V_36 * V_37 , unsigned long V_3 ,
T_2 * V_108 )
{
int V_63 ;
if ( V_37 -> V_42 >= V_84 )
return;
F_139 (i, *nodes_allowed) {
struct V_60 * V_60 , * V_33 ;
struct V_19 * V_151 = & V_37 -> V_69 [ V_63 ] ;
F_17 (page, next, freel, lru) {
if ( V_3 >= V_37 -> V_85 )
return;
if ( F_140 ( V_60 ) )
continue;
F_18 ( & V_60 -> V_68 ) ;
F_72 ( V_37 , V_60 ) ;
V_37 -> V_70 -- ;
V_37 -> V_71 [ F_60 ( V_60 ) ] -- ;
}
}
}
static inline void F_138 ( struct V_36 * V_37 , unsigned long V_3 ,
T_2 * V_108 )
{
}
static int F_141 ( struct V_36 * V_37 , T_2 * V_108 ,
int V_9 )
{
int V_111 , V_112 ;
int V_10 = 0 ;
F_43 ( V_9 != - 1 && V_9 != 1 ) ;
if ( V_9 < 0 )
V_111 = F_103 ( V_37 , V_108 ) ;
else
V_111 = F_106 ( V_37 , V_108 ) ;
V_112 = V_111 ;
do {
int V_67 = V_112 ;
if ( V_9 < 0 ) {
if ( ! V_37 -> V_98 [ V_67 ] ) {
V_112 = F_103 ( V_37 ,
V_108 ) ;
continue;
}
}
if ( V_9 > 0 ) {
if ( V_37 -> V_98 [ V_67 ] >=
V_37 -> V_86 [ V_67 ] ) {
V_112 = F_106 ( V_37 ,
V_108 ) ;
continue;
}
}
V_37 -> V_99 += V_9 ;
V_37 -> V_98 [ V_67 ] += V_9 ;
V_10 = 1 ;
break;
} while ( V_112 != V_111 );
return V_10 ;
}
static unsigned long F_142 ( struct V_36 * V_37 , unsigned long V_3 ,
T_2 * V_108 )
{
unsigned long V_152 , V_10 ;
if ( V_37 -> V_42 >= V_84 )
return V_37 -> V_147 ;
F_8 ( & V_97 ) ;
while ( V_37 -> V_99 && V_3 > F_143 ( V_37 ) ) {
if ( ! F_141 ( V_37 , V_108 , - 1 ) )
break;
}
while ( V_3 > F_143 ( V_37 ) ) {
F_2 ( & V_97 ) ;
V_10 = F_104 ( V_37 , V_108 ) ;
F_8 ( & V_97 ) ;
if ( ! V_10 )
goto V_153;
if ( F_144 ( V_154 ) )
goto V_153;
}
V_152 = V_37 -> V_58 + V_37 -> V_85 - V_37 -> V_70 ;
V_152 = F_26 ( V_3 , V_152 ) ;
F_138 ( V_37 , V_152 , V_108 ) ;
while ( V_152 < F_143 ( V_37 ) ) {
if ( ! F_107 ( V_37 , V_108 , 0 ) )
break;
}
while ( V_3 < F_143 ( V_37 ) ) {
if ( ! F_141 ( V_37 , V_108 , 1 ) )
break;
}
V_153:
V_10 = F_143 ( V_37 ) ;
F_2 ( & V_97 ) ;
return V_10 ;
}
static struct V_36 * F_145 ( struct V_155 * V_156 , int * V_157 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_158 ; V_63 ++ )
if ( V_159 [ V_63 ] == V_156 ) {
if ( V_157 )
* V_157 = V_119 ;
return & V_160 [ V_63 ] ;
}
return F_146 ( V_156 , V_157 ) ;
}
static T_5 F_147 ( struct V_155 * V_156 ,
struct V_161 * V_162 , char * V_148 )
{
struct V_36 * V_37 ;
unsigned long V_85 ;
int V_67 ;
V_37 = F_145 ( V_156 , & V_67 ) ;
if ( V_67 == V_119 )
V_85 = V_37 -> V_85 ;
else
V_85 = V_37 -> V_86 [ V_67 ] ;
return sprintf ( V_148 , L_6 , V_85 ) ;
}
static T_5 F_148 ( bool V_163 ,
struct V_155 * V_156 , struct V_161 * V_162 ,
const char * V_148 , T_6 V_164 )
{
int V_83 ;
int V_67 ;
unsigned long V_3 ;
struct V_36 * V_37 ;
F_149 ( T_2 , V_108 , V_7 | V_165 ) ;
V_83 = F_150 ( V_148 , 10 , & V_3 ) ;
if ( V_83 )
goto V_153;
V_37 = F_145 ( V_156 , & V_67 ) ;
if ( V_37 -> V_42 >= V_84 ) {
V_83 = - V_166 ;
goto V_153;
}
if ( V_67 == V_119 ) {
if ( ! ( V_163 &&
F_151 ( V_108 ) ) ) {
F_152 ( V_108 ) ;
V_108 = & V_127 [ V_128 ] ;
}
} else if ( V_108 ) {
V_3 += V_37 -> V_85 - V_37 -> V_86 [ V_67 ] ;
F_153 ( V_108 , V_67 ) ;
} else
V_108 = & V_127 [ V_128 ] ;
V_37 -> V_147 = F_142 ( V_37 , V_3 , V_108 ) ;
if ( V_108 != & V_127 [ V_128 ] )
F_152 ( V_108 ) ;
return V_164 ;
V_153:
F_152 ( V_108 ) ;
return V_83 ;
}
static T_5 F_154 ( struct V_155 * V_156 ,
struct V_161 * V_162 , char * V_148 )
{
return F_147 ( V_156 , V_162 , V_148 ) ;
}
static T_5 F_155 ( struct V_155 * V_156 ,
struct V_161 * V_162 , const char * V_148 , T_6 V_164 )
{
return F_148 ( false , V_156 , V_162 , V_148 , V_164 ) ;
}
static T_5 F_156 ( struct V_155 * V_156 ,
struct V_161 * V_162 , char * V_148 )
{
return F_147 ( V_156 , V_162 , V_148 ) ;
}
static T_5 F_157 ( struct V_155 * V_156 ,
struct V_161 * V_162 , const char * V_148 , T_6 V_164 )
{
return F_148 ( true , V_156 , V_162 , V_148 , V_164 ) ;
}
static T_5 F_158 ( struct V_155 * V_156 ,
struct V_161 * V_162 , char * V_148 )
{
struct V_36 * V_37 = F_145 ( V_156 , NULL ) ;
return sprintf ( V_148 , L_6 , V_37 -> V_118 ) ;
}
static T_5 F_159 ( struct V_155 * V_156 ,
struct V_161 * V_162 , const char * V_148 , T_6 V_3 )
{
int V_83 ;
unsigned long V_167 ;
struct V_36 * V_37 = F_145 ( V_156 , NULL ) ;
if ( V_37 -> V_42 >= V_84 )
return - V_166 ;
V_83 = F_150 ( V_148 , 10 , & V_167 ) ;
if ( V_83 )
return V_83 ;
F_8 ( & V_97 ) ;
V_37 -> V_118 = V_167 ;
F_2 ( & V_97 ) ;
return V_3 ;
}
static T_5 F_160 ( struct V_155 * V_156 ,
struct V_161 * V_162 , char * V_148 )
{
struct V_36 * V_37 ;
unsigned long V_70 ;
int V_67 ;
V_37 = F_145 ( V_156 , & V_67 ) ;
if ( V_67 == V_119 )
V_70 = V_37 -> V_70 ;
else
V_70 = V_37 -> V_71 [ V_67 ] ;
return sprintf ( V_148 , L_6 , V_70 ) ;
}
static T_5 F_161 ( struct V_155 * V_156 ,
struct V_161 * V_162 , char * V_148 )
{
struct V_36 * V_37 = F_145 ( V_156 , NULL ) ;
return sprintf ( V_148 , L_6 , V_37 -> V_58 ) ;
}
static T_5 F_162 ( struct V_155 * V_156 ,
struct V_161 * V_162 , char * V_148 )
{
struct V_36 * V_37 ;
unsigned long V_99 ;
int V_67 ;
V_37 = F_145 ( V_156 , & V_67 ) ;
if ( V_67 == V_119 )
V_99 = V_37 -> V_99 ;
else
V_99 = V_37 -> V_98 [ V_67 ] ;
return sprintf ( V_148 , L_6 , V_99 ) ;
}
static int F_163 ( struct V_36 * V_37 , struct V_155 * V_168 ,
struct V_155 * * V_159 ,
struct V_169 * V_170 )
{
int V_171 ;
int V_172 = V_37 - V_160 ;
V_159 [ V_172 ] = F_164 ( V_37 -> V_173 , V_168 ) ;
if ( ! V_159 [ V_172 ] )
return - V_11 ;
V_171 = F_165 ( V_159 [ V_172 ] , V_170 ) ;
if ( V_171 )
F_166 ( V_159 [ V_172 ] ) ;
return V_171 ;
}
static void T_4 F_167 ( void )
{
struct V_36 * V_37 ;
int V_83 ;
V_174 = F_164 ( L_7 , V_175 ) ;
if ( ! V_174 )
return;
F_77 (h) {
V_83 = F_163 ( V_37 , V_174 ,
V_159 , & V_170 ) ;
if ( V_83 )
F_137 ( V_176 L_8 ,
V_37 -> V_173 ) ;
}
}
static struct V_36 * F_146 ( struct V_155 * V_156 , int * V_157 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_177 ; V_67 ++ ) {
struct V_178 * V_179 = & V_180 [ V_67 ] ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_158 ; V_63 ++ )
if ( V_179 -> V_159 [ V_63 ] == V_156 ) {
if ( V_157 )
* V_157 = V_67 ;
return & V_160 [ V_63 ] ;
}
}
F_168 () ;
return NULL ;
}
void F_169 ( struct V_181 * V_181 )
{
struct V_36 * V_37 ;
struct V_178 * V_179 = & V_180 [ V_181 -> V_182 . V_183 ] ;
if ( ! V_179 -> V_174 )
return;
F_77 (h)
if ( V_179 -> V_159 [ V_37 - V_160 ] ) {
F_166 ( V_179 -> V_159 [ V_37 - V_160 ] ) ;
V_179 -> V_159 [ V_37 - V_160 ] = NULL ;
}
F_166 ( V_179 -> V_174 ) ;
V_179 -> V_174 = NULL ;
}
static void F_170 ( void )
{
int V_67 ;
F_171 ( NULL , NULL ) ;
for ( V_67 = 0 ; V_67 < V_177 ; V_67 ++ )
F_169 ( & V_184 [ V_67 ] ) ;
}
void F_172 ( struct V_181 * V_181 )
{
struct V_36 * V_37 ;
struct V_178 * V_179 = & V_180 [ V_181 -> V_182 . V_183 ] ;
int V_83 ;
if ( V_179 -> V_174 )
return;
V_179 -> V_174 = F_164 ( L_7 ,
& V_181 -> V_182 . V_156 ) ;
if ( ! V_179 -> V_174 )
return;
F_77 (h) {
V_83 = F_163 ( V_37 , V_179 -> V_174 ,
V_179 -> V_159 ,
& V_185 ) ;
if ( V_83 ) {
F_137 ( V_176 L_8
L_9 ,
V_37 -> V_173 , V_181 -> V_182 . V_183 ) ;
F_169 ( V_181 ) ;
break;
}
}
}
static void F_173 ( void )
{
int V_67 ;
F_174 (nid, N_HIGH_MEMORY) {
struct V_181 * V_181 = & V_184 [ V_67 ] ;
if ( V_181 -> V_182 . V_183 == V_67 )
F_172 ( V_181 ) ;
}
F_171 ( F_172 ,
F_169 ) ;
}
static struct V_36 * F_146 ( struct V_155 * V_156 , int * V_157 )
{
F_168 () ;
if ( V_157 )
* V_157 = - 1 ;
return NULL ;
}
static void F_170 ( void ) { }
static void F_173 ( void ) { }
static void T_7 F_175 ( void )
{
struct V_36 * V_37 ;
F_170 () ;
F_77 (h) {
F_166 ( V_159 [ V_37 - V_160 ] ) ;
}
F_166 ( V_174 ) ;
}
static int T_4 F_176 ( void )
{
if ( V_186 == 0 )
return 0 ;
if ( ! F_76 ( V_187 ) ) {
V_187 = V_188 ;
if ( ! F_76 ( V_187 ) )
F_177 ( V_189 ) ;
}
V_190 = F_76 ( V_187 ) - V_160 ;
if ( V_191 )
V_192 . V_147 = V_191 ;
F_134 () ;
F_126 () ;
F_136 () ;
F_167 () ;
F_173 () ;
return 0 ;
}
void T_4 F_177 ( unsigned V_42 )
{
struct V_36 * V_37 ;
unsigned long V_63 ;
if ( F_76 ( V_41 << V_42 ) ) {
F_137 ( V_193 L_10 ) ;
return;
}
F_9 ( V_194 >= V_158 ) ;
F_9 ( V_42 == 0 ) ;
V_37 = & V_160 [ V_194 ++ ] ;
V_37 -> V_42 = V_42 ;
V_37 -> V_195 = ~ ( ( 1ULL << ( V_42 + V_43 ) ) - 1 ) ;
V_37 -> V_85 = 0 ;
V_37 -> V_70 = 0 ;
for ( V_63 = 0 ; V_63 < V_109 ; ++ V_63 )
F_20 ( & V_37 -> V_69 [ V_63 ] ) ;
V_37 -> V_110 = F_100 ( V_127 [ V_128 ] ) ;
V_37 -> V_115 = F_100 ( V_127 [ V_128 ] ) ;
snprintf ( V_37 -> V_173 , V_196 , L_11 ,
F_78 ( V_37 ) / 1024 ) ;
V_197 = V_37 ;
}
static int T_4 F_178 ( char * V_198 )
{
unsigned long * V_199 ;
static unsigned long * V_200 ;
if ( ! V_194 )
V_199 = & V_191 ;
else
V_199 = & V_197 -> V_147 ;
if ( V_199 == V_200 ) {
F_137 ( V_193 L_12
L_13 ) ;
return 1 ;
}
if ( sscanf ( V_198 , L_14 , V_199 ) <= 0 )
* V_199 = 0 ;
if ( V_194 && V_197 -> V_42 >= V_84 )
F_133 ( V_197 ) ;
V_200 = V_199 ;
return 1 ;
}
static int T_4 F_179 ( char * V_198 )
{
V_187 = F_180 ( V_198 , & V_198 ) ;
return 1 ;
}
static unsigned int F_181 ( unsigned int * V_201 )
{
int V_181 ;
unsigned int V_202 = 0 ;
F_139 (node, cpuset_current_mems_allowed)
V_202 += V_201 [ V_181 ] ;
return V_202 ;
}
static int F_182 ( bool V_163 ,
struct V_203 * V_204 , int V_205 ,
void T_8 * V_206 , T_6 * V_207 , T_9 * V_208 )
{
struct V_36 * V_37 = & V_192 ;
unsigned long V_121 ;
int V_10 ;
V_121 = V_37 -> V_147 ;
if ( V_205 && V_37 -> V_42 >= V_84 )
return - V_166 ;
V_204 -> V_209 = & V_121 ;
V_204 -> V_210 = sizeof( unsigned long ) ;
V_10 = F_183 ( V_204 , V_205 , V_206 , V_207 , V_208 ) ;
if ( V_10 )
goto V_153;
if ( V_205 ) {
F_149 ( T_2 , V_108 ,
V_7 | V_165 ) ;
if ( ! ( V_163 &&
F_151 ( V_108 ) ) ) {
F_152 ( V_108 ) ;
V_108 = & V_127 [ V_128 ] ;
}
V_37 -> V_147 = F_142 ( V_37 , V_121 , V_108 ) ;
if ( V_108 != & V_127 [ V_128 ] )
F_152 ( V_108 ) ;
}
V_153:
return V_10 ;
}
int F_184 ( struct V_203 * V_204 , int V_205 ,
void T_8 * V_206 , T_6 * V_207 , T_9 * V_208 )
{
return F_182 ( false , V_204 , V_205 ,
V_206 , V_207 , V_208 ) ;
}
int F_185 ( struct V_203 * V_204 , int V_205 ,
void T_8 * V_206 , T_6 * V_207 , T_9 * V_208 )
{
return F_182 ( true , V_204 , V_205 ,
V_206 , V_207 , V_208 ) ;
}
int F_186 ( struct V_203 * V_204 , int V_205 ,
void T_8 * V_206 ,
T_6 * V_207 , T_9 * V_208 )
{
F_187 ( V_204 , V_205 , V_206 , V_207 , V_208 ) ;
if ( V_211 )
V_82 = V_212 ;
else
V_82 = V_213 ;
return 0 ;
}
int F_188 ( struct V_203 * V_204 , int V_205 ,
void T_8 * V_206 ,
T_6 * V_207 , T_9 * V_208 )
{
struct V_36 * V_37 = & V_192 ;
unsigned long V_121 ;
int V_10 ;
V_121 = V_37 -> V_118 ;
if ( V_205 && V_37 -> V_42 >= V_84 )
return - V_166 ;
V_204 -> V_209 = & V_121 ;
V_204 -> V_210 = sizeof( unsigned long ) ;
V_10 = F_183 ( V_204 , V_205 , V_206 , V_207 , V_208 ) ;
if ( V_10 )
goto V_153;
if ( V_205 ) {
F_8 ( & V_97 ) ;
V_37 -> V_118 = V_121 ;
F_2 ( & V_97 ) ;
}
V_153:
return V_10 ;
}
void F_189 ( struct V_214 * V_140 )
{
struct V_36 * V_37 = & V_192 ;
F_190 ( V_140 ,
L_15
L_16
L_17
L_18
L_19 ,
V_37 -> V_85 ,
V_37 -> V_70 ,
V_37 -> V_58 ,
V_37 -> V_99 ,
1UL << ( F_30 ( V_37 ) + V_43 - 10 ) ) ;
}
int F_191 ( int V_67 , char * V_148 )
{
struct V_36 * V_37 = & V_192 ;
return sprintf ( V_148 ,
L_20
L_21
L_22 ,
V_67 , V_37 -> V_86 [ V_67 ] ,
V_67 , V_37 -> V_71 [ V_67 ] ,
V_67 , V_37 -> V_98 [ V_67 ] ) ;
}
unsigned long F_192 ( void )
{
struct V_36 * V_37 = & V_192 ;
return V_37 -> V_85 * F_52 ( V_37 ) ;
}
static int F_193 ( struct V_36 * V_37 , long V_9 )
{
int V_10 = - V_11 ;
F_8 ( & V_97 ) ;
if ( V_9 > 0 ) {
if ( F_112 ( V_37 , V_9 ) < 0 )
goto V_153;
if ( V_9 > F_181 ( V_37 -> V_71 ) ) {
F_114 ( V_37 , V_9 ) ;
goto V_153;
}
}
V_10 = 0 ;
if ( V_9 < 0 )
F_114 ( V_37 , ( unsigned long ) - V_9 ) ;
V_153:
F_2 ( & V_97 ) ;
return V_10 ;
}
static void F_194 ( struct V_14 * V_15 )
{
struct V_46 * V_136 = F_42 ( V_15 ) ;
if ( V_136 )
F_195 ( & V_136 -> V_47 ) ;
}
static void F_196 ( struct V_14 * V_15 )
{
struct V_36 * V_37 = F_32 ( V_15 ) ;
struct V_46 * V_136 = F_42 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_15 ) ;
unsigned long V_215 ;
unsigned long V_216 ;
unsigned long V_32 ;
if ( V_136 ) {
V_216 = F_28 ( V_37 , V_15 , V_15 -> V_39 ) ;
V_32 = F_28 ( V_37 , V_15 , V_15 -> V_217 ) ;
V_215 = ( V_32 - V_216 ) -
F_25 ( & V_136 -> V_48 , V_216 , V_32 ) ;
F_197 ( & V_136 -> V_47 , F_40 ) ;
if ( V_215 ) {
F_193 ( V_37 , - V_215 ) ;
F_11 ( V_2 , V_215 ) ;
}
}
}
static int F_198 ( struct V_14 * V_15 , struct V_218 * V_219 )
{
F_168 () ;
return 0 ;
}
static T_10 F_199 ( struct V_14 * V_15 , struct V_60 * V_60 ,
int V_220 )
{
T_10 V_221 ;
if ( V_220 ) {
V_221 =
F_200 ( F_201 ( F_202 ( V_60 , V_15 -> V_222 ) ) ) ;
} else {
V_221 = F_203 ( F_202 ( V_60 , V_15 -> V_222 ) ) ;
}
V_221 = F_204 ( V_221 ) ;
V_221 = F_205 ( V_221 ) ;
return V_221 ;
}
static void F_206 ( struct V_14 * V_15 ,
unsigned long V_38 , T_10 * V_223 )
{
T_10 V_221 ;
V_221 = F_200 ( F_201 ( F_207 ( V_223 ) ) ) ;
if ( F_208 ( V_15 , V_38 , V_223 , V_221 , 1 ) )
F_209 ( V_15 , V_38 , V_223 ) ;
}
int F_210 ( struct V_224 * V_61 , struct V_224 * V_62 ,
struct V_14 * V_15 )
{
T_10 * V_225 , * V_226 , V_221 ;
struct V_60 * V_227 ;
unsigned long V_129 ;
int V_228 ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
unsigned long V_229 = F_78 ( V_37 ) ;
V_228 = ( V_15 -> V_51 & ( V_230 | V_231 ) ) == V_231 ;
for ( V_129 = V_15 -> V_39 ; V_129 < V_15 -> V_217 ; V_129 += V_229 ) {
V_225 = F_211 ( V_62 , V_129 ) ;
if ( ! V_225 )
continue;
V_226 = F_212 ( V_61 , V_129 , V_229 ) ;
if ( ! V_226 )
goto V_232;
if ( V_226 == V_225 )
continue;
F_8 ( & V_61 -> V_233 ) ;
F_213 ( & V_62 -> V_233 , V_234 ) ;
if ( ! F_214 ( F_207 ( V_225 ) ) ) {
if ( V_228 )
F_215 ( V_62 , V_129 , V_225 ) ;
V_221 = F_207 ( V_225 ) ;
V_227 = F_216 ( V_221 ) ;
F_217 ( V_227 ) ;
F_218 ( V_227 ) ;
F_219 ( V_61 , V_129 , V_226 , V_221 ) ;
}
F_2 ( & V_62 -> V_233 ) ;
F_2 ( & V_61 -> V_233 ) ;
}
return 0 ;
V_232:
return - V_11 ;
}
static int F_220 ( T_10 V_235 )
{
T_11 V_236 ;
if ( F_214 ( V_235 ) || F_221 ( V_235 ) )
return 0 ;
V_236 = F_222 ( V_235 ) ;
if ( F_223 ( V_236 ) && F_224 ( V_236 ) )
return 1 ;
else
return 0 ;
}
static int F_225 ( T_10 V_235 )
{
T_11 V_236 ;
if ( F_214 ( V_235 ) || F_221 ( V_235 ) )
return 0 ;
V_236 = F_222 ( V_235 ) ;
if ( F_223 ( V_236 ) && F_226 ( V_236 ) )
return 1 ;
else
return 0 ;
}
void F_227 ( struct V_14 * V_15 , unsigned long V_216 ,
unsigned long V_32 , struct V_60 * V_237 )
{
struct V_224 * V_238 = V_15 -> V_239 ;
unsigned long V_38 ;
T_10 * V_223 ;
T_10 V_235 ;
struct V_60 * V_60 ;
struct V_60 * V_121 ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
unsigned long V_229 = F_78 ( V_37 ) ;
F_228 ( V_240 ) ;
F_132 ( ! F_34 ( V_15 ) ) ;
F_9 ( V_216 & ~ F_229 ( V_37 ) ) ;
F_9 ( V_32 & ~ F_229 ( V_37 ) ) ;
F_230 ( V_238 , V_216 , V_32 ) ;
F_8 ( & V_238 -> V_233 ) ;
for ( V_38 = V_216 ; V_38 < V_32 ; V_38 += V_229 ) {
V_223 = F_211 ( V_238 , V_38 ) ;
if ( ! V_223 )
continue;
if ( F_231 ( V_238 , & V_38 , V_223 ) )
continue;
V_235 = F_207 ( V_223 ) ;
if ( F_214 ( V_235 ) )
continue;
if ( F_57 ( F_225 ( V_235 ) ) )
continue;
V_60 = F_216 ( V_235 ) ;
if ( V_237 ) {
if ( V_60 != V_237 )
continue;
F_45 ( V_15 , V_241 ) ;
}
V_235 = F_232 ( V_238 , V_38 , V_223 ) ;
if ( F_233 ( V_235 ) )
F_234 ( V_60 ) ;
F_21 ( & V_60 -> V_68 , & V_240 ) ;
if ( V_237 )
break;
}
F_235 ( V_15 , V_216 , V_32 ) ;
F_2 ( & V_238 -> V_233 ) ;
F_236 ( V_238 , V_216 , V_32 ) ;
F_17 (page, tmp, &page_list, lru) {
F_237 ( V_60 ) ;
F_18 ( & V_60 -> V_68 ) ;
F_85 ( V_60 ) ;
}
}
void F_238 ( struct V_14 * V_15 , unsigned long V_216 ,
unsigned long V_32 , struct V_60 * V_237 )
{
F_239 ( & V_15 -> V_16 -> V_131 -> V_242 ) ;
F_227 ( V_15 , V_216 , V_32 , V_237 ) ;
F_240 ( & V_15 -> V_16 -> V_131 -> V_242 ) ;
}
static int F_241 ( struct V_224 * V_238 , struct V_14 * V_15 ,
struct V_60 * V_60 , unsigned long V_38 )
{
struct V_36 * V_37 = F_32 ( V_15 ) ;
struct V_14 * V_243 ;
struct V_130 * V_96 ;
struct V_244 V_245 ;
T_1 V_246 ;
V_38 = V_38 & F_229 ( V_37 ) ;
V_246 = F_28 ( V_37 , V_15 , V_38 ) ;
V_96 = V_15 -> V_16 -> V_17 -> V_18 -> V_134 ;
F_239 ( & V_96 -> V_242 ) ;
F_242 (iter_vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
if ( V_243 == V_15 )
continue;
if ( ! F_46 ( V_243 , V_59 ) )
F_227 ( V_243 ,
V_38 , V_38 + F_78 ( V_37 ) ,
V_60 ) ;
}
F_240 ( & V_96 -> V_242 ) ;
return 1 ;
}
static int F_243 ( struct V_224 * V_238 , struct V_14 * V_15 ,
unsigned long V_38 , T_10 * V_223 , T_10 V_235 ,
struct V_60 * V_247 )
{
struct V_36 * V_37 = F_32 ( V_15 ) ;
struct V_60 * V_248 , * V_249 ;
int V_250 ;
int V_251 = 0 ;
V_248 = F_216 ( V_235 ) ;
V_252:
V_250 = ( F_83 ( V_248 ) == 1 ) ;
if ( V_250 ) {
if ( F_244 ( V_248 ) )
F_245 ( V_248 , V_15 , V_38 ) ;
F_206 ( V_15 , V_38 , V_223 ) ;
return 0 ;
}
if ( ! ( V_15 -> V_51 & V_52 ) &&
F_46 ( V_15 , V_59 ) &&
V_248 != V_247 )
V_251 = 1 ;
F_246 ( V_248 ) ;
F_2 ( & V_238 -> V_233 ) ;
V_249 = F_117 ( V_15 , V_38 , V_251 ) ;
if ( F_247 ( V_249 ) ) {
F_248 ( V_248 ) ;
if ( V_251 ) {
F_9 ( F_214 ( V_235 ) ) ;
if ( F_241 ( V_238 , V_15 , V_248 , V_38 ) ) {
F_9 ( F_214 ( V_235 ) ) ;
F_8 ( & V_238 -> V_233 ) ;
V_223 = F_211 ( V_238 , V_38 & F_229 ( V_37 ) ) ;
if ( F_249 ( F_250 ( F_207 ( V_223 ) , V_235 ) ) )
goto V_252;
return 0 ;
}
F_251 ( 1 ) ;
}
F_8 ( & V_238 -> V_233 ) ;
return - F_252 ( V_249 ) ;
}
if ( F_57 ( F_253 ( V_15 ) ) ) {
F_248 ( V_249 ) ;
F_248 ( V_248 ) ;
F_8 ( & V_238 -> V_233 ) ;
return V_137 ;
}
F_254 ( V_249 , V_248 , V_38 , V_15 ,
F_52 ( V_37 ) ) ;
F_255 ( V_249 ) ;
F_8 ( & V_238 -> V_233 ) ;
V_223 = F_211 ( V_238 , V_38 & F_229 ( V_37 ) ) ;
if ( F_249 ( F_250 ( F_207 ( V_223 ) , V_235 ) ) ) {
F_230 ( V_238 ,
V_38 & F_229 ( V_37 ) ,
( V_38 & F_229 ( V_37 ) ) + F_78 ( V_37 ) ) ;
F_256 ( V_15 , V_38 , V_223 ) ;
F_219 ( V_238 , V_38 , V_223 ,
F_199 ( V_15 , V_249 , 1 ) ) ;
F_237 ( V_248 ) ;
F_257 ( V_249 , V_15 , V_38 ) ;
V_249 = V_248 ;
F_236 ( V_238 ,
V_38 & F_229 ( V_37 ) ,
( V_38 & F_229 ( V_37 ) ) + F_78 ( V_37 ) ) ;
}
F_248 ( V_249 ) ;
F_248 ( V_248 ) ;
return 0 ;
}
static struct V_60 * F_258 ( struct V_36 * V_37 ,
struct V_14 * V_15 , unsigned long V_38 )
{
struct V_130 * V_96 ;
T_1 V_133 ;
V_96 = V_15 -> V_16 -> V_131 ;
V_133 = F_28 ( V_37 , V_15 , V_38 ) ;
return F_259 ( V_96 , V_133 ) ;
}
static bool F_260 ( struct V_36 * V_37 ,
struct V_14 * V_15 , unsigned long V_38 )
{
struct V_130 * V_96 ;
T_1 V_133 ;
struct V_60 * V_60 ;
V_96 = V_15 -> V_16 -> V_131 ;
V_133 = F_28 ( V_37 , V_15 , V_38 ) ;
V_60 = F_261 ( V_96 , V_133 ) ;
if ( V_60 )
F_85 ( V_60 ) ;
return V_60 != NULL ;
}
static int F_262 ( struct V_224 * V_238 , struct V_14 * V_15 ,
unsigned long V_38 , T_10 * V_223 , unsigned int V_55 )
{
struct V_36 * V_37 = F_32 ( V_15 ) ;
int V_10 = V_138 ;
int V_253 = 0 ;
T_1 V_133 ;
unsigned long V_95 ;
struct V_60 * V_60 ;
struct V_130 * V_96 ;
T_10 V_254 ;
if ( F_46 ( V_15 , V_241 ) ) {
F_137 ( V_193
L_23 ,
V_154 -> V_255 ) ;
return V_10 ;
}
V_96 = V_15 -> V_16 -> V_131 ;
V_133 = F_28 ( V_37 , V_15 , V_38 ) ;
V_125:
V_60 = F_259 ( V_96 , V_133 ) ;
if ( ! V_60 ) {
V_95 = F_263 ( V_96 -> V_132 ) >> F_29 ( V_37 ) ;
if ( V_133 >= V_95 )
goto V_153;
V_60 = F_117 ( V_15 , V_38 , 0 ) ;
if ( F_247 ( V_60 ) ) {
V_10 = - F_252 ( V_60 ) ;
goto V_153;
}
F_264 ( V_60 , V_38 , F_52 ( V_37 ) ) ;
F_255 ( V_60 ) ;
if ( V_15 -> V_51 & V_52 ) {
int V_83 ;
struct V_12 * V_12 = V_96 -> V_132 ;
V_83 = F_265 ( V_60 , V_96 , V_133 , V_7 ) ;
if ( V_83 ) {
F_85 ( V_60 ) ;
if ( V_83 == - V_256 )
goto V_125;
goto V_153;
}
F_8 ( & V_12 -> V_257 ) ;
V_12 -> V_258 += F_266 ( V_37 ) ;
F_2 ( & V_12 -> V_257 ) ;
} else {
F_267 ( V_60 ) ;
if ( F_57 ( F_253 ( V_15 ) ) ) {
V_10 = V_137 ;
goto V_259;
}
V_253 = 1 ;
}
} else {
if ( F_57 ( F_268 ( V_60 ) ) ) {
V_10 = V_260 |
F_269 ( V_37 - V_160 ) ;
goto V_259;
}
}
if ( ( V_55 & V_261 ) && ! ( V_15 -> V_51 & V_230 ) )
if ( F_115 ( V_37 , V_15 , V_38 ) < 0 ) {
V_10 = V_137 ;
goto V_259;
}
F_8 ( & V_238 -> V_233 ) ;
V_95 = F_263 ( V_96 -> V_132 ) >> F_29 ( V_37 ) ;
if ( V_133 >= V_95 )
goto V_262;
V_10 = 0 ;
if ( ! F_214 ( F_207 ( V_223 ) ) )
goto V_262;
if ( V_253 )
F_257 ( V_60 , V_15 , V_38 ) ;
else
F_218 ( V_60 ) ;
V_254 = F_199 ( V_15 , V_60 , ( ( V_15 -> V_51 & V_263 )
&& ( V_15 -> V_51 & V_230 ) ) ) ;
F_219 ( V_238 , V_38 , V_223 , V_254 ) ;
if ( ( V_55 & V_261 ) && ! ( V_15 -> V_51 & V_230 ) ) {
V_10 = F_243 ( V_238 , V_15 , V_38 , V_223 , V_254 , V_60 ) ;
}
F_2 ( & V_238 -> V_233 ) ;
F_270 ( V_60 ) ;
V_153:
return V_10 ;
V_262:
F_2 ( & V_238 -> V_233 ) ;
V_259:
F_270 ( V_60 ) ;
F_85 ( V_60 ) ;
goto V_153;
}
int F_271 ( struct V_224 * V_238 , struct V_14 * V_15 ,
unsigned long V_38 , unsigned int V_55 )
{
T_10 * V_223 ;
T_10 V_221 ;
int V_10 ;
struct V_60 * V_60 = NULL ;
struct V_60 * V_247 = NULL ;
static F_272 ( V_264 ) ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
V_38 &= F_229 ( V_37 ) ;
V_223 = F_211 ( V_238 , V_38 ) ;
if ( V_223 ) {
V_221 = F_207 ( V_223 ) ;
if ( F_57 ( F_220 ( V_221 ) ) ) {
F_273 ( V_238 , ( V_265 * ) V_223 , V_38 ) ;
return 0 ;
} else if ( F_57 ( F_225 ( V_221 ) ) )
return V_266 |
F_269 ( V_37 - V_160 ) ;
}
V_223 = F_212 ( V_238 , V_38 , F_78 ( V_37 ) ) ;
if ( ! V_223 )
return V_137 ;
F_239 ( & V_264 ) ;
V_221 = F_207 ( V_223 ) ;
if ( F_214 ( V_221 ) ) {
V_10 = F_262 ( V_238 , V_15 , V_38 , V_223 , V_55 ) ;
goto V_267;
}
V_10 = 0 ;
if ( ( V_55 & V_261 ) && ! F_274 ( V_221 ) ) {
if ( F_115 ( V_37 , V_15 , V_38 ) < 0 ) {
V_10 = V_137 ;
goto V_267;
}
if ( ! ( V_15 -> V_51 & V_52 ) )
V_247 = F_258 ( V_37 ,
V_15 , V_38 ) ;
}
V_60 = F_216 ( V_221 ) ;
F_217 ( V_60 ) ;
if ( V_60 != V_247 )
F_267 ( V_60 ) ;
F_8 ( & V_238 -> V_233 ) ;
if ( F_57 ( ! F_250 ( V_221 , F_207 ( V_223 ) ) ) )
goto V_268;
if ( V_55 & V_261 ) {
if ( ! F_274 ( V_221 ) ) {
V_10 = F_243 ( V_238 , V_15 , V_38 , V_223 , V_221 ,
V_247 ) ;
goto V_268;
}
V_221 = F_201 ( V_221 ) ;
}
V_221 = F_204 ( V_221 ) ;
if ( F_208 ( V_15 , V_38 , V_223 , V_221 ,
V_55 & V_261 ) )
F_209 ( V_15 , V_38 , V_223 ) ;
V_268:
F_2 ( & V_238 -> V_233 ) ;
if ( V_247 ) {
F_270 ( V_247 ) ;
F_85 ( V_247 ) ;
}
if ( V_60 != V_247 )
F_270 ( V_60 ) ;
F_85 ( V_60 ) ;
V_267:
F_240 ( & V_264 ) ;
return V_10 ;
}
struct V_60 *
F_275 ( struct V_224 * V_238 , unsigned long V_38 ,
T_12 * V_269 , int V_205 )
{
F_168 () ;
return NULL ;
}
int F_276 ( struct V_224 * V_238 , struct V_14 * V_15 ,
struct V_60 * * V_270 , struct V_14 * * V_271 ,
unsigned long * V_272 , int * V_207 , int V_63 ,
unsigned int V_55 )
{
unsigned long V_273 ;
unsigned long V_274 = * V_272 ;
int V_275 = * V_207 ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
F_8 ( & V_238 -> V_233 ) ;
while ( V_274 < V_15 -> V_217 && V_275 ) {
T_10 * V_235 ;
int V_276 ;
struct V_60 * V_60 ;
V_235 = F_211 ( V_238 , V_274 & F_229 ( V_37 ) ) ;
V_276 = ! V_235 || F_214 ( F_207 ( V_235 ) ) ;
if ( V_276 && ( V_55 & V_277 ) &&
! F_260 ( V_37 , V_15 , V_274 ) ) {
V_275 = 0 ;
break;
}
if ( V_276 ||
( ( V_55 & V_278 ) && ! F_274 ( F_207 ( V_235 ) ) ) ) {
int V_10 ;
F_2 ( & V_238 -> V_233 ) ;
V_10 = F_271 ( V_238 , V_15 , V_274 ,
( V_55 & V_278 ) ? V_261 : 0 ) ;
F_8 ( & V_238 -> V_233 ) ;
if ( ! ( V_10 & V_279 ) )
continue;
V_275 = 0 ;
break;
}
V_273 = ( V_274 & ~ F_229 ( V_37 ) ) >> V_43 ;
V_60 = F_216 ( F_207 ( V_235 ) ) ;
V_280:
if ( V_270 ) {
V_270 [ V_63 ] = F_277 ( V_60 , V_273 ) ;
F_217 ( V_270 [ V_63 ] ) ;
}
if ( V_271 )
V_271 [ V_63 ] = V_15 ;
V_274 += V_41 ;
++ V_273 ;
-- V_275 ;
++ V_63 ;
if ( V_274 < V_15 -> V_217 && V_275 &&
V_273 < F_52 ( V_37 ) ) {
goto V_280;
}
}
F_2 ( & V_238 -> V_233 ) ;
* V_207 = V_275 ;
* V_272 = V_274 ;
return V_63 ? V_63 : - V_281 ;
}
void F_278 ( struct V_14 * V_15 ,
unsigned long V_38 , unsigned long V_32 , T_13 V_282 )
{
struct V_224 * V_238 = V_15 -> V_239 ;
unsigned long V_216 = V_38 ;
T_10 * V_223 ;
T_10 V_235 ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
F_9 ( V_38 >= V_32 ) ;
F_279 ( V_15 , V_38 , V_32 ) ;
F_239 ( & V_15 -> V_16 -> V_131 -> V_242 ) ;
F_8 ( & V_238 -> V_233 ) ;
for (; V_38 < V_32 ; V_38 += F_78 ( V_37 ) ) {
V_223 = F_211 ( V_238 , V_38 ) ;
if ( ! V_223 )
continue;
if ( F_231 ( V_238 , & V_38 , V_223 ) )
continue;
if ( ! F_214 ( F_207 ( V_223 ) ) ) {
V_235 = F_232 ( V_238 , V_38 , V_223 ) ;
V_235 = F_205 ( F_280 ( V_235 , V_282 ) ) ;
F_219 ( V_238 , V_38 , V_223 , V_235 ) ;
}
}
F_2 ( & V_238 -> V_233 ) ;
F_240 ( & V_15 -> V_16 -> V_131 -> V_242 ) ;
F_235 ( V_15 , V_216 , V_32 ) ;
}
int F_281 ( struct V_12 * V_12 ,
long V_28 , long V_27 ,
struct V_14 * V_15 ,
T_14 V_51 )
{
long V_10 , V_30 ;
struct V_36 * V_37 = F_282 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( V_51 & V_57 )
return 0 ;
if ( ! V_15 || V_15 -> V_51 & V_52 )
V_30 = F_19 ( & V_12 -> V_134 -> V_135 , V_28 , V_27 ) ;
else {
struct V_46 * V_46 = F_38 () ;
if ( ! V_46 )
return - V_11 ;
V_30 = V_27 - V_28 ;
F_44 ( V_15 , V_46 ) ;
F_45 ( V_15 , V_59 ) ;
}
if ( V_30 < 0 )
return V_30 ;
if ( F_10 ( V_2 , V_30 ) )
return - V_283 ;
V_10 = F_193 ( V_37 , V_30 ) ;
if ( V_10 < 0 ) {
F_11 ( V_2 , V_30 ) ;
return V_10 ;
}
if ( ! V_15 || V_15 -> V_51 & V_52 )
F_15 ( & V_12 -> V_134 -> V_135 , V_28 , V_27 ) ;
return 0 ;
}
void F_283 ( struct V_12 * V_12 , long V_284 , long V_285 )
{
struct V_36 * V_37 = F_282 ( V_12 ) ;
long V_30 = F_22 ( & V_12 -> V_134 -> V_135 , V_284 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_8 ( & V_12 -> V_257 ) ;
V_12 -> V_258 -= ( F_266 ( V_37 ) * V_285 ) ;
F_2 ( & V_12 -> V_257 ) ;
F_11 ( V_2 , ( V_30 - V_285 ) ) ;
F_193 ( V_37 , - ( V_30 - V_285 ) ) ;
}
static int F_284 ( struct V_60 * V_286 )
{
struct V_60 * V_60 ;
struct V_60 * V_121 ;
struct V_36 * V_37 = F_51 ( V_286 ) ;
int V_67 = F_60 ( V_286 ) ;
F_17 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_60 == V_286 )
return 1 ;
return 0 ;
}
int F_285 ( struct V_60 * V_286 )
{
struct V_36 * V_37 = F_51 ( V_286 ) ;
int V_67 = F_60 ( V_286 ) ;
int V_10 = - V_287 ;
F_8 ( & V_97 ) ;
if ( F_284 ( V_286 ) ) {
F_18 ( & V_286 -> V_68 ) ;
F_63 ( V_286 ) ;
V_37 -> V_70 -- ;
V_37 -> V_71 [ V_67 ] -- ;
V_10 = 0 ;
}
F_2 ( & V_97 ) ;
return V_10 ;
}
