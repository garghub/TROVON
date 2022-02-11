static long F_1 ( struct V_1 * V_2 , long V_3 , long V_4 )
{
struct V_5 * V_6 , * V_7 , * V_8 ;
F_2 (rg, head, link)
if ( V_3 <= V_6 -> V_9 )
break;
if ( V_3 > V_6 -> V_10 )
V_3 = V_6 -> V_10 ;
V_7 = V_6 ;
F_3 (rg, trg, rg->link.prev, link) {
if ( & V_6 -> V_11 == V_2 )
break;
if ( V_6 -> V_10 > V_4 )
break;
if ( V_6 -> V_9 > V_4 )
V_4 = V_6 -> V_9 ;
if ( V_6 != V_7 ) {
F_4 ( & V_6 -> V_11 ) ;
F_5 ( V_6 ) ;
}
}
V_7 -> V_10 = V_3 ;
V_7 -> V_9 = V_4 ;
return 0 ;
}
static long F_6 ( struct V_1 * V_2 , long V_3 , long V_4 )
{
struct V_5 * V_6 , * V_7 ;
long V_12 = 0 ;
F_2 (rg, head, link)
if ( V_3 <= V_6 -> V_9 )
break;
if ( & V_6 -> V_11 == V_2 || V_4 < V_6 -> V_10 ) {
V_7 = F_7 ( sizeof( * V_7 ) , V_13 ) ;
if ( ! V_7 )
return - V_14 ;
V_7 -> V_10 = V_3 ;
V_7 -> V_9 = V_3 ;
F_8 ( & V_7 -> V_11 ) ;
F_9 ( & V_7 -> V_11 , V_6 -> V_11 . V_15 ) ;
return V_4 - V_3 ;
}
if ( V_3 > V_6 -> V_10 )
V_3 = V_6 -> V_10 ;
V_12 = V_4 - V_3 ;
F_2 (rg, rg->link.prev, link) {
if ( & V_6 -> V_11 == V_2 )
break;
if ( V_6 -> V_10 > V_4 )
return V_12 ;
if ( V_6 -> V_9 > V_4 ) {
V_12 += V_6 -> V_9 - V_4 ;
V_4 = V_6 -> V_9 ;
}
V_12 -= V_6 -> V_9 - V_6 -> V_10 ;
}
return V_12 ;
}
static long F_10 ( struct V_1 * V_2 , long V_16 )
{
struct V_5 * V_6 , * V_8 ;
long V_12 = 0 ;
F_2 (rg, head, link)
if ( V_16 <= V_6 -> V_9 )
break;
if ( & V_6 -> V_11 == V_2 )
return 0 ;
if ( V_16 > V_6 -> V_10 ) {
V_12 = V_6 -> V_9 - V_16 ;
V_6 -> V_9 = V_16 ;
V_6 = F_11 ( V_6 -> V_11 . V_17 , F_12 ( * V_6 ) , V_11 ) ;
}
F_3 (rg, trg, rg->link.prev, link) {
if ( & V_6 -> V_11 == V_2 )
break;
V_12 += V_6 -> V_9 - V_6 -> V_10 ;
F_4 ( & V_6 -> V_11 ) ;
F_5 ( V_6 ) ;
}
return V_12 ;
}
static long F_13 ( struct V_1 * V_2 , long V_3 , long V_4 )
{
struct V_5 * V_6 ;
long V_12 = 0 ;
F_2 (rg, head, link) {
int V_18 ;
int V_19 ;
if ( V_6 -> V_9 <= V_3 )
continue;
if ( V_6 -> V_10 >= V_4 )
break;
V_18 = F_14 ( V_6 -> V_10 , V_3 ) ;
V_19 = F_15 ( V_6 -> V_9 , V_4 ) ;
V_12 += V_19 - V_18 ;
}
return V_12 ;
}
static T_1 F_16 ( struct V_20 * V_21 ,
struct V_22 * V_23 , unsigned long V_24 )
{
return ( ( V_24 - V_23 -> V_25 ) >> F_17 ( V_21 ) ) +
( V_23 -> V_26 >> F_18 ( V_21 ) ) ;
}
T_1 F_19 ( struct V_22 * V_23 ,
unsigned long V_24 )
{
return F_16 ( F_20 ( V_23 ) , V_23 , V_24 ) ;
}
unsigned long F_21 ( struct V_22 * V_23 )
{
struct V_20 * V_20 ;
if ( ! F_22 ( V_23 ) )
return V_27 ;
V_20 = F_20 ( V_23 ) ;
return 1UL << ( V_20 -> V_28 + V_29 ) ;
}
unsigned long F_23 ( struct V_22 * V_23 )
{
return F_21 ( V_23 ) ;
}
static unsigned long F_24 ( struct V_22 * V_23 )
{
return ( unsigned long ) V_23 -> V_30 ;
}
static void F_25 ( struct V_22 * V_23 ,
unsigned long V_31 )
{
V_23 -> V_30 = ( void * ) V_31 ;
}
static struct V_32 * F_26 ( void )
{
struct V_32 * V_32 = F_7 ( sizeof( * V_32 ) , V_13 ) ;
if ( ! V_32 )
return NULL ;
F_27 ( & V_32 -> V_33 ) ;
F_8 ( & V_32 -> V_34 ) ;
return V_32 ;
}
static void F_28 ( struct V_35 * V_36 )
{
struct V_32 * V_32 = F_29 ( V_36 , struct V_32 , V_33 ) ;
F_10 ( & V_32 -> V_34 , 0 ) ;
F_5 ( V_32 ) ;
}
static struct V_32 * F_30 ( struct V_22 * V_23 )
{
F_31 ( ! F_22 ( V_23 ) ) ;
if ( ! ( V_23 -> V_37 & V_38 ) )
return (struct V_32 * ) ( F_24 ( V_23 ) &
~ V_39 ) ;
return NULL ;
}
static void F_32 ( struct V_22 * V_23 , struct V_32 * V_40 )
{
F_31 ( ! F_22 ( V_23 ) ) ;
F_31 ( V_23 -> V_37 & V_38 ) ;
F_25 ( V_23 , ( F_24 ( V_23 ) &
V_39 ) | ( unsigned long ) V_40 ) ;
}
static void F_33 ( struct V_22 * V_23 , unsigned long V_41 )
{
F_31 ( ! F_22 ( V_23 ) ) ;
F_31 ( V_23 -> V_37 & V_38 ) ;
F_25 ( V_23 , F_24 ( V_23 ) | V_41 ) ;
}
static int F_34 ( struct V_22 * V_23 , unsigned long V_42 )
{
F_31 ( ! F_22 ( V_23 ) ) ;
return ( F_24 ( V_23 ) & V_42 ) != 0 ;
}
static void F_35 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_37 & V_43 )
return;
if ( V_23 -> V_37 & V_38 ) {
V_21 -> V_44 -- ;
} else if ( F_34 ( V_23 , V_45 ) ) {
V_21 -> V_44 -- ;
}
}
void F_36 ( struct V_22 * V_23 )
{
F_31 ( ! F_22 ( V_23 ) ) ;
if ( ! ( V_23 -> V_37 & V_38 ) )
V_23 -> V_30 = ( void * ) 0 ;
}
static int F_37 ( struct V_22 * V_23 )
{
if ( V_23 -> V_37 & V_38 )
return 1 ;
if ( F_34 ( V_23 , V_45 ) )
return 1 ;
return 0 ;
}
static void F_38 ( struct V_46 * V_47 , struct V_46 * V_48 )
{
int V_49 ;
struct V_20 * V_21 = F_39 ( V_48 ) ;
struct V_46 * V_50 = V_47 ;
struct V_46 * V_51 = V_48 ;
for ( V_49 = 0 ; V_49 < F_40 ( V_21 ) ; ) {
F_41 () ;
F_42 ( V_47 , V_48 ) ;
V_49 ++ ;
V_47 = F_43 ( V_47 , V_50 , V_49 ) ;
V_48 = F_43 ( V_48 , V_51 , V_49 ) ;
}
}
void F_44 ( struct V_46 * V_47 , struct V_46 * V_48 )
{
int V_49 ;
struct V_20 * V_21 = F_39 ( V_48 ) ;
if ( F_45 ( F_40 ( V_21 ) > V_52 ) ) {
F_38 ( V_47 , V_48 ) ;
return;
}
F_46 () ;
for ( V_49 = 0 ; V_49 < F_40 ( V_21 ) ; V_49 ++ ) {
F_41 () ;
F_42 ( V_47 + V_49 , V_48 + V_49 ) ;
}
}
static void F_47 ( struct V_20 * V_21 , struct V_46 * V_46 )
{
int V_53 = F_48 ( V_46 ) ;
F_9 ( & V_46 -> V_54 , & V_21 -> V_55 [ V_53 ] ) ;
V_21 -> V_56 ++ ;
V_21 -> V_57 [ V_53 ] ++ ;
}
static struct V_46 * F_49 ( struct V_20 * V_21 , int V_53 )
{
struct V_46 * V_46 ;
if ( F_50 ( & V_21 -> V_55 [ V_53 ] ) )
return NULL ;
V_46 = F_11 ( V_21 -> V_55 [ V_53 ] . V_17 , struct V_46 , V_54 ) ;
F_4 ( & V_46 -> V_54 ) ;
F_51 ( V_46 ) ;
V_21 -> V_56 -- ;
V_21 -> V_57 [ V_53 ] -- ;
return V_46 ;
}
static struct V_46 * F_52 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
unsigned long V_24 , int V_58 )
{
struct V_46 * V_46 = NULL ;
struct V_59 * V_60 ;
T_2 * V_61 ;
struct V_62 * V_62 ;
struct V_63 * V_63 ;
struct V_64 * V_65 ;
F_53 () ;
V_62 = F_54 ( V_23 , V_24 ,
V_66 , & V_60 , & V_61 ) ;
if ( ! F_37 ( V_23 ) &&
V_21 -> V_56 - V_21 -> V_44 == 0 )
goto V_67;
if ( V_58 && V_21 -> V_56 - V_21 -> V_44 == 0 )
goto V_67;
F_55 (zone, z, zonelist,
MAX_NR_ZONES - 1 , nodemask) {
if ( F_56 ( V_63 , V_66 ) ) {
V_46 = F_49 ( V_21 , F_57 ( V_63 ) ) ;
if ( V_46 ) {
if ( ! V_58 )
F_35 ( V_21 , V_23 ) ;
break;
}
}
}
V_67:
F_58 ( V_60 ) ;
F_59 () ;
return V_46 ;
}
static void F_60 ( struct V_20 * V_21 , struct V_46 * V_46 )
{
int V_49 ;
F_31 ( V_21 -> V_28 >= V_68 ) ;
V_21 -> V_69 -- ;
V_21 -> V_70 [ F_48 ( V_46 ) ] -- ;
for ( V_49 = 0 ; V_49 < F_40 ( V_21 ) ; V_49 ++ ) {
V_46 [ V_49 ] . V_41 &= ~ ( 1 << V_71 | 1 << V_72 |
1 << V_73 | 1 << V_74 |
1 << V_75 | 1 << V_76 |
1 << V_77 | 1 << V_78 ) ;
}
F_61 ( V_46 , NULL ) ;
F_51 ( V_46 ) ;
F_62 ( V_46 ) ;
F_63 ( V_46 , F_18 ( V_21 ) ) ;
}
struct V_20 * F_64 ( unsigned long V_79 )
{
struct V_20 * V_21 ;
F_65 (h) {
if ( F_66 ( V_21 ) == V_79 )
return V_21 ;
}
return NULL ;
}
static void F_67 ( struct V_46 * V_46 )
{
struct V_20 * V_21 = F_39 ( V_46 ) ;
int V_53 = F_48 ( V_46 ) ;
struct V_80 * V_81 ;
V_81 = (struct V_80 * ) F_68 ( V_46 ) ;
F_69 ( V_46 , 0 ) ;
V_46 -> V_81 = NULL ;
F_70 ( F_71 ( V_46 ) ) ;
F_70 ( F_72 ( V_46 ) ) ;
F_8 ( & V_46 -> V_54 ) ;
F_73 ( & V_82 ) ;
if ( V_21 -> V_83 [ V_53 ] && F_18 ( V_21 ) < V_68 ) {
F_60 ( V_21 , V_46 ) ;
V_21 -> V_84 -- ;
V_21 -> V_83 [ V_53 ] -- ;
} else {
F_47 ( V_21 , V_46 ) ;
}
F_74 ( & V_82 ) ;
if ( V_81 )
F_75 ( V_81 , 1 ) ;
}
static void F_76 ( struct V_20 * V_21 , struct V_46 * V_46 , int V_53 )
{
F_61 ( V_46 , F_67 ) ;
F_73 ( & V_82 ) ;
V_21 -> V_69 ++ ;
V_21 -> V_70 [ V_53 ] ++ ;
F_74 ( & V_82 ) ;
F_77 ( V_46 ) ;
}
static void F_78 ( struct V_46 * V_46 , unsigned long V_28 )
{
int V_49 ;
int V_85 = 1 << V_28 ;
struct V_46 * V_86 = V_46 + 1 ;
F_79 ( V_46 , V_28 ) ;
F_80 ( V_46 ) ;
for ( V_49 = 1 ; V_49 < V_85 ; V_49 ++ , V_86 = F_43 ( V_86 , V_46 , V_49 ) ) {
F_81 ( V_86 ) ;
F_82 ( V_86 , 0 ) ;
V_86 -> V_87 = V_46 ;
}
}
int F_83 ( struct V_46 * V_46 )
{
T_3 * V_88 ;
if ( ! F_84 ( V_46 ) )
return 0 ;
V_46 = F_85 ( V_46 ) ;
V_88 = F_86 ( V_46 ) ;
return V_88 == F_67 ;
}
static struct V_46 * F_87 ( struct V_20 * V_21 , int V_53 )
{
struct V_46 * V_46 ;
if ( V_21 -> V_28 >= V_68 )
return NULL ;
V_46 = F_88 ( V_53 ,
V_66 | V_89 | V_90 |
V_91 | V_92 ,
F_18 ( V_21 ) ) ;
if ( V_46 ) {
if ( F_89 ( V_46 ) ) {
F_63 ( V_46 , F_18 ( V_21 ) ) ;
return NULL ;
}
F_76 ( V_21 , V_46 , V_53 ) ;
}
return V_46 ;
}
static int F_90 ( int V_53 , T_2 * V_93 )
{
V_53 = F_91 ( V_53 , * V_93 ) ;
if ( V_53 == V_94 )
V_53 = F_92 ( * V_93 ) ;
F_31 ( V_53 >= V_94 ) ;
return V_53 ;
}
static int F_93 ( int V_53 , T_2 * V_93 )
{
if ( ! F_94 ( V_53 , * V_93 ) )
V_53 = F_90 ( V_53 , V_93 ) ;
return V_53 ;
}
static int F_95 ( struct V_20 * V_21 ,
T_2 * V_93 )
{
int V_53 ;
F_31 ( ! V_93 ) ;
V_53 = F_93 ( V_21 -> V_95 , V_93 ) ;
V_21 -> V_95 = F_90 ( V_53 , V_93 ) ;
return V_53 ;
}
static int F_96 ( struct V_20 * V_21 , T_2 * V_93 )
{
struct V_46 * V_46 ;
int V_96 ;
int V_97 ;
int V_98 = 0 ;
V_96 = F_95 ( V_21 , V_93 ) ;
V_97 = V_96 ;
do {
V_46 = F_87 ( V_21 , V_97 ) ;
if ( V_46 ) {
V_98 = 1 ;
break;
}
V_97 = F_95 ( V_21 , V_93 ) ;
} while ( V_97 != V_96 );
if ( V_98 )
F_97 ( V_99 ) ;
else
F_97 ( V_100 ) ;
return V_98 ;
}
static int F_98 ( struct V_20 * V_21 , T_2 * V_93 )
{
int V_53 ;
F_31 ( ! V_93 ) ;
V_53 = F_93 ( V_21 -> V_101 , V_93 ) ;
V_21 -> V_101 = F_90 ( V_53 , V_93 ) ;
return V_53 ;
}
static int F_99 ( struct V_20 * V_21 , T_2 * V_93 ,
bool V_102 )
{
int V_96 ;
int V_97 ;
int V_98 = 0 ;
V_96 = F_98 ( V_21 , V_93 ) ;
V_97 = V_96 ;
do {
if ( ( ! V_102 || V_21 -> V_83 [ V_97 ] ) &&
! F_50 ( & V_21 -> V_55 [ V_97 ] ) ) {
struct V_46 * V_46 =
F_11 ( V_21 -> V_55 [ V_97 ] . V_17 ,
struct V_46 , V_54 ) ;
F_4 ( & V_46 -> V_54 ) ;
V_21 -> V_56 -- ;
V_21 -> V_57 [ V_97 ] -- ;
if ( V_102 ) {
V_21 -> V_84 -- ;
V_21 -> V_83 [ V_97 ] -- ;
}
F_60 ( V_21 , V_46 ) ;
V_98 = 1 ;
break;
}
V_97 = F_98 ( V_21 , V_93 ) ;
} while ( V_97 != V_96 );
return V_98 ;
}
static struct V_46 * F_100 ( struct V_20 * V_21 , int V_53 )
{
struct V_46 * V_46 ;
unsigned int V_103 ;
if ( V_21 -> V_28 >= V_68 )
return NULL ;
F_73 ( & V_82 ) ;
if ( V_21 -> V_84 >= V_21 -> V_104 ) {
F_74 ( & V_82 ) ;
return NULL ;
} else {
V_21 -> V_69 ++ ;
V_21 -> V_84 ++ ;
}
F_74 ( & V_82 ) ;
if ( V_53 == V_105 )
V_46 = F_101 ( V_66 | V_89 |
V_91 | V_92 ,
F_18 ( V_21 ) ) ;
else
V_46 = F_88 ( V_53 ,
V_66 | V_89 | V_90 |
V_91 | V_92 , F_18 ( V_21 ) ) ;
if ( V_46 && F_89 ( V_46 ) ) {
F_63 ( V_46 , F_18 ( V_21 ) ) ;
return NULL ;
}
F_73 ( & V_82 ) ;
if ( V_46 ) {
V_103 = F_48 ( V_46 ) ;
F_61 ( V_46 , F_67 ) ;
V_21 -> V_70 [ V_103 ] ++ ;
V_21 -> V_83 [ V_103 ] ++ ;
F_102 ( V_99 ) ;
} else {
V_21 -> V_69 -- ;
V_21 -> V_84 -- ;
F_102 ( V_100 ) ;
}
F_74 ( & V_82 ) ;
return V_46 ;
}
struct V_46 * F_103 ( struct V_20 * V_21 , int V_53 )
{
struct V_46 * V_46 ;
F_73 ( & V_82 ) ;
V_46 = F_49 ( V_21 , V_53 ) ;
F_74 ( & V_82 ) ;
if ( ! V_46 )
V_46 = F_100 ( V_21 , V_53 ) ;
return V_46 ;
}
static int F_104 ( struct V_20 * V_21 , int V_106 )
{
struct V_1 V_107 ;
struct V_46 * V_46 , * V_108 ;
int V_98 , V_49 ;
int V_109 , V_110 ;
V_109 = ( V_21 -> V_44 + V_106 ) - V_21 -> V_56 ;
if ( V_109 <= 0 ) {
V_21 -> V_44 += V_106 ;
return 0 ;
}
V_110 = 0 ;
F_8 ( & V_107 ) ;
V_98 = - V_14 ;
V_111:
F_74 ( & V_82 ) ;
for ( V_49 = 0 ; V_49 < V_109 ; V_49 ++ ) {
V_46 = F_100 ( V_21 , V_105 ) ;
if ( ! V_46 )
goto free;
F_9 ( & V_46 -> V_54 , & V_107 ) ;
}
V_110 += V_109 ;
F_73 ( & V_82 ) ;
V_109 = ( V_21 -> V_44 + V_106 ) -
( V_21 -> V_56 + V_110 ) ;
if ( V_109 > 0 )
goto V_111;
V_109 += V_110 ;
V_21 -> V_44 += V_106 ;
V_98 = 0 ;
F_3 (page, tmp, &surplus_list, lru) {
if ( ( -- V_109 ) < 0 )
break;
F_4 ( & V_46 -> V_54 ) ;
F_105 ( V_46 ) ;
F_31 ( F_71 ( V_46 ) ) ;
F_47 ( V_21 , V_46 ) ;
}
F_74 ( & V_82 ) ;
free:
if ( ! F_50 ( & V_107 ) ) {
F_3 (page, tmp, &surplus_list, lru) {
F_4 ( & V_46 -> V_54 ) ;
F_77 ( V_46 ) ;
}
}
F_73 ( & V_82 ) ;
return V_98 ;
}
static void F_106 ( struct V_20 * V_21 ,
unsigned long V_112 )
{
unsigned long V_85 ;
V_21 -> V_44 -= V_112 ;
if ( V_21 -> V_28 >= V_68 )
return;
V_85 = F_15 ( V_112 , V_21 -> V_84 ) ;
while ( V_85 -- ) {
if ( ! F_99 ( V_21 , & V_113 [ V_114 ] , 1 ) )
break;
}
}
static long F_107 ( struct V_20 * V_21 ,
struct V_22 * V_23 , unsigned long V_115 )
{
struct V_80 * V_81 = V_23 -> V_116 -> V_117 ;
struct V_118 * V_118 = V_81 -> V_119 ;
if ( V_23 -> V_37 & V_38 ) {
T_1 V_120 = F_16 ( V_21 , V_23 , V_115 ) ;
return F_6 ( & V_118 -> V_121 -> V_122 ,
V_120 , V_120 + 1 ) ;
} else if ( ! F_34 ( V_23 , V_45 ) ) {
return 1 ;
} else {
long V_67 ;
T_1 V_120 = F_16 ( V_21 , V_23 , V_115 ) ;
struct V_32 * V_123 = F_30 ( V_23 ) ;
V_67 = F_6 ( & V_123 -> V_34 , V_120 , V_120 + 1 ) ;
if ( V_67 < 0 )
return V_67 ;
return 0 ;
}
}
static void F_108 ( struct V_20 * V_21 ,
struct V_22 * V_23 , unsigned long V_115 )
{
struct V_80 * V_81 = V_23 -> V_116 -> V_117 ;
struct V_118 * V_118 = V_81 -> V_119 ;
if ( V_23 -> V_37 & V_38 ) {
T_1 V_120 = F_16 ( V_21 , V_23 , V_115 ) ;
F_1 ( & V_118 -> V_121 -> V_122 , V_120 , V_120 + 1 ) ;
} else if ( F_34 ( V_23 , V_45 ) ) {
T_1 V_120 = F_16 ( V_21 , V_23 , V_115 ) ;
struct V_32 * V_123 = F_30 ( V_23 ) ;
F_1 ( & V_123 -> V_34 , V_120 , V_120 + 1 ) ;
}
}
static struct V_46 * F_109 ( struct V_22 * V_23 ,
unsigned long V_115 , int V_58 )
{
struct V_20 * V_21 = F_20 ( V_23 ) ;
struct V_46 * V_46 ;
struct V_80 * V_81 = V_23 -> V_116 -> V_117 ;
struct V_118 * V_118 = V_81 -> V_119 ;
long V_12 ;
V_12 = F_107 ( V_21 , V_23 , V_115 ) ;
if ( V_12 < 0 )
return F_110 ( - V_124 ) ;
if ( V_12 )
if ( F_111 ( V_118 -> V_121 , V_12 ) )
return F_110 ( - V_125 ) ;
F_73 ( & V_82 ) ;
V_46 = F_52 ( V_21 , V_23 , V_115 , V_58 ) ;
F_74 ( & V_82 ) ;
if ( ! V_46 ) {
V_46 = F_100 ( V_21 , V_105 ) ;
if ( ! V_46 ) {
F_75 ( V_118 -> V_121 , V_12 ) ;
return F_110 ( - V_125 ) ;
}
}
F_69 ( V_46 , ( unsigned long ) V_81 ) ;
F_108 ( V_21 , V_23 , V_115 ) ;
return V_46 ;
}
int __weak F_112 ( struct V_20 * V_21 )
{
struct V_126 * V_127 ;
int V_128 = F_113 ( V_113 [ V_114 ] ) ;
while ( V_128 ) {
void * V_115 ;
V_115 = F_114 (
F_115 ( F_95 ( V_21 ,
& V_113 [ V_114 ] ) ) ,
F_66 ( V_21 ) , F_66 ( V_21 ) , 0 ) ;
if ( V_115 ) {
V_127 = V_115 ;
goto V_129;
}
V_128 -- ;
}
return 0 ;
V_129:
F_70 ( ( unsigned long ) F_116 ( V_127 ) & ( F_66 ( V_21 ) - 1 ) ) ;
F_9 ( & V_127 -> V_130 , & V_131 ) ;
V_127 -> V_20 = V_21 ;
return 1 ;
}
static void F_117 ( struct V_46 * V_46 , int V_28 )
{
if ( F_45 ( V_28 > ( V_68 - 1 ) ) )
F_78 ( V_46 , V_28 ) ;
else
F_118 ( V_46 , V_28 ) ;
}
static void T_4 F_119 ( void )
{
struct V_126 * V_127 ;
F_2 (m, &huge_boot_pages, list) {
struct V_20 * V_21 = V_127 -> V_20 ;
struct V_46 * V_46 ;
#ifdef F_120
V_46 = F_121 ( V_127 -> V_132 >> V_29 ) ;
F_122 ( ( unsigned long ) V_127 ,
sizeof( struct V_126 ) ) ;
#else
V_46 = F_123 ( V_127 ) ;
#endif
F_124 ( V_46 ) ;
F_125 ( F_71 ( V_46 ) != 1 ) ;
F_117 ( V_46 , V_21 -> V_28 ) ;
F_76 ( V_21 , V_46 , F_48 ( V_46 ) ) ;
if ( V_21 -> V_28 > ( V_68 - 1 ) )
V_133 += 1 << V_21 -> V_28 ;
}
}
static void T_4 F_126 ( struct V_20 * V_21 )
{
unsigned long V_49 ;
for ( V_49 = 0 ; V_49 < V_21 -> V_134 ; ++ V_49 ) {
if ( V_21 -> V_28 >= V_68 ) {
if ( ! F_112 ( V_21 ) )
break;
} else if ( ! F_96 ( V_21 ,
& V_113 [ V_114 ] ) )
break;
}
V_21 -> V_134 = V_49 ;
}
static void T_4 F_127 ( void )
{
struct V_20 * V_21 ;
F_65 (h) {
if ( V_21 -> V_28 < V_68 )
F_126 ( V_21 ) ;
}
}
static char * T_4 F_128 ( char * V_135 , unsigned long V_136 )
{
if ( V_136 >= ( 1UL << 30 ) )
sprintf ( V_135 , L_1 , V_136 >> 30 ) ;
else if ( V_136 >= ( 1UL << 20 ) )
sprintf ( V_135 , L_2 , V_136 >> 20 ) ;
else
sprintf ( V_135 , L_3 , V_136 >> 10 ) ;
return V_135 ;
}
static void T_4 F_129 ( void )
{
struct V_20 * V_21 ;
F_65 (h) {
char V_135 [ 32 ] ;
F_130 ( V_137 L_4
L_5 ,
F_128 ( V_135 , F_66 ( V_21 ) ) ,
V_21 -> V_56 ) ;
}
}
static void F_131 ( struct V_20 * V_21 , unsigned long V_138 ,
T_2 * V_93 )
{
int V_49 ;
if ( V_21 -> V_28 >= V_68 )
return;
F_132 (i, *nodes_allowed) {
struct V_46 * V_46 , * V_17 ;
struct V_1 * V_139 = & V_21 -> V_55 [ V_49 ] ;
F_3 (page, next, freel, lru) {
if ( V_138 >= V_21 -> V_69 )
return;
if ( F_133 ( V_46 ) )
continue;
F_4 ( & V_46 -> V_54 ) ;
F_60 ( V_21 , V_46 ) ;
V_21 -> V_56 -- ;
V_21 -> V_57 [ F_48 ( V_46 ) ] -- ;
}
}
}
static inline void F_131 ( struct V_20 * V_21 , unsigned long V_138 ,
T_2 * V_93 )
{
}
static int F_134 ( struct V_20 * V_21 , T_2 * V_93 ,
int V_106 )
{
int V_96 , V_97 ;
int V_98 = 0 ;
F_31 ( V_106 != - 1 && V_106 != 1 ) ;
if ( V_106 < 0 )
V_96 = F_95 ( V_21 , V_93 ) ;
else
V_96 = F_98 ( V_21 , V_93 ) ;
V_97 = V_96 ;
do {
int V_53 = V_97 ;
if ( V_106 < 0 ) {
if ( ! V_21 -> V_83 [ V_53 ] ) {
V_97 = F_95 ( V_21 ,
V_93 ) ;
continue;
}
}
if ( V_106 > 0 ) {
if ( V_21 -> V_83 [ V_53 ] >=
V_21 -> V_70 [ V_53 ] ) {
V_97 = F_98 ( V_21 ,
V_93 ) ;
continue;
}
}
V_21 -> V_84 += V_106 ;
V_21 -> V_83 [ V_53 ] += V_106 ;
V_98 = 1 ;
break;
} while ( V_97 != V_96 );
return V_98 ;
}
static unsigned long F_135 ( struct V_20 * V_21 , unsigned long V_138 ,
T_2 * V_93 )
{
unsigned long V_140 , V_98 ;
if ( V_21 -> V_28 >= V_68 )
return V_21 -> V_134 ;
F_73 ( & V_82 ) ;
while ( V_21 -> V_84 && V_138 > F_136 ( V_21 ) ) {
if ( ! F_134 ( V_21 , V_93 , - 1 ) )
break;
}
while ( V_138 > F_136 ( V_21 ) ) {
F_74 ( & V_82 ) ;
V_98 = F_96 ( V_21 , V_93 ) ;
F_73 ( & V_82 ) ;
if ( ! V_98 )
goto V_141;
if ( F_137 ( V_142 ) )
goto V_141;
}
V_140 = V_21 -> V_44 + V_21 -> V_69 - V_21 -> V_56 ;
V_140 = F_14 ( V_138 , V_140 ) ;
F_131 ( V_21 , V_140 , V_93 ) ;
while ( V_140 < F_136 ( V_21 ) ) {
if ( ! F_99 ( V_21 , V_93 , 0 ) )
break;
}
while ( V_138 < F_136 ( V_21 ) ) {
if ( ! F_134 ( V_21 , V_93 , 1 ) )
break;
}
V_141:
V_98 = F_136 ( V_21 ) ;
F_74 ( & V_82 ) ;
return V_98 ;
}
static struct V_20 * F_138 ( struct V_143 * V_144 , int * V_145 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_146 ; V_49 ++ )
if ( V_147 [ V_49 ] == V_144 ) {
if ( V_145 )
* V_145 = V_105 ;
return & V_148 [ V_49 ] ;
}
return F_139 ( V_144 , V_145 ) ;
}
static T_5 F_140 ( struct V_143 * V_144 ,
struct V_149 * V_150 , char * V_135 )
{
struct V_20 * V_21 ;
unsigned long V_69 ;
int V_53 ;
V_21 = F_138 ( V_144 , & V_53 ) ;
if ( V_53 == V_105 )
V_69 = V_21 -> V_69 ;
else
V_69 = V_21 -> V_70 [ V_53 ] ;
return sprintf ( V_135 , L_6 , V_69 ) ;
}
static T_5 F_141 ( bool V_151 ,
struct V_143 * V_144 , struct V_149 * V_150 ,
const char * V_135 , T_6 V_152 )
{
int V_67 ;
int V_53 ;
unsigned long V_138 ;
struct V_20 * V_21 ;
F_142 ( T_2 , V_93 , V_13 | V_153 ) ;
V_67 = F_143 ( V_135 , 10 , & V_138 ) ;
if ( V_67 )
goto V_141;
V_21 = F_138 ( V_144 , & V_53 ) ;
if ( V_21 -> V_28 >= V_68 ) {
V_67 = - V_154 ;
goto V_141;
}
if ( V_53 == V_105 ) {
if ( ! ( V_151 &&
F_144 ( V_93 ) ) ) {
F_145 ( V_93 ) ;
V_93 = & V_113 [ V_114 ] ;
}
} else if ( V_93 ) {
V_138 += V_21 -> V_69 - V_21 -> V_70 [ V_53 ] ;
F_146 ( V_93 , V_53 ) ;
} else
V_93 = & V_113 [ V_114 ] ;
V_21 -> V_134 = F_135 ( V_21 , V_138 , V_93 ) ;
if ( V_93 != & V_113 [ V_114 ] )
F_145 ( V_93 ) ;
return V_152 ;
V_141:
F_145 ( V_93 ) ;
return V_67 ;
}
static T_5 F_147 ( struct V_143 * V_144 ,
struct V_149 * V_150 , char * V_135 )
{
return F_140 ( V_144 , V_150 , V_135 ) ;
}
static T_5 F_148 ( struct V_143 * V_144 ,
struct V_149 * V_150 , const char * V_135 , T_6 V_152 )
{
return F_141 ( false , V_144 , V_150 , V_135 , V_152 ) ;
}
static T_5 F_149 ( struct V_143 * V_144 ,
struct V_149 * V_150 , char * V_135 )
{
return F_140 ( V_144 , V_150 , V_135 ) ;
}
static T_5 F_150 ( struct V_143 * V_144 ,
struct V_149 * V_150 , const char * V_135 , T_6 V_152 )
{
return F_141 ( true , V_144 , V_150 , V_135 , V_152 ) ;
}
static T_5 F_151 ( struct V_143 * V_144 ,
struct V_149 * V_150 , char * V_135 )
{
struct V_20 * V_21 = F_138 ( V_144 , NULL ) ;
return sprintf ( V_135 , L_6 , V_21 -> V_104 ) ;
}
static T_5 F_152 ( struct V_143 * V_144 ,
struct V_149 * V_150 , const char * V_135 , T_6 V_138 )
{
int V_67 ;
unsigned long V_155 ;
struct V_20 * V_21 = F_138 ( V_144 , NULL ) ;
if ( V_21 -> V_28 >= V_68 )
return - V_154 ;
V_67 = F_143 ( V_135 , 10 , & V_155 ) ;
if ( V_67 )
return V_67 ;
F_73 ( & V_82 ) ;
V_21 -> V_104 = V_155 ;
F_74 ( & V_82 ) ;
return V_138 ;
}
static T_5 F_153 ( struct V_143 * V_144 ,
struct V_149 * V_150 , char * V_135 )
{
struct V_20 * V_21 ;
unsigned long V_56 ;
int V_53 ;
V_21 = F_138 ( V_144 , & V_53 ) ;
if ( V_53 == V_105 )
V_56 = V_21 -> V_56 ;
else
V_56 = V_21 -> V_57 [ V_53 ] ;
return sprintf ( V_135 , L_6 , V_56 ) ;
}
static T_5 F_154 ( struct V_143 * V_144 ,
struct V_149 * V_150 , char * V_135 )
{
struct V_20 * V_21 = F_138 ( V_144 , NULL ) ;
return sprintf ( V_135 , L_6 , V_21 -> V_44 ) ;
}
static T_5 F_155 ( struct V_143 * V_144 ,
struct V_149 * V_150 , char * V_135 )
{
struct V_20 * V_21 ;
unsigned long V_84 ;
int V_53 ;
V_21 = F_138 ( V_144 , & V_53 ) ;
if ( V_53 == V_105 )
V_84 = V_21 -> V_84 ;
else
V_84 = V_21 -> V_83 [ V_53 ] ;
return sprintf ( V_135 , L_6 , V_84 ) ;
}
static int F_156 ( struct V_20 * V_21 , struct V_143 * V_156 ,
struct V_143 * * V_147 ,
struct V_157 * V_158 )
{
int V_159 ;
int V_160 = V_21 - V_148 ;
V_147 [ V_160 ] = F_157 ( V_21 -> V_161 , V_156 ) ;
if ( ! V_147 [ V_160 ] )
return - V_14 ;
V_159 = F_158 ( V_147 [ V_160 ] , V_158 ) ;
if ( V_159 )
F_159 ( V_147 [ V_160 ] ) ;
return V_159 ;
}
static void T_4 F_160 ( void )
{
struct V_20 * V_21 ;
int V_67 ;
V_162 = F_157 ( L_7 , V_163 ) ;
if ( ! V_162 )
return;
F_65 (h) {
V_67 = F_156 ( V_21 , V_162 ,
V_147 , & V_158 ) ;
if ( V_67 )
F_130 ( V_164 L_8 ,
V_21 -> V_161 ) ;
}
}
static struct V_20 * F_139 ( struct V_143 * V_144 , int * V_145 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_165 ; V_53 ++ ) {
struct V_166 * V_167 = & V_168 [ V_53 ] ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_146 ; V_49 ++ )
if ( V_167 -> V_147 [ V_49 ] == V_144 ) {
if ( V_145 )
* V_145 = V_53 ;
return & V_148 [ V_49 ] ;
}
}
F_161 () ;
return NULL ;
}
void F_162 ( struct V_169 * V_169 )
{
struct V_20 * V_21 ;
struct V_166 * V_167 = & V_168 [ V_169 -> V_170 . V_171 ] ;
if ( ! V_167 -> V_162 )
return;
F_65 (h)
if ( V_167 -> V_147 [ V_21 - V_148 ] ) {
F_159 ( V_167 -> V_147 [ V_21 - V_148 ] ) ;
V_167 -> V_147 [ V_21 - V_148 ] = NULL ;
}
F_159 ( V_167 -> V_162 ) ;
V_167 -> V_162 = NULL ;
}
static void F_163 ( void )
{
int V_53 ;
F_164 ( NULL , NULL ) ;
for ( V_53 = 0 ; V_53 < V_165 ; V_53 ++ )
F_162 ( & V_172 [ V_53 ] ) ;
}
void F_165 ( struct V_169 * V_169 )
{
struct V_20 * V_21 ;
struct V_166 * V_167 = & V_168 [ V_169 -> V_170 . V_171 ] ;
int V_67 ;
if ( V_167 -> V_162 )
return;
V_167 -> V_162 = F_157 ( L_7 ,
& V_169 -> V_170 . V_144 ) ;
if ( ! V_167 -> V_162 )
return;
F_65 (h) {
V_67 = F_156 ( V_21 , V_167 -> V_162 ,
V_167 -> V_147 ,
& V_173 ) ;
if ( V_67 ) {
F_130 ( V_164 L_8
L_9 ,
V_21 -> V_161 , V_169 -> V_170 . V_171 ) ;
F_162 ( V_169 ) ;
break;
}
}
}
static void F_166 ( void )
{
int V_53 ;
F_167 (nid, N_HIGH_MEMORY) {
struct V_169 * V_169 = & V_172 [ V_53 ] ;
if ( V_169 -> V_170 . V_171 == V_53 )
F_165 ( V_169 ) ;
}
F_164 ( F_165 ,
F_162 ) ;
}
static struct V_20 * F_139 ( struct V_143 * V_144 , int * V_145 )
{
F_161 () ;
if ( V_145 )
* V_145 = - 1 ;
return NULL ;
}
static void F_163 ( void ) { }
static void F_166 ( void ) { }
static void T_7 F_168 ( void )
{
struct V_20 * V_21 ;
F_163 () ;
F_65 (h) {
F_159 ( V_147 [ V_21 - V_148 ] ) ;
}
F_159 ( V_162 ) ;
}
static int T_4 F_169 ( void )
{
if ( V_174 == 0 )
return 0 ;
if ( ! F_64 ( V_175 ) ) {
V_175 = V_176 ;
if ( ! F_64 ( V_175 ) )
F_170 ( V_177 ) ;
}
V_178 = F_64 ( V_175 ) - V_148 ;
if ( V_179 )
V_180 . V_134 = V_179 ;
F_127 () ;
F_119 () ;
F_129 () ;
F_160 () ;
F_166 () ;
return 0 ;
}
void T_4 F_170 ( unsigned V_28 )
{
struct V_20 * V_21 ;
unsigned long V_49 ;
if ( F_64 ( V_27 << V_28 ) ) {
F_130 ( V_181 L_10 ) ;
return;
}
F_70 ( V_182 >= V_146 ) ;
F_70 ( V_28 == 0 ) ;
V_21 = & V_148 [ V_182 ++ ] ;
V_21 -> V_28 = V_28 ;
V_21 -> V_183 = ~ ( ( 1ULL << ( V_28 + V_29 ) ) - 1 ) ;
V_21 -> V_69 = 0 ;
V_21 -> V_56 = 0 ;
for ( V_49 = 0 ; V_49 < V_94 ; ++ V_49 )
F_8 ( & V_21 -> V_55 [ V_49 ] ) ;
V_21 -> V_95 = F_92 ( V_113 [ V_114 ] ) ;
V_21 -> V_101 = F_92 ( V_113 [ V_114 ] ) ;
snprintf ( V_21 -> V_161 , V_184 , L_11 ,
F_66 ( V_21 ) / 1024 ) ;
V_185 = V_21 ;
}
static int T_4 F_171 ( char * V_186 )
{
unsigned long * V_187 ;
static unsigned long * V_188 ;
if ( ! V_182 )
V_187 = & V_179 ;
else
V_187 = & V_185 -> V_134 ;
if ( V_187 == V_188 ) {
F_130 ( V_181 L_12
L_13 ) ;
return 1 ;
}
if ( sscanf ( V_186 , L_14 , V_187 ) <= 0 )
* V_187 = 0 ;
if ( V_182 && V_185 -> V_28 >= V_68 )
F_126 ( V_185 ) ;
V_188 = V_187 ;
return 1 ;
}
static int T_4 F_172 ( char * V_186 )
{
V_175 = F_173 ( V_186 , & V_186 ) ;
return 1 ;
}
static unsigned int F_174 ( unsigned int * V_189 )
{
int V_169 ;
unsigned int V_190 = 0 ;
F_132 (node, cpuset_current_mems_allowed)
V_190 += V_189 [ V_169 ] ;
return V_190 ;
}
static int F_175 ( bool V_151 ,
struct V_191 * V_192 , int V_193 ,
void T_8 * V_194 , T_6 * V_195 , T_9 * V_196 )
{
struct V_20 * V_21 = & V_180 ;
unsigned long V_108 ;
int V_98 ;
V_108 = V_21 -> V_134 ;
if ( V_193 && V_21 -> V_28 >= V_68 )
return - V_154 ;
V_192 -> V_197 = & V_108 ;
V_192 -> V_198 = sizeof( unsigned long ) ;
V_98 = F_176 ( V_192 , V_193 , V_194 , V_195 , V_196 ) ;
if ( V_98 )
goto V_141;
if ( V_193 ) {
F_142 ( T_2 , V_93 ,
V_13 | V_153 ) ;
if ( ! ( V_151 &&
F_144 ( V_93 ) ) ) {
F_145 ( V_93 ) ;
V_93 = & V_113 [ V_114 ] ;
}
V_21 -> V_134 = F_135 ( V_21 , V_108 , V_93 ) ;
if ( V_93 != & V_113 [ V_114 ] )
F_145 ( V_93 ) ;
}
V_141:
return V_98 ;
}
int F_177 ( struct V_191 * V_192 , int V_193 ,
void T_8 * V_194 , T_6 * V_195 , T_9 * V_196 )
{
return F_175 ( false , V_192 , V_193 ,
V_194 , V_195 , V_196 ) ;
}
int F_178 ( struct V_191 * V_192 , int V_193 ,
void T_8 * V_194 , T_6 * V_195 , T_9 * V_196 )
{
return F_175 ( true , V_192 , V_193 ,
V_194 , V_195 , V_196 ) ;
}
int F_179 ( struct V_191 * V_192 , int V_193 ,
void T_8 * V_194 ,
T_6 * V_195 , T_9 * V_196 )
{
F_180 ( V_192 , V_193 , V_194 , V_195 , V_196 ) ;
if ( V_199 )
V_66 = V_200 ;
else
V_66 = V_201 ;
return 0 ;
}
int F_181 ( struct V_191 * V_192 , int V_193 ,
void T_8 * V_194 ,
T_6 * V_195 , T_9 * V_196 )
{
struct V_20 * V_21 = & V_180 ;
unsigned long V_108 ;
int V_98 ;
V_108 = V_21 -> V_104 ;
if ( V_193 && V_21 -> V_28 >= V_68 )
return - V_154 ;
V_192 -> V_197 = & V_108 ;
V_192 -> V_198 = sizeof( unsigned long ) ;
V_98 = F_176 ( V_192 , V_193 , V_194 , V_195 , V_196 ) ;
if ( V_98 )
goto V_141;
if ( V_193 ) {
F_73 ( & V_82 ) ;
V_21 -> V_104 = V_108 ;
F_74 ( & V_82 ) ;
}
V_141:
return V_98 ;
}
void F_182 ( struct V_202 * V_127 )
{
struct V_20 * V_21 = & V_180 ;
F_183 ( V_127 ,
L_15
L_16
L_17
L_18
L_19 ,
V_21 -> V_69 ,
V_21 -> V_56 ,
V_21 -> V_44 ,
V_21 -> V_84 ,
1UL << ( F_18 ( V_21 ) + V_29 - 10 ) ) ;
}
int F_184 ( int V_53 , char * V_135 )
{
struct V_20 * V_21 = & V_180 ;
return sprintf ( V_135 ,
L_20
L_21
L_22 ,
V_53 , V_21 -> V_70 [ V_53 ] ,
V_53 , V_21 -> V_57 [ V_53 ] ,
V_53 , V_21 -> V_83 [ V_53 ] ) ;
}
unsigned long F_185 ( void )
{
struct V_20 * V_21 = & V_180 ;
return V_21 -> V_69 * F_40 ( V_21 ) ;
}
static int F_186 ( struct V_20 * V_21 , long V_106 )
{
int V_98 = - V_14 ;
F_73 ( & V_82 ) ;
if ( V_106 > 0 ) {
if ( F_104 ( V_21 , V_106 ) < 0 )
goto V_141;
if ( V_106 > F_174 ( V_21 -> V_57 ) ) {
F_106 ( V_21 , V_106 ) ;
goto V_141;
}
}
V_98 = 0 ;
if ( V_106 < 0 )
F_106 ( V_21 , ( unsigned long ) - V_106 ) ;
V_141:
F_74 ( & V_82 ) ;
return V_98 ;
}
static void F_187 ( struct V_22 * V_23 )
{
struct V_32 * V_123 = F_30 ( V_23 ) ;
if ( V_123 )
F_188 ( & V_123 -> V_33 ) ;
}
static void F_189 ( struct V_22 * V_23 )
{
struct V_20 * V_21 = F_20 ( V_23 ) ;
struct V_32 * V_123 = F_30 ( V_23 ) ;
unsigned long V_203 ;
unsigned long V_204 ;
unsigned long V_16 ;
if ( V_123 ) {
V_204 = F_16 ( V_21 , V_23 , V_23 -> V_25 ) ;
V_16 = F_16 ( V_21 , V_23 , V_23 -> V_205 ) ;
V_203 = ( V_16 - V_204 ) -
F_13 ( & V_123 -> V_34 , V_204 , V_16 ) ;
F_190 ( & V_123 -> V_33 , F_28 ) ;
if ( V_203 ) {
F_186 ( V_21 , - V_203 ) ;
F_75 ( V_23 -> V_116 -> V_117 , V_203 ) ;
}
}
}
static int F_191 ( struct V_22 * V_23 , struct V_206 * V_207 )
{
F_161 () ;
return 0 ;
}
static T_10 F_192 ( struct V_22 * V_23 , struct V_46 * V_46 ,
int V_208 )
{
T_10 V_209 ;
if ( V_208 ) {
V_209 =
F_193 ( F_194 ( F_195 ( V_46 , V_23 -> V_210 ) ) ) ;
} else {
V_209 = F_196 ( F_195 ( V_46 , V_23 -> V_210 ) ) ;
}
V_209 = F_197 ( V_209 ) ;
V_209 = F_198 ( V_209 ) ;
return V_209 ;
}
static void F_199 ( struct V_22 * V_23 ,
unsigned long V_24 , T_10 * V_211 )
{
T_10 V_209 ;
V_209 = F_193 ( F_194 ( F_200 ( V_211 ) ) ) ;
if ( F_201 ( V_23 , V_24 , V_211 , V_209 , 1 ) )
F_202 ( V_23 , V_24 , V_211 ) ;
}
int F_203 ( struct V_212 * V_47 , struct V_212 * V_48 ,
struct V_22 * V_23 )
{
T_10 * V_213 , * V_214 , V_209 ;
struct V_46 * V_215 ;
unsigned long V_115 ;
int V_216 ;
struct V_20 * V_21 = F_20 ( V_23 ) ;
unsigned long V_217 = F_66 ( V_21 ) ;
V_216 = ( V_23 -> V_37 & ( V_218 | V_219 ) ) == V_219 ;
for ( V_115 = V_23 -> V_25 ; V_115 < V_23 -> V_205 ; V_115 += V_217 ) {
V_213 = F_204 ( V_48 , V_115 ) ;
if ( ! V_213 )
continue;
V_214 = F_205 ( V_47 , V_115 , V_217 ) ;
if ( ! V_214 )
goto V_220;
if ( V_214 == V_213 )
continue;
F_73 ( & V_47 -> V_221 ) ;
F_206 ( & V_48 -> V_221 , V_222 ) ;
if ( ! F_207 ( F_200 ( V_213 ) ) ) {
if ( V_216 )
F_208 ( V_48 , V_115 , V_213 ) ;
V_209 = F_200 ( V_213 ) ;
V_215 = F_209 ( V_209 ) ;
F_210 ( V_215 ) ;
F_211 ( V_215 ) ;
F_212 ( V_47 , V_115 , V_214 , V_209 ) ;
}
F_74 ( & V_48 -> V_221 ) ;
F_74 ( & V_47 -> V_221 ) ;
}
return 0 ;
V_220:
return - V_14 ;
}
static int F_213 ( T_10 V_223 )
{
T_11 V_224 ;
if ( F_207 ( V_223 ) || F_214 ( V_223 ) )
return 0 ;
V_224 = F_215 ( V_223 ) ;
if ( F_216 ( V_224 ) && F_217 ( V_224 ) )
return 1 ;
else
return 0 ;
}
static int F_218 ( T_10 V_223 )
{
T_11 V_224 ;
if ( F_207 ( V_223 ) || F_214 ( V_223 ) )
return 0 ;
V_224 = F_215 ( V_223 ) ;
if ( F_216 ( V_224 ) && F_219 ( V_224 ) )
return 1 ;
else
return 0 ;
}
void F_220 ( struct V_22 * V_23 , unsigned long V_204 ,
unsigned long V_16 , struct V_46 * V_225 )
{
struct V_212 * V_226 = V_23 -> V_227 ;
unsigned long V_24 ;
T_10 * V_211 ;
T_10 V_223 ;
struct V_46 * V_46 ;
struct V_46 * V_108 ;
struct V_20 * V_21 = F_20 ( V_23 ) ;
unsigned long V_217 = F_66 ( V_21 ) ;
F_221 ( V_228 ) ;
F_125 ( ! F_22 ( V_23 ) ) ;
F_70 ( V_204 & ~ F_222 ( V_21 ) ) ;
F_70 ( V_16 & ~ F_222 ( V_21 ) ) ;
F_223 ( V_226 , V_204 , V_16 ) ;
F_73 ( & V_226 -> V_221 ) ;
for ( V_24 = V_204 ; V_24 < V_16 ; V_24 += V_217 ) {
V_211 = F_204 ( V_226 , V_24 ) ;
if ( ! V_211 )
continue;
if ( F_224 ( V_226 , & V_24 , V_211 ) )
continue;
if ( V_225 ) {
V_223 = F_200 ( V_211 ) ;
if ( F_207 ( V_223 ) )
continue;
V_46 = F_209 ( V_223 ) ;
if ( V_46 != V_225 )
continue;
F_33 ( V_23 , V_229 ) ;
}
V_223 = F_225 ( V_226 , V_24 , V_211 ) ;
if ( F_207 ( V_223 ) )
continue;
if ( F_45 ( F_218 ( V_223 ) ) )
continue;
V_46 = F_209 ( V_223 ) ;
if ( F_226 ( V_223 ) )
F_227 ( V_46 ) ;
F_9 ( & V_46 -> V_54 , & V_228 ) ;
}
F_74 ( & V_226 -> V_221 ) ;
F_228 ( V_23 , V_204 , V_16 ) ;
F_229 ( V_226 , V_204 , V_16 ) ;
F_3 (page, tmp, &page_list, lru) {
F_230 ( V_46 ) ;
F_4 ( & V_46 -> V_54 ) ;
F_77 ( V_46 ) ;
}
}
void F_231 ( struct V_22 * V_23 , unsigned long V_204 ,
unsigned long V_16 , struct V_46 * V_225 )
{
F_232 ( & V_23 -> V_116 -> V_117 -> V_230 ) ;
F_220 ( V_23 , V_204 , V_16 , V_225 ) ;
F_233 ( & V_23 -> V_116 -> V_117 -> V_230 ) ;
}
static int F_234 ( struct V_212 * V_226 , struct V_22 * V_23 ,
struct V_46 * V_46 , unsigned long V_24 )
{
struct V_20 * V_21 = F_20 ( V_23 ) ;
struct V_22 * V_231 ;
struct V_80 * V_81 ;
struct V_232 V_233 ;
T_1 V_234 ;
V_24 = V_24 & F_222 ( V_21 ) ;
V_234 = ( ( V_24 - V_23 -> V_25 ) >> V_29 )
+ ( V_23 -> V_26 >> V_29 ) ;
V_81 = (struct V_80 * ) F_68 ( V_46 ) ;
F_232 ( & V_81 -> V_230 ) ;
F_235 (iter_vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
if ( V_231 == V_23 )
continue;
if ( ! F_34 ( V_231 , V_45 ) )
F_220 ( V_231 ,
V_24 , V_24 + F_66 ( V_21 ) ,
V_46 ) ;
}
F_233 ( & V_81 -> V_230 ) ;
return 1 ;
}
static int F_236 ( struct V_212 * V_226 , struct V_22 * V_23 ,
unsigned long V_24 , T_10 * V_211 , T_10 V_223 ,
struct V_46 * V_235 )
{
struct V_20 * V_21 = F_20 ( V_23 ) ;
struct V_46 * V_236 , * V_237 ;
int V_238 ;
int V_239 = 0 ;
V_236 = F_209 ( V_223 ) ;
V_240:
V_238 = ( F_72 ( V_236 ) == 1 ) ;
if ( V_238 ) {
if ( F_237 ( V_236 ) )
F_238 ( V_236 , V_23 , V_24 ) ;
F_199 ( V_23 , V_24 , V_211 ) ;
return 0 ;
}
if ( ! ( V_23 -> V_37 & V_38 ) &&
F_34 ( V_23 , V_45 ) &&
V_236 != V_235 )
V_239 = 1 ;
F_239 ( V_236 ) ;
F_74 ( & V_226 -> V_221 ) ;
V_237 = F_109 ( V_23 , V_24 , V_239 ) ;
if ( F_240 ( V_237 ) ) {
F_241 ( V_236 ) ;
if ( V_239 ) {
F_70 ( F_207 ( V_223 ) ) ;
if ( F_234 ( V_226 , V_23 , V_236 , V_24 ) ) {
F_70 ( F_71 ( V_236 ) != 1 ) ;
F_70 ( F_207 ( V_223 ) ) ;
F_73 ( & V_226 -> V_221 ) ;
goto V_240;
}
F_242 ( 1 ) ;
}
F_73 ( & V_226 -> V_221 ) ;
return - F_243 ( V_237 ) ;
}
if ( F_45 ( F_244 ( V_23 ) ) ) {
F_241 ( V_237 ) ;
F_241 ( V_236 ) ;
F_73 ( & V_226 -> V_221 ) ;
return V_124 ;
}
F_245 ( V_237 , V_236 , V_24 , V_23 ,
F_40 ( V_21 ) ) ;
F_246 ( V_237 ) ;
F_73 ( & V_226 -> V_221 ) ;
V_211 = F_204 ( V_226 , V_24 & F_222 ( V_21 ) ) ;
if ( F_247 ( F_248 ( F_200 ( V_211 ) , V_223 ) ) ) {
F_223 ( V_226 ,
V_24 & F_222 ( V_21 ) ,
( V_24 & F_222 ( V_21 ) ) + F_66 ( V_21 ) ) ;
F_249 ( V_23 , V_24 , V_211 ) ;
F_212 ( V_226 , V_24 , V_211 ,
F_192 ( V_23 , V_237 , 1 ) ) ;
F_230 ( V_236 ) ;
F_250 ( V_237 , V_23 , V_24 ) ;
V_237 = V_236 ;
F_229 ( V_226 ,
V_24 & F_222 ( V_21 ) ,
( V_24 & F_222 ( V_21 ) ) + F_66 ( V_21 ) ) ;
}
F_241 ( V_237 ) ;
F_241 ( V_236 ) ;
return 0 ;
}
static struct V_46 * F_251 ( struct V_20 * V_21 ,
struct V_22 * V_23 , unsigned long V_24 )
{
struct V_80 * V_81 ;
T_1 V_120 ;
V_81 = V_23 -> V_116 -> V_117 ;
V_120 = F_16 ( V_21 , V_23 , V_24 ) ;
return F_252 ( V_81 , V_120 ) ;
}
static bool F_253 ( struct V_20 * V_21 ,
struct V_22 * V_23 , unsigned long V_24 )
{
struct V_80 * V_81 ;
T_1 V_120 ;
struct V_46 * V_46 ;
V_81 = V_23 -> V_116 -> V_117 ;
V_120 = F_16 ( V_21 , V_23 , V_24 ) ;
V_46 = F_254 ( V_81 , V_120 ) ;
if ( V_46 )
F_77 ( V_46 ) ;
return V_46 != NULL ;
}
static int F_255 ( struct V_212 * V_226 , struct V_22 * V_23 ,
unsigned long V_24 , T_10 * V_211 , unsigned int V_41 )
{
struct V_20 * V_21 = F_20 ( V_23 ) ;
int V_98 = V_125 ;
T_1 V_120 ;
unsigned long V_79 ;
struct V_46 * V_46 ;
struct V_80 * V_81 ;
T_10 V_241 ;
if ( F_34 ( V_23 , V_229 ) ) {
F_130 ( V_181
L_23 ,
V_142 -> V_242 ) ;
return V_98 ;
}
V_81 = V_23 -> V_116 -> V_117 ;
V_120 = F_16 ( V_21 , V_23 , V_24 ) ;
V_111:
V_46 = F_252 ( V_81 , V_120 ) ;
if ( ! V_46 ) {
V_79 = F_256 ( V_81 -> V_119 ) >> F_17 ( V_21 ) ;
if ( V_120 >= V_79 )
goto V_141;
V_46 = F_109 ( V_23 , V_24 , 0 ) ;
if ( F_240 ( V_46 ) ) {
V_98 = - F_243 ( V_46 ) ;
goto V_141;
}
F_257 ( V_46 , V_24 , F_40 ( V_21 ) ) ;
F_246 ( V_46 ) ;
if ( V_23 -> V_37 & V_38 ) {
int V_67 ;
struct V_118 * V_118 = V_81 -> V_119 ;
V_67 = F_258 ( V_46 , V_81 , V_120 , V_13 ) ;
if ( V_67 ) {
F_77 ( V_46 ) ;
if ( V_67 == - V_243 )
goto V_111;
goto V_141;
}
F_73 ( & V_118 -> V_244 ) ;
V_118 -> V_245 += F_259 ( V_21 ) ;
F_74 ( & V_118 -> V_244 ) ;
F_211 ( V_46 ) ;
} else {
F_260 ( V_46 ) ;
if ( F_45 ( F_244 ( V_23 ) ) ) {
V_98 = V_124 ;
goto V_246;
}
F_250 ( V_46 , V_23 , V_24 ) ;
}
} else {
if ( F_45 ( F_261 ( V_46 ) ) ) {
V_98 = V_247 |
F_262 ( V_21 - V_148 ) ;
goto V_246;
}
F_211 ( V_46 ) ;
}
if ( ( V_41 & V_248 ) && ! ( V_23 -> V_37 & V_218 ) )
if ( F_107 ( V_21 , V_23 , V_24 ) < 0 ) {
V_98 = V_124 ;
goto V_246;
}
F_73 ( & V_226 -> V_221 ) ;
V_79 = F_256 ( V_81 -> V_119 ) >> F_17 ( V_21 ) ;
if ( V_120 >= V_79 )
goto V_249;
V_98 = 0 ;
if ( ! F_207 ( F_200 ( V_211 ) ) )
goto V_249;
V_241 = F_192 ( V_23 , V_46 , ( ( V_23 -> V_37 & V_250 )
&& ( V_23 -> V_37 & V_218 ) ) ) ;
F_212 ( V_226 , V_24 , V_211 , V_241 ) ;
if ( ( V_41 & V_248 ) && ! ( V_23 -> V_37 & V_218 ) ) {
V_98 = F_236 ( V_226 , V_23 , V_24 , V_211 , V_241 , V_46 ) ;
}
F_74 ( & V_226 -> V_221 ) ;
F_263 ( V_46 ) ;
V_141:
return V_98 ;
V_249:
F_74 ( & V_226 -> V_221 ) ;
V_246:
F_263 ( V_46 ) ;
F_77 ( V_46 ) ;
goto V_141;
}
int F_264 ( struct V_212 * V_226 , struct V_22 * V_23 ,
unsigned long V_24 , unsigned int V_41 )
{
T_10 * V_211 ;
T_10 V_209 ;
int V_98 ;
struct V_46 * V_46 = NULL ;
struct V_46 * V_235 = NULL ;
static F_265 ( V_251 ) ;
struct V_20 * V_21 = F_20 ( V_23 ) ;
V_211 = F_204 ( V_226 , V_24 ) ;
if ( V_211 ) {
V_209 = F_200 ( V_211 ) ;
if ( F_45 ( F_213 ( V_209 ) ) ) {
F_266 ( V_226 , ( V_252 * ) V_211 , V_24 ) ;
return 0 ;
} else if ( F_45 ( F_218 ( V_209 ) ) )
return V_253 |
F_262 ( V_21 - V_148 ) ;
}
V_211 = F_205 ( V_226 , V_24 , F_66 ( V_21 ) ) ;
if ( ! V_211 )
return V_124 ;
F_232 ( & V_251 ) ;
V_209 = F_200 ( V_211 ) ;
if ( F_207 ( V_209 ) ) {
V_98 = F_255 ( V_226 , V_23 , V_24 , V_211 , V_41 ) ;
goto V_254;
}
V_98 = 0 ;
if ( ( V_41 & V_248 ) && ! F_267 ( V_209 ) ) {
if ( F_107 ( V_21 , V_23 , V_24 ) < 0 ) {
V_98 = V_124 ;
goto V_254;
}
if ( ! ( V_23 -> V_37 & V_38 ) )
V_235 = F_251 ( V_21 ,
V_23 , V_24 ) ;
}
V_46 = F_209 ( V_209 ) ;
if ( V_46 != V_235 )
F_260 ( V_46 ) ;
F_73 ( & V_226 -> V_221 ) ;
if ( F_45 ( ! F_248 ( V_209 , F_200 ( V_211 ) ) ) )
goto V_255;
if ( V_41 & V_248 ) {
if ( ! F_267 ( V_209 ) ) {
V_98 = F_236 ( V_226 , V_23 , V_24 , V_211 , V_209 ,
V_235 ) ;
goto V_255;
}
V_209 = F_194 ( V_209 ) ;
}
V_209 = F_197 ( V_209 ) ;
if ( F_201 ( V_23 , V_24 , V_211 , V_209 ,
V_41 & V_248 ) )
F_202 ( V_23 , V_24 , V_211 ) ;
V_255:
F_74 ( & V_226 -> V_221 ) ;
if ( V_235 ) {
F_263 ( V_235 ) ;
F_77 ( V_235 ) ;
}
if ( V_46 != V_235 )
F_263 ( V_46 ) ;
V_254:
F_233 ( & V_251 ) ;
return V_98 ;
}
struct V_46 *
F_268 ( struct V_212 * V_226 , unsigned long V_24 ,
T_12 * V_256 , int V_193 )
{
F_161 () ;
return NULL ;
}
int F_269 ( struct V_212 * V_226 , struct V_22 * V_23 ,
struct V_46 * * V_257 , struct V_22 * * V_258 ,
unsigned long * V_259 , int * V_195 , int V_49 ,
unsigned int V_41 )
{
unsigned long V_260 ;
unsigned long V_261 = * V_259 ;
int V_262 = * V_195 ;
struct V_20 * V_21 = F_20 ( V_23 ) ;
F_73 ( & V_226 -> V_221 ) ;
while ( V_261 < V_23 -> V_205 && V_262 ) {
T_10 * V_223 ;
int V_263 ;
struct V_46 * V_46 ;
V_223 = F_204 ( V_226 , V_261 & F_222 ( V_21 ) ) ;
V_263 = ! V_223 || F_207 ( F_200 ( V_223 ) ) ;
if ( V_263 && ( V_41 & V_264 ) &&
! F_253 ( V_21 , V_23 , V_261 ) ) {
V_262 = 0 ;
break;
}
if ( V_263 ||
( ( V_41 & V_265 ) && ! F_267 ( F_200 ( V_223 ) ) ) ) {
int V_98 ;
F_74 ( & V_226 -> V_221 ) ;
V_98 = F_264 ( V_226 , V_23 , V_261 ,
( V_41 & V_265 ) ? V_248 : 0 ) ;
F_73 ( & V_226 -> V_221 ) ;
if ( ! ( V_98 & V_266 ) )
continue;
V_262 = 0 ;
break;
}
V_260 = ( V_261 & ~ F_222 ( V_21 ) ) >> V_29 ;
V_46 = F_209 ( F_200 ( V_223 ) ) ;
V_267:
if ( V_257 ) {
V_257 [ V_49 ] = F_270 ( V_46 , V_260 ) ;
F_210 ( V_257 [ V_49 ] ) ;
}
if ( V_258 )
V_258 [ V_49 ] = V_23 ;
V_261 += V_27 ;
++ V_260 ;
-- V_262 ;
++ V_49 ;
if ( V_261 < V_23 -> V_205 && V_262 &&
V_260 < F_40 ( V_21 ) ) {
goto V_267;
}
}
F_74 ( & V_226 -> V_221 ) ;
* V_195 = V_262 ;
* V_259 = V_261 ;
return V_49 ? V_49 : - V_268 ;
}
void F_271 ( struct V_22 * V_23 ,
unsigned long V_24 , unsigned long V_16 , T_13 V_269 )
{
struct V_212 * V_226 = V_23 -> V_227 ;
unsigned long V_204 = V_24 ;
T_10 * V_211 ;
T_10 V_223 ;
struct V_20 * V_21 = F_20 ( V_23 ) ;
F_70 ( V_24 >= V_16 ) ;
F_272 ( V_23 , V_24 , V_16 ) ;
F_232 ( & V_23 -> V_116 -> V_117 -> V_230 ) ;
F_73 ( & V_226 -> V_221 ) ;
for (; V_24 < V_16 ; V_24 += F_66 ( V_21 ) ) {
V_211 = F_204 ( V_226 , V_24 ) ;
if ( ! V_211 )
continue;
if ( F_224 ( V_226 , & V_24 , V_211 ) )
continue;
if ( ! F_207 ( F_200 ( V_211 ) ) ) {
V_223 = F_225 ( V_226 , V_24 , V_211 ) ;
V_223 = F_198 ( F_273 ( V_223 , V_269 ) ) ;
F_212 ( V_226 , V_24 , V_211 , V_223 ) ;
}
}
F_74 ( & V_226 -> V_221 ) ;
F_233 ( & V_23 -> V_116 -> V_117 -> V_230 ) ;
F_228 ( V_23 , V_204 , V_16 ) ;
}
int F_274 ( struct V_118 * V_118 ,
long V_10 , long V_9 ,
struct V_22 * V_23 ,
T_14 V_37 )
{
long V_98 , V_12 ;
struct V_20 * V_21 = F_275 ( V_118 ) ;
if ( V_37 & V_43 )
return 0 ;
if ( ! V_23 || V_23 -> V_37 & V_38 )
V_12 = F_6 ( & V_118 -> V_121 -> V_122 , V_10 , V_9 ) ;
else {
struct V_32 * V_32 = F_26 () ;
if ( ! V_32 )
return - V_14 ;
V_12 = V_9 - V_10 ;
F_32 ( V_23 , V_32 ) ;
F_33 ( V_23 , V_45 ) ;
}
if ( V_12 < 0 )
return V_12 ;
if ( F_111 ( V_118 -> V_121 , V_12 ) )
return - V_270 ;
V_98 = F_186 ( V_21 , V_12 ) ;
if ( V_98 < 0 ) {
F_75 ( V_118 -> V_121 , V_12 ) ;
return V_98 ;
}
if ( ! V_23 || V_23 -> V_37 & V_38 )
F_1 ( & V_118 -> V_121 -> V_122 , V_10 , V_9 ) ;
return 0 ;
}
void F_276 ( struct V_118 * V_118 , long V_271 , long V_272 )
{
struct V_20 * V_21 = F_275 ( V_118 ) ;
long V_12 = F_10 ( & V_118 -> V_121 -> V_122 , V_271 ) ;
F_73 ( & V_118 -> V_244 ) ;
V_118 -> V_245 -= ( F_259 ( V_21 ) * V_272 ) ;
F_74 ( & V_118 -> V_244 ) ;
F_75 ( V_118 -> V_121 , ( V_12 - V_272 ) ) ;
F_186 ( V_21 , - ( V_12 - V_272 ) ) ;
}
static int F_277 ( struct V_46 * V_273 )
{
struct V_46 * V_46 ;
struct V_46 * V_108 ;
struct V_20 * V_21 = F_39 ( V_273 ) ;
int V_53 = F_48 ( V_273 ) ;
F_3 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_46 == V_273 )
return 1 ;
return 0 ;
}
int F_278 ( struct V_46 * V_273 )
{
struct V_20 * V_21 = F_39 ( V_273 ) ;
int V_53 = F_48 ( V_273 ) ;
int V_98 = - V_274 ;
F_73 ( & V_82 ) ;
if ( F_277 ( V_273 ) ) {
F_4 ( & V_273 -> V_54 ) ;
F_51 ( V_273 ) ;
V_21 -> V_56 -- ;
V_21 -> V_57 [ V_53 ] -- ;
V_98 = 0 ;
}
F_74 ( & V_82 ) ;
return V_98 ;
}
