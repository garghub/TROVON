static inline unsigned int F_1 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 )
{
unsigned int V_4 ;
if ( ! ( ( V_1 | V_2 | V_3 ) & 3 ) )
V_4 = 2 ;
else if ( ! ( ( V_1 | V_2 | V_3 ) & 1 ) )
V_4 = 1 ;
else
V_4 = 0 ;
return V_4 ;
}
static struct V_5 * F_2 ( struct V_6 * V_7 )
{
return F_3 ( & V_7 -> V_8 ,
struct V_5 , V_9 ) ;
}
static struct V_5 * F_4 ( struct V_6 * V_7 )
{
return F_3 ( & V_7 -> V_10 ,
struct V_5 , V_9 ) ;
}
static struct V_5 * F_5 ( struct V_11 * V_12 ,
T_3 V_13 )
{
struct V_5 * V_14 = NULL ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
T_1 V_18 ;
V_14 = F_7 ( V_16 -> V_19 , V_13 , & V_18 ) ;
if ( V_14 ) {
memset ( V_14 , 0 , sizeof( struct V_5 ) ) ;
F_8 ( & V_14 -> V_20 ) ;
F_9 ( & V_14 -> V_21 , V_12 ) ;
V_14 -> V_21 . V_22 = V_23 ;
V_14 -> V_21 . V_24 = V_25 ;
V_14 -> V_21 . V_18 = V_18 ;
}
return V_14 ;
}
static struct V_5 * F_10 ( struct V_6 * V_7 )
{
struct V_5 * V_14 , * V_26 ;
struct V_5 * V_27 = NULL ;
unsigned long V_22 ;
unsigned int V_28 = 0 ;
F_11 ( V_29 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_13 (desc, _desc, &atchan->free_list, desc_node) {
V_28 ++ ;
if ( F_14 ( & V_14 -> V_21 ) ) {
F_15 ( & V_14 -> V_9 ) ;
V_27 = V_14 ;
break;
}
F_16 ( F_17 ( & V_7 -> V_31 ) ,
L_1 , V_14 ) ;
}
F_18 ( & V_7 -> V_30 , V_22 ) ;
F_19 ( F_17 ( & V_7 -> V_31 ) ,
L_2 , V_28 ) ;
if ( ! V_27 ) {
V_27 = F_5 ( & V_7 -> V_31 , V_32 ) ;
if ( V_27 ) {
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_7 -> V_33 ++ ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
} else {
F_20 ( F_17 ( & V_7 -> V_31 ) ,
L_3 ) ;
}
}
return V_27 ;
}
static void F_21 ( struct V_6 * V_7 , struct V_5 * V_14 )
{
if ( V_14 ) {
struct V_5 * V_34 ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_22 (child, &desc->tx_list, desc_node)
F_19 ( F_17 ( & V_7 -> V_31 ) ,
L_4 ,
V_34 ) ;
F_23 ( & V_14 -> V_20 , & V_7 -> V_35 ) ;
F_19 ( F_17 ( & V_7 -> V_31 ) ,
L_5 , V_14 ) ;
F_24 ( & V_14 -> V_9 , & V_7 -> V_35 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
}
}
static void F_25 ( struct V_5 * * V_36 , struct V_5 * * V_37 ,
struct V_5 * V_14 )
{
if ( ! ( * V_36 ) ) {
* V_36 = V_14 ;
} else {
( * V_37 ) -> V_38 . V_39 = V_14 -> V_21 . V_18 ;
F_26 ( & V_14 -> V_9 ,
& ( * V_36 ) -> V_20 ) ;
}
* V_37 = V_14 ;
}
static void F_27 ( struct V_6 * V_7 , struct V_5 * V_36 )
{
struct V_15 * V_16 = F_6 ( V_7 -> V_31 . V_17 ) ;
if ( F_28 ( V_7 ) ) {
F_20 ( F_17 ( & V_7 -> V_31 ) ,
L_6 ) ;
F_20 ( F_17 ( & V_7 -> V_31 ) ,
L_7 ,
F_29 ( V_7 , V_40 ) ,
F_29 ( V_7 , V_41 ) ,
F_29 ( V_7 , V_42 ) ,
F_29 ( V_7 , V_43 ) ,
F_29 ( V_7 , V_44 ) ) ;
return;
}
F_30 ( V_7 ) ;
F_31 ( V_7 , V_40 , 0 ) ;
F_31 ( V_7 , V_41 , 0 ) ;
F_31 ( V_7 , V_42 , 0 ) ;
F_31 ( V_7 , V_43 , 0 ) ;
F_31 ( V_7 , V_44 , V_36 -> V_21 . V_18 ) ;
F_31 ( V_7 , V_45 , F_32 ( V_36 -> V_46 ) |
F_33 ( V_36 -> V_47 ) ) ;
F_31 ( V_7 , V_48 , F_34 ( V_36 -> V_49 ) |
F_35 ( V_36 -> V_47 ) ) ;
F_36 ( V_16 , V_50 , V_7 -> V_51 ) ;
F_30 ( V_7 ) ;
}
static struct V_5 * F_37 ( struct V_6 * V_7 ,
T_4 V_52 )
{
struct V_5 * V_14 , * V_26 ;
F_13 (desc, _desc, &atchan->queue, desc_node) {
if ( V_14 -> V_21 . V_52 == V_52 )
return V_14 ;
}
F_13 (desc, _desc, &atchan->active_list, desc_node) {
if ( V_14 -> V_21 . V_52 == V_52 )
return V_14 ;
}
return NULL ;
}
static inline int F_38 ( int V_53 , T_5 V_54 )
{
T_5 V_55 = ( V_54 & V_56 ) ;
T_5 V_57 = F_39 ( V_54 ) ;
return V_53 - ( V_55 << V_57 ) ;
}
static int F_40 ( struct V_11 * V_12 , T_4 V_52 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_5 * V_58 = F_2 ( V_7 ) ;
struct V_5 * V_14 ;
int V_27 ;
T_5 V_54 , V_39 , V_59 ;
V_14 = F_37 ( V_7 , V_52 ) ;
if ( V_14 == NULL )
return - V_60 ;
else if ( V_14 != V_58 )
return V_14 -> V_61 ;
V_27 = V_58 -> V_61 ;
if ( V_58 -> V_38 . V_39 ) {
V_39 = F_29 ( V_7 , V_44 ) ;
F_42 () ;
V_54 = F_29 ( V_7 , V_42 ) ;
for ( V_59 = 0 ; V_59 < V_62 ; ++ V_59 ) {
T_5 V_63 ;
F_42 () ;
V_63 = F_29 ( V_7 , V_44 ) ;
if ( F_43 ( V_63 == V_39 ) )
break;
V_39 = V_63 ;
F_42 () ;
V_54 = F_29 ( V_7 , V_42 ) ;
}
if ( F_44 ( V_59 >= V_62 ) )
return - V_64 ;
if ( V_58 -> V_38 . V_39 == V_39 )
return F_38 ( V_27 , V_54 ) ;
V_27 -= V_58 -> V_3 ;
F_22 (desc, &desc_first->tx_list, desc_node) {
if ( V_14 -> V_38 . V_39 == V_39 )
break;
V_27 -= V_14 -> V_3 ;
}
V_27 = F_38 ( V_27 , V_54 ) ;
} else {
V_54 = F_29 ( V_7 , V_42 ) ;
V_27 = F_38 ( V_27 , V_54 ) ;
}
return V_27 ;
}
static void
F_45 ( struct V_6 * V_7 , struct V_5 * V_14 )
{
struct V_65 * V_21 = & V_14 -> V_21 ;
F_19 ( F_17 ( & V_7 -> V_31 ) ,
L_8 , V_21 -> V_52 ) ;
if ( ! F_46 ( V_7 ) )
F_47 ( V_21 ) ;
F_23 ( & V_14 -> V_20 , & V_7 -> V_35 ) ;
F_48 ( & V_14 -> V_9 , & V_7 -> V_35 ) ;
F_49 ( V_21 ) ;
if ( ! F_46 ( V_7 ) ) {
T_6 V_66 = V_21 -> V_66 ;
void * V_67 = V_21 -> V_68 ;
if ( V_66 )
V_66 ( V_67 ) ;
}
F_50 ( V_21 ) ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_5 * V_14 , * V_26 ;
F_11 ( V_69 ) ;
F_19 ( F_17 ( & V_7 -> V_31 ) , L_9 ) ;
if ( ! F_52 ( & V_7 -> V_10 ) )
F_27 ( V_7 , F_4 ( V_7 ) ) ;
F_23 ( & V_7 -> V_8 , & V_69 ) ;
F_23 ( & V_7 -> V_10 , & V_7 -> V_8 ) ;
F_13 (desc, _desc, &list, desc_node)
F_45 ( V_7 , V_14 ) ;
}
static void F_53 ( struct V_6 * V_7 )
{
F_19 ( F_17 ( & V_7 -> V_31 ) , L_10 ) ;
if ( F_28 ( V_7 ) )
return;
if ( F_52 ( & V_7 -> V_8 ) ||
F_54 ( & V_7 -> V_8 ) ) {
F_51 ( V_7 ) ;
} else {
F_45 ( V_7 , F_2 ( V_7 ) ) ;
F_27 ( V_7 , F_2 ( V_7 ) ) ;
}
}
static void F_55 ( struct V_6 * V_7 )
{
struct V_5 * V_70 ;
struct V_5 * V_34 ;
V_70 = F_2 ( V_7 ) ;
F_56 ( & V_70 -> V_9 ) ;
F_23 ( & V_7 -> V_10 , V_7 -> V_8 . V_37 ) ;
if ( ! F_52 ( & V_7 -> V_8 ) )
F_27 ( V_7 , F_2 ( V_7 ) ) ;
F_57 ( F_17 ( & V_7 -> V_31 ) ,
L_11 ) ;
F_57 ( F_17 ( & V_7 -> V_31 ) ,
L_12 , V_70 -> V_21 . V_52 ) ;
F_58 ( V_7 , & V_70 -> V_38 ) ;
F_22 (child, &bad_desc->tx_list, desc_node)
F_58 ( V_7 , & V_34 -> V_38 ) ;
F_45 ( V_7 , V_70 ) ;
}
static void F_59 ( struct V_6 * V_7 )
{
struct V_5 * V_36 = F_2 ( V_7 ) ;
struct V_65 * V_21 = & V_36 -> V_21 ;
T_6 V_66 = V_21 -> V_66 ;
void * V_67 = V_21 -> V_68 ;
F_19 ( F_17 ( & V_7 -> V_31 ) ,
L_13 ,
F_29 ( V_7 , V_44 ) ) ;
if ( V_66 )
V_66 ( V_67 ) ;
}
static void F_60 ( unsigned long V_71 )
{
struct V_6 * V_7 = (struct V_6 * ) V_71 ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
if ( F_61 ( V_72 , & V_7 -> V_73 ) )
F_55 ( V_7 ) ;
else if ( F_46 ( V_7 ) )
F_59 ( V_7 ) ;
else
F_53 ( V_7 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
}
static T_7 F_62 ( int V_74 , void * V_75 )
{
struct V_15 * V_16 = (struct V_15 * ) V_75 ;
struct V_6 * V_7 ;
int V_28 ;
T_5 V_73 , V_76 , V_77 ;
int V_27 = V_78 ;
do {
V_77 = F_63 ( V_16 , V_79 ) ;
V_73 = F_63 ( V_16 , V_80 ) ;
V_76 = V_73 & V_77 ;
if ( ! V_76 )
break;
F_19 ( V_16 -> V_81 . V_82 ,
L_14 ,
V_73 , V_77 , V_76 ) ;
for ( V_28 = 0 ; V_28 < V_16 -> V_81 . V_83 ; V_28 ++ ) {
V_7 = & V_16 -> V_12 [ V_28 ] ;
if ( V_76 & ( F_64 ( V_28 ) | F_65 ( V_28 ) ) ) {
if ( V_76 & F_65 ( V_28 ) ) {
F_36 ( V_16 , V_84 ,
F_66 ( V_28 ) | V_7 -> V_51 ) ;
F_67 ( V_72 , & V_7 -> V_73 ) ;
}
F_68 ( & V_7 -> V_85 ) ;
V_27 = V_86 ;
}
}
} while ( V_76 );
return V_27 ;
}
static T_4 V_25 ( struct V_65 * V_87 )
{
struct V_5 * V_14 = F_69 ( V_87 ) ;
struct V_6 * V_7 = F_41 ( V_87 -> V_12 ) ;
T_4 V_52 ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_52 = F_70 ( V_87 ) ;
if ( F_52 ( & V_7 -> V_8 ) ) {
F_19 ( F_17 ( V_87 -> V_12 ) , L_15 ,
V_14 -> V_21 . V_52 ) ;
F_27 ( V_7 , V_14 ) ;
F_26 ( & V_14 -> V_9 , & V_7 -> V_8 ) ;
} else {
F_19 ( F_17 ( V_87 -> V_12 ) , L_16 ,
V_14 -> V_21 . V_52 ) ;
F_26 ( & V_14 -> V_9 , & V_7 -> V_10 ) ;
}
F_18 ( & V_7 -> V_30 , V_22 ) ;
return V_52 ;
}
static struct V_65 *
F_71 ( struct V_11 * V_12 ,
struct V_88 * V_89 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_90 * V_36 = V_89 -> V_91 ;
struct V_5 * V_14 = NULL ;
T_2 V_92 ;
unsigned int V_93 ;
T_5 V_54 ;
T_5 V_94 ;
T_2 V_3 = 0 ;
int V_28 ;
F_72 ( F_17 ( V_12 ) ,
L_17 ,
V_95 , V_89 -> V_96 , V_89 -> V_97 , V_89 -> V_98 ,
V_89 -> V_99 , V_22 ) ;
if ( F_44 ( ! V_89 || V_89 -> V_98 != 1 || ! V_89 -> V_99 ) )
return NULL ;
for ( V_28 = 0 ; V_28 < V_89 -> V_99 ; V_28 ++ ) {
struct V_90 * V_100 = V_89 -> V_91 + V_28 ;
if ( ( V_100 -> V_101 != V_89 -> V_91 -> V_101 ) ||
( F_73 ( V_89 , V_100 ) != F_73 ( V_89 , V_36 ) ) ||
( F_74 ( V_89 , V_100 ) != F_74 ( V_89 , V_36 ) ) ) {
F_20 ( F_17 ( V_12 ) ,
L_18 ,
V_95 ) ;
return NULL ;
}
V_3 += V_100 -> V_101 ;
}
V_93 = F_1 ( V_89 -> V_96 ,
V_89 -> V_97 , V_3 ) ;
V_92 = V_3 >> V_93 ;
if ( V_92 > V_56 ) {
F_20 ( F_17 ( V_12 ) , L_19 , V_95 ) ;
return NULL ;
}
V_54 = F_75 ( V_93 ) |
F_76 ( V_93 ) ;
V_94 = V_102 | V_103
| V_104
| V_105
| V_106
| V_107
| V_108 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 ) {
F_20 ( F_17 ( V_12 ) ,
L_20 , V_95 ) ;
return NULL ;
}
V_14 -> V_38 . V_109 = V_89 -> V_96 ;
V_14 -> V_38 . V_110 = V_89 -> V_97 ;
V_14 -> V_38 . V_54 = V_54 | V_92 ;
V_14 -> V_38 . V_94 = V_94 ;
V_14 -> V_47 = V_36 -> V_101 >> V_93 ;
V_14 -> V_49 = ( F_73 ( V_89 , V_36 ) >> V_93 ) + 1 ;
V_14 -> V_46 = ( F_74 ( V_89 , V_36 ) >> V_93 ) + 1 ;
V_14 -> V_21 . V_52 = - V_111 ;
V_14 -> V_61 = V_14 -> V_3 = V_3 ;
F_77 ( V_14 ) ;
V_14 -> V_21 . V_22 = V_22 ;
return & V_14 -> V_21 ;
}
static struct V_65 *
F_78 ( struct V_11 * V_12 , T_1 V_112 , T_1 V_1 ,
T_2 V_3 , unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_5 * V_14 = NULL ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
T_2 V_92 ;
T_2 V_113 ;
unsigned int V_57 ;
unsigned int V_114 ;
T_5 V_54 ;
T_5 V_94 ;
F_19 ( F_17 ( V_12 ) , L_21 ,
V_112 , V_1 , V_3 , V_22 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) , L_22 ) ;
return NULL ;
}
V_94 = V_102 | V_103
| V_104
| V_105
| V_108 ;
V_57 = V_114 = F_1 ( V_1 , V_112 , V_3 ) ;
V_54 = F_75 ( V_57 ) |
F_76 ( V_114 ) ;
for ( V_113 = 0 ; V_113 < V_3 ; V_113 += V_92 << V_57 ) {
V_92 = F_79 ( T_2 , ( V_3 - V_113 ) >> V_57 ,
V_56 ) ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_115;
V_14 -> V_38 . V_109 = V_1 + V_113 ;
V_14 -> V_38 . V_110 = V_112 + V_113 ;
V_14 -> V_38 . V_54 = V_54 | V_92 ;
V_14 -> V_38 . V_94 = V_94 ;
V_14 -> V_21 . V_52 = 0 ;
V_14 -> V_3 = V_92 << V_57 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
}
V_36 -> V_21 . V_52 = - V_111 ;
V_36 -> V_61 = V_3 ;
F_77 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_115:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_65 *
F_80 ( struct V_11 * V_12 , struct V_116 * V_91 ,
unsigned int V_117 , enum V_118 V_119 ,
unsigned long V_22 , void * V_120 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_121 * V_122 = V_12 -> V_123 ;
struct V_124 * V_125 = & V_7 -> V_126 ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
T_5 V_54 ;
T_5 V_94 ;
T_1 V_127 ;
unsigned int V_128 ;
unsigned int V_129 ;
unsigned int V_28 ;
struct V_116 * V_130 ;
T_2 V_61 = 0 ;
F_19 ( F_17 ( V_12 ) , L_23 ,
V_117 ,
V_119 == V_131 ? L_24 : L_25 ,
V_22 ) ;
if ( F_44 ( ! V_122 || ! V_117 ) ) {
F_16 ( F_17 ( V_12 ) , L_26 ) ;
return NULL ;
}
V_54 = F_81 ( V_125 -> V_132 )
| F_82 ( V_125 -> V_133 ) ;
V_94 = V_103 ;
switch ( V_119 ) {
case V_131 :
V_128 = F_83 ( V_125 -> V_134 ) ;
V_54 |= F_76 ( V_128 ) ;
V_94 |= V_135
| V_104
| V_136
| F_84 ( V_7 -> V_137 ) | F_85 ( V_7 -> V_138 ) ;
V_127 = V_125 -> V_139 ;
F_86 (sgl, sg, sg_len, i) {
struct V_5 * V_14 ;
T_5 V_3 ;
T_5 V_140 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_115;
V_140 = F_87 ( V_130 ) ;
V_3 = F_88 ( V_130 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) ,
L_27 , V_28 ) ;
goto V_141;
}
V_129 = 2 ;
if ( F_44 ( V_140 & 3 || V_3 & 3 ) )
V_129 = 0 ;
V_14 -> V_38 . V_109 = V_140 ;
V_14 -> V_38 . V_110 = V_127 ;
V_14 -> V_38 . V_54 = V_54
| F_75 ( V_129 )
| V_3 >> V_129 ;
V_14 -> V_38 . V_94 = V_94 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_61 += V_3 ;
}
break;
case V_142 :
V_128 = F_83 ( V_125 -> V_143 ) ;
V_54 |= F_75 ( V_128 ) ;
V_94 |= V_105
| V_144
| V_145
| F_84 ( V_7 -> V_138 ) | F_85 ( V_7 -> V_137 ) ;
V_127 = V_125 -> V_146 ;
F_86 (sgl, sg, sg_len, i) {
struct V_5 * V_14 ;
T_5 V_3 ;
T_5 V_140 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_115;
V_140 = F_87 ( V_130 ) ;
V_3 = F_88 ( V_130 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) ,
L_27 , V_28 ) ;
goto V_141;
}
V_129 = 2 ;
if ( F_44 ( V_140 & 3 || V_3 & 3 ) )
V_129 = 0 ;
V_14 -> V_38 . V_109 = V_127 ;
V_14 -> V_38 . V_110 = V_140 ;
V_14 -> V_38 . V_54 = V_54
| F_76 ( V_129 )
| V_3 >> V_128 ;
V_14 -> V_38 . V_94 = V_94 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_61 += V_3 ;
}
break;
default:
return NULL ;
}
F_77 ( V_37 ) ;
V_36 -> V_21 . V_52 = - V_111 ;
V_36 -> V_61 = V_61 ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_115:
F_20 ( F_17 ( V_12 ) , L_3 ) ;
V_141:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_65 *
F_89 ( struct V_11 * V_12 ,
struct V_116 * V_147 , unsigned int V_148 ,
struct V_116 * V_149 , unsigned int V_150 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_5 * V_14 = NULL ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
unsigned int V_57 ;
unsigned int V_114 ;
T_2 V_92 ;
T_5 V_54 ;
T_5 V_94 ;
T_2 V_151 = 0 , V_152 = 0 ;
T_1 V_2 = 0 , V_1 = 0 ;
T_2 V_3 = 0 , V_61 = 0 ;
if ( F_44 ( V_148 == 0 || V_150 == 0 ) )
return NULL ;
if ( F_44 ( V_147 == NULL || V_149 == NULL ) )
return NULL ;
V_94 = V_102 | V_103
| V_104
| V_105
| V_108 ;
while ( true ) {
if ( V_151 == 0 ) {
if ( ! V_147 || ! V_148 )
break;
V_2 = F_87 ( V_147 ) ;
V_151 = F_88 ( V_147 ) ;
V_147 = F_90 ( V_147 ) ;
V_148 -- ;
}
if ( V_152 == 0 ) {
if ( ! V_149 || ! V_150 )
break;
V_1 = F_87 ( V_149 ) ;
V_152 = F_88 ( V_149 ) ;
V_149 = F_90 ( V_149 ) ;
V_150 -- ;
}
V_3 = F_79 ( T_2 , V_152 , V_151 ) ;
if ( V_3 == 0 )
continue;
V_57 = V_114 = F_1 ( V_1 , V_2 , V_3 ) ;
V_54 = F_75 ( V_57 ) |
F_76 ( V_114 ) ;
V_92 = V_3 >> V_57 ;
if ( V_92 > V_56 ) {
V_92 = V_56 ;
V_3 = V_56 << V_57 ;
}
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_115;
V_14 -> V_38 . V_109 = V_1 ;
V_14 -> V_38 . V_110 = V_2 ;
V_14 -> V_38 . V_54 = V_54 | V_92 ;
V_14 -> V_38 . V_94 = V_94 ;
V_14 -> V_21 . V_52 = 0 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_151 -= V_3 ;
V_152 -= V_3 ;
V_2 += V_3 ;
V_1 += V_3 ;
V_61 += V_3 ;
}
V_36 -> V_21 . V_52 = - V_111 ;
V_36 -> V_61 = V_61 ;
F_77 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_115:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static int
F_91 ( unsigned int V_128 , T_1 V_153 ,
T_2 V_154 )
{
if ( V_154 > ( V_56 << V_128 ) )
goto V_155;
if ( F_44 ( V_154 & ( ( 1 << V_128 ) - 1 ) ) )
goto V_155;
if ( F_44 ( V_153 & ( ( 1 << V_128 ) - 1 ) ) )
goto V_155;
return 0 ;
V_155:
return - V_60 ;
}
static int
F_92 ( struct V_11 * V_12 , struct V_5 * V_14 ,
unsigned int V_156 , T_1 V_153 ,
unsigned int V_128 , T_2 V_154 ,
enum V_118 V_119 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_124 * V_125 = & V_7 -> V_126 ;
T_5 V_54 ;
V_54 = F_81 ( V_125 -> V_132 )
| F_82 ( V_125 -> V_133 )
| F_76 ( V_128 )
| F_75 ( V_128 )
| V_154 >> V_128 ;
switch ( V_119 ) {
case V_131 :
V_14 -> V_38 . V_109 = V_153 + ( V_154 * V_156 ) ;
V_14 -> V_38 . V_110 = V_125 -> V_139 ;
V_14 -> V_38 . V_54 = V_54 ;
V_14 -> V_38 . V_94 = V_135
| V_104
| V_136
| F_84 ( V_7 -> V_137 )
| F_85 ( V_7 -> V_138 ) ;
V_14 -> V_3 = V_154 ;
break;
case V_142 :
V_14 -> V_38 . V_109 = V_125 -> V_146 ;
V_14 -> V_38 . V_110 = V_153 + ( V_154 * V_156 ) ;
V_14 -> V_38 . V_54 = V_54 ;
V_14 -> V_38 . V_94 = V_105
| V_144
| V_145
| F_84 ( V_7 -> V_138 )
| F_85 ( V_7 -> V_137 ) ;
V_14 -> V_3 = V_154 ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static struct V_65 *
F_93 ( struct V_11 * V_12 , T_1 V_153 , T_2 V_157 ,
T_2 V_154 , enum V_118 V_119 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_121 * V_122 = V_12 -> V_123 ;
struct V_124 * V_125 = & V_7 -> V_126 ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
unsigned long V_158 ;
unsigned int V_128 ;
unsigned int V_159 = V_157 / V_154 ;
unsigned int V_28 ;
F_19 ( F_17 ( V_12 ) , L_28 ,
V_119 == V_131 ? L_24 : L_25 ,
V_153 ,
V_159 , V_157 , V_154 ) ;
if ( F_44 ( ! V_122 || ! V_157 || ! V_154 ) ) {
F_16 ( F_17 ( V_12 ) , L_29 ) ;
return NULL ;
}
V_158 = F_94 ( V_160 , & V_7 -> V_73 ) ;
if ( V_158 ) {
F_16 ( F_17 ( V_12 ) , L_30 ) ;
return NULL ;
}
if ( F_44 ( ! F_95 ( V_119 ) ) )
goto V_155;
if ( V_125 -> V_119 == V_131 )
V_128 = F_83 ( V_125 -> V_134 ) ;
else
V_128 = F_83 ( V_125 -> V_143 ) ;
if ( F_91 ( V_128 , V_153 , V_154 ) )
goto V_155;
for ( V_28 = 0 ; V_28 < V_159 ; V_28 ++ ) {
struct V_5 * V_14 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_115;
if ( F_92 ( V_12 , V_14 , V_28 , V_153 ,
V_128 , V_154 , V_119 ) )
goto V_115;
F_25 ( & V_36 , & V_37 , V_14 ) ;
}
V_37 -> V_38 . V_39 = V_36 -> V_21 . V_18 ;
V_36 -> V_21 . V_52 = - V_111 ;
V_36 -> V_61 = V_157 ;
return & V_36 -> V_21 ;
V_115:
F_20 ( F_17 ( V_12 ) , L_3 ) ;
F_21 ( V_7 , V_36 ) ;
V_155:
F_96 ( V_160 , & V_7 -> V_73 ) ;
return NULL ;
}
static int F_97 ( struct V_11 * V_12 ,
struct V_124 * V_125 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_19 ( F_17 ( V_12 ) , L_31 , V_95 ) ;
if ( ! V_12 -> V_123 )
return - V_60 ;
memcpy ( & V_7 -> V_126 , V_125 , sizeof( * V_125 ) ) ;
F_98 ( & V_7 -> V_126 . V_132 ) ;
F_98 ( & V_7 -> V_126 . V_133 ) ;
return 0 ;
}
static int F_99 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_161 = V_7 -> V_31 . V_161 ;
unsigned long V_22 ;
F_11 ( V_69 ) ;
F_19 ( F_17 ( V_12 ) , L_31 , V_95 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_50 , F_100 ( V_161 ) ) ;
F_67 ( V_162 , & V_7 -> V_73 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_101 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_161 = V_7 -> V_31 . V_161 ;
unsigned long V_22 ;
F_11 ( V_69 ) ;
F_19 ( F_17 ( V_12 ) , L_31 , V_95 ) ;
if ( ! F_102 ( V_7 ) )
return 0 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_84 , F_66 ( V_161 ) ) ;
F_96 ( V_162 , & V_7 -> V_73 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_103 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_161 = V_7 -> V_31 . V_161 ;
struct V_5 * V_14 , * V_26 ;
unsigned long V_22 ;
F_11 ( V_69 ) ;
F_19 ( F_17 ( V_12 ) , L_31 , V_95 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_84 , F_66 ( V_161 ) | V_7 -> V_51 ) ;
while ( F_63 ( V_16 , V_163 ) & V_7 -> V_51 )
F_104 () ;
F_23 ( & V_7 -> V_10 , & V_69 ) ;
F_23 ( & V_7 -> V_8 , & V_69 ) ;
F_13 (desc, _desc, &list, desc_node)
F_45 ( V_7 , V_14 ) ;
F_96 ( V_162 , & V_7 -> V_73 ) ;
F_96 ( V_160 , & V_7 -> V_73 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static enum V_164
F_105 ( struct V_11 * V_12 ,
T_4 V_52 ,
struct V_165 * V_166 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
unsigned long V_22 ;
enum V_164 V_27 ;
int V_167 = 0 ;
V_27 = F_106 ( V_12 , V_52 , V_166 ) ;
if ( V_27 == V_168 )
return V_27 ;
if ( ! V_166 )
return V_169 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_167 = F_40 ( V_12 , V_52 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
if ( F_44 ( V_167 < 0 ) ) {
F_19 ( F_17 ( V_12 ) , L_32 ) ;
return V_169 ;
} else {
F_107 ( V_166 , V_167 ) ;
}
F_19 ( F_17 ( V_12 ) , L_33 ,
V_27 , V_52 , V_167 ) ;
return V_27 ;
}
static void F_108 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
unsigned long V_22 ;
F_19 ( F_17 ( V_12 ) , L_34 ) ;
if ( F_46 ( V_7 ) )
return;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_53 ( V_7 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
}
static int F_109 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 ;
struct V_121 * V_122 ;
unsigned long V_22 ;
int V_28 ;
T_5 V_170 ;
F_11 ( V_29 ) ;
F_19 ( F_17 ( V_12 ) , L_35 ) ;
if ( F_28 ( V_7 ) ) {
F_16 ( F_17 ( V_12 ) , L_36 ) ;
return - V_171 ;
}
V_170 = V_172 ;
V_122 = V_12 -> V_123 ;
if ( V_122 ) {
F_110 ( ! V_122 -> V_173 || V_122 -> V_173 != V_16 -> V_81 . V_82 ) ;
if ( V_122 -> V_170 )
V_170 = V_122 -> V_170 ;
}
if ( ! F_52 ( & V_7 -> V_35 ) )
return V_7 -> V_33 ;
for ( V_28 = 0 ; V_28 < V_174 ; V_28 ++ ) {
V_14 = F_5 ( V_12 , V_175 ) ;
if ( ! V_14 ) {
F_20 ( V_16 -> V_81 . V_82 ,
L_37 , V_28 ) ;
break;
}
F_26 ( & V_14 -> V_9 , & V_29 ) ;
}
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_7 -> V_33 = V_28 ;
F_111 ( & V_29 , & V_7 -> V_35 ) ;
F_112 ( V_12 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
F_31 ( V_7 , V_176 , V_170 ) ;
F_16 ( F_17 ( V_12 ) ,
L_38 ,
V_7 -> V_33 ) ;
return V_7 -> V_33 ;
}
static void F_113 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 , * V_26 ;
F_11 ( V_69 ) ;
F_16 ( F_17 ( V_12 ) , L_39 ,
V_7 -> V_33 ) ;
F_110 ( ! F_52 ( & V_7 -> V_8 ) ) ;
F_110 ( ! F_52 ( & V_7 -> V_10 ) ) ;
F_110 ( F_28 ( V_7 ) ) ;
F_13 (desc, _desc, &atchan->free_list, desc_node) {
F_19 ( F_17 ( V_12 ) , L_40 , V_14 ) ;
F_15 ( & V_14 -> V_9 ) ;
F_114 ( V_16 -> V_19 , V_14 , V_14 -> V_21 . V_18 ) ;
}
F_23 ( & V_7 -> V_35 , & V_69 ) ;
V_7 -> V_33 = 0 ;
V_7 -> V_73 = 0 ;
F_19 ( F_17 ( V_12 ) , L_41 ) ;
}
static bool F_115 ( struct V_11 * V_12 , void * V_177 )
{
struct V_121 * V_122 = V_177 ;
if ( V_122 -> V_173 == V_12 -> V_17 -> V_82 ) {
V_12 -> V_123 = V_122 ;
return true ;
} else {
return false ;
}
}
static struct V_11 * F_116 ( struct V_178 * V_179 ,
struct V_180 * V_180 )
{
struct V_11 * V_12 ;
struct V_6 * V_7 ;
struct V_121 * V_122 ;
T_8 V_51 ;
unsigned int V_181 ;
struct V_182 * V_183 ;
if ( V_179 -> V_184 != 2 )
return NULL ;
V_183 = F_117 ( V_179 -> V_185 ) ;
F_118 ( V_51 ) ;
F_119 ( V_186 , V_51 ) ;
V_122 = F_120 ( & V_183 -> V_82 , sizeof( * V_122 ) , V_175 ) ;
if ( ! V_122 )
return NULL ;
V_122 -> V_170 = V_187 | V_188 ;
V_181 = V_179 -> args [ 1 ] & V_189 ;
V_122 -> V_170 |= F_121 ( V_181 ) | F_122 ( V_181 )
| F_123 ( V_181 ) | F_124 ( V_181 ) ;
switch ( V_179 -> args [ 1 ] & V_190 ) {
case V_191 :
V_122 -> V_170 |= V_192 ;
break;
case V_193 :
V_122 -> V_170 |= V_194 ;
break;
case V_195 :
default:
V_122 -> V_170 |= V_196 ;
}
V_122 -> V_173 = & V_183 -> V_82 ;
V_12 = F_125 ( V_51 , F_115 , V_122 ) ;
if ( ! V_12 )
return NULL ;
V_7 = F_41 ( V_12 ) ;
V_7 -> V_138 = V_179 -> args [ 0 ] & 0xff ;
V_7 -> V_137 = ( V_179 -> args [ 0 ] >> 16 ) & 0xff ;
return V_12 ;
}
static struct V_11 * F_116 ( struct V_178 * V_179 ,
struct V_180 * V_180 )
{
return NULL ;
}
static inline const struct V_197 * T_9 F_126 (
struct V_182 * V_198 )
{
if ( V_198 -> V_82 . V_199 ) {
const struct V_200 * V_201 ;
V_201 = F_127 ( V_202 , V_198 -> V_82 . V_199 ) ;
if ( V_201 == NULL )
return NULL ;
return V_201 -> V_71 ;
}
return (struct V_197 * )
F_128 ( V_198 ) -> V_203 ;
}
static void F_129 ( struct V_15 * V_16 )
{
F_36 ( V_16 , V_204 , 0 ) ;
F_36 ( V_16 , V_205 , - 1L ) ;
while ( F_63 ( V_16 , V_163 ) & V_16 -> V_206 )
F_104 () ;
}
static int T_9 F_130 ( struct V_182 * V_198 )
{
struct V_207 * V_208 ;
struct V_15 * V_16 ;
T_2 V_101 ;
int V_74 ;
int V_141 ;
int V_28 ;
const struct V_197 * V_209 ;
F_119 ( V_210 , V_211 . V_212 ) ;
F_119 ( V_213 , V_211 . V_212 ) ;
F_119 ( V_214 , V_215 . V_212 ) ;
F_119 ( V_210 , V_215 . V_212 ) ;
F_119 ( V_186 , V_215 . V_212 ) ;
F_119 ( V_213 , V_215 . V_212 ) ;
V_209 = F_126 ( V_198 ) ;
if ( ! V_209 )
return - V_216 ;
V_208 = F_131 ( V_198 , V_217 , 0 ) ;
if ( ! V_208 )
return - V_60 ;
V_74 = F_132 ( V_198 , 0 ) ;
if ( V_74 < 0 )
return V_74 ;
V_101 = sizeof( struct V_15 ) ;
V_101 += V_209 -> V_218 * sizeof( struct V_6 ) ;
V_16 = F_133 ( V_101 , V_175 ) ;
if ( ! V_16 )
return - V_219 ;
V_16 -> V_81 . V_212 = V_209 -> V_212 ;
V_16 -> V_206 = ( 1 << V_209 -> V_218 ) - 1 ;
V_101 = F_134 ( V_208 ) ;
if ( ! F_135 ( V_208 -> V_220 , V_101 , V_198 -> V_82 . V_221 -> V_222 ) ) {
V_141 = - V_111 ;
goto V_223;
}
V_16 -> V_224 = F_136 ( V_208 -> V_220 , V_101 ) ;
if ( ! V_16 -> V_224 ) {
V_141 = - V_219 ;
goto V_225;
}
V_16 -> V_226 = F_137 ( & V_198 -> V_82 , L_42 ) ;
if ( F_138 ( V_16 -> V_226 ) ) {
V_141 = F_139 ( V_16 -> V_226 ) ;
goto V_227;
}
V_141 = F_140 ( V_16 -> V_226 ) ;
if ( V_141 )
goto V_228;
F_129 ( V_16 ) ;
V_141 = F_141 ( V_74 , F_62 , 0 , L_43 , V_16 ) ;
if ( V_141 )
goto V_229;
F_142 ( V_198 , V_16 ) ;
V_16 -> V_19 = F_143 ( L_44 ,
& V_198 -> V_82 , sizeof( struct V_5 ) ,
4 , 0 ) ;
if ( ! V_16 -> V_19 ) {
F_20 ( & V_198 -> V_82 , L_45 ) ;
V_141 = - V_219 ;
goto V_230;
}
while ( F_63 ( V_16 , V_80 ) )
F_104 () ;
F_8 ( & V_16 -> V_81 . V_231 ) ;
for ( V_28 = 0 ; V_28 < V_209 -> V_218 ; V_28 ++ ) {
struct V_6 * V_7 = & V_16 -> V_12 [ V_28 ] ;
V_7 -> V_137 = V_232 ;
V_7 -> V_138 = V_233 ;
V_7 -> V_31 . V_17 = & V_16 -> V_81 ;
F_112 ( & V_7 -> V_31 ) ;
F_26 ( & V_7 -> V_31 . V_234 ,
& V_16 -> V_81 . V_231 ) ;
V_7 -> V_235 = V_16 -> V_224 + V_235 ( V_28 ) ;
F_144 ( & V_7 -> V_30 ) ;
V_7 -> V_51 = 1 << V_28 ;
F_8 ( & V_7 -> V_8 ) ;
F_8 ( & V_7 -> V_10 ) ;
F_8 ( & V_7 -> V_35 ) ;
F_145 ( & V_7 -> V_85 , F_60 ,
( unsigned long ) V_7 ) ;
F_146 ( V_16 , V_28 ) ;
}
V_16 -> V_81 . V_236 = F_109 ;
V_16 -> V_81 . V_237 = F_113 ;
V_16 -> V_81 . V_238 = F_105 ;
V_16 -> V_81 . V_239 = F_108 ;
V_16 -> V_81 . V_82 = & V_198 -> V_82 ;
if ( F_147 ( V_214 , V_16 -> V_81 . V_212 ) )
V_16 -> V_81 . V_240 = F_71 ;
if ( F_147 ( V_210 , V_16 -> V_81 . V_212 ) )
V_16 -> V_81 . V_241 = F_78 ;
if ( F_147 ( V_186 , V_16 -> V_81 . V_212 ) ) {
V_16 -> V_81 . V_242 = F_80 ;
F_119 ( V_243 , V_16 -> V_81 . V_212 ) ;
V_16 -> V_81 . V_244 = F_93 ;
V_16 -> V_81 . V_245 = F_97 ;
V_16 -> V_81 . V_246 = F_99 ;
V_16 -> V_81 . V_247 = F_101 ;
V_16 -> V_81 . V_248 = F_103 ;
V_16 -> V_81 . V_249 = V_250 ;
V_16 -> V_81 . V_251 = V_250 ;
V_16 -> V_81 . V_252 = F_148 ( V_142 ) | F_148 ( V_131 ) ;
V_16 -> V_81 . V_253 = V_254 ;
}
if ( F_147 ( V_213 , V_16 -> V_81 . V_212 ) )
V_16 -> V_81 . V_255 = F_89 ;
F_36 ( V_16 , V_204 , V_256 ) ;
F_72 ( & V_198 -> V_82 , L_46 ,
F_147 ( V_210 , V_16 -> V_81 . V_212 ) ? L_47 : L_48 ,
F_147 ( V_186 , V_16 -> V_81 . V_212 ) ? L_49 : L_48 ,
F_147 ( V_213 , V_16 -> V_81 . V_212 ) ? L_50 : L_48 ,
V_209 -> V_218 ) ;
F_149 ( & V_16 -> V_81 ) ;
if ( V_198 -> V_82 . V_199 ) {
V_141 = F_150 ( V_198 -> V_82 . V_199 ,
F_116 , V_16 ) ;
if ( V_141 ) {
F_20 ( & V_198 -> V_82 , L_51 ) ;
goto V_257;
}
}
return 0 ;
V_257:
F_151 ( & V_16 -> V_81 ) ;
F_152 ( V_16 -> V_19 ) ;
V_230:
F_153 ( F_132 ( V_198 , 0 ) , V_16 ) ;
V_229:
F_154 ( V_16 -> V_226 ) ;
V_228:
F_155 ( V_16 -> V_226 ) ;
V_227:
F_156 ( V_16 -> V_224 ) ;
V_16 -> V_224 = NULL ;
V_225:
F_157 ( V_208 -> V_220 , V_101 ) ;
V_223:
F_158 ( V_16 ) ;
return V_141 ;
}
static int F_159 ( struct V_182 * V_198 )
{
struct V_15 * V_16 = F_160 ( V_198 ) ;
struct V_11 * V_12 , * V_258 ;
struct V_207 * V_208 ;
F_129 ( V_16 ) ;
F_151 ( & V_16 -> V_81 ) ;
F_152 ( V_16 -> V_19 ) ;
F_153 ( F_132 ( V_198 , 0 ) , V_16 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_161 ( V_16 , V_12 -> V_161 ) ;
F_162 ( & V_7 -> V_85 ) ;
F_15 ( & V_12 -> V_234 ) ;
}
F_154 ( V_16 -> V_226 ) ;
F_155 ( V_16 -> V_226 ) ;
F_156 ( V_16 -> V_224 ) ;
V_16 -> V_224 = NULL ;
V_208 = F_131 ( V_198 , V_217 , 0 ) ;
F_157 ( V_208 -> V_220 , F_134 ( V_208 ) ) ;
F_158 ( V_16 ) ;
return 0 ;
}
static void F_163 ( struct V_182 * V_198 )
{
struct V_15 * V_16 = F_160 ( V_198 ) ;
F_129 ( F_160 ( V_198 ) ) ;
F_154 ( V_16 -> V_226 ) ;
}
static int F_164 ( struct V_17 * V_82 )
{
struct V_182 * V_198 = F_165 ( V_82 ) ;
struct V_15 * V_16 = F_160 ( V_198 ) ;
struct V_11 * V_12 , * V_258 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
if ( F_28 ( V_7 ) && ! F_46 ( V_7 ) )
return - V_259 ;
}
return 0 ;
}
static void F_166 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = & V_7 -> V_31 ;
if ( ! F_102 ( V_7 ) ) {
F_167 ( F_17 ( V_12 ) ,
L_52 ) ;
F_99 ( V_12 ) ;
}
V_7 -> V_260 = F_29 ( V_7 , V_44 ) ;
F_30 ( V_7 ) ;
}
static int F_168 ( struct V_17 * V_82 )
{
struct V_182 * V_198 = F_165 ( V_82 ) ;
struct V_15 * V_16 = F_160 ( V_198 ) ;
struct V_11 * V_12 , * V_258 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
if ( F_46 ( V_7 ) )
F_166 ( V_7 ) ;
V_7 -> V_261 = F_29 ( V_7 , V_176 ) ;
}
V_16 -> V_262 = F_63 ( V_16 , V_79 ) ;
F_129 ( V_16 ) ;
F_154 ( V_16 -> V_226 ) ;
return 0 ;
}
static void F_169 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = F_6 ( V_7 -> V_31 . V_17 ) ;
F_31 ( V_7 , V_40 , 0 ) ;
F_31 ( V_7 , V_41 , 0 ) ;
F_31 ( V_7 , V_42 , 0 ) ;
F_31 ( V_7 , V_43 , 0 ) ;
F_31 ( V_7 , V_44 , V_7 -> V_260 ) ;
F_36 ( V_16 , V_50 , V_7 -> V_51 ) ;
F_30 ( V_7 ) ;
}
static int F_170 ( struct V_17 * V_82 )
{
struct V_182 * V_198 = F_165 ( V_82 ) ;
struct V_15 * V_16 = F_160 ( V_198 ) ;
struct V_11 * V_12 , * V_258 ;
F_140 ( V_16 -> V_226 ) ;
F_36 ( V_16 , V_204 , V_256 ) ;
while ( F_63 ( V_16 , V_80 ) )
F_104 () ;
F_36 ( V_16 , V_263 , V_16 -> V_262 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_31 ( V_7 , V_176 , V_7 -> V_261 ) ;
if ( F_46 ( V_7 ) )
F_169 ( V_7 ) ;
}
return 0 ;
}
static int T_9 F_171 ( void )
{
return F_172 ( & V_264 , F_130 ) ;
}
static void T_10 F_173 ( void )
{
F_174 ( & V_264 ) ;
}
