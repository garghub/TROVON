int
F_1 (
struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) &&
V_2 -> V_3 . V_4 >= F_3 ( V_2 ) )
return V_2 -> V_3 . V_4 ;
return 1 ;
}
int
F_4 (
struct V_5 * V_6 ,
T_1 V_7 ,
T_2 V_8 ,
int * V_9 )
{
V_6 -> V_10 . V_11 . V_12 = V_7 ;
V_6 -> V_10 . V_11 . V_13 = 0 ;
V_6 -> V_10 . V_11 . V_14 = 0 ;
V_6 -> V_10 . V_11 . V_15 = 0 ;
V_6 -> V_10 . V_11 . V_16 = 0 ;
return F_5 ( V_6 , V_8 , V_9 ) ;
}
STATIC int
F_6 (
struct V_5 * V_6 ,
T_3 * V_17 )
{
union V_18 V_19 ;
V_19 . V_20 . V_12 = F_7 ( V_17 -> V_12 ) ;
if ( F_8 ( & V_6 -> V_21 -> V_3 ) ) {
V_19 . V_20 . V_22 . V_23 . V_13 = F_9 ( V_17 -> V_13 ) ;
V_19 . V_20 . V_22 . V_23 . V_14 = V_17 -> V_14 ;
V_19 . V_20 . V_22 . V_23 . V_15 = V_17 -> V_15 ;
} else {
V_19 . V_20 . V_22 . V_24 . V_15 = F_7 ( V_17 -> V_15 ) ;
}
V_19 . V_20 . V_16 = F_10 ( V_17 -> V_16 ) ;
return F_11 ( V_6 , & V_19 ) ;
}
void
F_12 (
struct V_1 * V_2 ,
union V_18 * V_19 ,
struct V_25 * V_17 )
{
V_17 -> V_12 = F_13 ( V_19 -> V_20 . V_12 ) ;
if ( F_8 ( & V_2 -> V_3 ) ) {
V_17 -> V_13 = F_14 ( V_19 -> V_20 . V_22 . V_23 . V_13 ) ;
V_17 -> V_14 = V_19 -> V_20 . V_22 . V_23 . V_14 ;
V_17 -> V_15 = V_19 -> V_20 . V_22 . V_23 . V_15 ;
} else {
V_17 -> V_13 = V_26 ;
V_17 -> V_14 = V_27 ;
V_17 -> V_15 =
F_13 ( V_19 -> V_20 . V_22 . V_24 . V_15 ) ;
}
V_17 -> V_16 = F_15 ( V_19 -> V_20 . V_16 ) ;
}
int
F_16 (
struct V_5 * V_6 ,
struct V_25 * V_17 ,
int * V_9 )
{
union V_18 * V_19 ;
int error ;
error = F_17 ( V_6 , & V_19 , V_9 ) ;
if ( error || * V_9 == 0 )
return error ;
F_12 ( V_6 -> V_21 , V_19 , V_17 ) ;
return 0 ;
}
STATIC int
F_18 (
struct V_5 * V_6 ,
T_4 V_28 ,
T_5 V_29 ,
T_6 V_30 ,
T_7 free ,
int * V_9 )
{
V_6 -> V_10 . V_11 . V_13 = V_28 ;
V_6 -> V_10 . V_11 . V_14 = V_29 ;
V_6 -> V_10 . V_11 . V_15 = V_30 ;
V_6 -> V_10 . V_11 . V_16 = free ;
return F_19 ( V_6 , V_9 ) ;
}
STATIC int
F_20 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_1 V_35 ,
T_1 V_36 ,
T_8 V_37 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 = F_21 ( V_34 ) ;
T_9 V_40 = F_13 ( V_39 -> V_41 ) ;
T_1 V_42 ;
int V_11 ;
int error ;
V_6 = F_22 ( V_2 , V_32 , V_34 , V_40 , V_37 ) ;
for ( V_42 = V_35 ;
V_42 < V_35 + V_36 ;
V_42 += V_27 ) {
error = F_4 ( V_6 , V_42 , V_43 , & V_11 ) ;
if ( error ) {
F_23 ( V_6 , V_44 ) ;
return error ;
}
ASSERT ( V_11 == 0 ) ;
error = F_18 ( V_6 , V_26 ,
V_27 ,
V_27 ,
V_45 , & V_11 ) ;
if ( error ) {
F_23 ( V_6 , V_44 ) ;
return error ;
}
ASSERT ( V_11 == 1 ) ;
}
F_23 ( V_6 , V_46 ) ;
return 0 ;
}
STATIC int
F_24 (
struct V_5 * V_6 ,
struct V_38 * V_39 )
{
if ( V_6 -> V_47 == 1 ) {
T_3 V_19 ;
int V_30 = 0 ;
int error ;
int V_11 ;
error = F_4 ( V_6 , 0 , V_48 , & V_11 ) ;
if ( error )
return error ;
do {
error = F_16 ( V_6 , & V_19 , & V_11 ) ;
if ( error )
return error ;
if ( V_11 ) {
V_30 += V_19 . V_15 ;
error = F_25 ( V_6 , 0 , & V_11 ) ;
if ( error )
return error ;
}
} while ( V_11 == 1 );
if ( ! F_26 ( V_6 -> V_21 ) )
ASSERT ( V_30 == F_13 ( V_39 -> V_49 ) ) ;
}
return 0 ;
}
int
F_27 (
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
int V_11 , V_62 ;
T_11 V_63 ;
T_12 V_7 = 0 ;
V_59 = F_3 ( V_2 ) ;
V_60 = V_59 << V_2 -> V_3 . V_64 ;
V_58 = V_54 / V_59 ;
if ( F_28 ( & V_2 -> V_3 ) ) {
V_61 = 3 ;
V_7 = F_29 ( V_2 , V_40 ,
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
for ( V_11 = 0 ; V_11 < V_60 ; V_11 ++ ) {
int V_73 = V_11 << V_2 -> V_3 . V_74 ;
T_13 V_75 = F_36 ( V_61 ) ;
free = F_37 ( V_2 , V_56 , V_11 ) ;
free -> V_76 = F_9 ( V_77 ) ;
free -> V_78 = V_61 ;
free -> V_79 = F_7 ( V_55 ) ;
free -> V_80 = F_7 ( V_81 ) ;
if ( V_61 == 3 ) {
free -> V_82 = F_10 ( V_7 ) ;
V_7 ++ ;
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
T_4 * V_88 )
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
struct V_25 * V_92 ,
struct V_25 * V_93 )
{
T_14 V_94 ;
T_14 V_95 ;
if ( V_92 -> V_12 != V_93 -> V_12 )
return false ;
if ( ! F_48 ( V_92 -> V_13 ) ||
! F_48 ( V_93 -> V_13 ) )
return false ;
if ( ! V_92 -> V_14 || ! V_93 -> V_14 )
return false ;
if ( V_92 -> V_14 + V_93 -> V_14 > V_27 )
return false ;
V_94 = F_49 ( V_92 ) ;
V_95 = F_49 ( V_93 ) ;
if ( V_94 & V_95 )
return false ;
return true ;
}
STATIC void
F_50 (
struct V_25 * V_92 ,
struct V_25 * V_93 )
{
ASSERT ( V_92 -> V_12 == V_93 -> V_12 ) ;
V_92 -> V_14 += V_93 -> V_14 ;
V_92 -> V_15 += V_93 -> V_15 ;
V_92 -> V_13 &= V_93 -> V_13 ;
V_92 -> V_16 &= V_93 -> V_16 ;
}
STATIC int
F_51 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
int V_37 ,
struct V_25 * V_96 ,
bool V_97 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 = F_21 ( V_34 ) ;
T_9 V_40 = F_13 ( V_39 -> V_41 ) ;
int error ;
int V_11 ;
struct V_25 V_19 ;
V_6 = F_22 ( V_2 , V_32 , V_34 , V_40 , V_37 ) ;
error = F_4 ( V_6 , V_96 -> V_12 , V_43 , & V_11 ) ;
if ( error )
goto error;
if ( V_11 == 0 ) {
error = F_18 ( V_6 , V_96 -> V_13 ,
V_96 -> V_14 , V_96 -> V_15 ,
V_96 -> V_16 , & V_11 ) ;
if ( error )
goto error;
F_52 ( V_2 , V_11 == 1 , error ) ;
goto V_98;
}
if ( V_97 ) {
error = F_16 ( V_6 , & V_19 , & V_11 ) ;
if ( error )
goto error;
F_52 ( V_2 , V_11 == 1 , error ) ;
F_52 ( V_2 ,
V_19 . V_12 == V_96 -> V_12 ,
error ) ;
F_52 ( V_2 , F_47 ( V_96 , & V_19 ) ,
error ) ;
F_53 ( V_2 , V_40 , V_19 . V_12 ,
V_19 . V_13 , V_96 -> V_12 ,
V_96 -> V_13 ) ;
F_50 ( V_96 , & V_19 ) ;
F_54 ( V_2 , V_40 , V_96 -> V_12 ,
V_96 -> V_13 ) ;
error = F_55 ( V_2 , V_96 ) ;
if ( error )
goto error;
}
error = F_6 ( V_6 , V_96 ) ;
if ( error )
goto error;
V_98:
F_23 ( V_6 , V_46 ) ;
return 0 ;
error:
F_23 ( V_6 , V_44 ) ;
return error ;
}
STATIC int
F_56 (
T_15 * V_32 ,
T_16 * V_34 ,
int * V_99 )
{
T_17 * V_39 ;
T_18 args ;
T_9 V_40 ;
int error ;
T_1 V_35 ;
T_1 V_36 ;
int V_100 = 0 ;
T_4 V_88 = ( T_4 ) - 1 ;
struct V_25 V_19 ;
struct V_101 * V_102 ;
int V_103 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_32 = V_32 ;
args . V_2 = V_32 -> V_104 ;
args . V_105 = V_106 ;
F_57 ( & args . V_107 , V_108 ) ;
#ifdef F_58
if ( F_8 ( & V_32 -> V_104 -> V_3 ) &&
args . V_2 -> V_109 < args . V_2 -> V_110 )
V_103 = F_59 () & 1 ;
#endif
V_36 = args . V_2 -> V_111 ;
if ( args . V_2 -> V_112 &&
F_60 ( & args . V_2 -> V_113 ) + V_36 >
args . V_2 -> V_112 )
return - V_114 ;
args . V_115 = args . V_116 = args . V_2 -> V_110 ;
V_39 = F_21 ( V_34 ) ;
V_35 = F_13 ( V_39 -> V_117 ) ;
V_40 = F_13 ( V_39 -> V_41 ) ;
args . V_53 = F_46 ( args . V_2 , V_35 ) +
args . V_2 -> V_110 ;
if ( V_103 )
goto V_118;
if ( F_61 ( V_35 != V_81 &&
( args . V_53 < F_13 ( V_39 -> V_119 ) ) ) ) {
args . V_105 = F_62 ( args . V_2 , V_40 , args . V_53 ) ;
args . type = V_120 ;
args . V_121 = 1 ;
args . V_122 = 1 ;
args . V_123 = F_1 ( args . V_2 ) - 1 ;
args . V_124 = args . V_2 -> V_125 - 1 ;
if ( ( error = F_63 ( & args ) ) )
return error ;
args . V_123 = 0 ;
}
if ( F_64 ( args . V_105 == V_106 ) ) {
V_100 = 0 ;
if ( args . V_2 -> V_126 ) {
ASSERT ( ! ( args . V_2 -> V_127 & V_128 ) ) ;
args . V_122 = args . V_2 -> V_129 ;
V_100 = 1 ;
} else
args . V_122 = F_1 ( args . V_2 ) ;
args . V_53 = F_13 ( V_39 -> V_130 ) ;
args . V_105 = F_62 ( args . V_2 , V_40 , args . V_53 ) ;
args . type = V_131 ;
args . V_121 = 1 ;
args . V_124 = args . V_2 -> V_125 - 1 ;
if ( ( error = F_63 ( & args ) ) )
return error ;
}
if ( V_100 && args . V_105 == V_106 ) {
args . type = V_131 ;
args . V_53 = F_13 ( V_39 -> V_130 ) ;
args . V_105 = F_62 ( args . V_2 , V_40 , args . V_53 ) ;
args . V_122 = F_1 ( args . V_2 ) ;
if ( ( error = F_63 ( & args ) ) )
return error ;
}
if ( F_8 ( & args . V_2 -> V_3 ) &&
args . V_2 -> V_109 < args . V_2 -> V_110 &&
args . V_105 == V_106 ) {
V_118:
args . type = V_131 ;
args . V_53 = F_13 ( V_39 -> V_130 ) ;
args . V_105 = F_62 ( args . V_2 , V_40 , args . V_53 ) ;
args . V_122 = args . V_2 -> V_3 . V_132 ;
args . V_121 = 1 ;
args . V_115 = args . V_2 -> V_109 ;
args . V_116 = args . V_115 ;
args . V_133 = args . V_2 -> V_3 . V_4 ;
args . V_134 = F_65 ( args . V_2 -> V_3 . V_135 ,
args . V_2 -> V_3 . V_4 ) -
args . V_2 -> V_110 ;
error = F_63 ( & args ) ;
if ( error )
return error ;
V_36 = args . V_136 << args . V_2 -> V_3 . V_64 ;
ASSERT ( V_36 <= V_27 ) ;
V_88 = ( 1 << ( V_36 / V_91 ) ) - 1 ;
}
if ( args . V_105 == V_106 ) {
* V_99 = 0 ;
return 0 ;
}
ASSERT ( args . V_136 == args . V_115 ) ;
error = F_27 ( args . V_2 , V_32 , NULL , V_36 , V_40 ,
args . V_53 , args . V_136 , F_59 () ) ;
if ( error )
return error ;
V_35 = F_30 ( args . V_2 , args . V_53 , 0 ) ;
if ( F_48 ( ~ V_88 ) ) {
F_45 ( args . V_2 , & V_35 , & V_88 ) ;
V_19 . V_12 = V_35 ;
V_19 . V_13 = ~ V_88 ;
V_19 . V_14 = V_36 ;
V_19 . V_15 = V_36 ;
V_19 . V_16 = V_45 ;
error = F_51 ( args . V_2 , V_32 , V_34 , V_137 ,
& V_19 , true ) ;
if ( error == - V_138 ) {
F_66 ( args . V_2 ,
L_1 ,
F_29 ( args . V_2 , V_40 ,
V_19 . V_12 ) ,
V_19 . V_13 , V_19 . V_14 ) ;
F_67 ( args . V_2 , V_139 ) ;
}
if ( error )
return error ;
if ( F_68 ( & args . V_2 -> V_3 ) ) {
error = F_51 ( args . V_2 , V_32 , V_34 ,
V_140 , & V_19 ,
false ) ;
if ( error )
return error ;
}
} else {
error = F_20 ( args . V_2 , V_32 , V_34 , V_35 , V_36 ,
V_137 ) ;
if ( error )
return error ;
if ( F_68 ( & args . V_2 -> V_3 ) ) {
error = F_20 ( args . V_2 , V_32 , V_34 , V_35 ,
V_36 , V_140 ) ;
if ( error )
return error ;
}
}
F_69 ( & V_39 -> V_141 , V_36 ) ;
F_69 ( & V_39 -> V_49 , V_36 ) ;
V_102 = F_70 ( args . V_2 , V_40 ) ;
V_102 -> V_142 += V_36 ;
F_71 ( V_102 ) ;
V_39 -> V_117 = F_7 ( V_35 ) ;
F_72 ( V_32 , V_34 ,
V_143 | V_144 | V_145 ) ;
F_73 ( V_32 , V_146 , ( long ) V_36 ) ;
F_73 ( V_32 , V_147 , ( long ) V_36 ) ;
* V_99 = 1 ;
return 0 ;
}
STATIC T_9
F_74 (
T_19 * V_2 )
{
T_9 V_40 ;
F_75 ( & V_2 -> V_148 ) ;
V_40 = V_2 -> V_149 ;
if ( ++ V_2 -> V_149 >= V_2 -> V_150 )
V_2 -> V_149 = 0 ;
F_76 ( & V_2 -> V_148 ) ;
return V_40 ;
}
STATIC T_9
F_77 (
T_15 * V_32 ,
T_12 V_151 ,
T_20 V_152 ,
int V_153 )
{
T_9 V_154 ;
T_9 V_40 ;
int V_155 ;
T_21 V_156 ;
T_21 V_157 = 0 ;
T_19 * V_2 ;
int V_158 ;
T_22 * V_102 ;
T_9 V_159 ;
int error ;
V_158 = F_78 ( V_152 ) || F_79 ( V_152 ) || F_80 ( V_152 ) ;
V_2 = V_32 -> V_104 ;
V_154 = V_2 -> V_150 ;
if ( F_78 ( V_152 ) )
V_159 = F_74 ( V_2 ) ;
else {
V_159 = F_81 ( V_2 , V_151 ) ;
if ( V_159 >= V_154 )
V_159 = 0 ;
}
ASSERT ( V_159 < V_154 ) ;
V_40 = V_159 ;
V_155 = V_160 ;
for (; ; ) {
V_102 = F_70 ( V_2 , V_40 ) ;
if ( ! V_102 -> V_161 ) {
F_74 ( V_2 ) ;
goto V_162;
}
if ( ! V_102 -> V_163 ) {
error = F_82 ( V_2 , V_32 , V_40 ) ;
if ( error )
goto V_162;
}
if ( V_102 -> V_142 ) {
F_71 ( V_102 ) ;
return V_40 ;
}
if ( ! V_153 )
goto V_162;
if ( ! V_102 -> V_164 ) {
error = F_83 ( V_2 , V_32 , V_40 , V_155 ) ;
if ( error )
goto V_162;
}
V_156 = V_2 -> V_109 ;
if ( V_155 && V_156 > 1 )
V_156 += F_1 ( V_2 ) ;
V_157 = V_102 -> V_165 ;
if ( ! V_157 )
V_157 = V_102 -> V_166 > 0 ;
if ( V_102 -> V_167 >= V_158 + V_156 &&
V_157 >= V_156 ) {
F_71 ( V_102 ) ;
return V_40 ;
}
V_162:
F_71 ( V_102 ) ;
if ( F_26 ( V_2 ) )
return V_168 ;
V_40 ++ ;
if ( V_40 >= V_154 )
V_40 = 0 ;
if ( V_40 == V_159 ) {
if ( V_155 == 0 )
return V_168 ;
V_155 = 0 ;
}
}
}
STATIC int
F_84 (
struct V_5 * V_6 ,
T_3 * V_19 ,
int * V_169 ,
int V_170 )
{
int error ;
int V_11 ;
if ( V_170 )
error = F_85 ( V_6 , 0 , & V_11 ) ;
else
error = F_25 ( V_6 , 0 , & V_11 ) ;
if ( error )
return error ;
* V_169 = ! V_11 ;
if ( V_11 ) {
error = F_16 ( V_6 , V_19 , & V_11 ) ;
if ( error )
return error ;
F_86 ( V_6 -> V_21 , V_11 == 1 ) ;
}
return 0 ;
}
STATIC int
F_87 (
struct V_5 * V_6 ,
T_1 V_171 ,
T_3 * V_19 ,
int * V_169 )
{
int error ;
int V_11 ;
error = F_4 ( V_6 , V_171 , V_43 , & V_11 ) ;
if ( error )
return error ;
* V_169 = ! V_11 ;
if ( V_11 ) {
error = F_16 ( V_6 , V_19 , & V_11 ) ;
if ( error )
return error ;
F_86 ( V_6 -> V_21 , V_11 == 1 ) ;
}
return 0 ;
}
STATIC int
F_88 (
struct V_25 * V_19 )
{
T_7 V_172 ;
if ( ! F_48 ( V_19 -> V_13 ) )
return F_89 ( V_19 -> V_16 ) ;
V_172 = F_49 ( V_19 ) ;
V_172 &= V_19 -> V_16 ;
return F_89 ( V_172 ) ;
}
STATIC int
F_90 (
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_12 V_151 ,
T_12 * V_173 )
{
struct V_1 * V_2 = V_32 -> V_104 ;
struct V_38 * V_39 = F_21 ( V_34 ) ;
T_9 V_40 = F_13 ( V_39 -> V_41 ) ;
T_9 V_159 = F_81 ( V_2 , V_151 ) ;
T_1 V_174 = F_91 ( V_2 , V_151 ) ;
struct V_101 * V_102 ;
struct V_5 * V_6 , * V_175 ;
struct V_25 V_19 , V_92 ;
T_12 V_7 ;
int error ;
int V_90 ;
int V_11 , V_62 ;
int V_176 = 10 ;
V_102 = F_70 ( V_2 , V_40 ) ;
ASSERT ( V_102 -> V_163 ) ;
ASSERT ( V_102 -> V_161 ) ;
ASSERT ( V_102 -> V_142 > 0 ) ;
V_177:
V_6 = F_22 ( V_2 , V_32 , V_34 , V_40 , V_137 ) ;
if ( ! V_174 )
V_174 = F_13 ( V_39 -> V_117 ) ;
error = F_24 ( V_6 , V_39 ) ;
if ( error )
goto V_178;
if ( V_159 == V_40 ) {
int V_179 ;
int V_180 ;
error = F_4 ( V_6 , V_174 , V_181 , & V_11 ) ;
if ( error )
goto V_178;
F_52 ( V_2 , V_11 == 1 , V_178 ) ;
error = F_16 ( V_6 , & V_19 , & V_62 ) ;
if ( error )
goto V_178;
F_52 ( V_2 , V_62 == 1 , V_178 ) ;
if ( V_19 . V_15 > 0 ) {
goto V_182;
}
error = F_92 ( V_6 , & V_175 ) ;
if ( error )
goto V_178;
if ( V_174 != V_81 &&
V_102 -> V_183 == V_174 &&
V_102 -> V_184 != V_81 &&
V_102 -> V_185 != V_81 ) {
error = F_87 ( V_175 , V_102 -> V_184 ,
& V_92 , & V_179 ) ;
if ( error )
goto V_186;
error = F_87 ( V_6 , V_102 -> V_185 ,
& V_19 , & V_180 ) ;
if ( error )
goto V_186;
} else {
error = F_84 ( V_175 , & V_92 , & V_179 , 1 ) ;
if ( error )
goto V_186;
error = F_84 ( V_6 , & V_19 , & V_180 , 0 ) ;
if ( error )
goto V_186;
}
while ( -- V_176 > 0 && ( ! V_179 || ! V_180 ) ) {
int V_187 ;
if ( ! V_179 && ! V_180 ) {
V_187 = V_174 -
( V_92 . V_12 + V_27 - 1 ) <
V_19 . V_12 - V_174 ;
} else {
V_187 = ! V_179 ;
}
if ( V_187 && V_92 . V_15 ) {
F_23 ( V_6 , V_46 ) ;
V_6 = V_175 ;
V_102 -> V_184 = V_92 . V_12 ;
V_102 -> V_185 = V_19 . V_12 ;
V_102 -> V_183 = V_174 ;
V_19 = V_92 ;
goto V_182;
}
if ( ! V_187 && V_19 . V_15 ) {
F_23 ( V_175 , V_46 ) ;
V_102 -> V_184 = V_92 . V_12 ;
V_102 -> V_185 = V_19 . V_12 ;
V_102 -> V_183 = V_174 ;
goto V_182;
}
if ( V_187 ) {
error = F_84 ( V_175 , & V_92 ,
& V_179 , 1 ) ;
} else {
error = F_84 ( V_6 , & V_19 ,
& V_180 , 0 ) ;
}
if ( error )
goto V_186;
}
if ( V_176 <= 0 ) {
F_23 ( V_175 , V_46 ) ;
V_102 -> V_184 = V_92 . V_12 ;
V_102 -> V_185 = V_19 . V_12 ;
V_102 -> V_183 = V_174 ;
} else {
V_102 -> V_183 = V_81 ;
V_102 -> V_184 = V_81 ;
V_102 -> V_185 = V_81 ;
F_23 ( V_175 , V_46 ) ;
F_23 ( V_6 , V_46 ) ;
goto V_177;
}
}
if ( V_39 -> V_117 != F_7 ( V_81 ) ) {
error = F_4 ( V_6 , F_13 ( V_39 -> V_117 ) ,
V_43 , & V_11 ) ;
if ( error )
goto V_178;
if ( V_11 == 1 ) {
error = F_16 ( V_6 , & V_19 , & V_62 ) ;
if ( error )
goto V_178;
if ( V_62 == 1 && V_19 . V_15 > 0 ) {
goto V_182;
}
}
}
error = F_4 ( V_6 , 0 , V_48 , & V_11 ) ;
if ( error )
goto V_178;
F_52 ( V_2 , V_11 == 1 , V_178 ) ;
for (; ; ) {
error = F_16 ( V_6 , & V_19 , & V_11 ) ;
if ( error )
goto V_178;
F_52 ( V_2 , V_11 == 1 , V_178 ) ;
if ( V_19 . V_15 > 0 )
break;
error = F_25 ( V_6 , 0 , & V_11 ) ;
if ( error )
goto V_178;
F_52 ( V_2 , V_11 == 1 , V_178 ) ;
}
V_182:
V_90 = F_88 ( & V_19 ) ;
ASSERT ( V_90 >= 0 ) ;
ASSERT ( V_90 < V_27 ) ;
ASSERT ( ( F_93 ( V_2 , V_19 . V_12 ) %
V_27 ) == 0 ) ;
V_7 = F_29 ( V_2 , V_40 , V_19 . V_12 + V_90 ) ;
V_19 . V_16 &= ~ F_94 ( V_90 ) ;
V_19 . V_15 -- ;
error = F_6 ( V_6 , & V_19 ) ;
if ( error )
goto V_178;
F_69 ( & V_39 -> V_49 , - 1 ) ;
F_72 ( V_32 , V_34 , V_144 ) ;
V_102 -> V_142 -- ;
error = F_24 ( V_6 , V_39 ) ;
if ( error )
goto V_178;
F_23 ( V_6 , V_46 ) ;
F_73 ( V_32 , V_147 , - 1 ) ;
F_71 ( V_102 ) ;
* V_173 = V_7 ;
return 0 ;
V_186:
F_23 ( V_175 , V_44 ) ;
V_178:
F_23 ( V_6 , V_44 ) ;
F_71 ( V_102 ) ;
return error ;
}
STATIC int
F_95 (
T_1 V_174 ,
struct V_5 * * V_188 ,
struct V_25 * V_19 )
{
struct V_5 * V_189 = * V_188 ;
struct V_5 * V_190 ;
struct V_25 V_191 ;
int error ;
int V_11 , V_62 ;
error = F_4 ( V_189 , V_174 , V_181 , & V_11 ) ;
if ( error )
return error ;
if ( V_11 == 1 ) {
error = F_16 ( V_189 , V_19 , & V_11 ) ;
if ( error )
return error ;
F_86 ( V_189 -> V_21 , V_11 == 1 ) ;
if ( V_174 >= V_19 -> V_12 &&
V_174 < ( V_19 -> V_12 + V_27 ) )
return 0 ;
}
error = F_92 ( V_189 , & V_190 ) ;
if ( error )
return error ;
error = F_4 ( V_190 , V_174 , V_48 , & V_62 ) ;
if ( error )
goto V_192;
if ( V_62 == 1 ) {
error = F_16 ( V_190 , & V_191 , & V_62 ) ;
if ( error )
goto V_192;
F_52 ( V_189 -> V_21 , V_62 == 1 , V_192 ) ;
}
F_52 ( V_189 -> V_21 , V_11 == 1 || V_62 == 1 , V_192 ) ;
if ( V_11 == 1 && V_62 == 1 ) {
if ( ( V_174 - V_19 -> V_12 + V_27 - 1 ) >
( V_191 . V_12 - V_174 ) ) {
* V_19 = V_191 ;
F_23 ( V_189 , V_46 ) ;
* V_188 = V_190 ;
} else {
F_23 ( V_190 , V_46 ) ;
}
} else if ( V_62 == 1 ) {
* V_19 = V_191 ;
F_23 ( V_189 , V_46 ) ;
* V_188 = V_190 ;
} else if ( V_11 == 1 ) {
F_23 ( V_190 , V_46 ) ;
}
return 0 ;
V_192:
F_23 ( V_190 , V_44 ) ;
return error ;
}
STATIC int
F_96 (
struct V_38 * V_39 ,
struct V_5 * V_6 ,
struct V_25 * V_19 )
{
int error ;
int V_11 ;
if ( V_39 -> V_117 != F_7 ( V_81 ) ) {
error = F_4 ( V_6 , F_13 ( V_39 -> V_117 ) ,
V_43 , & V_11 ) ;
if ( error )
return error ;
if ( V_11 == 1 ) {
error = F_16 ( V_6 , V_19 , & V_11 ) ;
if ( error )
return error ;
F_86 ( V_6 -> V_21 , V_11 == 1 ) ;
return 0 ;
}
}
error = F_4 ( V_6 , 0 , V_48 , & V_11 ) ;
if ( error )
return error ;
F_86 ( V_6 -> V_21 , V_11 == 1 ) ;
error = F_16 ( V_6 , V_19 , & V_11 ) ;
if ( error )
return error ;
F_86 ( V_6 -> V_21 , V_11 == 1 ) ;
return 0 ;
}
STATIC int
F_97 (
struct V_5 * V_6 ,
struct V_25 * V_193 ,
int V_90 )
{
struct V_25 V_19 ;
int error ;
int V_11 ;
error = F_4 ( V_6 , V_193 -> V_12 , V_43 , & V_11 ) ;
if ( error )
return error ;
F_86 ( V_6 -> V_21 , V_11 == 1 ) ;
error = F_16 ( V_6 , & V_19 , & V_11 ) ;
if ( error )
return error ;
F_86 ( V_6 -> V_21 , V_11 == 1 ) ;
ASSERT ( ( F_93 ( V_6 -> V_21 , V_19 . V_12 ) %
V_27 ) == 0 ) ;
V_19 . V_16 &= ~ F_94 ( V_90 ) ;
V_19 . V_15 -- ;
F_86 ( V_6 -> V_21 , ( V_19 . V_16 == V_193 -> V_16 ) &&
( V_19 . V_15 == V_193 -> V_15 ) ) ;
return F_6 ( V_6 , & V_19 ) ;
}
STATIC int
F_98 (
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_12 V_151 ,
T_12 * V_173 )
{
struct V_1 * V_2 = V_32 -> V_104 ;
struct V_38 * V_39 = F_21 ( V_34 ) ;
T_9 V_40 = F_13 ( V_39 -> V_41 ) ;
T_9 V_159 = F_81 ( V_2 , V_151 ) ;
T_1 V_174 = F_91 ( V_2 , V_151 ) ;
struct V_101 * V_102 ;
struct V_5 * V_6 ;
struct V_5 * V_194 ;
struct V_25 V_19 ;
T_12 V_7 ;
int error ;
int V_90 ;
int V_11 ;
if ( ! F_68 ( & V_2 -> V_3 ) )
return F_90 ( V_32 , V_34 , V_151 , V_173 ) ;
V_102 = F_70 ( V_2 , V_40 ) ;
if ( ! V_174 )
V_174 = F_13 ( V_39 -> V_117 ) ;
V_6 = F_22 ( V_2 , V_32 , V_34 , V_40 , V_140 ) ;
error = F_24 ( V_6 , V_39 ) ;
if ( error )
goto V_195;
if ( V_40 == V_159 )
error = F_95 ( V_174 , & V_6 , & V_19 ) ;
else
error = F_96 ( V_39 , V_6 , & V_19 ) ;
if ( error )
goto V_195;
V_90 = F_88 ( & V_19 ) ;
ASSERT ( V_90 >= 0 ) ;
ASSERT ( V_90 < V_27 ) ;
ASSERT ( ( F_93 ( V_2 , V_19 . V_12 ) %
V_27 ) == 0 ) ;
V_7 = F_29 ( V_2 , V_40 , V_19 . V_12 + V_90 ) ;
V_19 . V_16 &= ~ F_94 ( V_90 ) ;
V_19 . V_15 -- ;
if ( V_19 . V_15 )
error = F_6 ( V_6 , & V_19 ) ;
else
error = F_99 ( V_6 , & V_11 ) ;
if ( error )
goto V_195;
V_194 = F_22 ( V_2 , V_32 , V_34 , V_40 , V_137 ) ;
error = F_24 ( V_194 , V_39 ) ;
if ( error )
goto V_196;
error = F_97 ( V_194 , & V_19 , V_90 ) ;
if ( error )
goto V_196;
F_69 ( & V_39 -> V_49 , - 1 ) ;
F_72 ( V_32 , V_34 , V_144 ) ;
V_102 -> V_142 -- ;
F_73 ( V_32 , V_147 , - 1 ) ;
error = F_24 ( V_194 , V_39 ) ;
if ( error )
goto V_196;
error = F_24 ( V_6 , V_39 ) ;
if ( error )
goto V_196;
F_23 ( V_194 , V_46 ) ;
F_23 ( V_6 , V_46 ) ;
F_71 ( V_102 ) ;
* V_173 = V_7 ;
return 0 ;
V_196:
F_23 ( V_194 , V_44 ) ;
V_195:
F_23 ( V_6 , V_44 ) ;
F_71 ( V_102 ) ;
return error ;
}
int
F_100 (
struct V_31 * V_32 ,
T_12 V_151 ,
T_20 V_152 ,
int V_153 ,
struct V_33 * * V_197 ,
T_12 * V_173 )
{
struct V_1 * V_2 = V_32 -> V_104 ;
struct V_33 * V_34 ;
T_9 V_40 ;
int error ;
int V_198 ;
int V_199 = 0 ;
T_9 V_200 ;
struct V_101 * V_102 ;
if ( * V_197 ) {
V_34 = * V_197 ;
goto V_201;
}
V_200 = F_77 ( V_32 , V_151 , V_152 , V_153 ) ;
if ( V_200 == V_168 ) {
* V_173 = V_202 ;
return 0 ;
}
if ( V_2 -> V_112 &&
F_60 ( & V_2 -> V_113 ) + V_2 -> V_111
> V_2 -> V_112 ) {
V_199 = 1 ;
V_153 = 0 ;
}
V_40 = V_200 ;
for (; ; ) {
V_102 = F_70 ( V_2 , V_40 ) ;
if ( ! V_102 -> V_161 ) {
F_74 ( V_2 ) ;
goto V_162;
}
if ( ! V_102 -> V_163 ) {
error = F_82 ( V_2 , V_32 , V_40 ) ;
if ( error )
goto V_203;
}
if ( ! V_102 -> V_142 && ! V_153 )
goto V_162;
error = F_101 ( V_2 , V_32 , V_40 , & V_34 ) ;
if ( error )
goto V_203;
if ( V_102 -> V_142 ) {
F_71 ( V_102 ) ;
goto V_201;
}
if ( ! V_153 )
goto V_204;
error = F_56 ( V_32 , V_34 , & V_198 ) ;
if ( error ) {
F_102 ( V_32 , V_34 ) ;
if ( error != - V_114 )
goto V_203;
F_71 ( V_102 ) ;
* V_173 = V_202 ;
return 0 ;
}
if ( V_198 ) {
ASSERT ( V_102 -> V_142 > 0 ) ;
F_71 ( V_102 ) ;
* V_197 = V_34 ;
* V_173 = V_202 ;
return 0 ;
}
V_204:
F_102 ( V_32 , V_34 ) ;
V_162:
F_71 ( V_102 ) ;
if ( ++ V_40 == V_2 -> V_3 . V_205 )
V_40 = 0 ;
if ( V_40 == V_200 ) {
* V_173 = V_202 ;
return V_199 ? - V_114 : 0 ;
}
}
V_201:
* V_197 = NULL ;
return F_98 ( V_32 , V_34 , V_151 , V_173 ) ;
V_203:
F_71 ( V_102 ) ;
return error ;
}
STATIC void
F_103 (
struct V_1 * V_2 ,
T_9 V_40 ,
struct V_25 * V_19 ,
struct V_206 * V_207 )
{
T_10 V_208 = F_46 ( V_2 , V_19 -> V_12 ) ;
int V_209 , V_210 ;
int V_211 ;
T_10 V_53 ;
int V_212 ;
struct V_213 V_107 ;
F_104 ( V_28 , V_214 ) ;
F_57 ( & V_107 , V_108 ) ;
if ( ! F_48 ( V_19 -> V_13 ) ) {
F_105 ( V_2 , V_207 , F_62 ( V_2 , V_40 , V_208 ) ,
V_2 -> V_110 , & V_107 ) ;
return;
}
ASSERT ( sizeof( V_19 -> V_13 ) <= sizeof( V_28 [ 0 ] ) ) ;
V_28 [ 0 ] = V_19 -> V_13 ;
V_209 = V_210 = F_106 ( V_28 ,
V_214 ) ;
V_211 = V_209 + 1 ;
while ( V_209 < V_214 ) {
V_211 = F_107 ( V_28 , V_214 ,
V_211 ) ;
if ( V_211 != V_214 &&
V_211 == V_210 + 1 ) {
V_210 = V_211 ;
goto V_215;
}
V_53 = V_208 + ( V_209 * V_91 ) /
V_2 -> V_3 . V_216 ;
V_212 = ( ( V_210 - V_209 + 1 ) *
V_91 ) /
V_2 -> V_3 . V_216 ;
ASSERT ( V_53 % V_2 -> V_3 . V_132 == 0 ) ;
ASSERT ( V_212 % V_2 -> V_3 . V_132 == 0 ) ;
F_105 ( V_2 , V_207 , F_62 ( V_2 , V_40 , V_53 ) ,
V_212 , & V_107 ) ;
V_209 = V_210 = V_211 ;
V_215:
V_211 ++ ;
}
}
STATIC int
F_108 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_1 V_171 ,
struct V_206 * V_207 ,
struct V_217 * V_218 ,
struct V_25 * V_219 )
{
struct V_38 * V_39 = F_21 ( V_34 ) ;
T_9 V_40 = F_13 ( V_39 -> V_41 ) ;
struct V_101 * V_102 ;
struct V_5 * V_6 ;
struct V_25 V_19 ;
int V_220 ;
int error ;
int V_11 ;
int V_221 ;
ASSERT ( V_39 -> V_222 == F_7 ( V_223 ) ) ;
ASSERT ( F_46 ( V_2 , V_171 ) < F_13 ( V_39 -> V_119 ) ) ;
V_6 = F_22 ( V_2 , V_32 , V_34 , V_40 , V_137 ) ;
error = F_24 ( V_6 , V_39 ) ;
if ( error )
goto V_178;
if ( ( error = F_4 ( V_6 , V_171 , V_181 , & V_11 ) ) ) {
F_109 ( V_2 , L_2 ,
V_224 , error ) ;
goto V_178;
}
F_52 ( V_2 , V_11 == 1 , V_178 ) ;
error = F_16 ( V_6 , & V_19 , & V_11 ) ;
if ( error ) {
F_109 ( V_2 , L_3 ,
V_224 , error ) ;
goto V_178;
}
F_52 ( V_2 , V_11 == 1 , V_178 ) ;
V_221 = V_171 - V_19 . V_12 ;
ASSERT ( V_221 >= 0 && V_221 < V_27 ) ;
ASSERT ( ! ( V_19 . V_16 & F_94 ( V_221 ) ) ) ;
V_19 . V_16 |= F_94 ( V_221 ) ;
V_19 . V_15 ++ ;
if ( ! ( V_2 -> V_127 & V_225 ) &&
V_19 . V_16 == V_45 &&
V_2 -> V_3 . V_216 <= V_27 ) {
V_218 -> V_226 = true ;
V_218 -> V_227 = F_29 ( V_2 , V_40 , V_19 . V_12 ) ;
V_218 -> V_99 = F_49 ( & V_19 ) ;
V_220 = V_19 . V_15 ;
F_69 ( & V_39 -> V_141 , - V_220 ) ;
F_69 ( & V_39 -> V_49 , - ( V_220 - 1 ) ) ;
F_72 ( V_32 , V_34 , V_143 | V_144 ) ;
V_102 = F_70 ( V_2 , V_40 ) ;
V_102 -> V_142 -= V_220 - 1 ;
F_71 ( V_102 ) ;
F_73 ( V_32 , V_146 , - V_220 ) ;
F_73 ( V_32 , V_147 , - ( V_220 - 1 ) ) ;
if ( ( error = F_99 ( V_6 , & V_11 ) ) ) {
F_109 ( V_2 , L_4 ,
V_224 , error ) ;
goto V_178;
}
F_103 ( V_2 , V_40 , & V_19 , V_207 ) ;
} else {
V_218 -> V_226 = false ;
error = F_6 ( V_6 , & V_19 ) ;
if ( error ) {
F_109 ( V_2 , L_5 ,
V_224 , error ) ;
goto V_178;
}
F_69 ( & V_39 -> V_49 , 1 ) ;
F_72 ( V_32 , V_34 , V_144 ) ;
V_102 = F_70 ( V_2 , V_40 ) ;
V_102 -> V_142 ++ ;
F_71 ( V_102 ) ;
F_73 ( V_32 , V_147 , 1 ) ;
}
error = F_24 ( V_6 , V_39 ) ;
if ( error )
goto V_178;
* V_219 = V_19 ;
F_23 ( V_6 , V_46 ) ;
return 0 ;
V_178:
F_23 ( V_6 , V_44 ) ;
return error ;
}
STATIC int
F_110 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_1 V_171 ,
struct V_25 * V_228 )
{
struct V_38 * V_39 = F_21 ( V_34 ) ;
T_9 V_40 = F_13 ( V_39 -> V_41 ) ;
struct V_5 * V_6 ;
struct V_25 V_19 ;
int V_90 = V_171 - V_228 -> V_12 ;
int error ;
int V_11 ;
V_6 = F_22 ( V_2 , V_32 , V_34 , V_40 , V_140 ) ;
error = F_4 ( V_6 , V_228 -> V_12 , V_43 , & V_11 ) ;
if ( error )
goto error;
if ( V_11 == 0 ) {
F_52 ( V_2 , V_228 -> V_15 == 1 , error ) ;
error = F_18 ( V_6 , V_228 -> V_13 ,
V_228 -> V_14 ,
V_228 -> V_15 ,
V_228 -> V_16 , & V_11 ) ;
if ( error )
goto error;
ASSERT ( V_11 == 1 ) ;
goto V_98;
}
error = F_16 ( V_6 , & V_19 , & V_11 ) ;
if ( error )
goto error;
F_52 ( V_2 , V_11 == 1 , error ) ;
V_19 . V_16 |= F_94 ( V_90 ) ;
V_19 . V_15 ++ ;
F_52 ( V_2 , ( V_19 . V_16 == V_228 -> V_16 ) &&
( V_19 . V_15 == V_228 -> V_15 ) ,
error ) ;
if ( V_19 . V_16 == V_45 &&
V_2 -> V_3 . V_216 <= V_27 &&
! ( V_2 -> V_127 & V_225 ) ) {
error = F_99 ( V_6 , & V_11 ) ;
if ( error )
goto error;
ASSERT ( V_11 == 1 ) ;
} else {
error = F_6 ( V_6 , & V_19 ) ;
if ( error )
goto error;
}
V_98:
error = F_24 ( V_6 , V_39 ) ;
if ( error )
goto error;
F_23 ( V_6 , V_46 ) ;
return 0 ;
error:
F_23 ( V_6 , V_44 ) ;
return error ;
}
int
F_111 (
struct V_31 * V_32 ,
T_12 V_229 ,
struct V_206 * V_207 ,
struct V_217 * V_218 )
{
T_10 V_53 ;
struct V_33 * V_34 ;
T_1 V_171 ;
T_9 V_40 ;
int error ;
struct V_1 * V_2 ;
struct V_25 V_19 ;
V_2 = V_32 -> V_104 ;
V_40 = F_81 ( V_2 , V_229 ) ;
if ( V_40 >= V_2 -> V_3 . V_205 ) {
F_109 ( V_2 , L_6 ,
V_224 , V_40 , V_2 -> V_3 . V_205 ) ;
ASSERT ( 0 ) ;
return - V_230 ;
}
V_171 = F_91 ( V_2 , V_229 ) ;
if ( V_229 != F_29 ( V_2 , V_40 , V_171 ) ) {
F_109 ( V_2 , L_7 ,
V_224 , ( unsigned long long ) V_229 ,
( unsigned long long ) F_29 ( V_2 , V_40 , V_171 ) ) ;
ASSERT ( 0 ) ;
return - V_230 ;
}
V_53 = F_46 ( V_2 , V_171 ) ;
if ( V_53 >= V_2 -> V_3 . V_135 ) {
F_109 ( V_2 , L_8 ,
V_224 , V_53 , V_2 -> V_3 . V_135 ) ;
ASSERT ( 0 ) ;
return - V_230 ;
}
error = F_101 ( V_2 , V_32 , V_40 , & V_34 ) ;
if ( error ) {
F_109 ( V_2 , L_9 ,
V_224 , error ) ;
return error ;
}
error = F_108 ( V_2 , V_32 , V_34 , V_171 , V_207 , V_218 , & V_19 ) ;
if ( error )
goto V_178;
if ( F_68 ( & V_2 -> V_3 ) ) {
error = F_110 ( V_2 , V_32 , V_34 , V_171 , & V_19 ) ;
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
T_1 V_171 ,
T_10 V_53 ,
T_10 * V_231 ,
T_10 * V_232 ,
int V_155 )
{
struct V_25 V_19 ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
int error ;
int V_11 ;
error = F_101 ( V_2 , V_32 , V_40 , & V_34 ) ;
if ( error ) {
F_66 ( V_2 ,
L_10 ,
V_224 , error , V_40 ) ;
return error ;
}
V_6 = F_22 ( V_2 , V_32 , V_34 , V_40 , V_137 ) ;
error = F_4 ( V_6 , V_171 , V_181 , & V_11 ) ;
if ( ! error ) {
if ( V_11 )
error = F_16 ( V_6 , & V_19 , & V_11 ) ;
if ( ! error && V_11 == 0 )
error = - V_230 ;
}
F_102 ( V_32 , V_34 ) ;
F_23 ( V_6 , error ? V_44 : V_46 ) ;
if ( error )
return error ;
if ( V_19 . V_12 > V_171 ||
V_19 . V_12 + V_2 -> V_111 <= V_171 )
return - V_230 ;
if ( ( V_155 & V_233 ) &&
( V_19 . V_16 & F_94 ( V_171 - V_19 . V_12 ) ) )
return - V_230 ;
* V_231 = F_46 ( V_2 , V_19 . V_12 ) ;
* V_232 = V_53 - * V_231 ;
return 0 ;
}
int
F_113 (
T_19 * V_2 ,
T_15 * V_32 ,
T_12 V_7 ,
struct F_113 * V_234 ,
T_13 V_155 )
{
T_10 V_53 ;
T_1 V_171 ;
T_9 V_40 ;
int V_59 ;
T_10 V_231 ;
T_10 V_235 ;
int error ;
int V_90 ;
T_10 V_232 ;
ASSERT ( V_7 != V_202 ) ;
V_40 = F_81 ( V_2 , V_7 ) ;
V_171 = F_91 ( V_2 , V_7 ) ;
V_53 = F_46 ( V_2 , V_171 ) ;
if ( V_40 >= V_2 -> V_3 . V_205 || V_53 >= V_2 -> V_3 . V_135 ||
V_7 != F_29 ( V_2 , V_40 , V_171 ) ) {
#ifdef F_58
if ( V_155 & V_233 )
return - V_230 ;
if ( V_40 >= V_2 -> V_3 . V_205 ) {
F_66 ( V_2 ,
L_11 ,
V_224 , V_40 , V_2 -> V_3 . V_205 ) ;
}
if ( V_53 >= V_2 -> V_3 . V_135 ) {
F_66 ( V_2 ,
L_12 ,
V_224 , ( unsigned long long ) V_53 ,
( unsigned long ) V_2 -> V_3 . V_135 ) ;
}
if ( V_7 != F_29 ( V_2 , V_40 , V_171 ) ) {
F_66 ( V_2 ,
L_13 ,
V_224 , V_7 ,
F_29 ( V_2 , V_40 , V_171 ) ) ;
}
F_114 () ;
#endif
return - V_230 ;
}
V_59 = F_3 ( V_2 ) ;
if ( V_155 & V_233 ) {
error = F_112 ( V_2 , V_32 , V_40 , V_171 , V_53 ,
& V_231 , & V_232 , V_155 ) ;
if ( error )
return error ;
goto V_236;
}
if ( V_59 == 1 ) {
V_90 = F_115 ( V_2 , V_7 ) ;
ASSERT ( V_90 < V_2 -> V_3 . V_216 ) ;
V_234 -> V_237 = F_32 ( V_2 , V_40 , V_53 ) ;
V_234 -> V_238 = F_116 ( V_2 , 1 ) ;
V_234 -> V_239 = ( unsigned short ) ( V_90 <<
V_2 -> V_3 . V_74 ) ;
return 0 ;
}
if ( V_2 -> V_240 ) {
V_232 = V_53 & V_2 -> V_240 ;
V_231 = V_53 - V_232 ;
} else {
error = F_112 ( V_2 , V_32 , V_40 , V_171 , V_53 ,
& V_231 , & V_232 , V_155 ) ;
if ( error )
return error ;
}
V_236:
ASSERT ( V_53 >= V_231 ) ;
V_235 = V_231 +
( ( V_232 / V_59 ) * V_59 ) ;
V_90 = ( ( V_53 - V_235 ) * V_2 -> V_3 . V_216 ) +
F_115 ( V_2 , V_7 ) ;
V_234 -> V_237 = F_32 ( V_2 , V_40 , V_235 ) ;
V_234 -> V_238 = F_116 ( V_2 , V_59 ) ;
V_234 -> V_239 = ( unsigned short ) ( V_90 << V_2 -> V_3 . V_74 ) ;
if ( ( V_234 -> V_237 + V_234 -> V_238 ) >
F_116 ( V_2 , V_2 -> V_3 . V_241 ) ) {
F_66 ( V_2 ,
L_14 ,
V_224 , ( unsigned long long ) V_234 -> V_237 ,
( unsigned long long ) V_234 -> V_238 ,
F_116 ( V_2 , V_2 -> V_3 . V_241 ) ) ;
return - V_230 ;
}
return 0 ;
}
void
F_117 (
T_19 * V_2 )
{
T_13 V_242 ;
V_242 = ( 1LL << F_118 ( V_2 ) ) >> V_243 ;
V_2 -> V_125 = F_119 ( V_2 , V_2 -> V_244 ,
V_242 ) ;
}
void
F_72 (
T_15 * V_32 ,
T_16 * V_245 ,
int V_246 )
{
int V_247 ;
int V_248 ;
static const short V_249 [] = {
F_120 ( T_17 , V_222 ) ,
F_120 ( T_17 , V_250 ) ,
F_120 ( T_17 , V_41 ) ,
F_120 ( T_17 , V_119 ) ,
F_120 ( T_17 , V_141 ) ,
F_120 ( T_17 , V_130 ) ,
F_120 ( T_17 , V_251 ) ,
F_120 ( T_17 , V_49 ) ,
F_120 ( T_17 , V_117 ) ,
F_120 ( T_17 , V_252 ) ,
F_120 ( T_17 , V_253 ) ,
F_120 ( T_17 , V_254 ) ,
F_120 ( T_17 , V_255 ) ,
sizeof( T_17 )
} ;
#ifdef F_58
T_17 * V_39 ;
V_39 = F_21 ( V_245 ) ;
ASSERT ( V_39 -> V_222 == F_7 ( V_223 ) ) ;
#endif
if ( V_246 & V_256 ) {
F_121 ( V_246 , V_249 , V_257 ,
& V_247 , & V_248 ) ;
F_40 ( V_32 , V_245 , V_247 , V_248 ) ;
}
V_246 &= ~ V_256 ;
if ( V_246 ) {
F_121 ( V_246 , V_249 , V_258 ,
& V_247 , & V_248 ) ;
F_40 ( V_32 , V_245 , V_247 , V_248 ) ;
}
}
STATIC void
F_122 (
struct V_38 * V_39 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_259 ; V_11 ++ )
ASSERT ( V_39 -> V_253 [ V_11 ] ) ;
}
static bool
F_123 (
struct V_33 * V_245 )
{
struct V_1 * V_2 = V_245 -> V_260 -> V_261 ;
struct V_38 * V_39 = F_21 ( V_245 ) ;
if ( F_28 ( & V_2 -> V_3 ) ) {
if ( ! F_124 ( & V_39 -> V_262 , & V_2 -> V_3 . V_84 ) )
return false ;
if ( ! F_125 ( V_2 ,
F_15 ( F_21 ( V_245 ) -> V_263 ) ) )
return false ;
}
if ( V_39 -> V_222 != F_7 ( V_223 ) )
return false ;
if ( ! F_126 ( F_13 ( V_39 -> V_250 ) ) )
return false ;
if ( F_13 ( V_39 -> V_251 ) < 1 ||
F_13 ( V_39 -> V_251 ) > V_264 )
return false ;
if ( F_68 ( & V_2 -> V_3 ) &&
( F_13 ( V_39 -> V_255 ) < 1 ||
F_13 ( V_39 -> V_255 ) > V_264 ) )
return false ;
if ( V_245 -> V_265 && F_13 ( V_39 -> V_41 ) != V_245 -> V_265 -> V_266 )
return false ;
F_122 ( V_39 ) ;
return true ;
}
static void
F_127 (
struct V_33 * V_245 )
{
struct V_1 * V_2 = V_245 -> V_260 -> V_261 ;
if ( F_28 ( & V_2 -> V_3 ) &&
! F_128 ( V_245 , V_267 ) )
F_129 ( V_245 , - V_268 ) ;
else if ( F_130 ( ! F_123 ( V_245 ) , V_2 ,
V_269 ) )
F_129 ( V_245 , - V_138 ) ;
if ( V_245 -> V_270 )
F_131 ( V_245 ) ;
}
static void
F_132 (
struct V_33 * V_245 )
{
struct V_1 * V_2 = V_245 -> V_260 -> V_261 ;
struct V_271 * V_272 = V_245 -> V_273 ;
if ( ! F_123 ( V_245 ) ) {
F_129 ( V_245 , - V_138 ) ;
F_131 ( V_245 ) ;
return;
}
if ( ! F_28 ( & V_2 -> V_3 ) )
return;
if ( V_272 )
F_21 ( V_245 ) -> V_263 = F_10 ( V_272 -> V_274 . V_275 ) ;
F_133 ( V_245 , V_267 ) ;
}
int
F_134 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_9 V_40 ,
struct V_33 * * V_276 )
{
int error ;
F_135 ( V_2 , V_40 ) ;
ASSERT ( V_40 != V_168 ) ;
error = F_136 ( V_2 , V_32 , V_2 -> V_66 ,
F_137 ( V_2 , V_40 , F_138 ( V_2 ) ) ,
F_139 ( V_2 , 1 ) , 0 , V_276 , & V_277 ) ;
if ( error )
return error ;
if ( V_32 )
F_140 ( V_32 , * V_276 , V_278 ) ;
F_141 ( * V_276 , V_279 ) ;
return 0 ;
}
int
F_101 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_9 V_40 ,
struct V_33 * * V_276 )
{
struct V_38 * V_39 ;
struct V_101 * V_102 ;
int error ;
F_142 ( V_2 , V_40 ) ;
error = F_134 ( V_2 , V_32 , V_40 , V_276 ) ;
if ( error )
return error ;
V_39 = F_21 ( * V_276 ) ;
V_102 = F_70 ( V_2 , V_40 ) ;
if ( ! V_102 -> V_163 ) {
V_102 -> V_142 = F_13 ( V_39 -> V_49 ) ;
V_102 -> V_280 = F_13 ( V_39 -> V_141 ) ;
V_102 -> V_163 = 1 ;
}
ASSERT ( V_102 -> V_142 == F_13 ( V_39 -> V_49 ) ||
F_26 ( V_2 ) ) ;
F_71 ( V_102 ) ;
return 0 ;
}
int
F_82 (
T_19 * V_2 ,
T_15 * V_32 ,
T_9 V_40 )
{
T_16 * V_245 = NULL ;
int error ;
error = F_101 ( V_2 , V_32 , V_40 , & V_245 ) ;
if ( error )
return error ;
if ( V_245 )
F_102 ( V_32 , V_245 ) ;
return 0 ;
}
