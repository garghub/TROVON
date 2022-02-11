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
V_46 [ V_49 ] . V_41 &= ~ ( 1 << V_71 | 1 << V_72 | 1 << V_73 |
1 << V_74 | 1 << V_75 | 1 << V_76 |
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
V_86 -> V_87 = V_46 ;
}
}
int F_82 ( struct V_46 * V_46 )
{
T_3 * V_88 ;
if ( ! F_83 ( V_46 ) )
return 0 ;
V_46 = F_84 ( V_46 ) ;
V_88 = F_85 ( V_46 ) ;
return V_88 == F_67 ;
}
static struct V_46 * F_86 ( struct V_20 * V_21 , int V_53 )
{
struct V_46 * V_46 ;
if ( V_21 -> V_28 >= V_68 )
return NULL ;
V_46 = F_87 ( V_53 ,
V_66 | V_89 | V_90 |
V_91 | V_92 ,
F_18 ( V_21 ) ) ;
if ( V_46 ) {
if ( F_88 ( V_46 ) ) {
F_63 ( V_46 , F_18 ( V_21 ) ) ;
return NULL ;
}
F_76 ( V_21 , V_46 , V_53 ) ;
}
return V_46 ;
}
static int F_89 ( int V_53 , T_2 * V_93 )
{
V_53 = F_90 ( V_53 , * V_93 ) ;
if ( V_53 == V_94 )
V_53 = F_91 ( * V_93 ) ;
F_31 ( V_53 >= V_94 ) ;
return V_53 ;
}
static int F_92 ( int V_53 , T_2 * V_93 )
{
if ( ! F_93 ( V_53 , * V_93 ) )
V_53 = F_89 ( V_53 , V_93 ) ;
return V_53 ;
}
static int F_94 ( struct V_20 * V_21 ,
T_2 * V_93 )
{
int V_53 ;
F_31 ( ! V_93 ) ;
V_53 = F_92 ( V_21 -> V_95 , V_93 ) ;
V_21 -> V_95 = F_89 ( V_53 , V_93 ) ;
return V_53 ;
}
static int F_95 ( struct V_20 * V_21 , T_2 * V_93 )
{
struct V_46 * V_46 ;
int V_96 ;
int V_97 ;
int V_98 = 0 ;
V_96 = F_94 ( V_21 , V_93 ) ;
V_97 = V_96 ;
do {
V_46 = F_86 ( V_21 , V_97 ) ;
if ( V_46 ) {
V_98 = 1 ;
break;
}
V_97 = F_94 ( V_21 , V_93 ) ;
} while ( V_97 != V_96 );
if ( V_98 )
F_96 ( V_99 ) ;
else
F_96 ( V_100 ) ;
return V_98 ;
}
static int F_97 ( struct V_20 * V_21 , T_2 * V_93 )
{
int V_53 ;
F_31 ( ! V_93 ) ;
V_53 = F_92 ( V_21 -> V_101 , V_93 ) ;
V_21 -> V_101 = F_89 ( V_53 , V_93 ) ;
return V_53 ;
}
static int F_98 ( struct V_20 * V_21 , T_2 * V_93 ,
bool V_102 )
{
int V_96 ;
int V_97 ;
int V_98 = 0 ;
V_96 = F_97 ( V_21 , V_93 ) ;
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
V_97 = F_97 ( V_21 , V_93 ) ;
} while ( V_97 != V_96 );
return V_98 ;
}
static struct V_46 * F_99 ( struct V_20 * V_21 , int V_53 )
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
V_46 = F_100 ( V_66 | V_89 |
V_91 | V_92 ,
F_18 ( V_21 ) ) ;
else
V_46 = F_87 ( V_53 ,
V_66 | V_89 | V_90 |
V_91 | V_92 , F_18 ( V_21 ) ) ;
if ( V_46 && F_88 ( V_46 ) ) {
F_63 ( V_46 , F_18 ( V_21 ) ) ;
return NULL ;
}
F_73 ( & V_82 ) ;
if ( V_46 ) {
V_103 = F_48 ( V_46 ) ;
F_61 ( V_46 , F_67 ) ;
V_21 -> V_70 [ V_103 ] ++ ;
V_21 -> V_83 [ V_103 ] ++ ;
F_101 ( V_99 ) ;
} else {
V_21 -> V_69 -- ;
V_21 -> V_84 -- ;
F_101 ( V_100 ) ;
}
F_74 ( & V_82 ) ;
return V_46 ;
}
struct V_46 * F_102 ( struct V_20 * V_21 , int V_53 )
{
struct V_46 * V_46 ;
F_73 ( & V_82 ) ;
V_46 = F_49 ( V_21 , V_53 ) ;
F_74 ( & V_82 ) ;
if ( ! V_46 )
V_46 = F_99 ( V_21 , V_53 ) ;
return V_46 ;
}
static int F_103 ( struct V_20 * V_21 , int V_106 )
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
V_46 = F_99 ( V_21 , V_105 ) ;
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
F_74 ( & V_82 ) ;
F_3 (page, tmp, &surplus_list, lru) {
if ( ( -- V_109 ) < 0 )
break;
F_4 ( & V_46 -> V_54 ) ;
F_104 ( V_46 ) ;
F_31 ( F_71 ( V_46 ) ) ;
F_47 ( V_21 , V_46 ) ;
}
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
static void F_105 ( struct V_20 * V_21 ,
unsigned long V_112 )
{
unsigned long V_85 ;
V_21 -> V_44 -= V_112 ;
if ( V_21 -> V_28 >= V_68 )
return;
V_85 = F_15 ( V_112 , V_21 -> V_84 ) ;
while ( V_85 -- ) {
if ( ! F_98 ( V_21 , & V_113 [ V_114 ] , 1 ) )
break;
}
}
static long F_106 ( struct V_20 * V_21 ,
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
static void F_107 ( struct V_20 * V_21 ,
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
static struct V_46 * F_108 ( struct V_22 * V_23 ,
unsigned long V_115 , int V_58 )
{
struct V_20 * V_21 = F_20 ( V_23 ) ;
struct V_46 * V_46 ;
struct V_80 * V_81 = V_23 -> V_116 -> V_117 ;
struct V_118 * V_118 = V_81 -> V_119 ;
long V_12 ;
V_12 = F_106 ( V_21 , V_23 , V_115 ) ;
if ( V_12 < 0 )
return F_109 ( - V_124 ) ;
if ( V_12 )
if ( F_110 ( V_118 -> V_121 , V_12 ) )
return F_109 ( - V_125 ) ;
F_73 ( & V_82 ) ;
V_46 = F_52 ( V_21 , V_23 , V_115 , V_58 ) ;
F_74 ( & V_82 ) ;
if ( ! V_46 ) {
V_46 = F_99 ( V_21 , V_105 ) ;
if ( ! V_46 ) {
F_75 ( V_118 -> V_121 , V_12 ) ;
return F_109 ( - V_125 ) ;
}
}
F_69 ( V_46 , ( unsigned long ) V_81 ) ;
F_107 ( V_21 , V_23 , V_115 ) ;
return V_46 ;
}
int __weak F_111 ( struct V_20 * V_21 )
{
struct V_126 * V_127 ;
int V_128 = F_112 ( V_113 [ V_114 ] ) ;
while ( V_128 ) {
void * V_115 ;
V_115 = F_113 (
F_114 ( F_94 ( V_21 ,
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
F_70 ( ( unsigned long ) F_115 ( V_127 ) & ( F_66 ( V_21 ) - 1 ) ) ;
F_9 ( & V_127 -> V_130 , & V_131 ) ;
V_127 -> V_20 = V_21 ;
return 1 ;
}
static void F_116 ( struct V_46 * V_46 , int V_28 )
{
if ( F_45 ( V_28 > ( V_68 - 1 ) ) )
F_78 ( V_46 , V_28 ) ;
else
F_117 ( V_46 , V_28 ) ;
}
static void T_4 F_118 ( void )
{
struct V_126 * V_127 ;
F_2 (m, &huge_boot_pages, list) {
struct V_46 * V_46 = F_119 ( V_127 ) ;
struct V_20 * V_21 = V_127 -> V_20 ;
F_120 ( V_46 ) ;
F_121 ( F_71 ( V_46 ) != 1 ) ;
F_116 ( V_46 , V_21 -> V_28 ) ;
F_76 ( V_21 , V_46 , F_48 ( V_46 ) ) ;
if ( V_21 -> V_28 > ( V_68 - 1 ) )
V_132 += 1 << V_21 -> V_28 ;
}
}
static void T_4 F_122 ( struct V_20 * V_21 )
{
unsigned long V_49 ;
for ( V_49 = 0 ; V_49 < V_21 -> V_133 ; ++ V_49 ) {
if ( V_21 -> V_28 >= V_68 ) {
if ( ! F_111 ( V_21 ) )
break;
} else if ( ! F_95 ( V_21 ,
& V_113 [ V_114 ] ) )
break;
}
V_21 -> V_133 = V_49 ;
}
static void T_4 F_123 ( void )
{
struct V_20 * V_21 ;
F_65 (h) {
if ( V_21 -> V_28 < V_68 )
F_122 ( V_21 ) ;
}
}
static char * T_4 F_124 ( char * V_134 , unsigned long V_135 )
{
if ( V_135 >= ( 1UL << 30 ) )
sprintf ( V_134 , L_1 , V_135 >> 30 ) ;
else if ( V_135 >= ( 1UL << 20 ) )
sprintf ( V_134 , L_2 , V_135 >> 20 ) ;
else
sprintf ( V_134 , L_3 , V_135 >> 10 ) ;
return V_134 ;
}
static void T_4 F_125 ( void )
{
struct V_20 * V_21 ;
F_65 (h) {
char V_134 [ 32 ] ;
F_126 ( V_136 L_4
L_5 ,
F_124 ( V_134 , F_66 ( V_21 ) ) ,
V_21 -> V_56 ) ;
}
}
static void F_127 ( struct V_20 * V_21 , unsigned long V_137 ,
T_2 * V_93 )
{
int V_49 ;
if ( V_21 -> V_28 >= V_68 )
return;
F_128 (i, *nodes_allowed) {
struct V_46 * V_46 , * V_17 ;
struct V_1 * V_138 = & V_21 -> V_55 [ V_49 ] ;
F_3 (page, next, freel, lru) {
if ( V_137 >= V_21 -> V_69 )
return;
if ( F_129 ( V_46 ) )
continue;
F_4 ( & V_46 -> V_54 ) ;
F_60 ( V_21 , V_46 ) ;
V_21 -> V_56 -- ;
V_21 -> V_57 [ F_48 ( V_46 ) ] -- ;
}
}
}
static inline void F_127 ( struct V_20 * V_21 , unsigned long V_137 ,
T_2 * V_93 )
{
}
static int F_130 ( struct V_20 * V_21 , T_2 * V_93 ,
int V_106 )
{
int V_96 , V_97 ;
int V_98 = 0 ;
F_31 ( V_106 != - 1 && V_106 != 1 ) ;
if ( V_106 < 0 )
V_96 = F_94 ( V_21 , V_93 ) ;
else
V_96 = F_97 ( V_21 , V_93 ) ;
V_97 = V_96 ;
do {
int V_53 = V_97 ;
if ( V_106 < 0 ) {
if ( ! V_21 -> V_83 [ V_53 ] ) {
V_97 = F_94 ( V_21 ,
V_93 ) ;
continue;
}
}
if ( V_106 > 0 ) {
if ( V_21 -> V_83 [ V_53 ] >=
V_21 -> V_70 [ V_53 ] ) {
V_97 = F_97 ( V_21 ,
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
static unsigned long F_131 ( struct V_20 * V_21 , unsigned long V_137 ,
T_2 * V_93 )
{
unsigned long V_139 , V_98 ;
if ( V_21 -> V_28 >= V_68 )
return V_21 -> V_133 ;
F_73 ( & V_82 ) ;
while ( V_21 -> V_84 && V_137 > F_132 ( V_21 ) ) {
if ( ! F_130 ( V_21 , V_93 , - 1 ) )
break;
}
while ( V_137 > F_132 ( V_21 ) ) {
F_74 ( & V_82 ) ;
V_98 = F_95 ( V_21 , V_93 ) ;
F_73 ( & V_82 ) ;
if ( ! V_98 )
goto V_140;
if ( F_133 ( V_141 ) )
goto V_140;
}
V_139 = V_21 -> V_44 + V_21 -> V_69 - V_21 -> V_56 ;
V_139 = F_14 ( V_137 , V_139 ) ;
F_127 ( V_21 , V_139 , V_93 ) ;
while ( V_139 < F_132 ( V_21 ) ) {
if ( ! F_98 ( V_21 , V_93 , 0 ) )
break;
}
while ( V_137 < F_132 ( V_21 ) ) {
if ( ! F_130 ( V_21 , V_93 , 1 ) )
break;
}
V_140:
V_98 = F_132 ( V_21 ) ;
F_74 ( & V_82 ) ;
return V_98 ;
}
static struct V_20 * F_134 ( struct V_142 * V_143 , int * V_144 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_145 ; V_49 ++ )
if ( V_146 [ V_49 ] == V_143 ) {
if ( V_144 )
* V_144 = V_105 ;
return & V_147 [ V_49 ] ;
}
return F_135 ( V_143 , V_144 ) ;
}
static T_5 F_136 ( struct V_142 * V_143 ,
struct V_148 * V_149 , char * V_134 )
{
struct V_20 * V_21 ;
unsigned long V_69 ;
int V_53 ;
V_21 = F_134 ( V_143 , & V_53 ) ;
if ( V_53 == V_105 )
V_69 = V_21 -> V_69 ;
else
V_69 = V_21 -> V_70 [ V_53 ] ;
return sprintf ( V_134 , L_6 , V_69 ) ;
}
static T_5 F_137 ( bool V_150 ,
struct V_142 * V_143 , struct V_148 * V_149 ,
const char * V_134 , T_6 V_151 )
{
int V_67 ;
int V_53 ;
unsigned long V_137 ;
struct V_20 * V_21 ;
F_138 ( T_2 , V_93 , V_13 | V_152 ) ;
V_67 = F_139 ( V_134 , 10 , & V_137 ) ;
if ( V_67 )
goto V_140;
V_21 = F_134 ( V_143 , & V_53 ) ;
if ( V_21 -> V_28 >= V_68 ) {
V_67 = - V_153 ;
goto V_140;
}
if ( V_53 == V_105 ) {
if ( ! ( V_150 &&
F_140 ( V_93 ) ) ) {
F_141 ( V_93 ) ;
V_93 = & V_113 [ V_114 ] ;
}
} else if ( V_93 ) {
V_137 += V_21 -> V_69 - V_21 -> V_70 [ V_53 ] ;
F_142 ( V_93 , V_53 ) ;
} else
V_93 = & V_113 [ V_114 ] ;
V_21 -> V_133 = F_131 ( V_21 , V_137 , V_93 ) ;
if ( V_93 != & V_113 [ V_114 ] )
F_141 ( V_93 ) ;
return V_151 ;
V_140:
F_141 ( V_93 ) ;
return V_67 ;
}
static T_5 F_143 ( struct V_142 * V_143 ,
struct V_148 * V_149 , char * V_134 )
{
return F_136 ( V_143 , V_149 , V_134 ) ;
}
static T_5 F_144 ( struct V_142 * V_143 ,
struct V_148 * V_149 , const char * V_134 , T_6 V_151 )
{
return F_137 ( false , V_143 , V_149 , V_134 , V_151 ) ;
}
static T_5 F_145 ( struct V_142 * V_143 ,
struct V_148 * V_149 , char * V_134 )
{
return F_136 ( V_143 , V_149 , V_134 ) ;
}
static T_5 F_146 ( struct V_142 * V_143 ,
struct V_148 * V_149 , const char * V_134 , T_6 V_151 )
{
return F_137 ( true , V_143 , V_149 , V_134 , V_151 ) ;
}
static T_5 F_147 ( struct V_142 * V_143 ,
struct V_148 * V_149 , char * V_134 )
{
struct V_20 * V_21 = F_134 ( V_143 , NULL ) ;
return sprintf ( V_134 , L_6 , V_21 -> V_104 ) ;
}
static T_5 F_148 ( struct V_142 * V_143 ,
struct V_148 * V_149 , const char * V_134 , T_6 V_137 )
{
int V_67 ;
unsigned long V_154 ;
struct V_20 * V_21 = F_134 ( V_143 , NULL ) ;
if ( V_21 -> V_28 >= V_68 )
return - V_153 ;
V_67 = F_139 ( V_134 , 10 , & V_154 ) ;
if ( V_67 )
return V_67 ;
F_73 ( & V_82 ) ;
V_21 -> V_104 = V_154 ;
F_74 ( & V_82 ) ;
return V_137 ;
}
static T_5 F_149 ( struct V_142 * V_143 ,
struct V_148 * V_149 , char * V_134 )
{
struct V_20 * V_21 ;
unsigned long V_56 ;
int V_53 ;
V_21 = F_134 ( V_143 , & V_53 ) ;
if ( V_53 == V_105 )
V_56 = V_21 -> V_56 ;
else
V_56 = V_21 -> V_57 [ V_53 ] ;
return sprintf ( V_134 , L_6 , V_56 ) ;
}
static T_5 F_150 ( struct V_142 * V_143 ,
struct V_148 * V_149 , char * V_134 )
{
struct V_20 * V_21 = F_134 ( V_143 , NULL ) ;
return sprintf ( V_134 , L_6 , V_21 -> V_44 ) ;
}
static T_5 F_151 ( struct V_142 * V_143 ,
struct V_148 * V_149 , char * V_134 )
{
struct V_20 * V_21 ;
unsigned long V_84 ;
int V_53 ;
V_21 = F_134 ( V_143 , & V_53 ) ;
if ( V_53 == V_105 )
V_84 = V_21 -> V_84 ;
else
V_84 = V_21 -> V_83 [ V_53 ] ;
return sprintf ( V_134 , L_6 , V_84 ) ;
}
static int F_152 ( struct V_20 * V_21 , struct V_142 * V_155 ,
struct V_142 * * V_146 ,
struct V_156 * V_157 )
{
int V_158 ;
int V_159 = V_21 - V_147 ;
V_146 [ V_159 ] = F_153 ( V_21 -> V_160 , V_155 ) ;
if ( ! V_146 [ V_159 ] )
return - V_14 ;
V_158 = F_154 ( V_146 [ V_159 ] , V_157 ) ;
if ( V_158 )
F_155 ( V_146 [ V_159 ] ) ;
return V_158 ;
}
static void T_4 F_156 ( void )
{
struct V_20 * V_21 ;
int V_67 ;
V_161 = F_153 ( L_7 , V_162 ) ;
if ( ! V_161 )
return;
F_65 (h) {
V_67 = F_152 ( V_21 , V_161 ,
V_146 , & V_157 ) ;
if ( V_67 )
F_126 ( V_163 L_8 ,
V_21 -> V_160 ) ;
}
}
static struct V_20 * F_135 ( struct V_142 * V_143 , int * V_144 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_164 ; V_53 ++ ) {
struct V_165 * V_166 = & V_167 [ V_53 ] ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_145 ; V_49 ++ )
if ( V_166 -> V_146 [ V_49 ] == V_143 ) {
if ( V_144 )
* V_144 = V_53 ;
return & V_147 [ V_49 ] ;
}
}
F_157 () ;
return NULL ;
}
void F_158 ( struct V_168 * V_168 )
{
struct V_20 * V_21 ;
struct V_165 * V_166 = & V_167 [ V_168 -> V_169 . V_170 ] ;
if ( ! V_166 -> V_161 )
return;
F_65 (h)
if ( V_166 -> V_146 [ V_21 - V_147 ] ) {
F_155 ( V_166 -> V_146 [ V_21 - V_147 ] ) ;
V_166 -> V_146 [ V_21 - V_147 ] = NULL ;
}
F_155 ( V_166 -> V_161 ) ;
V_166 -> V_161 = NULL ;
}
static void F_159 ( void )
{
int V_53 ;
F_160 ( NULL , NULL ) ;
for ( V_53 = 0 ; V_53 < V_164 ; V_53 ++ )
F_158 ( & V_171 [ V_53 ] ) ;
}
void F_161 ( struct V_168 * V_168 )
{
struct V_20 * V_21 ;
struct V_165 * V_166 = & V_167 [ V_168 -> V_169 . V_170 ] ;
int V_67 ;
if ( V_166 -> V_161 )
return;
V_166 -> V_161 = F_153 ( L_7 ,
& V_168 -> V_169 . V_143 ) ;
if ( ! V_166 -> V_161 )
return;
F_65 (h) {
V_67 = F_152 ( V_21 , V_166 -> V_161 ,
V_166 -> V_146 ,
& V_172 ) ;
if ( V_67 ) {
F_126 ( V_163 L_8
L_9 ,
V_21 -> V_160 , V_168 -> V_169 . V_170 ) ;
F_158 ( V_168 ) ;
break;
}
}
}
static void F_162 ( void )
{
int V_53 ;
F_163 (nid, N_HIGH_MEMORY) {
struct V_168 * V_168 = & V_171 [ V_53 ] ;
if ( V_168 -> V_169 . V_170 == V_53 )
F_161 ( V_168 ) ;
}
F_160 ( F_161 ,
F_158 ) ;
}
static struct V_20 * F_135 ( struct V_142 * V_143 , int * V_144 )
{
F_157 () ;
if ( V_144 )
* V_144 = - 1 ;
return NULL ;
}
static void F_159 ( void ) { }
static void F_162 ( void ) { }
static void T_7 F_164 ( void )
{
struct V_20 * V_21 ;
F_159 () ;
F_65 (h) {
F_155 ( V_146 [ V_21 - V_147 ] ) ;
}
F_155 ( V_161 ) ;
}
static int T_4 F_165 ( void )
{
if ( V_173 == 0 )
return 0 ;
if ( ! F_64 ( V_174 ) ) {
V_174 = V_175 ;
if ( ! F_64 ( V_174 ) )
F_166 ( V_176 ) ;
}
V_177 = F_64 ( V_174 ) - V_147 ;
if ( V_178 )
V_179 . V_133 = V_178 ;
F_123 () ;
F_118 () ;
F_125 () ;
F_156 () ;
F_162 () ;
return 0 ;
}
void T_4 F_166 ( unsigned V_28 )
{
struct V_20 * V_21 ;
unsigned long V_49 ;
if ( F_64 ( V_27 << V_28 ) ) {
F_126 ( V_180 L_10 ) ;
return;
}
F_70 ( V_181 >= V_145 ) ;
F_70 ( V_28 == 0 ) ;
V_21 = & V_147 [ V_181 ++ ] ;
V_21 -> V_28 = V_28 ;
V_21 -> V_182 = ~ ( ( 1ULL << ( V_28 + V_29 ) ) - 1 ) ;
V_21 -> V_69 = 0 ;
V_21 -> V_56 = 0 ;
for ( V_49 = 0 ; V_49 < V_94 ; ++ V_49 )
F_8 ( & V_21 -> V_55 [ V_49 ] ) ;
V_21 -> V_95 = F_91 ( V_113 [ V_114 ] ) ;
V_21 -> V_101 = F_91 ( V_113 [ V_114 ] ) ;
snprintf ( V_21 -> V_160 , V_183 , L_11 ,
F_66 ( V_21 ) / 1024 ) ;
V_184 = V_21 ;
}
static int T_4 F_167 ( char * V_185 )
{
unsigned long * V_186 ;
static unsigned long * V_187 ;
if ( ! V_181 )
V_186 = & V_178 ;
else
V_186 = & V_184 -> V_133 ;
if ( V_186 == V_187 ) {
F_126 ( V_180 L_12
L_13 ) ;
return 1 ;
}
if ( sscanf ( V_185 , L_14 , V_186 ) <= 0 )
* V_186 = 0 ;
if ( V_181 && V_184 -> V_28 >= V_68 )
F_122 ( V_184 ) ;
V_187 = V_186 ;
return 1 ;
}
static int T_4 F_168 ( char * V_185 )
{
V_174 = F_169 ( V_185 , & V_185 ) ;
return 1 ;
}
static unsigned int F_170 ( unsigned int * V_188 )
{
int V_168 ;
unsigned int V_189 = 0 ;
F_128 (node, cpuset_current_mems_allowed)
V_189 += V_188 [ V_168 ] ;
return V_189 ;
}
static int F_171 ( bool V_150 ,
struct V_190 * V_191 , int V_192 ,
void T_8 * V_193 , T_6 * V_194 , T_9 * V_195 )
{
struct V_20 * V_21 = & V_179 ;
unsigned long V_108 ;
int V_98 ;
V_108 = V_21 -> V_133 ;
if ( V_192 && V_21 -> V_28 >= V_68 )
return - V_153 ;
V_191 -> V_196 = & V_108 ;
V_191 -> V_197 = sizeof( unsigned long ) ;
V_98 = F_172 ( V_191 , V_192 , V_193 , V_194 , V_195 ) ;
if ( V_98 )
goto V_140;
if ( V_192 ) {
F_138 ( T_2 , V_93 ,
V_13 | V_152 ) ;
if ( ! ( V_150 &&
F_140 ( V_93 ) ) ) {
F_141 ( V_93 ) ;
V_93 = & V_113 [ V_114 ] ;
}
V_21 -> V_133 = F_131 ( V_21 , V_108 , V_93 ) ;
if ( V_93 != & V_113 [ V_114 ] )
F_141 ( V_93 ) ;
}
V_140:
return V_98 ;
}
int F_173 ( struct V_190 * V_191 , int V_192 ,
void T_8 * V_193 , T_6 * V_194 , T_9 * V_195 )
{
return F_171 ( false , V_191 , V_192 ,
V_193 , V_194 , V_195 ) ;
}
int F_174 ( struct V_190 * V_191 , int V_192 ,
void T_8 * V_193 , T_6 * V_194 , T_9 * V_195 )
{
return F_171 ( true , V_191 , V_192 ,
V_193 , V_194 , V_195 ) ;
}
int F_175 ( struct V_190 * V_191 , int V_192 ,
void T_8 * V_193 ,
T_6 * V_194 , T_9 * V_195 )
{
F_176 ( V_191 , V_192 , V_193 , V_194 , V_195 ) ;
if ( V_198 )
V_66 = V_199 ;
else
V_66 = V_200 ;
return 0 ;
}
int F_177 ( struct V_190 * V_191 , int V_192 ,
void T_8 * V_193 ,
T_6 * V_194 , T_9 * V_195 )
{
struct V_20 * V_21 = & V_179 ;
unsigned long V_108 ;
int V_98 ;
V_108 = V_21 -> V_104 ;
if ( V_192 && V_21 -> V_28 >= V_68 )
return - V_153 ;
V_191 -> V_196 = & V_108 ;
V_191 -> V_197 = sizeof( unsigned long ) ;
V_98 = F_172 ( V_191 , V_192 , V_193 , V_194 , V_195 ) ;
if ( V_98 )
goto V_140;
if ( V_192 ) {
F_73 ( & V_82 ) ;
V_21 -> V_104 = V_108 ;
F_74 ( & V_82 ) ;
}
V_140:
return V_98 ;
}
void F_178 ( struct V_201 * V_127 )
{
struct V_20 * V_21 = & V_179 ;
F_179 ( V_127 ,
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
int F_180 ( int V_53 , char * V_134 )
{
struct V_20 * V_21 = & V_179 ;
return sprintf ( V_134 ,
L_20
L_21
L_22 ,
V_53 , V_21 -> V_70 [ V_53 ] ,
V_53 , V_21 -> V_57 [ V_53 ] ,
V_53 , V_21 -> V_83 [ V_53 ] ) ;
}
unsigned long F_181 ( void )
{
struct V_20 * V_21 = & V_179 ;
return V_21 -> V_69 * F_40 ( V_21 ) ;
}
static int F_182 ( struct V_20 * V_21 , long V_106 )
{
int V_98 = - V_14 ;
F_73 ( & V_82 ) ;
if ( V_106 > 0 ) {
if ( F_103 ( V_21 , V_106 ) < 0 )
goto V_140;
if ( V_106 > F_170 ( V_21 -> V_57 ) ) {
F_105 ( V_21 , V_106 ) ;
goto V_140;
}
}
V_98 = 0 ;
if ( V_106 < 0 )
F_105 ( V_21 , ( unsigned long ) - V_106 ) ;
V_140:
F_74 ( & V_82 ) ;
return V_98 ;
}
static void F_183 ( struct V_22 * V_23 )
{
struct V_32 * V_123 = F_30 ( V_23 ) ;
if ( V_123 )
F_184 ( & V_123 -> V_33 ) ;
}
static void F_185 ( struct V_22 * V_23 )
{
struct V_20 * V_21 = F_20 ( V_23 ) ;
struct V_32 * V_123 = F_30 ( V_23 ) ;
unsigned long V_202 ;
unsigned long V_203 ;
unsigned long V_16 ;
if ( V_123 ) {
V_203 = F_16 ( V_21 , V_23 , V_23 -> V_25 ) ;
V_16 = F_16 ( V_21 , V_23 , V_23 -> V_204 ) ;
V_202 = ( V_16 - V_203 ) -
F_13 ( & V_123 -> V_34 , V_203 , V_16 ) ;
F_186 ( & V_123 -> V_33 , F_28 ) ;
if ( V_202 ) {
F_182 ( V_21 , - V_202 ) ;
F_75 ( V_23 -> V_116 -> V_117 , V_202 ) ;
}
}
}
static int F_187 ( struct V_22 * V_23 , struct V_205 * V_206 )
{
F_157 () ;
return 0 ;
}
static T_10 F_188 ( struct V_22 * V_23 , struct V_46 * V_46 ,
int V_207 )
{
T_10 V_208 ;
if ( V_207 ) {
V_208 =
F_189 ( F_190 ( F_191 ( V_46 , V_23 -> V_209 ) ) ) ;
} else {
V_208 = F_192 ( F_191 ( V_46 , V_23 -> V_209 ) ) ;
}
V_208 = F_193 ( V_208 ) ;
V_208 = F_194 ( V_208 ) ;
return V_208 ;
}
static void F_195 ( struct V_22 * V_23 ,
unsigned long V_24 , T_10 * V_210 )
{
T_10 V_208 ;
V_208 = F_189 ( F_190 ( F_196 ( V_210 ) ) ) ;
if ( F_197 ( V_23 , V_24 , V_210 , V_208 , 1 ) ) {
F_198 ( V_23 , V_24 , V_210 ) ;
}
}
int F_199 ( struct V_211 * V_47 , struct V_211 * V_48 ,
struct V_22 * V_23 )
{
T_10 * V_212 , * V_213 , V_208 ;
struct V_46 * V_214 ;
unsigned long V_115 ;
int V_215 ;
struct V_20 * V_21 = F_20 ( V_23 ) ;
unsigned long V_216 = F_66 ( V_21 ) ;
V_215 = ( V_23 -> V_37 & ( V_217 | V_218 ) ) == V_218 ;
for ( V_115 = V_23 -> V_25 ; V_115 < V_23 -> V_204 ; V_115 += V_216 ) {
V_212 = F_200 ( V_48 , V_115 ) ;
if ( ! V_212 )
continue;
V_213 = F_201 ( V_47 , V_115 , V_216 ) ;
if ( ! V_213 )
goto V_219;
if ( V_213 == V_212 )
continue;
F_73 ( & V_47 -> V_220 ) ;
F_202 ( & V_48 -> V_220 , V_221 ) ;
if ( ! F_203 ( F_196 ( V_212 ) ) ) {
if ( V_215 )
F_204 ( V_48 , V_115 , V_212 ) ;
V_208 = F_196 ( V_212 ) ;
V_214 = F_205 ( V_208 ) ;
F_206 ( V_214 ) ;
F_207 ( V_214 ) ;
F_208 ( V_47 , V_115 , V_213 , V_208 ) ;
}
F_74 ( & V_48 -> V_220 ) ;
F_74 ( & V_47 -> V_220 ) ;
}
return 0 ;
V_219:
return - V_14 ;
}
static int F_209 ( T_10 V_222 )
{
T_11 V_223 ;
if ( F_203 ( V_222 ) || F_210 ( V_222 ) )
return 0 ;
V_223 = F_211 ( V_222 ) ;
if ( F_212 ( V_223 ) && F_213 ( V_223 ) ) {
return 1 ;
} else
return 0 ;
}
static int F_214 ( T_10 V_222 )
{
T_11 V_223 ;
if ( F_203 ( V_222 ) || F_210 ( V_222 ) )
return 0 ;
V_223 = F_211 ( V_222 ) ;
if ( F_212 ( V_223 ) && F_215 ( V_223 ) ) {
return 1 ;
} else
return 0 ;
}
void F_216 ( struct V_22 * V_23 , unsigned long V_203 ,
unsigned long V_16 , struct V_46 * V_224 )
{
struct V_211 * V_225 = V_23 -> V_226 ;
unsigned long V_24 ;
T_10 * V_210 ;
T_10 V_222 ;
struct V_46 * V_46 ;
struct V_46 * V_108 ;
struct V_20 * V_21 = F_20 ( V_23 ) ;
unsigned long V_216 = F_66 ( V_21 ) ;
F_217 ( V_227 ) ;
F_121 ( ! F_22 ( V_23 ) ) ;
F_70 ( V_203 & ~ F_218 ( V_21 ) ) ;
F_70 ( V_16 & ~ F_218 ( V_21 ) ) ;
F_219 ( V_225 , V_203 , V_16 ) ;
F_73 ( & V_225 -> V_220 ) ;
for ( V_24 = V_203 ; V_24 < V_16 ; V_24 += V_216 ) {
V_210 = F_200 ( V_225 , V_24 ) ;
if ( ! V_210 )
continue;
if ( F_220 ( V_225 , & V_24 , V_210 ) )
continue;
if ( V_224 ) {
V_222 = F_196 ( V_210 ) ;
if ( F_203 ( V_222 ) )
continue;
V_46 = F_205 ( V_222 ) ;
if ( V_46 != V_224 )
continue;
F_33 ( V_23 , V_228 ) ;
}
V_222 = F_221 ( V_225 , V_24 , V_210 ) ;
if ( F_203 ( V_222 ) )
continue;
if ( F_45 ( F_214 ( V_222 ) ) )
continue;
V_46 = F_205 ( V_222 ) ;
if ( F_222 ( V_222 ) )
F_223 ( V_46 ) ;
F_9 ( & V_46 -> V_54 , & V_227 ) ;
}
F_74 ( & V_225 -> V_220 ) ;
F_224 ( V_23 , V_203 , V_16 ) ;
F_225 ( V_225 , V_203 , V_16 ) ;
F_3 (page, tmp, &page_list, lru) {
F_226 ( V_46 ) ;
F_4 ( & V_46 -> V_54 ) ;
F_77 ( V_46 ) ;
}
}
void F_227 ( struct V_22 * V_23 , unsigned long V_203 ,
unsigned long V_16 , struct V_46 * V_224 )
{
F_228 ( & V_23 -> V_116 -> V_117 -> V_229 ) ;
F_216 ( V_23 , V_203 , V_16 , V_224 ) ;
F_229 ( & V_23 -> V_116 -> V_117 -> V_229 ) ;
}
static int F_230 ( struct V_211 * V_225 , struct V_22 * V_23 ,
struct V_46 * V_46 , unsigned long V_24 )
{
struct V_20 * V_21 = F_20 ( V_23 ) ;
struct V_22 * V_230 ;
struct V_80 * V_81 ;
struct V_231 V_232 ;
T_1 V_233 ;
V_24 = V_24 & F_218 ( V_21 ) ;
V_233 = ( ( V_24 - V_23 -> V_25 ) >> V_29 )
+ ( V_23 -> V_26 >> V_29 ) ;
V_81 = (struct V_80 * ) F_68 ( V_46 ) ;
F_228 ( & V_81 -> V_229 ) ;
F_231 (iter_vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
if ( V_230 == V_23 )
continue;
if ( ! F_34 ( V_230 , V_45 ) )
F_216 ( V_230 ,
V_24 , V_24 + F_66 ( V_21 ) ,
V_46 ) ;
}
F_229 ( & V_81 -> V_229 ) ;
return 1 ;
}
static int F_232 ( struct V_211 * V_225 , struct V_22 * V_23 ,
unsigned long V_24 , T_10 * V_210 , T_10 V_222 ,
struct V_46 * V_234 )
{
struct V_20 * V_21 = F_20 ( V_23 ) ;
struct V_46 * V_235 , * V_236 ;
int V_237 ;
int V_238 = 0 ;
V_235 = F_205 ( V_222 ) ;
V_239:
V_237 = ( F_72 ( V_235 ) == 1 ) ;
if ( V_237 ) {
if ( F_233 ( V_235 ) )
F_234 ( V_235 , V_23 , V_24 ) ;
F_195 ( V_23 , V_24 , V_210 ) ;
return 0 ;
}
if ( ! ( V_23 -> V_37 & V_38 ) &&
F_34 ( V_23 , V_45 ) &&
V_235 != V_234 )
V_238 = 1 ;
F_235 ( V_235 ) ;
F_74 ( & V_225 -> V_220 ) ;
V_236 = F_108 ( V_23 , V_24 , V_238 ) ;
if ( F_236 ( V_236 ) ) {
F_237 ( V_235 ) ;
if ( V_238 ) {
F_70 ( F_203 ( V_222 ) ) ;
if ( F_230 ( V_225 , V_23 , V_235 , V_24 ) ) {
F_70 ( F_71 ( V_235 ) != 1 ) ;
F_70 ( F_203 ( V_222 ) ) ;
F_73 ( & V_225 -> V_220 ) ;
goto V_239;
}
F_238 ( 1 ) ;
}
F_73 ( & V_225 -> V_220 ) ;
return - F_239 ( V_236 ) ;
}
if ( F_45 ( F_240 ( V_23 ) ) ) {
F_73 ( & V_225 -> V_220 ) ;
return V_124 ;
}
F_241 ( V_236 , V_235 , V_24 , V_23 ,
F_40 ( V_21 ) ) ;
F_242 ( V_236 ) ;
F_73 ( & V_225 -> V_220 ) ;
V_210 = F_200 ( V_225 , V_24 & F_218 ( V_21 ) ) ;
if ( F_243 ( F_244 ( F_196 ( V_210 ) , V_222 ) ) ) {
F_219 ( V_225 ,
V_24 & F_218 ( V_21 ) ,
( V_24 & F_218 ( V_21 ) ) + F_66 ( V_21 ) ) ;
F_245 ( V_23 , V_24 , V_210 ) ;
F_208 ( V_225 , V_24 , V_210 ,
F_188 ( V_23 , V_236 , 1 ) ) ;
F_226 ( V_235 ) ;
F_246 ( V_236 , V_23 , V_24 ) ;
V_236 = V_235 ;
F_225 ( V_225 ,
V_24 & F_218 ( V_21 ) ,
( V_24 & F_218 ( V_21 ) ) + F_66 ( V_21 ) ) ;
}
F_237 ( V_236 ) ;
F_237 ( V_235 ) ;
return 0 ;
}
static struct V_46 * F_247 ( struct V_20 * V_21 ,
struct V_22 * V_23 , unsigned long V_24 )
{
struct V_80 * V_81 ;
T_1 V_120 ;
V_81 = V_23 -> V_116 -> V_117 ;
V_120 = F_16 ( V_21 , V_23 , V_24 ) ;
return F_248 ( V_81 , V_120 ) ;
}
static bool F_249 ( struct V_20 * V_21 ,
struct V_22 * V_23 , unsigned long V_24 )
{
struct V_80 * V_81 ;
T_1 V_120 ;
struct V_46 * V_46 ;
V_81 = V_23 -> V_116 -> V_117 ;
V_120 = F_16 ( V_21 , V_23 , V_24 ) ;
V_46 = F_250 ( V_81 , V_120 ) ;
if ( V_46 )
F_77 ( V_46 ) ;
return V_46 != NULL ;
}
static int F_251 ( struct V_211 * V_225 , struct V_22 * V_23 ,
unsigned long V_24 , T_10 * V_210 , unsigned int V_41 )
{
struct V_20 * V_21 = F_20 ( V_23 ) ;
int V_98 = V_125 ;
T_1 V_120 ;
unsigned long V_79 ;
struct V_46 * V_46 ;
struct V_80 * V_81 ;
T_10 V_240 ;
if ( F_34 ( V_23 , V_228 ) ) {
F_126 ( V_180
L_23 ,
V_141 -> V_241 ) ;
return V_98 ;
}
V_81 = V_23 -> V_116 -> V_117 ;
V_120 = F_16 ( V_21 , V_23 , V_24 ) ;
V_111:
V_46 = F_248 ( V_81 , V_120 ) ;
if ( ! V_46 ) {
V_79 = F_252 ( V_81 -> V_119 ) >> F_17 ( V_21 ) ;
if ( V_120 >= V_79 )
goto V_140;
V_46 = F_108 ( V_23 , V_24 , 0 ) ;
if ( F_236 ( V_46 ) ) {
V_98 = - F_239 ( V_46 ) ;
goto V_140;
}
F_253 ( V_46 , V_24 , F_40 ( V_21 ) ) ;
F_242 ( V_46 ) ;
if ( V_23 -> V_37 & V_38 ) {
int V_67 ;
struct V_118 * V_118 = V_81 -> V_119 ;
V_67 = F_254 ( V_46 , V_81 , V_120 , V_13 ) ;
if ( V_67 ) {
F_77 ( V_46 ) ;
if ( V_67 == - V_242 )
goto V_111;
goto V_140;
}
F_73 ( & V_118 -> V_243 ) ;
V_118 -> V_244 += F_255 ( V_21 ) ;
F_74 ( & V_118 -> V_243 ) ;
F_207 ( V_46 ) ;
} else {
F_256 ( V_46 ) ;
if ( F_45 ( F_240 ( V_23 ) ) ) {
V_98 = V_124 ;
goto V_245;
}
F_246 ( V_46 , V_23 , V_24 ) ;
}
} else {
if ( F_45 ( F_257 ( V_46 ) ) ) {
V_98 = V_246 |
F_258 ( V_21 - V_147 ) ;
goto V_245;
}
F_207 ( V_46 ) ;
}
if ( ( V_41 & V_247 ) && ! ( V_23 -> V_37 & V_217 ) )
if ( F_106 ( V_21 , V_23 , V_24 ) < 0 ) {
V_98 = V_124 ;
goto V_245;
}
F_73 ( & V_225 -> V_220 ) ;
V_79 = F_252 ( V_81 -> V_119 ) >> F_17 ( V_21 ) ;
if ( V_120 >= V_79 )
goto V_248;
V_98 = 0 ;
if ( ! F_203 ( F_196 ( V_210 ) ) )
goto V_248;
V_240 = F_188 ( V_23 , V_46 , ( ( V_23 -> V_37 & V_249 )
&& ( V_23 -> V_37 & V_217 ) ) ) ;
F_208 ( V_225 , V_24 , V_210 , V_240 ) ;
if ( ( V_41 & V_247 ) && ! ( V_23 -> V_37 & V_217 ) ) {
V_98 = F_232 ( V_225 , V_23 , V_24 , V_210 , V_240 , V_46 ) ;
}
F_74 ( & V_225 -> V_220 ) ;
F_259 ( V_46 ) ;
V_140:
return V_98 ;
V_248:
F_74 ( & V_225 -> V_220 ) ;
V_245:
F_259 ( V_46 ) ;
F_77 ( V_46 ) ;
goto V_140;
}
int F_260 ( struct V_211 * V_225 , struct V_22 * V_23 ,
unsigned long V_24 , unsigned int V_41 )
{
T_10 * V_210 ;
T_10 V_208 ;
int V_98 ;
struct V_46 * V_46 = NULL ;
struct V_46 * V_234 = NULL ;
static F_261 ( V_250 ) ;
struct V_20 * V_21 = F_20 ( V_23 ) ;
V_210 = F_200 ( V_225 , V_24 ) ;
if ( V_210 ) {
V_208 = F_196 ( V_210 ) ;
if ( F_45 ( F_209 ( V_208 ) ) ) {
F_262 ( V_225 , ( V_251 * ) V_210 , V_24 ) ;
return 0 ;
} else if ( F_45 ( F_214 ( V_208 ) ) )
return V_252 |
F_258 ( V_21 - V_147 ) ;
}
V_210 = F_201 ( V_225 , V_24 , F_66 ( V_21 ) ) ;
if ( ! V_210 )
return V_124 ;
F_228 ( & V_250 ) ;
V_208 = F_196 ( V_210 ) ;
if ( F_203 ( V_208 ) ) {
V_98 = F_251 ( V_225 , V_23 , V_24 , V_210 , V_41 ) ;
goto V_253;
}
V_98 = 0 ;
if ( ( V_41 & V_247 ) && ! F_263 ( V_208 ) ) {
if ( F_106 ( V_21 , V_23 , V_24 ) < 0 ) {
V_98 = V_124 ;
goto V_253;
}
if ( ! ( V_23 -> V_37 & V_38 ) )
V_234 = F_247 ( V_21 ,
V_23 , V_24 ) ;
}
V_46 = F_205 ( V_208 ) ;
if ( V_46 != V_234 )
F_256 ( V_46 ) ;
F_73 ( & V_225 -> V_220 ) ;
if ( F_45 ( ! F_244 ( V_208 , F_196 ( V_210 ) ) ) )
goto V_254;
if ( V_41 & V_247 ) {
if ( ! F_263 ( V_208 ) ) {
V_98 = F_232 ( V_225 , V_23 , V_24 , V_210 , V_208 ,
V_234 ) ;
goto V_254;
}
V_208 = F_190 ( V_208 ) ;
}
V_208 = F_193 ( V_208 ) ;
if ( F_197 ( V_23 , V_24 , V_210 , V_208 ,
V_41 & V_247 ) )
F_198 ( V_23 , V_24 , V_210 ) ;
V_254:
F_74 ( & V_225 -> V_220 ) ;
if ( V_234 ) {
F_259 ( V_234 ) ;
F_77 ( V_234 ) ;
}
if ( V_46 != V_234 )
F_259 ( V_46 ) ;
V_253:
F_229 ( & V_250 ) ;
return V_98 ;
}
struct V_46 *
F_264 ( struct V_211 * V_225 , unsigned long V_24 ,
T_12 * V_255 , int V_192 )
{
F_157 () ;
return NULL ;
}
int F_265 ( struct V_211 * V_225 , struct V_22 * V_23 ,
struct V_46 * * V_256 , struct V_22 * * V_257 ,
unsigned long * V_258 , int * V_194 , int V_49 ,
unsigned int V_41 )
{
unsigned long V_259 ;
unsigned long V_260 = * V_258 ;
int V_261 = * V_194 ;
struct V_20 * V_21 = F_20 ( V_23 ) ;
F_73 ( & V_225 -> V_220 ) ;
while ( V_260 < V_23 -> V_204 && V_261 ) {
T_10 * V_222 ;
int V_262 ;
struct V_46 * V_46 ;
V_222 = F_200 ( V_225 , V_260 & F_218 ( V_21 ) ) ;
V_262 = ! V_222 || F_203 ( F_196 ( V_222 ) ) ;
if ( V_262 && ( V_41 & V_263 ) &&
! F_249 ( V_21 , V_23 , V_260 ) ) {
V_261 = 0 ;
break;
}
if ( V_262 ||
( ( V_41 & V_264 ) && ! F_263 ( F_196 ( V_222 ) ) ) ) {
int V_98 ;
F_74 ( & V_225 -> V_220 ) ;
V_98 = F_260 ( V_225 , V_23 , V_260 ,
( V_41 & V_264 ) ? V_247 : 0 ) ;
F_73 ( & V_225 -> V_220 ) ;
if ( ! ( V_98 & V_265 ) )
continue;
V_261 = 0 ;
break;
}
V_259 = ( V_260 & ~ F_218 ( V_21 ) ) >> V_29 ;
V_46 = F_205 ( F_196 ( V_222 ) ) ;
V_266:
if ( V_256 ) {
V_256 [ V_49 ] = F_266 ( V_46 , V_259 ) ;
F_206 ( V_256 [ V_49 ] ) ;
}
if ( V_257 )
V_257 [ V_49 ] = V_23 ;
V_260 += V_27 ;
++ V_259 ;
-- V_261 ;
++ V_49 ;
if ( V_260 < V_23 -> V_204 && V_261 &&
V_259 < F_40 ( V_21 ) ) {
goto V_266;
}
}
F_74 ( & V_225 -> V_220 ) ;
* V_194 = V_261 ;
* V_258 = V_260 ;
return V_49 ? V_49 : - V_267 ;
}
void F_267 ( struct V_22 * V_23 ,
unsigned long V_24 , unsigned long V_16 , T_13 V_268 )
{
struct V_211 * V_225 = V_23 -> V_226 ;
unsigned long V_203 = V_24 ;
T_10 * V_210 ;
T_10 V_222 ;
struct V_20 * V_21 = F_20 ( V_23 ) ;
F_70 ( V_24 >= V_16 ) ;
F_268 ( V_23 , V_24 , V_16 ) ;
F_228 ( & V_23 -> V_116 -> V_117 -> V_229 ) ;
F_73 ( & V_225 -> V_220 ) ;
for (; V_24 < V_16 ; V_24 += F_66 ( V_21 ) ) {
V_210 = F_200 ( V_225 , V_24 ) ;
if ( ! V_210 )
continue;
if ( F_220 ( V_225 , & V_24 , V_210 ) )
continue;
if ( ! F_203 ( F_196 ( V_210 ) ) ) {
V_222 = F_221 ( V_225 , V_24 , V_210 ) ;
V_222 = F_194 ( F_269 ( V_222 , V_268 ) ) ;
F_208 ( V_225 , V_24 , V_210 , V_222 ) ;
}
}
F_74 ( & V_225 -> V_220 ) ;
F_229 ( & V_23 -> V_116 -> V_117 -> V_229 ) ;
F_224 ( V_23 , V_203 , V_16 ) ;
}
int F_270 ( struct V_118 * V_118 ,
long V_10 , long V_9 ,
struct V_22 * V_23 ,
T_14 V_37 )
{
long V_98 , V_12 ;
struct V_20 * V_21 = F_271 ( V_118 ) ;
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
if ( F_110 ( V_118 -> V_121 , V_12 ) )
return - V_269 ;
V_98 = F_182 ( V_21 , V_12 ) ;
if ( V_98 < 0 ) {
F_75 ( V_118 -> V_121 , V_12 ) ;
return V_98 ;
}
if ( ! V_23 || V_23 -> V_37 & V_38 )
F_1 ( & V_118 -> V_121 -> V_122 , V_10 , V_9 ) ;
return 0 ;
}
void F_272 ( struct V_118 * V_118 , long V_270 , long V_271 )
{
struct V_20 * V_21 = F_271 ( V_118 ) ;
long V_12 = F_10 ( & V_118 -> V_121 -> V_122 , V_270 ) ;
F_73 ( & V_118 -> V_243 ) ;
V_118 -> V_244 -= ( F_255 ( V_21 ) * V_271 ) ;
F_74 ( & V_118 -> V_243 ) ;
F_75 ( V_118 -> V_121 , ( V_12 - V_271 ) ) ;
F_182 ( V_21 , - ( V_12 - V_271 ) ) ;
}
static int F_273 ( struct V_46 * V_272 )
{
struct V_46 * V_46 ;
struct V_46 * V_108 ;
struct V_20 * V_21 = F_39 ( V_272 ) ;
int V_53 = F_48 ( V_272 ) ;
F_3 (page, tmp, &h->hugepage_freelists[nid], lru)
if ( V_46 == V_272 )
return 1 ;
return 0 ;
}
int F_274 ( struct V_46 * V_272 )
{
struct V_20 * V_21 = F_39 ( V_272 ) ;
int V_53 = F_48 ( V_272 ) ;
int V_98 = - V_273 ;
F_73 ( & V_82 ) ;
if ( F_273 ( V_272 ) ) {
F_4 ( & V_272 -> V_54 ) ;
F_51 ( V_272 ) ;
V_21 -> V_56 -- ;
V_21 -> V_57 [ V_53 ] -- ;
V_98 = 0 ;
}
F_74 ( & V_82 ) ;
return V_98 ;
}
