STATIC int
F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
int * V_5 )
{
V_2 -> V_6 . V_7 . V_8 = V_3 ;
V_2 -> V_6 . V_7 . V_9 = V_4 ;
return F_2 ( V_2 , V_10 , V_5 ) ;
}
int
F_3 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
int * V_5 )
{
V_2 -> V_6 . V_7 . V_8 = V_3 ;
V_2 -> V_6 . V_7 . V_9 = V_4 ;
return F_2 ( V_2 , V_11 , V_5 ) ;
}
int
F_4 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
int * V_5 )
{
V_2 -> V_6 . V_7 . V_8 = V_3 ;
V_2 -> V_6 . V_7 . V_9 = V_4 ;
return F_2 ( V_2 , V_12 , V_5 ) ;
}
STATIC int
F_5 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 )
{
union V_13 V_14 ;
V_14 . V_15 . V_8 = F_6 ( V_3 ) ;
V_14 . V_15 . V_9 = F_6 ( V_4 ) ;
return F_7 ( V_2 , & V_14 ) ;
}
int
F_8 (
struct V_1 * V_2 ,
T_1 * V_3 ,
T_2 * V_4 ,
int * V_5 )
{
union V_13 * V_14 ;
int error ;
error = F_9 ( V_2 , & V_14 , V_5 ) ;
if ( ! error && * V_5 == 1 ) {
* V_3 = F_10 ( V_14 -> V_15 . V_8 ) ;
* V_4 = F_10 ( V_14 -> V_15 . V_9 ) ;
}
return error ;
}
STATIC void
F_11 (
T_3 * args ,
T_1 V_16 ,
T_2 V_17 ,
T_1 * V_18 ,
T_2 * V_19 )
{
T_1 V_3 ;
T_2 V_4 ;
T_2 V_20 ;
F_12 ( args , V_16 , V_17 , & V_3 , & V_4 ) ;
if ( V_3 < args -> V_21 && V_3 + V_4 > args -> V_21 ) {
V_20 = args -> V_21 - V_3 ;
if ( V_4 > V_20 ) {
V_3 += V_20 ;
V_4 -= V_20 ;
}
}
if ( args -> V_22 > 1 && V_4 >= args -> V_23 ) {
T_1 V_24 = F_13 ( V_3 , args -> V_22 ) ;
V_20 = V_24 - V_3 ;
* V_18 = V_24 ;
* V_19 = V_20 >= V_4 ? 0 : V_4 - V_20 ;
} else {
* V_18 = V_3 ;
* V_19 = V_4 ;
}
}
STATIC T_2
F_14 (
T_1 V_25 ,
T_2 V_26 ,
T_2 V_22 ,
char V_27 ,
T_1 V_28 ,
T_2 V_29 ,
T_1 * V_30 )
{
T_1 V_31 ;
T_1 V_32 ;
T_1 V_33 ;
T_2 V_34 = 0 ;
T_2 V_35 = 0 ;
T_1 V_36 ;
ASSERT ( V_29 >= V_26 ) ;
V_31 = V_28 + V_29 ;
V_36 = V_25 + V_26 ;
if ( V_28 >= V_25 || ( V_27 && V_31 < V_36 ) ) {
if ( ( V_32 = F_13 ( V_28 , V_22 ) ) >= V_31 )
V_32 = V_37 ;
} else if ( V_31 >= V_36 && V_22 > 1 ) {
V_32 = F_13 ( V_25 , V_22 ) ;
V_33 = V_32 - V_22 ;
if ( V_32 >= V_31 )
V_32 = V_37 ;
else
V_34 = F_15 ( V_26 , V_31 - V_32 ) ;
if ( V_33 < V_28 )
V_33 = V_37 ;
else
V_35 = F_15 ( V_26 , V_31 - V_33 ) ;
if ( V_32 != V_37 && V_33 != V_37 ) {
if ( V_34 < V_35 ||
( V_34 == V_35 &&
F_16 ( V_32 , V_25 ) >
F_16 ( V_33 , V_25 ) ) )
V_32 = V_33 ;
} else if ( V_33 != V_37 )
V_32 = V_33 ;
} else if ( V_31 >= V_36 ) {
V_32 = V_25 ;
} else if ( V_22 > 1 ) {
V_32 = F_13 ( V_31 - V_26 , V_22 ) ;
if ( V_32 > V_31 - V_26 &&
V_32 - V_22 >= V_28 )
V_32 -= V_22 ;
else if ( V_32 >= V_31 )
V_32 = V_37 ;
} else
V_32 = V_31 - V_26 ;
* V_30 = V_32 ;
return V_32 == V_37 ? 0 : F_16 ( V_32 , V_25 ) ;
}
STATIC void
F_17 (
T_3 * args )
{
T_2 V_38 ;
T_2 V_39 ;
ASSERT ( args -> V_40 < args -> V_41 ) ;
V_39 = args -> V_4 ;
ASSERT ( V_39 >= args -> V_23 ) ;
ASSERT ( V_39 <= args -> V_42 ) ;
if ( args -> V_41 <= 1 || V_39 < args -> V_40 || V_39 == args -> V_42 ||
( args -> V_40 == 0 && V_39 < args -> V_41 ) )
return;
V_38 = V_39 % args -> V_41 ;
if ( V_38 == args -> V_40 )
return;
if ( V_38 > args -> V_40 )
V_39 = V_39 - ( V_38 - args -> V_40 ) ;
else
V_39 = V_39 - args -> V_41 + ( args -> V_40 - V_38 ) ;
if ( ( int ) V_39 < ( int ) args -> V_23 )
return;
ASSERT ( V_39 >= args -> V_23 && V_39 <= args -> V_42 ) ;
ASSERT ( V_39 % args -> V_41 == args -> V_40 ) ;
args -> V_4 = V_39 ;
}
STATIC int
F_18 (
T_3 * args )
{
T_4 * V_43 ;
int V_20 ;
if ( args -> V_44 == 0 )
return 1 ;
V_43 = F_19 ( args -> V_45 ) ;
V_20 = F_10 ( V_43 -> V_46 )
- args -> V_4 - args -> V_44 ;
if ( V_20 >= 0 )
return 1 ;
args -> V_4 += V_20 ;
if ( ( int ) args -> V_4 >= ( int ) args -> V_23 )
return 1 ;
args -> V_47 = V_37 ;
return 0 ;
}
STATIC int
F_20 (
T_5 * V_48 ,
T_5 * V_49 ,
T_1 V_50 ,
T_2 V_51 ,
T_1 V_52 ,
T_2 V_39 ,
int V_53 )
{
int error ;
int V_54 ;
T_1 V_55 ;
T_1 V_56 ;
T_2 V_57 = 0 ;
T_2 V_58 = 0 ;
struct V_59 * V_60 ;
V_60 = V_48 -> V_61 ;
if ( V_53 & V_62 ) {
#ifdef F_21
if ( ( error = F_8 ( V_48 , & V_55 , & V_57 , & V_54 ) ) )
return error ;
F_22 ( V_60 ,
V_54 == 1 && V_55 == V_50 && V_57 == V_51 ) ;
#endif
} else {
if ( ( error = F_1 ( V_48 , V_50 , V_51 , & V_54 ) ) )
return error ;
F_22 ( V_60 , V_54 == 1 ) ;
}
if ( V_53 & V_63 ) {
#ifdef F_21
if ( ( error = F_8 ( V_49 , & V_55 , & V_57 , & V_54 ) ) )
return error ;
F_22 ( V_60 ,
V_54 == 1 && V_55 == V_50 && V_57 == V_51 ) ;
#endif
} else {
if ( ( error = F_1 ( V_49 , V_50 , V_51 , & V_54 ) ) )
return error ;
F_22 ( V_60 , V_54 == 1 ) ;
}
#ifdef F_21
if ( V_49 -> V_64 == 1 && V_48 -> V_64 == 1 ) {
struct V_65 * V_66 ;
struct V_65 * V_67 ;
V_66 = F_23 ( V_49 -> V_68 [ 0 ] ) ;
V_67 = F_23 ( V_48 -> V_68 [ 0 ] ) ;
F_22 ( V_60 ,
V_66 -> V_69 == V_67 -> V_69 ) ;
}
#endif
if ( V_52 == V_50 && V_39 == V_51 )
V_55 = V_56 = V_37 ;
else if ( V_52 == V_50 ) {
V_55 = V_52 + V_39 ;
V_57 = V_51 - V_39 ;
V_56 = V_37 ;
} else if ( V_52 + V_39 == V_50 + V_51 ) {
V_55 = V_50 ;
V_57 = V_51 - V_39 ;
V_56 = V_37 ;
} else {
V_55 = V_50 ;
V_57 = V_52 - V_50 ;
V_56 = V_52 + V_39 ;
V_58 = ( V_50 + V_51 ) - V_56 ;
}
if ( ( error = F_24 ( V_48 , & V_54 ) ) )
return error ;
F_22 ( V_60 , V_54 == 1 ) ;
if ( V_55 != V_37 ) {
if ( ( error = F_1 ( V_48 , V_55 , V_57 , & V_54 ) ) )
return error ;
F_22 ( V_60 , V_54 == 0 ) ;
if ( ( error = F_25 ( V_48 , & V_54 ) ) )
return error ;
F_22 ( V_60 , V_54 == 1 ) ;
}
if ( V_56 != V_37 ) {
if ( ( error = F_1 ( V_48 , V_56 , V_58 , & V_54 ) ) )
return error ;
F_22 ( V_60 , V_54 == 0 ) ;
if ( ( error = F_25 ( V_48 , & V_54 ) ) )
return error ;
F_22 ( V_60 , V_54 == 1 ) ;
}
if ( V_55 == V_37 ) {
if ( ( error = F_24 ( V_49 , & V_54 ) ) )
return error ;
F_22 ( V_60 , V_54 == 1 ) ;
} else {
if ( ( error = F_5 ( V_49 , V_55 , V_57 ) ) )
return error ;
}
if ( V_56 != V_37 ) {
if ( ( error = F_1 ( V_49 , V_56 , V_58 , & V_54 ) ) )
return error ;
F_22 ( V_60 , V_54 == 0 ) ;
if ( ( error = F_25 ( V_49 , & V_54 ) ) )
return error ;
F_22 ( V_60 , V_54 == 1 ) ;
}
return 0 ;
}
static bool
F_26 (
struct V_70 * V_71 )
{
struct V_59 * V_60 = V_71 -> V_72 -> V_73 ;
struct V_74 * V_75 = F_27 ( V_71 ) ;
int V_54 ;
if ( ! F_28 ( & V_75 -> V_76 , & V_60 -> V_77 . V_78 ) )
return false ;
if ( F_10 ( V_75 -> V_79 ) != V_80 )
return false ;
if ( V_71 -> V_81 && F_10 ( V_75 -> V_82 ) != V_71 -> V_81 -> V_83 )
return false ;
for ( V_54 = 0 ; V_54 < F_29 ( V_60 ) ; V_54 ++ ) {
if ( F_10 ( V_75 -> V_84 [ V_54 ] ) != V_37 &&
F_10 ( V_75 -> V_84 [ V_54 ] ) >= V_60 -> V_77 . V_85 )
return false ;
}
return true ;
}
static void
F_30 (
struct V_70 * V_71 )
{
struct V_59 * V_60 = V_71 -> V_72 -> V_73 ;
if ( ! F_31 ( & V_60 -> V_77 ) )
return;
if ( ! F_32 ( V_71 , V_86 ) )
F_33 ( V_71 , - V_87 ) ;
else if ( ! F_26 ( V_71 ) )
F_33 ( V_71 , - V_88 ) ;
if ( V_71 -> V_89 )
F_34 ( V_71 ) ;
}
static void
F_35 (
struct V_70 * V_71 )
{
struct V_59 * V_60 = V_71 -> V_72 -> V_73 ;
struct V_90 * V_91 = V_71 -> V_92 ;
if ( ! F_31 ( & V_60 -> V_77 ) )
return;
if ( ! F_26 ( V_71 ) ) {
F_33 ( V_71 , - V_88 ) ;
F_34 ( V_71 ) ;
return;
}
if ( V_91 )
F_27 ( V_71 ) -> V_93 = F_36 ( V_91 -> V_94 . V_95 ) ;
F_37 ( V_71 , V_86 ) ;
}
STATIC int
F_38 (
T_6 * V_60 ,
T_7 * V_96 ,
T_8 V_97 ,
T_9 * * V_98 )
{
T_9 * V_71 ;
int error ;
ASSERT ( V_97 != V_99 ) ;
error = F_39 (
V_60 , V_96 , V_60 -> V_100 ,
F_40 ( V_60 , V_97 , F_41 ( V_60 ) ) ,
F_42 ( V_60 , 1 ) , 0 , & V_71 , & V_101 ) ;
if ( error )
return error ;
F_43 ( V_71 , V_102 ) ;
* V_98 = V_71 ;
return 0 ;
}
STATIC int
F_44 (
struct V_103 * V_96 ,
struct V_104 * V_105 ,
struct V_70 * V_45 ,
long V_4 )
{
struct V_106 * V_43 = F_19 ( V_45 ) ;
V_105 -> V_107 += V_4 ;
F_45 ( & V_43 -> V_46 , V_4 ) ;
F_46 ( V_96 , V_4 ) ;
if ( F_47 ( F_10 ( V_43 -> V_46 ) >
F_10 ( V_43 -> V_108 ) ) )
return - V_88 ;
F_48 ( V_96 , V_45 , V_109 ) ;
return 0 ;
}
STATIC int
F_49 (
T_3 * args )
{
int error = 0 ;
ASSERT ( args -> V_23 > 0 ) ;
ASSERT ( args -> V_42 > 0 ) ;
ASSERT ( args -> V_23 <= args -> V_42 ) ;
ASSERT ( args -> V_40 < args -> V_41 ) ;
ASSERT ( args -> V_22 > 0 ) ;
args -> V_110 = 0 ;
switch ( args -> type ) {
case V_111 :
error = F_50 ( args ) ;
break;
case V_112 :
error = F_51 ( args ) ;
break;
case V_113 :
error = F_52 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error || args -> V_47 == V_37 )
return error ;
ASSERT ( args -> V_4 >= args -> V_23 ) ;
ASSERT ( args -> V_4 <= args -> V_42 ) ;
ASSERT ( ! args -> V_110 || ! args -> V_114 ) ;
ASSERT ( args -> V_47 % args -> V_22 == 0 ) ;
if ( ! args -> V_110 ) {
error = F_44 ( args -> V_96 , args -> V_105 ,
args -> V_45 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_53 ( args -> V_60 , args -> V_97 ,
args -> V_47 , args -> V_4 ) ) ;
}
if ( ! args -> V_114 ) {
F_54 ( args -> V_96 , args -> V_115 ?
V_116 :
V_117 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
}
F_55 ( V_118 ) ;
F_56 ( V_119 , args -> V_4 ) ;
return error ;
}
STATIC int
F_52 (
T_3 * args )
{
T_5 * V_49 ;
T_5 * V_48 ;
int error ;
T_1 V_50 ;
T_2 V_51 ;
T_1 V_120 ;
T_2 V_121 ;
T_1 V_122 ;
int V_54 ;
ASSERT ( args -> V_22 == 1 ) ;
V_49 = F_57 ( args -> V_60 , args -> V_96 , args -> V_45 ,
args -> V_97 , V_123 ) ;
error = F_4 ( V_49 , args -> V_47 , args -> V_23 , & V_54 ) ;
if ( error )
goto V_124;
if ( ! V_54 )
goto V_125;
error = F_8 ( V_49 , & V_50 , & V_51 , & V_54 ) ;
if ( error )
goto V_124;
F_58 ( args -> V_60 , V_54 == 1 , V_124 ) ;
ASSERT ( V_50 <= args -> V_47 ) ;
F_12 ( args , V_50 , V_51 , & V_120 , & V_121 ) ;
if ( V_120 > args -> V_47 )
goto V_125;
if ( V_121 < args -> V_23 )
goto V_125;
V_122 = V_120 + V_121 ;
if ( V_122 < args -> V_47 + args -> V_23 )
goto V_125;
args -> V_4 = F_59 ( V_122 , args -> V_47 + args -> V_42 )
- args -> V_47 ;
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_125;
ASSERT ( args -> V_47 + args -> V_4 <= V_122 ) ;
V_48 = F_57 ( args -> V_60 , args -> V_96 , args -> V_45 ,
args -> V_97 , V_126 ) ;
ASSERT ( args -> V_47 + args -> V_4 <=
F_10 ( F_19 ( args -> V_45 ) -> V_108 ) ) ;
error = F_20 ( V_48 , V_49 , V_50 , V_51 , args -> V_47 ,
args -> V_4 , V_63 ) ;
if ( error ) {
F_60 ( V_48 , V_127 ) ;
goto V_124;
}
F_60 ( V_49 , V_128 ) ;
F_60 ( V_48 , V_128 ) ;
args -> V_110 = 0 ;
F_61 ( args ) ;
return 0 ;
V_125:
F_60 ( V_49 , V_128 ) ;
args -> V_47 = V_37 ;
F_62 ( args ) ;
return 0 ;
V_124:
F_60 ( V_49 , V_127 ) ;
F_63 ( args ) ;
return error ;
}
STATIC int
F_64 (
struct V_129 * args ,
struct V_1 * * V_130 ,
struct V_1 * * V_131 ,
T_1 V_132 ,
T_1 * V_133 ,
T_2 * V_134 ,
T_1 * V_135 ,
T_2 * V_136 ,
int V_137 )
{
T_1 V_138 ;
T_1 V_139 ;
int error ;
int V_54 ;
if ( ! V_132 )
goto V_140;
do {
error = F_8 ( * V_131 , V_133 , V_134 , & V_54 ) ;
if ( error )
goto V_124;
F_58 ( args -> V_60 , V_54 == 1 , V_124 ) ;
F_11 ( args , * V_133 , * V_134 , V_135 , V_136 ) ;
if ( ! V_137 ) {
if ( * V_135 > args -> V_141 )
goto V_140;
if ( * V_135 >= args -> V_47 + V_132 )
goto V_140;
} else {
if ( * V_135 < args -> V_21 )
goto V_140;
if ( * V_135 <= args -> V_47 - V_132 )
goto V_140;
}
if ( * V_136 >= args -> V_23 ) {
args -> V_4 = F_15 ( * V_136 , args -> V_42 ) ;
F_17 ( args ) ;
V_139 = F_14 ( args -> V_47 , args -> V_4 ,
args -> V_22 ,
args -> V_27 , * V_135 ,
* V_136 , & V_138 ) ;
if ( V_139 < V_132 )
goto V_142;
goto V_140;
}
if ( ! V_137 )
error = F_65 ( * V_131 , 0 , & V_54 ) ;
else
error = F_66 ( * V_131 , 0 , & V_54 ) ;
if ( error )
goto V_124;
} while ( V_54 );
V_140:
F_60 ( * V_131 , V_128 ) ;
* V_131 = NULL ;
return 0 ;
V_142:
F_60 ( * V_130 , V_128 ) ;
* V_130 = NULL ;
return 0 ;
V_124:
return error ;
}
STATIC int
F_51 (
T_3 * args )
{
T_5 * V_143 ;
T_5 * V_144 ;
T_5 * V_48 ;
T_1 V_145 ;
T_1 V_146 ;
T_2 V_147 ;
T_2 V_148 ;
T_2 V_149 ;
T_1 V_150 ;
int error ;
int V_54 ;
int V_151 ;
T_1 V_152 ;
T_1 V_153 ;
T_2 V_154 ;
T_2 V_155 ;
T_2 V_156 ;
T_1 V_157 ;
T_2 V_39 ;
int V_158 = 0 ;
#ifdef F_21
int V_159 ;
V_159 = F_67 () & 1 ;
#endif
if ( ! args -> V_21 && ! args -> V_141 )
args -> V_141 = args -> V_60 -> V_77 . V_85 - 1 ;
ASSERT ( args -> V_21 <= args -> V_141 ) ;
if ( args -> V_47 < args -> V_21 )
args -> V_47 = args -> V_21 ;
if ( args -> V_47 > args -> V_141 )
args -> V_47 = args -> V_141 ;
V_160:
V_144 = NULL ;
V_143 = NULL ;
V_155 = 0 ;
V_149 = 0 ;
V_156 = 0 ;
V_48 = F_57 ( args -> V_60 , args -> V_96 , args -> V_45 ,
args -> V_97 , V_126 ) ;
if ( ( error = F_3 ( V_48 , 0 , args -> V_42 , & V_54 ) ) )
goto V_124;
if ( ! V_54 ) {
if ( ( error = F_68 ( args , V_48 , & V_152 ,
& V_155 , & V_54 ) ) )
goto V_124;
if ( V_54 == 0 || V_155 == 0 ) {
F_60 ( V_48 , V_128 ) ;
F_69 ( args ) ;
return 0 ;
}
ASSERT ( V_54 == 1 ) ;
}
args -> V_110 = 0 ;
while ( F_70 ( V_48 , 0 ) ) {
T_2 V_161 ;
int V_162 = 0 ;
T_2 V_163 = 0 ;
T_1 V_164 = 0 ;
#ifdef F_21
if ( V_159 )
break;
#endif
if ( V_155 || args -> V_22 > 1 ) {
V_48 -> V_165 [ 0 ] = 1 ;
do {
if ( ( error = F_8 ( V_48 , & V_152 ,
& V_155 , & V_54 ) ) )
goto V_124;
F_58 ( args -> V_60 , V_54 == 1 , V_124 ) ;
if ( V_155 >= args -> V_23 )
break;
if ( ( error = F_65 ( V_48 , 0 , & V_54 ) ) )
goto V_124;
} while ( V_54 );
ASSERT ( V_155 >= args -> V_23 ) ;
if ( ! V_54 )
break;
}
V_54 = V_48 -> V_165 [ 0 ] ;
for ( V_151 = 1 , V_163 = 0 , V_161 = 0 ;
! error && V_151 && ( V_163 < args -> V_42 || V_161 > 0 ) ;
error = F_65 ( V_48 , 0 , & V_151 ) ) {
if ( ( error = F_8 ( V_48 , & V_152 , & V_155 , & V_54 ) ) )
goto V_124;
F_58 ( args -> V_60 , V_54 == 1 , V_124 ) ;
F_11 ( args , V_152 , V_155 ,
& V_153 , & V_156 ) ;
if ( V_156 < args -> V_23 )
continue;
if ( V_153 < args -> V_21 || V_153 > args -> V_141 )
continue;
args -> V_4 = F_15 ( V_156 , args -> V_42 ) ;
F_17 ( args ) ;
ASSERT ( args -> V_4 >= args -> V_23 ) ;
if ( args -> V_4 < V_163 )
continue;
V_154 = F_14 ( args -> V_47 , args -> V_4 ,
args -> V_22 , args -> V_27 , V_153 ,
V_156 , & V_157 ) ;
if ( V_157 != V_37 &&
( args -> V_4 > V_163 || V_154 < V_161 ) ) {
V_161 = V_154 ;
V_164 = V_157 ;
V_163 = args -> V_4 ;
V_162 = V_48 -> V_165 [ 0 ] ;
}
}
if ( V_163 == 0 )
break;
V_48 -> V_165 [ 0 ] = V_162 ;
if ( ( error = F_8 ( V_48 , & V_152 , & V_155 , & V_54 ) ) )
goto V_124;
F_58 ( args -> V_60 , V_54 == 1 , V_124 ) ;
ASSERT ( V_152 + V_155 <= F_10 ( F_19 ( args -> V_45 ) -> V_108 ) ) ;
args -> V_4 = V_163 ;
if ( ! F_18 ( args ) ) {
F_60 ( V_48 , V_128 ) ;
F_71 ( args ) ;
return 0 ;
}
V_163 = args -> V_4 ;
args -> V_47 = V_164 ;
ASSERT ( V_164 >= V_152 ) ;
ASSERT ( V_164 + V_163 <= V_152 + V_155 ) ;
V_144 = F_57 ( args -> V_60 , args -> V_96 ,
args -> V_45 , args -> V_97 , V_123 ) ;
if ( ( error = F_20 ( V_48 , V_144 , V_152 ,
V_155 , V_164 , V_163 , V_62 ) ) )
goto V_124;
F_60 ( V_48 , V_128 ) ;
F_60 ( V_144 , V_128 ) ;
F_72 ( args ) ;
return 0 ;
}
V_144 = F_57 ( args -> V_60 , args -> V_96 , args -> V_45 ,
args -> V_97 , V_123 ) ;
if ( ( error = F_4 ( V_144 , args -> V_47 , args -> V_42 , & V_54 ) ) )
goto V_124;
if ( ! V_54 ) {
V_143 = V_144 ;
V_144 = NULL ;
}
else if ( ( error = F_73 ( V_144 , & V_143 ) ) )
goto V_124;
if ( ( error = F_65 ( V_143 , 0 , & V_54 ) ) )
goto V_124;
if ( ! V_54 ) {
F_60 ( V_143 , V_128 ) ;
V_143 = NULL ;
}
do {
if ( V_144 ) {
if ( ( error = F_8 ( V_144 , & V_152 , & V_155 , & V_54 ) ) )
goto V_124;
F_58 ( args -> V_60 , V_54 == 1 , V_124 ) ;
F_11 ( args , V_152 , V_155 ,
& V_153 , & V_156 ) ;
if ( V_156 >= args -> V_23 && V_153 >= args -> V_21 )
break;
if ( ( error = F_66 ( V_144 , 0 , & V_54 ) ) )
goto V_124;
if ( ! V_54 || V_153 < args -> V_21 ) {
F_60 ( V_144 ,
V_128 ) ;
V_144 = NULL ;
}
}
if ( V_143 ) {
if ( ( error = F_8 ( V_143 , & V_145 , & V_148 , & V_54 ) ) )
goto V_124;
F_58 ( args -> V_60 , V_54 == 1 , V_124 ) ;
F_11 ( args , V_145 , V_148 ,
& V_146 , & V_149 ) ;
if ( V_149 >= args -> V_23 && V_146 <= args -> V_141 )
break;
if ( ( error = F_65 ( V_143 , 0 , & V_54 ) ) )
goto V_124;
if ( ! V_54 || V_146 > args -> V_141 ) {
F_60 ( V_143 ,
V_128 ) ;
V_143 = NULL ;
}
}
} while ( V_144 || V_143 );
if ( V_144 && V_143 ) {
if ( V_156 >= args -> V_23 ) {
args -> V_4 = F_15 ( V_156 , args -> V_42 ) ;
F_17 ( args ) ;
V_154 = F_14 ( args -> V_47 , args -> V_4 ,
args -> V_22 , args -> V_27 , V_153 ,
V_156 , & V_157 ) ;
error = F_64 ( args ,
& V_144 , & V_143 ,
V_154 , & V_145 , & V_148 ,
& V_146 , & V_149 ,
0 ) ;
} else {
ASSERT ( V_149 >= args -> V_23 ) ;
args -> V_4 = F_15 ( V_149 , args -> V_42 ) ;
F_17 ( args ) ;
V_147 = F_14 ( args -> V_47 , args -> V_4 ,
args -> V_22 , args -> V_27 , V_146 ,
V_149 , & V_150 ) ;
error = F_64 ( args ,
& V_143 , & V_144 ,
V_147 , & V_152 , & V_155 ,
& V_153 , & V_156 ,
1 ) ;
}
if ( error )
goto V_124;
}
if ( V_144 == NULL && V_143 == NULL ) {
F_60 ( V_48 , V_128 ) ;
if ( ! V_158 ++ ) {
F_74 ( args ) ;
F_75 ( args -> V_60 , V_166 ) ;
goto V_160;
}
F_76 ( args ) ;
args -> V_47 = V_37 ;
return 0 ;
}
if ( V_143 ) {
V_144 = V_143 ;
V_143 = NULL ;
V_152 = V_145 ;
V_153 = V_146 ;
V_155 = V_148 ;
V_156 = V_149 ;
V_151 = 1 ;
} else
V_151 = 0 ;
args -> V_4 = F_15 ( V_156 , args -> V_42 ) ;
F_17 ( args ) ;
if ( ! F_18 ( args ) ) {
F_71 ( args ) ;
F_60 ( V_144 , V_128 ) ;
F_60 ( V_48 , V_128 ) ;
return 0 ;
}
V_39 = args -> V_4 ;
( void ) F_14 ( args -> V_47 , V_39 , args -> V_22 ,
args -> V_27 , V_153 , V_156 , & V_157 ) ;
ASSERT ( V_157 >= V_152 ) ;
ASSERT ( V_157 + V_39 <= V_153 + V_156 ) ;
ASSERT ( V_157 + V_39 <= F_10 ( F_19 ( args -> V_45 ) -> V_108 ) ) ;
ASSERT ( V_157 >= args -> V_21 && V_157 <= args -> V_141 ) ;
args -> V_47 = V_157 ;
if ( ( error = F_20 ( V_48 , V_144 , V_152 , V_155 ,
V_157 , V_39 , V_63 ) ) )
goto V_124;
if ( V_151 )
F_77 ( args ) ;
else
F_78 ( args ) ;
F_60 ( V_48 , V_128 ) ;
F_60 ( V_144 , V_128 ) ;
return 0 ;
V_124:
F_79 ( args ) ;
if ( V_48 != NULL )
F_60 ( V_48 , V_127 ) ;
if ( V_144 != NULL )
F_60 ( V_144 , V_127 ) ;
if ( V_143 != NULL )
F_60 ( V_143 , V_127 ) ;
return error ;
}
STATIC int
F_50 (
T_3 * args )
{
T_5 * V_49 ;
T_5 * V_48 ;
int error ;
T_1 V_50 ;
T_2 V_51 ;
int V_54 ;
T_1 V_52 ;
T_2 V_39 ;
int V_158 = 0 ;
V_160:
V_48 = F_57 ( args -> V_60 , args -> V_96 , args -> V_45 ,
args -> V_97 , V_126 ) ;
V_49 = NULL ;
if ( ( error = F_3 ( V_48 , 0 ,
args -> V_42 + args -> V_22 - 1 , & V_54 ) ) )
goto V_124;
if ( ! V_54 || V_158 > 1 ) {
error = F_68 ( args , V_48 ,
& V_50 , & V_51 , & V_54 ) ;
if ( error )
goto V_124;
if ( V_54 == 0 || V_51 == 0 ) {
F_60 ( V_48 , V_128 ) ;
F_80 ( args ) ;
return 0 ;
}
ASSERT ( V_54 == 1 ) ;
F_11 ( args , V_50 , V_51 , & V_52 , & V_39 ) ;
} else {
for (; ; ) {
error = F_8 ( V_48 , & V_50 , & V_51 , & V_54 ) ;
if ( error )
goto V_124;
F_58 ( args -> V_60 , V_54 == 1 , V_124 ) ;
F_11 ( args , V_50 , V_51 ,
& V_52 , & V_39 ) ;
if ( V_39 >= args -> V_42 )
break;
error = F_65 ( V_48 , 0 , & V_54 ) ;
if ( error )
goto V_124;
if ( V_54 == 0 ) {
F_60 ( V_48 ,
V_128 ) ;
F_81 ( args ) ;
if ( ! V_158 ++ )
F_75 ( args -> V_60 , V_166 ) ;
goto V_160;
}
}
}
V_39 = F_15 ( args -> V_42 , V_39 ) ;
F_58 ( args -> V_60 , V_39 == 0 ||
( V_39 <= V_51 && V_52 + V_39 <= V_50 + V_51 ) , V_124 ) ;
if ( V_39 < args -> V_42 ) {
T_1 V_167 ;
T_2 V_168 ;
T_1 V_169 ;
T_2 V_170 ;
V_170 = V_39 ;
V_169 = V_52 ;
V_168 = V_51 ;
V_167 = V_50 ;
for (; ; ) {
if ( ( error = F_66 ( V_48 , 0 , & V_54 ) ) )
goto V_124;
if ( V_54 == 0 )
break;
if ( ( error = F_8 ( V_48 , & V_50 , & V_51 ,
& V_54 ) ) )
goto V_124;
F_58 ( args -> V_60 , V_54 == 1 , V_124 ) ;
if ( V_51 < V_170 )
break;
F_11 ( args , V_50 , V_51 ,
& V_52 , & V_39 ) ;
V_39 = F_15 ( args -> V_42 , V_39 ) ;
F_58 ( args -> V_60 , V_39 == 0 ||
( V_39 <= V_51 && V_52 + V_39 <= V_50 + V_51 ) ,
V_124 ) ;
if ( V_39 > V_170 ) {
V_170 = V_39 ;
V_169 = V_52 ;
V_168 = V_51 ;
V_167 = V_50 ;
if ( V_39 == args -> V_42 )
break;
}
}
if ( ( error = F_1 ( V_48 , V_167 , V_168 ,
& V_54 ) ) )
goto V_124;
F_58 ( args -> V_60 , V_54 == 1 , V_124 ) ;
V_39 = V_170 ;
V_52 = V_169 ;
V_51 = V_168 ;
V_50 = V_167 ;
}
args -> V_110 = 0 ;
args -> V_4 = V_39 ;
if ( V_39 < args -> V_23 ) {
if ( ! V_158 ++ ) {
F_60 ( V_48 , V_128 ) ;
F_81 ( args ) ;
F_75 ( args -> V_60 , V_166 ) ;
goto V_160;
}
goto V_171;
}
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_171;
V_39 = args -> V_4 ;
F_58 ( args -> V_60 , V_39 <= V_51 , V_124 ) ;
V_49 = F_57 ( args -> V_60 , args -> V_96 , args -> V_45 ,
args -> V_97 , V_123 ) ;
if ( ( error = F_20 ( V_48 , V_49 , V_50 , V_51 ,
V_52 , V_39 , V_62 ) ) )
goto V_124;
F_60 ( V_48 , V_128 ) ;
F_60 ( V_49 , V_128 ) ;
V_48 = V_49 = NULL ;
args -> V_4 = V_39 ;
args -> V_47 = V_52 ;
F_58 ( args -> V_60 ,
args -> V_47 + args -> V_4 <=
F_10 ( F_19 ( args -> V_45 ) -> V_108 ) ,
V_124 ) ;
F_82 ( args ) ;
return 0 ;
V_124:
F_83 ( args ) ;
if ( V_48 )
F_60 ( V_48 , V_127 ) ;
if ( V_49 )
F_60 ( V_49 , V_127 ) ;
return error ;
V_171:
F_60 ( V_48 , V_128 ) ;
F_84 ( args ) ;
args -> V_47 = V_37 ;
return 0 ;
}
STATIC int
F_68 (
T_3 * args ,
T_5 * V_172 ,
T_1 * V_173 ,
T_2 * V_174 ,
int * V_5 )
{
int error ;
T_1 V_50 ;
T_2 V_51 ;
int V_54 ;
if ( ( error = F_66 ( V_172 , 0 , & V_54 ) ) )
goto V_124;
if ( V_54 ) {
if ( ( error = F_8 ( V_172 , & V_50 , & V_51 , & V_54 ) ) )
goto V_124;
F_58 ( args -> V_60 , V_54 == 1 , V_124 ) ;
}
else if ( args -> V_23 == 1 && args -> V_22 == 1 && ! args -> V_114 &&
( F_10 ( F_19 ( args -> V_45 ) -> V_175 )
> args -> V_44 ) ) {
error = F_85 ( args -> V_96 , args -> V_45 , & V_50 , 0 ) ;
if ( error )
goto V_124;
if ( V_50 != V_37 ) {
F_86 ( args -> V_60 , args -> V_97 , V_50 , 1 ,
args -> V_27 ) ;
if ( args -> V_27 ) {
T_9 * V_71 ;
V_71 = F_87 ( args -> V_60 , args -> V_96 ,
args -> V_97 , V_50 , 0 ) ;
F_88 ( args -> V_96 , V_71 ) ;
}
args -> V_4 = 1 ;
args -> V_47 = V_50 ;
F_58 ( args -> V_60 ,
args -> V_47 + args -> V_4 <=
F_10 ( F_19 ( args -> V_45 ) -> V_108 ) ,
V_124 ) ;
args -> V_110 = 1 ;
F_89 ( args ) ;
* V_5 = 0 ;
return 0 ;
}
else
V_51 = 0 ;
}
else {
V_50 = V_37 ;
V_51 = 0 ;
}
if ( V_51 < args -> V_23 ) {
args -> V_47 = V_37 ;
F_90 ( args ) ;
V_51 = 0 ;
}
* V_173 = V_50 ;
* V_174 = V_51 ;
* V_5 = 1 ;
F_91 ( args ) ;
return 0 ;
V_124:
F_92 ( args ) ;
return error ;
}
STATIC int
F_93 (
T_7 * V_96 ,
T_9 * V_45 ,
T_8 V_97 ,
T_1 V_3 ,
T_2 V_4 ,
int V_114 )
{
T_5 * V_49 ;
T_5 * V_48 ;
int error ;
T_1 V_145 ;
T_2 V_148 ;
int V_176 ;
int V_177 ;
int V_54 ;
T_1 V_152 ;
T_2 V_155 ;
T_6 * V_60 ;
T_1 V_178 ;
T_2 V_179 ;
T_10 * V_105 ;
V_60 = V_96 -> V_180 ;
V_49 = F_57 ( V_60 , V_96 , V_45 , V_97 , V_123 ) ;
V_48 = NULL ;
if ( ( error = F_4 ( V_49 , V_3 , V_4 , & V_176 ) ) )
goto V_124;
if ( V_176 ) {
if ( ( error = F_8 ( V_49 , & V_152 , & V_155 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
if ( V_152 + V_155 < V_3 )
V_176 = 0 ;
else {
F_58 ( V_60 ,
V_152 + V_155 <= V_3 , V_124 ) ;
}
}
if ( ( error = F_65 ( V_49 , 0 , & V_177 ) ) )
goto V_124;
if ( V_177 ) {
if ( ( error = F_8 ( V_49 , & V_145 , & V_148 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
if ( V_3 + V_4 < V_145 )
V_177 = 0 ;
else {
F_58 ( V_60 , V_145 >= V_3 + V_4 , V_124 ) ;
}
}
V_48 = F_57 ( V_60 , V_96 , V_45 , V_97 , V_126 ) ;
if ( V_176 && V_177 ) {
if ( ( error = F_1 ( V_48 , V_152 , V_155 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
if ( ( error = F_24 ( V_48 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
if ( ( error = F_1 ( V_48 , V_145 , V_148 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
if ( ( error = F_24 ( V_48 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
if ( ( error = F_24 ( V_49 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
if ( ( error = F_66 ( V_49 , 0 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
#ifdef F_21
{
T_1 V_181 ;
T_2 V_182 ;
if ( ( error = F_8 ( V_49 , & V_181 , & V_182 ,
& V_54 ) ) )
goto V_124;
F_58 ( V_60 ,
V_54 == 1 && V_181 == V_152 && V_182 == V_155 ,
V_124 ) ;
}
#endif
V_178 = V_152 ;
V_179 = V_4 + V_155 + V_148 ;
if ( ( error = F_5 ( V_49 , V_178 , V_179 ) ) )
goto V_124;
}
else if ( V_176 ) {
if ( ( error = F_1 ( V_48 , V_152 , V_155 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
if ( ( error = F_24 ( V_48 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
if ( ( error = F_66 ( V_49 , 0 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
V_178 = V_152 ;
V_179 = V_4 + V_155 ;
if ( ( error = F_5 ( V_49 , V_178 , V_179 ) ) )
goto V_124;
}
else if ( V_177 ) {
if ( ( error = F_1 ( V_48 , V_145 , V_148 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
if ( ( error = F_24 ( V_48 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
V_178 = V_3 ;
V_179 = V_4 + V_148 ;
if ( ( error = F_5 ( V_49 , V_178 , V_179 ) ) )
goto V_124;
}
else {
V_178 = V_3 ;
V_179 = V_4 ;
if ( ( error = F_25 ( V_49 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
}
F_60 ( V_49 , V_128 ) ;
V_49 = NULL ;
if ( ( error = F_1 ( V_48 , V_178 , V_179 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 0 , V_124 ) ;
if ( ( error = F_25 ( V_48 , & V_54 ) ) )
goto V_124;
F_58 ( V_60 , V_54 == 1 , V_124 ) ;
F_60 ( V_48 , V_128 ) ;
V_48 = NULL ;
V_105 = F_94 ( V_60 , V_97 ) ;
error = F_44 ( V_96 , V_105 , V_45 , V_4 ) ;
F_95 ( V_105 ) ;
if ( error )
goto V_124;
if ( ! V_114 )
F_54 ( V_96 , V_117 , ( long ) V_4 ) ;
F_55 ( V_183 ) ;
F_56 ( V_184 , V_4 ) ;
F_96 ( V_60 , V_97 , V_3 , V_4 , V_114 , V_176 , V_177 ) ;
return 0 ;
V_124:
F_96 ( V_60 , V_97 , V_3 , V_4 , V_114 , - 1 , - 1 ) ;
if ( V_49 )
F_60 ( V_49 , V_127 ) ;
if ( V_48 )
F_60 ( V_48 , V_127 ) ;
return error ;
}
void
F_97 (
T_6 * V_60 )
{
int V_185 ;
T_11 V_186 ;
T_11 V_187 ;
int V_188 ;
int V_189 ;
V_187 = ( V_60 -> V_77 . V_85 + 1 ) / 2 ;
V_188 = V_60 -> V_190 [ 0 ] ;
V_189 = V_60 -> V_190 [ 1 ] ;
V_186 = ( V_187 + V_188 - 1 ) / V_188 ;
for ( V_185 = 1 ; V_186 > 1 ; V_185 ++ )
V_186 = ( V_186 + V_189 - 1 ) / V_189 ;
V_60 -> V_191 = V_185 ;
}
T_2
F_98 (
struct V_59 * V_60 ,
struct V_104 * V_105 ,
T_2 V_192 )
{
T_2 V_193 = 0 ;
if ( V_192 > V_105 -> V_194 )
V_193 = V_192 - V_105 -> V_194 ;
if ( V_105 -> V_195 > V_193 )
return V_105 -> V_195 - V_193 ;
return V_105 -> V_194 > 0 || V_105 -> V_195 > 0 ;
}
unsigned int
F_99 (
struct V_59 * V_60 ,
struct V_104 * V_105 )
{
unsigned int V_196 ;
V_196 = F_100 (unsigned int, pag->pagf_levels[XFS_BTNUM_BNOi] + 1 ,
mp->m_ag_maxlevels) ;
V_196 += F_100 (unsigned int, pag->pagf_levels[XFS_BTNUM_CNTi] + 1 ,
mp->m_ag_maxlevels) ;
return V_196 ;
}
static bool
F_101 (
struct V_129 * args ,
T_2 V_196 ,
int V_53 )
{
struct V_104 * V_105 = args -> V_105 ;
T_2 V_197 ;
int V_198 ;
if ( V_53 & V_199 )
return true ;
V_197 = F_98 ( args -> V_60 , V_105 , V_196 ) ;
if ( ( args -> V_23 + args -> V_22 + args -> V_200 - 1 ) > V_197 )
return false ;
V_198 = ( int ) ( V_105 -> V_107 + V_105 -> V_194 -
V_196 - args -> V_201 ) ;
if ( V_198 < ( int ) args -> V_44 )
return false ;
return true ;
}
STATIC int
F_102 (
struct V_129 * args ,
int V_53 )
{
struct V_59 * V_60 = args -> V_60 ;
struct V_104 * V_105 = args -> V_105 ;
struct V_103 * V_96 = args -> V_96 ;
struct V_70 * V_45 = NULL ;
struct V_70 * V_202 = NULL ;
struct V_129 V_203 ;
T_1 V_3 ;
T_2 V_192 ;
int error ;
if ( ! V_105 -> V_204 ) {
error = F_103 ( V_60 , V_96 , args -> V_97 , V_53 , & V_45 ) ;
if ( error )
goto V_205;
if ( ! V_105 -> V_204 ) {
ASSERT ( V_53 & V_206 ) ;
ASSERT ( ! ( V_53 & V_199 ) ) ;
goto V_207;
}
}
if ( V_105 -> V_208 && args -> V_27 &&
( V_53 & V_206 ) ) {
ASSERT ( ! ( V_53 & V_199 ) ) ;
goto V_207;
}
V_192 = F_99 ( V_60 , V_105 ) ;
if ( ! F_101 ( args , V_192 , V_53 ) )
goto V_207;
if ( ! V_45 ) {
error = F_103 ( V_60 , V_96 , args -> V_97 , V_53 , & V_45 ) ;
if ( error )
goto V_205;
if ( ! V_45 ) {
ASSERT ( V_53 & V_206 ) ;
ASSERT ( ! ( V_53 & V_199 ) ) ;
goto V_205;
}
}
V_192 = F_99 ( V_60 , V_105 ) ;
if ( ! F_101 ( args , V_192 , V_53 ) )
goto V_207;
while ( V_105 -> V_194 > V_192 ) {
struct V_70 * V_71 ;
error = F_85 ( V_96 , V_45 , & V_3 , 0 ) ;
if ( error )
goto V_207;
error = F_93 ( V_96 , V_45 , args -> V_97 , V_3 , 1 , 1 ) ;
if ( error )
goto V_207;
V_71 = F_87 ( V_60 , V_96 , args -> V_97 , V_3 , 0 ) ;
F_88 ( V_96 , V_71 ) ;
}
memset ( & V_203 , 0 , sizeof( V_203 ) ) ;
V_203 . V_96 = V_96 ;
V_203 . V_60 = V_60 ;
V_203 . V_45 = V_45 ;
V_203 . V_97 = args -> V_97 ;
V_203 . V_22 = V_203 . V_23 = V_203 . V_41 = V_203 . V_114 = 1 ;
V_203 . type = V_111 ;
V_203 . V_105 = V_105 ;
error = F_38 ( V_60 , V_96 , V_203 . V_97 , & V_202 ) ;
if ( error )
goto V_207;
while ( V_105 -> V_194 < V_192 ) {
V_203 . V_47 = 0 ;
V_203 . V_42 = V_192 - V_105 -> V_194 ;
error = F_49 ( & V_203 ) ;
if ( error )
goto V_209;
if ( V_203 . V_47 == V_37 ) {
if ( V_53 & V_199 )
break;
goto V_209;
}
for ( V_3 = V_203 . V_47 ; V_3 < V_203 . V_47 + V_203 . V_4 ; V_3 ++ ) {
error = F_104 ( V_96 , V_45 ,
V_202 , V_3 , 0 ) ;
if ( error )
goto V_209;
}
}
F_105 ( V_96 , V_202 ) ;
args -> V_45 = V_45 ;
return 0 ;
V_209:
F_105 ( V_96 , V_202 ) ;
V_207:
if ( V_45 )
F_105 ( V_96 , V_45 ) ;
V_205:
args -> V_45 = NULL ;
return error ;
}
int
F_85 (
T_7 * V_96 ,
T_9 * V_45 ,
T_1 * V_210 ,
int V_211 )
{
T_4 * V_43 ;
T_9 * V_202 ;
T_1 V_3 ;
T_12 * V_84 ;
int error ;
int V_212 ;
T_6 * V_60 = V_96 -> V_180 ;
T_10 * V_105 ;
V_43 = F_19 ( V_45 ) ;
if ( ! V_43 -> V_175 ) {
* V_210 = V_37 ;
return 0 ;
}
error = F_38 ( V_60 , V_96 , F_10 ( V_43 -> V_213 ) ,
& V_202 ) ;
if ( error )
return error ;
V_84 = F_106 ( V_60 , V_202 ) ;
V_3 = F_10 ( V_84 [ F_10 ( V_43 -> V_214 ) ] ) ;
F_45 ( & V_43 -> V_214 , 1 ) ;
F_105 ( V_96 , V_202 ) ;
if ( F_10 ( V_43 -> V_214 ) == F_29 ( V_60 ) )
V_43 -> V_214 = 0 ;
V_105 = F_94 ( V_60 , F_10 ( V_43 -> V_213 ) ) ;
F_45 ( & V_43 -> V_175 , - 1 ) ;
F_107 ( V_96 , - 1 ) ;
V_105 -> V_194 -- ;
F_95 ( V_105 ) ;
V_212 = V_215 | V_216 ;
if ( V_211 ) {
F_45 ( & V_43 -> V_217 , 1 ) ;
V_105 -> V_218 ++ ;
V_212 |= V_219 ;
}
F_48 ( V_96 , V_45 , V_212 ) ;
* V_210 = V_3 ;
return 0 ;
}
void
F_48 (
T_7 * V_96 ,
T_9 * V_71 ,
int V_220 )
{
int V_221 ;
int V_222 ;
static const short V_223 [] = {
F_108 ( T_4 , V_224 ) ,
F_108 ( T_4 , V_225 ) ,
F_108 ( T_4 , V_213 ) ,
F_108 ( T_4 , V_108 ) ,
F_108 ( T_4 , V_226 [ 0 ] ) ,
F_108 ( T_4 , V_227 [ 0 ] ) ,
F_108 ( T_4 , V_214 ) ,
F_108 ( T_4 , V_228 ) ,
F_108 ( T_4 , V_175 ) ,
F_108 ( T_4 , V_46 ) ,
F_108 ( T_4 , V_229 ) ,
F_108 ( T_4 , V_217 ) ,
F_108 ( T_4 , V_230 ) ,
sizeof( T_4 )
} ;
F_109 ( V_96 -> V_180 , F_19 ( V_71 ) , V_220 , V_231 ) ;
F_110 ( V_96 , V_71 , V_232 ) ;
F_111 ( V_220 , V_223 , V_233 , & V_221 , & V_222 ) ;
F_112 ( V_96 , V_71 , ( T_11 ) V_221 , ( T_11 ) V_222 ) ;
}
int
F_113 (
T_6 * V_60 ,
T_7 * V_96 ,
T_8 V_97 ,
int V_53 )
{
T_9 * V_71 ;
int error ;
if ( ( error = F_103 ( V_60 , V_96 , V_97 , V_53 , & V_71 ) ) )
return error ;
if ( V_71 )
F_105 ( V_96 , V_71 ) ;
return 0 ;
}
int
F_104 (
T_7 * V_96 ,
T_9 * V_45 ,
T_9 * V_202 ,
T_1 V_3 ,
int V_211 )
{
T_4 * V_43 ;
T_12 * V_234 ;
int error ;
int V_212 ;
T_6 * V_60 ;
T_10 * V_105 ;
T_12 * V_84 ;
int V_235 ;
V_43 = F_19 ( V_45 ) ;
V_60 = V_96 -> V_180 ;
if ( ! V_202 && ( error = F_38 ( V_60 , V_96 ,
F_10 ( V_43 -> V_213 ) , & V_202 ) ) )
return error ;
F_45 ( & V_43 -> V_228 , 1 ) ;
if ( F_10 ( V_43 -> V_228 ) == F_29 ( V_60 ) )
V_43 -> V_228 = 0 ;
V_105 = F_94 ( V_60 , F_10 ( V_43 -> V_213 ) ) ;
F_45 ( & V_43 -> V_175 , 1 ) ;
F_107 ( V_96 , 1 ) ;
V_105 -> V_194 ++ ;
V_212 = V_236 | V_216 ;
if ( V_211 ) {
F_45 ( & V_43 -> V_217 , - 1 ) ;
V_105 -> V_218 -- ;
V_212 |= V_219 ;
}
F_95 ( V_105 ) ;
F_48 ( V_96 , V_45 , V_212 ) ;
ASSERT ( F_10 ( V_43 -> V_175 ) <= F_29 ( V_60 ) ) ;
V_84 = F_106 ( V_60 , V_202 ) ;
V_234 = & V_84 [ F_10 ( V_43 -> V_228 ) ] ;
* V_234 = F_6 ( V_3 ) ;
V_235 = ( char * ) V_234 - ( char * ) V_202 -> V_237 ;
F_48 ( V_96 , V_45 , V_212 ) ;
F_110 ( V_96 , V_202 , V_238 ) ;
F_112 ( V_96 , V_202 , V_235 ,
V_235 + sizeof( T_1 ) - 1 ) ;
return 0 ;
}
static bool
F_114 (
struct V_59 * V_60 ,
struct V_70 * V_71 )
{
struct V_106 * V_43 = F_19 ( V_71 ) ;
if ( F_31 ( & V_60 -> V_77 ) &&
! F_28 ( & V_43 -> V_230 , & V_60 -> V_77 . V_78 ) )
return false ;
if ( ! ( V_43 -> V_224 == F_6 ( V_239 ) &&
F_115 ( F_10 ( V_43 -> V_225 ) ) &&
F_10 ( V_43 -> V_46 ) <= F_10 ( V_43 -> V_108 ) &&
F_10 ( V_43 -> V_214 ) < F_29 ( V_60 ) &&
F_10 ( V_43 -> V_228 ) < F_29 ( V_60 ) &&
F_10 ( V_43 -> V_175 ) <= F_29 ( V_60 ) ) )
return false ;
if ( F_10 ( V_43 -> V_227 [ V_123 ] ) > V_240 ||
F_10 ( V_43 -> V_227 [ V_126 ] ) > V_240 )
return false ;
if ( V_71 -> V_81 && F_10 ( V_43 -> V_213 ) != V_71 -> V_81 -> V_83 )
return false ;
if ( F_116 ( & V_60 -> V_77 ) &&
F_10 ( V_43 -> V_217 ) > F_10 ( V_43 -> V_108 ) )
return false ;
return true ; ;
}
static void
F_117 (
struct V_70 * V_71 )
{
struct V_59 * V_60 = V_71 -> V_72 -> V_73 ;
if ( F_31 ( & V_60 -> V_77 ) &&
! F_32 ( V_71 , V_241 ) )
F_33 ( V_71 , - V_87 ) ;
else if ( F_118 ( ! F_114 ( V_60 , V_71 ) , V_60 ,
V_242 ,
V_243 ) )
F_33 ( V_71 , - V_88 ) ;
if ( V_71 -> V_89 )
F_34 ( V_71 ) ;
}
static void
F_119 (
struct V_70 * V_71 )
{
struct V_59 * V_60 = V_71 -> V_72 -> V_73 ;
struct V_90 * V_91 = V_71 -> V_92 ;
if ( ! F_114 ( V_60 , V_71 ) ) {
F_33 ( V_71 , - V_88 ) ;
F_34 ( V_71 ) ;
return;
}
if ( ! F_31 ( & V_60 -> V_77 ) )
return;
if ( V_91 )
F_19 ( V_71 ) -> V_244 = F_36 ( V_91 -> V_94 . V_95 ) ;
F_37 ( V_71 , V_241 ) ;
}
int
F_120 (
struct V_59 * V_60 ,
struct V_103 * V_96 ,
T_8 V_97 ,
int V_53 ,
struct V_70 * * V_98 )
{
int error ;
F_121 ( V_60 , V_97 ) ;
ASSERT ( V_97 != V_99 ) ;
error = F_39 (
V_60 , V_96 , V_60 -> V_100 ,
F_40 ( V_60 , V_97 , F_122 ( V_60 ) ) ,
F_42 ( V_60 , 1 ) , V_53 , V_98 , & V_245 ) ;
if ( error )
return error ;
if ( ! * V_98 )
return 0 ;
ASSERT ( ! ( * V_98 ) -> V_89 ) ;
F_43 ( * V_98 , V_246 ) ;
return 0 ;
}
int
F_103 (
struct V_59 * V_60 ,
struct V_103 * V_96 ,
T_8 V_97 ,
int V_53 ,
struct V_70 * * V_98 )
{
struct V_106 * V_43 ;
struct V_104 * V_105 ;
int error ;
F_123 ( V_60 , V_97 ) ;
ASSERT ( V_97 != V_99 ) ;
error = F_120 ( V_60 , V_96 , V_97 ,
( V_53 & V_206 ) ? V_247 : 0 ,
V_98 ) ;
if ( error )
return error ;
if ( ! * V_98 )
return 0 ;
ASSERT ( ! ( * V_98 ) -> V_89 ) ;
V_43 = F_19 ( * V_98 ) ;
V_105 = F_94 ( V_60 , V_97 ) ;
if ( ! V_105 -> V_204 ) {
V_105 -> V_107 = F_10 ( V_43 -> V_46 ) ;
V_105 -> V_218 = F_10 ( V_43 -> V_217 ) ;
V_105 -> V_194 = F_10 ( V_43 -> V_175 ) ;
V_105 -> V_195 = F_10 ( V_43 -> V_229 ) ;
V_105 -> V_248 [ V_249 ] =
F_10 ( V_43 -> V_227 [ V_249 ] ) ;
V_105 -> V_248 [ V_250 ] =
F_10 ( V_43 -> V_227 [ V_250 ] ) ;
F_124 ( & V_105 -> V_251 ) ;
V_105 -> V_252 = 0 ;
V_105 -> V_253 = V_254 ;
V_105 -> V_204 = 1 ;
}
#ifdef F_21
else if ( ! F_125 ( V_60 ) ) {
ASSERT ( V_105 -> V_107 == F_10 ( V_43 -> V_46 ) ) ;
ASSERT ( V_105 -> V_218 == F_10 ( V_43 -> V_217 ) ) ;
ASSERT ( V_105 -> V_194 == F_10 ( V_43 -> V_175 ) ) ;
ASSERT ( V_105 -> V_195 == F_10 ( V_43 -> V_229 ) ) ;
ASSERT ( V_105 -> V_248 [ V_249 ] ==
F_10 ( V_43 -> V_227 [ V_249 ] ) ) ;
ASSERT ( V_105 -> V_248 [ V_250 ] ==
F_10 ( V_43 -> V_227 [ V_250 ] ) ) ;
}
#endif
F_95 ( V_105 ) ;
return 0 ;
}
int
F_126 (
T_3 * args )
{
T_1 V_255 ;
int error ;
int V_53 ;
T_2 V_44 ;
T_6 * V_60 ;
T_8 V_256 ;
T_13 type ;
int V_257 = 0 ;
int V_258 = 0 ;
T_8 V_259 = V_260 ;
V_60 = args -> V_60 ;
type = args -> V_261 = args -> type ;
args -> V_47 = V_37 ;
V_255 = V_60 -> V_77 . V_85 ;
if ( args -> V_42 > V_255 )
args -> V_42 = V_255 ;
if ( args -> V_22 == 0 )
args -> V_22 = 1 ;
ASSERT ( F_127 ( V_60 , args -> V_262 ) < V_60 -> V_77 . V_263 ) ;
ASSERT ( F_128 ( V_60 , args -> V_262 ) < V_255 ) ;
ASSERT ( args -> V_23 <= args -> V_42 ) ;
ASSERT ( args -> V_23 <= V_255 ) ;
ASSERT ( args -> V_40 < args -> V_41 ) ;
if ( F_127 ( V_60 , args -> V_262 ) >= V_60 -> V_77 . V_263 ||
F_128 ( V_60 , args -> V_262 ) >= V_255 ||
args -> V_23 > args -> V_42 || args -> V_23 > V_255 ||
args -> V_40 >= args -> V_41 ) {
args -> V_262 = V_264 ;
F_129 ( args ) ;
return 0 ;
}
V_44 = args -> V_44 ;
switch ( type ) {
case V_111 :
case V_112 :
case V_113 :
args -> V_97 = F_127 ( V_60 , args -> V_262 ) ;
args -> V_105 = F_94 ( V_60 , args -> V_97 ) ;
args -> V_44 = 0 ;
error = F_102 ( args , 0 ) ;
args -> V_44 = V_44 ;
if ( error ) {
F_130 ( args ) ;
goto V_124;
}
if ( ! args -> V_45 ) {
F_131 ( args ) ;
break;
}
args -> V_47 = F_128 ( V_60 , args -> V_262 ) ;
if ( ( error = F_49 ( args ) ) )
goto V_124;
break;
case V_265 :
if ( ( args -> V_27 == V_266 ) &&
( V_60 -> V_267 & V_268 ) ) {
args -> V_262 = F_132 ( V_60 ,
( ( V_60 -> V_269 / V_259 ) %
V_60 -> V_77 . V_263 ) , 0 ) ;
V_257 = 1 ;
}
args -> V_47 = F_128 ( V_60 , args -> V_262 ) ;
args -> type = V_112 ;
case V_270 :
case V_271 :
case V_272 :
if ( type == V_270 ) {
args -> V_97 = V_256 = ( V_60 -> V_269 / V_259 ) %
V_60 -> V_77 . V_263 ;
args -> type = V_111 ;
V_53 = V_206 ;
} else if ( type == V_272 ) {
args -> V_97 = F_127 ( V_60 , args -> V_262 ) ;
args -> type = V_111 ;
V_256 = 0 ;
V_53 = 0 ;
} else {
if ( type == V_271 )
args -> type = V_111 ;
args -> V_97 = V_256 = F_127 ( V_60 , args -> V_262 ) ;
V_53 = V_206 ;
}
for (; ; ) {
args -> V_105 = F_94 ( V_60 , args -> V_97 ) ;
if ( V_258 ) args -> V_44 = 0 ;
error = F_102 ( args , V_53 ) ;
args -> V_44 = V_44 ;
if ( error ) {
F_130 ( args ) ;
goto V_124;
}
if ( args -> V_45 ) {
if ( ( error = F_49 ( args ) ) )
goto V_124;
break;
}
F_133 ( args ) ;
if ( args -> V_97 == V_256 &&
type == V_265 )
args -> type = V_111 ;
if ( ++ ( args -> V_97 ) == V_60 -> V_77 . V_263 ) {
if ( args -> V_273 != V_264 )
args -> V_97 = V_256 ;
else
args -> V_97 = 0 ;
}
if ( args -> V_97 == V_256 ) {
if ( V_258 == 1 ) {
args -> V_47 = V_37 ;
F_134 ( args ) ;
break;
}
if ( V_53 == 0 ) {
V_258 = 1 ;
} else {
V_53 = 0 ;
if ( type == V_265 ) {
args -> V_47 = F_128 ( V_60 ,
args -> V_262 ) ;
args -> type = V_112 ;
}
}
}
F_95 ( args -> V_105 ) ;
}
if ( V_257 || ( type == V_270 ) ) {
if ( args -> V_97 == V_256 )
V_60 -> V_269 = ( V_60 -> V_269 + 1 ) %
( V_60 -> V_77 . V_263 * V_259 ) ;
else
V_60 -> V_269 = ( args -> V_97 * V_259 + 1 ) %
( V_60 -> V_77 . V_263 * V_259 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_47 == V_37 )
args -> V_262 = V_264 ;
else {
args -> V_262 = F_132 ( V_60 , args -> V_97 , args -> V_47 ) ;
#ifdef F_21
ASSERT ( args -> V_4 >= args -> V_23 ) ;
ASSERT ( args -> V_4 <= args -> V_42 ) ;
ASSERT ( args -> V_47 % args -> V_22 == 0 ) ;
F_135 ( V_60 , F_136 ( V_60 , args -> V_262 ) ,
args -> V_4 ) ;
#endif
}
F_95 ( args -> V_105 ) ;
return 0 ;
V_124:
F_95 ( args -> V_105 ) ;
return error ;
}
int
F_137 (
T_7 * V_96 ,
T_14 V_3 ,
T_2 V_4 )
{
T_3 args ;
int error ;
ASSERT ( V_4 != 0 ) ;
memset ( & args , 0 , sizeof( T_3 ) ) ;
args . V_96 = V_96 ;
args . V_60 = V_96 -> V_180 ;
args . V_97 = F_127 ( args . V_60 , V_3 ) ;
if ( args . V_97 >= args . V_60 -> V_77 . V_263 )
return - V_88 ;
args . V_47 = F_128 ( args . V_60 , V_3 ) ;
if ( args . V_47 >= args . V_60 -> V_77 . V_85 )
return - V_88 ;
args . V_105 = F_94 ( args . V_60 , args . V_97 ) ;
ASSERT ( args . V_105 ) ;
error = F_102 ( & args , V_199 ) ;
if ( error )
goto V_124;
if ( args . V_47 + V_4 >
F_10 ( F_19 ( args . V_45 ) -> V_108 ) ) {
error = - V_88 ;
goto V_124;
}
error = F_93 ( V_96 , args . V_45 , args . V_97 , args . V_47 , V_4 , 0 ) ;
if ( ! error )
F_138 ( V_96 , args . V_97 , args . V_47 , V_4 , 0 ) ;
V_124:
F_95 ( args . V_105 ) ;
return error ;
}
