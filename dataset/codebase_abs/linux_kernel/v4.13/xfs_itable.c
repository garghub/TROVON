int
F_1 (
T_1 * V_1 ,
T_2 V_2 )
{
return ( V_2 == V_1 -> V_3 . V_4 || V_2 == V_1 -> V_3 . V_5 ||
( F_2 ( & V_1 -> V_3 ) &&
F_3 ( & V_1 -> V_3 , V_2 ) ) ) ;
}
int
F_4 (
struct V_6 * V_1 ,
T_2 V_2 ,
void T_3 * V_7 ,
int V_8 ,
T_4 V_9 ,
int * V_10 ,
int * V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_16 ;
struct V_17 * V_18 ;
int error = 0 ;
* V_11 = V_19 ;
if ( ! V_7 || F_1 ( V_1 , V_2 ) )
return - V_20 ;
V_18 = F_5 ( sizeof( * V_18 ) , V_21 | V_22 ) ;
if ( ! V_18 )
return - V_23 ;
error = F_6 ( V_1 , NULL , V_2 ,
( V_24 | V_25 ) ,
V_26 , & V_15 ) ;
if ( error )
goto V_27;
ASSERT ( V_15 != NULL ) ;
ASSERT ( V_15 -> V_28 . V_29 != 0 ) ;
V_16 = F_7 ( V_15 ) ;
V_13 = & V_15 -> V_30 ;
V_18 -> V_31 = V_13 -> V_32 ;
V_18 -> V_33 = V_13 -> V_34 ;
V_18 -> V_35 = V_2 ;
V_18 -> V_36 = V_13 -> V_37 ;
V_18 -> V_38 = V_13 -> V_39 ;
V_18 -> V_40 = V_13 -> V_41 ;
V_18 -> V_42 = V_16 -> V_43 ;
V_18 -> V_44 . V_45 = V_16 -> V_46 . V_45 ;
V_18 -> V_44 . V_47 = V_16 -> V_46 . V_47 ;
V_18 -> V_48 . V_45 = V_16 -> V_49 . V_45 ;
V_18 -> V_48 . V_47 = V_16 -> V_49 . V_47 ;
V_18 -> V_50 . V_45 = V_16 -> V_51 . V_45 ;
V_18 -> V_50 . V_47 = V_16 -> V_51 . V_47 ;
V_18 -> V_52 = V_16 -> V_53 ;
V_18 -> V_54 = V_16 -> V_55 ;
V_18 -> V_56 = F_8 ( V_15 ) ;
V_18 -> V_57 = V_13 -> V_58 << V_1 -> V_3 . V_59 ;
V_18 -> V_60 = V_13 -> V_61 ;
memset ( V_18 -> V_62 , 0 , sizeof( V_18 -> V_62 ) ) ;
V_18 -> V_63 = V_13 -> V_64 ;
V_18 -> V_65 = V_13 -> V_66 ;
V_18 -> V_67 = V_13 -> V_68 ;
V_18 -> V_69 = F_9 ( V_15 ) ;
if ( V_13 -> V_70 == 3 ) {
if ( V_13 -> V_71 & V_72 )
V_18 -> V_73 = V_13 -> V_74 <<
V_1 -> V_3 . V_59 ;
}
switch ( V_13 -> V_75 ) {
case V_76 :
V_18 -> V_77 = V_15 -> V_78 . V_79 . V_80 ;
V_18 -> V_81 = V_82 ;
V_18 -> V_83 = 0 ;
break;
case V_84 :
case V_85 :
V_18 -> V_77 = 0 ;
V_18 -> V_81 = V_1 -> V_3 . V_86 ;
V_18 -> V_83 = 0 ;
break;
case V_87 :
case V_88 :
V_18 -> V_77 = 0 ;
V_18 -> V_81 = V_1 -> V_3 . V_86 ;
V_18 -> V_83 = V_13 -> V_89 + V_15 -> V_90 ;
break;
}
F_10 ( V_15 , V_26 ) ;
F_11 ( V_15 ) ;
error = V_9 ( V_7 , V_8 , V_10 , V_18 ) ;
if ( ! error )
* V_11 = V_91 ;
V_27:
F_12 ( V_18 ) ;
return error ;
}
STATIC int
F_13 (
void T_3 * V_92 ,
int V_8 ,
int * V_10 ,
const T_5 * V_7 )
{
if ( V_8 < sizeof( * V_7 ) )
return - V_23 ;
if ( F_14 ( V_92 , V_7 , sizeof( * V_7 ) ) )
return - V_93 ;
if ( V_10 )
* V_10 = sizeof( * V_7 ) ;
return 0 ;
}
int
F_15 (
T_1 * V_1 ,
T_2 V_2 ,
void T_3 * V_7 ,
int V_8 ,
int * V_10 ,
int * V_11 )
{
return F_4 ( V_1 , V_2 , V_7 , V_8 ,
F_13 , V_10 , V_11 ) ;
}
STATIC void
F_16 (
struct V_6 * V_1 ,
T_6 V_94 ,
struct V_95 * V_96 )
{
T_7 V_97 ;
struct V_98 V_99 ;
int V_100 ;
int V_101 ;
int V_102 ;
V_97 = F_17 ( V_1 , V_96 -> V_103 ) ;
V_100 = F_18 ( V_1 ) ;
V_101 = V_100 << V_1 -> V_3 . V_104 ;
F_19 ( & V_99 ) ;
for ( V_102 = 0 ; V_102 < V_105 ;
V_102 += V_101 , V_97 += V_100 ) {
if ( F_20 ( V_102 , V_101 ) & ~ V_96 -> V_106 ) {
F_21 ( V_1 , V_94 , V_97 , V_100 ,
& V_107 ) ;
}
}
F_22 ( & V_99 ) ;
}
STATIC int
F_23 (
struct V_108 * V_109 ,
T_8 V_110 ,
int * V_111 ,
struct V_95 * V_96 )
{
int V_112 ;
int V_11 ;
int error = 0 ;
error = F_24 ( V_109 , V_110 , V_113 , & V_11 ) ;
if ( error )
return error ;
if ( ! V_11 ) {
* V_111 = 0 ;
return error ;
}
error = F_25 ( V_109 , V_96 , & V_11 ) ;
if ( error )
return error ;
F_26 ( V_109 -> V_114 , V_11 == 1 ) ;
if ( V_96 -> V_103 + V_105 <= V_110 ) {
* V_111 = 0 ;
return 0 ;
}
V_112 = V_110 - V_96 -> V_103 + 1 ;
if ( V_112 < V_105 &&
( F_20 ( V_112 , V_105 - V_112 ) & ~ V_96 -> V_106 ) ) {
int V_102 ;
for ( V_102 = 0 ; V_102 < V_112 ; V_102 ++ ) {
if ( F_27 ( V_102 ) & ~ V_96 -> V_106 )
V_96 -> V_115 ++ ;
}
V_96 -> V_106 |= F_20 ( 0 , V_112 ) ;
* V_111 = V_96 -> V_116 - V_96 -> V_115 ;
}
return 0 ;
}
static int
F_28 (
struct V_6 * V_1 ,
T_6 V_94 ,
struct V_95 * V_117 ,
T_9 V_9 ,
T_10 V_118 ,
struct V_119 * V_120 ,
T_8 * V_121 )
{
char T_3 * * V_122 = V_120 -> V_123 ;
int V_124 ;
int error = 0 ;
T_8 V_110 = V_117 -> V_103 ;
for ( V_124 = 0 ; V_124 < V_105 ;
V_124 ++ , V_110 ++ ) {
int V_125 ;
int V_10 ;
if ( V_120 -> V_126 < V_118 )
break;
if ( F_27 ( V_124 ) & V_117 -> V_106 )
continue;
V_10 = V_118 ;
error = V_9 ( V_1 , F_29 ( V_1 , V_94 , V_110 ) ,
* V_122 , V_120 -> V_126 , & V_10 , & V_125 ) ;
if ( V_125 == V_127 ||
( error && error != - V_128 && error != - V_20 ) ) {
V_120 -> V_126 = 0 ;
ASSERT ( error ) ;
break;
}
if ( V_125 == V_19 || error ) {
error = 0 ;
continue;
}
* V_122 += V_10 ;
V_120 -> V_126 -= V_10 ;
V_120 -> V_129 ++ ;
}
* V_121 = V_110 - 1 ;
return error ;
}
int
F_30 (
T_1 * V_1 ,
T_2 * V_130 ,
int * V_131 ,
T_9 V_9 ,
T_10 V_118 ,
char T_3 * V_92 ,
int * V_132 )
{
T_11 * V_133 ;
T_8 V_110 ;
T_6 V_94 ;
T_12 * V_109 ;
T_13 * V_134 ;
int V_135 ;
int V_136 ;
struct V_119 V_137 ;
int error = 0 ;
V_94 = F_31 ( V_1 , * V_130 ) ;
V_110 = F_32 ( V_1 , * V_130 ) ;
if ( V_94 >= V_1 -> V_3 . V_138 ||
* V_130 != F_29 ( V_1 , V_94 , V_110 ) ) {
* V_132 = 1 ;
* V_131 = 0 ;
return 0 ;
}
V_136 = * V_131 ;
V_137 . V_123 = & V_92 ;
V_137 . V_126 = V_136 * V_118 ; ;
V_137 . V_129 = 0 ;
* V_131 = 0 ;
* V_132 = 0 ;
V_134 = F_33 ( V_139 * 4 , V_21 ) ;
if ( ! V_134 )
return - V_23 ;
V_135 = ( V_139 * 4 ) / sizeof( * V_134 ) ;
while ( V_94 < V_1 -> V_3 . V_138 ) {
struct V_95 * V_117 = V_134 ;
struct V_95 * V_140 = V_134 + V_135 ;
bool V_141 = false ;
int V_111 = 0 ;
int V_11 ;
error = F_34 ( V_1 , NULL , V_94 , & V_133 ) ;
if ( error )
break;
V_109 = F_35 ( V_1 , NULL , V_133 , V_94 ,
V_142 ) ;
if ( V_110 > 0 ) {
struct V_95 V_143 ;
error = F_23 ( V_109 , V_110 , & V_111 , & V_143 ) ;
if ( error )
goto V_144;
if ( V_111 ) {
V_117 -> V_103 = V_143 . V_103 ;
V_117 -> V_145 = V_143 . V_145 ;
V_117 -> V_116 = V_143 . V_116 ;
V_117 -> V_115 = V_143 . V_115 ;
V_117 -> V_106 = V_143 . V_106 ;
V_117 ++ ;
}
error = F_36 ( V_109 , 0 , & V_11 ) ;
} else {
error = F_24 ( V_109 , 0 , V_146 , & V_11 ) ;
}
if ( error || V_11 == 0 ) {
V_141 = true ;
goto V_144;
}
while ( V_117 < V_140 && V_111 < V_136 ) {
struct V_95 V_143 ;
error = F_25 ( V_109 , & V_143 , & V_11 ) ;
if ( error || V_11 == 0 ) {
V_141 = true ;
goto V_144;
}
if ( V_143 . V_115 < V_143 . V_116 ) {
F_16 ( V_1 , V_94 , & V_143 ) ;
V_117 -> V_103 = V_143 . V_103 ;
V_117 -> V_145 = V_143 . V_145 ;
V_117 -> V_116 = V_143 . V_116 ;
V_117 -> V_115 = V_143 . V_115 ;
V_117 -> V_106 = V_143 . V_106 ;
V_117 ++ ;
V_111 += V_143 . V_116 - V_143 . V_115 ;
}
error = F_36 ( V_109 , 0 , & V_11 ) ;
if ( error || V_11 == 0 ) {
V_141 = true ;
goto V_144;
}
F_37 () ;
}
V_144:
F_38 ( V_109 , error ?
V_147 : V_148 ) ;
F_39 ( V_133 ) ;
if ( error )
break;
V_140 = V_117 ;
for ( V_117 = V_134 ;
V_117 < V_140 && V_137 . V_126 >= V_118 ;
V_117 ++ ) {
error = F_28 ( V_1 , V_94 , V_117 ,
V_9 , V_118 , & V_137 ,
& V_110 ) ;
if ( error )
break;
F_37 () ;
}
if ( V_137 . V_126 < V_118 || error )
break;
if ( V_141 ) {
V_94 ++ ;
V_110 = 0 ;
}
}
F_12 ( V_134 ) ;
* V_131 = V_137 . V_129 ;
if ( V_137 . V_129 )
error = 0 ;
* V_130 = F_29 ( V_1 , V_94 , V_110 ) ;
if ( V_94 >= V_1 -> V_3 . V_138 )
* V_132 = 1 ;
return error ;
}
int
F_40 (
void T_3 * V_92 ,
const struct V_149 * V_7 ,
long V_150 ,
long * V_151 )
{
if ( F_14 ( V_92 , V_7 , V_150 * sizeof( * V_7 ) ) )
return - V_93 ;
* V_151 = V_150 * sizeof( * V_7 ) ;
return 0 ;
}
int
F_41 (
struct V_6 * V_1 ,
T_2 * V_152 ,
int * V_150 ,
void T_3 * V_92 ,
T_14 V_9 )
{
T_6 V_94 = F_31 ( V_1 , * V_152 ) ;
T_8 V_110 = F_32 ( V_1 , * V_152 ) ;
struct V_108 * V_109 = NULL ;
struct V_153 * V_133 = NULL ;
struct V_149 * V_7 ;
int V_154 ;
int V_155 = * V_150 ;
int V_156 = 0 ;
int error = 0 ;
* V_150 = 0 ;
if ( V_94 >= V_1 -> V_3 . V_138 ||
* V_152 != F_29 ( V_1 , V_94 , V_110 ) )
return error ;
V_154 = F_42 ( V_155 , ( int ) ( V_139 / sizeof( * V_7 ) ) ) ;
V_7 = F_5 ( V_154 * sizeof( * V_7 ) , V_21 ) ;
do {
struct V_95 V_143 ;
int V_11 ;
if ( ! V_133 ) {
error = F_34 ( V_1 , NULL , V_94 , & V_133 ) ;
if ( error )
break;
V_109 = F_35 ( V_1 , NULL , V_133 , V_94 ,
V_142 ) ;
error = F_24 ( V_109 , V_110 , V_146 ,
& V_11 ) ;
if ( error )
break;
if ( ! V_11 )
goto V_157;
}
error = F_25 ( V_109 , & V_143 , & V_11 ) ;
if ( error )
break;
if ( ! V_11 )
goto V_157;
V_110 = V_143 . V_103 + V_105 - 1 ;
V_7 [ V_156 ] . V_158 =
F_29 ( V_1 , V_94 , V_143 . V_103 ) ;
V_7 [ V_156 ] . V_159 = V_143 . V_116 - V_143 . V_115 ;
V_7 [ V_156 ] . V_160 = ~ V_143 . V_106 ;
if ( ++ V_156 == V_154 ) {
long V_151 ;
error = V_9 ( V_92 , V_7 , V_156 , & V_151 ) ;
if ( error )
break;
V_92 += V_151 ;
* V_150 += V_156 ;
V_156 = 0 ;
}
if ( ! -- V_155 )
break;
error = F_36 ( V_109 , 0 , & V_11 ) ;
if ( error )
break;
if ( V_11 )
continue;
V_157:
F_38 ( V_109 , V_147 ) ;
V_109 = NULL ;
F_39 ( V_133 ) ;
V_133 = NULL ;
V_110 = 0 ;
V_94 ++ ;
} while ( V_94 < V_1 -> V_3 . V_138 );
if ( ! error ) {
if ( V_156 ) {
long V_151 ;
error = V_9 ( V_92 , V_7 , V_156 , & V_151 ) ;
if ( ! error )
* V_150 += V_156 ;
}
* V_152 = F_29 ( V_1 , V_94 , V_110 ) ;
}
F_12 ( V_7 ) ;
if ( V_109 )
F_38 ( V_109 , ( error ? V_147 :
V_148 ) ) ;
if ( V_133 )
F_39 ( V_133 ) ;
return error ;
}
