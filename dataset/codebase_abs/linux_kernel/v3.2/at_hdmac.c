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
if ( ! F_40 ( V_3 ) ) {
T_4 V_58 = V_17 -> V_58 ;
void * V_59 = V_17 -> V_60 ;
if ( V_58 )
V_58 ( V_59 ) ;
}
F_41 ( V_17 ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_10 , * V_22 ;
F_10 ( V_61 ) ;
F_18 ( F_16 ( & V_3 -> V_27 ) , L_9 ) ;
F_43 ( F_28 ( V_3 ) ) ;
if ( ! F_44 ( & V_3 -> V_6 ) )
F_27 ( V_3 , F_3 ( V_3 ) ) ;
F_22 ( & V_3 -> V_4 , & V_61 ) ;
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
if ( ! ( V_10 -> V_34 . V_62 & V_63 ) )
return;
F_21 (child, &desc->tx_list, desc_node)
if ( ! ( V_30 -> V_34 . V_62 & V_63 ) )
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
struct V_1 * V_64 ;
struct V_1 * V_30 ;
V_64 = F_1 ( V_3 ) ;
F_49 ( & V_64 -> V_5 ) ;
F_22 ( & V_3 -> V_6 , V_3 -> V_4 . V_33 ) ;
if ( ! F_44 ( & V_3 -> V_4 ) )
F_27 ( V_3 , F_1 ( V_3 ) ) ;
F_50 ( F_16 ( & V_3 -> V_27 ) ,
L_12 ) ;
F_50 ( F_16 ( & V_3 -> V_27 ) ,
L_13 , V_64 -> V_17 . V_36 ) ;
F_51 ( V_3 , & V_64 -> V_34 ) ;
F_21 (child, &bad_desc->tx_list, desc_node)
F_51 ( V_3 , & V_30 -> V_34 ) ;
F_35 ( V_3 , V_64 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_45 * V_17 = & V_32 -> V_17 ;
T_4 V_58 = V_17 -> V_58 ;
void * V_59 = V_17 -> V_60 ;
F_18 ( F_16 ( & V_3 -> V_27 ) ,
L_14 ,
F_29 ( V_3 , V_41 ) ) ;
if ( V_58 )
V_58 ( V_59 ) ;
}
static void F_53 ( unsigned long V_65 )
{
struct V_2 * V_3 = (struct V_2 * ) V_65 ;
unsigned long V_18 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
if ( F_54 ( V_66 , & V_3 -> V_67 ) )
F_48 ( V_3 ) ;
else if ( F_40 ( V_3 ) )
F_52 ( V_3 ) ;
else
F_46 ( V_3 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
}
static T_5 F_55 ( int V_68 , void * V_69 )
{
struct V_11 * V_12 = (struct V_11 * ) V_69 ;
struct V_2 * V_3 ;
int V_24 ;
T_6 V_67 , V_70 , V_71 ;
int V_23 = V_72 ;
do {
V_71 = F_31 ( V_12 , V_73 ) ;
V_67 = F_31 ( V_12 , V_42 ) ;
V_70 = V_67 & V_71 ;
if ( ! V_70 )
break;
F_18 ( V_12 -> V_74 . V_75 ,
L_15 ,
V_67 , V_71 , V_70 ) ;
for ( V_24 = 0 ; V_24 < V_12 -> V_74 . V_76 ; V_24 ++ ) {
V_3 = & V_12 -> V_8 [ V_24 ] ;
if ( V_70 & ( F_56 ( V_24 ) | F_57 ( V_24 ) ) ) {
if ( V_70 & F_57 ( V_24 ) ) {
F_34 ( V_12 , V_77 ,
F_58 ( V_24 ) | V_3 -> V_44 ) ;
F_59 ( V_66 , & V_3 -> V_67 ) ;
}
F_60 ( & V_3 -> V_78 ) ;
V_23 = V_79 ;
}
}
} while ( V_70 );
return V_23 ;
}
static T_3 V_21 ( struct V_45 * V_80 )
{
struct V_1 * V_10 = F_61 ( V_80 ) ;
struct V_2 * V_3 = F_62 ( V_80 -> V_8 ) ;
T_3 V_36 ;
unsigned long V_18 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_36 = F_26 ( V_3 , V_10 ) ;
if ( F_44 ( & V_3 -> V_4 ) ) {
F_18 ( F_16 ( V_80 -> V_8 ) , L_16 ,
V_10 -> V_17 . V_36 ) ;
F_27 ( V_3 , V_10 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_4 ) ;
} else {
F_18 ( F_16 ( V_80 -> V_8 ) , L_17 ,
V_10 -> V_17 . V_36 ) ;
F_25 ( & V_10 -> V_5 , & V_3 -> V_6 ) ;
}
F_17 ( & V_3 -> V_26 , V_18 ) ;
return V_36 ;
}
static struct V_45 *
F_63 ( struct V_7 * V_8 , T_2 V_81 , T_2 V_82 ,
T_7 V_52 , unsigned long V_18 )
{
struct V_2 * V_3 = F_62 ( V_8 ) ;
struct V_1 * V_10 = NULL ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_7 V_83 ;
T_7 V_84 ;
unsigned int V_85 ;
unsigned int V_86 ;
T_6 V_62 ;
T_6 V_87 ;
F_18 ( F_16 ( V_8 ) , L_18 ,
V_81 , V_82 , V_52 , V_18 ) ;
if ( F_64 ( ! V_52 ) ) {
F_15 ( F_16 ( V_8 ) , L_19 ) ;
return NULL ;
}
V_62 = V_88 ;
V_87 = V_89 | V_90
| V_91
| V_92
| V_93 ;
if ( ! ( ( V_82 | V_81 | V_52 ) & 3 ) ) {
V_62 |= V_94 | V_95 ;
V_85 = V_86 = 2 ;
} else if ( ! ( ( V_82 | V_81 | V_52 ) & 1 ) ) {
V_62 |= V_96 | V_97 ;
V_85 = V_86 = 1 ;
} else {
V_62 |= V_98 | V_99 ;
V_85 = V_86 = 0 ;
}
for ( V_84 = 0 ; V_84 < V_52 ; V_84 += V_83 << V_85 ) {
V_83 = F_65 ( T_7 , ( V_52 - V_84 ) >> V_85 ,
V_100 ) ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_101;
V_10 -> V_34 . V_56 = V_82 + V_84 ;
V_10 -> V_34 . V_51 = V_81 + V_84 ;
V_10 -> V_34 . V_62 = V_62 | V_83 ;
V_10 -> V_34 . V_87 = V_87 ;
V_10 -> V_17 . V_36 = 0 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_32 -> V_17 . V_36 = - V_102 ;
V_32 -> V_52 = V_52 ;
F_66 ( V_10 ) ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_101:
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static struct V_45 *
F_67 ( struct V_7 * V_8 , struct V_103 * V_104 ,
unsigned int V_105 , enum V_106 V_107 ,
unsigned long V_18 )
{
struct V_2 * V_3 = F_62 ( V_8 ) ;
struct V_108 * V_109 = V_8 -> V_47 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
T_6 V_62 ;
T_6 V_87 ;
T_2 V_110 ;
unsigned int V_111 ;
unsigned int V_112 ;
unsigned int V_24 ;
struct V_103 * V_113 ;
T_7 V_114 = 0 ;
F_18 ( F_16 ( V_8 ) , L_20 ,
V_105 ,
V_107 == V_57 ? L_21 : L_22 ,
V_18 ) ;
if ( F_64 ( ! V_109 || ! V_105 ) ) {
F_15 ( F_16 ( V_8 ) , L_19 ) ;
return NULL ;
}
V_111 = V_109 -> V_111 ;
V_62 = V_88 | V_109 -> V_62 ;
V_87 = V_90 ;
switch ( V_107 ) {
case V_57 :
V_62 |= F_68 ( V_111 ) ;
V_87 |= V_115
| V_91
| V_116
| F_69 ( V_117 ) | F_70 ( V_118 ) ;
V_110 = V_109 -> V_119 ;
F_71 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_6 V_52 ;
T_6 V_120 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_101;
V_120 = F_72 ( V_113 ) ;
V_52 = F_73 ( V_113 ) ;
V_112 = 2 ;
if ( F_64 ( V_120 & 3 || V_52 & 3 ) )
V_112 = 0 ;
V_10 -> V_34 . V_56 = V_120 ;
V_10 -> V_34 . V_51 = V_110 ;
V_10 -> V_34 . V_62 = V_62
| F_74 ( V_112 )
| V_52 >> V_112 ;
V_10 -> V_34 . V_87 = V_87 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_114 += V_52 ;
}
break;
case V_53 :
V_62 |= F_74 ( V_111 ) ;
V_87 |= V_92
| V_121
| V_122
| F_69 ( V_118 ) | F_70 ( V_117 ) ;
V_110 = V_109 -> V_123 ;
F_71 (sgl, sg, sg_len, i) {
struct V_1 * V_10 ;
T_6 V_52 ;
T_6 V_120 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_101;
V_120 = F_72 ( V_113 ) ;
V_52 = F_73 ( V_113 ) ;
V_112 = 2 ;
if ( F_64 ( V_120 & 3 || V_52 & 3 ) )
V_112 = 0 ;
V_10 -> V_34 . V_56 = V_110 ;
V_10 -> V_34 . V_51 = V_120 ;
V_10 -> V_34 . V_62 = V_62
| F_68 ( V_112 )
| V_52 >> V_111 ;
V_10 -> V_34 . V_87 = V_87 ;
F_24 ( & V_32 , & V_33 , V_10 ) ;
V_114 += V_52 ;
}
break;
default:
return NULL ;
}
F_66 ( V_33 ) ;
V_32 -> V_17 . V_36 = - V_102 ;
V_32 -> V_52 = V_114 ;
V_32 -> V_17 . V_18 = V_18 ;
return & V_32 -> V_17 ;
V_101:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
F_20 ( V_3 , V_32 ) ;
return NULL ;
}
static int
F_75 ( unsigned int V_111 , T_2 V_124 ,
T_7 V_125 , enum V_106 V_107 )
{
if ( V_125 > ( V_100 << V_111 ) )
goto V_126;
if ( F_64 ( V_125 & ( ( 1 << V_111 ) - 1 ) ) )
goto V_126;
if ( F_64 ( V_124 & ( ( 1 << V_111 ) - 1 ) ) )
goto V_126;
if ( F_64 ( ! ( V_107 & ( V_57 | V_53 ) ) ) )
goto V_126;
return 0 ;
V_126:
return - V_127 ;
}
static int
F_76 ( struct V_108 * V_109 , struct V_1 * V_10 ,
unsigned int V_128 , T_2 V_124 ,
T_7 V_125 , enum V_106 V_107 )
{
T_6 V_62 ;
unsigned int V_111 = V_109 -> V_111 ;
V_62 = V_88 | V_109 -> V_62
| F_68 ( V_111 )
| F_74 ( V_111 )
| V_125 >> V_111 ;
switch ( V_107 ) {
case V_57 :
V_10 -> V_34 . V_56 = V_124 + ( V_125 * V_128 ) ;
V_10 -> V_34 . V_51 = V_109 -> V_119 ;
V_10 -> V_34 . V_62 = V_62 ;
V_10 -> V_34 . V_87 = V_115
| V_91
| V_116
| F_69 ( V_117 )
| F_70 ( V_118 ) ;
break;
case V_53 :
V_10 -> V_34 . V_56 = V_109 -> V_123 ;
V_10 -> V_34 . V_51 = V_124 + ( V_125 * V_128 ) ;
V_10 -> V_34 . V_62 = V_62 ;
V_10 -> V_34 . V_87 = V_92
| V_121
| V_122
| F_69 ( V_118 )
| F_70 ( V_117 ) ;
break;
default:
return - V_127 ;
}
return 0 ;
}
static struct V_45 *
F_77 ( struct V_7 * V_8 , T_2 V_124 , T_7 V_129 ,
T_7 V_125 , enum V_106 V_107 )
{
struct V_2 * V_3 = F_62 ( V_8 ) ;
struct V_108 * V_109 = V_8 -> V_47 ;
struct V_1 * V_32 = NULL ;
struct V_1 * V_33 = NULL ;
unsigned long V_130 ;
unsigned int V_131 = V_129 / V_125 ;
unsigned int V_24 ;
F_18 ( F_16 ( V_8 ) , L_23 ,
V_107 == V_57 ? L_21 : L_22 ,
V_124 ,
V_131 , V_129 , V_125 ) ;
if ( F_64 ( ! V_109 || ! V_129 || ! V_125 ) ) {
F_15 ( F_16 ( V_8 ) , L_24 ) ;
return NULL ;
}
V_130 = F_78 ( V_132 , & V_3 -> V_67 ) ;
if ( V_130 ) {
F_15 ( F_16 ( V_8 ) , L_25 ) ;
return NULL ;
}
if ( F_75 ( V_109 -> V_111 , V_124 ,
V_125 , V_107 ) )
goto V_126;
for ( V_24 = 0 ; V_24 < V_131 ; V_24 ++ ) {
struct V_1 * V_10 ;
V_10 = F_9 ( V_3 ) ;
if ( ! V_10 )
goto V_101;
if ( F_76 ( V_109 , V_10 , V_24 , V_124 ,
V_125 , V_107 ) )
goto V_101;
F_24 ( & V_32 , & V_33 , V_10 ) ;
}
V_33 -> V_34 . V_35 = V_32 -> V_17 . V_14 ;
V_32 -> V_17 . V_36 = - V_102 ;
V_32 -> V_52 = V_129 ;
return & V_32 -> V_17 ;
V_101:
F_19 ( F_16 ( V_8 ) , L_3 ) ;
F_20 ( V_3 , V_32 ) ;
V_126:
F_79 ( V_132 , & V_3 -> V_67 ) ;
return NULL ;
}
static int F_80 ( struct V_7 * V_8 , enum V_133 V_134 ,
unsigned long V_135 )
{
struct V_2 * V_3 = F_62 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
int V_136 = V_3 -> V_27 . V_136 ;
unsigned long V_18 ;
F_10 ( V_61 ) ;
F_18 ( F_16 ( V_8 ) , L_26 , V_134 ) ;
if ( V_134 == V_137 ) {
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_34 ( V_12 , V_43 , F_81 ( V_136 ) ) ;
F_59 ( V_138 , & V_3 -> V_67 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else if ( V_134 == V_139 ) {
if ( ! F_82 ( V_3 ) )
return 0 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_34 ( V_12 , V_77 , F_58 ( V_136 ) ) ;
F_79 ( V_138 , & V_3 -> V_67 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else if ( V_134 == V_140 ) {
struct V_1 * V_10 , * V_22 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
F_34 ( V_12 , V_77 , F_58 ( V_136 ) | V_3 -> V_44 ) ;
while ( F_31 ( V_12 , V_141 ) & V_3 -> V_44 )
F_32 () ;
F_22 ( & V_3 -> V_6 , & V_61 ) ;
F_22 ( & V_3 -> V_4 , & V_61 ) ;
F_12 (desc, _desc, &list, desc_node)
F_35 ( V_3 , V_10 ) ;
F_79 ( V_138 , & V_3 -> V_67 ) ;
F_79 ( V_132 , & V_3 -> V_67 ) ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
} else {
return - V_142 ;
}
return 0 ;
}
static enum V_143
F_83 ( struct V_7 * V_8 ,
T_3 V_36 ,
struct V_144 * V_145 )
{
struct V_2 * V_3 = F_62 ( V_8 ) ;
T_3 V_146 ;
T_3 V_147 ;
unsigned long V_18 ;
enum V_143 V_23 ;
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_147 = V_3 -> V_46 ;
V_146 = V_8 -> V_36 ;
V_23 = F_84 ( V_36 , V_147 , V_146 ) ;
if ( V_23 != V_148 ) {
F_45 ( V_3 ) ;
V_147 = V_3 -> V_46 ;
V_146 = V_8 -> V_36 ;
V_23 = F_84 ( V_36 , V_147 , V_146 ) ;
}
F_17 ( & V_3 -> V_26 , V_18 ) ;
if ( V_23 != V_148 )
F_85 ( V_145 , V_147 , V_146 ,
F_1 ( V_3 ) -> V_52 ) ;
else
F_85 ( V_145 , V_147 , V_146 , 0 ) ;
if ( F_82 ( V_3 ) )
V_23 = V_149 ;
F_18 ( F_16 ( V_8 ) , L_27 ,
V_23 , V_36 , V_147 ? V_147 : 0 ,
V_146 ? V_146 : 0 ) ;
return V_23 ;
}
static void F_86 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_62 ( V_8 ) ;
unsigned long V_18 ;
F_18 ( F_16 ( V_8 ) , L_28 ) ;
if ( F_40 ( V_3 ) )
return;
F_11 ( & V_3 -> V_26 , V_18 ) ;
if ( ! F_28 ( V_3 ) ) {
F_46 ( V_3 ) ;
}
F_17 ( & V_3 -> V_26 , V_18 ) ;
}
static int F_87 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_62 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 ;
struct V_108 * V_109 ;
unsigned long V_18 ;
int V_24 ;
T_6 V_150 ;
F_10 ( V_25 ) ;
F_18 ( F_16 ( V_8 ) , L_29 ) ;
if ( F_28 ( V_3 ) ) {
F_15 ( F_16 ( V_8 ) , L_30 ) ;
return - V_151 ;
}
V_150 = V_152 ;
V_109 = V_8 -> V_47 ;
if ( V_109 ) {
F_43 ( ! V_109 -> V_153 || V_109 -> V_153 != V_12 -> V_74 . V_75 ) ;
if ( V_109 -> V_150 )
V_150 = V_109 -> V_150 ;
}
if ( ! F_44 ( & V_3 -> V_31 ) )
return V_3 -> V_29 ;
for ( V_24 = 0 ; V_24 < V_154 ; V_24 ++ ) {
V_10 = F_4 ( V_8 , V_155 ) ;
if ( ! V_10 ) {
F_19 ( V_12 -> V_74 . V_75 ,
L_31 , V_24 ) ;
break;
}
F_25 ( & V_10 -> V_5 , & V_25 ) ;
}
F_11 ( & V_3 -> V_26 , V_18 ) ;
V_3 -> V_29 = V_24 ;
F_88 ( & V_25 , & V_3 -> V_31 ) ;
V_3 -> V_46 = V_8 -> V_36 = 1 ;
F_17 ( & V_3 -> V_26 , V_18 ) ;
F_33 ( V_3 , V_156 , V_150 ) ;
F_15 ( F_16 ( V_8 ) ,
L_32 ,
V_3 -> V_29 ) ;
return V_3 -> V_29 ;
}
static void F_89 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_62 ( V_8 ) ;
struct V_11 * V_12 = F_5 ( V_8 -> V_13 ) ;
struct V_1 * V_10 , * V_22 ;
F_10 ( V_61 ) ;
F_15 ( F_16 ( V_8 ) , L_33 ,
V_3 -> V_29 ) ;
F_43 ( ! F_44 ( & V_3 -> V_4 ) ) ;
F_43 ( ! F_44 ( & V_3 -> V_6 ) ) ;
F_43 ( F_28 ( V_3 ) ) ;
F_12 (desc, _desc, &atchan->free_list, desc_node) {
F_18 ( F_16 ( V_8 ) , L_34 , V_10 ) ;
F_14 ( & V_10 -> V_5 ) ;
F_90 ( V_12 -> V_15 , V_10 , V_10 -> V_17 . V_14 ) ;
}
F_22 ( & V_3 -> V_31 , & V_61 ) ;
V_3 -> V_29 = 0 ;
V_3 -> V_67 = 0 ;
F_18 ( F_16 ( V_8 ) , L_35 ) ;
}
static void F_91 ( struct V_11 * V_12 )
{
F_34 ( V_12 , V_157 , 0 ) ;
F_34 ( V_12 , V_158 , - 1L ) ;
while ( F_31 ( V_12 , V_141 ) & V_12 -> V_159 )
F_32 () ;
}
static int T_8 F_92 ( struct V_160 * V_161 )
{
struct V_162 * V_163 ;
struct V_164 * V_165 ;
struct V_11 * V_12 ;
T_7 V_166 ;
int V_68 ;
int V_167 ;
int V_24 ;
V_163 = V_161 -> V_75 . V_168 ;
if ( ! V_163 || V_163 -> V_169 > V_170 )
return - V_127 ;
V_165 = F_93 ( V_161 , V_171 , 0 ) ;
if ( ! V_165 )
return - V_127 ;
V_68 = F_94 ( V_161 , 0 ) ;
if ( V_68 < 0 )
return V_68 ;
V_166 = sizeof( struct V_11 ) ;
V_166 += V_163 -> V_169 * sizeof( struct V_2 ) ;
V_12 = F_95 ( V_166 , V_155 ) ;
if ( ! V_12 )
return - V_172 ;
V_12 -> V_74 . V_173 = V_163 -> V_173 ;
V_12 -> V_159 = ( 1 << V_163 -> V_169 ) - 1 ;
V_166 = F_96 ( V_165 ) ;
if ( ! F_97 ( V_165 -> V_174 , V_166 , V_161 -> V_75 . V_175 -> V_176 ) ) {
V_167 = - V_102 ;
goto V_177;
}
V_12 -> V_178 = F_98 ( V_165 -> V_174 , V_166 ) ;
if ( ! V_12 -> V_178 ) {
V_167 = - V_172 ;
goto V_179;
}
V_12 -> V_180 = F_99 ( & V_161 -> V_75 , L_36 ) ;
if ( F_100 ( V_12 -> V_180 ) ) {
V_167 = F_101 ( V_12 -> V_180 ) ;
goto V_181;
}
F_102 ( V_12 -> V_180 ) ;
F_91 ( V_12 ) ;
V_167 = F_103 ( V_68 , F_55 , 0 , L_37 , V_12 ) ;
if ( V_167 )
goto V_182;
F_104 ( V_161 , V_12 ) ;
V_12 -> V_15 = F_105 ( L_38 ,
& V_161 -> V_75 , sizeof( struct V_1 ) ,
4 , 0 ) ;
if ( ! V_12 -> V_15 ) {
F_19 ( & V_161 -> V_75 , L_39 ) ;
V_167 = - V_172 ;
goto V_183;
}
while ( F_31 ( V_12 , V_42 ) )
F_32 () ;
F_7 ( & V_12 -> V_74 . V_184 ) ;
for ( V_24 = 0 ; V_24 < V_163 -> V_169 ; V_24 ++ ) {
struct V_2 * V_3 = & V_12 -> V_8 [ V_24 ] ;
V_3 -> V_27 . V_13 = & V_12 -> V_74 ;
V_3 -> V_27 . V_36 = V_3 -> V_46 = 1 ;
F_25 ( & V_3 -> V_27 . V_185 ,
& V_12 -> V_74 . V_184 ) ;
V_3 -> V_186 = V_12 -> V_178 + V_186 ( V_24 ) ;
F_106 ( & V_3 -> V_26 ) ;
V_3 -> V_44 = 1 << V_24 ;
F_7 ( & V_3 -> V_4 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_7 ( & V_3 -> V_31 ) ;
F_107 ( & V_3 -> V_78 , F_53 ,
( unsigned long ) V_3 ) ;
F_108 ( V_3 ) ;
}
V_12 -> V_74 . V_187 = F_87 ;
V_12 -> V_74 . V_188 = F_89 ;
V_12 -> V_74 . V_189 = F_83 ;
V_12 -> V_74 . V_190 = F_86 ;
V_12 -> V_74 . V_75 = & V_161 -> V_75 ;
if ( F_109 ( V_191 , V_12 -> V_74 . V_173 ) )
V_12 -> V_74 . V_192 = F_63 ;
if ( F_109 ( V_193 , V_12 -> V_74 . V_173 ) ) {
V_12 -> V_74 . V_194 = F_67 ;
F_110 ( V_195 , V_12 -> V_74 . V_173 ) ;
V_12 -> V_74 . V_196 = F_77 ;
V_12 -> V_74 . V_197 = F_80 ;
}
F_34 ( V_12 , V_157 , V_198 ) ;
F_111 ( & V_161 -> V_75 , L_40 ,
F_109 ( V_191 , V_12 -> V_74 . V_173 ) ? L_41 : L_42 ,
F_109 ( V_193 , V_12 -> V_74 . V_173 ) ? L_43 : L_42 ,
V_163 -> V_169 ) ;
F_112 ( & V_12 -> V_74 ) ;
return 0 ;
V_183:
F_104 ( V_161 , NULL ) ;
F_113 ( F_94 ( V_161 , 0 ) , V_12 ) ;
V_182:
F_114 ( V_12 -> V_180 ) ;
F_115 ( V_12 -> V_180 ) ;
V_181:
F_116 ( V_12 -> V_178 ) ;
V_12 -> V_178 = NULL ;
V_179:
F_117 ( V_165 -> V_174 , V_166 ) ;
V_177:
F_118 ( V_12 ) ;
return V_167 ;
}
static int T_9 F_119 ( struct V_160 * V_161 )
{
struct V_11 * V_12 = F_120 ( V_161 ) ;
struct V_7 * V_8 , * V_199 ;
struct V_164 * V_165 ;
F_91 ( V_12 ) ;
F_121 ( & V_12 -> V_74 ) ;
F_122 ( V_12 -> V_15 ) ;
F_104 ( V_161 , NULL ) ;
F_113 ( F_94 ( V_161 , 0 ) , V_12 ) ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_62 ( V_8 ) ;
F_123 ( V_3 ) ;
F_124 ( & V_3 -> V_78 ) ;
F_125 ( & V_3 -> V_78 ) ;
F_14 ( & V_8 -> V_185 ) ;
}
F_114 ( V_12 -> V_180 ) ;
F_115 ( V_12 -> V_180 ) ;
F_116 ( V_12 -> V_178 ) ;
V_12 -> V_178 = NULL ;
V_165 = F_93 ( V_161 , V_171 , 0 ) ;
F_117 ( V_165 -> V_174 , F_96 ( V_165 ) ) ;
F_118 ( V_12 ) ;
return 0 ;
}
static void F_126 ( struct V_160 * V_161 )
{
struct V_11 * V_12 = F_120 ( V_161 ) ;
F_91 ( F_120 ( V_161 ) ) ;
F_114 ( V_12 -> V_180 ) ;
}
static int F_127 ( struct V_13 * V_75 )
{
struct V_160 * V_161 = F_128 ( V_75 ) ;
struct V_11 * V_12 = F_120 ( V_161 ) ;
struct V_7 * V_8 , * V_199 ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_62 ( V_8 ) ;
if ( F_28 ( V_3 ) && ! F_40 ( V_3 ) )
return - V_200 ;
}
return 0 ;
}
static void F_129 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = & V_3 -> V_27 ;
if ( ! F_82 ( V_3 ) ) {
F_130 ( F_16 ( V_8 ) ,
L_44 ) ;
F_80 ( V_8 , V_137 , 0 ) ;
}
V_3 -> V_201 = F_29 ( V_3 , V_41 ) ;
F_30 ( V_3 ) ;
}
static int F_131 ( struct V_13 * V_75 )
{
struct V_160 * V_161 = F_128 ( V_75 ) ;
struct V_11 * V_12 = F_120 ( V_161 ) ;
struct V_7 * V_8 , * V_199 ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_62 ( V_8 ) ;
if ( F_40 ( V_3 ) )
F_129 ( V_3 ) ;
V_3 -> V_202 = F_29 ( V_3 , V_156 ) ;
}
V_12 -> V_203 = F_31 ( V_12 , V_73 ) ;
F_91 ( V_12 ) ;
F_114 ( V_12 -> V_180 ) ;
return 0 ;
}
static void F_132 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_5 ( V_3 -> V_27 . V_13 ) ;
F_33 ( V_3 , V_37 , 0 ) ;
F_33 ( V_3 , V_38 , 0 ) ;
F_33 ( V_3 , V_39 , 0 ) ;
F_33 ( V_3 , V_40 , 0 ) ;
F_33 ( V_3 , V_41 , V_3 -> V_201 ) ;
F_34 ( V_12 , V_43 , V_3 -> V_44 ) ;
F_30 ( V_3 ) ;
}
static int F_133 ( struct V_13 * V_75 )
{
struct V_160 * V_161 = F_128 ( V_75 ) ;
struct V_11 * V_12 = F_120 ( V_161 ) ;
struct V_7 * V_8 , * V_199 ;
F_102 ( V_12 -> V_180 ) ;
F_34 ( V_12 , V_157 , V_198 ) ;
while ( F_31 ( V_12 , V_42 ) )
F_32 () ;
F_34 ( V_12 , V_204 , V_12 -> V_203 ) ;
F_12 (chan, _chan, &atdma->dma_common.channels,
device_node) {
struct V_2 * V_3 = F_62 ( V_8 ) ;
F_33 ( V_3 , V_156 , V_3 -> V_202 ) ;
if ( F_40 ( V_3 ) )
F_132 ( V_3 ) ;
}
return 0 ;
}
static int T_8 F_134 ( void )
{
return F_135 ( & V_205 , F_92 ) ;
}
static void T_9 F_136 ( void )
{
F_137 ( & V_205 ) ;
}
