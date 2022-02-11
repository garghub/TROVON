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
return F_6 ( V_7 -> V_8 + V_9 / sizeof( T_1 ) ) ;
}
static void F_7 ( struct V_6 * V_7 , T_2 V_3 )
{
F_8 ( V_3 , V_7 -> V_8 + V_9 / sizeof( T_1 ) ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
unsigned short V_10 ;
unsigned long V_11 ;
F_10 ( & V_12 , V_11 ) ;
V_10 = F_5 ( V_7 ) ;
F_7 ( V_7 , V_10 & ~ ( V_13 | V_14 | V_15 ) ) ;
F_11 ( & V_12 , V_11 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
unsigned short V_10 ;
unsigned long V_11 ;
F_10 ( & V_12 , V_11 ) ;
V_10 = F_5 ( V_7 ) & ~ ( V_13 | V_14 | V_15 ) ;
F_7 ( V_7 , V_10 | V_7 -> V_16 -> V_17 ) ;
V_10 = F_5 ( V_7 ) ;
F_11 ( & V_12 , V_11 ) ;
if ( V_10 & ( V_14 | V_13 ) ) {
F_13 ( V_7 -> V_18 . V_19 , L_1 ) ;
return - V_20 ;
}
return 0 ;
}
static bool F_14 ( struct V_1 * V_21 )
{
T_1 V_22 = F_3 ( V_21 , V_23 ) ;
if ( ( V_22 & ( V_24 | V_25 ) ) == V_24 )
return true ;
return false ;
}
static unsigned int F_15 ( struct V_1 * V_21 , T_1 V_22 )
{
struct V_6 * V_7 = F_16 ( V_21 -> V_18 . V_26 ,
struct V_6 , V_18 ) ;
struct V_27 * V_16 = V_7 -> V_16 ;
int V_28 = ( ( V_22 & V_16 -> V_29 ) >> V_16 -> V_30 ) |
( ( V_22 & V_16 -> V_31 ) >> V_16 -> V_32 ) ;
if ( V_28 >= V_16 -> V_33 )
V_28 = 0 ;
return V_16 -> V_34 [ V_28 ] ;
}
static T_1 F_17 ( struct V_1 * V_21 , int V_35 )
{
struct V_6 * V_7 = F_16 ( V_21 -> V_18 . V_26 ,
struct V_6 , V_18 ) ;
struct V_27 * V_16 = V_7 -> V_16 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_16 -> V_33 ; V_36 ++ )
if ( V_16 -> V_34 [ V_36 ] == V_35 )
break;
if ( V_36 == V_16 -> V_33 )
V_36 = 0 ;
return ( ( V_36 << V_16 -> V_30 ) & V_16 -> V_29 ) |
( ( V_36 << V_16 -> V_32 ) & V_16 -> V_31 ) ;
}
static void F_18 ( struct V_1 * V_21 , struct V_37 * V_38 )
{
F_1 ( V_21 , V_38 -> V_39 , V_40 ) ;
F_1 ( V_21 , V_38 -> V_41 , V_42 ) ;
F_1 ( V_21 , V_38 -> V_43 >> V_21 -> V_44 , V_45 ) ;
}
static void F_19 ( struct V_1 * V_21 )
{
T_1 V_22 = F_3 ( V_21 , V_23 ) ;
V_22 |= V_24 | V_46 ;
F_1 ( V_21 , V_22 & ~ V_25 , V_23 ) ;
}
static void F_20 ( struct V_1 * V_21 )
{
T_1 V_22 = F_3 ( V_21 , V_23 ) ;
V_22 &= ~ ( V_24 | V_25 | V_46 ) ;
F_1 ( V_21 , V_22 , V_23 ) ;
}
static void F_21 ( struct V_1 * V_21 )
{
T_1 V_22 = V_47 | V_48 | 0x400 | F_17 ( V_21 ,
V_49 ) ;
V_21 -> V_44 = F_15 ( V_21 , V_22 ) ;
F_1 ( V_21 , V_22 , V_23 ) ;
}
static int F_22 ( struct V_1 * V_21 , T_1 V_50 )
{
if ( F_14 ( V_21 ) )
return - V_51 ;
V_21 -> V_44 = F_15 ( V_21 , V_50 ) ;
F_1 ( V_21 , V_50 , V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_21 , T_2 V_50 )
{
struct V_6 * V_7 = F_16 ( V_21 -> V_18 . V_26 ,
struct V_6 , V_18 ) ;
struct V_27 * V_16 = V_7 -> V_16 ;
const struct V_52 * V_53 = & V_16 -> V_54 [ V_21 -> V_55 ] ;
T_2 T_3 * V_56 = V_7 -> V_57 ;
int V_58 = V_53 -> V_59 ;
if ( F_14 ( V_21 ) )
return - V_51 ;
if ( ! V_56 )
V_56 = ( T_2 T_3 * ) V_7 -> V_8 ;
V_56 += V_53 -> V_57 / sizeof( T_2 ) ;
F_8 ( ( F_6 ( V_56 ) & ( 0xff00 >> V_58 ) ) | ( V_50 << V_58 ) ,
V_56 ) ;
return 0 ;
}
static T_4 F_24 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = F_25 ( V_61 ) , * V_64 , * V_65 = V_63 , * V_66 ;
struct V_1 * V_21 = F_26 ( V_61 -> V_67 ) ;
T_5 V_68 = V_61 -> V_68 ;
T_4 V_69 ;
F_27 ( & V_21 -> V_70 ) ;
V_69 = V_21 -> V_18 . V_69 ;
V_69 ++ ;
if ( V_69 < 0 )
V_69 = 1 ;
V_21 -> V_18 . V_69 = V_69 ;
V_61 -> V_69 = V_69 ;
F_28 (chunk, c, desc->node.prev, node) {
if ( V_64 != V_63 && ( V_64 -> V_71 == V_72 ||
V_64 -> V_73 . V_69 > 0 ||
V_64 -> V_73 . V_69 == - V_51 ||
& V_64 -> V_74 == & V_21 -> V_75 ) )
break;
V_64 -> V_71 = V_76 ;
V_64 -> V_73 . V_68 = NULL ;
V_64 -> V_69 = V_69 ;
F_29 ( & V_64 -> V_74 , & V_21 -> V_77 ) ;
V_65 = V_64 ;
}
V_65 -> V_73 . V_68 = V_68 ;
V_65 -> V_73 . V_78 = V_61 -> V_78 ;
F_30 ( V_21 -> V_19 , L_2 ,
V_61 -> V_69 , & V_65 -> V_73 , V_21 -> V_55 ,
V_63 -> V_38 . V_39 , V_63 -> V_38 . V_43 , V_63 -> V_38 . V_41 ) ;
F_31 ( & V_21 -> V_70 ) ;
return V_69 ;
}
static struct V_62 * F_32 ( struct V_1 * V_21 )
{
struct V_62 * V_63 ;
F_33 (desc, &sh_chan->ld_free, node)
if ( V_63 -> V_71 != V_79 ) {
F_34 ( V_63 -> V_71 != V_72 ) ;
F_35 ( & V_63 -> V_74 ) ;
return V_63 ;
}
return NULL ;
}
static const struct V_80 * F_36 (
struct V_1 * V_21 , struct V_81 * V_82 )
{
struct V_83 * V_84 = V_21 -> V_18 . V_26 ;
struct V_6 * V_7 = F_16 ( V_84 ,
struct V_6 , V_18 ) ;
struct V_27 * V_16 = V_7 -> V_16 ;
int V_36 ;
if ( V_82 -> V_85 >= V_86 )
return NULL ;
for ( V_36 = 0 ; V_36 < V_16 -> V_87 ; V_36 ++ )
if ( V_16 -> V_88 [ V_36 ] . V_85 == V_82 -> V_85 )
return V_16 -> V_88 + V_36 ;
return NULL ;
}
static int F_37 ( struct V_89 * V_67 )
{
struct V_1 * V_21 = F_26 ( V_67 ) ;
struct V_62 * V_63 ;
struct V_81 * V_82 = V_67 -> V_90 ;
int V_91 ;
F_38 ( V_21 -> V_19 ) ;
if ( V_82 ) {
const struct V_80 * V_92 ;
V_92 = F_36 ( V_21 , V_82 ) ;
if ( ! V_92 ) {
V_91 = - V_93 ;
goto V_94;
}
if ( F_39 ( V_82 -> V_85 , V_95 ) ) {
V_91 = - V_51 ;
goto V_96;
}
V_82 -> V_97 = V_92 ;
F_23 ( V_21 , V_92 -> V_98 ) ;
F_22 ( V_21 , V_92 -> V_22 ) ;
} else {
F_21 ( V_21 ) ;
}
F_27 ( & V_21 -> V_70 ) ;
while ( V_21 -> V_99 < V_100 ) {
F_31 ( & V_21 -> V_70 ) ;
V_63 = F_40 ( sizeof( struct V_62 ) , V_101 ) ;
if ( ! V_63 ) {
F_27 ( & V_21 -> V_70 ) ;
break;
}
F_41 ( & V_63 -> V_73 ,
& V_21 -> V_18 ) ;
V_63 -> V_73 . V_102 = F_24 ;
V_63 -> V_71 = V_72 ;
F_27 ( & V_21 -> V_70 ) ;
F_42 ( & V_63 -> V_74 , & V_21 -> V_75 ) ;
V_21 -> V_99 ++ ;
}
F_31 ( & V_21 -> V_70 ) ;
if ( ! V_21 -> V_99 ) {
V_91 = - V_103 ;
goto V_104;
}
return V_21 -> V_99 ;
V_104:
if ( V_82 )
F_43 ( V_82 -> V_85 , V_95 ) ;
V_96:
V_94:
F_44 ( V_21 -> V_19 ) ;
return V_91 ;
}
static void F_45 ( struct V_89 * V_67 )
{
struct V_1 * V_21 = F_26 ( V_67 ) ;
struct V_62 * V_63 , * V_105 ;
F_46 ( V_106 ) ;
int V_107 = V_21 -> V_99 ;
F_47 ( & V_21 -> V_70 ) ;
F_20 ( V_21 ) ;
F_48 ( & V_21 -> V_70 ) ;
if ( ! F_49 ( & V_21 -> V_77 ) )
F_50 ( V_21 , true ) ;
if ( V_67 -> V_90 ) {
struct V_81 * V_82 = V_67 -> V_90 ;
F_43 ( V_82 -> V_85 , V_95 ) ;
V_67 -> V_90 = NULL ;
}
F_27 ( & V_21 -> V_70 ) ;
F_51 ( & V_21 -> V_75 , & V_106 ) ;
V_21 -> V_99 = 0 ;
F_31 ( & V_21 -> V_70 ) ;
if ( V_107 > 0 )
F_44 ( V_21 -> V_19 ) ;
F_28 (desc, _desc, &list, node)
F_52 ( V_63 ) ;
}
static struct V_62 * F_53 ( struct V_1 * V_21 ,
unsigned long V_11 , T_6 * V_108 , T_6 * V_109 , T_7 * V_110 ,
struct V_62 * * V_111 , enum V_112 V_113 )
{
struct V_62 * V_114 ;
T_7 V_115 ;
if ( ! * V_110 )
return NULL ;
V_114 = F_32 ( V_21 ) ;
if ( ! V_114 ) {
F_54 ( V_21 -> V_19 , L_3 ) ;
return NULL ;
}
V_115 = F_55 ( * V_110 , ( T_7 ) V_116 + 1 ) ;
V_114 -> V_38 . V_39 = * V_109 ;
V_114 -> V_38 . V_41 = * V_108 ;
V_114 -> V_38 . V_43 = V_115 ;
if ( ! * V_111 ) {
V_114 -> V_73 . V_69 = - V_51 ;
* V_111 = V_114 ;
} else {
V_114 -> V_73 . V_69 = - V_93 ;
}
F_30 ( V_21 -> V_19 ,
L_4 ,
V_115 , * V_110 , * V_109 , * V_108 , & V_114 -> V_73 ,
V_114 -> V_73 . V_69 , V_21 -> V_44 ) ;
V_114 -> V_71 = V_79 ;
V_114 -> V_73 . V_11 = V_11 ;
V_114 -> V_113 = V_113 ;
* V_110 -= V_115 ;
if ( V_113 == V_117 || V_113 == V_118 )
* V_109 += V_115 ;
if ( V_113 == V_117 || V_113 == V_119 )
* V_108 += V_115 ;
return V_114 ;
}
static struct V_60 * F_56 ( struct V_1 * V_21 ,
struct V_120 * V_121 , unsigned int V_122 , T_6 * V_56 ,
enum V_112 V_113 , unsigned long V_11 )
{
struct V_120 * V_123 ;
struct V_62 * V_111 = NULL , * V_114 = NULL ;
F_46 ( V_124 ) ;
int V_125 = 0 ;
int V_36 ;
if ( ! V_122 )
return NULL ;
F_57 (sgl, sg, sg_len, i)
V_125 += ( F_58 ( V_123 ) + V_116 ) /
( V_116 + 1 ) ;
F_27 ( & V_21 -> V_70 ) ;
F_57 (sgl, sg, sg_len, i) {
T_6 V_126 = F_59 ( V_123 ) ;
T_7 V_110 = F_58 ( V_123 ) ;
if ( ! V_110 )
goto V_127;
do {
F_30 ( V_21 -> V_19 , L_5 ,
V_36 , V_123 , V_110 , ( unsigned long long ) V_126 ) ;
if ( V_113 == V_119 )
V_114 = F_53 ( V_21 , V_11 ,
& V_126 , V_56 , & V_110 , & V_111 ,
V_113 ) ;
else
V_114 = F_53 ( V_21 , V_11 ,
V_56 , & V_126 , & V_110 , & V_111 ,
V_113 ) ;
if ( ! V_114 )
goto V_127;
V_114 -> V_125 = V_125 -- ;
F_60 ( & V_114 -> V_74 , & V_124 ) ;
} while ( V_110 );
}
if ( V_114 != V_111 )
V_114 -> V_73 . V_69 = - V_128 ;
F_61 ( & V_124 , & V_21 -> V_75 ) ;
F_31 ( & V_21 -> V_70 ) ;
return & V_111 -> V_73 ;
V_127:
F_33 (new, &tx_list, node)
V_114 -> V_71 = V_72 ;
F_62 ( & V_124 , & V_21 -> V_75 ) ;
F_31 ( & V_21 -> V_70 ) ;
return NULL ;
}
static struct V_60 * F_63 (
struct V_89 * V_67 , T_6 V_129 , T_6 V_130 ,
T_7 V_110 , unsigned long V_11 )
{
struct V_1 * V_21 ;
struct V_120 V_123 ;
if ( ! V_67 || ! V_110 )
return NULL ;
V_21 = F_26 ( V_67 ) ;
F_64 ( & V_123 , 1 ) ;
F_65 ( & V_123 , F_66 ( F_67 ( V_130 ) ) , V_110 ,
F_68 ( V_130 ) ) ;
F_59 ( & V_123 ) = V_130 ;
F_58 ( & V_123 ) = V_110 ;
return F_56 ( V_21 , & V_123 , 1 , & V_129 , V_117 ,
V_11 ) ;
}
static struct V_60 * F_69 (
struct V_89 * V_67 , struct V_120 * V_121 , unsigned int V_122 ,
enum V_112 V_113 , unsigned long V_11 )
{
struct V_81 * V_82 ;
struct V_1 * V_21 ;
T_6 V_131 ;
if ( ! V_67 )
return NULL ;
V_21 = F_26 ( V_67 ) ;
V_82 = V_67 -> V_90 ;
if ( ! V_82 || ! V_122 ) {
F_13 ( V_21 -> V_19 , L_6 ,
V_132 , V_82 , V_122 , V_82 ? V_82 -> V_85 : - 1 ) ;
return NULL ;
}
V_131 = V_82 -> V_97 -> V_56 ;
return F_56 ( V_21 , V_121 , V_122 , & V_131 ,
V_113 , V_11 ) ;
}
static int F_70 ( struct V_89 * V_67 , enum V_133 V_134 ,
unsigned long V_135 )
{
struct V_1 * V_21 = F_26 ( V_67 ) ;
if ( V_134 != V_136 )
return - V_137 ;
if ( ! V_67 )
return - V_93 ;
F_27 ( & V_21 -> V_70 ) ;
F_20 ( V_21 ) ;
if ( ! F_49 ( & V_21 -> V_77 ) ) {
struct V_62 * V_63 = F_71 ( V_21 -> V_77 . V_138 ,
struct V_62 , V_74 ) ;
V_63 -> V_139 = ( V_63 -> V_38 . V_43 - F_3 ( V_21 , V_45 ) ) <<
V_21 -> V_44 ;
}
F_31 ( & V_21 -> V_70 ) ;
F_50 ( V_21 , true ) ;
return 0 ;
}
static T_5 F_72 ( struct V_1 * V_21 , bool V_140 )
{
struct V_62 * V_63 , * V_105 ;
bool V_141 = false ;
T_4 V_69 = 0 ;
T_5 V_68 = NULL ;
void * V_82 = NULL ;
F_27 ( & V_21 -> V_70 ) ;
F_28 (desc, _desc, &sh_chan->ld_queue, node) {
struct V_60 * V_61 = & V_63 -> V_73 ;
F_34 ( V_61 -> V_69 > 0 && V_61 -> V_69 != V_63 -> V_69 ) ;
F_34 ( V_63 -> V_71 != V_76 &&
V_63 -> V_71 != V_142 &&
V_63 -> V_71 != V_143 ) ;
if ( ! V_140 && V_63 -> V_71 == V_76 &&
V_63 -> V_69 != V_69 )
break;
if ( V_61 -> V_69 > 0 )
V_69 = V_61 -> V_69 ;
if ( V_63 -> V_71 == V_142 && V_63 -> V_125 == 1 ) {
if ( V_21 -> V_144 != V_63 -> V_69 - 1 )
F_30 ( V_21 -> V_19 ,
L_7 ,
V_63 -> V_69 ,
V_21 -> V_144 + 1 ) ;
V_21 -> V_144 = V_63 -> V_69 ;
}
if ( V_63 -> V_71 == V_142 && V_61 -> V_68 ) {
V_63 -> V_71 = V_143 ;
V_68 = V_61 -> V_68 ;
V_82 = V_61 -> V_78 ;
F_30 ( V_21 -> V_19 , L_8 ,
V_61 -> V_69 , V_61 , V_21 -> V_55 ) ;
F_34 ( V_63 -> V_125 != 1 ) ;
break;
}
if ( V_61 -> V_69 > 0 || V_61 -> V_69 == - V_51 ) {
if ( V_63 -> V_71 == V_142 ) {
F_34 ( V_61 -> V_69 < 0 ) ;
V_63 -> V_71 = V_143 ;
}
V_141 = F_73 ( V_61 ) ;
} else {
switch ( V_63 -> V_71 ) {
case V_142 :
V_63 -> V_71 = V_143 ;
case V_143 :
if ( V_141 )
F_74 ( & V_63 -> V_73 ) ;
}
}
F_30 ( V_21 -> V_19 , L_9 ,
V_61 , V_61 -> V_69 ) ;
if ( ( ( V_63 -> V_71 == V_142 ||
V_63 -> V_71 == V_143 ) &&
F_73 ( & V_63 -> V_73 ) ) || V_140 ) {
V_63 -> V_71 = V_72 ;
F_75 ( & V_63 -> V_74 , & V_21 -> V_75 ) ;
}
}
if ( V_140 && ! V_68 )
V_21 -> V_144 = V_21 -> V_18 . V_69 ;
F_31 ( & V_21 -> V_70 ) ;
if ( V_68 )
V_68 ( V_82 ) ;
return V_68 ;
}
static void F_50 ( struct V_1 * V_21 , bool V_140 )
{
while ( F_72 ( V_21 , V_140 ) )
;
}
static void F_76 ( struct V_1 * V_21 )
{
struct V_62 * V_63 ;
F_27 ( & V_21 -> V_70 ) ;
if ( F_14 ( V_21 ) ) {
F_31 ( & V_21 -> V_70 ) ;
return;
}
F_33 (desc, &sh_chan->ld_queue, node)
if ( V_63 -> V_71 == V_76 ) {
F_30 ( V_21 -> V_19 , L_10 ,
V_63 -> V_73 . V_69 , V_21 -> V_55 ,
V_63 -> V_38 . V_43 , V_63 -> V_38 . V_39 , V_63 -> V_38 . V_41 ) ;
F_18 ( V_21 , & V_63 -> V_38 ) ;
F_19 ( V_21 ) ;
break;
}
F_31 ( & V_21 -> V_70 ) ;
}
static void F_77 ( struct V_89 * V_67 )
{
struct V_1 * V_21 = F_26 ( V_67 ) ;
F_76 ( V_21 ) ;
}
static enum V_145 F_78 ( struct V_89 * V_67 ,
T_4 V_69 ,
struct V_146 * V_147 )
{
struct V_1 * V_21 = F_26 ( V_67 ) ;
T_4 V_148 ;
T_4 V_149 ;
enum V_145 V_150 ;
F_50 ( V_21 , false ) ;
V_149 = V_21 -> V_144 ;
F_79 () ;
V_148 = V_67 -> V_69 ;
F_34 ( V_149 < 0 ) ;
F_80 ( V_147 , V_149 , V_148 , 0 ) ;
F_27 ( & V_21 -> V_70 ) ;
V_150 = F_81 ( V_69 , V_149 , V_148 ) ;
if ( V_150 != V_151 ) {
struct V_62 * V_63 ;
V_150 = V_152 ;
F_33 (desc, &sh_chan->ld_queue, node)
if ( V_63 -> V_69 == V_69 ) {
V_150 = V_153 ;
break;
}
}
F_31 ( & V_21 -> V_70 ) ;
return V_150 ;
}
static T_8 F_82 ( int V_154 , void * V_3 )
{
T_8 V_91 = V_155 ;
struct V_1 * V_21 = V_3 ;
T_1 V_22 ;
F_83 ( & V_21 -> V_70 ) ;
V_22 = F_3 ( V_21 , V_23 ) ;
if ( V_22 & V_25 ) {
F_20 ( V_21 ) ;
V_91 = V_156 ;
F_84 ( & V_21 -> V_157 ) ;
}
F_85 ( & V_21 -> V_70 ) ;
return V_91 ;
}
static bool F_86 ( struct V_6 * V_7 )
{
unsigned int V_158 = 0 ;
int V_36 ;
F_9 ( V_7 ) ;
for ( V_36 = 0 ; V_36 < V_159 ; V_36 ++ ) {
struct V_1 * V_21 = V_7 -> V_67 [ V_36 ] ;
struct V_62 * V_63 ;
F_46 ( V_160 ) ;
if ( ! V_21 )
continue;
F_83 ( & V_21 -> V_70 ) ;
F_20 ( V_21 ) ;
F_51 ( & V_21 -> V_77 , & V_160 ) ;
F_85 ( & V_21 -> V_70 ) ;
F_33 (desc, &dl, node) {
struct V_60 * V_61 = & V_63 -> V_73 ;
V_63 -> V_71 = V_72 ;
if ( V_61 -> V_68 )
V_61 -> V_68 ( V_61 -> V_78 ) ;
}
F_83 ( & V_21 -> V_70 ) ;
F_62 ( & V_160 , & V_21 -> V_75 ) ;
F_85 ( & V_21 -> V_70 ) ;
V_158 ++ ;
}
F_12 ( V_7 ) ;
return ! ! V_158 ;
}
static T_8 F_87 ( int V_154 , void * V_3 )
{
struct V_6 * V_7 = V_3 ;
if ( ! ( F_5 ( V_7 ) & V_14 ) )
return V_155 ;
F_86 ( V_3 ) ;
return V_156 ;
}
static void F_88 ( unsigned long V_3 )
{
struct V_1 * V_21 = (struct V_1 * ) V_3 ;
struct V_62 * V_63 ;
T_1 V_161 = F_3 ( V_21 , V_40 ) ;
T_1 V_162 = F_3 ( V_21 , V_42 ) ;
F_83 ( & V_21 -> V_70 ) ;
F_33 (desc, &sh_chan->ld_queue, node) {
if ( V_63 -> V_71 == V_76 &&
( ( V_63 -> V_113 == V_119 &&
( V_63 -> V_38 . V_41 + V_63 -> V_38 . V_43 ) == V_162 ) ||
( V_63 -> V_38 . V_39 + V_63 -> V_38 . V_43 ) == V_161 ) ) {
F_30 ( V_21 -> V_19 , L_11 ,
V_63 -> V_73 . V_69 , & V_63 -> V_73 ,
V_63 -> V_38 . V_41 ) ;
V_63 -> V_71 = V_142 ;
break;
}
}
F_85 ( & V_21 -> V_70 ) ;
F_76 ( V_21 ) ;
F_50 ( V_21 , false ) ;
}
static bool F_89 ( struct V_6 * V_7 )
{
if ( ( F_5 ( V_7 ) & V_13 ) == 0 )
return false ;
return F_86 ( V_7 ) ;
}
static int F_90 ( struct V_163 * V_164 ,
unsigned long V_134 , void * V_3 )
{
struct V_6 * V_7 ;
int V_91 = V_165 ;
bool V_166 ;
if ( ! F_91 () )
return V_165 ;
F_92 () ;
F_93 (shdev, &sh_dmae_devices, node) {
V_166 = F_89 ( V_7 ) ;
if ( V_166 == true )
V_91 = V_167 ;
}
F_94 () ;
return V_91 ;
}
static int T_9 F_95 ( struct V_6 * V_7 , int V_55 ,
int V_154 , unsigned long V_11 )
{
int V_168 ;
const struct V_52 * V_53 = & V_7 -> V_16 -> V_54 [ V_55 ] ;
struct V_169 * V_170 = F_96 ( V_7 -> V_18 . V_19 ) ;
struct V_1 * V_171 ;
V_171 = F_40 ( sizeof( struct V_1 ) , V_101 ) ;
if ( ! V_171 ) {
F_54 ( V_7 -> V_18 . V_19 ,
L_12 ) ;
return - V_103 ;
}
V_171 -> V_18 . V_26 = & V_7 -> V_18 ;
V_171 -> V_19 = V_7 -> V_18 . V_19 ;
V_171 -> V_55 = V_55 ;
V_171 -> V_154 = V_154 ;
V_171 -> V_5 = V_7 -> V_8 + V_53 -> V_172 / sizeof( T_1 ) ;
F_97 ( & V_171 -> V_157 , F_88 ,
( unsigned long ) V_171 ) ;
F_98 ( & V_171 -> V_70 ) ;
F_99 ( & V_171 -> V_77 ) ;
F_99 ( & V_171 -> V_75 ) ;
F_60 ( & V_171 -> V_18 . V_173 ,
& V_7 -> V_18 . V_174 ) ;
V_7 -> V_18 . V_175 ++ ;
if ( V_170 -> V_55 >= 0 )
snprintf ( V_171 -> V_176 , sizeof( V_171 -> V_176 ) ,
L_13 , V_170 -> V_55 , V_171 -> V_55 ) ;
else
snprintf ( V_171 -> V_176 , sizeof( V_171 -> V_176 ) ,
L_14 , V_171 -> V_55 ) ;
V_168 = F_100 ( V_154 , & F_82 , V_11 ,
V_171 -> V_176 , V_171 ) ;
if ( V_168 ) {
F_54 ( V_7 -> V_18 . V_19 , L_15
L_16 , V_55 , V_168 ) ;
goto V_177;
}
V_7 -> V_67 [ V_55 ] = V_171 ;
return 0 ;
V_177:
F_35 ( & V_171 -> V_18 . V_173 ) ;
F_52 ( V_171 ) ;
return V_168 ;
}
static void F_101 ( struct V_6 * V_7 )
{
int V_36 ;
for ( V_36 = V_7 -> V_18 . V_175 - 1 ; V_36 >= 0 ; V_36 -- ) {
if ( V_7 -> V_67 [ V_36 ] ) {
struct V_1 * V_21 = V_7 -> V_67 [ V_36 ] ;
F_102 ( V_21 -> V_154 , V_21 ) ;
F_35 ( & V_21 -> V_18 . V_173 ) ;
F_52 ( V_21 ) ;
V_7 -> V_67 [ V_36 ] = NULL ;
}
}
V_7 -> V_18 . V_175 = 0 ;
}
static int T_10 F_103 ( struct V_169 * V_170 )
{
struct V_27 * V_16 = V_170 -> V_19 . V_178 ;
unsigned long V_179 = V_180 ,
V_181 [ V_159 ] = {} ;
int V_182 , V_183 [ V_159 ] ;
int V_168 , V_36 , V_184 = 0 , V_185 = 0 , V_186 = 0 ;
struct V_6 * V_7 ;
struct V_187 * V_67 , * V_57 , * V_188 , * V_189 ;
if ( ! V_16 || ! V_16 -> V_190 )
return - V_191 ;
V_67 = F_104 ( V_170 , V_192 , 0 ) ;
V_57 = F_104 ( V_170 , V_192 , 1 ) ;
V_188 = F_104 ( V_170 , V_193 , 0 ) ;
if ( ! V_67 || ! V_188 )
return - V_191 ;
if ( ! F_105 ( V_67 -> V_194 , F_106 ( V_67 ) , V_170 -> V_195 ) ) {
F_54 ( & V_170 -> V_19 , L_17 ) ;
return - V_51 ;
}
if ( V_57 && ! F_105 ( V_57 -> V_194 , F_106 ( V_57 ) , V_170 -> V_195 ) ) {
F_54 ( & V_170 -> V_19 , L_18 ) ;
V_168 = - V_51 ;
goto V_196;
}
V_168 = - V_103 ;
V_7 = F_40 ( sizeof( struct V_6 ) , V_101 ) ;
if ( ! V_7 ) {
F_54 ( & V_170 -> V_19 , L_19 ) ;
goto V_197;
}
V_7 -> V_8 = F_107 ( V_67 -> V_194 , F_106 ( V_67 ) ) ;
if ( ! V_7 -> V_8 )
goto V_198;
if ( V_57 ) {
V_7 -> V_57 = F_107 ( V_57 -> V_194 , F_106 ( V_57 ) ) ;
if ( ! V_7 -> V_57 )
goto V_199;
}
V_7 -> V_16 = V_16 ;
F_108 ( V_170 , V_7 ) ;
F_109 ( & V_170 -> V_19 ) ;
F_38 ( & V_170 -> V_19 ) ;
F_47 ( & V_12 ) ;
F_110 ( & V_7 -> V_74 , & V_200 ) ;
F_48 ( & V_12 ) ;
V_168 = F_12 ( V_7 ) ;
if ( V_168 )
goto V_201;
F_99 ( & V_7 -> V_18 . V_174 ) ;
F_111 ( V_202 , V_7 -> V_18 . V_203 ) ;
if ( V_16 -> V_88 && V_16 -> V_87 )
F_111 ( V_204 , V_7 -> V_18 . V_203 ) ;
V_7 -> V_18 . V_205
= F_37 ;
V_7 -> V_18 . V_206 = F_45 ;
V_7 -> V_18 . V_207 = F_63 ;
V_7 -> V_18 . V_208 = F_78 ;
V_7 -> V_18 . V_209 = F_77 ;
V_7 -> V_18 . V_210 = F_69 ;
V_7 -> V_18 . V_211 = F_70 ;
V_7 -> V_18 . V_19 = & V_170 -> V_19 ;
V_7 -> V_18 . V_212 = V_49 ;
#if F_112 ( V_213 ) || F_112 ( V_214 )
V_189 = F_104 ( V_170 , V_193 , 1 ) ;
if ( ! V_189 )
V_189 = V_188 ;
else
V_185 ++ ;
if ( V_189 == V_188 ||
( V_188 -> V_11 & V_215 ) == V_216 )
V_179 = V_217 ;
V_182 = V_188 -> V_194 ;
V_168 = F_100 ( V_182 , F_87 , V_179 ,
L_20 , V_7 ) ;
if ( V_168 ) {
F_54 ( & V_170 -> V_19 ,
L_21 ,
V_182 , V_168 ) ;
goto V_218;
}
#else
V_189 = V_188 ;
#endif
if ( V_189 -> V_194 == V_189 -> V_219 &&
! F_104 ( V_170 , V_193 , 1 ) ) {
for (; V_184 < V_16 -> V_190 ; V_184 ++ ) {
if ( V_184 < V_159 ) {
V_183 [ V_184 ] = V_189 -> V_194 ;
V_181 [ V_184 ] = V_217 ;
} else {
V_186 = 1 ;
break;
}
}
} else {
do {
for ( V_36 = V_189 -> V_194 ; V_36 <= V_189 -> V_219 ; V_36 ++ ) {
if ( V_184 >= V_159 ) {
V_186 = 1 ;
break;
}
if ( ( V_188 -> V_11 & V_215 ) ==
V_216 )
V_181 [ V_184 ] = V_217 ;
else
V_181 [ V_184 ] = V_180 ;
F_30 ( & V_170 -> V_19 ,
L_22 ,
V_36 , V_184 ) ;
V_183 [ V_184 ++ ] = V_36 ;
}
if ( V_184 >= V_159 )
break;
V_189 = F_104 ( V_170 ,
V_193 , ++ V_185 ) ;
} while ( V_184 < V_16 -> V_190 && V_189 );
}
for ( V_36 = 0 ; V_36 < V_184 ; V_36 ++ ) {
V_168 = F_95 ( V_7 , V_36 , V_183 [ V_36 ] , V_181 [ V_36 ] ) ;
if ( V_168 )
goto V_220;
}
if ( V_186 )
F_113 ( & V_170 -> V_19 , L_23
L_24 ,
V_16 -> V_190 , V_159 ) ;
F_44 ( & V_170 -> V_19 ) ;
F_114 ( & V_7 -> V_18 ) ;
return V_168 ;
V_220:
F_101 ( V_7 ) ;
#if F_112 ( V_213 ) || F_112 ( V_214 )
F_102 ( V_182 , V_7 ) ;
V_218:
#endif
V_201:
F_47 ( & V_12 ) ;
F_115 ( & V_7 -> V_74 ) ;
F_48 ( & V_12 ) ;
F_44 ( & V_170 -> V_19 ) ;
F_116 ( & V_170 -> V_19 ) ;
if ( V_57 )
F_117 ( V_7 -> V_57 ) ;
F_108 ( V_170 , NULL ) ;
V_199:
F_117 ( V_7 -> V_8 ) ;
F_118 () ;
V_198:
F_52 ( V_7 ) ;
V_197:
if ( V_57 )
F_119 ( V_57 -> V_194 , F_106 ( V_57 ) ) ;
V_196:
F_119 ( V_67 -> V_194 , F_106 ( V_67 ) ) ;
return V_168 ;
}
static int T_11 F_120 ( struct V_169 * V_170 )
{
struct V_6 * V_7 = F_121 ( V_170 ) ;
struct V_187 * V_221 ;
int V_182 = F_122 ( V_170 , 0 ) ;
F_123 ( & V_7 -> V_18 ) ;
if ( V_182 > 0 )
F_102 ( V_182 , V_7 ) ;
F_47 ( & V_12 ) ;
F_115 ( & V_7 -> V_74 ) ;
F_48 ( & V_12 ) ;
F_101 ( V_7 ) ;
F_116 ( & V_170 -> V_19 ) ;
if ( V_7 -> V_57 )
F_117 ( V_7 -> V_57 ) ;
F_117 ( V_7 -> V_8 ) ;
F_108 ( V_170 , NULL ) ;
F_118 () ;
F_52 ( V_7 ) ;
V_221 = F_104 ( V_170 , V_192 , 0 ) ;
if ( V_221 )
F_119 ( V_221 -> V_194 , F_106 ( V_221 ) ) ;
V_221 = F_104 ( V_170 , V_192 , 1 ) ;
if ( V_221 )
F_119 ( V_221 -> V_194 , F_106 ( V_221 ) ) ;
return 0 ;
}
static void F_124 ( struct V_169 * V_170 )
{
struct V_6 * V_7 = F_121 ( V_170 ) ;
F_9 ( V_7 ) ;
}
static int F_125 ( struct V_26 * V_19 )
{
return 0 ;
}
static int F_126 ( struct V_26 * V_19 )
{
struct V_6 * V_7 = F_127 ( V_19 ) ;
return F_12 ( V_7 ) ;
}
static int F_128 ( struct V_26 * V_19 )
{
struct V_6 * V_7 = F_127 ( V_19 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_7 -> V_16 -> V_190 ; V_36 ++ ) {
struct V_1 * V_21 = V_7 -> V_67 [ V_36 ] ;
if ( V_21 -> V_99 )
V_21 -> V_222 = F_129 ( V_19 ) ;
}
return 0 ;
}
static int F_130 ( struct V_26 * V_19 )
{
struct V_6 * V_7 = F_127 ( V_19 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_7 -> V_16 -> V_190 ; V_36 ++ ) {
struct V_1 * V_21 = V_7 -> V_67 [ V_36 ] ;
struct V_81 * V_82 = V_21 -> V_18 . V_90 ;
if ( ! V_21 -> V_99 )
continue;
if ( ! V_21 -> V_222 )
F_38 ( V_19 ) ;
if ( V_82 ) {
const struct V_80 * V_92 = V_82 -> V_97 ;
F_23 ( V_21 , V_92 -> V_98 ) ;
F_22 ( V_21 , V_92 -> V_22 ) ;
} else {
F_21 ( V_21 ) ;
}
}
return 0 ;
}
static int T_10 F_131 ( void )
{
int V_168 = F_132 ( & V_223 ) ;
if ( V_168 )
return V_168 ;
return F_133 ( & V_224 , F_103 ) ;
}
static void T_11 F_134 ( void )
{
F_135 ( & V_224 ) ;
F_136 ( & V_223 ) ;
}
