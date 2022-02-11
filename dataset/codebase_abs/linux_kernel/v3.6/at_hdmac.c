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
static void
F_32 ( struct V_2 * V_3 , struct V_1 * V_10 )
{
struct V_43 * V_17 = & V_10 -> V_17 ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_8 , V_17 -> V_44 ) ;
if ( ! F_33 ( V_3 ) )
F_34 ( V_17 ) ;
F_22 ( & V_10 -> V_16 , & V_3 -> V_31 ) ;
F_35 ( & V_10 -> V_5 , & V_3 -> V_31 ) ;
if ( ! V_3 -> V_27 . V_45 ) {
struct V_13 * V_46 = F_36 ( & V_3 -> V_27 ) ;
if ( ! ( V_17 -> V_18 & V_47 ) ) {
if ( V_17 -> V_18 & V_48 )
F_37 ( V_46 ,
V_10 -> V_34 . V_49 ,
V_10 -> V_50 , V_51 ) ;
else
F_38 ( V_46 ,
V_10 -> V_34 . V_49 ,
V_10 -> V_50 , V_51 ) ;
}
if ( ! ( V_17 -> V_18 & V_52 ) ) {
if ( V_17 -> V_18 & V_53 )
F_37 ( V_46 ,
V_10 -> V_34 . V_54 ,
V_10 -> V_50 , V_55 ) ;
else
F_38 ( V_46 ,
V_10 -> V_34 . V_54 ,
V_10 -> V_50 , V_55 ) ;
}
}
if ( ! F_33 ( V_3 ) ) {
T_3 V_56 = V_17 -> V_56 ;
void * V_57 = V_17 -> V_58 ;
if ( V_56 )
V_56 ( V_57 ) ;
}
F_39 ( V_17 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_10 , * V_22 ;
F_10 ( V_59 ) ;
F_18 ( F_16 ( & V_3 -> V_27 ) , L_9 ) ;
F_41 ( F_27 ( V_3 ) ) ;
if ( ! F_42 ( & V_3 -> V_6 ) )
F_26 ( V_3 , F_3 ( V_3 ) ) ;
F_22 ( & V_3 -> V_4 , & V_59 ) ;
F_22 ( & V_3 -> V_6 , & V_3 -> V_4 ) ;
F_12 (desc, _desc, &list, desc_node)
F_32 ( V_3 , V_10 ) ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_10 , * V_22 ;
struct V_1 * V_30 ;
F_18 ( F_16 ( & V_3 -> V_27 ) , L_10 ) ;
F_12 (desc, _desc, &atchan->active_list, desc_node) {
if ( ! ( V_10 -> V_34 . V_60 & V_61 ) )
return;
F_21 (child, &desc->tx_list, desc_node)
if ( ! ( V_30 -> V_34 . V_60 & V_61 ) )
return;
F_32 ( V_3 , V_10 ) ;
}
}
static void F_44 ( struct V_2 * V_3 )
{
F_18 ( F_16 ( & V_3 -> V_27 ) , L_11 ) ;
if ( F_42 ( & V_3 -> V_4 ) ||
F_45 ( & V_3 -> V_4 ) ) {
F_40 ( V_3 ) ;
} else {
F_32 ( V_3 , F_1 ( V_3 ) ) ;
F_26 ( V_3 , F_1 ( V_3 ) ) ;
}
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_62 ;
struct V_1 * V_30 ;
V_62 = F_1 ( V_3 ) ;
F_47 ( & V_62 -> V_5 ) ;
F_22 ( & V_3 -> V_6 , V_3 -> V_4 . V_33 ) ;
if ( ! F_42 ( & V_3 -> V_4 ) )
F_26 ( V_3 , F_1 ( V_3 ) ) ;
F_48 ( F_16 ( & V_3 -> V_27 ) ,
L_12 ) ;
F_48 ( F_16 ( & V_3 -> V_27 ) ,
L_13 , V_62 -> V_17 . V_44 ) ;
F_49 ( V_3 , & V_62 -> V_34 ) ;
F_21 (child, &bad_desc->tx_list, desc_node)
F_49 ( V_3 , & V_30 -> V_34 ) ;
F_32 ( V_3 , V_62 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_43 * V_17 = & V_32 -> V_17 ;
T_3 V_56 = V_17 -> V_56 ;
void * V_57 = V_17 -> V_58 ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_14 ,
F_28 ( V_3 , V_40 ) ) ;
if ( V_56 )
V_56 ( V_57 ) ;
}
static void F_51 ( unsigned long V_63 )
{
struct V_2 * V_3 = (struct V_2 * ) V_63 ;
unsigned long V_18 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
if ( F_52 ( V_64 , & V_3 -> V_65 ) )
F_46 ( V_3 ) ;
else if ( F_33 ( V_3 ) )
F_50 ( V_3 ) ;
else
F_44 ( V_3 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
}
static T_4 F_53 ( int V_66 , void * V_67 )
{
struct V_11 * V_12 = (struct V_11 * ) V_67 ;
struct V_2 * V_3 ;
int V_24 ;
T_5 V_65 , V_68 , V_69 ;
int V_23 = V_70 ;
do {
V_69 = F_54 ( V_12 , V_71 ) ;
V_65 = F_54 ( V_12 , V_72 ) ;
V_68 = V_65 & V_69 ;
if ( ! V_68 )
break;
F_18 ( V_12 -> V_73 . V_74 ,
L_15 ,
V_65 , V_69 , V_68 ) ;
for ( V_24 = 0 ; V_24 < V_12 -> V_73 . V_75 ; V_24 ++ ) {
V_3 = & V_12 -> V_8 [ V_24 ] ;
if ( V_68 & ( F_55 ( V_24 ) | F_56 ( V_24 ) ) ) {
if ( V_68 & F_56 ( V_24 ) ) {
F_31 ( V_12 , V_76 ,
F_57 ( V_24 ) | V_3 -> V_42 ) ;
F_58 ( V_64 , & V_3 -> V_65 ) ;
}
F_59 ( & V_3 -> V_77 ) ;
V_23 = V_78 ;
}
}
} while ( V_68 );
return V_23 ;
}
static T_6 V_21 ( struct V_43 * V_79 )
{
struct V_1 * V_10 = F_60 ( V_79 ) ;
struct V_2 * V_3 = F_61 ( V_79 -> V_8 ) ;
T_6 V_44 ;
unsigned long V_18 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_44 = F_62 ( V_79 ) ;
if ( F_42 ( & V_3 -> V_4 ) ) {
F_18 ( F_16 ( V_79 -> V_8 ) , L_16 ,
V_10 -> V_17 . V_44 ) ;
F_26 ( V_3 , V_10 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_4 ) ;
} else {
F_18 ( F_16 ( V_79 -> V_8 ) , L_17 ,
V_10 -> V_17 . V_44 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_6 ) ;
}
F_17 ( & V_3 -> V_26 , V_18 ) ;
return V_44 ;
}
static struct V_43 *
F_63 ( struct V_7 * V_8 , T_2 V_80 , T_2 V_81 ,
T_7 V_50 , unsigned long V_18 )
{
struct V_2 * V_3 = F_61 ( V_8 ) ;
struct V_1 * V_10 = NULL ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_7 V_82 ;
T_7 V_83 ;
unsigned int V_84 ;
unsigned int V_85 ;
T_5 V_60 ;
T_5 V_86 ;
F_18 ( F_16 ( V_8 ) , L_18 ,
V_80 , V_81 , V_50 , V_18 ) ;
if ( F_64 ( ! V_50 ) ) {
F_15 ( F_16 ( V_8 ) , L_19 ) ;
return NULL ;
}
V_86 = V_87 | V_88
| V_89
| V_90
| V_91 ;
if ( ! ( ( V_81 | V_80 | V_50 ) & 3 ) ) {
V_60 = V_92 | V_93 ;
V_84 = V_85 = 2 ;
} else if ( ! ( ( V_81 | V_80 | V_50 ) & 1 ) ) {
V_60 = V_94 | V_95 ;
V_84 = V_85 = 1 ;
} else {
V_60 = V_96 | V_97 ;
V_84 = V_85 = 0 ;
}
for ( V_83 = 0 ; V_83 < V_50 ; V_83 += V_82 << V_84 ) {
V_82 = F_65 ( T_7 , ( V_50 - V_83 ) >> V_84 ,
V_98 ) ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_99;
V_10 -> V_34 . V_54 = V_81 + V_83 ;
V_10 -> V_34 . V_49 = V_80 + V_83 ;
V_10 -> V_34 . V_60 = V_60 | V_82 ;
V_10 -> V_34 . V_86 = V_86 ;
V_10 -> V_17 . V_44 = 0 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_32 -> V_17 . V_44 = - V_100 ;
V_32 -> V_50 = V_50 ;
F_66 ( V_10 ) ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_99:
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static struct V_43 *
F_67 ( struct V_7 * V_8 , struct V_101 * V_102 ,
unsigned int V_103 , enum V_104 V_105 ,
unsigned long V_18 , void * V_106 )
{
struct V_2 * V_3 = F_61 ( V_8 ) ;
struct V_107 * V_108 = V_8 -> V_45 ;
struct V_109 * V_110 = & V_3 -> V_111 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_5 V_60 ;
T_5 V_86 ;
T_2 V_112 ;
unsigned int V_113 ;
unsigned int V_114 ;
unsigned int V_24 ;
struct V_101 * V_115 ;
T_7 V_116 = 0 ;
F_18 ( F_16 ( V_8 ) , L_20 ,
V_103 ,
V_105 == V_117 ? L_21 : L_22 ,
V_18 ) ;
if ( F_64 ( ! V_108 || ! V_103 ) ) {
F_15 ( F_16 ( V_8 ) , L_23 ) ;
return NULL ;
}
V_60 = F_68 ( V_110 -> V_118 )
| F_69 ( V_110 -> V_119 ) ;
V_86 = V_88 ;
switch ( V_105 ) {
case V_117 :
V_113 = F_70 ( V_110 -> V_120 ) ;
V_60 |= F_71 ( V_113 ) ;
V_86 |= V_121
| V_89
| V_122
| F_72 ( V_123 ) | F_73 ( V_124 ) ;
V_112 = V_110 -> V_125 ;
F_74 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_5 V_50 ;
T_5 V_126 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_99;
V_126 = F_75 ( V_115 ) ;
V_50 = F_76 ( V_115 ) ;
if ( F_64 ( ! V_50 ) ) {
F_15 ( F_16 ( V_8 ) ,
L_24 , V_24 ) ;
goto V_127;
}
V_114 = 2 ;
if ( F_64 ( V_126 & 3 || V_50 & 3 ) )
V_114 = 0 ;
V_10 -> V_34 . V_54 = V_126 ;
V_10 -> V_34 . V_49 = V_112 ;
V_10 -> V_34 . V_60 = V_60
| F_77 ( V_114 )
| V_50 >> V_114 ;
V_10 -> V_34 . V_86 = V_86 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_116 += V_50 ;
}
break;
case V_128 :
V_113 = F_70 ( V_110 -> V_129 ) ;
V_60 |= F_77 ( V_113 ) ;
V_86 |= V_90
| V_130
| V_131
| F_72 ( V_124 ) | F_73 ( V_123 ) ;
V_112 = V_110 -> V_132 ;
F_74 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_5 V_50 ;
T_5 V_126 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_99;
V_126 = F_75 ( V_115 ) ;
V_50 = F_76 ( V_115 ) ;
if ( F_64 ( ! V_50 ) ) {
F_15 ( F_16 ( V_8 ) ,
L_24 , V_24 ) ;
goto V_127;
}
V_114 = 2 ;
if ( F_64 ( V_126 & 3 || V_50 & 3 ) )
V_114 = 0 ;
V_10 -> V_34 . V_54 = V_112 ;
V_10 -> V_34 . V_49 = V_126 ;
V_10 -> V_34 . V_60 = V_60
| F_71 ( V_114 )
| V_50 >> V_113 ;
V_10 -> V_34 . V_86 = V_86 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_116 += V_50 ;
}
break;
default:
return NULL ;
}
F_66 ( V_33 ) ;
V_32 -> V_17 . V_44 = - V_100 ;
V_32 -> V_50 = V_116 ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_99:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
V_127:
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static int
F_78 ( unsigned int V_113 , T_2 V_133 ,
T_7 V_134 , enum V_104 V_105 )
{
if ( V_134 > ( V_98 << V_113 ) )
goto V_135;
if ( F_64 ( V_134 & ( ( 1 << V_113 ) - 1 ) ) )
goto V_135;
if ( F_64 ( V_133 & ( ( 1 << V_113 ) - 1 ) ) )
goto V_135;
if ( F_64 ( ! ( V_105 & ( V_128 | V_117 ) ) ) )
goto V_135;
return 0 ;
V_135:
return - V_136 ;
}
static int
F_79 ( struct V_7 * V_8 , struct V_1 * V_10 ,
unsigned int V_137 , T_2 V_133 ,
unsigned int V_113 , T_7 V_134 ,
enum V_104 V_105 )
{
struct V_2 * V_3 = F_61 ( V_8 ) ;
struct V_109 * V_110 = & V_3 -> V_111 ;
T_5 V_60 ;
V_60 = F_68 ( V_110 -> V_118 )
| F_69 ( V_110 -> V_119 )
| F_71 ( V_113 )
| F_77 ( V_113 )
| V_134 >> V_113 ;
switch ( V_105 ) {
case V_117 :
V_10 -> V_34 . V_54 = V_133 + ( V_134 * V_137 ) ;
V_10 -> V_34 . V_49 = V_110 -> V_125 ;
V_10 -> V_34 . V_60 = V_60 ;
V_10 -> V_34 . V_86 = V_121
| V_89
| V_122
| F_72 ( V_123 )
| F_73 ( V_124 ) ;
break;
case V_128 :
V_10 -> V_34 . V_54 = V_110 -> V_132 ;
V_10 -> V_34 . V_49 = V_133 + ( V_134 * V_137 ) ;
V_10 -> V_34 . V_60 = V_60 ;
V_10 -> V_34 . V_86 = V_90
| V_130
| V_131
| F_72 ( V_124 )
| F_73 ( V_123 ) ;
break;
default:
return - V_136 ;
}
return 0 ;
}
static struct V_43 *
F_80 ( struct V_7 * V_8 , T_2 V_133 , T_7 V_138 ,
T_7 V_134 , enum V_104 V_105 ,
void * V_106 )
{
struct V_2 * V_3 = F_61 ( V_8 ) ;
struct V_107 * V_108 = V_8 -> V_45 ;
struct V_109 * V_110 = & V_3 -> V_111 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
unsigned long V_139 ;
unsigned int V_113 ;
unsigned int V_140 = V_138 / V_134 ;
unsigned int V_24 ;
F_18 ( F_16 ( V_8 ) , L_25 ,
V_105 == V_117 ? L_21 : L_22 ,
V_133 ,
V_140 , V_138 , V_134 ) ;
if ( F_64 ( ! V_108 || ! V_138 || ! V_134 ) ) {
F_15 ( F_16 ( V_8 ) , L_26 ) ;
return NULL ;
}
V_139 = F_81 ( V_141 , & V_3 -> V_65 ) ;
if ( V_139 ) {
F_15 ( F_16 ( V_8 ) , L_27 ) ;
return NULL ;
}
if ( V_110 -> V_105 == V_117 )
V_113 = F_70 ( V_110 -> V_120 ) ;
else
V_113 = F_70 ( V_110 -> V_129 ) ;
if ( F_78 ( V_113 , V_133 ,
V_134 , V_105 ) )
goto V_135;
for ( V_24 = 0 ; V_24 < V_140 ; V_24 ++ ) {
struct V_1 * V_10 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_99;
if ( F_79 ( V_8 , V_10 , V_24 , V_133 ,
V_113 , V_134 , V_105 ) )
goto V_99;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_33 -> V_34 . V_35 = V_32 -> V_17 . V_14 ;
V_32 -> V_17 . V_44 = - V_100 ;
V_32 -> V_50 = V_138 ;
return & V_32 -> V_17 ;
V_99:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
F_20 ( V_3 , V_32 ) ;
V_135:
F_82 ( V_141 , & V_3 -> V_65 ) ;
return NULL ;
}
static int F_83 ( struct V_7 * V_8 ,
struct V_109 * V_110 )
{
struct V_2 * V_3 = F_61 ( V_8 ) ;
if ( ! V_8 -> V_45 )
return - V_136 ;
memcpy ( & V_3 -> V_111 , V_110 , sizeof( * V_110 ) ) ;
F_84 ( & V_3 -> V_111 . V_118 ) ;
F_84 ( & V_3 -> V_111 . V_119 ) ;
return 0 ;
}
static int F_85 ( struct V_7 * V_8 , enum V_142 V_143 ,
unsigned long V_144 )
{
struct V_2 * V_3 = F_61 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
int V_145 = V_3 -> V_27 . V_145 ;
unsigned long V_18 ;
F_10 ( V_59 ) ;
F_18 ( F_16 ( V_8 ) , L_28 , V_143 ) ;
if ( V_143 == V_146 ) {
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_41 , F_86 ( V_145 ) ) ;
F_58 ( V_147 , & V_3 -> V_65 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else if ( V_143 == V_148 ) {
if ( ! F_87 ( V_3 ) )
return 0 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_76 , F_57 ( V_145 ) ) ;
F_82 ( V_147 , & V_3 -> V_65 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else if ( V_143 == V_149 ) {
struct V_1 * V_10 , * V_22 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_76 , F_57 ( V_145 ) | V_3 -> V_42 ) ;
while ( F_54 ( V_12 , V_150 ) & V_3 -> V_42 )
F_88 () ;
F_22 ( & V_3 -> V_6 , & V_59 ) ;
F_22 ( & V_3 -> V_4 , & V_59 ) ;
F_12 (desc, _desc, &list, desc_node)
F_32 ( V_3 , V_10 ) ;
F_82 ( V_147 , & V_3 -> V_65 ) ;
F_82 ( V_141 , & V_3 -> V_65 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else if ( V_143 == V_151 ) {
return F_83 ( V_8 , (struct V_109 * ) V_144 ) ;
} else {
return - V_152 ;
}
return 0 ;
}
static enum V_153
F_89 ( struct V_7 * V_8 ,
T_6 V_44 ,
struct V_154 * V_155 )
{
struct V_2 * V_3 = F_61 ( V_8 ) ;
T_6 V_156 ;
T_6 V_157 ;
unsigned long V_18 ;
enum V_153 V_23 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_23 = F_90 ( V_8 , V_44 , V_155 ) ;
if ( V_23 != V_158 ) {
F_43 ( V_3 ) ;
V_23 = F_90 ( V_8 , V_44 , V_155 ) ;
}
V_157 = V_8 -> V_159 ;
V_156 = V_8 -> V_44 ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
if ( V_23 != V_158 )
F_91 ( V_155 , F_1 ( V_3 ) -> V_50 ) ;
if ( F_87 ( V_3 ) )
V_23 = V_160 ;
F_18 ( F_16 ( V_8 ) , L_29 ,
V_23 , V_44 , V_157 ? V_157 : 0 ,
V_156 ? V_156 : 0 ) ;
return V_23 ;
}
static void F_92 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_61 ( V_8 ) ;
unsigned long V_18 ;
F_18 ( F_16 ( V_8 ) , L_30 ) ;
if ( F_33 ( V_3 ) )
return;
F_11 ( & V_3 -> V_26 , V_18 ) ;
if ( ! F_27 ( V_3 ) ) {
F_44 ( V_3 ) ;
}
F_17 ( & V_3 -> V_26 , V_18 ) ;
}
static int F_93 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_61 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 ;
struct V_107 * V_108 ;
unsigned long V_18 ;
int V_24 ;
T_5 V_161 ;
F_10 ( V_25 ) ;
F_18 ( F_16 ( V_8 ) , L_31 ) ;
if ( F_27 ( V_3 ) ) {
F_15 ( F_16 ( V_8 ) , L_32 ) ;
return - V_162 ;
}
V_161 = V_163 ;
V_108 = V_8 -> V_45 ;
if ( V_108 ) {
F_41 ( ! V_108 -> V_164 || V_108 -> V_164 != V_12 -> V_73 . V_74 ) ;
if ( V_108 -> V_161 )
V_161 = V_108 -> V_161 ;
}
if ( ! F_42 ( & V_3 -> V_31 ) )
return V_3 -> V_29 ;
for ( V_24 = 0 ; V_24 < V_165 ; V_24 ++ ) {
V_10 = F_4 ( V_8 , V_166 ) ;
if ( ! V_10 ) {
F_19 ( V_12 -> V_73 . V_74 ,
L_33 , V_24 ) ;
break;
}
F_25 ( & V_10 -> V_5 , & V_25 ) ;
}
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_3 -> V_29 = V_24 ;
F_94 ( & V_25 , & V_3 -> V_31 ) ;
F_95 ( V_8 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
F_30 ( V_3 , V_167 , V_161 ) ;
F_15 ( F_16 ( V_8 ) ,
L_34 ,
V_3 -> V_29 ) ;
return V_3 -> V_29 ;
}
static void F_96 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_61 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 , * V_22 ;
F_10 ( V_59 ) ;
F_15 ( F_16 ( V_8 ) , L_35 ,
V_3 -> V_29 ) ;
F_41 ( ! F_42 ( & V_3 -> V_4 ) ) ;
F_41 ( ! F_42 ( & V_3 -> V_6 ) ) ;
F_41 ( F_27 ( V_3 ) ) ;
F_12 (desc, _desc, &atchan->free_list, desc_node) {
F_18 ( F_16 ( V_8 ) , L_36 , V_10 ) ;
F_14 ( & V_10 -> V_5 ) ;
F_97 ( V_12 -> V_15 , V_10 , V_10 -> V_17 . V_14 ) ;
}
F_22 ( & V_3 -> V_31 , & V_59 ) ;
V_3 -> V_29 = 0 ;
V_3 -> V_65 = 0 ;
F_18 ( F_16 ( V_8 ) , L_37 ) ;
}
static inline const struct V_168 * T_8 F_98 (
struct V_169 * V_170 )
{
if ( V_170 -> V_74 . V_171 ) {
const struct V_172 * V_173 ;
V_173 = F_99 ( V_174 , V_170 -> V_74 . V_171 ) ;
if ( V_173 == NULL )
return NULL ;
return V_173 -> V_63 ;
}
return (struct V_168 * )
F_100 ( V_170 ) -> V_175 ;
}
static void F_101 ( struct V_11 * V_12 )
{
F_31 ( V_12 , V_176 , 0 ) ;
F_31 ( V_12 , V_177 , - 1L ) ;
while ( F_54 ( V_12 , V_150 ) & V_12 -> V_178 )
F_88 () ;
}
static int T_8 F_102 ( struct V_169 * V_170 )
{
struct V_179 * V_180 ;
struct V_11 * V_12 ;
T_7 V_181 ;
int V_66 ;
int V_127 ;
int V_24 ;
const struct V_168 * V_182 ;
F_103 ( V_183 , V_184 . V_185 ) ;
F_103 ( V_183 , V_186 . V_185 ) ;
F_103 ( V_187 , V_186 . V_185 ) ;
V_182 = F_98 ( V_170 ) ;
if ( ! V_182 )
return - V_188 ;
V_180 = F_104 ( V_170 , V_189 , 0 ) ;
if ( ! V_180 )
return - V_136 ;
V_66 = F_105 ( V_170 , 0 ) ;
if ( V_66 < 0 )
return V_66 ;
V_181 = sizeof( struct V_11 ) ;
V_181 += V_182 -> V_190 * sizeof( struct V_2 ) ;
V_12 = F_106 ( V_181 , V_166 ) ;
if ( ! V_12 )
return - V_191 ;
V_12 -> V_73 . V_185 = V_182 -> V_185 ;
V_12 -> V_178 = ( 1 << V_182 -> V_190 ) - 1 ;
V_181 = F_107 ( V_180 ) ;
if ( ! F_108 ( V_180 -> V_192 , V_181 , V_170 -> V_74 . V_193 -> V_194 ) ) {
V_127 = - V_100 ;
goto V_195;
}
V_12 -> V_196 = F_109 ( V_180 -> V_192 , V_181 ) ;
if ( ! V_12 -> V_196 ) {
V_127 = - V_191 ;
goto V_197;
}
V_12 -> V_198 = F_110 ( & V_170 -> V_74 , L_38 ) ;
if ( F_111 ( V_12 -> V_198 ) ) {
V_127 = F_112 ( V_12 -> V_198 ) ;
goto V_199;
}
F_113 ( V_12 -> V_198 ) ;
F_101 ( V_12 ) ;
V_127 = F_114 ( V_66 , F_53 , 0 , L_39 , V_12 ) ;
if ( V_127 )
goto V_200;
F_115 ( V_170 , V_12 ) ;
V_12 -> V_15 = F_116 ( L_40 ,
& V_170 -> V_74 , sizeof( struct V_1 ) ,
4 , 0 ) ;
if ( ! V_12 -> V_15 ) {
F_19 ( & V_170 -> V_74 , L_41 ) ;
V_127 = - V_191 ;
goto V_201;
}
while ( F_54 ( V_12 , V_72 ) )
F_88 () ;
F_7 ( & V_12 -> V_73 . V_202 ) ;
for ( V_24 = 0 ; V_24 < V_182 -> V_190 ; V_24 ++ ) {
struct V_2 * V_3 = & V_12 -> V_8 [ V_24 ] ;
V_3 -> V_27 . V_13 = & V_12 -> V_73 ;
F_95 ( & V_3 -> V_27 ) ;
F_25 ( & V_3 -> V_27 . V_203 ,
& V_12 -> V_73 . V_202 ) ;
V_3 -> V_204 = V_12 -> V_196 + V_204 ( V_24 ) ;
F_117 ( & V_3 -> V_26 ) ;
V_3 -> V_42 = 1 << V_24 ;
F_7 ( & V_3 -> V_4 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_7 ( & V_3 -> V_31 ) ;
F_118 ( & V_3 -> V_77 , F_51 ,
( unsigned long ) V_3 ) ;
F_119 ( V_12 , V_24 ) ;
}
V_12 -> V_73 . V_205 = F_93 ;
V_12 -> V_73 . V_206 = F_96 ;
V_12 -> V_73 . V_207 = F_89 ;
V_12 -> V_73 . V_208 = F_92 ;
V_12 -> V_73 . V_74 = & V_170 -> V_74 ;
if ( F_120 ( V_183 , V_12 -> V_73 . V_185 ) )
V_12 -> V_73 . V_209 = F_63 ;
if ( F_120 ( V_187 , V_12 -> V_73 . V_185 ) ) {
V_12 -> V_73 . V_210 = F_67 ;
F_103 ( V_211 , V_12 -> V_73 . V_185 ) ;
V_12 -> V_73 . V_212 = F_80 ;
V_12 -> V_73 . V_213 = F_85 ;
}
F_31 ( V_12 , V_176 , V_214 ) ;
F_121 ( & V_170 -> V_74 , L_42 ,
F_120 ( V_183 , V_12 -> V_73 . V_185 ) ? L_43 : L_44 ,
F_120 ( V_187 , V_12 -> V_73 . V_185 ) ? L_45 : L_44 ,
V_182 -> V_190 ) ;
F_122 ( & V_12 -> V_73 ) ;
return 0 ;
V_201:
F_115 ( V_170 , NULL ) ;
F_123 ( F_105 ( V_170 , 0 ) , V_12 ) ;
V_200:
F_124 ( V_12 -> V_198 ) ;
F_125 ( V_12 -> V_198 ) ;
V_199:
F_126 ( V_12 -> V_196 ) ;
V_12 -> V_196 = NULL ;
V_197:
F_127 ( V_180 -> V_192 , V_181 ) ;
V_195:
F_128 ( V_12 ) ;
return V_127 ;
}
static int T_9 F_129 ( struct V_169 * V_170 )
{
struct V_11 * V_12 = F_130 ( V_170 ) ;
struct V_7 * V_8 , * V_215 ;
struct V_179 * V_180 ;
F_101 ( V_12 ) ;
F_131 ( & V_12 -> V_73 ) ;
F_132 ( V_12 -> V_15 ) ;
F_115 ( V_170 , NULL ) ;
F_123 ( F_105 ( V_170 , 0 ) , V_12 ) ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_61 ( V_8 ) ;
F_133 ( V_12 , V_8 -> V_145 ) ;
F_134 ( & V_3 -> V_77 ) ;
F_135 ( & V_3 -> V_77 ) ;
F_14 ( & V_8 -> V_203 ) ;
}
F_124 ( V_12 -> V_198 ) ;
F_125 ( V_12 -> V_198 ) ;
F_126 ( V_12 -> V_196 ) ;
V_12 -> V_196 = NULL ;
V_180 = F_104 ( V_170 , V_189 , 0 ) ;
F_127 ( V_180 -> V_192 , F_107 ( V_180 ) ) ;
F_128 ( V_12 ) ;
return 0 ;
}
static void F_136 ( struct V_169 * V_170 )
{
struct V_11 * V_12 = F_130 ( V_170 ) ;
F_101 ( F_130 ( V_170 ) ) ;
F_124 ( V_12 -> V_198 ) ;
}
static int F_137 ( struct V_13 * V_74 )
{
struct V_169 * V_170 = F_138 ( V_74 ) ;
struct V_11 * V_12 = F_130 ( V_170 ) ;
struct V_7 * V_8 , * V_215 ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_61 ( V_8 ) ;
if ( F_27 ( V_3 ) && ! F_33 ( V_3 ) )
return - V_216 ;
}
return 0 ;
}
static void F_139 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = & V_3 -> V_27 ;
if ( ! F_87 ( V_3 ) ) {
F_140 ( F_16 ( V_8 ) ,
L_46 ) ;
F_85 ( V_8 , V_146 , 0 ) ;
}
V_3 -> V_217 = F_28 ( V_3 , V_40 ) ;
F_29 ( V_3 ) ;
}
static int F_141 ( struct V_13 * V_74 )
{
struct V_169 * V_170 = F_138 ( V_74 ) ;
struct V_11 * V_12 = F_130 ( V_170 ) ;
struct V_7 * V_8 , * V_215 ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_61 ( V_8 ) ;
if ( F_33 ( V_3 ) )
F_139 ( V_3 ) ;
V_3 -> V_218 = F_28 ( V_3 , V_167 ) ;
}
V_12 -> V_219 = F_54 ( V_12 , V_71 ) ;
F_101 ( V_12 ) ;
F_124 ( V_12 -> V_198 ) ;
return 0 ;
}
static void F_142 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_5 ( V_3 -> V_27 . V_13 ) ;
F_30 ( V_3 , V_36 , 0 ) ;
F_30 ( V_3 , V_37 , 0 ) ;
F_30 ( V_3 , V_38 , 0 ) ;
F_30 ( V_3 , V_39 , 0 ) ;
F_30 ( V_3 , V_40 , V_3 -> V_217 ) ;
F_31 ( V_12 , V_41 , V_3 -> V_42 ) ;
F_29 ( V_3 ) ;
}
static int F_143 ( struct V_13 * V_74 )
{
struct V_169 * V_170 = F_138 ( V_74 ) ;
struct V_11 * V_12 = F_130 ( V_170 ) ;
struct V_7 * V_8 , * V_215 ;
F_113 ( V_12 -> V_198 ) ;
F_31 ( V_12 , V_176 , V_214 ) ;
while ( F_54 ( V_12 , V_72 ) )
F_88 () ;
F_31 ( V_12 , V_220 , V_12 -> V_219 ) ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_61 ( V_8 ) ;
F_30 ( V_3 , V_167 , V_3 -> V_218 ) ;
if ( F_33 ( V_3 ) )
F_142 ( V_3 ) ;
}
return 0 ;
}
static int T_8 F_144 ( void )
{
return F_145 ( & V_221 , F_102 ) ;
}
static void T_9 F_146 ( void )
{
F_147 ( & V_221 ) ;
}
