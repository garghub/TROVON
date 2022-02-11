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
return V_2 -> V_3 . V_4 * ( V_5 + 4 ) ;
}
unsigned int
F_10 (
struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_11 ( V_2 , F_12 ( V_2 , 4 ) ) ;
V_6 += V_5 ;
V_6 += 3 ;
if ( F_4 ( & V_2 -> V_3 ) )
V_6 ++ ;
if ( F_2 ( & V_2 -> V_3 ) )
V_6 ++ ;
if ( F_8 ( & V_2 -> V_3 ) )
V_6 ++ ;
return V_2 -> V_3 . V_7 - V_6 ;
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
STATIC bool
F_23 (
T_3 * args ,
T_2 V_23 ,
T_1 V_24 ,
T_2 * V_25 ,
T_1 * V_26 ,
unsigned * V_27 )
{
T_2 V_10 = V_23 ;
T_1 V_11 = V_24 ;
T_1 V_28 ;
bool V_29 ;
V_29 = F_24 ( args , & V_10 , & V_11 , V_27 ) ;
if ( V_10 < args -> V_30 && V_10 + V_11 > args -> V_30 ) {
V_28 = args -> V_30 - V_10 ;
if ( V_11 > V_28 ) {
V_10 += V_28 ;
V_11 -= V_28 ;
}
}
if ( args -> V_31 > 1 && V_11 >= args -> V_32 ) {
T_2 V_33 = F_25 ( V_10 , args -> V_31 ) ;
V_28 = V_33 - V_10 ;
* V_25 = V_33 ;
* V_26 = V_28 >= V_11 ? 0 : V_11 - V_28 ;
} else {
* V_25 = V_10 ;
* V_26 = V_11 ;
}
return V_29 ;
}
STATIC T_1
F_26 (
T_2 V_34 ,
T_1 V_35 ,
T_1 V_31 ,
int V_36 ,
T_2 V_37 ,
T_1 V_38 ,
T_2 * V_39 )
{
T_2 V_40 ;
T_2 V_41 ;
T_2 V_42 ;
T_1 V_43 = 0 ;
T_1 V_44 = 0 ;
T_2 V_45 ;
bool V_46 = F_27 ( V_36 ) ;
ASSERT ( V_38 >= V_35 ) ;
V_40 = V_37 + V_38 ;
V_45 = V_34 + V_35 ;
if ( V_37 >= V_34 || ( V_46 && V_40 < V_45 ) ) {
if ( ( V_41 = F_25 ( V_37 , V_31 ) ) >= V_40 )
V_41 = V_47 ;
} else if ( V_40 >= V_45 && V_31 > 1 ) {
V_41 = F_25 ( V_34 , V_31 ) ;
V_42 = V_41 - V_31 ;
if ( V_41 >= V_40 )
V_41 = V_47 ;
else
V_43 = F_28 ( V_35 , V_40 - V_41 ) ;
if ( V_42 < V_37 )
V_42 = V_47 ;
else
V_44 = F_28 ( V_35 , V_40 - V_42 ) ;
if ( V_41 != V_47 && V_42 != V_47 ) {
if ( V_43 < V_44 ||
( V_43 == V_44 &&
F_29 ( V_41 , V_34 ) >
F_29 ( V_42 , V_34 ) ) )
V_41 = V_42 ;
} else if ( V_42 != V_47 )
V_41 = V_42 ;
} else if ( V_40 >= V_45 ) {
V_41 = V_34 ;
} else if ( V_31 > 1 ) {
V_41 = F_25 ( V_40 - V_35 , V_31 ) ;
if ( V_41 > V_40 - V_35 &&
V_41 - V_31 >= V_37 )
V_41 -= V_31 ;
else if ( V_41 >= V_40 )
V_41 = V_47 ;
} else
V_41 = V_40 - V_35 ;
* V_39 = V_41 ;
return V_41 == V_47 ? 0 : F_29 ( V_41 , V_34 ) ;
}
STATIC void
F_30 (
T_3 * args )
{
T_1 V_48 ;
T_1 V_49 ;
ASSERT ( args -> V_50 < args -> V_51 ) ;
V_49 = args -> V_11 ;
ASSERT ( V_49 >= args -> V_32 ) ;
ASSERT ( V_49 <= args -> V_52 ) ;
if ( args -> V_51 <= 1 || V_49 < args -> V_50 || V_49 == args -> V_52 ||
( args -> V_50 == 0 && V_49 < args -> V_51 ) )
return;
V_48 = V_49 % args -> V_51 ;
if ( V_48 == args -> V_50 )
return;
if ( V_48 > args -> V_50 )
V_49 = V_49 - ( V_48 - args -> V_50 ) ;
else
V_49 = V_49 - args -> V_51 + ( args -> V_50 - V_48 ) ;
if ( ( int ) V_49 < ( int ) args -> V_32 )
return;
ASSERT ( V_49 >= args -> V_32 && V_49 <= args -> V_52 ) ;
ASSERT ( V_49 % args -> V_51 == args -> V_50 ) ;
ASSERT ( args -> V_53 -> V_54 + args -> V_53 -> V_55 >=
V_49 + args -> V_56 ) ;
args -> V_11 = V_49 ;
}
STATIC int
F_31 (
T_4 * V_57 ,
T_4 * V_58 ,
T_2 V_59 ,
T_1 V_60 ,
T_2 V_61 ,
T_1 V_49 ,
int V_62 )
{
int error ;
int V_63 ;
T_2 V_64 ;
T_2 V_65 ;
T_1 V_66 = 0 ;
T_1 V_67 = 0 ;
struct V_1 * V_2 ;
V_2 = V_57 -> V_68 ;
if ( V_62 & V_69 ) {
#ifdef F_32
if ( ( error = F_20 ( V_57 , & V_64 , & V_66 , & V_63 ) ) )
return error ;
F_33 ( V_2 ,
V_63 == 1 && V_64 == V_59 && V_66 == V_60 ) ;
#endif
} else {
if ( ( error = F_13 ( V_57 , V_59 , V_60 , & V_63 ) ) )
return error ;
F_33 ( V_2 , V_63 == 1 ) ;
}
if ( V_62 & V_70 ) {
#ifdef F_32
if ( ( error = F_20 ( V_58 , & V_64 , & V_66 , & V_63 ) ) )
return error ;
F_33 ( V_2 ,
V_63 == 1 && V_64 == V_59 && V_66 == V_60 ) ;
#endif
} else {
if ( ( error = F_13 ( V_58 , V_59 , V_60 , & V_63 ) ) )
return error ;
F_33 ( V_2 , V_63 == 1 ) ;
}
#ifdef F_32
if ( V_58 -> V_71 == 1 && V_57 -> V_71 == 1 ) {
struct V_72 * V_73 ;
struct V_72 * V_74 ;
V_73 = F_34 ( V_58 -> V_75 [ 0 ] ) ;
V_74 = F_34 ( V_57 -> V_75 [ 0 ] ) ;
F_33 ( V_2 ,
V_73 -> V_76 == V_74 -> V_76 ) ;
}
#endif
if ( V_61 == V_59 && V_49 == V_60 )
V_64 = V_65 = V_47 ;
else if ( V_61 == V_59 ) {
V_64 = V_61 + V_49 ;
V_66 = V_60 - V_49 ;
V_65 = V_47 ;
} else if ( V_61 + V_49 == V_59 + V_60 ) {
V_64 = V_59 ;
V_66 = V_60 - V_49 ;
V_65 = V_47 ;
} else {
V_64 = V_59 ;
V_66 = V_61 - V_59 ;
V_65 = V_61 + V_49 ;
V_67 = ( V_59 + V_60 ) - V_65 ;
}
if ( ( error = F_35 ( V_57 , & V_63 ) ) )
return error ;
F_33 ( V_2 , V_63 == 1 ) ;
if ( V_64 != V_47 ) {
if ( ( error = F_13 ( V_57 , V_64 , V_66 , & V_63 ) ) )
return error ;
F_33 ( V_2 , V_63 == 0 ) ;
if ( ( error = F_36 ( V_57 , & V_63 ) ) )
return error ;
F_33 ( V_2 , V_63 == 1 ) ;
}
if ( V_65 != V_47 ) {
if ( ( error = F_13 ( V_57 , V_65 , V_67 , & V_63 ) ) )
return error ;
F_33 ( V_2 , V_63 == 0 ) ;
if ( ( error = F_36 ( V_57 , & V_63 ) ) )
return error ;
F_33 ( V_2 , V_63 == 1 ) ;
}
if ( V_64 == V_47 ) {
if ( ( error = F_35 ( V_58 , & V_63 ) ) )
return error ;
F_33 ( V_2 , V_63 == 1 ) ;
} else {
if ( ( error = F_17 ( V_58 , V_64 , V_66 ) ) )
return error ;
}
if ( V_65 != V_47 ) {
if ( ( error = F_13 ( V_58 , V_65 , V_67 , & V_63 ) ) )
return error ;
F_33 ( V_2 , V_63 == 0 ) ;
if ( ( error = F_36 ( V_58 , & V_63 ) ) )
return error ;
F_33 ( V_2 , V_63 == 1 ) ;
}
return 0 ;
}
static bool
F_37 (
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_79 -> V_80 ;
struct V_81 * V_82 = F_38 ( V_78 ) ;
int V_63 ;
if ( ! F_39 ( & V_82 -> V_83 , & V_2 -> V_3 . V_84 ) )
return false ;
if ( F_22 ( V_82 -> V_85 ) != V_86 )
return false ;
if ( V_78 -> V_87 && F_22 ( V_82 -> V_88 ) != V_78 -> V_87 -> V_89 )
return false ;
for ( V_63 = 0 ; V_63 < F_40 ( V_2 ) ; V_63 ++ ) {
if ( F_22 ( V_82 -> V_90 [ V_63 ] ) != V_47 &&
F_22 ( V_82 -> V_90 [ V_63 ] ) >= V_2 -> V_3 . V_7 )
return false ;
}
return F_41 ( V_2 ,
F_42 ( F_38 ( V_78 ) -> V_91 ) ) ;
}
static void
F_43 (
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_79 -> V_80 ;
if ( ! F_44 ( & V_2 -> V_3 ) )
return;
if ( ! F_45 ( V_78 , V_92 ) )
F_46 ( V_78 , - V_93 ) ;
else if ( ! F_37 ( V_78 ) )
F_46 ( V_78 , - V_94 ) ;
if ( V_78 -> V_95 )
F_47 ( V_78 ) ;
}
static void
F_48 (
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_79 -> V_80 ;
struct V_96 * V_97 = V_78 -> V_98 ;
if ( ! F_44 ( & V_2 -> V_3 ) )
return;
if ( ! F_37 ( V_78 ) ) {
F_46 ( V_78 , - V_94 ) ;
F_47 ( V_78 ) ;
return;
}
if ( V_97 )
F_38 ( V_78 ) -> V_91 = F_49 ( V_97 -> V_99 . V_100 ) ;
F_50 ( V_78 , V_92 ) ;
}
STATIC int
F_51 (
T_5 * V_2 ,
T_6 * V_101 ,
T_7 V_102 ,
T_8 * * V_103 )
{
T_8 * V_78 ;
int error ;
ASSERT ( V_102 != V_104 ) ;
error = F_52 (
V_2 , V_101 , V_2 -> V_105 ,
F_53 ( V_2 , V_102 , F_54 ( V_2 ) ) ,
F_12 ( V_2 , 1 ) , 0 , & V_78 , & V_106 ) ;
if ( error )
return error ;
F_55 ( V_78 , V_107 ) ;
* V_103 = V_78 ;
return 0 ;
}
STATIC int
F_56 (
struct V_108 * V_101 ,
struct V_109 * V_53 ,
struct V_77 * V_110 ,
long V_11 )
{
struct V_111 * V_112 = F_57 ( V_110 ) ;
V_53 -> V_54 += V_11 ;
F_58 ( & V_112 -> V_113 , V_11 ) ;
F_59 ( V_101 , V_11 ) ;
if ( F_60 ( F_22 ( V_112 -> V_113 ) >
F_22 ( V_112 -> V_114 ) ) )
return - V_94 ;
F_61 ( V_101 , V_110 , V_115 ) ;
return 0 ;
}
STATIC int
F_62 (
T_3 * args )
{
int error = 0 ;
ASSERT ( args -> V_32 > 0 ) ;
ASSERT ( args -> V_52 > 0 ) ;
ASSERT ( args -> V_32 <= args -> V_52 ) ;
ASSERT ( args -> V_50 < args -> V_51 ) ;
ASSERT ( args -> V_31 > 0 ) ;
args -> V_116 = 0 ;
switch ( args -> type ) {
case V_117 :
error = F_63 ( args ) ;
break;
case V_118 :
error = F_64 ( args ) ;
break;
case V_119 :
error = F_65 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error || args -> V_120 == V_47 )
return error ;
ASSERT ( args -> V_11 >= args -> V_32 ) ;
ASSERT ( args -> V_11 <= args -> V_52 ) ;
ASSERT ( ! args -> V_116 || args -> V_121 != V_122 ) ;
ASSERT ( args -> V_120 % args -> V_31 == 0 ) ;
if ( args -> V_123 . V_124 != V_125 ) {
error = F_66 ( args -> V_101 , args -> V_110 , args -> V_102 ,
args -> V_120 , args -> V_11 , & args -> V_123 ) ;
if ( error )
return error ;
}
if ( ! args -> V_116 ) {
error = F_56 ( args -> V_101 , args -> V_53 ,
args -> V_110 ,
- ( ( long ) ( args -> V_11 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_67 ( args -> V_2 , args -> V_102 ,
args -> V_120 , args -> V_11 ) ) ;
}
F_68 ( args -> V_53 , args -> V_121 , args ) ;
F_69 ( args -> V_2 , V_126 ) ;
F_70 ( args -> V_2 , V_127 , args -> V_11 ) ;
return error ;
}
STATIC int
F_65 (
T_3 * args )
{
T_4 * V_58 ;
T_4 * V_57 ;
int error ;
T_2 V_59 ;
T_1 V_60 ;
T_2 V_128 ;
T_1 V_129 ;
T_2 V_130 ;
int V_63 ;
unsigned V_27 ;
ASSERT ( args -> V_31 == 1 ) ;
V_58 = F_71 ( args -> V_2 , args -> V_101 , args -> V_110 ,
args -> V_102 , V_131 ) ;
error = F_16 ( V_58 , args -> V_120 , args -> V_32 , & V_63 ) ;
if ( error )
goto V_132;
if ( ! V_63 )
goto V_133;
error = F_20 ( V_58 , & V_59 , & V_60 , & V_63 ) ;
if ( error )
goto V_132;
F_72 ( args -> V_2 , V_63 == 1 , V_132 ) ;
ASSERT ( V_59 <= args -> V_120 ) ;
V_128 = V_59 ;
V_129 = V_60 ;
F_24 ( args , & V_128 , & V_129 , & V_27 ) ;
if ( V_128 > args -> V_120 )
goto V_133;
if ( V_129 < args -> V_32 )
goto V_133;
V_130 = V_128 + V_129 ;
if ( V_130 < args -> V_120 + args -> V_32 )
goto V_133;
args -> V_11 = F_73 ( V_130 , args -> V_120 + args -> V_52 )
- args -> V_120 ;
F_30 ( args ) ;
ASSERT ( args -> V_120 + args -> V_11 <= V_130 ) ;
V_57 = F_71 ( args -> V_2 , args -> V_101 , args -> V_110 ,
args -> V_102 , V_134 ) ;
ASSERT ( args -> V_120 + args -> V_11 <=
F_22 ( F_57 ( args -> V_110 ) -> V_114 ) ) ;
error = F_31 ( V_57 , V_58 , V_59 , V_60 , args -> V_120 ,
args -> V_11 , V_70 ) ;
if ( error ) {
F_74 ( V_57 , V_135 ) ;
goto V_132;
}
F_74 ( V_58 , V_136 ) ;
F_74 ( V_57 , V_136 ) ;
args -> V_116 = 0 ;
F_75 ( args ) ;
return 0 ;
V_133:
F_74 ( V_58 , V_136 ) ;
args -> V_120 = V_47 ;
F_76 ( args ) ;
return 0 ;
V_132:
F_74 ( V_58 , V_135 ) ;
F_77 ( args ) ;
return error ;
}
STATIC int
F_78 (
struct V_137 * args ,
struct V_8 * * V_138 ,
struct V_8 * * V_139 ,
T_2 V_140 ,
T_2 * V_141 ,
T_1 * V_142 ,
T_2 * V_143 ,
T_1 * V_144 ,
int V_145 )
{
T_2 V_146 ;
T_2 V_147 ;
int error ;
int V_63 ;
unsigned V_27 ;
if ( ! V_140 )
goto V_148;
do {
error = F_20 ( * V_139 , V_141 , V_142 , & V_63 ) ;
if ( error )
goto V_132;
F_72 ( args -> V_2 , V_63 == 1 , V_132 ) ;
F_23 ( args , * V_141 , * V_142 ,
V_143 , V_144 , & V_27 ) ;
if ( ! V_145 ) {
if ( * V_143 > args -> V_149 )
goto V_148;
if ( * V_143 >= args -> V_120 + V_140 )
goto V_148;
} else {
if ( * V_143 < args -> V_30 )
goto V_148;
if ( * V_143 <= args -> V_120 - V_140 )
goto V_148;
}
if ( * V_144 >= args -> V_32 ) {
args -> V_11 = F_28 ( * V_144 , args -> V_52 ) ;
F_30 ( args ) ;
V_147 = F_26 ( args -> V_120 , args -> V_11 ,
args -> V_31 ,
args -> V_36 , * V_143 ,
* V_144 , & V_146 ) ;
if ( V_147 < V_140 )
goto V_150;
goto V_148;
}
if ( ! V_145 )
error = F_79 ( * V_139 , 0 , & V_63 ) ;
else
error = F_80 ( * V_139 , 0 , & V_63 ) ;
if ( error )
goto V_132;
} while ( V_63 );
V_148:
F_74 ( * V_139 , V_136 ) ;
* V_139 = NULL ;
return 0 ;
V_150:
F_74 ( * V_138 , V_136 ) ;
* V_138 = NULL ;
return 0 ;
V_132:
return error ;
}
STATIC int
F_64 (
T_3 * args )
{
T_4 * V_151 ;
T_4 * V_152 ;
T_4 * V_57 ;
T_2 V_153 ;
T_2 V_154 ;
T_1 V_155 ;
T_1 V_156 ;
T_1 V_157 ;
T_2 V_158 ;
int error ;
int V_63 ;
int V_159 ;
T_2 V_160 ;
T_2 V_161 ;
T_1 V_162 ;
T_1 V_163 ;
T_1 V_164 ;
T_2 V_165 ;
T_1 V_49 ;
bool V_29 ;
unsigned V_27 ;
#ifdef F_32
int V_166 ;
V_166 = F_81 () & 1 ;
#endif
if ( ! args -> V_30 && ! args -> V_149 )
args -> V_149 = args -> V_2 -> V_3 . V_7 - 1 ;
ASSERT ( args -> V_30 <= args -> V_149 ) ;
if ( args -> V_120 < args -> V_30 )
args -> V_120 = args -> V_30 ;
if ( args -> V_120 > args -> V_149 )
args -> V_120 = args -> V_149 ;
V_167:
V_152 = NULL ;
V_151 = NULL ;
V_163 = 0 ;
V_157 = 0 ;
V_164 = 0 ;
V_29 = false ;
V_57 = F_71 ( args -> V_2 , args -> V_101 , args -> V_110 ,
args -> V_102 , V_134 ) ;
if ( ( error = F_15 ( V_57 , 0 , args -> V_52 , & V_63 ) ) )
goto V_132;
if ( ! V_63 ) {
if ( ( error = F_82 ( args , V_57 , & V_160 ,
& V_163 , & V_63 ) ) )
goto V_132;
if ( V_63 == 0 || V_163 == 0 ) {
F_74 ( V_57 , V_136 ) ;
F_83 ( args ) ;
return 0 ;
}
ASSERT ( V_63 == 1 ) ;
}
args -> V_116 = 0 ;
while ( F_84 ( V_57 , 0 ) ) {
T_1 V_168 ;
int V_169 = 0 ;
T_1 V_170 = 0 ;
T_2 V_171 = 0 ;
#ifdef F_32
if ( V_166 )
break;
#endif
if ( V_163 || args -> V_31 > 1 ) {
V_57 -> V_172 [ 0 ] = 1 ;
do {
if ( ( error = F_20 ( V_57 , & V_160 ,
& V_163 , & V_63 ) ) )
goto V_132;
F_72 ( args -> V_2 , V_63 == 1 , V_132 ) ;
if ( V_163 >= args -> V_32 )
break;
if ( ( error = F_79 ( V_57 , 0 , & V_63 ) ) )
goto V_132;
} while ( V_63 );
ASSERT ( V_163 >= args -> V_32 ) ;
if ( ! V_63 )
break;
}
V_63 = V_57 -> V_172 [ 0 ] ;
for ( V_159 = 1 , V_170 = 0 , V_168 = 0 ;
! error && V_159 && ( V_170 < args -> V_52 || V_168 > 0 ) ;
error = F_79 ( V_57 , 0 , & V_159 ) ) {
if ( ( error = F_20 ( V_57 , & V_160 , & V_163 , & V_63 ) ) )
goto V_132;
F_72 ( args -> V_2 , V_63 == 1 , V_132 ) ;
V_29 = F_23 ( args , V_160 , V_163 ,
& V_161 , & V_164 , & V_27 ) ;
if ( V_164 < args -> V_32 )
continue;
if ( V_161 < args -> V_30 || V_161 > args -> V_149 )
continue;
args -> V_11 = F_28 ( V_164 , args -> V_52 ) ;
F_30 ( args ) ;
ASSERT ( args -> V_11 >= args -> V_32 ) ;
if ( args -> V_11 < V_170 )
continue;
V_162 = F_26 ( args -> V_120 , args -> V_11 ,
args -> V_31 , args -> V_36 , V_161 ,
V_164 , & V_165 ) ;
if ( V_165 != V_47 &&
( args -> V_11 > V_170 || V_162 < V_168 ) ) {
V_168 = V_162 ;
V_171 = V_165 ;
V_170 = args -> V_11 ;
V_169 = V_57 -> V_172 [ 0 ] ;
}
}
if ( V_170 == 0 )
break;
V_57 -> V_172 [ 0 ] = V_169 ;
if ( ( error = F_20 ( V_57 , & V_160 , & V_163 , & V_63 ) ) )
goto V_132;
F_72 ( args -> V_2 , V_63 == 1 , V_132 ) ;
ASSERT ( V_160 + V_163 <= F_22 ( F_57 ( args -> V_110 ) -> V_114 ) ) ;
args -> V_11 = V_170 ;
args -> V_120 = V_171 ;
ASSERT ( V_171 >= V_160 ) ;
ASSERT ( V_171 + V_170 <= V_160 + V_163 ) ;
V_152 = F_71 ( args -> V_2 , args -> V_101 ,
args -> V_110 , args -> V_102 , V_131 ) ;
if ( ( error = F_31 ( V_57 , V_152 , V_160 ,
V_163 , V_171 , V_170 , V_69 ) ) )
goto V_132;
F_74 ( V_57 , V_136 ) ;
F_74 ( V_152 , V_136 ) ;
F_85 ( args ) ;
return 0 ;
}
V_152 = F_71 ( args -> V_2 , args -> V_101 , args -> V_110 ,
args -> V_102 , V_131 ) ;
if ( ( error = F_16 ( V_152 , args -> V_120 , args -> V_52 , & V_63 ) ) )
goto V_132;
if ( ! V_63 ) {
V_151 = V_152 ;
V_152 = NULL ;
}
else if ( ( error = F_86 ( V_152 , & V_151 ) ) )
goto V_132;
if ( ( error = F_79 ( V_151 , 0 , & V_63 ) ) )
goto V_132;
if ( ! V_63 ) {
F_74 ( V_151 , V_136 ) ;
V_151 = NULL ;
}
do {
if ( V_152 ) {
if ( ( error = F_20 ( V_152 , & V_160 , & V_163 , & V_63 ) ) )
goto V_132;
F_72 ( args -> V_2 , V_63 == 1 , V_132 ) ;
V_29 |= F_23 ( args , V_160 , V_163 ,
& V_161 , & V_164 , & V_27 ) ;
if ( V_164 >= args -> V_32 && V_161 >= args -> V_30 )
break;
if ( ( error = F_80 ( V_152 , 0 , & V_63 ) ) )
goto V_132;
if ( ! V_63 || V_161 < args -> V_30 ) {
F_74 ( V_152 ,
V_136 ) ;
V_152 = NULL ;
}
}
if ( V_151 ) {
if ( ( error = F_20 ( V_151 , & V_153 , & V_156 , & V_63 ) ) )
goto V_132;
F_72 ( args -> V_2 , V_63 == 1 , V_132 ) ;
V_29 |= F_23 ( args , V_153 , V_156 ,
& V_154 , & V_157 , & V_27 ) ;
if ( V_157 >= args -> V_32 && V_154 <= args -> V_149 )
break;
if ( ( error = F_79 ( V_151 , 0 , & V_63 ) ) )
goto V_132;
if ( ! V_63 || V_154 > args -> V_149 ) {
F_74 ( V_151 ,
V_136 ) ;
V_151 = NULL ;
}
}
} while ( V_152 || V_151 );
if ( V_152 && V_151 ) {
if ( V_164 >= args -> V_32 ) {
args -> V_11 = F_28 ( V_164 , args -> V_52 ) ;
F_30 ( args ) ;
V_162 = F_26 ( args -> V_120 , args -> V_11 ,
args -> V_31 , args -> V_36 , V_161 ,
V_164 , & V_165 ) ;
error = F_78 ( args ,
& V_152 , & V_151 ,
V_162 , & V_153 , & V_156 ,
& V_154 , & V_157 ,
0 ) ;
} else {
ASSERT ( V_157 >= args -> V_32 ) ;
args -> V_11 = F_28 ( V_157 , args -> V_52 ) ;
F_30 ( args ) ;
V_155 = F_26 ( args -> V_120 , args -> V_11 ,
args -> V_31 , args -> V_36 , V_154 ,
V_157 , & V_158 ) ;
error = F_78 ( args ,
& V_151 , & V_152 ,
V_155 , & V_160 , & V_163 ,
& V_161 , & V_164 ,
1 ) ;
}
if ( error )
goto V_132;
}
if ( V_152 == NULL && V_151 == NULL ) {
F_74 ( V_57 , V_136 ) ;
if ( V_29 ) {
F_87 ( args ) ;
F_88 ( args -> V_2 , args -> V_53 , V_27 ) ;
goto V_167;
}
F_89 ( args ) ;
args -> V_120 = V_47 ;
return 0 ;
}
if ( V_151 ) {
V_152 = V_151 ;
V_151 = NULL ;
V_160 = V_153 ;
V_161 = V_154 ;
V_163 = V_156 ;
V_164 = V_157 ;
V_159 = 1 ;
} else
V_159 = 0 ;
args -> V_11 = F_28 ( V_164 , args -> V_52 ) ;
F_30 ( args ) ;
V_49 = args -> V_11 ;
( void ) F_26 ( args -> V_120 , V_49 , args -> V_31 ,
args -> V_36 , V_161 , V_164 , & V_165 ) ;
ASSERT ( V_165 >= V_160 ) ;
ASSERT ( V_165 + V_49 <= V_161 + V_164 ) ;
ASSERT ( V_165 + V_49 <= F_22 ( F_57 ( args -> V_110 ) -> V_114 ) ) ;
ASSERT ( V_165 >= args -> V_30 && V_165 <= args -> V_149 ) ;
args -> V_120 = V_165 ;
if ( ( error = F_31 ( V_57 , V_152 , V_160 , V_163 ,
V_165 , V_49 , V_70 ) ) )
goto V_132;
if ( V_159 )
F_90 ( args ) ;
else
F_91 ( args ) ;
F_74 ( V_57 , V_136 ) ;
F_74 ( V_152 , V_136 ) ;
return 0 ;
V_132:
F_92 ( args ) ;
if ( V_57 != NULL )
F_74 ( V_57 , V_135 ) ;
if ( V_152 != NULL )
F_74 ( V_152 , V_135 ) ;
if ( V_151 != NULL )
F_74 ( V_151 , V_135 ) ;
return error ;
}
STATIC int
F_63 (
T_3 * args )
{
T_4 * V_58 ;
T_4 * V_57 ;
int error ;
T_2 V_59 ;
T_1 V_60 ;
int V_63 ;
T_2 V_61 ;
T_1 V_49 ;
bool V_29 ;
unsigned V_27 ;
V_167:
V_57 = F_71 ( args -> V_2 , args -> V_101 , args -> V_110 ,
args -> V_102 , V_134 ) ;
V_58 = NULL ;
V_29 = false ;
if ( ( error = F_15 ( V_57 , 0 ,
args -> V_52 + args -> V_31 - 1 , & V_63 ) ) )
goto V_132;
if ( ! V_63 ) {
error = F_82 ( args , V_57 ,
& V_59 , & V_60 , & V_63 ) ;
if ( error )
goto V_132;
if ( V_63 == 0 || V_60 == 0 ) {
F_74 ( V_57 , V_136 ) ;
F_93 ( args ) ;
return 0 ;
}
ASSERT ( V_63 == 1 ) ;
V_29 = F_23 ( args , V_59 , V_60 , & V_61 ,
& V_49 , & V_27 ) ;
} else {
for (; ; ) {
error = F_20 ( V_57 , & V_59 , & V_60 , & V_63 ) ;
if ( error )
goto V_132;
F_72 ( args -> V_2 , V_63 == 1 , V_132 ) ;
V_29 = F_23 ( args , V_59 , V_60 ,
& V_61 , & V_49 , & V_27 ) ;
if ( V_49 >= args -> V_52 )
break;
error = F_79 ( V_57 , 0 , & V_63 ) ;
if ( error )
goto V_132;
if ( V_63 == 0 ) {
F_74 ( V_57 ,
V_136 ) ;
F_94 ( args ) ;
F_88 ( args -> V_2 ,
args -> V_53 , V_27 ) ;
goto V_167;
}
}
}
V_49 = F_28 ( args -> V_52 , V_49 ) ;
F_72 ( args -> V_2 , V_49 == 0 ||
( V_49 <= V_60 && V_61 + V_49 <= V_59 + V_60 ) , V_132 ) ;
if ( V_49 < args -> V_52 ) {
T_2 V_173 ;
T_1 V_174 ;
T_2 V_175 ;
T_1 V_176 ;
V_176 = V_49 ;
V_175 = V_61 ;
V_174 = V_60 ;
V_173 = V_59 ;
for (; ; ) {
if ( ( error = F_80 ( V_57 , 0 , & V_63 ) ) )
goto V_132;
if ( V_63 == 0 )
break;
if ( ( error = F_20 ( V_57 , & V_59 , & V_60 ,
& V_63 ) ) )
goto V_132;
F_72 ( args -> V_2 , V_63 == 1 , V_132 ) ;
if ( V_60 < V_176 )
break;
V_29 = F_23 ( args , V_59 , V_60 ,
& V_61 , & V_49 , & V_27 ) ;
V_49 = F_28 ( args -> V_52 , V_49 ) ;
F_72 ( args -> V_2 , V_49 == 0 ||
( V_49 <= V_60 && V_61 + V_49 <= V_59 + V_60 ) ,
V_132 ) ;
if ( V_49 > V_176 ) {
V_176 = V_49 ;
V_175 = V_61 ;
V_174 = V_60 ;
V_173 = V_59 ;
if ( V_49 == args -> V_52 )
break;
}
}
if ( ( error = F_13 ( V_57 , V_173 , V_174 ,
& V_63 ) ) )
goto V_132;
F_72 ( args -> V_2 , V_63 == 1 , V_132 ) ;
V_49 = V_176 ;
V_61 = V_175 ;
V_60 = V_174 ;
V_59 = V_173 ;
}
args -> V_116 = 0 ;
args -> V_11 = V_49 ;
if ( V_49 < args -> V_32 ) {
if ( V_29 ) {
F_74 ( V_57 , V_136 ) ;
F_94 ( args ) ;
F_88 ( args -> V_2 , args -> V_53 , V_27 ) ;
goto V_167;
}
goto V_177;
}
F_30 ( args ) ;
V_49 = args -> V_11 ;
F_72 ( args -> V_2 , V_49 <= V_60 , V_132 ) ;
V_58 = F_71 ( args -> V_2 , args -> V_101 , args -> V_110 ,
args -> V_102 , V_131 ) ;
if ( ( error = F_31 ( V_57 , V_58 , V_59 , V_60 ,
V_61 , V_49 , V_69 ) ) )
goto V_132;
F_74 ( V_57 , V_136 ) ;
F_74 ( V_58 , V_136 ) ;
V_57 = V_58 = NULL ;
args -> V_11 = V_49 ;
args -> V_120 = V_61 ;
F_72 ( args -> V_2 ,
args -> V_120 + args -> V_11 <=
F_22 ( F_57 ( args -> V_110 ) -> V_114 ) ,
V_132 ) ;
F_95 ( args ) ;
return 0 ;
V_132:
F_96 ( args ) ;
if ( V_57 )
F_74 ( V_57 , V_135 ) ;
if ( V_58 )
F_74 ( V_58 , V_135 ) ;
return error ;
V_177:
F_74 ( V_57 , V_136 ) ;
F_97 ( args ) ;
args -> V_120 = V_47 ;
return 0 ;
}
STATIC int
F_82 (
T_3 * args ,
T_4 * V_178 ,
T_2 * V_179 ,
T_1 * V_180 ,
int * V_12 )
{
struct V_181 V_123 ;
struct V_109 * V_53 ;
int error ;
T_2 V_59 ;
T_1 V_60 ;
int V_63 ;
if ( ( error = F_80 ( V_178 , 0 , & V_63 ) ) )
goto V_132;
if ( V_63 ) {
if ( ( error = F_20 ( V_178 , & V_59 , & V_60 , & V_63 ) ) )
goto V_132;
F_72 ( args -> V_2 , V_63 == 1 , V_132 ) ;
}
else if ( args -> V_32 == 1 && args -> V_31 == 1 &&
args -> V_121 != V_122 &&
( F_22 ( F_57 ( args -> V_110 ) -> V_182 )
> args -> V_56 ) ) {
error = F_98 ( args -> V_101 , args -> V_110 , & V_59 , 0 ) ;
if ( error )
goto V_132;
if ( V_59 != V_47 ) {
F_99 ( args -> V_2 , args -> V_102 , V_59 , 1 ,
F_100 ( args -> V_36 ) ) ;
if ( F_27 ( args -> V_36 ) ) {
T_8 * V_78 ;
V_78 = F_101 ( args -> V_2 , args -> V_101 ,
args -> V_102 , V_59 , 0 ) ;
F_102 ( args -> V_101 , V_78 ) ;
}
args -> V_11 = 1 ;
args -> V_120 = V_59 ;
F_72 ( args -> V_2 ,
args -> V_120 + args -> V_11 <=
F_22 ( F_57 ( args -> V_110 ) -> V_114 ) ,
V_132 ) ;
args -> V_116 = 1 ;
F_103 ( args ) ;
F_104 ( & V_123 , V_183 ) ;
error = F_105 ( args -> V_101 , args -> V_110 , args -> V_102 ,
V_59 , 1 , & V_123 ) ;
if ( error )
goto V_132;
V_53 = F_106 ( args -> V_2 , args -> V_102 ) ;
F_107 ( V_53 , V_122 ,
args -> V_101 , 1 ) ;
F_108 ( V_53 ) ;
* V_12 = 0 ;
return 0 ;
}
else
V_60 = 0 ;
}
else {
V_59 = V_47 ;
V_60 = 0 ;
}
if ( V_60 < args -> V_32 ) {
args -> V_120 = V_47 ;
F_109 ( args ) ;
V_60 = 0 ;
}
* V_179 = V_59 ;
* V_180 = V_60 ;
* V_12 = 1 ;
F_110 ( args ) ;
return 0 ;
V_132:
F_111 ( args ) ;
return error ;
}
STATIC int
F_112 (
T_6 * V_101 ,
T_8 * V_110 ,
T_7 V_102 ,
T_2 V_10 ,
T_1 V_11 ,
struct V_181 * V_123 ,
enum V_184 type )
{
T_4 * V_58 ;
T_4 * V_57 ;
int error ;
T_2 V_153 ;
T_1 V_156 ;
int V_185 ;
int V_186 ;
int V_63 ;
T_2 V_160 ;
T_1 V_163 ;
T_5 * V_2 ;
T_2 V_187 ;
T_1 V_188 ;
T_9 * V_53 ;
V_58 = V_57 = NULL ;
V_2 = V_101 -> V_189 ;
if ( V_123 -> V_124 != V_125 ) {
error = F_105 ( V_101 , V_110 , V_102 , V_10 , V_11 , V_123 ) ;
if ( error )
goto V_132;
}
V_58 = F_71 ( V_2 , V_101 , V_110 , V_102 , V_131 ) ;
if ( ( error = F_16 ( V_58 , V_10 , V_11 , & V_185 ) ) )
goto V_132;
if ( V_185 ) {
if ( ( error = F_20 ( V_58 , & V_160 , & V_163 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
if ( V_160 + V_163 < V_10 )
V_185 = 0 ;
else {
F_72 ( V_2 ,
V_160 + V_163 <= V_10 , V_132 ) ;
}
}
if ( ( error = F_79 ( V_58 , 0 , & V_186 ) ) )
goto V_132;
if ( V_186 ) {
if ( ( error = F_20 ( V_58 , & V_153 , & V_156 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
if ( V_10 + V_11 < V_153 )
V_186 = 0 ;
else {
F_72 ( V_2 , V_153 >= V_10 + V_11 , V_132 ) ;
}
}
V_57 = F_71 ( V_2 , V_101 , V_110 , V_102 , V_134 ) ;
if ( V_185 && V_186 ) {
if ( ( error = F_13 ( V_57 , V_160 , V_163 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
if ( ( error = F_35 ( V_57 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
if ( ( error = F_13 ( V_57 , V_153 , V_156 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
if ( ( error = F_35 ( V_57 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
if ( ( error = F_35 ( V_58 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
if ( ( error = F_80 ( V_58 , 0 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
#ifdef F_32
{
T_2 V_190 ;
T_1 V_191 ;
if ( ( error = F_20 ( V_58 , & V_190 , & V_191 ,
& V_63 ) ) )
goto V_132;
F_72 ( V_2 ,
V_63 == 1 && V_190 == V_160 && V_191 == V_163 ,
V_132 ) ;
}
#endif
V_187 = V_160 ;
V_188 = V_11 + V_163 + V_156 ;
if ( ( error = F_17 ( V_58 , V_187 , V_188 ) ) )
goto V_132;
}
else if ( V_185 ) {
if ( ( error = F_13 ( V_57 , V_160 , V_163 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
if ( ( error = F_35 ( V_57 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
if ( ( error = F_80 ( V_58 , 0 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
V_187 = V_160 ;
V_188 = V_11 + V_163 ;
if ( ( error = F_17 ( V_58 , V_187 , V_188 ) ) )
goto V_132;
}
else if ( V_186 ) {
if ( ( error = F_13 ( V_57 , V_153 , V_156 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
if ( ( error = F_35 ( V_57 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
V_187 = V_10 ;
V_188 = V_11 + V_156 ;
if ( ( error = F_17 ( V_58 , V_187 , V_188 ) ) )
goto V_132;
}
else {
V_187 = V_10 ;
V_188 = V_11 ;
if ( ( error = F_36 ( V_58 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
}
F_74 ( V_58 , V_136 ) ;
V_58 = NULL ;
if ( ( error = F_13 ( V_57 , V_187 , V_188 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 0 , V_132 ) ;
if ( ( error = F_36 ( V_57 , & V_63 ) ) )
goto V_132;
F_72 ( V_2 , V_63 == 1 , V_132 ) ;
F_74 ( V_57 , V_136 ) ;
V_57 = NULL ;
V_53 = F_106 ( V_2 , V_102 ) ;
error = F_56 ( V_101 , V_53 , V_110 , V_11 ) ;
F_107 ( V_53 , type , V_101 , V_11 ) ;
F_108 ( V_53 ) ;
if ( error )
goto V_132;
F_69 ( V_2 , V_192 ) ;
F_70 ( V_2 , V_193 , V_11 ) ;
F_113 ( V_2 , V_102 , V_10 , V_11 , type == V_122 ,
V_185 , V_186 ) ;
return 0 ;
V_132:
F_113 ( V_2 , V_102 , V_10 , V_11 , type == V_122 ,
- 1 , - 1 ) ;
if ( V_58 )
F_74 ( V_58 , V_135 ) ;
if ( V_57 )
F_74 ( V_57 , V_135 ) ;
return error ;
}
void
F_114 (
T_5 * V_2 )
{
V_2 -> V_194 = F_115 ( V_2 , V_2 -> V_195 ,
( V_2 -> V_3 . V_7 + 1 ) / 2 ) ;
}
T_1
F_116 (
struct V_1 * V_2 ,
struct V_109 * V_53 ,
T_1 V_196 ,
T_1 V_197 )
{
T_1 V_198 = 0 ;
if ( V_196 > V_53 -> V_55 )
V_198 = V_196 - V_53 -> V_55 ;
if ( V_53 -> V_54 - V_53 -> V_199 < V_197 )
V_198 += V_197 - ( V_53 -> V_54 - V_53 -> V_199 ) ;
if ( V_53 -> V_199 > V_198 )
return V_53 -> V_199 - V_198 ;
return V_53 -> V_55 > 0 || V_53 -> V_199 > 0 ;
}
unsigned int
F_117 (
struct V_1 * V_2 ,
struct V_109 * V_53 )
{
unsigned int V_200 ;
V_200 = F_118 (unsigned int, pag->pagf_levels[XFS_BTNUM_BNOi] + 1 ,
mp->m_ag_maxlevels) ;
V_200 += F_118 (unsigned int, pag->pagf_levels[XFS_BTNUM_CNTi] + 1 ,
mp->m_ag_maxlevels) ;
if ( F_2 ( & V_2 -> V_3 ) )
V_200 += F_118 (unsigned int,
pag->pagf_levels[XFS_BTNUM_RMAPi] + 1 ,
mp->m_rmap_maxlevels) ;
return V_200 ;
}
static bool
F_119 (
struct V_137 * args ,
T_1 V_200 ,
int V_62 )
{
struct V_109 * V_53 = args -> V_53 ;
T_1 V_201 , V_202 ;
T_1 V_203 ;
int V_204 ;
if ( V_62 & V_205 )
return true ;
V_203 = F_120 ( V_53 , args -> V_121 ) ;
V_201 = args -> V_32 + ( args -> V_31 - 1 ) + args -> V_206 ;
V_202 = F_116 ( args -> V_2 , V_53 , V_200 ,
V_203 ) ;
if ( V_202 < V_201 )
return false ;
V_204 = ( int ) ( V_53 -> V_54 + V_53 -> V_55 -
V_203 - V_200 - args -> V_56 ) ;
if ( V_204 < ( int ) F_121 ( args -> V_207 , V_201 ) )
return false ;
if ( V_204 < ( int ) args -> V_52 && ! ( V_62 & V_208 ) ) {
args -> V_52 = V_204 ;
ASSERT ( args -> V_52 > 0 ) ;
ASSERT ( args -> V_52 >= args -> V_32 ) ;
}
return true ;
}
int
F_122 (
struct V_137 * args ,
int V_62 )
{
struct V_1 * V_2 = args -> V_2 ;
struct V_109 * V_53 = args -> V_53 ;
struct V_108 * V_101 = args -> V_101 ;
struct V_77 * V_110 = NULL ;
struct V_77 * V_209 = NULL ;
struct V_137 V_210 ;
T_2 V_10 ;
T_1 V_196 ;
int error = 0 ;
if ( ! V_53 -> V_211 ) {
error = F_123 ( V_2 , V_101 , args -> V_102 , V_62 , & V_110 ) ;
if ( error )
goto V_212;
if ( ! V_53 -> V_211 ) {
ASSERT ( V_62 & V_213 ) ;
ASSERT ( ! ( V_62 & V_205 ) ) ;
goto V_214;
}
}
if ( V_53 -> V_215 && F_27 ( args -> V_36 ) &&
( V_62 & V_213 ) ) {
ASSERT ( ! ( V_62 & V_205 ) ) ;
goto V_214;
}
V_196 = F_117 ( V_2 , V_53 ) ;
if ( ! F_119 ( args , V_196 , V_62 |
V_208 ) )
goto V_214;
if ( ! V_110 ) {
error = F_123 ( V_2 , V_101 , args -> V_102 , V_62 , & V_110 ) ;
if ( error )
goto V_212;
if ( ! V_110 ) {
ASSERT ( V_62 & V_213 ) ;
ASSERT ( ! ( V_62 & V_205 ) ) ;
goto V_212;
}
}
V_196 = F_117 ( V_2 , V_53 ) ;
if ( ! F_119 ( args , V_196 , V_62 ) )
goto V_214;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
if ( V_62 & V_216 )
F_124 ( & V_210 . V_123 ) ;
else
F_104 ( & V_210 . V_123 , V_183 ) ;
while ( ! ( V_62 & V_217 ) && V_53 -> V_55 > V_196 ) {
struct V_77 * V_78 ;
error = F_98 ( V_101 , V_110 , & V_10 , 0 ) ;
if ( error )
goto V_214;
error = F_112 ( V_101 , V_110 , args -> V_102 , V_10 , 1 ,
& V_210 . V_123 , V_122 ) ;
if ( error )
goto V_214;
V_78 = F_101 ( V_2 , V_101 , args -> V_102 , V_10 , 0 ) ;
F_102 ( V_101 , V_78 ) ;
}
V_210 . V_101 = V_101 ;
V_210 . V_2 = V_2 ;
V_210 . V_110 = V_110 ;
V_210 . V_102 = args -> V_102 ;
V_210 . V_31 = V_210 . V_32 = V_210 . V_51 = 1 ;
V_210 . type = V_117 ;
V_210 . V_53 = V_53 ;
error = F_51 ( V_2 , V_101 , V_210 . V_102 , & V_209 ) ;
if ( error )
goto V_214;
while ( V_53 -> V_55 < V_196 ) {
V_210 . V_120 = 0 ;
V_210 . V_52 = V_196 - V_53 -> V_55 ;
V_210 . V_121 = V_122 ;
error = F_62 ( & V_210 ) ;
if ( error )
goto V_218;
if ( V_210 . V_120 == V_47 ) {
if ( V_62 & V_205 )
break;
goto V_218;
}
for ( V_10 = V_210 . V_120 ; V_10 < V_210 . V_120 + V_210 . V_11 ; V_10 ++ ) {
error = F_125 ( V_101 , V_110 ,
V_209 , V_10 , 0 ) ;
if ( error )
goto V_218;
}
}
F_126 ( V_101 , V_209 ) ;
args -> V_110 = V_110 ;
return 0 ;
V_218:
F_126 ( V_101 , V_209 ) ;
V_214:
if ( V_110 )
F_126 ( V_101 , V_110 ) ;
V_212:
args -> V_110 = NULL ;
return error ;
}
int
F_98 (
T_6 * V_101 ,
T_8 * V_110 ,
T_2 * V_219 ,
int V_220 )
{
T_10 * V_112 ;
T_8 * V_209 ;
T_2 V_10 ;
T_11 * V_90 ;
int error ;
int V_221 ;
T_5 * V_2 = V_101 -> V_189 ;
T_9 * V_53 ;
V_112 = F_57 ( V_110 ) ;
if ( ! V_112 -> V_182 ) {
* V_219 = V_47 ;
return 0 ;
}
error = F_51 ( V_2 , V_101 , F_22 ( V_112 -> V_222 ) ,
& V_209 ) ;
if ( error )
return error ;
V_90 = F_127 ( V_2 , V_209 ) ;
V_10 = F_22 ( V_90 [ F_22 ( V_112 -> V_223 ) ] ) ;
F_58 ( & V_112 -> V_223 , 1 ) ;
F_126 ( V_101 , V_209 ) ;
if ( F_22 ( V_112 -> V_223 ) == F_40 ( V_2 ) )
V_112 -> V_223 = 0 ;
V_53 = F_106 ( V_2 , F_22 ( V_112 -> V_222 ) ) ;
F_58 ( & V_112 -> V_182 , - 1 ) ;
F_128 ( V_101 , - 1 ) ;
V_53 -> V_55 -- ;
F_108 ( V_53 ) ;
V_221 = V_224 | V_225 ;
if ( V_220 ) {
F_58 ( & V_112 -> V_226 , 1 ) ;
V_53 -> V_227 ++ ;
V_221 |= V_228 ;
}
F_61 ( V_101 , V_110 , V_221 ) ;
* V_219 = V_10 ;
return 0 ;
}
void
F_61 (
T_6 * V_101 ,
T_8 * V_78 ,
int V_229 )
{
int V_230 ;
int V_231 ;
static const short V_232 [] = {
F_129 ( T_10 , V_233 ) ,
F_129 ( T_10 , V_234 ) ,
F_129 ( T_10 , V_222 ) ,
F_129 ( T_10 , V_114 ) ,
F_129 ( T_10 , V_235 [ 0 ] ) ,
F_129 ( T_10 , V_236 [ 0 ] ) ,
F_129 ( T_10 , V_223 ) ,
F_129 ( T_10 , V_237 ) ,
F_129 ( T_10 , V_182 ) ,
F_129 ( T_10 , V_113 ) ,
F_129 ( T_10 , V_238 ) ,
F_129 ( T_10 , V_226 ) ,
F_129 ( T_10 , V_239 ) ,
F_129 ( T_10 , V_240 ) ,
F_129 ( T_10 , V_241 ) ,
F_129 ( T_10 , V_242 ) ,
F_129 ( T_10 , V_243 ) ,
F_129 ( T_10 , V_244 ) ,
sizeof( T_10 )
} ;
F_130 ( V_101 -> V_189 , F_57 ( V_78 ) , V_229 , V_245 ) ;
F_131 ( V_101 , V_78 , V_246 ) ;
F_132 ( V_229 , V_232 , V_247 , & V_230 , & V_231 ) ;
F_133 ( V_101 , V_78 , ( V_248 ) V_230 , ( V_248 ) V_231 ) ;
}
int
F_134 (
T_5 * V_2 ,
T_6 * V_101 ,
T_7 V_102 ,
int V_62 )
{
T_8 * V_78 ;
int error ;
if ( ( error = F_123 ( V_2 , V_101 , V_102 , V_62 , & V_78 ) ) )
return error ;
if ( V_78 )
F_126 ( V_101 , V_78 ) ;
return 0 ;
}
int
F_125 (
T_6 * V_101 ,
T_8 * V_110 ,
T_8 * V_209 ,
T_2 V_10 ,
int V_220 )
{
T_10 * V_112 ;
T_11 * V_249 ;
int error ;
int V_221 ;
T_5 * V_2 ;
T_9 * V_53 ;
T_11 * V_90 ;
int V_250 ;
V_112 = F_57 ( V_110 ) ;
V_2 = V_101 -> V_189 ;
if ( ! V_209 && ( error = F_51 ( V_2 , V_101 ,
F_22 ( V_112 -> V_222 ) , & V_209 ) ) )
return error ;
F_58 ( & V_112 -> V_237 , 1 ) ;
if ( F_22 ( V_112 -> V_237 ) == F_40 ( V_2 ) )
V_112 -> V_237 = 0 ;
V_53 = F_106 ( V_2 , F_22 ( V_112 -> V_222 ) ) ;
F_58 ( & V_112 -> V_182 , 1 ) ;
F_128 ( V_101 , 1 ) ;
V_53 -> V_55 ++ ;
V_221 = V_251 | V_225 ;
if ( V_220 ) {
F_58 ( & V_112 -> V_226 , - 1 ) ;
V_53 -> V_227 -- ;
V_221 |= V_228 ;
}
F_108 ( V_53 ) ;
F_61 ( V_101 , V_110 , V_221 ) ;
ASSERT ( F_22 ( V_112 -> V_182 ) <= F_40 ( V_2 ) ) ;
V_90 = F_127 ( V_2 , V_209 ) ;
V_249 = & V_90 [ F_22 ( V_112 -> V_237 ) ] ;
* V_249 = F_18 ( V_10 ) ;
V_250 = ( char * ) V_249 - ( char * ) V_209 -> V_252 ;
F_61 ( V_101 , V_110 , V_221 ) ;
F_131 ( V_101 , V_209 , V_253 ) ;
F_133 ( V_101 , V_209 , V_250 ,
V_250 + sizeof( T_2 ) - 1 ) ;
return 0 ;
}
static bool
F_135 (
struct V_1 * V_2 ,
struct V_77 * V_78 )
{
struct V_111 * V_112 = F_57 ( V_78 ) ;
if ( F_44 ( & V_2 -> V_3 ) ) {
if ( ! F_39 ( & V_112 -> V_239 , & V_2 -> V_3 . V_84 ) )
return false ;
if ( ! F_41 ( V_2 ,
F_42 ( F_57 ( V_78 ) -> V_254 ) ) )
return false ;
}
if ( ! ( V_112 -> V_233 == F_18 ( V_255 ) &&
F_136 ( F_22 ( V_112 -> V_234 ) ) &&
F_22 ( V_112 -> V_113 ) <= F_22 ( V_112 -> V_114 ) &&
F_22 ( V_112 -> V_223 ) < F_40 ( V_2 ) &&
F_22 ( V_112 -> V_237 ) < F_40 ( V_2 ) &&
F_22 ( V_112 -> V_182 ) <= F_40 ( V_2 ) ) )
return false ;
if ( F_22 ( V_112 -> V_236 [ V_131 ] ) < 1 ||
F_22 ( V_112 -> V_236 [ V_134 ] ) < 1 ||
F_22 ( V_112 -> V_236 [ V_131 ] ) > V_256 ||
F_22 ( V_112 -> V_236 [ V_134 ] ) > V_256 )
return false ;
if ( F_2 ( & V_2 -> V_3 ) &&
( F_22 ( V_112 -> V_236 [ V_257 ] ) < 1 ||
F_22 ( V_112 -> V_236 [ V_257 ] ) > V_256 ) )
return false ;
if ( V_78 -> V_87 && F_22 ( V_112 -> V_222 ) != V_78 -> V_87 -> V_89 )
return false ;
if ( F_137 ( & V_2 -> V_3 ) &&
F_22 ( V_112 -> V_226 ) > F_22 ( V_112 -> V_114 ) )
return false ;
if ( F_8 ( & V_2 -> V_3 ) &&
( F_22 ( V_112 -> V_243 ) < 1 ||
F_22 ( V_112 -> V_243 ) > V_256 ) )
return false ;
return true ; ;
}
static void
F_138 (
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_79 -> V_80 ;
if ( F_44 ( & V_2 -> V_3 ) &&
! F_45 ( V_78 , V_258 ) )
F_46 ( V_78 , - V_93 ) ;
else if ( F_139 ( ! F_135 ( V_2 , V_78 ) , V_2 ,
V_259 ,
V_260 ) )
F_46 ( V_78 , - V_94 ) ;
if ( V_78 -> V_95 )
F_47 ( V_78 ) ;
}
static void
F_140 (
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_79 -> V_80 ;
struct V_96 * V_97 = V_78 -> V_98 ;
if ( ! F_135 ( V_2 , V_78 ) ) {
F_46 ( V_78 , - V_94 ) ;
F_47 ( V_78 ) ;
return;
}
if ( ! F_44 ( & V_2 -> V_3 ) )
return;
if ( V_97 )
F_57 ( V_78 ) -> V_254 = F_49 ( V_97 -> V_99 . V_100 ) ;
F_50 ( V_78 , V_258 ) ;
}
int
F_141 (
struct V_1 * V_2 ,
struct V_108 * V_101 ,
T_7 V_102 ,
int V_62 ,
struct V_77 * * V_103 )
{
int error ;
F_142 ( V_2 , V_102 ) ;
ASSERT ( V_102 != V_104 ) ;
error = F_52 (
V_2 , V_101 , V_2 -> V_105 ,
F_53 ( V_2 , V_102 , F_143 ( V_2 ) ) ,
F_12 ( V_2 , 1 ) , V_62 , V_103 , & V_261 ) ;
if ( error )
return error ;
if ( ! * V_103 )
return 0 ;
ASSERT ( ! ( * V_103 ) -> V_95 ) ;
F_55 ( * V_103 , V_262 ) ;
return 0 ;
}
int
F_123 (
struct V_1 * V_2 ,
struct V_108 * V_101 ,
T_7 V_102 ,
int V_62 ,
struct V_77 * * V_103 )
{
struct V_111 * V_112 ;
struct V_109 * V_53 ;
int error ;
F_144 ( V_2 , V_102 ) ;
ASSERT ( V_102 != V_104 ) ;
error = F_141 ( V_2 , V_101 , V_102 ,
( V_62 & V_213 ) ? V_263 : 0 ,
V_103 ) ;
if ( error )
return error ;
if ( ! * V_103 )
return 0 ;
ASSERT ( ! ( * V_103 ) -> V_95 ) ;
V_112 = F_57 ( * V_103 ) ;
V_53 = F_106 ( V_2 , V_102 ) ;
if ( ! V_53 -> V_211 ) {
V_53 -> V_54 = F_22 ( V_112 -> V_113 ) ;
V_53 -> V_227 = F_22 ( V_112 -> V_226 ) ;
V_53 -> V_55 = F_22 ( V_112 -> V_182 ) ;
V_53 -> V_199 = F_22 ( V_112 -> V_238 ) ;
V_53 -> V_264 [ V_265 ] =
F_22 ( V_112 -> V_236 [ V_265 ] ) ;
V_53 -> V_264 [ V_266 ] =
F_22 ( V_112 -> V_236 [ V_266 ] ) ;
V_53 -> V_264 [ V_267 ] =
F_22 ( V_112 -> V_236 [ V_267 ] ) ;
V_53 -> V_268 = F_22 ( V_112 -> V_243 ) ;
F_145 ( & V_53 -> V_269 ) ;
V_53 -> V_270 = 0 ;
V_53 -> V_271 = V_272 ;
V_53 -> V_211 = 1 ;
}
#ifdef F_32
else if ( ! F_146 ( V_2 ) ) {
ASSERT ( V_53 -> V_54 == F_22 ( V_112 -> V_113 ) ) ;
ASSERT ( V_53 -> V_227 == F_22 ( V_112 -> V_226 ) ) ;
ASSERT ( V_53 -> V_55 == F_22 ( V_112 -> V_182 ) ) ;
ASSERT ( V_53 -> V_199 == F_22 ( V_112 -> V_238 ) ) ;
ASSERT ( V_53 -> V_264 [ V_265 ] ==
F_22 ( V_112 -> V_236 [ V_265 ] ) ) ;
ASSERT ( V_53 -> V_264 [ V_266 ] ==
F_22 ( V_112 -> V_236 [ V_266 ] ) ) ;
}
#endif
F_108 ( V_53 ) ;
return 0 ;
}
int
F_147 (
T_3 * args )
{
T_2 V_273 ;
int error ;
int V_62 ;
T_5 * V_2 ;
T_7 V_274 ;
T_12 type ;
int V_275 = 0 ;
T_7 V_276 = V_277 ;
V_2 = args -> V_2 ;
type = args -> V_278 = args -> type ;
args -> V_120 = V_47 ;
V_273 = V_2 -> V_3 . V_7 ;
if ( args -> V_52 > V_273 )
args -> V_52 = V_273 ;
if ( args -> V_31 == 0 )
args -> V_31 = 1 ;
ASSERT ( F_148 ( V_2 , args -> V_279 ) < V_2 -> V_3 . V_4 ) ;
ASSERT ( F_149 ( V_2 , args -> V_279 ) < V_273 ) ;
ASSERT ( args -> V_32 <= args -> V_52 ) ;
ASSERT ( args -> V_32 <= V_273 ) ;
ASSERT ( args -> V_50 < args -> V_51 ) ;
if ( F_148 ( V_2 , args -> V_279 ) >= V_2 -> V_3 . V_4 ||
F_149 ( V_2 , args -> V_279 ) >= V_273 ||
args -> V_32 > args -> V_52 || args -> V_32 > V_273 ||
args -> V_50 >= args -> V_51 ) {
args -> V_279 = V_280 ;
F_150 ( args ) ;
return 0 ;
}
switch ( type ) {
case V_117 :
case V_118 :
case V_119 :
args -> V_102 = F_148 ( V_2 , args -> V_279 ) ;
args -> V_53 = F_106 ( V_2 , args -> V_102 ) ;
error = F_122 ( args , 0 ) ;
if ( error ) {
F_151 ( args ) ;
goto V_132;
}
if ( ! args -> V_110 ) {
F_152 ( args ) ;
break;
}
args -> V_120 = F_149 ( V_2 , args -> V_279 ) ;
if ( ( error = F_62 ( args ) ) )
goto V_132;
break;
case V_281 :
if ( ( args -> V_36 & V_282 ) &&
( V_2 -> V_283 & V_284 ) ) {
args -> V_279 = F_153 ( V_2 ,
( ( V_2 -> V_285 / V_276 ) %
V_2 -> V_3 . V_4 ) , 0 ) ;
V_275 = 1 ;
}
args -> V_120 = F_149 ( V_2 , args -> V_279 ) ;
args -> type = V_118 ;
case V_286 :
if ( type == V_286 ) {
args -> V_102 = F_148 ( V_2 , args -> V_279 ) ;
args -> type = V_117 ;
V_274 = 0 ;
V_62 = 0 ;
} else {
args -> V_102 = V_274 = F_148 ( V_2 , args -> V_279 ) ;
V_62 = V_213 ;
}
for (; ; ) {
args -> V_53 = F_106 ( V_2 , args -> V_102 ) ;
error = F_122 ( args , V_62 ) ;
if ( error ) {
F_151 ( args ) ;
goto V_132;
}
if ( args -> V_110 ) {
if ( ( error = F_62 ( args ) ) )
goto V_132;
break;
}
F_154 ( args ) ;
if ( args -> V_102 == V_274 &&
type == V_281 )
args -> type = V_117 ;
if ( ++ ( args -> V_102 ) == V_2 -> V_3 . V_4 ) {
if ( args -> V_287 != V_280 )
args -> V_102 = V_274 ;
else
args -> V_102 = 0 ;
}
if ( args -> V_102 == V_274 ) {
if ( V_62 == 0 ) {
args -> V_120 = V_47 ;
F_155 ( args ) ;
break;
}
V_62 = 0 ;
if ( type == V_281 ) {
args -> V_120 = F_149 ( V_2 ,
args -> V_279 ) ;
args -> type = V_118 ;
}
}
F_108 ( args -> V_53 ) ;
}
if ( V_275 ) {
if ( args -> V_102 == V_274 )
V_2 -> V_285 = ( V_2 -> V_285 + 1 ) %
( V_2 -> V_3 . V_4 * V_276 ) ;
else
V_2 -> V_285 = ( args -> V_102 * V_276 + 1 ) %
( V_2 -> V_3 . V_4 * V_276 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_120 == V_47 )
args -> V_279 = V_280 ;
else {
args -> V_279 = F_153 ( V_2 , args -> V_102 , args -> V_120 ) ;
#ifdef F_32
ASSERT ( args -> V_11 >= args -> V_32 ) ;
ASSERT ( args -> V_11 <= args -> V_52 ) ;
ASSERT ( args -> V_120 % args -> V_31 == 0 ) ;
F_156 ( V_2 , F_157 ( V_2 , args -> V_279 ) ,
args -> V_11 ) ;
#endif
if ( args -> V_36 & V_288 ) {
error = F_158 ( args -> V_289 , args -> V_279 , args -> V_11 ) ;
if ( error )
goto V_132;
}
}
F_108 ( args -> V_53 ) ;
return 0 ;
V_132:
F_108 ( args -> V_53 ) ;
return error ;
}
int
F_159 (
struct V_108 * V_101 ,
T_7 V_102 ,
struct V_77 * * V_110 )
{
struct V_137 args ;
int error ;
memset ( & args , 0 , sizeof( struct V_137 ) ) ;
args . V_101 = V_101 ;
args . V_2 = V_101 -> V_189 ;
args . V_102 = V_102 ;
if ( args . V_102 >= args . V_2 -> V_3 . V_4 )
return - V_94 ;
args . V_53 = F_106 ( args . V_2 , args . V_102 ) ;
ASSERT ( args . V_53 ) ;
error = F_122 ( & args , V_205 ) ;
if ( error )
goto V_290;
* V_110 = args . V_110 ;
V_290:
F_108 ( args . V_53 ) ;
return error ;
}
int
F_160 (
struct V_108 * V_101 ,
T_13 V_10 ,
T_1 V_11 ,
struct V_181 * V_123 ,
enum V_184 type )
{
struct V_1 * V_2 = V_101 -> V_189 ;
struct V_77 * V_110 ;
T_7 V_102 = F_148 ( V_2 , V_10 ) ;
T_2 V_120 = F_149 ( V_2 , V_10 ) ;
int error ;
ASSERT ( V_11 != 0 ) ;
ASSERT ( type != V_122 ) ;
if ( F_139 ( false , V_2 ,
V_291 ,
V_292 ) )
return - V_293 ;
error = F_159 ( V_101 , V_102 , & V_110 ) ;
if ( error )
return error ;
F_72 ( V_2 , V_120 < V_2 -> V_3 . V_7 , V_294 ) ;
F_72 ( V_2 ,
V_120 + V_11 <= F_22 ( F_57 ( V_110 ) -> V_114 ) ,
V_294 ) ;
error = F_112 ( V_101 , V_110 , V_102 , V_120 , V_11 , V_123 , type ) ;
if ( error )
goto V_294;
F_161 ( V_101 , V_102 , V_120 , V_11 , 0 ) ;
return 0 ;
V_294:
F_126 ( V_101 , V_110 ) ;
return error ;
}
