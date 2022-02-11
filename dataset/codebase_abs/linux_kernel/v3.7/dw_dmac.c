static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_3 : 0 ;
}
static inline unsigned int F_2 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_4 : 1 ;
}
static struct V_5 * F_3 ( struct V_6 * V_7 )
{
return & V_7 -> V_8 -> V_5 ;
}
static struct V_5 * F_4 ( struct V_6 * V_7 )
{
return V_7 -> V_8 -> V_5 . V_9 ;
}
static struct V_10 * F_5 ( struct V_11 * V_12 )
{
return F_6 ( V_12 -> V_13 . V_14 , struct V_10 , V_15 ) ;
}
static struct V_10 * F_7 ( struct V_11 * V_12 )
{
struct V_10 * V_16 , * V_17 ;
struct V_10 * V_18 = NULL ;
unsigned int V_19 = 0 ;
unsigned long V_20 ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
F_9 (desc, _desc, &dwc->free_list, desc_node) {
V_19 ++ ;
if ( F_10 ( & V_16 -> V_22 ) ) {
F_11 ( & V_16 -> V_15 ) ;
V_18 = V_16 ;
break;
}
F_12 ( F_3 ( & V_12 -> V_7 ) , L_1 , V_16 ) ;
}
F_13 ( & V_12 -> V_21 , V_20 ) ;
F_14 ( F_3 ( & V_12 -> V_7 ) , L_2 , V_19 ) ;
return V_18 ;
}
static void F_15 ( struct V_11 * V_12 , struct V_10 * V_16 )
{
struct V_10 * V_23 ;
F_16 (child, &desc->tx_list, desc_node)
F_17 ( F_4 ( & V_12 -> V_7 ) ,
V_23 -> V_22 . V_24 , sizeof( V_23 -> V_25 ) ,
V_26 ) ;
F_17 ( F_4 ( & V_12 -> V_7 ) ,
V_16 -> V_22 . V_24 , sizeof( V_16 -> V_25 ) ,
V_26 ) ;
}
static void F_18 ( struct V_11 * V_12 , struct V_10 * V_16 )
{
unsigned long V_20 ;
if ( V_16 ) {
struct V_10 * V_23 ;
F_15 ( V_12 , V_16 ) ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
F_16 (child, &desc->tx_list, desc_node)
F_14 ( F_3 ( & V_12 -> V_7 ) ,
L_3 ,
V_23 ) ;
F_19 ( & V_16 -> V_27 , & V_12 -> V_28 ) ;
F_14 ( F_3 ( & V_12 -> V_7 ) , L_4 , V_16 ) ;
F_20 ( & V_16 -> V_15 , & V_12 -> V_28 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
}
}
static void F_21 ( struct V_11 * V_12 )
{
struct V_29 * V_30 = F_22 ( V_12 -> V_7 . V_5 ) ;
struct V_1 * V_31 = V_12 -> V_7 . V_32 ;
T_1 V_33 = V_34 ;
T_1 V_35 = F_23 ( V_12 -> V_36 ) ;
if ( V_12 -> V_37 == true )
return;
if ( V_31 ) {
F_24 ( ! V_31 -> V_38 || V_31 -> V_38 != V_30 -> V_39 . V_8 ) ;
V_33 = V_31 -> V_40 ;
V_35 |= V_31 -> V_41 & ~ V_42 ;
} else {
if ( V_12 -> V_43 . V_44 == V_45 )
V_33 = F_25 ( V_12 -> V_43 . V_46 ) ;
else if ( V_12 -> V_43 . V_44 == V_47 )
V_33 = F_26 ( V_12 -> V_43 . V_46 ) ;
}
F_27 ( V_12 , V_48 , V_35 ) ;
F_27 ( V_12 , V_49 , V_33 ) ;
F_28 ( V_30 , V_50 . V_51 , V_12 -> V_52 ) ;
F_28 ( V_30 , V_50 . ERROR , V_12 -> V_52 ) ;
V_12 -> V_37 = true ;
}
static inline unsigned int F_29 ( unsigned long long V_53 )
{
if ( ! ( V_53 & 7 ) )
return 3 ;
else if ( ! ( V_53 & 3 ) )
return 2 ;
else if ( ! ( V_53 & 1 ) )
return 1 ;
return 0 ;
}
static inline void F_30 ( struct V_11 * V_12 )
{
F_31 ( F_3 ( & V_12 -> V_7 ) ,
L_5 ,
F_32 ( V_12 , V_54 ) ,
F_32 ( V_12 , V_55 ) ,
F_32 ( V_12 , V_56 ) ,
F_32 ( V_12 , V_57 ) ,
F_32 ( V_12 , V_58 ) ) ;
}
static inline void F_33 ( struct V_29 * V_30 , struct V_11 * V_12 )
{
F_34 ( V_30 , V_59 , V_12 -> V_52 ) ;
while ( F_35 ( V_30 , V_59 ) & V_12 -> V_52 )
F_36 () ;
}
static inline void F_37 ( struct V_11 * V_12 ,
struct V_10 * V_16 )
{
struct V_29 * V_30 = F_22 ( V_12 -> V_7 . V_5 ) ;
T_1 V_60 ;
V_60 = V_16 -> V_25 . V_60 | V_61 ;
F_27 ( V_12 , V_54 , V_16 -> V_25 . V_62 ) ;
F_27 ( V_12 , V_55 , V_16 -> V_25 . V_63 ) ;
F_27 ( V_12 , V_58 , V_60 ) ;
F_27 ( V_12 , V_57 , V_16 -> V_25 . V_64 ) ;
F_28 ( V_30 , V_59 , V_12 -> V_52 ) ;
}
static void F_38 ( struct V_11 * V_12 , struct V_10 * V_65 )
{
struct V_29 * V_30 = F_22 ( V_12 -> V_7 . V_5 ) ;
unsigned long V_66 ;
if ( F_35 ( V_30 , V_59 ) & V_12 -> V_52 ) {
F_31 ( F_3 ( & V_12 -> V_7 ) ,
L_6 ) ;
F_30 ( V_12 ) ;
return;
}
if ( V_12 -> V_67 ) {
V_66 = F_39 ( V_68 ,
& V_12 -> V_20 ) ;
if ( V_66 ) {
F_31 ( F_3 ( & V_12 -> V_7 ) ,
L_7
L_8 ) ;
return;
}
F_21 ( V_12 ) ;
V_12 -> V_27 = & V_65 -> V_27 ;
V_12 -> V_69 = V_65 -> V_27 . V_14 ;
F_37 ( V_12 , V_65 ) ;
return;
}
F_21 ( V_12 ) ;
F_27 ( V_12 , V_56 , V_65 -> V_22 . V_24 ) ;
F_27 ( V_12 , V_58 ,
V_70 | V_71 ) ;
F_27 ( V_12 , V_57 , 0 ) ;
F_28 ( V_30 , V_59 , V_12 -> V_52 ) ;
}
static void
F_40 ( struct V_11 * V_12 , struct V_10 * V_16 ,
bool V_72 )
{
T_2 V_73 = NULL ;
void * V_74 = NULL ;
struct V_75 * V_22 = & V_16 -> V_22 ;
struct V_10 * V_23 ;
unsigned long V_20 ;
F_14 ( F_3 ( & V_12 -> V_7 ) , L_9 , V_22 -> V_76 ) ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
F_41 ( V_22 ) ;
if ( V_72 ) {
V_73 = V_22 -> V_73 ;
V_74 = V_22 -> V_77 ;
}
F_15 ( V_12 , V_16 ) ;
F_16 (child, &desc->tx_list, desc_node)
F_42 ( & V_23 -> V_22 ) ;
F_42 ( & V_16 -> V_22 ) ;
F_19 ( & V_16 -> V_27 , & V_12 -> V_28 ) ;
F_43 ( & V_16 -> V_15 , & V_12 -> V_28 ) ;
if ( ! V_12 -> V_7 . V_32 ) {
struct V_5 * V_9 = F_4 ( & V_12 -> V_7 ) ;
if ( ! ( V_22 -> V_20 & V_78 ) ) {
if ( V_22 -> V_20 & V_79 )
F_44 ( V_9 , V_16 -> V_25 . V_63 ,
V_16 -> V_80 , V_81 ) ;
else
F_45 ( V_9 , V_16 -> V_25 . V_63 ,
V_16 -> V_80 , V_81 ) ;
}
if ( ! ( V_22 -> V_20 & V_82 ) ) {
if ( V_22 -> V_20 & V_83 )
F_44 ( V_9 , V_16 -> V_25 . V_62 ,
V_16 -> V_80 , V_26 ) ;
else
F_45 ( V_9 , V_16 -> V_25 . V_62 ,
V_16 -> V_80 , V_26 ) ;
}
}
F_13 ( & V_12 -> V_21 , V_20 ) ;
if ( V_72 && V_73 )
V_73 ( V_74 ) ;
}
static void F_46 ( struct V_29 * V_30 , struct V_11 * V_12 )
{
struct V_10 * V_16 , * V_17 ;
F_47 ( V_84 ) ;
unsigned long V_20 ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
if ( F_35 ( V_30 , V_59 ) & V_12 -> V_52 ) {
F_31 ( F_3 ( & V_12 -> V_7 ) ,
L_10 ) ;
F_33 ( V_30 , V_12 ) ;
}
F_19 ( & V_12 -> V_13 , & V_84 ) ;
if ( ! F_48 ( & V_12 -> V_85 ) ) {
F_43 ( V_12 -> V_85 . V_14 , & V_12 -> V_13 ) ;
F_38 ( V_12 , F_5 ( V_12 ) ) ;
}
F_13 ( & V_12 -> V_21 , V_20 ) ;
F_9 (desc, _desc, &list, desc_node)
F_40 ( V_12 , V_16 , true ) ;
}
static void F_49 ( struct V_29 * V_30 , struct V_11 * V_12 )
{
T_3 V_86 ;
struct V_10 * V_16 , * V_17 ;
struct V_10 * V_23 ;
T_1 V_87 ;
unsigned long V_20 ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
V_86 = F_32 ( V_12 , V_56 ) ;
V_87 = F_35 ( V_30 , V_88 . V_51 ) ;
if ( V_87 & V_12 -> V_52 ) {
F_50 ( V_30 , V_89 . V_51 , V_12 -> V_52 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
F_46 ( V_30 , V_12 ) ;
return;
}
if ( F_48 ( & V_12 -> V_13 ) ) {
F_13 ( & V_12 -> V_21 , V_20 ) ;
return;
}
F_14 ( F_3 ( & V_12 -> V_7 ) , L_11 , V_90 ,
( unsigned long long ) V_86 ) ;
F_9 (desc, _desc, &dwc->active_list, desc_node) {
if ( V_16 -> V_22 . V_24 == V_86 ) {
F_13 ( & V_12 -> V_21 , V_20 ) ;
return;
}
if ( V_16 -> V_25 . V_86 == V_86 ) {
F_13 ( & V_12 -> V_21 , V_20 ) ;
return;
}
F_16 (child, &desc->tx_list, desc_node)
if ( V_23 -> V_25 . V_86 == V_86 ) {
F_13 ( & V_12 -> V_21 , V_20 ) ;
return;
}
F_13 ( & V_12 -> V_21 , V_20 ) ;
F_40 ( V_12 , V_16 , true ) ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
}
F_31 ( F_3 ( & V_12 -> V_7 ) ,
L_12 ) ;
F_33 ( V_30 , V_12 ) ;
if ( ! F_48 ( & V_12 -> V_85 ) ) {
F_43 ( V_12 -> V_85 . V_14 , & V_12 -> V_13 ) ;
F_38 ( V_12 , F_5 ( V_12 ) ) ;
}
F_13 ( & V_12 -> V_21 , V_20 ) ;
}
static inline void F_51 ( struct V_11 * V_12 , struct V_91 * V_25 )
{
F_52 ( V_92 , F_3 ( & V_12 -> V_7 ) ,
L_13 ,
V_25 -> V_62 , V_25 -> V_63 , V_25 -> V_86 , V_25 -> V_64 , V_25 -> V_60 ) ;
}
static void F_53 ( struct V_29 * V_30 , struct V_11 * V_12 )
{
struct V_10 * V_93 ;
struct V_10 * V_23 ;
unsigned long V_20 ;
F_49 ( V_30 , V_12 ) ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
V_93 = F_5 ( V_12 ) ;
F_54 ( & V_93 -> V_15 ) ;
F_43 ( V_12 -> V_85 . V_14 , V_12 -> V_13 . V_94 ) ;
F_50 ( V_30 , V_89 . ERROR , V_12 -> V_52 ) ;
if ( ! F_48 ( & V_12 -> V_13 ) )
F_38 ( V_12 , F_5 ( V_12 ) ) ;
F_52 ( V_92 , F_3 ( & V_12 -> V_7 ) ,
L_14 ) ;
F_52 ( V_92 , F_3 ( & V_12 -> V_7 ) ,
L_15 , V_93 -> V_22 . V_76 ) ;
F_51 ( V_12 , & V_93 -> V_25 ) ;
F_16 (child, &bad_desc->tx_list, desc_node)
F_51 ( V_12 , & V_23 -> V_25 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
F_40 ( V_12 , V_93 , true ) ;
}
inline T_3 F_55 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
return F_32 ( V_12 , V_54 ) ;
}
inline T_3 F_57 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
return F_32 ( V_12 , V_55 ) ;
}
static void F_58 ( struct V_29 * V_30 , struct V_11 * V_12 ,
T_1 V_95 , T_1 V_87 )
{
unsigned long V_20 ;
if ( V_12 -> V_52 ) {
void (* V_73)( void * V_74 );
void * V_77 ;
F_14 ( F_3 ( & V_12 -> V_7 ) , L_16 ,
F_32 ( V_12 , V_56 ) ) ;
V_73 = V_12 -> V_96 -> V_97 ;
V_77 = V_12 -> V_96 -> V_98 ;
if ( V_73 )
V_73 ( V_77 ) ;
}
if ( F_59 ( V_95 & V_12 -> V_52 ) ||
F_59 ( V_87 & V_12 -> V_52 ) ) {
int V_19 ;
F_31 ( F_3 ( & V_12 -> V_7 ) , L_17
L_18 ,
V_87 ? L_19 : L_20 ) ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
F_30 ( V_12 ) ;
F_33 ( V_30 , V_12 ) ;
F_27 ( V_12 , V_56 , 0 ) ;
F_27 ( V_12 , V_58 , 0 ) ;
F_27 ( V_12 , V_57 , 0 ) ;
F_50 ( V_30 , V_89 . ERROR , V_12 -> V_52 ) ;
F_50 ( V_30 , V_89 . V_51 , V_12 -> V_52 ) ;
for ( V_19 = 0 ; V_19 < V_12 -> V_96 -> V_99 ; V_19 ++ )
F_51 ( V_12 , & V_12 -> V_96 -> V_16 [ V_19 ] -> V_25 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
}
}
static void F_60 ( unsigned long V_100 )
{
struct V_29 * V_30 = (struct V_29 * ) V_100 ;
struct V_11 * V_12 ;
T_1 V_87 ;
T_1 V_95 ;
int V_19 ;
V_87 = F_35 ( V_30 , V_88 . V_51 ) ;
V_95 = F_35 ( V_30 , V_88 . ERROR ) ;
F_14 ( V_30 -> V_39 . V_8 , L_21 , V_90 , V_95 ) ;
for ( V_19 = 0 ; V_19 < V_30 -> V_39 . V_101 ; V_19 ++ ) {
V_12 = & V_30 -> V_7 [ V_19 ] ;
if ( F_61 ( V_102 , & V_12 -> V_20 ) )
F_58 ( V_30 , V_12 , V_95 , V_87 ) ;
else if ( V_95 & ( 1 << V_19 ) )
F_53 ( V_30 , V_12 ) ;
else if ( V_87 & ( 1 << V_19 ) ) {
unsigned long V_20 ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
if ( F_61 ( V_68 , & V_12 -> V_20 ) ) {
if ( V_12 -> V_69 != V_12 -> V_27 ) {
struct V_10 * V_16 =
F_6 ( V_12 -> V_69 ,
struct V_10 ,
V_15 ) ;
F_50 ( V_30 , V_89 . V_51 , V_12 -> V_52 ) ;
V_12 -> V_69 =
V_12 -> V_69 -> V_14 ;
F_37 ( V_12 , V_16 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
continue;
} else {
F_62 ( V_68 , & V_12 -> V_20 ) ;
}
}
F_13 ( & V_12 -> V_21 , V_20 ) ;
F_49 ( V_30 , V_12 ) ;
}
}
F_28 ( V_30 , V_50 . V_51 , V_30 -> V_103 ) ;
F_28 ( V_30 , V_50 . ERROR , V_30 -> V_103 ) ;
}
static T_4 F_63 ( int V_104 , void * V_105 )
{
struct V_29 * V_30 = V_105 ;
T_1 V_106 ;
F_14 ( V_30 -> V_39 . V_8 , L_22 , V_90 ,
F_35 ( V_30 , V_107 ) ) ;
F_34 ( V_30 , V_50 . V_51 , V_30 -> V_103 ) ;
F_34 ( V_30 , V_50 . ERROR , V_30 -> V_103 ) ;
V_106 = F_35 ( V_30 , V_107 ) ;
if ( V_106 ) {
F_31 ( V_30 -> V_39 . V_8 ,
L_23 ,
V_106 ) ;
F_34 ( V_30 , V_50 . V_51 , ( 1 << 8 ) - 1 ) ;
F_34 ( V_30 , V_50 . V_108 , ( 1 << 8 ) - 1 ) ;
F_34 ( V_30 , V_50 . V_109 , ( 1 << 8 ) - 1 ) ;
F_34 ( V_30 , V_50 . ERROR , ( 1 << 8 ) - 1 ) ;
}
F_64 ( & V_30 -> V_110 ) ;
return V_111 ;
}
static T_5 F_65 ( struct V_75 * V_112 )
{
struct V_10 * V_16 = F_66 ( V_112 ) ;
struct V_11 * V_12 = F_56 ( V_112 -> V_7 ) ;
T_5 V_76 ;
unsigned long V_20 ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
V_76 = F_67 ( V_112 ) ;
if ( F_48 ( & V_12 -> V_13 ) ) {
F_14 ( F_3 ( V_112 -> V_7 ) , L_24 , V_90 ,
V_16 -> V_22 . V_76 ) ;
F_68 ( & V_16 -> V_15 , & V_12 -> V_13 ) ;
F_38 ( V_12 , F_5 ( V_12 ) ) ;
} else {
F_14 ( F_3 ( V_112 -> V_7 ) , L_25 , V_90 ,
V_16 -> V_22 . V_76 ) ;
F_68 ( & V_16 -> V_15 , & V_12 -> V_85 ) ;
}
F_13 ( & V_12 -> V_21 , V_20 ) ;
return V_76 ;
}
static struct V_75 *
F_69 ( struct V_6 * V_7 , T_3 V_113 , T_3 V_114 ,
T_6 V_80 , unsigned long V_20 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
struct V_1 * V_31 = V_7 -> V_32 ;
struct V_10 * V_16 ;
struct V_10 * V_65 ;
struct V_10 * V_94 ;
T_6 V_115 ;
T_6 V_116 ;
unsigned int V_117 ;
unsigned int V_118 ;
unsigned int V_119 ;
T_1 V_60 ;
F_14 ( F_3 ( V_7 ) ,
L_26 , V_90 ,
( unsigned long long ) V_113 , ( unsigned long long ) V_114 ,
V_80 , V_20 ) ;
if ( F_59 ( ! V_80 ) ) {
F_12 ( F_3 ( V_7 ) , L_27 , V_90 ) ;
return NULL ;
}
V_119 = F_70 (unsigned int, dwc->dw->data_width[dwc_get_sms(dws)],
dwc->dw->data_width[dwc_get_dms(dws)]) ;
V_117 = V_118 = F_70 (unsigned int, data_width,
dwc_fast_fls(src | dest | len)) ;
V_60 = F_71 ( V_7 )
| F_72 ( V_118 )
| F_73 ( V_117 )
| V_120
| V_121
| V_122 ;
V_94 = V_65 = NULL ;
for ( V_116 = 0 ; V_116 < V_80 ; V_116 += V_115 << V_117 ) {
V_115 = F_70 ( T_6 , ( V_80 - V_116 ) >> V_117 ,
V_12 -> V_123 ) ;
V_16 = F_7 ( V_12 ) ;
if ( ! V_16 )
goto V_124;
V_16 -> V_25 . V_62 = V_114 + V_116 ;
V_16 -> V_25 . V_63 = V_113 + V_116 ;
V_16 -> V_25 . V_60 = V_60 ;
V_16 -> V_25 . V_64 = V_115 ;
if ( ! V_65 ) {
V_65 = V_16 ;
} else {
V_94 -> V_25 . V_86 = V_16 -> V_22 . V_24 ;
F_74 ( F_4 ( V_7 ) ,
V_94 -> V_22 . V_24 , sizeof( V_94 -> V_25 ) ,
V_26 ) ;
F_68 ( & V_16 -> V_15 ,
& V_65 -> V_27 ) ;
}
V_94 = V_16 ;
}
if ( V_20 & V_125 )
V_94 -> V_25 . V_60 |= V_61 ;
V_94 -> V_25 . V_86 = 0 ;
F_74 ( F_4 ( V_7 ) ,
V_94 -> V_22 . V_24 , sizeof( V_94 -> V_25 ) ,
V_26 ) ;
V_65 -> V_22 . V_20 = V_20 ;
V_65 -> V_80 = V_80 ;
return & V_65 -> V_22 ;
V_124:
F_18 ( V_12 , V_65 ) ;
return NULL ;
}
static struct V_75 *
F_75 ( struct V_6 * V_7 , struct V_126 * V_127 ,
unsigned int V_128 , enum V_129 V_44 ,
unsigned long V_20 , void * V_130 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
struct V_1 * V_31 = V_7 -> V_32 ;
struct V_131 * V_132 = & V_12 -> V_43 ;
struct V_10 * V_94 ;
struct V_10 * V_65 ;
T_1 V_60 ;
T_3 V_133 ;
unsigned int V_134 ;
unsigned int V_135 ;
unsigned int V_119 ;
unsigned int V_19 ;
struct V_126 * V_136 ;
T_6 V_137 = 0 ;
F_14 ( F_3 ( V_7 ) , L_28 , V_90 ) ;
if ( F_59 ( ! V_31 || ! V_128 ) )
return NULL ;
V_94 = V_65 = NULL ;
switch ( V_44 ) {
case V_45 :
V_134 = F_76 ( V_132 -> V_138 ) ;
V_133 = V_132 -> V_139 ;
V_60 = ( F_71 ( V_7 )
| F_72 ( V_134 )
| V_140
| V_121 ) ;
V_60 |= V_132 -> V_141 ? F_77 ( V_142 ) :
F_77 ( V_143 ) ;
V_119 = V_12 -> V_30 -> V_119 [ F_2 ( V_31 ) ] ;
F_78 (sgl, sg, sg_len, i) {
struct V_10 * V_16 ;
T_1 V_80 , V_144 , V_145 ;
V_145 = F_79 ( V_136 ) ;
V_80 = F_80 ( V_136 ) ;
V_135 = F_70 (unsigned int,
data_width, dwc_fast_fls(mem | len)) ;
V_146:
V_16 = F_7 ( V_12 ) ;
if ( ! V_16 ) {
F_31 ( F_3 ( V_7 ) ,
L_29 ) ;
goto V_124;
}
V_16 -> V_25 . V_62 = V_145 ;
V_16 -> V_25 . V_63 = V_133 ;
V_16 -> V_25 . V_60 = V_60 | F_73 ( V_135 ) ;
if ( ( V_80 >> V_135 ) > V_12 -> V_123 ) {
V_144 = V_12 -> V_123 << V_135 ;
V_145 += V_144 ;
V_80 -= V_144 ;
} else {
V_144 = V_80 ;
V_80 = 0 ;
}
V_16 -> V_25 . V_64 = V_144 >> V_135 ;
if ( ! V_65 ) {
V_65 = V_16 ;
} else {
V_94 -> V_25 . V_86 = V_16 -> V_22 . V_24 ;
F_74 ( F_4 ( V_7 ) ,
V_94 -> V_22 . V_24 ,
sizeof( V_94 -> V_25 ) ,
V_26 ) ;
F_68 ( & V_16 -> V_15 ,
& V_65 -> V_27 ) ;
}
V_94 = V_16 ;
V_137 += V_144 ;
if ( V_80 )
goto V_146;
}
break;
case V_47 :
V_134 = F_76 ( V_132 -> V_147 ) ;
V_133 = V_132 -> V_148 ;
V_60 = ( F_71 ( V_7 )
| F_73 ( V_134 )
| V_120
| V_149 ) ;
V_60 |= V_132 -> V_141 ? F_77 ( V_150 ) :
F_77 ( V_151 ) ;
V_119 = V_12 -> V_30 -> V_119 [ F_1 ( V_31 ) ] ;
F_78 (sgl, sg, sg_len, i) {
struct V_10 * V_16 ;
T_1 V_80 , V_144 , V_145 ;
V_145 = F_79 ( V_136 ) ;
V_80 = F_80 ( V_136 ) ;
V_135 = F_70 (unsigned int,
data_width, dwc_fast_fls(mem | len)) ;
V_152:
V_16 = F_7 ( V_12 ) ;
if ( ! V_16 ) {
F_31 ( F_3 ( V_7 ) ,
L_29 ) ;
goto V_124;
}
V_16 -> V_25 . V_62 = V_133 ;
V_16 -> V_25 . V_63 = V_145 ;
V_16 -> V_25 . V_60 = V_60 | F_72 ( V_135 ) ;
if ( ( V_80 >> V_134 ) > V_12 -> V_123 ) {
V_144 = V_12 -> V_123 << V_134 ;
V_145 += V_144 ;
V_80 -= V_144 ;
} else {
V_144 = V_80 ;
V_80 = 0 ;
}
V_16 -> V_25 . V_64 = V_144 >> V_134 ;
if ( ! V_65 ) {
V_65 = V_16 ;
} else {
V_94 -> V_25 . V_86 = V_16 -> V_22 . V_24 ;
F_74 ( F_4 ( V_7 ) ,
V_94 -> V_22 . V_24 ,
sizeof( V_94 -> V_25 ) ,
V_26 ) ;
F_68 ( & V_16 -> V_15 ,
& V_65 -> V_27 ) ;
}
V_94 = V_16 ;
V_137 += V_144 ;
if ( V_80 )
goto V_152;
}
break;
default:
return NULL ;
}
if ( V_20 & V_125 )
V_94 -> V_25 . V_60 |= V_61 ;
V_94 -> V_25 . V_86 = 0 ;
F_74 ( F_4 ( V_7 ) ,
V_94 -> V_22 . V_24 , sizeof( V_94 -> V_25 ) ,
V_26 ) ;
V_65 -> V_80 = V_137 ;
return & V_65 -> V_22 ;
V_124:
F_18 ( V_12 , V_65 ) ;
return NULL ;
}
static inline void F_81 ( T_1 * V_153 )
{
if ( * V_153 > 1 )
* V_153 = F_82 ( * V_153 ) - 2 ;
else
* V_153 = 0 ;
}
static int
F_83 ( struct V_6 * V_7 , struct V_131 * V_132 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
if ( ! V_7 -> V_32 )
return - V_154 ;
memcpy ( & V_12 -> V_43 , V_132 , sizeof( * V_132 ) ) ;
F_81 ( & V_12 -> V_43 . V_155 ) ;
F_81 ( & V_12 -> V_43 . V_156 ) ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 , enum V_157 V_158 ,
unsigned long V_159 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
struct V_29 * V_30 = F_22 ( V_7 -> V_5 ) ;
struct V_10 * V_16 , * V_17 ;
unsigned long V_20 ;
T_1 V_35 ;
F_47 ( V_84 ) ;
if ( V_158 == V_160 ) {
F_8 ( & V_12 -> V_21 , V_20 ) ;
V_35 = F_32 ( V_12 , V_48 ) ;
F_27 ( V_12 , V_48 , V_35 | V_161 ) ;
while ( ! ( F_32 ( V_12 , V_48 ) & V_162 ) )
F_36 () ;
V_12 -> V_163 = true ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
} else if ( V_158 == V_164 ) {
if ( ! V_12 -> V_163 )
return 0 ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
V_35 = F_32 ( V_12 , V_48 ) ;
F_27 ( V_12 , V_48 , V_35 & ~ V_161 ) ;
V_12 -> V_163 = false ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
} else if ( V_158 == V_165 ) {
F_8 ( & V_12 -> V_21 , V_20 ) ;
F_62 ( V_68 , & V_12 -> V_20 ) ;
F_33 ( V_30 , V_12 ) ;
V_12 -> V_163 = false ;
F_19 ( & V_12 -> V_85 , & V_84 ) ;
F_19 ( & V_12 -> V_13 , & V_84 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
F_9 (desc, _desc, &list, desc_node)
F_40 ( V_12 , V_16 , false ) ;
} else if ( V_158 == V_166 ) {
return F_83 ( V_7 , (struct V_131 * ) V_159 ) ;
} else {
return - V_167 ;
}
return 0 ;
}
static enum V_168
F_85 ( struct V_6 * V_7 ,
T_5 V_76 ,
struct V_169 * V_170 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
enum V_168 V_18 ;
V_18 = F_86 ( V_7 , V_76 , V_170 ) ;
if ( V_18 != V_171 ) {
F_49 ( F_22 ( V_7 -> V_5 ) , V_12 ) ;
V_18 = F_86 ( V_7 , V_76 , V_170 ) ;
}
if ( V_18 != V_171 )
F_87 ( V_170 , F_5 ( V_12 ) -> V_80 ) ;
if ( V_12 -> V_163 )
return V_172 ;
return V_18 ;
}
static void F_88 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
if ( ! F_48 ( & V_12 -> V_85 ) )
F_49 ( F_22 ( V_7 -> V_5 ) , V_12 ) ;
}
static int F_89 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
struct V_29 * V_30 = F_22 ( V_7 -> V_5 ) ;
struct V_10 * V_16 ;
int V_19 ;
unsigned long V_20 ;
F_14 ( F_3 ( V_7 ) , L_28 , V_90 ) ;
if ( F_35 ( V_30 , V_59 ) & V_12 -> V_52 ) {
F_12 ( F_3 ( V_7 ) , L_30 ) ;
return - V_173 ;
}
F_90 ( V_7 ) ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
V_19 = V_12 -> V_174 ;
while ( V_12 -> V_174 < V_175 ) {
F_13 ( & V_12 -> V_21 , V_20 ) ;
V_16 = F_91 ( sizeof( struct V_10 ) , V_176 ) ;
if ( ! V_16 ) {
F_92 ( F_3 ( V_7 ) ,
L_31 , V_19 ) ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
break;
}
F_93 ( & V_16 -> V_27 ) ;
F_94 ( & V_16 -> V_22 , V_7 ) ;
V_16 -> V_22 . V_177 = F_65 ;
V_16 -> V_22 . V_20 = V_178 ;
V_16 -> V_22 . V_24 = F_95 ( F_4 ( V_7 ) , & V_16 -> V_25 ,
sizeof( V_16 -> V_25 ) , V_26 ) ;
F_18 ( V_12 , V_16 ) ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
V_19 = ++ V_12 -> V_174 ;
}
F_13 ( & V_12 -> V_21 , V_20 ) ;
F_12 ( F_3 ( V_7 ) , L_32 , V_90 , V_19 ) ;
return V_19 ;
}
static void F_96 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
struct V_29 * V_30 = F_22 ( V_7 -> V_5 ) ;
struct V_10 * V_16 , * V_17 ;
unsigned long V_20 ;
F_47 ( V_84 ) ;
F_12 ( F_3 ( V_7 ) , L_33 , V_90 ,
V_12 -> V_174 ) ;
F_24 ( ! F_48 ( & V_12 -> V_13 ) ) ;
F_24 ( ! F_48 ( & V_12 -> V_85 ) ) ;
F_24 ( F_35 ( F_22 ( V_7 -> V_5 ) , V_59 ) & V_12 -> V_52 ) ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
F_19 ( & V_12 -> V_28 , & V_84 ) ;
V_12 -> V_174 = 0 ;
V_12 -> V_37 = false ;
F_34 ( V_30 , V_50 . V_51 , V_12 -> V_52 ) ;
F_34 ( V_30 , V_50 . ERROR , V_12 -> V_52 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
F_9 (desc, _desc, &list, desc_node) {
F_14 ( F_3 ( V_7 ) , L_34 , V_16 ) ;
F_44 ( F_4 ( V_7 ) , V_16 -> V_22 . V_24 ,
sizeof( V_16 -> V_25 ) , V_26 ) ;
F_97 ( V_16 ) ;
}
F_14 ( F_3 ( V_7 ) , L_35 , V_90 ) ;
}
int F_98 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
struct V_29 * V_30 = F_22 ( V_12 -> V_7 . V_5 ) ;
unsigned long V_20 ;
if ( ! F_61 ( V_102 , & V_12 -> V_20 ) ) {
F_31 ( F_3 ( & V_12 -> V_7 ) , L_36 ) ;
return - V_179 ;
}
F_8 ( & V_12 -> V_21 , V_20 ) ;
if ( F_35 ( V_30 , V_59 ) & V_12 -> V_52 ) {
F_31 ( F_3 ( & V_12 -> V_7 ) ,
L_6 ) ;
F_30 ( V_12 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
return - V_180 ;
}
F_50 ( V_30 , V_89 . ERROR , V_12 -> V_52 ) ;
F_50 ( V_30 , V_89 . V_51 , V_12 -> V_52 ) ;
F_27 ( V_12 , V_56 , V_12 -> V_96 -> V_16 [ 0 ] -> V_22 . V_24 ) ;
F_27 ( V_12 , V_58 , V_70 | V_71 ) ;
F_27 ( V_12 , V_57 , 0 ) ;
F_28 ( V_30 , V_59 , V_12 -> V_52 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
return 0 ;
}
void F_99 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
struct V_29 * V_30 = F_22 ( V_12 -> V_7 . V_5 ) ;
unsigned long V_20 ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
F_33 ( V_30 , V_12 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
}
struct V_181 * F_100 ( struct V_6 * V_7 ,
T_3 V_182 , T_6 V_183 , T_6 V_184 ,
enum V_129 V_44 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
struct V_131 * V_132 = & V_12 -> V_43 ;
struct V_181 * V_96 ;
struct V_181 * V_185 = NULL ;
struct V_10 * V_16 ;
struct V_10 * V_186 = NULL ;
unsigned long V_187 ;
unsigned int V_134 ;
unsigned int V_99 ;
unsigned int V_19 ;
unsigned long V_20 ;
F_8 ( & V_12 -> V_21 , V_20 ) ;
if ( V_12 -> V_67 ) {
F_13 ( & V_12 -> V_21 , V_20 ) ;
F_12 ( F_3 ( & V_12 -> V_7 ) ,
L_37 ) ;
return F_101 ( - V_154 ) ;
}
if ( ! F_48 ( & V_12 -> V_85 ) || ! F_48 ( & V_12 -> V_13 ) ) {
F_13 ( & V_12 -> V_21 , V_20 ) ;
F_12 ( F_3 ( & V_12 -> V_7 ) ,
L_38 ) ;
return F_101 ( - V_180 ) ;
}
V_187 = F_39 ( V_102 , & V_12 -> V_20 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
if ( V_187 ) {
F_12 ( F_3 ( & V_12 -> V_7 ) ,
L_39 ) ;
return F_101 ( - V_180 ) ;
}
V_185 = F_101 ( - V_154 ) ;
if ( V_44 == V_45 )
V_134 = F_102 ( V_132 -> V_138 ) ;
else
V_134 = F_102 ( V_132 -> V_147 ) ;
V_99 = V_183 / V_184 ;
if ( V_184 > ( V_12 -> V_123 << V_134 ) )
goto V_188;
if ( F_59 ( V_184 & ( ( 1 << V_134 ) - 1 ) ) )
goto V_188;
if ( F_59 ( V_182 & ( ( 1 << V_134 ) - 1 ) ) )
goto V_188;
if ( F_59 ( ! ( V_44 & ( V_45 | V_47 ) ) ) )
goto V_188;
V_185 = F_101 ( - V_189 ) ;
if ( V_99 > V_175 )
goto V_188;
V_96 = F_91 ( sizeof( struct V_181 ) , V_176 ) ;
if ( ! V_96 )
goto V_188;
V_96 -> V_16 = F_91 ( sizeof( struct V_10 * ) * V_99 , V_176 ) ;
if ( ! V_96 -> V_16 )
goto V_190;
for ( V_19 = 0 ; V_19 < V_99 ; V_19 ++ ) {
V_16 = F_7 ( V_12 ) ;
if ( ! V_16 )
goto V_191;
switch ( V_44 ) {
case V_45 :
V_16 -> V_25 . V_63 = V_132 -> V_139 ;
V_16 -> V_25 . V_62 = V_182 + ( V_184 * V_19 ) ;
V_16 -> V_25 . V_60 = ( F_71 ( V_7 )
| F_72 ( V_134 )
| F_73 ( V_134 )
| V_140
| V_121
| V_61 ) ;
V_16 -> V_25 . V_60 |= V_132 -> V_141 ?
F_77 ( V_142 ) :
F_77 ( V_143 ) ;
break;
case V_47 :
V_16 -> V_25 . V_63 = V_182 + ( V_184 * V_19 ) ;
V_16 -> V_25 . V_62 = V_132 -> V_148 ;
V_16 -> V_25 . V_60 = ( F_71 ( V_7 )
| F_73 ( V_134 )
| F_72 ( V_134 )
| V_120
| V_149
| V_61 ) ;
V_16 -> V_25 . V_60 |= V_132 -> V_141 ?
F_77 ( V_150 ) :
F_77 ( V_151 ) ;
break;
default:
break;
}
V_16 -> V_25 . V_64 = ( V_184 >> V_134 ) ;
V_96 -> V_16 [ V_19 ] = V_16 ;
if ( V_186 ) {
V_186 -> V_25 . V_86 = V_16 -> V_22 . V_24 ;
F_74 ( F_4 ( V_7 ) ,
V_186 -> V_22 . V_24 , sizeof( V_186 -> V_25 ) ,
V_26 ) ;
}
V_186 = V_16 ;
}
V_186 -> V_25 . V_86 = V_96 -> V_16 [ 0 ] -> V_22 . V_24 ;
F_74 ( F_4 ( V_7 ) , V_186 -> V_22 . V_24 ,
sizeof( V_186 -> V_25 ) , V_26 ) ;
F_12 ( F_3 ( & V_12 -> V_7 ) , L_40
L_41 , ( unsigned long long ) V_182 ,
V_183 , V_184 , V_99 ) ;
V_96 -> V_99 = V_99 ;
V_12 -> V_96 = V_96 ;
return V_96 ;
V_191:
while ( V_19 -- )
F_18 ( V_12 , V_96 -> V_16 [ V_19 ] ) ;
V_190:
F_97 ( V_96 ) ;
V_188:
F_62 ( V_102 , & V_12 -> V_20 ) ;
return (struct V_181 * ) V_185 ;
}
void F_103 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_56 ( V_7 ) ;
struct V_29 * V_30 = F_22 ( V_12 -> V_7 . V_5 ) ;
struct V_181 * V_96 = V_12 -> V_96 ;
int V_19 ;
unsigned long V_20 ;
F_12 ( F_3 ( & V_12 -> V_7 ) , L_28 , V_90 ) ;
if ( ! V_96 )
return;
F_8 ( & V_12 -> V_21 , V_20 ) ;
F_33 ( V_30 , V_12 ) ;
F_50 ( V_30 , V_89 . ERROR , V_12 -> V_52 ) ;
F_50 ( V_30 , V_89 . V_51 , V_12 -> V_52 ) ;
F_13 ( & V_12 -> V_21 , V_20 ) ;
for ( V_19 = 0 ; V_19 < V_96 -> V_99 ; V_19 ++ )
F_18 ( V_12 , V_96 -> V_16 [ V_19 ] ) ;
F_97 ( V_96 -> V_16 ) ;
F_97 ( V_96 ) ;
F_62 ( V_102 , & V_12 -> V_20 ) ;
}
static void F_104 ( struct V_29 * V_30 )
{
int V_19 ;
F_50 ( V_30 , V_192 , 0 ) ;
F_34 ( V_30 , V_50 . V_51 , V_30 -> V_103 ) ;
F_34 ( V_30 , V_50 . V_108 , V_30 -> V_103 ) ;
F_34 ( V_30 , V_50 . V_109 , V_30 -> V_103 ) ;
F_34 ( V_30 , V_50 . ERROR , V_30 -> V_103 ) ;
while ( F_35 ( V_30 , V_192 ) & V_193 )
F_36 () ;
for ( V_19 = 0 ; V_19 < V_30 -> V_39 . V_101 ; V_19 ++ )
V_30 -> V_7 [ V_19 ] . V_37 = false ;
}
static int T_7 F_105 ( struct V_194 * V_195 )
{
struct V_196 * V_197 ;
struct V_198 * V_199 ;
struct V_29 * V_30 ;
T_6 V_200 ;
void T_8 * V_201 ;
bool V_202 ;
unsigned int V_203 ;
unsigned int V_204 ;
unsigned int V_205 = 0 ;
int V_104 ;
int V_206 ;
int V_19 ;
V_197 = F_106 ( & V_195 -> V_8 ) ;
if ( ! V_197 || V_197 -> V_204 > V_207 )
return - V_154 ;
V_199 = F_107 ( V_195 , V_208 , 0 ) ;
if ( ! V_199 )
return - V_154 ;
V_104 = F_108 ( V_195 , 0 ) ;
if ( V_104 < 0 )
return V_104 ;
V_201 = F_109 ( & V_195 -> V_8 , V_199 ) ;
if ( ! V_201 )
return - V_180 ;
V_203 = F_110 ( V_201 , V_209 ) ;
V_202 = V_203 >> V_210 & 0x1 ;
if ( V_202 )
V_204 = ( V_203 >> V_211 & 0x7 ) + 1 ;
else
V_204 = V_197 -> V_204 ;
V_200 = sizeof( struct V_29 ) + V_204 * sizeof( struct V_11 ) ;
V_30 = F_111 ( & V_195 -> V_8 , V_200 , V_176 ) ;
if ( ! V_30 )
return - V_189 ;
V_30 -> V_212 = F_112 ( & V_195 -> V_8 , L_42 ) ;
if ( F_113 ( V_30 -> V_212 ) )
return F_114 ( V_30 -> V_212 ) ;
F_115 ( V_30 -> V_212 ) ;
V_30 -> V_201 = V_201 ;
if ( V_202 ) {
V_205 = F_35 ( V_30 , V_213 ) ;
V_30 -> V_214 = ( V_203 >> V_215 & 3 ) + 1 ;
for ( V_19 = 0 ; V_19 < V_30 -> V_214 ; V_19 ++ ) {
V_30 -> V_119 [ V_19 ] =
( V_203 >> F_116 ( V_19 ) & 3 ) + 2 ;
}
} else {
V_30 -> V_214 = V_197 -> V_214 ;
memcpy ( V_30 -> V_119 , V_197 -> V_119 , 4 ) ;
}
V_30 -> V_103 = ( 1 << V_204 ) - 1 ;
F_104 ( V_30 ) ;
F_34 ( V_30 , V_50 . V_216 , V_30 -> V_103 ) ;
V_206 = F_117 ( & V_195 -> V_8 , V_104 , F_63 , 0 ,
L_43 , V_30 ) ;
if ( V_206 )
return V_206 ;
F_118 ( V_195 , V_30 ) ;
F_119 ( & V_30 -> V_110 , F_60 , ( unsigned long ) V_30 ) ;
F_93 ( & V_30 -> V_39 . V_217 ) ;
for ( V_19 = 0 ; V_19 < V_204 ; V_19 ++ ) {
struct V_11 * V_12 = & V_30 -> V_7 [ V_19 ] ;
int V_218 = V_204 - V_19 - 1 ;
V_12 -> V_7 . V_5 = & V_30 -> V_39 ;
F_90 ( & V_12 -> V_7 ) ;
if ( V_197 -> V_219 == V_220 )
F_68 ( & V_12 -> V_7 . V_221 ,
& V_30 -> V_39 . V_217 ) ;
else
F_20 ( & V_12 -> V_7 . V_221 , & V_30 -> V_39 . V_217 ) ;
if ( V_197 -> V_222 == V_223 )
V_12 -> V_36 = V_218 ;
else
V_12 -> V_36 = V_19 ;
V_12 -> V_224 = & F_120 ( V_30 ) -> V_225 [ V_19 ] ;
F_121 ( & V_12 -> V_21 ) ;
V_12 -> V_52 = 1 << V_19 ;
F_93 ( & V_12 -> V_13 ) ;
F_93 ( & V_12 -> V_85 ) ;
F_93 ( & V_12 -> V_28 ) ;
F_34 ( V_30 , V_59 , V_12 -> V_52 ) ;
V_12 -> V_30 = V_30 ;
if ( V_202 ) {
unsigned int V_226 ;
V_226 = F_110 ( V_201 + V_218 * sizeof( T_1 ) ,
V_227 ) ;
V_12 -> V_123 =
( 4 << ( ( V_205 >> 4 * V_19 ) & 0xf ) ) - 1 ;
V_12 -> V_67 =
( V_226 >> V_228 & 0x1 ) == 0 ;
} else {
V_12 -> V_123 = V_197 -> V_123 ;
F_27 ( V_12 , V_56 , 0xfffffffc ) ;
V_12 -> V_67 =
( F_32 ( V_12 , V_56 ) & 0xfffffffc ) == 0 ;
F_27 ( V_12 , V_56 , 0 ) ;
}
}
F_50 ( V_30 , V_89 . V_51 , V_30 -> V_103 ) ;
F_50 ( V_30 , V_89 . V_216 , V_30 -> V_103 ) ;
F_50 ( V_30 , V_89 . V_108 , V_30 -> V_103 ) ;
F_50 ( V_30 , V_89 . V_109 , V_30 -> V_103 ) ;
F_50 ( V_30 , V_89 . ERROR , V_30 -> V_103 ) ;
F_122 ( V_229 , V_30 -> V_39 . V_230 ) ;
F_122 ( V_231 , V_30 -> V_39 . V_230 ) ;
if ( V_197 -> V_232 )
F_122 ( V_233 , V_30 -> V_39 . V_230 ) ;
V_30 -> V_39 . V_8 = & V_195 -> V_8 ;
V_30 -> V_39 . V_234 = F_89 ;
V_30 -> V_39 . V_235 = F_96 ;
V_30 -> V_39 . V_236 = F_69 ;
V_30 -> V_39 . V_237 = F_75 ;
V_30 -> V_39 . V_238 = F_84 ;
V_30 -> V_39 . V_239 = F_85 ;
V_30 -> V_39 . V_240 = F_88 ;
F_50 ( V_30 , V_192 , V_193 ) ;
F_123 ( V_241 L_44 ,
F_124 ( & V_195 -> V_8 ) , V_204 ) ;
F_125 ( & V_30 -> V_39 ) ;
return 0 ;
}
static int T_9 F_126 ( struct V_194 * V_195 )
{
struct V_29 * V_30 = F_127 ( V_195 ) ;
struct V_11 * V_12 , * V_242 ;
F_104 ( V_30 ) ;
F_128 ( & V_30 -> V_39 ) ;
F_129 ( & V_30 -> V_110 ) ;
F_9 (dwc, _dwc, &dw->dma.channels,
chan.device_node) {
F_11 ( & V_12 -> V_7 . V_221 ) ;
F_34 ( V_30 , V_59 , V_12 -> V_52 ) ;
}
return 0 ;
}
static void F_130 ( struct V_194 * V_195 )
{
struct V_29 * V_30 = F_127 ( V_195 ) ;
F_104 ( F_127 ( V_195 ) ) ;
F_131 ( V_30 -> V_212 ) ;
}
static int F_132 ( struct V_5 * V_8 )
{
struct V_194 * V_195 = F_133 ( V_8 ) ;
struct V_29 * V_30 = F_127 ( V_195 ) ;
F_104 ( F_127 ( V_195 ) ) ;
F_131 ( V_30 -> V_212 ) ;
return 0 ;
}
static int F_134 ( struct V_5 * V_8 )
{
struct V_194 * V_195 = F_133 ( V_8 ) ;
struct V_29 * V_30 = F_127 ( V_195 ) ;
F_115 ( V_30 -> V_212 ) ;
F_50 ( V_30 , V_192 , V_193 ) ;
return 0 ;
}
static int T_10 F_135 ( void )
{
return F_136 ( & V_243 , F_105 ) ;
}
static void T_11 F_137 ( void )
{
F_138 ( & V_243 ) ;
}
