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
STATIC int
F_18 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
T_6 V_29 ,
T_6 V_30 ,
unsigned int V_31 )
{
struct V_32 * V_33 ;
struct V_34 * free ;
int V_35 , V_36 , V_37 ;
int V_38 ;
int V_10 , V_39 ;
T_7 V_40 ;
T_8 V_6 = 0 ;
if ( V_1 -> V_2 . V_41 >= F_4 ( V_1 ) ) {
V_35 = 1 ;
V_36 = V_30 ;
V_37 = V_1 -> V_2 . V_42 ;
} else {
V_35 = F_4 ( V_1 ) /
V_1 -> V_2 . V_41 ;
V_36 = V_30 / V_35 ;
V_37 = V_35 * V_1 -> V_2 . V_42 ;
}
if ( F_19 ( & V_1 -> V_2 ) ) {
V_38 = 3 ;
V_6 = F_20 ( V_1 , V_28 ,
F_21 ( V_1 , V_29 , 0 ) ) ;
} else if ( F_22 ( & V_1 -> V_2 ) )
V_38 = 2 ;
else
V_38 = 1 ;
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
V_40 = F_23 ( V_1 , V_28 , V_29 + ( V_39 * V_35 ) ) ;
V_33 = F_24 ( V_27 , V_1 -> V_43 , V_40 ,
V_1 -> V_44 * V_35 ,
V_45 ) ;
if ( ! V_33 )
return V_46 ;
V_33 -> V_47 = & V_48 ;
F_25 ( V_33 , 0 , F_26 ( V_33 -> V_49 ) ) ;
for ( V_10 = 0 ; V_10 < V_37 ; V_10 ++ ) {
int V_50 = V_10 << V_1 -> V_2 . V_51 ;
T_9 V_52 = F_27 ( V_38 ) ;
free = F_28 ( V_1 , V_33 , V_10 ) ;
free -> V_53 = F_29 ( V_54 ) ;
free -> V_55 = V_38 ;
free -> V_56 = F_8 ( V_31 ) ;
free -> V_57 = F_8 ( V_58 ) ;
if ( V_38 == 3 ) {
free -> V_59 = F_9 ( V_6 ) ;
V_6 ++ ;
F_30 ( & free -> V_60 , & V_1 -> V_2 . V_61 ) ;
F_31 ( V_1 , free ) ;
} else {
F_32 ( V_27 , V_33 , V_50 ,
V_50 + V_52 - 1 ) ;
}
}
if ( V_38 == 3 ) {
F_32 ( V_27 , V_33 , 0 ,
F_26 ( V_33 -> V_49 ) - 1 ) ;
}
F_33 ( V_27 , V_33 ) ;
}
return 0 ;
}
STATIC int
F_34 (
T_10 * V_27 ,
T_11 * V_62 ,
int * V_63 )
{
T_12 * V_19 ;
T_1 args ;
T_13 * V_5 ;
T_5 V_28 ;
int error ;
int V_10 ;
T_2 V_64 ;
T_2 V_65 ;
T_2 V_66 ;
int V_67 = 0 ;
struct V_68 * V_69 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_27 = V_27 ;
args . V_1 = V_27 -> V_70 ;
V_65 = F_35 ( args . V_1 ) ;
if ( args . V_1 -> V_71 &&
args . V_1 -> V_2 . V_72 + V_65 > args . V_1 -> V_71 )
return F_36 ( V_73 ) ;
args . V_74 = args . V_75 = F_37 ( args . V_1 ) ;
V_19 = F_38 ( V_62 ) ;
V_64 = F_13 ( V_19 -> V_76 ) ;
V_28 = F_13 ( V_19 -> V_77 ) ;
args . V_29 = F_39 ( args . V_1 , V_64 ) +
F_37 ( args . V_1 ) ;
if ( F_40 ( V_64 != V_58 &&
( args . V_29 < F_13 ( V_19 -> V_78 ) ) ) ) {
args . V_79 = F_41 ( args . V_1 , V_28 , args . V_29 ) ;
args . type = V_80 ;
args . V_81 = 1 ;
args . V_82 = 1 ;
args . V_83 = F_1 ( & args ) - 1 ;
args . V_84 = args . V_1 -> V_85 - 1 ;
if ( ( error = F_42 ( & args ) ) )
return error ;
} else
args . V_79 = V_86 ;
if ( F_43 ( args . V_79 == V_86 ) ) {
V_67 = 0 ;
if ( args . V_1 -> V_87 ) {
ASSERT ( ! ( args . V_1 -> V_88 & V_89 ) ) ;
args . V_82 = args . V_1 -> V_90 ;
V_67 = 1 ;
} else
args . V_82 = F_1 ( & args ) ;
args . V_29 = F_13 ( V_19 -> V_91 ) ;
args . V_79 = F_41 ( args . V_1 , V_28 , args . V_29 ) ;
args . type = V_92 ;
args . V_81 = 1 ;
args . V_84 = args . V_1 -> V_85 - 1 ;
if ( ( error = F_42 ( & args ) ) )
return error ;
}
if ( V_67 && args . V_79 == V_86 ) {
args . type = V_92 ;
args . V_29 = F_13 ( V_19 -> V_91 ) ;
args . V_79 = F_41 ( args . V_1 , V_28 , args . V_29 ) ;
args . V_82 = F_1 ( & args ) ;
if ( ( error = F_42 ( & args ) ) )
return error ;
}
if ( args . V_79 == V_86 ) {
* V_63 = 0 ;
return 0 ;
}
ASSERT ( args . V_93 == args . V_74 ) ;
error = F_18 ( args . V_1 , V_27 , V_28 , args . V_29 ,
args . V_93 , F_44 () ) ;
if ( error )
return error ;
V_64 = F_21 ( args . V_1 , args . V_29 , 0 ) ;
F_45 ( & V_19 -> V_94 , V_65 ) ;
F_45 ( & V_19 -> V_24 , V_65 ) ;
V_69 = F_46 ( args . V_1 , V_28 ) ;
V_69 -> V_95 += V_65 ;
F_47 ( V_69 ) ;
V_19 -> V_76 = F_8 ( V_64 ) ;
V_5 = F_48 ( args . V_1 , V_27 , V_62 , V_28 ) ;
for ( V_66 = V_64 ;
V_66 < V_64 + V_65 ;
V_66 += V_96 ) {
V_5 -> V_9 . V_10 . V_11 = V_66 ;
V_5 -> V_9 . V_10 . V_12 = V_96 ;
V_5 -> V_9 . V_10 . V_13 = V_97 ;
error = F_6 ( V_5 , V_98 , & V_10 ) ;
if ( error ) {
F_49 ( V_5 , V_99 ) ;
return error ;
}
ASSERT ( V_10 == 0 ) ;
error = F_50 ( V_5 , & V_10 ) ;
if ( error ) {
F_49 ( V_5 , V_99 ) ;
return error ;
}
ASSERT ( V_10 == 1 ) ;
}
F_49 ( V_5 , V_100 ) ;
F_51 ( V_27 , V_62 ,
V_101 | V_102 | V_103 ) ;
F_52 ( V_27 , V_104 , ( long ) V_65 ) ;
F_52 ( V_27 , V_105 , ( long ) V_65 ) ;
* V_63 = 1 ;
return 0 ;
}
STATIC T_5
F_53 (
T_14 * V_1 )
{
T_5 V_28 ;
F_54 ( & V_1 -> V_106 ) ;
V_28 = V_1 -> V_107 ;
if ( ++ V_1 -> V_107 >= V_1 -> V_108 )
V_1 -> V_107 = 0 ;
F_55 ( & V_1 -> V_106 ) ;
return V_28 ;
}
STATIC T_5
F_56 (
T_10 * V_27 ,
T_8 V_109 ,
T_15 V_110 ,
int V_111 )
{
T_5 V_112 ;
T_5 V_28 ;
int V_113 ;
T_16 V_114 ;
T_16 V_115 = 0 ;
T_14 * V_1 ;
int V_116 ;
T_17 * V_69 ;
T_5 V_117 ;
int error ;
V_116 = F_57 ( V_110 ) || F_58 ( V_110 ) || F_59 ( V_110 ) ;
V_1 = V_27 -> V_70 ;
V_112 = V_1 -> V_108 ;
if ( F_57 ( V_110 ) )
V_117 = F_53 ( V_1 ) ;
else {
V_117 = F_60 ( V_1 , V_109 ) ;
if ( V_117 >= V_112 )
V_117 = 0 ;
}
ASSERT ( V_117 < V_112 ) ;
V_28 = V_117 ;
V_113 = V_118 ;
for (; ; ) {
V_69 = F_46 ( V_1 , V_28 ) ;
if ( ! V_69 -> V_119 ) {
F_53 ( V_1 ) ;
goto V_120;
}
if ( ! V_69 -> V_121 ) {
error = F_61 ( V_1 , V_27 , V_28 ) ;
if ( error )
goto V_120;
}
if ( V_69 -> V_95 ) {
F_47 ( V_69 ) ;
return V_28 ;
}
if ( ! V_111 )
goto V_120;
if ( ! V_69 -> V_122 ) {
error = F_62 ( V_1 , V_27 , V_28 , V_113 ) ;
if ( error )
goto V_120;
}
V_114 = F_37 ( V_1 ) ;
V_115 = V_69 -> V_123 ;
if ( ! V_115 )
V_115 = V_69 -> V_124 > 0 ;
if ( V_69 -> V_125 >= V_116 + V_114 &&
V_115 >= V_114 ) {
F_47 ( V_69 ) ;
return V_28 ;
}
V_120:
F_47 ( V_69 ) ;
if ( F_17 ( V_1 ) )
return V_126 ;
V_28 ++ ;
if ( V_28 >= V_112 )
V_28 = 0 ;
if ( V_28 == V_117 ) {
if ( V_113 == 0 )
return V_126 ;
V_113 = 0 ;
}
}
}
STATIC int
F_63 (
struct V_4 * V_5 ,
T_4 * V_16 ,
int * V_127 ,
int V_128 )
{
int error ;
int V_10 ;
if ( V_128 )
error = F_64 ( V_5 , 0 , & V_10 ) ;
else
error = F_16 ( V_5 , 0 , & V_10 ) ;
if ( error )
return error ;
* V_127 = ! V_10 ;
if ( V_10 ) {
error = F_11 ( V_5 , V_16 , & V_10 ) ;
if ( error )
return error ;
F_65 ( V_10 == 1 ) ;
}
return 0 ;
}
STATIC int
F_66 (
struct V_4 * V_5 ,
T_2 V_129 ,
T_4 * V_16 ,
int * V_127 ,
int V_128 )
{
int error ;
int V_10 ;
error = F_5 ( V_5 , V_129 , V_98 , & V_10 ) ;
if ( error )
return error ;
* V_127 = ! V_10 ;
if ( V_10 ) {
error = F_11 ( V_5 , V_16 , & V_10 ) ;
if ( error )
return error ;
F_65 ( V_10 == 1 ) ;
}
return 0 ;
}
STATIC int
F_67 (
struct V_26 * V_27 ,
struct V_32 * V_62 ,
T_8 V_109 ,
T_8 * V_130 )
{
struct V_25 * V_1 = V_27 -> V_70 ;
struct V_18 * V_19 = F_38 ( V_62 ) ;
T_5 V_28 = F_13 ( V_19 -> V_77 ) ;
T_5 V_117 = F_60 ( V_1 , V_109 ) ;
T_2 V_131 = F_68 ( V_1 , V_109 ) ;
struct V_68 * V_69 ;
struct V_4 * V_5 , * V_132 ;
struct V_133 V_16 , V_134 ;
T_8 V_6 ;
int error ;
int V_135 ;
int V_10 , V_39 ;
V_69 = F_46 ( V_1 , V_28 ) ;
ASSERT ( V_69 -> V_121 ) ;
ASSERT ( V_69 -> V_119 ) ;
ASSERT ( V_69 -> V_95 > 0 ) ;
V_136:
V_5 = F_48 ( V_1 , V_27 , V_62 , V_28 ) ;
if ( ! V_131 )
V_131 = F_13 ( V_19 -> V_76 ) ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_137;
if ( V_117 == V_28 ) {
int V_138 ;
int V_139 ;
int V_140 = 10 ;
error = F_5 ( V_5 , V_131 , V_141 , & V_10 ) ;
if ( error )
goto V_137;
F_69 ( V_10 == 1 , V_137 ) ;
error = F_11 ( V_5 , & V_16 , & V_39 ) ;
if ( error )
goto V_137;
F_69 ( V_10 == 1 , V_137 ) ;
if ( V_16 . V_12 > 0 ) {
goto V_142;
}
error = F_70 ( V_5 , & V_132 ) ;
if ( error )
goto V_137;
if ( V_131 != V_58 &&
V_69 -> V_143 == V_131 &&
V_69 -> V_144 != V_58 &&
V_69 -> V_145 != V_58 ) {
error = F_66 ( V_132 , V_69 -> V_144 ,
& V_134 , & V_138 , 1 ) ;
if ( error )
goto V_146;
error = F_66 ( V_5 , V_69 -> V_145 ,
& V_16 , & V_139 , 0 ) ;
if ( error )
goto V_146;
} else {
error = F_63 ( V_132 , & V_134 , & V_138 , 1 ) ;
if ( error )
goto V_146;
error = F_63 ( V_5 , & V_16 , & V_139 , 0 ) ;
if ( error )
goto V_146;
}
while ( ! V_138 || ! V_139 ) {
int V_147 ;
if ( ! -- V_140 ) {
F_49 ( V_132 , V_100 ) ;
V_69 -> V_144 = V_134 . V_11 ;
V_69 -> V_145 = V_16 . V_11 ;
V_69 -> V_143 = V_131 ;
goto V_64;
}
if ( ! V_138 && ! V_139 ) {
V_147 = V_131 -
( V_134 . V_11 + V_96 - 1 ) <
V_16 . V_11 - V_131 ;
} else {
V_147 = ! V_138 ;
}
if ( V_147 && V_134 . V_12 ) {
V_16 = V_134 ;
F_49 ( V_5 , V_100 ) ;
V_5 = V_132 ;
V_69 -> V_144 = V_134 . V_11 ;
V_69 -> V_145 = V_16 . V_11 ;
V_69 -> V_143 = V_131 ;
goto V_142;
}
if ( ! V_147 && V_16 . V_12 ) {
F_49 ( V_132 , V_100 ) ;
V_69 -> V_144 = V_134 . V_11 ;
V_69 -> V_145 = V_16 . V_11 ;
V_69 -> V_143 = V_131 ;
goto V_142;
}
if ( V_147 ) {
error = F_63 ( V_132 , & V_134 ,
& V_138 , 1 ) ;
} else {
error = F_63 ( V_5 , & V_16 ,
& V_139 , 0 ) ;
}
if ( error )
goto V_146;
}
V_69 -> V_143 = V_58 ;
V_69 -> V_144 = V_58 ;
V_69 -> V_145 = V_58 ;
F_49 ( V_132 , V_100 ) ;
F_49 ( V_5 , V_100 ) ;
goto V_136;
}
V_64:
if ( V_19 -> V_76 != F_8 ( V_58 ) ) {
error = F_5 ( V_5 , F_13 ( V_19 -> V_76 ) ,
V_98 , & V_10 ) ;
if ( error )
goto V_137;
if ( V_10 == 1 ) {
error = F_11 ( V_5 , & V_16 , & V_39 ) ;
if ( error )
goto V_137;
if ( V_39 == 1 && V_16 . V_12 > 0 ) {
goto V_142;
}
}
}
error = F_5 ( V_5 , 0 , V_22 , & V_10 ) ;
if ( error )
goto V_137;
F_69 ( V_10 == 1 , V_137 ) ;
for (; ; ) {
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( error )
goto V_137;
F_69 ( V_10 == 1 , V_137 ) ;
if ( V_16 . V_12 > 0 )
break;
error = F_16 ( V_5 , 0 , & V_10 ) ;
if ( error )
goto V_137;
F_69 ( V_10 == 1 , V_137 ) ;
}
V_142:
V_135 = F_71 ( V_16 . V_13 ) ;
ASSERT ( V_135 >= 0 ) ;
ASSERT ( V_135 < V_96 ) ;
ASSERT ( ( F_72 ( V_1 , V_16 . V_11 ) %
V_96 ) == 0 ) ;
V_6 = F_20 ( V_1 , V_28 , V_16 . V_11 + V_135 ) ;
V_16 . V_13 &= ~ F_73 ( V_135 ) ;
V_16 . V_12 -- ;
error = F_7 ( V_5 , & V_16 ) ;
if ( error )
goto V_137;
F_45 ( & V_19 -> V_24 , - 1 ) ;
F_51 ( V_27 , V_62 , V_102 ) ;
V_69 -> V_95 -- ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_137;
F_49 ( V_5 , V_100 ) ;
F_52 ( V_27 , V_105 , - 1 ) ;
F_47 ( V_69 ) ;
* V_130 = V_6 ;
return 0 ;
V_146:
F_49 ( V_132 , V_99 ) ;
V_137:
F_49 ( V_5 , V_99 ) ;
F_47 ( V_69 ) ;
return error ;
}
int
F_74 (
struct V_26 * V_27 ,
T_8 V_109 ,
T_15 V_110 ,
int V_111 ,
struct V_32 * * V_148 ,
T_8 * V_130 )
{
struct V_25 * V_1 = V_27 -> V_70 ;
struct V_32 * V_62 ;
T_5 V_28 ;
int error ;
int V_149 ;
int V_150 = 0 ;
T_5 V_151 ;
struct V_68 * V_69 ;
if ( * V_148 ) {
V_62 = * V_148 ;
goto V_152;
}
V_151 = F_56 ( V_27 , V_109 , V_110 , V_111 ) ;
if ( V_151 == V_126 ) {
* V_130 = V_153 ;
return 0 ;
}
if ( V_1 -> V_71 &&
V_1 -> V_2 . V_72 + F_35 ( V_1 ) > V_1 -> V_71 ) {
V_150 = 1 ;
V_111 = 0 ;
}
V_28 = V_151 ;
for (; ; ) {
V_69 = F_46 ( V_1 , V_28 ) ;
if ( ! V_69 -> V_119 ) {
F_53 ( V_1 ) ;
goto V_120;
}
if ( ! V_69 -> V_121 ) {
error = F_61 ( V_1 , V_27 , V_28 ) ;
if ( error )
goto V_154;
}
if ( ! V_69 -> V_95 && ! V_111 )
goto V_120;
error = F_75 ( V_1 , V_27 , V_28 , & V_62 ) ;
if ( error )
goto V_154;
if ( V_69 -> V_95 ) {
F_47 ( V_69 ) ;
goto V_152;
}
if ( ! V_111 )
goto V_155;
error = F_34 ( V_27 , V_62 , & V_149 ) ;
if ( error ) {
F_76 ( V_27 , V_62 ) ;
if ( error != V_73 )
goto V_154;
F_47 ( V_69 ) ;
* V_130 = V_153 ;
return 0 ;
}
if ( V_149 ) {
ASSERT ( V_69 -> V_95 > 0 ) ;
F_47 ( V_69 ) ;
* V_148 = V_62 ;
* V_130 = V_153 ;
return 0 ;
}
V_155:
F_76 ( V_27 , V_62 ) ;
V_120:
F_47 ( V_69 ) ;
if ( ++ V_28 == V_1 -> V_2 . V_156 )
V_28 = 0 ;
if ( V_28 == V_151 ) {
* V_130 = V_153 ;
return V_150 ? V_73 : 0 ;
}
}
V_152:
* V_148 = NULL ;
return F_67 ( V_27 , V_62 , V_109 , V_130 ) ;
V_154:
F_47 ( V_69 ) ;
return F_36 ( error ) ;
}
int
F_77 (
T_10 * V_27 ,
T_8 V_157 ,
T_18 * V_158 ,
int * V_159 ,
T_8 * V_160 )
{
T_6 V_29 ;
T_11 * V_62 ;
T_2 V_129 ;
T_5 V_28 ;
T_12 * V_19 ;
T_13 * V_5 ;
int error ;
int V_10 ;
int V_161 ;
T_14 * V_1 ;
int V_162 ;
T_4 V_16 ;
struct V_68 * V_69 ;
V_1 = V_27 -> V_70 ;
V_28 = F_60 ( V_1 , V_157 ) ;
if ( V_28 >= V_1 -> V_2 . V_156 ) {
F_78 ( V_1 , L_1 ,
V_163 , V_28 , V_1 -> V_2 . V_156 ) ;
ASSERT ( 0 ) ;
return F_36 ( V_164 ) ;
}
V_129 = F_68 ( V_1 , V_157 ) ;
if ( V_157 != F_20 ( V_1 , V_28 , V_129 ) ) {
F_78 ( V_1 , L_2 ,
V_163 , ( unsigned long long ) V_157 ,
( unsigned long long ) F_20 ( V_1 , V_28 , V_129 ) ) ;
ASSERT ( 0 ) ;
return F_36 ( V_164 ) ;
}
V_29 = F_39 ( V_1 , V_129 ) ;
if ( V_29 >= V_1 -> V_2 . V_165 ) {
F_78 ( V_1 , L_3 ,
V_163 , V_29 , V_1 -> V_2 . V_165 ) ;
ASSERT ( 0 ) ;
return F_36 ( V_164 ) ;
}
error = F_75 ( V_1 , V_27 , V_28 , & V_62 ) ;
if ( error ) {
F_78 ( V_1 , L_4 ,
V_163 , error ) ;
return error ;
}
V_19 = F_38 ( V_62 ) ;
ASSERT ( V_19 -> V_166 == F_8 ( V_167 ) ) ;
ASSERT ( V_29 < F_13 ( V_19 -> V_78 ) ) ;
V_5 = F_48 ( V_1 , V_27 , V_62 , V_28 ) ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_137;
if ( ( error = F_5 ( V_5 , V_129 , V_141 , & V_10 ) ) ) {
F_78 ( V_1 , L_5 ,
V_163 , error ) ;
goto V_137;
}
F_69 ( V_10 == 1 , V_137 ) ;
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( error ) {
F_78 ( V_1 , L_6 ,
V_163 , error ) ;
goto V_137;
}
F_69 ( V_10 == 1 , V_137 ) ;
V_162 = V_129 - V_16 . V_11 ;
ASSERT ( V_162 >= 0 && V_162 < V_96 ) ;
ASSERT ( ! ( V_16 . V_13 & F_73 ( V_162 ) ) ) ;
V_16 . V_13 |= F_73 ( V_162 ) ;
V_16 . V_12 ++ ;
if ( ! ( V_1 -> V_88 & V_168 ) &&
( V_16 . V_12 == F_35 ( V_1 ) ) ) {
* V_159 = 1 ;
* V_160 = F_20 ( V_1 , V_28 , V_16 . V_11 ) ;
V_161 = F_35 ( V_1 ) ;
F_45 ( & V_19 -> V_94 , - V_161 ) ;
F_45 ( & V_19 -> V_24 , - ( V_161 - 1 ) ) ;
F_51 ( V_27 , V_62 , V_101 | V_102 ) ;
V_69 = F_46 ( V_1 , V_28 ) ;
V_69 -> V_95 -= V_161 - 1 ;
F_47 ( V_69 ) ;
F_52 ( V_27 , V_104 , - V_161 ) ;
F_52 ( V_27 , V_105 , - ( V_161 - 1 ) ) ;
if ( ( error = F_79 ( V_5 , & V_10 ) ) ) {
F_78 ( V_1 , L_7 ,
V_163 , error ) ;
goto V_137;
}
F_80 ( F_41 ( V_1 ,
V_28 , F_81 ( V_1 , V_16 . V_11 ) ) ,
F_37 ( V_1 ) , V_158 , V_1 ) ;
} else {
* V_159 = 0 ;
error = F_7 ( V_5 , & V_16 ) ;
if ( error ) {
F_78 ( V_1 , L_8 ,
V_163 , error ) ;
goto V_137;
}
F_45 ( & V_19 -> V_24 , 1 ) ;
F_51 ( V_27 , V_62 , V_102 ) ;
V_69 = F_46 ( V_1 , V_28 ) ;
V_69 -> V_95 ++ ;
F_47 ( V_69 ) ;
F_52 ( V_27 , V_105 , 1 ) ;
}
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_137;
F_49 ( V_5 , V_100 ) ;
return 0 ;
V_137:
F_49 ( V_5 , V_99 ) ;
return error ;
}
STATIC int
F_82 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
T_2 V_129 ,
T_6 V_29 ,
T_6 * V_169 ,
T_6 * V_170 ,
int V_113 )
{
struct V_133 V_16 ;
struct V_4 * V_5 ;
struct V_32 * V_62 ;
int error ;
int V_10 ;
error = F_75 ( V_1 , V_27 , V_28 , & V_62 ) ;
if ( error ) {
F_83 ( V_1 ,
L_9 ,
V_163 , error , V_28 ) ;
return error ;
}
V_5 = F_48 ( V_1 , V_27 , V_62 , V_28 ) ;
error = F_5 ( V_5 , V_129 , V_141 , & V_10 ) ;
if ( ! error ) {
if ( V_10 )
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( ! error && V_10 == 0 )
error = V_164 ;
}
F_76 ( V_27 , V_62 ) ;
F_49 ( V_5 , V_100 ) ;
if ( error )
return error ;
if ( V_16 . V_11 > V_129 ||
V_16 . V_11 + F_35 ( V_1 ) <= V_129 )
return V_164 ;
if ( ( V_113 & V_171 ) &&
( V_16 . V_13 & F_73 ( V_129 - V_16 . V_11 ) ) )
return V_164 ;
* V_169 = F_39 ( V_1 , V_16 . V_11 ) ;
* V_170 = V_29 - * V_169 ;
return 0 ;
}
int
F_84 (
T_14 * V_1 ,
T_10 * V_27 ,
T_8 V_6 ,
struct F_84 * V_172 ,
T_9 V_113 )
{
T_6 V_29 ;
T_2 V_129 ;
T_5 V_28 ;
int V_35 ;
T_6 V_169 ;
T_6 V_173 ;
int error ;
int V_135 ;
int V_170 ;
ASSERT ( V_6 != V_153 ) ;
V_28 = F_60 ( V_1 , V_6 ) ;
V_129 = F_68 ( V_1 , V_6 ) ;
V_29 = F_39 ( V_1 , V_129 ) ;
if ( V_28 >= V_1 -> V_2 . V_156 || V_29 >= V_1 -> V_2 . V_165 ||
V_6 != F_20 ( V_1 , V_28 , V_129 ) ) {
#ifdef F_85
if ( V_113 & V_171 )
return F_36 ( V_164 ) ;
if ( V_28 >= V_1 -> V_2 . V_156 ) {
F_83 ( V_1 ,
L_10 ,
V_163 , V_28 , V_1 -> V_2 . V_156 ) ;
}
if ( V_29 >= V_1 -> V_2 . V_165 ) {
F_83 ( V_1 ,
L_11 ,
V_163 , ( unsigned long long ) V_29 ,
( unsigned long ) V_1 -> V_2 . V_165 ) ;
}
if ( V_6 != F_20 ( V_1 , V_28 , V_129 ) ) {
F_83 ( V_1 ,
L_12 ,
V_163 , V_6 ,
F_20 ( V_1 , V_28 , V_129 ) ) ;
}
F_86 () ;
#endif
return F_36 ( V_164 ) ;
}
V_35 = F_4 ( V_1 ) >> V_1 -> V_2 . V_174 ;
if ( V_113 & V_171 ) {
error = F_82 ( V_1 , V_27 , V_28 , V_129 , V_29 ,
& V_169 , & V_170 , V_113 ) ;
if ( error )
return error ;
goto V_175;
}
if ( F_4 ( V_1 ) <= V_1 -> V_2 . V_41 ) {
V_135 = F_87 ( V_1 , V_6 ) ;
ASSERT ( V_135 < V_1 -> V_2 . V_42 ) ;
V_172 -> V_176 = F_23 ( V_1 , V_28 , V_29 ) ;
V_172 -> V_177 = F_88 ( V_1 , 1 ) ;
V_172 -> V_178 = ( V_179 ) ( V_135 << V_1 -> V_2 . V_51 ) ;
return 0 ;
}
if ( V_1 -> V_180 ) {
V_170 = V_29 & V_1 -> V_180 ;
V_169 = V_29 - V_170 ;
} else {
error = F_82 ( V_1 , V_27 , V_28 , V_129 , V_29 ,
& V_169 , & V_170 , V_113 ) ;
if ( error )
return error ;
}
V_175:
ASSERT ( V_29 >= V_169 ) ;
V_173 = V_169 +
( ( V_170 / V_35 ) * V_35 ) ;
V_135 = ( ( V_29 - V_173 ) * V_1 -> V_2 . V_42 ) +
F_87 ( V_1 , V_6 ) ;
V_172 -> V_176 = F_23 ( V_1 , V_28 , V_173 ) ;
V_172 -> V_177 = F_88 ( V_1 , V_35 ) ;
V_172 -> V_178 = ( V_179 ) ( V_135 << V_1 -> V_2 . V_51 ) ;
if ( ( V_172 -> V_176 + V_172 -> V_177 ) >
F_88 ( V_1 , V_1 -> V_2 . V_181 ) ) {
F_83 ( V_1 ,
L_13 ,
V_163 , ( unsigned long long ) V_172 -> V_176 ,
( unsigned long long ) V_172 -> V_177 ,
F_88 ( V_1 , V_1 -> V_2 . V_181 ) ) ;
return F_36 ( V_164 ) ;
}
return 0 ;
}
void
F_89 (
T_14 * V_1 )
{
int V_182 ;
T_9 V_183 ;
T_9 V_184 ;
int V_185 ;
int V_186 ;
V_184 = ( 1LL << F_90 ( V_1 ) ) >>
V_187 ;
V_185 = V_1 -> V_188 [ 0 ] ;
V_186 = V_1 -> V_188 [ 1 ] ;
V_183 = ( V_184 + V_185 - 1 ) / V_185 ;
for ( V_182 = 1 ; V_183 > 1 ; V_182 ++ )
V_183 = ( V_183 + V_186 - 1 ) / V_186 ;
V_1 -> V_85 = V_182 ;
}
void
F_51 (
T_10 * V_27 ,
T_11 * V_189 ,
int V_190 )
{
int V_191 ;
int V_192 ;
static const short V_193 [] = {
F_91 ( T_12 , V_166 ) ,
F_91 ( T_12 , V_194 ) ,
F_91 ( T_12 , V_77 ) ,
F_91 ( T_12 , V_78 ) ,
F_91 ( T_12 , V_94 ) ,
F_91 ( T_12 , V_91 ) ,
F_91 ( T_12 , V_195 ) ,
F_91 ( T_12 , V_24 ) ,
F_91 ( T_12 , V_76 ) ,
F_91 ( T_12 , V_196 ) ,
F_91 ( T_12 , V_197 ) ,
sizeof( T_12 )
} ;
#ifdef F_85
T_12 * V_19 ;
V_19 = F_38 ( V_189 ) ;
ASSERT ( V_19 -> V_166 == F_8 ( V_167 ) ) ;
#endif
F_92 ( V_190 , V_193 , V_198 , & V_191 , & V_192 ) ;
F_93 ( V_27 , V_189 , V_199 ) ;
F_32 ( V_27 , V_189 , V_191 , V_192 ) ;
}
STATIC void
F_94 (
struct V_18 * V_19 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_200 ; V_10 ++ )
ASSERT ( V_19 -> V_197 [ V_10 ] ) ;
}
static bool
F_95 (
struct V_32 * V_189 )
{
struct V_25 * V_1 = V_189 -> V_201 -> V_202 ;
struct V_18 * V_19 = F_38 ( V_189 ) ;
if ( F_19 ( & V_1 -> V_2 ) &&
! F_96 ( & V_19 -> V_203 , & V_1 -> V_2 . V_61 ) )
return false ;
if ( V_19 -> V_166 != F_8 ( V_167 ) )
return false ;
if ( ! F_97 ( F_13 ( V_19 -> V_194 ) ) )
return false ;
if ( V_189 -> V_204 && F_13 ( V_19 -> V_77 ) != V_189 -> V_204 -> V_205 )
return false ;
F_94 ( V_19 ) ;
return true ;
}
static void
F_98 (
struct V_32 * V_189 )
{
struct V_25 * V_1 = V_189 -> V_201 -> V_202 ;
int V_206 = 1 ;
if ( F_19 ( & V_1 -> V_2 ) )
V_206 = F_99 ( V_189 -> V_207 , F_26 ( V_189 -> V_49 ) ,
F_91 ( struct V_18 , V_208 ) ) ;
V_206 = V_206 && F_95 ( V_189 ) ;
if ( F_43 ( F_100 ( ! V_206 , V_1 , V_209 ,
V_210 ) ) ) {
F_101 ( V_163 , V_211 , V_1 , V_189 -> V_207 ) ;
F_102 ( V_189 , V_212 ) ;
}
}
static void
F_103 (
struct V_32 * V_189 )
{
struct V_25 * V_1 = V_189 -> V_201 -> V_202 ;
struct V_213 * V_214 = V_189 -> V_215 ;
if ( ! F_95 ( V_189 ) ) {
F_101 ( V_163 , V_211 , V_1 , V_189 -> V_207 ) ;
F_102 ( V_189 , V_212 ) ;
return;
}
if ( ! F_19 ( & V_1 -> V_2 ) )
return;
if ( V_214 )
F_38 ( V_189 ) -> V_216 = F_9 ( V_214 -> V_217 . V_218 ) ;
F_104 ( V_189 -> V_207 , F_26 ( V_189 -> V_49 ) ,
F_91 ( struct V_18 , V_208 ) ) ;
}
int
F_105 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
struct V_32 * * V_219 )
{
int error ;
ASSERT ( V_28 != V_126 ) ;
error = F_106 ( V_1 , V_27 , V_1 -> V_43 ,
F_107 ( V_1 , V_28 , F_108 ( V_1 ) ) ,
F_109 ( V_1 , 1 ) , 0 , V_219 , & V_220 ) ;
if ( error )
return error ;
ASSERT ( ! F_110 ( * V_219 ) ) ;
F_111 ( * V_219 , V_221 ) ;
return 0 ;
}
int
F_75 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
struct V_32 * * V_219 )
{
struct V_18 * V_19 ;
struct V_68 * V_69 ;
int error ;
error = F_105 ( V_1 , V_27 , V_28 , V_219 ) ;
if ( error )
return error ;
V_19 = F_38 ( * V_219 ) ;
V_69 = F_46 ( V_1 , V_28 ) ;
if ( ! V_69 -> V_121 ) {
V_69 -> V_95 = F_13 ( V_19 -> V_24 ) ;
V_69 -> V_222 = F_13 ( V_19 -> V_94 ) ;
V_69 -> V_121 = 1 ;
}
ASSERT ( V_69 -> V_95 == F_13 ( V_19 -> V_24 ) ||
F_17 ( V_1 ) ) ;
F_47 ( V_69 ) ;
return 0 ;
}
int
F_61 (
T_14 * V_1 ,
T_10 * V_27 ,
T_5 V_28 )
{
T_11 * V_189 = NULL ;
int error ;
error = F_75 ( V_1 , V_27 , V_28 , & V_189 ) ;
if ( error )
return error ;
if ( V_189 )
F_76 ( V_27 , V_189 ) ;
return 0 ;
}
