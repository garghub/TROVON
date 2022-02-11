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
bool F_23 ( struct V_5 * V_21 , void * V_52 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_45 = ( long ) V_52 ;
int V_35 ;
if ( V_45 < 0 )
return true ;
if ( ! V_2 -> V_33 -> V_46 && V_45 >= V_49 )
return false ;
V_35 = V_8 -> V_48 ( V_2 , V_45 , 0 , true ) ;
if ( V_35 < 0 )
return false ;
return true ;
}
static int F_24 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_19 ;
struct V_53 * V_54 = V_21 -> V_55 ;
int V_35 , V_56 ;
if ( V_54 ) {
V_35 = F_20 ( V_2 , V_54 -> V_41 , 0 ) ;
if ( V_35 < 0 )
goto V_57;
} else {
V_2 -> V_41 = - V_50 ;
}
V_2 -> V_19 = F_25 ( V_58 ,
V_4 -> V_59 , V_60 ) ;
if ( ! V_2 -> V_19 ) {
V_35 = - V_61 ;
goto V_62;
}
V_2 -> V_63 = V_58 ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
V_19 = V_8 -> V_64 ( V_2 -> V_19 , V_56 ) ;
F_26 ( & V_19 -> V_20 ,
& V_2 -> V_5 ) ;
V_19 -> V_20 . V_65 = F_4 ;
V_19 -> V_12 = V_27 ;
F_27 ( & V_19 -> V_29 , & V_2 -> V_30 ) ;
}
return V_58 ;
V_62:
if ( V_54 )
V_57:
F_22 ( V_54 -> V_41 , V_51 ) ;
V_21 -> V_55 = NULL ;
return V_35 ;
}
static T_2 F_28 ( struct V_1 * V_2 , bool V_66 )
{
struct V_9 * V_19 , * V_67 ;
bool V_68 = false ;
T_1 V_23 = 0 ;
T_2 V_22 = NULL ;
void * V_69 = NULL ;
unsigned long V_70 ;
F_29 ( V_71 ) ;
F_30 ( & V_2 -> V_25 , V_70 ) ;
F_10 (desc, _desc, &schan->ld_queue, node) {
struct V_15 * V_16 = & V_19 -> V_20 ;
F_18 ( V_16 -> V_23 > 0 && V_16 -> V_23 != V_19 -> V_23 ) ;
F_18 ( V_19 -> V_12 != V_13 &&
V_19 -> V_12 != V_72 &&
V_19 -> V_12 != V_73 ) ;
if ( ! V_66 && V_19 -> V_12 == V_13 &&
V_19 -> V_23 != V_23 )
break;
if ( V_16 -> V_23 > 0 )
V_23 = V_16 -> V_23 ;
if ( V_19 -> V_12 == V_72 && V_19 -> V_31 == 1 ) {
if ( V_2 -> V_5 . V_74 != V_19 -> V_23 - 1 )
F_12 ( V_2 -> V_33 ,
L_4 ,
V_19 -> V_23 ,
V_2 -> V_5 . V_74 + 1 ) ;
V_2 -> V_5 . V_74 = V_19 -> V_23 ;
}
if ( V_19 -> V_12 == V_72 && V_16 -> V_22 ) {
V_19 -> V_12 = V_73 ;
V_22 = V_16 -> V_22 ;
V_69 = V_16 -> V_32 ;
F_12 ( V_2 -> V_33 , L_5 ,
V_16 -> V_23 , V_16 , V_2 -> V_34 ) ;
F_18 ( V_19 -> V_31 != 1 ) ;
break;
}
if ( V_16 -> V_23 > 0 || V_16 -> V_23 == - V_28 ) {
if ( V_19 -> V_12 == V_72 ) {
F_18 ( V_16 -> V_23 < 0 ) ;
V_19 -> V_12 = V_73 ;
}
V_68 = F_31 ( V_16 ) ;
} else {
switch ( V_19 -> V_12 ) {
case V_72 :
V_19 -> V_12 = V_73 ;
case V_73 :
if ( V_68 )
F_32 ( & V_19 -> V_20 ) ;
}
}
F_12 ( V_2 -> V_33 , L_6 ,
V_16 , V_16 -> V_23 ) ;
if ( ( ( V_19 -> V_12 == V_72 ||
V_19 -> V_12 == V_73 ) &&
F_31 ( & V_19 -> V_20 ) ) || V_66 ) {
if ( V_66 || ! V_19 -> V_75 ) {
V_19 -> V_12 = V_27 ;
F_33 ( & V_19 -> V_29 , & V_2 -> V_30 ) ;
} else {
V_19 -> V_12 = V_13 ;
F_11 ( & V_19 -> V_29 , & V_71 ) ;
}
if ( F_8 ( & V_2 -> V_26 ) ) {
F_12 ( V_2 -> V_33 , L_7 , V_2 -> V_34 ) ;
F_34 ( V_2 -> V_33 ) ;
V_2 -> V_36 = V_39 ;
}
}
}
if ( V_66 && ! V_22 )
V_2 -> V_5 . V_74 = V_2 -> V_5 . V_23 ;
F_35 ( & V_71 , & V_2 -> V_26 ) ;
F_36 ( & V_2 -> V_25 , V_70 ) ;
if ( V_22 )
V_22 ( V_69 ) ;
return V_22 ;
}
static void F_37 ( struct V_1 * V_2 , bool V_66 )
{
while ( F_28 ( V_2 , V_66 ) )
;
}
static void F_38 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_21 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
F_29 ( V_76 ) ;
F_7 ( & V_2 -> V_25 ) ;
V_8 -> V_77 ( V_2 ) ;
F_14 ( & V_2 -> V_25 ) ;
if ( ! F_8 ( & V_2 -> V_26 ) )
F_37 ( V_2 , true ) ;
if ( V_2 -> V_41 >= 0 ) {
F_22 ( V_2 -> V_41 , V_51 ) ;
V_21 -> V_55 = NULL ;
}
F_7 ( & V_2 -> V_25 ) ;
F_39 ( & V_2 -> V_30 , & V_76 ) ;
V_2 -> V_63 = 0 ;
F_14 ( & V_2 -> V_25 ) ;
F_40 ( V_2 -> V_19 ) ;
}
static struct V_9 * F_41 ( struct V_1 * V_2 ,
unsigned long V_70 , T_3 * V_78 , T_3 * V_79 , T_4 * V_80 ,
struct V_9 * * V_81 , enum V_82 V_83 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_84 ;
T_4 V_85 = * V_80 ;
if ( ! V_85 )
return NULL ;
V_84 = F_17 ( V_2 ) ;
if ( ! V_84 ) {
F_15 ( V_2 -> V_33 , L_8 ) ;
return NULL ;
}
V_8 -> V_86 ( V_2 , V_84 , * V_79 , * V_78 , & V_85 ) ;
if ( ! * V_81 ) {
V_84 -> V_20 . V_23 = - V_28 ;
* V_81 = V_84 ;
} else {
V_84 -> V_20 . V_23 = - V_50 ;
}
F_12 ( V_2 -> V_33 ,
L_9 ,
V_85 , * V_80 , V_79 , V_78 , & V_84 -> V_20 ,
V_84 -> V_20 . V_23 ) ;
V_84 -> V_12 = V_43 ;
V_84 -> V_20 . V_70 = V_70 ;
V_84 -> V_83 = V_83 ;
V_84 -> V_87 = 0 ;
* V_80 -= V_85 ;
if ( V_83 == V_88 || V_83 == V_89 )
* V_79 += V_85 ;
if ( V_83 == V_88 || V_83 == V_90 )
* V_78 += V_85 ;
return V_84 ;
}
static struct V_15 * F_42 ( struct V_1 * V_2 ,
struct V_91 * V_92 , unsigned int V_93 , T_3 * V_94 ,
enum V_82 V_83 , unsigned long V_70 , bool V_75 )
{
struct V_91 * V_95 ;
struct V_9 * V_81 = NULL , * V_84 = NULL ;
F_29 ( V_96 ) ;
int V_31 = 0 ;
unsigned long V_97 ;
int V_56 ;
F_43 (sgl, sg, sg_len, i)
V_31 += F_44 ( F_45 ( V_95 ) , V_2 -> V_98 ) ;
F_30 ( & V_2 -> V_25 , V_97 ) ;
F_43 (sgl, sg, sg_len, i) {
T_3 V_99 = F_46 ( V_95 ) ;
T_4 V_80 = F_45 ( V_95 ) ;
if ( ! V_80 )
goto V_100;
do {
F_12 ( V_2 -> V_33 , L_10 ,
V_56 , V_95 , V_80 , & V_99 ) ;
if ( V_83 == V_90 )
V_84 = F_41 ( V_2 , V_70 ,
& V_99 , V_94 , & V_80 , & V_81 ,
V_83 ) ;
else
V_84 = F_41 ( V_2 , V_70 ,
V_94 , & V_99 , & V_80 , & V_81 ,
V_83 ) ;
if ( ! V_84 )
goto V_100;
V_84 -> V_75 = V_75 ;
if ( V_75 )
V_84 -> V_31 = 1 ;
else
V_84 -> V_31 = V_31 -- ;
F_47 ( & V_84 -> V_29 , & V_96 ) ;
} while ( V_80 );
}
if ( V_84 != V_81 )
V_84 -> V_20 . V_23 = - V_101 ;
F_35 ( & V_96 , & V_2 -> V_30 ) ;
F_36 ( & V_2 -> V_25 , V_97 ) ;
return & V_81 -> V_20 ;
V_100:
F_3 (new, &tx_list, node)
V_84 -> V_12 = V_27 ;
F_48 ( & V_96 , & V_2 -> V_30 ) ;
F_36 ( & V_2 -> V_25 , V_97 ) ;
return NULL ;
}
static struct V_15 * F_49 (
struct V_5 * V_21 , T_3 V_102 , T_3 V_103 ,
T_4 V_80 , unsigned long V_70 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_91 V_95 ;
if ( ! V_21 || ! V_80 )
return NULL ;
F_18 ( ! V_2 -> V_63 ) ;
F_50 ( & V_95 , 1 ) ;
F_51 ( & V_95 , F_52 ( F_53 ( V_103 ) ) , V_80 ,
F_54 ( V_103 ) ) ;
F_46 ( & V_95 ) = V_103 ;
F_45 ( & V_95 ) = V_80 ;
return F_42 ( V_2 , & V_95 , 1 , & V_102 , V_88 ,
V_70 , false ) ;
}
static struct V_15 * F_55 (
struct V_5 * V_21 , struct V_91 * V_92 , unsigned int V_93 ,
enum V_82 V_83 , unsigned long V_70 , void * V_104 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_41 = V_2 -> V_41 ;
T_3 V_44 ;
if ( ! V_21 )
return NULL ;
F_18 ( ! V_2 -> V_63 ) ;
if ( V_41 < 0 || ! V_93 ) {
F_56 ( V_2 -> V_33 , L_11 ,
V_38 , V_93 , V_41 ) ;
return NULL ;
}
V_44 = V_8 -> V_44 ( V_2 ) ;
return F_42 ( V_2 , V_92 , V_93 , & V_44 ,
V_83 , V_70 , false ) ;
}
static struct V_15 * F_57 (
struct V_5 * V_21 , T_3 V_105 , T_4 V_106 ,
T_4 V_107 , enum V_82 V_83 ,
unsigned long V_70 , void * V_104 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_93 = V_106 / V_107 ;
int V_41 = V_2 -> V_41 ;
T_3 V_44 ;
struct V_91 V_92 [ V_108 ] ;
int V_56 ;
if ( ! V_21 )
return NULL ;
F_18 ( ! V_2 -> V_63 ) ;
if ( V_93 > V_108 ) {
F_15 ( V_2 -> V_33 , L_12 ,
V_93 , V_108 ) ;
return NULL ;
}
if ( V_41 < 0 || ( V_106 < V_107 ) ) {
F_56 ( V_2 -> V_33 ,
L_13 ,
V_38 , V_106 , V_107 , V_41 ) ;
return NULL ;
}
V_44 = V_8 -> V_44 ( V_2 ) ;
F_50 ( V_92 , V_93 ) ;
for ( V_56 = 0 ; V_56 < V_93 ; V_56 ++ ) {
T_3 V_79 = V_105 + ( V_107 * V_56 ) ;
F_51 ( & V_92 [ V_56 ] , F_52 ( F_53 ( V_79 ) ) , V_107 ,
F_54 ( V_79 ) ) ;
F_46 ( & V_92 [ V_56 ] ) = V_79 ;
F_45 ( & V_92 [ V_56 ] ) = V_107 ;
}
return F_42 ( V_2 , V_92 , V_93 , & V_44 ,
V_83 , V_70 , true ) ;
}
static int F_58 ( struct V_5 * V_21 , enum V_109 V_110 ,
unsigned long V_52 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_21 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_111 * V_112 ;
unsigned long V_70 ;
int V_35 ;
switch ( V_110 ) {
case V_113 :
F_30 ( & V_2 -> V_25 , V_70 ) ;
V_8 -> V_77 ( V_2 ) ;
if ( V_8 -> V_114 && ! F_8 ( & V_2 -> V_26 ) ) {
struct V_9 * V_19 = F_59 ( & V_2 -> V_26 ,
struct V_9 , V_29 ) ;
V_19 -> V_87 = V_8 -> V_114 ( V_2 , V_19 ) ;
}
F_36 ( & V_2 -> V_25 , V_70 ) ;
F_37 ( V_2 , true ) ;
break;
case V_115 :
if ( ! V_52 )
return - V_50 ;
V_112 = (struct V_111 * ) V_52 ;
V_35 = F_20 ( V_2 , V_112 -> V_41 ,
V_112 -> V_83 == V_90 ?
V_112 -> V_116 : V_112 -> V_117 ) ;
if ( V_35 < 0 )
return V_35 ;
break;
default:
return - V_118 ;
}
return 0 ;
}
static void F_60 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
F_7 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_36 == V_39 )
F_1 ( V_2 ) ;
else
V_2 -> V_36 = V_42 ;
F_14 ( & V_2 -> V_25 ) ;
}
static enum V_119 F_61 ( struct V_5 * V_21 ,
T_1 V_23 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
enum V_119 V_122 ;
unsigned long V_70 ;
F_37 ( V_2 , false ) ;
F_30 ( & V_2 -> V_25 , V_70 ) ;
V_122 = F_62 ( V_21 , V_23 , V_121 ) ;
if ( V_122 != V_123 ) {
struct V_9 * V_10 ;
V_122 = V_124 ;
F_3 (sdesc, &schan->ld_queue, node)
if ( V_10 -> V_23 == V_23 ) {
V_122 = V_125 ;
break;
}
}
F_36 ( & V_2 -> V_25 , V_70 ) ;
return V_122 ;
}
bool F_63 ( struct V_3 * V_4 )
{
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_1 * V_2 ;
unsigned int V_126 = 0 ;
int V_56 ;
F_64 (schan, sdev, i) {
struct V_9 * V_10 ;
F_29 ( V_127 ) ;
if ( ! V_2 )
continue;
F_65 ( & V_2 -> V_25 ) ;
V_8 -> V_77 ( V_2 ) ;
F_39 ( & V_2 -> V_26 , & V_127 ) ;
if ( ! F_8 ( & V_127 ) ) {
F_12 ( V_2 -> V_33 , L_7 , V_2 -> V_34 ) ;
F_34 ( V_2 -> V_33 ) ;
}
V_2 -> V_36 = V_39 ;
F_66 ( & V_2 -> V_25 ) ;
F_3 (sdesc, &dl, node) {
struct V_15 * V_16 = & V_10 -> V_20 ;
V_10 -> V_12 = V_27 ;
if ( V_16 -> V_22 )
V_16 -> V_22 ( V_16 -> V_32 ) ;
}
F_65 ( & V_2 -> V_25 ) ;
F_48 ( & V_127 , & V_2 -> V_30 ) ;
F_66 ( & V_2 -> V_25 ) ;
V_126 ++ ;
}
return ! ! V_126 ;
}
static T_5 F_67 ( int V_128 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
T_5 V_35 ;
F_65 ( & V_2 -> V_25 ) ;
V_35 = V_8 -> F_67 ( V_2 , V_128 ) ? V_129 : V_130 ;
F_66 ( & V_2 -> V_25 ) ;
return V_35 ;
}
static T_5 F_68 ( int V_128 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
struct V_9 * V_10 ;
F_7 ( & V_2 -> V_25 ) ;
F_3 (sdesc, &schan->ld_queue, node) {
if ( V_10 -> V_12 == V_13 &&
V_8 -> V_131 ( V_2 , V_10 ) ) {
F_12 ( V_2 -> V_33 , L_14 ,
V_10 -> V_20 . V_23 , & V_10 -> V_20 ) ;
V_10 -> V_12 = V_72 ;
break;
}
}
F_1 ( V_2 ) ;
F_14 ( & V_2 -> V_25 ) ;
F_37 ( V_2 , false ) ;
return V_132 ;
}
int F_69 ( struct V_1 * V_2 , int V_128 ,
unsigned long V_70 , const char * V_133 )
{
int V_35 = F_70 ( V_2 -> V_33 , V_128 , F_67 ,
F_68 , V_70 , V_133 , V_2 ) ;
V_2 -> V_128 = V_35 < 0 ? V_35 : V_128 ;
return V_35 ;
}
void F_71 ( struct V_3 * V_4 ,
struct V_1 * V_2 , int V_34 )
{
V_2 -> V_36 = V_39 ;
V_2 -> V_5 . V_6 = & V_4 -> V_134 ;
F_72 ( & V_2 -> V_5 ) ;
V_2 -> V_33 = V_4 -> V_134 . V_33 ;
V_2 -> V_34 = V_34 ;
if ( ! V_2 -> V_98 )
V_2 -> V_98 = V_135 ;
F_73 ( & V_2 -> V_25 ) ;
F_74 ( & V_2 -> V_26 ) ;
F_74 ( & V_2 -> V_30 ) ;
F_47 ( & V_2 -> V_5 . V_136 ,
& V_4 -> V_134 . V_137 ) ;
V_4 -> V_2 [ V_4 -> V_134 . V_138 ++ ] = V_2 ;
}
void F_75 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_5 . V_136 ) ;
}
int F_76 ( struct V_6 * V_33 , struct V_3 * V_4 ,
int V_139 )
{
struct V_140 * V_134 = & V_4 -> V_134 ;
if ( ! V_4 -> V_8 ||
! V_4 -> V_59 ||
! V_4 -> V_8 -> V_64 ||
! V_4 -> V_8 -> V_14 ||
! V_4 -> V_8 -> V_40 ||
! V_4 -> V_8 -> V_48 ||
! V_4 -> V_8 -> V_86 ||
! V_4 -> V_8 -> V_44 ||
! V_4 -> V_8 -> V_11 ||
! V_4 -> V_8 -> V_77 ||
! V_4 -> V_8 -> V_131 )
return - V_50 ;
V_4 -> V_2 = F_25 ( V_139 , sizeof( * V_4 -> V_2 ) , V_60 ) ;
if ( ! V_4 -> V_2 )
return - V_61 ;
F_74 ( & V_134 -> V_137 ) ;
V_134 -> V_141
= F_24 ;
V_134 -> V_142 = F_38 ;
V_134 -> V_143 = F_49 ;
V_134 -> V_144 = F_61 ;
V_134 -> V_145 = F_60 ;
V_134 -> V_146 = F_55 ;
V_134 -> V_147 = F_57 ;
V_134 -> V_148 = F_58 ;
V_134 -> V_33 = V_33 ;
return 0 ;
}
void F_77 ( struct V_3 * V_4 )
{
F_40 ( V_4 -> V_2 ) ;
}
static int T_6 F_78 ( void )
{
V_51 = F_79 ( F_44 ( V_49 , V_149 ) *
sizeof( long ) , V_60 ) ;
if ( ! V_51 )
return - V_61 ;
return 0 ;
}
static void T_7 F_80 ( void )
{
F_40 ( V_51 ) ;
}
