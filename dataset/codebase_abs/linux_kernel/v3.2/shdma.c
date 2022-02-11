static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 / sizeof( T_1 ) ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 / sizeof( T_1 ) ) ;
}
static T_2 F_5 ( struct V_6 * V_7 )
{
T_1 T_3 * V_8 = V_7 -> V_9 + V_10 / sizeof( T_1 ) ;
if ( V_7 -> V_11 -> V_12 )
return F_4 ( V_8 ) ;
else
return F_6 ( V_8 ) ;
}
static void F_7 ( struct V_6 * V_7 , T_2 V_3 )
{
T_1 T_3 * V_8 = V_7 -> V_9 + V_10 / sizeof( T_1 ) ;
if ( V_7 -> V_11 -> V_12 )
F_2 ( V_3 , V_8 ) ;
else
F_8 ( V_3 , V_8 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_6 * V_7 = F_10 ( V_2 ) ;
F_2 ( V_3 , V_2 -> V_5 + V_7 -> V_13 / sizeof( T_1 ) ) ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_10 ( V_2 ) ;
return F_4 ( V_2 -> V_5 + V_7 -> V_13 / sizeof( T_1 ) ) ;
}
static void F_12 ( struct V_6 * V_7 )
{
unsigned short V_14 ;
unsigned long V_15 ;
F_13 ( & V_16 , V_15 ) ;
V_14 = F_5 ( V_7 ) ;
F_7 ( V_7 , V_14 & ~ ( V_17 | V_18 | V_19 ) ) ;
F_14 ( & V_16 , V_15 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
unsigned short V_14 ;
unsigned long V_15 ;
F_13 ( & V_16 , V_15 ) ;
V_14 = F_5 ( V_7 ) & ~ ( V_17 | V_18 | V_19 ) ;
F_7 ( V_7 , V_14 | V_7 -> V_11 -> V_20 ) ;
V_14 = F_5 ( V_7 ) ;
F_14 ( & V_16 , V_15 ) ;
if ( V_14 & ( V_18 | V_17 ) ) {
F_16 ( V_7 -> V_21 . V_22 , L_1 ) ;
return - V_23 ;
}
return 0 ;
}
static bool F_17 ( struct V_1 * V_24 )
{
T_1 V_25 = F_11 ( V_24 ) ;
if ( ( V_25 & ( V_26 | V_27 ) ) == V_26 )
return true ;
return false ;
}
static unsigned int F_18 ( struct V_1 * V_24 , T_1 V_25 )
{
struct V_6 * V_7 = F_10 ( V_24 ) ;
struct V_28 * V_11 = V_7 -> V_11 ;
int V_29 = ( ( V_25 & V_11 -> V_30 ) >> V_11 -> V_31 ) |
( ( V_25 & V_11 -> V_32 ) >> V_11 -> V_33 ) ;
if ( V_29 >= V_11 -> V_34 )
V_29 = 0 ;
return V_11 -> V_35 [ V_29 ] ;
}
static T_1 F_19 ( struct V_1 * V_24 , int V_36 )
{
struct V_6 * V_7 = F_10 ( V_24 ) ;
struct V_28 * V_11 = V_7 -> V_11 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_11 -> V_34 ; V_37 ++ )
if ( V_11 -> V_35 [ V_37 ] == V_36 )
break;
if ( V_37 == V_11 -> V_34 )
V_37 = 0 ;
return ( ( V_37 << V_11 -> V_31 ) & V_11 -> V_30 ) |
( ( V_37 << V_11 -> V_33 ) & V_11 -> V_32 ) ;
}
static void F_20 ( struct V_1 * V_24 , struct V_38 * V_39 )
{
F_1 ( V_24 , V_39 -> V_40 , V_41 ) ;
F_1 ( V_24 , V_39 -> V_42 , V_43 ) ;
F_1 ( V_24 , V_39 -> V_44 >> V_24 -> V_45 , V_46 ) ;
}
static void F_21 ( struct V_1 * V_24 )
{
struct V_6 * V_7 = F_10 ( V_24 ) ;
T_1 V_25 = F_11 ( V_24 ) ;
if ( V_7 -> V_11 -> V_47 )
F_1 ( V_24 , 0xFFFFFFFF , V_48 ) ;
V_25 |= V_26 | V_7 -> V_49 ;
F_9 ( V_24 , V_25 & ~ V_27 ) ;
}
static void F_22 ( struct V_1 * V_24 )
{
struct V_6 * V_7 = F_10 ( V_24 ) ;
T_1 V_25 = F_11 ( V_24 ) ;
V_25 &= ~ ( V_26 | V_27 | V_7 -> V_49 ) ;
F_9 ( V_24 , V_25 ) ;
}
static void F_23 ( struct V_1 * V_24 )
{
T_1 V_25 = V_50 | V_51 | 0x400 | F_19 ( V_24 ,
V_52 ) ;
V_24 -> V_45 = F_18 ( V_24 , V_25 ) ;
F_9 ( V_24 , V_25 ) ;
}
static int F_24 ( struct V_1 * V_24 , T_1 V_53 )
{
if ( F_17 ( V_24 ) )
return - V_54 ;
V_24 -> V_45 = F_18 ( V_24 , V_53 ) ;
F_9 ( V_24 , V_53 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_24 , T_2 V_53 )
{
struct V_6 * V_7 = F_10 ( V_24 ) ;
struct V_28 * V_11 = V_7 -> V_11 ;
const struct V_55 * V_56 = & V_11 -> V_57 [ V_24 -> V_58 ] ;
T_2 T_3 * V_8 = V_7 -> V_59 ;
unsigned int V_60 = V_56 -> V_61 ;
if ( F_17 ( V_24 ) )
return - V_54 ;
if ( V_11 -> V_62 )
return 0 ;
if ( ! V_8 )
V_8 = ( T_2 T_3 * ) V_7 -> V_9 ;
V_8 += V_56 -> V_59 / sizeof( T_2 ) ;
F_8 ( ( F_6 ( V_8 ) & ( 0xff00 >> V_60 ) ) | ( V_53 << V_60 ) ,
V_8 ) ;
return 0 ;
}
static T_4 F_26 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_27 ( V_64 ) , * V_67 , * V_68 = V_66 , * V_69 ;
struct V_1 * V_24 = F_28 ( V_64 -> V_70 ) ;
struct V_71 * V_72 = V_64 -> V_70 -> V_73 ;
T_5 V_74 = V_64 -> V_74 ;
T_4 V_75 ;
bool V_76 ;
F_29 ( & V_24 -> V_77 ) ;
if ( F_30 ( & V_24 -> V_78 ) )
V_76 = true ;
else
V_76 = false ;
V_75 = V_24 -> V_21 . V_75 ;
V_75 ++ ;
if ( V_75 < 0 )
V_75 = 1 ;
V_24 -> V_21 . V_75 = V_75 ;
V_64 -> V_75 = V_75 ;
F_31 (chunk, c, desc->node.prev, node) {
if ( V_67 != V_66 && ( V_67 -> V_79 == V_80 ||
V_67 -> V_81 . V_75 > 0 ||
V_67 -> V_81 . V_75 == - V_54 ||
& V_67 -> V_82 == & V_24 -> V_83 ) )
break;
V_67 -> V_79 = V_84 ;
V_67 -> V_81 . V_74 = NULL ;
V_67 -> V_75 = V_75 ;
F_32 ( & V_67 -> V_82 , & V_24 -> V_78 ) ;
V_68 = V_67 ;
}
V_68 -> V_81 . V_74 = V_74 ;
V_68 -> V_81 . V_85 = V_64 -> V_85 ;
F_33 ( V_24 -> V_22 , L_2 ,
V_64 -> V_75 , & V_68 -> V_81 , V_24 -> V_58 ,
V_66 -> V_39 . V_40 , V_66 -> V_39 . V_44 , V_66 -> V_39 . V_42 ) ;
if ( V_76 ) {
V_24 -> V_86 = V_87 ;
F_34 ( V_24 -> V_22 ) ;
F_35 ( & V_24 -> V_77 ) ;
F_36 ( V_24 -> V_22 ) ;
F_29 ( & V_24 -> V_77 ) ;
if ( V_24 -> V_86 != V_88 ) {
F_33 ( V_24 -> V_22 , L_3 ,
V_24 -> V_58 ) ;
if ( V_72 ) {
const struct V_89 * V_90 =
V_72 -> V_91 ;
F_25 ( V_24 , V_90 -> V_92 ) ;
F_24 ( V_24 , V_90 -> V_25 ) ;
} else {
F_23 ( V_24 ) ;
}
if ( V_24 -> V_86 == V_93 )
F_37 ( V_24 ) ;
V_24 -> V_86 = V_88 ;
}
}
F_35 ( & V_24 -> V_77 ) ;
return V_75 ;
}
static struct V_65 * F_38 ( struct V_1 * V_24 )
{
struct V_65 * V_66 ;
F_39 (desc, &sh_chan->ld_free, node)
if ( V_66 -> V_79 != V_94 ) {
F_40 ( V_66 -> V_79 != V_80 ) ;
F_41 ( & V_66 -> V_82 ) ;
return V_66 ;
}
return NULL ;
}
static const struct V_89 * F_42 (
struct V_1 * V_24 , struct V_71 * V_72 )
{
struct V_6 * V_7 = F_10 ( V_24 ) ;
struct V_28 * V_11 = V_7 -> V_11 ;
int V_37 ;
if ( V_72 -> V_95 >= V_96 )
return NULL ;
for ( V_37 = 0 ; V_37 < V_11 -> V_97 ; V_37 ++ )
if ( V_11 -> V_98 [ V_37 ] . V_95 == V_72 -> V_95 )
return V_11 -> V_98 + V_37 ;
return NULL ;
}
static int F_43 ( struct V_99 * V_70 )
{
struct V_1 * V_24 = F_28 ( V_70 ) ;
struct V_65 * V_66 ;
struct V_71 * V_72 = V_70 -> V_73 ;
int V_100 ;
if ( V_72 ) {
const struct V_89 * V_90 ;
V_90 = F_42 ( V_24 , V_72 ) ;
if ( ! V_90 ) {
V_100 = - V_101 ;
goto V_102;
}
if ( F_44 ( V_72 -> V_95 , V_103 ) ) {
V_100 = - V_54 ;
goto V_104;
}
V_72 -> V_91 = V_90 ;
}
while ( V_24 -> V_105 < V_106 ) {
V_66 = F_45 ( sizeof( struct V_65 ) , V_107 ) ;
if ( ! V_66 )
break;
F_46 ( & V_66 -> V_81 ,
& V_24 -> V_21 ) ;
V_66 -> V_81 . V_108 = F_26 ;
V_66 -> V_79 = V_80 ;
F_47 ( & V_66 -> V_82 , & V_24 -> V_83 ) ;
V_24 -> V_105 ++ ;
}
if ( ! V_24 -> V_105 ) {
V_100 = - V_109 ;
goto V_110;
}
return V_24 -> V_105 ;
V_110:
if ( V_72 )
F_48 ( V_72 -> V_95 , V_103 ) ;
V_104:
V_102:
V_70 -> V_73 = NULL ;
return V_100 ;
}
static void F_49 ( struct V_99 * V_70 )
{
struct V_1 * V_24 = F_28 ( V_70 ) ;
struct V_65 * V_66 , * V_111 ;
F_50 ( V_112 ) ;
F_29 ( & V_24 -> V_77 ) ;
F_22 ( V_24 ) ;
F_35 ( & V_24 -> V_77 ) ;
if ( ! F_30 ( & V_24 -> V_78 ) )
F_51 ( V_24 , true ) ;
if ( V_70 -> V_73 ) {
struct V_71 * V_72 = V_70 -> V_73 ;
F_48 ( V_72 -> V_95 , V_103 ) ;
V_70 -> V_73 = NULL ;
}
F_29 ( & V_24 -> V_77 ) ;
F_52 ( & V_24 -> V_83 , & V_112 ) ;
V_24 -> V_105 = 0 ;
F_35 ( & V_24 -> V_77 ) ;
F_31 (desc, _desc, &list, node)
F_53 ( V_66 ) ;
}
static struct V_65 * F_54 ( struct V_1 * V_24 ,
unsigned long V_15 , T_6 * V_113 , T_6 * V_114 , T_7 * V_115 ,
struct V_65 * * V_116 , enum V_117 V_118 )
{
struct V_65 * V_119 ;
T_7 V_120 ;
if ( ! * V_115 )
return NULL ;
V_119 = F_38 ( V_24 ) ;
if ( ! V_119 ) {
F_55 ( V_24 -> V_22 , L_4 ) ;
return NULL ;
}
V_120 = F_56 ( * V_115 , ( T_7 ) V_121 + 1 ) ;
V_119 -> V_39 . V_40 = * V_114 ;
V_119 -> V_39 . V_42 = * V_113 ;
V_119 -> V_39 . V_44 = V_120 ;
if ( ! * V_116 ) {
V_119 -> V_81 . V_75 = - V_54 ;
* V_116 = V_119 ;
} else {
V_119 -> V_81 . V_75 = - V_101 ;
}
F_33 ( V_24 -> V_22 ,
L_5 ,
V_120 , * V_115 , * V_114 , * V_113 , & V_119 -> V_81 ,
V_119 -> V_81 . V_75 , V_24 -> V_45 ) ;
V_119 -> V_79 = V_94 ;
V_119 -> V_81 . V_15 = V_15 ;
V_119 -> V_118 = V_118 ;
* V_115 -= V_120 ;
if ( V_118 == V_122 || V_118 == V_123 )
* V_114 += V_120 ;
if ( V_118 == V_122 || V_118 == V_124 )
* V_113 += V_120 ;
return V_119 ;
}
static struct V_63 * F_57 ( struct V_1 * V_24 ,
struct V_125 * V_126 , unsigned int V_127 , T_6 * V_8 ,
enum V_117 V_118 , unsigned long V_15 )
{
struct V_125 * V_128 ;
struct V_65 * V_116 = NULL , * V_119 = NULL ;
F_50 ( V_129 ) ;
int V_130 = 0 ;
unsigned long V_131 ;
int V_37 ;
if ( ! V_127 )
return NULL ;
F_58 (sgl, sg, sg_len, i)
V_130 += ( F_59 ( V_128 ) + V_121 ) /
( V_121 + 1 ) ;
F_13 ( & V_24 -> V_77 , V_131 ) ;
F_58 (sgl, sg, sg_len, i) {
T_6 V_132 = F_60 ( V_128 ) ;
T_7 V_115 = F_59 ( V_128 ) ;
if ( ! V_115 )
goto V_133;
do {
F_33 ( V_24 -> V_22 , L_6 ,
V_37 , V_128 , V_115 , ( unsigned long long ) V_132 ) ;
if ( V_118 == V_124 )
V_119 = F_54 ( V_24 , V_15 ,
& V_132 , V_8 , & V_115 , & V_116 ,
V_118 ) ;
else
V_119 = F_54 ( V_24 , V_15 ,
V_8 , & V_132 , & V_115 , & V_116 ,
V_118 ) ;
if ( ! V_119 )
goto V_133;
V_119 -> V_130 = V_130 -- ;
F_61 ( & V_119 -> V_82 , & V_129 ) ;
} while ( V_115 );
}
if ( V_119 != V_116 )
V_119 -> V_81 . V_75 = - V_134 ;
F_62 ( & V_129 , & V_24 -> V_83 ) ;
F_14 ( & V_24 -> V_77 , V_131 ) ;
return & V_116 -> V_81 ;
V_133:
F_39 (new, &tx_list, node)
V_119 -> V_79 = V_80 ;
F_63 ( & V_129 , & V_24 -> V_83 ) ;
F_14 ( & V_24 -> V_77 , V_131 ) ;
return NULL ;
}
static struct V_63 * F_64 (
struct V_99 * V_70 , T_6 V_135 , T_6 V_136 ,
T_7 V_115 , unsigned long V_15 )
{
struct V_1 * V_24 ;
struct V_125 V_128 ;
if ( ! V_70 || ! V_115 )
return NULL ;
V_24 = F_28 ( V_70 ) ;
F_65 ( & V_128 , 1 ) ;
F_66 ( & V_128 , F_67 ( F_68 ( V_136 ) ) , V_115 ,
F_69 ( V_136 ) ) ;
F_60 ( & V_128 ) = V_136 ;
F_59 ( & V_128 ) = V_115 ;
return F_57 ( V_24 , & V_128 , 1 , & V_135 , V_122 ,
V_15 ) ;
}
static struct V_63 * F_70 (
struct V_99 * V_70 , struct V_125 * V_126 , unsigned int V_127 ,
enum V_117 V_118 , unsigned long V_15 )
{
struct V_71 * V_72 ;
struct V_1 * V_24 ;
T_6 V_137 ;
if ( ! V_70 )
return NULL ;
V_24 = F_28 ( V_70 ) ;
V_72 = V_70 -> V_73 ;
if ( ! V_72 || ! V_127 ) {
F_16 ( V_24 -> V_22 , L_7 ,
V_138 , V_72 , V_127 , V_72 ? V_72 -> V_95 : - 1 ) ;
return NULL ;
}
V_137 = V_72 -> V_91 -> V_8 ;
return F_57 ( V_24 , V_126 , V_127 , & V_137 ,
V_118 , V_15 ) ;
}
static int F_71 ( struct V_99 * V_70 , enum V_139 V_140 ,
unsigned long V_141 )
{
struct V_1 * V_24 = F_28 ( V_70 ) ;
unsigned long V_15 ;
if ( V_140 != V_142 )
return - V_143 ;
if ( ! V_70 )
return - V_101 ;
F_13 ( & V_24 -> V_77 , V_15 ) ;
F_22 ( V_24 ) ;
if ( ! F_30 ( & V_24 -> V_78 ) ) {
struct V_65 * V_66 = F_72 ( V_24 -> V_78 . V_144 ,
struct V_65 , V_82 ) ;
V_66 -> V_145 = ( V_66 -> V_39 . V_44 - F_3 ( V_24 , V_46 ) ) <<
V_24 -> V_45 ;
}
F_14 ( & V_24 -> V_77 , V_15 ) ;
F_51 ( V_24 , true ) ;
return 0 ;
}
static T_5 F_73 ( struct V_1 * V_24 , bool V_146 )
{
struct V_65 * V_66 , * V_111 ;
bool V_147 = false ;
T_4 V_75 = 0 ;
T_5 V_74 = NULL ;
void * V_72 = NULL ;
unsigned long V_15 ;
F_13 ( & V_24 -> V_77 , V_15 ) ;
F_31 (desc, _desc, &sh_chan->ld_queue, node) {
struct V_63 * V_64 = & V_66 -> V_81 ;
F_40 ( V_64 -> V_75 > 0 && V_64 -> V_75 != V_66 -> V_75 ) ;
F_40 ( V_66 -> V_79 != V_84 &&
V_66 -> V_79 != V_148 &&
V_66 -> V_79 != V_149 ) ;
if ( ! V_146 && V_66 -> V_79 == V_84 &&
V_66 -> V_75 != V_75 )
break;
if ( V_64 -> V_75 > 0 )
V_75 = V_64 -> V_75 ;
if ( V_66 -> V_79 == V_148 && V_66 -> V_130 == 1 ) {
if ( V_24 -> V_150 != V_66 -> V_75 - 1 )
F_33 ( V_24 -> V_22 ,
L_8 ,
V_66 -> V_75 ,
V_24 -> V_150 + 1 ) ;
V_24 -> V_150 = V_66 -> V_75 ;
}
if ( V_66 -> V_79 == V_148 && V_64 -> V_74 ) {
V_66 -> V_79 = V_149 ;
V_74 = V_64 -> V_74 ;
V_72 = V_64 -> V_85 ;
F_33 ( V_24 -> V_22 , L_9 ,
V_64 -> V_75 , V_64 , V_24 -> V_58 ) ;
F_40 ( V_66 -> V_130 != 1 ) ;
break;
}
if ( V_64 -> V_75 > 0 || V_64 -> V_75 == - V_54 ) {
if ( V_66 -> V_79 == V_148 ) {
F_40 ( V_64 -> V_75 < 0 ) ;
V_66 -> V_79 = V_149 ;
}
V_147 = F_74 ( V_64 ) ;
} else {
switch ( V_66 -> V_79 ) {
case V_148 :
V_66 -> V_79 = V_149 ;
case V_149 :
if ( V_147 )
F_75 ( & V_66 -> V_81 ) ;
}
}
F_33 ( V_24 -> V_22 , L_10 ,
V_64 , V_64 -> V_75 ) ;
if ( ( ( V_66 -> V_79 == V_148 ||
V_66 -> V_79 == V_149 ) &&
F_74 ( & V_66 -> V_81 ) ) || V_146 ) {
V_66 -> V_79 = V_80 ;
F_76 ( & V_66 -> V_82 , & V_24 -> V_83 ) ;
if ( F_30 ( & V_24 -> V_78 ) ) {
F_33 ( V_24 -> V_22 , L_11 , V_24 -> V_58 ) ;
F_77 ( V_24 -> V_22 ) ;
}
}
}
if ( V_146 && ! V_74 )
V_24 -> V_150 = V_24 -> V_21 . V_75 ;
F_14 ( & V_24 -> V_77 , V_15 ) ;
if ( V_74 )
V_74 ( V_72 ) ;
return V_74 ;
}
static void F_51 ( struct V_1 * V_24 , bool V_146 )
{
while ( F_73 ( V_24 , V_146 ) )
;
}
static void F_37 ( struct V_1 * V_24 )
{
struct V_65 * V_66 ;
if ( F_17 ( V_24 ) )
return;
F_39 (desc, &sh_chan->ld_queue, node)
if ( V_66 -> V_79 == V_84 ) {
F_33 ( V_24 -> V_22 , L_12 ,
V_66 -> V_81 . V_75 , V_24 -> V_58 ,
V_66 -> V_39 . V_44 , V_66 -> V_39 . V_40 , V_66 -> V_39 . V_42 ) ;
F_20 ( V_24 , & V_66 -> V_39 ) ;
F_21 ( V_24 ) ;
break;
}
}
static void F_78 ( struct V_99 * V_70 )
{
struct V_1 * V_24 = F_28 ( V_70 ) ;
F_29 ( & V_24 -> V_77 ) ;
if ( V_24 -> V_86 == V_88 )
F_37 ( V_24 ) ;
else
V_24 -> V_86 = V_93 ;
F_35 ( & V_24 -> V_77 ) ;
}
static enum V_151 F_79 ( struct V_99 * V_70 ,
T_4 V_75 ,
struct V_152 * V_153 )
{
struct V_1 * V_24 = F_28 ( V_70 ) ;
T_4 V_154 ;
T_4 V_155 ;
enum V_151 V_156 ;
unsigned long V_15 ;
F_51 ( V_24 , false ) ;
V_155 = V_24 -> V_150 ;
F_80 () ;
V_154 = V_70 -> V_75 ;
F_40 ( V_155 < 0 ) ;
F_81 ( V_153 , V_155 , V_154 , 0 ) ;
F_13 ( & V_24 -> V_77 , V_15 ) ;
V_156 = F_82 ( V_75 , V_155 , V_154 ) ;
if ( V_156 != V_157 ) {
struct V_65 * V_66 ;
V_156 = V_158 ;
F_39 (desc, &sh_chan->ld_queue, node)
if ( V_66 -> V_75 == V_75 ) {
V_156 = V_159 ;
break;
}
}
F_14 ( & V_24 -> V_77 , V_15 ) ;
return V_156 ;
}
static T_8 F_83 ( int V_160 , void * V_3 )
{
T_8 V_100 = V_161 ;
struct V_1 * V_24 = V_3 ;
T_1 V_25 ;
F_84 ( & V_24 -> V_77 ) ;
V_25 = F_11 ( V_24 ) ;
if ( V_25 & V_27 ) {
F_22 ( V_24 ) ;
V_100 = V_162 ;
F_85 ( & V_24 -> V_163 ) ;
}
F_86 ( & V_24 -> V_77 ) ;
return V_100 ;
}
static bool F_87 ( struct V_6 * V_7 )
{
unsigned int V_164 = 0 ;
int V_37 ;
F_12 ( V_7 ) ;
for ( V_37 = 0 ; V_37 < V_165 ; V_37 ++ ) {
struct V_1 * V_24 = V_7 -> V_70 [ V_37 ] ;
struct V_65 * V_66 ;
F_50 ( V_166 ) ;
if ( ! V_24 )
continue;
F_84 ( & V_24 -> V_77 ) ;
F_22 ( V_24 ) ;
F_52 ( & V_24 -> V_78 , & V_166 ) ;
if ( ! F_30 ( & V_166 ) ) {
F_33 ( V_24 -> V_22 , L_11 , V_24 -> V_58 ) ;
F_77 ( V_24 -> V_22 ) ;
}
V_24 -> V_86 = V_88 ;
F_86 ( & V_24 -> V_77 ) ;
F_39 (desc, &dl, node) {
struct V_63 * V_64 = & V_66 -> V_81 ;
V_66 -> V_79 = V_80 ;
if ( V_64 -> V_74 )
V_64 -> V_74 ( V_64 -> V_85 ) ;
}
F_84 ( & V_24 -> V_77 ) ;
F_63 ( & V_166 , & V_24 -> V_83 ) ;
F_86 ( & V_24 -> V_77 ) ;
V_164 ++ ;
}
F_15 ( V_7 ) ;
return ! ! V_164 ;
}
static T_8 F_88 ( int V_160 , void * V_3 )
{
struct V_6 * V_7 = V_3 ;
if ( ! ( F_5 ( V_7 ) & V_18 ) )
return V_161 ;
F_87 ( V_3 ) ;
return V_162 ;
}
static void F_89 ( unsigned long V_3 )
{
struct V_1 * V_24 = (struct V_1 * ) V_3 ;
struct V_65 * V_66 ;
T_1 V_167 = F_3 ( V_24 , V_41 ) ;
T_1 V_168 = F_3 ( V_24 , V_43 ) ;
F_29 ( & V_24 -> V_77 ) ;
F_39 (desc, &sh_chan->ld_queue, node) {
if ( V_66 -> V_79 == V_84 &&
( ( V_66 -> V_118 == V_124 &&
( V_66 -> V_39 . V_42 + V_66 -> V_39 . V_44 ) == V_168 ) ||
( V_66 -> V_39 . V_40 + V_66 -> V_39 . V_44 ) == V_167 ) ) {
F_33 ( V_24 -> V_22 , L_13 ,
V_66 -> V_81 . V_75 , & V_66 -> V_81 ,
V_66 -> V_39 . V_42 ) ;
V_66 -> V_79 = V_148 ;
break;
}
}
F_37 ( V_24 ) ;
F_35 ( & V_24 -> V_77 ) ;
F_51 ( V_24 , false ) ;
}
static bool F_90 ( struct V_6 * V_7 )
{
if ( ( F_5 ( V_7 ) & V_17 ) == 0 )
return false ;
return F_87 ( V_7 ) ;
}
static int F_91 ( struct V_169 * V_170 ,
unsigned long V_140 , void * V_3 )
{
struct V_6 * V_7 ;
int V_100 = V_171 ;
bool V_172 ;
if ( ! F_92 () )
return V_171 ;
F_93 () ;
F_94 (shdev, &sh_dmae_devices, node) {
V_172 = F_90 ( V_7 ) ;
if ( V_172 == true )
V_100 = V_173 ;
}
F_95 () ;
return V_100 ;
}
static int T_9 F_96 ( struct V_6 * V_7 , int V_58 ,
int V_160 , unsigned long V_15 )
{
int V_174 ;
const struct V_55 * V_56 = & V_7 -> V_11 -> V_57 [ V_58 ] ;
struct V_175 * V_176 = F_97 ( V_7 -> V_21 . V_22 ) ;
struct V_1 * V_177 ;
V_177 = F_45 ( sizeof( struct V_1 ) , V_107 ) ;
if ( ! V_177 ) {
F_55 ( V_7 -> V_21 . V_22 ,
L_14 ) ;
return - V_109 ;
}
V_177 -> V_86 = V_88 ;
V_177 -> V_21 . V_178 = & V_7 -> V_21 ;
V_177 -> V_22 = V_7 -> V_21 . V_22 ;
V_177 -> V_58 = V_58 ;
V_177 -> V_160 = V_160 ;
V_177 -> V_5 = V_7 -> V_9 + V_56 -> V_179 / sizeof( T_1 ) ;
F_98 ( & V_177 -> V_163 , F_89 ,
( unsigned long ) V_177 ) ;
F_99 ( & V_177 -> V_77 ) ;
F_100 ( & V_177 -> V_78 ) ;
F_100 ( & V_177 -> V_83 ) ;
F_61 ( & V_177 -> V_21 . V_180 ,
& V_7 -> V_21 . V_181 ) ;
V_7 -> V_21 . V_182 ++ ;
if ( V_176 -> V_58 >= 0 )
snprintf ( V_177 -> V_183 , sizeof( V_177 -> V_183 ) ,
L_15 , V_176 -> V_58 , V_177 -> V_58 ) ;
else
snprintf ( V_177 -> V_183 , sizeof( V_177 -> V_183 ) ,
L_16 , V_177 -> V_58 ) ;
V_174 = F_101 ( V_160 , & F_83 , V_15 ,
V_177 -> V_183 , V_177 ) ;
if ( V_174 ) {
F_55 ( V_7 -> V_21 . V_22 , L_17
L_18 , V_58 , V_174 ) ;
goto V_184;
}
V_7 -> V_70 [ V_58 ] = V_177 ;
return 0 ;
V_184:
F_41 ( & V_177 -> V_21 . V_180 ) ;
F_53 ( V_177 ) ;
return V_174 ;
}
static void F_102 ( struct V_6 * V_7 )
{
int V_37 ;
for ( V_37 = V_7 -> V_21 . V_182 - 1 ; V_37 >= 0 ; V_37 -- ) {
if ( V_7 -> V_70 [ V_37 ] ) {
struct V_1 * V_24 = V_7 -> V_70 [ V_37 ] ;
F_103 ( V_24 -> V_160 , V_24 ) ;
F_41 ( & V_24 -> V_21 . V_180 ) ;
F_53 ( V_24 ) ;
V_7 -> V_70 [ V_37 ] = NULL ;
}
}
V_7 -> V_21 . V_182 = 0 ;
}
static int T_10 F_104 ( struct V_175 * V_176 )
{
struct V_28 * V_11 = V_176 -> V_22 . V_185 ;
unsigned long V_186 = V_187 ,
V_188 [ V_165 ] = {} ;
int V_189 , V_190 [ V_165 ] ;
int V_174 , V_37 , V_191 = 0 , V_192 = 0 , V_193 = 0 ;
struct V_6 * V_7 ;
struct V_194 * V_70 , * V_59 , * V_195 , * V_196 ;
if ( ! V_11 || ! V_11 -> V_197 )
return - V_198 ;
V_70 = F_105 ( V_176 , V_199 , 0 ) ;
V_59 = F_105 ( V_176 , V_199 , 1 ) ;
V_195 = F_105 ( V_176 , V_200 , 0 ) ;
if ( ! V_70 || ! V_195 )
return - V_198 ;
if ( ! F_106 ( V_70 -> V_201 , F_107 ( V_70 ) , V_176 -> V_202 ) ) {
F_55 ( & V_176 -> V_22 , L_19 ) ;
return - V_54 ;
}
if ( V_59 && ! F_106 ( V_59 -> V_201 , F_107 ( V_59 ) , V_176 -> V_202 ) ) {
F_55 ( & V_176 -> V_22 , L_20 ) ;
V_174 = - V_54 ;
goto V_203;
}
V_174 = - V_109 ;
V_7 = F_45 ( sizeof( struct V_6 ) , V_107 ) ;
if ( ! V_7 ) {
F_55 ( & V_176 -> V_22 , L_21 ) ;
goto V_204;
}
V_7 -> V_9 = F_108 ( V_70 -> V_201 , F_107 ( V_70 ) ) ;
if ( ! V_7 -> V_9 )
goto V_205;
if ( V_59 ) {
V_7 -> V_59 = F_108 ( V_59 -> V_201 , F_107 ( V_59 ) ) ;
if ( ! V_7 -> V_59 )
goto V_206;
}
V_7 -> V_11 = V_11 ;
if ( V_11 -> V_13 )
V_7 -> V_13 = V_11 -> V_13 ;
else
V_7 -> V_13 = V_207 ;
if ( V_11 -> V_49 )
V_7 -> V_49 = V_11 -> V_49 ;
else
V_7 -> V_49 = V_208 ;
F_109 ( V_176 , V_7 ) ;
F_110 ( & V_176 -> V_22 ) ;
F_111 ( & V_176 -> V_22 ) ;
F_29 ( & V_16 ) ;
F_112 ( & V_7 -> V_82 , & V_209 ) ;
F_35 ( & V_16 ) ;
V_174 = F_15 ( V_7 ) ;
if ( V_174 )
goto V_210;
F_100 ( & V_7 -> V_21 . V_181 ) ;
F_113 ( V_211 , V_7 -> V_21 . V_212 ) ;
if ( V_11 -> V_98 && V_11 -> V_97 )
F_113 ( V_213 , V_7 -> V_21 . V_212 ) ;
V_7 -> V_21 . V_214
= F_43 ;
V_7 -> V_21 . V_215 = F_49 ;
V_7 -> V_21 . V_216 = F_64 ;
V_7 -> V_21 . V_217 = F_79 ;
V_7 -> V_21 . V_218 = F_78 ;
V_7 -> V_21 . V_219 = F_70 ;
V_7 -> V_21 . V_220 = F_71 ;
V_7 -> V_21 . V_22 = & V_176 -> V_22 ;
V_7 -> V_21 . V_221 = V_52 ;
#if F_114 ( V_222 ) || F_114 ( V_223 )
V_196 = F_105 ( V_176 , V_200 , 1 ) ;
if ( ! V_196 )
V_196 = V_195 ;
else
V_192 ++ ;
if ( V_196 == V_195 ||
( V_195 -> V_15 & V_224 ) == V_225 )
V_186 = V_226 ;
V_189 = V_195 -> V_201 ;
V_174 = F_101 ( V_189 , F_88 , V_186 ,
L_22 , V_7 ) ;
if ( V_174 ) {
F_55 ( & V_176 -> V_22 ,
L_23 ,
V_189 , V_174 ) ;
goto V_227;
}
#else
V_196 = V_195 ;
#endif
if ( V_196 -> V_201 == V_196 -> V_228 &&
! F_105 ( V_176 , V_200 , 1 ) ) {
for (; V_191 < V_11 -> V_197 ; V_191 ++ ) {
if ( V_191 < V_165 ) {
V_190 [ V_191 ] = V_196 -> V_201 ;
V_188 [ V_191 ] = V_226 ;
} else {
V_193 = 1 ;
break;
}
}
} else {
do {
for ( V_37 = V_196 -> V_201 ; V_37 <= V_196 -> V_228 ; V_37 ++ ) {
if ( V_191 >= V_165 ) {
V_193 = 1 ;
break;
}
if ( ( V_195 -> V_15 & V_224 ) ==
V_225 )
V_188 [ V_191 ] = V_226 ;
else
V_188 [ V_191 ] = V_187 ;
F_33 ( & V_176 -> V_22 ,
L_24 ,
V_37 , V_191 ) ;
V_190 [ V_191 ++ ] = V_37 ;
}
if ( V_191 >= V_165 )
break;
V_196 = F_105 ( V_176 ,
V_200 , ++ V_192 ) ;
} while ( V_191 < V_11 -> V_197 && V_196 );
}
for ( V_37 = 0 ; V_37 < V_191 ; V_37 ++ ) {
V_174 = F_96 ( V_7 , V_37 , V_190 [ V_37 ] , V_188 [ V_37 ] ) ;
if ( V_174 )
goto V_229;
}
if ( V_193 )
F_115 ( & V_176 -> V_22 , L_25
L_26 ,
V_11 -> V_197 , V_165 ) ;
F_77 ( & V_176 -> V_22 ) ;
F_116 ( & V_7 -> V_21 ) ;
return V_174 ;
V_229:
F_102 ( V_7 ) ;
#if F_114 ( V_222 ) || F_114 ( V_223 )
F_103 ( V_189 , V_7 ) ;
V_227:
#endif
V_210:
F_29 ( & V_16 ) ;
F_117 ( & V_7 -> V_82 ) ;
F_35 ( & V_16 ) ;
F_77 ( & V_176 -> V_22 ) ;
F_118 ( & V_176 -> V_22 ) ;
if ( V_59 )
F_119 ( V_7 -> V_59 ) ;
F_109 ( V_176 , NULL ) ;
V_206:
F_119 ( V_7 -> V_9 ) ;
F_120 () ;
V_205:
F_53 ( V_7 ) ;
V_204:
if ( V_59 )
F_121 ( V_59 -> V_201 , F_107 ( V_59 ) ) ;
V_203:
F_121 ( V_70 -> V_201 , F_107 ( V_70 ) ) ;
return V_174 ;
}
static int T_11 F_122 ( struct V_175 * V_176 )
{
struct V_6 * V_7 = F_123 ( V_176 ) ;
struct V_194 * V_230 ;
int V_189 = F_124 ( V_176 , 0 ) ;
F_125 ( & V_7 -> V_21 ) ;
if ( V_189 > 0 )
F_103 ( V_189 , V_7 ) ;
F_29 ( & V_16 ) ;
F_117 ( & V_7 -> V_82 ) ;
F_35 ( & V_16 ) ;
F_102 ( V_7 ) ;
F_118 ( & V_176 -> V_22 ) ;
if ( V_7 -> V_59 )
F_119 ( V_7 -> V_59 ) ;
F_119 ( V_7 -> V_9 ) ;
F_109 ( V_176 , NULL ) ;
F_120 () ;
F_53 ( V_7 ) ;
V_230 = F_105 ( V_176 , V_199 , 0 ) ;
if ( V_230 )
F_121 ( V_230 -> V_201 , F_107 ( V_230 ) ) ;
V_230 = F_105 ( V_176 , V_199 , 1 ) ;
if ( V_230 )
F_121 ( V_230 -> V_201 , F_107 ( V_230 ) ) ;
return 0 ;
}
static void F_126 ( struct V_175 * V_176 )
{
struct V_6 * V_7 = F_123 ( V_176 ) ;
F_12 ( V_7 ) ;
}
static int F_127 ( struct V_178 * V_22 )
{
return 0 ;
}
static int F_128 ( struct V_178 * V_22 )
{
struct V_6 * V_7 = F_129 ( V_22 ) ;
return F_15 ( V_7 ) ;
}
static int F_130 ( struct V_178 * V_22 )
{
struct V_6 * V_7 = F_129 ( V_22 ) ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_7 -> V_11 -> V_197 ; V_37 ++ ) {
struct V_1 * V_24 = V_7 -> V_70 [ V_37 ] ;
if ( V_24 -> V_105 )
V_24 -> V_231 = F_131 ( V_22 ) ;
}
return 0 ;
}
static int F_132 ( struct V_178 * V_22 )
{
struct V_6 * V_7 = F_129 ( V_22 ) ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_7 -> V_11 -> V_197 ; V_37 ++ ) {
struct V_1 * V_24 = V_7 -> V_70 [ V_37 ] ;
struct V_71 * V_72 = V_24 -> V_21 . V_73 ;
if ( ! V_24 -> V_105 )
continue;
if ( ! V_24 -> V_231 )
F_111 ( V_22 ) ;
if ( V_72 ) {
const struct V_89 * V_90 = V_72 -> V_91 ;
F_25 ( V_24 , V_90 -> V_92 ) ;
F_24 ( V_24 , V_90 -> V_25 ) ;
} else {
F_23 ( V_24 ) ;
}
}
return 0 ;
}
static int T_10 F_133 ( void )
{
int V_174 = F_134 ( & V_232 ) ;
if ( V_174 )
return V_174 ;
return F_135 ( & V_233 , F_104 ) ;
}
static void T_11 F_136 ( void )
{
F_137 ( & V_233 ) ;
F_138 ( & V_232 ) ;
}
