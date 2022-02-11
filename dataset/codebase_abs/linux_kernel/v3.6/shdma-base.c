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
F_5 ( V_16 , struct V_9 , V_20 ) ,
* V_21 = V_19 ;
struct V_1 * V_2 = F_6 ( V_16 -> V_22 ) ;
T_2 V_23 = V_16 -> V_23 ;
T_1 V_24 ;
bool V_25 ;
F_7 ( & V_2 -> V_26 ) ;
V_25 = F_8 ( & V_2 -> V_27 ) ;
V_24 = F_9 ( V_16 ) ;
F_10 (chunk, c, desc->node.prev, node) {
if ( V_17 != V_19 && ( V_17 -> V_12 == V_28 ||
V_17 -> V_20 . V_24 > 0 ||
V_17 -> V_20 . V_24 == - V_29 ||
& V_17 -> V_30 == & V_2 -> V_31 ) )
break;
V_17 -> V_12 = V_13 ;
V_17 -> V_20 . V_23 = NULL ;
V_17 -> V_24 = V_24 ;
F_11 ( & V_17 -> V_30 , & V_2 -> V_27 ) ;
V_21 = V_17 ;
F_12 ( V_2 -> V_32 , L_1 ,
V_16 -> V_24 , & V_21 -> V_20 , V_2 -> V_33 ) ;
}
V_21 -> V_20 . V_23 = V_23 ;
V_21 -> V_20 . V_34 = V_16 -> V_34 ;
if ( V_25 ) {
int V_35 ;
V_2 -> V_36 = V_37 ;
V_35 = F_13 ( V_2 -> V_32 ) ;
F_14 ( & V_2 -> V_26 ) ;
if ( V_35 < 0 )
F_15 ( V_2 -> V_32 , L_2 , V_38 , V_35 ) ;
F_16 ( V_2 -> V_32 ) ;
F_7 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_36 != V_39 ) {
struct V_3 * V_4 =
F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
F_12 ( V_2 -> V_32 , L_3 ,
V_2 -> V_33 ) ;
V_8 -> V_40 ( V_2 , V_2 -> V_41 ) ;
if ( V_2 -> V_36 == V_42 )
F_1 ( V_2 ) ;
V_2 -> V_36 = V_39 ;
}
} else {
V_2 -> V_36 = V_42 ;
}
F_14 ( & V_2 -> V_26 ) ;
return V_24 ;
}
static struct V_9 * F_17 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_3 (sdesc, &schan->ld_free, node)
if ( V_10 -> V_12 != V_43 ) {
F_18 ( V_10 -> V_12 != V_28 ) ;
F_19 ( & V_10 -> V_30 ) ;
return V_10 ;
}
return NULL ;
}
static int F_20 ( struct V_1 * V_2 , int V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_35 ;
if ( V_41 < 0 || V_41 >= V_44 )
return - V_45 ;
if ( F_21 ( V_41 , V_46 ) )
return - V_29 ;
V_35 = V_8 -> V_47 ( V_2 , V_41 , false ) ;
if ( V_35 < 0 ) {
F_22 ( V_41 , V_46 ) ;
return V_35 ;
}
V_2 -> V_41 = V_41 ;
return 0 ;
}
bool F_23 ( struct V_5 * V_22 , void * V_48 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_41 = ( int ) V_48 ;
int V_35 ;
if ( V_41 < 0 )
return true ;
if ( V_41 >= V_44 )
return false ;
V_35 = V_8 -> V_47 ( V_2 , V_41 , true ) ;
if ( V_35 < 0 )
return false ;
return true ;
}
static int F_24 ( struct V_5 * V_22 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_19 ;
struct V_49 * V_50 = V_22 -> V_51 ;
int V_35 , V_52 ;
if ( V_50 ) {
V_35 = F_20 ( V_2 , V_50 -> V_41 ) ;
if ( V_35 < 0 )
goto V_53;
} else {
V_2 -> V_41 = - V_45 ;
}
V_2 -> V_19 = F_25 ( V_54 ,
V_4 -> V_55 , V_56 ) ;
if ( ! V_2 -> V_19 ) {
V_35 = - V_57 ;
goto V_58;
}
V_2 -> V_59 = V_54 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
V_19 = V_8 -> V_60 ( V_2 -> V_19 , V_52 ) ;
F_26 ( & V_19 -> V_20 ,
& V_2 -> V_5 ) ;
V_19 -> V_20 . V_61 = F_4 ;
V_19 -> V_12 = V_28 ;
F_27 ( & V_19 -> V_30 , & V_2 -> V_31 ) ;
}
return V_54 ;
V_58:
if ( V_50 )
V_53:
F_22 ( V_50 -> V_41 , V_46 ) ;
V_22 -> V_51 = NULL ;
return V_35 ;
}
static T_2 F_28 ( struct V_1 * V_2 , bool V_62 )
{
struct V_9 * V_19 , * V_63 ;
bool V_64 = false ;
T_1 V_24 = 0 ;
T_2 V_23 = NULL ;
void * V_65 = NULL ;
unsigned long V_66 ;
F_29 ( & V_2 -> V_26 , V_66 ) ;
F_10 (desc, _desc, &schan->ld_queue, node) {
struct V_15 * V_16 = & V_19 -> V_20 ;
F_18 ( V_16 -> V_24 > 0 && V_16 -> V_24 != V_19 -> V_24 ) ;
F_18 ( V_19 -> V_12 != V_13 &&
V_19 -> V_12 != V_67 &&
V_19 -> V_12 != V_68 ) ;
if ( ! V_62 && V_19 -> V_12 == V_13 &&
V_19 -> V_24 != V_24 )
break;
if ( V_16 -> V_24 > 0 )
V_24 = V_16 -> V_24 ;
if ( V_19 -> V_12 == V_67 && V_19 -> V_69 == 1 ) {
if ( V_2 -> V_5 . V_70 != V_19 -> V_24 - 1 )
F_12 ( V_2 -> V_32 ,
L_4 ,
V_19 -> V_24 ,
V_2 -> V_5 . V_70 + 1 ) ;
V_2 -> V_5 . V_70 = V_19 -> V_24 ;
}
if ( V_19 -> V_12 == V_67 && V_16 -> V_23 ) {
V_19 -> V_12 = V_68 ;
V_23 = V_16 -> V_23 ;
V_65 = V_16 -> V_34 ;
F_12 ( V_2 -> V_32 , L_5 ,
V_16 -> V_24 , V_16 , V_2 -> V_33 ) ;
F_18 ( V_19 -> V_69 != 1 ) ;
break;
}
if ( V_16 -> V_24 > 0 || V_16 -> V_24 == - V_29 ) {
if ( V_19 -> V_12 == V_67 ) {
F_18 ( V_16 -> V_24 < 0 ) ;
V_19 -> V_12 = V_68 ;
}
V_64 = F_30 ( V_16 ) ;
} else {
switch ( V_19 -> V_12 ) {
case V_67 :
V_19 -> V_12 = V_68 ;
case V_68 :
if ( V_64 )
F_31 ( & V_19 -> V_20 ) ;
}
}
F_12 ( V_2 -> V_32 , L_6 ,
V_16 , V_16 -> V_24 ) ;
if ( ( ( V_19 -> V_12 == V_67 ||
V_19 -> V_12 == V_68 ) &&
F_30 ( & V_19 -> V_20 ) ) || V_62 ) {
V_19 -> V_12 = V_28 ;
F_32 ( & V_19 -> V_30 , & V_2 -> V_31 ) ;
if ( F_8 ( & V_2 -> V_27 ) ) {
F_12 ( V_2 -> V_32 , L_7 , V_2 -> V_33 ) ;
F_33 ( V_2 -> V_32 ) ;
V_2 -> V_36 = V_39 ;
}
}
}
if ( V_62 && ! V_23 )
V_2 -> V_5 . V_70 = V_2 -> V_5 . V_24 ;
F_34 ( & V_2 -> V_26 , V_66 ) ;
if ( V_23 )
V_23 ( V_65 ) ;
return V_23 ;
}
static void F_35 ( struct V_1 * V_2 , bool V_62 )
{
while ( F_28 ( V_2 , V_62 ) )
;
}
static void F_36 ( struct V_5 * V_22 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_22 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
F_37 ( V_71 ) ;
F_7 ( & V_2 -> V_26 ) ;
V_8 -> V_72 ( V_2 ) ;
F_14 ( & V_2 -> V_26 ) ;
if ( ! F_8 ( & V_2 -> V_27 ) )
F_35 ( V_2 , true ) ;
if ( V_2 -> V_41 >= 0 ) {
F_22 ( V_2 -> V_41 , V_46 ) ;
V_22 -> V_51 = NULL ;
}
F_7 ( & V_2 -> V_26 ) ;
F_38 ( & V_2 -> V_31 , & V_71 ) ;
V_2 -> V_59 = 0 ;
F_14 ( & V_2 -> V_26 ) ;
F_39 ( V_2 -> V_19 ) ;
}
static struct V_9 * F_40 ( struct V_1 * V_2 ,
unsigned long V_66 , T_3 * V_73 , T_3 * V_74 , T_4 * V_75 ,
struct V_9 * * V_76 , enum V_77 V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_79 ;
T_4 V_80 = * V_75 ;
if ( ! V_80 )
return NULL ;
V_79 = F_17 ( V_2 ) ;
if ( ! V_79 ) {
F_15 ( V_2 -> V_32 , L_8 ) ;
return NULL ;
}
V_8 -> V_81 ( V_2 , V_79 , * V_74 , * V_73 , & V_80 ) ;
if ( ! * V_76 ) {
V_79 -> V_20 . V_24 = - V_29 ;
* V_76 = V_79 ;
} else {
V_79 -> V_20 . V_24 = - V_45 ;
}
F_12 ( V_2 -> V_32 ,
L_9 ,
V_80 , * V_75 , * V_74 , * V_73 , & V_79 -> V_20 ,
V_79 -> V_20 . V_24 ) ;
V_79 -> V_12 = V_43 ;
V_79 -> V_20 . V_66 = V_66 ;
V_79 -> V_78 = V_78 ;
V_79 -> V_82 = 0 ;
* V_75 -= V_80 ;
if ( V_78 == V_83 || V_78 == V_84 )
* V_74 += V_80 ;
if ( V_78 == V_83 || V_78 == V_85 )
* V_73 += V_80 ;
return V_79 ;
}
static struct V_15 * F_41 ( struct V_1 * V_2 ,
struct V_86 * V_87 , unsigned int V_88 , T_3 * V_89 ,
enum V_77 V_78 , unsigned long V_66 )
{
struct V_86 * V_90 ;
struct V_9 * V_76 = NULL , * V_79 = NULL ;
F_37 ( V_91 ) ;
int V_69 = 0 ;
unsigned long V_92 ;
int V_52 ;
F_42 (sgl, sg, sg_len, i)
V_69 += F_43 ( F_44 ( V_90 ) , V_2 -> V_93 ) ;
F_29 ( & V_2 -> V_26 , V_92 ) ;
F_42 (sgl, sg, sg_len, i) {
T_3 V_94 = F_45 ( V_90 ) ;
T_4 V_75 = F_44 ( V_90 ) ;
if ( ! V_75 )
goto V_95;
do {
F_12 ( V_2 -> V_32 , L_10 ,
V_52 , V_90 , V_75 , ( unsigned long long ) V_94 ) ;
if ( V_78 == V_85 )
V_79 = F_40 ( V_2 , V_66 ,
& V_94 , V_89 , & V_75 , & V_76 ,
V_78 ) ;
else
V_79 = F_40 ( V_2 , V_66 ,
V_89 , & V_94 , & V_75 , & V_76 ,
V_78 ) ;
if ( ! V_79 )
goto V_95;
V_79 -> V_69 = V_69 -- ;
F_46 ( & V_79 -> V_30 , & V_91 ) ;
} while ( V_75 );
}
if ( V_79 != V_76 )
V_79 -> V_20 . V_24 = - V_96 ;
F_47 ( & V_91 , & V_2 -> V_31 ) ;
F_34 ( & V_2 -> V_26 , V_92 ) ;
return & V_76 -> V_20 ;
V_95:
F_3 (new, &tx_list, node)
V_79 -> V_12 = V_28 ;
F_48 ( & V_91 , & V_2 -> V_31 ) ;
F_34 ( & V_2 -> V_26 , V_92 ) ;
return NULL ;
}
static struct V_15 * F_49 (
struct V_5 * V_22 , T_3 V_97 , T_3 V_98 ,
T_4 V_75 , unsigned long V_66 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_86 V_90 ;
if ( ! V_22 || ! V_75 )
return NULL ;
F_18 ( ! V_2 -> V_59 ) ;
F_50 ( & V_90 , 1 ) ;
F_51 ( & V_90 , F_52 ( F_53 ( V_98 ) ) , V_75 ,
F_54 ( V_98 ) ) ;
F_45 ( & V_90 ) = V_98 ;
F_44 ( & V_90 ) = V_75 ;
return F_41 ( V_2 , & V_90 , 1 , & V_97 , V_83 , V_66 ) ;
}
static struct V_15 * F_55 (
struct V_5 * V_22 , struct V_86 * V_87 , unsigned int V_88 ,
enum V_77 V_78 , unsigned long V_66 , void * V_99 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_41 = V_2 -> V_41 ;
T_3 V_100 ;
if ( ! V_22 )
return NULL ;
F_18 ( ! V_2 -> V_59 ) ;
if ( V_41 < 0 || ! V_88 ) {
F_56 ( V_2 -> V_32 , L_11 ,
V_38 , V_88 , V_41 ) ;
return NULL ;
}
V_100 = V_8 -> V_100 ( V_2 ) ;
return F_41 ( V_2 , V_87 , V_88 , & V_100 ,
V_78 , V_66 ) ;
}
static int F_57 ( struct V_5 * V_22 , enum V_101 V_102 ,
unsigned long V_48 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_22 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_103 * V_104 ;
unsigned long V_66 ;
int V_35 ;
if ( ! V_22 )
return - V_45 ;
switch ( V_102 ) {
case V_105 :
F_29 ( & V_2 -> V_26 , V_66 ) ;
V_8 -> V_72 ( V_2 ) ;
if ( V_8 -> V_106 && ! F_8 ( & V_2 -> V_27 ) ) {
struct V_9 * V_19 = F_58 ( & V_2 -> V_27 ,
struct V_9 , V_30 ) ;
V_19 -> V_82 = V_8 -> V_106 ( V_2 , V_19 ) ;
}
F_34 ( & V_2 -> V_26 , V_66 ) ;
F_35 ( V_2 , true ) ;
break;
case V_107 :
if ( ! V_48 )
return - V_45 ;
V_104 = (struct V_103 * ) V_48 ;
V_35 = F_20 ( V_2 , V_104 -> V_41 ) ;
if ( V_35 < 0 )
return V_35 ;
break;
default:
return - V_108 ;
}
return 0 ;
}
static void F_59 ( struct V_5 * V_22 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
F_7 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_36 == V_39 )
F_1 ( V_2 ) ;
else
V_2 -> V_36 = V_42 ;
F_14 ( & V_2 -> V_26 ) ;
}
static enum V_109 F_60 ( struct V_5 * V_22 ,
T_1 V_24 ,
struct V_110 * V_111 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
enum V_109 V_112 ;
unsigned long V_66 ;
F_35 ( V_2 , false ) ;
F_29 ( & V_2 -> V_26 , V_66 ) ;
V_112 = F_61 ( V_22 , V_24 , V_111 ) ;
if ( V_112 != V_113 ) {
struct V_9 * V_10 ;
V_112 = V_114 ;
F_3 (sdesc, &schan->ld_queue, node)
if ( V_10 -> V_24 == V_24 ) {
V_112 = V_115 ;
break;
}
}
F_34 ( & V_2 -> V_26 , V_66 ) ;
return V_112 ;
}
bool F_62 ( struct V_3 * V_4 )
{
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_1 * V_2 ;
unsigned int V_116 = 0 ;
int V_52 ;
F_63 (schan, sdev, i) {
struct V_9 * V_10 ;
F_37 ( V_117 ) ;
if ( ! V_2 )
continue;
F_64 ( & V_2 -> V_26 ) ;
V_8 -> V_72 ( V_2 ) ;
F_38 ( & V_2 -> V_27 , & V_117 ) ;
if ( ! F_8 ( & V_117 ) ) {
F_12 ( V_2 -> V_32 , L_7 , V_2 -> V_33 ) ;
F_33 ( V_2 -> V_32 ) ;
}
V_2 -> V_36 = V_39 ;
F_65 ( & V_2 -> V_26 ) ;
F_3 (sdesc, &dl, node) {
struct V_15 * V_16 = & V_10 -> V_20 ;
V_10 -> V_12 = V_28 ;
if ( V_16 -> V_23 )
V_16 -> V_23 ( V_16 -> V_34 ) ;
}
F_64 ( & V_2 -> V_26 ) ;
F_48 ( & V_117 , & V_2 -> V_31 ) ;
F_65 ( & V_2 -> V_26 ) ;
V_116 ++ ;
}
return ! ! V_116 ;
}
static T_5 F_66 ( int V_118 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
T_5 V_35 ;
F_64 ( & V_2 -> V_26 ) ;
V_35 = V_8 -> F_66 ( V_2 , V_118 ) ? V_119 : V_120 ;
F_65 ( & V_2 -> V_26 ) ;
return V_35 ;
}
static T_5 F_67 ( int V_118 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
struct V_9 * V_10 ;
F_7 ( & V_2 -> V_26 ) ;
F_3 (sdesc, &schan->ld_queue, node) {
if ( V_10 -> V_12 == V_13 &&
V_8 -> V_121 ( V_2 , V_10 ) ) {
F_12 ( V_2 -> V_32 , L_12 ,
V_10 -> V_20 . V_24 , & V_10 -> V_20 ) ;
V_10 -> V_12 = V_67 ;
break;
}
}
F_1 ( V_2 ) ;
F_14 ( & V_2 -> V_26 ) ;
F_35 ( V_2 , false ) ;
return V_122 ;
}
int F_68 ( struct V_1 * V_2 , int V_118 ,
unsigned long V_66 , const char * V_123 )
{
int V_35 = F_69 ( V_118 , F_66 , F_67 ,
V_66 , V_123 , V_2 ) ;
V_2 -> V_118 = V_35 < 0 ? V_35 : V_118 ;
return V_35 ;
}
void F_70 ( struct V_1 * V_2 )
{
if ( V_2 -> V_118 >= 0 )
F_71 ( V_2 -> V_118 , V_2 ) ;
}
void F_72 ( struct V_3 * V_4 ,
struct V_1 * V_2 , int V_33 )
{
V_2 -> V_36 = V_39 ;
V_2 -> V_5 . V_6 = & V_4 -> V_124 ;
F_73 ( & V_2 -> V_5 ) ;
V_2 -> V_32 = V_4 -> V_124 . V_32 ;
V_2 -> V_33 = V_33 ;
if ( ! V_2 -> V_93 )
V_2 -> V_93 = V_125 ;
F_74 ( & V_2 -> V_26 ) ;
F_75 ( & V_2 -> V_27 ) ;
F_75 ( & V_2 -> V_31 ) ;
F_46 ( & V_2 -> V_5 . V_126 ,
& V_4 -> V_124 . V_127 ) ;
V_4 -> V_2 [ V_4 -> V_124 . V_128 ++ ] = V_2 ;
}
void F_76 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_5 . V_126 ) ;
}
int F_77 ( struct V_6 * V_32 , struct V_3 * V_4 ,
int V_129 )
{
struct V_130 * V_124 = & V_4 -> V_124 ;
if ( ! V_4 -> V_8 ||
! V_4 -> V_55 ||
! V_4 -> V_8 -> V_60 ||
! V_4 -> V_8 -> V_14 ||
! V_4 -> V_8 -> V_40 ||
! V_4 -> V_8 -> V_47 ||
! V_4 -> V_8 -> V_81 ||
! V_4 -> V_8 -> V_100 ||
! V_4 -> V_8 -> V_11 ||
! V_4 -> V_8 -> V_72 ||
! V_4 -> V_8 -> V_121 )
return - V_45 ;
V_4 -> V_2 = F_25 ( V_129 , sizeof( * V_4 -> V_2 ) , V_56 ) ;
if ( ! V_4 -> V_2 )
return - V_57 ;
F_75 ( & V_124 -> V_127 ) ;
V_124 -> V_131
= F_24 ;
V_124 -> V_132 = F_36 ;
V_124 -> V_133 = F_49 ;
V_124 -> V_134 = F_60 ;
V_124 -> V_135 = F_59 ;
V_124 -> V_136 = F_55 ;
V_124 -> V_137 = F_57 ;
V_124 -> V_32 = V_32 ;
return 0 ;
}
void F_78 ( struct V_3 * V_4 )
{
F_39 ( V_4 -> V_2 ) ;
}
static int T_6 F_79 ( void )
{
V_46 = F_80 ( F_43 ( V_44 , V_138 ) *
sizeof( long ) , V_56 ) ;
if ( ! V_46 )
return - V_57 ;
return 0 ;
}
static void T_7 F_81 ( void )
{
F_39 ( V_46 ) ;
}
