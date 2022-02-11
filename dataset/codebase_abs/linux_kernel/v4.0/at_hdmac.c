static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( & V_3 -> V_4 ,
struct V_1 , V_5 ) ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 )
{
return F_2 ( & V_3 -> V_6 ,
struct V_1 , V_5 ) ;
}
static struct V_1 * F_4 ( struct V_7 * V_8 ,
T_1 V_9 )
{
struct V_1 * V_10 = NULL ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
T_2 V_14 ;
V_10 = F_6 ( V_12 -> V_15 , V_9 , & V_14 ) ;
if ( V_10 ) {
memset ( V_10 , 0 , sizeof( struct V_1 ) ) ;
F_7 ( & V_10 -> V_16 ) ;
F_8 ( & V_10 -> V_17 , V_8 ) ;
V_10 -> V_17 . V_18 = V_19 ;
V_10 -> V_17 . V_20 = V_21 ;
V_10 -> V_17 . V_14 = V_14 ;
}
return V_10 ;
}
static struct V_1 * F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_10 , * V_22 ;
struct V_1 * V_23 = NULL ;
unsigned long V_18 ;
unsigned int V_24 = 0 ;
F_10 ( V_25 ) ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_12 (desc, _desc, &atchan->free_list, desc_node) {
V_24 ++ ;
if ( F_13 ( & V_10 -> V_17 ) ) {
F_14 ( & V_10 -> V_5 ) ;
V_23 = V_10 ;
break;
}
F_15 ( F_16 ( & V_3 -> V_27 ) ,
L_1 , V_10 ) ;
}
F_17 ( & V_3 -> V_26 , V_18 ) ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_2 , V_24 ) ;
if ( ! V_23 ) {
V_23 = F_4 ( & V_3 -> V_27 , V_28 ) ;
if ( V_23 ) {
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_3 -> V_29 ++ ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else {
F_19 ( F_16 ( & V_3 -> V_27 ) ,
L_3 ) ;
}
}
return V_23 ;
}
static void F_20 ( struct V_2 * V_3 , struct V_1 * V_10 )
{
if ( V_10 ) {
struct V_1 * V_30 ;
unsigned long V_18 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_21 (child, &desc->tx_list, desc_node)
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_4 ,
V_30 ) ;
F_22 ( & V_10 -> V_16 , & V_3 -> V_31 ) ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_5 , V_10 ) ;
F_23 ( & V_10 -> V_5 , & V_3 -> V_31 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
}
}
static void F_24 ( struct V_1 * * V_32 , struct V_1 * * V_33 ,
struct V_1 * V_10 )
{
if ( ! ( * V_32 ) ) {
* V_32 = V_10 ;
} else {
( * V_33 ) -> V_34 . V_35 = V_10 -> V_17 . V_14 ;
F_25 ( & V_10 -> V_5 ,
& ( * V_32 ) -> V_16 ) ;
}
* V_33 = V_10 ;
}
static void F_26 ( struct V_2 * V_3 , struct V_1 * V_32 )
{
struct V_11 * V_12 = F_5 ( V_3 -> V_27 . V_13 ) ;
if ( F_27 ( V_3 ) ) {
F_19 ( F_16 ( & V_3 -> V_27 ) ,
L_6 ) ;
F_19 ( F_16 ( & V_3 -> V_27 ) ,
L_7 ,
F_28 ( V_3 , V_36 ) ,
F_28 ( V_3 , V_37 ) ,
F_28 ( V_3 , V_38 ) ,
F_28 ( V_3 , V_39 ) ,
F_28 ( V_3 , V_40 ) ) ;
return;
}
F_29 ( V_3 ) ;
F_30 ( V_3 , V_36 , 0 ) ;
F_30 ( V_3 , V_37 , 0 ) ;
F_30 ( V_3 , V_38 , 0 ) ;
F_30 ( V_3 , V_39 , 0 ) ;
F_30 ( V_3 , V_40 , V_32 -> V_17 . V_14 ) ;
F_31 ( V_12 , V_41 , V_3 -> V_42 ) ;
F_29 ( V_3 ) ;
}
static struct V_1 * F_32 ( struct V_2 * V_3 ,
T_3 V_43 )
{
struct V_1 * V_10 , * V_22 ;
F_12 (desc, _desc, &atchan->queue, desc_node) {
if ( V_10 -> V_17 . V_43 == V_43 )
return V_10 ;
}
F_12 (desc, _desc, &atchan->active_list, desc_node) {
if ( V_10 -> V_17 . V_43 == V_43 )
return V_10 ;
}
return NULL ;
}
static inline int F_33 ( int V_44 , T_4 V_45 ,
struct V_1 * V_10 )
{
return V_44 - ( ( V_45 & V_46 ) << V_10 -> V_47 ) ;
}
static inline int F_34 ( int V_44 ,
struct V_2 * V_3 , struct V_1 * V_10 )
{
T_4 V_45 = F_28 ( V_3 , V_38 ) ;
return F_33 ( V_44 , V_45 , V_10 ) ;
}
static int F_35 ( struct V_7 * V_8 , T_3 V_43 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_1 * V_10 ;
int V_23 ;
T_4 V_45 , V_35 ;
V_10 = F_32 ( V_3 , V_43 ) ;
if ( V_10 == NULL )
return - V_49 ;
else if ( V_10 != V_48 )
return V_10 -> V_50 ;
V_23 = V_48 -> V_50 ;
if ( V_48 -> V_34 . V_35 ) {
V_45 = F_28 ( V_3 , V_38 ) ;
F_37 () ;
V_35 = F_28 ( V_3 , V_40 ) ;
if ( V_48 -> V_34 . V_35 == V_35 )
return F_33 ( V_23 , V_45 , V_48 ) ;
V_23 -= V_48 -> V_51 ;
F_21 (desc, &desc_first->tx_list, desc_node) {
if ( V_10 -> V_34 . V_35 == V_35 )
break;
V_23 -= V_10 -> V_51 ;
}
if ( ! V_10 -> V_34 . V_35 )
V_23 = F_34 ( V_23 , V_3 , V_10 ) ;
} else {
V_23 = F_34 ( V_23 , V_3 , V_48 ) ;
}
return V_23 ;
}
static void
F_38 ( struct V_2 * V_3 , struct V_1 * V_10 )
{
struct V_52 * V_17 = & V_10 -> V_17 ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_8 , V_17 -> V_43 ) ;
if ( ! F_39 ( V_3 ) )
F_40 ( V_17 ) ;
F_22 ( & V_10 -> V_16 , & V_3 -> V_31 ) ;
F_41 ( & V_10 -> V_5 , & V_3 -> V_31 ) ;
F_42 ( V_17 ) ;
if ( ! F_39 ( V_3 ) ) {
T_5 V_53 = V_17 -> V_53 ;
void * V_54 = V_17 -> V_55 ;
if ( V_53 )
V_53 ( V_54 ) ;
}
F_43 ( V_17 ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_10 , * V_22 ;
F_10 ( V_56 ) ;
F_18 ( F_16 ( & V_3 -> V_27 ) , L_9 ) ;
if ( ! F_45 ( & V_3 -> V_6 ) )
F_26 ( V_3 , F_3 ( V_3 ) ) ;
F_22 ( & V_3 -> V_4 , & V_56 ) ;
F_22 ( & V_3 -> V_6 , & V_3 -> V_4 ) ;
F_12 (desc, _desc, &list, desc_node)
F_38 ( V_3 , V_10 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
F_18 ( F_16 ( & V_3 -> V_27 ) , L_10 ) ;
if ( F_27 ( V_3 ) )
return;
if ( F_45 ( & V_3 -> V_4 ) ||
F_47 ( & V_3 -> V_4 ) ) {
F_44 ( V_3 ) ;
} else {
F_38 ( V_3 , F_1 ( V_3 ) ) ;
F_26 ( V_3 , F_1 ( V_3 ) ) ;
}
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_57 ;
struct V_1 * V_30 ;
V_57 = F_1 ( V_3 ) ;
F_49 ( & V_57 -> V_5 ) ;
F_22 ( & V_3 -> V_6 , V_3 -> V_4 . V_33 ) ;
if ( ! F_45 ( & V_3 -> V_4 ) )
F_26 ( V_3 , F_1 ( V_3 ) ) ;
F_50 ( F_16 ( & V_3 -> V_27 ) ,
L_11 ) ;
F_50 ( F_16 ( & V_3 -> V_27 ) ,
L_12 , V_57 -> V_17 . V_43 ) ;
F_51 ( V_3 , & V_57 -> V_34 ) ;
F_21 (child, &bad_desc->tx_list, desc_node)
F_51 ( V_3 , & V_30 -> V_34 ) ;
F_38 ( V_3 , V_57 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_52 * V_17 = & V_32 -> V_17 ;
T_5 V_53 = V_17 -> V_53 ;
void * V_54 = V_17 -> V_55 ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_13 ,
F_28 ( V_3 , V_40 ) ) ;
if ( V_53 )
V_53 ( V_54 ) ;
}
static void F_53 ( unsigned long V_58 )
{
struct V_2 * V_3 = (struct V_2 * ) V_58 ;
unsigned long V_18 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
if ( F_54 ( V_59 , & V_3 -> V_60 ) )
F_48 ( V_3 ) ;
else if ( F_39 ( V_3 ) )
F_52 ( V_3 ) ;
else
F_46 ( V_3 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
}
static T_6 F_55 ( int V_61 , void * V_62 )
{
struct V_11 * V_12 = (struct V_11 * ) V_62 ;
struct V_2 * V_3 ;
int V_24 ;
T_4 V_60 , V_63 , V_64 ;
int V_23 = V_65 ;
do {
V_64 = F_56 ( V_12 , V_66 ) ;
V_60 = F_56 ( V_12 , V_67 ) ;
V_63 = V_60 & V_64 ;
if ( ! V_63 )
break;
F_18 ( V_12 -> V_68 . V_69 ,
L_14 ,
V_60 , V_64 , V_63 ) ;
for ( V_24 = 0 ; V_24 < V_12 -> V_68 . V_70 ; V_24 ++ ) {
V_3 = & V_12 -> V_8 [ V_24 ] ;
if ( V_63 & ( F_57 ( V_24 ) | F_58 ( V_24 ) ) ) {
if ( V_63 & F_58 ( V_24 ) ) {
F_31 ( V_12 , V_71 ,
F_59 ( V_24 ) | V_3 -> V_42 ) ;
F_60 ( V_59 , & V_3 -> V_60 ) ;
}
F_61 ( & V_3 -> V_72 ) ;
V_23 = V_73 ;
}
}
} while ( V_63 );
return V_23 ;
}
static T_3 V_21 ( struct V_52 * V_74 )
{
struct V_1 * V_10 = F_62 ( V_74 ) ;
struct V_2 * V_3 = F_36 ( V_74 -> V_8 ) ;
T_3 V_43 ;
unsigned long V_18 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_43 = F_63 ( V_74 ) ;
if ( F_45 ( & V_3 -> V_4 ) ) {
F_18 ( F_16 ( V_74 -> V_8 ) , L_15 ,
V_10 -> V_17 . V_43 ) ;
F_26 ( V_3 , V_10 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_4 ) ;
} else {
F_18 ( F_16 ( V_74 -> V_8 ) , L_16 ,
V_10 -> V_17 . V_43 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_6 ) ;
}
F_17 ( & V_3 -> V_26 , V_18 ) ;
return V_43 ;
}
static struct V_52 *
F_64 ( struct V_7 * V_8 , T_2 V_75 , T_2 V_76 ,
T_7 V_51 , unsigned long V_18 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
struct V_1 * V_10 = NULL ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_7 V_77 ;
T_7 V_78 ;
unsigned int V_79 ;
unsigned int V_80 ;
T_4 V_45 ;
T_4 V_81 ;
F_18 ( F_16 ( V_8 ) , L_17 ,
V_75 , V_76 , V_51 , V_18 ) ;
if ( F_65 ( ! V_51 ) ) {
F_15 ( F_16 ( V_8 ) , L_18 ) ;
return NULL ;
}
V_81 = V_82 | V_83
| V_84
| V_85
| V_86 ;
if ( ! ( ( V_76 | V_75 | V_51 ) & 3 ) ) {
V_45 = V_87 | V_88 ;
V_79 = V_80 = 2 ;
} else if ( ! ( ( V_76 | V_75 | V_51 ) & 1 ) ) {
V_45 = V_89 | V_90 ;
V_79 = V_80 = 1 ;
} else {
V_45 = V_91 | V_92 ;
V_79 = V_80 = 0 ;
}
for ( V_78 = 0 ; V_78 < V_51 ; V_78 += V_77 << V_79 ) {
V_77 = F_66 ( T_7 , ( V_51 - V_78 ) >> V_79 ,
V_46 ) ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_93;
V_10 -> V_34 . V_94 = V_76 + V_78 ;
V_10 -> V_34 . V_95 = V_75 + V_78 ;
V_10 -> V_34 . V_45 = V_45 | V_77 ;
V_10 -> V_34 . V_81 = V_81 ;
V_10 -> V_17 . V_43 = 0 ;
V_10 -> V_51 = V_77 << V_79 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_32 -> V_17 . V_43 = - V_96 ;
V_32 -> V_50 = V_51 ;
V_32 -> V_47 = V_79 ;
V_33 -> V_47 = V_79 ;
F_67 ( V_10 ) ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_93:
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static struct V_52 *
F_68 ( struct V_7 * V_8 , struct V_97 * V_98 ,
unsigned int V_99 , enum V_100 V_101 ,
unsigned long V_18 , void * V_102 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
struct V_103 * V_104 = V_8 -> V_105 ;
struct V_106 * V_107 = & V_3 -> V_108 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_4 V_45 ;
T_4 V_81 ;
T_2 V_109 ;
unsigned int V_110 ;
unsigned int V_111 ;
unsigned int V_24 ;
struct V_97 * V_112 ;
T_7 V_50 = 0 ;
F_18 ( F_16 ( V_8 ) , L_19 ,
V_99 ,
V_101 == V_113 ? L_20 : L_21 ,
V_18 ) ;
if ( F_65 ( ! V_104 || ! V_99 ) ) {
F_15 ( F_16 ( V_8 ) , L_22 ) ;
return NULL ;
}
V_45 = F_69 ( V_107 -> V_114 )
| F_70 ( V_107 -> V_115 ) ;
V_81 = V_83 ;
switch ( V_101 ) {
case V_113 :
V_110 = F_71 ( V_107 -> V_116 ) ;
V_45 |= F_72 ( V_110 ) ;
V_81 |= V_117
| V_84
| V_118
| F_73 ( V_3 -> V_119 ) | F_74 ( V_3 -> V_120 ) ;
V_109 = V_107 -> V_121 ;
F_75 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_4 V_51 ;
T_4 V_122 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_93;
V_122 = F_76 ( V_112 ) ;
V_51 = F_77 ( V_112 ) ;
if ( F_65 ( ! V_51 ) ) {
F_15 ( F_16 ( V_8 ) ,
L_23 , V_24 ) ;
goto V_123;
}
V_111 = 2 ;
if ( F_65 ( V_122 & 3 || V_51 & 3 ) )
V_111 = 0 ;
V_10 -> V_34 . V_94 = V_122 ;
V_10 -> V_34 . V_95 = V_109 ;
V_10 -> V_34 . V_45 = V_45
| F_78 ( V_111 )
| V_51 >> V_111 ;
V_10 -> V_34 . V_81 = V_81 ;
V_10 -> V_51 = V_51 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_50 += V_51 ;
}
break;
case V_124 :
V_110 = F_71 ( V_107 -> V_125 ) ;
V_45 |= F_78 ( V_110 ) ;
V_81 |= V_85
| V_126
| V_127
| F_73 ( V_3 -> V_120 ) | F_74 ( V_3 -> V_119 ) ;
V_109 = V_107 -> V_128 ;
F_75 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_4 V_51 ;
T_4 V_122 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_93;
V_122 = F_76 ( V_112 ) ;
V_51 = F_77 ( V_112 ) ;
if ( F_65 ( ! V_51 ) ) {
F_15 ( F_16 ( V_8 ) ,
L_23 , V_24 ) ;
goto V_123;
}
V_111 = 2 ;
if ( F_65 ( V_122 & 3 || V_51 & 3 ) )
V_111 = 0 ;
V_10 -> V_34 . V_94 = V_109 ;
V_10 -> V_34 . V_95 = V_122 ;
V_10 -> V_34 . V_45 = V_45
| F_72 ( V_111 )
| V_51 >> V_110 ;
V_10 -> V_34 . V_81 = V_81 ;
V_10 -> V_51 = V_51 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_50 += V_51 ;
}
break;
default:
return NULL ;
}
F_67 ( V_33 ) ;
V_32 -> V_17 . V_43 = - V_96 ;
V_32 -> V_50 = V_50 ;
V_32 -> V_47 = V_110 ;
V_33 -> V_47 = V_110 ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_93:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
V_123:
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static int
F_79 ( unsigned int V_110 , T_2 V_129 ,
T_7 V_130 )
{
if ( V_130 > ( V_46 << V_110 ) )
goto V_131;
if ( F_65 ( V_130 & ( ( 1 << V_110 ) - 1 ) ) )
goto V_131;
if ( F_65 ( V_129 & ( ( 1 << V_110 ) - 1 ) ) )
goto V_131;
return 0 ;
V_131:
return - V_49 ;
}
static int
F_80 ( struct V_7 * V_8 , struct V_1 * V_10 ,
unsigned int V_132 , T_2 V_129 ,
unsigned int V_110 , T_7 V_130 ,
enum V_100 V_101 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
struct V_106 * V_107 = & V_3 -> V_108 ;
T_4 V_45 ;
V_45 = F_69 ( V_107 -> V_114 )
| F_70 ( V_107 -> V_115 )
| F_72 ( V_110 )
| F_78 ( V_110 )
| V_130 >> V_110 ;
switch ( V_101 ) {
case V_113 :
V_10 -> V_34 . V_94 = V_129 + ( V_130 * V_132 ) ;
V_10 -> V_34 . V_95 = V_107 -> V_121 ;
V_10 -> V_34 . V_45 = V_45 ;
V_10 -> V_34 . V_81 = V_117
| V_84
| V_118
| F_73 ( V_3 -> V_119 )
| F_74 ( V_3 -> V_120 ) ;
V_10 -> V_51 = V_130 ;
break;
case V_124 :
V_10 -> V_34 . V_94 = V_107 -> V_128 ;
V_10 -> V_34 . V_95 = V_129 + ( V_130 * V_132 ) ;
V_10 -> V_34 . V_45 = V_45 ;
V_10 -> V_34 . V_81 = V_85
| V_126
| V_127
| F_73 ( V_3 -> V_120 )
| F_74 ( V_3 -> V_119 ) ;
V_10 -> V_51 = V_130 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static struct V_52 *
F_81 ( struct V_7 * V_8 , T_2 V_129 , T_7 V_133 ,
T_7 V_130 , enum V_100 V_101 ,
unsigned long V_18 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
struct V_103 * V_104 = V_8 -> V_105 ;
struct V_106 * V_107 = & V_3 -> V_108 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
unsigned long V_134 ;
unsigned int V_110 ;
unsigned int V_135 = V_133 / V_130 ;
unsigned int V_24 ;
F_18 ( F_16 ( V_8 ) , L_24 ,
V_101 == V_113 ? L_20 : L_21 ,
V_129 ,
V_135 , V_133 , V_130 ) ;
if ( F_65 ( ! V_104 || ! V_133 || ! V_130 ) ) {
F_15 ( F_16 ( V_8 ) , L_25 ) ;
return NULL ;
}
V_134 = F_82 ( V_136 , & V_3 -> V_60 ) ;
if ( V_134 ) {
F_15 ( F_16 ( V_8 ) , L_26 ) ;
return NULL ;
}
if ( F_65 ( ! F_83 ( V_101 ) ) )
goto V_131;
if ( V_107 -> V_101 == V_113 )
V_110 = F_71 ( V_107 -> V_116 ) ;
else
V_110 = F_71 ( V_107 -> V_125 ) ;
if ( F_79 ( V_110 , V_129 , V_130 ) )
goto V_131;
for ( V_24 = 0 ; V_24 < V_135 ; V_24 ++ ) {
struct V_1 * V_10 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_93;
if ( F_80 ( V_8 , V_10 , V_24 , V_129 ,
V_110 , V_130 , V_101 ) )
goto V_93;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_33 -> V_34 . V_35 = V_32 -> V_17 . V_14 ;
V_32 -> V_17 . V_43 = - V_96 ;
V_32 -> V_50 = V_133 ;
V_32 -> V_47 = V_110 ;
return & V_32 -> V_17 ;
V_93:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
F_20 ( V_3 , V_32 ) ;
V_131:
F_84 ( V_136 , & V_3 -> V_60 ) ;
return NULL ;
}
static int F_85 ( struct V_7 * V_8 ,
struct V_106 * V_107 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
F_18 ( F_16 ( V_8 ) , L_27 , V_137 ) ;
if ( ! V_8 -> V_105 )
return - V_49 ;
memcpy ( & V_3 -> V_108 , V_107 , sizeof( * V_107 ) ) ;
F_86 ( & V_3 -> V_108 . V_114 ) ;
F_86 ( & V_3 -> V_108 . V_115 ) ;
return 0 ;
}
static int F_87 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
int V_138 = V_3 -> V_27 . V_138 ;
unsigned long V_18 ;
F_10 ( V_56 ) ;
F_18 ( F_16 ( V_8 ) , L_27 , V_137 ) ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_41 , F_88 ( V_138 ) ) ;
F_60 ( V_139 , & V_3 -> V_60 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
return 0 ;
}
static int F_89 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
int V_138 = V_3 -> V_27 . V_138 ;
unsigned long V_18 ;
F_10 ( V_56 ) ;
F_18 ( F_16 ( V_8 ) , L_27 , V_137 ) ;
if ( ! F_90 ( V_3 ) )
return 0 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_71 , F_59 ( V_138 ) ) ;
F_84 ( V_139 , & V_3 -> V_60 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
return 0 ;
}
static int F_91 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
int V_138 = V_3 -> V_27 . V_138 ;
struct V_1 * V_10 , * V_22 ;
unsigned long V_18 ;
F_10 ( V_56 ) ;
F_18 ( F_16 ( V_8 ) , L_27 , V_137 ) ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_71 , F_59 ( V_138 ) | V_3 -> V_42 ) ;
while ( F_56 ( V_12 , V_140 ) & V_3 -> V_42 )
F_92 () ;
F_22 ( & V_3 -> V_6 , & V_56 ) ;
F_22 ( & V_3 -> V_4 , & V_56 ) ;
F_12 (desc, _desc, &list, desc_node)
F_38 ( V_3 , V_10 ) ;
F_84 ( V_139 , & V_3 -> V_60 ) ;
F_84 ( V_136 , & V_3 -> V_60 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
return 0 ;
}
static enum V_141
F_93 ( struct V_7 * V_8 ,
T_3 V_43 ,
struct V_142 * V_143 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
unsigned long V_18 ;
enum V_141 V_23 ;
int V_144 = 0 ;
V_23 = F_94 ( V_8 , V_43 , V_143 ) ;
if ( V_23 == V_145 )
return V_23 ;
if ( ! V_143 )
return V_146 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_144 = F_35 ( V_8 , V_43 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
if ( F_65 ( V_144 < 0 ) ) {
F_18 ( F_16 ( V_8 ) , L_28 ) ;
return V_146 ;
} else {
F_95 ( V_143 , V_144 ) ;
}
F_18 ( F_16 ( V_8 ) , L_29 ,
V_23 , V_43 , V_144 ) ;
return V_23 ;
}
static void F_96 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
unsigned long V_18 ;
F_18 ( F_16 ( V_8 ) , L_30 ) ;
if ( F_39 ( V_3 ) )
return;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_46 ( V_3 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
}
static int F_97 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 ;
struct V_103 * V_104 ;
unsigned long V_18 ;
int V_24 ;
T_4 V_147 ;
F_10 ( V_25 ) ;
F_18 ( F_16 ( V_8 ) , L_31 ) ;
if ( F_27 ( V_3 ) ) {
F_15 ( F_16 ( V_8 ) , L_32 ) ;
return - V_148 ;
}
V_147 = V_149 ;
V_104 = V_8 -> V_105 ;
if ( V_104 ) {
F_98 ( ! V_104 -> V_150 || V_104 -> V_150 != V_12 -> V_68 . V_69 ) ;
if ( V_104 -> V_147 )
V_147 = V_104 -> V_147 ;
}
if ( ! F_45 ( & V_3 -> V_31 ) )
return V_3 -> V_29 ;
for ( V_24 = 0 ; V_24 < V_151 ; V_24 ++ ) {
V_10 = F_4 ( V_8 , V_152 ) ;
if ( ! V_10 ) {
F_19 ( V_12 -> V_68 . V_69 ,
L_33 , V_24 ) ;
break;
}
F_25 ( & V_10 -> V_5 , & V_25 ) ;
}
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_3 -> V_29 = V_24 ;
F_99 ( & V_25 , & V_3 -> V_31 ) ;
F_100 ( V_8 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
F_30 ( V_3 , V_153 , V_147 ) ;
F_15 ( F_16 ( V_8 ) ,
L_34 ,
V_3 -> V_29 ) ;
return V_3 -> V_29 ;
}
static void F_101 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_36 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 , * V_22 ;
F_10 ( V_56 ) ;
F_15 ( F_16 ( V_8 ) , L_35 ,
V_3 -> V_29 ) ;
F_98 ( ! F_45 ( & V_3 -> V_4 ) ) ;
F_98 ( ! F_45 ( & V_3 -> V_6 ) ) ;
F_98 ( F_27 ( V_3 ) ) ;
F_12 (desc, _desc, &atchan->free_list, desc_node) {
F_18 ( F_16 ( V_8 ) , L_36 , V_10 ) ;
F_14 ( & V_10 -> V_5 ) ;
F_102 ( V_12 -> V_15 , V_10 , V_10 -> V_17 . V_14 ) ;
}
F_22 ( & V_3 -> V_31 , & V_56 ) ;
V_3 -> V_29 = 0 ;
V_3 -> V_60 = 0 ;
F_18 ( F_16 ( V_8 ) , L_37 ) ;
}
static bool F_103 ( struct V_7 * V_8 , void * V_154 )
{
struct V_103 * V_104 = V_154 ;
if ( V_104 -> V_150 == V_8 -> V_13 -> V_69 ) {
V_8 -> V_105 = V_104 ;
return true ;
} else {
return false ;
}
}
static struct V_7 * F_104 ( struct V_155 * V_156 ,
struct V_157 * V_157 )
{
struct V_7 * V_8 ;
struct V_2 * V_3 ;
struct V_103 * V_104 ;
T_8 V_42 ;
unsigned int V_158 ;
struct V_159 * V_160 ;
if ( V_156 -> V_161 != 2 )
return NULL ;
V_160 = F_105 ( V_156 -> V_162 ) ;
F_106 ( V_42 ) ;
F_107 ( V_163 , V_42 ) ;
V_104 = F_108 ( & V_160 -> V_69 , sizeof( * V_104 ) , V_152 ) ;
if ( ! V_104 )
return NULL ;
V_104 -> V_147 = V_164 | V_165 ;
V_158 = V_156 -> args [ 1 ] & V_166 ;
V_104 -> V_147 |= F_109 ( V_158 ) | F_110 ( V_158 )
| F_111 ( V_158 ) | F_112 ( V_158 ) ;
switch ( V_156 -> args [ 1 ] & V_167 ) {
case V_168 :
V_104 -> V_147 |= V_169 ;
break;
case V_170 :
V_104 -> V_147 |= V_171 ;
break;
case V_172 :
default:
V_104 -> V_147 |= V_173 ;
}
V_104 -> V_150 = & V_160 -> V_69 ;
V_8 = F_113 ( V_42 , F_103 , V_104 ) ;
if ( ! V_8 )
return NULL ;
V_3 = F_36 ( V_8 ) ;
V_3 -> V_120 = V_156 -> args [ 0 ] & 0xff ;
V_3 -> V_119 = ( V_156 -> args [ 0 ] >> 16 ) & 0xff ;
return V_8 ;
}
static struct V_7 * F_104 ( struct V_155 * V_156 ,
struct V_157 * V_157 )
{
return NULL ;
}
static inline const struct V_174 * T_9 F_114 (
struct V_159 * V_175 )
{
if ( V_175 -> V_69 . V_176 ) {
const struct V_177 * V_178 ;
V_178 = F_115 ( V_179 , V_175 -> V_69 . V_176 ) ;
if ( V_178 == NULL )
return NULL ;
return V_178 -> V_58 ;
}
return (struct V_174 * )
F_116 ( V_175 ) -> V_180 ;
}
static void F_117 ( struct V_11 * V_12 )
{
F_31 ( V_12 , V_181 , 0 ) ;
F_31 ( V_12 , V_182 , - 1L ) ;
while ( F_56 ( V_12 , V_140 ) & V_12 -> V_183 )
F_92 () ;
}
static int T_9 F_118 ( struct V_159 * V_175 )
{
struct V_184 * V_185 ;
struct V_11 * V_12 ;
T_7 V_186 ;
int V_61 ;
int V_123 ;
int V_24 ;
const struct V_174 * V_187 ;
F_107 ( V_188 , V_189 . V_190 ) ;
F_107 ( V_188 , V_191 . V_190 ) ;
F_107 ( V_163 , V_191 . V_190 ) ;
V_187 = F_114 ( V_175 ) ;
if ( ! V_187 )
return - V_192 ;
V_185 = F_119 ( V_175 , V_193 , 0 ) ;
if ( ! V_185 )
return - V_49 ;
V_61 = F_120 ( V_175 , 0 ) ;
if ( V_61 < 0 )
return V_61 ;
V_186 = sizeof( struct V_11 ) ;
V_186 += V_187 -> V_194 * sizeof( struct V_2 ) ;
V_12 = F_121 ( V_186 , V_152 ) ;
if ( ! V_12 )
return - V_195 ;
V_12 -> V_68 . V_190 = V_187 -> V_190 ;
V_12 -> V_183 = ( 1 << V_187 -> V_194 ) - 1 ;
V_186 = F_122 ( V_185 ) ;
if ( ! F_123 ( V_185 -> V_196 , V_186 , V_175 -> V_69 . V_197 -> V_198 ) ) {
V_123 = - V_96 ;
goto V_199;
}
V_12 -> V_200 = F_124 ( V_185 -> V_196 , V_186 ) ;
if ( ! V_12 -> V_200 ) {
V_123 = - V_195 ;
goto V_201;
}
V_12 -> V_202 = F_125 ( & V_175 -> V_69 , L_38 ) ;
if ( F_126 ( V_12 -> V_202 ) ) {
V_123 = F_127 ( V_12 -> V_202 ) ;
goto V_203;
}
V_123 = F_128 ( V_12 -> V_202 ) ;
if ( V_123 )
goto V_204;
F_117 ( V_12 ) ;
V_123 = F_129 ( V_61 , F_55 , 0 , L_39 , V_12 ) ;
if ( V_123 )
goto V_205;
F_130 ( V_175 , V_12 ) ;
V_12 -> V_15 = F_131 ( L_40 ,
& V_175 -> V_69 , sizeof( struct V_1 ) ,
4 , 0 ) ;
if ( ! V_12 -> V_15 ) {
F_19 ( & V_175 -> V_69 , L_41 ) ;
V_123 = - V_195 ;
goto V_206;
}
while ( F_56 ( V_12 , V_67 ) )
F_92 () ;
F_7 ( & V_12 -> V_68 . V_207 ) ;
for ( V_24 = 0 ; V_24 < V_187 -> V_194 ; V_24 ++ ) {
struct V_2 * V_3 = & V_12 -> V_8 [ V_24 ] ;
V_3 -> V_119 = V_208 ;
V_3 -> V_120 = V_209 ;
V_3 -> V_27 . V_13 = & V_12 -> V_68 ;
F_100 ( & V_3 -> V_27 ) ;
F_25 ( & V_3 -> V_27 . V_210 ,
& V_12 -> V_68 . V_207 ) ;
V_3 -> V_211 = V_12 -> V_200 + V_211 ( V_24 ) ;
F_132 ( & V_3 -> V_26 ) ;
V_3 -> V_42 = 1 << V_24 ;
F_7 ( & V_3 -> V_4 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_7 ( & V_3 -> V_31 ) ;
F_133 ( & V_3 -> V_72 , F_53 ,
( unsigned long ) V_3 ) ;
F_134 ( V_12 , V_24 ) ;
}
V_12 -> V_68 . V_212 = F_97 ;
V_12 -> V_68 . V_213 = F_101 ;
V_12 -> V_68 . V_214 = F_93 ;
V_12 -> V_68 . V_215 = F_96 ;
V_12 -> V_68 . V_69 = & V_175 -> V_69 ;
if ( F_135 ( V_188 , V_12 -> V_68 . V_190 ) )
V_12 -> V_68 . V_216 = F_64 ;
if ( F_135 ( V_163 , V_12 -> V_68 . V_190 ) ) {
V_12 -> V_68 . V_217 = F_68 ;
F_107 ( V_218 , V_12 -> V_68 . V_190 ) ;
V_12 -> V_68 . V_219 = F_81 ;
V_12 -> V_68 . V_220 = F_85 ;
V_12 -> V_68 . V_221 = F_87 ;
V_12 -> V_68 . V_222 = F_89 ;
V_12 -> V_68 . V_223 = F_91 ;
V_12 -> V_68 . V_224 = V_225 ;
V_12 -> V_68 . V_226 = V_225 ;
V_12 -> V_68 . V_227 = F_136 ( V_124 ) | F_136 ( V_113 ) ;
V_12 -> V_68 . V_228 = V_229 ;
}
F_31 ( V_12 , V_181 , V_230 ) ;
F_137 ( & V_175 -> V_69 , L_42 ,
F_135 ( V_188 , V_12 -> V_68 . V_190 ) ? L_43 : L_44 ,
F_135 ( V_163 , V_12 -> V_68 . V_190 ) ? L_45 : L_44 ,
V_187 -> V_194 ) ;
F_138 ( & V_12 -> V_68 ) ;
if ( V_175 -> V_69 . V_176 ) {
V_123 = F_139 ( V_175 -> V_69 . V_176 ,
F_104 , V_12 ) ;
if ( V_123 ) {
F_19 ( & V_175 -> V_69 , L_46 ) ;
goto V_231;
}
}
return 0 ;
V_231:
F_140 ( & V_12 -> V_68 ) ;
F_141 ( V_12 -> V_15 ) ;
V_206:
F_142 ( F_120 ( V_175 , 0 ) , V_12 ) ;
V_205:
F_143 ( V_12 -> V_202 ) ;
V_204:
F_144 ( V_12 -> V_202 ) ;
V_203:
F_145 ( V_12 -> V_200 ) ;
V_12 -> V_200 = NULL ;
V_201:
F_146 ( V_185 -> V_196 , V_186 ) ;
V_199:
F_147 ( V_12 ) ;
return V_123 ;
}
static int F_148 ( struct V_159 * V_175 )
{
struct V_11 * V_12 = F_149 ( V_175 ) ;
struct V_7 * V_8 , * V_232 ;
struct V_184 * V_185 ;
F_117 ( V_12 ) ;
F_140 ( & V_12 -> V_68 ) ;
F_141 ( V_12 -> V_15 ) ;
F_142 ( F_120 ( V_175 , 0 ) , V_12 ) ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_36 ( V_8 ) ;
F_150 ( V_12 , V_8 -> V_138 ) ;
F_151 ( & V_3 -> V_72 ) ;
F_14 ( & V_8 -> V_210 ) ;
}
F_143 ( V_12 -> V_202 ) ;
F_144 ( V_12 -> V_202 ) ;
F_145 ( V_12 -> V_200 ) ;
V_12 -> V_200 = NULL ;
V_185 = F_119 ( V_175 , V_193 , 0 ) ;
F_146 ( V_185 -> V_196 , F_122 ( V_185 ) ) ;
F_147 ( V_12 ) ;
return 0 ;
}
static void F_152 ( struct V_159 * V_175 )
{
struct V_11 * V_12 = F_149 ( V_175 ) ;
F_117 ( F_149 ( V_175 ) ) ;
F_143 ( V_12 -> V_202 ) ;
}
static int F_153 ( struct V_13 * V_69 )
{
struct V_159 * V_175 = F_154 ( V_69 ) ;
struct V_11 * V_12 = F_149 ( V_175 ) ;
struct V_7 * V_8 , * V_232 ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_36 ( V_8 ) ;
if ( F_27 ( V_3 ) && ! F_39 ( V_3 ) )
return - V_233 ;
}
return 0 ;
}
static void F_155 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = & V_3 -> V_27 ;
if ( ! F_90 ( V_3 ) ) {
F_156 ( F_16 ( V_8 ) ,
L_47 ) ;
F_87 ( V_8 ) ;
}
V_3 -> V_234 = F_28 ( V_3 , V_40 ) ;
F_29 ( V_3 ) ;
}
static int F_157 ( struct V_13 * V_69 )
{
struct V_159 * V_175 = F_154 ( V_69 ) ;
struct V_11 * V_12 = F_149 ( V_175 ) ;
struct V_7 * V_8 , * V_232 ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_36 ( V_8 ) ;
if ( F_39 ( V_3 ) )
F_155 ( V_3 ) ;
V_3 -> V_235 = F_28 ( V_3 , V_153 ) ;
}
V_12 -> V_236 = F_56 ( V_12 , V_66 ) ;
F_117 ( V_12 ) ;
F_143 ( V_12 -> V_202 ) ;
return 0 ;
}
static void F_158 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_5 ( V_3 -> V_27 . V_13 ) ;
F_30 ( V_3 , V_36 , 0 ) ;
F_30 ( V_3 , V_37 , 0 ) ;
F_30 ( V_3 , V_38 , 0 ) ;
F_30 ( V_3 , V_39 , 0 ) ;
F_30 ( V_3 , V_40 , V_3 -> V_234 ) ;
F_31 ( V_12 , V_41 , V_3 -> V_42 ) ;
F_29 ( V_3 ) ;
}
static int F_159 ( struct V_13 * V_69 )
{
struct V_159 * V_175 = F_154 ( V_69 ) ;
struct V_11 * V_12 = F_149 ( V_175 ) ;
struct V_7 * V_8 , * V_232 ;
F_128 ( V_12 -> V_202 ) ;
F_31 ( V_12 , V_181 , V_230 ) ;
while ( F_56 ( V_12 , V_67 ) )
F_92 () ;
F_31 ( V_12 , V_237 , V_12 -> V_236 ) ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_36 ( V_8 ) ;
F_30 ( V_3 , V_153 , V_3 -> V_235 ) ;
if ( F_39 ( V_3 ) )
F_158 ( V_3 ) ;
}
return 0 ;
}
static int T_9 F_160 ( void )
{
return F_161 ( & V_238 , F_118 ) ;
}
static void T_10 F_162 ( void )
{
F_163 ( & V_238 ) ;
}
