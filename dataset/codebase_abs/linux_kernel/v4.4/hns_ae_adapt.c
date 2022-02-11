static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_6 ;
}
static int F_3 ( T_1 V_7 )
{
int V_8 ;
if ( V_7 < V_9 )
V_8 = V_7 + V_10 ;
else
V_8 = V_7 - V_9 ;
return V_8 ;
}
static struct V_11 * F_4 ( struct V_12 * V_13 )
{
return F_5 ( V_13 , struct V_11 , V_14 ) ;
}
static struct V_15 * F_6 ( struct V_2 * V_3 )
{
int V_16 ;
int V_17 ;
struct V_18 * V_19 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_8 < V_10 ) {
V_16 = V_5 -> V_8 ;
V_17 = 0 ;
} else {
V_16 = 0 ;
V_17 =
V_5 -> V_8 - V_10 + 1 ;
}
V_19 = V_5 -> V_20 -> V_21 [ V_17 ] ;
return & V_19 -> V_22 [ V_16 ] ;
}
static int F_7 (
struct V_11 * V_20 , int V_23 )
{
int V_24 = F_8 ( V_23 ) ;
return V_20 -> V_25 [ V_24 ] -> V_26 ;
}
static int F_9 (
struct V_11 * V_20 , int V_23 )
{
int V_24 = F_8 ( V_23 ) ;
return V_20 -> V_25 [ V_24 ] -> V_27 ;
}
static struct V_28 * F_10 (
struct V_11 * V_20 , int V_23 )
{
int V_24 = F_8 ( V_23 ) ;
struct V_29 * V_30 = V_20 -> V_25 [ V_24 ] ;
int V_31 = V_30 -> V_26 ;
int V_32 = V_30 -> V_27 ;
if ( V_24 == V_33 )
return & V_30 -> V_28 [ V_23 * V_31 * V_32 ] ;
else
return & V_30 -> V_28 [ 0 ] ;
}
static struct V_28 * F_11 ( struct V_34 * V_35 )
{
return F_5 ( V_35 , struct V_28 , V_35 ) ;
}
struct V_2 * F_12 ( struct V_12 * V_13 ,
T_1 V_7 )
{
int V_36 ;
int V_37 ;
int V_38 ;
int V_39 ;
struct V_11 * V_20 ;
struct V_2 * V_40 ;
struct V_28 * V_28 ;
struct V_4 * V_5 ;
V_20 = F_4 ( V_13 ) ;
V_36 = F_3 ( V_7 ) ;
V_28 = F_10 ( V_20 , V_36 ) ;
V_37 = F_9 ( V_20 , V_36 ) ;
V_38 = F_7 ( V_20 , V_36 ) ;
V_5 = F_13 ( sizeof( * V_5 ) +
V_38 * sizeof( struct V_34 * ) , V_41 ) ;
if ( F_14 ( ! V_5 ) ) {
F_15 ( V_20 -> V_13 , L_1 ) ;
V_40 = F_16 ( - V_42 ) ;
goto V_43;
}
V_40 = & V_5 -> V_40 ;
V_40 -> V_44 = V_20 -> V_13 ;
V_40 -> V_13 = V_13 ;
V_40 -> V_31 = V_38 ;
for ( V_40 -> V_45 = 0 ;
V_40 -> V_45 < V_37 ; V_40 -> V_45 ++ ) {
if ( ! V_28 -> V_46 )
break;
V_28 += V_38 ;
}
if ( V_40 -> V_45 >= V_37 ) {
F_15 ( V_20 -> V_13 , L_2 ) ;
V_40 = F_16 ( - V_47 ) ;
goto V_48;
}
V_40 -> V_49 = (struct V_34 * * ) ( & V_40 -> V_49 + 1 ) ;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ ) {
V_40 -> V_49 [ V_39 ] = & V_28 -> V_35 ;
V_40 -> V_49 [ V_39 ] -> V_50 . V_35 = V_40 -> V_49 [ V_39 ] ;
V_40 -> V_49 [ V_39 ] -> V_51 . V_35 = V_40 -> V_49 [ V_39 ] ;
V_28 -> V_46 = 1 ;
if ( V_36 < V_10 )
V_28 -> V_52 = V_36 ;
else
V_28 -> V_52 = 0 ;
V_28 ++ ;
}
V_5 -> V_20 = V_20 ;
V_5 -> V_8 = V_36 ;
V_5 -> V_6 = & V_20 -> V_6 [ V_36 ] ;
V_40 -> V_53 = V_5 -> V_6 -> V_53 ;
V_40 -> V_54 = V_5 -> V_6 -> V_54 ;
V_40 -> V_55 = V_5 -> V_6 -> V_55 ;
V_40 -> V_56 = V_5 -> V_6 -> V_57 ;
return V_40 ;
V_48:
F_17 ( V_5 ) ;
V_43:
return V_40 ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_39 ;
V_5 -> V_6 = NULL ;
F_17 ( V_5 ) ;
for ( V_39 = 0 ; V_39 < V_3 -> V_31 ; V_39 ++ )
F_11 ( V_3 -> V_49 [ V_39 ] ) -> V_46 = 0 ;
}
static void F_19 ( struct V_2 * V_3 , int V_58 )
{
int V_31 = V_3 -> V_31 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_31 ; V_39 ++ )
F_20 ( V_3 -> V_49 [ V_39 ] , V_58 ) ;
}
static void F_21 ( struct V_34 * V_35 )
{
struct V_28 * V_59 =
F_5 ( V_35 , struct V_28 , V_35 ) ;
F_22 ( V_59 ) ;
}
static void F_23 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = F_2 ( V_35 -> V_3 ) ;
if ( V_5 -> V_6 -> V_57 == V_60 )
F_24 ( V_35 ) ;
}
static int F_25 ( struct V_2 * V_3 , void * V_61 )
{
int V_62 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( ! V_61 || ! F_26 ( ( const V_63 * ) V_61 ) ) {
F_15 ( V_3 -> V_44 , L_3 ) ;
return - V_64 ;
}
V_62 = F_27 ( V_6 , V_3 -> V_45 , V_61 ) ;
if ( V_62 != 0 ) {
F_15 ( V_3 -> V_44 ,
L_4 , V_62 ) ;
return V_62 ;
}
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , void * V_65 )
{
int V_62 ;
char * V_66 = ( char * ) V_65 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
assert ( V_6 ) ;
if ( V_6 -> V_57 != V_60 )
return 0 ;
V_62 = F_29 ( V_6 , V_6 -> V_67 , V_66 , V_68 ) ;
if ( V_62 ) {
F_15 ( V_3 -> V_44 ,
L_5 ,
V_66 , V_6 -> V_67 , V_62 ) ;
return V_62 ;
}
V_62 = F_29 ( V_6 , V_69 ,
V_66 , V_68 ) ;
if ( V_62 )
F_15 ( V_3 -> V_44 ,
L_5 ,
V_66 , V_69 , V_62 ) ;
return V_62 ;
}
static int F_30 ( struct V_2 * V_3 , int V_70 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_31 ( V_6 , V_70 ) ;
}
static int F_32 ( struct V_2 * V_3 )
{
int V_62 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_62 = F_33 ( V_6 , 0 , V_68 ) ;
if ( V_62 )
return V_62 ;
F_19 ( V_3 , 1 ) ;
F_34 ( 100 ) ;
F_35 ( V_6 ) ;
return 0 ;
}
void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_37 ( V_3 -> V_49 , V_3 -> V_31 , V_71 ) ;
F_34 ( 20 ) ;
F_38 ( V_6 ) ;
F_39 ( 10000 , 20000 ) ;
F_19 ( V_3 , 0 ) ;
( void ) F_33 ( V_6 , 0 , V_72 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_6 -> V_57 == V_73 ) {
V_63 V_17 =
V_5 -> V_8 - V_10 + 1 ;
F_41 ( V_5 -> V_6 ) ;
F_42 ( V_5 -> V_20 , V_17 ) ;
}
}
void F_43 ( struct V_74 * V_59 , T_1 V_75 )
{
T_1 V_76 ;
if ( F_44 ( V_59 ) )
V_76 = V_71 ;
else
V_76 = V_77 ;
F_45 ( V_59 -> V_35 , V_76 ) ;
F_46 ( V_59 -> V_35 , V_76 , V_75 ) ;
}
static void F_47 ( struct V_34 * V_78 , T_1 V_58 )
{
F_48 ( V_78 , V_58 ) ;
}
static int F_49 ( struct V_2 * V_3 )
{
T_1 V_79 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_50 ( V_6 , & V_79 ) ;
return ! ! V_79 ;
}
static int F_51 ( struct V_2 * V_3 ,
V_63 * V_80 , T_2 * V_81 , V_63 * V_82 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_52 ( V_6 , V_80 , V_81 , V_82 ) ;
}
static void F_53 ( struct V_2 * V_3 , int V_81 ,
int V_82 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_54 ( V_6 , V_81 , V_82 ) ;
}
static void F_55 ( struct V_34 * V_78 ,
T_1 * V_83 )
{
* V_83 = V_84 ;
}
static void F_56 ( struct V_2 * V_3 ,
T_1 * V_80 , T_1 * V_85 , T_1 * V_86 )
{
assert ( V_3 ) ;
F_57 ( F_1 ( V_3 ) , V_80 ) ;
F_58 ( F_1 ( V_3 ) , V_85 , V_86 ) ;
}
static int F_59 ( struct V_2 * V_3 , V_63 V_87 )
{
assert ( V_3 ) ;
return F_60 ( F_1 ( V_3 ) , V_87 ) ;
}
static void F_61 ( struct V_2 * V_3 , T_1 V_88 )
{
F_62 ( F_4 ( V_3 -> V_13 ) , V_88 ) ;
}
static int F_63 ( struct V_2 * V_3 )
{
T_1 V_80 ;
assert ( V_3 ) ;
F_57 ( F_1 ( V_3 ) , & V_80 ) ;
return V_80 ;
}
static int F_64 ( struct V_2 * V_3 ,
T_1 V_89 , T_1 V_85 , T_1 V_86 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_62 ;
V_62 = F_60 ( V_6 , V_89 ) ;
if ( V_62 )
return V_62 ;
return F_65 ( V_6 , V_85 , V_86 ) ;
}
static void F_66 ( struct V_2 * V_3 ,
T_1 * V_90 , T_1 * V_91 )
{
int V_23 ;
V_23 = F_3 ( V_3 -> V_92 ) ;
* V_90 = F_67 (
F_4 ( V_3 -> V_13 ) ,
F_8 ( V_23 ) ) ;
* V_91 = F_67 (
F_4 ( V_3 -> V_13 ) ,
F_8 ( V_23 ) ) ;
}
static void F_68 ( struct V_2 * V_3 ,
T_1 * V_93 , T_1 * V_94 )
{
int V_23 ;
assert ( V_3 ) ;
V_23 = F_3 ( V_3 -> V_92 ) ;
* V_93 = F_69 (
F_4 ( V_3 -> V_13 ) , V_23 ) ;
* V_94 = F_69 (
F_4 ( V_3 -> V_13 ) , V_23 ) ;
}
static void F_70 ( struct V_2 * V_3 ,
T_1 V_95 )
{
int V_23 ;
assert ( V_3 ) ;
V_23 = F_3 ( V_3 -> V_92 ) ;
F_71 ( F_4 ( V_3 -> V_13 ) ,
V_23 , V_95 ) ;
}
static int F_72 ( struct V_2 * V_3 ,
T_1 V_96 )
{
int V_23 ;
int V_62 ;
assert ( V_3 ) ;
V_23 = F_3 ( V_3 -> V_92 ) ;
V_62 = F_73 ( F_4 ( V_3 -> V_13 ) ,
V_23 , V_96 ) ;
return V_62 ;
}
void F_74 ( struct V_2 * V_3 ,
struct V_97 * V_98 )
{
int V_23 ;
int V_99 ;
struct V_11 * V_20 ;
struct V_1 * V_6 ;
struct V_15 * V_22 ;
struct V_34 * V_78 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_3 V_100 = 0 , V_101 = 0 , V_102 = 0 , V_103 = 0 ;
T_3 V_104 = 0 , V_105 = 0 , V_106 = 0 ;
T_3 V_107 = 0 ;
V_20 = F_4 ( V_3 -> V_13 ) ;
if ( ! V_20 )
return;
V_23 = V_5 -> V_8 ;
V_22 = F_6 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
for ( V_99 = 0 ; V_99 < V_3 -> V_31 ; V_99 ++ ) {
V_78 = V_3 -> V_49 [ V_99 ] ;
F_75 ( V_78 ) ;
V_100 += V_78 -> V_51 . V_108 . V_100 ;
V_102 += V_78 -> V_51 . V_108 . V_109 ;
V_101 += V_78 -> V_50 . V_108 . V_101 ;
V_103 += V_78 -> V_50 . V_108 . V_110 ;
V_104 += V_78 -> V_50 . V_108 . V_111
+ V_78 -> V_50 . V_108 . V_112
+ V_78 -> V_50 . V_108 . V_113 ;
}
F_76 ( V_22 ) ;
V_107 = V_22 -> V_114 . V_115 ;
V_105 += V_22 -> V_114 . V_116
+ V_22 -> V_114 . V_117 ;
if ( V_6 -> V_57 == V_60 ) {
F_77 ( V_20 , V_23 ) ;
V_107 += V_20 -> V_114 [ V_23 ] . V_118 ;
V_107 += V_20 -> V_114 [ V_23 ] . V_119 ;
V_107 += V_20 -> V_114 [ V_23 ] . V_120 ;
V_23 = V_23 + V_121 ;
F_77 ( V_20 , V_23 ) ;
V_106 += V_20 -> V_114 [ V_23 ] . V_118 ;
V_106 += V_20 -> V_114 [ V_23 ] . V_119 ;
V_106 += V_20 -> V_114 [ V_23 ] . V_120 ;
V_106 += V_20 -> V_114 [ V_23 ] . V_122 ;
V_106 += V_20 -> V_114 [ V_23 ] . V_123 ;
V_106 += V_20 -> V_114 [ V_23 ] . V_124 ;
}
F_78 ( V_6 ) ;
V_104 += V_6 -> V_114 . V_125 ;
V_105 += V_6 -> V_114 . V_126
+ V_6 -> V_114 . V_127
+ V_6 -> V_114 . V_128
+ V_6 -> V_114 . V_129
+ V_6 -> V_114 . V_130 ;
V_98 -> V_100 = V_100 ;
V_98 -> V_102 = V_102 ;
V_98 -> V_101 = V_101 ;
V_98 -> V_131 = 0 ;
V_98 -> V_103 = V_103 ;
V_98 -> V_104 = V_104 ;
V_98 -> V_105 = V_105 ;
V_98 -> V_106 = V_106 ;
V_98 -> V_107 = V_107 ;
V_98 -> V_132 = V_6 -> V_114 . V_133 ;
V_98 -> V_134 = V_6 -> V_114 . V_135 ;
V_98 -> V_136 = V_6 -> V_114 . V_125 ;
V_98 -> V_137 = V_6 -> V_114 . V_138 ;
V_98 -> V_139 = V_6 -> V_114 . V_140 ;
}
void F_79 ( struct V_2 * V_3 , T_3 * V_141 )
{
int V_99 ;
struct V_1 * V_6 ;
struct V_15 * V_22 ;
T_3 * V_61 = V_141 ;
struct V_4 * V_5 ;
if ( ! V_3 || ! V_141 ) {
F_80 ( L_6 ) ;
return;
}
V_5 = F_2 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_22 = F_6 ( V_3 ) ;
for ( V_99 = 0 ; V_99 < V_3 -> V_31 ; V_99 ++ ) {
F_81 ( V_3 -> V_49 [ V_99 ] , V_61 ) ;
V_61 += F_82 ( ( int ) V_142 ) ;
}
F_83 ( V_22 , V_61 ) ;
V_61 += F_84 ( ( int ) V_142 ) ;
F_85 ( V_6 , V_61 ) ;
V_61 += F_86 ( V_6 , ( int ) V_142 ) ;
if ( V_6 -> V_57 == V_60 )
F_87 ( V_5 -> V_20 , V_61 , V_5 -> V_8 ) ;
}
void F_88 ( struct V_2 * V_3 ,
T_1 V_143 , V_63 * V_141 )
{
int V_23 ;
int V_99 ;
struct V_1 * V_6 ;
struct V_15 * V_22 ;
V_63 * V_61 = V_141 ;
struct V_4 * V_5 ;
assert ( V_3 ) ;
V_5 = F_2 ( V_3 ) ;
V_23 = V_5 -> V_8 ;
V_6 = F_1 ( V_3 ) ;
V_22 = F_6 ( V_3 ) ;
for ( V_99 = 0 ; V_99 < V_3 -> V_31 ; V_99 ++ ) {
F_89 ( V_143 , V_61 , V_99 ) ;
V_61 += V_144 * F_82 ( V_143 ) ;
}
F_90 ( V_22 , V_143 , V_61 ) ;
V_61 += V_144 * F_84 ( V_143 ) ;
F_91 ( V_6 , V_143 , V_61 ) ;
V_61 += V_144 * F_86 ( V_6 , V_143 ) ;
if ( V_6 -> V_57 == V_60 )
F_92 ( V_143 , V_61 , V_23 ) ;
}
int F_93 ( struct V_2 * V_3 , int V_143 )
{
T_1 V_145 = 0 ;
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_145 += F_82 ( V_143 ) * V_3 -> V_31 ;
V_145 += F_84 ( V_143 ) ;
V_145 += F_86 ( V_6 , V_143 ) ;
if ( V_6 -> V_57 == V_60 )
V_145 += F_94 ( V_143 ) ;
return V_145 ;
}
static int F_95 ( struct V_2 * V_3 ,
enum V_146 V_147 , int V_88 )
{
int V_62 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
switch ( V_147 ) {
case V_148 :
V_62 = F_96 ( V_5 -> V_6 , V_88 ) ;
break;
case V_149 :
V_62 = F_97 ( V_5 -> V_6 , V_147 , V_88 ) ;
break;
default:
V_62 = - V_47 ;
}
return V_62 ;
}
void F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 -> V_150 )
return;
F_99 ( V_6 ) ;
}
int F_100 ( struct V_2 * V_3 ,
enum V_151 V_152 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
return F_101 ( V_6 , V_152 ) ;
}
void F_102 ( struct V_2 * V_3 , void * V_141 )
{
T_1 * V_61 = V_141 ;
T_1 V_153 ;
int V_39 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_15 * V_22 = F_6 ( V_3 ) ;
F_103 ( V_22 , V_61 ) ;
V_61 += F_104 () ;
V_153 = F_8 ( V_5 -> V_8 ) ;
F_105 ( V_5 -> V_20 -> V_25 [ V_153 ] , V_61 ) ;
V_61 += F_106 () ;
for ( V_39 = 0 ; V_39 < V_3 -> V_31 ; V_39 ++ ) {
F_107 ( V_3 -> V_49 [ V_39 ] , V_61 ) ;
V_61 += F_108 () ;
}
F_109 ( V_5 -> V_6 , V_61 ) ;
V_61 += F_110 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_57 == V_60 )
F_111 ( V_5 -> V_20 , V_5 -> V_8 , V_61 ) ;
}
int F_112 ( struct V_2 * V_3 )
{
T_1 V_154 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_154 = F_104 () ;
V_154 += F_106 () ;
V_154 += F_108 () * V_3 -> V_31 ;
V_154 += F_110 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_57 == V_60 )
V_154 += F_113 () ;
return V_154 ;
}
int F_114 ( struct V_11 * V_20 )
{
struct V_12 * V_14 = & V_20 -> V_14 ;
V_14 -> V_155 = & V_156 ;
V_14 -> V_13 = V_20 -> V_13 ;
return F_115 ( V_14 , V_157 ) ;
}
void F_116 ( struct V_11 * V_20 )
{
F_117 ( & V_20 -> V_14 ) ;
}
