static inline int
F_1 (
T_1 * args )
{
if ( F_2 ( & args -> V_1 -> V_2 ) &&
args -> V_1 -> V_2 . V_3 >=
F_3 ( args -> V_1 , F_4 ( args -> V_1 ) ) )
return args -> V_1 -> V_2 . V_3 ;
return 1 ;
}
int
F_5 (
struct V_4 * V_5 ,
T_2 V_6 ,
T_3 V_7 ,
int * V_8 )
{
V_5 -> V_9 . V_10 . V_11 = V_6 ;
V_5 -> V_9 . V_10 . V_12 = 0 ;
V_5 -> V_9 . V_10 . V_13 = 0 ;
return F_6 ( V_5 , V_7 , V_8 ) ;
}
STATIC int
F_7 (
struct V_4 * V_5 ,
T_4 * V_14 )
{
union V_15 V_16 ;
V_16 . V_17 . V_11 = F_8 ( V_14 -> V_11 ) ;
V_16 . V_17 . V_12 = F_8 ( V_14 -> V_12 ) ;
V_16 . V_17 . V_13 = F_9 ( V_14 -> V_13 ) ;
return F_10 ( V_5 , & V_16 ) ;
}
int
F_11 (
struct V_4 * V_5 ,
T_4 * V_14 ,
int * V_8 )
{
union V_15 * V_16 ;
int error ;
error = F_12 ( V_5 , & V_16 , V_8 ) ;
if ( ! error && * V_8 == 1 ) {
V_14 -> V_11 = F_13 ( V_16 -> V_17 . V_11 ) ;
V_14 -> V_12 = F_13 ( V_16 -> V_17 . V_12 ) ;
V_14 -> V_13 = F_14 ( V_16 -> V_17 . V_13 ) ;
}
return error ;
}
STATIC int
F_15 (
struct V_4 * V_5 ,
struct V_18 * V_19 )
{
if ( V_5 -> V_20 == 1 ) {
T_4 V_16 ;
int V_21 = 0 ;
int error ;
int V_10 ;
error = F_5 ( V_5 , 0 , V_22 , & V_10 ) ;
if ( error )
return error ;
do {
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( error )
return error ;
if ( V_10 ) {
V_21 += V_16 . V_12 ;
error = F_16 ( V_5 , 0 , & V_10 ) ;
if ( error )
return error ;
}
} while ( V_10 == 1 );
if ( ! F_17 ( V_5 -> V_23 ) )
ASSERT ( V_21 == F_13 ( V_19 -> V_24 ) ) ;
}
return 0 ;
}
int
F_18 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
struct V_28 * V_29 ,
T_5 V_30 ,
T_6 V_31 ,
T_6 V_32 ,
unsigned int V_33 )
{
struct V_34 * V_35 ;
struct V_36 * free ;
int V_37 , V_38 , V_39 ;
int V_40 ;
int V_10 , V_41 ;
T_7 V_42 ;
T_8 V_6 = 0 ;
if ( V_1 -> V_2 . V_43 >= F_4 ( V_1 ) ) {
V_37 = 1 ;
V_38 = V_32 ;
V_39 = V_1 -> V_2 . V_44 ;
} else {
V_37 = F_4 ( V_1 ) /
V_1 -> V_2 . V_43 ;
V_38 = V_32 / V_37 ;
V_39 = V_37 * V_1 -> V_2 . V_44 ;
}
if ( F_19 ( & V_1 -> V_2 ) ) {
V_40 = 3 ;
V_6 = F_20 ( V_1 , V_30 ,
F_21 ( V_1 , V_31 , 0 ) ) ;
if ( V_27 )
F_22 ( V_27 , V_30 , V_31 , F_23 ( V_1 ) ,
V_1 -> V_2 . V_45 , V_32 , V_33 ) ;
} else if ( F_24 ( & V_1 -> V_2 ) )
V_40 = 2 ;
else
V_40 = 1 ;
for ( V_41 = 0 ; V_41 < V_38 ; V_41 ++ ) {
V_42 = F_25 ( V_1 , V_30 , V_31 + ( V_41 * V_37 ) ) ;
V_35 = F_26 ( V_27 , V_1 -> V_46 , V_42 ,
V_1 -> V_47 * V_37 ,
V_48 ) ;
if ( ! V_35 )
return V_49 ;
V_35 -> V_50 = & V_51 ;
F_27 ( V_35 , 0 , F_28 ( V_35 -> V_52 ) ) ;
for ( V_10 = 0 ; V_10 < V_39 ; V_10 ++ ) {
int V_53 = V_10 << V_1 -> V_2 . V_54 ;
T_9 V_55 = F_29 ( V_40 ) ;
free = F_30 ( V_1 , V_35 , V_10 ) ;
free -> V_56 = F_31 ( V_57 ) ;
free -> V_58 = V_40 ;
free -> V_59 = F_8 ( V_33 ) ;
free -> V_60 = F_8 ( V_61 ) ;
if ( V_40 == 3 ) {
free -> V_62 = F_9 ( V_6 ) ;
V_6 ++ ;
F_32 ( & free -> V_63 , & V_1 -> V_2 . V_64 ) ;
F_33 ( V_1 , free ) ;
} else if ( V_27 ) {
F_34 ( V_27 , V_35 , V_53 ,
V_53 + V_55 - 1 ) ;
}
}
if ( V_27 ) {
F_35 ( V_27 , V_35 ) ;
if ( V_40 == 3 ) {
F_36 ( V_27 , V_35 ) ;
F_34 ( V_27 , V_35 , 0 ,
F_28 ( V_35 -> V_52 ) - 1 ) ;
}
} else {
V_35 -> V_65 |= V_66 ;
F_37 ( V_35 , V_29 ) ;
F_38 ( V_35 ) ;
}
}
return 0 ;
}
STATIC int
F_39 (
T_10 * V_27 ,
T_11 * V_67 ,
int * V_68 )
{
T_12 * V_19 ;
T_1 args ;
T_13 * V_5 ;
T_5 V_30 ;
int error ;
int V_10 ;
T_2 V_69 ;
T_2 V_70 ;
T_2 V_71 ;
int V_72 = 0 ;
struct V_73 * V_74 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_27 = V_27 ;
args . V_1 = V_27 -> V_75 ;
V_70 = F_23 ( args . V_1 ) ;
if ( args . V_1 -> V_76 &&
args . V_1 -> V_2 . V_77 + V_70 > args . V_1 -> V_76 )
return F_40 ( V_78 ) ;
args . V_79 = args . V_80 = F_41 ( args . V_1 ) ;
V_19 = F_42 ( V_67 ) ;
V_69 = F_13 ( V_19 -> V_81 ) ;
V_30 = F_13 ( V_19 -> V_82 ) ;
args . V_31 = F_43 ( args . V_1 , V_69 ) +
F_41 ( args . V_1 ) ;
if ( F_44 ( V_69 != V_61 &&
( args . V_31 < F_13 ( V_19 -> V_83 ) ) ) ) {
args . V_84 = F_45 ( args . V_1 , V_30 , args . V_31 ) ;
args . type = V_85 ;
args . V_86 = 1 ;
args . V_87 = 1 ;
args . V_88 = F_1 ( & args ) - 1 ;
args . V_89 = args . V_1 -> V_90 - 1 ;
if ( ( error = F_46 ( & args ) ) )
return error ;
} else
args . V_84 = V_91 ;
if ( F_47 ( args . V_84 == V_91 ) ) {
V_72 = 0 ;
if ( args . V_1 -> V_92 ) {
ASSERT ( ! ( args . V_1 -> V_93 & V_94 ) ) ;
args . V_87 = args . V_1 -> V_95 ;
V_72 = 1 ;
} else
args . V_87 = F_1 ( & args ) ;
args . V_31 = F_13 ( V_19 -> V_96 ) ;
args . V_84 = F_45 ( args . V_1 , V_30 , args . V_31 ) ;
args . type = V_97 ;
args . V_86 = 1 ;
args . V_89 = args . V_1 -> V_90 - 1 ;
if ( ( error = F_46 ( & args ) ) )
return error ;
}
if ( V_72 && args . V_84 == V_91 ) {
args . type = V_97 ;
args . V_31 = F_13 ( V_19 -> V_96 ) ;
args . V_84 = F_45 ( args . V_1 , V_30 , args . V_31 ) ;
args . V_87 = F_1 ( & args ) ;
if ( ( error = F_46 ( & args ) ) )
return error ;
}
if ( args . V_84 == V_91 ) {
* V_68 = 0 ;
return 0 ;
}
ASSERT ( args . V_98 == args . V_79 ) ;
error = F_18 ( args . V_1 , V_27 , NULL , V_30 , args . V_31 ,
args . V_98 , F_48 () ) ;
if ( error )
return error ;
V_69 = F_21 ( args . V_1 , args . V_31 , 0 ) ;
F_49 ( & V_19 -> V_99 , V_70 ) ;
F_49 ( & V_19 -> V_24 , V_70 ) ;
V_74 = F_50 ( args . V_1 , V_30 ) ;
V_74 -> V_100 += V_70 ;
F_51 ( V_74 ) ;
V_19 -> V_81 = F_8 ( V_69 ) ;
V_5 = F_52 ( args . V_1 , V_27 , V_67 , V_30 ) ;
for ( V_71 = V_69 ;
V_71 < V_69 + V_70 ;
V_71 += V_101 ) {
V_5 -> V_9 . V_10 . V_11 = V_71 ;
V_5 -> V_9 . V_10 . V_12 = V_101 ;
V_5 -> V_9 . V_10 . V_13 = V_102 ;
error = F_6 ( V_5 , V_103 , & V_10 ) ;
if ( error ) {
F_53 ( V_5 , V_104 ) ;
return error ;
}
ASSERT ( V_10 == 0 ) ;
error = F_54 ( V_5 , & V_10 ) ;
if ( error ) {
F_53 ( V_5 , V_104 ) ;
return error ;
}
ASSERT ( V_10 == 1 ) ;
}
F_53 ( V_5 , V_105 ) ;
F_55 ( V_27 , V_67 ,
V_106 | V_107 | V_108 ) ;
F_56 ( V_27 , V_109 , ( long ) V_70 ) ;
F_56 ( V_27 , V_110 , ( long ) V_70 ) ;
* V_68 = 1 ;
return 0 ;
}
STATIC T_5
F_57 (
T_14 * V_1 )
{
T_5 V_30 ;
F_58 ( & V_1 -> V_111 ) ;
V_30 = V_1 -> V_112 ;
if ( ++ V_1 -> V_112 >= V_1 -> V_113 )
V_1 -> V_112 = 0 ;
F_59 ( & V_1 -> V_111 ) ;
return V_30 ;
}
STATIC T_5
F_60 (
T_10 * V_27 ,
T_8 V_114 ,
T_15 V_115 ,
int V_116 )
{
T_5 V_117 ;
T_5 V_30 ;
int V_118 ;
T_16 V_119 ;
T_16 V_120 = 0 ;
T_14 * V_1 ;
int V_121 ;
T_17 * V_74 ;
T_5 V_122 ;
int error ;
V_121 = F_61 ( V_115 ) || F_62 ( V_115 ) || F_63 ( V_115 ) ;
V_1 = V_27 -> V_75 ;
V_117 = V_1 -> V_113 ;
if ( F_61 ( V_115 ) )
V_122 = F_57 ( V_1 ) ;
else {
V_122 = F_64 ( V_1 , V_114 ) ;
if ( V_122 >= V_117 )
V_122 = 0 ;
}
ASSERT ( V_122 < V_117 ) ;
V_30 = V_122 ;
V_118 = V_123 ;
for (; ; ) {
V_74 = F_50 ( V_1 , V_30 ) ;
if ( ! V_74 -> V_124 ) {
F_57 ( V_1 ) ;
goto V_125;
}
if ( ! V_74 -> V_126 ) {
error = F_65 ( V_1 , V_27 , V_30 ) ;
if ( error )
goto V_125;
}
if ( V_74 -> V_100 ) {
F_51 ( V_74 ) ;
return V_30 ;
}
if ( ! V_116 )
goto V_125;
if ( ! V_74 -> V_127 ) {
error = F_66 ( V_1 , V_27 , V_30 , V_118 ) ;
if ( error )
goto V_125;
}
V_119 = F_41 ( V_1 ) ;
V_120 = V_74 -> V_128 ;
if ( ! V_120 )
V_120 = V_74 -> V_129 > 0 ;
if ( V_74 -> V_130 >= V_121 + V_119 &&
V_120 >= V_119 ) {
F_51 ( V_74 ) ;
return V_30 ;
}
V_125:
F_51 ( V_74 ) ;
if ( F_17 ( V_1 ) )
return V_131 ;
V_30 ++ ;
if ( V_30 >= V_117 )
V_30 = 0 ;
if ( V_30 == V_122 ) {
if ( V_118 == 0 )
return V_131 ;
V_118 = 0 ;
}
}
}
STATIC int
F_67 (
struct V_4 * V_5 ,
T_4 * V_16 ,
int * V_132 ,
int V_133 )
{
int error ;
int V_10 ;
if ( V_133 )
error = F_68 ( V_5 , 0 , & V_10 ) ;
else
error = F_16 ( V_5 , 0 , & V_10 ) ;
if ( error )
return error ;
* V_132 = ! V_10 ;
if ( V_10 ) {
error = F_11 ( V_5 , V_16 , & V_10 ) ;
if ( error )
return error ;
F_69 ( V_10 == 1 ) ;
}
return 0 ;
}
STATIC int
F_70 (
struct V_4 * V_5 ,
T_2 V_134 ,
T_4 * V_16 ,
int * V_132 )
{
int error ;
int V_10 ;
error = F_5 ( V_5 , V_134 , V_103 , & V_10 ) ;
if ( error )
return error ;
* V_132 = ! V_10 ;
if ( V_10 ) {
error = F_11 ( V_5 , V_16 , & V_10 ) ;
if ( error )
return error ;
F_69 ( V_10 == 1 ) ;
}
return 0 ;
}
STATIC int
F_71 (
struct V_26 * V_27 ,
struct V_34 * V_67 ,
T_8 V_114 ,
T_8 * V_135 )
{
struct V_25 * V_1 = V_27 -> V_75 ;
struct V_18 * V_19 = F_42 ( V_67 ) ;
T_5 V_30 = F_13 ( V_19 -> V_82 ) ;
T_5 V_122 = F_64 ( V_1 , V_114 ) ;
T_2 V_136 = F_72 ( V_1 , V_114 ) ;
struct V_73 * V_74 ;
struct V_4 * V_5 , * V_137 ;
struct V_138 V_16 , V_139 ;
T_8 V_6 ;
int error ;
int V_140 ;
int V_10 , V_41 ;
V_74 = F_50 ( V_1 , V_30 ) ;
ASSERT ( V_74 -> V_126 ) ;
ASSERT ( V_74 -> V_124 ) ;
ASSERT ( V_74 -> V_100 > 0 ) ;
V_141:
V_5 = F_52 ( V_1 , V_27 , V_67 , V_30 ) ;
if ( ! V_136 )
V_136 = F_13 ( V_19 -> V_81 ) ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_142;
if ( V_122 == V_30 ) {
int V_143 ;
int V_144 ;
int V_145 = 10 ;
error = F_5 ( V_5 , V_136 , V_146 , & V_10 ) ;
if ( error )
goto V_142;
F_73 ( V_10 == 1 , V_142 ) ;
error = F_11 ( V_5 , & V_16 , & V_41 ) ;
if ( error )
goto V_142;
F_73 ( V_41 == 1 , V_142 ) ;
if ( V_16 . V_12 > 0 ) {
goto V_147;
}
error = F_74 ( V_5 , & V_137 ) ;
if ( error )
goto V_142;
if ( V_136 != V_61 &&
V_74 -> V_148 == V_136 &&
V_74 -> V_149 != V_61 &&
V_74 -> V_150 != V_61 ) {
error = F_70 ( V_137 , V_74 -> V_149 ,
& V_139 , & V_143 ) ;
if ( error )
goto V_151;
error = F_70 ( V_5 , V_74 -> V_150 ,
& V_16 , & V_144 ) ;
if ( error )
goto V_151;
} else {
error = F_67 ( V_137 , & V_139 , & V_143 , 1 ) ;
if ( error )
goto V_151;
error = F_67 ( V_5 , & V_16 , & V_144 , 0 ) ;
if ( error )
goto V_151;
}
while ( ! V_143 || ! V_144 ) {
int V_152 ;
if ( ! -- V_145 ) {
F_53 ( V_137 , V_105 ) ;
V_74 -> V_149 = V_139 . V_11 ;
V_74 -> V_150 = V_16 . V_11 ;
V_74 -> V_148 = V_136 ;
goto V_69;
}
if ( ! V_143 && ! V_144 ) {
V_152 = V_136 -
( V_139 . V_11 + V_101 - 1 ) <
V_16 . V_11 - V_136 ;
} else {
V_152 = ! V_143 ;
}
if ( V_152 && V_139 . V_12 ) {
V_16 = V_139 ;
F_53 ( V_5 , V_105 ) ;
V_5 = V_137 ;
V_74 -> V_149 = V_139 . V_11 ;
V_74 -> V_150 = V_16 . V_11 ;
V_74 -> V_148 = V_136 ;
goto V_147;
}
if ( ! V_152 && V_16 . V_12 ) {
F_53 ( V_137 , V_105 ) ;
V_74 -> V_149 = V_139 . V_11 ;
V_74 -> V_150 = V_16 . V_11 ;
V_74 -> V_148 = V_136 ;
goto V_147;
}
if ( V_152 ) {
error = F_67 ( V_137 , & V_139 ,
& V_143 , 1 ) ;
} else {
error = F_67 ( V_5 , & V_16 ,
& V_144 , 0 ) ;
}
if ( error )
goto V_151;
}
V_74 -> V_148 = V_61 ;
V_74 -> V_149 = V_61 ;
V_74 -> V_150 = V_61 ;
F_53 ( V_137 , V_105 ) ;
F_53 ( V_5 , V_105 ) ;
goto V_141;
}
V_69:
if ( V_19 -> V_81 != F_8 ( V_61 ) ) {
error = F_5 ( V_5 , F_13 ( V_19 -> V_81 ) ,
V_103 , & V_10 ) ;
if ( error )
goto V_142;
if ( V_10 == 1 ) {
error = F_11 ( V_5 , & V_16 , & V_41 ) ;
if ( error )
goto V_142;
if ( V_41 == 1 && V_16 . V_12 > 0 ) {
goto V_147;
}
}
}
error = F_5 ( V_5 , 0 , V_22 , & V_10 ) ;
if ( error )
goto V_142;
F_73 ( V_10 == 1 , V_142 ) ;
for (; ; ) {
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( error )
goto V_142;
F_73 ( V_10 == 1 , V_142 ) ;
if ( V_16 . V_12 > 0 )
break;
error = F_16 ( V_5 , 0 , & V_10 ) ;
if ( error )
goto V_142;
F_73 ( V_10 == 1 , V_142 ) ;
}
V_147:
V_140 = F_75 ( V_16 . V_13 ) ;
ASSERT ( V_140 >= 0 ) ;
ASSERT ( V_140 < V_101 ) ;
ASSERT ( ( F_76 ( V_1 , V_16 . V_11 ) %
V_101 ) == 0 ) ;
V_6 = F_20 ( V_1 , V_30 , V_16 . V_11 + V_140 ) ;
V_16 . V_13 &= ~ F_77 ( V_140 ) ;
V_16 . V_12 -- ;
error = F_7 ( V_5 , & V_16 ) ;
if ( error )
goto V_142;
F_49 ( & V_19 -> V_24 , - 1 ) ;
F_55 ( V_27 , V_67 , V_107 ) ;
V_74 -> V_100 -- ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_142;
F_53 ( V_5 , V_105 ) ;
F_56 ( V_27 , V_110 , - 1 ) ;
F_51 ( V_74 ) ;
* V_135 = V_6 ;
return 0 ;
V_151:
F_53 ( V_137 , V_104 ) ;
V_142:
F_53 ( V_5 , V_104 ) ;
F_51 ( V_74 ) ;
return error ;
}
int
F_78 (
struct V_26 * V_27 ,
T_8 V_114 ,
T_15 V_115 ,
int V_116 ,
struct V_34 * * V_153 ,
T_8 * V_135 )
{
struct V_25 * V_1 = V_27 -> V_75 ;
struct V_34 * V_67 ;
T_5 V_30 ;
int error ;
int V_154 ;
int V_155 = 0 ;
T_5 V_156 ;
struct V_73 * V_74 ;
if ( * V_153 ) {
V_67 = * V_153 ;
goto V_157;
}
V_156 = F_60 ( V_27 , V_114 , V_115 , V_116 ) ;
if ( V_156 == V_131 ) {
* V_135 = V_158 ;
return 0 ;
}
if ( V_1 -> V_76 &&
V_1 -> V_2 . V_77 + F_23 ( V_1 ) > V_1 -> V_76 ) {
V_155 = 1 ;
V_116 = 0 ;
}
V_30 = V_156 ;
for (; ; ) {
V_74 = F_50 ( V_1 , V_30 ) ;
if ( ! V_74 -> V_124 ) {
F_57 ( V_1 ) ;
goto V_125;
}
if ( ! V_74 -> V_126 ) {
error = F_65 ( V_1 , V_27 , V_30 ) ;
if ( error )
goto V_159;
}
if ( ! V_74 -> V_100 && ! V_116 )
goto V_125;
error = F_79 ( V_1 , V_27 , V_30 , & V_67 ) ;
if ( error )
goto V_159;
if ( V_74 -> V_100 ) {
F_51 ( V_74 ) ;
goto V_157;
}
if ( ! V_116 )
goto V_160;
error = F_39 ( V_27 , V_67 , & V_154 ) ;
if ( error ) {
F_80 ( V_27 , V_67 ) ;
if ( error != V_78 )
goto V_159;
F_51 ( V_74 ) ;
* V_135 = V_158 ;
return 0 ;
}
if ( V_154 ) {
ASSERT ( V_74 -> V_100 > 0 ) ;
F_51 ( V_74 ) ;
* V_153 = V_67 ;
* V_135 = V_158 ;
return 0 ;
}
V_160:
F_80 ( V_27 , V_67 ) ;
V_125:
F_51 ( V_74 ) ;
if ( ++ V_30 == V_1 -> V_2 . V_161 )
V_30 = 0 ;
if ( V_30 == V_156 ) {
* V_135 = V_158 ;
return V_155 ? V_78 : 0 ;
}
}
V_157:
* V_153 = NULL ;
return F_71 ( V_27 , V_67 , V_114 , V_135 ) ;
V_159:
F_51 ( V_74 ) ;
return F_40 ( error ) ;
}
int
F_81 (
T_10 * V_27 ,
T_8 V_162 ,
T_18 * V_163 ,
int * V_164 ,
T_8 * V_165 )
{
T_6 V_31 ;
T_11 * V_67 ;
T_2 V_134 ;
T_5 V_30 ;
T_12 * V_19 ;
T_13 * V_5 ;
int error ;
int V_10 ;
int V_166 ;
T_14 * V_1 ;
int V_167 ;
T_4 V_16 ;
struct V_73 * V_74 ;
V_1 = V_27 -> V_75 ;
V_30 = F_64 ( V_1 , V_162 ) ;
if ( V_30 >= V_1 -> V_2 . V_161 ) {
F_82 ( V_1 , L_1 ,
V_168 , V_30 , V_1 -> V_2 . V_161 ) ;
ASSERT ( 0 ) ;
return F_40 ( V_169 ) ;
}
V_134 = F_72 ( V_1 , V_162 ) ;
if ( V_162 != F_20 ( V_1 , V_30 , V_134 ) ) {
F_82 ( V_1 , L_2 ,
V_168 , ( unsigned long long ) V_162 ,
( unsigned long long ) F_20 ( V_1 , V_30 , V_134 ) ) ;
ASSERT ( 0 ) ;
return F_40 ( V_169 ) ;
}
V_31 = F_43 ( V_1 , V_134 ) ;
if ( V_31 >= V_1 -> V_2 . V_170 ) {
F_82 ( V_1 , L_3 ,
V_168 , V_31 , V_1 -> V_2 . V_170 ) ;
ASSERT ( 0 ) ;
return F_40 ( V_169 ) ;
}
error = F_79 ( V_1 , V_27 , V_30 , & V_67 ) ;
if ( error ) {
F_82 ( V_1 , L_4 ,
V_168 , error ) ;
return error ;
}
V_19 = F_42 ( V_67 ) ;
ASSERT ( V_19 -> V_171 == F_8 ( V_172 ) ) ;
ASSERT ( V_31 < F_13 ( V_19 -> V_83 ) ) ;
V_5 = F_52 ( V_1 , V_27 , V_67 , V_30 ) ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_142;
if ( ( error = F_5 ( V_5 , V_134 , V_146 , & V_10 ) ) ) {
F_82 ( V_1 , L_5 ,
V_168 , error ) ;
goto V_142;
}
F_73 ( V_10 == 1 , V_142 ) ;
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( error ) {
F_82 ( V_1 , L_6 ,
V_168 , error ) ;
goto V_142;
}
F_73 ( V_10 == 1 , V_142 ) ;
V_167 = V_134 - V_16 . V_11 ;
ASSERT ( V_167 >= 0 && V_167 < V_101 ) ;
ASSERT ( ! ( V_16 . V_13 & F_77 ( V_167 ) ) ) ;
V_16 . V_13 |= F_77 ( V_167 ) ;
V_16 . V_12 ++ ;
if ( ! ( V_1 -> V_93 & V_173 ) &&
( V_16 . V_12 == F_23 ( V_1 ) ) ) {
* V_164 = 1 ;
* V_165 = F_20 ( V_1 , V_30 , V_16 . V_11 ) ;
V_166 = F_23 ( V_1 ) ;
F_49 ( & V_19 -> V_99 , - V_166 ) ;
F_49 ( & V_19 -> V_24 , - ( V_166 - 1 ) ) ;
F_55 ( V_27 , V_67 , V_106 | V_107 ) ;
V_74 = F_50 ( V_1 , V_30 ) ;
V_74 -> V_100 -= V_166 - 1 ;
F_51 ( V_74 ) ;
F_56 ( V_27 , V_109 , - V_166 ) ;
F_56 ( V_27 , V_110 , - ( V_166 - 1 ) ) ;
if ( ( error = F_83 ( V_5 , & V_10 ) ) ) {
F_82 ( V_1 , L_7 ,
V_168 , error ) ;
goto V_142;
}
F_84 ( F_45 ( V_1 ,
V_30 , F_85 ( V_1 , V_16 . V_11 ) ) ,
F_41 ( V_1 ) , V_163 , V_1 ) ;
} else {
* V_164 = 0 ;
error = F_7 ( V_5 , & V_16 ) ;
if ( error ) {
F_82 ( V_1 , L_8 ,
V_168 , error ) ;
goto V_142;
}
F_49 ( & V_19 -> V_24 , 1 ) ;
F_55 ( V_27 , V_67 , V_107 ) ;
V_74 = F_50 ( V_1 , V_30 ) ;
V_74 -> V_100 ++ ;
F_51 ( V_74 ) ;
F_56 ( V_27 , V_110 , 1 ) ;
}
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_142;
F_53 ( V_5 , V_105 ) ;
return 0 ;
V_142:
F_53 ( V_5 , V_104 ) ;
return error ;
}
STATIC int
F_86 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_30 ,
T_2 V_134 ,
T_6 V_31 ,
T_6 * V_174 ,
T_6 * V_175 ,
int V_118 )
{
struct V_138 V_16 ;
struct V_4 * V_5 ;
struct V_34 * V_67 ;
int error ;
int V_10 ;
error = F_79 ( V_1 , V_27 , V_30 , & V_67 ) ;
if ( error ) {
F_87 ( V_1 ,
L_9 ,
V_168 , error , V_30 ) ;
return error ;
}
V_5 = F_52 ( V_1 , V_27 , V_67 , V_30 ) ;
error = F_5 ( V_5 , V_134 , V_146 , & V_10 ) ;
if ( ! error ) {
if ( V_10 )
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( ! error && V_10 == 0 )
error = V_169 ;
}
F_80 ( V_27 , V_67 ) ;
F_53 ( V_5 , V_105 ) ;
if ( error )
return error ;
if ( V_16 . V_11 > V_134 ||
V_16 . V_11 + F_23 ( V_1 ) <= V_134 )
return V_169 ;
if ( ( V_118 & V_176 ) &&
( V_16 . V_13 & F_77 ( V_134 - V_16 . V_11 ) ) )
return V_169 ;
* V_174 = F_43 ( V_1 , V_16 . V_11 ) ;
* V_175 = V_31 - * V_174 ;
return 0 ;
}
int
F_88 (
T_14 * V_1 ,
T_10 * V_27 ,
T_8 V_6 ,
struct F_88 * V_177 ,
T_9 V_118 )
{
T_6 V_31 ;
T_2 V_134 ;
T_5 V_30 ;
int V_37 ;
T_6 V_174 ;
T_6 V_178 ;
int error ;
int V_140 ;
T_6 V_175 ;
ASSERT ( V_6 != V_158 ) ;
V_30 = F_64 ( V_1 , V_6 ) ;
V_134 = F_72 ( V_1 , V_6 ) ;
V_31 = F_43 ( V_1 , V_134 ) ;
if ( V_30 >= V_1 -> V_2 . V_161 || V_31 >= V_1 -> V_2 . V_170 ||
V_6 != F_20 ( V_1 , V_30 , V_134 ) ) {
#ifdef F_89
if ( V_118 & V_176 )
return F_40 ( V_169 ) ;
if ( V_30 >= V_1 -> V_2 . V_161 ) {
F_87 ( V_1 ,
L_10 ,
V_168 , V_30 , V_1 -> V_2 . V_161 ) ;
}
if ( V_31 >= V_1 -> V_2 . V_170 ) {
F_87 ( V_1 ,
L_11 ,
V_168 , ( unsigned long long ) V_31 ,
( unsigned long ) V_1 -> V_2 . V_170 ) ;
}
if ( V_6 != F_20 ( V_1 , V_30 , V_134 ) ) {
F_87 ( V_1 ,
L_12 ,
V_168 , V_6 ,
F_20 ( V_1 , V_30 , V_134 ) ) ;
}
F_90 () ;
#endif
return F_40 ( V_169 ) ;
}
V_37 = F_4 ( V_1 ) >> V_1 -> V_2 . V_179 ;
if ( V_118 & V_176 ) {
error = F_86 ( V_1 , V_27 , V_30 , V_134 , V_31 ,
& V_174 , & V_175 , V_118 ) ;
if ( error )
return error ;
goto V_180;
}
if ( F_4 ( V_1 ) <= V_1 -> V_2 . V_43 ) {
V_140 = F_91 ( V_1 , V_6 ) ;
ASSERT ( V_140 < V_1 -> V_2 . V_44 ) ;
V_177 -> V_181 = F_25 ( V_1 , V_30 , V_31 ) ;
V_177 -> V_182 = F_92 ( V_1 , 1 ) ;
V_177 -> V_183 = ( V_184 ) ( V_140 << V_1 -> V_2 . V_54 ) ;
return 0 ;
}
if ( V_1 -> V_185 ) {
V_175 = V_31 & V_1 -> V_185 ;
V_174 = V_31 - V_175 ;
} else {
error = F_86 ( V_1 , V_27 , V_30 , V_134 , V_31 ,
& V_174 , & V_175 , V_118 ) ;
if ( error )
return error ;
}
V_180:
ASSERT ( V_31 >= V_174 ) ;
V_178 = V_174 +
( ( V_175 / V_37 ) * V_37 ) ;
V_140 = ( ( V_31 - V_178 ) * V_1 -> V_2 . V_44 ) +
F_91 ( V_1 , V_6 ) ;
V_177 -> V_181 = F_25 ( V_1 , V_30 , V_178 ) ;
V_177 -> V_182 = F_92 ( V_1 , V_37 ) ;
V_177 -> V_183 = ( V_184 ) ( V_140 << V_1 -> V_2 . V_54 ) ;
if ( ( V_177 -> V_181 + V_177 -> V_182 ) >
F_92 ( V_1 , V_1 -> V_2 . V_186 ) ) {
F_87 ( V_1 ,
L_13 ,
V_168 , ( unsigned long long ) V_177 -> V_181 ,
( unsigned long long ) V_177 -> V_182 ,
F_92 ( V_1 , V_1 -> V_2 . V_186 ) ) ;
return F_40 ( V_169 ) ;
}
return 0 ;
}
void
F_93 (
T_14 * V_1 )
{
int V_187 ;
T_9 V_188 ;
T_9 V_189 ;
int V_190 ;
int V_191 ;
V_189 = ( 1LL << F_94 ( V_1 ) ) >>
V_192 ;
V_190 = V_1 -> V_193 [ 0 ] ;
V_191 = V_1 -> V_193 [ 1 ] ;
V_188 = ( V_189 + V_190 - 1 ) / V_190 ;
for ( V_187 = 1 ; V_188 > 1 ; V_187 ++ )
V_188 = ( V_188 + V_191 - 1 ) / V_191 ;
V_1 -> V_90 = V_187 ;
}
void
F_55 (
T_10 * V_27 ,
T_11 * V_194 ,
int V_195 )
{
int V_196 ;
int V_197 ;
static const short V_198 [] = {
F_95 ( T_12 , V_171 ) ,
F_95 ( T_12 , V_199 ) ,
F_95 ( T_12 , V_82 ) ,
F_95 ( T_12 , V_83 ) ,
F_95 ( T_12 , V_99 ) ,
F_95 ( T_12 , V_96 ) ,
F_95 ( T_12 , V_200 ) ,
F_95 ( T_12 , V_24 ) ,
F_95 ( T_12 , V_81 ) ,
F_95 ( T_12 , V_201 ) ,
F_95 ( T_12 , V_202 ) ,
sizeof( T_12 )
} ;
#ifdef F_89
T_12 * V_19 ;
V_19 = F_42 ( V_194 ) ;
ASSERT ( V_19 -> V_171 == F_8 ( V_172 ) ) ;
#endif
F_96 ( V_195 , V_198 , V_203 , & V_196 , & V_197 ) ;
F_97 ( V_27 , V_194 , V_204 ) ;
F_34 ( V_27 , V_194 , V_196 , V_197 ) ;
}
STATIC void
F_98 (
struct V_18 * V_19 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_205 ; V_10 ++ )
ASSERT ( V_19 -> V_202 [ V_10 ] ) ;
}
static bool
F_99 (
struct V_34 * V_194 )
{
struct V_25 * V_1 = V_194 -> V_206 -> V_207 ;
struct V_18 * V_19 = F_42 ( V_194 ) ;
if ( F_19 ( & V_1 -> V_2 ) &&
! F_100 ( & V_19 -> V_208 , & V_1 -> V_2 . V_64 ) )
return false ;
if ( V_19 -> V_171 != F_8 ( V_172 ) )
return false ;
if ( ! F_101 ( F_13 ( V_19 -> V_199 ) ) )
return false ;
if ( V_194 -> V_209 && F_13 ( V_19 -> V_82 ) != V_194 -> V_209 -> V_210 )
return false ;
F_98 ( V_19 ) ;
return true ;
}
static void
F_102 (
struct V_34 * V_194 )
{
struct V_25 * V_1 = V_194 -> V_206 -> V_207 ;
int V_211 = 1 ;
if ( F_19 ( & V_1 -> V_2 ) )
V_211 = F_103 ( V_194 -> V_212 , F_28 ( V_194 -> V_52 ) ,
F_95 ( struct V_18 , V_213 ) ) ;
V_211 = V_211 && F_99 ( V_194 ) ;
if ( F_47 ( F_104 ( ! V_211 , V_1 , V_214 ,
V_215 ) ) ) {
F_105 ( V_168 , V_216 , V_1 , V_194 -> V_212 ) ;
F_106 ( V_194 , V_217 ) ;
}
}
static void
F_107 (
struct V_34 * V_194 )
{
struct V_25 * V_1 = V_194 -> V_206 -> V_207 ;
struct V_218 * V_219 = V_194 -> V_220 ;
if ( ! F_99 ( V_194 ) ) {
F_105 ( V_168 , V_216 , V_1 , V_194 -> V_212 ) ;
F_106 ( V_194 , V_217 ) ;
return;
}
if ( ! F_19 ( & V_1 -> V_2 ) )
return;
if ( V_219 )
F_42 ( V_194 ) -> V_221 = F_9 ( V_219 -> V_222 . V_223 ) ;
F_108 ( V_194 -> V_212 , F_28 ( V_194 -> V_52 ) ,
F_95 ( struct V_18 , V_213 ) ) ;
}
int
F_109 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_30 ,
struct V_34 * * V_224 )
{
int error ;
ASSERT ( V_30 != V_131 ) ;
error = F_110 ( V_1 , V_27 , V_1 -> V_46 ,
F_111 ( V_1 , V_30 , F_112 ( V_1 ) ) ,
F_113 ( V_1 , 1 ) , 0 , V_224 , & V_225 ) ;
if ( error )
return error ;
ASSERT ( ! F_114 ( * V_224 ) ) ;
F_115 ( * V_224 , V_226 ) ;
return 0 ;
}
int
F_79 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_30 ,
struct V_34 * * V_224 )
{
struct V_18 * V_19 ;
struct V_73 * V_74 ;
int error ;
error = F_109 ( V_1 , V_27 , V_30 , V_224 ) ;
if ( error )
return error ;
V_19 = F_42 ( * V_224 ) ;
V_74 = F_50 ( V_1 , V_30 ) ;
if ( ! V_74 -> V_126 ) {
V_74 -> V_100 = F_13 ( V_19 -> V_24 ) ;
V_74 -> V_227 = F_13 ( V_19 -> V_99 ) ;
V_74 -> V_126 = 1 ;
}
ASSERT ( V_74 -> V_100 == F_13 ( V_19 -> V_24 ) ||
F_17 ( V_1 ) ) ;
F_51 ( V_74 ) ;
return 0 ;
}
int
F_65 (
T_14 * V_1 ,
T_10 * V_27 ,
T_5 V_30 )
{
T_11 * V_194 = NULL ;
int error ;
error = F_79 ( V_1 , V_27 , V_30 , & V_194 ) ;
if ( error )
return error ;
if ( V_194 )
F_80 ( V_27 , V_194 ) ;
return 0 ;
}
