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
V_14 -> V_54 = V_55 ;
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
V_14 -> V_54 = V_56 ;
}
F_29 ( & V_14 -> V_9 . V_52 , V_50 ) ;
return 0 ;
}
static int F_33 ( struct V_7 * V_8 ,
struct V_57 * V_58 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
V_14 -> V_59 . V_60 = V_58 -> V_61 ;
if ( V_58 -> V_61 == V_62 ) {
V_14 -> V_59 . V_63 = V_58 -> V_64 ;
V_14 -> V_59 . V_33 = V_58 -> V_65 ;
V_14 -> V_59 . V_66 = V_58 -> V_67 ;
V_14 -> V_59 . V_68 = F_21 ( V_58 -> V_65 ) ;
} else if ( V_58 -> V_61 == V_69 ) {
V_14 -> V_59 . V_63 = V_58 -> V_70 ;
V_14 -> V_59 . V_33 = V_58 -> V_71 ;
V_14 -> V_59 . V_66 = V_58 -> V_72 ;
V_14 -> V_59 . V_68 = F_21 ( V_58 -> V_71 ) ;
} else {
return - V_73 ;
}
return 0 ;
}
static T_5 F_34 ( struct V_6 * V_14 ,
struct V_11 * V_13 , bool V_74 )
{
struct V_10 * V_53 = V_14 -> V_53 ;
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_1 V_16 = V_14 -> V_9 . V_8 . V_17 ;
enum V_75 V_60 = V_14 -> V_59 . V_60 ;
T_6 V_76 , V_77 ;
T_5 V_78 , V_79 ;
int V_43 ;
for ( V_78 = V_43 = 0 ; V_43 < V_14 -> V_53 -> V_44 ; V_43 ++ )
V_78 += F_35 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_80 )
* F_36 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_81 ) ;
if ( ! V_74 )
return V_78 ;
if ( V_60 == V_69 )
V_76 = F_1 ( V_14 -> V_2 , V_3 + F_37 ( V_16 ) ) ;
else
V_76 = F_1 ( V_14 -> V_2 , V_3 + F_38 ( V_16 ) ) ;
for ( V_43 = 0 ; V_43 < V_14 -> V_53 -> V_44 ; V_43 ++ ) {
V_79 = F_35 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_80 )
* F_36 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_81 ) ;
if ( V_60 == V_69 )
V_77 = F_35 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_82 ) ;
else
V_77 = F_35 ( V_53 -> V_47 [ V_43 ] . V_48 -> V_83 ) ;
V_78 -= V_79 ;
if ( V_76 >= V_77 && V_76 < V_77 + V_79 ) {
V_78 += V_77 + V_79 - V_76 ;
break;
}
}
return V_78 ;
}
static enum V_84 F_39 ( struct V_7 * V_8 ,
T_7 V_85 , struct V_86 * V_87 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
struct V_11 * V_13 ;
enum V_84 V_54 ;
unsigned long V_50 ;
V_54 = F_40 ( V_8 , V_85 , V_87 ) ;
if ( V_54 == V_88 )
return V_54 ;
if ( ! V_87 )
return V_14 -> V_54 ;
F_27 ( & V_14 -> V_9 . V_52 , V_50 ) ;
V_13 = F_41 ( & V_14 -> V_9 , V_85 ) ;
if ( V_14 -> V_53 && V_85 == V_14 -> V_53 -> V_13 . V_89 . V_85 )
V_87 -> V_90 = F_34 ( V_14 , V_13 , true ) ;
else if ( V_13 )
V_87 -> V_90 = F_34 ( V_14 , V_13 , false ) ;
else
V_87 -> V_90 = 0 ;
F_29 ( & V_14 -> V_9 . V_52 , V_50 ) ;
return V_14 -> V_54 ;
}
static void F_42 ( struct V_6 * V_14 ,
struct V_91 * V_47 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
void T_2 * V_3 = V_14 -> V_2 -> V_15 ;
T_1 V_16 = V_14 -> V_9 . V_8 . V_17 ;
F_6 ( V_2 , 0 , V_3 + F_43 ( V_16 ) ) ;
F_9 ( V_2 , F_35 ( V_47 -> V_82 ) , V_3 + F_37 ( V_16 ) ) ;
F_9 ( V_2 , F_35 ( V_47 -> V_83 ) , V_3 + F_38 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_68 ) , V_3 + F_44 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_92 ) , V_3 + F_45 ( V_16 ) ) ;
F_9 ( V_2 , F_35 ( V_47 -> V_80 ) , V_3 + F_46 ( V_16 ) ) ;
F_9 ( V_2 , F_35 ( V_47 -> V_93 ) , V_3 + F_47 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_94 ) , V_3 + F_48 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_81 ) , V_3 + F_49 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_95 ) , V_3 + F_50 ( V_16 ) ) ;
F_9 ( V_2 , F_35 ( V_47 -> V_96 ) , V_3 + F_51 ( V_16 ) ) ;
F_6 ( V_2 , F_36 ( V_47 -> V_97 ) , V_3 + F_43 ( V_16 ) ) ;
}
static inline
void F_52 ( struct V_91 * V_47 , T_1 V_98 , T_1 V_99 ,
T_4 V_68 , T_4 V_92 , T_1 V_80 , T_1 V_93 , T_4 V_94 ,
T_4 V_81 , T_4 V_95 , T_1 V_96 , bool V_100 ,
bool V_101 , bool V_102 )
{
T_4 V_97 = 0 ;
V_47 -> V_82 = F_53 ( V_98 ) ;
V_47 -> V_83 = F_53 ( V_99 ) ;
V_47 -> V_68 = F_54 ( V_68 ) ;
V_47 -> V_92 = F_54 ( F_55 ( V_92 ) ) ;
V_47 -> V_80 = F_53 ( F_56 ( V_80 ) ) ;
V_47 -> V_93 = F_53 ( F_57 ( V_93 ) ) ;
V_47 -> V_94 = F_54 ( F_58 ( V_94 ) ) ;
V_47 -> V_95 = F_54 ( F_59 ( V_95 ) ) ;
V_47 -> V_96 = F_53 ( F_60 ( V_96 ) ) ;
V_47 -> V_81 = F_54 ( F_61 ( V_81 ) ) ;
if ( V_100 )
V_97 |= V_103 ;
if ( V_101 )
V_97 |= V_104 ;
if ( V_102 )
V_97 |= V_105 ;
V_47 -> V_97 = F_54 ( V_97 ) ;
}
static struct V_10 * F_62 ( struct V_6 * V_14 ,
int V_106 )
{
struct V_10 * V_42 ;
int V_43 ;
V_42 = F_63 ( sizeof( * V_42 ) + sizeof( struct V_107 ) * V_106 ,
V_108 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_45 = V_14 ;
V_42 -> V_44 = V_106 ;
for ( V_43 = 0 ; V_43 < V_106 ; V_43 ++ ) {
V_42 -> V_47 [ V_43 ] . V_48 = F_64 ( V_14 -> V_46 ,
V_108 , & V_42 -> V_47 [ V_43 ] . V_49 ) ;
if ( ! V_42 -> V_47 [ V_43 ] . V_48 )
goto V_109;
}
return V_42 ;
V_109:
while ( -- V_43 >= 0 )
F_23 ( V_14 -> V_46 , V_42 -> V_47 [ V_43 ] . V_48 ,
V_42 -> V_47 [ V_43 ] . V_49 ) ;
F_24 ( V_42 ) ;
return NULL ;
}
static struct V_110 * F_65 (
struct V_7 * V_8 , T_6 V_77 , T_5 V_111 ,
T_5 V_112 , enum V_75 V_61 ,
unsigned long V_50 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
struct V_10 * V_42 ;
T_6 V_113 ;
int V_106 , V_43 ;
T_1 V_64 , V_70 , V_114 , V_80 ;
T_4 V_92 , V_95 , V_115 ;
if ( ! F_66 ( V_14 -> V_59 . V_60 ) )
return NULL ;
V_106 = V_111 / V_112 ;
V_42 = F_62 ( V_14 , V_106 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_116 = true ;
V_113 = V_77 ;
V_80 = V_14 -> V_59 . V_33 * V_14 -> V_59 . V_66 ;
V_115 = V_112 / V_80 ;
for ( V_43 = 0 ; V_43 < V_106 ; V_43 ++ ) {
if ( V_113 >= V_77 + V_111 )
V_113 = V_77 ;
V_114 = V_42 -> V_47 [ ( V_43 + 1 ) % V_106 ] . V_49 ;
if ( V_14 -> V_59 . V_60 == V_69 ) {
V_64 = V_113 ;
V_70 = V_14 -> V_59 . V_63 ;
V_92 = V_14 -> V_59 . V_33 ;
V_95 = 0 ;
} else {
V_64 = V_14 -> V_59 . V_63 ;
V_70 = V_113 ;
V_92 = 0 ;
V_95 = V_14 -> V_59 . V_33 ;
}
F_52 ( V_42 -> V_47 [ V_43 ] . V_48 , V_64 , V_70 ,
V_14 -> V_59 . V_68 , V_92 , V_80 , 0 , V_115 ,
V_115 , V_95 , V_114 , true , false , true ) ;
V_113 += V_112 ;
}
return F_67 ( & V_14 -> V_9 , & V_42 -> V_13 , V_50 ) ;
}
static struct V_110 * F_68 (
struct V_7 * V_8 , struct V_117 * V_118 ,
unsigned int V_106 , enum V_75 V_61 ,
unsigned long V_50 , void * V_119 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
struct V_10 * V_42 ;
struct V_117 * V_120 ;
T_1 V_64 , V_70 , V_114 , V_80 ;
T_4 V_92 , V_95 , V_115 ;
int V_43 ;
if ( ! F_66 ( V_14 -> V_59 . V_60 ) )
return NULL ;
V_42 = F_62 ( V_14 , V_106 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_116 = false ;
V_80 = V_14 -> V_59 . V_33 * V_14 -> V_59 . V_66 ;
F_69 (sgl, sg, sg_len, i) {
V_114 = V_42 -> V_47 [ ( V_43 + 1 ) % V_106 ] . V_49 ;
if ( V_14 -> V_59 . V_60 == V_69 ) {
V_64 = F_70 ( V_120 ) ;
V_70 = V_14 -> V_59 . V_63 ;
V_92 = V_14 -> V_59 . V_33 ;
V_95 = 0 ;
} else {
V_64 = V_14 -> V_59 . V_63 ;
V_70 = F_70 ( V_120 ) ;
V_92 = 0 ;
V_95 = V_14 -> V_59 . V_33 ;
}
V_115 = F_71 ( V_120 ) / V_80 ;
if ( V_43 < V_106 - 1 ) {
V_114 = V_42 -> V_47 [ ( V_43 + 1 ) ] . V_49 ;
F_52 ( V_42 -> V_47 [ V_43 ] . V_48 , V_64 ,
V_70 , V_14 -> V_59 . V_68 , V_92 ,
V_80 , 0 , V_115 , V_115 , V_95 , V_114 ,
false , false , true ) ;
} else {
V_114 = 0 ;
F_52 ( V_42 -> V_47 [ V_43 ] . V_48 , V_64 ,
V_70 , V_14 -> V_59 . V_68 , V_92 ,
V_80 , 0 , V_115 , V_115 , V_95 , V_114 ,
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
V_14 -> V_54 = V_56 ;
}
static T_8 F_74 ( int V_121 , void * V_122 )
{
struct V_1 * V_123 = V_122 ;
unsigned int V_124 , V_16 ;
void T_2 * V_125 ;
struct V_6 * V_14 ;
V_125 = V_123 -> V_15 ;
V_124 = F_1 ( V_123 , V_125 + V_126 ) ;
if ( ! V_124 )
return V_127 ;
for ( V_16 = 0 ; V_16 < V_123 -> V_27 ; V_16 ++ ) {
if ( V_124 & ( 0x1 << V_16 ) ) {
F_4 ( V_123 , F_75 ( V_16 ) ,
V_125 + V_128 ) ;
V_14 = & V_123 -> V_129 [ V_16 ] ;
F_76 ( & V_14 -> V_9 . V_52 ) ;
if ( ! V_14 -> V_53 -> V_116 ) {
F_77 ( & V_14 -> V_53 -> V_13 . V_130 ) ;
F_78 ( & V_14 -> V_53 -> V_13 ) ;
V_14 -> V_53 = NULL ;
V_14 -> V_54 = V_88 ;
} else {
F_79 ( & V_14 -> V_53 -> V_13 ) ;
}
if ( ! V_14 -> V_53 )
F_72 ( V_14 ) ;
F_80 ( & V_14 -> V_9 . V_52 ) ;
}
}
return V_131 ;
}
static T_8 F_81 ( int V_121 , void * V_122 )
{
struct V_1 * V_123 = V_122 ;
unsigned int V_109 , V_16 ;
V_109 = F_1 ( V_123 , V_123 -> V_15 + V_132 ) ;
if ( ! V_109 )
return V_127 ;
for ( V_16 = 0 ; V_16 < V_123 -> V_27 ; V_16 ++ ) {
if ( V_109 & ( 0x1 << V_16 ) ) {
F_17 ( & V_123 -> V_129 [ V_16 ] ) ;
F_4 ( V_123 , F_82 ( V_16 ) ,
V_123 -> V_15 + V_133 ) ;
V_123 -> V_129 [ V_16 ] . V_54 = V_134 ;
}
}
return V_131 ;
}
static T_8 F_83 ( int V_121 , void * V_122 )
{
if ( F_74 ( V_121 , V_122 ) == V_131 )
return V_131 ;
return F_81 ( V_121 , V_122 ) ;
}
static void F_84 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
unsigned long V_50 ;
F_27 ( & V_14 -> V_9 . V_52 , V_50 ) ;
if ( F_85 ( & V_14 -> V_9 ) && ! V_14 -> V_53 )
F_72 ( V_14 ) ;
F_29 ( & V_14 -> V_9 . V_52 , V_50 ) ;
}
static struct V_7 * F_86 ( struct V_135 * V_136 ,
struct V_137 * V_138 )
{
struct V_1 * V_123 = V_138 -> V_139 ;
struct V_7 * V_8 , * V_140 ;
unsigned long V_25 = V_123 -> V_27 / V_28 ;
if ( V_136 -> V_141 != 2 )
return NULL ;
F_87 ( & V_123 -> V_142 ) ;
F_88 (chan, _chan, &fsl_edma->dma_dev.channels, device_node) {
if ( V_8 -> V_143 )
continue;
if ( ( V_8 -> V_17 / V_25 ) == V_136 -> args [ 0 ] ) {
V_8 = F_89 ( V_8 ) ;
if ( V_8 ) {
V_8 -> V_144 -> V_145 ++ ;
F_19 ( F_12 ( V_8 ) ,
V_136 -> args [ 1 ] , true ) ;
F_90 ( & V_123 -> V_142 ) ;
return V_8 ;
}
}
}
F_90 ( & V_123 -> V_142 ) ;
return NULL ;
}
static int F_91 ( struct V_7 * V_8 )
{
struct V_6 * V_14 = F_12 ( V_8 ) ;
V_14 -> V_46 = F_92 ( L_1 , V_8 -> V_144 -> V_146 ,
sizeof( struct V_91 ) ,
32 , 0 ) ;
return 0 ;
}
static void F_93 ( struct V_7 * V_8 )
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
F_94 ( V_14 -> V_46 ) ;
V_14 -> V_46 = NULL ;
}
static int
F_95 ( struct V_147 * V_148 , struct V_1 * V_123 )
{
int V_149 ;
V_123 -> V_150 = F_96 ( V_148 , L_2 ) ;
if ( V_123 -> V_150 < 0 ) {
F_97 ( & V_148 -> V_146 , L_3 ) ;
return V_123 -> V_150 ;
}
V_123 -> V_151 = F_96 ( V_148 , L_4 ) ;
if ( V_123 -> V_151 < 0 ) {
F_97 ( & V_148 -> V_146 , L_5 ) ;
return V_123 -> V_151 ;
}
if ( V_123 -> V_150 == V_123 -> V_151 ) {
V_149 = F_98 ( & V_148 -> V_146 , V_123 -> V_150 ,
F_83 , 0 , L_6 , V_123 ) ;
if ( V_149 ) {
F_97 ( & V_148 -> V_146 , L_7 ) ;
return V_149 ;
}
} else {
V_149 = F_98 ( & V_148 -> V_146 , V_123 -> V_150 ,
F_74 , 0 , L_8 , V_123 ) ;
if ( V_149 ) {
F_97 ( & V_148 -> V_146 , L_9 ) ;
return V_149 ;
}
V_149 = F_98 ( & V_148 -> V_146 , V_123 -> V_151 ,
F_81 , 0 , L_10 , V_123 ) ;
if ( V_149 ) {
F_97 ( & V_148 -> V_146 , L_11 ) ;
return V_149 ;
}
}
return 0 ;
}
static int F_99 ( struct V_147 * V_148 )
{
struct V_152 * V_153 = V_148 -> V_146 . V_154 ;
struct V_1 * V_123 ;
struct V_6 * V_14 ;
struct V_155 * V_156 ;
int V_78 , V_129 ;
int V_149 , V_43 ;
V_149 = F_100 ( V_153 , L_12 , & V_129 ) ;
if ( V_149 ) {
F_97 ( & V_148 -> V_146 , L_13 ) ;
return V_149 ;
}
V_78 = sizeof( * V_123 ) + sizeof( * V_14 ) * V_129 ;
V_123 = F_101 ( & V_148 -> V_146 , V_78 , V_157 ) ;
if ( ! V_123 )
return - V_158 ;
V_123 -> V_27 = V_129 ;
F_102 ( & V_123 -> V_142 ) ;
V_156 = F_103 ( V_148 , V_159 , 0 ) ;
V_123 -> V_15 = F_104 ( & V_148 -> V_146 , V_156 ) ;
if ( F_105 ( V_123 -> V_15 ) )
return F_106 ( V_123 -> V_15 ) ;
for ( V_43 = 0 ; V_43 < V_28 ; V_43 ++ ) {
char V_160 [ 32 ] ;
V_156 = F_103 ( V_148 , V_159 , 1 + V_43 ) ;
V_123 -> V_29 [ V_43 ] = F_104 ( & V_148 -> V_146 , V_156 ) ;
if ( F_105 ( V_123 -> V_29 [ V_43 ] ) )
return F_106 ( V_123 -> V_29 [ V_43 ] ) ;
sprintf ( V_160 , L_14 , V_43 ) ;
V_123 -> V_161 [ V_43 ] = F_107 ( & V_148 -> V_146 , V_160 ) ;
if ( F_105 ( V_123 -> V_161 [ V_43 ] ) ) {
F_97 ( & V_148 -> V_146 , L_15 ) ;
return F_106 ( V_123 -> V_161 [ V_43 ] ) ;
}
V_149 = F_108 ( V_123 -> V_161 [ V_43 ] ) ;
if ( V_149 ) {
F_97 ( & V_148 -> V_146 , L_16 ) ;
return V_149 ;
}
}
V_123 -> V_4 = F_109 ( V_153 , L_17 ) ;
F_110 ( & V_123 -> V_162 . V_163 ) ;
for ( V_43 = 0 ; V_43 < V_123 -> V_27 ; V_43 ++ ) {
struct V_6 * V_14 = & V_123 -> V_129 [ V_43 ] ;
V_14 -> V_2 = V_123 ;
V_14 -> V_9 . V_164 = F_22 ;
F_111 ( & V_14 -> V_9 , & V_123 -> V_162 ) ;
F_6 ( V_123 , 0x0 , V_123 -> V_15 + F_43 ( V_43 ) ) ;
F_19 ( V_14 , 0 , false ) ;
}
F_9 ( V_123 , ~ 0 , V_123 -> V_15 + V_126 ) ;
V_149 = F_95 ( V_148 , V_123 ) ;
if ( V_149 )
return V_149 ;
F_112 ( V_165 , V_123 -> V_162 . V_166 ) ;
F_112 ( V_167 , V_123 -> V_162 . V_166 ) ;
F_112 ( V_168 , V_123 -> V_162 . V_166 ) ;
V_123 -> V_162 . V_146 = & V_148 -> V_146 ;
V_123 -> V_162 . V_169
= F_91 ;
V_123 -> V_162 . V_170
= F_93 ;
V_123 -> V_162 . V_171 = F_39 ;
V_123 -> V_162 . V_172 = F_68 ;
V_123 -> V_162 . V_173 = F_65 ;
V_123 -> V_162 . V_174 = F_33 ;
V_123 -> V_162 . V_175 = F_31 ;
V_123 -> V_162 . V_176 = F_32 ;
V_123 -> V_162 . V_177 = F_25 ;
V_123 -> V_162 . V_178 = F_84 ;
V_123 -> V_162 . V_179 = V_180 ;
V_123 -> V_162 . V_181 = V_180 ;
V_123 -> V_162 . V_182 = F_113 ( V_62 ) | F_113 ( V_69 ) ;
F_114 ( V_148 , V_123 ) ;
V_149 = F_115 ( & V_123 -> V_162 ) ;
if ( V_149 ) {
F_97 ( & V_148 -> V_146 , L_18 ) ;
return V_149 ;
}
V_149 = F_116 ( V_153 , F_86 , V_123 ) ;
if ( V_149 ) {
F_97 ( & V_148 -> V_146 , L_19 ) ;
F_117 ( & V_123 -> V_162 ) ;
return V_149 ;
}
F_9 ( V_123 , V_183 | V_184 , V_123 -> V_15 + V_185 ) ;
return 0 ;
}
static int F_118 ( struct V_147 * V_148 )
{
struct V_152 * V_153 = V_148 -> V_146 . V_154 ;
struct V_1 * V_123 = F_119 ( V_148 ) ;
int V_43 ;
F_120 ( V_153 ) ;
F_117 ( & V_123 -> V_162 ) ;
for ( V_43 = 0 ; V_43 < V_28 ; V_43 ++ )
F_121 ( V_123 -> V_161 [ V_43 ] ) ;
return 0 ;
}
static int T_9 F_122 ( void )
{
return F_123 ( & V_186 ) ;
}
static void T_10 F_124 ( void )
{
F_125 ( & V_186 ) ;
}
