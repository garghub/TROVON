static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_6 * V_7 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_7 -> V_2 -> V_5 + V_7 -> V_8 + V_3 ) ;
}
static inline T_1 F_6 ( struct V_6 * V_7 , T_1 V_3 )
{
return F_4 ( V_7 -> V_2 -> V_5 + V_7 -> V_8 + V_3 ) ;
}
static inline struct V_6 * F_7 ( struct V_9 * V_10 )
{
return F_8 ( V_10 , struct V_6 , V_9 ) ;
}
static inline struct V_11 * F_9 (
struct V_12 * V_13 )
{
return F_8 ( V_13 , struct V_11 , V_14 ) ;
}
static inline struct V_15 * F_10 ( struct V_6 * V_7 )
{
return & V_7 -> V_9 . V_16 -> V_15 ;
}
static struct V_11 * F_11 (
struct V_6 * V_7 )
{
struct V_11 * V_17 ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
F_13 (dma_desc, &tdc->free_dma_desc, node) {
if ( F_14 ( & V_17 -> V_14 ) ) {
F_15 ( & V_17 -> V_20 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_17 ;
}
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
V_17 = F_17 ( sizeof( * V_17 ) , V_21 ) ;
if ( ! V_17 ) {
F_18 ( F_10 ( V_7 ) , L_1 ) ;
return NULL ;
}
F_19 ( & V_17 -> V_14 , & V_7 -> V_9 ) ;
V_17 -> V_14 . V_22 = V_23 ;
V_17 -> V_14 . V_18 = 0 ;
return V_17 ;
}
static void F_20 ( struct V_6 * V_7 ,
struct V_11 * V_17 )
{
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( ! F_21 ( & V_17 -> V_24 ) )
F_22 ( & V_17 -> V_24 , & V_7 -> V_25 ) ;
F_23 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static struct V_27 * F_24 (
struct V_6 * V_7 )
{
struct V_27 * V_28 = NULL ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( ! F_21 ( & V_7 -> V_25 ) ) {
V_28 = F_25 ( & V_7 -> V_25 ,
F_26 ( * V_28 ) , V_20 ) ;
F_15 ( & V_28 -> V_20 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_28 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
V_28 = F_17 ( sizeof( struct V_27 ) , V_21 ) ;
if ( ! V_28 )
F_18 ( F_10 ( V_7 ) , L_2 ) ;
return V_28 ;
}
static int F_27 ( struct V_9 * V_10 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
if ( ! F_21 ( & V_7 -> V_31 ) ) {
F_18 ( F_10 ( V_7 ) , L_3 ) ;
return - V_32 ;
}
memcpy ( & V_7 -> V_33 , V_30 , sizeof( * V_30 ) ) ;
V_7 -> V_34 = true ;
return 0 ;
}
static void F_28 ( struct V_6 * V_7 ,
bool V_35 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_29 ( & V_2 -> V_36 ) ;
F_1 ( V_2 , V_37 , 0 ) ;
if ( V_35 )
F_30 ( V_38 ) ;
}
static void F_31 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_1 ( V_2 , V_37 , V_39 ) ;
F_32 ( & V_2 -> V_36 ) ;
}
static void F_33 ( struct V_6 * V_7 )
{
T_1 V_40 ;
T_1 V_41 ;
V_40 = F_6 ( V_7 , V_42 ) ;
V_40 &= ~ V_43 ;
F_5 ( V_7 , V_42 , V_40 ) ;
V_40 &= ~ V_44 ;
F_5 ( V_7 , V_42 , V_40 ) ;
V_41 = F_6 ( V_7 , V_45 ) ;
if ( V_41 & V_46 ) {
F_34 ( F_10 ( V_7 ) , L_4 , V_47 ) ;
F_5 ( V_7 , V_45 , V_41 ) ;
}
V_7 -> V_48 = false ;
}
static void F_35 ( struct V_6 * V_7 ,
struct V_27 * V_28 )
{
struct V_49 * V_50 = & V_28 -> V_50 ;
F_5 ( V_7 , V_42 , V_50 -> V_40 ) ;
F_5 ( V_7 , V_51 , V_50 -> V_52 ) ;
F_5 ( V_7 , V_53 , V_50 -> V_54 ) ;
F_5 ( V_7 , V_55 , V_50 -> V_56 ) ;
F_5 ( V_7 , V_57 , V_50 -> V_58 ) ;
F_5 ( V_7 , V_42 ,
V_50 -> V_40 | V_44 ) ;
}
static void F_36 ( struct V_6 * V_7 ,
struct V_27 * V_59 )
{
unsigned long V_41 ;
F_28 ( V_7 , false ) ;
V_41 = F_6 ( V_7 , V_45 ) ;
if ( V_41 & V_46 ) {
F_18 ( F_10 ( V_7 ) ,
L_5 ) ;
F_31 ( V_7 ) ;
return;
}
F_5 ( V_7 , V_53 , V_59 -> V_50 . V_54 ) ;
F_5 ( V_7 , V_57 , V_59 -> V_50 . V_58 ) ;
F_5 ( V_7 , V_42 ,
V_59 -> V_50 . V_40 | V_44 ) ;
V_59 -> V_60 = true ;
F_31 ( V_7 ) ;
}
static void F_37 ( struct V_6 * V_7 )
{
struct V_27 * V_28 ;
if ( F_21 ( & V_7 -> V_31 ) )
return;
V_28 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_28 ) , V_20 ) ;
F_35 ( V_7 , V_28 ) ;
V_28 -> V_60 = true ;
V_7 -> V_48 = true ;
}
static void F_38 ( struct V_6 * V_7 )
{
struct V_27 * V_61 ;
struct V_27 * V_62 ;
if ( F_21 ( & V_7 -> V_31 ) )
return;
V_61 = F_25 ( & V_7 -> V_31 , F_26 ( * V_61 ) , V_20 ) ;
if ( ! F_39 ( & V_61 -> V_20 , & V_7 -> V_31 ) ) {
V_62 = F_25 ( & V_61 -> V_20 ,
F_26 ( * V_62 ) , V_20 ) ;
F_36 ( V_7 , V_62 ) ;
}
}
static inline int F_40 ( struct V_6 * V_7 ,
struct V_27 * V_28 , unsigned long V_41 )
{
return V_28 -> V_63 - ( V_41 & V_64 ) - 4 ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_27 * V_65 ;
struct V_11 * V_17 ;
while ( ! F_21 ( & V_7 -> V_31 ) ) {
V_65 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_65 ) , V_20 ) ;
F_15 ( & V_65 -> V_20 ) ;
F_23 ( & V_65 -> V_20 , & V_7 -> V_25 ) ;
if ( V_65 -> V_66 ) {
V_17 = V_65 -> V_17 ;
V_17 -> V_67 = V_68 ;
F_23 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
if ( ! V_17 -> V_69 )
F_23 ( & V_17 -> V_70 ,
& V_7 -> V_71 ) ;
V_17 -> V_69 ++ ;
}
}
V_7 -> V_72 = NULL ;
}
static bool F_42 ( struct V_6 * V_7 ,
struct V_27 * V_73 , bool V_74 )
{
struct V_27 * V_61 = NULL ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_18 ( F_10 ( V_7 ) , L_6 ) ;
F_33 ( V_7 ) ;
return false ;
}
V_61 = F_25 ( & V_7 -> V_31 , F_26 ( * V_61 ) , V_20 ) ;
if ( ! V_61 -> V_60 ) {
F_33 ( V_7 ) ;
F_18 ( F_10 ( V_7 ) , L_7 ) ;
F_41 ( V_7 ) ;
return false ;
}
if ( ! V_74 )
F_38 ( V_7 ) ;
return true ;
}
static void F_43 ( struct V_6 * V_7 ,
bool V_74 )
{
struct V_27 * V_65 ;
struct V_11 * V_17 ;
V_7 -> V_48 = false ;
V_65 = F_25 ( & V_7 -> V_31 , F_26 ( * V_65 ) , V_20 ) ;
V_17 = V_65 -> V_17 ;
V_17 -> V_75 += V_65 -> V_63 ;
F_15 ( & V_65 -> V_20 ) ;
if ( V_65 -> V_66 ) {
V_17 -> V_67 = V_76 ;
F_44 ( & V_17 -> V_14 ) ;
if ( ! V_17 -> V_69 )
F_23 ( & V_17 -> V_70 , & V_7 -> V_71 ) ;
V_17 -> V_69 ++ ;
F_23 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
}
F_23 ( & V_65 -> V_20 , & V_7 -> V_25 ) ;
if ( V_74 || F_21 ( & V_7 -> V_31 ) )
return;
F_37 ( V_7 ) ;
return;
}
static void F_45 ( struct V_6 * V_7 ,
bool V_74 )
{
struct V_27 * V_65 ;
struct V_11 * V_17 ;
bool V_77 ;
V_65 = F_25 ( & V_7 -> V_31 , F_26 ( * V_65 ) , V_20 ) ;
V_17 = V_65 -> V_17 ;
V_17 -> V_75 += V_65 -> V_63 ;
if ( ! V_17 -> V_69 )
F_23 ( & V_17 -> V_70 , & V_7 -> V_71 ) ;
V_17 -> V_69 ++ ;
if ( ! F_39 ( & V_65 -> V_20 , & V_7 -> V_31 ) ) {
F_15 ( & V_65 -> V_20 ) ;
F_23 ( & V_65 -> V_20 , & V_7 -> V_31 ) ;
V_65 -> V_60 = false ;
V_77 = F_42 ( V_7 , V_65 , V_74 ) ;
if ( ! V_77 )
V_17 -> V_67 = V_68 ;
}
return;
}
static void F_46 ( unsigned long V_78 )
{
struct V_6 * V_7 = (struct V_6 * ) V_78 ;
T_2 V_79 = NULL ;
void * V_80 = NULL ;
struct V_11 * V_17 ;
unsigned long V_18 ;
int V_69 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
while ( ! F_21 ( & V_7 -> V_71 ) ) {
V_17 = F_25 ( & V_7 -> V_71 ,
F_26 ( * V_17 ) , V_70 ) ;
F_15 ( & V_17 -> V_70 ) ;
V_79 = V_17 -> V_14 . V_79 ;
V_80 = V_17 -> V_14 . V_80 ;
V_69 = V_17 -> V_69 ;
V_17 -> V_69 = 0 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
while ( V_69 -- && V_79 )
V_79 ( V_80 ) ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static T_3 F_47 ( int V_81 , void * V_82 )
{
struct V_6 * V_7 = V_82 ;
unsigned long V_41 ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
V_41 = F_6 ( V_7 , V_45 ) ;
if ( V_41 & V_46 ) {
F_5 ( V_7 , V_45 , V_41 ) ;
V_7 -> V_72 ( V_7 , false ) ;
F_48 ( & V_7 -> V_83 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_84 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
F_49 ( F_10 ( V_7 ) ,
L_8 , V_41 ) ;
return V_85 ;
}
static T_4 V_23 ( struct V_12 * V_14 )
{
struct V_11 * V_17 = F_9 ( V_14 ) ;
struct V_6 * V_7 = F_7 ( V_14 -> V_86 ) ;
unsigned long V_18 ;
T_4 V_87 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
V_17 -> V_67 = V_88 ;
V_87 = F_50 ( & V_17 -> V_14 ) ;
F_51 ( & V_17 -> V_24 , & V_7 -> V_31 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_87 ;
}
static void F_52 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_18 ( F_10 ( V_7 ) , L_9 ) ;
goto V_89;
}
if ( ! V_7 -> V_48 ) {
F_37 ( V_7 ) ;
if ( V_7 -> V_90 ) {
F_30 ( V_38 ) ;
F_38 ( V_7 ) ;
}
}
V_89:
F_16 ( & V_7 -> V_19 , V_18 ) ;
return;
}
static void F_53 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_27 * V_65 ;
struct V_11 * V_17 ;
unsigned long V_18 ;
unsigned long V_41 ;
bool V_91 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_16 ( & V_7 -> V_19 , V_18 ) ;
return;
}
if ( ! V_7 -> V_48 )
goto V_92;
F_28 ( V_7 , true ) ;
V_41 = F_6 ( V_7 , V_45 ) ;
if ( V_41 & V_46 ) {
F_34 ( F_10 ( V_7 ) , L_10 , V_47 ) ;
V_7 -> V_72 ( V_7 , true ) ;
V_41 = F_6 ( V_7 , V_45 ) ;
}
V_91 = V_7 -> V_48 ;
F_33 ( V_7 ) ;
if ( ! F_21 ( & V_7 -> V_31 ) && V_91 ) {
V_65 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_65 ) , V_20 ) ;
V_65 -> V_17 -> V_75 +=
F_40 ( V_7 , V_65 , V_41 ) ;
}
F_31 ( V_7 ) ;
V_92:
F_41 ( V_7 ) ;
while ( ! F_21 ( & V_7 -> V_71 ) ) {
V_17 = F_25 ( & V_7 -> V_71 ,
F_26 ( * V_17 ) , V_70 ) ;
F_15 ( & V_17 -> V_70 ) ;
V_17 -> V_69 = 0 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static enum V_67 F_54 ( struct V_9 * V_10 ,
T_4 V_87 , struct V_93 * V_94 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 ;
struct V_27 * V_28 ;
enum V_67 V_95 ;
unsigned long V_18 ;
unsigned int V_96 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
V_95 = F_55 ( V_10 , V_87 , V_94 ) ;
if ( V_95 == V_76 ) {
F_56 ( V_94 , 0 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_95 ;
}
F_13 (dma_desc, &tdc->free_dma_desc, node) {
if ( V_17 -> V_14 . V_87 == V_87 ) {
V_96 = V_17 -> V_97 -
( V_17 -> V_75 %
V_17 -> V_97 ) ;
F_56 ( V_94 , V_96 ) ;
V_95 = V_17 -> V_67 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_95 ;
}
}
F_13 (sg_req, &tdc->pending_sg_req, node) {
V_17 = V_28 -> V_17 ;
if ( V_17 -> V_14 . V_87 == V_87 ) {
V_96 = V_17 -> V_97 -
( V_17 -> V_75 %
V_17 -> V_97 ) ;
F_56 ( V_94 , V_96 ) ;
V_95 = V_17 -> V_67 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_95 ;
}
}
F_34 ( F_10 ( V_7 ) , L_11 , V_87 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_95 ;
}
static int F_57 ( struct V_9 * V_10 , enum V_98 V_99 ,
unsigned long V_100 )
{
switch ( V_99 ) {
case V_101 :
return F_27 ( V_10 ,
(struct V_29 * ) V_100 ) ;
case V_102 :
F_53 ( V_10 ) ;
return 0 ;
default:
break;
}
return - V_103 ;
}
static inline int F_58 ( struct V_6 * V_7 ,
enum V_104 V_105 )
{
switch ( V_105 ) {
case V_106 :
return V_107 ;
case V_108 :
return V_109 ;
case V_110 :
return V_111 ;
case V_112 :
return V_113 ;
default:
F_59 ( F_10 ( V_7 ) ,
L_12 ) ;
return V_111 ;
}
}
static inline int F_60 ( struct V_6 * V_7 ,
T_1 V_114 , enum V_104 V_105 , int V_115 )
{
int V_116 ;
int V_117 ;
V_116 = V_114 * V_105 ;
V_117 = V_116 / 4 ;
if ( ! V_117 ) {
if ( V_115 & 0xF )
return V_118 ;
else if ( ( V_115 >> 4 ) & 0x1 )
return V_119 ;
else
return V_120 ;
}
if ( V_117 < 4 )
return V_118 ;
else if ( V_117 < 8 )
return V_119 ;
else
return V_120 ;
}
static int F_61 ( struct V_6 * V_7 ,
enum V_121 V_122 , unsigned long * V_123 ,
unsigned long * V_52 , unsigned long * V_40 , unsigned int * V_114 ,
enum V_104 * V_105 )
{
switch ( V_122 ) {
case V_124 :
* V_123 = V_7 -> V_33 . V_125 ;
* V_52 = F_58 ( V_7 , V_7 -> V_33 . V_126 ) ;
* V_114 = V_7 -> V_33 . V_127 ;
* V_105 = V_7 -> V_33 . V_126 ;
* V_40 = V_128 ;
return 0 ;
case V_129 :
* V_123 = V_7 -> V_33 . V_130 ;
* V_52 = F_58 ( V_7 , V_7 -> V_33 . V_131 ) ;
* V_114 = V_7 -> V_33 . V_132 ;
* V_105 = V_7 -> V_33 . V_131 ;
* V_40 = 0 ;
return 0 ;
default:
F_18 ( F_10 ( V_7 ) , L_13 ) ;
return - V_133 ;
}
return - V_133 ;
}
static struct V_12 * F_62 (
struct V_9 * V_10 , struct V_134 * V_135 , unsigned int V_136 ,
enum V_121 V_122 , unsigned long V_18 ,
void * V_137 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 ;
unsigned int V_138 ;
struct V_134 * V_139 ;
unsigned long V_40 , V_56 , V_54 , V_52 ;
struct V_140 V_141 ;
struct V_27 * V_28 = NULL ;
T_1 V_114 ;
enum V_104 V_105 ;
int V_95 ;
if ( ! V_7 -> V_34 ) {
F_18 ( F_10 ( V_7 ) , L_14 ) ;
return NULL ;
}
if ( V_136 < 1 ) {
F_18 ( F_10 ( V_7 ) , L_15 , V_136 ) ;
return NULL ;
}
V_95 = F_61 ( V_7 , V_122 , & V_54 , & V_52 , & V_40 ,
& V_114 , & V_105 ) ;
if ( V_95 < 0 )
return NULL ;
F_63 ( & V_141 ) ;
V_56 = V_142 ;
V_56 |= V_143 <<
V_144 ;
V_56 |= V_145 ;
V_40 |= V_146 | V_147 ;
V_40 |= V_7 -> V_33 . V_148 << V_149 ;
if ( V_18 & V_150 )
V_40 |= V_43 ;
V_52 |= V_151 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_18 ( F_10 ( V_7 ) , L_16 ) ;
return NULL ;
}
F_63 ( & V_17 -> V_24 ) ;
F_63 ( & V_17 -> V_70 ) ;
V_17 -> V_69 = 0 ;
V_17 -> V_97 = 0 ;
V_17 -> V_75 = 0 ;
V_17 -> V_67 = V_88 ;
F_64 (sgl, sg, sg_len, i) {
T_1 V_115 , V_152 ;
V_152 = F_65 ( V_139 ) ;
V_115 = F_66 ( V_139 ) ;
if ( ( V_115 & 3 ) || ( V_152 & 3 ) ||
( V_115 > V_7 -> V_2 -> V_153 -> V_154 ) ) {
F_18 ( F_10 ( V_7 ) ,
L_17 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
V_28 = F_24 ( V_7 ) ;
if ( ! V_28 ) {
F_18 ( F_10 ( V_7 ) , L_18 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
V_56 |= F_60 ( V_7 , V_114 , V_105 , V_115 ) ;
V_17 -> V_97 += V_115 ;
V_28 -> V_50 . V_54 = V_54 ;
V_28 -> V_50 . V_58 = V_152 ;
V_28 -> V_50 . V_40 = V_40 | ( ( V_115 - 4 ) & 0xFFFC ) ;
V_28 -> V_50 . V_52 = V_52 ;
V_28 -> V_50 . V_56 = V_56 ;
V_28 -> V_60 = false ;
V_28 -> V_66 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_63 = V_115 ;
F_23 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
}
V_28 -> V_66 = true ;
if ( V_18 & V_155 )
V_17 -> V_14 . V_18 = V_155 ;
if ( ! V_7 -> V_72 ) {
V_7 -> V_72 = F_43 ;
V_7 -> V_90 = false ;
} else {
if ( V_7 -> V_90 ) {
F_18 ( F_10 ( V_7 ) , L_19 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
}
return & V_17 -> V_14 ;
}
struct V_12 * F_67 (
struct V_9 * V_10 , T_5 V_156 , T_6 V_157 ,
T_6 V_158 , enum V_121 V_122 ,
void * V_137 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 = NULL ;
struct V_27 * V_28 = NULL ;
unsigned long V_40 , V_56 , V_54 , V_52 ;
int V_115 ;
T_6 V_159 ;
T_5 V_152 = V_156 ;
T_1 V_114 ;
enum V_104 V_105 ;
int V_95 ;
if ( ! V_157 || ! V_158 ) {
F_18 ( F_10 ( V_7 ) , L_20 ) ;
return NULL ;
}
if ( ! V_7 -> V_34 ) {
F_18 ( F_10 ( V_7 ) , L_21 ) ;
return NULL ;
}
if ( V_7 -> V_48 ) {
F_18 ( F_10 ( V_7 ) , L_22 ) ;
return NULL ;
}
if ( V_157 % V_158 ) {
F_18 ( F_10 ( V_7 ) , L_23 ) ;
return NULL ;
}
V_115 = V_158 ;
if ( ( V_115 & 3 ) || ( V_156 & 3 ) ||
( V_115 > V_7 -> V_2 -> V_153 -> V_154 ) ) {
F_18 ( F_10 ( V_7 ) , L_24 ) ;
return NULL ;
}
V_95 = F_61 ( V_7 , V_122 , & V_54 , & V_52 , & V_40 ,
& V_114 , & V_105 ) ;
if ( V_95 < 0 )
return NULL ;
V_56 = V_142 ;
V_56 |= V_143 <<
V_144 ;
V_56 |= V_145 ;
V_40 |= V_147 | V_43 ;
V_40 |= V_7 -> V_33 . V_148 << V_149 ;
V_52 |= V_151 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_18 ( F_10 ( V_7 ) , L_25 ) ;
return NULL ;
}
F_63 ( & V_17 -> V_24 ) ;
F_63 ( & V_17 -> V_70 ) ;
V_17 -> V_69 = 0 ;
V_17 -> V_75 = 0 ;
V_17 -> V_97 = V_157 ;
V_159 = V_157 ;
while ( V_159 ) {
V_28 = F_24 ( V_7 ) ;
if ( ! V_28 ) {
F_18 ( F_10 ( V_7 ) , L_18 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
V_56 |= F_60 ( V_7 , V_114 , V_105 , V_115 ) ;
V_28 -> V_50 . V_54 = V_54 ;
V_28 -> V_50 . V_58 = V_152 ;
V_28 -> V_50 . V_40 = V_40 | ( ( V_115 - 4 ) & 0xFFFC ) ;
V_28 -> V_50 . V_52 = V_52 ;
V_28 -> V_50 . V_56 = V_56 ;
V_28 -> V_60 = false ;
V_28 -> V_160 = false ;
V_28 -> V_66 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_63 = V_115 ;
F_23 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
V_159 -= V_115 ;
V_152 += V_115 ;
}
V_28 -> V_66 = true ;
V_17 -> V_14 . V_18 = 0 ;
if ( ! V_7 -> V_72 ) {
V_7 -> V_72 = F_45 ;
V_7 -> V_90 = true ;
} else {
if ( ! V_7 -> V_90 ) {
F_18 ( F_10 ( V_7 ) , L_26 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
}
return & V_17 -> V_14 ;
}
static int F_68 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_95 ;
F_69 ( & V_7 -> V_9 ) ;
V_7 -> V_34 = false ;
V_95 = F_70 ( V_2 -> V_161 ) ;
if ( V_95 < 0 )
F_18 ( F_10 ( V_7 ) , L_27 , V_95 ) ;
return V_95 ;
}
static void F_71 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_11 * V_17 ;
struct V_27 * V_28 ;
struct V_140 V_162 ;
struct V_140 V_163 ;
unsigned long V_18 ;
F_63 ( & V_162 ) ;
F_63 ( & V_163 ) ;
F_34 ( F_10 ( V_7 ) , L_28 , V_7 -> V_164 ) ;
if ( V_7 -> V_48 )
F_53 ( V_10 ) ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
F_22 ( & V_7 -> V_31 , & V_163 ) ;
F_22 ( & V_7 -> V_25 , & V_163 ) ;
F_22 ( & V_7 -> V_26 , & V_162 ) ;
F_63 ( & V_7 -> V_71 ) ;
V_7 -> V_34 = false ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
while ( ! F_21 ( & V_162 ) ) {
V_17 = F_25 ( & V_162 ,
F_26 ( * V_17 ) , V_20 ) ;
F_15 ( & V_17 -> V_20 ) ;
F_72 ( V_17 ) ;
}
while ( ! F_21 ( & V_163 ) ) {
V_28 = F_25 ( & V_163 , F_26 ( * V_28 ) , V_20 ) ;
F_15 ( & V_28 -> V_20 ) ;
F_72 ( V_28 ) ;
}
F_73 ( V_2 -> V_161 ) ;
}
static int T_7 F_74 ( struct V_165 * V_166 )
{
struct V_167 * V_168 ;
struct V_1 * V_2 ;
int V_95 ;
int V_138 ;
struct V_169 * V_170 = NULL ;
if ( V_166 -> V_16 . V_171 ) {
const struct V_172 * V_173 ;
V_173 = F_75 ( F_76 ( V_174 ) ,
& V_166 -> V_16 ) ;
if ( ! V_173 ) {
F_18 ( & V_166 -> V_16 , L_29 ) ;
return - V_175 ;
}
V_170 = V_173 -> V_78 ;
} else {
V_170 = & V_176 ;
}
V_2 = F_77 ( & V_166 -> V_16 , sizeof( * V_2 ) + V_170 -> V_177 *
sizeof( struct V_6 ) , V_178 ) ;
if ( ! V_2 ) {
F_18 ( & V_166 -> V_16 , L_30 ) ;
return - V_179 ;
}
V_2 -> V_16 = & V_166 -> V_16 ;
V_2 -> V_153 = V_170 ;
F_78 ( V_166 , V_2 ) ;
V_168 = F_79 ( V_166 , V_180 , 0 ) ;
if ( ! V_168 ) {
F_18 ( & V_166 -> V_16 , L_31 ) ;
return - V_133 ;
}
V_2 -> V_5 = F_80 ( & V_166 -> V_16 , V_168 ) ;
if ( ! V_2 -> V_5 ) {
F_18 ( & V_166 -> V_16 ,
L_32 ) ;
return - V_181 ;
}
V_2 -> V_161 = F_81 ( & V_166 -> V_16 , NULL ) ;
if ( F_82 ( V_2 -> V_161 ) ) {
F_18 ( & V_166 -> V_16 , L_33 ) ;
return F_83 ( V_2 -> V_161 ) ;
}
F_84 ( & V_2 -> V_36 ) ;
F_85 ( & V_166 -> V_16 ) ;
if ( ! F_86 ( & V_166 -> V_16 ) ) {
V_95 = F_87 ( & V_166 -> V_16 ) ;
if ( V_95 ) {
F_18 ( & V_166 -> V_16 , L_34 ,
V_95 ) ;
goto V_182;
}
}
V_95 = F_70 ( V_2 -> V_161 ) ;
if ( V_95 < 0 ) {
F_18 ( & V_166 -> V_16 , L_27 , V_95 ) ;
goto V_182;
}
F_88 ( V_2 -> V_161 ) ;
F_30 ( 2 ) ;
F_89 ( V_2 -> V_161 ) ;
F_1 ( V_2 , V_37 , V_39 ) ;
F_1 ( V_2 , V_183 , 0 ) ;
F_1 ( V_2 , V_184 , 0xFFFFFFFFul ) ;
F_73 ( V_2 -> V_161 ) ;
F_63 ( & V_2 -> V_185 . V_186 ) ;
for ( V_138 = 0 ; V_138 < V_170 -> V_177 ; V_138 ++ ) {
struct V_6 * V_7 = & V_2 -> V_186 [ V_138 ] ;
char V_187 [ 30 ] ;
V_7 -> V_8 = V_188 +
V_138 * V_189 ;
V_168 = F_79 ( V_166 , V_190 , V_138 ) ;
if ( ! V_168 ) {
V_95 = - V_133 ;
F_18 ( & V_166 -> V_16 , L_35 , V_138 ) ;
goto V_191;
}
V_7 -> V_81 = V_168 -> V_192 ;
snprintf ( V_187 , sizeof( V_187 ) , L_36 , V_138 ) ;
V_95 = F_90 ( & V_166 -> V_16 , V_7 -> V_81 ,
F_47 , 0 , V_187 , V_7 ) ;
if ( V_95 ) {
F_18 ( & V_166 -> V_16 ,
L_37 ,
V_138 , V_95 ) ;
goto V_191;
}
V_7 -> V_9 . V_15 = & V_2 -> V_185 ;
F_69 ( & V_7 -> V_9 ) ;
F_23 ( & V_7 -> V_9 . V_193 ,
& V_2 -> V_185 . V_186 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_164 = V_138 ;
F_91 ( & V_7 -> V_83 , F_46 ,
( unsigned long ) V_7 ) ;
F_84 ( & V_7 -> V_19 ) ;
F_63 ( & V_7 -> V_31 ) ;
F_63 ( & V_7 -> V_25 ) ;
F_63 ( & V_7 -> V_26 ) ;
F_63 ( & V_7 -> V_71 ) ;
}
F_92 ( V_194 , V_2 -> V_185 . V_195 ) ;
F_92 ( V_196 , V_2 -> V_185 . V_195 ) ;
F_92 ( V_197 , V_2 -> V_185 . V_195 ) ;
V_2 -> V_185 . V_16 = & V_166 -> V_16 ;
V_2 -> V_185 . V_198 =
F_68 ;
V_2 -> V_185 . V_199 =
F_71 ;
V_2 -> V_185 . V_200 = F_62 ;
V_2 -> V_185 . V_201 = F_67 ;
V_2 -> V_185 . V_202 = F_57 ;
V_2 -> V_185 . V_203 = F_54 ;
V_2 -> V_185 . V_204 = F_52 ;
V_95 = F_93 ( & V_2 -> V_185 ) ;
if ( V_95 < 0 ) {
F_18 ( & V_166 -> V_16 ,
L_38 , V_95 ) ;
goto V_191;
}
F_49 ( & V_166 -> V_16 , L_39 ,
V_170 -> V_177 ) ;
return 0 ;
V_191:
while ( -- V_138 >= 0 ) {
struct V_6 * V_7 = & V_2 -> V_186 [ V_138 ] ;
F_94 ( & V_7 -> V_83 ) ;
}
V_182:
F_95 ( & V_166 -> V_16 ) ;
if ( ! F_96 ( & V_166 -> V_16 ) )
F_97 ( & V_166 -> V_16 ) ;
return V_95 ;
}
static int T_8 F_98 ( struct V_165 * V_166 )
{
struct V_1 * V_2 = F_99 ( V_166 ) ;
int V_138 ;
struct V_6 * V_7 ;
F_100 ( & V_2 -> V_185 ) ;
for ( V_138 = 0 ; V_138 < V_2 -> V_153 -> V_177 ; ++ V_138 ) {
V_7 = & V_2 -> V_186 [ V_138 ] ;
F_94 ( & V_7 -> V_83 ) ;
}
F_95 ( & V_166 -> V_16 ) ;
if ( ! F_96 ( & V_166 -> V_16 ) )
F_97 ( & V_166 -> V_16 ) ;
return 0 ;
}
static int F_97 ( struct V_15 * V_16 )
{
struct V_165 * V_166 = F_101 ( V_16 ) ;
struct V_1 * V_2 = F_99 ( V_166 ) ;
F_73 ( V_2 -> V_161 ) ;
return 0 ;
}
static int F_87 ( struct V_15 * V_16 )
{
struct V_165 * V_166 = F_101 ( V_16 ) ;
struct V_1 * V_2 = F_99 ( V_166 ) ;
int V_95 ;
V_95 = F_70 ( V_2 -> V_161 ) ;
if ( V_95 < 0 ) {
F_18 ( V_16 , L_40 , V_95 ) ;
return V_95 ;
}
return 0 ;
}
