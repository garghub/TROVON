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
T_5 V_19 ,
T_6 free ,
int * V_9 )
{
V_6 -> V_10 . V_11 . V_13 = V_19 ;
V_6 -> V_10 . V_11 . V_14 = free ;
return F_15 ( V_6 , V_9 ) ;
}
STATIC int
F_16 (
struct V_20 * V_1 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
T_2 V_25 ,
T_2 V_26 ,
T_7 V_27 )
{
struct V_5 * V_6 ;
struct V_28 * V_29 = F_17 ( V_24 ) ;
T_8 V_30 = F_12 ( V_29 -> V_31 ) ;
T_2 V_32 ;
int V_11 ;
int error ;
V_6 = F_18 ( V_1 , V_22 , V_24 , V_30 , V_27 ) ;
for ( V_32 = V_25 ;
V_32 < V_25 + V_26 ;
V_32 += V_33 ) {
error = F_4 ( V_6 , V_32 , V_34 , & V_11 ) ;
if ( error ) {
F_19 ( V_6 , V_35 ) ;
return error ;
}
ASSERT ( V_11 == 0 ) ;
error = F_14 ( V_6 , V_33 ,
V_36 , & V_11 ) ;
if ( error ) {
F_19 ( V_6 , V_35 ) ;
return error ;
}
ASSERT ( V_11 == 1 ) ;
}
F_19 ( V_6 , V_37 ) ;
return 0 ;
}
STATIC int
F_20 (
struct V_5 * V_6 ,
struct V_28 * V_29 )
{
if ( V_6 -> V_38 == 1 ) {
T_4 V_17 ;
int V_19 = 0 ;
int error ;
int V_11 ;
error = F_4 ( V_6 , 0 , V_39 , & V_11 ) ;
if ( error )
return error ;
do {
error = F_10 ( V_6 , & V_17 , & V_11 ) ;
if ( error )
return error ;
if ( V_11 ) {
V_19 += V_17 . V_13 ;
error = F_21 ( V_6 , 0 , & V_11 ) ;
if ( error )
return error ;
}
} while ( V_11 == 1 );
if ( ! F_22 ( V_6 -> V_40 ) )
ASSERT ( V_19 == F_12 ( V_29 -> V_41 ) ) ;
}
return 0 ;
}
int
F_23 (
struct V_20 * V_1 ,
struct V_21 * V_22 ,
struct V_42 * V_43 ,
T_8 V_30 ,
T_9 V_44 ,
T_9 V_45 ,
unsigned int V_46 )
{
struct V_23 * V_47 ;
struct V_48 * free ;
int V_49 , V_50 , V_51 ;
int V_52 ;
int V_11 , V_53 ;
T_10 V_54 ;
T_11 V_7 = 0 ;
V_50 = F_24 ( V_1 ) ;
V_51 = V_50 << V_1 -> V_2 . V_55 ;
V_49 = V_45 / V_50 ;
if ( F_25 ( & V_1 -> V_2 ) ) {
V_52 = 3 ;
V_7 = F_26 ( V_1 , V_30 ,
F_27 ( V_1 , V_44 , 0 ) ) ;
if ( V_22 )
F_28 ( V_22 , V_30 , V_44 , V_1 -> V_56 ,
V_1 -> V_2 . V_57 , V_45 , V_46 ) ;
} else
V_52 = 2 ;
for ( V_53 = 0 ; V_53 < V_49 ; V_53 ++ ) {
V_54 = F_29 ( V_1 , V_30 , V_44 + ( V_53 * V_50 ) ) ;
V_47 = F_30 ( V_22 , V_1 -> V_58 , V_54 ,
V_1 -> V_59 * V_50 ,
V_60 ) ;
if ( ! V_47 )
return V_61 ;
V_47 -> V_62 = & V_63 ;
F_31 ( V_47 , 0 , F_32 ( V_47 -> V_64 ) ) ;
for ( V_11 = 0 ; V_11 < V_51 ; V_11 ++ ) {
int V_65 = V_11 << V_1 -> V_2 . V_66 ;
T_12 V_67 = F_33 ( V_52 ) ;
free = F_34 ( V_1 , V_47 , V_11 ) ;
free -> V_68 = F_35 ( V_69 ) ;
free -> V_70 = V_52 ;
free -> V_71 = F_7 ( V_46 ) ;
free -> V_72 = F_7 ( V_73 ) ;
if ( V_52 == 3 ) {
free -> V_74 = F_8 ( V_7 ) ;
V_7 ++ ;
F_36 ( & free -> V_75 , & V_1 -> V_2 . V_76 ) ;
F_37 ( V_1 , free ) ;
} else if ( V_22 ) {
F_38 ( V_22 , V_47 , V_65 ,
V_65 + V_67 - 1 ) ;
}
}
if ( V_22 ) {
F_39 ( V_22 , V_47 ) ;
if ( V_52 == 3 ) {
F_40 ( V_22 , V_47 ) ;
F_38 ( V_22 , V_47 , 0 ,
F_32 ( V_47 -> V_64 ) - 1 ) ;
}
} else {
V_47 -> V_77 |= V_78 ;
F_41 ( V_47 , V_43 ) ;
F_42 ( V_47 ) ;
}
}
return 0 ;
}
STATIC int
F_43 (
T_13 * V_22 ,
T_14 * V_24 ,
int * V_79 )
{
T_15 * V_29 ;
T_1 args ;
T_8 V_30 ;
int error ;
T_2 V_25 ;
T_2 V_26 ;
int V_80 = 0 ;
struct V_81 * V_82 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_22 = V_22 ;
args . V_1 = V_22 -> V_83 ;
V_26 = args . V_1 -> V_56 ;
if ( args . V_1 -> V_84 &&
args . V_1 -> V_2 . V_85 + V_26 > args . V_1 -> V_84 )
return F_44 ( V_86 ) ;
args . V_87 = args . V_88 = args . V_1 -> V_89 ;
V_29 = F_17 ( V_24 ) ;
V_25 = F_12 ( V_29 -> V_90 ) ;
V_30 = F_12 ( V_29 -> V_31 ) ;
args . V_44 = F_45 ( args . V_1 , V_25 ) +
args . V_1 -> V_89 ;
if ( F_46 ( V_25 != V_73 &&
( args . V_44 < F_12 ( V_29 -> V_91 ) ) ) ) {
args . V_92 = F_47 ( args . V_1 , V_30 , args . V_44 ) ;
args . type = V_93 ;
args . V_94 = 1 ;
args . V_95 = 1 ;
args . V_96 = F_1 ( & args ) - 1 ;
args . V_97 = args . V_1 -> V_98 - 1 ;
if ( ( error = F_48 ( & args ) ) )
return error ;
args . V_96 = 0 ;
} else
args . V_92 = V_99 ;
if ( F_49 ( args . V_92 == V_99 ) ) {
V_80 = 0 ;
if ( args . V_1 -> V_100 ) {
ASSERT ( ! ( args . V_1 -> V_101 & V_102 ) ) ;
args . V_95 = args . V_1 -> V_103 ;
V_80 = 1 ;
} else
args . V_95 = F_1 ( & args ) ;
args . V_44 = F_12 ( V_29 -> V_104 ) ;
args . V_92 = F_47 ( args . V_1 , V_30 , args . V_44 ) ;
args . type = V_105 ;
args . V_94 = 1 ;
args . V_97 = args . V_1 -> V_98 - 1 ;
if ( ( error = F_48 ( & args ) ) )
return error ;
}
if ( V_80 && args . V_92 == V_99 ) {
args . type = V_105 ;
args . V_44 = F_12 ( V_29 -> V_104 ) ;
args . V_92 = F_47 ( args . V_1 , V_30 , args . V_44 ) ;
args . V_95 = F_1 ( & args ) ;
if ( ( error = F_48 ( & args ) ) )
return error ;
}
if ( args . V_92 == V_99 ) {
* V_79 = 0 ;
return 0 ;
}
ASSERT ( args . V_106 == args . V_87 ) ;
error = F_23 ( args . V_1 , V_22 , NULL , V_30 , args . V_44 ,
args . V_106 , F_50 () ) ;
if ( error )
return error ;
V_25 = F_27 ( args . V_1 , args . V_44 , 0 ) ;
F_51 ( & V_29 -> V_107 , V_26 ) ;
F_51 ( & V_29 -> V_41 , V_26 ) ;
V_82 = F_52 ( args . V_1 , V_30 ) ;
V_82 -> V_108 += V_26 ;
F_53 ( V_82 ) ;
V_29 -> V_90 = F_7 ( V_25 ) ;
error = F_16 ( args . V_1 , V_22 , V_24 , V_25 , V_26 ,
V_109 ) ;
if ( error )
return error ;
if ( F_54 ( & args . V_1 -> V_2 ) ) {
error = F_16 ( args . V_1 , V_22 , V_24 , V_25 , V_26 ,
V_110 ) ;
if ( error )
return error ;
}
F_55 ( V_22 , V_24 ,
V_111 | V_112 | V_113 ) ;
F_56 ( V_22 , V_114 , ( long ) V_26 ) ;
F_56 ( V_22 , V_115 , ( long ) V_26 ) ;
* V_79 = 1 ;
return 0 ;
}
STATIC T_8
F_57 (
T_16 * V_1 )
{
T_8 V_30 ;
F_58 ( & V_1 -> V_116 ) ;
V_30 = V_1 -> V_117 ;
if ( ++ V_1 -> V_117 >= V_1 -> V_118 )
V_1 -> V_117 = 0 ;
F_59 ( & V_1 -> V_116 ) ;
return V_30 ;
}
STATIC T_8
F_60 (
T_13 * V_22 ,
T_11 V_119 ,
T_17 V_120 ,
int V_121 )
{
T_8 V_122 ;
T_8 V_30 ;
int V_123 ;
T_18 V_124 ;
T_18 V_125 = 0 ;
T_16 * V_1 ;
int V_126 ;
T_19 * V_82 ;
T_8 V_127 ;
int error ;
V_126 = F_61 ( V_120 ) || F_62 ( V_120 ) || F_63 ( V_120 ) ;
V_1 = V_22 -> V_83 ;
V_122 = V_1 -> V_118 ;
if ( F_61 ( V_120 ) )
V_127 = F_57 ( V_1 ) ;
else {
V_127 = F_64 ( V_1 , V_119 ) ;
if ( V_127 >= V_122 )
V_127 = 0 ;
}
ASSERT ( V_127 < V_122 ) ;
V_30 = V_127 ;
V_123 = V_128 ;
for (; ; ) {
V_82 = F_52 ( V_1 , V_30 ) ;
if ( ! V_82 -> V_129 ) {
F_57 ( V_1 ) ;
goto V_130;
}
if ( ! V_82 -> V_131 ) {
error = F_65 ( V_1 , V_22 , V_30 ) ;
if ( error )
goto V_130;
}
if ( V_82 -> V_108 ) {
F_53 ( V_82 ) ;
return V_30 ;
}
if ( ! V_121 )
goto V_130;
if ( ! V_82 -> V_132 ) {
error = F_66 ( V_1 , V_22 , V_30 , V_123 ) ;
if ( error )
goto V_130;
}
V_124 = V_1 -> V_89 ;
V_125 = V_82 -> V_133 ;
if ( ! V_125 )
V_125 = V_82 -> V_134 > 0 ;
if ( V_82 -> V_135 >= V_126 + V_124 &&
V_125 >= V_124 ) {
F_53 ( V_82 ) ;
return V_30 ;
}
V_130:
F_53 ( V_82 ) ;
if ( F_22 ( V_1 ) )
return V_136 ;
V_30 ++ ;
if ( V_30 >= V_122 )
V_30 = 0 ;
if ( V_30 == V_127 ) {
if ( V_123 == 0 )
return V_136 ;
V_123 = 0 ;
}
}
}
STATIC int
F_67 (
struct V_5 * V_6 ,
T_4 * V_17 ,
int * V_137 ,
int V_138 )
{
int error ;
int V_11 ;
if ( V_138 )
error = F_68 ( V_6 , 0 , & V_11 ) ;
else
error = F_21 ( V_6 , 0 , & V_11 ) ;
if ( error )
return error ;
* V_137 = ! V_11 ;
if ( V_11 ) {
error = F_10 ( V_6 , V_17 , & V_11 ) ;
if ( error )
return error ;
F_69 ( V_11 == 1 ) ;
}
return 0 ;
}
STATIC int
F_70 (
struct V_5 * V_6 ,
T_2 V_139 ,
T_4 * V_17 ,
int * V_137 )
{
int error ;
int V_11 ;
error = F_4 ( V_6 , V_139 , V_34 , & V_11 ) ;
if ( error )
return error ;
* V_137 = ! V_11 ;
if ( V_11 ) {
error = F_10 ( V_6 , V_17 , & V_11 ) ;
if ( error )
return error ;
F_69 ( V_11 == 1 ) ;
}
return 0 ;
}
STATIC int
F_71 (
struct V_21 * V_22 ,
struct V_23 * V_24 ,
T_11 V_119 ,
T_11 * V_140 )
{
struct V_20 * V_1 = V_22 -> V_83 ;
struct V_28 * V_29 = F_17 ( V_24 ) ;
T_8 V_30 = F_12 ( V_29 -> V_31 ) ;
T_8 V_127 = F_64 ( V_1 , V_119 ) ;
T_2 V_141 = F_72 ( V_1 , V_119 ) ;
struct V_81 * V_82 ;
struct V_5 * V_6 , * V_142 ;
struct V_143 V_17 , V_144 ;
T_11 V_7 ;
int error ;
int V_145 ;
int V_11 , V_53 ;
V_82 = F_52 ( V_1 , V_30 ) ;
ASSERT ( V_82 -> V_131 ) ;
ASSERT ( V_82 -> V_129 ) ;
ASSERT ( V_82 -> V_108 > 0 ) ;
V_146:
V_6 = F_18 ( V_1 , V_22 , V_24 , V_30 , V_109 ) ;
if ( ! V_141 )
V_141 = F_12 ( V_29 -> V_90 ) ;
error = F_20 ( V_6 , V_29 ) ;
if ( error )
goto V_147;
if ( V_127 == V_30 ) {
int V_148 ;
int V_149 ;
int V_150 = 10 ;
error = F_4 ( V_6 , V_141 , V_151 , & V_11 ) ;
if ( error )
goto V_147;
F_73 ( V_11 == 1 , V_147 ) ;
error = F_10 ( V_6 , & V_17 , & V_53 ) ;
if ( error )
goto V_147;
F_73 ( V_53 == 1 , V_147 ) ;
if ( V_17 . V_13 > 0 ) {
goto V_152;
}
error = F_74 ( V_6 , & V_142 ) ;
if ( error )
goto V_147;
if ( V_141 != V_73 &&
V_82 -> V_153 == V_141 &&
V_82 -> V_154 != V_73 &&
V_82 -> V_155 != V_73 ) {
error = F_70 ( V_142 , V_82 -> V_154 ,
& V_144 , & V_148 ) ;
if ( error )
goto V_156;
error = F_70 ( V_6 , V_82 -> V_155 ,
& V_17 , & V_149 ) ;
if ( error )
goto V_156;
} else {
error = F_67 ( V_142 , & V_144 , & V_148 , 1 ) ;
if ( error )
goto V_156;
error = F_67 ( V_6 , & V_17 , & V_149 , 0 ) ;
if ( error )
goto V_156;
}
while ( ! V_148 || ! V_149 ) {
int V_157 ;
if ( ! -- V_150 ) {
F_19 ( V_142 , V_37 ) ;
V_82 -> V_154 = V_144 . V_12 ;
V_82 -> V_155 = V_17 . V_12 ;
V_82 -> V_153 = V_141 ;
goto V_25;
}
if ( ! V_148 && ! V_149 ) {
V_157 = V_141 -
( V_144 . V_12 + V_33 - 1 ) <
V_17 . V_12 - V_141 ;
} else {
V_157 = ! V_148 ;
}
if ( V_157 && V_144 . V_13 ) {
V_17 = V_144 ;
F_19 ( V_6 , V_37 ) ;
V_6 = V_142 ;
V_82 -> V_154 = V_144 . V_12 ;
V_82 -> V_155 = V_17 . V_12 ;
V_82 -> V_153 = V_141 ;
goto V_152;
}
if ( ! V_157 && V_17 . V_13 ) {
F_19 ( V_142 , V_37 ) ;
V_82 -> V_154 = V_144 . V_12 ;
V_82 -> V_155 = V_17 . V_12 ;
V_82 -> V_153 = V_141 ;
goto V_152;
}
if ( V_157 ) {
error = F_67 ( V_142 , & V_144 ,
& V_148 , 1 ) ;
} else {
error = F_67 ( V_6 , & V_17 ,
& V_149 , 0 ) ;
}
if ( error )
goto V_156;
}
V_82 -> V_153 = V_73 ;
V_82 -> V_154 = V_73 ;
V_82 -> V_155 = V_73 ;
F_19 ( V_142 , V_37 ) ;
F_19 ( V_6 , V_37 ) ;
goto V_146;
}
V_25:
if ( V_29 -> V_90 != F_7 ( V_73 ) ) {
error = F_4 ( V_6 , F_12 ( V_29 -> V_90 ) ,
V_34 , & V_11 ) ;
if ( error )
goto V_147;
if ( V_11 == 1 ) {
error = F_10 ( V_6 , & V_17 , & V_53 ) ;
if ( error )
goto V_147;
if ( V_53 == 1 && V_17 . V_13 > 0 ) {
goto V_152;
}
}
}
error = F_4 ( V_6 , 0 , V_39 , & V_11 ) ;
if ( error )
goto V_147;
F_73 ( V_11 == 1 , V_147 ) ;
for (; ; ) {
error = F_10 ( V_6 , & V_17 , & V_11 ) ;
if ( error )
goto V_147;
F_73 ( V_11 == 1 , V_147 ) ;
if ( V_17 . V_13 > 0 )
break;
error = F_21 ( V_6 , 0 , & V_11 ) ;
if ( error )
goto V_147;
F_73 ( V_11 == 1 , V_147 ) ;
}
V_152:
V_145 = F_75 ( V_17 . V_14 ) ;
ASSERT ( V_145 >= 0 ) ;
ASSERT ( V_145 < V_33 ) ;
ASSERT ( ( F_76 ( V_1 , V_17 . V_12 ) %
V_33 ) == 0 ) ;
V_7 = F_26 ( V_1 , V_30 , V_17 . V_12 + V_145 ) ;
V_17 . V_14 &= ~ F_77 ( V_145 ) ;
V_17 . V_13 -- ;
error = F_6 ( V_6 , & V_17 ) ;
if ( error )
goto V_147;
F_51 ( & V_29 -> V_41 , - 1 ) ;
F_55 ( V_22 , V_24 , V_112 ) ;
V_82 -> V_108 -- ;
error = F_20 ( V_6 , V_29 ) ;
if ( error )
goto V_147;
F_19 ( V_6 , V_37 ) ;
F_56 ( V_22 , V_115 , - 1 ) ;
F_53 ( V_82 ) ;
* V_140 = V_7 ;
return 0 ;
V_156:
F_19 ( V_142 , V_35 ) ;
V_147:
F_19 ( V_6 , V_35 ) ;
F_53 ( V_82 ) ;
return error ;
}
STATIC int
F_78 (
T_2 V_141 ,
struct V_5 * * V_158 ,
struct V_143 * V_17 )
{
struct V_5 * V_159 = * V_158 ;
struct V_5 * V_160 ;
struct V_143 V_161 ;
int error ;
int V_11 , V_53 ;
error = F_4 ( V_159 , V_141 , V_151 , & V_11 ) ;
if ( error )
return error ;
if ( V_11 == 1 ) {
error = F_10 ( V_159 , V_17 , & V_11 ) ;
if ( error )
return error ;
F_69 ( V_11 == 1 ) ;
if ( V_141 >= V_17 -> V_12 &&
V_141 < ( V_17 -> V_12 + V_33 ) )
return 0 ;
}
error = F_74 ( V_159 , & V_160 ) ;
if ( error )
return error ;
error = F_4 ( V_160 , V_141 , V_39 , & V_53 ) ;
if ( error )
goto V_162;
if ( V_53 == 1 ) {
error = F_10 ( V_160 , & V_161 , & V_53 ) ;
if ( error )
goto V_162;
F_73 ( V_53 == 1 , V_162 ) ;
}
F_73 ( V_11 == 1 || V_53 == 1 , V_162 ) ;
if ( V_11 == 1 && V_53 == 1 ) {
if ( ( V_141 - V_17 -> V_12 + V_33 - 1 ) >
( V_161 . V_12 - V_141 ) ) {
* V_17 = V_161 ;
F_19 ( V_159 , V_37 ) ;
* V_158 = V_160 ;
} else {
F_19 ( V_160 , V_37 ) ;
}
} else if ( V_53 == 1 ) {
* V_17 = V_161 ;
F_19 ( V_159 , V_37 ) ;
* V_158 = V_160 ;
} else if ( V_11 == 1 ) {
F_19 ( V_160 , V_37 ) ;
}
return 0 ;
V_162:
F_19 ( V_160 , V_35 ) ;
return error ;
}
STATIC int
F_79 (
struct V_28 * V_29 ,
struct V_5 * V_6 ,
struct V_143 * V_17 )
{
int error ;
int V_11 ;
if ( V_29 -> V_90 != F_7 ( V_73 ) ) {
error = F_4 ( V_6 , V_29 -> V_90 , V_34 ,
& V_11 ) ;
if ( error )
return error ;
if ( V_11 == 1 ) {
error = F_10 ( V_6 , V_17 , & V_11 ) ;
if ( error )
return error ;
F_69 ( V_11 == 1 ) ;
return 0 ;
}
}
error = F_4 ( V_6 , 0 , V_39 , & V_11 ) ;
if ( error )
return error ;
F_69 ( V_11 == 1 ) ;
error = F_10 ( V_6 , V_17 , & V_11 ) ;
if ( error )
return error ;
F_69 ( V_11 == 1 ) ;
return 0 ;
}
STATIC int
F_80 (
struct V_5 * V_6 ,
struct V_143 * V_163 ,
int V_145 )
{
struct V_143 V_17 ;
int error ;
int V_11 ;
error = F_4 ( V_6 , V_163 -> V_12 , V_34 , & V_11 ) ;
if ( error )
return error ;
F_69 ( V_11 == 1 ) ;
error = F_10 ( V_6 , & V_17 , & V_11 ) ;
if ( error )
return error ;
F_69 ( V_11 == 1 ) ;
ASSERT ( ( F_76 ( V_6 -> V_40 , V_17 . V_12 ) %
V_33 ) == 0 ) ;
V_17 . V_14 &= ~ F_77 ( V_145 ) ;
V_17 . V_13 -- ;
F_69 ( ( V_17 . V_14 == V_163 -> V_14 ) &&
( V_17 . V_13 == V_163 -> V_13 ) ) ;
error = F_6 ( V_6 , & V_17 ) ;
if ( error )
return error ;
return 0 ;
}
STATIC int
F_81 (
struct V_21 * V_22 ,
struct V_23 * V_24 ,
T_11 V_119 ,
T_11 * V_140 )
{
struct V_20 * V_1 = V_22 -> V_83 ;
struct V_28 * V_29 = F_17 ( V_24 ) ;
T_8 V_30 = F_12 ( V_29 -> V_31 ) ;
T_8 V_127 = F_64 ( V_1 , V_119 ) ;
T_2 V_141 = F_72 ( V_1 , V_119 ) ;
struct V_81 * V_82 ;
struct V_5 * V_6 ;
struct V_5 * V_164 ;
struct V_143 V_17 ;
T_11 V_7 ;
int error ;
int V_145 ;
int V_11 ;
if ( ! F_54 ( & V_1 -> V_2 ) )
return F_71 ( V_22 , V_24 , V_119 , V_140 ) ;
V_82 = F_52 ( V_1 , V_30 ) ;
if ( ! V_141 )
V_141 = F_12 ( V_29 -> V_90 ) ;
V_6 = F_18 ( V_1 , V_22 , V_24 , V_30 , V_110 ) ;
error = F_20 ( V_6 , V_29 ) ;
if ( error )
goto V_165;
if ( V_30 == V_127 )
error = F_78 ( V_141 , & V_6 , & V_17 ) ;
else
error = F_79 ( V_29 , V_6 , & V_17 ) ;
if ( error )
goto V_165;
V_145 = F_75 ( V_17 . V_14 ) ;
ASSERT ( V_145 >= 0 ) ;
ASSERT ( V_145 < V_33 ) ;
ASSERT ( ( F_76 ( V_1 , V_17 . V_12 ) %
V_33 ) == 0 ) ;
V_7 = F_26 ( V_1 , V_30 , V_17 . V_12 + V_145 ) ;
V_17 . V_14 &= ~ F_77 ( V_145 ) ;
V_17 . V_13 -- ;
if ( V_17 . V_13 )
error = F_6 ( V_6 , & V_17 ) ;
else
error = F_82 ( V_6 , & V_11 ) ;
if ( error )
goto V_165;
V_164 = F_18 ( V_1 , V_22 , V_24 , V_30 , V_109 ) ;
error = F_20 ( V_164 , V_29 ) ;
if ( error )
goto V_166;
error = F_80 ( V_164 , & V_17 , V_145 ) ;
if ( error )
goto V_166;
F_51 ( & V_29 -> V_41 , - 1 ) ;
F_55 ( V_22 , V_24 , V_112 ) ;
V_82 -> V_108 -- ;
F_56 ( V_22 , V_115 , - 1 ) ;
error = F_20 ( V_164 , V_29 ) ;
if ( error )
goto V_166;
error = F_20 ( V_6 , V_29 ) ;
if ( error )
goto V_166;
F_19 ( V_164 , V_37 ) ;
F_19 ( V_6 , V_37 ) ;
F_53 ( V_82 ) ;
* V_140 = V_7 ;
return 0 ;
V_166:
F_19 ( V_164 , V_35 ) ;
V_165:
F_19 ( V_6 , V_35 ) ;
F_53 ( V_82 ) ;
return error ;
}
int
F_83 (
struct V_21 * V_22 ,
T_11 V_119 ,
T_17 V_120 ,
int V_121 ,
struct V_23 * * V_167 ,
T_11 * V_140 )
{
struct V_20 * V_1 = V_22 -> V_83 ;
struct V_23 * V_24 ;
T_8 V_30 ;
int error ;
int V_168 ;
int V_169 = 0 ;
T_8 V_170 ;
struct V_81 * V_82 ;
if ( * V_167 ) {
V_24 = * V_167 ;
goto V_171;
}
V_170 = F_60 ( V_22 , V_119 , V_120 , V_121 ) ;
if ( V_170 == V_136 ) {
* V_140 = V_172 ;
return 0 ;
}
if ( V_1 -> V_84 &&
V_1 -> V_2 . V_85 + V_1 -> V_56 > V_1 -> V_84 ) {
V_169 = 1 ;
V_121 = 0 ;
}
V_30 = V_170 ;
for (; ; ) {
V_82 = F_52 ( V_1 , V_30 ) ;
if ( ! V_82 -> V_129 ) {
F_57 ( V_1 ) ;
goto V_130;
}
if ( ! V_82 -> V_131 ) {
error = F_65 ( V_1 , V_22 , V_30 ) ;
if ( error )
goto V_173;
}
if ( ! V_82 -> V_108 && ! V_121 )
goto V_130;
error = F_84 ( V_1 , V_22 , V_30 , & V_24 ) ;
if ( error )
goto V_173;
if ( V_82 -> V_108 ) {
F_53 ( V_82 ) ;
goto V_171;
}
if ( ! V_121 )
goto V_174;
error = F_43 ( V_22 , V_24 , & V_168 ) ;
if ( error ) {
F_85 ( V_22 , V_24 ) ;
if ( error != V_86 )
goto V_173;
F_53 ( V_82 ) ;
* V_140 = V_172 ;
return 0 ;
}
if ( V_168 ) {
ASSERT ( V_82 -> V_108 > 0 ) ;
F_53 ( V_82 ) ;
* V_167 = V_24 ;
* V_140 = V_172 ;
return 0 ;
}
V_174:
F_85 ( V_22 , V_24 ) ;
V_130:
F_53 ( V_82 ) ;
if ( ++ V_30 == V_1 -> V_2 . V_175 )
V_30 = 0 ;
if ( V_30 == V_170 ) {
* V_140 = V_172 ;
return V_169 ? V_86 : 0 ;
}
}
V_171:
* V_167 = NULL ;
return F_81 ( V_22 , V_24 , V_119 , V_140 ) ;
V_173:
F_53 ( V_82 ) ;
return F_44 ( error ) ;
}
STATIC int
F_86 (
struct V_20 * V_1 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
T_2 V_139 ,
struct V_176 * V_177 ,
int * V_178 ,
T_11 * V_179 ,
struct V_143 * V_180 )
{
struct V_28 * V_29 = F_17 ( V_24 ) ;
T_8 V_30 = F_12 ( V_29 -> V_31 ) ;
struct V_81 * V_82 ;
struct V_5 * V_6 ;
struct V_143 V_17 ;
int V_181 ;
int error ;
int V_11 ;
int V_182 ;
ASSERT ( V_29 -> V_183 == F_7 ( V_184 ) ) ;
ASSERT ( F_45 ( V_1 , V_139 ) < F_12 ( V_29 -> V_91 ) ) ;
V_6 = F_18 ( V_1 , V_22 , V_24 , V_30 , V_109 ) ;
error = F_20 ( V_6 , V_29 ) ;
if ( error )
goto V_147;
if ( ( error = F_4 ( V_6 , V_139 , V_151 , & V_11 ) ) ) {
F_87 ( V_1 , L_1 ,
V_185 , error ) ;
goto V_147;
}
F_73 ( V_11 == 1 , V_147 ) ;
error = F_10 ( V_6 , & V_17 , & V_11 ) ;
if ( error ) {
F_87 ( V_1 , L_2 ,
V_185 , error ) ;
goto V_147;
}
F_73 ( V_11 == 1 , V_147 ) ;
V_182 = V_139 - V_17 . V_12 ;
ASSERT ( V_182 >= 0 && V_182 < V_33 ) ;
ASSERT ( ! ( V_17 . V_14 & F_77 ( V_182 ) ) ) ;
V_17 . V_14 |= F_77 ( V_182 ) ;
V_17 . V_13 ++ ;
if ( ! ( V_1 -> V_101 & V_186 ) &&
( V_17 . V_13 == V_1 -> V_56 ) ) {
* V_178 = 1 ;
* V_179 = F_26 ( V_1 , V_30 , V_17 . V_12 ) ;
V_181 = V_1 -> V_56 ;
F_51 ( & V_29 -> V_107 , - V_181 ) ;
F_51 ( & V_29 -> V_41 , - ( V_181 - 1 ) ) ;
F_55 ( V_22 , V_24 , V_111 | V_112 ) ;
V_82 = F_52 ( V_1 , V_30 ) ;
V_82 -> V_108 -= V_181 - 1 ;
F_53 ( V_82 ) ;
F_56 ( V_22 , V_114 , - V_181 ) ;
F_56 ( V_22 , V_115 , - ( V_181 - 1 ) ) ;
if ( ( error = F_82 ( V_6 , & V_11 ) ) ) {
F_87 ( V_1 , L_3 ,
V_185 , error ) ;
goto V_147;
}
F_88 ( F_47 ( V_1 , V_30 ,
F_45 ( V_1 , V_17 . V_12 ) ) ,
V_1 -> V_89 , V_177 , V_1 ) ;
} else {
* V_178 = 0 ;
error = F_6 ( V_6 , & V_17 ) ;
if ( error ) {
F_87 ( V_1 , L_4 ,
V_185 , error ) ;
goto V_147;
}
F_51 ( & V_29 -> V_41 , 1 ) ;
F_55 ( V_22 , V_24 , V_112 ) ;
V_82 = F_52 ( V_1 , V_30 ) ;
V_82 -> V_108 ++ ;
F_53 ( V_82 ) ;
F_56 ( V_22 , V_115 , 1 ) ;
}
error = F_20 ( V_6 , V_29 ) ;
if ( error )
goto V_147;
* V_180 = V_17 ;
F_19 ( V_6 , V_37 ) ;
return 0 ;
V_147:
F_19 ( V_6 , V_35 ) ;
return error ;
}
STATIC int
F_89 (
struct V_20 * V_1 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
T_2 V_139 ,
struct V_143 * V_187 )
{
struct V_28 * V_29 = F_17 ( V_24 ) ;
T_8 V_30 = F_12 ( V_29 -> V_31 ) ;
struct V_5 * V_6 ;
struct V_143 V_17 ;
int V_145 = V_139 - V_187 -> V_12 ;
int error ;
int V_11 ;
V_6 = F_18 ( V_1 , V_22 , V_24 , V_30 , V_110 ) ;
error = F_4 ( V_6 , V_187 -> V_12 , V_34 , & V_11 ) ;
if ( error )
goto error;
if ( V_11 == 0 ) {
F_73 ( V_187 -> V_13 == 1 , error ) ;
error = F_14 ( V_6 , V_187 -> V_13 ,
V_187 -> V_14 , & V_11 ) ;
if ( error )
goto error;
ASSERT ( V_11 == 1 ) ;
goto V_188;
}
error = F_10 ( V_6 , & V_17 , & V_11 ) ;
if ( error )
goto error;
F_73 ( V_11 == 1 , error ) ;
V_17 . V_14 |= F_77 ( V_145 ) ;
V_17 . V_13 ++ ;
F_73 ( ( V_17 . V_14 == V_187 -> V_14 ) &&
( V_17 . V_13 == V_187 -> V_13 ) ,
error ) ;
if ( V_17 . V_13 == V_1 -> V_56 &&
! ( V_1 -> V_101 & V_186 ) ) {
error = F_82 ( V_6 , & V_11 ) ;
if ( error )
goto error;
ASSERT ( V_11 == 1 ) ;
} else {
error = F_6 ( V_6 , & V_17 ) ;
if ( error )
goto error;
}
V_188:
error = F_20 ( V_6 , V_29 ) ;
if ( error )
goto error;
F_19 ( V_6 , V_37 ) ;
return 0 ;
error:
F_19 ( V_6 , V_35 ) ;
return error ;
}
int
F_90 (
struct V_21 * V_22 ,
T_11 V_189 ,
struct V_176 * V_177 ,
int * V_178 ,
T_11 * V_179 )
{
T_9 V_44 ;
struct V_23 * V_24 ;
T_2 V_139 ;
T_8 V_30 ;
int error ;
struct V_20 * V_1 ;
struct V_143 V_17 ;
V_1 = V_22 -> V_83 ;
V_30 = F_64 ( V_1 , V_189 ) ;
if ( V_30 >= V_1 -> V_2 . V_175 ) {
F_87 ( V_1 , L_5 ,
V_185 , V_30 , V_1 -> V_2 . V_175 ) ;
ASSERT ( 0 ) ;
return F_44 ( V_190 ) ;
}
V_139 = F_72 ( V_1 , V_189 ) ;
if ( V_189 != F_26 ( V_1 , V_30 , V_139 ) ) {
F_87 ( V_1 , L_6 ,
V_185 , ( unsigned long long ) V_189 ,
( unsigned long long ) F_26 ( V_1 , V_30 , V_139 ) ) ;
ASSERT ( 0 ) ;
return F_44 ( V_190 ) ;
}
V_44 = F_45 ( V_1 , V_139 ) ;
if ( V_44 >= V_1 -> V_2 . V_191 ) {
F_87 ( V_1 , L_7 ,
V_185 , V_44 , V_1 -> V_2 . V_191 ) ;
ASSERT ( 0 ) ;
return F_44 ( V_190 ) ;
}
error = F_84 ( V_1 , V_22 , V_30 , & V_24 ) ;
if ( error ) {
F_87 ( V_1 , L_8 ,
V_185 , error ) ;
return error ;
}
error = F_86 ( V_1 , V_22 , V_24 , V_139 , V_177 , V_178 , V_179 ,
& V_17 ) ;
if ( error )
goto V_147;
if ( F_54 ( & V_1 -> V_2 ) ) {
error = F_89 ( V_1 , V_22 , V_24 , V_139 , & V_17 ) ;
if ( error )
goto V_147;
}
return 0 ;
V_147:
return error ;
}
STATIC int
F_91 (
struct V_20 * V_1 ,
struct V_21 * V_22 ,
T_8 V_30 ,
T_2 V_139 ,
T_9 V_44 ,
T_9 * V_192 ,
T_9 * V_193 ,
int V_123 )
{
struct V_143 V_17 ;
struct V_5 * V_6 ;
struct V_23 * V_24 ;
int error ;
int V_11 ;
error = F_84 ( V_1 , V_22 , V_30 , & V_24 ) ;
if ( error ) {
F_92 ( V_1 ,
L_9 ,
V_185 , error , V_30 ) ;
return error ;
}
V_6 = F_18 ( V_1 , V_22 , V_24 , V_30 , V_109 ) ;
error = F_4 ( V_6 , V_139 , V_151 , & V_11 ) ;
if ( ! error ) {
if ( V_11 )
error = F_10 ( V_6 , & V_17 , & V_11 ) ;
if ( ! error && V_11 == 0 )
error = V_190 ;
}
F_85 ( V_22 , V_24 ) ;
F_19 ( V_6 , V_37 ) ;
if ( error )
return error ;
if ( V_17 . V_12 > V_139 ||
V_17 . V_12 + V_1 -> V_56 <= V_139 )
return V_190 ;
if ( ( V_123 & V_194 ) &&
( V_17 . V_14 & F_77 ( V_139 - V_17 . V_12 ) ) )
return V_190 ;
* V_192 = F_45 ( V_1 , V_17 . V_12 ) ;
* V_193 = V_44 - * V_192 ;
return 0 ;
}
int
F_93 (
T_16 * V_1 ,
T_13 * V_22 ,
T_11 V_7 ,
struct F_93 * V_195 ,
T_12 V_123 )
{
T_9 V_44 ;
T_2 V_139 ;
T_8 V_30 ;
int V_50 ;
T_9 V_192 ;
T_9 V_196 ;
int error ;
int V_145 ;
T_9 V_193 ;
ASSERT ( V_7 != V_172 ) ;
V_30 = F_64 ( V_1 , V_7 ) ;
V_139 = F_72 ( V_1 , V_7 ) ;
V_44 = F_45 ( V_1 , V_139 ) ;
if ( V_30 >= V_1 -> V_2 . V_175 || V_44 >= V_1 -> V_2 . V_191 ||
V_7 != F_26 ( V_1 , V_30 , V_139 ) ) {
#ifdef F_94
if ( V_123 & V_194 )
return F_44 ( V_190 ) ;
if ( V_30 >= V_1 -> V_2 . V_175 ) {
F_92 ( V_1 ,
L_10 ,
V_185 , V_30 , V_1 -> V_2 . V_175 ) ;
}
if ( V_44 >= V_1 -> V_2 . V_191 ) {
F_92 ( V_1 ,
L_11 ,
V_185 , ( unsigned long long ) V_44 ,
( unsigned long ) V_1 -> V_2 . V_191 ) ;
}
if ( V_7 != F_26 ( V_1 , V_30 , V_139 ) ) {
F_92 ( V_1 ,
L_12 ,
V_185 , V_7 ,
F_26 ( V_1 , V_30 , V_139 ) ) ;
}
F_95 () ;
#endif
return F_44 ( V_190 ) ;
}
V_50 = F_24 ( V_1 ) ;
if ( V_123 & V_194 ) {
error = F_91 ( V_1 , V_22 , V_30 , V_139 , V_44 ,
& V_192 , & V_193 , V_123 ) ;
if ( error )
return error ;
goto V_197;
}
if ( V_50 == 1 ) {
V_145 = F_96 ( V_1 , V_7 ) ;
ASSERT ( V_145 < V_1 -> V_2 . V_198 ) ;
V_195 -> V_199 = F_29 ( V_1 , V_30 , V_44 ) ;
V_195 -> V_200 = F_97 ( V_1 , 1 ) ;
V_195 -> V_201 = ( V_202 ) ( V_145 << V_1 -> V_2 . V_66 ) ;
return 0 ;
}
if ( V_1 -> V_203 ) {
V_193 = V_44 & V_1 -> V_203 ;
V_192 = V_44 - V_193 ;
} else {
error = F_91 ( V_1 , V_22 , V_30 , V_139 , V_44 ,
& V_192 , & V_193 , V_123 ) ;
if ( error )
return error ;
}
V_197:
ASSERT ( V_44 >= V_192 ) ;
V_196 = V_192 +
( ( V_193 / V_50 ) * V_50 ) ;
V_145 = ( ( V_44 - V_196 ) * V_1 -> V_2 . V_198 ) +
F_96 ( V_1 , V_7 ) ;
V_195 -> V_199 = F_29 ( V_1 , V_30 , V_196 ) ;
V_195 -> V_200 = F_97 ( V_1 , V_50 ) ;
V_195 -> V_201 = ( V_202 ) ( V_145 << V_1 -> V_2 . V_66 ) ;
if ( ( V_195 -> V_199 + V_195 -> V_200 ) >
F_97 ( V_1 , V_1 -> V_2 . V_204 ) ) {
F_92 ( V_1 ,
L_13 ,
V_185 , ( unsigned long long ) V_195 -> V_199 ,
( unsigned long long ) V_195 -> V_200 ,
F_97 ( V_1 , V_1 -> V_2 . V_204 ) ) ;
return F_44 ( V_190 ) ;
}
return 0 ;
}
void
F_98 (
T_16 * V_1 )
{
int V_205 ;
T_12 V_206 ;
T_12 V_207 ;
int V_208 ;
int V_209 ;
V_207 = ( 1LL << F_99 ( V_1 ) ) >>
V_210 ;
V_208 = V_1 -> V_211 [ 0 ] ;
V_209 = V_1 -> V_211 [ 1 ] ;
V_206 = ( V_207 + V_208 - 1 ) / V_208 ;
for ( V_205 = 1 ; V_206 > 1 ; V_205 ++ )
V_206 = ( V_206 + V_209 - 1 ) / V_209 ;
V_1 -> V_98 = V_205 ;
}
void
F_55 (
T_13 * V_22 ,
T_14 * V_212 ,
int V_213 )
{
int V_214 ;
int V_215 ;
static const short V_216 [] = {
F_100 ( T_15 , V_183 ) ,
F_100 ( T_15 , V_217 ) ,
F_100 ( T_15 , V_31 ) ,
F_100 ( T_15 , V_91 ) ,
F_100 ( T_15 , V_107 ) ,
F_100 ( T_15 , V_104 ) ,
F_100 ( T_15 , V_218 ) ,
F_100 ( T_15 , V_41 ) ,
F_100 ( T_15 , V_90 ) ,
F_100 ( T_15 , V_219 ) ,
F_100 ( T_15 , V_220 ) ,
F_100 ( T_15 , V_221 ) ,
F_100 ( T_15 , V_222 ) ,
sizeof( T_15 )
} ;
#ifdef F_94
T_15 * V_29 ;
V_29 = F_17 ( V_212 ) ;
ASSERT ( V_29 -> V_183 == F_7 ( V_184 ) ) ;
#endif
F_101 ( V_22 , V_212 , V_223 ) ;
if ( V_213 & V_224 ) {
F_102 ( V_213 , V_216 , V_225 ,
& V_214 , & V_215 ) ;
F_38 ( V_22 , V_212 , V_214 , V_215 ) ;
}
V_213 &= ~ V_224 ;
if ( V_213 ) {
F_102 ( V_213 , V_216 , V_226 ,
& V_214 , & V_215 ) ;
F_38 ( V_22 , V_212 , V_214 , V_215 ) ;
}
}
STATIC void
F_103 (
struct V_28 * V_29 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_227 ; V_11 ++ )
ASSERT ( V_29 -> V_220 [ V_11 ] ) ;
}
static bool
F_104 (
struct V_23 * V_212 )
{
struct V_20 * V_1 = V_212 -> V_228 -> V_229 ;
struct V_28 * V_29 = F_17 ( V_212 ) ;
if ( F_25 ( & V_1 -> V_2 ) &&
! F_105 ( & V_29 -> V_230 , & V_1 -> V_2 . V_76 ) )
return false ;
if ( V_29 -> V_183 != F_7 ( V_184 ) )
return false ;
if ( ! F_106 ( F_12 ( V_29 -> V_217 ) ) )
return false ;
if ( V_212 -> V_231 && F_12 ( V_29 -> V_31 ) != V_212 -> V_231 -> V_232 )
return false ;
F_103 ( V_29 ) ;
return true ;
}
static void
F_107 (
struct V_23 * V_212 )
{
struct V_20 * V_1 = V_212 -> V_228 -> V_229 ;
if ( F_25 ( & V_1 -> V_2 ) &&
! F_108 ( V_212 , V_233 ) )
F_109 ( V_212 , V_234 ) ;
else if ( F_110 ( ! F_104 ( V_212 ) , V_1 ,
V_235 ,
V_236 ) )
F_109 ( V_212 , V_237 ) ;
if ( V_212 -> V_238 )
F_111 ( V_212 ) ;
}
static void
F_112 (
struct V_23 * V_212 )
{
struct V_20 * V_1 = V_212 -> V_228 -> V_229 ;
struct V_239 * V_240 = V_212 -> V_241 ;
if ( ! F_104 ( V_212 ) ) {
F_109 ( V_212 , V_237 ) ;
F_111 ( V_212 ) ;
return;
}
if ( ! F_25 ( & V_1 -> V_2 ) )
return;
if ( V_240 )
F_17 ( V_212 ) -> V_242 = F_8 ( V_240 -> V_243 . V_244 ) ;
F_113 ( V_212 , V_233 ) ;
}
int
F_114 (
struct V_20 * V_1 ,
struct V_21 * V_22 ,
T_8 V_30 ,
struct V_23 * * V_245 )
{
int error ;
F_115 ( V_1 , V_30 ) ;
ASSERT ( V_30 != V_136 ) ;
error = F_116 ( V_1 , V_22 , V_1 -> V_58 ,
F_117 ( V_1 , V_30 , F_118 ( V_1 ) ) ,
F_119 ( V_1 , 1 ) , 0 , V_245 , & V_246 ) ;
if ( error )
return error ;
F_120 ( * V_245 , V_247 ) ;
return 0 ;
}
int
F_84 (
struct V_20 * V_1 ,
struct V_21 * V_22 ,
T_8 V_30 ,
struct V_23 * * V_245 )
{
struct V_28 * V_29 ;
struct V_81 * V_82 ;
int error ;
F_121 ( V_1 , V_30 ) ;
error = F_114 ( V_1 , V_22 , V_30 , V_245 ) ;
if ( error )
return error ;
V_29 = F_17 ( * V_245 ) ;
V_82 = F_52 ( V_1 , V_30 ) ;
if ( ! V_82 -> V_131 ) {
V_82 -> V_108 = F_12 ( V_29 -> V_41 ) ;
V_82 -> V_248 = F_12 ( V_29 -> V_107 ) ;
V_82 -> V_131 = 1 ;
}
ASSERT ( V_82 -> V_108 == F_12 ( V_29 -> V_41 ) ||
F_22 ( V_1 ) ) ;
F_53 ( V_82 ) ;
return 0 ;
}
int
F_65 (
T_16 * V_1 ,
T_13 * V_22 ,
T_8 V_30 )
{
T_14 * V_212 = NULL ;
int error ;
error = F_84 ( V_1 , V_22 , V_30 , & V_212 ) ;
if ( error )
return error ;
if ( V_212 )
F_85 ( V_22 , V_212 ) ;
return 0 ;
}
