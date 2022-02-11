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
F_32 ( V_16 , V_45 , V_7 -> V_46 ) ;
F_30 ( V_7 ) ;
}
static struct V_5 * F_33 ( struct V_6 * V_7 ,
T_4 V_47 )
{
struct V_5 * V_14 , * V_26 ;
F_13 (desc, _desc, &atchan->queue, desc_node) {
if ( V_14 -> V_21 . V_47 == V_47 )
return V_14 ;
}
F_13 (desc, _desc, &atchan->active_list, desc_node) {
if ( V_14 -> V_21 . V_47 == V_47 )
return V_14 ;
}
return NULL ;
}
static inline int F_34 ( int V_48 , T_5 V_49 ,
struct V_5 * V_14 )
{
return V_48 - ( ( V_49 & V_50 ) << V_14 -> V_51 ) ;
}
static inline int F_35 ( int V_48 ,
struct V_6 * V_7 , struct V_5 * V_14 )
{
T_5 V_49 = F_29 ( V_7 , V_42 ) ;
return F_34 ( V_48 , V_49 , V_14 ) ;
}
static int F_36 ( struct V_11 * V_12 , T_4 V_47 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
struct V_5 * V_52 = F_2 ( V_7 ) ;
struct V_5 * V_14 ;
int V_27 ;
T_5 V_49 , V_39 ;
V_14 = F_33 ( V_7 , V_47 ) ;
if ( V_14 == NULL )
return - V_53 ;
else if ( V_14 != V_52 )
return V_14 -> V_54 ;
V_27 = V_52 -> V_54 ;
if ( V_52 -> V_38 . V_39 ) {
V_49 = F_29 ( V_7 , V_42 ) ;
F_38 () ;
V_39 = F_29 ( V_7 , V_44 ) ;
if ( V_52 -> V_38 . V_39 == V_39 )
return F_34 ( V_27 , V_49 , V_52 ) ;
V_27 -= V_52 -> V_3 ;
F_22 (desc, &desc_first->tx_list, desc_node) {
if ( V_14 -> V_38 . V_39 == V_39 )
break;
V_27 -= V_14 -> V_3 ;
}
if ( ! V_14 -> V_38 . V_39 )
V_27 = F_35 ( V_27 , V_7 , V_14 ) ;
} else {
V_27 = F_35 ( V_27 , V_7 , V_52 ) ;
}
return V_27 ;
}
static void
F_39 ( struct V_6 * V_7 , struct V_5 * V_14 )
{
struct V_55 * V_21 = & V_14 -> V_21 ;
F_19 ( F_17 ( & V_7 -> V_31 ) ,
L_8 , V_21 -> V_47 ) ;
if ( ! F_40 ( V_7 ) )
F_41 ( V_21 ) ;
F_23 ( & V_14 -> V_20 , & V_7 -> V_35 ) ;
F_42 ( & V_14 -> V_9 , & V_7 -> V_35 ) ;
F_43 ( V_21 ) ;
if ( ! F_40 ( V_7 ) ) {
T_6 V_56 = V_21 -> V_56 ;
void * V_57 = V_21 -> V_58 ;
if ( V_56 )
V_56 ( V_57 ) ;
}
F_44 ( V_21 ) ;
}
static void F_45 ( struct V_6 * V_7 )
{
struct V_5 * V_14 , * V_26 ;
F_11 ( V_59 ) ;
F_19 ( F_17 ( & V_7 -> V_31 ) , L_9 ) ;
if ( ! F_46 ( & V_7 -> V_10 ) )
F_27 ( V_7 , F_4 ( V_7 ) ) ;
F_23 ( & V_7 -> V_8 , & V_59 ) ;
F_23 ( & V_7 -> V_10 , & V_7 -> V_8 ) ;
F_13 (desc, _desc, &list, desc_node)
F_39 ( V_7 , V_14 ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
F_19 ( F_17 ( & V_7 -> V_31 ) , L_10 ) ;
if ( F_28 ( V_7 ) )
return;
if ( F_46 ( & V_7 -> V_8 ) ||
F_48 ( & V_7 -> V_8 ) ) {
F_45 ( V_7 ) ;
} else {
F_39 ( V_7 , F_2 ( V_7 ) ) ;
F_27 ( V_7 , F_2 ( V_7 ) ) ;
}
}
static void F_49 ( struct V_6 * V_7 )
{
struct V_5 * V_60 ;
struct V_5 * V_34 ;
V_60 = F_2 ( V_7 ) ;
F_50 ( & V_60 -> V_9 ) ;
F_23 ( & V_7 -> V_10 , V_7 -> V_8 . V_37 ) ;
if ( ! F_46 ( & V_7 -> V_8 ) )
F_27 ( V_7 , F_2 ( V_7 ) ) ;
F_51 ( F_17 ( & V_7 -> V_31 ) ,
L_11 ) ;
F_51 ( F_17 ( & V_7 -> V_31 ) ,
L_12 , V_60 -> V_21 . V_47 ) ;
F_52 ( V_7 , & V_60 -> V_38 ) ;
F_22 (child, &bad_desc->tx_list, desc_node)
F_52 ( V_7 , & V_34 -> V_38 ) ;
F_39 ( V_7 , V_60 ) ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_5 * V_36 = F_2 ( V_7 ) ;
struct V_55 * V_21 = & V_36 -> V_21 ;
T_6 V_56 = V_21 -> V_56 ;
void * V_57 = V_21 -> V_58 ;
F_19 ( F_17 ( & V_7 -> V_31 ) ,
L_13 ,
F_29 ( V_7 , V_44 ) ) ;
if ( V_56 )
V_56 ( V_57 ) ;
}
static void F_54 ( unsigned long V_61 )
{
struct V_6 * V_7 = (struct V_6 * ) V_61 ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
if ( F_55 ( V_62 , & V_7 -> V_63 ) )
F_49 ( V_7 ) ;
else if ( F_40 ( V_7 ) )
F_53 ( V_7 ) ;
else
F_47 ( V_7 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
}
static T_7 F_56 ( int V_64 , void * V_65 )
{
struct V_15 * V_16 = (struct V_15 * ) V_65 ;
struct V_6 * V_7 ;
int V_28 ;
T_5 V_63 , V_66 , V_67 ;
int V_27 = V_68 ;
do {
V_67 = F_57 ( V_16 , V_69 ) ;
V_63 = F_57 ( V_16 , V_70 ) ;
V_66 = V_63 & V_67 ;
if ( ! V_66 )
break;
F_19 ( V_16 -> V_71 . V_72 ,
L_14 ,
V_63 , V_67 , V_66 ) ;
for ( V_28 = 0 ; V_28 < V_16 -> V_71 . V_73 ; V_28 ++ ) {
V_7 = & V_16 -> V_12 [ V_28 ] ;
if ( V_66 & ( F_58 ( V_28 ) | F_59 ( V_28 ) ) ) {
if ( V_66 & F_59 ( V_28 ) ) {
F_32 ( V_16 , V_74 ,
F_60 ( V_28 ) | V_7 -> V_46 ) ;
F_61 ( V_62 , & V_7 -> V_63 ) ;
}
F_62 ( & V_7 -> V_75 ) ;
V_27 = V_76 ;
}
}
} while ( V_66 );
return V_27 ;
}
static T_4 V_25 ( struct V_55 * V_77 )
{
struct V_5 * V_14 = F_63 ( V_77 ) ;
struct V_6 * V_7 = F_37 ( V_77 -> V_12 ) ;
T_4 V_47 ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_47 = F_64 ( V_77 ) ;
if ( F_46 ( & V_7 -> V_8 ) ) {
F_19 ( F_17 ( V_77 -> V_12 ) , L_15 ,
V_14 -> V_21 . V_47 ) ;
F_27 ( V_7 , V_14 ) ;
F_26 ( & V_14 -> V_9 , & V_7 -> V_8 ) ;
} else {
F_19 ( F_17 ( V_77 -> V_12 ) , L_16 ,
V_14 -> V_21 . V_47 ) ;
F_26 ( & V_14 -> V_9 , & V_7 -> V_10 ) ;
}
F_18 ( & V_7 -> V_30 , V_22 ) ;
return V_47 ;
}
static struct V_55 *
F_65 ( struct V_11 * V_12 , T_1 V_78 , T_1 V_1 ,
T_2 V_3 , unsigned long V_22 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
struct V_5 * V_14 = NULL ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
T_2 V_79 ;
T_2 V_80 ;
unsigned int V_81 ;
unsigned int V_82 ;
T_5 V_49 ;
T_5 V_83 ;
F_19 ( F_17 ( V_12 ) , L_17 ,
V_78 , V_1 , V_3 , V_22 ) ;
if ( F_66 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) , L_18 ) ;
return NULL ;
}
V_83 = V_84 | V_85
| V_86
| V_87
| V_88 ;
V_81 = V_82 = F_1 ( V_1 , V_78 , V_3 ) ;
V_49 = F_67 ( V_81 ) |
F_68 ( V_82 ) ;
for ( V_80 = 0 ; V_80 < V_3 ; V_80 += V_79 << V_81 ) {
V_79 = F_69 ( T_2 , ( V_3 - V_80 ) >> V_81 ,
V_50 ) ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_89;
V_14 -> V_38 . V_90 = V_1 + V_80 ;
V_14 -> V_38 . V_91 = V_78 + V_80 ;
V_14 -> V_38 . V_49 = V_49 | V_79 ;
V_14 -> V_38 . V_83 = V_83 ;
V_14 -> V_21 . V_47 = 0 ;
V_14 -> V_3 = V_79 << V_81 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
}
V_36 -> V_21 . V_47 = - V_92 ;
V_36 -> V_54 = V_3 ;
V_36 -> V_51 = V_81 ;
V_37 -> V_51 = V_81 ;
F_70 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_89:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_55 *
F_71 ( struct V_11 * V_12 , struct V_93 * V_94 ,
unsigned int V_95 , enum V_96 V_97 ,
unsigned long V_22 , void * V_98 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
struct V_99 * V_100 = V_12 -> V_101 ;
struct V_102 * V_103 = & V_7 -> V_104 ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
T_5 V_49 ;
T_5 V_83 ;
T_1 V_105 ;
unsigned int V_106 ;
unsigned int V_107 ;
unsigned int V_28 ;
struct V_93 * V_108 ;
T_2 V_54 = 0 ;
F_19 ( F_17 ( V_12 ) , L_19 ,
V_95 ,
V_97 == V_109 ? L_20 : L_21 ,
V_22 ) ;
if ( F_66 ( ! V_100 || ! V_95 ) ) {
F_16 ( F_17 ( V_12 ) , L_22 ) ;
return NULL ;
}
V_49 = F_72 ( V_103 -> V_110 )
| F_73 ( V_103 -> V_111 ) ;
V_83 = V_85 ;
switch ( V_97 ) {
case V_109 :
V_106 = F_74 ( V_103 -> V_112 ) ;
V_49 |= F_68 ( V_106 ) ;
V_83 |= V_113
| V_86
| V_114
| F_75 ( V_7 -> V_115 ) | F_76 ( V_7 -> V_116 ) ;
V_105 = V_103 -> V_117 ;
F_77 (sgl, sg, sg_len, i) {
struct V_5 * V_14 ;
T_5 V_3 ;
T_5 V_118 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_89;
V_118 = F_78 ( V_108 ) ;
V_3 = F_79 ( V_108 ) ;
if ( F_66 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) ,
L_23 , V_28 ) ;
goto V_119;
}
V_107 = 2 ;
if ( F_66 ( V_118 & 3 || V_3 & 3 ) )
V_107 = 0 ;
V_14 -> V_38 . V_90 = V_118 ;
V_14 -> V_38 . V_91 = V_105 ;
V_14 -> V_38 . V_49 = V_49
| F_67 ( V_107 )
| V_3 >> V_107 ;
V_14 -> V_38 . V_83 = V_83 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_54 += V_3 ;
}
break;
case V_120 :
V_106 = F_74 ( V_103 -> V_121 ) ;
V_49 |= F_67 ( V_106 ) ;
V_83 |= V_87
| V_122
| V_123
| F_75 ( V_7 -> V_116 ) | F_76 ( V_7 -> V_115 ) ;
V_105 = V_103 -> V_124 ;
F_77 (sgl, sg, sg_len, i) {
struct V_5 * V_14 ;
T_5 V_3 ;
T_5 V_118 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_89;
V_118 = F_78 ( V_108 ) ;
V_3 = F_79 ( V_108 ) ;
if ( F_66 ( ! V_3 ) ) {
F_16 ( F_17 ( V_12 ) ,
L_23 , V_28 ) ;
goto V_119;
}
V_107 = 2 ;
if ( F_66 ( V_118 & 3 || V_3 & 3 ) )
V_107 = 0 ;
V_14 -> V_38 . V_90 = V_105 ;
V_14 -> V_38 . V_91 = V_118 ;
V_14 -> V_38 . V_49 = V_49
| F_68 ( V_107 )
| V_3 >> V_106 ;
V_14 -> V_38 . V_83 = V_83 ;
V_14 -> V_3 = V_3 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_54 += V_3 ;
}
break;
default:
return NULL ;
}
F_70 ( V_37 ) ;
V_36 -> V_21 . V_47 = - V_92 ;
V_36 -> V_54 = V_54 ;
V_36 -> V_51 = V_106 ;
V_37 -> V_51 = V_106 ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_89:
F_20 ( F_17 ( V_12 ) , L_3 ) ;
V_119:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static struct V_55 *
F_80 ( struct V_11 * V_12 ,
struct V_93 * V_125 , unsigned int V_126 ,
struct V_93 * V_127 , unsigned int V_128 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
struct V_5 * V_14 = NULL ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
unsigned int V_81 ;
unsigned int V_82 ;
T_2 V_79 ;
T_5 V_49 ;
T_5 V_83 ;
T_2 V_129 = 0 , V_130 = 0 ;
T_1 V_2 = 0 , V_1 = 0 ;
T_2 V_3 = 0 , V_54 = 0 ;
if ( F_66 ( V_126 == 0 || V_128 == 0 ) )
return NULL ;
if ( F_66 ( V_125 == NULL || V_127 == NULL ) )
return NULL ;
V_83 = V_84 | V_85
| V_86
| V_87
| V_88 ;
while ( true ) {
if ( V_129 == 0 ) {
if ( ! V_125 || ! V_126 )
break;
V_2 = F_78 ( V_125 ) ;
V_129 = F_79 ( V_125 ) ;
V_125 = F_81 ( V_125 ) ;
V_126 -- ;
}
if ( V_130 == 0 ) {
if ( ! V_127 || ! V_128 )
break;
V_1 = F_78 ( V_127 ) ;
V_130 = F_79 ( V_127 ) ;
V_127 = F_81 ( V_127 ) ;
V_128 -- ;
}
V_3 = F_69 ( T_2 , V_130 , V_129 ) ;
if ( V_3 == 0 )
continue;
V_81 = V_82 = F_1 ( V_1 , V_2 , V_3 ) ;
V_49 = F_67 ( V_81 ) |
F_68 ( V_82 ) ;
V_79 = V_3 >> V_81 ;
if ( V_79 > V_50 ) {
V_79 = V_50 ;
V_3 = V_50 << V_81 ;
}
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_89;
V_14 -> V_38 . V_90 = V_1 ;
V_14 -> V_38 . V_91 = V_2 ;
V_14 -> V_38 . V_49 = V_49 | V_79 ;
V_14 -> V_38 . V_83 = V_83 ;
V_14 -> V_21 . V_47 = 0 ;
V_14 -> V_3 = V_3 ;
V_14 -> V_51 = V_81 ;
F_25 ( & V_36 , & V_37 , V_14 ) ;
V_129 -= V_3 ;
V_130 -= V_3 ;
V_2 += V_3 ;
V_1 += V_3 ;
V_54 += V_3 ;
}
V_36 -> V_21 . V_47 = - V_92 ;
V_36 -> V_54 = V_54 ;
F_70 ( V_14 ) ;
V_36 -> V_21 . V_22 = V_22 ;
return & V_36 -> V_21 ;
V_89:
F_21 ( V_7 , V_36 ) ;
return NULL ;
}
static int
F_82 ( unsigned int V_106 , T_1 V_131 ,
T_2 V_132 )
{
if ( V_132 > ( V_50 << V_106 ) )
goto V_133;
if ( F_66 ( V_132 & ( ( 1 << V_106 ) - 1 ) ) )
goto V_133;
if ( F_66 ( V_131 & ( ( 1 << V_106 ) - 1 ) ) )
goto V_133;
return 0 ;
V_133:
return - V_53 ;
}
static int
F_83 ( struct V_11 * V_12 , struct V_5 * V_14 ,
unsigned int V_134 , T_1 V_131 ,
unsigned int V_106 , T_2 V_132 ,
enum V_96 V_97 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
struct V_102 * V_103 = & V_7 -> V_104 ;
T_5 V_49 ;
V_49 = F_72 ( V_103 -> V_110 )
| F_73 ( V_103 -> V_111 )
| F_68 ( V_106 )
| F_67 ( V_106 )
| V_132 >> V_106 ;
switch ( V_97 ) {
case V_109 :
V_14 -> V_38 . V_90 = V_131 + ( V_132 * V_134 ) ;
V_14 -> V_38 . V_91 = V_103 -> V_117 ;
V_14 -> V_38 . V_49 = V_49 ;
V_14 -> V_38 . V_83 = V_113
| V_86
| V_114
| F_75 ( V_7 -> V_115 )
| F_76 ( V_7 -> V_116 ) ;
V_14 -> V_3 = V_132 ;
break;
case V_120 :
V_14 -> V_38 . V_90 = V_103 -> V_124 ;
V_14 -> V_38 . V_91 = V_131 + ( V_132 * V_134 ) ;
V_14 -> V_38 . V_49 = V_49 ;
V_14 -> V_38 . V_83 = V_87
| V_122
| V_123
| F_75 ( V_7 -> V_116 )
| F_76 ( V_7 -> V_115 ) ;
V_14 -> V_3 = V_132 ;
break;
default:
return - V_53 ;
}
return 0 ;
}
static struct V_55 *
F_84 ( struct V_11 * V_12 , T_1 V_131 , T_2 V_135 ,
T_2 V_132 , enum V_96 V_97 ,
unsigned long V_22 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
struct V_99 * V_100 = V_12 -> V_101 ;
struct V_102 * V_103 = & V_7 -> V_104 ;
struct V_5 * V_36 = NULL ;
struct V_5 * V_37 = NULL ;
unsigned long V_136 ;
unsigned int V_106 ;
unsigned int V_137 = V_135 / V_132 ;
unsigned int V_28 ;
F_19 ( F_17 ( V_12 ) , L_24 ,
V_97 == V_109 ? L_20 : L_21 ,
V_131 ,
V_137 , V_135 , V_132 ) ;
if ( F_66 ( ! V_100 || ! V_135 || ! V_132 ) ) {
F_16 ( F_17 ( V_12 ) , L_25 ) ;
return NULL ;
}
V_136 = F_85 ( V_138 , & V_7 -> V_63 ) ;
if ( V_136 ) {
F_16 ( F_17 ( V_12 ) , L_26 ) ;
return NULL ;
}
if ( F_66 ( ! F_86 ( V_97 ) ) )
goto V_133;
if ( V_103 -> V_97 == V_109 )
V_106 = F_74 ( V_103 -> V_112 ) ;
else
V_106 = F_74 ( V_103 -> V_121 ) ;
if ( F_82 ( V_106 , V_131 , V_132 ) )
goto V_133;
for ( V_28 = 0 ; V_28 < V_137 ; V_28 ++ ) {
struct V_5 * V_14 ;
V_14 = F_10 ( V_7 ) ;
if ( ! V_14 )
goto V_89;
if ( F_83 ( V_12 , V_14 , V_28 , V_131 ,
V_106 , V_132 , V_97 ) )
goto V_89;
F_25 ( & V_36 , & V_37 , V_14 ) ;
}
V_37 -> V_38 . V_39 = V_36 -> V_21 . V_18 ;
V_36 -> V_21 . V_47 = - V_92 ;
V_36 -> V_54 = V_135 ;
V_36 -> V_51 = V_106 ;
return & V_36 -> V_21 ;
V_89:
F_20 ( F_17 ( V_12 ) , L_3 ) ;
F_21 ( V_7 , V_36 ) ;
V_133:
F_87 ( V_138 , & V_7 -> V_63 ) ;
return NULL ;
}
static int F_88 ( struct V_11 * V_12 ,
struct V_102 * V_103 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
F_19 ( F_17 ( V_12 ) , L_27 , V_139 ) ;
if ( ! V_12 -> V_101 )
return - V_53 ;
memcpy ( & V_7 -> V_104 , V_103 , sizeof( * V_103 ) ) ;
F_89 ( & V_7 -> V_104 . V_110 ) ;
F_89 ( & V_7 -> V_104 . V_111 ) ;
return 0 ;
}
static int F_90 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_140 = V_7 -> V_31 . V_140 ;
unsigned long V_22 ;
F_11 ( V_59 ) ;
F_19 ( F_17 ( V_12 ) , L_27 , V_139 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_32 ( V_16 , V_45 , F_91 ( V_140 ) ) ;
F_61 ( V_141 , & V_7 -> V_63 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_92 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_140 = V_7 -> V_31 . V_140 ;
unsigned long V_22 ;
F_11 ( V_59 ) ;
F_19 ( F_17 ( V_12 ) , L_27 , V_139 ) ;
if ( ! F_93 ( V_7 ) )
return 0 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_32 ( V_16 , V_74 , F_60 ( V_140 ) ) ;
F_87 ( V_141 , & V_7 -> V_63 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static int F_94 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
int V_140 = V_7 -> V_31 . V_140 ;
struct V_5 * V_14 , * V_26 ;
unsigned long V_22 ;
F_11 ( V_59 ) ;
F_19 ( F_17 ( V_12 ) , L_27 , V_139 ) ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_32 ( V_16 , V_74 , F_60 ( V_140 ) | V_7 -> V_46 ) ;
while ( F_57 ( V_16 , V_142 ) & V_7 -> V_46 )
F_95 () ;
F_23 ( & V_7 -> V_10 , & V_59 ) ;
F_23 ( & V_7 -> V_8 , & V_59 ) ;
F_13 (desc, _desc, &list, desc_node)
F_39 ( V_7 , V_14 ) ;
F_87 ( V_141 , & V_7 -> V_63 ) ;
F_87 ( V_138 , & V_7 -> V_63 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
return 0 ;
}
static enum V_143
F_96 ( struct V_11 * V_12 ,
T_4 V_47 ,
struct V_144 * V_145 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
unsigned long V_22 ;
enum V_143 V_27 ;
int V_146 = 0 ;
V_27 = F_97 ( V_12 , V_47 , V_145 ) ;
if ( V_27 == V_147 )
return V_27 ;
if ( ! V_145 )
return V_148 ;
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_146 = F_36 ( V_12 , V_47 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
if ( F_66 ( V_146 < 0 ) ) {
F_19 ( F_17 ( V_12 ) , L_28 ) ;
return V_148 ;
} else {
F_98 ( V_145 , V_146 ) ;
}
F_19 ( F_17 ( V_12 ) , L_29 ,
V_27 , V_47 , V_146 ) ;
return V_27 ;
}
static void F_99 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
unsigned long V_22 ;
F_19 ( F_17 ( V_12 ) , L_30 ) ;
if ( F_40 ( V_7 ) )
return;
F_12 ( & V_7 -> V_30 , V_22 ) ;
F_47 ( V_7 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
}
static int F_100 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 ;
struct V_99 * V_100 ;
unsigned long V_22 ;
int V_28 ;
T_5 V_149 ;
F_11 ( V_29 ) ;
F_19 ( F_17 ( V_12 ) , L_31 ) ;
if ( F_28 ( V_7 ) ) {
F_16 ( F_17 ( V_12 ) , L_32 ) ;
return - V_150 ;
}
V_149 = V_151 ;
V_100 = V_12 -> V_101 ;
if ( V_100 ) {
F_101 ( ! V_100 -> V_152 || V_100 -> V_152 != V_16 -> V_71 . V_72 ) ;
if ( V_100 -> V_149 )
V_149 = V_100 -> V_149 ;
}
if ( ! F_46 ( & V_7 -> V_35 ) )
return V_7 -> V_33 ;
for ( V_28 = 0 ; V_28 < V_153 ; V_28 ++ ) {
V_14 = F_5 ( V_12 , V_154 ) ;
if ( ! V_14 ) {
F_20 ( V_16 -> V_71 . V_72 ,
L_33 , V_28 ) ;
break;
}
F_26 ( & V_14 -> V_9 , & V_29 ) ;
}
F_12 ( & V_7 -> V_30 , V_22 ) ;
V_7 -> V_33 = V_28 ;
F_102 ( & V_29 , & V_7 -> V_35 ) ;
F_103 ( V_12 ) ;
F_18 ( & V_7 -> V_30 , V_22 ) ;
F_31 ( V_7 , V_155 , V_149 ) ;
F_16 ( F_17 ( V_12 ) ,
L_34 ,
V_7 -> V_33 ) ;
return V_7 -> V_33 ;
}
static void F_104 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_37 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 -> V_17 ) ;
struct V_5 * V_14 , * V_26 ;
F_11 ( V_59 ) ;
F_16 ( F_17 ( V_12 ) , L_35 ,
V_7 -> V_33 ) ;
F_101 ( ! F_46 ( & V_7 -> V_8 ) ) ;
F_101 ( ! F_46 ( & V_7 -> V_10 ) ) ;
F_101 ( F_28 ( V_7 ) ) ;
F_13 (desc, _desc, &atchan->free_list, desc_node) {
F_19 ( F_17 ( V_12 ) , L_36 , V_14 ) ;
F_15 ( & V_14 -> V_9 ) ;
F_105 ( V_16 -> V_19 , V_14 , V_14 -> V_21 . V_18 ) ;
}
F_23 ( & V_7 -> V_35 , & V_59 ) ;
V_7 -> V_33 = 0 ;
V_7 -> V_63 = 0 ;
F_19 ( F_17 ( V_12 ) , L_37 ) ;
}
static bool F_106 ( struct V_11 * V_12 , void * V_156 )
{
struct V_99 * V_100 = V_156 ;
if ( V_100 -> V_152 == V_12 -> V_17 -> V_72 ) {
V_12 -> V_101 = V_100 ;
return true ;
} else {
return false ;
}
}
static struct V_11 * F_107 ( struct V_157 * V_158 ,
struct V_159 * V_159 )
{
struct V_11 * V_12 ;
struct V_6 * V_7 ;
struct V_99 * V_100 ;
T_8 V_46 ;
unsigned int V_160 ;
struct V_161 * V_162 ;
if ( V_158 -> V_163 != 2 )
return NULL ;
V_162 = F_108 ( V_158 -> V_164 ) ;
F_109 ( V_46 ) ;
F_110 ( V_165 , V_46 ) ;
V_100 = F_111 ( & V_162 -> V_72 , sizeof( * V_100 ) , V_154 ) ;
if ( ! V_100 )
return NULL ;
V_100 -> V_149 = V_166 | V_167 ;
V_160 = V_158 -> args [ 1 ] & V_168 ;
V_100 -> V_149 |= F_112 ( V_160 ) | F_113 ( V_160 )
| F_114 ( V_160 ) | F_115 ( V_160 ) ;
switch ( V_158 -> args [ 1 ] & V_169 ) {
case V_170 :
V_100 -> V_149 |= V_171 ;
break;
case V_172 :
V_100 -> V_149 |= V_173 ;
break;
case V_174 :
default:
V_100 -> V_149 |= V_175 ;
}
V_100 -> V_152 = & V_162 -> V_72 ;
V_12 = F_116 ( V_46 , F_106 , V_100 ) ;
if ( ! V_12 )
return NULL ;
V_7 = F_37 ( V_12 ) ;
V_7 -> V_116 = V_158 -> args [ 0 ] & 0xff ;
V_7 -> V_115 = ( V_158 -> args [ 0 ] >> 16 ) & 0xff ;
return V_12 ;
}
static struct V_11 * F_107 ( struct V_157 * V_158 ,
struct V_159 * V_159 )
{
return NULL ;
}
static inline const struct V_176 * T_9 F_117 (
struct V_161 * V_177 )
{
if ( V_177 -> V_72 . V_178 ) {
const struct V_179 * V_180 ;
V_180 = F_118 ( V_181 , V_177 -> V_72 . V_178 ) ;
if ( V_180 == NULL )
return NULL ;
return V_180 -> V_61 ;
}
return (struct V_176 * )
F_119 ( V_177 ) -> V_182 ;
}
static void F_120 ( struct V_15 * V_16 )
{
F_32 ( V_16 , V_183 , 0 ) ;
F_32 ( V_16 , V_184 , - 1L ) ;
while ( F_57 ( V_16 , V_142 ) & V_16 -> V_185 )
F_95 () ;
}
static int T_9 F_121 ( struct V_161 * V_177 )
{
struct V_186 * V_187 ;
struct V_15 * V_16 ;
T_2 V_188 ;
int V_64 ;
int V_119 ;
int V_28 ;
const struct V_176 * V_189 ;
F_110 ( V_190 , V_191 . V_192 ) ;
F_110 ( V_193 , V_191 . V_192 ) ;
F_110 ( V_190 , V_194 . V_192 ) ;
F_110 ( V_165 , V_194 . V_192 ) ;
F_110 ( V_193 , V_194 . V_192 ) ;
V_189 = F_117 ( V_177 ) ;
if ( ! V_189 )
return - V_195 ;
V_187 = F_122 ( V_177 , V_196 , 0 ) ;
if ( ! V_187 )
return - V_53 ;
V_64 = F_123 ( V_177 , 0 ) ;
if ( V_64 < 0 )
return V_64 ;
V_188 = sizeof( struct V_15 ) ;
V_188 += V_189 -> V_197 * sizeof( struct V_6 ) ;
V_16 = F_124 ( V_188 , V_154 ) ;
if ( ! V_16 )
return - V_198 ;
V_16 -> V_71 . V_192 = V_189 -> V_192 ;
V_16 -> V_185 = ( 1 << V_189 -> V_197 ) - 1 ;
V_188 = F_125 ( V_187 ) ;
if ( ! F_126 ( V_187 -> V_199 , V_188 , V_177 -> V_72 . V_200 -> V_201 ) ) {
V_119 = - V_92 ;
goto V_202;
}
V_16 -> V_203 = F_127 ( V_187 -> V_199 , V_188 ) ;
if ( ! V_16 -> V_203 ) {
V_119 = - V_198 ;
goto V_204;
}
V_16 -> V_205 = F_128 ( & V_177 -> V_72 , L_38 ) ;
if ( F_129 ( V_16 -> V_205 ) ) {
V_119 = F_130 ( V_16 -> V_205 ) ;
goto V_206;
}
V_119 = F_131 ( V_16 -> V_205 ) ;
if ( V_119 )
goto V_207;
F_120 ( V_16 ) ;
V_119 = F_132 ( V_64 , F_56 , 0 , L_39 , V_16 ) ;
if ( V_119 )
goto V_208;
F_133 ( V_177 , V_16 ) ;
V_16 -> V_19 = F_134 ( L_40 ,
& V_177 -> V_72 , sizeof( struct V_5 ) ,
4 , 0 ) ;
if ( ! V_16 -> V_19 ) {
F_20 ( & V_177 -> V_72 , L_41 ) ;
V_119 = - V_198 ;
goto V_209;
}
while ( F_57 ( V_16 , V_70 ) )
F_95 () ;
F_8 ( & V_16 -> V_71 . V_210 ) ;
for ( V_28 = 0 ; V_28 < V_189 -> V_197 ; V_28 ++ ) {
struct V_6 * V_7 = & V_16 -> V_12 [ V_28 ] ;
V_7 -> V_115 = V_211 ;
V_7 -> V_116 = V_212 ;
V_7 -> V_31 . V_17 = & V_16 -> V_71 ;
F_103 ( & V_7 -> V_31 ) ;
F_26 ( & V_7 -> V_31 . V_213 ,
& V_16 -> V_71 . V_210 ) ;
V_7 -> V_214 = V_16 -> V_203 + V_214 ( V_28 ) ;
F_135 ( & V_7 -> V_30 ) ;
V_7 -> V_46 = 1 << V_28 ;
F_8 ( & V_7 -> V_8 ) ;
F_8 ( & V_7 -> V_10 ) ;
F_8 ( & V_7 -> V_35 ) ;
F_136 ( & V_7 -> V_75 , F_54 ,
( unsigned long ) V_7 ) ;
F_137 ( V_16 , V_28 ) ;
}
V_16 -> V_71 . V_215 = F_100 ;
V_16 -> V_71 . V_216 = F_104 ;
V_16 -> V_71 . V_217 = F_96 ;
V_16 -> V_71 . V_218 = F_99 ;
V_16 -> V_71 . V_72 = & V_177 -> V_72 ;
if ( F_138 ( V_190 , V_16 -> V_71 . V_192 ) )
V_16 -> V_71 . V_219 = F_65 ;
if ( F_138 ( V_165 , V_16 -> V_71 . V_192 ) ) {
V_16 -> V_71 . V_220 = F_71 ;
F_110 ( V_221 , V_16 -> V_71 . V_192 ) ;
V_16 -> V_71 . V_222 = F_84 ;
V_16 -> V_71 . V_223 = F_88 ;
V_16 -> V_71 . V_224 = F_90 ;
V_16 -> V_71 . V_225 = F_92 ;
V_16 -> V_71 . V_226 = F_94 ;
V_16 -> V_71 . V_227 = V_228 ;
V_16 -> V_71 . V_229 = V_228 ;
V_16 -> V_71 . V_230 = F_139 ( V_120 ) | F_139 ( V_109 ) ;
V_16 -> V_71 . V_231 = V_232 ;
}
if ( F_138 ( V_193 , V_16 -> V_71 . V_192 ) )
V_16 -> V_71 . V_233 = F_80 ;
F_32 ( V_16 , V_183 , V_234 ) ;
F_140 ( & V_177 -> V_72 , L_42 ,
F_138 ( V_190 , V_16 -> V_71 . V_192 ) ? L_43 : L_44 ,
F_138 ( V_165 , V_16 -> V_71 . V_192 ) ? L_45 : L_44 ,
F_138 ( V_193 , V_16 -> V_71 . V_192 ) ? L_46 : L_44 ,
V_189 -> V_197 ) ;
F_141 ( & V_16 -> V_71 ) ;
if ( V_177 -> V_72 . V_178 ) {
V_119 = F_142 ( V_177 -> V_72 . V_178 ,
F_107 , V_16 ) ;
if ( V_119 ) {
F_20 ( & V_177 -> V_72 , L_47 ) ;
goto V_235;
}
}
return 0 ;
V_235:
F_143 ( & V_16 -> V_71 ) ;
F_144 ( V_16 -> V_19 ) ;
V_209:
F_145 ( F_123 ( V_177 , 0 ) , V_16 ) ;
V_208:
F_146 ( V_16 -> V_205 ) ;
V_207:
F_147 ( V_16 -> V_205 ) ;
V_206:
F_148 ( V_16 -> V_203 ) ;
V_16 -> V_203 = NULL ;
V_204:
F_149 ( V_187 -> V_199 , V_188 ) ;
V_202:
F_150 ( V_16 ) ;
return V_119 ;
}
static int F_151 ( struct V_161 * V_177 )
{
struct V_15 * V_16 = F_152 ( V_177 ) ;
struct V_11 * V_12 , * V_236 ;
struct V_186 * V_187 ;
F_120 ( V_16 ) ;
F_143 ( & V_16 -> V_71 ) ;
F_144 ( V_16 -> V_19 ) ;
F_145 ( F_123 ( V_177 , 0 ) , V_16 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_37 ( V_12 ) ;
F_153 ( V_16 , V_12 -> V_140 ) ;
F_154 ( & V_7 -> V_75 ) ;
F_15 ( & V_12 -> V_213 ) ;
}
F_146 ( V_16 -> V_205 ) ;
F_147 ( V_16 -> V_205 ) ;
F_148 ( V_16 -> V_203 ) ;
V_16 -> V_203 = NULL ;
V_187 = F_122 ( V_177 , V_196 , 0 ) ;
F_149 ( V_187 -> V_199 , F_125 ( V_187 ) ) ;
F_150 ( V_16 ) ;
return 0 ;
}
static void F_155 ( struct V_161 * V_177 )
{
struct V_15 * V_16 = F_152 ( V_177 ) ;
F_120 ( F_152 ( V_177 ) ) ;
F_146 ( V_16 -> V_205 ) ;
}
static int F_156 ( struct V_17 * V_72 )
{
struct V_161 * V_177 = F_157 ( V_72 ) ;
struct V_15 * V_16 = F_152 ( V_177 ) ;
struct V_11 * V_12 , * V_236 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_37 ( V_12 ) ;
if ( F_28 ( V_7 ) && ! F_40 ( V_7 ) )
return - V_237 ;
}
return 0 ;
}
static void F_158 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = & V_7 -> V_31 ;
if ( ! F_93 ( V_7 ) ) {
F_159 ( F_17 ( V_12 ) ,
L_48 ) ;
F_90 ( V_12 ) ;
}
V_7 -> V_238 = F_29 ( V_7 , V_44 ) ;
F_30 ( V_7 ) ;
}
static int F_160 ( struct V_17 * V_72 )
{
struct V_161 * V_177 = F_157 ( V_72 ) ;
struct V_15 * V_16 = F_152 ( V_177 ) ;
struct V_11 * V_12 , * V_236 ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_37 ( V_12 ) ;
if ( F_40 ( V_7 ) )
F_158 ( V_7 ) ;
V_7 -> V_239 = F_29 ( V_7 , V_155 ) ;
}
V_16 -> V_240 = F_57 ( V_16 , V_69 ) ;
F_120 ( V_16 ) ;
F_146 ( V_16 -> V_205 ) ;
return 0 ;
}
static void F_161 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = F_6 ( V_7 -> V_31 . V_17 ) ;
F_31 ( V_7 , V_40 , 0 ) ;
F_31 ( V_7 , V_41 , 0 ) ;
F_31 ( V_7 , V_42 , 0 ) ;
F_31 ( V_7 , V_43 , 0 ) ;
F_31 ( V_7 , V_44 , V_7 -> V_238 ) ;
F_32 ( V_16 , V_45 , V_7 -> V_46 ) ;
F_30 ( V_7 ) ;
}
static int F_162 ( struct V_17 * V_72 )
{
struct V_161 * V_177 = F_157 ( V_72 ) ;
struct V_15 * V_16 = F_152 ( V_177 ) ;
struct V_11 * V_12 , * V_236 ;
F_131 ( V_16 -> V_205 ) ;
F_32 ( V_16 , V_183 , V_234 ) ;
while ( F_57 ( V_16 , V_70 ) )
F_95 () ;
F_32 ( V_16 , V_241 , V_16 -> V_240 ) ;
F_13 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_6 * V_7 = F_37 ( V_12 ) ;
F_31 ( V_7 , V_155 , V_7 -> V_239 ) ;
if ( F_40 ( V_7 ) )
F_161 ( V_7 ) ;
}
return 0 ;
}
static int T_9 F_163 ( void )
{
return F_164 ( & V_242 , F_121 ) ;
}
static void T_10 F_165 ( void )
{
F_166 ( & V_242 ) ;
}
