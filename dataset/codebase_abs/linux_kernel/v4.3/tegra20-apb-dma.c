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
if ( ! V_7 -> V_34 )
V_7 -> V_34 = V_30 -> V_34 ;
V_7 -> V_35 = true ;
return 0 ;
}
static void F_28 ( struct V_6 * V_7 ,
bool V_36 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_29 ( & V_2 -> V_37 ) ;
if ( V_7 -> V_2 -> V_38 == 0 ) {
F_1 ( V_2 , V_39 , 0 ) ;
if ( V_36 )
F_30 ( V_40 ) ;
}
V_7 -> V_2 -> V_38 ++ ;
F_31 ( & V_2 -> V_37 ) ;
}
static void F_32 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_29 ( & V_2 -> V_37 ) ;
if ( F_33 ( V_7 -> V_2 -> V_38 == 0 ) )
goto V_41;
if ( -- V_7 -> V_2 -> V_38 == 0 )
F_1 ( V_2 , V_39 ,
V_42 ) ;
V_41:
F_31 ( & V_2 -> V_37 ) ;
}
static void F_34 ( struct V_6 * V_7 ,
bool V_36 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_2 -> V_43 -> V_44 ) {
F_5 ( V_7 , V_45 ,
V_46 ) ;
if ( V_36 )
F_30 ( V_40 ) ;
} else {
F_28 ( V_7 , V_36 ) ;
}
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_2 -> V_43 -> V_44 ) {
F_5 ( V_7 , V_45 , 0 ) ;
} else {
F_32 ( V_7 ) ;
}
}
static void F_36 ( struct V_6 * V_7 )
{
T_1 V_47 ;
T_1 V_48 ;
V_47 = F_6 ( V_7 , V_49 ) ;
V_47 &= ~ V_50 ;
F_5 ( V_7 , V_49 , V_47 ) ;
V_47 &= ~ V_51 ;
F_5 ( V_7 , V_49 , V_47 ) ;
V_48 = F_6 ( V_7 , V_52 ) ;
if ( V_48 & V_53 ) {
F_37 ( F_10 ( V_7 ) , L_4 , V_54 ) ;
F_5 ( V_7 , V_52 , V_48 ) ;
}
V_7 -> V_55 = false ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_27 * V_28 )
{
struct V_56 * V_57 = & V_28 -> V_57 ;
F_5 ( V_7 , V_49 , V_57 -> V_47 ) ;
F_5 ( V_7 , V_58 , V_57 -> V_59 ) ;
F_5 ( V_7 , V_60 , V_57 -> V_61 ) ;
F_5 ( V_7 , V_62 , V_57 -> V_63 ) ;
F_5 ( V_7 , V_64 , V_57 -> V_65 ) ;
if ( V_7 -> V_2 -> V_43 -> V_66 )
F_5 ( V_7 , V_67 , V_57 -> V_68 ) ;
F_5 ( V_7 , V_49 ,
V_57 -> V_47 | V_51 ) ;
}
static void F_39 ( struct V_6 * V_7 ,
struct V_27 * V_69 )
{
unsigned long V_48 ;
F_34 ( V_7 , false ) ;
V_48 = F_6 ( V_7 , V_52 ) ;
if ( V_48 & V_53 ) {
F_18 ( F_10 ( V_7 ) ,
L_5 ) ;
F_35 ( V_7 ) ;
return;
}
F_5 ( V_7 , V_60 , V_69 -> V_57 . V_61 ) ;
F_5 ( V_7 , V_64 , V_69 -> V_57 . V_65 ) ;
if ( V_7 -> V_2 -> V_43 -> V_66 )
F_5 ( V_7 , V_67 ,
V_69 -> V_57 . V_68 ) ;
F_5 ( V_7 , V_49 ,
V_69 -> V_57 . V_47 | V_51 ) ;
V_69 -> V_70 = true ;
F_35 ( V_7 ) ;
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_27 * V_28 ;
if ( F_21 ( & V_7 -> V_31 ) )
return;
V_28 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_28 ) , V_20 ) ;
F_38 ( V_7 , V_28 ) ;
V_28 -> V_70 = true ;
V_7 -> V_55 = true ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_27 * V_71 ;
struct V_27 * V_72 ;
if ( F_21 ( & V_7 -> V_31 ) )
return;
V_71 = F_25 ( & V_7 -> V_31 , F_26 ( * V_71 ) , V_20 ) ;
if ( ! F_42 ( & V_71 -> V_20 , & V_7 -> V_31 ) ) {
V_72 = F_25 ( & V_71 -> V_20 ,
F_26 ( * V_72 ) , V_20 ) ;
F_39 ( V_7 , V_72 ) ;
}
}
static inline int F_43 ( struct V_6 * V_7 ,
struct V_27 * V_28 , unsigned long V_48 )
{
return V_28 -> V_73 - ( V_48 & V_74 ) - 4 ;
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_27 * V_75 ;
struct V_11 * V_17 ;
while ( ! F_21 ( & V_7 -> V_31 ) ) {
V_75 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_75 ) , V_20 ) ;
F_45 ( & V_75 -> V_20 , & V_7 -> V_25 ) ;
if ( V_75 -> V_76 ) {
V_17 = V_75 -> V_17 ;
V_17 -> V_77 = V_78 ;
F_23 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
if ( ! V_17 -> V_79 )
F_23 ( & V_17 -> V_80 ,
& V_7 -> V_81 ) ;
V_17 -> V_79 ++ ;
}
}
V_7 -> V_82 = NULL ;
}
static bool F_46 ( struct V_6 * V_7 ,
struct V_27 * V_83 , bool V_84 )
{
struct V_27 * V_71 = NULL ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_18 ( F_10 ( V_7 ) , L_6 ) ;
F_36 ( V_7 ) ;
return false ;
}
V_71 = F_25 ( & V_7 -> V_31 , F_26 ( * V_71 ) , V_20 ) ;
if ( ! V_71 -> V_70 ) {
F_36 ( V_7 ) ;
F_18 ( F_10 ( V_7 ) , L_7 ) ;
F_44 ( V_7 ) ;
return false ;
}
if ( ! V_84 )
F_41 ( V_7 ) ;
return true ;
}
static void F_47 ( struct V_6 * V_7 ,
bool V_84 )
{
struct V_27 * V_75 ;
struct V_11 * V_17 ;
V_7 -> V_55 = false ;
V_75 = F_25 ( & V_7 -> V_31 , F_26 ( * V_75 ) , V_20 ) ;
V_17 = V_75 -> V_17 ;
V_17 -> V_85 += V_75 -> V_73 ;
F_15 ( & V_75 -> V_20 ) ;
if ( V_75 -> V_76 ) {
V_17 -> V_77 = V_86 ;
F_48 ( & V_17 -> V_14 ) ;
if ( ! V_17 -> V_79 )
F_23 ( & V_17 -> V_80 , & V_7 -> V_81 ) ;
V_17 -> V_79 ++ ;
F_23 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
}
F_23 ( & V_75 -> V_20 , & V_7 -> V_25 ) ;
if ( V_84 || F_21 ( & V_7 -> V_31 ) )
return;
F_40 ( V_7 ) ;
}
static void F_49 ( struct V_6 * V_7 ,
bool V_84 )
{
struct V_27 * V_75 ;
struct V_11 * V_17 ;
bool V_87 ;
V_75 = F_25 ( & V_7 -> V_31 , F_26 ( * V_75 ) , V_20 ) ;
V_17 = V_75 -> V_17 ;
V_17 -> V_85 += V_75 -> V_73 ;
if ( ! V_17 -> V_79 )
F_23 ( & V_17 -> V_80 , & V_7 -> V_81 ) ;
V_17 -> V_79 ++ ;
if ( ! F_42 ( & V_75 -> V_20 , & V_7 -> V_31 ) ) {
F_45 ( & V_75 -> V_20 , & V_7 -> V_31 ) ;
V_75 -> V_70 = false ;
V_87 = F_46 ( V_7 , V_75 , V_84 ) ;
if ( ! V_87 )
V_17 -> V_77 = V_78 ;
}
}
static void F_50 ( unsigned long V_88 )
{
struct V_6 * V_7 = (struct V_6 * ) V_88 ;
T_2 V_89 = NULL ;
void * V_90 = NULL ;
struct V_11 * V_17 ;
unsigned long V_18 ;
int V_79 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
while ( ! F_21 ( & V_7 -> V_81 ) ) {
V_17 = F_25 ( & V_7 -> V_81 ,
F_26 ( * V_17 ) , V_80 ) ;
F_15 ( & V_17 -> V_80 ) ;
V_89 = V_17 -> V_14 . V_89 ;
V_90 = V_17 -> V_14 . V_90 ;
V_79 = V_17 -> V_79 ;
V_17 -> V_79 = 0 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
while ( V_79 -- && V_89 )
V_89 ( V_90 ) ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static T_3 F_51 ( int V_91 , void * V_92 )
{
struct V_6 * V_7 = V_92 ;
unsigned long V_48 ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
V_48 = F_6 ( V_7 , V_52 ) ;
if ( V_48 & V_53 ) {
F_5 ( V_7 , V_52 , V_48 ) ;
V_7 -> V_82 ( V_7 , false ) ;
F_52 ( & V_7 -> V_93 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_94 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
F_53 ( F_10 ( V_7 ) ,
L_8 , V_48 ) ;
return V_95 ;
}
static T_4 V_23 ( struct V_12 * V_14 )
{
struct V_11 * V_17 = F_9 ( V_14 ) ;
struct V_6 * V_7 = F_7 ( V_14 -> V_96 ) ;
unsigned long V_18 ;
T_4 V_97 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
V_17 -> V_77 = V_98 ;
V_97 = F_54 ( & V_17 -> V_14 ) ;
F_55 ( & V_17 -> V_24 , & V_7 -> V_31 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_97 ;
}
static void F_56 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_18 ( F_10 ( V_7 ) , L_9 ) ;
goto V_99;
}
if ( ! V_7 -> V_55 ) {
F_40 ( V_7 ) ;
if ( V_7 -> V_100 ) {
F_30 ( V_40 ) ;
F_41 ( V_7 ) ;
}
}
V_99:
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static int F_57 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_27 * V_75 ;
struct V_11 * V_17 ;
unsigned long V_18 ;
unsigned long V_48 ;
unsigned long V_68 ;
bool V_101 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_16 ( & V_7 -> V_19 , V_18 ) ;
return 0 ;
}
if ( ! V_7 -> V_55 )
goto V_102;
F_34 ( V_7 , true ) ;
V_48 = F_6 ( V_7 , V_52 ) ;
if ( V_48 & V_53 ) {
F_37 ( F_10 ( V_7 ) , L_10 , V_54 ) ;
V_7 -> V_82 ( V_7 , true ) ;
V_48 = F_6 ( V_7 , V_52 ) ;
}
if ( V_7 -> V_2 -> V_43 -> V_66 )
V_68 = F_6 ( V_7 , V_103 ) ;
else
V_68 = V_48 ;
V_101 = V_7 -> V_55 ;
F_36 ( V_7 ) ;
if ( ! F_21 ( & V_7 -> V_31 ) && V_101 ) {
V_75 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_75 ) , V_20 ) ;
V_75 -> V_17 -> V_85 +=
F_43 ( V_7 , V_75 , V_68 ) ;
}
F_35 ( V_7 ) ;
V_102:
F_44 ( V_7 ) ;
while ( ! F_21 ( & V_7 -> V_81 ) ) {
V_17 = F_25 ( & V_7 -> V_81 ,
F_26 ( * V_17 ) , V_80 ) ;
F_15 ( & V_17 -> V_80 ) ;
V_17 -> V_79 = 0 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
return 0 ;
}
static enum V_77 F_58 ( struct V_9 * V_10 ,
T_4 V_97 , struct V_104 * V_105 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 ;
struct V_27 * V_28 ;
enum V_77 V_106 ;
unsigned long V_18 ;
unsigned int V_107 ;
V_106 = F_59 ( V_10 , V_97 , V_105 ) ;
if ( V_106 == V_86 )
return V_106 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
F_13 (dma_desc, &tdc->free_dma_desc, node) {
if ( V_17 -> V_14 . V_97 == V_97 ) {
V_107 = V_17 -> V_108 -
( V_17 -> V_85 %
V_17 -> V_108 ) ;
F_60 ( V_105 , V_107 ) ;
V_106 = V_17 -> V_77 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_106 ;
}
}
F_13 (sg_req, &tdc->pending_sg_req, node) {
V_17 = V_28 -> V_17 ;
if ( V_17 -> V_14 . V_97 == V_97 ) {
V_107 = V_17 -> V_108 -
( V_17 -> V_85 %
V_17 -> V_108 ) ;
F_60 ( V_105 , V_107 ) ;
V_106 = V_17 -> V_77 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_106 ;
}
}
F_37 ( F_10 ( V_7 ) , L_11 , V_97 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_106 ;
}
static inline int F_61 ( struct V_6 * V_7 ,
enum V_109 V_110 )
{
switch ( V_110 ) {
case V_111 :
return V_112 ;
case V_113 :
return V_114 ;
case V_115 :
return V_116 ;
case V_117 :
return V_118 ;
default:
F_62 ( F_10 ( V_7 ) ,
L_12 ) ;
return V_116 ;
}
}
static inline int F_63 ( struct V_6 * V_7 ,
T_1 V_119 , enum V_109 V_110 , int V_120 )
{
int V_121 ;
int V_122 ;
V_121 = V_119 * V_110 ;
V_122 = V_121 / 4 ;
if ( ! V_122 ) {
if ( V_120 & 0xF )
return V_123 ;
else if ( ( V_120 >> 4 ) & 0x1 )
return V_124 ;
else
return V_125 ;
}
if ( V_122 < 4 )
return V_123 ;
else if ( V_122 < 8 )
return V_124 ;
else
return V_125 ;
}
static int F_64 ( struct V_6 * V_7 ,
enum V_126 V_127 , unsigned long * V_128 ,
unsigned long * V_59 , unsigned long * V_47 , unsigned int * V_119 ,
enum V_109 * V_110 )
{
switch ( V_127 ) {
case V_129 :
* V_128 = V_7 -> V_33 . V_130 ;
* V_59 = F_61 ( V_7 , V_7 -> V_33 . V_131 ) ;
* V_119 = V_7 -> V_33 . V_132 ;
* V_110 = V_7 -> V_33 . V_131 ;
* V_47 = V_133 ;
return 0 ;
case V_134 :
* V_128 = V_7 -> V_33 . V_135 ;
* V_59 = F_61 ( V_7 , V_7 -> V_33 . V_136 ) ;
* V_119 = V_7 -> V_33 . V_137 ;
* V_110 = V_7 -> V_33 . V_136 ;
* V_47 = 0 ;
return 0 ;
default:
F_18 ( F_10 ( V_7 ) , L_13 ) ;
return - V_138 ;
}
return - V_138 ;
}
static void F_65 ( struct V_6 * V_7 ,
struct V_56 * V_57 , T_1 V_120 )
{
T_1 V_139 = ( V_120 - 4 ) & 0xFFFC ;
if ( V_7 -> V_2 -> V_43 -> V_66 )
V_57 -> V_68 = V_139 ;
else
V_57 -> V_47 |= V_139 ;
}
static struct V_12 * F_66 (
struct V_9 * V_10 , struct V_140 * V_141 , unsigned int V_142 ,
enum V_126 V_127 , unsigned long V_18 ,
void * V_143 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 ;
unsigned int V_144 ;
struct V_140 * V_145 ;
unsigned long V_47 , V_63 , V_61 , V_59 ;
struct V_146 V_147 ;
struct V_27 * V_28 = NULL ;
T_1 V_119 ;
enum V_109 V_110 ;
if ( ! V_7 -> V_35 ) {
F_18 ( F_10 ( V_7 ) , L_14 ) ;
return NULL ;
}
if ( V_142 < 1 ) {
F_18 ( F_10 ( V_7 ) , L_15 , V_142 ) ;
return NULL ;
}
if ( F_64 ( V_7 , V_127 , & V_61 , & V_59 , & V_47 ,
& V_119 , & V_110 ) < 0 )
return NULL ;
F_67 ( & V_147 ) ;
V_63 = V_148 ;
V_63 |= V_149 <<
V_150 ;
V_63 |= V_151 ;
V_47 |= V_152 | V_153 ;
V_47 |= V_7 -> V_34 << V_154 ;
if ( V_18 & V_155 )
V_47 |= V_50 ;
V_59 |= V_156 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_18 ( F_10 ( V_7 ) , L_16 ) ;
return NULL ;
}
F_67 ( & V_17 -> V_24 ) ;
F_67 ( & V_17 -> V_80 ) ;
V_17 -> V_79 = 0 ;
V_17 -> V_108 = 0 ;
V_17 -> V_85 = 0 ;
V_17 -> V_77 = V_98 ;
F_68 (sgl, sg, sg_len, i) {
T_1 V_120 , V_157 ;
V_157 = F_69 ( V_145 ) ;
V_120 = F_70 ( V_145 ) ;
if ( ( V_120 & 3 ) || ( V_157 & 3 ) ||
( V_120 > V_7 -> V_2 -> V_43 -> V_158 ) ) {
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
V_63 |= F_63 ( V_7 , V_119 , V_110 , V_120 ) ;
V_17 -> V_108 += V_120 ;
V_28 -> V_57 . V_61 = V_61 ;
V_28 -> V_57 . V_65 = V_157 ;
V_28 -> V_57 . V_47 = V_47 ;
F_65 ( V_7 , & V_28 -> V_57 , V_120 ) ;
V_28 -> V_57 . V_59 = V_59 ;
V_28 -> V_57 . V_63 = V_63 ;
V_28 -> V_70 = false ;
V_28 -> V_76 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_73 = V_120 ;
F_23 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
}
V_28 -> V_76 = true ;
if ( V_18 & V_159 )
V_17 -> V_14 . V_18 = V_159 ;
if ( ! V_7 -> V_82 ) {
V_7 -> V_82 = F_47 ;
V_7 -> V_100 = false ;
} else {
if ( V_7 -> V_100 ) {
F_18 ( F_10 ( V_7 ) , L_19 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
}
return & V_17 -> V_14 ;
}
static struct V_12 * F_71 (
struct V_9 * V_10 , T_5 V_160 , T_6 V_161 ,
T_6 V_162 , enum V_126 V_127 ,
unsigned long V_18 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 = NULL ;
struct V_27 * V_28 = NULL ;
unsigned long V_47 , V_63 , V_61 , V_59 ;
int V_120 ;
T_6 V_163 ;
T_5 V_157 = V_160 ;
T_1 V_119 ;
enum V_109 V_110 ;
if ( ! V_161 || ! V_162 ) {
F_18 ( F_10 ( V_7 ) , L_20 ) ;
return NULL ;
}
if ( ! V_7 -> V_35 ) {
F_18 ( F_10 ( V_7 ) , L_21 ) ;
return NULL ;
}
if ( V_7 -> V_55 ) {
F_18 ( F_10 ( V_7 ) , L_22 ) ;
return NULL ;
}
if ( V_161 % V_162 ) {
F_18 ( F_10 ( V_7 ) , L_23 ) ;
return NULL ;
}
V_120 = V_162 ;
if ( ( V_120 & 3 ) || ( V_160 & 3 ) ||
( V_120 > V_7 -> V_2 -> V_43 -> V_158 ) ) {
F_18 ( F_10 ( V_7 ) , L_24 ) ;
return NULL ;
}
if ( F_64 ( V_7 , V_127 , & V_61 , & V_59 , & V_47 ,
& V_119 , & V_110 ) < 0 )
return NULL ;
V_63 = V_148 ;
V_63 |= V_149 <<
V_150 ;
V_63 |= V_151 ;
V_47 |= V_153 ;
if ( V_18 & V_155 )
V_47 |= V_50 ;
V_47 |= V_7 -> V_34 << V_154 ;
V_59 |= V_156 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_18 ( F_10 ( V_7 ) , L_25 ) ;
return NULL ;
}
F_67 ( & V_17 -> V_24 ) ;
F_67 ( & V_17 -> V_80 ) ;
V_17 -> V_79 = 0 ;
V_17 -> V_85 = 0 ;
V_17 -> V_108 = V_161 ;
V_163 = V_161 ;
while ( V_163 ) {
V_28 = F_24 ( V_7 ) ;
if ( ! V_28 ) {
F_18 ( F_10 ( V_7 ) , L_18 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
V_63 |= F_63 ( V_7 , V_119 , V_110 , V_120 ) ;
V_28 -> V_57 . V_61 = V_61 ;
V_28 -> V_57 . V_65 = V_157 ;
V_28 -> V_57 . V_47 = V_47 ;
F_65 ( V_7 , & V_28 -> V_57 , V_120 ) ;
V_28 -> V_57 . V_59 = V_59 ;
V_28 -> V_57 . V_63 = V_63 ;
V_28 -> V_70 = false ;
V_28 -> V_76 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_73 = V_120 ;
F_23 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
V_163 -= V_120 ;
V_157 += V_120 ;
}
V_28 -> V_76 = true ;
if ( V_18 & V_159 )
V_17 -> V_14 . V_18 = V_159 ;
if ( ! V_7 -> V_82 ) {
V_7 -> V_82 = F_49 ;
V_7 -> V_100 = true ;
} else {
if ( ! V_7 -> V_100 ) {
F_18 ( F_10 ( V_7 ) , L_26 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
}
return & V_17 -> V_14 ;
}
static int F_72 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_106 ;
F_73 ( & V_7 -> V_9 ) ;
V_7 -> V_35 = false ;
V_106 = F_74 ( V_2 -> V_164 ) ;
if ( V_106 < 0 )
F_18 ( F_10 ( V_7 ) , L_27 , V_106 ) ;
return V_106 ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_11 * V_17 ;
struct V_27 * V_28 ;
struct V_146 V_165 ;
struct V_146 V_166 ;
unsigned long V_18 ;
F_67 ( & V_165 ) ;
F_67 ( & V_166 ) ;
F_37 ( F_10 ( V_7 ) , L_28 , V_7 -> V_167 ) ;
if ( V_7 -> V_55 )
F_57 ( V_10 ) ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
F_22 ( & V_7 -> V_31 , & V_166 ) ;
F_22 ( & V_7 -> V_25 , & V_166 ) ;
F_22 ( & V_7 -> V_26 , & V_165 ) ;
F_67 ( & V_7 -> V_81 ) ;
V_7 -> V_35 = false ;
V_7 -> V_82 = NULL ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
while ( ! F_21 ( & V_165 ) ) {
V_17 = F_25 ( & V_165 ,
F_26 ( * V_17 ) , V_20 ) ;
F_15 ( & V_17 -> V_20 ) ;
F_76 ( V_17 ) ;
}
while ( ! F_21 ( & V_166 ) ) {
V_28 = F_25 ( & V_166 , F_26 ( * V_28 ) , V_20 ) ;
F_15 ( & V_28 -> V_20 ) ;
F_76 ( V_28 ) ;
}
F_77 ( V_2 -> V_164 ) ;
V_7 -> V_34 = 0 ;
}
static struct V_9 * F_78 ( struct V_168 * V_169 ,
struct V_170 * V_171 )
{
struct V_1 * V_2 = V_171 -> V_172 ;
struct V_9 * V_96 ;
struct V_6 * V_7 ;
V_96 = F_79 ( & V_2 -> V_173 ) ;
if ( ! V_96 )
return NULL ;
V_7 = F_7 ( V_96 ) ;
V_7 -> V_34 = V_169 -> args [ 0 ] ;
return V_96 ;
}
static int F_80 ( struct V_174 * V_175 )
{
struct V_176 * V_177 ;
struct V_1 * V_2 ;
int V_106 ;
int V_144 ;
const struct V_178 * V_179 = NULL ;
const struct V_180 * V_181 ;
V_181 = F_81 ( V_182 , & V_175 -> V_16 ) ;
if ( ! V_181 ) {
F_18 ( & V_175 -> V_16 , L_29 ) ;
return - V_183 ;
}
V_179 = V_181 -> V_88 ;
V_2 = F_82 ( & V_175 -> V_16 , sizeof( * V_2 ) + V_179 -> V_184 *
sizeof( struct V_6 ) , V_185 ) ;
if ( ! V_2 ) {
F_18 ( & V_175 -> V_16 , L_30 ) ;
return - V_186 ;
}
V_2 -> V_16 = & V_175 -> V_16 ;
V_2 -> V_43 = V_179 ;
F_83 ( V_175 , V_2 ) ;
V_177 = F_84 ( V_175 , V_187 , 0 ) ;
V_2 -> V_5 = F_85 ( & V_175 -> V_16 , V_177 ) ;
if ( F_86 ( V_2 -> V_5 ) )
return F_87 ( V_2 -> V_5 ) ;
V_2 -> V_164 = F_88 ( & V_175 -> V_16 , NULL ) ;
if ( F_86 ( V_2 -> V_164 ) ) {
F_18 ( & V_175 -> V_16 , L_31 ) ;
return F_87 ( V_2 -> V_164 ) ;
}
V_2 -> V_188 = F_89 ( & V_175 -> V_16 , L_32 ) ;
if ( F_86 ( V_2 -> V_188 ) ) {
F_18 ( & V_175 -> V_16 , L_33 ) ;
return F_87 ( V_2 -> V_188 ) ;
}
F_90 ( & V_2 -> V_37 ) ;
F_91 ( & V_175 -> V_16 ) ;
if ( ! F_92 ( & V_175 -> V_16 ) ) {
V_106 = F_93 ( & V_175 -> V_16 ) ;
if ( V_106 ) {
F_18 ( & V_175 -> V_16 , L_34 ,
V_106 ) ;
goto V_189;
}
}
V_106 = F_74 ( V_2 -> V_164 ) ;
if ( V_106 < 0 ) {
F_18 ( & V_175 -> V_16 , L_27 , V_106 ) ;
goto V_189;
}
F_94 ( V_2 -> V_188 ) ;
F_30 ( 2 ) ;
F_95 ( V_2 -> V_188 ) ;
F_1 ( V_2 , V_39 , V_42 ) ;
F_1 ( V_2 , V_190 , 0 ) ;
F_1 ( V_2 , V_191 , 0xFFFFFFFFul ) ;
F_77 ( V_2 -> V_164 ) ;
F_67 ( & V_2 -> V_173 . V_192 ) ;
for ( V_144 = 0 ; V_144 < V_179 -> V_184 ; V_144 ++ ) {
struct V_6 * V_7 = & V_2 -> V_192 [ V_144 ] ;
V_7 -> V_8 = V_2 -> V_5 +
V_193 +
( V_144 * V_179 -> V_194 ) ;
V_177 = F_84 ( V_175 , V_195 , V_144 ) ;
if ( ! V_177 ) {
V_106 = - V_138 ;
F_18 ( & V_175 -> V_16 , L_35 , V_144 ) ;
goto V_196;
}
V_7 -> V_91 = V_177 -> V_197 ;
snprintf ( V_7 -> V_198 , sizeof( V_7 -> V_198 ) , L_36 , V_144 ) ;
V_106 = F_96 ( & V_175 -> V_16 , V_7 -> V_91 ,
F_51 , 0 , V_7 -> V_198 , V_7 ) ;
if ( V_106 ) {
F_18 ( & V_175 -> V_16 ,
L_37 ,
V_106 , V_144 ) ;
goto V_196;
}
V_7 -> V_9 . V_15 = & V_2 -> V_173 ;
F_73 ( & V_7 -> V_9 ) ;
F_23 ( & V_7 -> V_9 . V_199 ,
& V_2 -> V_173 . V_192 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_167 = V_144 ;
F_97 ( & V_7 -> V_93 , F_50 ,
( unsigned long ) V_7 ) ;
F_90 ( & V_7 -> V_19 ) ;
F_67 ( & V_7 -> V_31 ) ;
F_67 ( & V_7 -> V_25 ) ;
F_67 ( & V_7 -> V_26 ) ;
F_67 ( & V_7 -> V_81 ) ;
}
F_98 ( V_200 , V_2 -> V_173 . V_201 ) ;
F_98 ( V_202 , V_2 -> V_173 . V_201 ) ;
F_98 ( V_203 , V_2 -> V_173 . V_201 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_173 . V_16 = & V_175 -> V_16 ;
V_2 -> V_173 . V_204 =
F_72 ;
V_2 -> V_173 . V_205 =
F_75 ;
V_2 -> V_173 . V_206 = F_66 ;
V_2 -> V_173 . V_207 = F_71 ;
V_2 -> V_173 . V_208 = F_99 ( V_111 ) |
F_99 ( V_113 ) |
F_99 ( V_115 ) |
F_99 ( V_117 ) ;
V_2 -> V_173 . V_209 = F_99 ( V_111 ) |
F_99 ( V_113 ) |
F_99 ( V_115 ) |
F_99 ( V_117 ) ;
V_2 -> V_173 . V_210 = F_99 ( V_134 ) | F_99 ( V_129 ) ;
V_2 -> V_173 . V_211 = V_212 ;
V_2 -> V_173 . V_213 = F_27 ;
V_2 -> V_173 . V_214 = F_57 ;
V_2 -> V_173 . V_215 = F_58 ;
V_2 -> V_173 . V_216 = F_56 ;
V_106 = F_100 ( & V_2 -> V_173 ) ;
if ( V_106 < 0 ) {
F_18 ( & V_175 -> V_16 ,
L_38 , V_106 ) ;
goto V_196;
}
V_106 = F_101 ( V_175 -> V_16 . V_217 ,
F_78 , V_2 ) ;
if ( V_106 < 0 ) {
F_18 ( & V_175 -> V_16 ,
L_39 , V_106 ) ;
goto V_218;
}
F_53 ( & V_175 -> V_16 , L_40 ,
V_179 -> V_184 ) ;
return 0 ;
V_218:
F_102 ( & V_2 -> V_173 ) ;
V_196:
while ( -- V_144 >= 0 ) {
struct V_6 * V_7 = & V_2 -> V_192 [ V_144 ] ;
F_103 ( & V_7 -> V_93 ) ;
}
V_189:
F_104 ( & V_175 -> V_16 ) ;
if ( ! F_105 ( & V_175 -> V_16 ) )
F_106 ( & V_175 -> V_16 ) ;
return V_106 ;
}
static int F_107 ( struct V_174 * V_175 )
{
struct V_1 * V_2 = F_108 ( V_175 ) ;
int V_144 ;
struct V_6 * V_7 ;
F_102 ( & V_2 -> V_173 ) ;
for ( V_144 = 0 ; V_144 < V_2 -> V_43 -> V_184 ; ++ V_144 ) {
V_7 = & V_2 -> V_192 [ V_144 ] ;
F_103 ( & V_7 -> V_93 ) ;
}
F_104 ( & V_175 -> V_16 ) ;
if ( ! F_105 ( & V_175 -> V_16 ) )
F_106 ( & V_175 -> V_16 ) ;
return 0 ;
}
static int F_106 ( struct V_15 * V_16 )
{
struct V_174 * V_175 = F_109 ( V_16 ) ;
struct V_1 * V_2 = F_108 ( V_175 ) ;
F_77 ( V_2 -> V_164 ) ;
return 0 ;
}
static int F_93 ( struct V_15 * V_16 )
{
struct V_174 * V_175 = F_109 ( V_16 ) ;
struct V_1 * V_2 = F_108 ( V_175 ) ;
int V_106 ;
V_106 = F_74 ( V_2 -> V_164 ) ;
if ( V_106 < 0 ) {
F_18 ( V_16 , L_41 , V_106 ) ;
return V_106 ;
}
return 0 ;
}
static int F_110 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_111 ( V_16 ) ;
int V_144 ;
int V_106 ;
V_106 = F_93 ( V_16 ) ;
if ( V_106 < 0 )
return V_106 ;
V_2 -> V_219 = F_3 ( V_2 , V_39 ) ;
for ( V_144 = 0 ; V_144 < V_2 -> V_43 -> V_184 ; V_144 ++ ) {
struct V_6 * V_7 = & V_2 -> V_192 [ V_144 ] ;
struct V_56 * V_220 = & V_7 -> V_221 ;
V_220 -> V_47 = F_6 ( V_7 , V_49 ) ;
V_220 -> V_65 = F_6 ( V_7 , V_64 ) ;
V_220 -> V_61 = F_6 ( V_7 , V_60 ) ;
V_220 -> V_63 = F_6 ( V_7 , V_62 ) ;
V_220 -> V_59 = F_6 ( V_7 , V_58 ) ;
}
F_106 ( V_16 ) ;
return 0 ;
}
static int F_112 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_111 ( V_16 ) ;
int V_144 ;
int V_106 ;
V_106 = F_93 ( V_16 ) ;
if ( V_106 < 0 )
return V_106 ;
F_1 ( V_2 , V_39 , V_2 -> V_219 ) ;
F_1 ( V_2 , V_190 , 0 ) ;
F_1 ( V_2 , V_191 , 0xFFFFFFFFul ) ;
for ( V_144 = 0 ; V_144 < V_2 -> V_43 -> V_184 ; V_144 ++ ) {
struct V_6 * V_7 = & V_2 -> V_192 [ V_144 ] ;
struct V_56 * V_220 = & V_7 -> V_221 ;
F_5 ( V_7 , V_58 , V_220 -> V_59 ) ;
F_5 ( V_7 , V_60 , V_220 -> V_61 ) ;
F_5 ( V_7 , V_62 , V_220 -> V_63 ) ;
F_5 ( V_7 , V_64 , V_220 -> V_65 ) ;
F_5 ( V_7 , V_49 ,
( V_220 -> V_47 & ~ V_51 ) ) ;
}
F_106 ( V_16 ) ;
return 0 ;
}
