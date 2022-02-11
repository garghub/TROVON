static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_6 ;
}
static struct V_7 * F_3 ( struct V_8 * V_9 )
{
return F_4 ( V_9 , struct V_7 , V_10 ) ;
}
static struct V_11 * F_5 ( struct V_2 * V_3 )
{
int V_12 ;
struct V_13 * V_14 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_14 = V_5 -> V_15 -> V_16 [ 0 ] ;
V_12 = V_5 -> V_17 ;
return & V_14 -> V_18 [ V_12 ] ;
}
static int F_6 (
struct V_7 * V_15 , int V_19 )
{
return V_15 -> V_20 [ 0 ] -> V_21 ;
}
static int F_7 (
struct V_7 * V_15 , int V_19 )
{
return V_15 -> V_20 [ 0 ] -> V_22 ;
}
static struct V_23 * F_8 (
struct V_7 * V_15 , int V_19 )
{
struct V_24 * V_25 = V_15 -> V_20 [ 0 ] ;
int V_26 = V_25 -> V_21 ;
int V_27 = V_25 -> V_22 ;
return & V_25 -> V_23 [ V_19 * V_26 * V_27 ] ;
}
static struct V_23 * F_9 ( struct V_28 * V_29 )
{
return F_4 ( V_29 , struct V_23 , V_29 ) ;
}
struct V_2 * F_10 ( struct V_8 * V_9 ,
T_1 V_30 )
{
int V_31 ;
int V_32 ;
int V_33 ;
struct V_7 * V_15 ;
struct V_2 * V_34 ;
struct V_23 * V_23 ;
struct V_4 * V_5 ;
V_15 = F_3 ( V_9 ) ;
V_23 = F_8 ( V_15 , V_30 ) ;
V_31 = F_7 ( V_15 , V_30 ) ;
V_32 = F_6 ( V_15 , V_30 ) ;
V_5 = F_11 ( sizeof( * V_5 ) +
V_32 * sizeof( struct V_28 * ) , V_35 ) ;
if ( F_12 ( ! V_5 ) ) {
F_13 ( V_15 -> V_9 , L_1 ) ;
V_34 = F_14 ( - V_36 ) ;
goto V_37;
}
V_34 = & V_5 -> V_34 ;
V_34 -> V_38 = V_15 -> V_9 ;
V_34 -> V_9 = V_9 ;
V_34 -> V_26 = V_32 ;
V_34 -> V_39 = V_40 ;
for ( V_34 -> V_41 = 0 ;
V_34 -> V_41 < V_31 ; V_34 -> V_41 ++ ) {
if ( ! V_23 -> V_42 )
break;
V_23 += V_32 ;
}
if ( V_34 -> V_41 >= V_31 ) {
F_13 ( V_15 -> V_9 , L_2 ) ;
V_34 = F_14 ( - V_43 ) ;
goto V_44;
}
V_34 -> V_45 = (struct V_28 * * ) ( & V_34 -> V_45 + 1 ) ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
V_34 -> V_45 [ V_33 ] = & V_23 -> V_29 ;
V_34 -> V_45 [ V_33 ] -> V_46 . V_29 = V_34 -> V_45 [ V_33 ] ;
V_34 -> V_45 [ V_33 ] -> V_47 . V_29 = V_34 -> V_45 [ V_33 ] ;
V_23 -> V_42 = 1 ;
V_23 ++ ;
}
V_5 -> V_15 = V_15 ;
V_5 -> V_17 = V_30 ;
V_5 -> V_6 = V_15 -> V_6 [ V_30 ] ;
V_34 -> V_48 = V_5 -> V_6 -> V_48 ;
V_34 -> V_49 = V_5 -> V_6 -> V_49 ;
V_34 -> V_50 = V_5 -> V_6 -> V_50 ;
V_34 -> V_51 = V_5 -> V_6 -> V_52 ;
V_34 -> V_53 = V_5 -> V_6 -> V_53 ;
V_34 -> V_54 = V_30 ;
return V_34 ;
V_44:
F_15 ( V_5 ) ;
V_37:
return V_34 ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_33 ;
V_5 -> V_6 = NULL ;
F_15 ( V_5 ) ;
for ( V_33 = 0 ; V_33 < V_3 -> V_26 ; V_33 ++ )
F_9 ( V_3 -> V_45 [ V_33 ] ) -> V_42 = 0 ;
}
static void F_17 ( struct V_2 * V_3 , int V_55 )
{
int V_26 = V_3 -> V_26 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_26 ; V_33 ++ )
F_18 ( V_3 -> V_45 [ V_33 ] , V_55 ) ;
}
static void F_19 ( struct V_28 * V_29 )
{
struct V_23 * V_56 =
F_4 ( V_29 , struct V_23 , V_29 ) ;
F_20 ( V_56 ) ;
}
static void F_21 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 -> V_3 ) ;
if ( V_5 -> V_6 -> V_52 == V_57 )
F_22 ( V_29 ) ;
}
static int F_23 ( struct V_2 * V_3 , void * V_58 )
{
int V_59 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( ! V_58 || ! F_24 ( ( const V_60 * ) V_58 ) ) {
F_13 ( V_3 -> V_38 , L_3 ) ;
return - V_61 ;
}
V_59 = F_25 ( V_6 , V_3 -> V_41 , V_58 ) ;
if ( V_59 != 0 ) {
F_13 ( V_3 -> V_38 ,
L_4 , V_59 ) ;
return V_59 ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
const unsigned char * V_62 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_52 != V_57 )
return - V_63 ;
return F_27 ( V_6 , V_3 -> V_41 , V_62 ) ;
}
static int F_28 ( struct V_2 * V_3 ,
const unsigned char * V_62 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_52 != V_57 )
return - V_63 ;
return F_29 ( V_6 , V_3 -> V_41 , V_62 ) ;
}
static int F_30 ( struct V_2 * V_3 , void * V_62 )
{
int V_59 ;
char * V_64 = ( char * ) V_62 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_60 V_65 ;
assert ( V_6 ) ;
if ( V_6 -> V_52 != V_57 )
return 0 ;
V_59 = F_31 ( V_6 , V_6 -> V_66 , V_64 , true ) ;
if ( V_59 ) {
F_13 ( V_3 -> V_38 ,
L_5 ,
V_64 , V_6 -> V_66 , V_59 ) ;
return V_59 ;
}
V_59 = F_32 ( V_6 , V_3 -> V_41 , & V_65 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_31 ( V_6 , V_65 , V_64 , true ) ;
if ( V_59 )
F_13 ( V_3 -> V_38 ,
L_5 ,
V_64 , V_67 , V_59 ) ;
return V_59 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_52 != V_57 )
return 0 ;
return F_34 ( V_6 , V_3 -> V_41 ) ;
}
static int F_35 ( struct V_2 * V_3 , int V_68 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_28 * V_29 ;
T_1 V_69 ;
int V_33 , V_59 ;
if ( ! F_36 ( V_6 -> V_15 -> V_70 ) ) {
if ( V_68 <= V_71 )
V_69 = 2048 ;
else
V_69 = 4096 ;
} else {
V_69 = V_6 -> V_15 -> V_72 ;
}
V_59 = F_37 ( V_6 , V_68 , V_69 ) ;
if ( ! V_59 ) {
for ( V_33 = 0 ; V_33 < V_3 -> V_26 ; V_33 ++ ) {
V_29 = V_3 -> V_45 [ V_33 ] ;
V_29 -> V_46 . V_72 = V_69 ;
F_38 ( V_29 , V_69 ) ;
}
}
return V_59 ;
}
static void F_39 ( struct V_2 * V_3 , int V_73 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
F_40 ( V_18 , V_73 ) ;
}
static int F_41 ( struct V_2 * V_3 )
{
int V_59 ;
int V_74 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_59 = F_42 ( V_6 , 0 , true ) ;
if ( V_59 )
return V_59 ;
for ( V_74 = 0 ; V_74 < V_3 -> V_26 ; V_74 ++ ) {
if ( F_36 ( V_6 -> V_15 -> V_70 ) )
F_43 ( V_3 -> V_45 [ V_74 ] ,
V_75 | V_76 ) ;
else
F_44 ( V_3 -> V_45 [ V_74 ] ,
V_75 | V_76 ) ;
}
F_17 ( V_3 , 1 ) ;
F_45 ( 100 ) ;
F_46 ( V_6 ) ;
return 0 ;
}
void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_48 ( V_3 -> V_45 , V_3 -> V_26 , V_75 ) ;
F_45 ( 20 ) ;
F_49 ( V_6 ) ;
F_50 ( 10000 , 20000 ) ;
F_17 ( V_3 , 0 ) ;
( void ) F_42 ( V_6 , 0 , false ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_6 -> V_52 == V_77 ) {
F_52 ( V_5 -> V_6 ) ;
F_53 ( V_5 -> V_15 , 0 ) ;
}
}
void F_54 ( struct V_78 * V_56 , T_1 V_79 )
{
T_1 V_80 ;
if ( F_55 ( V_56 ) )
V_80 = V_75 ;
else
V_80 = V_76 ;
F_56 ( V_56 -> V_29 , V_80 , V_79 ) ;
}
static void F_57 ( struct V_78 * V_56 , T_1 V_79 )
{
T_1 V_80 ;
if ( F_55 ( V_56 ) )
V_80 = V_75 ;
else
V_80 = V_76 ;
F_58 ( V_56 -> V_29 , V_80 , V_79 ) ;
}
static int F_59 ( struct V_2 * V_3 )
{
T_1 V_81 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_60 ( V_6 , & V_81 ) ;
return ! ! V_81 ;
}
static int F_61 ( struct V_2 * V_3 ,
V_60 * V_82 , T_2 * V_83 , V_60 * V_84 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_62 ( V_6 , V_82 , V_83 , V_84 ) ;
}
static void F_63 ( struct V_2 * V_3 , int V_83 ,
int V_84 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_64 ( V_6 , V_83 , V_84 ) ;
}
static void F_65 ( struct V_28 * V_85 ,
T_1 * V_86 )
{
* V_86 = V_87 ;
}
static void F_66 ( struct V_2 * V_3 ,
T_1 * V_82 , T_1 * V_88 , T_1 * V_89 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_15 = V_6 -> V_15 ;
F_67 ( V_6 , V_82 ) ;
F_68 ( V_6 , V_88 , V_89 ) ;
if ( V_3 -> V_51 == V_57 )
F_69 ( V_15 , V_6 -> V_66 , V_88 ) ;
}
static int F_70 ( struct V_2 * V_3 , V_60 V_73 )
{
assert ( V_3 ) ;
return F_71 ( F_1 ( V_3 ) , V_73 ) ;
}
static void F_72 ( struct V_2 * V_3 , T_1 V_90 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_73 ( F_3 ( V_3 -> V_9 ) , V_90 ) ;
F_74 ( V_6 , ( V_60 ) ! ! V_90 ) ;
}
static int F_75 ( struct V_2 * V_3 )
{
T_1 V_82 ;
assert ( V_3 ) ;
F_67 ( F_1 ( V_3 ) , & V_82 ) ;
return V_82 ;
}
static int F_76 ( struct V_2 * V_3 ,
T_1 V_91 , T_1 V_88 , T_1 V_89 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_15 = V_6 -> V_15 ;
int V_59 ;
V_59 = F_71 ( V_6 , V_91 ) ;
if ( V_59 )
return V_59 ;
if ( V_3 -> V_51 == V_57 ) {
V_59 = F_77 ( V_15 ,
V_6 -> V_66 , V_88 ) ;
if ( V_59 )
return V_59 ;
V_88 = 0 ;
}
return F_78 ( V_6 , V_88 , V_89 ) ;
}
static void F_79 ( struct V_2 * V_3 ,
T_1 * V_92 , T_1 * V_93 )
{
struct V_23 * V_94 =
F_4 ( V_3 -> V_45 [ 0 ] , struct V_23 , V_29 ) ;
* V_92 = F_80 ( V_94 -> V_20 ,
V_94 -> V_95 ) ;
* V_93 = F_80 ( V_94 -> V_20 ,
V_94 -> V_95 ) ;
}
static void F_81 ( struct V_2 * V_3 ,
T_1 * V_96 , T_1 * V_97 )
{
struct V_23 * V_94 =
F_4 ( V_3 -> V_45 [ 0 ] , struct V_23 , V_29 ) ;
struct V_7 * V_15 = F_3 ( V_3 -> V_9 ) ;
if ( F_36 ( V_15 -> V_70 ) ||
V_3 -> V_51 == V_77 )
* V_96 = F_82 (
V_94 -> V_20 , V_94 -> V_95 ) ;
else
* V_96 = F_83 (
V_94 -> V_20 , V_94 -> V_95 ) ;
* V_97 = F_82 ( V_94 -> V_20 ,
V_94 -> V_95 ) ;
}
static int F_84 ( struct V_2 * V_3 ,
T_1 V_98 )
{
struct V_23 * V_94 =
F_4 ( V_3 -> V_45 [ 0 ] , struct V_23 , V_29 ) ;
return F_85 (
V_94 -> V_20 , V_94 -> V_95 , V_98 ) ;
}
static int F_86 ( struct V_2 * V_3 ,
T_1 V_96 , T_1 V_97 )
{
int V_59 ;
struct V_23 * V_94 =
F_4 ( V_3 -> V_45 [ 0 ] , struct V_23 , V_29 ) ;
struct V_7 * V_15 = F_3 ( V_3 -> V_9 ) ;
if ( F_36 ( V_15 -> V_70 ) ||
V_3 -> V_51 == V_77 ) {
if ( V_96 != V_97 )
return - V_43 ;
return F_87 (
V_94 -> V_20 ,
V_94 -> V_95 , V_97 ) ;
} else {
if ( V_96 != 1 )
return - V_43 ;
V_59 = F_88 (
V_94 -> V_20 ,
V_94 -> V_95 , V_96 ) ;
if ( V_59 )
return V_59 ;
return F_87 (
V_94 -> V_20 ,
V_94 -> V_95 , V_97 ) ;
}
}
static void F_89 ( struct V_2 * V_3 ,
T_1 * V_99 , T_1 * V_100 ,
T_1 * V_101 , T_1 * V_102 ,
T_1 * V_103 , T_1 * V_104 ,
T_1 * V_105 , T_1 * V_106 )
{
struct V_7 * V_15 ;
assert ( V_3 ) ;
V_15 = F_3 ( V_3 -> V_9 ) ;
* V_99 = V_107 ;
* V_100 = V_108 ;
if ( F_36 ( V_15 -> V_70 ) ||
V_3 -> V_51 == V_77 )
* V_101 =
( V_15 -> V_109 - 1 > V_110 ) ?
V_110 : V_15 -> V_109 - 1 ;
else
* V_101 = 1 ;
* V_102 = ( V_15 -> V_109 - 1 > V_111 ) ?
V_111 : V_15 -> V_109 - 1 ;
* V_103 = V_112 ;
* V_104 = V_113 ;
* V_105 = V_114 ;
* V_106 = V_115 ;
}
void F_90 ( struct V_2 * V_3 ,
struct V_116 * V_117 )
{
int V_19 ;
int V_118 ;
struct V_7 * V_15 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
struct V_28 * V_85 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_3 V_119 = 0 , V_120 = 0 , V_121 = 0 , V_122 = 0 ;
T_3 V_123 = 0 , V_124 = 0 , V_125 = 0 ;
T_3 V_126 = 0 ;
V_15 = F_3 ( V_3 -> V_9 ) ;
if ( ! V_15 )
return;
V_19 = V_5 -> V_17 ;
V_18 = F_5 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
for ( V_118 = 0 ; V_118 < V_3 -> V_26 ; V_118 ++ ) {
V_85 = V_3 -> V_45 [ V_118 ] ;
F_91 ( V_85 ) ;
V_119 += V_85 -> V_47 . V_127 . V_119 ;
V_121 += V_85 -> V_47 . V_127 . V_128 ;
V_120 += V_85 -> V_46 . V_127 . V_120 ;
V_122 += V_85 -> V_46 . V_127 . V_129 ;
V_123 += V_85 -> V_46 . V_127 . V_130
+ V_85 -> V_46 . V_127 . V_131
+ V_85 -> V_46 . V_127 . V_132 ;
}
F_92 ( V_18 ) ;
V_126 = V_18 -> V_133 . V_134 ;
V_124 += V_18 -> V_133 . V_135
+ V_18 -> V_133 . V_136 ;
if ( V_6 -> V_52 == V_57 ) {
F_93 ( V_15 , V_19 ) ;
V_126 += V_15 -> V_133 [ V_19 ] . V_137 ;
V_126 += V_15 -> V_133 [ V_19 ] . V_138 ;
V_126 += V_15 -> V_133 [ V_19 ] . V_139 ;
V_19 = V_19 + V_140 ;
F_93 ( V_15 , V_19 ) ;
V_125 += V_15 -> V_133 [ V_19 ] . V_137 ;
V_125 += V_15 -> V_133 [ V_19 ] . V_138 ;
V_125 += V_15 -> V_133 [ V_19 ] . V_139 ;
V_125 += V_15 -> V_133 [ V_19 ] . V_141 ;
V_125 += V_15 -> V_133 [ V_19 ] . V_142 ;
V_125 += V_15 -> V_133 [ V_19 ] . V_143 ;
}
F_94 ( V_6 ) ;
V_123 += V_6 -> V_133 . V_144 ;
V_124 += V_6 -> V_133 . V_145
+ V_6 -> V_133 . V_146
+ V_6 -> V_133 . V_147
+ V_6 -> V_133 . V_148
+ V_6 -> V_133 . V_149 ;
V_117 -> V_119 = V_119 ;
V_117 -> V_121 = V_121 ;
V_117 -> V_120 = V_120 ;
V_117 -> V_150 = 0 ;
V_117 -> V_122 = V_122 ;
V_117 -> V_123 = V_123 ;
V_117 -> V_124 = V_124 ;
V_117 -> V_125 = V_125 ;
V_117 -> V_126 = V_126 ;
V_117 -> V_151 = V_6 -> V_133 . V_152 ;
V_117 -> V_153 = V_6 -> V_133 . V_154 ;
V_117 -> V_155 = V_6 -> V_133 . V_144 ;
V_117 -> V_156 = V_6 -> V_133 . V_157 ;
V_117 -> V_158 = V_6 -> V_133 . V_159 ;
}
void F_95 ( struct V_2 * V_3 , T_3 * V_160 )
{
int V_118 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
T_3 * V_58 = V_160 ;
struct V_4 * V_5 ;
if ( ! V_3 || ! V_160 ) {
F_96 ( L_6 ) ;
return;
}
V_5 = F_2 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_18 = F_5 ( V_3 ) ;
for ( V_118 = 0 ; V_118 < V_3 -> V_26 ; V_118 ++ ) {
F_97 ( V_3 -> V_45 [ V_118 ] , V_58 ) ;
V_58 += F_98 ( ( int ) V_161 ) ;
}
F_99 ( V_18 , V_58 ) ;
V_58 += F_100 ( ( int ) V_161 ) ;
F_101 ( V_6 , V_58 ) ;
V_58 += F_102 ( V_6 , ( int ) V_161 ) ;
if ( V_6 -> V_52 == V_57 )
F_103 ( V_5 -> V_15 , V_58 , V_5 -> V_17 ) ;
}
void F_104 ( struct V_2 * V_3 ,
T_1 V_162 , V_60 * V_160 )
{
int V_19 ;
int V_118 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
struct V_7 * V_15 = F_3 ( V_3 -> V_9 ) ;
V_60 * V_58 = V_160 ;
struct V_4 * V_5 ;
assert ( V_3 ) ;
V_5 = F_2 ( V_3 ) ;
V_19 = V_5 -> V_17 ;
V_6 = F_1 ( V_3 ) ;
V_18 = F_5 ( V_3 ) ;
for ( V_118 = 0 ; V_118 < V_3 -> V_26 ; V_118 ++ ) {
F_105 ( V_162 , V_58 , V_118 ) ;
V_58 += V_163 * F_98 ( V_162 ) ;
}
F_106 ( V_18 , V_162 , V_58 ) ;
V_58 += V_163 * F_100 ( V_162 ) ;
F_107 ( V_6 , V_162 , V_58 ) ;
V_58 += V_163 * F_102 ( V_6 , V_162 ) ;
if ( V_6 -> V_52 == V_57 )
F_108 ( V_162 , V_58 , V_19 , V_15 ) ;
}
int F_109 ( struct V_2 * V_3 , int V_162 )
{
T_1 V_164 = 0 ;
struct V_1 * V_6 ;
struct V_7 * V_15 = F_3 ( V_3 -> V_9 ) ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_164 += F_98 ( V_162 ) * V_3 -> V_26 ;
V_164 += F_100 ( V_162 ) ;
V_164 += F_102 ( V_6 , V_162 ) ;
if ( V_6 -> V_52 == V_57 )
V_164 += F_110 ( V_15 , V_162 ) ;
return V_164 ;
}
static int F_111 ( struct V_2 * V_3 ,
enum V_165 V_166 , int V_90 )
{
int V_59 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_15 = V_6 -> V_15 ;
switch ( V_166 ) {
case V_167 :
V_59 = 0 ;
break;
case V_168 :
V_59 = V_15 -> V_169 -> V_170 ( V_5 -> V_6 ,
! ! V_90 ) ;
break;
case V_171 :
V_59 = F_112 ( V_5 -> V_6 , V_166 , V_90 ) ;
break;
default:
V_59 = - V_43 ;
}
return V_59 ;
}
void F_113 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_53 != V_172 )
return;
F_114 ( V_6 ) ;
}
int F_115 ( struct V_2 * V_3 ,
enum V_173 V_174 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
return F_116 ( V_6 , V_174 ) ;
}
void F_117 ( struct V_2 * V_3 , void * V_160 )
{
T_1 * V_58 = V_160 ;
int V_33 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_11 * V_18 = F_5 ( V_3 ) ;
F_118 ( V_18 , V_58 ) ;
V_58 += F_119 () ;
F_120 ( V_5 -> V_15 -> V_20 [ 0 ] , V_58 ) ;
V_58 += F_121 () ;
for ( V_33 = 0 ; V_33 < V_3 -> V_26 ; V_33 ++ ) {
F_122 ( V_3 -> V_45 [ V_33 ] , V_58 ) ;
V_58 += F_123 () ;
}
F_124 ( V_5 -> V_6 , V_58 ) ;
V_58 += F_125 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_52 == V_57 )
F_126 ( V_5 -> V_15 , V_5 -> V_17 , V_58 ) ;
}
int F_127 ( struct V_2 * V_3 )
{
T_1 V_175 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_175 = F_119 () ;
V_175 += F_121 () ;
V_175 += F_123 () * V_3 -> V_26 ;
V_175 += F_125 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_52 == V_57 )
V_175 += F_128 () ;
return V_175 ;
}
static T_1 F_129 ( struct V_2 * V_3 )
{
return V_176 ;
}
static T_1 F_130 ( struct V_2 * V_3 )
{
return V_177 ;
}
static int F_131 ( struct V_2 * V_3 , T_1 * V_178 , V_60 * V_179 ,
V_60 * V_180 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
if ( V_180 )
* V_180 = V_181 ;
if ( V_179 )
memcpy ( V_179 , V_18 -> V_182 , V_176 ) ;
if ( V_178 )
memcpy ( V_178 , V_18 -> V_183 ,
V_177 * sizeof( * V_178 ) ) ;
return 0 ;
}
static int F_132 ( struct V_2 * V_3 , const T_1 * V_178 ,
const V_60 * V_179 , const V_60 V_180 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
if ( V_179 ) {
memcpy ( V_18 -> V_182 , V_179 , V_176 ) ;
F_133 ( V_18 , V_18 -> V_182 ) ;
}
if ( V_178 ) {
memcpy ( V_18 -> V_183 , V_178 ,
V_177 * sizeof( * V_178 ) ) ;
F_134 ( V_18 , V_18 -> V_183 ) ;
}
return 0 ;
}
int F_135 ( struct V_7 * V_15 )
{
struct V_8 * V_10 = & V_15 -> V_10 ;
static T_4 V_184 = F_136 ( - 1 ) ;
switch ( V_15 -> V_70 ) {
case V_185 :
V_186 . V_187 = F_54 ;
break;
case V_188 :
V_186 . V_187 = F_57 ;
break;
default:
break;
}
snprintf ( V_10 -> V_189 , V_190 , L_7 , V_191 ,
( int ) F_137 ( & V_184 ) ) ;
V_10 -> V_192 = & V_186 ;
V_10 -> V_9 = V_15 -> V_9 ;
return F_138 ( V_10 , V_193 ) ;
}
void F_139 ( struct V_7 * V_15 )
{
F_140 ( & V_15 -> V_10 ) ;
}
