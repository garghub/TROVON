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
switch ( V_13 -> V_70 ) {
case V_71 :
V_18 -> V_72 = V_15 -> V_73 . V_74 . V_75 ;
V_18 -> V_76 = V_77 ;
V_18 -> V_78 = 0 ;
break;
case V_79 :
case V_80 :
V_18 -> V_72 = 0 ;
V_18 -> V_76 = V_1 -> V_3 . V_81 ;
V_18 -> V_78 = 0 ;
break;
case V_82 :
case V_83 :
V_18 -> V_72 = 0 ;
V_18 -> V_76 = V_1 -> V_3 . V_81 ;
V_18 -> V_78 = V_13 -> V_84 + V_15 -> V_85 ;
break;
}
F_10 ( V_15 , V_26 ) ;
F_11 ( V_15 ) ;
error = V_9 ( V_7 , V_8 , V_10 , V_18 ) ;
if ( ! error )
* V_11 = V_86 ;
V_27:
F_12 ( V_18 ) ;
return error ;
}
STATIC int
F_13 (
void T_3 * V_87 ,
int V_8 ,
int * V_10 ,
const T_5 * V_7 )
{
if ( V_8 < sizeof( * V_7 ) )
return - V_23 ;
if ( F_14 ( V_87 , V_7 , sizeof( * V_7 ) ) )
return - V_88 ;
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
T_6 V_89 ,
struct V_90 * V_91 )
{
T_7 V_92 ;
struct V_93 V_94 ;
int V_95 ;
int V_96 ;
int V_97 ;
V_92 = F_17 ( V_1 , V_91 -> V_98 ) ;
V_95 = F_18 ( V_1 ) ;
V_96 = V_95 << V_1 -> V_3 . V_99 ;
F_19 ( & V_94 ) ;
for ( V_97 = 0 ; V_97 < V_100 ;
V_97 += V_96 , V_92 += V_95 ) {
if ( F_20 ( V_97 , V_96 ) & ~ V_91 -> V_101 ) {
F_21 ( V_1 , V_89 , V_92 , V_95 ,
& V_102 ) ;
}
}
F_22 ( & V_94 ) ;
}
STATIC int
F_23 (
struct V_103 * V_104 ,
T_8 V_105 ,
int * V_106 ,
struct V_90 * V_91 )
{
int V_107 ;
int V_11 ;
int error = 0 ;
error = F_24 ( V_104 , V_105 , V_108 , & V_11 ) ;
if ( error )
return error ;
if ( ! V_11 ) {
* V_106 = 0 ;
return error ;
}
error = F_25 ( V_104 , V_91 , & V_11 ) ;
if ( error )
return error ;
F_26 ( V_104 -> V_109 , V_11 == 1 ) ;
if ( V_91 -> V_98 + V_100 <= V_105 ) {
* V_106 = 0 ;
return 0 ;
}
V_107 = V_105 - V_91 -> V_98 + 1 ;
if ( V_107 < V_100 &&
( F_20 ( V_107 , V_100 - V_107 ) & ~ V_91 -> V_101 ) ) {
int V_97 ;
for ( V_97 = 0 ; V_97 < V_107 ; V_97 ++ ) {
if ( F_27 ( V_97 ) & ~ V_91 -> V_101 )
V_91 -> V_110 ++ ;
}
V_91 -> V_101 |= F_20 ( 0 , V_107 ) ;
* V_106 = V_91 -> V_111 - V_91 -> V_110 ;
}
return 0 ;
}
static int
F_28 (
struct V_6 * V_1 ,
T_6 V_89 ,
struct V_90 * V_112 ,
T_9 V_9 ,
T_10 V_113 ,
struct V_114 * V_115 ,
T_8 * V_116 )
{
char T_3 * * V_117 = V_115 -> V_118 ;
int V_119 ;
int error = 0 ;
T_8 V_105 = V_112 -> V_98 ;
for ( V_119 = 0 ; V_119 < V_100 ;
V_119 ++ , V_105 ++ ) {
int V_120 ;
int V_10 ;
if ( V_115 -> V_121 < V_113 )
break;
if ( F_27 ( V_119 ) & V_112 -> V_101 )
continue;
V_10 = V_113 ;
error = V_9 ( V_1 , F_29 ( V_1 , V_89 , V_105 ) ,
* V_117 , V_115 -> V_121 , & V_10 , & V_120 ) ;
if ( V_120 == V_122 ||
( error && error != - V_123 && error != - V_20 ) ) {
V_115 -> V_121 = 0 ;
ASSERT ( error ) ;
break;
}
if ( V_120 == V_19 || error ) {
error = 0 ;
continue;
}
* V_117 += V_10 ;
V_115 -> V_121 -= V_10 ;
V_115 -> V_124 ++ ;
}
* V_116 = V_105 - 1 ;
return error ;
}
int
F_30 (
T_1 * V_1 ,
T_2 * V_125 ,
int * V_126 ,
T_9 V_9 ,
T_10 V_113 ,
char T_3 * V_87 ,
int * V_127 )
{
T_11 * V_128 ;
T_8 V_105 ;
T_6 V_89 ;
T_12 * V_104 ;
T_10 V_129 ;
T_13 * V_130 ;
int V_131 ;
int V_132 ;
struct V_114 V_133 ;
int error = 0 ;
V_89 = F_31 ( V_1 , * V_125 ) ;
V_105 = F_32 ( V_1 , * V_125 ) ;
if ( V_89 >= V_1 -> V_3 . V_134 ||
* V_125 != F_29 ( V_1 , V_89 , V_105 ) ) {
* V_127 = 1 ;
* V_126 = 0 ;
return 0 ;
}
V_132 = * V_126 ;
V_133 . V_118 = & V_87 ;
V_133 . V_121 = V_132 * V_113 ; ;
V_133 . V_124 = 0 ;
* V_126 = 0 ;
* V_127 = 0 ;
V_130 = F_33 ( & V_129 , V_135 , V_135 * 4 ) ;
if ( ! V_130 )
return - V_23 ;
V_131 = V_129 / sizeof( * V_130 ) ;
while ( V_89 < V_1 -> V_3 . V_134 ) {
struct V_90 * V_112 = V_130 ;
struct V_90 * V_136 = V_130 + V_131 ;
bool V_137 = false ;
int V_106 = 0 ;
int V_11 ;
error = F_34 ( V_1 , NULL , V_89 , & V_128 ) ;
if ( error )
break;
V_104 = F_35 ( V_1 , NULL , V_128 , V_89 ,
V_138 ) ;
if ( V_105 > 0 ) {
struct V_90 V_139 ;
error = F_23 ( V_104 , V_105 , & V_106 , & V_139 ) ;
if ( error )
goto V_140;
if ( V_106 ) {
V_112 -> V_98 = V_139 . V_98 ;
V_112 -> V_141 = V_139 . V_141 ;
V_112 -> V_111 = V_139 . V_111 ;
V_112 -> V_110 = V_139 . V_110 ;
V_112 -> V_101 = V_139 . V_101 ;
V_112 ++ ;
}
error = F_36 ( V_104 , 0 , & V_11 ) ;
} else {
error = F_24 ( V_104 , 0 , V_142 , & V_11 ) ;
}
if ( error || V_11 == 0 ) {
V_137 = true ;
goto V_140;
}
while ( V_112 < V_136 && V_106 < V_132 ) {
struct V_90 V_139 ;
error = F_25 ( V_104 , & V_139 , & V_11 ) ;
if ( error || V_11 == 0 ) {
V_137 = true ;
goto V_140;
}
if ( V_139 . V_110 < V_139 . V_111 ) {
F_16 ( V_1 , V_89 , & V_139 ) ;
V_112 -> V_98 = V_139 . V_98 ;
V_112 -> V_141 = V_139 . V_141 ;
V_112 -> V_111 = V_139 . V_111 ;
V_112 -> V_110 = V_139 . V_110 ;
V_112 -> V_101 = V_139 . V_101 ;
V_112 ++ ;
V_106 += V_139 . V_111 - V_139 . V_110 ;
}
error = F_36 ( V_104 , 0 , & V_11 ) ;
if ( error || V_11 == 0 ) {
V_137 = true ;
goto V_140;
}
F_37 () ;
}
V_140:
F_38 ( V_104 , error ?
V_143 : V_144 ) ;
F_39 ( V_128 ) ;
if ( error )
break;
V_136 = V_112 ;
for ( V_112 = V_130 ;
V_112 < V_136 && V_133 . V_121 >= V_113 ;
V_112 ++ ) {
error = F_28 ( V_1 , V_89 , V_112 ,
V_9 , V_113 , & V_133 ,
& V_105 ) ;
if ( error )
break;
F_37 () ;
}
if ( V_133 . V_121 < V_113 || error )
break;
if ( V_137 ) {
V_89 ++ ;
V_105 = 0 ;
}
}
F_12 ( V_130 ) ;
* V_126 = V_133 . V_124 ;
if ( V_133 . V_124 )
error = 0 ;
* V_125 = F_29 ( V_1 , V_89 , V_105 ) ;
if ( V_89 >= V_1 -> V_3 . V_134 )
* V_127 = 1 ;
return error ;
}
int
F_40 (
void T_3 * V_87 ,
const struct V_145 * V_7 ,
long V_146 ,
long * V_147 )
{
if ( F_14 ( V_87 , V_7 , V_146 * sizeof( * V_7 ) ) )
return - V_88 ;
* V_147 = V_146 * sizeof( * V_7 ) ;
return 0 ;
}
int
F_41 (
struct V_6 * V_1 ,
T_2 * V_148 ,
int * V_146 ,
void T_3 * V_87 ,
T_14 V_9 )
{
T_6 V_89 = F_31 ( V_1 , * V_148 ) ;
T_8 V_105 = F_32 ( V_1 , * V_148 ) ;
struct V_103 * V_104 = NULL ;
struct V_149 * V_128 = NULL ;
struct V_145 * V_7 ;
int V_150 ;
int V_151 = * V_146 ;
int V_152 = 0 ;
int error = 0 ;
* V_146 = 0 ;
if ( V_89 >= V_1 -> V_3 . V_134 ||
* V_148 != F_29 ( V_1 , V_89 , V_105 ) )
return error ;
V_150 = F_42 ( V_151 , ( int ) ( V_135 / sizeof( * V_7 ) ) ) ;
V_7 = F_5 ( V_150 * sizeof( * V_7 ) , V_21 ) ;
do {
struct V_90 V_139 ;
int V_11 ;
if ( ! V_128 ) {
error = F_34 ( V_1 , NULL , V_89 , & V_128 ) ;
if ( error )
break;
V_104 = F_35 ( V_1 , NULL , V_128 , V_89 ,
V_138 ) ;
error = F_24 ( V_104 , V_105 , V_142 ,
& V_11 ) ;
if ( error )
break;
if ( ! V_11 )
goto V_153;
}
error = F_25 ( V_104 , & V_139 , & V_11 ) ;
if ( error )
break;
if ( ! V_11 )
goto V_153;
V_105 = V_139 . V_98 + V_100 - 1 ;
V_7 [ V_152 ] . V_154 =
F_29 ( V_1 , V_89 , V_139 . V_98 ) ;
V_7 [ V_152 ] . V_155 = V_139 . V_111 - V_139 . V_110 ;
V_7 [ V_152 ] . V_156 = ~ V_139 . V_101 ;
if ( ++ V_152 == V_150 ) {
long V_147 ;
error = V_9 ( V_87 , V_7 , V_152 , & V_147 ) ;
if ( error )
break;
V_87 += V_147 ;
* V_146 += V_152 ;
V_152 = 0 ;
}
if ( ! -- V_151 )
break;
error = F_36 ( V_104 , 0 , & V_11 ) ;
if ( error )
break;
if ( V_11 )
continue;
V_153:
F_38 ( V_104 , V_143 ) ;
V_104 = NULL ;
F_39 ( V_128 ) ;
V_128 = NULL ;
V_105 = 0 ;
V_89 ++ ;
} while ( V_89 < V_1 -> V_3 . V_134 );
if ( ! error ) {
if ( V_152 ) {
long V_147 ;
error = V_9 ( V_87 , V_7 , V_152 , & V_147 ) ;
if ( ! error )
* V_146 += V_152 ;
}
* V_148 = F_29 ( V_1 , V_89 , V_105 ) ;
}
F_12 ( V_7 ) ;
if ( V_104 )
F_38 ( V_104 , ( error ? V_143 :
V_144 ) ) ;
if ( V_128 )
F_39 ( V_128 ) ;
return error ;
}
