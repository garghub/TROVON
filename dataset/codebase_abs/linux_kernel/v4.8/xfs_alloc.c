T_1
F_1 (
struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) )
return F_3 ( V_2 ) + 1 ;
if ( F_4 ( & V_2 -> V_3 ) )
return F_5 ( V_2 ) + 1 ;
return F_6 ( V_2 ) + 1 ;
}
unsigned int
F_7 (
struct V_1 * V_2 )
{
unsigned int V_4 ;
V_4 = 4 + ( V_2 -> V_3 . V_5 * V_6 ) ;
if ( F_2 ( & V_2 -> V_3 ) )
V_4 += V_2 -> V_3 . V_5 * V_2 -> V_7 ;
return V_4 ;
}
unsigned int
F_8 (
struct V_1 * V_2 )
{
unsigned int V_4 ;
V_4 = F_9 ( V_2 , F_10 ( V_2 , 4 ) ) ;
V_4 += V_6 ;
V_4 += 3 ;
if ( F_4 ( & V_2 -> V_3 ) )
V_4 ++ ;
if ( F_2 ( & V_2 -> V_3 ) )
V_4 ++ ;
return V_2 -> V_3 . V_8 - V_4 ;
}
STATIC int
F_11 (
struct V_9 * V_10 ,
T_2 V_11 ,
T_1 V_12 ,
int * V_13 )
{
V_10 -> V_14 . V_15 . V_16 = V_11 ;
V_10 -> V_14 . V_15 . V_17 = V_12 ;
return F_12 ( V_10 , V_18 , V_13 ) ;
}
int
F_13 (
struct V_9 * V_10 ,
T_2 V_11 ,
T_1 V_12 ,
int * V_13 )
{
V_10 -> V_14 . V_15 . V_16 = V_11 ;
V_10 -> V_14 . V_15 . V_17 = V_12 ;
return F_12 ( V_10 , V_19 , V_13 ) ;
}
static int
F_14 (
struct V_9 * V_10 ,
T_2 V_11 ,
T_1 V_12 ,
int * V_13 )
{
V_10 -> V_14 . V_15 . V_16 = V_11 ;
V_10 -> V_14 . V_15 . V_17 = V_12 ;
return F_12 ( V_10 , V_20 , V_13 ) ;
}
STATIC int
F_15 (
struct V_9 * V_10 ,
T_2 V_11 ,
T_1 V_12 )
{
union V_21 V_22 ;
V_22 . V_23 . V_16 = F_16 ( V_11 ) ;
V_22 . V_23 . V_17 = F_16 ( V_12 ) ;
return F_17 ( V_10 , & V_22 ) ;
}
int
F_18 (
struct V_9 * V_10 ,
T_2 * V_11 ,
T_1 * V_12 ,
int * V_13 )
{
union V_21 * V_22 ;
int error ;
error = F_19 ( V_10 , & V_22 , V_13 ) ;
if ( ! error && * V_13 == 1 ) {
* V_11 = F_20 ( V_22 -> V_23 . V_16 ) ;
* V_12 = F_20 ( V_22 -> V_23 . V_17 ) ;
}
return error ;
}
STATIC void
F_21 (
T_3 * args ,
T_2 V_24 ,
T_1 V_25 ,
T_2 * V_26 ,
T_1 * V_27 )
{
T_2 V_11 ;
T_1 V_12 ;
T_1 V_28 ;
F_22 ( args , V_24 , V_25 , & V_11 , & V_12 ) ;
if ( V_11 < args -> V_29 && V_11 + V_12 > args -> V_29 ) {
V_28 = args -> V_29 - V_11 ;
if ( V_12 > V_28 ) {
V_11 += V_28 ;
V_12 -= V_28 ;
}
}
if ( args -> V_30 > 1 && V_12 >= args -> V_31 ) {
T_2 V_32 = F_23 ( V_11 , args -> V_30 ) ;
V_28 = V_32 - V_11 ;
* V_26 = V_32 ;
* V_27 = V_28 >= V_12 ? 0 : V_12 - V_28 ;
} else {
* V_26 = V_11 ;
* V_27 = V_12 ;
}
}
STATIC T_1
F_24 (
T_2 V_33 ,
T_1 V_34 ,
T_1 V_30 ,
char V_35 ,
T_2 V_36 ,
T_1 V_37 ,
T_2 * V_38 )
{
T_2 V_39 ;
T_2 V_40 ;
T_2 V_41 ;
T_1 V_42 = 0 ;
T_1 V_43 = 0 ;
T_2 V_44 ;
ASSERT ( V_37 >= V_34 ) ;
V_39 = V_36 + V_37 ;
V_44 = V_33 + V_34 ;
if ( V_36 >= V_33 || ( V_35 && V_39 < V_44 ) ) {
if ( ( V_40 = F_23 ( V_36 , V_30 ) ) >= V_39 )
V_40 = V_45 ;
} else if ( V_39 >= V_44 && V_30 > 1 ) {
V_40 = F_23 ( V_33 , V_30 ) ;
V_41 = V_40 - V_30 ;
if ( V_40 >= V_39 )
V_40 = V_45 ;
else
V_42 = F_25 ( V_34 , V_39 - V_40 ) ;
if ( V_41 < V_36 )
V_41 = V_45 ;
else
V_43 = F_25 ( V_34 , V_39 - V_41 ) ;
if ( V_40 != V_45 && V_41 != V_45 ) {
if ( V_42 < V_43 ||
( V_42 == V_43 &&
F_26 ( V_40 , V_33 ) >
F_26 ( V_41 , V_33 ) ) )
V_40 = V_41 ;
} else if ( V_41 != V_45 )
V_40 = V_41 ;
} else if ( V_39 >= V_44 ) {
V_40 = V_33 ;
} else if ( V_30 > 1 ) {
V_40 = F_23 ( V_39 - V_34 , V_30 ) ;
if ( V_40 > V_39 - V_34 &&
V_40 - V_30 >= V_36 )
V_40 -= V_30 ;
else if ( V_40 >= V_39 )
V_40 = V_45 ;
} else
V_40 = V_39 - V_34 ;
* V_38 = V_40 ;
return V_40 == V_45 ? 0 : F_26 ( V_40 , V_33 ) ;
}
STATIC void
F_27 (
T_3 * args )
{
T_1 V_46 ;
T_1 V_47 ;
ASSERT ( args -> V_48 < args -> V_49 ) ;
V_47 = args -> V_12 ;
ASSERT ( V_47 >= args -> V_31 ) ;
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
if ( ( int ) V_47 < ( int ) args -> V_31 )
return;
ASSERT ( V_47 >= args -> V_31 && V_47 <= args -> V_50 ) ;
ASSERT ( V_47 % args -> V_49 == args -> V_48 ) ;
args -> V_12 = V_47 ;
}
STATIC int
F_28 (
T_3 * args )
{
T_4 * V_51 ;
int V_28 ;
if ( args -> V_52 == 0 )
return 1 ;
V_51 = F_29 ( args -> V_53 ) ;
V_28 = F_20 ( V_51 -> V_54 )
- args -> V_12 - args -> V_52 ;
if ( V_28 >= 0 )
return 1 ;
args -> V_12 += V_28 ;
if ( ( int ) args -> V_12 >= ( int ) args -> V_31 )
return 1 ;
args -> V_55 = V_45 ;
return 0 ;
}
STATIC int
F_30 (
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
#ifdef F_31
if ( ( error = F_18 ( V_56 , & V_63 , & V_65 , & V_62 ) ) )
return error ;
F_32 ( V_2 ,
V_62 == 1 && V_63 == V_58 && V_65 == V_59 ) ;
#endif
} else {
if ( ( error = F_11 ( V_56 , V_58 , V_59 , & V_62 ) ) )
return error ;
F_32 ( V_2 , V_62 == 1 ) ;
}
if ( V_61 & V_69 ) {
#ifdef F_31
if ( ( error = F_18 ( V_57 , & V_63 , & V_65 , & V_62 ) ) )
return error ;
F_32 ( V_2 ,
V_62 == 1 && V_63 == V_58 && V_65 == V_59 ) ;
#endif
} else {
if ( ( error = F_11 ( V_57 , V_58 , V_59 , & V_62 ) ) )
return error ;
F_32 ( V_2 , V_62 == 1 ) ;
}
#ifdef F_31
if ( V_57 -> V_70 == 1 && V_56 -> V_70 == 1 ) {
struct V_71 * V_72 ;
struct V_71 * V_73 ;
V_72 = F_33 ( V_57 -> V_74 [ 0 ] ) ;
V_73 = F_33 ( V_56 -> V_74 [ 0 ] ) ;
F_32 ( V_2 ,
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
if ( ( error = F_34 ( V_56 , & V_62 ) ) )
return error ;
F_32 ( V_2 , V_62 == 1 ) ;
if ( V_63 != V_45 ) {
if ( ( error = F_11 ( V_56 , V_63 , V_65 , & V_62 ) ) )
return error ;
F_32 ( V_2 , V_62 == 0 ) ;
if ( ( error = F_35 ( V_56 , & V_62 ) ) )
return error ;
F_32 ( V_2 , V_62 == 1 ) ;
}
if ( V_64 != V_45 ) {
if ( ( error = F_11 ( V_56 , V_64 , V_66 , & V_62 ) ) )
return error ;
F_32 ( V_2 , V_62 == 0 ) ;
if ( ( error = F_35 ( V_56 , & V_62 ) ) )
return error ;
F_32 ( V_2 , V_62 == 1 ) ;
}
if ( V_63 == V_45 ) {
if ( ( error = F_34 ( V_57 , & V_62 ) ) )
return error ;
F_32 ( V_2 , V_62 == 1 ) ;
} else {
if ( ( error = F_15 ( V_57 , V_63 , V_65 ) ) )
return error ;
}
if ( V_64 != V_45 ) {
if ( ( error = F_11 ( V_57 , V_64 , V_66 , & V_62 ) ) )
return error ;
F_32 ( V_2 , V_62 == 0 ) ;
if ( ( error = F_35 ( V_57 , & V_62 ) ) )
return error ;
F_32 ( V_2 , V_62 == 1 ) ;
}
return 0 ;
}
static bool
F_36 (
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_78 -> V_79 ;
struct V_80 * V_81 = F_37 ( V_77 ) ;
int V_62 ;
if ( ! F_38 ( & V_81 -> V_82 , & V_2 -> V_3 . V_83 ) )
return false ;
if ( F_20 ( V_81 -> V_84 ) != V_85 )
return false ;
if ( V_77 -> V_86 && F_20 ( V_81 -> V_87 ) != V_77 -> V_86 -> V_88 )
return false ;
for ( V_62 = 0 ; V_62 < F_39 ( V_2 ) ; V_62 ++ ) {
if ( F_20 ( V_81 -> V_89 [ V_62 ] ) != V_45 &&
F_20 ( V_81 -> V_89 [ V_62 ] ) >= V_2 -> V_3 . V_8 )
return false ;
}
return F_40 ( V_2 ,
F_41 ( F_37 ( V_77 ) -> V_90 ) ) ;
}
static void
F_42 (
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_78 -> V_79 ;
if ( ! F_43 ( & V_2 -> V_3 ) )
return;
if ( ! F_44 ( V_77 , V_91 ) )
F_45 ( V_77 , - V_92 ) ;
else if ( ! F_36 ( V_77 ) )
F_45 ( V_77 , - V_93 ) ;
if ( V_77 -> V_94 )
F_46 ( V_77 ) ;
}
static void
F_47 (
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_78 -> V_79 ;
struct V_95 * V_96 = V_77 -> V_97 ;
if ( ! F_43 ( & V_2 -> V_3 ) )
return;
if ( ! F_36 ( V_77 ) ) {
F_45 ( V_77 , - V_93 ) ;
F_46 ( V_77 ) ;
return;
}
if ( V_96 )
F_37 ( V_77 ) -> V_90 = F_48 ( V_96 -> V_98 . V_99 ) ;
F_49 ( V_77 , V_91 ) ;
}
STATIC int
F_50 (
T_6 * V_2 ,
T_7 * V_100 ,
T_8 V_101 ,
T_9 * * V_102 )
{
T_9 * V_77 ;
int error ;
ASSERT ( V_101 != V_103 ) ;
error = F_51 (
V_2 , V_100 , V_2 -> V_104 ,
F_52 ( V_2 , V_101 , F_53 ( V_2 ) ) ,
F_10 ( V_2 , 1 ) , 0 , & V_77 , & V_105 ) ;
if ( error )
return error ;
F_54 ( V_77 , V_106 ) ;
* V_102 = V_77 ;
return 0 ;
}
STATIC int
F_55 (
struct V_107 * V_100 ,
struct V_108 * V_109 ,
struct V_76 * V_53 ,
long V_12 )
{
struct V_110 * V_51 = F_29 ( V_53 ) ;
V_109 -> V_111 += V_12 ;
F_56 ( & V_51 -> V_54 , V_12 ) ;
F_57 ( V_100 , V_12 ) ;
if ( F_58 ( F_20 ( V_51 -> V_54 ) >
F_20 ( V_51 -> V_112 ) ) )
return - V_93 ;
F_59 ( V_100 , V_53 , V_113 ) ;
return 0 ;
}
STATIC int
F_60 (
T_3 * args )
{
int error = 0 ;
ASSERT ( args -> V_31 > 0 ) ;
ASSERT ( args -> V_50 > 0 ) ;
ASSERT ( args -> V_31 <= args -> V_50 ) ;
ASSERT ( args -> V_48 < args -> V_49 ) ;
ASSERT ( args -> V_30 > 0 ) ;
args -> V_114 = 0 ;
switch ( args -> type ) {
case V_115 :
error = F_61 ( args ) ;
break;
case V_116 :
error = F_62 ( args ) ;
break;
case V_117 :
error = F_63 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error || args -> V_55 == V_45 )
return error ;
ASSERT ( args -> V_12 >= args -> V_31 ) ;
ASSERT ( args -> V_12 <= args -> V_50 ) ;
ASSERT ( ! args -> V_114 || ! args -> V_118 ) ;
ASSERT ( args -> V_55 % args -> V_30 == 0 ) ;
if ( args -> V_119 . V_120 != V_121 ) {
error = F_64 ( args -> V_100 , args -> V_53 , args -> V_101 ,
args -> V_55 , args -> V_12 , & args -> V_119 ) ;
if ( error )
return error ;
}
if ( ! args -> V_114 ) {
error = F_55 ( args -> V_100 , args -> V_109 ,
args -> V_53 ,
- ( ( long ) ( args -> V_12 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_65 ( args -> V_2 , args -> V_101 ,
args -> V_55 , args -> V_12 ) ) ;
}
if ( ! args -> V_118 ) {
F_66 ( args -> V_100 , args -> V_122 ?
V_123 :
V_124 ,
- ( ( long ) ( args -> V_12 ) ) ) ;
}
F_67 ( args -> V_2 , V_125 ) ;
F_68 ( args -> V_2 , V_126 , args -> V_12 ) ;
return error ;
}
STATIC int
F_63 (
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
ASSERT ( args -> V_30 == 1 ) ;
V_57 = F_69 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_130 ) ;
error = F_14 ( V_57 , args -> V_55 , args -> V_31 , & V_62 ) ;
if ( error )
goto V_131;
if ( ! V_62 )
goto V_132;
error = F_18 ( V_57 , & V_58 , & V_59 , & V_62 ) ;
if ( error )
goto V_131;
F_70 ( args -> V_2 , V_62 == 1 , V_131 ) ;
ASSERT ( V_58 <= args -> V_55 ) ;
F_22 ( args , V_58 , V_59 , & V_127 , & V_128 ) ;
if ( V_127 > args -> V_55 )
goto V_132;
if ( V_128 < args -> V_31 )
goto V_132;
V_129 = V_127 + V_128 ;
if ( V_129 < args -> V_55 + args -> V_31 )
goto V_132;
args -> V_12 = F_71 ( V_129 , args -> V_55 + args -> V_50 )
- args -> V_55 ;
F_27 ( args ) ;
if ( ! F_28 ( args ) )
goto V_132;
ASSERT ( args -> V_55 + args -> V_12 <= V_129 ) ;
V_56 = F_69 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_133 ) ;
ASSERT ( args -> V_55 + args -> V_12 <=
F_20 ( F_29 ( args -> V_53 ) -> V_112 ) ) ;
error = F_30 ( V_56 , V_57 , V_58 , V_59 , args -> V_55 ,
args -> V_12 , V_69 ) ;
if ( error ) {
F_72 ( V_56 , V_134 ) ;
goto V_131;
}
F_72 ( V_57 , V_135 ) ;
F_72 ( V_56 , V_135 ) ;
args -> V_114 = 0 ;
F_73 ( args ) ;
return 0 ;
V_132:
F_72 ( V_57 , V_135 ) ;
args -> V_55 = V_45 ;
F_74 ( args ) ;
return 0 ;
V_131:
F_72 ( V_57 , V_134 ) ;
F_75 ( args ) ;
return error ;
}
STATIC int
F_76 (
struct V_136 * args ,
struct V_9 * * V_137 ,
struct V_9 * * V_138 ,
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
error = F_18 ( * V_138 , V_140 , V_141 , & V_62 ) ;
if ( error )
goto V_131;
F_70 ( args -> V_2 , V_62 == 1 , V_131 ) ;
F_21 ( args , * V_140 , * V_141 , V_142 , V_143 ) ;
if ( ! V_144 ) {
if ( * V_142 > args -> V_148 )
goto V_147;
if ( * V_142 >= args -> V_55 + V_139 )
goto V_147;
} else {
if ( * V_142 < args -> V_29 )
goto V_147;
if ( * V_142 <= args -> V_55 - V_139 )
goto V_147;
}
if ( * V_143 >= args -> V_31 ) {
args -> V_12 = F_25 ( * V_143 , args -> V_50 ) ;
F_27 ( args ) ;
V_146 = F_24 ( args -> V_55 , args -> V_12 ,
args -> V_30 ,
args -> V_35 , * V_142 ,
* V_143 , & V_145 ) ;
if ( V_146 < V_139 )
goto V_149;
goto V_147;
}
if ( ! V_144 )
error = F_77 ( * V_138 , 0 , & V_62 ) ;
else
error = F_78 ( * V_138 , 0 , & V_62 ) ;
if ( error )
goto V_131;
} while ( V_62 );
V_147:
F_72 ( * V_138 , V_135 ) ;
* V_138 = NULL ;
return 0 ;
V_149:
F_72 ( * V_137 , V_135 ) ;
* V_137 = NULL ;
return 0 ;
V_131:
return error ;
}
STATIC int
F_62 (
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
#ifdef F_31
int V_166 ;
V_166 = F_79 () & 1 ;
#endif
if ( ! args -> V_29 && ! args -> V_148 )
args -> V_148 = args -> V_2 -> V_3 . V_8 - 1 ;
ASSERT ( args -> V_29 <= args -> V_148 ) ;
if ( args -> V_55 < args -> V_29 )
args -> V_55 = args -> V_29 ;
if ( args -> V_55 > args -> V_148 )
args -> V_55 = args -> V_148 ;
V_167:
V_151 = NULL ;
V_150 = NULL ;
V_162 = 0 ;
V_156 = 0 ;
V_163 = 0 ;
V_56 = F_69 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_133 ) ;
if ( ( error = F_13 ( V_56 , 0 , args -> V_50 , & V_62 ) ) )
goto V_131;
if ( ! V_62 ) {
if ( ( error = F_80 ( args , V_56 , & V_159 ,
& V_162 , & V_62 ) ) )
goto V_131;
if ( V_62 == 0 || V_162 == 0 ) {
F_72 ( V_56 , V_135 ) ;
F_81 ( args ) ;
return 0 ;
}
ASSERT ( V_62 == 1 ) ;
}
args -> V_114 = 0 ;
while ( F_82 ( V_56 , 0 ) ) {
T_1 V_168 ;
int V_169 = 0 ;
T_1 V_170 = 0 ;
T_2 V_171 = 0 ;
#ifdef F_31
if ( V_166 )
break;
#endif
if ( V_162 || args -> V_30 > 1 ) {
V_56 -> V_172 [ 0 ] = 1 ;
do {
if ( ( error = F_18 ( V_56 , & V_159 ,
& V_162 , & V_62 ) ) )
goto V_131;
F_70 ( args -> V_2 , V_62 == 1 , V_131 ) ;
if ( V_162 >= args -> V_31 )
break;
if ( ( error = F_77 ( V_56 , 0 , & V_62 ) ) )
goto V_131;
} while ( V_62 );
ASSERT ( V_162 >= args -> V_31 ) ;
if ( ! V_62 )
break;
}
V_62 = V_56 -> V_172 [ 0 ] ;
for ( V_158 = 1 , V_170 = 0 , V_168 = 0 ;
! error && V_158 && ( V_170 < args -> V_50 || V_168 > 0 ) ;
error = F_77 ( V_56 , 0 , & V_158 ) ) {
if ( ( error = F_18 ( V_56 , & V_159 , & V_162 , & V_62 ) ) )
goto V_131;
F_70 ( args -> V_2 , V_62 == 1 , V_131 ) ;
F_21 ( args , V_159 , V_162 ,
& V_160 , & V_163 ) ;
if ( V_163 < args -> V_31 )
continue;
if ( V_160 < args -> V_29 || V_160 > args -> V_148 )
continue;
args -> V_12 = F_25 ( V_163 , args -> V_50 ) ;
F_27 ( args ) ;
ASSERT ( args -> V_12 >= args -> V_31 ) ;
if ( args -> V_12 < V_170 )
continue;
V_161 = F_24 ( args -> V_55 , args -> V_12 ,
args -> V_30 , args -> V_35 , V_160 ,
V_163 , & V_164 ) ;
if ( V_164 != V_45 &&
( args -> V_12 > V_170 || V_161 < V_168 ) ) {
V_168 = V_161 ;
V_171 = V_164 ;
V_170 = args -> V_12 ;
V_169 = V_56 -> V_172 [ 0 ] ;
}
}
if ( V_170 == 0 )
break;
V_56 -> V_172 [ 0 ] = V_169 ;
if ( ( error = F_18 ( V_56 , & V_159 , & V_162 , & V_62 ) ) )
goto V_131;
F_70 ( args -> V_2 , V_62 == 1 , V_131 ) ;
ASSERT ( V_159 + V_162 <= F_20 ( F_29 ( args -> V_53 ) -> V_112 ) ) ;
args -> V_12 = V_170 ;
if ( ! F_28 ( args ) ) {
F_72 ( V_56 , V_135 ) ;
F_83 ( args ) ;
return 0 ;
}
V_170 = args -> V_12 ;
args -> V_55 = V_171 ;
ASSERT ( V_171 >= V_159 ) ;
ASSERT ( V_171 + V_170 <= V_159 + V_162 ) ;
V_151 = F_69 ( args -> V_2 , args -> V_100 ,
args -> V_53 , args -> V_101 , V_130 ) ;
if ( ( error = F_30 ( V_56 , V_151 , V_159 ,
V_162 , V_171 , V_170 , V_68 ) ) )
goto V_131;
F_72 ( V_56 , V_135 ) ;
F_72 ( V_151 , V_135 ) ;
F_84 ( args ) ;
return 0 ;
}
V_151 = F_69 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_130 ) ;
if ( ( error = F_14 ( V_151 , args -> V_55 , args -> V_50 , & V_62 ) ) )
goto V_131;
if ( ! V_62 ) {
V_150 = V_151 ;
V_151 = NULL ;
}
else if ( ( error = F_85 ( V_151 , & V_150 ) ) )
goto V_131;
if ( ( error = F_77 ( V_150 , 0 , & V_62 ) ) )
goto V_131;
if ( ! V_62 ) {
F_72 ( V_150 , V_135 ) ;
V_150 = NULL ;
}
do {
if ( V_151 ) {
if ( ( error = F_18 ( V_151 , & V_159 , & V_162 , & V_62 ) ) )
goto V_131;
F_70 ( args -> V_2 , V_62 == 1 , V_131 ) ;
F_21 ( args , V_159 , V_162 ,
& V_160 , & V_163 ) ;
if ( V_163 >= args -> V_31 && V_160 >= args -> V_29 )
break;
if ( ( error = F_78 ( V_151 , 0 , & V_62 ) ) )
goto V_131;
if ( ! V_62 || V_160 < args -> V_29 ) {
F_72 ( V_151 ,
V_135 ) ;
V_151 = NULL ;
}
}
if ( V_150 ) {
if ( ( error = F_18 ( V_150 , & V_152 , & V_155 , & V_62 ) ) )
goto V_131;
F_70 ( args -> V_2 , V_62 == 1 , V_131 ) ;
F_21 ( args , V_152 , V_155 ,
& V_153 , & V_156 ) ;
if ( V_156 >= args -> V_31 && V_153 <= args -> V_148 )
break;
if ( ( error = F_77 ( V_150 , 0 , & V_62 ) ) )
goto V_131;
if ( ! V_62 || V_153 > args -> V_148 ) {
F_72 ( V_150 ,
V_135 ) ;
V_150 = NULL ;
}
}
} while ( V_151 || V_150 );
if ( V_151 && V_150 ) {
if ( V_163 >= args -> V_31 ) {
args -> V_12 = F_25 ( V_163 , args -> V_50 ) ;
F_27 ( args ) ;
V_161 = F_24 ( args -> V_55 , args -> V_12 ,
args -> V_30 , args -> V_35 , V_160 ,
V_163 , & V_164 ) ;
error = F_76 ( args ,
& V_151 , & V_150 ,
V_161 , & V_152 , & V_155 ,
& V_153 , & V_156 ,
0 ) ;
} else {
ASSERT ( V_156 >= args -> V_31 ) ;
args -> V_12 = F_25 ( V_156 , args -> V_50 ) ;
F_27 ( args ) ;
V_154 = F_24 ( args -> V_55 , args -> V_12 ,
args -> V_30 , args -> V_35 , V_153 ,
V_156 , & V_157 ) ;
error = F_76 ( args ,
& V_150 , & V_151 ,
V_154 , & V_159 , & V_162 ,
& V_160 , & V_163 ,
1 ) ;
}
if ( error )
goto V_131;
}
if ( V_151 == NULL && V_150 == NULL ) {
F_72 ( V_56 , V_135 ) ;
if ( ! V_165 ++ ) {
F_86 ( args ) ;
F_87 ( args -> V_2 , V_173 ) ;
goto V_167;
}
F_88 ( args ) ;
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
args -> V_12 = F_25 ( V_163 , args -> V_50 ) ;
F_27 ( args ) ;
if ( ! F_28 ( args ) ) {
F_83 ( args ) ;
F_72 ( V_151 , V_135 ) ;
F_72 ( V_56 , V_135 ) ;
return 0 ;
}
V_47 = args -> V_12 ;
( void ) F_24 ( args -> V_55 , V_47 , args -> V_30 ,
args -> V_35 , V_160 , V_163 , & V_164 ) ;
ASSERT ( V_164 >= V_159 ) ;
ASSERT ( V_164 + V_47 <= V_160 + V_163 ) ;
ASSERT ( V_164 + V_47 <= F_20 ( F_29 ( args -> V_53 ) -> V_112 ) ) ;
ASSERT ( V_164 >= args -> V_29 && V_164 <= args -> V_148 ) ;
args -> V_55 = V_164 ;
if ( ( error = F_30 ( V_56 , V_151 , V_159 , V_162 ,
V_164 , V_47 , V_69 ) ) )
goto V_131;
if ( V_158 )
F_89 ( args ) ;
else
F_90 ( args ) ;
F_72 ( V_56 , V_135 ) ;
F_72 ( V_151 , V_135 ) ;
return 0 ;
V_131:
F_91 ( args ) ;
if ( V_56 != NULL )
F_72 ( V_56 , V_134 ) ;
if ( V_151 != NULL )
F_72 ( V_151 , V_134 ) ;
if ( V_150 != NULL )
F_72 ( V_150 , V_134 ) ;
return error ;
}
STATIC int
F_61 (
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
V_56 = F_69 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_133 ) ;
V_57 = NULL ;
if ( ( error = F_13 ( V_56 , 0 ,
args -> V_50 + args -> V_30 - 1 , & V_62 ) ) )
goto V_131;
if ( ! V_62 || V_165 > 1 ) {
error = F_80 ( args , V_56 ,
& V_58 , & V_59 , & V_62 ) ;
if ( error )
goto V_131;
if ( V_62 == 0 || V_59 == 0 ) {
F_72 ( V_56 , V_135 ) ;
F_92 ( args ) ;
return 0 ;
}
ASSERT ( V_62 == 1 ) ;
F_21 ( args , V_58 , V_59 , & V_60 , & V_47 ) ;
} else {
for (; ; ) {
error = F_18 ( V_56 , & V_58 , & V_59 , & V_62 ) ;
if ( error )
goto V_131;
F_70 ( args -> V_2 , V_62 == 1 , V_131 ) ;
F_21 ( args , V_58 , V_59 ,
& V_60 , & V_47 ) ;
if ( V_47 >= args -> V_50 )
break;
error = F_77 ( V_56 , 0 , & V_62 ) ;
if ( error )
goto V_131;
if ( V_62 == 0 ) {
F_72 ( V_56 ,
V_135 ) ;
F_93 ( args ) ;
if ( ! V_165 ++ )
F_87 ( args -> V_2 , V_173 ) ;
goto V_167;
}
}
}
V_47 = F_25 ( args -> V_50 , V_47 ) ;
F_70 ( args -> V_2 , V_47 == 0 ||
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
if ( ( error = F_78 ( V_56 , 0 , & V_62 ) ) )
goto V_131;
if ( V_62 == 0 )
break;
if ( ( error = F_18 ( V_56 , & V_58 , & V_59 ,
& V_62 ) ) )
goto V_131;
F_70 ( args -> V_2 , V_62 == 1 , V_131 ) ;
if ( V_59 < V_177 )
break;
F_21 ( args , V_58 , V_59 ,
& V_60 , & V_47 ) ;
V_47 = F_25 ( args -> V_50 , V_47 ) ;
F_70 ( args -> V_2 , V_47 == 0 ||
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
if ( ( error = F_11 ( V_56 , V_174 , V_175 ,
& V_62 ) ) )
goto V_131;
F_70 ( args -> V_2 , V_62 == 1 , V_131 ) ;
V_47 = V_177 ;
V_60 = V_176 ;
V_59 = V_175 ;
V_58 = V_174 ;
}
args -> V_114 = 0 ;
args -> V_12 = V_47 ;
if ( V_47 < args -> V_31 ) {
if ( ! V_165 ++ ) {
F_72 ( V_56 , V_135 ) ;
F_93 ( args ) ;
F_87 ( args -> V_2 , V_173 ) ;
goto V_167;
}
goto V_178;
}
F_27 ( args ) ;
if ( ! F_28 ( args ) )
goto V_178;
V_47 = args -> V_12 ;
F_70 ( args -> V_2 , V_47 <= V_59 , V_131 ) ;
V_57 = F_69 ( args -> V_2 , args -> V_100 , args -> V_53 ,
args -> V_101 , V_130 ) ;
if ( ( error = F_30 ( V_56 , V_57 , V_58 , V_59 ,
V_60 , V_47 , V_68 ) ) )
goto V_131;
F_72 ( V_56 , V_135 ) ;
F_72 ( V_57 , V_135 ) ;
V_56 = V_57 = NULL ;
args -> V_12 = V_47 ;
args -> V_55 = V_60 ;
F_70 ( args -> V_2 ,
args -> V_55 + args -> V_12 <=
F_20 ( F_29 ( args -> V_53 ) -> V_112 ) ,
V_131 ) ;
F_94 ( args ) ;
return 0 ;
V_131:
F_95 ( args ) ;
if ( V_56 )
F_72 ( V_56 , V_134 ) ;
if ( V_57 )
F_72 ( V_57 , V_134 ) ;
return error ;
V_178:
F_72 ( V_56 , V_135 ) ;
F_96 ( args ) ;
args -> V_55 = V_45 ;
return 0 ;
}
STATIC int
F_80 (
T_3 * args ,
T_5 * V_179 ,
T_2 * V_180 ,
T_1 * V_181 ,
int * V_13 )
{
struct V_182 V_119 ;
int error ;
T_2 V_58 ;
T_1 V_59 ;
int V_62 ;
if ( ( error = F_78 ( V_179 , 0 , & V_62 ) ) )
goto V_131;
if ( V_62 ) {
if ( ( error = F_18 ( V_179 , & V_58 , & V_59 , & V_62 ) ) )
goto V_131;
F_70 ( args -> V_2 , V_62 == 1 , V_131 ) ;
}
else if ( args -> V_31 == 1 && args -> V_30 == 1 && ! args -> V_118 &&
( F_20 ( F_29 ( args -> V_53 ) -> V_183 )
> args -> V_52 ) ) {
error = F_97 ( args -> V_100 , args -> V_53 , & V_58 , 0 ) ;
if ( error )
goto V_131;
if ( V_58 != V_45 ) {
F_98 ( args -> V_2 , args -> V_101 , V_58 , 1 ,
args -> V_35 ) ;
if ( args -> V_35 ) {
T_9 * V_77 ;
V_77 = F_99 ( args -> V_2 , args -> V_100 ,
args -> V_101 , V_58 , 0 ) ;
F_100 ( args -> V_100 , V_77 ) ;
}
args -> V_12 = 1 ;
args -> V_55 = V_58 ;
F_70 ( args -> V_2 ,
args -> V_55 + args -> V_12 <=
F_20 ( F_29 ( args -> V_53 ) -> V_112 ) ,
V_131 ) ;
args -> V_114 = 1 ;
F_101 ( args ) ;
F_102 ( & V_119 , V_184 ) ;
error = F_103 ( args -> V_100 , args -> V_53 , args -> V_101 ,
V_58 , 1 , & V_119 ) ;
if ( error )
goto V_131;
* V_13 = 0 ;
return 0 ;
}
else
V_59 = 0 ;
}
else {
V_58 = V_45 ;
V_59 = 0 ;
}
if ( V_59 < args -> V_31 ) {
args -> V_55 = V_45 ;
F_104 ( args ) ;
V_59 = 0 ;
}
* V_180 = V_58 ;
* V_181 = V_59 ;
* V_13 = 1 ;
F_105 ( args ) ;
return 0 ;
V_131:
F_106 ( args ) ;
return error ;
}
STATIC int
F_107 (
T_7 * V_100 ,
T_9 * V_53 ,
T_8 V_101 ,
T_2 V_11 ,
T_1 V_12 ,
struct V_182 * V_119 ,
int V_118 )
{
T_5 * V_57 ;
T_5 * V_56 ;
int error ;
T_2 V_152 ;
T_1 V_155 ;
int V_185 ;
int V_186 ;
int V_62 ;
T_2 V_159 ;
T_1 V_162 ;
T_6 * V_2 ;
T_2 V_187 ;
T_1 V_188 ;
T_10 * V_109 ;
V_57 = V_56 = NULL ;
V_2 = V_100 -> V_189 ;
if ( V_119 -> V_120 != V_121 ) {
error = F_103 ( V_100 , V_53 , V_101 , V_11 , V_12 , V_119 ) ;
if ( error )
goto V_131;
}
V_57 = F_69 ( V_2 , V_100 , V_53 , V_101 , V_130 ) ;
if ( ( error = F_14 ( V_57 , V_11 , V_12 , & V_185 ) ) )
goto V_131;
if ( V_185 ) {
if ( ( error = F_18 ( V_57 , & V_159 , & V_162 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
if ( V_159 + V_162 < V_11 )
V_185 = 0 ;
else {
F_70 ( V_2 ,
V_159 + V_162 <= V_11 , V_131 ) ;
}
}
if ( ( error = F_77 ( V_57 , 0 , & V_186 ) ) )
goto V_131;
if ( V_186 ) {
if ( ( error = F_18 ( V_57 , & V_152 , & V_155 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
if ( V_11 + V_12 < V_152 )
V_186 = 0 ;
else {
F_70 ( V_2 , V_152 >= V_11 + V_12 , V_131 ) ;
}
}
V_56 = F_69 ( V_2 , V_100 , V_53 , V_101 , V_133 ) ;
if ( V_185 && V_186 ) {
if ( ( error = F_11 ( V_56 , V_159 , V_162 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_34 ( V_56 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_11 ( V_56 , V_152 , V_155 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_34 ( V_56 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_34 ( V_57 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_78 ( V_57 , 0 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
#ifdef F_31
{
T_2 V_190 ;
T_1 V_191 ;
if ( ( error = F_18 ( V_57 , & V_190 , & V_191 ,
& V_62 ) ) )
goto V_131;
F_70 ( V_2 ,
V_62 == 1 && V_190 == V_159 && V_191 == V_162 ,
V_131 ) ;
}
#endif
V_187 = V_159 ;
V_188 = V_12 + V_162 + V_155 ;
if ( ( error = F_15 ( V_57 , V_187 , V_188 ) ) )
goto V_131;
}
else if ( V_185 ) {
if ( ( error = F_11 ( V_56 , V_159 , V_162 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_34 ( V_56 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_78 ( V_57 , 0 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
V_187 = V_159 ;
V_188 = V_12 + V_162 ;
if ( ( error = F_15 ( V_57 , V_187 , V_188 ) ) )
goto V_131;
}
else if ( V_186 ) {
if ( ( error = F_11 ( V_56 , V_152 , V_155 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
if ( ( error = F_34 ( V_56 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
V_187 = V_11 ;
V_188 = V_12 + V_155 ;
if ( ( error = F_15 ( V_57 , V_187 , V_188 ) ) )
goto V_131;
}
else {
V_187 = V_11 ;
V_188 = V_12 ;
if ( ( error = F_35 ( V_57 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
}
F_72 ( V_57 , V_135 ) ;
V_57 = NULL ;
if ( ( error = F_11 ( V_56 , V_187 , V_188 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 0 , V_131 ) ;
if ( ( error = F_35 ( V_56 , & V_62 ) ) )
goto V_131;
F_70 ( V_2 , V_62 == 1 , V_131 ) ;
F_72 ( V_56 , V_135 ) ;
V_56 = NULL ;
V_109 = F_108 ( V_2 , V_101 ) ;
error = F_55 ( V_100 , V_109 , V_53 , V_12 ) ;
F_109 ( V_109 ) ;
if ( error )
goto V_131;
if ( ! V_118 )
F_66 ( V_100 , V_124 , ( long ) V_12 ) ;
F_67 ( V_2 , V_192 ) ;
F_68 ( V_2 , V_193 , V_12 ) ;
F_110 ( V_2 , V_101 , V_11 , V_12 , V_118 , V_185 , V_186 ) ;
return 0 ;
V_131:
F_110 ( V_2 , V_101 , V_11 , V_12 , V_118 , - 1 , - 1 ) ;
if ( V_57 )
F_72 ( V_57 , V_134 ) ;
if ( V_56 )
F_72 ( V_56 , V_134 ) ;
return error ;
}
void
F_111 (
T_6 * V_2 )
{
V_2 -> V_194 = F_112 ( V_2 , V_2 -> V_195 ,
( V_2 -> V_3 . V_8 + 1 ) / 2 ) ;
}
T_1
F_113 (
struct V_1 * V_2 ,
struct V_108 * V_109 ,
T_1 V_196 )
{
T_1 V_197 = 0 ;
if ( V_196 > V_109 -> V_198 )
V_197 = V_196 - V_109 -> V_198 ;
if ( V_109 -> V_199 > V_197 )
return V_109 -> V_199 - V_197 ;
return V_109 -> V_198 > 0 || V_109 -> V_199 > 0 ;
}
unsigned int
F_114 (
struct V_1 * V_2 ,
struct V_108 * V_109 )
{
unsigned int V_200 ;
V_200 = F_115 (unsigned int, pag->pagf_levels[XFS_BTNUM_BNOi] + 1 ,
mp->m_ag_maxlevels) ;
V_200 += F_115 (unsigned int, pag->pagf_levels[XFS_BTNUM_CNTi] + 1 ,
mp->m_ag_maxlevels) ;
if ( F_2 ( & V_2 -> V_3 ) )
V_200 += F_115 (unsigned int,
pag->pagf_levels[XFS_BTNUM_RMAPi] + 1 ,
mp->m_rmap_maxlevels) ;
return V_200 ;
}
static bool
F_116 (
struct V_136 * args ,
T_1 V_200 ,
int V_61 )
{
struct V_108 * V_109 = args -> V_109 ;
T_1 V_201 ;
int V_202 ;
if ( V_61 & V_203 )
return true ;
V_201 = F_113 ( args -> V_2 , V_109 , V_200 ) ;
if ( ( args -> V_31 + args -> V_30 + args -> V_204 - 1 ) > V_201 )
return false ;
V_202 = ( int ) ( V_109 -> V_111 + V_109 -> V_198 -
V_200 - args -> V_205 ) ;
if ( V_202 < ( int ) args -> V_52 )
return false ;
return true ;
}
int
F_117 (
struct V_136 * args ,
int V_61 )
{
struct V_1 * V_2 = args -> V_2 ;
struct V_108 * V_109 = args -> V_109 ;
struct V_107 * V_100 = args -> V_100 ;
struct V_76 * V_53 = NULL ;
struct V_76 * V_206 = NULL ;
struct V_136 V_207 ;
T_2 V_11 ;
T_1 V_196 ;
int error = 0 ;
if ( ! V_109 -> V_208 ) {
error = F_118 ( V_2 , V_100 , args -> V_101 , V_61 , & V_53 ) ;
if ( error )
goto V_209;
if ( ! V_109 -> V_208 ) {
ASSERT ( V_61 & V_210 ) ;
ASSERT ( ! ( V_61 & V_203 ) ) ;
goto V_211;
}
}
if ( V_109 -> V_212 && args -> V_35 &&
( V_61 & V_210 ) ) {
ASSERT ( ! ( V_61 & V_203 ) ) ;
goto V_211;
}
V_196 = F_114 ( V_2 , V_109 ) ;
if ( ! F_116 ( args , V_196 , V_61 ) )
goto V_211;
if ( ! V_53 ) {
error = F_118 ( V_2 , V_100 , args -> V_101 , V_61 , & V_53 ) ;
if ( error )
goto V_209;
if ( ! V_53 ) {
ASSERT ( V_61 & V_210 ) ;
ASSERT ( ! ( V_61 & V_203 ) ) ;
goto V_209;
}
}
V_196 = F_114 ( V_2 , V_109 ) ;
if ( ! F_116 ( args , V_196 , V_61 ) )
goto V_211;
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
if ( V_61 & V_213 )
F_119 ( & V_207 . V_119 ) ;
else
F_102 ( & V_207 . V_119 , V_184 ) ;
while ( ! ( V_61 & V_214 ) && V_109 -> V_198 > V_196 ) {
struct V_76 * V_77 ;
error = F_97 ( V_100 , V_53 , & V_11 , 0 ) ;
if ( error )
goto V_211;
error = F_107 ( V_100 , V_53 , args -> V_101 , V_11 , 1 ,
& V_207 . V_119 , 1 ) ;
if ( error )
goto V_211;
V_77 = F_99 ( V_2 , V_100 , args -> V_101 , V_11 , 0 ) ;
F_100 ( V_100 , V_77 ) ;
}
V_207 . V_100 = V_100 ;
V_207 . V_2 = V_2 ;
V_207 . V_53 = V_53 ;
V_207 . V_101 = args -> V_101 ;
V_207 . V_30 = V_207 . V_31 = V_207 . V_49 = V_207 . V_118 = 1 ;
V_207 . type = V_115 ;
V_207 . V_109 = V_109 ;
error = F_50 ( V_2 , V_100 , V_207 . V_101 , & V_206 ) ;
if ( error )
goto V_211;
while ( V_109 -> V_198 < V_196 ) {
V_207 . V_55 = 0 ;
V_207 . V_50 = V_196 - V_109 -> V_198 ;
error = F_60 ( & V_207 ) ;
if ( error )
goto V_215;
if ( V_207 . V_55 == V_45 ) {
if ( V_61 & V_203 )
break;
goto V_215;
}
for ( V_11 = V_207 . V_55 ; V_11 < V_207 . V_55 + V_207 . V_12 ; V_11 ++ ) {
error = F_120 ( V_100 , V_53 ,
V_206 , V_11 , 0 ) ;
if ( error )
goto V_215;
}
}
F_121 ( V_100 , V_206 ) ;
args -> V_53 = V_53 ;
return 0 ;
V_215:
F_121 ( V_100 , V_206 ) ;
V_211:
if ( V_53 )
F_121 ( V_100 , V_53 ) ;
V_209:
args -> V_53 = NULL ;
return error ;
}
int
F_97 (
T_7 * V_100 ,
T_9 * V_53 ,
T_2 * V_216 ,
int V_217 )
{
T_4 * V_51 ;
T_9 * V_206 ;
T_2 V_11 ;
T_11 * V_89 ;
int error ;
int V_218 ;
T_6 * V_2 = V_100 -> V_189 ;
T_10 * V_109 ;
V_51 = F_29 ( V_53 ) ;
if ( ! V_51 -> V_183 ) {
* V_216 = V_45 ;
return 0 ;
}
error = F_50 ( V_2 , V_100 , F_20 ( V_51 -> V_219 ) ,
& V_206 ) ;
if ( error )
return error ;
V_89 = F_122 ( V_2 , V_206 ) ;
V_11 = F_20 ( V_89 [ F_20 ( V_51 -> V_220 ) ] ) ;
F_56 ( & V_51 -> V_220 , 1 ) ;
F_121 ( V_100 , V_206 ) ;
if ( F_20 ( V_51 -> V_220 ) == F_39 ( V_2 ) )
V_51 -> V_220 = 0 ;
V_109 = F_108 ( V_2 , F_20 ( V_51 -> V_219 ) ) ;
F_56 ( & V_51 -> V_183 , - 1 ) ;
F_123 ( V_100 , - 1 ) ;
V_109 -> V_198 -- ;
F_109 ( V_109 ) ;
V_218 = V_221 | V_222 ;
if ( V_217 ) {
F_56 ( & V_51 -> V_223 , 1 ) ;
V_109 -> V_224 ++ ;
V_218 |= V_225 ;
}
F_59 ( V_100 , V_53 , V_218 ) ;
* V_216 = V_11 ;
return 0 ;
}
void
F_59 (
T_7 * V_100 ,
T_9 * V_77 ,
int V_226 )
{
int V_227 ;
int V_228 ;
static const short V_229 [] = {
F_124 ( T_4 , V_230 ) ,
F_124 ( T_4 , V_231 ) ,
F_124 ( T_4 , V_219 ) ,
F_124 ( T_4 , V_112 ) ,
F_124 ( T_4 , V_232 [ 0 ] ) ,
F_124 ( T_4 , V_233 [ 0 ] ) ,
F_124 ( T_4 , V_220 ) ,
F_124 ( T_4 , V_234 ) ,
F_124 ( T_4 , V_183 ) ,
F_124 ( T_4 , V_54 ) ,
F_124 ( T_4 , V_235 ) ,
F_124 ( T_4 , V_223 ) ,
F_124 ( T_4 , V_236 ) ,
F_124 ( T_4 , V_237 ) ,
F_124 ( T_4 , V_238 ) ,
sizeof( T_4 )
} ;
F_125 ( V_100 -> V_189 , F_29 ( V_77 ) , V_226 , V_239 ) ;
F_126 ( V_100 , V_77 , V_240 ) ;
F_127 ( V_226 , V_229 , V_241 , & V_227 , & V_228 ) ;
F_128 ( V_100 , V_77 , ( V_242 ) V_227 , ( V_242 ) V_228 ) ;
}
int
F_129 (
T_6 * V_2 ,
T_7 * V_100 ,
T_8 V_101 ,
int V_61 )
{
T_9 * V_77 ;
int error ;
if ( ( error = F_118 ( V_2 , V_100 , V_101 , V_61 , & V_77 ) ) )
return error ;
if ( V_77 )
F_121 ( V_100 , V_77 ) ;
return 0 ;
}
int
F_120 (
T_7 * V_100 ,
T_9 * V_53 ,
T_9 * V_206 ,
T_2 V_11 ,
int V_217 )
{
T_4 * V_51 ;
T_11 * V_243 ;
int error ;
int V_218 ;
T_6 * V_2 ;
T_10 * V_109 ;
T_11 * V_89 ;
int V_244 ;
V_51 = F_29 ( V_53 ) ;
V_2 = V_100 -> V_189 ;
if ( ! V_206 && ( error = F_50 ( V_2 , V_100 ,
F_20 ( V_51 -> V_219 ) , & V_206 ) ) )
return error ;
F_56 ( & V_51 -> V_234 , 1 ) ;
if ( F_20 ( V_51 -> V_234 ) == F_39 ( V_2 ) )
V_51 -> V_234 = 0 ;
V_109 = F_108 ( V_2 , F_20 ( V_51 -> V_219 ) ) ;
F_56 ( & V_51 -> V_183 , 1 ) ;
F_123 ( V_100 , 1 ) ;
V_109 -> V_198 ++ ;
V_218 = V_245 | V_222 ;
if ( V_217 ) {
F_56 ( & V_51 -> V_223 , - 1 ) ;
V_109 -> V_224 -- ;
V_218 |= V_225 ;
}
F_109 ( V_109 ) ;
F_59 ( V_100 , V_53 , V_218 ) ;
ASSERT ( F_20 ( V_51 -> V_183 ) <= F_39 ( V_2 ) ) ;
V_89 = F_122 ( V_2 , V_206 ) ;
V_243 = & V_89 [ F_20 ( V_51 -> V_234 ) ] ;
* V_243 = F_16 ( V_11 ) ;
V_244 = ( char * ) V_243 - ( char * ) V_206 -> V_246 ;
F_59 ( V_100 , V_53 , V_218 ) ;
F_126 ( V_100 , V_206 , V_247 ) ;
F_128 ( V_100 , V_206 , V_244 ,
V_244 + sizeof( T_2 ) - 1 ) ;
return 0 ;
}
static bool
F_130 (
struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_110 * V_51 = F_29 ( V_77 ) ;
if ( F_43 ( & V_2 -> V_3 ) ) {
if ( ! F_38 ( & V_51 -> V_236 , & V_2 -> V_3 . V_83 ) )
return false ;
if ( ! F_40 ( V_2 ,
F_41 ( F_29 ( V_77 ) -> V_248 ) ) )
return false ;
}
if ( ! ( V_51 -> V_230 == F_16 ( V_249 ) &&
F_131 ( F_20 ( V_51 -> V_231 ) ) &&
F_20 ( V_51 -> V_54 ) <= F_20 ( V_51 -> V_112 ) &&
F_20 ( V_51 -> V_220 ) < F_39 ( V_2 ) &&
F_20 ( V_51 -> V_234 ) < F_39 ( V_2 ) &&
F_20 ( V_51 -> V_183 ) <= F_39 ( V_2 ) ) )
return false ;
if ( F_20 ( V_51 -> V_233 [ V_130 ] ) > V_250 ||
F_20 ( V_51 -> V_233 [ V_133 ] ) > V_250 )
return false ;
if ( F_2 ( & V_2 -> V_3 ) &&
F_20 ( V_51 -> V_233 [ V_251 ] ) > V_250 )
return false ;
if ( V_77 -> V_86 && F_20 ( V_51 -> V_219 ) != V_77 -> V_86 -> V_88 )
return false ;
if ( F_132 ( & V_2 -> V_3 ) &&
F_20 ( V_51 -> V_223 ) > F_20 ( V_51 -> V_112 ) )
return false ;
return true ; ;
}
static void
F_133 (
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_78 -> V_79 ;
if ( F_43 ( & V_2 -> V_3 ) &&
! F_44 ( V_77 , V_252 ) )
F_45 ( V_77 , - V_92 ) ;
else if ( F_134 ( ! F_130 ( V_2 , V_77 ) , V_2 ,
V_253 ,
V_254 ) )
F_45 ( V_77 , - V_93 ) ;
if ( V_77 -> V_94 )
F_46 ( V_77 ) ;
}
static void
F_135 (
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_78 -> V_79 ;
struct V_95 * V_96 = V_77 -> V_97 ;
if ( ! F_130 ( V_2 , V_77 ) ) {
F_45 ( V_77 , - V_93 ) ;
F_46 ( V_77 ) ;
return;
}
if ( ! F_43 ( & V_2 -> V_3 ) )
return;
if ( V_96 )
F_29 ( V_77 ) -> V_248 = F_48 ( V_96 -> V_98 . V_99 ) ;
F_49 ( V_77 , V_252 ) ;
}
int
F_136 (
struct V_1 * V_2 ,
struct V_107 * V_100 ,
T_8 V_101 ,
int V_61 ,
struct V_76 * * V_102 )
{
int error ;
F_137 ( V_2 , V_101 ) ;
ASSERT ( V_101 != V_103 ) ;
error = F_51 (
V_2 , V_100 , V_2 -> V_104 ,
F_52 ( V_2 , V_101 , F_138 ( V_2 ) ) ,
F_10 ( V_2 , 1 ) , V_61 , V_102 , & V_255 ) ;
if ( error )
return error ;
if ( ! * V_102 )
return 0 ;
ASSERT ( ! ( * V_102 ) -> V_94 ) ;
F_54 ( * V_102 , V_256 ) ;
return 0 ;
}
int
F_118 (
struct V_1 * V_2 ,
struct V_107 * V_100 ,
T_8 V_101 ,
int V_61 ,
struct V_76 * * V_102 )
{
struct V_110 * V_51 ;
struct V_108 * V_109 ;
int error ;
F_139 ( V_2 , V_101 ) ;
ASSERT ( V_101 != V_103 ) ;
error = F_136 ( V_2 , V_100 , V_101 ,
( V_61 & V_210 ) ? V_257 : 0 ,
V_102 ) ;
if ( error )
return error ;
if ( ! * V_102 )
return 0 ;
ASSERT ( ! ( * V_102 ) -> V_94 ) ;
V_51 = F_29 ( * V_102 ) ;
V_109 = F_108 ( V_2 , V_101 ) ;
if ( ! V_109 -> V_208 ) {
V_109 -> V_111 = F_20 ( V_51 -> V_54 ) ;
V_109 -> V_224 = F_20 ( V_51 -> V_223 ) ;
V_109 -> V_198 = F_20 ( V_51 -> V_183 ) ;
V_109 -> V_199 = F_20 ( V_51 -> V_235 ) ;
V_109 -> V_258 [ V_259 ] =
F_20 ( V_51 -> V_233 [ V_259 ] ) ;
V_109 -> V_258 [ V_260 ] =
F_20 ( V_51 -> V_233 [ V_260 ] ) ;
V_109 -> V_258 [ V_261 ] =
F_20 ( V_51 -> V_233 [ V_261 ] ) ;
F_140 ( & V_109 -> V_262 ) ;
V_109 -> V_263 = 0 ;
V_109 -> V_264 = V_265 ;
V_109 -> V_208 = 1 ;
}
#ifdef F_31
else if ( ! F_141 ( V_2 ) ) {
ASSERT ( V_109 -> V_111 == F_20 ( V_51 -> V_54 ) ) ;
ASSERT ( V_109 -> V_224 == F_20 ( V_51 -> V_223 ) ) ;
ASSERT ( V_109 -> V_198 == F_20 ( V_51 -> V_183 ) ) ;
ASSERT ( V_109 -> V_199 == F_20 ( V_51 -> V_235 ) ) ;
ASSERT ( V_109 -> V_258 [ V_259 ] ==
F_20 ( V_51 -> V_233 [ V_259 ] ) ) ;
ASSERT ( V_109 -> V_258 [ V_260 ] ==
F_20 ( V_51 -> V_233 [ V_260 ] ) ) ;
}
#endif
F_109 ( V_109 ) ;
return 0 ;
}
int
F_142 (
T_3 * args )
{
T_2 V_266 ;
int error ;
int V_61 ;
T_1 V_52 ;
T_6 * V_2 ;
T_8 V_267 ;
T_12 type ;
int V_268 = 0 ;
int V_269 = 0 ;
T_8 V_270 = V_271 ;
V_2 = args -> V_2 ;
type = args -> V_272 = args -> type ;
args -> V_55 = V_45 ;
V_266 = V_2 -> V_3 . V_8 ;
if ( args -> V_50 > V_266 )
args -> V_50 = V_266 ;
if ( args -> V_30 == 0 )
args -> V_30 = 1 ;
ASSERT ( F_143 ( V_2 , args -> V_273 ) < V_2 -> V_3 . V_5 ) ;
ASSERT ( F_144 ( V_2 , args -> V_273 ) < V_266 ) ;
ASSERT ( args -> V_31 <= args -> V_50 ) ;
ASSERT ( args -> V_31 <= V_266 ) ;
ASSERT ( args -> V_48 < args -> V_49 ) ;
if ( F_143 ( V_2 , args -> V_273 ) >= V_2 -> V_3 . V_5 ||
F_144 ( V_2 , args -> V_273 ) >= V_266 ||
args -> V_31 > args -> V_50 || args -> V_31 > V_266 ||
args -> V_48 >= args -> V_49 ) {
args -> V_273 = V_274 ;
F_145 ( args ) ;
return 0 ;
}
V_52 = args -> V_52 ;
switch ( type ) {
case V_115 :
case V_116 :
case V_117 :
args -> V_101 = F_143 ( V_2 , args -> V_273 ) ;
args -> V_109 = F_108 ( V_2 , args -> V_101 ) ;
args -> V_52 = 0 ;
error = F_117 ( args , 0 ) ;
args -> V_52 = V_52 ;
if ( error ) {
F_146 ( args ) ;
goto V_131;
}
if ( ! args -> V_53 ) {
F_147 ( args ) ;
break;
}
args -> V_55 = F_144 ( V_2 , args -> V_273 ) ;
if ( ( error = F_60 ( args ) ) )
goto V_131;
break;
case V_275 :
if ( ( args -> V_35 & V_276 ) &&
( V_2 -> V_277 & V_278 ) ) {
args -> V_273 = F_148 ( V_2 ,
( ( V_2 -> V_279 / V_270 ) %
V_2 -> V_3 . V_5 ) , 0 ) ;
V_268 = 1 ;
}
args -> V_55 = F_144 ( V_2 , args -> V_273 ) ;
args -> type = V_116 ;
case V_280 :
case V_281 :
case V_282 :
if ( type == V_280 ) {
args -> V_101 = V_267 = ( V_2 -> V_279 / V_270 ) %
V_2 -> V_3 . V_5 ;
args -> type = V_115 ;
V_61 = V_210 ;
} else if ( type == V_282 ) {
args -> V_101 = F_143 ( V_2 , args -> V_273 ) ;
args -> type = V_115 ;
V_267 = 0 ;
V_61 = 0 ;
} else {
if ( type == V_281 )
args -> type = V_115 ;
args -> V_101 = V_267 = F_143 ( V_2 , args -> V_273 ) ;
V_61 = V_210 ;
}
for (; ; ) {
args -> V_109 = F_108 ( V_2 , args -> V_101 ) ;
if ( V_269 ) args -> V_52 = 0 ;
error = F_117 ( args , V_61 ) ;
args -> V_52 = V_52 ;
if ( error ) {
F_146 ( args ) ;
goto V_131;
}
if ( args -> V_53 ) {
if ( ( error = F_60 ( args ) ) )
goto V_131;
break;
}
F_149 ( args ) ;
if ( args -> V_101 == V_267 &&
type == V_275 )
args -> type = V_115 ;
if ( ++ ( args -> V_101 ) == V_2 -> V_3 . V_5 ) {
if ( args -> V_283 != V_274 )
args -> V_101 = V_267 ;
else
args -> V_101 = 0 ;
}
if ( args -> V_101 == V_267 ) {
if ( V_269 == 1 ) {
args -> V_55 = V_45 ;
F_150 ( args ) ;
break;
}
if ( V_61 == 0 ) {
V_269 = 1 ;
} else {
V_61 = 0 ;
if ( type == V_275 ) {
args -> V_55 = F_144 ( V_2 ,
args -> V_273 ) ;
args -> type = V_116 ;
}
}
}
F_109 ( args -> V_109 ) ;
}
if ( V_268 || ( type == V_280 ) ) {
if ( args -> V_101 == V_267 )
V_2 -> V_279 = ( V_2 -> V_279 + 1 ) %
( V_2 -> V_3 . V_5 * V_270 ) ;
else
V_2 -> V_279 = ( args -> V_101 * V_270 + 1 ) %
( V_2 -> V_3 . V_5 * V_270 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_55 == V_45 )
args -> V_273 = V_274 ;
else {
args -> V_273 = F_148 ( V_2 , args -> V_101 , args -> V_55 ) ;
#ifdef F_31
ASSERT ( args -> V_12 >= args -> V_31 ) ;
ASSERT ( args -> V_12 <= args -> V_50 ) ;
ASSERT ( args -> V_55 % args -> V_30 == 0 ) ;
F_151 ( V_2 , F_152 ( V_2 , args -> V_273 ) ,
args -> V_12 ) ;
#endif
if ( args -> V_35 & V_284 ) {
error = F_153 ( args -> V_285 , args -> V_273 , args -> V_12 ) ;
if ( error )
goto V_131;
}
}
F_109 ( args -> V_109 ) ;
return 0 ;
V_131:
F_109 ( args -> V_109 ) ;
return error ;
}
int
F_154 (
struct V_107 * V_100 ,
T_8 V_101 ,
struct V_76 * * V_53 )
{
struct V_136 args ;
int error ;
memset ( & args , 0 , sizeof( struct V_136 ) ) ;
args . V_100 = V_100 ;
args . V_2 = V_100 -> V_189 ;
args . V_101 = V_101 ;
if ( args . V_101 >= args . V_2 -> V_3 . V_5 )
return - V_93 ;
args . V_109 = F_108 ( args . V_2 , args . V_101 ) ;
ASSERT ( args . V_109 ) ;
error = F_117 ( & args , V_203 ) ;
if ( error )
goto V_286;
* V_53 = args . V_53 ;
V_286:
F_109 ( args . V_109 ) ;
return error ;
}
int
F_155 (
struct V_107 * V_100 ,
T_13 V_11 ,
T_1 V_12 ,
struct V_182 * V_119 )
{
struct V_1 * V_2 = V_100 -> V_189 ;
struct V_76 * V_53 ;
T_8 V_101 = F_143 ( V_2 , V_11 ) ;
T_2 V_55 = F_144 ( V_2 , V_11 ) ;
int error ;
ASSERT ( V_12 != 0 ) ;
if ( F_134 ( false , V_2 ,
V_287 ,
V_288 ) )
return - V_289 ;
error = F_154 ( V_100 , V_101 , & V_53 ) ;
if ( error )
return error ;
F_70 ( V_2 , V_55 < V_2 -> V_3 . V_8 , V_290 ) ;
F_70 ( V_2 ,
V_55 + V_12 <= F_20 ( F_29 ( V_53 ) -> V_112 ) ,
V_290 ) ;
error = F_107 ( V_100 , V_53 , V_101 , V_55 , V_12 , V_119 , 0 ) ;
if ( error )
goto V_290;
F_156 ( V_100 , V_101 , V_55 , V_12 , 0 ) ;
return 0 ;
V_290:
F_121 ( V_100 , V_53 ) ;
return error ;
}
