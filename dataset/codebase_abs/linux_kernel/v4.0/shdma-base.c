static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 ;
if ( V_8 -> V_11 ( V_2 ) )
return;
F_3 (sdesc, &schan->ld_queue, node)
if ( V_10 -> V_12 == V_13 ) {
V_8 -> V_14 ( V_2 , V_10 ) ;
break;
}
}
static T_1 F_4 ( struct V_15 * V_16 )
{
struct V_9 * V_17 , * V_18 , * V_19 =
F_5 ( V_16 , struct V_9 , V_20 ) ;
struct V_1 * V_2 = F_6 ( V_16 -> V_21 ) ;
T_2 V_22 = V_16 -> V_22 ;
T_1 V_23 ;
bool V_24 ;
F_7 ( & V_2 -> V_25 ) ;
V_24 = F_8 ( & V_2 -> V_26 ) ;
V_23 = F_9 ( V_16 ) ;
F_10 (chunk, c, desc->node.prev, node) {
if ( V_17 != V_19 && ( V_17 -> V_12 == V_27 ||
V_17 -> V_20 . V_23 > 0 ||
V_17 -> V_20 . V_23 == - V_28 ||
& V_17 -> V_29 == & V_2 -> V_30 ) )
break;
V_17 -> V_12 = V_13 ;
if ( V_17 -> V_31 == 1 ) {
V_17 -> V_20 . V_22 = V_22 ;
V_17 -> V_20 . V_32 = V_16 -> V_32 ;
} else {
V_17 -> V_20 . V_22 = NULL ;
}
V_17 -> V_23 = V_23 ;
F_11 ( & V_17 -> V_29 , & V_2 -> V_26 ) ;
F_12 ( V_2 -> V_33 , L_1 ,
V_16 -> V_23 , & V_17 -> V_20 , V_2 -> V_34 ) ;
}
if ( V_24 ) {
int V_35 ;
V_2 -> V_36 = V_37 ;
V_35 = F_13 ( V_2 -> V_33 ) ;
F_14 ( & V_2 -> V_25 ) ;
if ( V_35 < 0 )
F_15 ( V_2 -> V_33 , L_2 , V_38 , V_35 ) ;
F_16 ( V_2 -> V_33 ) ;
F_7 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_36 != V_39 ) {
struct V_3 * V_4 =
F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
F_12 ( V_2 -> V_33 , L_3 ,
V_2 -> V_34 ) ;
V_8 -> V_40 ( V_2 , V_2 -> V_41 ) ;
if ( V_2 -> V_36 == V_42 )
F_1 ( V_2 ) ;
V_2 -> V_36 = V_39 ;
}
} else {
V_2 -> V_36 = V_42 ;
}
F_14 ( & V_2 -> V_25 ) ;
return V_23 ;
}
static struct V_9 * F_17 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_3 (sdesc, &schan->ld_free, node)
if ( V_10 -> V_12 != V_43 ) {
F_18 ( V_10 -> V_12 != V_27 ) ;
F_19 ( & V_10 -> V_29 ) ;
return V_10 ;
}
return NULL ;
}
static int F_20 ( struct V_1 * V_2 , int V_41 ,
T_3 V_44 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_35 , V_45 ;
if ( V_2 -> V_33 -> V_46 ) {
V_45 = V_2 -> V_47 ;
V_35 = V_8 -> V_48 ( V_2 , V_45 , V_44 , true ) ;
if ( V_35 < 0 )
return V_35 ;
V_41 = V_2 -> V_41 ;
} else {
V_45 = V_41 ;
}
if ( V_41 < 0 || V_41 >= V_49 )
return - V_50 ;
if ( F_21 ( V_41 , V_51 ) )
return - V_28 ;
V_35 = V_8 -> V_48 ( V_2 , V_45 , V_44 , false ) ;
if ( V_35 < 0 ) {
F_22 ( V_41 , V_51 ) ;
return V_35 ;
}
V_2 -> V_41 = V_41 ;
return 0 ;
}
static int F_23 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_19 ;
struct V_52 * V_53 = V_21 -> V_54 ;
int V_35 , V_55 ;
if ( V_53 ) {
V_35 = F_20 ( V_2 , V_53 -> V_41 , 0 ) ;
if ( V_35 < 0 )
goto V_56;
} else {
V_2 -> V_41 = - V_50 ;
}
V_2 -> V_19 = F_24 ( V_57 ,
V_4 -> V_58 , V_59 ) ;
if ( ! V_2 -> V_19 ) {
V_35 = - V_60 ;
goto V_61;
}
V_2 -> V_62 = V_57 ;
for ( V_55 = 0 ; V_55 < V_57 ; V_55 ++ ) {
V_19 = V_8 -> V_63 ( V_2 -> V_19 , V_55 ) ;
F_25 ( & V_19 -> V_20 ,
& V_2 -> V_5 ) ;
V_19 -> V_20 . V_64 = F_4 ;
V_19 -> V_12 = V_27 ;
F_26 ( & V_19 -> V_29 , & V_2 -> V_30 ) ;
}
return V_57 ;
V_61:
if ( V_53 )
V_56:
F_22 ( V_53 -> V_41 , V_51 ) ;
V_21 -> V_54 = NULL ;
return V_35 ;
}
bool F_27 ( struct V_5 * V_21 , void * V_65 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_45 = ( long ) V_65 ;
int V_35 ;
if ( V_21 -> V_6 -> V_66 !=
F_23 )
return false ;
if ( V_45 < 0 )
return true ;
V_2 = F_6 ( V_21 ) ;
if ( ! V_2 -> V_33 -> V_46 && V_45 >= V_49 )
return false ;
V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
V_35 = V_4 -> V_8 -> V_48 ( V_2 , V_45 , 0 , true ) ;
if ( V_35 < 0 )
return false ;
return true ;
}
static T_2 F_28 ( struct V_1 * V_2 , bool V_67 )
{
struct V_9 * V_19 , * V_68 ;
bool V_69 = false ;
T_1 V_23 = 0 ;
T_2 V_22 = NULL ;
void * V_70 = NULL ;
unsigned long V_71 ;
F_29 ( V_72 ) ;
F_30 ( & V_2 -> V_25 , V_71 ) ;
F_10 (desc, _desc, &schan->ld_queue, node) {
struct V_15 * V_16 = & V_19 -> V_20 ;
F_18 ( V_16 -> V_23 > 0 && V_16 -> V_23 != V_19 -> V_23 ) ;
F_18 ( V_19 -> V_12 != V_13 &&
V_19 -> V_12 != V_73 &&
V_19 -> V_12 != V_74 ) ;
if ( ! V_67 && V_19 -> V_12 == V_13 &&
V_19 -> V_23 != V_23 )
break;
if ( V_16 -> V_23 > 0 )
V_23 = V_16 -> V_23 ;
if ( V_19 -> V_12 == V_73 && V_19 -> V_31 == 1 ) {
if ( V_2 -> V_5 . V_75 != V_19 -> V_23 - 1 )
F_12 ( V_2 -> V_33 ,
L_4 ,
V_19 -> V_23 ,
V_2 -> V_5 . V_75 + 1 ) ;
V_2 -> V_5 . V_75 = V_19 -> V_23 ;
}
if ( V_19 -> V_12 == V_73 && V_16 -> V_22 ) {
V_19 -> V_12 = V_74 ;
V_22 = V_16 -> V_22 ;
V_70 = V_16 -> V_32 ;
F_12 ( V_2 -> V_33 , L_5 ,
V_16 -> V_23 , V_16 , V_2 -> V_34 ) ;
F_18 ( V_19 -> V_31 != 1 ) ;
break;
}
if ( V_16 -> V_23 > 0 || V_16 -> V_23 == - V_28 ) {
if ( V_19 -> V_12 == V_73 ) {
F_18 ( V_16 -> V_23 < 0 ) ;
V_19 -> V_12 = V_74 ;
}
V_69 = F_31 ( V_16 ) ;
} else {
switch ( V_19 -> V_12 ) {
case V_73 :
V_19 -> V_12 = V_74 ;
case V_74 :
if ( V_69 )
F_32 ( & V_19 -> V_20 ) ;
}
}
F_12 ( V_2 -> V_33 , L_6 ,
V_16 , V_16 -> V_23 ) ;
if ( ( ( V_19 -> V_12 == V_73 ||
V_19 -> V_12 == V_74 ) &&
F_31 ( & V_19 -> V_20 ) ) || V_67 ) {
if ( V_67 || ! V_19 -> V_76 ) {
V_19 -> V_12 = V_27 ;
F_33 ( & V_19 -> V_29 , & V_2 -> V_30 ) ;
} else {
V_19 -> V_12 = V_13 ;
F_11 ( & V_19 -> V_29 , & V_72 ) ;
}
if ( F_8 ( & V_2 -> V_26 ) ) {
F_12 ( V_2 -> V_33 , L_7 , V_2 -> V_34 ) ;
F_34 ( V_2 -> V_33 ) ;
V_2 -> V_36 = V_39 ;
} else if ( V_2 -> V_36 == V_42 ) {
F_1 ( V_2 ) ;
}
}
}
if ( V_67 && ! V_22 )
V_2 -> V_5 . V_75 = V_2 -> V_5 . V_23 ;
F_35 ( & V_72 , & V_2 -> V_26 ) ;
F_36 ( & V_2 -> V_25 , V_71 ) ;
if ( V_22 )
V_22 ( V_70 ) ;
return V_22 ;
}
static void F_37 ( struct V_1 * V_2 , bool V_67 )
{
while ( F_28 ( V_2 , V_67 ) )
;
}
static void F_38 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_21 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
F_29 ( V_77 ) ;
F_7 ( & V_2 -> V_25 ) ;
V_8 -> V_78 ( V_2 ) ;
F_14 ( & V_2 -> V_25 ) ;
if ( ! F_8 ( & V_2 -> V_26 ) )
F_37 ( V_2 , true ) ;
if ( V_2 -> V_41 >= 0 ) {
F_22 ( V_2 -> V_41 , V_51 ) ;
V_21 -> V_54 = NULL ;
}
F_7 ( & V_2 -> V_25 ) ;
F_39 ( & V_2 -> V_30 , & V_77 ) ;
V_2 -> V_62 = 0 ;
F_14 ( & V_2 -> V_25 ) ;
F_40 ( V_2 -> V_19 ) ;
}
static struct V_9 * F_41 ( struct V_1 * V_2 ,
unsigned long V_71 , T_3 * V_79 , T_3 * V_80 , T_4 * V_81 ,
struct V_9 * * V_82 , enum V_83 V_84 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_85 ;
T_4 V_86 = * V_81 ;
if ( ! V_86 )
return NULL ;
V_85 = F_17 ( V_2 ) ;
if ( ! V_85 ) {
F_15 ( V_2 -> V_33 , L_8 ) ;
return NULL ;
}
V_8 -> V_87 ( V_2 , V_85 , * V_80 , * V_79 , & V_86 ) ;
if ( ! * V_82 ) {
V_85 -> V_20 . V_23 = - V_28 ;
* V_82 = V_85 ;
} else {
V_85 -> V_20 . V_23 = - V_50 ;
}
F_12 ( V_2 -> V_33 ,
L_9 ,
V_86 , * V_81 , V_80 , V_79 , & V_85 -> V_20 ,
V_85 -> V_20 . V_23 ) ;
V_85 -> V_12 = V_43 ;
V_85 -> V_20 . V_71 = V_71 ;
V_85 -> V_84 = V_84 ;
V_85 -> V_88 = 0 ;
* V_81 -= V_86 ;
if ( V_84 == V_89 || V_84 == V_90 )
* V_80 += V_86 ;
if ( V_84 == V_89 || V_84 == V_91 )
* V_79 += V_86 ;
return V_85 ;
}
static struct V_15 * F_42 ( struct V_1 * V_2 ,
struct V_92 * V_93 , unsigned int V_94 , T_3 * V_95 ,
enum V_83 V_84 , unsigned long V_71 , bool V_76 )
{
struct V_92 * V_96 ;
struct V_9 * V_82 = NULL , * V_85 = NULL ;
F_29 ( V_97 ) ;
int V_31 = 0 ;
unsigned long V_98 ;
int V_55 ;
F_43 (sgl, sg, sg_len, i)
V_31 += F_44 ( F_45 ( V_96 ) , V_2 -> V_99 ) ;
F_30 ( & V_2 -> V_25 , V_98 ) ;
F_43 (sgl, sg, sg_len, i) {
T_3 V_100 = F_46 ( V_96 ) ;
T_4 V_81 = F_45 ( V_96 ) ;
if ( ! V_81 )
goto V_101;
do {
F_12 ( V_2 -> V_33 , L_10 ,
V_55 , V_96 , V_81 , & V_100 ) ;
if ( V_84 == V_91 )
V_85 = F_41 ( V_2 , V_71 ,
& V_100 , V_95 , & V_81 , & V_82 ,
V_84 ) ;
else
V_85 = F_41 ( V_2 , V_71 ,
V_95 , & V_100 , & V_81 , & V_82 ,
V_84 ) ;
if ( ! V_85 )
goto V_101;
V_85 -> V_76 = V_76 ;
if ( V_76 )
V_85 -> V_31 = 1 ;
else
V_85 -> V_31 = V_31 -- ;
F_47 ( & V_85 -> V_29 , & V_97 ) ;
} while ( V_81 );
}
if ( V_85 != V_82 )
V_85 -> V_20 . V_23 = - V_102 ;
F_35 ( & V_97 , & V_2 -> V_30 ) ;
F_36 ( & V_2 -> V_25 , V_98 ) ;
return & V_82 -> V_20 ;
V_101:
F_3 (new, &tx_list, node)
V_85 -> V_12 = V_27 ;
F_48 ( & V_97 , & V_2 -> V_30 ) ;
F_36 ( & V_2 -> V_25 , V_98 ) ;
return NULL ;
}
static struct V_15 * F_49 (
struct V_5 * V_21 , T_3 V_103 , T_3 V_104 ,
T_4 V_81 , unsigned long V_71 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_92 V_96 ;
if ( ! V_21 || ! V_81 )
return NULL ;
F_18 ( ! V_2 -> V_62 ) ;
F_50 ( & V_96 , 1 ) ;
F_51 ( & V_96 , F_52 ( F_53 ( V_104 ) ) , V_81 ,
F_54 ( V_104 ) ) ;
F_46 ( & V_96 ) = V_104 ;
F_45 ( & V_96 ) = V_81 ;
return F_42 ( V_2 , & V_96 , 1 , & V_103 , V_89 ,
V_71 , false ) ;
}
static struct V_15 * F_55 (
struct V_5 * V_21 , struct V_92 * V_93 , unsigned int V_94 ,
enum V_83 V_84 , unsigned long V_71 , void * V_105 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_41 = V_2 -> V_41 ;
T_3 V_44 ;
if ( ! V_21 )
return NULL ;
F_18 ( ! V_2 -> V_62 ) ;
if ( V_41 < 0 || ! V_94 ) {
F_56 ( V_2 -> V_33 , L_11 ,
V_38 , V_94 , V_41 ) ;
return NULL ;
}
V_44 = V_8 -> V_44 ( V_2 ) ;
return F_42 ( V_2 , V_93 , V_94 , & V_44 ,
V_84 , V_71 , false ) ;
}
static struct V_15 * F_57 (
struct V_5 * V_21 , T_3 V_106 , T_4 V_107 ,
T_4 V_108 , enum V_83 V_84 ,
unsigned long V_71 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_15 * V_19 ;
const struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_94 = V_107 / V_108 ;
int V_41 = V_2 -> V_41 ;
T_3 V_44 ;
struct V_92 * V_93 ;
int V_55 ;
if ( ! V_21 )
return NULL ;
F_18 ( ! V_2 -> V_62 ) ;
if ( V_94 > V_109 ) {
F_15 ( V_2 -> V_33 , L_12 ,
V_94 , V_109 ) ;
return NULL ;
}
if ( V_41 < 0 || ( V_107 < V_108 ) ) {
F_56 ( V_2 -> V_33 ,
L_13 ,
V_38 , V_107 , V_108 , V_41 ) ;
return NULL ;
}
V_44 = V_8 -> V_44 ( V_2 ) ;
V_93 = F_24 ( V_94 , sizeof( * V_93 ) , V_59 ) ;
if ( ! V_93 )
return NULL ;
F_50 ( V_93 , V_94 ) ;
for ( V_55 = 0 ; V_55 < V_94 ; V_55 ++ ) {
T_3 V_80 = V_106 + ( V_108 * V_55 ) ;
F_51 ( & V_93 [ V_55 ] , F_52 ( F_53 ( V_80 ) ) , V_108 ,
F_54 ( V_80 ) ) ;
F_46 ( & V_93 [ V_55 ] ) = V_80 ;
F_45 ( & V_93 [ V_55 ] ) = V_108 ;
}
V_19 = F_42 ( V_2 , V_93 , V_94 , & V_44 ,
V_84 , V_71 , true ) ;
F_40 ( V_93 ) ;
return V_19 ;
}
static int F_58 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_21 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
unsigned long V_71 ;
F_30 ( & V_2 -> V_25 , V_71 ) ;
V_8 -> V_78 ( V_2 ) ;
if ( V_8 -> V_110 && ! F_8 ( & V_2 -> V_26 ) ) {
struct V_9 * V_19 = F_59 ( & V_2 -> V_26 ,
struct V_9 , V_29 ) ;
V_19 -> V_88 = V_8 -> V_110 ( V_2 , V_19 ) ;
}
F_36 ( & V_2 -> V_25 , V_71 ) ;
F_37 ( V_2 , true ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_21 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
if ( ! V_112 )
return - V_50 ;
return F_20 ( V_2 , V_112 -> V_41 ,
V_112 -> V_84 == V_91 ?
V_112 -> V_113 : V_112 -> V_114 ) ;
}
static void F_61 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
F_7 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_36 == V_39 )
F_1 ( V_2 ) ;
else
V_2 -> V_36 = V_42 ;
F_14 ( & V_2 -> V_25 ) ;
}
static enum V_115 F_62 ( struct V_5 * V_21 ,
T_1 V_23 ,
struct V_116 * V_117 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
enum V_115 V_118 ;
unsigned long V_71 ;
F_37 ( V_2 , false ) ;
F_30 ( & V_2 -> V_25 , V_71 ) ;
V_118 = F_63 ( V_21 , V_23 , V_117 ) ;
if ( V_118 != V_119 ) {
struct V_9 * V_10 ;
V_118 = V_120 ;
F_3 (sdesc, &schan->ld_queue, node)
if ( V_10 -> V_23 == V_23 ) {
V_118 = V_121 ;
break;
}
}
F_36 ( & V_2 -> V_25 , V_71 ) ;
return V_118 ;
}
bool F_64 ( struct V_3 * V_4 )
{
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_1 * V_2 ;
unsigned int V_122 = 0 ;
int V_55 ;
F_65 (schan, sdev, i) {
struct V_9 * V_10 ;
F_29 ( V_123 ) ;
if ( ! V_2 )
continue;
F_66 ( & V_2 -> V_25 ) ;
V_8 -> V_78 ( V_2 ) ;
F_39 ( & V_2 -> V_26 , & V_123 ) ;
if ( ! F_8 ( & V_123 ) ) {
F_12 ( V_2 -> V_33 , L_7 , V_2 -> V_34 ) ;
F_34 ( V_2 -> V_33 ) ;
}
V_2 -> V_36 = V_39 ;
F_67 ( & V_2 -> V_25 ) ;
F_3 (sdesc, &dl, node) {
struct V_15 * V_16 = & V_10 -> V_20 ;
V_10 -> V_12 = V_27 ;
if ( V_16 -> V_22 )
V_16 -> V_22 ( V_16 -> V_32 ) ;
}
F_66 ( & V_2 -> V_25 ) ;
F_48 ( & V_123 , & V_2 -> V_30 ) ;
F_67 ( & V_2 -> V_25 ) ;
V_122 ++ ;
}
return ! ! V_122 ;
}
static T_5 F_68 ( int V_124 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
T_5 V_35 ;
F_66 ( & V_2 -> V_25 ) ;
V_35 = V_8 -> F_68 ( V_2 , V_124 ) ? V_125 : V_126 ;
F_67 ( & V_2 -> V_25 ) ;
return V_35 ;
}
static T_5 F_69 ( int V_124 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
struct V_9 * V_10 ;
F_7 ( & V_2 -> V_25 ) ;
F_3 (sdesc, &schan->ld_queue, node) {
if ( V_10 -> V_12 == V_13 &&
V_8 -> V_127 ( V_2 , V_10 ) ) {
F_12 ( V_2 -> V_33 , L_14 ,
V_10 -> V_20 . V_23 , & V_10 -> V_20 ) ;
V_10 -> V_12 = V_73 ;
break;
}
}
F_1 ( V_2 ) ;
F_14 ( & V_2 -> V_25 ) ;
F_37 ( V_2 , false ) ;
return V_128 ;
}
int F_70 ( struct V_1 * V_2 , int V_124 ,
unsigned long V_71 , const char * V_129 )
{
int V_35 = F_71 ( V_2 -> V_33 , V_124 , F_68 ,
F_69 , V_71 , V_129 , V_2 ) ;
V_2 -> V_124 = V_35 < 0 ? V_35 : V_124 ;
return V_35 ;
}
void F_72 ( struct V_3 * V_4 ,
struct V_1 * V_2 , int V_34 )
{
V_2 -> V_36 = V_39 ;
V_2 -> V_5 . V_6 = & V_4 -> V_130 ;
F_73 ( & V_2 -> V_5 ) ;
V_2 -> V_33 = V_4 -> V_130 . V_33 ;
V_2 -> V_34 = V_34 ;
if ( ! V_2 -> V_99 )
V_2 -> V_99 = V_131 ;
F_74 ( & V_2 -> V_25 ) ;
F_75 ( & V_2 -> V_26 ) ;
F_75 ( & V_2 -> V_30 ) ;
F_47 ( & V_2 -> V_5 . V_132 ,
& V_4 -> V_130 . V_133 ) ;
V_4 -> V_2 [ V_34 ] = V_2 ;
}
void F_76 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_5 . V_132 ) ;
}
int F_77 ( struct V_6 * V_33 , struct V_3 * V_4 ,
int V_134 )
{
struct V_135 * V_130 = & V_4 -> V_130 ;
if ( ! V_4 -> V_8 ||
! V_4 -> V_58 ||
! V_4 -> V_8 -> V_63 ||
! V_4 -> V_8 -> V_14 ||
! V_4 -> V_8 -> V_40 ||
! V_4 -> V_8 -> V_48 ||
! V_4 -> V_8 -> V_87 ||
! V_4 -> V_8 -> V_44 ||
! V_4 -> V_8 -> V_11 ||
! V_4 -> V_8 -> V_78 ||
! V_4 -> V_8 -> V_127 )
return - V_50 ;
V_4 -> V_2 = F_24 ( V_134 , sizeof( * V_4 -> V_2 ) , V_59 ) ;
if ( ! V_4 -> V_2 )
return - V_60 ;
F_75 ( & V_130 -> V_133 ) ;
V_130 -> V_66
= F_23 ;
V_130 -> V_136 = F_38 ;
V_130 -> V_137 = F_49 ;
V_130 -> V_138 = F_62 ;
V_130 -> V_139 = F_61 ;
V_130 -> V_140 = F_55 ;
V_130 -> V_141 = F_57 ;
V_130 -> V_142 = F_60 ;
V_130 -> V_143 = F_58 ;
V_130 -> V_33 = V_33 ;
return 0 ;
}
void F_78 ( struct V_3 * V_4 )
{
F_40 ( V_4 -> V_2 ) ;
}
static int T_6 F_79 ( void )
{
V_51 = F_80 ( F_44 ( V_49 , V_144 ) *
sizeof( long ) , V_59 ) ;
if ( ! V_51 )
return - V_60 ;
return 0 ;
}
static void T_7 F_81 ( void )
{
F_40 ( V_51 ) ;
}
