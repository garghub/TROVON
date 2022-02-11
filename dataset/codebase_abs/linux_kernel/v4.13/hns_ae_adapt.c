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
for ( V_34 -> V_39 = 0 ;
V_34 -> V_39 < V_31 ; V_34 -> V_39 ++ ) {
if ( ! V_23 -> V_40 )
break;
V_23 += V_32 ;
}
if ( V_34 -> V_39 >= V_31 ) {
F_13 ( V_15 -> V_9 , L_2 ) ;
V_34 = F_14 ( - V_41 ) ;
goto V_42;
}
V_34 -> V_43 = (struct V_28 * * ) ( & V_34 -> V_43 + 1 ) ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
V_34 -> V_43 [ V_33 ] = & V_23 -> V_29 ;
V_34 -> V_43 [ V_33 ] -> V_44 . V_29 = V_34 -> V_43 [ V_33 ] ;
V_34 -> V_43 [ V_33 ] -> V_45 . V_29 = V_34 -> V_43 [ V_33 ] ;
V_23 -> V_40 = 1 ;
V_23 ++ ;
}
V_5 -> V_15 = V_15 ;
V_5 -> V_17 = V_30 ;
V_5 -> V_6 = V_15 -> V_6 [ V_30 ] ;
V_34 -> V_46 = V_5 -> V_6 -> V_46 ;
V_34 -> V_47 = V_5 -> V_6 -> V_47 ;
V_34 -> V_48 = V_5 -> V_6 -> V_48 ;
V_34 -> V_49 = V_5 -> V_6 -> V_50 ;
V_34 -> V_51 = V_5 -> V_6 -> V_51 ;
V_34 -> V_52 = V_30 ;
return V_34 ;
V_42:
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
F_9 ( V_3 -> V_43 [ V_33 ] ) -> V_40 = 0 ;
}
static void F_17 ( struct V_2 * V_3 , int V_53 )
{
int V_26 = V_3 -> V_26 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_26 ; V_33 ++ )
F_18 ( V_3 -> V_43 [ V_33 ] , V_53 ) ;
}
static void F_19 ( struct V_28 * V_29 )
{
struct V_23 * V_54 =
F_4 ( V_29 , struct V_23 , V_29 ) ;
F_20 ( V_54 ) ;
}
static void F_21 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 -> V_3 ) ;
if ( V_5 -> V_6 -> V_50 == V_55 )
F_22 ( V_29 ) ;
}
static int F_23 ( struct V_2 * V_3 , void * V_56 )
{
int V_57 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( ! V_56 || ! F_24 ( ( const V_58 * ) V_56 ) ) {
F_13 ( V_3 -> V_38 , L_3 ) ;
return - V_59 ;
}
V_57 = F_25 ( V_6 , V_3 -> V_39 , V_56 ) ;
if ( V_57 != 0 ) {
F_13 ( V_3 -> V_38 ,
L_4 , V_57 ) ;
return V_57 ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
const unsigned char * V_60 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_50 != V_55 )
return - V_61 ;
return F_27 ( V_6 , V_3 -> V_39 , V_60 ) ;
}
static int F_28 ( struct V_2 * V_3 ,
const unsigned char * V_60 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_50 != V_55 )
return - V_61 ;
return F_29 ( V_6 , V_3 -> V_39 , V_60 ) ;
}
static int F_30 ( struct V_2 * V_3 , void * V_60 )
{
int V_57 ;
char * V_62 = ( char * ) V_60 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_58 V_63 ;
assert ( V_6 ) ;
if ( V_6 -> V_50 != V_55 )
return 0 ;
V_57 = F_31 ( V_6 , V_6 -> V_64 , V_62 , true ) ;
if ( V_57 ) {
F_13 ( V_3 -> V_38 ,
L_5 ,
V_62 , V_6 -> V_64 , V_57 ) ;
return V_57 ;
}
V_57 = F_32 ( V_6 , V_3 -> V_39 , & V_63 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_31 ( V_6 , V_63 , V_62 , true ) ;
if ( V_57 )
F_13 ( V_3 -> V_38 ,
L_5 ,
V_62 , V_65 , V_57 ) ;
return V_57 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_50 != V_55 )
return 0 ;
return F_34 ( V_6 , V_3 -> V_39 ) ;
}
static int F_35 ( struct V_2 * V_3 , int V_66 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_28 * V_29 ;
T_1 V_67 ;
int V_33 , V_57 ;
if ( ! F_36 ( V_6 -> V_15 -> V_68 ) ) {
if ( V_66 <= V_69 )
V_67 = 2048 ;
else
V_67 = 4096 ;
} else {
V_67 = V_6 -> V_15 -> V_70 ;
}
V_57 = F_37 ( V_6 , V_66 , V_67 ) ;
if ( ! V_57 ) {
for ( V_33 = 0 ; V_33 < V_3 -> V_26 ; V_33 ++ ) {
V_29 = V_3 -> V_43 [ V_33 ] ;
V_29 -> V_44 . V_70 = V_67 ;
F_38 ( V_29 , V_67 ) ;
}
}
return V_57 ;
}
static void F_39 ( struct V_2 * V_3 , int V_71 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
F_40 ( V_18 , V_71 ) ;
}
static int F_41 ( struct V_2 * V_3 )
{
int V_57 ;
int V_72 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_57 = F_42 ( V_6 , 0 , true ) ;
if ( V_57 )
return V_57 ;
for ( V_72 = 0 ; V_72 < V_3 -> V_26 ; V_72 ++ ) {
if ( F_36 ( V_6 -> V_15 -> V_68 ) )
F_43 ( V_3 -> V_43 [ V_72 ] ,
V_73 | V_74 ) ;
else
F_44 ( V_3 -> V_43 [ V_72 ] ,
V_73 | V_74 ) ;
}
F_17 ( V_3 , 1 ) ;
F_45 ( 100 ) ;
F_46 ( V_6 ) ;
return 0 ;
}
void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_48 ( V_3 -> V_43 , V_3 -> V_26 , V_73 ) ;
F_45 ( 20 ) ;
F_49 ( V_6 ) ;
F_50 ( 10000 , 20000 ) ;
F_17 ( V_3 , 0 ) ;
( void ) F_42 ( V_6 , 0 , false ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_6 -> V_50 == V_75 ) {
F_52 ( V_5 -> V_6 ) ;
F_53 ( V_5 -> V_15 , 0 ) ;
}
}
void F_54 ( struct V_76 * V_54 , T_1 V_77 )
{
T_1 V_78 ;
if ( F_55 ( V_54 ) )
V_78 = V_73 ;
else
V_78 = V_74 ;
F_56 ( V_54 -> V_29 , V_78 , V_77 ) ;
}
static void F_57 ( struct V_76 * V_54 , T_1 V_77 )
{
T_1 V_78 ;
if ( F_55 ( V_54 ) )
V_78 = V_73 ;
else
V_78 = V_74 ;
F_58 ( V_54 -> V_29 , V_78 , V_77 ) ;
}
static int F_59 ( struct V_2 * V_3 )
{
T_1 V_79 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_60 ( V_6 , & V_79 ) ;
return ! ! V_79 ;
}
static int F_61 ( struct V_2 * V_3 ,
V_58 * V_80 , T_2 * V_81 , V_58 * V_82 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_62 ( V_6 , V_80 , V_81 , V_82 ) ;
}
static void F_63 ( struct V_2 * V_3 , int V_81 ,
int V_82 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_64 ( V_6 , V_81 , V_82 ) ;
}
static void F_65 ( struct V_28 * V_83 ,
T_1 * V_84 )
{
* V_84 = V_85 ;
}
static void F_66 ( struct V_2 * V_3 ,
T_1 * V_80 , T_1 * V_86 , T_1 * V_87 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_15 = V_6 -> V_15 ;
F_67 ( V_6 , V_80 ) ;
F_68 ( V_6 , V_86 , V_87 ) ;
if ( V_3 -> V_49 == V_55 )
F_69 ( V_15 , V_6 -> V_64 , V_86 ) ;
}
static int F_70 ( struct V_2 * V_3 , V_58 V_71 )
{
assert ( V_3 ) ;
return F_71 ( F_1 ( V_3 ) , V_71 ) ;
}
static void F_72 ( struct V_2 * V_3 , T_1 V_88 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_73 ( F_3 ( V_3 -> V_9 ) , V_88 ) ;
F_74 ( V_6 , ( V_58 ) ! ! V_88 ) ;
}
static int F_75 ( struct V_2 * V_3 )
{
T_1 V_80 ;
assert ( V_3 ) ;
F_67 ( F_1 ( V_3 ) , & V_80 ) ;
return V_80 ;
}
static int F_76 ( struct V_2 * V_3 ,
T_1 V_89 , T_1 V_86 , T_1 V_87 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_15 = V_6 -> V_15 ;
int V_57 ;
V_57 = F_71 ( V_6 , V_89 ) ;
if ( V_57 )
return V_57 ;
if ( V_3 -> V_49 == V_55 ) {
V_57 = F_77 ( V_15 ,
V_6 -> V_64 , V_86 ) ;
if ( V_57 )
return V_57 ;
V_86 = 0 ;
}
return F_78 ( V_6 , V_86 , V_87 ) ;
}
static void F_79 ( struct V_2 * V_3 ,
T_1 * V_90 , T_1 * V_91 )
{
struct V_23 * V_92 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
* V_90 = F_80 ( V_92 -> V_20 ,
V_92 -> V_93 ) ;
* V_91 = F_80 ( V_92 -> V_20 ,
V_92 -> V_93 ) ;
}
static void F_81 ( struct V_2 * V_3 ,
T_1 * V_94 , T_1 * V_95 )
{
struct V_23 * V_92 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
struct V_7 * V_15 = F_3 ( V_3 -> V_9 ) ;
if ( F_36 ( V_15 -> V_68 ) ||
V_3 -> V_49 == V_75 )
* V_94 = F_82 (
V_92 -> V_20 , V_92 -> V_93 ) ;
else
* V_94 = F_83 (
V_92 -> V_20 , V_92 -> V_93 ) ;
* V_95 = F_82 ( V_92 -> V_20 ,
V_92 -> V_93 ) ;
}
static int F_84 ( struct V_2 * V_3 ,
T_1 V_96 )
{
struct V_23 * V_92 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
return F_85 (
V_92 -> V_20 , V_92 -> V_93 , V_96 ) ;
}
static int F_86 ( struct V_2 * V_3 ,
T_1 V_94 , T_1 V_95 )
{
int V_57 ;
struct V_23 * V_92 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
struct V_7 * V_15 = F_3 ( V_3 -> V_9 ) ;
if ( F_36 ( V_15 -> V_68 ) ||
V_3 -> V_49 == V_75 ) {
if ( V_94 != V_95 )
return - V_41 ;
return F_87 (
V_92 -> V_20 ,
V_92 -> V_93 , V_95 ) ;
} else {
if ( V_94 != 1 )
return - V_41 ;
V_57 = F_88 (
V_92 -> V_20 ,
V_92 -> V_93 , V_94 ) ;
if ( V_57 )
return V_57 ;
return F_87 (
V_92 -> V_20 ,
V_92 -> V_93 , V_95 ) ;
}
}
static void F_89 ( struct V_2 * V_3 ,
T_1 * V_97 , T_1 * V_98 ,
T_1 * V_99 , T_1 * V_100 ,
T_1 * V_101 , T_1 * V_102 ,
T_1 * V_103 , T_1 * V_104 )
{
struct V_7 * V_15 ;
assert ( V_3 ) ;
V_15 = F_3 ( V_3 -> V_9 ) ;
* V_97 = V_105 ;
* V_98 = V_106 ;
if ( F_36 ( V_15 -> V_68 ) ||
V_3 -> V_49 == V_75 )
* V_99 =
( V_15 -> V_107 - 1 > V_108 ) ?
V_108 : V_15 -> V_107 - 1 ;
else
* V_99 = 1 ;
* V_100 = ( V_15 -> V_107 - 1 > V_109 ) ?
V_109 : V_15 -> V_107 - 1 ;
* V_101 = V_110 ;
* V_102 = V_111 ;
* V_103 = V_112 ;
* V_104 = V_113 ;
}
void F_90 ( struct V_2 * V_3 ,
struct V_114 * V_115 )
{
int V_19 ;
int V_116 ;
struct V_7 * V_15 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
struct V_28 * V_83 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_3 V_117 = 0 , V_118 = 0 , V_119 = 0 , V_120 = 0 ;
T_3 V_121 = 0 , V_122 = 0 , V_123 = 0 ;
T_3 V_124 = 0 ;
V_15 = F_3 ( V_3 -> V_9 ) ;
if ( ! V_15 )
return;
V_19 = V_5 -> V_17 ;
V_18 = F_5 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
for ( V_116 = 0 ; V_116 < V_3 -> V_26 ; V_116 ++ ) {
V_83 = V_3 -> V_43 [ V_116 ] ;
F_91 ( V_83 ) ;
V_117 += V_83 -> V_45 . V_125 . V_117 ;
V_119 += V_83 -> V_45 . V_125 . V_126 ;
V_118 += V_83 -> V_44 . V_125 . V_118 ;
V_120 += V_83 -> V_44 . V_125 . V_127 ;
V_121 += V_83 -> V_44 . V_125 . V_128
+ V_83 -> V_44 . V_125 . V_129
+ V_83 -> V_44 . V_125 . V_130 ;
}
F_92 ( V_18 ) ;
V_124 = V_18 -> V_131 . V_132 ;
V_122 += V_18 -> V_131 . V_133
+ V_18 -> V_131 . V_134 ;
if ( V_6 -> V_50 == V_55 ) {
F_93 ( V_15 , V_19 ) ;
V_124 += V_15 -> V_131 [ V_19 ] . V_135 ;
V_124 += V_15 -> V_131 [ V_19 ] . V_136 ;
V_124 += V_15 -> V_131 [ V_19 ] . V_137 ;
V_19 = V_19 + V_138 ;
F_93 ( V_15 , V_19 ) ;
V_123 += V_15 -> V_131 [ V_19 ] . V_135 ;
V_123 += V_15 -> V_131 [ V_19 ] . V_136 ;
V_123 += V_15 -> V_131 [ V_19 ] . V_137 ;
V_123 += V_15 -> V_131 [ V_19 ] . V_139 ;
V_123 += V_15 -> V_131 [ V_19 ] . V_140 ;
V_123 += V_15 -> V_131 [ V_19 ] . V_141 ;
}
F_94 ( V_6 ) ;
V_121 += V_6 -> V_131 . V_142 ;
V_122 += V_6 -> V_131 . V_143
+ V_6 -> V_131 . V_144
+ V_6 -> V_131 . V_145
+ V_6 -> V_131 . V_146
+ V_6 -> V_131 . V_147 ;
V_115 -> V_117 = V_117 ;
V_115 -> V_119 = V_119 ;
V_115 -> V_118 = V_118 ;
V_115 -> V_148 = 0 ;
V_115 -> V_120 = V_120 ;
V_115 -> V_121 = V_121 ;
V_115 -> V_122 = V_122 ;
V_115 -> V_123 = V_123 ;
V_115 -> V_124 = V_124 ;
V_115 -> V_149 = V_6 -> V_131 . V_150 ;
V_115 -> V_151 = V_6 -> V_131 . V_152 ;
V_115 -> V_153 = V_6 -> V_131 . V_142 ;
V_115 -> V_154 = V_6 -> V_131 . V_155 ;
V_115 -> V_156 = V_6 -> V_131 . V_157 ;
}
void F_95 ( struct V_2 * V_3 , T_3 * V_158 )
{
int V_116 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
T_3 * V_56 = V_158 ;
struct V_4 * V_5 ;
if ( ! V_3 || ! V_158 ) {
F_96 ( L_6 ) ;
return;
}
V_5 = F_2 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_18 = F_5 ( V_3 ) ;
for ( V_116 = 0 ; V_116 < V_3 -> V_26 ; V_116 ++ ) {
F_97 ( V_3 -> V_43 [ V_116 ] , V_56 ) ;
V_56 += F_98 ( ( int ) V_159 ) ;
}
F_99 ( V_18 , V_56 ) ;
V_56 += F_100 ( ( int ) V_159 ) ;
F_101 ( V_6 , V_56 ) ;
V_56 += F_102 ( V_6 , ( int ) V_159 ) ;
if ( V_6 -> V_50 == V_55 )
F_103 ( V_5 -> V_15 , V_56 , V_5 -> V_17 ) ;
}
void F_104 ( struct V_2 * V_3 ,
T_1 V_160 , V_58 * V_158 )
{
int V_19 ;
int V_116 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
struct V_7 * V_15 = F_3 ( V_3 -> V_9 ) ;
V_58 * V_56 = V_158 ;
struct V_4 * V_5 ;
assert ( V_3 ) ;
V_5 = F_2 ( V_3 ) ;
V_19 = V_5 -> V_17 ;
V_6 = F_1 ( V_3 ) ;
V_18 = F_5 ( V_3 ) ;
for ( V_116 = 0 ; V_116 < V_3 -> V_26 ; V_116 ++ ) {
F_105 ( V_160 , V_56 , V_116 ) ;
V_56 += V_161 * F_98 ( V_160 ) ;
}
F_106 ( V_18 , V_160 , V_56 ) ;
V_56 += V_161 * F_100 ( V_160 ) ;
F_107 ( V_6 , V_160 , V_56 ) ;
V_56 += V_161 * F_102 ( V_6 , V_160 ) ;
if ( V_6 -> V_50 == V_55 )
F_108 ( V_160 , V_56 , V_19 , V_15 ) ;
}
int F_109 ( struct V_2 * V_3 , int V_160 )
{
T_1 V_162 = 0 ;
struct V_1 * V_6 ;
struct V_7 * V_15 = F_3 ( V_3 -> V_9 ) ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_162 += F_98 ( V_160 ) * V_3 -> V_26 ;
V_162 += F_100 ( V_160 ) ;
V_162 += F_102 ( V_6 , V_160 ) ;
if ( V_6 -> V_50 == V_55 )
V_162 += F_110 ( V_15 , V_160 ) ;
return V_162 ;
}
static int F_111 ( struct V_2 * V_3 ,
enum V_163 V_164 , int V_88 )
{
int V_57 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_15 = V_6 -> V_15 ;
switch ( V_164 ) {
case V_165 :
V_57 = 0 ;
break;
case V_166 :
V_57 = V_15 -> V_167 -> V_168 ( V_5 -> V_6 ,
! ! V_88 ) ;
break;
case V_169 :
V_57 = F_112 ( V_5 -> V_6 , V_164 , V_88 ) ;
break;
default:
V_57 = - V_41 ;
}
return V_57 ;
}
void F_113 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
if ( V_6 -> V_51 != V_170 )
return;
F_114 ( V_6 ) ;
}
int F_115 ( struct V_2 * V_3 ,
enum V_171 V_172 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
return F_116 ( V_6 , V_172 ) ;
}
void F_117 ( struct V_2 * V_3 , void * V_158 )
{
T_1 * V_56 = V_158 ;
int V_33 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_11 * V_18 = F_5 ( V_3 ) ;
F_118 ( V_18 , V_56 ) ;
V_56 += F_119 () ;
F_120 ( V_5 -> V_15 -> V_20 [ 0 ] , V_56 ) ;
V_56 += F_121 () ;
for ( V_33 = 0 ; V_33 < V_3 -> V_26 ; V_33 ++ ) {
F_122 ( V_3 -> V_43 [ V_33 ] , V_56 ) ;
V_56 += F_123 () ;
}
F_124 ( V_5 -> V_6 , V_56 ) ;
V_56 += F_125 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_50 == V_55 )
F_126 ( V_5 -> V_15 , V_5 -> V_17 , V_56 ) ;
}
int F_127 ( struct V_2 * V_3 )
{
T_1 V_173 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_173 = F_119 () ;
V_173 += F_121 () ;
V_173 += F_123 () * V_3 -> V_26 ;
V_173 += F_125 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_50 == V_55 )
V_173 += F_128 () ;
return V_173 ;
}
static T_1 F_129 ( struct V_2 * V_3 )
{
return V_174 ;
}
static T_1 F_130 ( struct V_2 * V_3 )
{
return V_175 ;
}
static int F_131 ( struct V_2 * V_3 , T_1 * V_176 , V_58 * V_177 ,
V_58 * V_178 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
if ( V_178 )
* V_178 = V_179 ;
if ( V_177 )
memcpy ( V_177 , V_18 -> V_180 , V_174 ) ;
if ( V_176 )
memcpy ( V_176 , V_18 -> V_181 ,
V_175 * sizeof( * V_176 ) ) ;
return 0 ;
}
static int F_132 ( struct V_2 * V_3 , const T_1 * V_176 ,
const V_58 * V_177 , const V_58 V_178 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
if ( V_177 ) {
memcpy ( V_18 -> V_180 , V_177 , V_174 ) ;
F_133 ( V_18 , V_18 -> V_180 ) ;
}
if ( V_176 ) {
memcpy ( V_18 -> V_181 , V_176 ,
V_175 * sizeof( * V_176 ) ) ;
F_134 ( V_18 , V_18 -> V_181 ) ;
}
return 0 ;
}
int F_135 ( struct V_7 * V_15 )
{
struct V_8 * V_10 = & V_15 -> V_10 ;
static T_4 V_182 = F_136 ( - 1 ) ;
switch ( V_15 -> V_68 ) {
case V_183 :
V_184 . V_185 = F_54 ;
break;
case V_186 :
V_184 . V_185 = F_57 ;
break;
default:
break;
}
snprintf ( V_10 -> V_187 , V_188 , L_7 , V_189 ,
( int ) F_137 ( & V_182 ) ) ;
V_10 -> V_190 = & V_184 ;
V_10 -> V_9 = V_15 -> V_9 ;
return F_138 ( V_10 , V_191 ) ;
}
void F_139 ( struct V_7 * V_15 )
{
F_140 ( & V_15 -> V_10 ) ;
}
