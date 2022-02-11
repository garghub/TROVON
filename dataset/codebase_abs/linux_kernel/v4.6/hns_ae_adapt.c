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
V_28 ++ ;
}
V_5 -> V_20 = V_20 ;
V_5 -> V_8 = V_36 ;
V_5 -> V_6 = & V_20 -> V_6 [ V_36 ] ;
V_40 -> V_52 = V_5 -> V_6 -> V_52 ;
V_40 -> V_53 = V_5 -> V_6 -> V_53 ;
V_40 -> V_54 = V_5 -> V_6 -> V_54 ;
V_40 -> V_55 = V_5 -> V_6 -> V_56 ;
V_40 -> V_57 = V_36 ;
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
if ( V_5 -> V_6 -> V_56 == V_60 )
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
if ( V_6 -> V_56 != V_60 )
return 0 ;
V_62 = F_29 ( V_6 , V_6 -> V_67 , V_66 , true ) ;
if ( V_62 ) {
F_15 ( V_3 -> V_44 ,
L_5 ,
V_66 , V_6 -> V_67 , V_62 ) ;
return V_62 ;
}
V_62 = F_29 ( V_6 , V_68 ,
V_66 , true ) ;
if ( V_62 )
F_15 ( V_3 -> V_44 ,
L_5 ,
V_66 , V_68 , V_62 ) ;
return V_62 ;
}
static int F_30 ( struct V_2 * V_3 , int V_69 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_31 ( V_6 , V_69 ) ;
}
static void F_32 ( struct V_2 * V_3 , int V_70 )
{
struct V_15 * V_22 = F_6 ( V_3 ) ;
F_33 ( V_22 , V_70 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
int V_62 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_62 = F_35 ( V_6 , 0 , true ) ;
if ( V_62 )
return V_62 ;
F_19 ( V_3 , 1 ) ;
F_36 ( 100 ) ;
F_37 ( V_6 ) ;
return 0 ;
}
void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_39 ( V_3 -> V_49 , V_3 -> V_31 , V_71 ) ;
F_36 ( 20 ) ;
F_40 ( V_6 ) ;
F_41 ( 10000 , 20000 ) ;
F_19 ( V_3 , 0 ) ;
( void ) F_35 ( V_6 , 0 , false ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_6 -> V_56 == V_72 ) {
V_63 V_17 =
V_5 -> V_8 - V_10 + 1 ;
F_43 ( V_5 -> V_6 ) ;
F_44 ( V_5 -> V_20 , V_17 ) ;
}
}
void F_45 ( struct V_73 * V_59 , T_1 V_74 )
{
T_1 V_75 ;
if ( F_46 ( V_59 ) )
V_75 = V_71 ;
else
V_75 = V_76 ;
F_47 ( V_59 -> V_35 , V_75 , V_74 ) ;
}
static void F_48 ( struct V_73 * V_59 , T_1 V_74 )
{
T_1 V_75 ;
if ( F_46 ( V_59 ) )
V_75 = V_71 ;
else
V_75 = V_76 ;
F_49 ( V_59 -> V_35 , V_75 , V_74 ) ;
}
static void F_50 ( struct V_34 * V_77 , T_1 V_58 )
{
struct V_11 * V_20 = F_4 ( V_77 -> V_13 ) ;
if ( F_51 ( V_20 -> V_78 ) )
F_52 ( V_77 , V_71 | V_76 ) ;
else
F_53 ( V_77 , V_71 | V_76 ) ;
F_54 ( V_77 , V_58 ) ;
}
static int F_55 ( struct V_2 * V_3 )
{
T_1 V_79 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_56 ( V_6 , & V_79 ) ;
return ! ! V_79 ;
}
static int F_57 ( struct V_2 * V_3 ,
V_63 * V_80 , T_2 * V_81 , V_63 * V_82 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_58 ( V_6 , V_80 , V_81 , V_82 ) ;
}
static void F_59 ( struct V_2 * V_3 , int V_81 ,
int V_82 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_60 ( V_6 , V_81 , V_82 ) ;
}
static void F_61 ( struct V_34 * V_77 ,
T_1 * V_83 )
{
* V_83 = V_84 ;
}
static void F_62 ( struct V_2 * V_3 ,
T_1 * V_80 , T_1 * V_85 , T_1 * V_86 )
{
assert ( V_3 ) ;
F_63 ( F_1 ( V_3 ) , V_80 ) ;
F_64 ( F_1 ( V_3 ) , V_85 , V_86 ) ;
}
static int F_65 ( struct V_2 * V_3 , V_63 V_70 )
{
assert ( V_3 ) ;
return F_66 ( F_1 ( V_3 ) , V_70 ) ;
}
static void F_67 ( struct V_2 * V_3 , T_1 V_87 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_68 ( F_4 ( V_3 -> V_13 ) , V_87 ) ;
F_69 ( V_6 , ( V_63 ) ! ! V_87 ) ;
}
static int F_70 ( struct V_2 * V_3 )
{
T_1 V_80 ;
assert ( V_3 ) ;
F_63 ( F_1 ( V_3 ) , & V_80 ) ;
return V_80 ;
}
static int F_71 ( struct V_2 * V_3 ,
T_1 V_88 , T_1 V_85 , T_1 V_86 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_62 ;
V_62 = F_66 ( V_6 , V_88 ) ;
if ( V_62 )
return V_62 ;
return F_72 ( V_6 , V_85 , V_86 ) ;
}
static void F_73 ( struct V_2 * V_3 ,
T_1 * V_89 , T_1 * V_90 )
{
struct V_28 * V_91 =
F_5 ( V_3 -> V_49 [ 0 ] , struct V_28 , V_35 ) ;
* V_89 = F_74 ( V_91 -> V_25 ,
V_91 -> V_92 ) ;
* V_90 = F_74 ( V_91 -> V_25 ,
V_91 -> V_92 ) ;
}
static void F_75 ( struct V_2 * V_3 ,
T_1 * V_93 , T_1 * V_94 )
{
struct V_28 * V_91 =
F_5 ( V_3 -> V_49 [ 0 ] , struct V_28 , V_35 ) ;
* V_93 = F_76 ( V_91 -> V_25 ,
V_91 -> V_92 ) ;
* V_94 = F_76 ( V_91 -> V_25 ,
V_91 -> V_92 ) ;
}
static int F_77 ( struct V_2 * V_3 ,
T_1 V_95 )
{
struct V_28 * V_91 =
F_5 ( V_3 -> V_49 [ 0 ] , struct V_28 , V_35 ) ;
return F_78 (
V_91 -> V_25 , V_91 -> V_92 , V_95 ) ;
}
static int F_79 ( struct V_2 * V_3 ,
T_1 V_96 )
{
struct V_28 * V_91 =
F_5 ( V_3 -> V_49 [ 0 ] , struct V_28 , V_35 ) ;
return F_80 (
V_91 -> V_25 ,
V_91 -> V_92 , V_96 ) ;
}
void F_81 ( struct V_2 * V_3 ,
struct V_97 * V_98 )
{
int V_23 ;
int V_99 ;
struct V_11 * V_20 ;
struct V_1 * V_6 ;
struct V_15 * V_22 ;
struct V_34 * V_77 ;
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
V_77 = V_3 -> V_49 [ V_99 ] ;
F_82 ( V_77 ) ;
V_100 += V_77 -> V_51 . V_108 . V_100 ;
V_102 += V_77 -> V_51 . V_108 . V_109 ;
V_101 += V_77 -> V_50 . V_108 . V_101 ;
V_103 += V_77 -> V_50 . V_108 . V_110 ;
V_104 += V_77 -> V_50 . V_108 . V_111
+ V_77 -> V_50 . V_108 . V_112
+ V_77 -> V_50 . V_108 . V_113 ;
}
F_83 ( V_22 ) ;
V_107 = V_22 -> V_114 . V_115 ;
V_105 += V_22 -> V_114 . V_116
+ V_22 -> V_114 . V_117 ;
if ( V_6 -> V_56 == V_60 ) {
F_84 ( V_20 , V_23 ) ;
V_107 += V_20 -> V_114 [ V_23 ] . V_118 ;
V_107 += V_20 -> V_114 [ V_23 ] . V_119 ;
V_107 += V_20 -> V_114 [ V_23 ] . V_120 ;
V_23 = V_23 + V_121 ;
F_84 ( V_20 , V_23 ) ;
V_106 += V_20 -> V_114 [ V_23 ] . V_118 ;
V_106 += V_20 -> V_114 [ V_23 ] . V_119 ;
V_106 += V_20 -> V_114 [ V_23 ] . V_120 ;
V_106 += V_20 -> V_114 [ V_23 ] . V_122 ;
V_106 += V_20 -> V_114 [ V_23 ] . V_123 ;
V_106 += V_20 -> V_114 [ V_23 ] . V_124 ;
}
F_85 ( V_6 ) ;
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
void F_86 ( struct V_2 * V_3 , T_3 * V_141 )
{
int V_99 ;
struct V_1 * V_6 ;
struct V_15 * V_22 ;
T_3 * V_61 = V_141 ;
struct V_4 * V_5 ;
if ( ! V_3 || ! V_141 ) {
F_87 ( L_6 ) ;
return;
}
V_5 = F_2 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_22 = F_6 ( V_3 ) ;
for ( V_99 = 0 ; V_99 < V_3 -> V_31 ; V_99 ++ ) {
F_88 ( V_3 -> V_49 [ V_99 ] , V_61 ) ;
V_61 += F_89 ( ( int ) V_142 ) ;
}
F_90 ( V_22 , V_61 ) ;
V_61 += F_91 ( ( int ) V_142 ) ;
F_92 ( V_6 , V_61 ) ;
V_61 += F_93 ( V_6 , ( int ) V_142 ) ;
if ( V_6 -> V_56 == V_60 )
F_94 ( V_5 -> V_20 , V_61 , V_5 -> V_8 ) ;
}
void F_95 ( struct V_2 * V_3 ,
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
F_96 ( V_143 , V_61 , V_99 ) ;
V_61 += V_144 * F_89 ( V_143 ) ;
}
F_97 ( V_22 , V_143 , V_61 ) ;
V_61 += V_144 * F_91 ( V_143 ) ;
F_98 ( V_6 , V_143 , V_61 ) ;
V_61 += V_144 * F_93 ( V_6 , V_143 ) ;
if ( V_6 -> V_56 == V_60 )
F_99 ( V_143 , V_61 , V_23 ) ;
}
int F_100 ( struct V_2 * V_3 , int V_143 )
{
T_1 V_145 = 0 ;
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_145 += F_89 ( V_143 ) * V_3 -> V_31 ;
V_145 += F_91 ( V_143 ) ;
V_145 += F_93 ( V_6 , V_143 ) ;
if ( V_6 -> V_56 == V_60 )
V_145 += F_101 ( V_143 ) ;
return V_145 ;
}
static int F_102 ( struct V_2 * V_3 ,
enum V_146 V_147 , int V_87 )
{
int V_62 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
switch ( V_147 ) {
case V_148 :
V_62 = 0 ;
break;
case V_149 :
V_62 = F_103 ( V_5 -> V_6 , V_87 ) ;
break;
case V_150 :
V_62 = F_104 ( V_5 -> V_6 , V_147 , V_87 ) ;
break;
default:
V_62 = - V_47 ;
}
if ( ! V_62 )
F_105 ( V_6 -> V_20 , V_6 -> V_67 , V_87 ) ;
return V_62 ;
}
void F_106 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 -> V_151 )
return;
F_107 ( V_6 ) ;
}
int F_108 ( struct V_2 * V_3 ,
enum V_152 V_153 )
{
struct V_1 * V_6 ;
assert ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
return F_109 ( V_6 , V_153 ) ;
}
void F_110 ( struct V_2 * V_3 , void * V_141 )
{
T_1 * V_61 = V_141 ;
T_1 V_154 ;
int V_39 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_15 * V_22 = F_6 ( V_3 ) ;
F_111 ( V_22 , V_61 ) ;
V_61 += F_112 () ;
V_154 = F_8 ( V_5 -> V_8 ) ;
F_113 ( V_5 -> V_20 -> V_25 [ V_154 ] , V_61 ) ;
V_61 += F_114 () ;
for ( V_39 = 0 ; V_39 < V_3 -> V_31 ; V_39 ++ ) {
F_115 ( V_3 -> V_49 [ V_39 ] , V_61 ) ;
V_61 += F_116 () ;
}
F_117 ( V_5 -> V_6 , V_61 ) ;
V_61 += F_118 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_56 == V_60 )
F_119 ( V_5 -> V_20 , V_5 -> V_8 , V_61 ) ;
}
int F_120 ( struct V_2 * V_3 )
{
T_1 V_155 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_155 = F_112 () ;
V_155 += F_114 () ;
V_155 += F_116 () * V_3 -> V_31 ;
V_155 += F_118 ( V_5 -> V_6 ) ;
if ( V_5 -> V_6 -> V_56 == V_60 )
V_155 += F_121 () ;
return V_155 ;
}
static T_1 F_122 ( struct V_2 * V_3 )
{
return V_156 ;
}
static T_1 F_123 ( struct V_2 * V_3 )
{
return V_157 ;
}
static int F_124 ( struct V_2 * V_3 , T_1 * V_158 , V_63 * V_159 ,
V_63 * V_160 )
{
struct V_15 * V_22 = F_6 ( V_3 ) ;
if ( V_160 )
* V_160 = V_161 ;
if ( V_159 )
memcpy ( V_159 , V_22 -> V_162 , V_156 ) ;
memcpy ( V_158 , V_22 -> V_163 ,
V_157 * sizeof( * V_158 ) ) ;
return 0 ;
}
static int F_125 ( struct V_2 * V_3 , const T_1 * V_158 ,
const V_63 * V_159 , const V_63 V_160 )
{
struct V_15 * V_22 = F_6 ( V_3 ) ;
if ( V_159 )
F_126 ( V_22 , ( T_1 * ) V_159 ) ;
memcpy ( V_22 -> V_163 , V_158 ,
V_157 * sizeof( * V_158 ) ) ;
F_127 ( V_22 , V_22 -> V_163 ) ;
return 0 ;
}
int F_128 ( struct V_11 * V_20 )
{
struct V_12 * V_14 = & V_20 -> V_14 ;
static T_4 V_164 = F_129 ( - 1 ) ;
switch ( V_20 -> V_78 ) {
case V_165 :
V_166 . V_167 = F_45 ;
break;
case V_168 :
V_166 . V_167 = F_48 ;
break;
default:
break;
}
snprintf ( V_14 -> V_169 , V_170 , L_7 , V_171 ,
( int ) F_130 ( & V_164 ) ) ;
V_14 -> V_172 = & V_166 ;
V_14 -> V_13 = V_20 -> V_13 ;
return F_131 ( V_14 , V_173 ) ;
}
void F_132 ( struct V_11 * V_20 )
{
F_133 ( & V_20 -> V_14 ) ;
}
