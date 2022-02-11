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
return 1UL << F_30 ( V_34 ) ;
}
unsigned long F_36 ( struct V_14 * V_15 )
{
return F_34 ( V_15 ) ;
}
static unsigned long F_37 ( struct V_14 * V_15 )
{
return ( unsigned long ) V_15 -> V_40 ;
}
static void F_38 ( struct V_14 * V_15 ,
unsigned long V_41 )
{
V_15 -> V_40 = ( void * ) V_41 ;
}
static struct V_42 * F_39 ( void )
{
struct V_42 * V_42 = F_5 ( sizeof( * V_42 ) , V_7 ) ;
if ( ! V_42 )
return NULL ;
F_40 ( & V_42 -> V_43 ) ;
F_21 ( & V_42 -> V_44 ) ;
return V_42 ;
}
static void F_41 ( struct V_45 * V_46 )
{
struct V_42 * V_42 = F_42 ( V_46 , struct V_42 , V_43 ) ;
F_23 ( & V_42 -> V_44 , 0 ) ;
F_3 ( V_42 ) ;
}
static struct V_42 * F_43 ( struct V_14 * V_15 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
if ( ! ( V_15 -> V_47 & V_48 ) )
return (struct V_42 * ) ( F_37 ( V_15 ) &
~ V_49 ) ;
return NULL ;
}
static void F_45 ( struct V_14 * V_15 , struct V_42 * V_50 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
F_44 ( V_15 -> V_47 & V_48 ) ;
F_38 ( V_15 , ( F_37 ( V_15 ) &
V_49 ) | ( unsigned long ) V_50 ) ;
}
static void F_46 ( struct V_14 * V_15 , unsigned long V_51 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
F_44 ( V_15 -> V_47 & V_48 ) ;
F_38 ( V_15 , F_37 ( V_15 ) | V_51 ) ;
}
static int F_47 ( struct V_14 * V_15 , unsigned long V_52 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
return ( F_37 ( V_15 ) & V_52 ) != 0 ;
}
static void F_48 ( struct V_34 * V_35 ,
struct V_14 * V_15 )
{
if ( V_15 -> V_47 & V_53 )
return;
if ( V_15 -> V_47 & V_48 ) {
V_35 -> V_54 -- ;
} else if ( F_47 ( V_15 , V_55 ) ) {
V_35 -> V_54 -- ;
}
}
void F_49 ( struct V_14 * V_15 )
{
F_44 ( ! F_35 ( V_15 ) ) ;
if ( ! ( V_15 -> V_47 & V_48 ) )
V_15 -> V_40 = ( void * ) 0 ;
}
static int F_50 ( struct V_14 * V_15 )
{
if ( V_15 -> V_47 & V_48 )
return 1 ;
if ( F_47 ( V_15 , V_55 ) )
return 1 ;
return 0 ;
}
static void F_51 ( struct V_56 * V_57 , struct V_56 * V_58 )
{
int V_59 ;
struct V_34 * V_35 = F_52 ( V_58 ) ;
struct V_56 * V_60 = V_57 ;
struct V_56 * V_61 = V_58 ;
for ( V_59 = 0 ; V_59 < F_53 ( V_35 ) ; ) {
F_54 () ;
F_55 ( V_57 , V_58 ) ;
V_59 ++ ;
V_57 = F_56 ( V_57 , V_60 , V_59 ) ;
V_58 = F_56 ( V_58 , V_61 , V_59 ) ;
}
}
void F_57 ( struct V_56 * V_57 , struct V_56 * V_58 )
{
int V_59 ;
struct V_34 * V_35 = F_52 ( V_58 ) ;
if ( F_58 ( F_53 ( V_35 ) > V_62 ) ) {
F_51 ( V_57 , V_58 ) ;
return;
}
F_59 () ;
for ( V_59 = 0 ; V_59 < F_53 ( V_35 ) ; V_59 ++ ) {
F_54 () ;
F_55 ( V_57 + V_59 , V_58 + V_59 ) ;
}
}
static void F_60 ( struct V_34 * V_35 , struct V_56 * V_56 )
{
int V_63 = F_61 ( V_56 ) ;
F_62 ( & V_56 -> V_64 , & V_35 -> V_65 [ V_63 ] ) ;
V_35 -> V_66 ++ ;
V_35 -> V_67 [ V_63 ] ++ ;
}
static struct V_56 * F_63 ( struct V_34 * V_35 , int V_63 )
{
struct V_56 * V_56 ;
if ( F_64 ( & V_35 -> V_65 [ V_63 ] ) )
return NULL ;
V_56 = F_24 ( V_35 -> V_65 [ V_63 ] . V_31 , struct V_56 , V_64 ) ;
F_62 ( & V_56 -> V_64 , & V_35 -> V_68 ) ;
F_65 ( V_56 ) ;
V_35 -> V_66 -- ;
V_35 -> V_67 [ V_63 ] -- ;
return V_56 ;
}
static struct V_56 * F_66 ( struct V_34 * V_35 ,
struct V_14 * V_15 ,
unsigned long V_36 , int V_69 )
{
struct V_56 * V_56 = NULL ;
struct V_70 * V_71 ;
T_2 * V_72 ;
struct V_73 * V_73 ;
struct V_74 * V_74 ;
struct V_75 * V_76 ;
unsigned int V_77 ;
V_78:
V_77 = F_67 () ;
V_73 = F_68 ( V_15 , V_36 ,
V_79 , & V_71 , & V_72 ) ;
if ( ! F_50 ( V_15 ) &&
V_35 -> V_66 - V_35 -> V_54 == 0 )
goto V_80;
if ( V_69 && V_35 -> V_66 - V_35 -> V_54 == 0 )
goto V_80;
F_69 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_70 ( V_74 , V_79 ) ) {
V_56 = F_63 ( V_35 , F_71 ( V_74 ) ) ;
if ( V_56 ) {
if ( ! V_69 )
F_48 ( V_35 , V_15 ) ;
break;
}
}
}
F_72 ( V_71 ) ;
if ( F_58 ( ! F_73 ( V_77 ) && ! V_56 ) )
goto V_78;
return V_56 ;
V_80:
F_72 ( V_71 ) ;
return NULL ;
}
static void F_74 ( struct V_34 * V_35 , struct V_56 * V_56 )
{
int V_59 ;
F_44 ( V_35 -> V_81 >= V_82 ) ;
V_35 -> V_83 -- ;
V_35 -> V_84 [ F_61 ( V_56 ) ] -- ;
for ( V_59 = 0 ; V_59 < F_53 ( V_35 ) ; V_59 ++ ) {
V_56 [ V_59 ] . V_51 &= ~ ( 1 << V_85 | 1 << V_86 |
1 << V_87 | 1 << V_88 |
1 << V_89 | 1 << V_90 |
1 << V_91 | 1 << V_92 ) ;
}
F_44 ( F_75 ( V_56 ) ) ;
F_76 ( V_56 , NULL ) ;
F_65 ( V_56 ) ;
F_77 ( V_56 ) ;
F_78 ( V_56 , F_31 ( V_35 ) ) ;
}
struct V_34 * F_79 ( unsigned long V_93 )
{
struct V_34 * V_35 ;
F_80 (h) {
if ( F_81 ( V_35 ) == V_93 )
return V_35 ;
}
return NULL ;
}
static void F_82 ( struct V_56 * V_56 )
{
struct V_34 * V_35 = F_52 ( V_56 ) ;
int V_63 = F_61 ( V_56 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_83 ( V_56 ) ;
F_84 ( V_56 , 0 ) ;
V_56 -> V_94 = NULL ;
F_9 ( F_85 ( V_56 ) ) ;
F_9 ( F_86 ( V_56 ) ) ;
F_8 ( & V_95 ) ;
F_87 ( F_88 ( V_35 ) ,
F_53 ( V_35 ) , V_56 ) ;
if ( V_35 -> V_96 [ V_63 ] && F_31 ( V_35 ) < V_82 ) {
F_19 ( & V_56 -> V_64 ) ;
F_74 ( V_35 , V_56 ) ;
V_35 -> V_97 -- ;
V_35 -> V_96 [ V_63 ] -- ;
} else {
F_89 ( V_56 ) ;
F_60 ( V_35 , V_56 ) ;
}
F_2 ( & V_95 ) ;
F_11 ( V_2 , 1 ) ;
}
static void F_90 ( struct V_34 * V_35 , struct V_56 * V_56 , int V_63 )
{
F_21 ( & V_56 -> V_64 ) ;
F_76 ( V_56 , F_82 ) ;
F_8 ( & V_95 ) ;
F_91 ( V_56 , NULL ) ;
V_35 -> V_83 ++ ;
V_35 -> V_84 [ V_63 ] ++ ;
F_2 ( & V_95 ) ;
F_92 ( V_56 ) ;
}
static void F_93 ( struct V_56 * V_56 , unsigned long V_81 )
{
int V_59 ;
int V_98 = 1 << V_81 ;
struct V_56 * V_99 = V_56 + 1 ;
F_94 ( V_56 , V_81 ) ;
F_95 ( V_56 ) ;
for ( V_59 = 1 ; V_59 < V_98 ; V_59 ++ , V_99 = F_56 ( V_99 , V_56 , V_59 ) ) {
F_96 ( V_99 ) ;
F_97 ( V_99 , 0 ) ;
V_99 -> V_100 = V_56 ;
}
}
int F_98 ( struct V_56 * V_56 )
{
T_3 * V_101 ;
if ( ! F_99 ( V_56 ) )
return 0 ;
V_56 = F_100 ( V_56 ) ;
V_101 = F_101 ( V_56 ) ;
return V_101 == F_82 ;
}
T_1 F_102 ( struct V_56 * V_56 )
{
struct V_56 * V_102 = F_100 ( V_56 ) ;
T_1 V_103 = F_103 ( V_102 ) ;
unsigned long V_104 ;
if ( ! F_98 ( V_102 ) )
return F_103 ( V_56 ) ;
if ( F_104 ( V_102 ) >= V_82 )
V_104 = F_105 ( V_56 ) - F_105 ( V_102 ) ;
else
V_104 = V_56 - V_102 ;
return ( V_103 << F_104 ( V_102 ) ) + V_104 ;
}
static struct V_56 * F_106 ( struct V_34 * V_35 , int V_63 )
{
struct V_56 * V_56 ;
if ( V_35 -> V_81 >= V_82 )
return NULL ;
V_56 = F_107 ( V_63 ,
V_79 | V_105 | V_106 |
V_107 | V_108 ,
F_31 ( V_35 ) ) ;
if ( V_56 ) {
if ( F_108 ( V_56 ) ) {
F_78 ( V_56 , F_31 ( V_35 ) ) ;
return NULL ;
}
F_90 ( V_35 , V_56 , V_63 ) ;
}
return V_56 ;
}
static int F_109 ( int V_63 , T_2 * V_109 )
{
V_63 = F_110 ( V_63 , * V_109 ) ;
if ( V_63 == V_110 )
V_63 = F_111 ( * V_109 ) ;
F_44 ( V_63 >= V_110 ) ;
return V_63 ;
}
static int F_112 ( int V_63 , T_2 * V_109 )
{
if ( ! F_113 ( V_63 , * V_109 ) )
V_63 = F_109 ( V_63 , V_109 ) ;
return V_63 ;
}
static int F_114 ( struct V_34 * V_35 ,
T_2 * V_109 )
{
int V_63 ;
F_44 ( ! V_109 ) ;
V_63 = F_112 ( V_35 -> V_111 , V_109 ) ;
V_35 -> V_111 = F_109 ( V_63 , V_109 ) ;
return V_63 ;
}
static int F_115 ( struct V_34 * V_35 , T_2 * V_109 )
{
struct V_56 * V_56 ;
int V_112 ;
int V_113 ;
int V_10 = 0 ;
V_112 = F_114 ( V_35 , V_109 ) ;
V_113 = V_112 ;
do {
V_56 = F_106 ( V_35 , V_113 ) ;
if ( V_56 ) {
V_10 = 1 ;
break;
}
V_113 = F_114 ( V_35 , V_109 ) ;
} while ( V_113 != V_112 );
if ( V_10 )
F_116 ( V_114 ) ;
else
F_116 ( V_115 ) ;
return V_10 ;
}
static int F_117 ( struct V_34 * V_35 , T_2 * V_109 )
{
int V_63 ;
F_44 ( ! V_109 ) ;
V_63 = F_112 ( V_35 -> V_116 , V_109 ) ;
V_35 -> V_116 = F_109 ( V_63 , V_109 ) ;
return V_63 ;
}
static int F_118 ( struct V_34 * V_35 , T_2 * V_109 ,
bool V_117 )
{
int V_112 ;
int V_113 ;
int V_10 = 0 ;
V_112 = F_117 ( V_35 , V_109 ) ;
V_113 = V_112 ;
do {
if ( ( ! V_117 || V_35 -> V_96 [ V_113 ] ) &&
! F_64 ( & V_35 -> V_65 [ V_113 ] ) ) {
struct V_56 * V_56 =
F_24 ( V_35 -> V_65 [ V_113 ] . V_31 ,
struct V_56 , V_64 ) ;
F_19 ( & V_56 -> V_64 ) ;
V_35 -> V_66 -- ;
V_35 -> V_67 [ V_113 ] -- ;
if ( V_117 ) {
V_35 -> V_97 -- ;
V_35 -> V_96 [ V_113 ] -- ;
}
F_74 ( V_35 , V_56 ) ;
V_10 = 1 ;
break;
}
V_113 = F_117 ( V_35 , V_109 ) ;
} while ( V_113 != V_112 );
return V_10 ;
}
static struct V_56 * F_119 ( struct V_34 * V_35 , int V_63 )
{
struct V_56 * V_56 ;
unsigned int V_118 ;
if ( V_35 -> V_81 >= V_82 )
return NULL ;
F_8 ( & V_95 ) ;
if ( V_35 -> V_97 >= V_35 -> V_119 ) {
F_2 ( & V_95 ) ;
return NULL ;
} else {
V_35 -> V_83 ++ ;
V_35 -> V_97 ++ ;
}
F_2 ( & V_95 ) ;
if ( V_63 == V_120 )
V_56 = F_120 ( V_79 | V_105 |
V_107 | V_108 ,
F_31 ( V_35 ) ) ;
else
V_56 = F_107 ( V_63 ,
V_79 | V_105 | V_106 |
V_107 | V_108 , F_31 ( V_35 ) ) ;
if ( V_56 && F_108 ( V_56 ) ) {
F_78 ( V_56 , F_31 ( V_35 ) ) ;
V_56 = NULL ;
}
F_8 ( & V_95 ) ;
if ( V_56 ) {
F_21 ( & V_56 -> V_64 ) ;
V_118 = F_61 ( V_56 ) ;
F_76 ( V_56 , F_82 ) ;
F_91 ( V_56 , NULL ) ;
V_35 -> V_84 [ V_118 ] ++ ;
V_35 -> V_96 [ V_118 ] ++ ;
F_121 ( V_114 ) ;
} else {
V_35 -> V_83 -- ;
V_35 -> V_97 -- ;
F_121 ( V_115 ) ;
}
F_2 ( & V_95 ) ;
return V_56 ;
}
struct V_56 * F_122 ( struct V_34 * V_35 , int V_63 )
{
struct V_56 * V_56 ;
F_8 ( & V_95 ) ;
V_56 = F_63 ( V_35 , V_63 ) ;
F_2 ( & V_95 ) ;
if ( ! V_56 )
V_56 = F_119 ( V_35 , V_63 ) ;
return V_56 ;
}
static int F_123 ( struct V_34 * V_35 , int V_9 )
{
struct V_17 V_121 ;
struct V_56 * V_56 , * V_122 ;
int V_10 , V_59 ;
int V_123 , V_124 ;
bool V_125 = true ;
V_123 = ( V_35 -> V_54 + V_9 ) - V_35 -> V_66 ;
if ( V_123 <= 0 ) {
V_35 -> V_54 += V_9 ;
return 0 ;
}
V_124 = 0 ;
F_21 ( & V_121 ) ;
V_10 = - V_11 ;
V_126:
F_2 ( & V_95 ) ;
for ( V_59 = 0 ; V_59 < V_123 ; V_59 ++ ) {
V_56 = F_119 ( V_35 , V_120 ) ;
if ( ! V_56 ) {
V_125 = false ;
break;
}
F_22 ( & V_56 -> V_64 , & V_121 ) ;
}
V_124 += V_59 ;
F_8 ( & V_95 ) ;
V_123 = ( V_35 -> V_54 + V_9 ) -
( V_35 -> V_66 + V_124 ) ;
if ( V_123 > 0 ) {
if ( V_125 )
goto V_126;
goto free;
}
V_123 += V_124 ;
V_35 -> V_54 += V_9 ;
V_10 = 0 ;
F_18 (page, tmp, &surplus_list, lru) {
if ( ( -- V_123 ) < 0 )
break;
F_124 ( V_56 ) ;
F_44 ( F_85 ( V_56 ) ) ;
F_60 ( V_35 , V_56 ) ;
}
free:
F_2 ( & V_95 ) ;
if ( ! F_64 ( & V_121 ) ) {
F_18 (page, tmp, &surplus_list, lru) {
F_92 ( V_56 ) ;
}
}
F_8 ( & V_95 ) ;
return V_10 ;
}
static void F_125 ( struct V_34 * V_35 ,
unsigned long V_127 )
{
unsigned long V_98 ;
V_35 -> V_54 -= V_127 ;
if ( V_35 -> V_81 >= V_82 )
return;
V_98 = F_28 ( V_127 , V_35 -> V_97 ) ;
while ( V_98 -- ) {
if ( ! F_118 ( V_35 , & V_128 [ V_129 ] , 1 ) )
break;
}
}
static long F_126 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_130 )
{
struct V_131 * V_94 = V_15 -> V_16 -> V_132 ;
struct V_12 * V_12 = V_94 -> V_133 ;
if ( V_15 -> V_47 & V_48 ) {
T_1 V_134 = F_29 ( V_35 , V_15 , V_130 ) ;
return F_20 ( & V_12 -> V_135 -> V_136 ,
V_134 , V_134 + 1 ) ;
} else if ( ! F_47 ( V_15 , V_55 ) ) {
return 1 ;
} else {
long V_80 ;
T_1 V_134 = F_29 ( V_35 , V_15 , V_130 ) ;
struct V_42 * V_137 = F_43 ( V_15 ) ;
V_80 = F_20 ( & V_137 -> V_44 , V_134 , V_134 + 1 ) ;
if ( V_80 < 0 )
return V_80 ;
return 0 ;
}
}
static void F_127 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_130 )
{
struct V_131 * V_94 = V_15 -> V_16 -> V_132 ;
struct V_12 * V_12 = V_94 -> V_133 ;
if ( V_15 -> V_47 & V_48 ) {
T_1 V_134 = F_29 ( V_35 , V_15 , V_130 ) ;
F_16 ( & V_12 -> V_135 -> V_136 , V_134 , V_134 + 1 ) ;
} else if ( F_47 ( V_15 , V_55 ) ) {
T_1 V_134 = F_29 ( V_35 , V_15 , V_130 ) ;
struct V_42 * V_137 = F_43 ( V_15 ) ;
F_16 ( & V_137 -> V_44 , V_134 , V_134 + 1 ) ;
}
}
static struct V_56 * F_128 ( struct V_14 * V_15 ,
unsigned long V_130 , int V_69 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_56 * V_56 ;
long V_28 ;
int V_10 , V_134 ;
struct V_138 * V_139 ;
V_134 = F_88 ( V_35 ) ;
V_28 = F_126 ( V_35 , V_15 , V_130 ) ;
if ( V_28 < 0 )
return F_129 ( - V_11 ) ;
if ( V_28 )
if ( F_10 ( V_2 , V_28 ) )
return F_129 ( - V_140 ) ;
V_10 = F_130 ( V_134 , F_53 ( V_35 ) , & V_139 ) ;
if ( V_10 ) {
F_11 ( V_2 , V_28 ) ;
return F_129 ( - V_140 ) ;
}
F_8 ( & V_95 ) ;
V_56 = F_66 ( V_35 , V_15 , V_130 , V_69 ) ;
if ( V_56 ) {
F_131 ( V_134 , F_53 ( V_35 ) ,
V_139 , V_56 ) ;
F_2 ( & V_95 ) ;
} else {
F_2 ( & V_95 ) ;
V_56 = F_119 ( V_35 , V_120 ) ;
if ( ! V_56 ) {
F_132 ( V_134 ,
F_53 ( V_35 ) ,
V_139 ) ;
F_11 ( V_2 , V_28 ) ;
return F_129 ( - V_140 ) ;
}
F_8 ( & V_95 ) ;
F_131 ( V_134 , F_53 ( V_35 ) ,
V_139 , V_56 ) ;
F_62 ( & V_56 -> V_64 , & V_35 -> V_68 ) ;
F_2 ( & V_95 ) ;
}
F_84 ( V_56 , ( unsigned long ) V_2 ) ;
F_127 ( V_35 , V_15 , V_130 ) ;
return V_56 ;
}
int __weak F_133 ( struct V_34 * V_35 )
{
struct V_141 * V_142 ;
int V_143 = F_134 ( V_128 [ V_129 ] ) ;
while ( V_143 ) {
void * V_130 ;
V_130 = F_135 (
F_136 ( F_114 ( V_35 ,
& V_128 [ V_129 ] ) ) ,
F_81 ( V_35 ) , F_81 ( V_35 ) , 0 ) ;
if ( V_130 ) {
V_142 = V_130 ;
goto V_144;
}
V_143 -- ;
}
return 0 ;
V_144:
F_9 ( ( unsigned long ) F_137 ( V_142 ) & ( F_81 ( V_35 ) - 1 ) ) ;
F_22 ( & V_142 -> V_145 , & V_146 ) ;
V_142 -> V_34 = V_35 ;
return 1 ;
}
static void F_138 ( struct V_56 * V_56 , int V_81 )
{
if ( F_58 ( V_81 > ( V_82 - 1 ) ) )
F_93 ( V_56 , V_81 ) ;
else
F_139 ( V_56 , V_81 ) ;
}
static void T_4 F_140 ( void )
{
struct V_141 * V_142 ;
F_17 (m, &huge_boot_pages, list) {
struct V_34 * V_35 = V_142 -> V_34 ;
struct V_56 * V_56 ;
#ifdef F_141
V_56 = F_142 ( V_142 -> V_147 >> V_148 ) ;
F_143 ( ( unsigned long ) V_142 ,
sizeof( struct V_141 ) ) ;
#else
V_56 = F_144 ( V_142 ) ;
#endif
F_145 ( V_56 ) ;
F_146 ( F_85 ( V_56 ) != 1 ) ;
F_138 ( V_56 , V_35 -> V_81 ) ;
F_90 ( V_35 , V_56 , F_61 ( V_56 ) ) ;
if ( V_35 -> V_81 > ( V_82 - 1 ) )
F_147 ( V_56 , 1 << V_35 -> V_81 ) ;
}
}
static void T_4 F_148 ( struct V_34 * V_35 )
{
unsigned long V_59 ;
for ( V_59 = 0 ; V_59 < V_35 -> V_149 ; ++ V_59 ) {
if ( V_35 -> V_81 >= V_82 ) {
if ( ! F_133 ( V_35 ) )
break;
} else if ( ! F_115 ( V_35 ,
& V_128 [ V_129 ] ) )
break;
}
V_35 -> V_149 = V_59 ;
}
static void T_4 F_149 ( void )
{
struct V_34 * V_35 ;
F_80 (h) {
if ( V_35 -> V_81 < V_82 )
F_148 ( V_35 ) ;
}
}
static char * T_4 F_150 ( char * V_150 , unsigned long V_151 )
{
if ( V_151 >= ( 1UL << 30 ) )
sprintf ( V_150 , L_1 , V_151 >> 30 ) ;
else if ( V_151 >= ( 1UL << 20 ) )
sprintf ( V_150 , L_2 , V_151 >> 20 ) ;
else
sprintf ( V_150 , L_3 , V_151 >> 10 ) ;
return V_150 ;
}
static void T_4 F_151 ( void )
{
struct V_34 * V_35 ;
F_80 (h) {
char V_150 [ 32 ] ;
F_152 ( L_4 ,
F_150 ( V_150 , F_81 ( V_35 ) ) ,
V_35 -> V_66 ) ;
}
}
static void F_153 ( struct V_34 * V_35 , unsigned long V_3 ,
T_2 * V_109 )
{
int V_59 ;
if ( V_35 -> V_81 >= V_82 )
return;
F_154 (i, *nodes_allowed) {
struct V_56 * V_56 , * V_31 ;
struct V_17 * V_152 = & V_35 -> V_65 [ V_59 ] ;
F_18 (page, next, freel, lru) {
if ( V_3 >= V_35 -> V_83 )
return;
if ( F_155 ( V_56 ) )
continue;
F_19 ( & V_56 -> V_64 ) ;
F_74 ( V_35 , V_56 ) ;
V_35 -> V_66 -- ;
V_35 -> V_67 [ F_61 ( V_56 ) ] -- ;
}
}
}
static inline void F_153 ( struct V_34 * V_35 , unsigned long V_3 ,
T_2 * V_109 )
{
}
static int F_156 ( struct V_34 * V_35 , T_2 * V_109 ,
int V_9 )
{
int V_112 , V_113 ;
int V_10 = 0 ;
F_44 ( V_9 != - 1 && V_9 != 1 ) ;
if ( V_9 < 0 )
V_112 = F_114 ( V_35 , V_109 ) ;
else
V_112 = F_117 ( V_35 , V_109 ) ;
V_113 = V_112 ;
do {
int V_63 = V_113 ;
if ( V_9 < 0 ) {
if ( ! V_35 -> V_96 [ V_63 ] ) {
V_113 = F_114 ( V_35 ,
V_109 ) ;
continue;
}
}
if ( V_9 > 0 ) {
if ( V_35 -> V_96 [ V_63 ] >=
V_35 -> V_84 [ V_63 ] ) {
V_113 = F_117 ( V_35 ,
V_109 ) ;
continue;
}
}
V_35 -> V_97 += V_9 ;
V_35 -> V_96 [ V_63 ] += V_9 ;
V_10 = 1 ;
break;
} while ( V_113 != V_112 );
return V_10 ;
}
static unsigned long F_157 ( struct V_34 * V_35 , unsigned long V_3 ,
T_2 * V_109 )
{
unsigned long V_153 , V_10 ;
if ( V_35 -> V_81 >= V_82 )
return V_35 -> V_149 ;
F_8 ( & V_95 ) ;
while ( V_35 -> V_97 && V_3 > F_158 ( V_35 ) ) {
if ( ! F_156 ( V_35 , V_109 , - 1 ) )
break;
}
while ( V_3 > F_158 ( V_35 ) ) {
F_2 ( & V_95 ) ;
V_10 = F_115 ( V_35 , V_109 ) ;
F_8 ( & V_95 ) ;
if ( ! V_10 )
goto V_154;
if ( F_159 ( V_155 ) )
goto V_154;
}
V_153 = V_35 -> V_54 + V_35 -> V_83 - V_35 -> V_66 ;
V_153 = F_27 ( V_3 , V_153 ) ;
F_153 ( V_35 , V_153 , V_109 ) ;
while ( V_153 < F_158 ( V_35 ) ) {
if ( ! F_118 ( V_35 , V_109 , 0 ) )
break;
}
while ( V_3 < F_158 ( V_35 ) ) {
if ( ! F_156 ( V_35 , V_109 , 1 ) )
break;
}
V_154:
V_10 = F_158 ( V_35 ) ;
F_2 ( & V_95 ) ;
return V_10 ;
}
static struct V_34 * F_160 ( struct V_156 * V_157 , int * V_158 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_159 ; V_59 ++ )
if ( V_160 [ V_59 ] == V_157 ) {
if ( V_158 )
* V_158 = V_120 ;
return & V_161 [ V_59 ] ;
}
return F_161 ( V_157 , V_158 ) ;
}
static T_5 F_162 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 ;
unsigned long V_83 ;
int V_63 ;
V_35 = F_160 ( V_157 , & V_63 ) ;
if ( V_63 == V_120 )
V_83 = V_35 -> V_83 ;
else
V_83 = V_35 -> V_84 [ V_63 ] ;
return sprintf ( V_150 , L_5 , V_83 ) ;
}
static T_5 F_163 ( bool V_164 ,
struct V_156 * V_157 , struct V_162 * V_163 ,
const char * V_150 , T_6 V_165 )
{
int V_80 ;
int V_63 ;
unsigned long V_3 ;
struct V_34 * V_35 ;
F_164 ( T_2 , V_109 , V_7 | V_166 ) ;
V_80 = F_165 ( V_150 , 10 , & V_3 ) ;
if ( V_80 )
goto V_154;
V_35 = F_160 ( V_157 , & V_63 ) ;
if ( V_35 -> V_81 >= V_82 ) {
V_80 = - V_167 ;
goto V_154;
}
if ( V_63 == V_120 ) {
if ( ! ( V_164 &&
F_166 ( V_109 ) ) ) {
F_167 ( V_109 ) ;
V_109 = & V_128 [ V_129 ] ;
}
} else if ( V_109 ) {
V_3 += V_35 -> V_83 - V_35 -> V_84 [ V_63 ] ;
F_168 ( V_109 , V_63 ) ;
} else
V_109 = & V_128 [ V_129 ] ;
V_35 -> V_149 = F_157 ( V_35 , V_3 , V_109 ) ;
if ( V_109 != & V_128 [ V_129 ] )
F_167 ( V_109 ) ;
return V_165 ;
V_154:
F_167 ( V_109 ) ;
return V_80 ;
}
static T_5 F_169 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
return F_162 ( V_157 , V_163 , V_150 ) ;
}
static T_5 F_170 ( struct V_156 * V_157 ,
struct V_162 * V_163 , const char * V_150 , T_6 V_165 )
{
return F_163 ( false , V_157 , V_163 , V_150 , V_165 ) ;
}
static T_5 F_171 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
return F_162 ( V_157 , V_163 , V_150 ) ;
}
static T_5 F_172 ( struct V_156 * V_157 ,
struct V_162 * V_163 , const char * V_150 , T_6 V_165 )
{
return F_163 ( true , V_157 , V_163 , V_150 , V_165 ) ;
}
static T_5 F_173 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 = F_160 ( V_157 , NULL ) ;
return sprintf ( V_150 , L_5 , V_35 -> V_119 ) ;
}
static T_5 F_174 ( struct V_156 * V_157 ,
struct V_162 * V_163 , const char * V_150 , T_6 V_3 )
{
int V_80 ;
unsigned long V_168 ;
struct V_34 * V_35 = F_160 ( V_157 , NULL ) ;
if ( V_35 -> V_81 >= V_82 )
return - V_167 ;
V_80 = F_165 ( V_150 , 10 , & V_168 ) ;
if ( V_80 )
return V_80 ;
F_8 ( & V_95 ) ;
V_35 -> V_119 = V_168 ;
F_2 ( & V_95 ) ;
return V_3 ;
}
static T_5 F_175 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 ;
unsigned long V_66 ;
int V_63 ;
V_35 = F_160 ( V_157 , & V_63 ) ;
if ( V_63 == V_120 )
V_66 = V_35 -> V_66 ;
else
V_66 = V_35 -> V_67 [ V_63 ] ;
return sprintf ( V_150 , L_5 , V_66 ) ;
}
static T_5 F_176 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 = F_160 ( V_157 , NULL ) ;
return sprintf ( V_150 , L_5 , V_35 -> V_54 ) ;
}
static T_5 F_177 ( struct V_156 * V_157 ,
struct V_162 * V_163 , char * V_150 )
{
struct V_34 * V_35 ;
unsigned long V_97 ;
int V_63 ;
V_35 = F_160 ( V_157 , & V_63 ) ;
if ( V_63 == V_120 )
V_97 = V_35 -> V_97 ;
else
V_97 = V_35 -> V_96 [ V_63 ] ;
return sprintf ( V_150 , L_5 , V_97 ) ;
}
static int F_178 ( struct V_34 * V_35 , struct V_156 * V_169 ,
struct V_156 * * V_160 ,
struct V_170 * V_171 )
{
int V_172 ;
int V_173 = F_88 ( V_35 ) ;
V_160 [ V_173 ] = F_179 ( V_35 -> V_174 , V_169 ) ;
if ( ! V_160 [ V_173 ] )
return - V_11 ;
V_172 = F_180 ( V_160 [ V_173 ] , V_171 ) ;
if ( V_172 )
F_181 ( V_160 [ V_173 ] ) ;
return V_172 ;
}
static void T_4 F_182 ( void )
{
struct V_34 * V_35 ;
int V_80 ;
V_175 = F_179 ( L_6 , V_176 ) ;
if ( ! V_175 )
return;
F_80 (h) {
V_80 = F_178 ( V_35 , V_175 ,
V_160 , & V_171 ) ;
if ( V_80 )
F_183 ( L_7 , V_35 -> V_174 ) ;
}
}
static struct V_34 * F_161 ( struct V_156 * V_157 , int * V_158 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_177 ; V_63 ++ ) {
struct V_178 * V_179 = & V_180 [ V_63 ] ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_159 ; V_59 ++ )
if ( V_179 -> V_160 [ V_59 ] == V_157 ) {
if ( V_158 )
* V_158 = V_63 ;
return & V_161 [ V_59 ] ;
}
}
F_184 () ;
return NULL ;
}
static void F_185 ( struct V_181 * V_181 )
{
struct V_34 * V_35 ;
struct V_178 * V_179 = & V_180 [ V_181 -> V_182 . V_183 ] ;
if ( ! V_179 -> V_175 )
return;
F_80 (h) {
int V_134 = F_88 ( V_35 ) ;
if ( V_179 -> V_160 [ V_134 ] ) {
F_181 ( V_179 -> V_160 [ V_134 ] ) ;
V_179 -> V_160 [ V_134 ] = NULL ;
}
}
F_181 ( V_179 -> V_175 ) ;
V_179 -> V_175 = NULL ;
}
static void F_186 ( void )
{
int V_63 ;
F_187 ( NULL , NULL ) ;
for ( V_63 = 0 ; V_63 < V_177 ; V_63 ++ )
F_185 ( V_184 [ V_63 ] ) ;
}
static void F_188 ( struct V_181 * V_181 )
{
struct V_34 * V_35 ;
struct V_178 * V_179 = & V_180 [ V_181 -> V_182 . V_183 ] ;
int V_80 ;
if ( V_179 -> V_175 )
return;
V_179 -> V_175 = F_179 ( L_6 ,
& V_181 -> V_182 . V_157 ) ;
if ( ! V_179 -> V_175 )
return;
F_80 (h) {
V_80 = F_178 ( V_35 , V_179 -> V_175 ,
V_179 -> V_160 ,
& V_185 ) ;
if ( V_80 ) {
F_183 ( L_8 ,
V_35 -> V_174 , V_181 -> V_182 . V_183 ) ;
F_185 ( V_181 ) ;
break;
}
}
}
static void F_189 ( void )
{
int V_63 ;
F_190 (nid, N_MEMORY) {
struct V_181 * V_181 = V_184 [ V_63 ] ;
if ( V_181 -> V_182 . V_183 == V_63 )
F_188 ( V_181 ) ;
}
F_187 ( F_188 ,
F_185 ) ;
}
static struct V_34 * F_161 ( struct V_156 * V_157 , int * V_158 )
{
F_184 () ;
if ( V_158 )
* V_158 = - 1 ;
return NULL ;
}
static void F_186 ( void ) { }
static void F_189 ( void ) { }
static void T_7 F_191 ( void )
{
struct V_34 * V_35 ;
F_186 () ;
F_80 (h) {
F_181 ( V_160 [ F_88 ( V_35 ) ] ) ;
}
F_181 ( V_175 ) ;
}
static int T_4 F_192 ( void )
{
if ( V_186 == 0 )
return 0 ;
if ( ! F_79 ( V_187 ) ) {
V_187 = V_188 ;
if ( ! F_79 ( V_187 ) )
F_193 ( V_189 ) ;
}
V_190 = F_88 ( F_79 ( V_187 ) ) ;
if ( V_191 )
V_192 . V_149 = V_191 ;
F_149 () ;
F_140 () ;
F_151 () ;
F_182 () ;
F_189 () ;
F_194 () ;
return 0 ;
}
void T_4 F_193 ( unsigned V_81 )
{
struct V_34 * V_35 ;
unsigned long V_59 ;
if ( F_79 ( V_39 << V_81 ) ) {
F_195 ( L_9 ) ;
return;
}
F_9 ( V_193 >= V_159 ) ;
F_9 ( V_81 == 0 ) ;
V_35 = & V_161 [ V_193 ++ ] ;
V_35 -> V_81 = V_81 ;
V_35 -> V_194 = ~ ( ( 1ULL << ( V_81 + V_148 ) ) - 1 ) ;
V_35 -> V_83 = 0 ;
V_35 -> V_66 = 0 ;
for ( V_59 = 0 ; V_59 < V_110 ; ++ V_59 )
F_21 ( & V_35 -> V_65 [ V_59 ] ) ;
F_21 ( & V_35 -> V_68 ) ;
V_35 -> V_111 = F_111 ( V_128 [ V_129 ] ) ;
V_35 -> V_116 = F_111 ( V_128 [ V_129 ] ) ;
snprintf ( V_35 -> V_174 , V_195 , L_10 ,
F_81 ( V_35 ) / 1024 ) ;
V_196 = V_35 ;
}
static int T_4 F_196 ( char * V_197 )
{
unsigned long * V_198 ;
static unsigned long * V_199 ;
if ( ! V_193 )
V_198 = & V_191 ;
else
V_198 = & V_196 -> V_149 ;
if ( V_198 == V_199 ) {
F_195 ( L_11
L_12 ) ;
return 1 ;
}
if ( sscanf ( V_197 , L_13 , V_198 ) <= 0 )
* V_198 = 0 ;
if ( V_193 && V_196 -> V_81 >= V_82 )
F_148 ( V_196 ) ;
V_199 = V_198 ;
return 1 ;
}
static int T_4 F_197 ( char * V_197 )
{
V_187 = F_198 ( V_197 , & V_197 ) ;
return 1 ;
}
static unsigned int F_199 ( unsigned int * V_200 )
{
int V_181 ;
unsigned int V_201 = 0 ;
F_154 (node, cpuset_current_mems_allowed)
V_201 += V_200 [ V_181 ] ;
return V_201 ;
}
static int F_200 ( bool V_164 ,
struct V_202 * V_203 , int V_204 ,
void T_8 * V_205 , T_6 * V_206 , T_9 * V_207 )
{
struct V_34 * V_35 = & V_192 ;
unsigned long V_122 ;
int V_10 ;
V_122 = V_35 -> V_149 ;
if ( V_204 && V_35 -> V_81 >= V_82 )
return - V_167 ;
V_203 -> V_208 = & V_122 ;
V_203 -> V_209 = sizeof( unsigned long ) ;
V_10 = F_201 ( V_203 , V_204 , V_205 , V_206 , V_207 ) ;
if ( V_10 )
goto V_154;
if ( V_204 ) {
F_164 ( T_2 , V_109 ,
V_7 | V_166 ) ;
if ( ! ( V_164 &&
F_166 ( V_109 ) ) ) {
F_167 ( V_109 ) ;
V_109 = & V_128 [ V_129 ] ;
}
V_35 -> V_149 = F_157 ( V_35 , V_122 , V_109 ) ;
if ( V_109 != & V_128 [ V_129 ] )
F_167 ( V_109 ) ;
}
V_154:
return V_10 ;
}
int F_202 ( struct V_202 * V_203 , int V_204 ,
void T_8 * V_205 , T_6 * V_206 , T_9 * V_207 )
{
return F_200 ( false , V_203 , V_204 ,
V_205 , V_206 , V_207 ) ;
}
int F_203 ( struct V_202 * V_203 , int V_204 ,
void T_8 * V_205 , T_6 * V_206 , T_9 * V_207 )
{
return F_200 ( true , V_203 , V_204 ,
V_205 , V_206 , V_207 ) ;
}
int F_204 ( struct V_202 * V_203 , int V_204 ,
void T_8 * V_205 ,
T_6 * V_206 , T_9 * V_207 )
{
F_205 ( V_203 , V_204 , V_205 , V_206 , V_207 ) ;
if ( V_210 )
V_79 = V_211 ;
else
V_79 = V_212 ;
return 0 ;
}
int F_206 ( struct V_202 * V_203 , int V_204 ,
void T_8 * V_205 ,
T_6 * V_206 , T_9 * V_207 )
{
struct V_34 * V_35 = & V_192 ;
unsigned long V_122 ;
int V_10 ;
V_122 = V_35 -> V_119 ;
if ( V_204 && V_35 -> V_81 >= V_82 )
return - V_167 ;
V_203 -> V_208 = & V_122 ;
V_203 -> V_209 = sizeof( unsigned long ) ;
V_10 = F_201 ( V_203 , V_204 , V_205 , V_206 , V_207 ) ;
if ( V_10 )
goto V_154;
if ( V_204 ) {
F_8 ( & V_95 ) ;
V_35 -> V_119 = V_122 ;
F_2 ( & V_95 ) ;
}
V_154:
return V_10 ;
}
void F_207 ( struct V_213 * V_142 )
{
struct V_34 * V_35 = & V_192 ;
F_208 ( V_142 ,
L_14
L_15
L_16
L_17
L_18 ,
V_35 -> V_83 ,
V_35 -> V_66 ,
V_35 -> V_54 ,
V_35 -> V_97 ,
1UL << ( F_31 ( V_35 ) + V_148 - 10 ) ) ;
}
int F_209 ( int V_63 , char * V_150 )
{
struct V_34 * V_35 = & V_192 ;
return sprintf ( V_150 ,
L_19
L_20
L_21 ,
V_63 , V_35 -> V_84 [ V_63 ] ,
V_63 , V_35 -> V_67 [ V_63 ] ,
V_63 , V_35 -> V_96 [ V_63 ] ) ;
}
void F_210 ( void )
{
struct V_34 * V_35 ;
int V_63 ;
F_190 (nid, N_MEMORY)
F_80 (h)
F_152 ( L_22 ,
V_63 ,
V_35 -> V_84 [ V_63 ] ,
V_35 -> V_67 [ V_63 ] ,
V_35 -> V_96 [ V_63 ] ,
1UL << ( F_31 ( V_35 ) + V_148 - 10 ) ) ;
}
unsigned long F_211 ( void )
{
struct V_34 * V_35 ;
unsigned long V_214 = 0 ;
F_80 (h)
V_214 += V_35 -> V_83 * F_53 ( V_35 ) ;
return V_214 ;
}
static int F_212 ( struct V_34 * V_35 , long V_9 )
{
int V_10 = - V_11 ;
F_8 ( & V_95 ) ;
if ( V_9 > 0 ) {
if ( F_123 ( V_35 , V_9 ) < 0 )
goto V_154;
if ( V_9 > F_199 ( V_35 -> V_67 ) ) {
F_125 ( V_35 , V_9 ) ;
goto V_154;
}
}
V_10 = 0 ;
if ( V_9 < 0 )
F_125 ( V_35 , ( unsigned long ) - V_9 ) ;
V_154:
F_2 ( & V_95 ) ;
return V_10 ;
}
static void F_213 ( struct V_14 * V_15 )
{
struct V_42 * V_137 = F_43 ( V_15 ) ;
if ( V_137 )
F_214 ( & V_137 -> V_43 ) ;
}
static void F_215 ( struct V_14 * V_15 )
{
struct V_42 * V_137 = F_43 ( V_15 ) ;
if ( ! V_137 )
return;
F_216 ( & V_137 -> V_43 , F_41 ) ;
}
static void F_217 ( struct V_14 * V_15 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_42 * V_137 = F_43 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_15 ) ;
unsigned long V_215 ;
unsigned long V_216 ;
unsigned long V_30 ;
if ( V_137 ) {
V_216 = F_29 ( V_35 , V_15 , V_15 -> V_37 ) ;
V_30 = F_29 ( V_35 , V_15 , V_15 -> V_217 ) ;
V_215 = ( V_30 - V_216 ) -
F_26 ( & V_137 -> V_44 , V_216 , V_30 ) ;
F_215 ( V_15 ) ;
if ( V_215 ) {
F_212 ( V_35 , - V_215 ) ;
F_11 ( V_2 , V_215 ) ;
}
}
}
static int F_218 ( struct V_14 * V_15 , struct V_218 * V_219 )
{
F_184 () ;
return 0 ;
}
static T_10 F_219 ( struct V_14 * V_15 , struct V_56 * V_56 ,
int V_220 )
{
T_10 V_221 ;
if ( V_220 ) {
V_221 = F_220 ( F_221 ( F_222 ( V_56 ,
V_15 -> V_222 ) ) ) ;
} else {
V_221 = F_223 ( F_222 ( V_56 ,
V_15 -> V_222 ) ) ;
}
V_221 = F_224 ( V_221 ) ;
V_221 = F_225 ( V_221 ) ;
V_221 = F_226 ( V_221 , V_15 , V_56 , V_220 ) ;
return V_221 ;
}
static void F_227 ( struct V_14 * V_15 ,
unsigned long V_36 , T_10 * V_223 )
{
T_10 V_221 ;
V_221 = F_220 ( F_221 ( F_228 ( V_223 ) ) ) ;
if ( F_229 ( V_15 , V_36 , V_223 , V_221 , 1 ) )
F_230 ( V_15 , V_36 , V_223 ) ;
}
int F_231 ( struct V_224 * V_57 , struct V_224 * V_58 ,
struct V_14 * V_15 )
{
T_10 * V_225 , * V_226 , V_221 ;
struct V_56 * V_227 ;
unsigned long V_130 ;
int V_228 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_229 = F_81 ( V_35 ) ;
V_228 = ( V_15 -> V_47 & ( V_230 | V_231 ) ) == V_231 ;
for ( V_130 = V_15 -> V_37 ; V_130 < V_15 -> V_217 ; V_130 += V_229 ) {
V_225 = F_232 ( V_58 , V_130 ) ;
if ( ! V_225 )
continue;
V_226 = F_233 ( V_57 , V_130 , V_229 ) ;
if ( ! V_226 )
goto V_232;
if ( V_226 == V_225 )
continue;
F_8 ( & V_57 -> V_233 ) ;
F_234 ( & V_58 -> V_233 , V_234 ) ;
if ( ! F_235 ( F_228 ( V_225 ) ) ) {
if ( V_228 )
F_236 ( V_58 , V_130 , V_225 ) ;
V_221 = F_228 ( V_225 ) ;
V_227 = F_237 ( V_221 ) ;
F_238 ( V_227 ) ;
F_239 ( V_227 ) ;
F_240 ( V_57 , V_130 , V_226 , V_221 ) ;
}
F_2 ( & V_58 -> V_233 ) ;
F_2 ( & V_57 -> V_233 ) ;
}
return 0 ;
V_232:
return - V_11 ;
}
static int F_241 ( T_10 V_235 )
{
T_11 V_236 ;
if ( F_235 ( V_235 ) || F_242 ( V_235 ) )
return 0 ;
V_236 = F_243 ( V_235 ) ;
if ( F_244 ( V_236 ) && F_245 ( V_236 ) )
return 1 ;
else
return 0 ;
}
static int F_246 ( T_10 V_235 )
{
T_11 V_236 ;
if ( F_235 ( V_235 ) || F_242 ( V_235 ) )
return 0 ;
V_236 = F_243 ( V_235 ) ;
if ( F_244 ( V_236 ) && F_247 ( V_236 ) )
return 1 ;
else
return 0 ;
}
void F_248 ( struct V_237 * V_238 , struct V_14 * V_15 ,
unsigned long V_216 , unsigned long V_30 ,
struct V_56 * V_239 )
{
int V_240 = 0 ;
struct V_224 * V_241 = V_15 -> V_242 ;
unsigned long V_36 ;
T_10 * V_223 ;
T_10 V_235 ;
struct V_56 * V_56 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_229 = F_81 ( V_35 ) ;
const unsigned long V_243 = V_216 ;
const unsigned long V_244 = V_30 ;
F_146 ( ! F_35 ( V_15 ) ) ;
F_9 ( V_216 & ~ F_249 ( V_35 ) ) ;
F_9 ( V_30 & ~ F_249 ( V_35 ) ) ;
F_250 ( V_238 , V_15 ) ;
F_251 ( V_241 , V_243 , V_244 ) ;
V_245:
F_8 ( & V_241 -> V_233 ) ;
for ( V_36 = V_216 ; V_36 < V_30 ; V_36 += V_229 ) {
V_223 = F_232 ( V_241 , V_36 ) ;
if ( ! V_223 )
continue;
if ( F_252 ( V_241 , & V_36 , V_223 ) )
continue;
V_235 = F_228 ( V_223 ) ;
if ( F_235 ( V_235 ) )
continue;
if ( F_58 ( F_246 ( V_235 ) ) ) {
F_253 ( V_241 , V_36 , V_223 ) ;
continue;
}
V_56 = F_237 ( V_235 ) ;
if ( V_239 ) {
if ( V_56 != V_239 )
continue;
F_46 ( V_15 , V_246 ) ;
}
V_235 = F_254 ( V_241 , V_36 , V_223 ) ;
F_255 ( V_238 , V_223 , V_36 ) ;
if ( F_256 ( V_235 ) )
F_257 ( V_56 ) ;
F_258 ( V_56 ) ;
V_240 = ! F_259 ( V_238 , V_56 ) ;
if ( V_240 )
break;
if ( V_239 )
break;
}
F_2 ( & V_241 -> V_233 ) ;
if ( V_240 ) {
V_240 = 0 ;
F_260 ( V_238 ) ;
if ( V_36 < V_30 && ! V_239 )
goto V_245;
}
F_261 ( V_241 , V_243 , V_244 ) ;
F_262 ( V_238 , V_15 ) ;
}
void F_263 ( struct V_237 * V_238 ,
struct V_14 * V_15 , unsigned long V_216 ,
unsigned long V_30 , struct V_56 * V_239 )
{
F_248 ( V_238 , V_15 , V_216 , V_30 , V_239 ) ;
V_15 -> V_47 &= ~ V_48 ;
}
void F_264 ( struct V_14 * V_15 , unsigned long V_216 ,
unsigned long V_30 , struct V_56 * V_239 )
{
struct V_224 * V_241 ;
struct V_237 V_238 ;
V_241 = V_15 -> V_242 ;
F_265 ( & V_238 , V_241 , V_216 , V_30 ) ;
F_248 ( & V_238 , V_15 , V_216 , V_30 , V_239 ) ;
F_266 ( & V_238 , V_216 , V_30 ) ;
}
static int F_267 ( struct V_224 * V_241 , struct V_14 * V_15 ,
struct V_56 * V_56 , unsigned long V_36 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_14 * V_247 ;
struct V_131 * V_94 ;
T_1 V_248 ;
V_36 = V_36 & F_249 ( V_35 ) ;
V_248 = ( ( V_36 - V_15 -> V_37 ) >> V_148 ) +
V_15 -> V_38 ;
V_94 = F_15 ( V_15 -> V_16 ) -> V_135 ;
F_268 ( & V_94 -> V_249 ) ;
F_269 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_247 == V_15 )
continue;
if ( ! F_47 ( V_247 , V_55 ) )
F_264 ( V_247 , V_36 ,
V_36 + F_81 ( V_35 ) , V_56 ) ;
}
F_270 ( & V_94 -> V_249 ) ;
return 1 ;
}
static int F_271 ( struct V_224 * V_241 , struct V_14 * V_15 ,
unsigned long V_36 , T_10 * V_223 , T_10 V_235 ,
struct V_56 * V_250 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
struct V_56 * V_251 , * V_252 ;
int V_253 ;
int V_254 = 0 ;
unsigned long V_243 ;
unsigned long V_244 ;
V_251 = F_237 ( V_235 ) ;
V_255:
V_253 = ( F_86 ( V_251 ) == 1 ) ;
if ( V_253 ) {
if ( F_272 ( V_251 ) )
F_273 ( V_251 , V_15 , V_36 ) ;
F_227 ( V_15 , V_36 , V_223 ) ;
return 0 ;
}
if ( ! ( V_15 -> V_47 & V_48 ) &&
F_47 ( V_15 , V_55 ) &&
V_251 != V_250 )
V_254 = 1 ;
F_274 ( V_251 ) ;
F_2 ( & V_241 -> V_233 ) ;
V_252 = F_128 ( V_15 , V_36 , V_254 ) ;
if ( F_275 ( V_252 ) ) {
long V_80 = F_276 ( V_252 ) ;
F_277 ( V_251 ) ;
if ( V_254 ) {
F_9 ( F_235 ( V_235 ) ) ;
if ( F_267 ( V_241 , V_15 , V_251 , V_36 ) ) {
F_9 ( F_235 ( V_235 ) ) ;
F_8 ( & V_241 -> V_233 ) ;
V_223 = F_232 ( V_241 , V_36 & F_249 ( V_35 ) ) ;
if ( F_278 ( F_279 ( F_228 ( V_223 ) , V_235 ) ) )
goto V_255;
return 0 ;
}
F_280 ( 1 ) ;
}
F_8 ( & V_241 -> V_233 ) ;
if ( V_80 == - V_11 )
return V_256 ;
else
return V_257 ;
}
if ( F_58 ( F_281 ( V_15 ) ) ) {
F_277 ( V_252 ) ;
F_277 ( V_251 ) ;
F_8 ( & V_241 -> V_233 ) ;
return V_256 ;
}
F_282 ( V_252 , V_251 , V_36 , V_15 ,
F_53 ( V_35 ) ) ;
F_283 ( V_252 ) ;
V_243 = V_36 & F_249 ( V_35 ) ;
V_244 = V_243 + F_81 ( V_35 ) ;
F_251 ( V_241 , V_243 , V_244 ) ;
F_8 ( & V_241 -> V_233 ) ;
V_223 = F_232 ( V_241 , V_36 & F_249 ( V_35 ) ) ;
if ( F_278 ( F_279 ( F_228 ( V_223 ) , V_235 ) ) ) {
F_284 ( V_15 , V_36 , V_223 ) ;
F_240 ( V_241 , V_36 , V_223 ,
F_219 ( V_15 , V_252 , 1 ) ) ;
F_258 ( V_251 ) ;
F_285 ( V_252 , V_15 , V_36 ) ;
V_252 = V_251 ;
}
F_2 ( & V_241 -> V_233 ) ;
F_261 ( V_241 , V_243 , V_244 ) ;
F_8 ( & V_241 -> V_233 ) ;
F_277 ( V_252 ) ;
F_277 ( V_251 ) ;
return 0 ;
}
static struct V_56 * F_286 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_36 )
{
struct V_131 * V_94 ;
T_1 V_134 ;
V_94 = V_15 -> V_16 -> V_132 ;
V_134 = F_29 ( V_35 , V_15 , V_36 ) ;
return F_287 ( V_94 , V_134 ) ;
}
static bool F_288 ( struct V_34 * V_35 ,
struct V_14 * V_15 , unsigned long V_36 )
{
struct V_131 * V_94 ;
T_1 V_134 ;
struct V_56 * V_56 ;
V_94 = V_15 -> V_16 -> V_132 ;
V_134 = F_29 ( V_35 , V_15 , V_36 ) ;
V_56 = F_289 ( V_94 , V_134 ) ;
if ( V_56 )
F_92 ( V_56 ) ;
return V_56 != NULL ;
}
static int F_290 ( struct V_224 * V_241 , struct V_14 * V_15 ,
unsigned long V_36 , T_10 * V_223 , unsigned int V_51 )
{
struct V_34 * V_35 = F_33 ( V_15 ) ;
int V_10 = V_257 ;
int V_258 = 0 ;
T_1 V_134 ;
unsigned long V_93 ;
struct V_56 * V_56 ;
struct V_131 * V_94 ;
T_10 V_259 ;
if ( F_47 ( V_15 , V_246 ) ) {
F_195 ( L_23 ,
V_155 -> V_260 ) ;
return V_10 ;
}
V_94 = V_15 -> V_16 -> V_132 ;
V_134 = F_29 ( V_35 , V_15 , V_36 ) ;
V_126:
V_56 = F_287 ( V_94 , V_134 ) ;
if ( ! V_56 ) {
V_93 = F_291 ( V_94 -> V_133 ) >> F_30 ( V_35 ) ;
if ( V_134 >= V_93 )
goto V_154;
V_56 = F_128 ( V_15 , V_36 , 0 ) ;
if ( F_275 ( V_56 ) ) {
V_10 = F_276 ( V_56 ) ;
if ( V_10 == - V_11 )
V_10 = V_256 ;
else
V_10 = V_257 ;
goto V_154;
}
F_292 ( V_56 , V_36 , F_53 ( V_35 ) ) ;
F_283 ( V_56 ) ;
if ( V_15 -> V_47 & V_48 ) {
int V_80 ;
struct V_12 * V_12 = V_94 -> V_133 ;
V_80 = F_293 ( V_56 , V_94 , V_134 , V_7 ) ;
if ( V_80 ) {
F_92 ( V_56 ) ;
if ( V_80 == - V_261 )
goto V_126;
goto V_154;
}
F_8 ( & V_12 -> V_262 ) ;
V_12 -> V_263 += F_294 ( V_35 ) ;
F_2 ( & V_12 -> V_262 ) ;
} else {
F_295 ( V_56 ) ;
if ( F_58 ( F_281 ( V_15 ) ) ) {
V_10 = V_256 ;
goto V_264;
}
V_258 = 1 ;
}
} else {
if ( F_58 ( F_296 ( V_56 ) ) ) {
V_10 = V_265 |
F_297 ( F_88 ( V_35 ) ) ;
goto V_264;
}
}
if ( ( V_51 & V_266 ) && ! ( V_15 -> V_47 & V_230 ) )
if ( F_126 ( V_35 , V_15 , V_36 ) < 0 ) {
V_10 = V_256 ;
goto V_264;
}
F_8 ( & V_241 -> V_233 ) ;
V_93 = F_291 ( V_94 -> V_133 ) >> F_30 ( V_35 ) ;
if ( V_134 >= V_93 )
goto V_267;
V_10 = 0 ;
if ( ! F_235 ( F_228 ( V_223 ) ) )
goto V_267;
if ( V_258 )
F_285 ( V_56 , V_15 , V_36 ) ;
else
F_239 ( V_56 ) ;
V_259 = F_219 ( V_15 , V_56 , ( ( V_15 -> V_47 & V_268 )
&& ( V_15 -> V_47 & V_230 ) ) ) ;
F_240 ( V_241 , V_36 , V_223 , V_259 ) ;
if ( ( V_51 & V_266 ) && ! ( V_15 -> V_47 & V_230 ) ) {
V_10 = F_271 ( V_241 , V_15 , V_36 , V_223 , V_259 , V_56 ) ;
}
F_2 ( & V_241 -> V_233 ) ;
F_298 ( V_56 ) ;
V_154:
return V_10 ;
V_267:
F_2 ( & V_241 -> V_233 ) ;
V_264:
F_298 ( V_56 ) ;
F_92 ( V_56 ) ;
goto V_154;
}
int F_299 ( struct V_224 * V_241 , struct V_14 * V_15 ,
unsigned long V_36 , unsigned int V_51 )
{
T_10 * V_223 ;
T_10 V_221 ;
int V_10 ;
struct V_56 * V_56 = NULL ;
struct V_56 * V_250 = NULL ;
static F_300 ( V_269 ) ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
V_36 &= F_249 ( V_35 ) ;
V_223 = F_232 ( V_241 , V_36 ) ;
if ( V_223 ) {
V_221 = F_228 ( V_223 ) ;
if ( F_58 ( F_241 ( V_221 ) ) ) {
F_301 ( V_241 , V_223 ) ;
return 0 ;
} else if ( F_58 ( F_246 ( V_221 ) ) )
return V_270 |
F_297 ( F_88 ( V_35 ) ) ;
}
V_223 = F_233 ( V_241 , V_36 , F_81 ( V_35 ) ) ;
if ( ! V_223 )
return V_256 ;
F_268 ( & V_269 ) ;
V_221 = F_228 ( V_223 ) ;
if ( F_235 ( V_221 ) ) {
V_10 = F_290 ( V_241 , V_15 , V_36 , V_223 , V_51 ) ;
goto V_271;
}
V_10 = 0 ;
if ( ( V_51 & V_266 ) && ! F_302 ( V_221 ) ) {
if ( F_126 ( V_35 , V_15 , V_36 ) < 0 ) {
V_10 = V_256 ;
goto V_271;
}
if ( ! ( V_15 -> V_47 & V_48 ) )
V_250 = F_286 ( V_35 ,
V_15 , V_36 ) ;
}
V_56 = F_237 ( V_221 ) ;
F_238 ( V_56 ) ;
if ( V_56 != V_250 )
F_295 ( V_56 ) ;
F_8 ( & V_241 -> V_233 ) ;
if ( F_58 ( ! F_279 ( V_221 , F_228 ( V_223 ) ) ) )
goto V_272;
if ( V_51 & V_266 ) {
if ( ! F_302 ( V_221 ) ) {
V_10 = F_271 ( V_241 , V_15 , V_36 , V_223 , V_221 ,
V_250 ) ;
goto V_272;
}
V_221 = F_221 ( V_221 ) ;
}
V_221 = F_224 ( V_221 ) ;
if ( F_229 ( V_15 , V_36 , V_223 , V_221 ,
V_51 & V_266 ) )
F_230 ( V_15 , V_36 , V_223 ) ;
V_272:
F_2 ( & V_241 -> V_233 ) ;
if ( V_250 ) {
F_298 ( V_250 ) ;
F_92 ( V_250 ) ;
}
if ( V_56 != V_250 )
F_298 ( V_56 ) ;
F_92 ( V_56 ) ;
V_271:
F_270 ( & V_269 ) ;
return V_10 ;
}
long F_303 ( struct V_224 * V_241 , struct V_14 * V_15 ,
struct V_56 * * V_273 , struct V_14 * * V_274 ,
unsigned long * V_275 , unsigned long * V_98 ,
long V_59 , unsigned int V_51 )
{
unsigned long V_276 ;
unsigned long V_277 = * V_275 ;
unsigned long V_278 = * V_98 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
F_8 ( & V_241 -> V_233 ) ;
while ( V_277 < V_15 -> V_217 && V_278 ) {
T_10 * V_235 ;
int V_279 ;
struct V_56 * V_56 ;
V_235 = F_232 ( V_241 , V_277 & F_249 ( V_35 ) ) ;
V_279 = ! V_235 || F_235 ( F_228 ( V_235 ) ) ;
if ( V_279 && ( V_51 & V_280 ) &&
! F_288 ( V_35 , V_15 , V_277 ) ) {
V_278 = 0 ;
break;
}
if ( V_279 || F_304 ( F_228 ( V_235 ) ) ||
( ( V_51 & V_281 ) &&
! F_302 ( F_228 ( V_235 ) ) ) ) {
int V_10 ;
F_2 ( & V_241 -> V_233 ) ;
V_10 = F_299 ( V_241 , V_15 , V_277 ,
( V_51 & V_281 ) ? V_266 : 0 ) ;
F_8 ( & V_241 -> V_233 ) ;
if ( ! ( V_10 & V_282 ) )
continue;
V_278 = 0 ;
break;
}
V_276 = ( V_277 & ~ F_249 ( V_35 ) ) >> V_148 ;
V_56 = F_237 ( F_228 ( V_235 ) ) ;
V_283:
if ( V_273 ) {
V_273 [ V_59 ] = F_305 ( V_56 , V_276 ) ;
F_238 ( V_273 [ V_59 ] ) ;
}
if ( V_274 )
V_274 [ V_59 ] = V_15 ;
V_277 += V_39 ;
++ V_276 ;
-- V_278 ;
++ V_59 ;
if ( V_277 < V_15 -> V_217 && V_278 &&
V_276 < F_53 ( V_35 ) ) {
goto V_283;
}
}
F_2 ( & V_241 -> V_233 ) ;
* V_98 = V_278 ;
* V_275 = V_277 ;
return V_59 ? V_59 : - V_284 ;
}
unsigned long F_306 ( struct V_14 * V_15 ,
unsigned long V_36 , unsigned long V_30 , T_12 V_285 )
{
struct V_224 * V_241 = V_15 -> V_242 ;
unsigned long V_216 = V_36 ;
T_10 * V_223 ;
T_10 V_235 ;
struct V_34 * V_35 = F_33 ( V_15 ) ;
unsigned long V_273 = 0 ;
F_9 ( V_36 >= V_30 ) ;
F_307 ( V_15 , V_36 , V_30 ) ;
F_268 ( & V_15 -> V_16 -> V_132 -> V_249 ) ;
F_8 ( & V_241 -> V_233 ) ;
for (; V_36 < V_30 ; V_36 += F_81 ( V_35 ) ) {
V_223 = F_232 ( V_241 , V_36 ) ;
if ( ! V_223 )
continue;
if ( F_252 ( V_241 , & V_36 , V_223 ) ) {
V_273 ++ ;
continue;
}
if ( ! F_235 ( F_228 ( V_223 ) ) ) {
V_235 = F_254 ( V_241 , V_36 , V_223 ) ;
V_235 = F_225 ( F_308 ( V_235 , V_285 ) ) ;
V_235 = F_226 ( V_235 , V_15 , NULL , 0 ) ;
F_240 ( V_241 , V_36 , V_223 , V_235 ) ;
V_273 ++ ;
}
}
F_2 ( & V_241 -> V_233 ) ;
F_309 ( V_15 , V_216 , V_30 ) ;
F_270 ( & V_15 -> V_16 -> V_132 -> V_249 ) ;
return V_273 << V_35 -> V_81 ;
}
int F_310 ( struct V_12 * V_12 ,
long V_26 , long V_25 ,
struct V_14 * V_15 ,
T_13 V_47 )
{
long V_10 , V_28 ;
struct V_34 * V_35 = F_311 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( V_47 & V_53 )
return 0 ;
if ( ! V_15 || V_15 -> V_47 & V_48 )
V_28 = F_20 ( & V_12 -> V_135 -> V_136 , V_26 , V_25 ) ;
else {
struct V_42 * V_42 = F_39 () ;
if ( ! V_42 )
return - V_11 ;
V_28 = V_25 - V_26 ;
F_45 ( V_15 , V_42 ) ;
F_46 ( V_15 , V_55 ) ;
}
if ( V_28 < 0 ) {
V_10 = V_28 ;
goto V_286;
}
if ( F_10 ( V_2 , V_28 ) ) {
V_10 = - V_140 ;
goto V_286;
}
V_10 = F_212 ( V_35 , V_28 ) ;
if ( V_10 < 0 ) {
F_11 ( V_2 , V_28 ) ;
goto V_286;
}
if ( ! V_15 || V_15 -> V_47 & V_48 )
F_16 ( & V_12 -> V_135 -> V_136 , V_26 , V_25 ) ;
return 0 ;
V_286:
if ( V_15 )
F_215 ( V_15 ) ;
return V_10 ;
}
void F_312 ( struct V_12 * V_12 , long V_287 , long V_288 )
{
struct V_34 * V_35 = F_311 ( V_12 ) ;
long V_28 = F_23 ( & V_12 -> V_135 -> V_136 , V_287 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_8 ( & V_12 -> V_262 ) ;
V_12 -> V_263 -= ( F_294 ( V_35 ) * V_288 ) ;
F_2 ( & V_12 -> V_262 ) ;
F_11 ( V_2 , ( V_28 - V_288 ) ) ;
F_212 ( V_35 , - ( V_28 - V_288 ) ) ;
}
static unsigned long F_313 ( struct V_14 * V_289 ,
struct V_14 * V_15 ,
unsigned long V_130 , T_1 V_134 )
{
unsigned long V_290 = ( ( V_134 - V_289 -> V_38 ) << V_148 ) +
V_289 -> V_37 ;
unsigned long V_291 = V_290 & V_292 ;
unsigned long V_293 = V_291 + V_294 ;
unsigned long V_47 = V_15 -> V_47 & ~ V_295 ;
unsigned long V_296 = V_289 -> V_47 & ~ V_295 ;
if ( F_314 ( V_130 ) != F_314 ( V_290 ) ||
V_47 != V_296 ||
V_291 < V_289 -> V_37 || V_289 -> V_217 < V_293 )
return 0 ;
return V_290 ;
}
static int F_315 ( struct V_14 * V_15 , unsigned long V_130 )
{
unsigned long V_297 = V_130 & V_292 ;
unsigned long V_30 = V_297 + V_294 ;
if ( V_15 -> V_47 & V_48 &&
V_15 -> V_37 <= V_297 && V_30 <= V_15 -> V_217 )
return 1 ;
return 0 ;
}
T_10 * F_316 ( struct V_224 * V_241 , unsigned long V_130 , T_14 * V_298 )
{
struct V_14 * V_15 = F_317 ( V_241 , V_130 ) ;
struct V_131 * V_94 = V_15 -> V_16 -> V_132 ;
T_1 V_134 = ( ( V_130 - V_15 -> V_37 ) >> V_148 ) +
V_15 -> V_38 ;
struct V_14 * V_289 ;
unsigned long V_290 ;
T_10 * V_299 = NULL ;
T_10 * V_235 ;
if ( ! F_315 ( V_15 , V_130 ) )
return ( T_10 * ) F_318 ( V_241 , V_298 , V_130 ) ;
F_268 ( & V_94 -> V_249 ) ;
F_269 (svma, &mapping->i_mmap, idx, idx) {
if ( V_289 == V_15 )
continue;
V_290 = F_313 ( V_289 , V_15 , V_130 , V_134 ) ;
if ( V_290 ) {
V_299 = F_232 ( V_289 -> V_242 , V_290 ) ;
if ( V_299 ) {
F_238 ( F_144 ( V_299 ) ) ;
break;
}
}
}
if ( ! V_299 )
goto V_154;
F_8 ( & V_241 -> V_233 ) ;
if ( F_319 ( * V_298 ) )
F_320 ( V_241 , V_298 ,
( V_300 * ) ( ( unsigned long ) V_299 & V_301 ) ) ;
else
F_92 ( F_144 ( V_299 ) ) ;
F_2 ( & V_241 -> V_233 ) ;
V_154:
V_235 = ( T_10 * ) F_318 ( V_241 , V_298 , V_130 ) ;
F_270 ( & V_94 -> V_249 ) ;
return V_235 ;
}
int F_252 ( struct V_224 * V_241 , unsigned long * V_130 , T_10 * V_223 )
{
T_15 * V_302 = F_321 ( V_241 , * V_130 ) ;
T_14 * V_298 = F_322 ( V_302 , * V_130 ) ;
F_9 ( F_85 ( F_144 ( V_223 ) ) == 0 ) ;
if ( F_85 ( F_144 ( V_223 ) ) == 1 )
return 0 ;
F_323 ( V_298 ) ;
F_92 ( F_144 ( V_223 ) ) ;
* V_130 = F_324 ( * V_130 , V_188 * V_303 ) - V_188 ;
return 1 ;
}
T_10 * F_316 ( struct V_224 * V_241 , unsigned long V_130 , T_14 * V_298 )
{
return NULL ;
}
T_10 * F_233 ( struct V_224 * V_241 ,
unsigned long V_130 , unsigned long V_229 )
{
T_15 * V_302 ;
T_14 * V_298 ;
T_10 * V_235 = NULL ;
V_302 = F_321 ( V_241 , V_130 ) ;
V_298 = F_325 ( V_241 , V_302 , V_130 ) ;
if ( V_298 ) {
if ( V_229 == V_294 ) {
V_235 = ( T_10 * ) V_298 ;
} else {
F_9 ( V_229 != V_304 ) ;
if ( F_326 () && F_319 ( * V_298 ) )
V_235 = F_316 ( V_241 , V_130 , V_298 ) ;
else
V_235 = ( T_10 * ) F_318 ( V_241 , V_298 , V_130 ) ;
}
}
F_9 ( V_235 && ! F_327 ( * V_235 ) && ! F_328 ( * V_235 ) ) ;
return V_235 ;
}
T_10 * F_232 ( struct V_224 * V_241 , unsigned long V_130 )
{
T_15 * V_302 ;
T_14 * V_298 ;
V_300 * V_305 = NULL ;
V_302 = F_321 ( V_241 , V_130 ) ;
if ( F_329 ( * V_302 ) ) {
V_298 = F_322 ( V_302 , V_130 ) ;
if ( F_330 ( * V_298 ) ) {
if ( F_331 ( * V_298 ) )
return ( T_10 * ) V_298 ;
V_305 = F_332 ( V_298 , V_130 ) ;
}
}
return ( T_10 * ) V_305 ;
}
struct V_56 *
F_333 ( struct V_224 * V_241 , unsigned long V_36 ,
V_300 * V_305 , int V_204 )
{
struct V_56 * V_56 ;
V_56 = F_237 ( * ( T_10 * ) V_305 ) ;
if ( V_56 )
V_56 += ( ( V_36 & ~ V_306 ) >> V_148 ) ;
return V_56 ;
}
struct V_56 *
F_334 ( struct V_224 * V_241 , unsigned long V_36 ,
T_14 * V_298 , int V_204 )
{
struct V_56 * V_56 ;
V_56 = F_237 ( * ( T_10 * ) V_298 ) ;
if ( V_56 )
V_56 += ( ( V_36 & ~ V_292 ) >> V_148 ) ;
return V_56 ;
}
struct V_56 *
F_334 ( struct V_224 * V_241 , unsigned long V_36 ,
T_14 * V_298 , int V_204 )
{
F_184 () ;
return NULL ;
}
static int F_335 ( struct V_56 * V_307 )
{
struct V_56 * V_56 ;
struct V_56 * V_122 ;
struct V_34 * V_35 = F_52 ( V_307 ) ;
int V_63 = F_61 ( V_307 ) ;
F_18 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_56 == V_307 )
return 1 ;
return 0 ;
}
int F_336 ( struct V_56 * V_307 )
{
struct V_34 * V_35 = F_52 ( V_307 ) ;
int V_63 = F_61 ( V_307 ) ;
int V_10 = - V_308 ;
F_8 ( & V_95 ) ;
if ( F_335 ( V_307 ) ) {
F_337 ( & V_307 -> V_64 ) ;
F_65 ( V_307 ) ;
V_35 -> V_66 -- ;
V_35 -> V_67 [ V_63 ] -- ;
V_10 = 0 ;
}
F_2 ( & V_95 ) ;
return V_10 ;
}
