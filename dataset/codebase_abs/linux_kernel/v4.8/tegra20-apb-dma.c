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
F_2 ( V_4 , V_7 -> V_8 + V_3 ) ;
}
static inline T_1 F_6 ( struct V_6 * V_7 , T_1 V_3 )
{
return F_4 ( V_7 -> V_8 + V_3 ) ;
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
if ( ! V_17 )
return NULL ;
F_18 ( & V_17 -> V_14 , & V_7 -> V_9 ) ;
V_17 -> V_14 . V_22 = V_23 ;
V_17 -> V_14 . V_18 = 0 ;
return V_17 ;
}
static void F_19 ( struct V_6 * V_7 ,
struct V_11 * V_17 )
{
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( ! F_20 ( & V_17 -> V_24 ) )
F_21 ( & V_17 -> V_24 , & V_7 -> V_25 ) ;
F_22 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static struct V_27 * F_23 (
struct V_6 * V_7 )
{
struct V_27 * V_28 = NULL ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( ! F_20 ( & V_7 -> V_25 ) ) {
V_28 = F_24 ( & V_7 -> V_25 ,
F_25 ( * V_28 ) , V_20 ) ;
F_15 ( & V_28 -> V_20 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_28 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
V_28 = F_17 ( sizeof( struct V_27 ) , V_21 ) ;
return V_28 ;
}
static int F_26 ( struct V_9 * V_10 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
if ( ! F_20 ( & V_7 -> V_31 ) ) {
F_27 ( F_10 ( V_7 ) , L_1 ) ;
return - V_32 ;
}
memcpy ( & V_7 -> V_33 , V_30 , sizeof( * V_30 ) ) ;
if ( V_7 -> V_34 == V_35 ) {
if ( V_30 -> V_34 > V_36 )
return - V_37 ;
V_7 -> V_34 = V_30 -> V_34 ;
}
V_7 -> V_38 = true ;
return 0 ;
}
static void F_28 ( struct V_6 * V_7 ,
bool V_39 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_29 ( & V_2 -> V_40 ) ;
if ( V_7 -> V_2 -> V_41 == 0 ) {
F_1 ( V_2 , V_42 , 0 ) ;
if ( V_39 )
F_30 ( V_43 ) ;
}
V_7 -> V_2 -> V_41 ++ ;
F_31 ( & V_2 -> V_40 ) ;
}
static void F_32 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_29 ( & V_2 -> V_40 ) ;
if ( F_33 ( V_7 -> V_2 -> V_41 == 0 ) )
goto V_44;
if ( -- V_7 -> V_2 -> V_41 == 0 )
F_1 ( V_2 , V_42 ,
V_45 ) ;
V_44:
F_31 ( & V_2 -> V_40 ) ;
}
static void F_34 ( struct V_6 * V_7 ,
bool V_39 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_2 -> V_46 -> V_47 ) {
F_5 ( V_7 , V_48 ,
V_49 ) ;
if ( V_39 )
F_30 ( V_43 ) ;
} else {
F_28 ( V_7 , V_39 ) ;
}
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_2 -> V_46 -> V_47 ) {
F_5 ( V_7 , V_48 , 0 ) ;
} else {
F_32 ( V_7 ) ;
}
}
static void F_36 ( struct V_6 * V_7 )
{
T_1 V_50 ;
T_1 V_51 ;
V_50 = F_6 ( V_7 , V_52 ) ;
V_50 &= ~ V_53 ;
F_5 ( V_7 , V_52 , V_50 ) ;
V_50 &= ~ V_54 ;
F_5 ( V_7 , V_52 , V_50 ) ;
V_51 = F_6 ( V_7 , V_55 ) ;
if ( V_51 & V_56 ) {
F_37 ( F_10 ( V_7 ) , L_2 , V_57 ) ;
F_5 ( V_7 , V_55 , V_51 ) ;
}
V_7 -> V_58 = false ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_27 * V_28 )
{
struct V_59 * V_60 = & V_28 -> V_60 ;
F_5 ( V_7 , V_52 , V_60 -> V_50 ) ;
F_5 ( V_7 , V_61 , V_60 -> V_62 ) ;
F_5 ( V_7 , V_63 , V_60 -> V_64 ) ;
F_5 ( V_7 , V_65 , V_60 -> V_66 ) ;
F_5 ( V_7 , V_67 , V_60 -> V_68 ) ;
if ( V_7 -> V_2 -> V_46 -> V_69 )
F_5 ( V_7 , V_70 , V_60 -> V_71 ) ;
F_5 ( V_7 , V_52 ,
V_60 -> V_50 | V_54 ) ;
}
static void F_39 ( struct V_6 * V_7 ,
struct V_27 * V_72 )
{
unsigned long V_51 ;
F_34 ( V_7 , false ) ;
V_51 = F_6 ( V_7 , V_55 ) ;
if ( V_51 & V_56 ) {
F_27 ( F_10 ( V_7 ) ,
L_3 ) ;
F_35 ( V_7 ) ;
return;
}
F_5 ( V_7 , V_63 , V_72 -> V_60 . V_64 ) ;
F_5 ( V_7 , V_67 , V_72 -> V_60 . V_68 ) ;
if ( V_7 -> V_2 -> V_46 -> V_69 )
F_5 ( V_7 , V_70 ,
V_72 -> V_60 . V_71 ) ;
F_5 ( V_7 , V_52 ,
V_72 -> V_60 . V_50 | V_54 ) ;
V_72 -> V_73 = true ;
F_35 ( V_7 ) ;
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_27 * V_28 ;
if ( F_20 ( & V_7 -> V_31 ) )
return;
V_28 = F_24 ( & V_7 -> V_31 ,
F_25 ( * V_28 ) , V_20 ) ;
F_38 ( V_7 , V_28 ) ;
V_28 -> V_73 = true ;
V_7 -> V_58 = true ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_27 * V_74 ;
struct V_27 * V_75 ;
if ( F_20 ( & V_7 -> V_31 ) )
return;
V_74 = F_24 ( & V_7 -> V_31 , F_25 ( * V_74 ) , V_20 ) ;
if ( ! F_42 ( & V_74 -> V_20 , & V_7 -> V_31 ) ) {
V_75 = F_24 ( & V_74 -> V_20 ,
F_25 ( * V_75 ) , V_20 ) ;
F_39 ( V_7 , V_75 ) ;
}
}
static inline int F_43 ( struct V_6 * V_7 ,
struct V_27 * V_28 , unsigned long V_51 )
{
return V_28 -> V_76 - ( V_51 & V_77 ) - 4 ;
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_27 * V_78 ;
struct V_11 * V_17 ;
while ( ! F_20 ( & V_7 -> V_31 ) ) {
V_78 = F_24 ( & V_7 -> V_31 ,
F_25 ( * V_78 ) , V_20 ) ;
F_45 ( & V_78 -> V_20 , & V_7 -> V_25 ) ;
if ( V_78 -> V_79 ) {
V_17 = V_78 -> V_17 ;
V_17 -> V_80 = V_81 ;
F_22 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
if ( ! V_17 -> V_82 )
F_22 ( & V_17 -> V_83 ,
& V_7 -> V_84 ) ;
V_17 -> V_82 ++ ;
}
}
V_7 -> V_85 = NULL ;
}
static bool F_46 ( struct V_6 * V_7 ,
struct V_27 * V_86 , bool V_87 )
{
struct V_27 * V_74 = NULL ;
if ( F_20 ( & V_7 -> V_31 ) ) {
F_27 ( F_10 ( V_7 ) , L_4 ) ;
F_36 ( V_7 ) ;
return false ;
}
V_74 = F_24 ( & V_7 -> V_31 , F_25 ( * V_74 ) , V_20 ) ;
if ( ! V_74 -> V_73 ) {
F_36 ( V_7 ) ;
F_27 ( F_10 ( V_7 ) , L_5 ) ;
F_44 ( V_7 ) ;
return false ;
}
if ( ! V_87 )
F_41 ( V_7 ) ;
return true ;
}
static void F_47 ( struct V_6 * V_7 ,
bool V_87 )
{
struct V_27 * V_78 ;
struct V_11 * V_17 ;
V_7 -> V_58 = false ;
V_78 = F_24 ( & V_7 -> V_31 , F_25 ( * V_78 ) , V_20 ) ;
V_17 = V_78 -> V_17 ;
V_17 -> V_88 += V_78 -> V_76 ;
F_15 ( & V_78 -> V_20 ) ;
if ( V_78 -> V_79 ) {
V_17 -> V_80 = V_89 ;
F_48 ( & V_17 -> V_14 ) ;
if ( ! V_17 -> V_82 )
F_22 ( & V_17 -> V_83 , & V_7 -> V_84 ) ;
V_17 -> V_82 ++ ;
F_22 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
}
F_22 ( & V_78 -> V_20 , & V_7 -> V_25 ) ;
if ( V_87 || F_20 ( & V_7 -> V_31 ) )
return;
F_40 ( V_7 ) ;
}
static void F_49 ( struct V_6 * V_7 ,
bool V_87 )
{
struct V_27 * V_78 ;
struct V_11 * V_17 ;
bool V_90 ;
V_78 = F_24 ( & V_7 -> V_31 , F_25 ( * V_78 ) , V_20 ) ;
V_17 = V_78 -> V_17 ;
V_17 -> V_88 += V_78 -> V_76 ;
if ( ! V_17 -> V_82 )
F_22 ( & V_17 -> V_83 , & V_7 -> V_84 ) ;
V_17 -> V_82 ++ ;
if ( ! F_42 ( & V_78 -> V_20 , & V_7 -> V_31 ) ) {
F_45 ( & V_78 -> V_20 , & V_7 -> V_31 ) ;
V_78 -> V_73 = false ;
V_90 = F_46 ( V_7 , V_78 , V_87 ) ;
if ( ! V_90 )
V_17 -> V_80 = V_81 ;
}
}
static void F_50 ( unsigned long V_91 )
{
struct V_6 * V_7 = (struct V_6 * ) V_91 ;
T_2 V_92 = NULL ;
void * V_93 = NULL ;
struct V_11 * V_17 ;
unsigned long V_18 ;
int V_82 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
while ( ! F_20 ( & V_7 -> V_84 ) ) {
V_17 = F_24 ( & V_7 -> V_84 ,
F_25 ( * V_17 ) , V_83 ) ;
F_15 ( & V_17 -> V_83 ) ;
V_92 = V_17 -> V_14 . V_92 ;
V_93 = V_17 -> V_14 . V_93 ;
V_82 = V_17 -> V_82 ;
V_17 -> V_82 = 0 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
while ( V_82 -- && V_92 )
V_92 ( V_93 ) ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static T_3 F_51 ( int V_94 , void * V_95 )
{
struct V_6 * V_7 = V_95 ;
unsigned long V_51 ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
V_51 = F_6 ( V_7 , V_55 ) ;
if ( V_51 & V_56 ) {
F_5 ( V_7 , V_55 , V_51 ) ;
V_7 -> V_85 ( V_7 , false ) ;
F_52 ( & V_7 -> V_96 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_97 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
F_53 ( F_10 ( V_7 ) ,
L_6 , V_51 ) ;
return V_98 ;
}
static T_4 V_23 ( struct V_12 * V_14 )
{
struct V_11 * V_17 = F_9 ( V_14 ) ;
struct V_6 * V_7 = F_7 ( V_14 -> V_99 ) ;
unsigned long V_18 ;
T_4 V_100 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
V_17 -> V_80 = V_101 ;
V_100 = F_54 ( & V_17 -> V_14 ) ;
F_55 ( & V_17 -> V_24 , & V_7 -> V_31 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_100 ;
}
static void F_56 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( F_20 ( & V_7 -> V_31 ) ) {
F_27 ( F_10 ( V_7 ) , L_7 ) ;
goto V_102;
}
if ( ! V_7 -> V_58 ) {
F_40 ( V_7 ) ;
if ( V_7 -> V_103 ) {
F_30 ( V_43 ) ;
F_41 ( V_7 ) ;
}
}
V_102:
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static int F_57 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_27 * V_78 ;
struct V_11 * V_17 ;
unsigned long V_18 ;
unsigned long V_51 ;
unsigned long V_71 ;
bool V_104 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( F_20 ( & V_7 -> V_31 ) ) {
F_16 ( & V_7 -> V_19 , V_18 ) ;
return 0 ;
}
if ( ! V_7 -> V_58 )
goto V_105;
F_34 ( V_7 , true ) ;
V_51 = F_6 ( V_7 , V_55 ) ;
if ( V_51 & V_56 ) {
F_37 ( F_10 ( V_7 ) , L_8 , V_57 ) ;
V_7 -> V_85 ( V_7 , true ) ;
V_51 = F_6 ( V_7 , V_55 ) ;
}
if ( V_7 -> V_2 -> V_46 -> V_69 )
V_71 = F_6 ( V_7 , V_106 ) ;
else
V_71 = V_51 ;
V_104 = V_7 -> V_58 ;
F_36 ( V_7 ) ;
if ( ! F_20 ( & V_7 -> V_31 ) && V_104 ) {
V_78 = F_24 ( & V_7 -> V_31 ,
F_25 ( * V_78 ) , V_20 ) ;
V_78 -> V_17 -> V_88 +=
F_43 ( V_7 , V_78 , V_71 ) ;
}
F_35 ( V_7 ) ;
V_105:
F_44 ( V_7 ) ;
while ( ! F_20 ( & V_7 -> V_84 ) ) {
V_17 = F_24 ( & V_7 -> V_84 ,
F_25 ( * V_17 ) , V_83 ) ;
F_15 ( & V_17 -> V_83 ) ;
V_17 -> V_82 = 0 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
return 0 ;
}
static enum V_80 F_58 ( struct V_9 * V_10 ,
T_4 V_100 , struct V_107 * V_108 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 ;
struct V_27 * V_28 ;
enum V_80 V_109 ;
unsigned long V_18 ;
unsigned int V_110 ;
V_109 = F_59 ( V_10 , V_100 , V_108 ) ;
if ( V_109 == V_89 )
return V_109 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
F_13 (dma_desc, &tdc->free_dma_desc, node) {
if ( V_17 -> V_14 . V_100 == V_100 ) {
V_109 = V_17 -> V_80 ;
goto V_111;
}
}
F_13 (sg_req, &tdc->pending_sg_req, node) {
V_17 = V_28 -> V_17 ;
if ( V_17 -> V_14 . V_100 == V_100 ) {
V_109 = V_17 -> V_80 ;
goto V_111;
}
}
F_37 ( F_10 ( V_7 ) , L_9 , V_100 ) ;
V_17 = NULL ;
V_111:
if ( V_17 && V_108 ) {
V_110 = V_17 -> V_112 -
( V_17 -> V_88 %
V_17 -> V_112 ) ;
F_60 ( V_108 , V_110 ) ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_109 ;
}
static inline int F_61 ( struct V_6 * V_7 ,
enum V_113 V_114 )
{
switch ( V_114 ) {
case V_115 :
return V_116 ;
case V_117 :
return V_118 ;
case V_119 :
return V_120 ;
case V_121 :
return V_122 ;
default:
F_62 ( F_10 ( V_7 ) ,
L_10 ) ;
return V_120 ;
}
}
static inline int F_63 ( struct V_6 * V_7 ,
T_1 V_123 , enum V_113 V_114 , int V_124 )
{
int V_125 ;
int V_126 ;
V_125 = V_123 * V_114 ;
V_126 = V_125 / 4 ;
if ( ! V_126 ) {
if ( V_124 & 0xF )
return V_127 ;
else if ( ( V_124 >> 4 ) & 0x1 )
return V_128 ;
else
return V_129 ;
}
if ( V_126 < 4 )
return V_127 ;
else if ( V_126 < 8 )
return V_128 ;
else
return V_129 ;
}
static int F_64 ( struct V_6 * V_7 ,
enum V_130 V_131 , unsigned long * V_132 ,
unsigned long * V_62 , unsigned long * V_50 , unsigned int * V_123 ,
enum V_113 * V_114 )
{
switch ( V_131 ) {
case V_133 :
* V_132 = V_7 -> V_33 . V_134 ;
* V_62 = F_61 ( V_7 , V_7 -> V_33 . V_135 ) ;
* V_123 = V_7 -> V_33 . V_136 ;
* V_114 = V_7 -> V_33 . V_135 ;
* V_50 = V_137 ;
return 0 ;
case V_138 :
* V_132 = V_7 -> V_33 . V_139 ;
* V_62 = F_61 ( V_7 , V_7 -> V_33 . V_140 ) ;
* V_123 = V_7 -> V_33 . V_141 ;
* V_114 = V_7 -> V_33 . V_140 ;
* V_50 = 0 ;
return 0 ;
default:
F_27 ( F_10 ( V_7 ) , L_11 ) ;
return - V_37 ;
}
return - V_37 ;
}
static void F_65 ( struct V_6 * V_7 ,
struct V_59 * V_60 , T_1 V_124 )
{
T_1 V_142 = ( V_124 - 4 ) & 0xFFFC ;
if ( V_7 -> V_2 -> V_46 -> V_69 )
V_60 -> V_71 = V_142 ;
else
V_60 -> V_50 |= V_142 ;
}
static struct V_12 * F_66 (
struct V_9 * V_10 , struct V_143 * V_144 , unsigned int V_145 ,
enum V_130 V_131 , unsigned long V_18 ,
void * V_146 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 ;
unsigned int V_147 ;
struct V_143 * V_148 ;
unsigned long V_50 , V_66 , V_64 , V_62 ;
struct V_149 V_150 ;
struct V_27 * V_28 = NULL ;
T_1 V_123 ;
enum V_113 V_114 ;
if ( ! V_7 -> V_38 ) {
F_27 ( F_10 ( V_7 ) , L_12 ) ;
return NULL ;
}
if ( V_145 < 1 ) {
F_27 ( F_10 ( V_7 ) , L_13 , V_145 ) ;
return NULL ;
}
if ( F_64 ( V_7 , V_131 , & V_64 , & V_62 , & V_50 ,
& V_123 , & V_114 ) < 0 )
return NULL ;
F_67 ( & V_150 ) ;
V_66 = V_151 ;
V_66 |= V_152 <<
V_153 ;
V_66 |= V_154 ;
V_50 |= V_155 | V_156 ;
V_50 |= V_7 -> V_34 << V_157 ;
if ( V_18 & V_158 )
V_50 |= V_53 ;
V_62 |= V_159 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_27 ( F_10 ( V_7 ) , L_14 ) ;
return NULL ;
}
F_67 ( & V_17 -> V_24 ) ;
F_67 ( & V_17 -> V_83 ) ;
V_17 -> V_82 = 0 ;
V_17 -> V_112 = 0 ;
V_17 -> V_88 = 0 ;
V_17 -> V_80 = V_101 ;
F_68 (sgl, sg, sg_len, i) {
T_1 V_124 , V_160 ;
V_160 = F_69 ( V_148 ) ;
V_124 = F_70 ( V_148 ) ;
if ( ( V_124 & 3 ) || ( V_160 & 3 ) ||
( V_124 > V_7 -> V_2 -> V_46 -> V_161 ) ) {
F_27 ( F_10 ( V_7 ) ,
L_15 ) ;
F_19 ( V_7 , V_17 ) ;
return NULL ;
}
V_28 = F_23 ( V_7 ) ;
if ( ! V_28 ) {
F_27 ( F_10 ( V_7 ) , L_16 ) ;
F_19 ( V_7 , V_17 ) ;
return NULL ;
}
V_66 |= F_63 ( V_7 , V_123 , V_114 , V_124 ) ;
V_17 -> V_112 += V_124 ;
V_28 -> V_60 . V_64 = V_64 ;
V_28 -> V_60 . V_68 = V_160 ;
V_28 -> V_60 . V_50 = V_50 ;
F_65 ( V_7 , & V_28 -> V_60 , V_124 ) ;
V_28 -> V_60 . V_62 = V_62 ;
V_28 -> V_60 . V_66 = V_66 ;
V_28 -> V_73 = false ;
V_28 -> V_79 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_76 = V_124 ;
F_22 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
}
V_28 -> V_79 = true ;
if ( V_18 & V_162 )
V_17 -> V_14 . V_18 = V_162 ;
if ( ! V_7 -> V_85 ) {
V_7 -> V_85 = F_47 ;
V_7 -> V_103 = false ;
} else {
if ( V_7 -> V_103 ) {
F_27 ( F_10 ( V_7 ) , L_17 ) ;
F_19 ( V_7 , V_17 ) ;
return NULL ;
}
}
return & V_17 -> V_14 ;
}
static struct V_12 * F_71 (
struct V_9 * V_10 , T_5 V_163 , T_6 V_164 ,
T_6 V_165 , enum V_130 V_131 ,
unsigned long V_18 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 = NULL ;
struct V_27 * V_28 = NULL ;
unsigned long V_50 , V_66 , V_64 , V_62 ;
int V_124 ;
T_6 V_166 ;
T_5 V_160 = V_163 ;
T_1 V_123 ;
enum V_113 V_114 ;
if ( ! V_164 || ! V_165 ) {
F_27 ( F_10 ( V_7 ) , L_18 ) ;
return NULL ;
}
if ( ! V_7 -> V_38 ) {
F_27 ( F_10 ( V_7 ) , L_19 ) ;
return NULL ;
}
if ( V_7 -> V_58 ) {
F_27 ( F_10 ( V_7 ) , L_20 ) ;
return NULL ;
}
if ( V_164 % V_165 ) {
F_27 ( F_10 ( V_7 ) , L_21 ) ;
return NULL ;
}
V_124 = V_165 ;
if ( ( V_124 & 3 ) || ( V_163 & 3 ) ||
( V_124 > V_7 -> V_2 -> V_46 -> V_161 ) ) {
F_27 ( F_10 ( V_7 ) , L_22 ) ;
return NULL ;
}
if ( F_64 ( V_7 , V_131 , & V_64 , & V_62 , & V_50 ,
& V_123 , & V_114 ) < 0 )
return NULL ;
V_66 = V_151 ;
V_66 |= V_152 <<
V_153 ;
V_66 |= V_154 ;
V_50 |= V_156 ;
if ( V_18 & V_158 )
V_50 |= V_53 ;
V_50 |= V_7 -> V_34 << V_157 ;
V_62 |= V_159 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_27 ( F_10 ( V_7 ) , L_23 ) ;
return NULL ;
}
F_67 ( & V_17 -> V_24 ) ;
F_67 ( & V_17 -> V_83 ) ;
V_17 -> V_82 = 0 ;
V_17 -> V_88 = 0 ;
V_17 -> V_112 = V_164 ;
V_166 = V_164 ;
while ( V_166 ) {
V_28 = F_23 ( V_7 ) ;
if ( ! V_28 ) {
F_27 ( F_10 ( V_7 ) , L_16 ) ;
F_19 ( V_7 , V_17 ) ;
return NULL ;
}
V_66 |= F_63 ( V_7 , V_123 , V_114 , V_124 ) ;
V_28 -> V_60 . V_64 = V_64 ;
V_28 -> V_60 . V_68 = V_160 ;
V_28 -> V_60 . V_50 = V_50 ;
F_65 ( V_7 , & V_28 -> V_60 , V_124 ) ;
V_28 -> V_60 . V_62 = V_62 ;
V_28 -> V_60 . V_66 = V_66 ;
V_28 -> V_73 = false ;
V_28 -> V_79 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_76 = V_124 ;
F_22 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
V_166 -= V_124 ;
V_160 += V_124 ;
}
V_28 -> V_79 = true ;
if ( V_18 & V_162 )
V_17 -> V_14 . V_18 = V_162 ;
if ( ! V_7 -> V_85 ) {
V_7 -> V_85 = F_49 ;
V_7 -> V_103 = true ;
} else {
if ( ! V_7 -> V_103 ) {
F_27 ( F_10 ( V_7 ) , L_24 ) ;
F_19 ( V_7 , V_17 ) ;
return NULL ;
}
}
return & V_17 -> V_14 ;
}
static int F_72 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_109 ;
F_73 ( & V_7 -> V_9 ) ;
V_7 -> V_38 = false ;
V_109 = F_74 ( V_2 -> V_16 ) ;
if ( V_109 < 0 )
return V_109 ;
return 0 ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_11 * V_17 ;
struct V_27 * V_28 ;
struct V_149 V_167 ;
struct V_149 V_168 ;
unsigned long V_18 ;
F_67 ( & V_167 ) ;
F_67 ( & V_168 ) ;
F_37 ( F_10 ( V_7 ) , L_25 , V_7 -> V_169 ) ;
if ( V_7 -> V_58 )
F_57 ( V_10 ) ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
F_21 ( & V_7 -> V_31 , & V_168 ) ;
F_21 ( & V_7 -> V_25 , & V_168 ) ;
F_21 ( & V_7 -> V_26 , & V_167 ) ;
F_67 ( & V_7 -> V_84 ) ;
V_7 -> V_38 = false ;
V_7 -> V_85 = NULL ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
while ( ! F_20 ( & V_167 ) ) {
V_17 = F_24 ( & V_167 ,
F_25 ( * V_17 ) , V_20 ) ;
F_15 ( & V_17 -> V_20 ) ;
F_76 ( V_17 ) ;
}
while ( ! F_20 ( & V_168 ) ) {
V_28 = F_24 ( & V_168 , F_25 ( * V_28 ) , V_20 ) ;
F_15 ( & V_28 -> V_20 ) ;
F_76 ( V_28 ) ;
}
F_77 ( V_2 -> V_16 ) ;
V_7 -> V_34 = V_35 ;
}
static struct V_9 * F_78 ( struct V_170 * V_171 ,
struct V_172 * V_173 )
{
struct V_1 * V_2 = V_173 -> V_174 ;
struct V_9 * V_99 ;
struct V_6 * V_7 ;
if ( V_171 -> args [ 0 ] > V_36 ) {
F_27 ( V_2 -> V_16 , L_26 , V_171 -> args [ 0 ] ) ;
return NULL ;
}
V_99 = F_79 ( & V_2 -> V_175 ) ;
if ( ! V_99 )
return NULL ;
V_7 = F_7 ( V_99 ) ;
V_7 -> V_34 = V_171 -> args [ 0 ] ;
return V_99 ;
}
static int F_80 ( struct V_176 * V_177 )
{
struct V_178 * V_179 ;
struct V_1 * V_2 ;
int V_109 ;
int V_147 ;
const struct V_180 * V_181 ;
V_181 = F_81 ( & V_177 -> V_16 ) ;
if ( ! V_181 ) {
F_27 ( & V_177 -> V_16 , L_27 ) ;
return - V_182 ;
}
V_2 = F_82 ( & V_177 -> V_16 , sizeof( * V_2 ) + V_181 -> V_183 *
sizeof( struct V_6 ) , V_184 ) ;
if ( ! V_2 )
return - V_185 ;
V_2 -> V_16 = & V_177 -> V_16 ;
V_2 -> V_46 = V_181 ;
F_83 ( V_177 , V_2 ) ;
V_179 = F_84 ( V_177 , V_186 , 0 ) ;
V_2 -> V_5 = F_85 ( & V_177 -> V_16 , V_179 ) ;
if ( F_86 ( V_2 -> V_5 ) )
return F_87 ( V_2 -> V_5 ) ;
V_2 -> V_187 = F_88 ( & V_177 -> V_16 , NULL ) ;
if ( F_86 ( V_2 -> V_187 ) ) {
F_27 ( & V_177 -> V_16 , L_28 ) ;
return F_87 ( V_2 -> V_187 ) ;
}
V_2 -> V_188 = F_89 ( & V_177 -> V_16 , L_29 ) ;
if ( F_86 ( V_2 -> V_188 ) ) {
F_27 ( & V_177 -> V_16 , L_30 ) ;
return F_87 ( V_2 -> V_188 ) ;
}
F_90 ( & V_2 -> V_40 ) ;
F_91 ( & V_177 -> V_16 ) ;
if ( ! F_92 ( & V_177 -> V_16 ) )
V_109 = F_93 ( & V_177 -> V_16 ) ;
else
V_109 = F_74 ( & V_177 -> V_16 ) ;
if ( V_109 < 0 ) {
F_94 ( & V_177 -> V_16 ) ;
return V_109 ;
}
F_95 ( V_2 -> V_188 ) ;
F_30 ( 2 ) ;
F_96 ( V_2 -> V_188 ) ;
F_1 ( V_2 , V_42 , V_45 ) ;
F_1 ( V_2 , V_189 , 0 ) ;
F_1 ( V_2 , V_190 , 0xFFFFFFFFul ) ;
F_77 ( & V_177 -> V_16 ) ;
F_67 ( & V_2 -> V_175 . V_191 ) ;
for ( V_147 = 0 ; V_147 < V_181 -> V_183 ; V_147 ++ ) {
struct V_6 * V_7 = & V_2 -> V_191 [ V_147 ] ;
V_7 -> V_8 = V_2 -> V_5 +
V_192 +
( V_147 * V_181 -> V_193 ) ;
V_179 = F_84 ( V_177 , V_194 , V_147 ) ;
if ( ! V_179 ) {
V_109 = - V_37 ;
F_27 ( & V_177 -> V_16 , L_31 , V_147 ) ;
goto V_195;
}
V_7 -> V_94 = V_179 -> V_196 ;
snprintf ( V_7 -> V_197 , sizeof( V_7 -> V_197 ) , L_32 , V_147 ) ;
V_109 = F_97 ( V_7 -> V_94 , F_51 , 0 , V_7 -> V_197 , V_7 ) ;
if ( V_109 ) {
F_27 ( & V_177 -> V_16 ,
L_33 ,
V_109 , V_147 ) ;
goto V_195;
}
V_7 -> V_9 . V_15 = & V_2 -> V_175 ;
F_73 ( & V_7 -> V_9 ) ;
F_22 ( & V_7 -> V_9 . V_198 ,
& V_2 -> V_175 . V_191 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_169 = V_147 ;
V_7 -> V_34 = V_35 ;
F_98 ( & V_7 -> V_96 , F_50 ,
( unsigned long ) V_7 ) ;
F_90 ( & V_7 -> V_19 ) ;
F_67 ( & V_7 -> V_31 ) ;
F_67 ( & V_7 -> V_25 ) ;
F_67 ( & V_7 -> V_26 ) ;
F_67 ( & V_7 -> V_84 ) ;
}
F_99 ( V_199 , V_2 -> V_175 . V_200 ) ;
F_99 ( V_201 , V_2 -> V_175 . V_200 ) ;
F_99 ( V_202 , V_2 -> V_175 . V_200 ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_175 . V_16 = & V_177 -> V_16 ;
V_2 -> V_175 . V_203 =
F_72 ;
V_2 -> V_175 . V_204 =
F_75 ;
V_2 -> V_175 . V_205 = F_66 ;
V_2 -> V_175 . V_206 = F_71 ;
V_2 -> V_175 . V_207 = F_100 ( V_115 ) |
F_100 ( V_117 ) |
F_100 ( V_119 ) |
F_100 ( V_121 ) ;
V_2 -> V_175 . V_208 = F_100 ( V_115 ) |
F_100 ( V_117 ) |
F_100 ( V_119 ) |
F_100 ( V_121 ) ;
V_2 -> V_175 . V_209 = F_100 ( V_138 ) | F_100 ( V_133 ) ;
V_2 -> V_175 . V_210 = V_211 ;
V_2 -> V_175 . V_212 = F_26 ;
V_2 -> V_175 . V_213 = F_57 ;
V_2 -> V_175 . V_214 = F_58 ;
V_2 -> V_175 . V_215 = F_56 ;
V_109 = F_101 ( & V_2 -> V_175 ) ;
if ( V_109 < 0 ) {
F_27 ( & V_177 -> V_16 ,
L_34 , V_109 ) ;
goto V_195;
}
V_109 = F_102 ( V_177 -> V_16 . V_216 ,
F_78 , V_2 ) ;
if ( V_109 < 0 ) {
F_27 ( & V_177 -> V_16 ,
L_35 , V_109 ) ;
goto V_217;
}
F_53 ( & V_177 -> V_16 , L_36 ,
V_181 -> V_183 ) ;
return 0 ;
V_217:
F_103 ( & V_2 -> V_175 ) ;
V_195:
while ( -- V_147 >= 0 ) {
struct V_6 * V_7 = & V_2 -> V_191 [ V_147 ] ;
F_104 ( V_7 -> V_94 , V_7 ) ;
F_105 ( & V_7 -> V_96 ) ;
}
F_94 ( & V_177 -> V_16 ) ;
if ( ! F_106 ( & V_177 -> V_16 ) )
F_107 ( & V_177 -> V_16 ) ;
return V_109 ;
}
static int F_108 ( struct V_176 * V_177 )
{
struct V_1 * V_2 = F_109 ( V_177 ) ;
int V_147 ;
struct V_6 * V_7 ;
F_103 ( & V_2 -> V_175 ) ;
for ( V_147 = 0 ; V_147 < V_2 -> V_46 -> V_183 ; ++ V_147 ) {
V_7 = & V_2 -> V_191 [ V_147 ] ;
F_104 ( V_7 -> V_94 , V_7 ) ;
F_105 ( & V_7 -> V_96 ) ;
}
F_94 ( & V_177 -> V_16 ) ;
if ( ! F_106 ( & V_177 -> V_16 ) )
F_107 ( & V_177 -> V_16 ) ;
return 0 ;
}
static int F_107 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_110 ( V_16 ) ;
F_111 ( V_2 -> V_187 ) ;
return 0 ;
}
static int F_93 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_110 ( V_16 ) ;
int V_109 ;
V_109 = F_112 ( V_2 -> V_187 ) ;
if ( V_109 < 0 ) {
F_27 ( V_16 , L_37 , V_109 ) ;
return V_109 ;
}
return 0 ;
}
static int F_113 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_110 ( V_16 ) ;
int V_147 ;
int V_109 ;
V_109 = F_74 ( V_16 ) ;
if ( V_109 < 0 )
return V_109 ;
V_2 -> V_218 = F_3 ( V_2 , V_42 ) ;
for ( V_147 = 0 ; V_147 < V_2 -> V_46 -> V_183 ; V_147 ++ ) {
struct V_6 * V_7 = & V_2 -> V_191 [ V_147 ] ;
struct V_59 * V_219 = & V_7 -> V_220 ;
if ( ! V_7 -> V_38 )
continue;
V_219 -> V_50 = F_6 ( V_7 , V_52 ) ;
V_219 -> V_68 = F_6 ( V_7 , V_67 ) ;
V_219 -> V_64 = F_6 ( V_7 , V_63 ) ;
V_219 -> V_66 = F_6 ( V_7 , V_65 ) ;
V_219 -> V_62 = F_6 ( V_7 , V_61 ) ;
if ( V_2 -> V_46 -> V_69 )
V_219 -> V_71 = F_6 ( V_7 ,
V_70 ) ;
}
F_77 ( V_16 ) ;
return 0 ;
}
static int F_114 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_110 ( V_16 ) ;
int V_147 ;
int V_109 ;
V_109 = F_74 ( V_16 ) ;
if ( V_109 < 0 )
return V_109 ;
F_1 ( V_2 , V_42 , V_2 -> V_218 ) ;
F_1 ( V_2 , V_189 , 0 ) ;
F_1 ( V_2 , V_190 , 0xFFFFFFFFul ) ;
for ( V_147 = 0 ; V_147 < V_2 -> V_46 -> V_183 ; V_147 ++ ) {
struct V_6 * V_7 = & V_2 -> V_191 [ V_147 ] ;
struct V_59 * V_219 = & V_7 -> V_220 ;
if ( ! V_7 -> V_38 )
continue;
if ( V_2 -> V_46 -> V_69 )
F_5 ( V_7 , V_70 ,
V_219 -> V_71 ) ;
F_5 ( V_7 , V_61 , V_219 -> V_62 ) ;
F_5 ( V_7 , V_63 , V_219 -> V_64 ) ;
F_5 ( V_7 , V_65 , V_219 -> V_66 ) ;
F_5 ( V_7 , V_67 , V_219 -> V_68 ) ;
F_5 ( V_7 , V_52 ,
( V_219 -> V_50 & ~ V_54 ) ) ;
}
F_77 ( V_16 ) ;
return 0 ;
}
