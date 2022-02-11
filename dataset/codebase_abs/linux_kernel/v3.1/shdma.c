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
T_5 V_71 = V_64 -> V_71 ;
T_4 V_72 ;
F_29 ( & V_24 -> V_73 ) ;
V_72 = V_24 -> V_21 . V_72 ;
V_72 ++ ;
if ( V_72 < 0 )
V_72 = 1 ;
V_24 -> V_21 . V_72 = V_72 ;
V_64 -> V_72 = V_72 ;
F_30 (chunk, c, desc->node.prev, node) {
if ( V_67 != V_66 && ( V_67 -> V_74 == V_75 ||
V_67 -> V_76 . V_72 > 0 ||
V_67 -> V_76 . V_72 == - V_54 ||
& V_67 -> V_77 == & V_24 -> V_78 ) )
break;
V_67 -> V_74 = V_79 ;
V_67 -> V_76 . V_71 = NULL ;
V_67 -> V_72 = V_72 ;
F_31 ( & V_67 -> V_77 , & V_24 -> V_80 ) ;
V_68 = V_67 ;
}
V_68 -> V_76 . V_71 = V_71 ;
V_68 -> V_76 . V_81 = V_64 -> V_81 ;
F_32 ( V_24 -> V_22 , L_2 ,
V_64 -> V_72 , & V_68 -> V_76 , V_24 -> V_58 ,
V_66 -> V_39 . V_40 , V_66 -> V_39 . V_44 , V_66 -> V_39 . V_42 ) ;
F_33 ( & V_24 -> V_73 ) ;
return V_72 ;
}
static struct V_65 * F_34 ( struct V_1 * V_24 )
{
struct V_65 * V_66 ;
F_35 (desc, &sh_chan->ld_free, node)
if ( V_66 -> V_74 != V_82 ) {
F_36 ( V_66 -> V_74 != V_75 ) ;
F_37 ( & V_66 -> V_77 ) ;
return V_66 ;
}
return NULL ;
}
static const struct V_83 * F_38 (
struct V_1 * V_24 , struct V_84 * V_85 )
{
struct V_6 * V_7 = F_10 ( V_24 ) ;
struct V_28 * V_11 = V_7 -> V_11 ;
int V_37 ;
if ( V_85 -> V_86 >= V_87 )
return NULL ;
for ( V_37 = 0 ; V_37 < V_11 -> V_88 ; V_37 ++ )
if ( V_11 -> V_89 [ V_37 ] . V_86 == V_85 -> V_86 )
return V_11 -> V_89 + V_37 ;
return NULL ;
}
static int F_39 ( struct V_90 * V_70 )
{
struct V_1 * V_24 = F_28 ( V_70 ) ;
struct V_65 * V_66 ;
struct V_84 * V_85 = V_70 -> V_91 ;
int V_92 ;
F_40 ( V_24 -> V_22 ) ;
if ( V_85 ) {
const struct V_83 * V_93 ;
V_93 = F_38 ( V_24 , V_85 ) ;
if ( ! V_93 ) {
V_92 = - V_94 ;
goto V_95;
}
if ( F_41 ( V_85 -> V_86 , V_96 ) ) {
V_92 = - V_54 ;
goto V_97;
}
V_85 -> V_98 = V_93 ;
F_25 ( V_24 , V_93 -> V_99 ) ;
F_24 ( V_24 , V_93 -> V_25 ) ;
} else {
F_23 ( V_24 ) ;
}
F_29 ( & V_24 -> V_73 ) ;
while ( V_24 -> V_100 < V_101 ) {
F_33 ( & V_24 -> V_73 ) ;
V_66 = F_42 ( sizeof( struct V_65 ) , V_102 ) ;
if ( ! V_66 ) {
F_29 ( & V_24 -> V_73 ) ;
break;
}
F_43 ( & V_66 -> V_76 ,
& V_24 -> V_21 ) ;
V_66 -> V_76 . V_103 = F_26 ;
V_66 -> V_74 = V_75 ;
F_29 ( & V_24 -> V_73 ) ;
F_44 ( & V_66 -> V_77 , & V_24 -> V_78 ) ;
V_24 -> V_100 ++ ;
}
F_33 ( & V_24 -> V_73 ) ;
if ( ! V_24 -> V_100 ) {
V_92 = - V_104 ;
goto V_105;
}
return V_24 -> V_100 ;
V_105:
if ( V_85 )
F_45 ( V_85 -> V_86 , V_96 ) ;
V_97:
V_95:
F_46 ( V_24 -> V_22 ) ;
return V_92 ;
}
static void F_47 ( struct V_90 * V_70 )
{
struct V_1 * V_24 = F_28 ( V_70 ) ;
struct V_65 * V_66 , * V_106 ;
F_48 ( V_107 ) ;
int V_108 = V_24 -> V_100 ;
F_49 ( & V_24 -> V_73 ) ;
F_22 ( V_24 ) ;
F_50 ( & V_24 -> V_73 ) ;
if ( ! F_51 ( & V_24 -> V_80 ) )
F_52 ( V_24 , true ) ;
if ( V_70 -> V_91 ) {
struct V_84 * V_85 = V_70 -> V_91 ;
F_45 ( V_85 -> V_86 , V_96 ) ;
V_70 -> V_91 = NULL ;
}
F_29 ( & V_24 -> V_73 ) ;
F_53 ( & V_24 -> V_78 , & V_107 ) ;
V_24 -> V_100 = 0 ;
F_33 ( & V_24 -> V_73 ) ;
if ( V_108 > 0 )
F_46 ( V_24 -> V_22 ) ;
F_30 (desc, _desc, &list, node)
F_54 ( V_66 ) ;
}
static struct V_65 * F_55 ( struct V_1 * V_24 ,
unsigned long V_15 , T_6 * V_109 , T_6 * V_110 , T_7 * V_111 ,
struct V_65 * * V_112 , enum V_113 V_114 )
{
struct V_65 * V_115 ;
T_7 V_116 ;
if ( ! * V_111 )
return NULL ;
V_115 = F_34 ( V_24 ) ;
if ( ! V_115 ) {
F_56 ( V_24 -> V_22 , L_3 ) ;
return NULL ;
}
V_116 = F_57 ( * V_111 , ( T_7 ) V_117 + 1 ) ;
V_115 -> V_39 . V_40 = * V_110 ;
V_115 -> V_39 . V_42 = * V_109 ;
V_115 -> V_39 . V_44 = V_116 ;
if ( ! * V_112 ) {
V_115 -> V_76 . V_72 = - V_54 ;
* V_112 = V_115 ;
} else {
V_115 -> V_76 . V_72 = - V_94 ;
}
F_32 ( V_24 -> V_22 ,
L_4 ,
V_116 , * V_111 , * V_110 , * V_109 , & V_115 -> V_76 ,
V_115 -> V_76 . V_72 , V_24 -> V_45 ) ;
V_115 -> V_74 = V_82 ;
V_115 -> V_76 . V_15 = V_15 ;
V_115 -> V_114 = V_114 ;
* V_111 -= V_116 ;
if ( V_114 == V_118 || V_114 == V_119 )
* V_110 += V_116 ;
if ( V_114 == V_118 || V_114 == V_120 )
* V_109 += V_116 ;
return V_115 ;
}
static struct V_63 * F_58 ( struct V_1 * V_24 ,
struct V_121 * V_122 , unsigned int V_123 , T_6 * V_8 ,
enum V_113 V_114 , unsigned long V_15 )
{
struct V_121 * V_124 ;
struct V_65 * V_112 = NULL , * V_115 = NULL ;
F_48 ( V_125 ) ;
int V_126 = 0 ;
int V_37 ;
if ( ! V_123 )
return NULL ;
F_59 (sgl, sg, sg_len, i)
V_126 += ( F_60 ( V_124 ) + V_117 ) /
( V_117 + 1 ) ;
F_29 ( & V_24 -> V_73 ) ;
F_59 (sgl, sg, sg_len, i) {
T_6 V_127 = F_61 ( V_124 ) ;
T_7 V_111 = F_60 ( V_124 ) ;
if ( ! V_111 )
goto V_128;
do {
F_32 ( V_24 -> V_22 , L_5 ,
V_37 , V_124 , V_111 , ( unsigned long long ) V_127 ) ;
if ( V_114 == V_120 )
V_115 = F_55 ( V_24 , V_15 ,
& V_127 , V_8 , & V_111 , & V_112 ,
V_114 ) ;
else
V_115 = F_55 ( V_24 , V_15 ,
V_8 , & V_127 , & V_111 , & V_112 ,
V_114 ) ;
if ( ! V_115 )
goto V_128;
V_115 -> V_126 = V_126 -- ;
F_62 ( & V_115 -> V_77 , & V_125 ) ;
} while ( V_111 );
}
if ( V_115 != V_112 )
V_115 -> V_76 . V_72 = - V_129 ;
F_63 ( & V_125 , & V_24 -> V_78 ) ;
F_33 ( & V_24 -> V_73 ) ;
return & V_112 -> V_76 ;
V_128:
F_35 (new, &tx_list, node)
V_115 -> V_74 = V_75 ;
F_64 ( & V_125 , & V_24 -> V_78 ) ;
F_33 ( & V_24 -> V_73 ) ;
return NULL ;
}
static struct V_63 * F_65 (
struct V_90 * V_70 , T_6 V_130 , T_6 V_131 ,
T_7 V_111 , unsigned long V_15 )
{
struct V_1 * V_24 ;
struct V_121 V_124 ;
if ( ! V_70 || ! V_111 )
return NULL ;
V_24 = F_28 ( V_70 ) ;
F_66 ( & V_124 , 1 ) ;
F_67 ( & V_124 , F_68 ( F_69 ( V_131 ) ) , V_111 ,
F_70 ( V_131 ) ) ;
F_61 ( & V_124 ) = V_131 ;
F_60 ( & V_124 ) = V_111 ;
return F_58 ( V_24 , & V_124 , 1 , & V_130 , V_118 ,
V_15 ) ;
}
static struct V_63 * F_71 (
struct V_90 * V_70 , struct V_121 * V_122 , unsigned int V_123 ,
enum V_113 V_114 , unsigned long V_15 )
{
struct V_84 * V_85 ;
struct V_1 * V_24 ;
T_6 V_132 ;
if ( ! V_70 )
return NULL ;
V_24 = F_28 ( V_70 ) ;
V_85 = V_70 -> V_91 ;
if ( ! V_85 || ! V_123 ) {
F_16 ( V_24 -> V_22 , L_6 ,
V_133 , V_85 , V_123 , V_85 ? V_85 -> V_86 : - 1 ) ;
return NULL ;
}
V_132 = V_85 -> V_98 -> V_8 ;
return F_58 ( V_24 , V_122 , V_123 , & V_132 ,
V_114 , V_15 ) ;
}
static int F_72 ( struct V_90 * V_70 , enum V_134 V_135 ,
unsigned long V_136 )
{
struct V_1 * V_24 = F_28 ( V_70 ) ;
if ( V_135 != V_137 )
return - V_138 ;
if ( ! V_70 )
return - V_94 ;
F_29 ( & V_24 -> V_73 ) ;
F_22 ( V_24 ) ;
if ( ! F_51 ( & V_24 -> V_80 ) ) {
struct V_65 * V_66 = F_73 ( V_24 -> V_80 . V_139 ,
struct V_65 , V_77 ) ;
V_66 -> V_140 = ( V_66 -> V_39 . V_44 - F_3 ( V_24 , V_46 ) ) <<
V_24 -> V_45 ;
}
F_33 ( & V_24 -> V_73 ) ;
F_52 ( V_24 , true ) ;
return 0 ;
}
static T_5 F_74 ( struct V_1 * V_24 , bool V_141 )
{
struct V_65 * V_66 , * V_106 ;
bool V_142 = false ;
T_4 V_72 = 0 ;
T_5 V_71 = NULL ;
void * V_85 = NULL ;
F_29 ( & V_24 -> V_73 ) ;
F_30 (desc, _desc, &sh_chan->ld_queue, node) {
struct V_63 * V_64 = & V_66 -> V_76 ;
F_36 ( V_64 -> V_72 > 0 && V_64 -> V_72 != V_66 -> V_72 ) ;
F_36 ( V_66 -> V_74 != V_79 &&
V_66 -> V_74 != V_143 &&
V_66 -> V_74 != V_144 ) ;
if ( ! V_141 && V_66 -> V_74 == V_79 &&
V_66 -> V_72 != V_72 )
break;
if ( V_64 -> V_72 > 0 )
V_72 = V_64 -> V_72 ;
if ( V_66 -> V_74 == V_143 && V_66 -> V_126 == 1 ) {
if ( V_24 -> V_145 != V_66 -> V_72 - 1 )
F_32 ( V_24 -> V_22 ,
L_7 ,
V_66 -> V_72 ,
V_24 -> V_145 + 1 ) ;
V_24 -> V_145 = V_66 -> V_72 ;
}
if ( V_66 -> V_74 == V_143 && V_64 -> V_71 ) {
V_66 -> V_74 = V_144 ;
V_71 = V_64 -> V_71 ;
V_85 = V_64 -> V_81 ;
F_32 ( V_24 -> V_22 , L_8 ,
V_64 -> V_72 , V_64 , V_24 -> V_58 ) ;
F_36 ( V_66 -> V_126 != 1 ) ;
break;
}
if ( V_64 -> V_72 > 0 || V_64 -> V_72 == - V_54 ) {
if ( V_66 -> V_74 == V_143 ) {
F_36 ( V_64 -> V_72 < 0 ) ;
V_66 -> V_74 = V_144 ;
}
V_142 = F_75 ( V_64 ) ;
} else {
switch ( V_66 -> V_74 ) {
case V_143 :
V_66 -> V_74 = V_144 ;
case V_144 :
if ( V_142 )
F_76 ( & V_66 -> V_76 ) ;
}
}
F_32 ( V_24 -> V_22 , L_9 ,
V_64 , V_64 -> V_72 ) ;
if ( ( ( V_66 -> V_74 == V_143 ||
V_66 -> V_74 == V_144 ) &&
F_75 ( & V_66 -> V_76 ) ) || V_141 ) {
V_66 -> V_74 = V_75 ;
F_77 ( & V_66 -> V_77 , & V_24 -> V_78 ) ;
}
}
if ( V_141 && ! V_71 )
V_24 -> V_145 = V_24 -> V_21 . V_72 ;
F_33 ( & V_24 -> V_73 ) ;
if ( V_71 )
V_71 ( V_85 ) ;
return V_71 ;
}
static void F_52 ( struct V_1 * V_24 , bool V_141 )
{
while ( F_74 ( V_24 , V_141 ) )
;
}
static void F_78 ( struct V_1 * V_24 )
{
struct V_65 * V_66 ;
F_29 ( & V_24 -> V_73 ) ;
if ( F_17 ( V_24 ) )
goto V_146;
F_35 (desc, &sh_chan->ld_queue, node)
if ( V_66 -> V_74 == V_79 ) {
F_32 ( V_24 -> V_22 , L_10 ,
V_66 -> V_76 . V_72 , V_24 -> V_58 ,
V_66 -> V_39 . V_44 , V_66 -> V_39 . V_40 , V_66 -> V_39 . V_42 ) ;
F_20 ( V_24 , & V_66 -> V_39 ) ;
F_21 ( V_24 ) ;
break;
}
V_146:
F_33 ( & V_24 -> V_73 ) ;
}
static void F_79 ( struct V_90 * V_70 )
{
struct V_1 * V_24 = F_28 ( V_70 ) ;
F_78 ( V_24 ) ;
}
static enum V_147 F_80 ( struct V_90 * V_70 ,
T_4 V_72 ,
struct V_148 * V_149 )
{
struct V_1 * V_24 = F_28 ( V_70 ) ;
T_4 V_150 ;
T_4 V_151 ;
enum V_147 V_152 ;
F_52 ( V_24 , false ) ;
V_151 = V_24 -> V_145 ;
F_81 () ;
V_150 = V_70 -> V_72 ;
F_36 ( V_151 < 0 ) ;
F_82 ( V_149 , V_151 , V_150 , 0 ) ;
F_29 ( & V_24 -> V_73 ) ;
V_152 = F_83 ( V_72 , V_151 , V_150 ) ;
if ( V_152 != V_153 ) {
struct V_65 * V_66 ;
V_152 = V_154 ;
F_35 (desc, &sh_chan->ld_queue, node)
if ( V_66 -> V_72 == V_72 ) {
V_152 = V_155 ;
break;
}
}
F_33 ( & V_24 -> V_73 ) ;
return V_152 ;
}
static T_8 F_84 ( int V_156 , void * V_3 )
{
T_8 V_92 = V_157 ;
struct V_1 * V_24 = V_3 ;
T_1 V_25 ;
F_85 ( & V_24 -> V_73 ) ;
V_25 = F_11 ( V_24 ) ;
if ( V_25 & V_27 ) {
F_22 ( V_24 ) ;
V_92 = V_158 ;
F_86 ( & V_24 -> V_159 ) ;
}
F_87 ( & V_24 -> V_73 ) ;
return V_92 ;
}
static bool F_88 ( struct V_6 * V_7 )
{
unsigned int V_160 = 0 ;
int V_37 ;
F_12 ( V_7 ) ;
for ( V_37 = 0 ; V_37 < V_161 ; V_37 ++ ) {
struct V_1 * V_24 = V_7 -> V_70 [ V_37 ] ;
struct V_65 * V_66 ;
F_48 ( V_162 ) ;
if ( ! V_24 )
continue;
F_85 ( & V_24 -> V_73 ) ;
F_22 ( V_24 ) ;
F_53 ( & V_24 -> V_80 , & V_162 ) ;
F_87 ( & V_24 -> V_73 ) ;
F_35 (desc, &dl, node) {
struct V_63 * V_64 = & V_66 -> V_76 ;
V_66 -> V_74 = V_75 ;
if ( V_64 -> V_71 )
V_64 -> V_71 ( V_64 -> V_81 ) ;
}
F_85 ( & V_24 -> V_73 ) ;
F_64 ( & V_162 , & V_24 -> V_78 ) ;
F_87 ( & V_24 -> V_73 ) ;
V_160 ++ ;
}
F_15 ( V_7 ) ;
return ! ! V_160 ;
}
static T_8 F_89 ( int V_156 , void * V_3 )
{
struct V_6 * V_7 = V_3 ;
if ( ! ( F_5 ( V_7 ) & V_18 ) )
return V_157 ;
F_88 ( V_3 ) ;
return V_158 ;
}
static void F_90 ( unsigned long V_3 )
{
struct V_1 * V_24 = (struct V_1 * ) V_3 ;
struct V_65 * V_66 ;
T_1 V_163 = F_3 ( V_24 , V_41 ) ;
T_1 V_164 = F_3 ( V_24 , V_43 ) ;
F_85 ( & V_24 -> V_73 ) ;
F_35 (desc, &sh_chan->ld_queue, node) {
if ( V_66 -> V_74 == V_79 &&
( ( V_66 -> V_114 == V_120 &&
( V_66 -> V_39 . V_42 + V_66 -> V_39 . V_44 ) == V_164 ) ||
( V_66 -> V_39 . V_40 + V_66 -> V_39 . V_44 ) == V_163 ) ) {
F_32 ( V_24 -> V_22 , L_11 ,
V_66 -> V_76 . V_72 , & V_66 -> V_76 ,
V_66 -> V_39 . V_42 ) ;
V_66 -> V_74 = V_143 ;
break;
}
}
F_87 ( & V_24 -> V_73 ) ;
F_78 ( V_24 ) ;
F_52 ( V_24 , false ) ;
}
static bool F_91 ( struct V_6 * V_7 )
{
if ( ( F_5 ( V_7 ) & V_17 ) == 0 )
return false ;
return F_88 ( V_7 ) ;
}
static int F_92 ( struct V_165 * V_166 ,
unsigned long V_135 , void * V_3 )
{
struct V_6 * V_7 ;
int V_92 = V_167 ;
bool V_168 ;
if ( ! F_93 () )
return V_167 ;
F_94 () ;
F_95 (shdev, &sh_dmae_devices, node) {
V_168 = F_91 ( V_7 ) ;
if ( V_168 == true )
V_92 = V_169 ;
}
F_96 () ;
return V_92 ;
}
static int T_9 F_97 ( struct V_6 * V_7 , int V_58 ,
int V_156 , unsigned long V_15 )
{
int V_170 ;
const struct V_55 * V_56 = & V_7 -> V_11 -> V_57 [ V_58 ] ;
struct V_171 * V_172 = F_98 ( V_7 -> V_21 . V_22 ) ;
struct V_1 * V_173 ;
V_173 = F_42 ( sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_173 ) {
F_56 ( V_7 -> V_21 . V_22 ,
L_12 ) ;
return - V_104 ;
}
V_173 -> V_21 . V_174 = & V_7 -> V_21 ;
V_173 -> V_22 = V_7 -> V_21 . V_22 ;
V_173 -> V_58 = V_58 ;
V_173 -> V_156 = V_156 ;
V_173 -> V_5 = V_7 -> V_9 + V_56 -> V_175 / sizeof( T_1 ) ;
F_99 ( & V_173 -> V_159 , F_90 ,
( unsigned long ) V_173 ) ;
F_100 ( & V_173 -> V_73 ) ;
F_101 ( & V_173 -> V_80 ) ;
F_101 ( & V_173 -> V_78 ) ;
F_62 ( & V_173 -> V_21 . V_176 ,
& V_7 -> V_21 . V_177 ) ;
V_7 -> V_21 . V_178 ++ ;
if ( V_172 -> V_58 >= 0 )
snprintf ( V_173 -> V_179 , sizeof( V_173 -> V_179 ) ,
L_13 , V_172 -> V_58 , V_173 -> V_58 ) ;
else
snprintf ( V_173 -> V_179 , sizeof( V_173 -> V_179 ) ,
L_14 , V_173 -> V_58 ) ;
V_170 = F_102 ( V_156 , & F_84 , V_15 ,
V_173 -> V_179 , V_173 ) ;
if ( V_170 ) {
F_56 ( V_7 -> V_21 . V_22 , L_15
L_16 , V_58 , V_170 ) ;
goto V_180;
}
V_7 -> V_70 [ V_58 ] = V_173 ;
return 0 ;
V_180:
F_37 ( & V_173 -> V_21 . V_176 ) ;
F_54 ( V_173 ) ;
return V_170 ;
}
static void F_103 ( struct V_6 * V_7 )
{
int V_37 ;
for ( V_37 = V_7 -> V_21 . V_178 - 1 ; V_37 >= 0 ; V_37 -- ) {
if ( V_7 -> V_70 [ V_37 ] ) {
struct V_1 * V_24 = V_7 -> V_70 [ V_37 ] ;
F_104 ( V_24 -> V_156 , V_24 ) ;
F_37 ( & V_24 -> V_21 . V_176 ) ;
F_54 ( V_24 ) ;
V_7 -> V_70 [ V_37 ] = NULL ;
}
}
V_7 -> V_21 . V_178 = 0 ;
}
static int T_10 F_105 ( struct V_171 * V_172 )
{
struct V_28 * V_11 = V_172 -> V_22 . V_181 ;
unsigned long V_182 = V_183 ,
V_184 [ V_161 ] = {} ;
int V_185 , V_186 [ V_161 ] ;
int V_170 , V_37 , V_187 = 0 , V_188 = 0 , V_189 = 0 ;
struct V_6 * V_7 ;
struct V_190 * V_70 , * V_59 , * V_191 , * V_192 ;
if ( ! V_11 || ! V_11 -> V_193 )
return - V_194 ;
V_70 = F_106 ( V_172 , V_195 , 0 ) ;
V_59 = F_106 ( V_172 , V_195 , 1 ) ;
V_191 = F_106 ( V_172 , V_196 , 0 ) ;
if ( ! V_70 || ! V_191 )
return - V_194 ;
if ( ! F_107 ( V_70 -> V_197 , F_108 ( V_70 ) , V_172 -> V_198 ) ) {
F_56 ( & V_172 -> V_22 , L_17 ) ;
return - V_54 ;
}
if ( V_59 && ! F_107 ( V_59 -> V_197 , F_108 ( V_59 ) , V_172 -> V_198 ) ) {
F_56 ( & V_172 -> V_22 , L_18 ) ;
V_170 = - V_54 ;
goto V_199;
}
V_170 = - V_104 ;
V_7 = F_42 ( sizeof( struct V_6 ) , V_102 ) ;
if ( ! V_7 ) {
F_56 ( & V_172 -> V_22 , L_19 ) ;
goto V_200;
}
V_7 -> V_9 = F_109 ( V_70 -> V_197 , F_108 ( V_70 ) ) ;
if ( ! V_7 -> V_9 )
goto V_201;
if ( V_59 ) {
V_7 -> V_59 = F_109 ( V_59 -> V_197 , F_108 ( V_59 ) ) ;
if ( ! V_7 -> V_59 )
goto V_202;
}
V_7 -> V_11 = V_11 ;
if ( V_11 -> V_13 )
V_7 -> V_13 = V_11 -> V_13 ;
else
V_7 -> V_13 = V_203 ;
if ( V_11 -> V_49 )
V_7 -> V_49 = V_11 -> V_49 ;
else
V_7 -> V_49 = V_204 ;
F_110 ( V_172 , V_7 ) ;
F_111 ( & V_172 -> V_22 ) ;
F_40 ( & V_172 -> V_22 ) ;
F_49 ( & V_16 ) ;
F_112 ( & V_7 -> V_77 , & V_205 ) ;
F_50 ( & V_16 ) ;
V_170 = F_15 ( V_7 ) ;
if ( V_170 )
goto V_206;
F_101 ( & V_7 -> V_21 . V_177 ) ;
F_113 ( V_207 , V_7 -> V_21 . V_208 ) ;
if ( V_11 -> V_89 && V_11 -> V_88 )
F_113 ( V_209 , V_7 -> V_21 . V_208 ) ;
V_7 -> V_21 . V_210
= F_39 ;
V_7 -> V_21 . V_211 = F_47 ;
V_7 -> V_21 . V_212 = F_65 ;
V_7 -> V_21 . V_213 = F_80 ;
V_7 -> V_21 . V_214 = F_79 ;
V_7 -> V_21 . V_215 = F_71 ;
V_7 -> V_21 . V_216 = F_72 ;
V_7 -> V_21 . V_22 = & V_172 -> V_22 ;
V_7 -> V_21 . V_217 = V_52 ;
#if F_114 ( V_218 ) || F_114 ( V_219 )
V_192 = F_106 ( V_172 , V_196 , 1 ) ;
if ( ! V_192 )
V_192 = V_191 ;
else
V_188 ++ ;
if ( V_192 == V_191 ||
( V_191 -> V_15 & V_220 ) == V_221 )
V_182 = V_222 ;
V_185 = V_191 -> V_197 ;
V_170 = F_102 ( V_185 , F_89 , V_182 ,
L_20 , V_7 ) ;
if ( V_170 ) {
F_56 ( & V_172 -> V_22 ,
L_21 ,
V_185 , V_170 ) ;
goto V_223;
}
#else
V_192 = V_191 ;
#endif
if ( V_192 -> V_197 == V_192 -> V_224 &&
! F_106 ( V_172 , V_196 , 1 ) ) {
for (; V_187 < V_11 -> V_193 ; V_187 ++ ) {
if ( V_187 < V_161 ) {
V_186 [ V_187 ] = V_192 -> V_197 ;
V_184 [ V_187 ] = V_222 ;
} else {
V_189 = 1 ;
break;
}
}
} else {
do {
for ( V_37 = V_192 -> V_197 ; V_37 <= V_192 -> V_224 ; V_37 ++ ) {
if ( V_187 >= V_161 ) {
V_189 = 1 ;
break;
}
if ( ( V_191 -> V_15 & V_220 ) ==
V_221 )
V_184 [ V_187 ] = V_222 ;
else
V_184 [ V_187 ] = V_183 ;
F_32 ( & V_172 -> V_22 ,
L_22 ,
V_37 , V_187 ) ;
V_186 [ V_187 ++ ] = V_37 ;
}
if ( V_187 >= V_161 )
break;
V_192 = F_106 ( V_172 ,
V_196 , ++ V_188 ) ;
} while ( V_187 < V_11 -> V_193 && V_192 );
}
for ( V_37 = 0 ; V_37 < V_187 ; V_37 ++ ) {
V_170 = F_97 ( V_7 , V_37 , V_186 [ V_37 ] , V_184 [ V_37 ] ) ;
if ( V_170 )
goto V_225;
}
if ( V_189 )
F_115 ( & V_172 -> V_22 , L_23
L_24 ,
V_11 -> V_193 , V_161 ) ;
F_46 ( & V_172 -> V_22 ) ;
F_116 ( & V_7 -> V_21 ) ;
return V_170 ;
V_225:
F_103 ( V_7 ) ;
#if F_114 ( V_218 ) || F_114 ( V_219 )
F_104 ( V_185 , V_7 ) ;
V_223:
#endif
V_206:
F_49 ( & V_16 ) ;
F_117 ( & V_7 -> V_77 ) ;
F_50 ( & V_16 ) ;
F_46 ( & V_172 -> V_22 ) ;
F_118 ( & V_172 -> V_22 ) ;
if ( V_59 )
F_119 ( V_7 -> V_59 ) ;
F_110 ( V_172 , NULL ) ;
V_202:
F_119 ( V_7 -> V_9 ) ;
F_120 () ;
V_201:
F_54 ( V_7 ) ;
V_200:
if ( V_59 )
F_121 ( V_59 -> V_197 , F_108 ( V_59 ) ) ;
V_199:
F_121 ( V_70 -> V_197 , F_108 ( V_70 ) ) ;
return V_170 ;
}
static int T_11 F_122 ( struct V_171 * V_172 )
{
struct V_6 * V_7 = F_123 ( V_172 ) ;
struct V_190 * V_226 ;
int V_185 = F_124 ( V_172 , 0 ) ;
F_125 ( & V_7 -> V_21 ) ;
if ( V_185 > 0 )
F_104 ( V_185 , V_7 ) ;
F_49 ( & V_16 ) ;
F_117 ( & V_7 -> V_77 ) ;
F_50 ( & V_16 ) ;
F_103 ( V_7 ) ;
F_118 ( & V_172 -> V_22 ) ;
if ( V_7 -> V_59 )
F_119 ( V_7 -> V_59 ) ;
F_119 ( V_7 -> V_9 ) ;
F_110 ( V_172 , NULL ) ;
F_120 () ;
F_54 ( V_7 ) ;
V_226 = F_106 ( V_172 , V_195 , 0 ) ;
if ( V_226 )
F_121 ( V_226 -> V_197 , F_108 ( V_226 ) ) ;
V_226 = F_106 ( V_172 , V_195 , 1 ) ;
if ( V_226 )
F_121 ( V_226 -> V_197 , F_108 ( V_226 ) ) ;
return 0 ;
}
static void F_126 ( struct V_171 * V_172 )
{
struct V_6 * V_7 = F_123 ( V_172 ) ;
F_12 ( V_7 ) ;
}
static int F_127 ( struct V_174 * V_22 )
{
return 0 ;
}
static int F_128 ( struct V_174 * V_22 )
{
struct V_6 * V_7 = F_129 ( V_22 ) ;
return F_15 ( V_7 ) ;
}
static int F_130 ( struct V_174 * V_22 )
{
struct V_6 * V_7 = F_129 ( V_22 ) ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_7 -> V_11 -> V_193 ; V_37 ++ ) {
struct V_1 * V_24 = V_7 -> V_70 [ V_37 ] ;
if ( V_24 -> V_100 )
V_24 -> V_227 = F_131 ( V_22 ) ;
}
return 0 ;
}
static int F_132 ( struct V_174 * V_22 )
{
struct V_6 * V_7 = F_129 ( V_22 ) ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_7 -> V_11 -> V_193 ; V_37 ++ ) {
struct V_1 * V_24 = V_7 -> V_70 [ V_37 ] ;
struct V_84 * V_85 = V_24 -> V_21 . V_91 ;
if ( ! V_24 -> V_100 )
continue;
if ( ! V_24 -> V_227 )
F_40 ( V_22 ) ;
if ( V_85 ) {
const struct V_83 * V_93 = V_85 -> V_98 ;
F_25 ( V_24 , V_93 -> V_99 ) ;
F_24 ( V_24 , V_93 -> V_25 ) ;
} else {
F_23 ( V_24 ) ;
}
}
return 0 ;
}
static int T_10 F_133 ( void )
{
int V_170 = F_134 ( & V_228 ) ;
if ( V_170 )
return V_170 ;
return F_135 ( & V_229 , F_105 ) ;
}
static void T_11 F_136 ( void )
{
F_137 ( & V_229 ) ;
F_138 ( & V_228 ) ;
}
