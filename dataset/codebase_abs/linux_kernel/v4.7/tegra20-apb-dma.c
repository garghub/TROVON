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
F_37 ( F_10 ( V_7 ) , L_4 , V_57 ) ;
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
F_18 ( F_10 ( V_7 ) ,
L_5 ) ;
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
if ( F_21 ( & V_7 -> V_31 ) )
return;
V_28 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_28 ) , V_20 ) ;
F_38 ( V_7 , V_28 ) ;
V_28 -> V_73 = true ;
V_7 -> V_58 = true ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_27 * V_74 ;
struct V_27 * V_75 ;
if ( F_21 ( & V_7 -> V_31 ) )
return;
V_74 = F_25 ( & V_7 -> V_31 , F_26 ( * V_74 ) , V_20 ) ;
if ( ! F_42 ( & V_74 -> V_20 , & V_7 -> V_31 ) ) {
V_75 = F_25 ( & V_74 -> V_20 ,
F_26 ( * V_75 ) , V_20 ) ;
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
while ( ! F_21 ( & V_7 -> V_31 ) ) {
V_78 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_78 ) , V_20 ) ;
F_45 ( & V_78 -> V_20 , & V_7 -> V_25 ) ;
if ( V_78 -> V_79 ) {
V_17 = V_78 -> V_17 ;
V_17 -> V_80 = V_81 ;
F_23 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
if ( ! V_17 -> V_82 )
F_23 ( & V_17 -> V_83 ,
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
if ( F_21 ( & V_7 -> V_31 ) ) {
F_18 ( F_10 ( V_7 ) , L_6 ) ;
F_36 ( V_7 ) ;
return false ;
}
V_74 = F_25 ( & V_7 -> V_31 , F_26 ( * V_74 ) , V_20 ) ;
if ( ! V_74 -> V_73 ) {
F_36 ( V_7 ) ;
F_18 ( F_10 ( V_7 ) , L_7 ) ;
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
V_78 = F_25 ( & V_7 -> V_31 , F_26 ( * V_78 ) , V_20 ) ;
V_17 = V_78 -> V_17 ;
V_17 -> V_88 += V_78 -> V_76 ;
F_15 ( & V_78 -> V_20 ) ;
if ( V_78 -> V_79 ) {
V_17 -> V_80 = V_89 ;
F_48 ( & V_17 -> V_14 ) ;
if ( ! V_17 -> V_82 )
F_23 ( & V_17 -> V_83 , & V_7 -> V_84 ) ;
V_17 -> V_82 ++ ;
F_23 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
}
F_23 ( & V_78 -> V_20 , & V_7 -> V_25 ) ;
if ( V_87 || F_21 ( & V_7 -> V_31 ) )
return;
F_40 ( V_7 ) ;
}
static void F_49 ( struct V_6 * V_7 ,
bool V_87 )
{
struct V_27 * V_78 ;
struct V_11 * V_17 ;
bool V_90 ;
V_78 = F_25 ( & V_7 -> V_31 , F_26 ( * V_78 ) , V_20 ) ;
V_17 = V_78 -> V_17 ;
V_17 -> V_88 += V_78 -> V_76 ;
if ( ! V_17 -> V_82 )
F_23 ( & V_17 -> V_83 , & V_7 -> V_84 ) ;
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
while ( ! F_21 ( & V_7 -> V_84 ) ) {
V_17 = F_25 ( & V_7 -> V_84 ,
F_26 ( * V_17 ) , V_83 ) ;
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
L_8 , V_51 ) ;
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
if ( F_21 ( & V_7 -> V_31 ) ) {
F_18 ( F_10 ( V_7 ) , L_9 ) ;
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
if ( F_21 ( & V_7 -> V_31 ) ) {
F_16 ( & V_7 -> V_19 , V_18 ) ;
return 0 ;
}
if ( ! V_7 -> V_58 )
goto V_105;
F_34 ( V_7 , true ) ;
V_51 = F_6 ( V_7 , V_55 ) ;
if ( V_51 & V_56 ) {
F_37 ( F_10 ( V_7 ) , L_10 , V_57 ) ;
V_7 -> V_85 ( V_7 , true ) ;
V_51 = F_6 ( V_7 , V_55 ) ;
}
if ( V_7 -> V_2 -> V_46 -> V_69 )
V_71 = F_6 ( V_7 , V_106 ) ;
else
V_71 = V_51 ;
V_104 = V_7 -> V_58 ;
F_36 ( V_7 ) ;
if ( ! F_21 ( & V_7 -> V_31 ) && V_104 ) {
V_78 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_78 ) , V_20 ) ;
V_78 -> V_17 -> V_88 +=
F_43 ( V_7 , V_78 , V_71 ) ;
}
F_35 ( V_7 ) ;
V_105:
F_44 ( V_7 ) ;
while ( ! F_21 ( & V_7 -> V_84 ) ) {
V_17 = F_25 ( & V_7 -> V_84 ,
F_26 ( * V_17 ) , V_83 ) ;
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
V_110 = V_17 -> V_111 -
( V_17 -> V_88 %
V_17 -> V_111 ) ;
F_60 ( V_108 , V_110 ) ;
V_109 = V_17 -> V_80 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_109 ;
}
}
F_13 (sg_req, &tdc->pending_sg_req, node) {
V_17 = V_28 -> V_17 ;
if ( V_17 -> V_14 . V_100 == V_100 ) {
V_110 = V_17 -> V_111 -
( V_17 -> V_88 %
V_17 -> V_111 ) ;
F_60 ( V_108 , V_110 ) ;
V_109 = V_17 -> V_80 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_109 ;
}
}
F_37 ( F_10 ( V_7 ) , L_11 , V_100 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_109 ;
}
static inline int F_61 ( struct V_6 * V_7 ,
enum V_112 V_113 )
{
switch ( V_113 ) {
case V_114 :
return V_115 ;
case V_116 :
return V_117 ;
case V_118 :
return V_119 ;
case V_120 :
return V_121 ;
default:
F_62 ( F_10 ( V_7 ) ,
L_12 ) ;
return V_119 ;
}
}
static inline int F_63 ( struct V_6 * V_7 ,
T_1 V_122 , enum V_112 V_113 , int V_123 )
{
int V_124 ;
int V_125 ;
V_124 = V_122 * V_113 ;
V_125 = V_124 / 4 ;
if ( ! V_125 ) {
if ( V_123 & 0xF )
return V_126 ;
else if ( ( V_123 >> 4 ) & 0x1 )
return V_127 ;
else
return V_128 ;
}
if ( V_125 < 4 )
return V_126 ;
else if ( V_125 < 8 )
return V_127 ;
else
return V_128 ;
}
static int F_64 ( struct V_6 * V_7 ,
enum V_129 V_130 , unsigned long * V_131 ,
unsigned long * V_62 , unsigned long * V_50 , unsigned int * V_122 ,
enum V_112 * V_113 )
{
switch ( V_130 ) {
case V_132 :
* V_131 = V_7 -> V_33 . V_133 ;
* V_62 = F_61 ( V_7 , V_7 -> V_33 . V_134 ) ;
* V_122 = V_7 -> V_33 . V_135 ;
* V_113 = V_7 -> V_33 . V_134 ;
* V_50 = V_136 ;
return 0 ;
case V_137 :
* V_131 = V_7 -> V_33 . V_138 ;
* V_62 = F_61 ( V_7 , V_7 -> V_33 . V_139 ) ;
* V_122 = V_7 -> V_33 . V_140 ;
* V_113 = V_7 -> V_33 . V_139 ;
* V_50 = 0 ;
return 0 ;
default:
F_18 ( F_10 ( V_7 ) , L_13 ) ;
return - V_37 ;
}
return - V_37 ;
}
static void F_65 ( struct V_6 * V_7 ,
struct V_59 * V_60 , T_1 V_123 )
{
T_1 V_141 = ( V_123 - 4 ) & 0xFFFC ;
if ( V_7 -> V_2 -> V_46 -> V_69 )
V_60 -> V_71 = V_141 ;
else
V_60 -> V_50 |= V_141 ;
}
static struct V_12 * F_66 (
struct V_9 * V_10 , struct V_142 * V_143 , unsigned int V_144 ,
enum V_129 V_130 , unsigned long V_18 ,
void * V_145 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 ;
unsigned int V_146 ;
struct V_142 * V_147 ;
unsigned long V_50 , V_66 , V_64 , V_62 ;
struct V_148 V_149 ;
struct V_27 * V_28 = NULL ;
T_1 V_122 ;
enum V_112 V_113 ;
if ( ! V_7 -> V_38 ) {
F_18 ( F_10 ( V_7 ) , L_14 ) ;
return NULL ;
}
if ( V_144 < 1 ) {
F_18 ( F_10 ( V_7 ) , L_15 , V_144 ) ;
return NULL ;
}
if ( F_64 ( V_7 , V_130 , & V_64 , & V_62 , & V_50 ,
& V_122 , & V_113 ) < 0 )
return NULL ;
F_67 ( & V_149 ) ;
V_66 = V_150 ;
V_66 |= V_151 <<
V_152 ;
V_66 |= V_153 ;
V_50 |= V_154 | V_155 ;
V_50 |= V_7 -> V_34 << V_156 ;
if ( V_18 & V_157 )
V_50 |= V_53 ;
V_62 |= V_158 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_18 ( F_10 ( V_7 ) , L_16 ) ;
return NULL ;
}
F_67 ( & V_17 -> V_24 ) ;
F_67 ( & V_17 -> V_83 ) ;
V_17 -> V_82 = 0 ;
V_17 -> V_111 = 0 ;
V_17 -> V_88 = 0 ;
V_17 -> V_80 = V_101 ;
F_68 (sgl, sg, sg_len, i) {
T_1 V_123 , V_159 ;
V_159 = F_69 ( V_147 ) ;
V_123 = F_70 ( V_147 ) ;
if ( ( V_123 & 3 ) || ( V_159 & 3 ) ||
( V_123 > V_7 -> V_2 -> V_46 -> V_160 ) ) {
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
V_66 |= F_63 ( V_7 , V_122 , V_113 , V_123 ) ;
V_17 -> V_111 += V_123 ;
V_28 -> V_60 . V_64 = V_64 ;
V_28 -> V_60 . V_68 = V_159 ;
V_28 -> V_60 . V_50 = V_50 ;
F_65 ( V_7 , & V_28 -> V_60 , V_123 ) ;
V_28 -> V_60 . V_62 = V_62 ;
V_28 -> V_60 . V_66 = V_66 ;
V_28 -> V_73 = false ;
V_28 -> V_79 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_76 = V_123 ;
F_23 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
}
V_28 -> V_79 = true ;
if ( V_18 & V_161 )
V_17 -> V_14 . V_18 = V_161 ;
if ( ! V_7 -> V_85 ) {
V_7 -> V_85 = F_47 ;
V_7 -> V_103 = false ;
} else {
if ( V_7 -> V_103 ) {
F_18 ( F_10 ( V_7 ) , L_19 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
}
return & V_17 -> V_14 ;
}
static struct V_12 * F_71 (
struct V_9 * V_10 , T_5 V_162 , T_6 V_163 ,
T_6 V_164 , enum V_129 V_130 ,
unsigned long V_18 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 = NULL ;
struct V_27 * V_28 = NULL ;
unsigned long V_50 , V_66 , V_64 , V_62 ;
int V_123 ;
T_6 V_165 ;
T_5 V_159 = V_162 ;
T_1 V_122 ;
enum V_112 V_113 ;
if ( ! V_163 || ! V_164 ) {
F_18 ( F_10 ( V_7 ) , L_20 ) ;
return NULL ;
}
if ( ! V_7 -> V_38 ) {
F_18 ( F_10 ( V_7 ) , L_21 ) ;
return NULL ;
}
if ( V_7 -> V_58 ) {
F_18 ( F_10 ( V_7 ) , L_22 ) ;
return NULL ;
}
if ( V_163 % V_164 ) {
F_18 ( F_10 ( V_7 ) , L_23 ) ;
return NULL ;
}
V_123 = V_164 ;
if ( ( V_123 & 3 ) || ( V_162 & 3 ) ||
( V_123 > V_7 -> V_2 -> V_46 -> V_160 ) ) {
F_18 ( F_10 ( V_7 ) , L_24 ) ;
return NULL ;
}
if ( F_64 ( V_7 , V_130 , & V_64 , & V_62 , & V_50 ,
& V_122 , & V_113 ) < 0 )
return NULL ;
V_66 = V_150 ;
V_66 |= V_151 <<
V_152 ;
V_66 |= V_153 ;
V_50 |= V_155 ;
if ( V_18 & V_157 )
V_50 |= V_53 ;
V_50 |= V_7 -> V_34 << V_156 ;
V_62 |= V_158 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_18 ( F_10 ( V_7 ) , L_25 ) ;
return NULL ;
}
F_67 ( & V_17 -> V_24 ) ;
F_67 ( & V_17 -> V_83 ) ;
V_17 -> V_82 = 0 ;
V_17 -> V_88 = 0 ;
V_17 -> V_111 = V_163 ;
V_165 = V_163 ;
while ( V_165 ) {
V_28 = F_24 ( V_7 ) ;
if ( ! V_28 ) {
F_18 ( F_10 ( V_7 ) , L_18 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
V_66 |= F_63 ( V_7 , V_122 , V_113 , V_123 ) ;
V_28 -> V_60 . V_64 = V_64 ;
V_28 -> V_60 . V_68 = V_159 ;
V_28 -> V_60 . V_50 = V_50 ;
F_65 ( V_7 , & V_28 -> V_60 , V_123 ) ;
V_28 -> V_60 . V_62 = V_62 ;
V_28 -> V_60 . V_66 = V_66 ;
V_28 -> V_73 = false ;
V_28 -> V_79 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_76 = V_123 ;
F_23 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
V_165 -= V_123 ;
V_159 += V_123 ;
}
V_28 -> V_79 = true ;
if ( V_18 & V_161 )
V_17 -> V_14 . V_18 = V_161 ;
if ( ! V_7 -> V_85 ) {
V_7 -> V_85 = F_49 ;
V_7 -> V_103 = true ;
} else {
if ( ! V_7 -> V_103 ) {
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
struct V_148 V_166 ;
struct V_148 V_167 ;
unsigned long V_18 ;
F_67 ( & V_166 ) ;
F_67 ( & V_167 ) ;
F_37 ( F_10 ( V_7 ) , L_27 , V_7 -> V_168 ) ;
if ( V_7 -> V_58 )
F_57 ( V_10 ) ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
F_22 ( & V_7 -> V_31 , & V_167 ) ;
F_22 ( & V_7 -> V_25 , & V_167 ) ;
F_22 ( & V_7 -> V_26 , & V_166 ) ;
F_67 ( & V_7 -> V_84 ) ;
V_7 -> V_38 = false ;
V_7 -> V_85 = NULL ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
while ( ! F_21 ( & V_166 ) ) {
V_17 = F_25 ( & V_166 ,
F_26 ( * V_17 ) , V_20 ) ;
F_15 ( & V_17 -> V_20 ) ;
F_76 ( V_17 ) ;
}
while ( ! F_21 ( & V_167 ) ) {
V_28 = F_25 ( & V_167 , F_26 ( * V_28 ) , V_20 ) ;
F_15 ( & V_28 -> V_20 ) ;
F_76 ( V_28 ) ;
}
F_77 ( V_2 -> V_16 ) ;
V_7 -> V_34 = V_35 ;
}
static struct V_9 * F_78 ( struct V_169 * V_170 ,
struct V_171 * V_172 )
{
struct V_1 * V_2 = V_172 -> V_173 ;
struct V_9 * V_99 ;
struct V_6 * V_7 ;
if ( V_170 -> args [ 0 ] > V_36 ) {
F_18 ( V_2 -> V_16 , L_28 , V_170 -> args [ 0 ] ) ;
return NULL ;
}
V_99 = F_79 ( & V_2 -> V_174 ) ;
if ( ! V_99 )
return NULL ;
V_7 = F_7 ( V_99 ) ;
V_7 -> V_34 = V_170 -> args [ 0 ] ;
return V_99 ;
}
static int F_80 ( struct V_175 * V_176 )
{
struct V_177 * V_178 ;
struct V_1 * V_2 ;
int V_109 ;
int V_146 ;
const struct V_179 * V_180 ;
V_180 = F_81 ( & V_176 -> V_16 ) ;
if ( ! V_180 ) {
F_18 ( & V_176 -> V_16 , L_29 ) ;
return - V_181 ;
}
V_2 = F_82 ( & V_176 -> V_16 , sizeof( * V_2 ) + V_180 -> V_182 *
sizeof( struct V_6 ) , V_183 ) ;
if ( ! V_2 ) {
F_18 ( & V_176 -> V_16 , L_30 ) ;
return - V_184 ;
}
V_2 -> V_16 = & V_176 -> V_16 ;
V_2 -> V_46 = V_180 ;
F_83 ( V_176 , V_2 ) ;
V_178 = F_84 ( V_176 , V_185 , 0 ) ;
V_2 -> V_5 = F_85 ( & V_176 -> V_16 , V_178 ) ;
if ( F_86 ( V_2 -> V_5 ) )
return F_87 ( V_2 -> V_5 ) ;
V_2 -> V_186 = F_88 ( & V_176 -> V_16 , NULL ) ;
if ( F_86 ( V_2 -> V_186 ) ) {
F_18 ( & V_176 -> V_16 , L_31 ) ;
return F_87 ( V_2 -> V_186 ) ;
}
V_2 -> V_187 = F_89 ( & V_176 -> V_16 , L_32 ) ;
if ( F_86 ( V_2 -> V_187 ) ) {
F_18 ( & V_176 -> V_16 , L_33 ) ;
return F_87 ( V_2 -> V_187 ) ;
}
F_90 ( & V_2 -> V_40 ) ;
F_91 ( & V_176 -> V_16 ) ;
if ( ! F_92 ( & V_176 -> V_16 ) )
V_109 = F_93 ( & V_176 -> V_16 ) ;
else
V_109 = F_74 ( & V_176 -> V_16 ) ;
if ( V_109 < 0 ) {
F_94 ( & V_176 -> V_16 ) ;
return V_109 ;
}
F_95 ( V_2 -> V_187 ) ;
F_30 ( 2 ) ;
F_96 ( V_2 -> V_187 ) ;
F_1 ( V_2 , V_42 , V_45 ) ;
F_1 ( V_2 , V_188 , 0 ) ;
F_1 ( V_2 , V_189 , 0xFFFFFFFFul ) ;
F_77 ( & V_176 -> V_16 ) ;
F_67 ( & V_2 -> V_174 . V_190 ) ;
for ( V_146 = 0 ; V_146 < V_180 -> V_182 ; V_146 ++ ) {
struct V_6 * V_7 = & V_2 -> V_190 [ V_146 ] ;
V_7 -> V_8 = V_2 -> V_5 +
V_191 +
( V_146 * V_180 -> V_192 ) ;
V_178 = F_84 ( V_176 , V_193 , V_146 ) ;
if ( ! V_178 ) {
V_109 = - V_37 ;
F_18 ( & V_176 -> V_16 , L_34 , V_146 ) ;
goto V_194;
}
V_7 -> V_94 = V_178 -> V_195 ;
snprintf ( V_7 -> V_196 , sizeof( V_7 -> V_196 ) , L_35 , V_146 ) ;
V_109 = F_97 ( V_7 -> V_94 , F_51 , 0 , V_7 -> V_196 , V_7 ) ;
if ( V_109 ) {
F_18 ( & V_176 -> V_16 ,
L_36 ,
V_109 , V_146 ) ;
goto V_194;
}
V_7 -> V_9 . V_15 = & V_2 -> V_174 ;
F_73 ( & V_7 -> V_9 ) ;
F_23 ( & V_7 -> V_9 . V_197 ,
& V_2 -> V_174 . V_190 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_168 = V_146 ;
V_7 -> V_34 = V_35 ;
F_98 ( & V_7 -> V_96 , F_50 ,
( unsigned long ) V_7 ) ;
F_90 ( & V_7 -> V_19 ) ;
F_67 ( & V_7 -> V_31 ) ;
F_67 ( & V_7 -> V_25 ) ;
F_67 ( & V_7 -> V_26 ) ;
F_67 ( & V_7 -> V_84 ) ;
}
F_99 ( V_198 , V_2 -> V_174 . V_199 ) ;
F_99 ( V_200 , V_2 -> V_174 . V_199 ) ;
F_99 ( V_201 , V_2 -> V_174 . V_199 ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_174 . V_16 = & V_176 -> V_16 ;
V_2 -> V_174 . V_202 =
F_72 ;
V_2 -> V_174 . V_203 =
F_75 ;
V_2 -> V_174 . V_204 = F_66 ;
V_2 -> V_174 . V_205 = F_71 ;
V_2 -> V_174 . V_206 = F_100 ( V_114 ) |
F_100 ( V_116 ) |
F_100 ( V_118 ) |
F_100 ( V_120 ) ;
V_2 -> V_174 . V_207 = F_100 ( V_114 ) |
F_100 ( V_116 ) |
F_100 ( V_118 ) |
F_100 ( V_120 ) ;
V_2 -> V_174 . V_208 = F_100 ( V_137 ) | F_100 ( V_132 ) ;
V_2 -> V_174 . V_209 = V_210 ;
V_2 -> V_174 . V_211 = F_27 ;
V_2 -> V_174 . V_212 = F_57 ;
V_2 -> V_174 . V_213 = F_58 ;
V_2 -> V_174 . V_214 = F_56 ;
V_109 = F_101 ( & V_2 -> V_174 ) ;
if ( V_109 < 0 ) {
F_18 ( & V_176 -> V_16 ,
L_37 , V_109 ) ;
goto V_194;
}
V_109 = F_102 ( V_176 -> V_16 . V_215 ,
F_78 , V_2 ) ;
if ( V_109 < 0 ) {
F_18 ( & V_176 -> V_16 ,
L_38 , V_109 ) ;
goto V_216;
}
F_53 ( & V_176 -> V_16 , L_39 ,
V_180 -> V_182 ) ;
return 0 ;
V_216:
F_103 ( & V_2 -> V_174 ) ;
V_194:
while ( -- V_146 >= 0 ) {
struct V_6 * V_7 = & V_2 -> V_190 [ V_146 ] ;
F_104 ( V_7 -> V_94 , V_7 ) ;
F_105 ( & V_7 -> V_96 ) ;
}
F_94 ( & V_176 -> V_16 ) ;
if ( ! F_106 ( & V_176 -> V_16 ) )
F_107 ( & V_176 -> V_16 ) ;
return V_109 ;
}
static int F_108 ( struct V_175 * V_176 )
{
struct V_1 * V_2 = F_109 ( V_176 ) ;
int V_146 ;
struct V_6 * V_7 ;
F_103 ( & V_2 -> V_174 ) ;
for ( V_146 = 0 ; V_146 < V_2 -> V_46 -> V_182 ; ++ V_146 ) {
V_7 = & V_2 -> V_190 [ V_146 ] ;
F_104 ( V_7 -> V_94 , V_7 ) ;
F_105 ( & V_7 -> V_96 ) ;
}
F_94 ( & V_176 -> V_16 ) ;
if ( ! F_106 ( & V_176 -> V_16 ) )
F_107 ( & V_176 -> V_16 ) ;
return 0 ;
}
static int F_107 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_110 ( V_16 ) ;
F_111 ( V_2 -> V_186 ) ;
return 0 ;
}
static int F_93 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_110 ( V_16 ) ;
int V_109 ;
V_109 = F_112 ( V_2 -> V_186 ) ;
if ( V_109 < 0 ) {
F_18 ( V_16 , L_40 , V_109 ) ;
return V_109 ;
}
return 0 ;
}
static int F_113 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_110 ( V_16 ) ;
int V_146 ;
int V_109 ;
V_109 = F_74 ( V_16 ) ;
if ( V_109 < 0 )
return V_109 ;
V_2 -> V_217 = F_3 ( V_2 , V_42 ) ;
for ( V_146 = 0 ; V_146 < V_2 -> V_46 -> V_182 ; V_146 ++ ) {
struct V_6 * V_7 = & V_2 -> V_190 [ V_146 ] ;
struct V_59 * V_218 = & V_7 -> V_219 ;
if ( ! V_7 -> V_38 )
continue;
V_218 -> V_50 = F_6 ( V_7 , V_52 ) ;
V_218 -> V_68 = F_6 ( V_7 , V_67 ) ;
V_218 -> V_64 = F_6 ( V_7 , V_63 ) ;
V_218 -> V_66 = F_6 ( V_7 , V_65 ) ;
V_218 -> V_62 = F_6 ( V_7 , V_61 ) ;
if ( V_2 -> V_46 -> V_69 )
V_218 -> V_71 = F_6 ( V_7 ,
V_70 ) ;
}
F_77 ( V_16 ) ;
return 0 ;
}
static int F_114 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_110 ( V_16 ) ;
int V_146 ;
int V_109 ;
V_109 = F_74 ( V_16 ) ;
if ( V_109 < 0 )
return V_109 ;
F_1 ( V_2 , V_42 , V_2 -> V_217 ) ;
F_1 ( V_2 , V_188 , 0 ) ;
F_1 ( V_2 , V_189 , 0xFFFFFFFFul ) ;
for ( V_146 = 0 ; V_146 < V_2 -> V_46 -> V_182 ; V_146 ++ ) {
struct V_6 * V_7 = & V_2 -> V_190 [ V_146 ] ;
struct V_59 * V_218 = & V_7 -> V_219 ;
if ( ! V_7 -> V_38 )
continue;
if ( V_2 -> V_46 -> V_69 )
F_5 ( V_7 , V_70 ,
V_218 -> V_71 ) ;
F_5 ( V_7 , V_61 , V_218 -> V_62 ) ;
F_5 ( V_7 , V_63 , V_218 -> V_64 ) ;
F_5 ( V_7 , V_65 , V_218 -> V_66 ) ;
F_5 ( V_7 , V_67 , V_218 -> V_68 ) ;
F_5 ( V_7 , V_52 ,
( V_218 -> V_50 & ~ V_54 ) ) ;
}
F_77 ( V_16 ) ;
return 0 ;
}
