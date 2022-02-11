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
long V_34 ;
long V_35 ;
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
F_61 ( & V_60 -> V_68 , & V_37 -> V_69 [ V_67 ] ) ;
V_37 -> V_70 ++ ;
V_37 -> V_71 [ V_67 ] ++ ;
}
static struct V_60 * F_62 ( struct V_36 * V_37 , int V_67 )
{
struct V_60 * V_60 ;
if ( F_63 ( & V_37 -> V_69 [ V_67 ] ) )
return NULL ;
V_60 = F_23 ( V_37 -> V_69 [ V_67 ] . V_33 , struct V_60 , V_68 ) ;
F_61 ( & V_60 -> V_68 , & V_37 -> V_72 ) ;
F_64 ( V_60 ) ;
V_37 -> V_70 -- ;
V_37 -> V_71 [ V_67 ] -- ;
return V_60 ;
}
static struct V_60 * F_65 ( struct V_36 * V_37 ,
struct V_14 * V_15 ,
unsigned long V_38 , int V_73 )
{
struct V_60 * V_60 = NULL ;
struct V_74 * V_75 ;
T_2 * V_76 ;
struct V_77 * V_77 ;
struct V_78 * V_78 ;
struct V_79 * V_80 ;
unsigned int V_81 ;
V_82:
V_81 = F_66 () ;
V_77 = F_67 ( V_15 , V_38 ,
V_83 , & V_75 , & V_76 ) ;
if ( ! F_49 ( V_15 ) &&
V_37 -> V_70 - V_37 -> V_58 == 0 )
goto V_84;
if ( V_73 && V_37 -> V_70 - V_37 -> V_58 == 0 )
goto V_84;
F_68 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_69 ( V_78 , V_83 ) ) {
V_60 = F_62 ( V_37 , F_70 ( V_78 ) ) ;
if ( V_60 ) {
if ( ! V_73 )
F_47 ( V_37 , V_15 ) ;
break;
}
}
}
F_71 ( V_75 ) ;
if ( F_57 ( ! F_72 ( V_81 ) && ! V_60 ) )
goto V_82;
return V_60 ;
V_84:
F_71 ( V_75 ) ;
return NULL ;
}
static void F_73 ( struct V_36 * V_37 , struct V_60 * V_60 )
{
int V_63 ;
F_43 ( V_37 -> V_42 >= V_85 ) ;
V_37 -> V_86 -- ;
V_37 -> V_87 [ F_60 ( V_60 ) ] -- ;
for ( V_63 = 0 ; V_63 < F_52 ( V_37 ) ; V_63 ++ ) {
V_60 [ V_63 ] . V_55 &= ~ ( 1 << V_88 | 1 << V_89 |
1 << V_90 | 1 << V_91 |
1 << V_92 | 1 << V_93 |
1 << V_94 | 1 << V_95 ) ;
}
F_43 ( F_74 ( V_60 ) ) ;
F_75 ( V_60 , NULL ) ;
F_64 ( V_60 ) ;
F_76 ( V_60 ) ;
F_77 ( V_60 , F_30 ( V_37 ) ) ;
}
struct V_36 * F_78 ( unsigned long V_96 )
{
struct V_36 * V_37 ;
F_79 (h) {
if ( F_80 ( V_37 ) == V_96 )
return V_37 ;
}
return NULL ;
}
static void F_81 ( struct V_60 * V_60 )
{
struct V_36 * V_37 = F_51 ( V_60 ) ;
int V_67 = F_60 ( V_60 ) ;
struct V_1 * V_2 =
(struct V_1 * ) F_82 ( V_60 ) ;
F_83 ( V_60 , 0 ) ;
V_60 -> V_97 = NULL ;
F_9 ( F_84 ( V_60 ) ) ;
F_9 ( F_85 ( V_60 ) ) ;
F_8 ( & V_98 ) ;
F_86 ( F_87 ( V_37 ) ,
F_52 ( V_37 ) , V_60 ) ;
if ( V_37 -> V_99 [ V_67 ] && F_30 ( V_37 ) < V_85 ) {
F_18 ( & V_60 -> V_68 ) ;
F_73 ( V_37 , V_60 ) ;
V_37 -> V_100 -- ;
V_37 -> V_99 [ V_67 ] -- ;
} else {
F_88 ( V_60 ) ;
F_59 ( V_37 , V_60 ) ;
}
F_2 ( & V_98 ) ;
F_11 ( V_2 , 1 ) ;
}
static void F_89 ( struct V_36 * V_37 , struct V_60 * V_60 , int V_67 )
{
F_20 ( & V_60 -> V_68 ) ;
F_75 ( V_60 , F_81 ) ;
F_8 ( & V_98 ) ;
F_90 ( V_60 , NULL ) ;
V_37 -> V_86 ++ ;
V_37 -> V_87 [ V_67 ] ++ ;
F_2 ( & V_98 ) ;
F_91 ( V_60 ) ;
}
static void F_92 ( struct V_60 * V_60 , unsigned long V_42 )
{
int V_63 ;
int V_101 = 1 << V_42 ;
struct V_60 * V_102 = V_60 + 1 ;
F_93 ( V_60 , V_42 ) ;
F_94 ( V_60 ) ;
for ( V_63 = 1 ; V_63 < V_101 ; V_63 ++ , V_102 = F_55 ( V_102 , V_60 , V_63 ) ) {
F_95 ( V_102 ) ;
F_96 ( V_102 , 0 ) ;
V_102 -> V_103 = V_60 ;
}
}
int F_97 ( struct V_60 * V_60 )
{
T_3 * V_104 ;
if ( ! F_98 ( V_60 ) )
return 0 ;
V_60 = F_99 ( V_60 ) ;
V_104 = F_100 ( V_60 ) ;
return V_104 == F_81 ;
}
static struct V_60 * F_101 ( struct V_36 * V_37 , int V_67 )
{
struct V_60 * V_60 ;
if ( V_37 -> V_42 >= V_85 )
return NULL ;
V_60 = F_102 ( V_67 ,
V_83 | V_105 | V_106 |
V_107 | V_108 ,
F_30 ( V_37 ) ) ;
if ( V_60 ) {
if ( F_103 ( V_60 ) ) {
F_77 ( V_60 , F_30 ( V_37 ) ) ;
return NULL ;
}
F_89 ( V_37 , V_60 , V_67 ) ;
}
return V_60 ;
}
static int F_104 ( int V_67 , T_2 * V_109 )
{
V_67 = F_105 ( V_67 , * V_109 ) ;
if ( V_67 == V_110 )
V_67 = F_106 ( * V_109 ) ;
F_43 ( V_67 >= V_110 ) ;
return V_67 ;
}
static int F_107 ( int V_67 , T_2 * V_109 )
{
if ( ! F_108 ( V_67 , * V_109 ) )
V_67 = F_104 ( V_67 , V_109 ) ;
return V_67 ;
}
static int F_109 ( struct V_36 * V_37 ,
T_2 * V_109 )
{
int V_67 ;
F_43 ( ! V_109 ) ;
V_67 = F_107 ( V_37 -> V_111 , V_109 ) ;
V_37 -> V_111 = F_104 ( V_67 , V_109 ) ;
return V_67 ;
}
static int F_110 ( struct V_36 * V_37 , T_2 * V_109 )
{
struct V_60 * V_60 ;
int V_112 ;
int V_113 ;
int V_10 = 0 ;
V_112 = F_109 ( V_37 , V_109 ) ;
V_113 = V_112 ;
do {
V_60 = F_101 ( V_37 , V_113 ) ;
if ( V_60 ) {
V_10 = 1 ;
break;
}
V_113 = F_109 ( V_37 , V_109 ) ;
} while ( V_113 != V_112 );
if ( V_10 )
F_111 ( V_114 ) ;
else
F_111 ( V_115 ) ;
return V_10 ;
}
static int F_112 ( struct V_36 * V_37 , T_2 * V_109 )
{
int V_67 ;
F_43 ( ! V_109 ) ;
V_67 = F_107 ( V_37 -> V_116 , V_109 ) ;
V_37 -> V_116 = F_104 ( V_67 , V_109 ) ;
return V_67 ;
}
static int F_113 ( struct V_36 * V_37 , T_2 * V_109 ,
bool V_117 )
{
int V_112 ;
int V_113 ;
int V_10 = 0 ;
V_112 = F_112 ( V_37 , V_109 ) ;
V_113 = V_112 ;
do {
if ( ( ! V_117 || V_37 -> V_99 [ V_113 ] ) &&
! F_63 ( & V_37 -> V_69 [ V_113 ] ) ) {
struct V_60 * V_60 =
F_23 ( V_37 -> V_69 [ V_113 ] . V_33 ,
struct V_60 , V_68 ) ;
F_18 ( & V_60 -> V_68 ) ;
V_37 -> V_70 -- ;
V_37 -> V_71 [ V_113 ] -- ;
if ( V_117 ) {
V_37 -> V_100 -- ;
V_37 -> V_99 [ V_113 ] -- ;
}
F_73 ( V_37 , V_60 ) ;
V_10 = 1 ;
break;
}
V_113 = F_112 ( V_37 , V_109 ) ;
} while ( V_113 != V_112 );
return V_10 ;
}
static struct V_60 * F_114 ( struct V_36 * V_37 , int V_67 )
{
struct V_60 * V_60 ;
unsigned int V_118 ;
if ( V_37 -> V_42 >= V_85 )
return NULL ;
F_8 ( & V_98 ) ;
if ( V_37 -> V_100 >= V_37 -> V_119 ) {
F_2 ( & V_98 ) ;
return NULL ;
} else {
V_37 -> V_86 ++ ;
V_37 -> V_100 ++ ;
}
F_2 ( & V_98 ) ;
if ( V_67 == V_120 )
V_60 = F_115 ( V_83 | V_105 |
V_107 | V_108 ,
F_30 ( V_37 ) ) ;
else
V_60 = F_102 ( V_67 ,
V_83 | V_105 | V_106 |
V_107 | V_108 , F_30 ( V_37 ) ) ;
if ( V_60 && F_103 ( V_60 ) ) {
F_77 ( V_60 , F_30 ( V_37 ) ) ;
V_60 = NULL ;
}
F_8 ( & V_98 ) ;
if ( V_60 ) {
F_20 ( & V_60 -> V_68 ) ;
V_118 = F_60 ( V_60 ) ;
F_75 ( V_60 , F_81 ) ;
F_90 ( V_60 , NULL ) ;
V_37 -> V_87 [ V_118 ] ++ ;
V_37 -> V_99 [ V_118 ] ++ ;
F_116 ( V_114 ) ;
} else {
V_37 -> V_86 -- ;
V_37 -> V_100 -- ;
F_116 ( V_115 ) ;
}
F_2 ( & V_98 ) ;
return V_60 ;
}
struct V_60 * F_117 ( struct V_36 * V_37 , int V_67 )
{
struct V_60 * V_60 ;
F_8 ( & V_98 ) ;
V_60 = F_62 ( V_37 , V_67 ) ;
F_2 ( & V_98 ) ;
if ( ! V_60 )
V_60 = F_114 ( V_37 , V_67 ) ;
return V_60 ;
}
static int F_118 ( struct V_36 * V_37 , int V_9 )
{
struct V_19 V_121 ;
struct V_60 * V_60 , * V_122 ;
int V_10 , V_63 ;
int V_123 , V_124 ;
bool V_125 = true ;
V_123 = ( V_37 -> V_58 + V_9 ) - V_37 -> V_70 ;
if ( V_123 <= 0 ) {
V_37 -> V_58 += V_9 ;
return 0 ;
}
V_124 = 0 ;
F_20 ( & V_121 ) ;
V_10 = - V_11 ;
V_126:
F_2 ( & V_98 ) ;
for ( V_63 = 0 ; V_63 < V_123 ; V_63 ++ ) {
V_60 = F_114 ( V_37 , V_120 ) ;
if ( ! V_60 ) {
V_125 = false ;
break;
}
F_21 ( & V_60 -> V_68 , & V_121 ) ;
}
V_124 += V_63 ;
F_8 ( & V_98 ) ;
V_123 = ( V_37 -> V_58 + V_9 ) -
( V_37 -> V_70 + V_124 ) ;
if ( V_123 > 0 ) {
if ( V_125 )
goto V_126;
goto free;
}
V_123 += V_124 ;
V_37 -> V_58 += V_9 ;
V_10 = 0 ;
F_17 (page, tmp, &surplus_list, lru) {
if ( ( -- V_123 ) < 0 )
break;
F_119 ( V_60 ) ;
F_43 ( F_84 ( V_60 ) ) ;
F_59 ( V_37 , V_60 ) ;
}
free:
F_2 ( & V_98 ) ;
if ( ! F_63 ( & V_121 ) ) {
F_17 (page, tmp, &surplus_list, lru) {
F_91 ( V_60 ) ;
}
}
F_8 ( & V_98 ) ;
return V_10 ;
}
static void F_120 ( struct V_36 * V_37 ,
unsigned long V_127 )
{
unsigned long V_101 ;
V_37 -> V_58 -= V_127 ;
if ( V_37 -> V_42 >= V_85 )
return;
V_101 = F_27 ( V_127 , V_37 -> V_100 ) ;
while ( V_101 -- ) {
if ( ! F_113 ( V_37 , & V_128 [ V_129 ] , 1 ) )
break;
}
}
static long F_121 ( struct V_36 * V_37 ,
struct V_14 * V_15 , unsigned long V_130 )
{
struct V_131 * V_97 = V_15 -> V_16 -> V_132 ;
struct V_12 * V_12 = V_97 -> V_133 ;
if ( V_15 -> V_51 & V_52 ) {
T_1 V_134 = F_28 ( V_37 , V_15 , V_130 ) ;
return F_19 ( & V_12 -> V_135 -> V_136 ,
V_134 , V_134 + 1 ) ;
} else if ( ! F_46 ( V_15 , V_59 ) ) {
return 1 ;
} else {
long V_84 ;
T_1 V_134 = F_28 ( V_37 , V_15 , V_130 ) ;
struct V_46 * V_137 = F_42 ( V_15 ) ;
V_84 = F_19 ( & V_137 -> V_48 , V_134 , V_134 + 1 ) ;
if ( V_84 < 0 )
return V_84 ;
return 0 ;
}
}
static void F_122 ( struct V_36 * V_37 ,
struct V_14 * V_15 , unsigned long V_130 )
{
struct V_131 * V_97 = V_15 -> V_16 -> V_132 ;
struct V_12 * V_12 = V_97 -> V_133 ;
if ( V_15 -> V_51 & V_52 ) {
T_1 V_134 = F_28 ( V_37 , V_15 , V_130 ) ;
F_15 ( & V_12 -> V_135 -> V_136 , V_134 , V_134 + 1 ) ;
} else if ( F_46 ( V_15 , V_59 ) ) {
T_1 V_134 = F_28 ( V_37 , V_15 , V_130 ) ;
struct V_46 * V_137 = F_42 ( V_15 ) ;
F_15 ( & V_137 -> V_48 , V_134 , V_134 + 1 ) ;
}
}
static struct V_60 * F_123 ( struct V_14 * V_15 ,
unsigned long V_130 , int V_73 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
struct V_60 * V_60 ;
long V_30 ;
int V_10 , V_134 ;
struct V_138 * V_139 ;
V_134 = F_87 ( V_37 ) ;
V_30 = F_121 ( V_37 , V_15 , V_130 ) ;
if ( V_30 < 0 )
return F_124 ( - V_11 ) ;
if ( V_30 )
if ( F_10 ( V_2 , V_30 ) )
return F_124 ( - V_140 ) ;
V_10 = F_125 ( V_134 , F_52 ( V_37 ) , & V_139 ) ;
if ( V_10 ) {
F_11 ( V_2 , V_30 ) ;
return F_124 ( - V_140 ) ;
}
F_8 ( & V_98 ) ;
V_60 = F_65 ( V_37 , V_15 , V_130 , V_73 ) ;
if ( V_60 ) {
F_126 ( V_134 , F_52 ( V_37 ) ,
V_139 , V_60 ) ;
F_2 ( & V_98 ) ;
} else {
F_2 ( & V_98 ) ;
V_60 = F_114 ( V_37 , V_120 ) ;
if ( ! V_60 ) {
F_127 ( V_134 ,
F_52 ( V_37 ) ,
V_139 ) ;
F_11 ( V_2 , V_30 ) ;
return F_124 ( - V_140 ) ;
}
F_8 ( & V_98 ) ;
F_126 ( V_134 , F_52 ( V_37 ) ,
V_139 , V_60 ) ;
F_61 ( & V_60 -> V_68 , & V_37 -> V_72 ) ;
F_2 ( & V_98 ) ;
}
F_83 ( V_60 , ( unsigned long ) V_2 ) ;
F_122 ( V_37 , V_15 , V_130 ) ;
return V_60 ;
}
int __weak F_128 ( struct V_36 * V_37 )
{
struct V_141 * V_142 ;
int V_143 = F_129 ( V_128 [ V_129 ] ) ;
while ( V_143 ) {
void * V_130 ;
V_130 = F_130 (
F_131 ( F_109 ( V_37 ,
& V_128 [ V_129 ] ) ) ,
F_80 ( V_37 ) , F_80 ( V_37 ) , 0 ) ;
if ( V_130 ) {
V_142 = V_130 ;
goto V_144;
}
V_143 -- ;
}
return 0 ;
V_144:
F_9 ( ( unsigned long ) F_132 ( V_142 ) & ( F_80 ( V_37 ) - 1 ) ) ;
F_21 ( & V_142 -> V_145 , & V_146 ) ;
V_142 -> V_36 = V_37 ;
return 1 ;
}
static void F_133 ( struct V_60 * V_60 , int V_42 )
{
if ( F_57 ( V_42 > ( V_85 - 1 ) ) )
F_92 ( V_60 , V_42 ) ;
else
F_134 ( V_60 , V_42 ) ;
}
static void T_4 F_135 ( void )
{
struct V_141 * V_142 ;
F_16 (m, &huge_boot_pages, list) {
struct V_36 * V_37 = V_142 -> V_36 ;
struct V_60 * V_60 ;
#ifdef F_136
V_60 = F_137 ( V_142 -> V_147 >> V_43 ) ;
F_138 ( ( unsigned long ) V_142 ,
sizeof( struct V_141 ) ) ;
#else
V_60 = F_139 ( V_142 ) ;
#endif
F_140 ( V_60 ) ;
F_141 ( F_84 ( V_60 ) != 1 ) ;
F_133 ( V_60 , V_37 -> V_42 ) ;
F_89 ( V_37 , V_60 , F_60 ( V_60 ) ) ;
if ( V_37 -> V_42 > ( V_85 - 1 ) )
V_148 += 1 << V_37 -> V_42 ;
}
}
static void T_4 F_142 ( struct V_36 * V_37 )
{
unsigned long V_63 ;
for ( V_63 = 0 ; V_63 < V_37 -> V_149 ; ++ V_63 ) {
if ( V_37 -> V_42 >= V_85 ) {
if ( ! F_128 ( V_37 ) )
break;
} else if ( ! F_110 ( V_37 ,
& V_128 [ V_129 ] ) )
break;
}
V_37 -> V_149 = V_63 ;
}
static void T_4 F_143 ( void )
{
struct V_36 * V_37 ;
F_79 (h) {
if ( V_37 -> V_42 < V_85 )
F_142 ( V_37 ) ;
}
}
static char * T_4 F_144 ( char * V_150 , unsigned long V_151 )
{
if ( V_151 >= ( 1UL << 30 ) )
sprintf ( V_150 , L_1 , V_151 >> 30 ) ;
else if ( V_151 >= ( 1UL << 20 ) )
sprintf ( V_150 , L_2 , V_151 >> 20 ) ;
else
sprintf ( V_150 , L_3 , V_151 >> 10 ) ;
return V_150 ;
}
static void T_4 F_145 ( void )
{
struct V_36 * V_37 ;
F_79 (h) {
char V_150 [ 32 ] ;
F_146 ( V_152 L_4
L_5 ,
F_144 ( V_150 , F_80 ( V_37 ) ) ,
V_37 -> V_70 ) ;
}
}
static void F_147 ( struct V_36 * V_37 , unsigned long V_3 ,
T_2 * V_109 )
{
int V_63 ;
if ( V_37 -> V_42 >= V_85 )
return;
F_148 (i, *nodes_allowed) {
struct V_60 * V_60 , * V_33 ;
struct V_19 * V_153 = & V_37 -> V_69 [ V_63 ] ;
F_17 (page, next, freel, lru) {
if ( V_3 >= V_37 -> V_86 )
return;
if ( F_149 ( V_60 ) )
continue;
F_18 ( & V_60 -> V_68 ) ;
F_73 ( V_37 , V_60 ) ;
V_37 -> V_70 -- ;
V_37 -> V_71 [ F_60 ( V_60 ) ] -- ;
}
}
}
static inline void F_147 ( struct V_36 * V_37 , unsigned long V_3 ,
T_2 * V_109 )
{
}
static int F_150 ( struct V_36 * V_37 , T_2 * V_109 ,
int V_9 )
{
int V_112 , V_113 ;
int V_10 = 0 ;
F_43 ( V_9 != - 1 && V_9 != 1 ) ;
if ( V_9 < 0 )
V_112 = F_109 ( V_37 , V_109 ) ;
else
V_112 = F_112 ( V_37 , V_109 ) ;
V_113 = V_112 ;
do {
int V_67 = V_113 ;
if ( V_9 < 0 ) {
if ( ! V_37 -> V_99 [ V_67 ] ) {
V_113 = F_109 ( V_37 ,
V_109 ) ;
continue;
}
}
if ( V_9 > 0 ) {
if ( V_37 -> V_99 [ V_67 ] >=
V_37 -> V_87 [ V_67 ] ) {
V_113 = F_112 ( V_37 ,
V_109 ) ;
continue;
}
}
V_37 -> V_100 += V_9 ;
V_37 -> V_99 [ V_67 ] += V_9 ;
V_10 = 1 ;
break;
} while ( V_113 != V_112 );
return V_10 ;
}
static unsigned long F_151 ( struct V_36 * V_37 , unsigned long V_3 ,
T_2 * V_109 )
{
unsigned long V_154 , V_10 ;
if ( V_37 -> V_42 >= V_85 )
return V_37 -> V_149 ;
F_8 ( & V_98 ) ;
while ( V_37 -> V_100 && V_3 > F_152 ( V_37 ) ) {
if ( ! F_150 ( V_37 , V_109 , - 1 ) )
break;
}
while ( V_3 > F_152 ( V_37 ) ) {
F_2 ( & V_98 ) ;
V_10 = F_110 ( V_37 , V_109 ) ;
F_8 ( & V_98 ) ;
if ( ! V_10 )
goto V_155;
if ( F_153 ( V_156 ) )
goto V_155;
}
V_154 = V_37 -> V_58 + V_37 -> V_86 - V_37 -> V_70 ;
V_154 = F_26 ( V_3 , V_154 ) ;
F_147 ( V_37 , V_154 , V_109 ) ;
while ( V_154 < F_152 ( V_37 ) ) {
if ( ! F_113 ( V_37 , V_109 , 0 ) )
break;
}
while ( V_3 < F_152 ( V_37 ) ) {
if ( ! F_150 ( V_37 , V_109 , 1 ) )
break;
}
V_155:
V_10 = F_152 ( V_37 ) ;
F_2 ( & V_98 ) ;
return V_10 ;
}
static struct V_36 * F_154 ( struct V_157 * V_158 , int * V_159 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_160 ; V_63 ++ )
if ( V_161 [ V_63 ] == V_158 ) {
if ( V_159 )
* V_159 = V_120 ;
return & V_162 [ V_63 ] ;
}
return F_155 ( V_158 , V_159 ) ;
}
static T_5 F_156 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_150 )
{
struct V_36 * V_37 ;
unsigned long V_86 ;
int V_67 ;
V_37 = F_154 ( V_158 , & V_67 ) ;
if ( V_67 == V_120 )
V_86 = V_37 -> V_86 ;
else
V_86 = V_37 -> V_87 [ V_67 ] ;
return sprintf ( V_150 , L_6 , V_86 ) ;
}
static T_5 F_157 ( bool V_165 ,
struct V_157 * V_158 , struct V_163 * V_164 ,
const char * V_150 , T_6 V_166 )
{
int V_84 ;
int V_67 ;
unsigned long V_3 ;
struct V_36 * V_37 ;
F_158 ( T_2 , V_109 , V_7 | V_167 ) ;
V_84 = F_159 ( V_150 , 10 , & V_3 ) ;
if ( V_84 )
goto V_155;
V_37 = F_154 ( V_158 , & V_67 ) ;
if ( V_37 -> V_42 >= V_85 ) {
V_84 = - V_168 ;
goto V_155;
}
if ( V_67 == V_120 ) {
if ( ! ( V_165 &&
F_160 ( V_109 ) ) ) {
F_161 ( V_109 ) ;
V_109 = & V_128 [ V_129 ] ;
}
} else if ( V_109 ) {
V_3 += V_37 -> V_86 - V_37 -> V_87 [ V_67 ] ;
F_162 ( V_109 , V_67 ) ;
} else
V_109 = & V_128 [ V_129 ] ;
V_37 -> V_149 = F_151 ( V_37 , V_3 , V_109 ) ;
if ( V_109 != & V_128 [ V_129 ] )
F_161 ( V_109 ) ;
return V_166 ;
V_155:
F_161 ( V_109 ) ;
return V_84 ;
}
static T_5 F_163 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_150 )
{
return F_156 ( V_158 , V_164 , V_150 ) ;
}
static T_5 F_164 ( struct V_157 * V_158 ,
struct V_163 * V_164 , const char * V_150 , T_6 V_166 )
{
return F_157 ( false , V_158 , V_164 , V_150 , V_166 ) ;
}
static T_5 F_165 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_150 )
{
return F_156 ( V_158 , V_164 , V_150 ) ;
}
static T_5 F_166 ( struct V_157 * V_158 ,
struct V_163 * V_164 , const char * V_150 , T_6 V_166 )
{
return F_157 ( true , V_158 , V_164 , V_150 , V_166 ) ;
}
static T_5 F_167 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_150 )
{
struct V_36 * V_37 = F_154 ( V_158 , NULL ) ;
return sprintf ( V_150 , L_6 , V_37 -> V_119 ) ;
}
static T_5 F_168 ( struct V_157 * V_158 ,
struct V_163 * V_164 , const char * V_150 , T_6 V_3 )
{
int V_84 ;
unsigned long V_169 ;
struct V_36 * V_37 = F_154 ( V_158 , NULL ) ;
if ( V_37 -> V_42 >= V_85 )
return - V_168 ;
V_84 = F_159 ( V_150 , 10 , & V_169 ) ;
if ( V_84 )
return V_84 ;
F_8 ( & V_98 ) ;
V_37 -> V_119 = V_169 ;
F_2 ( & V_98 ) ;
return V_3 ;
}
static T_5 F_169 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_150 )
{
struct V_36 * V_37 ;
unsigned long V_70 ;
int V_67 ;
V_37 = F_154 ( V_158 , & V_67 ) ;
if ( V_67 == V_120 )
V_70 = V_37 -> V_70 ;
else
V_70 = V_37 -> V_71 [ V_67 ] ;
return sprintf ( V_150 , L_6 , V_70 ) ;
}
static T_5 F_170 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_150 )
{
struct V_36 * V_37 = F_154 ( V_158 , NULL ) ;
return sprintf ( V_150 , L_6 , V_37 -> V_58 ) ;
}
static T_5 F_171 ( struct V_157 * V_158 ,
struct V_163 * V_164 , char * V_150 )
{
struct V_36 * V_37 ;
unsigned long V_100 ;
int V_67 ;
V_37 = F_154 ( V_158 , & V_67 ) ;
if ( V_67 == V_120 )
V_100 = V_37 -> V_100 ;
else
V_100 = V_37 -> V_99 [ V_67 ] ;
return sprintf ( V_150 , L_6 , V_100 ) ;
}
static int F_172 ( struct V_36 * V_37 , struct V_157 * V_170 ,
struct V_157 * * V_161 ,
struct V_171 * V_172 )
{
int V_173 ;
int V_174 = F_87 ( V_37 ) ;
V_161 [ V_174 ] = F_173 ( V_37 -> V_175 , V_170 ) ;
if ( ! V_161 [ V_174 ] )
return - V_11 ;
V_173 = F_174 ( V_161 [ V_174 ] , V_172 ) ;
if ( V_173 )
F_175 ( V_161 [ V_174 ] ) ;
return V_173 ;
}
static void T_4 F_176 ( void )
{
struct V_36 * V_37 ;
int V_84 ;
V_176 = F_173 ( L_7 , V_177 ) ;
if ( ! V_176 )
return;
F_79 (h) {
V_84 = F_172 ( V_37 , V_176 ,
V_161 , & V_172 ) ;
if ( V_84 )
F_146 ( V_178 L_8 ,
V_37 -> V_175 ) ;
}
}
static struct V_36 * F_155 ( struct V_157 * V_158 , int * V_159 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_179 ; V_67 ++ ) {
struct V_180 * V_181 = & V_182 [ V_67 ] ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_160 ; V_63 ++ )
if ( V_181 -> V_161 [ V_63 ] == V_158 ) {
if ( V_159 )
* V_159 = V_67 ;
return & V_162 [ V_63 ] ;
}
}
F_177 () ;
return NULL ;
}
void F_178 ( struct V_183 * V_183 )
{
struct V_36 * V_37 ;
struct V_180 * V_181 = & V_182 [ V_183 -> V_184 . V_185 ] ;
if ( ! V_181 -> V_176 )
return;
F_79 (h) {
int V_134 = F_87 ( V_37 ) ;
if ( V_181 -> V_161 [ V_134 ] ) {
F_175 ( V_181 -> V_161 [ V_134 ] ) ;
V_181 -> V_161 [ V_134 ] = NULL ;
}
}
F_175 ( V_181 -> V_176 ) ;
V_181 -> V_176 = NULL ;
}
static void F_179 ( void )
{
int V_67 ;
F_180 ( NULL , NULL ) ;
for ( V_67 = 0 ; V_67 < V_179 ; V_67 ++ )
F_178 ( V_186 [ V_67 ] ) ;
}
void F_181 ( struct V_183 * V_183 )
{
struct V_36 * V_37 ;
struct V_180 * V_181 = & V_182 [ V_183 -> V_184 . V_185 ] ;
int V_84 ;
if ( V_181 -> V_176 )
return;
V_181 -> V_176 = F_173 ( L_7 ,
& V_183 -> V_184 . V_158 ) ;
if ( ! V_181 -> V_176 )
return;
F_79 (h) {
V_84 = F_172 ( V_37 , V_181 -> V_176 ,
V_181 -> V_161 ,
& V_187 ) ;
if ( V_84 ) {
F_146 ( V_178 L_8
L_9 ,
V_37 -> V_175 , V_183 -> V_184 . V_185 ) ;
F_178 ( V_183 ) ;
break;
}
}
}
static void F_182 ( void )
{
int V_67 ;
F_183 (nid, N_MEMORY) {
struct V_183 * V_183 = V_186 [ V_67 ] ;
if ( V_183 -> V_184 . V_185 == V_67 )
F_181 ( V_183 ) ;
}
F_180 ( F_181 ,
F_178 ) ;
}
static struct V_36 * F_155 ( struct V_157 * V_158 , int * V_159 )
{
F_177 () ;
if ( V_159 )
* V_159 = - 1 ;
return NULL ;
}
static void F_179 ( void ) { }
static void F_182 ( void ) { }
static void T_7 F_184 ( void )
{
struct V_36 * V_37 ;
F_179 () ;
F_79 (h) {
F_175 ( V_161 [ F_87 ( V_37 ) ] ) ;
}
F_175 ( V_176 ) ;
}
static int T_4 F_185 ( void )
{
if ( V_188 == 0 )
return 0 ;
if ( ! F_78 ( V_189 ) ) {
V_189 = V_190 ;
if ( ! F_78 ( V_189 ) )
F_186 ( V_191 ) ;
}
V_192 = F_87 ( F_78 ( V_189 ) ) ;
if ( V_193 )
V_194 . V_149 = V_193 ;
F_143 () ;
F_135 () ;
F_145 () ;
F_176 () ;
F_182 () ;
F_187 () ;
return 0 ;
}
void T_4 F_186 ( unsigned V_42 )
{
struct V_36 * V_37 ;
unsigned long V_63 ;
if ( F_78 ( V_41 << V_42 ) ) {
F_146 ( V_195 L_10 ) ;
return;
}
F_9 ( V_196 >= V_160 ) ;
F_9 ( V_42 == 0 ) ;
V_37 = & V_162 [ V_196 ++ ] ;
V_37 -> V_42 = V_42 ;
V_37 -> V_197 = ~ ( ( 1ULL << ( V_42 + V_43 ) ) - 1 ) ;
V_37 -> V_86 = 0 ;
V_37 -> V_70 = 0 ;
for ( V_63 = 0 ; V_63 < V_110 ; ++ V_63 )
F_20 ( & V_37 -> V_69 [ V_63 ] ) ;
F_20 ( & V_37 -> V_72 ) ;
V_37 -> V_111 = F_106 ( V_128 [ V_129 ] ) ;
V_37 -> V_116 = F_106 ( V_128 [ V_129 ] ) ;
snprintf ( V_37 -> V_175 , V_198 , L_11 ,
F_80 ( V_37 ) / 1024 ) ;
V_199 = V_37 ;
}
static int T_4 F_188 ( char * V_200 )
{
unsigned long * V_201 ;
static unsigned long * V_202 ;
if ( ! V_196 )
V_201 = & V_193 ;
else
V_201 = & V_199 -> V_149 ;
if ( V_201 == V_202 ) {
F_146 ( V_195 L_12
L_13 ) ;
return 1 ;
}
if ( sscanf ( V_200 , L_14 , V_201 ) <= 0 )
* V_201 = 0 ;
if ( V_196 && V_199 -> V_42 >= V_85 )
F_142 ( V_199 ) ;
V_202 = V_201 ;
return 1 ;
}
static int T_4 F_189 ( char * V_200 )
{
V_189 = F_190 ( V_200 , & V_200 ) ;
return 1 ;
}
static unsigned int F_191 ( unsigned int * V_203 )
{
int V_183 ;
unsigned int V_204 = 0 ;
F_148 (node, cpuset_current_mems_allowed)
V_204 += V_203 [ V_183 ] ;
return V_204 ;
}
static int F_192 ( bool V_165 ,
struct V_205 * V_206 , int V_207 ,
void T_8 * V_208 , T_6 * V_209 , T_9 * V_210 )
{
struct V_36 * V_37 = & V_194 ;
unsigned long V_122 ;
int V_10 ;
V_122 = V_37 -> V_149 ;
if ( V_207 && V_37 -> V_42 >= V_85 )
return - V_168 ;
V_206 -> V_211 = & V_122 ;
V_206 -> V_212 = sizeof( unsigned long ) ;
V_10 = F_193 ( V_206 , V_207 , V_208 , V_209 , V_210 ) ;
if ( V_10 )
goto V_155;
if ( V_207 ) {
F_158 ( T_2 , V_109 ,
V_7 | V_167 ) ;
if ( ! ( V_165 &&
F_160 ( V_109 ) ) ) {
F_161 ( V_109 ) ;
V_109 = & V_128 [ V_129 ] ;
}
V_37 -> V_149 = F_151 ( V_37 , V_122 , V_109 ) ;
if ( V_109 != & V_128 [ V_129 ] )
F_161 ( V_109 ) ;
}
V_155:
return V_10 ;
}
int F_194 ( struct V_205 * V_206 , int V_207 ,
void T_8 * V_208 , T_6 * V_209 , T_9 * V_210 )
{
return F_192 ( false , V_206 , V_207 ,
V_208 , V_209 , V_210 ) ;
}
int F_195 ( struct V_205 * V_206 , int V_207 ,
void T_8 * V_208 , T_6 * V_209 , T_9 * V_210 )
{
return F_192 ( true , V_206 , V_207 ,
V_208 , V_209 , V_210 ) ;
}
int F_196 ( struct V_205 * V_206 , int V_207 ,
void T_8 * V_208 ,
T_6 * V_209 , T_9 * V_210 )
{
F_197 ( V_206 , V_207 , V_208 , V_209 , V_210 ) ;
if ( V_213 )
V_83 = V_214 ;
else
V_83 = V_215 ;
return 0 ;
}
int F_198 ( struct V_205 * V_206 , int V_207 ,
void T_8 * V_208 ,
T_6 * V_209 , T_9 * V_210 )
{
struct V_36 * V_37 = & V_194 ;
unsigned long V_122 ;
int V_10 ;
V_122 = V_37 -> V_119 ;
if ( V_207 && V_37 -> V_42 >= V_85 )
return - V_168 ;
V_206 -> V_211 = & V_122 ;
V_206 -> V_212 = sizeof( unsigned long ) ;
V_10 = F_193 ( V_206 , V_207 , V_208 , V_209 , V_210 ) ;
if ( V_10 )
goto V_155;
if ( V_207 ) {
F_8 ( & V_98 ) ;
V_37 -> V_119 = V_122 ;
F_2 ( & V_98 ) ;
}
V_155:
return V_10 ;
}
void F_199 ( struct V_216 * V_142 )
{
struct V_36 * V_37 = & V_194 ;
F_200 ( V_142 ,
L_15
L_16
L_17
L_18
L_19 ,
V_37 -> V_86 ,
V_37 -> V_70 ,
V_37 -> V_58 ,
V_37 -> V_100 ,
1UL << ( F_30 ( V_37 ) + V_43 - 10 ) ) ;
}
int F_201 ( int V_67 , char * V_150 )
{
struct V_36 * V_37 = & V_194 ;
return sprintf ( V_150 ,
L_20
L_21
L_22 ,
V_67 , V_37 -> V_87 [ V_67 ] ,
V_67 , V_37 -> V_71 [ V_67 ] ,
V_67 , V_37 -> V_99 [ V_67 ] ) ;
}
unsigned long F_202 ( void )
{
struct V_36 * V_37 = & V_194 ;
return V_37 -> V_86 * F_52 ( V_37 ) ;
}
static int F_203 ( struct V_36 * V_37 , long V_9 )
{
int V_10 = - V_11 ;
F_8 ( & V_98 ) ;
if ( V_9 > 0 ) {
if ( F_118 ( V_37 , V_9 ) < 0 )
goto V_155;
if ( V_9 > F_191 ( V_37 -> V_71 ) ) {
F_120 ( V_37 , V_9 ) ;
goto V_155;
}
}
V_10 = 0 ;
if ( V_9 < 0 )
F_120 ( V_37 , ( unsigned long ) - V_9 ) ;
V_155:
F_2 ( & V_98 ) ;
return V_10 ;
}
static void F_204 ( struct V_14 * V_15 )
{
struct V_46 * V_137 = F_42 ( V_15 ) ;
if ( V_137 )
F_205 ( & V_137 -> V_47 ) ;
}
static void F_206 ( struct V_14 * V_15 )
{
struct V_46 * V_137 = F_42 ( V_15 ) ;
if ( ! V_137 )
return;
F_207 ( & V_137 -> V_47 , F_40 ) ;
}
static void F_208 ( struct V_14 * V_15 )
{
struct V_36 * V_37 = F_32 ( V_15 ) ;
struct V_46 * V_137 = F_42 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_15 ) ;
unsigned long V_217 ;
unsigned long V_218 ;
unsigned long V_32 ;
if ( V_137 ) {
V_218 = F_28 ( V_37 , V_15 , V_15 -> V_39 ) ;
V_32 = F_28 ( V_37 , V_15 , V_15 -> V_219 ) ;
V_217 = ( V_32 - V_218 ) -
F_25 ( & V_137 -> V_48 , V_218 , V_32 ) ;
F_206 ( V_15 ) ;
if ( V_217 ) {
F_203 ( V_37 , - V_217 ) ;
F_11 ( V_2 , V_217 ) ;
}
}
}
static int F_209 ( struct V_14 * V_15 , struct V_220 * V_221 )
{
F_177 () ;
return 0 ;
}
static T_10 F_210 ( struct V_14 * V_15 , struct V_60 * V_60 ,
int V_222 )
{
T_10 V_223 ;
if ( V_222 ) {
V_223 =
F_211 ( F_212 ( F_213 ( V_60 , V_15 -> V_224 ) ) ) ;
} else {
V_223 = F_214 ( F_213 ( V_60 , V_15 -> V_224 ) ) ;
}
V_223 = F_215 ( V_223 ) ;
V_223 = F_216 ( V_223 ) ;
V_223 = F_217 ( V_223 , V_15 , V_60 , V_222 ) ;
return V_223 ;
}
static void F_218 ( struct V_14 * V_15 ,
unsigned long V_38 , T_10 * V_225 )
{
T_10 V_223 ;
V_223 = F_211 ( F_212 ( F_219 ( V_225 ) ) ) ;
if ( F_220 ( V_15 , V_38 , V_225 , V_223 , 1 ) )
F_221 ( V_15 , V_38 , V_225 ) ;
}
int F_222 ( struct V_226 * V_61 , struct V_226 * V_62 ,
struct V_14 * V_15 )
{
T_10 * V_227 , * V_228 , V_223 ;
struct V_60 * V_229 ;
unsigned long V_130 ;
int V_230 ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
unsigned long V_231 = F_80 ( V_37 ) ;
V_230 = ( V_15 -> V_51 & ( V_232 | V_233 ) ) == V_233 ;
for ( V_130 = V_15 -> V_39 ; V_130 < V_15 -> V_219 ; V_130 += V_231 ) {
V_227 = F_223 ( V_62 , V_130 ) ;
if ( ! V_227 )
continue;
V_228 = F_224 ( V_61 , V_130 , V_231 ) ;
if ( ! V_228 )
goto V_234;
if ( V_228 == V_227 )
continue;
F_8 ( & V_61 -> V_235 ) ;
F_225 ( & V_62 -> V_235 , V_236 ) ;
if ( ! F_226 ( F_219 ( V_227 ) ) ) {
if ( V_230 )
F_227 ( V_62 , V_130 , V_227 ) ;
V_223 = F_219 ( V_227 ) ;
V_229 = F_228 ( V_223 ) ;
F_229 ( V_229 ) ;
F_230 ( V_229 ) ;
F_231 ( V_61 , V_130 , V_228 , V_223 ) ;
}
F_2 ( & V_62 -> V_235 ) ;
F_2 ( & V_61 -> V_235 ) ;
}
return 0 ;
V_234:
return - V_11 ;
}
static int F_232 ( T_10 V_237 )
{
T_11 V_238 ;
if ( F_226 ( V_237 ) || F_233 ( V_237 ) )
return 0 ;
V_238 = F_234 ( V_237 ) ;
if ( F_235 ( V_238 ) && F_236 ( V_238 ) )
return 1 ;
else
return 0 ;
}
static int F_237 ( T_10 V_237 )
{
T_11 V_238 ;
if ( F_226 ( V_237 ) || F_233 ( V_237 ) )
return 0 ;
V_238 = F_234 ( V_237 ) ;
if ( F_235 ( V_238 ) && F_238 ( V_238 ) )
return 1 ;
else
return 0 ;
}
void F_239 ( struct V_239 * V_240 , struct V_14 * V_15 ,
unsigned long V_218 , unsigned long V_32 ,
struct V_60 * V_241 )
{
int V_242 = 0 ;
struct V_226 * V_243 = V_15 -> V_244 ;
unsigned long V_38 ;
T_10 * V_225 ;
T_10 V_237 ;
struct V_60 * V_60 ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
unsigned long V_231 = F_80 ( V_37 ) ;
const unsigned long V_245 = V_218 ;
const unsigned long V_246 = V_32 ;
F_141 ( ! F_34 ( V_15 ) ) ;
F_9 ( V_218 & ~ F_240 ( V_37 ) ) ;
F_9 ( V_32 & ~ F_240 ( V_37 ) ) ;
F_241 ( V_240 , V_15 ) ;
F_242 ( V_243 , V_245 , V_246 ) ;
V_247:
F_8 ( & V_243 -> V_235 ) ;
for ( V_38 = V_218 ; V_38 < V_32 ; V_38 += V_231 ) {
V_225 = F_223 ( V_243 , V_38 ) ;
if ( ! V_225 )
continue;
if ( F_243 ( V_243 , & V_38 , V_225 ) )
continue;
V_237 = F_219 ( V_225 ) ;
if ( F_226 ( V_237 ) )
continue;
if ( F_57 ( F_237 ( V_237 ) ) ) {
F_244 ( V_243 , V_38 , V_225 ) ;
continue;
}
V_60 = F_228 ( V_237 ) ;
if ( V_241 ) {
if ( V_60 != V_241 )
continue;
F_45 ( V_15 , V_248 ) ;
}
V_237 = F_245 ( V_243 , V_38 , V_225 ) ;
F_246 ( V_240 , V_225 , V_38 ) ;
if ( F_247 ( V_237 ) )
F_248 ( V_60 ) ;
F_249 ( V_60 ) ;
V_242 = ! F_250 ( V_240 , V_60 ) ;
if ( V_242 )
break;
if ( V_241 )
break;
}
F_2 ( & V_243 -> V_235 ) ;
if ( V_242 ) {
V_242 = 0 ;
F_251 ( V_240 ) ;
if ( V_38 < V_32 && ! V_241 )
goto V_247;
}
F_252 ( V_243 , V_245 , V_246 ) ;
F_253 ( V_240 , V_15 ) ;
}
void F_254 ( struct V_239 * V_240 ,
struct V_14 * V_15 , unsigned long V_218 ,
unsigned long V_32 , struct V_60 * V_241 )
{
F_239 ( V_240 , V_15 , V_218 , V_32 , V_241 ) ;
V_15 -> V_51 &= ~ V_52 ;
}
void F_255 ( struct V_14 * V_15 , unsigned long V_218 ,
unsigned long V_32 , struct V_60 * V_241 )
{
struct V_226 * V_243 ;
struct V_239 V_240 ;
V_243 = V_15 -> V_244 ;
F_256 ( & V_240 , V_243 , 0 ) ;
F_239 ( & V_240 , V_15 , V_218 , V_32 , V_241 ) ;
F_257 ( & V_240 , V_218 , V_32 ) ;
}
static int F_258 ( struct V_226 * V_243 , struct V_14 * V_15 ,
struct V_60 * V_60 , unsigned long V_38 )
{
struct V_36 * V_37 = F_32 ( V_15 ) ;
struct V_14 * V_249 ;
struct V_131 * V_97 ;
T_1 V_250 ;
V_38 = V_38 & F_240 ( V_37 ) ;
V_250 = ( ( V_38 - V_15 -> V_39 ) >> V_43 ) +
V_15 -> V_40 ;
V_97 = V_15 -> V_16 -> V_17 -> V_18 -> V_135 ;
F_259 ( & V_97 -> V_251 ) ;
F_260 (iter_vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_249 == V_15 )
continue;
if ( ! F_46 ( V_249 , V_59 ) )
F_255 ( V_249 , V_38 ,
V_38 + F_80 ( V_37 ) , V_60 ) ;
}
F_261 ( & V_97 -> V_251 ) ;
return 1 ;
}
static int F_262 ( struct V_226 * V_243 , struct V_14 * V_15 ,
unsigned long V_38 , T_10 * V_225 , T_10 V_237 ,
struct V_60 * V_252 )
{
struct V_36 * V_37 = F_32 ( V_15 ) ;
struct V_60 * V_253 , * V_254 ;
int V_255 ;
int V_256 = 0 ;
unsigned long V_245 ;
unsigned long V_246 ;
V_253 = F_228 ( V_237 ) ;
V_257:
V_255 = ( F_85 ( V_253 ) == 1 ) ;
if ( V_255 ) {
if ( F_263 ( V_253 ) )
F_264 ( V_253 , V_15 , V_38 ) ;
F_218 ( V_15 , V_38 , V_225 ) ;
return 0 ;
}
if ( ! ( V_15 -> V_51 & V_52 ) &&
F_46 ( V_15 , V_59 ) &&
V_253 != V_252 )
V_256 = 1 ;
F_265 ( V_253 ) ;
F_2 ( & V_243 -> V_235 ) ;
V_254 = F_123 ( V_15 , V_38 , V_256 ) ;
if ( F_266 ( V_254 ) ) {
long V_84 = F_267 ( V_254 ) ;
F_268 ( V_253 ) ;
if ( V_256 ) {
F_9 ( F_226 ( V_237 ) ) ;
if ( F_258 ( V_243 , V_15 , V_253 , V_38 ) ) {
F_9 ( F_226 ( V_237 ) ) ;
F_8 ( & V_243 -> V_235 ) ;
V_225 = F_223 ( V_243 , V_38 & F_240 ( V_37 ) ) ;
if ( F_269 ( F_270 ( F_219 ( V_225 ) , V_237 ) ) )
goto V_257;
return 0 ;
}
F_271 ( 1 ) ;
}
F_8 ( & V_243 -> V_235 ) ;
if ( V_84 == - V_11 )
return V_258 ;
else
return V_259 ;
}
if ( F_57 ( F_272 ( V_15 ) ) ) {
F_268 ( V_254 ) ;
F_268 ( V_253 ) ;
F_8 ( & V_243 -> V_235 ) ;
return V_258 ;
}
F_273 ( V_254 , V_253 , V_38 , V_15 ,
F_52 ( V_37 ) ) ;
F_274 ( V_254 ) ;
V_245 = V_38 & F_240 ( V_37 ) ;
V_246 = V_245 + F_80 ( V_37 ) ;
F_242 ( V_243 , V_245 , V_246 ) ;
F_8 ( & V_243 -> V_235 ) ;
V_225 = F_223 ( V_243 , V_38 & F_240 ( V_37 ) ) ;
if ( F_269 ( F_270 ( F_219 ( V_225 ) , V_237 ) ) ) {
F_275 ( V_15 , V_38 , V_225 ) ;
F_231 ( V_243 , V_38 , V_225 ,
F_210 ( V_15 , V_254 , 1 ) ) ;
F_249 ( V_253 ) ;
F_276 ( V_254 , V_15 , V_38 ) ;
V_254 = V_253 ;
}
F_2 ( & V_243 -> V_235 ) ;
F_252 ( V_243 , V_245 , V_246 ) ;
F_8 ( & V_243 -> V_235 ) ;
F_268 ( V_254 ) ;
F_268 ( V_253 ) ;
return 0 ;
}
static struct V_60 * F_277 ( struct V_36 * V_37 ,
struct V_14 * V_15 , unsigned long V_38 )
{
struct V_131 * V_97 ;
T_1 V_134 ;
V_97 = V_15 -> V_16 -> V_132 ;
V_134 = F_28 ( V_37 , V_15 , V_38 ) ;
return F_278 ( V_97 , V_134 ) ;
}
static bool F_279 ( struct V_36 * V_37 ,
struct V_14 * V_15 , unsigned long V_38 )
{
struct V_131 * V_97 ;
T_1 V_134 ;
struct V_60 * V_60 ;
V_97 = V_15 -> V_16 -> V_132 ;
V_134 = F_28 ( V_37 , V_15 , V_38 ) ;
V_60 = F_280 ( V_97 , V_134 ) ;
if ( V_60 )
F_91 ( V_60 ) ;
return V_60 != NULL ;
}
static int F_281 ( struct V_226 * V_243 , struct V_14 * V_15 ,
unsigned long V_38 , T_10 * V_225 , unsigned int V_55 )
{
struct V_36 * V_37 = F_32 ( V_15 ) ;
int V_10 = V_259 ;
int V_260 = 0 ;
T_1 V_134 ;
unsigned long V_96 ;
struct V_60 * V_60 ;
struct V_131 * V_97 ;
T_10 V_261 ;
if ( F_46 ( V_15 , V_248 ) ) {
F_146 ( V_195
L_23 ,
V_156 -> V_262 ) ;
return V_10 ;
}
V_97 = V_15 -> V_16 -> V_132 ;
V_134 = F_28 ( V_37 , V_15 , V_38 ) ;
V_126:
V_60 = F_278 ( V_97 , V_134 ) ;
if ( ! V_60 ) {
V_96 = F_282 ( V_97 -> V_133 ) >> F_29 ( V_37 ) ;
if ( V_134 >= V_96 )
goto V_155;
V_60 = F_123 ( V_15 , V_38 , 0 ) ;
if ( F_266 ( V_60 ) ) {
V_10 = F_267 ( V_60 ) ;
if ( V_10 == - V_11 )
V_10 = V_258 ;
else
V_10 = V_259 ;
goto V_155;
}
F_283 ( V_60 , V_38 , F_52 ( V_37 ) ) ;
F_274 ( V_60 ) ;
if ( V_15 -> V_51 & V_52 ) {
int V_84 ;
struct V_12 * V_12 = V_97 -> V_133 ;
V_84 = F_284 ( V_60 , V_97 , V_134 , V_7 ) ;
if ( V_84 ) {
F_91 ( V_60 ) ;
if ( V_84 == - V_263 )
goto V_126;
goto V_155;
}
F_8 ( & V_12 -> V_264 ) ;
V_12 -> V_265 += F_285 ( V_37 ) ;
F_2 ( & V_12 -> V_264 ) ;
} else {
F_286 ( V_60 ) ;
if ( F_57 ( F_272 ( V_15 ) ) ) {
V_10 = V_258 ;
goto V_266;
}
V_260 = 1 ;
}
} else {
if ( F_57 ( F_287 ( V_60 ) ) ) {
V_10 = V_267 |
F_288 ( F_87 ( V_37 ) ) ;
goto V_266;
}
}
if ( ( V_55 & V_268 ) && ! ( V_15 -> V_51 & V_232 ) )
if ( F_121 ( V_37 , V_15 , V_38 ) < 0 ) {
V_10 = V_258 ;
goto V_266;
}
F_8 ( & V_243 -> V_235 ) ;
V_96 = F_282 ( V_97 -> V_133 ) >> F_29 ( V_37 ) ;
if ( V_134 >= V_96 )
goto V_269;
V_10 = 0 ;
if ( ! F_226 ( F_219 ( V_225 ) ) )
goto V_269;
if ( V_260 )
F_276 ( V_60 , V_15 , V_38 ) ;
else
F_230 ( V_60 ) ;
V_261 = F_210 ( V_15 , V_60 , ( ( V_15 -> V_51 & V_270 )
&& ( V_15 -> V_51 & V_232 ) ) ) ;
F_231 ( V_243 , V_38 , V_225 , V_261 ) ;
if ( ( V_55 & V_268 ) && ! ( V_15 -> V_51 & V_232 ) ) {
V_10 = F_262 ( V_243 , V_15 , V_38 , V_225 , V_261 , V_60 ) ;
}
F_2 ( & V_243 -> V_235 ) ;
F_289 ( V_60 ) ;
V_155:
return V_10 ;
V_269:
F_2 ( & V_243 -> V_235 ) ;
V_266:
F_289 ( V_60 ) ;
F_91 ( V_60 ) ;
goto V_155;
}
int F_290 ( struct V_226 * V_243 , struct V_14 * V_15 ,
unsigned long V_38 , unsigned int V_55 )
{
T_10 * V_225 ;
T_10 V_223 ;
int V_10 ;
struct V_60 * V_60 = NULL ;
struct V_60 * V_252 = NULL ;
static F_291 ( V_271 ) ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
V_38 &= F_240 ( V_37 ) ;
V_225 = F_223 ( V_243 , V_38 ) ;
if ( V_225 ) {
V_223 = F_219 ( V_225 ) ;
if ( F_57 ( F_232 ( V_223 ) ) ) {
F_292 ( V_243 , ( V_272 * ) V_225 , V_38 ) ;
return 0 ;
} else if ( F_57 ( F_237 ( V_223 ) ) )
return V_273 |
F_288 ( F_87 ( V_37 ) ) ;
}
V_225 = F_224 ( V_243 , V_38 , F_80 ( V_37 ) ) ;
if ( ! V_225 )
return V_258 ;
F_259 ( & V_271 ) ;
V_223 = F_219 ( V_225 ) ;
if ( F_226 ( V_223 ) ) {
V_10 = F_281 ( V_243 , V_15 , V_38 , V_225 , V_55 ) ;
goto V_274;
}
V_10 = 0 ;
if ( ( V_55 & V_268 ) && ! F_293 ( V_223 ) ) {
if ( F_121 ( V_37 , V_15 , V_38 ) < 0 ) {
V_10 = V_258 ;
goto V_274;
}
if ( ! ( V_15 -> V_51 & V_52 ) )
V_252 = F_277 ( V_37 ,
V_15 , V_38 ) ;
}
V_60 = F_228 ( V_223 ) ;
F_229 ( V_60 ) ;
if ( V_60 != V_252 )
F_286 ( V_60 ) ;
F_8 ( & V_243 -> V_235 ) ;
if ( F_57 ( ! F_270 ( V_223 , F_219 ( V_225 ) ) ) )
goto V_275;
if ( V_55 & V_268 ) {
if ( ! F_293 ( V_223 ) ) {
V_10 = F_262 ( V_243 , V_15 , V_38 , V_225 , V_223 ,
V_252 ) ;
goto V_275;
}
V_223 = F_212 ( V_223 ) ;
}
V_223 = F_215 ( V_223 ) ;
if ( F_220 ( V_15 , V_38 , V_225 , V_223 ,
V_55 & V_268 ) )
F_221 ( V_15 , V_38 , V_225 ) ;
V_275:
F_2 ( & V_243 -> V_235 ) ;
if ( V_252 ) {
F_289 ( V_252 ) ;
F_91 ( V_252 ) ;
}
if ( V_60 != V_252 )
F_289 ( V_60 ) ;
F_91 ( V_60 ) ;
V_274:
F_261 ( & V_271 ) ;
return V_10 ;
}
struct V_60 *
F_294 ( struct V_226 * V_243 , unsigned long V_38 ,
T_12 * V_276 , int V_207 )
{
F_177 () ;
return NULL ;
}
int F_295 ( struct V_226 * V_243 , struct V_14 * V_15 ,
struct V_60 * * V_277 , struct V_14 * * V_278 ,
unsigned long * V_279 , int * V_209 , int V_63 ,
unsigned int V_55 )
{
unsigned long V_280 ;
unsigned long V_281 = * V_279 ;
int V_282 = * V_209 ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
F_8 ( & V_243 -> V_235 ) ;
while ( V_281 < V_15 -> V_219 && V_282 ) {
T_10 * V_237 ;
int V_283 ;
struct V_60 * V_60 ;
V_237 = F_223 ( V_243 , V_281 & F_240 ( V_37 ) ) ;
V_283 = ! V_237 || F_226 ( F_219 ( V_237 ) ) ;
if ( V_283 && ( V_55 & V_284 ) &&
! F_279 ( V_37 , V_15 , V_281 ) ) {
V_282 = 0 ;
break;
}
if ( V_283 ||
( ( V_55 & V_285 ) && ! F_293 ( F_219 ( V_237 ) ) ) ) {
int V_10 ;
F_2 ( & V_243 -> V_235 ) ;
V_10 = F_290 ( V_243 , V_15 , V_281 ,
( V_55 & V_285 ) ? V_268 : 0 ) ;
F_8 ( & V_243 -> V_235 ) ;
if ( ! ( V_10 & V_286 ) )
continue;
V_282 = 0 ;
break;
}
V_280 = ( V_281 & ~ F_240 ( V_37 ) ) >> V_43 ;
V_60 = F_228 ( F_219 ( V_237 ) ) ;
V_287:
if ( V_277 ) {
V_277 [ V_63 ] = F_296 ( V_60 , V_280 ) ;
F_229 ( V_277 [ V_63 ] ) ;
}
if ( V_278 )
V_278 [ V_63 ] = V_15 ;
V_281 += V_41 ;
++ V_280 ;
-- V_282 ;
++ V_63 ;
if ( V_281 < V_15 -> V_219 && V_282 &&
V_280 < F_52 ( V_37 ) ) {
goto V_287;
}
}
F_2 ( & V_243 -> V_235 ) ;
* V_209 = V_282 ;
* V_279 = V_281 ;
return V_63 ? V_63 : - V_288 ;
}
unsigned long F_297 ( struct V_14 * V_15 ,
unsigned long V_38 , unsigned long V_32 , T_13 V_289 )
{
struct V_226 * V_243 = V_15 -> V_244 ;
unsigned long V_218 = V_38 ;
T_10 * V_225 ;
T_10 V_237 ;
struct V_36 * V_37 = F_32 ( V_15 ) ;
unsigned long V_277 = 0 ;
F_9 ( V_38 >= V_32 ) ;
F_298 ( V_15 , V_38 , V_32 ) ;
F_259 ( & V_15 -> V_16 -> V_132 -> V_251 ) ;
F_8 ( & V_243 -> V_235 ) ;
for (; V_38 < V_32 ; V_38 += F_80 ( V_37 ) ) {
V_225 = F_223 ( V_243 , V_38 ) ;
if ( ! V_225 )
continue;
if ( F_243 ( V_243 , & V_38 , V_225 ) ) {
V_277 ++ ;
continue;
}
if ( ! F_226 ( F_219 ( V_225 ) ) ) {
V_237 = F_245 ( V_243 , V_38 , V_225 ) ;
V_237 = F_216 ( F_299 ( V_237 , V_289 ) ) ;
V_237 = F_217 ( V_237 , V_15 , NULL , 0 ) ;
F_231 ( V_243 , V_38 , V_225 , V_237 ) ;
V_277 ++ ;
}
}
F_2 ( & V_243 -> V_235 ) ;
F_300 ( V_15 , V_218 , V_32 ) ;
F_261 ( & V_15 -> V_16 -> V_132 -> V_251 ) ;
return V_277 << V_37 -> V_42 ;
}
int F_301 ( struct V_12 * V_12 ,
long V_28 , long V_27 ,
struct V_14 * V_15 ,
T_14 V_51 )
{
long V_10 , V_30 ;
struct V_36 * V_37 = F_302 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( V_51 & V_57 )
return 0 ;
if ( ! V_15 || V_15 -> V_51 & V_52 )
V_30 = F_19 ( & V_12 -> V_135 -> V_136 , V_28 , V_27 ) ;
else {
struct V_46 * V_46 = F_38 () ;
if ( ! V_46 )
return - V_11 ;
V_30 = V_27 - V_28 ;
F_44 ( V_15 , V_46 ) ;
F_45 ( V_15 , V_59 ) ;
}
if ( V_30 < 0 ) {
V_10 = V_30 ;
goto V_290;
}
if ( F_10 ( V_2 , V_30 ) ) {
V_10 = - V_140 ;
goto V_290;
}
V_10 = F_203 ( V_37 , V_30 ) ;
if ( V_10 < 0 ) {
F_11 ( V_2 , V_30 ) ;
goto V_290;
}
if ( ! V_15 || V_15 -> V_51 & V_52 )
F_15 ( & V_12 -> V_135 -> V_136 , V_28 , V_27 ) ;
return 0 ;
V_290:
if ( V_15 )
F_206 ( V_15 ) ;
return V_10 ;
}
void F_303 ( struct V_12 * V_12 , long V_291 , long V_292 )
{
struct V_36 * V_37 = F_302 ( V_12 ) ;
long V_30 = F_22 ( & V_12 -> V_135 -> V_136 , V_291 ) ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_8 ( & V_12 -> V_264 ) ;
V_12 -> V_265 -= ( F_285 ( V_37 ) * V_292 ) ;
F_2 ( & V_12 -> V_264 ) ;
F_11 ( V_2 , ( V_30 - V_292 ) ) ;
F_203 ( V_37 , - ( V_30 - V_292 ) ) ;
}
static int F_304 ( struct V_60 * V_293 )
{
struct V_60 * V_60 ;
struct V_60 * V_122 ;
struct V_36 * V_37 = F_51 ( V_293 ) ;
int V_67 = F_60 ( V_293 ) ;
F_17 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_60 == V_293 )
return 1 ;
return 0 ;
}
int F_305 ( struct V_60 * V_293 )
{
struct V_36 * V_37 = F_51 ( V_293 ) ;
int V_67 = F_60 ( V_293 ) ;
int V_10 = - V_294 ;
F_8 ( & V_98 ) ;
if ( F_304 ( V_293 ) ) {
F_306 ( & V_293 -> V_68 ) ;
F_64 ( V_293 ) ;
V_37 -> V_70 -- ;
V_37 -> V_71 [ V_67 ] -- ;
V_10 = 0 ;
}
F_2 ( & V_98 ) ;
return V_10 ;
}
