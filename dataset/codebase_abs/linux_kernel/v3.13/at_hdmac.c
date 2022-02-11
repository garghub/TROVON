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
struct V_1 * V_10 , * V_22 , * V_30 , * V_44 = NULL ;
F_12 (desc, _desc, &atchan->active_list, desc_node) {
if ( V_10 -> V_34 . V_35 == V_43 ) {
V_44 = V_10 ;
break;
}
F_21 (child, &desc->tx_list, desc_node) {
if ( V_30 -> V_34 . V_35 == V_43 ) {
V_44 = V_30 ;
break;
}
}
}
return V_44 ;
}
static int F_33 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
int V_45 = V_3 -> V_27 . V_45 ;
struct V_1 * V_46 = F_1 ( V_3 ) ;
struct V_1 * V_44 ;
int V_23 = 0 , V_47 = 0 ;
if ( V_3 -> V_48 == 0 )
V_3 -> V_48 = V_46 -> V_49 ;
if ( F_35 ( F_36 ( V_50 , & V_3 -> V_51 ) ) ) {
F_37 ( V_50 , & V_3 -> V_51 ) ;
V_44 = F_32 ( V_3 ,
F_28 ( V_3 , V_40 ) ) ;
if ( ! V_44 ) {
V_23 = - V_52 ;
goto V_53;
}
V_3 -> V_48 -= ( V_44 -> V_34 . V_54 & V_55 )
<< ( V_46 -> V_56 ) ;
if ( V_3 -> V_48 < 0 ) {
V_23 = - V_52 ;
goto V_53;
} else {
V_23 = V_3 -> V_48 ;
}
} else {
V_47 = ( F_28 ( V_3 , V_38 ) & V_55 )
<< ( V_46 -> V_56 ) ;
V_23 = V_3 -> V_48 - V_47 ;
}
if ( ! ( F_38 ( V_12 , V_57 ) & F_39 ( V_45 ) ) )
F_40 ( V_8 ) ;
V_53:
return V_23 ;
}
static void
F_41 ( struct V_2 * V_3 , struct V_1 * V_10 )
{
struct V_58 * V_17 = & V_10 -> V_17 ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_8 , V_17 -> V_59 ) ;
if ( ! F_42 ( V_3 ) )
F_43 ( V_17 ) ;
F_22 ( & V_10 -> V_16 , & V_3 -> V_31 ) ;
F_44 ( & V_10 -> V_5 , & V_3 -> V_31 ) ;
F_45 ( V_17 ) ;
if ( ! F_42 ( V_3 ) ) {
T_4 V_60 = V_17 -> V_60 ;
void * V_61 = V_17 -> V_62 ;
if ( V_60 )
V_60 ( V_61 ) ;
}
F_46 ( V_17 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_10 , * V_22 ;
F_10 ( V_63 ) ;
F_18 ( F_16 ( & V_3 -> V_27 ) , L_9 ) ;
if ( ! F_48 ( & V_3 -> V_6 ) )
F_26 ( V_3 , F_3 ( V_3 ) ) ;
F_22 ( & V_3 -> V_4 , & V_63 ) ;
F_22 ( & V_3 -> V_6 , & V_3 -> V_4 ) ;
F_12 (desc, _desc, &list, desc_node)
F_41 ( V_3 , V_10 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
F_18 ( F_16 ( & V_3 -> V_27 ) , L_10 ) ;
if ( F_27 ( V_3 ) )
return;
if ( F_48 ( & V_3 -> V_4 ) ||
F_50 ( & V_3 -> V_4 ) ) {
F_47 ( V_3 ) ;
} else {
F_41 ( V_3 , F_1 ( V_3 ) ) ;
F_26 ( V_3 , F_1 ( V_3 ) ) ;
}
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_64 ;
struct V_1 * V_30 ;
V_64 = F_1 ( V_3 ) ;
F_52 ( & V_64 -> V_5 ) ;
F_22 ( & V_3 -> V_6 , V_3 -> V_4 . V_33 ) ;
if ( ! F_48 ( & V_3 -> V_4 ) )
F_26 ( V_3 , F_1 ( V_3 ) ) ;
F_53 ( F_16 ( & V_3 -> V_27 ) ,
L_11 ) ;
F_53 ( F_16 ( & V_3 -> V_27 ) ,
L_12 , V_64 -> V_17 . V_59 ) ;
F_54 ( V_3 , & V_64 -> V_34 ) ;
F_21 (child, &bad_desc->tx_list, desc_node)
F_54 ( V_3 , & V_30 -> V_34 ) ;
F_41 ( V_3 , V_64 ) ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_58 * V_17 = & V_32 -> V_17 ;
T_4 V_60 = V_17 -> V_60 ;
void * V_61 = V_17 -> V_62 ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_13 ,
F_28 ( V_3 , V_40 ) ) ;
if ( V_60 )
V_60 ( V_61 ) ;
}
static void F_56 ( unsigned long V_65 )
{
struct V_2 * V_3 = (struct V_2 * ) V_65 ;
unsigned long V_18 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
if ( F_57 ( V_66 , & V_3 -> V_51 ) )
F_51 ( V_3 ) ;
else if ( F_42 ( V_3 ) )
F_55 ( V_3 ) ;
else
F_49 ( V_3 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
}
static T_5 F_58 ( int V_67 , void * V_68 )
{
struct V_11 * V_12 = (struct V_11 * ) V_68 ;
struct V_2 * V_3 ;
int V_24 ;
T_3 V_51 , V_69 , V_70 ;
int V_23 = V_71 ;
do {
V_70 = F_38 ( V_12 , V_72 ) ;
V_51 = F_38 ( V_12 , V_73 ) ;
V_69 = V_51 & V_70 ;
if ( ! V_69 )
break;
F_18 ( V_12 -> V_74 . V_75 ,
L_14 ,
V_51 , V_70 , V_69 ) ;
for ( V_24 = 0 ; V_24 < V_12 -> V_74 . V_76 ; V_24 ++ ) {
V_3 = & V_12 -> V_8 [ V_24 ] ;
if ( V_69 & ( F_59 ( V_24 ) | F_60 ( V_24 ) ) ) {
if ( V_69 & F_60 ( V_24 ) ) {
F_31 ( V_12 , V_77 ,
F_61 ( V_24 ) | V_3 -> V_42 ) ;
F_62 ( V_66 , & V_3 -> V_51 ) ;
}
if ( V_69 & F_59 ( V_24 ) )
F_62 ( V_50 , & V_3 -> V_51 ) ;
F_63 ( & V_3 -> V_78 ) ;
V_23 = V_79 ;
}
}
} while ( V_69 );
return V_23 ;
}
static T_6 V_21 ( struct V_58 * V_80 )
{
struct V_1 * V_10 = F_64 ( V_80 ) ;
struct V_2 * V_3 = F_34 ( V_80 -> V_8 ) ;
T_6 V_59 ;
unsigned long V_18 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_59 = F_65 ( V_80 ) ;
if ( F_48 ( & V_3 -> V_4 ) ) {
F_18 ( F_16 ( V_80 -> V_8 ) , L_15 ,
V_10 -> V_17 . V_59 ) ;
F_26 ( V_3 , V_10 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_4 ) ;
} else {
F_18 ( F_16 ( V_80 -> V_8 ) , L_16 ,
V_10 -> V_17 . V_59 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_6 ) ;
}
F_17 ( & V_3 -> V_26 , V_18 ) ;
return V_59 ;
}
static struct V_58 *
F_66 ( struct V_7 * V_8 , T_2 V_81 , T_2 V_82 ,
T_7 V_49 , unsigned long V_18 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_1 * V_10 = NULL ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_7 V_83 ;
T_7 V_84 ;
unsigned int V_85 ;
unsigned int V_86 ;
T_3 V_54 ;
T_3 V_87 ;
F_18 ( F_16 ( V_8 ) , L_17 ,
V_81 , V_82 , V_49 , V_18 ) ;
if ( F_35 ( ! V_49 ) ) {
F_15 ( F_16 ( V_8 ) , L_18 ) ;
return NULL ;
}
V_87 = V_88 | V_89
| V_90
| V_91
| V_92 ;
if ( ! ( ( V_82 | V_81 | V_49 ) & 3 ) ) {
V_54 = V_93 | V_94 ;
V_85 = V_86 = 2 ;
} else if ( ! ( ( V_82 | V_81 | V_49 ) & 1 ) ) {
V_54 = V_95 | V_96 ;
V_85 = V_86 = 1 ;
} else {
V_54 = V_97 | V_98 ;
V_85 = V_86 = 0 ;
}
for ( V_84 = 0 ; V_84 < V_49 ; V_84 += V_83 << V_85 ) {
V_83 = F_67 ( T_7 , ( V_49 - V_84 ) >> V_85 ,
V_55 ) ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_99;
V_10 -> V_34 . V_100 = V_82 + V_84 ;
V_10 -> V_34 . V_101 = V_81 + V_84 ;
V_10 -> V_34 . V_54 = V_54 | V_83 ;
V_10 -> V_34 . V_87 = V_87 ;
V_10 -> V_17 . V_59 = 0 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_32 -> V_17 . V_59 = - V_102 ;
V_32 -> V_49 = V_49 ;
V_32 -> V_56 = V_85 ;
F_68 ( V_10 ) ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_99:
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static struct V_58 *
F_69 ( struct V_7 * V_8 , struct V_103 * V_104 ,
unsigned int V_105 , enum V_106 V_107 ,
unsigned long V_18 , void * V_108 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_109 * V_110 = V_8 -> V_111 ;
struct V_112 * V_113 = & V_3 -> V_114 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_3 V_54 ;
T_3 V_87 ;
T_2 V_115 ;
unsigned int V_116 ;
unsigned int V_117 ;
unsigned int V_24 ;
struct V_103 * V_118 ;
T_7 V_119 = 0 ;
F_18 ( F_16 ( V_8 ) , L_19 ,
V_105 ,
V_107 == V_120 ? L_20 : L_21 ,
V_18 ) ;
if ( F_35 ( ! V_110 || ! V_105 ) ) {
F_15 ( F_16 ( V_8 ) , L_22 ) ;
return NULL ;
}
V_54 = F_70 ( V_113 -> V_121 )
| F_71 ( V_113 -> V_122 ) ;
V_87 = V_89 ;
switch ( V_107 ) {
case V_120 :
V_116 = F_72 ( V_113 -> V_123 ) ;
V_54 |= F_73 ( V_116 ) ;
V_87 |= V_124
| V_90
| V_125
| F_74 ( V_3 -> V_126 ) | F_75 ( V_3 -> V_127 ) ;
V_115 = V_113 -> V_128 ;
F_76 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_3 V_49 ;
T_3 V_129 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_99;
V_129 = F_77 ( V_118 ) ;
V_49 = F_78 ( V_118 ) ;
if ( F_35 ( ! V_49 ) ) {
F_15 ( F_16 ( V_8 ) ,
L_23 , V_24 ) ;
goto V_130;
}
V_117 = 2 ;
if ( F_35 ( V_129 & 3 || V_49 & 3 ) )
V_117 = 0 ;
V_10 -> V_34 . V_100 = V_129 ;
V_10 -> V_34 . V_101 = V_115 ;
V_10 -> V_34 . V_54 = V_54
| F_79 ( V_117 )
| V_49 >> V_117 ;
V_10 -> V_34 . V_87 = V_87 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_119 += V_49 ;
}
break;
case V_131 :
V_116 = F_72 ( V_113 -> V_132 ) ;
V_54 |= F_79 ( V_116 ) ;
V_87 |= V_91
| V_133
| V_134
| F_74 ( V_3 -> V_127 ) | F_75 ( V_3 -> V_126 ) ;
V_115 = V_113 -> V_135 ;
F_76 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_3 V_49 ;
T_3 V_129 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_99;
V_129 = F_77 ( V_118 ) ;
V_49 = F_78 ( V_118 ) ;
if ( F_35 ( ! V_49 ) ) {
F_15 ( F_16 ( V_8 ) ,
L_23 , V_24 ) ;
goto V_130;
}
V_117 = 2 ;
if ( F_35 ( V_129 & 3 || V_49 & 3 ) )
V_117 = 0 ;
V_10 -> V_34 . V_100 = V_115 ;
V_10 -> V_34 . V_101 = V_129 ;
V_10 -> V_34 . V_54 = V_54
| F_73 ( V_117 )
| V_49 >> V_116 ;
V_10 -> V_34 . V_87 = V_87 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_119 += V_49 ;
}
break;
default:
return NULL ;
}
F_68 ( V_33 ) ;
V_32 -> V_17 . V_59 = - V_102 ;
V_32 -> V_49 = V_119 ;
V_32 -> V_56 = V_116 ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_99:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
V_130:
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static int
F_80 ( unsigned int V_116 , T_2 V_136 ,
T_7 V_137 )
{
if ( V_137 > ( V_55 << V_116 ) )
goto V_138;
if ( F_35 ( V_137 & ( ( 1 << V_116 ) - 1 ) ) )
goto V_138;
if ( F_35 ( V_136 & ( ( 1 << V_116 ) - 1 ) ) )
goto V_138;
return 0 ;
V_138:
return - V_52 ;
}
static int
F_81 ( struct V_7 * V_8 , struct V_1 * V_10 ,
unsigned int V_139 , T_2 V_136 ,
unsigned int V_116 , T_7 V_137 ,
enum V_106 V_107 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_112 * V_113 = & V_3 -> V_114 ;
T_3 V_54 ;
V_54 = F_70 ( V_113 -> V_121 )
| F_71 ( V_113 -> V_122 )
| F_73 ( V_116 )
| F_79 ( V_116 )
| V_137 >> V_116 ;
switch ( V_107 ) {
case V_120 :
V_10 -> V_34 . V_100 = V_136 + ( V_137 * V_139 ) ;
V_10 -> V_34 . V_101 = V_113 -> V_128 ;
V_10 -> V_34 . V_54 = V_54 ;
V_10 -> V_34 . V_87 = V_124
| V_90
| V_125
| F_74 ( V_3 -> V_126 )
| F_75 ( V_3 -> V_127 ) ;
break;
case V_131 :
V_10 -> V_34 . V_100 = V_113 -> V_135 ;
V_10 -> V_34 . V_101 = V_136 + ( V_137 * V_139 ) ;
V_10 -> V_34 . V_54 = V_54 ;
V_10 -> V_34 . V_87 = V_91
| V_133
| V_134
| F_74 ( V_3 -> V_127 )
| F_75 ( V_3 -> V_126 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static struct V_58 *
F_82 ( struct V_7 * V_8 , T_2 V_136 , T_7 V_140 ,
T_7 V_137 , enum V_106 V_107 ,
unsigned long V_18 , void * V_108 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_109 * V_110 = V_8 -> V_111 ;
struct V_112 * V_113 = & V_3 -> V_114 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
unsigned long V_141 ;
unsigned int V_116 ;
unsigned int V_142 = V_140 / V_137 ;
unsigned int V_24 ;
F_18 ( F_16 ( V_8 ) , L_24 ,
V_107 == V_120 ? L_20 : L_21 ,
V_136 ,
V_142 , V_140 , V_137 ) ;
if ( F_35 ( ! V_110 || ! V_140 || ! V_137 ) ) {
F_15 ( F_16 ( V_8 ) , L_25 ) ;
return NULL ;
}
V_141 = F_83 ( V_143 , & V_3 -> V_51 ) ;
if ( V_141 ) {
F_15 ( F_16 ( V_8 ) , L_26 ) ;
return NULL ;
}
if ( F_35 ( ! F_84 ( V_107 ) ) )
goto V_138;
if ( V_113 -> V_107 == V_120 )
V_116 = F_72 ( V_113 -> V_123 ) ;
else
V_116 = F_72 ( V_113 -> V_132 ) ;
if ( F_80 ( V_116 , V_136 , V_137 ) )
goto V_138;
for ( V_24 = 0 ; V_24 < V_142 ; V_24 ++ ) {
struct V_1 * V_10 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_99;
if ( F_81 ( V_8 , V_10 , V_24 , V_136 ,
V_116 , V_137 , V_107 ) )
goto V_99;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_33 -> V_34 . V_35 = V_32 -> V_17 . V_14 ;
V_32 -> V_17 . V_59 = - V_102 ;
V_32 -> V_49 = V_140 ;
V_32 -> V_56 = V_116 ;
return & V_32 -> V_17 ;
V_99:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
F_20 ( V_3 , V_32 ) ;
V_138:
F_37 ( V_143 , & V_3 -> V_51 ) ;
return NULL ;
}
static int F_85 ( struct V_7 * V_8 ,
struct V_112 * V_113 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
if ( ! V_8 -> V_111 )
return - V_52 ;
memcpy ( & V_3 -> V_114 , V_113 , sizeof( * V_113 ) ) ;
F_86 ( & V_3 -> V_114 . V_121 ) ;
F_86 ( & V_3 -> V_114 . V_122 ) ;
return 0 ;
}
static int F_87 ( struct V_7 * V_8 , enum V_144 V_145 ,
unsigned long V_146 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
int V_45 = V_3 -> V_27 . V_45 ;
unsigned long V_18 ;
F_10 ( V_63 ) ;
F_18 ( F_16 ( V_8 ) , L_27 , V_145 ) ;
if ( V_145 == V_147 ) {
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_41 , F_88 ( V_45 ) ) ;
F_62 ( V_148 , & V_3 -> V_51 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else if ( V_145 == V_149 ) {
if ( ! F_89 ( V_3 ) )
return 0 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_77 , F_61 ( V_45 ) ) ;
F_37 ( V_148 , & V_3 -> V_51 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else if ( V_145 == V_150 ) {
struct V_1 * V_10 , * V_22 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_77 , F_61 ( V_45 ) | V_3 -> V_42 ) ;
while ( F_38 ( V_12 , V_57 ) & V_3 -> V_42 )
F_90 () ;
F_22 ( & V_3 -> V_6 , & V_63 ) ;
F_22 ( & V_3 -> V_4 , & V_63 ) ;
F_12 (desc, _desc, &list, desc_node)
F_41 ( V_3 , V_10 ) ;
F_37 ( V_148 , & V_3 -> V_51 ) ;
F_37 ( V_143 , & V_3 -> V_51 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else if ( V_145 == V_151 ) {
return F_85 ( V_8 , (struct V_112 * ) V_146 ) ;
} else {
return - V_152 ;
}
return 0 ;
}
static enum V_153
F_91 ( struct V_7 * V_8 ,
T_6 V_59 ,
struct V_154 * V_155 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
unsigned long V_18 ;
enum V_153 V_23 ;
int V_156 = 0 ;
V_23 = F_92 ( V_8 , V_59 , V_155 ) ;
if ( V_23 == V_157 )
return V_23 ;
if ( ! V_155 )
return V_158 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_156 = F_33 ( V_8 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
if ( F_35 ( V_156 < 0 ) ) {
F_18 ( F_16 ( V_8 ) , L_28 ) ;
return V_158 ;
} else {
F_93 ( V_155 , V_156 ) ;
}
F_18 ( F_16 ( V_8 ) , L_29 ,
V_23 , V_59 , V_156 ) ;
return V_23 ;
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
unsigned long V_18 ;
F_18 ( F_16 ( V_8 ) , L_30 ) ;
if ( F_42 ( V_3 ) )
return;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_49 ( V_3 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
}
static int F_94 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 ;
struct V_109 * V_110 ;
unsigned long V_18 ;
int V_24 ;
T_3 V_159 ;
F_10 ( V_25 ) ;
F_18 ( F_16 ( V_8 ) , L_31 ) ;
if ( F_27 ( V_3 ) ) {
F_15 ( F_16 ( V_8 ) , L_32 ) ;
return - V_160 ;
}
V_159 = V_161 ;
V_110 = V_8 -> V_111 ;
if ( V_110 ) {
F_95 ( ! V_110 -> V_162 || V_110 -> V_162 != V_12 -> V_74 . V_75 ) ;
if ( V_110 -> V_159 )
V_159 = V_110 -> V_159 ;
}
if ( ! F_48 ( & V_3 -> V_31 ) )
return V_3 -> V_29 ;
for ( V_24 = 0 ; V_24 < V_163 ; V_24 ++ ) {
V_10 = F_4 ( V_8 , V_164 ) ;
if ( ! V_10 ) {
F_19 ( V_12 -> V_74 . V_75 ,
L_33 , V_24 ) ;
break;
}
F_25 ( & V_10 -> V_5 , & V_25 ) ;
}
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_3 -> V_29 = V_24 ;
V_3 -> V_48 = 0 ;
F_96 ( & V_25 , & V_3 -> V_31 ) ;
F_97 ( V_8 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
F_30 ( V_3 , V_165 , V_159 ) ;
F_15 ( F_16 ( V_8 ) ,
L_34 ,
V_3 -> V_29 ) ;
return V_3 -> V_29 ;
}
static void F_98 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 , * V_22 ;
F_10 ( V_63 ) ;
F_15 ( F_16 ( V_8 ) , L_35 ,
V_3 -> V_29 ) ;
F_95 ( ! F_48 ( & V_3 -> V_4 ) ) ;
F_95 ( ! F_48 ( & V_3 -> V_6 ) ) ;
F_95 ( F_27 ( V_3 ) ) ;
F_12 (desc, _desc, &atchan->free_list, desc_node) {
F_18 ( F_16 ( V_8 ) , L_36 , V_10 ) ;
F_14 ( & V_10 -> V_5 ) ;
F_99 ( V_12 -> V_15 , V_10 , V_10 -> V_17 . V_14 ) ;
}
F_22 ( & V_3 -> V_31 , & V_63 ) ;
V_3 -> V_29 = 0 ;
V_3 -> V_51 = 0 ;
V_3 -> V_48 = 0 ;
F_18 ( F_16 ( V_8 ) , L_37 ) ;
}
static bool F_100 ( struct V_7 * V_8 , void * V_166 )
{
struct V_109 * V_110 = V_166 ;
if ( V_110 -> V_162 == V_8 -> V_13 -> V_75 ) {
V_8 -> V_111 = V_110 ;
return true ;
} else {
return false ;
}
}
static struct V_7 * F_101 ( struct V_167 * V_168 ,
struct V_169 * V_169 )
{
struct V_7 * V_8 ;
struct V_2 * V_3 ;
struct V_109 * V_110 ;
T_8 V_42 ;
unsigned int V_170 ;
struct V_171 * V_172 ;
if ( V_168 -> V_173 != 2 )
return NULL ;
V_172 = F_102 ( V_168 -> V_174 ) ;
F_103 ( V_42 ) ;
F_104 ( V_175 , V_42 ) ;
V_110 = F_105 ( & V_172 -> V_75 , sizeof( * V_110 ) , V_164 ) ;
if ( ! V_110 )
return NULL ;
V_110 -> V_159 = V_176 | V_177 ;
V_170 = V_168 -> args [ 1 ] & V_178 ;
V_110 -> V_159 |= F_106 ( V_170 ) | F_107 ( V_170 )
| F_108 ( V_170 ) | F_109 ( V_170 ) ;
switch ( V_168 -> args [ 1 ] & V_179 ) {
case V_180 :
V_110 -> V_159 |= V_181 ;
break;
case V_182 :
V_110 -> V_159 |= V_183 ;
break;
case V_184 :
default:
V_110 -> V_159 |= V_185 ;
}
V_110 -> V_162 = & V_172 -> V_75 ;
V_8 = F_110 ( V_42 , F_100 , V_110 ) ;
if ( ! V_8 )
return NULL ;
V_3 = F_34 ( V_8 ) ;
V_3 -> V_127 = V_168 -> args [ 0 ] & 0xff ;
V_3 -> V_126 = ( V_168 -> args [ 0 ] >> 16 ) & 0xff ;
return V_8 ;
}
static struct V_7 * F_101 ( struct V_167 * V_168 ,
struct V_169 * V_169 )
{
return NULL ;
}
static inline const struct V_186 * T_9 F_111 (
struct V_171 * V_187 )
{
if ( V_187 -> V_75 . V_188 ) {
const struct V_189 * V_190 ;
V_190 = F_112 ( V_191 , V_187 -> V_75 . V_188 ) ;
if ( V_190 == NULL )
return NULL ;
return V_190 -> V_65 ;
}
return (struct V_186 * )
F_113 ( V_187 ) -> V_192 ;
}
static void F_114 ( struct V_11 * V_12 )
{
F_31 ( V_12 , V_193 , 0 ) ;
F_31 ( V_12 , V_194 , - 1L ) ;
while ( F_38 ( V_12 , V_57 ) & V_12 -> V_195 )
F_90 () ;
}
static int T_9 F_115 ( struct V_171 * V_187 )
{
struct V_196 * V_197 ;
struct V_11 * V_12 ;
T_7 V_198 ;
int V_67 ;
int V_130 ;
int V_24 ;
const struct V_186 * V_199 ;
F_104 ( V_200 , V_201 . V_202 ) ;
F_104 ( V_200 , V_203 . V_202 ) ;
F_104 ( V_175 , V_203 . V_202 ) ;
V_199 = F_111 ( V_187 ) ;
if ( ! V_199 )
return - V_204 ;
V_197 = F_116 ( V_187 , V_205 , 0 ) ;
if ( ! V_197 )
return - V_52 ;
V_67 = F_117 ( V_187 , 0 ) ;
if ( V_67 < 0 )
return V_67 ;
V_198 = sizeof( struct V_11 ) ;
V_198 += V_199 -> V_206 * sizeof( struct V_2 ) ;
V_12 = F_118 ( V_198 , V_164 ) ;
if ( ! V_12 )
return - V_207 ;
V_12 -> V_74 . V_202 = V_199 -> V_202 ;
V_12 -> V_195 = ( 1 << V_199 -> V_206 ) - 1 ;
V_198 = F_119 ( V_197 ) ;
if ( ! F_120 ( V_197 -> V_208 , V_198 , V_187 -> V_75 . V_209 -> V_210 ) ) {
V_130 = - V_102 ;
goto V_211;
}
V_12 -> V_212 = F_121 ( V_197 -> V_208 , V_198 ) ;
if ( ! V_12 -> V_212 ) {
V_130 = - V_207 ;
goto V_213;
}
V_12 -> V_214 = F_122 ( & V_187 -> V_75 , L_38 ) ;
if ( F_123 ( V_12 -> V_214 ) ) {
V_130 = F_124 ( V_12 -> V_214 ) ;
goto V_215;
}
V_130 = F_125 ( V_12 -> V_214 ) ;
if ( V_130 )
goto V_216;
F_114 ( V_12 ) ;
V_130 = F_126 ( V_67 , F_58 , 0 , L_39 , V_12 ) ;
if ( V_130 )
goto V_217;
F_127 ( V_187 , V_12 ) ;
V_12 -> V_15 = F_128 ( L_40 ,
& V_187 -> V_75 , sizeof( struct V_1 ) ,
4 , 0 ) ;
if ( ! V_12 -> V_15 ) {
F_19 ( & V_187 -> V_75 , L_41 ) ;
V_130 = - V_207 ;
goto V_218;
}
while ( F_38 ( V_12 , V_73 ) )
F_90 () ;
F_7 ( & V_12 -> V_74 . V_219 ) ;
for ( V_24 = 0 ; V_24 < V_199 -> V_206 ; V_24 ++ ) {
struct V_2 * V_3 = & V_12 -> V_8 [ V_24 ] ;
V_3 -> V_126 = V_220 ;
V_3 -> V_127 = V_221 ;
V_3 -> V_27 . V_13 = & V_12 -> V_74 ;
F_97 ( & V_3 -> V_27 ) ;
F_25 ( & V_3 -> V_27 . V_222 ,
& V_12 -> V_74 . V_219 ) ;
V_3 -> V_223 = V_12 -> V_212 + V_223 ( V_24 ) ;
F_129 ( & V_3 -> V_26 ) ;
V_3 -> V_42 = 1 << V_24 ;
F_7 ( & V_3 -> V_4 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_7 ( & V_3 -> V_31 ) ;
F_130 ( & V_3 -> V_78 , F_56 ,
( unsigned long ) V_3 ) ;
F_131 ( V_12 , V_24 ) ;
}
V_12 -> V_74 . V_224 = F_94 ;
V_12 -> V_74 . V_225 = F_98 ;
V_12 -> V_74 . V_226 = F_91 ;
V_12 -> V_74 . V_227 = F_40 ;
V_12 -> V_74 . V_75 = & V_187 -> V_75 ;
if ( F_132 ( V_200 , V_12 -> V_74 . V_202 ) )
V_12 -> V_74 . V_228 = F_66 ;
if ( F_132 ( V_175 , V_12 -> V_74 . V_202 ) ) {
V_12 -> V_74 . V_229 = F_69 ;
F_104 ( V_230 , V_12 -> V_74 . V_202 ) ;
V_12 -> V_74 . V_231 = F_82 ;
V_12 -> V_74 . V_232 = F_87 ;
}
F_31 ( V_12 , V_193 , V_233 ) ;
F_133 ( & V_187 -> V_75 , L_42 ,
F_132 ( V_200 , V_12 -> V_74 . V_202 ) ? L_43 : L_44 ,
F_132 ( V_175 , V_12 -> V_74 . V_202 ) ? L_45 : L_44 ,
V_199 -> V_206 ) ;
F_134 ( & V_12 -> V_74 ) ;
if ( V_187 -> V_75 . V_188 ) {
V_130 = F_135 ( V_187 -> V_75 . V_188 ,
F_101 , V_12 ) ;
if ( V_130 ) {
F_19 ( & V_187 -> V_75 , L_46 ) ;
goto V_234;
}
}
return 0 ;
V_234:
F_136 ( & V_12 -> V_74 ) ;
F_137 ( V_12 -> V_15 ) ;
V_218:
F_138 ( F_117 ( V_187 , 0 ) , V_12 ) ;
V_217:
F_139 ( V_12 -> V_214 ) ;
V_216:
F_140 ( V_12 -> V_214 ) ;
V_215:
F_141 ( V_12 -> V_212 ) ;
V_12 -> V_212 = NULL ;
V_213:
F_142 ( V_197 -> V_208 , V_198 ) ;
V_211:
F_143 ( V_12 ) ;
return V_130 ;
}
static int F_144 ( struct V_171 * V_187 )
{
struct V_11 * V_12 = F_145 ( V_187 ) ;
struct V_7 * V_8 , * V_235 ;
struct V_196 * V_197 ;
F_114 ( V_12 ) ;
F_136 ( & V_12 -> V_74 ) ;
F_137 ( V_12 -> V_15 ) ;
F_138 ( F_117 ( V_187 , 0 ) , V_12 ) ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_34 ( V_8 ) ;
F_146 ( V_12 , V_8 -> V_45 ) ;
F_147 ( & V_3 -> V_78 ) ;
F_148 ( & V_3 -> V_78 ) ;
F_14 ( & V_8 -> V_222 ) ;
}
F_139 ( V_12 -> V_214 ) ;
F_140 ( V_12 -> V_214 ) ;
F_141 ( V_12 -> V_212 ) ;
V_12 -> V_212 = NULL ;
V_197 = F_116 ( V_187 , V_205 , 0 ) ;
F_142 ( V_197 -> V_208 , F_119 ( V_197 ) ) ;
F_143 ( V_12 ) ;
return 0 ;
}
static void F_149 ( struct V_171 * V_187 )
{
struct V_11 * V_12 = F_145 ( V_187 ) ;
F_114 ( F_145 ( V_187 ) ) ;
F_139 ( V_12 -> V_214 ) ;
}
static int F_150 ( struct V_13 * V_75 )
{
struct V_171 * V_187 = F_151 ( V_75 ) ;
struct V_11 * V_12 = F_145 ( V_187 ) ;
struct V_7 * V_8 , * V_235 ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_34 ( V_8 ) ;
if ( F_27 ( V_3 ) && ! F_42 ( V_3 ) )
return - V_236 ;
}
return 0 ;
}
static void F_152 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = & V_3 -> V_27 ;
if ( ! F_89 ( V_3 ) ) {
F_153 ( F_16 ( V_8 ) ,
L_47 ) ;
F_87 ( V_8 , V_147 , 0 ) ;
}
V_3 -> V_237 = F_28 ( V_3 , V_40 ) ;
F_29 ( V_3 ) ;
}
static int F_154 ( struct V_13 * V_75 )
{
struct V_171 * V_187 = F_151 ( V_75 ) ;
struct V_11 * V_12 = F_145 ( V_187 ) ;
struct V_7 * V_8 , * V_235 ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_34 ( V_8 ) ;
if ( F_42 ( V_3 ) )
F_152 ( V_3 ) ;
V_3 -> V_238 = F_28 ( V_3 , V_165 ) ;
}
V_12 -> V_239 = F_38 ( V_12 , V_72 ) ;
F_114 ( V_12 ) ;
F_139 ( V_12 -> V_214 ) ;
return 0 ;
}
static void F_155 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_5 ( V_3 -> V_27 . V_13 ) ;
F_30 ( V_3 , V_36 , 0 ) ;
F_30 ( V_3 , V_37 , 0 ) ;
F_30 ( V_3 , V_38 , 0 ) ;
F_30 ( V_3 , V_39 , 0 ) ;
F_30 ( V_3 , V_40 , V_3 -> V_237 ) ;
F_31 ( V_12 , V_41 , V_3 -> V_42 ) ;
F_29 ( V_3 ) ;
}
static int F_156 ( struct V_13 * V_75 )
{
struct V_171 * V_187 = F_151 ( V_75 ) ;
struct V_11 * V_12 = F_145 ( V_187 ) ;
struct V_7 * V_8 , * V_235 ;
F_125 ( V_12 -> V_214 ) ;
F_31 ( V_12 , V_193 , V_233 ) ;
while ( F_38 ( V_12 , V_73 ) )
F_90 () ;
F_31 ( V_12 , V_240 , V_12 -> V_239 ) ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_34 ( V_8 ) ;
F_30 ( V_3 , V_165 , V_3 -> V_238 ) ;
if ( F_42 ( V_3 ) )
F_155 ( V_3 ) ;
}
return 0 ;
}
static int T_9 F_157 ( void )
{
return F_158 ( & V_241 , F_115 ) ;
}
static void T_10 F_159 ( void )
{
F_160 ( & V_241 ) ;
}
