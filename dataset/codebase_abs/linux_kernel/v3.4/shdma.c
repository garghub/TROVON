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
V_78 = F_32 ( V_68 ) ;
F_33 (chunk, c, desc->node.prev, node) {
if ( V_71 != V_70 && ( V_71 -> V_82 == V_83 ||
V_71 -> V_84 . V_78 > 0 ||
V_71 -> V_84 . V_78 == - V_60 ||
& V_71 -> V_85 == & V_26 -> V_86 ) )
break;
V_71 -> V_82 = V_87 ;
V_71 -> V_84 . V_77 = NULL ;
V_71 -> V_78 = V_78 ;
F_34 ( & V_71 -> V_85 , & V_26 -> V_81 ) ;
V_72 = V_71 ;
}
V_72 -> V_84 . V_77 = V_77 ;
V_72 -> V_84 . V_88 = V_68 -> V_88 ;
F_35 ( V_26 -> V_30 , L_3 ,
V_68 -> V_78 , & V_72 -> V_84 , V_26 -> V_9 ,
V_70 -> V_45 . V_46 , V_70 -> V_45 . V_50 , V_70 -> V_45 . V_48 ) ;
if ( V_79 ) {
V_26 -> V_89 = V_90 ;
F_36 ( V_26 -> V_30 ) ;
F_37 ( & V_26 -> V_80 ) ;
F_38 ( V_26 -> V_30 ) ;
F_30 ( & V_26 -> V_80 ) ;
if ( V_26 -> V_89 != V_91 ) {
F_35 ( V_26 -> V_30 , L_4 ,
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
F_39 ( V_26 ) ;
V_26 -> V_89 = V_91 ;
}
} else {
V_26 -> V_89 = V_96 ;
}
F_37 ( & V_26 -> V_80 ) ;
return V_78 ;
}
static struct V_69 * F_40 ( struct V_1 * V_26 )
{
struct V_69 * V_70 ;
F_41 (desc, &sh_chan->ld_free, node)
if ( V_70 -> V_82 != V_97 ) {
F_42 ( V_70 -> V_82 != V_83 ) ;
F_43 ( & V_70 -> V_85 ) ;
return V_70 ;
}
return NULL ;
}
static const struct V_92 * F_44 (
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
static int F_45 ( struct V_102 * V_27 )
{
struct V_1 * V_26 = F_29 ( V_27 ) ;
struct V_69 * V_70 ;
struct V_74 * V_75 = V_27 -> V_76 ;
int V_103 ;
if ( V_75 ) {
const struct V_92 * V_93 ;
V_93 = F_44 ( V_26 , V_75 ) ;
if ( ! V_93 ) {
V_103 = - V_104 ;
goto V_105;
}
if ( F_46 ( V_75 -> V_98 , V_106 ) ) {
V_103 = - V_60 ;
goto V_107;
}
V_75 -> V_94 = V_93 ;
}
while ( V_26 -> V_108 < V_109 ) {
V_70 = F_47 ( sizeof( struct V_69 ) , V_110 ) ;
if ( ! V_70 )
break;
F_48 ( & V_70 -> V_84 ,
& V_26 -> V_29 ) ;
V_70 -> V_84 . V_111 = F_27 ;
V_70 -> V_82 = V_83 ;
F_49 ( & V_70 -> V_85 , & V_26 -> V_86 ) ;
V_26 -> V_108 ++ ;
}
if ( ! V_26 -> V_108 ) {
V_103 = - V_112 ;
goto V_113;
}
return V_26 -> V_108 ;
V_113:
if ( V_75 )
F_50 ( V_75 -> V_98 , V_106 ) ;
V_107:
V_105:
V_27 -> V_76 = NULL ;
return V_103 ;
}
static void F_51 ( struct V_102 * V_27 )
{
struct V_1 * V_26 = F_29 ( V_27 ) ;
struct V_69 * V_70 , * V_114 ;
F_52 ( V_115 ) ;
F_30 ( & V_26 -> V_80 ) ;
F_23 ( V_26 ) ;
F_37 ( & V_26 -> V_80 ) ;
if ( ! F_31 ( & V_26 -> V_81 ) )
F_53 ( V_26 , true ) ;
if ( V_27 -> V_76 ) {
struct V_74 * V_75 = V_27 -> V_76 ;
F_50 ( V_75 -> V_98 , V_106 ) ;
V_27 -> V_76 = NULL ;
}
F_30 ( & V_26 -> V_80 ) ;
F_54 ( & V_26 -> V_86 , & V_115 ) ;
V_26 -> V_108 = 0 ;
F_37 ( & V_26 -> V_80 ) ;
F_33 (desc, _desc, &list, node)
F_55 ( V_70 ) ;
}
static struct V_69 * F_56 ( struct V_1 * V_26 ,
unsigned long V_18 , T_6 * V_116 , T_6 * V_117 , T_7 * V_118 ,
struct V_69 * * V_119 , enum V_120 V_121 )
{
struct V_69 * V_122 ;
T_7 V_123 ;
if ( ! * V_118 )
return NULL ;
V_122 = F_40 ( V_26 ) ;
if ( ! V_122 ) {
F_57 ( V_26 -> V_30 , L_5 ) ;
return NULL ;
}
V_123 = F_58 ( * V_118 , ( T_7 ) V_124 + 1 ) ;
V_122 -> V_45 . V_46 = * V_117 ;
V_122 -> V_45 . V_48 = * V_116 ;
V_122 -> V_45 . V_50 = V_123 ;
if ( ! * V_119 ) {
V_122 -> V_84 . V_78 = - V_60 ;
* V_119 = V_122 ;
} else {
V_122 -> V_84 . V_78 = - V_104 ;
}
F_35 ( V_26 -> V_30 ,
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
static struct V_67 * F_59 ( struct V_1 * V_26 ,
struct V_128 * V_129 , unsigned int V_130 , T_6 * V_13 ,
enum V_120 V_121 , unsigned long V_18 )
{
struct V_128 * V_131 ;
struct V_69 * V_119 = NULL , * V_122 = NULL ;
F_52 ( V_132 ) ;
int V_133 = 0 ;
unsigned long V_134 ;
int V_24 ;
if ( ! V_130 )
return NULL ;
F_60 (sgl, sg, sg_len, i)
V_133 += ( F_61 ( V_131 ) + V_124 ) /
( V_124 + 1 ) ;
F_14 ( & V_26 -> V_80 , V_134 ) ;
F_60 (sgl, sg, sg_len, i) {
T_6 V_135 = F_62 ( V_131 ) ;
T_7 V_118 = F_61 ( V_131 ) ;
if ( ! V_118 )
goto V_136;
do {
F_35 ( V_26 -> V_30 , L_7 ,
V_24 , V_131 , V_118 , ( unsigned long long ) V_135 ) ;
if ( V_121 == V_127 )
V_122 = F_56 ( V_26 , V_18 ,
& V_135 , V_13 , & V_118 , & V_119 ,
V_121 ) ;
else
V_122 = F_56 ( V_26 , V_18 ,
V_13 , & V_135 , & V_118 , & V_119 ,
V_121 ) ;
if ( ! V_122 )
goto V_136;
V_122 -> V_133 = V_133 -- ;
F_63 ( & V_122 -> V_85 , & V_132 ) ;
} while ( V_118 );
}
if ( V_122 != V_119 )
V_122 -> V_84 . V_78 = - V_137 ;
F_64 ( & V_132 , & V_26 -> V_86 ) ;
F_15 ( & V_26 -> V_80 , V_134 ) ;
return & V_119 -> V_84 ;
V_136:
F_41 (new, &tx_list, node)
V_122 -> V_82 = V_83 ;
F_65 ( & V_132 , & V_26 -> V_86 ) ;
F_15 ( & V_26 -> V_80 , V_134 ) ;
return NULL ;
}
static struct V_67 * F_66 (
struct V_102 * V_27 , T_6 V_138 , T_6 V_139 ,
T_7 V_118 , unsigned long V_18 )
{
struct V_1 * V_26 ;
struct V_128 V_131 ;
if ( ! V_27 || ! V_118 )
return NULL ;
V_26 = F_29 ( V_27 ) ;
F_67 ( & V_131 , 1 ) ;
F_68 ( & V_131 , F_69 ( F_70 ( V_139 ) ) , V_118 ,
F_71 ( V_139 ) ) ;
F_62 ( & V_131 ) = V_139 ;
F_61 ( & V_131 ) = V_118 ;
return F_59 ( V_26 , & V_131 , 1 , & V_138 , V_125 ,
V_18 ) ;
}
static struct V_67 * F_72 (
struct V_102 * V_27 , struct V_128 * V_129 , unsigned int V_130 ,
enum V_120 V_121 , unsigned long V_18 ,
void * V_140 )
{
struct V_74 * V_75 ;
struct V_1 * V_26 ;
T_6 V_141 ;
if ( ! V_27 )
return NULL ;
V_26 = F_29 ( V_27 ) ;
V_75 = V_27 -> V_76 ;
if ( ! V_75 || ! V_130 ) {
F_17 ( V_26 -> V_30 , L_8 ,
V_142 , V_75 , V_130 , V_75 ? V_75 -> V_98 : - 1 ) ;
return NULL ;
}
V_141 = V_75 -> V_94 -> V_13 ;
return F_59 ( V_26 , V_129 , V_130 , & V_141 ,
V_121 , V_18 ) ;
}
static int F_73 ( struct V_102 * V_27 , enum V_143 V_144 ,
unsigned long V_145 )
{
struct V_1 * V_26 = F_29 ( V_27 ) ;
unsigned long V_18 ;
if ( V_144 != V_146 )
return - V_147 ;
if ( ! V_27 )
return - V_104 ;
F_14 ( & V_26 -> V_80 , V_18 ) ;
F_23 ( V_26 ) ;
if ( ! F_31 ( & V_26 -> V_81 ) ) {
struct V_69 * V_70 = F_74 ( V_26 -> V_81 . V_148 ,
struct V_69 , V_85 ) ;
V_70 -> V_149 = ( V_70 -> V_45 . V_50 - F_5 ( V_26 , V_52 ) ) <<
V_26 -> V_51 ;
}
F_15 ( & V_26 -> V_80 , V_18 ) ;
F_53 ( V_26 , true ) ;
return 0 ;
}
static T_5 F_75 ( struct V_1 * V_26 , bool V_150 )
{
struct V_69 * V_70 , * V_114 ;
bool V_151 = false ;
T_4 V_78 = 0 ;
T_5 V_77 = NULL ;
void * V_75 = NULL ;
unsigned long V_18 ;
F_14 ( & V_26 -> V_80 , V_18 ) ;
F_33 (desc, _desc, &sh_chan->ld_queue, node) {
struct V_67 * V_68 = & V_70 -> V_84 ;
F_42 ( V_68 -> V_78 > 0 && V_68 -> V_78 != V_70 -> V_78 ) ;
F_42 ( V_70 -> V_82 != V_87 &&
V_70 -> V_82 != V_152 &&
V_70 -> V_82 != V_153 ) ;
if ( ! V_150 && V_70 -> V_82 == V_87 &&
V_70 -> V_78 != V_78 )
break;
if ( V_68 -> V_78 > 0 )
V_78 = V_68 -> V_78 ;
if ( V_70 -> V_82 == V_152 && V_70 -> V_133 == 1 ) {
if ( V_26 -> V_29 . V_154 != V_70 -> V_78 - 1 )
F_35 ( V_26 -> V_30 ,
L_9 ,
V_70 -> V_78 ,
V_26 -> V_29 . V_154 + 1 ) ;
V_26 -> V_29 . V_154 = V_70 -> V_78 ;
}
if ( V_70 -> V_82 == V_152 && V_68 -> V_77 ) {
V_70 -> V_82 = V_153 ;
V_77 = V_68 -> V_77 ;
V_75 = V_68 -> V_88 ;
F_35 ( V_26 -> V_30 , L_10 ,
V_68 -> V_78 , V_68 , V_26 -> V_9 ) ;
F_42 ( V_70 -> V_133 != 1 ) ;
break;
}
if ( V_68 -> V_78 > 0 || V_68 -> V_78 == - V_60 ) {
if ( V_70 -> V_82 == V_152 ) {
F_42 ( V_68 -> V_78 < 0 ) ;
V_70 -> V_82 = V_153 ;
}
V_151 = F_76 ( V_68 ) ;
} else {
switch ( V_70 -> V_82 ) {
case V_152 :
V_70 -> V_82 = V_153 ;
case V_153 :
if ( V_151 )
F_77 ( & V_70 -> V_84 ) ;
}
}
F_35 ( V_26 -> V_30 , L_11 ,
V_68 , V_68 -> V_78 ) ;
if ( ( ( V_70 -> V_82 == V_152 ||
V_70 -> V_82 == V_153 ) &&
F_76 ( & V_70 -> V_84 ) ) || V_150 ) {
V_70 -> V_82 = V_83 ;
F_78 ( & V_70 -> V_85 , & V_26 -> V_86 ) ;
if ( F_31 ( & V_26 -> V_81 ) ) {
F_35 ( V_26 -> V_30 , L_12 , V_26 -> V_9 ) ;
F_79 ( V_26 -> V_30 ) ;
}
}
}
if ( V_150 && ! V_77 )
V_26 -> V_29 . V_154 = V_26 -> V_29 . V_78 ;
F_15 ( & V_26 -> V_80 , V_18 ) ;
if ( V_77 )
V_77 ( V_75 ) ;
return V_77 ;
}
static void F_53 ( struct V_1 * V_26 , bool V_150 )
{
while ( F_75 ( V_26 , V_150 ) )
;
}
static void F_39 ( struct V_1 * V_26 )
{
struct V_69 * V_70 ;
if ( F_18 ( V_26 ) )
return;
F_41 (desc, &sh_chan->ld_queue, node)
if ( V_70 -> V_82 == V_87 ) {
F_35 ( V_26 -> V_30 , L_13 ,
V_70 -> V_84 . V_78 , V_26 -> V_9 ,
V_70 -> V_45 . V_50 , V_70 -> V_45 . V_46 , V_70 -> V_45 . V_48 ) ;
F_21 ( V_26 , & V_70 -> V_45 ) ;
F_22 ( V_26 ) ;
break;
}
}
static void F_80 ( struct V_102 * V_27 )
{
struct V_1 * V_26 = F_29 ( V_27 ) ;
F_30 ( & V_26 -> V_80 ) ;
if ( V_26 -> V_89 == V_91 )
F_39 ( V_26 ) ;
else
V_26 -> V_89 = V_96 ;
F_37 ( & V_26 -> V_80 ) ;
}
static enum V_155 F_81 ( struct V_102 * V_27 ,
T_4 V_78 ,
struct V_156 * V_157 )
{
struct V_1 * V_26 = F_29 ( V_27 ) ;
enum V_155 V_158 ;
unsigned long V_18 ;
F_53 ( V_26 , false ) ;
F_14 ( & V_26 -> V_80 , V_18 ) ;
V_158 = F_82 ( V_27 , V_78 , V_157 ) ;
if ( V_158 != V_159 ) {
struct V_69 * V_70 ;
V_158 = V_160 ;
F_41 (desc, &sh_chan->ld_queue, node)
if ( V_70 -> V_78 == V_78 ) {
V_158 = V_161 ;
break;
}
}
F_15 ( & V_26 -> V_80 , V_18 ) ;
return V_158 ;
}
static T_8 F_83 ( int V_162 , void * V_3 )
{
T_8 V_103 = V_163 ;
struct V_1 * V_26 = V_3 ;
T_1 V_32 ;
F_84 ( & V_26 -> V_80 ) ;
V_32 = F_12 ( V_26 ) ;
if ( V_32 & V_34 ) {
F_23 ( V_26 ) ;
V_103 = V_164 ;
F_85 ( & V_26 -> V_165 ) ;
}
F_86 ( & V_26 -> V_80 ) ;
return V_103 ;
}
static bool F_87 ( struct V_4 * V_5 )
{
unsigned int V_166 = 0 ;
int V_24 ;
F_13 ( V_5 ) ;
for ( V_24 = 0 ; V_24 < V_167 ; V_24 ++ ) {
struct V_1 * V_26 = V_5 -> V_27 [ V_24 ] ;
struct V_69 * V_70 ;
F_52 ( V_168 ) ;
if ( ! V_26 )
continue;
F_84 ( & V_26 -> V_80 ) ;
F_23 ( V_26 ) ;
F_54 ( & V_26 -> V_81 , & V_168 ) ;
if ( ! F_31 ( & V_168 ) ) {
F_35 ( V_26 -> V_30 , L_12 , V_26 -> V_9 ) ;
F_79 ( V_26 -> V_30 ) ;
}
V_26 -> V_89 = V_91 ;
F_86 ( & V_26 -> V_80 ) ;
F_41 (desc, &dl, node) {
struct V_67 * V_68 = & V_70 -> V_84 ;
V_70 -> V_82 = V_83 ;
if ( V_68 -> V_77 )
V_68 -> V_77 ( V_68 -> V_88 ) ;
}
F_84 ( & V_26 -> V_80 ) ;
F_65 ( & V_168 , & V_26 -> V_86 ) ;
F_86 ( & V_26 -> V_80 ) ;
V_166 ++ ;
}
F_16 ( V_5 ) ;
return ! ! V_166 ;
}
static T_8 F_88 ( int V_162 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( ! ( F_7 ( V_5 ) & V_21 ) )
return V_163 ;
F_87 ( V_3 ) ;
return V_164 ;
}
static void F_89 ( unsigned long V_3 )
{
struct V_1 * V_26 = (struct V_1 * ) V_3 ;
struct V_69 * V_70 ;
T_1 V_169 = F_5 ( V_26 , V_47 ) ;
T_1 V_170 = F_5 ( V_26 , V_49 ) ;
F_30 ( & V_26 -> V_80 ) ;
F_41 (desc, &sh_chan->ld_queue, node) {
if ( V_70 -> V_82 == V_87 &&
( ( V_70 -> V_121 == V_127 &&
( V_70 -> V_45 . V_48 + V_70 -> V_45 . V_50 ) == V_170 ) ||
( V_70 -> V_45 . V_46 + V_70 -> V_45 . V_50 ) == V_169 ) ) {
F_35 ( V_26 -> V_30 , L_14 ,
V_70 -> V_84 . V_78 , & V_70 -> V_84 ,
V_70 -> V_45 . V_48 ) ;
V_70 -> V_82 = V_152 ;
break;
}
}
F_39 ( V_26 ) ;
F_37 ( & V_26 -> V_80 ) ;
F_53 ( V_26 , false ) ;
}
static bool F_90 ( struct V_4 * V_5 )
{
if ( ( F_7 ( V_5 ) & V_20 ) == 0 )
return false ;
return F_87 ( V_5 ) ;
}
static int F_91 ( struct V_171 * V_172 ,
unsigned long V_144 , void * V_3 )
{
struct V_4 * V_5 ;
int V_103 = V_173 ;
bool V_174 ;
if ( ! F_92 () )
return V_173 ;
F_93 () ;
F_94 (shdev, &sh_dmae_devices, node) {
V_174 = F_90 ( V_5 ) ;
if ( V_174 == true )
V_103 = V_175 ;
}
F_95 () ;
return V_103 ;
}
static int T_9 F_96 ( struct V_4 * V_5 , int V_9 ,
int V_162 , unsigned long V_18 )
{
int V_176 ;
const struct V_61 * V_62 = & V_5 -> V_7 -> V_8 [ V_9 ] ;
struct V_177 * V_178 = F_97 ( V_5 -> V_29 . V_30 ) ;
struct V_1 * V_179 ;
V_179 = F_47 ( sizeof( struct V_1 ) , V_110 ) ;
if ( ! V_179 ) {
F_57 ( V_5 -> V_29 . V_30 ,
L_15 ) ;
return - V_112 ;
}
V_179 -> V_89 = V_91 ;
V_179 -> V_29 . V_180 = & V_5 -> V_29 ;
F_98 ( & V_179 -> V_29 ) ;
V_179 -> V_30 = V_5 -> V_29 . V_30 ;
V_179 -> V_9 = V_9 ;
V_179 -> V_162 = V_162 ;
V_179 -> V_12 = V_5 -> V_6 + V_62 -> V_181 / sizeof( T_1 ) ;
F_99 ( & V_179 -> V_165 , F_89 ,
( unsigned long ) V_179 ) ;
F_100 ( & V_179 -> V_80 ) ;
F_101 ( & V_179 -> V_81 ) ;
F_101 ( & V_179 -> V_86 ) ;
F_63 ( & V_179 -> V_29 . V_182 ,
& V_5 -> V_29 . V_183 ) ;
V_5 -> V_29 . V_184 ++ ;
if ( V_178 -> V_9 >= 0 )
snprintf ( V_179 -> V_185 , sizeof( V_179 -> V_185 ) ,
L_16 , V_178 -> V_9 , V_179 -> V_9 ) ;
else
snprintf ( V_179 -> V_185 , sizeof( V_179 -> V_185 ) ,
L_17 , V_179 -> V_9 ) ;
V_176 = F_102 ( V_162 , & F_83 , V_18 ,
V_179 -> V_185 , V_179 ) ;
if ( V_176 ) {
F_57 ( V_5 -> V_29 . V_30 , L_18
L_19 , V_9 , V_176 ) ;
goto V_186;
}
V_5 -> V_27 [ V_9 ] = V_179 ;
return 0 ;
V_186:
F_43 ( & V_179 -> V_29 . V_182 ) ;
F_55 ( V_179 ) ;
return V_176 ;
}
static void F_103 ( struct V_4 * V_5 )
{
int V_24 ;
for ( V_24 = V_5 -> V_29 . V_184 - 1 ; V_24 >= 0 ; V_24 -- ) {
if ( V_5 -> V_27 [ V_24 ] ) {
struct V_1 * V_26 = V_5 -> V_27 [ V_24 ] ;
F_104 ( V_26 -> V_162 , V_26 ) ;
F_43 ( & V_26 -> V_29 . V_182 ) ;
F_55 ( V_26 ) ;
V_5 -> V_27 [ V_24 ] = NULL ;
}
}
V_5 -> V_29 . V_184 = 0 ;
}
static int T_10 F_105 ( struct V_177 * V_178 )
{
struct V_35 * V_7 = V_178 -> V_30 . V_187 ;
unsigned long V_188 = V_189 ,
V_190 [ V_167 ] = {} ;
int V_191 , V_192 [ V_167 ] ;
int V_176 , V_24 , V_193 = 0 , V_194 = 0 , V_195 = 0 ;
struct V_4 * V_5 ;
struct V_196 * V_27 , * V_63 , * V_197 , * V_198 ;
if ( ! V_7 || ! V_7 -> V_25 )
return - V_199 ;
V_27 = F_106 ( V_178 , V_200 , 0 ) ;
V_63 = F_106 ( V_178 , V_200 , 1 ) ;
V_197 = F_106 ( V_178 , V_201 , 0 ) ;
if ( ! V_27 || ! V_197 )
return - V_199 ;
if ( ! F_107 ( V_27 -> V_202 , F_108 ( V_27 ) , V_178 -> V_203 ) ) {
F_57 ( & V_178 -> V_30 , L_20 ) ;
return - V_60 ;
}
if ( V_63 && ! F_107 ( V_63 -> V_202 , F_108 ( V_63 ) , V_178 -> V_203 ) ) {
F_57 ( & V_178 -> V_30 , L_21 ) ;
V_176 = - V_60 ;
goto V_204;
}
V_176 = - V_112 ;
V_5 = F_47 ( sizeof( struct V_4 ) , V_110 ) ;
if ( ! V_5 ) {
F_57 ( & V_178 -> V_30 , L_22 ) ;
goto V_205;
}
V_5 -> V_6 = F_109 ( V_27 -> V_202 , F_108 ( V_27 ) ) ;
if ( ! V_5 -> V_6 )
goto V_206;
if ( V_63 ) {
V_5 -> V_63 = F_109 ( V_63 -> V_202 , F_108 ( V_63 ) ) ;
if ( ! V_5 -> V_63 )
goto V_207;
}
V_5 -> V_7 = V_7 ;
if ( V_7 -> V_16 )
V_5 -> V_16 = V_7 -> V_16 ;
else
V_5 -> V_16 = V_208 ;
if ( V_7 -> V_55 )
V_5 -> V_55 = V_7 -> V_55 ;
else
V_5 -> V_55 = V_209 ;
F_110 ( V_178 , V_5 ) ;
V_5 -> V_29 . V_30 = & V_178 -> V_30 ;
F_111 ( & V_178 -> V_30 ) ;
F_112 ( & V_178 -> V_30 ) ;
F_30 ( & V_19 ) ;
F_113 ( & V_5 -> V_85 , & V_210 ) ;
F_37 ( & V_19 ) ;
V_176 = F_16 ( V_5 ) ;
if ( V_176 )
goto V_211;
F_101 ( & V_5 -> V_29 . V_183 ) ;
if ( ! V_7 -> V_212 )
F_114 ( V_213 , V_5 -> V_29 . V_214 ) ;
if ( V_7 -> V_101 && V_7 -> V_100 )
F_114 ( V_215 , V_5 -> V_29 . V_214 ) ;
V_5 -> V_29 . V_216
= F_45 ;
V_5 -> V_29 . V_217 = F_51 ;
V_5 -> V_29 . V_218 = F_66 ;
V_5 -> V_29 . V_219 = F_81 ;
V_5 -> V_29 . V_220 = F_80 ;
V_5 -> V_29 . V_221 = F_72 ;
V_5 -> V_29 . V_222 = F_73 ;
V_5 -> V_29 . V_223 = V_58 ;
#if F_115 ( V_224 ) || F_115 ( V_225 )
V_198 = F_106 ( V_178 , V_201 , 1 ) ;
if ( ! V_198 )
V_198 = V_197 ;
else
V_194 ++ ;
if ( V_198 == V_197 ||
( V_197 -> V_18 & V_226 ) == V_227 )
V_188 = V_228 ;
V_191 = V_197 -> V_202 ;
V_176 = F_102 ( V_191 , F_88 , V_188 ,
L_23 , V_5 ) ;
if ( V_176 ) {
F_57 ( & V_178 -> V_30 ,
L_24 ,
V_191 , V_176 ) ;
goto V_229;
}
#else
V_198 = V_197 ;
#endif
if ( V_198 -> V_202 == V_198 -> V_230 &&
! F_106 ( V_178 , V_201 , 1 ) ) {
for (; V_193 < V_7 -> V_25 ; V_193 ++ ) {
if ( V_193 < V_167 ) {
V_192 [ V_193 ] = V_198 -> V_202 ;
V_190 [ V_193 ] = V_228 ;
} else {
V_195 = 1 ;
break;
}
}
} else {
do {
for ( V_24 = V_198 -> V_202 ; V_24 <= V_198 -> V_230 ; V_24 ++ ) {
if ( V_193 >= V_167 ) {
V_195 = 1 ;
break;
}
if ( ( V_197 -> V_18 & V_226 ) ==
V_227 )
V_190 [ V_193 ] = V_228 ;
else
V_190 [ V_193 ] = V_189 ;
F_35 ( & V_178 -> V_30 ,
L_25 ,
V_24 , V_193 ) ;
V_192 [ V_193 ++ ] = V_24 ;
}
if ( V_193 >= V_167 )
break;
V_198 = F_106 ( V_178 ,
V_201 , ++ V_194 ) ;
} while ( V_193 < V_7 -> V_25 && V_198 );
}
for ( V_24 = 0 ; V_24 < V_193 ; V_24 ++ ) {
V_176 = F_96 ( V_5 , V_24 , V_192 [ V_24 ] , V_190 [ V_24 ] ) ;
if ( V_176 )
goto V_231;
}
if ( V_195 )
F_116 ( & V_178 -> V_30 , L_26
L_27 ,
V_7 -> V_25 , V_167 ) ;
F_79 ( & V_178 -> V_30 ) ;
F_117 ( & V_5 -> V_29 ) ;
return V_176 ;
V_231:
F_103 ( V_5 ) ;
#if F_115 ( V_224 ) || F_115 ( V_225 )
F_104 ( V_191 , V_5 ) ;
V_229:
#endif
V_211:
F_30 ( & V_19 ) ;
F_118 ( & V_5 -> V_85 ) ;
F_37 ( & V_19 ) ;
F_79 ( & V_178 -> V_30 ) ;
F_119 ( & V_178 -> V_30 ) ;
if ( V_63 )
F_120 ( V_5 -> V_63 ) ;
F_110 ( V_178 , NULL ) ;
V_207:
F_120 ( V_5 -> V_6 ) ;
F_121 () ;
V_206:
F_55 ( V_5 ) ;
V_205:
if ( V_63 )
F_122 ( V_63 -> V_202 , F_108 ( V_63 ) ) ;
V_204:
F_122 ( V_27 -> V_202 , F_108 ( V_27 ) ) ;
return V_176 ;
}
static int T_11 F_123 ( struct V_177 * V_178 )
{
struct V_4 * V_5 = F_124 ( V_178 ) ;
struct V_196 * V_232 ;
int V_191 = F_125 ( V_178 , 0 ) ;
F_126 ( & V_5 -> V_29 ) ;
if ( V_191 > 0 )
F_104 ( V_191 , V_5 ) ;
F_30 ( & V_19 ) ;
F_118 ( & V_5 -> V_85 ) ;
F_37 ( & V_19 ) ;
F_103 ( V_5 ) ;
F_119 ( & V_178 -> V_30 ) ;
if ( V_5 -> V_63 )
F_120 ( V_5 -> V_63 ) ;
F_120 ( V_5 -> V_6 ) ;
F_110 ( V_178 , NULL ) ;
F_121 () ;
F_55 ( V_5 ) ;
V_232 = F_106 ( V_178 , V_200 , 0 ) ;
if ( V_232 )
F_122 ( V_232 -> V_202 , F_108 ( V_232 ) ) ;
V_232 = F_106 ( V_178 , V_200 , 1 ) ;
if ( V_232 )
F_122 ( V_232 -> V_202 , F_108 ( V_232 ) ) ;
return 0 ;
}
static void F_127 ( struct V_177 * V_178 )
{
struct V_4 * V_5 = F_124 ( V_178 ) ;
F_13 ( V_5 ) ;
}
static int F_128 ( struct V_180 * V_30 )
{
return 0 ;
}
static int F_129 ( struct V_180 * V_30 )
{
struct V_4 * V_5 = F_130 ( V_30 ) ;
return F_16 ( V_5 ) ;
}
static int F_131 ( struct V_180 * V_30 )
{
return 0 ;
}
static int F_132 ( struct V_180 * V_30 )
{
struct V_4 * V_5 = F_130 ( V_30 ) ;
int V_24 , V_103 ;
V_103 = F_16 ( V_5 ) ;
if ( V_103 < 0 )
F_57 ( V_30 , L_28 ) ;
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
int V_176 = F_134 ( & V_233 ) ;
if ( V_176 )
return V_176 ;
return F_135 ( & V_234 , F_105 ) ;
}
static void T_11 F_136 ( void )
{
F_137 ( & V_234 ) ;
F_138 ( & V_233 ) ;
}
