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
static int F_20 ( struct V_1 * V_2 , int V_41 ,
T_3 V_44 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_35 , V_45 ;
if ( V_2 -> V_32 -> V_46 ) {
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
return - V_29 ;
V_35 = V_8 -> V_48 ( V_2 , V_45 , V_44 , false ) ;
if ( V_35 < 0 ) {
F_22 ( V_41 , V_51 ) ;
return V_35 ;
}
V_2 -> V_41 = V_41 ;
return 0 ;
}
bool F_23 ( struct V_5 * V_22 , void * V_52 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_45 = ( long ) V_52 ;
int V_35 ;
if ( V_45 < 0 )
return true ;
if ( ! V_2 -> V_32 -> V_46 && V_45 >= V_49 )
return false ;
V_35 = V_8 -> V_48 ( V_2 , V_45 , 0 , true ) ;
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
struct V_53 * V_54 = V_22 -> V_55 ;
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
V_19 -> V_12 = V_28 ;
F_27 ( & V_19 -> V_30 , & V_2 -> V_31 ) ;
}
return V_58 ;
V_62:
if ( V_54 )
V_57:
F_22 ( V_54 -> V_41 , V_51 ) ;
V_22 -> V_55 = NULL ;
return V_35 ;
}
static T_2 F_28 ( struct V_1 * V_2 , bool V_66 )
{
struct V_9 * V_19 , * V_67 ;
bool V_68 = false ;
T_1 V_24 = 0 ;
T_2 V_23 = NULL ;
void * V_69 = NULL ;
unsigned long V_70 ;
F_29 ( & V_2 -> V_26 , V_70 ) ;
F_10 (desc, _desc, &schan->ld_queue, node) {
struct V_15 * V_16 = & V_19 -> V_20 ;
F_18 ( V_16 -> V_24 > 0 && V_16 -> V_24 != V_19 -> V_24 ) ;
F_18 ( V_19 -> V_12 != V_13 &&
V_19 -> V_12 != V_71 &&
V_19 -> V_12 != V_72 ) ;
if ( ! V_66 && V_19 -> V_12 == V_13 &&
V_19 -> V_24 != V_24 )
break;
if ( V_16 -> V_24 > 0 )
V_24 = V_16 -> V_24 ;
if ( V_19 -> V_12 == V_71 && V_19 -> V_73 == 1 ) {
if ( V_2 -> V_5 . V_74 != V_19 -> V_24 - 1 )
F_12 ( V_2 -> V_32 ,
L_4 ,
V_19 -> V_24 ,
V_2 -> V_5 . V_74 + 1 ) ;
V_2 -> V_5 . V_74 = V_19 -> V_24 ;
}
if ( V_19 -> V_12 == V_71 && V_16 -> V_23 ) {
V_19 -> V_12 = V_72 ;
V_23 = V_16 -> V_23 ;
V_69 = V_16 -> V_34 ;
F_12 ( V_2 -> V_32 , L_5 ,
V_16 -> V_24 , V_16 , V_2 -> V_33 ) ;
F_18 ( V_19 -> V_73 != 1 ) ;
break;
}
if ( V_16 -> V_24 > 0 || V_16 -> V_24 == - V_29 ) {
if ( V_19 -> V_12 == V_71 ) {
F_18 ( V_16 -> V_24 < 0 ) ;
V_19 -> V_12 = V_72 ;
}
V_68 = F_30 ( V_16 ) ;
} else {
switch ( V_19 -> V_12 ) {
case V_71 :
V_19 -> V_12 = V_72 ;
case V_72 :
if ( V_68 )
F_31 ( & V_19 -> V_20 ) ;
}
}
F_12 ( V_2 -> V_32 , L_6 ,
V_16 , V_16 -> V_24 ) ;
if ( ( ( V_19 -> V_12 == V_71 ||
V_19 -> V_12 == V_72 ) &&
F_30 ( & V_19 -> V_20 ) ) || V_66 ) {
V_19 -> V_12 = V_28 ;
F_32 ( & V_19 -> V_30 , & V_2 -> V_31 ) ;
if ( F_8 ( & V_2 -> V_27 ) ) {
F_12 ( V_2 -> V_32 , L_7 , V_2 -> V_33 ) ;
F_33 ( V_2 -> V_32 ) ;
V_2 -> V_36 = V_39 ;
}
}
}
if ( V_66 && ! V_23 )
V_2 -> V_5 . V_74 = V_2 -> V_5 . V_24 ;
F_34 ( & V_2 -> V_26 , V_70 ) ;
if ( V_23 )
V_23 ( V_69 ) ;
return V_23 ;
}
static void F_35 ( struct V_1 * V_2 , bool V_66 )
{
while ( F_28 ( V_2 , V_66 ) )
;
}
static void F_36 ( struct V_5 * V_22 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_22 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
F_37 ( V_75 ) ;
F_7 ( & V_2 -> V_26 ) ;
V_8 -> V_76 ( V_2 ) ;
F_14 ( & V_2 -> V_26 ) ;
if ( ! F_8 ( & V_2 -> V_27 ) )
F_35 ( V_2 , true ) ;
if ( V_2 -> V_41 >= 0 ) {
F_22 ( V_2 -> V_41 , V_51 ) ;
V_22 -> V_55 = NULL ;
}
F_7 ( & V_2 -> V_26 ) ;
F_38 ( & V_2 -> V_31 , & V_75 ) ;
V_2 -> V_63 = 0 ;
F_14 ( & V_2 -> V_26 ) ;
F_39 ( V_2 -> V_19 ) ;
}
static struct V_9 * F_40 ( struct V_1 * V_2 ,
unsigned long V_70 , T_3 * V_77 , T_3 * V_78 , T_4 * V_79 ,
struct V_9 * * V_80 , enum V_81 V_82 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_83 ;
T_4 V_84 = * V_79 ;
if ( ! V_84 )
return NULL ;
V_83 = F_17 ( V_2 ) ;
if ( ! V_83 ) {
F_15 ( V_2 -> V_32 , L_8 ) ;
return NULL ;
}
V_8 -> V_85 ( V_2 , V_83 , * V_78 , * V_77 , & V_84 ) ;
if ( ! * V_80 ) {
V_83 -> V_20 . V_24 = - V_29 ;
* V_80 = V_83 ;
} else {
V_83 -> V_20 . V_24 = - V_50 ;
}
F_12 ( V_2 -> V_32 ,
L_9 ,
V_84 , * V_79 , V_78 , V_77 , & V_83 -> V_20 ,
V_83 -> V_20 . V_24 ) ;
V_83 -> V_12 = V_43 ;
V_83 -> V_20 . V_70 = V_70 ;
V_83 -> V_82 = V_82 ;
V_83 -> V_86 = 0 ;
* V_79 -= V_84 ;
if ( V_82 == V_87 || V_82 == V_88 )
* V_78 += V_84 ;
if ( V_82 == V_87 || V_82 == V_89 )
* V_77 += V_84 ;
return V_83 ;
}
static struct V_15 * F_41 ( struct V_1 * V_2 ,
struct V_90 * V_91 , unsigned int V_92 , T_3 * V_93 ,
enum V_81 V_82 , unsigned long V_70 )
{
struct V_90 * V_94 ;
struct V_9 * V_80 = NULL , * V_83 = NULL ;
F_37 ( V_95 ) ;
int V_73 = 0 ;
unsigned long V_96 ;
int V_56 ;
F_42 (sgl, sg, sg_len, i)
V_73 += F_43 ( F_44 ( V_94 ) , V_2 -> V_97 ) ;
F_29 ( & V_2 -> V_26 , V_96 ) ;
F_42 (sgl, sg, sg_len, i) {
T_3 V_98 = F_45 ( V_94 ) ;
T_4 V_79 = F_44 ( V_94 ) ;
if ( ! V_79 )
goto V_99;
do {
F_12 ( V_2 -> V_32 , L_10 ,
V_56 , V_94 , V_79 , & V_98 ) ;
if ( V_82 == V_89 )
V_83 = F_40 ( V_2 , V_70 ,
& V_98 , V_93 , & V_79 , & V_80 ,
V_82 ) ;
else
V_83 = F_40 ( V_2 , V_70 ,
V_93 , & V_98 , & V_79 , & V_80 ,
V_82 ) ;
if ( ! V_83 )
goto V_99;
V_83 -> V_73 = V_73 -- ;
F_46 ( & V_83 -> V_30 , & V_95 ) ;
} while ( V_79 );
}
if ( V_83 != V_80 )
V_83 -> V_20 . V_24 = - V_100 ;
F_47 ( & V_95 , & V_2 -> V_31 ) ;
F_34 ( & V_2 -> V_26 , V_96 ) ;
return & V_80 -> V_20 ;
V_99:
F_3 (new, &tx_list, node)
V_83 -> V_12 = V_28 ;
F_48 ( & V_95 , & V_2 -> V_31 ) ;
F_34 ( & V_2 -> V_26 , V_96 ) ;
return NULL ;
}
static struct V_15 * F_49 (
struct V_5 * V_22 , T_3 V_101 , T_3 V_102 ,
T_4 V_79 , unsigned long V_70 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_90 V_94 ;
if ( ! V_22 || ! V_79 )
return NULL ;
F_18 ( ! V_2 -> V_63 ) ;
F_50 ( & V_94 , 1 ) ;
F_51 ( & V_94 , F_52 ( F_53 ( V_102 ) ) , V_79 ,
F_54 ( V_102 ) ) ;
F_45 ( & V_94 ) = V_102 ;
F_44 ( & V_94 ) = V_79 ;
return F_41 ( V_2 , & V_94 , 1 , & V_101 , V_87 , V_70 ) ;
}
static struct V_15 * F_55 (
struct V_5 * V_22 , struct V_90 * V_91 , unsigned int V_92 ,
enum V_81 V_82 , unsigned long V_70 , void * V_103 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
int V_41 = V_2 -> V_41 ;
T_3 V_44 ;
if ( ! V_22 )
return NULL ;
F_18 ( ! V_2 -> V_63 ) ;
if ( V_41 < 0 || ! V_92 ) {
F_56 ( V_2 -> V_32 , L_11 ,
V_38 , V_92 , V_41 ) ;
return NULL ;
}
V_44 = V_8 -> V_44 ( V_2 ) ;
return F_41 ( V_2 , V_91 , V_92 , & V_44 ,
V_82 , V_70 ) ;
}
static int F_57 ( struct V_5 * V_22 , enum V_104 V_105 ,
unsigned long V_52 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( V_22 -> V_6 ) ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_106 * V_107 ;
unsigned long V_70 ;
int V_35 ;
switch ( V_105 ) {
case V_108 :
F_29 ( & V_2 -> V_26 , V_70 ) ;
V_8 -> V_76 ( V_2 ) ;
if ( V_8 -> V_109 && ! F_8 ( & V_2 -> V_27 ) ) {
struct V_9 * V_19 = F_58 ( & V_2 -> V_27 ,
struct V_9 , V_30 ) ;
V_19 -> V_86 = V_8 -> V_109 ( V_2 , V_19 ) ;
}
F_34 ( & V_2 -> V_26 , V_70 ) ;
F_35 ( V_2 , true ) ;
break;
case V_110 :
if ( ! V_52 )
return - V_50 ;
V_107 = (struct V_106 * ) V_52 ;
V_35 = F_20 ( V_2 , V_107 -> V_41 ,
V_107 -> V_82 == V_89 ?
V_107 -> V_111 : V_107 -> V_112 ) ;
if ( V_35 < 0 )
return V_35 ;
break;
default:
return - V_113 ;
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
static enum V_114 F_60 ( struct V_5 * V_22 ,
T_1 V_24 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_6 ( V_22 ) ;
enum V_114 V_117 ;
unsigned long V_70 ;
F_35 ( V_2 , false ) ;
F_29 ( & V_2 -> V_26 , V_70 ) ;
V_117 = F_61 ( V_22 , V_24 , V_116 ) ;
if ( V_117 != V_118 ) {
struct V_9 * V_10 ;
V_117 = V_119 ;
F_3 (sdesc, &schan->ld_queue, node)
if ( V_10 -> V_24 == V_24 ) {
V_117 = V_120 ;
break;
}
}
F_34 ( & V_2 -> V_26 , V_70 ) ;
return V_117 ;
}
bool F_62 ( struct V_3 * V_4 )
{
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_1 * V_2 ;
unsigned int V_121 = 0 ;
int V_56 ;
F_63 (schan, sdev, i) {
struct V_9 * V_10 ;
F_37 ( V_122 ) ;
if ( ! V_2 )
continue;
F_64 ( & V_2 -> V_26 ) ;
V_8 -> V_76 ( V_2 ) ;
F_38 ( & V_2 -> V_27 , & V_122 ) ;
if ( ! F_8 ( & V_122 ) ) {
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
F_48 ( & V_122 , & V_2 -> V_31 ) ;
F_65 ( & V_2 -> V_26 ) ;
V_121 ++ ;
}
return ! ! V_121 ;
}
static T_5 F_66 ( int V_123 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
T_5 V_35 ;
F_64 ( & V_2 -> V_26 ) ;
V_35 = V_8 -> F_66 ( V_2 , V_123 ) ? V_124 : V_125 ;
F_65 ( & V_2 -> V_26 ) ;
return V_35 ;
}
static T_5 F_67 ( int V_123 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
const struct V_7 * V_8 =
F_2 ( V_2 -> V_5 . V_6 ) -> V_8 ;
struct V_9 * V_10 ;
F_7 ( & V_2 -> V_26 ) ;
F_3 (sdesc, &schan->ld_queue, node) {
if ( V_10 -> V_12 == V_13 &&
V_8 -> V_126 ( V_2 , V_10 ) ) {
F_12 ( V_2 -> V_32 , L_12 ,
V_10 -> V_20 . V_24 , & V_10 -> V_20 ) ;
V_10 -> V_12 = V_71 ;
break;
}
}
F_1 ( V_2 ) ;
F_14 ( & V_2 -> V_26 ) ;
F_35 ( V_2 , false ) ;
return V_127 ;
}
int F_68 ( struct V_1 * V_2 , int V_123 ,
unsigned long V_70 , const char * V_128 )
{
int V_35 = F_69 ( V_2 -> V_32 , V_123 , F_66 ,
F_67 , V_70 , V_128 , V_2 ) ;
V_2 -> V_123 = V_35 < 0 ? V_35 : V_123 ;
return V_35 ;
}
void F_70 ( struct V_3 * V_4 ,
struct V_1 * V_2 , int V_33 )
{
V_2 -> V_36 = V_39 ;
V_2 -> V_5 . V_6 = & V_4 -> V_129 ;
F_71 ( & V_2 -> V_5 ) ;
V_2 -> V_32 = V_4 -> V_129 . V_32 ;
V_2 -> V_33 = V_33 ;
if ( ! V_2 -> V_97 )
V_2 -> V_97 = V_130 ;
F_72 ( & V_2 -> V_26 ) ;
F_73 ( & V_2 -> V_27 ) ;
F_73 ( & V_2 -> V_31 ) ;
F_46 ( & V_2 -> V_5 . V_131 ,
& V_4 -> V_129 . V_132 ) ;
V_4 -> V_2 [ V_4 -> V_129 . V_133 ++ ] = V_2 ;
}
void F_74 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_5 . V_131 ) ;
}
int F_75 ( struct V_6 * V_32 , struct V_3 * V_4 ,
int V_134 )
{
struct V_135 * V_129 = & V_4 -> V_129 ;
if ( ! V_4 -> V_8 ||
! V_4 -> V_59 ||
! V_4 -> V_8 -> V_64 ||
! V_4 -> V_8 -> V_14 ||
! V_4 -> V_8 -> V_40 ||
! V_4 -> V_8 -> V_48 ||
! V_4 -> V_8 -> V_85 ||
! V_4 -> V_8 -> V_44 ||
! V_4 -> V_8 -> V_11 ||
! V_4 -> V_8 -> V_76 ||
! V_4 -> V_8 -> V_126 )
return - V_50 ;
V_4 -> V_2 = F_25 ( V_134 , sizeof( * V_4 -> V_2 ) , V_60 ) ;
if ( ! V_4 -> V_2 )
return - V_61 ;
F_73 ( & V_129 -> V_132 ) ;
V_129 -> V_136
= F_24 ;
V_129 -> V_137 = F_36 ;
V_129 -> V_138 = F_49 ;
V_129 -> V_139 = F_60 ;
V_129 -> V_140 = F_59 ;
V_129 -> V_141 = F_55 ;
V_129 -> V_142 = F_57 ;
V_129 -> V_32 = V_32 ;
return 0 ;
}
void F_76 ( struct V_3 * V_4 )
{
F_39 ( V_4 -> V_2 ) ;
}
static int T_6 F_77 ( void )
{
V_51 = F_78 ( F_43 ( V_49 , V_143 ) *
sizeof( long ) , V_60 ) ;
if ( ! V_51 )
return - V_61 ;
return 0 ;
}
static void T_7 F_79 ( void )
{
F_39 ( V_51 ) ;
}
