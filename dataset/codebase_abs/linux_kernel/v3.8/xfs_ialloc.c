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
if ( F_19 ( & V_1 -> V_2 ) )
V_38 = 2 ;
else
V_38 = 1 ;
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
V_40 = F_20 ( V_1 , V_28 , V_29 + ( V_39 * V_35 ) ) ;
V_33 = F_21 ( V_27 , V_1 -> V_43 , V_40 ,
V_1 -> V_44 * V_35 ,
V_45 ) ;
if ( ! V_33 )
return V_46 ;
V_33 -> V_47 = & V_48 ;
F_22 ( V_33 , 0 , V_37 << V_1 -> V_2 . V_49 ) ;
for ( V_10 = 0 ; V_10 < V_37 ; V_10 ++ ) {
int V_50 = V_10 << V_1 -> V_2 . V_49 ;
T_8 V_51 = sizeof( struct V_34 ) ;
free = F_23 ( V_1 , V_33 , V_10 ) ;
free -> V_52 = F_24 ( V_53 ) ;
free -> V_54 = V_38 ;
free -> V_55 = F_8 ( V_31 ) ;
free -> V_56 = F_8 ( V_57 ) ;
F_25 ( V_27 , V_33 , V_50 , V_50 + V_51 - 1 ) ;
}
F_26 ( V_27 , V_33 ) ;
}
return 0 ;
}
STATIC int
F_27 (
T_9 * V_27 ,
T_10 * V_58 ,
int * V_59 )
{
T_11 * V_19 ;
T_1 args ;
T_12 * V_5 ;
T_5 V_28 ;
int error ;
int V_10 ;
T_2 V_60 ;
T_2 V_61 ;
T_2 V_62 ;
int V_63 = 0 ;
struct V_64 * V_65 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_27 = V_27 ;
args . V_1 = V_27 -> V_66 ;
V_61 = F_28 ( args . V_1 ) ;
if ( args . V_1 -> V_67 &&
args . V_1 -> V_2 . V_68 + V_61 > args . V_1 -> V_67 )
return F_29 ( V_69 ) ;
args . V_70 = args . V_71 = F_30 ( args . V_1 ) ;
V_19 = F_31 ( V_58 ) ;
V_60 = F_13 ( V_19 -> V_72 ) ;
V_28 = F_13 ( V_19 -> V_73 ) ;
args . V_29 = F_32 ( args . V_1 , V_60 ) +
F_30 ( args . V_1 ) ;
if ( F_33 ( V_60 != V_57 &&
( args . V_29 < F_13 ( V_19 -> V_74 ) ) ) ) {
args . V_75 = F_34 ( args . V_1 , V_28 , args . V_29 ) ;
args . type = V_76 ;
args . V_77 = args . V_78 = args . V_79 = args . V_80 =
args . V_81 = args . V_82 = 0 ;
args . V_83 = 1 ;
args . V_84 = 1 ;
args . V_82 = F_1 ( & args ) - 1 ;
args . V_85 = args . V_1 -> V_86 - 1 ;
if ( ( error = F_35 ( & args ) ) )
return error ;
} else
args . V_75 = V_87 ;
if ( F_36 ( args . V_75 == V_87 ) ) {
V_63 = 0 ;
if ( args . V_1 -> V_88 ) {
ASSERT ( ! ( args . V_1 -> V_89 & V_90 ) ) ;
args . V_84 = args . V_1 -> V_91 ;
V_63 = 1 ;
} else
args . V_84 = F_1 ( & args ) ;
args . V_29 = F_13 ( V_19 -> V_92 ) ;
args . V_75 = F_34 ( args . V_1 , V_28 , args . V_29 ) ;
args . type = V_93 ;
args . V_77 = args . V_78 = args . V_79 = args . V_80 =
args . V_81 = args . V_82 = 0 ;
args . V_83 = 1 ;
args . V_85 = args . V_1 -> V_86 - 1 ;
if ( ( error = F_35 ( & args ) ) )
return error ;
}
if ( V_63 && args . V_75 == V_87 ) {
args . type = V_93 ;
args . V_29 = F_13 ( V_19 -> V_92 ) ;
args . V_75 = F_34 ( args . V_1 , V_28 , args . V_29 ) ;
args . V_84 = F_1 ( & args ) ;
if ( ( error = F_35 ( & args ) ) )
return error ;
}
if ( args . V_75 == V_87 ) {
* V_59 = 0 ;
return 0 ;
}
ASSERT ( args . V_94 == args . V_70 ) ;
error = F_18 ( args . V_1 , V_27 , V_28 , args . V_29 ,
args . V_94 , F_37 () ) ;
if ( error )
return error ;
V_60 = F_38 ( args . V_1 , args . V_29 , 0 ) ;
F_39 ( & V_19 -> V_95 , V_61 ) ;
F_39 ( & V_19 -> V_24 , V_61 ) ;
V_65 = F_40 ( args . V_1 , V_28 ) ;
V_65 -> V_96 += V_61 ;
F_41 ( V_65 ) ;
V_19 -> V_72 = F_8 ( V_60 ) ;
V_5 = F_42 ( args . V_1 , V_27 , V_58 , V_28 ) ;
for ( V_62 = V_60 ;
V_62 < V_60 + V_61 ;
V_62 += V_97 ) {
V_5 -> V_9 . V_10 . V_11 = V_62 ;
V_5 -> V_9 . V_10 . V_12 = V_97 ;
V_5 -> V_9 . V_10 . V_13 = V_98 ;
error = F_6 ( V_5 , V_99 , & V_10 ) ;
if ( error ) {
F_43 ( V_5 , V_100 ) ;
return error ;
}
ASSERT ( V_10 == 0 ) ;
error = F_44 ( V_5 , & V_10 ) ;
if ( error ) {
F_43 ( V_5 , V_100 ) ;
return error ;
}
ASSERT ( V_10 == 1 ) ;
}
F_43 ( V_5 , V_101 ) ;
F_45 ( V_27 , V_58 ,
V_102 | V_103 | V_104 ) ;
F_46 ( V_27 , V_105 , ( long ) V_61 ) ;
F_46 ( V_27 , V_106 , ( long ) V_61 ) ;
* V_59 = 1 ;
return 0 ;
}
STATIC T_5
F_47 (
T_13 * V_1 )
{
T_5 V_28 ;
F_48 ( & V_1 -> V_107 ) ;
V_28 = V_1 -> V_108 ;
if ( ++ V_1 -> V_108 >= V_1 -> V_109 )
V_1 -> V_108 = 0 ;
F_49 ( & V_1 -> V_107 ) ;
return V_28 ;
}
STATIC T_5
F_50 (
T_9 * V_27 ,
T_14 V_110 ,
T_15 V_111 ,
int V_112 )
{
T_5 V_113 ;
T_5 V_28 ;
int V_114 ;
T_16 V_115 ;
T_16 V_116 = 0 ;
T_13 * V_1 ;
int V_117 ;
T_17 * V_65 ;
T_5 V_118 ;
int error ;
V_117 = F_51 ( V_111 ) || F_52 ( V_111 ) || F_53 ( V_111 ) ;
V_1 = V_27 -> V_66 ;
V_113 = V_1 -> V_109 ;
if ( F_51 ( V_111 ) )
V_118 = F_47 ( V_1 ) ;
else {
V_118 = F_54 ( V_1 , V_110 ) ;
if ( V_118 >= V_113 )
V_118 = 0 ;
}
ASSERT ( V_118 < V_113 ) ;
V_28 = V_118 ;
V_114 = V_119 ;
for (; ; ) {
V_65 = F_40 ( V_1 , V_28 ) ;
if ( ! V_65 -> V_120 ) {
F_47 ( V_1 ) ;
goto V_121;
}
if ( ! V_65 -> V_122 ) {
error = F_55 ( V_1 , V_27 , V_28 ) ;
if ( error )
goto V_121;
}
if ( V_65 -> V_96 ) {
F_41 ( V_65 ) ;
return V_28 ;
}
if ( ! V_112 )
goto V_121;
if ( ! V_65 -> V_123 ) {
error = F_56 ( V_1 , V_27 , V_28 , V_114 ) ;
if ( error )
goto V_121;
}
V_115 = F_30 ( V_1 ) ;
V_116 = V_65 -> V_124 ;
if ( ! V_116 )
V_116 = V_65 -> V_125 > 0 ;
if ( V_65 -> V_126 >= V_117 + V_115 &&
V_116 >= V_115 ) {
F_41 ( V_65 ) ;
return V_28 ;
}
V_121:
F_41 ( V_65 ) ;
if ( F_17 ( V_1 ) )
return V_127 ;
V_28 ++ ;
if ( V_28 >= V_113 )
V_28 = 0 ;
if ( V_28 == V_118 ) {
if ( V_114 == 0 )
return V_127 ;
V_114 = 0 ;
}
}
}
STATIC int
F_57 (
struct V_4 * V_5 ,
T_4 * V_16 ,
int * V_128 ,
int V_129 )
{
int error ;
int V_10 ;
if ( V_129 )
error = F_58 ( V_5 , 0 , & V_10 ) ;
else
error = F_16 ( V_5 , 0 , & V_10 ) ;
if ( error )
return error ;
* V_128 = ! V_10 ;
if ( V_10 ) {
error = F_11 ( V_5 , V_16 , & V_10 ) ;
if ( error )
return error ;
F_59 ( V_10 == 1 ) ;
}
return 0 ;
}
STATIC int
F_60 (
struct V_4 * V_5 ,
T_2 V_130 ,
T_4 * V_16 ,
int * V_128 ,
int V_129 )
{
int error ;
int V_10 ;
error = F_5 ( V_5 , V_130 , V_99 , & V_10 ) ;
if ( error )
return error ;
* V_128 = ! V_10 ;
if ( V_10 ) {
error = F_11 ( V_5 , V_16 , & V_10 ) ;
if ( error )
return error ;
F_59 ( V_10 == 1 ) ;
}
return 0 ;
}
STATIC int
F_61 (
struct V_26 * V_27 ,
struct V_32 * V_58 ,
T_14 V_110 ,
T_14 * V_131 )
{
struct V_25 * V_1 = V_27 -> V_66 ;
struct V_18 * V_19 = F_31 ( V_58 ) ;
T_5 V_28 = F_13 ( V_19 -> V_73 ) ;
T_5 V_118 = F_54 ( V_1 , V_110 ) ;
T_2 V_132 = F_62 ( V_1 , V_110 ) ;
struct V_64 * V_65 ;
struct V_4 * V_5 , * V_133 ;
struct V_134 V_16 , V_135 ;
T_14 V_6 ;
int error ;
int V_136 ;
int V_10 , V_39 ;
V_65 = F_40 ( V_1 , V_28 ) ;
ASSERT ( V_65 -> V_122 ) ;
ASSERT ( V_65 -> V_120 ) ;
ASSERT ( V_65 -> V_96 > 0 ) ;
V_137:
V_5 = F_42 ( V_1 , V_27 , V_58 , V_28 ) ;
if ( ! V_132 )
V_132 = F_13 ( V_19 -> V_72 ) ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_138;
if ( V_118 == V_28 ) {
int V_139 ;
int V_140 ;
int V_141 = 10 ;
error = F_5 ( V_5 , V_132 , V_142 , & V_10 ) ;
if ( error )
goto V_138;
F_63 ( V_10 == 1 , V_138 ) ;
error = F_11 ( V_5 , & V_16 , & V_39 ) ;
if ( error )
goto V_138;
F_63 ( V_10 == 1 , V_138 ) ;
if ( V_16 . V_12 > 0 ) {
goto V_143;
}
error = F_64 ( V_5 , & V_133 ) ;
if ( error )
goto V_138;
if ( V_132 != V_57 &&
V_65 -> V_144 == V_132 &&
V_65 -> V_145 != V_57 &&
V_65 -> V_146 != V_57 ) {
error = F_60 ( V_133 , V_65 -> V_145 ,
& V_135 , & V_139 , 1 ) ;
if ( error )
goto V_147;
error = F_60 ( V_5 , V_65 -> V_146 ,
& V_16 , & V_140 , 0 ) ;
if ( error )
goto V_147;
} else {
error = F_57 ( V_133 , & V_135 , & V_139 , 1 ) ;
if ( error )
goto V_147;
error = F_57 ( V_5 , & V_16 , & V_140 , 0 ) ;
if ( error )
goto V_147;
}
while ( ! V_139 || ! V_140 ) {
int V_148 ;
if ( ! -- V_141 ) {
F_43 ( V_133 , V_101 ) ;
V_65 -> V_145 = V_135 . V_11 ;
V_65 -> V_146 = V_16 . V_11 ;
V_65 -> V_144 = V_132 ;
goto V_60;
}
if ( ! V_139 && ! V_140 ) {
V_148 = V_132 -
( V_135 . V_11 + V_97 - 1 ) <
V_16 . V_11 - V_132 ;
} else {
V_148 = ! V_139 ;
}
if ( V_148 && V_135 . V_12 ) {
V_16 = V_135 ;
F_43 ( V_5 , V_101 ) ;
V_5 = V_133 ;
V_65 -> V_145 = V_135 . V_11 ;
V_65 -> V_146 = V_16 . V_11 ;
V_65 -> V_144 = V_132 ;
goto V_143;
}
if ( ! V_148 && V_16 . V_12 ) {
F_43 ( V_133 , V_101 ) ;
V_65 -> V_145 = V_135 . V_11 ;
V_65 -> V_146 = V_16 . V_11 ;
V_65 -> V_144 = V_132 ;
goto V_143;
}
if ( V_148 ) {
error = F_57 ( V_133 , & V_135 ,
& V_139 , 1 ) ;
} else {
error = F_57 ( V_5 , & V_16 ,
& V_140 , 0 ) ;
}
if ( error )
goto V_147;
}
V_65 -> V_144 = V_57 ;
V_65 -> V_145 = V_57 ;
V_65 -> V_146 = V_57 ;
F_43 ( V_133 , V_101 ) ;
F_43 ( V_5 , V_101 ) ;
goto V_137;
}
V_60:
if ( V_19 -> V_72 != F_8 ( V_57 ) ) {
error = F_5 ( V_5 , F_13 ( V_19 -> V_72 ) ,
V_99 , & V_10 ) ;
if ( error )
goto V_138;
if ( V_10 == 1 ) {
error = F_11 ( V_5 , & V_16 , & V_39 ) ;
if ( error )
goto V_138;
if ( V_39 == 1 && V_16 . V_12 > 0 ) {
goto V_143;
}
}
}
error = F_5 ( V_5 , 0 , V_22 , & V_10 ) ;
if ( error )
goto V_138;
F_63 ( V_10 == 1 , V_138 ) ;
for (; ; ) {
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( error )
goto V_138;
F_63 ( V_10 == 1 , V_138 ) ;
if ( V_16 . V_12 > 0 )
break;
error = F_16 ( V_5 , 0 , & V_10 ) ;
if ( error )
goto V_138;
F_63 ( V_10 == 1 , V_138 ) ;
}
V_143:
V_136 = F_65 ( V_16 . V_13 ) ;
ASSERT ( V_136 >= 0 ) ;
ASSERT ( V_136 < V_97 ) ;
ASSERT ( ( F_66 ( V_1 , V_16 . V_11 ) %
V_97 ) == 0 ) ;
V_6 = F_67 ( V_1 , V_28 , V_16 . V_11 + V_136 ) ;
V_16 . V_13 &= ~ F_68 ( V_136 ) ;
V_16 . V_12 -- ;
error = F_7 ( V_5 , & V_16 ) ;
if ( error )
goto V_138;
F_39 ( & V_19 -> V_24 , - 1 ) ;
F_45 ( V_27 , V_58 , V_103 ) ;
V_65 -> V_96 -- ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_138;
F_43 ( V_5 , V_101 ) ;
F_46 ( V_27 , V_106 , - 1 ) ;
F_41 ( V_65 ) ;
* V_131 = V_6 ;
return 0 ;
V_147:
F_43 ( V_133 , V_100 ) ;
V_138:
F_43 ( V_5 , V_100 ) ;
F_41 ( V_65 ) ;
return error ;
}
int
F_69 (
struct V_26 * V_27 ,
T_14 V_110 ,
T_15 V_111 ,
int V_112 ,
struct V_32 * * V_149 ,
T_14 * V_131 )
{
struct V_25 * V_1 = V_27 -> V_66 ;
struct V_32 * V_58 ;
T_5 V_28 ;
int error ;
int V_150 ;
int V_151 = 0 ;
T_5 V_152 ;
struct V_64 * V_65 ;
if ( * V_149 ) {
V_58 = * V_149 ;
goto V_153;
}
V_152 = F_50 ( V_27 , V_110 , V_111 , V_112 ) ;
if ( V_152 == V_127 ) {
* V_131 = V_154 ;
return 0 ;
}
if ( V_1 -> V_67 &&
V_1 -> V_2 . V_68 + F_28 ( V_1 ) > V_1 -> V_67 ) {
V_151 = 1 ;
V_112 = 0 ;
}
V_28 = V_152 ;
for (; ; ) {
V_65 = F_40 ( V_1 , V_28 ) ;
if ( ! V_65 -> V_120 ) {
F_47 ( V_1 ) ;
goto V_121;
}
if ( ! V_65 -> V_122 ) {
error = F_55 ( V_1 , V_27 , V_28 ) ;
if ( error )
goto V_155;
}
if ( ! V_65 -> V_96 && ! V_112 )
goto V_121;
error = F_70 ( V_1 , V_27 , V_28 , & V_58 ) ;
if ( error )
goto V_155;
if ( V_65 -> V_96 ) {
F_41 ( V_65 ) ;
goto V_153;
}
if ( ! V_112 )
goto V_156;
error = F_27 ( V_27 , V_58 , & V_150 ) ;
if ( error ) {
F_71 ( V_27 , V_58 ) ;
if ( error != V_69 )
goto V_155;
F_41 ( V_65 ) ;
* V_131 = V_154 ;
return 0 ;
}
if ( V_150 ) {
ASSERT ( V_65 -> V_96 > 0 ) ;
F_41 ( V_65 ) ;
* V_149 = V_58 ;
* V_131 = V_154 ;
return 0 ;
}
V_156:
F_71 ( V_27 , V_58 ) ;
V_121:
F_41 ( V_65 ) ;
if ( ++ V_28 == V_1 -> V_2 . V_157 )
V_28 = 0 ;
if ( V_28 == V_152 ) {
* V_131 = V_154 ;
return V_151 ? V_69 : 0 ;
}
}
V_153:
* V_149 = NULL ;
return F_61 ( V_27 , V_58 , V_110 , V_131 ) ;
V_155:
F_41 ( V_65 ) ;
return F_29 ( error ) ;
}
int
F_72 (
T_9 * V_27 ,
T_14 V_158 ,
T_18 * V_159 ,
int * V_160 ,
T_14 * V_161 )
{
T_6 V_29 ;
T_10 * V_58 ;
T_2 V_130 ;
T_5 V_28 ;
T_11 * V_19 ;
T_12 * V_5 ;
int error ;
int V_10 ;
int V_162 ;
T_13 * V_1 ;
int V_163 ;
T_4 V_16 ;
struct V_64 * V_65 ;
V_1 = V_27 -> V_66 ;
V_28 = F_54 ( V_1 , V_158 ) ;
if ( V_28 >= V_1 -> V_2 . V_157 ) {
F_73 ( V_1 , L_1 ,
V_164 , V_28 , V_1 -> V_2 . V_157 ) ;
ASSERT ( 0 ) ;
return F_29 ( V_165 ) ;
}
V_130 = F_62 ( V_1 , V_158 ) ;
if ( V_158 != F_67 ( V_1 , V_28 , V_130 ) ) {
F_73 ( V_1 , L_2 ,
V_164 , ( unsigned long long ) V_158 ,
( unsigned long long ) F_67 ( V_1 , V_28 , V_130 ) ) ;
ASSERT ( 0 ) ;
return F_29 ( V_165 ) ;
}
V_29 = F_32 ( V_1 , V_130 ) ;
if ( V_29 >= V_1 -> V_2 . V_166 ) {
F_73 ( V_1 , L_3 ,
V_164 , V_29 , V_1 -> V_2 . V_166 ) ;
ASSERT ( 0 ) ;
return F_29 ( V_165 ) ;
}
error = F_70 ( V_1 , V_27 , V_28 , & V_58 ) ;
if ( error ) {
F_73 ( V_1 , L_4 ,
V_164 , error ) ;
return error ;
}
V_19 = F_31 ( V_58 ) ;
ASSERT ( V_19 -> V_167 == F_8 ( V_168 ) ) ;
ASSERT ( V_29 < F_13 ( V_19 -> V_74 ) ) ;
V_5 = F_42 ( V_1 , V_27 , V_58 , V_28 ) ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_138;
if ( ( error = F_5 ( V_5 , V_130 , V_142 , & V_10 ) ) ) {
F_73 ( V_1 , L_5 ,
V_164 , error ) ;
goto V_138;
}
F_63 ( V_10 == 1 , V_138 ) ;
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( error ) {
F_73 ( V_1 , L_6 ,
V_164 , error ) ;
goto V_138;
}
F_63 ( V_10 == 1 , V_138 ) ;
V_163 = V_130 - V_16 . V_11 ;
ASSERT ( V_163 >= 0 && V_163 < V_97 ) ;
ASSERT ( ! ( V_16 . V_13 & F_68 ( V_163 ) ) ) ;
V_16 . V_13 |= F_68 ( V_163 ) ;
V_16 . V_12 ++ ;
if ( ! ( V_1 -> V_89 & V_169 ) &&
( V_16 . V_12 == F_28 ( V_1 ) ) ) {
* V_160 = 1 ;
* V_161 = F_67 ( V_1 , V_28 , V_16 . V_11 ) ;
V_162 = F_28 ( V_1 ) ;
F_39 ( & V_19 -> V_95 , - V_162 ) ;
F_39 ( & V_19 -> V_24 , - ( V_162 - 1 ) ) ;
F_45 ( V_27 , V_58 , V_102 | V_103 ) ;
V_65 = F_40 ( V_1 , V_28 ) ;
V_65 -> V_96 -= V_162 - 1 ;
F_41 ( V_65 ) ;
F_46 ( V_27 , V_105 , - V_162 ) ;
F_46 ( V_27 , V_106 , - ( V_162 - 1 ) ) ;
if ( ( error = F_74 ( V_5 , & V_10 ) ) ) {
F_73 ( V_1 , L_7 ,
V_164 , error ) ;
goto V_138;
}
F_75 ( F_34 ( V_1 ,
V_28 , F_76 ( V_1 , V_16 . V_11 ) ) ,
F_30 ( V_1 ) , V_159 , V_1 ) ;
} else {
* V_160 = 0 ;
error = F_7 ( V_5 , & V_16 ) ;
if ( error ) {
F_73 ( V_1 , L_8 ,
V_164 , error ) ;
goto V_138;
}
F_39 ( & V_19 -> V_24 , 1 ) ;
F_45 ( V_27 , V_58 , V_103 ) ;
V_65 = F_40 ( V_1 , V_28 ) ;
V_65 -> V_96 ++ ;
F_41 ( V_65 ) ;
F_46 ( V_27 , V_106 , 1 ) ;
}
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_138;
F_43 ( V_5 , V_101 ) ;
return 0 ;
V_138:
F_43 ( V_5 , V_100 ) ;
return error ;
}
STATIC int
F_77 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
T_2 V_130 ,
T_6 V_29 ,
T_6 * V_170 ,
T_6 * V_171 ,
int V_114 )
{
struct V_134 V_16 ;
struct V_4 * V_5 ;
struct V_32 * V_58 ;
int error ;
int V_10 ;
error = F_70 ( V_1 , V_27 , V_28 , & V_58 ) ;
if ( error ) {
F_78 ( V_1 ,
L_9 ,
V_164 , error , V_28 ) ;
return error ;
}
V_5 = F_42 ( V_1 , V_27 , V_58 , V_28 ) ;
error = F_5 ( V_5 , V_130 , V_142 , & V_10 ) ;
if ( ! error ) {
if ( V_10 )
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( ! error && V_10 == 0 )
error = V_165 ;
}
F_71 ( V_27 , V_58 ) ;
F_43 ( V_5 , V_101 ) ;
if ( error )
return error ;
if ( V_16 . V_11 > V_130 ||
V_16 . V_11 + F_28 ( V_1 ) <= V_130 )
return V_165 ;
if ( ( V_114 & V_172 ) &&
( V_16 . V_13 & F_68 ( V_130 - V_16 . V_11 ) ) )
return V_165 ;
* V_170 = F_32 ( V_1 , V_16 . V_11 ) ;
* V_171 = V_29 - * V_170 ;
return 0 ;
}
int
F_79 (
T_13 * V_1 ,
T_9 * V_27 ,
T_14 V_6 ,
struct F_79 * V_173 ,
T_8 V_114 )
{
T_6 V_29 ;
T_2 V_130 ;
T_5 V_28 ;
int V_35 ;
T_6 V_170 ;
T_6 V_174 ;
int error ;
int V_136 ;
int V_171 ;
ASSERT ( V_6 != V_154 ) ;
V_28 = F_54 ( V_1 , V_6 ) ;
V_130 = F_62 ( V_1 , V_6 ) ;
V_29 = F_32 ( V_1 , V_130 ) ;
if ( V_28 >= V_1 -> V_2 . V_157 || V_29 >= V_1 -> V_2 . V_166 ||
V_6 != F_67 ( V_1 , V_28 , V_130 ) ) {
#ifdef F_80
if ( V_114 & V_172 )
return F_29 ( V_165 ) ;
if ( V_28 >= V_1 -> V_2 . V_157 ) {
F_78 ( V_1 ,
L_10 ,
V_164 , V_28 , V_1 -> V_2 . V_157 ) ;
}
if ( V_29 >= V_1 -> V_2 . V_166 ) {
F_78 ( V_1 ,
L_11 ,
V_164 , ( unsigned long long ) V_29 ,
( unsigned long ) V_1 -> V_2 . V_166 ) ;
}
if ( V_6 != F_67 ( V_1 , V_28 , V_130 ) ) {
F_78 ( V_1 ,
L_12 ,
V_164 , V_6 ,
F_67 ( V_1 , V_28 , V_130 ) ) ;
}
F_81 () ;
#endif
return F_29 ( V_165 ) ;
}
V_35 = F_4 ( V_1 ) >> V_1 -> V_2 . V_175 ;
if ( V_114 & V_172 ) {
error = F_77 ( V_1 , V_27 , V_28 , V_130 , V_29 ,
& V_170 , & V_171 , V_114 ) ;
if ( error )
return error ;
goto V_176;
}
if ( F_4 ( V_1 ) <= V_1 -> V_2 . V_41 ) {
V_136 = F_82 ( V_1 , V_6 ) ;
ASSERT ( V_136 < V_1 -> V_2 . V_42 ) ;
V_173 -> V_177 = F_20 ( V_1 , V_28 , V_29 ) ;
V_173 -> V_178 = F_83 ( V_1 , 1 ) ;
V_173 -> V_179 = ( V_180 ) ( V_136 << V_1 -> V_2 . V_49 ) ;
return 0 ;
}
if ( V_1 -> V_181 ) {
V_171 = V_29 & V_1 -> V_181 ;
V_170 = V_29 - V_171 ;
} else {
error = F_77 ( V_1 , V_27 , V_28 , V_130 , V_29 ,
& V_170 , & V_171 , V_114 ) ;
if ( error )
return error ;
}
V_176:
ASSERT ( V_29 >= V_170 ) ;
V_174 = V_170 +
( ( V_171 / V_35 ) * V_35 ) ;
V_136 = ( ( V_29 - V_174 ) * V_1 -> V_2 . V_42 ) +
F_82 ( V_1 , V_6 ) ;
V_173 -> V_177 = F_20 ( V_1 , V_28 , V_174 ) ;
V_173 -> V_178 = F_83 ( V_1 , V_35 ) ;
V_173 -> V_179 = ( V_180 ) ( V_136 << V_1 -> V_2 . V_49 ) ;
if ( ( V_173 -> V_177 + V_173 -> V_178 ) >
F_83 ( V_1 , V_1 -> V_2 . V_182 ) ) {
F_78 ( V_1 ,
L_13 ,
V_164 , ( unsigned long long ) V_173 -> V_177 ,
( unsigned long long ) V_173 -> V_178 ,
F_83 ( V_1 , V_1 -> V_2 . V_182 ) ) ;
return F_29 ( V_165 ) ;
}
return 0 ;
}
void
F_84 (
T_13 * V_1 )
{
int V_183 ;
T_8 V_184 ;
T_8 V_185 ;
int V_186 ;
int V_187 ;
V_185 = ( 1LL << F_85 ( V_1 ) ) >>
V_188 ;
V_186 = V_1 -> V_189 [ 0 ] ;
V_187 = V_1 -> V_189 [ 1 ] ;
V_184 = ( V_185 + V_186 - 1 ) / V_186 ;
for ( V_183 = 1 ; V_184 > 1 ; V_183 ++ )
V_184 = ( V_184 + V_187 - 1 ) / V_187 ;
V_1 -> V_86 = V_183 ;
}
void
F_45 (
T_9 * V_27 ,
T_10 * V_190 ,
int V_191 )
{
int V_192 ;
int V_193 ;
static const short V_194 [] = {
F_86 ( T_11 , V_167 ) ,
F_86 ( T_11 , V_195 ) ,
F_86 ( T_11 , V_73 ) ,
F_86 ( T_11 , V_74 ) ,
F_86 ( T_11 , V_95 ) ,
F_86 ( T_11 , V_92 ) ,
F_86 ( T_11 , V_196 ) ,
F_86 ( T_11 , V_24 ) ,
F_86 ( T_11 , V_72 ) ,
F_86 ( T_11 , V_197 ) ,
F_86 ( T_11 , V_198 ) ,
sizeof( T_11 )
} ;
#ifdef F_80
T_11 * V_19 ;
V_19 = F_31 ( V_190 ) ;
ASSERT ( V_19 -> V_167 == F_8 ( V_168 ) ) ;
#endif
F_87 ( V_191 , V_194 , V_199 , & V_192 , & V_193 ) ;
F_25 ( V_27 , V_190 , V_192 , V_193 ) ;
}
STATIC void
F_88 (
struct V_18 * V_19 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_200 ; V_10 ++ )
ASSERT ( V_19 -> V_198 [ V_10 ] ) ;
}
static void
F_89 (
struct V_32 * V_190 )
{
struct V_25 * V_1 = V_190 -> V_201 -> V_202 ;
struct V_18 * V_19 = F_31 ( V_190 ) ;
int V_203 ;
V_203 = V_19 -> V_167 == F_8 ( V_168 ) &&
F_90 ( F_13 ( V_19 -> V_195 ) ) ;
if ( V_190 -> V_204 )
V_203 = V_203 && F_13 ( V_19 -> V_73 ) ==
V_190 -> V_204 -> V_205 ;
if ( F_36 ( F_91 ( ! V_203 , V_1 , V_206 ,
V_207 ) ) ) {
F_92 ( V_164 , V_208 , V_1 , V_19 ) ;
F_93 ( V_190 , V_209 ) ;
}
F_88 ( V_19 ) ;
}
static void
F_94 (
struct V_32 * V_190 )
{
F_89 ( V_190 ) ;
}
static void
F_95 (
struct V_32 * V_190 )
{
F_89 ( V_190 ) ;
}
int
F_96 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
struct V_32 * * V_210 )
{
int error ;
ASSERT ( V_28 != V_127 ) ;
error = F_97 ( V_1 , V_27 , V_1 -> V_43 ,
F_98 ( V_1 , V_28 , F_99 ( V_1 ) ) ,
F_100 ( V_1 , 1 ) , 0 , V_210 , & V_211 ) ;
if ( error )
return error ;
ASSERT ( ! F_101 ( * V_210 ) ) ;
F_102 ( * V_210 , V_212 ) ;
return 0 ;
}
int
F_70 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
struct V_32 * * V_210 )
{
struct V_18 * V_19 ;
struct V_64 * V_65 ;
int error ;
error = F_96 ( V_1 , V_27 , V_28 , V_210 ) ;
if ( error )
return error ;
V_19 = F_31 ( * V_210 ) ;
V_65 = F_40 ( V_1 , V_28 ) ;
if ( ! V_65 -> V_122 ) {
V_65 -> V_96 = F_13 ( V_19 -> V_24 ) ;
V_65 -> V_213 = F_13 ( V_19 -> V_95 ) ;
V_65 -> V_122 = 1 ;
}
ASSERT ( V_65 -> V_96 == F_13 ( V_19 -> V_24 ) ||
F_17 ( V_1 ) ) ;
F_41 ( V_65 ) ;
return 0 ;
}
int
F_55 (
T_13 * V_1 ,
T_9 * V_27 ,
T_5 V_28 )
{
T_10 * V_190 = NULL ;
int error ;
error = F_70 ( V_1 , V_27 , V_28 , & V_190 ) ;
if ( error )
return error ;
if ( V_190 )
F_71 ( V_27 , V_190 ) ;
return 0 ;
}
