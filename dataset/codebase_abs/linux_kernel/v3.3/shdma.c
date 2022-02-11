static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_3 , V_5 -> V_6 +
V_5 -> V_7 -> V_8 [ V_2 -> V_9 ] . V_10 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
F_3 ( V_3 , V_2 -> V_12 + V_11 / sizeof( T_1 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_11 )
{
return F_6 ( V_2 -> V_12 + V_11 / sizeof( T_1 ) ) ;
}
static T_2 F_7 ( struct V_4 * V_5 )
{
T_1 T_3 * V_13 = V_5 -> V_6 + V_14 / sizeof( T_1 ) ;
if ( V_5 -> V_7 -> V_15 )
return F_6 ( V_13 ) ;
else
return F_8 ( V_13 ) ;
}
static void F_9 ( struct V_4 * V_5 , T_2 V_3 )
{
T_1 T_3 * V_13 = V_5 -> V_6 + V_14 / sizeof( T_1 ) ;
if ( V_5 -> V_7 -> V_15 )
F_3 ( V_3 , V_13 ) ;
else
F_10 ( V_3 , V_13 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_3 , V_2 -> V_12 + V_5 -> V_16 / sizeof( T_1 ) ) ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_6 ( V_2 -> V_12 + V_5 -> V_16 / sizeof( T_1 ) ) ;
}
static void F_13 ( struct V_4 * V_5 )
{
unsigned short V_17 ;
unsigned long V_18 ;
F_14 ( & V_19 , V_18 ) ;
V_17 = F_7 ( V_5 ) ;
F_9 ( V_5 , V_17 & ~ ( V_20 | V_21 | V_22 ) ) ;
F_15 ( & V_19 , V_18 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
unsigned short V_17 ;
unsigned long V_18 ;
F_14 ( & V_19 , V_18 ) ;
V_17 = F_7 ( V_5 ) & ~ ( V_20 | V_21 | V_22 ) ;
if ( V_5 -> V_7 -> V_23 ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < V_5 -> V_7 -> V_25 ; V_24 ++ ) {
struct V_1 * V_26 = V_5 -> V_27 [ V_24 ] ;
if ( V_26 )
F_1 ( V_26 , 0 ) ;
}
}
F_9 ( V_5 , V_17 | V_5 -> V_7 -> V_28 ) ;
V_17 = F_7 ( V_5 ) ;
F_15 ( & V_19 , V_18 ) ;
if ( V_17 & ( V_21 | V_20 ) ) {
F_17 ( V_5 -> V_29 . V_30 , L_1 ) ;
return - V_31 ;
}
if ( V_5 -> V_7 -> V_28 & ~ V_17 )
F_17 ( V_5 -> V_29 . V_30 ,
L_2 ,
V_17 , V_5 -> V_7 -> V_28 ) ;
return 0 ;
}
static bool F_18 ( struct V_1 * V_26 )
{
T_1 V_32 = F_12 ( V_26 ) ;
if ( ( V_32 & ( V_33 | V_34 ) ) == V_33 )
return true ;
return false ;
}
static unsigned int F_19 ( struct V_1 * V_26 , T_1 V_32 )
{
struct V_4 * V_5 = F_2 ( V_26 ) ;
struct V_35 * V_7 = V_5 -> V_7 ;
int V_36 = ( ( V_32 & V_7 -> V_37 ) >> V_7 -> V_38 ) |
( ( V_32 & V_7 -> V_39 ) >> V_7 -> V_40 ) ;
if ( V_36 >= V_7 -> V_41 )
V_36 = 0 ;
return V_7 -> V_42 [ V_36 ] ;
}
static T_1 F_20 ( struct V_1 * V_26 , int V_43 )
{
struct V_4 * V_5 = F_2 ( V_26 ) ;
struct V_35 * V_7 = V_5 -> V_7 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_7 -> V_41 ; V_24 ++ )
if ( V_7 -> V_42 [ V_24 ] == V_43 )
break;
if ( V_24 == V_7 -> V_41 )
V_24 = 0 ;
return ( ( V_24 << V_7 -> V_38 ) & V_7 -> V_37 ) |
( ( V_24 << V_7 -> V_40 ) & V_7 -> V_39 ) ;
}
static void F_21 ( struct V_1 * V_26 , struct V_44 * V_45 )
{
F_4 ( V_26 , V_45 -> V_46 , V_47 ) ;
F_4 ( V_26 , V_45 -> V_48 , V_49 ) ;
F_4 ( V_26 , V_45 -> V_50 >> V_26 -> V_51 , V_52 ) ;
}
static void F_22 ( struct V_1 * V_26 )
{
struct V_4 * V_5 = F_2 ( V_26 ) ;
T_1 V_32 = F_12 ( V_26 ) ;
if ( V_5 -> V_7 -> V_53 )
F_4 ( V_26 , 0xFFFFFFFF , V_54 ) ;
V_32 |= V_33 | V_5 -> V_55 ;
F_11 ( V_26 , V_32 & ~ V_34 ) ;
}
static void F_23 ( struct V_1 * V_26 )
{
struct V_4 * V_5 = F_2 ( V_26 ) ;
T_1 V_32 = F_12 ( V_26 ) ;
V_32 &= ~ ( V_33 | V_34 | V_5 -> V_55 ) ;
F_11 ( V_26 , V_32 ) ;
}
static void F_24 ( struct V_1 * V_26 )
{
T_1 V_32 = V_56 | V_57 | 0x400 | F_20 ( V_26 ,
V_58 ) ;
V_26 -> V_51 = F_19 ( V_26 , V_32 ) ;
F_11 ( V_26 , V_32 ) ;
}
static int F_25 ( struct V_1 * V_26 , T_1 V_59 )
{
if ( F_18 ( V_26 ) )
return - V_60 ;
V_26 -> V_51 = F_19 ( V_26 , V_59 ) ;
F_11 ( V_26 , V_59 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_26 , T_2 V_59 )
{
struct V_4 * V_5 = F_2 ( V_26 ) ;
struct V_35 * V_7 = V_5 -> V_7 ;
const struct V_61 * V_62 = & V_7 -> V_8 [ V_26 -> V_9 ] ;
T_2 T_3 * V_13 = V_5 -> V_63 ;
unsigned int V_64 = V_62 -> V_65 ;
if ( F_18 ( V_26 ) )
return - V_60 ;
if ( V_7 -> V_66 )
return 0 ;
if ( ! V_13 )
V_13 = ( T_2 T_3 * ) V_5 -> V_6 ;
V_13 += V_62 -> V_63 / sizeof( T_2 ) ;
F_10 ( ( F_8 ( V_13 ) & ( 0xff00 >> V_64 ) ) | ( V_59 << V_64 ) ,
V_13 ) ;
return 0 ;
}
static T_4 F_27 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = F_28 ( V_68 ) , * V_71 , * V_72 = V_70 , * V_73 ;
struct V_1 * V_26 = F_29 ( V_68 -> V_27 ) ;
struct V_74 * V_75 = V_68 -> V_27 -> V_76 ;
T_5 V_77 = V_68 -> V_77 ;
T_4 V_78 ;
bool V_79 ;
F_30 ( & V_26 -> V_80 ) ;
if ( F_31 ( & V_26 -> V_81 ) )
V_79 = true ;
else
V_79 = false ;
V_78 = V_26 -> V_29 . V_78 ;
V_78 ++ ;
if ( V_78 < 0 )
V_78 = 1 ;
V_26 -> V_29 . V_78 = V_78 ;
V_68 -> V_78 = V_78 ;
F_32 (chunk, c, desc->node.prev, node) {
if ( V_71 != V_70 && ( V_71 -> V_82 == V_83 ||
V_71 -> V_84 . V_78 > 0 ||
V_71 -> V_84 . V_78 == - V_60 ||
& V_71 -> V_85 == & V_26 -> V_86 ) )
break;
V_71 -> V_82 = V_87 ;
V_71 -> V_84 . V_77 = NULL ;
V_71 -> V_78 = V_78 ;
F_33 ( & V_71 -> V_85 , & V_26 -> V_81 ) ;
V_72 = V_71 ;
}
V_72 -> V_84 . V_77 = V_77 ;
V_72 -> V_84 . V_88 = V_68 -> V_88 ;
F_34 ( V_26 -> V_30 , L_3 ,
V_68 -> V_78 , & V_72 -> V_84 , V_26 -> V_9 ,
V_70 -> V_45 . V_46 , V_70 -> V_45 . V_50 , V_70 -> V_45 . V_48 ) ;
if ( V_79 ) {
V_26 -> V_89 = V_90 ;
F_35 ( V_26 -> V_30 ) ;
F_36 ( & V_26 -> V_80 ) ;
F_37 ( V_26 -> V_30 ) ;
F_30 ( & V_26 -> V_80 ) ;
if ( V_26 -> V_89 != V_91 ) {
F_34 ( V_26 -> V_30 , L_4 ,
V_26 -> V_9 ) ;
if ( V_75 ) {
const struct V_92 * V_93 =
V_75 -> V_94 ;
F_26 ( V_26 , V_93 -> V_95 ) ;
F_25 ( V_26 , V_93 -> V_32 ) ;
} else {
F_24 ( V_26 ) ;
}
if ( V_26 -> V_89 == V_96 )
F_38 ( V_26 ) ;
V_26 -> V_89 = V_91 ;
}
} else {
V_26 -> V_89 = V_96 ;
}
F_36 ( & V_26 -> V_80 ) ;
return V_78 ;
}
static struct V_69 * F_39 ( struct V_1 * V_26 )
{
struct V_69 * V_70 ;
F_40 (desc, &sh_chan->ld_free, node)
if ( V_70 -> V_82 != V_97 ) {
F_41 ( V_70 -> V_82 != V_83 ) ;
F_42 ( & V_70 -> V_85 ) ;
return V_70 ;
}
return NULL ;
}
static const struct V_92 * F_43 (
struct V_1 * V_26 , struct V_74 * V_75 )
{
struct V_4 * V_5 = F_2 ( V_26 ) ;
struct V_35 * V_7 = V_5 -> V_7 ;
int V_24 ;
if ( V_75 -> V_98 >= V_99 )
return NULL ;
for ( V_24 = 0 ; V_24 < V_7 -> V_100 ; V_24 ++ )
if ( V_7 -> V_101 [ V_24 ] . V_98 == V_75 -> V_98 )
return V_7 -> V_101 + V_24 ;
return NULL ;
}
static int F_44 ( struct V_102 * V_27 )
{
struct V_1 * V_26 = F_29 ( V_27 ) ;
struct V_69 * V_70 ;
struct V_74 * V_75 = V_27 -> V_76 ;
int V_103 ;
if ( V_75 ) {
const struct V_92 * V_93 ;
V_93 = F_43 ( V_26 , V_75 ) ;
if ( ! V_93 ) {
V_103 = - V_104 ;
goto V_105;
}
if ( F_45 ( V_75 -> V_98 , V_106 ) ) {
V_103 = - V_60 ;
goto V_107;
}
V_75 -> V_94 = V_93 ;
}
while ( V_26 -> V_108 < V_109 ) {
V_70 = F_46 ( sizeof( struct V_69 ) , V_110 ) ;
if ( ! V_70 )
break;
F_47 ( & V_70 -> V_84 ,
& V_26 -> V_29 ) ;
V_70 -> V_84 . V_111 = F_27 ;
V_70 -> V_82 = V_83 ;
F_48 ( & V_70 -> V_85 , & V_26 -> V_86 ) ;
V_26 -> V_108 ++ ;
}
if ( ! V_26 -> V_108 ) {
V_103 = - V_112 ;
goto V_113;
}
return V_26 -> V_108 ;
V_113:
if ( V_75 )
F_49 ( V_75 -> V_98 , V_106 ) ;
V_107:
V_105:
V_27 -> V_76 = NULL ;
return V_103 ;
}
static void F_50 ( struct V_102 * V_27 )
{
struct V_1 * V_26 = F_29 ( V_27 ) ;
struct V_69 * V_70 , * V_114 ;
F_51 ( V_115 ) ;
F_30 ( & V_26 -> V_80 ) ;
F_23 ( V_26 ) ;
F_36 ( & V_26 -> V_80 ) ;
if ( ! F_31 ( & V_26 -> V_81 ) )
F_52 ( V_26 , true ) ;
if ( V_27 -> V_76 ) {
struct V_74 * V_75 = V_27 -> V_76 ;
F_49 ( V_75 -> V_98 , V_106 ) ;
V_27 -> V_76 = NULL ;
}
F_30 ( & V_26 -> V_80 ) ;
F_53 ( & V_26 -> V_86 , & V_115 ) ;
V_26 -> V_108 = 0 ;
F_36 ( & V_26 -> V_80 ) ;
F_32 (desc, _desc, &list, node)
F_54 ( V_70 ) ;
}
static struct V_69 * F_55 ( struct V_1 * V_26 ,
unsigned long V_18 , T_6 * V_116 , T_6 * V_117 , T_7 * V_118 ,
struct V_69 * * V_119 , enum V_120 V_121 )
{
struct V_69 * V_122 ;
T_7 V_123 ;
if ( ! * V_118 )
return NULL ;
V_122 = F_39 ( V_26 ) ;
if ( ! V_122 ) {
F_56 ( V_26 -> V_30 , L_5 ) ;
return NULL ;
}
V_123 = F_57 ( * V_118 , ( T_7 ) V_124 + 1 ) ;
V_122 -> V_45 . V_46 = * V_117 ;
V_122 -> V_45 . V_48 = * V_116 ;
V_122 -> V_45 . V_50 = V_123 ;
if ( ! * V_119 ) {
V_122 -> V_84 . V_78 = - V_60 ;
* V_119 = V_122 ;
} else {
V_122 -> V_84 . V_78 = - V_104 ;
}
F_34 ( V_26 -> V_30 ,
L_6 ,
V_123 , * V_118 , * V_117 , * V_116 , & V_122 -> V_84 ,
V_122 -> V_84 . V_78 , V_26 -> V_51 ) ;
V_122 -> V_82 = V_97 ;
V_122 -> V_84 . V_18 = V_18 ;
V_122 -> V_121 = V_121 ;
* V_118 -= V_123 ;
if ( V_121 == V_125 || V_121 == V_126 )
* V_117 += V_123 ;
if ( V_121 == V_125 || V_121 == V_127 )
* V_116 += V_123 ;
return V_122 ;
}
static struct V_67 * F_58 ( struct V_1 * V_26 ,
struct V_128 * V_129 , unsigned int V_130 , T_6 * V_13 ,
enum V_120 V_121 , unsigned long V_18 )
{
struct V_128 * V_131 ;
struct V_69 * V_119 = NULL , * V_122 = NULL ;
F_51 ( V_132 ) ;
int V_133 = 0 ;
unsigned long V_134 ;
int V_24 ;
if ( ! V_130 )
return NULL ;
F_59 (sgl, sg, sg_len, i)
V_133 += ( F_60 ( V_131 ) + V_124 ) /
( V_124 + 1 ) ;
F_14 ( & V_26 -> V_80 , V_134 ) ;
F_59 (sgl, sg, sg_len, i) {
T_6 V_135 = F_61 ( V_131 ) ;
T_7 V_118 = F_60 ( V_131 ) ;
if ( ! V_118 )
goto V_136;
do {
F_34 ( V_26 -> V_30 , L_7 ,
V_24 , V_131 , V_118 , ( unsigned long long ) V_135 ) ;
if ( V_121 == V_127 )
V_122 = F_55 ( V_26 , V_18 ,
& V_135 , V_13 , & V_118 , & V_119 ,
V_121 ) ;
else
V_122 = F_55 ( V_26 , V_18 ,
V_13 , & V_135 , & V_118 , & V_119 ,
V_121 ) ;
if ( ! V_122 )
goto V_136;
V_122 -> V_133 = V_133 -- ;
F_62 ( & V_122 -> V_85 , & V_132 ) ;
} while ( V_118 );
}
if ( V_122 != V_119 )
V_122 -> V_84 . V_78 = - V_137 ;
F_63 ( & V_132 , & V_26 -> V_86 ) ;
F_15 ( & V_26 -> V_80 , V_134 ) ;
return & V_119 -> V_84 ;
V_136:
F_40 (new, &tx_list, node)
V_122 -> V_82 = V_83 ;
F_64 ( & V_132 , & V_26 -> V_86 ) ;
F_15 ( & V_26 -> V_80 , V_134 ) ;
return NULL ;
}
static struct V_67 * F_65 (
struct V_102 * V_27 , T_6 V_138 , T_6 V_139 ,
T_7 V_118 , unsigned long V_18 )
{
struct V_1 * V_26 ;
struct V_128 V_131 ;
if ( ! V_27 || ! V_118 )
return NULL ;
V_26 = F_29 ( V_27 ) ;
F_66 ( & V_131 , 1 ) ;
F_67 ( & V_131 , F_68 ( F_69 ( V_139 ) ) , V_118 ,
F_70 ( V_139 ) ) ;
F_61 ( & V_131 ) = V_139 ;
F_60 ( & V_131 ) = V_118 ;
return F_58 ( V_26 , & V_131 , 1 , & V_138 , V_125 ,
V_18 ) ;
}
static struct V_67 * F_71 (
struct V_102 * V_27 , struct V_128 * V_129 , unsigned int V_130 ,
enum V_120 V_121 , unsigned long V_18 )
{
struct V_74 * V_75 ;
struct V_1 * V_26 ;
T_6 V_140 ;
if ( ! V_27 )
return NULL ;
V_26 = F_29 ( V_27 ) ;
V_75 = V_27 -> V_76 ;
if ( ! V_75 || ! V_130 ) {
F_17 ( V_26 -> V_30 , L_8 ,
V_141 , V_75 , V_130 , V_75 ? V_75 -> V_98 : - 1 ) ;
return NULL ;
}
V_140 = V_75 -> V_94 -> V_13 ;
return F_58 ( V_26 , V_129 , V_130 , & V_140 ,
V_121 , V_18 ) ;
}
static int F_72 ( struct V_102 * V_27 , enum V_142 V_143 ,
unsigned long V_144 )
{
struct V_1 * V_26 = F_29 ( V_27 ) ;
unsigned long V_18 ;
if ( V_143 != V_145 )
return - V_146 ;
if ( ! V_27 )
return - V_104 ;
F_14 ( & V_26 -> V_80 , V_18 ) ;
F_23 ( V_26 ) ;
if ( ! F_31 ( & V_26 -> V_81 ) ) {
struct V_69 * V_70 = F_73 ( V_26 -> V_81 . V_147 ,
struct V_69 , V_85 ) ;
V_70 -> V_148 = ( V_70 -> V_45 . V_50 - F_5 ( V_26 , V_52 ) ) <<
V_26 -> V_51 ;
}
F_15 ( & V_26 -> V_80 , V_18 ) ;
F_52 ( V_26 , true ) ;
return 0 ;
}
static T_5 F_74 ( struct V_1 * V_26 , bool V_149 )
{
struct V_69 * V_70 , * V_114 ;
bool V_150 = false ;
T_4 V_78 = 0 ;
T_5 V_77 = NULL ;
void * V_75 = NULL ;
unsigned long V_18 ;
F_14 ( & V_26 -> V_80 , V_18 ) ;
F_32 (desc, _desc, &sh_chan->ld_queue, node) {
struct V_67 * V_68 = & V_70 -> V_84 ;
F_41 ( V_68 -> V_78 > 0 && V_68 -> V_78 != V_70 -> V_78 ) ;
F_41 ( V_70 -> V_82 != V_87 &&
V_70 -> V_82 != V_151 &&
V_70 -> V_82 != V_152 ) ;
if ( ! V_149 && V_70 -> V_82 == V_87 &&
V_70 -> V_78 != V_78 )
break;
if ( V_68 -> V_78 > 0 )
V_78 = V_68 -> V_78 ;
if ( V_70 -> V_82 == V_151 && V_70 -> V_133 == 1 ) {
if ( V_26 -> V_153 != V_70 -> V_78 - 1 )
F_34 ( V_26 -> V_30 ,
L_9 ,
V_70 -> V_78 ,
V_26 -> V_153 + 1 ) ;
V_26 -> V_153 = V_70 -> V_78 ;
}
if ( V_70 -> V_82 == V_151 && V_68 -> V_77 ) {
V_70 -> V_82 = V_152 ;
V_77 = V_68 -> V_77 ;
V_75 = V_68 -> V_88 ;
F_34 ( V_26 -> V_30 , L_10 ,
V_68 -> V_78 , V_68 , V_26 -> V_9 ) ;
F_41 ( V_70 -> V_133 != 1 ) ;
break;
}
if ( V_68 -> V_78 > 0 || V_68 -> V_78 == - V_60 ) {
if ( V_70 -> V_82 == V_151 ) {
F_41 ( V_68 -> V_78 < 0 ) ;
V_70 -> V_82 = V_152 ;
}
V_150 = F_75 ( V_68 ) ;
} else {
switch ( V_70 -> V_82 ) {
case V_151 :
V_70 -> V_82 = V_152 ;
case V_152 :
if ( V_150 )
F_76 ( & V_70 -> V_84 ) ;
}
}
F_34 ( V_26 -> V_30 , L_11 ,
V_68 , V_68 -> V_78 ) ;
if ( ( ( V_70 -> V_82 == V_151 ||
V_70 -> V_82 == V_152 ) &&
F_75 ( & V_70 -> V_84 ) ) || V_149 ) {
V_70 -> V_82 = V_83 ;
F_77 ( & V_70 -> V_85 , & V_26 -> V_86 ) ;
if ( F_31 ( & V_26 -> V_81 ) ) {
F_34 ( V_26 -> V_30 , L_12 , V_26 -> V_9 ) ;
F_78 ( V_26 -> V_30 ) ;
}
}
}
if ( V_149 && ! V_77 )
V_26 -> V_153 = V_26 -> V_29 . V_78 ;
F_15 ( & V_26 -> V_80 , V_18 ) ;
if ( V_77 )
V_77 ( V_75 ) ;
return V_77 ;
}
static void F_52 ( struct V_1 * V_26 , bool V_149 )
{
while ( F_74 ( V_26 , V_149 ) )
;
}
static void F_38 ( struct V_1 * V_26 )
{
struct V_69 * V_70 ;
if ( F_18 ( V_26 ) )
return;
F_40 (desc, &sh_chan->ld_queue, node)
if ( V_70 -> V_82 == V_87 ) {
F_34 ( V_26 -> V_30 , L_13 ,
V_70 -> V_84 . V_78 , V_26 -> V_9 ,
V_70 -> V_45 . V_50 , V_70 -> V_45 . V_46 , V_70 -> V_45 . V_48 ) ;
F_21 ( V_26 , & V_70 -> V_45 ) ;
F_22 ( V_26 ) ;
break;
}
}
static void F_79 ( struct V_102 * V_27 )
{
struct V_1 * V_26 = F_29 ( V_27 ) ;
F_30 ( & V_26 -> V_80 ) ;
if ( V_26 -> V_89 == V_91 )
F_38 ( V_26 ) ;
else
V_26 -> V_89 = V_96 ;
F_36 ( & V_26 -> V_80 ) ;
}
static enum V_154 F_80 ( struct V_102 * V_27 ,
T_4 V_78 ,
struct V_155 * V_156 )
{
struct V_1 * V_26 = F_29 ( V_27 ) ;
T_4 V_157 ;
T_4 V_158 ;
enum V_154 V_159 ;
unsigned long V_18 ;
F_52 ( V_26 , false ) ;
V_158 = V_26 -> V_153 ;
F_81 () ;
V_157 = V_27 -> V_78 ;
F_41 ( V_158 < 0 ) ;
F_82 ( V_156 , V_158 , V_157 , 0 ) ;
F_14 ( & V_26 -> V_80 , V_18 ) ;
V_159 = F_83 ( V_78 , V_158 , V_157 ) ;
if ( V_159 != V_160 ) {
struct V_69 * V_70 ;
V_159 = V_161 ;
F_40 (desc, &sh_chan->ld_queue, node)
if ( V_70 -> V_78 == V_78 ) {
V_159 = V_162 ;
break;
}
}
F_15 ( & V_26 -> V_80 , V_18 ) ;
return V_159 ;
}
static T_8 F_84 ( int V_163 , void * V_3 )
{
T_8 V_103 = V_164 ;
struct V_1 * V_26 = V_3 ;
T_1 V_32 ;
F_85 ( & V_26 -> V_80 ) ;
V_32 = F_12 ( V_26 ) ;
if ( V_32 & V_34 ) {
F_23 ( V_26 ) ;
V_103 = V_165 ;
F_86 ( & V_26 -> V_166 ) ;
}
F_87 ( & V_26 -> V_80 ) ;
return V_103 ;
}
static bool F_88 ( struct V_4 * V_5 )
{
unsigned int V_167 = 0 ;
int V_24 ;
F_13 ( V_5 ) ;
for ( V_24 = 0 ; V_24 < V_168 ; V_24 ++ ) {
struct V_1 * V_26 = V_5 -> V_27 [ V_24 ] ;
struct V_69 * V_70 ;
F_51 ( V_169 ) ;
if ( ! V_26 )
continue;
F_85 ( & V_26 -> V_80 ) ;
F_23 ( V_26 ) ;
F_53 ( & V_26 -> V_81 , & V_169 ) ;
if ( ! F_31 ( & V_169 ) ) {
F_34 ( V_26 -> V_30 , L_12 , V_26 -> V_9 ) ;
F_78 ( V_26 -> V_30 ) ;
}
V_26 -> V_89 = V_91 ;
F_87 ( & V_26 -> V_80 ) ;
F_40 (desc, &dl, node) {
struct V_67 * V_68 = & V_70 -> V_84 ;
V_70 -> V_82 = V_83 ;
if ( V_68 -> V_77 )
V_68 -> V_77 ( V_68 -> V_88 ) ;
}
F_85 ( & V_26 -> V_80 ) ;
F_64 ( & V_169 , & V_26 -> V_86 ) ;
F_87 ( & V_26 -> V_80 ) ;
V_167 ++ ;
}
F_16 ( V_5 ) ;
return ! ! V_167 ;
}
static T_8 F_89 ( int V_163 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( ! ( F_7 ( V_5 ) & V_21 ) )
return V_164 ;
F_88 ( V_3 ) ;
return V_165 ;
}
static void F_90 ( unsigned long V_3 )
{
struct V_1 * V_26 = (struct V_1 * ) V_3 ;
struct V_69 * V_70 ;
T_1 V_170 = F_5 ( V_26 , V_47 ) ;
T_1 V_171 = F_5 ( V_26 , V_49 ) ;
F_30 ( & V_26 -> V_80 ) ;
F_40 (desc, &sh_chan->ld_queue, node) {
if ( V_70 -> V_82 == V_87 &&
( ( V_70 -> V_121 == V_127 &&
( V_70 -> V_45 . V_48 + V_70 -> V_45 . V_50 ) == V_171 ) ||
( V_70 -> V_45 . V_46 + V_70 -> V_45 . V_50 ) == V_170 ) ) {
F_34 ( V_26 -> V_30 , L_14 ,
V_70 -> V_84 . V_78 , & V_70 -> V_84 ,
V_70 -> V_45 . V_48 ) ;
V_70 -> V_82 = V_151 ;
break;
}
}
F_38 ( V_26 ) ;
F_36 ( & V_26 -> V_80 ) ;
F_52 ( V_26 , false ) ;
}
static bool F_91 ( struct V_4 * V_5 )
{
if ( ( F_7 ( V_5 ) & V_20 ) == 0 )
return false ;
return F_88 ( V_5 ) ;
}
static int F_92 ( struct V_172 * V_173 ,
unsigned long V_143 , void * V_3 )
{
struct V_4 * V_5 ;
int V_103 = V_174 ;
bool V_175 ;
if ( ! F_93 () )
return V_174 ;
F_94 () ;
F_95 (shdev, &sh_dmae_devices, node) {
V_175 = F_91 ( V_5 ) ;
if ( V_175 == true )
V_103 = V_176 ;
}
F_96 () ;
return V_103 ;
}
static int T_9 F_97 ( struct V_4 * V_5 , int V_9 ,
int V_163 , unsigned long V_18 )
{
int V_177 ;
const struct V_61 * V_62 = & V_5 -> V_7 -> V_8 [ V_9 ] ;
struct V_178 * V_179 = F_98 ( V_5 -> V_29 . V_30 ) ;
struct V_1 * V_180 ;
V_180 = F_46 ( sizeof( struct V_1 ) , V_110 ) ;
if ( ! V_180 ) {
F_56 ( V_5 -> V_29 . V_30 ,
L_15 ) ;
return - V_112 ;
}
V_180 -> V_89 = V_91 ;
V_180 -> V_29 . V_181 = & V_5 -> V_29 ;
V_180 -> V_30 = V_5 -> V_29 . V_30 ;
V_180 -> V_9 = V_9 ;
V_180 -> V_163 = V_163 ;
V_180 -> V_12 = V_5 -> V_6 + V_62 -> V_182 / sizeof( T_1 ) ;
F_99 ( & V_180 -> V_166 , F_90 ,
( unsigned long ) V_180 ) ;
F_100 ( & V_180 -> V_80 ) ;
F_101 ( & V_180 -> V_81 ) ;
F_101 ( & V_180 -> V_86 ) ;
F_62 ( & V_180 -> V_29 . V_183 ,
& V_5 -> V_29 . V_184 ) ;
V_5 -> V_29 . V_185 ++ ;
if ( V_179 -> V_9 >= 0 )
snprintf ( V_180 -> V_186 , sizeof( V_180 -> V_186 ) ,
L_16 , V_179 -> V_9 , V_180 -> V_9 ) ;
else
snprintf ( V_180 -> V_186 , sizeof( V_180 -> V_186 ) ,
L_17 , V_180 -> V_9 ) ;
V_177 = F_102 ( V_163 , & F_84 , V_18 ,
V_180 -> V_186 , V_180 ) ;
if ( V_177 ) {
F_56 ( V_5 -> V_29 . V_30 , L_18
L_19 , V_9 , V_177 ) ;
goto V_187;
}
V_5 -> V_27 [ V_9 ] = V_180 ;
return 0 ;
V_187:
F_42 ( & V_180 -> V_29 . V_183 ) ;
F_54 ( V_180 ) ;
return V_177 ;
}
static void F_103 ( struct V_4 * V_5 )
{
int V_24 ;
for ( V_24 = V_5 -> V_29 . V_185 - 1 ; V_24 >= 0 ; V_24 -- ) {
if ( V_5 -> V_27 [ V_24 ] ) {
struct V_1 * V_26 = V_5 -> V_27 [ V_24 ] ;
F_104 ( V_26 -> V_163 , V_26 ) ;
F_42 ( & V_26 -> V_29 . V_183 ) ;
F_54 ( V_26 ) ;
V_5 -> V_27 [ V_24 ] = NULL ;
}
}
V_5 -> V_29 . V_185 = 0 ;
}
static int T_10 F_105 ( struct V_178 * V_179 )
{
struct V_35 * V_7 = V_179 -> V_30 . V_188 ;
unsigned long V_189 = V_190 ,
V_191 [ V_168 ] = {} ;
int V_192 , V_193 [ V_168 ] ;
int V_177 , V_24 , V_194 = 0 , V_195 = 0 , V_196 = 0 ;
struct V_4 * V_5 ;
struct V_197 * V_27 , * V_63 , * V_198 , * V_199 ;
if ( ! V_7 || ! V_7 -> V_25 )
return - V_200 ;
V_27 = F_106 ( V_179 , V_201 , 0 ) ;
V_63 = F_106 ( V_179 , V_201 , 1 ) ;
V_198 = F_106 ( V_179 , V_202 , 0 ) ;
if ( ! V_27 || ! V_198 )
return - V_200 ;
if ( ! F_107 ( V_27 -> V_203 , F_108 ( V_27 ) , V_179 -> V_204 ) ) {
F_56 ( & V_179 -> V_30 , L_20 ) ;
return - V_60 ;
}
if ( V_63 && ! F_107 ( V_63 -> V_203 , F_108 ( V_63 ) , V_179 -> V_204 ) ) {
F_56 ( & V_179 -> V_30 , L_21 ) ;
V_177 = - V_60 ;
goto V_205;
}
V_177 = - V_112 ;
V_5 = F_46 ( sizeof( struct V_4 ) , V_110 ) ;
if ( ! V_5 ) {
F_56 ( & V_179 -> V_30 , L_22 ) ;
goto V_206;
}
V_5 -> V_6 = F_109 ( V_27 -> V_203 , F_108 ( V_27 ) ) ;
if ( ! V_5 -> V_6 )
goto V_207;
if ( V_63 ) {
V_5 -> V_63 = F_109 ( V_63 -> V_203 , F_108 ( V_63 ) ) ;
if ( ! V_5 -> V_63 )
goto V_208;
}
V_5 -> V_7 = V_7 ;
if ( V_7 -> V_16 )
V_5 -> V_16 = V_7 -> V_16 ;
else
V_5 -> V_16 = V_209 ;
if ( V_7 -> V_55 )
V_5 -> V_55 = V_7 -> V_55 ;
else
V_5 -> V_55 = V_210 ;
F_110 ( V_179 , V_5 ) ;
V_5 -> V_29 . V_30 = & V_179 -> V_30 ;
F_111 ( & V_179 -> V_30 ) ;
F_112 ( & V_179 -> V_30 ) ;
F_30 ( & V_19 ) ;
F_113 ( & V_5 -> V_85 , & V_211 ) ;
F_36 ( & V_19 ) ;
V_177 = F_16 ( V_5 ) ;
if ( V_177 )
goto V_212;
F_101 ( & V_5 -> V_29 . V_184 ) ;
if ( ! V_7 -> V_213 )
F_114 ( V_214 , V_5 -> V_29 . V_215 ) ;
if ( V_7 -> V_101 && V_7 -> V_100 )
F_114 ( V_216 , V_5 -> V_29 . V_215 ) ;
V_5 -> V_29 . V_217
= F_44 ;
V_5 -> V_29 . V_218 = F_50 ;
V_5 -> V_29 . V_219 = F_65 ;
V_5 -> V_29 . V_220 = F_80 ;
V_5 -> V_29 . V_221 = F_79 ;
V_5 -> V_29 . V_222 = F_71 ;
V_5 -> V_29 . V_223 = F_72 ;
V_5 -> V_29 . V_224 = V_58 ;
#if F_115 ( V_225 ) || F_115 ( V_226 )
V_199 = F_106 ( V_179 , V_202 , 1 ) ;
if ( ! V_199 )
V_199 = V_198 ;
else
V_195 ++ ;
if ( V_199 == V_198 ||
( V_198 -> V_18 & V_227 ) == V_228 )
V_189 = V_229 ;
V_192 = V_198 -> V_203 ;
V_177 = F_102 ( V_192 , F_89 , V_189 ,
L_23 , V_5 ) ;
if ( V_177 ) {
F_56 ( & V_179 -> V_30 ,
L_24 ,
V_192 , V_177 ) ;
goto V_230;
}
#else
V_199 = V_198 ;
#endif
if ( V_199 -> V_203 == V_199 -> V_231 &&
! F_106 ( V_179 , V_202 , 1 ) ) {
for (; V_194 < V_7 -> V_25 ; V_194 ++ ) {
if ( V_194 < V_168 ) {
V_193 [ V_194 ] = V_199 -> V_203 ;
V_191 [ V_194 ] = V_229 ;
} else {
V_196 = 1 ;
break;
}
}
} else {
do {
for ( V_24 = V_199 -> V_203 ; V_24 <= V_199 -> V_231 ; V_24 ++ ) {
if ( V_194 >= V_168 ) {
V_196 = 1 ;
break;
}
if ( ( V_198 -> V_18 & V_227 ) ==
V_228 )
V_191 [ V_194 ] = V_229 ;
else
V_191 [ V_194 ] = V_190 ;
F_34 ( & V_179 -> V_30 ,
L_25 ,
V_24 , V_194 ) ;
V_193 [ V_194 ++ ] = V_24 ;
}
if ( V_194 >= V_168 )
break;
V_199 = F_106 ( V_179 ,
V_202 , ++ V_195 ) ;
} while ( V_194 < V_7 -> V_25 && V_199 );
}
for ( V_24 = 0 ; V_24 < V_194 ; V_24 ++ ) {
V_177 = F_97 ( V_5 , V_24 , V_193 [ V_24 ] , V_191 [ V_24 ] ) ;
if ( V_177 )
goto V_232;
}
if ( V_196 )
F_116 ( & V_179 -> V_30 , L_26
L_27 ,
V_7 -> V_25 , V_168 ) ;
F_78 ( & V_179 -> V_30 ) ;
F_117 ( & V_5 -> V_29 ) ;
return V_177 ;
V_232:
F_103 ( V_5 ) ;
#if F_115 ( V_225 ) || F_115 ( V_226 )
F_104 ( V_192 , V_5 ) ;
V_230:
#endif
V_212:
F_30 ( & V_19 ) ;
F_118 ( & V_5 -> V_85 ) ;
F_36 ( & V_19 ) ;
F_78 ( & V_179 -> V_30 ) ;
F_119 ( & V_179 -> V_30 ) ;
if ( V_63 )
F_120 ( V_5 -> V_63 ) ;
F_110 ( V_179 , NULL ) ;
V_208:
F_120 ( V_5 -> V_6 ) ;
F_121 () ;
V_207:
F_54 ( V_5 ) ;
V_206:
if ( V_63 )
F_122 ( V_63 -> V_203 , F_108 ( V_63 ) ) ;
V_205:
F_122 ( V_27 -> V_203 , F_108 ( V_27 ) ) ;
return V_177 ;
}
static int T_11 F_123 ( struct V_178 * V_179 )
{
struct V_4 * V_5 = F_124 ( V_179 ) ;
struct V_197 * V_233 ;
int V_192 = F_125 ( V_179 , 0 ) ;
F_126 ( & V_5 -> V_29 ) ;
if ( V_192 > 0 )
F_104 ( V_192 , V_5 ) ;
F_30 ( & V_19 ) ;
F_118 ( & V_5 -> V_85 ) ;
F_36 ( & V_19 ) ;
F_103 ( V_5 ) ;
F_119 ( & V_179 -> V_30 ) ;
if ( V_5 -> V_63 )
F_120 ( V_5 -> V_63 ) ;
F_120 ( V_5 -> V_6 ) ;
F_110 ( V_179 , NULL ) ;
F_121 () ;
F_54 ( V_5 ) ;
V_233 = F_106 ( V_179 , V_201 , 0 ) ;
if ( V_233 )
F_122 ( V_233 -> V_203 , F_108 ( V_233 ) ) ;
V_233 = F_106 ( V_179 , V_201 , 1 ) ;
if ( V_233 )
F_122 ( V_233 -> V_203 , F_108 ( V_233 ) ) ;
return 0 ;
}
static void F_127 ( struct V_178 * V_179 )
{
struct V_4 * V_5 = F_124 ( V_179 ) ;
F_13 ( V_5 ) ;
}
static int F_128 ( struct V_181 * V_30 )
{
return 0 ;
}
static int F_129 ( struct V_181 * V_30 )
{
struct V_4 * V_5 = F_130 ( V_30 ) ;
return F_16 ( V_5 ) ;
}
static int F_131 ( struct V_181 * V_30 )
{
return 0 ;
}
static int F_132 ( struct V_181 * V_30 )
{
struct V_4 * V_5 = F_130 ( V_30 ) ;
int V_24 , V_103 ;
V_103 = F_16 ( V_5 ) ;
if ( V_103 < 0 )
F_56 ( V_30 , L_28 ) ;
for ( V_24 = 0 ; V_24 < V_5 -> V_7 -> V_25 ; V_24 ++ ) {
struct V_1 * V_26 = V_5 -> V_27 [ V_24 ] ;
struct V_74 * V_75 = V_26 -> V_29 . V_76 ;
if ( ! V_26 -> V_108 )
continue;
if ( V_75 ) {
const struct V_92 * V_93 = V_75 -> V_94 ;
F_26 ( V_26 , V_93 -> V_95 ) ;
F_25 ( V_26 , V_93 -> V_32 ) ;
} else {
F_24 ( V_26 ) ;
}
}
return 0 ;
}
static int T_10 F_133 ( void )
{
int V_177 = F_134 ( & V_234 ) ;
if ( V_177 )
return V_177 ;
return F_135 ( & V_235 , F_105 ) ;
}
static void T_11 F_136 ( void )
{
F_137 ( & V_235 ) ;
F_138 ( & V_234 ) ;
}
