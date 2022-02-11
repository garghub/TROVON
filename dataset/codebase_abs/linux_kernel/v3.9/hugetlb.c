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
return 1UL << ( V_34 -> V_40 + V_41 ) ;
}
unsigned long F_36 ( struct V_14 * V_15 )
{
return F_34 ( V_15 ) ;
}
static unsigned long F_37 ( struct V_14 * V_15 )
{
return ( unsigned long ) V_15 -> V_42 ;
}
static void F_38 ( struct V_14 * V_15 ,
unsigned long V_43 )
{
V_15 -> V_42 = ( void * ) V_43 ;
}
static struct V_44 * F_39 ( void )
{
struct V_44 * V_44 = F_5 ( sizeof( * V_44 ) , V_7 ) ;
if ( ! V_44 )
return NULL ;
F_40 ( & V_44 -> V_45 ) ;
F_21 ( & V_44 -> V_46 ) ;
return V_44 ;
}
static void F_41 ( struct V_47 * V_48 )
{
struct V_44 * V_44 = F_42 ( V_48 , struct V_44 , V_45 ) ;
F_23 ( & V_44 -> V_46 , 0 ) ;
F_3 ( V_44 ) ;
}
static struct V_44 * F_43 ( struct V_14 * V_15 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
if ( ! ( V_15 -> V_49 & V_50 ) )
return (struct V_44 * ) ( F_37 ( V_15 ) &
~ V_51 ) ;
return NULL ;
}
static void F_45 ( struct V_14 * V_15 , struct V_44 * V_52 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
F_44 ( V_15 -> V_49 & V_50 ) ;
F_38 ( V_15 , ( F_37 ( V_15 ) &
V_51 ) | ( unsigned long ) V_52 ) ;
}
static void F_46 ( struct V_14 * V_15 , unsigned long V_53 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
F_44 ( V_15 -> V_49 & V_50 ) ;
F_38 ( V_15 , F_37 ( V_15 ) | V_53 ) ;
}
static int F_47 ( struct V_14 * V_15 , unsigned long V_54 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
return ( F_37 ( V_15 ) & V_54 ) != 0 ;
}
static void F_48 ( struct V_34 * V_35 ,
struct V_14 * V_15 )
{
if ( V_15 -> V_49 & V_55 )
return;
if ( V_15 -> V_49 & V_50 ) {
V_35 -> V_56 -- ;
} else if ( F_47 ( V_15 , V_57 ) ) {
V_35 -> V_56 -- ;
}
}
void F_49 ( struct V_14 * V_15 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
if ( ! ( V_15 -> V_49 & V_50 ) )
V_15 -> V_42 = ( void * ) 0 ;
}
static int F_50 ( struct V_14 * V_15 )
{
if ( V_15 -> V_49 & V_50 )
return 1 ;
if ( F_47 ( V_15 , V_57 ) )
return 1 ;
return 0 ;
}
static void F_51 ( struct V_58 * V_59 , struct V_58 * V_60 )
{
int V_61 ;
struct V_34 * V_35 = F_52 ( V_60 ) ;
struct V_58 * V_62 = V_59 ;
struct V_58 * V_63 = V_60 ;
for ( V_61 = 0 ; V_61 < F_53 ( V_35 ) ; ) {
F_54 () ;
F_55 ( V_59 , V_60 ) ;
V_61 ++ ;
V_59 = F_56 ( V_59 , V_62 , V_61 ) ;
V_60 = F_56 ( V_60 , V_63 , V_61 ) ;
}
}
void F_57 ( struct V_58 * V_59 , struct V_58 * V_60 )
{
int V_61 ;
struct V_34 * V_35 = F_52 ( V_60 ) ;
if ( F_58 ( F_53 ( V_35 ) > V_64 ) ) {
F_51 ( V_59 , V_60 ) ;
return;
}
F_59 () ;
for ( V_61 = 0 ; V_61 < F_53 ( V_35 ) ; V_61 ++ ) {
F_54 () ;
F_55 ( V_59 + V_61 , V_60 + V_61 ) ;
}
}
static void F_60 ( struct V_34 * V_35 , struct V_58 * V_58 )
{
int V_65 = F_61 ( V_58 ) ;
F_62 ( & V_58 -> V_66 , & V_35 -> V_67 [ V_65 ] ) ;
V_35 -> V_68 ++ ;
V_35 -> V_69 [ V_65 ] ++ ;
}
static struct V_58 * F_63 ( struct V_34 * V_35 , int V_65 )
{
struct V_58 * V_58 ;
if ( F_64 ( & V_35 -> V_67 [ V_65 ] ) )
return NULL ;
V_58 = F_24 ( V_35 -> V_67 [ V_65 ] . V_31 , struct V_58 , V_66 ) ;
F_62 ( & V_58 -> V_66 , & V_35 -> V_70 ) ;
F_65 ( V_58 ) ;
V_35 -> V_68 -- ;
V_35 -> V_69 [ V_65 ] -- ;
return V_58 ;
}
static struct V_58 * F_66 ( struct V_34 * V_35 ,
struct V_14 * V_15 ,
unsigned long V_36 , int V_71 )
{
struct V_58 * V_58 = NULL ;
struct V_72 * V_73 ;
T_2 * V_74 ;
struct V_75 * V_75 ;
struct V_76 * V_76 ;
struct V_77 * V_78 ;
unsigned int V_79 ;
V_80:
V_79 = F_67 () ;
V_75 = F_68 ( V_15 , V_36 ,
V_81 , & V_73 , & V_74 ) ;
if ( ! F_50 ( V_15 ) &&
V_35 -> V_68 - V_35 -> V_56 == 0 )
goto V_82;
if ( V_71 && V_35 -> V_68 - V_35 -> V_56 == 0 )
goto V_82;
F_69 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_70 ( V_76 , V_81 ) ) {
V_58 = F_63 ( V_35 , F_71 ( V_76 ) ) ;
if ( V_58 ) {
if ( ! V_71 )
F_48 ( V_35 , V_15 ) ;
break;
}
}
}
F_72 ( V_73 ) ;
if ( F_58 ( ! F_73 ( V_79 ) && ! V_58 ) )
goto V_80;
return V_58 ;
V_82:
F_72 ( V_73 ) ;
return NULL ;
}
static void F_74 ( struct V_34 * V_35 , struct V_58 * V_58 )
{
int V_61 ;
F_44 ( V_35 -> V_40 >= V_83 ) ;
V_35 -> V_84 -- ;
V_35 -> V_85 [ F_61 ( V_58 ) ] -- ;
for ( V_61 = 0 ; V_61 < F_53 ( V_35 ) ; V_61 ++ ) {
V_58 [ V_61 ] . V_53 &= ~ ( 1 << V_86 | 1 << V_87 |
1 << V_88 | 1 << V_89 |
1 << V_90 | 1 << V_91 |
1 << V_92 | 1 << V_93 ) ;
}
F_44 ( F_75 ( V_58 ) ) ;
F_76 ( V_58 , NULL ) ;
F_65 ( V_58 ) ;
F_77 ( V_58 ) ;
F_78 ( V_58 , F_31 ( V_35 ) ) ;
}
struct V_34 * F_79 ( unsigned long V_94 )
{
struct V_34 * V_35 ;
F_80 (h) {
if ( F_81 ( V_35 ) == V_94 )
return V_35 ;
}
return NULL ;
}
static void F_82 ( struct V_58 * V_58 )
{
struct V_34 * V_35 = F_52 ( V_58 ) ;
int V_65 = F_61 ( V_58 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_83 ( V_58 ) ;
F_84 ( V_58 , 0 ) ;
V_58 -> V_95 = NULL ;
F_9 ( F_85 ( V_58 ) ) ;
F_9 ( F_86 ( V_58 ) ) ;
F_8 ( & V_96 ) ;
F_87 ( F_88 ( V_35 ) ,
F_53 ( V_35 ) , V_58 ) ;
if ( V_35 -> V_97 [ V_65 ] && F_31 ( V_35 ) < V_83 ) {
F_19 ( & V_58 -> V_66 ) ;
F_74 ( V_35 , V_58 ) ;
V_35 -> V_98 -- ;
V_35 -> V_97 [ V_65 ] -- ;
} else {
F_89 ( V_58 ) ;
F_60 ( V_35 , V_58 ) ;
}
F_2 ( & V_96 ) ;
F_11 ( V_2 , 1 ) ;
}
static void F_90 ( struct V_34 * V_35 , struct V_58 * V_58 , int V_65 )
{
F_21 ( & V_58 -> V_66 ) ;
F_76 ( V_58 , F_82 ) ;
F_8 ( & V_96 ) ;
F_91 ( V_58 , NULL ) ;
V_35 -> V_84 ++ ;
V_35 -> V_85 [ V_65 ] ++ ;
F_2 ( & V_96 ) ;
F_92 ( V_58 ) ;
}
static void F_93 ( struct V_58 * V_58 , unsigned long V_40 )
{
int V_61 ;
int V_99 = 1 << V_40 ;
struct V_58 * V_100 = V_58 + 1 ;
F_94 ( V_58 , V_40 ) ;
F_95 ( V_58 ) ;
for ( V_61 = 1 ; V_61 < V_99 ; V_61 ++ , V_100 = F_56 ( V_100 , V_58 , V_61 ) ) {
F_96 ( V_100 ) ;
F_97 ( V_100 , 0 ) ;
V_100 -> V_101 = V_58 ;
}
}
int F_98 ( struct V_58 * V_58 )
{
T_3 * V_102 ;
if ( ! F_99 ( V_58 ) )
return 0 ;
V_58 = F_100 ( V_58 ) ;
V_102 = F_101 ( V_58 ) ;
return V_102 == F_82 ;
}
static struct V_58 * F_102 ( struct V_34 * V_35 , int V_65 )
{
struct V_58 * V_58 ;
if ( V_35 -> V_40 >= V_83 )
return NULL ;
V_58 = F_103 ( V_65 ,
V_81 | V_103 | V_104 |
V_105 | V_106 ,
F_31 ( V_35 ) ) ;
if ( V_58 ) {
if ( F_104 ( V_58 ) ) {
F_78 ( V_58 , F_31 ( V_35 ) ) ;
return NULL ;
}
F_90 ( V_35 , V_58 , V_65 ) ;
}
return V_58 ;
}
static int F_105 ( int V_65 , T_2 * V_107 )
{
V_65 = F_106 ( V_65 , * V_107 ) ;
if ( V_65 == V_108 )
V_65 = F_107 ( * V_107 ) ;
F_44 ( V_65 >= V_108 ) ;
return V_65 ;
}
static int F_108 ( int V_65 , T_2 * V_107 )
{
if ( ! F_109 ( V_65 , * V_107 ) )
V_65 = F_105 ( V_65 , V_107 ) ;
return V_65 ;
}
static int F_110 ( struct V_34 * V_35 ,
T_2 * V_107 )
{
int V_65 ;
F_44 ( ! V_107 ) ;
V_65 = F_108 ( V_35 -> V_109 , V_107 ) ;
V_35 -> V_109 = F_105 ( V_65 , V_107 ) ;
return V_65 ;
}
static int F_111 ( struct V_34 * V_35 , T_2 * V_107 )
{
struct V_58 * V_58 ;
int V_110 ;
int V_111 ;
int V_10 = 0 ;
V_110 = F_110 ( V_35 , V_107 ) ;
V_111 = V_110 ;
do {
V_58 = F_102 ( V_35 , V_111 ) ;
if ( V_58 ) {
V_10 = 1 ;
break;
}
V_111 = F_110 ( V_35 , V_107 ) ;
} while ( V_111 != V_110 );
if ( V_10 )
F_112 ( V_112 ) ;
else
F_112 ( V_113 ) ;
return V_10 ;
}
static int F_113 ( struct V_34 * V_35 , T_2 * V_107 )
{
int V_65 ;
F_44 ( ! V_107 ) ;
V_65 = F_108 ( V_35 -> V_114 , V_107 ) ;
V_35 -> V_114 = F_105 ( V_65 , V_107 ) ;
return V_65 ;
}
static int F_114 ( struct V_34 * V_35 , T_2 * V_107 ,
bool V_115 )
{
int V_110 ;
int V_111 ;
int V_10 = 0 ;
V_110 = F_113 ( V_35 , V_107 ) ;
V_111 = V_110 ;
do {
if ( ( ! V_115 || V_35 -> V_97 [ V_111 ] ) &&
! F_64 ( & V_35 -> V_67 [ V_111 ] ) ) {
struct V_58 * V_58 =
F_24 ( V_35 -> V_67 [ V_111 ] . V_31 ,
struct V_58 , V_66 ) ;
F_19 ( & V_58 -> V_66 ) ;
V_35 -> V_68 -- ;
V_35 -> V_69 [ V_111 ] -- ;
if ( V_115 ) {
V_35 -> V_98 -- ;
V_35 -> V_97 [ V_111 ] -- ;
}
F_74 ( V_35 , V_58 ) ;
V_10 = 1 ;
break;
}
V_111 = F_113 ( V_35 , V_107 ) ;
} while ( V_111 != V_110 );
return V_10 ;
}
static struct V_58 * F_115 ( struct V_34 * V_35 , int V_65 )
{
struct V_58 * V_58 ;
unsigned int V_116 ;
if ( V_35 -> V_40 >= V_83 )
return NULL ;
F_8 ( & V_96 ) ;
if ( V_35 -> V_98 >= V_35 -> V_117 ) {
F_2 ( & V_96 ) ;
return NULL ;
} else {
V_35 -> V_84 ++ ;
V_35 -> V_98 ++ ;
}
F_2 ( & V_96 ) ;
if ( V_65 == V_118 )
V_58 = F_116 ( V_81 | V_103 |
V_105 | V_106 ,
F_31 ( V_35 ) ) ;
else
V_58 = F_103 ( V_65 ,
V_81 | V_103 | V_104 |
V_105 | V_106 , F_31 ( V_35 ) ) ;
if ( V_58 && F_104 ( V_58 ) ) {
F_78 ( V_58 , F_31 ( V_35 ) ) ;
V_58 = NULL ;
}
F_8 ( & V_96 ) ;
if ( V_58 ) {
F_21 ( & V_58 -> V_66 ) ;
V_116 = F_61 ( V_58 ) ;
F_76 ( V_58 , F_82 ) ;
F_91 ( V_58 , NULL ) ;
V_35 -> V_85 [ V_116 ] ++ ;
V_35 -> V_97 [ V_116 ] ++ ;
F_117 ( V_112 ) ;
} else {
V_35 -> V_84 -- ;
V_35 -> V_98 -- ;
F_117 ( V_113 ) ;
}
F_2 ( & V_96 ) ;
return V_58 ;
}
struct V_58 * F_118 ( struct V_34 * V_35 , int V_65 )
{
struct V_58 * V_58 ;
F_8 ( & V_96 ) ;
V_58 = F_63 ( V_35 , V_65 ) ;
F_2 ( & V_96 ) ;
if ( ! V_58 )
V_58 = F_115 ( V_35 , V_65 ) ;
return V_58 ;
}
static int F_119 ( struct V_34 * V_35 , int V_9 )
{
struct V_17 V_119 ;
struct V_58 * V_58 , * V_120 ;
int V_10 , V_61 ;
int V_121 , V_122 ;
bool V_123 = true ;
V_121 = ( V_35 -> V_56 + V_9 ) - V_35 -> V_68 ;
if ( V_121 <= 0 ) {
V_35 -> V_56 += V_9 ;
return 0 ;
}
V_122 = 0 ;
F_21 ( & V_119 ) ;
V_10 = - V_11 ;
V_124:
F_2 ( & V_96 ) ;
for ( V_61 = 0 ; V_61 < V_121 ; V_61 ++ ) {
V_58 = F_115 ( V_35 , V_118 ) ;
if ( ! V_58 ) {
V_123 = false ;
break;
}
F_22 ( & V_58 -> V_66 , & V_119 ) ;
}
V_122 += V_61 ;
F_8 ( & V_96 ) ;
V_121 = ( V_35 -> V_56 + V_9 ) -
( V_35 -> V_68 + V_122 ) ;
if ( V_121 > 0 ) {
if ( V_123 )
goto V_124;
goto free;
}
V_121 += V_122 ;
V_35 -> V_56 += V_9 ;
V_10 = 0 ;
F_18 (page, tmp, &surplus_list, lru) {
if ( ( -- V_121 ) < 0 )
break;
F_120 ( V_58 ) ;
F_44 ( F_85 ( V_58 ) ) ;
F_60 ( V_35 , V_58 ) ;
}
free:
F_2 ( & V_96 ) ;
if ( ! F_64 ( & V_119 ) ) {
F_18 (page, tmp, &surplus_list, lru) {
F_92 ( V_58 ) ;
}
}
F_8 ( & V_96 ) ;
return V_10 ;
}
static void F_121 ( struct V_34 * V_35 ,
unsigned long V_125 )
{
unsigned long V_99 ;
V_35 -> V_56 -= V_125 ;
if ( V_35 -> V_40 >= V_83 )
return;
V_99 = F_28 ( V_125 , V_35 -> V_98 ) ;
while ( V_99 -- ) {
if ( ! F_114 ( V_35 , & V_126 [ V_127 ] , 1 ) )
break;
}
}
static long F_122 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_128 )
{
struct V_129 * V_95 = V_15 -> V_16 -> V_130 ;
struct V_12 * V_12 = V_95 -> V_131 ;
if ( V_15 -> V_49 & V_50 ) {
T_1 V_132 = F_29 ( V_35 , V_15 , V_128 ) ;
return F_20 ( & V_12 -> V_133 -> V_134 ,
V_132 , V_132 + 1 ) ;
} else if ( ! F_47 ( V_15 , V_57 ) ) {
return 1 ;
} else {
long V_82 ;
T_1 V_132 = F_29 ( V_35 , V_15 , V_128 ) ;
struct V_44 * V_135 = F_43 ( V_15 ) ;
V_82 = F_20 ( & V_135 -> V_46 , V_132 , V_132 + 1 ) ;
if ( V_82 < 0 )
return V_82 ;
return 0 ;
}
}
static void F_123 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_128 )
{
struct V_129 * V_95 = V_15 -> V_16 -> V_130 ;
struct V_12 * V_12 = V_95 -> V_131 ;
if ( V_15 -> V_49 & V_50 ) {
T_1 V_132 = F_29 ( V_35 , V_15 , V_128 ) ;
F_16 ( & V_12 -> V_133 -> V_134 , V_132 , V_132 + 1 ) ;
} else if ( F_47 ( V_15 , V_57 ) ) {
T_1 V_132 = F_29 ( V_35 , V_15 , V_128 ) ;
struct V_44 * V_135 = F_43 ( V_15 ) ;
F_16 ( & V_135 -> V_46 , V_132 , V_132 + 1 ) ;
}
}
static struct V_58 * F_124 ( struct V_14 * V_15 ,
unsigned long V_128 , int V_71 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_58 * V_58 ;
long V_28 ;
int V_10 , V_132 ;
struct V_136 * V_137 ;
V_132 = F_88 ( V_35 ) ;
V_28 = F_122 ( V_35 , V_15 , V_128 ) ;
if ( V_28 < 0 )
return F_125 ( - V_11 ) ;
if ( V_28 )
if ( F_10 ( V_2 , V_28 ) )
return F_125 ( - V_138 ) ;
V_10 = F_126 ( V_132 , F_53 ( V_35 ) , & V_137 ) ;
if ( V_10 ) {
F_11 ( V_2 , V_28 ) ;
return F_125 ( - V_138 ) ;
}
F_8 ( & V_96 ) ;
V_58 = F_66 ( V_35 , V_15 , V_128 , V_71 ) ;
if ( V_58 ) {
F_127 ( V_132 , F_53 ( V_35 ) ,
V_137 , V_58 ) ;
F_2 ( & V_96 ) ;
} else {
F_2 ( & V_96 ) ;
V_58 = F_115 ( V_35 , V_118 ) ;
if ( ! V_58 ) {
F_128 ( V_132 ,
F_53 ( V_35 ) ,
V_137 ) ;
F_11 ( V_2 , V_28 ) ;
return F_125 ( - V_138 ) ;
}
F_8 ( & V_96 ) ;
F_127 ( V_132 , F_53 ( V_35 ) ,
V_137 , V_58 ) ;
F_62 ( & V_58 -> V_66 , & V_35 -> V_70 ) ;
F_2 ( & V_96 ) ;
}
F_84 ( V_58 , ( unsigned long ) V_2 ) ;
F_123 ( V_35 , V_15 , V_128 ) ;
return V_58 ;
}
int __weak F_129 ( struct V_34 * V_35 )
{
struct V_139 * V_140 ;
int V_141 = F_130 ( V_126 [ V_127 ] ) ;
while ( V_141 ) {
void * V_128 ;
V_128 = F_131 (
F_132 ( F_110 ( V_35 ,
& V_126 [ V_127 ] ) ) ,
F_81 ( V_35 ) , F_81 ( V_35 ) , 0 ) ;
if ( V_128 ) {
V_140 = V_128 ;
goto V_142;
}
V_141 -- ;
}
return 0 ;
V_142:
F_9 ( ( unsigned long ) F_133 ( V_140 ) & ( F_81 ( V_35 ) - 1 ) ) ;
F_22 ( & V_140 -> V_143 , & V_144 ) ;
V_140 -> V_34 = V_35 ;
return 1 ;
}
static void F_134 ( struct V_58 * V_58 , int V_40 )
{
if ( F_58 ( V_40 > ( V_83 - 1 ) ) )
F_93 ( V_58 , V_40 ) ;
else
F_135 ( V_58 , V_40 ) ;
}
static void T_4 F_136 ( void )
{
struct V_139 * V_140 ;
F_17 (m, &huge_boot_pages, list) {
struct V_34 * V_35 = V_140 -> V_34 ;
struct V_58 * V_58 ;
#ifdef F_137
V_58 = F_138 ( V_140 -> V_145 >> V_41 ) ;
F_139 ( ( unsigned long ) V_140 ,
sizeof( struct V_139 ) ) ;
#else
V_58 = F_140 ( V_140 ) ;
#endif
F_141 ( V_58 ) ;
F_142 ( F_85 ( V_58 ) != 1 ) ;
F_134 ( V_58 , V_35 -> V_40 ) ;
F_90 ( V_35 , V_58 , F_61 ( V_58 ) ) ;
if ( V_35 -> V_40 > ( V_83 - 1 ) )
V_146 += 1 << V_35 -> V_40 ;
}
}
static void T_4 F_143 ( struct V_34 * V_35 )
{
unsigned long V_61 ;
for ( V_61 = 0 ; V_61 < V_35 -> V_147 ; ++ V_61 ) {
if ( V_35 -> V_40 >= V_83 ) {
if ( ! F_129 ( V_35 ) )
break;
} else if ( ! F_111 ( V_35 ,
& V_126 [ V_127 ] ) )
break;
}
V_35 -> V_147 = V_61 ;
}
static void T_4 F_144 ( void )
{
struct V_34 * V_35 ;
F_80 (h) {
if ( V_35 -> V_40 < V_83 )
F_143 ( V_35 ) ;
}
}
static char * T_4 F_145 ( char * V_148 , unsigned long V_149 )
{
if ( V_149 >= ( 1UL << 30 ) )
sprintf ( V_148 , L_1 , V_149 >> 30 ) ;
else if ( V_149 >= ( 1UL << 20 ) )
sprintf ( V_148 , L_2 , V_149 >> 20 ) ;
else
sprintf ( V_148 , L_3 , V_149 >> 10 ) ;
return V_148 ;
}
static void T_4 F_146 ( void )
{
struct V_34 * V_35 ;
F_80 (h) {
char V_148 [ 32 ] ;
F_147 ( L_4 ,
F_145 ( V_148 , F_81 ( V_35 ) ) ,
V_35 -> V_68 ) ;
}
}
static void F_148 ( struct V_34 * V_35 , unsigned long V_3 ,
T_2 * V_107 )
{
int V_61 ;
if ( V_35 -> V_40 >= V_83 )
return;
F_149 (i, *nodes_allowed) {
struct V_58 * V_58 , * V_31 ;
struct V_17 * V_150 = & V_35 -> V_67 [ V_61 ] ;
F_18 (page, next, freel, lru) {
if ( V_3 >= V_35 -> V_84 )
return;
if ( F_150 ( V_58 ) )
continue;
F_19 ( & V_58 -> V_66 ) ;
F_74 ( V_35 , V_58 ) ;
V_35 -> V_68 -- ;
V_35 -> V_69 [ F_61 ( V_58 ) ] -- ;
}
}
}
static inline void F_148 ( struct V_34 * V_35 , unsigned long V_3 ,
T_2 * V_107 )
{
}
static int F_151 ( struct V_34 * V_35 , T_2 * V_107 ,
int V_9 )
{
int V_110 , V_111 ;
int V_10 = 0 ;
F_44 ( V_9 != - 1 && V_9 != 1 ) ;
if ( V_9 < 0 )
V_110 = F_110 ( V_35 , V_107 ) ;
else
V_110 = F_113 ( V_35 , V_107 ) ;
V_111 = V_110 ;
do {
int V_65 = V_111 ;
if ( V_9 < 0 ) {
if ( ! V_35 -> V_97 [ V_65 ] ) {
V_111 = F_110 ( V_35 ,
V_107 ) ;
continue;
}
}
if ( V_9 > 0 ) {
if ( V_35 -> V_97 [ V_65 ] >=
V_35 -> V_85 [ V_65 ] ) {
V_111 = F_113 ( V_35 ,
V_107 ) ;
continue;
}
}
V_35 -> V_98 += V_9 ;
V_35 -> V_97 [ V_65 ] += V_9 ;
V_10 = 1 ;
break;
} while ( V_111 != V_110 );
return V_10 ;
}
static unsigned long F_152 ( struct V_34 * V_35 , unsigned long V_3 ,
T_2 * V_107 )
{
unsigned long V_151 , V_10 ;
if ( V_35 -> V_40 >= V_83 )
return V_35 -> V_147 ;
F_8 ( & V_96 ) ;
while ( V_35 -> V_98 && V_3 > F_153 ( V_35 ) ) {
if ( ! F_151 ( V_35 , V_107 , - 1 ) )
break;
}
while ( V_3 > F_153 ( V_35 ) ) {
F_2 ( & V_96 ) ;
V_10 = F_111 ( V_35 , V_107 ) ;
F_8 ( & V_96 ) ;
if ( ! V_10 )
goto V_152;
if ( F_154 ( V_153 ) )
goto V_152;
}
V_151 = V_35 -> V_56 + V_35 -> V_84 - V_35 -> V_68 ;
V_151 = F_27 ( V_3 , V_151 ) ;
F_148 ( V_35 , V_151 , V_107 ) ;
while ( V_151 < F_153 ( V_35 ) ) {
if ( ! F_114 ( V_35 , V_107 , 0 ) )
break;
}
while ( V_3 < F_153 ( V_35 ) ) {
if ( ! F_151 ( V_35 , V_107 , 1 ) )
break;
}
V_152:
V_10 = F_153 ( V_35 ) ;
F_2 ( & V_96 ) ;
return V_10 ;
}
static struct V_34 * F_155 ( struct V_154 * V_155 , int * V_156 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_157 ; V_61 ++ )
if ( V_158 [ V_61 ] == V_155 ) {
if ( V_156 )
* V_156 = V_118 ;
return & V_159 [ V_61 ] ;
}
return F_156 ( V_155 , V_156 ) ;
}
static T_5 F_157 ( struct V_154 * V_155 ,
struct V_160 * V_161 , char * V_148 )
{
struct V_34 * V_35 ;
unsigned long V_84 ;
int V_65 ;
V_35 = F_155 ( V_155 , & V_65 ) ;
if ( V_65 == V_118 )
V_84 = V_35 -> V_84 ;
else
V_84 = V_35 -> V_85 [ V_65 ] ;
return sprintf ( V_148 , L_5 , V_84 ) ;
}
static T_5 F_158 ( bool V_162 ,
struct V_154 * V_155 , struct V_160 * V_161 ,
const char * V_148 , T_6 V_163 )
{
int V_82 ;
int V_65 ;
unsigned long V_3 ;
struct V_34 * V_35 ;
F_159 ( T_2 , V_107 , V_7 | V_164 ) ;
V_82 = F_160 ( V_148 , 10 , & V_3 ) ;
if ( V_82 )
goto V_152;
V_35 = F_155 ( V_155 , & V_65 ) ;
if ( V_35 -> V_40 >= V_83 ) {
V_82 = - V_165 ;
goto V_152;
}
if ( V_65 == V_118 ) {
if ( ! ( V_162 &&
F_161 ( V_107 ) ) ) {
F_162 ( V_107 ) ;
V_107 = & V_126 [ V_127 ] ;
}
} else if ( V_107 ) {
V_3 += V_35 -> V_84 - V_35 -> V_85 [ V_65 ] ;
F_163 ( V_107 , V_65 ) ;
} else
V_107 = & V_126 [ V_127 ] ;
V_35 -> V_147 = F_152 ( V_35 , V_3 , V_107 ) ;
if ( V_107 != & V_126 [ V_127 ] )
F_162 ( V_107 ) ;
return V_163 ;
V_152:
F_162 ( V_107 ) ;
return V_82 ;
}
static T_5 F_164 ( struct V_154 * V_155 ,
struct V_160 * V_161 , char * V_148 )
{
return F_157 ( V_155 , V_161 , V_148 ) ;
}
static T_5 F_165 ( struct V_154 * V_155 ,
struct V_160 * V_161 , const char * V_148 , T_6 V_163 )
{
return F_158 ( false , V_155 , V_161 , V_148 , V_163 ) ;
}
static T_5 F_166 ( struct V_154 * V_155 ,
struct V_160 * V_161 , char * V_148 )
{
return F_157 ( V_155 , V_161 , V_148 ) ;
}
static T_5 F_167 ( struct V_154 * V_155 ,
struct V_160 * V_161 , const char * V_148 , T_6 V_163 )
{
return F_158 ( true , V_155 , V_161 , V_148 , V_163 ) ;
}
static T_5 F_168 ( struct V_154 * V_155 ,
struct V_160 * V_161 , char * V_148 )
{
struct V_34 * V_35 = F_155 ( V_155 , NULL ) ;
return sprintf ( V_148 , L_5 , V_35 -> V_117 ) ;
}
static T_5 F_169 ( struct V_154 * V_155 ,
struct V_160 * V_161 , const char * V_148 , T_6 V_3 )
{
int V_82 ;
unsigned long V_166 ;
struct V_34 * V_35 = F_155 ( V_155 , NULL ) ;
if ( V_35 -> V_40 >= V_83 )
return - V_165 ;
V_82 = F_160 ( V_148 , 10 , & V_166 ) ;
if ( V_82 )
return V_82 ;
F_8 ( & V_96 ) ;
V_35 -> V_117 = V_166 ;
F_2 ( & V_96 ) ;
return V_3 ;
}
static T_5 F_170 ( struct V_154 * V_155 ,
struct V_160 * V_161 , char * V_148 )
{
struct V_34 * V_35 ;
unsigned long V_68 ;
int V_65 ;
V_35 = F_155 ( V_155 , & V_65 ) ;
if ( V_65 == V_118 )
V_68 = V_35 -> V_68 ;
else
V_68 = V_35 -> V_69 [ V_65 ] ;
return sprintf ( V_148 , L_5 , V_68 ) ;
}
static T_5 F_171 ( struct V_154 * V_155 ,
struct V_160 * V_161 , char * V_148 )
{
struct V_34 * V_35 = F_155 ( V_155 , NULL ) ;
return sprintf ( V_148 , L_5 , V_35 -> V_56 ) ;
}
static T_5 F_172 ( struct V_154 * V_155 ,
struct V_160 * V_161 , char * V_148 )
{
struct V_34 * V_35 ;
unsigned long V_98 ;
int V_65 ;
V_35 = F_155 ( V_155 , & V_65 ) ;
if ( V_65 == V_118 )
V_98 = V_35 -> V_98 ;
else
V_98 = V_35 -> V_97 [ V_65 ] ;
return sprintf ( V_148 , L_5 , V_98 ) ;
}
static int F_173 ( struct V_34 * V_35 , struct V_154 * V_167 ,
struct V_154 * * V_158 ,
struct V_168 * V_169 )
{
int V_170 ;
int V_171 = F_88 ( V_35 ) ;
V_158 [ V_171 ] = F_174 ( V_35 -> V_172 , V_167 ) ;
if ( ! V_158 [ V_171 ] )
return - V_11 ;
V_170 = F_175 ( V_158 [ V_171 ] , V_169 ) ;
if ( V_170 )
F_176 ( V_158 [ V_171 ] ) ;
return V_170 ;
}
static void T_4 F_177 ( void )
{
struct V_34 * V_35 ;
int V_82 ;
V_173 = F_174 ( L_6 , V_174 ) ;
if ( ! V_173 )
return;
F_80 (h) {
V_82 = F_173 ( V_35 , V_173 ,
V_158 , & V_169 ) ;
if ( V_82 )
F_178 ( L_7 , V_35 -> V_172 ) ;
}
}
static struct V_34 * F_156 ( struct V_154 * V_155 , int * V_156 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_175 ; V_65 ++ ) {
struct V_176 * V_177 = & V_178 [ V_65 ] ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_157 ; V_61 ++ )
if ( V_177 -> V_158 [ V_61 ] == V_155 ) {
if ( V_156 )
* V_156 = V_65 ;
return & V_159 [ V_61 ] ;
}
}
F_179 () ;
return NULL ;
}
void F_180 ( struct V_179 * V_179 )
{
struct V_34 * V_35 ;
struct V_176 * V_177 = & V_178 [ V_179 -> V_180 . V_181 ] ;
if ( ! V_177 -> V_173 )
return;
F_80 (h) {
int V_132 = F_88 ( V_35 ) ;
if ( V_177 -> V_158 [ V_132 ] ) {
F_176 ( V_177 -> V_158 [ V_132 ] ) ;
V_177 -> V_158 [ V_132 ] = NULL ;
}
}
F_176 ( V_177 -> V_173 ) ;
V_177 -> V_173 = NULL ;
}
static void F_181 ( void )
{
int V_65 ;
F_182 ( NULL , NULL ) ;
for ( V_65 = 0 ; V_65 < V_175 ; V_65 ++ )
F_180 ( V_182 [ V_65 ] ) ;
}
void F_183 ( struct V_179 * V_179 )
{
struct V_34 * V_35 ;
struct V_176 * V_177 = & V_178 [ V_179 -> V_180 . V_181 ] ;
int V_82 ;
if ( V_177 -> V_173 )
return;
V_177 -> V_173 = F_174 ( L_6 ,
& V_179 -> V_180 . V_155 ) ;
if ( ! V_177 -> V_173 )
return;
F_80 (h) {
V_82 = F_173 ( V_35 , V_177 -> V_173 ,
V_177 -> V_158 ,
& V_183 ) ;
if ( V_82 ) {
F_178 ( L_8 ,
V_35 -> V_172 , V_179 -> V_180 . V_181 ) ;
F_180 ( V_179 ) ;
break;
}
}
}
static void F_184 ( void )
{
int V_65 ;
F_185 (nid, N_MEMORY) {
struct V_179 * V_179 = V_182 [ V_65 ] ;
if ( V_179 -> V_180 . V_181 == V_65 )
F_183 ( V_179 ) ;
}
F_182 ( F_183 ,
F_180 ) ;
}
static struct V_34 * F_156 ( struct V_154 * V_155 , int * V_156 )
{
F_179 () ;
if ( V_156 )
* V_156 = - 1 ;
return NULL ;
}
static void F_181 ( void ) { }
static void F_184 ( void ) { }
static void T_7 F_186 ( void )
{
struct V_34 * V_35 ;
F_181 () ;
F_80 (h) {
F_176 ( V_158 [ F_88 ( V_35 ) ] ) ;
}
F_176 ( V_173 ) ;
}
static int T_4 F_187 ( void )
{
if ( V_184 == 0 )
return 0 ;
if ( ! F_79 ( V_185 ) ) {
V_185 = V_186 ;
if ( ! F_79 ( V_185 ) )
F_188 ( V_187 ) ;
}
V_188 = F_88 ( F_79 ( V_185 ) ) ;
if ( V_189 )
V_190 . V_147 = V_189 ;
F_144 () ;
F_136 () ;
F_146 () ;
F_177 () ;
F_184 () ;
F_189 () ;
return 0 ;
}
void T_4 F_188 ( unsigned V_40 )
{
struct V_34 * V_35 ;
unsigned long V_61 ;
if ( F_79 ( V_39 << V_40 ) ) {
F_190 ( L_9 ) ;
return;
}
F_9 ( V_191 >= V_157 ) ;
F_9 ( V_40 == 0 ) ;
V_35 = & V_159 [ V_191 ++ ] ;
V_35 -> V_40 = V_40 ;
V_35 -> V_192 = ~ ( ( 1ULL << ( V_40 + V_41 ) ) - 1 ) ;
V_35 -> V_84 = 0 ;
V_35 -> V_68 = 0 ;
for ( V_61 = 0 ; V_61 < V_108 ; ++ V_61 )
F_21 ( & V_35 -> V_67 [ V_61 ] ) ;
F_21 ( & V_35 -> V_70 ) ;
V_35 -> V_109 = F_107 ( V_126 [ V_127 ] ) ;
V_35 -> V_114 = F_107 ( V_126 [ V_127 ] ) ;
snprintf ( V_35 -> V_172 , V_193 , L_10 ,
F_81 ( V_35 ) / 1024 ) ;
V_194 = V_35 ;
}
static int T_4 F_191 ( char * V_195 )
{
unsigned long * V_196 ;
static unsigned long * V_197 ;
if ( ! V_191 )
V_196 = & V_189 ;
else
V_196 = & V_194 -> V_147 ;
if ( V_196 == V_197 ) {
F_190 ( L_11
L_12 ) ;
return 1 ;
}
if ( sscanf ( V_195 , L_13 , V_196 ) <= 0 )
* V_196 = 0 ;
if ( V_191 && V_194 -> V_40 >= V_83 )
F_143 ( V_194 ) ;
V_197 = V_196 ;
return 1 ;
}
static int T_4 F_192 ( char * V_195 )
{
V_185 = F_193 ( V_195 , & V_195 ) ;
return 1 ;
}
static unsigned int F_194 ( unsigned int * V_198 )
{
int V_179 ;
unsigned int V_199 = 0 ;
F_149 (node, cpuset_current_mems_allowed)
V_199 += V_198 [ V_179 ] ;
return V_199 ;
}
static int F_195 ( bool V_162 ,
struct V_200 * V_201 , int V_202 ,
void T_8 * V_203 , T_6 * V_204 , T_9 * V_205 )
{
struct V_34 * V_35 = & V_190 ;
unsigned long V_120 ;
int V_10 ;
V_120 = V_35 -> V_147 ;
if ( V_202 && V_35 -> V_40 >= V_83 )
return - V_165 ;
V_201 -> V_206 = & V_120 ;
V_201 -> V_207 = sizeof( unsigned long ) ;
V_10 = F_196 ( V_201 , V_202 , V_203 , V_204 , V_205 ) ;
if ( V_10 )
goto V_152;
if ( V_202 ) {
F_159 ( T_2 , V_107 ,
V_7 | V_164 ) ;
if ( ! ( V_162 &&
F_161 ( V_107 ) ) ) {
F_162 ( V_107 ) ;
V_107 = & V_126 [ V_127 ] ;
}
V_35 -> V_147 = F_152 ( V_35 , V_120 , V_107 ) ;
if ( V_107 != & V_126 [ V_127 ] )
F_162 ( V_107 ) ;
}
V_152:
return V_10 ;
}
int F_197 ( struct V_200 * V_201 , int V_202 ,
void T_8 * V_203 , T_6 * V_204 , T_9 * V_205 )
{
return F_195 ( false , V_201 , V_202 ,
V_203 , V_204 , V_205 ) ;
}
int F_198 ( struct V_200 * V_201 , int V_202 ,
void T_8 * V_203 , T_6 * V_204 , T_9 * V_205 )
{
return F_195 ( true , V_201 , V_202 ,
V_203 , V_204 , V_205 ) ;
}
int F_199 ( struct V_200 * V_201 , int V_202 ,
void T_8 * V_203 ,
T_6 * V_204 , T_9 * V_205 )
{
F_200 ( V_201 , V_202 , V_203 , V_204 , V_205 ) ;
if ( V_208 )
V_81 = V_209 ;
else
V_81 = V_210 ;
return 0 ;
}
int F_201 ( struct V_200 * V_201 , int V_202 ,
void T_8 * V_203 ,
T_6 * V_204 , T_9 * V_205 )
{
struct V_34 * V_35 = & V_190 ;
unsigned long V_120 ;
int V_10 ;
V_120 = V_35 -> V_117 ;
if ( V_202 && V_35 -> V_40 >= V_83 )
return - V_165 ;
V_201 -> V_206 = & V_120 ;
V_201 -> V_207 = sizeof( unsigned long ) ;
V_10 = F_196 ( V_201 , V_202 , V_203 , V_204 , V_205 ) ;
if ( V_10 )
goto V_152;
if ( V_202 ) {
F_8 ( & V_96 ) ;
V_35 -> V_117 = V_120 ;
F_2 ( & V_96 ) ;
}
V_152:
return V_10 ;
}
void F_202 ( struct V_211 * V_140 )
{
struct V_34 * V_35 = & V_190 ;
F_203 ( V_140 ,
L_14
L_15
L_16
L_17
L_18 ,
V_35 -> V_84 ,
V_35 -> V_68 ,
V_35 -> V_56 ,
V_35 -> V_98 ,
1UL << ( F_31 ( V_35 ) + V_41 - 10 ) ) ;
}
int F_204 ( int V_65 , char * V_148 )
{
struct V_34 * V_35 = & V_190 ;
return sprintf ( V_148 ,
L_19
L_20
L_21 ,
V_65 , V_35 -> V_85 [ V_65 ] ,
V_65 , V_35 -> V_69 [ V_65 ] ,
V_65 , V_35 -> V_97 [ V_65 ] ) ;
}
unsigned long F_205 ( void )
{
struct V_34 * V_35 ;
unsigned long V_212 = 0 ;
F_80 (h)
V_212 += V_35 -> V_84 * F_53 ( V_35 ) ;
return V_212 ;
}
static int F_206 ( struct V_34 * V_35 , long V_9 )
{
int V_10 = - V_11 ;
F_8 ( & V_96 ) ;
if ( V_9 > 0 ) {
if ( F_119 ( V_35 , V_9 ) < 0 )
goto V_152;
if ( V_9 > F_194 ( V_35 -> V_69 ) ) {
F_121 ( V_35 , V_9 ) ;
goto V_152;
}
}
V_10 = 0 ;
if ( V_9 < 0 )
F_121 ( V_35 , ( unsigned long ) - V_9 ) ;
V_152:
F_2 ( & V_96 ) ;
return V_10 ;
}
static void F_207 ( struct V_14 * V_15 )
{
struct V_44 * V_135 = F_43 ( V_15 ) ;
if ( V_135 )
F_208 ( & V_135 -> V_45 ) ;
}
static void F_209 ( struct V_14 * V_15 )
{
struct V_44 * V_135 = F_43 ( V_15 ) ;
if ( ! V_135 )
return;
F_210 ( & V_135 -> V_45 , F_41 ) ;
}
static void F_211 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_44 * V_135 = F_43 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_15 ) ;
unsigned long V_213 ;
unsigned long V_214 ;
unsigned long V_30 ;
if ( V_135 ) {
V_214 = F_29 ( V_35 , V_15 , V_15 -> V_37 ) ;
V_30 = F_29 ( V_35 , V_15 , V_15 -> V_215 ) ;
V_213 = ( V_30 - V_214 ) -
F_26 ( & V_135 -> V_46 , V_214 , V_30 ) ;
F_209 ( V_15 ) ;
if ( V_213 ) {
F_206 ( V_35 , - V_213 ) ;
F_11 ( V_2 , V_213 ) ;
}
}
}
static int F_212 ( struct V_14 * V_15 , struct V_216 * V_217 )
{
F_179 () ;
return 0 ;
}
static T_10 F_213 ( struct V_14 * V_15 , struct V_58 * V_58 ,
int V_218 )
{
T_10 V_219 ;
if ( V_218 ) {
V_219 =
F_214 ( F_215 ( F_216 ( V_58 , V_15 -> V_220 ) ) ) ;
} else {
V_219 = F_217 ( F_216 ( V_58 , V_15 -> V_220 ) ) ;
}
V_219 = F_218 ( V_219 ) ;
V_219 = F_219 ( V_219 ) ;
V_219 = F_220 ( V_219 , V_15 , V_58 , V_218 ) ;
return V_219 ;
}
static void F_221 ( struct V_14 * V_15 ,
unsigned long V_36 , T_10 * V_221 )
{
T_10 V_219 ;
V_219 = F_214 ( F_215 ( F_222 ( V_221 ) ) ) ;
if ( F_223 ( V_15 , V_36 , V_221 , V_219 , 1 ) )
F_224 ( V_15 , V_36 , V_221 ) ;
}
int F_225 ( struct V_222 * V_59 , struct V_222 * V_60 ,
struct V_14 * V_15 )
{
T_10 * V_223 , * V_224 , V_219 ;
struct V_58 * V_225 ;
unsigned long V_128 ;
int V_226 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_227 = F_81 ( V_35 ) ;
V_226 = ( V_15 -> V_49 & ( V_228 | V_229 ) ) == V_229 ;
for ( V_128 = V_15 -> V_37 ; V_128 < V_15 -> V_215 ; V_128 += V_227 ) {
V_223 = F_226 ( V_60 , V_128 ) ;
if ( ! V_223 )
continue;
V_224 = F_227 ( V_59 , V_128 , V_227 ) ;
if ( ! V_224 )
goto V_230;
if ( V_224 == V_223 )
continue;
F_8 ( & V_59 -> V_231 ) ;
F_228 ( & V_60 -> V_231 , V_232 ) ;
if ( ! F_229 ( F_222 ( V_223 ) ) ) {
if ( V_226 )
F_230 ( V_60 , V_128 , V_223 ) ;
V_219 = F_222 ( V_223 ) ;
V_225 = F_231 ( V_219 ) ;
F_232 ( V_225 ) ;
F_233 ( V_225 ) ;
F_234 ( V_59 , V_128 , V_224 , V_219 ) ;
}
F_2 ( & V_60 -> V_231 ) ;
F_2 ( & V_59 -> V_231 ) ;
}
return 0 ;
V_230:
return - V_11 ;
}
static int F_235 ( T_10 V_233 )
{
T_11 V_234 ;
if ( F_229 ( V_233 ) || F_236 ( V_233 ) )
return 0 ;
V_234 = F_237 ( V_233 ) ;
if ( F_238 ( V_234 ) && F_239 ( V_234 ) )
return 1 ;
else
return 0 ;
}
static int F_240 ( T_10 V_233 )
{
T_11 V_234 ;
if ( F_229 ( V_233 ) || F_236 ( V_233 ) )
return 0 ;
V_234 = F_237 ( V_233 ) ;
if ( F_238 ( V_234 ) && F_241 ( V_234 ) )
return 1 ;
else
return 0 ;
}
void F_242 ( struct V_235 * V_236 , struct V_14 * V_15 ,
unsigned long V_214 , unsigned long V_30 ,
struct V_58 * V_237 )
{
int V_238 = 0 ;
struct V_222 * V_239 = V_15 -> V_240 ;
unsigned long V_36 ;
T_10 * V_221 ;
T_10 V_233 ;
struct V_58 * V_58 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_227 = F_81 ( V_35 ) ;
const unsigned long V_241 = V_214 ;
const unsigned long V_242 = V_30 ;
F_142 ( ! F_35 ( V_15 ) ) ;
F_9 ( V_214 & ~ F_243 ( V_35 ) ) ;
F_9 ( V_30 & ~ F_243 ( V_35 ) ) ;
F_244 ( V_236 , V_15 ) ;
F_245 ( V_239 , V_241 , V_242 ) ;
V_243:
F_8 ( & V_239 -> V_231 ) ;
for ( V_36 = V_214 ; V_36 < V_30 ; V_36 += V_227 ) {
V_221 = F_226 ( V_239 , V_36 ) ;
if ( ! V_221 )
continue;
if ( F_246 ( V_239 , & V_36 , V_221 ) )
continue;
V_233 = F_222 ( V_221 ) ;
if ( F_229 ( V_233 ) )
continue;
if ( F_58 ( F_240 ( V_233 ) ) ) {
F_247 ( V_239 , V_36 , V_221 ) ;
continue;
}
V_58 = F_231 ( V_233 ) ;
if ( V_237 ) {
if ( V_58 != V_237 )
continue;
F_46 ( V_15 , V_244 ) ;
}
V_233 = F_248 ( V_239 , V_36 , V_221 ) ;
F_249 ( V_236 , V_221 , V_36 ) ;
if ( F_250 ( V_233 ) )
F_251 ( V_58 ) ;
F_252 ( V_58 ) ;
V_238 = ! F_253 ( V_236 , V_58 ) ;
if ( V_238 )
break;
if ( V_237 )
break;
}
F_2 ( & V_239 -> V_231 ) ;
if ( V_238 ) {
V_238 = 0 ;
F_254 ( V_236 ) ;
if ( V_36 < V_30 && ! V_237 )
goto V_243;
}
F_255 ( V_239 , V_241 , V_242 ) ;
F_256 ( V_236 , V_15 ) ;
}
void F_257 ( struct V_235 * V_236 ,
struct V_14 * V_15 , unsigned long V_214 ,
unsigned long V_30 , struct V_58 * V_237 )
{
F_242 ( V_236 , V_15 , V_214 , V_30 , V_237 ) ;
V_15 -> V_49 &= ~ V_50 ;
}
void F_258 ( struct V_14 * V_15 , unsigned long V_214 ,
unsigned long V_30 , struct V_58 * V_237 )
{
struct V_222 * V_239 ;
struct V_235 V_236 ;
V_239 = V_15 -> V_240 ;
F_259 ( & V_236 , V_239 , 0 ) ;
F_242 ( & V_236 , V_15 , V_214 , V_30 , V_237 ) ;
F_260 ( & V_236 , V_214 , V_30 ) ;
}
static int F_261 ( struct V_222 * V_239 , struct V_14 * V_15 ,
struct V_58 * V_58 , unsigned long V_36 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_14 * V_245 ;
struct V_129 * V_95 ;
T_1 V_246 ;
V_36 = V_36 & F_243 ( V_35 ) ;
V_246 = ( ( V_36 - V_15 -> V_37 ) >> V_41 ) +
V_15 -> V_38 ;
V_95 = F_15 ( V_15 -> V_16 ) -> V_133 ;
F_262 ( & V_95 -> V_247 ) ;
F_263 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_245 == V_15 )
continue;
if ( ! F_47 ( V_245 , V_57 ) )
F_258 ( V_245 , V_36 ,
V_36 + F_81 ( V_35 ) , V_58 ) ;
}
F_264 ( & V_95 -> V_247 ) ;
return 1 ;
}
static int F_265 ( struct V_222 * V_239 , struct V_14 * V_15 ,
unsigned long V_36 , T_10 * V_221 , T_10 V_233 ,
struct V_58 * V_248 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_58 * V_249 , * V_250 ;
int V_251 ;
int V_252 = 0 ;
unsigned long V_241 ;
unsigned long V_242 ;
V_249 = F_231 ( V_233 ) ;
V_253:
V_251 = ( F_86 ( V_249 ) == 1 ) ;
if ( V_251 ) {
if ( F_266 ( V_249 ) )
F_267 ( V_249 , V_15 , V_36 ) ;
F_221 ( V_15 , V_36 , V_221 ) ;
return 0 ;
}
if ( ! ( V_15 -> V_49 & V_50 ) &&
F_47 ( V_15 , V_57 ) &&
V_249 != V_248 )
V_252 = 1 ;
F_268 ( V_249 ) ;
F_2 ( & V_239 -> V_231 ) ;
V_250 = F_124 ( V_15 , V_36 , V_252 ) ;
if ( F_269 ( V_250 ) ) {
long V_82 = F_270 ( V_250 ) ;
F_271 ( V_249 ) ;
if ( V_252 ) {
F_9 ( F_229 ( V_233 ) ) ;
if ( F_261 ( V_239 , V_15 , V_249 , V_36 ) ) {
F_9 ( F_229 ( V_233 ) ) ;
F_8 ( & V_239 -> V_231 ) ;
V_221 = F_226 ( V_239 , V_36 & F_243 ( V_35 ) ) ;
if ( F_272 ( F_273 ( F_222 ( V_221 ) , V_233 ) ) )
goto V_253;
return 0 ;
}
F_274 ( 1 ) ;
}
F_8 ( & V_239 -> V_231 ) ;
if ( V_82 == - V_11 )
return V_254 ;
else
return V_255 ;
}
if ( F_58 ( F_275 ( V_15 ) ) ) {
F_271 ( V_250 ) ;
F_271 ( V_249 ) ;
F_8 ( & V_239 -> V_231 ) ;
return V_254 ;
}
F_276 ( V_250 , V_249 , V_36 , V_15 ,
F_53 ( V_35 ) ) ;
F_277 ( V_250 ) ;
V_241 = V_36 & F_243 ( V_35 ) ;
V_242 = V_241 + F_81 ( V_35 ) ;
F_245 ( V_239 , V_241 , V_242 ) ;
F_8 ( & V_239 -> V_231 ) ;
V_221 = F_226 ( V_239 , V_36 & F_243 ( V_35 ) ) ;
if ( F_272 ( F_273 ( F_222 ( V_221 ) , V_233 ) ) ) {
F_278 ( V_15 , V_36 , V_221 ) ;
F_234 ( V_239 , V_36 , V_221 ,
F_213 ( V_15 , V_250 , 1 ) ) ;
F_252 ( V_249 ) ;
F_279 ( V_250 , V_15 , V_36 ) ;
V_250 = V_249 ;
}
F_2 ( & V_239 -> V_231 ) ;
F_255 ( V_239 , V_241 , V_242 ) ;
F_8 ( & V_239 -> V_231 ) ;
F_271 ( V_250 ) ;
F_271 ( V_249 ) ;
return 0 ;
}
static struct V_58 * F_280 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_36 )
{
struct V_129 * V_95 ;
T_1 V_132 ;
V_95 = V_15 -> V_16 -> V_130 ;
V_132 = F_29 ( V_35 , V_15 , V_36 ) ;
return F_281 ( V_95 , V_132 ) ;
}
static bool F_282 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_36 )
{
struct V_129 * V_95 ;
T_1 V_132 ;
struct V_58 * V_58 ;
V_95 = V_15 -> V_16 -> V_130 ;
V_132 = F_29 ( V_35 , V_15 , V_36 ) ;
V_58 = F_283 ( V_95 , V_132 ) ;
if ( V_58 )
F_92 ( V_58 ) ;
return V_58 != NULL ;
}
static int F_284 ( struct V_222 * V_239 , struct V_14 * V_15 ,
unsigned long V_36 , T_10 * V_221 , unsigned int V_53 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
int V_10 = V_255 ;
int V_256 = 0 ;
T_1 V_132 ;
unsigned long V_94 ;
struct V_58 * V_58 ;
struct V_129 * V_95 ;
T_10 V_257 ;
if ( F_47 ( V_15 , V_244 ) ) {
F_190 ( L_22 ,
V_153 -> V_258 ) ;
return V_10 ;
}
V_95 = V_15 -> V_16 -> V_130 ;
V_132 = F_29 ( V_35 , V_15 , V_36 ) ;
V_124:
V_58 = F_281 ( V_95 , V_132 ) ;
if ( ! V_58 ) {
V_94 = F_285 ( V_95 -> V_131 ) >> F_30 ( V_35 ) ;
if ( V_132 >= V_94 )
goto V_152;
V_58 = F_124 ( V_15 , V_36 , 0 ) ;
if ( F_269 ( V_58 ) ) {
V_10 = F_270 ( V_58 ) ;
if ( V_10 == - V_11 )
V_10 = V_254 ;
else
V_10 = V_255 ;
goto V_152;
}
F_286 ( V_58 , V_36 , F_53 ( V_35 ) ) ;
F_277 ( V_58 ) ;
if ( V_15 -> V_49 & V_50 ) {
int V_82 ;
struct V_12 * V_12 = V_95 -> V_131 ;
V_82 = F_287 ( V_58 , V_95 , V_132 , V_7 ) ;
if ( V_82 ) {
F_92 ( V_58 ) ;
if ( V_82 == - V_259 )
goto V_124;
goto V_152;
}
F_8 ( & V_12 -> V_260 ) ;
V_12 -> V_261 += F_288 ( V_35 ) ;
F_2 ( & V_12 -> V_260 ) ;
} else {
F_289 ( V_58 ) ;
if ( F_58 ( F_275 ( V_15 ) ) ) {
V_10 = V_254 ;
goto V_262;
}
V_256 = 1 ;
}
} else {
if ( F_58 ( F_290 ( V_58 ) ) ) {
V_10 = V_263 |
F_291 ( F_88 ( V_35 ) ) ;
goto V_262;
}
}
if ( ( V_53 & V_264 ) && ! ( V_15 -> V_49 & V_228 ) )
if ( F_122 ( V_35 , V_15 , V_36 ) < 0 ) {
V_10 = V_254 ;
goto V_262;
}
F_8 ( & V_239 -> V_231 ) ;
V_94 = F_285 ( V_95 -> V_131 ) >> F_30 ( V_35 ) ;
if ( V_132 >= V_94 )
goto V_265;
V_10 = 0 ;
if ( ! F_229 ( F_222 ( V_221 ) ) )
goto V_265;
if ( V_256 )
F_279 ( V_58 , V_15 , V_36 ) ;
else
F_233 ( V_58 ) ;
V_257 = F_213 ( V_15 , V_58 , ( ( V_15 -> V_49 & V_266 )
&& ( V_15 -> V_49 & V_228 ) ) ) ;
F_234 ( V_239 , V_36 , V_221 , V_257 ) ;
if ( ( V_53 & V_264 ) && ! ( V_15 -> V_49 & V_228 ) ) {
V_10 = F_265 ( V_239 , V_15 , V_36 , V_221 , V_257 , V_58 ) ;
}
F_2 ( & V_239 -> V_231 ) ;
F_292 ( V_58 ) ;
V_152:
return V_10 ;
V_265:
F_2 ( & V_239 -> V_231 ) ;
V_262:
F_292 ( V_58 ) ;
F_92 ( V_58 ) ;
goto V_152;
}
int F_293 ( struct V_222 * V_239 , struct V_14 * V_15 ,
unsigned long V_36 , unsigned int V_53 )
{
T_10 * V_221 ;
T_10 V_219 ;
int V_10 ;
struct V_58 * V_58 = NULL ;
struct V_58 * V_248 = NULL ;
static F_294 ( V_267 ) ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
V_36 &= F_243 ( V_35 ) ;
V_221 = F_226 ( V_239 , V_36 ) ;
if ( V_221 ) {
V_219 = F_222 ( V_221 ) ;
if ( F_58 ( F_235 ( V_219 ) ) ) {
F_295 ( V_239 , ( V_268 * ) V_221 , V_36 ) ;
return 0 ;
} else if ( F_58 ( F_240 ( V_219 ) ) )
return V_269 |
F_291 ( F_88 ( V_35 ) ) ;
}
V_221 = F_227 ( V_239 , V_36 , F_81 ( V_35 ) ) ;
if ( ! V_221 )
return V_254 ;
F_262 ( & V_267 ) ;
V_219 = F_222 ( V_221 ) ;
if ( F_229 ( V_219 ) ) {
V_10 = F_284 ( V_239 , V_15 , V_36 , V_221 , V_53 ) ;
goto V_270;
}
V_10 = 0 ;
if ( ( V_53 & V_264 ) && ! F_296 ( V_219 ) ) {
if ( F_122 ( V_35 , V_15 , V_36 ) < 0 ) {
V_10 = V_254 ;
goto V_270;
}
if ( ! ( V_15 -> V_49 & V_50 ) )
V_248 = F_280 ( V_35 ,
V_15 , V_36 ) ;
}
V_58 = F_231 ( V_219 ) ;
F_232 ( V_58 ) ;
if ( V_58 != V_248 )
F_289 ( V_58 ) ;
F_8 ( & V_239 -> V_231 ) ;
if ( F_58 ( ! F_273 ( V_219 , F_222 ( V_221 ) ) ) )
goto V_271;
if ( V_53 & V_264 ) {
if ( ! F_296 ( V_219 ) ) {
V_10 = F_265 ( V_239 , V_15 , V_36 , V_221 , V_219 ,
V_248 ) ;
goto V_271;
}
V_219 = F_215 ( V_219 ) ;
}
V_219 = F_218 ( V_219 ) ;
if ( F_223 ( V_15 , V_36 , V_221 , V_219 ,
V_53 & V_264 ) )
F_224 ( V_15 , V_36 , V_221 ) ;
V_271:
F_2 ( & V_239 -> V_231 ) ;
if ( V_248 ) {
F_292 ( V_248 ) ;
F_92 ( V_248 ) ;
}
if ( V_58 != V_248 )
F_292 ( V_58 ) ;
F_92 ( V_58 ) ;
V_270:
F_264 ( & V_267 ) ;
return V_10 ;
}
struct V_58 *
F_297 ( struct V_222 * V_239 , unsigned long V_36 ,
T_12 * V_272 , int V_202 )
{
F_179 () ;
return NULL ;
}
long F_298 ( struct V_222 * V_239 , struct V_14 * V_15 ,
struct V_58 * * V_273 , struct V_14 * * V_274 ,
unsigned long * V_275 , unsigned long * V_99 ,
long V_61 , unsigned int V_53 )
{
unsigned long V_276 ;
unsigned long V_277 = * V_275 ;
unsigned long V_278 = * V_99 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
F_8 ( & V_239 -> V_231 ) ;
while ( V_277 < V_15 -> V_215 && V_278 ) {
T_10 * V_233 ;
int V_279 ;
struct V_58 * V_58 ;
V_233 = F_226 ( V_239 , V_277 & F_243 ( V_35 ) ) ;
V_279 = ! V_233 || F_229 ( F_222 ( V_233 ) ) ;
if ( V_279 && ( V_53 & V_280 ) &&
! F_282 ( V_35 , V_15 , V_277 ) ) {
V_278 = 0 ;
break;
}
if ( V_279 || F_299 ( F_222 ( V_233 ) ) ||
( ( V_53 & V_281 ) && ! F_296 ( F_222 ( V_233 ) ) ) ) {
int V_10 ;
F_2 ( & V_239 -> V_231 ) ;
V_10 = F_293 ( V_239 , V_15 , V_277 ,
( V_53 & V_281 ) ? V_264 : 0 ) ;
F_8 ( & V_239 -> V_231 ) ;
if ( ! ( V_10 & V_282 ) )
continue;
V_278 = 0 ;
break;
}
V_276 = ( V_277 & ~ F_243 ( V_35 ) ) >> V_41 ;
V_58 = F_231 ( F_222 ( V_233 ) ) ;
V_283:
if ( V_273 ) {
V_273 [ V_61 ] = F_300 ( V_58 , V_276 ) ;
F_232 ( V_273 [ V_61 ] ) ;
}
if ( V_274 )
V_274 [ V_61 ] = V_15 ;
V_277 += V_39 ;
++ V_276 ;
-- V_278 ;
++ V_61 ;
if ( V_277 < V_15 -> V_215 && V_278 &&
V_276 < F_53 ( V_35 ) ) {
goto V_283;
}
}
F_2 ( & V_239 -> V_231 ) ;
* V_99 = V_278 ;
* V_275 = V_277 ;
return V_61 ? V_61 : - V_284 ;
}
unsigned long F_301 ( struct V_14 * V_15 ,
unsigned long V_36 , unsigned long V_30 , T_13 V_285 )
{
struct V_222 * V_239 = V_15 -> V_240 ;
unsigned long V_214 = V_36 ;
T_10 * V_221 ;
T_10 V_233 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_273 = 0 ;
F_9 ( V_36 >= V_30 ) ;
F_302 ( V_15 , V_36 , V_30 ) ;
F_262 ( & V_15 -> V_16 -> V_130 -> V_247 ) ;
F_8 ( & V_239 -> V_231 ) ;
for (; V_36 < V_30 ; V_36 += F_81 ( V_35 ) ) {
V_221 = F_226 ( V_239 , V_36 ) ;
if ( ! V_221 )
continue;
if ( F_246 ( V_239 , & V_36 , V_221 ) ) {
V_273 ++ ;
continue;
}
if ( ! F_229 ( F_222 ( V_221 ) ) ) {
V_233 = F_248 ( V_239 , V_36 , V_221 ) ;
V_233 = F_219 ( F_303 ( V_233 , V_285 ) ) ;
V_233 = F_220 ( V_233 , V_15 , NULL , 0 ) ;
F_234 ( V_239 , V_36 , V_221 , V_233 ) ;
V_273 ++ ;
}
}
F_2 ( & V_239 -> V_231 ) ;
F_304 ( V_15 , V_214 , V_30 ) ;
F_264 ( & V_15 -> V_16 -> V_130 -> V_247 ) ;
return V_273 << V_35 -> V_40 ;
}
int F_305 ( struct V_12 * V_12 ,
long V_26 , long V_25 ,
struct V_14 * V_15 ,
T_14 V_49 )
{
long V_10 , V_28 ;
struct V_34 * V_35 = F_306 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( V_49 & V_55 )
return 0 ;
if ( ! V_15 || V_15 -> V_49 & V_50 )
V_28 = F_20 ( & V_12 -> V_133 -> V_134 , V_26 , V_25 ) ;
else {
struct V_44 * V_44 = F_39 () ;
if ( ! V_44 )
return - V_11 ;
V_28 = V_25 - V_26 ;
F_45 ( V_15 , V_44 ) ;
F_46 ( V_15 , V_57 ) ;
}
if ( V_28 < 0 ) {
V_10 = V_28 ;
goto V_286;
}
if ( F_10 ( V_2 , V_28 ) ) {
V_10 = - V_138 ;
goto V_286;
}
V_10 = F_206 ( V_35 , V_28 ) ;
if ( V_10 < 0 ) {
F_11 ( V_2 , V_28 ) ;
goto V_286;
}
if ( ! V_15 || V_15 -> V_49 & V_50 )
F_16 ( & V_12 -> V_133 -> V_134 , V_26 , V_25 ) ;
return 0 ;
V_286:
if ( V_15 )
F_209 ( V_15 ) ;
return V_10 ;
}
void F_307 ( struct V_12 * V_12 , long V_287 , long V_288 )
{
struct V_34 * V_35 = F_306 ( V_12 ) ;
long V_28 = F_23 ( & V_12 -> V_133 -> V_134 , V_287 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_8 ( & V_12 -> V_260 ) ;
V_12 -> V_261 -= ( F_288 ( V_35 ) * V_288 ) ;
F_2 ( & V_12 -> V_260 ) ;
F_11 ( V_2 , ( V_28 - V_288 ) ) ;
F_206 ( V_35 , - ( V_28 - V_288 ) ) ;
}
static int F_308 ( struct V_58 * V_289 )
{
struct V_58 * V_58 ;
struct V_58 * V_120 ;
struct V_34 * V_35 = F_52 ( V_289 ) ;
int V_65 = F_61 ( V_289 ) ;
F_18 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_58 == V_289 )
return 1 ;
return 0 ;
}
int F_309 ( struct V_58 * V_289 )
{
struct V_34 * V_35 = F_52 ( V_289 ) ;
int V_65 = F_61 ( V_289 ) ;
int V_10 = - V_290 ;
F_8 ( & V_96 ) ;
if ( F_308 ( V_289 ) ) {
F_310 ( & V_289 -> V_66 ) ;
F_65 ( V_289 ) ;
V_35 -> V_68 -- ;
V_35 -> V_69 [ V_65 ] -- ;
V_10 = 0 ;
}
F_2 ( & V_96 ) ;
return V_10 ;
}
