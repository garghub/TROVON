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
ASSERT ( args -> V_51 -> V_52 + args -> V_51 -> V_53 >=
V_47 + args -> V_54 ) ;
args -> V_11 = V_47 ;
}
STATIC int
F_31 (
T_4 * V_55 ,
T_4 * V_56 ,
T_2 V_57 ,
T_1 V_58 ,
T_2 V_59 ,
T_1 V_47 ,
int V_60 )
{
int error ;
int V_61 ;
T_2 V_62 ;
T_2 V_63 ;
T_1 V_64 = 0 ;
T_1 V_65 = 0 ;
struct V_1 * V_2 ;
V_2 = V_55 -> V_66 ;
if ( V_60 & V_67 ) {
#ifdef F_32
if ( ( error = F_20 ( V_55 , & V_62 , & V_64 , & V_61 ) ) )
return error ;
F_33 ( V_2 ,
V_61 == 1 && V_62 == V_57 && V_64 == V_58 ) ;
#endif
} else {
if ( ( error = F_13 ( V_55 , V_57 , V_58 , & V_61 ) ) )
return error ;
F_33 ( V_2 , V_61 == 1 ) ;
}
if ( V_60 & V_68 ) {
#ifdef F_32
if ( ( error = F_20 ( V_56 , & V_62 , & V_64 , & V_61 ) ) )
return error ;
F_33 ( V_2 ,
V_61 == 1 && V_62 == V_57 && V_64 == V_58 ) ;
#endif
} else {
if ( ( error = F_13 ( V_56 , V_57 , V_58 , & V_61 ) ) )
return error ;
F_33 ( V_2 , V_61 == 1 ) ;
}
#ifdef F_32
if ( V_56 -> V_69 == 1 && V_55 -> V_69 == 1 ) {
struct V_70 * V_71 ;
struct V_70 * V_72 ;
V_71 = F_34 ( V_56 -> V_73 [ 0 ] ) ;
V_72 = F_34 ( V_55 -> V_73 [ 0 ] ) ;
F_33 ( V_2 ,
V_71 -> V_74 == V_72 -> V_74 ) ;
}
#endif
if ( V_59 == V_57 && V_47 == V_58 )
V_62 = V_63 = V_45 ;
else if ( V_59 == V_57 ) {
V_62 = V_59 + V_47 ;
V_64 = V_58 - V_47 ;
V_63 = V_45 ;
} else if ( V_59 + V_47 == V_57 + V_58 ) {
V_62 = V_57 ;
V_64 = V_58 - V_47 ;
V_63 = V_45 ;
} else {
V_62 = V_57 ;
V_64 = V_59 - V_57 ;
V_63 = V_59 + V_47 ;
V_65 = ( V_57 + V_58 ) - V_63 ;
}
if ( ( error = F_35 ( V_55 , & V_61 ) ) )
return error ;
F_33 ( V_2 , V_61 == 1 ) ;
if ( V_62 != V_45 ) {
if ( ( error = F_13 ( V_55 , V_62 , V_64 , & V_61 ) ) )
return error ;
F_33 ( V_2 , V_61 == 0 ) ;
if ( ( error = F_36 ( V_55 , & V_61 ) ) )
return error ;
F_33 ( V_2 , V_61 == 1 ) ;
}
if ( V_63 != V_45 ) {
if ( ( error = F_13 ( V_55 , V_63 , V_65 , & V_61 ) ) )
return error ;
F_33 ( V_2 , V_61 == 0 ) ;
if ( ( error = F_36 ( V_55 , & V_61 ) ) )
return error ;
F_33 ( V_2 , V_61 == 1 ) ;
}
if ( V_62 == V_45 ) {
if ( ( error = F_35 ( V_56 , & V_61 ) ) )
return error ;
F_33 ( V_2 , V_61 == 1 ) ;
} else {
if ( ( error = F_17 ( V_56 , V_62 , V_64 ) ) )
return error ;
}
if ( V_63 != V_45 ) {
if ( ( error = F_13 ( V_56 , V_63 , V_65 , & V_61 ) ) )
return error ;
F_33 ( V_2 , V_61 == 0 ) ;
if ( ( error = F_36 ( V_56 , & V_61 ) ) )
return error ;
F_33 ( V_2 , V_61 == 1 ) ;
}
return 0 ;
}
static bool
F_37 (
struct V_75 * V_76 )
{
struct V_1 * V_2 = V_76 -> V_77 -> V_78 ;
struct V_79 * V_80 = F_38 ( V_76 ) ;
int V_61 ;
if ( ! F_39 ( & V_80 -> V_81 , & V_2 -> V_3 . V_82 ) )
return false ;
if ( F_22 ( V_80 -> V_83 ) != V_84 )
return false ;
if ( V_76 -> V_85 && F_22 ( V_80 -> V_86 ) != V_76 -> V_85 -> V_87 )
return false ;
for ( V_61 = 0 ; V_61 < F_40 ( V_2 ) ; V_61 ++ ) {
if ( F_22 ( V_80 -> V_88 [ V_61 ] ) != V_45 &&
F_22 ( V_80 -> V_88 [ V_61 ] ) >= V_2 -> V_3 . V_7 )
return false ;
}
return F_41 ( V_2 ,
F_42 ( F_38 ( V_76 ) -> V_89 ) ) ;
}
static void
F_43 (
struct V_75 * V_76 )
{
struct V_1 * V_2 = V_76 -> V_77 -> V_78 ;
if ( ! F_44 ( & V_2 -> V_3 ) )
return;
if ( ! F_45 ( V_76 , V_90 ) )
F_46 ( V_76 , - V_91 ) ;
else if ( ! F_37 ( V_76 ) )
F_46 ( V_76 , - V_92 ) ;
if ( V_76 -> V_93 )
F_47 ( V_76 ) ;
}
static void
F_48 (
struct V_75 * V_76 )
{
struct V_1 * V_2 = V_76 -> V_77 -> V_78 ;
struct V_94 * V_95 = V_76 -> V_96 ;
if ( ! F_44 ( & V_2 -> V_3 ) )
return;
if ( ! F_37 ( V_76 ) ) {
F_46 ( V_76 , - V_92 ) ;
F_47 ( V_76 ) ;
return;
}
if ( V_95 )
F_38 ( V_76 ) -> V_89 = F_49 ( V_95 -> V_97 . V_98 ) ;
F_50 ( V_76 , V_90 ) ;
}
STATIC int
F_51 (
T_5 * V_2 ,
T_6 * V_99 ,
T_7 V_100 ,
T_8 * * V_101 )
{
T_8 * V_76 ;
int error ;
ASSERT ( V_100 != V_102 ) ;
error = F_52 (
V_2 , V_99 , V_2 -> V_103 ,
F_53 ( V_2 , V_100 , F_54 ( V_2 ) ) ,
F_12 ( V_2 , 1 ) , 0 , & V_76 , & V_104 ) ;
if ( error )
return error ;
F_55 ( V_76 , V_105 ) ;
* V_101 = V_76 ;
return 0 ;
}
STATIC int
F_56 (
struct V_106 * V_99 ,
struct V_107 * V_51 ,
struct V_75 * V_108 ,
long V_11 )
{
struct V_109 * V_110 = F_57 ( V_108 ) ;
V_51 -> V_52 += V_11 ;
F_58 ( & V_110 -> V_111 , V_11 ) ;
F_59 ( V_99 , V_11 ) ;
if ( F_60 ( F_22 ( V_110 -> V_111 ) >
F_22 ( V_110 -> V_112 ) ) )
return - V_92 ;
F_61 ( V_99 , V_108 , V_113 ) ;
return 0 ;
}
STATIC int
F_62 (
T_3 * args )
{
int error = 0 ;
ASSERT ( args -> V_30 > 0 ) ;
ASSERT ( args -> V_50 > 0 ) ;
ASSERT ( args -> V_30 <= args -> V_50 ) ;
ASSERT ( args -> V_48 < args -> V_49 ) ;
ASSERT ( args -> V_29 > 0 ) ;
args -> V_114 = 0 ;
switch ( args -> type ) {
case V_115 :
error = F_63 ( args ) ;
break;
case V_116 :
error = F_64 ( args ) ;
break;
case V_117 :
error = F_65 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error || args -> V_118 == V_45 )
return error ;
ASSERT ( args -> V_11 >= args -> V_30 ) ;
ASSERT ( args -> V_11 <= args -> V_50 ) ;
ASSERT ( ! args -> V_114 || args -> V_119 != V_120 ) ;
ASSERT ( args -> V_118 % args -> V_29 == 0 ) ;
if ( args -> V_121 . V_122 != V_123 ) {
error = F_66 ( args -> V_99 , args -> V_108 , args -> V_100 ,
args -> V_118 , args -> V_11 , & args -> V_121 ) ;
if ( error )
return error ;
}
if ( ! args -> V_114 ) {
error = F_56 ( args -> V_99 , args -> V_51 ,
args -> V_108 ,
- ( ( long ) ( args -> V_11 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_67 ( args -> V_2 , args -> V_100 ,
args -> V_118 , args -> V_11 ) ) ;
}
F_68 ( args -> V_51 , args -> V_119 , args ) ;
F_69 ( args -> V_2 , V_124 ) ;
F_70 ( args -> V_2 , V_125 , args -> V_11 ) ;
return error ;
}
STATIC int
F_65 (
T_3 * args )
{
T_4 * V_56 ;
T_4 * V_55 ;
int error ;
T_2 V_57 ;
T_1 V_58 ;
T_2 V_126 ;
T_1 V_127 ;
T_2 V_128 ;
int V_61 ;
ASSERT ( args -> V_29 == 1 ) ;
V_56 = F_71 ( args -> V_2 , args -> V_99 , args -> V_108 ,
args -> V_100 , V_129 ) ;
error = F_16 ( V_56 , args -> V_118 , args -> V_30 , & V_61 ) ;
if ( error )
goto V_130;
if ( ! V_61 )
goto V_131;
error = F_20 ( V_56 , & V_57 , & V_58 , & V_61 ) ;
if ( error )
goto V_130;
F_72 ( args -> V_2 , V_61 == 1 , V_130 ) ;
ASSERT ( V_57 <= args -> V_118 ) ;
F_24 ( args , V_57 , V_58 , & V_126 , & V_127 ) ;
if ( V_126 > args -> V_118 )
goto V_131;
if ( V_127 < args -> V_30 )
goto V_131;
V_128 = V_126 + V_127 ;
if ( V_128 < args -> V_118 + args -> V_30 )
goto V_131;
args -> V_11 = F_73 ( V_128 , args -> V_118 + args -> V_50 )
- args -> V_118 ;
F_30 ( args ) ;
ASSERT ( args -> V_118 + args -> V_11 <= V_128 ) ;
V_55 = F_71 ( args -> V_2 , args -> V_99 , args -> V_108 ,
args -> V_100 , V_132 ) ;
ASSERT ( args -> V_118 + args -> V_11 <=
F_22 ( F_57 ( args -> V_108 ) -> V_112 ) ) ;
error = F_31 ( V_55 , V_56 , V_57 , V_58 , args -> V_118 ,
args -> V_11 , V_68 ) ;
if ( error ) {
F_74 ( V_55 , V_133 ) ;
goto V_130;
}
F_74 ( V_56 , V_134 ) ;
F_74 ( V_55 , V_134 ) ;
args -> V_114 = 0 ;
F_75 ( args ) ;
return 0 ;
V_131:
F_74 ( V_56 , V_134 ) ;
args -> V_118 = V_45 ;
F_76 ( args ) ;
return 0 ;
V_130:
F_74 ( V_56 , V_133 ) ;
F_77 ( args ) ;
return error ;
}
STATIC int
F_78 (
struct V_135 * args ,
struct V_8 * * V_136 ,
struct V_8 * * V_137 ,
T_2 V_138 ,
T_2 * V_139 ,
T_1 * V_140 ,
T_2 * V_141 ,
T_1 * V_142 ,
int V_143 )
{
T_2 V_144 ;
T_2 V_145 ;
int error ;
int V_61 ;
if ( ! V_138 )
goto V_146;
do {
error = F_20 ( * V_137 , V_139 , V_140 , & V_61 ) ;
if ( error )
goto V_130;
F_72 ( args -> V_2 , V_61 == 1 , V_130 ) ;
F_23 ( args , * V_139 , * V_140 , V_141 , V_142 ) ;
if ( ! V_143 ) {
if ( * V_141 > args -> V_147 )
goto V_146;
if ( * V_141 >= args -> V_118 + V_138 )
goto V_146;
} else {
if ( * V_141 < args -> V_28 )
goto V_146;
if ( * V_141 <= args -> V_118 - V_138 )
goto V_146;
}
if ( * V_142 >= args -> V_30 ) {
args -> V_11 = F_28 ( * V_142 , args -> V_50 ) ;
F_30 ( args ) ;
V_145 = F_26 ( args -> V_118 , args -> V_11 ,
args -> V_29 ,
args -> V_34 , * V_141 ,
* V_142 , & V_144 ) ;
if ( V_145 < V_138 )
goto V_148;
goto V_146;
}
if ( ! V_143 )
error = F_79 ( * V_137 , 0 , & V_61 ) ;
else
error = F_80 ( * V_137 , 0 , & V_61 ) ;
if ( error )
goto V_130;
} while ( V_61 );
V_146:
F_74 ( * V_137 , V_134 ) ;
* V_137 = NULL ;
return 0 ;
V_148:
F_74 ( * V_136 , V_134 ) ;
* V_136 = NULL ;
return 0 ;
V_130:
return error ;
}
STATIC int
F_64 (
T_3 * args )
{
T_4 * V_149 ;
T_4 * V_150 ;
T_4 * V_55 ;
T_2 V_151 ;
T_2 V_152 ;
T_1 V_153 ;
T_1 V_154 ;
T_1 V_155 ;
T_2 V_156 ;
int error ;
int V_61 ;
int V_157 ;
T_2 V_158 ;
T_2 V_159 ;
T_1 V_160 ;
T_1 V_161 ;
T_1 V_162 ;
T_2 V_163 ;
T_1 V_47 ;
int V_164 = 0 ;
#ifdef F_32
int V_165 ;
V_165 = F_81 () & 1 ;
#endif
if ( ! args -> V_28 && ! args -> V_147 )
args -> V_147 = args -> V_2 -> V_3 . V_7 - 1 ;
ASSERT ( args -> V_28 <= args -> V_147 ) ;
if ( args -> V_118 < args -> V_28 )
args -> V_118 = args -> V_28 ;
if ( args -> V_118 > args -> V_147 )
args -> V_118 = args -> V_147 ;
V_166:
V_150 = NULL ;
V_149 = NULL ;
V_161 = 0 ;
V_155 = 0 ;
V_162 = 0 ;
V_55 = F_71 ( args -> V_2 , args -> V_99 , args -> V_108 ,
args -> V_100 , V_132 ) ;
if ( ( error = F_15 ( V_55 , 0 , args -> V_50 , & V_61 ) ) )
goto V_130;
if ( ! V_61 ) {
if ( ( error = F_82 ( args , V_55 , & V_158 ,
& V_161 , & V_61 ) ) )
goto V_130;
if ( V_61 == 0 || V_161 == 0 ) {
F_74 ( V_55 , V_134 ) ;
F_83 ( args ) ;
return 0 ;
}
ASSERT ( V_61 == 1 ) ;
}
args -> V_114 = 0 ;
while ( F_84 ( V_55 , 0 ) ) {
T_1 V_167 ;
int V_168 = 0 ;
T_1 V_169 = 0 ;
T_2 V_170 = 0 ;
#ifdef F_32
if ( V_165 )
break;
#endif
if ( V_161 || args -> V_29 > 1 ) {
V_55 -> V_171 [ 0 ] = 1 ;
do {
if ( ( error = F_20 ( V_55 , & V_158 ,
& V_161 , & V_61 ) ) )
goto V_130;
F_72 ( args -> V_2 , V_61 == 1 , V_130 ) ;
if ( V_161 >= args -> V_30 )
break;
if ( ( error = F_79 ( V_55 , 0 , & V_61 ) ) )
goto V_130;
} while ( V_61 );
ASSERT ( V_161 >= args -> V_30 ) ;
if ( ! V_61 )
break;
}
V_61 = V_55 -> V_171 [ 0 ] ;
for ( V_157 = 1 , V_169 = 0 , V_167 = 0 ;
! error && V_157 && ( V_169 < args -> V_50 || V_167 > 0 ) ;
error = F_79 ( V_55 , 0 , & V_157 ) ) {
if ( ( error = F_20 ( V_55 , & V_158 , & V_161 , & V_61 ) ) )
goto V_130;
F_72 ( args -> V_2 , V_61 == 1 , V_130 ) ;
F_23 ( args , V_158 , V_161 ,
& V_159 , & V_162 ) ;
if ( V_162 < args -> V_30 )
continue;
if ( V_159 < args -> V_28 || V_159 > args -> V_147 )
continue;
args -> V_11 = F_28 ( V_162 , args -> V_50 ) ;
F_30 ( args ) ;
ASSERT ( args -> V_11 >= args -> V_30 ) ;
if ( args -> V_11 < V_169 )
continue;
V_160 = F_26 ( args -> V_118 , args -> V_11 ,
args -> V_29 , args -> V_34 , V_159 ,
V_162 , & V_163 ) ;
if ( V_163 != V_45 &&
( args -> V_11 > V_169 || V_160 < V_167 ) ) {
V_167 = V_160 ;
V_170 = V_163 ;
V_169 = args -> V_11 ;
V_168 = V_55 -> V_171 [ 0 ] ;
}
}
if ( V_169 == 0 )
break;
V_55 -> V_171 [ 0 ] = V_168 ;
if ( ( error = F_20 ( V_55 , & V_158 , & V_161 , & V_61 ) ) )
goto V_130;
F_72 ( args -> V_2 , V_61 == 1 , V_130 ) ;
ASSERT ( V_158 + V_161 <= F_22 ( F_57 ( args -> V_108 ) -> V_112 ) ) ;
args -> V_11 = V_169 ;
args -> V_118 = V_170 ;
ASSERT ( V_170 >= V_158 ) ;
ASSERT ( V_170 + V_169 <= V_158 + V_161 ) ;
V_150 = F_71 ( args -> V_2 , args -> V_99 ,
args -> V_108 , args -> V_100 , V_129 ) ;
if ( ( error = F_31 ( V_55 , V_150 , V_158 ,
V_161 , V_170 , V_169 , V_67 ) ) )
goto V_130;
F_74 ( V_55 , V_134 ) ;
F_74 ( V_150 , V_134 ) ;
F_85 ( args ) ;
return 0 ;
}
V_150 = F_71 ( args -> V_2 , args -> V_99 , args -> V_108 ,
args -> V_100 , V_129 ) ;
if ( ( error = F_16 ( V_150 , args -> V_118 , args -> V_50 , & V_61 ) ) )
goto V_130;
if ( ! V_61 ) {
V_149 = V_150 ;
V_150 = NULL ;
}
else if ( ( error = F_86 ( V_150 , & V_149 ) ) )
goto V_130;
if ( ( error = F_79 ( V_149 , 0 , & V_61 ) ) )
goto V_130;
if ( ! V_61 ) {
F_74 ( V_149 , V_134 ) ;
V_149 = NULL ;
}
do {
if ( V_150 ) {
if ( ( error = F_20 ( V_150 , & V_158 , & V_161 , & V_61 ) ) )
goto V_130;
F_72 ( args -> V_2 , V_61 == 1 , V_130 ) ;
F_23 ( args , V_158 , V_161 ,
& V_159 , & V_162 ) ;
if ( V_162 >= args -> V_30 && V_159 >= args -> V_28 )
break;
if ( ( error = F_80 ( V_150 , 0 , & V_61 ) ) )
goto V_130;
if ( ! V_61 || V_159 < args -> V_28 ) {
F_74 ( V_150 ,
V_134 ) ;
V_150 = NULL ;
}
}
if ( V_149 ) {
if ( ( error = F_20 ( V_149 , & V_151 , & V_154 , & V_61 ) ) )
goto V_130;
F_72 ( args -> V_2 , V_61 == 1 , V_130 ) ;
F_23 ( args , V_151 , V_154 ,
& V_152 , & V_155 ) ;
if ( V_155 >= args -> V_30 && V_152 <= args -> V_147 )
break;
if ( ( error = F_79 ( V_149 , 0 , & V_61 ) ) )
goto V_130;
if ( ! V_61 || V_152 > args -> V_147 ) {
F_74 ( V_149 ,
V_134 ) ;
V_149 = NULL ;
}
}
} while ( V_150 || V_149 );
if ( V_150 && V_149 ) {
if ( V_162 >= args -> V_30 ) {
args -> V_11 = F_28 ( V_162 , args -> V_50 ) ;
F_30 ( args ) ;
V_160 = F_26 ( args -> V_118 , args -> V_11 ,
args -> V_29 , args -> V_34 , V_159 ,
V_162 , & V_163 ) ;
error = F_78 ( args ,
& V_150 , & V_149 ,
V_160 , & V_151 , & V_154 ,
& V_152 , & V_155 ,
0 ) ;
} else {
ASSERT ( V_155 >= args -> V_30 ) ;
args -> V_11 = F_28 ( V_155 , args -> V_50 ) ;
F_30 ( args ) ;
V_153 = F_26 ( args -> V_118 , args -> V_11 ,
args -> V_29 , args -> V_34 , V_152 ,
V_155 , & V_156 ) ;
error = F_78 ( args ,
& V_149 , & V_150 ,
V_153 , & V_158 , & V_161 ,
& V_159 , & V_162 ,
1 ) ;
}
if ( error )
goto V_130;
}
if ( V_150 == NULL && V_149 == NULL ) {
F_74 ( V_55 , V_134 ) ;
if ( ! V_164 ++ ) {
F_87 ( args ) ;
F_88 ( args -> V_2 , V_172 ) ;
goto V_166;
}
F_89 ( args ) ;
args -> V_118 = V_45 ;
return 0 ;
}
if ( V_149 ) {
V_150 = V_149 ;
V_149 = NULL ;
V_158 = V_151 ;
V_159 = V_152 ;
V_161 = V_154 ;
V_162 = V_155 ;
V_157 = 1 ;
} else
V_157 = 0 ;
args -> V_11 = F_28 ( V_162 , args -> V_50 ) ;
F_30 ( args ) ;
V_47 = args -> V_11 ;
( void ) F_26 ( args -> V_118 , V_47 , args -> V_29 ,
args -> V_34 , V_159 , V_162 , & V_163 ) ;
ASSERT ( V_163 >= V_158 ) ;
ASSERT ( V_163 + V_47 <= V_159 + V_162 ) ;
ASSERT ( V_163 + V_47 <= F_22 ( F_57 ( args -> V_108 ) -> V_112 ) ) ;
ASSERT ( V_163 >= args -> V_28 && V_163 <= args -> V_147 ) ;
args -> V_118 = V_163 ;
if ( ( error = F_31 ( V_55 , V_150 , V_158 , V_161 ,
V_163 , V_47 , V_68 ) ) )
goto V_130;
if ( V_157 )
F_90 ( args ) ;
else
F_91 ( args ) ;
F_74 ( V_55 , V_134 ) ;
F_74 ( V_150 , V_134 ) ;
return 0 ;
V_130:
F_92 ( args ) ;
if ( V_55 != NULL )
F_74 ( V_55 , V_133 ) ;
if ( V_150 != NULL )
F_74 ( V_150 , V_133 ) ;
if ( V_149 != NULL )
F_74 ( V_149 , V_133 ) ;
return error ;
}
STATIC int
F_63 (
T_3 * args )
{
T_4 * V_56 ;
T_4 * V_55 ;
int error ;
T_2 V_57 ;
T_1 V_58 ;
int V_61 ;
T_2 V_59 ;
T_1 V_47 ;
int V_164 = 0 ;
V_166:
V_55 = F_71 ( args -> V_2 , args -> V_99 , args -> V_108 ,
args -> V_100 , V_132 ) ;
V_56 = NULL ;
if ( ( error = F_15 ( V_55 , 0 ,
args -> V_50 + args -> V_29 - 1 , & V_61 ) ) )
goto V_130;
if ( ! V_61 || V_164 > 1 ) {
error = F_82 ( args , V_55 ,
& V_57 , & V_58 , & V_61 ) ;
if ( error )
goto V_130;
if ( V_61 == 0 || V_58 == 0 ) {
F_74 ( V_55 , V_134 ) ;
F_93 ( args ) ;
return 0 ;
}
ASSERT ( V_61 == 1 ) ;
F_23 ( args , V_57 , V_58 , & V_59 , & V_47 ) ;
} else {
for (; ; ) {
error = F_20 ( V_55 , & V_57 , & V_58 , & V_61 ) ;
if ( error )
goto V_130;
F_72 ( args -> V_2 , V_61 == 1 , V_130 ) ;
F_23 ( args , V_57 , V_58 ,
& V_59 , & V_47 ) ;
if ( V_47 >= args -> V_50 )
break;
error = F_79 ( V_55 , 0 , & V_61 ) ;
if ( error )
goto V_130;
if ( V_61 == 0 ) {
F_74 ( V_55 ,
V_134 ) ;
F_94 ( args ) ;
if ( ! V_164 ++ )
F_88 ( args -> V_2 , V_172 ) ;
goto V_166;
}
}
}
V_47 = F_28 ( args -> V_50 , V_47 ) ;
F_72 ( args -> V_2 , V_47 == 0 ||
( V_47 <= V_58 && V_59 + V_47 <= V_57 + V_58 ) , V_130 ) ;
if ( V_47 < args -> V_50 ) {
T_2 V_173 ;
T_1 V_174 ;
T_2 V_175 ;
T_1 V_176 ;
V_176 = V_47 ;
V_175 = V_59 ;
V_174 = V_58 ;
V_173 = V_57 ;
for (; ; ) {
if ( ( error = F_80 ( V_55 , 0 , & V_61 ) ) )
goto V_130;
if ( V_61 == 0 )
break;
if ( ( error = F_20 ( V_55 , & V_57 , & V_58 ,
& V_61 ) ) )
goto V_130;
F_72 ( args -> V_2 , V_61 == 1 , V_130 ) ;
if ( V_58 < V_176 )
break;
F_23 ( args , V_57 , V_58 ,
& V_59 , & V_47 ) ;
V_47 = F_28 ( args -> V_50 , V_47 ) ;
F_72 ( args -> V_2 , V_47 == 0 ||
( V_47 <= V_58 && V_59 + V_47 <= V_57 + V_58 ) ,
V_130 ) ;
if ( V_47 > V_176 ) {
V_176 = V_47 ;
V_175 = V_59 ;
V_174 = V_58 ;
V_173 = V_57 ;
if ( V_47 == args -> V_50 )
break;
}
}
if ( ( error = F_13 ( V_55 , V_173 , V_174 ,
& V_61 ) ) )
goto V_130;
F_72 ( args -> V_2 , V_61 == 1 , V_130 ) ;
V_47 = V_176 ;
V_59 = V_175 ;
V_58 = V_174 ;
V_57 = V_173 ;
}
args -> V_114 = 0 ;
args -> V_11 = V_47 ;
if ( V_47 < args -> V_30 ) {
if ( ! V_164 ++ ) {
F_74 ( V_55 , V_134 ) ;
F_94 ( args ) ;
F_88 ( args -> V_2 , V_172 ) ;
goto V_166;
}
goto V_177;
}
F_30 ( args ) ;
V_47 = args -> V_11 ;
F_72 ( args -> V_2 , V_47 <= V_58 , V_130 ) ;
V_56 = F_71 ( args -> V_2 , args -> V_99 , args -> V_108 ,
args -> V_100 , V_129 ) ;
if ( ( error = F_31 ( V_55 , V_56 , V_57 , V_58 ,
V_59 , V_47 , V_67 ) ) )
goto V_130;
F_74 ( V_55 , V_134 ) ;
F_74 ( V_56 , V_134 ) ;
V_55 = V_56 = NULL ;
args -> V_11 = V_47 ;
args -> V_118 = V_59 ;
F_72 ( args -> V_2 ,
args -> V_118 + args -> V_11 <=
F_22 ( F_57 ( args -> V_108 ) -> V_112 ) ,
V_130 ) ;
F_95 ( args ) ;
return 0 ;
V_130:
F_96 ( args ) ;
if ( V_55 )
F_74 ( V_55 , V_133 ) ;
if ( V_56 )
F_74 ( V_56 , V_133 ) ;
return error ;
V_177:
F_74 ( V_55 , V_134 ) ;
F_97 ( args ) ;
args -> V_118 = V_45 ;
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
struct V_181 V_121 ;
struct V_107 * V_51 ;
int error ;
T_2 V_57 ;
T_1 V_58 ;
int V_61 ;
if ( ( error = F_80 ( V_178 , 0 , & V_61 ) ) )
goto V_130;
if ( V_61 ) {
if ( ( error = F_20 ( V_178 , & V_57 , & V_58 , & V_61 ) ) )
goto V_130;
F_72 ( args -> V_2 , V_61 == 1 , V_130 ) ;
}
else if ( args -> V_30 == 1 && args -> V_29 == 1 &&
args -> V_119 != V_120 &&
( F_22 ( F_57 ( args -> V_108 ) -> V_182 )
> args -> V_54 ) ) {
error = F_98 ( args -> V_99 , args -> V_108 , & V_57 , 0 ) ;
if ( error )
goto V_130;
if ( V_57 != V_45 ) {
F_99 ( args -> V_2 , args -> V_100 , V_57 , 1 ,
F_100 ( args -> V_34 ) ) ;
if ( F_27 ( args -> V_34 ) ) {
T_8 * V_76 ;
V_76 = F_101 ( args -> V_2 , args -> V_99 ,
args -> V_100 , V_57 , 0 ) ;
F_102 ( args -> V_99 , V_76 ) ;
}
args -> V_11 = 1 ;
args -> V_118 = V_57 ;
F_72 ( args -> V_2 ,
args -> V_118 + args -> V_11 <=
F_22 ( F_57 ( args -> V_108 ) -> V_112 ) ,
V_130 ) ;
args -> V_114 = 1 ;
F_103 ( args ) ;
F_104 ( & V_121 , V_183 ) ;
error = F_105 ( args -> V_99 , args -> V_108 , args -> V_100 ,
V_57 , 1 , & V_121 ) ;
if ( error )
goto V_130;
V_51 = F_106 ( args -> V_2 , args -> V_100 ) ;
F_107 ( V_51 , V_120 ,
args -> V_99 , 1 ) ;
F_108 ( V_51 ) ;
* V_12 = 0 ;
return 0 ;
}
else
V_58 = 0 ;
}
else {
V_57 = V_45 ;
V_58 = 0 ;
}
if ( V_58 < args -> V_30 ) {
args -> V_118 = V_45 ;
F_109 ( args ) ;
V_58 = 0 ;
}
* V_179 = V_57 ;
* V_180 = V_58 ;
* V_12 = 1 ;
F_110 ( args ) ;
return 0 ;
V_130:
F_111 ( args ) ;
return error ;
}
STATIC int
F_112 (
T_6 * V_99 ,
T_8 * V_108 ,
T_7 V_100 ,
T_2 V_10 ,
T_1 V_11 ,
struct V_181 * V_121 ,
enum V_184 type )
{
T_4 * V_56 ;
T_4 * V_55 ;
int error ;
T_2 V_151 ;
T_1 V_154 ;
int V_185 ;
int V_186 ;
int V_61 ;
T_2 V_158 ;
T_1 V_161 ;
T_5 * V_2 ;
T_2 V_187 ;
T_1 V_188 ;
T_9 * V_51 ;
V_56 = V_55 = NULL ;
V_2 = V_99 -> V_189 ;
if ( V_121 -> V_122 != V_123 ) {
error = F_105 ( V_99 , V_108 , V_100 , V_10 , V_11 , V_121 ) ;
if ( error )
goto V_130;
}
V_56 = F_71 ( V_2 , V_99 , V_108 , V_100 , V_129 ) ;
if ( ( error = F_16 ( V_56 , V_10 , V_11 , & V_185 ) ) )
goto V_130;
if ( V_185 ) {
if ( ( error = F_20 ( V_56 , & V_158 , & V_161 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
if ( V_158 + V_161 < V_10 )
V_185 = 0 ;
else {
F_72 ( V_2 ,
V_158 + V_161 <= V_10 , V_130 ) ;
}
}
if ( ( error = F_79 ( V_56 , 0 , & V_186 ) ) )
goto V_130;
if ( V_186 ) {
if ( ( error = F_20 ( V_56 , & V_151 , & V_154 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
if ( V_10 + V_11 < V_151 )
V_186 = 0 ;
else {
F_72 ( V_2 , V_151 >= V_10 + V_11 , V_130 ) ;
}
}
V_55 = F_71 ( V_2 , V_99 , V_108 , V_100 , V_132 ) ;
if ( V_185 && V_186 ) {
if ( ( error = F_13 ( V_55 , V_158 , V_161 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
if ( ( error = F_35 ( V_55 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
if ( ( error = F_13 ( V_55 , V_151 , V_154 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
if ( ( error = F_35 ( V_55 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
if ( ( error = F_35 ( V_56 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
if ( ( error = F_80 ( V_56 , 0 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
#ifdef F_32
{
T_2 V_190 ;
T_1 V_191 ;
if ( ( error = F_20 ( V_56 , & V_190 , & V_191 ,
& V_61 ) ) )
goto V_130;
F_72 ( V_2 ,
V_61 == 1 && V_190 == V_158 && V_191 == V_161 ,
V_130 ) ;
}
#endif
V_187 = V_158 ;
V_188 = V_11 + V_161 + V_154 ;
if ( ( error = F_17 ( V_56 , V_187 , V_188 ) ) )
goto V_130;
}
else if ( V_185 ) {
if ( ( error = F_13 ( V_55 , V_158 , V_161 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
if ( ( error = F_35 ( V_55 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
if ( ( error = F_80 ( V_56 , 0 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
V_187 = V_158 ;
V_188 = V_11 + V_161 ;
if ( ( error = F_17 ( V_56 , V_187 , V_188 ) ) )
goto V_130;
}
else if ( V_186 ) {
if ( ( error = F_13 ( V_55 , V_151 , V_154 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
if ( ( error = F_35 ( V_55 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
V_187 = V_10 ;
V_188 = V_11 + V_154 ;
if ( ( error = F_17 ( V_56 , V_187 , V_188 ) ) )
goto V_130;
}
else {
V_187 = V_10 ;
V_188 = V_11 ;
if ( ( error = F_36 ( V_56 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
}
F_74 ( V_56 , V_134 ) ;
V_56 = NULL ;
if ( ( error = F_13 ( V_55 , V_187 , V_188 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 0 , V_130 ) ;
if ( ( error = F_36 ( V_55 , & V_61 ) ) )
goto V_130;
F_72 ( V_2 , V_61 == 1 , V_130 ) ;
F_74 ( V_55 , V_134 ) ;
V_55 = NULL ;
V_51 = F_106 ( V_2 , V_100 ) ;
error = F_56 ( V_99 , V_51 , V_108 , V_11 ) ;
F_107 ( V_51 , type , V_99 , V_11 ) ;
F_108 ( V_51 ) ;
if ( error )
goto V_130;
F_69 ( V_2 , V_192 ) ;
F_70 ( V_2 , V_193 , V_11 ) ;
F_113 ( V_2 , V_100 , V_10 , V_11 , type == V_120 ,
V_185 , V_186 ) ;
return 0 ;
V_130:
F_113 ( V_2 , V_100 , V_10 , V_11 , type == V_120 ,
- 1 , - 1 ) ;
if ( V_56 )
F_74 ( V_56 , V_133 ) ;
if ( V_55 )
F_74 ( V_55 , V_133 ) ;
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
struct V_107 * V_51 ,
T_1 V_196 ,
T_1 V_197 )
{
T_1 V_198 = 0 ;
if ( V_196 > V_51 -> V_53 )
V_198 = V_196 - V_51 -> V_53 ;
if ( V_51 -> V_52 - V_51 -> V_199 < V_197 )
V_198 += V_197 - ( V_51 -> V_52 - V_51 -> V_199 ) ;
if ( V_51 -> V_199 > V_198 )
return V_51 -> V_199 - V_198 ;
return V_51 -> V_53 > 0 || V_51 -> V_199 > 0 ;
}
unsigned int
F_117 (
struct V_1 * V_2 ,
struct V_107 * V_51 )
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
struct V_135 * args ,
T_1 V_200 ,
int V_60 )
{
struct V_107 * V_51 = args -> V_51 ;
T_1 V_201 , V_202 ;
T_1 V_203 ;
int V_204 ;
if ( V_60 & V_205 )
return true ;
V_203 = F_120 ( V_51 , args -> V_119 ) ;
V_201 = args -> V_30 + ( args -> V_29 - 1 ) + args -> V_206 ;
V_202 = F_116 ( args -> V_2 , V_51 , V_200 ,
V_203 ) ;
if ( V_202 < V_201 )
return false ;
V_204 = ( int ) ( V_51 -> V_52 + V_51 -> V_53 -
V_203 - V_200 - args -> V_54 ) ;
if ( V_204 < ( int ) F_121 ( args -> V_207 , V_201 ) )
return false ;
if ( V_204 < ( int ) args -> V_50 && ! ( V_60 & V_208 ) ) {
args -> V_50 = V_204 ;
ASSERT ( args -> V_50 > 0 ) ;
ASSERT ( args -> V_50 >= args -> V_30 ) ;
}
return true ;
}
int
F_122 (
struct V_135 * args ,
int V_60 )
{
struct V_1 * V_2 = args -> V_2 ;
struct V_107 * V_51 = args -> V_51 ;
struct V_106 * V_99 = args -> V_99 ;
struct V_75 * V_108 = NULL ;
struct V_75 * V_209 = NULL ;
struct V_135 V_210 ;
T_2 V_10 ;
T_1 V_196 ;
int error = 0 ;
if ( ! V_51 -> V_211 ) {
error = F_123 ( V_2 , V_99 , args -> V_100 , V_60 , & V_108 ) ;
if ( error )
goto V_212;
if ( ! V_51 -> V_211 ) {
ASSERT ( V_60 & V_213 ) ;
ASSERT ( ! ( V_60 & V_205 ) ) ;
goto V_214;
}
}
if ( V_51 -> V_215 && F_27 ( args -> V_34 ) &&
( V_60 & V_213 ) ) {
ASSERT ( ! ( V_60 & V_205 ) ) ;
goto V_214;
}
V_196 = F_117 ( V_2 , V_51 ) ;
if ( ! F_119 ( args , V_196 , V_60 |
V_208 ) )
goto V_214;
if ( ! V_108 ) {
error = F_123 ( V_2 , V_99 , args -> V_100 , V_60 , & V_108 ) ;
if ( error )
goto V_212;
if ( ! V_108 ) {
ASSERT ( V_60 & V_213 ) ;
ASSERT ( ! ( V_60 & V_205 ) ) ;
goto V_212;
}
}
V_196 = F_117 ( V_2 , V_51 ) ;
if ( ! F_119 ( args , V_196 , V_60 ) )
goto V_214;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
if ( V_60 & V_216 )
F_124 ( & V_210 . V_121 ) ;
else
F_104 ( & V_210 . V_121 , V_183 ) ;
while ( ! ( V_60 & V_217 ) && V_51 -> V_53 > V_196 ) {
struct V_75 * V_76 ;
error = F_98 ( V_99 , V_108 , & V_10 , 0 ) ;
if ( error )
goto V_214;
error = F_112 ( V_99 , V_108 , args -> V_100 , V_10 , 1 ,
& V_210 . V_121 , V_120 ) ;
if ( error )
goto V_214;
V_76 = F_101 ( V_2 , V_99 , args -> V_100 , V_10 , 0 ) ;
F_102 ( V_99 , V_76 ) ;
}
V_210 . V_99 = V_99 ;
V_210 . V_2 = V_2 ;
V_210 . V_108 = V_108 ;
V_210 . V_100 = args -> V_100 ;
V_210 . V_29 = V_210 . V_30 = V_210 . V_49 = 1 ;
V_210 . type = V_115 ;
V_210 . V_51 = V_51 ;
error = F_51 ( V_2 , V_99 , V_210 . V_100 , & V_209 ) ;
if ( error )
goto V_214;
while ( V_51 -> V_53 < V_196 ) {
V_210 . V_118 = 0 ;
V_210 . V_50 = V_196 - V_51 -> V_53 ;
V_210 . V_119 = V_120 ;
error = F_62 ( & V_210 ) ;
if ( error )
goto V_218;
if ( V_210 . V_118 == V_45 ) {
if ( V_60 & V_205 )
break;
goto V_218;
}
for ( V_10 = V_210 . V_118 ; V_10 < V_210 . V_118 + V_210 . V_11 ; V_10 ++ ) {
error = F_125 ( V_99 , V_108 ,
V_209 , V_10 , 0 ) ;
if ( error )
goto V_218;
}
}
F_126 ( V_99 , V_209 ) ;
args -> V_108 = V_108 ;
return 0 ;
V_218:
F_126 ( V_99 , V_209 ) ;
V_214:
if ( V_108 )
F_126 ( V_99 , V_108 ) ;
V_212:
args -> V_108 = NULL ;
return error ;
}
int
F_98 (
T_6 * V_99 ,
T_8 * V_108 ,
T_2 * V_219 ,
int V_220 )
{
T_10 * V_110 ;
T_8 * V_209 ;
T_2 V_10 ;
T_11 * V_88 ;
int error ;
int V_221 ;
T_5 * V_2 = V_99 -> V_189 ;
T_9 * V_51 ;
V_110 = F_57 ( V_108 ) ;
if ( ! V_110 -> V_182 ) {
* V_219 = V_45 ;
return 0 ;
}
error = F_51 ( V_2 , V_99 , F_22 ( V_110 -> V_222 ) ,
& V_209 ) ;
if ( error )
return error ;
V_88 = F_127 ( V_2 , V_209 ) ;
V_10 = F_22 ( V_88 [ F_22 ( V_110 -> V_223 ) ] ) ;
F_58 ( & V_110 -> V_223 , 1 ) ;
F_126 ( V_99 , V_209 ) ;
if ( F_22 ( V_110 -> V_223 ) == F_40 ( V_2 ) )
V_110 -> V_223 = 0 ;
V_51 = F_106 ( V_2 , F_22 ( V_110 -> V_222 ) ) ;
F_58 ( & V_110 -> V_182 , - 1 ) ;
F_128 ( V_99 , - 1 ) ;
V_51 -> V_53 -- ;
F_108 ( V_51 ) ;
V_221 = V_224 | V_225 ;
if ( V_220 ) {
F_58 ( & V_110 -> V_226 , 1 ) ;
V_51 -> V_227 ++ ;
V_221 |= V_228 ;
}
F_61 ( V_99 , V_108 , V_221 ) ;
* V_219 = V_10 ;
return 0 ;
}
void
F_61 (
T_6 * V_99 ,
T_8 * V_76 ,
int V_229 )
{
int V_230 ;
int V_231 ;
static const short V_232 [] = {
F_129 ( T_10 , V_233 ) ,
F_129 ( T_10 , V_234 ) ,
F_129 ( T_10 , V_222 ) ,
F_129 ( T_10 , V_112 ) ,
F_129 ( T_10 , V_235 [ 0 ] ) ,
F_129 ( T_10 , V_236 [ 0 ] ) ,
F_129 ( T_10 , V_223 ) ,
F_129 ( T_10 , V_237 ) ,
F_129 ( T_10 , V_182 ) ,
F_129 ( T_10 , V_111 ) ,
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
F_130 ( V_99 -> V_189 , F_57 ( V_76 ) , V_229 , V_245 ) ;
F_131 ( V_99 , V_76 , V_246 ) ;
F_132 ( V_229 , V_232 , V_247 , & V_230 , & V_231 ) ;
F_133 ( V_99 , V_76 , ( V_248 ) V_230 , ( V_248 ) V_231 ) ;
}
int
F_134 (
T_5 * V_2 ,
T_6 * V_99 ,
T_7 V_100 ,
int V_60 )
{
T_8 * V_76 ;
int error ;
if ( ( error = F_123 ( V_2 , V_99 , V_100 , V_60 , & V_76 ) ) )
return error ;
if ( V_76 )
F_126 ( V_99 , V_76 ) ;
return 0 ;
}
int
F_125 (
T_6 * V_99 ,
T_8 * V_108 ,
T_8 * V_209 ,
T_2 V_10 ,
int V_220 )
{
T_10 * V_110 ;
T_11 * V_249 ;
int error ;
int V_221 ;
T_5 * V_2 ;
T_9 * V_51 ;
T_11 * V_88 ;
int V_250 ;
V_110 = F_57 ( V_108 ) ;
V_2 = V_99 -> V_189 ;
if ( ! V_209 && ( error = F_51 ( V_2 , V_99 ,
F_22 ( V_110 -> V_222 ) , & V_209 ) ) )
return error ;
F_58 ( & V_110 -> V_237 , 1 ) ;
if ( F_22 ( V_110 -> V_237 ) == F_40 ( V_2 ) )
V_110 -> V_237 = 0 ;
V_51 = F_106 ( V_2 , F_22 ( V_110 -> V_222 ) ) ;
F_58 ( & V_110 -> V_182 , 1 ) ;
F_128 ( V_99 , 1 ) ;
V_51 -> V_53 ++ ;
V_221 = V_251 | V_225 ;
if ( V_220 ) {
F_58 ( & V_110 -> V_226 , - 1 ) ;
V_51 -> V_227 -- ;
V_221 |= V_228 ;
}
F_108 ( V_51 ) ;
F_61 ( V_99 , V_108 , V_221 ) ;
ASSERT ( F_22 ( V_110 -> V_182 ) <= F_40 ( V_2 ) ) ;
V_88 = F_127 ( V_2 , V_209 ) ;
V_249 = & V_88 [ F_22 ( V_110 -> V_237 ) ] ;
* V_249 = F_18 ( V_10 ) ;
V_250 = ( char * ) V_249 - ( char * ) V_209 -> V_252 ;
F_61 ( V_99 , V_108 , V_221 ) ;
F_131 ( V_99 , V_209 , V_253 ) ;
F_133 ( V_99 , V_209 , V_250 ,
V_250 + sizeof( T_2 ) - 1 ) ;
return 0 ;
}
static bool
F_135 (
struct V_1 * V_2 ,
struct V_75 * V_76 )
{
struct V_109 * V_110 = F_57 ( V_76 ) ;
if ( F_44 ( & V_2 -> V_3 ) ) {
if ( ! F_39 ( & V_110 -> V_239 , & V_2 -> V_3 . V_82 ) )
return false ;
if ( ! F_41 ( V_2 ,
F_42 ( F_57 ( V_76 ) -> V_254 ) ) )
return false ;
}
if ( ! ( V_110 -> V_233 == F_18 ( V_255 ) &&
F_136 ( F_22 ( V_110 -> V_234 ) ) &&
F_22 ( V_110 -> V_111 ) <= F_22 ( V_110 -> V_112 ) &&
F_22 ( V_110 -> V_223 ) < F_40 ( V_2 ) &&
F_22 ( V_110 -> V_237 ) < F_40 ( V_2 ) &&
F_22 ( V_110 -> V_182 ) <= F_40 ( V_2 ) ) )
return false ;
if ( F_22 ( V_110 -> V_236 [ V_129 ] ) < 1 ||
F_22 ( V_110 -> V_236 [ V_132 ] ) < 1 ||
F_22 ( V_110 -> V_236 [ V_129 ] ) > V_256 ||
F_22 ( V_110 -> V_236 [ V_132 ] ) > V_256 )
return false ;
if ( F_2 ( & V_2 -> V_3 ) &&
( F_22 ( V_110 -> V_236 [ V_257 ] ) < 1 ||
F_22 ( V_110 -> V_236 [ V_257 ] ) > V_256 ) )
return false ;
if ( V_76 -> V_85 && F_22 ( V_110 -> V_222 ) != V_76 -> V_85 -> V_87 )
return false ;
if ( F_137 ( & V_2 -> V_3 ) &&
F_22 ( V_110 -> V_226 ) > F_22 ( V_110 -> V_112 ) )
return false ;
if ( F_8 ( & V_2 -> V_3 ) &&
( F_22 ( V_110 -> V_243 ) < 1 ||
F_22 ( V_110 -> V_243 ) > V_256 ) )
return false ;
return true ; ;
}
static void
F_138 (
struct V_75 * V_76 )
{
struct V_1 * V_2 = V_76 -> V_77 -> V_78 ;
if ( F_44 ( & V_2 -> V_3 ) &&
! F_45 ( V_76 , V_258 ) )
F_46 ( V_76 , - V_91 ) ;
else if ( F_139 ( ! F_135 ( V_2 , V_76 ) , V_2 ,
V_259 ,
V_260 ) )
F_46 ( V_76 , - V_92 ) ;
if ( V_76 -> V_93 )
F_47 ( V_76 ) ;
}
static void
F_140 (
struct V_75 * V_76 )
{
struct V_1 * V_2 = V_76 -> V_77 -> V_78 ;
struct V_94 * V_95 = V_76 -> V_96 ;
if ( ! F_135 ( V_2 , V_76 ) ) {
F_46 ( V_76 , - V_92 ) ;
F_47 ( V_76 ) ;
return;
}
if ( ! F_44 ( & V_2 -> V_3 ) )
return;
if ( V_95 )
F_57 ( V_76 ) -> V_254 = F_49 ( V_95 -> V_97 . V_98 ) ;
F_50 ( V_76 , V_258 ) ;
}
int
F_141 (
struct V_1 * V_2 ,
struct V_106 * V_99 ,
T_7 V_100 ,
int V_60 ,
struct V_75 * * V_101 )
{
int error ;
F_142 ( V_2 , V_100 ) ;
ASSERT ( V_100 != V_102 ) ;
error = F_52 (
V_2 , V_99 , V_2 -> V_103 ,
F_53 ( V_2 , V_100 , F_143 ( V_2 ) ) ,
F_12 ( V_2 , 1 ) , V_60 , V_101 , & V_261 ) ;
if ( error )
return error ;
if ( ! * V_101 )
return 0 ;
ASSERT ( ! ( * V_101 ) -> V_93 ) ;
F_55 ( * V_101 , V_262 ) ;
return 0 ;
}
int
F_123 (
struct V_1 * V_2 ,
struct V_106 * V_99 ,
T_7 V_100 ,
int V_60 ,
struct V_75 * * V_101 )
{
struct V_109 * V_110 ;
struct V_107 * V_51 ;
int error ;
F_144 ( V_2 , V_100 ) ;
ASSERT ( V_100 != V_102 ) ;
error = F_141 ( V_2 , V_99 , V_100 ,
( V_60 & V_213 ) ? V_263 : 0 ,
V_101 ) ;
if ( error )
return error ;
if ( ! * V_101 )
return 0 ;
ASSERT ( ! ( * V_101 ) -> V_93 ) ;
V_110 = F_57 ( * V_101 ) ;
V_51 = F_106 ( V_2 , V_100 ) ;
if ( ! V_51 -> V_211 ) {
V_51 -> V_52 = F_22 ( V_110 -> V_111 ) ;
V_51 -> V_227 = F_22 ( V_110 -> V_226 ) ;
V_51 -> V_53 = F_22 ( V_110 -> V_182 ) ;
V_51 -> V_199 = F_22 ( V_110 -> V_238 ) ;
V_51 -> V_264 [ V_265 ] =
F_22 ( V_110 -> V_236 [ V_265 ] ) ;
V_51 -> V_264 [ V_266 ] =
F_22 ( V_110 -> V_236 [ V_266 ] ) ;
V_51 -> V_264 [ V_267 ] =
F_22 ( V_110 -> V_236 [ V_267 ] ) ;
V_51 -> V_268 = F_22 ( V_110 -> V_243 ) ;
F_145 ( & V_51 -> V_269 ) ;
V_51 -> V_270 = 0 ;
V_51 -> V_271 = V_272 ;
V_51 -> V_211 = 1 ;
}
#ifdef F_32
else if ( ! F_146 ( V_2 ) ) {
ASSERT ( V_51 -> V_52 == F_22 ( V_110 -> V_111 ) ) ;
ASSERT ( V_51 -> V_227 == F_22 ( V_110 -> V_226 ) ) ;
ASSERT ( V_51 -> V_53 == F_22 ( V_110 -> V_182 ) ) ;
ASSERT ( V_51 -> V_199 == F_22 ( V_110 -> V_238 ) ) ;
ASSERT ( V_51 -> V_264 [ V_265 ] ==
F_22 ( V_110 -> V_236 [ V_265 ] ) ) ;
ASSERT ( V_51 -> V_264 [ V_266 ] ==
F_22 ( V_110 -> V_236 [ V_266 ] ) ) ;
}
#endif
F_108 ( V_51 ) ;
return 0 ;
}
int
F_147 (
T_3 * args )
{
T_2 V_273 ;
int error ;
int V_60 ;
T_5 * V_2 ;
T_7 V_274 ;
T_12 type ;
int V_275 = 0 ;
T_7 V_276 = V_277 ;
V_2 = args -> V_2 ;
type = args -> V_278 = args -> type ;
args -> V_118 = V_45 ;
V_273 = V_2 -> V_3 . V_7 ;
if ( args -> V_50 > V_273 )
args -> V_50 = V_273 ;
if ( args -> V_29 == 0 )
args -> V_29 = 1 ;
ASSERT ( F_148 ( V_2 , args -> V_279 ) < V_2 -> V_3 . V_4 ) ;
ASSERT ( F_149 ( V_2 , args -> V_279 ) < V_273 ) ;
ASSERT ( args -> V_30 <= args -> V_50 ) ;
ASSERT ( args -> V_30 <= V_273 ) ;
ASSERT ( args -> V_48 < args -> V_49 ) ;
if ( F_148 ( V_2 , args -> V_279 ) >= V_2 -> V_3 . V_4 ||
F_149 ( V_2 , args -> V_279 ) >= V_273 ||
args -> V_30 > args -> V_50 || args -> V_30 > V_273 ||
args -> V_48 >= args -> V_49 ) {
args -> V_279 = V_280 ;
F_150 ( args ) ;
return 0 ;
}
switch ( type ) {
case V_115 :
case V_116 :
case V_117 :
args -> V_100 = F_148 ( V_2 , args -> V_279 ) ;
args -> V_51 = F_106 ( V_2 , args -> V_100 ) ;
error = F_122 ( args , 0 ) ;
if ( error ) {
F_151 ( args ) ;
goto V_130;
}
if ( ! args -> V_108 ) {
F_152 ( args ) ;
break;
}
args -> V_118 = F_149 ( V_2 , args -> V_279 ) ;
if ( ( error = F_62 ( args ) ) )
goto V_130;
break;
case V_281 :
if ( ( args -> V_34 & V_282 ) &&
( V_2 -> V_283 & V_284 ) ) {
args -> V_279 = F_153 ( V_2 ,
( ( V_2 -> V_285 / V_276 ) %
V_2 -> V_3 . V_4 ) , 0 ) ;
V_275 = 1 ;
}
args -> V_118 = F_149 ( V_2 , args -> V_279 ) ;
args -> type = V_116 ;
case V_286 :
case V_287 :
case V_288 :
if ( type == V_286 ) {
args -> V_100 = V_274 = ( V_2 -> V_285 / V_276 ) %
V_2 -> V_3 . V_4 ;
args -> type = V_115 ;
V_60 = V_213 ;
} else if ( type == V_288 ) {
args -> V_100 = F_148 ( V_2 , args -> V_279 ) ;
args -> type = V_115 ;
V_274 = 0 ;
V_60 = 0 ;
} else {
if ( type == V_287 )
args -> type = V_115 ;
args -> V_100 = V_274 = F_148 ( V_2 , args -> V_279 ) ;
V_60 = V_213 ;
}
for (; ; ) {
args -> V_51 = F_106 ( V_2 , args -> V_100 ) ;
error = F_122 ( args , V_60 ) ;
if ( error ) {
F_151 ( args ) ;
goto V_130;
}
if ( args -> V_108 ) {
if ( ( error = F_62 ( args ) ) )
goto V_130;
break;
}
F_154 ( args ) ;
if ( args -> V_100 == V_274 &&
type == V_281 )
args -> type = V_115 ;
if ( ++ ( args -> V_100 ) == V_2 -> V_3 . V_4 ) {
if ( args -> V_289 != V_280 )
args -> V_100 = V_274 ;
else
args -> V_100 = 0 ;
}
if ( args -> V_100 == V_274 ) {
if ( V_60 == 0 ) {
args -> V_118 = V_45 ;
F_155 ( args ) ;
break;
}
V_60 = 0 ;
if ( type == V_281 ) {
args -> V_118 = F_149 ( V_2 ,
args -> V_279 ) ;
args -> type = V_116 ;
}
}
F_108 ( args -> V_51 ) ;
}
if ( V_275 || ( type == V_286 ) ) {
if ( args -> V_100 == V_274 )
V_2 -> V_285 = ( V_2 -> V_285 + 1 ) %
( V_2 -> V_3 . V_4 * V_276 ) ;
else
V_2 -> V_285 = ( args -> V_100 * V_276 + 1 ) %
( V_2 -> V_3 . V_4 * V_276 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_118 == V_45 )
args -> V_279 = V_280 ;
else {
args -> V_279 = F_153 ( V_2 , args -> V_100 , args -> V_118 ) ;
#ifdef F_32
ASSERT ( args -> V_11 >= args -> V_30 ) ;
ASSERT ( args -> V_11 <= args -> V_50 ) ;
ASSERT ( args -> V_118 % args -> V_29 == 0 ) ;
F_156 ( V_2 , F_157 ( V_2 , args -> V_279 ) ,
args -> V_11 ) ;
#endif
if ( args -> V_34 & V_290 ) {
error = F_158 ( args -> V_291 , args -> V_279 , args -> V_11 ) ;
if ( error )
goto V_130;
}
}
F_108 ( args -> V_51 ) ;
return 0 ;
V_130:
F_108 ( args -> V_51 ) ;
return error ;
}
int
F_159 (
struct V_106 * V_99 ,
T_7 V_100 ,
struct V_75 * * V_108 )
{
struct V_135 args ;
int error ;
memset ( & args , 0 , sizeof( struct V_135 ) ) ;
args . V_99 = V_99 ;
args . V_2 = V_99 -> V_189 ;
args . V_100 = V_100 ;
if ( args . V_100 >= args . V_2 -> V_3 . V_4 )
return - V_92 ;
args . V_51 = F_106 ( args . V_2 , args . V_100 ) ;
ASSERT ( args . V_51 ) ;
error = F_122 ( & args , V_205 ) ;
if ( error )
goto V_292;
* V_108 = args . V_108 ;
V_292:
F_108 ( args . V_51 ) ;
return error ;
}
int
F_160 (
struct V_106 * V_99 ,
T_13 V_10 ,
T_1 V_11 ,
struct V_181 * V_121 ,
enum V_184 type )
{
struct V_1 * V_2 = V_99 -> V_189 ;
struct V_75 * V_108 ;
T_7 V_100 = F_148 ( V_2 , V_10 ) ;
T_2 V_118 = F_149 ( V_2 , V_10 ) ;
int error ;
ASSERT ( V_11 != 0 ) ;
ASSERT ( type != V_120 ) ;
if ( F_139 ( false , V_2 ,
V_293 ,
V_294 ) )
return - V_295 ;
error = F_159 ( V_99 , V_100 , & V_108 ) ;
if ( error )
return error ;
F_72 ( V_2 , V_118 < V_2 -> V_3 . V_7 , V_296 ) ;
F_72 ( V_2 ,
V_118 + V_11 <= F_22 ( F_57 ( V_108 ) -> V_112 ) ,
V_296 ) ;
error = F_112 ( V_99 , V_108 , V_100 , V_118 , V_11 , V_121 , type ) ;
if ( error )
goto V_296;
F_161 ( V_99 , V_100 , V_118 , V_11 , 0 ) ;
return 0 ;
V_296:
F_126 ( V_99 , V_108 ) ;
return error ;
}
