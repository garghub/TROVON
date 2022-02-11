static inline int
F_1 (
struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) &&
V_2 -> V_3 . V_4 >=
F_3 ( V_2 , V_2 -> V_5 ) )
return V_2 -> V_3 . V_4 ;
return 1 ;
}
int
F_4 (
struct V_6 * V_7 ,
T_1 V_8 ,
T_2 V_9 ,
int * V_10 )
{
V_7 -> V_11 . V_12 . V_13 = V_8 ;
V_7 -> V_11 . V_12 . V_14 = 0 ;
V_7 -> V_11 . V_12 . V_15 = 0 ;
V_7 -> V_11 . V_12 . V_16 = 0 ;
V_7 -> V_11 . V_12 . V_17 = 0 ;
return F_5 ( V_7 , V_9 , V_10 ) ;
}
STATIC int
F_6 (
struct V_6 * V_7 ,
T_3 * V_18 )
{
union V_19 V_20 ;
V_20 . V_21 . V_13 = F_7 ( V_18 -> V_13 ) ;
if ( F_8 ( & V_7 -> V_22 -> V_3 ) ) {
V_20 . V_21 . V_23 . V_24 . V_14 = F_9 ( V_18 -> V_14 ) ;
V_20 . V_21 . V_23 . V_24 . V_15 = V_18 -> V_15 ;
V_20 . V_21 . V_23 . V_24 . V_16 = V_18 -> V_16 ;
} else {
V_20 . V_21 . V_23 . V_25 . V_16 = F_7 ( V_18 -> V_16 ) ;
}
V_20 . V_21 . V_17 = F_10 ( V_18 -> V_17 ) ;
return F_11 ( V_7 , & V_20 ) ;
}
int
F_12 (
struct V_6 * V_7 ,
T_3 * V_18 ,
int * V_10 )
{
union V_19 * V_20 ;
int error ;
error = F_13 ( V_7 , & V_20 , V_10 ) ;
if ( error || * V_10 == 0 )
return error ;
V_18 -> V_13 = F_14 ( V_20 -> V_21 . V_13 ) ;
if ( F_8 ( & V_7 -> V_22 -> V_3 ) ) {
V_18 -> V_14 = F_15 ( V_20 -> V_21 . V_23 . V_24 . V_14 ) ;
V_18 -> V_15 = V_20 -> V_21 . V_23 . V_24 . V_15 ;
V_18 -> V_16 = V_20 -> V_21 . V_23 . V_24 . V_16 ;
} else {
V_18 -> V_14 = V_26 ;
V_18 -> V_15 = V_27 ;
V_18 -> V_16 =
F_14 ( V_20 -> V_21 . V_23 . V_25 . V_16 ) ;
}
V_18 -> V_17 = F_16 ( V_20 -> V_21 . V_17 ) ;
return 0 ;
}
STATIC int
F_17 (
struct V_6 * V_7 ,
T_4 V_28 ,
T_5 V_29 ,
T_6 V_30 ,
T_7 free ,
int * V_10 )
{
V_7 -> V_11 . V_12 . V_14 = V_28 ;
V_7 -> V_11 . V_12 . V_15 = V_29 ;
V_7 -> V_11 . V_12 . V_16 = V_30 ;
V_7 -> V_11 . V_12 . V_17 = free ;
return F_18 ( V_7 , V_10 ) ;
}
STATIC int
F_19 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_1 V_35 ,
T_1 V_36 ,
T_8 V_37 )
{
struct V_6 * V_7 ;
struct V_38 * V_39 = F_20 ( V_34 ) ;
T_9 V_40 = F_14 ( V_39 -> V_41 ) ;
T_1 V_42 ;
int V_12 ;
int error ;
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_37 ) ;
for ( V_42 = V_35 ;
V_42 < V_35 + V_36 ;
V_42 += V_27 ) {
error = F_4 ( V_7 , V_42 , V_43 , & V_12 ) ;
if ( error ) {
F_22 ( V_7 , V_44 ) ;
return error ;
}
ASSERT ( V_12 == 0 ) ;
error = F_17 ( V_7 , V_26 ,
V_27 ,
V_27 ,
V_45 , & V_12 ) ;
if ( error ) {
F_22 ( V_7 , V_44 ) ;
return error ;
}
ASSERT ( V_12 == 1 ) ;
}
F_22 ( V_7 , V_46 ) ;
return 0 ;
}
STATIC int
F_23 (
struct V_6 * V_7 ,
struct V_38 * V_39 )
{
if ( V_7 -> V_47 == 1 ) {
T_3 V_20 ;
int V_30 = 0 ;
int error ;
int V_12 ;
error = F_4 ( V_7 , 0 , V_48 , & V_12 ) ;
if ( error )
return error ;
do {
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( error )
return error ;
if ( V_12 ) {
V_30 += V_20 . V_16 ;
error = F_24 ( V_7 , 0 , & V_12 ) ;
if ( error )
return error ;
}
} while ( V_12 == 1 );
if ( ! F_25 ( V_7 -> V_22 ) )
ASSERT ( V_30 == F_14 ( V_39 -> V_49 ) ) ;
}
return 0 ;
}
int
F_26 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_50 * V_51 ,
int V_52 ,
T_9 V_40 ,
T_10 V_53 ,
T_10 V_54 ,
unsigned int V_55 )
{
struct V_33 * V_56 ;
struct V_57 * free ;
int V_58 , V_59 , V_60 ;
int V_61 ;
int V_12 , V_62 ;
T_11 V_63 ;
T_12 V_8 = 0 ;
V_59 = F_27 ( V_2 ) ;
V_60 = V_59 << V_2 -> V_3 . V_64 ;
V_58 = V_54 / V_59 ;
if ( F_28 ( & V_2 -> V_3 ) ) {
V_61 = 3 ;
V_8 = F_29 ( V_2 , V_40 ,
F_30 ( V_2 , V_53 , 0 ) ) ;
if ( V_32 )
F_31 ( V_32 , V_40 , V_53 , V_52 ,
V_2 -> V_3 . V_65 , V_54 , V_55 ) ;
} else
V_61 = 2 ;
for ( V_62 = 0 ; V_62 < V_58 ; V_62 ++ ) {
V_63 = F_32 ( V_2 , V_40 , V_53 + ( V_62 * V_59 ) ) ;
V_56 = F_33 ( V_32 , V_2 -> V_66 , V_63 ,
V_2 -> V_67 * V_59 ,
V_68 ) ;
if ( ! V_56 )
return - V_69 ;
V_56 -> V_70 = & V_71 ;
F_34 ( V_56 , 0 , F_35 ( V_56 -> V_72 ) ) ;
for ( V_12 = 0 ; V_12 < V_60 ; V_12 ++ ) {
int V_73 = V_12 << V_2 -> V_3 . V_74 ;
T_13 V_75 = F_36 ( V_61 ) ;
free = F_37 ( V_2 , V_56 , V_12 ) ;
free -> V_76 = F_9 ( V_77 ) ;
free -> V_78 = V_61 ;
free -> V_79 = F_7 ( V_55 ) ;
free -> V_80 = F_7 ( V_81 ) ;
if ( V_61 == 3 ) {
free -> V_82 = F_10 ( V_8 ) ;
V_8 ++ ;
F_38 ( & free -> V_83 ,
& V_2 -> V_3 . V_84 ) ;
F_39 ( V_2 , free ) ;
} else if ( V_32 ) {
F_40 ( V_32 , V_56 , V_73 ,
V_73 + V_75 - 1 ) ;
}
}
if ( V_32 ) {
F_41 ( V_32 , V_56 ) ;
if ( V_61 == 3 ) {
F_42 ( V_32 , V_56 ) ;
F_40 ( V_32 , V_56 , 0 ,
F_35 ( V_56 -> V_72 ) - 1 ) ;
}
} else {
V_56 -> V_85 |= V_86 ;
F_43 ( V_56 , V_51 ) ;
F_44 ( V_56 ) ;
}
}
return 0 ;
}
STATIC void
F_45 (
struct V_1 * V_2 ,
T_1 * V_87 ,
T_14 * V_88 )
{
T_10 V_53 ;
T_10 V_89 ;
int V_90 ;
V_53 = F_46 ( V_2 , * V_87 ) ;
V_89 = V_53 % V_2 -> V_3 . V_4 ;
if ( ! V_89 )
return;
V_90 = V_89 << V_2 -> V_3 . V_64 ;
* V_87 -= V_90 ;
* V_88 <<= V_90 / V_91 ;
}
STATIC bool
F_47 (
struct V_92 * V_93 ,
struct V_92 * V_94 )
{
T_15 V_95 ;
T_15 V_96 ;
if ( V_93 -> V_13 != V_94 -> V_13 )
return false ;
if ( ! F_48 ( V_93 -> V_14 ) ||
! F_48 ( V_94 -> V_14 ) )
return false ;
if ( ! V_93 -> V_15 || ! V_94 -> V_15 )
return false ;
if ( V_93 -> V_15 + V_94 -> V_15 > V_27 )
return false ;
V_95 = F_49 ( V_93 ) ;
V_96 = F_49 ( V_94 ) ;
if ( V_95 & V_96 )
return false ;
return true ;
}
STATIC void
F_50 (
struct V_92 * V_93 ,
struct V_92 * V_94 )
{
ASSERT ( V_93 -> V_13 == V_94 -> V_13 ) ;
V_93 -> V_15 += V_94 -> V_15 ;
V_93 -> V_16 += V_94 -> V_16 ;
V_93 -> V_14 &= V_94 -> V_14 ;
V_93 -> V_17 &= V_94 -> V_17 ;
}
STATIC int
F_51 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
int V_37 ,
struct V_92 * V_97 ,
bool V_98 )
{
struct V_6 * V_7 ;
struct V_38 * V_39 = F_20 ( V_34 ) ;
T_9 V_40 = F_14 ( V_39 -> V_41 ) ;
int error ;
int V_12 ;
struct V_92 V_20 ;
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_37 ) ;
error = F_4 ( V_7 , V_97 -> V_13 , V_43 , & V_12 ) ;
if ( error )
goto error;
if ( V_12 == 0 ) {
error = F_17 ( V_7 , V_97 -> V_14 ,
V_97 -> V_15 , V_97 -> V_16 ,
V_97 -> V_17 , & V_12 ) ;
if ( error )
goto error;
F_52 ( V_2 , V_12 == 1 , error ) ;
goto V_99;
}
if ( V_98 ) {
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( error )
goto error;
F_52 ( V_2 , V_12 == 1 , error ) ;
F_52 ( V_2 ,
V_20 . V_13 == V_97 -> V_13 ,
error ) ;
F_52 ( V_2 , F_47 ( V_97 , & V_20 ) ,
error ) ;
F_53 ( V_2 , V_40 , V_20 . V_13 ,
V_20 . V_14 , V_97 -> V_13 ,
V_97 -> V_14 ) ;
F_50 ( V_97 , & V_20 ) ;
F_54 ( V_2 , V_40 , V_97 -> V_13 ,
V_97 -> V_14 ) ;
error = F_55 ( V_2 , V_97 ) ;
if ( error )
goto error;
}
error = F_6 ( V_7 , V_97 ) ;
if ( error )
goto error;
V_99:
F_22 ( V_7 , V_46 ) ;
return 0 ;
error:
F_22 ( V_7 , V_44 ) ;
return error ;
}
STATIC int
F_56 (
T_16 * V_32 ,
T_17 * V_34 ,
int * V_100 )
{
T_18 * V_39 ;
T_19 args ;
T_9 V_40 ;
int error ;
T_1 V_35 ;
T_1 V_36 ;
int V_101 = 0 ;
T_14 V_88 = ( T_14 ) - 1 ;
struct V_92 V_20 ;
struct V_102 * V_103 ;
int V_104 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_32 = V_32 ;
args . V_2 = V_32 -> V_105 ;
args . V_106 = V_107 ;
F_57 ( & args . V_108 , V_109 ) ;
#ifdef F_58
if ( F_8 ( & V_32 -> V_105 -> V_3 ) &&
args . V_2 -> V_110 < args . V_2 -> V_111 )
V_104 = F_59 () & 1 ;
#endif
V_36 = args . V_2 -> V_112 ;
if ( args . V_2 -> V_113 &&
F_60 ( & args . V_2 -> V_114 ) + V_36 >
args . V_2 -> V_113 )
return - V_115 ;
args . V_116 = args . V_117 = args . V_2 -> V_111 ;
V_39 = F_20 ( V_34 ) ;
V_35 = F_14 ( V_39 -> V_118 ) ;
V_40 = F_14 ( V_39 -> V_41 ) ;
args . V_53 = F_46 ( args . V_2 , V_35 ) +
args . V_2 -> V_111 ;
if ( V_104 )
goto V_119;
if ( F_61 ( V_35 != V_81 &&
( args . V_53 < F_14 ( V_39 -> V_120 ) ) ) ) {
args . V_106 = F_62 ( args . V_2 , V_40 , args . V_53 ) ;
args . type = V_121 ;
args . V_122 = 1 ;
args . V_123 = 1 ;
args . V_124 = F_1 ( args . V_2 ) - 1 ;
args . V_125 = args . V_2 -> V_126 - 1 ;
if ( ( error = F_63 ( & args ) ) )
return error ;
args . V_124 = 0 ;
}
if ( F_64 ( args . V_106 == V_107 ) ) {
V_101 = 0 ;
if ( args . V_2 -> V_127 ) {
ASSERT ( ! ( args . V_2 -> V_128 & V_129 ) ) ;
args . V_123 = args . V_2 -> V_130 ;
V_101 = 1 ;
} else
args . V_123 = F_1 ( args . V_2 ) ;
args . V_53 = F_14 ( V_39 -> V_131 ) ;
args . V_106 = F_62 ( args . V_2 , V_40 , args . V_53 ) ;
args . type = V_132 ;
args . V_122 = 1 ;
args . V_125 = args . V_2 -> V_126 - 1 ;
if ( ( error = F_63 ( & args ) ) )
return error ;
}
if ( V_101 && args . V_106 == V_107 ) {
args . type = V_132 ;
args . V_53 = F_14 ( V_39 -> V_131 ) ;
args . V_106 = F_62 ( args . V_2 , V_40 , args . V_53 ) ;
args . V_123 = F_1 ( args . V_2 ) ;
if ( ( error = F_63 ( & args ) ) )
return error ;
}
if ( F_8 ( & args . V_2 -> V_3 ) &&
args . V_2 -> V_110 < args . V_2 -> V_111 &&
args . V_106 == V_107 ) {
V_119:
args . type = V_132 ;
args . V_53 = F_14 ( V_39 -> V_131 ) ;
args . V_106 = F_62 ( args . V_2 , V_40 , args . V_53 ) ;
args . V_123 = args . V_2 -> V_3 . V_133 ;
args . V_122 = 1 ;
args . V_116 = args . V_2 -> V_110 ;
args . V_117 = args . V_116 ;
args . V_134 = args . V_2 -> V_3 . V_4 ;
args . V_135 = F_65 ( args . V_2 -> V_3 . V_136 ,
args . V_2 -> V_3 . V_4 ) -
args . V_2 -> V_111 ;
error = F_63 ( & args ) ;
if ( error )
return error ;
V_36 = args . V_137 << args . V_2 -> V_3 . V_64 ;
ASSERT ( V_36 <= V_27 ) ;
V_88 = ( 1 << ( V_36 / V_91 ) ) - 1 ;
}
if ( args . V_106 == V_107 ) {
* V_100 = 0 ;
return 0 ;
}
ASSERT ( args . V_137 == args . V_116 ) ;
error = F_26 ( args . V_2 , V_32 , NULL , V_36 , V_40 ,
args . V_53 , args . V_137 , F_59 () ) ;
if ( error )
return error ;
V_35 = F_30 ( args . V_2 , args . V_53 , 0 ) ;
if ( F_48 ( ~ V_88 ) ) {
F_45 ( args . V_2 , & V_35 , & V_88 ) ;
V_20 . V_13 = V_35 ;
V_20 . V_14 = ~ V_88 ;
V_20 . V_15 = V_36 ;
V_20 . V_16 = V_36 ;
V_20 . V_17 = V_45 ;
error = F_51 ( args . V_2 , V_32 , V_34 , V_138 ,
& V_20 , true ) ;
if ( error == - V_139 ) {
F_66 ( args . V_2 ,
L_1 ,
F_29 ( args . V_2 , V_40 ,
V_20 . V_13 ) ,
V_20 . V_14 , V_20 . V_15 ) ;
F_67 ( args . V_2 , V_140 ) ;
}
if ( error )
return error ;
if ( F_68 ( & args . V_2 -> V_3 ) ) {
error = F_51 ( args . V_2 , V_32 , V_34 ,
V_141 , & V_20 ,
false ) ;
if ( error )
return error ;
}
} else {
error = F_19 ( args . V_2 , V_32 , V_34 , V_35 , V_36 ,
V_138 ) ;
if ( error )
return error ;
if ( F_68 ( & args . V_2 -> V_3 ) ) {
error = F_19 ( args . V_2 , V_32 , V_34 , V_35 ,
V_36 , V_141 ) ;
if ( error )
return error ;
}
}
F_69 ( & V_39 -> V_142 , V_36 ) ;
F_69 ( & V_39 -> V_49 , V_36 ) ;
V_103 = F_70 ( args . V_2 , V_40 ) ;
V_103 -> V_143 += V_36 ;
F_71 ( V_103 ) ;
V_39 -> V_118 = F_7 ( V_35 ) ;
F_72 ( V_32 , V_34 ,
V_144 | V_145 | V_146 ) ;
F_73 ( V_32 , V_147 , ( long ) V_36 ) ;
F_73 ( V_32 , V_148 , ( long ) V_36 ) ;
* V_100 = 1 ;
return 0 ;
}
STATIC T_9
F_74 (
T_20 * V_2 )
{
T_9 V_40 ;
F_75 ( & V_2 -> V_149 ) ;
V_40 = V_2 -> V_150 ;
if ( ++ V_2 -> V_150 >= V_2 -> V_151 )
V_2 -> V_150 = 0 ;
F_76 ( & V_2 -> V_149 ) ;
return V_40 ;
}
STATIC T_9
F_77 (
T_16 * V_32 ,
T_12 V_152 ,
T_21 V_153 ,
int V_154 )
{
T_9 V_155 ;
T_9 V_40 ;
int V_156 ;
T_22 V_157 ;
T_22 V_158 = 0 ;
T_20 * V_2 ;
int V_159 ;
T_23 * V_103 ;
T_9 V_160 ;
int error ;
V_159 = F_78 ( V_153 ) || F_79 ( V_153 ) || F_80 ( V_153 ) ;
V_2 = V_32 -> V_105 ;
V_155 = V_2 -> V_151 ;
if ( F_78 ( V_153 ) )
V_160 = F_74 ( V_2 ) ;
else {
V_160 = F_81 ( V_2 , V_152 ) ;
if ( V_160 >= V_155 )
V_160 = 0 ;
}
ASSERT ( V_160 < V_155 ) ;
V_40 = V_160 ;
V_156 = V_161 ;
for (; ; ) {
V_103 = F_70 ( V_2 , V_40 ) ;
if ( ! V_103 -> V_162 ) {
F_74 ( V_2 ) ;
goto V_163;
}
if ( ! V_103 -> V_164 ) {
error = F_82 ( V_2 , V_32 , V_40 ) ;
if ( error )
goto V_163;
}
if ( V_103 -> V_143 ) {
F_71 ( V_103 ) ;
return V_40 ;
}
if ( ! V_154 )
goto V_163;
if ( ! V_103 -> V_165 ) {
error = F_83 ( V_2 , V_32 , V_40 , V_156 ) ;
if ( error )
goto V_163;
}
V_157 = V_2 -> V_110 ;
if ( V_156 && V_157 > 1 )
V_157 += F_1 ( V_2 ) ;
V_158 = V_103 -> V_166 ;
if ( ! V_158 )
V_158 = V_103 -> V_167 > 0 ;
if ( V_103 -> V_168 >= V_159 + V_157 &&
V_158 >= V_157 ) {
F_71 ( V_103 ) ;
return V_40 ;
}
V_163:
F_71 ( V_103 ) ;
if ( F_25 ( V_2 ) )
return V_169 ;
V_40 ++ ;
if ( V_40 >= V_155 )
V_40 = 0 ;
if ( V_40 == V_160 ) {
if ( V_156 == 0 )
return V_169 ;
V_156 = 0 ;
}
}
}
STATIC int
F_84 (
struct V_6 * V_7 ,
T_3 * V_20 ,
int * V_170 ,
int V_171 )
{
int error ;
int V_12 ;
if ( V_171 )
error = F_85 ( V_7 , 0 , & V_12 ) ;
else
error = F_24 ( V_7 , 0 , & V_12 ) ;
if ( error )
return error ;
* V_170 = ! V_12 ;
if ( V_12 ) {
error = F_12 ( V_7 , V_20 , & V_12 ) ;
if ( error )
return error ;
F_86 ( V_7 -> V_22 , V_12 == 1 ) ;
}
return 0 ;
}
STATIC int
F_87 (
struct V_6 * V_7 ,
T_1 V_172 ,
T_3 * V_20 ,
int * V_170 )
{
int error ;
int V_12 ;
error = F_4 ( V_7 , V_172 , V_43 , & V_12 ) ;
if ( error )
return error ;
* V_170 = ! V_12 ;
if ( V_12 ) {
error = F_12 ( V_7 , V_20 , & V_12 ) ;
if ( error )
return error ;
F_86 ( V_7 -> V_22 , V_12 == 1 ) ;
}
return 0 ;
}
STATIC int
F_88 (
struct V_92 * V_20 )
{
T_7 V_173 ;
if ( ! F_48 ( V_20 -> V_14 ) )
return F_89 ( V_20 -> V_17 ) ;
V_173 = F_49 ( V_20 ) ;
V_173 &= V_20 -> V_17 ;
return F_89 ( V_173 ) ;
}
STATIC int
F_90 (
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_12 V_152 ,
T_12 * V_174 )
{
struct V_1 * V_2 = V_32 -> V_105 ;
struct V_38 * V_39 = F_20 ( V_34 ) ;
T_9 V_40 = F_14 ( V_39 -> V_41 ) ;
T_9 V_160 = F_81 ( V_2 , V_152 ) ;
T_1 V_175 = F_91 ( V_2 , V_152 ) ;
struct V_102 * V_103 ;
struct V_6 * V_7 , * V_176 ;
struct V_92 V_20 , V_93 ;
T_12 V_8 ;
int error ;
int V_90 ;
int V_12 , V_62 ;
V_103 = F_70 ( V_2 , V_40 ) ;
ASSERT ( V_103 -> V_164 ) ;
ASSERT ( V_103 -> V_162 ) ;
ASSERT ( V_103 -> V_143 > 0 ) ;
V_177:
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_138 ) ;
if ( ! V_175 )
V_175 = F_14 ( V_39 -> V_118 ) ;
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_178;
if ( V_160 == V_40 ) {
int V_179 ;
int V_180 ;
int V_181 = 10 ;
error = F_4 ( V_7 , V_175 , V_182 , & V_12 ) ;
if ( error )
goto V_178;
F_52 ( V_2 , V_12 == 1 , V_178 ) ;
error = F_12 ( V_7 , & V_20 , & V_62 ) ;
if ( error )
goto V_178;
F_52 ( V_2 , V_62 == 1 , V_178 ) ;
if ( V_20 . V_16 > 0 ) {
goto V_183;
}
error = F_92 ( V_7 , & V_176 ) ;
if ( error )
goto V_178;
if ( V_175 != V_81 &&
V_103 -> V_184 == V_175 &&
V_103 -> V_185 != V_81 &&
V_103 -> V_186 != V_81 ) {
error = F_87 ( V_176 , V_103 -> V_185 ,
& V_93 , & V_179 ) ;
if ( error )
goto V_187;
error = F_87 ( V_7 , V_103 -> V_186 ,
& V_20 , & V_180 ) ;
if ( error )
goto V_187;
} else {
error = F_84 ( V_176 , & V_93 , & V_179 , 1 ) ;
if ( error )
goto V_187;
error = F_84 ( V_7 , & V_20 , & V_180 , 0 ) ;
if ( error )
goto V_187;
}
while ( ! V_179 || ! V_180 ) {
int V_188 ;
if ( ! -- V_181 ) {
F_22 ( V_176 , V_46 ) ;
V_103 -> V_185 = V_93 . V_13 ;
V_103 -> V_186 = V_20 . V_13 ;
V_103 -> V_184 = V_175 ;
goto V_35;
}
if ( ! V_179 && ! V_180 ) {
V_188 = V_175 -
( V_93 . V_13 + V_27 - 1 ) <
V_20 . V_13 - V_175 ;
} else {
V_188 = ! V_179 ;
}
if ( V_188 && V_93 . V_16 ) {
V_20 = V_93 ;
F_22 ( V_7 , V_46 ) ;
V_7 = V_176 ;
V_103 -> V_185 = V_93 . V_13 ;
V_103 -> V_186 = V_20 . V_13 ;
V_103 -> V_184 = V_175 ;
goto V_183;
}
if ( ! V_188 && V_20 . V_16 ) {
F_22 ( V_176 , V_46 ) ;
V_103 -> V_185 = V_93 . V_13 ;
V_103 -> V_186 = V_20 . V_13 ;
V_103 -> V_184 = V_175 ;
goto V_183;
}
if ( V_188 ) {
error = F_84 ( V_176 , & V_93 ,
& V_179 , 1 ) ;
} else {
error = F_84 ( V_7 , & V_20 ,
& V_180 , 0 ) ;
}
if ( error )
goto V_187;
}
V_103 -> V_184 = V_81 ;
V_103 -> V_185 = V_81 ;
V_103 -> V_186 = V_81 ;
F_22 ( V_176 , V_46 ) ;
F_22 ( V_7 , V_46 ) ;
goto V_177;
}
V_35:
if ( V_39 -> V_118 != F_7 ( V_81 ) ) {
error = F_4 ( V_7 , F_14 ( V_39 -> V_118 ) ,
V_43 , & V_12 ) ;
if ( error )
goto V_178;
if ( V_12 == 1 ) {
error = F_12 ( V_7 , & V_20 , & V_62 ) ;
if ( error )
goto V_178;
if ( V_62 == 1 && V_20 . V_16 > 0 ) {
goto V_183;
}
}
}
error = F_4 ( V_7 , 0 , V_48 , & V_12 ) ;
if ( error )
goto V_178;
F_52 ( V_2 , V_12 == 1 , V_178 ) ;
for (; ; ) {
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( error )
goto V_178;
F_52 ( V_2 , V_12 == 1 , V_178 ) ;
if ( V_20 . V_16 > 0 )
break;
error = F_24 ( V_7 , 0 , & V_12 ) ;
if ( error )
goto V_178;
F_52 ( V_2 , V_12 == 1 , V_178 ) ;
}
V_183:
V_90 = F_88 ( & V_20 ) ;
ASSERT ( V_90 >= 0 ) ;
ASSERT ( V_90 < V_27 ) ;
ASSERT ( ( F_93 ( V_2 , V_20 . V_13 ) %
V_27 ) == 0 ) ;
V_8 = F_29 ( V_2 , V_40 , V_20 . V_13 + V_90 ) ;
V_20 . V_17 &= ~ F_94 ( V_90 ) ;
V_20 . V_16 -- ;
error = F_6 ( V_7 , & V_20 ) ;
if ( error )
goto V_178;
F_69 ( & V_39 -> V_49 , - 1 ) ;
F_72 ( V_32 , V_34 , V_145 ) ;
V_103 -> V_143 -- ;
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_178;
F_22 ( V_7 , V_46 ) ;
F_73 ( V_32 , V_148 , - 1 ) ;
F_71 ( V_103 ) ;
* V_174 = V_8 ;
return 0 ;
V_187:
F_22 ( V_176 , V_44 ) ;
V_178:
F_22 ( V_7 , V_44 ) ;
F_71 ( V_103 ) ;
return error ;
}
STATIC int
F_95 (
T_1 V_175 ,
struct V_6 * * V_189 ,
struct V_92 * V_20 )
{
struct V_6 * V_190 = * V_189 ;
struct V_6 * V_191 ;
struct V_92 V_192 ;
int error ;
int V_12 , V_62 ;
error = F_4 ( V_190 , V_175 , V_182 , & V_12 ) ;
if ( error )
return error ;
if ( V_12 == 1 ) {
error = F_12 ( V_190 , V_20 , & V_12 ) ;
if ( error )
return error ;
F_86 ( V_190 -> V_22 , V_12 == 1 ) ;
if ( V_175 >= V_20 -> V_13 &&
V_175 < ( V_20 -> V_13 + V_27 ) )
return 0 ;
}
error = F_92 ( V_190 , & V_191 ) ;
if ( error )
return error ;
error = F_4 ( V_191 , V_175 , V_48 , & V_62 ) ;
if ( error )
goto V_193;
if ( V_62 == 1 ) {
error = F_12 ( V_191 , & V_192 , & V_62 ) ;
if ( error )
goto V_193;
F_52 ( V_190 -> V_22 , V_62 == 1 , V_193 ) ;
}
F_52 ( V_190 -> V_22 , V_12 == 1 || V_62 == 1 , V_193 ) ;
if ( V_12 == 1 && V_62 == 1 ) {
if ( ( V_175 - V_20 -> V_13 + V_27 - 1 ) >
( V_192 . V_13 - V_175 ) ) {
* V_20 = V_192 ;
F_22 ( V_190 , V_46 ) ;
* V_189 = V_191 ;
} else {
F_22 ( V_191 , V_46 ) ;
}
} else if ( V_62 == 1 ) {
* V_20 = V_192 ;
F_22 ( V_190 , V_46 ) ;
* V_189 = V_191 ;
} else if ( V_12 == 1 ) {
F_22 ( V_191 , V_46 ) ;
}
return 0 ;
V_193:
F_22 ( V_191 , V_44 ) ;
return error ;
}
STATIC int
F_96 (
struct V_38 * V_39 ,
struct V_6 * V_7 ,
struct V_92 * V_20 )
{
int error ;
int V_12 ;
if ( V_39 -> V_118 != F_7 ( V_81 ) ) {
error = F_4 ( V_7 , F_14 ( V_39 -> V_118 ) ,
V_43 , & V_12 ) ;
if ( error )
return error ;
if ( V_12 == 1 ) {
error = F_12 ( V_7 , V_20 , & V_12 ) ;
if ( error )
return error ;
F_86 ( V_7 -> V_22 , V_12 == 1 ) ;
return 0 ;
}
}
error = F_4 ( V_7 , 0 , V_48 , & V_12 ) ;
if ( error )
return error ;
F_86 ( V_7 -> V_22 , V_12 == 1 ) ;
error = F_12 ( V_7 , V_20 , & V_12 ) ;
if ( error )
return error ;
F_86 ( V_7 -> V_22 , V_12 == 1 ) ;
return 0 ;
}
STATIC int
F_97 (
struct V_6 * V_7 ,
struct V_92 * V_194 ,
int V_90 )
{
struct V_92 V_20 ;
int error ;
int V_12 ;
error = F_4 ( V_7 , V_194 -> V_13 , V_43 , & V_12 ) ;
if ( error )
return error ;
F_86 ( V_7 -> V_22 , V_12 == 1 ) ;
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( error )
return error ;
F_86 ( V_7 -> V_22 , V_12 == 1 ) ;
ASSERT ( ( F_93 ( V_7 -> V_22 , V_20 . V_13 ) %
V_27 ) == 0 ) ;
V_20 . V_17 &= ~ F_94 ( V_90 ) ;
V_20 . V_16 -- ;
F_86 ( V_7 -> V_22 , ( V_20 . V_17 == V_194 -> V_17 ) &&
( V_20 . V_16 == V_194 -> V_16 ) ) ;
return F_6 ( V_7 , & V_20 ) ;
}
STATIC int
F_98 (
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_12 V_152 ,
T_12 * V_174 )
{
struct V_1 * V_2 = V_32 -> V_105 ;
struct V_38 * V_39 = F_20 ( V_34 ) ;
T_9 V_40 = F_14 ( V_39 -> V_41 ) ;
T_9 V_160 = F_81 ( V_2 , V_152 ) ;
T_1 V_175 = F_91 ( V_2 , V_152 ) ;
struct V_102 * V_103 ;
struct V_6 * V_7 ;
struct V_6 * V_195 ;
struct V_92 V_20 ;
T_12 V_8 ;
int error ;
int V_90 ;
int V_12 ;
if ( ! F_68 ( & V_2 -> V_3 ) )
return F_90 ( V_32 , V_34 , V_152 , V_174 ) ;
V_103 = F_70 ( V_2 , V_40 ) ;
if ( ! V_175 )
V_175 = F_14 ( V_39 -> V_118 ) ;
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_141 ) ;
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_196;
if ( V_40 == V_160 )
error = F_95 ( V_175 , & V_7 , & V_20 ) ;
else
error = F_96 ( V_39 , V_7 , & V_20 ) ;
if ( error )
goto V_196;
V_90 = F_88 ( & V_20 ) ;
ASSERT ( V_90 >= 0 ) ;
ASSERT ( V_90 < V_27 ) ;
ASSERT ( ( F_93 ( V_2 , V_20 . V_13 ) %
V_27 ) == 0 ) ;
V_8 = F_29 ( V_2 , V_40 , V_20 . V_13 + V_90 ) ;
V_20 . V_17 &= ~ F_94 ( V_90 ) ;
V_20 . V_16 -- ;
if ( V_20 . V_16 )
error = F_6 ( V_7 , & V_20 ) ;
else
error = F_99 ( V_7 , & V_12 ) ;
if ( error )
goto V_196;
V_195 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_138 ) ;
error = F_23 ( V_195 , V_39 ) ;
if ( error )
goto V_197;
error = F_97 ( V_195 , & V_20 , V_90 ) ;
if ( error )
goto V_197;
F_69 ( & V_39 -> V_49 , - 1 ) ;
F_72 ( V_32 , V_34 , V_145 ) ;
V_103 -> V_143 -- ;
F_73 ( V_32 , V_148 , - 1 ) ;
error = F_23 ( V_195 , V_39 ) ;
if ( error )
goto V_197;
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_197;
F_22 ( V_195 , V_46 ) ;
F_22 ( V_7 , V_46 ) ;
F_71 ( V_103 ) ;
* V_174 = V_8 ;
return 0 ;
V_197:
F_22 ( V_195 , V_44 ) ;
V_196:
F_22 ( V_7 , V_44 ) ;
F_71 ( V_103 ) ;
return error ;
}
int
F_100 (
struct V_31 * V_32 ,
T_12 V_152 ,
T_21 V_153 ,
int V_154 ,
struct V_33 * * V_198 ,
T_12 * V_174 )
{
struct V_1 * V_2 = V_32 -> V_105 ;
struct V_33 * V_34 ;
T_9 V_40 ;
int error ;
int V_199 ;
int V_200 = 0 ;
T_9 V_201 ;
struct V_102 * V_103 ;
if ( * V_198 ) {
V_34 = * V_198 ;
goto V_202;
}
V_201 = F_77 ( V_32 , V_152 , V_153 , V_154 ) ;
if ( V_201 == V_169 ) {
* V_174 = V_203 ;
return 0 ;
}
if ( V_2 -> V_113 &&
F_60 ( & V_2 -> V_114 ) + V_2 -> V_112
> V_2 -> V_113 ) {
V_200 = 1 ;
V_154 = 0 ;
}
V_40 = V_201 ;
for (; ; ) {
V_103 = F_70 ( V_2 , V_40 ) ;
if ( ! V_103 -> V_162 ) {
F_74 ( V_2 ) ;
goto V_163;
}
if ( ! V_103 -> V_164 ) {
error = F_82 ( V_2 , V_32 , V_40 ) ;
if ( error )
goto V_204;
}
if ( ! V_103 -> V_143 && ! V_154 )
goto V_163;
error = F_101 ( V_2 , V_32 , V_40 , & V_34 ) ;
if ( error )
goto V_204;
if ( V_103 -> V_143 ) {
F_71 ( V_103 ) ;
goto V_202;
}
if ( ! V_154 )
goto V_205;
error = F_56 ( V_32 , V_34 , & V_199 ) ;
if ( error ) {
F_102 ( V_32 , V_34 ) ;
if ( error != - V_115 )
goto V_204;
F_71 ( V_103 ) ;
* V_174 = V_203 ;
return 0 ;
}
if ( V_199 ) {
ASSERT ( V_103 -> V_143 > 0 ) ;
F_71 ( V_103 ) ;
* V_198 = V_34 ;
* V_174 = V_203 ;
return 0 ;
}
V_205:
F_102 ( V_32 , V_34 ) ;
V_163:
F_71 ( V_103 ) ;
if ( ++ V_40 == V_2 -> V_3 . V_206 )
V_40 = 0 ;
if ( V_40 == V_201 ) {
* V_174 = V_203 ;
return V_200 ? - V_115 : 0 ;
}
}
V_202:
* V_198 = NULL ;
return F_98 ( V_32 , V_34 , V_152 , V_174 ) ;
V_204:
F_71 ( V_103 ) ;
return error ;
}
STATIC void
F_103 (
struct V_1 * V_2 ,
T_9 V_40 ,
struct V_92 * V_20 ,
struct V_207 * V_208 )
{
T_10 V_209 = F_46 ( V_2 , V_20 -> V_13 ) ;
int V_210 , V_211 ;
int V_212 ;
T_10 V_53 ;
int V_213 ;
struct V_214 V_108 ;
F_104 ( V_28 , V_215 ) ;
F_57 ( & V_108 , V_109 ) ;
if ( ! F_48 ( V_20 -> V_14 ) ) {
F_105 ( V_2 , V_208 , F_62 ( V_2 , V_40 , V_209 ) ,
V_2 -> V_111 , & V_108 ) ;
return;
}
ASSERT ( sizeof( V_20 -> V_14 ) <= sizeof( V_28 [ 0 ] ) ) ;
V_28 [ 0 ] = V_20 -> V_14 ;
V_210 = V_211 = F_106 ( V_28 ,
V_215 ) ;
V_212 = V_210 + 1 ;
while ( V_210 < V_215 ) {
V_212 = F_107 ( V_28 , V_215 ,
V_212 ) ;
if ( V_212 != V_215 &&
V_212 == V_211 + 1 ) {
V_211 = V_212 ;
goto V_216;
}
V_53 = V_209 + ( V_210 * V_91 ) /
V_2 -> V_3 . V_217 ;
V_213 = ( ( V_211 - V_210 + 1 ) *
V_91 ) /
V_2 -> V_3 . V_217 ;
ASSERT ( V_53 % V_2 -> V_3 . V_133 == 0 ) ;
ASSERT ( V_213 % V_2 -> V_3 . V_133 == 0 ) ;
F_105 ( V_2 , V_208 , F_62 ( V_2 , V_40 , V_53 ) ,
V_213 , & V_108 ) ;
V_210 = V_211 = V_212 ;
V_216:
V_212 ++ ;
}
}
STATIC int
F_108 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_1 V_172 ,
struct V_207 * V_208 ,
struct V_218 * V_219 ,
struct V_92 * V_220 )
{
struct V_38 * V_39 = F_20 ( V_34 ) ;
T_9 V_40 = F_14 ( V_39 -> V_41 ) ;
struct V_102 * V_103 ;
struct V_6 * V_7 ;
struct V_92 V_20 ;
int V_221 ;
int error ;
int V_12 ;
int V_222 ;
ASSERT ( V_39 -> V_223 == F_7 ( V_224 ) ) ;
ASSERT ( F_46 ( V_2 , V_172 ) < F_14 ( V_39 -> V_120 ) ) ;
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_138 ) ;
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_178;
if ( ( error = F_4 ( V_7 , V_172 , V_182 , & V_12 ) ) ) {
F_109 ( V_2 , L_2 ,
V_225 , error ) ;
goto V_178;
}
F_52 ( V_2 , V_12 == 1 , V_178 ) ;
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( error ) {
F_109 ( V_2 , L_3 ,
V_225 , error ) ;
goto V_178;
}
F_52 ( V_2 , V_12 == 1 , V_178 ) ;
V_222 = V_172 - V_20 . V_13 ;
ASSERT ( V_222 >= 0 && V_222 < V_27 ) ;
ASSERT ( ! ( V_20 . V_17 & F_94 ( V_222 ) ) ) ;
V_20 . V_17 |= F_94 ( V_222 ) ;
V_20 . V_16 ++ ;
if ( ! ( V_2 -> V_128 & V_226 ) &&
V_20 . V_17 == V_45 &&
V_2 -> V_3 . V_217 <= V_27 ) {
V_219 -> V_227 = 1 ;
V_219 -> V_228 = F_29 ( V_2 , V_40 , V_20 . V_13 ) ;
V_219 -> V_100 = F_49 ( & V_20 ) ;
V_221 = V_20 . V_16 ;
F_69 ( & V_39 -> V_142 , - V_221 ) ;
F_69 ( & V_39 -> V_49 , - ( V_221 - 1 ) ) ;
F_72 ( V_32 , V_34 , V_144 | V_145 ) ;
V_103 = F_70 ( V_2 , V_40 ) ;
V_103 -> V_143 -= V_221 - 1 ;
F_71 ( V_103 ) ;
F_73 ( V_32 , V_147 , - V_221 ) ;
F_73 ( V_32 , V_148 , - ( V_221 - 1 ) ) ;
if ( ( error = F_99 ( V_7 , & V_12 ) ) ) {
F_109 ( V_2 , L_4 ,
V_225 , error ) ;
goto V_178;
}
F_103 ( V_2 , V_40 , & V_20 , V_208 ) ;
} else {
V_219 -> V_227 = 0 ;
error = F_6 ( V_7 , & V_20 ) ;
if ( error ) {
F_109 ( V_2 , L_5 ,
V_225 , error ) ;
goto V_178;
}
F_69 ( & V_39 -> V_49 , 1 ) ;
F_72 ( V_32 , V_34 , V_145 ) ;
V_103 = F_70 ( V_2 , V_40 ) ;
V_103 -> V_143 ++ ;
F_71 ( V_103 ) ;
F_73 ( V_32 , V_148 , 1 ) ;
}
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_178;
* V_220 = V_20 ;
F_22 ( V_7 , V_46 ) ;
return 0 ;
V_178:
F_22 ( V_7 , V_44 ) ;
return error ;
}
STATIC int
F_110 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_1 V_172 ,
struct V_92 * V_229 )
{
struct V_38 * V_39 = F_20 ( V_34 ) ;
T_9 V_40 = F_14 ( V_39 -> V_41 ) ;
struct V_6 * V_7 ;
struct V_92 V_20 ;
int V_90 = V_172 - V_229 -> V_13 ;
int error ;
int V_12 ;
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_141 ) ;
error = F_4 ( V_7 , V_229 -> V_13 , V_43 , & V_12 ) ;
if ( error )
goto error;
if ( V_12 == 0 ) {
F_52 ( V_2 , V_229 -> V_16 == 1 , error ) ;
error = F_17 ( V_7 , V_229 -> V_14 ,
V_229 -> V_15 ,
V_229 -> V_16 ,
V_229 -> V_17 , & V_12 ) ;
if ( error )
goto error;
ASSERT ( V_12 == 1 ) ;
goto V_99;
}
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( error )
goto error;
F_52 ( V_2 , V_12 == 1 , error ) ;
V_20 . V_17 |= F_94 ( V_90 ) ;
V_20 . V_16 ++ ;
F_52 ( V_2 , ( V_20 . V_17 == V_229 -> V_17 ) &&
( V_20 . V_16 == V_229 -> V_16 ) ,
error ) ;
if ( V_20 . V_17 == V_45 &&
V_2 -> V_3 . V_217 <= V_27 &&
! ( V_2 -> V_128 & V_226 ) ) {
error = F_99 ( V_7 , & V_12 ) ;
if ( error )
goto error;
ASSERT ( V_12 == 1 ) ;
} else {
error = F_6 ( V_7 , & V_20 ) ;
if ( error )
goto error;
}
V_99:
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto error;
F_22 ( V_7 , V_46 ) ;
return 0 ;
error:
F_22 ( V_7 , V_44 ) ;
return error ;
}
int
F_111 (
struct V_31 * V_32 ,
T_12 V_230 ,
struct V_207 * V_208 ,
struct V_218 * V_219 )
{
T_10 V_53 ;
struct V_33 * V_34 ;
T_1 V_172 ;
T_9 V_40 ;
int error ;
struct V_1 * V_2 ;
struct V_92 V_20 ;
V_2 = V_32 -> V_105 ;
V_40 = F_81 ( V_2 , V_230 ) ;
if ( V_40 >= V_2 -> V_3 . V_206 ) {
F_109 ( V_2 , L_6 ,
V_225 , V_40 , V_2 -> V_3 . V_206 ) ;
ASSERT ( 0 ) ;
return - V_231 ;
}
V_172 = F_91 ( V_2 , V_230 ) ;
if ( V_230 != F_29 ( V_2 , V_40 , V_172 ) ) {
F_109 ( V_2 , L_7 ,
V_225 , ( unsigned long long ) V_230 ,
( unsigned long long ) F_29 ( V_2 , V_40 , V_172 ) ) ;
ASSERT ( 0 ) ;
return - V_231 ;
}
V_53 = F_46 ( V_2 , V_172 ) ;
if ( V_53 >= V_2 -> V_3 . V_136 ) {
F_109 ( V_2 , L_8 ,
V_225 , V_53 , V_2 -> V_3 . V_136 ) ;
ASSERT ( 0 ) ;
return - V_231 ;
}
error = F_101 ( V_2 , V_32 , V_40 , & V_34 ) ;
if ( error ) {
F_109 ( V_2 , L_9 ,
V_225 , error ) ;
return error ;
}
error = F_108 ( V_2 , V_32 , V_34 , V_172 , V_208 , V_219 , & V_20 ) ;
if ( error )
goto V_178;
if ( F_68 ( & V_2 -> V_3 ) ) {
error = F_110 ( V_2 , V_32 , V_34 , V_172 , & V_20 ) ;
if ( error )
goto V_178;
}
return 0 ;
V_178:
return error ;
}
STATIC int
F_112 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_9 V_40 ,
T_1 V_172 ,
T_10 V_53 ,
T_10 * V_232 ,
T_10 * V_233 ,
int V_156 )
{
struct V_92 V_20 ;
struct V_6 * V_7 ;
struct V_33 * V_34 ;
int error ;
int V_12 ;
error = F_101 ( V_2 , V_32 , V_40 , & V_34 ) ;
if ( error ) {
F_66 ( V_2 ,
L_10 ,
V_225 , error , V_40 ) ;
return error ;
}
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_138 ) ;
error = F_4 ( V_7 , V_172 , V_182 , & V_12 ) ;
if ( ! error ) {
if ( V_12 )
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( ! error && V_12 == 0 )
error = - V_231 ;
}
F_102 ( V_32 , V_34 ) ;
F_22 ( V_7 , error ? V_44 : V_46 ) ;
if ( error )
return error ;
if ( V_20 . V_13 > V_172 ||
V_20 . V_13 + V_2 -> V_112 <= V_172 )
return - V_231 ;
if ( ( V_156 & V_234 ) &&
( V_20 . V_17 & F_94 ( V_172 - V_20 . V_13 ) ) )
return - V_231 ;
* V_232 = F_46 ( V_2 , V_20 . V_13 ) ;
* V_233 = V_53 - * V_232 ;
return 0 ;
}
int
F_113 (
T_20 * V_2 ,
T_16 * V_32 ,
T_12 V_8 ,
struct F_113 * V_235 ,
T_13 V_156 )
{
T_10 V_53 ;
T_1 V_172 ;
T_9 V_40 ;
int V_59 ;
T_10 V_232 ;
T_10 V_236 ;
int error ;
int V_90 ;
T_10 V_233 ;
ASSERT ( V_8 != V_203 ) ;
V_40 = F_81 ( V_2 , V_8 ) ;
V_172 = F_91 ( V_2 , V_8 ) ;
V_53 = F_46 ( V_2 , V_172 ) ;
if ( V_40 >= V_2 -> V_3 . V_206 || V_53 >= V_2 -> V_3 . V_136 ||
V_8 != F_29 ( V_2 , V_40 , V_172 ) ) {
#ifdef F_58
if ( V_156 & V_234 )
return - V_231 ;
if ( V_40 >= V_2 -> V_3 . V_206 ) {
F_66 ( V_2 ,
L_11 ,
V_225 , V_40 , V_2 -> V_3 . V_206 ) ;
}
if ( V_53 >= V_2 -> V_3 . V_136 ) {
F_66 ( V_2 ,
L_12 ,
V_225 , ( unsigned long long ) V_53 ,
( unsigned long ) V_2 -> V_3 . V_136 ) ;
}
if ( V_8 != F_29 ( V_2 , V_40 , V_172 ) ) {
F_66 ( V_2 ,
L_13 ,
V_225 , V_8 ,
F_29 ( V_2 , V_40 , V_172 ) ) ;
}
F_114 () ;
#endif
return - V_231 ;
}
V_59 = F_27 ( V_2 ) ;
if ( V_156 & V_234 ) {
error = F_112 ( V_2 , V_32 , V_40 , V_172 , V_53 ,
& V_232 , & V_233 , V_156 ) ;
if ( error )
return error ;
goto V_237;
}
if ( V_59 == 1 ) {
V_90 = F_115 ( V_2 , V_8 ) ;
ASSERT ( V_90 < V_2 -> V_3 . V_217 ) ;
V_235 -> V_238 = F_32 ( V_2 , V_40 , V_53 ) ;
V_235 -> V_239 = F_116 ( V_2 , 1 ) ;
V_235 -> V_240 = ( unsigned short ) ( V_90 <<
V_2 -> V_3 . V_74 ) ;
return 0 ;
}
if ( V_2 -> V_241 ) {
V_233 = V_53 & V_2 -> V_241 ;
V_232 = V_53 - V_233 ;
} else {
error = F_112 ( V_2 , V_32 , V_40 , V_172 , V_53 ,
& V_232 , & V_233 , V_156 ) ;
if ( error )
return error ;
}
V_237:
ASSERT ( V_53 >= V_232 ) ;
V_236 = V_232 +
( ( V_233 / V_59 ) * V_59 ) ;
V_90 = ( ( V_53 - V_236 ) * V_2 -> V_3 . V_217 ) +
F_115 ( V_2 , V_8 ) ;
V_235 -> V_238 = F_32 ( V_2 , V_40 , V_236 ) ;
V_235 -> V_239 = F_116 ( V_2 , V_59 ) ;
V_235 -> V_240 = ( unsigned short ) ( V_90 << V_2 -> V_3 . V_74 ) ;
if ( ( V_235 -> V_238 + V_235 -> V_239 ) >
F_116 ( V_2 , V_2 -> V_3 . V_242 ) ) {
F_66 ( V_2 ,
L_14 ,
V_225 , ( unsigned long long ) V_235 -> V_238 ,
( unsigned long long ) V_235 -> V_239 ,
F_116 ( V_2 , V_2 -> V_3 . V_242 ) ) ;
return - V_231 ;
}
return 0 ;
}
void
F_117 (
T_20 * V_2 )
{
T_13 V_243 ;
V_243 = ( 1LL << F_118 ( V_2 ) ) >> V_244 ;
V_2 -> V_126 = F_119 ( V_2 , V_2 -> V_245 ,
V_243 ) ;
}
void
F_72 (
T_16 * V_32 ,
T_17 * V_246 ,
int V_247 )
{
int V_248 ;
int V_249 ;
static const short V_250 [] = {
F_120 ( T_18 , V_223 ) ,
F_120 ( T_18 , V_251 ) ,
F_120 ( T_18 , V_41 ) ,
F_120 ( T_18 , V_120 ) ,
F_120 ( T_18 , V_142 ) ,
F_120 ( T_18 , V_131 ) ,
F_120 ( T_18 , V_252 ) ,
F_120 ( T_18 , V_49 ) ,
F_120 ( T_18 , V_118 ) ,
F_120 ( T_18 , V_253 ) ,
F_120 ( T_18 , V_254 ) ,
F_120 ( T_18 , V_255 ) ,
F_120 ( T_18 , V_256 ) ,
sizeof( T_18 )
} ;
#ifdef F_58
T_18 * V_39 ;
V_39 = F_20 ( V_246 ) ;
ASSERT ( V_39 -> V_223 == F_7 ( V_224 ) ) ;
#endif
if ( V_247 & V_257 ) {
F_121 ( V_247 , V_250 , V_258 ,
& V_248 , & V_249 ) ;
F_40 ( V_32 , V_246 , V_248 , V_249 ) ;
}
V_247 &= ~ V_257 ;
if ( V_247 ) {
F_121 ( V_247 , V_250 , V_259 ,
& V_248 , & V_249 ) ;
F_40 ( V_32 , V_246 , V_248 , V_249 ) ;
}
}
STATIC void
F_122 (
struct V_38 * V_39 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_260 ; V_12 ++ )
ASSERT ( V_39 -> V_254 [ V_12 ] ) ;
}
static bool
F_123 (
struct V_33 * V_246 )
{
struct V_1 * V_2 = V_246 -> V_261 -> V_262 ;
struct V_38 * V_39 = F_20 ( V_246 ) ;
if ( F_28 ( & V_2 -> V_3 ) ) {
if ( ! F_124 ( & V_39 -> V_263 , & V_2 -> V_3 . V_84 ) )
return false ;
if ( ! F_125 ( V_2 ,
F_16 ( F_20 ( V_246 ) -> V_264 ) ) )
return false ;
}
if ( V_39 -> V_223 != F_7 ( V_224 ) )
return false ;
if ( ! F_126 ( F_14 ( V_39 -> V_251 ) ) )
return false ;
if ( F_14 ( V_39 -> V_252 ) < 1 ||
F_14 ( V_39 -> V_252 ) > V_265 )
return false ;
if ( F_68 ( & V_2 -> V_3 ) &&
( F_14 ( V_39 -> V_256 ) < 1 ||
F_14 ( V_39 -> V_256 ) > V_265 ) )
return false ;
if ( V_246 -> V_266 && F_14 ( V_39 -> V_41 ) != V_246 -> V_266 -> V_267 )
return false ;
F_122 ( V_39 ) ;
return true ;
}
static void
F_127 (
struct V_33 * V_246 )
{
struct V_1 * V_2 = V_246 -> V_261 -> V_262 ;
if ( F_28 ( & V_2 -> V_3 ) &&
! F_128 ( V_246 , V_268 ) )
F_129 ( V_246 , - V_269 ) ;
else if ( F_130 ( ! F_123 ( V_246 ) , V_2 ,
V_270 ,
V_271 ) )
F_129 ( V_246 , - V_139 ) ;
if ( V_246 -> V_272 )
F_131 ( V_246 ) ;
}
static void
F_132 (
struct V_33 * V_246 )
{
struct V_1 * V_2 = V_246 -> V_261 -> V_262 ;
struct V_273 * V_274 = V_246 -> V_275 ;
if ( ! F_123 ( V_246 ) ) {
F_129 ( V_246 , - V_139 ) ;
F_131 ( V_246 ) ;
return;
}
if ( ! F_28 ( & V_2 -> V_3 ) )
return;
if ( V_274 )
F_20 ( V_246 ) -> V_264 = F_10 ( V_274 -> V_276 . V_277 ) ;
F_133 ( V_246 , V_268 ) ;
}
int
F_134 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_9 V_40 ,
struct V_33 * * V_278 )
{
int error ;
F_135 ( V_2 , V_40 ) ;
ASSERT ( V_40 != V_169 ) ;
error = F_136 ( V_2 , V_32 , V_2 -> V_66 ,
F_137 ( V_2 , V_40 , F_138 ( V_2 ) ) ,
F_139 ( V_2 , 1 ) , 0 , V_278 , & V_279 ) ;
if ( error )
return error ;
if ( V_32 )
F_140 ( V_32 , * V_278 , V_280 ) ;
F_141 ( * V_278 , V_281 ) ;
return 0 ;
}
int
F_101 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_9 V_40 ,
struct V_33 * * V_278 )
{
struct V_38 * V_39 ;
struct V_102 * V_103 ;
int error ;
F_142 ( V_2 , V_40 ) ;
error = F_134 ( V_2 , V_32 , V_40 , V_278 ) ;
if ( error )
return error ;
V_39 = F_20 ( * V_278 ) ;
V_103 = F_70 ( V_2 , V_40 ) ;
if ( ! V_103 -> V_164 ) {
V_103 -> V_143 = F_14 ( V_39 -> V_49 ) ;
V_103 -> V_282 = F_14 ( V_39 -> V_142 ) ;
V_103 -> V_164 = 1 ;
}
ASSERT ( V_103 -> V_143 == F_14 ( V_39 -> V_49 ) ||
F_25 ( V_2 ) ) ;
F_71 ( V_103 ) ;
return 0 ;
}
int
F_82 (
T_20 * V_2 ,
T_16 * V_32 ,
T_9 V_40 )
{
T_17 * V_246 = NULL ;
int error ;
error = F_101 ( V_2 , V_32 , V_40 , & V_246 ) ;
if ( error )
return error ;
if ( V_246 )
F_102 ( V_32 , V_246 ) ;
return 0 ;
}
