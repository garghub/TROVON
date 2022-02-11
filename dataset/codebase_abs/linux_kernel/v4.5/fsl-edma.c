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
static int F_25 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
unsigned long V_50 ;
F_26 ( V_51 ) ;
F_27 ( & V_14 -> V_9 . V_52 , V_50 ) ;
F_17 ( V_14 ) ;
V_14 -> V_53 = NULL ;
V_14 -> V_54 = true ;
F_28 ( & V_14 -> V_9 , & V_51 ) ;
F_29 ( & V_14 -> V_9 . V_52 , V_50 ) ;
F_30 ( & V_14 -> V_9 , & V_51 ) ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
unsigned long V_50 ;
F_27 ( & V_14 -> V_9 . V_52 , V_50 ) ;
if ( V_14 -> V_53 ) {
F_17 ( V_14 ) ;
V_14 -> V_55 = V_56 ;
V_14 -> V_54 = true ;
}
F_29 ( & V_14 -> V_9 . V_52 , V_50 ) ;
return 0 ;
}
static int F_32 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
unsigned long V_50 ;
F_27 ( & V_14 -> V_9 . V_52 , V_50 ) ;
if ( V_14 -> V_53 ) {
F_15 ( V_14 ) ;
V_14 -> V_55 = V_57 ;
V_14 -> V_54 = false ;
}
F_29 ( & V_14 -> V_9 . V_52 , V_50 ) ;
return 0 ;
}
static int F_33 ( struct V_7 * V_8 ,
struct V_58 * V_59 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
V_14 -> V_60 . V_61 = V_59 -> V_62 ;
if ( V_59 -> V_62 == V_63 ) {
V_14 -> V_60 . V_64 = V_59 -> V_65 ;
V_14 -> V_60 . V_33 = V_59 -> V_66 ;
V_14 -> V_60 . V_67 = V_59 -> V_68 ;
V_14 -> V_60 . V_69 = F_21 ( V_59 -> V_66 ) ;
} else if ( V_59 -> V_62 == V_70 ) {
V_14 -> V_60 . V_64 = V_59 -> V_71 ;
V_14 -> V_60 . V_33 = V_59 -> V_72 ;
V_14 -> V_60 . V_67 = V_59 -> V_73 ;
V_14 -> V_60 . V_69 = F_21 ( V_59 -> V_72 ) ;
} else {
return - V_74 ;
}
return 0 ;
}
static T_5 F_34 ( struct V_6 * V_14 ,
struct V_11 * V_13 , bool V_75 )
{
struct V_10 * V_53 = V_14 -> V_53 ;
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_1 V_16 = V_14 -> V_9 . V_8 . V_17 ;
enum V_76 V_61 = V_14 -> V_60 . V_61 ;
T_6 V_77 , V_78 ;
T_5 V_79 , V_80 ;
int V_43 ;
for ( V_79 = V_43 = 0 ; V_43 < V_14 -> V_53 -> V_44 ; V_43 ++ )
V_79 += F_35 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_81 )
* F_36 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_82 ) ;
if ( ! V_75 )
return V_79 ;
if ( V_61 == V_70 )
V_77 = F_1 ( V_14 -> V_2 , V_3 + F_37 ( V_16 ) ) ;
else
V_77 = F_1 ( V_14 -> V_2 , V_3 + F_38 ( V_16 ) ) ;
for ( V_43 = 0 ; V_43 < V_14 -> V_53 -> V_44 ; V_43 ++ ) {
V_80 = F_35 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_81 )
* F_36 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_82 ) ;
if ( V_61 == V_70 )
V_78 = F_35 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_83 ) ;
else
V_78 = F_35 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_84 ) ;
V_79 -= V_80 ;
if ( V_77 >= V_78 && V_77 < V_78 + V_80 ) {
V_79 += V_78 + V_80 - V_77 ;
break;
}
}
return V_79 ;
}
static enum V_85 F_39 ( struct V_7 * V_8 ,
T_7 V_86 , struct V_87 * V_88 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
struct V_11 * V_13 ;
enum V_85 V_55 ;
unsigned long V_50 ;
V_55 = F_40 ( V_8 , V_86 , V_88 ) ;
if ( V_55 == V_89 )
return V_55 ;
if ( ! V_88 )
return V_14 -> V_55 ;
F_27 ( & V_14 -> V_9 . V_52 , V_50 ) ;
V_13 = F_41 ( & V_14 -> V_9 , V_86 ) ;
if ( V_14 -> V_53 && V_86 == V_14 -> V_53 -> V_13 . V_90 . V_86 )
V_88 -> V_91 = F_34 ( V_14 , V_13 , true ) ;
else if ( V_13 )
V_88 -> V_91 = F_34 ( V_14 , V_13 , false ) ;
else
V_88 -> V_91 = 0 ;
F_29 ( & V_14 -> V_9 . V_52 , V_50 ) ;
return V_14 -> V_55 ;
}
static void F_42 ( struct V_6 * V_14 ,
struct V_92 * V_47 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_1 V_16 = V_14 -> V_9 . V_8 . V_17 ;
F_6 ( V_2 , 0 , V_3 + F_43 ( V_16 ) ) ;
F_9 ( V_2 , F_35 ( V_47 -> V_83 ) , V_3 + F_37 ( V_16 ) ) ;
F_9 ( V_2 , F_35 ( V_47 -> V_84 ) , V_3 + F_38 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_69 ) , V_3 + F_44 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_93 ) , V_3 + F_45 ( V_16 ) ) ;
F_9 ( V_2 , F_35 ( V_47 -> V_81 ) , V_3 + F_46 ( V_16 ) ) ;
F_9 ( V_2 , F_35 ( V_47 -> V_94 ) , V_3 + F_47 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_95 ) , V_3 + F_48 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_82 ) , V_3 + F_49 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_96 ) , V_3 + F_50 ( V_16 ) ) ;
F_9 ( V_2 , F_35 ( V_47 -> V_97 ) , V_3 + F_51 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_98 ) , V_3 + F_43 ( V_16 ) ) ;
}
static inline
void F_52 ( struct V_92 * V_47 , T_1 V_99 , T_1 V_100 ,
T_4 V_69 , T_4 V_93 , T_1 V_81 , T_1 V_94 , T_4 V_95 ,
T_4 V_82 , T_4 V_96 , T_1 V_97 , bool V_101 ,
bool V_102 , bool V_103 )
{
T_4 V_98 = 0 ;
V_47 -> V_83 = F_53 ( V_99 ) ;
V_47 -> V_84 = F_53 ( V_100 ) ;
V_47 -> V_69 = F_54 ( V_69 ) ;
V_47 -> V_93 = F_54 ( F_55 ( V_93 ) ) ;
V_47 -> V_81 = F_53 ( F_56 ( V_81 ) ) ;
V_47 -> V_94 = F_53 ( F_57 ( V_94 ) ) ;
V_47 -> V_95 = F_54 ( F_58 ( V_95 ) ) ;
V_47 -> V_96 = F_54 ( F_59 ( V_96 ) ) ;
V_47 -> V_97 = F_53 ( F_60 ( V_97 ) ) ;
V_47 -> V_82 = F_54 ( F_61 ( V_82 ) ) ;
if ( V_101 )
V_98 |= V_104 ;
if ( V_102 )
V_98 |= V_105 ;
if ( V_103 )
V_98 |= V_106 ;
V_47 -> V_98 = F_54 ( V_98 ) ;
}
static struct V_10 * F_62 ( struct V_6 * V_14 ,
int V_107 )
{
struct V_10 * V_42 ;
int V_43 ;
V_42 = F_63 ( sizeof( * V_42 ) + sizeof( struct V_108 ) * V_107 ,
V_109 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_45 = V_14 ;
V_42 -> V_44 = V_107 ;
for ( V_43 = 0 ; V_43 < V_107 ; V_43 ++ ) {
V_42 -> V_47 [ V_43 ] . V_48 = F_64 ( V_14 -> V_46 ,
V_109 , & V_42 -> V_47 [ V_43 ] . V_49 ) ;
if ( ! V_42 -> V_47 [ V_43 ] . V_48 )
goto V_110;
}
return V_42 ;
V_110:
while ( -- V_43 >= 0 )
F_23 ( V_14 -> V_46 , V_42 -> V_47 [ V_43 ] . V_48 ,
V_42 -> V_47 [ V_43 ] . V_49 ) ;
F_24 ( V_42 ) ;
return NULL ;
}
static struct V_111 * F_65 (
struct V_7 * V_8 , T_6 V_78 , T_5 V_112 ,
T_5 V_113 , enum V_76 V_62 ,
unsigned long V_50 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
struct V_10 * V_42 ;
T_6 V_114 ;
int V_107 , V_43 ;
T_1 V_65 , V_71 , V_115 , V_81 ;
T_4 V_93 , V_96 , V_116 ;
if ( ! F_66 ( V_14 -> V_60 . V_61 ) )
return NULL ;
V_107 = V_112 / V_113 ;
V_42 = F_62 ( V_14 , V_107 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_117 = true ;
V_114 = V_78 ;
V_81 = V_14 -> V_60 . V_33 * V_14 -> V_60 . V_67 ;
V_116 = V_113 / V_81 ;
for ( V_43 = 0 ; V_43 < V_107 ; V_43 ++ ) {
if ( V_114 >= V_78 + V_112 )
V_114 = V_78 ;
V_115 = V_42 -> V_47 [ ( V_43 + 1 ) % V_107 ] . V_49 ;
if ( V_14 -> V_60 . V_61 == V_70 ) {
V_65 = V_114 ;
V_71 = V_14 -> V_60 . V_64 ;
V_93 = V_14 -> V_60 . V_33 ;
V_96 = 0 ;
} else {
V_65 = V_14 -> V_60 . V_64 ;
V_71 = V_114 ;
V_93 = 0 ;
V_96 = V_14 -> V_60 . V_33 ;
}
F_52 ( V_42 -> V_47 [ V_43 ] . V_48 , V_65 , V_71 ,
V_14 -> V_60 . V_69 , V_93 , V_81 , 0 , V_116 ,
V_116 , V_96 , V_115 , true , false , true ) ;
V_114 += V_113 ;
}
return F_67 ( & V_14 -> V_9 , & V_42 -> V_13 , V_50 ) ;
}
static struct V_111 * F_68 (
struct V_7 * V_8 , struct V_118 * V_119 ,
unsigned int V_107 , enum V_76 V_62 ,
unsigned long V_50 , void * V_120 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
struct V_10 * V_42 ;
struct V_118 * V_121 ;
T_1 V_65 , V_71 , V_115 , V_81 ;
T_4 V_93 , V_96 , V_116 ;
int V_43 ;
if ( ! F_66 ( V_14 -> V_60 . V_61 ) )
return NULL ;
V_42 = F_62 ( V_14 , V_107 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_117 = false ;
V_81 = V_14 -> V_60 . V_33 * V_14 -> V_60 . V_67 ;
F_69 (sgl, sg, sg_len, i) {
V_115 = V_42 -> V_47 [ ( V_43 + 1 ) % V_107 ] . V_49 ;
if ( V_14 -> V_60 . V_61 == V_70 ) {
V_65 = F_70 ( V_121 ) ;
V_71 = V_14 -> V_60 . V_64 ;
V_93 = V_14 -> V_60 . V_33 ;
V_96 = 0 ;
} else {
V_65 = V_14 -> V_60 . V_64 ;
V_71 = F_70 ( V_121 ) ;
V_93 = 0 ;
V_96 = V_14 -> V_60 . V_33 ;
}
V_116 = F_71 ( V_121 ) / V_81 ;
if ( V_43 < V_107 - 1 ) {
V_115 = V_42 -> V_47 [ ( V_43 + 1 ) ] . V_49 ;
F_52 ( V_42 -> V_47 [ V_43 ] . V_48 , V_65 ,
V_71 , V_14 -> V_60 . V_69 , V_93 ,
V_81 , 0 , V_116 , V_116 , V_96 , V_115 ,
false , false , true ) ;
} else {
V_115 = 0 ;
F_52 ( V_42 -> V_47 [ V_43 ] . V_48 , V_65 ,
V_71 , V_14 -> V_60 . V_69 , V_93 ,
V_81 , 0 , V_116 , V_116 , V_96 , V_115 ,
true , true , false ) ;
}
}
return F_67 ( & V_14 -> V_9 , & V_42 -> V_13 , V_50 ) ;
}
static void F_72 ( struct V_6 * V_14 )
{
struct V_11 * V_13 ;
V_13 = F_73 ( & V_14 -> V_9 ) ;
if ( ! V_13 )
return;
V_14 -> V_53 = F_14 ( V_13 ) ;
F_42 ( V_14 , V_14 -> V_53 -> V_47 [ 0 ] . V_48 ) ;
F_15 ( V_14 ) ;
V_14 -> V_55 = V_57 ;
V_14 -> V_54 = false ;
}
static T_8 F_74 ( int V_122 , void * V_123 )
{
struct V_1 * V_124 = V_123 ;
unsigned int V_125 , V_16 ;
void T_2 * V_126 ;
struct V_6 * V_14 ;
V_126 = V_124 -> V_15 ;
V_125 = F_1 ( V_124 , V_126 + V_127 ) ;
if ( ! V_125 )
return V_128 ;
for ( V_16 = 0 ; V_16 < V_124 -> V_27 ; V_16 ++ ) {
if ( V_125 & ( 0x1 << V_16 ) ) {
F_4 ( V_124 , F_75 ( V_16 ) ,
V_126 + V_129 ) ;
V_14 = & V_124 -> V_130 [ V_16 ] ;
F_76 ( & V_14 -> V_9 . V_52 ) ;
if ( ! V_14 -> V_53 -> V_117 ) {
F_77 ( & V_14 -> V_53 -> V_13 . V_131 ) ;
F_78 ( & V_14 -> V_53 -> V_13 ) ;
V_14 -> V_53 = NULL ;
V_14 -> V_55 = V_89 ;
V_14 -> V_54 = true ;
} else {
F_79 ( & V_14 -> V_53 -> V_13 ) ;
}
if ( ! V_14 -> V_53 )
F_72 ( V_14 ) ;
F_80 ( & V_14 -> V_9 . V_52 ) ;
}
}
return V_132 ;
}
static T_8 F_81 ( int V_122 , void * V_123 )
{
struct V_1 * V_124 = V_123 ;
unsigned int V_110 , V_16 ;
V_110 = F_1 ( V_124 , V_124 -> V_15 + V_133 ) ;
if ( ! V_110 )
return V_128 ;
for ( V_16 = 0 ; V_16 < V_124 -> V_27 ; V_16 ++ ) {
if ( V_110 & ( 0x1 << V_16 ) ) {
F_17 ( & V_124 -> V_130 [ V_16 ] ) ;
F_4 ( V_124 , F_82 ( V_16 ) ,
V_124 -> V_15 + V_134 ) ;
V_124 -> V_130 [ V_16 ] . V_55 = V_135 ;
V_124 -> V_130 [ V_16 ] . V_54 = true ;
}
}
return V_132 ;
}
static T_8 F_83 ( int V_122 , void * V_123 )
{
if ( F_74 ( V_122 , V_123 ) == V_132 )
return V_132 ;
return F_81 ( V_122 , V_123 ) ;
}
static void F_84 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
unsigned long V_50 ;
F_27 ( & V_14 -> V_9 . V_52 , V_50 ) ;
if ( F_85 ( V_14 -> V_136 != V_137 ) ) {
F_29 ( & V_14 -> V_9 . V_52 , V_50 ) ;
return;
}
if ( F_86 ( & V_14 -> V_9 ) && ! V_14 -> V_53 )
F_72 ( V_14 ) ;
F_29 ( & V_14 -> V_9 . V_52 , V_50 ) ;
}
static struct V_7 * F_87 ( struct V_138 * V_139 ,
struct V_140 * V_141 )
{
struct V_1 * V_124 = V_141 -> V_142 ;
struct V_7 * V_8 , * V_143 ;
struct V_6 * V_14 ;
unsigned long V_25 = V_124 -> V_27 / V_28 ;
if ( V_139 -> V_144 != 2 )
return NULL ;
F_88 ( & V_124 -> V_145 ) ;
F_89 (chan, _chan, &fsl_edma->dma_dev.channels, device_node) {
if ( V_8 -> V_146 )
continue;
if ( ( V_8 -> V_17 / V_25 ) == V_139 -> args [ 0 ] ) {
V_8 = F_90 ( V_8 ) ;
if ( V_8 ) {
V_8 -> V_147 -> V_148 ++ ;
V_14 = F_12 ( V_8 ) ;
V_14 -> V_149 = V_139 -> args [ 1 ] ;
F_19 ( V_14 , V_14 -> V_149 ,
true ) ;
F_91 ( & V_124 -> V_145 ) ;
return V_8 ;
}
}
}
F_91 ( & V_124 -> V_145 ) ;
return NULL ;
}
static int F_92 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
V_14 -> V_46 = F_93 ( L_1 , V_8 -> V_147 -> V_150 ,
sizeof( struct V_92 ) ,
32 , 0 ) ;
return 0 ;
}
static void F_94 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
unsigned long V_50 ;
F_26 ( V_51 ) ;
F_27 ( & V_14 -> V_9 . V_52 , V_50 ) ;
F_17 ( V_14 ) ;
F_19 ( V_14 , 0 , false ) ;
V_14 -> V_53 = NULL ;
F_28 ( & V_14 -> V_9 , & V_51 ) ;
F_29 ( & V_14 -> V_9 . V_52 , V_50 ) ;
F_30 ( & V_14 -> V_9 , & V_51 ) ;
F_95 ( V_14 -> V_46 ) ;
V_14 -> V_46 = NULL ;
}
static int
F_96 ( struct V_151 * V_152 , struct V_1 * V_124 )
{
int V_153 ;
V_124 -> V_154 = F_97 ( V_152 , L_2 ) ;
if ( V_124 -> V_154 < 0 ) {
F_98 ( & V_152 -> V_150 , L_3 ) ;
return V_124 -> V_154 ;
}
V_124 -> V_155 = F_97 ( V_152 , L_4 ) ;
if ( V_124 -> V_155 < 0 ) {
F_98 ( & V_152 -> V_150 , L_5 ) ;
return V_124 -> V_155 ;
}
if ( V_124 -> V_154 == V_124 -> V_155 ) {
V_153 = F_99 ( & V_152 -> V_150 , V_124 -> V_154 ,
F_83 , 0 , L_6 , V_124 ) ;
if ( V_153 ) {
F_98 ( & V_152 -> V_150 , L_7 ) ;
return V_153 ;
}
} else {
V_153 = F_99 ( & V_152 -> V_150 , V_124 -> V_154 ,
F_74 , 0 , L_8 , V_124 ) ;
if ( V_153 ) {
F_98 ( & V_152 -> V_150 , L_9 ) ;
return V_153 ;
}
V_153 = F_99 ( & V_152 -> V_150 , V_124 -> V_155 ,
F_81 , 0 , L_10 , V_124 ) ;
if ( V_153 ) {
F_98 ( & V_152 -> V_150 , L_11 ) ;
return V_153 ;
}
}
return 0 ;
}
static int F_100 ( struct V_151 * V_152 )
{
struct V_156 * V_157 = V_152 -> V_150 . V_158 ;
struct V_1 * V_124 ;
struct V_6 * V_14 ;
struct V_159 * V_160 ;
int V_79 , V_130 ;
int V_153 , V_43 ;
V_153 = F_101 ( V_157 , L_12 , & V_130 ) ;
if ( V_153 ) {
F_98 ( & V_152 -> V_150 , L_13 ) ;
return V_153 ;
}
V_79 = sizeof( * V_124 ) + sizeof( * V_14 ) * V_130 ;
V_124 = F_102 ( & V_152 -> V_150 , V_79 , V_161 ) ;
if ( ! V_124 )
return - V_162 ;
V_124 -> V_27 = V_130 ;
F_103 ( & V_124 -> V_145 ) ;
V_160 = F_104 ( V_152 , V_163 , 0 ) ;
V_124 -> V_15 = F_105 ( & V_152 -> V_150 , V_160 ) ;
if ( F_106 ( V_124 -> V_15 ) )
return F_107 ( V_124 -> V_15 ) ;
for ( V_43 = 0 ; V_43 < V_28 ; V_43 ++ ) {
char V_164 [ 32 ] ;
V_160 = F_104 ( V_152 , V_163 , 1 + V_43 ) ;
V_124 -> V_29 [ V_43 ] = F_105 ( & V_152 -> V_150 , V_160 ) ;
if ( F_106 ( V_124 -> V_29 [ V_43 ] ) )
return F_107 ( V_124 -> V_29 [ V_43 ] ) ;
sprintf ( V_164 , L_14 , V_43 ) ;
V_124 -> V_165 [ V_43 ] = F_108 ( & V_152 -> V_150 , V_164 ) ;
if ( F_106 ( V_124 -> V_165 [ V_43 ] ) ) {
F_98 ( & V_152 -> V_150 , L_15 ) ;
return F_107 ( V_124 -> V_165 [ V_43 ] ) ;
}
V_153 = F_109 ( V_124 -> V_165 [ V_43 ] ) ;
if ( V_153 ) {
F_98 ( & V_152 -> V_150 , L_16 ) ;
return V_153 ;
}
}
V_124 -> V_4 = F_110 ( V_157 , L_17 ) ;
F_111 ( & V_124 -> V_166 . V_167 ) ;
for ( V_43 = 0 ; V_43 < V_124 -> V_27 ; V_43 ++ ) {
struct V_6 * V_14 = & V_124 -> V_130 [ V_43 ] ;
V_14 -> V_2 = V_124 ;
V_14 -> V_136 = V_137 ;
V_14 -> V_149 = 0 ;
V_14 -> V_54 = true ;
V_14 -> V_9 . V_168 = F_22 ;
F_112 ( & V_14 -> V_9 , & V_124 -> V_166 ) ;
F_6 ( V_124 , 0x0 , V_124 -> V_15 + F_43 ( V_43 ) ) ;
F_19 ( V_14 , 0 , false ) ;
}
F_9 ( V_124 , ~ 0 , V_124 -> V_15 + V_127 ) ;
V_153 = F_96 ( V_152 , V_124 ) ;
if ( V_153 )
return V_153 ;
F_113 ( V_169 , V_124 -> V_166 . V_170 ) ;
F_113 ( V_171 , V_124 -> V_166 . V_170 ) ;
F_113 ( V_172 , V_124 -> V_166 . V_170 ) ;
V_124 -> V_166 . V_150 = & V_152 -> V_150 ;
V_124 -> V_166 . V_173
= F_92 ;
V_124 -> V_166 . V_174
= F_94 ;
V_124 -> V_166 . V_175 = F_39 ;
V_124 -> V_166 . V_176 = F_68 ;
V_124 -> V_166 . V_177 = F_65 ;
V_124 -> V_166 . V_178 = F_33 ;
V_124 -> V_166 . V_179 = F_31 ;
V_124 -> V_166 . V_180 = F_32 ;
V_124 -> V_166 . V_181 = F_25 ;
V_124 -> V_166 . V_182 = F_84 ;
V_124 -> V_166 . V_183 = V_184 ;
V_124 -> V_166 . V_185 = V_184 ;
V_124 -> V_166 . V_186 = F_114 ( V_63 ) | F_114 ( V_70 ) ;
F_115 ( V_152 , V_124 ) ;
V_153 = F_116 ( & V_124 -> V_166 ) ;
if ( V_153 ) {
F_98 ( & V_152 -> V_150 , L_18 ) ;
return V_153 ;
}
V_153 = F_117 ( V_157 , F_87 , V_124 ) ;
if ( V_153 ) {
F_98 ( & V_152 -> V_150 , L_19 ) ;
F_118 ( & V_124 -> V_166 ) ;
return V_153 ;
}
F_9 ( V_124 , V_187 | V_188 , V_124 -> V_15 + V_189 ) ;
return 0 ;
}
static int F_119 ( struct V_151 * V_152 )
{
struct V_156 * V_157 = V_152 -> V_150 . V_158 ;
struct V_1 * V_124 = F_120 ( V_152 ) ;
int V_43 ;
F_121 ( V_157 ) ;
F_118 ( & V_124 -> V_166 ) ;
for ( V_43 = 0 ; V_43 < V_28 ; V_43 ++ )
F_122 ( V_124 -> V_165 [ V_43 ] ) ;
return 0 ;
}
static int F_123 ( struct V_147 * V_150 )
{
struct V_1 * V_124 = F_124 ( V_150 ) ;
struct V_6 * V_14 ;
unsigned long V_50 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_124 -> V_27 ; V_43 ++ ) {
V_14 = & V_124 -> V_130 [ V_43 ] ;
F_27 ( & V_14 -> V_9 . V_52 , V_50 ) ;
if ( F_85 ( ! V_14 -> V_54 ) ) {
F_125 ( V_150 , L_20 ) ;
F_17 ( V_14 ) ;
F_19 ( V_14 , 0 , false ) ;
}
V_14 -> V_136 = V_190 ;
F_29 ( & V_14 -> V_9 . V_52 , V_50 ) ;
}
return 0 ;
}
static int F_126 ( struct V_147 * V_150 )
{
struct V_1 * V_124 = F_124 ( V_150 ) ;
struct V_6 * V_14 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_124 -> V_27 ; V_43 ++ ) {
V_14 = & V_124 -> V_130 [ V_43 ] ;
V_14 -> V_136 = V_137 ;
F_6 ( V_124 , 0x0 , V_124 -> V_15 + F_43 ( V_43 ) ) ;
if ( V_14 -> V_149 != 0 )
F_19 ( V_14 , V_14 -> V_149 , true ) ;
}
F_9 ( V_124 , V_187 | V_188 ,
V_124 -> V_15 + V_189 ) ;
return 0 ;
}
static int T_9 F_127 ( void )
{
return F_128 ( & V_191 ) ;
}
static void T_10 F_129 ( void )
{
F_130 ( & V_191 ) ;
}
