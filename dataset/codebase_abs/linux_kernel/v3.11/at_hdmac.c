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
if ( ! V_3 -> V_27 . V_60 ) {
struct V_13 * V_61 = F_45 ( & V_3 -> V_27 ) ;
if ( ! ( V_17 -> V_18 & V_62 ) ) {
if ( V_17 -> V_18 & V_63 )
F_46 ( V_61 ,
V_10 -> V_34 . V_64 ,
V_10 -> V_49 , V_65 ) ;
else
F_47 ( V_61 ,
V_10 -> V_34 . V_64 ,
V_10 -> V_49 , V_65 ) ;
}
if ( ! ( V_17 -> V_18 & V_66 ) ) {
if ( V_17 -> V_18 & V_67 )
F_46 ( V_61 ,
V_10 -> V_34 . V_68 ,
V_10 -> V_49 , V_69 ) ;
else
F_47 ( V_61 ,
V_10 -> V_34 . V_68 ,
V_10 -> V_49 , V_69 ) ;
}
}
if ( ! F_42 ( V_3 ) ) {
T_4 V_70 = V_17 -> V_70 ;
void * V_71 = V_17 -> V_72 ;
if ( V_70 )
V_70 ( V_71 ) ;
}
F_48 ( V_17 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_10 , * V_22 ;
F_10 ( V_73 ) ;
F_18 ( F_16 ( & V_3 -> V_27 ) , L_9 ) ;
if ( ! F_50 ( & V_3 -> V_6 ) )
F_26 ( V_3 , F_3 ( V_3 ) ) ;
F_22 ( & V_3 -> V_4 , & V_73 ) ;
F_22 ( & V_3 -> V_6 , & V_3 -> V_4 ) ;
F_12 (desc, _desc, &list, desc_node)
F_41 ( V_3 , V_10 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
F_18 ( F_16 ( & V_3 -> V_27 ) , L_10 ) ;
if ( F_27 ( V_3 ) )
return;
if ( F_50 ( & V_3 -> V_4 ) ||
F_52 ( & V_3 -> V_4 ) ) {
F_49 ( V_3 ) ;
} else {
F_41 ( V_3 , F_1 ( V_3 ) ) ;
F_26 ( V_3 , F_1 ( V_3 ) ) ;
}
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_74 ;
struct V_1 * V_30 ;
V_74 = F_1 ( V_3 ) ;
F_54 ( & V_74 -> V_5 ) ;
F_22 ( & V_3 -> V_6 , V_3 -> V_4 . V_33 ) ;
if ( ! F_50 ( & V_3 -> V_4 ) )
F_26 ( V_3 , F_1 ( V_3 ) ) ;
F_55 ( F_16 ( & V_3 -> V_27 ) ,
L_11 ) ;
F_55 ( F_16 ( & V_3 -> V_27 ) ,
L_12 , V_74 -> V_17 . V_59 ) ;
F_56 ( V_3 , & V_74 -> V_34 ) ;
F_21 (child, &bad_desc->tx_list, desc_node)
F_56 ( V_3 , & V_30 -> V_34 ) ;
F_41 ( V_3 , V_74 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_58 * V_17 = & V_32 -> V_17 ;
T_4 V_70 = V_17 -> V_70 ;
void * V_71 = V_17 -> V_72 ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_13 ,
F_28 ( V_3 , V_40 ) ) ;
if ( V_70 )
V_70 ( V_71 ) ;
}
static void F_58 ( unsigned long V_75 )
{
struct V_2 * V_3 = (struct V_2 * ) V_75 ;
unsigned long V_18 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
if ( F_59 ( V_76 , & V_3 -> V_51 ) )
F_53 ( V_3 ) ;
else if ( F_42 ( V_3 ) )
F_57 ( V_3 ) ;
else
F_51 ( V_3 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
}
static T_5 F_60 ( int V_77 , void * V_78 )
{
struct V_11 * V_12 = (struct V_11 * ) V_78 ;
struct V_2 * V_3 ;
int V_24 ;
T_3 V_51 , V_79 , V_80 ;
int V_23 = V_81 ;
do {
V_80 = F_38 ( V_12 , V_82 ) ;
V_51 = F_38 ( V_12 , V_83 ) ;
V_79 = V_51 & V_80 ;
if ( ! V_79 )
break;
F_18 ( V_12 -> V_84 . V_85 ,
L_14 ,
V_51 , V_80 , V_79 ) ;
for ( V_24 = 0 ; V_24 < V_12 -> V_84 . V_86 ; V_24 ++ ) {
V_3 = & V_12 -> V_8 [ V_24 ] ;
if ( V_79 & ( F_61 ( V_24 ) | F_62 ( V_24 ) ) ) {
if ( V_79 & F_62 ( V_24 ) ) {
F_31 ( V_12 , V_87 ,
F_63 ( V_24 ) | V_3 -> V_42 ) ;
F_64 ( V_76 , & V_3 -> V_51 ) ;
}
if ( V_79 & F_61 ( V_24 ) )
F_64 ( V_50 , & V_3 -> V_51 ) ;
F_65 ( & V_3 -> V_88 ) ;
V_23 = V_89 ;
}
}
} while ( V_79 );
return V_23 ;
}
static T_6 V_21 ( struct V_58 * V_90 )
{
struct V_1 * V_10 = F_66 ( V_90 ) ;
struct V_2 * V_3 = F_34 ( V_90 -> V_8 ) ;
T_6 V_59 ;
unsigned long V_18 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_59 = F_67 ( V_90 ) ;
if ( F_50 ( & V_3 -> V_4 ) ) {
F_18 ( F_16 ( V_90 -> V_8 ) , L_15 ,
V_10 -> V_17 . V_59 ) ;
F_26 ( V_3 , V_10 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_4 ) ;
} else {
F_18 ( F_16 ( V_90 -> V_8 ) , L_16 ,
V_10 -> V_17 . V_59 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_6 ) ;
}
F_17 ( & V_3 -> V_26 , V_18 ) ;
return V_59 ;
}
static struct V_58 *
F_68 ( struct V_7 * V_8 , T_2 V_91 , T_2 V_92 ,
T_7 V_49 , unsigned long V_18 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_1 * V_10 = NULL ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_7 V_93 ;
T_7 V_94 ;
unsigned int V_95 ;
unsigned int V_96 ;
T_3 V_54 ;
T_3 V_97 ;
F_18 ( F_16 ( V_8 ) , L_17 ,
V_91 , V_92 , V_49 , V_18 ) ;
if ( F_35 ( ! V_49 ) ) {
F_15 ( F_16 ( V_8 ) , L_18 ) ;
return NULL ;
}
V_97 = V_98 | V_99
| V_100
| V_101
| V_102 ;
if ( ! ( ( V_92 | V_91 | V_49 ) & 3 ) ) {
V_54 = V_103 | V_104 ;
V_95 = V_96 = 2 ;
} else if ( ! ( ( V_92 | V_91 | V_49 ) & 1 ) ) {
V_54 = V_105 | V_106 ;
V_95 = V_96 = 1 ;
} else {
V_54 = V_107 | V_108 ;
V_95 = V_96 = 0 ;
}
for ( V_94 = 0 ; V_94 < V_49 ; V_94 += V_93 << V_95 ) {
V_93 = F_69 ( T_7 , ( V_49 - V_94 ) >> V_95 ,
V_55 ) ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_109;
V_10 -> V_34 . V_68 = V_92 + V_94 ;
V_10 -> V_34 . V_64 = V_91 + V_94 ;
V_10 -> V_34 . V_54 = V_54 | V_93 ;
V_10 -> V_34 . V_97 = V_97 ;
V_10 -> V_17 . V_59 = 0 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_32 -> V_17 . V_59 = - V_110 ;
V_32 -> V_49 = V_49 ;
V_32 -> V_56 = V_95 ;
F_70 ( V_10 ) ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_109:
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static struct V_58 *
F_71 ( struct V_7 * V_8 , struct V_111 * V_112 ,
unsigned int V_113 , enum V_114 V_115 ,
unsigned long V_18 , void * V_116 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_117 * V_118 = V_8 -> V_60 ;
struct V_119 * V_120 = & V_3 -> V_121 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_3 V_54 ;
T_3 V_97 ;
T_2 V_122 ;
unsigned int V_123 ;
unsigned int V_124 ;
unsigned int V_24 ;
struct V_111 * V_125 ;
T_7 V_126 = 0 ;
F_18 ( F_16 ( V_8 ) , L_19 ,
V_113 ,
V_115 == V_127 ? L_20 : L_21 ,
V_18 ) ;
if ( F_35 ( ! V_118 || ! V_113 ) ) {
F_15 ( F_16 ( V_8 ) , L_22 ) ;
return NULL ;
}
V_54 = F_72 ( V_120 -> V_128 )
| F_73 ( V_120 -> V_129 ) ;
V_97 = V_99 ;
switch ( V_115 ) {
case V_127 :
V_123 = F_74 ( V_120 -> V_130 ) ;
V_54 |= F_75 ( V_123 ) ;
V_97 |= V_131
| V_100
| V_132
| F_76 ( V_3 -> V_133 ) | F_77 ( V_3 -> V_134 ) ;
V_122 = V_120 -> V_135 ;
F_78 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_3 V_49 ;
T_3 V_136 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_109;
V_136 = F_79 ( V_125 ) ;
V_49 = F_80 ( V_125 ) ;
if ( F_35 ( ! V_49 ) ) {
F_15 ( F_16 ( V_8 ) ,
L_23 , V_24 ) ;
goto V_137;
}
V_124 = 2 ;
if ( F_35 ( V_136 & 3 || V_49 & 3 ) )
V_124 = 0 ;
V_10 -> V_34 . V_68 = V_136 ;
V_10 -> V_34 . V_64 = V_122 ;
V_10 -> V_34 . V_54 = V_54
| F_81 ( V_124 )
| V_49 >> V_124 ;
V_10 -> V_34 . V_97 = V_97 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_126 += V_49 ;
}
break;
case V_138 :
V_123 = F_74 ( V_120 -> V_139 ) ;
V_54 |= F_81 ( V_123 ) ;
V_97 |= V_101
| V_140
| V_141
| F_76 ( V_3 -> V_134 ) | F_77 ( V_3 -> V_133 ) ;
V_122 = V_120 -> V_142 ;
F_78 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_3 V_49 ;
T_3 V_136 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_109;
V_136 = F_79 ( V_125 ) ;
V_49 = F_80 ( V_125 ) ;
if ( F_35 ( ! V_49 ) ) {
F_15 ( F_16 ( V_8 ) ,
L_23 , V_24 ) ;
goto V_137;
}
V_124 = 2 ;
if ( F_35 ( V_136 & 3 || V_49 & 3 ) )
V_124 = 0 ;
V_10 -> V_34 . V_68 = V_122 ;
V_10 -> V_34 . V_64 = V_136 ;
V_10 -> V_34 . V_54 = V_54
| F_75 ( V_124 )
| V_49 >> V_123 ;
V_10 -> V_34 . V_97 = V_97 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_126 += V_49 ;
}
break;
default:
return NULL ;
}
F_70 ( V_33 ) ;
V_32 -> V_17 . V_59 = - V_110 ;
V_32 -> V_49 = V_126 ;
V_32 -> V_56 = V_123 ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_109:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
V_137:
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static int
F_82 ( unsigned int V_123 , T_2 V_143 ,
T_7 V_144 )
{
if ( V_144 > ( V_55 << V_123 ) )
goto V_145;
if ( F_35 ( V_144 & ( ( 1 << V_123 ) - 1 ) ) )
goto V_145;
if ( F_35 ( V_143 & ( ( 1 << V_123 ) - 1 ) ) )
goto V_145;
return 0 ;
V_145:
return - V_52 ;
}
static int
F_83 ( struct V_7 * V_8 , struct V_1 * V_10 ,
unsigned int V_146 , T_2 V_143 ,
unsigned int V_123 , T_7 V_144 ,
enum V_114 V_115 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_119 * V_120 = & V_3 -> V_121 ;
T_3 V_54 ;
V_54 = F_72 ( V_120 -> V_128 )
| F_73 ( V_120 -> V_129 )
| F_75 ( V_123 )
| F_81 ( V_123 )
| V_144 >> V_123 ;
switch ( V_115 ) {
case V_127 :
V_10 -> V_34 . V_68 = V_143 + ( V_144 * V_146 ) ;
V_10 -> V_34 . V_64 = V_120 -> V_135 ;
V_10 -> V_34 . V_54 = V_54 ;
V_10 -> V_34 . V_97 = V_131
| V_100
| V_132
| F_76 ( V_3 -> V_133 )
| F_77 ( V_3 -> V_134 ) ;
break;
case V_138 :
V_10 -> V_34 . V_68 = V_120 -> V_142 ;
V_10 -> V_34 . V_64 = V_143 + ( V_144 * V_146 ) ;
V_10 -> V_34 . V_54 = V_54 ;
V_10 -> V_34 . V_97 = V_101
| V_140
| V_141
| F_76 ( V_3 -> V_134 )
| F_77 ( V_3 -> V_133 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static struct V_58 *
F_84 ( struct V_7 * V_8 , T_2 V_143 , T_7 V_147 ,
T_7 V_144 , enum V_114 V_115 ,
unsigned long V_18 , void * V_116 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_117 * V_118 = V_8 -> V_60 ;
struct V_119 * V_120 = & V_3 -> V_121 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
unsigned long V_148 ;
unsigned int V_123 ;
unsigned int V_149 = V_147 / V_144 ;
unsigned int V_24 ;
F_18 ( F_16 ( V_8 ) , L_24 ,
V_115 == V_127 ? L_20 : L_21 ,
V_143 ,
V_149 , V_147 , V_144 ) ;
if ( F_35 ( ! V_118 || ! V_147 || ! V_144 ) ) {
F_15 ( F_16 ( V_8 ) , L_25 ) ;
return NULL ;
}
V_148 = F_85 ( V_150 , & V_3 -> V_51 ) ;
if ( V_148 ) {
F_15 ( F_16 ( V_8 ) , L_26 ) ;
return NULL ;
}
if ( F_35 ( ! F_86 ( V_115 ) ) )
goto V_145;
if ( V_120 -> V_115 == V_127 )
V_123 = F_74 ( V_120 -> V_130 ) ;
else
V_123 = F_74 ( V_120 -> V_139 ) ;
if ( F_82 ( V_123 , V_143 , V_144 ) )
goto V_145;
for ( V_24 = 0 ; V_24 < V_149 ; V_24 ++ ) {
struct V_1 * V_10 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_109;
if ( F_83 ( V_8 , V_10 , V_24 , V_143 ,
V_123 , V_144 , V_115 ) )
goto V_109;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_33 -> V_34 . V_35 = V_32 -> V_17 . V_14 ;
V_32 -> V_17 . V_59 = - V_110 ;
V_32 -> V_49 = V_147 ;
V_32 -> V_56 = V_123 ;
return & V_32 -> V_17 ;
V_109:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
F_20 ( V_3 , V_32 ) ;
V_145:
F_37 ( V_150 , & V_3 -> V_51 ) ;
return NULL ;
}
static int F_87 ( struct V_7 * V_8 ,
struct V_119 * V_120 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
if ( ! V_8 -> V_60 )
return - V_52 ;
memcpy ( & V_3 -> V_121 , V_120 , sizeof( * V_120 ) ) ;
F_88 ( & V_3 -> V_121 . V_128 ) ;
F_88 ( & V_3 -> V_121 . V_129 ) ;
return 0 ;
}
static int F_89 ( struct V_7 * V_8 , enum V_151 V_152 ,
unsigned long V_153 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
int V_45 = V_3 -> V_27 . V_45 ;
unsigned long V_18 ;
F_10 ( V_73 ) ;
F_18 ( F_16 ( V_8 ) , L_27 , V_152 ) ;
if ( V_152 == V_154 ) {
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_41 , F_90 ( V_45 ) ) ;
F_64 ( V_155 , & V_3 -> V_51 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else if ( V_152 == V_156 ) {
if ( ! F_91 ( V_3 ) )
return 0 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_87 , F_63 ( V_45 ) ) ;
F_37 ( V_155 , & V_3 -> V_51 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else if ( V_152 == V_157 ) {
struct V_1 * V_10 , * V_22 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_31 ( V_12 , V_87 , F_63 ( V_45 ) | V_3 -> V_42 ) ;
while ( F_38 ( V_12 , V_57 ) & V_3 -> V_42 )
F_92 () ;
F_22 ( & V_3 -> V_6 , & V_73 ) ;
F_22 ( & V_3 -> V_4 , & V_73 ) ;
F_12 (desc, _desc, &list, desc_node)
F_41 ( V_3 , V_10 ) ;
F_37 ( V_155 , & V_3 -> V_51 ) ;
F_37 ( V_150 , & V_3 -> V_51 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else if ( V_152 == V_158 ) {
return F_87 ( V_8 , (struct V_119 * ) V_153 ) ;
} else {
return - V_159 ;
}
return 0 ;
}
static enum V_160
F_93 ( struct V_7 * V_8 ,
T_6 V_59 ,
struct V_161 * V_162 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
unsigned long V_18 ;
enum V_160 V_23 ;
int V_163 = 0 ;
V_23 = F_94 ( V_8 , V_59 , V_162 ) ;
if ( V_23 == V_164 )
return V_23 ;
if ( ! V_162 )
return V_165 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_163 = F_33 ( V_8 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
if ( F_35 ( V_163 < 0 ) ) {
F_18 ( F_16 ( V_8 ) , L_28 ) ;
return V_165 ;
} else {
F_95 ( V_162 , V_163 ) ;
}
F_18 ( F_16 ( V_8 ) , L_29 ,
V_23 , V_59 , V_163 ) ;
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
F_51 ( V_3 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
}
static int F_96 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 ;
struct V_117 * V_118 ;
unsigned long V_18 ;
int V_24 ;
T_3 V_166 ;
F_10 ( V_25 ) ;
F_18 ( F_16 ( V_8 ) , L_31 ) ;
if ( F_27 ( V_3 ) ) {
F_15 ( F_16 ( V_8 ) , L_32 ) ;
return - V_167 ;
}
V_166 = V_168 ;
V_118 = V_8 -> V_60 ;
if ( V_118 ) {
F_97 ( ! V_118 -> V_169 || V_118 -> V_169 != V_12 -> V_84 . V_85 ) ;
if ( V_118 -> V_166 )
V_166 = V_118 -> V_166 ;
}
if ( ! F_50 ( & V_3 -> V_31 ) )
return V_3 -> V_29 ;
for ( V_24 = 0 ; V_24 < V_170 ; V_24 ++ ) {
V_10 = F_4 ( V_8 , V_171 ) ;
if ( ! V_10 ) {
F_19 ( V_12 -> V_84 . V_85 ,
L_33 , V_24 ) ;
break;
}
F_25 ( & V_10 -> V_5 , & V_25 ) ;
}
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_3 -> V_29 = V_24 ;
V_3 -> V_48 = 0 ;
F_98 ( & V_25 , & V_3 -> V_31 ) ;
F_99 ( V_8 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
F_30 ( V_3 , V_172 , V_166 ) ;
F_15 ( F_16 ( V_8 ) ,
L_34 ,
V_3 -> V_29 ) ;
return V_3 -> V_29 ;
}
static void F_100 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_34 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 , * V_22 ;
F_10 ( V_73 ) ;
F_15 ( F_16 ( V_8 ) , L_35 ,
V_3 -> V_29 ) ;
F_97 ( ! F_50 ( & V_3 -> V_4 ) ) ;
F_97 ( ! F_50 ( & V_3 -> V_6 ) ) ;
F_97 ( F_27 ( V_3 ) ) ;
F_12 (desc, _desc, &atchan->free_list, desc_node) {
F_18 ( F_16 ( V_8 ) , L_36 , V_10 ) ;
F_14 ( & V_10 -> V_5 ) ;
F_101 ( V_12 -> V_15 , V_10 , V_10 -> V_17 . V_14 ) ;
}
F_22 ( & V_3 -> V_31 , & V_73 ) ;
V_3 -> V_29 = 0 ;
V_3 -> V_51 = 0 ;
V_3 -> V_48 = 0 ;
F_18 ( F_16 ( V_8 ) , L_37 ) ;
}
static bool F_102 ( struct V_7 * V_8 , void * V_173 )
{
struct V_117 * V_118 = V_173 ;
if ( V_118 -> V_169 == V_8 -> V_13 -> V_85 ) {
V_8 -> V_60 = V_118 ;
return true ;
} else {
return false ;
}
}
static struct V_7 * F_103 ( struct V_174 * V_175 ,
struct V_176 * V_176 )
{
struct V_7 * V_8 ;
struct V_2 * V_3 ;
struct V_117 * V_118 ;
T_8 V_42 ;
unsigned int V_177 ;
struct V_178 * V_179 ;
if ( V_175 -> V_180 != 2 )
return NULL ;
V_179 = F_104 ( V_175 -> V_181 ) ;
F_105 ( V_42 ) ;
F_106 ( V_182 , V_42 ) ;
V_118 = F_107 ( & V_179 -> V_85 , sizeof( * V_118 ) , V_171 ) ;
if ( ! V_118 )
return NULL ;
V_118 -> V_166 = V_183 | V_184 ;
V_177 = V_175 -> args [ 1 ] & V_185 ;
V_118 -> V_166 |= F_108 ( V_177 ) | F_109 ( V_177 )
| F_110 ( V_177 ) | F_111 ( V_177 ) ;
switch ( V_175 -> args [ 1 ] & V_186 ) {
case V_187 :
V_118 -> V_166 |= V_188 ;
break;
case V_189 :
V_118 -> V_166 |= V_190 ;
break;
case V_191 :
default:
V_118 -> V_166 |= V_192 ;
}
V_118 -> V_169 = & V_179 -> V_85 ;
V_8 = F_112 ( V_42 , F_102 , V_118 ) ;
if ( ! V_8 )
return NULL ;
V_3 = F_34 ( V_8 ) ;
V_3 -> V_134 = V_175 -> args [ 0 ] & 0xff ;
V_3 -> V_133 = ( V_175 -> args [ 0 ] >> 16 ) & 0xff ;
return V_8 ;
}
static struct V_7 * F_103 ( struct V_174 * V_175 ,
struct V_176 * V_176 )
{
return NULL ;
}
static inline const struct V_193 * T_9 F_113 (
struct V_178 * V_194 )
{
if ( V_194 -> V_85 . V_195 ) {
const struct V_196 * V_197 ;
V_197 = F_114 ( V_198 , V_194 -> V_85 . V_195 ) ;
if ( V_197 == NULL )
return NULL ;
return V_197 -> V_75 ;
}
return (struct V_193 * )
F_115 ( V_194 ) -> V_199 ;
}
static void F_116 ( struct V_11 * V_12 )
{
F_31 ( V_12 , V_200 , 0 ) ;
F_31 ( V_12 , V_201 , - 1L ) ;
while ( F_38 ( V_12 , V_57 ) & V_12 -> V_202 )
F_92 () ;
}
static int T_9 F_117 ( struct V_178 * V_194 )
{
struct V_203 * V_204 ;
struct V_11 * V_12 ;
T_7 V_205 ;
int V_77 ;
int V_137 ;
int V_24 ;
const struct V_193 * V_206 ;
F_106 ( V_207 , V_208 . V_209 ) ;
F_106 ( V_207 , V_210 . V_209 ) ;
F_106 ( V_182 , V_210 . V_209 ) ;
V_206 = F_113 ( V_194 ) ;
if ( ! V_206 )
return - V_211 ;
V_204 = F_118 ( V_194 , V_212 , 0 ) ;
if ( ! V_204 )
return - V_52 ;
V_77 = F_119 ( V_194 , 0 ) ;
if ( V_77 < 0 )
return V_77 ;
V_205 = sizeof( struct V_11 ) ;
V_205 += V_206 -> V_213 * sizeof( struct V_2 ) ;
V_12 = F_120 ( V_205 , V_171 ) ;
if ( ! V_12 )
return - V_214 ;
V_12 -> V_84 . V_209 = V_206 -> V_209 ;
V_12 -> V_202 = ( 1 << V_206 -> V_213 ) - 1 ;
V_205 = F_121 ( V_204 ) ;
if ( ! F_122 ( V_204 -> V_215 , V_205 , V_194 -> V_85 . V_216 -> V_217 ) ) {
V_137 = - V_110 ;
goto V_218;
}
V_12 -> V_219 = F_123 ( V_204 -> V_215 , V_205 ) ;
if ( ! V_12 -> V_219 ) {
V_137 = - V_214 ;
goto V_220;
}
V_12 -> V_221 = F_124 ( & V_194 -> V_85 , L_38 ) ;
if ( F_125 ( V_12 -> V_221 ) ) {
V_137 = F_126 ( V_12 -> V_221 ) ;
goto V_222;
}
V_137 = F_127 ( V_12 -> V_221 ) ;
if ( V_137 )
goto V_223;
F_116 ( V_12 ) ;
V_137 = F_128 ( V_77 , F_60 , 0 , L_39 , V_12 ) ;
if ( V_137 )
goto V_224;
F_129 ( V_194 , V_12 ) ;
V_12 -> V_15 = F_130 ( L_40 ,
& V_194 -> V_85 , sizeof( struct V_1 ) ,
4 , 0 ) ;
if ( ! V_12 -> V_15 ) {
F_19 ( & V_194 -> V_85 , L_41 ) ;
V_137 = - V_214 ;
goto V_225;
}
while ( F_38 ( V_12 , V_83 ) )
F_92 () ;
F_7 ( & V_12 -> V_84 . V_226 ) ;
for ( V_24 = 0 ; V_24 < V_206 -> V_213 ; V_24 ++ ) {
struct V_2 * V_3 = & V_12 -> V_8 [ V_24 ] ;
V_3 -> V_133 = V_227 ;
V_3 -> V_134 = V_228 ;
V_3 -> V_27 . V_13 = & V_12 -> V_84 ;
F_99 ( & V_3 -> V_27 ) ;
F_25 ( & V_3 -> V_27 . V_229 ,
& V_12 -> V_84 . V_226 ) ;
V_3 -> V_230 = V_12 -> V_219 + V_230 ( V_24 ) ;
F_131 ( & V_3 -> V_26 ) ;
V_3 -> V_42 = 1 << V_24 ;
F_7 ( & V_3 -> V_4 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_7 ( & V_3 -> V_31 ) ;
F_132 ( & V_3 -> V_88 , F_58 ,
( unsigned long ) V_3 ) ;
F_133 ( V_12 , V_24 ) ;
}
V_12 -> V_84 . V_231 = F_96 ;
V_12 -> V_84 . V_232 = F_100 ;
V_12 -> V_84 . V_233 = F_93 ;
V_12 -> V_84 . V_234 = F_40 ;
V_12 -> V_84 . V_85 = & V_194 -> V_85 ;
if ( F_134 ( V_207 , V_12 -> V_84 . V_209 ) )
V_12 -> V_84 . V_235 = F_68 ;
if ( F_134 ( V_182 , V_12 -> V_84 . V_209 ) ) {
V_12 -> V_84 . V_236 = F_71 ;
F_106 ( V_237 , V_12 -> V_84 . V_209 ) ;
V_12 -> V_84 . V_238 = F_84 ;
V_12 -> V_84 . V_239 = F_89 ;
}
F_31 ( V_12 , V_200 , V_240 ) ;
F_135 ( & V_194 -> V_85 , L_42 ,
F_134 ( V_207 , V_12 -> V_84 . V_209 ) ? L_43 : L_44 ,
F_134 ( V_182 , V_12 -> V_84 . V_209 ) ? L_45 : L_44 ,
V_206 -> V_213 ) ;
F_136 ( & V_12 -> V_84 ) ;
if ( V_194 -> V_85 . V_195 ) {
V_137 = F_137 ( V_194 -> V_85 . V_195 ,
F_103 , V_12 ) ;
if ( V_137 ) {
F_19 ( & V_194 -> V_85 , L_46 ) ;
goto V_241;
}
}
return 0 ;
V_241:
F_138 ( & V_12 -> V_84 ) ;
F_139 ( V_12 -> V_15 ) ;
V_225:
F_140 ( F_119 ( V_194 , 0 ) , V_12 ) ;
V_224:
F_141 ( V_12 -> V_221 ) ;
V_223:
F_142 ( V_12 -> V_221 ) ;
V_222:
F_143 ( V_12 -> V_219 ) ;
V_12 -> V_219 = NULL ;
V_220:
F_144 ( V_204 -> V_215 , V_205 ) ;
V_218:
F_145 ( V_12 ) ;
return V_137 ;
}
static int F_146 ( struct V_178 * V_194 )
{
struct V_11 * V_12 = F_147 ( V_194 ) ;
struct V_7 * V_8 , * V_242 ;
struct V_203 * V_204 ;
F_116 ( V_12 ) ;
F_138 ( & V_12 -> V_84 ) ;
F_139 ( V_12 -> V_15 ) ;
F_140 ( F_119 ( V_194 , 0 ) , V_12 ) ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_34 ( V_8 ) ;
F_148 ( V_12 , V_8 -> V_45 ) ;
F_149 ( & V_3 -> V_88 ) ;
F_150 ( & V_3 -> V_88 ) ;
F_14 ( & V_8 -> V_229 ) ;
}
F_141 ( V_12 -> V_221 ) ;
F_142 ( V_12 -> V_221 ) ;
F_143 ( V_12 -> V_219 ) ;
V_12 -> V_219 = NULL ;
V_204 = F_118 ( V_194 , V_212 , 0 ) ;
F_144 ( V_204 -> V_215 , F_121 ( V_204 ) ) ;
F_145 ( V_12 ) ;
return 0 ;
}
static void F_151 ( struct V_178 * V_194 )
{
struct V_11 * V_12 = F_147 ( V_194 ) ;
F_116 ( F_147 ( V_194 ) ) ;
F_141 ( V_12 -> V_221 ) ;
}
static int F_152 ( struct V_13 * V_85 )
{
struct V_178 * V_194 = F_153 ( V_85 ) ;
struct V_11 * V_12 = F_147 ( V_194 ) ;
struct V_7 * V_8 , * V_242 ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_34 ( V_8 ) ;
if ( F_27 ( V_3 ) && ! F_42 ( V_3 ) )
return - V_243 ;
}
return 0 ;
}
static void F_154 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = & V_3 -> V_27 ;
if ( ! F_91 ( V_3 ) ) {
F_155 ( F_16 ( V_8 ) ,
L_47 ) ;
F_89 ( V_8 , V_154 , 0 ) ;
}
V_3 -> V_244 = F_28 ( V_3 , V_40 ) ;
F_29 ( V_3 ) ;
}
static int F_156 ( struct V_13 * V_85 )
{
struct V_178 * V_194 = F_153 ( V_85 ) ;
struct V_11 * V_12 = F_147 ( V_194 ) ;
struct V_7 * V_8 , * V_242 ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_34 ( V_8 ) ;
if ( F_42 ( V_3 ) )
F_154 ( V_3 ) ;
V_3 -> V_245 = F_28 ( V_3 , V_172 ) ;
}
V_12 -> V_246 = F_38 ( V_12 , V_82 ) ;
F_116 ( V_12 ) ;
F_141 ( V_12 -> V_221 ) ;
return 0 ;
}
static void F_157 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_5 ( V_3 -> V_27 . V_13 ) ;
F_30 ( V_3 , V_36 , 0 ) ;
F_30 ( V_3 , V_37 , 0 ) ;
F_30 ( V_3 , V_38 , 0 ) ;
F_30 ( V_3 , V_39 , 0 ) ;
F_30 ( V_3 , V_40 , V_3 -> V_244 ) ;
F_31 ( V_12 , V_41 , V_3 -> V_42 ) ;
F_29 ( V_3 ) ;
}
static int F_158 ( struct V_13 * V_85 )
{
struct V_178 * V_194 = F_153 ( V_85 ) ;
struct V_11 * V_12 = F_147 ( V_194 ) ;
struct V_7 * V_8 , * V_242 ;
F_127 ( V_12 -> V_221 ) ;
F_31 ( V_12 , V_200 , V_240 ) ;
while ( F_38 ( V_12 , V_83 ) )
F_92 () ;
F_31 ( V_12 , V_247 , V_12 -> V_246 ) ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_34 ( V_8 ) ;
F_30 ( V_3 , V_172 , V_3 -> V_245 ) ;
if ( F_42 ( V_3 ) )
F_157 ( V_3 ) ;
}
return 0 ;
}
static int T_9 F_159 ( void )
{
return F_160 ( & V_248 , F_117 ) ;
}
static void T_10 F_161 ( void )
{
F_162 ( & V_248 ) ;
}
