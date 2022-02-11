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
static void F_20 ( struct V_7 * V_8 , struct V_6 * V_26 )
{
struct V_27 * V_28 = F_21 ( V_8 -> V_3 . V_1 ) ;
if ( F_22 ( V_28 , V_29 ) & V_8 -> V_30 ) {
F_23 ( F_1 ( & V_8 -> V_3 ) ,
L_5 ) ;
F_23 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ,
F_24 ( V_8 , V_31 ) ,
F_24 ( V_8 , V_32 ) ,
F_24 ( V_8 , V_33 ) ,
F_24 ( V_8 , V_34 ) ,
F_24 ( V_8 , V_35 ) ) ;
return;
}
F_25 ( V_8 , V_33 , V_26 -> V_18 . V_20 ) ;
F_25 ( V_8 , V_35 ,
V_36 | V_37 ) ;
F_25 ( V_8 , V_34 , 0 ) ;
F_26 ( V_28 , V_29 , V_8 -> V_30 ) ;
}
static void
F_27 ( struct V_7 * V_8 , struct V_6 * V_12 ,
bool V_38 )
{
T_2 V_39 = NULL ;
void * V_40 = NULL ;
struct V_41 * V_18 = & V_12 -> V_18 ;
struct V_6 * V_19 ;
unsigned long V_16 ;
F_12 ( F_1 ( & V_8 -> V_3 ) , L_7 , V_18 -> V_25 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_8 -> V_42 = V_18 -> V_25 ;
if ( V_38 ) {
V_39 = V_18 -> V_39 ;
V_40 = V_18 -> V_43 ;
}
F_13 ( V_8 , V_12 ) ;
F_14 (child, &desc->tx_list, desc_node)
F_28 ( & V_19 -> V_18 ) ;
F_28 ( & V_12 -> V_18 ) ;
F_17 ( & V_12 -> V_23 , & V_8 -> V_24 ) ;
F_29 ( & V_12 -> V_11 , & V_8 -> V_24 ) ;
if ( ! V_8 -> V_3 . V_44 ) {
struct V_1 * V_5 = F_2 ( & V_8 -> V_3 ) ;
if ( ! ( V_18 -> V_16 & V_45 ) ) {
if ( V_18 -> V_16 & V_46 )
F_30 ( V_5 , V_12 -> V_21 . V_47 ,
V_12 -> V_48 , V_49 ) ;
else
F_31 ( V_5 , V_12 -> V_21 . V_47 ,
V_12 -> V_48 , V_49 ) ;
}
if ( ! ( V_18 -> V_16 & V_50 ) ) {
if ( V_18 -> V_16 & V_51 )
F_30 ( V_5 , V_12 -> V_21 . V_52 ,
V_12 -> V_48 , V_22 ) ;
else
F_31 ( V_5 , V_12 -> V_21 . V_52 ,
V_12 -> V_48 , V_22 ) ;
}
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
if ( V_38 && V_39 )
V_39 ( V_40 ) ;
}
static void F_32 ( struct V_27 * V_28 , struct V_7 * V_8 )
{
struct V_6 * V_12 , * V_13 ;
F_33 ( V_53 ) ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( F_22 ( V_28 , V_29 ) & V_8 -> V_30 ) {
F_23 ( F_1 ( & V_8 -> V_3 ) ,
L_8 ) ;
F_34 ( V_28 , V_29 , V_8 -> V_30 ) ;
while ( F_22 ( V_28 , V_29 ) & V_8 -> V_30 )
F_35 () ;
}
F_17 ( & V_8 -> V_9 , & V_53 ) ;
if ( ! F_36 ( & V_8 -> V_54 ) ) {
F_29 ( V_8 -> V_54 . V_10 , & V_8 -> V_9 ) ;
F_20 ( V_8 , F_3 ( V_8 ) ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node)
F_27 ( V_8 , V_12 , true ) ;
}
static void F_37 ( struct V_27 * V_28 , struct V_7 * V_8 )
{
T_3 V_55 ;
struct V_6 * V_12 , * V_13 ;
struct V_6 * V_19 ;
T_4 V_56 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_38 ( V_28 , V_57 . V_58 , V_8 -> V_30 ) ;
V_55 = F_24 ( V_8 , V_33 ) ;
V_56 = F_22 ( V_28 , V_59 . V_60 ) ;
if ( V_56 & V_8 -> V_30 ) {
F_38 ( V_28 , V_57 . V_60 , V_8 -> V_30 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_32 ( V_28 , V_8 ) ;
return;
}
if ( F_36 ( & V_8 -> V_9 ) ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_12 ( F_1 ( & V_8 -> V_3 ) , L_9 , V_55 ) ;
F_7 (desc, _desc, &dwc->active_list, desc_node) {
if ( V_12 -> V_18 . V_20 == V_55 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
if ( V_12 -> V_21 . V_55 == V_55 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_14 (child, &desc->tx_list, desc_node)
if ( V_19 -> V_21 . V_55 == V_55 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
return;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_27 ( V_8 , V_12 , true ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
}
F_23 ( F_1 ( & V_8 -> V_3 ) ,
L_10 ) ;
F_34 ( V_28 , V_29 , V_8 -> V_30 ) ;
while ( F_22 ( V_28 , V_29 ) & V_8 -> V_30 )
F_35 () ;
if ( ! F_36 ( & V_8 -> V_54 ) ) {
F_29 ( V_8 -> V_54 . V_10 , & V_8 -> V_9 ) ;
F_20 ( V_8 , F_3 ( V_8 ) ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
static void F_39 ( struct V_7 * V_8 , struct V_61 * V_21 )
{
F_40 ( V_62 , F_1 ( & V_8 -> V_3 ) ,
L_11 ,
V_21 -> V_52 , V_21 -> V_47 , V_21 -> V_55 ,
V_21 -> V_63 , V_21 -> V_64 ) ;
}
static void F_41 ( struct V_27 * V_28 , struct V_7 * V_8 )
{
struct V_6 * V_65 ;
struct V_6 * V_19 ;
unsigned long V_16 ;
F_37 ( V_28 , V_8 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_65 = F_3 ( V_8 ) ;
F_42 ( & V_65 -> V_11 ) ;
F_29 ( V_8 -> V_54 . V_10 , V_8 -> V_9 . V_66 ) ;
F_38 ( V_28 , V_57 . ERROR , V_8 -> V_30 ) ;
if ( ! F_36 ( & V_8 -> V_9 ) )
F_20 ( V_8 , F_3 ( V_8 ) ) ;
F_40 ( V_62 , F_1 ( & V_8 -> V_3 ) ,
L_12 ) ;
F_40 ( V_62 , F_1 ( & V_8 -> V_3 ) ,
L_13 , V_65 -> V_18 . V_25 ) ;
F_39 ( V_8 , & V_65 -> V_21 ) ;
F_14 (child, &bad_desc->tx_list, desc_node)
F_39 ( V_8 , & V_19 -> V_21 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_27 ( V_8 , V_65 , true ) ;
}
inline T_3 F_43 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
return F_24 ( V_8 , V_31 ) ;
}
inline T_3 F_45 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
return F_24 ( V_8 , V_32 ) ;
}
static void F_46 ( struct V_27 * V_28 , struct V_7 * V_8 ,
T_4 V_67 , T_4 V_68 , T_4 V_56 )
{
unsigned long V_16 ;
if ( V_67 & V_8 -> V_30 ) {
void (* V_39)( void * V_40 );
void * V_43 ;
F_12 ( F_1 ( & V_8 -> V_3 ) , L_14 ,
F_24 ( V_8 , V_33 ) ) ;
F_38 ( V_28 , V_57 . V_58 , V_8 -> V_30 ) ;
V_39 = V_8 -> V_69 -> V_70 ;
V_43 = V_8 -> V_69 -> V_71 ;
if ( V_39 )
V_39 ( V_43 ) ;
}
if ( F_47 ( V_68 & V_8 -> V_30 ) ||
F_47 ( V_56 & V_8 -> V_30 ) ) {
int V_15 ;
F_23 ( F_1 ( & V_8 -> V_3 ) , L_15
L_16 ,
V_56 ? L_17 : L_18 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_23 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ,
F_24 ( V_8 , V_31 ) ,
F_24 ( V_8 , V_32 ) ,
F_24 ( V_8 , V_33 ) ,
F_24 ( V_8 , V_34 ) ,
F_24 ( V_8 , V_35 ) ) ;
F_34 ( V_28 , V_29 , V_8 -> V_30 ) ;
while ( F_22 ( V_28 , V_29 ) & V_8 -> V_30 )
F_35 () ;
F_25 ( V_8 , V_33 , 0 ) ;
F_25 ( V_8 , V_35 , 0 ) ;
F_25 ( V_8 , V_34 , 0 ) ;
F_38 ( V_28 , V_57 . V_58 , V_8 -> V_30 ) ;
F_38 ( V_28 , V_57 . ERROR , V_8 -> V_30 ) ;
F_38 ( V_28 , V_57 . V_60 , V_8 -> V_30 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_69 -> V_72 ; V_15 ++ )
F_39 ( V_8 , & V_8 -> V_69 -> V_12 [ V_15 ] -> V_21 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
}
static void F_48 ( unsigned long V_73 )
{
struct V_27 * V_28 = (struct V_27 * ) V_73 ;
struct V_7 * V_8 ;
T_4 V_67 ;
T_4 V_56 ;
T_4 V_68 ;
int V_15 ;
V_67 = F_22 ( V_28 , V_59 . V_58 ) ;
V_56 = F_22 ( V_28 , V_59 . V_60 ) ;
V_68 = F_22 ( V_28 , V_59 . ERROR ) ;
F_12 ( V_28 -> V_74 . V_4 , L_19 ,
V_67 , V_68 ) ;
for ( V_15 = 0 ; V_15 < V_28 -> V_74 . V_75 ; V_15 ++ ) {
V_8 = & V_28 -> V_3 [ V_15 ] ;
if ( F_49 ( V_76 , & V_8 -> V_16 ) )
F_46 ( V_28 , V_8 , V_67 , V_68 ,
V_56 ) ;
else if ( V_68 & ( 1 << V_15 ) )
F_41 ( V_28 , V_8 ) ;
else if ( ( V_67 | V_56 ) & ( 1 << V_15 ) )
F_37 ( V_28 , V_8 ) ;
}
F_26 ( V_28 , V_77 . V_60 , V_28 -> V_78 ) ;
F_26 ( V_28 , V_77 . V_58 , V_28 -> V_78 ) ;
F_26 ( V_28 , V_77 . ERROR , V_28 -> V_78 ) ;
}
static T_5 F_50 ( int V_79 , void * V_80 )
{
struct V_27 * V_28 = V_80 ;
T_4 V_81 ;
F_12 ( V_28 -> V_74 . V_4 , L_20 ,
F_22 ( V_28 , V_82 ) ) ;
F_34 ( V_28 , V_77 . V_60 , V_28 -> V_78 ) ;
F_34 ( V_28 , V_77 . V_58 , V_28 -> V_78 ) ;
F_34 ( V_28 , V_77 . ERROR , V_28 -> V_78 ) ;
V_81 = F_22 ( V_28 , V_82 ) ;
if ( V_81 ) {
F_23 ( V_28 -> V_74 . V_4 ,
L_21 ,
V_81 ) ;
F_34 ( V_28 , V_77 . V_60 , ( 1 << 8 ) - 1 ) ;
F_34 ( V_28 , V_77 . V_58 , ( 1 << 8 ) - 1 ) ;
F_34 ( V_28 , V_77 . V_83 , ( 1 << 8 ) - 1 ) ;
F_34 ( V_28 , V_77 . V_84 , ( 1 << 8 ) - 1 ) ;
F_34 ( V_28 , V_77 . ERROR , ( 1 << 8 ) - 1 ) ;
}
F_51 ( & V_28 -> V_85 ) ;
return V_86 ;
}
static T_1 F_52 ( struct V_41 * V_87 )
{
struct V_6 * V_12 = F_53 ( V_87 ) ;
struct V_7 * V_8 = F_44 ( V_87 -> V_3 ) ;
T_1 V_25 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_25 = F_19 ( V_8 , V_12 ) ;
if ( F_36 ( & V_8 -> V_9 ) ) {
F_12 ( F_1 ( V_87 -> V_3 ) , L_22 ,
V_12 -> V_18 . V_25 ) ;
F_54 ( & V_12 -> V_11 , & V_8 -> V_9 ) ;
F_20 ( V_8 , F_3 ( V_8 ) ) ;
} else {
F_12 ( F_1 ( V_87 -> V_3 ) , L_23 ,
V_12 -> V_18 . V_25 ) ;
F_54 ( & V_12 -> V_11 , & V_8 -> V_54 ) ;
}
F_11 ( & V_8 -> V_17 , V_16 ) ;
return V_25 ;
}
static struct V_41 *
F_55 ( struct V_2 * V_3 , T_3 V_88 , T_3 V_89 ,
T_6 V_48 , unsigned long V_16 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
struct V_6 * V_12 ;
struct V_6 * V_26 ;
struct V_6 * V_66 ;
T_6 V_90 ;
T_6 V_91 ;
unsigned int V_92 ;
unsigned int V_93 ;
T_4 V_64 ;
F_12 ( F_1 ( V_3 ) , L_24 ,
V_88 , V_89 , V_48 , V_16 ) ;
if ( F_47 ( ! V_48 ) ) {
F_10 ( F_1 ( V_3 ) , L_25 ) ;
return NULL ;
}
if ( ! ( ( V_89 | V_88 | V_48 ) & 7 ) )
V_92 = V_93 = 3 ;
else if ( ! ( ( V_89 | V_88 | V_48 ) & 3 ) )
V_92 = V_93 = 2 ;
else if ( ! ( ( V_89 | V_88 | V_48 ) & 1 ) )
V_92 = V_93 = 1 ;
else
V_92 = V_93 = 0 ;
V_64 = F_56 ( V_3 -> V_44 )
| F_57 ( V_93 )
| F_58 ( V_92 )
| V_94
| V_95
| V_96 ;
V_66 = V_26 = NULL ;
for ( V_91 = 0 ; V_91 < V_48 ; V_91 += V_90 << V_92 ) {
V_90 = F_59 ( T_6 , ( V_48 - V_91 ) >> V_92 ,
V_97 ) ;
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 )
goto V_98;
V_12 -> V_21 . V_52 = V_89 + V_91 ;
V_12 -> V_21 . V_47 = V_88 + V_91 ;
V_12 -> V_21 . V_64 = V_64 ;
V_12 -> V_21 . V_63 = V_90 ;
if ( ! V_26 ) {
V_26 = V_12 ;
} else {
V_66 -> V_21 . V_55 = V_12 -> V_18 . V_20 ;
F_60 ( F_2 ( V_3 ) ,
V_66 -> V_18 . V_20 , sizeof( V_66 -> V_21 ) ,
V_22 ) ;
F_54 ( & V_12 -> V_11 ,
& V_26 -> V_23 ) ;
}
V_66 = V_12 ;
}
if ( V_16 & V_99 )
V_66 -> V_21 . V_64 |= V_100 ;
V_66 -> V_21 . V_55 = 0 ;
F_60 ( F_2 ( V_3 ) ,
V_66 -> V_18 . V_20 , sizeof( V_66 -> V_21 ) ,
V_22 ) ;
V_26 -> V_18 . V_16 = V_16 ;
V_26 -> V_48 = V_48 ;
return & V_26 -> V_18 ;
V_98:
F_16 ( V_8 , V_26 ) ;
return NULL ;
}
static struct V_41 *
F_61 ( struct V_2 * V_3 , struct V_101 * V_102 ,
unsigned int V_103 , enum V_104 V_105 ,
unsigned long V_16 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
struct V_106 * V_107 = V_3 -> V_44 ;
struct V_6 * V_66 ;
struct V_6 * V_26 ;
T_4 V_64 ;
T_3 V_108 ;
unsigned int V_109 ;
unsigned int V_110 ;
unsigned int V_15 ;
struct V_101 * V_111 ;
T_6 V_112 = 0 ;
F_12 ( F_1 ( V_3 ) , L_26 ) ;
if ( F_47 ( ! V_107 || ! V_103 ) )
return NULL ;
V_109 = V_107 -> V_109 ;
V_66 = V_26 = NULL ;
switch ( V_105 ) {
case V_22 :
V_64 = ( F_56 ( V_3 -> V_44 )
| F_57 ( V_109 )
| V_113
| V_95
| F_62 ( V_107 -> V_114 ) ) ;
V_108 = V_107 -> V_115 ;
F_63 (sgl, sg, sg_len, i) {
struct V_6 * V_12 ;
T_4 V_48 , V_116 , V_117 ;
V_117 = F_64 ( V_111 ) ;
V_48 = F_65 ( V_111 ) ;
V_110 = 2 ;
if ( F_47 ( V_117 & 3 || V_48 & 3 ) )
V_110 = 0 ;
V_118:
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 ) {
F_23 ( F_1 ( V_3 ) ,
L_27 ) ;
goto V_98;
}
V_12 -> V_21 . V_52 = V_117 ;
V_12 -> V_21 . V_47 = V_108 ;
V_12 -> V_21 . V_64 = V_64 | F_58 ( V_110 ) ;
if ( ( V_48 >> V_110 ) > V_97 ) {
V_116 = V_97 << V_110 ;
V_117 += V_116 ;
V_48 -= V_116 ;
} else {
V_116 = V_48 ;
V_48 = 0 ;
}
V_12 -> V_21 . V_63 = V_116 >> V_110 ;
if ( ! V_26 ) {
V_26 = V_12 ;
} else {
V_66 -> V_21 . V_55 = V_12 -> V_18 . V_20 ;
F_60 ( F_2 ( V_3 ) ,
V_66 -> V_18 . V_20 ,
sizeof( V_66 -> V_21 ) ,
V_22 ) ;
F_54 ( & V_12 -> V_11 ,
& V_26 -> V_23 ) ;
}
V_66 = V_12 ;
V_112 += V_116 ;
if ( V_48 )
goto V_118;
}
break;
case V_49 :
V_64 = ( F_56 ( V_3 -> V_44 )
| F_58 ( V_109 )
| V_94
| V_119
| F_62 ( V_107 -> V_114 ) ) ;
V_108 = V_107 -> V_120 ;
F_63 (sgl, sg, sg_len, i) {
struct V_6 * V_12 ;
T_4 V_48 , V_116 , V_117 ;
V_117 = F_64 ( V_111 ) ;
V_48 = F_65 ( V_111 ) ;
V_110 = 2 ;
if ( F_47 ( V_117 & 3 || V_48 & 3 ) )
V_110 = 0 ;
V_121:
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 ) {
F_23 ( F_1 ( V_3 ) ,
L_27 ) ;
goto V_98;
}
V_12 -> V_21 . V_52 = V_108 ;
V_12 -> V_21 . V_47 = V_117 ;
V_12 -> V_21 . V_64 = V_64 | F_57 ( V_110 ) ;
if ( ( V_48 >> V_109 ) > V_97 ) {
V_116 = V_97 << V_109 ;
V_117 += V_116 ;
V_48 -= V_116 ;
} else {
V_116 = V_48 ;
V_48 = 0 ;
}
V_12 -> V_21 . V_63 = V_116 >> V_109 ;
if ( ! V_26 ) {
V_26 = V_12 ;
} else {
V_66 -> V_21 . V_55 = V_12 -> V_18 . V_20 ;
F_60 ( F_2 ( V_3 ) ,
V_66 -> V_18 . V_20 ,
sizeof( V_66 -> V_21 ) ,
V_22 ) ;
F_54 ( & V_12 -> V_11 ,
& V_26 -> V_23 ) ;
}
V_66 = V_12 ;
V_112 += V_116 ;
if ( V_48 )
goto V_121;
}
break;
default:
return NULL ;
}
if ( V_16 & V_99 )
V_66 -> V_21 . V_64 |= V_100 ;
V_66 -> V_21 . V_55 = 0 ;
F_60 ( F_2 ( V_3 ) ,
V_66 -> V_18 . V_20 , sizeof( V_66 -> V_21 ) ,
V_22 ) ;
V_26 -> V_48 = V_112 ;
return & V_26 -> V_18 ;
V_98:
F_16 ( V_8 , V_26 ) ;
return NULL ;
}
static int F_66 ( struct V_2 * V_3 , enum V_122 V_123 ,
unsigned long V_124 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
struct V_27 * V_28 = F_21 ( V_3 -> V_1 ) ;
struct V_6 * V_12 , * V_13 ;
unsigned long V_16 ;
T_4 V_125 ;
F_33 ( V_53 ) ;
if ( V_123 == V_126 ) {
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_125 = F_24 ( V_8 , V_127 ) ;
F_25 ( V_8 , V_127 , V_125 | V_128 ) ;
while ( ! ( F_24 ( V_8 , V_127 ) & V_129 ) )
F_35 () ;
V_8 -> V_130 = true ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
} else if ( V_123 == V_131 ) {
if ( ! V_8 -> V_130 )
return 0 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_125 = F_24 ( V_8 , V_127 ) ;
F_25 ( V_8 , V_127 , V_125 & ~ V_128 ) ;
V_8 -> V_130 = false ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
} else if ( V_123 == V_132 ) {
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_34 ( V_28 , V_29 , V_8 -> V_30 ) ;
while ( F_22 ( V_28 , V_29 ) & V_8 -> V_30 )
F_35 () ;
V_8 -> V_130 = false ;
F_17 ( & V_8 -> V_54 , & V_53 ) ;
F_17 ( & V_8 -> V_9 , & V_53 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node)
F_27 ( V_8 , V_12 , false ) ;
} else
return - V_133 ;
return 0 ;
}
static enum V_134
F_67 ( struct V_2 * V_3 ,
T_1 V_25 ,
struct V_135 * V_136 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
T_1 V_137 ;
T_1 V_138 ;
int V_14 ;
V_138 = V_8 -> V_42 ;
V_137 = V_3 -> V_25 ;
V_14 = F_68 ( V_25 , V_138 , V_137 ) ;
if ( V_14 != V_139 ) {
F_37 ( F_21 ( V_3 -> V_1 ) , V_8 ) ;
V_138 = V_8 -> V_42 ;
V_137 = V_3 -> V_25 ;
V_14 = F_68 ( V_25 , V_138 , V_137 ) ;
}
if ( V_14 != V_139 )
F_69 ( V_136 , V_138 , V_137 ,
F_3 ( V_8 ) -> V_48 ) ;
else
F_69 ( V_136 , V_138 , V_137 , 0 ) ;
if ( V_8 -> V_130 )
return V_140 ;
return V_14 ;
}
static void F_70 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
if ( ! F_36 ( & V_8 -> V_54 ) )
F_37 ( F_21 ( V_3 -> V_1 ) , V_8 ) ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
struct V_27 * V_28 = F_21 ( V_3 -> V_1 ) ;
struct V_6 * V_12 ;
struct V_106 * V_107 ;
int V_15 ;
T_4 V_141 ;
T_4 V_125 ;
unsigned long V_16 ;
F_12 ( F_1 ( V_3 ) , L_28 ) ;
if ( F_22 ( V_28 , V_29 ) & V_8 -> V_30 ) {
F_10 ( F_1 ( V_3 ) , L_29 ) ;
return - V_142 ;
}
V_8 -> V_42 = V_3 -> V_25 = 1 ;
V_141 = V_143 ;
V_125 = 0 ;
V_107 = V_3 -> V_44 ;
if ( V_107 ) {
F_72 ( ! V_107 -> V_144 || V_107 -> V_144 != V_28 -> V_74 . V_4 ) ;
V_141 = V_107 -> V_145 ;
V_125 = V_107 -> V_146 & ~ V_147 ;
}
V_125 |= F_73 ( V_8 -> V_148 ) ;
F_25 ( V_8 , V_127 , V_125 ) ;
F_25 ( V_8 , V_149 , V_141 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_15 = V_8 -> V_150 ;
while ( V_8 -> V_150 < V_151 ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
V_12 = F_74 ( sizeof( struct V_6 ) , V_152 ) ;
if ( ! V_12 ) {
F_75 ( F_1 ( V_3 ) ,
L_30 , V_15 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
break;
}
F_76 ( & V_12 -> V_23 ) ;
F_77 ( & V_12 -> V_18 , V_3 ) ;
V_12 -> V_18 . V_153 = F_52 ;
V_12 -> V_18 . V_16 = V_154 ;
V_12 -> V_18 . V_20 = F_78 ( F_2 ( V_3 ) , & V_12 -> V_21 ,
sizeof( V_12 -> V_21 ) , V_22 ) ;
F_16 ( V_8 , V_12 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
V_15 = ++ V_8 -> V_150 ;
}
F_26 ( V_28 , V_77 . V_60 , V_8 -> V_30 ) ;
F_26 ( V_28 , V_77 . V_58 , V_8 -> V_30 ) ;
F_26 ( V_28 , V_77 . ERROR , V_8 -> V_30 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_10 ( F_1 ( V_3 ) ,
L_31 , V_15 ) ;
return V_15 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
struct V_27 * V_28 = F_21 ( V_3 -> V_1 ) ;
struct V_6 * V_12 , * V_13 ;
unsigned long V_16 ;
F_33 ( V_53 ) ;
F_10 ( F_1 ( V_3 ) , L_32 ,
V_8 -> V_150 ) ;
F_72 ( ! F_36 ( & V_8 -> V_9 ) ) ;
F_72 ( ! F_36 ( & V_8 -> V_54 ) ) ;
F_72 ( F_22 ( F_21 ( V_3 -> V_1 ) , V_29 ) & V_8 -> V_30 ) ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_17 ( & V_8 -> V_24 , & V_53 ) ;
V_8 -> V_150 = 0 ;
F_34 ( V_28 , V_77 . V_60 , V_8 -> V_30 ) ;
F_34 ( V_28 , V_77 . V_58 , V_8 -> V_30 ) ;
F_34 ( V_28 , V_77 . ERROR , V_8 -> V_30 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_7 (desc, _desc, &list, desc_node) {
F_12 ( F_1 ( V_3 ) , L_33 , V_12 ) ;
F_30 ( F_2 ( V_3 ) , V_12 -> V_18 . V_20 ,
sizeof( V_12 -> V_21 ) , V_22 ) ;
F_80 ( V_12 ) ;
}
F_12 ( F_1 ( V_3 ) , L_34 ) ;
}
int F_81 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
struct V_27 * V_28 = F_21 ( V_8 -> V_3 . V_1 ) ;
unsigned long V_16 ;
if ( ! F_49 ( V_76 , & V_8 -> V_16 ) ) {
F_23 ( F_1 ( & V_8 -> V_3 ) , L_35 ) ;
return - V_155 ;
}
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( F_22 ( V_28 , V_29 ) & V_8 -> V_30 ) {
F_23 ( F_1 ( & V_8 -> V_3 ) ,
L_5 ) ;
F_23 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ,
F_24 ( V_8 , V_31 ) ,
F_24 ( V_8 , V_32 ) ,
F_24 ( V_8 , V_33 ) ,
F_24 ( V_8 , V_34 ) ,
F_24 ( V_8 , V_35 ) ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
return - V_156 ;
}
F_38 ( V_28 , V_57 . V_58 , V_8 -> V_30 ) ;
F_38 ( V_28 , V_57 . ERROR , V_8 -> V_30 ) ;
F_38 ( V_28 , V_57 . V_60 , V_8 -> V_30 ) ;
F_25 ( V_8 , V_33 , V_8 -> V_69 -> V_12 [ 0 ] -> V_18 . V_20 ) ;
F_25 ( V_8 , V_35 , V_36 | V_37 ) ;
F_25 ( V_8 , V_34 , 0 ) ;
F_26 ( V_28 , V_29 , V_8 -> V_30 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
return 0 ;
}
void F_82 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
struct V_27 * V_28 = F_21 ( V_8 -> V_3 . V_1 ) ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_34 ( V_28 , V_29 , V_8 -> V_30 ) ;
while ( F_22 ( V_28 , V_29 ) & V_8 -> V_30 )
F_35 () ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
}
struct V_157 * F_83 ( struct V_2 * V_3 ,
T_3 V_158 , T_6 V_159 , T_6 V_160 ,
enum V_104 V_105 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
struct V_157 * V_69 ;
struct V_157 * V_161 = NULL ;
struct V_6 * V_12 ;
struct V_6 * V_162 = NULL ;
struct V_106 * V_107 = V_3 -> V_44 ;
unsigned long V_163 ;
unsigned int V_109 ;
unsigned int V_72 ;
unsigned int V_15 ;
unsigned long V_16 ;
F_6 ( & V_8 -> V_17 , V_16 ) ;
if ( ! F_36 ( & V_8 -> V_54 ) || ! F_36 ( & V_8 -> V_9 ) ) {
F_11 ( & V_8 -> V_17 , V_16 ) ;
F_10 ( F_1 ( & V_8 -> V_3 ) ,
L_36 ) ;
return F_84 ( - V_156 ) ;
}
V_163 = F_85 ( V_76 , & V_8 -> V_16 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
if ( V_163 ) {
F_10 ( F_1 ( & V_8 -> V_3 ) ,
L_37 ) ;
return F_84 ( - V_156 ) ;
}
V_161 = F_84 ( - V_164 ) ;
V_109 = V_107 -> V_109 ;
V_72 = V_159 / V_160 ;
if ( V_160 > ( V_97 << V_109 ) )
goto V_165;
if ( F_47 ( V_160 & ( ( 1 << V_109 ) - 1 ) ) )
goto V_165;
if ( F_47 ( V_158 & ( ( 1 << V_109 ) - 1 ) ) )
goto V_165;
if ( F_47 ( ! ( V_105 & ( V_22 | V_49 ) ) ) )
goto V_165;
V_161 = F_84 ( - V_166 ) ;
if ( V_72 > V_151 )
goto V_165;
V_69 = F_74 ( sizeof( struct V_157 ) , V_152 ) ;
if ( ! V_69 )
goto V_165;
V_69 -> V_12 = F_74 ( sizeof( struct V_6 * ) * V_72 , V_152 ) ;
if ( ! V_69 -> V_12 )
goto V_167;
for ( V_15 = 0 ; V_15 < V_72 ; V_15 ++ ) {
V_12 = F_5 ( V_8 ) ;
if ( ! V_12 )
goto V_168;
switch ( V_105 ) {
case V_22 :
V_12 -> V_21 . V_47 = V_107 -> V_115 ;
V_12 -> V_21 . V_52 = V_158 + ( V_160 * V_15 ) ;
V_12 -> V_21 . V_64 = ( F_56 ( V_3 -> V_44 )
| F_57 ( V_109 )
| F_58 ( V_109 )
| V_113
| V_95
| F_62 ( V_107 -> V_114 )
| V_100 ) ;
break;
case V_49 :
V_12 -> V_21 . V_47 = V_158 + ( V_160 * V_15 ) ;
V_12 -> V_21 . V_52 = V_107 -> V_120 ;
V_12 -> V_21 . V_64 = ( F_56 ( V_3 -> V_44 )
| F_58 ( V_109 )
| F_57 ( V_109 )
| V_94
| V_119
| F_62 ( V_107 -> V_114 )
| V_100 ) ;
break;
default:
break;
}
V_12 -> V_21 . V_63 = ( V_160 >> V_109 ) ;
V_69 -> V_12 [ V_15 ] = V_12 ;
if ( V_162 ) {
V_162 -> V_21 . V_55 = V_12 -> V_18 . V_20 ;
F_60 ( F_2 ( V_3 ) ,
V_162 -> V_18 . V_20 , sizeof( V_162 -> V_21 ) ,
V_22 ) ;
}
V_162 = V_12 ;
}
V_162 -> V_21 . V_55 = V_69 -> V_12 [ 0 ] -> V_18 . V_20 ;
F_60 ( F_2 ( V_3 ) , V_162 -> V_18 . V_20 ,
sizeof( V_162 -> V_21 ) , V_22 ) ;
F_10 ( F_1 ( & V_8 -> V_3 ) , L_38
L_39 , V_158 , V_159 ,
V_160 , V_72 ) ;
V_69 -> V_72 = V_72 ;
V_8 -> V_69 = V_69 ;
return V_69 ;
V_168:
while ( V_15 -- )
F_16 ( V_8 , V_69 -> V_12 [ V_15 ] ) ;
V_167:
F_80 ( V_69 ) ;
V_165:
F_86 ( V_76 , & V_8 -> V_16 ) ;
return (struct V_157 * ) V_161 ;
}
void F_87 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_44 ( V_3 ) ;
struct V_27 * V_28 = F_21 ( V_8 -> V_3 . V_1 ) ;
struct V_157 * V_69 = V_8 -> V_69 ;
int V_15 ;
unsigned long V_16 ;
F_10 ( F_1 ( & V_8 -> V_3 ) , L_40 ) ;
if ( ! V_69 )
return;
F_6 ( & V_8 -> V_17 , V_16 ) ;
F_34 ( V_28 , V_29 , V_8 -> V_30 ) ;
while ( F_22 ( V_28 , V_29 ) & V_8 -> V_30 )
F_35 () ;
F_38 ( V_28 , V_57 . V_58 , V_8 -> V_30 ) ;
F_38 ( V_28 , V_57 . ERROR , V_8 -> V_30 ) ;
F_38 ( V_28 , V_57 . V_60 , V_8 -> V_30 ) ;
F_11 ( & V_8 -> V_17 , V_16 ) ;
for ( V_15 = 0 ; V_15 < V_69 -> V_72 ; V_15 ++ )
F_16 ( V_8 , V_69 -> V_12 [ V_15 ] ) ;
F_80 ( V_69 -> V_12 ) ;
F_80 ( V_69 ) ;
F_86 ( V_76 , & V_8 -> V_16 ) ;
}
static void F_88 ( struct V_27 * V_28 )
{
F_38 ( V_28 , V_169 , 0 ) ;
F_34 ( V_28 , V_77 . V_60 , V_28 -> V_78 ) ;
F_34 ( V_28 , V_77 . V_58 , V_28 -> V_78 ) ;
F_34 ( V_28 , V_77 . V_83 , V_28 -> V_78 ) ;
F_34 ( V_28 , V_77 . V_84 , V_28 -> V_78 ) ;
F_34 ( V_28 , V_77 . ERROR , V_28 -> V_78 ) ;
while ( F_22 ( V_28 , V_169 ) & V_170 )
F_35 () ;
}
static int T_7 F_89 ( struct V_171 * V_172 )
{
struct V_173 * V_174 ;
struct V_175 * V_176 ;
struct V_27 * V_28 ;
T_6 V_177 ;
int V_79 ;
int V_178 ;
int V_15 ;
V_174 = V_172 -> V_4 . V_179 ;
if ( ! V_174 || V_174 -> V_180 > V_181 )
return - V_164 ;
V_176 = F_90 ( V_172 , V_182 , 0 ) ;
if ( ! V_176 )
return - V_164 ;
V_79 = F_91 ( V_172 , 0 ) ;
if ( V_79 < 0 )
return V_79 ;
V_177 = sizeof( struct V_27 ) ;
V_177 += V_174 -> V_180 * sizeof( struct V_7 ) ;
V_28 = F_74 ( V_177 , V_152 ) ;
if ( ! V_28 )
return - V_166 ;
if ( ! F_92 ( V_176 -> V_183 , V_184 , V_172 -> V_4 . V_185 -> V_186 ) ) {
V_178 = - V_156 ;
goto V_187;
}
V_28 -> V_188 = F_93 ( V_176 -> V_183 , V_184 ) ;
if ( ! V_28 -> V_188 ) {
V_178 = - V_166 ;
goto V_189;
}
V_28 -> V_190 = F_94 ( & V_172 -> V_4 , L_41 ) ;
if ( F_95 ( V_28 -> V_190 ) ) {
V_178 = F_96 ( V_28 -> V_190 ) ;
goto V_191;
}
F_97 ( V_28 -> V_190 ) ;
F_88 ( V_28 ) ;
V_178 = F_98 ( V_79 , F_50 , 0 , L_42 , V_28 ) ;
if ( V_178 )
goto V_192;
F_99 ( V_172 , V_28 ) ;
F_100 ( & V_28 -> V_85 , F_48 , ( unsigned long ) V_28 ) ;
V_28 -> V_78 = ( 1 << V_174 -> V_180 ) - 1 ;
F_76 ( & V_28 -> V_74 . V_193 ) ;
for ( V_15 = 0 ; V_15 < V_174 -> V_180 ; V_15 ++ ) {
struct V_7 * V_8 = & V_28 -> V_3 [ V_15 ] ;
V_8 -> V_3 . V_1 = & V_28 -> V_74 ;
V_8 -> V_3 . V_25 = V_8 -> V_42 = 1 ;
if ( V_174 -> V_194 == V_195 )
F_54 ( & V_8 -> V_3 . V_196 ,
& V_28 -> V_74 . V_193 ) ;
else
F_18 ( & V_8 -> V_3 . V_196 , & V_28 -> V_74 . V_193 ) ;
if ( V_174 -> V_197 == V_198 )
V_8 -> V_148 = 7 - V_15 ;
else
V_8 -> V_148 = V_15 ;
V_8 -> V_199 = & F_101 ( V_28 ) -> V_200 [ V_15 ] ;
F_102 ( & V_8 -> V_17 ) ;
V_8 -> V_30 = 1 << V_15 ;
F_76 ( & V_8 -> V_9 ) ;
F_76 ( & V_8 -> V_54 ) ;
F_76 ( & V_8 -> V_24 ) ;
F_34 ( V_28 , V_29 , V_8 -> V_30 ) ;
}
F_38 ( V_28 , V_57 . V_60 , V_28 -> V_78 ) ;
F_38 ( V_28 , V_57 . V_58 , V_28 -> V_78 ) ;
F_38 ( V_28 , V_57 . V_83 , V_28 -> V_78 ) ;
F_38 ( V_28 , V_57 . V_84 , V_28 -> V_78 ) ;
F_38 ( V_28 , V_57 . ERROR , V_28 -> V_78 ) ;
F_34 ( V_28 , V_77 . V_60 , V_28 -> V_78 ) ;
F_34 ( V_28 , V_77 . V_58 , V_28 -> V_78 ) ;
F_34 ( V_28 , V_77 . V_83 , V_28 -> V_78 ) ;
F_34 ( V_28 , V_77 . V_84 , V_28 -> V_78 ) ;
F_34 ( V_28 , V_77 . ERROR , V_28 -> V_78 ) ;
F_103 ( V_201 , V_28 -> V_74 . V_202 ) ;
F_103 ( V_203 , V_28 -> V_74 . V_202 ) ;
if ( V_174 -> V_204 )
F_103 ( V_205 , V_28 -> V_74 . V_202 ) ;
V_28 -> V_74 . V_4 = & V_172 -> V_4 ;
V_28 -> V_74 . V_206 = F_71 ;
V_28 -> V_74 . V_207 = F_79 ;
V_28 -> V_74 . V_208 = F_55 ;
V_28 -> V_74 . V_209 = F_61 ;
V_28 -> V_74 . V_210 = F_66 ;
V_28 -> V_74 . V_211 = F_67 ;
V_28 -> V_74 . V_212 = F_70 ;
F_38 ( V_28 , V_169 , V_170 ) ;
F_104 ( V_213 L_43 ,
F_105 ( & V_172 -> V_4 ) , V_174 -> V_180 ) ;
F_106 ( & V_28 -> V_74 ) ;
return 0 ;
V_192:
F_107 ( V_28 -> V_190 ) ;
F_108 ( V_28 -> V_190 ) ;
V_191:
F_109 ( V_28 -> V_188 ) ;
V_28 -> V_188 = NULL ;
V_189:
F_110 ( V_176 ) ;
V_187:
F_80 ( V_28 ) ;
return V_178 ;
}
static int T_8 F_111 ( struct V_171 * V_172 )
{
struct V_27 * V_28 = F_112 ( V_172 ) ;
struct V_7 * V_8 , * V_214 ;
struct V_175 * V_176 ;
F_88 ( V_28 ) ;
F_113 ( & V_28 -> V_74 ) ;
F_114 ( F_91 ( V_172 , 0 ) , V_28 ) ;
F_115 ( & V_28 -> V_85 ) ;
F_7 (dwc, _dwc, &dw->dma.channels,
chan.device_node) {
F_9 ( & V_8 -> V_3 . V_196 ) ;
F_34 ( V_28 , V_29 , V_8 -> V_30 ) ;
}
F_107 ( V_28 -> V_190 ) ;
F_108 ( V_28 -> V_190 ) ;
F_109 ( V_28 -> V_188 ) ;
V_28 -> V_188 = NULL ;
V_176 = F_90 ( V_172 , V_182 , 0 ) ;
F_116 ( V_176 -> V_183 , V_184 ) ;
F_80 ( V_28 ) ;
return 0 ;
}
static void F_117 ( struct V_171 * V_172 )
{
struct V_27 * V_28 = F_112 ( V_172 ) ;
F_88 ( F_112 ( V_172 ) ) ;
F_107 ( V_28 -> V_190 ) ;
}
static int F_118 ( struct V_1 * V_4 )
{
struct V_171 * V_172 = F_119 ( V_4 ) ;
struct V_27 * V_28 = F_112 ( V_172 ) ;
F_88 ( F_112 ( V_172 ) ) ;
F_107 ( V_28 -> V_190 ) ;
return 0 ;
}
static int F_120 ( struct V_1 * V_4 )
{
struct V_171 * V_172 = F_119 ( V_4 ) ;
struct V_27 * V_28 = F_112 ( V_172 ) ;
F_97 ( V_28 -> V_190 ) ;
F_38 ( V_28 , V_169 , V_170 ) ;
return 0 ;
}
static int T_7 F_121 ( void )
{
return F_122 ( & V_215 , F_89 ) ;
}
static void T_8 F_123 ( void )
{
F_124 ( & V_215 ) ;
}
