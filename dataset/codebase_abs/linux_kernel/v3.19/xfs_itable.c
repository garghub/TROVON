STATIC int
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
struct V_16 * V_17 ;
int error = 0 ;
* V_11 = V_18 ;
if ( ! V_7 || F_1 ( V_1 , V_2 ) )
return - V_19 ;
V_17 = F_5 ( sizeof( * V_17 ) , V_20 | V_21 ) ;
if ( ! V_17 )
return - V_22 ;
error = F_6 ( V_1 , NULL , V_2 ,
( V_23 | V_24 ) ,
V_25 , & V_15 ) ;
if ( error )
goto V_26;
ASSERT ( V_15 != NULL ) ;
ASSERT ( V_15 -> V_27 . V_28 != 0 ) ;
V_13 = & V_15 -> V_29 ;
V_17 -> V_30 = V_13 -> V_31 ;
V_17 -> V_32 = V_13 -> V_33 ;
V_17 -> V_34 = V_13 -> V_35 ;
V_17 -> V_36 = V_2 ;
V_17 -> V_37 = V_13 -> V_38 ;
V_17 -> V_39 = V_13 -> V_40 ;
V_17 -> V_41 = V_13 -> V_42 ;
V_17 -> V_43 = V_13 -> V_44 ;
V_17 -> V_45 . V_46 = V_13 -> V_47 . V_48 ;
V_17 -> V_45 . V_49 = V_13 -> V_47 . V_50 ;
V_17 -> V_51 . V_46 = V_13 -> V_52 . V_48 ;
V_17 -> V_51 . V_49 = V_13 -> V_52 . V_50 ;
V_17 -> V_53 . V_46 = V_13 -> V_54 . V_48 ;
V_17 -> V_53 . V_49 = V_13 -> V_54 . V_50 ;
V_17 -> V_55 = F_7 ( V_15 ) ;
V_17 -> V_56 = V_13 -> V_57 << V_1 -> V_3 . V_58 ;
V_17 -> V_59 = V_13 -> V_60 ;
V_17 -> V_61 = V_13 -> V_62 ;
memset ( V_17 -> V_63 , 0 , sizeof( V_17 -> V_63 ) ) ;
V_17 -> V_64 = V_13 -> V_65 ;
V_17 -> V_66 = V_13 -> V_67 ;
V_17 -> V_68 = V_13 -> V_69 ;
V_17 -> V_70 = F_8 ( V_15 ) ;
switch ( V_13 -> V_71 ) {
case V_72 :
V_17 -> V_73 = V_15 -> V_74 . V_75 . V_76 ;
V_17 -> V_77 = V_78 ;
V_17 -> V_79 = 0 ;
break;
case V_80 :
case V_81 :
V_17 -> V_73 = 0 ;
V_17 -> V_77 = V_1 -> V_3 . V_82 ;
V_17 -> V_79 = 0 ;
break;
case V_83 :
case V_84 :
V_17 -> V_73 = 0 ;
V_17 -> V_77 = V_1 -> V_3 . V_82 ;
V_17 -> V_79 = V_13 -> V_85 + V_15 -> V_86 ;
break;
}
F_9 ( V_15 , V_25 ) ;
F_10 ( V_15 ) ;
error = V_9 ( V_7 , V_8 , V_10 , V_17 ) ;
if ( ! error )
* V_11 = V_87 ;
V_26:
F_11 ( V_17 ) ;
return error ;
}
STATIC int
F_12 (
void T_3 * V_88 ,
int V_8 ,
int * V_10 ,
const T_5 * V_7 )
{
if ( V_8 < sizeof( * V_7 ) )
return - V_22 ;
if ( F_13 ( V_88 , V_7 , sizeof( * V_7 ) ) )
return - V_89 ;
if ( V_10 )
* V_10 = sizeof( * V_7 ) ;
return 0 ;
}
int
F_14 (
T_1 * V_1 ,
T_2 V_2 ,
void T_3 * V_7 ,
int V_8 ,
int * V_10 ,
int * V_11 )
{
return F_4 ( V_1 , V_2 , V_7 , V_8 ,
F_12 , V_10 , V_11 ) ;
}
STATIC void
F_15 (
struct V_6 * V_1 ,
T_6 V_90 ,
struct V_91 * V_92 )
{
T_7 V_93 ;
struct V_94 V_95 ;
int V_96 ;
int V_97 ;
int V_98 ;
V_93 = F_16 ( V_1 , V_92 -> V_99 ) ;
V_96 = F_17 ( V_1 ) ;
V_97 = V_96 << V_1 -> V_3 . V_100 ;
F_18 ( & V_95 ) ;
for ( V_98 = 0 ; V_98 < V_101 ;
V_98 += V_97 , V_93 += V_96 ) {
if ( F_19 ( V_98 , V_97 ) & ~ V_92 -> V_102 ) {
F_20 ( V_1 , V_90 , V_93 , V_96 ,
& V_103 ) ;
}
}
F_21 ( & V_95 ) ;
}
STATIC int
F_22 (
struct V_104 * V_105 ,
T_8 V_106 ,
int * V_107 ,
struct V_91 * V_92 )
{
int V_108 ;
int V_11 ;
int error = 0 ;
error = F_23 ( V_105 , V_106 , V_109 , & V_11 ) ;
if ( error )
return error ;
if ( ! V_11 ) {
* V_107 = 0 ;
return error ;
}
error = F_24 ( V_105 , V_92 , & V_11 ) ;
if ( error )
return error ;
F_25 ( V_11 == 1 ) ;
if ( V_92 -> V_99 + V_101 <= V_106 ) {
* V_107 = 0 ;
return 0 ;
}
V_108 = V_106 - V_92 -> V_99 + 1 ;
if ( V_108 < V_101 &&
( F_19 ( V_108 , V_101 - V_108 ) & ~ V_92 -> V_102 ) ) {
int V_98 ;
for ( V_98 = 0 ; V_98 < V_108 ; V_98 ++ ) {
if ( F_26 ( V_98 ) & ~ V_92 -> V_102 )
V_92 -> V_110 ++ ;
}
V_92 -> V_102 |= F_19 ( 0 , V_108 ) ;
* V_107 = V_101 - V_92 -> V_110 ;
}
return 0 ;
}
static int
F_27 (
struct V_6 * V_1 ,
T_6 V_90 ,
struct V_91 * V_111 ,
T_9 V_9 ,
T_10 V_112 ,
struct V_113 * V_114 ,
T_8 * V_115 )
{
char T_3 * * V_116 = V_114 -> V_117 ;
int V_118 ;
int error = 0 ;
T_8 V_106 = V_111 -> V_99 ;
for ( V_118 = 0 ; V_118 < V_101 ;
V_118 ++ , V_106 ++ ) {
int V_119 ;
int V_10 ;
if ( V_114 -> V_120 < V_112 )
break;
if ( F_26 ( V_118 ) & V_111 -> V_102 )
continue;
V_10 = V_112 ;
error = V_9 ( V_1 , F_28 ( V_1 , V_90 , V_106 ) ,
* V_116 , V_114 -> V_120 , & V_10 , & V_119 ) ;
if ( V_119 == V_121 ||
( error && error != - V_122 && error != - V_19 ) ) {
V_114 -> V_120 = 0 ;
ASSERT ( error ) ;
break;
}
if ( V_119 == V_18 || error ) {
error = 0 ;
continue;
}
* V_116 += V_10 ;
V_114 -> V_120 -= V_10 ;
V_114 -> V_123 ++ ;
}
* V_115 = V_106 - 1 ;
return error ;
}
int
F_29 (
T_1 * V_1 ,
T_2 * V_124 ,
int * V_125 ,
T_9 V_9 ,
T_10 V_112 ,
char T_3 * V_88 ,
int * V_126 )
{
T_11 * V_127 ;
T_8 V_106 ;
T_6 V_90 ;
T_12 * V_105 ;
T_10 V_128 ;
T_13 * V_129 ;
int V_130 ;
int V_131 ;
struct V_113 V_132 ;
int error = 0 ;
V_90 = F_30 ( V_1 , * V_124 ) ;
V_106 = F_31 ( V_1 , * V_124 ) ;
if ( V_90 >= V_1 -> V_3 . V_133 ||
* V_124 != F_28 ( V_1 , V_90 , V_106 ) ) {
* V_126 = 1 ;
* V_125 = 0 ;
return 0 ;
}
V_131 = * V_125 ;
V_132 . V_117 = & V_88 ;
V_132 . V_120 = V_131 * V_112 ; ;
V_132 . V_123 = 0 ;
* V_125 = 0 ;
* V_126 = 0 ;
V_129 = F_32 ( & V_128 , V_134 , V_134 * 4 ) ;
if ( ! V_129 )
return - V_22 ;
V_130 = V_128 / sizeof( * V_129 ) ;
while ( V_90 < V_1 -> V_3 . V_133 ) {
struct V_91 * V_111 = V_129 ;
struct V_91 * V_135 = V_129 + V_130 ;
bool V_136 = false ;
int V_107 = 0 ;
int V_11 ;
error = F_33 ( V_1 , NULL , V_90 , & V_127 ) ;
if ( error )
break;
V_105 = F_34 ( V_1 , NULL , V_127 , V_90 ,
V_137 ) ;
if ( V_106 > 0 ) {
struct V_91 V_138 ;
error = F_22 ( V_105 , V_106 , & V_107 , & V_138 ) ;
if ( error )
goto V_139;
if ( V_107 ) {
V_111 -> V_99 = V_138 . V_99 ;
V_111 -> V_110 = V_138 . V_110 ;
V_111 -> V_102 = V_138 . V_102 ;
V_111 ++ ;
}
error = F_35 ( V_105 , 0 , & V_11 ) ;
} else {
error = F_23 ( V_105 , 0 , V_140 , & V_11 ) ;
}
if ( error || V_11 == 0 ) {
V_136 = true ;
goto V_139;
}
while ( V_111 < V_135 && V_107 < V_131 ) {
struct V_91 V_138 ;
error = F_24 ( V_105 , & V_138 , & V_11 ) ;
if ( error || V_11 == 0 ) {
V_136 = true ;
goto V_139;
}
if ( V_138 . V_110 < V_101 ) {
F_15 ( V_1 , V_90 , & V_138 ) ;
V_111 -> V_99 = V_138 . V_99 ;
V_111 -> V_110 = V_138 . V_110 ;
V_111 -> V_102 = V_138 . V_102 ;
V_111 ++ ;
V_107 += V_101 - V_138 . V_110 ;
}
error = F_35 ( V_105 , 0 , & V_11 ) ;
if ( error || V_11 == 0 ) {
V_136 = true ;
goto V_139;
}
F_36 () ;
}
V_139:
F_37 ( V_105 , V_141 ) ;
F_38 ( V_127 ) ;
if ( error )
break;
V_135 = V_111 ;
for ( V_111 = V_129 ;
V_111 < V_135 && V_132 . V_120 >= V_112 ;
V_111 ++ ) {
error = F_27 ( V_1 , V_90 , V_111 ,
V_9 , V_112 , & V_132 ,
& V_106 ) ;
if ( error )
break;
F_36 () ;
}
if ( V_132 . V_120 < V_112 || error )
break;
if ( V_136 ) {
V_90 ++ ;
V_106 = 0 ;
}
}
F_11 ( V_129 ) ;
* V_125 = V_132 . V_123 ;
if ( V_132 . V_123 )
error = 0 ;
* V_124 = F_28 ( V_1 , V_90 , V_106 ) ;
if ( V_90 >= V_1 -> V_3 . V_133 )
* V_126 = 1 ;
return error ;
}
int
F_39 (
void T_3 * V_88 ,
const struct V_142 * V_7 ,
long V_143 ,
long * V_144 )
{
if ( F_13 ( V_88 , V_7 , V_143 * sizeof( * V_7 ) ) )
return - V_89 ;
* V_144 = V_143 * sizeof( * V_7 ) ;
return 0 ;
}
int
F_40 (
struct V_6 * V_1 ,
T_2 * V_145 ,
int * V_143 ,
void T_3 * V_88 ,
T_14 V_9 )
{
T_6 V_90 = F_30 ( V_1 , * V_145 ) ;
T_8 V_106 = F_31 ( V_1 , * V_145 ) ;
struct V_104 * V_105 = NULL ;
struct V_146 * V_127 = NULL ;
struct V_142 * V_7 ;
int V_147 ;
int V_148 = * V_143 ;
int V_149 = 0 ;
int error = 0 ;
* V_143 = 0 ;
if ( V_90 >= V_1 -> V_3 . V_133 ||
* V_145 != F_28 ( V_1 , V_90 , V_106 ) )
return error ;
V_147 = F_41 ( V_148 , ( int ) ( V_134 / sizeof( * V_7 ) ) ) ;
V_7 = F_5 ( V_147 * sizeof( * V_7 ) , V_20 ) ;
do {
struct V_91 V_138 ;
int V_11 ;
if ( ! V_127 ) {
error = F_33 ( V_1 , NULL , V_90 , & V_127 ) ;
if ( error )
break;
V_105 = F_34 ( V_1 , NULL , V_127 , V_90 ,
V_137 ) ;
error = F_23 ( V_105 , V_106 , V_140 ,
& V_11 ) ;
if ( error )
break;
if ( ! V_11 )
goto V_150;
}
error = F_24 ( V_105 , & V_138 , & V_11 ) ;
if ( error )
break;
if ( ! V_11 )
goto V_150;
V_106 = V_138 . V_99 + V_101 - 1 ;
V_7 [ V_149 ] . V_151 =
F_28 ( V_1 , V_90 , V_138 . V_99 ) ;
V_7 [ V_149 ] . V_152 =
V_101 - V_138 . V_110 ;
V_7 [ V_149 ] . V_153 = ~ V_138 . V_102 ;
if ( ++ V_149 == V_147 ) {
long V_144 ;
error = V_9 ( V_88 , V_7 , V_149 , & V_144 ) ;
if ( error )
break;
V_88 += V_144 ;
* V_143 += V_149 ;
V_149 = 0 ;
}
if ( ! -- V_148 )
break;
error = F_35 ( V_105 , 0 , & V_11 ) ;
if ( error )
break;
if ( V_11 )
continue;
V_150:
F_37 ( V_105 , V_154 ) ;
V_105 = NULL ;
F_38 ( V_127 ) ;
V_127 = NULL ;
V_106 = 0 ;
V_90 ++ ;
} while ( V_90 < V_1 -> V_3 . V_133 );
if ( ! error ) {
if ( V_149 ) {
long V_144 ;
error = V_9 ( V_88 , V_7 , V_149 , & V_144 ) ;
if ( ! error )
* V_143 += V_149 ;
}
* V_145 = F_28 ( V_1 , V_90 , V_106 ) ;
}
F_11 ( V_7 ) ;
if ( V_105 )
F_37 ( V_105 , ( error ? V_154 :
V_141 ) ) ;
if ( V_127 )
F_38 ( V_127 ) ;
return error ;
}
