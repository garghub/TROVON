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
int V_35 , V_44 ;
if ( V_2 -> V_32 -> V_45 ) {
V_44 = V_2 -> V_46 ;
V_35 = V_8 -> V_47 ( V_2 , V_44 , true ) ;
if ( V_35 < 0 )
return V_35 ;
V_41 = V_2 -> V_41 ;
} else {
V_44 = V_41 ;
}
if ( V_41 < 0 || V_41 >= V_48 )
return - V_49 ;
if ( F_21 ( V_41 , V_50 ) )
return - V_29 ;
V_35 = V_8 -> V_47 ( V_2 , V_44 , false ) ;
if ( V_35 < 0 ) {
F_22 ( V_41 , V_50 ) ;
return V_35 ;
}
V_2 -> V_41 = V_41 ;
return 0 ;
}
bool F_23 ( struct V_5 * V_22 , void * V_51 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_44 = ( int ) V_51 ;
int V_35 ;
if ( V_44 < 0 )
return true ;
if ( ! V_2 -> V_32 -> V_45 && V_44 >= V_48 )
return false ;
V_35 = V_8 -> V_47 ( V_2 , V_44 , true ) ;
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
struct V_52 * V_53 = V_22 -> V_54 ;
int V_35 , V_55 ;
if ( V_53 ) {
V_35 = F_20 ( V_2 , V_53 -> V_41 ) ;
if ( V_35 < 0 )
goto V_56;
} else {
V_2 -> V_41 = - V_49 ;
}
V_2 -> V_19 = F_25 ( V_57 ,
V_4 -> V_58 , V_59 ) ;
if ( ! V_2 -> V_19 ) {
V_35 = - V_60 ;
goto V_61;
}
V_2 -> V_62 = V_57 ;
for ( V_55 = 0 ; V_55 < V_57 ; V_55 ++ ) {
V_19 = V_8 -> V_63 ( V_2 -> V_19 , V_55 ) ;
F_26 ( & V_19 -> V_20 ,
& V_2 -> V_5 ) ;
V_19 -> V_20 . V_64 = F_4 ;
V_19 -> V_12 = V_28 ;
F_27 ( & V_19 -> V_30 , & V_2 -> V_31 ) ;
}
return V_57 ;
V_61:
if ( V_53 )
V_56:
F_22 ( V_53 -> V_41 , V_50 ) ;
V_22 -> V_54 = NULL ;
return V_35 ;
}
static T_2 F_28 ( struct V_1 * V_2 , bool V_65 )
{
struct V_9 * V_19 , * V_66 ;
bool V_67 = false ;
T_1 V_24 = 0 ;
T_2 V_23 = NULL ;
void * V_68 = NULL ;
unsigned long V_69 ;
F_29 ( & V_2 -> V_26 , V_69 ) ;
F_10 (desc, _desc, &schan->ld_queue, node) {
struct V_15 * V_16 = & V_19 -> V_20 ;
F_18 ( V_16 -> V_24 > 0 && V_16 -> V_24 != V_19 -> V_24 ) ;
F_18 ( V_19 -> V_12 != V_13 &&
V_19 -> V_12 != V_70 &&
V_19 -> V_12 != V_71 ) ;
if ( ! V_65 && V_19 -> V_12 == V_13 &&
V_19 -> V_24 != V_24 )
break;
if ( V_16 -> V_24 > 0 )
V_24 = V_16 -> V_24 ;
if ( V_19 -> V_12 == V_70 && V_19 -> V_72 == 1 ) {
if ( V_2 -> V_5 . V_73 != V_19 -> V_24 - 1 )
F_12 ( V_2 -> V_32 ,
L_4 ,
V_19 -> V_24 ,
V_2 -> V_5 . V_73 + 1 ) ;
V_2 -> V_5 . V_73 = V_19 -> V_24 ;
}
if ( V_19 -> V_12 == V_70 && V_16 -> V_23 ) {
V_19 -> V_12 = V_71 ;
V_23 = V_16 -> V_23 ;
V_68 = V_16 -> V_34 ;
F_12 ( V_2 -> V_32 , L_5 ,
V_16 -> V_24 , V_16 , V_2 -> V_33 ) ;
F_18 ( V_19 -> V_72 != 1 ) ;
break;
}
if ( V_16 -> V_24 > 0 || V_16 -> V_24 == - V_29 ) {
if ( V_19 -> V_12 == V_70 ) {
F_18 ( V_16 -> V_24 < 0 ) ;
V_19 -> V_12 = V_71 ;
}
V_67 = F_30 ( V_16 ) ;
} else {
switch ( V_19 -> V_12 ) {
case V_70 :
V_19 -> V_12 = V_71 ;
case V_71 :
if ( V_67 )
F_31 ( & V_19 -> V_20 ) ;
}
}
F_12 ( V_2 -> V_32 , L_6 ,
V_16 , V_16 -> V_24 ) ;
if ( ( ( V_19 -> V_12 == V_70 ||
V_19 -> V_12 == V_71 ) &&
F_30 ( & V_19 -> V_20 ) ) || V_65 ) {
V_19 -> V_12 = V_28 ;
F_32 ( & V_19 -> V_30 , & V_2 -> V_31 ) ;
if ( F_8 ( & V_2 -> V_27 ) ) {
F_12 ( V_2 -> V_32 , L_7 , V_2 -> V_33 ) ;
F_33 ( V_2 -> V_32 ) ;
V_2 -> V_36 = V_39 ;
}
}
}
if ( V_65 && ! V_23 )
V_2 -> V_5 . V_73 = V_2 -> V_5 . V_24 ;
F_34 ( & V_2 -> V_26 , V_69 ) ;
if ( V_23 )
V_23 ( V_68 ) ;
return V_23 ;
}
static void F_35 ( struct V_1 * V_2 , bool V_65 )
{
while ( F_28 ( V_2 , V_65 ) )
;
}
static void F_36 ( struct V_5 * V_22 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_22 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
F_37 ( V_74 ) ;
F_7 ( & V_2 -> V_26 ) ;
V_8 -> V_75 ( V_2 ) ;
F_14 ( & V_2 -> V_26 ) ;
if ( ! F_8 ( & V_2 -> V_27 ) )
F_35 ( V_2 , true ) ;
if ( V_2 -> V_41 >= 0 ) {
F_22 ( V_2 -> V_41 , V_50 ) ;
V_22 -> V_54 = NULL ;
}
F_7 ( & V_2 -> V_26 ) ;
F_38 ( & V_2 -> V_31 , & V_74 ) ;
V_2 -> V_62 = 0 ;
F_14 ( & V_2 -> V_26 ) ;
F_39 ( V_2 -> V_19 ) ;
}
static struct V_9 * F_40 ( struct V_1 * V_2 ,
unsigned long V_69 , T_3 * V_76 , T_3 * V_77 , T_4 * V_78 ,
struct V_9 * * V_79 , enum V_80 V_81 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_82 ;
T_4 V_83 = * V_78 ;
if ( ! V_83 )
return NULL ;
V_82 = F_17 ( V_2 ) ;
if ( ! V_82 ) {
F_15 ( V_2 -> V_32 , L_8 ) ;
return NULL ;
}
V_8 -> V_84 ( V_2 , V_82 , * V_77 , * V_76 , & V_83 ) ;
if ( ! * V_79 ) {
V_82 -> V_20 . V_24 = - V_29 ;
* V_79 = V_82 ;
} else {
V_82 -> V_20 . V_24 = - V_49 ;
}
F_12 ( V_2 -> V_32 ,
L_9 ,
V_83 , * V_78 , * V_77 , * V_76 , & V_82 -> V_20 ,
V_82 -> V_20 . V_24 ) ;
V_82 -> V_12 = V_43 ;
V_82 -> V_20 . V_69 = V_69 ;
V_82 -> V_81 = V_81 ;
V_82 -> V_85 = 0 ;
* V_78 -= V_83 ;
if ( V_81 == V_86 || V_81 == V_87 )
* V_77 += V_83 ;
if ( V_81 == V_86 || V_81 == V_88 )
* V_76 += V_83 ;
return V_82 ;
}
static struct V_15 * F_41 ( struct V_1 * V_2 ,
struct V_89 * V_90 , unsigned int V_91 , T_3 * V_92 ,
enum V_80 V_81 , unsigned long V_69 )
{
struct V_89 * V_93 ;
struct V_9 * V_79 = NULL , * V_82 = NULL ;
F_37 ( V_94 ) ;
int V_72 = 0 ;
unsigned long V_95 ;
int V_55 ;
F_42 (sgl, sg, sg_len, i)
V_72 += F_43 ( F_44 ( V_93 ) , V_2 -> V_96 ) ;
F_29 ( & V_2 -> V_26 , V_95 ) ;
F_42 (sgl, sg, sg_len, i) {
T_3 V_97 = F_45 ( V_93 ) ;
T_4 V_78 = F_44 ( V_93 ) ;
if ( ! V_78 )
goto V_98;
do {
F_12 ( V_2 -> V_32 , L_10 ,
V_55 , V_93 , V_78 , ( unsigned long long ) V_97 ) ;
if ( V_81 == V_88 )
V_82 = F_40 ( V_2 , V_69 ,
& V_97 , V_92 , & V_78 , & V_79 ,
V_81 ) ;
else
V_82 = F_40 ( V_2 , V_69 ,
V_92 , & V_97 , & V_78 , & V_79 ,
V_81 ) ;
if ( ! V_82 )
goto V_98;
V_82 -> V_72 = V_72 -- ;
F_46 ( & V_82 -> V_30 , & V_94 ) ;
} while ( V_78 );
}
if ( V_82 != V_79 )
V_82 -> V_20 . V_24 = - V_99 ;
F_47 ( & V_94 , & V_2 -> V_31 ) ;
F_34 ( & V_2 -> V_26 , V_95 ) ;
return & V_79 -> V_20 ;
V_98:
F_3 (new, &tx_list, node)
V_82 -> V_12 = V_28 ;
F_48 ( & V_94 , & V_2 -> V_31 ) ;
F_34 ( & V_2 -> V_26 , V_95 ) ;
return NULL ;
}
static struct V_15 * F_49 (
struct V_5 * V_22 , T_3 V_100 , T_3 V_101 ,
T_4 V_78 , unsigned long V_69 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_89 V_93 ;
if ( ! V_22 || ! V_78 )
return NULL ;
F_18 ( ! V_2 -> V_62 ) ;
F_50 ( & V_93 , 1 ) ;
F_51 ( & V_93 , F_52 ( F_53 ( V_101 ) ) , V_78 ,
F_54 ( V_101 ) ) ;
F_45 ( & V_93 ) = V_101 ;
F_44 ( & V_93 ) = V_78 ;
return F_41 ( V_2 , & V_93 , 1 , & V_100 , V_86 , V_69 ) ;
}
static struct V_15 * F_55 (
struct V_5 * V_22 , struct V_89 * V_90 , unsigned int V_91 ,
enum V_80 V_81 , unsigned long V_69 , void * V_102 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_41 = V_2 -> V_41 ;
T_3 V_103 ;
if ( ! V_22 )
return NULL ;
F_18 ( ! V_2 -> V_62 ) ;
if ( V_41 < 0 || ! V_91 ) {
F_56 ( V_2 -> V_32 , L_11 ,
V_38 , V_91 , V_41 ) ;
return NULL ;
}
V_103 = V_8 -> V_103 ( V_2 ) ;
return F_41 ( V_2 , V_90 , V_91 , & V_103 ,
V_81 , V_69 ) ;
}
static int F_57 ( struct V_5 * V_22 , enum V_104 V_105 ,
unsigned long V_51 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_22 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_106 * V_107 ;
unsigned long V_69 ;
int V_35 ;
switch ( V_105 ) {
case V_108 :
F_29 ( & V_2 -> V_26 , V_69 ) ;
V_8 -> V_75 ( V_2 ) ;
if ( V_8 -> V_109 && ! F_8 ( & V_2 -> V_27 ) ) {
struct V_9 * V_19 = F_58 ( & V_2 -> V_27 ,
struct V_9 , V_30 ) ;
V_19 -> V_85 = V_8 -> V_109 ( V_2 , V_19 ) ;
}
F_34 ( & V_2 -> V_26 , V_69 ) ;
F_35 ( V_2 , true ) ;
break;
case V_110 :
if ( ! V_51 )
return - V_49 ;
V_107 = (struct V_106 * ) V_51 ;
V_35 = F_20 ( V_2 , V_107 -> V_41 ) ;
if ( V_35 < 0 )
return V_35 ;
break;
default:
return - V_111 ;
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
static enum V_112 F_60 ( struct V_5 * V_22 ,
T_1 V_24 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
enum V_112 V_115 ;
unsigned long V_69 ;
F_35 ( V_2 , false ) ;
F_29 ( & V_2 -> V_26 , V_69 ) ;
V_115 = F_61 ( V_22 , V_24 , V_114 ) ;
if ( V_115 != V_116 ) {
struct V_9 * V_10 ;
V_115 = V_117 ;
F_3 (sdesc, &schan->ld_queue, node)
if ( V_10 -> V_24 == V_24 ) {
V_115 = V_118 ;
break;
}
}
F_34 ( & V_2 -> V_26 , V_69 ) ;
return V_115 ;
}
bool F_62 ( struct V_3 * V_4 )
{
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_1 * V_2 ;
unsigned int V_119 = 0 ;
int V_55 ;
F_63 (schan, sdev, i) {
struct V_9 * V_10 ;
F_37 ( V_120 ) ;
if ( ! V_2 )
continue;
F_64 ( & V_2 -> V_26 ) ;
V_8 -> V_75 ( V_2 ) ;
F_38 ( & V_2 -> V_27 , & V_120 ) ;
if ( ! F_8 ( & V_120 ) ) {
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
F_48 ( & V_120 , & V_2 -> V_31 ) ;
F_65 ( & V_2 -> V_26 ) ;
V_119 ++ ;
}
return ! ! V_119 ;
}
static T_5 F_66 ( int V_121 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
T_5 V_35 ;
F_64 ( & V_2 -> V_26 ) ;
V_35 = V_8 -> F_66 ( V_2 , V_121 ) ? V_122 : V_123 ;
F_65 ( & V_2 -> V_26 ) ;
return V_35 ;
}
static T_5 F_67 ( int V_121 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
struct V_9 * V_10 ;
F_7 ( & V_2 -> V_26 ) ;
F_3 (sdesc, &schan->ld_queue, node) {
if ( V_10 -> V_12 == V_13 &&
V_8 -> V_124 ( V_2 , V_10 ) ) {
F_12 ( V_2 -> V_32 , L_12 ,
V_10 -> V_20 . V_24 , & V_10 -> V_20 ) ;
V_10 -> V_12 = V_70 ;
break;
}
}
F_1 ( V_2 ) ;
F_14 ( & V_2 -> V_26 ) ;
F_35 ( V_2 , false ) ;
return V_125 ;
}
int F_68 ( struct V_1 * V_2 , int V_121 ,
unsigned long V_69 , const char * V_126 )
{
int V_35 = F_69 ( V_121 , F_66 , F_67 ,
V_69 , V_126 , V_2 ) ;
V_2 -> V_121 = V_35 < 0 ? V_35 : V_121 ;
return V_35 ;
}
void F_70 ( struct V_1 * V_2 )
{
if ( V_2 -> V_121 >= 0 )
F_71 ( V_2 -> V_121 , V_2 ) ;
}
void F_72 ( struct V_3 * V_4 ,
struct V_1 * V_2 , int V_33 )
{
V_2 -> V_36 = V_39 ;
V_2 -> V_5 . V_6 = & V_4 -> V_127 ;
F_73 ( & V_2 -> V_5 ) ;
V_2 -> V_32 = V_4 -> V_127 . V_32 ;
V_2 -> V_33 = V_33 ;
if ( ! V_2 -> V_96 )
V_2 -> V_96 = V_128 ;
F_74 ( & V_2 -> V_26 ) ;
F_75 ( & V_2 -> V_27 ) ;
F_75 ( & V_2 -> V_31 ) ;
F_46 ( & V_2 -> V_5 . V_129 ,
& V_4 -> V_127 . V_130 ) ;
V_4 -> V_2 [ V_4 -> V_127 . V_131 ++ ] = V_2 ;
}
void F_76 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_5 . V_129 ) ;
}
int F_77 ( struct V_6 * V_32 , struct V_3 * V_4 ,
int V_132 )
{
struct V_133 * V_127 = & V_4 -> V_127 ;
if ( ! V_4 -> V_8 ||
! V_4 -> V_58 ||
! V_4 -> V_8 -> V_63 ||
! V_4 -> V_8 -> V_14 ||
! V_4 -> V_8 -> V_40 ||
! V_4 -> V_8 -> V_47 ||
! V_4 -> V_8 -> V_84 ||
! V_4 -> V_8 -> V_103 ||
! V_4 -> V_8 -> V_11 ||
! V_4 -> V_8 -> V_75 ||
! V_4 -> V_8 -> V_124 )
return - V_49 ;
V_4 -> V_2 = F_25 ( V_132 , sizeof( * V_4 -> V_2 ) , V_59 ) ;
if ( ! V_4 -> V_2 )
return - V_60 ;
F_75 ( & V_127 -> V_130 ) ;
V_127 -> V_134
= F_24 ;
V_127 -> V_135 = F_36 ;
V_127 -> V_136 = F_49 ;
V_127 -> V_137 = F_60 ;
V_127 -> V_138 = F_59 ;
V_127 -> V_139 = F_55 ;
V_127 -> V_140 = F_57 ;
V_127 -> V_32 = V_32 ;
return 0 ;
}
void F_78 ( struct V_3 * V_4 )
{
F_39 ( V_4 -> V_2 ) ;
}
static int T_6 F_79 ( void )
{
V_50 = F_80 ( F_43 ( V_48 , V_141 ) *
sizeof( long ) , V_59 ) ;
if ( ! V_50 )
return - V_60 ;
return 0 ;
}
static void T_7 F_81 ( void )
{
F_39 ( V_50 ) ;
}
