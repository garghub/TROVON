static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
return V_6 -> V_7 + V_3 -> V_8 . V_9 [ V_4 ] ;
}
static void F_2 ( T_2 * V_10 , T_2 V_11 , int V_12 , int V_13 )
{
T_2 V_14 = F_3 ( V_12 , V_13 ) ;
* V_10 &= ~ V_14 ;
* V_10 |= ( V_11 << V_13 ) & V_14 ;
}
static void F_4 ( struct V_15 * V_16 , T_3 V_17 )
{
F_2 ( & V_16 -> V_10 [ 0 ] , V_17 , 7 , 0 ) ;
}
static void F_5 ( struct V_15 * V_16 , T_1 V_18 )
{
F_2 ( & V_16 -> V_10 [ 0 ] , V_18 , 63 , 32 ) ;
}
static void F_6 ( struct V_15 * V_16 , T_1 V_19 )
{
F_2 ( & V_16 -> V_10 [ 1 ] , V_19 , 31 , 0 ) ;
}
static void F_7 ( struct V_15 * V_16 , T_1 V_20 )
{
F_2 ( & V_16 -> V_10 [ 1 ] , V_20 , 63 , 32 ) ;
}
static void F_8 ( struct V_15 * V_16 , T_3 V_21 )
{
F_2 ( & V_16 -> V_10 [ 1 ] , V_21 , 4 , 0 ) ;
}
static void F_9 ( struct V_15 * V_16 , T_2 V_22 )
{
F_2 ( & V_16 -> V_10 [ 2 ] , V_22 >> 8 , 51 , 8 ) ;
}
static void F_10 ( struct V_15 * V_16 , int V_23 )
{
F_2 ( & V_16 -> V_10 [ 2 ] , ! ! V_23 , 63 , 63 ) ;
}
static void F_11 ( struct V_15 * V_16 , T_2 V_24 )
{
F_2 ( & V_16 -> V_10 [ 2 ] , V_24 >> 16 , 51 , 16 ) ;
}
static void F_12 ( struct V_15 * V_16 , T_4 V_25 )
{
F_2 ( & V_16 -> V_10 [ 2 ] , V_25 , 15 , 0 ) ;
}
static void F_13 ( struct V_15 * V_16 , T_4 V_26 )
{
F_2 ( & V_16 -> V_10 [ 1 ] , V_26 , 47 , 32 ) ;
}
static void F_14 ( struct V_15 * V_16 , T_1 V_27 )
{
F_2 ( & V_16 -> V_10 [ 2 ] , V_27 , 31 , 0 ) ;
}
static void F_15 ( struct V_15 * V_16 , T_1 V_28 )
{
F_2 ( & V_16 -> V_10 [ 2 ] , V_28 , 63 , 32 ) ;
}
static void F_16 ( struct V_15 * V_16 , bool V_29 )
{
F_2 ( & V_16 -> V_10 [ 2 ] , V_29 , 0 , 0 ) ;
}
static void F_17 ( struct V_15 * V_16 , T_4 V_30 )
{
F_2 ( & V_16 -> V_10 [ 0 ] , V_30 , 47 , 32 ) ;
}
static void F_18 ( struct V_15 * V_16 , T_4 V_31 )
{
F_2 ( & V_16 -> V_10 [ 1 ] , V_31 , 15 , 0 ) ;
}
static void F_19 ( struct V_15 * V_16 , T_2 V_32 )
{
F_2 ( & V_16 -> V_10 [ 3 ] , V_32 >> 16 , 51 , 16 ) ;
}
static void F_20 ( struct V_15 * V_16 , T_3 V_33 )
{
F_2 ( & V_16 -> V_10 [ 3 ] , V_33 , 4 , 0 ) ;
}
static inline void F_21 ( struct V_15 * V_16 )
{
V_16 -> V_10 [ 0 ] = F_22 ( V_16 -> V_10 [ 0 ] ) ;
V_16 -> V_10 [ 1 ] = F_22 ( V_16 -> V_10 [ 1 ] ) ;
V_16 -> V_10 [ 2 ] = F_22 ( V_16 -> V_10 [ 2 ] ) ;
V_16 -> V_10 [ 3 ] = F_22 ( V_16 -> V_10 [ 3 ] ) ;
}
static struct V_1 * F_23 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
unsigned long V_22 ;
T_3 V_21 = F_24 ( V_35 -> V_36 . V_37 -> V_38 ) ;
V_22 = F_25 ( V_35 -> V_36 . V_37 -> V_39 ) ;
V_22 = F_26 ( V_22 , V_40 ) ;
F_4 ( V_16 , V_41 ) ;
F_5 ( V_16 , V_35 -> V_36 . V_37 -> V_42 ) ;
F_8 ( V_16 , V_21 - 1 ) ;
F_9 ( V_16 , V_22 ) ;
F_10 ( V_16 , V_35 -> V_36 . V_23 ) ;
F_21 ( V_16 ) ;
return NULL ;
}
static struct V_1 * F_27 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
F_4 ( V_16 , V_43 ) ;
F_12 ( V_16 , V_35 -> V_44 . V_25 -> V_45 ) ;
F_11 ( V_16 , V_35 -> V_44 . V_25 -> V_46 ) ;
F_10 ( V_16 , V_35 -> V_44 . V_23 ) ;
F_21 ( V_16 ) ;
return V_35 -> V_44 . V_25 ;
}
static struct V_1 * F_28 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
struct V_1 * V_25 ;
V_25 = F_1 ( V_35 -> V_47 . V_37 ,
V_35 -> V_47 . V_48 ) ;
F_4 ( V_16 , V_49 ) ;
F_5 ( V_16 , V_35 -> V_47 . V_37 -> V_42 ) ;
F_6 ( V_16 , V_35 -> V_47 . V_48 ) ;
F_7 ( V_16 , V_35 -> V_47 . V_20 ) ;
F_12 ( V_16 , V_25 -> V_45 ) ;
F_21 ( V_16 ) ;
return V_25 ;
}
static struct V_1 * F_29 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
struct V_1 * V_25 ;
V_25 = F_1 ( V_35 -> V_50 . V_37 ,
V_35 -> V_50 . V_48 ) ;
F_4 ( V_16 , V_51 ) ;
F_5 ( V_16 , V_35 -> V_50 . V_37 -> V_42 ) ;
F_6 ( V_16 , V_35 -> V_50 . V_48 ) ;
F_12 ( V_16 , V_35 -> V_50 . V_25 -> V_45 ) ;
F_21 ( V_16 ) ;
return V_25 ;
}
static struct V_1 * F_30 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
struct V_1 * V_25 ;
V_25 = F_1 ( V_35 -> V_52 . V_37 ,
V_35 -> V_52 . V_48 ) ;
F_4 ( V_16 , V_53 ) ;
F_5 ( V_16 , V_35 -> V_52 . V_37 -> V_42 ) ;
F_6 ( V_16 , V_35 -> V_52 . V_48 ) ;
F_21 ( V_16 ) ;
return V_25 ;
}
static struct V_1 * F_31 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
struct V_1 * V_25 ;
V_25 = F_1 ( V_35 -> V_54 . V_37 ,
V_35 -> V_54 . V_48 ) ;
F_4 ( V_16 , V_55 ) ;
F_5 ( V_16 , V_35 -> V_54 . V_37 -> V_42 ) ;
F_6 ( V_16 , V_35 -> V_54 . V_48 ) ;
F_21 ( V_16 ) ;
return V_25 ;
}
static struct V_1 * F_32 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
struct V_1 * V_25 ;
V_25 = F_1 ( V_35 -> V_56 . V_37 ,
V_35 -> V_56 . V_48 ) ;
F_4 ( V_16 , V_57 ) ;
F_5 ( V_16 , V_35 -> V_56 . V_37 -> V_42 ) ;
F_6 ( V_16 , V_35 -> V_56 . V_48 ) ;
F_21 ( V_16 ) ;
return V_25 ;
}
static struct V_1 * F_33 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
struct V_1 * V_25 ;
V_25 = F_1 ( V_35 -> V_58 . V_37 ,
V_35 -> V_58 . V_48 ) ;
F_4 ( V_16 , V_59 ) ;
F_5 ( V_16 , V_35 -> V_58 . V_37 -> V_42 ) ;
F_6 ( V_16 , V_35 -> V_58 . V_48 ) ;
F_21 ( V_16 ) ;
return V_25 ;
}
static struct V_1 * F_34 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
F_4 ( V_16 , V_60 ) ;
F_12 ( V_16 , V_35 -> V_44 . V_25 -> V_45 ) ;
F_21 ( V_16 ) ;
return NULL ;
}
static struct V_61 * F_35 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
F_4 ( V_16 , V_62 ) ;
F_13 ( V_16 , V_35 -> V_63 . V_64 -> V_65 ) ;
F_21 ( V_16 ) ;
return V_35 -> V_63 . V_64 ;
}
static struct V_61 * F_36 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
unsigned long V_66 ;
V_66 = F_25 ( F_37 ( V_35 -> V_67 . V_64 -> V_68 ) ) ;
F_4 ( V_16 , V_69 ) ;
F_13 ( V_16 , V_35 -> V_67 . V_64 -> V_65 ) ;
F_10 ( V_16 , V_35 -> V_67 . V_23 ) ;
F_11 ( V_16 , V_35 -> V_67 . V_25 -> V_46 ) ;
F_19 ( V_16 , V_66 ) ;
F_20 ( V_16 , V_70 - 1 ) ;
F_21 ( V_16 ) ;
return V_35 -> V_67 . V_64 ;
}
static struct V_61 * F_38 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
T_1 V_71 ;
if ( V_35 -> V_72 . V_73 )
V_71 = V_35 -> V_72 . V_64 -> V_74 ;
else
V_71 = 1023 ;
F_4 ( V_16 , V_75 ) ;
F_5 ( V_16 , V_35 -> V_72 . V_37 -> V_42 ) ;
F_13 ( V_16 , V_35 -> V_72 . V_64 -> V_65 ) ;
F_6 ( V_16 , V_35 -> V_72 . V_48 ) ;
F_15 ( V_16 , V_71 ) ;
F_14 ( V_16 , V_35 -> V_72 . V_27 ) ;
F_21 ( V_16 ) ;
return V_35 -> V_72 . V_64 ;
}
static struct V_61 * F_39 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
T_1 V_71 ;
if ( V_35 -> V_76 . V_73 )
V_71 = V_35 -> V_76 . V_64 -> V_74 ;
else
V_71 = 1023 ;
F_4 ( V_16 , V_77 ) ;
F_5 ( V_16 , V_35 -> V_76 . V_37 -> V_42 ) ;
F_13 ( V_16 , V_35 -> V_76 . V_64 -> V_65 ) ;
F_6 ( V_16 , V_35 -> V_76 . V_48 ) ;
F_15 ( V_16 , V_71 ) ;
F_16 ( V_16 , true ) ;
F_21 ( V_16 ) ;
return V_35 -> V_76 . V_64 ;
}
static struct V_61 * F_40 ( struct V_15 * V_16 ,
struct V_34 * V_35 )
{
F_4 ( V_16 , V_78 ) ;
F_17 ( V_16 , V_35 -> V_79 . V_30 ) ;
F_18 ( V_16 , V_35 -> V_79 . V_31 ) ;
F_13 ( V_16 , V_35 -> V_79 . V_64 -> V_65 ) ;
F_11 ( V_16 , V_35 -> V_79 . V_25 -> V_46 ) ;
F_21 ( V_16 ) ;
return V_35 -> V_79 . V_64 ;
}
static T_2 F_41 ( struct V_5 * V_6 ,
struct V_15 * V_80 )
{
return ( V_80 - V_6 -> V_81 ) * sizeof( * V_80 ) ;
}
static int F_42 ( struct V_5 * V_6 )
{
int V_82 ;
int V_83 ;
V_82 = V_6 -> V_84 - V_6 -> V_81 ;
V_83 = F_43 ( V_6 -> V_85 + V_86 ) / sizeof( struct V_15 ) ;
if ( ( ( V_82 + 1 ) % V_87 ) == V_83 )
return 1 ;
return 0 ;
}
static struct V_15 * F_44 ( struct V_5 * V_6 )
{
struct V_15 * V_16 ;
T_1 V_88 = 1000000 ;
while ( F_42 ( V_6 ) ) {
V_88 -- ;
if ( ! V_88 ) {
F_45 ( L_1 ) ;
return NULL ;
}
F_46 () ;
F_47 ( 1 ) ;
}
V_16 = V_6 -> V_84 ++ ;
if ( V_6 -> V_84 == ( V_6 -> V_81 + V_87 ) )
V_6 -> V_84 = V_6 -> V_81 ;
V_16 -> V_10 [ 0 ] = 0 ;
V_16 -> V_10 [ 1 ] = 0 ;
V_16 -> V_10 [ 2 ] = 0 ;
V_16 -> V_10 [ 3 ] = 0 ;
return V_16 ;
}
static struct V_15 * F_48 ( struct V_5 * V_6 )
{
T_2 V_89 = F_41 ( V_6 , V_6 -> V_84 ) ;
F_49 ( V_89 , V_6 -> V_85 + V_90 ) ;
return V_6 -> V_84 ;
}
static void F_50 ( struct V_5 * V_6 , struct V_15 * V_16 )
{
if ( V_6 -> V_91 & V_92 )
F_51 ( V_16 , sizeof( * V_16 ) ) ;
else
F_52 ( V_93 ) ;
}
static void F_53 ( struct V_5 * V_6 ,
struct V_15 * V_94 ,
struct V_15 * V_95 )
{
T_2 V_96 , V_97 , V_98 ;
T_1 V_88 = 1000000 ;
V_97 = F_41 ( V_6 , V_94 ) ;
V_98 = F_41 ( V_6 , V_95 ) ;
while ( 1 ) {
V_96 = F_43 ( V_6 -> V_85 + V_86 ) ;
if ( V_97 < V_98 && V_96 >= V_98 )
break;
if ( V_97 >= V_98 && V_96 >= V_98 && V_96 < V_97 )
break;
V_88 -- ;
if ( ! V_88 ) {
F_45 ( L_2 ) ;
return;
}
F_46 () ;
F_47 ( 1 ) ;
}
}
static void F_54 ( struct V_15 * V_99 ,
struct V_1 * V_100 )
{
F_4 ( V_99 , V_101 ) ;
F_11 ( V_99 , V_100 -> V_46 ) ;
F_21 ( V_99 ) ;
}
void F_55 ( struct V_61 * V_64 )
{
struct V_34 V_35 ;
struct V_5 * V_6 ;
unsigned long V_91 ;
int V_45 = V_64 -> V_102 ;
V_35 . V_79 . V_64 = V_64 ;
V_35 . V_79 . V_31 = ( T_4 ) V_103 ;
if ( ! V_103 ) {
V_6 = F_56 ( & V_104 , struct V_5 , V_105 ) ;
V_35 . V_79 . V_30 = 0 ;
V_35 . V_79 . V_25 = & V_6 -> V_7 [ V_45 ] ;
F_57 ( V_6 , F_40 , & V_35 ) ;
return;
}
F_58 ( & V_106 , V_91 ) ;
V_35 . V_79 . V_30 = V_107 ++ ;
F_59 (its, &its_nodes, entry) {
if ( ! V_6 -> V_108 )
continue;
V_35 . V_79 . V_25 = & V_6 -> V_7 [ V_45 ] ;
F_57 ( V_6 , F_40 , & V_35 ) ;
}
F_60 ( & V_106 , V_91 ) ;
}
static void F_61 ( struct V_61 * V_64 )
{
struct V_34 V_35 ;
struct V_5 * V_6 ;
V_35 . V_63 . V_64 = V_64 ;
F_59 (its, &its_nodes, entry) {
if ( ! V_6 -> V_108 )
continue;
F_57 ( V_6 , F_35 , & V_35 ) ;
}
}
static inline T_1 F_62 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
return V_110 -> V_111 - V_3 -> V_8 . V_112 ;
}
static void F_64 ( struct V_109 * V_110 , T_3 V_113 , T_3 V_114 )
{
T_5 V_111 ;
struct V_115 * V_116 ;
T_3 * V_117 ;
if ( F_65 ( V_110 ) ) {
struct V_2 * V_3 = F_63 ( V_110 ) ;
T_1 V_4 = F_62 ( V_110 ) ;
V_116 = V_3 -> V_8 . V_118 -> V_119 ;
V_111 = V_3 -> V_8 . V_120 [ V_4 ] . V_121 ;
} else {
V_116 = V_122 -> V_116 ;
V_111 = V_110 -> V_111 ;
}
V_117 = F_37 ( V_116 ) + V_111 - 8192 ;
* V_117 &= ~ V_113 ;
* V_117 |= V_114 | V_123 ;
if ( V_122 -> V_91 & V_124 )
F_51 ( V_117 , sizeof( * V_117 ) ) ;
else
F_52 ( V_93 ) ;
}
static void F_66 ( struct V_109 * V_110 , T_3 V_113 , T_3 V_114 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
F_64 ( V_110 , V_113 , V_114 ) ;
F_67 ( V_3 , F_62 ( V_110 ) ) ;
}
static void F_68 ( struct V_109 * V_110 , bool V_125 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
T_1 V_4 = F_62 ( V_110 ) ;
if ( V_3 -> V_8 . V_120 [ V_4 ] . V_73 == V_125 )
return;
V_3 -> V_8 . V_120 [ V_4 ] . V_73 = V_125 ;
F_69 ( V_3 , V_4 ) ;
}
static void F_70 ( struct V_109 * V_110 )
{
if ( F_65 ( V_110 ) )
F_68 ( V_110 , false ) ;
F_66 ( V_110 , V_126 , 0 ) ;
}
static void F_71 ( struct V_109 * V_110 )
{
if ( F_65 ( V_110 ) )
F_68 ( V_110 , true ) ;
F_66 ( V_110 , 0 , V_126 ) ;
}
static int F_72 ( struct V_109 * V_110 , const struct V_127 * V_128 ,
bool V_129 )
{
unsigned int V_130 ;
const struct V_127 * V_131 = V_132 ;
struct V_2 * V_3 = F_63 ( V_110 ) ;
struct V_1 * V_133 ;
T_1 V_19 = F_62 ( V_110 ) ;
if ( F_65 ( V_110 ) )
return - V_134 ;
if ( V_3 -> V_6 -> V_91 & V_135 ) {
if ( V_3 -> V_6 -> V_136 >= 0 ) {
V_131 = F_73 ( V_3 -> V_6 -> V_136 ) ;
if ( ! F_74 ( V_128 , V_131 ) )
return - V_134 ;
}
}
V_130 = F_75 ( V_128 , V_131 ) ;
if ( V_130 >= V_137 )
return - V_134 ;
if ( V_130 != V_3 -> V_8 . V_9 [ V_19 ] ) {
V_133 = & V_3 -> V_6 -> V_7 [ V_130 ] ;
F_76 ( V_3 , V_133 , V_19 ) ;
V_3 -> V_8 . V_9 [ V_19 ] = V_130 ;
F_77 ( V_110 , F_78 ( V_130 ) ) ;
}
return V_138 ;
}
static void F_79 ( struct V_109 * V_110 , struct V_139 * V_140 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
struct V_5 * V_6 ;
T_2 V_141 ;
V_6 = V_3 -> V_6 ;
V_141 = V_6 -> V_142 + V_143 ;
V_140 -> V_144 = F_80 ( V_141 ) ;
V_140 -> V_145 = F_81 ( V_141 ) ;
V_140 -> V_146 = F_62 ( V_110 ) ;
F_82 ( V_110 -> V_147 , V_140 ) ;
}
static int F_83 ( struct V_109 * V_110 ,
enum V_148 V_149 ,
bool V_150 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
T_1 V_4 = F_62 ( V_110 ) ;
if ( V_149 != V_151 )
return - V_134 ;
if ( V_150 )
F_84 ( V_3 , V_4 ) ;
else
F_85 ( V_3 , V_4 ) ;
return 0 ;
}
static int F_86 ( struct V_109 * V_110 , struct V_152 * V_153 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
T_1 V_4 = F_62 ( V_110 ) ;
int V_154 = 0 ;
if ( ! V_153 -> V_155 )
return - V_134 ;
F_87 ( & V_3 -> V_8 . V_156 ) ;
if ( ! V_3 -> V_8 . V_118 ) {
struct F_86 * V_157 ;
V_157 = F_88 ( sizeof( * V_157 ) * V_3 -> V_8 . V_158 ,
V_159 ) ;
if ( ! V_157 ) {
V_154 = - V_160 ;
goto V_161;
}
V_3 -> V_8 . V_118 = V_153 -> V_155 -> V_118 ;
V_3 -> V_8 . V_120 = V_157 ;
} else if ( V_3 -> V_8 . V_118 != V_153 -> V_155 -> V_118 ) {
V_154 = - V_134 ;
goto V_161;
}
V_3 -> V_8 . V_120 [ V_4 ] = * V_153 -> V_155 ;
if ( F_65 ( V_110 ) ) {
F_69 ( V_3 , V_4 ) ;
} else {
F_89 ( V_3 , V_4 ) ;
F_90 ( V_3 , V_4 ) ;
F_91 ( V_110 ) ;
V_3 -> V_8 . V_162 ++ ;
}
V_161:
F_92 ( & V_3 -> V_8 . V_156 ) ;
return V_154 ;
}
static int F_93 ( struct V_109 * V_110 , struct V_152 * V_153 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
T_1 V_4 = F_62 ( V_110 ) ;
int V_154 = 0 ;
F_87 ( & V_3 -> V_8 . V_156 ) ;
if ( ! V_3 -> V_8 . V_118 ||
! V_3 -> V_8 . V_120 [ V_4 ] . V_118 ) {
V_154 = - V_134 ;
goto V_161;
}
* V_153 -> V_155 = V_3 -> V_8 . V_120 [ V_4 ] ;
V_161:
F_92 ( & V_3 -> V_8 . V_156 ) ;
return V_154 ;
}
static int F_94 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
T_1 V_4 = F_62 ( V_110 ) ;
int V_154 = 0 ;
F_87 ( & V_3 -> V_8 . V_156 ) ;
if ( ! V_3 -> V_8 . V_118 || ! F_65 ( V_110 ) ) {
V_154 = - V_134 ;
goto V_161;
}
F_89 ( V_3 , V_4 ) ;
F_95 ( V_110 ) ;
F_96 ( V_3 , V_110 -> V_111 , V_4 ) ;
F_66 ( V_110 , 0xff , ( V_163 |
V_126 |
V_123 ) ) ;
if ( ! -- V_3 -> V_8 . V_162 ) {
V_3 -> V_8 . V_118 = NULL ;
F_97 ( V_3 -> V_8 . V_120 ) ;
}
V_161:
F_92 ( & V_3 -> V_8 . V_156 ) ;
return V_154 ;
}
static int F_98 ( struct V_109 * V_110 , struct V_152 * V_153 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
if ( ! V_3 -> V_8 . V_118 || ! F_65 ( V_110 ) )
return - V_134 ;
if ( V_153 -> V_164 == V_165 )
F_66 ( V_110 , 0xff , V_153 -> V_166 ) ;
else
F_64 ( V_110 , 0xff , V_153 -> V_166 ) ;
F_68 ( V_110 , ! ! ( V_153 -> V_166 & V_126 ) ) ;
return 0 ;
}
static int F_99 ( struct V_109 * V_110 , void * V_167 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
struct V_152 * V_153 = V_167 ;
if ( ! V_3 -> V_6 -> V_108 )
return - V_134 ;
if ( ! V_153 )
return F_94 ( V_110 ) ;
switch ( V_153 -> V_164 ) {
case V_168 :
return F_86 ( V_110 , V_153 ) ;
case V_169 :
return F_93 ( V_110 , V_153 ) ;
case V_170 :
case V_165 :
return F_98 ( V_110 , V_153 ) ;
default:
return - V_134 ;
}
}
static int F_100 ( int V_171 )
{
return ( V_171 - 8192 ) >> V_172 ;
}
static int F_101 ( int V_173 )
{
return ( V_173 << V_172 ) + 8192 ;
}
static int T_6 F_102 ( T_1 V_174 )
{
V_175 = F_100 ( 1UL << V_174 ) ;
V_176 = F_88 ( F_103 ( V_175 ) * sizeof( long ) ,
V_159 ) ;
if ( ! V_176 ) {
V_175 = 0 ;
return - V_160 ;
}
F_104 ( L_3 , ( int ) V_175 ) ;
return 0 ;
}
static unsigned long * F_105 ( int V_177 , int * V_85 , int * V_178 )
{
unsigned long * V_179 = NULL ;
int V_180 ;
int V_181 ;
int V_182 ;
V_181 = F_106 ( V_177 , V_183 ) ;
F_107 ( & V_184 ) ;
do {
V_180 = F_108 ( V_176 , V_175 ,
0 , V_181 , 0 ) ;
if ( V_180 < V_175 )
break;
V_181 -- ;
} while ( V_181 > 0 );
if ( ! V_181 )
goto V_161;
V_179 = F_88 ( F_103 ( V_181 * V_183 ) * sizeof ( long ) ,
V_185 ) ;
if ( ! V_179 )
goto V_161;
for ( V_182 = 0 ; V_182 < V_181 ; V_182 ++ )
F_109 ( V_180 + V_182 , V_176 ) ;
* V_85 = F_101 ( V_180 ) ;
* V_178 = V_181 * V_183 ;
V_161:
F_110 ( & V_184 ) ;
if ( ! V_179 )
* V_85 = * V_178 = 0 ;
return V_179 ;
}
static void F_111 ( unsigned long * V_179 , int V_85 , int V_178 )
{
int V_171 ;
F_107 ( & V_184 ) ;
for ( V_171 = V_85 ; V_171 < ( V_85 + V_178 ) ; V_171 += V_183 ) {
int V_173 = F_100 ( V_171 ) ;
F_112 ( V_173 > V_175 ) ;
if ( F_113 ( V_173 , V_176 ) ) {
F_114 ( V_173 , V_176 ) ;
} else {
F_115 ( L_4 , V_173 ) ;
}
}
F_110 ( & V_184 ) ;
F_97 ( V_179 ) ;
}
static struct V_115 * F_116 ( T_7 V_186 )
{
struct V_115 * V_116 ;
V_116 = F_117 ( V_186 , F_118 ( V_187 ) ) ;
if ( ! V_116 )
return NULL ;
memset ( F_37 ( V_116 ) ,
V_163 | V_123 ,
V_187 ) ;
F_51 ( F_37 ( V_116 ) , V_187 ) ;
return V_116 ;
}
static void F_119 ( struct V_115 * V_116 )
{
F_120 ( ( unsigned long ) F_37 ( V_116 ) ,
F_118 ( V_187 ) ) ;
}
static int T_6 F_121 ( void )
{
T_8 V_188 ;
V_189 = F_122 ( T_1 , V_122 -> V_174 , V_190 ) ;
V_122 -> V_116 = F_116 ( V_191 ) ;
if ( ! V_122 -> V_116 ) {
F_115 ( L_5 ) ;
return - V_160 ;
}
V_188 = F_123 ( V_122 -> V_116 ) ;
F_104 ( L_6 , & V_188 ) ;
return F_102 ( V_189 ) ;
}
static T_2 F_124 ( struct V_5 * V_6 , struct V_192 * V_193 )
{
T_1 V_194 = V_193 - V_6 -> V_195 ;
return F_125 ( V_6 -> V_85 + V_196 + ( V_194 << 3 ) ) ;
}
static void F_126 ( struct V_5 * V_6 , struct V_192 * V_193 ,
T_2 V_11 )
{
T_1 V_194 = V_193 - V_6 -> V_195 ;
F_127 ( V_11 , V_6 -> V_85 + V_196 + ( V_194 << 3 ) ) ;
V_193 -> V_11 = F_124 ( V_6 , V_193 ) ;
}
static int F_128 ( struct V_5 * V_6 , struct V_192 * V_193 ,
T_2 V_197 , T_2 V_198 , T_1 V_199 , T_1 V_200 ,
bool V_201 )
{
T_2 V_11 = F_124 ( V_6 , V_193 ) ;
T_2 V_202 = F_129 ( V_11 ) ;
T_2 type = F_130 ( V_11 ) ;
T_2 V_203 , V_204 ;
T_1 F_117 ;
void * V_85 ;
V_205:
F_117 = ( F_131 ( V_200 ) / V_199 ) ;
if ( F_117 > V_206 ) {
F_132 ( L_7 ,
& V_6 -> V_142 , V_207 [ type ] ,
F_117 , V_206 ) ;
F_117 = V_206 ;
V_200 = F_118 ( V_206 * V_199 ) ;
}
V_85 = ( void * ) F_133 ( V_159 | V_208 , V_200 ) ;
if ( ! V_85 )
return - V_160 ;
V_203 = F_25 ( V_85 ) ;
if ( F_134 ( V_209 ) && ( V_203 >> 48 ) ) {
if ( V_199 != V_210 ) {
F_115 ( L_8 , V_199 ) ;
F_120 ( ( unsigned long ) V_85 , V_200 ) ;
return - V_211 ;
}
V_203 = F_135 ( V_203 ) ;
}
V_212:
V_11 = ( V_203 |
( type << V_213 ) |
( ( V_202 - 1 ) << V_214 ) |
( ( F_117 - 1 ) << V_215 ) |
V_197 |
V_198 |
V_216 ) ;
V_11 |= V_201 ? V_217 : 0x0 ;
switch ( V_199 ) {
case V_218 :
V_11 |= V_219 ;
break;
case V_220 :
V_11 |= V_221 ;
break;
case V_210 :
V_11 |= V_222 ;
break;
}
F_126 ( V_6 , V_193 , V_11 ) ;
V_204 = V_193 -> V_11 ;
if ( ( V_11 ^ V_204 ) & V_223 ) {
V_198 = V_204 & V_223 ;
if ( ! V_198 ) {
V_197 = V_224 ;
F_51 ( V_85 , F_131 ( V_200 ) ) ;
}
goto V_212;
}
if ( ( V_11 ^ V_204 ) & V_225 ) {
F_120 ( ( unsigned long ) V_85 , V_200 ) ;
V_193 -> V_85 = NULL ;
switch ( V_199 ) {
case V_220 :
V_199 = V_218 ;
goto V_205;
case V_210 :
V_199 = V_220 ;
goto V_205;
}
}
if ( V_11 != V_204 ) {
F_115 ( L_9 ,
& V_6 -> V_142 , V_207 [ type ] ,
V_11 , V_204 ) ;
F_120 ( ( unsigned long ) V_85 , V_200 ) ;
return - V_211 ;
}
V_193 -> V_200 = V_200 ;
V_193 -> V_85 = V_85 ;
V_193 -> V_199 = V_199 ;
V_204 = V_201 ? V_226 : V_202 ;
F_104 ( L_10 ,
& V_6 -> V_142 , ( int ) ( F_131 ( V_200 ) / ( int ) V_204 ) ,
V_207 [ type ] ,
( unsigned long ) F_25 ( V_85 ) ,
V_201 ? L_11 : L_12 , ( int ) V_202 ,
V_199 / V_227 , ( int ) V_198 >> V_228 ) ;
return 0 ;
}
static bool F_136 ( struct V_5 * V_6 ,
struct V_192 * V_193 ,
T_1 V_199 , T_1 * V_200 , T_1 V_229 )
{
T_2 V_204 = F_124 ( V_6 , V_193 ) ;
T_2 type = F_130 ( V_204 ) ;
T_2 V_202 = F_129 ( V_204 ) ;
T_2 V_11 = V_230 | V_231 ;
T_1 V_232 = * V_200 ;
bool V_201 = false ;
if ( ( V_202 << V_229 ) > ( V_199 * 2 ) ) {
F_126 ( V_6 , V_193 , V_11 | V_217 ) ;
V_201 = ! ! ( V_193 -> V_11 & V_217 ) ;
if ( V_201 ) {
V_229 -= F_24 ( V_199 / ( int ) V_202 ) ;
V_202 = V_226 ;
}
}
V_232 = F_137 ( T_1 , F_118 ( V_202 << V_229 ) , V_232 ) ;
if ( V_232 >= V_233 ) {
V_232 = V_233 - 1 ;
V_229 = F_24 ( F_131 ( V_232 ) / ( int ) V_202 ) ;
F_132 ( L_13 ,
& V_6 -> V_142 , V_207 [ type ] ,
V_6 -> V_234 , V_229 ) ;
}
* V_200 = V_232 ;
return V_201 ;
}
static void F_138 ( struct V_5 * V_6 )
{
int V_182 ;
for ( V_182 = 0 ; V_182 < V_235 ; V_182 ++ ) {
if ( V_6 -> V_195 [ V_182 ] . V_85 ) {
F_120 ( ( unsigned long ) V_6 -> V_195 [ V_182 ] . V_85 ,
V_6 -> V_195 [ V_182 ] . V_200 ) ;
V_6 -> V_195 [ V_182 ] . V_85 = NULL ;
}
}
}
static int F_139 ( struct V_5 * V_6 )
{
T_2 V_236 = F_140 ( V_6 -> V_85 + V_237 ) ;
T_1 V_229 = F_141 ( V_236 ) ;
T_2 V_198 = V_230 ;
T_2 V_197 = V_231 ;
T_1 V_199 = V_210 ;
int V_238 , V_182 ;
if ( V_6 -> V_91 & V_239 ) {
V_197 = V_240 ;
V_229 = 0x14 ;
}
V_6 -> V_234 = V_229 ;
for ( V_182 = 0 ; V_182 < V_235 ; V_182 ++ ) {
struct V_192 * V_193 = V_6 -> V_195 + V_182 ;
T_2 V_11 = F_124 ( V_6 , V_193 ) ;
T_2 type = F_130 ( V_11 ) ;
T_1 V_200 = F_118 ( V_199 ) ;
bool V_201 = false ;
switch ( type ) {
case V_241 :
continue;
case V_242 :
V_201 = F_136 ( V_6 , V_193 ,
V_199 , & V_200 ,
V_6 -> V_234 ) ;
case V_243 :
V_201 = F_136 ( V_6 , V_193 ,
V_199 , & V_200 ,
V_244 ) ;
break;
}
V_238 = F_128 ( V_6 , V_193 , V_197 , V_198 , V_199 , V_200 , V_201 ) ;
if ( V_238 < 0 ) {
F_138 ( V_6 ) ;
return V_238 ;
}
V_199 = V_193 -> V_199 ;
V_197 = V_193 -> V_11 & V_245 ;
V_198 = V_193 -> V_11 & V_223 ;
}
return 0 ;
}
static int F_142 ( struct V_5 * V_6 )
{
V_6 -> V_7 = F_88 ( V_137 * sizeof( * V_6 -> V_7 ) ,
V_159 ) ;
if ( ! V_6 -> V_7 )
return - V_160 ;
return 0 ;
}
static struct V_115 * F_143 ( T_7 V_186 )
{
struct V_115 * V_246 ;
V_246 = F_117 ( V_186 | V_208 ,
F_118 ( F_137 ( T_1 , V_247 , V_210 ) ) ) ;
if ( ! V_246 )
return NULL ;
F_51 ( F_37 ( V_246 ) , V_247 ) ;
return V_246 ;
}
static void F_144 ( struct V_115 * V_248 )
{
F_120 ( ( unsigned long ) F_37 ( V_248 ) ,
F_118 ( F_137 ( T_1 , V_247 , V_210 ) ) ) ;
}
static void F_145 ( void )
{
void T_9 * V_249 = F_146 () ;
struct V_115 * V_246 ;
T_2 V_11 , V_204 ;
V_246 = F_147 () -> V_246 ;
if ( ! V_246 ) {
T_8 V_188 ;
V_246 = F_143 ( V_191 ) ;
if ( ! V_246 ) {
F_115 ( L_14 ,
F_148 () ) ;
return;
}
V_188 = F_123 ( V_246 ) ;
F_104 ( L_15 ,
F_148 () , & V_188 ) ;
F_147 () -> V_246 = V_246 ;
}
V_11 = F_43 ( V_249 + V_250 ) ;
V_11 &= ~ V_251 ;
F_49 ( V_11 , V_249 + V_250 ) ;
F_52 ( V_252 ) ;
V_11 = ( F_123 ( V_122 -> V_116 ) |
V_253 |
V_254 |
( ( V_70 - 1 ) & V_255 ) ) ;
F_149 ( V_11 , V_249 + V_256 ) ;
V_204 = F_150 ( V_249 + V_256 ) ;
if ( ( V_204 ^ V_11 ) & V_257 ) {
if ( ! ( V_204 & V_257 ) ) {
V_11 &= ~ ( V_257 |
V_258 ) ;
V_11 |= V_259 ;
F_149 ( V_11 , V_249 + V_256 ) ;
}
F_151 ( L_16 ) ;
V_122 -> V_91 |= V_124 ;
}
V_11 = ( F_123 ( V_246 ) |
V_260 |
V_261 ) ;
F_152 ( V_11 , V_249 + V_262 ) ;
V_204 = F_153 ( V_249 + V_262 ) ;
if ( ! ( V_204 & V_263 ) ) {
V_11 &= ~ ( V_263 |
V_264 ) ;
V_11 |= V_265 ;
F_152 ( V_11 , V_249 + V_262 ) ;
}
V_11 = F_43 ( V_249 + V_250 ) ;
V_11 |= V_251 ;
F_49 ( V_11 , V_249 + V_250 ) ;
F_52 ( V_252 ) ;
}
static void F_154 ( void )
{
struct V_5 * V_6 ;
int V_130 ;
F_107 ( & V_266 ) ;
V_130 = F_148 () ;
F_59 (its, &its_nodes, entry) {
T_2 V_267 ;
if ( V_6 -> V_91 & V_135 ) {
struct V_268 * V_269 ;
V_269 = F_155 ( V_130 , NULL ) ;
if ( V_6 -> V_136 != V_270 &&
V_6 -> V_136 != F_156 ( V_269 ) )
continue;
}
if ( F_140 ( V_6 -> V_85 + V_237 ) & V_271 ) {
V_267 = F_147 () -> V_142 ;
} else {
V_267 = F_140 ( F_146 () + V_272 ) ;
V_267 = F_157 ( V_267 ) << 16 ;
}
V_6 -> V_7 [ V_130 ] . V_46 = V_267 ;
V_6 -> V_7 [ V_130 ] . V_45 = V_130 ;
F_158 ( V_6 , & V_6 -> V_7 [ V_130 ] , 1 ) ;
F_159 ( V_6 , & V_6 -> V_7 [ V_130 ] ) ;
}
F_110 ( & V_266 ) ;
}
static struct V_2 * F_160 ( struct V_5 * V_6 , T_1 V_273 )
{
struct V_2 * V_3 = NULL , * V_204 ;
unsigned long V_91 ;
F_58 ( & V_6 -> V_274 , V_91 ) ;
F_59 (tmp, &its->its_device_list, entry) {
if ( V_204 -> V_42 == V_273 ) {
V_3 = V_204 ;
break;
}
}
F_60 ( & V_6 -> V_274 , V_91 ) ;
return V_3 ;
}
static struct V_192 * F_161 ( struct V_5 * V_6 , T_1 type )
{
int V_182 ;
for ( V_182 = 0 ; V_182 < V_235 ; V_182 ++ ) {
if ( F_130 ( V_6 -> V_195 [ V_182 ] . V_11 ) == type )
return & V_6 -> V_195 [ V_182 ] ;
}
return NULL ;
}
static bool F_162 ( struct V_192 * V_193 , T_1 V_19 )
{
struct V_115 * V_115 ;
T_1 V_202 , V_194 ;
T_10 * V_275 ;
V_202 = F_129 ( V_193 -> V_11 ) ;
if ( ! ( V_193 -> V_11 & V_217 ) )
return ( V_19 < ( F_131 ( V_193 -> V_200 ) / V_202 ) ) ;
V_194 = V_19 >> F_24 ( V_193 -> V_199 / V_202 ) ;
if ( V_194 >= ( F_131 ( V_193 -> V_200 ) / V_226 ) )
return false ;
V_275 = V_193 -> V_85 ;
if ( ! V_275 [ V_194 ] ) {
V_115 = F_117 ( V_159 | V_208 , F_118 ( V_193 -> V_199 ) ) ;
if ( ! V_115 )
return false ;
if ( ! ( V_193 -> V_11 & V_223 ) )
F_51 ( F_37 ( V_115 ) , V_193 -> V_199 ) ;
V_275 [ V_194 ] = F_22 ( F_123 ( V_115 ) | V_216 ) ;
if ( ! ( V_193 -> V_11 & V_223 ) )
F_51 ( V_275 + V_194 , V_226 ) ;
F_52 ( V_252 ) ;
}
return true ;
}
static bool F_163 ( struct V_5 * V_6 , T_1 V_273 )
{
struct V_192 * V_193 ;
V_193 = F_161 ( V_6 , V_242 ) ;
if ( ! V_193 )
return ( F_24 ( V_273 ) < V_6 -> V_234 ) ;
return F_162 ( V_193 , V_273 ) ;
}
static bool F_164 ( T_1 V_65 )
{
struct V_5 * V_6 ;
F_59 (its, &its_nodes, entry) {
struct V_192 * V_193 ;
if ( ! V_6 -> V_108 )
continue;
V_193 = F_161 ( V_6 , V_243 ) ;
if ( ! V_193 )
return false ;
if ( ! F_162 ( V_193 , V_65 ) )
return false ;
}
return true ;
}
static struct V_2 * F_165 ( struct V_5 * V_6 , T_1 V_273 ,
int V_276 , bool V_277 )
{
struct V_2 * V_37 ;
unsigned long * V_278 = NULL ;
unsigned long V_91 ;
T_4 * V_9 = NULL ;
void * V_39 ;
int V_112 ;
int V_158 ;
int V_38 ;
int V_279 ;
if ( ! F_163 ( V_6 , V_273 ) )
return NULL ;
V_37 = F_88 ( sizeof( * V_37 ) , V_159 ) ;
V_38 = F_166 ( 2UL , F_167 ( V_276 ) ) ;
V_279 = V_38 * V_6 -> V_280 ;
V_279 = F_166 ( V_279 , V_40 ) + V_40 - 1 ;
V_39 = F_88 ( V_279 , V_159 ) ;
if ( V_277 ) {
V_278 = F_105 ( V_276 , & V_112 , & V_158 ) ;
if ( V_278 )
V_9 = F_88 ( sizeof( * V_9 ) * V_158 ,
V_159 ) ;
} else {
V_9 = F_88 ( sizeof( * V_9 ) * V_38 , V_159 ) ;
V_158 = 0 ;
V_112 = 0 ;
}
if ( ! V_37 || ! V_39 || ! V_9 || ( ! V_278 && V_277 ) ) {
F_97 ( V_37 ) ;
F_97 ( V_39 ) ;
F_97 ( V_278 ) ;
F_97 ( V_9 ) ;
return NULL ;
}
F_51 ( V_39 , V_279 ) ;
V_37 -> V_6 = V_6 ;
V_37 -> V_39 = V_39 ;
V_37 -> V_38 = V_38 ;
V_37 -> V_8 . V_278 = V_278 ;
V_37 -> V_8 . V_9 = V_9 ;
V_37 -> V_8 . V_112 = V_112 ;
V_37 -> V_8 . V_158 = V_158 ;
F_168 ( & V_37 -> V_8 . V_156 ) ;
V_37 -> V_42 = V_273 ;
F_169 ( & V_37 -> V_105 ) ;
F_58 ( & V_6 -> V_274 , V_91 ) ;
F_170 ( & V_37 -> V_105 , & V_6 -> V_281 ) ;
F_60 ( & V_6 -> V_274 , V_91 ) ;
F_171 ( V_37 , 1 ) ;
return V_37 ;
}
static void F_172 ( struct V_2 * V_3 )
{
unsigned long V_91 ;
F_58 ( & V_3 -> V_6 -> V_274 , V_91 ) ;
F_173 ( & V_3 -> V_105 ) ;
F_60 ( & V_3 -> V_6 -> V_274 , V_91 ) ;
F_97 ( V_3 -> V_39 ) ;
F_97 ( V_3 ) ;
}
static int F_174 ( struct V_2 * V_37 , T_5 * V_111 )
{
int V_194 ;
V_194 = F_175 ( V_37 -> V_8 . V_278 ,
V_37 -> V_8 . V_158 ) ;
if ( V_194 == V_37 -> V_8 . V_158 )
return - V_282 ;
* V_111 = V_37 -> V_8 . V_112 + V_194 ;
F_109 ( V_194 , V_37 -> V_8 . V_278 ) ;
return 0 ;
}
static int F_176 ( struct V_283 * V_284 , struct V_285 * V_37 ,
int V_286 , T_11 * V_153 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_287 * V_288 ;
T_1 V_273 ;
V_273 = V_153 -> V_289 [ 0 ] . V_290 ;
V_288 = F_177 ( V_284 ) ;
V_6 = V_288 -> V_146 ;
if ( ! V_122 -> V_291 &&
V_292 . V_37 &&
V_292 . V_37 -> V_6 == V_6 &&
V_273 == V_292 . V_37 -> V_42 ) {
F_178 ( 1 , L_17 ,
V_273 ) ;
return - V_134 ;
}
V_3 = F_160 ( V_6 , V_273 ) ;
if ( V_3 ) {
F_179 ( L_18 , V_273 ) ;
goto V_161;
}
V_3 = F_165 ( V_6 , V_273 , V_286 , true ) ;
if ( ! V_3 )
return - V_160 ;
F_179 ( L_19 , V_286 , F_24 ( V_286 ) ) ;
V_161:
V_153 -> V_289 [ 0 ] . V_80 = V_3 ;
return 0 ;
}
static int F_180 ( struct V_283 * V_284 ,
unsigned int V_293 ,
T_5 V_111 )
{
struct V_294 V_295 ;
if ( F_181 ( V_284 -> V_296 ) ) {
V_295 . V_297 = V_284 -> V_296 -> V_297 ;
V_295 . V_298 = 3 ;
V_295 . V_299 [ 0 ] = V_300 ;
V_295 . V_299 [ 1 ] = V_111 ;
V_295 . V_299 [ 2 ] = V_301 ;
} else if ( F_182 ( V_284 -> V_296 -> V_297 ) ) {
V_295 . V_297 = V_284 -> V_296 -> V_297 ;
V_295 . V_298 = 2 ;
V_295 . V_299 [ 0 ] = V_111 ;
V_295 . V_299 [ 1 ] = V_301 ;
} else {
return - V_134 ;
}
return F_183 ( V_284 , V_293 , 1 , & V_295 ) ;
}
static int F_184 ( struct V_283 * V_284 , unsigned int V_293 ,
unsigned int V_177 , void * args )
{
T_11 * V_153 = args ;
struct V_2 * V_3 = V_153 -> V_289 [ 0 ] . V_80 ;
T_5 V_111 ;
int V_238 ;
int V_182 ;
for ( V_182 = 0 ; V_182 < V_177 ; V_182 ++ ) {
V_238 = F_174 ( V_3 , & V_111 ) ;
if ( V_238 )
return V_238 ;
V_238 = F_180 ( V_284 , V_293 + V_182 , V_111 ) ;
if ( V_238 )
return V_238 ;
F_185 ( V_284 , V_293 + V_182 ,
V_111 , & V_302 , V_3 ) ;
F_186 ( F_187 ( F_188 ( V_293 + V_182 ) ) ) ;
F_179 ( L_20 ,
( int ) ( V_111 - V_3 -> V_8 . V_112 ) ,
( int ) V_111 , V_293 + V_182 ) ;
}
return 0 ;
}
static void F_189 ( struct V_283 * V_284 ,
struct V_109 * V_110 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
T_1 V_4 = F_62 ( V_110 ) ;
const struct V_127 * V_131 = V_132 ;
int V_130 ;
if ( V_3 -> V_6 -> V_136 >= 0 )
V_131 = F_73 ( V_3 -> V_6 -> V_136 ) ;
V_130 = F_190 ( V_131 ) ;
V_3 -> V_8 . V_9 [ V_4 ] = V_130 ;
F_77 ( V_110 , F_78 ( V_130 ) ) ;
F_96 ( V_3 , V_110 -> V_111 , V_4 ) ;
}
static void F_191 ( struct V_283 * V_284 ,
struct V_109 * V_110 )
{
struct V_2 * V_3 = F_63 ( V_110 ) ;
T_1 V_4 = F_62 ( V_110 ) ;
F_89 ( V_3 , V_4 ) ;
}
static void F_192 ( struct V_283 * V_284 , unsigned int V_293 ,
unsigned int V_177 )
{
struct V_109 * V_110 = F_193 ( V_284 , V_293 ) ;
struct V_2 * V_3 = F_63 ( V_110 ) ;
int V_182 ;
for ( V_182 = 0 ; V_182 < V_177 ; V_182 ++ ) {
struct V_109 * V_146 = F_193 ( V_284 ,
V_293 + V_182 ) ;
T_1 V_4 = F_62 ( V_146 ) ;
F_114 ( V_4 , V_3 -> V_8 . V_278 ) ;
F_194 ( V_146 ) ;
}
if ( F_195 ( V_3 -> V_8 . V_278 ,
V_3 -> V_8 . V_158 ) ) {
F_111 ( V_3 -> V_8 . V_278 ,
V_3 -> V_8 . V_112 ,
V_3 -> V_8 . V_158 ) ;
F_97 ( V_3 -> V_8 . V_9 ) ;
F_171 ( V_3 , 0 ) ;
F_172 ( V_3 ) ;
}
F_196 ( V_284 , V_293 , V_177 ) ;
}
static void F_197 ( struct V_61 * V_64 )
{
if ( V_64 -> V_303 == - 1 )
return;
F_89 ( V_292 . V_37 , V_64 -> V_303 ) ;
V_292 . V_304 [ V_64 -> V_303 ] = NULL ;
if ( V_292 . V_304 [ V_292 . V_305 ] )
V_292 . V_305 = V_64 -> V_303 ;
V_64 -> V_303 = - 1 ;
}
static void F_198 ( struct V_61 * V_64 )
{
if ( ! V_122 -> V_291 ) {
unsigned long V_91 ;
F_58 ( & V_292 . V_274 , V_91 ) ;
F_197 ( V_64 ) ;
F_60 ( & V_292 . V_274 , V_91 ) ;
}
}
static void F_199 ( struct V_61 * V_64 )
{
if ( V_64 -> V_303 != - 1 )
return;
if ( V_292 . V_304 [ V_292 . V_305 ] )
F_197 ( V_292 . V_304 [ V_292 . V_305 ] ) ;
V_292 . V_304 [ V_292 . V_305 ] = V_64 ;
V_64 -> V_303 = V_292 . V_305 ;
V_292 . V_305 = ( V_292 . V_305 + 1 ) % V_292 . V_37 -> V_38 ;
V_292 . V_37 -> V_8 . V_9 [ V_64 -> V_303 ] = V_64 -> V_102 ;
F_96 ( V_292 . V_37 , V_64 -> V_74 , V_64 -> V_303 ) ;
}
static void F_200 ( struct V_61 * V_64 , int V_94 , int V_95 )
{
unsigned long V_91 ;
struct V_1 * V_133 ;
if ( V_122 -> V_291 ) {
void T_9 * V_306 ;
V_306 = F_201 ( V_122 -> V_307 , V_94 ) -> V_308 ;
F_202 ( V_64 -> V_74 , V_306 + V_309 ) ;
while ( F_203 ( V_306 + V_310 ) & 1 )
F_46 () ;
return;
}
F_58 ( & V_292 . V_274 , V_91 ) ;
F_199 ( V_64 ) ;
V_133 = & V_292 . V_37 -> V_6 -> V_7 [ V_95 ] ;
F_76 ( V_292 . V_37 , V_133 , V_64 -> V_303 ) ;
V_292 . V_37 -> V_8 . V_9 [ V_64 -> V_303 ] = V_95 ;
F_60 ( & V_292 . V_274 , V_91 ) ;
}
static int F_204 ( struct V_109 * V_110 ,
const struct V_127 * V_128 ,
bool V_129 )
{
struct V_61 * V_64 = F_63 ( V_110 ) ;
int V_130 = F_190 ( V_128 ) ;
if ( V_64 -> V_102 != V_130 ) {
int V_94 = V_64 -> V_102 ;
V_64 -> V_102 = V_130 ;
F_55 ( V_64 ) ;
F_200 ( V_64 , V_94 , V_130 ) ;
}
return V_138 ;
}
static void F_205 ( struct V_61 * V_64 )
{
void * T_9 V_311 = F_206 () ;
T_2 V_11 ;
V_11 = F_25 ( F_37 ( V_64 -> V_312 -> V_119 ) ) &
F_3 ( 51 , 12 ) ;
V_11 |= ( V_70 - 1 ) & V_313 ;
V_11 |= V_314 ;
V_11 |= V_315 ;
F_207 ( V_11 , V_311 + V_316 ) ;
V_11 = F_25 ( F_37 ( V_64 -> V_68 ) ) &
F_3 ( 51 , 16 ) ;
V_11 |= V_317 ;
V_11 |= V_318 ;
V_11 |= V_319 ;
V_11 |= V_64 -> V_320 ? V_321 : 0 ;
V_11 |= V_322 ;
F_208 ( V_11 , V_311 + V_323 ) ;
}
static void F_209 ( struct V_61 * V_64 )
{
void * T_9 V_311 = F_206 () ;
T_1 V_88 = 1000000 ;
bool V_324 ;
T_2 V_11 ;
V_11 = F_210 ( V_311 + V_323 ) ;
V_11 &= ~ V_322 ;
F_208 ( V_11 , V_311 + V_323 ) ;
do {
V_11 = F_210 ( V_311 + V_323 ) ;
V_324 = ! ( V_11 & V_325 ) ;
if ( ! V_324 ) {
V_88 -- ;
F_46 () ;
F_47 ( 1 ) ;
}
} while ( ! V_324 && V_88 );
if ( F_211 ( ! V_324 && ! V_88 ) ) {
F_45 ( L_21 ) ;
V_64 -> V_320 = false ;
V_64 -> V_326 = true ;
} else {
V_64 -> V_320 = ! ! ( V_11 & V_321 ) ;
V_64 -> V_326 = ! ! ( V_11 & V_319 ) ;
}
}
static int F_212 ( struct V_109 * V_110 , void * V_167 )
{
struct V_61 * V_64 = F_63 ( V_110 ) ;
struct V_152 * V_153 = V_167 ;
switch ( V_153 -> V_164 ) {
case V_327 :
F_205 ( V_64 ) ;
return 0 ;
case V_328 :
F_209 ( V_64 ) ;
return 0 ;
case V_329 :
F_61 ( V_64 ) ;
return 0 ;
default:
return - V_134 ;
}
}
static void F_213 ( struct V_61 * V_64 ,
void (* V_16)( struct V_2 * , T_1 ) )
{
unsigned long V_91 ;
F_58 ( & V_292 . V_274 , V_91 ) ;
F_199 ( V_64 ) ;
V_16 ( V_292 . V_37 , V_64 -> V_303 ) ;
F_60 ( & V_292 . V_274 , V_91 ) ;
}
static void F_214 ( struct V_109 * V_110 )
{
struct V_61 * V_64 = F_63 ( V_110 ) ;
if ( V_122 -> V_291 ) {
void T_9 * V_306 ;
V_306 = F_201 ( V_122 -> V_307 , V_64 -> V_102 ) -> V_308 ;
F_202 ( V_64 -> V_74 , V_306 + V_330 ) ;
while ( F_203 ( V_306 + V_310 ) & 1 )
F_46 () ;
} else {
F_213 ( V_64 , F_67 ) ;
}
}
static void F_215 ( struct V_109 * V_110 )
{
F_64 ( V_110 -> V_331 , V_126 , 0 ) ;
F_214 ( V_110 ) ;
}
static void F_216 ( struct V_109 * V_110 )
{
F_64 ( V_110 -> V_331 , 0 , V_126 ) ;
F_214 ( V_110 ) ;
}
static int F_217 ( struct V_109 * V_110 ,
enum V_148 V_149 ,
bool V_150 )
{
struct V_61 * V_64 = F_63 ( V_110 ) ;
if ( V_149 != V_151 )
return - V_134 ;
if ( V_122 -> V_291 ) {
void T_9 * V_306 ;
V_306 = F_201 ( V_122 -> V_307 , V_64 -> V_102 ) -> V_308 ;
if ( V_150 ) {
F_202 ( V_64 -> V_74 , V_306 + V_332 ) ;
} else {
F_202 ( V_64 -> V_74 , V_306 + V_309 ) ;
while ( F_203 ( V_306 + V_310 ) & 1 )
F_46 () ;
}
} else {
if ( V_150 )
F_213 ( V_64 , F_84 ) ;
else
F_213 ( V_64 , F_85 ) ;
}
return 0 ;
}
static int F_218 ( void )
{
return F_219 ( & V_333 , 0 , V_334 , V_159 ) ;
}
static void F_220 ( T_4 V_19 )
{
F_221 ( & V_333 , V_19 ) ;
}
static int F_222 ( struct V_61 * V_64 )
{
struct V_115 * V_68 ;
int V_65 ;
V_65 = F_218 () ;
if ( V_65 < 0 )
return V_65 ;
V_68 = F_143 ( V_159 ) ;
if ( ! V_68 ) {
F_220 ( V_65 ) ;
return - V_160 ;
}
if ( ! F_164 ( V_65 ) ) {
F_220 ( V_65 ) ;
F_144 ( V_64 -> V_68 ) ;
return - V_160 ;
}
V_64 -> V_65 = V_65 ;
V_64 -> V_68 = V_68 ;
V_64 -> V_303 = - 1 ;
return 0 ;
}
static void F_223 ( struct V_61 * V_64 )
{
F_198 ( V_64 ) ;
F_220 ( V_64 -> V_65 ) ;
F_144 ( V_64 -> V_68 ) ;
}
static void F_224 ( struct V_283 * V_284 ,
unsigned int V_293 ,
unsigned int V_177 )
{
struct V_312 * V_118 = V_284 -> V_335 ;
int V_182 ;
F_196 ( V_284 , V_293 , V_177 ) ;
for ( V_182 = 0 ; V_182 < V_177 ; V_182 ++ ) {
struct V_109 * V_146 = F_193 ( V_284 ,
V_293 + V_182 ) ;
struct V_61 * V_64 = F_63 ( V_146 ) ;
F_112 ( V_118 != V_64 -> V_312 ) ;
F_114 ( V_146 -> V_111 , V_118 -> V_336 ) ;
F_223 ( V_64 ) ;
F_194 ( V_146 ) ;
}
if ( F_195 ( V_118 -> V_336 , V_118 -> V_337 ) ) {
F_111 ( V_118 -> V_336 , V_118 -> V_338 , V_118 -> V_337 ) ;
F_119 ( V_118 -> V_119 ) ;
}
}
static int F_225 ( struct V_283 * V_284 , unsigned int V_293 ,
unsigned int V_177 , void * args )
{
struct V_312 * V_118 = args ;
unsigned long * V_179 ;
struct V_115 * V_119 ;
int V_85 , V_178 , V_182 , V_238 = 0 ;
F_112 ( ! V_118 ) ;
V_179 = F_105 ( V_177 , & V_85 , & V_178 ) ;
if ( ! V_179 )
return - V_160 ;
if ( V_178 < V_177 ) {
F_111 ( V_179 , V_85 , V_178 ) ;
return - V_160 ;
}
V_119 = F_116 ( V_159 ) ;
if ( ! V_119 ) {
F_111 ( V_179 , V_85 , V_178 ) ;
return - V_160 ;
}
V_118 -> V_336 = V_179 ;
V_118 -> V_338 = V_85 ;
V_118 -> V_337 = V_178 ;
V_118 -> V_119 = V_119 ;
for ( V_182 = 0 ; V_182 < V_177 ; V_182 ++ ) {
V_118 -> V_304 [ V_182 ] -> V_74 = V_85 + V_182 ;
V_238 = F_222 ( V_118 -> V_304 [ V_182 ] ) ;
if ( V_238 )
break;
V_238 = F_180 ( V_284 , V_293 + V_182 ,
V_118 -> V_304 [ V_182 ] -> V_74 ) ;
if ( V_238 )
break;
F_185 ( V_284 , V_293 + V_182 , V_182 ,
& V_339 , V_118 -> V_304 [ V_182 ] ) ;
F_109 ( V_182 , V_179 ) ;
}
if ( V_238 ) {
if ( V_182 > 0 )
F_224 ( V_284 , V_293 , V_182 - 1 ) ;
F_111 ( V_179 , V_85 , V_178 ) ;
F_119 ( V_119 ) ;
}
return V_238 ;
}
static void F_226 ( struct V_283 * V_284 ,
struct V_109 * V_110 )
{
struct V_61 * V_64 = F_63 ( V_110 ) ;
V_64 -> V_102 = F_190 ( V_132 ) ;
F_227 ( V_64 , true ) ;
F_61 ( V_64 ) ;
}
static void F_228 ( struct V_283 * V_284 ,
struct V_109 * V_110 )
{
struct V_61 * V_64 = F_63 ( V_110 ) ;
F_227 ( V_64 , false ) ;
}
static int F_229 ( void T_9 * V_85 )
{
T_1 V_88 = 1000000 ;
T_1 V_11 ;
V_11 = F_43 ( V_85 + V_340 ) ;
if ( ( V_11 & V_341 ) && ! ( V_11 & V_342 ) )
return 0 ;
V_11 &= ~ ( V_342 | V_343 ) ;
F_49 ( V_11 , V_85 + V_340 ) ;
while ( 1 ) {
V_11 = F_43 ( V_85 + V_340 ) ;
if ( V_11 & V_341 )
return 0 ;
V_88 -- ;
if ( ! V_88 )
return - V_344 ;
F_46 () ;
F_47 ( 1 ) ;
}
}
static void T_12 F_230 ( void * V_146 )
{
struct V_5 * V_6 = V_146 ;
V_6 -> V_91 |= V_239 ;
}
static void T_12 F_231 ( void * V_146 )
{
struct V_5 * V_6 = V_146 ;
V_6 -> V_91 |= V_135 ;
}
static void T_12 F_232 ( void * V_146 )
{
struct V_5 * V_6 = V_146 ;
V_6 -> V_280 = 16 ;
}
static void F_233 ( struct V_5 * V_6 )
{
T_1 V_345 = F_43 ( V_6 -> V_85 + V_346 ) ;
F_234 ( V_345 , V_347 , V_6 ) ;
}
static int F_235 ( struct V_348 * V_349 , struct V_5 * V_6 )
{
struct V_283 * V_350 ;
struct V_287 * V_153 ;
V_153 = F_88 ( sizeof( * V_153 ) , V_159 ) ;
if ( ! V_153 )
return - V_160 ;
V_350 = F_236 ( V_349 , & V_351 , V_6 ) ;
if ( ! V_350 ) {
F_97 ( V_153 ) ;
return - V_160 ;
}
V_350 -> V_296 = V_352 ;
F_237 ( V_350 , V_353 ) ;
V_350 -> V_91 |= V_354 ;
V_153 -> V_355 = & V_356 ;
V_153 -> V_146 = V_6 ;
V_350 -> V_335 = V_153 ;
return 0 ;
}
static int F_238 ( void )
{
struct V_5 * V_6 ;
T_1 V_18 ;
int V_357 ;
if ( V_122 -> V_291 ) {
F_104 ( L_22 ) ;
return 0 ;
}
V_6 = F_56 ( & V_104 , struct V_5 , V_105 ) ;
V_357 = F_167 ( V_137 ) ;
V_292 . V_304 = F_88 ( sizeof( * V_292 . V_304 ) * V_357 ,
V_159 ) ;
if ( ! V_292 . V_304 ) {
F_115 ( L_23 ) ;
return - V_160 ;
}
V_18 = F_239 ( V_6 -> V_234 - 1 , 0 ) ;
V_292 . V_37 = F_165 ( V_6 , V_18 , V_357 , false ) ;
if ( ! V_292 . V_37 ) {
F_97 ( V_292 . V_304 ) ;
F_115 ( L_24 ) ;
return - V_160 ;
}
F_112 ( V_357 > V_292 . V_37 -> V_38 ) ;
F_240 ( & V_292 . V_274 ) ;
V_292 . V_305 = 0 ;
F_104 ( L_25 ,
V_18 , V_292 . V_37 -> V_38 ) ;
return 0 ;
}
static int T_6 F_241 ( struct V_358 * V_359 ,
void T_9 * V_360 )
{
int V_361 ;
T_1 V_362 ;
V_361 = F_175 ( & V_103 , V_363 ) ;
if ( V_361 >= V_363 ) {
F_115 ( L_26 ,
& V_359 -> V_364 ) ;
return - V_134 ;
}
V_362 = F_43 ( V_360 + V_340 ) ;
V_362 &= ~ V_365 ;
V_362 |= V_361 << V_366 ;
F_49 ( V_362 , V_360 + V_340 ) ;
V_362 = F_43 ( V_360 + V_340 ) ;
if ( ( V_362 & V_365 ) != ( V_361 << V_366 ) ) {
V_361 = V_362 & V_365 ;
V_361 >>= V_366 ;
}
if ( F_242 ( V_361 , & V_103 ) ) {
F_115 ( L_27 ,
& V_359 -> V_364 , V_361 ) ;
return - V_134 ;
}
return V_361 ;
}
static int T_6 F_243 ( struct V_358 * V_359 ,
struct V_348 * V_349 , int V_136 )
{
struct V_5 * V_6 ;
void T_9 * V_360 ;
T_1 V_11 , V_362 ;
T_2 V_193 , V_204 , V_236 ;
int V_238 ;
V_360 = F_244 ( V_359 -> V_364 , F_245 ( V_359 ) ) ;
if ( ! V_360 ) {
F_132 ( L_28 , & V_359 -> V_364 ) ;
return - V_160 ;
}
V_11 = F_43 ( V_360 + V_367 ) & V_368 ;
if ( V_11 != 0x30 && V_11 != 0x40 ) {
F_132 ( L_29 , & V_359 -> V_364 ) ;
V_238 = - V_369 ;
goto V_370;
}
V_238 = F_229 ( V_360 ) ;
if ( V_238 ) {
F_132 ( L_30 , & V_359 -> V_364 ) ;
goto V_370;
}
F_104 ( L_31 , V_359 ) ;
V_6 = F_88 ( sizeof( * V_6 ) , V_159 ) ;
if ( ! V_6 ) {
V_238 = - V_160 ;
goto V_370;
}
F_240 ( & V_6 -> V_274 ) ;
F_169 ( & V_6 -> V_105 ) ;
F_169 ( & V_6 -> V_281 ) ;
V_236 = F_140 ( V_360 + V_237 ) ;
V_6 -> V_85 = V_360 ;
V_6 -> V_142 = V_359 -> V_364 ;
V_6 -> V_280 = F_246 ( V_236 ) ;
V_6 -> V_108 = ! ! ( V_236 & V_371 ) ;
if ( V_6 -> V_108 ) {
if ( ! ( V_236 & V_372 ) ) {
V_238 = F_241 ( V_359 , V_360 ) ;
if ( V_238 < 0 )
goto V_373;
F_104 ( L_32 ,
& V_359 -> V_364 , V_238 ) ;
} else {
F_104 ( L_33 , & V_359 -> V_364 ) ;
}
}
V_6 -> V_136 = V_136 ;
V_6 -> V_81 = ( void * ) F_133 ( V_159 | V_208 ,
F_118 ( V_374 ) ) ;
if ( ! V_6 -> V_81 ) {
V_238 = - V_160 ;
goto V_373;
}
V_6 -> V_84 = V_6 -> V_81 ;
F_233 ( V_6 ) ;
V_238 = F_139 ( V_6 ) ;
if ( V_238 )
goto V_375;
V_238 = F_142 ( V_6 ) ;
if ( V_238 )
goto V_376;
V_193 = ( F_25 ( V_6 -> V_81 ) |
V_377 |
V_378 |
( V_374 / V_218 - 1 ) |
V_379 ) ;
F_247 ( V_193 , V_6 -> V_85 + V_380 ) ;
V_204 = F_248 ( V_6 -> V_85 + V_380 ) ;
if ( ( V_204 ^ V_193 ) & V_381 ) {
if ( ! ( V_204 & V_381 ) ) {
V_193 &= ~ ( V_381 |
V_382 ) ;
V_193 |= V_383 ;
F_247 ( V_193 , V_6 -> V_85 + V_380 ) ;
}
F_104 ( L_34 ) ;
V_6 -> V_91 |= V_92 ;
}
F_249 ( 0 , V_6 -> V_85 + V_90 ) ;
V_362 = F_43 ( V_6 -> V_85 + V_340 ) ;
V_362 |= V_342 ;
if ( V_6 -> V_108 )
V_362 |= V_343 ;
F_49 ( V_362 , V_6 -> V_85 + V_340 ) ;
V_238 = F_235 ( V_349 , V_6 ) ;
if ( V_238 )
goto V_376;
F_107 ( & V_266 ) ;
F_170 ( & V_6 -> V_105 , & V_104 ) ;
F_110 ( & V_266 ) ;
return 0 ;
V_376:
F_138 ( V_6 ) ;
V_375:
F_120 ( ( unsigned long ) V_6 -> V_81 , F_118 ( V_374 ) ) ;
V_373:
F_97 ( V_6 ) ;
V_370:
F_250 ( V_360 ) ;
F_115 ( L_35 , & V_359 -> V_364 , V_238 ) ;
return V_238 ;
}
static bool F_251 ( void )
{
return ! ! ( F_140 ( F_146 () + V_272 ) & V_384 ) ;
}
int F_252 ( void )
{
if ( ! F_253 ( & V_104 ) ) {
if ( ! F_251 () ) {
F_104 ( L_36 , F_148 () ) ;
return - V_211 ;
}
F_145 () ;
F_154 () ;
}
return 0 ;
}
static int T_6 F_254 ( struct V_268 * V_385 )
{
struct V_268 * V_386 ;
struct V_358 V_359 ;
for ( V_386 = F_255 ( V_385 , V_387 ) ; V_386 ;
V_386 = F_255 ( V_386 , V_387 ) ) {
if ( ! F_256 ( V_386 , L_37 ) ) {
F_132 ( L_38 ,
V_386 ) ;
continue;
}
if ( F_257 ( V_386 , 0 , & V_359 ) ) {
F_132 ( L_39 , V_386 ) ;
continue;
}
F_243 ( & V_359 , & V_386 -> V_297 , F_156 ( V_386 ) ) ;
}
return 0 ;
}
static int T_6 F_258 ( T_1 V_388 )
{
int V_182 ;
for ( V_182 = 0 ; V_182 < V_389 ; V_182 ++ ) {
if ( V_388 == V_390 [ V_182 ] . V_388 )
return V_390 [ V_182 ] . V_136 ;
}
return V_270 ;
}
static int T_6 F_259 ( struct V_391 * V_392 ,
const unsigned long V_393 )
{
return 0 ;
}
static int T_6 F_260 ( struct V_391 * V_392 ,
const unsigned long V_393 )
{
int V_385 ;
struct V_394 * V_395 ;
V_395 = (struct V_394 * ) V_392 ;
if ( ! V_395 )
return - V_134 ;
if ( V_395 -> V_392 . V_396 < sizeof( * V_395 ) ) {
F_115 ( L_40 ,
V_395 -> V_392 . V_396 ) ;
return - V_134 ;
}
V_385 = F_261 ( V_395 -> V_397 ) ;
if ( V_385 == V_270 || V_385 >= V_398 ) {
F_115 ( L_41 , V_385 ) ;
return 0 ;
}
V_390 [ V_389 ] . V_136 = V_385 ;
V_390 [ V_389 ] . V_388 = V_395 -> V_388 ;
V_389 ++ ;
F_104 ( L_42 ,
V_395 -> V_397 , V_395 -> V_388 , V_385 ) ;
return 0 ;
}
static void T_6 F_262 ( void )
{
int V_88 ;
V_88 = F_263 ( V_399 ,
sizeof( struct V_400 ) ,
V_401 ,
F_259 , 0 ) ;
if ( V_88 <= 0 )
return;
V_390 = F_264 ( V_88 * sizeof( struct V_402 ) ,
V_159 ) ;
if ( ! V_390 ) {
F_132 ( L_43 ) ;
return;
}
F_263 ( V_399 ,
sizeof( struct V_400 ) ,
V_401 ,
F_260 , 0 ) ;
}
static void T_6 F_265 ( void )
{
F_97 ( V_390 ) ;
}
static void T_6 F_262 ( void ) { }
static int T_6 F_258 ( T_1 V_388 ) { return V_270 ; }
static void T_6 F_265 ( void ) { }
static int T_6 F_266 ( struct V_391 * V_392 ,
const unsigned long V_393 )
{
struct V_403 * V_404 ;
struct V_348 * V_405 ;
struct V_358 V_359 ;
int V_238 ;
V_404 = (struct V_403 * ) V_392 ;
memset ( & V_359 , 0 , sizeof( V_359 ) ) ;
V_359 . V_364 = V_404 -> V_406 ;
V_359 . V_393 = V_404 -> V_406 + V_407 - 1 ;
V_359 . V_91 = V_408 ;
V_405 = F_267 ( ( void * ) V_404 -> V_406 ) ;
if ( ! V_405 ) {
F_115 ( L_44 ,
& V_359 . V_364 ) ;
return - V_160 ;
}
V_238 = F_268 ( V_404 -> V_409 , V_405 ) ;
if ( V_238 ) {
F_115 ( L_45 ,
& V_359 . V_364 , V_404 -> V_409 ) ;
goto V_410;
}
V_238 = F_243 ( & V_359 , V_405 ,
F_258 ( V_404 -> V_409 ) ) ;
if ( ! V_238 )
return 0 ;
F_269 ( V_404 -> V_409 ) ;
V_410:
F_270 ( V_405 ) ;
return V_238 ;
}
static void T_6 F_271 ( void )
{
F_262 () ;
F_272 ( V_411 ,
F_266 , 0 ) ;
F_265 () ;
}
static void T_6 F_271 ( void ) { }
int T_6 F_273 ( struct V_348 * V_349 , struct V_412 * V_412 ,
struct V_283 * V_413 )
{
struct V_268 * V_414 ;
struct V_5 * V_6 ;
bool V_415 = false ;
int V_238 ;
V_352 = V_413 ;
V_414 = F_274 ( V_349 ) ;
if ( V_414 )
F_254 ( V_414 ) ;
else
F_271 () ;
if ( F_253 ( & V_104 ) ) {
F_132 ( L_46 ) ;
return - V_211 ;
}
V_122 = V_412 ;
V_238 = F_121 () ;
if ( V_238 )
return V_238 ;
F_59 (its, &its_nodes, entry)
V_415 |= V_6 -> V_108 ;
if ( V_415 & V_412 -> V_416 ) {
if ( F_238 () ||
F_275 ( V_413 , & V_417 ) ) {
V_412 -> V_416 = false ;
F_115 ( L_47 ) ;
}
}
return 0 ;
}
