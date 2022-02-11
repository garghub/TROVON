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
static int F_20 ( struct V_1 * V_2 , T_3 V_44 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_35 , V_45 ;
if ( V_2 -> V_33 -> V_46 ) {
V_45 = V_2 -> V_47 ;
V_35 = V_8 -> V_48 ( V_2 , V_45 , V_44 , true ) ;
if ( V_35 < 0 )
return V_35 ;
} else {
V_45 = V_2 -> V_49 ;
}
if ( V_2 -> V_49 < 0 || V_2 -> V_49 >= V_50 )
return - V_51 ;
if ( F_21 ( V_2 -> V_49 , V_52 ) )
return - V_28 ;
V_35 = V_8 -> V_48 ( V_2 , V_45 , V_44 , false ) ;
if ( V_35 < 0 ) {
F_22 ( V_2 -> V_49 , V_52 ) ;
return V_35 ;
}
V_2 -> V_41 = V_2 -> V_49 ;
return 0 ;
}
static int F_23 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_19 ;
struct V_53 * V_54 = V_21 -> V_55 ;
int V_35 , V_56 ;
if ( V_54 ) {
V_2 -> V_49 = V_54 -> V_41 ;
V_35 = F_20 ( V_2 , 0 ) ;
if ( V_35 < 0 )
goto V_57;
} else {
V_2 -> V_41 = - V_51 ;
}
V_2 -> V_19 = F_24 ( V_58 ,
V_4 -> V_59 , V_60 ) ;
if ( ! V_2 -> V_19 ) {
V_35 = - V_61 ;
goto V_62;
}
V_2 -> V_63 = V_58 ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
V_19 = V_8 -> V_64 ( V_2 -> V_19 , V_56 ) ;
F_25 ( & V_19 -> V_20 ,
& V_2 -> V_5 ) ;
V_19 -> V_20 . V_65 = F_4 ;
V_19 -> V_12 = V_27 ;
F_26 ( & V_19 -> V_29 , & V_2 -> V_30 ) ;
}
return V_58 ;
V_62:
if ( V_54 )
V_57:
F_22 ( V_54 -> V_41 , V_52 ) ;
V_21 -> V_55 = NULL ;
return V_35 ;
}
bool F_27 ( struct V_5 * V_21 , void * V_66 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_41 = ( long ) V_66 ;
int V_35 ;
if ( V_21 -> V_6 -> V_67 !=
F_23 )
return false ;
V_2 = F_6 ( V_21 ) ;
V_4 = F_2 ( V_21 -> V_6 ) ;
if ( V_2 -> V_33 -> V_46 ) {
V_35 = V_4 -> V_8 -> V_48 ( V_2 , V_41 , 0 , true ) ;
if ( V_35 < 0 )
return false ;
V_2 -> V_49 = V_2 -> V_41 ;
return true ;
}
if ( V_41 < 0 ) {
F_28 ( V_4 -> V_68 . V_33 , L_4 ) ;
return true ;
}
if ( V_41 >= V_50 )
return false ;
V_35 = V_4 -> V_8 -> V_48 ( V_2 , V_41 , 0 , true ) ;
if ( V_35 < 0 )
return false ;
V_2 -> V_49 = V_41 ;
return true ;
}
static T_2 F_29 ( struct V_1 * V_2 , bool V_69 )
{
struct V_9 * V_19 , * V_70 ;
bool V_71 = false ;
T_1 V_23 = 0 ;
T_2 V_22 = NULL ;
void * V_72 = NULL ;
unsigned long V_73 ;
F_30 ( V_74 ) ;
F_31 ( & V_2 -> V_25 , V_73 ) ;
F_10 (desc, _desc, &schan->ld_queue, node) {
struct V_15 * V_16 = & V_19 -> V_20 ;
F_18 ( V_16 -> V_23 > 0 && V_16 -> V_23 != V_19 -> V_23 ) ;
F_18 ( V_19 -> V_12 != V_13 &&
V_19 -> V_12 != V_75 &&
V_19 -> V_12 != V_76 ) ;
if ( ! V_69 && V_19 -> V_12 == V_13 &&
V_19 -> V_23 != V_23 )
break;
if ( V_16 -> V_23 > 0 )
V_23 = V_16 -> V_23 ;
if ( V_19 -> V_12 == V_75 && V_19 -> V_31 == 1 ) {
if ( V_2 -> V_5 . V_77 != V_19 -> V_23 - 1 )
F_12 ( V_2 -> V_33 ,
L_5 ,
V_19 -> V_23 ,
V_2 -> V_5 . V_77 + 1 ) ;
V_2 -> V_5 . V_77 = V_19 -> V_23 ;
}
if ( V_19 -> V_12 == V_75 && V_16 -> V_22 ) {
V_19 -> V_12 = V_76 ;
V_22 = V_16 -> V_22 ;
V_72 = V_16 -> V_32 ;
F_12 ( V_2 -> V_33 , L_6 ,
V_16 -> V_23 , V_16 , V_2 -> V_34 ) ;
F_18 ( V_19 -> V_31 != 1 ) ;
break;
}
if ( V_16 -> V_23 > 0 || V_16 -> V_23 == - V_28 ) {
if ( V_19 -> V_12 == V_75 ) {
F_18 ( V_16 -> V_23 < 0 ) ;
V_19 -> V_12 = V_76 ;
}
V_71 = F_32 ( V_16 ) ;
} else {
switch ( V_19 -> V_12 ) {
case V_75 :
V_19 -> V_12 = V_76 ;
case V_76 :
if ( V_71 )
F_33 ( & V_19 -> V_20 ) ;
}
}
F_12 ( V_2 -> V_33 , L_7 ,
V_16 , V_16 -> V_23 ) ;
if ( ( ( V_19 -> V_12 == V_75 ||
V_19 -> V_12 == V_76 ) &&
F_32 ( & V_19 -> V_20 ) ) || V_69 ) {
if ( V_69 || ! V_19 -> V_78 ) {
V_19 -> V_12 = V_27 ;
F_34 ( & V_19 -> V_29 , & V_2 -> V_30 ) ;
} else {
V_19 -> V_12 = V_13 ;
F_11 ( & V_19 -> V_29 , & V_74 ) ;
}
if ( F_8 ( & V_2 -> V_26 ) ) {
F_12 ( V_2 -> V_33 , L_8 , V_2 -> V_34 ) ;
F_35 ( V_2 -> V_33 ) ;
V_2 -> V_36 = V_39 ;
} else if ( V_2 -> V_36 == V_42 ) {
F_1 ( V_2 ) ;
}
}
}
if ( V_69 && ! V_22 )
V_2 -> V_5 . V_77 = V_2 -> V_5 . V_23 ;
F_36 ( & V_74 , & V_2 -> V_26 ) ;
F_37 ( & V_2 -> V_25 , V_73 ) ;
if ( V_22 )
V_22 ( V_72 ) ;
return V_22 ;
}
static void F_38 ( struct V_1 * V_2 , bool V_69 )
{
while ( F_29 ( V_2 , V_69 ) )
;
}
static void F_39 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_21 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
F_30 ( V_79 ) ;
F_7 ( & V_2 -> V_25 ) ;
V_8 -> V_80 ( V_2 ) ;
F_14 ( & V_2 -> V_25 ) ;
if ( ! F_8 ( & V_2 -> V_26 ) )
F_38 ( V_2 , true ) ;
if ( V_2 -> V_41 >= 0 ) {
F_22 ( V_2 -> V_41 , V_52 ) ;
V_21 -> V_55 = NULL ;
}
V_2 -> V_49 = 0 ;
F_7 ( & V_2 -> V_25 ) ;
F_40 ( & V_2 -> V_30 , & V_79 ) ;
V_2 -> V_63 = 0 ;
F_14 ( & V_2 -> V_25 ) ;
F_41 ( V_2 -> V_19 ) ;
}
static struct V_9 * F_42 ( struct V_1 * V_2 ,
unsigned long V_73 , T_3 * V_81 , T_3 * V_82 , T_4 * V_83 ,
struct V_9 * * V_84 , enum V_85 V_86 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_87 ;
T_4 V_88 = * V_83 ;
if ( ! V_88 )
return NULL ;
V_87 = F_17 ( V_2 ) ;
if ( ! V_87 ) {
F_15 ( V_2 -> V_33 , L_9 ) ;
return NULL ;
}
V_8 -> V_89 ( V_2 , V_87 , * V_82 , * V_81 , & V_88 ) ;
if ( ! * V_84 ) {
V_87 -> V_20 . V_23 = - V_28 ;
* V_84 = V_87 ;
} else {
V_87 -> V_20 . V_23 = - V_51 ;
}
F_12 ( V_2 -> V_33 ,
L_10 ,
V_88 , * V_83 , V_82 , V_81 , & V_87 -> V_20 ,
V_87 -> V_20 . V_23 ) ;
V_87 -> V_12 = V_43 ;
V_87 -> V_20 . V_73 = V_73 ;
V_87 -> V_86 = V_86 ;
V_87 -> V_90 = 0 ;
* V_83 -= V_88 ;
if ( V_86 == V_91 || V_86 == V_92 )
* V_82 += V_88 ;
if ( V_86 == V_91 || V_86 == V_93 )
* V_81 += V_88 ;
return V_87 ;
}
static struct V_15 * F_43 ( struct V_1 * V_2 ,
struct V_94 * V_95 , unsigned int V_96 , T_3 * V_97 ,
enum V_85 V_86 , unsigned long V_73 , bool V_78 )
{
struct V_94 * V_98 ;
struct V_9 * V_84 = NULL , * V_87 = NULL ;
F_30 ( V_99 ) ;
int V_31 = 0 ;
unsigned long V_100 ;
int V_56 ;
F_44 (sgl, sg, sg_len, i)
V_31 += F_45 ( F_46 ( V_98 ) , V_2 -> V_101 ) ;
F_31 ( & V_2 -> V_25 , V_100 ) ;
F_44 (sgl, sg, sg_len, i) {
T_3 V_102 = F_47 ( V_98 ) ;
T_4 V_83 = F_46 ( V_98 ) ;
if ( ! V_83 )
goto V_103;
do {
F_12 ( V_2 -> V_33 , L_11 ,
V_56 , V_98 , V_83 , & V_102 ) ;
if ( V_86 == V_93 )
V_87 = F_42 ( V_2 , V_73 ,
& V_102 , V_97 , & V_83 , & V_84 ,
V_86 ) ;
else
V_87 = F_42 ( V_2 , V_73 ,
V_97 , & V_102 , & V_83 , & V_84 ,
V_86 ) ;
if ( ! V_87 )
goto V_103;
V_87 -> V_78 = V_78 ;
if ( V_78 )
V_87 -> V_31 = 1 ;
else
V_87 -> V_31 = V_31 -- ;
F_48 ( & V_87 -> V_29 , & V_99 ) ;
} while ( V_83 );
}
if ( V_87 != V_84 )
V_87 -> V_20 . V_23 = - V_104 ;
F_36 ( & V_99 , & V_2 -> V_30 ) ;
F_37 ( & V_2 -> V_25 , V_100 ) ;
return & V_84 -> V_20 ;
V_103:
F_3 (new, &tx_list, node)
V_87 -> V_12 = V_27 ;
F_49 ( & V_99 , & V_2 -> V_30 ) ;
F_37 ( & V_2 -> V_25 , V_100 ) ;
return NULL ;
}
static struct V_15 * F_50 (
struct V_5 * V_21 , T_3 V_105 , T_3 V_106 ,
T_4 V_83 , unsigned long V_73 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_94 V_98 ;
if ( ! V_21 || ! V_83 )
return NULL ;
F_18 ( ! V_2 -> V_63 ) ;
F_51 ( & V_98 , 1 ) ;
F_52 ( & V_98 , F_53 ( F_54 ( V_106 ) ) , V_83 ,
F_55 ( V_106 ) ) ;
F_47 ( & V_98 ) = V_106 ;
F_46 ( & V_98 ) = V_83 ;
return F_43 ( V_2 , & V_98 , 1 , & V_105 , V_91 ,
V_73 , false ) ;
}
static struct V_15 * F_56 (
struct V_5 * V_21 , struct V_94 * V_95 , unsigned int V_96 ,
enum V_85 V_86 , unsigned long V_73 , void * V_107 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_41 = V_2 -> V_41 ;
T_3 V_44 ;
if ( ! V_21 )
return NULL ;
F_18 ( ! V_2 -> V_63 ) ;
if ( V_41 < 0 || ! V_96 ) {
F_28 ( V_2 -> V_33 , L_12 ,
V_38 , V_96 , V_41 ) ;
return NULL ;
}
V_44 = V_8 -> V_44 ( V_2 ) ;
return F_43 ( V_2 , V_95 , V_96 , & V_44 ,
V_86 , V_73 , false ) ;
}
static struct V_15 * F_57 (
struct V_5 * V_21 , T_3 V_108 , T_4 V_109 ,
T_4 V_110 , enum V_85 V_86 ,
unsigned long V_73 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_15 * V_19 ;
const struct V_7 * V_8 = V_4 -> V_8 ;
unsigned int V_96 = V_109 / V_110 ;
int V_41 = V_2 -> V_41 ;
T_3 V_44 ;
struct V_94 * V_95 ;
int V_56 ;
if ( ! V_21 )
return NULL ;
F_18 ( ! V_2 -> V_63 ) ;
if ( V_96 > V_111 ) {
F_15 ( V_2 -> V_33 , L_13 ,
V_96 , V_111 ) ;
return NULL ;
}
if ( V_41 < 0 || ( V_109 < V_110 ) ) {
F_28 ( V_2 -> V_33 ,
L_14 ,
V_38 , V_109 , V_110 , V_41 ) ;
return NULL ;
}
V_44 = V_8 -> V_44 ( V_2 ) ;
V_95 = F_24 ( V_96 , sizeof( * V_95 ) , V_60 ) ;
if ( ! V_95 )
return NULL ;
F_51 ( V_95 , V_96 ) ;
for ( V_56 = 0 ; V_56 < V_96 ; V_56 ++ ) {
T_3 V_82 = V_108 + ( V_110 * V_56 ) ;
F_52 ( & V_95 [ V_56 ] , F_53 ( F_54 ( V_82 ) ) , V_110 ,
F_55 ( V_82 ) ) ;
F_47 ( & V_95 [ V_56 ] ) = V_82 ;
F_46 ( & V_95 [ V_56 ] ) = V_110 ;
}
V_19 = F_43 ( V_2 , V_95 , V_96 , & V_44 ,
V_86 , V_73 , true ) ;
F_41 ( V_95 ) ;
return V_19 ;
}
static int F_58 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( V_21 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
unsigned long V_73 ;
F_31 ( & V_2 -> V_25 , V_73 ) ;
V_8 -> V_80 ( V_2 ) ;
if ( V_8 -> V_112 && ! F_8 ( & V_2 -> V_26 ) ) {
struct V_9 * V_19 = F_59 ( & V_2 -> V_26 ,
struct V_9 , V_29 ) ;
V_19 -> V_90 = V_8 -> V_112 ( V_2 , V_19 ) ;
}
F_37 ( & V_2 -> V_25 , V_73 ) ;
F_38 ( V_2 , true ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_21 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
if ( ! V_114 )
return - V_51 ;
if ( F_61 ( V_114 -> V_41 &&
V_114 -> V_41 != V_2 -> V_49 ) )
V_2 -> V_49 = V_114 -> V_41 ;
return F_20 ( V_2 ,
V_114 -> V_86 == V_93 ?
V_114 -> V_115 : V_114 -> V_116 ) ;
}
static void F_62 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
F_7 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_36 == V_39 )
F_1 ( V_2 ) ;
else
V_2 -> V_36 = V_42 ;
F_14 ( & V_2 -> V_25 ) ;
}
static enum V_117 F_63 ( struct V_5 * V_21 ,
T_1 V_23 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
enum V_117 V_120 ;
unsigned long V_73 ;
F_38 ( V_2 , false ) ;
F_31 ( & V_2 -> V_25 , V_73 ) ;
V_120 = F_64 ( V_21 , V_23 , V_119 ) ;
if ( V_120 != V_121 ) {
struct V_9 * V_10 ;
V_120 = V_122 ;
F_3 (sdesc, &schan->ld_queue, node)
if ( V_10 -> V_23 == V_23 ) {
V_120 = V_123 ;
break;
}
}
F_37 ( & V_2 -> V_25 , V_73 ) ;
return V_120 ;
}
bool F_65 ( struct V_3 * V_4 )
{
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_1 * V_2 ;
unsigned int V_124 = 0 ;
int V_56 ;
F_66 (schan, sdev, i) {
struct V_9 * V_10 ;
F_30 ( V_125 ) ;
if ( ! V_2 )
continue;
F_67 ( & V_2 -> V_25 ) ;
V_8 -> V_80 ( V_2 ) ;
F_40 ( & V_2 -> V_26 , & V_125 ) ;
if ( ! F_8 ( & V_125 ) ) {
F_12 ( V_2 -> V_33 , L_8 , V_2 -> V_34 ) ;
F_35 ( V_2 -> V_33 ) ;
}
V_2 -> V_36 = V_39 ;
F_68 ( & V_2 -> V_25 ) ;
F_3 (sdesc, &dl, node) {
struct V_15 * V_16 = & V_10 -> V_20 ;
V_10 -> V_12 = V_27 ;
if ( V_16 -> V_22 )
V_16 -> V_22 ( V_16 -> V_32 ) ;
}
F_67 ( & V_2 -> V_25 ) ;
F_49 ( & V_125 , & V_2 -> V_30 ) ;
F_68 ( & V_2 -> V_25 ) ;
V_124 ++ ;
}
return ! ! V_124 ;
}
static T_5 F_69 ( int V_126 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
T_5 V_35 ;
F_67 ( & V_2 -> V_25 ) ;
V_35 = V_8 -> F_69 ( V_2 , V_126 ) ? V_127 : V_128 ;
F_68 ( & V_2 -> V_25 ) ;
return V_35 ;
}
static T_5 F_70 ( int V_126 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
struct V_9 * V_10 ;
F_7 ( & V_2 -> V_25 ) ;
F_3 (sdesc, &schan->ld_queue, node) {
if ( V_10 -> V_12 == V_13 &&
V_8 -> V_129 ( V_2 , V_10 ) ) {
F_12 ( V_2 -> V_33 , L_15 ,
V_10 -> V_20 . V_23 , & V_10 -> V_20 ) ;
V_10 -> V_12 = V_75 ;
break;
}
}
F_1 ( V_2 ) ;
F_14 ( & V_2 -> V_25 ) ;
F_38 ( V_2 , false ) ;
return V_130 ;
}
int F_71 ( struct V_1 * V_2 , int V_126 ,
unsigned long V_73 , const char * V_131 )
{
int V_35 = F_72 ( V_2 -> V_33 , V_126 , F_69 ,
F_70 , V_73 , V_131 , V_2 ) ;
V_2 -> V_126 = V_35 < 0 ? V_35 : V_126 ;
return V_35 ;
}
void F_73 ( struct V_3 * V_4 ,
struct V_1 * V_2 , int V_34 )
{
V_2 -> V_36 = V_39 ;
V_2 -> V_5 . V_6 = & V_4 -> V_68 ;
F_74 ( & V_2 -> V_5 ) ;
V_2 -> V_33 = V_4 -> V_68 . V_33 ;
V_2 -> V_34 = V_34 ;
if ( ! V_2 -> V_101 )
V_2 -> V_101 = V_132 ;
F_75 ( & V_2 -> V_25 ) ;
F_76 ( & V_2 -> V_26 ) ;
F_76 ( & V_2 -> V_30 ) ;
F_48 ( & V_2 -> V_5 . V_133 ,
& V_4 -> V_68 . V_134 ) ;
V_4 -> V_2 [ V_34 ] = V_2 ;
}
void F_77 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_5 . V_133 ) ;
}
int F_78 ( struct V_6 * V_33 , struct V_3 * V_4 ,
int V_135 )
{
struct V_136 * V_68 = & V_4 -> V_68 ;
if ( ! V_4 -> V_8 ||
! V_4 -> V_59 ||
! V_4 -> V_8 -> V_64 ||
! V_4 -> V_8 -> V_14 ||
! V_4 -> V_8 -> V_40 ||
! V_4 -> V_8 -> V_48 ||
! V_4 -> V_8 -> V_89 ||
! V_4 -> V_8 -> V_44 ||
! V_4 -> V_8 -> V_11 ||
! V_4 -> V_8 -> V_80 ||
! V_4 -> V_8 -> V_129 )
return - V_51 ;
V_4 -> V_2 = F_24 ( V_135 , sizeof( * V_4 -> V_2 ) , V_60 ) ;
if ( ! V_4 -> V_2 )
return - V_61 ;
F_76 ( & V_68 -> V_134 ) ;
V_68 -> V_67
= F_23 ;
V_68 -> V_137 = F_39 ;
V_68 -> V_138 = F_50 ;
V_68 -> V_139 = F_63 ;
V_68 -> V_140 = F_62 ;
V_68 -> V_141 = F_56 ;
V_68 -> V_142 = F_57 ;
V_68 -> V_143 = F_60 ;
V_68 -> V_144 = F_58 ;
V_68 -> V_33 = V_33 ;
return 0 ;
}
void F_79 ( struct V_3 * V_4 )
{
F_41 ( V_4 -> V_2 ) ;
}
static int T_6 F_80 ( void )
{
V_52 = F_81 ( F_45 ( V_50 , V_145 ) *
sizeof( long ) , V_60 ) ;
if ( ! V_52 )
return - V_61 ;
return 0 ;
}
static void T_7 F_82 ( void )
{
F_41 ( V_52 ) ;
}
