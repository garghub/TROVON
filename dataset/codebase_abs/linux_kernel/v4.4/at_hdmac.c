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
if ( V_14 -> V_66 ) {
F_48 ( V_16 -> V_67 , V_14 -> V_68 ,
V_14 -> V_69 ) ;
V_14 -> V_66 = false ;
}
F_23 ( & V_14 -> V_20 , & V_7 -> V_35 ) ;
F_49 ( & V_14 -> V_9 , & V_7 -> V_35 ) ;
F_50 ( V_21 ) ;
if ( ! F_46 ( V_7 ) ) {
T_6 V_70 = V_21 -> V_70 ;
void * V_71 = V_21 -> V_72 ;
if ( V_70 )
V_70 ( V_71 ) ;
}
F_51 ( V_21 ) ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_5 * V_14 , * V_26 ;
F_11 ( V_73 ) ;
F_19 ( F_17 ( & V_7 -> V_31 ) , L_9 ) ;
if ( ! F_53 ( & V_7 -> V_10 ) )
F_27 ( V_7 , F_4 ( V_7 ) ) ;
F_23 ( & V_7 -> V_8 , & V_73 ) ;
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
struct V_5 * V_74 ;
struct V_5 * V_34 ;
V_74 = F_2 ( V_7 ) ;
F_57 ( & V_74 -> V_9 ) ;
F_23 ( & V_7 -> V_10 , V_7 -> V_8 . V_37 ) ;
if ( ! F_53 ( & V_7 -> V_8 ) )
F_27 ( V_7 , F_2 ( V_7 ) ) ;
F_58 ( F_17 ( & V_7 -> V_31 ) ,
L_11 ) ;
F_58 ( F_17 ( & V_7 -> V_31 ) ,
L_12 , V_74 -> V_21 . V_52 ) ;
F_59 ( V_7 , & V_74 -> V_38 ) ;
F_22 (child, &bad_desc->tx_list, desc_node)
F_59 ( V_7 , & V_34 -> V_38 ) ;
F_45 ( V_7 , V_74 ) ;
}
static void F_60 ( struct V_6 * V_7 )
{
struct V_5 * V_36 = F_2 ( V_7 ) ;
struct V_65 * V_21 = & V_36 -> V_21 ;
T_6 V_70 = V_21 -> V_70 ;
void * V_71 = V_21 -> V_72 ;
F_19 ( F_17 ( & V_7 -> V_31 ) ,
L_13 ,
F_29 ( V_7 , V_44 ) ) ;
if ( V_70 )
V_70 ( V_71 ) ;
}
static void F_61 ( unsigned long V_75 )
{
struct V_6 * V_7 = (struct V_6 * ) V_75 ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
if ( F_62 ( V_76 , & V_7 -> V_77 ) )
F_56 ( V_7 ) ;
else if ( F_46 ( V_7 ) )
F_60 ( V_7 ) ;
else
F_54 ( V_7 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
}
static T_7 F_63 ( int V_78 , void * V_79 )
{
struct V_15 * V_16 = (struct V_15 * ) V_79 ;
struct V_6 * V_7 ;
int V_28 ;
T_5 V_77 , V_80 , V_81 ;
int V_27 = V_82 ;
do {
V_81 = F_64 ( V_16 , V_83 ) ;
V_77 = F_64 ( V_16 , V_84 ) ;
V_80 = V_77 & V_81 ;
if ( ! V_80 )
break;
F_19 ( V_16 -> V_85 . V_86 ,
L_14 ,
V_77 , V_81 , V_80 ) ;
for ( V_28 = 0 ; V_28 < V_16 -> V_85 . V_87 ; V_28 ++ ) {
V_7 = & V_16 -> V_12 [ V_28 ] ;
if ( V_80 & ( F_65 ( V_28 ) | F_66 ( V_28 ) ) ) {
if ( V_80 & F_66 ( V_28 ) ) {
F_36 ( V_16 , V_88 ,
F_67 ( V_28 ) | V_7 -> V_51 ) ;
F_68 ( V_76 , & V_7 -> V_77 ) ;
}
F_69 ( & V_7 -> V_89 ) ;
V_27 = V_90 ;
}
}
} while ( V_80 );
return V_27 ;
}
static T_4 V_25 ( struct V_65 * V_91 )
{
struct V_5 * V_14 = F_70 ( V_91 ) ;
struct V_6 * V_7 = F_41 ( V_91 -> V_12 ) ;
T_4 V_52 ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_52 = F_71 ( V_91 ) ;
if ( F_53 ( & V_7 -> V_8 ) ) {
F_19 ( F_17 ( V_91 -> V_12 ) , L_15 ,
V_14 -> V_21 . V_52 ) ;
F_27 ( V_7 , V_14 ) ;
F_26 ( & V_14 -> V_9 , & V_7 -> V_8 ) ;
} else {
F_19 ( F_17 ( V_91 -> V_12 ) , L_16 ,
V_14 -> V_21 . V_52 ) ;
F_26 ( & V_14 -> V_9 , & V_7 -> V_10 ) ;
}
F_18 ( & V_7 -> V_30 , V_22 ) ;
return V_52 ;
}
static struct V_65 *
F_72 ( struct V_11 * V_12 ,
struct V_92 * V_93 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_94 * V_36 = V_93 -> V_95 ;
struct V_5 * V_14 = NULL ;
T_2 V_96 ;
unsigned int V_97 ;
T_5 V_54 ;
T_5 V_98 ;
T_2 V_3 = 0 ;
int V_28 ;
if ( F_44 ( ! V_93 || V_93 -> V_99 != 1 || ! V_93 -> V_100 ) )
return NULL ;
F_73 ( F_17 ( V_12 ) ,
L_17 ,
V_101 , & V_93 -> V_102 , & V_93 -> V_103 , V_93 -> V_99 ,
V_93 -> V_100 , V_22 ) ;
for ( V_28 = 0 ; V_28 < V_93 -> V_100 ; V_28 ++ ) {
struct V_94 * V_104 = V_93 -> V_95 + V_28 ;
if ( ( V_104 -> V_105 != V_93 -> V_95 -> V_105 ) ||
( F_74 ( V_93 , V_104 ) != F_74 ( V_93 , V_36 ) ) ||
( F_75 ( V_93 , V_104 ) != F_75 ( V_93 , V_36 ) ) ) {
F_20 ( F_17 ( V_12 ) ,
L_18 ,
V_101 ) ;
return NULL ;
}
V_3 += V_104 -> V_105 ;
}
V_97 = F_1 ( V_93 -> V_102 ,
V_93 -> V_103 , V_3 ) ;
V_96 = V_3 >> V_97 ;
if ( V_96 > V_56 ) {
F_20 ( F_17 ( V_12 ) , L_19 , V_101 ) ;
return NULL ;
}
V_54 = F_76 ( V_97 ) |
F_77 ( V_97 ) ;
V_98 = V_106 | V_107
| V_108
| V_109
| V_110
| V_111
| V_112 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 ) {
F_20 ( F_17 ( V_12 ) ,
L_20 , V_101 ) ;
return NULL ;
}
V_14 -> V_38 . V_113 = V_93 -> V_102 ;
V_14 -> V_38 . V_114 = V_93 -> V_103 ;
V_14 -> V_38 . V_54 = V_54 | V_96 ;
V_14 -> V_38 . V_98 = V_98 ;
V_14 -> V_47 = V_36 -> V_105 >> V_97 ;
V_14 -> V_49 = ( F_74 ( V_93 , V_36 ) >> V_97 ) + 1 ;
V_14 -> V_46 = ( F_75 ( V_93 , V_36 ) >> V_97 ) + 1 ;
V_14 -> V_21 . V_52 = - V_115 ;
V_14 -> V_61 = V_14 -> V_3 = V_3 ;
F_78 ( V_14 ) ;
V_14 -> V_21 . V_22 = V_22 ;
return & V_14 -> V_21 ;
}
static struct V_65 *
F_79 ( struct V_11 * V_12 , T_1 V_116 , T_1 V_1 ,
T_2 V_3 , unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_5 * V_14 = NULL ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
T_2 V_96 ;
T_2 V_117 ;
unsigned int V_57 ;
unsigned int V_118 ;
T_5 V_54 ;
T_5 V_98 ;
F_19 ( F_17 ( V_12 ) , L_21 ,
& V_116 , & V_1 , V_3 , V_22 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) , L_22 ) ;
return NULL ;
}
V_98 = V_106 | V_107
| V_108
| V_109
| V_112 ;
V_57 = V_118 = F_1 ( V_1 , V_116 , V_3 ) ;
V_54 = F_76 ( V_57 ) |
F_77 ( V_118 ) ;
for ( V_117 = 0 ; V_117 < V_3 ; V_117 += V_96 << V_57 ) {
V_96 = F_80 ( T_2 , ( V_3 - V_117 ) >> V_57 ,
V_56 ) ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_119;
V_14 -> V_38 . V_113 = V_1 + V_117 ;
V_14 -> V_38 . V_114 = V_116 + V_117 ;
V_14 -> V_38 . V_54 = V_54 | V_96 ;
V_14 -> V_38 . V_98 = V_98 ;
V_14 -> V_21 . V_52 = 0 ;
V_14 -> V_3 = V_96 << V_57 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
}
V_36 -> V_21 . V_52 = - V_115 ;
V_36 -> V_61 = V_3 ;
F_78 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_119:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_5 * F_81 ( struct V_11 * V_12 ,
T_1 V_120 ,
T_1 V_121 ,
T_2 V_3 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_5 * V_14 ;
T_2 V_96 ;
T_5 V_54 = F_76 ( 2 ) | F_77 ( 2 ) ;
T_5 V_98 = V_106 | V_107 |
V_122 |
V_109 |
V_112 ;
V_96 = V_3 >> 2 ;
if ( V_96 > V_56 ) {
F_20 ( F_17 ( V_12 ) , L_19 ,
V_101 ) ;
return NULL ;
}
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 ) {
F_20 ( F_17 ( V_12 ) , L_23 ,
V_101 ) ;
return NULL ;
}
V_14 -> V_38 . V_113 = V_120 ;
V_14 -> V_38 . V_114 = V_121 ;
V_14 -> V_38 . V_54 = V_54 | V_96 ;
V_14 -> V_38 . V_98 = V_98 ;
V_14 -> V_21 . V_52 = 0 ;
V_14 -> V_3 = V_3 ;
return V_14 ;
}
static struct V_65 *
F_82 ( struct V_11 * V_12 , T_1 V_116 , int V_123 ,
T_2 V_3 , unsigned long V_22 )
{
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 ;
void T_8 * V_124 ;
T_1 V_125 ;
F_19 ( F_17 ( V_12 ) , L_24 , V_101 ,
& V_116 , V_123 , V_3 , V_22 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) , L_25 , V_101 ) ;
return NULL ;
}
if ( ! F_83 ( V_12 -> V_17 , V_116 , 0 , V_3 ) ) {
F_16 ( F_17 ( V_12 ) , L_26 ,
V_101 ) ;
return NULL ;
}
V_124 = F_7 ( V_16 -> V_67 , V_32 , & V_125 ) ;
if ( ! V_124 ) {
F_20 ( F_17 ( V_12 ) , L_27 ,
V_101 ) ;
return NULL ;
}
* ( T_5 * ) V_124 = V_123 ;
V_14 = F_81 ( V_12 , V_125 , V_116 , V_3 ) ;
if ( ! V_14 ) {
F_20 ( F_17 ( V_12 ) , L_28 ,
V_101 ) ;
goto V_126;
}
V_14 -> V_69 = V_125 ;
V_14 -> V_68 = V_124 ;
V_14 -> V_66 = true ;
V_14 -> V_21 . V_52 = - V_115 ;
V_14 -> V_61 = V_3 ;
F_78 ( V_14 ) ;
V_14 -> V_21 . V_22 = V_22 ;
return & V_14 -> V_21 ;
V_126:
F_48 ( V_16 -> V_67 , V_124 , V_125 ) ;
return NULL ;
}
static struct V_65 *
F_84 ( struct V_11 * V_12 ,
struct V_127 * V_95 ,
unsigned int V_128 , int V_123 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 = NULL , * V_36 = NULL , * V_37 = NULL ;
struct V_127 * V_129 ;
void T_8 * V_124 ;
T_1 V_125 ;
T_2 V_61 = 0 ;
int V_28 ;
F_19 ( F_17 ( V_12 ) , L_29 , V_101 ,
V_123 , V_128 , V_22 ) ;
if ( F_44 ( ! V_95 || ! V_128 ) ) {
F_16 ( F_17 ( V_12 ) , L_30 ,
V_101 ) ;
return NULL ;
}
V_124 = F_7 ( V_16 -> V_67 , V_32 , & V_125 ) ;
if ( ! V_124 ) {
F_20 ( F_17 ( V_12 ) , L_27 ,
V_101 ) ;
return NULL ;
}
* ( T_5 * ) V_124 = V_123 ;
F_85 (sgl, sg, sg_len, i) {
T_1 V_116 = F_86 ( V_129 ) ;
T_2 V_3 = F_87 ( V_129 ) ;
F_19 ( F_17 ( V_12 ) , L_31 ,
V_101 , & V_116 , V_3 ) ;
if ( ! F_83 ( V_12 -> V_17 , V_116 , 0 , V_3 ) ) {
F_20 ( F_17 ( V_12 ) , L_26 ,
V_101 ) ;
goto V_130;
}
V_14 = F_81 ( V_12 , V_125 , V_116 , V_3 ) ;
if ( ! V_14 )
goto V_130;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_61 += V_3 ;
}
V_14 -> V_69 = V_125 ;
V_14 -> V_68 = V_124 ;
V_14 -> V_66 = true ;
V_36 -> V_21 . V_52 = - V_115 ;
V_36 -> V_61 = V_61 ;
F_78 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_130:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_65 *
F_88 ( struct V_11 * V_12 , struct V_127 * V_95 ,
unsigned int V_128 , enum V_131 V_132 ,
unsigned long V_22 , void * V_133 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_134 * V_135 = V_12 -> V_136 ;
struct V_137 * V_138 = & V_7 -> V_139 ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
T_5 V_54 ;
T_5 V_98 ;
T_1 V_140 ;
unsigned int V_141 ;
unsigned int V_142 ;
unsigned int V_28 ;
struct V_127 * V_129 ;
T_2 V_61 = 0 ;
F_19 ( F_17 ( V_12 ) , L_32 ,
V_128 ,
V_132 == V_143 ? L_33 : L_34 ,
V_22 ) ;
if ( F_44 ( ! V_135 || ! V_128 ) ) {
F_16 ( F_17 ( V_12 ) , L_35 ) ;
return NULL ;
}
V_54 = F_89 ( V_138 -> V_144 )
| F_90 ( V_138 -> V_145 ) ;
V_98 = V_107 ;
switch ( V_132 ) {
case V_143 :
V_141 = F_91 ( V_138 -> V_146 ) ;
V_54 |= F_77 ( V_141 ) ;
V_98 |= V_147
| V_108
| V_148
| F_92 ( V_7 -> V_149 ) | F_93 ( V_7 -> V_150 ) ;
V_140 = V_138 -> V_151 ;
F_85 (sgl, sg, sg_len, i) {
struct V_5 * V_14 ;
T_5 V_3 ;
T_5 V_152 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_119;
V_152 = F_86 ( V_129 ) ;
V_3 = F_87 ( V_129 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) ,
L_36 , V_28 ) ;
goto V_153;
}
V_142 = 2 ;
if ( F_44 ( V_152 & 3 || V_3 & 3 ) )
V_142 = 0 ;
V_14 -> V_38 . V_113 = V_152 ;
V_14 -> V_38 . V_114 = V_140 ;
V_14 -> V_38 . V_54 = V_54
| F_76 ( V_142 )
| V_3 >> V_142 ;
V_14 -> V_38 . V_98 = V_98 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_61 += V_3 ;
}
break;
case V_154 :
V_141 = F_91 ( V_138 -> V_155 ) ;
V_54 |= F_76 ( V_141 ) ;
V_98 |= V_109
| V_122
| V_156
| F_92 ( V_7 -> V_150 ) | F_93 ( V_7 -> V_149 ) ;
V_140 = V_138 -> V_157 ;
F_85 (sgl, sg, sg_len, i) {
struct V_5 * V_14 ;
T_5 V_3 ;
T_5 V_152 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_119;
V_152 = F_86 ( V_129 ) ;
V_3 = F_87 ( V_129 ) ;
if ( F_44 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) ,
L_36 , V_28 ) ;
goto V_153;
}
V_142 = 2 ;
if ( F_44 ( V_152 & 3 || V_3 & 3 ) )
V_142 = 0 ;
V_14 -> V_38 . V_113 = V_140 ;
V_14 -> V_38 . V_114 = V_152 ;
V_14 -> V_38 . V_54 = V_54
| F_77 ( V_142 )
| V_3 >> V_141 ;
V_14 -> V_38 . V_98 = V_98 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_61 += V_3 ;
}
break;
default:
return NULL ;
}
F_78 ( V_37 ) ;
V_36 -> V_21 . V_52 = - V_115 ;
V_36 -> V_61 = V_61 ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_119:
F_20 ( F_17 ( V_12 ) , L_3 ) ;
V_153:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_65 *
F_94 ( struct V_11 * V_12 ,
struct V_127 * V_158 , unsigned int V_159 ,
struct V_127 * V_160 , unsigned int V_161 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_5 * V_14 = NULL ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
unsigned int V_57 ;
unsigned int V_118 ;
T_2 V_96 ;
T_5 V_54 ;
T_5 V_98 ;
T_2 V_162 = 0 , V_163 = 0 ;
T_1 V_2 = 0 , V_1 = 0 ;
T_2 V_3 = 0 , V_61 = 0 ;
if ( F_44 ( V_159 == 0 || V_161 == 0 ) )
return NULL ;
if ( F_44 ( V_158 == NULL || V_160 == NULL ) )
return NULL ;
V_98 = V_106 | V_107
| V_108
| V_109
| V_112 ;
while ( true ) {
if ( V_162 == 0 ) {
if ( ! V_158 || ! V_159 )
break;
V_2 = F_86 ( V_158 ) ;
V_162 = F_87 ( V_158 ) ;
V_158 = F_95 ( V_158 ) ;
V_159 -- ;
}
if ( V_163 == 0 ) {
if ( ! V_160 || ! V_161 )
break;
V_1 = F_86 ( V_160 ) ;
V_163 = F_87 ( V_160 ) ;
V_160 = F_95 ( V_160 ) ;
V_161 -- ;
}
V_3 = F_80 ( T_2 , V_163 , V_162 ) ;
if ( V_3 == 0 )
continue;
V_57 = V_118 = F_1 ( V_1 , V_2 , V_3 ) ;
V_54 = F_76 ( V_57 ) |
F_77 ( V_118 ) ;
V_96 = V_3 >> V_57 ;
if ( V_96 > V_56 ) {
V_96 = V_56 ;
V_3 = V_56 << V_57 ;
}
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_119;
V_14 -> V_38 . V_113 = V_1 ;
V_14 -> V_38 . V_114 = V_2 ;
V_14 -> V_38 . V_54 = V_54 | V_96 ;
V_14 -> V_38 . V_98 = V_98 ;
V_14 -> V_21 . V_52 = 0 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_162 -= V_3 ;
V_163 -= V_3 ;
V_2 += V_3 ;
V_1 += V_3 ;
V_61 += V_3 ;
}
V_36 -> V_21 . V_52 = - V_115 ;
V_36 -> V_61 = V_61 ;
F_78 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_119:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static int
F_96 ( unsigned int V_141 , T_1 V_164 ,
T_2 V_165 )
{
if ( V_165 > ( V_56 << V_141 ) )
goto V_166;
if ( F_44 ( V_165 & ( ( 1 << V_141 ) - 1 ) ) )
goto V_166;
if ( F_44 ( V_164 & ( ( 1 << V_141 ) - 1 ) ) )
goto V_166;
return 0 ;
V_166:
return - V_60 ;
}
static int
F_97 ( struct V_11 * V_12 , struct V_5 * V_14 ,
unsigned int V_167 , T_1 V_164 ,
unsigned int V_141 , T_2 V_165 ,
enum V_131 V_132 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_137 * V_138 = & V_7 -> V_139 ;
T_5 V_54 ;
V_54 = F_89 ( V_138 -> V_144 )
| F_90 ( V_138 -> V_145 )
| F_77 ( V_141 )
| F_76 ( V_141 )
| V_165 >> V_141 ;
switch ( V_132 ) {
case V_143 :
V_14 -> V_38 . V_113 = V_164 + ( V_165 * V_167 ) ;
V_14 -> V_38 . V_114 = V_138 -> V_151 ;
V_14 -> V_38 . V_54 = V_54 ;
V_14 -> V_38 . V_98 = V_147
| V_108
| V_148
| F_92 ( V_7 -> V_149 )
| F_93 ( V_7 -> V_150 ) ;
V_14 -> V_3 = V_165 ;
break;
case V_154 :
V_14 -> V_38 . V_113 = V_138 -> V_157 ;
V_14 -> V_38 . V_114 = V_164 + ( V_165 * V_167 ) ;
V_14 -> V_38 . V_54 = V_54 ;
V_14 -> V_38 . V_98 = V_109
| V_122
| V_156
| F_92 ( V_7 -> V_150 )
| F_93 ( V_7 -> V_149 ) ;
V_14 -> V_3 = V_165 ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static struct V_65 *
F_98 ( struct V_11 * V_12 , T_1 V_164 , T_2 V_168 ,
T_2 V_165 , enum V_131 V_132 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_134 * V_135 = V_12 -> V_136 ;
struct V_137 * V_138 = & V_7 -> V_139 ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
unsigned long V_169 ;
unsigned int V_141 ;
unsigned int V_170 = V_168 / V_165 ;
unsigned int V_28 ;
F_19 ( F_17 ( V_12 ) , L_37 ,
V_132 == V_143 ? L_33 : L_34 ,
& V_164 ,
V_170 , V_168 , V_165 ) ;
if ( F_44 ( ! V_135 || ! V_168 || ! V_165 ) ) {
F_16 ( F_17 ( V_12 ) , L_38 ) ;
return NULL ;
}
V_169 = F_99 ( V_171 , & V_7 -> V_77 ) ;
if ( V_169 ) {
F_16 ( F_17 ( V_12 ) , L_39 ) ;
return NULL ;
}
if ( F_44 ( ! F_100 ( V_132 ) ) )
goto V_166;
if ( V_138 -> V_132 == V_143 )
V_141 = F_91 ( V_138 -> V_146 ) ;
else
V_141 = F_91 ( V_138 -> V_155 ) ;
if ( F_96 ( V_141 , V_164 , V_165 ) )
goto V_166;
for ( V_28 = 0 ; V_28 < V_170 ; V_28 ++ ) {
struct V_5 * V_14 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_119;
if ( F_97 ( V_12 , V_14 , V_28 , V_164 ,
V_141 , V_165 , V_132 ) )
goto V_119;
F_25 ( & V_36 , & V_37 , V_14 ) ;
}
V_37 -> V_38 . V_39 = V_36 -> V_21 . V_18 ;
V_36 -> V_21 . V_52 = - V_115 ;
V_36 -> V_61 = V_168 ;
return & V_36 -> V_21 ;
V_119:
F_20 ( F_17 ( V_12 ) , L_3 ) ;
F_21 ( V_7 , V_36 ) ;
V_166:
F_101 ( V_171 , & V_7 -> V_77 ) ;
return NULL ;
}
static int F_102 ( struct V_11 * V_12 ,
struct V_137 * V_138 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_101 ) ;
if ( ! V_12 -> V_136 )
return - V_60 ;
memcpy ( & V_7 -> V_139 , V_138 , sizeof( * V_138 ) ) ;
F_103 ( & V_7 -> V_139 . V_144 ) ;
F_103 ( & V_7 -> V_139 . V_145 ) ;
return 0 ;
}
static int F_104 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_172 = V_7 -> V_31 . V_172 ;
unsigned long V_22 ;
F_11 ( V_73 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_101 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_50 , F_105 ( V_172 ) ) ;
F_68 ( V_173 , & V_7 -> V_77 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_106 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_172 = V_7 -> V_31 . V_172 ;
unsigned long V_22 ;
F_11 ( V_73 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_101 ) ;
if ( ! F_107 ( V_7 ) )
return 0 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_88 , F_67 ( V_172 ) ) ;
F_101 ( V_173 , & V_7 -> V_77 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_108 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_172 = V_7 -> V_31 . V_172 ;
struct V_5 * V_14 , * V_26 ;
unsigned long V_22 ;
F_11 ( V_73 ) ;
F_19 ( F_17 ( V_12 ) , L_40 , V_101 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_36 ( V_16 , V_88 , F_67 ( V_172 ) | V_7 -> V_51 ) ;
while ( F_64 ( V_16 , V_174 ) & V_7 -> V_51 )
F_109 () ;
F_23 ( & V_7 -> V_10 , & V_73 ) ;
F_23 ( & V_7 -> V_8 , & V_73 ) ;
F_13 (desc, _desc, &list, desc_node)
F_45 ( V_7 , V_14 ) ;
F_101 ( V_173 , & V_7 -> V_77 ) ;
F_101 ( V_171 , & V_7 -> V_77 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static enum V_175
F_110 ( struct V_11 * V_12 ,
T_4 V_52 ,
struct V_176 * V_177 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
unsigned long V_22 ;
enum V_175 V_27 ;
int V_178 = 0 ;
V_27 = F_111 ( V_12 , V_52 , V_177 ) ;
if ( V_27 == V_179 )
return V_27 ;
if ( ! V_177 )
return V_180 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_178 = F_40 ( V_12 , V_52 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
if ( F_44 ( V_178 < 0 ) ) {
F_19 ( F_17 ( V_12 ) , L_41 ) ;
return V_180 ;
} else {
F_112 ( V_177 , V_178 ) ;
}
F_19 ( F_17 ( V_12 ) , L_42 ,
V_27 , V_52 , V_178 ) ;
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
F_54 ( V_7 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
}
static int F_114 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_41 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 ;
struct V_134 * V_135 ;
unsigned long V_22 ;
int V_28 ;
T_5 V_181 ;
F_11 ( V_29 ) ;
F_19 ( F_17 ( V_12 ) , L_44 ) ;
if ( F_28 ( V_7 ) ) {
F_16 ( F_17 ( V_12 ) , L_45 ) ;
return - V_182 ;
}
V_181 = V_183 ;
V_135 = V_12 -> V_136 ;
if ( V_135 ) {
F_115 ( ! V_135 -> V_184 || V_135 -> V_184 != V_16 -> V_85 . V_86 ) ;
if ( V_135 -> V_181 )
V_181 = V_135 -> V_181 ;
}
if ( ! F_53 ( & V_7 -> V_35 ) )
return V_7 -> V_33 ;
for ( V_28 = 0 ; V_28 < V_185 ; V_28 ++ ) {
V_14 = F_5 ( V_12 , V_186 ) ;
if ( ! V_14 ) {
F_20 ( V_16 -> V_85 . V_86 ,
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
F_31 ( V_7 , V_187 , V_181 ) ;
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
F_11 ( V_73 ) ;
F_16 ( F_17 ( V_12 ) , L_48 ,
V_7 -> V_33 ) ;
F_115 ( ! F_53 ( & V_7 -> V_8 ) ) ;
F_115 ( ! F_53 ( & V_7 -> V_10 ) ) ;
F_115 ( F_28 ( V_7 ) ) ;
F_13 (desc, _desc, &atchan->free_list, desc_node) {
F_19 ( F_17 ( V_12 ) , L_49 , V_14 ) ;
F_15 ( & V_14 -> V_9 ) ;
F_48 ( V_16 -> V_19 , V_14 , V_14 -> V_21 . V_18 ) ;
}
F_23 ( & V_7 -> V_35 , & V_73 ) ;
V_7 -> V_33 = 0 ;
V_7 -> V_77 = 0 ;
F_19 ( F_17 ( V_12 ) , L_50 ) ;
}
static bool F_119 ( struct V_11 * V_12 , void * V_188 )
{
struct V_134 * V_135 = V_188 ;
if ( V_135 -> V_184 == V_12 -> V_17 -> V_86 ) {
V_12 -> V_136 = V_135 ;
return true ;
} else {
return false ;
}
}
static struct V_11 * F_120 ( struct V_189 * V_190 ,
struct V_191 * V_191 )
{
struct V_11 * V_12 ;
struct V_6 * V_7 ;
struct V_134 * V_135 ;
T_9 V_51 ;
unsigned int V_192 ;
struct V_193 * V_194 ;
if ( V_190 -> V_195 != 2 )
return NULL ;
V_194 = F_121 ( V_190 -> V_196 ) ;
F_122 ( V_51 ) ;
F_123 ( V_197 , V_51 ) ;
V_135 = F_124 ( & V_194 -> V_86 , sizeof( * V_135 ) , V_186 ) ;
if ( ! V_135 )
return NULL ;
V_135 -> V_181 = V_198 | V_199 ;
V_192 = V_190 -> args [ 1 ] & V_200 ;
V_135 -> V_181 |= F_125 ( V_192 ) | F_126 ( V_192 )
| F_127 ( V_192 ) | F_128 ( V_192 ) ;
switch ( V_190 -> args [ 1 ] & V_201 ) {
case V_202 :
V_135 -> V_181 |= V_203 ;
break;
case V_204 :
V_135 -> V_181 |= V_205 ;
break;
case V_206 :
default:
V_135 -> V_181 |= V_207 ;
}
V_135 -> V_184 = & V_194 -> V_86 ;
V_12 = F_129 ( V_51 , F_119 , V_135 ) ;
if ( ! V_12 )
return NULL ;
V_7 = F_41 ( V_12 ) ;
V_7 -> V_150 = V_190 -> args [ 0 ] & 0xff ;
V_7 -> V_149 = ( V_190 -> args [ 0 ] >> 16 ) & 0xff ;
return V_12 ;
}
static struct V_11 * F_120 ( struct V_189 * V_190 ,
struct V_191 * V_191 )
{
return NULL ;
}
static inline const struct V_208 * T_10 F_130 (
struct V_193 * V_209 )
{
if ( V_209 -> V_86 . V_210 ) {
const struct V_211 * V_212 ;
V_212 = F_131 ( V_213 , V_209 -> V_86 . V_210 ) ;
if ( V_212 == NULL )
return NULL ;
return V_212 -> V_75 ;
}
return (struct V_208 * )
F_132 ( V_209 ) -> V_214 ;
}
static void F_133 ( struct V_15 * V_16 )
{
F_36 ( V_16 , V_215 , 0 ) ;
F_36 ( V_16 , V_216 , - 1L ) ;
while ( F_64 ( V_16 , V_174 ) & V_16 -> V_217 )
F_109 () ;
}
static int T_10 F_134 ( struct V_193 * V_209 )
{
struct V_218 * V_219 ;
struct V_15 * V_16 ;
T_2 V_105 ;
int V_78 ;
int V_153 ;
int V_28 ;
const struct V_208 * V_220 ;
F_123 ( V_221 , V_222 . V_223 ) ;
F_123 ( V_224 , V_222 . V_223 ) ;
F_123 ( V_225 , V_226 . V_223 ) ;
F_123 ( V_221 , V_226 . V_223 ) ;
F_123 ( V_227 , V_226 . V_223 ) ;
F_123 ( V_228 , V_226 . V_223 ) ;
F_123 ( V_229 , V_226 . V_223 ) ;
F_123 ( V_197 , V_226 . V_223 ) ;
F_123 ( V_224 , V_226 . V_223 ) ;
V_220 = F_130 ( V_209 ) ;
if ( ! V_220 )
return - V_230 ;
V_219 = F_135 ( V_209 , V_231 , 0 ) ;
if ( ! V_219 )
return - V_60 ;
V_78 = F_136 ( V_209 , 0 ) ;
if ( V_78 < 0 )
return V_78 ;
V_105 = sizeof( struct V_15 ) ;
V_105 += V_220 -> V_232 * sizeof( struct V_6 ) ;
V_16 = F_137 ( V_105 , V_186 ) ;
if ( ! V_16 )
return - V_233 ;
V_16 -> V_85 . V_223 = V_220 -> V_223 ;
V_16 -> V_217 = ( 1 << V_220 -> V_232 ) - 1 ;
V_105 = F_138 ( V_219 ) ;
if ( ! F_139 ( V_219 -> V_234 , V_105 , V_209 -> V_86 . V_235 -> V_236 ) ) {
V_153 = - V_115 ;
goto V_237;
}
V_16 -> V_238 = F_140 ( V_219 -> V_234 , V_105 ) ;
if ( ! V_16 -> V_238 ) {
V_153 = - V_233 ;
goto V_239;
}
V_16 -> V_240 = F_141 ( & V_209 -> V_86 , L_51 ) ;
if ( F_142 ( V_16 -> V_240 ) ) {
V_153 = F_143 ( V_16 -> V_240 ) ;
goto V_241;
}
V_153 = F_144 ( V_16 -> V_240 ) ;
if ( V_153 )
goto V_242;
F_133 ( V_16 ) ;
V_153 = F_145 ( V_78 , F_63 , 0 , L_52 , V_16 ) ;
if ( V_153 )
goto V_243;
F_146 ( V_209 , V_16 ) ;
V_16 -> V_19 = F_147 ( L_53 ,
& V_209 -> V_86 , sizeof( struct V_5 ) ,
4 , 0 ) ;
if ( ! V_16 -> V_19 ) {
F_20 ( & V_209 -> V_86 , L_54 ) ;
V_153 = - V_233 ;
goto V_244;
}
V_16 -> V_67 = F_147 ( L_55 ,
& V_209 -> V_86 , sizeof( int ) , 4 , 0 ) ;
if ( ! V_16 -> V_67 ) {
F_20 ( & V_209 -> V_86 , L_56 ) ;
V_153 = - V_233 ;
goto V_245;
}
while ( F_64 ( V_16 , V_84 ) )
F_109 () ;
F_8 ( & V_16 -> V_85 . V_246 ) ;
for ( V_28 = 0 ; V_28 < V_220 -> V_232 ; V_28 ++ ) {
struct V_6 * V_7 = & V_16 -> V_12 [ V_28 ] ;
V_7 -> V_149 = V_247 ;
V_7 -> V_150 = V_248 ;
V_7 -> V_31 . V_17 = & V_16 -> V_85 ;
F_117 ( & V_7 -> V_31 ) ;
F_26 ( & V_7 -> V_31 . V_249 ,
& V_16 -> V_85 . V_246 ) ;
V_7 -> V_250 = V_16 -> V_238 + V_250 ( V_28 ) ;
F_148 ( & V_7 -> V_30 ) ;
V_7 -> V_51 = 1 << V_28 ;
F_8 ( & V_7 -> V_8 ) ;
F_8 ( & V_7 -> V_10 ) ;
F_8 ( & V_7 -> V_35 ) ;
F_149 ( & V_7 -> V_89 , F_61 ,
( unsigned long ) V_7 ) ;
F_150 ( V_16 , V_28 ) ;
}
V_16 -> V_85 . V_251 = F_114 ;
V_16 -> V_85 . V_252 = F_118 ;
V_16 -> V_85 . V_253 = F_110 ;
V_16 -> V_85 . V_254 = F_113 ;
V_16 -> V_85 . V_86 = & V_209 -> V_86 ;
if ( F_151 ( V_225 , V_16 -> V_85 . V_223 ) )
V_16 -> V_85 . V_255 = F_72 ;
if ( F_151 ( V_221 , V_16 -> V_85 . V_223 ) )
V_16 -> V_85 . V_256 = F_79 ;
if ( F_151 ( V_227 , V_16 -> V_85 . V_223 ) ) {
V_16 -> V_85 . V_257 = F_82 ;
V_16 -> V_85 . V_258 = F_84 ;
V_16 -> V_85 . V_259 = V_260 ;
}
if ( F_151 ( V_197 , V_16 -> V_85 . V_223 ) ) {
V_16 -> V_85 . V_261 = F_88 ;
F_123 ( V_262 , V_16 -> V_85 . V_223 ) ;
V_16 -> V_85 . V_263 = F_98 ;
V_16 -> V_85 . V_264 = F_102 ;
V_16 -> V_85 . V_265 = F_104 ;
V_16 -> V_85 . V_266 = F_106 ;
V_16 -> V_85 . V_267 = F_108 ;
V_16 -> V_85 . V_268 = V_269 ;
V_16 -> V_85 . V_270 = V_269 ;
V_16 -> V_85 . V_271 = F_152 ( V_154 ) | F_152 ( V_143 ) ;
V_16 -> V_85 . V_272 = V_273 ;
}
if ( F_151 ( V_224 , V_16 -> V_85 . V_223 ) )
V_16 -> V_85 . V_274 = F_94 ;
F_36 ( V_16 , V_215 , V_275 ) ;
F_73 ( & V_209 -> V_86 , L_57 ,
F_151 ( V_221 , V_16 -> V_85 . V_223 ) ? L_58 : L_59 ,
F_151 ( V_227 , V_16 -> V_85 . V_223 ) ? L_60 : L_59 ,
F_151 ( V_197 , V_16 -> V_85 . V_223 ) ? L_61 : L_59 ,
F_151 ( V_224 , V_16 -> V_85 . V_223 ) ? L_62 : L_59 ,
V_220 -> V_232 ) ;
F_153 ( & V_16 -> V_85 ) ;
if ( V_209 -> V_86 . V_210 ) {
V_153 = F_154 ( V_209 -> V_86 . V_210 ,
F_120 , V_16 ) ;
if ( V_153 ) {
F_20 ( & V_209 -> V_86 , L_63 ) ;
goto V_276;
}
}
return 0 ;
V_276:
F_155 ( & V_16 -> V_85 ) ;
F_156 ( V_16 -> V_67 ) ;
V_245:
F_156 ( V_16 -> V_19 ) ;
V_244:
F_157 ( F_136 ( V_209 , 0 ) , V_16 ) ;
V_243:
F_158 ( V_16 -> V_240 ) ;
V_242:
F_159 ( V_16 -> V_240 ) ;
V_241:
F_160 ( V_16 -> V_238 ) ;
V_16 -> V_238 = NULL ;
V_239:
F_161 ( V_219 -> V_234 , V_105 ) ;
V_237:
F_162 ( V_16 ) ;
return V_153 ;
}
static int F_163 ( struct V_193 * V_209 )
{
struct V_15 * V_16 = F_164 ( V_209 ) ;
struct V_11 * V_12 , * V_277 ;
struct V_218 * V_219 ;
F_133 ( V_16 ) ;
F_155 ( & V_16 -> V_85 ) ;
F_156 ( V_16 -> V_67 ) ;
F_156 ( V_16 -> V_19 ) ;
F_157 ( F_136 ( V_209 , 0 ) , V_16 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_165 ( V_16 , V_12 -> V_172 ) ;
F_166 ( & V_7 -> V_89 ) ;
F_15 ( & V_12 -> V_249 ) ;
}
F_158 ( V_16 -> V_240 ) ;
F_159 ( V_16 -> V_240 ) ;
F_160 ( V_16 -> V_238 ) ;
V_16 -> V_238 = NULL ;
V_219 = F_135 ( V_209 , V_231 , 0 ) ;
F_161 ( V_219 -> V_234 , F_138 ( V_219 ) ) ;
F_162 ( V_16 ) ;
return 0 ;
}
static void F_167 ( struct V_193 * V_209 )
{
struct V_15 * V_16 = F_164 ( V_209 ) ;
F_133 ( F_164 ( V_209 ) ) ;
F_158 ( V_16 -> V_240 ) ;
}
static int F_168 ( struct V_17 * V_86 )
{
struct V_193 * V_209 = F_169 ( V_86 ) ;
struct V_15 * V_16 = F_164 ( V_209 ) ;
struct V_11 * V_12 , * V_277 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
if ( F_28 ( V_7 ) && ! F_46 ( V_7 ) )
return - V_278 ;
}
return 0 ;
}
static void F_170 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = & V_7 -> V_31 ;
if ( ! F_107 ( V_7 ) ) {
F_171 ( F_17 ( V_12 ) ,
L_64 ) ;
F_104 ( V_12 ) ;
}
V_7 -> V_279 = F_29 ( V_7 , V_44 ) ;
F_30 ( V_7 ) ;
}
static int F_172 ( struct V_17 * V_86 )
{
struct V_193 * V_209 = F_169 ( V_86 ) ;
struct V_15 * V_16 = F_164 ( V_209 ) ;
struct V_11 * V_12 , * V_277 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
if ( F_46 ( V_7 ) )
F_170 ( V_7 ) ;
V_7 -> V_280 = F_29 ( V_7 , V_187 ) ;
}
V_16 -> V_281 = F_64 ( V_16 , V_83 ) ;
F_133 ( V_16 ) ;
F_158 ( V_16 -> V_240 ) ;
return 0 ;
}
static void F_173 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = F_6 ( V_7 -> V_31 . V_17 ) ;
F_31 ( V_7 , V_40 , 0 ) ;
F_31 ( V_7 , V_41 , 0 ) ;
F_31 ( V_7 , V_42 , 0 ) ;
F_31 ( V_7 , V_43 , 0 ) ;
F_31 ( V_7 , V_44 , V_7 -> V_279 ) ;
F_36 ( V_16 , V_50 , V_7 -> V_51 ) ;
F_30 ( V_7 ) ;
}
static int F_174 ( struct V_17 * V_86 )
{
struct V_193 * V_209 = F_169 ( V_86 ) ;
struct V_15 * V_16 = F_164 ( V_209 ) ;
struct V_11 * V_12 , * V_277 ;
F_144 ( V_16 -> V_240 ) ;
F_36 ( V_16 , V_215 , V_275 ) ;
while ( F_64 ( V_16 , V_84 ) )
F_109 () ;
F_36 ( V_16 , V_282 , V_16 -> V_281 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_41 ( V_12 ) ;
F_31 ( V_7 , V_187 , V_7 -> V_280 ) ;
if ( F_46 ( V_7 ) )
F_173 ( V_7 ) ;
}
return 0 ;
}
static int T_10 F_175 ( void )
{
return F_176 ( & V_283 , F_134 ) ;
}
static void T_11 F_177 ( void )
{
F_178 ( & V_283 ) ;
}
