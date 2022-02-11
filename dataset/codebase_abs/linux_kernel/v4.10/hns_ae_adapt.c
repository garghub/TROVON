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
return F_36 ( V_6 , V_66 ) ;
}
static void F_37 ( struct V_2 * V_3 , int V_67 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
F_38 ( V_18 , V_67 ) ;
}
static int F_39 ( struct V_2 * V_3 )
{
int V_57 ;
int V_68 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_57 = F_40 ( V_6 , 0 , true ) ;
if ( V_57 )
return V_57 ;
for ( V_68 = 0 ; V_68 < V_3 -> V_26 ; V_68 ++ ) {
if ( F_41 ( V_6 -> V_15 -> V_69 ) )
F_42 ( V_3 -> V_43 [ V_68 ] ,
V_70 | V_71 ) ;
else
F_43 ( V_3 -> V_43 [ V_68 ] ,
V_70 | V_71 ) ;
}
F_17 ( V_3 , 1 ) ;
F_44 ( 100 ) ;
F_45 ( V_6 ) ;
return 0 ;
}
void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_47 ( V_3 -> V_43 , V_3 -> V_26 , V_70 ) ;
F_44 ( 20 ) ;
F_48 ( V_6 ) ;
F_49 ( 10000 , 20000 ) ;
F_17 ( V_3 , 0 ) ;
( void ) F_40 ( V_6 , 0 , false ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_6 -> V_50 == V_72 ) {
F_51 ( V_5 -> V_6 ) ;
F_52 ( V_5 -> V_15 , 0 ) ;
}
}
void F_53 ( struct V_73 * V_54 , T_1 V_74 )
{
T_1 V_75 ;
if ( F_54 ( V_54 ) )
V_75 = V_70 ;
else
V_75 = V_71 ;
F_55 ( V_54 -> V_29 , V_75 , V_74 ) ;
}
static void F_56 ( struct V_73 * V_54 , T_1 V_74 )
{
T_1 V_75 ;
if ( F_54 ( V_54 ) )
V_75 = V_70 ;
else
V_75 = V_71 ;
F_57 ( V_54 -> V_29 , V_75 , V_74 ) ;
}
static int F_58 ( struct V_2 * V_3 )
{
T_1 V_76 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_59 ( V_6 , & V_76 ) ;
return ! ! V_76 ;
}
static int F_60 ( struct V_2 * V_3 ,
V_58 * V_77 , T_2 * V_78 , V_58 * V_79 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_61 ( V_6 , V_77 , V_78 , V_79 ) ;
}
static void F_62 ( struct V_2 * V_3 , int V_78 ,
int V_79 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_63 ( V_6 , V_78 , V_79 ) ;
}
static void F_64 ( struct V_28 * V_80 ,
T_1 * V_81 )
{
* V_81 = V_82 ;
}
static void F_65 ( struct V_2 * V_3 ,
T_1 * V_77 , T_1 * V_83 , T_1 * V_84 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_15 = V_6 -> V_15 ;
F_66 ( V_6 , V_77 ) ;
F_67 ( V_6 , V_83 , V_84 ) ;
if ( V_3 -> V_49 == V_55 )
F_68 ( V_15 , V_6 -> V_64 , V_83 ) ;
}
static int F_69 ( struct V_2 * V_3 , V_58 V_67 )
{
assert ( V_3 ) ;
return F_70 ( F_1 ( V_3 ) , V_67 ) ;
}
static void F_71 ( struct V_2 * V_3 , T_1 V_85 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_72 ( F_3 ( V_3 -> V_9 ) , V_85 ) ;
F_73 ( V_6 , ( V_58 ) ! ! V_85 ) ;
}
static int F_74 ( struct V_2 * V_3 )
{
T_1 V_77 ;
assert ( V_3 ) ;
F_66 ( F_1 ( V_3 ) , & V_77 ) ;
return V_77 ;
}
static int F_75 ( struct V_2 * V_3 ,
T_1 V_86 , T_1 V_83 , T_1 V_84 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_15 = V_6 -> V_15 ;
int V_57 ;
V_57 = F_70 ( V_6 , V_86 ) ;
if ( V_57 )
return V_57 ;
if ( V_3 -> V_49 == V_55 ) {
V_57 = F_76 ( V_15 ,
V_6 -> V_64 , V_83 ) ;
if ( V_57 )
return V_57 ;
V_83 = 0 ;
}
return F_77 ( V_6 , V_83 , V_84 ) ;
}
static void F_78 ( struct V_2 * V_3 ,
T_1 * V_87 , T_1 * V_88 )
{
struct V_23 * V_89 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
* V_87 = F_79 ( V_89 -> V_20 ,
V_89 -> V_90 ) ;
* V_88 = F_79 ( V_89 -> V_20 ,
V_89 -> V_90 ) ;
}
static void F_80 ( struct V_2 * V_3 ,
T_1 * V_91 , T_1 * V_92 )
{
struct V_23 * V_89 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
* V_91 = F_81 ( V_89 -> V_20 ,
V_89 -> V_90 ) ;
* V_92 = F_81 ( V_89 -> V_20 ,
V_89 -> V_90 ) ;
}
static int F_82 ( struct V_2 * V_3 ,
T_1 V_93 )
{
struct V_23 * V_89 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
return F_83 (
V_89 -> V_20 , V_89 -> V_90 , V_93 ) ;
}
static int F_84 ( struct V_2 * V_3 ,
T_1 V_94 )
{
struct V_23 * V_89 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
return F_85 (
V_89 -> V_20 ,
V_89 -> V_90 , V_94 ) ;
}
static void F_86 ( struct V_2 * V_3 ,
T_1 * V_95 , T_1 * V_96 ,
T_1 * V_97 , T_1 * V_98 ,
T_1 * V_99 , T_1 * V_100 ,
T_1 * V_101 , T_1 * V_102 )
{
struct V_7 * V_15 ;
V_15 = F_3 ( V_3 -> V_9 ) ;
* V_95 = V_103 ;
* V_96 = V_103 ;
* V_97 =
( V_15 -> V_104 - 1 > V_105 ) ?
V_105 : V_15 -> V_104 - 1 ;
* V_98 =
( V_15 -> V_104 - 1 > V_105 ) ?
V_105 : V_15 -> V_104 - 1 ;
* V_99 = 0 ;
* V_100 = 0 ;
* V_101 = V_106 ;
* V_102 = V_106 ;
}
void F_87 ( struct V_2 * V_3 ,
struct V_107 * V_108 )
{
int V_19 ;
int V_109 ;
struct V_7 * V_15 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
struct V_28 * V_80 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_3 V_110 = 0 , V_111 = 0 , V_112 = 0 , V_113 = 0 ;
T_3 V_114 = 0 , V_115 = 0 , V_116 = 0 ;
T_3 V_117 = 0 ;
V_15 = F_3 ( V_3 -> V_9 ) ;
if ( ! V_15 )
return;
V_19 = V_5 -> V_17 ;
V_18 = F_5 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
for ( V_109 = 0 ; V_109 < V_3 -> V_26 ; V_109 ++ ) {
V_80 = V_3 -> V_43 [ V_109 ] ;
F_88 ( V_80 ) ;
V_110 += V_80 -> V_45 . V_118 . V_110 ;
V_112 += V_80 -> V_45 . V_118 . V_119 ;
V_111 += V_80 -> V_44 . V_118 . V_111 ;
V_113 += V_80 -> V_44 . V_118 . V_120 ;
V_114 += V_80 -> V_44 . V_118 . V_121
+ V_80 -> V_44 . V_118 . V_122
+ V_80 -> V_44 . V_118 . V_123 ;
}
F_89 ( V_18 ) ;
V_117 = V_18 -> V_124 . V_125 ;
V_115 += V_18 -> V_124 . V_126
+ V_18 -> V_124 . V_127 ;
if ( V_6 -> V_50 == V_55 ) {
F_90 ( V_15 , V_19 ) ;
V_117 += V_15 -> V_124 [ V_19 ] . V_128 ;
V_117 += V_15 -> V_124 [ V_19 ] . V_129 ;
V_117 += V_15 -> V_124 [ V_19 ] . V_130 ;
V_19 = V_19 + V_131 ;
F_90 ( V_15 , V_19 ) ;
V_116 += V_15 -> V_124 [ V_19 ] . V_128 ;
V_116 += V_15 -> V_124 [ V_19 ] . V_129 ;
V_116 += V_15 -> V_124 [ V_19 ] . V_130 ;
V_116 += V_15 -> V_124 [ V_19 ] . V_132 ;
V_116 += V_15 -> V_124 [ V_19 ] . V_133 ;
V_116 += V_15 -> V_124 [ V_19 ] . V_134 ;
}
F_91 ( V_6 ) ;
V_114 += V_6 -> V_124 . V_135 ;
V_115 += V_6 -> V_124 . V_136
+ V_6 -> V_124 . V_137
+ V_6 -> V_124 . V_138
+ V_6 -> V_124 . V_139
+ V_6 -> V_124 . V_140 ;
V_108 -> V_110 = V_110 ;
V_108 -> V_112 = V_112 ;
V_108 -> V_111 = V_111 ;
V_108 -> V_141 = 0 ;
V_108 -> V_113 = V_113 ;
V_108 -> V_114 = V_114 ;
V_108 -> V_115 = V_115 ;
V_108 -> V_116 = V_116 ;
V_108 -> V_117 = V_117 ;
V_108 -> V_142 = V_6 -> V_124 . V_143 ;
V_108 -> V_144 = V_6 -> V_124 . V_145 ;
V_108 -> V_146 = V_6 -> V_124 . V_135 ;
V_108 -> V_147 = V_6 -> V_124 . V_148 ;
V_108 -> V_149 = V_6 -> V_124 . V_150 ;
}
void F_92 ( struct V_2 * V_3 , T_3 * V_151 )
{
int V_109 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
T_3 * V_56 = V_151 ;
struct V_4 * V_5 ;
if ( ! V_3 || ! V_151 ) {
F_93 ( L_6 ) ;
return;
}
V_5 = F_2 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_18 = F_5 ( V_3 ) ;
for ( V_109 = 0 ; V_109 < V_3 -> V_26 ; V_109 ++ ) {
F_94 ( V_3 -> V_43 [ V_109 ] , V_56 ) ;
V_56 += F_95 ( ( int ) V_152 ) ;
}
F_96 ( V_18 , V_56 ) ;
V_56 += F_97 ( ( int ) V_152 ) ;
F_98 ( V_6 , V_56 ) ;
V_56 += F_99 ( V_6 , ( int ) V_152 ) ;
if ( V_6 -> V_50 == V_55 )
F_100 ( V_5 -> V_15 , V_56 , V_5 -> V_17 ) ;
}
void F_101 ( struct V_2 * V_3 ,
T_1 V_153 , V_58 * V_151 )
{
int V_19 ;
int V_109 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
struct V_7 * V_15 = F_3 ( V_3 -> V_9 ) ;
V_58 * V_56 = V_151 ;
struct V_4 * V_5 ;
assert ( V_3 ) ;
V_5 = F_2 ( V_3 ) ;
V_19 = V_5 -> V_17 ;
V_6 = F_1 ( V_3 ) ;
V_18 = F_5 ( V_3 ) ;
for ( V_109 = 0 ; V_109 < V_3 -> V_26 ; V_109 ++ ) {
F_102 ( V_153 , V_56 , V_109 ) ;
V_56 += V_154 * F_95 ( V_153 ) ;
}
F_103 ( V_18 , V_153 , V_56 ) ;
V_56 += V_154 * F_97 ( V_153 ) ;
F_104 ( V_6 , V_153 , V_56 ) ;
V_56 += V_154 * F_99 ( V_6 , V_153 ) ;
if ( V_6 -> V_50 == V_55 )
F_105 ( V_153 , V_56 , V_19 , V_15 ) ;
}
int F_106 ( struct V_2 * V_3 , int V_153 )
{
T_1 V_155 = 0 ;
struct V_1 * V_6 ;
struct V_7 * V_15 = F_3 ( V_3 -> V_9 ) ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_155 += F_95 ( V_153 ) * V_3 -> V_26 ;
V_155 += F_97 ( V_153 ) ;
V_155 += F_99 ( V_6 , V_153 ) ;
if ( V_6 -> V_50 == V_55 )
V_155 += F_107 ( V_15 , V_153 ) ;
return V_155 ;
}
static int F_108 ( struct V_2 * V_3 ,
enum V_156 V_157 , int V_85 )
{
int V_57 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_15 = V_6 -> V_15 ;
switch ( V_157 ) {
case V_158 :
V_57 = 0 ;
break;
case V_159 :
V_57 = V_15 -> V_160 -> V_161 ( V_5 -> V_6 ,
! ! V_85 ) ;
break;
case V_162 :
V_57 = F_109 ( V_5 -> V_6 , V_157 , V_85 ) ;
break;
default:
V_57 = - V_41 ;
}
return V_57 ;
}
void F_110 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 -> V_163 )
return;
F_111 ( V_6 ) ;
}
int F_112 ( struct V_2 * V_3 ,
enum V_164 V_165 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
return F_113 ( V_6 , V_165 ) ;
}
void F_114 ( struct V_2 * V_3 , void * V_151 )
{
T_1 * V_56 = V_151 ;
int V_33 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_11 * V_18 = F_5 ( V_3 ) ;
F_115 ( V_18 , V_56 ) ;
V_56 += F_116 () ;
F_117 ( V_5 -> V_15 -> V_20 [ 0 ] , V_56 ) ;
V_56 += F_118 () ;
for ( V_33 = 0 ; V_33 < V_3 -> V_26 ; V_33 ++ ) {
F_119 ( V_3 -> V_43 [ V_33 ] , V_56 ) ;
V_56 += F_120 () ;
}
F_121 ( V_5 -> V_6 , V_56 ) ;
V_56 += F_122 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_50 == V_55 )
F_123 ( V_5 -> V_15 , V_5 -> V_17 , V_56 ) ;
}
int F_124 ( struct V_2 * V_3 )
{
T_1 V_166 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_166 = F_116 () ;
V_166 += F_118 () ;
V_166 += F_120 () * V_3 -> V_26 ;
V_166 += F_122 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_50 == V_55 )
V_166 += F_125 () ;
return V_166 ;
}
static T_1 F_126 ( struct V_2 * V_3 )
{
return V_167 ;
}
static T_1 F_127 ( struct V_2 * V_3 )
{
return V_168 ;
}
static int F_128 ( struct V_2 * V_3 , T_1 * V_169 , V_58 * V_170 ,
V_58 * V_171 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
if ( V_171 )
* V_171 = V_172 ;
if ( V_170 )
memcpy ( V_170 , V_18 -> V_173 , V_167 ) ;
memcpy ( V_169 , V_18 -> V_174 ,
V_168 * sizeof( * V_169 ) ) ;
return 0 ;
}
static int F_129 ( struct V_2 * V_3 , const T_1 * V_169 ,
const V_58 * V_170 , const V_58 V_171 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
if ( V_170 )
F_130 ( V_18 , ( T_1 * ) V_170 ) ;
memcpy ( V_18 -> V_174 , V_169 ,
V_168 * sizeof( * V_169 ) ) ;
F_131 ( V_18 , V_18 -> V_174 ) ;
return 0 ;
}
int F_132 ( struct V_7 * V_15 )
{
struct V_8 * V_10 = & V_15 -> V_10 ;
static T_4 V_175 = F_133 ( - 1 ) ;
switch ( V_15 -> V_69 ) {
case V_176 :
V_177 . V_178 = F_53 ;
break;
case V_179 :
V_177 . V_178 = F_56 ;
break;
default:
break;
}
snprintf ( V_10 -> V_180 , V_181 , L_7 , V_182 ,
( int ) F_134 ( & V_175 ) ) ;
V_10 -> V_183 = & V_177 ;
V_10 -> V_9 = V_15 -> V_9 ;
return F_135 ( V_10 , V_184 ) ;
}
void F_136 ( struct V_7 * V_15 )
{
F_137 ( & V_15 -> V_10 ) ;
}
