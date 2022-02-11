static T_1 F_1 ( struct V_1 * V_2 , void T_2 * V_3 )
{
if ( V_2 -> V_4 )
return F_2 ( V_3 ) ;
else
return F_3 ( V_3 ) ;
}
static T_3 F_4 ( struct V_1 * V_2 , void T_2 * V_3 )
{
if ( V_2 -> V_4 )
return F_5 ( V_3 ) ;
else
return F_6 ( V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_4 V_5 , void T_2 * V_3 )
{
F_8 ( V_5 , V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_5 , void T_2 * V_3 )
{
if ( V_2 -> V_4 )
F_10 ( V_5 , V_3 ) ;
else
F_11 ( V_5 , V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_3 V_5 , void T_2 * V_3 )
{
if ( V_2 -> V_4 )
F_13 ( V_5 , V_3 ) ;
else
F_14 ( V_5 , V_3 ) ;
}
static struct V_6 * F_15 ( struct V_7 * V_8 )
{
return F_16 ( V_8 , struct V_6 , V_9 . V_8 ) ;
}
static struct V_10 * F_17 ( struct V_11 * V_12 )
{
return F_16 ( V_12 , struct V_10 , V_13 ) ;
}
static void F_18 ( struct V_6 * V_14 )
{
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_3 V_16 = V_14 -> V_9 . V_8 . V_17 ;
F_7 ( V_14 -> V_2 , F_19 ( V_16 ) , V_3 + V_18 ) ;
F_7 ( V_14 -> V_2 , V_16 , V_3 + V_19 ) ;
}
static void F_20 ( struct V_6 * V_14 )
{
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_3 V_16 = V_14 -> V_9 . V_8 . V_17 ;
F_7 ( V_14 -> V_2 , V_16 , V_3 + V_20 ) ;
F_7 ( V_14 -> V_2 , F_21 ( V_16 ) , V_3 + V_21 ) ;
}
static void F_22 ( struct V_6 * V_14 ,
unsigned int V_22 , bool V_23 )
{
T_3 V_16 = V_14 -> V_9 . V_8 . V_17 ;
void T_2 * V_24 = V_14 -> V_2 -> V_25 [ V_16 / V_26 ] ;
unsigned V_27 , V_28 ;
V_27 = V_14 -> V_2 -> V_29 / V_26 ;
V_28 = V_14 -> V_9 . V_8 . V_17 % V_27 ;
if ( V_23 )
F_7 ( V_14 -> V_2 ,
V_30 | F_23 ( V_22 ) ,
V_24 + V_28 ) ;
else
F_7 ( V_14 -> V_2 , V_31 , V_24 + V_28 ) ;
}
static unsigned int F_24 ( enum V_32 V_33 )
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
static void F_25 ( struct V_11 * V_13 )
{
struct V_10 * V_42 ;
int V_43 ;
V_42 = F_17 ( V_13 ) ;
for ( V_43 = 0 ; V_43 < V_42 -> V_44 ; V_43 ++ )
F_26 ( V_42 -> V_45 -> V_46 ,
V_42 -> V_47 [ V_43 ] . V_48 ,
V_42 -> V_47 [ V_43 ] . V_49 ) ;
F_27 ( V_42 ) ;
}
static int F_28 ( struct V_7 * V_8 , enum V_50 V_51 ,
unsigned long V_52 )
{
struct V_6 * V_14 = F_15 ( V_8 ) ;
struct V_53 * V_54 = ( void * ) V_52 ;
unsigned long V_55 ;
F_29 ( V_56 ) ;
switch ( V_51 ) {
case V_57 :
F_30 ( & V_14 -> V_9 . V_58 , V_55 ) ;
F_20 ( V_14 ) ;
V_14 -> V_59 = NULL ;
F_31 ( & V_14 -> V_9 , & V_56 ) ;
F_32 ( & V_14 -> V_9 . V_58 , V_55 ) ;
F_33 ( & V_14 -> V_9 , & V_56 ) ;
return 0 ;
case V_60 :
V_14 -> V_61 . V_62 = V_54 -> V_63 ;
if ( V_54 -> V_63 == V_64 ) {
V_14 -> V_61 . V_65 = V_54 -> V_66 ;
V_14 -> V_61 . V_33 = V_54 -> V_67 ;
V_14 -> V_61 . V_68 = V_54 -> V_69 ;
V_14 -> V_61 . V_70 = F_24 ( V_54 -> V_67 ) ;
} else if ( V_54 -> V_63 == V_71 ) {
V_14 -> V_61 . V_65 = V_54 -> V_72 ;
V_14 -> V_61 . V_33 = V_54 -> V_73 ;
V_14 -> V_61 . V_68 = V_54 -> V_74 ;
V_14 -> V_61 . V_70 = F_24 ( V_54 -> V_73 ) ;
} else {
return - V_75 ;
}
return 0 ;
case V_76 :
F_30 ( & V_14 -> V_9 . V_58 , V_55 ) ;
if ( V_14 -> V_59 ) {
F_20 ( V_14 ) ;
V_14 -> V_77 = V_78 ;
}
F_32 ( & V_14 -> V_9 . V_58 , V_55 ) ;
return 0 ;
case V_79 :
F_30 ( & V_14 -> V_9 . V_58 , V_55 ) ;
if ( V_14 -> V_59 ) {
F_18 ( V_14 ) ;
V_14 -> V_77 = V_80 ;
}
F_32 ( & V_14 -> V_9 . V_58 , V_55 ) ;
return 0 ;
default:
return - V_81 ;
}
}
static T_5 F_34 ( struct V_6 * V_14 ,
struct V_11 * V_13 , bool V_82 )
{
struct V_10 * V_59 = V_14 -> V_59 ;
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_3 V_16 = V_14 -> V_9 . V_8 . V_17 ;
enum V_83 V_62 = V_14 -> V_61 . V_62 ;
T_6 V_84 , V_85 ;
T_5 V_86 , V_87 ;
int V_43 ;
for ( V_86 = V_43 = 0 ; V_43 < V_14 -> V_59 -> V_44 ; V_43 ++ )
V_86 += F_4 ( V_14 -> V_2 , & ( V_59 -> V_47 [ V_43 ] . V_48 -> V_88 ) )
* F_1 ( V_14 -> V_2 , & ( V_59 -> V_47 [ V_43 ] . V_48 -> V_89 ) ) ;
if ( ! V_82 )
return V_86 ;
if ( V_62 == V_71 )
V_84 = F_4 ( V_14 -> V_2 , V_3 + F_35 ( V_16 ) ) ;
else
V_84 = F_4 ( V_14 -> V_2 , V_3 + F_36 ( V_16 ) ) ;
for ( V_43 = 0 ; V_43 < V_14 -> V_59 -> V_44 ; V_43 ++ ) {
V_87 = F_4 ( V_14 -> V_2 , & ( V_59 -> V_47 [ V_43 ] . V_48 -> V_88 ) )
* F_1 ( V_14 -> V_2 , & ( V_59 -> V_47 [ V_43 ] . V_48 -> V_89 ) ) ;
if ( V_62 == V_71 )
V_85 = F_4 ( V_14 -> V_2 ,
& ( V_59 -> V_47 [ V_43 ] . V_48 -> V_90 ) ) ;
else
V_85 = F_4 ( V_14 -> V_2 ,
& ( V_59 -> V_47 [ V_43 ] . V_48 -> V_91 ) ) ;
V_86 -= V_87 ;
if ( V_84 > V_85 && V_84 < V_85 + V_87 ) {
V_86 += V_85 + V_87 - V_84 ;
break;
}
}
return V_86 ;
}
static enum V_92 F_37 ( struct V_7 * V_8 ,
T_7 V_93 , struct V_94 * V_95 )
{
struct V_6 * V_14 = F_15 ( V_8 ) ;
struct V_11 * V_13 ;
enum V_92 V_77 ;
unsigned long V_55 ;
V_77 = F_38 ( V_8 , V_93 , V_95 ) ;
if ( V_77 == V_96 )
return V_77 ;
if ( ! V_95 )
return V_14 -> V_77 ;
F_30 ( & V_14 -> V_9 . V_58 , V_55 ) ;
V_13 = F_39 ( & V_14 -> V_9 , V_93 ) ;
if ( V_14 -> V_59 && V_93 == V_14 -> V_59 -> V_13 . V_97 . V_93 )
V_95 -> V_98 = F_34 ( V_14 , V_13 , true ) ;
else if ( V_13 )
V_95 -> V_98 = F_34 ( V_14 , V_13 , false ) ;
else
V_95 -> V_98 = 0 ;
F_32 ( & V_14 -> V_9 . V_58 , V_55 ) ;
return V_14 -> V_77 ;
}
static void F_40 ( struct V_6 * V_14 ,
T_3 V_99 , T_3 V_100 , T_1 V_70 , T_1 V_101 , T_3 V_88 ,
T_3 V_102 , T_1 V_103 , T_1 V_89 , T_3 V_104 , T_3 V_105 ,
T_1 V_106 )
{
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_3 V_16 = V_14 -> V_9 . V_8 . V_17 ;
F_41 ( 0 , V_3 + F_42 ( V_16 ) ) ;
F_43 ( V_99 , V_3 + F_35 ( V_16 ) ) ;
F_43 ( V_100 , V_3 + F_36 ( V_16 ) ) ;
F_41 ( V_70 , V_3 + F_44 ( V_16 ) ) ;
F_41 ( V_101 , V_3 + F_45 ( V_16 ) ) ;
F_43 ( V_88 , V_3 + F_46 ( V_16 ) ) ;
F_43 ( V_102 , V_3 + F_47 ( V_16 ) ) ;
F_41 ( V_103 , V_3 + F_48 ( V_16 ) ) ;
F_41 ( V_89 , V_3 + F_49 ( V_16 ) ) ;
F_41 ( V_104 , V_3 + F_50 ( V_16 ) ) ;
F_43 ( V_105 , V_3 + F_51 ( V_16 ) ) ;
F_41 ( V_106 , V_3 + F_42 ( V_16 ) ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_107 * V_47 , T_3 V_99 , T_3 V_100 ,
T_1 V_70 , T_1 V_101 , T_3 V_88 , T_3 V_102 , T_1 V_103 ,
T_1 V_89 , T_1 V_104 , T_3 V_105 , bool V_108 ,
bool V_109 , bool V_110 )
{
T_1 V_106 = 0 ;
F_12 ( V_2 , V_99 , & ( V_47 -> V_90 ) ) ;
F_12 ( V_2 , V_100 , & ( V_47 -> V_91 ) ) ;
F_9 ( V_2 , V_70 , & ( V_47 -> V_70 ) ) ;
F_9 ( V_2 , F_53 ( V_101 ) , & ( V_47 -> V_101 ) ) ;
F_12 ( V_2 , F_54 ( V_88 ) , & ( V_47 -> V_88 ) ) ;
F_12 ( V_2 , F_55 ( V_102 ) , & ( V_47 -> V_102 ) ) ;
F_9 ( V_2 , F_56 ( V_103 ) , & ( V_47 -> V_103 ) ) ;
F_9 ( V_2 , F_57 ( V_104 ) , & ( V_47 -> V_104 ) ) ;
F_12 ( V_2 , F_58 ( V_105 ) , & ( V_47 -> V_105 ) ) ;
F_9 ( V_2 , F_59 ( V_89 ) , & ( V_47 -> V_89 ) ) ;
if ( V_108 )
V_106 |= V_111 ;
if ( V_109 )
V_106 |= V_112 ;
if ( V_110 )
V_106 |= V_113 ;
F_9 ( V_2 , V_106 , & ( V_47 -> V_106 ) ) ;
}
static struct V_10 * F_60 ( struct V_6 * V_14 ,
int V_114 )
{
struct V_10 * V_42 ;
int V_43 ;
V_42 = F_61 ( sizeof( * V_42 ) + sizeof( struct V_115 ) * V_114 ,
V_116 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_45 = V_14 ;
V_42 -> V_44 = V_114 ;
for ( V_43 = 0 ; V_43 < V_114 ; V_43 ++ ) {
V_42 -> V_47 [ V_43 ] . V_48 = F_62 ( V_14 -> V_46 ,
V_116 , & V_42 -> V_47 [ V_43 ] . V_49 ) ;
if ( ! V_42 -> V_47 [ V_43 ] . V_48 )
goto V_117;
}
return V_42 ;
V_117:
while ( -- V_43 >= 0 )
F_26 ( V_14 -> V_46 , V_42 -> V_47 [ V_43 ] . V_48 ,
V_42 -> V_47 [ V_43 ] . V_49 ) ;
F_27 ( V_42 ) ;
return NULL ;
}
static struct V_118 * F_63 (
struct V_7 * V_8 , T_6 V_85 , T_5 V_119 ,
T_5 V_120 , enum V_83 V_63 ,
unsigned long V_55 , void * V_121 )
{
struct V_6 * V_14 = F_15 ( V_8 ) ;
struct V_10 * V_42 ;
T_6 V_122 ;
int V_114 , V_43 ;
T_3 V_66 , V_72 , V_123 , V_88 ;
T_1 V_101 , V_104 , V_124 ;
if ( ! F_64 ( V_14 -> V_61 . V_62 ) )
return NULL ;
V_114 = V_119 / V_120 ;
V_42 = F_60 ( V_14 , V_114 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_125 = true ;
V_122 = V_85 ;
V_88 = V_14 -> V_61 . V_33 * V_14 -> V_61 . V_68 ;
V_124 = V_120 / V_88 ;
for ( V_43 = 0 ; V_43 < V_114 ; V_43 ++ ) {
if ( V_122 >= V_85 + V_119 )
V_122 = V_85 ;
V_123 = V_42 -> V_47 [ ( V_43 + 1 ) % V_114 ] . V_49 ;
if ( V_14 -> V_61 . V_62 == V_71 ) {
V_66 = V_122 ;
V_72 = V_14 -> V_61 . V_65 ;
V_101 = V_14 -> V_61 . V_33 ;
V_104 = 0 ;
} else {
V_66 = V_14 -> V_61 . V_65 ;
V_72 = V_122 ;
V_101 = 0 ;
V_104 = V_14 -> V_61 . V_33 ;
}
F_52 ( V_14 -> V_2 , V_42 -> V_47 [ V_43 ] . V_48 , V_66 ,
V_72 , V_14 -> V_61 . V_70 , V_101 , V_88 , 0 ,
V_124 , V_124 , V_104 , V_123 , true , false , true ) ;
V_122 += V_120 ;
}
return F_65 ( & V_14 -> V_9 , & V_42 -> V_13 , V_55 ) ;
}
static struct V_118 * F_66 (
struct V_7 * V_8 , struct V_126 * V_127 ,
unsigned int V_114 , enum V_83 V_63 ,
unsigned long V_55 , void * V_121 )
{
struct V_6 * V_14 = F_15 ( V_8 ) ;
struct V_10 * V_42 ;
struct V_126 * V_128 ;
T_3 V_66 , V_72 , V_123 , V_88 ;
T_1 V_101 , V_104 , V_124 ;
int V_43 ;
if ( ! F_64 ( V_14 -> V_61 . V_62 ) )
return NULL ;
V_42 = F_60 ( V_14 , V_114 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_125 = false ;
V_88 = V_14 -> V_61 . V_33 * V_14 -> V_61 . V_68 ;
F_67 (sgl, sg, sg_len, i) {
V_123 = V_42 -> V_47 [ ( V_43 + 1 ) % V_114 ] . V_49 ;
if ( V_14 -> V_61 . V_62 == V_71 ) {
V_66 = F_68 ( V_128 ) ;
V_72 = V_14 -> V_61 . V_65 ;
V_101 = V_14 -> V_61 . V_33 ;
V_104 = 0 ;
} else {
V_66 = V_14 -> V_61 . V_65 ;
V_72 = F_68 ( V_128 ) ;
V_101 = 0 ;
V_104 = V_14 -> V_61 . V_33 ;
}
V_124 = F_69 ( V_128 ) / V_88 ;
if ( V_43 < V_114 - 1 ) {
V_123 = V_42 -> V_47 [ ( V_43 + 1 ) ] . V_49 ;
F_52 ( V_14 -> V_2 , V_42 -> V_47 [ V_43 ] . V_48 ,
V_66 , V_72 , V_14 -> V_61 . V_70 ,
V_101 , V_88 , 0 , V_124 , V_124 , V_104 , V_123 ,
false , false , true ) ;
} else {
V_123 = 0 ;
F_52 ( V_14 -> V_2 , V_42 -> V_47 [ V_43 ] . V_48 ,
V_66 , V_72 , V_14 -> V_61 . V_70 ,
V_101 , V_88 , 0 , V_124 , V_124 , V_104 , V_123 ,
true , true , false ) ;
}
}
return F_65 ( & V_14 -> V_9 , & V_42 -> V_13 , V_55 ) ;
}
static void F_70 ( struct V_6 * V_14 )
{
struct V_107 * V_47 ;
struct V_11 * V_13 ;
V_13 = F_71 ( & V_14 -> V_9 ) ;
if ( ! V_13 )
return;
V_14 -> V_59 = F_17 ( V_13 ) ;
V_47 = V_14 -> V_59 -> V_47 [ 0 ] . V_48 ;
F_40 ( V_14 , V_47 -> V_90 , V_47 -> V_91 , V_47 -> V_70 ,
V_47 -> V_101 , V_47 -> V_88 , V_47 -> V_102 , V_47 -> V_103 ,
V_47 -> V_89 , V_47 -> V_104 , V_47 -> V_105 , V_47 -> V_106 ) ;
F_18 ( V_14 ) ;
V_14 -> V_77 = V_80 ;
}
static T_8 F_72 ( int V_129 , void * V_130 )
{
struct V_1 * V_131 = V_130 ;
unsigned int V_132 , V_16 ;
void T_2 * V_133 ;
struct V_6 * V_14 ;
V_133 = V_131 -> V_15 ;
V_132 = F_4 ( V_131 , V_133 + V_134 ) ;
if ( ! V_132 )
return V_135 ;
for ( V_16 = 0 ; V_16 < V_131 -> V_29 ; V_16 ++ ) {
if ( V_132 & ( 0x1 << V_16 ) ) {
F_7 ( V_131 , F_73 ( V_16 ) ,
V_133 + V_136 ) ;
V_14 = & V_131 -> V_137 [ V_16 ] ;
F_74 ( & V_14 -> V_9 . V_58 ) ;
if ( ! V_14 -> V_59 -> V_125 ) {
F_75 ( & V_14 -> V_59 -> V_13 . V_138 ) ;
F_76 ( & V_14 -> V_59 -> V_13 ) ;
V_14 -> V_59 = NULL ;
V_14 -> V_77 = V_96 ;
} else {
F_77 ( & V_14 -> V_59 -> V_13 ) ;
}
if ( ! V_14 -> V_59 )
F_70 ( V_14 ) ;
F_78 ( & V_14 -> V_9 . V_58 ) ;
}
}
return V_139 ;
}
static T_8 F_79 ( int V_129 , void * V_130 )
{
struct V_1 * V_131 = V_130 ;
unsigned int V_117 , V_16 ;
V_117 = F_4 ( V_131 , V_131 -> V_15 + V_140 ) ;
if ( ! V_117 )
return V_135 ;
for ( V_16 = 0 ; V_16 < V_131 -> V_29 ; V_16 ++ ) {
if ( V_117 & ( 0x1 << V_16 ) ) {
F_20 ( & V_131 -> V_137 [ V_16 ] ) ;
F_7 ( V_131 , F_80 ( V_16 ) ,
V_131 -> V_15 + V_141 ) ;
V_131 -> V_137 [ V_16 ] . V_77 = V_142 ;
}
}
return V_139 ;
}
static T_8 F_81 ( int V_129 , void * V_130 )
{
if ( F_72 ( V_129 , V_130 ) == V_139 )
return V_139 ;
return F_79 ( V_129 , V_130 ) ;
}
static void F_82 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_15 ( V_8 ) ;
unsigned long V_55 ;
F_30 ( & V_14 -> V_9 . V_58 , V_55 ) ;
if ( F_83 ( & V_14 -> V_9 ) && ! V_14 -> V_59 )
F_70 ( V_14 ) ;
F_32 ( & V_14 -> V_9 . V_58 , V_55 ) ;
}
static struct V_7 * F_84 ( struct V_143 * V_144 ,
struct V_145 * V_146 )
{
struct V_1 * V_131 = V_146 -> V_147 ;
struct V_7 * V_8 , * V_148 ;
if ( V_144 -> V_149 != 2 )
return NULL ;
F_85 ( & V_131 -> V_150 ) ;
F_86 (chan, _chan, &fsl_edma->dma_dev.channels, device_node) {
if ( V_8 -> V_151 )
continue;
if ( ( V_8 -> V_17 / V_26 ) == V_144 -> args [ 0 ] ) {
V_8 = F_87 ( V_8 ) ;
if ( V_8 ) {
V_8 -> V_152 -> V_153 ++ ;
F_22 ( F_15 ( V_8 ) ,
V_144 -> args [ 1 ] , true ) ;
F_88 ( & V_131 -> V_150 ) ;
return V_8 ;
}
}
}
F_88 ( & V_131 -> V_150 ) ;
return NULL ;
}
static int F_89 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_15 ( V_8 ) ;
V_14 -> V_46 = F_90 ( L_1 , V_8 -> V_152 -> V_154 ,
sizeof( struct V_107 ) ,
32 , 0 ) ;
return 0 ;
}
static void F_91 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_15 ( V_8 ) ;
unsigned long V_55 ;
F_29 ( V_56 ) ;
F_30 ( & V_14 -> V_9 . V_58 , V_55 ) ;
F_20 ( V_14 ) ;
F_22 ( V_14 , 0 , false ) ;
V_14 -> V_59 = NULL ;
F_31 ( & V_14 -> V_9 , & V_56 ) ;
F_32 ( & V_14 -> V_9 . V_58 , V_55 ) ;
F_33 ( & V_14 -> V_9 , & V_56 ) ;
F_92 ( V_14 -> V_46 ) ;
V_14 -> V_46 = NULL ;
}
static int F_93 ( struct V_7 * V_155 ,
struct V_156 * V_157 )
{
V_157 -> V_158 = V_159 ;
V_157 -> V_160 = V_159 ;
V_157 -> V_161 = F_94 ( V_64 ) | F_94 ( V_71 ) ;
V_157 -> V_162 = true ;
V_157 -> V_163 = true ;
return 0 ;
}
static int
F_95 ( struct V_164 * V_165 , struct V_1 * V_131 )
{
int V_166 ;
V_131 -> V_167 = F_96 ( V_165 , L_2 ) ;
if ( V_131 -> V_167 < 0 ) {
F_97 ( & V_165 -> V_154 , L_3 ) ;
return V_131 -> V_167 ;
}
V_131 -> V_168 = F_96 ( V_165 , L_4 ) ;
if ( V_131 -> V_168 < 0 ) {
F_97 ( & V_165 -> V_154 , L_5 ) ;
return V_131 -> V_168 ;
}
if ( V_131 -> V_167 == V_131 -> V_168 ) {
V_166 = F_98 ( & V_165 -> V_154 , V_131 -> V_167 ,
F_81 , 0 , L_6 , V_131 ) ;
if ( V_166 ) {
F_97 ( & V_165 -> V_154 , L_7 ) ;
return V_166 ;
}
} else {
V_166 = F_98 ( & V_165 -> V_154 , V_131 -> V_167 ,
F_72 , 0 , L_8 , V_131 ) ;
if ( V_166 ) {
F_97 ( & V_165 -> V_154 , L_9 ) ;
return V_166 ;
}
V_166 = F_98 ( & V_165 -> V_154 , V_131 -> V_168 ,
F_79 , 0 , L_10 , V_131 ) ;
if ( V_166 ) {
F_97 ( & V_165 -> V_154 , L_11 ) ;
return V_166 ;
}
}
return 0 ;
}
static int F_99 ( struct V_164 * V_165 )
{
struct V_169 * V_170 = V_165 -> V_154 . V_171 ;
struct V_1 * V_131 ;
struct V_6 * V_14 ;
struct V_172 * V_173 ;
int V_86 , V_137 ;
int V_166 , V_43 ;
V_166 = F_100 ( V_170 , L_12 , & V_137 ) ;
if ( V_166 ) {
F_97 ( & V_165 -> V_154 , L_13 ) ;
return V_166 ;
}
V_86 = sizeof( * V_131 ) + sizeof( * V_14 ) * V_137 ;
V_131 = F_101 ( & V_165 -> V_154 , V_86 , V_174 ) ;
if ( ! V_131 )
return - V_175 ;
V_131 -> V_29 = V_137 ;
F_102 ( & V_131 -> V_150 ) ;
V_173 = F_103 ( V_165 , V_176 , 0 ) ;
V_131 -> V_15 = F_104 ( & V_165 -> V_154 , V_173 ) ;
if ( F_105 ( V_131 -> V_15 ) )
return F_106 ( V_131 -> V_15 ) ;
for ( V_43 = 0 ; V_43 < V_26 ; V_43 ++ ) {
char V_177 [ 32 ] ;
V_173 = F_103 ( V_165 , V_176 , 1 + V_43 ) ;
V_131 -> V_25 [ V_43 ] = F_104 ( & V_165 -> V_154 , V_173 ) ;
if ( F_105 ( V_131 -> V_25 [ V_43 ] ) )
return F_106 ( V_131 -> V_25 [ V_43 ] ) ;
sprintf ( V_177 , L_14 , V_43 ) ;
V_131 -> V_178 [ V_43 ] = F_107 ( & V_165 -> V_154 , V_177 ) ;
if ( F_105 ( V_131 -> V_178 [ V_43 ] ) ) {
F_97 ( & V_165 -> V_154 , L_15 ) ;
return F_106 ( V_131 -> V_178 [ V_43 ] ) ;
}
V_166 = F_108 ( V_131 -> V_178 [ V_43 ] ) ;
if ( V_166 ) {
F_97 ( & V_165 -> V_154 , L_16 ) ;
return V_166 ;
}
}
V_166 = F_95 ( V_165 , V_131 ) ;
if ( V_166 )
return V_166 ;
V_131 -> V_4 = F_109 ( V_170 , L_17 ) ;
F_110 ( & V_131 -> V_179 . V_180 ) ;
for ( V_43 = 0 ; V_43 < V_131 -> V_29 ; V_43 ++ ) {
struct V_6 * V_14 = & V_131 -> V_137 [ V_43 ] ;
V_14 -> V_2 = V_131 ;
V_14 -> V_9 . V_181 = F_25 ;
F_111 ( & V_14 -> V_9 , & V_131 -> V_179 ) ;
F_9 ( V_131 , 0x0 , V_131 -> V_15 + F_42 ( V_43 ) ) ;
F_22 ( V_14 , 0 , false ) ;
}
F_112 ( V_182 , V_131 -> V_179 . V_183 ) ;
F_112 ( V_184 , V_131 -> V_179 . V_183 ) ;
F_112 ( V_185 , V_131 -> V_179 . V_183 ) ;
V_131 -> V_179 . V_154 = & V_165 -> V_154 ;
V_131 -> V_179 . V_186
= F_89 ;
V_131 -> V_179 . V_187
= F_91 ;
V_131 -> V_179 . V_188 = F_37 ;
V_131 -> V_179 . V_189 = F_66 ;
V_131 -> V_179 . V_190 = F_63 ;
V_131 -> V_179 . V_191 = F_28 ;
V_131 -> V_179 . V_192 = F_82 ;
V_131 -> V_179 . V_193 = F_93 ;
F_113 ( V_165 , V_131 ) ;
V_166 = F_114 ( & V_131 -> V_179 ) ;
if ( V_166 ) {
F_97 ( & V_165 -> V_154 , L_18 ) ;
return V_166 ;
}
V_166 = F_115 ( V_170 , F_84 , V_131 ) ;
if ( V_166 ) {
F_97 ( & V_165 -> V_154 , L_19 ) ;
F_116 ( & V_131 -> V_179 ) ;
return V_166 ;
}
F_12 ( V_131 , V_194 | V_195 , V_131 -> V_15 + V_196 ) ;
return 0 ;
}
static int F_117 ( struct V_164 * V_165 )
{
struct V_169 * V_170 = V_165 -> V_154 . V_171 ;
struct V_1 * V_131 = F_118 ( V_165 ) ;
int V_43 ;
F_119 ( V_170 ) ;
F_116 ( & V_131 -> V_179 ) ;
for ( V_43 = 0 ; V_43 < V_26 ; V_43 ++ )
F_120 ( V_131 -> V_178 [ V_43 ] ) ;
return 0 ;
}
static int T_9 F_121 ( void )
{
return F_122 ( & V_197 ) ;
}
static void T_10 F_123 ( void )
{
F_124 ( & V_197 ) ;
}
