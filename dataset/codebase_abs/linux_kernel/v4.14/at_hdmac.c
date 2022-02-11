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
static int
F_96 ( unsigned int V_138 , T_1 V_155 ,
T_2 V_156 )
{
if ( V_156 > ( V_56 << V_138 ) )
goto V_157;
if ( F_44 ( V_156 & ( ( 1 << V_138 ) - 1 ) ) )
goto V_157;
if ( F_44 ( V_155 & ( ( 1 << V_138 ) - 1 ) ) )
goto V_157;
return 0 ;
V_157:
return - V_60 ;
}
static int
F_97 ( struct V_11 * V_12 , struct V_5 * V_14 ,
unsigned int V_158 , T_1 V_155 ,
unsigned int V_138 , T_2 V_156 ,
enum V_128 V_129 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_134 * V_135 = & V_7 -> V_136 ;
T_5 V_54 ;
V_54 = F_91 ( V_135 -> V_141 )
| F_92 ( V_135 -> V_142 )
| F_78 ( V_138 )
| F_77 ( V_138 )
| V_156 >> V_138 ;
switch ( V_129 ) {
case V_140 :
V_14 -> V_38 . V_110 = V_155 + ( V_156 * V_158 ) ;
V_14 -> V_38 . V_111 = V_135 -> V_148 ;
V_14 -> V_38 . V_54 = V_54 ;
V_14 -> V_38 . V_95 = V_144
| V_105
| V_145
| F_94 ( V_7 -> V_146 )
| F_95 ( V_7 -> V_147 ) ;
V_14 -> V_3 = V_156 ;
break;
case V_151 :
V_14 -> V_38 . V_110 = V_135 -> V_154 ;
V_14 -> V_38 . V_111 = V_155 + ( V_156 * V_158 ) ;
V_14 -> V_38 . V_54 = V_54 ;
V_14 -> V_38 . V_95 = V_106
| V_119
| V_153
| F_94 ( V_7 -> V_147 )
| F_95 ( V_7 -> V_146 ) ;
V_14 -> V_3 = V_156 ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static struct V_65 *
F_98 ( struct V_11 * V_12 , T_1 V_155 , T_2 V_159 ,
T_2 V_156 , enum V_128 V_129 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_131 * V_132 = V_12 -> V_133 ;
struct V_134 * V_135 = & V_7 -> V_136 ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
unsigned long V_160 ;
unsigned int V_138 ;
unsigned int V_161 = V_159 / V_156 ;
unsigned int V_28 ;
F_19 ( F_17 ( V_12 ) , L_37 ,
V_129 == V_140 ? L_33 : L_34 ,
& V_155 ,
V_161 , V_159 , V_156 ) ;
if ( F_44 ( ! V_132 || ! V_159 || ! V_156 ) ) {
F_16 ( F_17 ( V_12 ) , L_38 ) ;
return NULL ;
}
V_160 = F_99 ( V_162 , & V_7 -> V_74 ) ;
if ( V_160 ) {
F_16 ( F_17 ( V_12 ) , L_39 ) ;
return NULL ;
}
if ( F_44 ( ! F_100 ( V_129 ) ) )
goto V_157;
if ( V_135 -> V_129 == V_140 )
V_138 = F_93 ( V_135 -> V_143 ) ;
else
V_138 = F_93 ( V_135 -> V_152 ) ;
if ( F_96 ( V_138 , V_155 , V_156 ) )
goto V_157;
for ( V_28 = 0 ; V_28 < V_161 ; V_28 ++ ) {
struct V_5 * V_14 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_116;
if ( F_97 ( V_12 , V_14 , V_28 , V_155 ,
V_138 , V_156 , V_129 ) )
goto V_116;
F_25 ( & V_36 , & V_37 , V_14 ) ;
}
V_37 -> V_38 . V_39 = V_36 -> V_21 . V_18 ;
V_36 -> V_21 . V_52 = - V_112 ;
V_36 -> V_61 = V_159 ;
return & V_36 -> V_21 ;
V_116:
F_20 ( F_17 ( V_12 ) , L_3 ) ;
F_21 ( V_7 , V_36 ) ;
V_157:
F_101 ( V_162 , & V_7 -> V_74 ) ;
return NULL ;
}
static int F_102 ( struct V_11 * V_12 ,
struct V_134 * V_135 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_98 ) ;
if ( ! V_12 -> V_133 )
return - V_60 ;
memcpy ( & V_7 -> V_136 , V_135 , sizeof( * V_135 ) ) ;
F_103 ( & V_7 -> V_136 . V_141 ) ;
F_103 ( & V_7 -> V_136 . V_142 ) ;
return 0 ;
}
static int F_104 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_163 = V_7 -> V_31 . V_163 ;
unsigned long V_22 ;
F_11 ( V_70 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_98 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_50 , F_105 ( V_163 ) ) ;
F_69 ( V_164 , & V_7 -> V_74 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_106 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_163 = V_7 -> V_31 . V_163 ;
unsigned long V_22 ;
F_11 ( V_70 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_98 ) ;
if ( ! F_107 ( V_7 ) )
return 0 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_85 , F_68 ( V_163 ) ) ;
F_101 ( V_164 , & V_7 -> V_74 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_108 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_163 = V_7 -> V_31 . V_163 ;
struct V_5 * V_14 , * V_26 ;
unsigned long V_22 ;
F_11 ( V_70 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_98 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_85 , F_68 ( V_163 ) | V_7 -> V_51 ) ;
while ( F_65 ( V_16 , V_165 ) & V_7 -> V_51 )
F_109 () ;
F_23 ( & V_7 -> V_10 , & V_70 ) ;
F_23 ( & V_7 -> V_8 , & V_70 ) ;
F_13 (desc, _desc, &list, desc_node)
F_45 ( V_7 , V_14 ) ;
F_101 ( V_164 , & V_7 -> V_74 ) ;
F_101 ( V_162 , & V_7 -> V_74 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static enum V_166
F_110 ( struct V_11 * V_12 ,
T_4 V_52 ,
struct V_167 * V_168 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
unsigned long V_22 ;
enum V_166 V_27 ;
int V_169 = 0 ;
V_27 = F_111 ( V_12 , V_52 , V_168 ) ;
if ( V_27 == V_170 )
return V_27 ;
if ( ! V_168 )
return V_171 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_169 = F_40 ( V_12 , V_52 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
if ( F_44 ( V_169 < 0 ) ) {
F_19 ( F_17 ( V_12 ) , L_41 ) ;
return V_171 ;
} else {
F_112 ( V_168 , V_169 ) ;
}
F_19 ( F_17 ( V_12 ) , L_42 ,
V_27 , V_52 , V_169 ) ;
return V_27 ;
}
static void F_113 ( struct V_11 * V_12 )
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
static int F_114 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 ;
struct V_131 * V_132 ;
unsigned long V_22 ;
int V_28 ;
T_5 V_172 ;
F_11 ( V_29 ) ;
F_19 ( F_17 ( V_12 ) , L_44 ) ;
if ( F_28 ( V_7 ) ) {
F_16 ( F_17 ( V_12 ) , L_45 ) ;
return - V_173 ;
}
V_172 = V_174 ;
V_132 = V_12 -> V_133 ;
if ( V_132 ) {
F_115 ( ! V_132 -> V_175 || V_132 -> V_175 != V_16 -> V_82 . V_83 ) ;
if ( V_132 -> V_172 )
V_172 = V_132 -> V_172 ;
}
if ( ! F_54 ( & V_7 -> V_35 ) )
return V_7 -> V_33 ;
for ( V_28 = 0 ; V_28 < V_176 ; V_28 ++ ) {
V_14 = F_5 ( V_12 , V_177 ) ;
if ( ! V_14 ) {
F_20 ( V_16 -> V_82 . V_83 ,
L_46 , V_28 ) ;
break;
}
F_26 ( & V_14 -> V_9 , & V_29 ) ;
}
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_7 -> V_33 = V_28 ;
F_116 ( & V_29 , & V_7 -> V_35 ) ;
F_117 ( V_12 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
F_31 ( V_7 , V_178 , V_172 ) ;
F_16 ( F_17 ( V_12 ) ,
L_47 ,
V_7 -> V_33 ) ;
return V_7 -> V_33 ;
}
static void F_118 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 , * V_26 ;
F_11 ( V_70 ) ;
F_16 ( F_17 ( V_12 ) , L_48 ,
V_7 -> V_33 ) ;
F_115 ( ! F_54 ( & V_7 -> V_8 ) ) ;
F_115 ( ! F_54 ( & V_7 -> V_10 ) ) ;
F_115 ( F_28 ( V_7 ) ) ;
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
static bool F_119 ( struct V_11 * V_12 , void * V_179 )
{
struct V_131 * V_132 = V_179 ;
if ( V_132 -> V_175 == V_12 -> V_17 -> V_83 ) {
V_12 -> V_133 = V_132 ;
return true ;
} else {
return false ;
}
}
static struct V_11 * F_120 ( struct V_180 * V_181 ,
struct V_182 * V_182 )
{
struct V_11 * V_12 ;
struct V_6 * V_7 ;
struct V_131 * V_132 ;
T_8 V_51 ;
unsigned int V_183 ;
struct V_184 * V_185 ;
if ( V_181 -> V_186 != 2 )
return NULL ;
V_185 = F_121 ( V_181 -> V_187 ) ;
F_122 ( V_51 ) ;
F_123 ( V_188 , V_51 ) ;
V_132 = F_124 ( & V_185 -> V_83 , sizeof( * V_132 ) , V_177 ) ;
if ( ! V_132 )
return NULL ;
V_132 -> V_172 = V_189 | V_190 ;
V_183 = V_181 -> args [ 1 ] & V_191 ;
V_132 -> V_172 |= F_125 ( V_183 ) | F_126 ( V_183 )
| F_127 ( V_183 ) | F_128 ( V_183 ) ;
switch ( V_181 -> args [ 1 ] & V_192 ) {
case V_193 :
V_132 -> V_172 |= V_194 ;
break;
case V_195 :
V_132 -> V_172 |= V_196 ;
break;
case V_197 :
default:
V_132 -> V_172 |= V_198 ;
}
V_132 -> V_175 = & V_185 -> V_83 ;
V_12 = F_129 ( V_51 , F_119 , V_132 ) ;
if ( ! V_12 )
return NULL ;
V_7 = F_41 ( V_12 ) ;
V_7 -> V_147 = V_181 -> args [ 0 ] & 0xff ;
V_7 -> V_146 = ( V_181 -> args [ 0 ] >> 16 ) & 0xff ;
return V_12 ;
}
static struct V_11 * F_120 ( struct V_180 * V_181 ,
struct V_182 * V_182 )
{
return NULL ;
}
static inline const struct V_199 * T_9 F_130 (
struct V_184 * V_200 )
{
if ( V_200 -> V_83 . V_201 ) {
const struct V_202 * V_203 ;
V_203 = F_131 ( V_204 , V_200 -> V_83 . V_201 ) ;
if ( V_203 == NULL )
return NULL ;
return V_203 -> V_72 ;
}
return (struct V_199 * )
F_132 ( V_200 ) -> V_205 ;
}
static void F_133 ( struct V_15 * V_16 )
{
F_36 ( V_16 , V_206 , 0 ) ;
F_36 ( V_16 , V_207 , - 1L ) ;
while ( F_65 ( V_16 , V_165 ) & V_16 -> V_208 )
F_109 () ;
}
static int T_9 F_134 ( struct V_184 * V_200 )
{
struct V_209 * V_210 ;
struct V_15 * V_16 ;
T_2 V_102 ;
int V_75 ;
int V_150 ;
int V_28 ;
const struct V_199 * V_211 ;
F_123 ( V_212 , V_213 . V_214 ) ;
F_123 ( V_215 , V_216 . V_214 ) ;
F_123 ( V_212 , V_216 . V_214 ) ;
F_123 ( V_217 , V_216 . V_214 ) ;
F_123 ( V_218 , V_216 . V_214 ) ;
F_123 ( V_219 , V_216 . V_214 ) ;
F_123 ( V_188 , V_216 . V_214 ) ;
V_211 = F_130 ( V_200 ) ;
if ( ! V_211 )
return - V_220 ;
V_210 = F_135 ( V_200 , V_221 , 0 ) ;
if ( ! V_210 )
return - V_60 ;
V_75 = F_136 ( V_200 , 0 ) ;
if ( V_75 < 0 )
return V_75 ;
V_102 = sizeof( struct V_15 ) ;
V_102 += V_211 -> V_222 * sizeof( struct V_6 ) ;
V_16 = F_137 ( V_102 , V_177 ) ;
if ( ! V_16 )
return - V_223 ;
V_16 -> V_82 . V_214 = V_211 -> V_214 ;
V_16 -> V_208 = ( 1 << V_211 -> V_222 ) - 1 ;
V_102 = F_138 ( V_210 ) ;
if ( ! F_139 ( V_210 -> V_224 , V_102 , V_200 -> V_83 . V_225 -> V_226 ) ) {
V_150 = - V_112 ;
goto V_227;
}
V_16 -> V_228 = F_140 ( V_210 -> V_224 , V_102 ) ;
if ( ! V_16 -> V_228 ) {
V_150 = - V_223 ;
goto V_229;
}
V_16 -> V_230 = F_141 ( & V_200 -> V_83 , L_51 ) ;
if ( F_142 ( V_16 -> V_230 ) ) {
V_150 = F_143 ( V_16 -> V_230 ) ;
goto V_231;
}
V_150 = F_144 ( V_16 -> V_230 ) ;
if ( V_150 )
goto V_232;
F_133 ( V_16 ) ;
V_150 = F_145 ( V_75 , F_64 , 0 , L_52 , V_16 ) ;
if ( V_150 )
goto V_233;
F_146 ( V_200 , V_16 ) ;
V_16 -> V_19 = F_147 ( L_53 ,
& V_200 -> V_83 , sizeof( struct V_5 ) ,
4 , 0 ) ;
if ( ! V_16 -> V_19 ) {
F_20 ( & V_200 -> V_83 , L_54 ) ;
V_150 = - V_223 ;
goto V_234;
}
V_16 -> V_67 = F_147 ( L_55 ,
& V_200 -> V_83 , sizeof( int ) , 4 , 0 ) ;
if ( ! V_16 -> V_67 ) {
F_20 ( & V_200 -> V_83 , L_56 ) ;
V_150 = - V_223 ;
goto V_235;
}
while ( F_65 ( V_16 , V_81 ) )
F_109 () ;
F_8 ( & V_16 -> V_82 . V_236 ) ;
for ( V_28 = 0 ; V_28 < V_211 -> V_222 ; V_28 ++ ) {
struct V_6 * V_7 = & V_16 -> V_12 [ V_28 ] ;
V_7 -> V_146 = V_237 ;
V_7 -> V_147 = V_238 ;
V_7 -> V_31 . V_17 = & V_16 -> V_82 ;
F_117 ( & V_7 -> V_31 ) ;
F_26 ( & V_7 -> V_31 . V_239 ,
& V_16 -> V_82 . V_236 ) ;
V_7 -> V_240 = V_16 -> V_228 + V_240 ( V_28 ) ;
F_148 ( & V_7 -> V_30 ) ;
V_7 -> V_51 = 1 << V_28 ;
F_8 ( & V_7 -> V_8 ) ;
F_8 ( & V_7 -> V_10 ) ;
F_8 ( & V_7 -> V_35 ) ;
F_149 ( & V_7 -> V_86 , F_62 ,
( unsigned long ) V_7 ) ;
F_150 ( V_16 , V_28 ) ;
}
V_16 -> V_82 . V_241 = F_114 ;
V_16 -> V_82 . V_242 = F_118 ;
V_16 -> V_82 . V_243 = F_110 ;
V_16 -> V_82 . V_244 = F_113 ;
V_16 -> V_82 . V_83 = & V_200 -> V_83 ;
if ( F_151 ( V_215 , V_16 -> V_82 . V_214 ) )
V_16 -> V_82 . V_245 = F_73 ;
if ( F_151 ( V_212 , V_16 -> V_82 . V_214 ) )
V_16 -> V_82 . V_246 = F_80 ;
if ( F_151 ( V_217 , V_16 -> V_82 . V_214 ) ) {
V_16 -> V_82 . V_247 = F_83 ;
V_16 -> V_82 . V_248 = F_86 ;
V_16 -> V_82 . V_249 = V_250 ;
}
if ( F_151 ( V_188 , V_16 -> V_82 . V_214 ) ) {
V_16 -> V_82 . V_251 = F_90 ;
F_123 ( V_252 , V_16 -> V_82 . V_214 ) ;
V_16 -> V_82 . V_253 = F_98 ;
V_16 -> V_82 . V_254 = F_102 ;
V_16 -> V_82 . V_255 = F_104 ;
V_16 -> V_82 . V_256 = F_106 ;
V_16 -> V_82 . V_257 = F_108 ;
V_16 -> V_82 . V_258 = V_259 ;
V_16 -> V_82 . V_260 = V_259 ;
V_16 -> V_82 . V_261 = F_152 ( V_151 ) | F_152 ( V_140 ) ;
V_16 -> V_82 . V_262 = V_263 ;
}
F_36 ( V_16 , V_206 , V_264 ) ;
F_74 ( & V_200 -> V_83 , L_57 ,
F_151 ( V_212 , V_16 -> V_82 . V_214 ) ? L_58 : L_59 ,
F_151 ( V_217 , V_16 -> V_82 . V_214 ) ? L_60 : L_59 ,
F_151 ( V_188 , V_16 -> V_82 . V_214 ) ? L_61 : L_59 ,
V_211 -> V_222 ) ;
F_153 ( & V_16 -> V_82 ) ;
if ( V_200 -> V_83 . V_201 ) {
V_150 = F_154 ( V_200 -> V_83 . V_201 ,
F_120 , V_16 ) ;
if ( V_150 ) {
F_20 ( & V_200 -> V_83 , L_62 ) ;
goto V_265;
}
}
return 0 ;
V_265:
F_155 ( & V_16 -> V_82 ) ;
F_156 ( V_16 -> V_67 ) ;
V_235:
F_156 ( V_16 -> V_19 ) ;
V_234:
F_157 ( F_136 ( V_200 , 0 ) , V_16 ) ;
V_233:
F_158 ( V_16 -> V_230 ) ;
V_232:
F_159 ( V_16 -> V_230 ) ;
V_231:
F_160 ( V_16 -> V_228 ) ;
V_16 -> V_228 = NULL ;
V_229:
F_161 ( V_210 -> V_224 , V_102 ) ;
V_227:
F_162 ( V_16 ) ;
return V_150 ;
}
static int F_163 ( struct V_184 * V_200 )
{
struct V_15 * V_16 = F_164 ( V_200 ) ;
struct V_11 * V_12 , * V_266 ;
struct V_209 * V_210 ;
F_133 ( V_16 ) ;
F_155 ( & V_16 -> V_82 ) ;
F_156 ( V_16 -> V_67 ) ;
F_156 ( V_16 -> V_19 ) ;
F_157 ( F_136 ( V_200 , 0 ) , V_16 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_165 ( V_16 , V_12 -> V_163 ) ;
F_166 ( & V_7 -> V_86 ) ;
F_15 ( & V_12 -> V_239 ) ;
}
F_158 ( V_16 -> V_230 ) ;
F_159 ( V_16 -> V_230 ) ;
F_160 ( V_16 -> V_228 ) ;
V_16 -> V_228 = NULL ;
V_210 = F_135 ( V_200 , V_221 , 0 ) ;
F_161 ( V_210 -> V_224 , F_138 ( V_210 ) ) ;
F_162 ( V_16 ) ;
return 0 ;
}
static void F_167 ( struct V_184 * V_200 )
{
struct V_15 * V_16 = F_164 ( V_200 ) ;
F_133 ( F_164 ( V_200 ) ) ;
F_158 ( V_16 -> V_230 ) ;
}
static int F_168 ( struct V_17 * V_83 )
{
struct V_184 * V_200 = F_169 ( V_83 ) ;
struct V_15 * V_16 = F_164 ( V_200 ) ;
struct V_11 * V_12 , * V_266 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
if ( F_28 ( V_7 ) && ! F_46 ( V_7 ) )
return - V_267 ;
}
return 0 ;
}
static void F_170 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = & V_7 -> V_31 ;
if ( ! F_107 ( V_7 ) ) {
F_171 ( F_17 ( V_12 ) ,
L_63 ) ;
F_104 ( V_12 ) ;
}
V_7 -> V_268 = F_29 ( V_7 , V_44 ) ;
F_30 ( V_7 ) ;
}
static int F_172 ( struct V_17 * V_83 )
{
struct V_184 * V_200 = F_169 ( V_83 ) ;
struct V_15 * V_16 = F_164 ( V_200 ) ;
struct V_11 * V_12 , * V_266 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
if ( F_46 ( V_7 ) )
F_170 ( V_7 ) ;
V_7 -> V_269 = F_29 ( V_7 , V_178 ) ;
}
V_16 -> V_270 = F_65 ( V_16 , V_80 ) ;
F_133 ( V_16 ) ;
F_158 ( V_16 -> V_230 ) ;
return 0 ;
}
static void F_173 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = F_6 ( V_7 -> V_31 . V_17 ) ;
F_31 ( V_7 , V_40 , 0 ) ;
F_31 ( V_7 , V_41 , 0 ) ;
F_31 ( V_7 , V_42 , 0 ) ;
F_31 ( V_7 , V_43 , 0 ) ;
F_31 ( V_7 , V_44 , V_7 -> V_268 ) ;
F_36 ( V_16 , V_50 , V_7 -> V_51 ) ;
F_30 ( V_7 ) ;
}
static int F_174 ( struct V_17 * V_83 )
{
struct V_184 * V_200 = F_169 ( V_83 ) ;
struct V_15 * V_16 = F_164 ( V_200 ) ;
struct V_11 * V_12 , * V_266 ;
F_144 ( V_16 -> V_230 ) ;
F_36 ( V_16 , V_206 , V_264 ) ;
while ( F_65 ( V_16 , V_81 ) )
F_109 () ;
F_36 ( V_16 , V_271 , V_16 -> V_270 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_31 ( V_7 , V_178 , V_7 -> V_269 ) ;
if ( F_46 ( V_7 ) )
F_173 ( V_7 ) ;
}
return 0 ;
}
static int T_9 F_175 ( void )
{
return F_176 ( & V_272 , F_134 ) ;
}
static void T_10 F_177 ( void )
{
F_178 ( & V_272 ) ;
}
