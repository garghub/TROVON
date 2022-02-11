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
unsigned int V_24 = 0 ;
F_10 ( V_25 ) ;
F_11 ( & V_3 -> V_26 ) ;
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
F_17 ( & V_3 -> V_26 ) ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_2 , V_24 ) ;
if ( ! V_23 ) {
V_23 = F_4 ( & V_3 -> V_27 , V_28 ) ;
if ( V_23 ) {
F_11 ( & V_3 -> V_26 ) ;
V_3 -> V_29 ++ ;
F_17 ( & V_3 -> V_26 ) ;
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
F_11 ( & V_3 -> V_26 ) ;
F_21 (child, &desc->tx_list, desc_node)
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_4 ,
V_30 ) ;
F_22 ( & V_10 -> V_16 , & V_3 -> V_31 ) ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_5 , V_10 ) ;
F_23 ( & V_10 -> V_5 , & V_3 -> V_31 ) ;
F_17 ( & V_3 -> V_26 ) ;
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
static T_3
F_26 ( struct V_2 * V_3 , struct V_1 * V_10 )
{
T_3 V_36 = V_3 -> V_27 . V_36 ;
if ( ++ V_36 < 0 )
V_36 = 1 ;
V_3 -> V_27 . V_36 = V_36 ;
V_10 -> V_17 . V_36 = V_36 ;
return V_36 ;
}
static void F_27 ( struct V_2 * V_3 , struct V_1 * V_32 )
{
struct V_11 * V_12 = F_5 ( V_3 -> V_27 . V_13 ) ;
if ( F_28 ( V_3 ) ) {
F_19 ( F_16 ( & V_3 -> V_27 ) ,
L_6 ) ;
F_19 ( F_16 ( & V_3 -> V_27 ) ,
L_7 ,
F_29 ( V_3 , V_37 ) ,
F_29 ( V_3 , V_38 ) ,
F_29 ( V_3 , V_39 ) ,
F_29 ( V_3 , V_40 ) ,
F_29 ( V_3 , V_41 ) ) ;
return;
}
F_30 ( V_3 ) ;
while ( F_31 ( V_12 , V_42 ) )
F_32 () ;
F_33 ( V_3 , V_37 , 0 ) ;
F_33 ( V_3 , V_38 , 0 ) ;
F_33 ( V_3 , V_39 , 0 ) ;
F_33 ( V_3 , V_40 , 0 ) ;
F_33 ( V_3 , V_41 , V_32 -> V_17 . V_14 ) ;
F_34 ( V_12 , V_43 , V_3 -> V_44 ) ;
F_30 ( V_3 ) ;
}
static void
F_35 ( struct V_2 * V_3 , struct V_1 * V_10 )
{
struct V_45 * V_17 = & V_10 -> V_17 ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_8 , V_17 -> V_36 ) ;
V_3 -> V_46 = V_17 -> V_36 ;
F_22 ( & V_10 -> V_16 , & V_3 -> V_31 ) ;
F_36 ( & V_10 -> V_5 , & V_3 -> V_31 ) ;
if ( ! V_3 -> V_27 . V_47 ) {
struct V_13 * V_48 = F_37 ( & V_3 -> V_27 ) ;
if ( ! ( V_17 -> V_18 & V_49 ) ) {
if ( V_17 -> V_18 & V_50 )
F_38 ( V_48 ,
V_10 -> V_34 . V_51 ,
V_10 -> V_52 , V_53 ) ;
else
F_39 ( V_48 ,
V_10 -> V_34 . V_51 ,
V_10 -> V_52 , V_53 ) ;
}
if ( ! ( V_17 -> V_18 & V_54 ) ) {
if ( V_17 -> V_18 & V_55 )
F_38 ( V_48 ,
V_10 -> V_34 . V_56 ,
V_10 -> V_52 , V_57 ) ;
else
F_39 ( V_48 ,
V_10 -> V_34 . V_56 ,
V_10 -> V_52 , V_57 ) ;
}
}
if ( ! F_40 ( V_58 , & V_3 -> V_59 ) ) {
T_4 V_60 = V_17 -> V_60 ;
void * V_61 = V_17 -> V_62 ;
if ( V_60 )
V_60 ( V_61 ) ;
}
F_41 ( V_17 ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_10 , * V_22 ;
F_10 ( V_63 ) ;
F_18 ( F_16 ( & V_3 -> V_27 ) , L_9 ) ;
F_43 ( F_28 ( V_3 ) ) ;
if ( ! F_44 ( & V_3 -> V_6 ) )
F_27 ( V_3 , F_3 ( V_3 ) ) ;
F_22 ( & V_3 -> V_4 , & V_63 ) ;
F_22 ( & V_3 -> V_6 , & V_3 -> V_4 ) ;
F_12 (desc, _desc, &list, desc_node)
F_35 ( V_3 , V_10 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_10 , * V_22 ;
struct V_1 * V_30 ;
F_18 ( F_16 ( & V_3 -> V_27 ) , L_10 ) ;
F_12 (desc, _desc, &atchan->active_list, desc_node) {
if ( ! ( V_10 -> V_34 . V_64 & V_65 ) )
return;
F_21 (child, &desc->tx_list, desc_node)
if ( ! ( V_30 -> V_34 . V_64 & V_65 ) )
return;
F_35 ( V_3 , V_10 ) ;
}
}
static void F_46 ( struct V_2 * V_3 )
{
F_18 ( F_16 ( & V_3 -> V_27 ) , L_11 ) ;
if ( F_44 ( & V_3 -> V_4 ) ||
F_47 ( & V_3 -> V_4 ) ) {
F_42 ( V_3 ) ;
} else {
F_35 ( V_3 , F_1 ( V_3 ) ) ;
F_27 ( V_3 , F_1 ( V_3 ) ) ;
}
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_66 ;
struct V_1 * V_30 ;
V_66 = F_1 ( V_3 ) ;
F_49 ( & V_66 -> V_5 ) ;
F_22 ( & V_3 -> V_6 , V_3 -> V_4 . V_33 ) ;
if ( ! F_44 ( & V_3 -> V_4 ) )
F_27 ( V_3 , F_1 ( V_3 ) ) ;
F_50 ( F_16 ( & V_3 -> V_27 ) ,
L_12 ) ;
F_50 ( F_16 ( & V_3 -> V_27 ) ,
L_13 , V_66 -> V_17 . V_36 ) ;
F_51 ( V_3 , & V_66 -> V_34 ) ;
F_21 (child, &bad_desc->tx_list, desc_node)
F_51 ( V_3 , & V_30 -> V_34 ) ;
F_35 ( V_3 , V_66 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_45 * V_17 = & V_32 -> V_17 ;
T_4 V_60 = V_17 -> V_60 ;
void * V_61 = V_17 -> V_62 ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_14 ,
F_29 ( V_3 , V_41 ) ) ;
if ( V_60 )
V_60 ( V_61 ) ;
}
static void F_53 ( unsigned long V_67 )
{
struct V_2 * V_3 = (struct V_2 * ) V_67 ;
F_54 ( & V_3 -> V_26 ) ;
if ( F_55 ( V_68 , & V_3 -> V_59 ) )
F_48 ( V_3 ) ;
else if ( F_40 ( V_58 , & V_3 -> V_59 ) )
F_52 ( V_3 ) ;
else
F_46 ( V_3 ) ;
F_56 ( & V_3 -> V_26 ) ;
}
static T_5 F_57 ( int V_69 , void * V_70 )
{
struct V_11 * V_12 = (struct V_11 * ) V_70 ;
struct V_2 * V_3 ;
int V_24 ;
T_6 V_59 , V_71 , V_72 ;
int V_23 = V_73 ;
do {
V_72 = F_31 ( V_12 , V_74 ) ;
V_59 = F_31 ( V_12 , V_42 ) ;
V_71 = V_59 & V_72 ;
if ( ! V_71 )
break;
F_18 ( V_12 -> V_75 . V_76 ,
L_15 ,
V_59 , V_72 , V_71 ) ;
for ( V_24 = 0 ; V_24 < V_12 -> V_75 . V_77 ; V_24 ++ ) {
V_3 = & V_12 -> V_8 [ V_24 ] ;
if ( V_71 & ( F_58 ( V_24 ) | F_59 ( V_24 ) ) ) {
if ( V_71 & F_59 ( V_24 ) ) {
F_34 ( V_12 , V_78 ,
F_60 ( V_24 ) | V_3 -> V_44 ) ;
F_61 ( V_68 , & V_3 -> V_59 ) ;
}
F_62 ( & V_3 -> V_79 ) ;
V_23 = V_80 ;
}
}
} while ( V_71 );
return V_23 ;
}
static T_3 V_21 ( struct V_45 * V_81 )
{
struct V_1 * V_10 = F_63 ( V_81 ) ;
struct V_2 * V_3 = F_64 ( V_81 -> V_8 ) ;
T_3 V_36 ;
F_11 ( & V_3 -> V_26 ) ;
V_36 = F_26 ( V_3 , V_10 ) ;
if ( F_44 ( & V_3 -> V_4 ) ) {
F_18 ( F_16 ( V_81 -> V_8 ) , L_16 ,
V_10 -> V_17 . V_36 ) ;
F_27 ( V_3 , V_10 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_4 ) ;
} else {
F_18 ( F_16 ( V_81 -> V_8 ) , L_17 ,
V_10 -> V_17 . V_36 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_6 ) ;
}
F_17 ( & V_3 -> V_26 ) ;
return V_36 ;
}
static struct V_45 *
F_65 ( struct V_7 * V_8 , T_2 V_82 , T_2 V_83 ,
T_7 V_52 , unsigned long V_18 )
{
struct V_2 * V_3 = F_64 ( V_8 ) ;
struct V_1 * V_10 = NULL ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_7 V_84 ;
T_7 V_85 ;
unsigned int V_86 ;
unsigned int V_87 ;
T_6 V_64 ;
T_6 V_88 ;
F_18 ( F_16 ( V_8 ) , L_18 ,
V_82 , V_83 , V_52 , V_18 ) ;
if ( F_66 ( ! V_52 ) ) {
F_15 ( F_16 ( V_8 ) , L_19 ) ;
return NULL ;
}
V_64 = V_89 ;
V_88 = V_90 | V_91
| V_92
| V_93
| V_94 ;
if ( ! ( ( V_83 | V_82 | V_52 ) & 3 ) ) {
V_64 |= V_95 | V_96 ;
V_86 = V_87 = 2 ;
} else if ( ! ( ( V_83 | V_82 | V_52 ) & 1 ) ) {
V_64 |= V_97 | V_98 ;
V_86 = V_87 = 1 ;
} else {
V_64 |= V_99 | V_100 ;
V_86 = V_87 = 0 ;
}
for ( V_85 = 0 ; V_85 < V_52 ; V_85 += V_84 << V_86 ) {
V_84 = F_67 ( T_7 , ( V_52 - V_85 ) >> V_86 ,
V_101 ) ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_102;
V_10 -> V_34 . V_56 = V_83 + V_85 ;
V_10 -> V_34 . V_51 = V_82 + V_85 ;
V_10 -> V_34 . V_64 = V_64 | V_84 ;
V_10 -> V_34 . V_88 = V_88 ;
V_10 -> V_17 . V_36 = 0 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_32 -> V_17 . V_36 = - V_103 ;
V_32 -> V_52 = V_52 ;
F_68 ( V_10 ) ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_102:
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static struct V_45 *
F_69 ( struct V_7 * V_8 , struct V_104 * V_105 ,
unsigned int V_106 , enum V_107 V_108 ,
unsigned long V_18 )
{
struct V_2 * V_3 = F_64 ( V_8 ) ;
struct V_109 * V_110 = V_8 -> V_47 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_6 V_64 ;
T_6 V_88 ;
T_2 V_111 ;
unsigned int V_112 ;
unsigned int V_113 ;
unsigned int V_24 ;
struct V_104 * V_114 ;
T_7 V_115 = 0 ;
F_18 ( F_16 ( V_8 ) , L_20 ,
V_106 ,
V_108 == V_57 ? L_21 : L_22 ,
V_18 ) ;
if ( F_66 ( ! V_110 || ! V_106 ) ) {
F_15 ( F_16 ( V_8 ) , L_19 ) ;
return NULL ;
}
V_112 = V_110 -> V_112 ;
V_64 = V_89 | V_110 -> V_64 ;
V_88 = V_91 ;
switch ( V_108 ) {
case V_57 :
V_64 |= F_70 ( V_112 ) ;
V_88 |= V_116
| V_92
| V_117
| F_71 ( V_118 ) | F_72 ( V_119 ) ;
V_111 = V_110 -> V_120 ;
F_73 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_6 V_52 ;
T_6 V_121 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_102;
V_121 = F_74 ( V_114 ) ;
V_52 = F_75 ( V_114 ) ;
V_113 = 2 ;
if ( F_66 ( V_121 & 3 || V_52 & 3 ) )
V_113 = 0 ;
V_10 -> V_34 . V_56 = V_121 ;
V_10 -> V_34 . V_51 = V_111 ;
V_10 -> V_34 . V_64 = V_64
| F_76 ( V_113 )
| V_52 >> V_113 ;
V_10 -> V_34 . V_88 = V_88 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_115 += V_52 ;
}
break;
case V_53 :
V_64 |= F_76 ( V_112 ) ;
V_88 |= V_93
| V_122
| V_123
| F_71 ( V_119 ) | F_72 ( V_118 ) ;
V_111 = V_110 -> V_124 ;
F_73 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_6 V_52 ;
T_6 V_121 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_102;
V_121 = F_74 ( V_114 ) ;
V_52 = F_75 ( V_114 ) ;
V_113 = 2 ;
if ( F_66 ( V_121 & 3 || V_52 & 3 ) )
V_113 = 0 ;
V_10 -> V_34 . V_56 = V_111 ;
V_10 -> V_34 . V_51 = V_121 ;
V_10 -> V_34 . V_64 = V_64
| F_70 ( V_113 )
| V_52 >> V_112 ;
V_10 -> V_34 . V_88 = V_88 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_115 += V_52 ;
}
break;
default:
return NULL ;
}
F_68 ( V_33 ) ;
V_32 -> V_17 . V_36 = - V_103 ;
V_32 -> V_52 = V_115 ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_102:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static int
F_77 ( unsigned int V_112 , T_2 V_125 ,
T_7 V_126 , enum V_107 V_108 )
{
if ( V_126 > ( V_101 << V_112 ) )
goto V_127;
if ( F_66 ( V_126 & ( ( 1 << V_112 ) - 1 ) ) )
goto V_127;
if ( F_66 ( V_125 & ( ( 1 << V_112 ) - 1 ) ) )
goto V_127;
if ( F_66 ( ! ( V_108 & ( V_57 | V_53 ) ) ) )
goto V_127;
return 0 ;
V_127:
return - V_128 ;
}
static int
F_78 ( struct V_109 * V_110 , struct V_1 * V_10 ,
unsigned int V_129 , T_2 V_125 ,
T_7 V_126 , enum V_107 V_108 )
{
T_6 V_64 ;
unsigned int V_112 = V_110 -> V_112 ;
V_64 = V_89 | V_110 -> V_64
| F_70 ( V_112 )
| F_76 ( V_112 )
| V_126 >> V_112 ;
switch ( V_108 ) {
case V_57 :
V_10 -> V_34 . V_56 = V_125 + ( V_126 * V_129 ) ;
V_10 -> V_34 . V_51 = V_110 -> V_120 ;
V_10 -> V_34 . V_64 = V_64 ;
V_10 -> V_34 . V_88 = V_116
| V_92
| V_117
| F_71 ( V_118 )
| F_72 ( V_119 ) ;
break;
case V_53 :
V_10 -> V_34 . V_56 = V_110 -> V_124 ;
V_10 -> V_34 . V_51 = V_125 + ( V_126 * V_129 ) ;
V_10 -> V_34 . V_64 = V_64 ;
V_10 -> V_34 . V_88 = V_93
| V_122
| V_123
| F_71 ( V_119 )
| F_72 ( V_118 ) ;
break;
default:
return - V_128 ;
}
return 0 ;
}
static struct V_45 *
F_79 ( struct V_7 * V_8 , T_2 V_125 , T_7 V_130 ,
T_7 V_126 , enum V_107 V_108 )
{
struct V_2 * V_3 = F_64 ( V_8 ) ;
struct V_109 * V_110 = V_8 -> V_47 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
unsigned long V_131 ;
unsigned int V_132 = V_130 / V_126 ;
unsigned int V_24 ;
F_18 ( F_16 ( V_8 ) , L_23 ,
V_108 == V_57 ? L_21 : L_22 ,
V_125 ,
V_132 , V_130 , V_126 ) ;
if ( F_66 ( ! V_110 || ! V_130 || ! V_126 ) ) {
F_15 ( F_16 ( V_8 ) , L_24 ) ;
return NULL ;
}
V_131 = F_80 ( V_58 , & V_3 -> V_59 ) ;
if ( V_131 ) {
F_15 ( F_16 ( V_8 ) , L_25 ) ;
return NULL ;
}
if ( F_77 ( V_110 -> V_112 , V_125 ,
V_126 , V_108 ) )
goto V_127;
for ( V_24 = 0 ; V_24 < V_132 ; V_24 ++ ) {
struct V_1 * V_10 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_102;
if ( F_78 ( V_110 , V_10 , V_24 , V_125 ,
V_126 , V_108 ) )
goto V_102;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_33 -> V_34 . V_35 = V_32 -> V_17 . V_14 ;
V_32 -> V_17 . V_36 = - V_103 ;
V_32 -> V_52 = V_130 ;
return & V_32 -> V_17 ;
V_102:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
F_20 ( V_3 , V_32 ) ;
V_127:
F_81 ( V_58 , & V_3 -> V_59 ) ;
return NULL ;
}
static int F_82 ( struct V_7 * V_8 , enum V_133 V_134 ,
unsigned long V_135 )
{
struct V_2 * V_3 = F_64 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
int V_136 = V_3 -> V_27 . V_136 ;
F_10 ( V_63 ) ;
F_18 ( F_16 ( V_8 ) , L_26 , V_134 ) ;
if ( V_134 == V_137 ) {
F_11 ( & V_3 -> V_26 ) ;
F_34 ( V_12 , V_43 , F_83 ( V_136 ) ) ;
F_61 ( V_138 , & V_3 -> V_59 ) ;
F_17 ( & V_3 -> V_26 ) ;
} else if ( V_134 == V_139 ) {
if ( ! F_40 ( V_138 , & V_3 -> V_59 ) )
return 0 ;
F_11 ( & V_3 -> V_26 ) ;
F_34 ( V_12 , V_78 , F_60 ( V_136 ) ) ;
F_81 ( V_138 , & V_3 -> V_59 ) ;
F_17 ( & V_3 -> V_26 ) ;
} else if ( V_134 == V_140 ) {
struct V_1 * V_10 , * V_22 ;
F_11 ( & V_3 -> V_26 ) ;
F_34 ( V_12 , V_78 , F_60 ( V_136 ) | V_3 -> V_44 ) ;
while ( F_31 ( V_12 , V_141 ) & V_3 -> V_44 )
F_32 () ;
F_22 ( & V_3 -> V_6 , & V_63 ) ;
F_22 ( & V_3 -> V_4 , & V_63 ) ;
F_12 (desc, _desc, &list, desc_node)
F_35 ( V_3 , V_10 ) ;
F_81 ( V_138 , & V_3 -> V_59 ) ;
F_81 ( V_58 , & V_3 -> V_59 ) ;
F_17 ( & V_3 -> V_26 ) ;
} else {
return - V_142 ;
}
return 0 ;
}
static enum V_143
F_84 ( struct V_7 * V_8 ,
T_3 V_36 ,
struct V_144 * V_145 )
{
struct V_2 * V_3 = F_64 ( V_8 ) ;
T_3 V_146 ;
T_3 V_147 ;
enum V_143 V_23 ;
F_11 ( & V_3 -> V_26 ) ;
V_147 = V_3 -> V_46 ;
V_146 = V_8 -> V_36 ;
V_23 = F_85 ( V_36 , V_147 , V_146 ) ;
if ( V_23 != V_148 ) {
F_45 ( V_3 ) ;
V_147 = V_3 -> V_46 ;
V_146 = V_8 -> V_36 ;
V_23 = F_85 ( V_36 , V_147 , V_146 ) ;
}
F_17 ( & V_3 -> V_26 ) ;
if ( V_23 != V_148 )
F_86 ( V_145 , V_147 , V_146 ,
F_1 ( V_3 ) -> V_52 ) ;
else
F_86 ( V_145 , V_147 , V_146 , 0 ) ;
if ( F_40 ( V_138 , & V_3 -> V_59 ) )
V_23 = V_149 ;
F_18 ( F_16 ( V_8 ) , L_27 ,
V_23 , V_36 , V_147 ? V_147 : 0 ,
V_146 ? V_146 : 0 ) ;
return V_23 ;
}
static void F_87 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_64 ( V_8 ) ;
F_18 ( F_16 ( V_8 ) , L_28 ) ;
if ( F_40 ( V_58 , & V_3 -> V_59 ) )
return;
F_11 ( & V_3 -> V_26 ) ;
if ( ! F_28 ( V_3 ) ) {
F_46 ( V_3 ) ;
}
F_17 ( & V_3 -> V_26 ) ;
}
static int F_88 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_64 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 ;
struct V_109 * V_110 ;
int V_24 ;
T_6 V_150 ;
F_10 ( V_25 ) ;
F_18 ( F_16 ( V_8 ) , L_29 ) ;
if ( F_28 ( V_3 ) ) {
F_15 ( F_16 ( V_8 ) , L_30 ) ;
return - V_151 ;
}
V_150 = V_152 ;
V_110 = V_8 -> V_47 ;
if ( V_110 ) {
F_43 ( ! V_110 -> V_153 || V_110 -> V_153 != V_12 -> V_75 . V_76 ) ;
if ( V_110 -> V_150 )
V_150 = V_110 -> V_150 ;
}
if ( ! F_44 ( & V_3 -> V_31 ) )
return V_3 -> V_29 ;
for ( V_24 = 0 ; V_24 < V_154 ; V_24 ++ ) {
V_10 = F_4 ( V_8 , V_155 ) ;
if ( ! V_10 ) {
F_19 ( V_12 -> V_75 . V_76 ,
L_31 , V_24 ) ;
break;
}
F_25 ( & V_10 -> V_5 , & V_25 ) ;
}
F_11 ( & V_3 -> V_26 ) ;
V_3 -> V_29 = V_24 ;
F_89 ( & V_25 , & V_3 -> V_31 ) ;
V_3 -> V_46 = V_8 -> V_36 = 1 ;
F_17 ( & V_3 -> V_26 ) ;
F_33 ( V_3 , V_156 , V_150 ) ;
F_15 ( F_16 ( V_8 ) ,
L_32 ,
V_3 -> V_29 ) ;
return V_3 -> V_29 ;
}
static void F_90 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_64 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 , * V_22 ;
F_10 ( V_63 ) ;
F_15 ( F_16 ( V_8 ) , L_33 ,
V_3 -> V_29 ) ;
F_43 ( ! F_44 ( & V_3 -> V_4 ) ) ;
F_43 ( ! F_44 ( & V_3 -> V_6 ) ) ;
F_43 ( F_28 ( V_3 ) ) ;
F_12 (desc, _desc, &atchan->free_list, desc_node) {
F_18 ( F_16 ( V_8 ) , L_34 , V_10 ) ;
F_14 ( & V_10 -> V_5 ) ;
F_91 ( V_12 -> V_15 , V_10 , V_10 -> V_17 . V_14 ) ;
}
F_22 ( & V_3 -> V_31 , & V_63 ) ;
V_3 -> V_29 = 0 ;
V_3 -> V_59 = 0 ;
F_18 ( F_16 ( V_8 ) , L_35 ) ;
}
static void F_92 ( struct V_11 * V_12 )
{
F_34 ( V_12 , V_157 , 0 ) ;
F_34 ( V_12 , V_158 , - 1L ) ;
while ( F_31 ( V_12 , V_141 ) & V_12 -> V_159 )
F_32 () ;
}
static int T_8 F_93 ( struct V_160 * V_161 )
{
struct V_162 * V_163 ;
struct V_164 * V_165 ;
struct V_11 * V_12 ;
T_7 V_166 ;
int V_69 ;
int V_167 ;
int V_24 ;
V_163 = V_161 -> V_76 . V_168 ;
if ( ! V_163 || V_163 -> V_169 > V_170 )
return - V_128 ;
V_165 = F_94 ( V_161 , V_171 , 0 ) ;
if ( ! V_165 )
return - V_128 ;
V_69 = F_95 ( V_161 , 0 ) ;
if ( V_69 < 0 )
return V_69 ;
V_166 = sizeof( struct V_11 ) ;
V_166 += V_163 -> V_169 * sizeof( struct V_2 ) ;
V_12 = F_96 ( V_166 , V_155 ) ;
if ( ! V_12 )
return - V_172 ;
V_12 -> V_75 . V_173 = V_163 -> V_173 ;
V_12 -> V_159 = ( 1 << V_163 -> V_169 ) - 1 ;
V_166 = V_165 -> V_174 - V_165 -> V_175 + 1 ;
if ( ! F_97 ( V_165 -> V_175 , V_166 , V_161 -> V_76 . V_176 -> V_177 ) ) {
V_167 = - V_103 ;
goto V_178;
}
V_12 -> V_179 = F_98 ( V_165 -> V_175 , V_166 ) ;
if ( ! V_12 -> V_179 ) {
V_167 = - V_172 ;
goto V_180;
}
V_12 -> V_181 = F_99 ( & V_161 -> V_76 , L_36 ) ;
if ( F_100 ( V_12 -> V_181 ) ) {
V_167 = F_101 ( V_12 -> V_181 ) ;
goto V_182;
}
F_102 ( V_12 -> V_181 ) ;
F_92 ( V_12 ) ;
V_167 = F_103 ( V_69 , F_57 , 0 , L_37 , V_12 ) ;
if ( V_167 )
goto V_183;
F_104 ( V_161 , V_12 ) ;
V_12 -> V_15 = F_105 ( L_38 ,
& V_161 -> V_76 , sizeof( struct V_1 ) ,
4 , 0 ) ;
if ( ! V_12 -> V_15 ) {
F_19 ( & V_161 -> V_76 , L_39 ) ;
V_167 = - V_172 ;
goto V_184;
}
while ( F_31 ( V_12 , V_42 ) )
F_32 () ;
F_7 ( & V_12 -> V_75 . V_185 ) ;
for ( V_24 = 0 ; V_24 < V_163 -> V_169 ; V_24 ++ , V_12 -> V_75 . V_77 ++ ) {
struct V_2 * V_3 = & V_12 -> V_8 [ V_24 ] ;
V_3 -> V_27 . V_13 = & V_12 -> V_75 ;
V_3 -> V_27 . V_36 = V_3 -> V_46 = 1 ;
V_3 -> V_27 . V_136 = V_24 ;
F_25 ( & V_3 -> V_27 . V_186 ,
& V_12 -> V_75 . V_185 ) ;
V_3 -> V_187 = V_12 -> V_179 + V_187 ( V_24 ) ;
F_106 ( & V_3 -> V_26 ) ;
V_3 -> V_44 = 1 << V_24 ;
F_7 ( & V_3 -> V_4 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_7 ( & V_3 -> V_31 ) ;
F_107 ( & V_3 -> V_79 , F_53 ,
( unsigned long ) V_3 ) ;
F_108 ( V_3 ) ;
}
V_12 -> V_75 . V_188 = F_88 ;
V_12 -> V_75 . V_189 = F_90 ;
V_12 -> V_75 . V_190 = F_84 ;
V_12 -> V_75 . V_191 = F_87 ;
V_12 -> V_75 . V_76 = & V_161 -> V_76 ;
if ( F_109 ( V_192 , V_12 -> V_75 . V_173 ) )
V_12 -> V_75 . V_193 = F_65 ;
if ( F_109 ( V_194 , V_12 -> V_75 . V_173 ) )
V_12 -> V_75 . V_195 = F_69 ;
if ( F_109 ( V_196 , V_12 -> V_75 . V_173 ) )
V_12 -> V_75 . V_197 = F_79 ;
if ( F_109 ( V_194 , V_12 -> V_75 . V_173 ) ||
F_109 ( V_196 , V_12 -> V_75 . V_173 ) )
V_12 -> V_75 . V_198 = F_82 ;
F_34 ( V_12 , V_157 , V_199 ) ;
F_110 ( & V_161 -> V_76 , L_40 ,
F_109 ( V_192 , V_12 -> V_75 . V_173 ) ? L_41 : L_42 ,
F_109 ( V_194 , V_12 -> V_75 . V_173 ) ? L_43 : L_42 ,
V_12 -> V_75 . V_77 ) ;
F_111 ( & V_12 -> V_75 ) ;
return 0 ;
V_184:
F_104 ( V_161 , NULL ) ;
F_112 ( F_95 ( V_161 , 0 ) , V_12 ) ;
V_183:
F_113 ( V_12 -> V_181 ) ;
F_114 ( V_12 -> V_181 ) ;
V_182:
F_115 ( V_12 -> V_179 ) ;
V_12 -> V_179 = NULL ;
V_180:
F_116 ( V_165 -> V_175 , V_166 ) ;
V_178:
F_117 ( V_12 ) ;
return V_167 ;
}
static int T_9 F_118 ( struct V_160 * V_161 )
{
struct V_11 * V_12 = F_119 ( V_161 ) ;
struct V_7 * V_8 , * V_200 ;
struct V_164 * V_165 ;
F_92 ( V_12 ) ;
F_120 ( & V_12 -> V_75 ) ;
F_121 ( V_12 -> V_15 ) ;
F_104 ( V_161 , NULL ) ;
F_112 ( F_95 ( V_161 , 0 ) , V_12 ) ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_64 ( V_8 ) ;
F_122 ( V_3 ) ;
F_123 ( & V_3 -> V_79 ) ;
F_124 ( & V_3 -> V_79 ) ;
F_14 ( & V_8 -> V_186 ) ;
}
F_113 ( V_12 -> V_181 ) ;
F_114 ( V_12 -> V_181 ) ;
F_115 ( V_12 -> V_179 ) ;
V_12 -> V_179 = NULL ;
V_165 = F_94 ( V_161 , V_171 , 0 ) ;
F_116 ( V_165 -> V_175 , V_165 -> V_174 - V_165 -> V_175 + 1 ) ;
F_117 ( V_12 ) ;
return 0 ;
}
static void F_125 ( struct V_160 * V_161 )
{
struct V_11 * V_12 = F_119 ( V_161 ) ;
F_92 ( F_119 ( V_161 ) ) ;
F_113 ( V_12 -> V_181 ) ;
}
static int F_126 ( struct V_13 * V_76 )
{
struct V_160 * V_161 = F_127 ( V_76 ) ;
struct V_11 * V_12 = F_119 ( V_161 ) ;
F_92 ( F_119 ( V_161 ) ) ;
F_113 ( V_12 -> V_181 ) ;
return 0 ;
}
static int F_128 ( struct V_13 * V_76 )
{
struct V_160 * V_161 = F_127 ( V_76 ) ;
struct V_11 * V_12 = F_119 ( V_161 ) ;
F_102 ( V_12 -> V_181 ) ;
F_34 ( V_12 , V_157 , V_199 ) ;
return 0 ;
}
static int T_8 F_129 ( void )
{
return F_130 ( & V_201 , F_93 ) ;
}
static void T_9 F_131 ( void )
{
F_132 ( & V_201 ) ;
}
