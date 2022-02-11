static T_1 F_1 ( struct V_1 * V_2 , void T_2 * V_3 )
{
if ( V_2 -> V_4 )
return F_2 ( V_3 ) ;
else
return F_3 ( V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_3 V_5 , void T_2 * V_3 )
{
if ( V_2 -> V_4 )
F_5 ( V_5 , ( void T_2 * ) ( ( unsigned long ) V_3 ^ 0x3 ) ) ;
else
F_5 ( V_5 , V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_4 V_5 , void T_2 * V_3 )
{
if ( V_2 -> V_4 )
F_7 ( V_5 , ( void T_2 * ) ( ( unsigned long ) V_3 ^ 0x2 ) ) ;
else
F_8 ( V_5 , V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_5 , void T_2 * V_3 )
{
if ( V_2 -> V_4 )
F_10 ( V_5 , V_3 ) ;
else
F_11 ( V_5 , V_3 ) ;
}
static struct V_6 * F_12 ( struct V_7 * V_8 )
{
return F_13 ( V_8 , struct V_6 , V_9 . V_8 ) ;
}
static struct V_10 * F_14 ( struct V_11 * V_12 )
{
return F_13 ( V_12 , struct V_10 , V_13 ) ;
}
static void F_15 ( struct V_6 * V_14 )
{
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_1 V_16 = V_14 -> V_9 . V_8 . V_17 ;
F_4 ( V_14 -> V_2 , F_16 ( V_16 ) , V_3 + V_18 ) ;
F_4 ( V_14 -> V_2 , V_16 , V_3 + V_19 ) ;
}
static void F_17 ( struct V_6 * V_14 )
{
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_1 V_16 = V_14 -> V_9 . V_8 . V_17 ;
F_4 ( V_14 -> V_2 , V_16 , V_3 + V_20 ) ;
F_4 ( V_14 -> V_2 , F_18 ( V_16 ) , V_3 + V_21 ) ;
}
static void F_19 ( struct V_6 * V_14 ,
unsigned int V_22 , bool V_23 )
{
T_1 V_16 = V_14 -> V_9 . V_8 . V_17 ;
void T_2 * V_24 ;
unsigned V_25 , V_26 ;
V_25 = V_14 -> V_2 -> V_27 / V_28 ;
V_26 = V_14 -> V_9 . V_8 . V_17 % V_25 ;
V_24 = V_14 -> V_2 -> V_29 [ V_16 / V_25 ] ;
V_22 = F_20 ( V_22 ) ;
if ( V_23 )
F_5 ( V_30 | V_22 , V_24 + V_26 ) ;
else
F_5 ( V_31 , V_24 + V_26 ) ;
}
static unsigned int F_21 ( enum V_32 V_33 )
{
switch ( V_33 ) {
case 1 :
return V_34 | V_35 ;
case 2 :
return V_36 | V_37 ;
case 4 :
return V_38 | V_39 ;
case 8 :
return V_40 | V_41 ;
default:
return V_38 | V_39 ;
}
}
static void F_22 ( struct V_11 * V_13 )
{
struct V_10 * V_42 ;
int V_43 ;
V_42 = F_14 ( V_13 ) ;
for ( V_43 = 0 ; V_43 < V_42 -> V_44 ; V_43 ++ )
F_23 ( V_42 -> V_45 -> V_46 , V_42 -> V_47 [ V_43 ] . V_48 ,
V_42 -> V_47 [ V_43 ] . V_49 ) ;
F_24 ( V_42 ) ;
}
static int F_25 ( struct V_7 * V_8 , enum V_50 V_51 ,
unsigned long V_52 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
struct V_53 * V_54 = ( void * ) V_52 ;
unsigned long V_55 ;
F_26 ( V_56 ) ;
switch ( V_51 ) {
case V_57 :
F_27 ( & V_14 -> V_9 . V_58 , V_55 ) ;
F_17 ( V_14 ) ;
V_14 -> V_59 = NULL ;
F_28 ( & V_14 -> V_9 , & V_56 ) ;
F_29 ( & V_14 -> V_9 . V_58 , V_55 ) ;
F_30 ( & V_14 -> V_9 , & V_56 ) ;
return 0 ;
case V_60 :
V_14 -> V_61 . V_62 = V_54 -> V_63 ;
if ( V_54 -> V_63 == V_64 ) {
V_14 -> V_61 . V_65 = V_54 -> V_66 ;
V_14 -> V_61 . V_33 = V_54 -> V_67 ;
V_14 -> V_61 . V_68 = V_54 -> V_69 ;
V_14 -> V_61 . V_70 = F_21 ( V_54 -> V_67 ) ;
} else if ( V_54 -> V_63 == V_71 ) {
V_14 -> V_61 . V_65 = V_54 -> V_72 ;
V_14 -> V_61 . V_33 = V_54 -> V_73 ;
V_14 -> V_61 . V_68 = V_54 -> V_74 ;
V_14 -> V_61 . V_70 = F_21 ( V_54 -> V_73 ) ;
} else {
return - V_75 ;
}
return 0 ;
case V_76 :
F_27 ( & V_14 -> V_9 . V_58 , V_55 ) ;
if ( V_14 -> V_59 ) {
F_17 ( V_14 ) ;
V_14 -> V_77 = V_78 ;
}
F_29 ( & V_14 -> V_9 . V_58 , V_55 ) ;
return 0 ;
case V_79 :
F_27 ( & V_14 -> V_9 . V_58 , V_55 ) ;
if ( V_14 -> V_59 ) {
F_15 ( V_14 ) ;
V_14 -> V_77 = V_80 ;
}
F_29 ( & V_14 -> V_9 . V_58 , V_55 ) ;
return 0 ;
default:
return - V_81 ;
}
}
static T_5 F_31 ( struct V_6 * V_14 ,
struct V_11 * V_13 , bool V_82 )
{
struct V_10 * V_59 = V_14 -> V_59 ;
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_1 V_16 = V_14 -> V_9 . V_8 . V_17 ;
enum V_83 V_62 = V_14 -> V_61 . V_62 ;
T_6 V_84 , V_85 ;
T_5 V_86 , V_87 ;
int V_43 ;
for ( V_86 = V_43 = 0 ; V_43 < V_14 -> V_59 -> V_44 ; V_43 ++ )
V_86 += F_32 ( V_59 -> V_47 [ V_43 ] . V_48 -> V_88 )
* F_33 ( V_59 -> V_47 [ V_43 ] . V_48 -> V_89 ) ;
if ( ! V_82 )
return V_86 ;
if ( V_62 == V_71 )
V_84 = F_1 ( V_14 -> V_2 , V_3 + F_34 ( V_16 ) ) ;
else
V_84 = F_1 ( V_14 -> V_2 , V_3 + F_35 ( V_16 ) ) ;
for ( V_43 = 0 ; V_43 < V_14 -> V_59 -> V_44 ; V_43 ++ ) {
V_87 = F_32 ( V_59 -> V_47 [ V_43 ] . V_48 -> V_88 )
* F_33 ( V_59 -> V_47 [ V_43 ] . V_48 -> V_89 ) ;
if ( V_62 == V_71 )
V_85 = F_32 ( V_59 -> V_47 [ V_43 ] . V_48 -> V_90 ) ;
else
V_85 = F_32 ( V_59 -> V_47 [ V_43 ] . V_48 -> V_91 ) ;
V_86 -= V_87 ;
if ( V_84 >= V_85 && V_84 < V_85 + V_87 ) {
V_86 += V_85 + V_87 - V_84 ;
break;
}
}
return V_86 ;
}
static enum V_92 F_36 ( struct V_7 * V_8 ,
T_7 V_93 , struct V_94 * V_95 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
struct V_11 * V_13 ;
enum V_92 V_77 ;
unsigned long V_55 ;
V_77 = F_37 ( V_8 , V_93 , V_95 ) ;
if ( V_77 == V_96 )
return V_77 ;
if ( ! V_95 )
return V_14 -> V_77 ;
F_27 ( & V_14 -> V_9 . V_58 , V_55 ) ;
V_13 = F_38 ( & V_14 -> V_9 , V_93 ) ;
if ( V_14 -> V_59 && V_93 == V_14 -> V_59 -> V_13 . V_97 . V_93 )
V_95 -> V_98 = F_31 ( V_14 , V_13 , true ) ;
else if ( V_13 )
V_95 -> V_98 = F_31 ( V_14 , V_13 , false ) ;
else
V_95 -> V_98 = 0 ;
F_29 ( & V_14 -> V_9 . V_58 , V_55 ) ;
return V_14 -> V_77 ;
}
static void F_39 ( struct V_6 * V_14 ,
struct V_99 * V_47 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_1 V_16 = V_14 -> V_9 . V_8 . V_17 ;
F_6 ( V_2 , 0 , V_3 + F_40 ( V_16 ) ) ;
F_9 ( V_2 , F_32 ( V_47 -> V_90 ) , V_3 + F_34 ( V_16 ) ) ;
F_9 ( V_2 , F_32 ( V_47 -> V_91 ) , V_3 + F_35 ( V_16 ) ) ;
F_6 ( V_2 , F_33 ( V_47 -> V_70 ) , V_3 + F_41 ( V_16 ) ) ;
F_6 ( V_2 , F_33 ( V_47 -> V_100 ) , V_3 + F_42 ( V_16 ) ) ;
F_9 ( V_2 , F_32 ( V_47 -> V_88 ) , V_3 + F_43 ( V_16 ) ) ;
F_9 ( V_2 , F_32 ( V_47 -> V_101 ) , V_3 + F_44 ( V_16 ) ) ;
F_6 ( V_2 , F_33 ( V_47 -> V_102 ) , V_3 + F_45 ( V_16 ) ) ;
F_6 ( V_2 , F_33 ( V_47 -> V_89 ) , V_3 + F_46 ( V_16 ) ) ;
F_6 ( V_2 , F_33 ( V_47 -> V_103 ) , V_3 + F_47 ( V_16 ) ) ;
F_9 ( V_2 , F_32 ( V_47 -> V_104 ) , V_3 + F_48 ( V_16 ) ) ;
F_6 ( V_2 , F_33 ( V_47 -> V_105 ) , V_3 + F_40 ( V_16 ) ) ;
}
static inline
void F_49 ( struct V_99 * V_47 , T_1 V_106 , T_1 V_107 ,
T_4 V_70 , T_4 V_100 , T_1 V_88 , T_1 V_101 , T_4 V_102 ,
T_4 V_89 , T_4 V_103 , T_1 V_104 , bool V_108 ,
bool V_109 , bool V_110 )
{
T_4 V_105 = 0 ;
V_47 -> V_90 = F_50 ( V_106 ) ;
V_47 -> V_91 = F_50 ( V_107 ) ;
V_47 -> V_70 = F_51 ( V_70 ) ;
V_47 -> V_100 = F_51 ( F_52 ( V_100 ) ) ;
V_47 -> V_88 = F_50 ( F_53 ( V_88 ) ) ;
V_47 -> V_101 = F_50 ( F_54 ( V_101 ) ) ;
V_47 -> V_102 = F_51 ( F_55 ( V_102 ) ) ;
V_47 -> V_103 = F_51 ( F_56 ( V_103 ) ) ;
V_47 -> V_104 = F_50 ( F_57 ( V_104 ) ) ;
V_47 -> V_89 = F_51 ( F_58 ( V_89 ) ) ;
if ( V_108 )
V_105 |= V_111 ;
if ( V_109 )
V_105 |= V_112 ;
if ( V_110 )
V_105 |= V_113 ;
V_47 -> V_105 = F_51 ( V_105 ) ;
}
static struct V_10 * F_59 ( struct V_6 * V_14 ,
int V_114 )
{
struct V_10 * V_42 ;
int V_43 ;
V_42 = F_60 ( sizeof( * V_42 ) + sizeof( struct V_115 ) * V_114 ,
V_116 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_45 = V_14 ;
V_42 -> V_44 = V_114 ;
for ( V_43 = 0 ; V_43 < V_114 ; V_43 ++ ) {
V_42 -> V_47 [ V_43 ] . V_48 = F_61 ( V_14 -> V_46 ,
V_116 , & V_42 -> V_47 [ V_43 ] . V_49 ) ;
if ( ! V_42 -> V_47 [ V_43 ] . V_48 )
goto V_117;
}
return V_42 ;
V_117:
while ( -- V_43 >= 0 )
F_23 ( V_14 -> V_46 , V_42 -> V_47 [ V_43 ] . V_48 ,
V_42 -> V_47 [ V_43 ] . V_49 ) ;
F_24 ( V_42 ) ;
return NULL ;
}
static struct V_118 * F_62 (
struct V_7 * V_8 , T_6 V_85 , T_5 V_119 ,
T_5 V_120 , enum V_83 V_63 ,
unsigned long V_55 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
struct V_10 * V_42 ;
T_6 V_121 ;
int V_114 , V_43 ;
T_1 V_66 , V_72 , V_122 , V_88 ;
T_4 V_100 , V_103 , V_123 ;
if ( ! F_63 ( V_14 -> V_61 . V_62 ) )
return NULL ;
V_114 = V_119 / V_120 ;
V_42 = F_59 ( V_14 , V_114 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_124 = true ;
V_121 = V_85 ;
V_88 = V_14 -> V_61 . V_33 * V_14 -> V_61 . V_68 ;
V_123 = V_120 / V_88 ;
for ( V_43 = 0 ; V_43 < V_114 ; V_43 ++ ) {
if ( V_121 >= V_85 + V_119 )
V_121 = V_85 ;
V_122 = V_42 -> V_47 [ ( V_43 + 1 ) % V_114 ] . V_49 ;
if ( V_14 -> V_61 . V_62 == V_71 ) {
V_66 = V_121 ;
V_72 = V_14 -> V_61 . V_65 ;
V_100 = V_14 -> V_61 . V_33 ;
V_103 = 0 ;
} else {
V_66 = V_14 -> V_61 . V_65 ;
V_72 = V_121 ;
V_100 = 0 ;
V_103 = V_14 -> V_61 . V_33 ;
}
F_49 ( V_42 -> V_47 [ V_43 ] . V_48 , V_66 , V_72 ,
V_14 -> V_61 . V_70 , V_100 , V_88 , 0 , V_123 ,
V_123 , V_103 , V_122 , true , false , true ) ;
V_121 += V_120 ;
}
return F_64 ( & V_14 -> V_9 , & V_42 -> V_13 , V_55 ) ;
}
static struct V_118 * F_65 (
struct V_7 * V_8 , struct V_125 * V_126 ,
unsigned int V_114 , enum V_83 V_63 ,
unsigned long V_55 , void * V_127 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
struct V_10 * V_42 ;
struct V_125 * V_128 ;
T_1 V_66 , V_72 , V_122 , V_88 ;
T_4 V_100 , V_103 , V_123 ;
int V_43 ;
if ( ! F_63 ( V_14 -> V_61 . V_62 ) )
return NULL ;
V_42 = F_59 ( V_14 , V_114 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_124 = false ;
V_88 = V_14 -> V_61 . V_33 * V_14 -> V_61 . V_68 ;
F_66 (sgl, sg, sg_len, i) {
V_122 = V_42 -> V_47 [ ( V_43 + 1 ) % V_114 ] . V_49 ;
if ( V_14 -> V_61 . V_62 == V_71 ) {
V_66 = F_67 ( V_128 ) ;
V_72 = V_14 -> V_61 . V_65 ;
V_100 = V_14 -> V_61 . V_33 ;
V_103 = 0 ;
} else {
V_66 = V_14 -> V_61 . V_65 ;
V_72 = F_67 ( V_128 ) ;
V_100 = 0 ;
V_103 = V_14 -> V_61 . V_33 ;
}
V_123 = F_68 ( V_128 ) / V_88 ;
if ( V_43 < V_114 - 1 ) {
V_122 = V_42 -> V_47 [ ( V_43 + 1 ) ] . V_49 ;
F_49 ( V_42 -> V_47 [ V_43 ] . V_48 , V_66 ,
V_72 , V_14 -> V_61 . V_70 , V_100 ,
V_88 , 0 , V_123 , V_123 , V_103 , V_122 ,
false , false , true ) ;
} else {
V_122 = 0 ;
F_49 ( V_42 -> V_47 [ V_43 ] . V_48 , V_66 ,
V_72 , V_14 -> V_61 . V_70 , V_100 ,
V_88 , 0 , V_123 , V_123 , V_103 , V_122 ,
true , true , false ) ;
}
}
return F_64 ( & V_14 -> V_9 , & V_42 -> V_13 , V_55 ) ;
}
static void F_69 ( struct V_6 * V_14 )
{
struct V_11 * V_13 ;
V_13 = F_70 ( & V_14 -> V_9 ) ;
if ( ! V_13 )
return;
V_14 -> V_59 = F_14 ( V_13 ) ;
F_39 ( V_14 , V_14 -> V_59 -> V_47 [ 0 ] . V_48 ) ;
F_15 ( V_14 ) ;
V_14 -> V_77 = V_80 ;
}
static T_8 F_71 ( int V_129 , void * V_130 )
{
struct V_1 * V_131 = V_130 ;
unsigned int V_132 , V_16 ;
void T_2 * V_133 ;
struct V_6 * V_14 ;
V_133 = V_131 -> V_15 ;
V_132 = F_1 ( V_131 , V_133 + V_134 ) ;
if ( ! V_132 )
return V_135 ;
for ( V_16 = 0 ; V_16 < V_131 -> V_27 ; V_16 ++ ) {
if ( V_132 & ( 0x1 << V_16 ) ) {
F_4 ( V_131 , F_72 ( V_16 ) ,
V_133 + V_136 ) ;
V_14 = & V_131 -> V_137 [ V_16 ] ;
F_73 ( & V_14 -> V_9 . V_58 ) ;
if ( ! V_14 -> V_59 -> V_124 ) {
F_74 ( & V_14 -> V_59 -> V_13 . V_138 ) ;
F_75 ( & V_14 -> V_59 -> V_13 ) ;
V_14 -> V_59 = NULL ;
V_14 -> V_77 = V_96 ;
} else {
F_76 ( & V_14 -> V_59 -> V_13 ) ;
}
if ( ! V_14 -> V_59 )
F_69 ( V_14 ) ;
F_77 ( & V_14 -> V_9 . V_58 ) ;
}
}
return V_139 ;
}
static T_8 F_78 ( int V_129 , void * V_130 )
{
struct V_1 * V_131 = V_130 ;
unsigned int V_117 , V_16 ;
V_117 = F_1 ( V_131 , V_131 -> V_15 + V_140 ) ;
if ( ! V_117 )
return V_135 ;
for ( V_16 = 0 ; V_16 < V_131 -> V_27 ; V_16 ++ ) {
if ( V_117 & ( 0x1 << V_16 ) ) {
F_17 ( & V_131 -> V_137 [ V_16 ] ) ;
F_4 ( V_131 , F_79 ( V_16 ) ,
V_131 -> V_15 + V_141 ) ;
V_131 -> V_137 [ V_16 ] . V_77 = V_142 ;
}
}
return V_139 ;
}
static T_8 F_80 ( int V_129 , void * V_130 )
{
if ( F_71 ( V_129 , V_130 ) == V_139 )
return V_139 ;
return F_78 ( V_129 , V_130 ) ;
}
static void F_81 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
unsigned long V_55 ;
F_27 ( & V_14 -> V_9 . V_58 , V_55 ) ;
if ( F_82 ( & V_14 -> V_9 ) && ! V_14 -> V_59 )
F_69 ( V_14 ) ;
F_29 ( & V_14 -> V_9 . V_58 , V_55 ) ;
}
static struct V_7 * F_83 ( struct V_143 * V_144 ,
struct V_145 * V_146 )
{
struct V_1 * V_131 = V_146 -> V_147 ;
struct V_7 * V_8 , * V_148 ;
unsigned long V_25 = V_131 -> V_27 / V_28 ;
if ( V_144 -> V_149 != 2 )
return NULL ;
F_84 ( & V_131 -> V_150 ) ;
F_85 (chan, _chan, &fsl_edma->dma_dev.channels, device_node) {
if ( V_8 -> V_151 )
continue;
if ( ( V_8 -> V_17 / V_25 ) == V_144 -> args [ 0 ] ) {
V_8 = F_86 ( V_8 ) ;
if ( V_8 ) {
V_8 -> V_152 -> V_153 ++ ;
F_19 ( F_12 ( V_8 ) ,
V_144 -> args [ 1 ] , true ) ;
F_87 ( & V_131 -> V_150 ) ;
return V_8 ;
}
}
}
F_87 ( & V_131 -> V_150 ) ;
return NULL ;
}
static int F_88 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
V_14 -> V_46 = F_89 ( L_1 , V_8 -> V_152 -> V_154 ,
sizeof( struct V_99 ) ,
32 , 0 ) ;
return 0 ;
}
static void F_90 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
unsigned long V_55 ;
F_26 ( V_56 ) ;
F_27 ( & V_14 -> V_9 . V_58 , V_55 ) ;
F_17 ( V_14 ) ;
F_19 ( V_14 , 0 , false ) ;
V_14 -> V_59 = NULL ;
F_28 ( & V_14 -> V_9 , & V_56 ) ;
F_29 ( & V_14 -> V_9 . V_58 , V_55 ) ;
F_30 ( & V_14 -> V_9 , & V_56 ) ;
F_91 ( V_14 -> V_46 ) ;
V_14 -> V_46 = NULL ;
}
static int F_92 ( struct V_7 * V_155 ,
struct V_156 * V_157 )
{
V_157 -> V_158 = V_159 ;
V_157 -> V_160 = V_159 ;
V_157 -> V_161 = F_93 ( V_64 ) | F_93 ( V_71 ) ;
V_157 -> V_162 = true ;
V_157 -> V_163 = true ;
return 0 ;
}
static int
F_94 ( struct V_164 * V_165 , struct V_1 * V_131 )
{
int V_166 ;
V_131 -> V_167 = F_95 ( V_165 , L_2 ) ;
if ( V_131 -> V_167 < 0 ) {
F_96 ( & V_165 -> V_154 , L_3 ) ;
return V_131 -> V_167 ;
}
V_131 -> V_168 = F_95 ( V_165 , L_4 ) ;
if ( V_131 -> V_168 < 0 ) {
F_96 ( & V_165 -> V_154 , L_5 ) ;
return V_131 -> V_168 ;
}
if ( V_131 -> V_167 == V_131 -> V_168 ) {
V_166 = F_97 ( & V_165 -> V_154 , V_131 -> V_167 ,
F_80 , 0 , L_6 , V_131 ) ;
if ( V_166 ) {
F_96 ( & V_165 -> V_154 , L_7 ) ;
return V_166 ;
}
} else {
V_166 = F_97 ( & V_165 -> V_154 , V_131 -> V_167 ,
F_71 , 0 , L_8 , V_131 ) ;
if ( V_166 ) {
F_96 ( & V_165 -> V_154 , L_9 ) ;
return V_166 ;
}
V_166 = F_97 ( & V_165 -> V_154 , V_131 -> V_168 ,
F_78 , 0 , L_10 , V_131 ) ;
if ( V_166 ) {
F_96 ( & V_165 -> V_154 , L_11 ) ;
return V_166 ;
}
}
return 0 ;
}
static int F_98 ( struct V_164 * V_165 )
{
struct V_169 * V_170 = V_165 -> V_154 . V_171 ;
struct V_1 * V_131 ;
struct V_6 * V_14 ;
struct V_172 * V_173 ;
int V_86 , V_137 ;
int V_166 , V_43 ;
V_166 = F_99 ( V_170 , L_12 , & V_137 ) ;
if ( V_166 ) {
F_96 ( & V_165 -> V_154 , L_13 ) ;
return V_166 ;
}
V_86 = sizeof( * V_131 ) + sizeof( * V_14 ) * V_137 ;
V_131 = F_100 ( & V_165 -> V_154 , V_86 , V_174 ) ;
if ( ! V_131 )
return - V_175 ;
V_131 -> V_27 = V_137 ;
F_101 ( & V_131 -> V_150 ) ;
V_173 = F_102 ( V_165 , V_176 , 0 ) ;
V_131 -> V_15 = F_103 ( & V_165 -> V_154 , V_173 ) ;
if ( F_104 ( V_131 -> V_15 ) )
return F_105 ( V_131 -> V_15 ) ;
for ( V_43 = 0 ; V_43 < V_28 ; V_43 ++ ) {
char V_177 [ 32 ] ;
V_173 = F_102 ( V_165 , V_176 , 1 + V_43 ) ;
V_131 -> V_29 [ V_43 ] = F_103 ( & V_165 -> V_154 , V_173 ) ;
if ( F_104 ( V_131 -> V_29 [ V_43 ] ) )
return F_105 ( V_131 -> V_29 [ V_43 ] ) ;
sprintf ( V_177 , L_14 , V_43 ) ;
V_131 -> V_178 [ V_43 ] = F_106 ( & V_165 -> V_154 , V_177 ) ;
if ( F_104 ( V_131 -> V_178 [ V_43 ] ) ) {
F_96 ( & V_165 -> V_154 , L_15 ) ;
return F_105 ( V_131 -> V_178 [ V_43 ] ) ;
}
V_166 = F_107 ( V_131 -> V_178 [ V_43 ] ) ;
if ( V_166 ) {
F_96 ( & V_165 -> V_154 , L_16 ) ;
return V_166 ;
}
}
V_166 = F_94 ( V_165 , V_131 ) ;
if ( V_166 )
return V_166 ;
V_131 -> V_4 = F_108 ( V_170 , L_17 ) ;
F_109 ( & V_131 -> V_179 . V_180 ) ;
for ( V_43 = 0 ; V_43 < V_131 -> V_27 ; V_43 ++ ) {
struct V_6 * V_14 = & V_131 -> V_137 [ V_43 ] ;
V_14 -> V_2 = V_131 ;
V_14 -> V_9 . V_181 = F_22 ;
F_110 ( & V_14 -> V_9 , & V_131 -> V_179 ) ;
F_6 ( V_131 , 0x0 , V_131 -> V_15 + F_40 ( V_43 ) ) ;
F_19 ( V_14 , 0 , false ) ;
}
F_111 ( V_182 , V_131 -> V_179 . V_183 ) ;
F_111 ( V_184 , V_131 -> V_179 . V_183 ) ;
F_111 ( V_185 , V_131 -> V_179 . V_183 ) ;
V_131 -> V_179 . V_154 = & V_165 -> V_154 ;
V_131 -> V_179 . V_186
= F_88 ;
V_131 -> V_179 . V_187
= F_90 ;
V_131 -> V_179 . V_188 = F_36 ;
V_131 -> V_179 . V_189 = F_65 ;
V_131 -> V_179 . V_190 = F_62 ;
V_131 -> V_179 . V_191 = F_25 ;
V_131 -> V_179 . V_192 = F_81 ;
V_131 -> V_179 . V_193 = F_92 ;
F_112 ( V_165 , V_131 ) ;
V_166 = F_113 ( & V_131 -> V_179 ) ;
if ( V_166 ) {
F_96 ( & V_165 -> V_154 , L_18 ) ;
return V_166 ;
}
V_166 = F_114 ( V_170 , F_83 , V_131 ) ;
if ( V_166 ) {
F_96 ( & V_165 -> V_154 , L_19 ) ;
F_115 ( & V_131 -> V_179 ) ;
return V_166 ;
}
F_9 ( V_131 , V_194 | V_195 , V_131 -> V_15 + V_196 ) ;
return 0 ;
}
static int F_116 ( struct V_164 * V_165 )
{
struct V_169 * V_170 = V_165 -> V_154 . V_171 ;
struct V_1 * V_131 = F_117 ( V_165 ) ;
int V_43 ;
F_118 ( V_170 ) ;
F_115 ( & V_131 -> V_179 ) ;
for ( V_43 = 0 ; V_43 < V_28 ; V_43 ++ )
F_119 ( V_131 -> V_178 [ V_43 ] ) ;
return 0 ;
}
static int T_9 F_120 ( void )
{
return F_121 ( & V_197 ) ;
}
static void T_10 F_122 ( void )
{
F_123 ( & V_197 ) ;
}
