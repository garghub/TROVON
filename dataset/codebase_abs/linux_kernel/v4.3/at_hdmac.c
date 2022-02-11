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
struct V_15 * V_16 = F_6 ( V_7 -> V_31 . V_17 ) ;
F_19 ( F_17 ( & V_7 -> V_31 ) ,
L_8 , V_21 -> V_52 ) ;
if ( ! F_46 ( V_7 ) )
F_47 ( V_21 ) ;
if ( V_14 -> memset ) {
F_48 ( V_16 -> V_66 , V_14 -> V_67 ,
V_14 -> V_68 ) ;
V_14 -> memset = false ;
}
F_23 ( & V_14 -> V_20 , & V_7 -> V_35 ) ;
F_49 ( & V_14 -> V_9 , & V_7 -> V_35 ) ;
F_50 ( V_21 ) ;
if ( ! F_46 ( V_7 ) ) {
T_6 V_69 = V_21 -> V_69 ;
void * V_70 = V_21 -> V_71 ;
if ( V_69 )
V_69 ( V_70 ) ;
}
F_51 ( V_21 ) ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_5 * V_14 , * V_26 ;
F_11 ( V_72 ) ;
F_19 ( F_17 ( & V_7 -> V_31 ) , L_9 ) ;
if ( ! F_53 ( & V_7 -> V_10 ) )
F_27 ( V_7 , F_4 ( V_7 ) ) ;
F_23 ( & V_7 -> V_8 , & V_72 ) ;
F_23 ( & V_7 -> V_10 , & V_7 -> V_8 ) ;
F_13 (desc, _desc, &list, desc_node)
F_45 ( V_7 , V_14 ) ;
}
static void F_54 ( struct V_6 * V_7 )
{
F_19 ( F_17 ( & V_7 -> V_31 ) , L_10 ) ;
if ( F_28 ( V_7 ) )
return;
if ( F_53 ( & V_7 -> V_8 ) ||
F_55 ( & V_7 -> V_8 ) ) {
F_52 ( V_7 ) ;
} else {
F_45 ( V_7 , F_2 ( V_7 ) ) ;
F_27 ( V_7 , F_2 ( V_7 ) ) ;
}
}
static void F_56 ( struct V_6 * V_7 )
{
struct V_5 * V_73 ;
struct V_5 * V_34 ;
V_73 = F_2 ( V_7 ) ;
F_57 ( & V_73 -> V_9 ) ;
F_23 ( & V_7 -> V_10 , V_7 -> V_8 . V_37 ) ;
if ( ! F_53 ( & V_7 -> V_8 ) )
F_27 ( V_7 , F_2 ( V_7 ) ) ;
F_58 ( F_17 ( & V_7 -> V_31 ) ,
L_11 ) ;
F_58 ( F_17 ( & V_7 -> V_31 ) ,
L_12 , V_73 -> V_21 . V_52 ) ;
F_59 ( V_7 , & V_73 -> V_38 ) ;
F_22 (child, &bad_desc->tx_list, desc_node)
F_59 ( V_7 , & V_34 -> V_38 ) ;
F_45 ( V_7 , V_73 ) ;
}
static void F_60 ( struct V_6 * V_7 )
{
struct V_5 * V_36 = F_2 ( V_7 ) ;
struct V_65 * V_21 = & V_36 -> V_21 ;
T_6 V_69 = V_21 -> V_69 ;
void * V_70 = V_21 -> V_71 ;
F_19 ( F_17 ( & V_7 -> V_31 ) ,
L_13 ,
F_29 ( V_7 , V_44 ) ) ;
if ( V_69 )
V_69 ( V_70 ) ;
}
static void F_61 ( unsigned long V_74 )
{
struct V_6 * V_7 = (struct V_6 * ) V_74 ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
if ( F_62 ( V_75 , & V_7 -> V_76 ) )
F_56 ( V_7 ) ;
else if ( F_46 ( V_7 ) )
F_60 ( V_7 ) ;
else
F_54 ( V_7 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
}
static T_7 F_63 ( int V_77 , void * V_78 )
{
struct V_15 * V_16 = (struct V_15 * ) V_78 ;
struct V_6 * V_7 ;
int V_28 ;
T_5 V_76 , V_79 , V_80 ;
int V_27 = V_81 ;
do {
V_80 = F_64 ( V_16 , V_82 ) ;
V_76 = F_64 ( V_16 , V_83 ) ;
V_79 = V_76 & V_80 ;
if ( ! V_79 )
break;
F_19 ( V_16 -> V_84 . V_85 ,
L_14 ,
V_76 , V_80 , V_79 ) ;
for ( V_28 = 0 ; V_28 < V_16 -> V_84 . V_86 ; V_28 ++ ) {
V_7 = & V_16 -> V_12 [ V_28 ] ;
if ( V_79 & ( F_65 ( V_28 ) | F_66 ( V_28 ) ) ) {
if ( V_79 & F_66 ( V_28 ) ) {
F_36 ( V_16 , V_87 ,
F_67 ( V_28 ) | V_7 -> V_51 ) ;
F_68 ( V_75 , & V_7 -> V_76 ) ;
}
F_69 ( & V_7 -> V_88 ) ;
V_27 = V_89 ;
}
}
} while ( V_79 );
return V_27 ;
}
static T_4 V_25 ( struct V_65 * V_90 )
{
struct V_5 * V_14 = F_70 ( V_90 ) ;
struct V_6 * V_7 = F_41 ( V_90 -> V_12 ) ;
T_4 V_52 ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_52 = F_71 ( V_90 ) ;
if ( F_53 ( & V_7 -> V_8 ) ) {
F_19 ( F_17 ( V_90 -> V_12 ) , L_15 ,
V_14 -> V_21 . V_52 ) ;
F_27 ( V_7 , V_14 ) ;
F_26 ( & V_14 -> V_9 , & V_7 -> V_8 ) ;
} else {
F_19 ( F_17 ( V_90 -> V_12 ) , L_16 ,
V_14 -> V_21 . V_52 ) ;
F_26 ( & V_14 -> V_9 , & V_7 -> V_10 ) ;
}
F_18 ( & V_7 -> V_30 , V_22 ) ;
return V_52 ;
}
static struct V_65 *
F_72 ( struct V_11 * V_12 ,
struct V_91 * V_92 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_93 * V_36 = V_92 -> V_94 ;
struct V_5 * V_14 = NULL ;
T_2 V_95 ;
unsigned int V_96 ;
T_5 V_54 ;
T_5 V_97 ;
T_2 V_3 = 0 ;
int V_28 ;
if ( F_44 ( ! V_92 || V_92 -> V_98 != 1 || ! V_92 -> V_99 ) )
return NULL ;
F_73 ( F_17 ( V_12 ) ,
L_17 ,
V_100 , V_92 -> V_101 , V_92 -> V_102 , V_92 -> V_98 ,
V_92 -> V_99 , V_22 ) ;
for ( V_28 = 0 ; V_28 < V_92 -> V_99 ; V_28 ++ ) {
struct V_93 * V_103 = V_92 -> V_94 + V_28 ;
if ( ( V_103 -> V_104 != V_92 -> V_94 -> V_104 ) ||
( F_74 ( V_92 , V_103 ) != F_74 ( V_92 , V_36 ) ) ||
( F_75 ( V_92 , V_103 ) != F_75 ( V_92 , V_36 ) ) ) {
F_20 ( F_17 ( V_12 ) ,
L_18 ,
V_100 ) ;
return NULL ;
}
V_3 += V_103 -> V_104 ;
}
V_96 = F_1 ( V_92 -> V_101 ,
V_92 -> V_102 , V_3 ) ;
V_95 = V_3 >> V_96 ;
if ( V_95 > V_56 ) {
F_20 ( F_17 ( V_12 ) , L_19 , V_100 ) ;
return NULL ;
}
V_54 = F_76 ( V_96 ) |
F_77 ( V_96 ) ;
V_97 = V_105 | V_106
| V_107
| V_108
| V_109
| V_110
| V_111 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 ) {
F_20 ( F_17 ( V_12 ) ,
L_20 , V_100 ) ;
return NULL ;
}
V_14 -> V_38 . V_112 = V_92 -> V_101 ;
V_14 -> V_38 . V_113 = V_92 -> V_102 ;
V_14 -> V_38 . V_54 = V_54 | V_95 ;
V_14 -> V_38 . V_97 = V_97 ;
V_14 -> V_47 = V_36 -> V_104 >> V_96 ;
V_14 -> V_49 = ( F_74 ( V_92 , V_36 ) >> V_96 ) + 1 ;
V_14 -> V_46 = ( F_75 ( V_92 , V_36 ) >> V_96 ) + 1 ;
V_14 -> V_21 . V_52 = - V_114 ;
V_14 -> V_61 = V_14 -> V_3 = V_3 ;
F_78 ( V_14 ) ;
V_14 -> V_21 . V_22 = V_22 ;
return & V_14 -> V_21 ;
}
static struct V_65 *
F_79 ( struct V_11 * V_12 , T_1 V_115 , T_1 V_1 ,
T_2 V_3 , unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_5 * V_14 = NULL ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
T_2 V_95 ;
T_2 V_116 ;
unsigned int V_57 ;
unsigned int V_117 ;
T_5 V_54 ;
T_5 V_97 ;
F_19 ( F_17 ( V_12 ) , L_21 ,
V_115 , V_1 , V_3 , V_22 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) , L_22 ) ;
return NULL ;
}
V_97 = V_105 | V_106
| V_107
| V_108
| V_111 ;
V_57 = V_117 = F_1 ( V_1 , V_115 , V_3 ) ;
V_54 = F_76 ( V_57 ) |
F_77 ( V_117 ) ;
for ( V_116 = 0 ; V_116 < V_3 ; V_116 += V_95 << V_57 ) {
V_95 = F_80 ( T_2 , ( V_3 - V_116 ) >> V_57 ,
V_56 ) ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_118;
V_14 -> V_38 . V_112 = V_1 + V_116 ;
V_14 -> V_38 . V_113 = V_115 + V_116 ;
V_14 -> V_38 . V_54 = V_54 | V_95 ;
V_14 -> V_38 . V_97 = V_97 ;
V_14 -> V_21 . V_52 = 0 ;
V_14 -> V_3 = V_95 << V_57 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
}
V_36 -> V_21 . V_52 = - V_114 ;
V_36 -> V_61 = V_3 ;
F_78 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_118:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_65 *
F_81 ( struct V_11 * V_12 , T_1 V_115 , int V_119 ,
T_2 V_3 , unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 = NULL ;
T_2 V_95 ;
T_5 V_54 ;
T_5 V_97 ;
F_19 ( F_17 ( V_12 ) , L_23 , V_100 ,
V_115 , V_119 , V_3 , V_22 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) , L_24 , V_100 ) ;
return NULL ;
}
if ( ! F_82 ( V_12 -> V_17 , V_115 , 0 , V_3 ) ) {
F_16 ( F_17 ( V_12 ) , L_25 ,
V_100 ) ;
return NULL ;
}
V_95 = V_3 >> 2 ;
if ( V_95 > V_56 ) {
F_20 ( F_17 ( V_12 ) , L_19 ,
V_100 ) ;
return NULL ;
}
V_97 = V_105 | V_106
| V_120
| V_108
| V_111 ;
V_54 = F_76 ( 2 ) |
F_77 ( 2 ) ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 ) {
F_20 ( F_17 ( V_12 ) , L_26 ,
V_100 ) ;
return NULL ;
}
V_14 -> V_67 = F_7 ( V_16 -> V_66 , V_32 ,
& V_14 -> V_68 ) ;
if ( ! V_14 -> V_67 ) {
F_20 ( F_17 ( V_12 ) , L_27 ,
V_100 ) ;
goto V_121;
}
* V_14 -> V_67 = V_119 ;
V_14 -> memset = true ;
V_14 -> V_38 . V_112 = V_14 -> V_68 ;
V_14 -> V_38 . V_113 = V_115 ;
V_14 -> V_38 . V_54 = V_54 | V_95 ;
V_14 -> V_38 . V_97 = V_97 ;
V_14 -> V_21 . V_52 = - V_114 ;
V_14 -> V_3 = V_3 ;
V_14 -> V_61 = V_3 ;
F_78 ( V_14 ) ;
V_14 -> V_21 . V_22 = V_22 ;
return & V_14 -> V_21 ;
V_121:
F_21 ( V_7 , V_14 ) ;
return NULL ;
}
static struct V_65 *
F_83 ( struct V_11 * V_12 , struct V_122 * V_94 ,
unsigned int V_123 , enum V_124 V_125 ,
unsigned long V_22 , void * V_126 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_127 * V_128 = V_12 -> V_129 ;
struct V_130 * V_131 = & V_7 -> V_132 ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
T_5 V_54 ;
T_5 V_97 ;
T_1 V_133 ;
unsigned int V_134 ;
unsigned int V_135 ;
unsigned int V_28 ;
struct V_122 * V_136 ;
T_2 V_61 = 0 ;
F_19 ( F_17 ( V_12 ) , L_28 ,
V_123 ,
V_125 == V_137 ? L_29 : L_30 ,
V_22 ) ;
if ( F_44 ( ! V_128 || ! V_123 ) ) {
F_16 ( F_17 ( V_12 ) , L_31 ) ;
return NULL ;
}
V_54 = F_84 ( V_131 -> V_138 )
| F_85 ( V_131 -> V_139 ) ;
V_97 = V_106 ;
switch ( V_125 ) {
case V_137 :
V_134 = F_86 ( V_131 -> V_140 ) ;
V_54 |= F_77 ( V_134 ) ;
V_97 |= V_141
| V_107
| V_142
| F_87 ( V_7 -> V_143 ) | F_88 ( V_7 -> V_144 ) ;
V_133 = V_131 -> V_145 ;
F_89 (sgl, sg, sg_len, i) {
struct V_5 * V_14 ;
T_5 V_3 ;
T_5 V_146 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_118;
V_146 = F_90 ( V_136 ) ;
V_3 = F_91 ( V_136 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) ,
L_32 , V_28 ) ;
goto V_147;
}
V_135 = 2 ;
if ( F_44 ( V_146 & 3 || V_3 & 3 ) )
V_135 = 0 ;
V_14 -> V_38 . V_112 = V_146 ;
V_14 -> V_38 . V_113 = V_133 ;
V_14 -> V_38 . V_54 = V_54
| F_76 ( V_135 )
| V_3 >> V_135 ;
V_14 -> V_38 . V_97 = V_97 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_61 += V_3 ;
}
break;
case V_148 :
V_134 = F_86 ( V_131 -> V_149 ) ;
V_54 |= F_76 ( V_134 ) ;
V_97 |= V_108
| V_120
| V_150
| F_87 ( V_7 -> V_144 ) | F_88 ( V_7 -> V_143 ) ;
V_133 = V_131 -> V_151 ;
F_89 (sgl, sg, sg_len, i) {
struct V_5 * V_14 ;
T_5 V_3 ;
T_5 V_146 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_118;
V_146 = F_90 ( V_136 ) ;
V_3 = F_91 ( V_136 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) ,
L_32 , V_28 ) ;
goto V_147;
}
V_135 = 2 ;
if ( F_44 ( V_146 & 3 || V_3 & 3 ) )
V_135 = 0 ;
V_14 -> V_38 . V_112 = V_133 ;
V_14 -> V_38 . V_113 = V_146 ;
V_14 -> V_38 . V_54 = V_54
| F_77 ( V_135 )
| V_3 >> V_134 ;
V_14 -> V_38 . V_97 = V_97 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_61 += V_3 ;
}
break;
default:
return NULL ;
}
F_78 ( V_37 ) ;
V_36 -> V_21 . V_52 = - V_114 ;
V_36 -> V_61 = V_61 ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_118:
F_20 ( F_17 ( V_12 ) , L_3 ) ;
V_147:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_65 *
F_92 ( struct V_11 * V_12 ,
struct V_122 * V_152 , unsigned int V_153 ,
struct V_122 * V_154 , unsigned int V_155 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_5 * V_14 = NULL ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
unsigned int V_57 ;
unsigned int V_117 ;
T_2 V_95 ;
T_5 V_54 ;
T_5 V_97 ;
T_2 V_156 = 0 , V_157 = 0 ;
T_1 V_2 = 0 , V_1 = 0 ;
T_2 V_3 = 0 , V_61 = 0 ;
if ( F_44 ( V_153 == 0 || V_155 == 0 ) )
return NULL ;
if ( F_44 ( V_152 == NULL || V_154 == NULL ) )
return NULL ;
V_97 = V_105 | V_106
| V_107
| V_108
| V_111 ;
while ( true ) {
if ( V_156 == 0 ) {
if ( ! V_152 || ! V_153 )
break;
V_2 = F_90 ( V_152 ) ;
V_156 = F_91 ( V_152 ) ;
V_152 = F_93 ( V_152 ) ;
V_153 -- ;
}
if ( V_157 == 0 ) {
if ( ! V_154 || ! V_155 )
break;
V_1 = F_90 ( V_154 ) ;
V_157 = F_91 ( V_154 ) ;
V_154 = F_93 ( V_154 ) ;
V_155 -- ;
}
V_3 = F_80 ( T_2 , V_157 , V_156 ) ;
if ( V_3 == 0 )
continue;
V_57 = V_117 = F_1 ( V_1 , V_2 , V_3 ) ;
V_54 = F_76 ( V_57 ) |
F_77 ( V_117 ) ;
V_95 = V_3 >> V_57 ;
if ( V_95 > V_56 ) {
V_95 = V_56 ;
V_3 = V_56 << V_57 ;
}
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_118;
V_14 -> V_38 . V_112 = V_1 ;
V_14 -> V_38 . V_113 = V_2 ;
V_14 -> V_38 . V_54 = V_54 | V_95 ;
V_14 -> V_38 . V_97 = V_97 ;
V_14 -> V_21 . V_52 = 0 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_156 -= V_3 ;
V_157 -= V_3 ;
V_2 += V_3 ;
V_1 += V_3 ;
V_61 += V_3 ;
}
V_36 -> V_21 . V_52 = - V_114 ;
V_36 -> V_61 = V_61 ;
F_78 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_118:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static int
F_94 ( unsigned int V_134 , T_1 V_158 ,
T_2 V_159 )
{
if ( V_159 > ( V_56 << V_134 ) )
goto V_160;
if ( F_44 ( V_159 & ( ( 1 << V_134 ) - 1 ) ) )
goto V_160;
if ( F_44 ( V_158 & ( ( 1 << V_134 ) - 1 ) ) )
goto V_160;
return 0 ;
V_160:
return - V_60 ;
}
static int
F_95 ( struct V_11 * V_12 , struct V_5 * V_14 ,
unsigned int V_161 , T_1 V_158 ,
unsigned int V_134 , T_2 V_159 ,
enum V_124 V_125 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_130 * V_131 = & V_7 -> V_132 ;
T_5 V_54 ;
V_54 = F_84 ( V_131 -> V_138 )
| F_85 ( V_131 -> V_139 )
| F_77 ( V_134 )
| F_76 ( V_134 )
| V_159 >> V_134 ;
switch ( V_125 ) {
case V_137 :
V_14 -> V_38 . V_112 = V_158 + ( V_159 * V_161 ) ;
V_14 -> V_38 . V_113 = V_131 -> V_145 ;
V_14 -> V_38 . V_54 = V_54 ;
V_14 -> V_38 . V_97 = V_141
| V_107
| V_142
| F_87 ( V_7 -> V_143 )
| F_88 ( V_7 -> V_144 ) ;
V_14 -> V_3 = V_159 ;
break;
case V_148 :
V_14 -> V_38 . V_112 = V_131 -> V_151 ;
V_14 -> V_38 . V_113 = V_158 + ( V_159 * V_161 ) ;
V_14 -> V_38 . V_54 = V_54 ;
V_14 -> V_38 . V_97 = V_108
| V_120
| V_150
| F_87 ( V_7 -> V_144 )
| F_88 ( V_7 -> V_143 ) ;
V_14 -> V_3 = V_159 ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static struct V_65 *
F_96 ( struct V_11 * V_12 , T_1 V_158 , T_2 V_162 ,
T_2 V_159 , enum V_124 V_125 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_127 * V_128 = V_12 -> V_129 ;
struct V_130 * V_131 = & V_7 -> V_132 ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
unsigned long V_163 ;
unsigned int V_134 ;
unsigned int V_164 = V_162 / V_159 ;
unsigned int V_28 ;
F_19 ( F_17 ( V_12 ) , L_33 ,
V_125 == V_137 ? L_29 : L_30 ,
V_158 ,
V_164 , V_162 , V_159 ) ;
if ( F_44 ( ! V_128 || ! V_162 || ! V_159 ) ) {
F_16 ( F_17 ( V_12 ) , L_34 ) ;
return NULL ;
}
V_163 = F_97 ( V_165 , & V_7 -> V_76 ) ;
if ( V_163 ) {
F_16 ( F_17 ( V_12 ) , L_35 ) ;
return NULL ;
}
if ( F_44 ( ! F_98 ( V_125 ) ) )
goto V_160;
if ( V_131 -> V_125 == V_137 )
V_134 = F_86 ( V_131 -> V_140 ) ;
else
V_134 = F_86 ( V_131 -> V_149 ) ;
if ( F_94 ( V_134 , V_158 , V_159 ) )
goto V_160;
for ( V_28 = 0 ; V_28 < V_164 ; V_28 ++ ) {
struct V_5 * V_14 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_118;
if ( F_95 ( V_12 , V_14 , V_28 , V_158 ,
V_134 , V_159 , V_125 ) )
goto V_118;
F_25 ( & V_36 , & V_37 , V_14 ) ;
}
V_37 -> V_38 . V_39 = V_36 -> V_21 . V_18 ;
V_36 -> V_21 . V_52 = - V_114 ;
V_36 -> V_61 = V_162 ;
return & V_36 -> V_21 ;
V_118:
F_20 ( F_17 ( V_12 ) , L_3 ) ;
F_21 ( V_7 , V_36 ) ;
V_160:
F_99 ( V_165 , & V_7 -> V_76 ) ;
return NULL ;
}
static int F_100 ( struct V_11 * V_12 ,
struct V_130 * V_131 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_19 ( F_17 ( V_12 ) , L_36 , V_100 ) ;
if ( ! V_12 -> V_129 )
return - V_60 ;
memcpy ( & V_7 -> V_132 , V_131 , sizeof( * V_131 ) ) ;
F_101 ( & V_7 -> V_132 . V_138 ) ;
F_101 ( & V_7 -> V_132 . V_139 ) ;
return 0 ;
}
static int F_102 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_166 = V_7 -> V_31 . V_166 ;
unsigned long V_22 ;
F_11 ( V_72 ) ;
F_19 ( F_17 ( V_12 ) , L_36 , V_100 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_50 , F_103 ( V_166 ) ) ;
F_68 ( V_167 , & V_7 -> V_76 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_104 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_166 = V_7 -> V_31 . V_166 ;
unsigned long V_22 ;
F_11 ( V_72 ) ;
F_19 ( F_17 ( V_12 ) , L_36 , V_100 ) ;
if ( ! F_105 ( V_7 ) )
return 0 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_87 , F_67 ( V_166 ) ) ;
F_99 ( V_167 , & V_7 -> V_76 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_106 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_166 = V_7 -> V_31 . V_166 ;
struct V_5 * V_14 , * V_26 ;
unsigned long V_22 ;
F_11 ( V_72 ) ;
F_19 ( F_17 ( V_12 ) , L_36 , V_100 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_87 , F_67 ( V_166 ) | V_7 -> V_51 ) ;
while ( F_64 ( V_16 , V_168 ) & V_7 -> V_51 )
F_107 () ;
F_23 ( & V_7 -> V_10 , & V_72 ) ;
F_23 ( & V_7 -> V_8 , & V_72 ) ;
F_13 (desc, _desc, &list, desc_node)
F_45 ( V_7 , V_14 ) ;
F_99 ( V_167 , & V_7 -> V_76 ) ;
F_99 ( V_165 , & V_7 -> V_76 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static enum V_169
F_108 ( struct V_11 * V_12 ,
T_4 V_52 ,
struct V_170 * V_171 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
unsigned long V_22 ;
enum V_169 V_27 ;
int V_172 = 0 ;
V_27 = F_109 ( V_12 , V_52 , V_171 ) ;
if ( V_27 == V_173 )
return V_27 ;
if ( ! V_171 )
return V_174 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_172 = F_40 ( V_12 , V_52 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
if ( F_44 ( V_172 < 0 ) ) {
F_19 ( F_17 ( V_12 ) , L_37 ) ;
return V_174 ;
} else {
F_110 ( V_171 , V_172 ) ;
}
F_19 ( F_17 ( V_12 ) , L_38 ,
V_27 , V_52 , V_172 ) ;
return V_27 ;
}
static void F_111 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
unsigned long V_22 ;
F_19 ( F_17 ( V_12 ) , L_39 ) ;
if ( F_46 ( V_7 ) )
return;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_54 ( V_7 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
}
static int F_112 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 ;
struct V_127 * V_128 ;
unsigned long V_22 ;
int V_28 ;
T_5 V_175 ;
F_11 ( V_29 ) ;
F_19 ( F_17 ( V_12 ) , L_40 ) ;
if ( F_28 ( V_7 ) ) {
F_16 ( F_17 ( V_12 ) , L_41 ) ;
return - V_176 ;
}
V_175 = V_177 ;
V_128 = V_12 -> V_129 ;
if ( V_128 ) {
F_113 ( ! V_128 -> V_178 || V_128 -> V_178 != V_16 -> V_84 . V_85 ) ;
if ( V_128 -> V_175 )
V_175 = V_128 -> V_175 ;
}
if ( ! F_53 ( & V_7 -> V_35 ) )
return V_7 -> V_33 ;
for ( V_28 = 0 ; V_28 < V_179 ; V_28 ++ ) {
V_14 = F_5 ( V_12 , V_180 ) ;
if ( ! V_14 ) {
F_20 ( V_16 -> V_84 . V_85 ,
L_42 , V_28 ) ;
break;
}
F_26 ( & V_14 -> V_9 , & V_29 ) ;
}
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_7 -> V_33 = V_28 ;
F_114 ( & V_29 , & V_7 -> V_35 ) ;
F_115 ( V_12 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
F_31 ( V_7 , V_181 , V_175 ) ;
F_16 ( F_17 ( V_12 ) ,
L_43 ,
V_7 -> V_33 ) ;
return V_7 -> V_33 ;
}
static void F_116 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 , * V_26 ;
F_11 ( V_72 ) ;
F_16 ( F_17 ( V_12 ) , L_44 ,
V_7 -> V_33 ) ;
F_113 ( ! F_53 ( & V_7 -> V_8 ) ) ;
F_113 ( ! F_53 ( & V_7 -> V_10 ) ) ;
F_113 ( F_28 ( V_7 ) ) ;
F_13 (desc, _desc, &atchan->free_list, desc_node) {
F_19 ( F_17 ( V_12 ) , L_45 , V_14 ) ;
F_15 ( & V_14 -> V_9 ) ;
F_48 ( V_16 -> V_19 , V_14 , V_14 -> V_21 . V_18 ) ;
}
F_23 ( & V_7 -> V_35 , & V_72 ) ;
V_7 -> V_33 = 0 ;
V_7 -> V_76 = 0 ;
F_19 ( F_17 ( V_12 ) , L_46 ) ;
}
static bool F_117 ( struct V_11 * V_12 , void * V_182 )
{
struct V_127 * V_128 = V_182 ;
if ( V_128 -> V_178 == V_12 -> V_17 -> V_85 ) {
V_12 -> V_129 = V_128 ;
return true ;
} else {
return false ;
}
}
static struct V_11 * F_118 ( struct V_183 * V_184 ,
struct V_185 * V_185 )
{
struct V_11 * V_12 ;
struct V_6 * V_7 ;
struct V_127 * V_128 ;
T_8 V_51 ;
unsigned int V_186 ;
struct V_187 * V_188 ;
if ( V_184 -> V_189 != 2 )
return NULL ;
V_188 = F_119 ( V_184 -> V_190 ) ;
F_120 ( V_51 ) ;
F_121 ( V_191 , V_51 ) ;
V_128 = F_122 ( & V_188 -> V_85 , sizeof( * V_128 ) , V_180 ) ;
if ( ! V_128 )
return NULL ;
V_128 -> V_175 = V_192 | V_193 ;
V_186 = V_184 -> args [ 1 ] & V_194 ;
V_128 -> V_175 |= F_123 ( V_186 ) | F_124 ( V_186 )
| F_125 ( V_186 ) | F_126 ( V_186 ) ;
switch ( V_184 -> args [ 1 ] & V_195 ) {
case V_196 :
V_128 -> V_175 |= V_197 ;
break;
case V_198 :
V_128 -> V_175 |= V_199 ;
break;
case V_200 :
default:
V_128 -> V_175 |= V_201 ;
}
V_128 -> V_178 = & V_188 -> V_85 ;
V_12 = F_127 ( V_51 , F_117 , V_128 ) ;
if ( ! V_12 )
return NULL ;
V_7 = F_41 ( V_12 ) ;
V_7 -> V_144 = V_184 -> args [ 0 ] & 0xff ;
V_7 -> V_143 = ( V_184 -> args [ 0 ] >> 16 ) & 0xff ;
return V_12 ;
}
static struct V_11 * F_118 ( struct V_183 * V_184 ,
struct V_185 * V_185 )
{
return NULL ;
}
static inline const struct V_202 * T_9 F_128 (
struct V_187 * V_203 )
{
if ( V_203 -> V_85 . V_204 ) {
const struct V_205 * V_206 ;
V_206 = F_129 ( V_207 , V_203 -> V_85 . V_204 ) ;
if ( V_206 == NULL )
return NULL ;
return V_206 -> V_74 ;
}
return (struct V_202 * )
F_130 ( V_203 ) -> V_208 ;
}
static void F_131 ( struct V_15 * V_16 )
{
F_36 ( V_16 , V_209 , 0 ) ;
F_36 ( V_16 , V_210 , - 1L ) ;
while ( F_64 ( V_16 , V_168 ) & V_16 -> V_211 )
F_107 () ;
}
static int T_9 F_132 ( struct V_187 * V_203 )
{
struct V_212 * V_213 ;
struct V_15 * V_16 ;
T_2 V_104 ;
int V_77 ;
int V_147 ;
int V_28 ;
const struct V_202 * V_214 ;
F_121 ( V_215 , V_216 . V_217 ) ;
F_121 ( V_218 , V_216 . V_217 ) ;
F_121 ( V_219 , V_220 . V_217 ) ;
F_121 ( V_215 , V_220 . V_217 ) ;
F_121 ( V_221 , V_220 . V_217 ) ;
F_121 ( V_222 , V_220 . V_217 ) ;
F_121 ( V_191 , V_220 . V_217 ) ;
F_121 ( V_218 , V_220 . V_217 ) ;
V_214 = F_128 ( V_203 ) ;
if ( ! V_214 )
return - V_223 ;
V_213 = F_133 ( V_203 , V_224 , 0 ) ;
if ( ! V_213 )
return - V_60 ;
V_77 = F_134 ( V_203 , 0 ) ;
if ( V_77 < 0 )
return V_77 ;
V_104 = sizeof( struct V_15 ) ;
V_104 += V_214 -> V_225 * sizeof( struct V_6 ) ;
V_16 = F_135 ( V_104 , V_180 ) ;
if ( ! V_16 )
return - V_226 ;
V_16 -> V_84 . V_217 = V_214 -> V_217 ;
V_16 -> V_211 = ( 1 << V_214 -> V_225 ) - 1 ;
V_104 = F_136 ( V_213 ) ;
if ( ! F_137 ( V_213 -> V_227 , V_104 , V_203 -> V_85 . V_228 -> V_229 ) ) {
V_147 = - V_114 ;
goto V_230;
}
V_16 -> V_231 = F_138 ( V_213 -> V_227 , V_104 ) ;
if ( ! V_16 -> V_231 ) {
V_147 = - V_226 ;
goto V_232;
}
V_16 -> V_233 = F_139 ( & V_203 -> V_85 , L_47 ) ;
if ( F_140 ( V_16 -> V_233 ) ) {
V_147 = F_141 ( V_16 -> V_233 ) ;
goto V_234;
}
V_147 = F_142 ( V_16 -> V_233 ) ;
if ( V_147 )
goto V_235;
F_131 ( V_16 ) ;
V_147 = F_143 ( V_77 , F_63 , 0 , L_48 , V_16 ) ;
if ( V_147 )
goto V_236;
F_144 ( V_203 , V_16 ) ;
V_16 -> V_19 = F_145 ( L_49 ,
& V_203 -> V_85 , sizeof( struct V_5 ) ,
4 , 0 ) ;
if ( ! V_16 -> V_19 ) {
F_20 ( & V_203 -> V_85 , L_50 ) ;
V_147 = - V_226 ;
goto V_237;
}
V_16 -> V_66 = F_145 ( L_51 ,
& V_203 -> V_85 , sizeof( int ) , 4 , 0 ) ;
if ( ! V_16 -> V_66 ) {
F_20 ( & V_203 -> V_85 , L_52 ) ;
V_147 = - V_226 ;
goto V_238;
}
while ( F_64 ( V_16 , V_83 ) )
F_107 () ;
F_8 ( & V_16 -> V_84 . V_239 ) ;
for ( V_28 = 0 ; V_28 < V_214 -> V_225 ; V_28 ++ ) {
struct V_6 * V_7 = & V_16 -> V_12 [ V_28 ] ;
V_7 -> V_143 = V_240 ;
V_7 -> V_144 = V_241 ;
V_7 -> V_31 . V_17 = & V_16 -> V_84 ;
F_115 ( & V_7 -> V_31 ) ;
F_26 ( & V_7 -> V_31 . V_242 ,
& V_16 -> V_84 . V_239 ) ;
V_7 -> V_243 = V_16 -> V_231 + V_243 ( V_28 ) ;
F_146 ( & V_7 -> V_30 ) ;
V_7 -> V_51 = 1 << V_28 ;
F_8 ( & V_7 -> V_8 ) ;
F_8 ( & V_7 -> V_10 ) ;
F_8 ( & V_7 -> V_35 ) ;
F_147 ( & V_7 -> V_88 , F_61 ,
( unsigned long ) V_7 ) ;
F_148 ( V_16 , V_28 ) ;
}
V_16 -> V_84 . V_244 = F_112 ;
V_16 -> V_84 . V_245 = F_116 ;
V_16 -> V_84 . V_246 = F_108 ;
V_16 -> V_84 . V_247 = F_111 ;
V_16 -> V_84 . V_85 = & V_203 -> V_85 ;
if ( F_149 ( V_219 , V_16 -> V_84 . V_217 ) )
V_16 -> V_84 . V_248 = F_72 ;
if ( F_149 ( V_215 , V_16 -> V_84 . V_217 ) )
V_16 -> V_84 . V_249 = F_79 ;
if ( F_149 ( V_221 , V_16 -> V_84 . V_217 ) ) {
V_16 -> V_84 . V_250 = F_81 ;
V_16 -> V_84 . V_251 = V_252 ;
}
if ( F_149 ( V_191 , V_16 -> V_84 . V_217 ) ) {
V_16 -> V_84 . V_253 = F_83 ;
F_121 ( V_254 , V_16 -> V_84 . V_217 ) ;
V_16 -> V_84 . V_255 = F_96 ;
V_16 -> V_84 . V_256 = F_100 ;
V_16 -> V_84 . V_257 = F_102 ;
V_16 -> V_84 . V_258 = F_104 ;
V_16 -> V_84 . V_259 = F_106 ;
V_16 -> V_84 . V_260 = V_261 ;
V_16 -> V_84 . V_262 = V_261 ;
V_16 -> V_84 . V_263 = F_150 ( V_148 ) | F_150 ( V_137 ) ;
V_16 -> V_84 . V_264 = V_265 ;
}
if ( F_149 ( V_218 , V_16 -> V_84 . V_217 ) )
V_16 -> V_84 . V_266 = F_92 ;
F_36 ( V_16 , V_209 , V_267 ) ;
F_73 ( & V_203 -> V_85 , L_53 ,
F_149 ( V_215 , V_16 -> V_84 . V_217 ) ? L_54 : L_55 ,
F_149 ( V_221 , V_16 -> V_84 . V_217 ) ? L_56 : L_55 ,
F_149 ( V_191 , V_16 -> V_84 . V_217 ) ? L_57 : L_55 ,
F_149 ( V_218 , V_16 -> V_84 . V_217 ) ? L_58 : L_55 ,
V_214 -> V_225 ) ;
F_151 ( & V_16 -> V_84 ) ;
if ( V_203 -> V_85 . V_204 ) {
V_147 = F_152 ( V_203 -> V_85 . V_204 ,
F_118 , V_16 ) ;
if ( V_147 ) {
F_20 ( & V_203 -> V_85 , L_59 ) ;
goto V_268;
}
}
return 0 ;
V_268:
F_153 ( & V_16 -> V_84 ) ;
F_154 ( V_16 -> V_66 ) ;
V_238:
F_154 ( V_16 -> V_19 ) ;
V_237:
F_155 ( F_134 ( V_203 , 0 ) , V_16 ) ;
V_236:
F_156 ( V_16 -> V_233 ) ;
V_235:
F_157 ( V_16 -> V_233 ) ;
V_234:
F_158 ( V_16 -> V_231 ) ;
V_16 -> V_231 = NULL ;
V_232:
F_159 ( V_213 -> V_227 , V_104 ) ;
V_230:
F_160 ( V_16 ) ;
return V_147 ;
}
static int F_161 ( struct V_187 * V_203 )
{
struct V_15 * V_16 = F_162 ( V_203 ) ;
struct V_11 * V_12 , * V_269 ;
struct V_212 * V_213 ;
F_131 ( V_16 ) ;
F_153 ( & V_16 -> V_84 ) ;
F_154 ( V_16 -> V_66 ) ;
F_154 ( V_16 -> V_19 ) ;
F_155 ( F_134 ( V_203 , 0 ) , V_16 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_163 ( V_16 , V_12 -> V_166 ) ;
F_164 ( & V_7 -> V_88 ) ;
F_15 ( & V_12 -> V_242 ) ;
}
F_156 ( V_16 -> V_233 ) ;
F_157 ( V_16 -> V_233 ) ;
F_158 ( V_16 -> V_231 ) ;
V_16 -> V_231 = NULL ;
V_213 = F_133 ( V_203 , V_224 , 0 ) ;
F_159 ( V_213 -> V_227 , F_136 ( V_213 ) ) ;
F_160 ( V_16 ) ;
return 0 ;
}
static void F_165 ( struct V_187 * V_203 )
{
struct V_15 * V_16 = F_162 ( V_203 ) ;
F_131 ( F_162 ( V_203 ) ) ;
F_156 ( V_16 -> V_233 ) ;
}
static int F_166 ( struct V_17 * V_85 )
{
struct V_187 * V_203 = F_167 ( V_85 ) ;
struct V_15 * V_16 = F_162 ( V_203 ) ;
struct V_11 * V_12 , * V_269 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
if ( F_28 ( V_7 ) && ! F_46 ( V_7 ) )
return - V_270 ;
}
return 0 ;
}
static void F_168 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = & V_7 -> V_31 ;
if ( ! F_105 ( V_7 ) ) {
F_169 ( F_17 ( V_12 ) ,
L_60 ) ;
F_102 ( V_12 ) ;
}
V_7 -> V_271 = F_29 ( V_7 , V_44 ) ;
F_30 ( V_7 ) ;
}
static int F_170 ( struct V_17 * V_85 )
{
struct V_187 * V_203 = F_167 ( V_85 ) ;
struct V_15 * V_16 = F_162 ( V_203 ) ;
struct V_11 * V_12 , * V_269 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
if ( F_46 ( V_7 ) )
F_168 ( V_7 ) ;
V_7 -> V_272 = F_29 ( V_7 , V_181 ) ;
}
V_16 -> V_273 = F_64 ( V_16 , V_82 ) ;
F_131 ( V_16 ) ;
F_156 ( V_16 -> V_233 ) ;
return 0 ;
}
static void F_171 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = F_6 ( V_7 -> V_31 . V_17 ) ;
F_31 ( V_7 , V_40 , 0 ) ;
F_31 ( V_7 , V_41 , 0 ) ;
F_31 ( V_7 , V_42 , 0 ) ;
F_31 ( V_7 , V_43 , 0 ) ;
F_31 ( V_7 , V_44 , V_7 -> V_271 ) ;
F_36 ( V_16 , V_50 , V_7 -> V_51 ) ;
F_30 ( V_7 ) ;
}
static int F_172 ( struct V_17 * V_85 )
{
struct V_187 * V_203 = F_167 ( V_85 ) ;
struct V_15 * V_16 = F_162 ( V_203 ) ;
struct V_11 * V_12 , * V_269 ;
F_142 ( V_16 -> V_233 ) ;
F_36 ( V_16 , V_209 , V_267 ) ;
while ( F_64 ( V_16 , V_83 ) )
F_107 () ;
F_36 ( V_16 , V_274 , V_16 -> V_273 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_31 ( V_7 , V_181 , V_7 -> V_272 ) ;
if ( F_46 ( V_7 ) )
F_171 ( V_7 ) ;
}
return 0 ;
}
static int T_9 F_173 ( void )
{
return F_174 ( & V_275 , F_132 ) ;
}
static void T_10 F_175 ( void )
{
F_176 ( & V_275 ) ;
}
