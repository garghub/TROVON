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
F_52 ( struct V_1 * V_5 , struct V_6 * V_12 ,
struct V_2 * V_3 , bool V_79 )
{
unsigned int V_80 = V_5 -> V_73 ;
bool V_81 = V_79 && F_53 ( V_5 ) ;
if ( V_3 -> V_82 )
F_54 ( V_5 ) ;
else
F_55 ( V_5 ) ;
if ( V_3 -> V_83 )
F_56 ( V_5 ) ;
else
F_57 ( V_5 ) ;
V_5 -> V_84 = V_3 -> V_85 ;
V_5 -> V_73 = V_3 -> V_86 ;
V_5 -> V_87 = V_3 -> V_88 ;
V_5 -> V_89 = V_3 -> V_90 ;
V_5 -> V_91 = V_3 -> V_92 ;
if ( V_5 -> V_73 > 1 && ( F_58 ( V_5 ) ||
F_59 ( V_5 -> V_89 +
V_5 -> V_91 ) ) ) {
F_40 ( V_5 -> V_12 , V_5 ,
L_5 ) ;
V_5 -> V_73 = 1 ;
}
V_5 -> V_54 . V_93 = 1 ;
if ( F_60 ( ! V_81 ) )
return;
if ( V_80 == 1 && V_5 -> V_73 > 1 )
V_12 -> V_74 ++ ;
else if ( V_80 > 1 && V_5 -> V_73 == 1 )
V_12 -> V_74 -- ;
}
static int F_61 ( struct V_1 * V_5 )
{
return V_5 -> V_94 - V_5 -> V_95 - V_5 -> V_54 . V_96 ;
}
static void F_62 ( struct V_6 * V_12 , struct V_1 * V_5 )
{
struct V_1 * V_97 ;
struct V_98 * V_42 ;
F_63 (item, n, &bfqd->burst_list, burst_list_node)
F_64 ( & V_97 -> V_99 ) ;
F_65 ( & V_5 -> V_99 , & V_12 -> V_100 ) ;
V_12 -> V_101 = 1 ;
V_12 -> V_102 = V_5 -> V_54 . V_41 ;
}
static void F_66 ( struct V_6 * V_12 , struct V_1 * V_5 )
{
V_12 -> V_101 ++ ;
if ( V_12 -> V_101 == V_12 -> V_103 ) {
struct V_1 * V_104 , * V_105 ;
struct V_98 * V_42 ;
V_12 -> V_106 = true ;
F_67 (bfqq_item, &bfqd->burst_list,
burst_list_node)
F_68 ( V_105 ) ;
F_68 ( V_5 ) ;
F_63 (pos, n, &bfqd->burst_list,
burst_list_node)
F_64 ( & V_104 -> V_99 ) ;
} else
F_65 ( & V_5 -> V_99 , & V_12 -> V_100 ) ;
}
static void F_69 ( struct V_6 * V_12 , struct V_1 * V_5 )
{
if ( ! F_70 ( & V_5 -> V_99 ) ||
F_58 ( V_5 ) ||
F_71 ( V_5 -> V_107 +
F_72 ( 10 ) ) )
return;
if ( F_59 ( V_12 -> V_108 +
V_12 -> V_109 ) ||
V_5 -> V_54 . V_41 != V_12 -> V_102 ) {
V_12 -> V_106 = false ;
F_62 ( V_12 , V_5 ) ;
goto V_110;
}
if ( V_12 -> V_106 ) {
F_68 ( V_5 ) ;
goto V_110;
}
F_66 ( V_12 , V_5 ) ;
V_110:
V_12 -> V_108 = V_111 ;
}
static int F_73 ( struct V_1 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_54 ;
return V_54 -> V_78 - V_54 -> V_112 ;
}
static int F_74 ( struct V_6 * V_12 )
{
if ( V_12 -> V_113 < V_114 )
return V_115 ;
else
return V_12 -> F_74 ;
}
static int F_75 ( struct V_6 * V_12 )
{
if ( V_12 -> V_113 < V_114 )
return V_115 / 32 ;
else
return V_12 -> F_74 / 32 ;
}
static bool F_76 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
bool V_116 ,
bool V_117 )
{
struct V_53 * V_54 = & V_5 -> V_54 ;
if ( F_77 ( V_5 ) && V_116 ) {
V_54 -> V_78 = F_78 (unsigned long,
bfq_bfqq_budget_left(bfqq),
bfqq->max_budget) ;
return true ;
}
V_54 -> V_78 = F_50 (unsigned long, bfqq->max_budget,
bfq_serv_to_charge(bfqq->next_rq, bfqq)) ;
F_79 ( V_5 ) ;
return V_117 ;
}
static unsigned int F_80 ( struct V_6 * V_12 )
{
T_2 V_118 ;
if ( V_12 -> V_119 > 0 )
return V_12 -> V_119 ;
V_118 = V_12 -> V_120 ;
F_81 ( V_118 , V_12 -> V_121 ) ;
if ( V_118 > F_72 ( 13000 ) )
V_118 = F_72 ( 13000 ) ;
else if ( V_118 < F_72 ( 3000 ) )
V_118 = F_72 ( 3000 ) ;
return V_118 ;
}
static void F_82 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
unsigned int V_80 ,
bool V_117 ,
bool V_122 ,
bool V_123 ,
bool V_124 )
{
if ( V_80 == 1 && V_117 ) {
if ( V_122 ) {
V_5 -> V_73 = V_12 -> V_125 ;
V_5 -> V_91 = F_80 ( V_12 ) ;
} else {
V_5 -> V_87 = V_111 ;
V_5 -> V_73 = V_12 -> V_125 *
V_126 ;
V_5 -> V_91 =
V_12 -> V_127 ;
}
V_5 -> V_54 . V_78 = F_78 (unsigned long,
bfqq->entity.budget,
2 * bfq_min_budget(bfqd)) ;
} else if ( V_80 > 1 ) {
if ( V_122 ) {
V_5 -> V_73 = V_12 -> V_125 ;
V_5 -> V_91 = F_80 ( V_12 ) ;
} else if ( V_123 )
V_5 -> V_73 = 1 ;
else if ( V_124 ) {
if ( V_5 -> V_91 !=
V_12 -> V_127 ) {
V_5 -> V_87 =
V_5 -> V_89 ;
V_5 -> V_91 =
V_12 -> V_127 ;
V_5 -> V_73 = V_12 -> V_125 *
V_126 ;
}
V_5 -> V_89 = V_111 ;
}
}
}
static bool F_83 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
return V_5 -> V_128 == 0 &&
F_59 (
V_5 -> V_129 +
V_12 -> V_130 ) ;
}
static void F_84 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
int V_80 ,
struct V_20 * V_65 ,
bool * V_122 )
{
bool V_124 , V_123 , V_117 ,
V_131 ,
V_132 = F_83 ( V_12 , V_5 ) ,
V_116 = F_39 () <=
V_5 -> V_84 . V_133 +
V_12 -> V_134 * 3 ;
F_85 ( F_86 ( F_87 ( V_65 ) ) , V_5 , V_65 -> V_30 ) ;
V_123 = F_58 ( V_5 ) ;
V_124 = V_12 -> V_135 > 0 &&
! V_123 &&
F_59 ( V_5 -> V_136 ) ;
* V_122 = ! V_123 && V_132 ;
V_117 = V_12 -> V_137 &&
( V_5 -> V_73 > 1 ||
( F_47 ( V_5 ) &&
V_5 -> V_3 && ( * V_122 || V_124 ) ) ) ;
V_131 =
F_76 ( V_12 , V_5 ,
V_116 ,
V_117 ) ;
if ( F_60 ( ! F_88 ( V_5 ) ) &&
V_132 &&
F_59 (
V_5 -> V_129 +
F_72 ( 10000 ) ) ) {
F_64 ( & V_5 -> V_99 ) ;
F_89 ( V_5 ) ;
}
F_90 ( V_5 ) ;
if ( ! F_91 ( V_5 ) ) {
if ( V_116 ) {
V_5 -> V_138 ++ ;
if ( V_5 -> V_138 >=
V_12 -> V_139 )
F_56 ( V_5 ) ;
} else
V_5 -> V_138 = 0 ;
}
if ( V_12 -> V_137 ) {
if ( F_32 ( F_92 ( V_5 -> V_107 ) ) )
V_5 -> V_107 =
V_111 - V_12 -> V_130 - 1 ;
if ( F_59 ( V_5 -> V_107 +
V_12 -> V_130 ) ) {
F_82 ( V_12 , V_5 ,
V_80 ,
V_117 ,
* V_122 ,
V_123 ,
V_124 ) ;
if ( V_80 != V_5 -> V_73 )
V_5 -> V_54 . V_93 = 1 ;
}
}
V_5 -> V_140 = V_111 ;
V_5 -> V_141 = 0 ;
F_93 ( V_5 ) ;
F_94 ( V_12 , V_5 ) ;
if ( V_12 -> V_77 && V_131 &&
V_12 -> V_77 -> V_73 < V_5 -> V_73 &&
F_95 ( V_12 ) )
F_96 ( V_12 , V_12 -> V_77 ,
false , V_142 ) ;
}
static void F_97 ( struct V_20 * V_65 )
{
struct V_1 * V_5 = F_87 ( V_65 ) ;
struct V_6 * V_12 = V_5 -> V_12 ;
struct V_20 * V_44 , * V_71 ;
unsigned int V_80 = V_5 -> V_73 ;
bool V_122 = false ;
F_40 ( V_12 , V_5 , L_6 , F_16 ( V_65 ) ) ;
V_5 -> V_18 [ F_16 ( V_65 ) ] ++ ;
V_12 -> V_18 ++ ;
F_98 ( & V_5 -> V_72 , V_65 ) ;
V_71 = V_5 -> V_44 ;
V_44 = F_13 ( V_12 , V_5 -> V_44 , V_65 , V_12 -> V_143 ) ;
V_5 -> V_44 = V_44 ;
if ( V_71 != V_5 -> V_44 )
F_20 ( V_12 , V_5 ) ;
if ( ! F_53 ( V_5 ) )
F_84 ( V_12 , V_5 , V_80 ,
V_65 , & V_122 ) ;
else {
if ( V_12 -> V_137 && V_80 == 1 && ! F_16 ( V_65 ) &&
F_59 (
V_5 -> V_89 +
V_12 -> V_144 ) ) {
V_5 -> V_73 = V_12 -> V_125 ;
V_5 -> V_91 = F_80 ( V_12 ) ;
V_12 -> V_74 ++ ;
V_5 -> V_54 . V_93 = 1 ;
}
if ( V_71 != V_5 -> V_44 )
F_49 ( V_12 , V_5 ) ;
}
if ( V_12 -> V_137 &&
( V_80 == 1 || V_5 -> V_73 == 1 || V_122 ) )
V_5 -> V_89 = V_111 ;
}
static struct V_20 * F_99 ( struct V_6 * V_12 ,
struct V_145 * V_145 ,
struct V_15 * V_8 )
{
struct V_1 * V_5 = V_12 -> V_146 ;
if ( V_5 )
return F_100 ( & V_5 -> V_72 , F_101 ( V_145 ) ) ;
return NULL ;
}
static T_1 F_102 ( T_1 V_147 , struct V_20 * V_65 )
{
if ( V_147 )
return abs ( F_17 ( V_65 ) - V_147 ) ;
return 0 ;
}
static void F_103 ( struct V_15 * V_8 ,
struct V_20 * V_65 )
{
struct V_1 * V_5 = F_87 ( V_65 ) ;
struct V_6 * V_12 = V_5 -> V_12 ;
const int V_148 = F_16 ( V_65 ) ;
if ( V_5 -> V_44 == V_65 ) {
V_5 -> V_44 = F_41 ( V_12 , V_5 , V_65 ) ;
F_49 ( V_12 , V_5 ) ;
}
if ( V_65 -> V_149 . V_71 != & V_65 -> V_149 )
F_104 ( & V_65 -> V_149 ) ;
V_5 -> V_18 [ V_148 ] -- ;
V_12 -> V_18 -- ;
F_105 ( & V_5 -> V_72 , V_65 ) ;
F_106 ( V_8 , V_65 ) ;
if ( V_8 -> V_150 == V_65 )
V_8 -> V_150 = NULL ;
if ( F_27 ( & V_5 -> V_72 ) ) {
V_5 -> V_44 = NULL ;
if ( F_53 ( V_5 ) && V_5 != V_12 -> V_77 ) {
F_107 ( V_12 , V_5 , false ) ;
V_5 -> V_54 . V_78 = V_5 -> V_54 . V_112 = 0 ;
}
if ( V_5 -> V_49 ) {
F_21 ( & V_5 -> V_43 , V_5 -> V_49 ) ;
V_5 -> V_49 = NULL ;
}
}
if ( V_65 -> V_30 & V_31 )
V_5 -> V_151 -- ;
F_108 ( F_86 ( V_5 ) , V_65 -> V_30 ) ;
}
static bool F_109 ( struct V_152 * V_153 , struct V_145 * V_145 )
{
struct V_15 * V_8 = V_153 -> V_19 ;
struct V_6 * V_12 = V_8 -> V_9 -> V_10 ;
struct V_20 * free = NULL ;
struct V_2 * V_3 = F_6 ( V_12 , V_154 -> V_13 , V_8 ) ;
bool V_155 ;
F_110 ( & V_12 -> V_156 ) ;
if ( V_3 )
V_12 -> V_146 = F_1 ( V_3 , F_111 ( V_145 -> V_157 ) ) ;
else
V_12 -> V_146 = NULL ;
V_12 -> V_158 = V_3 ;
V_155 = F_112 ( V_8 , V_145 , & free ) ;
if ( free )
F_113 ( free ) ;
F_114 ( & V_12 -> V_156 ) ;
return V_155 ;
}
static int F_115 ( struct V_15 * V_8 , struct V_20 * * V_159 ,
struct V_145 * V_145 )
{
struct V_6 * V_12 = V_8 -> V_9 -> V_10 ;
struct V_20 * V_160 ;
V_160 = F_99 ( V_12 , V_145 , V_8 ) ;
if ( V_160 && F_116 ( V_160 , V_145 ) ) {
* V_159 = V_160 ;
return V_161 ;
}
return V_162 ;
}
static void F_117 ( struct V_15 * V_8 , struct V_20 * V_159 ,
enum V_163 type )
{
if ( type == V_161 &&
F_43 ( & V_159 -> V_37 ) &&
F_17 ( V_159 ) <
F_17 ( F_5 ( F_43 ( & V_159 -> V_37 ) ,
struct V_20 , V_37 ) ) ) {
struct V_1 * V_5 = F_87 ( V_159 ) ;
struct V_6 * V_12 = V_5 -> V_12 ;
struct V_20 * V_71 , * V_44 ;
F_105 ( & V_5 -> V_72 , V_159 ) ;
F_98 ( & V_5 -> V_72 , V_159 ) ;
V_71 = V_5 -> V_44 ;
V_44 = F_13 ( V_12 , V_5 -> V_44 , V_159 ,
V_12 -> V_143 ) ;
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
struct V_1 * V_5 = F_87 ( V_65 ) , * V_164 = F_87 ( V_67 ) ;
if ( ! F_119 ( & V_65 -> V_37 ) )
goto V_110;
F_110 ( & V_5 -> V_12 -> V_156 ) ;
if ( V_5 == V_164 &&
! F_120 ( & V_65 -> V_149 ) && ! F_120 ( & V_67 -> V_149 ) &&
V_67 -> V_68 < V_65 -> V_68 ) {
F_104 ( & V_65 -> V_149 ) ;
F_121 ( & V_67 -> V_149 , & V_65 -> V_149 ) ;
V_65 -> V_68 = V_67 -> V_68 ;
}
if ( V_5 -> V_44 == V_67 )
V_5 -> V_44 = V_65 ;
F_103 ( V_8 , V_67 ) ;
F_114 ( & V_5 -> V_12 -> V_156 ) ;
V_110:
F_122 ( F_86 ( V_5 ) , V_67 -> V_30 ) ;
}
static void F_123 ( struct V_1 * V_5 )
{
if ( F_53 ( V_5 ) )
V_5 -> V_12 -> V_74 -- ;
V_5 -> V_73 = 1 ;
V_5 -> V_91 = 0 ;
V_5 -> V_89 = V_111 ;
V_5 -> V_54 . V_93 = 1 ;
}
void F_124 ( struct V_6 * V_12 ,
struct V_165 * V_166 )
{
int V_167 , V_168 ;
for ( V_167 = 0 ; V_167 < 2 ; V_167 ++ )
for ( V_168 = 0 ; V_168 < V_169 ; V_168 ++ )
if ( V_166 -> V_170 [ V_167 ] [ V_168 ] )
F_123 ( V_166 -> V_170 [ V_167 ] [ V_168 ] ) ;
if ( V_166 -> V_171 )
F_123 ( V_166 -> V_171 ) ;
}
static void F_125 ( struct V_6 * V_12 )
{
struct V_1 * V_5 ;
F_110 ( & V_12 -> V_156 ) ;
F_126 (bfqq, &bfqd->active_list, bfqq_list)
F_123 ( V_5 ) ;
F_126 (bfqq, &bfqd->idle_list, bfqq_list)
F_123 ( V_5 ) ;
F_127 ( V_12 ) ;
F_114 ( & V_12 -> V_156 ) ;
}
static T_1 F_128 ( void * V_172 , bool V_20 )
{
if ( V_20 )
return F_17 ( V_172 ) ;
else
return ( (struct V_145 * ) V_172 ) -> V_173 . V_174 ;
}
static int F_129 ( void * V_172 , bool V_20 ,
T_1 V_36 )
{
return abs ( F_128 ( V_172 , V_20 ) - V_36 ) <=
V_175 ;
}
static struct V_1 * F_130 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
T_1 V_36 )
{
struct V_34 * V_35 = & F_23 ( V_5 ) -> V_50 ;
struct V_37 * V_41 , * V_176 ;
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
V_176 = F_42 ( & V_48 -> V_43 ) ;
else
V_176 = F_43 ( & V_48 -> V_43 ) ;
if ( ! V_176 )
return NULL ;
V_48 = F_19 ( V_176 , struct V_1 , V_43 ) ;
if ( F_129 ( V_48 -> V_44 , true , V_36 ) )
return V_48 ;
return NULL ;
}
static struct V_1 * F_131 ( struct V_6 * V_12 ,
struct V_1 * V_177 ,
T_1 V_36 )
{
struct V_1 * V_5 ;
V_5 = F_130 ( V_12 , V_177 , V_36 ) ;
if ( ! V_5 || V_5 == V_177 )
return NULL ;
return V_5 ;
}
static struct V_1 *
F_132 ( struct V_1 * V_5 , struct V_1 * V_178 )
{
int V_179 , V_180 ;
struct V_1 * V_48 ;
if ( ! F_61 ( V_178 ) )
return NULL ;
while ( ( V_48 = V_178 -> V_178 ) ) {
if ( V_48 == V_5 )
return NULL ;
V_178 = V_48 ;
}
V_179 = F_61 ( V_5 ) ;
V_180 = F_61 ( V_178 ) ;
if ( V_179 == 0 || V_180 == 0 )
return NULL ;
F_40 ( V_5 -> V_12 , V_5 , L_7 ,
V_178 -> V_47 ) ;
V_5 -> V_178 = V_178 ;
V_178 -> V_94 += V_179 ;
return V_178 ;
}
static bool F_133 ( struct V_1 * V_5 ,
struct V_1 * V_178 )
{
if ( F_22 ( V_5 ) || F_22 ( V_178 ) ||
( V_5 -> V_181 != V_178 -> V_181 ) )
return false ;
if ( F_134 ( V_5 ) || F_134 ( V_178 ) )
return false ;
if ( ! F_47 ( V_5 ) || ! F_47 ( V_178 ) )
return false ;
return true ;
}
static bool F_135 ( struct V_1 * V_5 )
{
return V_5 -> V_73 > 1 &&
F_59 ( V_5 -> V_89 +
F_72 ( 100 ) ) ;
}
static struct V_1 *
F_136 ( struct V_6 * V_12 , struct V_1 * V_5 ,
void * V_172 , bool V_20 )
{
struct V_1 * V_182 , * V_178 ;
if ( V_5 -> V_178 )
return V_5 -> V_178 ;
if ( ! V_172 ||
F_135 ( V_5 ) ||
F_32 ( V_5 == & V_12 -> V_183 ) )
return NULL ;
if ( V_12 -> V_184 == 1 )
return NULL ;
V_182 = V_12 -> V_77 ;
if ( ! V_182 || V_182 == V_5
|| F_135 ( V_182 ) ||
F_32 ( V_182 == & V_12 -> V_183 ) )
goto V_185;
if ( F_129 ( V_172 , V_20 , V_12 -> V_143 ) &&
V_5 -> V_54 . V_41 == V_182 -> V_54 . V_41 &&
F_133 ( V_5 , V_182 ) ) {
V_178 = F_132 ( V_5 , V_182 ) ;
if ( V_178 )
return V_178 ;
}
V_185:
V_178 = F_131 ( V_12 , V_5 ,
F_128 ( V_172 , V_20 ) ) ;
if ( V_178 && ! F_135 ( V_178 ) &&
F_60 ( V_178 != & V_12 -> V_183 ) &&
F_133 ( V_5 , V_178 ) )
return F_132 ( V_5 , V_178 ) ;
return NULL ;
}
static void F_137 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
if ( ! V_3 )
return;
V_3 -> V_85 = V_5 -> V_84 ;
V_3 -> V_82 = F_138 ( V_5 ) ;
V_3 -> V_83 = F_91 ( V_5 ) ;
V_3 -> V_186 = F_58 ( V_5 ) ;
V_3 -> V_187 = ! F_70 ( & V_5 -> V_99 ) ;
V_3 -> V_86 = V_5 -> V_73 ;
V_3 -> V_88 = V_5 -> V_87 ;
V_3 -> V_90 = V_5 -> V_89 ;
V_3 -> V_92 = V_5 -> V_91 ;
}
static void
F_139 ( struct V_6 * V_12 , struct V_2 * V_3 ,
struct V_1 * V_5 , struct V_1 * V_178 )
{
F_40 ( V_12 , V_5 , L_8 ,
( unsigned long ) V_178 -> V_47 ) ;
F_137 ( V_5 ) ;
F_137 ( V_178 ) ;
if ( F_91 ( V_5 ) )
F_56 ( V_178 ) ;
F_57 ( V_5 ) ;
if ( V_178 -> V_73 == 1 && V_5 -> V_73 > 1 ) {
V_178 -> V_73 = V_5 -> V_73 ;
V_178 -> V_91 = V_5 -> V_91 ;
V_178 -> V_89 = V_5 -> V_89 ;
V_178 -> V_87 =
V_5 -> V_87 ;
if ( F_53 ( V_178 ) )
V_12 -> V_74 ++ ;
V_178 -> V_54 . V_93 = 1 ;
}
if ( V_5 -> V_73 > 1 ) {
V_5 -> V_73 = 1 ;
V_5 -> V_54 . V_93 = 1 ;
if ( F_53 ( V_5 ) )
V_12 -> V_74 -- ;
}
F_40 ( V_12 , V_178 , L_9 ,
V_12 -> V_74 ) ;
F_2 ( V_3 , V_178 , 1 ) ;
F_140 ( V_178 ) ;
V_178 -> V_3 = NULL ;
V_5 -> V_3 = NULL ;
F_141 ( V_5 ) ;
}
static bool F_142 ( struct V_15 * V_8 , struct V_20 * V_65 ,
struct V_145 * V_145 )
{
struct V_6 * V_12 = V_8 -> V_9 -> V_10 ;
bool V_4 = F_111 ( V_145 -> V_157 ) ;
struct V_1 * V_5 = V_12 -> V_146 , * V_178 ;
if ( V_4 && ! F_16 ( V_65 ) )
return false ;
if ( ! V_5 )
return false ;
V_178 = F_136 ( V_12 , V_5 , V_145 , false ) ;
if ( V_178 ) {
F_139 ( V_12 , V_12 -> V_158 , V_5 ,
V_178 ) ;
V_5 = V_178 ;
V_12 -> V_146 = V_5 ;
}
return V_5 == F_87 ( V_65 ) ;
}
static void F_143 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
unsigned int V_188 ;
if ( V_5 -> V_91 == V_12 -> V_127 )
V_188 = 1 ;
else
V_188 = V_5 -> V_54 . V_60 / V_5 -> V_54 . V_189 ;
V_12 -> V_190 = F_144 () ;
V_5 -> V_129 = V_111 +
V_12 -> V_191 * V_188 ;
}
static void F_145 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
if ( V_5 ) {
F_146 ( F_86 ( V_5 ) ) ;
F_147 ( V_5 ) ;
V_12 -> V_113 = ( V_12 -> V_113 * 7 + 256 ) / 8 ;
if ( F_59 ( V_5 -> V_89 ) &&
V_5 -> V_73 > 1 &&
V_5 -> V_91 == V_12 -> V_127 &&
F_59 ( V_5 -> V_129 ) ) {
if ( F_148 ( V_5 -> V_129 ,
V_5 -> V_89 ) )
V_5 -> V_89 +=
V_111 - V_5 -> V_129 ;
else
V_5 -> V_89 = V_111 ;
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
T_3 V_192 ;
F_152 ( V_5 ) ;
V_192 = V_12 -> V_134 ;
if ( F_134 ( V_5 ) && V_5 -> V_73 == 1 &&
F_29 ( V_12 ) )
V_192 = F_78 ( T_2 , V_192 , V_193 ) ;
V_12 -> V_194 = F_144 () ;
F_153 ( & V_12 -> V_195 , F_154 ( V_192 ) ,
V_196 ) ;
F_155 ( F_86 ( V_5 ) ) ;
}
static unsigned long F_156 ( struct V_6 * V_12 )
{
return ( T_2 ) V_12 -> V_121 * V_197 *
F_157 ( V_12 -> V_191 ) >> V_198 ;
}
static void F_158 ( struct V_6 * V_12 )
{
int V_199 = F_159 ( V_12 -> V_19 ) ;
if ( V_12 -> V_200 == 0 )
V_12 -> F_74 =
F_156 ( V_12 ) ;
if ( V_12 -> V_201 == V_202 &&
V_12 -> V_121 < V_203 [ V_199 ] ) {
V_12 -> V_201 = V_204 ;
V_12 -> V_120 = V_205 [ V_199 ] *
V_206 [ V_199 ] ;
} else if ( V_12 -> V_201 == V_204 &&
V_12 -> V_121 > V_203 [ V_199 ] ) {
V_12 -> V_201 = V_202 ;
V_12 -> V_120 = V_207 [ V_199 ] *
V_208 [ V_199 ] ;
}
F_11 ( V_12 ,
L_11 ,
V_199 == 0 ? L_12 : L_13 ,
V_12 -> V_201 == V_202 ? L_14 : L_15 ,
V_12 -> V_201 == V_202 ?
( V_209 * ( T_2 ) V_207 [ V_199 ] ) >> V_198 :
( V_209 * ( T_2 ) V_205 [ V_199 ] ) >> V_198 ,
( V_209 * ( T_2 ) V_203 [ V_199 ] ) >>
V_198 ) ;
}
static void F_160 ( struct V_6 * V_12 ,
struct V_20 * V_65 )
{
if ( V_65 != NULL ) {
V_12 -> V_210 = V_12 -> V_211 = F_39 () ;
V_12 -> V_212 = 1 ;
V_12 -> V_213 = 0 ;
V_12 -> V_214 = V_12 -> V_215 =
F_48 ( V_65 ) ;
} else
V_12 -> V_212 = 0 ;
F_11 ( V_12 ,
L_16 ,
V_12 -> V_212 , V_12 -> V_213 ,
V_12 -> V_214 ) ;
}
static void F_161 ( struct V_6 * V_12 , struct V_20 * V_65 )
{
T_3 V_216 , V_60 , V_217 ;
if ( V_12 -> V_212 < V_218 ||
V_12 -> V_219 < V_220 )
goto V_221;
V_12 -> V_219 =
F_50 ( T_2 , V_12 -> V_219 ,
V_12 -> V_222 - V_12 -> V_211 ) ;
V_216 = F_162 ( V_12 -> V_214 << V_198 ,
F_163 ( V_12 -> V_219 , V_223 ) ) ;
if ( ( V_12 -> V_213 < ( 3 * V_12 -> V_212 ) >> 2 &&
V_216 <= V_12 -> V_121 ) ||
V_216 > 20 << V_198 )
goto V_221;
V_60 = ( 9 * V_12 -> V_213 ) / V_12 -> V_212 ;
V_60 = F_78 ( T_3 , 8 ,
F_163 ( V_60 * V_12 -> V_219 ,
V_224 ) ) ;
V_217 = 10 - V_60 ;
V_12 -> V_121 *= V_217 - 1 ;
V_12 -> V_121 /= V_217 ;
V_216 /= V_217 ;
V_12 -> V_121 += V_216 ;
F_158 ( V_12 ) ;
V_221:
F_160 ( V_12 , V_65 ) ;
}
static void F_164 ( struct V_6 * V_12 , struct V_20 * V_65 )
{
T_2 V_225 = F_39 () ;
if ( V_12 -> V_212 == 0 ) {
F_11 ( V_12 , L_17 ,
V_12 -> V_212 ) ;
F_160 ( V_12 , V_65 ) ;
goto V_226;
}
if ( V_225 - V_12 -> V_210 > 100 * V_227 &&
V_12 -> V_228 == 0 )
goto V_229;
V_12 -> V_212 ++ ;
if ( ( V_12 -> V_228 > 0 ||
V_225 - V_12 -> V_222 < V_193 )
&& F_102 ( V_12 -> V_143 , V_65 ) < V_230 )
V_12 -> V_213 ++ ;
V_12 -> V_214 += F_48 ( V_65 ) ;
if ( F_60 ( V_12 -> V_212 % 32 ) )
V_12 -> V_215 =
F_50 ( T_3 , F_48 ( V_65 ) , V_12 -> V_215 ) ;
else
V_12 -> V_215 = F_48 ( V_65 ) ;
V_12 -> V_219 = V_225 - V_12 -> V_211 ;
if ( V_12 -> V_219 < V_224 )
goto V_226;
V_229:
F_161 ( V_12 , V_65 ) ;
V_226:
V_12 -> V_143 = F_17 ( V_65 ) + F_48 ( V_65 ) ;
V_12 -> V_210 = V_225 ;
}
static void F_165 ( struct V_15 * V_8 , struct V_20 * V_65 )
{
struct V_1 * V_5 = F_87 ( V_65 ) ;
V_5 -> V_128 ++ ;
F_164 ( V_8 -> V_9 -> V_10 , V_65 ) ;
F_103 ( V_8 , V_65 ) ;
}
static void F_166 ( struct V_6 * V_12 , struct V_1 * V_5 )
{
if ( F_167 ( V_5 ) && F_134 ( V_5 ) )
F_168 ( V_5 ) ;
if ( F_27 ( & V_5 -> V_72 ) ) {
if ( V_5 -> V_128 == 0 )
V_5 -> V_129 = V_111 ;
F_107 ( V_12 , V_5 , true ) ;
} else {
F_51 ( V_12 , V_5 ) ;
F_20 ( V_12 , V_5 ) ;
}
F_169 ( V_12 ) ;
}
static void F_170 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
enum V_231 V_232 )
{
struct V_20 * V_44 ;
int V_78 , V_233 ;
V_233 = F_75 ( V_12 ) ;
if ( V_5 -> V_73 == 1 )
V_78 = V_5 -> V_234 ;
else
V_78 = 2 * V_233 ;
F_40 ( V_12 , V_5 , L_18 ,
V_5 -> V_54 . V_78 , F_73 ( V_5 ) ) ;
F_40 ( V_12 , V_5 , L_19 ,
V_78 , F_75 ( V_12 ) ) ;
F_40 ( V_12 , V_5 , L_20 ,
F_47 ( V_5 ) , F_134 ( V_12 -> V_77 ) ) ;
if ( F_47 ( V_5 ) && V_5 -> V_73 == 1 ) {
switch ( V_232 ) {
case V_235 :
if ( V_5 -> V_128 > 0 )
V_78 = F_171 ( V_78 * 2 , V_12 -> F_74 ) ;
else {
if ( V_78 > 5 * V_233 )
V_78 -= 4 * V_233 ;
else
V_78 = V_233 ;
}
break;
case V_236 :
V_78 = F_171 ( V_78 * 2 , V_12 -> F_74 ) ;
break;
case V_237 :
V_78 = F_171 ( V_78 * 4 , V_12 -> F_74 ) ;
break;
case V_238 :
V_78 = F_50 ( int , V_5 -> V_54 . V_112 , V_233 ) ;
break;
default:
return;
}
} else if ( ! F_47 ( V_5 ) ) {
V_78 = V_12 -> F_74 ;
}
V_5 -> V_234 = V_78 ;
if ( V_12 -> V_113 >= V_114 &&
! V_12 -> V_200 )
V_5 -> V_234 = F_171 ( V_5 -> V_234 , V_12 -> F_74 ) ;
V_44 = V_5 -> V_44 ;
if ( V_44 )
V_5 -> V_54 . V_78 = F_50 (unsigned long, bfqq->max_budget,
bfq_serv_to_charge(next_rq, bfqq)) ;
F_40 ( V_12 , V_5 , L_21 ,
V_44 ? F_48 ( V_44 ) : 0 ,
V_5 -> V_54 . V_78 ) ;
}
static bool F_172 ( struct V_6 * V_12 , struct V_1 * V_5 ,
bool V_239 , enum V_231 V_232 ,
unsigned long * V_240 )
{
T_4 V_241 ;
T_3 V_242 ;
bool V_243 = F_134 ( V_5 ) ;
if ( ! F_47 ( V_5 ) )
return false ;
if ( V_239 )
V_241 = V_12 -> V_194 ;
else
V_241 = F_144 () ;
V_241 = F_173 ( V_241 , V_12 -> V_190 ) ;
V_242 = F_174 ( V_241 ) ;
if ( V_242 < 1000 ) {
if ( F_159 ( V_12 -> V_19 ) )
* V_240 = V_193 / V_227 ;
else
* V_240 = V_134 / V_227 ;
return V_243 ;
}
* V_240 = V_242 / V_197 ;
if ( V_242 > 20000 ) {
V_243 = V_5 -> V_54 . V_112 < V_12 -> F_74 / 2 ;
}
F_40 ( V_12 , V_5 , L_22 , V_243 ) ;
return V_243 ;
}
static unsigned long F_175 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
return F_176 ( V_5 -> V_140 +
V_244 * V_5 -> V_141 /
V_12 -> V_135 ,
V_111 + F_177 ( V_5 -> V_12 -> V_134 ) + 4 ) ;
}
static unsigned long F_178 ( void )
{
return V_111 + V_245 ;
}
static unsigned long F_179 ( void )
{
return V_111 - V_245 ;
}
void F_96 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
bool V_239 ,
enum V_231 V_232 )
{
bool V_243 ;
unsigned long V_246 = 0 ;
struct V_53 * V_54 = & V_5 -> V_54 ;
int V_94 ;
V_243 = F_172 ( V_12 , V_5 , V_239 , V_232 , & V_246 ) ;
V_5 -> V_141 += V_54 -> V_112 ;
if ( V_5 -> V_73 == 1 &&
( V_243 ||
( V_232 == V_236 &&
F_73 ( V_5 ) >= V_54 -> V_78 / 3 ) ) )
F_180 ( V_12 , V_5 , V_246 ) ;
if ( V_232 == V_235 &&
V_54 -> V_112 <= 2 * V_54 -> V_78 / 10 )
F_57 ( V_5 ) ;
if ( V_12 -> V_137 && V_5 -> V_73 == 1 )
V_5 -> V_89 = V_111 ;
if ( V_12 -> V_137 && V_12 -> V_135 > 0 &&
F_27 ( & V_5 -> V_72 ) ) {
if ( V_5 -> V_128 == 0 )
V_5 -> V_136 =
F_175 ( V_12 , V_5 ) ;
else {
V_5 -> V_136 =
F_178 () ;
F_181 ( V_5 ) ;
}
}
F_40 ( V_12 , V_5 ,
L_23 , V_232 ,
V_243 , V_5 -> V_128 , F_138 ( V_5 ) ) ;
F_170 ( V_12 , V_5 , V_232 ) ;
V_94 = V_5 -> V_94 ;
F_166 ( V_12 , V_5 ) ;
if ( V_94 > 1 && ! F_53 ( V_5 ) &&
V_232 != V_236 &&
V_232 != V_237 )
F_182 ( V_5 ) ;
}
static bool F_183 ( struct V_1 * V_5 )
{
return F_184 ( V_5 -> V_129 ) ;
}
static bool F_185 ( struct V_1 * V_5 )
{
F_40 ( V_5 -> V_12 , V_5 ,
L_24 ,
F_186 ( V_5 ) ,
F_73 ( V_5 ) >= V_5 -> V_54 . V_78 / 3 ,
F_183 ( V_5 ) ) ;
return ( ! F_186 ( V_5 ) ||
F_73 ( V_5 ) >= V_5 -> V_54 . V_78 / 3 )
&&
F_183 ( V_5 ) ;
}
static bool F_187 ( struct V_1 * V_5 )
{
struct V_6 * V_12 = V_5 -> V_12 ;
bool V_247 , V_248 ,
V_249 ,
V_250 ;
if ( V_12 -> V_251 )
return true ;
V_247 = ! V_12 -> V_252 ||
( ! F_159 ( V_12 -> V_19 ) && F_91 ( V_5 ) &&
F_138 ( V_5 ) ) ;
V_248 = V_247 &&
V_12 -> V_74 == 0 ;
V_250 = V_5 -> V_73 > 1 ||
! F_29 ( V_12 ) ;
V_249 =
V_250 && ! F_58 ( V_5 ) ;
return F_47 ( V_5 ) &&
( V_248 ||
V_249 ) ;
}
static bool F_188 ( struct V_1 * V_5 )
{
struct V_6 * V_12 = V_5 -> V_12 ;
return F_27 ( & V_5 -> V_72 ) && V_12 -> V_134 != 0 &&
F_187 ( V_5 ) ;
}
static struct V_1 * F_189 ( struct V_6 * V_12 )
{
struct V_1 * V_5 ;
struct V_20 * V_44 ;
enum V_231 V_232 = V_236 ;
V_5 = V_12 -> V_77 ;
if ( ! V_5 )
goto V_253;
F_40 ( V_12 , V_5 , L_25 ) ;
if ( F_185 ( V_5 ) &&
! F_186 ( V_5 ) &&
! F_188 ( V_5 ) )
goto V_254;
V_255:
V_44 = V_5 -> V_44 ;
if ( V_44 ) {
if ( F_46 ( V_44 , V_5 ) >
F_73 ( V_5 ) ) {
V_232 = V_237 ;
goto V_254;
} else {
if ( F_186 ( V_5 ) ) {
F_190 ( V_5 ) ;
F_191 ( & V_12 -> V_195 ) ;
F_192 ( F_86 ( V_5 ) ) ;
}
goto V_256;
}
}
if ( F_186 ( V_5 ) ||
( V_5 -> V_128 != 0 && F_187 ( V_5 ) ) ) {
V_5 = NULL ;
goto V_256;
}
V_232 = V_238 ;
V_254:
F_96 ( V_12 , V_5 , false , V_232 ) ;
V_253:
V_5 = F_149 ( V_12 ) ;
if ( V_5 ) {
F_40 ( V_12 , V_5 , L_26 ) ;
goto V_255;
}
V_256:
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
F_157 ( V_111 - V_5 -> V_89 ) ,
F_157 ( V_5 -> V_91 ) ,
V_5 -> V_73 ,
V_5 -> V_54 . V_60 , V_5 -> V_54 . V_189 ) ;
if ( V_54 -> V_93 )
F_40 ( V_12 , V_5 , L_30 ) ;
if ( F_58 ( V_5 ) )
F_123 ( V_5 ) ;
else if ( F_59 ( V_5 -> V_89 +
V_5 -> V_91 ) ) {
if ( V_5 -> V_91 != V_12 -> V_127 ||
F_59 ( V_5 -> V_87 +
F_80 ( V_12 ) ) )
F_123 ( V_5 ) ;
else {
V_5 -> V_73 = V_12 -> V_125 ;
V_5 -> V_91 = F_80 ( V_12 ) ;
V_5 -> V_89 =
V_5 -> V_87 ;
V_5 -> V_54 . V_93 = 1 ;
}
}
}
if ( ( V_54 -> V_60 > V_54 -> V_189 ) != ( V_5 -> V_73 > 1 ) )
F_194 ( F_195 ( V_54 ) ,
V_54 , false ) ;
}
static struct V_20 * F_196 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
struct V_20 * V_65 = V_5 -> V_44 ;
unsigned long V_257 ;
V_257 = F_46 ( V_65 , V_5 ) ;
F_197 ( V_5 , V_257 ) ;
F_165 ( V_12 -> V_19 , V_65 ) ;
F_193 ( V_12 , V_5 ) ;
if ( V_12 -> V_184 > 1 && F_22 ( V_5 ) )
goto V_254;
return V_65 ;
V_254:
F_96 ( V_12 , V_5 , false , V_237 ) ;
return V_65 ;
}
static bool F_198 ( struct V_152 * V_153 )
{
struct V_6 * V_12 = V_153 -> V_19 -> V_9 -> V_10 ;
return ! F_199 ( & V_12 -> V_258 ) ||
V_12 -> V_184 > 0 ;
}
static struct V_20 * F_200 ( struct V_152 * V_153 )
{
struct V_6 * V_12 = V_153 -> V_19 -> V_9 -> V_10 ;
struct V_20 * V_65 = NULL ;
struct V_1 * V_5 = NULL ;
if ( ! F_120 ( & V_12 -> V_258 ) ) {
V_65 = F_201 ( & V_12 -> V_258 , struct V_20 ,
V_149 ) ;
F_104 ( & V_65 -> V_149 ) ;
V_5 = F_87 ( V_65 ) ;
if ( V_5 ) {
V_5 -> V_128 ++ ;
goto V_259;
}
goto V_260;
}
F_11 ( V_12 , L_31 , V_12 -> V_184 ) ;
if ( V_12 -> V_184 == 0 )
goto exit;
if ( V_12 -> V_251 && V_12 -> V_228 > 0 )
goto exit;
V_5 = F_189 ( V_12 ) ;
if ( ! V_5 )
goto exit;
V_65 = F_196 ( V_12 , V_5 ) ;
if ( V_65 ) {
V_259:
V_12 -> V_228 ++ ;
V_260:
V_65 -> V_261 |= V_262 ;
}
exit:
return V_65 ;
}
static struct V_20 * F_202 ( struct V_152 * V_153 )
{
struct V_6 * V_12 = V_153 -> V_19 -> V_9 -> V_10 ;
struct V_20 * V_65 ;
F_110 ( & V_12 -> V_156 ) ;
V_65 = F_200 ( V_153 ) ;
F_114 ( & V_12 -> V_156 ) ;
return V_65 ;
}
void F_141 ( struct V_1 * V_5 )
{
#ifdef F_28
struct V_165 * V_166 = F_86 ( V_5 ) ;
#endif
if ( V_5 -> V_12 )
F_40 ( V_5 -> V_12 , V_5 , L_32 ,
V_5 , V_5 -> V_94 ) ;
V_5 -> V_94 -- ;
if ( V_5 -> V_94 )
return;
if ( F_47 ( V_5 ) )
F_64 ( & V_5 -> V_99 ) ;
F_203 ( V_263 , V_5 ) ;
#ifdef F_28
F_204 ( V_166 ) ;
#endif
}
static void F_205 ( struct V_1 * V_5 )
{
struct V_1 * V_48 , * V_67 ;
V_48 = V_5 -> V_178 ;
while ( V_48 ) {
if ( V_48 == V_5 )
break;
V_67 = V_48 -> V_178 ;
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
F_40 ( V_12 , V_5 , L_33 , V_5 , V_5 -> V_94 ) ;
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
F_7 ( & V_12 -> V_156 , V_16 ) ;
F_206 ( V_12 , V_5 ) ;
F_2 ( V_3 , NULL , V_4 ) ;
F_9 ( & V_12 -> V_156 , V_16 ) ;
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
struct V_264 * V_265 = V_154 ;
int V_181 ;
struct V_6 * V_12 = V_5 -> V_12 ;
if ( ! V_12 )
return;
V_181 = F_210 ( V_3 -> V_266 ) ;
switch ( V_181 ) {
default:
F_211 ( V_5 -> V_12 -> V_19 -> V_267 -> V_268 ,
L_34 , V_181 ) ;
case V_269 :
V_5 -> V_270 = F_212 ( V_265 ) ;
V_5 -> V_271 = F_213 ( V_265 ) ;
break;
case V_272 :
V_5 -> V_270 = F_214 ( V_3 -> V_266 ) ;
V_5 -> V_271 = V_272 ;
break;
case V_273 :
V_5 -> V_270 = F_214 ( V_3 -> V_266 ) ;
V_5 -> V_271 = V_273 ;
break;
case V_274 :
V_5 -> V_271 = V_274 ;
V_5 -> V_270 = 7 ;
F_55 ( V_5 ) ;
break;
}
if ( V_5 -> V_270 >= V_169 ) {
F_215 ( L_35 ,
V_5 -> V_270 ) ;
V_5 -> V_270 = V_169 ;
}
V_5 -> V_54 . V_275 = F_216 ( V_5 -> V_270 ) ;
V_5 -> V_54 . V_93 = 1 ;
}
static void F_217 ( struct V_2 * V_3 , struct V_145 * V_145 )
{
struct V_6 * V_12 = F_3 ( V_3 ) ;
struct V_1 * V_5 ;
int V_266 = V_3 -> V_7 . V_14 -> V_266 ;
if ( F_32 ( ! V_12 ) || F_60 ( V_3 -> V_266 == V_266 ) )
return;
V_3 -> V_266 = V_266 ;
V_5 = F_1 ( V_3 , false ) ;
if ( V_5 ) {
F_141 ( V_5 ) ;
V_5 = F_218 ( V_12 , V_145 , V_276 , V_3 ) ;
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
F_222 ( & V_5 -> V_99 ) ;
V_5 -> V_94 = 0 ;
V_5 -> V_12 = V_12 ;
if ( V_3 )
F_209 ( V_5 , V_3 ) ;
if ( V_4 ) {
if ( ! F_22 ( V_5 ) )
F_54 ( V_5 ) ;
F_223 ( V_5 ) ;
F_224 ( V_5 ) ;
} else
F_225 ( V_5 ) ;
V_5 -> V_84 . V_133 = F_39 () + 1 ;
F_56 ( V_5 ) ;
V_5 -> V_47 = V_47 ;
V_5 -> V_234 = ( 2 * F_74 ( V_12 ) ) / 3 ;
V_5 -> V_129 = F_179 () ;
V_5 -> V_73 = 1 ;
V_5 -> V_89 = V_111 ;
V_5 -> V_87 = F_179 () ;
V_5 -> V_107 = F_179 () ;
V_5 -> V_136 = F_178 () ;
V_5 -> V_277 = 1 ;
}
static struct V_1 * * F_226 ( struct V_6 * V_12 ,
struct V_165 * V_166 ,
int V_181 , int V_266 )
{
switch ( V_181 ) {
case V_272 :
return & V_166 -> V_170 [ 0 ] [ V_266 ] ;
case V_269 :
V_266 = V_278 ;
case V_273 :
return & V_166 -> V_170 [ 1 ] [ V_266 ] ;
case V_274 :
return & V_166 -> V_171 ;
default:
return NULL ;
}
}
static struct V_1 * F_218 ( struct V_6 * V_12 ,
struct V_145 * V_145 , bool V_4 ,
struct V_2 * V_3 )
{
const int V_266 = F_214 ( V_3 -> V_266 ) ;
const int V_181 = F_210 ( V_3 -> V_266 ) ;
struct V_1 * * V_170 = NULL ;
struct V_1 * V_5 ;
struct V_165 * V_166 ;
F_227 () ;
V_166 = F_228 ( V_12 , F_229 ( V_145 ) ) ;
if ( ! V_166 ) {
V_5 = & V_12 -> V_183 ;
goto V_279;
}
if ( ! V_4 ) {
V_170 = F_226 ( V_12 , V_166 , V_181 ,
V_266 ) ;
V_5 = * V_170 ;
if ( V_5 )
goto V_279;
}
V_5 = F_230 ( V_263 ,
V_280 | V_281 | V_282 ,
V_12 -> V_19 -> V_176 ) ;
if ( V_5 ) {
F_219 ( V_12 , V_5 , V_3 , V_154 -> V_47 ,
V_4 ) ;
F_231 ( & V_5 -> V_54 , V_166 ) ;
F_40 ( V_12 , V_5 , L_36 ) ;
} else {
V_5 = & V_12 -> V_183 ;
F_40 ( V_12 , V_5 , L_37 ) ;
goto V_279;
}
if ( V_170 ) {
V_5 -> V_94 ++ ;
F_40 ( V_12 , V_5 , L_38 ,
V_5 , V_5 -> V_94 ) ;
* V_170 = V_5 ;
}
V_279:
V_5 -> V_94 ++ ;
F_40 ( V_12 , V_5 , L_39 , V_5 , V_5 -> V_94 ) ;
F_232 () ;
return V_5 ;
}
static void F_233 ( struct V_6 * V_12 ,
struct V_1 * V_5 )
{
struct V_283 * V_84 = & V_5 -> V_84 ;
T_2 V_284 = F_39 () - V_5 -> V_84 . V_133 ;
V_284 = F_78 ( T_2 , V_284 , 2ULL * V_12 -> V_134 ) ;
V_84 -> V_285 = ( 7 * V_5 -> V_84 . V_285 + 256 ) / 8 ;
V_84 -> V_286 = F_163 ( 7 * V_84 -> V_286 + 256 * V_284 , 8 ) ;
V_84 -> V_287 = F_162 ( V_84 -> V_286 + 128 ,
V_84 -> V_285 ) ;
}
static void
F_234 ( struct V_6 * V_12 , struct V_1 * V_5 ,
struct V_20 * V_65 )
{
V_5 -> V_277 <<= 1 ;
V_5 -> V_277 |=
F_102 ( V_5 -> V_288 , V_65 ) > V_230 &&
( ! F_159 ( V_12 -> V_19 ) ||
F_48 ( V_65 ) < V_289 ) ;
}
static void F_235 ( struct V_6 * V_12 ,
struct V_1 * V_5 ,
struct V_2 * V_3 )
{
int V_290 ;
if ( ! F_47 ( V_5 ) || F_22 ( V_5 ) )
return;
if ( F_71 ( V_5 -> V_107 +
V_12 -> V_130 ) )
return;
V_290 = F_138 ( V_5 ) ;
if ( F_236 ( & V_3 -> V_7 . V_14 -> V_291 ) == 0 ||
V_12 -> V_134 == 0 ||
( V_12 -> V_252 && F_134 ( V_5 ) &&
V_5 -> V_73 == 1 ) )
V_290 = 0 ;
else if ( F_237 ( V_5 -> V_84 . V_285 ) ) {
if ( V_5 -> V_84 . V_287 > V_12 -> V_134 &&
V_5 -> V_73 == 1 )
V_290 = 0 ;
else
V_290 = 1 ;
}
F_40 ( V_12 , V_5 , L_40 ,
V_290 ) ;
if ( V_290 )
F_54 ( V_5 ) ;
else
F_55 ( V_5 ) ;
}
static void F_238 ( struct V_6 * V_12 , struct V_1 * V_5 ,
struct V_20 * V_65 )
{
struct V_2 * V_3 = F_239 ( V_65 ) ;
if ( V_65 -> V_30 & V_31 )
V_5 -> V_151 ++ ;
F_233 ( V_12 , V_5 ) ;
F_234 ( V_12 , V_5 , V_65 ) ;
if ( V_5 -> V_54 . V_112 > F_74 ( V_12 ) / 8 ||
! F_134 ( V_5 ) )
F_235 ( V_12 , V_5 , V_3 ) ;
F_40 ( V_12 , V_5 ,
L_41 ,
F_138 ( V_5 ) , F_134 ( V_5 ) ) ;
V_5 -> V_288 = F_17 ( V_65 ) + F_48 ( V_65 ) ;
if ( V_5 == V_12 -> V_77 && F_186 ( V_5 ) ) {
bool V_292 = V_5 -> V_18 [ F_16 ( V_65 ) ] == 1 &&
F_48 ( V_65 ) < 32 ;
bool V_129 = F_183 ( V_5 ) ;
if ( V_292 && ! V_129 )
return;
F_190 ( V_5 ) ;
F_191 ( & V_12 -> V_195 ) ;
F_192 ( F_86 ( V_5 ) ) ;
if ( V_129 )
F_96 ( V_12 , V_5 , false ,
V_236 ) ;
}
}
static void F_240 ( struct V_6 * V_12 , struct V_20 * V_65 )
{
struct V_1 * V_5 = F_87 ( V_65 ) ,
* V_178 = F_136 ( V_12 , V_5 , V_65 , true ) ;
if ( V_178 ) {
if ( F_1 ( F_239 ( V_65 ) , 1 ) != V_5 )
V_178 = F_1 ( F_239 ( V_65 ) , 1 ) ;
V_178 -> V_95 ++ ;
V_5 -> V_95 -- ;
V_178 -> V_94 ++ ;
F_90 ( V_5 ) ;
if ( F_1 ( F_239 ( V_65 ) , 1 ) == V_5 )
F_139 ( V_12 , F_239 ( V_65 ) ,
V_5 , V_178 ) ;
F_141 ( V_5 ) ;
V_65 -> V_293 . V_294 [ 1 ] = V_178 ;
V_5 = V_178 ;
}
F_97 ( V_65 ) ;
V_65 -> V_68 = F_39 () + V_12 -> V_295 [ F_16 ( V_65 ) ] ;
F_241 ( & V_65 -> V_149 , & V_5 -> V_66 ) ;
F_238 ( V_12 , V_5 , V_65 ) ;
}
static void F_242 ( struct V_152 * V_153 , struct V_20 * V_65 ,
bool V_296 )
{
struct V_15 * V_8 = V_153 -> V_19 ;
struct V_6 * V_12 = V_8 -> V_9 -> V_10 ;
F_110 ( & V_12 -> V_156 ) ;
if ( F_243 ( V_8 , V_65 ) ) {
F_114 ( & V_12 -> V_156 ) ;
return;
}
F_114 ( & V_12 -> V_156 ) ;
F_244 ( V_65 ) ;
F_110 ( & V_12 -> V_156 ) ;
if ( V_296 || F_245 ( V_65 ) ) {
if ( V_296 )
F_246 ( & V_65 -> V_149 , & V_12 -> V_258 ) ;
else
F_241 ( & V_65 -> V_149 , & V_12 -> V_258 ) ;
} else {
F_240 ( V_12 , V_65 ) ;
if ( F_247 ( V_65 ) ) {
F_248 ( V_8 , V_65 ) ;
if ( ! V_8 -> V_150 )
V_8 -> V_150 = V_65 ;
}
}
F_114 ( & V_12 -> V_156 ) ;
}
static void F_249 ( struct V_152 * V_153 ,
struct V_297 * V_298 , bool V_296 )
{
while ( ! F_120 ( V_298 ) ) {
struct V_20 * V_65 ;
V_65 = F_201 ( V_298 , struct V_20 , V_149 ) ;
F_104 ( & V_65 -> V_149 ) ;
F_242 ( V_153 , V_65 , V_296 ) ;
}
}
static void F_250 ( struct V_6 * V_12 )
{
V_12 -> V_299 = F_50 ( int , V_12 -> V_299 ,
V_12 -> V_228 ) ;
if ( V_12 -> V_252 == 1 )
return;
if ( V_12 -> V_228 + V_12 -> V_18 < V_300 )
return;
if ( V_12 -> V_301 ++ < V_302 )
return;
V_12 -> V_252 = V_12 -> V_299 > V_300 ;
V_12 -> V_299 = 0 ;
V_12 -> V_301 = 0 ;
}
static void F_251 ( struct V_1 * V_5 , struct V_6 * V_12 )
{
T_2 V_225 ;
T_3 V_303 ;
F_250 ( V_12 ) ;
V_12 -> V_228 -- ;
V_5 -> V_128 -- ;
if ( ! V_5 -> V_128 && ! F_53 ( V_5 ) ) {
V_5 -> V_129 = V_111 ;
F_33 ( V_12 , & V_5 -> V_54 ,
& V_12 -> V_51 ) ;
}
V_225 = F_39 () ;
V_5 -> V_84 . V_133 = V_225 ;
V_303 = F_163 ( V_225 - V_12 -> V_222 , V_223 ) ;
if ( V_303 > V_193 / V_223 &&
( V_12 -> V_215 << V_198 ) / V_303 <
1UL << ( V_198 - 10 ) )
F_161 ( V_12 , NULL ) ;
V_12 -> V_222 = V_225 ;
if ( F_252 ( V_5 ) && V_5 -> V_128 == 0 &&
F_27 ( & V_5 -> V_72 ) )
V_5 -> V_136 =
F_175 ( V_12 , V_5 ) ;
if ( V_12 -> V_77 == V_5 ) {
if ( V_5 -> V_128 == 0 && F_188 ( V_5 ) ) {
F_151 ( V_12 ) ;
return;
} else if ( F_185 ( V_5 ) )
F_96 ( V_12 , V_5 , false ,
V_236 ) ;
else if ( F_27 ( & V_5 -> V_72 ) &&
( V_5 -> V_128 == 0 ||
! F_187 ( V_5 ) ) )
F_96 ( V_12 , V_5 , false ,
V_238 ) ;
}
if ( ! V_12 -> V_228 )
F_10 ( V_12 ) ;
}
static void F_253 ( struct V_1 * V_5 )
{
V_5 -> V_95 -- ;
F_141 ( V_5 ) ;
}
static void F_254 ( struct V_20 * V_65 )
{
struct V_1 * V_5 ;
struct V_6 * V_12 ;
if ( ! V_65 -> V_293 . V_7 )
return;
V_5 = F_87 ( V_65 ) ;
V_12 = V_5 -> V_12 ;
if ( V_65 -> V_261 & V_262 )
F_255 ( F_86 ( V_5 ) ,
F_256 ( V_65 ) ,
F_257 ( V_65 ) ,
V_65 -> V_30 ) ;
if ( F_60 ( V_65 -> V_261 & V_262 ) ) {
unsigned long V_16 ;
F_7 ( & V_12 -> V_156 , V_16 ) ;
F_251 ( V_5 , V_12 ) ;
F_253 ( V_5 ) ;
F_9 ( & V_12 -> V_156 , V_16 ) ;
} else {
if ( ! F_119 ( & V_65 -> V_37 ) )
F_103 ( V_65 -> V_8 , V_65 ) ;
F_253 ( V_5 ) ;
}
V_65 -> V_293 . V_294 [ 0 ] = NULL ;
V_65 -> V_293 . V_294 [ 1 ] = NULL ;
}
static struct V_1 *
F_258 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
F_40 ( V_5 -> V_12 , V_5 , L_42 ) ;
if ( F_61 ( V_5 ) == 1 ) {
V_5 -> V_47 = V_154 -> V_47 ;
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
struct V_145 * V_145 ,
bool V_304 , bool V_4 ,
bool * V_253 )
{
struct V_1 * V_5 = F_1 ( V_3 , V_4 ) ;
if ( F_60 ( V_5 && V_5 != & V_12 -> V_183 ) )
return V_5 ;
if ( V_253 )
* V_253 = true ;
if ( V_5 )
F_141 ( V_5 ) ;
V_5 = F_218 ( V_12 , V_145 , V_4 , V_3 ) ;
F_2 ( V_3 , V_5 , V_4 ) ;
if ( V_304 && V_4 ) {
if ( ( V_3 -> V_187 && V_12 -> V_106 ) ||
V_3 -> V_186 )
F_68 ( V_5 ) ;
else {
F_89 ( V_5 ) ;
if ( V_3 -> V_187 )
F_65 ( & V_5 -> V_99 ,
& V_12 -> V_100 ) ;
}
V_5 -> V_107 = V_111 ;
}
return V_5 ;
}
static void F_262 ( struct V_20 * V_65 , struct V_145 * V_145 )
{
struct V_15 * V_8 = V_65 -> V_8 ;
struct V_6 * V_12 = V_8 -> V_9 -> V_10 ;
struct V_2 * V_3 ;
const int V_4 = F_16 ( V_65 ) ;
struct V_1 * V_5 ;
bool V_253 = false ;
bool V_305 = false , V_304 = false ;
if ( ! V_65 -> V_293 . V_7 )
return;
V_3 = F_4 ( V_65 -> V_293 . V_7 ) ;
F_110 ( & V_12 -> V_156 ) ;
F_217 ( V_3 , V_145 ) ;
F_263 ( V_3 , V_145 ) ;
V_5 = F_261 ( V_12 , V_3 , V_145 , false , V_4 ,
& V_253 ) ;
if ( F_60 ( ! V_253 ) ) {
if ( F_167 ( V_5 ) && F_264 ( V_5 ) ) {
F_40 ( V_12 , V_5 , L_43 ) ;
if ( F_58 ( V_5 ) )
V_3 -> V_186 = true ;
V_5 = F_258 ( V_3 , V_5 ) ;
V_304 = true ;
if ( ! V_5 )
V_5 = F_261 ( V_12 , V_3 , V_145 ,
true , V_4 ,
NULL ) ;
else
V_305 = true ;
}
}
V_5 -> V_95 ++ ;
V_5 -> V_94 ++ ;
F_40 ( V_12 , V_5 , L_44 ,
V_65 , V_5 , V_5 -> V_94 ) ;
V_65 -> V_293 . V_294 [ 0 ] = V_3 ;
V_65 -> V_293 . V_294 [ 1 ] = V_5 ;
if ( F_60 ( V_5 != & V_12 -> V_183 ) && F_61 ( V_5 ) == 1 ) {
V_5 -> V_3 = V_3 ;
if ( V_304 ) {
F_52 ( V_5 , V_12 , V_3 ,
V_305 ) ;
}
}
if ( F_32 ( F_88 ( V_5 ) ) )
F_69 ( V_12 , V_5 ) ;
F_114 ( & V_12 -> V_156 ) ;
}
static void F_265 ( struct V_1 * V_5 )
{
struct V_6 * V_12 = V_5 -> V_12 ;
enum V_231 V_232 ;
unsigned long V_16 ;
F_7 ( & V_12 -> V_156 , V_16 ) ;
F_190 ( V_5 ) ;
if ( V_5 != V_12 -> V_77 ) {
F_9 ( & V_12 -> V_156 , V_16 ) ;
return;
}
if ( F_183 ( V_5 ) )
V_232 = V_236 ;
else if ( V_5 -> V_18 [ 0 ] == 0 && V_5 -> V_18 [ 1 ] == 0 )
V_232 = V_235 ;
else
goto V_306;
F_96 ( V_12 , V_5 , true , V_232 ) ;
V_306:
F_9 ( & V_12 -> V_156 , V_16 ) ;
F_10 ( V_12 ) ;
}
static enum V_307 F_266 ( struct V_308 * V_309 )
{
struct V_6 * V_12 = F_5 ( V_309 , struct V_6 ,
V_195 ) ;
struct V_1 * V_5 = V_12 -> V_77 ;
if ( V_5 )
F_265 ( V_5 ) ;
return V_310 ;
}
static void F_267 ( struct V_6 * V_12 ,
struct V_1 * * V_311 )
{
struct V_1 * V_5 = * V_311 ;
F_11 ( V_12 , L_45 , V_5 ) ;
if ( V_5 ) {
F_268 ( V_12 , V_5 , V_12 -> V_312 ) ;
F_40 ( V_12 , V_5 , L_46 ,
V_5 , V_5 -> V_94 ) ;
F_141 ( V_5 ) ;
* V_311 = NULL ;
}
}
void F_269 ( struct V_6 * V_12 , struct V_165 * V_166 )
{
int V_167 , V_168 ;
for ( V_167 = 0 ; V_167 < 2 ; V_167 ++ )
for ( V_168 = 0 ; V_168 < V_169 ; V_168 ++ )
F_267 ( V_12 , & V_166 -> V_170 [ V_167 ] [ V_168 ] ) ;
F_267 ( V_12 , & V_166 -> V_171 ) ;
}
static void F_270 ( struct V_313 * V_314 )
{
struct V_6 * V_12 = V_314 -> V_10 ;
struct V_1 * V_5 , * V_42 ;
F_271 ( & V_12 -> V_195 ) ;
F_110 ( & V_12 -> V_156 ) ;
F_272 (bfqq, n, &bfqd->idle_list, bfqq_list)
F_273 ( V_12 , V_5 , false , false ) ;
F_114 ( & V_12 -> V_156 ) ;
F_271 ( & V_12 -> V_195 ) ;
#ifdef F_28
F_274 ( V_12 -> V_19 , & V_315 ) ;
#else
F_110 ( & V_12 -> V_156 ) ;
F_269 ( V_12 , V_12 -> V_312 ) ;
F_34 ( V_12 -> V_312 ) ;
F_114 ( & V_12 -> V_156 ) ;
#endif
F_34 ( V_12 ) ;
}
static void F_275 ( struct V_165 * V_312 ,
struct V_6 * V_12 )
{
int V_167 ;
#ifdef F_28
V_312 -> V_54 . V_41 = NULL ;
V_312 -> V_316 = NULL ;
V_312 -> V_12 = V_12 ;
#endif
V_312 -> V_50 = V_317 ;
for ( V_167 = 0 ; V_167 < V_318 ; V_167 ++ )
V_312 -> V_319 . V_320 [ V_167 ] = V_321 ;
V_312 -> V_319 . V_322 = V_111 ;
}
static int F_276 ( struct V_15 * V_8 , struct V_323 * V_314 )
{
struct V_6 * V_12 ;
struct V_313 * V_324 ;
V_324 = F_277 ( V_8 , V_314 ) ;
if ( ! V_324 )
return - V_325 ;
V_12 = F_278 ( sizeof( * V_12 ) , V_326 , V_8 -> V_176 ) ;
if ( ! V_12 ) {
F_279 ( & V_324 -> V_327 ) ;
return - V_325 ;
}
V_324 -> V_10 = V_12 ;
F_110 ( V_8 -> V_17 ) ;
V_8 -> V_9 = V_324 ;
F_114 ( V_8 -> V_17 ) ;
F_219 ( V_12 , & V_12 -> V_183 , NULL , 1 , 0 ) ;
V_12 -> V_183 . V_94 ++ ;
V_12 -> V_183 . V_270 = V_328 ;
V_12 -> V_183 . V_271 = V_273 ;
V_12 -> V_183 . V_54 . V_275 =
F_216 ( V_12 -> V_183 . V_270 ) ;
F_90 ( & V_12 -> V_183 ) ;
V_12 -> V_183 . V_54 . V_93 = 1 ;
V_12 -> V_19 = V_8 ;
F_221 ( & V_12 -> V_258 ) ;
F_280 ( & V_12 -> V_195 , V_329 ,
V_196 ) ;
V_12 -> V_195 . V_330 = F_266 ;
V_12 -> V_51 = V_317 ;
V_12 -> V_52 = V_317 ;
F_221 ( & V_12 -> V_331 ) ;
F_221 ( & V_12 -> V_332 ) ;
F_281 ( & V_12 -> V_100 ) ;
V_12 -> V_252 = - 1 ;
V_12 -> F_74 = V_115 ;
V_12 -> V_295 [ 0 ] = V_295 [ 0 ] ;
V_12 -> V_295 [ 1 ] = V_295 [ 1 ] ;
V_12 -> V_32 = V_32 ;
V_12 -> V_33 = V_33 ;
V_12 -> V_134 = V_134 ;
V_12 -> V_191 = V_191 ;
V_12 -> V_139 = 120 ;
V_12 -> V_103 = 8 ;
V_12 -> V_109 = F_72 ( 180 ) ;
V_12 -> V_137 = true ;
V_12 -> V_125 = 30 ;
V_12 -> V_127 = F_72 ( 300 ) ;
V_12 -> V_119 = 0 ;
V_12 -> V_130 = F_72 ( 2000 ) ;
V_12 -> V_144 = F_72 ( 500 ) ;
V_12 -> V_135 = 7000 ;
V_12 -> V_74 = 0 ;
V_12 -> V_120 = V_207 [ F_159 ( V_12 -> V_19 ) ] *
V_208 [ F_159 ( V_12 -> V_19 ) ] ;
V_12 -> V_121 = V_207 [ F_159 ( V_12 -> V_19 ) ] * 2 / 3 ;
V_12 -> V_201 = V_202 ;
F_282 ( & V_12 -> V_156 ) ;
V_12 -> V_312 = F_283 ( V_12 , V_8 -> V_176 ) ;
if ( ! V_12 -> V_312 )
goto V_333;
F_275 ( V_12 -> V_312 , V_12 ) ;
F_231 ( & V_12 -> V_183 . V_54 , V_12 -> V_312 ) ;
return 0 ;
V_333:
F_34 ( V_12 ) ;
F_279 ( & V_324 -> V_327 ) ;
return - V_325 ;
}
static void F_284 ( void )
{
F_285 ( V_263 ) ;
}
static int T_6 F_286 ( void )
{
V_263 = F_287 ( V_1 , 0 ) ;
if ( ! V_263 )
return - V_325 ;
return 0 ;
}
static T_7 F_288 ( unsigned int V_334 , char * V_335 )
{
return sprintf ( V_335 , L_47 , V_334 ) ;
}
static T_7 F_289 ( unsigned long * V_334 , const char * V_335 ,
T_8 V_336 )
{
unsigned long V_337 ;
int V_155 = F_290 ( V_335 , 10 , & V_337 ) ;
if ( V_155 == 0 )
* V_334 = V_337 ;
return V_336 ;
}
static T_7 F_291 ( struct V_313 * V_314 ,
const char * V_335 , T_8 V_336 )
{
struct V_6 * V_12 = V_314 -> V_10 ;
unsigned long V_338 ( V_339 ) ;
int V_155 = F_289 ( & V_339 , ( V_335 ) , V_336 ) ;
if ( V_339 == 0 )
V_12 -> F_74 = F_156 ( V_12 ) ;
else {
if ( V_339 > V_340 )
V_339 = V_340 ;
V_12 -> F_74 = V_339 ;
}
V_12 -> V_200 = V_339 ;
return V_155 ;
}
static T_7 F_292 ( struct V_313 * V_314 ,
const char * V_335 , T_8 V_336 )
{
struct V_6 * V_12 = V_314 -> V_10 ;
unsigned long V_338 ( V_339 ) ;
int V_155 = F_289 ( & V_339 , ( V_335 ) , V_336 ) ;
if ( V_339 < 1 )
V_339 = 1 ;
else if ( V_339 > V_340 )
V_339 = V_340 ;
V_12 -> V_191 = F_72 ( V_339 ) ;
if ( V_12 -> V_200 == 0 )
V_12 -> F_74 = F_156 ( V_12 ) ;
return V_155 ;
}
static T_7 F_293 ( struct V_313 * V_314 ,
const char * V_335 , T_8 V_336 )
{
struct V_6 * V_12 = V_314 -> V_10 ;
unsigned long V_338 ( V_339 ) ;
int V_155 = F_289 ( & V_339 , ( V_335 ) , V_336 ) ;
if ( V_339 > 1 )
V_339 = 1 ;
if ( ! V_12 -> V_251 && V_339 == 1
&& V_12 -> V_134 < 8 * V_227 )
V_12 -> V_134 = 8 * V_227 ;
V_12 -> V_251 = V_339 ;
return V_155 ;
}
static T_7 F_294 ( struct V_313 * V_314 ,
const char * V_335 , T_8 V_336 )
{
struct V_6 * V_12 = V_314 -> V_10 ;
unsigned long V_338 ( V_339 ) ;
int V_155 = F_289 ( & V_339 , ( V_335 ) , V_336 ) ;
if ( V_339 > 1 )
V_339 = 1 ;
if ( V_339 == 0 && V_12 -> V_137 != 0 )
F_125 ( V_12 ) ;
V_12 -> V_137 = V_339 ;
return V_155 ;
}
static int T_6 F_295 ( void )
{
int V_155 ;
#ifdef F_28
V_155 = F_296 ( & V_315 ) ;
if ( V_155 )
return V_155 ;
#endif
V_155 = - V_325 ;
if ( F_286 () )
goto V_341;
V_206 [ 0 ] = F_72 ( 3500 ) ;
V_206 [ 1 ] = F_72 ( 6000 ) ;
V_208 [ 0 ] = F_72 ( 7000 ) ;
V_208 [ 1 ] = F_72 ( 2500 ) ;
V_203 [ 0 ] = ( 4 * V_205 [ 0 ] ) / 3 ;
V_203 [ 1 ] = ( 4 * V_205 [ 1 ] ) / 3 ;
V_155 = F_297 ( & V_342 ) ;
if ( V_155 )
goto V_341;
return 0 ;
V_341:
#ifdef F_28
F_298 ( & V_315 ) ;
#endif
return V_155 ;
}
static void T_9 F_299 ( void )
{
F_300 ( & V_342 ) ;
#ifdef F_28
F_298 ( & V_315 ) ;
#endif
F_284 () ;
}
