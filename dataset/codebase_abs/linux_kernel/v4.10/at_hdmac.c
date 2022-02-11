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
if ( V_14 -> V_66 ) {
F_48 ( V_16 -> V_67 , V_14 -> V_68 ,
V_14 -> V_69 ) ;
V_14 -> V_66 = false ;
}
F_23 ( & V_14 -> V_20 , & V_7 -> V_35 ) ;
F_49 ( & V_14 -> V_9 , & V_7 -> V_35 ) ;
F_50 ( V_21 ) ;
if ( ! F_46 ( V_7 ) ) {
F_51 ( V_21 , NULL ) ;
}
F_52 ( V_21 ) ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_5 * V_14 , * V_26 ;
F_11 ( V_70 ) ;
F_19 ( F_17 ( & V_7 -> V_31 ) , L_9 ) ;
if ( ! F_54 ( & V_7 -> V_10 ) )
F_27 ( V_7 , F_4 ( V_7 ) ) ;
F_23 ( & V_7 -> V_8 , & V_70 ) ;
F_23 ( & V_7 -> V_10 , & V_7 -> V_8 ) ;
F_13 (desc, _desc, &list, desc_node)
F_45 ( V_7 , V_14 ) ;
}
static void F_55 ( struct V_6 * V_7 )
{
F_19 ( F_17 ( & V_7 -> V_31 ) , L_10 ) ;
if ( F_28 ( V_7 ) )
return;
if ( F_54 ( & V_7 -> V_8 ) ||
F_56 ( & V_7 -> V_8 ) ) {
F_53 ( V_7 ) ;
} else {
F_45 ( V_7 , F_2 ( V_7 ) ) ;
F_27 ( V_7 , F_2 ( V_7 ) ) ;
}
}
static void F_57 ( struct V_6 * V_7 )
{
struct V_5 * V_71 ;
struct V_5 * V_34 ;
V_71 = F_2 ( V_7 ) ;
F_58 ( & V_71 -> V_9 ) ;
F_23 ( & V_7 -> V_10 , V_7 -> V_8 . V_37 ) ;
if ( ! F_54 ( & V_7 -> V_8 ) )
F_27 ( V_7 , F_2 ( V_7 ) ) ;
F_59 ( F_17 ( & V_7 -> V_31 ) ,
L_11 ) ;
F_59 ( F_17 ( & V_7 -> V_31 ) ,
L_12 , V_71 -> V_21 . V_52 ) ;
F_60 ( V_7 , & V_71 -> V_38 ) ;
F_22 (child, &bad_desc->tx_list, desc_node)
F_60 ( V_7 , & V_34 -> V_38 ) ;
F_45 ( V_7 , V_71 ) ;
}
static void F_61 ( struct V_6 * V_7 )
{
struct V_5 * V_36 = F_2 ( V_7 ) ;
struct V_65 * V_21 = & V_36 -> V_21 ;
F_19 ( F_17 ( & V_7 -> V_31 ) ,
L_13 ,
F_29 ( V_7 , V_44 ) ) ;
F_51 ( V_21 , NULL ) ;
}
static void F_62 ( unsigned long V_72 )
{
struct V_6 * V_7 = (struct V_6 * ) V_72 ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
if ( F_63 ( V_73 , & V_7 -> V_74 ) )
F_57 ( V_7 ) ;
else if ( F_46 ( V_7 ) )
F_61 ( V_7 ) ;
else
F_55 ( V_7 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
}
static T_6 F_64 ( int V_75 , void * V_76 )
{
struct V_15 * V_16 = (struct V_15 * ) V_76 ;
struct V_6 * V_7 ;
int V_28 ;
T_5 V_74 , V_77 , V_78 ;
int V_27 = V_79 ;
do {
V_78 = F_65 ( V_16 , V_80 ) ;
V_74 = F_65 ( V_16 , V_81 ) ;
V_77 = V_74 & V_78 ;
if ( ! V_77 )
break;
F_19 ( V_16 -> V_82 . V_83 ,
L_14 ,
V_74 , V_78 , V_77 ) ;
for ( V_28 = 0 ; V_28 < V_16 -> V_82 . V_84 ; V_28 ++ ) {
V_7 = & V_16 -> V_12 [ V_28 ] ;
if ( V_77 & ( F_66 ( V_28 ) | F_67 ( V_28 ) ) ) {
if ( V_77 & F_67 ( V_28 ) ) {
F_36 ( V_16 , V_85 ,
F_68 ( V_28 ) | V_7 -> V_51 ) ;
F_69 ( V_73 , & V_7 -> V_74 ) ;
}
F_70 ( & V_7 -> V_86 ) ;
V_27 = V_87 ;
}
}
} while ( V_77 );
return V_27 ;
}
static T_4 V_25 ( struct V_65 * V_88 )
{
struct V_5 * V_14 = F_71 ( V_88 ) ;
struct V_6 * V_7 = F_41 ( V_88 -> V_12 ) ;
T_4 V_52 ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_52 = F_72 ( V_88 ) ;
if ( F_54 ( & V_7 -> V_8 ) ) {
F_19 ( F_17 ( V_88 -> V_12 ) , L_15 ,
V_14 -> V_21 . V_52 ) ;
F_27 ( V_7 , V_14 ) ;
F_26 ( & V_14 -> V_9 , & V_7 -> V_8 ) ;
} else {
F_19 ( F_17 ( V_88 -> V_12 ) , L_16 ,
V_14 -> V_21 . V_52 ) ;
F_26 ( & V_14 -> V_9 , & V_7 -> V_10 ) ;
}
F_18 ( & V_7 -> V_30 , V_22 ) ;
return V_52 ;
}
static struct V_65 *
F_73 ( struct V_11 * V_12 ,
struct V_89 * V_90 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_91 * V_36 = V_90 -> V_92 ;
struct V_5 * V_14 = NULL ;
T_2 V_93 ;
unsigned int V_94 ;
T_5 V_54 ;
T_5 V_95 ;
T_2 V_3 = 0 ;
int V_28 ;
if ( F_44 ( ! V_90 || V_90 -> V_96 != 1 || ! V_90 -> V_97 ) )
return NULL ;
F_74 ( F_17 ( V_12 ) ,
L_17 ,
V_98 , & V_90 -> V_99 , & V_90 -> V_100 , V_90 -> V_96 ,
V_90 -> V_97 , V_22 ) ;
for ( V_28 = 0 ; V_28 < V_90 -> V_97 ; V_28 ++ ) {
struct V_91 * V_101 = V_90 -> V_92 + V_28 ;
if ( ( V_101 -> V_102 != V_90 -> V_92 -> V_102 ) ||
( F_75 ( V_90 , V_101 ) != F_75 ( V_90 , V_36 ) ) ||
( F_76 ( V_90 , V_101 ) != F_76 ( V_90 , V_36 ) ) ) {
F_20 ( F_17 ( V_12 ) ,
L_18 ,
V_98 ) ;
return NULL ;
}
V_3 += V_101 -> V_102 ;
}
V_94 = F_1 ( V_90 -> V_99 ,
V_90 -> V_100 , V_3 ) ;
V_93 = V_3 >> V_94 ;
if ( V_93 > V_56 ) {
F_20 ( F_17 ( V_12 ) , L_19 , V_98 ) ;
return NULL ;
}
V_54 = F_77 ( V_94 ) |
F_78 ( V_94 ) ;
V_95 = V_103 | V_104
| V_105
| V_106
| V_107
| V_108
| V_109 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 ) {
F_20 ( F_17 ( V_12 ) ,
L_20 , V_98 ) ;
return NULL ;
}
V_14 -> V_38 . V_110 = V_90 -> V_99 ;
V_14 -> V_38 . V_111 = V_90 -> V_100 ;
V_14 -> V_38 . V_54 = V_54 | V_93 ;
V_14 -> V_38 . V_95 = V_95 ;
V_14 -> V_47 = V_36 -> V_102 >> V_94 ;
V_14 -> V_49 = ( F_75 ( V_90 , V_36 ) >> V_94 ) + 1 ;
V_14 -> V_46 = ( F_76 ( V_90 , V_36 ) >> V_94 ) + 1 ;
V_14 -> V_21 . V_52 = - V_112 ;
V_14 -> V_61 = V_14 -> V_3 = V_3 ;
F_79 ( V_14 ) ;
V_14 -> V_21 . V_22 = V_22 ;
return & V_14 -> V_21 ;
}
static struct V_65 *
F_80 ( struct V_11 * V_12 , T_1 V_113 , T_1 V_1 ,
T_2 V_3 , unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_5 * V_14 = NULL ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
T_2 V_93 ;
T_2 V_114 ;
unsigned int V_57 ;
unsigned int V_115 ;
T_5 V_54 ;
T_5 V_95 ;
F_19 ( F_17 ( V_12 ) , L_21 ,
& V_113 , & V_1 , V_3 , V_22 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) , L_22 ) ;
return NULL ;
}
V_95 = V_103 | V_104
| V_105
| V_106
| V_109 ;
V_57 = V_115 = F_1 ( V_1 , V_113 , V_3 ) ;
V_54 = F_77 ( V_57 ) |
F_78 ( V_115 ) ;
for ( V_114 = 0 ; V_114 < V_3 ; V_114 += V_93 << V_57 ) {
V_93 = F_81 ( T_2 , ( V_3 - V_114 ) >> V_57 ,
V_56 ) ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_116;
V_14 -> V_38 . V_110 = V_1 + V_114 ;
V_14 -> V_38 . V_111 = V_113 + V_114 ;
V_14 -> V_38 . V_54 = V_54 | V_93 ;
V_14 -> V_38 . V_95 = V_95 ;
V_14 -> V_21 . V_52 = 0 ;
V_14 -> V_3 = V_93 << V_57 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
}
V_36 -> V_21 . V_52 = - V_112 ;
V_36 -> V_61 = V_3 ;
F_79 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_116:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_5 * F_82 ( struct V_11 * V_12 ,
T_1 V_117 ,
T_1 V_118 ,
T_2 V_3 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_5 * V_14 ;
T_2 V_93 ;
T_5 V_54 = F_77 ( 2 ) | F_78 ( 2 ) ;
T_5 V_95 = V_103 | V_104 |
V_119 |
V_106 |
V_109 ;
V_93 = V_3 >> 2 ;
if ( V_93 > V_56 ) {
F_20 ( F_17 ( V_12 ) , L_19 ,
V_98 ) ;
return NULL ;
}
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 ) {
F_20 ( F_17 ( V_12 ) , L_23 ,
V_98 ) ;
return NULL ;
}
V_14 -> V_38 . V_110 = V_117 ;
V_14 -> V_38 . V_111 = V_118 ;
V_14 -> V_38 . V_54 = V_54 | V_93 ;
V_14 -> V_38 . V_95 = V_95 ;
V_14 -> V_21 . V_52 = 0 ;
V_14 -> V_3 = V_3 ;
return V_14 ;
}
static struct V_65 *
F_83 ( struct V_11 * V_12 , T_1 V_113 , int V_120 ,
T_2 V_3 , unsigned long V_22 )
{
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 ;
void T_7 * V_121 ;
T_1 V_122 ;
F_19 ( F_17 ( V_12 ) , L_24 , V_98 ,
& V_113 , V_120 , V_3 , V_22 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) , L_25 , V_98 ) ;
return NULL ;
}
if ( ! F_84 ( V_12 -> V_17 , V_113 , 0 , V_3 ) ) {
F_16 ( F_17 ( V_12 ) , L_26 ,
V_98 ) ;
return NULL ;
}
V_121 = F_85 ( V_16 -> V_67 , V_32 , & V_122 ) ;
if ( ! V_121 ) {
F_20 ( F_17 ( V_12 ) , L_27 ,
V_98 ) ;
return NULL ;
}
* ( T_5 * ) V_121 = V_120 ;
V_14 = F_82 ( V_12 , V_122 , V_113 , V_3 ) ;
if ( ! V_14 ) {
F_20 ( F_17 ( V_12 ) , L_28 ,
V_98 ) ;
goto V_123;
}
V_14 -> V_69 = V_122 ;
V_14 -> V_68 = V_121 ;
V_14 -> V_66 = true ;
V_14 -> V_21 . V_52 = - V_112 ;
V_14 -> V_61 = V_3 ;
F_79 ( V_14 ) ;
V_14 -> V_21 . V_22 = V_22 ;
return & V_14 -> V_21 ;
V_123:
F_48 ( V_16 -> V_67 , V_121 , V_122 ) ;
return NULL ;
}
static struct V_65 *
F_86 ( struct V_11 * V_12 ,
struct V_124 * V_92 ,
unsigned int V_125 , int V_120 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 = NULL , * V_36 = NULL , * V_37 = NULL ;
struct V_124 * V_126 ;
void T_7 * V_121 ;
T_1 V_122 ;
T_2 V_61 = 0 ;
int V_28 ;
F_19 ( F_17 ( V_12 ) , L_29 , V_98 ,
V_120 , V_125 , V_22 ) ;
if ( F_44 ( ! V_92 || ! V_125 ) ) {
F_16 ( F_17 ( V_12 ) , L_30 ,
V_98 ) ;
return NULL ;
}
V_121 = F_85 ( V_16 -> V_67 , V_32 , & V_122 ) ;
if ( ! V_121 ) {
F_20 ( F_17 ( V_12 ) , L_27 ,
V_98 ) ;
return NULL ;
}
* ( T_5 * ) V_121 = V_120 ;
F_87 (sgl, sg, sg_len, i) {
T_1 V_113 = F_88 ( V_126 ) ;
T_2 V_3 = F_89 ( V_126 ) ;
F_19 ( F_17 ( V_12 ) , L_31 ,
V_98 , & V_113 , V_3 ) ;
if ( ! F_84 ( V_12 -> V_17 , V_113 , 0 , V_3 ) ) {
F_20 ( F_17 ( V_12 ) , L_26 ,
V_98 ) ;
goto V_127;
}
V_14 = F_82 ( V_12 , V_122 , V_113 , V_3 ) ;
if ( ! V_14 )
goto V_127;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_61 += V_3 ;
}
V_14 -> V_69 = V_122 ;
V_14 -> V_68 = V_121 ;
V_14 -> V_66 = true ;
V_36 -> V_21 . V_52 = - V_112 ;
V_36 -> V_61 = V_61 ;
F_79 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_127:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_65 *
F_90 ( struct V_11 * V_12 , struct V_124 * V_92 ,
unsigned int V_125 , enum V_128 V_129 ,
unsigned long V_22 , void * V_130 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_131 * V_132 = V_12 -> V_133 ;
struct V_134 * V_135 = & V_7 -> V_136 ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
T_5 V_54 ;
T_5 V_95 ;
T_1 V_137 ;
unsigned int V_138 ;
unsigned int V_139 ;
unsigned int V_28 ;
struct V_124 * V_126 ;
T_2 V_61 = 0 ;
F_19 ( F_17 ( V_12 ) , L_32 ,
V_125 ,
V_129 == V_140 ? L_33 : L_34 ,
V_22 ) ;
if ( F_44 ( ! V_132 || ! V_125 ) ) {
F_16 ( F_17 ( V_12 ) , L_35 ) ;
return NULL ;
}
V_54 = F_91 ( V_135 -> V_141 )
| F_92 ( V_135 -> V_142 ) ;
V_95 = V_104 ;
switch ( V_129 ) {
case V_140 :
V_138 = F_93 ( V_135 -> V_143 ) ;
V_54 |= F_78 ( V_138 ) ;
V_95 |= V_144
| V_105
| V_145
| F_94 ( V_7 -> V_146 ) | F_95 ( V_7 -> V_147 ) ;
V_137 = V_135 -> V_148 ;
F_87 (sgl, sg, sg_len, i) {
struct V_5 * V_14 ;
T_5 V_3 ;
T_5 V_149 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_116;
V_149 = F_88 ( V_126 ) ;
V_3 = F_89 ( V_126 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) ,
L_36 , V_28 ) ;
goto V_150;
}
V_139 = 2 ;
if ( F_44 ( V_149 & 3 || V_3 & 3 ) )
V_139 = 0 ;
V_14 -> V_38 . V_110 = V_149 ;
V_14 -> V_38 . V_111 = V_137 ;
V_14 -> V_38 . V_54 = V_54
| F_77 ( V_139 )
| V_3 >> V_139 ;
V_14 -> V_38 . V_95 = V_95 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_61 += V_3 ;
}
break;
case V_151 :
V_138 = F_93 ( V_135 -> V_152 ) ;
V_54 |= F_77 ( V_138 ) ;
V_95 |= V_106
| V_119
| V_153
| F_94 ( V_7 -> V_147 ) | F_95 ( V_7 -> V_146 ) ;
V_137 = V_135 -> V_154 ;
F_87 (sgl, sg, sg_len, i) {
struct V_5 * V_14 ;
T_5 V_3 ;
T_5 V_149 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_116;
V_149 = F_88 ( V_126 ) ;
V_3 = F_89 ( V_126 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) ,
L_36 , V_28 ) ;
goto V_150;
}
V_139 = 2 ;
if ( F_44 ( V_149 & 3 || V_3 & 3 ) )
V_139 = 0 ;
V_14 -> V_38 . V_110 = V_137 ;
V_14 -> V_38 . V_111 = V_149 ;
V_14 -> V_38 . V_54 = V_54
| F_78 ( V_139 )
| V_3 >> V_138 ;
V_14 -> V_38 . V_95 = V_95 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_61 += V_3 ;
}
break;
default:
return NULL ;
}
F_79 ( V_37 ) ;
V_36 -> V_21 . V_52 = - V_112 ;
V_36 -> V_61 = V_61 ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_116:
F_20 ( F_17 ( V_12 ) , L_3 ) ;
V_150:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_65 *
F_96 ( struct V_11 * V_12 ,
struct V_124 * V_155 , unsigned int V_156 ,
struct V_124 * V_157 , unsigned int V_158 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_5 * V_14 = NULL ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
unsigned int V_57 ;
unsigned int V_115 ;
T_2 V_93 ;
T_5 V_54 ;
T_5 V_95 ;
T_2 V_159 = 0 , V_160 = 0 ;
T_1 V_2 = 0 , V_1 = 0 ;
T_2 V_3 = 0 , V_61 = 0 ;
if ( F_44 ( V_156 == 0 || V_158 == 0 ) )
return NULL ;
if ( F_44 ( V_155 == NULL || V_157 == NULL ) )
return NULL ;
V_95 = V_103 | V_104
| V_105
| V_106
| V_109 ;
while ( true ) {
if ( V_159 == 0 ) {
if ( ! V_155 || ! V_156 )
break;
V_2 = F_88 ( V_155 ) ;
V_159 = F_89 ( V_155 ) ;
V_155 = F_97 ( V_155 ) ;
V_156 -- ;
}
if ( V_160 == 0 ) {
if ( ! V_157 || ! V_158 )
break;
V_1 = F_88 ( V_157 ) ;
V_160 = F_89 ( V_157 ) ;
V_157 = F_97 ( V_157 ) ;
V_158 -- ;
}
V_3 = F_81 ( T_2 , V_160 , V_159 ) ;
if ( V_3 == 0 )
continue;
V_57 = V_115 = F_1 ( V_1 , V_2 , V_3 ) ;
V_54 = F_77 ( V_57 ) |
F_78 ( V_115 ) ;
V_93 = V_3 >> V_57 ;
if ( V_93 > V_56 ) {
V_93 = V_56 ;
V_3 = V_56 << V_57 ;
}
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_116;
V_14 -> V_38 . V_110 = V_1 ;
V_14 -> V_38 . V_111 = V_2 ;
V_14 -> V_38 . V_54 = V_54 | V_93 ;
V_14 -> V_38 . V_95 = V_95 ;
V_14 -> V_21 . V_52 = 0 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_159 -= V_3 ;
V_160 -= V_3 ;
V_2 += V_3 ;
V_1 += V_3 ;
V_61 += V_3 ;
}
V_36 -> V_21 . V_52 = - V_112 ;
V_36 -> V_61 = V_61 ;
F_79 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_116:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static int
F_98 ( unsigned int V_138 , T_1 V_161 ,
T_2 V_162 )
{
if ( V_162 > ( V_56 << V_138 ) )
goto V_163;
if ( F_44 ( V_162 & ( ( 1 << V_138 ) - 1 ) ) )
goto V_163;
if ( F_44 ( V_161 & ( ( 1 << V_138 ) - 1 ) ) )
goto V_163;
return 0 ;
V_163:
return - V_60 ;
}
static int
F_99 ( struct V_11 * V_12 , struct V_5 * V_14 ,
unsigned int V_164 , T_1 V_161 ,
unsigned int V_138 , T_2 V_162 ,
enum V_128 V_129 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_134 * V_135 = & V_7 -> V_136 ;
T_5 V_54 ;
V_54 = F_91 ( V_135 -> V_141 )
| F_92 ( V_135 -> V_142 )
| F_78 ( V_138 )
| F_77 ( V_138 )
| V_162 >> V_138 ;
switch ( V_129 ) {
case V_140 :
V_14 -> V_38 . V_110 = V_161 + ( V_162 * V_164 ) ;
V_14 -> V_38 . V_111 = V_135 -> V_148 ;
V_14 -> V_38 . V_54 = V_54 ;
V_14 -> V_38 . V_95 = V_144
| V_105
| V_145
| F_94 ( V_7 -> V_146 )
| F_95 ( V_7 -> V_147 ) ;
V_14 -> V_3 = V_162 ;
break;
case V_151 :
V_14 -> V_38 . V_110 = V_135 -> V_154 ;
V_14 -> V_38 . V_111 = V_161 + ( V_162 * V_164 ) ;
V_14 -> V_38 . V_54 = V_54 ;
V_14 -> V_38 . V_95 = V_106
| V_119
| V_153
| F_94 ( V_7 -> V_147 )
| F_95 ( V_7 -> V_146 ) ;
V_14 -> V_3 = V_162 ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static struct V_65 *
F_100 ( struct V_11 * V_12 , T_1 V_161 , T_2 V_165 ,
T_2 V_162 , enum V_128 V_129 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_131 * V_132 = V_12 -> V_133 ;
struct V_134 * V_135 = & V_7 -> V_136 ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
unsigned long V_166 ;
unsigned int V_138 ;
unsigned int V_167 = V_165 / V_162 ;
unsigned int V_28 ;
F_19 ( F_17 ( V_12 ) , L_37 ,
V_129 == V_140 ? L_33 : L_34 ,
& V_161 ,
V_167 , V_165 , V_162 ) ;
if ( F_44 ( ! V_132 || ! V_165 || ! V_162 ) ) {
F_16 ( F_17 ( V_12 ) , L_38 ) ;
return NULL ;
}
V_166 = F_101 ( V_168 , & V_7 -> V_74 ) ;
if ( V_166 ) {
F_16 ( F_17 ( V_12 ) , L_39 ) ;
return NULL ;
}
if ( F_44 ( ! F_102 ( V_129 ) ) )
goto V_163;
if ( V_135 -> V_129 == V_140 )
V_138 = F_93 ( V_135 -> V_143 ) ;
else
V_138 = F_93 ( V_135 -> V_152 ) ;
if ( F_98 ( V_138 , V_161 , V_162 ) )
goto V_163;
for ( V_28 = 0 ; V_28 < V_167 ; V_28 ++ ) {
struct V_5 * V_14 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_116;
if ( F_99 ( V_12 , V_14 , V_28 , V_161 ,
V_138 , V_162 , V_129 ) )
goto V_116;
F_25 ( & V_36 , & V_37 , V_14 ) ;
}
V_37 -> V_38 . V_39 = V_36 -> V_21 . V_18 ;
V_36 -> V_21 . V_52 = - V_112 ;
V_36 -> V_61 = V_165 ;
return & V_36 -> V_21 ;
V_116:
F_20 ( F_17 ( V_12 ) , L_3 ) ;
F_21 ( V_7 , V_36 ) ;
V_163:
F_103 ( V_168 , & V_7 -> V_74 ) ;
return NULL ;
}
static int F_104 ( struct V_11 * V_12 ,
struct V_134 * V_135 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_98 ) ;
if ( ! V_12 -> V_133 )
return - V_60 ;
memcpy ( & V_7 -> V_136 , V_135 , sizeof( * V_135 ) ) ;
F_105 ( & V_7 -> V_136 . V_141 ) ;
F_105 ( & V_7 -> V_136 . V_142 ) ;
return 0 ;
}
static int F_106 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_169 = V_7 -> V_31 . V_169 ;
unsigned long V_22 ;
F_11 ( V_70 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_98 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_50 , F_107 ( V_169 ) ) ;
F_69 ( V_170 , & V_7 -> V_74 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_108 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_169 = V_7 -> V_31 . V_169 ;
unsigned long V_22 ;
F_11 ( V_70 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_98 ) ;
if ( ! F_109 ( V_7 ) )
return 0 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_85 , F_68 ( V_169 ) ) ;
F_103 ( V_170 , & V_7 -> V_74 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_110 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_169 = V_7 -> V_31 . V_169 ;
struct V_5 * V_14 , * V_26 ;
unsigned long V_22 ;
F_11 ( V_70 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_98 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_85 , F_68 ( V_169 ) | V_7 -> V_51 ) ;
while ( F_65 ( V_16 , V_171 ) & V_7 -> V_51 )
F_111 () ;
F_23 ( & V_7 -> V_10 , & V_70 ) ;
F_23 ( & V_7 -> V_8 , & V_70 ) ;
F_13 (desc, _desc, &list, desc_node)
F_45 ( V_7 , V_14 ) ;
F_103 ( V_170 , & V_7 -> V_74 ) ;
F_103 ( V_168 , & V_7 -> V_74 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static enum V_172
F_112 ( struct V_11 * V_12 ,
T_4 V_52 ,
struct V_173 * V_174 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
unsigned long V_22 ;
enum V_172 V_27 ;
int V_175 = 0 ;
V_27 = F_113 ( V_12 , V_52 , V_174 ) ;
if ( V_27 == V_176 )
return V_27 ;
if ( ! V_174 )
return V_177 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_175 = F_40 ( V_12 , V_52 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
if ( F_44 ( V_175 < 0 ) ) {
F_19 ( F_17 ( V_12 ) , L_41 ) ;
return V_177 ;
} else {
F_114 ( V_174 , V_175 ) ;
}
F_19 ( F_17 ( V_12 ) , L_42 ,
V_27 , V_52 , V_175 ) ;
return V_27 ;
}
static void F_115 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
unsigned long V_22 ;
F_19 ( F_17 ( V_12 ) , L_43 ) ;
if ( F_46 ( V_7 ) )
return;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_55 ( V_7 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
}
static int F_116 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 ;
struct V_131 * V_132 ;
unsigned long V_22 ;
int V_28 ;
T_5 V_178 ;
F_11 ( V_29 ) ;
F_19 ( F_17 ( V_12 ) , L_44 ) ;
if ( F_28 ( V_7 ) ) {
F_16 ( F_17 ( V_12 ) , L_45 ) ;
return - V_179 ;
}
V_178 = V_180 ;
V_132 = V_12 -> V_133 ;
if ( V_132 ) {
F_117 ( ! V_132 -> V_181 || V_132 -> V_181 != V_16 -> V_82 . V_83 ) ;
if ( V_132 -> V_178 )
V_178 = V_132 -> V_178 ;
}
if ( ! F_54 ( & V_7 -> V_35 ) )
return V_7 -> V_33 ;
for ( V_28 = 0 ; V_28 < V_182 ; V_28 ++ ) {
V_14 = F_5 ( V_12 , V_183 ) ;
if ( ! V_14 ) {
F_20 ( V_16 -> V_82 . V_83 ,
L_46 , V_28 ) ;
break;
}
F_26 ( & V_14 -> V_9 , & V_29 ) ;
}
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_7 -> V_33 = V_28 ;
F_118 ( & V_29 , & V_7 -> V_35 ) ;
F_119 ( V_12 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
F_31 ( V_7 , V_184 , V_178 ) ;
F_16 ( F_17 ( V_12 ) ,
L_47 ,
V_7 -> V_33 ) ;
return V_7 -> V_33 ;
}
static void F_120 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 , * V_26 ;
F_11 ( V_70 ) ;
F_16 ( F_17 ( V_12 ) , L_48 ,
V_7 -> V_33 ) ;
F_117 ( ! F_54 ( & V_7 -> V_8 ) ) ;
F_117 ( ! F_54 ( & V_7 -> V_10 ) ) ;
F_117 ( F_28 ( V_7 ) ) ;
F_13 (desc, _desc, &atchan->free_list, desc_node) {
F_19 ( F_17 ( V_12 ) , L_49 , V_14 ) ;
F_15 ( & V_14 -> V_9 ) ;
F_48 ( V_16 -> V_19 , V_14 , V_14 -> V_21 . V_18 ) ;
}
F_23 ( & V_7 -> V_35 , & V_70 ) ;
V_7 -> V_33 = 0 ;
V_7 -> V_74 = 0 ;
F_19 ( F_17 ( V_12 ) , L_50 ) ;
}
static bool F_121 ( struct V_11 * V_12 , void * V_185 )
{
struct V_131 * V_132 = V_185 ;
if ( V_132 -> V_181 == V_12 -> V_17 -> V_83 ) {
V_12 -> V_133 = V_132 ;
return true ;
} else {
return false ;
}
}
static struct V_11 * F_122 ( struct V_186 * V_187 ,
struct V_188 * V_188 )
{
struct V_11 * V_12 ;
struct V_6 * V_7 ;
struct V_131 * V_132 ;
T_8 V_51 ;
unsigned int V_189 ;
struct V_190 * V_191 ;
if ( V_187 -> V_192 != 2 )
return NULL ;
V_191 = F_123 ( V_187 -> V_193 ) ;
F_124 ( V_51 ) ;
F_125 ( V_194 , V_51 ) ;
V_132 = F_126 ( & V_191 -> V_83 , sizeof( * V_132 ) , V_183 ) ;
if ( ! V_132 )
return NULL ;
V_132 -> V_178 = V_195 | V_196 ;
V_189 = V_187 -> args [ 1 ] & V_197 ;
V_132 -> V_178 |= F_127 ( V_189 ) | F_128 ( V_189 )
| F_129 ( V_189 ) | F_130 ( V_189 ) ;
switch ( V_187 -> args [ 1 ] & V_198 ) {
case V_199 :
V_132 -> V_178 |= V_200 ;
break;
case V_201 :
V_132 -> V_178 |= V_202 ;
break;
case V_203 :
default:
V_132 -> V_178 |= V_204 ;
}
V_132 -> V_181 = & V_191 -> V_83 ;
V_12 = F_131 ( V_51 , F_121 , V_132 ) ;
if ( ! V_12 )
return NULL ;
V_7 = F_41 ( V_12 ) ;
V_7 -> V_147 = V_187 -> args [ 0 ] & 0xff ;
V_7 -> V_146 = ( V_187 -> args [ 0 ] >> 16 ) & 0xff ;
return V_12 ;
}
static struct V_11 * F_122 ( struct V_186 * V_187 ,
struct V_188 * V_188 )
{
return NULL ;
}
static inline const struct V_205 * T_9 F_132 (
struct V_190 * V_206 )
{
if ( V_206 -> V_83 . V_207 ) {
const struct V_208 * V_209 ;
V_209 = F_133 ( V_210 , V_206 -> V_83 . V_207 ) ;
if ( V_209 == NULL )
return NULL ;
return V_209 -> V_72 ;
}
return (struct V_205 * )
F_134 ( V_206 ) -> V_211 ;
}
static void F_135 ( struct V_15 * V_16 )
{
F_36 ( V_16 , V_212 , 0 ) ;
F_36 ( V_16 , V_213 , - 1L ) ;
while ( F_65 ( V_16 , V_171 ) & V_16 -> V_214 )
F_111 () ;
}
static int T_9 F_136 ( struct V_190 * V_206 )
{
struct V_215 * V_216 ;
struct V_15 * V_16 ;
T_2 V_102 ;
int V_75 ;
int V_150 ;
int V_28 ;
const struct V_205 * V_217 ;
F_125 ( V_218 , V_219 . V_220 ) ;
F_125 ( V_221 , V_219 . V_220 ) ;
F_125 ( V_222 , V_223 . V_220 ) ;
F_125 ( V_218 , V_223 . V_220 ) ;
F_125 ( V_224 , V_223 . V_220 ) ;
F_125 ( V_225 , V_223 . V_220 ) ;
F_125 ( V_226 , V_223 . V_220 ) ;
F_125 ( V_194 , V_223 . V_220 ) ;
F_125 ( V_221 , V_223 . V_220 ) ;
V_217 = F_132 ( V_206 ) ;
if ( ! V_217 )
return - V_227 ;
V_216 = F_137 ( V_206 , V_228 , 0 ) ;
if ( ! V_216 )
return - V_60 ;
V_75 = F_138 ( V_206 , 0 ) ;
if ( V_75 < 0 )
return V_75 ;
V_102 = sizeof( struct V_15 ) ;
V_102 += V_217 -> V_229 * sizeof( struct V_6 ) ;
V_16 = F_139 ( V_102 , V_183 ) ;
if ( ! V_16 )
return - V_230 ;
V_16 -> V_82 . V_220 = V_217 -> V_220 ;
V_16 -> V_214 = ( 1 << V_217 -> V_229 ) - 1 ;
V_102 = F_140 ( V_216 ) ;
if ( ! F_141 ( V_216 -> V_231 , V_102 , V_206 -> V_83 . V_232 -> V_233 ) ) {
V_150 = - V_112 ;
goto V_234;
}
V_16 -> V_235 = F_142 ( V_216 -> V_231 , V_102 ) ;
if ( ! V_16 -> V_235 ) {
V_150 = - V_230 ;
goto V_236;
}
V_16 -> V_237 = F_143 ( & V_206 -> V_83 , L_51 ) ;
if ( F_144 ( V_16 -> V_237 ) ) {
V_150 = F_145 ( V_16 -> V_237 ) ;
goto V_238;
}
V_150 = F_146 ( V_16 -> V_237 ) ;
if ( V_150 )
goto V_239;
F_135 ( V_16 ) ;
V_150 = F_147 ( V_75 , F_64 , 0 , L_52 , V_16 ) ;
if ( V_150 )
goto V_240;
F_148 ( V_206 , V_16 ) ;
V_16 -> V_19 = F_149 ( L_53 ,
& V_206 -> V_83 , sizeof( struct V_5 ) ,
4 , 0 ) ;
if ( ! V_16 -> V_19 ) {
F_20 ( & V_206 -> V_83 , L_54 ) ;
V_150 = - V_230 ;
goto V_241;
}
V_16 -> V_67 = F_149 ( L_55 ,
& V_206 -> V_83 , sizeof( int ) , 4 , 0 ) ;
if ( ! V_16 -> V_67 ) {
F_20 ( & V_206 -> V_83 , L_56 ) ;
V_150 = - V_230 ;
goto V_242;
}
while ( F_65 ( V_16 , V_81 ) )
F_111 () ;
F_8 ( & V_16 -> V_82 . V_243 ) ;
for ( V_28 = 0 ; V_28 < V_217 -> V_229 ; V_28 ++ ) {
struct V_6 * V_7 = & V_16 -> V_12 [ V_28 ] ;
V_7 -> V_146 = V_244 ;
V_7 -> V_147 = V_245 ;
V_7 -> V_31 . V_17 = & V_16 -> V_82 ;
F_119 ( & V_7 -> V_31 ) ;
F_26 ( & V_7 -> V_31 . V_246 ,
& V_16 -> V_82 . V_243 ) ;
V_7 -> V_247 = V_16 -> V_235 + V_247 ( V_28 ) ;
F_150 ( & V_7 -> V_30 ) ;
V_7 -> V_51 = 1 << V_28 ;
F_8 ( & V_7 -> V_8 ) ;
F_8 ( & V_7 -> V_10 ) ;
F_8 ( & V_7 -> V_35 ) ;
F_151 ( & V_7 -> V_86 , F_62 ,
( unsigned long ) V_7 ) ;
F_152 ( V_16 , V_28 ) ;
}
V_16 -> V_82 . V_248 = F_116 ;
V_16 -> V_82 . V_249 = F_120 ;
V_16 -> V_82 . V_250 = F_112 ;
V_16 -> V_82 . V_251 = F_115 ;
V_16 -> V_82 . V_83 = & V_206 -> V_83 ;
if ( F_153 ( V_222 , V_16 -> V_82 . V_220 ) )
V_16 -> V_82 . V_252 = F_73 ;
if ( F_153 ( V_218 , V_16 -> V_82 . V_220 ) )
V_16 -> V_82 . V_253 = F_80 ;
if ( F_153 ( V_224 , V_16 -> V_82 . V_220 ) ) {
V_16 -> V_82 . V_254 = F_83 ;
V_16 -> V_82 . V_255 = F_86 ;
V_16 -> V_82 . V_256 = V_257 ;
}
if ( F_153 ( V_194 , V_16 -> V_82 . V_220 ) ) {
V_16 -> V_82 . V_258 = F_90 ;
F_125 ( V_259 , V_16 -> V_82 . V_220 ) ;
V_16 -> V_82 . V_260 = F_100 ;
V_16 -> V_82 . V_261 = F_104 ;
V_16 -> V_82 . V_262 = F_106 ;
V_16 -> V_82 . V_263 = F_108 ;
V_16 -> V_82 . V_264 = F_110 ;
V_16 -> V_82 . V_265 = V_266 ;
V_16 -> V_82 . V_267 = V_266 ;
V_16 -> V_82 . V_268 = F_154 ( V_151 ) | F_154 ( V_140 ) ;
V_16 -> V_82 . V_269 = V_270 ;
}
if ( F_153 ( V_221 , V_16 -> V_82 . V_220 ) )
V_16 -> V_82 . V_271 = F_96 ;
F_36 ( V_16 , V_212 , V_272 ) ;
F_74 ( & V_206 -> V_83 , L_57 ,
F_153 ( V_218 , V_16 -> V_82 . V_220 ) ? L_58 : L_59 ,
F_153 ( V_224 , V_16 -> V_82 . V_220 ) ? L_60 : L_59 ,
F_153 ( V_194 , V_16 -> V_82 . V_220 ) ? L_61 : L_59 ,
F_153 ( V_221 , V_16 -> V_82 . V_220 ) ? L_62 : L_59 ,
V_217 -> V_229 ) ;
F_155 ( & V_16 -> V_82 ) ;
if ( V_206 -> V_83 . V_207 ) {
V_150 = F_156 ( V_206 -> V_83 . V_207 ,
F_122 , V_16 ) ;
if ( V_150 ) {
F_20 ( & V_206 -> V_83 , L_63 ) ;
goto V_273;
}
}
return 0 ;
V_273:
F_157 ( & V_16 -> V_82 ) ;
F_158 ( V_16 -> V_67 ) ;
V_242:
F_158 ( V_16 -> V_19 ) ;
V_241:
F_159 ( F_138 ( V_206 , 0 ) , V_16 ) ;
V_240:
F_160 ( V_16 -> V_237 ) ;
V_239:
F_161 ( V_16 -> V_237 ) ;
V_238:
F_162 ( V_16 -> V_235 ) ;
V_16 -> V_235 = NULL ;
V_236:
F_163 ( V_216 -> V_231 , V_102 ) ;
V_234:
F_164 ( V_16 ) ;
return V_150 ;
}
static int F_165 ( struct V_190 * V_206 )
{
struct V_15 * V_16 = F_166 ( V_206 ) ;
struct V_11 * V_12 , * V_274 ;
struct V_215 * V_216 ;
F_135 ( V_16 ) ;
F_157 ( & V_16 -> V_82 ) ;
F_158 ( V_16 -> V_67 ) ;
F_158 ( V_16 -> V_19 ) ;
F_159 ( F_138 ( V_206 , 0 ) , V_16 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_167 ( V_16 , V_12 -> V_169 ) ;
F_168 ( & V_7 -> V_86 ) ;
F_15 ( & V_12 -> V_246 ) ;
}
F_160 ( V_16 -> V_237 ) ;
F_161 ( V_16 -> V_237 ) ;
F_162 ( V_16 -> V_235 ) ;
V_16 -> V_235 = NULL ;
V_216 = F_137 ( V_206 , V_228 , 0 ) ;
F_163 ( V_216 -> V_231 , F_140 ( V_216 ) ) ;
F_164 ( V_16 ) ;
return 0 ;
}
static void F_169 ( struct V_190 * V_206 )
{
struct V_15 * V_16 = F_166 ( V_206 ) ;
F_135 ( F_166 ( V_206 ) ) ;
F_160 ( V_16 -> V_237 ) ;
}
static int F_170 ( struct V_17 * V_83 )
{
struct V_190 * V_206 = F_171 ( V_83 ) ;
struct V_15 * V_16 = F_166 ( V_206 ) ;
struct V_11 * V_12 , * V_274 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
if ( F_28 ( V_7 ) && ! F_46 ( V_7 ) )
return - V_275 ;
}
return 0 ;
}
static void F_172 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = & V_7 -> V_31 ;
if ( ! F_109 ( V_7 ) ) {
F_173 ( F_17 ( V_12 ) ,
L_64 ) ;
F_106 ( V_12 ) ;
}
V_7 -> V_276 = F_29 ( V_7 , V_44 ) ;
F_30 ( V_7 ) ;
}
static int F_174 ( struct V_17 * V_83 )
{
struct V_190 * V_206 = F_171 ( V_83 ) ;
struct V_15 * V_16 = F_166 ( V_206 ) ;
struct V_11 * V_12 , * V_274 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
if ( F_46 ( V_7 ) )
F_172 ( V_7 ) ;
V_7 -> V_277 = F_29 ( V_7 , V_184 ) ;
}
V_16 -> V_278 = F_65 ( V_16 , V_80 ) ;
F_135 ( V_16 ) ;
F_160 ( V_16 -> V_237 ) ;
return 0 ;
}
static void F_175 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = F_6 ( V_7 -> V_31 . V_17 ) ;
F_31 ( V_7 , V_40 , 0 ) ;
F_31 ( V_7 , V_41 , 0 ) ;
F_31 ( V_7 , V_42 , 0 ) ;
F_31 ( V_7 , V_43 , 0 ) ;
F_31 ( V_7 , V_44 , V_7 -> V_276 ) ;
F_36 ( V_16 , V_50 , V_7 -> V_51 ) ;
F_30 ( V_7 ) ;
}
static int F_176 ( struct V_17 * V_83 )
{
struct V_190 * V_206 = F_171 ( V_83 ) ;
struct V_15 * V_16 = F_166 ( V_206 ) ;
struct V_11 * V_12 , * V_274 ;
F_146 ( V_16 -> V_237 ) ;
F_36 ( V_16 , V_212 , V_272 ) ;
while ( F_65 ( V_16 , V_81 ) )
F_111 () ;
F_36 ( V_16 , V_279 , V_16 -> V_278 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_31 ( V_7 , V_184 , V_7 -> V_277 ) ;
if ( F_46 ( V_7 ) )
F_175 ( V_7 ) ;
}
return 0 ;
}
static int T_9 F_177 ( void )
{
return F_178 ( & V_280 , F_136 ) ;
}
static void T_10 F_179 ( void )
{
F_180 ( & V_280 ) ;
}
