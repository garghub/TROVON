static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 -> V_1 ;
}
static struct V_1 * F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_1 . V_5 ;
}
static struct V_6 * F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 -> V_9 . V_10 , struct V_6 , V_11 ) ;
}
static struct V_6 * F_5 ( struct V_7 * V_8 )
{
struct V_6 * V_12 , * V_13 ;
struct V_6 * V_14 = NULL ;
unsigned int V_15 = 0 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &dwc->free_list, desc_node) {
V_15 ++ ;
if ( F_8 ( & V_12 -> V_18 ) ) {
F_9 ( & V_12 -> V_11 ) ;
V_14 = V_12 ;
break;
}
F_10 ( F_1 ( & V_8 -> V_3 ) , L_1 , V_12 ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_12 ( F_1 ( & V_8 -> V_3 ) , L_2 , V_15 ) ;
return V_14 ;
}
static void F_13 ( struct V_7 * V_8 , struct V_6 * V_12 )
{
struct V_6 * V_19 ;
F_14 (child, &desc->tx_list, desc_node)
F_15 ( F_2 ( & V_8 -> V_3 ) ,
V_19 -> V_18 . V_20 , sizeof( V_19 -> V_21 ) ,
V_22 ) ;
F_15 ( F_2 ( & V_8 -> V_3 ) ,
V_12 -> V_18 . V_20 , sizeof( V_12 -> V_21 ) ,
V_22 ) ;
}
static void F_16 ( struct V_7 * V_8 , struct V_6 * V_12 )
{
unsigned long V_16 ;
if ( V_12 ) {
struct V_6 * V_19 ;
F_13 ( V_8 , V_12 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_14 (child, &desc->tx_list, desc_node)
F_12 ( F_1 ( & V_8 -> V_3 ) ,
L_3 ,
V_19 ) ;
F_17 ( & V_12 -> V_23 , & V_8 -> V_24 ) ;
F_12 ( F_1 ( & V_8 -> V_3 ) , L_4 , V_12 ) ;
F_18 ( & V_12 -> V_11 , & V_8 -> V_24 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
}
static void F_19 ( struct V_7 * V_8 )
{
struct V_25 * V_26 = F_20 ( V_8 -> V_3 . V_1 ) ;
struct V_27 * V_28 = V_8 -> V_3 . V_29 ;
T_1 V_30 = V_31 ;
T_1 V_32 = F_21 ( V_8 -> V_33 ) ;
if ( V_8 -> V_34 == true )
return;
if ( V_28 ) {
F_22 ( ! V_28 -> V_35 || V_28 -> V_35 != V_26 -> V_36 . V_4 ) ;
V_30 = V_28 -> V_37 ;
V_32 |= V_28 -> V_38 & ~ V_39 ;
}
F_23 ( V_8 , V_40 , V_32 ) ;
F_23 ( V_8 , V_41 , V_30 ) ;
F_24 ( V_26 , V_42 . V_43 , V_8 -> V_44 ) ;
F_24 ( V_26 , V_42 . ERROR , V_8 -> V_44 ) ;
V_8 -> V_34 = true ;
}
static inline unsigned int F_25 ( unsigned long long V_45 )
{
if ( ! ( V_45 & 7 ) )
return 3 ;
else if ( ! ( V_45 & 3 ) )
return 2 ;
else if ( ! ( V_45 & 1 ) )
return 1 ;
return 0 ;
}
static void F_26 ( struct V_7 * V_8 )
{
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_5 ,
F_28 ( V_8 , V_46 ) ,
F_28 ( V_8 , V_47 ) ,
F_28 ( V_8 , V_48 ) ,
F_28 ( V_8 , V_49 ) ,
F_28 ( V_8 , V_50 ) ) ;
}
static inline void F_29 ( struct V_25 * V_26 , struct V_7 * V_8 )
{
F_30 ( V_26 , V_51 , V_8 -> V_44 ) ;
while ( F_31 ( V_26 , V_51 ) & V_8 -> V_44 )
F_32 () ;
}
static void F_33 ( struct V_7 * V_8 , struct V_6 * V_52 )
{
struct V_25 * V_26 = F_20 ( V_8 -> V_3 . V_1 ) ;
if ( F_31 ( V_26 , V_51 ) & V_8 -> V_44 ) {
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ) ;
F_26 ( V_8 ) ;
return;
}
F_19 ( V_8 ) ;
F_23 ( V_8 , V_48 , V_52 -> V_18 . V_20 ) ;
F_23 ( V_8 , V_50 ,
V_53 | V_54 ) ;
F_23 ( V_8 , V_49 , 0 ) ;
F_24 ( V_26 , V_51 , V_8 -> V_44 ) ;
}
static void
F_34 ( struct V_7 * V_8 , struct V_6 * V_12 ,
bool V_55 )
{
T_2 V_56 = NULL ;
void * V_57 = NULL ;
struct V_58 * V_18 = & V_12 -> V_18 ;
struct V_6 * V_19 ;
unsigned long V_16 ;
F_12 ( F_1 ( & V_8 -> V_3 ) , L_7 , V_18 -> V_59 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_35 ( V_18 ) ;
if ( V_55 ) {
V_56 = V_18 -> V_56 ;
V_57 = V_18 -> V_60 ;
}
F_13 ( V_8 , V_12 ) ;
F_14 (child, &desc->tx_list, desc_node)
F_36 ( & V_19 -> V_18 ) ;
F_36 ( & V_12 -> V_18 ) ;
F_17 ( & V_12 -> V_23 , & V_8 -> V_24 ) ;
F_37 ( & V_12 -> V_11 , & V_8 -> V_24 ) ;
if ( ! V_8 -> V_3 . V_29 ) {
struct V_1 * V_5 = F_2 ( & V_8 -> V_3 ) ;
if ( ! ( V_18 -> V_16 & V_61 ) ) {
if ( V_18 -> V_16 & V_62 )
F_38 ( V_5 , V_12 -> V_21 . V_63 ,
V_12 -> V_64 , V_65 ) ;
else
F_39 ( V_5 , V_12 -> V_21 . V_63 ,
V_12 -> V_64 , V_65 ) ;
}
if ( ! ( V_18 -> V_16 & V_66 ) ) {
if ( V_18 -> V_16 & V_67 )
F_38 ( V_5 , V_12 -> V_21 . V_68 ,
V_12 -> V_64 , V_22 ) ;
else
F_39 ( V_5 , V_12 -> V_21 . V_68 ,
V_12 -> V_64 , V_22 ) ;
}
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
if ( V_55 && V_56 )
V_56 ( V_57 ) ;
}
static void F_40 ( struct V_25 * V_26 , struct V_7 * V_8 )
{
struct V_6 * V_12 , * V_13 ;
F_41 ( V_69 ) ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( F_31 ( V_26 , V_51 ) & V_8 -> V_44 ) {
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_8 ) ;
F_29 ( V_26 , V_8 ) ;
}
F_17 ( & V_8 -> V_9 , & V_69 ) ;
if ( ! F_42 ( & V_8 -> V_70 ) ) {
F_37 ( V_8 -> V_70 . V_10 , & V_8 -> V_9 ) ;
F_33 ( V_8 , F_3 ( V_8 ) ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node)
F_34 ( V_8 , V_12 , true ) ;
}
static void F_43 ( struct V_25 * V_26 , struct V_7 * V_8 )
{
T_3 V_71 ;
struct V_6 * V_12 , * V_13 ;
struct V_6 * V_19 ;
T_1 V_72 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_71 = F_28 ( V_8 , V_48 ) ;
V_72 = F_31 ( V_26 , V_73 . V_43 ) ;
if ( V_72 & V_8 -> V_44 ) {
F_44 ( V_26 , V_74 . V_43 , V_8 -> V_44 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_40 ( V_26 , V_8 ) ;
return;
}
if ( F_42 ( & V_8 -> V_9 ) ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_12 ( F_1 ( & V_8 -> V_3 ) , L_9 , V_75 ,
( unsigned long long ) V_71 ) ;
F_7 (desc, _desc, &dwc->active_list, desc_node) {
if ( V_12 -> V_18 . V_20 == V_71 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
if ( V_12 -> V_21 . V_71 == V_71 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_14 (child, &desc->tx_list, desc_node)
if ( V_19 -> V_21 . V_71 == V_71 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_34 ( V_8 , V_12 , true ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
}
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_10 ) ;
F_29 ( V_26 , V_8 ) ;
if ( ! F_42 ( & V_8 -> V_70 ) ) {
F_37 ( V_8 -> V_70 . V_10 , & V_8 -> V_9 ) ;
F_33 ( V_8 , F_3 ( V_8 ) ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
static inline void F_45 ( struct V_7 * V_8 , struct V_76 * V_21 )
{
F_46 ( V_77 , F_1 ( & V_8 -> V_3 ) ,
L_11 ,
V_21 -> V_68 , V_21 -> V_63 , V_21 -> V_71 , V_21 -> V_78 , V_21 -> V_79 ) ;
}
static void F_47 ( struct V_25 * V_26 , struct V_7 * V_8 )
{
struct V_6 * V_80 ;
struct V_6 * V_19 ;
unsigned long V_16 ;
F_43 ( V_26 , V_8 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_80 = F_3 ( V_8 ) ;
F_48 ( & V_80 -> V_11 ) ;
F_37 ( V_8 -> V_70 . V_10 , V_8 -> V_9 . V_81 ) ;
F_44 ( V_26 , V_74 . ERROR , V_8 -> V_44 ) ;
if ( ! F_42 ( & V_8 -> V_9 ) )
F_33 ( V_8 , F_3 ( V_8 ) ) ;
F_46 ( V_77 , F_1 ( & V_8 -> V_3 ) ,
L_12 ) ;
F_46 ( V_77 , F_1 ( & V_8 -> V_3 ) ,
L_13 , V_80 -> V_18 . V_59 ) ;
F_45 ( V_8 , & V_80 -> V_21 ) ;
F_14 (child, &bad_desc->tx_list, desc_node)
F_45 ( V_8 , & V_19 -> V_21 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_34 ( V_8 , V_80 , true ) ;
}
inline T_3 F_49 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
return F_28 ( V_8 , V_46 ) ;
}
inline T_3 F_51 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
return F_28 ( V_8 , V_47 ) ;
}
static void F_52 ( struct V_25 * V_26 , struct V_7 * V_8 ,
T_1 V_82 , T_1 V_72 )
{
unsigned long V_16 ;
if ( V_8 -> V_44 ) {
void (* V_56)( void * V_57 );
void * V_60 ;
F_12 ( F_1 ( & V_8 -> V_3 ) , L_14 ,
F_28 ( V_8 , V_48 ) ) ;
V_56 = V_8 -> V_83 -> V_84 ;
V_60 = V_8 -> V_83 -> V_85 ;
if ( V_56 )
V_56 ( V_60 ) ;
}
if ( F_53 ( V_82 & V_8 -> V_44 ) ||
F_53 ( V_72 & V_8 -> V_44 ) ) {
int V_15 ;
F_27 ( F_1 ( & V_8 -> V_3 ) , L_15
L_16 ,
V_72 ? L_17 : L_18 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_26 ( V_8 ) ;
F_29 ( V_26 , V_8 ) ;
F_23 ( V_8 , V_48 , 0 ) ;
F_23 ( V_8 , V_50 , 0 ) ;
F_23 ( V_8 , V_49 , 0 ) ;
F_44 ( V_26 , V_74 . ERROR , V_8 -> V_44 ) ;
F_44 ( V_26 , V_74 . V_43 , V_8 -> V_44 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_83 -> V_86 ; V_15 ++ )
F_45 ( V_8 , & V_8 -> V_83 -> V_12 [ V_15 ] -> V_21 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
}
static void F_54 ( unsigned long V_87 )
{
struct V_25 * V_26 = (struct V_25 * ) V_87 ;
struct V_7 * V_8 ;
T_1 V_72 ;
T_1 V_82 ;
int V_15 ;
V_72 = F_31 ( V_26 , V_73 . V_43 ) ;
V_82 = F_31 ( V_26 , V_73 . ERROR ) ;
F_12 ( V_26 -> V_36 . V_4 , L_19 , V_75 , V_82 ) ;
for ( V_15 = 0 ; V_15 < V_26 -> V_36 . V_88 ; V_15 ++ ) {
V_8 = & V_26 -> V_3 [ V_15 ] ;
if ( F_55 ( V_89 , & V_8 -> V_16 ) )
F_52 ( V_26 , V_8 , V_82 , V_72 ) ;
else if ( V_82 & ( 1 << V_15 ) )
F_47 ( V_26 , V_8 ) ;
else if ( V_72 & ( 1 << V_15 ) )
F_43 ( V_26 , V_8 ) ;
}
F_24 ( V_26 , V_42 . V_43 , V_26 -> V_90 ) ;
F_24 ( V_26 , V_42 . ERROR , V_26 -> V_90 ) ;
}
static T_4 F_56 ( int V_91 , void * V_92 )
{
struct V_25 * V_26 = V_92 ;
T_1 V_93 ;
F_12 ( V_26 -> V_36 . V_4 , L_20 , V_75 ,
F_31 ( V_26 , V_94 ) ) ;
F_30 ( V_26 , V_42 . V_43 , V_26 -> V_90 ) ;
F_30 ( V_26 , V_42 . ERROR , V_26 -> V_90 ) ;
V_93 = F_31 ( V_26 , V_94 ) ;
if ( V_93 ) {
F_27 ( V_26 -> V_36 . V_4 ,
L_21 ,
V_93 ) ;
F_30 ( V_26 , V_42 . V_43 , ( 1 << 8 ) - 1 ) ;
F_30 ( V_26 , V_42 . V_95 , ( 1 << 8 ) - 1 ) ;
F_30 ( V_26 , V_42 . V_96 , ( 1 << 8 ) - 1 ) ;
F_30 ( V_26 , V_42 . ERROR , ( 1 << 8 ) - 1 ) ;
}
F_57 ( & V_26 -> V_97 ) ;
return V_98 ;
}
static T_5 F_58 ( struct V_58 * V_99 )
{
struct V_6 * V_12 = F_59 ( V_99 ) ;
struct V_7 * V_8 = F_50 ( V_99 -> V_3 ) ;
T_5 V_59 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_59 = F_60 ( V_99 ) ;
if ( F_42 ( & V_8 -> V_9 ) ) {
F_12 ( F_1 ( V_99 -> V_3 ) , L_22 , V_75 ,
V_12 -> V_18 . V_59 ) ;
F_61 ( & V_12 -> V_11 , & V_8 -> V_9 ) ;
F_33 ( V_8 , F_3 ( V_8 ) ) ;
} else {
F_12 ( F_1 ( V_99 -> V_3 ) , L_23 , V_75 ,
V_12 -> V_18 . V_59 ) ;
F_61 ( & V_12 -> V_11 , & V_8 -> V_70 ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
return V_59 ;
}
static struct V_58 *
F_62 ( struct V_2 * V_3 , T_3 V_100 , T_3 V_101 ,
T_6 V_64 , unsigned long V_16 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
struct V_6 * V_12 ;
struct V_6 * V_52 ;
struct V_6 * V_81 ;
T_6 V_102 ;
T_6 V_103 ;
unsigned int V_104 ;
unsigned int V_105 ;
T_1 V_79 ;
F_12 ( F_1 ( V_3 ) ,
L_24 , V_75 ,
( unsigned long long ) V_100 , ( unsigned long long ) V_101 ,
V_64 , V_16 ) ;
if ( F_53 ( ! V_64 ) ) {
F_10 ( F_1 ( V_3 ) , L_25 , V_75 ) ;
return NULL ;
}
V_104 = V_105 = F_25 ( V_101 | V_100 | V_64 ) ;
V_79 = F_63 ( V_3 )
| F_64 ( V_105 )
| F_65 ( V_104 )
| V_106
| V_107
| V_108 ;
V_81 = V_52 = NULL ;
for ( V_103 = 0 ; V_103 < V_64 ; V_103 += V_102 << V_104 ) {
V_102 = F_66 ( T_6 , ( V_64 - V_103 ) >> V_104 ,
V_109 ) ;
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 )
goto V_110;
V_12 -> V_21 . V_68 = V_101 + V_103 ;
V_12 -> V_21 . V_63 = V_100 + V_103 ;
V_12 -> V_21 . V_79 = V_79 ;
V_12 -> V_21 . V_78 = V_102 ;
if ( ! V_52 ) {
V_52 = V_12 ;
} else {
V_81 -> V_21 . V_71 = V_12 -> V_18 . V_20 ;
F_67 ( F_2 ( V_3 ) ,
V_81 -> V_18 . V_20 , sizeof( V_81 -> V_21 ) ,
V_22 ) ;
F_61 ( & V_12 -> V_11 ,
& V_52 -> V_23 ) ;
}
V_81 = V_12 ;
}
if ( V_16 & V_111 )
V_81 -> V_21 . V_79 |= V_112 ;
V_81 -> V_21 . V_71 = 0 ;
F_67 ( F_2 ( V_3 ) ,
V_81 -> V_18 . V_20 , sizeof( V_81 -> V_21 ) ,
V_22 ) ;
V_52 -> V_18 . V_16 = V_16 ;
V_52 -> V_64 = V_64 ;
return & V_52 -> V_18 ;
V_110:
F_16 ( V_8 , V_52 ) ;
return NULL ;
}
static struct V_58 *
F_68 ( struct V_2 * V_3 , struct V_113 * V_114 ,
unsigned int V_115 , enum V_116 V_117 ,
unsigned long V_16 , void * V_118 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
struct V_27 * V_28 = V_3 -> V_29 ;
struct V_119 * V_120 = & V_8 -> V_121 ;
struct V_6 * V_81 ;
struct V_6 * V_52 ;
T_1 V_79 ;
T_3 V_122 ;
unsigned int V_123 ;
unsigned int V_124 ;
unsigned int V_15 ;
struct V_113 * V_125 ;
T_6 V_126 = 0 ;
F_12 ( F_1 ( V_3 ) , L_26 , V_75 ) ;
if ( F_53 ( ! V_28 || ! V_115 ) )
return NULL ;
V_81 = V_52 = NULL ;
switch ( V_117 ) {
case V_127 :
V_123 = F_69 ( V_120 -> V_128 ) ;
V_122 = V_120 -> V_129 ;
V_79 = ( F_63 ( V_3 )
| F_64 ( V_123 )
| V_130
| V_107 ) ;
V_79 |= V_120 -> V_131 ? F_70 ( V_132 ) :
F_70 ( V_133 ) ;
F_71 (sgl, sg, sg_len, i) {
struct V_6 * V_12 ;
T_1 V_64 , V_134 , V_135 ;
V_135 = F_72 ( V_125 ) ;
V_64 = F_73 ( V_125 ) ;
V_124 = F_25 ( V_135 | V_64 ) ;
V_136:
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 ) {
F_27 ( F_1 ( V_3 ) ,
L_27 ) ;
goto V_110;
}
V_12 -> V_21 . V_68 = V_135 ;
V_12 -> V_21 . V_63 = V_122 ;
V_12 -> V_21 . V_79 = V_79 | F_65 ( V_124 ) ;
if ( ( V_64 >> V_124 ) > V_109 ) {
V_134 = V_109 << V_124 ;
V_135 += V_134 ;
V_64 -= V_134 ;
} else {
V_134 = V_64 ;
V_64 = 0 ;
}
V_12 -> V_21 . V_78 = V_134 >> V_124 ;
if ( ! V_52 ) {
V_52 = V_12 ;
} else {
V_81 -> V_21 . V_71 = V_12 -> V_18 . V_20 ;
F_67 ( F_2 ( V_3 ) ,
V_81 -> V_18 . V_20 ,
sizeof( V_81 -> V_21 ) ,
V_22 ) ;
F_61 ( & V_12 -> V_11 ,
& V_52 -> V_23 ) ;
}
V_81 = V_12 ;
V_126 += V_134 ;
if ( V_64 )
goto V_136;
}
break;
case V_137 :
V_123 = F_69 ( V_120 -> V_138 ) ;
V_122 = V_120 -> V_139 ;
V_79 = ( F_63 ( V_3 )
| F_65 ( V_123 )
| V_106
| V_140 ) ;
V_79 |= V_120 -> V_131 ? F_70 ( V_141 ) :
F_70 ( V_142 ) ;
F_71 (sgl, sg, sg_len, i) {
struct V_6 * V_12 ;
T_1 V_64 , V_134 , V_135 ;
V_135 = F_72 ( V_125 ) ;
V_64 = F_73 ( V_125 ) ;
V_124 = F_25 ( V_135 | V_64 ) ;
V_143:
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 ) {
F_27 ( F_1 ( V_3 ) ,
L_27 ) ;
goto V_110;
}
V_12 -> V_21 . V_68 = V_122 ;
V_12 -> V_21 . V_63 = V_135 ;
V_12 -> V_21 . V_79 = V_79 | F_64 ( V_124 ) ;
if ( ( V_64 >> V_123 ) > V_109 ) {
V_134 = V_109 << V_123 ;
V_135 += V_134 ;
V_64 -= V_134 ;
} else {
V_134 = V_64 ;
V_64 = 0 ;
}
V_12 -> V_21 . V_78 = V_134 >> V_123 ;
if ( ! V_52 ) {
V_52 = V_12 ;
} else {
V_81 -> V_21 . V_71 = V_12 -> V_18 . V_20 ;
F_67 ( F_2 ( V_3 ) ,
V_81 -> V_18 . V_20 ,
sizeof( V_81 -> V_21 ) ,
V_22 ) ;
F_61 ( & V_12 -> V_11 ,
& V_52 -> V_23 ) ;
}
V_81 = V_12 ;
V_126 += V_134 ;
if ( V_64 )
goto V_143;
}
break;
default:
return NULL ;
}
if ( V_16 & V_111 )
V_81 -> V_21 . V_79 |= V_112 ;
V_81 -> V_21 . V_71 = 0 ;
F_67 ( F_2 ( V_3 ) ,
V_81 -> V_18 . V_20 , sizeof( V_81 -> V_21 ) ,
V_22 ) ;
V_52 -> V_64 = V_126 ;
return & V_52 -> V_18 ;
V_110:
F_16 ( V_8 , V_52 ) ;
return NULL ;
}
static inline void F_74 ( T_1 * V_144 )
{
if ( * V_144 > 1 )
* V_144 = F_75 ( * V_144 ) - 2 ;
else
* V_144 = 0 ;
}
static int
F_76 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
if ( ! V_3 -> V_29 )
return - V_145 ;
memcpy ( & V_8 -> V_121 , V_120 , sizeof( * V_120 ) ) ;
F_74 ( & V_8 -> V_121 . V_146 ) ;
F_74 ( & V_8 -> V_121 . V_147 ) ;
return 0 ;
}
static int F_77 ( struct V_2 * V_3 , enum V_148 V_149 ,
unsigned long V_150 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_3 -> V_1 ) ;
struct V_6 * V_12 , * V_13 ;
unsigned long V_16 ;
T_1 V_32 ;
F_41 ( V_69 ) ;
if ( V_149 == V_151 ) {
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_32 = F_28 ( V_8 , V_40 ) ;
F_23 ( V_8 , V_40 , V_32 | V_152 ) ;
while ( ! ( F_28 ( V_8 , V_40 ) & V_153 ) )
F_32 () ;
V_8 -> V_154 = true ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
} else if ( V_149 == V_155 ) {
if ( ! V_8 -> V_154 )
return 0 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_32 = F_28 ( V_8 , V_40 ) ;
F_23 ( V_8 , V_40 , V_32 & ~ V_152 ) ;
V_8 -> V_154 = false ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
} else if ( V_149 == V_156 ) {
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_29 ( V_26 , V_8 ) ;
V_8 -> V_154 = false ;
F_17 ( & V_8 -> V_70 , & V_69 ) ;
F_17 ( & V_8 -> V_9 , & V_69 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node)
F_34 ( V_8 , V_12 , false ) ;
} else if ( V_149 == V_157 ) {
return F_76 ( V_3 , (struct V_119 * ) V_150 ) ;
} else {
return - V_158 ;
}
return 0 ;
}
static enum V_159
F_78 ( struct V_2 * V_3 ,
T_5 V_59 ,
struct V_160 * V_161 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
enum V_159 V_14 ;
V_14 = F_79 ( V_3 , V_59 , V_161 ) ;
if ( V_14 != V_162 ) {
F_43 ( F_20 ( V_3 -> V_1 ) , V_8 ) ;
V_14 = F_79 ( V_3 , V_59 , V_161 ) ;
}
if ( V_14 != V_162 )
F_80 ( V_161 , F_3 ( V_8 ) -> V_64 ) ;
if ( V_8 -> V_154 )
return V_163 ;
return V_14 ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
if ( ! F_42 ( & V_8 -> V_70 ) )
F_43 ( F_20 ( V_3 -> V_1 ) , V_8 ) ;
}
static int F_82 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_3 -> V_1 ) ;
struct V_6 * V_12 ;
int V_15 ;
unsigned long V_16 ;
F_12 ( F_1 ( V_3 ) , L_26 , V_75 ) ;
if ( F_31 ( V_26 , V_51 ) & V_8 -> V_44 ) {
F_10 ( F_1 ( V_3 ) , L_28 ) ;
return - V_164 ;
}
F_83 ( V_3 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_15 = V_8 -> V_165 ;
while ( V_8 -> V_165 < V_166 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
V_12 = F_84 ( sizeof( struct V_6 ) , V_167 ) ;
if ( ! V_12 ) {
F_85 ( F_1 ( V_3 ) ,
L_29 , V_15 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
break;
}
F_86 ( & V_12 -> V_23 ) ;
F_87 ( & V_12 -> V_18 , V_3 ) ;
V_12 -> V_18 . V_168 = F_58 ;
V_12 -> V_18 . V_16 = V_169 ;
V_12 -> V_18 . V_20 = F_88 ( F_2 ( V_3 ) , & V_12 -> V_21 ,
sizeof( V_12 -> V_21 ) , V_22 ) ;
F_16 ( V_8 , V_12 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_15 = ++ V_8 -> V_165 ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_10 ( F_1 ( V_3 ) , L_30 , V_75 , V_15 ) ;
return V_15 ;
}
static void F_89 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_3 -> V_1 ) ;
struct V_6 * V_12 , * V_13 ;
unsigned long V_16 ;
F_41 ( V_69 ) ;
F_10 ( F_1 ( V_3 ) , L_31 , V_75 ,
V_8 -> V_165 ) ;
F_22 ( ! F_42 ( & V_8 -> V_9 ) ) ;
F_22 ( ! F_42 ( & V_8 -> V_70 ) ) ;
F_22 ( F_31 ( F_20 ( V_3 -> V_1 ) , V_51 ) & V_8 -> V_44 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_17 ( & V_8 -> V_24 , & V_69 ) ;
V_8 -> V_165 = 0 ;
V_8 -> V_34 = false ;
F_30 ( V_26 , V_42 . V_43 , V_8 -> V_44 ) ;
F_30 ( V_26 , V_42 . ERROR , V_8 -> V_44 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node) {
F_12 ( F_1 ( V_3 ) , L_32 , V_12 ) ;
F_38 ( F_2 ( V_3 ) , V_12 -> V_18 . V_20 ,
sizeof( V_12 -> V_21 ) , V_22 ) ;
F_90 ( V_12 ) ;
}
F_12 ( F_1 ( V_3 ) , L_33 , V_75 ) ;
}
int F_91 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_8 -> V_3 . V_1 ) ;
unsigned long V_16 ;
if ( ! F_55 ( V_89 , & V_8 -> V_16 ) ) {
F_27 ( F_1 ( & V_8 -> V_3 ) , L_34 ) ;
return - V_170 ;
}
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( F_31 ( V_26 , V_51 ) & V_8 -> V_44 ) {
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ) ;
F_26 ( V_8 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
return - V_171 ;
}
F_44 ( V_26 , V_74 . ERROR , V_8 -> V_44 ) ;
F_44 ( V_26 , V_74 . V_43 , V_8 -> V_44 ) ;
F_23 ( V_8 , V_48 , V_8 -> V_83 -> V_12 [ 0 ] -> V_18 . V_20 ) ;
F_23 ( V_8 , V_50 , V_53 | V_54 ) ;
F_23 ( V_8 , V_49 , 0 ) ;
F_24 ( V_26 , V_51 , V_8 -> V_44 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
return 0 ;
}
void F_92 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_8 -> V_3 . V_1 ) ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_29 ( V_26 , V_8 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
struct V_172 * F_93 ( struct V_2 * V_3 ,
T_3 V_173 , T_6 V_174 , T_6 V_175 ,
enum V_116 V_117 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
struct V_119 * V_120 = & V_8 -> V_121 ;
struct V_172 * V_83 ;
struct V_172 * V_176 = NULL ;
struct V_6 * V_12 ;
struct V_6 * V_177 = NULL ;
unsigned long V_178 ;
unsigned int V_123 ;
unsigned int V_86 ;
unsigned int V_15 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( ! F_42 ( & V_8 -> V_70 ) || ! F_42 ( & V_8 -> V_9 ) ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_10 ( F_1 ( & V_8 -> V_3 ) ,
L_35 ) ;
return F_94 ( - V_171 ) ;
}
V_178 = F_95 ( V_89 , & V_8 -> V_16 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
if ( V_178 ) {
F_10 ( F_1 ( & V_8 -> V_3 ) ,
L_36 ) ;
return F_94 ( - V_171 ) ;
}
V_176 = F_94 ( - V_145 ) ;
if ( V_117 == V_127 )
V_123 = F_96 ( V_120 -> V_128 ) ;
else
V_123 = F_96 ( V_120 -> V_138 ) ;
V_86 = V_174 / V_175 ;
if ( V_175 > ( V_109 << V_123 ) )
goto V_179;
if ( F_53 ( V_175 & ( ( 1 << V_123 ) - 1 ) ) )
goto V_179;
if ( F_53 ( V_173 & ( ( 1 << V_123 ) - 1 ) ) )
goto V_179;
if ( F_53 ( ! ( V_117 & ( V_127 | V_137 ) ) ) )
goto V_179;
V_176 = F_94 ( - V_180 ) ;
if ( V_86 > V_166 )
goto V_179;
V_83 = F_84 ( sizeof( struct V_172 ) , V_167 ) ;
if ( ! V_83 )
goto V_179;
V_83 -> V_12 = F_84 ( sizeof( struct V_6 * ) * V_86 , V_167 ) ;
if ( ! V_83 -> V_12 )
goto V_181;
for ( V_15 = 0 ; V_15 < V_86 ; V_15 ++ ) {
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 )
goto V_182;
switch ( V_117 ) {
case V_127 :
V_12 -> V_21 . V_63 = V_120 -> V_129 ;
V_12 -> V_21 . V_68 = V_173 + ( V_175 * V_15 ) ;
V_12 -> V_21 . V_79 = ( F_63 ( V_3 )
| F_64 ( V_123 )
| F_65 ( V_123 )
| V_130
| V_107
| V_112 ) ;
V_12 -> V_21 . V_79 |= V_120 -> V_131 ?
F_70 ( V_132 ) :
F_70 ( V_133 ) ;
break;
case V_137 :
V_12 -> V_21 . V_63 = V_173 + ( V_175 * V_15 ) ;
V_12 -> V_21 . V_68 = V_120 -> V_139 ;
V_12 -> V_21 . V_79 = ( F_63 ( V_3 )
| F_65 ( V_123 )
| F_64 ( V_123 )
| V_106
| V_140
| V_112 ) ;
V_12 -> V_21 . V_79 |= V_120 -> V_131 ?
F_70 ( V_141 ) :
F_70 ( V_142 ) ;
break;
default:
break;
}
V_12 -> V_21 . V_78 = ( V_175 >> V_123 ) ;
V_83 -> V_12 [ V_15 ] = V_12 ;
if ( V_177 ) {
V_177 -> V_21 . V_71 = V_12 -> V_18 . V_20 ;
F_67 ( F_2 ( V_3 ) ,
V_177 -> V_18 . V_20 , sizeof( V_177 -> V_21 ) ,
V_22 ) ;
}
V_177 = V_12 ;
}
V_177 -> V_21 . V_71 = V_83 -> V_12 [ 0 ] -> V_18 . V_20 ;
F_67 ( F_2 ( V_3 ) , V_177 -> V_18 . V_20 ,
sizeof( V_177 -> V_21 ) , V_22 ) ;
F_10 ( F_1 ( & V_8 -> V_3 ) , L_37
L_38 , ( unsigned long long ) V_173 ,
V_174 , V_175 , V_86 ) ;
V_83 -> V_86 = V_86 ;
V_8 -> V_83 = V_83 ;
return V_83 ;
V_182:
while ( V_15 -- )
F_16 ( V_8 , V_83 -> V_12 [ V_15 ] ) ;
V_181:
F_90 ( V_83 ) ;
V_179:
F_97 ( V_89 , & V_8 -> V_16 ) ;
return (struct V_172 * ) V_176 ;
}
void F_98 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_50 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_8 -> V_3 . V_1 ) ;
struct V_172 * V_83 = V_8 -> V_83 ;
int V_15 ;
unsigned long V_16 ;
F_10 ( F_1 ( & V_8 -> V_3 ) , L_26 , V_75 ) ;
if ( ! V_83 )
return;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_29 ( V_26 , V_8 ) ;
F_44 ( V_26 , V_74 . ERROR , V_8 -> V_44 ) ;
F_44 ( V_26 , V_74 . V_43 , V_8 -> V_44 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
for ( V_15 = 0 ; V_15 < V_83 -> V_86 ; V_15 ++ )
F_16 ( V_8 , V_83 -> V_12 [ V_15 ] ) ;
F_90 ( V_83 -> V_12 ) ;
F_90 ( V_83 ) ;
F_97 ( V_89 , & V_8 -> V_16 ) ;
}
static void F_99 ( struct V_25 * V_26 )
{
int V_15 ;
F_44 ( V_26 , V_183 , 0 ) ;
F_30 ( V_26 , V_42 . V_43 , V_26 -> V_90 ) ;
F_30 ( V_26 , V_42 . V_95 , V_26 -> V_90 ) ;
F_30 ( V_26 , V_42 . V_96 , V_26 -> V_90 ) ;
F_30 ( V_26 , V_42 . ERROR , V_26 -> V_90 ) ;
while ( F_31 ( V_26 , V_183 ) & V_184 )
F_32 () ;
for ( V_15 = 0 ; V_15 < V_26 -> V_36 . V_88 ; V_15 ++ )
V_26 -> V_3 [ V_15 ] . V_34 = false ;
}
static int T_7 F_100 ( struct V_185 * V_186 )
{
struct V_187 * V_188 ;
struct V_189 * V_190 ;
struct V_25 * V_26 ;
T_6 V_191 ;
int V_91 ;
int V_192 ;
int V_15 ;
V_188 = F_101 ( & V_186 -> V_4 ) ;
if ( ! V_188 || V_188 -> V_193 > V_194 )
return - V_145 ;
V_190 = F_102 ( V_186 , V_195 , 0 ) ;
if ( ! V_190 )
return - V_145 ;
V_91 = F_103 ( V_186 , 0 ) ;
if ( V_91 < 0 )
return V_91 ;
V_191 = sizeof( struct V_25 ) ;
V_191 += V_188 -> V_193 * sizeof( struct V_7 ) ;
V_26 = F_84 ( V_191 , V_167 ) ;
if ( ! V_26 )
return - V_180 ;
if ( ! F_104 ( V_190 -> V_196 , V_197 , V_186 -> V_4 . V_198 -> V_199 ) ) {
V_192 = - V_171 ;
goto V_200;
}
V_26 -> V_201 = F_105 ( V_190 -> V_196 , V_197 ) ;
if ( ! V_26 -> V_201 ) {
V_192 = - V_180 ;
goto V_202;
}
V_26 -> V_203 = F_106 ( & V_186 -> V_4 , L_39 ) ;
if ( F_107 ( V_26 -> V_203 ) ) {
V_192 = F_108 ( V_26 -> V_203 ) ;
goto V_204;
}
F_109 ( V_26 -> V_203 ) ;
V_26 -> V_90 = ( 1 << V_188 -> V_193 ) - 1 ;
F_99 ( V_26 ) ;
F_30 ( V_26 , V_42 . V_205 , V_26 -> V_90 ) ;
V_192 = F_110 ( V_91 , F_56 , 0 , L_40 , V_26 ) ;
if ( V_192 )
goto V_206;
F_111 ( V_186 , V_26 ) ;
F_112 ( & V_26 -> V_97 , F_54 , ( unsigned long ) V_26 ) ;
F_86 ( & V_26 -> V_36 . V_207 ) ;
for ( V_15 = 0 ; V_15 < V_188 -> V_193 ; V_15 ++ ) {
struct V_7 * V_8 = & V_26 -> V_3 [ V_15 ] ;
V_8 -> V_3 . V_1 = & V_26 -> V_36 ;
F_83 ( & V_8 -> V_3 ) ;
if ( V_188 -> V_208 == V_209 )
F_61 ( & V_8 -> V_3 . V_210 ,
& V_26 -> V_36 . V_207 ) ;
else
F_18 ( & V_8 -> V_3 . V_210 , & V_26 -> V_36 . V_207 ) ;
if ( V_188 -> V_211 == V_212 )
V_8 -> V_33 = V_188 -> V_193 - V_15 - 1 ;
else
V_8 -> V_33 = V_15 ;
V_8 -> V_213 = & F_113 ( V_26 ) -> V_214 [ V_15 ] ;
F_114 ( & V_8 -> V_17 ) ;
V_8 -> V_44 = 1 << V_15 ;
F_86 ( & V_8 -> V_9 ) ;
F_86 ( & V_8 -> V_70 ) ;
F_86 ( & V_8 -> V_24 ) ;
F_30 ( V_26 , V_51 , V_8 -> V_44 ) ;
}
F_44 ( V_26 , V_74 . V_43 , V_26 -> V_90 ) ;
F_44 ( V_26 , V_74 . V_205 , V_26 -> V_90 ) ;
F_44 ( V_26 , V_74 . V_95 , V_26 -> V_90 ) ;
F_44 ( V_26 , V_74 . V_96 , V_26 -> V_90 ) ;
F_44 ( V_26 , V_74 . ERROR , V_26 -> V_90 ) ;
F_115 ( V_215 , V_26 -> V_36 . V_216 ) ;
F_115 ( V_217 , V_26 -> V_36 . V_216 ) ;
if ( V_188 -> V_218 )
F_115 ( V_219 , V_26 -> V_36 . V_216 ) ;
V_26 -> V_36 . V_4 = & V_186 -> V_4 ;
V_26 -> V_36 . V_220 = F_82 ;
V_26 -> V_36 . V_221 = F_89 ;
V_26 -> V_36 . V_222 = F_62 ;
V_26 -> V_36 . V_223 = F_68 ;
V_26 -> V_36 . V_224 = F_77 ;
V_26 -> V_36 . V_225 = F_78 ;
V_26 -> V_36 . V_226 = F_81 ;
F_44 ( V_26 , V_183 , V_184 ) ;
F_116 ( V_227 L_41 ,
F_117 ( & V_186 -> V_4 ) , V_188 -> V_193 ) ;
F_118 ( & V_26 -> V_36 ) ;
return 0 ;
V_206:
F_119 ( V_26 -> V_203 ) ;
F_120 ( V_26 -> V_203 ) ;
V_204:
F_121 ( V_26 -> V_201 ) ;
V_26 -> V_201 = NULL ;
V_202:
F_122 ( V_190 ) ;
V_200:
F_90 ( V_26 ) ;
return V_192 ;
}
static int T_8 F_123 ( struct V_185 * V_186 )
{
struct V_25 * V_26 = F_124 ( V_186 ) ;
struct V_7 * V_8 , * V_228 ;
struct V_189 * V_190 ;
F_99 ( V_26 ) ;
F_125 ( & V_26 -> V_36 ) ;
F_126 ( F_103 ( V_186 , 0 ) , V_26 ) ;
F_127 ( & V_26 -> V_97 ) ;
F_7 (dwc, _dwc, &dw->dma.channels,
chan.device_node) {
F_9 ( & V_8 -> V_3 . V_210 ) ;
F_30 ( V_26 , V_51 , V_8 -> V_44 ) ;
}
F_119 ( V_26 -> V_203 ) ;
F_120 ( V_26 -> V_203 ) ;
F_121 ( V_26 -> V_201 ) ;
V_26 -> V_201 = NULL ;
V_190 = F_102 ( V_186 , V_195 , 0 ) ;
F_128 ( V_190 -> V_196 , V_197 ) ;
F_90 ( V_26 ) ;
return 0 ;
}
static void F_129 ( struct V_185 * V_186 )
{
struct V_25 * V_26 = F_124 ( V_186 ) ;
F_99 ( F_124 ( V_186 ) ) ;
F_119 ( V_26 -> V_203 ) ;
}
static int F_130 ( struct V_1 * V_4 )
{
struct V_185 * V_186 = F_131 ( V_4 ) ;
struct V_25 * V_26 = F_124 ( V_186 ) ;
F_99 ( F_124 ( V_186 ) ) ;
F_119 ( V_26 -> V_203 ) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_4 )
{
struct V_185 * V_186 = F_131 ( V_4 ) ;
struct V_25 * V_26 = F_124 ( V_186 ) ;
F_109 ( V_26 -> V_203 ) ;
F_44 ( V_26 , V_183 , V_184 ) ;
return 0 ;
}
static int T_9 F_133 ( void )
{
return F_134 ( & V_229 , F_100 ) ;
}
static void T_10 F_135 ( void )
{
F_136 ( & V_229 ) ;
}
