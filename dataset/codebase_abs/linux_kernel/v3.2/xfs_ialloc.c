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
F_22 ( V_33 , 0 , V_37 << V_1 -> V_2 . V_47 ) ;
for ( V_10 = 0 ; V_10 < V_37 ; V_10 ++ ) {
int V_48 = V_10 << V_1 -> V_2 . V_47 ;
T_8 V_49 = sizeof( struct V_34 ) ;
free = F_23 ( V_1 , V_33 , V_10 ) ;
free -> V_50 = F_24 ( V_51 ) ;
free -> V_52 = V_38 ;
free -> V_53 = F_8 ( V_31 ) ;
free -> V_54 = F_8 ( V_55 ) ;
F_25 ( V_27 , V_33 , V_48 , V_48 + V_49 - 1 ) ;
}
F_26 ( V_27 , V_33 ) ;
}
return 0 ;
}
STATIC int
F_27 (
T_9 * V_27 ,
T_10 * V_56 ,
int * V_57 )
{
T_11 * V_19 ;
T_1 args ;
T_12 * V_5 ;
T_5 V_28 ;
int error ;
int V_10 ;
T_2 V_58 ;
T_2 V_59 ;
T_2 V_60 ;
int V_61 = 0 ;
struct V_62 * V_63 ;
args . V_27 = V_27 ;
args . V_1 = V_27 -> V_64 ;
V_59 = F_28 ( args . V_1 ) ;
if ( args . V_1 -> V_65 &&
args . V_1 -> V_2 . V_66 + V_59 > args . V_1 -> V_65 )
return F_29 ( V_67 ) ;
args . V_68 = args . V_69 = F_30 ( args . V_1 ) ;
V_19 = F_31 ( V_56 ) ;
V_58 = F_13 ( V_19 -> V_70 ) ;
V_28 = F_13 ( V_19 -> V_71 ) ;
args . V_29 = F_32 ( args . V_1 , V_58 ) +
F_30 ( args . V_1 ) ;
if ( F_33 ( V_58 != V_55 &&
( args . V_29 < F_13 ( V_19 -> V_72 ) ) ) ) {
args . V_73 = F_34 ( args . V_1 , V_28 , args . V_29 ) ;
args . type = V_74 ;
args . V_75 = args . V_76 = args . V_77 = args . V_78 =
args . V_79 = args . V_80 = 0 ;
args . V_81 = 1 ;
args . V_82 = 1 ;
args . V_80 = F_1 ( & args ) - 1 ;
args . V_83 = args . V_1 -> V_84 - 1 ;
if ( ( error = F_35 ( & args ) ) )
return error ;
} else
args . V_73 = V_85 ;
if ( F_36 ( args . V_73 == V_85 ) ) {
V_61 = 0 ;
if ( args . V_1 -> V_86 ) {
ASSERT ( ! ( args . V_1 -> V_87 & V_88 ) ) ;
args . V_82 = args . V_1 -> V_89 ;
V_61 = 1 ;
} else
args . V_82 = F_1 ( & args ) ;
args . V_29 = F_13 ( V_19 -> V_90 ) ;
args . V_73 = F_34 ( args . V_1 , V_28 , args . V_29 ) ;
args . type = V_91 ;
args . V_75 = args . V_76 = args . V_77 = args . V_78 =
args . V_79 = args . V_80 = 0 ;
args . V_81 = 1 ;
args . V_83 = args . V_1 -> V_84 - 1 ;
if ( ( error = F_35 ( & args ) ) )
return error ;
}
if ( V_61 && args . V_73 == V_85 ) {
args . type = V_91 ;
args . V_29 = F_13 ( V_19 -> V_90 ) ;
args . V_73 = F_34 ( args . V_1 , V_28 , args . V_29 ) ;
args . V_82 = F_1 ( & args ) ;
if ( ( error = F_35 ( & args ) ) )
return error ;
}
if ( args . V_73 == V_85 ) {
* V_57 = 0 ;
return 0 ;
}
ASSERT ( args . V_92 == args . V_68 ) ;
error = F_18 ( args . V_1 , V_27 , V_28 , args . V_29 ,
args . V_92 , F_37 () ) ;
if ( error )
return error ;
V_58 = F_38 ( args . V_1 , args . V_29 , 0 ) ;
F_39 ( & V_19 -> V_93 , V_59 ) ;
F_39 ( & V_19 -> V_24 , V_59 ) ;
V_63 = F_40 ( args . V_1 , V_28 ) ;
V_63 -> V_94 += V_59 ;
F_41 ( V_63 ) ;
V_19 -> V_70 = F_8 ( V_58 ) ;
V_5 = F_42 ( args . V_1 , V_27 , V_56 , V_28 ) ;
for ( V_60 = V_58 ;
V_60 < V_58 + V_59 ;
V_60 += V_95 ) {
V_5 -> V_9 . V_10 . V_11 = V_60 ;
V_5 -> V_9 . V_10 . V_12 = V_95 ;
V_5 -> V_9 . V_10 . V_13 = V_96 ;
error = F_6 ( V_5 , V_97 , & V_10 ) ;
if ( error ) {
F_43 ( V_5 , V_98 ) ;
return error ;
}
ASSERT ( V_10 == 0 ) ;
error = F_44 ( V_5 , & V_10 ) ;
if ( error ) {
F_43 ( V_5 , V_98 ) ;
return error ;
}
ASSERT ( V_10 == 1 ) ;
}
F_43 ( V_5 , V_99 ) ;
F_45 ( V_27 , V_56 ,
V_100 | V_101 | V_102 ) ;
F_46 ( V_27 , V_103 , ( long ) V_59 ) ;
F_46 ( V_27 , V_104 , ( long ) V_59 ) ;
* V_57 = 1 ;
return 0 ;
}
STATIC T_5
F_47 (
T_13 * V_1 )
{
T_5 V_28 ;
F_48 ( & V_1 -> V_105 ) ;
V_28 = V_1 -> V_106 ;
if ( ++ V_1 -> V_106 == V_1 -> V_107 )
V_1 -> V_106 = 0 ;
F_49 ( & V_1 -> V_105 ) ;
return V_28 ;
}
STATIC T_10 *
F_50 (
T_9 * V_27 ,
T_14 V_108 ,
T_15 V_109 ,
int V_110 )
{
T_10 * V_56 ;
T_5 V_111 ;
T_5 V_28 ;
int V_112 ;
T_16 V_113 ;
T_16 V_114 = 0 ;
T_13 * V_1 ;
int V_115 ;
T_17 * V_63 ;
T_5 V_116 ;
V_115 = F_51 ( V_109 ) || F_52 ( V_109 ) || F_53 ( V_109 ) ;
V_1 = V_27 -> V_64 ;
V_111 = V_1 -> V_107 ;
if ( F_51 ( V_109 ) )
V_116 = F_47 ( V_1 ) ;
else {
V_116 = F_54 ( V_1 , V_108 ) ;
if ( V_116 >= V_111 )
V_116 = 0 ;
}
ASSERT ( V_116 < V_111 ) ;
V_28 = V_116 ;
V_112 = V_117 ;
for (; ; ) {
V_63 = F_40 ( V_1 , V_28 ) ;
if ( ! V_63 -> V_118 ) {
if ( F_55 ( V_1 , V_27 , V_28 , & V_56 ) ) {
V_56 = NULL ;
goto V_119;
}
} else
V_56 = NULL ;
if ( ! V_63 -> V_120 ) {
F_47 ( V_1 ) ;
goto V_121;
}
V_113 = V_63 -> V_94 ? 0 : F_30 ( V_1 ) ;
if ( V_113 && ! V_63 -> V_122 ) {
if ( V_56 == NULL &&
F_55 ( V_1 , V_27 , V_28 , & V_56 ) ) {
V_56 = NULL ;
goto V_119;
}
( void ) F_56 ( V_1 , V_27 , V_28 , V_112 ) ;
}
if ( ! V_113 || V_63 -> V_122 ) {
if ( V_113 && ! ( V_114 = V_63 -> V_123 ) )
V_114 = V_63 -> V_124 > 0 ;
if ( ! V_113 ||
( V_63 -> V_125 >= V_115 + V_113 &&
V_114 >= V_113 &&
V_110 ) ) {
if ( V_56 == NULL &&
F_55 ( V_1 , V_27 , V_28 , & V_56 ) ) {
V_56 = NULL ;
goto V_119;
}
F_41 ( V_63 ) ;
return V_56 ;
}
}
V_121:
if ( V_56 )
F_57 ( V_27 , V_56 ) ;
V_119:
F_41 ( V_63 ) ;
if ( F_17 ( V_1 ) )
return NULL ;
V_28 ++ ;
if ( V_28 >= V_111 )
V_28 = 0 ;
if ( V_28 == V_116 ) {
if ( V_112 == 0 )
return NULL ;
V_112 = 0 ;
}
}
}
STATIC int
F_58 (
struct V_4 * V_5 ,
T_4 * V_16 ,
int * V_126 ,
int V_127 )
{
int error ;
int V_10 ;
if ( V_127 )
error = F_59 ( V_5 , 0 , & V_10 ) ;
else
error = F_16 ( V_5 , 0 , & V_10 ) ;
if ( error )
return error ;
* V_126 = ! V_10 ;
if ( V_10 ) {
error = F_11 ( V_5 , V_16 , & V_10 ) ;
if ( error )
return error ;
F_60 ( V_10 == 1 ) ;
}
return 0 ;
}
STATIC int
F_61 (
struct V_4 * V_5 ,
T_2 V_128 ,
T_4 * V_16 ,
int * V_126 ,
int V_127 )
{
int error ;
int V_10 ;
error = F_5 ( V_5 , V_128 , V_97 , & V_10 ) ;
if ( error )
return error ;
* V_126 = ! V_10 ;
if ( V_10 ) {
error = F_11 ( V_5 , V_16 , & V_10 ) ;
if ( error )
return error ;
F_60 ( V_10 == 1 ) ;
}
return 0 ;
}
int
F_62 (
T_9 * V_27 ,
T_14 V_108 ,
T_15 V_109 ,
int V_110 ,
T_10 * * V_129 ,
T_18 * V_130 ,
T_14 * V_131 )
{
T_5 V_111 ;
T_10 * V_56 ;
T_5 V_28 ;
T_11 * V_19 ;
T_12 * V_5 ;
int error ;
int V_10 ;
int V_132 ;
int V_133 = 0 ;
T_14 V_6 ;
int V_39 ;
T_13 * V_1 ;
int V_134 ;
T_2 V_135 ;
T_5 V_116 ;
T_4 V_16 ;
T_5 V_136 ;
T_12 * V_137 ;
T_4 V_138 ;
struct V_62 * V_63 ;
if ( * V_129 == NULL ) {
V_56 = F_50 ( V_27 , V_108 , V_109 , V_110 ) ;
if ( ! V_56 ) {
* V_131 = V_139 ;
return 0 ;
}
V_19 = F_31 ( V_56 ) ;
ASSERT ( V_19 -> V_140 == F_8 ( V_141 ) ) ;
} else {
V_56 = * V_129 ;
V_19 = F_31 ( V_56 ) ;
ASSERT ( V_19 -> V_140 == F_8 ( V_141 ) ) ;
ASSERT ( F_13 ( V_19 -> V_24 ) > 0 ) ;
}
V_1 = V_27 -> V_64 ;
V_111 = V_1 -> V_2 . V_142 ;
V_28 = F_13 ( V_19 -> V_71 ) ;
V_136 = V_28 ;
V_116 = F_54 ( V_1 , V_108 ) ;
V_135 = F_63 ( V_1 , V_108 ) ;
if ( V_1 -> V_65 &&
V_1 -> V_2 . V_66 + F_28 ( V_1 ) > V_1 -> V_65 ) {
V_133 = 1 ;
V_110 = 0 ;
}
* V_130 = V_143 ;
while ( ! V_19 -> V_24 ) {
if ( V_110 ) {
if ( ( error = F_27 ( V_27 , V_56 , & V_132 ) ) ) {
F_57 ( V_27 , V_56 ) ;
if ( error == V_67 ) {
* V_131 = V_139 ;
return 0 ;
} else
return error ;
}
if ( V_132 ) {
ASSERT ( F_13 ( V_19 -> V_24 ) > 0 ) ;
* V_130 = V_144 ;
* V_129 = V_56 ;
* V_131 = V_139 ;
return 0 ;
}
}
F_57 ( V_27 , V_56 ) ;
V_119:
if ( ++ V_136 == V_111 )
V_136 = 0 ;
if ( V_136 == V_28 ) {
* V_131 = V_139 ;
return V_133 ? V_67 : 0 ;
}
V_63 = F_40 ( V_1 , V_136 ) ;
if ( V_63 -> V_120 == 0 ) {
F_41 ( V_63 ) ;
goto V_119;
}
error = F_55 ( V_1 , V_27 , V_136 , & V_56 ) ;
F_41 ( V_63 ) ;
if ( error )
goto V_119;
V_19 = F_31 ( V_56 ) ;
ASSERT ( V_19 -> V_140 == F_8 ( V_141 ) ) ;
}
V_28 = V_136 ;
* V_129 = NULL ;
V_63 = F_40 ( V_1 , V_28 ) ;
V_145:
V_5 = F_42 ( V_1 , V_27 , V_56 , F_13 ( V_19 -> V_71 ) ) ;
if ( ! V_135 )
V_135 = F_13 ( V_19 -> V_70 ) ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_146;
if ( V_116 == V_28 ) {
int V_147 ;
int V_148 ;
int V_149 = 10 ;
error = F_5 ( V_5 , V_135 , V_150 , & V_10 ) ;
if ( error )
goto V_146;
F_64 ( V_10 == 1 , V_146 ) ;
error = F_11 ( V_5 , & V_16 , & V_39 ) ;
if ( error )
goto V_146;
F_64 ( V_10 == 1 , V_146 ) ;
if ( V_16 . V_12 > 0 ) {
goto V_151;
}
error = F_65 ( V_5 , & V_137 ) ;
if ( error )
goto V_146;
if ( V_135 != V_55 &&
V_63 -> V_152 == V_135 &&
V_63 -> V_153 != V_55 &&
V_63 -> V_154 != V_55 ) {
error = F_61 ( V_137 , V_63 -> V_153 ,
& V_138 , & V_147 , 1 ) ;
if ( error )
goto V_155;
error = F_61 ( V_5 , V_63 -> V_154 ,
& V_16 , & V_148 , 0 ) ;
if ( error )
goto V_155;
} else {
error = F_58 ( V_137 , & V_138 , & V_147 , 1 ) ;
if ( error )
goto V_155;
error = F_58 ( V_5 , & V_16 , & V_148 , 0 ) ;
if ( error )
goto V_155;
}
while ( ! V_147 || ! V_148 ) {
int V_156 ;
if ( ! -- V_149 ) {
F_43 ( V_137 , V_99 ) ;
V_63 -> V_153 = V_138 . V_11 ;
V_63 -> V_154 = V_16 . V_11 ;
V_63 -> V_152 = V_135 ;
goto V_58;
}
if ( ! V_147 && ! V_148 ) {
V_156 = V_135 -
( V_138 . V_11 + V_95 - 1 ) <
V_16 . V_11 - V_135 ;
} else {
V_156 = ! V_147 ;
}
if ( V_156 && V_138 . V_12 ) {
V_16 = V_138 ;
F_43 ( V_5 , V_99 ) ;
V_5 = V_137 ;
V_63 -> V_153 = V_138 . V_11 ;
V_63 -> V_154 = V_16 . V_11 ;
V_63 -> V_152 = V_135 ;
goto V_151;
}
if ( ! V_156 && V_16 . V_12 ) {
F_43 ( V_137 , V_99 ) ;
V_63 -> V_153 = V_138 . V_11 ;
V_63 -> V_154 = V_16 . V_11 ;
V_63 -> V_152 = V_135 ;
goto V_151;
}
if ( V_156 ) {
error = F_58 ( V_137 , & V_138 ,
& V_147 , 1 ) ;
} else {
error = F_58 ( V_5 , & V_16 ,
& V_148 , 0 ) ;
}
if ( error )
goto V_155;
}
V_63 -> V_152 = V_55 ;
V_63 -> V_153 = V_55 ;
V_63 -> V_154 = V_55 ;
F_43 ( V_137 , V_99 ) ;
F_43 ( V_5 , V_99 ) ;
goto V_145;
}
V_58:
if ( V_19 -> V_70 != F_8 ( V_55 ) ) {
error = F_5 ( V_5 , F_13 ( V_19 -> V_70 ) ,
V_97 , & V_10 ) ;
if ( error )
goto V_146;
if ( V_10 == 1 ) {
error = F_11 ( V_5 , & V_16 , & V_39 ) ;
if ( error )
goto V_146;
if ( V_39 == 1 && V_16 . V_12 > 0 ) {
goto V_151;
}
}
}
error = F_5 ( V_5 , 0 , V_22 , & V_10 ) ;
if ( error )
goto V_146;
F_64 ( V_10 == 1 , V_146 ) ;
for (; ; ) {
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( error )
goto V_146;
F_64 ( V_10 == 1 , V_146 ) ;
if ( V_16 . V_12 > 0 )
break;
error = F_16 ( V_5 , 0 , & V_10 ) ;
if ( error )
goto V_146;
F_64 ( V_10 == 1 , V_146 ) ;
}
V_151:
V_134 = F_66 ( & V_16 . V_13 ) ;
ASSERT ( V_134 >= 0 ) ;
ASSERT ( V_134 < V_95 ) ;
ASSERT ( ( F_67 ( V_1 , V_16 . V_11 ) %
V_95 ) == 0 ) ;
V_6 = F_68 ( V_1 , V_28 , V_16 . V_11 + V_134 ) ;
V_16 . V_13 &= ~ F_69 ( V_134 ) ;
V_16 . V_12 -- ;
error = F_7 ( V_5 , & V_16 ) ;
if ( error )
goto V_146;
F_39 ( & V_19 -> V_24 , - 1 ) ;
F_45 ( V_27 , V_56 , V_101 ) ;
V_63 -> V_94 -- ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_146;
F_43 ( V_5 , V_99 ) ;
F_46 ( V_27 , V_104 , - 1 ) ;
F_41 ( V_63 ) ;
* V_131 = V_6 ;
return 0 ;
V_155:
F_43 ( V_137 , V_98 ) ;
V_146:
F_43 ( V_5 , V_98 ) ;
F_41 ( V_63 ) ;
return error ;
}
int
F_70 (
T_9 * V_27 ,
T_14 V_157 ,
T_19 * V_158 ,
int * V_159 ,
T_14 * V_160 )
{
T_6 V_29 ;
T_10 * V_56 ;
T_2 V_128 ;
T_5 V_28 ;
T_11 * V_19 ;
T_12 * V_5 ;
int error ;
int V_10 ;
int V_161 ;
T_13 * V_1 ;
int V_162 ;
T_4 V_16 ;
struct V_62 * V_63 ;
V_1 = V_27 -> V_64 ;
V_28 = F_54 ( V_1 , V_157 ) ;
if ( V_28 >= V_1 -> V_2 . V_142 ) {
F_71 ( V_1 , L_1 ,
V_163 , V_28 , V_1 -> V_2 . V_142 ) ;
ASSERT ( 0 ) ;
return F_29 ( V_164 ) ;
}
V_128 = F_63 ( V_1 , V_157 ) ;
if ( V_157 != F_68 ( V_1 , V_28 , V_128 ) ) {
F_71 ( V_1 , L_2 ,
V_163 , ( unsigned long long ) V_157 ,
( unsigned long long ) F_68 ( V_1 , V_28 , V_128 ) ) ;
ASSERT ( 0 ) ;
return F_29 ( V_164 ) ;
}
V_29 = F_32 ( V_1 , V_128 ) ;
if ( V_29 >= V_1 -> V_2 . V_165 ) {
F_71 ( V_1 , L_3 ,
V_163 , V_29 , V_1 -> V_2 . V_165 ) ;
ASSERT ( 0 ) ;
return F_29 ( V_164 ) ;
}
error = F_55 ( V_1 , V_27 , V_28 , & V_56 ) ;
if ( error ) {
F_71 ( V_1 , L_4 ,
V_163 , error ) ;
return error ;
}
V_19 = F_31 ( V_56 ) ;
ASSERT ( V_19 -> V_140 == F_8 ( V_141 ) ) ;
ASSERT ( V_29 < F_13 ( V_19 -> V_72 ) ) ;
V_5 = F_42 ( V_1 , V_27 , V_56 , V_28 ) ;
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_146;
if ( ( error = F_5 ( V_5 , V_128 , V_150 , & V_10 ) ) ) {
F_71 ( V_1 , L_5 ,
V_163 , error ) ;
goto V_146;
}
F_64 ( V_10 == 1 , V_146 ) ;
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( error ) {
F_71 ( V_1 , L_6 ,
V_163 , error ) ;
goto V_146;
}
F_64 ( V_10 == 1 , V_146 ) ;
V_162 = V_128 - V_16 . V_11 ;
ASSERT ( V_162 >= 0 && V_162 < V_95 ) ;
ASSERT ( ! ( V_16 . V_13 & F_69 ( V_162 ) ) ) ;
V_16 . V_13 |= F_69 ( V_162 ) ;
V_16 . V_12 ++ ;
if ( ! ( V_1 -> V_87 & V_166 ) &&
( V_16 . V_12 == F_28 ( V_1 ) ) ) {
* V_159 = 1 ;
* V_160 = F_68 ( V_1 , V_28 , V_16 . V_11 ) ;
V_161 = F_28 ( V_1 ) ;
F_39 ( & V_19 -> V_93 , - V_161 ) ;
F_39 ( & V_19 -> V_24 , - ( V_161 - 1 ) ) ;
F_45 ( V_27 , V_56 , V_100 | V_101 ) ;
V_63 = F_40 ( V_1 , V_28 ) ;
V_63 -> V_94 -= V_161 - 1 ;
F_41 ( V_63 ) ;
F_46 ( V_27 , V_103 , - V_161 ) ;
F_46 ( V_27 , V_104 , - ( V_161 - 1 ) ) ;
if ( ( error = F_72 ( V_5 , & V_10 ) ) ) {
F_71 ( V_1 , L_7 ,
V_163 , error ) ;
goto V_146;
}
F_73 ( F_34 ( V_1 ,
V_28 , F_74 ( V_1 , V_16 . V_11 ) ) ,
F_30 ( V_1 ) , V_158 , V_1 ) ;
} else {
* V_159 = 0 ;
error = F_7 ( V_5 , & V_16 ) ;
if ( error ) {
F_71 ( V_1 , L_8 ,
V_163 , error ) ;
goto V_146;
}
F_39 ( & V_19 -> V_24 , 1 ) ;
F_45 ( V_27 , V_56 , V_101 ) ;
V_63 = F_40 ( V_1 , V_28 ) ;
V_63 -> V_94 ++ ;
F_41 ( V_63 ) ;
F_46 ( V_27 , V_104 , 1 ) ;
}
error = F_15 ( V_5 , V_19 ) ;
if ( error )
goto V_146;
F_43 ( V_5 , V_99 ) ;
return 0 ;
V_146:
F_43 ( V_5 , V_98 ) ;
return error ;
}
STATIC int
F_75 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
T_2 V_128 ,
T_6 V_29 ,
T_6 * V_167 ,
T_6 * V_168 ,
int V_112 )
{
struct V_169 V_16 ;
struct V_4 * V_5 ;
struct V_32 * V_56 ;
int error ;
int V_10 ;
error = F_55 ( V_1 , V_27 , V_28 , & V_56 ) ;
if ( error ) {
F_76 ( V_1 ,
L_9 ,
V_163 , error , V_28 ) ;
return error ;
}
V_5 = F_42 ( V_1 , V_27 , V_56 , V_28 ) ;
error = F_5 ( V_5 , V_128 , V_150 , & V_10 ) ;
if ( ! error ) {
if ( V_10 )
error = F_11 ( V_5 , & V_16 , & V_10 ) ;
if ( ! error && V_10 == 0 )
error = V_164 ;
}
F_57 ( V_27 , V_56 ) ;
F_43 ( V_5 , V_99 ) ;
if ( error )
return error ;
if ( V_16 . V_11 > V_128 ||
V_16 . V_11 + F_28 ( V_1 ) <= V_128 )
return V_164 ;
if ( ( V_112 & V_170 ) &&
( V_16 . V_13 & F_69 ( V_128 - V_16 . V_11 ) ) )
return V_164 ;
* V_167 = F_32 ( V_1 , V_16 . V_11 ) ;
* V_168 = V_29 - * V_167 ;
return 0 ;
}
int
F_77 (
T_13 * V_1 ,
T_9 * V_27 ,
T_14 V_6 ,
struct F_77 * V_171 ,
T_8 V_112 )
{
T_6 V_29 ;
T_2 V_128 ;
T_5 V_28 ;
int V_35 ;
T_6 V_167 ;
T_6 V_172 ;
int error ;
int V_134 ;
int V_168 ;
ASSERT ( V_6 != V_139 ) ;
V_28 = F_54 ( V_1 , V_6 ) ;
V_128 = F_63 ( V_1 , V_6 ) ;
V_29 = F_32 ( V_1 , V_128 ) ;
if ( V_28 >= V_1 -> V_2 . V_142 || V_29 >= V_1 -> V_2 . V_165 ||
V_6 != F_68 ( V_1 , V_28 , V_128 ) ) {
#ifdef F_78
if ( V_112 & V_170 )
return F_29 ( V_164 ) ;
if ( V_28 >= V_1 -> V_2 . V_142 ) {
F_76 ( V_1 ,
L_10 ,
V_163 , V_28 , V_1 -> V_2 . V_142 ) ;
}
if ( V_29 >= V_1 -> V_2 . V_165 ) {
F_76 ( V_1 ,
L_11 ,
V_163 , ( unsigned long long ) V_29 ,
( unsigned long ) V_1 -> V_2 . V_165 ) ;
}
if ( V_6 != F_68 ( V_1 , V_28 , V_128 ) ) {
F_76 ( V_1 ,
L_12 ,
V_163 , V_6 ,
F_68 ( V_1 , V_28 , V_128 ) ) ;
}
F_79 () ;
#endif
return F_29 ( V_164 ) ;
}
V_35 = F_4 ( V_1 ) >> V_1 -> V_2 . V_173 ;
if ( V_112 & V_170 ) {
error = F_75 ( V_1 , V_27 , V_28 , V_128 , V_29 ,
& V_167 , & V_168 , V_112 ) ;
if ( error )
return error ;
goto V_174;
}
if ( F_4 ( V_1 ) <= V_1 -> V_2 . V_41 ) {
V_134 = F_80 ( V_1 , V_6 ) ;
ASSERT ( V_134 < V_1 -> V_2 . V_42 ) ;
V_171 -> V_175 = F_20 ( V_1 , V_28 , V_29 ) ;
V_171 -> V_176 = F_81 ( V_1 , 1 ) ;
V_171 -> V_177 = ( V_178 ) ( V_134 << V_1 -> V_2 . V_47 ) ;
return 0 ;
}
if ( V_1 -> V_179 ) {
V_168 = V_29 & V_1 -> V_179 ;
V_167 = V_29 - V_168 ;
} else {
error = F_75 ( V_1 , V_27 , V_28 , V_128 , V_29 ,
& V_167 , & V_168 , V_112 ) ;
if ( error )
return error ;
}
V_174:
ASSERT ( V_29 >= V_167 ) ;
V_172 = V_167 +
( ( V_168 / V_35 ) * V_35 ) ;
V_134 = ( ( V_29 - V_172 ) * V_1 -> V_2 . V_42 ) +
F_80 ( V_1 , V_6 ) ;
V_171 -> V_175 = F_20 ( V_1 , V_28 , V_172 ) ;
V_171 -> V_176 = F_81 ( V_1 , V_35 ) ;
V_171 -> V_177 = ( V_178 ) ( V_134 << V_1 -> V_2 . V_47 ) ;
if ( ( V_171 -> V_175 + V_171 -> V_176 ) >
F_81 ( V_1 , V_1 -> V_2 . V_180 ) ) {
F_76 ( V_1 ,
L_13 ,
V_163 , ( unsigned long long ) V_171 -> V_175 ,
( unsigned long long ) V_171 -> V_176 ,
F_81 ( V_1 , V_1 -> V_2 . V_180 ) ) ;
return F_29 ( V_164 ) ;
}
return 0 ;
}
void
F_82 (
T_13 * V_1 )
{
int V_181 ;
T_8 V_182 ;
T_8 V_183 ;
int V_184 ;
int V_185 ;
V_183 = ( 1LL << F_83 ( V_1 ) ) >>
V_186 ;
V_184 = V_1 -> V_187 [ 0 ] ;
V_185 = V_1 -> V_187 [ 1 ] ;
V_182 = ( V_183 + V_184 - 1 ) / V_184 ;
for ( V_181 = 1 ; V_182 > 1 ; V_181 ++ )
V_182 = ( V_182 + V_185 - 1 ) / V_185 ;
V_1 -> V_84 = V_181 ;
}
void
F_45 (
T_9 * V_27 ,
T_10 * V_188 ,
int V_189 )
{
int V_190 ;
int V_191 ;
static const short V_192 [] = {
F_84 ( T_11 , V_140 ) ,
F_84 ( T_11 , V_193 ) ,
F_84 ( T_11 , V_71 ) ,
F_84 ( T_11 , V_72 ) ,
F_84 ( T_11 , V_93 ) ,
F_84 ( T_11 , V_90 ) ,
F_84 ( T_11 , V_194 ) ,
F_84 ( T_11 , V_24 ) ,
F_84 ( T_11 , V_70 ) ,
F_84 ( T_11 , V_195 ) ,
F_84 ( T_11 , V_196 ) ,
sizeof( T_11 )
} ;
#ifdef F_78
T_11 * V_19 ;
V_19 = F_31 ( V_188 ) ;
ASSERT ( V_19 -> V_140 == F_8 ( V_141 ) ) ;
#endif
F_85 ( V_189 , V_192 , V_197 , & V_190 , & V_191 ) ;
F_25 ( V_27 , V_188 , V_190 , V_191 ) ;
}
STATIC void
F_86 (
struct V_18 * V_19 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_198 ; V_10 ++ )
ASSERT ( V_19 -> V_196 [ V_10 ] ) ;
}
int
F_87 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
struct V_32 * * V_199 )
{
struct V_18 * V_19 ;
int V_200 ;
int error ;
ASSERT ( V_28 != V_201 ) ;
error = F_88 ( V_1 , V_27 , V_1 -> V_43 ,
F_89 ( V_1 , V_28 , F_90 ( V_1 ) ) ,
F_91 ( V_1 , 1 ) , 0 , V_199 ) ;
if ( error )
return error ;
ASSERT ( ! F_92 ( * V_199 ) ) ;
V_19 = F_31 ( * V_199 ) ;
V_200 = V_19 -> V_140 == F_8 ( V_141 ) &&
F_93 ( F_13 ( V_19 -> V_193 ) ) &&
F_13 ( V_19 -> V_71 ) == V_28 ;
if ( F_36 ( F_94 ( ! V_200 , V_1 , V_202 ,
V_203 ) ) ) {
F_95 ( L_14 , V_204 ,
V_1 , V_19 ) ;
F_57 ( V_27 , * V_199 ) ;
return F_29 ( V_205 ) ;
}
F_96 ( * V_199 , V_206 ) ;
F_86 ( V_19 ) ;
return 0 ;
}
int
F_55 (
struct V_25 * V_1 ,
struct V_26 * V_27 ,
T_5 V_28 ,
struct V_32 * * V_199 )
{
struct V_18 * V_19 ;
struct V_62 * V_63 ;
int error ;
error = F_87 ( V_1 , V_27 , V_28 , V_199 ) ;
if ( error )
return error ;
V_19 = F_31 ( * V_199 ) ;
V_63 = F_40 ( V_1 , V_28 ) ;
if ( ! V_63 -> V_118 ) {
V_63 -> V_94 = F_13 ( V_19 -> V_24 ) ;
V_63 -> V_207 = F_13 ( V_19 -> V_93 ) ;
V_63 -> V_118 = 1 ;
}
ASSERT ( V_63 -> V_94 == F_13 ( V_19 -> V_24 ) ||
F_17 ( V_1 ) ) ;
F_41 ( V_63 ) ;
return 0 ;
}
int
F_97 (
T_13 * V_1 ,
T_9 * V_27 ,
T_5 V_28 )
{
T_10 * V_188 = NULL ;
int error ;
error = F_55 ( V_1 , V_27 , V_28 , & V_188 ) ;
if ( error )
return error ;
if ( V_188 )
F_57 ( V_27 , V_188 ) ;
return 0 ;
}
