static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_3 : 0 ;
}
static inline unsigned int F_2 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_4 : 1 ;
}
static inline unsigned int F_3 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = F_4 ( V_6 -> V_10 ) ;
struct V_1 * V_11 = V_6 -> V_12 ;
unsigned int V_13 ;
if ( V_7 == V_14 )
V_13 = F_2 ( V_11 ) ;
else
V_13 = F_1 ( V_11 ) ;
return F_5 (unsigned int, dw->nr_masters - 1 , m) ;
}
static inline unsigned int F_6 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = F_4 ( V_6 -> V_10 ) ;
return V_9 -> V_15 [ F_3 ( V_6 , V_7 ) ] ;
}
static struct V_10 * F_7 ( struct V_5 * V_6 )
{
return & V_6 -> V_16 -> V_10 ;
}
static struct V_10 * F_8 ( struct V_5 * V_6 )
{
return V_6 -> V_16 -> V_10 . V_17 ;
}
static struct V_18 * F_9 ( struct V_19 * V_20 )
{
return F_10 ( V_20 -> V_21 . V_22 ) ;
}
static struct V_18 * F_11 ( struct V_19 * V_20 )
{
struct V_18 * V_23 , * V_24 ;
struct V_18 * V_25 = NULL ;
unsigned int V_26 = 0 ;
unsigned long V_27 ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
F_13 (desc, _desc, &dwc->free_list, desc_node) {
V_26 ++ ;
if ( F_14 ( & V_23 -> V_29 ) ) {
F_15 ( & V_23 -> V_30 ) ;
V_25 = V_23 ;
break;
}
F_16 ( F_7 ( & V_20 -> V_6 ) , L_1 , V_23 ) ;
}
F_17 ( & V_20 -> V_28 , V_27 ) ;
F_18 ( F_7 ( & V_20 -> V_6 ) , L_2 , V_26 ) ;
return V_25 ;
}
static void F_19 ( struct V_19 * V_20 , struct V_18 * V_23 )
{
unsigned long V_27 ;
if ( V_23 ) {
struct V_18 * V_31 ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
F_20 (child, &desc->tx_list, desc_node)
F_18 ( F_7 ( & V_20 -> V_6 ) ,
L_3 ,
V_31 ) ;
F_21 ( & V_23 -> V_32 , & V_20 -> V_33 ) ;
F_18 ( F_7 ( & V_20 -> V_6 ) , L_4 , V_23 ) ;
F_22 ( & V_23 -> V_30 , & V_20 -> V_33 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
}
}
static void F_23 ( struct V_19 * V_20 )
{
struct V_8 * V_9 = F_4 ( V_20 -> V_6 . V_10 ) ;
struct V_1 * V_11 = V_20 -> V_6 . V_12 ;
T_1 V_34 = V_35 ;
T_1 V_36 = F_24 ( V_20 -> V_37 ) ;
if ( V_20 -> V_38 == true )
return;
if ( V_11 && V_11 -> V_39 == ~ 0 && V_11 -> V_40 == ~ 0 ) {
if ( V_20 -> V_41 == V_42 )
V_34 = F_25 ( V_20 -> V_43 ) ;
else if ( V_20 -> V_41 == V_44 )
V_34 = F_26 ( V_20 -> V_43 ) ;
} else if ( V_11 ) {
F_27 ( ! V_11 -> V_45 || V_11 -> V_45 != V_9 -> V_46 . V_16 ) ;
V_34 = V_11 -> V_39 ;
V_36 |= V_11 -> V_40 & ~ V_47 ;
} else {
if ( V_20 -> V_41 == V_42 )
V_34 = F_25 ( V_20 -> V_48 . V_49 ) ;
else if ( V_20 -> V_41 == V_44 )
V_34 = F_26 ( V_20 -> V_48 . V_49 ) ;
}
F_28 ( V_20 , V_50 , V_36 ) ;
F_28 ( V_20 , V_51 , V_34 ) ;
F_29 ( V_9 , V_52 . V_53 , V_20 -> V_54 ) ;
F_29 ( V_9 , V_52 . ERROR , V_20 -> V_54 ) ;
V_20 -> V_38 = true ;
}
static inline unsigned int F_30 ( unsigned long long V_55 )
{
if ( ! ( V_55 & 7 ) )
return 3 ;
else if ( ! ( V_55 & 3 ) )
return 2 ;
else if ( ! ( V_55 & 1 ) )
return 1 ;
return 0 ;
}
static inline void F_31 ( struct V_19 * V_20 )
{
F_32 ( F_7 ( & V_20 -> V_6 ) ,
L_5 ,
F_33 ( V_20 , V_56 ) ,
F_33 ( V_20 , V_57 ) ,
F_33 ( V_20 , V_58 ) ,
F_33 ( V_20 , V_59 ) ,
F_33 ( V_20 , V_60 ) ) ;
}
static inline void F_34 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
F_35 ( V_9 , V_61 , V_20 -> V_54 ) ;
while ( F_36 ( V_9 , V_61 ) & V_20 -> V_54 )
F_37 () ;
}
static inline void F_38 ( struct V_19 * V_20 ,
struct V_18 * V_23 )
{
struct V_8 * V_9 = F_4 ( V_20 -> V_6 . V_10 ) ;
T_1 V_62 ;
V_62 = V_23 -> V_63 . V_62 | V_64 ;
F_28 ( V_20 , V_56 , V_23 -> V_63 . V_65 ) ;
F_28 ( V_20 , V_57 , V_23 -> V_63 . V_66 ) ;
F_28 ( V_20 , V_60 , V_62 ) ;
F_28 ( V_20 , V_59 , V_23 -> V_63 . V_67 ) ;
F_29 ( V_9 , V_61 , V_20 -> V_54 ) ;
V_20 -> V_68 = V_20 -> V_68 -> V_22 ;
}
static void F_39 ( struct V_19 * V_20 , struct V_18 * V_69 )
{
struct V_8 * V_9 = F_4 ( V_20 -> V_6 . V_10 ) ;
unsigned long V_70 ;
if ( F_36 ( V_9 , V_61 ) & V_20 -> V_54 ) {
F_32 ( F_7 ( & V_20 -> V_6 ) ,
L_6 ) ;
F_31 ( V_20 ) ;
return;
}
if ( V_20 -> V_71 ) {
V_70 = F_40 ( V_72 ,
& V_20 -> V_27 ) ;
if ( V_70 ) {
F_32 ( F_7 ( & V_20 -> V_6 ) ,
L_7
L_8 ) ;
return;
}
F_23 ( V_20 ) ;
V_20 -> V_73 = V_69 -> V_74 ;
V_20 -> V_68 = & V_69 -> V_32 ;
F_38 ( V_20 , V_69 ) ;
return;
}
F_23 ( V_20 ) ;
F_28 ( V_20 , V_58 , V_69 -> V_29 . V_75 ) ;
F_28 ( V_20 , V_60 ,
V_76 | V_77 ) ;
F_28 ( V_20 , V_59 , 0 ) ;
F_29 ( V_9 , V_61 , V_20 -> V_54 ) ;
}
static void
F_41 ( struct V_19 * V_20 , struct V_18 * V_23 ,
bool V_78 )
{
T_2 V_79 = NULL ;
void * V_80 = NULL ;
struct V_81 * V_29 = & V_23 -> V_29 ;
struct V_18 * V_31 ;
unsigned long V_27 ;
F_18 ( F_7 ( & V_20 -> V_6 ) , L_9 , V_29 -> V_82 ) ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
F_42 ( V_29 ) ;
if ( V_78 ) {
V_79 = V_29 -> V_79 ;
V_80 = V_29 -> V_83 ;
}
F_20 (child, &desc->tx_list, desc_node)
F_43 ( & V_31 -> V_29 ) ;
F_43 ( & V_23 -> V_29 ) ;
F_21 ( & V_23 -> V_32 , & V_20 -> V_33 ) ;
F_44 ( & V_23 -> V_30 , & V_20 -> V_33 ) ;
if ( ! F_45 ( V_20 -> V_41 ) ) {
struct V_10 * V_17 = F_8 ( & V_20 -> V_6 ) ;
if ( ! ( V_29 -> V_27 & V_84 ) ) {
if ( V_29 -> V_27 & V_85 )
F_46 ( V_17 , V_23 -> V_63 . V_66 ,
V_23 -> V_74 , V_86 ) ;
else
F_47 ( V_17 , V_23 -> V_63 . V_66 ,
V_23 -> V_74 , V_86 ) ;
}
if ( ! ( V_29 -> V_27 & V_87 ) ) {
if ( V_29 -> V_27 & V_88 )
F_46 ( V_17 , V_23 -> V_63 . V_65 ,
V_23 -> V_74 , V_89 ) ;
else
F_47 ( V_17 , V_23 -> V_63 . V_65 ,
V_23 -> V_74 , V_89 ) ;
}
}
F_17 ( & V_20 -> V_28 , V_27 ) ;
if ( V_79 )
V_79 ( V_80 ) ;
}
static void F_48 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
struct V_18 * V_23 , * V_24 ;
F_49 ( V_90 ) ;
unsigned long V_27 ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
if ( F_36 ( V_9 , V_61 ) & V_20 -> V_54 ) {
F_32 ( F_7 ( & V_20 -> V_6 ) ,
L_10 ) ;
F_34 ( V_9 , V_20 ) ;
}
F_21 ( & V_20 -> V_21 , & V_90 ) ;
if ( ! F_50 ( & V_20 -> V_91 ) ) {
F_44 ( V_20 -> V_91 . V_22 , & V_20 -> V_21 ) ;
F_39 ( V_20 , F_9 ( V_20 ) ) ;
}
F_17 ( & V_20 -> V_28 , V_27 ) ;
F_13 (desc, _desc, &list, desc_node)
F_41 ( V_20 , V_23 , true ) ;
}
static inline T_1 F_51 ( struct V_19 * V_20 )
{
T_1 V_67 = F_33 ( V_20 , V_59 ) ;
T_1 V_62 = F_33 ( V_20 , V_60 ) ;
return ( V_67 & V_92 ) * ( 1 << ( V_62 >> 4 & 7 ) ) ;
}
static void F_52 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
T_3 V_93 ;
struct V_18 * V_23 , * V_24 ;
struct V_18 * V_31 ;
T_1 V_94 ;
unsigned long V_27 ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
V_93 = F_33 ( V_20 , V_58 ) ;
V_94 = F_36 ( V_9 , V_95 . V_53 ) ;
if ( V_94 & V_20 -> V_54 ) {
F_53 ( V_9 , V_96 . V_53 , V_20 -> V_54 ) ;
if ( F_54 ( V_72 , & V_20 -> V_27 ) ) {
struct V_97 * V_98 , * V_99 = V_20 -> V_68 ;
V_23 = F_9 ( V_20 ) ;
V_98 = & V_23 -> V_32 ;
if ( V_99 != V_98 ) {
if ( V_99 != V_98 -> V_22 )
V_23 = F_10 ( V_99 -> V_100 ) ;
V_20 -> V_73 -= V_23 -> V_101 ;
V_31 = F_10 ( V_99 ) ;
F_38 ( V_20 , V_31 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
return;
}
F_55 ( V_72 , & V_20 -> V_27 ) ;
}
V_20 -> V_73 = 0 ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
F_48 ( V_9 , V_20 ) ;
return;
}
if ( F_50 ( & V_20 -> V_21 ) ) {
V_20 -> V_73 = 0 ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
return;
}
if ( F_54 ( V_72 , & V_20 -> V_27 ) ) {
F_18 ( F_7 ( & V_20 -> V_6 ) , L_11 , V_102 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
return;
}
F_18 ( F_7 ( & V_20 -> V_6 ) , L_12 , V_102 ,
( unsigned long long ) V_93 ) ;
F_13 (desc, _desc, &dwc->active_list, desc_node) {
V_20 -> V_73 = V_23 -> V_74 ;
if ( V_23 -> V_29 . V_75 == V_93 ) {
F_17 ( & V_20 -> V_28 , V_27 ) ;
return;
}
if ( V_23 -> V_63 . V_93 == V_93 ) {
V_20 -> V_73 -= F_51 ( V_20 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
return;
}
V_20 -> V_73 -= V_23 -> V_101 ;
F_20 (child, &desc->tx_list, desc_node) {
if ( V_31 -> V_63 . V_93 == V_93 ) {
V_20 -> V_73 -= F_51 ( V_20 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
return;
}
V_20 -> V_73 -= V_31 -> V_101 ;
}
F_17 ( & V_20 -> V_28 , V_27 ) ;
F_41 ( V_20 , V_23 , true ) ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
}
F_32 ( F_7 ( & V_20 -> V_6 ) ,
L_13 ) ;
F_34 ( V_9 , V_20 ) ;
if ( ! F_50 ( & V_20 -> V_91 ) ) {
F_44 ( V_20 -> V_91 . V_22 , & V_20 -> V_21 ) ;
F_39 ( V_20 , F_9 ( V_20 ) ) ;
}
F_17 ( & V_20 -> V_28 , V_27 ) ;
}
static inline void F_56 ( struct V_19 * V_20 , struct V_103 * V_63 )
{
F_57 ( F_7 ( & V_20 -> V_6 ) , L_14 ,
V_63 -> V_65 , V_63 -> V_66 , V_63 -> V_93 , V_63 -> V_67 , V_63 -> V_62 ) ;
}
static void F_58 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
struct V_18 * V_104 ;
struct V_18 * V_31 ;
unsigned long V_27 ;
F_52 ( V_9 , V_20 ) ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
V_104 = F_9 ( V_20 ) ;
F_59 ( & V_104 -> V_30 ) ;
F_44 ( V_20 -> V_91 . V_22 , V_20 -> V_21 . V_100 ) ;
F_53 ( V_9 , V_96 . ERROR , V_20 -> V_54 ) ;
if ( ! F_50 ( & V_20 -> V_21 ) )
F_39 ( V_20 , F_9 ( V_20 ) ) ;
F_60 ( F_7 ( & V_20 -> V_6 ) , L_15
L_16 , V_104 -> V_29 . V_82 ) ;
F_56 ( V_20 , & V_104 -> V_63 ) ;
F_20 (child, &bad_desc->tx_list, desc_node)
F_56 ( V_20 , & V_31 -> V_63 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
F_41 ( V_20 , V_104 , true ) ;
}
inline T_3 F_61 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
return F_33 ( V_20 , V_56 ) ;
}
inline T_3 F_63 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
return F_33 ( V_20 , V_57 ) ;
}
static void F_64 ( struct V_8 * V_9 , struct V_19 * V_20 ,
T_1 V_105 , T_1 V_94 )
{
unsigned long V_27 ;
if ( V_20 -> V_54 ) {
void (* V_79)( void * V_80 );
void * V_83 ;
F_18 ( F_7 ( & V_20 -> V_6 ) , L_17 ,
F_33 ( V_20 , V_58 ) ) ;
V_79 = V_20 -> V_106 -> V_107 ;
V_83 = V_20 -> V_106 -> V_108 ;
if ( V_79 )
V_79 ( V_83 ) ;
}
if ( F_65 ( V_105 & V_20 -> V_54 ) ||
F_65 ( V_94 & V_20 -> V_54 ) ) {
int V_26 ;
F_32 ( F_7 ( & V_20 -> V_6 ) , L_18
L_19 ,
V_94 ? L_20 : L_21 ) ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
F_31 ( V_20 ) ;
F_34 ( V_9 , V_20 ) ;
F_28 ( V_20 , V_58 , 0 ) ;
F_28 ( V_20 , V_60 , 0 ) ;
F_28 ( V_20 , V_59 , 0 ) ;
F_53 ( V_9 , V_96 . ERROR , V_20 -> V_54 ) ;
F_53 ( V_9 , V_96 . V_53 , V_20 -> V_54 ) ;
for ( V_26 = 0 ; V_26 < V_20 -> V_106 -> V_109 ; V_26 ++ )
F_56 ( V_20 , & V_20 -> V_106 -> V_23 [ V_26 ] -> V_63 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
}
}
static void F_66 ( unsigned long V_110 )
{
struct V_8 * V_9 = (struct V_8 * ) V_110 ;
struct V_19 * V_20 ;
T_1 V_94 ;
T_1 V_105 ;
int V_26 ;
V_94 = F_36 ( V_9 , V_95 . V_53 ) ;
V_105 = F_36 ( V_9 , V_95 . ERROR ) ;
F_18 ( V_9 -> V_46 . V_16 , L_22 , V_102 , V_105 ) ;
for ( V_26 = 0 ; V_26 < V_9 -> V_46 . V_111 ; V_26 ++ ) {
V_20 = & V_9 -> V_6 [ V_26 ] ;
if ( F_54 ( V_112 , & V_20 -> V_27 ) )
F_64 ( V_9 , V_20 , V_105 , V_94 ) ;
else if ( V_105 & ( 1 << V_26 ) )
F_58 ( V_9 , V_20 ) ;
else if ( V_94 & ( 1 << V_26 ) )
F_52 ( V_9 , V_20 ) ;
}
F_29 ( V_9 , V_52 . V_53 , V_9 -> V_113 ) ;
F_29 ( V_9 , V_52 . ERROR , V_9 -> V_113 ) ;
}
static T_4 F_67 ( int V_114 , void * V_115 )
{
struct V_8 * V_9 = V_115 ;
T_1 V_116 ;
F_18 ( V_9 -> V_46 . V_16 , L_23 , V_102 ,
F_36 ( V_9 , V_117 ) ) ;
F_35 ( V_9 , V_52 . V_53 , V_9 -> V_113 ) ;
F_35 ( V_9 , V_52 . ERROR , V_9 -> V_113 ) ;
V_116 = F_36 ( V_9 , V_117 ) ;
if ( V_116 ) {
F_32 ( V_9 -> V_46 . V_16 ,
L_24 ,
V_116 ) ;
F_35 ( V_9 , V_52 . V_53 , ( 1 << 8 ) - 1 ) ;
F_35 ( V_9 , V_52 . V_118 , ( 1 << 8 ) - 1 ) ;
F_35 ( V_9 , V_52 . V_119 , ( 1 << 8 ) - 1 ) ;
F_35 ( V_9 , V_52 . ERROR , ( 1 << 8 ) - 1 ) ;
}
F_68 ( & V_9 -> V_120 ) ;
return V_121 ;
}
static T_5 F_69 ( struct V_81 * V_122 )
{
struct V_18 * V_23 = F_70 ( V_122 ) ;
struct V_19 * V_20 = F_62 ( V_122 -> V_6 ) ;
T_5 V_82 ;
unsigned long V_27 ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
V_82 = F_71 ( V_122 ) ;
if ( F_50 ( & V_20 -> V_21 ) ) {
F_18 ( F_7 ( V_122 -> V_6 ) , L_25 , V_102 ,
V_23 -> V_29 . V_82 ) ;
F_72 ( & V_23 -> V_30 , & V_20 -> V_21 ) ;
F_39 ( V_20 , F_9 ( V_20 ) ) ;
} else {
F_18 ( F_7 ( V_122 -> V_6 ) , L_26 , V_102 ,
V_23 -> V_29 . V_82 ) ;
F_72 ( & V_23 -> V_30 , & V_20 -> V_91 ) ;
}
F_17 ( & V_20 -> V_28 , V_27 ) ;
return V_82 ;
}
static struct V_81 *
F_73 ( struct V_5 * V_6 , T_3 V_123 , T_3 V_124 ,
T_6 V_101 , unsigned long V_27 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
struct V_18 * V_23 ;
struct V_18 * V_69 ;
struct V_18 * V_100 ;
T_6 V_125 ;
T_6 V_126 ;
unsigned int V_127 ;
unsigned int V_128 ;
unsigned int V_15 ;
T_1 V_62 ;
F_18 ( F_7 ( V_6 ) ,
L_27 , V_102 ,
( unsigned long long ) V_123 , ( unsigned long long ) V_124 ,
V_101 , V_27 ) ;
if ( F_65 ( ! V_101 ) ) {
F_16 ( F_7 ( V_6 ) , L_28 , V_102 ) ;
return NULL ;
}
V_20 -> V_41 = V_129 ;
V_15 = F_5 (unsigned int, dwc_get_data_width(chan, SRC_MASTER),
dwc_get_data_width(chan, DST_MASTER)) ;
V_127 = V_128 = F_5 (unsigned int, data_width,
dwc_fast_fls(src | dest | len)) ;
V_62 = F_74 ( V_6 )
| F_75 ( V_128 )
| F_76 ( V_127 )
| V_130
| V_131
| V_132 ;
V_100 = V_69 = NULL ;
for ( V_126 = 0 ; V_126 < V_101 ; V_126 += V_125 << V_127 ) {
V_125 = F_5 ( T_6 , ( V_101 - V_126 ) >> V_127 ,
V_20 -> V_133 ) ;
V_23 = F_11 ( V_20 ) ;
if ( ! V_23 )
goto V_134;
V_23 -> V_63 . V_65 = V_124 + V_126 ;
V_23 -> V_63 . V_66 = V_123 + V_126 ;
V_23 -> V_63 . V_62 = V_62 ;
V_23 -> V_63 . V_67 = V_125 ;
V_23 -> V_101 = V_125 << V_127 ;
if ( ! V_69 ) {
V_69 = V_23 ;
} else {
V_100 -> V_63 . V_93 = V_23 -> V_29 . V_75 ;
F_72 ( & V_23 -> V_30 ,
& V_69 -> V_32 ) ;
}
V_100 = V_23 ;
}
if ( V_27 & V_135 )
V_100 -> V_63 . V_62 |= V_64 ;
V_100 -> V_63 . V_93 = 0 ;
V_69 -> V_29 . V_27 = V_27 ;
V_69 -> V_74 = V_101 ;
return & V_69 -> V_29 ;
V_134:
F_19 ( V_20 , V_69 ) ;
return NULL ;
}
static struct V_81 *
F_77 ( struct V_5 * V_6 , struct V_136 * V_137 ,
unsigned int V_138 , enum V_139 V_41 ,
unsigned long V_27 , void * V_140 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
struct V_141 * V_142 = & V_20 -> V_48 ;
struct V_18 * V_100 ;
struct V_18 * V_69 ;
T_1 V_62 ;
T_3 V_143 ;
unsigned int V_144 ;
unsigned int V_145 ;
unsigned int V_15 ;
unsigned int V_26 ;
struct V_136 * V_146 ;
T_6 V_74 = 0 ;
F_18 ( F_7 ( V_6 ) , L_29 , V_102 ) ;
if ( F_65 ( ! F_45 ( V_41 ) || ! V_138 ) )
return NULL ;
V_20 -> V_41 = V_41 ;
V_100 = V_69 = NULL ;
switch ( V_41 ) {
case V_42 :
V_144 = F_78 ( V_142 -> V_147 ) ;
V_143 = V_142 -> V_148 ;
V_62 = ( F_74 ( V_6 )
| F_75 ( V_144 )
| V_149
| V_131 ) ;
V_62 |= V_142 -> V_150 ? F_79 ( V_151 ) :
F_79 ( V_152 ) ;
V_15 = F_6 ( V_6 , V_14 ) ;
F_80 (sgl, sg, sg_len, i) {
struct V_18 * V_23 ;
T_1 V_101 , V_153 , V_154 ;
V_154 = F_81 ( V_146 ) ;
V_101 = F_82 ( V_146 ) ;
V_145 = F_5 (unsigned int,
data_width, dwc_fast_fls(mem | len)) ;
V_155:
V_23 = F_11 ( V_20 ) ;
if ( ! V_23 ) {
F_32 ( F_7 ( V_6 ) ,
L_30 ) ;
goto V_134;
}
V_23 -> V_63 . V_65 = V_154 ;
V_23 -> V_63 . V_66 = V_143 ;
V_23 -> V_63 . V_62 = V_62 | F_76 ( V_145 ) ;
if ( ( V_101 >> V_145 ) > V_20 -> V_133 ) {
V_153 = V_20 -> V_133 << V_145 ;
V_154 += V_153 ;
V_101 -= V_153 ;
} else {
V_153 = V_101 ;
V_101 = 0 ;
}
V_23 -> V_63 . V_67 = V_153 >> V_145 ;
V_23 -> V_101 = V_153 ;
if ( ! V_69 ) {
V_69 = V_23 ;
} else {
V_100 -> V_63 . V_93 = V_23 -> V_29 . V_75 ;
F_72 ( & V_23 -> V_30 ,
& V_69 -> V_32 ) ;
}
V_100 = V_23 ;
V_74 += V_153 ;
if ( V_101 )
goto V_155;
}
break;
case V_44 :
V_144 = F_78 ( V_142 -> V_156 ) ;
V_143 = V_142 -> V_157 ;
V_62 = ( F_74 ( V_6 )
| F_76 ( V_144 )
| V_130
| V_158 ) ;
V_62 |= V_142 -> V_150 ? F_79 ( V_159 ) :
F_79 ( V_160 ) ;
V_15 = F_6 ( V_6 , V_161 ) ;
F_80 (sgl, sg, sg_len, i) {
struct V_18 * V_23 ;
T_1 V_101 , V_153 , V_154 ;
V_154 = F_81 ( V_146 ) ;
V_101 = F_82 ( V_146 ) ;
V_145 = F_5 (unsigned int,
data_width, dwc_fast_fls(mem | len)) ;
V_162:
V_23 = F_11 ( V_20 ) ;
if ( ! V_23 ) {
F_32 ( F_7 ( V_6 ) ,
L_30 ) ;
goto V_134;
}
V_23 -> V_63 . V_65 = V_143 ;
V_23 -> V_63 . V_66 = V_154 ;
V_23 -> V_63 . V_62 = V_62 | F_75 ( V_145 ) ;
if ( ( V_101 >> V_144 ) > V_20 -> V_133 ) {
V_153 = V_20 -> V_133 << V_144 ;
V_154 += V_153 ;
V_101 -= V_153 ;
} else {
V_153 = V_101 ;
V_101 = 0 ;
}
V_23 -> V_63 . V_67 = V_153 >> V_144 ;
V_23 -> V_101 = V_153 ;
if ( ! V_69 ) {
V_69 = V_23 ;
} else {
V_100 -> V_63 . V_93 = V_23 -> V_29 . V_75 ;
F_72 ( & V_23 -> V_30 ,
& V_69 -> V_32 ) ;
}
V_100 = V_23 ;
V_74 += V_153 ;
if ( V_101 )
goto V_162;
}
break;
default:
return NULL ;
}
if ( V_27 & V_135 )
V_100 -> V_63 . V_62 |= V_64 ;
V_100 -> V_63 . V_93 = 0 ;
V_69 -> V_74 = V_74 ;
return & V_69 -> V_29 ;
V_134:
F_19 ( V_20 , V_69 ) ;
return NULL ;
}
static inline void F_83 ( T_1 * V_163 )
{
if ( * V_163 > 1 )
* V_163 = F_84 ( * V_163 ) - 2 ;
else
* V_163 = 0 ;
}
static inline void F_85 ( struct V_19 * V_20 )
{
struct V_8 * V_9 = F_4 ( V_20 -> V_6 . V_10 ) ;
V_20 -> V_48 . V_49 -= V_9 -> V_164 ;
}
static int
F_86 ( struct V_5 * V_6 , struct V_141 * V_142 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
if ( ! F_45 ( V_142 -> V_41 ) )
return - V_165 ;
memcpy ( & V_20 -> V_48 , V_142 , sizeof( * V_142 ) ) ;
V_20 -> V_41 = V_142 -> V_41 ;
F_83 ( & V_20 -> V_48 . V_166 ) ;
F_83 ( & V_20 -> V_48 . V_167 ) ;
F_85 ( V_20 ) ;
return 0 ;
}
static inline void F_87 ( struct V_19 * V_20 )
{
T_1 V_36 = F_33 ( V_20 , V_50 ) ;
F_28 ( V_20 , V_50 , V_36 | V_168 ) ;
while ( ! ( F_33 ( V_20 , V_50 ) & V_169 ) )
F_37 () ;
V_20 -> V_170 = true ;
}
static inline void F_88 ( struct V_19 * V_20 )
{
T_1 V_36 = F_33 ( V_20 , V_50 ) ;
F_28 ( V_20 , V_50 , V_36 & ~ V_168 ) ;
V_20 -> V_170 = false ;
}
static int F_89 ( struct V_5 * V_6 , enum V_171 V_172 ,
unsigned long V_173 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
struct V_8 * V_9 = F_4 ( V_6 -> V_10 ) ;
struct V_18 * V_23 , * V_24 ;
unsigned long V_27 ;
F_49 ( V_90 ) ;
if ( V_172 == V_174 ) {
F_12 ( & V_20 -> V_28 , V_27 ) ;
F_87 ( V_20 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
} else if ( V_172 == V_175 ) {
if ( ! V_20 -> V_170 )
return 0 ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
F_88 ( V_20 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
} else if ( V_172 == V_176 ) {
F_12 ( & V_20 -> V_28 , V_27 ) ;
F_55 ( V_72 , & V_20 -> V_27 ) ;
F_34 ( V_9 , V_20 ) ;
F_88 ( V_20 ) ;
F_21 ( & V_20 -> V_91 , & V_90 ) ;
F_21 ( & V_20 -> V_21 , & V_90 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
F_13 (desc, _desc, &list, desc_node)
F_41 ( V_20 , V_23 , false ) ;
} else if ( V_172 == V_177 ) {
return F_86 ( V_6 , (struct V_141 * ) V_173 ) ;
} else {
return - V_178 ;
}
return 0 ;
}
static inline T_1 F_90 ( struct V_19 * V_20 )
{
unsigned long V_27 ;
T_1 V_73 ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
V_73 = V_20 -> V_73 ;
if ( F_54 ( V_72 , & V_20 -> V_27 ) && V_73 )
V_73 -= F_51 ( V_20 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
return V_73 ;
}
static enum V_179
F_91 ( struct V_5 * V_6 ,
T_5 V_82 ,
struct V_180 * V_181 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
enum V_179 V_25 ;
V_25 = F_92 ( V_6 , V_82 , V_181 ) ;
if ( V_25 != V_182 ) {
F_52 ( F_4 ( V_6 -> V_10 ) , V_20 ) ;
V_25 = F_92 ( V_6 , V_82 , V_181 ) ;
}
if ( V_25 != V_182 )
F_93 ( V_181 , F_90 ( V_20 ) ) ;
if ( V_20 -> V_170 )
return V_183 ;
return V_25 ;
}
static void F_94 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
if ( ! F_50 ( & V_20 -> V_91 ) )
F_52 ( F_4 ( V_6 -> V_10 ) , V_20 ) ;
}
static int F_95 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
struct V_8 * V_9 = F_4 ( V_6 -> V_10 ) ;
struct V_18 * V_23 ;
int V_26 ;
unsigned long V_27 ;
F_18 ( F_7 ( V_6 ) , L_29 , V_102 ) ;
if ( F_36 ( V_9 , V_61 ) & V_20 -> V_54 ) {
F_16 ( F_7 ( V_6 ) , L_31 ) ;
return - V_184 ;
}
F_96 ( V_6 ) ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
V_26 = V_20 -> V_185 ;
while ( V_20 -> V_185 < V_186 ) {
T_3 V_75 ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
V_23 = F_97 ( V_9 -> V_187 , V_188 , & V_75 ) ;
if ( ! V_23 )
goto V_189;
memset ( V_23 , 0 , sizeof( struct V_18 ) ) ;
F_98 ( & V_23 -> V_32 ) ;
F_99 ( & V_23 -> V_29 , V_6 ) ;
V_23 -> V_29 . V_190 = F_69 ;
V_23 -> V_29 . V_27 = V_191 ;
V_23 -> V_29 . V_75 = V_75 ;
F_19 ( V_20 , V_23 ) ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
V_26 = ++ V_20 -> V_185 ;
}
F_17 ( & V_20 -> V_28 , V_27 ) ;
F_16 ( F_7 ( V_6 ) , L_32 , V_102 , V_26 ) ;
return V_26 ;
V_189:
F_100 ( F_7 ( V_6 ) , L_33 , V_26 ) ;
return V_26 ;
}
static void F_101 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
struct V_8 * V_9 = F_4 ( V_6 -> V_10 ) ;
struct V_18 * V_23 , * V_24 ;
unsigned long V_27 ;
F_49 ( V_90 ) ;
F_16 ( F_7 ( V_6 ) , L_34 , V_102 ,
V_20 -> V_185 ) ;
F_27 ( ! F_50 ( & V_20 -> V_21 ) ) ;
F_27 ( ! F_50 ( & V_20 -> V_91 ) ) ;
F_27 ( F_36 ( F_4 ( V_6 -> V_10 ) , V_61 ) & V_20 -> V_54 ) ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
F_21 ( & V_20 -> V_33 , & V_90 ) ;
V_20 -> V_185 = 0 ;
V_20 -> V_38 = false ;
F_35 ( V_9 , V_52 . V_53 , V_20 -> V_54 ) ;
F_35 ( V_9 , V_52 . ERROR , V_20 -> V_54 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
F_13 (desc, _desc, &list, desc_node) {
F_18 ( F_7 ( V_6 ) , L_35 , V_23 ) ;
F_102 ( V_9 -> V_187 , V_23 , V_23 -> V_29 . V_75 ) ;
}
F_18 ( F_7 ( V_6 ) , L_36 , V_102 ) ;
}
static bool F_103 ( struct V_5 * V_6 , void * V_80 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
struct V_8 * V_9 = F_4 ( V_6 -> V_10 ) ;
struct V_192 * V_193 = V_80 ;
struct V_1 * V_11 = & V_20 -> V_2 ;
if ( V_6 -> V_10 != & V_193 -> V_9 -> V_46 )
return false ;
V_11 -> V_45 = V_9 -> V_46 . V_16 ;
V_11 -> V_39 = ~ 0 ;
V_11 -> V_40 = ~ 0 ;
V_11 -> V_4 = V_193 -> V_124 ;
V_11 -> V_3 = V_193 -> V_194 ;
V_20 -> V_43 = V_193 -> V_195 ;
V_6 -> V_12 = V_11 ;
return true ;
}
static struct V_5 * F_104 ( struct V_196 * V_197 ,
struct V_198 * V_199 )
{
struct V_8 * V_9 = V_199 -> V_200 ;
struct V_192 V_193 = {
. V_9 = V_9 ,
} ;
T_7 V_201 ;
if ( V_197 -> V_202 != 3 )
return NULL ;
V_193 . V_195 = V_197 -> args [ 0 ] ;
V_193 . V_124 = V_197 -> args [ 1 ] ;
V_193 . V_194 = V_197 -> args [ 2 ] ;
if ( F_105 ( V_193 . V_195 >= V_203 ||
V_193 . V_124 >= V_9 -> V_204 ||
V_193 . V_194 >= V_9 -> V_204 ) )
return NULL ;
F_106 ( V_201 ) ;
F_107 ( V_205 , V_201 ) ;
return F_108 ( V_201 , F_103 , & V_193 ) ;
}
int F_109 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
struct V_8 * V_9 = F_4 ( V_20 -> V_6 . V_10 ) ;
unsigned long V_27 ;
if ( ! F_54 ( V_112 , & V_20 -> V_27 ) ) {
F_32 ( F_7 ( & V_20 -> V_6 ) , L_37 ) ;
return - V_206 ;
}
F_12 ( & V_20 -> V_28 , V_27 ) ;
if ( F_36 ( V_9 , V_61 ) & V_20 -> V_54 ) {
F_32 ( F_7 ( & V_20 -> V_6 ) ,
L_6 ) ;
F_31 ( V_20 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
return - V_207 ;
}
F_53 ( V_9 , V_96 . ERROR , V_20 -> V_54 ) ;
F_53 ( V_9 , V_96 . V_53 , V_20 -> V_54 ) ;
F_28 ( V_20 , V_58 , V_20 -> V_106 -> V_23 [ 0 ] -> V_29 . V_75 ) ;
F_28 ( V_20 , V_60 , V_76 | V_77 ) ;
F_28 ( V_20 , V_59 , 0 ) ;
F_29 ( V_9 , V_61 , V_20 -> V_54 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
return 0 ;
}
void F_110 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
struct V_8 * V_9 = F_4 ( V_20 -> V_6 . V_10 ) ;
unsigned long V_27 ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
F_34 ( V_9 , V_20 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
}
struct V_208 * F_111 ( struct V_5 * V_6 ,
T_3 V_209 , T_6 V_210 , T_6 V_211 ,
enum V_139 V_41 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
struct V_141 * V_142 = & V_20 -> V_48 ;
struct V_208 * V_106 ;
struct V_208 * V_212 = NULL ;
struct V_18 * V_23 ;
struct V_18 * V_213 = NULL ;
unsigned long V_214 ;
unsigned int V_144 ;
unsigned int V_109 ;
unsigned int V_26 ;
unsigned long V_27 ;
F_12 ( & V_20 -> V_28 , V_27 ) ;
if ( V_20 -> V_71 ) {
F_17 ( & V_20 -> V_28 , V_27 ) ;
F_16 ( F_7 ( & V_20 -> V_6 ) ,
L_38 ) ;
return F_112 ( - V_165 ) ;
}
if ( ! F_50 ( & V_20 -> V_91 ) || ! F_50 ( & V_20 -> V_21 ) ) {
F_17 ( & V_20 -> V_28 , V_27 ) ;
F_16 ( F_7 ( & V_20 -> V_6 ) ,
L_39 ) ;
return F_112 ( - V_207 ) ;
}
V_214 = F_40 ( V_112 , & V_20 -> V_27 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
if ( V_214 ) {
F_16 ( F_7 ( & V_20 -> V_6 ) ,
L_40 ) ;
return F_112 ( - V_207 ) ;
}
V_212 = F_112 ( - V_165 ) ;
if ( F_65 ( ! F_45 ( V_41 ) ) )
goto V_215;
V_20 -> V_41 = V_41 ;
if ( V_41 == V_42 )
V_144 = F_113 ( V_142 -> V_147 ) ;
else
V_144 = F_113 ( V_142 -> V_156 ) ;
V_109 = V_210 / V_211 ;
if ( V_211 > ( V_20 -> V_133 << V_144 ) )
goto V_215;
if ( F_65 ( V_211 & ( ( 1 << V_144 ) - 1 ) ) )
goto V_215;
if ( F_65 ( V_209 & ( ( 1 << V_144 ) - 1 ) ) )
goto V_215;
V_212 = F_112 ( - V_216 ) ;
if ( V_109 > V_186 )
goto V_215;
V_106 = F_114 ( sizeof( struct V_208 ) , V_217 ) ;
if ( ! V_106 )
goto V_215;
V_106 -> V_23 = F_114 ( sizeof( struct V_18 * ) * V_109 , V_217 ) ;
if ( ! V_106 -> V_23 )
goto V_218;
for ( V_26 = 0 ; V_26 < V_109 ; V_26 ++ ) {
V_23 = F_11 ( V_20 ) ;
if ( ! V_23 )
goto V_219;
switch ( V_41 ) {
case V_42 :
V_23 -> V_63 . V_66 = V_142 -> V_148 ;
V_23 -> V_63 . V_65 = V_209 + ( V_211 * V_26 ) ;
V_23 -> V_63 . V_62 = ( F_74 ( V_6 )
| F_75 ( V_144 )
| F_76 ( V_144 )
| V_149
| V_131
| V_64 ) ;
V_23 -> V_63 . V_62 |= V_142 -> V_150 ?
F_79 ( V_151 ) :
F_79 ( V_152 ) ;
break;
case V_44 :
V_23 -> V_63 . V_66 = V_209 + ( V_211 * V_26 ) ;
V_23 -> V_63 . V_65 = V_142 -> V_157 ;
V_23 -> V_63 . V_62 = ( F_74 ( V_6 )
| F_76 ( V_144 )
| F_75 ( V_144 )
| V_130
| V_158
| V_64 ) ;
V_23 -> V_63 . V_62 |= V_142 -> V_150 ?
F_79 ( V_159 ) :
F_79 ( V_160 ) ;
break;
default:
break;
}
V_23 -> V_63 . V_67 = ( V_211 >> V_144 ) ;
V_106 -> V_23 [ V_26 ] = V_23 ;
if ( V_213 )
V_213 -> V_63 . V_93 = V_23 -> V_29 . V_75 ;
V_213 = V_23 ;
}
V_213 -> V_63 . V_93 = V_106 -> V_23 [ 0 ] -> V_29 . V_75 ;
F_16 ( F_7 ( & V_20 -> V_6 ) , L_41
L_42 , ( unsigned long long ) V_209 ,
V_210 , V_211 , V_109 ) ;
V_106 -> V_109 = V_109 ;
V_20 -> V_106 = V_106 ;
return V_106 ;
V_219:
while ( V_26 -- )
F_19 ( V_20 , V_106 -> V_23 [ V_26 ] ) ;
V_218:
F_115 ( V_106 ) ;
V_215:
F_55 ( V_112 , & V_20 -> V_27 ) ;
return (struct V_208 * ) V_212 ;
}
void F_116 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = F_62 ( V_6 ) ;
struct V_8 * V_9 = F_4 ( V_20 -> V_6 . V_10 ) ;
struct V_208 * V_106 = V_20 -> V_106 ;
int V_26 ;
unsigned long V_27 ;
F_16 ( F_7 ( & V_20 -> V_6 ) , L_29 , V_102 ) ;
if ( ! V_106 )
return;
F_12 ( & V_20 -> V_28 , V_27 ) ;
F_34 ( V_9 , V_20 ) ;
F_53 ( V_9 , V_96 . ERROR , V_20 -> V_54 ) ;
F_53 ( V_9 , V_96 . V_53 , V_20 -> V_54 ) ;
F_17 ( & V_20 -> V_28 , V_27 ) ;
for ( V_26 = 0 ; V_26 < V_106 -> V_109 ; V_26 ++ )
F_19 ( V_20 , V_106 -> V_23 [ V_26 ] ) ;
F_115 ( V_106 -> V_23 ) ;
F_115 ( V_106 ) ;
F_55 ( V_112 , & V_20 -> V_27 ) ;
}
static void F_117 ( struct V_8 * V_9 )
{
int V_26 ;
F_53 ( V_9 , V_220 , 0 ) ;
F_35 ( V_9 , V_52 . V_53 , V_9 -> V_113 ) ;
F_35 ( V_9 , V_52 . V_118 , V_9 -> V_113 ) ;
F_35 ( V_9 , V_52 . V_119 , V_9 -> V_113 ) ;
F_35 ( V_9 , V_52 . ERROR , V_9 -> V_113 ) ;
while ( F_36 ( V_9 , V_220 ) & V_221 )
F_37 () ;
for ( V_26 = 0 ; V_26 < V_9 -> V_46 . V_111 ; V_26 ++ )
V_9 -> V_6 [ V_26 ] . V_38 = false ;
}
static struct V_222 *
F_118 ( struct V_223 * V_224 )
{
struct V_225 * V_226 = V_224 -> V_16 . V_227 ;
struct V_222 * V_228 ;
T_1 V_229 , V_230 [ 4 ] ;
if ( ! V_226 ) {
F_32 ( & V_224 -> V_16 , L_43 ) ;
return NULL ;
}
V_228 = F_119 ( & V_224 -> V_16 , sizeof( * V_228 ) , V_217 ) ;
if ( ! V_228 )
return NULL ;
if ( F_120 ( V_226 , L_44 , & V_228 -> V_231 ) )
return NULL ;
if ( F_121 ( V_226 , L_45 ) )
V_228 -> V_232 = true ;
if ( ! F_120 ( V_226 , L_46 , & V_229 ) )
V_228 -> V_233 = ( unsigned char ) V_229 ;
if ( ! F_120 ( V_226 , L_47 , & V_229 ) )
V_228 -> V_234 = V_229 ;
if ( ! F_120 ( V_226 , L_48 , & V_229 ) )
V_228 -> V_133 = V_229 ;
if ( ! F_120 ( V_226 , L_49 , & V_229 ) ) {
if ( V_229 > 4 )
return NULL ;
V_228 -> V_204 = V_229 ;
}
if ( ! F_122 ( V_226 , L_50 , V_230 ,
V_228 -> V_204 ) )
for ( V_229 = 0 ; V_229 < V_228 -> V_204 ; V_229 ++ )
V_228 -> V_15 [ V_229 ] = V_230 [ V_229 ] ;
return V_228 ;
}
static inline struct V_222 *
F_118 ( struct V_223 * V_224 )
{
return NULL ;
}
static int F_123 ( struct V_223 * V_224 )
{
const struct V_235 * V_236 ;
struct V_222 * V_228 ;
struct V_237 * V_238 ;
struct V_8 * V_9 ;
T_6 V_239 ;
void T_8 * V_240 ;
bool V_241 ;
unsigned int V_242 ;
unsigned int V_231 ;
unsigned int V_243 = 0 ;
int V_114 ;
int V_244 ;
int V_26 ;
V_238 = F_124 ( V_224 , V_245 , 0 ) ;
if ( ! V_238 )
return - V_165 ;
V_114 = F_125 ( V_224 , 0 ) ;
if ( V_114 < 0 )
return V_114 ;
V_240 = F_126 ( & V_224 -> V_16 , V_238 ) ;
if ( F_127 ( V_240 ) )
return F_128 ( V_240 ) ;
if ( ! V_224 -> V_16 . V_246 ) {
V_224 -> V_16 . V_246 = & V_224 -> V_16 . V_247 ;
V_224 -> V_16 . V_247 = F_129 ( 32 ) ;
}
V_242 = F_130 ( V_240 , V_248 ) ;
V_241 = V_242 >> V_249 & 0x1 ;
F_16 ( & V_224 -> V_16 , L_51 , V_242 ) ;
V_228 = F_131 ( & V_224 -> V_16 ) ;
if ( ! V_228 )
V_228 = F_118 ( V_224 ) ;
if ( ! V_228 && V_241 ) {
V_228 = F_119 ( & V_224 -> V_16 , sizeof( * V_228 ) , V_217 ) ;
if ( ! V_228 )
return - V_216 ;
V_228 -> V_232 = true ;
V_228 -> V_233 = V_250 ;
V_228 -> V_234 = V_251 ;
} else if ( ! V_228 || V_228 -> V_231 > V_252 )
return - V_165 ;
if ( V_241 )
V_231 = ( V_242 >> V_253 & 0x7 ) + 1 ;
else
V_231 = V_228 -> V_231 ;
V_239 = sizeof( struct V_8 ) + V_231 * sizeof( struct V_19 ) ;
V_9 = F_119 ( & V_224 -> V_16 , V_239 , V_217 ) ;
if ( ! V_9 )
return - V_216 ;
V_9 -> V_254 = F_132 ( & V_224 -> V_16 , L_52 ) ;
if ( F_127 ( V_9 -> V_254 ) )
return F_128 ( V_9 -> V_254 ) ;
F_133 ( V_9 -> V_254 ) ;
V_9 -> V_240 = V_240 ;
if ( V_241 ) {
V_243 = F_36 ( V_9 , V_255 ) ;
V_9 -> V_204 = ( V_242 >> V_256 & 3 ) + 1 ;
for ( V_26 = 0 ; V_26 < V_9 -> V_204 ; V_26 ++ ) {
V_9 -> V_15 [ V_26 ] =
( V_242 >> F_134 ( V_26 ) & 3 ) + 2 ;
}
} else {
V_9 -> V_204 = V_228 -> V_204 ;
memcpy ( V_9 -> V_15 , V_228 -> V_15 , 4 ) ;
}
V_236 = F_135 ( V_224 ) ;
if ( V_236 )
V_9 -> V_164 = ( unsigned int ) V_236 -> V_257 ;
V_9 -> V_113 = ( 1 << V_231 ) - 1 ;
F_117 ( V_9 ) ;
F_35 ( V_9 , V_52 . V_258 , V_9 -> V_113 ) ;
V_244 = F_136 ( & V_224 -> V_16 , V_114 , F_67 , 0 ,
L_53 , V_9 ) ;
if ( V_244 )
return V_244 ;
F_137 ( V_224 , V_9 ) ;
V_9 -> V_187 = F_138 ( L_54 , & V_224 -> V_16 ,
sizeof( struct V_18 ) , 4 , 0 ) ;
if ( ! V_9 -> V_187 ) {
F_32 ( & V_224 -> V_16 , L_55 ) ;
return - V_216 ;
}
F_139 ( & V_9 -> V_120 , F_66 , ( unsigned long ) V_9 ) ;
F_98 ( & V_9 -> V_46 . V_259 ) ;
for ( V_26 = 0 ; V_26 < V_231 ; V_26 ++ ) {
struct V_19 * V_20 = & V_9 -> V_6 [ V_26 ] ;
int V_260 = V_231 - V_26 - 1 ;
V_20 -> V_6 . V_10 = & V_9 -> V_46 ;
F_96 ( & V_20 -> V_6 ) ;
if ( V_228 -> V_233 == V_250 )
F_72 ( & V_20 -> V_6 . V_225 ,
& V_9 -> V_46 . V_259 ) ;
else
F_22 ( & V_20 -> V_6 . V_225 , & V_9 -> V_46 . V_259 ) ;
if ( V_228 -> V_234 == V_251 )
V_20 -> V_37 = V_260 ;
else
V_20 -> V_37 = V_26 ;
V_20 -> V_261 = & F_140 ( V_9 ) -> V_262 [ V_26 ] ;
F_141 ( & V_20 -> V_28 ) ;
V_20 -> V_54 = 1 << V_26 ;
F_98 ( & V_20 -> V_21 ) ;
F_98 ( & V_20 -> V_91 ) ;
F_98 ( & V_20 -> V_33 ) ;
F_35 ( V_9 , V_61 , V_20 -> V_54 ) ;
V_20 -> V_41 = V_263 ;
if ( V_241 ) {
unsigned int V_264 ;
V_264 = F_130 ( V_240 + V_260 * sizeof( T_1 ) ,
V_265 ) ;
F_16 ( & V_224 -> V_16 , L_56 , V_26 ,
V_264 ) ;
V_20 -> V_133 =
( 4 << ( ( V_243 >> 4 * V_26 ) & 0xf ) ) - 1 ;
V_20 -> V_71 =
( V_264 >> V_266 & 0x1 ) == 0 ;
} else {
V_20 -> V_133 = V_228 -> V_133 ;
F_28 ( V_20 , V_58 , 0xfffffffc ) ;
V_20 -> V_71 =
( F_33 ( V_20 , V_58 ) & 0xfffffffc ) == 0 ;
F_28 ( V_20 , V_58 , 0 ) ;
}
}
F_53 ( V_9 , V_96 . V_53 , V_9 -> V_113 ) ;
F_53 ( V_9 , V_96 . V_258 , V_9 -> V_113 ) ;
F_53 ( V_9 , V_96 . V_118 , V_9 -> V_113 ) ;
F_53 ( V_9 , V_96 . V_119 , V_9 -> V_113 ) ;
F_53 ( V_9 , V_96 . ERROR , V_9 -> V_113 ) ;
F_107 ( V_267 , V_9 -> V_46 . V_268 ) ;
F_107 ( V_205 , V_9 -> V_46 . V_268 ) ;
if ( V_228 -> V_232 )
F_107 ( V_269 , V_9 -> V_46 . V_268 ) ;
V_9 -> V_46 . V_16 = & V_224 -> V_16 ;
V_9 -> V_46 . V_270 = F_95 ;
V_9 -> V_46 . V_271 = F_101 ;
V_9 -> V_46 . V_272 = F_73 ;
V_9 -> V_46 . V_273 = F_77 ;
V_9 -> V_46 . V_274 = F_89 ;
V_9 -> V_46 . V_275 = F_91 ;
V_9 -> V_46 . V_276 = F_94 ;
F_53 ( V_9 , V_220 , V_221 ) ;
F_100 ( & V_224 -> V_16 , L_57 ,
V_231 ) ;
F_142 ( & V_9 -> V_46 ) ;
if ( V_224 -> V_16 . V_227 ) {
V_244 = F_143 ( V_224 -> V_16 . V_227 ,
F_104 , V_9 ) ;
if ( V_244 && V_244 != - V_206 )
F_32 ( & V_224 -> V_16 ,
L_58 ) ;
}
return 0 ;
}
static int F_144 ( struct V_223 * V_224 )
{
struct V_8 * V_9 = F_145 ( V_224 ) ;
struct V_19 * V_20 , * V_277 ;
if ( V_224 -> V_16 . V_227 )
F_146 ( V_224 -> V_16 . V_227 ) ;
F_117 ( V_9 ) ;
F_147 ( & V_9 -> V_46 ) ;
F_148 ( & V_9 -> V_120 ) ;
F_13 (dwc, _dwc, &dw->dma.channels,
chan.device_node) {
F_15 ( & V_20 -> V_6 . V_225 ) ;
F_35 ( V_9 , V_61 , V_20 -> V_54 ) ;
}
return 0 ;
}
static void F_149 ( struct V_223 * V_224 )
{
struct V_8 * V_9 = F_145 ( V_224 ) ;
F_117 ( V_9 ) ;
F_150 ( V_9 -> V_254 ) ;
}
static int F_151 ( struct V_10 * V_16 )
{
struct V_223 * V_224 = F_152 ( V_16 ) ;
struct V_8 * V_9 = F_145 ( V_224 ) ;
F_117 ( V_9 ) ;
F_150 ( V_9 -> V_254 ) ;
return 0 ;
}
static int F_153 ( struct V_10 * V_16 )
{
struct V_223 * V_224 = F_152 ( V_16 ) ;
struct V_8 * V_9 = F_145 ( V_224 ) ;
F_133 ( V_9 -> V_254 ) ;
F_53 ( V_9 , V_220 , V_221 ) ;
return 0 ;
}
static int T_9 F_154 ( void )
{
return F_155 ( & V_278 ) ;
}
static void T_10 F_156 ( void )
{
F_157 ( & V_278 ) ;
}
