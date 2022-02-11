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
if ( F_8 ( & V_12 -> V_18 ) ) {
F_9 ( & V_12 -> V_11 ) ;
V_14 = V_12 ;
break;
}
F_10 ( F_1 ( & V_8 -> V_3 ) , L_1 , V_12 ) ;
V_15 ++ ;
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
static T_1
F_19 ( struct V_7 * V_8 , struct V_6 * V_12 )
{
T_1 V_25 = V_8 -> V_3 . V_25 ;
if ( ++ V_25 < 0 )
V_25 = 1 ;
V_8 -> V_3 . V_25 = V_25 ;
V_12 -> V_18 . V_25 = V_25 ;
return V_25 ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_26 * V_27 = F_21 ( V_8 -> V_3 . V_1 ) ;
struct V_28 * V_29 = V_8 -> V_3 . V_30 ;
T_2 V_31 = V_32 ;
T_2 V_33 = F_22 ( V_8 -> V_34 ) ;
if ( V_8 -> V_35 == true )
return;
if ( V_29 ) {
F_23 ( ! V_29 -> V_36 || V_29 -> V_36 != V_27 -> V_37 . V_4 ) ;
V_31 = V_29 -> V_38 ;
V_33 |= V_29 -> V_39 & ~ V_40 ;
}
F_24 ( V_8 , V_41 , V_33 ) ;
F_24 ( V_8 , V_42 , V_31 ) ;
F_25 ( V_27 , V_43 . V_44 , V_8 -> V_45 ) ;
F_25 ( V_27 , V_43 . V_46 , V_8 -> V_45 ) ;
F_25 ( V_27 , V_43 . ERROR , V_8 -> V_45 ) ;
V_8 -> V_35 = true ;
}
static void F_26 ( struct V_7 * V_8 , struct V_6 * V_47 )
{
struct V_26 * V_27 = F_21 ( V_8 -> V_3 . V_1 ) ;
if ( F_27 ( V_27 , V_48 ) & V_8 -> V_45 ) {
F_28 ( F_1 ( & V_8 -> V_3 ) ,
L_5 ) ;
F_28 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ,
F_29 ( V_8 , V_49 ) ,
F_29 ( V_8 , V_50 ) ,
F_29 ( V_8 , V_51 ) ,
F_29 ( V_8 , V_52 ) ,
F_29 ( V_8 , V_53 ) ) ;
return;
}
F_20 ( V_8 ) ;
F_24 ( V_8 , V_51 , V_47 -> V_18 . V_20 ) ;
F_24 ( V_8 , V_53 ,
V_54 | V_55 ) ;
F_24 ( V_8 , V_52 , 0 ) ;
F_25 ( V_27 , V_48 , V_8 -> V_45 ) ;
}
static void
F_30 ( struct V_7 * V_8 , struct V_6 * V_12 ,
bool V_56 )
{
T_3 V_57 = NULL ;
void * V_58 = NULL ;
struct V_59 * V_18 = & V_12 -> V_18 ;
struct V_6 * V_19 ;
unsigned long V_16 ;
F_12 ( F_1 ( & V_8 -> V_3 ) , L_7 , V_18 -> V_25 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_8 -> V_60 = V_18 -> V_25 ;
if ( V_56 ) {
V_57 = V_18 -> V_57 ;
V_58 = V_18 -> V_61 ;
}
F_13 ( V_8 , V_12 ) ;
F_14 (child, &desc->tx_list, desc_node)
F_31 ( & V_19 -> V_18 ) ;
F_31 ( & V_12 -> V_18 ) ;
F_17 ( & V_12 -> V_23 , & V_8 -> V_24 ) ;
F_32 ( & V_12 -> V_11 , & V_8 -> V_24 ) ;
if ( ! V_8 -> V_3 . V_30 ) {
struct V_1 * V_5 = F_2 ( & V_8 -> V_3 ) ;
if ( ! ( V_18 -> V_16 & V_62 ) ) {
if ( V_18 -> V_16 & V_63 )
F_33 ( V_5 , V_12 -> V_21 . V_64 ,
V_12 -> V_65 , V_66 ) ;
else
F_34 ( V_5 , V_12 -> V_21 . V_64 ,
V_12 -> V_65 , V_66 ) ;
}
if ( ! ( V_18 -> V_16 & V_67 ) ) {
if ( V_18 -> V_16 & V_68 )
F_33 ( V_5 , V_12 -> V_21 . V_69 ,
V_12 -> V_65 , V_22 ) ;
else
F_34 ( V_5 , V_12 -> V_21 . V_69 ,
V_12 -> V_65 , V_22 ) ;
}
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
if ( V_56 && V_57 )
V_57 ( V_58 ) ;
}
static void F_35 ( struct V_26 * V_27 , struct V_7 * V_8 )
{
struct V_6 * V_12 , * V_13 ;
F_36 ( V_70 ) ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( F_27 ( V_27 , V_48 ) & V_8 -> V_45 ) {
F_28 ( F_1 ( & V_8 -> V_3 ) ,
L_8 ) ;
F_37 ( V_27 , V_48 , V_8 -> V_45 ) ;
while ( F_27 ( V_27 , V_48 ) & V_8 -> V_45 )
F_38 () ;
}
F_17 ( & V_8 -> V_9 , & V_70 ) ;
if ( ! F_39 ( & V_8 -> V_71 ) ) {
F_32 ( V_8 -> V_71 . V_10 , & V_8 -> V_9 ) ;
F_26 ( V_8 , F_3 ( V_8 ) ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node)
F_30 ( V_8 , V_12 , true ) ;
}
static void F_40 ( struct V_26 * V_27 , struct V_7 * V_8 )
{
T_4 V_72 ;
struct V_6 * V_12 , * V_13 ;
struct V_6 * V_19 ;
T_2 V_73 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_41 ( V_27 , V_74 . V_46 , V_8 -> V_45 ) ;
V_72 = F_29 ( V_8 , V_51 ) ;
V_73 = F_27 ( V_27 , V_75 . V_44 ) ;
if ( V_73 & V_8 -> V_45 ) {
F_41 ( V_27 , V_74 . V_44 , V_8 -> V_45 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_35 ( V_27 , V_8 ) ;
return;
}
if ( F_39 ( & V_8 -> V_9 ) ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_12 ( F_1 ( & V_8 -> V_3 ) , L_9 , V_72 ) ;
F_7 (desc, _desc, &dwc->active_list, desc_node) {
if ( V_12 -> V_18 . V_20 == V_72 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
if ( V_12 -> V_21 . V_72 == V_72 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_14 (child, &desc->tx_list, desc_node)
if ( V_19 -> V_21 . V_72 == V_72 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_30 ( V_8 , V_12 , true ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
}
F_28 ( F_1 ( & V_8 -> V_3 ) ,
L_10 ) ;
F_37 ( V_27 , V_48 , V_8 -> V_45 ) ;
while ( F_27 ( V_27 , V_48 ) & V_8 -> V_45 )
F_38 () ;
if ( ! F_39 ( & V_8 -> V_71 ) ) {
F_32 ( V_8 -> V_71 . V_10 , & V_8 -> V_9 ) ;
F_26 ( V_8 , F_3 ( V_8 ) ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
static void F_42 ( struct V_7 * V_8 , struct V_76 * V_21 )
{
F_43 ( V_77 , F_1 ( & V_8 -> V_3 ) ,
L_11 ,
V_21 -> V_69 , V_21 -> V_64 , V_21 -> V_72 ,
V_21 -> V_78 , V_21 -> V_79 ) ;
}
static void F_44 ( struct V_26 * V_27 , struct V_7 * V_8 )
{
struct V_6 * V_80 ;
struct V_6 * V_19 ;
unsigned long V_16 ;
F_40 ( V_27 , V_8 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_80 = F_3 ( V_8 ) ;
F_45 ( & V_80 -> V_11 ) ;
F_32 ( V_8 -> V_71 . V_10 , V_8 -> V_9 . V_81 ) ;
F_41 ( V_27 , V_74 . ERROR , V_8 -> V_45 ) ;
if ( ! F_39 ( & V_8 -> V_9 ) )
F_26 ( V_8 , F_3 ( V_8 ) ) ;
F_43 ( V_77 , F_1 ( & V_8 -> V_3 ) ,
L_12 ) ;
F_43 ( V_77 , F_1 ( & V_8 -> V_3 ) ,
L_13 , V_80 -> V_18 . V_25 ) ;
F_42 ( V_8 , & V_80 -> V_21 ) ;
F_14 (child, &bad_desc->tx_list, desc_node)
F_42 ( V_8 , & V_19 -> V_21 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_30 ( V_8 , V_80 , true ) ;
}
inline T_4 F_46 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
return F_29 ( V_8 , V_49 ) ;
}
inline T_4 F_48 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
return F_29 ( V_8 , V_50 ) ;
}
static void F_49 ( struct V_26 * V_27 , struct V_7 * V_8 ,
T_2 V_82 , T_2 V_83 , T_2 V_73 )
{
unsigned long V_16 ;
if ( V_82 & V_8 -> V_45 ) {
void (* V_57)( void * V_58 );
void * V_61 ;
F_12 ( F_1 ( & V_8 -> V_3 ) , L_14 ,
F_29 ( V_8 , V_51 ) ) ;
F_41 ( V_27 , V_74 . V_46 , V_8 -> V_45 ) ;
V_57 = V_8 -> V_84 -> V_85 ;
V_61 = V_8 -> V_84 -> V_86 ;
if ( V_57 )
V_57 ( V_61 ) ;
}
if ( F_50 ( V_83 & V_8 -> V_45 ) ||
F_50 ( V_73 & V_8 -> V_45 ) ) {
int V_15 ;
F_28 ( F_1 ( & V_8 -> V_3 ) , L_15
L_16 ,
V_73 ? L_17 : L_18 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_28 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ,
F_29 ( V_8 , V_49 ) ,
F_29 ( V_8 , V_50 ) ,
F_29 ( V_8 , V_51 ) ,
F_29 ( V_8 , V_52 ) ,
F_29 ( V_8 , V_53 ) ) ;
F_37 ( V_27 , V_48 , V_8 -> V_45 ) ;
while ( F_27 ( V_27 , V_48 ) & V_8 -> V_45 )
F_38 () ;
F_24 ( V_8 , V_51 , 0 ) ;
F_24 ( V_8 , V_53 , 0 ) ;
F_24 ( V_8 , V_52 , 0 ) ;
F_41 ( V_27 , V_74 . V_46 , V_8 -> V_45 ) ;
F_41 ( V_27 , V_74 . ERROR , V_8 -> V_45 ) ;
F_41 ( V_27 , V_74 . V_44 , V_8 -> V_45 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_84 -> V_87 ; V_15 ++ )
F_42 ( V_8 , & V_8 -> V_84 -> V_12 [ V_15 ] -> V_21 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
}
static void F_51 ( unsigned long V_88 )
{
struct V_26 * V_27 = (struct V_26 * ) V_88 ;
struct V_7 * V_8 ;
T_2 V_82 ;
T_2 V_73 ;
T_2 V_83 ;
int V_15 ;
V_82 = F_27 ( V_27 , V_75 . V_46 ) ;
V_73 = F_27 ( V_27 , V_75 . V_44 ) ;
V_83 = F_27 ( V_27 , V_75 . ERROR ) ;
F_12 ( V_27 -> V_37 . V_4 , L_19 ,
V_82 , V_83 ) ;
for ( V_15 = 0 ; V_15 < V_27 -> V_37 . V_89 ; V_15 ++ ) {
V_8 = & V_27 -> V_3 [ V_15 ] ;
if ( F_52 ( V_90 , & V_8 -> V_16 ) )
F_49 ( V_27 , V_8 , V_82 , V_83 ,
V_73 ) ;
else if ( V_83 & ( 1 << V_15 ) )
F_44 ( V_27 , V_8 ) ;
else if ( ( V_82 | V_73 ) & ( 1 << V_15 ) )
F_40 ( V_27 , V_8 ) ;
}
F_25 ( V_27 , V_43 . V_44 , V_27 -> V_91 ) ;
F_25 ( V_27 , V_43 . V_46 , V_27 -> V_91 ) ;
F_25 ( V_27 , V_43 . ERROR , V_27 -> V_91 ) ;
}
static T_5 F_53 ( int V_92 , void * V_93 )
{
struct V_26 * V_27 = V_93 ;
T_2 V_94 ;
F_12 ( V_27 -> V_37 . V_4 , L_20 ,
F_27 ( V_27 , V_95 ) ) ;
F_37 ( V_27 , V_43 . V_44 , V_27 -> V_91 ) ;
F_37 ( V_27 , V_43 . V_46 , V_27 -> V_91 ) ;
F_37 ( V_27 , V_43 . ERROR , V_27 -> V_91 ) ;
V_94 = F_27 ( V_27 , V_95 ) ;
if ( V_94 ) {
F_28 ( V_27 -> V_37 . V_4 ,
L_21 ,
V_94 ) ;
F_37 ( V_27 , V_43 . V_44 , ( 1 << 8 ) - 1 ) ;
F_37 ( V_27 , V_43 . V_46 , ( 1 << 8 ) - 1 ) ;
F_37 ( V_27 , V_43 . V_96 , ( 1 << 8 ) - 1 ) ;
F_37 ( V_27 , V_43 . V_97 , ( 1 << 8 ) - 1 ) ;
F_37 ( V_27 , V_43 . ERROR , ( 1 << 8 ) - 1 ) ;
}
F_54 ( & V_27 -> V_98 ) ;
return V_99 ;
}
static T_1 F_55 ( struct V_59 * V_100 )
{
struct V_6 * V_12 = F_56 ( V_100 ) ;
struct V_7 * V_8 = F_47 ( V_100 -> V_3 ) ;
T_1 V_25 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_25 = F_19 ( V_8 , V_12 ) ;
if ( F_39 ( & V_8 -> V_9 ) ) {
F_12 ( F_1 ( V_100 -> V_3 ) , L_22 ,
V_12 -> V_18 . V_25 ) ;
F_57 ( & V_12 -> V_11 , & V_8 -> V_9 ) ;
F_26 ( V_8 , F_3 ( V_8 ) ) ;
} else {
F_12 ( F_1 ( V_100 -> V_3 ) , L_23 ,
V_12 -> V_18 . V_25 ) ;
F_57 ( & V_12 -> V_11 , & V_8 -> V_71 ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
return V_25 ;
}
static struct V_59 *
F_58 ( struct V_2 * V_3 , T_4 V_101 , T_4 V_102 ,
T_6 V_65 , unsigned long V_16 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_6 * V_12 ;
struct V_6 * V_47 ;
struct V_6 * V_81 ;
T_6 V_103 ;
T_6 V_104 ;
unsigned int V_105 ;
unsigned int V_106 ;
T_2 V_79 ;
F_12 ( F_1 ( V_3 ) , L_24 ,
V_101 , V_102 , V_65 , V_16 ) ;
if ( F_50 ( ! V_65 ) ) {
F_10 ( F_1 ( V_3 ) , L_25 ) ;
return NULL ;
}
if ( ! ( ( V_102 | V_101 | V_65 ) & 7 ) )
V_105 = V_106 = 3 ;
else if ( ! ( ( V_102 | V_101 | V_65 ) & 3 ) )
V_105 = V_106 = 2 ;
else if ( ! ( ( V_102 | V_101 | V_65 ) & 1 ) )
V_105 = V_106 = 1 ;
else
V_105 = V_106 = 0 ;
V_79 = F_59 ( V_3 -> V_30 )
| F_60 ( V_106 )
| F_61 ( V_105 )
| V_107
| V_108
| V_109 ;
V_81 = V_47 = NULL ;
for ( V_104 = 0 ; V_104 < V_65 ; V_104 += V_103 << V_105 ) {
V_103 = F_62 ( T_6 , ( V_65 - V_104 ) >> V_105 ,
V_110 ) ;
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 )
goto V_111;
V_12 -> V_21 . V_69 = V_102 + V_104 ;
V_12 -> V_21 . V_64 = V_101 + V_104 ;
V_12 -> V_21 . V_79 = V_79 ;
V_12 -> V_21 . V_78 = V_103 ;
if ( ! V_47 ) {
V_47 = V_12 ;
} else {
V_81 -> V_21 . V_72 = V_12 -> V_18 . V_20 ;
F_63 ( F_2 ( V_3 ) ,
V_81 -> V_18 . V_20 , sizeof( V_81 -> V_21 ) ,
V_22 ) ;
F_57 ( & V_12 -> V_11 ,
& V_47 -> V_23 ) ;
}
V_81 = V_12 ;
}
if ( V_16 & V_112 )
V_81 -> V_21 . V_79 |= V_113 ;
V_81 -> V_21 . V_72 = 0 ;
F_63 ( F_2 ( V_3 ) ,
V_81 -> V_18 . V_20 , sizeof( V_81 -> V_21 ) ,
V_22 ) ;
V_47 -> V_18 . V_16 = V_16 ;
V_47 -> V_65 = V_65 ;
return & V_47 -> V_18 ;
V_111:
F_16 ( V_8 , V_47 ) ;
return NULL ;
}
static struct V_59 *
F_64 ( struct V_2 * V_3 , struct V_114 * V_115 ,
unsigned int V_116 , enum V_117 V_118 ,
unsigned long V_16 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_28 * V_29 = V_3 -> V_30 ;
struct V_6 * V_81 ;
struct V_6 * V_47 ;
T_2 V_79 ;
T_4 V_119 ;
unsigned int V_120 ;
unsigned int V_121 ;
unsigned int V_15 ;
struct V_114 * V_122 ;
T_6 V_123 = 0 ;
F_12 ( F_1 ( V_3 ) , L_26 ) ;
if ( F_50 ( ! V_29 || ! V_116 ) )
return NULL ;
V_120 = V_29 -> V_120 ;
V_81 = V_47 = NULL ;
switch ( V_118 ) {
case V_124 :
V_79 = ( F_59 ( V_3 -> V_30 )
| F_60 ( V_120 )
| V_125
| V_108
| F_65 ( V_29 -> V_126 ) ) ;
V_119 = V_29 -> V_127 ;
F_66 (sgl, sg, sg_len, i) {
struct V_6 * V_12 ;
T_2 V_65 , V_128 , V_129 ;
V_129 = F_67 ( V_122 ) ;
V_65 = F_68 ( V_122 ) ;
V_121 = 2 ;
if ( F_50 ( V_129 & 3 || V_65 & 3 ) )
V_121 = 0 ;
V_130:
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 ) {
F_28 ( F_1 ( V_3 ) ,
L_27 ) ;
goto V_111;
}
V_12 -> V_21 . V_69 = V_129 ;
V_12 -> V_21 . V_64 = V_119 ;
V_12 -> V_21 . V_79 = V_79 | F_61 ( V_121 ) ;
if ( ( V_65 >> V_121 ) > V_110 ) {
V_128 = V_110 << V_121 ;
V_129 += V_128 ;
V_65 -= V_128 ;
} else {
V_128 = V_65 ;
V_65 = 0 ;
}
V_12 -> V_21 . V_78 = V_128 >> V_121 ;
if ( ! V_47 ) {
V_47 = V_12 ;
} else {
V_81 -> V_21 . V_72 = V_12 -> V_18 . V_20 ;
F_63 ( F_2 ( V_3 ) ,
V_81 -> V_18 . V_20 ,
sizeof( V_81 -> V_21 ) ,
V_22 ) ;
F_57 ( & V_12 -> V_11 ,
& V_47 -> V_23 ) ;
}
V_81 = V_12 ;
V_123 += V_128 ;
if ( V_65 )
goto V_130;
}
break;
case V_131 :
V_79 = ( F_59 ( V_3 -> V_30 )
| F_61 ( V_120 )
| V_107
| V_132
| F_65 ( V_29 -> V_126 ) ) ;
V_119 = V_29 -> V_133 ;
F_66 (sgl, sg, sg_len, i) {
struct V_6 * V_12 ;
T_2 V_65 , V_128 , V_129 ;
V_129 = F_67 ( V_122 ) ;
V_65 = F_68 ( V_122 ) ;
V_121 = 2 ;
if ( F_50 ( V_129 & 3 || V_65 & 3 ) )
V_121 = 0 ;
V_134:
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 ) {
F_28 ( F_1 ( V_3 ) ,
L_27 ) ;
goto V_111;
}
V_12 -> V_21 . V_69 = V_119 ;
V_12 -> V_21 . V_64 = V_129 ;
V_12 -> V_21 . V_79 = V_79 | F_60 ( V_121 ) ;
if ( ( V_65 >> V_120 ) > V_110 ) {
V_128 = V_110 << V_120 ;
V_129 += V_128 ;
V_65 -= V_128 ;
} else {
V_128 = V_65 ;
V_65 = 0 ;
}
V_12 -> V_21 . V_78 = V_128 >> V_120 ;
if ( ! V_47 ) {
V_47 = V_12 ;
} else {
V_81 -> V_21 . V_72 = V_12 -> V_18 . V_20 ;
F_63 ( F_2 ( V_3 ) ,
V_81 -> V_18 . V_20 ,
sizeof( V_81 -> V_21 ) ,
V_22 ) ;
F_57 ( & V_12 -> V_11 ,
& V_47 -> V_23 ) ;
}
V_81 = V_12 ;
V_123 += V_128 ;
if ( V_65 )
goto V_134;
}
break;
default:
return NULL ;
}
if ( V_16 & V_112 )
V_81 -> V_21 . V_79 |= V_113 ;
V_81 -> V_21 . V_72 = 0 ;
F_63 ( F_2 ( V_3 ) ,
V_81 -> V_18 . V_20 , sizeof( V_81 -> V_21 ) ,
V_22 ) ;
V_47 -> V_65 = V_123 ;
return & V_47 -> V_18 ;
V_111:
F_16 ( V_8 , V_47 ) ;
return NULL ;
}
static int F_69 ( struct V_2 * V_3 , enum V_135 V_136 ,
unsigned long V_137 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_26 * V_27 = F_21 ( V_3 -> V_1 ) ;
struct V_6 * V_12 , * V_13 ;
unsigned long V_16 ;
T_2 V_33 ;
F_36 ( V_70 ) ;
if ( V_136 == V_138 ) {
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_33 = F_29 ( V_8 , V_41 ) ;
F_24 ( V_8 , V_41 , V_33 | V_139 ) ;
while ( ! ( F_29 ( V_8 , V_41 ) & V_140 ) )
F_38 () ;
V_8 -> V_141 = true ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
} else if ( V_136 == V_142 ) {
if ( ! V_8 -> V_141 )
return 0 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_33 = F_29 ( V_8 , V_41 ) ;
F_24 ( V_8 , V_41 , V_33 & ~ V_139 ) ;
V_8 -> V_141 = false ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
} else if ( V_136 == V_143 ) {
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_37 ( V_27 , V_48 , V_8 -> V_45 ) ;
while ( F_27 ( V_27 , V_48 ) & V_8 -> V_45 )
F_38 () ;
V_8 -> V_141 = false ;
F_17 ( & V_8 -> V_71 , & V_70 ) ;
F_17 ( & V_8 -> V_9 , & V_70 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node)
F_30 ( V_8 , V_12 , false ) ;
} else
return - V_144 ;
return 0 ;
}
static enum V_145
F_70 ( struct V_2 * V_3 ,
T_1 V_25 ,
struct V_146 * V_147 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
T_1 V_148 ;
T_1 V_149 ;
int V_14 ;
V_149 = V_8 -> V_60 ;
V_148 = V_3 -> V_25 ;
V_14 = F_71 ( V_25 , V_149 , V_148 ) ;
if ( V_14 != V_150 ) {
F_40 ( F_21 ( V_3 -> V_1 ) , V_8 ) ;
V_149 = V_8 -> V_60 ;
V_148 = V_3 -> V_25 ;
V_14 = F_71 ( V_25 , V_149 , V_148 ) ;
}
if ( V_14 != V_150 )
F_72 ( V_147 , V_149 , V_148 ,
F_3 ( V_8 ) -> V_65 ) ;
else
F_72 ( V_147 , V_149 , V_148 , 0 ) ;
if ( V_8 -> V_141 )
return V_151 ;
return V_14 ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
if ( ! F_39 ( & V_8 -> V_71 ) )
F_40 ( F_21 ( V_3 -> V_1 ) , V_8 ) ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_26 * V_27 = F_21 ( V_3 -> V_1 ) ;
struct V_6 * V_12 ;
int V_15 ;
unsigned long V_16 ;
F_12 ( F_1 ( V_3 ) , L_28 ) ;
if ( F_27 ( V_27 , V_48 ) & V_8 -> V_45 ) {
F_10 ( F_1 ( V_3 ) , L_29 ) ;
return - V_152 ;
}
V_8 -> V_60 = V_3 -> V_25 = 1 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_15 = V_8 -> V_153 ;
while ( V_8 -> V_153 < V_154 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
V_12 = F_75 ( sizeof( struct V_6 ) , V_155 ) ;
if ( ! V_12 ) {
F_76 ( F_1 ( V_3 ) ,
L_30 , V_15 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
break;
}
F_77 ( & V_12 -> V_23 ) ;
F_78 ( & V_12 -> V_18 , V_3 ) ;
V_12 -> V_18 . V_156 = F_55 ;
V_12 -> V_18 . V_16 = V_157 ;
V_12 -> V_18 . V_20 = F_79 ( F_2 ( V_3 ) , & V_12 -> V_21 ,
sizeof( V_12 -> V_21 ) , V_22 ) ;
F_16 ( V_8 , V_12 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_15 = ++ V_8 -> V_153 ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_10 ( F_1 ( V_3 ) ,
L_31 , V_15 ) ;
return V_15 ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_26 * V_27 = F_21 ( V_3 -> V_1 ) ;
struct V_6 * V_12 , * V_13 ;
unsigned long V_16 ;
F_36 ( V_70 ) ;
F_10 ( F_1 ( V_3 ) , L_32 ,
V_8 -> V_153 ) ;
F_23 ( ! F_39 ( & V_8 -> V_9 ) ) ;
F_23 ( ! F_39 ( & V_8 -> V_71 ) ) ;
F_23 ( F_27 ( F_21 ( V_3 -> V_1 ) , V_48 ) & V_8 -> V_45 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_17 ( & V_8 -> V_24 , & V_70 ) ;
V_8 -> V_153 = 0 ;
V_8 -> V_35 = false ;
F_37 ( V_27 , V_43 . V_44 , V_8 -> V_45 ) ;
F_37 ( V_27 , V_43 . V_46 , V_8 -> V_45 ) ;
F_37 ( V_27 , V_43 . ERROR , V_8 -> V_45 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node) {
F_12 ( F_1 ( V_3 ) , L_33 , V_12 ) ;
F_33 ( F_2 ( V_3 ) , V_12 -> V_18 . V_20 ,
sizeof( V_12 -> V_21 ) , V_22 ) ;
F_81 ( V_12 ) ;
}
F_12 ( F_1 ( V_3 ) , L_34 ) ;
}
int F_82 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_26 * V_27 = F_21 ( V_8 -> V_3 . V_1 ) ;
unsigned long V_16 ;
if ( ! F_52 ( V_90 , & V_8 -> V_16 ) ) {
F_28 ( F_1 ( & V_8 -> V_3 ) , L_35 ) ;
return - V_158 ;
}
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( F_27 ( V_27 , V_48 ) & V_8 -> V_45 ) {
F_28 ( F_1 ( & V_8 -> V_3 ) ,
L_5 ) ;
F_28 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ,
F_29 ( V_8 , V_49 ) ,
F_29 ( V_8 , V_50 ) ,
F_29 ( V_8 , V_51 ) ,
F_29 ( V_8 , V_52 ) ,
F_29 ( V_8 , V_53 ) ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
return - V_159 ;
}
F_41 ( V_27 , V_74 . V_46 , V_8 -> V_45 ) ;
F_41 ( V_27 , V_74 . ERROR , V_8 -> V_45 ) ;
F_41 ( V_27 , V_74 . V_44 , V_8 -> V_45 ) ;
F_24 ( V_8 , V_51 , V_8 -> V_84 -> V_12 [ 0 ] -> V_18 . V_20 ) ;
F_24 ( V_8 , V_53 , V_54 | V_55 ) ;
F_24 ( V_8 , V_52 , 0 ) ;
F_25 ( V_27 , V_48 , V_8 -> V_45 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
return 0 ;
}
void F_83 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_26 * V_27 = F_21 ( V_8 -> V_3 . V_1 ) ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_37 ( V_27 , V_48 , V_8 -> V_45 ) ;
while ( F_27 ( V_27 , V_48 ) & V_8 -> V_45 )
F_38 () ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
struct V_160 * F_84 ( struct V_2 * V_3 ,
T_4 V_161 , T_6 V_162 , T_6 V_163 ,
enum V_117 V_118 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_160 * V_84 ;
struct V_160 * V_164 = NULL ;
struct V_6 * V_12 ;
struct V_6 * V_165 = NULL ;
struct V_28 * V_29 = V_3 -> V_30 ;
unsigned long V_166 ;
unsigned int V_120 ;
unsigned int V_87 ;
unsigned int V_15 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( ! F_39 ( & V_8 -> V_71 ) || ! F_39 ( & V_8 -> V_9 ) ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_10 ( F_1 ( & V_8 -> V_3 ) ,
L_36 ) ;
return F_85 ( - V_159 ) ;
}
V_166 = F_86 ( V_90 , & V_8 -> V_16 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
if ( V_166 ) {
F_10 ( F_1 ( & V_8 -> V_3 ) ,
L_37 ) ;
return F_85 ( - V_159 ) ;
}
V_164 = F_85 ( - V_167 ) ;
V_120 = V_29 -> V_120 ;
V_87 = V_162 / V_163 ;
if ( V_163 > ( V_110 << V_120 ) )
goto V_168;
if ( F_50 ( V_163 & ( ( 1 << V_120 ) - 1 ) ) )
goto V_168;
if ( F_50 ( V_161 & ( ( 1 << V_120 ) - 1 ) ) )
goto V_168;
if ( F_50 ( ! ( V_118 & ( V_124 | V_131 ) ) ) )
goto V_168;
V_164 = F_85 ( - V_169 ) ;
if ( V_87 > V_154 )
goto V_168;
V_84 = F_75 ( sizeof( struct V_160 ) , V_155 ) ;
if ( ! V_84 )
goto V_168;
V_84 -> V_12 = F_75 ( sizeof( struct V_6 * ) * V_87 , V_155 ) ;
if ( ! V_84 -> V_12 )
goto V_170;
for ( V_15 = 0 ; V_15 < V_87 ; V_15 ++ ) {
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 )
goto V_171;
switch ( V_118 ) {
case V_124 :
V_12 -> V_21 . V_64 = V_29 -> V_127 ;
V_12 -> V_21 . V_69 = V_161 + ( V_163 * V_15 ) ;
V_12 -> V_21 . V_79 = ( F_59 ( V_3 -> V_30 )
| F_60 ( V_120 )
| F_61 ( V_120 )
| V_125
| V_108
| F_65 ( V_29 -> V_126 )
| V_113 ) ;
break;
case V_131 :
V_12 -> V_21 . V_64 = V_161 + ( V_163 * V_15 ) ;
V_12 -> V_21 . V_69 = V_29 -> V_133 ;
V_12 -> V_21 . V_79 = ( F_59 ( V_3 -> V_30 )
| F_61 ( V_120 )
| F_60 ( V_120 )
| V_107
| V_132
| F_65 ( V_29 -> V_126 )
| V_113 ) ;
break;
default:
break;
}
V_12 -> V_21 . V_78 = ( V_163 >> V_120 ) ;
V_84 -> V_12 [ V_15 ] = V_12 ;
if ( V_165 ) {
V_165 -> V_21 . V_72 = V_12 -> V_18 . V_20 ;
F_63 ( F_2 ( V_3 ) ,
V_165 -> V_18 . V_20 , sizeof( V_165 -> V_21 ) ,
V_22 ) ;
}
V_165 = V_12 ;
}
V_165 -> V_21 . V_72 = V_84 -> V_12 [ 0 ] -> V_18 . V_20 ;
F_63 ( F_2 ( V_3 ) , V_165 -> V_18 . V_20 ,
sizeof( V_165 -> V_21 ) , V_22 ) ;
F_10 ( F_1 ( & V_8 -> V_3 ) , L_38
L_39 , V_161 , V_162 ,
V_163 , V_87 ) ;
V_84 -> V_87 = V_87 ;
V_8 -> V_84 = V_84 ;
return V_84 ;
V_171:
while ( V_15 -- )
F_16 ( V_8 , V_84 -> V_12 [ V_15 ] ) ;
V_170:
F_81 ( V_84 ) ;
V_168:
F_87 ( V_90 , & V_8 -> V_16 ) ;
return (struct V_160 * ) V_164 ;
}
void F_88 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_26 * V_27 = F_21 ( V_8 -> V_3 . V_1 ) ;
struct V_160 * V_84 = V_8 -> V_84 ;
int V_15 ;
unsigned long V_16 ;
F_10 ( F_1 ( & V_8 -> V_3 ) , L_40 ) ;
if ( ! V_84 )
return;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_37 ( V_27 , V_48 , V_8 -> V_45 ) ;
while ( F_27 ( V_27 , V_48 ) & V_8 -> V_45 )
F_38 () ;
F_41 ( V_27 , V_74 . V_46 , V_8 -> V_45 ) ;
F_41 ( V_27 , V_74 . ERROR , V_8 -> V_45 ) ;
F_41 ( V_27 , V_74 . V_44 , V_8 -> V_45 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
for ( V_15 = 0 ; V_15 < V_84 -> V_87 ; V_15 ++ )
F_16 ( V_8 , V_84 -> V_12 [ V_15 ] ) ;
F_81 ( V_84 -> V_12 ) ;
F_81 ( V_84 ) ;
F_87 ( V_90 , & V_8 -> V_16 ) ;
}
static void F_89 ( struct V_26 * V_27 )
{
int V_15 ;
F_41 ( V_27 , V_172 , 0 ) ;
F_37 ( V_27 , V_43 . V_44 , V_27 -> V_91 ) ;
F_37 ( V_27 , V_43 . V_46 , V_27 -> V_91 ) ;
F_37 ( V_27 , V_43 . V_96 , V_27 -> V_91 ) ;
F_37 ( V_27 , V_43 . V_97 , V_27 -> V_91 ) ;
F_37 ( V_27 , V_43 . ERROR , V_27 -> V_91 ) ;
while ( F_27 ( V_27 , V_172 ) & V_173 )
F_38 () ;
for ( V_15 = 0 ; V_15 < V_27 -> V_37 . V_89 ; V_15 ++ )
V_27 -> V_3 [ V_15 ] . V_35 = false ;
}
static int T_7 F_90 ( struct V_174 * V_175 )
{
struct V_176 * V_177 ;
struct V_178 * V_179 ;
struct V_26 * V_27 ;
T_6 V_180 ;
int V_92 ;
int V_181 ;
int V_15 ;
V_177 = V_175 -> V_4 . V_182 ;
if ( ! V_177 || V_177 -> V_183 > V_184 )
return - V_167 ;
V_179 = F_91 ( V_175 , V_185 , 0 ) ;
if ( ! V_179 )
return - V_167 ;
V_92 = F_92 ( V_175 , 0 ) ;
if ( V_92 < 0 )
return V_92 ;
V_180 = sizeof( struct V_26 ) ;
V_180 += V_177 -> V_183 * sizeof( struct V_7 ) ;
V_27 = F_75 ( V_180 , V_155 ) ;
if ( ! V_27 )
return - V_169 ;
if ( ! F_93 ( V_179 -> V_186 , V_187 , V_175 -> V_4 . V_188 -> V_189 ) ) {
V_181 = - V_159 ;
goto V_190;
}
V_27 -> V_191 = F_94 ( V_179 -> V_186 , V_187 ) ;
if ( ! V_27 -> V_191 ) {
V_181 = - V_169 ;
goto V_192;
}
V_27 -> V_193 = F_95 ( & V_175 -> V_4 , L_41 ) ;
if ( F_96 ( V_27 -> V_193 ) ) {
V_181 = F_97 ( V_27 -> V_193 ) ;
goto V_194;
}
F_98 ( V_27 -> V_193 ) ;
F_89 ( V_27 ) ;
V_181 = F_99 ( V_92 , F_53 , 0 , L_42 , V_27 ) ;
if ( V_181 )
goto V_195;
F_100 ( V_175 , V_27 ) ;
F_101 ( & V_27 -> V_98 , F_51 , ( unsigned long ) V_27 ) ;
V_27 -> V_91 = ( 1 << V_177 -> V_183 ) - 1 ;
F_77 ( & V_27 -> V_37 . V_196 ) ;
for ( V_15 = 0 ; V_15 < V_177 -> V_183 ; V_15 ++ ) {
struct V_7 * V_8 = & V_27 -> V_3 [ V_15 ] ;
V_8 -> V_3 . V_1 = & V_27 -> V_37 ;
V_8 -> V_3 . V_25 = V_8 -> V_60 = 1 ;
if ( V_177 -> V_197 == V_198 )
F_57 ( & V_8 -> V_3 . V_199 ,
& V_27 -> V_37 . V_196 ) ;
else
F_18 ( & V_8 -> V_3 . V_199 , & V_27 -> V_37 . V_196 ) ;
if ( V_177 -> V_200 == V_201 )
V_8 -> V_34 = 7 - V_15 ;
else
V_8 -> V_34 = V_15 ;
V_8 -> V_202 = & F_102 ( V_27 ) -> V_203 [ V_15 ] ;
F_103 ( & V_8 -> V_17 ) ;
V_8 -> V_45 = 1 << V_15 ;
F_77 ( & V_8 -> V_9 ) ;
F_77 ( & V_8 -> V_71 ) ;
F_77 ( & V_8 -> V_24 ) ;
F_37 ( V_27 , V_48 , V_8 -> V_45 ) ;
}
F_41 ( V_27 , V_74 . V_44 , V_27 -> V_91 ) ;
F_41 ( V_27 , V_74 . V_46 , V_27 -> V_91 ) ;
F_41 ( V_27 , V_74 . V_96 , V_27 -> V_91 ) ;
F_41 ( V_27 , V_74 . V_97 , V_27 -> V_91 ) ;
F_41 ( V_27 , V_74 . ERROR , V_27 -> V_91 ) ;
F_37 ( V_27 , V_43 . V_44 , V_27 -> V_91 ) ;
F_37 ( V_27 , V_43 . V_46 , V_27 -> V_91 ) ;
F_37 ( V_27 , V_43 . V_96 , V_27 -> V_91 ) ;
F_37 ( V_27 , V_43 . V_97 , V_27 -> V_91 ) ;
F_37 ( V_27 , V_43 . ERROR , V_27 -> V_91 ) ;
F_104 ( V_204 , V_27 -> V_37 . V_205 ) ;
F_104 ( V_206 , V_27 -> V_37 . V_205 ) ;
if ( V_177 -> V_207 )
F_104 ( V_208 , V_27 -> V_37 . V_205 ) ;
V_27 -> V_37 . V_4 = & V_175 -> V_4 ;
V_27 -> V_37 . V_209 = F_74 ;
V_27 -> V_37 . V_210 = F_80 ;
V_27 -> V_37 . V_211 = F_58 ;
V_27 -> V_37 . V_212 = F_64 ;
V_27 -> V_37 . V_213 = F_69 ;
V_27 -> V_37 . V_214 = F_70 ;
V_27 -> V_37 . V_215 = F_73 ;
F_41 ( V_27 , V_172 , V_173 ) ;
F_105 ( V_216 L_43 ,
F_106 ( & V_175 -> V_4 ) , V_177 -> V_183 ) ;
F_107 ( & V_27 -> V_37 ) ;
return 0 ;
V_195:
F_108 ( V_27 -> V_193 ) ;
F_109 ( V_27 -> V_193 ) ;
V_194:
F_110 ( V_27 -> V_191 ) ;
V_27 -> V_191 = NULL ;
V_192:
F_111 ( V_179 ) ;
V_190:
F_81 ( V_27 ) ;
return V_181 ;
}
static int T_8 F_112 ( struct V_174 * V_175 )
{
struct V_26 * V_27 = F_113 ( V_175 ) ;
struct V_7 * V_8 , * V_217 ;
struct V_178 * V_179 ;
F_89 ( V_27 ) ;
F_114 ( & V_27 -> V_37 ) ;
F_115 ( F_92 ( V_175 , 0 ) , V_27 ) ;
F_116 ( & V_27 -> V_98 ) ;
F_7 (dwc, _dwc, &dw->dma.channels,
chan.device_node) {
F_9 ( & V_8 -> V_3 . V_199 ) ;
F_37 ( V_27 , V_48 , V_8 -> V_45 ) ;
}
F_108 ( V_27 -> V_193 ) ;
F_109 ( V_27 -> V_193 ) ;
F_110 ( V_27 -> V_191 ) ;
V_27 -> V_191 = NULL ;
V_179 = F_91 ( V_175 , V_185 , 0 ) ;
F_117 ( V_179 -> V_186 , V_187 ) ;
F_81 ( V_27 ) ;
return 0 ;
}
static void F_118 ( struct V_174 * V_175 )
{
struct V_26 * V_27 = F_113 ( V_175 ) ;
F_89 ( F_113 ( V_175 ) ) ;
F_108 ( V_27 -> V_193 ) ;
}
static int F_119 ( struct V_1 * V_4 )
{
struct V_174 * V_175 = F_120 ( V_4 ) ;
struct V_26 * V_27 = F_113 ( V_175 ) ;
F_89 ( F_113 ( V_175 ) ) ;
F_108 ( V_27 -> V_193 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_4 )
{
struct V_174 * V_175 = F_120 ( V_4 ) ;
struct V_26 * V_27 = F_113 ( V_175 ) ;
F_98 ( V_27 -> V_193 ) ;
F_41 ( V_27 , V_172 , V_173 ) ;
return 0 ;
}
static int T_7 F_122 ( void )
{
return F_123 ( & V_218 , F_90 ) ;
}
static void T_8 F_124 ( void )
{
F_125 ( & V_218 ) ;
}
