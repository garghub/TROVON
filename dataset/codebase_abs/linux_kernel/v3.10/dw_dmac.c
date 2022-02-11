static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_3 : 0 ;
}
static inline unsigned int F_2 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_4 : 1 ;
}
static inline void F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 -> V_9 . V_10 ) ;
struct V_1 * V_11 = V_6 -> V_9 . V_12 ;
unsigned char V_13 = V_8 -> V_14 - 1 ;
if ( V_6 -> V_15 == ~ 0 ) {
V_6 -> V_4 = F_5 (unsigned char, mmax, dwc_get_sms(dws)) ;
V_6 -> V_3 = F_5 (unsigned char, mmax, dwc_get_dms(dws)) ;
}
}
static struct V_10 * F_6 ( struct V_16 * V_9 )
{
return & V_9 -> V_17 -> V_10 ;
}
static struct V_10 * F_7 ( struct V_16 * V_9 )
{
return V_9 -> V_17 -> V_10 . V_18 ;
}
static struct V_19 * F_8 ( struct V_5 * V_6 )
{
return F_9 ( V_6 -> V_20 . V_21 ) ;
}
static struct V_19 * F_10 ( struct V_5 * V_6 )
{
struct V_19 * V_22 , * V_23 ;
struct V_19 * V_24 = NULL ;
unsigned int V_25 = 0 ;
unsigned long V_26 ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
F_12 (desc, _desc, &dwc->free_list, desc_node) {
V_25 ++ ;
if ( F_13 ( & V_22 -> V_28 ) ) {
F_14 ( & V_22 -> V_29 ) ;
V_24 = V_22 ;
break;
}
F_15 ( F_6 ( & V_6 -> V_9 ) , L_1 , V_22 ) ;
}
F_16 ( & V_6 -> V_27 , V_26 ) ;
F_17 ( F_6 ( & V_6 -> V_9 ) , L_2 , V_25 ) ;
return V_24 ;
}
static void F_18 ( struct V_5 * V_6 , struct V_19 * V_22 )
{
unsigned long V_26 ;
if ( V_22 ) {
struct V_19 * V_30 ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
F_19 (child, &desc->tx_list, desc_node)
F_17 ( F_6 ( & V_6 -> V_9 ) ,
L_3 ,
V_30 ) ;
F_20 ( & V_22 -> V_31 , & V_6 -> V_32 ) ;
F_17 ( F_6 ( & V_6 -> V_9 ) , L_4 , V_22 ) ;
F_21 ( & V_22 -> V_29 , & V_6 -> V_32 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
}
}
static void F_22 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 -> V_9 . V_10 ) ;
struct V_1 * V_11 = V_6 -> V_9 . V_12 ;
T_1 V_33 = V_34 ;
T_1 V_35 = F_23 ( V_6 -> V_36 ) ;
if ( V_6 -> V_37 == true )
return;
if ( V_11 ) {
F_24 ( ! V_11 -> V_38 || V_11 -> V_38 != V_8 -> V_39 . V_17 ) ;
V_33 = V_11 -> V_40 ;
V_35 |= V_11 -> V_41 & ~ V_42 ;
} else {
if ( V_6 -> V_43 == V_44 )
V_33 = F_25 ( V_6 -> V_15 ) ;
else if ( V_6 -> V_43 == V_45 )
V_33 = F_26 ( V_6 -> V_15 ) ;
}
F_27 ( V_6 , V_46 , V_35 ) ;
F_27 ( V_6 , V_47 , V_33 ) ;
F_28 ( V_8 , V_48 . V_49 , V_6 -> V_50 ) ;
F_28 ( V_8 , V_48 . ERROR , V_6 -> V_50 ) ;
V_6 -> V_37 = true ;
}
static inline unsigned int F_29 ( unsigned long long V_51 )
{
if ( ! ( V_51 & 7 ) )
return 3 ;
else if ( ! ( V_51 & 3 ) )
return 2 ;
else if ( ! ( V_51 & 1 ) )
return 1 ;
return 0 ;
}
static inline void F_30 ( struct V_5 * V_6 )
{
F_31 ( F_6 ( & V_6 -> V_9 ) ,
L_5 ,
F_32 ( V_6 , V_52 ) ,
F_32 ( V_6 , V_53 ) ,
F_32 ( V_6 , V_54 ) ,
F_32 ( V_6 , V_55 ) ,
F_32 ( V_6 , V_56 ) ) ;
}
static inline void F_33 ( struct V_7 * V_8 , struct V_5 * V_6 )
{
F_34 ( V_8 , V_57 , V_6 -> V_50 ) ;
while ( F_35 ( V_8 , V_57 ) & V_6 -> V_50 )
F_36 () ;
}
static inline void F_37 ( struct V_5 * V_6 ,
struct V_19 * V_22 )
{
struct V_7 * V_8 = F_4 ( V_6 -> V_9 . V_10 ) ;
T_1 V_58 ;
V_58 = V_22 -> V_59 . V_58 | V_60 ;
F_27 ( V_6 , V_52 , V_22 -> V_59 . V_61 ) ;
F_27 ( V_6 , V_53 , V_22 -> V_59 . V_62 ) ;
F_27 ( V_6 , V_56 , V_58 ) ;
F_27 ( V_6 , V_55 , V_22 -> V_59 . V_63 ) ;
F_28 ( V_8 , V_57 , V_6 -> V_50 ) ;
V_6 -> V_64 = V_6 -> V_64 -> V_21 ;
}
static void F_38 ( struct V_5 * V_6 , struct V_19 * V_65 )
{
struct V_7 * V_8 = F_4 ( V_6 -> V_9 . V_10 ) ;
unsigned long V_66 ;
if ( F_35 ( V_8 , V_57 ) & V_6 -> V_50 ) {
F_31 ( F_6 ( & V_6 -> V_9 ) ,
L_6 ) ;
F_30 ( V_6 ) ;
return;
}
if ( V_6 -> V_67 ) {
V_66 = F_39 ( V_68 ,
& V_6 -> V_26 ) ;
if ( V_66 ) {
F_31 ( F_6 ( & V_6 -> V_9 ) ,
L_7
L_8 ) ;
return;
}
F_22 ( V_6 ) ;
V_6 -> V_69 = V_65 -> V_70 ;
V_6 -> V_64 = & V_65 -> V_31 ;
F_37 ( V_6 , V_65 ) ;
return;
}
F_22 ( V_6 ) ;
F_27 ( V_6 , V_54 , V_65 -> V_28 . V_71 ) ;
F_27 ( V_6 , V_56 ,
V_72 | V_73 ) ;
F_27 ( V_6 , V_55 , 0 ) ;
F_28 ( V_8 , V_57 , V_6 -> V_50 ) ;
}
static void
F_40 ( struct V_5 * V_6 , struct V_19 * V_22 ,
bool V_74 )
{
T_2 V_75 = NULL ;
void * V_76 = NULL ;
struct V_77 * V_28 = & V_22 -> V_28 ;
struct V_19 * V_30 ;
unsigned long V_26 ;
F_17 ( F_6 ( & V_6 -> V_9 ) , L_9 , V_28 -> V_78 ) ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
F_41 ( V_28 ) ;
if ( V_74 ) {
V_75 = V_28 -> V_75 ;
V_76 = V_28 -> V_79 ;
}
F_19 (child, &desc->tx_list, desc_node)
F_42 ( & V_30 -> V_28 ) ;
F_42 ( & V_22 -> V_28 ) ;
F_20 ( & V_22 -> V_31 , & V_6 -> V_32 ) ;
F_43 ( & V_22 -> V_29 , & V_6 -> V_32 ) ;
if ( ! F_44 ( V_6 -> V_43 ) ) {
struct V_10 * V_18 = F_7 ( & V_6 -> V_9 ) ;
if ( ! ( V_28 -> V_26 & V_80 ) ) {
if ( V_28 -> V_26 & V_81 )
F_45 ( V_18 , V_22 -> V_59 . V_62 ,
V_22 -> V_70 , V_82 ) ;
else
F_46 ( V_18 , V_22 -> V_59 . V_62 ,
V_22 -> V_70 , V_82 ) ;
}
if ( ! ( V_28 -> V_26 & V_83 ) ) {
if ( V_28 -> V_26 & V_84 )
F_45 ( V_18 , V_22 -> V_59 . V_61 ,
V_22 -> V_70 , V_85 ) ;
else
F_46 ( V_18 , V_22 -> V_59 . V_61 ,
V_22 -> V_70 , V_85 ) ;
}
}
F_16 ( & V_6 -> V_27 , V_26 ) ;
if ( V_75 )
V_75 ( V_76 ) ;
}
static void F_47 ( struct V_7 * V_8 , struct V_5 * V_6 )
{
struct V_19 * V_22 , * V_23 ;
F_48 ( V_86 ) ;
unsigned long V_26 ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
if ( F_35 ( V_8 , V_57 ) & V_6 -> V_50 ) {
F_31 ( F_6 ( & V_6 -> V_9 ) ,
L_10 ) ;
F_33 ( V_8 , V_6 ) ;
}
F_20 ( & V_6 -> V_20 , & V_86 ) ;
if ( ! F_49 ( & V_6 -> V_87 ) ) {
F_43 ( V_6 -> V_87 . V_21 , & V_6 -> V_20 ) ;
F_38 ( V_6 , F_8 ( V_6 ) ) ;
}
F_16 ( & V_6 -> V_27 , V_26 ) ;
F_12 (desc, _desc, &list, desc_node)
F_40 ( V_6 , V_22 , true ) ;
}
static inline T_1 F_50 ( struct V_5 * V_6 )
{
T_1 V_63 = F_32 ( V_6 , V_55 ) ;
T_1 V_58 = F_32 ( V_6 , V_56 ) ;
return ( V_63 & V_88 ) * ( 1 << ( V_58 >> 4 & 7 ) ) ;
}
static void F_51 ( struct V_7 * V_8 , struct V_5 * V_6 )
{
T_3 V_89 ;
struct V_19 * V_22 , * V_23 ;
struct V_19 * V_30 ;
T_1 V_90 ;
unsigned long V_26 ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
V_89 = F_32 ( V_6 , V_54 ) ;
V_90 = F_35 ( V_8 , V_91 . V_49 ) ;
if ( V_90 & V_6 -> V_50 ) {
F_52 ( V_8 , V_92 . V_49 , V_6 -> V_50 ) ;
if ( F_53 ( V_68 , & V_6 -> V_26 ) ) {
struct V_93 * V_94 , * V_95 = V_6 -> V_64 ;
V_22 = F_8 ( V_6 ) ;
V_94 = & V_22 -> V_31 ;
if ( V_95 != V_94 ) {
if ( V_95 != V_94 -> V_21 )
V_22 = F_9 ( V_95 -> V_96 ) ;
V_6 -> V_69 -= V_22 -> V_97 ;
V_30 = F_9 ( V_95 ) ;
F_37 ( V_6 , V_30 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
return;
}
F_54 ( V_68 , & V_6 -> V_26 ) ;
}
V_6 -> V_69 = 0 ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
F_47 ( V_8 , V_6 ) ;
return;
}
if ( F_49 ( & V_6 -> V_20 ) ) {
V_6 -> V_69 = 0 ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
return;
}
if ( F_53 ( V_68 , & V_6 -> V_26 ) ) {
F_17 ( F_6 ( & V_6 -> V_9 ) , L_11 , V_98 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
return;
}
F_17 ( F_6 ( & V_6 -> V_9 ) , L_12 , V_98 ,
( unsigned long long ) V_89 ) ;
F_12 (desc, _desc, &dwc->active_list, desc_node) {
V_6 -> V_69 = V_22 -> V_70 ;
if ( V_22 -> V_28 . V_71 == V_89 ) {
F_16 ( & V_6 -> V_27 , V_26 ) ;
return;
}
if ( V_22 -> V_59 . V_89 == V_89 ) {
V_6 -> V_69 -= F_50 ( V_6 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
return;
}
V_6 -> V_69 -= V_22 -> V_97 ;
F_19 (child, &desc->tx_list, desc_node) {
if ( V_30 -> V_59 . V_89 == V_89 ) {
V_6 -> V_69 -= F_50 ( V_6 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
return;
}
V_6 -> V_69 -= V_30 -> V_97 ;
}
F_16 ( & V_6 -> V_27 , V_26 ) ;
F_40 ( V_6 , V_22 , true ) ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
}
F_31 ( F_6 ( & V_6 -> V_9 ) ,
L_13 ) ;
F_33 ( V_8 , V_6 ) ;
if ( ! F_49 ( & V_6 -> V_87 ) ) {
F_43 ( V_6 -> V_87 . V_21 , & V_6 -> V_20 ) ;
F_38 ( V_6 , F_8 ( V_6 ) ) ;
}
F_16 ( & V_6 -> V_27 , V_26 ) ;
}
static inline void F_55 ( struct V_5 * V_6 , struct V_99 * V_59 )
{
F_56 ( F_6 ( & V_6 -> V_9 ) , L_14 ,
V_59 -> V_61 , V_59 -> V_62 , V_59 -> V_89 , V_59 -> V_63 , V_59 -> V_58 ) ;
}
static void F_57 ( struct V_7 * V_8 , struct V_5 * V_6 )
{
struct V_19 * V_100 ;
struct V_19 * V_30 ;
unsigned long V_26 ;
F_51 ( V_8 , V_6 ) ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
V_100 = F_8 ( V_6 ) ;
F_58 ( & V_100 -> V_29 ) ;
F_43 ( V_6 -> V_87 . V_21 , V_6 -> V_20 . V_96 ) ;
F_52 ( V_8 , V_92 . ERROR , V_6 -> V_50 ) ;
if ( ! F_49 ( & V_6 -> V_20 ) )
F_38 ( V_6 , F_8 ( V_6 ) ) ;
F_59 ( F_6 ( & V_6 -> V_9 ) , L_15
L_16 , V_100 -> V_28 . V_78 ) ;
F_55 ( V_6 , & V_100 -> V_59 ) ;
F_19 (child, &bad_desc->tx_list, desc_node)
F_55 ( V_6 , & V_30 -> V_59 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
F_40 ( V_6 , V_100 , true ) ;
}
inline T_3 F_60 ( struct V_16 * V_9 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
return F_32 ( V_6 , V_52 ) ;
}
inline T_3 F_62 ( struct V_16 * V_9 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
return F_32 ( V_6 , V_53 ) ;
}
static void F_63 ( struct V_7 * V_8 , struct V_5 * V_6 ,
T_1 V_101 , T_1 V_90 )
{
unsigned long V_26 ;
if ( V_6 -> V_50 ) {
void (* V_75)( void * V_76 );
void * V_79 ;
F_17 ( F_6 ( & V_6 -> V_9 ) , L_17 ,
F_32 ( V_6 , V_54 ) ) ;
V_75 = V_6 -> V_102 -> V_103 ;
V_79 = V_6 -> V_102 -> V_104 ;
if ( V_75 )
V_75 ( V_79 ) ;
}
if ( F_64 ( V_101 & V_6 -> V_50 ) ||
F_64 ( V_90 & V_6 -> V_50 ) ) {
int V_25 ;
F_31 ( F_6 ( & V_6 -> V_9 ) , L_18
L_19 ,
V_90 ? L_20 : L_21 ) ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
F_30 ( V_6 ) ;
F_33 ( V_8 , V_6 ) ;
F_27 ( V_6 , V_54 , 0 ) ;
F_27 ( V_6 , V_56 , 0 ) ;
F_27 ( V_6 , V_55 , 0 ) ;
F_52 ( V_8 , V_92 . ERROR , V_6 -> V_50 ) ;
F_52 ( V_8 , V_92 . V_49 , V_6 -> V_50 ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_102 -> V_105 ; V_25 ++ )
F_55 ( V_6 , & V_6 -> V_102 -> V_22 [ V_25 ] -> V_59 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
}
}
static void F_65 ( unsigned long V_106 )
{
struct V_7 * V_8 = (struct V_7 * ) V_106 ;
struct V_5 * V_6 ;
T_1 V_90 ;
T_1 V_101 ;
int V_25 ;
V_90 = F_35 ( V_8 , V_91 . V_49 ) ;
V_101 = F_35 ( V_8 , V_91 . ERROR ) ;
F_17 ( V_8 -> V_39 . V_17 , L_22 , V_98 , V_101 ) ;
for ( V_25 = 0 ; V_25 < V_8 -> V_39 . V_107 ; V_25 ++ ) {
V_6 = & V_8 -> V_9 [ V_25 ] ;
if ( F_53 ( V_108 , & V_6 -> V_26 ) )
F_63 ( V_8 , V_6 , V_101 , V_90 ) ;
else if ( V_101 & ( 1 << V_25 ) )
F_57 ( V_8 , V_6 ) ;
else if ( V_90 & ( 1 << V_25 ) )
F_51 ( V_8 , V_6 ) ;
}
F_28 ( V_8 , V_48 . V_49 , V_8 -> V_109 ) ;
F_28 ( V_8 , V_48 . ERROR , V_8 -> V_109 ) ;
}
static T_4 F_66 ( int V_110 , void * V_111 )
{
struct V_7 * V_8 = V_111 ;
T_1 V_112 ;
F_17 ( V_8 -> V_39 . V_17 , L_23 , V_98 ,
F_35 ( V_8 , V_113 ) ) ;
F_34 ( V_8 , V_48 . V_49 , V_8 -> V_109 ) ;
F_34 ( V_8 , V_48 . ERROR , V_8 -> V_109 ) ;
V_112 = F_35 ( V_8 , V_113 ) ;
if ( V_112 ) {
F_31 ( V_8 -> V_39 . V_17 ,
L_24 ,
V_112 ) ;
F_34 ( V_8 , V_48 . V_49 , ( 1 << 8 ) - 1 ) ;
F_34 ( V_8 , V_48 . V_114 , ( 1 << 8 ) - 1 ) ;
F_34 ( V_8 , V_48 . V_115 , ( 1 << 8 ) - 1 ) ;
F_34 ( V_8 , V_48 . ERROR , ( 1 << 8 ) - 1 ) ;
}
F_67 ( & V_8 -> V_116 ) ;
return V_117 ;
}
static T_5 F_68 ( struct V_77 * V_118 )
{
struct V_19 * V_22 = F_69 ( V_118 ) ;
struct V_5 * V_6 = F_61 ( V_118 -> V_9 ) ;
T_5 V_78 ;
unsigned long V_26 ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
V_78 = F_70 ( V_118 ) ;
if ( F_49 ( & V_6 -> V_20 ) ) {
F_17 ( F_6 ( V_118 -> V_9 ) , L_25 , V_98 ,
V_22 -> V_28 . V_78 ) ;
F_71 ( & V_22 -> V_29 , & V_6 -> V_20 ) ;
F_38 ( V_6 , F_8 ( V_6 ) ) ;
} else {
F_17 ( F_6 ( V_118 -> V_9 ) , L_26 , V_98 ,
V_22 -> V_28 . V_78 ) ;
F_71 ( & V_22 -> V_29 , & V_6 -> V_87 ) ;
}
F_16 ( & V_6 -> V_27 , V_26 ) ;
return V_78 ;
}
static struct V_77 *
F_72 ( struct V_16 * V_9 , T_3 V_119 , T_3 V_120 ,
T_6 V_97 , unsigned long V_26 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
struct V_7 * V_8 = F_4 ( V_9 -> V_10 ) ;
struct V_19 * V_22 ;
struct V_19 * V_65 ;
struct V_19 * V_96 ;
T_6 V_121 ;
T_6 V_122 ;
unsigned int V_123 ;
unsigned int V_124 ;
unsigned int V_125 ;
T_1 V_58 ;
F_17 ( F_6 ( V_9 ) ,
L_27 , V_98 ,
( unsigned long long ) V_119 , ( unsigned long long ) V_120 ,
V_97 , V_26 ) ;
if ( F_64 ( ! V_97 ) ) {
F_15 ( F_6 ( V_9 ) , L_28 , V_98 ) ;
return NULL ;
}
V_6 -> V_43 = V_126 ;
V_125 = F_5 (unsigned int, dw->data_width[dwc->src_master],
dw->data_width[dwc->dst_master]) ;
V_123 = V_124 = F_5 (unsigned int, data_width,
dwc_fast_fls(src | dest | len)) ;
V_58 = F_73 ( V_9 )
| F_74 ( V_124 )
| F_75 ( V_123 )
| V_127
| V_128
| V_129 ;
V_96 = V_65 = NULL ;
for ( V_122 = 0 ; V_122 < V_97 ; V_122 += V_121 << V_123 ) {
V_121 = F_5 ( T_6 , ( V_97 - V_122 ) >> V_123 ,
V_6 -> V_130 ) ;
V_22 = F_10 ( V_6 ) ;
if ( ! V_22 )
goto V_131;
V_22 -> V_59 . V_61 = V_120 + V_122 ;
V_22 -> V_59 . V_62 = V_119 + V_122 ;
V_22 -> V_59 . V_58 = V_58 ;
V_22 -> V_59 . V_63 = V_121 ;
V_22 -> V_97 = V_121 << V_123 ;
if ( ! V_65 ) {
V_65 = V_22 ;
} else {
V_96 -> V_59 . V_89 = V_22 -> V_28 . V_71 ;
F_71 ( & V_22 -> V_29 ,
& V_65 -> V_31 ) ;
}
V_96 = V_22 ;
}
if ( V_26 & V_132 )
V_96 -> V_59 . V_58 |= V_60 ;
V_96 -> V_59 . V_89 = 0 ;
V_65 -> V_28 . V_26 = V_26 ;
V_65 -> V_70 = V_97 ;
return & V_65 -> V_28 ;
V_131:
F_18 ( V_6 , V_65 ) ;
return NULL ;
}
static struct V_77 *
F_76 ( struct V_16 * V_9 , struct V_133 * V_134 ,
unsigned int V_135 , enum V_136 V_43 ,
unsigned long V_26 , void * V_137 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
struct V_7 * V_8 = F_4 ( V_9 -> V_10 ) ;
struct V_138 * V_139 = & V_6 -> V_140 ;
struct V_19 * V_96 ;
struct V_19 * V_65 ;
T_1 V_58 ;
T_3 V_141 ;
unsigned int V_142 ;
unsigned int V_143 ;
unsigned int V_125 ;
unsigned int V_25 ;
struct V_133 * V_144 ;
T_6 V_70 = 0 ;
F_17 ( F_6 ( V_9 ) , L_29 , V_98 ) ;
if ( F_64 ( ! F_44 ( V_43 ) || ! V_135 ) )
return NULL ;
V_6 -> V_43 = V_43 ;
V_96 = V_65 = NULL ;
switch ( V_43 ) {
case V_44 :
V_142 = F_77 ( V_139 -> V_145 ) ;
V_141 = V_139 -> V_146 ;
V_58 = ( F_73 ( V_9 )
| F_74 ( V_142 )
| V_147
| V_128 ) ;
V_58 |= V_139 -> V_148 ? F_78 ( V_149 ) :
F_78 ( V_150 ) ;
V_125 = V_8 -> V_125 [ V_6 -> V_4 ] ;
F_79 (sgl, sg, sg_len, i) {
struct V_19 * V_22 ;
T_1 V_97 , V_151 , V_152 ;
V_152 = F_80 ( V_144 ) ;
V_97 = F_81 ( V_144 ) ;
V_143 = F_5 (unsigned int,
data_width, dwc_fast_fls(mem | len)) ;
V_153:
V_22 = F_10 ( V_6 ) ;
if ( ! V_22 ) {
F_31 ( F_6 ( V_9 ) ,
L_30 ) ;
goto V_131;
}
V_22 -> V_59 . V_61 = V_152 ;
V_22 -> V_59 . V_62 = V_141 ;
V_22 -> V_59 . V_58 = V_58 | F_75 ( V_143 ) ;
if ( ( V_97 >> V_143 ) > V_6 -> V_130 ) {
V_151 = V_6 -> V_130 << V_143 ;
V_152 += V_151 ;
V_97 -= V_151 ;
} else {
V_151 = V_97 ;
V_97 = 0 ;
}
V_22 -> V_59 . V_63 = V_151 >> V_143 ;
V_22 -> V_97 = V_151 ;
if ( ! V_65 ) {
V_65 = V_22 ;
} else {
V_96 -> V_59 . V_89 = V_22 -> V_28 . V_71 ;
F_71 ( & V_22 -> V_29 ,
& V_65 -> V_31 ) ;
}
V_96 = V_22 ;
V_70 += V_151 ;
if ( V_97 )
goto V_153;
}
break;
case V_45 :
V_142 = F_77 ( V_139 -> V_154 ) ;
V_141 = V_139 -> V_155 ;
V_58 = ( F_73 ( V_9 )
| F_75 ( V_142 )
| V_127
| V_156 ) ;
V_58 |= V_139 -> V_148 ? F_78 ( V_157 ) :
F_78 ( V_158 ) ;
V_125 = V_8 -> V_125 [ V_6 -> V_3 ] ;
F_79 (sgl, sg, sg_len, i) {
struct V_19 * V_22 ;
T_1 V_97 , V_151 , V_152 ;
V_152 = F_80 ( V_144 ) ;
V_97 = F_81 ( V_144 ) ;
V_143 = F_5 (unsigned int,
data_width, dwc_fast_fls(mem | len)) ;
V_159:
V_22 = F_10 ( V_6 ) ;
if ( ! V_22 ) {
F_31 ( F_6 ( V_9 ) ,
L_30 ) ;
goto V_131;
}
V_22 -> V_59 . V_61 = V_141 ;
V_22 -> V_59 . V_62 = V_152 ;
V_22 -> V_59 . V_58 = V_58 | F_74 ( V_143 ) ;
if ( ( V_97 >> V_142 ) > V_6 -> V_130 ) {
V_151 = V_6 -> V_130 << V_142 ;
V_152 += V_151 ;
V_97 -= V_151 ;
} else {
V_151 = V_97 ;
V_97 = 0 ;
}
V_22 -> V_59 . V_63 = V_151 >> V_142 ;
V_22 -> V_97 = V_151 ;
if ( ! V_65 ) {
V_65 = V_22 ;
} else {
V_96 -> V_59 . V_89 = V_22 -> V_28 . V_71 ;
F_71 ( & V_22 -> V_29 ,
& V_65 -> V_31 ) ;
}
V_96 = V_22 ;
V_70 += V_151 ;
if ( V_97 )
goto V_159;
}
break;
default:
return NULL ;
}
if ( V_26 & V_132 )
V_96 -> V_59 . V_58 |= V_60 ;
V_96 -> V_59 . V_89 = 0 ;
V_65 -> V_70 = V_70 ;
return & V_65 -> V_28 ;
V_131:
F_18 ( V_6 , V_65 ) ;
return NULL ;
}
static inline void F_82 ( T_1 * V_160 )
{
if ( * V_160 > 1 )
* V_160 = F_83 ( * V_160 ) - 2 ;
else
* V_160 = 0 ;
}
static int
F_84 ( struct V_16 * V_9 , struct V_138 * V_139 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
if ( ! F_44 ( V_139 -> V_43 ) )
return - V_161 ;
memcpy ( & V_6 -> V_140 , V_139 , sizeof( * V_139 ) ) ;
V_6 -> V_43 = V_139 -> V_43 ;
if ( V_6 -> V_15 == ~ 0 )
V_6 -> V_15 = V_139 -> V_162 ;
F_82 ( & V_6 -> V_140 . V_163 ) ;
F_82 ( & V_6 -> V_140 . V_164 ) ;
return 0 ;
}
static inline void F_85 ( struct V_5 * V_6 )
{
T_1 V_35 = F_32 ( V_6 , V_46 ) ;
unsigned int V_165 = 20 ;
F_27 ( V_6 , V_46 , V_35 | V_166 ) ;
while ( ! ( F_32 ( V_6 , V_46 ) & V_167 ) && V_165 -- )
F_86 ( 2 ) ;
V_6 -> V_168 = true ;
}
static inline void F_87 ( struct V_5 * V_6 )
{
T_1 V_35 = F_32 ( V_6 , V_46 ) ;
F_27 ( V_6 , V_46 , V_35 & ~ V_166 ) ;
V_6 -> V_168 = false ;
}
static int F_88 ( struct V_16 * V_9 , enum V_169 V_170 ,
unsigned long V_171 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
struct V_7 * V_8 = F_4 ( V_9 -> V_10 ) ;
struct V_19 * V_22 , * V_23 ;
unsigned long V_26 ;
F_48 ( V_86 ) ;
if ( V_170 == V_172 ) {
F_11 ( & V_6 -> V_27 , V_26 ) ;
F_85 ( V_6 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
} else if ( V_170 == V_173 ) {
if ( ! V_6 -> V_168 )
return 0 ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
F_87 ( V_6 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
} else if ( V_170 == V_174 ) {
F_11 ( & V_6 -> V_27 , V_26 ) ;
F_54 ( V_68 , & V_6 -> V_26 ) ;
F_33 ( V_8 , V_6 ) ;
F_87 ( V_6 ) ;
F_20 ( & V_6 -> V_87 , & V_86 ) ;
F_20 ( & V_6 -> V_20 , & V_86 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
F_12 (desc, _desc, &list, desc_node)
F_40 ( V_6 , V_22 , false ) ;
} else if ( V_170 == V_175 ) {
return F_84 ( V_9 , (struct V_138 * ) V_171 ) ;
} else {
return - V_176 ;
}
return 0 ;
}
static inline T_1 F_89 ( struct V_5 * V_6 )
{
unsigned long V_26 ;
T_1 V_69 ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
V_69 = V_6 -> V_69 ;
if ( F_53 ( V_68 , & V_6 -> V_26 ) && V_69 )
V_69 -= F_50 ( V_6 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
return V_69 ;
}
static enum V_177
F_90 ( struct V_16 * V_9 ,
T_5 V_78 ,
struct V_178 * V_179 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
enum V_177 V_24 ;
V_24 = F_91 ( V_9 , V_78 , V_179 ) ;
if ( V_24 != V_180 ) {
F_51 ( F_4 ( V_9 -> V_10 ) , V_6 ) ;
V_24 = F_91 ( V_9 , V_78 , V_179 ) ;
}
if ( V_24 != V_180 )
F_92 ( V_179 , F_89 ( V_6 ) ) ;
if ( V_6 -> V_168 )
return V_181 ;
return V_24 ;
}
static void F_93 ( struct V_16 * V_9 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
if ( ! F_49 ( & V_6 -> V_87 ) )
F_51 ( F_4 ( V_9 -> V_10 ) , V_6 ) ;
}
static int F_94 ( struct V_16 * V_9 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
struct V_7 * V_8 = F_4 ( V_9 -> V_10 ) ;
struct V_19 * V_22 ;
int V_25 ;
unsigned long V_26 ;
F_17 ( F_6 ( V_9 ) , L_29 , V_98 ) ;
if ( F_35 ( V_8 , V_57 ) & V_6 -> V_50 ) {
F_15 ( F_6 ( V_9 ) , L_31 ) ;
return - V_182 ;
}
F_95 ( V_9 ) ;
F_3 ( V_6 ) ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
V_25 = V_6 -> V_183 ;
while ( V_6 -> V_183 < V_184 ) {
T_3 V_71 ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
V_22 = F_96 ( V_8 -> V_185 , V_186 , & V_71 ) ;
if ( ! V_22 )
goto V_187;
memset ( V_22 , 0 , sizeof( struct V_19 ) ) ;
F_97 ( & V_22 -> V_31 ) ;
F_98 ( & V_22 -> V_28 , V_9 ) ;
V_22 -> V_28 . V_188 = F_68 ;
V_22 -> V_28 . V_26 = V_189 ;
V_22 -> V_28 . V_71 = V_71 ;
F_18 ( V_6 , V_22 ) ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
V_25 = ++ V_6 -> V_183 ;
}
F_16 ( & V_6 -> V_27 , V_26 ) ;
F_15 ( F_6 ( V_9 ) , L_32 , V_98 , V_25 ) ;
return V_25 ;
V_187:
F_99 ( F_6 ( V_9 ) , L_33 , V_25 ) ;
return V_25 ;
}
static void F_100 ( struct V_16 * V_9 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
struct V_7 * V_8 = F_4 ( V_9 -> V_10 ) ;
struct V_19 * V_22 , * V_23 ;
unsigned long V_26 ;
F_48 ( V_86 ) ;
F_15 ( F_6 ( V_9 ) , L_34 , V_98 ,
V_6 -> V_183 ) ;
F_24 ( ! F_49 ( & V_6 -> V_20 ) ) ;
F_24 ( ! F_49 ( & V_6 -> V_87 ) ) ;
F_24 ( F_35 ( F_4 ( V_9 -> V_10 ) , V_57 ) & V_6 -> V_50 ) ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
F_20 ( & V_6 -> V_32 , & V_86 ) ;
V_6 -> V_183 = 0 ;
V_6 -> V_37 = false ;
V_6 -> V_15 = ~ 0 ;
F_34 ( V_8 , V_48 . V_49 , V_6 -> V_50 ) ;
F_34 ( V_8 , V_48 . ERROR , V_6 -> V_50 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
F_12 (desc, _desc, &list, desc_node) {
F_17 ( F_6 ( V_9 ) , L_35 , V_22 ) ;
F_101 ( V_8 -> V_185 , V_22 , V_22 -> V_28 . V_71 ) ;
}
F_17 ( F_6 ( V_9 ) , L_36 , V_98 ) ;
}
static bool F_102 ( struct V_16 * V_9 , void * V_76 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
struct V_190 * V_191 = V_76 ;
if ( V_9 -> V_10 != & V_191 -> V_8 -> V_39 )
return false ;
V_6 -> V_15 = V_191 -> V_192 ;
V_6 -> V_4 = V_191 -> V_120 ;
V_6 -> V_3 = V_191 -> V_193 ;
return true ;
}
static struct V_16 * F_103 ( struct V_194 * V_195 ,
struct V_196 * V_197 )
{
struct V_7 * V_8 = V_197 -> V_198 ;
struct V_190 V_191 = {
. V_8 = V_8 ,
} ;
T_7 V_199 ;
if ( V_195 -> V_200 != 3 )
return NULL ;
V_191 . V_192 = V_195 -> args [ 0 ] ;
V_191 . V_120 = V_195 -> args [ 1 ] ;
V_191 . V_193 = V_195 -> args [ 2 ] ;
if ( F_104 ( V_191 . V_192 >= V_201 ||
V_191 . V_120 >= V_8 -> V_14 ||
V_191 . V_193 >= V_8 -> V_14 ) )
return NULL ;
F_105 ( V_199 ) ;
F_106 ( V_202 , V_199 ) ;
return F_107 ( V_199 , F_102 , & V_191 ) ;
}
static bool F_108 ( struct V_16 * V_9 , void * V_76 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
struct V_203 * V_195 = V_76 ;
if ( V_9 -> V_10 -> V_17 != V_195 -> V_17 ||
V_9 -> V_204 != V_195 -> V_204 )
return false ;
V_6 -> V_15 = V_195 -> V_162 ;
V_6 -> V_4 = F_2 ( NULL ) ;
V_6 -> V_3 = F_1 ( NULL ) ;
return true ;
}
static void F_109 ( struct V_7 * V_8 )
{
struct V_10 * V_17 = V_8 -> V_39 . V_17 ;
struct V_205 * V_206 ;
int V_24 ;
V_206 = F_110 ( V_17 , sizeof( * V_206 ) , V_207 ) ;
if ( ! V_206 )
return;
F_105 ( V_206 -> V_208 ) ;
F_106 ( V_202 , V_206 -> V_208 ) ;
V_206 -> V_209 = F_108 ;
V_24 = F_111 ( V_17 , V_210 ,
V_206 ) ;
if ( V_24 )
F_31 ( V_17 , L_37 ) ;
}
static inline void F_109 ( struct V_7 * V_8 ) {}
int F_112 ( struct V_16 * V_9 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
struct V_7 * V_8 = F_4 ( V_6 -> V_9 . V_10 ) ;
unsigned long V_26 ;
if ( ! F_53 ( V_108 , & V_6 -> V_26 ) ) {
F_31 ( F_6 ( & V_6 -> V_9 ) , L_38 ) ;
return - V_211 ;
}
F_11 ( & V_6 -> V_27 , V_26 ) ;
if ( F_35 ( V_8 , V_57 ) & V_6 -> V_50 ) {
F_31 ( F_6 ( & V_6 -> V_9 ) ,
L_6 ) ;
F_30 ( V_6 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
return - V_212 ;
}
F_52 ( V_8 , V_92 . ERROR , V_6 -> V_50 ) ;
F_52 ( V_8 , V_92 . V_49 , V_6 -> V_50 ) ;
F_27 ( V_6 , V_54 , V_6 -> V_102 -> V_22 [ 0 ] -> V_28 . V_71 ) ;
F_27 ( V_6 , V_56 , V_72 | V_73 ) ;
F_27 ( V_6 , V_55 , 0 ) ;
F_28 ( V_8 , V_57 , V_6 -> V_50 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
return 0 ;
}
void F_113 ( struct V_16 * V_9 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
struct V_7 * V_8 = F_4 ( V_6 -> V_9 . V_10 ) ;
unsigned long V_26 ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
F_33 ( V_8 , V_6 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
}
struct V_213 * F_114 ( struct V_16 * V_9 ,
T_3 V_214 , T_6 V_215 , T_6 V_216 ,
enum V_136 V_43 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
struct V_138 * V_139 = & V_6 -> V_140 ;
struct V_213 * V_102 ;
struct V_213 * V_217 = NULL ;
struct V_19 * V_22 ;
struct V_19 * V_218 = NULL ;
unsigned long V_219 ;
unsigned int V_142 ;
unsigned int V_105 ;
unsigned int V_25 ;
unsigned long V_26 ;
F_11 ( & V_6 -> V_27 , V_26 ) ;
if ( V_6 -> V_67 ) {
F_16 ( & V_6 -> V_27 , V_26 ) ;
F_15 ( F_6 ( & V_6 -> V_9 ) ,
L_39 ) ;
return F_115 ( - V_161 ) ;
}
if ( ! F_49 ( & V_6 -> V_87 ) || ! F_49 ( & V_6 -> V_20 ) ) {
F_16 ( & V_6 -> V_27 , V_26 ) ;
F_15 ( F_6 ( & V_6 -> V_9 ) ,
L_40 ) ;
return F_115 ( - V_212 ) ;
}
V_219 = F_39 ( V_108 , & V_6 -> V_26 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
if ( V_219 ) {
F_15 ( F_6 ( & V_6 -> V_9 ) ,
L_41 ) ;
return F_115 ( - V_212 ) ;
}
V_217 = F_115 ( - V_161 ) ;
if ( F_64 ( ! F_44 ( V_43 ) ) )
goto V_220;
V_6 -> V_43 = V_43 ;
if ( V_43 == V_44 )
V_142 = F_116 ( V_139 -> V_145 ) ;
else
V_142 = F_116 ( V_139 -> V_154 ) ;
V_105 = V_215 / V_216 ;
if ( V_216 > ( V_6 -> V_130 << V_142 ) )
goto V_220;
if ( F_64 ( V_216 & ( ( 1 << V_142 ) - 1 ) ) )
goto V_220;
if ( F_64 ( V_214 & ( ( 1 << V_142 ) - 1 ) ) )
goto V_220;
V_217 = F_115 ( - V_221 ) ;
if ( V_105 > V_184 )
goto V_220;
V_102 = F_117 ( sizeof( struct V_213 ) , V_207 ) ;
if ( ! V_102 )
goto V_220;
V_102 -> V_22 = F_117 ( sizeof( struct V_19 * ) * V_105 , V_207 ) ;
if ( ! V_102 -> V_22 )
goto V_222;
for ( V_25 = 0 ; V_25 < V_105 ; V_25 ++ ) {
V_22 = F_10 ( V_6 ) ;
if ( ! V_22 )
goto V_223;
switch ( V_43 ) {
case V_44 :
V_22 -> V_59 . V_62 = V_139 -> V_146 ;
V_22 -> V_59 . V_61 = V_214 + ( V_216 * V_25 ) ;
V_22 -> V_59 . V_58 = ( F_73 ( V_9 )
| F_74 ( V_142 )
| F_75 ( V_142 )
| V_147
| V_128
| V_60 ) ;
V_22 -> V_59 . V_58 |= V_139 -> V_148 ?
F_78 ( V_149 ) :
F_78 ( V_150 ) ;
break;
case V_45 :
V_22 -> V_59 . V_62 = V_214 + ( V_216 * V_25 ) ;
V_22 -> V_59 . V_61 = V_139 -> V_155 ;
V_22 -> V_59 . V_58 = ( F_73 ( V_9 )
| F_75 ( V_142 )
| F_74 ( V_142 )
| V_127
| V_156
| V_60 ) ;
V_22 -> V_59 . V_58 |= V_139 -> V_148 ?
F_78 ( V_157 ) :
F_78 ( V_158 ) ;
break;
default:
break;
}
V_22 -> V_59 . V_63 = ( V_216 >> V_142 ) ;
V_102 -> V_22 [ V_25 ] = V_22 ;
if ( V_218 )
V_218 -> V_59 . V_89 = V_22 -> V_28 . V_71 ;
V_218 = V_22 ;
}
V_218 -> V_59 . V_89 = V_102 -> V_22 [ 0 ] -> V_28 . V_71 ;
F_15 ( F_6 ( & V_6 -> V_9 ) , L_42
L_43 , ( unsigned long long ) V_214 ,
V_215 , V_216 , V_105 ) ;
V_102 -> V_105 = V_105 ;
V_6 -> V_102 = V_102 ;
return V_102 ;
V_223:
while ( V_25 -- )
F_18 ( V_6 , V_102 -> V_22 [ V_25 ] ) ;
V_222:
F_118 ( V_102 ) ;
V_220:
F_54 ( V_108 , & V_6 -> V_26 ) ;
return (struct V_213 * ) V_217 ;
}
void F_119 ( struct V_16 * V_9 )
{
struct V_5 * V_6 = F_61 ( V_9 ) ;
struct V_7 * V_8 = F_4 ( V_6 -> V_9 . V_10 ) ;
struct V_213 * V_102 = V_6 -> V_102 ;
int V_25 ;
unsigned long V_26 ;
F_15 ( F_6 ( & V_6 -> V_9 ) , L_29 , V_98 ) ;
if ( ! V_102 )
return;
F_11 ( & V_6 -> V_27 , V_26 ) ;
F_33 ( V_8 , V_6 ) ;
F_52 ( V_8 , V_92 . ERROR , V_6 -> V_50 ) ;
F_52 ( V_8 , V_92 . V_49 , V_6 -> V_50 ) ;
F_16 ( & V_6 -> V_27 , V_26 ) ;
for ( V_25 = 0 ; V_25 < V_102 -> V_105 ; V_25 ++ )
F_18 ( V_6 , V_102 -> V_22 [ V_25 ] ) ;
F_118 ( V_102 -> V_22 ) ;
F_118 ( V_102 ) ;
F_54 ( V_108 , & V_6 -> V_26 ) ;
}
static void F_120 ( struct V_7 * V_8 )
{
int V_25 ;
F_52 ( V_8 , V_224 , 0 ) ;
F_34 ( V_8 , V_48 . V_49 , V_8 -> V_109 ) ;
F_34 ( V_8 , V_48 . V_114 , V_8 -> V_109 ) ;
F_34 ( V_8 , V_48 . V_115 , V_8 -> V_109 ) ;
F_34 ( V_8 , V_48 . ERROR , V_8 -> V_109 ) ;
while ( F_35 ( V_8 , V_224 ) & V_225 )
F_36 () ;
for ( V_25 = 0 ; V_25 < V_8 -> V_39 . V_107 ; V_25 ++ )
V_8 -> V_9 [ V_25 ] . V_37 = false ;
}
static struct V_226 *
F_121 ( struct V_227 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_17 . V_231 ;
struct V_226 * V_232 ;
T_1 V_233 , V_234 [ 4 ] ;
if ( ! V_230 ) {
F_31 ( & V_228 -> V_17 , L_44 ) ;
return NULL ;
}
V_232 = F_110 ( & V_228 -> V_17 , sizeof( * V_232 ) , V_207 ) ;
if ( ! V_232 )
return NULL ;
if ( F_122 ( V_230 , L_45 , & V_232 -> V_235 ) )
return NULL ;
if ( F_123 ( V_230 , L_46 ) )
V_232 -> V_236 = true ;
if ( ! F_122 ( V_230 , L_47 , & V_233 ) )
V_232 -> V_237 = ( unsigned char ) V_233 ;
if ( ! F_122 ( V_230 , L_48 , & V_233 ) )
V_232 -> V_238 = V_233 ;
if ( ! F_122 ( V_230 , L_49 , & V_233 ) )
V_232 -> V_130 = V_233 ;
if ( ! F_122 ( V_230 , L_50 , & V_233 ) ) {
if ( V_233 > 4 )
return NULL ;
V_232 -> V_14 = V_233 ;
}
if ( ! F_124 ( V_230 , L_51 , V_234 ,
V_232 -> V_14 ) )
for ( V_233 = 0 ; V_233 < V_232 -> V_14 ; V_233 ++ )
V_232 -> V_125 [ V_233 ] = V_234 [ V_233 ] ;
return V_232 ;
}
static inline struct V_226 *
F_121 ( struct V_227 * V_228 )
{
return NULL ;
}
static int F_125 ( struct V_227 * V_228 )
{
struct V_226 * V_232 ;
struct V_239 * V_240 ;
struct V_7 * V_8 ;
T_6 V_241 ;
void T_8 * V_242 ;
bool V_243 ;
unsigned int V_244 ;
unsigned int V_235 ;
unsigned int V_245 = 0 ;
int V_110 ;
int V_246 ;
int V_25 ;
V_240 = F_126 ( V_228 , V_247 , 0 ) ;
if ( ! V_240 )
return - V_161 ;
V_110 = F_127 ( V_228 , 0 ) ;
if ( V_110 < 0 )
return V_110 ;
V_242 = F_128 ( & V_228 -> V_17 , V_240 ) ;
if ( F_129 ( V_242 ) )
return F_130 ( V_242 ) ;
if ( ! V_228 -> V_17 . V_248 ) {
V_228 -> V_17 . V_248 = & V_228 -> V_17 . V_249 ;
V_228 -> V_17 . V_249 = F_131 ( 32 ) ;
}
V_244 = F_132 ( V_242 , V_250 ) ;
V_243 = V_244 >> V_251 & 0x1 ;
F_15 ( & V_228 -> V_17 , L_52 , V_244 ) ;
V_232 = F_133 ( & V_228 -> V_17 ) ;
if ( ! V_232 )
V_232 = F_121 ( V_228 ) ;
if ( ! V_232 && V_243 ) {
V_232 = F_110 ( & V_228 -> V_17 , sizeof( * V_232 ) , V_207 ) ;
if ( ! V_232 )
return - V_221 ;
V_232 -> V_236 = true ;
V_232 -> V_237 = V_252 ;
V_232 -> V_238 = V_253 ;
} else if ( ! V_232 || V_232 -> V_235 > V_254 )
return - V_161 ;
if ( V_243 )
V_235 = ( V_244 >> V_255 & 0x7 ) + 1 ;
else
V_235 = V_232 -> V_235 ;
V_241 = sizeof( struct V_7 ) + V_235 * sizeof( struct V_5 ) ;
V_8 = F_110 ( & V_228 -> V_17 , V_241 , V_207 ) ;
if ( ! V_8 )
return - V_221 ;
V_8 -> V_256 = F_134 ( & V_228 -> V_17 , L_53 ) ;
if ( F_129 ( V_8 -> V_256 ) )
return F_130 ( V_8 -> V_256 ) ;
F_135 ( V_8 -> V_256 ) ;
V_8 -> V_242 = V_242 ;
if ( V_243 ) {
V_245 = F_35 ( V_8 , V_257 ) ;
V_8 -> V_14 = ( V_244 >> V_258 & 3 ) + 1 ;
for ( V_25 = 0 ; V_25 < V_8 -> V_14 ; V_25 ++ ) {
V_8 -> V_125 [ V_25 ] =
( V_244 >> F_136 ( V_25 ) & 3 ) + 2 ;
}
} else {
V_8 -> V_14 = V_232 -> V_14 ;
memcpy ( V_8 -> V_125 , V_232 -> V_125 , 4 ) ;
}
V_8 -> V_109 = ( 1 << V_235 ) - 1 ;
F_120 ( V_8 ) ;
F_34 ( V_8 , V_48 . V_259 , V_8 -> V_109 ) ;
V_246 = F_137 ( & V_228 -> V_17 , V_110 , F_66 , 0 ,
L_54 , V_8 ) ;
if ( V_246 )
return V_246 ;
F_138 ( V_228 , V_8 ) ;
V_8 -> V_185 = F_139 ( L_55 , & V_228 -> V_17 ,
sizeof( struct V_19 ) , 4 , 0 ) ;
if ( ! V_8 -> V_185 ) {
F_31 ( & V_228 -> V_17 , L_56 ) ;
return - V_221 ;
}
F_140 ( & V_8 -> V_116 , F_65 , ( unsigned long ) V_8 ) ;
F_97 ( & V_8 -> V_39 . V_260 ) ;
for ( V_25 = 0 ; V_25 < V_235 ; V_25 ++ ) {
struct V_5 * V_6 = & V_8 -> V_9 [ V_25 ] ;
int V_261 = V_235 - V_25 - 1 ;
V_6 -> V_9 . V_10 = & V_8 -> V_39 ;
F_95 ( & V_6 -> V_9 ) ;
if ( V_232 -> V_237 == V_252 )
F_71 ( & V_6 -> V_9 . V_229 ,
& V_8 -> V_39 . V_260 ) ;
else
F_21 ( & V_6 -> V_9 . V_229 , & V_8 -> V_39 . V_260 ) ;
if ( V_232 -> V_238 == V_253 )
V_6 -> V_36 = V_261 ;
else
V_6 -> V_36 = V_25 ;
V_6 -> V_262 = & F_141 ( V_8 ) -> V_263 [ V_25 ] ;
F_142 ( & V_6 -> V_27 ) ;
V_6 -> V_50 = 1 << V_25 ;
F_97 ( & V_6 -> V_20 ) ;
F_97 ( & V_6 -> V_87 ) ;
F_97 ( & V_6 -> V_32 ) ;
F_34 ( V_8 , V_57 , V_6 -> V_50 ) ;
V_6 -> V_43 = V_264 ;
V_6 -> V_15 = ~ 0 ;
if ( V_243 ) {
unsigned int V_265 ;
V_265 = F_132 ( V_242 + V_261 * sizeof( T_1 ) ,
V_266 ) ;
F_15 ( & V_228 -> V_17 , L_57 , V_25 ,
V_265 ) ;
V_6 -> V_130 =
( 4 << ( ( V_245 >> 4 * V_25 ) & 0xf ) ) - 1 ;
V_6 -> V_67 =
( V_265 >> V_267 & 0x1 ) == 0 ;
} else {
V_6 -> V_130 = V_232 -> V_130 ;
F_27 ( V_6 , V_54 , 0xfffffffc ) ;
V_6 -> V_67 =
( F_32 ( V_6 , V_54 ) & 0xfffffffc ) == 0 ;
F_27 ( V_6 , V_54 , 0 ) ;
}
}
F_52 ( V_8 , V_92 . V_49 , V_8 -> V_109 ) ;
F_52 ( V_8 , V_92 . V_259 , V_8 -> V_109 ) ;
F_52 ( V_8 , V_92 . V_114 , V_8 -> V_109 ) ;
F_52 ( V_8 , V_92 . V_115 , V_8 -> V_109 ) ;
F_52 ( V_8 , V_92 . ERROR , V_8 -> V_109 ) ;
F_106 ( V_268 , V_8 -> V_39 . V_269 ) ;
F_106 ( V_202 , V_8 -> V_39 . V_269 ) ;
if ( V_232 -> V_236 )
F_106 ( V_270 , V_8 -> V_39 . V_269 ) ;
V_8 -> V_39 . V_17 = & V_228 -> V_17 ;
V_8 -> V_39 . V_271 = F_94 ;
V_8 -> V_39 . V_272 = F_100 ;
V_8 -> V_39 . V_273 = F_72 ;
V_8 -> V_39 . V_274 = F_76 ;
V_8 -> V_39 . V_275 = F_88 ;
V_8 -> V_39 . V_276 = F_90 ;
V_8 -> V_39 . V_277 = F_93 ;
F_52 ( V_8 , V_224 , V_225 ) ;
F_99 ( & V_228 -> V_17 , L_58 ,
V_235 ) ;
F_143 ( & V_8 -> V_39 ) ;
if ( V_228 -> V_17 . V_231 ) {
V_246 = F_144 ( V_228 -> V_17 . V_231 ,
F_103 , V_8 ) ;
if ( V_246 )
F_31 ( & V_228 -> V_17 ,
L_59 ) ;
}
if ( F_145 ( & V_228 -> V_17 ) )
F_109 ( V_8 ) ;
return 0 ;
}
static int F_146 ( struct V_227 * V_228 )
{
struct V_7 * V_8 = F_147 ( V_228 ) ;
struct V_5 * V_6 , * V_278 ;
if ( V_228 -> V_17 . V_231 )
F_148 ( V_228 -> V_17 . V_231 ) ;
F_120 ( V_8 ) ;
F_149 ( & V_8 -> V_39 ) ;
F_150 ( & V_8 -> V_116 ) ;
F_12 (dwc, _dwc, &dw->dma.channels,
chan.device_node) {
F_14 ( & V_6 -> V_9 . V_229 ) ;
F_34 ( V_8 , V_57 , V_6 -> V_50 ) ;
}
return 0 ;
}
static void F_151 ( struct V_227 * V_228 )
{
struct V_7 * V_8 = F_147 ( V_228 ) ;
F_120 ( V_8 ) ;
F_152 ( V_8 -> V_256 ) ;
}
static int F_153 ( struct V_10 * V_17 )
{
struct V_227 * V_228 = F_154 ( V_17 ) ;
struct V_7 * V_8 = F_147 ( V_228 ) ;
F_120 ( V_8 ) ;
F_152 ( V_8 -> V_256 ) ;
return 0 ;
}
static int F_155 ( struct V_10 * V_17 )
{
struct V_227 * V_228 = F_154 ( V_17 ) ;
struct V_7 * V_8 = F_147 ( V_228 ) ;
F_135 ( V_8 -> V_256 ) ;
F_52 ( V_8 , V_224 , V_225 ) ;
return 0 ;
}
static int T_9 F_156 ( void )
{
return F_157 ( & V_279 ) ;
}
static void T_10 F_158 ( void )
{
F_159 ( & V_279 ) ;
}
