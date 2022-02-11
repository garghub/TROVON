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
V_17 -> V_14 . V_18 = 0 ;
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
static void F_33 ( struct V_6 * V_7 ,
bool V_35 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_2 -> V_40 -> V_41 ) {
F_5 ( V_7 , V_42 ,
V_43 ) ;
if ( V_35 )
F_30 ( V_38 ) ;
} else {
F_28 ( V_7 , V_35 ) ;
}
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_2 -> V_40 -> V_41 ) {
F_5 ( V_7 , V_42 , 0 ) ;
} else {
F_31 ( V_7 ) ;
}
}
static void F_35 ( struct V_6 * V_7 )
{
T_1 V_44 ;
T_1 V_45 ;
V_44 = F_6 ( V_7 , V_46 ) ;
V_44 &= ~ V_47 ;
F_5 ( V_7 , V_46 , V_44 ) ;
V_44 &= ~ V_48 ;
F_5 ( V_7 , V_46 , V_44 ) ;
V_45 = F_6 ( V_7 , V_49 ) ;
if ( V_45 & V_50 ) {
F_36 ( F_10 ( V_7 ) , L_4 , V_51 ) ;
F_5 ( V_7 , V_49 , V_45 ) ;
}
V_7 -> V_52 = false ;
}
static void F_37 ( struct V_6 * V_7 ,
struct V_27 * V_28 )
{
struct V_53 * V_54 = & V_28 -> V_54 ;
F_5 ( V_7 , V_46 , V_54 -> V_44 ) ;
F_5 ( V_7 , V_55 , V_54 -> V_56 ) ;
F_5 ( V_7 , V_57 , V_54 -> V_58 ) ;
F_5 ( V_7 , V_59 , V_54 -> V_60 ) ;
F_5 ( V_7 , V_61 , V_54 -> V_62 ) ;
F_5 ( V_7 , V_46 ,
V_54 -> V_44 | V_48 ) ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_27 * V_63 )
{
unsigned long V_45 ;
F_33 ( V_7 , false ) ;
V_45 = F_6 ( V_7 , V_49 ) ;
if ( V_45 & V_50 ) {
F_18 ( F_10 ( V_7 ) ,
L_5 ) ;
F_34 ( V_7 ) ;
return;
}
F_5 ( V_7 , V_57 , V_63 -> V_54 . V_58 ) ;
F_5 ( V_7 , V_61 , V_63 -> V_54 . V_62 ) ;
F_5 ( V_7 , V_46 ,
V_63 -> V_54 . V_44 | V_48 ) ;
V_63 -> V_64 = true ;
F_34 ( V_7 ) ;
}
static void F_39 ( struct V_6 * V_7 )
{
struct V_27 * V_28 ;
if ( F_21 ( & V_7 -> V_31 ) )
return;
V_28 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_28 ) , V_20 ) ;
F_37 ( V_7 , V_28 ) ;
V_28 -> V_64 = true ;
V_7 -> V_52 = true ;
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_27 * V_65 ;
struct V_27 * V_66 ;
if ( F_21 ( & V_7 -> V_31 ) )
return;
V_65 = F_25 ( & V_7 -> V_31 , F_26 ( * V_65 ) , V_20 ) ;
if ( ! F_41 ( & V_65 -> V_20 , & V_7 -> V_31 ) ) {
V_66 = F_25 ( & V_65 -> V_20 ,
F_26 ( * V_66 ) , V_20 ) ;
F_38 ( V_7 , V_66 ) ;
}
}
static inline int F_42 ( struct V_6 * V_7 ,
struct V_27 * V_28 , unsigned long V_45 )
{
return V_28 -> V_67 - ( V_45 & V_68 ) - 4 ;
}
static void F_43 ( struct V_6 * V_7 )
{
struct V_27 * V_69 ;
struct V_11 * V_17 ;
while ( ! F_21 ( & V_7 -> V_31 ) ) {
V_69 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_69 ) , V_20 ) ;
F_44 ( & V_69 -> V_20 , & V_7 -> V_25 ) ;
if ( V_69 -> V_70 ) {
V_17 = V_69 -> V_17 ;
V_17 -> V_71 = V_72 ;
F_23 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
if ( ! V_17 -> V_73 )
F_23 ( & V_17 -> V_74 ,
& V_7 -> V_75 ) ;
V_17 -> V_73 ++ ;
}
}
V_7 -> V_76 = NULL ;
}
static bool F_45 ( struct V_6 * V_7 ,
struct V_27 * V_77 , bool V_78 )
{
struct V_27 * V_65 = NULL ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_18 ( F_10 ( V_7 ) , L_6 ) ;
F_35 ( V_7 ) ;
return false ;
}
V_65 = F_25 ( & V_7 -> V_31 , F_26 ( * V_65 ) , V_20 ) ;
if ( ! V_65 -> V_64 ) {
F_35 ( V_7 ) ;
F_18 ( F_10 ( V_7 ) , L_7 ) ;
F_43 ( V_7 ) ;
return false ;
}
if ( ! V_78 )
F_40 ( V_7 ) ;
return true ;
}
static void F_46 ( struct V_6 * V_7 ,
bool V_78 )
{
struct V_27 * V_69 ;
struct V_11 * V_17 ;
V_7 -> V_52 = false ;
V_69 = F_25 ( & V_7 -> V_31 , F_26 ( * V_69 ) , V_20 ) ;
V_17 = V_69 -> V_17 ;
V_17 -> V_79 += V_69 -> V_67 ;
F_15 ( & V_69 -> V_20 ) ;
if ( V_69 -> V_70 ) {
V_17 -> V_71 = V_80 ;
F_47 ( & V_17 -> V_14 ) ;
if ( ! V_17 -> V_73 )
F_23 ( & V_17 -> V_74 , & V_7 -> V_75 ) ;
V_17 -> V_73 ++ ;
F_23 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
}
F_23 ( & V_69 -> V_20 , & V_7 -> V_25 ) ;
if ( V_78 || F_21 ( & V_7 -> V_31 ) )
return;
F_39 ( V_7 ) ;
return;
}
static void F_48 ( struct V_6 * V_7 ,
bool V_78 )
{
struct V_27 * V_69 ;
struct V_11 * V_17 ;
bool V_81 ;
V_69 = F_25 ( & V_7 -> V_31 , F_26 ( * V_69 ) , V_20 ) ;
V_17 = V_69 -> V_17 ;
V_17 -> V_79 += V_69 -> V_67 ;
if ( ! V_17 -> V_73 )
F_23 ( & V_17 -> V_74 , & V_7 -> V_75 ) ;
V_17 -> V_73 ++ ;
if ( ! F_41 ( & V_69 -> V_20 , & V_7 -> V_31 ) ) {
F_44 ( & V_69 -> V_20 , & V_7 -> V_31 ) ;
V_69 -> V_64 = false ;
V_81 = F_45 ( V_7 , V_69 , V_78 ) ;
if ( ! V_81 )
V_17 -> V_71 = V_72 ;
}
return;
}
static void F_49 ( unsigned long V_82 )
{
struct V_6 * V_7 = (struct V_6 * ) V_82 ;
T_2 V_83 = NULL ;
void * V_84 = NULL ;
struct V_11 * V_17 ;
unsigned long V_18 ;
int V_73 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
while ( ! F_21 ( & V_7 -> V_75 ) ) {
V_17 = F_25 ( & V_7 -> V_75 ,
F_26 ( * V_17 ) , V_74 ) ;
F_15 ( & V_17 -> V_74 ) ;
V_83 = V_17 -> V_14 . V_83 ;
V_84 = V_17 -> V_14 . V_84 ;
V_73 = V_17 -> V_73 ;
V_17 -> V_73 = 0 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
while ( V_73 -- && V_83 )
V_83 ( V_84 ) ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static T_3 F_50 ( int V_85 , void * V_86 )
{
struct V_6 * V_7 = V_86 ;
unsigned long V_45 ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
V_45 = F_6 ( V_7 , V_49 ) ;
if ( V_45 & V_50 ) {
F_5 ( V_7 , V_49 , V_45 ) ;
V_7 -> V_76 ( V_7 , false ) ;
F_51 ( & V_7 -> V_87 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_88 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
F_52 ( F_10 ( V_7 ) ,
L_8 , V_45 ) ;
return V_89 ;
}
static T_4 V_23 ( struct V_12 * V_14 )
{
struct V_11 * V_17 = F_9 ( V_14 ) ;
struct V_6 * V_7 = F_7 ( V_14 -> V_90 ) ;
unsigned long V_18 ;
T_4 V_91 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
V_17 -> V_71 = V_92 ;
V_91 = F_53 ( & V_17 -> V_14 ) ;
F_54 ( & V_17 -> V_24 , & V_7 -> V_31 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_91 ;
}
static void F_55 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_18 ( F_10 ( V_7 ) , L_9 ) ;
goto V_93;
}
if ( ! V_7 -> V_52 ) {
F_39 ( V_7 ) ;
if ( V_7 -> V_94 ) {
F_30 ( V_38 ) ;
F_40 ( V_7 ) ;
}
}
V_93:
F_16 ( & V_7 -> V_19 , V_18 ) ;
return;
}
static void F_56 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_27 * V_69 ;
struct V_11 * V_17 ;
unsigned long V_18 ;
unsigned long V_45 ;
bool V_95 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_16 ( & V_7 -> V_19 , V_18 ) ;
return;
}
if ( ! V_7 -> V_52 )
goto V_96;
F_33 ( V_7 , true ) ;
V_45 = F_6 ( V_7 , V_49 ) ;
if ( V_45 & V_50 ) {
F_36 ( F_10 ( V_7 ) , L_10 , V_51 ) ;
V_7 -> V_76 ( V_7 , true ) ;
V_45 = F_6 ( V_7 , V_49 ) ;
}
V_95 = V_7 -> V_52 ;
F_35 ( V_7 ) ;
if ( ! F_21 ( & V_7 -> V_31 ) && V_95 ) {
V_69 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_69 ) , V_20 ) ;
V_69 -> V_17 -> V_79 +=
F_42 ( V_7 , V_69 , V_45 ) ;
}
F_34 ( V_7 ) ;
V_96:
F_43 ( V_7 ) ;
while ( ! F_21 ( & V_7 -> V_75 ) ) {
V_17 = F_25 ( & V_7 -> V_75 ,
F_26 ( * V_17 ) , V_74 ) ;
F_15 ( & V_17 -> V_74 ) ;
V_17 -> V_73 = 0 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static enum V_71 F_57 ( struct V_9 * V_10 ,
T_4 V_91 , struct V_97 * V_98 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 ;
struct V_27 * V_28 ;
enum V_71 V_99 ;
unsigned long V_18 ;
unsigned int V_100 ;
V_99 = F_58 ( V_10 , V_91 , V_98 ) ;
if ( V_99 == V_80 )
return V_99 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
F_13 (dma_desc, &tdc->free_dma_desc, node) {
if ( V_17 -> V_14 . V_91 == V_91 ) {
V_100 = V_17 -> V_101 -
( V_17 -> V_79 %
V_17 -> V_101 ) ;
F_59 ( V_98 , V_100 ) ;
V_99 = V_17 -> V_71 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_99 ;
}
}
F_13 (sg_req, &tdc->pending_sg_req, node) {
V_17 = V_28 -> V_17 ;
if ( V_17 -> V_14 . V_91 == V_91 ) {
V_100 = V_17 -> V_101 -
( V_17 -> V_79 %
V_17 -> V_101 ) ;
F_59 ( V_98 , V_100 ) ;
V_99 = V_17 -> V_71 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_99 ;
}
}
F_36 ( F_10 ( V_7 ) , L_11 , V_91 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_99 ;
}
static int F_60 ( struct V_9 * V_10 , enum V_102 V_103 ,
unsigned long V_104 )
{
switch ( V_103 ) {
case V_105 :
return F_27 ( V_10 ,
(struct V_29 * ) V_104 ) ;
case V_106 :
F_56 ( V_10 ) ;
return 0 ;
default:
break;
}
return - V_107 ;
}
static inline int F_61 ( struct V_6 * V_7 ,
enum V_108 V_109 )
{
switch ( V_109 ) {
case V_110 :
return V_111 ;
case V_112 :
return V_113 ;
case V_114 :
return V_115 ;
case V_116 :
return V_117 ;
default:
F_62 ( F_10 ( V_7 ) ,
L_12 ) ;
return V_115 ;
}
}
static inline int F_63 ( struct V_6 * V_7 ,
T_1 V_118 , enum V_108 V_109 , int V_119 )
{
int V_120 ;
int V_121 ;
V_120 = V_118 * V_109 ;
V_121 = V_120 / 4 ;
if ( ! V_121 ) {
if ( V_119 & 0xF )
return V_122 ;
else if ( ( V_119 >> 4 ) & 0x1 )
return V_123 ;
else
return V_124 ;
}
if ( V_121 < 4 )
return V_122 ;
else if ( V_121 < 8 )
return V_123 ;
else
return V_124 ;
}
static int F_64 ( struct V_6 * V_7 ,
enum V_125 V_126 , unsigned long * V_127 ,
unsigned long * V_56 , unsigned long * V_44 , unsigned int * V_118 ,
enum V_108 * V_109 )
{
switch ( V_126 ) {
case V_128 :
* V_127 = V_7 -> V_33 . V_129 ;
* V_56 = F_61 ( V_7 , V_7 -> V_33 . V_130 ) ;
* V_118 = V_7 -> V_33 . V_131 ;
* V_109 = V_7 -> V_33 . V_130 ;
* V_44 = V_132 ;
return 0 ;
case V_133 :
* V_127 = V_7 -> V_33 . V_134 ;
* V_56 = F_61 ( V_7 , V_7 -> V_33 . V_135 ) ;
* V_118 = V_7 -> V_33 . V_136 ;
* V_109 = V_7 -> V_33 . V_135 ;
* V_44 = 0 ;
return 0 ;
default:
F_18 ( F_10 ( V_7 ) , L_13 ) ;
return - V_137 ;
}
return - V_137 ;
}
static struct V_12 * F_65 (
struct V_9 * V_10 , struct V_138 * V_139 , unsigned int V_140 ,
enum V_125 V_126 , unsigned long V_18 ,
void * V_141 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 ;
unsigned int V_142 ;
struct V_138 * V_143 ;
unsigned long V_44 , V_60 , V_58 , V_56 ;
struct V_144 V_145 ;
struct V_27 * V_28 = NULL ;
T_1 V_118 ;
enum V_108 V_109 ;
int V_99 ;
if ( ! V_7 -> V_34 ) {
F_18 ( F_10 ( V_7 ) , L_14 ) ;
return NULL ;
}
if ( V_140 < 1 ) {
F_18 ( F_10 ( V_7 ) , L_15 , V_140 ) ;
return NULL ;
}
V_99 = F_64 ( V_7 , V_126 , & V_58 , & V_56 , & V_44 ,
& V_118 , & V_109 ) ;
if ( V_99 < 0 )
return NULL ;
F_66 ( & V_145 ) ;
V_60 = V_146 ;
V_60 |= V_147 <<
V_148 ;
V_60 |= V_149 ;
V_44 |= V_150 | V_151 ;
V_44 |= V_7 -> V_33 . V_152 << V_153 ;
if ( V_18 & V_154 )
V_44 |= V_47 ;
V_56 |= V_155 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_18 ( F_10 ( V_7 ) , L_16 ) ;
return NULL ;
}
F_66 ( & V_17 -> V_24 ) ;
F_66 ( & V_17 -> V_74 ) ;
V_17 -> V_73 = 0 ;
V_17 -> V_101 = 0 ;
V_17 -> V_79 = 0 ;
V_17 -> V_71 = V_92 ;
F_67 (sgl, sg, sg_len, i) {
T_1 V_119 , V_156 ;
V_156 = F_68 ( V_143 ) ;
V_119 = F_69 ( V_143 ) ;
if ( ( V_119 & 3 ) || ( V_156 & 3 ) ||
( V_119 > V_7 -> V_2 -> V_40 -> V_157 ) ) {
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
V_60 |= F_63 ( V_7 , V_118 , V_109 , V_119 ) ;
V_17 -> V_101 += V_119 ;
V_28 -> V_54 . V_58 = V_58 ;
V_28 -> V_54 . V_62 = V_156 ;
V_28 -> V_54 . V_44 = V_44 | ( ( V_119 - 4 ) & 0xFFFC ) ;
V_28 -> V_54 . V_56 = V_56 ;
V_28 -> V_54 . V_60 = V_60 ;
V_28 -> V_64 = false ;
V_28 -> V_70 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_67 = V_119 ;
F_23 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
}
V_28 -> V_70 = true ;
if ( V_18 & V_158 )
V_17 -> V_14 . V_18 = V_158 ;
if ( ! V_7 -> V_76 ) {
V_7 -> V_76 = F_46 ;
V_7 -> V_94 = false ;
} else {
if ( V_7 -> V_94 ) {
F_18 ( F_10 ( V_7 ) , L_19 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
}
return & V_17 -> V_14 ;
}
static struct V_12 * F_70 (
struct V_9 * V_10 , T_5 V_159 , T_6 V_160 ,
T_6 V_161 , enum V_125 V_126 ,
unsigned long V_18 , void * V_141 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 = NULL ;
struct V_27 * V_28 = NULL ;
unsigned long V_44 , V_60 , V_58 , V_56 ;
int V_119 ;
T_6 V_162 ;
T_5 V_156 = V_159 ;
T_1 V_118 ;
enum V_108 V_109 ;
int V_99 ;
if ( ! V_160 || ! V_161 ) {
F_18 ( F_10 ( V_7 ) , L_20 ) ;
return NULL ;
}
if ( ! V_7 -> V_34 ) {
F_18 ( F_10 ( V_7 ) , L_21 ) ;
return NULL ;
}
if ( V_7 -> V_52 ) {
F_18 ( F_10 ( V_7 ) , L_22 ) ;
return NULL ;
}
if ( V_160 % V_161 ) {
F_18 ( F_10 ( V_7 ) , L_23 ) ;
return NULL ;
}
V_119 = V_161 ;
if ( ( V_119 & 3 ) || ( V_159 & 3 ) ||
( V_119 > V_7 -> V_2 -> V_40 -> V_157 ) ) {
F_18 ( F_10 ( V_7 ) , L_24 ) ;
return NULL ;
}
V_99 = F_64 ( V_7 , V_126 , & V_58 , & V_56 , & V_44 ,
& V_118 , & V_109 ) ;
if ( V_99 < 0 )
return NULL ;
V_60 = V_146 ;
V_60 |= V_147 <<
V_148 ;
V_60 |= V_149 ;
V_44 |= V_151 ;
if ( V_18 & V_154 )
V_44 |= V_47 ;
V_44 |= V_7 -> V_33 . V_152 << V_153 ;
V_56 |= V_155 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_18 ( F_10 ( V_7 ) , L_25 ) ;
return NULL ;
}
F_66 ( & V_17 -> V_24 ) ;
F_66 ( & V_17 -> V_74 ) ;
V_17 -> V_73 = 0 ;
V_17 -> V_79 = 0 ;
V_17 -> V_101 = V_160 ;
V_162 = V_160 ;
while ( V_162 ) {
V_28 = F_24 ( V_7 ) ;
if ( ! V_28 ) {
F_18 ( F_10 ( V_7 ) , L_18 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
V_60 |= F_63 ( V_7 , V_118 , V_109 , V_119 ) ;
V_28 -> V_54 . V_58 = V_58 ;
V_28 -> V_54 . V_62 = V_156 ;
V_28 -> V_54 . V_44 = V_44 | ( ( V_119 - 4 ) & 0xFFFC ) ;
V_28 -> V_54 . V_56 = V_56 ;
V_28 -> V_54 . V_60 = V_60 ;
V_28 -> V_64 = false ;
V_28 -> V_163 = false ;
V_28 -> V_70 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_67 = V_119 ;
F_23 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
V_162 -= V_119 ;
V_156 += V_119 ;
}
V_28 -> V_70 = true ;
if ( V_18 & V_158 )
V_17 -> V_14 . V_18 = V_158 ;
if ( ! V_7 -> V_76 ) {
V_7 -> V_76 = F_48 ;
V_7 -> V_94 = true ;
} else {
if ( ! V_7 -> V_94 ) {
F_18 ( F_10 ( V_7 ) , L_26 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
}
return & V_17 -> V_14 ;
}
static int F_71 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_99 ;
F_72 ( & V_7 -> V_9 ) ;
V_7 -> V_34 = false ;
V_99 = F_73 ( V_2 -> V_164 ) ;
if ( V_99 < 0 )
F_18 ( F_10 ( V_7 ) , L_27 , V_99 ) ;
return V_99 ;
}
static void F_74 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_11 * V_17 ;
struct V_27 * V_28 ;
struct V_144 V_165 ;
struct V_144 V_166 ;
unsigned long V_18 ;
F_66 ( & V_165 ) ;
F_66 ( & V_166 ) ;
F_36 ( F_10 ( V_7 ) , L_28 , V_7 -> V_167 ) ;
if ( V_7 -> V_52 )
F_56 ( V_10 ) ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
F_22 ( & V_7 -> V_31 , & V_166 ) ;
F_22 ( & V_7 -> V_25 , & V_166 ) ;
F_22 ( & V_7 -> V_26 , & V_165 ) ;
F_66 ( & V_7 -> V_75 ) ;
V_7 -> V_34 = false ;
V_7 -> V_76 = NULL ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
while ( ! F_21 ( & V_165 ) ) {
V_17 = F_25 ( & V_165 ,
F_26 ( * V_17 ) , V_20 ) ;
F_15 ( & V_17 -> V_20 ) ;
F_75 ( V_17 ) ;
}
while ( ! F_21 ( & V_166 ) ) {
V_28 = F_25 ( & V_166 , F_26 ( * V_28 ) , V_20 ) ;
F_15 ( & V_28 -> V_20 ) ;
F_75 ( V_28 ) ;
}
F_76 ( V_2 -> V_164 ) ;
}
static int F_77 ( struct V_168 * V_169 )
{
struct V_170 * V_171 ;
struct V_1 * V_2 ;
int V_99 ;
int V_142 ;
const struct V_172 * V_173 = NULL ;
const struct V_174 * V_175 ;
V_175 = F_78 ( V_176 , & V_169 -> V_16 ) ;
if ( ! V_175 ) {
F_18 ( & V_169 -> V_16 , L_29 ) ;
return - V_177 ;
}
V_173 = V_175 -> V_82 ;
V_2 = F_79 ( & V_169 -> V_16 , sizeof( * V_2 ) + V_173 -> V_178 *
sizeof( struct V_6 ) , V_179 ) ;
if ( ! V_2 ) {
F_18 ( & V_169 -> V_16 , L_30 ) ;
return - V_180 ;
}
V_2 -> V_16 = & V_169 -> V_16 ;
V_2 -> V_40 = V_173 ;
F_80 ( V_169 , V_2 ) ;
V_171 = F_81 ( V_169 , V_181 , 0 ) ;
V_2 -> V_5 = F_82 ( & V_169 -> V_16 , V_171 ) ;
if ( F_83 ( V_2 -> V_5 ) )
return F_84 ( V_2 -> V_5 ) ;
V_2 -> V_164 = F_85 ( & V_169 -> V_16 , NULL ) ;
if ( F_83 ( V_2 -> V_164 ) ) {
F_18 ( & V_169 -> V_16 , L_31 ) ;
return F_84 ( V_2 -> V_164 ) ;
}
F_86 ( & V_2 -> V_36 ) ;
F_87 ( & V_169 -> V_16 ) ;
if ( ! F_88 ( & V_169 -> V_16 ) ) {
V_99 = F_89 ( & V_169 -> V_16 ) ;
if ( V_99 ) {
F_18 ( & V_169 -> V_16 , L_32 ,
V_99 ) ;
goto V_182;
}
}
V_99 = F_73 ( V_2 -> V_164 ) ;
if ( V_99 < 0 ) {
F_18 ( & V_169 -> V_16 , L_27 , V_99 ) ;
goto V_182;
}
F_90 ( V_2 -> V_164 ) ;
F_30 ( 2 ) ;
F_91 ( V_2 -> V_164 ) ;
F_1 ( V_2 , V_37 , V_39 ) ;
F_1 ( V_2 , V_183 , 0 ) ;
F_1 ( V_2 , V_184 , 0xFFFFFFFFul ) ;
F_76 ( V_2 -> V_164 ) ;
F_66 ( & V_2 -> V_185 . V_186 ) ;
for ( V_142 = 0 ; V_142 < V_173 -> V_178 ; V_142 ++ ) {
struct V_6 * V_7 = & V_2 -> V_186 [ V_142 ] ;
V_7 -> V_8 = V_187 +
V_142 * V_188 ;
V_171 = F_81 ( V_169 , V_189 , V_142 ) ;
if ( ! V_171 ) {
V_99 = - V_137 ;
F_18 ( & V_169 -> V_16 , L_33 , V_142 ) ;
goto V_190;
}
V_7 -> V_85 = V_171 -> V_191 ;
snprintf ( V_7 -> V_192 , sizeof( V_7 -> V_192 ) , L_34 , V_142 ) ;
V_99 = F_92 ( & V_169 -> V_16 , V_7 -> V_85 ,
F_50 , 0 , V_7 -> V_192 , V_7 ) ;
if ( V_99 ) {
F_18 ( & V_169 -> V_16 ,
L_35 ,
V_99 , V_142 ) ;
goto V_190;
}
V_7 -> V_9 . V_15 = & V_2 -> V_185 ;
F_72 ( & V_7 -> V_9 ) ;
F_23 ( & V_7 -> V_9 . V_193 ,
& V_2 -> V_185 . V_186 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_167 = V_142 ;
F_93 ( & V_7 -> V_87 , F_49 ,
( unsigned long ) V_7 ) ;
F_86 ( & V_7 -> V_19 ) ;
F_66 ( & V_7 -> V_31 ) ;
F_66 ( & V_7 -> V_25 ) ;
F_66 ( & V_7 -> V_26 ) ;
F_66 ( & V_7 -> V_75 ) ;
}
F_94 ( V_194 , V_2 -> V_185 . V_195 ) ;
F_94 ( V_196 , V_2 -> V_185 . V_195 ) ;
F_94 ( V_197 , V_2 -> V_185 . V_195 ) ;
V_2 -> V_185 . V_16 = & V_169 -> V_16 ;
V_2 -> V_185 . V_198 =
F_71 ;
V_2 -> V_185 . V_199 =
F_74 ;
V_2 -> V_185 . V_200 = F_65 ;
V_2 -> V_185 . V_201 = F_70 ;
V_2 -> V_185 . V_202 = F_60 ;
V_2 -> V_185 . V_203 = F_57 ;
V_2 -> V_185 . V_204 = F_55 ;
V_99 = F_95 ( & V_2 -> V_185 ) ;
if ( V_99 < 0 ) {
F_18 ( & V_169 -> V_16 ,
L_36 , V_99 ) ;
goto V_190;
}
F_52 ( & V_169 -> V_16 , L_37 ,
V_173 -> V_178 ) ;
return 0 ;
V_190:
while ( -- V_142 >= 0 ) {
struct V_6 * V_7 = & V_2 -> V_186 [ V_142 ] ;
F_96 ( & V_7 -> V_87 ) ;
}
V_182:
F_97 ( & V_169 -> V_16 ) ;
if ( ! F_98 ( & V_169 -> V_16 ) )
F_99 ( & V_169 -> V_16 ) ;
return V_99 ;
}
static int F_100 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = F_101 ( V_169 ) ;
int V_142 ;
struct V_6 * V_7 ;
F_102 ( & V_2 -> V_185 ) ;
for ( V_142 = 0 ; V_142 < V_2 -> V_40 -> V_178 ; ++ V_142 ) {
V_7 = & V_2 -> V_186 [ V_142 ] ;
F_96 ( & V_7 -> V_87 ) ;
}
F_97 ( & V_169 -> V_16 ) ;
if ( ! F_98 ( & V_169 -> V_16 ) )
F_99 ( & V_169 -> V_16 ) ;
return 0 ;
}
static int F_99 ( struct V_15 * V_16 )
{
struct V_168 * V_169 = F_103 ( V_16 ) ;
struct V_1 * V_2 = F_101 ( V_169 ) ;
F_76 ( V_2 -> V_164 ) ;
return 0 ;
}
static int F_89 ( struct V_15 * V_16 )
{
struct V_168 * V_169 = F_103 ( V_16 ) ;
struct V_1 * V_2 = F_101 ( V_169 ) ;
int V_99 ;
V_99 = F_73 ( V_2 -> V_164 ) ;
if ( V_99 < 0 ) {
F_18 ( V_16 , L_38 , V_99 ) ;
return V_99 ;
}
return 0 ;
}
static int F_104 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_105 ( V_16 ) ;
int V_142 ;
int V_99 ;
V_99 = F_89 ( V_16 ) ;
if ( V_99 < 0 )
return V_99 ;
V_2 -> V_205 = F_3 ( V_2 , V_37 ) ;
for ( V_142 = 0 ; V_142 < V_2 -> V_40 -> V_178 ; V_142 ++ ) {
struct V_6 * V_7 = & V_2 -> V_186 [ V_142 ] ;
struct V_53 * V_206 = & V_7 -> V_207 ;
V_206 -> V_44 = F_6 ( V_7 , V_46 ) ;
V_206 -> V_62 = F_6 ( V_7 , V_61 ) ;
V_206 -> V_58 = F_6 ( V_7 , V_57 ) ;
V_206 -> V_60 = F_6 ( V_7 , V_59 ) ;
V_206 -> V_56 = F_6 ( V_7 , V_55 ) ;
}
F_99 ( V_16 ) ;
return 0 ;
}
static int F_106 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_105 ( V_16 ) ;
int V_142 ;
int V_99 ;
V_99 = F_89 ( V_16 ) ;
if ( V_99 < 0 )
return V_99 ;
F_1 ( V_2 , V_37 , V_2 -> V_205 ) ;
F_1 ( V_2 , V_183 , 0 ) ;
F_1 ( V_2 , V_184 , 0xFFFFFFFFul ) ;
for ( V_142 = 0 ; V_142 < V_2 -> V_40 -> V_178 ; V_142 ++ ) {
struct V_6 * V_7 = & V_2 -> V_186 [ V_142 ] ;
struct V_53 * V_206 = & V_7 -> V_207 ;
F_5 ( V_7 , V_55 , V_206 -> V_56 ) ;
F_5 ( V_7 , V_57 , V_206 -> V_58 ) ;
F_5 ( V_7 , V_59 , V_206 -> V_60 ) ;
F_5 ( V_7 , V_61 , V_206 -> V_62 ) ;
F_5 ( V_7 , V_46 ,
( V_206 -> V_44 & ~ V_48 ) ) ;
}
F_99 ( V_16 ) ;
return 0 ;
}
