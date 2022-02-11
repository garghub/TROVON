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
static void F_25 ( struct V_7 * V_8 , struct V_6 * V_45 )
{
struct V_25 * V_26 = F_20 ( V_8 -> V_3 . V_1 ) ;
if ( F_26 ( V_26 , V_46 ) & V_8 -> V_44 ) {
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_5 ) ;
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ,
F_28 ( V_8 , V_47 ) ,
F_28 ( V_8 , V_48 ) ,
F_28 ( V_8 , V_49 ) ,
F_28 ( V_8 , V_50 ) ,
F_28 ( V_8 , V_51 ) ) ;
return;
}
F_19 ( V_8 ) ;
F_23 ( V_8 , V_49 , V_45 -> V_18 . V_20 ) ;
F_23 ( V_8 , V_51 ,
V_52 | V_53 ) ;
F_23 ( V_8 , V_50 , 0 ) ;
F_24 ( V_26 , V_46 , V_8 -> V_44 ) ;
}
static void
F_29 ( struct V_7 * V_8 , struct V_6 * V_12 ,
bool V_54 )
{
T_2 V_55 = NULL ;
void * V_56 = NULL ;
struct V_57 * V_18 = & V_12 -> V_18 ;
struct V_6 * V_19 ;
unsigned long V_16 ;
F_12 ( F_1 ( & V_8 -> V_3 ) , L_7 , V_18 -> V_58 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_30 ( V_18 ) ;
if ( V_54 ) {
V_55 = V_18 -> V_55 ;
V_56 = V_18 -> V_59 ;
}
F_13 ( V_8 , V_12 ) ;
F_14 (child, &desc->tx_list, desc_node)
F_31 ( & V_19 -> V_18 ) ;
F_31 ( & V_12 -> V_18 ) ;
F_17 ( & V_12 -> V_23 , & V_8 -> V_24 ) ;
F_32 ( & V_12 -> V_11 , & V_8 -> V_24 ) ;
if ( ! V_8 -> V_3 . V_29 ) {
struct V_1 * V_5 = F_2 ( & V_8 -> V_3 ) ;
if ( ! ( V_18 -> V_16 & V_60 ) ) {
if ( V_18 -> V_16 & V_61 )
F_33 ( V_5 , V_12 -> V_21 . V_62 ,
V_12 -> V_63 , V_64 ) ;
else
F_34 ( V_5 , V_12 -> V_21 . V_62 ,
V_12 -> V_63 , V_64 ) ;
}
if ( ! ( V_18 -> V_16 & V_65 ) ) {
if ( V_18 -> V_16 & V_66 )
F_33 ( V_5 , V_12 -> V_21 . V_67 ,
V_12 -> V_63 , V_22 ) ;
else
F_34 ( V_5 , V_12 -> V_21 . V_67 ,
V_12 -> V_63 , V_22 ) ;
}
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
if ( V_54 && V_55 )
V_55 ( V_56 ) ;
}
static void F_35 ( struct V_25 * V_26 , struct V_7 * V_8 )
{
struct V_6 * V_12 , * V_13 ;
F_36 ( V_68 ) ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( F_26 ( V_26 , V_46 ) & V_8 -> V_44 ) {
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_8 ) ;
F_37 ( V_26 , V_46 , V_8 -> V_44 ) ;
while ( F_26 ( V_26 , V_46 ) & V_8 -> V_44 )
F_38 () ;
}
F_17 ( & V_8 -> V_9 , & V_68 ) ;
if ( ! F_39 ( & V_8 -> V_69 ) ) {
F_32 ( V_8 -> V_69 . V_10 , & V_8 -> V_9 ) ;
F_25 ( V_8 , F_3 ( V_8 ) ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node)
F_29 ( V_8 , V_12 , true ) ;
}
static void F_40 ( struct V_25 * V_26 , struct V_7 * V_8 )
{
T_3 V_70 ;
struct V_6 * V_12 , * V_13 ;
struct V_6 * V_19 ;
T_1 V_71 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_70 = F_28 ( V_8 , V_49 ) ;
V_71 = F_26 ( V_26 , V_72 . V_43 ) ;
if ( V_71 & V_8 -> V_44 ) {
F_41 ( V_26 , V_73 . V_43 , V_8 -> V_44 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_35 ( V_26 , V_8 ) ;
return;
}
if ( F_39 ( & V_8 -> V_9 ) ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_12 ( F_1 ( & V_8 -> V_3 ) , L_9 , V_70 ) ;
F_7 (desc, _desc, &dwc->active_list, desc_node) {
if ( V_12 -> V_18 . V_20 == V_70 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
if ( V_12 -> V_21 . V_70 == V_70 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_14 (child, &desc->tx_list, desc_node)
if ( V_19 -> V_21 . V_70 == V_70 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_29 ( V_8 , V_12 , true ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
}
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_10 ) ;
F_37 ( V_26 , V_46 , V_8 -> V_44 ) ;
while ( F_26 ( V_26 , V_46 ) & V_8 -> V_44 )
F_38 () ;
if ( ! F_39 ( & V_8 -> V_69 ) ) {
F_32 ( V_8 -> V_69 . V_10 , & V_8 -> V_9 ) ;
F_25 ( V_8 , F_3 ( V_8 ) ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
static void F_42 ( struct V_7 * V_8 , struct V_74 * V_21 )
{
F_43 ( V_75 , F_1 ( & V_8 -> V_3 ) ,
L_11 ,
V_21 -> V_67 , V_21 -> V_62 , V_21 -> V_70 ,
V_21 -> V_76 , V_21 -> V_77 ) ;
}
static void F_44 ( struct V_25 * V_26 , struct V_7 * V_8 )
{
struct V_6 * V_78 ;
struct V_6 * V_19 ;
unsigned long V_16 ;
F_40 ( V_26 , V_8 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_78 = F_3 ( V_8 ) ;
F_45 ( & V_78 -> V_11 ) ;
F_32 ( V_8 -> V_69 . V_10 , V_8 -> V_9 . V_79 ) ;
F_41 ( V_26 , V_73 . ERROR , V_8 -> V_44 ) ;
if ( ! F_39 ( & V_8 -> V_9 ) )
F_25 ( V_8 , F_3 ( V_8 ) ) ;
F_43 ( V_75 , F_1 ( & V_8 -> V_3 ) ,
L_12 ) ;
F_43 ( V_75 , F_1 ( & V_8 -> V_3 ) ,
L_13 , V_78 -> V_18 . V_58 ) ;
F_42 ( V_8 , & V_78 -> V_21 ) ;
F_14 (child, &bad_desc->tx_list, desc_node)
F_42 ( V_8 , & V_19 -> V_21 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_29 ( V_8 , V_78 , true ) ;
}
inline T_3 F_46 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
return F_28 ( V_8 , V_47 ) ;
}
inline T_3 F_48 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
return F_28 ( V_8 , V_48 ) ;
}
static void F_49 ( struct V_25 * V_26 , struct V_7 * V_8 ,
T_1 V_80 , T_1 V_71 )
{
unsigned long V_16 ;
if ( V_8 -> V_44 ) {
void (* V_55)( void * V_56 );
void * V_59 ;
F_12 ( F_1 ( & V_8 -> V_3 ) , L_14 ,
F_28 ( V_8 , V_49 ) ) ;
V_55 = V_8 -> V_81 -> V_82 ;
V_59 = V_8 -> V_81 -> V_83 ;
if ( V_55 )
V_55 ( V_59 ) ;
}
if ( F_50 ( V_80 & V_8 -> V_44 ) ||
F_50 ( V_71 & V_8 -> V_44 ) ) {
int V_15 ;
F_27 ( F_1 ( & V_8 -> V_3 ) , L_15
L_16 ,
V_71 ? L_17 : L_18 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ,
F_28 ( V_8 , V_47 ) ,
F_28 ( V_8 , V_48 ) ,
F_28 ( V_8 , V_49 ) ,
F_28 ( V_8 , V_50 ) ,
F_28 ( V_8 , V_51 ) ) ;
F_37 ( V_26 , V_46 , V_8 -> V_44 ) ;
while ( F_26 ( V_26 , V_46 ) & V_8 -> V_44 )
F_38 () ;
F_23 ( V_8 , V_49 , 0 ) ;
F_23 ( V_8 , V_51 , 0 ) ;
F_23 ( V_8 , V_50 , 0 ) ;
F_41 ( V_26 , V_73 . ERROR , V_8 -> V_44 ) ;
F_41 ( V_26 , V_73 . V_43 , V_8 -> V_44 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_81 -> V_84 ; V_15 ++ )
F_42 ( V_8 , & V_8 -> V_81 -> V_12 [ V_15 ] -> V_21 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
}
static void F_51 ( unsigned long V_85 )
{
struct V_25 * V_26 = (struct V_25 * ) V_85 ;
struct V_7 * V_8 ;
T_1 V_71 ;
T_1 V_80 ;
int V_15 ;
V_71 = F_26 ( V_26 , V_72 . V_43 ) ;
V_80 = F_26 ( V_26 , V_72 . ERROR ) ;
F_12 ( V_26 -> V_36 . V_4 , L_19 , V_80 ) ;
for ( V_15 = 0 ; V_15 < V_26 -> V_36 . V_86 ; V_15 ++ ) {
V_8 = & V_26 -> V_3 [ V_15 ] ;
if ( F_52 ( V_87 , & V_8 -> V_16 ) )
F_49 ( V_26 , V_8 , V_80 , V_71 ) ;
else if ( V_80 & ( 1 << V_15 ) )
F_44 ( V_26 , V_8 ) ;
else if ( V_71 & ( 1 << V_15 ) )
F_40 ( V_26 , V_8 ) ;
}
F_24 ( V_26 , V_42 . V_43 , V_26 -> V_88 ) ;
F_24 ( V_26 , V_42 . ERROR , V_26 -> V_88 ) ;
}
static T_4 F_53 ( int V_89 , void * V_90 )
{
struct V_25 * V_26 = V_90 ;
T_1 V_91 ;
F_12 ( V_26 -> V_36 . V_4 , L_20 ,
F_26 ( V_26 , V_92 ) ) ;
F_37 ( V_26 , V_42 . V_43 , V_26 -> V_88 ) ;
F_37 ( V_26 , V_42 . ERROR , V_26 -> V_88 ) ;
V_91 = F_26 ( V_26 , V_92 ) ;
if ( V_91 ) {
F_27 ( V_26 -> V_36 . V_4 ,
L_21 ,
V_91 ) ;
F_37 ( V_26 , V_42 . V_43 , ( 1 << 8 ) - 1 ) ;
F_37 ( V_26 , V_42 . V_93 , ( 1 << 8 ) - 1 ) ;
F_37 ( V_26 , V_42 . V_94 , ( 1 << 8 ) - 1 ) ;
F_37 ( V_26 , V_42 . ERROR , ( 1 << 8 ) - 1 ) ;
}
F_54 ( & V_26 -> V_95 ) ;
return V_96 ;
}
static T_5 F_55 ( struct V_57 * V_97 )
{
struct V_6 * V_12 = F_56 ( V_97 ) ;
struct V_7 * V_8 = F_47 ( V_97 -> V_3 ) ;
T_5 V_58 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_58 = F_57 ( V_97 ) ;
if ( F_39 ( & V_8 -> V_9 ) ) {
F_12 ( F_1 ( V_97 -> V_3 ) , L_22 ,
V_12 -> V_18 . V_58 ) ;
F_58 ( & V_12 -> V_11 , & V_8 -> V_9 ) ;
F_25 ( V_8 , F_3 ( V_8 ) ) ;
} else {
F_12 ( F_1 ( V_97 -> V_3 ) , L_23 ,
V_12 -> V_18 . V_58 ) ;
F_58 ( & V_12 -> V_11 , & V_8 -> V_69 ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
return V_58 ;
}
static struct V_57 *
F_59 ( struct V_2 * V_3 , T_3 V_98 , T_3 V_99 ,
T_6 V_63 , unsigned long V_16 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_6 * V_12 ;
struct V_6 * V_45 ;
struct V_6 * V_79 ;
T_6 V_100 ;
T_6 V_101 ;
unsigned int V_102 ;
unsigned int V_103 ;
T_1 V_77 ;
F_12 ( F_1 ( V_3 ) , L_24 ,
V_98 , V_99 , V_63 , V_16 ) ;
if ( F_50 ( ! V_63 ) ) {
F_10 ( F_1 ( V_3 ) , L_25 ) ;
return NULL ;
}
if ( ! ( ( V_99 | V_98 | V_63 ) & 7 ) )
V_102 = V_103 = 3 ;
else if ( ! ( ( V_99 | V_98 | V_63 ) & 3 ) )
V_102 = V_103 = 2 ;
else if ( ! ( ( V_99 | V_98 | V_63 ) & 1 ) )
V_102 = V_103 = 1 ;
else
V_102 = V_103 = 0 ;
V_77 = F_60 ( V_3 )
| F_61 ( V_103 )
| F_62 ( V_102 )
| V_104
| V_105
| V_106 ;
V_79 = V_45 = NULL ;
for ( V_101 = 0 ; V_101 < V_63 ; V_101 += V_100 << V_102 ) {
V_100 = F_63 ( T_6 , ( V_63 - V_101 ) >> V_102 ,
V_107 ) ;
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 )
goto V_108;
V_12 -> V_21 . V_67 = V_99 + V_101 ;
V_12 -> V_21 . V_62 = V_98 + V_101 ;
V_12 -> V_21 . V_77 = V_77 ;
V_12 -> V_21 . V_76 = V_100 ;
if ( ! V_45 ) {
V_45 = V_12 ;
} else {
V_79 -> V_21 . V_70 = V_12 -> V_18 . V_20 ;
F_64 ( F_2 ( V_3 ) ,
V_79 -> V_18 . V_20 , sizeof( V_79 -> V_21 ) ,
V_22 ) ;
F_58 ( & V_12 -> V_11 ,
& V_45 -> V_23 ) ;
}
V_79 = V_12 ;
}
if ( V_16 & V_109 )
V_79 -> V_21 . V_77 |= V_110 ;
V_79 -> V_21 . V_70 = 0 ;
F_64 ( F_2 ( V_3 ) ,
V_79 -> V_18 . V_20 , sizeof( V_79 -> V_21 ) ,
V_22 ) ;
V_45 -> V_18 . V_16 = V_16 ;
V_45 -> V_63 = V_63 ;
return & V_45 -> V_18 ;
V_108:
F_16 ( V_8 , V_45 ) ;
return NULL ;
}
static struct V_57 *
F_65 ( struct V_2 * V_3 , struct V_111 * V_112 ,
unsigned int V_113 , enum V_114 V_115 ,
unsigned long V_16 , void * V_116 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_27 * V_28 = V_3 -> V_29 ;
struct V_117 * V_118 = & V_8 -> V_119 ;
struct V_6 * V_79 ;
struct V_6 * V_45 ;
T_1 V_77 ;
T_3 V_120 ;
unsigned int V_121 ;
unsigned int V_122 ;
unsigned int V_15 ;
struct V_111 * V_123 ;
T_6 V_124 = 0 ;
F_12 ( F_1 ( V_3 ) , L_26 ) ;
if ( F_50 ( ! V_28 || ! V_113 ) )
return NULL ;
V_79 = V_45 = NULL ;
switch ( V_115 ) {
case V_125 :
V_121 = F_66 ( V_118 -> V_126 ) ;
V_120 = V_118 -> V_127 ;
V_77 = ( F_60 ( V_3 )
| F_61 ( V_121 )
| V_128
| V_105 ) ;
V_77 |= V_118 -> V_129 ? F_67 ( V_130 ) :
F_67 ( V_131 ) ;
F_68 (sgl, sg, sg_len, i) {
struct V_6 * V_12 ;
T_1 V_63 , V_132 , V_133 ;
V_133 = F_69 ( V_123 ) ;
V_63 = F_70 ( V_123 ) ;
if ( ! ( ( V_133 | V_63 ) & 7 ) )
V_122 = 3 ;
else if ( ! ( ( V_133 | V_63 ) & 3 ) )
V_122 = 2 ;
else if ( ! ( ( V_133 | V_63 ) & 1 ) )
V_122 = 1 ;
else
V_122 = 0 ;
V_134:
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 ) {
F_27 ( F_1 ( V_3 ) ,
L_27 ) ;
goto V_108;
}
V_12 -> V_21 . V_67 = V_133 ;
V_12 -> V_21 . V_62 = V_120 ;
V_12 -> V_21 . V_77 = V_77 | F_62 ( V_122 ) ;
if ( ( V_63 >> V_122 ) > V_107 ) {
V_132 = V_107 << V_122 ;
V_133 += V_132 ;
V_63 -= V_132 ;
} else {
V_132 = V_63 ;
V_63 = 0 ;
}
V_12 -> V_21 . V_76 = V_132 >> V_122 ;
if ( ! V_45 ) {
V_45 = V_12 ;
} else {
V_79 -> V_21 . V_70 = V_12 -> V_18 . V_20 ;
F_64 ( F_2 ( V_3 ) ,
V_79 -> V_18 . V_20 ,
sizeof( V_79 -> V_21 ) ,
V_22 ) ;
F_58 ( & V_12 -> V_11 ,
& V_45 -> V_23 ) ;
}
V_79 = V_12 ;
V_124 += V_132 ;
if ( V_63 )
goto V_134;
}
break;
case V_135 :
V_121 = F_66 ( V_118 -> V_136 ) ;
V_120 = V_118 -> V_137 ;
V_77 = ( F_60 ( V_3 )
| F_62 ( V_121 )
| V_104
| V_138 ) ;
V_77 |= V_118 -> V_129 ? F_67 ( V_139 ) :
F_67 ( V_140 ) ;
F_68 (sgl, sg, sg_len, i) {
struct V_6 * V_12 ;
T_1 V_63 , V_132 , V_133 ;
V_133 = F_69 ( V_123 ) ;
V_63 = F_70 ( V_123 ) ;
if ( ! ( ( V_133 | V_63 ) & 7 ) )
V_122 = 3 ;
else if ( ! ( ( V_133 | V_63 ) & 3 ) )
V_122 = 2 ;
else if ( ! ( ( V_133 | V_63 ) & 1 ) )
V_122 = 1 ;
else
V_122 = 0 ;
V_141:
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 ) {
F_27 ( F_1 ( V_3 ) ,
L_27 ) ;
goto V_108;
}
V_12 -> V_21 . V_67 = V_120 ;
V_12 -> V_21 . V_62 = V_133 ;
V_12 -> V_21 . V_77 = V_77 | F_61 ( V_122 ) ;
if ( ( V_63 >> V_121 ) > V_107 ) {
V_132 = V_107 << V_121 ;
V_133 += V_132 ;
V_63 -= V_132 ;
} else {
V_132 = V_63 ;
V_63 = 0 ;
}
V_12 -> V_21 . V_76 = V_132 >> V_121 ;
if ( ! V_45 ) {
V_45 = V_12 ;
} else {
V_79 -> V_21 . V_70 = V_12 -> V_18 . V_20 ;
F_64 ( F_2 ( V_3 ) ,
V_79 -> V_18 . V_20 ,
sizeof( V_79 -> V_21 ) ,
V_22 ) ;
F_58 ( & V_12 -> V_11 ,
& V_45 -> V_23 ) ;
}
V_79 = V_12 ;
V_124 += V_132 ;
if ( V_63 )
goto V_141;
}
break;
default:
return NULL ;
}
if ( V_16 & V_109 )
V_79 -> V_21 . V_77 |= V_110 ;
V_79 -> V_21 . V_70 = 0 ;
F_64 ( F_2 ( V_3 ) ,
V_79 -> V_18 . V_20 , sizeof( V_79 -> V_21 ) ,
V_22 ) ;
V_45 -> V_63 = V_124 ;
return & V_45 -> V_18 ;
V_108:
F_16 ( V_8 , V_45 ) ;
return NULL ;
}
static inline void F_71 ( T_1 * V_142 )
{
if ( * V_142 > 1 )
* V_142 = F_72 ( * V_142 ) - 2 ;
else
* V_142 = 0 ;
}
static int
F_73 ( struct V_2 * V_3 , struct V_117 * V_118 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
if ( ! V_3 -> V_29 )
return - V_143 ;
memcpy ( & V_8 -> V_119 , V_118 , sizeof( * V_118 ) ) ;
F_71 ( & V_8 -> V_119 . V_144 ) ;
F_71 ( & V_8 -> V_119 . V_145 ) ;
return 0 ;
}
static int F_74 ( struct V_2 * V_3 , enum V_146 V_147 ,
unsigned long V_148 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_3 -> V_1 ) ;
struct V_6 * V_12 , * V_13 ;
unsigned long V_16 ;
T_1 V_32 ;
F_36 ( V_68 ) ;
if ( V_147 == V_149 ) {
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_32 = F_28 ( V_8 , V_40 ) ;
F_23 ( V_8 , V_40 , V_32 | V_150 ) ;
while ( ! ( F_28 ( V_8 , V_40 ) & V_151 ) )
F_38 () ;
V_8 -> V_152 = true ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
} else if ( V_147 == V_153 ) {
if ( ! V_8 -> V_152 )
return 0 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_32 = F_28 ( V_8 , V_40 ) ;
F_23 ( V_8 , V_40 , V_32 & ~ V_150 ) ;
V_8 -> V_152 = false ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
} else if ( V_147 == V_154 ) {
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_37 ( V_26 , V_46 , V_8 -> V_44 ) ;
while ( F_26 ( V_26 , V_46 ) & V_8 -> V_44 )
F_38 () ;
V_8 -> V_152 = false ;
F_17 ( & V_8 -> V_69 , & V_68 ) ;
F_17 ( & V_8 -> V_9 , & V_68 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node)
F_29 ( V_8 , V_12 , false ) ;
} else if ( V_147 == V_155 ) {
return F_73 ( V_3 , (struct V_117 * ) V_148 ) ;
} else {
return - V_156 ;
}
return 0 ;
}
static enum V_157
F_75 ( struct V_2 * V_3 ,
T_5 V_58 ,
struct V_158 * V_159 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
enum V_157 V_14 ;
V_14 = F_76 ( V_3 , V_58 , V_159 ) ;
if ( V_14 != V_160 ) {
F_40 ( F_20 ( V_3 -> V_1 ) , V_8 ) ;
V_14 = F_76 ( V_3 , V_58 , V_159 ) ;
}
if ( V_14 != V_160 )
F_77 ( V_159 , F_3 ( V_8 ) -> V_63 ) ;
if ( V_8 -> V_152 )
return V_161 ;
return V_14 ;
}
static void F_78 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
if ( ! F_39 ( & V_8 -> V_69 ) )
F_40 ( F_20 ( V_3 -> V_1 ) , V_8 ) ;
}
static int F_79 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_3 -> V_1 ) ;
struct V_6 * V_12 ;
int V_15 ;
unsigned long V_16 ;
F_12 ( F_1 ( V_3 ) , L_28 ) ;
if ( F_26 ( V_26 , V_46 ) & V_8 -> V_44 ) {
F_10 ( F_1 ( V_3 ) , L_29 ) ;
return - V_162 ;
}
F_80 ( V_3 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_15 = V_8 -> V_163 ;
while ( V_8 -> V_163 < V_164 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
V_12 = F_81 ( sizeof( struct V_6 ) , V_165 ) ;
if ( ! V_12 ) {
F_82 ( F_1 ( V_3 ) ,
L_30 , V_15 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
break;
}
F_83 ( & V_12 -> V_23 ) ;
F_84 ( & V_12 -> V_18 , V_3 ) ;
V_12 -> V_18 . V_166 = F_55 ;
V_12 -> V_18 . V_16 = V_167 ;
V_12 -> V_18 . V_20 = F_85 ( F_2 ( V_3 ) , & V_12 -> V_21 ,
sizeof( V_12 -> V_21 ) , V_22 ) ;
F_16 ( V_8 , V_12 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_15 = ++ V_8 -> V_163 ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_10 ( F_1 ( V_3 ) ,
L_31 , V_15 ) ;
return V_15 ;
}
static void F_86 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_3 -> V_1 ) ;
struct V_6 * V_12 , * V_13 ;
unsigned long V_16 ;
F_36 ( V_68 ) ;
F_10 ( F_1 ( V_3 ) , L_32 ,
V_8 -> V_163 ) ;
F_22 ( ! F_39 ( & V_8 -> V_9 ) ) ;
F_22 ( ! F_39 ( & V_8 -> V_69 ) ) ;
F_22 ( F_26 ( F_20 ( V_3 -> V_1 ) , V_46 ) & V_8 -> V_44 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_17 ( & V_8 -> V_24 , & V_68 ) ;
V_8 -> V_163 = 0 ;
V_8 -> V_34 = false ;
F_37 ( V_26 , V_42 . V_43 , V_8 -> V_44 ) ;
F_37 ( V_26 , V_42 . ERROR , V_8 -> V_44 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node) {
F_12 ( F_1 ( V_3 ) , L_33 , V_12 ) ;
F_33 ( F_2 ( V_3 ) , V_12 -> V_18 . V_20 ,
sizeof( V_12 -> V_21 ) , V_22 ) ;
F_87 ( V_12 ) ;
}
F_12 ( F_1 ( V_3 ) , L_34 ) ;
}
int F_88 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_8 -> V_3 . V_1 ) ;
unsigned long V_16 ;
if ( ! F_52 ( V_87 , & V_8 -> V_16 ) ) {
F_27 ( F_1 ( & V_8 -> V_3 ) , L_35 ) ;
return - V_168 ;
}
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( F_26 ( V_26 , V_46 ) & V_8 -> V_44 ) {
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_5 ) ;
F_27 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ,
F_28 ( V_8 , V_47 ) ,
F_28 ( V_8 , V_48 ) ,
F_28 ( V_8 , V_49 ) ,
F_28 ( V_8 , V_50 ) ,
F_28 ( V_8 , V_51 ) ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
return - V_169 ;
}
F_41 ( V_26 , V_73 . ERROR , V_8 -> V_44 ) ;
F_41 ( V_26 , V_73 . V_43 , V_8 -> V_44 ) ;
F_23 ( V_8 , V_49 , V_8 -> V_81 -> V_12 [ 0 ] -> V_18 . V_20 ) ;
F_23 ( V_8 , V_51 , V_52 | V_53 ) ;
F_23 ( V_8 , V_50 , 0 ) ;
F_24 ( V_26 , V_46 , V_8 -> V_44 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
return 0 ;
}
void F_89 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_8 -> V_3 . V_1 ) ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_37 ( V_26 , V_46 , V_8 -> V_44 ) ;
while ( F_26 ( V_26 , V_46 ) & V_8 -> V_44 )
F_38 () ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
struct V_170 * F_90 ( struct V_2 * V_3 ,
T_3 V_171 , T_6 V_172 , T_6 V_173 ,
enum V_114 V_115 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_117 * V_118 = & V_8 -> V_119 ;
struct V_170 * V_81 ;
struct V_170 * V_174 = NULL ;
struct V_6 * V_12 ;
struct V_6 * V_175 = NULL ;
unsigned long V_176 ;
unsigned int V_121 ;
unsigned int V_84 ;
unsigned int V_15 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( ! F_39 ( & V_8 -> V_69 ) || ! F_39 ( & V_8 -> V_9 ) ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_10 ( F_1 ( & V_8 -> V_3 ) ,
L_36 ) ;
return F_91 ( - V_169 ) ;
}
V_176 = F_92 ( V_87 , & V_8 -> V_16 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
if ( V_176 ) {
F_10 ( F_1 ( & V_8 -> V_3 ) ,
L_37 ) ;
return F_91 ( - V_169 ) ;
}
V_174 = F_91 ( - V_143 ) ;
if ( V_115 == V_125 )
V_121 = F_93 ( V_118 -> V_126 ) ;
else
V_121 = F_93 ( V_118 -> V_136 ) ;
V_84 = V_172 / V_173 ;
if ( V_173 > ( V_107 << V_121 ) )
goto V_177;
if ( F_50 ( V_173 & ( ( 1 << V_121 ) - 1 ) ) )
goto V_177;
if ( F_50 ( V_171 & ( ( 1 << V_121 ) - 1 ) ) )
goto V_177;
if ( F_50 ( ! ( V_115 & ( V_125 | V_135 ) ) ) )
goto V_177;
V_174 = F_91 ( - V_178 ) ;
if ( V_84 > V_164 )
goto V_177;
V_81 = F_81 ( sizeof( struct V_170 ) , V_165 ) ;
if ( ! V_81 )
goto V_177;
V_81 -> V_12 = F_81 ( sizeof( struct V_6 * ) * V_84 , V_165 ) ;
if ( ! V_81 -> V_12 )
goto V_179;
for ( V_15 = 0 ; V_15 < V_84 ; V_15 ++ ) {
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 )
goto V_180;
switch ( V_115 ) {
case V_125 :
V_12 -> V_21 . V_62 = V_118 -> V_127 ;
V_12 -> V_21 . V_67 = V_171 + ( V_173 * V_15 ) ;
V_12 -> V_21 . V_77 = ( F_60 ( V_3 )
| F_61 ( V_121 )
| F_62 ( V_121 )
| V_128
| V_105
| V_110 ) ;
V_12 -> V_21 . V_77 |= V_118 -> V_129 ?
F_67 ( V_130 ) :
F_67 ( V_131 ) ;
break;
case V_135 :
V_12 -> V_21 . V_62 = V_171 + ( V_173 * V_15 ) ;
V_12 -> V_21 . V_67 = V_118 -> V_137 ;
V_12 -> V_21 . V_77 = ( F_60 ( V_3 )
| F_62 ( V_121 )
| F_61 ( V_121 )
| V_104
| V_138
| V_110 ) ;
V_12 -> V_21 . V_77 |= V_118 -> V_129 ?
F_67 ( V_139 ) :
F_67 ( V_140 ) ;
break;
default:
break;
}
V_12 -> V_21 . V_76 = ( V_173 >> V_121 ) ;
V_81 -> V_12 [ V_15 ] = V_12 ;
if ( V_175 ) {
V_175 -> V_21 . V_70 = V_12 -> V_18 . V_20 ;
F_64 ( F_2 ( V_3 ) ,
V_175 -> V_18 . V_20 , sizeof( V_175 -> V_21 ) ,
V_22 ) ;
}
V_175 = V_12 ;
}
V_175 -> V_21 . V_70 = V_81 -> V_12 [ 0 ] -> V_18 . V_20 ;
F_64 ( F_2 ( V_3 ) , V_175 -> V_18 . V_20 ,
sizeof( V_175 -> V_21 ) , V_22 ) ;
F_10 ( F_1 ( & V_8 -> V_3 ) , L_38
L_39 , V_171 , V_172 ,
V_173 , V_84 ) ;
V_81 -> V_84 = V_84 ;
V_8 -> V_81 = V_81 ;
return V_81 ;
V_180:
while ( V_15 -- )
F_16 ( V_8 , V_81 -> V_12 [ V_15 ] ) ;
V_179:
F_87 ( V_81 ) ;
V_177:
F_94 ( V_87 , & V_8 -> V_16 ) ;
return (struct V_170 * ) V_174 ;
}
void F_95 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_47 ( V_3 ) ;
struct V_25 * V_26 = F_20 ( V_8 -> V_3 . V_1 ) ;
struct V_170 * V_81 = V_8 -> V_81 ;
int V_15 ;
unsigned long V_16 ;
F_10 ( F_1 ( & V_8 -> V_3 ) , L_40 ) ;
if ( ! V_81 )
return;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_37 ( V_26 , V_46 , V_8 -> V_44 ) ;
while ( F_26 ( V_26 , V_46 ) & V_8 -> V_44 )
F_38 () ;
F_41 ( V_26 , V_73 . ERROR , V_8 -> V_44 ) ;
F_41 ( V_26 , V_73 . V_43 , V_8 -> V_44 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
for ( V_15 = 0 ; V_15 < V_81 -> V_84 ; V_15 ++ )
F_16 ( V_8 , V_81 -> V_12 [ V_15 ] ) ;
F_87 ( V_81 -> V_12 ) ;
F_87 ( V_81 ) ;
F_94 ( V_87 , & V_8 -> V_16 ) ;
}
static void F_96 ( struct V_25 * V_26 )
{
int V_15 ;
F_41 ( V_26 , V_181 , 0 ) ;
F_37 ( V_26 , V_42 . V_43 , V_26 -> V_88 ) ;
F_37 ( V_26 , V_42 . V_93 , V_26 -> V_88 ) ;
F_37 ( V_26 , V_42 . V_94 , V_26 -> V_88 ) ;
F_37 ( V_26 , V_42 . ERROR , V_26 -> V_88 ) ;
while ( F_26 ( V_26 , V_181 ) & V_182 )
F_38 () ;
for ( V_15 = 0 ; V_15 < V_26 -> V_36 . V_86 ; V_15 ++ )
V_26 -> V_3 [ V_15 ] . V_34 = false ;
}
static int T_7 F_97 ( struct V_183 * V_184 )
{
struct V_185 * V_186 ;
struct V_187 * V_188 ;
struct V_25 * V_26 ;
T_6 V_189 ;
int V_89 ;
int V_190 ;
int V_15 ;
V_186 = F_98 ( & V_184 -> V_4 ) ;
if ( ! V_186 || V_186 -> V_191 > V_192 )
return - V_143 ;
V_188 = F_99 ( V_184 , V_193 , 0 ) ;
if ( ! V_188 )
return - V_143 ;
V_89 = F_100 ( V_184 , 0 ) ;
if ( V_89 < 0 )
return V_89 ;
V_189 = sizeof( struct V_25 ) ;
V_189 += V_186 -> V_191 * sizeof( struct V_7 ) ;
V_26 = F_81 ( V_189 , V_165 ) ;
if ( ! V_26 )
return - V_178 ;
if ( ! F_101 ( V_188 -> V_194 , V_195 , V_184 -> V_4 . V_196 -> V_197 ) ) {
V_190 = - V_169 ;
goto V_198;
}
V_26 -> V_199 = F_102 ( V_188 -> V_194 , V_195 ) ;
if ( ! V_26 -> V_199 ) {
V_190 = - V_178 ;
goto V_200;
}
V_26 -> V_201 = F_103 ( & V_184 -> V_4 , L_41 ) ;
if ( F_104 ( V_26 -> V_201 ) ) {
V_190 = F_105 ( V_26 -> V_201 ) ;
goto V_202;
}
F_106 ( V_26 -> V_201 ) ;
F_96 ( V_26 ) ;
V_190 = F_107 ( V_89 , F_53 , 0 , L_42 , V_26 ) ;
if ( V_190 )
goto V_203;
F_108 ( V_184 , V_26 ) ;
F_109 ( & V_26 -> V_95 , F_51 , ( unsigned long ) V_26 ) ;
V_26 -> V_88 = ( 1 << V_186 -> V_191 ) - 1 ;
F_83 ( & V_26 -> V_36 . V_204 ) ;
for ( V_15 = 0 ; V_15 < V_186 -> V_191 ; V_15 ++ ) {
struct V_7 * V_8 = & V_26 -> V_3 [ V_15 ] ;
V_8 -> V_3 . V_1 = & V_26 -> V_36 ;
F_80 ( & V_8 -> V_3 ) ;
if ( V_186 -> V_205 == V_206 )
F_58 ( & V_8 -> V_3 . V_207 ,
& V_26 -> V_36 . V_204 ) ;
else
F_18 ( & V_8 -> V_3 . V_207 , & V_26 -> V_36 . V_204 ) ;
if ( V_186 -> V_208 == V_209 )
V_8 -> V_33 = V_186 -> V_191 - V_15 - 1 ;
else
V_8 -> V_33 = V_15 ;
V_8 -> V_210 = & F_110 ( V_26 ) -> V_211 [ V_15 ] ;
F_111 ( & V_8 -> V_17 ) ;
V_8 -> V_44 = 1 << V_15 ;
F_83 ( & V_8 -> V_9 ) ;
F_83 ( & V_8 -> V_69 ) ;
F_83 ( & V_8 -> V_24 ) ;
F_37 ( V_26 , V_46 , V_8 -> V_44 ) ;
}
F_41 ( V_26 , V_73 . V_43 , V_26 -> V_88 ) ;
F_41 ( V_26 , V_73 . V_93 , V_26 -> V_88 ) ;
F_41 ( V_26 , V_73 . V_94 , V_26 -> V_88 ) ;
F_41 ( V_26 , V_73 . ERROR , V_26 -> V_88 ) ;
F_37 ( V_26 , V_42 . V_43 , V_26 -> V_88 ) ;
F_37 ( V_26 , V_42 . V_93 , V_26 -> V_88 ) ;
F_37 ( V_26 , V_42 . V_94 , V_26 -> V_88 ) ;
F_37 ( V_26 , V_42 . ERROR , V_26 -> V_88 ) ;
F_112 ( V_212 , V_26 -> V_36 . V_213 ) ;
F_112 ( V_214 , V_26 -> V_36 . V_213 ) ;
if ( V_186 -> V_215 )
F_112 ( V_216 , V_26 -> V_36 . V_213 ) ;
V_26 -> V_36 . V_4 = & V_184 -> V_4 ;
V_26 -> V_36 . V_217 = F_79 ;
V_26 -> V_36 . V_218 = F_86 ;
V_26 -> V_36 . V_219 = F_59 ;
V_26 -> V_36 . V_220 = F_65 ;
V_26 -> V_36 . V_221 = F_74 ;
V_26 -> V_36 . V_222 = F_75 ;
V_26 -> V_36 . V_223 = F_78 ;
F_41 ( V_26 , V_181 , V_182 ) ;
F_113 ( V_224 L_43 ,
F_114 ( & V_184 -> V_4 ) , V_186 -> V_191 ) ;
F_115 ( & V_26 -> V_36 ) ;
return 0 ;
V_203:
F_116 ( V_26 -> V_201 ) ;
F_117 ( V_26 -> V_201 ) ;
V_202:
F_118 ( V_26 -> V_199 ) ;
V_26 -> V_199 = NULL ;
V_200:
F_119 ( V_188 ) ;
V_198:
F_87 ( V_26 ) ;
return V_190 ;
}
static int T_8 F_120 ( struct V_183 * V_184 )
{
struct V_25 * V_26 = F_121 ( V_184 ) ;
struct V_7 * V_8 , * V_225 ;
struct V_187 * V_188 ;
F_96 ( V_26 ) ;
F_122 ( & V_26 -> V_36 ) ;
F_123 ( F_100 ( V_184 , 0 ) , V_26 ) ;
F_124 ( & V_26 -> V_95 ) ;
F_7 (dwc, _dwc, &dw->dma.channels,
chan.device_node) {
F_9 ( & V_8 -> V_3 . V_207 ) ;
F_37 ( V_26 , V_46 , V_8 -> V_44 ) ;
}
F_116 ( V_26 -> V_201 ) ;
F_117 ( V_26 -> V_201 ) ;
F_118 ( V_26 -> V_199 ) ;
V_26 -> V_199 = NULL ;
V_188 = F_99 ( V_184 , V_193 , 0 ) ;
F_125 ( V_188 -> V_194 , V_195 ) ;
F_87 ( V_26 ) ;
return 0 ;
}
static void F_126 ( struct V_183 * V_184 )
{
struct V_25 * V_26 = F_121 ( V_184 ) ;
F_96 ( F_121 ( V_184 ) ) ;
F_116 ( V_26 -> V_201 ) ;
}
static int F_127 ( struct V_1 * V_4 )
{
struct V_183 * V_184 = F_128 ( V_4 ) ;
struct V_25 * V_26 = F_121 ( V_184 ) ;
F_96 ( F_121 ( V_184 ) ) ;
F_116 ( V_26 -> V_201 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_4 )
{
struct V_183 * V_184 = F_128 ( V_4 ) ;
struct V_25 * V_26 = F_121 ( V_184 ) ;
F_106 ( V_26 -> V_201 ) ;
F_41 ( V_26 , V_181 , V_182 ) ;
return 0 ;
}
static int T_7 F_130 ( void )
{
return F_131 ( & V_226 , F_97 ) ;
}
static void T_8 F_132 ( void )
{
F_133 ( & V_226 ) ;
}
