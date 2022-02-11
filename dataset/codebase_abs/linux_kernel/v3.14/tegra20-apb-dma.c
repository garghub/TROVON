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
F_1 ( V_2 , V_38 , 0 ) ;
if ( V_36 )
F_30 ( V_39 ) ;
}
static void F_31 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_1 ( V_2 , V_38 , V_40 ) ;
F_32 ( & V_2 -> V_37 ) ;
}
static void F_33 ( struct V_6 * V_7 ,
bool V_36 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_2 -> V_41 -> V_42 ) {
F_5 ( V_7 , V_43 ,
V_44 ) ;
if ( V_36 )
F_30 ( V_39 ) ;
} else {
F_28 ( V_7 , V_36 ) ;
}
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_2 -> V_41 -> V_42 ) {
F_5 ( V_7 , V_43 , 0 ) ;
} else {
F_31 ( V_7 ) ;
}
}
static void F_35 ( struct V_6 * V_7 )
{
T_1 V_45 ;
T_1 V_46 ;
V_45 = F_6 ( V_7 , V_47 ) ;
V_45 &= ~ V_48 ;
F_5 ( V_7 , V_47 , V_45 ) ;
V_45 &= ~ V_49 ;
F_5 ( V_7 , V_47 , V_45 ) ;
V_46 = F_6 ( V_7 , V_50 ) ;
if ( V_46 & V_51 ) {
F_36 ( F_10 ( V_7 ) , L_4 , V_52 ) ;
F_5 ( V_7 , V_50 , V_46 ) ;
}
V_7 -> V_53 = false ;
}
static void F_37 ( struct V_6 * V_7 ,
struct V_27 * V_28 )
{
struct V_54 * V_55 = & V_28 -> V_55 ;
F_5 ( V_7 , V_47 , V_55 -> V_45 ) ;
F_5 ( V_7 , V_56 , V_55 -> V_57 ) ;
F_5 ( V_7 , V_58 , V_55 -> V_59 ) ;
F_5 ( V_7 , V_60 , V_55 -> V_61 ) ;
F_5 ( V_7 , V_62 , V_55 -> V_63 ) ;
if ( V_7 -> V_2 -> V_41 -> V_64 )
F_5 ( V_7 , V_65 , V_55 -> V_66 ) ;
F_5 ( V_7 , V_47 ,
V_55 -> V_45 | V_49 ) ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_27 * V_67 )
{
unsigned long V_46 ;
F_33 ( V_7 , false ) ;
V_46 = F_6 ( V_7 , V_50 ) ;
if ( V_46 & V_51 ) {
F_18 ( F_10 ( V_7 ) ,
L_5 ) ;
F_34 ( V_7 ) ;
return;
}
F_5 ( V_7 , V_58 , V_67 -> V_55 . V_59 ) ;
F_5 ( V_7 , V_62 , V_67 -> V_55 . V_63 ) ;
if ( V_7 -> V_2 -> V_41 -> V_64 )
F_5 ( V_7 , V_65 ,
V_67 -> V_55 . V_66 ) ;
F_5 ( V_7 , V_47 ,
V_67 -> V_55 . V_45 | V_49 ) ;
V_67 -> V_68 = true ;
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
V_28 -> V_68 = true ;
V_7 -> V_53 = true ;
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_27 * V_69 ;
struct V_27 * V_70 ;
if ( F_21 ( & V_7 -> V_31 ) )
return;
V_69 = F_25 ( & V_7 -> V_31 , F_26 ( * V_69 ) , V_20 ) ;
if ( ! F_41 ( & V_69 -> V_20 , & V_7 -> V_31 ) ) {
V_70 = F_25 ( & V_69 -> V_20 ,
F_26 ( * V_70 ) , V_20 ) ;
F_38 ( V_7 , V_70 ) ;
}
}
static inline int F_42 ( struct V_6 * V_7 ,
struct V_27 * V_28 , unsigned long V_46 )
{
return V_28 -> V_71 - ( V_46 & V_72 ) - 4 ;
}
static void F_43 ( struct V_6 * V_7 )
{
struct V_27 * V_73 ;
struct V_11 * V_17 ;
while ( ! F_21 ( & V_7 -> V_31 ) ) {
V_73 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_73 ) , V_20 ) ;
F_44 ( & V_73 -> V_20 , & V_7 -> V_25 ) ;
if ( V_73 -> V_74 ) {
V_17 = V_73 -> V_17 ;
V_17 -> V_75 = V_76 ;
F_23 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
if ( ! V_17 -> V_77 )
F_23 ( & V_17 -> V_78 ,
& V_7 -> V_79 ) ;
V_17 -> V_77 ++ ;
}
}
V_7 -> V_80 = NULL ;
}
static bool F_45 ( struct V_6 * V_7 ,
struct V_27 * V_81 , bool V_82 )
{
struct V_27 * V_69 = NULL ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_18 ( F_10 ( V_7 ) , L_6 ) ;
F_35 ( V_7 ) ;
return false ;
}
V_69 = F_25 ( & V_7 -> V_31 , F_26 ( * V_69 ) , V_20 ) ;
if ( ! V_69 -> V_68 ) {
F_35 ( V_7 ) ;
F_18 ( F_10 ( V_7 ) , L_7 ) ;
F_43 ( V_7 ) ;
return false ;
}
if ( ! V_82 )
F_40 ( V_7 ) ;
return true ;
}
static void F_46 ( struct V_6 * V_7 ,
bool V_82 )
{
struct V_27 * V_73 ;
struct V_11 * V_17 ;
V_7 -> V_53 = false ;
V_73 = F_25 ( & V_7 -> V_31 , F_26 ( * V_73 ) , V_20 ) ;
V_17 = V_73 -> V_17 ;
V_17 -> V_83 += V_73 -> V_71 ;
F_15 ( & V_73 -> V_20 ) ;
if ( V_73 -> V_74 ) {
V_17 -> V_75 = V_84 ;
F_47 ( & V_17 -> V_14 ) ;
if ( ! V_17 -> V_77 )
F_23 ( & V_17 -> V_78 , & V_7 -> V_79 ) ;
V_17 -> V_77 ++ ;
F_23 ( & V_17 -> V_20 , & V_7 -> V_26 ) ;
}
F_23 ( & V_73 -> V_20 , & V_7 -> V_25 ) ;
if ( V_82 || F_21 ( & V_7 -> V_31 ) )
return;
F_39 ( V_7 ) ;
return;
}
static void F_48 ( struct V_6 * V_7 ,
bool V_82 )
{
struct V_27 * V_73 ;
struct V_11 * V_17 ;
bool V_85 ;
V_73 = F_25 ( & V_7 -> V_31 , F_26 ( * V_73 ) , V_20 ) ;
V_17 = V_73 -> V_17 ;
V_17 -> V_83 += V_73 -> V_71 ;
if ( ! V_17 -> V_77 )
F_23 ( & V_17 -> V_78 , & V_7 -> V_79 ) ;
V_17 -> V_77 ++ ;
if ( ! F_41 ( & V_73 -> V_20 , & V_7 -> V_31 ) ) {
F_44 ( & V_73 -> V_20 , & V_7 -> V_31 ) ;
V_73 -> V_68 = false ;
V_85 = F_45 ( V_7 , V_73 , V_82 ) ;
if ( ! V_85 )
V_17 -> V_75 = V_76 ;
}
return;
}
static void F_49 ( unsigned long V_86 )
{
struct V_6 * V_7 = (struct V_6 * ) V_86 ;
T_2 V_87 = NULL ;
void * V_88 = NULL ;
struct V_11 * V_17 ;
unsigned long V_18 ;
int V_77 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
while ( ! F_21 ( & V_7 -> V_79 ) ) {
V_17 = F_25 ( & V_7 -> V_79 ,
F_26 ( * V_17 ) , V_78 ) ;
F_15 ( & V_17 -> V_78 ) ;
V_87 = V_17 -> V_14 . V_87 ;
V_88 = V_17 -> V_14 . V_88 ;
V_77 = V_17 -> V_77 ;
V_17 -> V_77 = 0 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
while ( V_77 -- && V_87 )
V_87 ( V_88 ) ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static T_3 F_50 ( int V_89 , void * V_90 )
{
struct V_6 * V_7 = V_90 ;
unsigned long V_46 ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
V_46 = F_6 ( V_7 , V_50 ) ;
if ( V_46 & V_51 ) {
F_5 ( V_7 , V_50 , V_46 ) ;
V_7 -> V_80 ( V_7 , false ) ;
F_51 ( & V_7 -> V_91 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_92 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
F_52 ( F_10 ( V_7 ) ,
L_8 , V_46 ) ;
return V_93 ;
}
static T_4 V_23 ( struct V_12 * V_14 )
{
struct V_11 * V_17 = F_9 ( V_14 ) ;
struct V_6 * V_7 = F_7 ( V_14 -> V_94 ) ;
unsigned long V_18 ;
T_4 V_95 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
V_17 -> V_75 = V_96 ;
V_95 = F_53 ( & V_17 -> V_14 ) ;
F_54 ( & V_17 -> V_24 , & V_7 -> V_31 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_95 ;
}
static void F_55 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
unsigned long V_18 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_18 ( F_10 ( V_7 ) , L_9 ) ;
goto V_97;
}
if ( ! V_7 -> V_53 ) {
F_39 ( V_7 ) ;
if ( V_7 -> V_98 ) {
F_30 ( V_39 ) ;
F_40 ( V_7 ) ;
}
}
V_97:
F_16 ( & V_7 -> V_19 , V_18 ) ;
return;
}
static void F_56 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_27 * V_73 ;
struct V_11 * V_17 ;
unsigned long V_18 ;
unsigned long V_46 ;
unsigned long V_66 ;
bool V_99 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
if ( F_21 ( & V_7 -> V_31 ) ) {
F_16 ( & V_7 -> V_19 , V_18 ) ;
return;
}
if ( ! V_7 -> V_53 )
goto V_100;
F_33 ( V_7 , true ) ;
V_46 = F_6 ( V_7 , V_50 ) ;
if ( V_46 & V_51 ) {
F_36 ( F_10 ( V_7 ) , L_10 , V_52 ) ;
V_7 -> V_80 ( V_7 , true ) ;
V_46 = F_6 ( V_7 , V_50 ) ;
}
if ( V_7 -> V_2 -> V_41 -> V_64 )
V_66 = F_6 ( V_7 , V_101 ) ;
else
V_66 = V_46 ;
V_99 = V_7 -> V_53 ;
F_35 ( V_7 ) ;
if ( ! F_21 ( & V_7 -> V_31 ) && V_99 ) {
V_73 = F_25 ( & V_7 -> V_31 ,
F_26 ( * V_73 ) , V_20 ) ;
V_73 -> V_17 -> V_83 +=
F_42 ( V_7 , V_73 , V_66 ) ;
}
F_34 ( V_7 ) ;
V_100:
F_43 ( V_7 ) ;
while ( ! F_21 ( & V_7 -> V_79 ) ) {
V_17 = F_25 ( & V_7 -> V_79 ,
F_26 ( * V_17 ) , V_78 ) ;
F_15 ( & V_17 -> V_78 ) ;
V_17 -> V_77 = 0 ;
}
F_16 ( & V_7 -> V_19 , V_18 ) ;
}
static enum V_75 F_57 ( struct V_9 * V_10 ,
T_4 V_95 , struct V_102 * V_103 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 ;
struct V_27 * V_28 ;
enum V_75 V_104 ;
unsigned long V_18 ;
unsigned int V_105 ;
V_104 = F_58 ( V_10 , V_95 , V_103 ) ;
if ( V_104 == V_84 )
return V_104 ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
F_13 (dma_desc, &tdc->free_dma_desc, node) {
if ( V_17 -> V_14 . V_95 == V_95 ) {
V_105 = V_17 -> V_106 -
( V_17 -> V_83 %
V_17 -> V_106 ) ;
F_59 ( V_103 , V_105 ) ;
V_104 = V_17 -> V_75 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_104 ;
}
}
F_13 (sg_req, &tdc->pending_sg_req, node) {
V_17 = V_28 -> V_17 ;
if ( V_17 -> V_14 . V_95 == V_95 ) {
V_105 = V_17 -> V_106 -
( V_17 -> V_83 %
V_17 -> V_106 ) ;
F_59 ( V_103 , V_105 ) ;
V_104 = V_17 -> V_75 ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_104 ;
}
}
F_36 ( F_10 ( V_7 ) , L_11 , V_95 ) ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
return V_104 ;
}
static int F_60 ( struct V_9 * V_10 , enum V_107 V_108 ,
unsigned long V_109 )
{
switch ( V_108 ) {
case V_110 :
return F_27 ( V_10 ,
(struct V_29 * ) V_109 ) ;
case V_111 :
F_56 ( V_10 ) ;
return 0 ;
default:
break;
}
return - V_112 ;
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
L_12 ) ;
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
unsigned long * V_57 , unsigned long * V_45 , unsigned int * V_123 ,
enum V_113 * V_114 )
{
switch ( V_131 ) {
case V_133 :
* V_132 = V_7 -> V_33 . V_134 ;
* V_57 = F_61 ( V_7 , V_7 -> V_33 . V_135 ) ;
* V_123 = V_7 -> V_33 . V_136 ;
* V_114 = V_7 -> V_33 . V_135 ;
* V_45 = V_137 ;
return 0 ;
case V_138 :
* V_132 = V_7 -> V_33 . V_139 ;
* V_57 = F_61 ( V_7 , V_7 -> V_33 . V_140 ) ;
* V_123 = V_7 -> V_33 . V_141 ;
* V_114 = V_7 -> V_33 . V_140 ;
* V_45 = 0 ;
return 0 ;
default:
F_18 ( F_10 ( V_7 ) , L_13 ) ;
return - V_142 ;
}
return - V_142 ;
}
static void F_65 ( struct V_6 * V_7 ,
struct V_54 * V_55 , T_1 V_124 )
{
T_1 V_143 = ( V_124 - 4 ) & 0xFFFC ;
if ( V_7 -> V_2 -> V_41 -> V_64 )
V_55 -> V_66 = V_143 ;
else
V_55 -> V_45 |= V_143 ;
}
static struct V_12 * F_66 (
struct V_9 * V_10 , struct V_144 * V_145 , unsigned int V_146 ,
enum V_130 V_131 , unsigned long V_18 ,
void * V_147 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 ;
unsigned int V_148 ;
struct V_144 * V_149 ;
unsigned long V_45 , V_61 , V_59 , V_57 ;
struct V_150 V_151 ;
struct V_27 * V_28 = NULL ;
T_1 V_123 ;
enum V_113 V_114 ;
int V_104 ;
if ( ! V_7 -> V_35 ) {
F_18 ( F_10 ( V_7 ) , L_14 ) ;
return NULL ;
}
if ( V_146 < 1 ) {
F_18 ( F_10 ( V_7 ) , L_15 , V_146 ) ;
return NULL ;
}
V_104 = F_64 ( V_7 , V_131 , & V_59 , & V_57 , & V_45 ,
& V_123 , & V_114 ) ;
if ( V_104 < 0 )
return NULL ;
F_67 ( & V_151 ) ;
V_61 = V_152 ;
V_61 |= V_153 <<
V_154 ;
V_61 |= V_155 ;
V_45 |= V_156 | V_157 ;
V_45 |= V_7 -> V_34 << V_158 ;
if ( V_18 & V_159 )
V_45 |= V_48 ;
V_57 |= V_160 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_18 ( F_10 ( V_7 ) , L_16 ) ;
return NULL ;
}
F_67 ( & V_17 -> V_24 ) ;
F_67 ( & V_17 -> V_78 ) ;
V_17 -> V_77 = 0 ;
V_17 -> V_106 = 0 ;
V_17 -> V_83 = 0 ;
V_17 -> V_75 = V_96 ;
F_68 (sgl, sg, sg_len, i) {
T_1 V_124 , V_161 ;
V_161 = F_69 ( V_149 ) ;
V_124 = F_70 ( V_149 ) ;
if ( ( V_124 & 3 ) || ( V_161 & 3 ) ||
( V_124 > V_7 -> V_2 -> V_41 -> V_162 ) ) {
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
V_61 |= F_63 ( V_7 , V_123 , V_114 , V_124 ) ;
V_17 -> V_106 += V_124 ;
V_28 -> V_55 . V_59 = V_59 ;
V_28 -> V_55 . V_63 = V_161 ;
V_28 -> V_55 . V_45 = V_45 ;
F_65 ( V_7 , & V_28 -> V_55 , V_124 ) ;
V_28 -> V_55 . V_57 = V_57 ;
V_28 -> V_55 . V_61 = V_61 ;
V_28 -> V_68 = false ;
V_28 -> V_74 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_71 = V_124 ;
F_23 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
}
V_28 -> V_74 = true ;
if ( V_18 & V_163 )
V_17 -> V_14 . V_18 = V_163 ;
if ( ! V_7 -> V_80 ) {
V_7 -> V_80 = F_46 ;
V_7 -> V_98 = false ;
} else {
if ( V_7 -> V_98 ) {
F_18 ( F_10 ( V_7 ) , L_19 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
}
return & V_17 -> V_14 ;
}
static struct V_12 * F_71 (
struct V_9 * V_10 , T_5 V_164 , T_6 V_165 ,
T_6 V_166 , enum V_130 V_131 ,
unsigned long V_18 , void * V_147 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_11 * V_17 = NULL ;
struct V_27 * V_28 = NULL ;
unsigned long V_45 , V_61 , V_59 , V_57 ;
int V_124 ;
T_6 V_167 ;
T_5 V_161 = V_164 ;
T_1 V_123 ;
enum V_113 V_114 ;
int V_104 ;
if ( ! V_165 || ! V_166 ) {
F_18 ( F_10 ( V_7 ) , L_20 ) ;
return NULL ;
}
if ( ! V_7 -> V_35 ) {
F_18 ( F_10 ( V_7 ) , L_21 ) ;
return NULL ;
}
if ( V_7 -> V_53 ) {
F_18 ( F_10 ( V_7 ) , L_22 ) ;
return NULL ;
}
if ( V_165 % V_166 ) {
F_18 ( F_10 ( V_7 ) , L_23 ) ;
return NULL ;
}
V_124 = V_166 ;
if ( ( V_124 & 3 ) || ( V_164 & 3 ) ||
( V_124 > V_7 -> V_2 -> V_41 -> V_162 ) ) {
F_18 ( F_10 ( V_7 ) , L_24 ) ;
return NULL ;
}
V_104 = F_64 ( V_7 , V_131 , & V_59 , & V_57 , & V_45 ,
& V_123 , & V_114 ) ;
if ( V_104 < 0 )
return NULL ;
V_61 = V_152 ;
V_61 |= V_153 <<
V_154 ;
V_61 |= V_155 ;
V_45 |= V_157 ;
if ( V_18 & V_159 )
V_45 |= V_48 ;
V_45 |= V_7 -> V_34 << V_158 ;
V_57 |= V_160 ;
V_17 = F_11 ( V_7 ) ;
if ( ! V_17 ) {
F_18 ( F_10 ( V_7 ) , L_25 ) ;
return NULL ;
}
F_67 ( & V_17 -> V_24 ) ;
F_67 ( & V_17 -> V_78 ) ;
V_17 -> V_77 = 0 ;
V_17 -> V_83 = 0 ;
V_17 -> V_106 = V_165 ;
V_167 = V_165 ;
while ( V_167 ) {
V_28 = F_24 ( V_7 ) ;
if ( ! V_28 ) {
F_18 ( F_10 ( V_7 ) , L_18 ) ;
F_20 ( V_7 , V_17 ) ;
return NULL ;
}
V_61 |= F_63 ( V_7 , V_123 , V_114 , V_124 ) ;
V_28 -> V_55 . V_59 = V_59 ;
V_28 -> V_55 . V_63 = V_161 ;
V_28 -> V_55 . V_45 = V_45 ;
F_65 ( V_7 , & V_28 -> V_55 , V_124 ) ;
V_28 -> V_55 . V_57 = V_57 ;
V_28 -> V_55 . V_61 = V_61 ;
V_28 -> V_68 = false ;
V_28 -> V_168 = false ;
V_28 -> V_74 = false ;
V_28 -> V_17 = V_17 ;
V_28 -> V_71 = V_124 ;
F_23 ( & V_28 -> V_20 , & V_17 -> V_24 ) ;
V_167 -= V_124 ;
V_161 += V_124 ;
}
V_28 -> V_74 = true ;
if ( V_18 & V_163 )
V_17 -> V_14 . V_18 = V_163 ;
if ( ! V_7 -> V_80 ) {
V_7 -> V_80 = F_48 ;
V_7 -> V_98 = true ;
} else {
if ( ! V_7 -> V_98 ) {
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
int V_104 ;
F_73 ( & V_7 -> V_9 ) ;
V_7 -> V_35 = false ;
V_104 = F_74 ( V_2 -> V_169 ) ;
if ( V_104 < 0 )
F_18 ( F_10 ( V_7 ) , L_27 , V_104 ) ;
return V_104 ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_11 * V_17 ;
struct V_27 * V_28 ;
struct V_150 V_170 ;
struct V_150 V_171 ;
unsigned long V_18 ;
F_67 ( & V_170 ) ;
F_67 ( & V_171 ) ;
F_36 ( F_10 ( V_7 ) , L_28 , V_7 -> V_172 ) ;
if ( V_7 -> V_53 )
F_56 ( V_10 ) ;
F_12 ( & V_7 -> V_19 , V_18 ) ;
F_22 ( & V_7 -> V_31 , & V_171 ) ;
F_22 ( & V_7 -> V_25 , & V_171 ) ;
F_22 ( & V_7 -> V_26 , & V_170 ) ;
F_67 ( & V_7 -> V_79 ) ;
V_7 -> V_35 = false ;
V_7 -> V_80 = NULL ;
F_16 ( & V_7 -> V_19 , V_18 ) ;
while ( ! F_21 ( & V_170 ) ) {
V_17 = F_25 ( & V_170 ,
F_26 ( * V_17 ) , V_20 ) ;
F_15 ( & V_17 -> V_20 ) ;
F_76 ( V_17 ) ;
}
while ( ! F_21 ( & V_171 ) ) {
V_28 = F_25 ( & V_171 , F_26 ( * V_28 ) , V_20 ) ;
F_15 ( & V_28 -> V_20 ) ;
F_76 ( V_28 ) ;
}
F_77 ( V_2 -> V_169 ) ;
V_7 -> V_34 = 0 ;
}
static struct V_9 * F_78 ( struct V_173 * V_174 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = V_176 -> V_177 ;
struct V_9 * V_94 ;
struct V_6 * V_7 ;
V_94 = F_79 ( & V_2 -> V_178 ) ;
if ( ! V_94 )
return NULL ;
V_7 = F_7 ( V_94 ) ;
V_7 -> V_34 = V_174 -> args [ 0 ] ;
return V_94 ;
}
static int F_80 ( struct V_179 * V_180 )
{
struct V_181 * V_182 ;
struct V_1 * V_2 ;
int V_104 ;
int V_148 ;
const struct V_183 * V_184 = NULL ;
const struct V_185 * V_186 ;
V_186 = F_81 ( V_187 , & V_180 -> V_16 ) ;
if ( ! V_186 ) {
F_18 ( & V_180 -> V_16 , L_29 ) ;
return - V_188 ;
}
V_184 = V_186 -> V_86 ;
V_2 = F_82 ( & V_180 -> V_16 , sizeof( * V_2 ) + V_184 -> V_189 *
sizeof( struct V_6 ) , V_190 ) ;
if ( ! V_2 ) {
F_18 ( & V_180 -> V_16 , L_30 ) ;
return - V_191 ;
}
V_2 -> V_16 = & V_180 -> V_16 ;
V_2 -> V_41 = V_184 ;
F_83 ( V_180 , V_2 ) ;
V_182 = F_84 ( V_180 , V_192 , 0 ) ;
V_2 -> V_5 = F_85 ( & V_180 -> V_16 , V_182 ) ;
if ( F_86 ( V_2 -> V_5 ) )
return F_87 ( V_2 -> V_5 ) ;
V_2 -> V_169 = F_88 ( & V_180 -> V_16 , NULL ) ;
if ( F_86 ( V_2 -> V_169 ) ) {
F_18 ( & V_180 -> V_16 , L_31 ) ;
return F_87 ( V_2 -> V_169 ) ;
}
V_2 -> V_193 = F_89 ( & V_180 -> V_16 , L_32 ) ;
if ( F_86 ( V_2 -> V_193 ) ) {
F_18 ( & V_180 -> V_16 , L_33 ) ;
return F_87 ( V_2 -> V_193 ) ;
}
F_90 ( & V_2 -> V_37 ) ;
F_91 ( & V_180 -> V_16 ) ;
if ( ! F_92 ( & V_180 -> V_16 ) ) {
V_104 = F_93 ( & V_180 -> V_16 ) ;
if ( V_104 ) {
F_18 ( & V_180 -> V_16 , L_34 ,
V_104 ) ;
goto V_194;
}
}
V_104 = F_74 ( V_2 -> V_169 ) ;
if ( V_104 < 0 ) {
F_18 ( & V_180 -> V_16 , L_27 , V_104 ) ;
goto V_194;
}
F_94 ( V_2 -> V_193 ) ;
F_30 ( 2 ) ;
F_95 ( V_2 -> V_193 ) ;
F_1 ( V_2 , V_38 , V_40 ) ;
F_1 ( V_2 , V_195 , 0 ) ;
F_1 ( V_2 , V_196 , 0xFFFFFFFFul ) ;
F_77 ( V_2 -> V_169 ) ;
F_67 ( & V_2 -> V_178 . V_197 ) ;
for ( V_148 = 0 ; V_148 < V_184 -> V_189 ; V_148 ++ ) {
struct V_6 * V_7 = & V_2 -> V_197 [ V_148 ] ;
V_7 -> V_8 = V_198 +
V_148 * V_184 -> V_199 ;
V_182 = F_84 ( V_180 , V_200 , V_148 ) ;
if ( ! V_182 ) {
V_104 = - V_142 ;
F_18 ( & V_180 -> V_16 , L_35 , V_148 ) ;
goto V_201;
}
V_7 -> V_89 = V_182 -> V_202 ;
snprintf ( V_7 -> V_203 , sizeof( V_7 -> V_203 ) , L_36 , V_148 ) ;
V_104 = F_96 ( & V_180 -> V_16 , V_7 -> V_89 ,
F_50 , 0 , V_7 -> V_203 , V_7 ) ;
if ( V_104 ) {
F_18 ( & V_180 -> V_16 ,
L_37 ,
V_104 , V_148 ) ;
goto V_201;
}
V_7 -> V_9 . V_15 = & V_2 -> V_178 ;
F_73 ( & V_7 -> V_9 ) ;
F_23 ( & V_7 -> V_9 . V_204 ,
& V_2 -> V_178 . V_197 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_172 = V_148 ;
F_97 ( & V_7 -> V_91 , F_49 ,
( unsigned long ) V_7 ) ;
F_90 ( & V_7 -> V_19 ) ;
F_67 ( & V_7 -> V_31 ) ;
F_67 ( & V_7 -> V_25 ) ;
F_67 ( & V_7 -> V_26 ) ;
F_67 ( & V_7 -> V_79 ) ;
}
F_98 ( V_205 , V_2 -> V_178 . V_206 ) ;
F_98 ( V_207 , V_2 -> V_178 . V_206 ) ;
F_98 ( V_208 , V_2 -> V_178 . V_206 ) ;
V_2 -> V_178 . V_16 = & V_180 -> V_16 ;
V_2 -> V_178 . V_209 =
F_72 ;
V_2 -> V_178 . V_210 =
F_75 ;
V_2 -> V_178 . V_211 = F_66 ;
V_2 -> V_178 . V_212 = F_71 ;
V_2 -> V_178 . V_213 = F_60 ;
V_2 -> V_178 . V_214 = F_57 ;
V_2 -> V_178 . V_215 = F_55 ;
V_104 = F_99 ( & V_2 -> V_178 ) ;
if ( V_104 < 0 ) {
F_18 ( & V_180 -> V_16 ,
L_38 , V_104 ) ;
goto V_201;
}
V_104 = F_100 ( V_180 -> V_16 . V_216 ,
F_78 , V_2 ) ;
if ( V_104 < 0 ) {
F_18 ( & V_180 -> V_16 ,
L_39 , V_104 ) ;
goto V_217;
}
F_52 ( & V_180 -> V_16 , L_40 ,
V_184 -> V_189 ) ;
return 0 ;
V_217:
F_101 ( & V_2 -> V_178 ) ;
V_201:
while ( -- V_148 >= 0 ) {
struct V_6 * V_7 = & V_2 -> V_197 [ V_148 ] ;
F_102 ( & V_7 -> V_91 ) ;
}
V_194:
F_103 ( & V_180 -> V_16 ) ;
if ( ! F_104 ( & V_180 -> V_16 ) )
F_105 ( & V_180 -> V_16 ) ;
return V_104 ;
}
static int F_106 ( struct V_179 * V_180 )
{
struct V_1 * V_2 = F_107 ( V_180 ) ;
int V_148 ;
struct V_6 * V_7 ;
F_101 ( & V_2 -> V_178 ) ;
for ( V_148 = 0 ; V_148 < V_2 -> V_41 -> V_189 ; ++ V_148 ) {
V_7 = & V_2 -> V_197 [ V_148 ] ;
F_102 ( & V_7 -> V_91 ) ;
}
F_103 ( & V_180 -> V_16 ) ;
if ( ! F_104 ( & V_180 -> V_16 ) )
F_105 ( & V_180 -> V_16 ) ;
return 0 ;
}
static int F_105 ( struct V_15 * V_16 )
{
struct V_179 * V_180 = F_108 ( V_16 ) ;
struct V_1 * V_2 = F_107 ( V_180 ) ;
F_77 ( V_2 -> V_169 ) ;
return 0 ;
}
static int F_93 ( struct V_15 * V_16 )
{
struct V_179 * V_180 = F_108 ( V_16 ) ;
struct V_1 * V_2 = F_107 ( V_180 ) ;
int V_104 ;
V_104 = F_74 ( V_2 -> V_169 ) ;
if ( V_104 < 0 ) {
F_18 ( V_16 , L_41 , V_104 ) ;
return V_104 ;
}
return 0 ;
}
static int F_109 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_110 ( V_16 ) ;
int V_148 ;
int V_104 ;
V_104 = F_93 ( V_16 ) ;
if ( V_104 < 0 )
return V_104 ;
V_2 -> V_218 = F_3 ( V_2 , V_38 ) ;
for ( V_148 = 0 ; V_148 < V_2 -> V_41 -> V_189 ; V_148 ++ ) {
struct V_6 * V_7 = & V_2 -> V_197 [ V_148 ] ;
struct V_54 * V_219 = & V_7 -> V_220 ;
V_219 -> V_45 = F_6 ( V_7 , V_47 ) ;
V_219 -> V_63 = F_6 ( V_7 , V_62 ) ;
V_219 -> V_59 = F_6 ( V_7 , V_58 ) ;
V_219 -> V_61 = F_6 ( V_7 , V_60 ) ;
V_219 -> V_57 = F_6 ( V_7 , V_56 ) ;
}
F_105 ( V_16 ) ;
return 0 ;
}
static int F_111 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_110 ( V_16 ) ;
int V_148 ;
int V_104 ;
V_104 = F_93 ( V_16 ) ;
if ( V_104 < 0 )
return V_104 ;
F_1 ( V_2 , V_38 , V_2 -> V_218 ) ;
F_1 ( V_2 , V_195 , 0 ) ;
F_1 ( V_2 , V_196 , 0xFFFFFFFFul ) ;
for ( V_148 = 0 ; V_148 < V_2 -> V_41 -> V_189 ; V_148 ++ ) {
struct V_6 * V_7 = & V_2 -> V_197 [ V_148 ] ;
struct V_54 * V_219 = & V_7 -> V_220 ;
F_5 ( V_7 , V_56 , V_219 -> V_57 ) ;
F_5 ( V_7 , V_58 , V_219 -> V_59 ) ;
F_5 ( V_7 , V_60 , V_219 -> V_61 ) ;
F_5 ( V_7 , V_62 , V_219 -> V_63 ) ;
F_5 ( V_7 , V_47 ,
( V_219 -> V_45 & ~ V_49 ) ) ;
}
F_105 ( V_16 ) ;
return 0 ;
}
