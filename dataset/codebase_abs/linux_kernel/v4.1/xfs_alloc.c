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
F_12 ( args , V_16 , V_17 , & V_3 , & V_4 ) ;
if ( args -> V_20 > 1 && V_4 >= args -> V_21 ) {
T_1 V_22 = F_13 ( V_3 , args -> V_20 ) ;
T_2 V_23 = V_22 - V_3 ;
* V_18 = V_22 ;
* V_19 = V_23 >= V_4 ? 0 : V_4 - V_23 ;
} else {
* V_18 = V_3 ;
* V_19 = V_4 ;
}
}
STATIC T_2
F_14 (
T_1 V_24 ,
T_2 V_25 ,
T_2 V_20 ,
char V_26 ,
T_1 V_27 ,
T_2 V_28 ,
T_1 * V_29 )
{
T_1 V_30 ;
T_1 V_31 ;
T_1 V_32 ;
T_2 V_33 = 0 ;
T_2 V_34 = 0 ;
T_1 V_35 ;
ASSERT ( V_28 >= V_25 ) ;
V_30 = V_27 + V_28 ;
V_35 = V_24 + V_25 ;
if ( V_27 >= V_24 || ( V_26 && V_30 < V_35 ) ) {
if ( ( V_31 = F_13 ( V_27 , V_20 ) ) >= V_30 )
V_31 = V_36 ;
} else if ( V_30 >= V_35 && V_20 > 1 ) {
V_31 = F_13 ( V_24 , V_20 ) ;
V_32 = V_31 - V_20 ;
if ( V_31 >= V_30 )
V_31 = V_36 ;
else
V_33 = F_15 ( V_25 , V_30 - V_31 ) ;
if ( V_32 < V_27 )
V_32 = V_36 ;
else
V_34 = F_15 ( V_25 , V_30 - V_32 ) ;
if ( V_31 != V_36 && V_32 != V_36 ) {
if ( V_33 < V_34 ||
( V_33 == V_34 &&
F_16 ( V_31 , V_24 ) >
F_16 ( V_32 , V_24 ) ) )
V_31 = V_32 ;
} else if ( V_32 != V_36 )
V_31 = V_32 ;
} else if ( V_30 >= V_35 ) {
V_31 = V_24 ;
} else if ( V_20 > 1 ) {
V_31 = F_13 ( V_30 - V_25 , V_20 ) ;
if ( V_31 > V_30 - V_25 &&
V_31 - V_20 >= V_27 )
V_31 -= V_20 ;
else if ( V_31 >= V_30 )
V_31 = V_36 ;
} else
V_31 = V_30 - V_25 ;
* V_29 = V_31 ;
return V_31 == V_36 ? 0 : F_16 ( V_31 , V_24 ) ;
}
STATIC void
F_17 (
T_3 * args )
{
T_2 V_37 ;
T_2 V_38 ;
ASSERT ( args -> V_39 < args -> V_40 ) ;
V_38 = args -> V_4 ;
ASSERT ( V_38 >= args -> V_21 ) ;
ASSERT ( V_38 <= args -> V_41 ) ;
if ( args -> V_40 <= 1 || V_38 < args -> V_39 || V_38 == args -> V_41 ||
( args -> V_39 == 0 && V_38 < args -> V_40 ) )
return;
V_37 = V_38 % args -> V_40 ;
if ( V_37 == args -> V_39 )
return;
if ( V_37 > args -> V_39 )
V_38 = V_38 - ( V_37 - args -> V_39 ) ;
else
V_38 = V_38 - args -> V_40 + ( args -> V_39 - V_37 ) ;
if ( ( int ) V_38 < ( int ) args -> V_21 )
return;
ASSERT ( V_38 >= args -> V_21 && V_38 <= args -> V_41 ) ;
ASSERT ( V_38 % args -> V_40 == args -> V_39 ) ;
args -> V_4 = V_38 ;
}
STATIC int
F_18 (
T_3 * args )
{
T_4 * V_42 ;
int V_23 ;
if ( args -> V_43 == 0 )
return 1 ;
V_42 = F_19 ( args -> V_44 ) ;
V_23 = F_10 ( V_42 -> V_45 )
- args -> V_4 - args -> V_43 ;
if ( V_23 >= 0 )
return 1 ;
args -> V_4 += V_23 ;
if ( ( int ) args -> V_4 >= ( int ) args -> V_21 )
return 1 ;
args -> V_46 = V_36 ;
return 0 ;
}
STATIC int
F_20 (
T_5 * V_47 ,
T_5 * V_48 ,
T_1 V_49 ,
T_2 V_50 ,
T_1 V_51 ,
T_2 V_38 ,
int V_52 )
{
int error ;
int V_53 ;
T_1 V_54 ;
T_1 V_55 ;
T_2 V_56 = 0 ;
T_2 V_57 = 0 ;
struct V_58 * V_59 ;
V_59 = V_47 -> V_60 ;
if ( V_52 & V_61 ) {
#ifdef F_21
if ( ( error = F_8 ( V_47 , & V_54 , & V_56 , & V_53 ) ) )
return error ;
F_22 ( V_59 ,
V_53 == 1 && V_54 == V_49 && V_56 == V_50 ) ;
#endif
} else {
if ( ( error = F_1 ( V_47 , V_49 , V_50 , & V_53 ) ) )
return error ;
F_22 ( V_59 , V_53 == 1 ) ;
}
if ( V_52 & V_62 ) {
#ifdef F_21
if ( ( error = F_8 ( V_48 , & V_54 , & V_56 , & V_53 ) ) )
return error ;
F_22 ( V_59 ,
V_53 == 1 && V_54 == V_49 && V_56 == V_50 ) ;
#endif
} else {
if ( ( error = F_1 ( V_48 , V_49 , V_50 , & V_53 ) ) )
return error ;
F_22 ( V_59 , V_53 == 1 ) ;
}
#ifdef F_21
if ( V_48 -> V_63 == 1 && V_47 -> V_63 == 1 ) {
struct V_64 * V_65 ;
struct V_64 * V_66 ;
V_65 = F_23 ( V_48 -> V_67 [ 0 ] ) ;
V_66 = F_23 ( V_47 -> V_67 [ 0 ] ) ;
F_22 ( V_59 ,
V_65 -> V_68 == V_66 -> V_68 ) ;
}
#endif
if ( V_51 == V_49 && V_38 == V_50 )
V_54 = V_55 = V_36 ;
else if ( V_51 == V_49 ) {
V_54 = V_51 + V_38 ;
V_56 = V_50 - V_38 ;
V_55 = V_36 ;
} else if ( V_51 + V_38 == V_49 + V_50 ) {
V_54 = V_49 ;
V_56 = V_50 - V_38 ;
V_55 = V_36 ;
} else {
V_54 = V_49 ;
V_56 = V_51 - V_49 ;
V_55 = V_51 + V_38 ;
V_57 = ( V_49 + V_50 ) - V_55 ;
}
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
return error ;
F_22 ( V_59 , V_53 == 1 ) ;
if ( V_54 != V_36 ) {
if ( ( error = F_1 ( V_47 , V_54 , V_56 , & V_53 ) ) )
return error ;
F_22 ( V_59 , V_53 == 0 ) ;
if ( ( error = F_25 ( V_47 , & V_53 ) ) )
return error ;
F_22 ( V_59 , V_53 == 1 ) ;
}
if ( V_55 != V_36 ) {
if ( ( error = F_1 ( V_47 , V_55 , V_57 , & V_53 ) ) )
return error ;
F_22 ( V_59 , V_53 == 0 ) ;
if ( ( error = F_25 ( V_47 , & V_53 ) ) )
return error ;
F_22 ( V_59 , V_53 == 1 ) ;
}
if ( V_54 == V_36 ) {
if ( ( error = F_24 ( V_48 , & V_53 ) ) )
return error ;
F_22 ( V_59 , V_53 == 1 ) ;
} else {
if ( ( error = F_5 ( V_48 , V_54 , V_56 ) ) )
return error ;
}
if ( V_55 != V_36 ) {
if ( ( error = F_1 ( V_48 , V_55 , V_57 , & V_53 ) ) )
return error ;
F_22 ( V_59 , V_53 == 0 ) ;
if ( ( error = F_25 ( V_48 , & V_53 ) ) )
return error ;
F_22 ( V_59 , V_53 == 1 ) ;
}
return 0 ;
}
static bool
F_26 (
struct V_69 * V_70 )
{
struct V_58 * V_59 = V_70 -> V_71 -> V_72 ;
struct V_73 * V_74 = F_27 ( V_70 ) ;
int V_53 ;
if ( ! F_28 ( & V_74 -> V_75 , & V_59 -> V_76 . V_77 ) )
return false ;
if ( F_10 ( V_74 -> V_78 ) != V_79 )
return false ;
if ( V_70 -> V_80 && F_10 ( V_74 -> V_81 ) != V_70 -> V_80 -> V_82 )
return false ;
for ( V_53 = 0 ; V_53 < F_29 ( V_59 ) ; V_53 ++ ) {
if ( F_10 ( V_74 -> V_83 [ V_53 ] ) != V_36 &&
F_10 ( V_74 -> V_83 [ V_53 ] ) >= V_59 -> V_76 . V_84 )
return false ;
}
return true ;
}
static void
F_30 (
struct V_69 * V_70 )
{
struct V_58 * V_59 = V_70 -> V_71 -> V_72 ;
if ( ! F_31 ( & V_59 -> V_76 ) )
return;
if ( ! F_32 ( V_70 , V_85 ) )
F_33 ( V_70 , - V_86 ) ;
else if ( ! F_26 ( V_70 ) )
F_33 ( V_70 , - V_87 ) ;
if ( V_70 -> V_88 )
F_34 ( V_70 ) ;
}
static void
F_35 (
struct V_69 * V_70 )
{
struct V_58 * V_59 = V_70 -> V_71 -> V_72 ;
struct V_89 * V_90 = V_70 -> V_91 ;
if ( ! F_31 ( & V_59 -> V_76 ) )
return;
if ( ! F_26 ( V_70 ) ) {
F_33 ( V_70 , - V_87 ) ;
F_34 ( V_70 ) ;
return;
}
if ( V_90 )
F_27 ( V_70 ) -> V_92 = F_36 ( V_90 -> V_93 . V_94 ) ;
F_37 ( V_70 , V_85 ) ;
}
STATIC int
F_38 (
T_6 * V_59 ,
T_7 * V_95 ,
T_8 V_96 ,
T_9 * * V_97 )
{
T_9 * V_70 ;
int error ;
ASSERT ( V_96 != V_98 ) ;
error = F_39 (
V_59 , V_95 , V_59 -> V_99 ,
F_40 ( V_59 , V_96 , F_41 ( V_59 ) ) ,
F_42 ( V_59 , 1 ) , 0 , & V_70 , & V_100 ) ;
if ( error )
return error ;
F_43 ( V_70 , V_101 ) ;
* V_97 = V_70 ;
return 0 ;
}
STATIC int
F_44 (
struct V_102 * V_95 ,
struct V_103 * V_104 ,
struct V_69 * V_44 ,
long V_4 )
{
struct V_105 * V_42 = F_19 ( V_44 ) ;
V_104 -> V_106 += V_4 ;
F_45 ( & V_42 -> V_45 , V_4 ) ;
F_46 ( V_95 , V_4 ) ;
if ( F_47 ( F_10 ( V_42 -> V_45 ) >
F_10 ( V_42 -> V_107 ) ) )
return - V_87 ;
F_48 ( V_95 , V_44 , V_108 ) ;
return 0 ;
}
STATIC int
F_49 (
T_3 * args )
{
int error = 0 ;
ASSERT ( args -> V_21 > 0 ) ;
ASSERT ( args -> V_41 > 0 ) ;
ASSERT ( args -> V_21 <= args -> V_41 ) ;
ASSERT ( args -> V_39 < args -> V_40 ) ;
ASSERT ( args -> V_20 > 0 ) ;
args -> V_109 = 0 ;
switch ( args -> type ) {
case V_110 :
error = F_50 ( args ) ;
break;
case V_111 :
error = F_51 ( args ) ;
break;
case V_112 :
error = F_52 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error || args -> V_46 == V_36 )
return error ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_41 ) ;
ASSERT ( ! args -> V_109 || ! args -> V_113 ) ;
ASSERT ( args -> V_46 % args -> V_20 == 0 ) ;
if ( ! args -> V_109 ) {
error = F_44 ( args -> V_95 , args -> V_104 ,
args -> V_44 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_53 ( args -> V_59 , args -> V_96 ,
args -> V_46 , args -> V_4 ) ) ;
}
if ( ! args -> V_113 ) {
F_54 ( args -> V_95 , args -> V_114 ?
V_115 :
V_116 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
}
F_55 ( V_117 ) ;
F_56 ( V_118 , args -> V_4 ) ;
return error ;
}
STATIC int
F_52 (
T_3 * args )
{
T_5 * V_48 ;
T_5 * V_47 ;
int error ;
T_1 V_49 ;
T_2 V_50 ;
T_1 V_119 ;
T_2 V_120 ;
T_1 V_121 ;
int V_53 ;
ASSERT ( args -> V_20 == 1 ) ;
V_48 = F_57 ( args -> V_59 , args -> V_95 , args -> V_44 ,
args -> V_96 , V_122 ) ;
error = F_4 ( V_48 , args -> V_46 , args -> V_21 , & V_53 ) ;
if ( error )
goto V_123;
if ( ! V_53 )
goto V_124;
error = F_8 ( V_48 , & V_49 , & V_50 , & V_53 ) ;
if ( error )
goto V_123;
F_58 ( args -> V_59 , V_53 == 1 , V_123 ) ;
ASSERT ( V_49 <= args -> V_46 ) ;
F_12 ( args , V_49 , V_50 , & V_119 , & V_120 ) ;
if ( V_119 > args -> V_46 )
goto V_124;
if ( V_120 < args -> V_21 )
goto V_124;
V_121 = V_119 + V_120 ;
if ( V_121 < args -> V_46 + args -> V_21 )
goto V_124;
args -> V_4 = F_59 ( V_121 , args -> V_46 + args -> V_41 )
- args -> V_46 ;
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_124;
ASSERT ( args -> V_46 + args -> V_4 <= V_121 ) ;
V_47 = F_57 ( args -> V_59 , args -> V_95 , args -> V_44 ,
args -> V_96 , V_125 ) ;
ASSERT ( args -> V_46 + args -> V_4 <=
F_10 ( F_19 ( args -> V_44 ) -> V_107 ) ) ;
error = F_20 ( V_47 , V_48 , V_49 , V_50 , args -> V_46 ,
args -> V_4 , V_62 ) ;
if ( error ) {
F_60 ( V_47 , V_126 ) ;
goto V_123;
}
F_60 ( V_48 , V_127 ) ;
F_60 ( V_47 , V_127 ) ;
args -> V_109 = 0 ;
F_61 ( args ) ;
return 0 ;
V_124:
F_60 ( V_48 , V_127 ) ;
args -> V_46 = V_36 ;
F_62 ( args ) ;
return 0 ;
V_123:
F_60 ( V_48 , V_126 ) ;
F_63 ( args ) ;
return error ;
}
STATIC int
F_64 (
struct V_128 * args ,
struct V_1 * * V_129 ,
struct V_1 * * V_130 ,
T_1 V_131 ,
T_1 * V_132 ,
T_2 * V_133 ,
T_1 * V_134 ,
T_2 * V_135 ,
int V_136 )
{
T_1 V_137 ;
T_1 V_138 ;
int error ;
int V_53 ;
if ( ! V_131 )
goto V_139;
do {
error = F_8 ( * V_130 , V_132 , V_133 , & V_53 ) ;
if ( error )
goto V_123;
F_58 ( args -> V_59 , V_53 == 1 , V_123 ) ;
F_11 ( args , * V_132 , * V_133 , V_134 , V_135 ) ;
if ( ! V_136 ) {
if ( * V_134 >= args -> V_46 + V_131 )
goto V_139;
} else {
if ( * V_134 <= args -> V_46 - V_131 )
goto V_139;
}
if ( * V_135 >= args -> V_21 ) {
args -> V_4 = F_15 ( * V_135 , args -> V_41 ) ;
F_17 ( args ) ;
V_138 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 ,
args -> V_26 , * V_134 ,
* V_135 , & V_137 ) ;
if ( V_138 < V_131 )
goto V_140;
goto V_139;
}
if ( ! V_136 )
error = F_65 ( * V_130 , 0 , & V_53 ) ;
else
error = F_66 ( * V_130 , 0 , & V_53 ) ;
if ( error )
goto V_123;
} while ( V_53 );
V_139:
F_60 ( * V_130 , V_127 ) ;
* V_130 = NULL ;
return 0 ;
V_140:
F_60 ( * V_129 , V_127 ) ;
* V_129 = NULL ;
return 0 ;
V_123:
return error ;
}
STATIC int
F_51 (
T_3 * args )
{
T_5 * V_141 ;
T_5 * V_142 ;
T_5 * V_47 ;
T_1 V_143 ;
T_1 V_144 ;
T_2 V_145 ;
T_2 V_146 ;
T_2 V_147 ;
T_1 V_148 ;
int error ;
int V_53 ;
int V_149 ;
T_1 V_150 ;
T_1 V_151 ;
T_2 V_152 ;
T_2 V_153 ;
T_2 V_154 ;
T_1 V_155 ;
T_2 V_38 ;
int V_156 = 0 ;
#ifdef F_21
int V_157 ;
V_157 = F_67 () & 1 ;
#endif
V_158:
V_142 = NULL ;
V_141 = NULL ;
V_153 = 0 ;
V_147 = 0 ;
V_154 = 0 ;
V_47 = F_57 ( args -> V_59 , args -> V_95 , args -> V_44 ,
args -> V_96 , V_125 ) ;
if ( ( error = F_3 ( V_47 , 0 , args -> V_41 , & V_53 ) ) )
goto V_123;
if ( ! V_53 ) {
if ( ( error = F_68 ( args , V_47 , & V_150 ,
& V_153 , & V_53 ) ) )
goto V_123;
if ( V_53 == 0 || V_153 == 0 ) {
F_60 ( V_47 , V_127 ) ;
F_69 ( args ) ;
return 0 ;
}
ASSERT ( V_53 == 1 ) ;
}
args -> V_109 = 0 ;
while ( F_70 ( V_47 , 0 ) ) {
T_2 V_159 ;
int V_160 = 0 ;
T_2 V_161 = 0 ;
T_1 V_162 = 0 ;
#ifdef F_21
if ( V_157 )
break;
#endif
if ( V_153 || args -> V_20 > 1 ) {
V_47 -> V_163 [ 0 ] = 1 ;
do {
if ( ( error = F_8 ( V_47 , & V_150 ,
& V_153 , & V_53 ) ) )
goto V_123;
F_58 ( args -> V_59 , V_53 == 1 , V_123 ) ;
if ( V_153 >= args -> V_21 )
break;
if ( ( error = F_65 ( V_47 , 0 , & V_53 ) ) )
goto V_123;
} while ( V_53 );
ASSERT ( V_153 >= args -> V_21 ) ;
if ( ! V_53 )
break;
}
V_53 = V_47 -> V_163 [ 0 ] ;
for ( V_149 = 1 , V_161 = 0 , V_159 = 0 ;
! error && V_149 && ( V_161 < args -> V_41 || V_159 > 0 ) ;
error = F_65 ( V_47 , 0 , & V_149 ) ) {
if ( ( error = F_8 ( V_47 , & V_150 , & V_153 , & V_53 ) ) )
goto V_123;
F_58 ( args -> V_59 , V_53 == 1 , V_123 ) ;
F_11 ( args , V_150 , V_153 ,
& V_151 , & V_154 ) ;
if ( V_154 < args -> V_21 )
continue;
args -> V_4 = F_15 ( V_154 , args -> V_41 ) ;
F_17 ( args ) ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
if ( args -> V_4 < V_161 )
continue;
V_152 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 , args -> V_26 , V_151 ,
V_154 , & V_155 ) ;
if ( V_155 != V_36 &&
( args -> V_4 > V_161 || V_152 < V_159 ) ) {
V_159 = V_152 ;
V_162 = V_155 ;
V_161 = args -> V_4 ;
V_160 = V_47 -> V_163 [ 0 ] ;
}
}
if ( V_161 == 0 )
break;
V_47 -> V_163 [ 0 ] = V_160 ;
if ( ( error = F_8 ( V_47 , & V_150 , & V_153 , & V_53 ) ) )
goto V_123;
F_58 ( args -> V_59 , V_53 == 1 , V_123 ) ;
ASSERT ( V_150 + V_153 <= F_10 ( F_19 ( args -> V_44 ) -> V_107 ) ) ;
args -> V_4 = V_161 ;
if ( ! F_18 ( args ) ) {
F_60 ( V_47 , V_127 ) ;
F_71 ( args ) ;
return 0 ;
}
V_161 = args -> V_4 ;
args -> V_46 = V_162 ;
ASSERT ( V_162 >= V_150 ) ;
ASSERT ( V_162 + V_161 <= V_150 + V_153 ) ;
V_142 = F_57 ( args -> V_59 , args -> V_95 ,
args -> V_44 , args -> V_96 , V_122 ) ;
if ( ( error = F_20 ( V_47 , V_142 , V_150 ,
V_153 , V_162 , V_161 , V_61 ) ) )
goto V_123;
F_60 ( V_47 , V_127 ) ;
F_60 ( V_142 , V_127 ) ;
F_72 ( args ) ;
return 0 ;
}
V_142 = F_57 ( args -> V_59 , args -> V_95 , args -> V_44 ,
args -> V_96 , V_122 ) ;
if ( ( error = F_4 ( V_142 , args -> V_46 , args -> V_41 , & V_53 ) ) )
goto V_123;
if ( ! V_53 ) {
V_141 = V_142 ;
V_142 = NULL ;
}
else if ( ( error = F_73 ( V_142 , & V_141 ) ) )
goto V_123;
if ( ( error = F_65 ( V_141 , 0 , & V_53 ) ) )
goto V_123;
if ( ! V_53 ) {
F_60 ( V_141 , V_127 ) ;
V_141 = NULL ;
}
do {
if ( V_142 ) {
if ( ( error = F_8 ( V_142 , & V_150 , & V_153 , & V_53 ) ) )
goto V_123;
F_58 ( args -> V_59 , V_53 == 1 , V_123 ) ;
F_11 ( args , V_150 , V_153 ,
& V_151 , & V_154 ) ;
if ( V_154 >= args -> V_21 )
break;
if ( ( error = F_66 ( V_142 , 0 , & V_53 ) ) )
goto V_123;
if ( ! V_53 ) {
F_60 ( V_142 ,
V_127 ) ;
V_142 = NULL ;
}
}
if ( V_141 ) {
if ( ( error = F_8 ( V_141 , & V_143 , & V_146 , & V_53 ) ) )
goto V_123;
F_58 ( args -> V_59 , V_53 == 1 , V_123 ) ;
F_11 ( args , V_143 , V_146 ,
& V_144 , & V_147 ) ;
if ( V_147 >= args -> V_21 )
break;
if ( ( error = F_65 ( V_141 , 0 , & V_53 ) ) )
goto V_123;
if ( ! V_53 ) {
F_60 ( V_141 ,
V_127 ) ;
V_141 = NULL ;
}
}
} while ( V_142 || V_141 );
if ( V_142 && V_141 ) {
if ( V_154 >= args -> V_21 ) {
args -> V_4 = F_15 ( V_154 , args -> V_41 ) ;
F_17 ( args ) ;
V_152 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 , args -> V_26 , V_151 ,
V_154 , & V_155 ) ;
error = F_64 ( args ,
& V_142 , & V_141 ,
V_152 , & V_143 , & V_146 ,
& V_144 , & V_147 ,
0 ) ;
} else {
ASSERT ( V_147 >= args -> V_21 ) ;
args -> V_4 = F_15 ( V_147 , args -> V_41 ) ;
F_17 ( args ) ;
V_145 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 , args -> V_26 , V_144 ,
V_147 , & V_148 ) ;
error = F_64 ( args ,
& V_141 , & V_142 ,
V_145 , & V_150 , & V_153 ,
& V_151 , & V_154 ,
1 ) ;
}
if ( error )
goto V_123;
}
if ( V_142 == NULL && V_141 == NULL ) {
F_60 ( V_47 , V_127 ) ;
if ( ! V_156 ++ ) {
F_74 ( args ) ;
F_75 ( args -> V_59 , V_164 ) ;
goto V_158;
}
F_76 ( args ) ;
args -> V_46 = V_36 ;
return 0 ;
}
if ( V_141 ) {
V_142 = V_141 ;
V_141 = NULL ;
V_150 = V_143 ;
V_151 = V_144 ;
V_153 = V_146 ;
V_154 = V_147 ;
V_149 = 1 ;
} else
V_149 = 0 ;
args -> V_4 = F_15 ( V_154 , args -> V_41 ) ;
F_17 ( args ) ;
if ( ! F_18 ( args ) ) {
F_71 ( args ) ;
F_60 ( V_142 , V_127 ) ;
F_60 ( V_47 , V_127 ) ;
return 0 ;
}
V_38 = args -> V_4 ;
( void ) F_14 ( args -> V_46 , V_38 , args -> V_20 ,
args -> V_26 , V_151 , V_154 , & V_155 ) ;
ASSERT ( V_155 >= V_150 ) ;
ASSERT ( V_155 + V_38 <= V_151 + V_154 ) ;
ASSERT ( V_155 + V_38 <= F_10 ( F_19 ( args -> V_44 ) -> V_107 ) ) ;
args -> V_46 = V_155 ;
if ( ( error = F_20 ( V_47 , V_142 , V_150 , V_153 ,
V_155 , V_38 , V_62 ) ) )
goto V_123;
if ( V_149 )
F_77 ( args ) ;
else
F_78 ( args ) ;
F_60 ( V_47 , V_127 ) ;
F_60 ( V_142 , V_127 ) ;
return 0 ;
V_123:
F_79 ( args ) ;
if ( V_47 != NULL )
F_60 ( V_47 , V_126 ) ;
if ( V_142 != NULL )
F_60 ( V_142 , V_126 ) ;
if ( V_141 != NULL )
F_60 ( V_141 , V_126 ) ;
return error ;
}
STATIC int
F_50 (
T_3 * args )
{
T_5 * V_48 ;
T_5 * V_47 ;
int error ;
T_1 V_49 ;
T_2 V_50 ;
int V_53 ;
T_1 V_51 ;
T_2 V_38 ;
int V_156 = 0 ;
V_158:
V_47 = F_57 ( args -> V_59 , args -> V_95 , args -> V_44 ,
args -> V_96 , V_125 ) ;
V_48 = NULL ;
if ( ( error = F_3 ( V_47 , 0 ,
args -> V_41 + args -> V_20 - 1 , & V_53 ) ) )
goto V_123;
if ( ! V_53 || V_156 > 1 ) {
error = F_68 ( args , V_47 ,
& V_49 , & V_50 , & V_53 ) ;
if ( error )
goto V_123;
if ( V_53 == 0 || V_50 == 0 ) {
F_60 ( V_47 , V_127 ) ;
F_80 ( args ) ;
return 0 ;
}
ASSERT ( V_53 == 1 ) ;
F_11 ( args , V_49 , V_50 , & V_51 , & V_38 ) ;
} else {
for (; ; ) {
error = F_8 ( V_47 , & V_49 , & V_50 , & V_53 ) ;
if ( error )
goto V_123;
F_58 ( args -> V_59 , V_53 == 1 , V_123 ) ;
F_11 ( args , V_49 , V_50 ,
& V_51 , & V_38 ) ;
if ( V_38 >= args -> V_41 )
break;
error = F_65 ( V_47 , 0 , & V_53 ) ;
if ( error )
goto V_123;
if ( V_53 == 0 ) {
F_60 ( V_47 ,
V_127 ) ;
F_81 ( args ) ;
if ( ! V_156 ++ )
F_75 ( args -> V_59 , V_164 ) ;
goto V_158;
}
}
}
V_38 = F_15 ( args -> V_41 , V_38 ) ;
F_58 ( args -> V_59 , V_38 == 0 ||
( V_38 <= V_50 && V_51 + V_38 <= V_49 + V_50 ) , V_123 ) ;
if ( V_38 < args -> V_41 ) {
T_1 V_165 ;
T_2 V_166 ;
T_1 V_167 ;
T_2 V_168 ;
V_168 = V_38 ;
V_167 = V_51 ;
V_166 = V_50 ;
V_165 = V_49 ;
for (; ; ) {
if ( ( error = F_66 ( V_47 , 0 , & V_53 ) ) )
goto V_123;
if ( V_53 == 0 )
break;
if ( ( error = F_8 ( V_47 , & V_49 , & V_50 ,
& V_53 ) ) )
goto V_123;
F_58 ( args -> V_59 , V_53 == 1 , V_123 ) ;
if ( V_50 < V_168 )
break;
F_11 ( args , V_49 , V_50 ,
& V_51 , & V_38 ) ;
V_38 = F_15 ( args -> V_41 , V_38 ) ;
F_58 ( args -> V_59 , V_38 == 0 ||
( V_38 <= V_50 && V_51 + V_38 <= V_49 + V_50 ) ,
V_123 ) ;
if ( V_38 > V_168 ) {
V_168 = V_38 ;
V_167 = V_51 ;
V_166 = V_50 ;
V_165 = V_49 ;
if ( V_38 == args -> V_41 )
break;
}
}
if ( ( error = F_1 ( V_47 , V_165 , V_166 ,
& V_53 ) ) )
goto V_123;
F_58 ( args -> V_59 , V_53 == 1 , V_123 ) ;
V_38 = V_168 ;
V_51 = V_167 ;
V_50 = V_166 ;
V_49 = V_165 ;
}
args -> V_109 = 0 ;
args -> V_4 = V_38 ;
if ( V_38 < args -> V_21 ) {
if ( ! V_156 ++ ) {
F_60 ( V_47 , V_127 ) ;
F_81 ( args ) ;
F_75 ( args -> V_59 , V_164 ) ;
goto V_158;
}
goto V_169;
}
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_169;
V_38 = args -> V_4 ;
F_58 ( args -> V_59 , V_38 <= V_50 , V_123 ) ;
V_48 = F_57 ( args -> V_59 , args -> V_95 , args -> V_44 ,
args -> V_96 , V_122 ) ;
if ( ( error = F_20 ( V_47 , V_48 , V_49 , V_50 ,
V_51 , V_38 , V_61 ) ) )
goto V_123;
F_60 ( V_47 , V_127 ) ;
F_60 ( V_48 , V_127 ) ;
V_47 = V_48 = NULL ;
args -> V_4 = V_38 ;
args -> V_46 = V_51 ;
F_58 ( args -> V_59 ,
args -> V_46 + args -> V_4 <=
F_10 ( F_19 ( args -> V_44 ) -> V_107 ) ,
V_123 ) ;
F_82 ( args ) ;
return 0 ;
V_123:
F_83 ( args ) ;
if ( V_47 )
F_60 ( V_47 , V_126 ) ;
if ( V_48 )
F_60 ( V_48 , V_126 ) ;
return error ;
V_169:
F_60 ( V_47 , V_127 ) ;
F_84 ( args ) ;
args -> V_46 = V_36 ;
return 0 ;
}
STATIC int
F_68 (
T_3 * args ,
T_5 * V_170 ,
T_1 * V_171 ,
T_2 * V_172 ,
int * V_5 )
{
int error ;
T_1 V_49 ;
T_2 V_50 ;
int V_53 ;
if ( ( error = F_66 ( V_170 , 0 , & V_53 ) ) )
goto V_123;
if ( V_53 ) {
if ( ( error = F_8 ( V_170 , & V_49 , & V_50 , & V_53 ) ) )
goto V_123;
F_58 ( args -> V_59 , V_53 == 1 , V_123 ) ;
}
else if ( args -> V_21 == 1 && args -> V_20 == 1 && ! args -> V_113 &&
( F_10 ( F_19 ( args -> V_44 ) -> V_173 )
> args -> V_43 ) ) {
error = F_85 ( args -> V_95 , args -> V_44 , & V_49 , 0 ) ;
if ( error )
goto V_123;
if ( V_49 != V_36 ) {
F_86 ( args -> V_59 , args -> V_96 , V_49 , 1 ,
args -> V_26 ) ;
if ( args -> V_26 ) {
T_9 * V_70 ;
V_70 = F_87 ( args -> V_59 , args -> V_95 ,
args -> V_96 , V_49 , 0 ) ;
F_88 ( args -> V_95 , V_70 ) ;
}
args -> V_4 = 1 ;
args -> V_46 = V_49 ;
F_58 ( args -> V_59 ,
args -> V_46 + args -> V_4 <=
F_10 ( F_19 ( args -> V_44 ) -> V_107 ) ,
V_123 ) ;
args -> V_109 = 1 ;
F_89 ( args ) ;
* V_5 = 0 ;
return 0 ;
}
else
V_50 = 0 ;
}
else {
V_49 = V_36 ;
V_50 = 0 ;
}
if ( V_50 < args -> V_21 ) {
args -> V_46 = V_36 ;
F_90 ( args ) ;
V_50 = 0 ;
}
* V_171 = V_49 ;
* V_172 = V_50 ;
* V_5 = 1 ;
F_91 ( args ) ;
return 0 ;
V_123:
F_92 ( args ) ;
return error ;
}
STATIC int
F_93 (
T_7 * V_95 ,
T_9 * V_44 ,
T_8 V_96 ,
T_1 V_3 ,
T_2 V_4 ,
int V_113 )
{
T_5 * V_48 ;
T_5 * V_47 ;
int error ;
T_1 V_143 ;
T_2 V_146 ;
int V_174 ;
int V_175 ;
int V_53 ;
T_1 V_150 ;
T_2 V_153 ;
T_6 * V_59 ;
T_1 V_176 ;
T_2 V_177 ;
T_10 * V_104 ;
V_59 = V_95 -> V_178 ;
V_48 = F_57 ( V_59 , V_95 , V_44 , V_96 , V_122 ) ;
V_47 = NULL ;
if ( ( error = F_4 ( V_48 , V_3 , V_4 , & V_174 ) ) )
goto V_123;
if ( V_174 ) {
if ( ( error = F_8 ( V_48 , & V_150 , & V_153 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
if ( V_150 + V_153 < V_3 )
V_174 = 0 ;
else {
F_58 ( V_59 ,
V_150 + V_153 <= V_3 , V_123 ) ;
}
}
if ( ( error = F_65 ( V_48 , 0 , & V_175 ) ) )
goto V_123;
if ( V_175 ) {
if ( ( error = F_8 ( V_48 , & V_143 , & V_146 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
if ( V_3 + V_4 < V_143 )
V_175 = 0 ;
else {
F_58 ( V_59 , V_143 >= V_3 + V_4 , V_123 ) ;
}
}
V_47 = F_57 ( V_59 , V_95 , V_44 , V_96 , V_125 ) ;
if ( V_174 && V_175 ) {
if ( ( error = F_1 ( V_47 , V_150 , V_153 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
if ( ( error = F_1 ( V_47 , V_143 , V_146 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
if ( ( error = F_24 ( V_48 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
if ( ( error = F_66 ( V_48 , 0 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
#ifdef F_21
{
T_1 V_179 ;
T_2 V_180 ;
if ( ( error = F_8 ( V_48 , & V_179 , & V_180 ,
& V_53 ) ) )
goto V_123;
F_58 ( V_59 ,
V_53 == 1 && V_179 == V_150 && V_180 == V_153 ,
V_123 ) ;
}
#endif
V_176 = V_150 ;
V_177 = V_4 + V_153 + V_146 ;
if ( ( error = F_5 ( V_48 , V_176 , V_177 ) ) )
goto V_123;
}
else if ( V_174 ) {
if ( ( error = F_1 ( V_47 , V_150 , V_153 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
if ( ( error = F_66 ( V_48 , 0 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
V_176 = V_150 ;
V_177 = V_4 + V_153 ;
if ( ( error = F_5 ( V_48 , V_176 , V_177 ) ) )
goto V_123;
}
else if ( V_175 ) {
if ( ( error = F_1 ( V_47 , V_143 , V_146 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
V_176 = V_3 ;
V_177 = V_4 + V_146 ;
if ( ( error = F_5 ( V_48 , V_176 , V_177 ) ) )
goto V_123;
}
else {
V_176 = V_3 ;
V_177 = V_4 ;
if ( ( error = F_25 ( V_48 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
}
F_60 ( V_48 , V_127 ) ;
V_48 = NULL ;
if ( ( error = F_1 ( V_47 , V_176 , V_177 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 0 , V_123 ) ;
if ( ( error = F_25 ( V_47 , & V_53 ) ) )
goto V_123;
F_58 ( V_59 , V_53 == 1 , V_123 ) ;
F_60 ( V_47 , V_127 ) ;
V_47 = NULL ;
V_104 = F_94 ( V_59 , V_96 ) ;
error = F_44 ( V_95 , V_104 , V_44 , V_4 ) ;
F_95 ( V_104 ) ;
if ( error )
goto V_123;
if ( ! V_113 )
F_54 ( V_95 , V_116 , ( long ) V_4 ) ;
F_55 ( V_181 ) ;
F_56 ( V_182 , V_4 ) ;
F_96 ( V_59 , V_96 , V_3 , V_4 , V_113 , V_174 , V_175 ) ;
return 0 ;
V_123:
F_96 ( V_59 , V_96 , V_3 , V_4 , V_113 , - 1 , - 1 ) ;
if ( V_48 )
F_60 ( V_48 , V_126 ) ;
if ( V_47 )
F_60 ( V_47 , V_126 ) ;
return error ;
}
void
F_97 (
T_6 * V_59 )
{
int V_183 ;
T_11 V_184 ;
T_11 V_185 ;
int V_186 ;
int V_187 ;
V_185 = ( V_59 -> V_76 . V_84 + 1 ) / 2 ;
V_186 = V_59 -> V_188 [ 0 ] ;
V_187 = V_59 -> V_188 [ 1 ] ;
V_184 = ( V_185 + V_186 - 1 ) / V_186 ;
for ( V_183 = 1 ; V_184 > 1 ; V_183 ++ )
V_184 = ( V_184 + V_187 - 1 ) / V_187 ;
V_59 -> V_189 = V_183 ;
}
T_2
F_98 (
struct V_58 * V_59 ,
struct V_103 * V_104 )
{
T_2 V_190 , V_191 = 0 ;
V_190 = F_99 ( V_104 , V_59 ) ;
if ( V_190 > V_104 -> V_192 )
V_191 = V_190 - V_104 -> V_192 ;
if ( V_104 -> V_193 > V_191 )
return V_104 -> V_193 - V_191 ;
return V_104 -> V_192 > 0 || V_104 -> V_193 > 0 ;
}
STATIC int
F_100 (
T_3 * args ,
int V_52 )
{
T_9 * V_44 ;
T_4 * V_42 ;
T_9 * V_194 ;
T_1 V_3 ;
T_2 V_191 ;
int error ;
T_2 V_195 ;
T_6 * V_59 ;
T_2 V_190 ;
T_10 * V_104 ;
T_3 V_196 ;
T_7 * V_95 ;
V_59 = args -> V_59 ;
V_104 = args -> V_104 ;
V_95 = args -> V_95 ;
if ( ! V_104 -> V_197 ) {
if ( ( error = F_101 ( V_59 , V_95 , args -> V_96 , V_52 ,
& V_44 ) ) )
return error ;
if ( ! V_104 -> V_197 ) {
ASSERT ( V_52 & V_198 ) ;
ASSERT ( ! ( V_52 & V_199 ) ) ;
args -> V_44 = NULL ;
return 0 ;
}
} else
V_44 = NULL ;
if ( V_104 -> V_200 && args -> V_26 &&
( V_52 & V_198 ) ) {
ASSERT ( ! ( V_52 & V_199 ) ) ;
args -> V_44 = NULL ;
return 0 ;
}
if ( ! ( V_52 & V_199 ) ) {
V_190 = F_99 ( V_104 , V_59 ) ;
V_195 = F_98 ( V_59 , V_104 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_201 - 1 ) >
V_195 ||
( ( int ) ( V_104 -> V_106 + V_104 -> V_192 -
V_190 - args -> V_202 ) < ( int ) args -> V_43 ) ) {
if ( V_44 )
F_102 ( V_95 , V_44 ) ;
args -> V_44 = NULL ;
return 0 ;
}
}
if ( V_44 == NULL ) {
if ( ( error = F_101 ( V_59 , V_95 , args -> V_96 , V_52 ,
& V_44 ) ) )
return error ;
if ( V_44 == NULL ) {
ASSERT ( V_52 & V_198 ) ;
ASSERT ( ! ( V_52 & V_199 ) ) ;
args -> V_44 = NULL ;
return 0 ;
}
}
V_42 = F_19 ( V_44 ) ;
V_190 = F_103 ( V_42 , V_59 ) ;
if ( ! ( V_52 & V_199 ) ) {
V_191 = V_190 > F_10 ( V_42 -> V_173 ) ?
( V_190 - F_10 ( V_42 -> V_173 ) ) : 0 ;
V_195 = F_10 ( V_42 -> V_203 ) ;
V_195 = ( V_195 > V_191 ) ? ( V_195 - V_191 ) :
( F_10 ( V_42 -> V_173 ) > 0 || V_195 > 0 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_201 - 1 ) >
V_195 ||
( ( int ) ( F_10 ( V_42 -> V_45 ) +
F_10 ( V_42 -> V_173 ) - V_190 - args -> V_202 ) <
( int ) args -> V_43 ) ) {
F_102 ( V_95 , V_44 ) ;
args -> V_44 = NULL ;
return 0 ;
}
}
while ( F_10 ( V_42 -> V_173 ) > V_190 ) {
T_9 * V_70 ;
error = F_85 ( V_95 , V_44 , & V_3 , 0 ) ;
if ( error )
return error ;
if ( ( error = F_93 ( V_95 , V_44 , args -> V_96 , V_3 , 1 , 1 ) ) )
return error ;
V_70 = F_87 ( V_59 , V_95 , args -> V_96 , V_3 , 0 ) ;
F_88 ( V_95 , V_70 ) ;
}
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
V_196 . V_95 = V_95 ;
V_196 . V_59 = V_59 ;
V_196 . V_44 = V_44 ;
V_196 . V_96 = args -> V_96 ;
V_196 . V_20 = V_196 . V_21 = V_196 . V_40 = V_196 . V_113 = 1 ;
V_196 . type = V_110 ;
V_196 . V_104 = V_104 ;
if ( ( error = F_38 ( V_59 , V_95 , V_196 . V_96 , & V_194 ) ) )
return error ;
while ( F_10 ( V_42 -> V_173 ) < V_190 ) {
V_196 . V_46 = 0 ;
V_196 . V_41 = V_190 - F_10 ( V_42 -> V_173 ) ;
if ( ( error = F_49 ( & V_196 ) ) ) {
F_102 ( V_95 , V_194 ) ;
return error ;
}
if ( V_196 . V_46 == V_36 ) {
if ( V_52 & V_199 )
break;
F_102 ( V_95 , V_194 ) ;
args -> V_44 = NULL ;
return 0 ;
}
for ( V_3 = V_196 . V_46 ; V_3 < V_196 . V_46 + V_196 . V_4 ; V_3 ++ ) {
error = F_104 ( V_95 , V_44 ,
V_194 , V_3 , 0 ) ;
if ( error )
return error ;
}
}
F_102 ( V_95 , V_194 ) ;
args -> V_44 = V_44 ;
return 0 ;
}
int
F_85 (
T_7 * V_95 ,
T_9 * V_44 ,
T_1 * V_204 ,
int V_205 )
{
T_4 * V_42 ;
T_9 * V_194 ;
T_1 V_3 ;
T_12 * V_83 ;
int error ;
int V_206 ;
T_6 * V_59 = V_95 -> V_178 ;
T_10 * V_104 ;
V_42 = F_19 ( V_44 ) ;
if ( ! V_42 -> V_173 ) {
* V_204 = V_36 ;
return 0 ;
}
error = F_38 ( V_59 , V_95 , F_10 ( V_42 -> V_207 ) ,
& V_194 ) ;
if ( error )
return error ;
V_83 = F_105 ( V_59 , V_194 ) ;
V_3 = F_10 ( V_83 [ F_10 ( V_42 -> V_208 ) ] ) ;
F_45 ( & V_42 -> V_208 , 1 ) ;
F_102 ( V_95 , V_194 ) ;
if ( F_10 ( V_42 -> V_208 ) == F_29 ( V_59 ) )
V_42 -> V_208 = 0 ;
V_104 = F_94 ( V_59 , F_10 ( V_42 -> V_207 ) ) ;
F_45 ( & V_42 -> V_173 , - 1 ) ;
F_106 ( V_95 , - 1 ) ;
V_104 -> V_192 -- ;
F_95 ( V_104 ) ;
V_206 = V_209 | V_210 ;
if ( V_205 ) {
F_45 ( & V_42 -> V_211 , 1 ) ;
V_104 -> V_212 ++ ;
V_206 |= V_213 ;
}
F_48 ( V_95 , V_44 , V_206 ) ;
* V_204 = V_3 ;
return 0 ;
}
void
F_48 (
T_7 * V_95 ,
T_9 * V_70 ,
int V_214 )
{
int V_215 ;
int V_216 ;
static const short V_217 [] = {
F_107 ( T_4 , V_218 ) ,
F_107 ( T_4 , V_219 ) ,
F_107 ( T_4 , V_207 ) ,
F_107 ( T_4 , V_107 ) ,
F_107 ( T_4 , V_220 [ 0 ] ) ,
F_107 ( T_4 , V_221 [ 0 ] ) ,
F_107 ( T_4 , V_208 ) ,
F_107 ( T_4 , V_222 ) ,
F_107 ( T_4 , V_173 ) ,
F_107 ( T_4 , V_45 ) ,
F_107 ( T_4 , V_203 ) ,
F_107 ( T_4 , V_211 ) ,
F_107 ( T_4 , V_223 ) ,
sizeof( T_4 )
} ;
F_108 ( V_95 -> V_178 , F_19 ( V_70 ) , V_214 , V_224 ) ;
F_109 ( V_95 , V_70 , V_225 ) ;
F_110 ( V_214 , V_217 , V_226 , & V_215 , & V_216 ) ;
F_111 ( V_95 , V_70 , ( T_11 ) V_215 , ( T_11 ) V_216 ) ;
}
int
F_112 (
T_6 * V_59 ,
T_7 * V_95 ,
T_8 V_96 ,
int V_52 )
{
T_9 * V_70 ;
int error ;
if ( ( error = F_101 ( V_59 , V_95 , V_96 , V_52 , & V_70 ) ) )
return error ;
if ( V_70 )
F_102 ( V_95 , V_70 ) ;
return 0 ;
}
int
F_104 (
T_7 * V_95 ,
T_9 * V_44 ,
T_9 * V_194 ,
T_1 V_3 ,
int V_205 )
{
T_4 * V_42 ;
T_12 * V_227 ;
int error ;
int V_206 ;
T_6 * V_59 ;
T_10 * V_104 ;
T_12 * V_83 ;
int V_228 ;
V_42 = F_19 ( V_44 ) ;
V_59 = V_95 -> V_178 ;
if ( ! V_194 && ( error = F_38 ( V_59 , V_95 ,
F_10 ( V_42 -> V_207 ) , & V_194 ) ) )
return error ;
F_45 ( & V_42 -> V_222 , 1 ) ;
if ( F_10 ( V_42 -> V_222 ) == F_29 ( V_59 ) )
V_42 -> V_222 = 0 ;
V_104 = F_94 ( V_59 , F_10 ( V_42 -> V_207 ) ) ;
F_45 ( & V_42 -> V_173 , 1 ) ;
F_106 ( V_95 , 1 ) ;
V_104 -> V_192 ++ ;
V_206 = V_229 | V_210 ;
if ( V_205 ) {
F_45 ( & V_42 -> V_211 , - 1 ) ;
V_104 -> V_212 -- ;
V_206 |= V_213 ;
}
F_95 ( V_104 ) ;
F_48 ( V_95 , V_44 , V_206 ) ;
ASSERT ( F_10 ( V_42 -> V_173 ) <= F_29 ( V_59 ) ) ;
V_83 = F_105 ( V_59 , V_194 ) ;
V_227 = & V_83 [ F_10 ( V_42 -> V_222 ) ] ;
* V_227 = F_6 ( V_3 ) ;
V_228 = ( char * ) V_227 - ( char * ) V_194 -> V_230 ;
F_48 ( V_95 , V_44 , V_206 ) ;
F_109 ( V_95 , V_194 , V_231 ) ;
F_111 ( V_95 , V_194 , V_228 ,
V_228 + sizeof( T_1 ) - 1 ) ;
return 0 ;
}
static bool
F_113 (
struct V_58 * V_59 ,
struct V_69 * V_70 )
{
struct V_105 * V_42 = F_19 ( V_70 ) ;
if ( F_31 ( & V_59 -> V_76 ) &&
! F_28 ( & V_42 -> V_223 , & V_59 -> V_76 . V_77 ) )
return false ;
if ( ! ( V_42 -> V_218 == F_6 ( V_232 ) &&
F_114 ( F_10 ( V_42 -> V_219 ) ) &&
F_10 ( V_42 -> V_45 ) <= F_10 ( V_42 -> V_107 ) &&
F_10 ( V_42 -> V_208 ) < F_29 ( V_59 ) &&
F_10 ( V_42 -> V_222 ) < F_29 ( V_59 ) &&
F_10 ( V_42 -> V_173 ) <= F_29 ( V_59 ) ) )
return false ;
if ( F_10 ( V_42 -> V_221 [ V_122 ] ) > V_233 ||
F_10 ( V_42 -> V_221 [ V_125 ] ) > V_233 )
return false ;
if ( V_70 -> V_80 && F_10 ( V_42 -> V_207 ) != V_70 -> V_80 -> V_82 )
return false ;
if ( F_115 ( & V_59 -> V_76 ) &&
F_10 ( V_42 -> V_211 ) > F_10 ( V_42 -> V_107 ) )
return false ;
return true ; ;
}
static void
F_116 (
struct V_69 * V_70 )
{
struct V_58 * V_59 = V_70 -> V_71 -> V_72 ;
if ( F_31 ( & V_59 -> V_76 ) &&
! F_32 ( V_70 , V_234 ) )
F_33 ( V_70 , - V_86 ) ;
else if ( F_117 ( ! F_113 ( V_59 , V_70 ) , V_59 ,
V_235 ,
V_236 ) )
F_33 ( V_70 , - V_87 ) ;
if ( V_70 -> V_88 )
F_34 ( V_70 ) ;
}
static void
F_118 (
struct V_69 * V_70 )
{
struct V_58 * V_59 = V_70 -> V_71 -> V_72 ;
struct V_89 * V_90 = V_70 -> V_91 ;
if ( ! F_113 ( V_59 , V_70 ) ) {
F_33 ( V_70 , - V_87 ) ;
F_34 ( V_70 ) ;
return;
}
if ( ! F_31 ( & V_59 -> V_76 ) )
return;
if ( V_90 )
F_19 ( V_70 ) -> V_237 = F_36 ( V_90 -> V_93 . V_94 ) ;
F_37 ( V_70 , V_234 ) ;
}
int
F_119 (
struct V_58 * V_59 ,
struct V_102 * V_95 ,
T_8 V_96 ,
int V_52 ,
struct V_69 * * V_97 )
{
int error ;
F_120 ( V_59 , V_96 ) ;
ASSERT ( V_96 != V_98 ) ;
error = F_39 (
V_59 , V_95 , V_59 -> V_99 ,
F_40 ( V_59 , V_96 , F_121 ( V_59 ) ) ,
F_42 ( V_59 , 1 ) , V_52 , V_97 , & V_238 ) ;
if ( error )
return error ;
if ( ! * V_97 )
return 0 ;
ASSERT ( ! ( * V_97 ) -> V_88 ) ;
F_43 ( * V_97 , V_239 ) ;
return 0 ;
}
int
F_101 (
struct V_58 * V_59 ,
struct V_102 * V_95 ,
T_8 V_96 ,
int V_52 ,
struct V_69 * * V_97 )
{
struct V_105 * V_42 ;
struct V_103 * V_104 ;
int error ;
F_122 ( V_59 , V_96 ) ;
ASSERT ( V_96 != V_98 ) ;
error = F_119 ( V_59 , V_95 , V_96 ,
( V_52 & V_198 ) ? V_240 : 0 ,
V_97 ) ;
if ( error )
return error ;
if ( ! * V_97 )
return 0 ;
ASSERT ( ! ( * V_97 ) -> V_88 ) ;
V_42 = F_19 ( * V_97 ) ;
V_104 = F_94 ( V_59 , V_96 ) ;
if ( ! V_104 -> V_197 ) {
V_104 -> V_106 = F_10 ( V_42 -> V_45 ) ;
V_104 -> V_212 = F_10 ( V_42 -> V_211 ) ;
V_104 -> V_192 = F_10 ( V_42 -> V_173 ) ;
V_104 -> V_193 = F_10 ( V_42 -> V_203 ) ;
V_104 -> V_241 [ V_242 ] =
F_10 ( V_42 -> V_221 [ V_242 ] ) ;
V_104 -> V_241 [ V_243 ] =
F_10 ( V_42 -> V_221 [ V_243 ] ) ;
F_123 ( & V_104 -> V_244 ) ;
V_104 -> V_245 = 0 ;
V_104 -> V_246 = V_247 ;
V_104 -> V_197 = 1 ;
}
#ifdef F_21
else if ( ! F_124 ( V_59 ) ) {
ASSERT ( V_104 -> V_106 == F_10 ( V_42 -> V_45 ) ) ;
ASSERT ( V_104 -> V_212 == F_10 ( V_42 -> V_211 ) ) ;
ASSERT ( V_104 -> V_192 == F_10 ( V_42 -> V_173 ) ) ;
ASSERT ( V_104 -> V_193 == F_10 ( V_42 -> V_203 ) ) ;
ASSERT ( V_104 -> V_241 [ V_242 ] ==
F_10 ( V_42 -> V_221 [ V_242 ] ) ) ;
ASSERT ( V_104 -> V_241 [ V_243 ] ==
F_10 ( V_42 -> V_221 [ V_243 ] ) ) ;
}
#endif
F_95 ( V_104 ) ;
return 0 ;
}
int
F_125 (
T_3 * args )
{
T_1 V_248 ;
int error ;
int V_52 ;
T_2 V_43 ;
T_6 * V_59 ;
T_8 V_249 ;
T_13 type ;
int V_250 = 0 ;
int V_251 = 0 ;
T_8 V_252 = V_253 ;
V_59 = args -> V_59 ;
type = args -> V_254 = args -> type ;
args -> V_46 = V_36 ;
V_248 = V_59 -> V_76 . V_84 ;
if ( args -> V_41 > V_248 )
args -> V_41 = V_248 ;
if ( args -> V_20 == 0 )
args -> V_20 = 1 ;
ASSERT ( F_126 ( V_59 , args -> V_255 ) < V_59 -> V_76 . V_256 ) ;
ASSERT ( F_127 ( V_59 , args -> V_255 ) < V_248 ) ;
ASSERT ( args -> V_21 <= args -> V_41 ) ;
ASSERT ( args -> V_21 <= V_248 ) ;
ASSERT ( args -> V_39 < args -> V_40 ) ;
if ( F_126 ( V_59 , args -> V_255 ) >= V_59 -> V_76 . V_256 ||
F_127 ( V_59 , args -> V_255 ) >= V_248 ||
args -> V_21 > args -> V_41 || args -> V_21 > V_248 ||
args -> V_39 >= args -> V_40 ) {
args -> V_255 = V_257 ;
F_128 ( args ) ;
return 0 ;
}
V_43 = args -> V_43 ;
switch ( type ) {
case V_110 :
case V_111 :
case V_112 :
args -> V_96 = F_126 ( V_59 , args -> V_255 ) ;
args -> V_104 = F_94 ( V_59 , args -> V_96 ) ;
args -> V_43 = 0 ;
error = F_100 ( args , 0 ) ;
args -> V_43 = V_43 ;
if ( error ) {
F_129 ( args ) ;
goto V_123;
}
if ( ! args -> V_44 ) {
F_130 ( args ) ;
break;
}
args -> V_46 = F_127 ( V_59 , args -> V_255 ) ;
if ( ( error = F_49 ( args ) ) )
goto V_123;
break;
case V_258 :
if ( ( args -> V_26 == V_259 ) &&
( V_59 -> V_260 & V_261 ) ) {
args -> V_255 = F_131 ( V_59 ,
( ( V_59 -> V_262 / V_252 ) %
V_59 -> V_76 . V_256 ) , 0 ) ;
V_250 = 1 ;
}
args -> V_46 = F_127 ( V_59 , args -> V_255 ) ;
args -> type = V_111 ;
case V_263 :
case V_264 :
case V_265 :
if ( type == V_263 ) {
args -> V_96 = V_249 = ( V_59 -> V_262 / V_252 ) %
V_59 -> V_76 . V_256 ;
args -> type = V_110 ;
V_52 = V_198 ;
} else if ( type == V_265 ) {
args -> V_96 = F_126 ( V_59 , args -> V_255 ) ;
args -> type = V_110 ;
V_249 = 0 ;
V_52 = 0 ;
} else {
if ( type == V_264 )
args -> type = V_110 ;
args -> V_96 = V_249 = F_126 ( V_59 , args -> V_255 ) ;
V_52 = V_198 ;
}
for (; ; ) {
args -> V_104 = F_94 ( V_59 , args -> V_96 ) ;
if ( V_251 ) args -> V_43 = 0 ;
error = F_100 ( args , V_52 ) ;
args -> V_43 = V_43 ;
if ( error ) {
F_129 ( args ) ;
goto V_123;
}
if ( args -> V_44 ) {
if ( ( error = F_49 ( args ) ) )
goto V_123;
break;
}
F_132 ( args ) ;
if ( args -> V_96 == V_249 &&
type == V_258 )
args -> type = V_110 ;
if ( ++ ( args -> V_96 ) == V_59 -> V_76 . V_256 ) {
if ( args -> V_266 != V_257 )
args -> V_96 = V_249 ;
else
args -> V_96 = 0 ;
}
if ( args -> V_96 == V_249 ) {
if ( V_251 == 1 ) {
args -> V_46 = V_36 ;
F_133 ( args ) ;
break;
}
if ( V_52 == 0 ) {
V_251 = 1 ;
} else {
V_52 = 0 ;
if ( type == V_258 ) {
args -> V_46 = F_127 ( V_59 ,
args -> V_255 ) ;
args -> type = V_111 ;
}
}
}
F_95 ( args -> V_104 ) ;
}
if ( V_250 || ( type == V_263 ) ) {
if ( args -> V_96 == V_249 )
V_59 -> V_262 = ( V_59 -> V_262 + 1 ) %
( V_59 -> V_76 . V_256 * V_252 ) ;
else
V_59 -> V_262 = ( args -> V_96 * V_252 + 1 ) %
( V_59 -> V_76 . V_256 * V_252 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_46 == V_36 )
args -> V_255 = V_257 ;
else {
args -> V_255 = F_131 ( V_59 , args -> V_96 , args -> V_46 ) ;
#ifdef F_21
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_41 ) ;
ASSERT ( args -> V_46 % args -> V_20 == 0 ) ;
F_134 ( V_59 , F_135 ( V_59 , args -> V_255 ) ,
args -> V_4 ) ;
#endif
}
F_95 ( args -> V_104 ) ;
return 0 ;
V_123:
F_95 ( args -> V_104 ) ;
return error ;
}
int
F_136 (
T_7 * V_95 ,
T_14 V_3 ,
T_2 V_4 )
{
T_3 args ;
int error ;
ASSERT ( V_4 != 0 ) ;
memset ( & args , 0 , sizeof( T_3 ) ) ;
args . V_95 = V_95 ;
args . V_59 = V_95 -> V_178 ;
args . V_96 = F_126 ( args . V_59 , V_3 ) ;
if ( args . V_96 >= args . V_59 -> V_76 . V_256 )
return - V_87 ;
args . V_46 = F_127 ( args . V_59 , V_3 ) ;
if ( args . V_46 >= args . V_59 -> V_76 . V_84 )
return - V_87 ;
args . V_104 = F_94 ( args . V_59 , args . V_96 ) ;
ASSERT ( args . V_104 ) ;
error = F_100 ( & args , V_199 ) ;
if ( error )
goto V_123;
if ( args . V_46 + V_4 >
F_10 ( F_19 ( args . V_44 ) -> V_107 ) ) {
error = - V_87 ;
goto V_123;
}
error = F_93 ( V_95 , args . V_44 , args . V_96 , args . V_46 , V_4 , 0 ) ;
if ( ! error )
F_137 ( V_95 , args . V_96 , args . V_46 , V_4 , 0 ) ;
V_123:
F_95 ( args . V_104 ) ;
return error ;
}
