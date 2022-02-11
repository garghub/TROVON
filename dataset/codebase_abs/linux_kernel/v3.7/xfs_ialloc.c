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
V_1 -> V_44 * V_35 , 0 ) ;
if ( ! V_33 )
return V_45 ;
F_22 ( V_33 , 0 , V_37 << V_1 -> V_2 . V_46 ) ;
for ( V_10 = 0 ; V_10 < V_37 ; V_10 ++ ) {
int V_47 = V_10 << V_1 -> V_2 . V_46 ;
T_8 V_48 = sizeof( struct V_34 ) ;
free = F_23 ( V_1 , V_33 , V_10 ) ;
free -> V_49 = F_24 ( V_50 ) ;
free -> V_51 = V_38 ;
free -> V_52 = F_8 ( V_31 ) ;
free -> V_53 = F_8 ( V_54 ) ;
F_25 ( V_27 , V_33 , V_47 , V_47 + V_48 - 1 ) ;
}
F_26 ( V_27 , V_33 ) ;
}
return 0 ;
}
STATIC int
F_27 (
T_9 * V_27 ,
T_10 * V_55 ,
int * V_56 )
{
T_11 * V_19 ;
T_1 args ;
T_12 * V_5 ;
T_5 V_28 ;
int error ;
int V_10 ;
T_2 V_57 ;
T_2 V_58 ;
T_2 V_59 ;
int V_60 = 0 ;
struct V_61 * V_62 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_27 = V_27 ;
args . V_1 = V_27 -> V_63 ;
V_58 = F_28 ( args . V_1 ) ;
if ( args . V_1 -> V_64 &&
args . V_1 -> V_2 . V_65 + V_58 > args . V_1 -> V_64 )
return F_29 ( V_66 ) ;
args . V_67 = args . V_68 = F_30 ( args . V_1 ) ;
V_19 = F_31 ( V_55 ) ;
V_57 = F_13 ( V_19 -> V_69 ) ;
V_28 = F_13 ( V_19 -> V_70 ) ;
args . V_29 = F_32 ( args . V_1 , V_57 ) +
F_30 ( args . V_1 ) ;
if ( F_33 ( V_57 != V_54 &&
( args . V_29 < F_13 ( V_19 -> V_71 ) ) ) ) {
args . V_72 = F_34 ( args . V_1 , V_28 , args . V_29 ) ;
args . type = V_73 ;
args . V_74 = args . V_75 = args . V_76 = args . V_77 =
args . V_78 = args . V_79 = 0 ;
args . V_80 = 1 ;
args . V_81 = 1 ;
args . V_79 = F_1 ( & args ) - 1 ;
args . V_82 = args . V_1 -> V_83 - 1 ;
if ( ( error = F_35 ( & args ) ) )
return error ;
} else
args . V_72 = V_84 ;
if ( F_36 ( args . V_72 == V_84 ) ) {
V_60 = 0 ;
if ( args . V_1 -> V_85 ) {
ASSERT ( ! ( args . V_1 -> V_86 & V_87 ) ) ;
args . V_81 = args . V_1 -> V_88 ;
V_60 = 1 ;
} else
args . V_81 = F_1 ( & args ) ;
args . V_29 = F_13 ( V_19 -> V_89 ) ;
args . V_72 = F_34 ( args . V_1 , V_28 , args . V_29 ) ;
args . type = V_90 ;
args . V_74 = args . V_75 = args . V_76 = args . V_77 =
args . V_78 = args . V_79 = 0 ;
args . V_80 = 1 ;
args . V_82 = args . V_1 -> V_83 - 1 ;
if ( ( error = F_35 ( & args ) ) )
return error ;
}
if ( V_60 && args . V_72 == V_84 ) {
args . type = V_90 ;
args . V_29 = F_13 ( V_19 -> V_89 ) ;
args . V_72 = F_34 ( args . V_1 , V_28 , args . V_29 ) ;
args . V_81 = F_1 ( & args ) ;
if ( ( error = F_35 ( & args ) ) )
return error ;
}
if ( args . V_72 == V_84 ) {
* V_56 = 0 ;
return 0 ;
}
ASSERT ( args . V_91 == args . V_67 ) ;
error = F_18 ( args . V_1 , V_27 , V_28 , args . V_29 ,
args . V_91 , F_37 () ) ;
if ( error )
return error ;
V_57 = F_38 ( args . V_1 , args . V_29 , 0 ) ;
F_39 ( & V_19 -> V_92 , V_58 ) ;
F_39 ( & V_19 -> V_24 , V_58 ) ;
V_62 = F_40 ( args . V_1 , V_28 ) ;
V_62 -> V_93 += V_58 ;
F_41 ( V_62 ) ;
V_19 -> V_69 = F_8 ( V_57 ) ;
V_5 = F_42 ( args . V_1 , V_27 , V_55 , V_28 ) ;
for ( V_59 = V_57 ;
V_59 < V_57 + V_58 ;
V_59 += V_94 ) {
V_5 -> V_9 . V_10 . V_11 = V_59 ;
V_5 -> V_9 . V_10 . V_12 = V_94 ;
V_5 -> V_9 . V_10 . V_13 = V_95 ;
error = F_6 ( V_5 , V_96 , & V_10 ) ;
if ( error ) {
F_43 ( V_5 , V_97 ) ;
return error ;
}
ASSERT ( V_10 == 0 ) ;
error = F_44 ( V_5 , & V_10 ) ;
if ( error ) {
F_43 ( V_5 , V_97 ) ;
return error ;
}
ASSERT ( V_10 == 1 ) ;
}
F_43 ( V_5 , V_98 ) ;
F_45 ( V_27 , V_55 ,
V_99 | V_100 | V_101 ) ;
F_46 ( V_27 , V_102 , ( long ) V_58 ) ;
F_46 ( V_27 , V_103 , ( long ) V_58 ) ;
* V_56 = 1 ;
return 0 ;
}
STATIC T_5
F_47 (
T_13 * V_1 )
{
T_5 V_28 ;
F_48 ( & V_1 -> V_104 ) ;
V_28 = V_1 -> V_105 ;
if ( ++ V_1 -> V_105 >= V_1 -> V_106 )
V_1 -> V_105 = 0 ;
F_49 ( & V_1 -> V_104 ) ;
return V_28 ;
}
STATIC T_5
F_50 (
T_9 * V_27 ,
T_14 V_107 ,
T_15 V_108 ,
int V_109 )
{
T_5 V_110 ;
T_5 V_28 ;
int V_111 ;
T_16 V_112 ;
T_16 V_113 = 0 ;
T_13 * V_1 ;
int V_114 ;
T_17 * V_62 ;
T_5 V_115 ;
int error ;
V_114 = F_51 ( V_108 ) || F_52 ( V_108 ) || F_53 ( V_108 ) ;
V_1 = V_27 -> V_63 ;
V_110 = V_1 -> V_106 ;
if ( F_51 ( V_108 ) )
V_115 = F_47 ( V_1 ) ;
else {
V_115 = F_54 ( V_1 , V_107 ) ;
if ( V_115 >= V_110 )
V_115 = 0 ;
}
ASSERT ( V_115 < V_110 ) ;
V_28 = V_115 ;
V_111 = V_116 ;
for (; ; ) {
V_62 = F_40 ( V_1 , V_28 ) ;
if ( ! V_62 -> V_117 ) {
F_47 ( V_1 ) ;
goto V_118;
}
if ( ! V_62 -> V_119 ) {
error = F_55 ( V_1 , V_27 , V_28 ) ;
if ( error )
goto V_118;
}
if ( V_62 -> V_93 ) {
F_41 ( V_62 ) ;
return V_28 ;
}
if ( ! V_109 )
goto V_118;
if ( ! V_62 -> V_120 ) {
error = F_56 ( V_1 , V_27 , V_28 , V_111 ) ;
if ( error )
goto V_118;
}
V_112 = F_30 ( V_1 ) ;
V_113 = V_62 -> V_121 ;
if ( ! V_113 )
V_113 = V_62 -> V_122 > 0 ;
if ( V_62 -> V_123 >= V_114 + V_112 &&
V_113 >= V_112 ) {
F_41 ( V_62 ) ;
return V_28 ;
}
V_118:
F_41 ( V_62 ) ;
if ( F_17 ( V_1 ) )
return V_124 ;
V_28 ++ ;
if ( V_28 >= V_110 )
V_28 = 0 ;
if ( V_28 == V_115 ) {
if ( V_111 == 0 )
return V_124 ;
V_111 = 0 ;
}
}
}
STATIC int
F_57 (
struct V_4 * V_5 ,
T_4 * V_16 ,
int * V_125 ,
int V_126 )
{
int error ;
int V_10 ;
if ( V_126 )
error = F_58 ( V_5 , 0 , & V_10 ) ;
else
error = F_16 ( V_5 , 0 , & V_10 ) ;
if ( error )
return error ;
* V_125 = ! V_10 ;
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
T_2 V_127 ,
T_4 * V_16 ,
int * V_125 ,
int V_126 )
{
int error ;
int V_10 ;
error = F_5 ( V_5 , V_127 , V_96 , & V_10 ) ;
if ( error )
return error ;
* V_125 = ! V_10 ;
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
struct V_32 * V_55 ,
T_14 V_107 ,
T_14 * V_128 )
{
struct V_25 * V_1 = V_27 -> V_63 ;
struct V_18 * V_19 = F_31 ( V_55 ) ;
T_5 V_28 = F_13 ( V_19 -> V_70 ) ;
T_5 V_115 = F_54 ( V_1 , V_107 ) ;
T_2 V_129 = F_62 ( V_1 , V_107 ) ;
struct V_61 * V_62 ;
struct V_4 * V_5 , * V_130 ;
struct V_131 V_16 , V_132 ;
T_14 V_6 ;
int error ;
int V_133 ;
int V_10 , V_39 ;
V_62 = F_40 ( V_1 , V_28 ) ;
ASSERT ( V_62 -> V_119 ) ;
ASSERT ( V_62 -> V_117 ) ;
ASSERT ( V_62 -> V_93 > 0 ) ;
V_134:
V_5 = F_42 ( V_1 , V_27 , V_55 , V_28 ) ;
if ( ! V_129 )
V_129 = F_13 ( V_19 -> V_69 ) ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_135;
if ( V_115 == V_28 ) {
int V_136 ;
int V_137 ;
int V_138 = 10 ;
error = F_5 ( V_5 , V_129 , V_139 , & V_10 ) ;
if ( error )
goto V_135;
F_63 ( V_10 == 1 , V_135 ) ;
error = F_11 ( V_5 , & V_16 , & V_39 ) ;
if ( error )
goto V_135;
F_63 ( V_10 == 1 , V_135 ) ;
if ( V_16 . V_12 > 0 ) {
goto V_140;
}
error = F_64 ( V_5 , & V_130 ) ;
if ( error )
goto V_135;
if ( V_129 != V_54 &&
V_62 -> V_141 == V_129 &&
V_62 -> V_142 != V_54 &&
V_62 -> V_143 != V_54 ) {
error = F_60 ( V_130 , V_62 -> V_142 ,
& V_132 , & V_136 , 1 ) ;
if ( error )
goto V_144;
error = F_60 ( V_5 , V_62 -> V_143 ,
& V_16 , & V_137 , 0 ) ;
if ( error )
goto V_144;
} else {
error = F_57 ( V_130 , & V_132 , & V_136 , 1 ) ;
if ( error )
goto V_144;
error = F_57 ( V_5 , & V_16 , & V_137 , 0 ) ;
if ( error )
goto V_144;
}
while ( ! V_136 || ! V_137 ) {
int V_145 ;
if ( ! -- V_138 ) {
F_43 ( V_130 , V_98 ) ;
V_62 -> V_142 = V_132 . V_11 ;
V_62 -> V_143 = V_16 . V_11 ;
V_62 -> V_141 = V_129 ;
goto V_57;
}
if ( ! V_136 && ! V_137 ) {
V_145 = V_129 -
( V_132 . V_11 + V_94 - 1 ) <
V_16 . V_11 - V_129 ;
} else {
V_145 = ! V_136 ;
}
if ( V_145 && V_132 . V_12 ) {
V_16 = V_132 ;
F_43 ( V_5 , V_98 ) ;
V_5 = V_130 ;
V_62 -> V_142 = V_132 . V_11 ;
V_62 -> V_143 = V_16 . V_11 ;
V_62 -> V_141 = V_129 ;
goto V_140;
}
if ( ! V_145 && V_16 . V_12 ) {
F_43 ( V_130 , V_98 ) ;
V_62 -> V_142 = V_132 . V_11 ;
V_62 -> V_143 = V_16 . V_11 ;
V_62 -> V_141 = V_129 ;
goto V_140;
}
if ( V_145 ) {
error = F_57 ( V_130 , & V_132 ,
& V_136 , 1 ) ;
} else {
error = F_57 ( V_5 , & V_16 ,
& V_137 , 0 ) ;
}
if ( error )
goto V_144;
}
V_62 -> V_141 = V_54 ;
V_62 -> V_142 = V_54 ;
V_62 -> V_143 = V_54 ;
F_43 ( V_130 , V_98 ) ;
F_43 ( V_5 , V_98 ) ;
goto V_134;
}
V_57:
if ( V_19 -> V_69 != F_8 ( V_54 ) ) {
error = F_5 ( V_5 , F_13 ( V_19 -> V_69 ) ,
V_96 , & V_10 ) ;
if ( error )
goto V_135;
if ( V_10 == 1 ) {
error = F_11 ( V_5 , & V_16 , & V_39 ) ;
if ( error )
goto V_135;
if ( V_39 == 1 && V_16 . V_12 > 0 ) {
goto V_140;
}
}
}
error = F_5 ( V_5 , 0 , V_22 , & V_10 ) ;
if ( error )
goto V_135;
F_63 ( V_10 == 1 , V_135 ) ;
for (; ; ) {
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( error )
goto V_135;
F_63 ( V_10 == 1 , V_135 ) ;
if ( V_16 . V_12 > 0 )
break;
error = F_16 ( V_5 , 0 , & V_10 ) ;
if ( error )
goto V_135;
F_63 ( V_10 == 1 , V_135 ) ;
}
V_140:
V_133 = F_65 ( V_16 . V_13 ) ;
ASSERT ( V_133 >= 0 ) ;
ASSERT ( V_133 < V_94 ) ;
ASSERT ( ( F_66 ( V_1 , V_16 . V_11 ) %
V_94 ) == 0 ) ;
V_6 = F_67 ( V_1 , V_28 , V_16 . V_11 + V_133 ) ;
V_16 . V_13 &= ~ F_68 ( V_133 ) ;
V_16 . V_12 -- ;
error = F_7 ( V_5 , & V_16 ) ;
if ( error )
goto V_135;
F_39 ( & V_19 -> V_24 , - 1 ) ;
F_45 ( V_27 , V_55 , V_100 ) ;
V_62 -> V_93 -- ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_135;
F_43 ( V_5 , V_98 ) ;
F_46 ( V_27 , V_103 , - 1 ) ;
F_41 ( V_62 ) ;
* V_128 = V_6 ;
return 0 ;
V_144:
F_43 ( V_130 , V_97 ) ;
V_135:
F_43 ( V_5 , V_97 ) ;
F_41 ( V_62 ) ;
return error ;
}
int
F_69 (
struct V_26 * V_27 ,
T_14 V_107 ,
T_15 V_108 ,
int V_109 ,
struct V_32 * * V_146 ,
T_14 * V_128 )
{
struct V_25 * V_1 = V_27 -> V_63 ;
struct V_32 * V_55 ;
T_5 V_28 ;
int error ;
int V_147 ;
int V_148 = 0 ;
T_5 V_149 ;
struct V_61 * V_62 ;
if ( * V_146 ) {
V_55 = * V_146 ;
goto V_150;
}
V_149 = F_50 ( V_27 , V_107 , V_108 , V_109 ) ;
if ( V_149 == V_124 ) {
* V_128 = V_151 ;
return 0 ;
}
if ( V_1 -> V_64 &&
V_1 -> V_2 . V_65 + F_28 ( V_1 ) > V_1 -> V_64 ) {
V_148 = 1 ;
V_109 = 0 ;
}
V_28 = V_149 ;
for (; ; ) {
V_62 = F_40 ( V_1 , V_28 ) ;
if ( ! V_62 -> V_117 ) {
F_47 ( V_1 ) ;
goto V_118;
}
if ( ! V_62 -> V_119 ) {
error = F_55 ( V_1 , V_27 , V_28 ) ;
if ( error )
goto V_152;
}
if ( ! V_62 -> V_93 && ! V_109 )
goto V_118;
error = F_70 ( V_1 , V_27 , V_28 , & V_55 ) ;
if ( error )
goto V_152;
if ( V_62 -> V_93 ) {
F_41 ( V_62 ) ;
goto V_150;
}
if ( ! V_109 )
goto V_153;
error = F_27 ( V_27 , V_55 , & V_147 ) ;
if ( error ) {
F_71 ( V_27 , V_55 ) ;
if ( error != V_66 )
goto V_152;
F_41 ( V_62 ) ;
* V_128 = V_151 ;
return 0 ;
}
if ( V_147 ) {
ASSERT ( V_62 -> V_93 > 0 ) ;
F_41 ( V_62 ) ;
* V_146 = V_55 ;
* V_128 = V_151 ;
return 0 ;
}
V_153:
F_71 ( V_27 , V_55 ) ;
V_118:
F_41 ( V_62 ) ;
if ( ++ V_28 == V_1 -> V_2 . V_154 )
V_28 = 0 ;
if ( V_28 == V_149 ) {
* V_128 = V_151 ;
return V_148 ? V_66 : 0 ;
}
}
V_150:
* V_146 = NULL ;
return F_61 ( V_27 , V_55 , V_107 , V_128 ) ;
V_152:
F_41 ( V_62 ) ;
return F_29 ( error ) ;
}
int
F_72 (
T_9 * V_27 ,
T_14 V_155 ,
T_18 * V_156 ,
int * V_157 ,
T_14 * V_158 )
{
T_6 V_29 ;
T_10 * V_55 ;
T_2 V_127 ;
T_5 V_28 ;
T_11 * V_19 ;
T_12 * V_5 ;
int error ;
int V_10 ;
int V_159 ;
T_13 * V_1 ;
int V_160 ;
T_4 V_16 ;
struct V_61 * V_62 ;
V_1 = V_27 -> V_63 ;
V_28 = F_54 ( V_1 , V_155 ) ;
if ( V_28 >= V_1 -> V_2 . V_154 ) {
F_73 ( V_1 , L_1 ,
V_161 , V_28 , V_1 -> V_2 . V_154 ) ;
ASSERT ( 0 ) ;
return F_29 ( V_162 ) ;
}
V_127 = F_62 ( V_1 , V_155 ) ;
if ( V_155 != F_67 ( V_1 , V_28 , V_127 ) ) {
F_73 ( V_1 , L_2 ,
V_161 , ( unsigned long long ) V_155 ,
( unsigned long long ) F_67 ( V_1 , V_28 , V_127 ) ) ;
ASSERT ( 0 ) ;
return F_29 ( V_162 ) ;
}
V_29 = F_32 ( V_1 , V_127 ) ;
if ( V_29 >= V_1 -> V_2 . V_163 ) {
F_73 ( V_1 , L_3 ,
V_161 , V_29 , V_1 -> V_2 . V_163 ) ;
ASSERT ( 0 ) ;
return F_29 ( V_162 ) ;
}
error = F_70 ( V_1 , V_27 , V_28 , & V_55 ) ;
if ( error ) {
F_73 ( V_1 , L_4 ,
V_161 , error ) ;
return error ;
}
V_19 = F_31 ( V_55 ) ;
ASSERT ( V_19 -> V_164 == F_8 ( V_165 ) ) ;
ASSERT ( V_29 < F_13 ( V_19 -> V_71 ) ) ;
V_5 = F_42 ( V_1 , V_27 , V_55 , V_28 ) ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_135;
if ( ( error = F_5 ( V_5 , V_127 , V_139 , & V_10 ) ) ) {
F_73 ( V_1 , L_5 ,
V_161 , error ) ;
goto V_135;
}
F_63 ( V_10 == 1 , V_135 ) ;
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( error ) {
F_73 ( V_1 , L_6 ,
V_161 , error ) ;
goto V_135;
}
F_63 ( V_10 == 1 , V_135 ) ;
V_160 = V_127 - V_16 . V_11 ;
ASSERT ( V_160 >= 0 && V_160 < V_94 ) ;
ASSERT ( ! ( V_16 . V_13 & F_68 ( V_160 ) ) ) ;
V_16 . V_13 |= F_68 ( V_160 ) ;
V_16 . V_12 ++ ;
if ( ! ( V_1 -> V_86 & V_166 ) &&
( V_16 . V_12 == F_28 ( V_1 ) ) ) {
* V_157 = 1 ;
* V_158 = F_67 ( V_1 , V_28 , V_16 . V_11 ) ;
V_159 = F_28 ( V_1 ) ;
F_39 ( & V_19 -> V_92 , - V_159 ) ;
F_39 ( & V_19 -> V_24 , - ( V_159 - 1 ) ) ;
F_45 ( V_27 , V_55 , V_99 | V_100 ) ;
V_62 = F_40 ( V_1 , V_28 ) ;
V_62 -> V_93 -= V_159 - 1 ;
F_41 ( V_62 ) ;
F_46 ( V_27 , V_102 , - V_159 ) ;
F_46 ( V_27 , V_103 , - ( V_159 - 1 ) ) ;
if ( ( error = F_74 ( V_5 , & V_10 ) ) ) {
F_73 ( V_1 , L_7 ,
V_161 , error ) ;
goto V_135;
}
F_75 ( F_34 ( V_1 ,
V_28 , F_76 ( V_1 , V_16 . V_11 ) ) ,
F_30 ( V_1 ) , V_156 , V_1 ) ;
} else {
* V_157 = 0 ;
error = F_7 ( V_5 , & V_16 ) ;
if ( error ) {
F_73 ( V_1 , L_8 ,
V_161 , error ) ;
goto V_135;
}
F_39 ( & V_19 -> V_24 , 1 ) ;
F_45 ( V_27 , V_55 , V_100 ) ;
V_62 = F_40 ( V_1 , V_28 ) ;
V_62 -> V_93 ++ ;
F_41 ( V_62 ) ;
F_46 ( V_27 , V_103 , 1 ) ;
}
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_135;
F_43 ( V_5 , V_98 ) ;
return 0 ;
V_135:
F_43 ( V_5 , V_97 ) ;
return error ;
}
STATIC int
F_77 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
T_2 V_127 ,
T_6 V_29 ,
T_6 * V_167 ,
T_6 * V_168 ,
int V_111 )
{
struct V_131 V_16 ;
struct V_4 * V_5 ;
struct V_32 * V_55 ;
int error ;
int V_10 ;
error = F_70 ( V_1 , V_27 , V_28 , & V_55 ) ;
if ( error ) {
F_78 ( V_1 ,
L_9 ,
V_161 , error , V_28 ) ;
return error ;
}
V_5 = F_42 ( V_1 , V_27 , V_55 , V_28 ) ;
error = F_5 ( V_5 , V_127 , V_139 , & V_10 ) ;
if ( ! error ) {
if ( V_10 )
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( ! error && V_10 == 0 )
error = V_162 ;
}
F_71 ( V_27 , V_55 ) ;
F_43 ( V_5 , V_98 ) ;
if ( error )
return error ;
if ( V_16 . V_11 > V_127 ||
V_16 . V_11 + F_28 ( V_1 ) <= V_127 )
return V_162 ;
if ( ( V_111 & V_169 ) &&
( V_16 . V_13 & F_68 ( V_127 - V_16 . V_11 ) ) )
return V_162 ;
* V_167 = F_32 ( V_1 , V_16 . V_11 ) ;
* V_168 = V_29 - * V_167 ;
return 0 ;
}
int
F_79 (
T_13 * V_1 ,
T_9 * V_27 ,
T_14 V_6 ,
struct F_79 * V_170 ,
T_8 V_111 )
{
T_6 V_29 ;
T_2 V_127 ;
T_5 V_28 ;
int V_35 ;
T_6 V_167 ;
T_6 V_171 ;
int error ;
int V_133 ;
int V_168 ;
ASSERT ( V_6 != V_151 ) ;
V_28 = F_54 ( V_1 , V_6 ) ;
V_127 = F_62 ( V_1 , V_6 ) ;
V_29 = F_32 ( V_1 , V_127 ) ;
if ( V_28 >= V_1 -> V_2 . V_154 || V_29 >= V_1 -> V_2 . V_163 ||
V_6 != F_67 ( V_1 , V_28 , V_127 ) ) {
#ifdef F_80
if ( V_111 & V_169 )
return F_29 ( V_162 ) ;
if ( V_28 >= V_1 -> V_2 . V_154 ) {
F_78 ( V_1 ,
L_10 ,
V_161 , V_28 , V_1 -> V_2 . V_154 ) ;
}
if ( V_29 >= V_1 -> V_2 . V_163 ) {
F_78 ( V_1 ,
L_11 ,
V_161 , ( unsigned long long ) V_29 ,
( unsigned long ) V_1 -> V_2 . V_163 ) ;
}
if ( V_6 != F_67 ( V_1 , V_28 , V_127 ) ) {
F_78 ( V_1 ,
L_12 ,
V_161 , V_6 ,
F_67 ( V_1 , V_28 , V_127 ) ) ;
}
F_81 () ;
#endif
return F_29 ( V_162 ) ;
}
V_35 = F_4 ( V_1 ) >> V_1 -> V_2 . V_172 ;
if ( V_111 & V_169 ) {
error = F_77 ( V_1 , V_27 , V_28 , V_127 , V_29 ,
& V_167 , & V_168 , V_111 ) ;
if ( error )
return error ;
goto V_173;
}
if ( F_4 ( V_1 ) <= V_1 -> V_2 . V_41 ) {
V_133 = F_82 ( V_1 , V_6 ) ;
ASSERT ( V_133 < V_1 -> V_2 . V_42 ) ;
V_170 -> V_174 = F_20 ( V_1 , V_28 , V_29 ) ;
V_170 -> V_175 = F_83 ( V_1 , 1 ) ;
V_170 -> V_176 = ( V_177 ) ( V_133 << V_1 -> V_2 . V_46 ) ;
return 0 ;
}
if ( V_1 -> V_178 ) {
V_168 = V_29 & V_1 -> V_178 ;
V_167 = V_29 - V_168 ;
} else {
error = F_77 ( V_1 , V_27 , V_28 , V_127 , V_29 ,
& V_167 , & V_168 , V_111 ) ;
if ( error )
return error ;
}
V_173:
ASSERT ( V_29 >= V_167 ) ;
V_171 = V_167 +
( ( V_168 / V_35 ) * V_35 ) ;
V_133 = ( ( V_29 - V_171 ) * V_1 -> V_2 . V_42 ) +
F_82 ( V_1 , V_6 ) ;
V_170 -> V_174 = F_20 ( V_1 , V_28 , V_171 ) ;
V_170 -> V_175 = F_83 ( V_1 , V_35 ) ;
V_170 -> V_176 = ( V_177 ) ( V_133 << V_1 -> V_2 . V_46 ) ;
if ( ( V_170 -> V_174 + V_170 -> V_175 ) >
F_83 ( V_1 , V_1 -> V_2 . V_179 ) ) {
F_78 ( V_1 ,
L_13 ,
V_161 , ( unsigned long long ) V_170 -> V_174 ,
( unsigned long long ) V_170 -> V_175 ,
F_83 ( V_1 , V_1 -> V_2 . V_179 ) ) ;
return F_29 ( V_162 ) ;
}
return 0 ;
}
void
F_84 (
T_13 * V_1 )
{
int V_180 ;
T_8 V_181 ;
T_8 V_182 ;
int V_183 ;
int V_184 ;
V_182 = ( 1LL << F_85 ( V_1 ) ) >>
V_185 ;
V_183 = V_1 -> V_186 [ 0 ] ;
V_184 = V_1 -> V_186 [ 1 ] ;
V_181 = ( V_182 + V_183 - 1 ) / V_183 ;
for ( V_180 = 1 ; V_181 > 1 ; V_180 ++ )
V_181 = ( V_181 + V_184 - 1 ) / V_184 ;
V_1 -> V_83 = V_180 ;
}
void
F_45 (
T_9 * V_27 ,
T_10 * V_187 ,
int V_188 )
{
int V_189 ;
int V_190 ;
static const short V_191 [] = {
F_86 ( T_11 , V_164 ) ,
F_86 ( T_11 , V_192 ) ,
F_86 ( T_11 , V_70 ) ,
F_86 ( T_11 , V_71 ) ,
F_86 ( T_11 , V_92 ) ,
F_86 ( T_11 , V_89 ) ,
F_86 ( T_11 , V_193 ) ,
F_86 ( T_11 , V_24 ) ,
F_86 ( T_11 , V_69 ) ,
F_86 ( T_11 , V_194 ) ,
F_86 ( T_11 , V_195 ) ,
sizeof( T_11 )
} ;
#ifdef F_80
T_11 * V_19 ;
V_19 = F_31 ( V_187 ) ;
ASSERT ( V_19 -> V_164 == F_8 ( V_165 ) ) ;
#endif
F_87 ( V_188 , V_191 , V_196 , & V_189 , & V_190 ) ;
F_25 ( V_27 , V_187 , V_189 , V_190 ) ;
}
STATIC void
F_88 (
struct V_18 * V_19 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_197 ; V_10 ++ )
ASSERT ( V_19 -> V_195 [ V_10 ] ) ;
}
int
F_89 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
struct V_32 * * V_198 )
{
struct V_18 * V_19 ;
int V_199 ;
int error ;
ASSERT ( V_28 != V_124 ) ;
error = F_90 ( V_1 , V_27 , V_1 -> V_43 ,
F_91 ( V_1 , V_28 , F_92 ( V_1 ) ) ,
F_93 ( V_1 , 1 ) , 0 , V_198 ) ;
if ( error )
return error ;
ASSERT ( ! F_94 ( * V_198 ) ) ;
V_19 = F_31 ( * V_198 ) ;
V_199 = V_19 -> V_164 == F_8 ( V_165 ) &&
F_95 ( F_13 ( V_19 -> V_192 ) ) &&
F_13 ( V_19 -> V_70 ) == V_28 ;
if ( F_36 ( F_96 ( ! V_199 , V_1 , V_200 ,
V_201 ) ) ) {
F_97 ( L_14 , V_202 ,
V_1 , V_19 ) ;
F_71 ( V_27 , * V_198 ) ;
return F_29 ( V_203 ) ;
}
F_98 ( * V_198 , V_204 ) ;
F_88 ( V_19 ) ;
return 0 ;
}
int
F_70 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
struct V_32 * * V_198 )
{
struct V_18 * V_19 ;
struct V_61 * V_62 ;
int error ;
error = F_89 ( V_1 , V_27 , V_28 , V_198 ) ;
if ( error )
return error ;
V_19 = F_31 ( * V_198 ) ;
V_62 = F_40 ( V_1 , V_28 ) ;
if ( ! V_62 -> V_119 ) {
V_62 -> V_93 = F_13 ( V_19 -> V_24 ) ;
V_62 -> V_205 = F_13 ( V_19 -> V_92 ) ;
V_62 -> V_119 = 1 ;
}
ASSERT ( V_62 -> V_93 == F_13 ( V_19 -> V_24 ) ||
F_17 ( V_1 ) ) ;
F_41 ( V_62 ) ;
return 0 ;
}
int
F_55 (
T_13 * V_1 ,
T_9 * V_27 ,
T_5 V_28 )
{
T_10 * V_187 = NULL ;
int error ;
error = F_70 ( V_1 , V_27 , V_28 , & V_187 ) ;
if ( error )
return error ;
if ( V_187 )
F_71 ( V_27 , V_187 ) ;
return 0 ;
}
