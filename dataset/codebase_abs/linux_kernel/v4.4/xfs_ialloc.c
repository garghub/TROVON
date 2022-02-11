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
#ifdef F_57
if ( F_8 ( & V_32 -> V_105 -> V_3 ) &&
args . V_2 -> V_108 < args . V_2 -> V_109 )
V_104 = F_58 () & 1 ;
#endif
V_36 = args . V_2 -> V_110 ;
if ( args . V_2 -> V_111 &&
F_59 ( & args . V_2 -> V_112 ) + V_36 >
args . V_2 -> V_111 )
return - V_113 ;
args . V_114 = args . V_115 = args . V_2 -> V_109 ;
V_39 = F_20 ( V_34 ) ;
V_35 = F_14 ( V_39 -> V_116 ) ;
V_40 = F_14 ( V_39 -> V_41 ) ;
args . V_53 = F_46 ( args . V_2 , V_35 ) +
args . V_2 -> V_109 ;
if ( V_104 )
goto V_117;
if ( F_60 ( V_35 != V_81 &&
( args . V_53 < F_14 ( V_39 -> V_118 ) ) ) ) {
args . V_106 = F_61 ( args . V_2 , V_40 , args . V_53 ) ;
args . type = V_119 ;
args . V_120 = 1 ;
args . V_121 = 1 ;
args . V_122 = F_1 ( args . V_2 ) - 1 ;
args . V_123 = args . V_2 -> V_124 - 1 ;
if ( ( error = F_62 ( & args ) ) )
return error ;
args . V_122 = 0 ;
}
if ( F_63 ( args . V_106 == V_107 ) ) {
V_101 = 0 ;
if ( args . V_2 -> V_125 ) {
ASSERT ( ! ( args . V_2 -> V_126 & V_127 ) ) ;
args . V_121 = args . V_2 -> V_128 ;
V_101 = 1 ;
} else
args . V_121 = F_1 ( args . V_2 ) ;
args . V_53 = F_14 ( V_39 -> V_129 ) ;
args . V_106 = F_61 ( args . V_2 , V_40 , args . V_53 ) ;
args . type = V_130 ;
args . V_120 = 1 ;
args . V_123 = args . V_2 -> V_124 - 1 ;
if ( ( error = F_62 ( & args ) ) )
return error ;
}
if ( V_101 && args . V_106 == V_107 ) {
args . type = V_130 ;
args . V_53 = F_14 ( V_39 -> V_129 ) ;
args . V_106 = F_61 ( args . V_2 , V_40 , args . V_53 ) ;
args . V_121 = F_1 ( args . V_2 ) ;
if ( ( error = F_62 ( & args ) ) )
return error ;
}
if ( F_8 ( & args . V_2 -> V_3 ) &&
args . V_2 -> V_108 < args . V_2 -> V_109 &&
args . V_106 == V_107 ) {
V_117:
args . type = V_130 ;
args . V_53 = F_14 ( V_39 -> V_129 ) ;
args . V_106 = F_61 ( args . V_2 , V_40 , args . V_53 ) ;
args . V_121 = args . V_2 -> V_3 . V_131 ;
args . V_120 = 1 ;
args . V_114 = args . V_2 -> V_108 ;
args . V_115 = args . V_114 ;
args . V_132 = args . V_2 -> V_3 . V_4 ;
args . V_133 = F_64 ( args . V_2 -> V_3 . V_134 ,
args . V_2 -> V_3 . V_4 ) -
args . V_2 -> V_109 ;
error = F_62 ( & args ) ;
if ( error )
return error ;
V_36 = args . V_135 << args . V_2 -> V_3 . V_64 ;
ASSERT ( V_36 <= V_27 ) ;
V_88 = ( 1 << ( V_36 / V_91 ) ) - 1 ;
}
if ( args . V_106 == V_107 ) {
* V_100 = 0 ;
return 0 ;
}
ASSERT ( args . V_135 == args . V_114 ) ;
error = F_26 ( args . V_2 , V_32 , NULL , V_36 , V_40 ,
args . V_53 , args . V_135 , F_58 () ) ;
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
error = F_51 ( args . V_2 , V_32 , V_34 , V_136 ,
& V_20 , true ) ;
if ( error == - V_137 ) {
F_65 ( args . V_2 ,
L_1 ,
F_29 ( args . V_2 , V_40 ,
V_20 . V_13 ) ,
V_20 . V_14 , V_20 . V_15 ) ;
F_66 ( args . V_2 , V_138 ) ;
}
if ( error )
return error ;
if ( F_67 ( & args . V_2 -> V_3 ) ) {
error = F_51 ( args . V_2 , V_32 , V_34 ,
V_139 , & V_20 ,
false ) ;
if ( error )
return error ;
}
} else {
error = F_19 ( args . V_2 , V_32 , V_34 , V_35 , V_36 ,
V_136 ) ;
if ( error )
return error ;
if ( F_67 ( & args . V_2 -> V_3 ) ) {
error = F_19 ( args . V_2 , V_32 , V_34 , V_35 ,
V_36 , V_139 ) ;
if ( error )
return error ;
}
}
F_68 ( & V_39 -> V_140 , V_36 ) ;
F_68 ( & V_39 -> V_49 , V_36 ) ;
V_103 = F_69 ( args . V_2 , V_40 ) ;
V_103 -> V_141 += V_36 ;
F_70 ( V_103 ) ;
V_39 -> V_116 = F_7 ( V_35 ) ;
F_71 ( V_32 , V_34 ,
V_142 | V_143 | V_144 ) ;
F_72 ( V_32 , V_145 , ( long ) V_36 ) ;
F_72 ( V_32 , V_146 , ( long ) V_36 ) ;
* V_100 = 1 ;
return 0 ;
}
STATIC T_9
F_73 (
T_20 * V_2 )
{
T_9 V_40 ;
F_74 ( & V_2 -> V_147 ) ;
V_40 = V_2 -> V_148 ;
if ( ++ V_2 -> V_148 >= V_2 -> V_149 )
V_2 -> V_148 = 0 ;
F_75 ( & V_2 -> V_147 ) ;
return V_40 ;
}
STATIC T_9
F_76 (
T_16 * V_32 ,
T_12 V_150 ,
T_21 V_151 ,
int V_152 )
{
T_9 V_153 ;
T_9 V_40 ;
int V_154 ;
T_22 V_155 ;
T_22 V_156 = 0 ;
T_20 * V_2 ;
int V_157 ;
T_23 * V_103 ;
T_9 V_158 ;
int error ;
V_157 = F_77 ( V_151 ) || F_78 ( V_151 ) || F_79 ( V_151 ) ;
V_2 = V_32 -> V_105 ;
V_153 = V_2 -> V_149 ;
if ( F_77 ( V_151 ) )
V_158 = F_73 ( V_2 ) ;
else {
V_158 = F_80 ( V_2 , V_150 ) ;
if ( V_158 >= V_153 )
V_158 = 0 ;
}
ASSERT ( V_158 < V_153 ) ;
V_40 = V_158 ;
V_154 = V_159 ;
for (; ; ) {
V_103 = F_69 ( V_2 , V_40 ) ;
if ( ! V_103 -> V_160 ) {
F_73 ( V_2 ) ;
goto V_161;
}
if ( ! V_103 -> V_162 ) {
error = F_81 ( V_2 , V_32 , V_40 ) ;
if ( error )
goto V_161;
}
if ( V_103 -> V_141 ) {
F_70 ( V_103 ) ;
return V_40 ;
}
if ( ! V_152 )
goto V_161;
if ( ! V_103 -> V_163 ) {
error = F_82 ( V_2 , V_32 , V_40 , V_154 ) ;
if ( error )
goto V_161;
}
V_155 = V_2 -> V_108 ;
if ( V_154 && V_155 > 1 )
V_155 += F_1 ( V_2 ) ;
V_156 = V_103 -> V_164 ;
if ( ! V_156 )
V_156 = V_103 -> V_165 > 0 ;
if ( V_103 -> V_166 >= V_157 + V_155 &&
V_156 >= V_155 ) {
F_70 ( V_103 ) ;
return V_40 ;
}
V_161:
F_70 ( V_103 ) ;
if ( F_25 ( V_2 ) )
return V_167 ;
V_40 ++ ;
if ( V_40 >= V_153 )
V_40 = 0 ;
if ( V_40 == V_158 ) {
if ( V_154 == 0 )
return V_167 ;
V_154 = 0 ;
}
}
}
STATIC int
F_83 (
struct V_6 * V_7 ,
T_3 * V_20 ,
int * V_168 ,
int V_169 )
{
int error ;
int V_12 ;
if ( V_169 )
error = F_84 ( V_7 , 0 , & V_12 ) ;
else
error = F_24 ( V_7 , 0 , & V_12 ) ;
if ( error )
return error ;
* V_168 = ! V_12 ;
if ( V_12 ) {
error = F_12 ( V_7 , V_20 , & V_12 ) ;
if ( error )
return error ;
F_85 ( V_7 -> V_22 , V_12 == 1 ) ;
}
return 0 ;
}
STATIC int
F_86 (
struct V_6 * V_7 ,
T_1 V_170 ,
T_3 * V_20 ,
int * V_168 )
{
int error ;
int V_12 ;
error = F_4 ( V_7 , V_170 , V_43 , & V_12 ) ;
if ( error )
return error ;
* V_168 = ! V_12 ;
if ( V_12 ) {
error = F_12 ( V_7 , V_20 , & V_12 ) ;
if ( error )
return error ;
F_85 ( V_7 -> V_22 , V_12 == 1 ) ;
}
return 0 ;
}
STATIC int
F_87 (
struct V_92 * V_20 )
{
T_7 V_171 ;
if ( ! F_48 ( V_20 -> V_14 ) )
return F_88 ( V_20 -> V_17 ) ;
V_171 = F_49 ( V_20 ) ;
V_171 &= V_20 -> V_17 ;
return F_88 ( V_171 ) ;
}
STATIC int
F_89 (
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_12 V_150 ,
T_12 * V_172 )
{
struct V_1 * V_2 = V_32 -> V_105 ;
struct V_38 * V_39 = F_20 ( V_34 ) ;
T_9 V_40 = F_14 ( V_39 -> V_41 ) ;
T_9 V_158 = F_80 ( V_2 , V_150 ) ;
T_1 V_173 = F_90 ( V_2 , V_150 ) ;
struct V_102 * V_103 ;
struct V_6 * V_7 , * V_174 ;
struct V_92 V_20 , V_93 ;
T_12 V_8 ;
int error ;
int V_90 ;
int V_12 , V_62 ;
V_103 = F_69 ( V_2 , V_40 ) ;
ASSERT ( V_103 -> V_162 ) ;
ASSERT ( V_103 -> V_160 ) ;
ASSERT ( V_103 -> V_141 > 0 ) ;
V_175:
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_136 ) ;
if ( ! V_173 )
V_173 = F_14 ( V_39 -> V_116 ) ;
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_176;
if ( V_158 == V_40 ) {
int V_177 ;
int V_178 ;
int V_179 = 10 ;
error = F_4 ( V_7 , V_173 , V_180 , & V_12 ) ;
if ( error )
goto V_176;
F_52 ( V_2 , V_12 == 1 , V_176 ) ;
error = F_12 ( V_7 , & V_20 , & V_62 ) ;
if ( error )
goto V_176;
F_52 ( V_2 , V_62 == 1 , V_176 ) ;
if ( V_20 . V_16 > 0 ) {
goto V_181;
}
error = F_91 ( V_7 , & V_174 ) ;
if ( error )
goto V_176;
if ( V_173 != V_81 &&
V_103 -> V_182 == V_173 &&
V_103 -> V_183 != V_81 &&
V_103 -> V_184 != V_81 ) {
error = F_86 ( V_174 , V_103 -> V_183 ,
& V_93 , & V_177 ) ;
if ( error )
goto V_185;
error = F_86 ( V_7 , V_103 -> V_184 ,
& V_20 , & V_178 ) ;
if ( error )
goto V_185;
} else {
error = F_83 ( V_174 , & V_93 , & V_177 , 1 ) ;
if ( error )
goto V_185;
error = F_83 ( V_7 , & V_20 , & V_178 , 0 ) ;
if ( error )
goto V_185;
}
while ( ! V_177 || ! V_178 ) {
int V_186 ;
if ( ! -- V_179 ) {
F_22 ( V_174 , V_46 ) ;
V_103 -> V_183 = V_93 . V_13 ;
V_103 -> V_184 = V_20 . V_13 ;
V_103 -> V_182 = V_173 ;
goto V_35;
}
if ( ! V_177 && ! V_178 ) {
V_186 = V_173 -
( V_93 . V_13 + V_27 - 1 ) <
V_20 . V_13 - V_173 ;
} else {
V_186 = ! V_177 ;
}
if ( V_186 && V_93 . V_16 ) {
V_20 = V_93 ;
F_22 ( V_7 , V_46 ) ;
V_7 = V_174 ;
V_103 -> V_183 = V_93 . V_13 ;
V_103 -> V_184 = V_20 . V_13 ;
V_103 -> V_182 = V_173 ;
goto V_181;
}
if ( ! V_186 && V_20 . V_16 ) {
F_22 ( V_174 , V_46 ) ;
V_103 -> V_183 = V_93 . V_13 ;
V_103 -> V_184 = V_20 . V_13 ;
V_103 -> V_182 = V_173 ;
goto V_181;
}
if ( V_186 ) {
error = F_83 ( V_174 , & V_93 ,
& V_177 , 1 ) ;
} else {
error = F_83 ( V_7 , & V_20 ,
& V_178 , 0 ) ;
}
if ( error )
goto V_185;
}
V_103 -> V_182 = V_81 ;
V_103 -> V_183 = V_81 ;
V_103 -> V_184 = V_81 ;
F_22 ( V_174 , V_46 ) ;
F_22 ( V_7 , V_46 ) ;
goto V_175;
}
V_35:
if ( V_39 -> V_116 != F_7 ( V_81 ) ) {
error = F_4 ( V_7 , F_14 ( V_39 -> V_116 ) ,
V_43 , & V_12 ) ;
if ( error )
goto V_176;
if ( V_12 == 1 ) {
error = F_12 ( V_7 , & V_20 , & V_62 ) ;
if ( error )
goto V_176;
if ( V_62 == 1 && V_20 . V_16 > 0 ) {
goto V_181;
}
}
}
error = F_4 ( V_7 , 0 , V_48 , & V_12 ) ;
if ( error )
goto V_176;
F_52 ( V_2 , V_12 == 1 , V_176 ) ;
for (; ; ) {
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( error )
goto V_176;
F_52 ( V_2 , V_12 == 1 , V_176 ) ;
if ( V_20 . V_16 > 0 )
break;
error = F_24 ( V_7 , 0 , & V_12 ) ;
if ( error )
goto V_176;
F_52 ( V_2 , V_12 == 1 , V_176 ) ;
}
V_181:
V_90 = F_87 ( & V_20 ) ;
ASSERT ( V_90 >= 0 ) ;
ASSERT ( V_90 < V_27 ) ;
ASSERT ( ( F_92 ( V_2 , V_20 . V_13 ) %
V_27 ) == 0 ) ;
V_8 = F_29 ( V_2 , V_40 , V_20 . V_13 + V_90 ) ;
V_20 . V_17 &= ~ F_93 ( V_90 ) ;
V_20 . V_16 -- ;
error = F_6 ( V_7 , & V_20 ) ;
if ( error )
goto V_176;
F_68 ( & V_39 -> V_49 , - 1 ) ;
F_71 ( V_32 , V_34 , V_143 ) ;
V_103 -> V_141 -- ;
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_176;
F_22 ( V_7 , V_46 ) ;
F_72 ( V_32 , V_146 , - 1 ) ;
F_70 ( V_103 ) ;
* V_172 = V_8 ;
return 0 ;
V_185:
F_22 ( V_174 , V_44 ) ;
V_176:
F_22 ( V_7 , V_44 ) ;
F_70 ( V_103 ) ;
return error ;
}
STATIC int
F_94 (
T_1 V_173 ,
struct V_6 * * V_187 ,
struct V_92 * V_20 )
{
struct V_6 * V_188 = * V_187 ;
struct V_6 * V_189 ;
struct V_92 V_190 ;
int error ;
int V_12 , V_62 ;
error = F_4 ( V_188 , V_173 , V_180 , & V_12 ) ;
if ( error )
return error ;
if ( V_12 == 1 ) {
error = F_12 ( V_188 , V_20 , & V_12 ) ;
if ( error )
return error ;
F_85 ( V_188 -> V_22 , V_12 == 1 ) ;
if ( V_173 >= V_20 -> V_13 &&
V_173 < ( V_20 -> V_13 + V_27 ) )
return 0 ;
}
error = F_91 ( V_188 , & V_189 ) ;
if ( error )
return error ;
error = F_4 ( V_189 , V_173 , V_48 , & V_62 ) ;
if ( error )
goto V_191;
if ( V_62 == 1 ) {
error = F_12 ( V_189 , & V_190 , & V_62 ) ;
if ( error )
goto V_191;
F_52 ( V_188 -> V_22 , V_62 == 1 , V_191 ) ;
}
F_52 ( V_188 -> V_22 , V_12 == 1 || V_62 == 1 , V_191 ) ;
if ( V_12 == 1 && V_62 == 1 ) {
if ( ( V_173 - V_20 -> V_13 + V_27 - 1 ) >
( V_190 . V_13 - V_173 ) ) {
* V_20 = V_190 ;
F_22 ( V_188 , V_46 ) ;
* V_187 = V_189 ;
} else {
F_22 ( V_189 , V_46 ) ;
}
} else if ( V_62 == 1 ) {
* V_20 = V_190 ;
F_22 ( V_188 , V_46 ) ;
* V_187 = V_189 ;
} else if ( V_12 == 1 ) {
F_22 ( V_189 , V_46 ) ;
}
return 0 ;
V_191:
F_22 ( V_189 , V_44 ) ;
return error ;
}
STATIC int
F_95 (
struct V_38 * V_39 ,
struct V_6 * V_7 ,
struct V_92 * V_20 )
{
int error ;
int V_12 ;
if ( V_39 -> V_116 != F_7 ( V_81 ) ) {
error = F_4 ( V_7 , F_14 ( V_39 -> V_116 ) ,
V_43 , & V_12 ) ;
if ( error )
return error ;
if ( V_12 == 1 ) {
error = F_12 ( V_7 , V_20 , & V_12 ) ;
if ( error )
return error ;
F_85 ( V_7 -> V_22 , V_12 == 1 ) ;
return 0 ;
}
}
error = F_4 ( V_7 , 0 , V_48 , & V_12 ) ;
if ( error )
return error ;
F_85 ( V_7 -> V_22 , V_12 == 1 ) ;
error = F_12 ( V_7 , V_20 , & V_12 ) ;
if ( error )
return error ;
F_85 ( V_7 -> V_22 , V_12 == 1 ) ;
return 0 ;
}
STATIC int
F_96 (
struct V_6 * V_7 ,
struct V_92 * V_192 ,
int V_90 )
{
struct V_92 V_20 ;
int error ;
int V_12 ;
error = F_4 ( V_7 , V_192 -> V_13 , V_43 , & V_12 ) ;
if ( error )
return error ;
F_85 ( V_7 -> V_22 , V_12 == 1 ) ;
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( error )
return error ;
F_85 ( V_7 -> V_22 , V_12 == 1 ) ;
ASSERT ( ( F_92 ( V_7 -> V_22 , V_20 . V_13 ) %
V_27 ) == 0 ) ;
V_20 . V_17 &= ~ F_93 ( V_90 ) ;
V_20 . V_16 -- ;
F_85 ( V_7 -> V_22 , ( V_20 . V_17 == V_192 -> V_17 ) &&
( V_20 . V_16 == V_192 -> V_16 ) ) ;
return F_6 ( V_7 , & V_20 ) ;
}
STATIC int
F_97 (
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_12 V_150 ,
T_12 * V_172 )
{
struct V_1 * V_2 = V_32 -> V_105 ;
struct V_38 * V_39 = F_20 ( V_34 ) ;
T_9 V_40 = F_14 ( V_39 -> V_41 ) ;
T_9 V_158 = F_80 ( V_2 , V_150 ) ;
T_1 V_173 = F_90 ( V_2 , V_150 ) ;
struct V_102 * V_103 ;
struct V_6 * V_7 ;
struct V_6 * V_193 ;
struct V_92 V_20 ;
T_12 V_8 ;
int error ;
int V_90 ;
int V_12 ;
if ( ! F_67 ( & V_2 -> V_3 ) )
return F_89 ( V_32 , V_34 , V_150 , V_172 ) ;
V_103 = F_69 ( V_2 , V_40 ) ;
if ( ! V_173 )
V_173 = F_14 ( V_39 -> V_116 ) ;
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_139 ) ;
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_194;
if ( V_40 == V_158 )
error = F_94 ( V_173 , & V_7 , & V_20 ) ;
else
error = F_95 ( V_39 , V_7 , & V_20 ) ;
if ( error )
goto V_194;
V_90 = F_87 ( & V_20 ) ;
ASSERT ( V_90 >= 0 ) ;
ASSERT ( V_90 < V_27 ) ;
ASSERT ( ( F_92 ( V_2 , V_20 . V_13 ) %
V_27 ) == 0 ) ;
V_8 = F_29 ( V_2 , V_40 , V_20 . V_13 + V_90 ) ;
V_20 . V_17 &= ~ F_93 ( V_90 ) ;
V_20 . V_16 -- ;
if ( V_20 . V_16 )
error = F_6 ( V_7 , & V_20 ) ;
else
error = F_98 ( V_7 , & V_12 ) ;
if ( error )
goto V_194;
V_193 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_136 ) ;
error = F_23 ( V_193 , V_39 ) ;
if ( error )
goto V_195;
error = F_96 ( V_193 , & V_20 , V_90 ) ;
if ( error )
goto V_195;
F_68 ( & V_39 -> V_49 , - 1 ) ;
F_71 ( V_32 , V_34 , V_143 ) ;
V_103 -> V_141 -- ;
F_72 ( V_32 , V_146 , - 1 ) ;
error = F_23 ( V_193 , V_39 ) ;
if ( error )
goto V_195;
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_195;
F_22 ( V_193 , V_46 ) ;
F_22 ( V_7 , V_46 ) ;
F_70 ( V_103 ) ;
* V_172 = V_8 ;
return 0 ;
V_195:
F_22 ( V_193 , V_44 ) ;
V_194:
F_22 ( V_7 , V_44 ) ;
F_70 ( V_103 ) ;
return error ;
}
int
F_99 (
struct V_31 * V_32 ,
T_12 V_150 ,
T_21 V_151 ,
int V_152 ,
struct V_33 * * V_196 ,
T_12 * V_172 )
{
struct V_1 * V_2 = V_32 -> V_105 ;
struct V_33 * V_34 ;
T_9 V_40 ;
int error ;
int V_197 ;
int V_198 = 0 ;
T_9 V_199 ;
struct V_102 * V_103 ;
if ( * V_196 ) {
V_34 = * V_196 ;
goto V_200;
}
V_199 = F_76 ( V_32 , V_150 , V_151 , V_152 ) ;
if ( V_199 == V_167 ) {
* V_172 = V_201 ;
return 0 ;
}
if ( V_2 -> V_111 &&
F_59 ( & V_2 -> V_112 ) + V_2 -> V_110
> V_2 -> V_111 ) {
V_198 = 1 ;
V_152 = 0 ;
}
V_40 = V_199 ;
for (; ; ) {
V_103 = F_69 ( V_2 , V_40 ) ;
if ( ! V_103 -> V_160 ) {
F_73 ( V_2 ) ;
goto V_161;
}
if ( ! V_103 -> V_162 ) {
error = F_81 ( V_2 , V_32 , V_40 ) ;
if ( error )
goto V_202;
}
if ( ! V_103 -> V_141 && ! V_152 )
goto V_161;
error = F_100 ( V_2 , V_32 , V_40 , & V_34 ) ;
if ( error )
goto V_202;
if ( V_103 -> V_141 ) {
F_70 ( V_103 ) ;
goto V_200;
}
if ( ! V_152 )
goto V_203;
error = F_56 ( V_32 , V_34 , & V_197 ) ;
if ( error ) {
F_101 ( V_32 , V_34 ) ;
if ( error != - V_113 )
goto V_202;
F_70 ( V_103 ) ;
* V_172 = V_201 ;
return 0 ;
}
if ( V_197 ) {
ASSERT ( V_103 -> V_141 > 0 ) ;
F_70 ( V_103 ) ;
* V_196 = V_34 ;
* V_172 = V_201 ;
return 0 ;
}
V_203:
F_101 ( V_32 , V_34 ) ;
V_161:
F_70 ( V_103 ) ;
if ( ++ V_40 == V_2 -> V_3 . V_204 )
V_40 = 0 ;
if ( V_40 == V_199 ) {
* V_172 = V_201 ;
return V_198 ? - V_113 : 0 ;
}
}
V_200:
* V_196 = NULL ;
return F_97 ( V_32 , V_34 , V_150 , V_172 ) ;
V_202:
F_70 ( V_103 ) ;
return error ;
}
STATIC void
F_102 (
struct V_1 * V_2 ,
T_9 V_40 ,
struct V_92 * V_20 ,
struct V_205 * V_206 )
{
T_10 V_207 = F_46 ( V_2 , V_20 -> V_13 ) ;
int V_208 , V_209 ;
int V_210 ;
T_10 V_53 ;
int V_211 ;
F_103 ( V_28 , V_212 ) ;
if ( ! F_48 ( V_20 -> V_14 ) ) {
F_104 ( F_61 ( V_2 , V_40 ,
F_46 ( V_2 , V_20 -> V_13 ) ) ,
V_2 -> V_109 , V_206 , V_2 ) ;
return;
}
ASSERT ( sizeof( V_20 -> V_14 ) <= sizeof( V_28 [ 0 ] ) ) ;
V_28 [ 0 ] = V_20 -> V_14 ;
V_208 = V_209 = F_105 ( V_28 ,
V_212 ) ;
V_210 = V_208 + 1 ;
while ( V_208 < V_212 ) {
V_210 = F_106 ( V_28 , V_212 ,
V_210 ) ;
if ( V_210 != V_212 &&
V_210 == V_209 + 1 ) {
V_209 = V_210 ;
goto V_213;
}
V_53 = V_207 + ( V_208 * V_91 ) /
V_2 -> V_3 . V_214 ;
V_211 = ( ( V_209 - V_208 + 1 ) *
V_91 ) /
V_2 -> V_3 . V_214 ;
ASSERT ( V_53 % V_2 -> V_3 . V_131 == 0 ) ;
ASSERT ( V_211 % V_2 -> V_3 . V_131 == 0 ) ;
F_104 ( F_61 ( V_2 , V_40 , V_53 ) , V_211 ,
V_206 , V_2 ) ;
V_208 = V_209 = V_210 ;
V_213:
V_210 ++ ;
}
}
STATIC int
F_107 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_1 V_170 ,
struct V_205 * V_206 ,
struct V_215 * V_216 ,
struct V_92 * V_217 )
{
struct V_38 * V_39 = F_20 ( V_34 ) ;
T_9 V_40 = F_14 ( V_39 -> V_41 ) ;
struct V_102 * V_103 ;
struct V_6 * V_7 ;
struct V_92 V_20 ;
int V_218 ;
int error ;
int V_12 ;
int V_219 ;
ASSERT ( V_39 -> V_220 == F_7 ( V_221 ) ) ;
ASSERT ( F_46 ( V_2 , V_170 ) < F_14 ( V_39 -> V_118 ) ) ;
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_136 ) ;
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_176;
if ( ( error = F_4 ( V_7 , V_170 , V_180 , & V_12 ) ) ) {
F_108 ( V_2 , L_2 ,
V_222 , error ) ;
goto V_176;
}
F_52 ( V_2 , V_12 == 1 , V_176 ) ;
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( error ) {
F_108 ( V_2 , L_3 ,
V_222 , error ) ;
goto V_176;
}
F_52 ( V_2 , V_12 == 1 , V_176 ) ;
V_219 = V_170 - V_20 . V_13 ;
ASSERT ( V_219 >= 0 && V_219 < V_27 ) ;
ASSERT ( ! ( V_20 . V_17 & F_93 ( V_219 ) ) ) ;
V_20 . V_17 |= F_93 ( V_219 ) ;
V_20 . V_16 ++ ;
if ( ! ( V_2 -> V_126 & V_223 ) &&
V_20 . V_17 == V_45 &&
V_2 -> V_3 . V_214 <= V_27 ) {
V_216 -> V_224 = 1 ;
V_216 -> V_225 = F_29 ( V_2 , V_40 , V_20 . V_13 ) ;
V_216 -> V_100 = F_49 ( & V_20 ) ;
V_218 = V_20 . V_16 ;
F_68 ( & V_39 -> V_140 , - V_218 ) ;
F_68 ( & V_39 -> V_49 , - ( V_218 - 1 ) ) ;
F_71 ( V_32 , V_34 , V_142 | V_143 ) ;
V_103 = F_69 ( V_2 , V_40 ) ;
V_103 -> V_141 -= V_218 - 1 ;
F_70 ( V_103 ) ;
F_72 ( V_32 , V_145 , - V_218 ) ;
F_72 ( V_32 , V_146 , - ( V_218 - 1 ) ) ;
if ( ( error = F_98 ( V_7 , & V_12 ) ) ) {
F_108 ( V_2 , L_4 ,
V_222 , error ) ;
goto V_176;
}
F_102 ( V_2 , V_40 , & V_20 , V_206 ) ;
} else {
V_216 -> V_224 = 0 ;
error = F_6 ( V_7 , & V_20 ) ;
if ( error ) {
F_108 ( V_2 , L_5 ,
V_222 , error ) ;
goto V_176;
}
F_68 ( & V_39 -> V_49 , 1 ) ;
F_71 ( V_32 , V_34 , V_143 ) ;
V_103 = F_69 ( V_2 , V_40 ) ;
V_103 -> V_141 ++ ;
F_70 ( V_103 ) ;
F_72 ( V_32 , V_146 , 1 ) ;
}
error = F_23 ( V_7 , V_39 ) ;
if ( error )
goto V_176;
* V_217 = V_20 ;
F_22 ( V_7 , V_46 ) ;
return 0 ;
V_176:
F_22 ( V_7 , V_44 ) ;
return error ;
}
STATIC int
F_109 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_1 V_170 ,
struct V_92 * V_226 )
{
struct V_38 * V_39 = F_20 ( V_34 ) ;
T_9 V_40 = F_14 ( V_39 -> V_41 ) ;
struct V_6 * V_7 ;
struct V_92 V_20 ;
int V_90 = V_170 - V_226 -> V_13 ;
int error ;
int V_12 ;
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_139 ) ;
error = F_4 ( V_7 , V_226 -> V_13 , V_43 , & V_12 ) ;
if ( error )
goto error;
if ( V_12 == 0 ) {
F_52 ( V_2 , V_226 -> V_16 == 1 , error ) ;
error = F_17 ( V_7 , V_226 -> V_14 ,
V_226 -> V_15 ,
V_226 -> V_16 ,
V_226 -> V_17 , & V_12 ) ;
if ( error )
goto error;
ASSERT ( V_12 == 1 ) ;
goto V_99;
}
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( error )
goto error;
F_52 ( V_2 , V_12 == 1 , error ) ;
V_20 . V_17 |= F_93 ( V_90 ) ;
V_20 . V_16 ++ ;
F_52 ( V_2 , ( V_20 . V_17 == V_226 -> V_17 ) &&
( V_20 . V_16 == V_226 -> V_16 ) ,
error ) ;
if ( V_20 . V_17 == V_45 &&
V_2 -> V_3 . V_214 <= V_27 &&
! ( V_2 -> V_126 & V_223 ) ) {
error = F_98 ( V_7 , & V_12 ) ;
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
F_110 (
struct V_31 * V_32 ,
T_12 V_227 ,
struct V_205 * V_206 ,
struct V_215 * V_216 )
{
T_10 V_53 ;
struct V_33 * V_34 ;
T_1 V_170 ;
T_9 V_40 ;
int error ;
struct V_1 * V_2 ;
struct V_92 V_20 ;
V_2 = V_32 -> V_105 ;
V_40 = F_80 ( V_2 , V_227 ) ;
if ( V_40 >= V_2 -> V_3 . V_204 ) {
F_108 ( V_2 , L_6 ,
V_222 , V_40 , V_2 -> V_3 . V_204 ) ;
ASSERT ( 0 ) ;
return - V_228 ;
}
V_170 = F_90 ( V_2 , V_227 ) ;
if ( V_227 != F_29 ( V_2 , V_40 , V_170 ) ) {
F_108 ( V_2 , L_7 ,
V_222 , ( unsigned long long ) V_227 ,
( unsigned long long ) F_29 ( V_2 , V_40 , V_170 ) ) ;
ASSERT ( 0 ) ;
return - V_228 ;
}
V_53 = F_46 ( V_2 , V_170 ) ;
if ( V_53 >= V_2 -> V_3 . V_134 ) {
F_108 ( V_2 , L_8 ,
V_222 , V_53 , V_2 -> V_3 . V_134 ) ;
ASSERT ( 0 ) ;
return - V_228 ;
}
error = F_100 ( V_2 , V_32 , V_40 , & V_34 ) ;
if ( error ) {
F_108 ( V_2 , L_9 ,
V_222 , error ) ;
return error ;
}
error = F_107 ( V_2 , V_32 , V_34 , V_170 , V_206 , V_216 , & V_20 ) ;
if ( error )
goto V_176;
if ( F_67 ( & V_2 -> V_3 ) ) {
error = F_109 ( V_2 , V_32 , V_34 , V_170 , & V_20 ) ;
if ( error )
goto V_176;
}
return 0 ;
V_176:
return error ;
}
STATIC int
F_111 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_9 V_40 ,
T_1 V_170 ,
T_10 V_53 ,
T_10 * V_229 ,
T_10 * V_230 ,
int V_154 )
{
struct V_92 V_20 ;
struct V_6 * V_7 ;
struct V_33 * V_34 ;
int error ;
int V_12 ;
error = F_100 ( V_2 , V_32 , V_40 , & V_34 ) ;
if ( error ) {
F_65 ( V_2 ,
L_10 ,
V_222 , error , V_40 ) ;
return error ;
}
V_7 = F_21 ( V_2 , V_32 , V_34 , V_40 , V_136 ) ;
error = F_4 ( V_7 , V_170 , V_180 , & V_12 ) ;
if ( ! error ) {
if ( V_12 )
error = F_12 ( V_7 , & V_20 , & V_12 ) ;
if ( ! error && V_12 == 0 )
error = - V_228 ;
}
F_101 ( V_32 , V_34 ) ;
F_22 ( V_7 , error ? V_44 : V_46 ) ;
if ( error )
return error ;
if ( V_20 . V_13 > V_170 ||
V_20 . V_13 + V_2 -> V_110 <= V_170 )
return - V_228 ;
if ( ( V_154 & V_231 ) &&
( V_20 . V_17 & F_93 ( V_170 - V_20 . V_13 ) ) )
return - V_228 ;
* V_229 = F_46 ( V_2 , V_20 . V_13 ) ;
* V_230 = V_53 - * V_229 ;
return 0 ;
}
int
F_112 (
T_20 * V_2 ,
T_16 * V_32 ,
T_12 V_8 ,
struct F_112 * V_232 ,
T_13 V_154 )
{
T_10 V_53 ;
T_1 V_170 ;
T_9 V_40 ;
int V_59 ;
T_10 V_229 ;
T_10 V_233 ;
int error ;
int V_90 ;
T_10 V_230 ;
ASSERT ( V_8 != V_201 ) ;
V_40 = F_80 ( V_2 , V_8 ) ;
V_170 = F_90 ( V_2 , V_8 ) ;
V_53 = F_46 ( V_2 , V_170 ) ;
if ( V_40 >= V_2 -> V_3 . V_204 || V_53 >= V_2 -> V_3 . V_134 ||
V_8 != F_29 ( V_2 , V_40 , V_170 ) ) {
#ifdef F_57
if ( V_154 & V_231 )
return - V_228 ;
if ( V_40 >= V_2 -> V_3 . V_204 ) {
F_65 ( V_2 ,
L_11 ,
V_222 , V_40 , V_2 -> V_3 . V_204 ) ;
}
if ( V_53 >= V_2 -> V_3 . V_134 ) {
F_65 ( V_2 ,
L_12 ,
V_222 , ( unsigned long long ) V_53 ,
( unsigned long ) V_2 -> V_3 . V_134 ) ;
}
if ( V_8 != F_29 ( V_2 , V_40 , V_170 ) ) {
F_65 ( V_2 ,
L_13 ,
V_222 , V_8 ,
F_29 ( V_2 , V_40 , V_170 ) ) ;
}
F_113 () ;
#endif
return - V_228 ;
}
V_59 = F_27 ( V_2 ) ;
if ( V_154 & V_231 ) {
error = F_111 ( V_2 , V_32 , V_40 , V_170 , V_53 ,
& V_229 , & V_230 , V_154 ) ;
if ( error )
return error ;
goto V_234;
}
if ( V_59 == 1 ) {
V_90 = F_114 ( V_2 , V_8 ) ;
ASSERT ( V_90 < V_2 -> V_3 . V_214 ) ;
V_232 -> V_235 = F_32 ( V_2 , V_40 , V_53 ) ;
V_232 -> V_236 = F_115 ( V_2 , 1 ) ;
V_232 -> V_237 = ( V_238 ) ( V_90 << V_2 -> V_3 . V_74 ) ;
return 0 ;
}
if ( V_2 -> V_239 ) {
V_230 = V_53 & V_2 -> V_239 ;
V_229 = V_53 - V_230 ;
} else {
error = F_111 ( V_2 , V_32 , V_40 , V_170 , V_53 ,
& V_229 , & V_230 , V_154 ) ;
if ( error )
return error ;
}
V_234:
ASSERT ( V_53 >= V_229 ) ;
V_233 = V_229 +
( ( V_230 / V_59 ) * V_59 ) ;
V_90 = ( ( V_53 - V_233 ) * V_2 -> V_3 . V_214 ) +
F_114 ( V_2 , V_8 ) ;
V_232 -> V_235 = F_32 ( V_2 , V_40 , V_233 ) ;
V_232 -> V_236 = F_115 ( V_2 , V_59 ) ;
V_232 -> V_237 = ( V_238 ) ( V_90 << V_2 -> V_3 . V_74 ) ;
if ( ( V_232 -> V_235 + V_232 -> V_236 ) >
F_115 ( V_2 , V_2 -> V_3 . V_240 ) ) {
F_65 ( V_2 ,
L_14 ,
V_222 , ( unsigned long long ) V_232 -> V_235 ,
( unsigned long long ) V_232 -> V_236 ,
F_115 ( V_2 , V_2 -> V_3 . V_240 ) ) ;
return - V_228 ;
}
return 0 ;
}
void
F_116 (
T_20 * V_2 )
{
int V_241 ;
T_13 V_242 ;
T_13 V_243 ;
int V_244 ;
int V_245 ;
V_243 = ( 1LL << F_117 ( V_2 ) ) >>
V_246 ;
V_244 = V_2 -> V_247 [ 0 ] ;
V_245 = V_2 -> V_247 [ 1 ] ;
V_242 = ( V_243 + V_244 - 1 ) / V_244 ;
for ( V_241 = 1 ; V_242 > 1 ; V_241 ++ )
V_242 = ( V_242 + V_245 - 1 ) / V_245 ;
V_2 -> V_124 = V_241 ;
}
void
F_71 (
T_16 * V_32 ,
T_17 * V_248 ,
int V_249 )
{
int V_250 ;
int V_251 ;
static const short V_252 [] = {
F_118 ( T_18 , V_220 ) ,
F_118 ( T_18 , V_253 ) ,
F_118 ( T_18 , V_41 ) ,
F_118 ( T_18 , V_118 ) ,
F_118 ( T_18 , V_140 ) ,
F_118 ( T_18 , V_129 ) ,
F_118 ( T_18 , V_254 ) ,
F_118 ( T_18 , V_49 ) ,
F_118 ( T_18 , V_116 ) ,
F_118 ( T_18 , V_255 ) ,
F_118 ( T_18 , V_256 ) ,
F_118 ( T_18 , V_257 ) ,
F_118 ( T_18 , V_258 ) ,
sizeof( T_18 )
} ;
#ifdef F_57
T_18 * V_39 ;
V_39 = F_20 ( V_248 ) ;
ASSERT ( V_39 -> V_220 == F_7 ( V_221 ) ) ;
#endif
F_119 ( V_32 , V_248 , V_259 ) ;
if ( V_249 & V_260 ) {
F_120 ( V_249 , V_252 , V_261 ,
& V_250 , & V_251 ) ;
F_40 ( V_32 , V_248 , V_250 , V_251 ) ;
}
V_249 &= ~ V_260 ;
if ( V_249 ) {
F_120 ( V_249 , V_252 , V_262 ,
& V_250 , & V_251 ) ;
F_40 ( V_32 , V_248 , V_250 , V_251 ) ;
}
}
STATIC void
F_121 (
struct V_38 * V_39 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_263 ; V_12 ++ )
ASSERT ( V_39 -> V_256 [ V_12 ] ) ;
}
static bool
F_122 (
struct V_33 * V_248 )
{
struct V_1 * V_2 = V_248 -> V_264 -> V_265 ;
struct V_38 * V_39 = F_20 ( V_248 ) ;
if ( F_28 ( & V_2 -> V_3 ) ) {
if ( ! F_123 ( & V_39 -> V_266 , & V_2 -> V_3 . V_84 ) )
return false ;
if ( ! F_124 ( V_2 ,
F_16 ( F_20 ( V_248 ) -> V_267 ) ) )
return false ;
}
if ( V_39 -> V_220 != F_7 ( V_221 ) )
return false ;
if ( ! F_125 ( F_14 ( V_39 -> V_253 ) ) )
return false ;
if ( F_14 ( V_39 -> V_254 ) > V_268 )
return false ;
if ( V_248 -> V_269 && F_14 ( V_39 -> V_41 ) != V_248 -> V_269 -> V_270 )
return false ;
F_121 ( V_39 ) ;
return true ;
}
static void
F_126 (
struct V_33 * V_248 )
{
struct V_1 * V_2 = V_248 -> V_264 -> V_265 ;
if ( F_28 ( & V_2 -> V_3 ) &&
! F_127 ( V_248 , V_271 ) )
F_128 ( V_248 , - V_272 ) ;
else if ( F_129 ( ! F_122 ( V_248 ) , V_2 ,
V_273 ,
V_274 ) )
F_128 ( V_248 , - V_137 ) ;
if ( V_248 -> V_275 )
F_130 ( V_248 ) ;
}
static void
F_131 (
struct V_33 * V_248 )
{
struct V_1 * V_2 = V_248 -> V_264 -> V_265 ;
struct V_276 * V_277 = V_248 -> V_278 ;
if ( ! F_122 ( V_248 ) ) {
F_128 ( V_248 , - V_137 ) ;
F_130 ( V_248 ) ;
return;
}
if ( ! F_28 ( & V_2 -> V_3 ) )
return;
if ( V_277 )
F_20 ( V_248 ) -> V_267 = F_10 ( V_277 -> V_279 . V_280 ) ;
F_132 ( V_248 , V_271 ) ;
}
int
F_133 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_9 V_40 ,
struct V_33 * * V_281 )
{
int error ;
F_134 ( V_2 , V_40 ) ;
ASSERT ( V_40 != V_167 ) ;
error = F_135 ( V_2 , V_32 , V_2 -> V_66 ,
F_136 ( V_2 , V_40 , F_137 ( V_2 ) ) ,
F_138 ( V_2 , 1 ) , 0 , V_281 , & V_282 ) ;
if ( error )
return error ;
F_139 ( * V_281 , V_283 ) ;
return 0 ;
}
int
F_100 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_9 V_40 ,
struct V_33 * * V_281 )
{
struct V_38 * V_39 ;
struct V_102 * V_103 ;
int error ;
F_140 ( V_2 , V_40 ) ;
error = F_133 ( V_2 , V_32 , V_40 , V_281 ) ;
if ( error )
return error ;
V_39 = F_20 ( * V_281 ) ;
V_103 = F_69 ( V_2 , V_40 ) ;
if ( ! V_103 -> V_162 ) {
V_103 -> V_141 = F_14 ( V_39 -> V_49 ) ;
V_103 -> V_284 = F_14 ( V_39 -> V_140 ) ;
V_103 -> V_162 = 1 ;
}
ASSERT ( V_103 -> V_141 == F_14 ( V_39 -> V_49 ) ||
F_25 ( V_2 ) ) ;
F_70 ( V_103 ) ;
return 0 ;
}
int
F_81 (
T_20 * V_2 ,
T_16 * V_32 ,
T_9 V_40 )
{
T_17 * V_248 = NULL ;
int error ;
error = F_100 ( V_2 , V_32 , V_40 , & V_248 ) ;
if ( error )
return error ;
if ( V_248 )
F_101 ( V_32 , V_248 ) ;
return 0 ;
}
