static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( ! V_3 -> V_4 [ V_5 ] . V_7 ) {
V_4 = & V_3 -> V_4 [ V_5 ] ;
break;
}
}
return V_4 ;
}
static int F_2 ( struct V_2 * V_3 )
{
int V_5 , V_8 = 0 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_3 -> V_4 [ V_5 ] . V_7 )
V_8 ++ ;
}
return V_8 ;
}
static void F_3 ( struct V_2 * V_3 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( ! V_3 -> V_4 [ V_5 ] . V_7 )
continue;
if ( V_3 -> V_4 [ V_5 ] . V_9 == V_10 ||
V_3 -> V_4 [ V_5 ] . V_9 == V_11 ) {
V_3 -> V_12 = 1 ;
break;
}
}
}
static enum V_13 F_4 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
int V_16 = 0 , V_5 = 0 ;
if ( ! V_3 || ! V_15 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
if ( V_3 -> V_4 [ V_15 -> V_18 ] . V_9 != V_19 ) {
F_5 ( L_2 ) ;
return V_20 ;
}
if ( V_15 -> V_21 . V_22 . V_23 . V_24 == V_25 ) {
V_3 -> V_4 [ V_15 -> V_18 ] . V_9 = V_15 -> V_21 . V_22 . V_23 . V_24 ;
return V_26 ;
}
if ( V_3 -> V_27 != V_28 ) {
F_5 ( L_3 , V_3 -> V_27 ) ;
return V_20 ;
}
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_3 -> V_4 [ V_5 ] . V_9 == V_10 ||
V_3 -> V_4 [ V_5 ] . V_9 == V_11 ) {
F_5 ( L_4
L_5 ) ;
return V_20 ;
}
}
V_3 -> V_29 = 0 ;
V_3 -> V_4 [ V_15 -> V_18 ] . V_9 = V_15 -> V_21 . V_22 . V_23 . V_24 ;
V_16 = F_6 ( V_3 -> V_30 , V_31 ) ;
if ( V_16 )
return V_32 ;
return F_7 ( & V_3 -> V_33 ) ;
}
static enum V_13 F_8 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
if ( ! V_3 || ! V_15 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
V_15 -> V_21 . V_22 . V_34 . V_35 = V_36 ;
V_15 -> V_21 . V_22 . V_34 . V_37 = V_38 ;
V_15 -> V_21 . V_22 . V_34 . V_39 = V_40 ;
return V_26 ;
}
static enum V_13 F_9 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
if ( ! V_3 || ! V_15 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
F_10 ( V_3 -> V_30 , 0 , 2 ,
( V_41 * ) & V_15 -> V_21 . V_22 . V_42 . V_43 ) ;
F_10 ( V_3 -> V_30 , 2 , 2 ,
( V_41 * ) & V_15 -> V_21 . V_22 . V_42 . V_44 ) ;
F_10 ( V_3 -> V_30 , 8 , 1 ,
( V_41 * ) & V_15 -> V_21 . V_22 . V_42 . V_45 ) ;
return V_26 ;
}
static enum V_13 F_11 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
if ( ! V_3 || ! V_15 )
return V_17 ;
V_15 -> V_21 . V_22 . V_46 . V_47 = F_12 ( V_3 -> V_30 ,
V_15 -> V_21 . V_22 . V_46 . V_48 ) ;
return V_26 ;
}
static enum V_13 F_13 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
if ( ! V_3 || ! V_15 )
return V_17 ;
F_14 ( V_3 -> V_30 , V_15 -> V_21 . V_22 . V_46 . V_48 ,
V_15 -> V_21 . V_22 . V_46 . V_47 ) ;
return V_26 ;
}
static enum V_13 F_15 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
if ( ! V_3 || ! V_15 )
return V_17 ;
V_15 -> V_21 . V_22 . V_46 . V_47 = F_16 ( V_3 -> V_30 ,
V_15 -> V_21 . V_22 . V_46 . V_48 ) ;
return V_26 ;
}
static enum V_13 F_17 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
if ( ! V_3 || ! V_15 )
return V_17 ;
F_18 ( V_3 -> V_30 , V_15 -> V_21 . V_22 . V_46 . V_48 ,
V_15 -> V_21 . V_22 . V_46 . V_47 ) ;
return V_26 ;
}
static enum V_13 F_19 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
enum V_13 V_49 = V_26 ;
if ( ! V_3 || ! V_15 || ! V_15 -> V_50 )
return V_17 ;
if ( V_15 -> V_21 . V_22 . V_51 . V_52 > ( V_15 -> V_53 / 4 ) ) {
F_5 ( L_6 ) ;
return V_17 ;
}
V_49 = F_20 ( V_3 -> V_30 , V_15 -> V_21 . V_22 . V_51 . V_54 ,
V_15 -> V_21 . V_22 . V_51 . V_52 ,
( V_41 * ) V_15 -> V_50 ) ;
return V_49 ;
}
static enum V_13 F_21 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
enum V_13 V_49 = V_26 ;
if ( ! V_3 || ! V_15 || ! V_15 -> V_50 )
return V_17 ;
if ( V_15 -> V_21 . V_22 . V_51 . V_52 > ( V_15 -> V_53 / 4 ) ) {
F_5 ( L_6 ) ;
return V_17 ;
}
V_49 = F_22 ( V_3 -> V_30 , V_15 -> V_21 . V_22 . V_51 . V_54 ,
V_15 -> V_21 . V_22 . V_51 . V_52 ,
( V_41 * ) V_15 -> V_50 ) ;
return V_49 ;
}
static enum V_13 F_23 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
V_41 V_55 , V_56 , V_57 , V_58 ;
enum V_13 V_49 = V_26 ;
V_41 * V_59 ;
if ( ! V_3 || ! V_15 )
return V_17 ;
V_59 = ( V_41 * ) V_15 -> V_21 . V_22 . V_60 . V_61 ;
V_57 = V_15 -> V_21 . V_22 . V_60 . V_48 ;
V_58 = V_15 -> V_21 . V_22 . V_60 . V_62 ;
if ( V_58 <= 4 )
return F_10 ( V_3 -> V_30 , V_57 , V_58 , V_59 ) ;
V_58 = 4 ;
V_56 = V_15 -> V_21 . V_22 . V_60 . V_62 / V_58 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_49 = F_10 ( V_3 -> V_30 , V_57 , V_58 , & V_59 [ V_55 ] ) ;
if ( V_49 != V_26 ) {
F_5 ( L_7 , V_49 ) ;
return V_49 ;
}
V_57 += V_58 ;
}
return V_49 ;
}
static enum V_13 F_24 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
V_41 V_55 , V_56 , V_57 , V_58 ;
enum V_13 V_49 = V_26 ;
V_41 * V_59 ;
if ( ! V_3 || ! V_15 )
return V_17 ;
V_59 = ( V_41 * ) V_15 -> V_21 . V_22 . V_60 . V_61 ;
V_57 = V_15 -> V_21 . V_22 . V_60 . V_48 ;
V_58 = V_15 -> V_21 . V_22 . V_60 . V_62 ;
if ( V_58 <= 4 )
return F_25 ( V_3 -> V_30 , V_57 , V_58 , V_59 [ 0 ] ) ;
V_58 = 4 ;
V_56 = V_15 -> V_21 . V_22 . V_60 . V_62 / V_58 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_49 = F_25 ( V_3 -> V_30 , V_57 , V_58 , V_59 [ V_55 ] ) ;
if ( V_49 != V_26 ) {
F_5 ( L_8 , V_49 ) ;
return V_49 ;
}
V_57 += V_58 ;
}
return V_49 ;
}
static enum V_13 F_26 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
enum V_13 V_49 = V_26 ;
if ( ! V_3 || ! V_15 || ! V_15 -> V_50 || ! V_15 -> V_53 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
if ( V_3 -> V_27 != V_28 ) {
F_5 ( L_3 , V_3 -> V_27 ) ;
return V_20 ;
}
V_49 = F_27 ( V_3 -> V_30 , ( V_63 * ) V_15 -> V_50 ,
V_15 -> V_53 ) ;
if ( V_49 != V_26 )
F_5 ( L_9 , V_49 ) ;
else
V_3 -> V_27 |= V_64 ;
return V_49 ;
}
static enum V_13 F_28 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
enum V_13 V_49 ;
V_41 * V_65 ;
if ( ! ( V_3 -> V_27 & V_64 ) ) {
F_5 ( L_3 , V_3 -> V_27 ) ;
return V_20 ;
}
V_65 = V_15 -> V_21 . V_22 . V_66 . V_65 ;
if ( V_65 [ 0 ] == V_67 ) {
if ( ! V_65 [ 3 ] ) {
V_3 -> V_27 &= ~ V_68 ;
F_29 ( & V_3 -> V_33 ) ;
}
} else if ( V_65 [ 0 ] == V_69 ) {
F_30 ( V_70 , L_10 ) ;
if ( V_65 [ 3 ] )
V_3 -> V_29 = 1 ;
}
V_49 = F_31 ( & V_3 -> V_33 , & V_15 -> V_21 . V_22 . V_66 ) ;
if ( V_49 != V_26 ) {
F_30 ( V_70 , L_11 , V_65 [ 0 ] ) ;
return V_49 ;
}
if ( V_65 [ 0 ] == V_67 ) {
if ( V_65 [ 3 ] ) {
V_3 -> V_27 |= V_68 ;
F_32 ( & V_3 -> V_33 ) ;
}
}
return V_49 ;
}
static void F_33 ( struct V_71 * V_72 ,
T_1 * V_73 , enum V_13 V_49 )
{
if ( ! V_72 || ! V_73 ) {
F_5 ( L_1 ) ;
return;
}
if ( V_49 == V_74 )
return;
V_72 -> V_75 . V_76 = V_49 ;
V_72 -> V_75 . V_77 = 1 ;
F_34 ( V_73 ) ;
}
static enum V_13 F_35 ( struct V_2 * V_3 )
{
T_1 V_78 ;
int V_16 = 0 ;
if ( V_3 -> V_27 & V_79 )
return V_74 ;
if ( V_3 -> V_29 ) {
V_3 -> V_29 = 0 ;
return V_80 ;
}
F_36 ( & V_78 ) ;
F_37 ( & V_78 , 0 , 100 , V_16 , 0 ) ;
if ( V_16 == - V_81 )
return V_74 ;
return V_26 ;
}
static enum V_13 F_38 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_71 * V_82 )
{
V_41 V_83 = 0 ;
enum V_13 V_49 = V_26 ;
T_1 V_73 ;
int V_16 = 0 ;
if ( ! V_3 || ! V_15 || ! V_82 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
F_36 ( & V_73 ) ;
V_3 -> V_84 = 0 ;
V_49 = F_39 ( & V_3 -> V_33 , V_82 , F_33 ,
& V_73 , & V_83 ,
V_15 -> V_21 . V_22 . V_85 . V_86 ) ;
while ( V_49 == V_87 ) {
V_49 = F_35 ( V_3 ) ;
if ( V_49 != V_26 )
break;
V_49 = F_39 ( & V_3 -> V_33 , V_82 ,
F_33 ,
& V_73 , & V_83 ,
V_15 -> V_21 . V_22 . V_85 . V_86 ) ;
}
if ( V_49 != V_26 ) {
F_30 ( V_88 , L_12 , V_49 ) ;
return V_49 ;
}
if ( V_3 -> V_29 )
V_3 -> V_29 = 0 ;
V_3 -> V_84 = V_83 ;
F_37 ( & V_73 , ( V_82 -> V_75 . V_77 ) , 3000 , V_16 , 0 ) ;
V_3 -> V_84 = 0 ;
if ( ! V_16 ) {
return V_82 -> V_75 . V_76 ;
} else if ( V_16 == - V_89 ) {
F_30 ( V_88 , L_13 ) ;
V_49 = V_90 ;
} else if ( V_16 == - V_81 ) {
F_30 ( V_88 , L_14 ) ;
V_49 = V_74 ;
} else {
V_49 = V_91 ;
}
F_40 ( & V_3 -> V_33 , V_83 ) ;
return V_49 ;
}
static enum V_13 F_41 ( bool V_92 , void * V_93 , V_41 V_94 ,
V_41 V_95 , bool V_96 )
{
if ( ! V_93 || ! V_94 ) {
F_5 ( L_15 ,
( ( V_92 ) ? L_16 : L_17 ) , V_93 , V_94 ) ;
return V_17 ;
}
if ( ( ( V_97 ) V_93 ) & 0x03 ) {
F_5 ( L_18 ,
( ( V_92 ) ? L_16 : L_17 ) , V_93 ) ;
return V_98 ;
}
if ( V_92 )
return V_26 ;
if ( ! V_96 && ! V_95 ) {
F_5 ( L_19 ) ;
return V_17 ;
}
if ( V_96 && V_95 ) {
F_5 ( L_20 ) ;
return V_17 ;
}
return V_26 ;
}
static enum V_13 F_42 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
void * V_93 ;
V_41 V_94 ;
struct V_71 * V_72 = NULL ;
enum V_13 V_49 = V_26 ;
if ( ! V_3 || ! V_15 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
V_93 = V_15 -> V_21 . V_22 . V_85 . V_99 ;
V_94 = V_15 -> V_21 . V_22 . V_85 . V_100 ;
V_49 = F_41 ( 1 , V_93 , V_94 , 0 , 0 ) ;
if ( V_49 != V_26 )
return V_49 ;
V_49 = F_43 ( V_3 -> V_30 , V_93 , V_94 , 0 , 0 , 1 , & V_72 ) ;
if ( V_49 != V_26 ) {
F_5 ( L_21 , V_49 ) ;
return V_49 ;
}
if ( ! V_72 )
return V_32 ;
V_49 = F_38 ( V_3 , V_15 , V_72 ) ;
F_44 ( V_3 -> V_30 , V_72 ) ;
return V_49 ;
}
static enum V_13 F_45 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
void * V_93 ;
V_41 V_94 , V_95 ;
bool V_96 ;
struct V_71 * V_72 = NULL ;
enum V_13 V_49 = V_26 ;
if ( ! V_3 || ! V_15 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
V_93 = V_15 -> V_21 . V_22 . V_101 . V_102 ;
V_94 = V_15 -> V_21 . V_22 . V_101 . V_103 ;
V_95 = V_15 -> V_21 . V_22 . V_101 . V_104 ;
V_96 = V_15 -> V_21 . V_22 . V_101 . V_105 ;
V_49 = F_41 ( 0 , V_93 , V_94 , V_95 , V_96 ) ;
if ( V_49 != V_26 )
return V_49 ;
V_49 = F_43 ( V_3 -> V_30 , V_93 , V_94 , V_95 ,
V_96 , 0 , & V_72 ) ;
if ( V_49 != V_26 ) {
F_5 ( L_21 , V_49 ) ;
return V_49 ;
}
if ( ! V_72 )
return V_32 ;
V_49 = F_46 ( & V_3 -> V_33 , V_72 , ( V_3 -> V_27 == V_106 ) ) ;
if ( ( V_49 != V_26 ) && ( V_49 != V_87 ) ) {
F_44 ( V_3 -> V_30 , V_72 ) ;
return V_49 ;
}
return V_26 ;
}
static enum V_13 F_47 ( struct V_2 * V_3 ,
struct V_71 * V_82 )
{
enum V_13 V_49 = V_26 ;
V_49 = F_46 ( & V_3 -> V_33 , V_82 , 0 ) ;
if ( V_49 != V_26 )
return V_49 ;
V_3 -> V_27 |= V_107 ;
if ( V_3 -> V_27 == V_106 )
V_49 = F_48 ( & V_3 -> V_33 ) ;
return V_49 ;
}
static enum V_13 F_49 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_71 * V_82 = NULL ;
enum V_13 V_49 = V_26 ;
struct V_108 * V_109 ;
if ( ! V_3 || ! V_15 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
if ( ! ( V_3 -> V_27 & V_110 ) ) {
F_30 ( V_88 , L_22 , V_3 -> V_27 ) ;
return V_20 ;
}
V_109 = & V_15 -> V_21 . V_22 . V_111 ;
V_49 = F_50 ( & V_3 -> V_33 , & V_109 -> V_112 , & V_82 ) ;
if ( V_49 != V_26 )
return ( V_3 -> V_27 & V_79 ) ? V_74 : V_49 ;
V_109 -> V_113 = V_82 -> V_75 . V_114 ;
if ( V_109 -> V_113 & V_115 )
return F_47 ( V_3 , V_82 ) ;
V_109 -> V_116 . V_102 = V_82 -> V_75 . V_117 ;
V_109 -> V_116 . V_103 = V_82 -> V_75 . V_118 ;
V_109 -> V_116 . V_104 = V_82 -> V_75 . V_119 ;
V_109 -> V_116 . V_105 = V_82 -> V_75 . V_120 ;
V_109 -> V_116 . V_121 = V_82 -> V_75 . V_122 ;
V_109 -> V_116 . V_123 = V_82 -> V_75 . V_124 ;
F_44 ( V_3 -> V_30 , V_82 ) ;
return V_26 ;
}
static enum V_13 F_51 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
V_3 -> V_27 |= V_110 ;
if ( V_3 -> V_27 == V_106 )
return F_48 ( & V_3 -> V_33 ) ;
return V_26 ;
}
static enum V_13 F_52 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_71 * V_82 = NULL ;
enum V_13 V_49 = V_26 ;
struct V_108 * V_109 ;
V_41 V_8 ;
if ( ! V_3 || ! V_15 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
if ( ! ( V_3 -> V_27 & V_110 ) )
return V_20 ;
if ( ! ( V_3 -> V_27 & V_106 ) )
return F_53 ( & V_3 -> V_33 ) ;
V_3 -> V_27 &= ~ ( V_110 | V_107 ) ;
V_109 = & V_15 -> V_21 . V_22 . V_111 ;
for ( V_8 = 0 ; V_8 < V_125 ; V_8 ++ ) {
V_49 = F_50 ( & V_3 -> V_33 , & V_109 -> V_112 , & V_82 ) ;
if ( V_49 != V_26 )
break;
F_44 ( V_3 -> V_30 , V_82 ) ;
}
return F_53 ( & V_3 -> V_33 ) ;
}
static enum V_13 F_54 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_126 * V_127 ;
struct V_128 V_129 ;
if ( ! V_3 || ! V_15 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
V_128 ( & V_3 -> V_33 , & V_129 ) ;
V_127 = & V_15 -> V_21 . V_22 . V_130 ;
V_127 -> V_131 = V_129 . V_132 ;
V_127 -> V_133 = V_129 . V_134 ;
V_127 -> V_135 = V_129 . V_136 ;
V_127 -> V_137 = V_129 . V_136 + V_129 . V_138 ;
V_127 -> V_139 = V_129 . V_140 ;
V_127 -> V_141 = V_129 . V_140 -
V_129 . V_142 ;
V_127 -> V_143 = V_129 . V_144 ;
V_127 -> V_145 = V_129 . V_146 ;
if ( V_3 -> V_12 )
V_127 -> V_12 = 1 ;
if ( V_3 -> V_27 & V_68 )
V_127 -> V_147 = 1 ;
return V_26 ;
}
static enum V_13 F_55 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
V_128 ( & V_3 -> V_33 , NULL ) ;
return V_26 ;
}
static enum V_13 F_56 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_148 * clock ;
V_41 V_149 ;
enum V_13 V_49 = V_26 ;
if ( ! V_3 || ! V_15 ) {
F_5 ( L_1 ) ;
return V_17 ;
}
clock = & V_15 -> V_21 . V_22 . V_150 ;
V_149 = V_3 -> V_33 . V_151 ;
V_3 -> V_33 . V_151 = clock -> V_152 ;
if ( V_3 -> V_27 & V_106 ) {
V_49 = F_57 ( & V_3 -> V_33 ) ;
if ( V_49 == V_153 )
V_3 -> V_33 . V_151 = V_149 ;
}
clock -> V_152 = V_3 -> V_33 . V_151 ;
return V_49 ;
}
enum V_13 F_58 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
enum V_13 V_49 = V_26 ;
if ( ! V_3 || ! V_15 ) {
F_5 ( L_23 ) ;
return V_32 ;
}
if ( V_3 -> V_27 & V_79 )
return V_26 ;
if ( V_3 -> V_27 == V_28 ) {
F_30 ( V_88 , L_24 ) ;
return V_26 ;
}
V_3 -> V_27 |= V_79 ;
F_3 ( V_3 ) ;
if ( V_3 -> V_27 & V_110 ) {
V_49 = F_52 ( V_3 , V_15 ) ;
if ( V_49 != V_26 )
return V_49 ;
}
if ( V_3 -> V_84 ) {
V_49 = F_40 ( & V_3 -> V_33 , V_3 -> V_84 ) ;
if ( V_49 != V_26 )
return V_49 ;
}
V_49 = F_59 ( & V_3 -> V_33 ) ;
if ( V_49 != V_26 )
return V_49 ;
F_30 ( V_88 , L_25 ) ;
return V_26 ;
}
enum V_13 F_60 ( struct V_2 * V_3 )
{
F_30 ( V_88 , L_26 , V_3 -> V_27 ) ;
F_3 ( V_3 ) ;
return V_26 ;
}
enum V_13 F_61 ( struct V_2 * V_3 ,
struct V_1 * * V_154 )
{
struct V_1 * V_155 ;
if ( ! V_3 || ! V_154 ) {
F_5 ( L_27 ) ;
return V_17 ;
}
V_155 = F_1 ( V_3 ) ;
if ( ! V_155 ) {
F_30 ( V_70 , L_28 ) ;
return V_87 ;
}
F_30 ( V_70 , L_29 , V_155 -> V_156 ) ;
F_62 ( & V_3 -> V_33 , V_3 -> V_30 ) ;
V_155 -> V_7 = 1 ;
* V_154 = V_155 ;
return V_26 ;
}
enum V_13 F_63 ( struct V_2 * V_3 , struct V_1 * V_155 )
{
V_41 V_9 = V_155 -> V_9 ;
V_3 -> V_4 [ V_155 -> V_156 ] . V_9 = V_19 ;
V_3 -> V_4 [ V_155 -> V_156 ] . V_7 = 0 ;
V_3 -> V_29 = 1 ;
V_3 -> V_12 = 0 ;
F_30 ( V_70 , L_30 , V_155 -> V_156 ) ;
if ( ( V_9 == V_10 ) || ( V_9 == V_11 ) ) {
F_64 ( & V_3 -> V_33 ) ;
F_65 ( V_3 -> V_30 ) ;
} else if ( F_2 ( V_3 ) ) {
return V_26 ;
}
F_66 ( & V_3 -> V_33 ) ;
V_3 -> V_27 = V_28 ;
return V_26 ;
}
enum V_13 F_67 ( struct V_2 * V_3 ,
struct V_157 * V_30 )
{
int V_5 = 0 ;
if ( ! V_3 || ! V_30 ) {
F_5 ( L_31 ) ;
return V_17 ;
}
if ( V_3 -> V_30 )
F_30 ( V_88 , L_32 ) ;
V_3 -> V_30 = V_30 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_3 -> V_4 [ V_5 ] . V_156 = V_5 ;
V_3 -> V_4 [ V_5 ] . V_7 = 0 ;
V_3 -> V_4 [ V_5 ] . V_9 = V_19 ;
}
F_62 ( & V_3 -> V_33 , V_3 -> V_30 ) ;
F_66 ( & V_3 -> V_33 ) ;
return V_26 ;
}
enum V_13 F_68 ( struct V_2 * V_3 )
{
F_30 ( V_88 , L_33 ) ;
V_3 -> V_30 = NULL ;
return V_26 ;
}
T_2 F_69 ( struct V_2 * V_3 , V_41 V_65 ,
struct V_1 * V_155 )
{
T_2 V_158 = NULL ;
unsigned int V_5 , V_159 ;
if ( ! V_3 ) {
F_5 ( L_34 , V_65 ) ;
return NULL ;
}
if ( ( V_65 != V_160 ) && ( V_3 -> V_27 & V_79 ) ) {
F_5 ( L_35 , V_65 ) ;
return NULL ;
}
V_159 = sizeof( V_161 ) / sizeof( struct V_162 ) ;
for ( V_5 = 0 ; V_5 < V_159 ; V_5 ++ ) {
if ( V_161 [ V_5 ] . V_163 == V_65 ) {
if ( ( V_155 -> V_9 == V_25 ) &&
( V_161 [ V_5 ] . V_164 ) ) {
F_30 ( V_70 , L_36 , V_65 ) ;
break;
}
V_158 = V_161 [ V_5 ] . V_165 ;
break;
}
}
return V_158 ;
}
bool F_70 ( struct V_2 * V_3 )
{
if ( ! V_3 ) {
F_5 ( L_27 ) ;
return 0 ;
}
return F_71 ( V_3 -> V_30 , & V_3 -> V_33 ) ;
}
