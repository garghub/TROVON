static inline int
F_1 (
T_1 * args )
{
if ( F_2 ( & args -> V_1 -> V_2 ) &&
args -> V_1 -> V_2 . V_3 >=
F_3 ( args -> V_1 , args -> V_1 -> V_4 ) )
return args -> V_1 -> V_2 . V_3 ;
return 1 ;
}
int
F_4 (
struct V_5 * V_6 ,
T_2 V_7 ,
T_3 V_8 ,
int * V_9 )
{
V_6 -> V_10 . V_11 . V_12 = V_7 ;
V_6 -> V_10 . V_11 . V_13 = 0 ;
V_6 -> V_10 . V_11 . V_14 = 0 ;
return F_5 ( V_6 , V_8 , V_9 ) ;
}
STATIC int
F_6 (
struct V_5 * V_6 ,
T_4 * V_15 )
{
union V_16 V_17 ;
V_17 . V_18 . V_12 = F_7 ( V_15 -> V_12 ) ;
V_17 . V_18 . V_13 = F_7 ( V_15 -> V_13 ) ;
V_17 . V_18 . V_14 = F_8 ( V_15 -> V_14 ) ;
return F_9 ( V_6 , & V_17 ) ;
}
int
F_10 (
struct V_5 * V_6 ,
T_4 * V_15 ,
int * V_9 )
{
union V_16 * V_17 ;
int error ;
error = F_11 ( V_6 , & V_17 , V_9 ) ;
if ( ! error && * V_9 == 1 ) {
V_15 -> V_12 = F_12 ( V_17 -> V_18 . V_12 ) ;
V_15 -> V_13 = F_12 ( V_17 -> V_18 . V_13 ) ;
V_15 -> V_14 = F_13 ( V_17 -> V_18 . V_14 ) ;
}
return error ;
}
STATIC int
F_14 (
struct V_5 * V_6 ,
struct V_19 * V_20 )
{
if ( V_6 -> V_21 == 1 ) {
T_4 V_17 ;
int V_22 = 0 ;
int error ;
int V_11 ;
error = F_4 ( V_6 , 0 , V_23 , & V_11 ) ;
if ( error )
return error ;
do {
error = F_10 ( V_6 , & V_17 , & V_11 ) ;
if ( error )
return error ;
if ( V_11 ) {
V_22 += V_17 . V_13 ;
error = F_15 ( V_6 , 0 , & V_11 ) ;
if ( error )
return error ;
}
} while ( V_11 == 1 );
if ( ! F_16 ( V_6 -> V_24 ) )
ASSERT ( V_22 == F_12 ( V_20 -> V_25 ) ) ;
}
return 0 ;
}
int
F_17 (
struct V_26 * V_1 ,
struct V_27 * V_28 ,
struct V_29 * V_30 ,
T_5 V_31 ,
T_6 V_32 ,
T_6 V_33 ,
unsigned int V_34 )
{
struct V_35 * V_36 ;
struct V_37 * free ;
int V_38 , V_39 , V_40 ;
int V_41 ;
int V_11 , V_42 ;
T_7 V_43 ;
T_8 V_7 = 0 ;
V_39 = F_18 ( V_1 ) ;
V_40 = V_39 << V_1 -> V_2 . V_44 ;
V_38 = V_33 / V_39 ;
if ( F_19 ( & V_1 -> V_2 ) ) {
V_41 = 3 ;
V_7 = F_20 ( V_1 , V_31 ,
F_21 ( V_1 , V_32 , 0 ) ) ;
if ( V_28 )
F_22 ( V_28 , V_31 , V_32 , V_1 -> V_45 ,
V_1 -> V_2 . V_46 , V_33 , V_34 ) ;
} else if ( F_23 ( & V_1 -> V_2 ) )
V_41 = 2 ;
else
V_41 = 1 ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ ) {
V_43 = F_24 ( V_1 , V_31 , V_32 + ( V_42 * V_39 ) ) ;
V_36 = F_25 ( V_28 , V_1 -> V_47 , V_43 ,
V_1 -> V_48 * V_39 ,
V_49 ) ;
if ( ! V_36 )
return V_50 ;
V_36 -> V_51 = & V_52 ;
F_26 ( V_36 , 0 , F_27 ( V_36 -> V_53 ) ) ;
for ( V_11 = 0 ; V_11 < V_40 ; V_11 ++ ) {
int V_54 = V_11 << V_1 -> V_2 . V_55 ;
T_9 V_56 = F_28 ( V_41 ) ;
free = F_29 ( V_1 , V_36 , V_11 ) ;
free -> V_57 = F_30 ( V_58 ) ;
free -> V_59 = V_41 ;
free -> V_60 = F_7 ( V_34 ) ;
free -> V_61 = F_7 ( V_62 ) ;
if ( V_41 == 3 ) {
free -> V_63 = F_8 ( V_7 ) ;
V_7 ++ ;
F_31 ( & free -> V_64 , & V_1 -> V_2 . V_65 ) ;
F_32 ( V_1 , free ) ;
} else if ( V_28 ) {
F_33 ( V_28 , V_36 , V_54 ,
V_54 + V_56 - 1 ) ;
}
}
if ( V_28 ) {
F_34 ( V_28 , V_36 ) ;
if ( V_41 == 3 ) {
F_35 ( V_28 , V_36 ) ;
F_33 ( V_28 , V_36 , 0 ,
F_27 ( V_36 -> V_53 ) - 1 ) ;
}
} else {
V_36 -> V_66 |= V_67 ;
F_36 ( V_36 , V_30 ) ;
F_37 ( V_36 ) ;
}
}
return 0 ;
}
STATIC int
F_38 (
T_10 * V_28 ,
T_11 * V_68 ,
int * V_69 )
{
T_12 * V_20 ;
T_1 args ;
T_13 * V_6 ;
T_5 V_31 ;
int error ;
int V_11 ;
T_2 V_70 ;
T_2 V_71 ;
T_2 V_72 ;
int V_73 = 0 ;
struct V_74 * V_75 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_28 = V_28 ;
args . V_1 = V_28 -> V_76 ;
V_71 = args . V_1 -> V_45 ;
if ( args . V_1 -> V_77 &&
args . V_1 -> V_2 . V_78 + V_71 > args . V_1 -> V_77 )
return F_39 ( V_79 ) ;
args . V_80 = args . V_81 = args . V_1 -> V_82 ;
V_20 = F_40 ( V_68 ) ;
V_70 = F_12 ( V_20 -> V_83 ) ;
V_31 = F_12 ( V_20 -> V_84 ) ;
args . V_32 = F_41 ( args . V_1 , V_70 ) +
args . V_1 -> V_82 ;
if ( F_42 ( V_70 != V_62 &&
( args . V_32 < F_12 ( V_20 -> V_85 ) ) ) ) {
args . V_86 = F_43 ( args . V_1 , V_31 , args . V_32 ) ;
args . type = V_87 ;
args . V_88 = 1 ;
args . V_89 = 1 ;
args . V_90 = F_1 ( & args ) - 1 ;
args . V_91 = args . V_1 -> V_92 - 1 ;
if ( ( error = F_44 ( & args ) ) )
return error ;
} else
args . V_86 = V_93 ;
if ( F_45 ( args . V_86 == V_93 ) ) {
V_73 = 0 ;
if ( args . V_1 -> V_94 ) {
ASSERT ( ! ( args . V_1 -> V_95 & V_96 ) ) ;
args . V_89 = args . V_1 -> V_97 ;
V_73 = 1 ;
} else
args . V_89 = F_1 ( & args ) ;
args . V_32 = F_12 ( V_20 -> V_98 ) ;
args . V_86 = F_43 ( args . V_1 , V_31 , args . V_32 ) ;
args . type = V_99 ;
args . V_88 = 1 ;
args . V_91 = args . V_1 -> V_92 - 1 ;
if ( ( error = F_44 ( & args ) ) )
return error ;
}
if ( V_73 && args . V_86 == V_93 ) {
args . type = V_99 ;
args . V_32 = F_12 ( V_20 -> V_98 ) ;
args . V_86 = F_43 ( args . V_1 , V_31 , args . V_32 ) ;
args . V_89 = F_1 ( & args ) ;
if ( ( error = F_44 ( & args ) ) )
return error ;
}
if ( args . V_86 == V_93 ) {
* V_69 = 0 ;
return 0 ;
}
ASSERT ( args . V_100 == args . V_80 ) ;
error = F_17 ( args . V_1 , V_28 , NULL , V_31 , args . V_32 ,
args . V_100 , F_46 () ) ;
if ( error )
return error ;
V_70 = F_21 ( args . V_1 , args . V_32 , 0 ) ;
F_47 ( & V_20 -> V_101 , V_71 ) ;
F_47 ( & V_20 -> V_25 , V_71 ) ;
V_75 = F_48 ( args . V_1 , V_31 ) ;
V_75 -> V_102 += V_71 ;
F_49 ( V_75 ) ;
V_20 -> V_83 = F_7 ( V_70 ) ;
V_6 = F_50 ( args . V_1 , V_28 , V_68 , V_31 ) ;
for ( V_72 = V_70 ;
V_72 < V_70 + V_71 ;
V_72 += V_103 ) {
V_6 -> V_10 . V_11 . V_12 = V_72 ;
V_6 -> V_10 . V_11 . V_13 = V_103 ;
V_6 -> V_10 . V_11 . V_14 = V_104 ;
error = F_5 ( V_6 , V_105 , & V_11 ) ;
if ( error ) {
F_51 ( V_6 , V_106 ) ;
return error ;
}
ASSERT ( V_11 == 0 ) ;
error = F_52 ( V_6 , & V_11 ) ;
if ( error ) {
F_51 ( V_6 , V_106 ) ;
return error ;
}
ASSERT ( V_11 == 1 ) ;
}
F_51 ( V_6 , V_107 ) ;
F_53 ( V_28 , V_68 ,
V_108 | V_109 | V_110 ) ;
F_54 ( V_28 , V_111 , ( long ) V_71 ) ;
F_54 ( V_28 , V_112 , ( long ) V_71 ) ;
* V_69 = 1 ;
return 0 ;
}
STATIC T_5
F_55 (
T_14 * V_1 )
{
T_5 V_31 ;
F_56 ( & V_1 -> V_113 ) ;
V_31 = V_1 -> V_114 ;
if ( ++ V_1 -> V_114 >= V_1 -> V_115 )
V_1 -> V_114 = 0 ;
F_57 ( & V_1 -> V_113 ) ;
return V_31 ;
}
STATIC T_5
F_58 (
T_10 * V_28 ,
T_8 V_116 ,
T_15 V_117 ,
int V_118 )
{
T_5 V_119 ;
T_5 V_31 ;
int V_120 ;
T_16 V_121 ;
T_16 V_122 = 0 ;
T_14 * V_1 ;
int V_123 ;
T_17 * V_75 ;
T_5 V_124 ;
int error ;
V_123 = F_59 ( V_117 ) || F_60 ( V_117 ) || F_61 ( V_117 ) ;
V_1 = V_28 -> V_76 ;
V_119 = V_1 -> V_115 ;
if ( F_59 ( V_117 ) )
V_124 = F_55 ( V_1 ) ;
else {
V_124 = F_62 ( V_1 , V_116 ) ;
if ( V_124 >= V_119 )
V_124 = 0 ;
}
ASSERT ( V_124 < V_119 ) ;
V_31 = V_124 ;
V_120 = V_125 ;
for (; ; ) {
V_75 = F_48 ( V_1 , V_31 ) ;
if ( ! V_75 -> V_126 ) {
F_55 ( V_1 ) ;
goto V_127;
}
if ( ! V_75 -> V_128 ) {
error = F_63 ( V_1 , V_28 , V_31 ) ;
if ( error )
goto V_127;
}
if ( V_75 -> V_102 ) {
F_49 ( V_75 ) ;
return V_31 ;
}
if ( ! V_118 )
goto V_127;
if ( ! V_75 -> V_129 ) {
error = F_64 ( V_1 , V_28 , V_31 , V_120 ) ;
if ( error )
goto V_127;
}
V_121 = V_1 -> V_82 ;
V_122 = V_75 -> V_130 ;
if ( ! V_122 )
V_122 = V_75 -> V_131 > 0 ;
if ( V_75 -> V_132 >= V_123 + V_121 &&
V_122 >= V_121 ) {
F_49 ( V_75 ) ;
return V_31 ;
}
V_127:
F_49 ( V_75 ) ;
if ( F_16 ( V_1 ) )
return V_133 ;
V_31 ++ ;
if ( V_31 >= V_119 )
V_31 = 0 ;
if ( V_31 == V_124 ) {
if ( V_120 == 0 )
return V_133 ;
V_120 = 0 ;
}
}
}
STATIC int
F_65 (
struct V_5 * V_6 ,
T_4 * V_17 ,
int * V_134 ,
int V_135 )
{
int error ;
int V_11 ;
if ( V_135 )
error = F_66 ( V_6 , 0 , & V_11 ) ;
else
error = F_15 ( V_6 , 0 , & V_11 ) ;
if ( error )
return error ;
* V_134 = ! V_11 ;
if ( V_11 ) {
error = F_10 ( V_6 , V_17 , & V_11 ) ;
if ( error )
return error ;
F_67 ( V_11 == 1 ) ;
}
return 0 ;
}
STATIC int
F_68 (
struct V_5 * V_6 ,
T_2 V_136 ,
T_4 * V_17 ,
int * V_134 )
{
int error ;
int V_11 ;
error = F_4 ( V_6 , V_136 , V_105 , & V_11 ) ;
if ( error )
return error ;
* V_134 = ! V_11 ;
if ( V_11 ) {
error = F_10 ( V_6 , V_17 , & V_11 ) ;
if ( error )
return error ;
F_67 ( V_11 == 1 ) ;
}
return 0 ;
}
STATIC int
F_69 (
struct V_27 * V_28 ,
struct V_35 * V_68 ,
T_8 V_116 ,
T_8 * V_137 )
{
struct V_26 * V_1 = V_28 -> V_76 ;
struct V_19 * V_20 = F_40 ( V_68 ) ;
T_5 V_31 = F_12 ( V_20 -> V_84 ) ;
T_5 V_124 = F_62 ( V_1 , V_116 ) ;
T_2 V_138 = F_70 ( V_1 , V_116 ) ;
struct V_74 * V_75 ;
struct V_5 * V_6 , * V_139 ;
struct V_140 V_17 , V_141 ;
T_8 V_7 ;
int error ;
int V_142 ;
int V_11 , V_42 ;
V_75 = F_48 ( V_1 , V_31 ) ;
ASSERT ( V_75 -> V_128 ) ;
ASSERT ( V_75 -> V_126 ) ;
ASSERT ( V_75 -> V_102 > 0 ) ;
V_143:
V_6 = F_50 ( V_1 , V_28 , V_68 , V_31 ) ;
if ( ! V_138 )
V_138 = F_12 ( V_20 -> V_83 ) ;
error = F_14 ( V_6 , V_20 ) ;
if ( error )
goto V_144;
if ( V_124 == V_31 ) {
int V_145 ;
int V_146 ;
int V_147 = 10 ;
error = F_4 ( V_6 , V_138 , V_148 , & V_11 ) ;
if ( error )
goto V_144;
F_71 ( V_11 == 1 , V_144 ) ;
error = F_10 ( V_6 , & V_17 , & V_42 ) ;
if ( error )
goto V_144;
F_71 ( V_42 == 1 , V_144 ) ;
if ( V_17 . V_13 > 0 ) {
goto V_149;
}
error = F_72 ( V_6 , & V_139 ) ;
if ( error )
goto V_144;
if ( V_138 != V_62 &&
V_75 -> V_150 == V_138 &&
V_75 -> V_151 != V_62 &&
V_75 -> V_152 != V_62 ) {
error = F_68 ( V_139 , V_75 -> V_151 ,
& V_141 , & V_145 ) ;
if ( error )
goto V_153;
error = F_68 ( V_6 , V_75 -> V_152 ,
& V_17 , & V_146 ) ;
if ( error )
goto V_153;
} else {
error = F_65 ( V_139 , & V_141 , & V_145 , 1 ) ;
if ( error )
goto V_153;
error = F_65 ( V_6 , & V_17 , & V_146 , 0 ) ;
if ( error )
goto V_153;
}
while ( ! V_145 || ! V_146 ) {
int V_154 ;
if ( ! -- V_147 ) {
F_51 ( V_139 , V_107 ) ;
V_75 -> V_151 = V_141 . V_12 ;
V_75 -> V_152 = V_17 . V_12 ;
V_75 -> V_150 = V_138 ;
goto V_70;
}
if ( ! V_145 && ! V_146 ) {
V_154 = V_138 -
( V_141 . V_12 + V_103 - 1 ) <
V_17 . V_12 - V_138 ;
} else {
V_154 = ! V_145 ;
}
if ( V_154 && V_141 . V_13 ) {
V_17 = V_141 ;
F_51 ( V_6 , V_107 ) ;
V_6 = V_139 ;
V_75 -> V_151 = V_141 . V_12 ;
V_75 -> V_152 = V_17 . V_12 ;
V_75 -> V_150 = V_138 ;
goto V_149;
}
if ( ! V_154 && V_17 . V_13 ) {
F_51 ( V_139 , V_107 ) ;
V_75 -> V_151 = V_141 . V_12 ;
V_75 -> V_152 = V_17 . V_12 ;
V_75 -> V_150 = V_138 ;
goto V_149;
}
if ( V_154 ) {
error = F_65 ( V_139 , & V_141 ,
& V_145 , 1 ) ;
} else {
error = F_65 ( V_6 , & V_17 ,
& V_146 , 0 ) ;
}
if ( error )
goto V_153;
}
V_75 -> V_150 = V_62 ;
V_75 -> V_151 = V_62 ;
V_75 -> V_152 = V_62 ;
F_51 ( V_139 , V_107 ) ;
F_51 ( V_6 , V_107 ) ;
goto V_143;
}
V_70:
if ( V_20 -> V_83 != F_7 ( V_62 ) ) {
error = F_4 ( V_6 , F_12 ( V_20 -> V_83 ) ,
V_105 , & V_11 ) ;
if ( error )
goto V_144;
if ( V_11 == 1 ) {
error = F_10 ( V_6 , & V_17 , & V_42 ) ;
if ( error )
goto V_144;
if ( V_42 == 1 && V_17 . V_13 > 0 ) {
goto V_149;
}
}
}
error = F_4 ( V_6 , 0 , V_23 , & V_11 ) ;
if ( error )
goto V_144;
F_71 ( V_11 == 1 , V_144 ) ;
for (; ; ) {
error = F_10 ( V_6 , & V_17 , & V_11 ) ;
if ( error )
goto V_144;
F_71 ( V_11 == 1 , V_144 ) ;
if ( V_17 . V_13 > 0 )
break;
error = F_15 ( V_6 , 0 , & V_11 ) ;
if ( error )
goto V_144;
F_71 ( V_11 == 1 , V_144 ) ;
}
V_149:
V_142 = F_73 ( V_17 . V_14 ) ;
ASSERT ( V_142 >= 0 ) ;
ASSERT ( V_142 < V_103 ) ;
ASSERT ( ( F_74 ( V_1 , V_17 . V_12 ) %
V_103 ) == 0 ) ;
V_7 = F_20 ( V_1 , V_31 , V_17 . V_12 + V_142 ) ;
V_17 . V_14 &= ~ F_75 ( V_142 ) ;
V_17 . V_13 -- ;
error = F_6 ( V_6 , & V_17 ) ;
if ( error )
goto V_144;
F_47 ( & V_20 -> V_25 , - 1 ) ;
F_53 ( V_28 , V_68 , V_109 ) ;
V_75 -> V_102 -- ;
error = F_14 ( V_6 , V_20 ) ;
if ( error )
goto V_144;
F_51 ( V_6 , V_107 ) ;
F_54 ( V_28 , V_112 , - 1 ) ;
F_49 ( V_75 ) ;
* V_137 = V_7 ;
return 0 ;
V_153:
F_51 ( V_139 , V_106 ) ;
V_144:
F_51 ( V_6 , V_106 ) ;
F_49 ( V_75 ) ;
return error ;
}
int
F_76 (
struct V_27 * V_28 ,
T_8 V_116 ,
T_15 V_117 ,
int V_118 ,
struct V_35 * * V_155 ,
T_8 * V_137 )
{
struct V_26 * V_1 = V_28 -> V_76 ;
struct V_35 * V_68 ;
T_5 V_31 ;
int error ;
int V_156 ;
int V_157 = 0 ;
T_5 V_158 ;
struct V_74 * V_75 ;
if ( * V_155 ) {
V_68 = * V_155 ;
goto V_159;
}
V_158 = F_58 ( V_28 , V_116 , V_117 , V_118 ) ;
if ( V_158 == V_133 ) {
* V_137 = V_160 ;
return 0 ;
}
if ( V_1 -> V_77 &&
V_1 -> V_2 . V_78 + V_1 -> V_45 > V_1 -> V_77 ) {
V_157 = 1 ;
V_118 = 0 ;
}
V_31 = V_158 ;
for (; ; ) {
V_75 = F_48 ( V_1 , V_31 ) ;
if ( ! V_75 -> V_126 ) {
F_55 ( V_1 ) ;
goto V_127;
}
if ( ! V_75 -> V_128 ) {
error = F_63 ( V_1 , V_28 , V_31 ) ;
if ( error )
goto V_161;
}
if ( ! V_75 -> V_102 && ! V_118 )
goto V_127;
error = F_77 ( V_1 , V_28 , V_31 , & V_68 ) ;
if ( error )
goto V_161;
if ( V_75 -> V_102 ) {
F_49 ( V_75 ) ;
goto V_159;
}
if ( ! V_118 )
goto V_162;
error = F_38 ( V_28 , V_68 , & V_156 ) ;
if ( error ) {
F_78 ( V_28 , V_68 ) ;
if ( error != V_79 )
goto V_161;
F_49 ( V_75 ) ;
* V_137 = V_160 ;
return 0 ;
}
if ( V_156 ) {
ASSERT ( V_75 -> V_102 > 0 ) ;
F_49 ( V_75 ) ;
* V_155 = V_68 ;
* V_137 = V_160 ;
return 0 ;
}
V_162:
F_78 ( V_28 , V_68 ) ;
V_127:
F_49 ( V_75 ) ;
if ( ++ V_31 == V_1 -> V_2 . V_163 )
V_31 = 0 ;
if ( V_31 == V_158 ) {
* V_137 = V_160 ;
return V_157 ? V_79 : 0 ;
}
}
V_159:
* V_155 = NULL ;
return F_69 ( V_28 , V_68 , V_116 , V_137 ) ;
V_161:
F_49 ( V_75 ) ;
return F_39 ( error ) ;
}
int
F_79 (
T_10 * V_28 ,
T_8 V_164 ,
T_18 * V_165 ,
int * V_166 ,
T_8 * V_167 )
{
T_6 V_32 ;
T_11 * V_68 ;
T_2 V_136 ;
T_5 V_31 ;
T_12 * V_20 ;
T_13 * V_6 ;
int error ;
int V_11 ;
int V_168 ;
T_14 * V_1 ;
int V_169 ;
T_4 V_17 ;
struct V_74 * V_75 ;
V_1 = V_28 -> V_76 ;
V_31 = F_62 ( V_1 , V_164 ) ;
if ( V_31 >= V_1 -> V_2 . V_163 ) {
F_80 ( V_1 , L_1 ,
V_170 , V_31 , V_1 -> V_2 . V_163 ) ;
ASSERT ( 0 ) ;
return F_39 ( V_171 ) ;
}
V_136 = F_70 ( V_1 , V_164 ) ;
if ( V_164 != F_20 ( V_1 , V_31 , V_136 ) ) {
F_80 ( V_1 , L_2 ,
V_170 , ( unsigned long long ) V_164 ,
( unsigned long long ) F_20 ( V_1 , V_31 , V_136 ) ) ;
ASSERT ( 0 ) ;
return F_39 ( V_171 ) ;
}
V_32 = F_41 ( V_1 , V_136 ) ;
if ( V_32 >= V_1 -> V_2 . V_172 ) {
F_80 ( V_1 , L_3 ,
V_170 , V_32 , V_1 -> V_2 . V_172 ) ;
ASSERT ( 0 ) ;
return F_39 ( V_171 ) ;
}
error = F_77 ( V_1 , V_28 , V_31 , & V_68 ) ;
if ( error ) {
F_80 ( V_1 , L_4 ,
V_170 , error ) ;
return error ;
}
V_20 = F_40 ( V_68 ) ;
ASSERT ( V_20 -> V_173 == F_7 ( V_174 ) ) ;
ASSERT ( V_32 < F_12 ( V_20 -> V_85 ) ) ;
V_6 = F_50 ( V_1 , V_28 , V_68 , V_31 ) ;
error = F_14 ( V_6 , V_20 ) ;
if ( error )
goto V_144;
if ( ( error = F_4 ( V_6 , V_136 , V_148 , & V_11 ) ) ) {
F_80 ( V_1 , L_5 ,
V_170 , error ) ;
goto V_144;
}
F_71 ( V_11 == 1 , V_144 ) ;
error = F_10 ( V_6 , & V_17 , & V_11 ) ;
if ( error ) {
F_80 ( V_1 , L_6 ,
V_170 , error ) ;
goto V_144;
}
F_71 ( V_11 == 1 , V_144 ) ;
V_169 = V_136 - V_17 . V_12 ;
ASSERT ( V_169 >= 0 && V_169 < V_103 ) ;
ASSERT ( ! ( V_17 . V_14 & F_75 ( V_169 ) ) ) ;
V_17 . V_14 |= F_75 ( V_169 ) ;
V_17 . V_13 ++ ;
if ( ! ( V_1 -> V_95 & V_175 ) &&
( V_17 . V_13 == V_1 -> V_45 ) ) {
* V_166 = 1 ;
* V_167 = F_20 ( V_1 , V_31 , V_17 . V_12 ) ;
V_168 = V_1 -> V_45 ;
F_47 ( & V_20 -> V_101 , - V_168 ) ;
F_47 ( & V_20 -> V_25 , - ( V_168 - 1 ) ) ;
F_53 ( V_28 , V_68 , V_108 | V_109 ) ;
V_75 = F_48 ( V_1 , V_31 ) ;
V_75 -> V_102 -= V_168 - 1 ;
F_49 ( V_75 ) ;
F_54 ( V_28 , V_111 , - V_168 ) ;
F_54 ( V_28 , V_112 , - ( V_168 - 1 ) ) ;
if ( ( error = F_81 ( V_6 , & V_11 ) ) ) {
F_80 ( V_1 , L_7 ,
V_170 , error ) ;
goto V_144;
}
F_82 ( F_43 ( V_1 , V_31 ,
F_41 ( V_1 , V_17 . V_12 ) ) ,
V_1 -> V_82 , V_165 , V_1 ) ;
} else {
* V_166 = 0 ;
error = F_6 ( V_6 , & V_17 ) ;
if ( error ) {
F_80 ( V_1 , L_8 ,
V_170 , error ) ;
goto V_144;
}
F_47 ( & V_20 -> V_25 , 1 ) ;
F_53 ( V_28 , V_68 , V_109 ) ;
V_75 = F_48 ( V_1 , V_31 ) ;
V_75 -> V_102 ++ ;
F_49 ( V_75 ) ;
F_54 ( V_28 , V_112 , 1 ) ;
}
error = F_14 ( V_6 , V_20 ) ;
if ( error )
goto V_144;
F_51 ( V_6 , V_107 ) ;
return 0 ;
V_144:
F_51 ( V_6 , V_106 ) ;
return error ;
}
STATIC int
F_83 (
struct V_26 * V_1 ,
struct V_27 * V_28 ,
T_5 V_31 ,
T_2 V_136 ,
T_6 V_32 ,
T_6 * V_176 ,
T_6 * V_177 ,
int V_120 )
{
struct V_140 V_17 ;
struct V_5 * V_6 ;
struct V_35 * V_68 ;
int error ;
int V_11 ;
error = F_77 ( V_1 , V_28 , V_31 , & V_68 ) ;
if ( error ) {
F_84 ( V_1 ,
L_9 ,
V_170 , error , V_31 ) ;
return error ;
}
V_6 = F_50 ( V_1 , V_28 , V_68 , V_31 ) ;
error = F_4 ( V_6 , V_136 , V_148 , & V_11 ) ;
if ( ! error ) {
if ( V_11 )
error = F_10 ( V_6 , & V_17 , & V_11 ) ;
if ( ! error && V_11 == 0 )
error = V_171 ;
}
F_78 ( V_28 , V_68 ) ;
F_51 ( V_6 , V_107 ) ;
if ( error )
return error ;
if ( V_17 . V_12 > V_136 ||
V_17 . V_12 + V_1 -> V_45 <= V_136 )
return V_171 ;
if ( ( V_120 & V_178 ) &&
( V_17 . V_14 & F_75 ( V_136 - V_17 . V_12 ) ) )
return V_171 ;
* V_176 = F_41 ( V_1 , V_17 . V_12 ) ;
* V_177 = V_32 - * V_176 ;
return 0 ;
}
int
F_85 (
T_14 * V_1 ,
T_10 * V_28 ,
T_8 V_7 ,
struct F_85 * V_179 ,
T_9 V_120 )
{
T_6 V_32 ;
T_2 V_136 ;
T_5 V_31 ;
int V_39 ;
T_6 V_176 ;
T_6 V_180 ;
int error ;
int V_142 ;
T_6 V_177 ;
ASSERT ( V_7 != V_160 ) ;
V_31 = F_62 ( V_1 , V_7 ) ;
V_136 = F_70 ( V_1 , V_7 ) ;
V_32 = F_41 ( V_1 , V_136 ) ;
if ( V_31 >= V_1 -> V_2 . V_163 || V_32 >= V_1 -> V_2 . V_172 ||
V_7 != F_20 ( V_1 , V_31 , V_136 ) ) {
#ifdef F_86
if ( V_120 & V_178 )
return F_39 ( V_171 ) ;
if ( V_31 >= V_1 -> V_2 . V_163 ) {
F_84 ( V_1 ,
L_10 ,
V_170 , V_31 , V_1 -> V_2 . V_163 ) ;
}
if ( V_32 >= V_1 -> V_2 . V_172 ) {
F_84 ( V_1 ,
L_11 ,
V_170 , ( unsigned long long ) V_32 ,
( unsigned long ) V_1 -> V_2 . V_172 ) ;
}
if ( V_7 != F_20 ( V_1 , V_31 , V_136 ) ) {
F_84 ( V_1 ,
L_12 ,
V_170 , V_7 ,
F_20 ( V_1 , V_31 , V_136 ) ) ;
}
F_87 () ;
#endif
return F_39 ( V_171 ) ;
}
V_39 = F_18 ( V_1 ) ;
if ( V_120 & V_178 ) {
error = F_83 ( V_1 , V_28 , V_31 , V_136 , V_32 ,
& V_176 , & V_177 , V_120 ) ;
if ( error )
return error ;
goto V_181;
}
if ( V_39 == 1 ) {
V_142 = F_88 ( V_1 , V_7 ) ;
ASSERT ( V_142 < V_1 -> V_2 . V_182 ) ;
V_179 -> V_183 = F_24 ( V_1 , V_31 , V_32 ) ;
V_179 -> V_184 = F_89 ( V_1 , 1 ) ;
V_179 -> V_185 = ( V_186 ) ( V_142 << V_1 -> V_2 . V_55 ) ;
return 0 ;
}
if ( V_1 -> V_187 ) {
V_177 = V_32 & V_1 -> V_187 ;
V_176 = V_32 - V_177 ;
} else {
error = F_83 ( V_1 , V_28 , V_31 , V_136 , V_32 ,
& V_176 , & V_177 , V_120 ) ;
if ( error )
return error ;
}
V_181:
ASSERT ( V_32 >= V_176 ) ;
V_180 = V_176 +
( ( V_177 / V_39 ) * V_39 ) ;
V_142 = ( ( V_32 - V_180 ) * V_1 -> V_2 . V_182 ) +
F_88 ( V_1 , V_7 ) ;
V_179 -> V_183 = F_24 ( V_1 , V_31 , V_180 ) ;
V_179 -> V_184 = F_89 ( V_1 , V_39 ) ;
V_179 -> V_185 = ( V_186 ) ( V_142 << V_1 -> V_2 . V_55 ) ;
if ( ( V_179 -> V_183 + V_179 -> V_184 ) >
F_89 ( V_1 , V_1 -> V_2 . V_188 ) ) {
F_84 ( V_1 ,
L_13 ,
V_170 , ( unsigned long long ) V_179 -> V_183 ,
( unsigned long long ) V_179 -> V_184 ,
F_89 ( V_1 , V_1 -> V_2 . V_188 ) ) ;
return F_39 ( V_171 ) ;
}
return 0 ;
}
void
F_90 (
T_14 * V_1 )
{
int V_189 ;
T_9 V_190 ;
T_9 V_191 ;
int V_192 ;
int V_193 ;
V_191 = ( 1LL << F_91 ( V_1 ) ) >>
V_194 ;
V_192 = V_1 -> V_195 [ 0 ] ;
V_193 = V_1 -> V_195 [ 1 ] ;
V_190 = ( V_191 + V_192 - 1 ) / V_192 ;
for ( V_189 = 1 ; V_190 > 1 ; V_189 ++ )
V_190 = ( V_190 + V_193 - 1 ) / V_193 ;
V_1 -> V_92 = V_189 ;
}
void
F_53 (
T_10 * V_28 ,
T_11 * V_196 ,
int V_197 )
{
int V_198 ;
int V_199 ;
static const short V_200 [] = {
F_92 ( T_12 , V_173 ) ,
F_92 ( T_12 , V_201 ) ,
F_92 ( T_12 , V_84 ) ,
F_92 ( T_12 , V_85 ) ,
F_92 ( T_12 , V_101 ) ,
F_92 ( T_12 , V_98 ) ,
F_92 ( T_12 , V_202 ) ,
F_92 ( T_12 , V_25 ) ,
F_92 ( T_12 , V_83 ) ,
F_92 ( T_12 , V_203 ) ,
F_92 ( T_12 , V_204 ) ,
sizeof( T_12 )
} ;
#ifdef F_86
T_12 * V_20 ;
V_20 = F_40 ( V_196 ) ;
ASSERT ( V_20 -> V_173 == F_7 ( V_174 ) ) ;
#endif
F_93 ( V_197 , V_200 , V_205 , & V_198 , & V_199 ) ;
F_94 ( V_28 , V_196 , V_206 ) ;
F_33 ( V_28 , V_196 , V_198 , V_199 ) ;
}
STATIC void
F_95 (
struct V_19 * V_20 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_207 ; V_11 ++ )
ASSERT ( V_20 -> V_204 [ V_11 ] ) ;
}
static bool
F_96 (
struct V_35 * V_196 )
{
struct V_26 * V_1 = V_196 -> V_208 -> V_209 ;
struct V_19 * V_20 = F_40 ( V_196 ) ;
if ( F_19 ( & V_1 -> V_2 ) &&
! F_97 ( & V_20 -> V_210 , & V_1 -> V_2 . V_65 ) )
return false ;
if ( V_20 -> V_173 != F_7 ( V_174 ) )
return false ;
if ( ! F_98 ( F_12 ( V_20 -> V_201 ) ) )
return false ;
if ( V_196 -> V_211 && F_12 ( V_20 -> V_84 ) != V_196 -> V_211 -> V_212 )
return false ;
F_95 ( V_20 ) ;
return true ;
}
static void
F_99 (
struct V_35 * V_196 )
{
struct V_26 * V_1 = V_196 -> V_208 -> V_209 ;
int V_213 = 1 ;
if ( F_19 ( & V_1 -> V_2 ) )
V_213 = F_100 ( V_196 -> V_214 , F_27 ( V_196 -> V_53 ) ,
F_92 ( struct V_19 , V_215 ) ) ;
V_213 = V_213 && F_96 ( V_196 ) ;
if ( F_45 ( F_101 ( ! V_213 , V_1 , V_216 ,
V_217 ) ) ) {
F_102 ( V_170 , V_218 , V_1 , V_196 -> V_214 ) ;
F_103 ( V_196 , V_219 ) ;
}
}
static void
F_104 (
struct V_35 * V_196 )
{
struct V_26 * V_1 = V_196 -> V_208 -> V_209 ;
struct V_220 * V_221 = V_196 -> V_222 ;
if ( ! F_96 ( V_196 ) ) {
F_102 ( V_170 , V_218 , V_1 , V_196 -> V_214 ) ;
F_103 ( V_196 , V_219 ) ;
return;
}
if ( ! F_19 ( & V_1 -> V_2 ) )
return;
if ( V_221 )
F_40 ( V_196 ) -> V_223 = F_8 ( V_221 -> V_224 . V_225 ) ;
F_105 ( V_196 -> V_214 , F_27 ( V_196 -> V_53 ) ,
F_92 ( struct V_19 , V_215 ) ) ;
}
int
F_106 (
struct V_26 * V_1 ,
struct V_27 * V_28 ,
T_5 V_31 ,
struct V_35 * * V_226 )
{
int error ;
F_107 ( V_1 , V_31 ) ;
ASSERT ( V_31 != V_133 ) ;
error = F_108 ( V_1 , V_28 , V_1 -> V_47 ,
F_109 ( V_1 , V_31 , F_110 ( V_1 ) ) ,
F_111 ( V_1 , 1 ) , 0 , V_226 , & V_227 ) ;
if ( error )
return error ;
ASSERT ( ! F_112 ( * V_226 ) ) ;
F_113 ( * V_226 , V_228 ) ;
return 0 ;
}
int
F_77 (
struct V_26 * V_1 ,
struct V_27 * V_28 ,
T_5 V_31 ,
struct V_35 * * V_226 )
{
struct V_19 * V_20 ;
struct V_74 * V_75 ;
int error ;
F_114 ( V_1 , V_31 ) ;
error = F_106 ( V_1 , V_28 , V_31 , V_226 ) ;
if ( error )
return error ;
V_20 = F_40 ( * V_226 ) ;
V_75 = F_48 ( V_1 , V_31 ) ;
if ( ! V_75 -> V_128 ) {
V_75 -> V_102 = F_12 ( V_20 -> V_25 ) ;
V_75 -> V_229 = F_12 ( V_20 -> V_101 ) ;
V_75 -> V_128 = 1 ;
}
ASSERT ( V_75 -> V_102 == F_12 ( V_20 -> V_25 ) ||
F_16 ( V_1 ) ) ;
F_49 ( V_75 ) ;
return 0 ;
}
int
F_63 (
T_14 * V_1 ,
T_10 * V_28 ,
T_5 V_31 )
{
T_11 * V_196 = NULL ;
int error ;
error = F_77 ( V_1 , V_28 , V_31 , & V_196 ) ;
if ( error )
return error ;
if ( V_196 )
F_78 ( V_28 , V_196 ) ;
return 0 ;
}
