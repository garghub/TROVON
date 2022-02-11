struct V_1 * F_1 ( struct V_2 * V_3 , bool V_4 )
{
return V_3 -> V_5 [ V_4 ] ;
}
void F_2 ( struct V_2 * V_3 , struct V_1 * V_5 , bool V_4 )
{
V_3 -> V_5 [ V_4 ] = V_5 ;
}
struct V_6 * F_3 ( struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 -> V_9 -> V_10 ;
}
static struct V_2 * F_4 ( struct V_11 * V_7 )
{
return F_5 ( V_7 , struct V_2 , V_7 ) ;
}
static struct V_2 * F_6 ( struct V_6 * V_12 ,
struct V_13 * V_14 ,
struct V_15 * V_8 )
{
if ( V_14 ) {
unsigned long V_16 ;
struct V_2 * V_7 ;
F_7 ( V_8 -> V_17 , V_16 ) ;
V_7 = F_4 ( F_8 ( V_14 , V_8 ) ) ;
F_9 ( V_8 -> V_17 , V_16 ) ;
return V_7 ;
}
return NULL ;
}
void F_10 ( struct V_6 * V_12 )
{
if ( V_12 -> V_18 != 0 ) {
F_11 ( V_12 , L_1 ) ;
F_12 ( V_12 -> V_19 , true ) ;
}
}
static struct V_20 * F_13 ( struct V_6 * V_12 ,
struct V_20 * V_21 ,
struct V_20 * V_22 ,
T_1 V_23 )
{
T_1 V_24 , V_25 , V_26 = 0 , V_27 = 0 ;
unsigned long V_28 ;
#define F_14 0x01
#define F_15 0x02
unsigned int V_29 = 0 ;
if ( ! V_21 || V_21 == V_22 )
return V_22 ;
if ( ! V_22 )
return V_21 ;
if ( F_16 ( V_21 ) && ! F_16 ( V_22 ) )
return V_21 ;
else if ( F_16 ( V_22 ) && ! F_16 ( V_21 ) )
return V_22 ;
if ( ( V_21 -> V_30 & V_31 ) && ! ( V_22 -> V_30 & V_31 ) )
return V_21 ;
else if ( ( V_22 -> V_30 & V_31 ) && ! ( V_21 -> V_30 & V_31 ) )
return V_22 ;
V_24 = F_17 ( V_21 ) ;
V_25 = F_17 ( V_22 ) ;
V_28 = V_12 -> V_32 * 2 ;
if ( V_24 >= V_23 )
V_26 = V_24 - V_23 ;
else if ( V_24 + V_28 >= V_23 )
V_26 = ( V_23 - V_24 ) * V_12 -> V_33 ;
else
V_29 |= F_14 ;
if ( V_25 >= V_23 )
V_27 = V_25 - V_23 ;
else if ( V_25 + V_28 >= V_23 )
V_27 = ( V_23 - V_25 ) * V_12 -> V_33 ;
else
V_29 |= F_15 ;
switch ( V_29 ) {
case 0 :
if ( V_26 < V_27 )
return V_21 ;
else if ( V_27 < V_26 )
return V_22 ;
if ( V_24 >= V_25 )
return V_21 ;
else
return V_22 ;
case F_15 :
return V_21 ;
case F_14 :
return V_22 ;
case F_14 | F_15 :
default:
if ( V_24 <= V_25 )
return V_21 ;
else
return V_22 ;
}
}
static struct V_1 *
F_18 ( struct V_6 * V_12 , struct V_34 * V_35 ,
T_1 V_36 , struct V_37 * * V_38 ,
struct V_37 * * * V_39 )
{
struct V_37 * * V_40 , * V_41 ;
struct V_1 * V_5 = NULL ;
V_41 = NULL ;
V_40 = & V_35 -> V_37 ;
while ( * V_40 ) {
struct V_37 * * V_42 ;
V_41 = * V_40 ;
V_5 = F_19 ( V_41 , struct V_1 , V_43 ) ;
if ( V_36 > F_17 ( V_5 -> V_44 ) )
V_42 = & ( * V_40 ) -> V_45 ;
else if ( V_36 < F_17 ( V_5 -> V_44 ) )
V_42 = & ( * V_40 ) -> V_46 ;
else
break;
V_40 = V_42 ;
V_5 = NULL ;
}
* V_38 = V_41 ;
if ( V_39 )
* V_39 = V_40 ;
F_11 ( V_12 , L_2 ,
( unsigned long long ) V_36 ,
V_5 ? V_5 -> V_47 : 0 ) ;
return V_5 ;
}
void F_20 ( struct V_6 * V_12 , struct V_1 * V_5 )
{
struct V_37 * * V_40 , * V_41 ;
struct V_1 * V_48 ;
if ( V_5 -> V_49 ) {
F_21 ( & V_5 -> V_43 , V_5 -> V_49 ) ;
V_5 -> V_49 = NULL ;
}
if ( F_22 ( V_5 ) )
return;
if ( ! V_5 -> V_44 )
return;
V_5 -> V_49 = & F_23 ( V_5 ) -> V_50 ;
V_48 = F_18 ( V_12 , V_5 -> V_49 ,
F_17 ( V_5 -> V_44 ) , & V_41 , & V_40 ) ;
if ( ! V_48 ) {
F_24 ( & V_5 -> V_43 , V_41 , V_40 ) ;
F_25 ( & V_5 -> V_43 , V_5 -> V_49 ) ;
} else
V_5 -> V_49 = NULL ;
}
static bool F_26 ( struct V_6 * V_12 )
{
return ( ! F_27 ( & V_12 -> V_51 ) &&
( V_12 -> V_51 . V_37 -> V_46 ||
V_12 -> V_51 . V_37 -> V_45 )
#ifdef F_28
) ||
( ! F_27 ( & V_12 -> V_52 ) &&
( V_12 -> V_52 . V_37 -> V_46 ||
V_12 -> V_52 . V_37 -> V_45 )
#endif
) ;
}
static bool F_29 ( struct V_6 * V_12 )
{
return ! F_26 ( V_12 ) ;
}
void F_30 ( struct V_6 * V_12 , struct V_53 * V_54 ,
struct V_34 * V_35 )
{
struct V_37 * * V_55 = & ( V_35 -> V_37 ) , * V_41 = NULL ;
if ( V_54 -> V_56 )
return;
while ( * V_55 ) {
struct V_57 * V_58 = F_5 ( * V_55 ,
struct V_57 ,
V_59 ) ;
V_41 = * V_55 ;
if ( V_54 -> V_60 == V_58 -> V_60 ) {
V_54 -> V_56 = V_58 ;
goto V_61;
}
if ( V_54 -> V_60 < V_58 -> V_60 )
V_55 = & ( ( * V_55 ) -> V_46 ) ;
else
V_55 = & ( ( * V_55 ) -> V_45 ) ;
}
V_54 -> V_56 = F_31 ( sizeof( struct V_57 ) ,
V_62 ) ;
if ( F_32 ( ! V_54 -> V_56 ) )
return;
V_54 -> V_56 -> V_60 = V_54 -> V_60 ;
F_24 ( & V_54 -> V_56 -> V_59 , V_41 , V_55 ) ;
F_25 ( & V_54 -> V_56 -> V_59 , V_35 ) ;
V_61:
V_54 -> V_56 -> V_63 ++ ;
}
void F_33 ( struct V_6 * V_12 , struct V_53 * V_54 ,
struct V_34 * V_35 )
{
if ( ! V_54 -> V_56 )
return;
V_54 -> V_56 -> V_63 -- ;
if ( V_54 -> V_56 -> V_63 > 0 )
goto V_64;
F_21 ( & V_54 -> V_56 -> V_59 , V_35 ) ;
F_34 ( V_54 -> V_56 ) ;
V_64:
V_54 -> V_56 = NULL ;
}
static struct V_20 * F_35 ( struct V_1 * V_5 ,
struct V_20 * V_23 )
{
struct V_20 * V_65 ;
if ( F_36 ( V_5 ) )
return NULL ;
F_37 ( V_5 ) ;
V_65 = F_38 ( V_5 -> V_66 . V_67 ) ;
if ( V_65 == V_23 || F_39 () < V_65 -> V_68 )
return NULL ;
F_40 ( V_5 -> V_12 , V_5 , L_3 , V_65 ) ;
return V_65 ;
}
static struct V_20 * F_41 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
struct V_20 * V_23 )
{
struct V_37 * V_69 = F_42 ( & V_23 -> V_37 ) ;
struct V_37 * V_70 = F_43 ( & V_23 -> V_37 ) ;
struct V_20 * V_67 , * V_71 = NULL ;
V_67 = F_35 ( V_5 , V_23 ) ;
if ( V_67 )
return V_67 ;
if ( V_70 )
V_71 = F_44 ( V_70 ) ;
if ( V_69 )
V_67 = F_44 ( V_69 ) ;
else {
V_69 = F_45 ( & V_5 -> V_72 ) ;
if ( V_69 && V_69 != & V_23 -> V_37 )
V_67 = F_44 ( V_69 ) ;
}
return F_13 ( V_12 , V_67 , V_71 , F_17 ( V_23 ) ) ;
}
static unsigned long F_46 ( struct V_20 * V_65 ,
struct V_1 * V_5 )
{
if ( F_47 ( V_5 ) || V_5 -> V_73 > 1 )
return F_48 ( V_65 ) ;
if ( V_5 -> V_12 -> V_74 == 0 )
return F_48 ( V_65 ) * V_75 ;
return F_48 ( V_65 ) * 2 * V_75 ;
}
static void F_49 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_54 ;
struct V_20 * V_44 = V_5 -> V_44 ;
unsigned long V_76 ;
if ( ! V_44 )
return;
if ( V_5 == V_12 -> V_77 )
return;
V_76 = F_50 (unsigned long, bfqq->max_budget,
bfq_serv_to_charge(next_rq, bfqq)) ;
if ( V_54 -> V_78 != V_76 ) {
V_54 -> V_78 = V_76 ;
F_40 ( V_12 , V_5 , L_4 ,
V_76 ) ;
F_51 ( V_12 , V_5 ) ;
}
}
static void
F_52 ( struct V_1 * V_5 , struct V_2 * V_3 )
{
if ( V_3 -> V_79 )
F_53 ( V_5 ) ;
else
F_54 ( V_5 ) ;
if ( V_3 -> V_80 )
F_55 ( V_5 ) ;
else
F_56 ( V_5 ) ;
V_5 -> V_81 = V_3 -> V_82 ;
V_5 -> V_73 = V_3 -> V_83 ;
V_5 -> V_84 = V_3 -> V_85 ;
V_5 -> V_86 = V_3 -> V_87 ;
V_5 -> V_88 = V_3 -> V_89 ;
if ( V_5 -> V_73 > 1 && ( F_57 ( V_5 ) ||
F_58 ( V_5 -> V_86 +
V_5 -> V_88 ) ) ) {
F_40 ( V_5 -> V_12 , V_5 ,
L_5 ) ;
V_5 -> V_73 = 1 ;
}
V_5 -> V_54 . V_90 = 1 ;
}
static int F_59 ( struct V_1 * V_5 )
{
return V_5 -> V_91 - V_5 -> V_92 - V_5 -> V_54 . V_93 ;
}
static void F_60 ( struct V_6 * V_12 , struct V_1 * V_5 )
{
struct V_1 * V_94 ;
struct V_95 * V_42 ;
F_61 (item, n, &bfqd->burst_list, burst_list_node)
F_62 ( & V_94 -> V_96 ) ;
F_63 ( & V_5 -> V_96 , & V_12 -> V_97 ) ;
V_12 -> V_98 = 1 ;
V_12 -> V_99 = V_5 -> V_54 . V_41 ;
}
static void F_64 ( struct V_6 * V_12 , struct V_1 * V_5 )
{
V_12 -> V_98 ++ ;
if ( V_12 -> V_98 == V_12 -> V_100 ) {
struct V_1 * V_101 , * V_102 ;
struct V_95 * V_42 ;
V_12 -> V_103 = true ;
F_65 (bfqq_item, &bfqd->burst_list,
burst_list_node)
F_66 ( V_102 ) ;
F_66 ( V_5 ) ;
F_61 (pos, n, &bfqd->burst_list,
burst_list_node)
F_62 ( & V_101 -> V_96 ) ;
} else
F_63 ( & V_5 -> V_96 , & V_12 -> V_97 ) ;
}
static void F_67 ( struct V_6 * V_12 , struct V_1 * V_5 )
{
if ( ! F_68 ( & V_5 -> V_96 ) ||
F_57 ( V_5 ) ||
F_69 ( V_5 -> V_104 +
F_70 ( 10 ) ) )
return;
if ( F_58 ( V_12 -> V_105 +
V_12 -> V_106 ) ||
V_5 -> V_54 . V_41 != V_12 -> V_99 ) {
V_12 -> V_103 = false ;
F_60 ( V_12 , V_5 ) ;
goto V_107;
}
if ( V_12 -> V_103 ) {
F_66 ( V_5 ) ;
goto V_107;
}
F_64 ( V_12 , V_5 ) ;
V_107:
V_12 -> V_105 = V_108 ;
}
static int F_71 ( struct V_1 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_54 ;
return V_54 -> V_78 - V_54 -> V_109 ;
}
static int F_72 ( struct V_6 * V_12 )
{
if ( V_12 -> V_110 < V_111 )
return V_112 ;
else
return V_12 -> F_72 ;
}
static int F_73 ( struct V_6 * V_12 )
{
if ( V_12 -> V_110 < V_111 )
return V_112 / 32 ;
else
return V_12 -> F_72 / 32 ;
}
static bool F_74 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
bool V_113 ,
bool V_114 )
{
struct V_53 * V_54 = & V_5 -> V_54 ;
if ( F_75 ( V_5 ) && V_113 ) {
V_54 -> V_78 = F_76 (unsigned long,
bfq_bfqq_budget_left(bfqq),
bfqq->max_budget) ;
return true ;
}
V_54 -> V_78 = F_50 (unsigned long, bfqq->max_budget,
bfq_serv_to_charge(bfqq->next_rq, bfqq)) ;
F_77 ( V_5 ) ;
return V_114 ;
}
static unsigned int F_78 ( struct V_6 * V_12 )
{
T_2 V_115 ;
if ( V_12 -> V_116 > 0 )
return V_12 -> V_116 ;
V_115 = V_12 -> V_117 ;
F_79 ( V_115 , V_12 -> V_118 ) ;
if ( V_115 > F_70 ( 13000 ) )
V_115 = F_70 ( 13000 ) ;
else if ( V_115 < F_70 ( 3000 ) )
V_115 = F_70 ( 3000 ) ;
return V_115 ;
}
static void F_80 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
unsigned int V_119 ,
bool V_114 ,
bool V_120 ,
bool V_121 ,
bool V_122 )
{
if ( V_119 == 1 && V_114 ) {
if ( V_120 ) {
V_5 -> V_73 = V_12 -> V_123 ;
V_5 -> V_88 = F_78 ( V_12 ) ;
} else {
V_5 -> V_84 = V_108 ;
V_5 -> V_73 = V_12 -> V_123 *
V_124 ;
V_5 -> V_88 =
V_12 -> V_125 ;
}
V_5 -> V_54 . V_78 = F_76 (unsigned long,
bfqq->entity.budget,
2 * bfq_min_budget(bfqd)) ;
} else if ( V_119 > 1 ) {
if ( V_120 ) {
V_5 -> V_73 = V_12 -> V_123 ;
V_5 -> V_88 = F_78 ( V_12 ) ;
} else if ( V_121 )
V_5 -> V_73 = 1 ;
else if ( V_122 ) {
if ( V_5 -> V_88 !=
V_12 -> V_125 ) {
V_5 -> V_84 =
V_5 -> V_86 ;
V_5 -> V_88 =
V_12 -> V_125 ;
V_5 -> V_73 = V_12 -> V_123 *
V_124 ;
}
V_5 -> V_86 = V_108 ;
}
}
}
static bool F_81 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
return V_5 -> V_126 == 0 &&
F_58 (
V_5 -> V_127 +
V_12 -> V_128 ) ;
}
static void F_82 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
int V_119 ,
struct V_20 * V_65 ,
bool * V_120 )
{
bool V_122 , V_121 , V_114 ,
V_129 ,
V_130 = F_81 ( V_12 , V_5 ) ,
V_113 = F_39 () <=
V_5 -> V_81 . V_131 +
V_12 -> V_132 * 3 ;
F_83 ( F_84 ( F_85 ( V_65 ) ) , V_5 , V_65 -> V_30 ) ;
V_121 = F_57 ( V_5 ) ;
V_122 = V_12 -> V_133 > 0 &&
! V_121 &&
F_58 ( V_5 -> V_134 ) ;
* V_120 = ! V_121 && V_130 ;
V_114 = V_12 -> V_135 &&
( V_5 -> V_73 > 1 ||
( F_47 ( V_5 ) &&
V_5 -> V_3 && ( * V_120 || V_122 ) ) ) ;
V_129 =
F_74 ( V_12 , V_5 ,
V_113 ,
V_114 ) ;
if ( F_86 ( ! F_87 ( V_5 ) ) &&
V_130 &&
F_58 (
V_5 -> V_127 +
F_70 ( 10000 ) ) ) {
F_62 ( & V_5 -> V_96 ) ;
F_88 ( V_5 ) ;
}
F_89 ( V_5 ) ;
if ( ! F_90 ( V_5 ) ) {
if ( V_113 ) {
V_5 -> V_136 ++ ;
if ( V_5 -> V_136 >=
V_12 -> V_137 )
F_55 ( V_5 ) ;
} else
V_5 -> V_136 = 0 ;
}
if ( V_12 -> V_135 ) {
if ( F_32 ( F_91 ( V_5 -> V_104 ) ) )
V_5 -> V_104 =
V_108 - V_12 -> V_128 - 1 ;
if ( F_58 ( V_5 -> V_104 +
V_12 -> V_128 ) ) {
F_80 ( V_12 , V_5 ,
V_119 ,
V_114 ,
* V_120 ,
V_121 ,
V_122 ) ;
if ( V_119 != V_5 -> V_73 )
V_5 -> V_54 . V_90 = 1 ;
}
}
V_5 -> V_138 = V_108 ;
V_5 -> V_139 = 0 ;
F_92 ( V_5 ) ;
F_93 ( V_12 , V_5 ) ;
if ( V_12 -> V_77 && V_129 &&
V_12 -> V_77 -> V_73 < V_5 -> V_73 &&
F_94 ( V_12 ) )
F_95 ( V_12 , V_12 -> V_77 ,
false , V_140 ) ;
}
static void F_96 ( struct V_20 * V_65 )
{
struct V_1 * V_5 = F_85 ( V_65 ) ;
struct V_6 * V_12 = V_5 -> V_12 ;
struct V_20 * V_44 , * V_71 ;
unsigned int V_119 = V_5 -> V_73 ;
bool V_120 = false ;
F_40 ( V_12 , V_5 , L_6 , F_16 ( V_65 ) ) ;
V_5 -> V_18 [ F_16 ( V_65 ) ] ++ ;
V_12 -> V_18 ++ ;
F_97 ( & V_5 -> V_72 , V_65 ) ;
V_71 = V_5 -> V_44 ;
V_44 = F_13 ( V_12 , V_5 -> V_44 , V_65 , V_12 -> V_141 ) ;
V_5 -> V_44 = V_44 ;
if ( V_71 != V_5 -> V_44 )
F_20 ( V_12 , V_5 ) ;
if ( ! F_98 ( V_5 ) )
F_82 ( V_12 , V_5 , V_119 ,
V_65 , & V_120 ) ;
else {
if ( V_12 -> V_135 && V_119 == 1 && ! F_16 ( V_65 ) &&
F_58 (
V_5 -> V_86 +
V_12 -> V_142 ) ) {
V_5 -> V_73 = V_12 -> V_123 ;
V_5 -> V_88 = F_78 ( V_12 ) ;
V_12 -> V_74 ++ ;
V_5 -> V_54 . V_90 = 1 ;
}
if ( V_71 != V_5 -> V_44 )
F_49 ( V_12 , V_5 ) ;
}
if ( V_12 -> V_135 &&
( V_119 == 1 || V_5 -> V_73 == 1 || V_120 ) )
V_5 -> V_86 = V_108 ;
}
static struct V_20 * F_99 ( struct V_6 * V_12 ,
struct V_143 * V_143 ,
struct V_15 * V_8 )
{
struct V_1 * V_5 = V_12 -> V_144 ;
if ( V_5 )
return F_100 ( & V_5 -> V_72 , F_101 ( V_143 ) ) ;
return NULL ;
}
static T_1 F_102 ( T_1 V_145 , struct V_20 * V_65 )
{
if ( V_145 )
return abs ( F_17 ( V_65 ) - V_145 ) ;
return 0 ;
}
static void F_103 ( struct V_15 * V_8 ,
struct V_20 * V_65 )
{
struct V_1 * V_5 = F_85 ( V_65 ) ;
struct V_6 * V_12 = V_5 -> V_12 ;
const int V_146 = F_16 ( V_65 ) ;
if ( V_5 -> V_44 == V_65 ) {
V_5 -> V_44 = F_41 ( V_12 , V_5 , V_65 ) ;
F_49 ( V_12 , V_5 ) ;
}
if ( V_65 -> V_147 . V_71 != & V_65 -> V_147 )
F_104 ( & V_65 -> V_147 ) ;
V_5 -> V_18 [ V_146 ] -- ;
V_12 -> V_18 -- ;
F_105 ( & V_5 -> V_72 , V_65 ) ;
F_106 ( V_8 , V_65 ) ;
if ( V_8 -> V_148 == V_65 )
V_8 -> V_148 = NULL ;
if ( F_27 ( & V_5 -> V_72 ) ) {
V_5 -> V_44 = NULL ;
if ( F_98 ( V_5 ) && V_5 != V_12 -> V_77 ) {
F_107 ( V_12 , V_5 , false ) ;
V_5 -> V_54 . V_78 = V_5 -> V_54 . V_109 = 0 ;
}
if ( V_5 -> V_49 ) {
F_21 ( & V_5 -> V_43 , V_5 -> V_49 ) ;
V_5 -> V_49 = NULL ;
}
}
if ( V_65 -> V_30 & V_31 )
V_5 -> V_149 -- ;
F_108 ( F_84 ( V_5 ) , V_65 -> V_30 ) ;
}
static bool F_109 ( struct V_150 * V_151 , struct V_143 * V_143 )
{
struct V_15 * V_8 = V_151 -> V_19 ;
struct V_6 * V_12 = V_8 -> V_9 -> V_10 ;
struct V_20 * free = NULL ;
struct V_2 * V_3 = F_6 ( V_12 , V_152 -> V_13 , V_8 ) ;
bool V_153 ;
F_110 ( & V_12 -> V_154 ) ;
if ( V_3 )
V_12 -> V_144 = F_1 ( V_3 , F_111 ( V_143 -> V_155 ) ) ;
else
V_12 -> V_144 = NULL ;
V_12 -> V_156 = V_3 ;
V_153 = F_112 ( V_8 , V_143 , & free ) ;
if ( free )
F_113 ( free ) ;
F_114 ( & V_12 -> V_154 ) ;
return V_153 ;
}
static int F_115 ( struct V_15 * V_8 , struct V_20 * * V_157 ,
struct V_143 * V_143 )
{
struct V_6 * V_12 = V_8 -> V_9 -> V_10 ;
struct V_20 * V_158 ;
V_158 = F_99 ( V_12 , V_143 , V_8 ) ;
if ( V_158 && F_116 ( V_158 , V_143 ) ) {
* V_157 = V_158 ;
return V_159 ;
}
return V_160 ;
}
static void F_117 ( struct V_15 * V_8 , struct V_20 * V_157 ,
enum V_161 type )
{
if ( type == V_159 &&
F_43 ( & V_157 -> V_37 ) &&
F_17 ( V_157 ) <
F_17 ( F_5 ( F_43 ( & V_157 -> V_37 ) ,
struct V_20 , V_37 ) ) ) {
struct V_1 * V_5 = F_85 ( V_157 ) ;
struct V_6 * V_12 = V_5 -> V_12 ;
struct V_20 * V_71 , * V_44 ;
F_105 ( & V_5 -> V_72 , V_157 ) ;
F_97 ( & V_5 -> V_72 , V_157 ) ;
V_71 = V_5 -> V_44 ;
V_44 = F_13 ( V_12 , V_5 -> V_44 , V_157 ,
V_12 -> V_141 ) ;
V_5 -> V_44 = V_44 ;
if ( V_71 != V_5 -> V_44 ) {
F_49 ( V_12 , V_5 ) ;
F_20 ( V_12 , V_5 ) ;
}
}
}
static void F_118 ( struct V_15 * V_8 , struct V_20 * V_65 ,
struct V_20 * V_67 )
{
struct V_1 * V_5 = F_85 ( V_65 ) , * V_162 = F_85 ( V_67 ) ;
if ( ! F_119 ( & V_65 -> V_37 ) )
goto V_107;
F_110 ( & V_5 -> V_12 -> V_154 ) ;
if ( V_5 == V_162 &&
! F_120 ( & V_65 -> V_147 ) && ! F_120 ( & V_67 -> V_147 ) &&
V_67 -> V_68 < V_65 -> V_68 ) {
F_104 ( & V_65 -> V_147 ) ;
F_121 ( & V_67 -> V_147 , & V_65 -> V_147 ) ;
V_65 -> V_68 = V_67 -> V_68 ;
}
if ( V_5 -> V_44 == V_67 )
V_5 -> V_44 = V_65 ;
F_103 ( V_8 , V_67 ) ;
F_114 ( & V_5 -> V_12 -> V_154 ) ;
V_107:
F_122 ( F_84 ( V_5 ) , V_67 -> V_30 ) ;
}
static void F_123 ( struct V_1 * V_5 )
{
if ( F_98 ( V_5 ) )
V_5 -> V_12 -> V_74 -- ;
V_5 -> V_73 = 1 ;
V_5 -> V_88 = 0 ;
V_5 -> V_86 = V_108 ;
V_5 -> V_54 . V_90 = 1 ;
}
void F_124 ( struct V_6 * V_12 ,
struct V_163 * V_164 )
{
int V_165 , V_166 ;
for ( V_165 = 0 ; V_165 < 2 ; V_165 ++ )
for ( V_166 = 0 ; V_166 < V_167 ; V_166 ++ )
if ( V_164 -> V_168 [ V_165 ] [ V_166 ] )
F_123 ( V_164 -> V_168 [ V_165 ] [ V_166 ] ) ;
if ( V_164 -> V_169 )
F_123 ( V_164 -> V_169 ) ;
}
static void F_125 ( struct V_6 * V_12 )
{
struct V_1 * V_5 ;
F_110 ( & V_12 -> V_154 ) ;
F_126 (bfqq, &bfqd->active_list, bfqq_list)
F_123 ( V_5 ) ;
F_126 (bfqq, &bfqd->idle_list, bfqq_list)
F_123 ( V_5 ) ;
F_127 ( V_12 ) ;
F_114 ( & V_12 -> V_154 ) ;
}
static T_1 F_128 ( void * V_170 , bool V_20 )
{
if ( V_20 )
return F_17 ( V_170 ) ;
else
return ( (struct V_143 * ) V_170 ) -> V_171 . V_172 ;
}
static int F_129 ( void * V_170 , bool V_20 ,
T_1 V_36 )
{
return abs ( F_128 ( V_170 , V_20 ) - V_36 ) <=
V_173 ;
}
static struct V_1 * F_130 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
T_1 V_36 )
{
struct V_34 * V_35 = & F_23 ( V_5 ) -> V_50 ;
struct V_37 * V_41 , * V_174 ;
struct V_1 * V_48 ;
if ( F_27 ( V_35 ) )
return NULL ;
V_48 = F_18 ( V_12 , V_35 , V_36 , & V_41 , NULL ) ;
if ( V_48 )
return V_48 ;
V_48 = F_19 ( V_41 , struct V_1 , V_43 ) ;
if ( F_129 ( V_48 -> V_44 , true , V_36 ) )
return V_48 ;
if ( F_17 ( V_48 -> V_44 ) < V_36 )
V_174 = F_42 ( & V_48 -> V_43 ) ;
else
V_174 = F_43 ( & V_48 -> V_43 ) ;
if ( ! V_174 )
return NULL ;
V_48 = F_19 ( V_174 , struct V_1 , V_43 ) ;
if ( F_129 ( V_48 -> V_44 , true , V_36 ) )
return V_48 ;
return NULL ;
}
static struct V_1 * F_131 ( struct V_6 * V_12 ,
struct V_1 * V_175 ,
T_1 V_36 )
{
struct V_1 * V_5 ;
V_5 = F_130 ( V_12 , V_175 , V_36 ) ;
if ( ! V_5 || V_5 == V_175 )
return NULL ;
return V_5 ;
}
static struct V_1 *
F_132 ( struct V_1 * V_5 , struct V_1 * V_176 )
{
int V_177 , V_178 ;
struct V_1 * V_48 ;
if ( ! F_59 ( V_176 ) )
return NULL ;
while ( ( V_48 = V_176 -> V_176 ) ) {
if ( V_48 == V_5 )
return NULL ;
V_176 = V_48 ;
}
V_177 = F_59 ( V_5 ) ;
V_178 = F_59 ( V_176 ) ;
if ( V_177 == 0 || V_178 == 0 )
return NULL ;
F_40 ( V_5 -> V_12 , V_5 , L_7 ,
V_176 -> V_47 ) ;
V_5 -> V_176 = V_176 ;
V_176 -> V_91 += V_177 ;
return V_176 ;
}
static bool F_133 ( struct V_1 * V_5 ,
struct V_1 * V_176 )
{
if ( F_22 ( V_5 ) || F_22 ( V_176 ) ||
( V_5 -> V_179 != V_176 -> V_179 ) )
return false ;
if ( F_134 ( V_5 ) || F_134 ( V_176 ) )
return false ;
if ( ! F_47 ( V_5 ) || ! F_47 ( V_176 ) )
return false ;
return true ;
}
static bool F_135 ( struct V_1 * V_5 )
{
return V_5 -> V_73 > 1 &&
F_58 ( V_5 -> V_86 +
F_70 ( 100 ) ) ;
}
static struct V_1 *
F_136 ( struct V_6 * V_12 , struct V_1 * V_5 ,
void * V_170 , bool V_20 )
{
struct V_1 * V_180 , * V_176 ;
if ( V_5 -> V_176 )
return V_5 -> V_176 ;
if ( ! V_170 ||
F_135 ( V_5 ) ||
F_32 ( V_5 == & V_12 -> V_181 ) )
return NULL ;
if ( V_12 -> V_182 == 1 )
return NULL ;
V_180 = V_12 -> V_77 ;
if ( ! V_180 || V_180 == V_5
|| F_135 ( V_180 ) ||
F_32 ( V_180 == & V_12 -> V_181 ) )
goto V_183;
if ( F_129 ( V_170 , V_20 , V_12 -> V_141 ) &&
V_5 -> V_54 . V_41 == V_180 -> V_54 . V_41 &&
F_133 ( V_5 , V_180 ) ) {
V_176 = F_132 ( V_5 , V_180 ) ;
if ( V_176 )
return V_176 ;
}
V_183:
V_176 = F_131 ( V_12 , V_5 ,
F_128 ( V_170 , V_20 ) ) ;
if ( V_176 && ! F_135 ( V_176 ) &&
F_86 ( V_176 != & V_12 -> V_181 ) &&
F_133 ( V_5 , V_176 ) )
return F_132 ( V_5 , V_176 ) ;
return NULL ;
}
static void F_137 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
if ( ! V_3 )
return;
V_3 -> V_82 = V_5 -> V_81 ;
V_3 -> V_79 = F_138 ( V_5 ) ;
V_3 -> V_80 = F_90 ( V_5 ) ;
V_3 -> V_184 = F_57 ( V_5 ) ;
V_3 -> V_185 = ! F_68 ( & V_5 -> V_96 ) ;
V_3 -> V_83 = V_5 -> V_73 ;
V_3 -> V_85 = V_5 -> V_84 ;
V_3 -> V_87 = V_5 -> V_86 ;
V_3 -> V_89 = V_5 -> V_88 ;
}
static void
F_139 ( struct V_6 * V_12 , struct V_2 * V_3 ,
struct V_1 * V_5 , struct V_1 * V_176 )
{
F_40 ( V_12 , V_5 , L_8 ,
( unsigned long ) V_176 -> V_47 ) ;
F_137 ( V_5 ) ;
F_137 ( V_176 ) ;
if ( F_90 ( V_5 ) )
F_55 ( V_176 ) ;
F_56 ( V_5 ) ;
if ( V_176 -> V_73 == 1 && V_5 -> V_73 > 1 ) {
V_176 -> V_73 = V_5 -> V_73 ;
V_176 -> V_88 = V_5 -> V_88 ;
V_176 -> V_86 = V_5 -> V_86 ;
V_176 -> V_84 =
V_5 -> V_84 ;
if ( F_98 ( V_176 ) )
V_12 -> V_74 ++ ;
V_176 -> V_54 . V_90 = 1 ;
}
if ( V_5 -> V_73 > 1 ) {
V_5 -> V_73 = 1 ;
V_5 -> V_54 . V_90 = 1 ;
if ( F_98 ( V_5 ) )
V_12 -> V_74 -- ;
}
F_40 ( V_12 , V_176 , L_9 ,
V_12 -> V_74 ) ;
F_2 ( V_3 , V_176 , 1 ) ;
F_140 ( V_176 ) ;
V_176 -> V_3 = NULL ;
V_5 -> V_3 = NULL ;
F_141 ( V_5 ) ;
}
static bool F_142 ( struct V_15 * V_8 , struct V_20 * V_65 ,
struct V_143 * V_143 )
{
struct V_6 * V_12 = V_8 -> V_9 -> V_10 ;
bool V_4 = F_111 ( V_143 -> V_155 ) ;
struct V_1 * V_5 = V_12 -> V_144 , * V_176 ;
if ( V_4 && ! F_16 ( V_65 ) )
return false ;
if ( ! V_5 )
return false ;
V_176 = F_136 ( V_12 , V_5 , V_143 , false ) ;
if ( V_176 ) {
F_139 ( V_12 , V_12 -> V_156 , V_5 ,
V_176 ) ;
V_5 = V_176 ;
V_12 -> V_144 = V_5 ;
}
return V_5 == F_85 ( V_65 ) ;
}
static void F_143 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
unsigned int V_186 ;
if ( V_5 -> V_88 == V_12 -> V_125 )
V_186 = 1 ;
else
V_186 = V_5 -> V_54 . V_60 / V_5 -> V_54 . V_187 ;
V_12 -> V_188 = F_144 () ;
V_5 -> V_127 = V_108 +
V_12 -> V_189 * V_186 ;
}
static void F_145 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
if ( V_5 ) {
F_146 ( F_84 ( V_5 ) ) ;
F_147 ( V_5 ) ;
V_12 -> V_110 = ( V_12 -> V_110 * 7 + 256 ) / 8 ;
if ( F_58 ( V_5 -> V_86 ) &&
V_5 -> V_73 > 1 &&
V_5 -> V_88 == V_12 -> V_125 &&
F_58 ( V_5 -> V_127 ) ) {
if ( F_148 ( V_5 -> V_127 ,
V_5 -> V_86 ) )
V_5 -> V_86 +=
V_108 - V_5 -> V_127 ;
else
V_5 -> V_86 = V_108 ;
}
F_143 ( V_12 , V_5 ) ;
F_40 ( V_12 , V_5 ,
L_10 ,
V_5 -> V_54 . V_78 ) ;
}
V_12 -> V_77 = V_5 ;
}
static struct V_1 * F_149 ( struct V_6 * V_12 )
{
struct V_1 * V_5 = F_150 ( V_12 ) ;
F_145 ( V_12 , V_5 ) ;
return V_5 ;
}
static void F_151 ( struct V_6 * V_12 )
{
struct V_1 * V_5 = V_12 -> V_77 ;
T_3 V_190 ;
F_152 ( V_5 ) ;
V_190 = V_12 -> V_132 ;
if ( F_134 ( V_5 ) && V_5 -> V_73 == 1 &&
F_29 ( V_12 ) )
V_190 = F_76 ( T_2 , V_190 , V_191 ) ;
V_12 -> V_192 = F_144 () ;
F_153 ( & V_12 -> V_193 , F_154 ( V_190 ) ,
V_194 ) ;
F_155 ( F_84 ( V_5 ) ) ;
}
static unsigned long F_156 ( struct V_6 * V_12 )
{
return ( T_2 ) V_12 -> V_118 * V_195 *
F_157 ( V_12 -> V_189 ) >> V_196 ;
}
static void F_158 ( struct V_6 * V_12 )
{
int V_197 = F_159 ( V_12 -> V_19 ) ;
if ( V_12 -> V_198 == 0 )
V_12 -> F_72 =
F_156 ( V_12 ) ;
if ( V_12 -> V_199 == V_200 &&
V_12 -> V_118 < V_201 [ V_197 ] ) {
V_12 -> V_199 = V_202 ;
V_12 -> V_117 = V_203 [ V_197 ] *
V_204 [ V_197 ] ;
} else if ( V_12 -> V_199 == V_202 &&
V_12 -> V_118 > V_201 [ V_197 ] ) {
V_12 -> V_199 = V_200 ;
V_12 -> V_117 = V_205 [ V_197 ] *
V_206 [ V_197 ] ;
}
F_11 ( V_12 ,
L_11 ,
V_197 == 0 ? L_12 : L_13 ,
V_12 -> V_199 == V_200 ? L_14 : L_15 ,
V_12 -> V_199 == V_200 ?
( V_207 * ( T_2 ) V_205 [ V_197 ] ) >> V_196 :
( V_207 * ( T_2 ) V_203 [ V_197 ] ) >> V_196 ,
( V_207 * ( T_2 ) V_201 [ V_197 ] ) >>
V_196 ) ;
}
static void F_160 ( struct V_6 * V_12 ,
struct V_20 * V_65 )
{
if ( V_65 != NULL ) {
V_12 -> V_208 = V_12 -> V_209 = F_39 () ;
V_12 -> V_210 = 1 ;
V_12 -> V_211 = 0 ;
V_12 -> V_212 = V_12 -> V_213 =
F_48 ( V_65 ) ;
} else
V_12 -> V_210 = 0 ;
F_11 ( V_12 ,
L_16 ,
V_12 -> V_210 , V_12 -> V_211 ,
V_12 -> V_212 ) ;
}
static void F_161 ( struct V_6 * V_12 , struct V_20 * V_65 )
{
T_3 V_214 , V_60 , V_215 ;
if ( V_12 -> V_210 < V_216 ||
V_12 -> V_217 < V_218 )
goto V_219;
V_12 -> V_217 =
F_50 ( T_2 , V_12 -> V_217 ,
V_12 -> V_220 - V_12 -> V_209 ) ;
V_214 = F_162 ( V_12 -> V_212 << V_196 ,
F_163 ( V_12 -> V_217 , V_221 ) ) ;
if ( ( V_12 -> V_211 < ( 3 * V_12 -> V_210 ) >> 2 &&
V_214 <= V_12 -> V_118 ) ||
V_214 > 20 << V_196 )
goto V_219;
V_60 = ( 9 * V_12 -> V_211 ) / V_12 -> V_210 ;
V_60 = F_76 ( T_3 , 8 ,
F_163 ( V_60 * V_12 -> V_217 ,
V_222 ) ) ;
V_215 = 10 - V_60 ;
V_12 -> V_118 *= V_215 - 1 ;
V_12 -> V_118 /= V_215 ;
V_214 /= V_215 ;
V_12 -> V_118 += V_214 ;
F_158 ( V_12 ) ;
V_219:
F_160 ( V_12 , V_65 ) ;
}
static void F_164 ( struct V_6 * V_12 , struct V_20 * V_65 )
{
T_2 V_223 = F_39 () ;
if ( V_12 -> V_210 == 0 ) {
F_11 ( V_12 , L_17 ,
V_12 -> V_210 ) ;
F_160 ( V_12 , V_65 ) ;
goto V_224;
}
if ( V_223 - V_12 -> V_208 > 100 * V_225 &&
V_12 -> V_226 == 0 )
goto V_227;
V_12 -> V_210 ++ ;
if ( ( V_12 -> V_226 > 0 ||
V_223 - V_12 -> V_220 < V_191 )
&& F_102 ( V_12 -> V_141 , V_65 ) < V_228 )
V_12 -> V_211 ++ ;
V_12 -> V_212 += F_48 ( V_65 ) ;
if ( F_86 ( V_12 -> V_210 % 32 ) )
V_12 -> V_213 =
F_50 ( T_3 , F_48 ( V_65 ) , V_12 -> V_213 ) ;
else
V_12 -> V_213 = F_48 ( V_65 ) ;
V_12 -> V_217 = V_223 - V_12 -> V_209 ;
if ( V_12 -> V_217 < V_222 )
goto V_224;
V_227:
F_161 ( V_12 , V_65 ) ;
V_224:
V_12 -> V_141 = F_17 ( V_65 ) + F_48 ( V_65 ) ;
V_12 -> V_208 = V_223 ;
}
static void F_165 ( struct V_15 * V_8 , struct V_20 * V_65 )
{
struct V_1 * V_5 = F_85 ( V_65 ) ;
V_5 -> V_126 ++ ;
F_164 ( V_8 -> V_9 -> V_10 , V_65 ) ;
F_103 ( V_8 , V_65 ) ;
}
static void F_166 ( struct V_6 * V_12 , struct V_1 * V_5 )
{
if ( F_167 ( V_5 ) && F_134 ( V_5 ) )
F_168 ( V_5 ) ;
if ( F_27 ( & V_5 -> V_72 ) ) {
if ( V_5 -> V_126 == 0 )
V_5 -> V_127 = V_108 ;
F_107 ( V_12 , V_5 , true ) ;
} else {
F_51 ( V_12 , V_5 ) ;
F_20 ( V_12 , V_5 ) ;
}
F_169 ( V_12 ) ;
}
static void F_170 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
enum V_229 V_230 )
{
struct V_20 * V_44 ;
int V_78 , V_231 ;
V_231 = F_73 ( V_12 ) ;
if ( V_5 -> V_73 == 1 )
V_78 = V_5 -> V_232 ;
else
V_78 = 2 * V_231 ;
F_40 ( V_12 , V_5 , L_18 ,
V_5 -> V_54 . V_78 , F_71 ( V_5 ) ) ;
F_40 ( V_12 , V_5 , L_19 ,
V_78 , F_73 ( V_12 ) ) ;
F_40 ( V_12 , V_5 , L_20 ,
F_47 ( V_5 ) , F_134 ( V_12 -> V_77 ) ) ;
if ( F_47 ( V_5 ) && V_5 -> V_73 == 1 ) {
switch ( V_230 ) {
case V_233 :
if ( V_5 -> V_126 > 0 )
V_78 = F_171 ( V_78 * 2 , V_12 -> F_72 ) ;
else {
if ( V_78 > 5 * V_231 )
V_78 -= 4 * V_231 ;
else
V_78 = V_231 ;
}
break;
case V_234 :
V_78 = F_171 ( V_78 * 2 , V_12 -> F_72 ) ;
break;
case V_235 :
V_78 = F_171 ( V_78 * 4 , V_12 -> F_72 ) ;
break;
case V_236 :
V_78 = F_50 ( int , V_5 -> V_54 . V_109 , V_231 ) ;
break;
default:
return;
}
} else if ( ! F_47 ( V_5 ) ) {
V_78 = V_12 -> F_72 ;
}
V_5 -> V_232 = V_78 ;
if ( V_12 -> V_110 >= V_111 &&
! V_12 -> V_198 )
V_5 -> V_232 = F_171 ( V_5 -> V_232 , V_12 -> F_72 ) ;
V_44 = V_5 -> V_44 ;
if ( V_44 )
V_5 -> V_54 . V_78 = F_50 (unsigned long, bfqq->max_budget,
bfq_serv_to_charge(next_rq, bfqq)) ;
F_40 ( V_12 , V_5 , L_21 ,
V_44 ? F_48 ( V_44 ) : 0 ,
V_5 -> V_54 . V_78 ) ;
}
static bool F_172 ( struct V_6 * V_12 , struct V_1 * V_5 ,
bool V_237 , enum V_229 V_230 ,
unsigned long * V_238 )
{
T_4 V_239 ;
T_3 V_240 ;
bool V_241 = F_134 ( V_5 ) ;
if ( ! F_47 ( V_5 ) )
return false ;
if ( V_237 )
V_239 = V_12 -> V_192 ;
else
V_239 = F_144 () ;
V_239 = F_173 ( V_239 , V_12 -> V_188 ) ;
V_240 = F_174 ( V_239 ) ;
if ( V_240 < 1000 ) {
if ( F_159 ( V_12 -> V_19 ) )
* V_238 = V_191 / V_225 ;
else
* V_238 = V_132 / V_225 ;
return V_241 ;
}
* V_238 = V_240 / V_195 ;
if ( V_240 > 20000 ) {
V_241 = V_5 -> V_54 . V_109 < V_12 -> F_72 / 2 ;
}
F_40 ( V_12 , V_5 , L_22 , V_241 ) ;
return V_241 ;
}
static unsigned long F_175 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
return F_176 ( V_5 -> V_138 +
V_242 * V_5 -> V_139 /
V_12 -> V_133 ,
V_108 + F_177 ( V_5 -> V_12 -> V_132 ) + 4 ) ;
}
static unsigned long F_178 ( void )
{
return V_108 + V_243 ;
}
static unsigned long F_179 ( void )
{
return V_108 - V_243 ;
}
void F_95 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
bool V_237 ,
enum V_229 V_230 )
{
bool V_241 ;
unsigned long V_244 = 0 ;
struct V_53 * V_54 = & V_5 -> V_54 ;
int V_91 ;
V_241 = F_172 ( V_12 , V_5 , V_237 , V_230 , & V_244 ) ;
V_5 -> V_139 += V_54 -> V_109 ;
if ( V_5 -> V_73 == 1 &&
( V_241 ||
( V_230 == V_234 &&
F_71 ( V_5 ) >= V_54 -> V_78 / 3 ) ) )
F_180 ( V_12 , V_5 , V_244 ) ;
if ( V_230 == V_233 &&
V_54 -> V_109 <= 2 * V_54 -> V_78 / 10 )
F_56 ( V_5 ) ;
if ( V_12 -> V_135 && V_5 -> V_73 == 1 )
V_5 -> V_86 = V_108 ;
if ( V_12 -> V_135 && V_12 -> V_133 > 0 &&
F_27 ( & V_5 -> V_72 ) ) {
if ( V_5 -> V_126 == 0 )
V_5 -> V_134 =
F_175 ( V_12 , V_5 ) ;
else {
V_5 -> V_134 =
F_178 () ;
F_181 ( V_5 ) ;
}
}
F_40 ( V_12 , V_5 ,
L_23 , V_230 ,
V_241 , V_5 -> V_126 , F_138 ( V_5 ) ) ;
F_170 ( V_12 , V_5 , V_230 ) ;
V_91 = V_5 -> V_91 ;
F_166 ( V_12 , V_5 ) ;
if ( V_91 > 1 && ! F_98 ( V_5 ) &&
V_230 != V_234 &&
V_230 != V_235 )
F_182 ( V_5 ) ;
}
static bool F_183 ( struct V_1 * V_5 )
{
return F_184 ( V_5 -> V_127 ) ;
}
static bool F_185 ( struct V_1 * V_5 )
{
F_40 ( V_5 -> V_12 , V_5 ,
L_24 ,
F_186 ( V_5 ) ,
F_71 ( V_5 ) >= V_5 -> V_54 . V_78 / 3 ,
F_183 ( V_5 ) ) ;
return ( ! F_186 ( V_5 ) ||
F_71 ( V_5 ) >= V_5 -> V_54 . V_78 / 3 )
&&
F_183 ( V_5 ) ;
}
static bool F_187 ( struct V_1 * V_5 )
{
struct V_6 * V_12 = V_5 -> V_12 ;
bool V_245 , V_246 ,
V_247 ,
V_248 ;
if ( V_12 -> V_249 )
return true ;
V_245 = ! V_12 -> V_250 ||
( ! F_159 ( V_12 -> V_19 ) && F_90 ( V_5 ) &&
F_138 ( V_5 ) ) ;
V_246 = V_245 &&
V_12 -> V_74 == 0 ;
V_248 = V_5 -> V_73 > 1 ||
! F_29 ( V_12 ) ;
V_247 =
V_248 && ! F_57 ( V_5 ) ;
return F_47 ( V_5 ) &&
( V_246 ||
V_247 ) ;
}
static bool F_188 ( struct V_1 * V_5 )
{
struct V_6 * V_12 = V_5 -> V_12 ;
return F_27 ( & V_5 -> V_72 ) && V_12 -> V_132 != 0 &&
F_187 ( V_5 ) ;
}
static struct V_1 * F_189 ( struct V_6 * V_12 )
{
struct V_1 * V_5 ;
struct V_20 * V_44 ;
enum V_229 V_230 = V_234 ;
V_5 = V_12 -> V_77 ;
if ( ! V_5 )
goto V_251;
F_40 ( V_12 , V_5 , L_25 ) ;
if ( F_185 ( V_5 ) &&
! F_186 ( V_5 ) &&
! F_188 ( V_5 ) )
goto V_252;
V_253:
V_44 = V_5 -> V_44 ;
if ( V_44 ) {
if ( F_46 ( V_44 , V_5 ) >
F_71 ( V_5 ) ) {
V_230 = V_235 ;
goto V_252;
} else {
if ( F_186 ( V_5 ) ) {
F_190 ( V_5 ) ;
F_191 ( & V_12 -> V_193 ) ;
F_192 ( F_84 ( V_5 ) ) ;
}
goto V_254;
}
}
if ( F_186 ( V_5 ) ||
( V_5 -> V_126 != 0 && F_187 ( V_5 ) ) ) {
V_5 = NULL ;
goto V_254;
}
V_230 = V_236 ;
V_252:
F_95 ( V_12 , V_5 , false , V_230 ) ;
V_251:
V_5 = F_149 ( V_12 ) ;
if ( V_5 ) {
F_40 ( V_12 , V_5 , L_26 ) ;
goto V_253;
}
V_254:
if ( V_5 )
F_40 ( V_12 , V_5 , L_27 ) ;
else
F_11 ( V_12 , L_28 ) ;
return V_5 ;
}
static void F_193 ( struct V_6 * V_12 , struct V_1 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_54 ;
if ( V_5 -> V_73 > 1 ) {
F_40 ( V_12 , V_5 ,
L_29 ,
F_157 ( V_108 - V_5 -> V_86 ) ,
F_157 ( V_5 -> V_88 ) ,
V_5 -> V_73 ,
V_5 -> V_54 . V_60 , V_5 -> V_54 . V_187 ) ;
if ( V_54 -> V_90 )
F_40 ( V_12 , V_5 , L_30 ) ;
if ( F_57 ( V_5 ) )
F_123 ( V_5 ) ;
else if ( F_58 ( V_5 -> V_86 +
V_5 -> V_88 ) ) {
if ( V_5 -> V_88 != V_12 -> V_125 ||
F_58 ( V_5 -> V_84 +
F_78 ( V_12 ) ) )
F_123 ( V_5 ) ;
else {
V_5 -> V_73 = V_12 -> V_123 ;
V_5 -> V_88 = F_78 ( V_12 ) ;
V_5 -> V_86 =
V_5 -> V_84 ;
V_5 -> V_54 . V_90 = 1 ;
}
}
}
if ( ( V_54 -> V_60 > V_54 -> V_187 ) != ( V_5 -> V_73 > 1 ) )
F_194 (
F_195 ( V_54 ) ,
V_54 ) ;
}
static struct V_20 * F_196 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
struct V_20 * V_65 = V_5 -> V_44 ;
unsigned long V_255 ;
V_255 = F_46 ( V_65 , V_5 ) ;
F_197 ( V_5 , V_255 ) ;
F_165 ( V_12 -> V_19 , V_65 ) ;
F_193 ( V_12 , V_5 ) ;
if ( V_12 -> V_182 > 1 && F_22 ( V_5 ) )
goto V_252;
return V_65 ;
V_252:
F_95 ( V_12 , V_5 , false , V_235 ) ;
return V_65 ;
}
static bool F_198 ( struct V_150 * V_151 )
{
struct V_6 * V_12 = V_151 -> V_19 -> V_9 -> V_10 ;
return ! F_199 ( & V_12 -> V_256 ) ||
V_12 -> V_182 > 0 ;
}
static struct V_20 * F_200 ( struct V_150 * V_151 )
{
struct V_6 * V_12 = V_151 -> V_19 -> V_9 -> V_10 ;
struct V_20 * V_65 = NULL ;
struct V_1 * V_5 = NULL ;
if ( ! F_120 ( & V_12 -> V_256 ) ) {
V_65 = F_201 ( & V_12 -> V_256 , struct V_20 ,
V_147 ) ;
F_104 ( & V_65 -> V_147 ) ;
V_5 = F_85 ( V_65 ) ;
if ( V_5 ) {
V_5 -> V_126 ++ ;
goto V_257;
}
goto V_258;
}
F_11 ( V_12 , L_31 , V_12 -> V_182 ) ;
if ( V_12 -> V_182 == 0 )
goto exit;
if ( V_12 -> V_249 && V_12 -> V_226 > 0 )
goto exit;
V_5 = F_189 ( V_12 ) ;
if ( ! V_5 )
goto exit;
V_65 = F_196 ( V_12 , V_5 ) ;
if ( V_65 ) {
V_257:
V_12 -> V_226 ++ ;
V_258:
V_65 -> V_259 |= V_260 ;
}
exit:
return V_65 ;
}
static struct V_20 * F_202 ( struct V_150 * V_151 )
{
struct V_6 * V_12 = V_151 -> V_19 -> V_9 -> V_10 ;
struct V_20 * V_65 ;
F_110 ( & V_12 -> V_154 ) ;
V_65 = F_200 ( V_151 ) ;
F_114 ( & V_12 -> V_154 ) ;
return V_65 ;
}
void F_141 ( struct V_1 * V_5 )
{
#ifdef F_28
struct V_163 * V_164 = F_84 ( V_5 ) ;
#endif
if ( V_5 -> V_12 )
F_40 ( V_5 -> V_12 , V_5 , L_32 ,
V_5 , V_5 -> V_91 ) ;
V_5 -> V_91 -- ;
if ( V_5 -> V_91 )
return;
if ( F_47 ( V_5 ) )
F_62 ( & V_5 -> V_96 ) ;
F_203 ( V_261 , V_5 ) ;
#ifdef F_28
F_204 ( V_164 ) ;
#endif
}
static void F_205 ( struct V_1 * V_5 )
{
struct V_1 * V_48 , * V_67 ;
V_48 = V_5 -> V_176 ;
while ( V_48 ) {
if ( V_48 == V_5 )
break;
V_67 = V_48 -> V_176 ;
F_141 ( V_48 ) ;
V_48 = V_67 ;
}
}
static void F_206 ( struct V_6 * V_12 , struct V_1 * V_5 )
{
if ( V_5 == V_12 -> V_77 ) {
F_166 ( V_12 , V_5 ) ;
F_10 ( V_12 ) ;
}
F_40 ( V_12 , V_5 , L_33 , V_5 , V_5 -> V_91 ) ;
F_205 ( V_5 ) ;
F_141 ( V_5 ) ;
}
static void F_207 ( struct V_2 * V_3 , bool V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 , V_4 ) ;
struct V_6 * V_12 ;
if ( V_5 )
V_12 = V_5 -> V_12 ;
if ( V_5 && V_12 ) {
unsigned long V_16 ;
F_7 ( & V_12 -> V_154 , V_16 ) ;
F_206 ( V_12 , V_5 ) ;
F_2 ( V_3 , NULL , V_4 ) ;
F_9 ( & V_12 -> V_154 , V_16 ) ;
}
}
static void F_208 ( struct V_11 * V_7 )
{
struct V_2 * V_3 = F_4 ( V_7 ) ;
F_207 ( V_3 , true ) ;
F_207 ( V_3 , false ) ;
}
static void
F_209 ( struct V_1 * V_5 , struct V_2 * V_3 )
{
struct V_262 * V_263 = V_152 ;
int V_179 ;
struct V_6 * V_12 = V_5 -> V_12 ;
if ( ! V_12 )
return;
V_179 = F_210 ( V_3 -> V_264 ) ;
switch ( V_179 ) {
default:
F_211 ( V_5 -> V_12 -> V_19 -> V_265 -> V_266 ,
L_34 , V_179 ) ;
case V_267 :
V_5 -> V_268 = F_212 ( V_263 ) ;
V_5 -> V_269 = F_213 ( V_263 ) ;
break;
case V_270 :
V_5 -> V_268 = F_214 ( V_3 -> V_264 ) ;
V_5 -> V_269 = V_270 ;
break;
case V_271 :
V_5 -> V_268 = F_214 ( V_3 -> V_264 ) ;
V_5 -> V_269 = V_271 ;
break;
case V_272 :
V_5 -> V_269 = V_272 ;
V_5 -> V_268 = 7 ;
F_54 ( V_5 ) ;
break;
}
if ( V_5 -> V_268 >= V_167 ) {
F_215 ( L_35 ,
V_5 -> V_268 ) ;
V_5 -> V_268 = V_167 ;
}
V_5 -> V_54 . V_273 = F_216 ( V_5 -> V_268 ) ;
V_5 -> V_54 . V_90 = 1 ;
}
static void F_217 ( struct V_2 * V_3 , struct V_143 * V_143 )
{
struct V_6 * V_12 = F_3 ( V_3 ) ;
struct V_1 * V_5 ;
int V_264 = V_3 -> V_7 . V_14 -> V_264 ;
if ( F_32 ( ! V_12 ) || F_86 ( V_3 -> V_264 == V_264 ) )
return;
V_3 -> V_264 = V_264 ;
V_5 = F_1 ( V_3 , false ) ;
if ( V_5 ) {
F_141 ( V_5 ) ;
V_5 = F_218 ( V_12 , V_143 , V_274 , V_3 ) ;
F_2 ( V_3 , V_5 , false ) ;
}
V_5 = F_1 ( V_3 , true ) ;
if ( V_5 )
F_209 ( V_5 , V_3 ) ;
}
static void F_219 ( struct V_6 * V_12 , struct V_1 * V_5 ,
struct V_2 * V_3 , T_5 V_47 , int V_4 )
{
F_220 ( & V_5 -> V_54 . V_37 ) ;
F_221 ( & V_5 -> V_66 ) ;
F_222 ( & V_5 -> V_96 ) ;
V_5 -> V_91 = 0 ;
V_5 -> V_12 = V_12 ;
if ( V_3 )
F_209 ( V_5 , V_3 ) ;
if ( V_4 ) {
if ( ! F_22 ( V_5 ) )
F_53 ( V_5 ) ;
F_223 ( V_5 ) ;
F_224 ( V_5 ) ;
} else
F_225 ( V_5 ) ;
V_5 -> V_81 . V_131 = F_39 () + 1 ;
F_55 ( V_5 ) ;
V_5 -> V_47 = V_47 ;
V_5 -> V_232 = ( 2 * F_72 ( V_12 ) ) / 3 ;
V_5 -> V_127 = F_179 () ;
V_5 -> V_73 = 1 ;
V_5 -> V_86 = V_108 ;
V_5 -> V_84 = F_179 () ;
V_5 -> V_104 = F_179 () ;
V_5 -> V_134 = F_178 () ;
V_5 -> V_275 = 1 ;
}
static struct V_1 * * F_226 ( struct V_6 * V_12 ,
struct V_163 * V_164 ,
int V_179 , int V_264 )
{
switch ( V_179 ) {
case V_270 :
return & V_164 -> V_168 [ 0 ] [ V_264 ] ;
case V_267 :
V_264 = V_276 ;
case V_271 :
return & V_164 -> V_168 [ 1 ] [ V_264 ] ;
case V_272 :
return & V_164 -> V_169 ;
default:
return NULL ;
}
}
static struct V_1 * F_218 ( struct V_6 * V_12 ,
struct V_143 * V_143 , bool V_4 ,
struct V_2 * V_3 )
{
const int V_264 = F_214 ( V_3 -> V_264 ) ;
const int V_179 = F_210 ( V_3 -> V_264 ) ;
struct V_1 * * V_168 = NULL ;
struct V_1 * V_5 ;
struct V_163 * V_164 ;
F_227 () ;
V_164 = F_228 ( V_12 , F_229 ( V_143 ) ) ;
if ( ! V_164 ) {
V_5 = & V_12 -> V_181 ;
goto V_277;
}
if ( ! V_4 ) {
V_168 = F_226 ( V_12 , V_164 , V_179 ,
V_264 ) ;
V_5 = * V_168 ;
if ( V_5 )
goto V_277;
}
V_5 = F_230 ( V_261 ,
V_278 | V_279 | V_280 ,
V_12 -> V_19 -> V_174 ) ;
if ( V_5 ) {
F_219 ( V_12 , V_5 , V_3 , V_152 -> V_47 ,
V_4 ) ;
F_231 ( & V_5 -> V_54 , V_164 ) ;
F_40 ( V_12 , V_5 , L_36 ) ;
} else {
V_5 = & V_12 -> V_181 ;
F_40 ( V_12 , V_5 , L_37 ) ;
goto V_277;
}
if ( V_168 ) {
V_5 -> V_91 ++ ;
F_40 ( V_12 , V_5 , L_38 ,
V_5 , V_5 -> V_91 ) ;
* V_168 = V_5 ;
}
V_277:
V_5 -> V_91 ++ ;
F_40 ( V_12 , V_5 , L_39 , V_5 , V_5 -> V_91 ) ;
F_232 () ;
return V_5 ;
}
static void F_233 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
struct V_281 * V_81 = & V_5 -> V_81 ;
T_2 V_282 = F_39 () - V_5 -> V_81 . V_131 ;
V_282 = F_76 ( T_2 , V_282 , 2ULL * V_12 -> V_132 ) ;
V_81 -> V_283 = ( 7 * V_5 -> V_81 . V_283 + 256 ) / 8 ;
V_81 -> V_284 = F_163 ( 7 * V_81 -> V_284 + 256 * V_282 , 8 ) ;
V_81 -> V_285 = F_162 ( V_81 -> V_284 + 128 ,
V_81 -> V_283 ) ;
}
static void
F_234 ( struct V_6 * V_12 , struct V_1 * V_5 ,
struct V_20 * V_65 )
{
V_5 -> V_275 <<= 1 ;
V_5 -> V_275 |=
F_102 ( V_5 -> V_286 , V_65 ) > V_228 &&
( ! F_159 ( V_12 -> V_19 ) ||
F_48 ( V_65 ) < V_287 ) ;
}
static void F_235 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
struct V_2 * V_3 )
{
int V_288 ;
if ( ! F_47 ( V_5 ) || F_22 ( V_5 ) )
return;
if ( F_69 ( V_5 -> V_104 +
V_12 -> V_128 ) )
return;
V_288 = F_138 ( V_5 ) ;
if ( F_236 ( & V_3 -> V_7 . V_14 -> V_289 ) == 0 ||
V_12 -> V_132 == 0 ||
( V_12 -> V_250 && F_134 ( V_5 ) &&
V_5 -> V_73 == 1 ) )
V_288 = 0 ;
else if ( F_237 ( V_5 -> V_81 . V_283 ) ) {
if ( V_5 -> V_81 . V_285 > V_12 -> V_132 &&
V_5 -> V_73 == 1 )
V_288 = 0 ;
else
V_288 = 1 ;
}
F_40 ( V_12 , V_5 , L_40 ,
V_288 ) ;
if ( V_288 )
F_53 ( V_5 ) ;
else
F_54 ( V_5 ) ;
}
static void F_238 ( struct V_6 * V_12 , struct V_1 * V_5 ,
struct V_20 * V_65 )
{
struct V_2 * V_3 = F_239 ( V_65 ) ;
if ( V_65 -> V_30 & V_31 )
V_5 -> V_149 ++ ;
F_233 ( V_12 , V_5 ) ;
F_234 ( V_12 , V_5 , V_65 ) ;
if ( V_5 -> V_54 . V_109 > F_72 ( V_12 ) / 8 ||
! F_134 ( V_5 ) )
F_235 ( V_12 , V_5 , V_3 ) ;
F_40 ( V_12 , V_5 ,
L_41 ,
F_138 ( V_5 ) , F_134 ( V_5 ) ) ;
V_5 -> V_286 = F_17 ( V_65 ) + F_48 ( V_65 ) ;
if ( V_5 == V_12 -> V_77 && F_186 ( V_5 ) ) {
bool V_290 = V_5 -> V_18 [ F_16 ( V_65 ) ] == 1 &&
F_48 ( V_65 ) < 32 ;
bool V_127 = F_183 ( V_5 ) ;
if ( V_290 && ! V_127 )
return;
F_190 ( V_5 ) ;
F_191 ( & V_12 -> V_193 ) ;
F_192 ( F_84 ( V_5 ) ) ;
if ( V_127 )
F_95 ( V_12 , V_5 , false ,
V_234 ) ;
}
}
static void F_240 ( struct V_6 * V_12 , struct V_20 * V_65 )
{
struct V_1 * V_5 = F_85 ( V_65 ) ,
* V_176 = F_136 ( V_12 , V_5 , V_65 , true ) ;
if ( V_176 ) {
if ( F_1 ( F_239 ( V_65 ) , 1 ) != V_5 )
V_176 = F_1 ( F_239 ( V_65 ) , 1 ) ;
V_176 -> V_92 ++ ;
V_5 -> V_92 -- ;
V_176 -> V_91 ++ ;
F_89 ( V_5 ) ;
if ( F_1 ( F_239 ( V_65 ) , 1 ) == V_5 )
F_139 ( V_12 , F_239 ( V_65 ) ,
V_5 , V_176 ) ;
F_141 ( V_5 ) ;
V_65 -> V_291 . V_292 [ 1 ] = V_176 ;
V_5 = V_176 ;
}
F_96 ( V_65 ) ;
V_65 -> V_68 = F_39 () + V_12 -> V_293 [ F_16 ( V_65 ) ] ;
F_241 ( & V_65 -> V_147 , & V_5 -> V_66 ) ;
F_238 ( V_12 , V_5 , V_65 ) ;
}
static void F_242 ( struct V_150 * V_151 , struct V_20 * V_65 ,
bool V_294 )
{
struct V_15 * V_8 = V_151 -> V_19 ;
struct V_6 * V_12 = V_8 -> V_9 -> V_10 ;
F_110 ( & V_12 -> V_154 ) ;
if ( F_243 ( V_8 , V_65 ) ) {
F_114 ( & V_12 -> V_154 ) ;
return;
}
F_114 ( & V_12 -> V_154 ) ;
F_244 ( V_65 ) ;
F_110 ( & V_12 -> V_154 ) ;
if ( V_294 || F_245 ( V_65 ) ) {
if ( V_294 )
F_246 ( & V_65 -> V_147 , & V_12 -> V_256 ) ;
else
F_241 ( & V_65 -> V_147 , & V_12 -> V_256 ) ;
} else {
F_240 ( V_12 , V_65 ) ;
if ( F_247 ( V_65 ) ) {
F_248 ( V_8 , V_65 ) ;
if ( ! V_8 -> V_148 )
V_8 -> V_148 = V_65 ;
}
}
F_114 ( & V_12 -> V_154 ) ;
}
static void F_249 ( struct V_150 * V_151 ,
struct V_295 * V_296 , bool V_294 )
{
while ( ! F_120 ( V_296 ) ) {
struct V_20 * V_65 ;
V_65 = F_201 ( V_296 , struct V_20 , V_147 ) ;
F_104 ( & V_65 -> V_147 ) ;
F_242 ( V_151 , V_65 , V_294 ) ;
}
}
static void F_250 ( struct V_6 * V_12 )
{
V_12 -> V_297 = F_50 ( int , V_12 -> V_297 ,
V_12 -> V_226 ) ;
if ( V_12 -> V_250 == 1 )
return;
if ( V_12 -> V_226 + V_12 -> V_18 < V_298 )
return;
if ( V_12 -> V_299 ++ < V_300 )
return;
V_12 -> V_250 = V_12 -> V_297 > V_298 ;
V_12 -> V_297 = 0 ;
V_12 -> V_299 = 0 ;
}
static void F_251 ( struct V_1 * V_5 , struct V_6 * V_12 )
{
T_2 V_223 ;
T_3 V_301 ;
F_250 ( V_12 ) ;
V_12 -> V_226 -- ;
V_5 -> V_126 -- ;
if ( ! V_5 -> V_126 && ! F_98 ( V_5 ) ) {
V_5 -> V_127 = V_108 ;
F_33 ( V_12 , & V_5 -> V_54 ,
& V_12 -> V_51 ) ;
}
V_223 = F_39 () ;
V_5 -> V_81 . V_131 = V_223 ;
V_301 = F_163 ( V_223 - V_12 -> V_220 , V_221 ) ;
if ( V_301 > V_191 / V_221 &&
( V_12 -> V_213 << V_196 ) / V_301 <
1UL << ( V_196 - 10 ) )
F_161 ( V_12 , NULL ) ;
V_12 -> V_220 = V_223 ;
if ( F_252 ( V_5 ) && V_5 -> V_126 == 0 &&
F_27 ( & V_5 -> V_72 ) )
V_5 -> V_134 =
F_175 ( V_12 , V_5 ) ;
if ( V_12 -> V_77 == V_5 ) {
if ( V_5 -> V_126 == 0 && F_188 ( V_5 ) ) {
F_151 ( V_12 ) ;
return;
} else if ( F_185 ( V_5 ) )
F_95 ( V_12 , V_5 , false ,
V_234 ) ;
else if ( F_27 ( & V_5 -> V_72 ) &&
( V_5 -> V_126 == 0 ||
! F_187 ( V_5 ) ) )
F_95 ( V_12 , V_5 , false ,
V_236 ) ;
}
}
static void F_253 ( struct V_1 * V_5 )
{
V_5 -> V_92 -- ;
F_141 ( V_5 ) ;
}
static void F_254 ( struct V_15 * V_8 , struct V_20 * V_65 )
{
struct V_1 * V_5 = F_85 ( V_65 ) ;
struct V_6 * V_12 = V_5 -> V_12 ;
if ( V_65 -> V_259 & V_260 )
F_255 ( F_84 ( V_5 ) ,
F_256 ( V_65 ) ,
F_257 ( V_65 ) ,
V_65 -> V_30 ) ;
if ( F_86 ( V_65 -> V_259 & V_260 ) ) {
unsigned long V_16 ;
F_7 ( & V_12 -> V_154 , V_16 ) ;
F_251 ( V_5 , V_12 ) ;
F_253 ( V_5 ) ;
F_9 ( & V_12 -> V_154 , V_16 ) ;
} else {
if ( ! F_119 ( & V_65 -> V_37 ) )
F_103 ( V_8 , V_65 ) ;
F_253 ( V_5 ) ;
}
V_65 -> V_291 . V_292 [ 0 ] = NULL ;
V_65 -> V_291 . V_292 [ 1 ] = NULL ;
}
static struct V_1 *
F_258 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
F_40 ( V_5 -> V_12 , V_5 , L_42 ) ;
if ( F_59 ( V_5 ) == 1 ) {
V_5 -> V_47 = V_152 -> V_47 ;
F_259 ( V_5 ) ;
F_260 ( V_5 ) ;
return V_5 ;
}
F_2 ( V_3 , NULL , 1 ) ;
F_205 ( V_5 ) ;
F_141 ( V_5 ) ;
return NULL ;
}
static struct V_1 * F_261 ( struct V_6 * V_12 ,
struct V_2 * V_3 ,
struct V_143 * V_143 ,
bool V_302 , bool V_4 ,
bool * V_251 )
{
struct V_1 * V_5 = F_1 ( V_3 , V_4 ) ;
if ( F_86 ( V_5 && V_5 != & V_12 -> V_181 ) )
return V_5 ;
if ( V_251 )
* V_251 = true ;
if ( V_5 )
F_141 ( V_5 ) ;
V_5 = F_218 ( V_12 , V_143 , V_4 , V_3 ) ;
F_2 ( V_3 , V_5 , V_4 ) ;
if ( V_302 && V_4 ) {
if ( ( V_3 -> V_185 && V_12 -> V_103 ) ||
V_3 -> V_184 )
F_66 ( V_5 ) ;
else {
F_88 ( V_5 ) ;
if ( V_3 -> V_185 )
F_63 ( & V_5 -> V_96 ,
& V_12 -> V_97 ) ;
}
V_5 -> V_104 = V_108 ;
}
return V_5 ;
}
static int F_262 ( struct V_15 * V_8 , struct V_20 * V_65 ,
struct V_143 * V_143 )
{
struct V_6 * V_12 = V_8 -> V_9 -> V_10 ;
struct V_2 * V_3 = F_4 ( V_65 -> V_291 . V_7 ) ;
const int V_4 = F_16 ( V_65 ) ;
struct V_1 * V_5 ;
bool V_251 = false ;
bool V_302 = false ;
F_110 ( & V_12 -> V_154 ) ;
if ( ! V_3 )
goto V_303;
F_217 ( V_3 , V_143 ) ;
F_263 ( V_3 , V_143 ) ;
V_5 = F_261 ( V_12 , V_3 , V_143 , false , V_4 ,
& V_251 ) ;
if ( F_86 ( ! V_251 ) ) {
if ( F_167 ( V_5 ) && F_264 ( V_5 ) ) {
F_40 ( V_12 , V_5 , L_43 ) ;
if ( F_57 ( V_5 ) )
V_3 -> V_184 = true ;
V_5 = F_258 ( V_3 , V_5 ) ;
V_302 = true ;
if ( ! V_5 )
V_5 = F_261 ( V_12 , V_3 , V_143 ,
true , V_4 ,
NULL ) ;
}
}
V_5 -> V_92 ++ ;
V_5 -> V_91 ++ ;
F_40 ( V_12 , V_5 , L_44 ,
V_65 , V_5 , V_5 -> V_91 ) ;
V_65 -> V_291 . V_292 [ 0 ] = V_3 ;
V_65 -> V_291 . V_292 [ 1 ] = V_5 ;
if ( F_86 ( V_5 != & V_12 -> V_181 ) && F_59 ( V_5 ) == 1 ) {
V_5 -> V_3 = V_3 ;
if ( V_302 ) {
F_52 ( V_5 , V_3 ) ;
}
}
if ( F_32 ( F_87 ( V_5 ) ) )
F_67 ( V_12 , V_5 ) ;
F_114 ( & V_12 -> V_154 ) ;
return 0 ;
V_303:
F_114 ( & V_12 -> V_154 ) ;
return 1 ;
}
static void F_265 ( struct V_1 * V_5 )
{
struct V_6 * V_12 = V_5 -> V_12 ;
enum V_229 V_230 ;
unsigned long V_16 ;
F_7 ( & V_12 -> V_154 , V_16 ) ;
F_190 ( V_5 ) ;
if ( V_5 != V_12 -> V_77 ) {
F_9 ( & V_12 -> V_154 , V_16 ) ;
return;
}
if ( F_183 ( V_5 ) )
V_230 = V_234 ;
else if ( V_5 -> V_18 [ 0 ] == 0 && V_5 -> V_18 [ 1 ] == 0 )
V_230 = V_233 ;
else
goto V_304;
F_95 ( V_12 , V_5 , true , V_230 ) ;
V_304:
F_9 ( & V_12 -> V_154 , V_16 ) ;
F_10 ( V_12 ) ;
}
static enum V_305 F_266 ( struct V_306 * V_307 )
{
struct V_6 * V_12 = F_5 ( V_307 , struct V_6 ,
V_193 ) ;
struct V_1 * V_5 = V_12 -> V_77 ;
if ( V_5 )
F_265 ( V_5 ) ;
return V_308 ;
}
static void F_267 ( struct V_6 * V_12 ,
struct V_1 * * V_309 )
{
struct V_1 * V_5 = * V_309 ;
F_11 ( V_12 , L_45 , V_5 ) ;
if ( V_5 ) {
F_268 ( V_12 , V_5 , V_12 -> V_310 ) ;
F_40 ( V_12 , V_5 , L_46 ,
V_5 , V_5 -> V_91 ) ;
F_141 ( V_5 ) ;
* V_309 = NULL ;
}
}
void F_269 ( struct V_6 * V_12 , struct V_163 * V_164 )
{
int V_165 , V_166 ;
for ( V_165 = 0 ; V_165 < 2 ; V_165 ++ )
for ( V_166 = 0 ; V_166 < V_167 ; V_166 ++ )
F_267 ( V_12 , & V_164 -> V_168 [ V_165 ] [ V_166 ] ) ;
F_267 ( V_12 , & V_164 -> V_169 ) ;
}
static void F_270 ( struct V_311 * V_312 )
{
struct V_6 * V_12 = V_312 -> V_10 ;
struct V_1 * V_5 , * V_42 ;
F_271 ( & V_12 -> V_193 ) ;
F_110 ( & V_12 -> V_154 ) ;
F_272 (bfqq, n, &bfqd->idle_list, bfqq_list)
F_273 ( V_12 , V_5 , false , false ) ;
F_114 ( & V_12 -> V_154 ) ;
F_271 ( & V_12 -> V_193 ) ;
#ifdef F_28
F_274 ( V_12 -> V_19 , & V_313 ) ;
#else
F_110 ( & V_12 -> V_154 ) ;
F_269 ( V_12 , V_12 -> V_310 ) ;
F_34 ( V_12 -> V_310 ) ;
F_114 ( & V_12 -> V_154 ) ;
#endif
F_34 ( V_12 ) ;
}
static void F_275 ( struct V_163 * V_310 ,
struct V_6 * V_12 )
{
int V_165 ;
#ifdef F_28
V_310 -> V_54 . V_41 = NULL ;
V_310 -> V_314 = NULL ;
V_310 -> V_12 = V_12 ;
#endif
V_310 -> V_50 = V_315 ;
for ( V_165 = 0 ; V_165 < V_316 ; V_165 ++ )
V_310 -> V_317 . V_318 [ V_165 ] = V_319 ;
V_310 -> V_317 . V_320 = V_108 ;
}
static int F_276 ( struct V_15 * V_8 , struct V_321 * V_312 )
{
struct V_6 * V_12 ;
struct V_311 * V_322 ;
V_322 = F_277 ( V_8 , V_312 ) ;
if ( ! V_322 )
return - V_323 ;
V_12 = F_278 ( sizeof( * V_12 ) , V_324 , V_8 -> V_174 ) ;
if ( ! V_12 ) {
F_279 ( & V_322 -> V_325 ) ;
return - V_323 ;
}
V_322 -> V_10 = V_12 ;
F_110 ( V_8 -> V_17 ) ;
V_8 -> V_9 = V_322 ;
F_114 ( V_8 -> V_17 ) ;
F_219 ( V_12 , & V_12 -> V_181 , NULL , 1 , 0 ) ;
V_12 -> V_181 . V_91 ++ ;
V_12 -> V_181 . V_268 = V_326 ;
V_12 -> V_181 . V_269 = V_271 ;
V_12 -> V_181 . V_54 . V_273 =
F_216 ( V_12 -> V_181 . V_268 ) ;
F_89 ( & V_12 -> V_181 ) ;
V_12 -> V_181 . V_54 . V_90 = 1 ;
V_12 -> V_19 = V_8 ;
F_221 ( & V_12 -> V_256 ) ;
F_280 ( & V_12 -> V_193 , V_327 ,
V_194 ) ;
V_12 -> V_193 . V_328 = F_266 ;
V_12 -> V_51 = V_315 ;
V_12 -> V_52 = V_315 ;
F_221 ( & V_12 -> V_329 ) ;
F_221 ( & V_12 -> V_330 ) ;
F_281 ( & V_12 -> V_97 ) ;
V_12 -> V_250 = - 1 ;
V_12 -> F_72 = V_112 ;
V_12 -> V_293 [ 0 ] = V_293 [ 0 ] ;
V_12 -> V_293 [ 1 ] = V_293 [ 1 ] ;
V_12 -> V_32 = V_32 ;
V_12 -> V_33 = V_33 ;
V_12 -> V_132 = V_132 ;
V_12 -> V_189 = V_189 ;
V_12 -> V_137 = 120 ;
V_12 -> V_100 = 8 ;
V_12 -> V_106 = F_70 ( 180 ) ;
V_12 -> V_135 = true ;
V_12 -> V_123 = 30 ;
V_12 -> V_125 = F_70 ( 300 ) ;
V_12 -> V_116 = 0 ;
V_12 -> V_128 = F_70 ( 2000 ) ;
V_12 -> V_142 = F_70 ( 500 ) ;
V_12 -> V_133 = 7000 ;
V_12 -> V_74 = 0 ;
V_12 -> V_117 = V_205 [ F_159 ( V_12 -> V_19 ) ] *
V_206 [ F_159 ( V_12 -> V_19 ) ] ;
V_12 -> V_118 = V_205 [ F_159 ( V_12 -> V_19 ) ] * 2 / 3 ;
V_12 -> V_199 = V_200 ;
F_282 ( & V_12 -> V_154 ) ;
V_12 -> V_310 = F_283 ( V_12 , V_8 -> V_174 ) ;
if ( ! V_12 -> V_310 )
goto V_331;
F_275 ( V_12 -> V_310 , V_12 ) ;
F_231 ( & V_12 -> V_181 . V_54 , V_12 -> V_310 ) ;
return 0 ;
V_331:
F_34 ( V_12 ) ;
F_279 ( & V_322 -> V_325 ) ;
return - V_323 ;
}
static void F_284 ( void )
{
F_285 ( V_261 ) ;
}
static int T_6 F_286 ( void )
{
V_261 = F_287 ( V_1 , 0 ) ;
if ( ! V_261 )
return - V_323 ;
return 0 ;
}
static T_7 F_288 ( unsigned int V_332 , char * V_333 )
{
return sprintf ( V_333 , L_47 , V_332 ) ;
}
static T_7 F_289 ( unsigned long * V_332 , const char * V_333 ,
T_8 V_334 )
{
unsigned long V_335 ;
int V_153 = F_290 ( V_333 , 10 , & V_335 ) ;
if ( V_153 == 0 )
* V_332 = V_335 ;
return V_334 ;
}
static T_7 F_291 ( struct V_311 * V_312 ,
const char * V_333 , T_8 V_334 )
{
struct V_6 * V_12 = V_312 -> V_10 ;
unsigned long V_336 ( V_337 ) ;
int V_153 = F_289 ( & V_337 , ( V_333 ) , V_334 ) ;
if ( V_337 == 0 )
V_12 -> F_72 = F_156 ( V_12 ) ;
else {
if ( V_337 > V_338 )
V_337 = V_338 ;
V_12 -> F_72 = V_337 ;
}
V_12 -> V_198 = V_337 ;
return V_153 ;
}
static T_7 F_292 ( struct V_311 * V_312 ,
const char * V_333 , T_8 V_334 )
{
struct V_6 * V_12 = V_312 -> V_10 ;
unsigned long V_336 ( V_337 ) ;
int V_153 = F_289 ( & V_337 , ( V_333 ) , V_334 ) ;
if ( V_337 < 1 )
V_337 = 1 ;
else if ( V_337 > V_338 )
V_337 = V_338 ;
V_12 -> V_189 = F_70 ( V_337 ) ;
if ( V_12 -> V_198 == 0 )
V_12 -> F_72 = F_156 ( V_12 ) ;
return V_153 ;
}
static T_7 F_293 ( struct V_311 * V_312 ,
const char * V_333 , T_8 V_334 )
{
struct V_6 * V_12 = V_312 -> V_10 ;
unsigned long V_336 ( V_337 ) ;
int V_153 = F_289 ( & V_337 , ( V_333 ) , V_334 ) ;
if ( V_337 > 1 )
V_337 = 1 ;
if ( ! V_12 -> V_249 && V_337 == 1
&& V_12 -> V_132 < 8 * V_225 )
V_12 -> V_132 = 8 * V_225 ;
V_12 -> V_249 = V_337 ;
return V_153 ;
}
static T_7 F_294 ( struct V_311 * V_312 ,
const char * V_333 , T_8 V_334 )
{
struct V_6 * V_12 = V_312 -> V_10 ;
unsigned long V_336 ( V_337 ) ;
int V_153 = F_289 ( & V_337 , ( V_333 ) , V_334 ) ;
if ( V_337 > 1 )
V_337 = 1 ;
if ( V_337 == 0 && V_12 -> V_135 != 0 )
F_125 ( V_12 ) ;
V_12 -> V_135 = V_337 ;
return V_153 ;
}
static int T_6 F_295 ( void )
{
int V_153 ;
#ifdef F_28
V_153 = F_296 ( & V_313 ) ;
if ( V_153 )
return V_153 ;
#endif
V_153 = - V_323 ;
if ( F_286 () )
goto V_339;
V_204 [ 0 ] = F_70 ( 3500 ) ;
V_204 [ 1 ] = F_70 ( 6000 ) ;
V_206 [ 0 ] = F_70 ( 7000 ) ;
V_206 [ 1 ] = F_70 ( 2500 ) ;
V_201 [ 0 ] = ( 4 * V_203 [ 0 ] ) / 3 ;
V_201 [ 1 ] = ( 4 * V_203 [ 1 ] ) / 3 ;
V_153 = F_297 ( & V_340 ) ;
if ( V_153 )
goto V_339;
return 0 ;
V_339:
#ifdef F_28
F_298 ( & V_313 ) ;
#endif
return V_153 ;
}
static void T_9 F_299 ( void )
{
F_300 ( & V_340 ) ;
#ifdef F_28
F_298 ( & V_313 ) ;
#endif
F_284 () ;
}
