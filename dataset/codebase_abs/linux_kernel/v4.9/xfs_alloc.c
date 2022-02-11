unsigned int
F_1 (
struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) )
return F_3 ( V_2 ) + 1 ;
if ( F_4 ( & V_2 -> V_3 ) )
return F_5 ( V_2 ) + 1 ;
return F_6 ( V_2 ) + 1 ;
}
T_1
F_7 (
struct V_1 * V_2 )
{
if ( F_8 ( & V_2 -> V_3 ) )
return F_1 ( V_2 ) + 1 ;
if ( F_2 ( & V_2 -> V_3 ) )
return F_3 ( V_2 ) + 1 ;
if ( F_4 ( & V_2 -> V_3 ) )
return F_5 ( V_2 ) + 1 ;
return F_6 ( V_2 ) + 1 ;
}
unsigned int
F_9 (
struct V_1 * V_2 )
{
unsigned int V_4 ;
V_4 = 4 + ( V_2 -> V_3 . V_5 * V_6 ) ;
return V_4 ;
}
unsigned int
F_10 (
struct V_1 * V_2 )
{
unsigned int V_4 ;
V_4 = F_11 ( V_2 , F_12 ( V_2 , 4 ) ) ;
V_4 += V_6 ;
V_4 += 3 ;
if ( F_4 ( & V_2 -> V_3 ) )
V_4 ++ ;
if ( F_2 ( & V_2 -> V_3 ) )
V_4 ++ ;
if ( F_8 ( & V_2 -> V_3 ) )
V_4 ++ ;
return V_2 -> V_3 . V_7 - V_4 ;
}
STATIC int
F_13 (
struct V_8 * V_9 ,
T_2 V_10 ,
T_1 V_11 ,
int * V_12 )
{
V_9 -> V_13 . V_14 . V_15 = V_10 ;
V_9 -> V_13 . V_14 . V_16 = V_11 ;
return F_14 ( V_9 , V_17 , V_12 ) ;
}
int
F_15 (
struct V_8 * V_9 ,
T_2 V_10 ,
T_1 V_11 ,
int * V_12 )
{
V_9 -> V_13 . V_14 . V_15 = V_10 ;
V_9 -> V_13 . V_14 . V_16 = V_11 ;
return F_14 ( V_9 , V_18 , V_12 ) ;
}
static int
F_16 (
struct V_8 * V_9 ,
T_2 V_10 ,
T_1 V_11 ,
int * V_12 )
{
V_9 -> V_13 . V_14 . V_15 = V_10 ;
V_9 -> V_13 . V_14 . V_16 = V_11 ;
return F_14 ( V_9 , V_19 , V_12 ) ;
}
STATIC int
F_17 (
struct V_8 * V_9 ,
T_2 V_10 ,
T_1 V_11 )
{
union V_20 V_21 ;
V_21 . V_22 . V_15 = F_18 ( V_10 ) ;
V_21 . V_22 . V_16 = F_18 ( V_11 ) ;
return F_19 ( V_9 , & V_21 ) ;
}
int
F_20 (
struct V_8 * V_9 ,
T_2 * V_10 ,
T_1 * V_11 ,
int * V_12 )
{
union V_20 * V_21 ;
int error ;
error = F_21 ( V_9 , & V_21 , V_12 ) ;
if ( ! error && * V_12 == 1 ) {
* V_10 = F_22 ( V_21 -> V_22 . V_15 ) ;
* V_11 = F_22 ( V_21 -> V_22 . V_16 ) ;
}
return error ;
}
STATIC void
F_23 (
T_3 * args ,
T_2 V_23 ,
T_1 V_24 ,
T_2 * V_25 ,
T_1 * V_26 )
{
T_2 V_10 ;
T_1 V_11 ;
T_1 V_27 ;
F_24 ( args , V_23 , V_24 , & V_10 , & V_11 ) ;
if ( V_10 < args -> V_28 && V_10 + V_11 > args -> V_28 ) {
V_27 = args -> V_28 - V_10 ;
if ( V_11 > V_27 ) {
V_10 += V_27 ;
V_11 -= V_27 ;
}
}
if ( args -> V_29 > 1 && V_11 >= args -> V_30 ) {
T_2 V_31 = F_25 ( V_10 , args -> V_29 ) ;
V_27 = V_31 - V_10 ;
* V_25 = V_31 ;
* V_26 = V_27 >= V_11 ? 0 : V_11 - V_27 ;
} else {
* V_25 = V_10 ;
* V_26 = V_11 ;
}
}
STATIC T_1
F_26 (
T_2 V_32 ,
T_1 V_33 ,
T_1 V_29 ,
int V_34 ,
T_2 V_35 ,
T_1 V_36 ,
T_2 * V_37 )
{
T_2 V_38 ;
T_2 V_39 ;
T_2 V_40 ;
T_1 V_41 = 0 ;
T_1 V_42 = 0 ;
T_2 V_43 ;
bool V_44 = F_27 ( V_34 ) ;
ASSERT ( V_36 >= V_33 ) ;
V_38 = V_35 + V_36 ;
V_43 = V_32 + V_33 ;
if ( V_35 >= V_32 || ( V_44 && V_38 < V_43 ) ) {
if ( ( V_39 = F_25 ( V_35 , V_29 ) ) >= V_38 )
V_39 = V_45 ;
} else if ( V_38 >= V_43 && V_29 > 1 ) {
V_39 = F_25 ( V_32 , V_29 ) ;
V_40 = V_39 - V_29 ;
if ( V_39 >= V_38 )
V_39 = V_45 ;
else
V_41 = F_28 ( V_33 , V_38 - V_39 ) ;
if ( V_40 < V_35 )
V_40 = V_45 ;
else
V_42 = F_28 ( V_33 , V_38 - V_40 ) ;
if ( V_39 != V_45 && V_40 != V_45 ) {
if ( V_41 < V_42 ||
( V_41 == V_42 &&
F_29 ( V_39 , V_32 ) >
F_29 ( V_40 , V_32 ) ) )
V_39 = V_40 ;
} else if ( V_40 != V_45 )
V_39 = V_40 ;
} else if ( V_38 >= V_43 ) {
V_39 = V_32 ;
} else if ( V_29 > 1 ) {
V_39 = F_25 ( V_38 - V_33 , V_29 ) ;
if ( V_39 > V_38 - V_33 &&
V_39 - V_29 >= V_35 )
V_39 -= V_29 ;
else if ( V_39 >= V_38 )
V_39 = V_45 ;
} else
V_39 = V_38 - V_33 ;
* V_37 = V_39 ;
return V_39 == V_45 ? 0 : F_29 ( V_39 , V_32 ) ;
}
STATIC void
F_30 (
T_3 * args )
{
T_1 V_46 ;
T_1 V_47 ;
ASSERT ( args -> V_48 < args -> V_49 ) ;
V_47 = args -> V_11 ;
ASSERT ( V_47 >= args -> V_30 ) ;
ASSERT ( V_47 <= args -> V_50 ) ;
if ( args -> V_49 <= 1 || V_47 < args -> V_48 || V_47 == args -> V_50 ||
( args -> V_48 == 0 && V_47 < args -> V_49 ) )
return;
V_46 = V_47 % args -> V_49 ;
if ( V_46 == args -> V_48 )
return;
if ( V_46 > args -> V_48 )
V_47 = V_47 - ( V_46 - args -> V_48 ) ;
else
V_47 = V_47 - args -> V_49 + ( args -> V_48 - V_46 ) ;
if ( ( int ) V_47 < ( int ) args -> V_30 )
return;
ASSERT ( V_47 >= args -> V_30 && V_47 <= args -> V_50 ) ;
ASSERT ( V_47 % args -> V_49 == args -> V_48 ) ;
args -> V_11 = V_47 ;
}
STATIC int
F_31 (
T_3 * args )
{
T_4 * V_51 ;
int V_27 ;
if ( args -> V_52 == 0 )
return 1 ;
V_51 = F_32 ( args -> V_53 ) ;
V_27 = F_22 ( V_51 -> V_54 )
- args -> V_11 - args -> V_52 ;
if ( V_27 >= 0 )
return 1 ;
args -> V_11 += V_27 ;
if ( ( int ) args -> V_11 >= ( int ) args -> V_30 )
return 1 ;
args -> V_55 = V_45 ;
return 0 ;
}
STATIC int
F_33 (
T_5 * V_56 ,
T_5 * V_57 ,
T_2 V_58 ,
T_1 V_59 ,
T_2 V_60 ,
T_1 V_47 ,
int V_61 )
{
int error ;
int V_62 ;
T_2 V_63 ;
T_2 V_64 ;
T_1 V_65 = 0 ;
T_1 V_66 = 0 ;
struct V_1 * V_2 ;
V_2 = V_56 -> V_67 ;
if ( V_61 & V_68 ) {
#ifdef F_34
if ( ( error = F_20 ( V_56 , & V_63 , & V_65 , & V_62 ) ) )
return error ;
F_35 ( V_2 ,
V_62 == 1 && V_63 == V_58 && V_65 == V_59 ) ;
#endif
} else {
if ( ( error = F_13 ( V_56 , V_58 , V_59 , & V_62 ) ) )
return error ;
F_35 ( V_2 , V_62 == 1 ) ;
}
if ( V_61 & V_69 ) {
#ifdef F_34
if ( ( error = F_20 ( V_57 , & V_63 , & V_65 , & V_62 ) ) )
return error ;
F_35 ( V_2 ,
V_62 == 1 && V_63 == V_58 && V_65 == V_59 ) ;
#endif
} else {
if ( ( error = F_13 ( V_57 , V_58 , V_59 , & V_62 ) ) )
return error ;
F_35 ( V_2 , V_62 == 1 ) ;
}
#ifdef F_34
if ( V_57 -> V_70 == 1 && V_56 -> V_70 == 1 ) {
struct V_71 * V_72 ;
struct V_71 * V_73 ;
V_72 = F_36 ( V_57 -> V_74 [ 0 ] ) ;
V_73 = F_36 ( V_56 -> V_74 [ 0 ] ) ;
F_35 ( V_2 ,
V_72 -> V_75 == V_73 -> V_75 ) ;
}
#endif
if ( V_60 == V_58 && V_47 == V_59 )
V_63 = V_64 = V_45 ;
else if ( V_60 == V_58 ) {
V_63 = V_60 + V_47 ;
V_65 = V_59 - V_47 ;
V_64 = V_45 ;
} else if ( V_60 + V_47 == V_58 + V_59 ) {
V_63 = V_58 ;
V_65 = V_59 - V_47 ;
V_64 = V_45 ;
} else {
V_63 = V_58 ;
V_65 = V_60 - V_58 ;
V_64 = V_60 + V_47 ;
V_66 = ( V_58 + V_59 ) - V_64 ;
}
if ( ( error = F_37 ( V_56 , & V_62 ) ) )
return error ;
F_35 ( V_2 , V_62 == 1 ) ;
if ( V_63 != V_45 ) {
if ( ( error = F_13 ( V_56 , V_63 , V_65 , & V_62 ) ) )
return error ;
F_35 ( V_2 , V_62 == 0 ) ;
if ( ( error = F_38 ( V_56 , & V_62 ) ) )
return error ;
F_35 ( V_2 , V_62 == 1 ) ;
}
if ( V_64 != V_45 ) {
if ( ( error = F_13 ( V_56 , V_64 , V_66 , & V_62 ) ) )
return error ;
F_35 ( V_2 , V_62 == 0 ) ;
if ( ( error = F_38 ( V_56 , & V_62 ) ) )
return error ;
F_35 ( V_2 , V_62 == 1 ) ;
}
if ( V_63 == V_45 ) {
if ( ( error = F_37 ( V_57 , & V_62 ) ) )
return error ;
F_35 ( V_2 , V_62 == 1 ) ;
} else {
if ( ( error = F_17 ( V_57 , V_63 , V_65 ) ) )
return error ;
}
if ( V_64 != V_45 ) {
if ( ( error = F_13 ( V_57 , V_64 , V_66 , & V_62 ) ) )
return error ;
F_35 ( V_2 , V_62 == 0 ) ;
if ( ( error = F_38 ( V_57 , & V_62 ) ) )
return error ;
F_35 ( V_2 , V_62 == 1 ) ;
}
return 0 ;
}
static bool
F_39 (
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_78 -> V_79 ;
struct V_80 * V_81 = F_40 ( V_77 ) ;
int V_62 ;
if ( ! F_41 ( & V_81 -> V_82 , & V_2 -> V_3 . V_83 ) )
return false ;
if ( F_22 ( V_81 -> V_84 ) != V_85 )
return false ;
if ( V_77 -> V_86 && F_22 ( V_81 -> V_87 ) != V_77 -> V_86 -> V_88 )
return false ;
for ( V_62 = 0 ; V_62 < F_42 ( V_2 ) ; V_62 ++ ) {
if ( F_22 ( V_81 -> V_89 [ V_62 ] ) != V_45 &&
F_22 ( V_81 -> V_89 [ V_62 ] ) >= V_2 -> V_3 . V_7 )
return false ;
}
return F_43 ( V_2 ,
F_44 ( F_40 ( V_77 ) -> V_90 ) ) ;
}
static void
F_45 (
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_78 -> V_79 ;
if ( ! F_46 ( & V_2 -> V_3 ) )
return;
if ( ! F_47 ( V_77 , V_91 ) )
F_48 ( V_77 , - V_92 ) ;
else if ( ! F_39 ( V_77 ) )
F_48 ( V_77 , - V_93 ) ;
if ( V_77 -> V_94 )
F_49 ( V_77 ) ;
}
static void
F_50 (
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_78 -> V_79 ;
struct V_95 * V_96 = V_77 -> V_97 ;
if ( ! F_46 ( & V_2 -> V_3 ) )
return;
if ( ! F_39 ( V_77 ) ) {
F_48 ( V_77 , - V_93 ) ;
F_49 ( V_77 ) ;
return;
}
if ( V_96 )
F_40 ( V_77 ) -> V_90 = F_51 ( V_96 -> V_98 . V_99 ) ;
F_52 ( V_77 , V_91 ) ;
}
STATIC int
F_53 (
T_6 * V_2 ,
T_7 * V_100 ,
T_8 V_101 ,
T_9 * * V_102 )
{
T_9 * V_77 ;
int error ;
ASSERT ( V_101 != V_103 ) ;
error = F_54 (
V_2 , V_100 , V_2 -> V_104 ,
F_55 ( V_2 , V_101 , F_56 ( V_2 ) ) ,
F_12 ( V_2 , 1 ) , 0 , & V_77 , & V_105 ) ;
if ( error )
return error ;
F_57 ( V_77 , V_106 ) ;
* V_102 = V_77 ;
return 0 ;
}
STATIC int
F_58 (
struct V_107 * V_100 ,
struct V_108 * V_109 ,
struct V_76 * V_53 ,
long V_11 )
{
struct V_110 * V_51 = F_32 ( V_53 ) ;
V_109 -> V_111 += V_11 ;
F_59 ( & V_51 -> V_54 , V_11 ) ;
F_60 ( V_100 , V_11 ) ;
if ( F_61 ( F_22 ( V_51 -> V_54 ) >
F_22 ( V_51 -> V_112 ) ) )
return - V_93 ;
F_62 ( V_100 , V_53 , V_113 ) ;
return 0 ;
}
STATIC int
F_63 (
T_3 * args )
{
int error = 0 ;
T_1 V_114 ;
T_1 V_115 ;
ASSERT ( args -> V_30 > 0 ) ;
ASSERT ( args -> V_50 > 0 ) ;
ASSERT ( args -> V_30 <= args -> V_50 ) ;
ASSERT ( args -> V_48 < args -> V_49 ) ;
ASSERT ( args -> V_29 > 0 ) ;
V_115 = args -> V_50 ;
V_114 = F_64 ( args -> V_109 , args -> V_116 ) ;
if ( args -> V_50 > args -> V_109 -> V_111 - V_114 )
args -> V_50 = args -> V_109 -> V_111 - V_114 ;
if ( args -> V_50 == 0 ) {
args -> V_55 = V_45 ;
args -> V_50 = V_115 ;
return 0 ;
}
args -> V_117 = 0 ;
switch ( args -> type ) {
case V_118 :
error = F_65 ( args ) ;
break;
case V_119 :
error = F_66 ( args ) ;
break;
case V_120 :
error = F_67 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
args -> V_50 = V_115 ;
if ( error || args -> V_55 == V_45 )
return error ;
ASSERT ( args -> V_11 >= args -> V_30 ) ;
ASSERT ( args -> V_11 <= args -> V_50 ) ;
ASSERT ( ! args -> V_117 || args -> V_116 != V_121 ) ;
ASSERT ( args -> V_55 % args -> V_29 == 0 ) ;
if ( args -> V_122 . V_123 != V_124 ) {
error = F_68 ( args -> V_100 , args -> V_53 , args -> V_101 ,
args -> V_55 , args -> V_11 , & args -> V_122 ) ;
if ( error )
return error ;
}
if ( ! args -> V_117 ) {
error = F_58 ( args -> V_100 , args -> V_109 ,
args -> V_53 ,
- ( ( long ) ( args -> V_11 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_69 ( args -> V_2 , args -> V_101 ,
args -> V_55 , args -> V_11 ) ) ;
}
F_70 ( args -> V_109 , args -> V_116 , args ) ;
F_71 ( args -> V_2 , V_125 ) ;
F_72 ( args -> V_2 , V_126 , args -> V_11 ) ;
return error ;
}
STATIC int
F_67 (
T_3 * args )
{
T_5 * V_57 ;
T_5 * V_56 ;
int error ;
T_2 V_58 ;
T_1 V_59 ;
T_2 V_127 ;
T_1 V_128 ;
T_2 V_129 ;
int V_62 ;
ASSERT ( args -> V_29 == 1 ) ;
V_57 = F_73 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_130 ) ;
error = F_16 ( V_57 , args -> V_55 , args -> V_30 , & V_62 ) ;
if ( error )
goto V_131;
if ( ! V_62 )
goto V_132;
error = F_20 ( V_57 , & V_58 , & V_59 , & V_62 ) ;
if ( error )
goto V_131;
F_74 ( args -> V_2 , V_62 == 1 , V_131 ) ;
ASSERT ( V_58 <= args -> V_55 ) ;
F_24 ( args , V_58 , V_59 , & V_127 , & V_128 ) ;
if ( V_127 > args -> V_55 )
goto V_132;
if ( V_128 < args -> V_30 )
goto V_132;
V_129 = V_127 + V_128 ;
if ( V_129 < args -> V_55 + args -> V_30 )
goto V_132;
args -> V_11 = F_75 ( V_129 , args -> V_55 + args -> V_50 )
- args -> V_55 ;
F_30 ( args ) ;
if ( ! F_31 ( args ) )
goto V_132;
ASSERT ( args -> V_55 + args -> V_11 <= V_129 ) ;
V_56 = F_73 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_133 ) ;
ASSERT ( args -> V_55 + args -> V_11 <=
F_22 ( F_32 ( args -> V_53 ) -> V_112 ) ) ;
error = F_33 ( V_56 , V_57 , V_58 , V_59 , args -> V_55 ,
args -> V_11 , V_69 ) ;
if ( error ) {
F_76 ( V_56 , V_134 ) ;
goto V_131;
}
F_76 ( V_57 , V_135 ) ;
F_76 ( V_56 , V_135 ) ;
args -> V_117 = 0 ;
F_77 ( args ) ;
return 0 ;
V_132:
F_76 ( V_57 , V_135 ) ;
args -> V_55 = V_45 ;
F_78 ( args ) ;
return 0 ;
V_131:
F_76 ( V_57 , V_134 ) ;
F_79 ( args ) ;
return error ;
}
STATIC int
F_80 (
struct V_136 * args ,
struct V_8 * * V_137 ,
struct V_8 * * V_138 ,
T_2 V_139 ,
T_2 * V_140 ,
T_1 * V_141 ,
T_2 * V_142 ,
T_1 * V_143 ,
int V_144 )
{
T_2 V_145 ;
T_2 V_146 ;
int error ;
int V_62 ;
if ( ! V_139 )
goto V_147;
do {
error = F_20 ( * V_138 , V_140 , V_141 , & V_62 ) ;
if ( error )
goto V_131;
F_74 ( args -> V_2 , V_62 == 1 , V_131 ) ;
F_23 ( args , * V_140 , * V_141 , V_142 , V_143 ) ;
if ( ! V_144 ) {
if ( * V_142 > args -> V_148 )
goto V_147;
if ( * V_142 >= args -> V_55 + V_139 )
goto V_147;
} else {
if ( * V_142 < args -> V_28 )
goto V_147;
if ( * V_142 <= args -> V_55 - V_139 )
goto V_147;
}
if ( * V_143 >= args -> V_30 ) {
args -> V_11 = F_28 ( * V_143 , args -> V_50 ) ;
F_30 ( args ) ;
V_146 = F_26 ( args -> V_55 , args -> V_11 ,
args -> V_29 ,
args -> V_34 , * V_142 ,
* V_143 , & V_145 ) ;
if ( V_146 < V_139 )
goto V_149;
goto V_147;
}
if ( ! V_144 )
error = F_81 ( * V_138 , 0 , & V_62 ) ;
else
error = F_82 ( * V_138 , 0 , & V_62 ) ;
if ( error )
goto V_131;
} while ( V_62 );
V_147:
F_76 ( * V_138 , V_135 ) ;
* V_138 = NULL ;
return 0 ;
V_149:
F_76 ( * V_137 , V_135 ) ;
* V_137 = NULL ;
return 0 ;
V_131:
return error ;
}
STATIC int
F_66 (
T_3 * args )
{
T_5 * V_150 ;
T_5 * V_151 ;
T_5 * V_56 ;
T_2 V_152 ;
T_2 V_153 ;
T_1 V_154 ;
T_1 V_155 ;
T_1 V_156 ;
T_2 V_157 ;
int error ;
int V_62 ;
int V_158 ;
T_2 V_159 ;
T_2 V_160 ;
T_1 V_161 ;
T_1 V_162 ;
T_1 V_163 ;
T_2 V_164 ;
T_1 V_47 ;
int V_165 = 0 ;
#ifdef F_34
int V_166 ;
V_166 = F_83 () & 1 ;
#endif
if ( ! args -> V_28 && ! args -> V_148 )
args -> V_148 = args -> V_2 -> V_3 . V_7 - 1 ;
ASSERT ( args -> V_28 <= args -> V_148 ) ;
if ( args -> V_55 < args -> V_28 )
args -> V_55 = args -> V_28 ;
if ( args -> V_55 > args -> V_148 )
args -> V_55 = args -> V_148 ;
V_167:
V_151 = NULL ;
V_150 = NULL ;
V_162 = 0 ;
V_156 = 0 ;
V_163 = 0 ;
V_56 = F_73 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_133 ) ;
if ( ( error = F_15 ( V_56 , 0 , args -> V_50 , & V_62 ) ) )
goto V_131;
if ( ! V_62 ) {
if ( ( error = F_84 ( args , V_56 , & V_159 ,
& V_162 , & V_62 ) ) )
goto V_131;
if ( V_62 == 0 || V_162 == 0 ) {
F_76 ( V_56 , V_135 ) ;
F_85 ( args ) ;
return 0 ;
}
ASSERT ( V_62 == 1 ) ;
}
args -> V_117 = 0 ;
while ( F_86 ( V_56 , 0 ) ) {
T_1 V_168 ;
int V_169 = 0 ;
T_1 V_170 = 0 ;
T_2 V_171 = 0 ;
#ifdef F_34
if ( V_166 )
break;
#endif
if ( V_162 || args -> V_29 > 1 ) {
V_56 -> V_172 [ 0 ] = 1 ;
do {
if ( ( error = F_20 ( V_56 , & V_159 ,
& V_162 , & V_62 ) ) )
goto V_131;
F_74 ( args -> V_2 , V_62 == 1 , V_131 ) ;
if ( V_162 >= args -> V_30 )
break;
if ( ( error = F_81 ( V_56 , 0 , & V_62 ) ) )
goto V_131;
} while ( V_62 );
ASSERT ( V_162 >= args -> V_30 ) ;
if ( ! V_62 )
break;
}
V_62 = V_56 -> V_172 [ 0 ] ;
for ( V_158 = 1 , V_170 = 0 , V_168 = 0 ;
! error && V_158 && ( V_170 < args -> V_50 || V_168 > 0 ) ;
error = F_81 ( V_56 , 0 , & V_158 ) ) {
if ( ( error = F_20 ( V_56 , & V_159 , & V_162 , & V_62 ) ) )
goto V_131;
F_74 ( args -> V_2 , V_62 == 1 , V_131 ) ;
F_23 ( args , V_159 , V_162 ,
& V_160 , & V_163 ) ;
if ( V_163 < args -> V_30 )
continue;
if ( V_160 < args -> V_28 || V_160 > args -> V_148 )
continue;
args -> V_11 = F_28 ( V_163 , args -> V_50 ) ;
F_30 ( args ) ;
ASSERT ( args -> V_11 >= args -> V_30 ) ;
if ( args -> V_11 < V_170 )
continue;
V_161 = F_26 ( args -> V_55 , args -> V_11 ,
args -> V_29 , args -> V_34 , V_160 ,
V_163 , & V_164 ) ;
if ( V_164 != V_45 &&
( args -> V_11 > V_170 || V_161 < V_168 ) ) {
V_168 = V_161 ;
V_171 = V_164 ;
V_170 = args -> V_11 ;
V_169 = V_56 -> V_172 [ 0 ] ;
}
}
if ( V_170 == 0 )
break;
V_56 -> V_172 [ 0 ] = V_169 ;
if ( ( error = F_20 ( V_56 , & V_159 , & V_162 , & V_62 ) ) )
goto V_131;
F_74 ( args -> V_2 , V_62 == 1 , V_131 ) ;
ASSERT ( V_159 + V_162 <= F_22 ( F_32 ( args -> V_53 ) -> V_112 ) ) ;
args -> V_11 = V_170 ;
if ( ! F_31 ( args ) ) {
F_76 ( V_56 , V_135 ) ;
F_87 ( args ) ;
return 0 ;
}
V_170 = args -> V_11 ;
args -> V_55 = V_171 ;
ASSERT ( V_171 >= V_159 ) ;
ASSERT ( V_171 + V_170 <= V_159 + V_162 ) ;
V_151 = F_73 ( args -> V_2 , args -> V_100 ,
args -> V_53 , args -> V_101 , V_130 ) ;
if ( ( error = F_33 ( V_56 , V_151 , V_159 ,
V_162 , V_171 , V_170 , V_68 ) ) )
goto V_131;
F_76 ( V_56 , V_135 ) ;
F_76 ( V_151 , V_135 ) ;
F_88 ( args ) ;
return 0 ;
}
V_151 = F_73 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_130 ) ;
if ( ( error = F_16 ( V_151 , args -> V_55 , args -> V_50 , & V_62 ) ) )
goto V_131;
if ( ! V_62 ) {
V_150 = V_151 ;
V_151 = NULL ;
}
else if ( ( error = F_89 ( V_151 , & V_150 ) ) )
goto V_131;
if ( ( error = F_81 ( V_150 , 0 , & V_62 ) ) )
goto V_131;
if ( ! V_62 ) {
F_76 ( V_150 , V_135 ) ;
V_150 = NULL ;
}
do {
if ( V_151 ) {
if ( ( error = F_20 ( V_151 , & V_159 , & V_162 , & V_62 ) ) )
goto V_131;
F_74 ( args -> V_2 , V_62 == 1 , V_131 ) ;
F_23 ( args , V_159 , V_162 ,
& V_160 , & V_163 ) ;
if ( V_163 >= args -> V_30 && V_160 >= args -> V_28 )
break;
if ( ( error = F_82 ( V_151 , 0 , & V_62 ) ) )
goto V_131;
if ( ! V_62 || V_160 < args -> V_28 ) {
F_76 ( V_151 ,
V_135 ) ;
V_151 = NULL ;
}
}
if ( V_150 ) {
if ( ( error = F_20 ( V_150 , & V_152 , & V_155 , & V_62 ) ) )
goto V_131;
F_74 ( args -> V_2 , V_62 == 1 , V_131 ) ;
F_23 ( args , V_152 , V_155 ,
& V_153 , & V_156 ) ;
if ( V_156 >= args -> V_30 && V_153 <= args -> V_148 )
break;
if ( ( error = F_81 ( V_150 , 0 , & V_62 ) ) )
goto V_131;
if ( ! V_62 || V_153 > args -> V_148 ) {
F_76 ( V_150 ,
V_135 ) ;
V_150 = NULL ;
}
}
} while ( V_151 || V_150 );
if ( V_151 && V_150 ) {
if ( V_163 >= args -> V_30 ) {
args -> V_11 = F_28 ( V_163 , args -> V_50 ) ;
F_30 ( args ) ;
V_161 = F_26 ( args -> V_55 , args -> V_11 ,
args -> V_29 , args -> V_34 , V_160 ,
V_163 , & V_164 ) ;
error = F_80 ( args ,
& V_151 , & V_150 ,
V_161 , & V_152 , & V_155 ,
& V_153 , & V_156 ,
0 ) ;
} else {
ASSERT ( V_156 >= args -> V_30 ) ;
args -> V_11 = F_28 ( V_156 , args -> V_50 ) ;
F_30 ( args ) ;
V_154 = F_26 ( args -> V_55 , args -> V_11 ,
args -> V_29 , args -> V_34 , V_153 ,
V_156 , & V_157 ) ;
error = F_80 ( args ,
& V_150 , & V_151 ,
V_154 , & V_159 , & V_162 ,
& V_160 , & V_163 ,
1 ) ;
}
if ( error )
goto V_131;
}
if ( V_151 == NULL && V_150 == NULL ) {
F_76 ( V_56 , V_135 ) ;
if ( ! V_165 ++ ) {
F_90 ( args ) ;
F_91 ( args -> V_2 , V_173 ) ;
goto V_167;
}
F_92 ( args ) ;
args -> V_55 = V_45 ;
return 0 ;
}
if ( V_150 ) {
V_151 = V_150 ;
V_150 = NULL ;
V_159 = V_152 ;
V_160 = V_153 ;
V_162 = V_155 ;
V_163 = V_156 ;
V_158 = 1 ;
} else
V_158 = 0 ;
args -> V_11 = F_28 ( V_163 , args -> V_50 ) ;
F_30 ( args ) ;
if ( ! F_31 ( args ) ) {
F_87 ( args ) ;
F_76 ( V_151 , V_135 ) ;
F_76 ( V_56 , V_135 ) ;
return 0 ;
}
V_47 = args -> V_11 ;
( void ) F_26 ( args -> V_55 , V_47 , args -> V_29 ,
args -> V_34 , V_160 , V_163 , & V_164 ) ;
ASSERT ( V_164 >= V_159 ) ;
ASSERT ( V_164 + V_47 <= V_160 + V_163 ) ;
ASSERT ( V_164 + V_47 <= F_22 ( F_32 ( args -> V_53 ) -> V_112 ) ) ;
ASSERT ( V_164 >= args -> V_28 && V_164 <= args -> V_148 ) ;
args -> V_55 = V_164 ;
if ( ( error = F_33 ( V_56 , V_151 , V_159 , V_162 ,
V_164 , V_47 , V_69 ) ) )
goto V_131;
if ( V_158 )
F_93 ( args ) ;
else
F_94 ( args ) ;
F_76 ( V_56 , V_135 ) ;
F_76 ( V_151 , V_135 ) ;
return 0 ;
V_131:
F_95 ( args ) ;
if ( V_56 != NULL )
F_76 ( V_56 , V_134 ) ;
if ( V_151 != NULL )
F_76 ( V_151 , V_134 ) ;
if ( V_150 != NULL )
F_76 ( V_150 , V_134 ) ;
return error ;
}
STATIC int
F_65 (
T_3 * args )
{
T_5 * V_57 ;
T_5 * V_56 ;
int error ;
T_2 V_58 ;
T_1 V_59 ;
int V_62 ;
T_2 V_60 ;
T_1 V_47 ;
int V_165 = 0 ;
V_167:
V_56 = F_73 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_133 ) ;
V_57 = NULL ;
if ( ( error = F_15 ( V_56 , 0 ,
args -> V_50 + args -> V_29 - 1 , & V_62 ) ) )
goto V_131;
if ( ! V_62 || V_165 > 1 ) {
error = F_84 ( args , V_56 ,
& V_58 , & V_59 , & V_62 ) ;
if ( error )
goto V_131;
if ( V_62 == 0 || V_59 == 0 ) {
F_76 ( V_56 , V_135 ) ;
F_96 ( args ) ;
return 0 ;
}
ASSERT ( V_62 == 1 ) ;
F_23 ( args , V_58 , V_59 , & V_60 , & V_47 ) ;
} else {
for (; ; ) {
error = F_20 ( V_56 , & V_58 , & V_59 , & V_62 ) ;
if ( error )
goto V_131;
F_74 ( args -> V_2 , V_62 == 1 , V_131 ) ;
F_23 ( args , V_58 , V_59 ,
& V_60 , & V_47 ) ;
if ( V_47 >= args -> V_50 )
break;
error = F_81 ( V_56 , 0 , & V_62 ) ;
if ( error )
goto V_131;
if ( V_62 == 0 ) {
F_76 ( V_56 ,
V_135 ) ;
F_97 ( args ) ;
if ( ! V_165 ++ )
F_91 ( args -> V_2 , V_173 ) ;
goto V_167;
}
}
}
V_47 = F_28 ( args -> V_50 , V_47 ) ;
F_74 ( args -> V_2 , V_47 == 0 ||
( V_47 <= V_59 && V_60 + V_47 <= V_58 + V_59 ) , V_131 ) ;
if ( V_47 < args -> V_50 ) {
T_2 V_174 ;
T_1 V_175 ;
T_2 V_176 ;
T_1 V_177 ;
V_177 = V_47 ;
V_176 = V_60 ;
V_175 = V_59 ;
V_174 = V_58 ;
for (; ; ) {
if ( ( error = F_82 ( V_56 , 0 , & V_62 ) ) )
goto V_131;
if ( V_62 == 0 )
break;
if ( ( error = F_20 ( V_56 , & V_58 , & V_59 ,
& V_62 ) ) )
goto V_131;
F_74 ( args -> V_2 , V_62 == 1 , V_131 ) ;
if ( V_59 < V_177 )
break;
F_23 ( args , V_58 , V_59 ,
& V_60 , & V_47 ) ;
V_47 = F_28 ( args -> V_50 , V_47 ) ;
F_74 ( args -> V_2 , V_47 == 0 ||
( V_47 <= V_59 && V_60 + V_47 <= V_58 + V_59 ) ,
V_131 ) ;
if ( V_47 > V_177 ) {
V_177 = V_47 ;
V_176 = V_60 ;
V_175 = V_59 ;
V_174 = V_58 ;
if ( V_47 == args -> V_50 )
break;
}
}
if ( ( error = F_13 ( V_56 , V_174 , V_175 ,
& V_62 ) ) )
goto V_131;
F_74 ( args -> V_2 , V_62 == 1 , V_131 ) ;
V_47 = V_177 ;
V_60 = V_176 ;
V_59 = V_175 ;
V_58 = V_174 ;
}
args -> V_117 = 0 ;
args -> V_11 = V_47 ;
if ( V_47 < args -> V_30 ) {
if ( ! V_165 ++ ) {
F_76 ( V_56 , V_135 ) ;
F_97 ( args ) ;
F_91 ( args -> V_2 , V_173 ) ;
goto V_167;
}
goto V_178;
}
F_30 ( args ) ;
if ( ! F_31 ( args ) )
goto V_178;
V_47 = args -> V_11 ;
F_74 ( args -> V_2 , V_47 <= V_59 , V_131 ) ;
V_57 = F_73 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_130 ) ;
if ( ( error = F_33 ( V_56 , V_57 , V_58 , V_59 ,
V_60 , V_47 , V_68 ) ) )
goto V_131;
F_76 ( V_56 , V_135 ) ;
F_76 ( V_57 , V_135 ) ;
V_56 = V_57 = NULL ;
args -> V_11 = V_47 ;
args -> V_55 = V_60 ;
F_74 ( args -> V_2 ,
args -> V_55 + args -> V_11 <=
F_22 ( F_32 ( args -> V_53 ) -> V_112 ) ,
V_131 ) ;
F_98 ( args ) ;
return 0 ;
V_131:
F_99 ( args ) ;
if ( V_56 )
F_76 ( V_56 , V_134 ) ;
if ( V_57 )
F_76 ( V_57 , V_134 ) ;
return error ;
V_178:
F_76 ( V_56 , V_135 ) ;
F_100 ( args ) ;
args -> V_55 = V_45 ;
return 0 ;
}
STATIC int
F_84 (
T_3 * args ,
T_5 * V_179 ,
T_2 * V_180 ,
T_1 * V_181 ,
int * V_12 )
{
struct V_182 V_122 ;
struct V_108 * V_109 ;
int error ;
T_2 V_58 ;
T_1 V_59 ;
int V_62 ;
if ( ( error = F_82 ( V_179 , 0 , & V_62 ) ) )
goto V_131;
if ( V_62 ) {
if ( ( error = F_20 ( V_179 , & V_58 , & V_59 , & V_62 ) ) )
goto V_131;
F_74 ( args -> V_2 , V_62 == 1 , V_131 ) ;
}
else if ( args -> V_30 == 1 && args -> V_29 == 1 &&
args -> V_116 != V_121 &&
( F_22 ( F_32 ( args -> V_53 ) -> V_183 )
> args -> V_52 ) ) {
error = F_101 ( args -> V_100 , args -> V_53 , & V_58 , 0 ) ;
if ( error )
goto V_131;
if ( V_58 != V_45 ) {
F_102 ( args -> V_2 , args -> V_101 , V_58 , 1 ,
F_103 ( args -> V_34 ) ) ;
if ( F_27 ( args -> V_34 ) ) {
T_9 * V_77 ;
V_77 = F_104 ( args -> V_2 , args -> V_100 ,
args -> V_101 , V_58 , 0 ) ;
F_105 ( args -> V_100 , V_77 ) ;
}
args -> V_11 = 1 ;
args -> V_55 = V_58 ;
F_74 ( args -> V_2 ,
args -> V_55 + args -> V_11 <=
F_22 ( F_32 ( args -> V_53 ) -> V_112 ) ,
V_131 ) ;
args -> V_117 = 1 ;
F_106 ( args ) ;
F_107 ( & V_122 , V_184 ) ;
error = F_108 ( args -> V_100 , args -> V_53 , args -> V_101 ,
V_58 , 1 , & V_122 ) ;
if ( error )
goto V_131;
V_109 = F_109 ( args -> V_2 , args -> V_101 ) ;
F_110 ( V_109 , V_121 ,
args -> V_100 , 1 ) ;
F_111 ( V_109 ) ;
* V_12 = 0 ;
return 0 ;
}
else
V_59 = 0 ;
}
else {
V_58 = V_45 ;
V_59 = 0 ;
}
if ( V_59 < args -> V_30 ) {
args -> V_55 = V_45 ;
F_112 ( args ) ;
V_59 = 0 ;
}
* V_180 = V_58 ;
* V_181 = V_59 ;
* V_12 = 1 ;
F_113 ( args ) ;
return 0 ;
V_131:
F_114 ( args ) ;
return error ;
}
STATIC int
F_115 (
T_7 * V_100 ,
T_9 * V_53 ,
T_8 V_101 ,
T_2 V_10 ,
T_1 V_11 ,
struct V_182 * V_122 ,
enum V_185 type )
{
T_5 * V_57 ;
T_5 * V_56 ;
int error ;
T_2 V_152 ;
T_1 V_155 ;
int V_186 ;
int V_187 ;
int V_62 ;
T_2 V_159 ;
T_1 V_162 ;
T_6 * V_2 ;
T_2 V_188 ;
T_1 V_189 ;
T_10 * V_109 ;
V_57 = V_56 = NULL ;
V_2 = V_100 -> V_190 ;
if ( V_122 -> V_123 != V_124 ) {
error = F_108 ( V_100 , V_53 , V_101 , V_10 , V_11 , V_122 ) ;
if ( error )
goto V_131;
}
V_57 = F_73 ( V_2 , V_100 , V_53 , V_101 , V_130 ) ;
if ( ( error = F_16 ( V_57 , V_10 , V_11 , & V_186 ) ) )
goto V_131;
if ( V_186 ) {
if ( ( error = F_20 ( V_57 , & V_159 , & V_162 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
if ( V_159 + V_162 < V_10 )
V_186 = 0 ;
else {
F_74 ( V_2 ,
V_159 + V_162 <= V_10 , V_131 ) ;
}
}
if ( ( error = F_81 ( V_57 , 0 , & V_187 ) ) )
goto V_131;
if ( V_187 ) {
if ( ( error = F_20 ( V_57 , & V_152 , & V_155 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
if ( V_10 + V_11 < V_152 )
V_187 = 0 ;
else {
F_74 ( V_2 , V_152 >= V_10 + V_11 , V_131 ) ;
}
}
V_56 = F_73 ( V_2 , V_100 , V_53 , V_101 , V_133 ) ;
if ( V_186 && V_187 ) {
if ( ( error = F_13 ( V_56 , V_159 , V_162 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_37 ( V_56 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_13 ( V_56 , V_152 , V_155 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_37 ( V_56 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_37 ( V_57 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_82 ( V_57 , 0 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
#ifdef F_34
{
T_2 V_191 ;
T_1 V_192 ;
if ( ( error = F_20 ( V_57 , & V_191 , & V_192 ,
& V_62 ) ) )
goto V_131;
F_74 ( V_2 ,
V_62 == 1 && V_191 == V_159 && V_192 == V_162 ,
V_131 ) ;
}
#endif
V_188 = V_159 ;
V_189 = V_11 + V_162 + V_155 ;
if ( ( error = F_17 ( V_57 , V_188 , V_189 ) ) )
goto V_131;
}
else if ( V_186 ) {
if ( ( error = F_13 ( V_56 , V_159 , V_162 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_37 ( V_56 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_82 ( V_57 , 0 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
V_188 = V_159 ;
V_189 = V_11 + V_162 ;
if ( ( error = F_17 ( V_57 , V_188 , V_189 ) ) )
goto V_131;
}
else if ( V_187 ) {
if ( ( error = F_13 ( V_56 , V_152 , V_155 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_37 ( V_56 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
V_188 = V_10 ;
V_189 = V_11 + V_155 ;
if ( ( error = F_17 ( V_57 , V_188 , V_189 ) ) )
goto V_131;
}
else {
V_188 = V_10 ;
V_189 = V_11 ;
if ( ( error = F_38 ( V_57 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
}
F_76 ( V_57 , V_135 ) ;
V_57 = NULL ;
if ( ( error = F_13 ( V_56 , V_188 , V_189 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 0 , V_131 ) ;
if ( ( error = F_38 ( V_56 , & V_62 ) ) )
goto V_131;
F_74 ( V_2 , V_62 == 1 , V_131 ) ;
F_76 ( V_56 , V_135 ) ;
V_56 = NULL ;
V_109 = F_109 ( V_2 , V_101 ) ;
error = F_58 ( V_100 , V_109 , V_53 , V_11 ) ;
F_110 ( V_109 , type , V_100 , V_11 ) ;
F_111 ( V_109 ) ;
if ( error )
goto V_131;
F_71 ( V_2 , V_193 ) ;
F_72 ( V_2 , V_194 , V_11 ) ;
F_116 ( V_2 , V_101 , V_10 , V_11 , type == V_121 ,
V_186 , V_187 ) ;
return 0 ;
V_131:
F_116 ( V_2 , V_101 , V_10 , V_11 , type == V_121 ,
- 1 , - 1 ) ;
if ( V_57 )
F_76 ( V_57 , V_134 ) ;
if ( V_56 )
F_76 ( V_56 , V_134 ) ;
return error ;
}
void
F_117 (
T_6 * V_2 )
{
V_2 -> V_195 = F_118 ( V_2 , V_2 -> V_196 ,
( V_2 -> V_3 . V_7 + 1 ) / 2 ) ;
}
T_1
F_119 (
struct V_1 * V_2 ,
struct V_108 * V_109 ,
T_1 V_197 ,
T_1 V_198 )
{
T_1 V_199 = 0 ;
if ( V_197 > V_109 -> V_200 )
V_199 = V_197 - V_109 -> V_200 ;
if ( V_109 -> V_111 - V_109 -> V_201 < V_198 )
V_199 += V_198 - ( V_109 -> V_111 - V_109 -> V_201 ) ;
if ( V_109 -> V_201 > V_199 )
return V_109 -> V_201 - V_199 ;
return V_109 -> V_200 > 0 || V_109 -> V_201 > 0 ;
}
unsigned int
F_120 (
struct V_1 * V_2 ,
struct V_108 * V_109 )
{
unsigned int V_202 ;
V_202 = F_121 (unsigned int, pag->pagf_levels[XFS_BTNUM_BNOi] + 1 ,
mp->m_ag_maxlevels) ;
V_202 += F_121 (unsigned int, pag->pagf_levels[XFS_BTNUM_CNTi] + 1 ,
mp->m_ag_maxlevels) ;
if ( F_2 ( & V_2 -> V_3 ) )
V_202 += F_121 (unsigned int,
pag->pagf_levels[XFS_BTNUM_RMAPi] + 1 ,
mp->m_rmap_maxlevels) ;
return V_202 ;
}
static bool
F_122 (
struct V_136 * args ,
T_1 V_202 ,
int V_61 )
{
struct V_108 * V_109 = args -> V_109 ;
T_1 V_203 ;
T_1 V_114 ;
int V_204 ;
if ( V_61 & V_205 )
return true ;
V_114 = F_64 ( V_109 , args -> V_116 ) ;
V_203 = F_119 ( args -> V_2 , V_109 , V_202 ,
V_114 ) ;
if ( ( args -> V_30 + args -> V_29 + args -> V_206 - 1 ) > V_203 )
return false ;
V_204 = ( int ) ( V_109 -> V_111 + V_109 -> V_200 -
V_114 - V_202 - args -> V_207 ) ;
if ( V_204 < ( int ) args -> V_52 || V_204 <= 0 )
return false ;
return true ;
}
int
F_123 (
struct V_136 * args ,
int V_61 )
{
struct V_1 * V_2 = args -> V_2 ;
struct V_108 * V_109 = args -> V_109 ;
struct V_107 * V_100 = args -> V_100 ;
struct V_76 * V_53 = NULL ;
struct V_76 * V_208 = NULL ;
struct V_136 V_209 ;
T_2 V_10 ;
T_1 V_197 ;
int error = 0 ;
if ( ! V_109 -> V_210 ) {
error = F_124 ( V_2 , V_100 , args -> V_101 , V_61 , & V_53 ) ;
if ( error )
goto V_211;
if ( ! V_109 -> V_210 ) {
ASSERT ( V_61 & V_212 ) ;
ASSERT ( ! ( V_61 & V_205 ) ) ;
goto V_213;
}
}
if ( V_109 -> V_214 && F_27 ( args -> V_34 ) &&
( V_61 & V_212 ) ) {
ASSERT ( ! ( V_61 & V_205 ) ) ;
goto V_213;
}
V_197 = F_120 ( V_2 , V_109 ) ;
if ( ! F_122 ( args , V_197 , V_61 ) )
goto V_213;
if ( ! V_53 ) {
error = F_124 ( V_2 , V_100 , args -> V_101 , V_61 , & V_53 ) ;
if ( error )
goto V_211;
if ( ! V_53 ) {
ASSERT ( V_61 & V_212 ) ;
ASSERT ( ! ( V_61 & V_205 ) ) ;
goto V_211;
}
}
V_197 = F_120 ( V_2 , V_109 ) ;
if ( ! F_122 ( args , V_197 , V_61 ) )
goto V_213;
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
if ( V_61 & V_215 )
F_125 ( & V_209 . V_122 ) ;
else
F_107 ( & V_209 . V_122 , V_184 ) ;
while ( ! ( V_61 & V_216 ) && V_109 -> V_200 > V_197 ) {
struct V_76 * V_77 ;
error = F_101 ( V_100 , V_53 , & V_10 , 0 ) ;
if ( error )
goto V_213;
error = F_115 ( V_100 , V_53 , args -> V_101 , V_10 , 1 ,
& V_209 . V_122 , V_121 ) ;
if ( error )
goto V_213;
V_77 = F_104 ( V_2 , V_100 , args -> V_101 , V_10 , 0 ) ;
F_105 ( V_100 , V_77 ) ;
}
V_209 . V_100 = V_100 ;
V_209 . V_2 = V_2 ;
V_209 . V_53 = V_53 ;
V_209 . V_101 = args -> V_101 ;
V_209 . V_29 = V_209 . V_30 = V_209 . V_49 = 1 ;
V_209 . type = V_118 ;
V_209 . V_109 = V_109 ;
error = F_53 ( V_2 , V_100 , V_209 . V_101 , & V_208 ) ;
if ( error )
goto V_213;
while ( V_109 -> V_200 < V_197 ) {
V_209 . V_55 = 0 ;
V_209 . V_50 = V_197 - V_109 -> V_200 ;
V_209 . V_116 = V_121 ;
error = F_63 ( & V_209 ) ;
if ( error )
goto V_217;
if ( V_209 . V_55 == V_45 ) {
if ( V_61 & V_205 )
break;
goto V_217;
}
for ( V_10 = V_209 . V_55 ; V_10 < V_209 . V_55 + V_209 . V_11 ; V_10 ++ ) {
error = F_126 ( V_100 , V_53 ,
V_208 , V_10 , 0 ) ;
if ( error )
goto V_217;
}
}
F_127 ( V_100 , V_208 ) ;
args -> V_53 = V_53 ;
return 0 ;
V_217:
F_127 ( V_100 , V_208 ) ;
V_213:
if ( V_53 )
F_127 ( V_100 , V_53 ) ;
V_211:
args -> V_53 = NULL ;
return error ;
}
int
F_101 (
T_7 * V_100 ,
T_9 * V_53 ,
T_2 * V_218 ,
int V_219 )
{
T_4 * V_51 ;
T_9 * V_208 ;
T_2 V_10 ;
T_11 * V_89 ;
int error ;
int V_220 ;
T_6 * V_2 = V_100 -> V_190 ;
T_10 * V_109 ;
V_51 = F_32 ( V_53 ) ;
if ( ! V_51 -> V_183 ) {
* V_218 = V_45 ;
return 0 ;
}
error = F_53 ( V_2 , V_100 , F_22 ( V_51 -> V_221 ) ,
& V_208 ) ;
if ( error )
return error ;
V_89 = F_128 ( V_2 , V_208 ) ;
V_10 = F_22 ( V_89 [ F_22 ( V_51 -> V_222 ) ] ) ;
F_59 ( & V_51 -> V_222 , 1 ) ;
F_127 ( V_100 , V_208 ) ;
if ( F_22 ( V_51 -> V_222 ) == F_42 ( V_2 ) )
V_51 -> V_222 = 0 ;
V_109 = F_109 ( V_2 , F_22 ( V_51 -> V_221 ) ) ;
F_59 ( & V_51 -> V_183 , - 1 ) ;
F_129 ( V_100 , - 1 ) ;
V_109 -> V_200 -- ;
F_111 ( V_109 ) ;
V_220 = V_223 | V_224 ;
if ( V_219 ) {
F_59 ( & V_51 -> V_225 , 1 ) ;
V_109 -> V_226 ++ ;
V_220 |= V_227 ;
}
F_62 ( V_100 , V_53 , V_220 ) ;
* V_218 = V_10 ;
return 0 ;
}
void
F_62 (
T_7 * V_100 ,
T_9 * V_77 ,
int V_228 )
{
int V_229 ;
int V_230 ;
static const short V_231 [] = {
F_130 ( T_4 , V_232 ) ,
F_130 ( T_4 , V_233 ) ,
F_130 ( T_4 , V_221 ) ,
F_130 ( T_4 , V_112 ) ,
F_130 ( T_4 , V_234 [ 0 ] ) ,
F_130 ( T_4 , V_235 [ 0 ] ) ,
F_130 ( T_4 , V_222 ) ,
F_130 ( T_4 , V_236 ) ,
F_130 ( T_4 , V_183 ) ,
F_130 ( T_4 , V_54 ) ,
F_130 ( T_4 , V_237 ) ,
F_130 ( T_4 , V_225 ) ,
F_130 ( T_4 , V_238 ) ,
F_130 ( T_4 , V_239 ) ,
F_130 ( T_4 , V_240 ) ,
F_130 ( T_4 , V_241 ) ,
F_130 ( T_4 , V_242 ) ,
F_130 ( T_4 , V_243 ) ,
sizeof( T_4 )
} ;
F_131 ( V_100 -> V_190 , F_32 ( V_77 ) , V_228 , V_244 ) ;
F_132 ( V_100 , V_77 , V_245 ) ;
F_133 ( V_228 , V_231 , V_246 , & V_229 , & V_230 ) ;
F_134 ( V_100 , V_77 , ( V_247 ) V_229 , ( V_247 ) V_230 ) ;
}
int
F_135 (
T_6 * V_2 ,
T_7 * V_100 ,
T_8 V_101 ,
int V_61 )
{
T_9 * V_77 ;
int error ;
if ( ( error = F_124 ( V_2 , V_100 , V_101 , V_61 , & V_77 ) ) )
return error ;
if ( V_77 )
F_127 ( V_100 , V_77 ) ;
return 0 ;
}
int
F_126 (
T_7 * V_100 ,
T_9 * V_53 ,
T_9 * V_208 ,
T_2 V_10 ,
int V_219 )
{
T_4 * V_51 ;
T_11 * V_248 ;
int error ;
int V_220 ;
T_6 * V_2 ;
T_10 * V_109 ;
T_11 * V_89 ;
int V_249 ;
V_51 = F_32 ( V_53 ) ;
V_2 = V_100 -> V_190 ;
if ( ! V_208 && ( error = F_53 ( V_2 , V_100 ,
F_22 ( V_51 -> V_221 ) , & V_208 ) ) )
return error ;
F_59 ( & V_51 -> V_236 , 1 ) ;
if ( F_22 ( V_51 -> V_236 ) == F_42 ( V_2 ) )
V_51 -> V_236 = 0 ;
V_109 = F_109 ( V_2 , F_22 ( V_51 -> V_221 ) ) ;
F_59 ( & V_51 -> V_183 , 1 ) ;
F_129 ( V_100 , 1 ) ;
V_109 -> V_200 ++ ;
V_220 = V_250 | V_224 ;
if ( V_219 ) {
F_59 ( & V_51 -> V_225 , - 1 ) ;
V_109 -> V_226 -- ;
V_220 |= V_227 ;
}
F_111 ( V_109 ) ;
F_62 ( V_100 , V_53 , V_220 ) ;
ASSERT ( F_22 ( V_51 -> V_183 ) <= F_42 ( V_2 ) ) ;
V_89 = F_128 ( V_2 , V_208 ) ;
V_248 = & V_89 [ F_22 ( V_51 -> V_236 ) ] ;
* V_248 = F_18 ( V_10 ) ;
V_249 = ( char * ) V_248 - ( char * ) V_208 -> V_251 ;
F_62 ( V_100 , V_53 , V_220 ) ;
F_132 ( V_100 , V_208 , V_252 ) ;
F_134 ( V_100 , V_208 , V_249 ,
V_249 + sizeof( T_2 ) - 1 ) ;
return 0 ;
}
static bool
F_136 (
struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_110 * V_51 = F_32 ( V_77 ) ;
if ( F_46 ( & V_2 -> V_3 ) ) {
if ( ! F_41 ( & V_51 -> V_238 , & V_2 -> V_3 . V_83 ) )
return false ;
if ( ! F_43 ( V_2 ,
F_44 ( F_32 ( V_77 ) -> V_253 ) ) )
return false ;
}
if ( ! ( V_51 -> V_232 == F_18 ( V_254 ) &&
F_137 ( F_22 ( V_51 -> V_233 ) ) &&
F_22 ( V_51 -> V_54 ) <= F_22 ( V_51 -> V_112 ) &&
F_22 ( V_51 -> V_222 ) < F_42 ( V_2 ) &&
F_22 ( V_51 -> V_236 ) < F_42 ( V_2 ) &&
F_22 ( V_51 -> V_183 ) <= F_42 ( V_2 ) ) )
return false ;
if ( F_22 ( V_51 -> V_235 [ V_130 ] ) > V_255 ||
F_22 ( V_51 -> V_235 [ V_133 ] ) > V_255 )
return false ;
if ( F_2 ( & V_2 -> V_3 ) &&
F_22 ( V_51 -> V_235 [ V_256 ] ) > V_255 )
return false ;
if ( V_77 -> V_86 && F_22 ( V_51 -> V_221 ) != V_77 -> V_86 -> V_88 )
return false ;
if ( F_138 ( & V_2 -> V_3 ) &&
F_22 ( V_51 -> V_225 ) > F_22 ( V_51 -> V_112 ) )
return false ;
if ( F_8 ( & V_2 -> V_3 ) &&
F_22 ( V_51 -> V_242 ) > V_255 )
return false ;
return true ; ;
}
static void
F_139 (
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_78 -> V_79 ;
if ( F_46 ( & V_2 -> V_3 ) &&
! F_47 ( V_77 , V_257 ) )
F_48 ( V_77 , - V_92 ) ;
else if ( F_140 ( ! F_136 ( V_2 , V_77 ) , V_2 ,
V_258 ,
V_259 ) )
F_48 ( V_77 , - V_93 ) ;
if ( V_77 -> V_94 )
F_49 ( V_77 ) ;
}
static void
F_141 (
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_78 -> V_79 ;
struct V_95 * V_96 = V_77 -> V_97 ;
if ( ! F_136 ( V_2 , V_77 ) ) {
F_48 ( V_77 , - V_93 ) ;
F_49 ( V_77 ) ;
return;
}
if ( ! F_46 ( & V_2 -> V_3 ) )
return;
if ( V_96 )
F_32 ( V_77 ) -> V_253 = F_51 ( V_96 -> V_98 . V_99 ) ;
F_52 ( V_77 , V_257 ) ;
}
int
F_142 (
struct V_1 * V_2 ,
struct V_107 * V_100 ,
T_8 V_101 ,
int V_61 ,
struct V_76 * * V_102 )
{
int error ;
F_143 ( V_2 , V_101 ) ;
ASSERT ( V_101 != V_103 ) ;
error = F_54 (
V_2 , V_100 , V_2 -> V_104 ,
F_55 ( V_2 , V_101 , F_144 ( V_2 ) ) ,
F_12 ( V_2 , 1 ) , V_61 , V_102 , & V_260 ) ;
if ( error )
return error ;
if ( ! * V_102 )
return 0 ;
ASSERT ( ! ( * V_102 ) -> V_94 ) ;
F_57 ( * V_102 , V_261 ) ;
return 0 ;
}
int
F_124 (
struct V_1 * V_2 ,
struct V_107 * V_100 ,
T_8 V_101 ,
int V_61 ,
struct V_76 * * V_102 )
{
struct V_110 * V_51 ;
struct V_108 * V_109 ;
int error ;
F_145 ( V_2 , V_101 ) ;
ASSERT ( V_101 != V_103 ) ;
error = F_142 ( V_2 , V_100 , V_101 ,
( V_61 & V_212 ) ? V_262 : 0 ,
V_102 ) ;
if ( error )
return error ;
if ( ! * V_102 )
return 0 ;
ASSERT ( ! ( * V_102 ) -> V_94 ) ;
V_51 = F_32 ( * V_102 ) ;
V_109 = F_109 ( V_2 , V_101 ) ;
if ( ! V_109 -> V_210 ) {
V_109 -> V_111 = F_22 ( V_51 -> V_54 ) ;
V_109 -> V_226 = F_22 ( V_51 -> V_225 ) ;
V_109 -> V_200 = F_22 ( V_51 -> V_183 ) ;
V_109 -> V_201 = F_22 ( V_51 -> V_237 ) ;
V_109 -> V_263 [ V_264 ] =
F_22 ( V_51 -> V_235 [ V_264 ] ) ;
V_109 -> V_263 [ V_265 ] =
F_22 ( V_51 -> V_235 [ V_265 ] ) ;
V_109 -> V_263 [ V_266 ] =
F_22 ( V_51 -> V_235 [ V_266 ] ) ;
V_109 -> V_267 = F_22 ( V_51 -> V_242 ) ;
F_146 ( & V_109 -> V_268 ) ;
V_109 -> V_269 = 0 ;
V_109 -> V_270 = V_271 ;
V_109 -> V_210 = 1 ;
}
#ifdef F_34
else if ( ! F_147 ( V_2 ) ) {
ASSERT ( V_109 -> V_111 == F_22 ( V_51 -> V_54 ) ) ;
ASSERT ( V_109 -> V_226 == F_22 ( V_51 -> V_225 ) ) ;
ASSERT ( V_109 -> V_200 == F_22 ( V_51 -> V_183 ) ) ;
ASSERT ( V_109 -> V_201 == F_22 ( V_51 -> V_237 ) ) ;
ASSERT ( V_109 -> V_263 [ V_264 ] ==
F_22 ( V_51 -> V_235 [ V_264 ] ) ) ;
ASSERT ( V_109 -> V_263 [ V_265 ] ==
F_22 ( V_51 -> V_235 [ V_265 ] ) ) ;
}
#endif
F_111 ( V_109 ) ;
return 0 ;
}
int
F_148 (
T_3 * args )
{
T_2 V_272 ;
int error ;
int V_61 ;
T_1 V_52 ;
T_6 * V_2 ;
T_8 V_273 ;
T_12 type ;
int V_274 = 0 ;
int V_275 = 0 ;
T_8 V_276 = V_277 ;
V_2 = args -> V_2 ;
type = args -> V_278 = args -> type ;
args -> V_55 = V_45 ;
V_272 = V_2 -> V_3 . V_7 ;
if ( args -> V_50 > V_272 )
args -> V_50 = V_272 ;
if ( args -> V_29 == 0 )
args -> V_29 = 1 ;
ASSERT ( F_149 ( V_2 , args -> V_279 ) < V_2 -> V_3 . V_5 ) ;
ASSERT ( F_150 ( V_2 , args -> V_279 ) < V_272 ) ;
ASSERT ( args -> V_30 <= args -> V_50 ) ;
ASSERT ( args -> V_30 <= V_272 ) ;
ASSERT ( args -> V_48 < args -> V_49 ) ;
if ( F_149 ( V_2 , args -> V_279 ) >= V_2 -> V_3 . V_5 ||
F_150 ( V_2 , args -> V_279 ) >= V_272 ||
args -> V_30 > args -> V_50 || args -> V_30 > V_272 ||
args -> V_48 >= args -> V_49 ) {
args -> V_279 = V_280 ;
F_151 ( args ) ;
return 0 ;
}
V_52 = args -> V_52 ;
switch ( type ) {
case V_118 :
case V_119 :
case V_120 :
args -> V_101 = F_149 ( V_2 , args -> V_279 ) ;
args -> V_109 = F_109 ( V_2 , args -> V_101 ) ;
args -> V_52 = 0 ;
error = F_123 ( args , 0 ) ;
args -> V_52 = V_52 ;
if ( error ) {
F_152 ( args ) ;
goto V_131;
}
if ( ! args -> V_53 ) {
F_153 ( args ) ;
break;
}
args -> V_55 = F_150 ( V_2 , args -> V_279 ) ;
if ( ( error = F_63 ( args ) ) )
goto V_131;
break;
case V_281 :
if ( ( args -> V_34 & V_282 ) &&
( V_2 -> V_283 & V_284 ) ) {
args -> V_279 = F_154 ( V_2 ,
( ( V_2 -> V_285 / V_276 ) %
V_2 -> V_3 . V_5 ) , 0 ) ;
V_274 = 1 ;
}
args -> V_55 = F_150 ( V_2 , args -> V_279 ) ;
args -> type = V_119 ;
case V_286 :
case V_287 :
case V_288 :
if ( type == V_286 ) {
args -> V_101 = V_273 = ( V_2 -> V_285 / V_276 ) %
V_2 -> V_3 . V_5 ;
args -> type = V_118 ;
V_61 = V_212 ;
} else if ( type == V_288 ) {
args -> V_101 = F_149 ( V_2 , args -> V_279 ) ;
args -> type = V_118 ;
V_273 = 0 ;
V_61 = 0 ;
} else {
if ( type == V_287 )
args -> type = V_118 ;
args -> V_101 = V_273 = F_149 ( V_2 , args -> V_279 ) ;
V_61 = V_212 ;
}
for (; ; ) {
args -> V_109 = F_109 ( V_2 , args -> V_101 ) ;
if ( V_275 ) args -> V_52 = 0 ;
error = F_123 ( args , V_61 ) ;
args -> V_52 = V_52 ;
if ( error ) {
F_152 ( args ) ;
goto V_131;
}
if ( args -> V_53 ) {
if ( ( error = F_63 ( args ) ) )
goto V_131;
break;
}
F_155 ( args ) ;
if ( args -> V_101 == V_273 &&
type == V_281 )
args -> type = V_118 ;
if ( ++ ( args -> V_101 ) == V_2 -> V_3 . V_5 ) {
if ( args -> V_289 != V_280 )
args -> V_101 = V_273 ;
else
args -> V_101 = 0 ;
}
if ( args -> V_101 == V_273 ) {
if ( V_275 == 1 ) {
args -> V_55 = V_45 ;
F_156 ( args ) ;
break;
}
if ( V_61 == 0 ) {
V_275 = 1 ;
} else {
V_61 = 0 ;
if ( type == V_281 ) {
args -> V_55 = F_150 ( V_2 ,
args -> V_279 ) ;
args -> type = V_119 ;
}
}
}
F_111 ( args -> V_109 ) ;
}
if ( V_274 || ( type == V_286 ) ) {
if ( args -> V_101 == V_273 )
V_2 -> V_285 = ( V_2 -> V_285 + 1 ) %
( V_2 -> V_3 . V_5 * V_276 ) ;
else
V_2 -> V_285 = ( args -> V_101 * V_276 + 1 ) %
( V_2 -> V_3 . V_5 * V_276 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_55 == V_45 )
args -> V_279 = V_280 ;
else {
args -> V_279 = F_154 ( V_2 , args -> V_101 , args -> V_55 ) ;
#ifdef F_34
ASSERT ( args -> V_11 >= args -> V_30 ) ;
ASSERT ( args -> V_11 <= args -> V_50 ) ;
ASSERT ( args -> V_55 % args -> V_29 == 0 ) ;
F_157 ( V_2 , F_158 ( V_2 , args -> V_279 ) ,
args -> V_11 ) ;
#endif
if ( args -> V_34 & V_290 ) {
error = F_159 ( args -> V_291 , args -> V_279 , args -> V_11 ) ;
if ( error )
goto V_131;
}
}
F_111 ( args -> V_109 ) ;
return 0 ;
V_131:
F_111 ( args -> V_109 ) ;
return error ;
}
int
F_160 (
struct V_107 * V_100 ,
T_8 V_101 ,
struct V_76 * * V_53 )
{
struct V_136 args ;
int error ;
memset ( & args , 0 , sizeof( struct V_136 ) ) ;
args . V_100 = V_100 ;
args . V_2 = V_100 -> V_190 ;
args . V_101 = V_101 ;
if ( args . V_101 >= args . V_2 -> V_3 . V_5 )
return - V_93 ;
args . V_109 = F_109 ( args . V_2 , args . V_101 ) ;
ASSERT ( args . V_109 ) ;
error = F_123 ( & args , V_205 ) ;
if ( error )
goto V_292;
* V_53 = args . V_53 ;
V_292:
F_111 ( args . V_109 ) ;
return error ;
}
int
F_161 (
struct V_107 * V_100 ,
T_13 V_10 ,
T_1 V_11 ,
struct V_182 * V_122 ,
enum V_185 type )
{
struct V_1 * V_2 = V_100 -> V_190 ;
struct V_76 * V_53 ;
T_8 V_101 = F_149 ( V_2 , V_10 ) ;
T_2 V_55 = F_150 ( V_2 , V_10 ) ;
int error ;
ASSERT ( V_11 != 0 ) ;
ASSERT ( type != V_121 ) ;
if ( F_140 ( false , V_2 ,
V_293 ,
V_294 ) )
return - V_295 ;
error = F_160 ( V_100 , V_101 , & V_53 ) ;
if ( error )
return error ;
F_74 ( V_2 , V_55 < V_2 -> V_3 . V_7 , V_296 ) ;
F_74 ( V_2 ,
V_55 + V_11 <= F_22 ( F_32 ( V_53 ) -> V_112 ) ,
V_296 ) ;
error = F_115 ( V_100 , V_53 , V_101 , V_55 , V_11 , V_122 , type ) ;
if ( error )
goto V_296;
F_162 ( V_100 , V_101 , V_55 , V_11 , 0 ) ;
return 0 ;
V_296:
F_127 ( V_100 , V_53 ) ;
return error ;
}
