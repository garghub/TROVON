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
V_34 -> V_51 = V_30 ;
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
static void F_17 ( struct V_2 * V_3 , int V_52 )
{
int V_26 = V_3 -> V_26 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_26 ; V_33 ++ )
F_18 ( V_3 -> V_43 [ V_33 ] , V_52 ) ;
}
static void F_19 ( struct V_28 * V_29 )
{
struct V_23 * V_53 =
F_4 ( V_29 , struct V_23 , V_29 ) ;
F_20 ( V_53 ) ;
}
static void F_21 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 -> V_3 ) ;
if ( V_5 -> V_6 -> V_50 == V_54 )
F_22 ( V_29 ) ;
}
static int F_23 ( struct V_2 * V_3 , void * V_55 )
{
int V_56 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( ! V_55 || ! F_24 ( ( const V_57 * ) V_55 ) ) {
F_13 ( V_3 -> V_38 , L_3 ) ;
return - V_58 ;
}
V_56 = F_25 ( V_6 , V_3 -> V_39 , V_55 ) ;
if ( V_56 != 0 ) {
F_13 ( V_3 -> V_38 ,
L_4 , V_56 ) ;
return V_56 ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , void * V_59 )
{
int V_56 ;
char * V_60 = ( char * ) V_59 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
assert ( V_6 ) ;
if ( V_6 -> V_50 != V_54 )
return 0 ;
V_56 = F_27 ( V_6 , V_6 -> V_61 , V_60 , true ) ;
if ( V_56 ) {
F_13 ( V_3 -> V_38 ,
L_5 ,
V_60 , V_6 -> V_61 , V_56 ) ;
return V_56 ;
}
V_56 = F_27 ( V_6 , V_62 ,
V_60 , true ) ;
if ( V_56 )
F_13 ( V_3 -> V_38 ,
L_5 ,
V_60 , V_62 , V_56 ) ;
return V_56 ;
}
static int F_28 ( struct V_2 * V_3 , int V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_29 ( V_6 , V_63 ) ;
}
static void F_30 ( struct V_2 * V_3 , int V_64 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
F_31 ( V_18 , V_64 ) ;
}
static int F_32 ( struct V_2 * V_3 )
{
int V_56 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_56 = F_33 ( V_6 , 0 , true ) ;
if ( V_56 )
return V_56 ;
F_17 ( V_3 , 1 ) ;
F_34 ( 100 ) ;
F_35 ( V_6 ) ;
return 0 ;
}
void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_37 ( V_3 -> V_43 , V_3 -> V_26 , V_65 ) ;
F_34 ( 20 ) ;
F_38 ( V_6 ) ;
F_39 ( 10000 , 20000 ) ;
F_17 ( V_3 , 0 ) ;
( void ) F_33 ( V_6 , 0 , false ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_6 -> V_50 == V_66 ) {
F_41 ( V_5 -> V_6 ) ;
F_42 ( V_5 -> V_15 , 0 ) ;
}
}
void F_43 ( struct V_67 * V_53 , T_1 V_68 )
{
T_1 V_69 ;
if ( F_44 ( V_53 ) )
V_69 = V_65 ;
else
V_69 = V_70 ;
F_45 ( V_53 -> V_29 , V_69 , V_68 ) ;
}
static void F_46 ( struct V_67 * V_53 , T_1 V_68 )
{
T_1 V_69 ;
if ( F_44 ( V_53 ) )
V_69 = V_65 ;
else
V_69 = V_70 ;
F_47 ( V_53 -> V_29 , V_69 , V_68 ) ;
}
static void F_48 ( struct V_28 * V_71 , T_1 V_52 )
{
struct V_7 * V_15 = F_3 ( V_71 -> V_9 ) ;
if ( F_49 ( V_15 -> V_72 ) )
F_50 ( V_71 , V_65 | V_70 ) ;
else
F_51 ( V_71 , V_65 | V_70 ) ;
F_52 ( V_71 , V_52 ) ;
}
static int F_53 ( struct V_2 * V_3 )
{
T_1 V_73 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_54 ( V_6 , & V_73 ) ;
return ! ! V_73 ;
}
static int F_55 ( struct V_2 * V_3 ,
V_57 * V_74 , T_2 * V_75 , V_57 * V_76 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_56 ( V_6 , V_74 , V_75 , V_76 ) ;
}
static void F_57 ( struct V_2 * V_3 , int V_75 ,
int V_76 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_58 ( V_6 , V_75 , V_76 ) ;
}
static void F_59 ( struct V_28 * V_71 ,
T_1 * V_77 )
{
* V_77 = V_78 ;
}
static void F_60 ( struct V_2 * V_3 ,
T_1 * V_74 , T_1 * V_79 , T_1 * V_80 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_15 = V_6 -> V_15 ;
F_61 ( V_6 , V_74 ) ;
F_62 ( V_6 , V_79 , V_80 ) ;
if ( V_3 -> V_49 == V_54 )
F_63 ( V_15 , V_6 -> V_61 , V_79 ) ;
}
static int F_64 ( struct V_2 * V_3 , V_57 V_64 )
{
assert ( V_3 ) ;
return F_65 ( F_1 ( V_3 ) , V_64 ) ;
}
static void F_66 ( struct V_2 * V_3 , T_1 V_81 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_67 ( F_3 ( V_3 -> V_9 ) , V_81 ) ;
F_68 ( V_6 , ( V_57 ) ! ! V_81 ) ;
}
static int F_69 ( struct V_2 * V_3 )
{
T_1 V_74 ;
assert ( V_3 ) ;
F_61 ( F_1 ( V_3 ) , & V_74 ) ;
return V_74 ;
}
static int F_70 ( struct V_2 * V_3 ,
T_1 V_82 , T_1 V_79 , T_1 V_80 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_15 = V_6 -> V_15 ;
int V_56 ;
V_56 = F_65 ( V_6 , V_82 ) ;
if ( V_56 )
return V_56 ;
if ( V_3 -> V_49 == V_54 ) {
V_56 = F_71 ( V_15 ,
V_6 -> V_61 , V_79 ) ;
if ( V_56 )
return V_56 ;
V_79 = 0 ;
}
return F_72 ( V_6 , V_79 , V_80 ) ;
}
static void F_73 ( struct V_2 * V_3 ,
T_1 * V_83 , T_1 * V_84 )
{
struct V_23 * V_85 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
* V_83 = F_74 ( V_85 -> V_20 ,
V_85 -> V_86 ) ;
* V_84 = F_74 ( V_85 -> V_20 ,
V_85 -> V_86 ) ;
}
static void F_75 ( struct V_2 * V_3 ,
T_1 * V_87 , T_1 * V_88 )
{
struct V_23 * V_85 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
* V_87 = F_76 ( V_85 -> V_20 ,
V_85 -> V_86 ) ;
* V_88 = F_76 ( V_85 -> V_20 ,
V_85 -> V_86 ) ;
}
static int F_77 ( struct V_2 * V_3 ,
T_1 V_89 )
{
struct V_23 * V_85 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
return F_78 (
V_85 -> V_20 , V_85 -> V_86 , V_89 ) ;
}
static int F_79 ( struct V_2 * V_3 ,
T_1 V_90 )
{
struct V_23 * V_85 =
F_4 ( V_3 -> V_43 [ 0 ] , struct V_23 , V_29 ) ;
return F_80 (
V_85 -> V_20 ,
V_85 -> V_86 , V_90 ) ;
}
void F_81 ( struct V_2 * V_3 ,
struct V_91 * V_92 )
{
int V_19 ;
int V_93 ;
struct V_7 * V_15 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
struct V_28 * V_71 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_3 V_94 = 0 , V_95 = 0 , V_96 = 0 , V_97 = 0 ;
T_3 V_98 = 0 , V_99 = 0 , V_100 = 0 ;
T_3 V_101 = 0 ;
V_15 = F_3 ( V_3 -> V_9 ) ;
if ( ! V_15 )
return;
V_19 = V_5 -> V_17 ;
V_18 = F_5 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
for ( V_93 = 0 ; V_93 < V_3 -> V_26 ; V_93 ++ ) {
V_71 = V_3 -> V_43 [ V_93 ] ;
F_82 ( V_71 ) ;
V_94 += V_71 -> V_45 . V_102 . V_94 ;
V_96 += V_71 -> V_45 . V_102 . V_103 ;
V_95 += V_71 -> V_44 . V_102 . V_95 ;
V_97 += V_71 -> V_44 . V_102 . V_104 ;
V_98 += V_71 -> V_44 . V_102 . V_105
+ V_71 -> V_44 . V_102 . V_106
+ V_71 -> V_44 . V_102 . V_107 ;
}
F_83 ( V_18 ) ;
V_101 = V_18 -> V_108 . V_109 ;
V_99 += V_18 -> V_108 . V_110
+ V_18 -> V_108 . V_111 ;
if ( V_6 -> V_50 == V_54 ) {
F_84 ( V_15 , V_19 ) ;
V_101 += V_15 -> V_108 [ V_19 ] . V_112 ;
V_101 += V_15 -> V_108 [ V_19 ] . V_113 ;
V_101 += V_15 -> V_108 [ V_19 ] . V_114 ;
V_19 = V_19 + V_115 ;
F_84 ( V_15 , V_19 ) ;
V_100 += V_15 -> V_108 [ V_19 ] . V_112 ;
V_100 += V_15 -> V_108 [ V_19 ] . V_113 ;
V_100 += V_15 -> V_108 [ V_19 ] . V_114 ;
V_100 += V_15 -> V_108 [ V_19 ] . V_116 ;
V_100 += V_15 -> V_108 [ V_19 ] . V_117 ;
V_100 += V_15 -> V_108 [ V_19 ] . V_118 ;
}
F_85 ( V_6 ) ;
V_98 += V_6 -> V_108 . V_119 ;
V_99 += V_6 -> V_108 . V_120
+ V_6 -> V_108 . V_121
+ V_6 -> V_108 . V_122
+ V_6 -> V_108 . V_123
+ V_6 -> V_108 . V_124 ;
V_92 -> V_94 = V_94 ;
V_92 -> V_96 = V_96 ;
V_92 -> V_95 = V_95 ;
V_92 -> V_125 = 0 ;
V_92 -> V_97 = V_97 ;
V_92 -> V_98 = V_98 ;
V_92 -> V_99 = V_99 ;
V_92 -> V_100 = V_100 ;
V_92 -> V_101 = V_101 ;
V_92 -> V_126 = V_6 -> V_108 . V_127 ;
V_92 -> V_128 = V_6 -> V_108 . V_129 ;
V_92 -> V_130 = V_6 -> V_108 . V_119 ;
V_92 -> V_131 = V_6 -> V_108 . V_132 ;
V_92 -> V_133 = V_6 -> V_108 . V_134 ;
}
void F_86 ( struct V_2 * V_3 , T_3 * V_135 )
{
int V_93 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
T_3 * V_55 = V_135 ;
struct V_4 * V_5 ;
if ( ! V_3 || ! V_135 ) {
F_87 ( L_6 ) ;
return;
}
V_5 = F_2 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_18 = F_5 ( V_3 ) ;
for ( V_93 = 0 ; V_93 < V_3 -> V_26 ; V_93 ++ ) {
F_88 ( V_3 -> V_43 [ V_93 ] , V_55 ) ;
V_55 += F_89 ( ( int ) V_136 ) ;
}
F_90 ( V_18 , V_55 ) ;
V_55 += F_91 ( ( int ) V_136 ) ;
F_92 ( V_6 , V_55 ) ;
V_55 += F_93 ( V_6 , ( int ) V_136 ) ;
if ( V_6 -> V_50 == V_54 )
F_94 ( V_5 -> V_15 , V_55 , V_5 -> V_17 ) ;
}
void F_95 ( struct V_2 * V_3 ,
T_1 V_137 , V_57 * V_135 )
{
int V_19 ;
int V_93 ;
struct V_1 * V_6 ;
struct V_11 * V_18 ;
V_57 * V_55 = V_135 ;
struct V_4 * V_5 ;
assert ( V_3 ) ;
V_5 = F_2 ( V_3 ) ;
V_19 = V_5 -> V_17 ;
V_6 = F_1 ( V_3 ) ;
V_18 = F_5 ( V_3 ) ;
for ( V_93 = 0 ; V_93 < V_3 -> V_26 ; V_93 ++ ) {
F_96 ( V_137 , V_55 , V_93 ) ;
V_55 += V_138 * F_89 ( V_137 ) ;
}
F_97 ( V_18 , V_137 , V_55 ) ;
V_55 += V_138 * F_91 ( V_137 ) ;
F_98 ( V_6 , V_137 , V_55 ) ;
V_55 += V_138 * F_93 ( V_6 , V_137 ) ;
if ( V_6 -> V_50 == V_54 )
F_99 ( V_137 , V_55 , V_19 ) ;
}
int F_100 ( struct V_2 * V_3 , int V_137 )
{
T_1 V_139 = 0 ;
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_139 += F_89 ( V_137 ) * V_3 -> V_26 ;
V_139 += F_91 ( V_137 ) ;
V_139 += F_93 ( V_6 , V_137 ) ;
if ( V_6 -> V_50 == V_54 )
V_139 += F_101 ( V_137 ) ;
return V_139 ;
}
static int F_102 ( struct V_2 * V_3 ,
enum V_140 V_141 , int V_81 )
{
int V_56 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
switch ( V_141 ) {
case V_142 :
V_56 = 0 ;
break;
case V_143 :
V_56 = F_103 ( V_5 -> V_6 , V_81 ) ;
break;
case V_144 :
V_56 = F_104 ( V_5 -> V_6 , V_141 , V_81 ) ;
break;
default:
V_56 = - V_41 ;
}
if ( ! V_56 )
F_105 ( V_6 -> V_15 , V_6 -> V_61 , V_81 ) ;
return V_56 ;
}
void F_106 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 -> V_145 )
return;
F_107 ( V_6 ) ;
}
int F_108 ( struct V_2 * V_3 ,
enum V_146 V_147 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
return F_109 ( V_6 , V_147 ) ;
}
void F_110 ( struct V_2 * V_3 , void * V_135 )
{
T_1 * V_55 = V_135 ;
int V_33 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_11 * V_18 = F_5 ( V_3 ) ;
F_111 ( V_18 , V_55 ) ;
V_55 += F_112 () ;
F_113 ( V_5 -> V_15 -> V_20 [ 0 ] , V_55 ) ;
V_55 += F_114 () ;
for ( V_33 = 0 ; V_33 < V_3 -> V_26 ; V_33 ++ ) {
F_115 ( V_3 -> V_43 [ V_33 ] , V_55 ) ;
V_55 += F_116 () ;
}
F_117 ( V_5 -> V_6 , V_55 ) ;
V_55 += F_118 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_50 == V_54 )
F_119 ( V_5 -> V_15 , V_5 -> V_17 , V_55 ) ;
}
int F_120 ( struct V_2 * V_3 )
{
T_1 V_148 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_148 = F_112 () ;
V_148 += F_114 () ;
V_148 += F_116 () * V_3 -> V_26 ;
V_148 += F_118 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_50 == V_54 )
V_148 += F_121 () ;
return V_148 ;
}
static T_1 F_122 ( struct V_2 * V_3 )
{
return V_149 ;
}
static T_1 F_123 ( struct V_2 * V_3 )
{
return V_150 ;
}
static int F_124 ( struct V_2 * V_3 , T_1 * V_151 , V_57 * V_152 ,
V_57 * V_153 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
if ( V_153 )
* V_153 = V_154 ;
if ( V_152 )
memcpy ( V_152 , V_18 -> V_155 , V_149 ) ;
memcpy ( V_151 , V_18 -> V_156 ,
V_150 * sizeof( * V_151 ) ) ;
return 0 ;
}
static int F_125 ( struct V_2 * V_3 , const T_1 * V_151 ,
const V_57 * V_152 , const V_57 V_153 )
{
struct V_11 * V_18 = F_5 ( V_3 ) ;
if ( V_152 )
F_126 ( V_18 , ( T_1 * ) V_152 ) ;
memcpy ( V_18 -> V_156 , V_151 ,
V_150 * sizeof( * V_151 ) ) ;
F_127 ( V_18 , V_18 -> V_156 ) ;
return 0 ;
}
int F_128 ( struct V_7 * V_15 )
{
struct V_8 * V_10 = & V_15 -> V_10 ;
static T_4 V_157 = F_129 ( - 1 ) ;
switch ( V_15 -> V_72 ) {
case V_158 :
V_159 . V_160 = F_43 ;
break;
case V_161 :
V_159 . V_160 = F_46 ;
break;
default:
break;
}
snprintf ( V_10 -> V_162 , V_163 , L_7 , V_164 ,
( int ) F_130 ( & V_157 ) ) ;
V_10 -> V_165 = & V_159 ;
V_10 -> V_9 = V_15 -> V_9 ;
return F_131 ( V_10 , V_166 ) ;
}
void F_132 ( struct V_7 * V_15 )
{
F_133 ( & V_15 -> V_10 ) ;
}
