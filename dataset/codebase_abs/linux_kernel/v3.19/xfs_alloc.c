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
if ( args -> V_4 >= args -> V_21 )
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
if ( V_52 & V_58 ) {
#ifdef F_21
if ( ( error = F_8 ( V_47 , & V_54 , & V_56 , & V_53 ) ) )
return error ;
F_22 (
V_53 == 1 && V_54 == V_49 && V_56 == V_50 ) ;
#endif
} else {
if ( ( error = F_1 ( V_47 , V_49 , V_50 , & V_53 ) ) )
return error ;
F_22 ( V_53 == 1 ) ;
}
if ( V_52 & V_59 ) {
#ifdef F_21
if ( ( error = F_8 ( V_48 , & V_54 , & V_56 , & V_53 ) ) )
return error ;
F_22 (
V_53 == 1 && V_54 == V_49 && V_56 == V_50 ) ;
#endif
} else {
if ( ( error = F_1 ( V_48 , V_49 , V_50 , & V_53 ) ) )
return error ;
F_22 ( V_53 == 1 ) ;
}
#ifdef F_21
if ( V_48 -> V_60 == 1 && V_47 -> V_60 == 1 ) {
struct V_61 * V_62 ;
struct V_61 * V_63 ;
V_62 = F_23 ( V_48 -> V_64 [ 0 ] ) ;
V_63 = F_23 ( V_47 -> V_64 [ 0 ] ) ;
F_22 (
V_62 -> V_65 == V_63 -> V_65 ) ;
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
F_22 ( V_53 == 1 ) ;
if ( V_54 != V_36 ) {
if ( ( error = F_1 ( V_47 , V_54 , V_56 , & V_53 ) ) )
return error ;
F_22 ( V_53 == 0 ) ;
if ( ( error = F_25 ( V_47 , & V_53 ) ) )
return error ;
F_22 ( V_53 == 1 ) ;
}
if ( V_55 != V_36 ) {
if ( ( error = F_1 ( V_47 , V_55 , V_57 , & V_53 ) ) )
return error ;
F_22 ( V_53 == 0 ) ;
if ( ( error = F_25 ( V_47 , & V_53 ) ) )
return error ;
F_22 ( V_53 == 1 ) ;
}
if ( V_54 == V_36 ) {
if ( ( error = F_24 ( V_48 , & V_53 ) ) )
return error ;
F_22 ( V_53 == 1 ) ;
} else {
if ( ( error = F_5 ( V_48 , V_54 , V_56 ) ) )
return error ;
}
if ( V_55 != V_36 ) {
if ( ( error = F_1 ( V_48 , V_55 , V_57 , & V_53 ) ) )
return error ;
F_22 ( V_53 == 0 ) ;
if ( ( error = F_25 ( V_48 , & V_53 ) ) )
return error ;
F_22 ( V_53 == 1 ) ;
}
return 0 ;
}
static bool
F_26 (
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 -> V_71 ;
struct V_72 * V_73 = F_27 ( V_67 ) ;
int V_53 ;
if ( ! F_28 ( & V_73 -> V_74 , & V_69 -> V_75 . V_76 ) )
return false ;
if ( F_10 ( V_73 -> V_77 ) != V_78 )
return false ;
if ( V_67 -> V_79 && F_10 ( V_73 -> V_80 ) != V_67 -> V_79 -> V_81 )
return false ;
for ( V_53 = 0 ; V_53 < F_29 ( V_69 ) ; V_53 ++ ) {
if ( F_10 ( V_73 -> V_82 [ V_53 ] ) != V_36 &&
F_10 ( V_73 -> V_82 [ V_53 ] ) >= V_69 -> V_75 . V_83 )
return false ;
}
return true ;
}
static void
F_30 (
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 -> V_71 ;
if ( ! F_31 ( & V_69 -> V_75 ) )
return;
if ( ! F_32 ( V_67 , V_84 ) )
F_33 ( V_67 , - V_85 ) ;
else if ( ! F_26 ( V_67 ) )
F_33 ( V_67 , - V_86 ) ;
if ( V_67 -> V_87 )
F_34 ( V_67 ) ;
}
static void
F_35 (
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 -> V_71 ;
struct V_88 * V_89 = V_67 -> V_90 ;
if ( ! F_31 ( & V_69 -> V_75 ) )
return;
if ( ! F_26 ( V_67 ) ) {
F_33 ( V_67 , - V_86 ) ;
F_34 ( V_67 ) ;
return;
}
if ( V_89 )
F_27 ( V_67 ) -> V_91 = F_36 ( V_89 -> V_92 . V_93 ) ;
F_37 ( V_67 , V_84 ) ;
}
STATIC int
F_38 (
T_6 * V_69 ,
T_7 * V_94 ,
T_8 V_95 ,
T_9 * * V_96 )
{
T_9 * V_67 ;
int error ;
ASSERT ( V_95 != V_97 ) ;
error = F_39 (
V_69 , V_94 , V_69 -> V_98 ,
F_40 ( V_69 , V_95 , F_41 ( V_69 ) ) ,
F_42 ( V_69 , 1 ) , 0 , & V_67 , & V_99 ) ;
if ( error )
return error ;
F_43 ( V_67 , V_100 ) ;
* V_96 = V_67 ;
return 0 ;
}
STATIC int
F_44 (
struct V_101 * V_94 ,
struct V_102 * V_103 ,
struct V_66 * V_44 ,
long V_4 )
{
struct V_104 * V_42 = F_19 ( V_44 ) ;
V_103 -> V_105 += V_4 ;
F_45 ( & V_42 -> V_45 , V_4 ) ;
F_46 ( V_94 , V_4 ) ;
if ( F_47 ( F_10 ( V_42 -> V_45 ) >
F_10 ( V_42 -> V_106 ) ) )
return - V_86 ;
F_48 ( V_94 , V_44 , V_107 ) ;
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
args -> V_108 = 0 ;
switch ( args -> type ) {
case V_109 :
error = F_50 ( args ) ;
break;
case V_110 :
error = F_51 ( args ) ;
break;
case V_111 :
error = F_52 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error || args -> V_46 == V_36 )
return error ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_41 ) ;
ASSERT ( ! args -> V_108 || ! args -> V_112 ) ;
ASSERT ( args -> V_46 % args -> V_20 == 0 ) ;
if ( ! args -> V_108 ) {
error = F_44 ( args -> V_94 , args -> V_103 ,
args -> V_44 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_53 ( args -> V_69 , args -> V_95 ,
args -> V_46 , args -> V_4 ) ) ;
}
if ( ! args -> V_112 ) {
F_54 ( args -> V_94 , args -> V_113 ?
V_114 :
V_115 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
}
F_55 ( V_116 ) ;
F_56 ( V_117 , args -> V_4 ) ;
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
T_1 V_118 ;
T_2 V_119 ;
T_1 V_120 ;
int V_53 ;
ASSERT ( args -> V_20 == 1 ) ;
V_48 = F_57 ( args -> V_69 , args -> V_94 , args -> V_44 ,
args -> V_95 , V_121 ) ;
error = F_4 ( V_48 , args -> V_46 , args -> V_21 , & V_53 ) ;
if ( error )
goto V_122;
if ( ! V_53 )
goto V_123;
error = F_8 ( V_48 , & V_49 , & V_50 , & V_53 ) ;
if ( error )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
ASSERT ( V_49 <= args -> V_46 ) ;
F_12 ( args , V_49 , V_50 , & V_118 , & V_119 ) ;
if ( V_118 > args -> V_46 )
goto V_123;
if ( V_119 < args -> V_21 )
goto V_123;
V_120 = V_118 + V_119 ;
if ( V_120 < args -> V_46 + args -> V_21 )
goto V_123;
args -> V_4 = F_59 ( V_120 , args -> V_46 + args -> V_41 )
- args -> V_46 ;
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_123;
ASSERT ( args -> V_46 + args -> V_4 <= V_120 ) ;
V_47 = F_57 ( args -> V_69 , args -> V_94 , args -> V_44 ,
args -> V_95 , V_124 ) ;
ASSERT ( args -> V_46 + args -> V_4 <=
F_10 ( F_19 ( args -> V_44 ) -> V_106 ) ) ;
error = F_20 ( V_47 , V_48 , V_49 , V_50 , args -> V_46 ,
args -> V_4 , V_59 ) ;
if ( error ) {
F_60 ( V_47 , V_125 ) ;
goto V_122;
}
F_60 ( V_48 , V_126 ) ;
F_60 ( V_47 , V_126 ) ;
args -> V_108 = 0 ;
F_61 ( args ) ;
return 0 ;
V_123:
F_60 ( V_48 , V_126 ) ;
args -> V_46 = V_36 ;
F_62 ( args ) ;
return 0 ;
V_122:
F_60 ( V_48 , V_125 ) ;
F_63 ( args ) ;
return error ;
}
STATIC int
F_64 (
struct V_127 * args ,
struct V_1 * * V_128 ,
struct V_1 * * V_129 ,
T_1 V_130 ,
T_1 * V_131 ,
T_2 * V_132 ,
T_1 * V_133 ,
T_2 * V_134 ,
int V_135 )
{
T_1 V_136 ;
T_1 V_137 ;
int error ;
int V_53 ;
if ( ! V_130 )
goto V_138;
do {
error = F_8 ( * V_129 , V_131 , V_132 , & V_53 ) ;
if ( error )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
F_11 ( args , * V_131 , * V_132 , V_133 , V_134 ) ;
if ( ! V_135 ) {
if ( * V_133 >= args -> V_46 + V_130 )
goto V_138;
} else {
if ( * V_133 <= args -> V_46 - V_130 )
goto V_138;
}
if ( * V_134 >= args -> V_21 ) {
args -> V_4 = F_15 ( * V_134 , args -> V_41 ) ;
F_17 ( args ) ;
V_137 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 ,
args -> V_26 , * V_133 ,
* V_134 , & V_136 ) ;
if ( V_137 < V_130 )
goto V_139;
goto V_138;
}
if ( ! V_135 )
error = F_65 ( * V_129 , 0 , & V_53 ) ;
else
error = F_66 ( * V_129 , 0 , & V_53 ) ;
if ( error )
goto V_122;
} while ( V_53 );
V_138:
F_60 ( * V_129 , V_126 ) ;
* V_129 = NULL ;
return 0 ;
V_139:
F_60 ( * V_128 , V_126 ) ;
* V_128 = NULL ;
return 0 ;
V_122:
return error ;
}
STATIC int
F_51 (
T_3 * args )
{
T_5 * V_140 ;
T_5 * V_141 ;
T_5 * V_47 ;
T_1 V_142 ;
T_1 V_143 ;
T_2 V_144 ;
T_2 V_145 ;
T_2 V_146 ;
T_1 V_147 ;
int error ;
int V_53 ;
int V_148 ;
T_1 V_149 ;
T_1 V_150 ;
T_2 V_151 ;
T_2 V_152 ;
T_2 V_153 ;
T_1 V_154 ;
T_2 V_38 ;
int V_155 = 0 ;
#ifdef F_21
int V_156 ;
V_156 = F_67 () & 1 ;
#endif
V_157:
V_141 = NULL ;
V_140 = NULL ;
V_152 = 0 ;
V_146 = 0 ;
V_153 = 0 ;
V_47 = F_57 ( args -> V_69 , args -> V_94 , args -> V_44 ,
args -> V_95 , V_124 ) ;
if ( ( error = F_3 ( V_47 , 0 , args -> V_41 , & V_53 ) ) )
goto V_122;
if ( ! V_53 ) {
if ( ( error = F_68 ( args , V_47 , & V_149 ,
& V_152 , & V_53 ) ) )
goto V_122;
if ( V_53 == 0 || V_152 == 0 ) {
F_60 ( V_47 , V_126 ) ;
F_69 ( args ) ;
return 0 ;
}
ASSERT ( V_53 == 1 ) ;
}
args -> V_108 = 0 ;
while ( F_70 ( V_47 , 0 ) ) {
T_2 V_158 ;
int V_159 = 0 ;
T_2 V_160 = 0 ;
T_1 V_161 = 0 ;
#ifdef F_21
if ( V_156 )
break;
#endif
if ( V_152 || args -> V_20 > 1 ) {
V_47 -> V_162 [ 0 ] = 1 ;
do {
if ( ( error = F_8 ( V_47 , & V_149 ,
& V_152 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( V_152 >= args -> V_21 )
break;
if ( ( error = F_65 ( V_47 , 0 , & V_53 ) ) )
goto V_122;
} while ( V_53 );
ASSERT ( V_152 >= args -> V_21 ) ;
if ( ! V_53 )
break;
}
V_53 = V_47 -> V_162 [ 0 ] ;
for ( V_148 = 1 , V_160 = 0 , V_158 = 0 ;
! error && V_148 && ( V_160 < args -> V_41 || V_158 > 0 ) ;
error = F_65 ( V_47 , 0 , & V_148 ) ) {
if ( ( error = F_8 ( V_47 , & V_149 , & V_152 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
F_11 ( args , V_149 , V_152 ,
& V_150 , & V_153 ) ;
if ( V_153 < args -> V_21 )
continue;
args -> V_4 = F_15 ( V_153 , args -> V_41 ) ;
F_17 ( args ) ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
if ( args -> V_4 < V_160 )
continue;
V_151 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 , args -> V_26 , V_150 ,
V_153 , & V_154 ) ;
if ( V_154 != V_36 &&
( args -> V_4 > V_160 || V_151 < V_158 ) ) {
V_158 = V_151 ;
V_161 = V_154 ;
V_160 = args -> V_4 ;
V_159 = V_47 -> V_162 [ 0 ] ;
}
}
if ( V_160 == 0 )
break;
V_47 -> V_162 [ 0 ] = V_159 ;
if ( ( error = F_8 ( V_47 , & V_149 , & V_152 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
ASSERT ( V_149 + V_152 <= F_10 ( F_19 ( args -> V_44 ) -> V_106 ) ) ;
args -> V_4 = V_160 ;
if ( ! F_18 ( args ) ) {
F_60 ( V_47 , V_126 ) ;
F_71 ( args ) ;
return 0 ;
}
V_160 = args -> V_4 ;
args -> V_46 = V_161 ;
ASSERT ( V_161 >= V_149 ) ;
ASSERT ( V_161 + V_160 <= V_149 + V_152 ) ;
V_141 = F_57 ( args -> V_69 , args -> V_94 ,
args -> V_44 , args -> V_95 , V_121 ) ;
if ( ( error = F_20 ( V_47 , V_141 , V_149 ,
V_152 , V_161 , V_160 , V_58 ) ) )
goto V_122;
F_60 ( V_47 , V_126 ) ;
F_60 ( V_141 , V_126 ) ;
F_72 ( args ) ;
return 0 ;
}
V_141 = F_57 ( args -> V_69 , args -> V_94 , args -> V_44 ,
args -> V_95 , V_121 ) ;
if ( ( error = F_4 ( V_141 , args -> V_46 , args -> V_41 , & V_53 ) ) )
goto V_122;
if ( ! V_53 ) {
V_140 = V_141 ;
V_141 = NULL ;
}
else if ( ( error = F_73 ( V_141 , & V_140 ) ) )
goto V_122;
if ( ( error = F_65 ( V_140 , 0 , & V_53 ) ) )
goto V_122;
if ( ! V_53 ) {
F_60 ( V_140 , V_126 ) ;
V_140 = NULL ;
}
do {
if ( V_141 ) {
if ( ( error = F_8 ( V_141 , & V_149 , & V_152 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
F_11 ( args , V_149 , V_152 ,
& V_150 , & V_153 ) ;
if ( V_153 >= args -> V_21 )
break;
if ( ( error = F_66 ( V_141 , 0 , & V_53 ) ) )
goto V_122;
if ( ! V_53 ) {
F_60 ( V_141 ,
V_126 ) ;
V_141 = NULL ;
}
}
if ( V_140 ) {
if ( ( error = F_8 ( V_140 , & V_142 , & V_145 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
F_11 ( args , V_142 , V_145 ,
& V_143 , & V_146 ) ;
if ( V_146 >= args -> V_21 )
break;
if ( ( error = F_65 ( V_140 , 0 , & V_53 ) ) )
goto V_122;
if ( ! V_53 ) {
F_60 ( V_140 ,
V_126 ) ;
V_140 = NULL ;
}
}
} while ( V_141 || V_140 );
if ( V_141 && V_140 ) {
if ( V_153 >= args -> V_21 ) {
args -> V_4 = F_15 ( V_153 , args -> V_41 ) ;
F_17 ( args ) ;
V_151 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 , args -> V_26 , V_150 ,
V_153 , & V_154 ) ;
error = F_64 ( args ,
& V_141 , & V_140 ,
V_151 , & V_142 , & V_145 ,
& V_143 , & V_146 ,
0 ) ;
} else {
ASSERT ( V_146 >= args -> V_21 ) ;
args -> V_4 = F_15 ( V_146 , args -> V_41 ) ;
F_17 ( args ) ;
V_144 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 , args -> V_26 , V_143 ,
V_146 , & V_147 ) ;
error = F_64 ( args ,
& V_140 , & V_141 ,
V_144 , & V_149 , & V_152 ,
& V_150 , & V_153 ,
1 ) ;
}
if ( error )
goto V_122;
}
if ( V_141 == NULL && V_140 == NULL ) {
F_60 ( V_47 , V_126 ) ;
if ( ! V_155 ++ ) {
F_74 ( args ) ;
F_75 ( args -> V_69 , V_163 ) ;
goto V_157;
}
F_76 ( args ) ;
args -> V_46 = V_36 ;
return 0 ;
}
if ( V_140 ) {
V_141 = V_140 ;
V_140 = NULL ;
V_149 = V_142 ;
V_150 = V_143 ;
V_152 = V_145 ;
V_153 = V_146 ;
V_148 = 1 ;
} else
V_148 = 0 ;
args -> V_4 = F_15 ( V_153 , args -> V_41 ) ;
F_17 ( args ) ;
if ( ! F_18 ( args ) ) {
F_71 ( args ) ;
F_60 ( V_141 , V_126 ) ;
F_60 ( V_47 , V_126 ) ;
return 0 ;
}
V_38 = args -> V_4 ;
( void ) F_14 ( args -> V_46 , V_38 , args -> V_20 ,
args -> V_26 , V_150 , V_153 , & V_154 ) ;
ASSERT ( V_154 >= V_149 ) ;
ASSERT ( V_154 + V_38 <= V_150 + V_153 ) ;
ASSERT ( V_154 + V_38 <= F_10 ( F_19 ( args -> V_44 ) -> V_106 ) ) ;
args -> V_46 = V_154 ;
if ( ( error = F_20 ( V_47 , V_141 , V_149 , V_152 ,
V_154 , V_38 , V_59 ) ) )
goto V_122;
if ( V_148 )
F_77 ( args ) ;
else
F_78 ( args ) ;
F_60 ( V_47 , V_126 ) ;
F_60 ( V_141 , V_126 ) ;
return 0 ;
V_122:
F_79 ( args ) ;
if ( V_47 != NULL )
F_60 ( V_47 , V_125 ) ;
if ( V_141 != NULL )
F_60 ( V_141 , V_125 ) ;
if ( V_140 != NULL )
F_60 ( V_140 , V_125 ) ;
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
int V_155 = 0 ;
V_157:
V_47 = F_57 ( args -> V_69 , args -> V_94 , args -> V_44 ,
args -> V_95 , V_124 ) ;
V_48 = NULL ;
if ( ( error = F_3 ( V_47 , 0 ,
args -> V_41 + args -> V_20 - 1 , & V_53 ) ) )
goto V_122;
if ( ! V_53 || V_155 > 1 ) {
error = F_68 ( args , V_47 ,
& V_49 , & V_50 , & V_53 ) ;
if ( error )
goto V_122;
if ( V_53 == 0 || V_50 == 0 ) {
F_60 ( V_47 , V_126 ) ;
F_80 ( args ) ;
return 0 ;
}
ASSERT ( V_53 == 1 ) ;
F_11 ( args , V_49 , V_50 , & V_51 , & V_38 ) ;
} else {
for (; ; ) {
error = F_8 ( V_47 , & V_49 , & V_50 , & V_53 ) ;
if ( error )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
F_11 ( args , V_49 , V_50 ,
& V_51 , & V_38 ) ;
if ( V_38 >= args -> V_41 )
break;
error = F_65 ( V_47 , 0 , & V_53 ) ;
if ( error )
goto V_122;
if ( V_53 == 0 ) {
F_60 ( V_47 ,
V_126 ) ;
F_81 ( args ) ;
if ( ! V_155 ++ )
F_75 ( args -> V_69 , V_163 ) ;
goto V_157;
}
}
}
V_38 = F_15 ( args -> V_41 , V_38 ) ;
F_58 ( V_38 == 0 ||
( V_38 <= V_50 && V_51 + V_38 <= V_49 + V_50 ) , V_122 ) ;
if ( V_38 < args -> V_41 ) {
T_1 V_164 ;
T_2 V_165 ;
T_1 V_166 ;
T_2 V_167 ;
V_167 = V_38 ;
V_166 = V_51 ;
V_165 = V_50 ;
V_164 = V_49 ;
for (; ; ) {
if ( ( error = F_66 ( V_47 , 0 , & V_53 ) ) )
goto V_122;
if ( V_53 == 0 )
break;
if ( ( error = F_8 ( V_47 , & V_49 , & V_50 ,
& V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( V_50 < V_167 )
break;
F_11 ( args , V_49 , V_50 ,
& V_51 , & V_38 ) ;
V_38 = F_15 ( args -> V_41 , V_38 ) ;
F_58 ( V_38 == 0 ||
( V_38 <= V_50 && V_51 + V_38 <= V_49 + V_50 ) ,
V_122 ) ;
if ( V_38 > V_167 ) {
V_167 = V_38 ;
V_166 = V_51 ;
V_165 = V_50 ;
V_164 = V_49 ;
if ( V_38 == args -> V_41 )
break;
}
}
if ( ( error = F_1 ( V_47 , V_164 , V_165 ,
& V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
V_38 = V_167 ;
V_51 = V_166 ;
V_50 = V_165 ;
V_49 = V_164 ;
}
args -> V_108 = 0 ;
args -> V_4 = V_38 ;
if ( V_38 < args -> V_21 ) {
if ( ! V_155 ++ ) {
F_60 ( V_47 , V_126 ) ;
F_81 ( args ) ;
F_75 ( args -> V_69 , V_163 ) ;
goto V_157;
}
goto V_168;
}
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_168;
V_38 = args -> V_4 ;
F_58 ( V_38 <= V_50 , V_122 ) ;
V_48 = F_57 ( args -> V_69 , args -> V_94 , args -> V_44 ,
args -> V_95 , V_121 ) ;
if ( ( error = F_20 ( V_47 , V_48 , V_49 , V_50 ,
V_51 , V_38 , V_58 ) ) )
goto V_122;
F_60 ( V_47 , V_126 ) ;
F_60 ( V_48 , V_126 ) ;
V_47 = V_48 = NULL ;
args -> V_4 = V_38 ;
args -> V_46 = V_51 ;
F_58 (
args -> V_46 + args -> V_4 <=
F_10 ( F_19 ( args -> V_44 ) -> V_106 ) ,
V_122 ) ;
F_82 ( args ) ;
return 0 ;
V_122:
F_83 ( args ) ;
if ( V_47 )
F_60 ( V_47 , V_125 ) ;
if ( V_48 )
F_60 ( V_48 , V_125 ) ;
return error ;
V_168:
F_60 ( V_47 , V_126 ) ;
F_84 ( args ) ;
args -> V_46 = V_36 ;
return 0 ;
}
STATIC int
F_68 (
T_3 * args ,
T_5 * V_169 ,
T_1 * V_170 ,
T_2 * V_171 ,
int * V_5 )
{
int error ;
T_1 V_49 ;
T_2 V_50 ;
int V_53 ;
if ( ( error = F_66 ( V_169 , 0 , & V_53 ) ) )
goto V_122;
if ( V_53 ) {
if ( ( error = F_8 ( V_169 , & V_49 , & V_50 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
}
else if ( args -> V_21 == 1 && args -> V_20 == 1 && ! args -> V_112 &&
( F_10 ( F_19 ( args -> V_44 ) -> V_172 )
> args -> V_43 ) ) {
error = F_85 ( args -> V_94 , args -> V_44 , & V_49 , 0 ) ;
if ( error )
goto V_122;
if ( V_49 != V_36 ) {
F_86 ( args -> V_69 , args -> V_95 , V_49 , 1 ,
args -> V_26 ) ;
if ( args -> V_26 ) {
T_9 * V_67 ;
V_67 = F_87 ( args -> V_69 , args -> V_94 ,
args -> V_95 , V_49 , 0 ) ;
F_88 ( args -> V_94 , V_67 ) ;
}
args -> V_4 = 1 ;
args -> V_46 = V_49 ;
F_58 (
args -> V_46 + args -> V_4 <=
F_10 ( F_19 ( args -> V_44 ) -> V_106 ) ,
V_122 ) ;
args -> V_108 = 1 ;
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
* V_170 = V_49 ;
* V_171 = V_50 ;
* V_5 = 1 ;
F_91 ( args ) ;
return 0 ;
V_122:
F_92 ( args ) ;
return error ;
}
STATIC int
F_93 (
T_7 * V_94 ,
T_9 * V_44 ,
T_8 V_95 ,
T_1 V_3 ,
T_2 V_4 ,
int V_112 )
{
T_5 * V_48 ;
T_5 * V_47 ;
int error ;
T_1 V_142 ;
T_2 V_145 ;
int V_173 ;
int V_174 ;
int V_53 ;
T_1 V_149 ;
T_2 V_152 ;
T_6 * V_69 ;
T_1 V_175 ;
T_2 V_176 ;
T_10 * V_103 ;
V_69 = V_94 -> V_177 ;
V_48 = F_57 ( V_69 , V_94 , V_44 , V_95 , V_121 ) ;
V_47 = NULL ;
if ( ( error = F_4 ( V_48 , V_3 , V_4 , & V_173 ) ) )
goto V_122;
if ( V_173 ) {
if ( ( error = F_8 ( V_48 , & V_149 , & V_152 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( V_149 + V_152 < V_3 )
V_173 = 0 ;
else {
F_58 ( V_149 + V_152 <= V_3 , V_122 ) ;
}
}
if ( ( error = F_65 ( V_48 , 0 , & V_174 ) ) )
goto V_122;
if ( V_174 ) {
if ( ( error = F_8 ( V_48 , & V_142 , & V_145 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( V_3 + V_4 < V_142 )
V_174 = 0 ;
else {
F_58 ( V_142 >= V_3 + V_4 , V_122 ) ;
}
}
V_47 = F_57 ( V_69 , V_94 , V_44 , V_95 , V_124 ) ;
if ( V_173 && V_174 ) {
if ( ( error = F_1 ( V_47 , V_149 , V_152 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( ( error = F_1 ( V_47 , V_142 , V_145 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( ( error = F_24 ( V_48 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( ( error = F_66 ( V_48 , 0 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
#ifdef F_21
{
T_1 V_178 ;
T_2 V_179 ;
if ( ( error = F_8 ( V_48 , & V_178 , & V_179 ,
& V_53 ) ) )
goto V_122;
F_58 (
V_53 == 1 && V_178 == V_149 && V_179 == V_152 ,
V_122 ) ;
}
#endif
V_175 = V_149 ;
V_176 = V_4 + V_152 + V_145 ;
if ( ( error = F_5 ( V_48 , V_175 , V_176 ) ) )
goto V_122;
}
else if ( V_173 ) {
if ( ( error = F_1 ( V_47 , V_149 , V_152 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( ( error = F_66 ( V_48 , 0 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
V_175 = V_149 ;
V_176 = V_4 + V_152 ;
if ( ( error = F_5 ( V_48 , V_175 , V_176 ) ) )
goto V_122;
}
else if ( V_174 ) {
if ( ( error = F_1 ( V_47 , V_142 , V_145 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
V_175 = V_3 ;
V_176 = V_4 + V_145 ;
if ( ( error = F_5 ( V_48 , V_175 , V_176 ) ) )
goto V_122;
}
else {
V_175 = V_3 ;
V_176 = V_4 ;
if ( ( error = F_25 ( V_48 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
}
F_60 ( V_48 , V_126 ) ;
V_48 = NULL ;
if ( ( error = F_1 ( V_47 , V_175 , V_176 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 0 , V_122 ) ;
if ( ( error = F_25 ( V_47 , & V_53 ) ) )
goto V_122;
F_58 ( V_53 == 1 , V_122 ) ;
F_60 ( V_47 , V_126 ) ;
V_47 = NULL ;
V_103 = F_94 ( V_69 , V_95 ) ;
error = F_44 ( V_94 , V_103 , V_44 , V_4 ) ;
F_95 ( V_103 ) ;
if ( error )
goto V_122;
if ( ! V_112 )
F_54 ( V_94 , V_115 , ( long ) V_4 ) ;
F_55 ( V_180 ) ;
F_56 ( V_181 , V_4 ) ;
F_96 ( V_69 , V_95 , V_3 , V_4 , V_112 , V_173 , V_174 ) ;
return 0 ;
V_122:
F_96 ( V_69 , V_95 , V_3 , V_4 , V_112 , - 1 , - 1 ) ;
if ( V_48 )
F_60 ( V_48 , V_125 ) ;
if ( V_47 )
F_60 ( V_47 , V_125 ) ;
return error ;
}
void
F_97 (
T_6 * V_69 )
{
int V_182 ;
T_11 V_183 ;
T_11 V_184 ;
int V_185 ;
int V_186 ;
V_184 = ( V_69 -> V_75 . V_83 + 1 ) / 2 ;
V_185 = V_69 -> V_187 [ 0 ] ;
V_186 = V_69 -> V_187 [ 1 ] ;
V_183 = ( V_184 + V_185 - 1 ) / V_185 ;
for ( V_182 = 1 ; V_183 > 1 ; V_182 ++ )
V_183 = ( V_183 + V_186 - 1 ) / V_186 ;
V_69 -> V_188 = V_182 ;
}
T_2
F_98 (
struct V_68 * V_69 ,
struct V_102 * V_103 )
{
T_2 V_189 , V_190 = 0 ;
V_189 = F_99 ( V_103 , V_69 ) ;
if ( V_189 > V_103 -> V_191 )
V_190 = V_189 - V_103 -> V_191 ;
if ( V_103 -> V_192 > V_190 )
return V_103 -> V_192 - V_190 ;
return V_103 -> V_191 > 0 || V_103 -> V_192 > 0 ;
}
STATIC int
F_100 (
T_3 * args ,
int V_52 )
{
T_9 * V_44 ;
T_4 * V_42 ;
T_9 * V_193 ;
T_1 V_3 ;
T_2 V_190 ;
int error ;
T_2 V_194 ;
T_6 * V_69 ;
T_2 V_189 ;
T_10 * V_103 ;
T_3 V_195 ;
T_7 * V_94 ;
V_69 = args -> V_69 ;
V_103 = args -> V_103 ;
V_94 = args -> V_94 ;
if ( ! V_103 -> V_196 ) {
if ( ( error = F_101 ( V_69 , V_94 , args -> V_95 , V_52 ,
& V_44 ) ) )
return error ;
if ( ! V_103 -> V_196 ) {
ASSERT ( V_52 & V_197 ) ;
ASSERT ( ! ( V_52 & V_198 ) ) ;
args -> V_44 = NULL ;
return 0 ;
}
} else
V_44 = NULL ;
if ( V_103 -> V_199 && args -> V_26 &&
( V_52 & V_197 ) ) {
ASSERT ( ! ( V_52 & V_198 ) ) ;
args -> V_44 = NULL ;
return 0 ;
}
if ( ! ( V_52 & V_198 ) ) {
V_189 = F_99 ( V_103 , V_69 ) ;
V_194 = F_98 ( V_69 , V_103 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_200 - 1 ) >
V_194 ||
( ( int ) ( V_103 -> V_105 + V_103 -> V_191 -
V_189 - args -> V_201 ) < ( int ) args -> V_43 ) ) {
if ( V_44 )
F_102 ( V_94 , V_44 ) ;
args -> V_44 = NULL ;
return 0 ;
}
}
if ( V_44 == NULL ) {
if ( ( error = F_101 ( V_69 , V_94 , args -> V_95 , V_52 ,
& V_44 ) ) )
return error ;
if ( V_44 == NULL ) {
ASSERT ( V_52 & V_197 ) ;
ASSERT ( ! ( V_52 & V_198 ) ) ;
args -> V_44 = NULL ;
return 0 ;
}
}
V_42 = F_19 ( V_44 ) ;
V_189 = F_103 ( V_42 , V_69 ) ;
if ( ! ( V_52 & V_198 ) ) {
V_190 = V_189 > F_10 ( V_42 -> V_172 ) ?
( V_189 - F_10 ( V_42 -> V_172 ) ) : 0 ;
V_194 = F_10 ( V_42 -> V_202 ) ;
V_194 = ( V_194 > V_190 ) ? ( V_194 - V_190 ) :
( F_10 ( V_42 -> V_172 ) > 0 || V_194 > 0 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_200 - 1 ) >
V_194 ||
( ( int ) ( F_10 ( V_42 -> V_45 ) +
F_10 ( V_42 -> V_172 ) - V_189 - args -> V_201 ) <
( int ) args -> V_43 ) ) {
F_102 ( V_94 , V_44 ) ;
args -> V_44 = NULL ;
return 0 ;
}
}
while ( F_10 ( V_42 -> V_172 ) > V_189 ) {
T_9 * V_67 ;
error = F_85 ( V_94 , V_44 , & V_3 , 0 ) ;
if ( error )
return error ;
if ( ( error = F_93 ( V_94 , V_44 , args -> V_95 , V_3 , 1 , 1 ) ) )
return error ;
V_67 = F_87 ( V_69 , V_94 , args -> V_95 , V_3 , 0 ) ;
F_88 ( V_94 , V_67 ) ;
}
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_94 = V_94 ;
V_195 . V_69 = V_69 ;
V_195 . V_44 = V_44 ;
V_195 . V_95 = args -> V_95 ;
V_195 . V_20 = V_195 . V_21 = V_195 . V_40 = V_195 . V_112 = 1 ;
V_195 . type = V_109 ;
V_195 . V_103 = V_103 ;
if ( ( error = F_38 ( V_69 , V_94 , V_195 . V_95 , & V_193 ) ) )
return error ;
while ( F_10 ( V_42 -> V_172 ) < V_189 ) {
V_195 . V_46 = 0 ;
V_195 . V_41 = V_189 - F_10 ( V_42 -> V_172 ) ;
if ( ( error = F_49 ( & V_195 ) ) ) {
F_102 ( V_94 , V_193 ) ;
return error ;
}
if ( V_195 . V_46 == V_36 ) {
if ( V_52 & V_198 )
break;
F_102 ( V_94 , V_193 ) ;
args -> V_44 = NULL ;
return 0 ;
}
for ( V_3 = V_195 . V_46 ; V_3 < V_195 . V_46 + V_195 . V_4 ; V_3 ++ ) {
error = F_104 ( V_94 , V_44 ,
V_193 , V_3 , 0 ) ;
if ( error )
return error ;
}
}
F_102 ( V_94 , V_193 ) ;
args -> V_44 = V_44 ;
return 0 ;
}
int
F_85 (
T_7 * V_94 ,
T_9 * V_44 ,
T_1 * V_203 ,
int V_204 )
{
T_4 * V_42 ;
T_9 * V_193 ;
T_1 V_3 ;
T_12 * V_82 ;
int error ;
int V_205 ;
T_6 * V_69 = V_94 -> V_177 ;
T_10 * V_103 ;
V_42 = F_19 ( V_44 ) ;
if ( ! V_42 -> V_172 ) {
* V_203 = V_36 ;
return 0 ;
}
error = F_38 ( V_69 , V_94 , F_10 ( V_42 -> V_206 ) ,
& V_193 ) ;
if ( error )
return error ;
V_82 = F_105 ( V_69 , V_193 ) ;
V_3 = F_10 ( V_82 [ F_10 ( V_42 -> V_207 ) ] ) ;
F_45 ( & V_42 -> V_207 , 1 ) ;
F_102 ( V_94 , V_193 ) ;
if ( F_10 ( V_42 -> V_207 ) == F_29 ( V_69 ) )
V_42 -> V_207 = 0 ;
V_103 = F_94 ( V_69 , F_10 ( V_42 -> V_206 ) ) ;
F_45 ( & V_42 -> V_172 , - 1 ) ;
F_106 ( V_94 , - 1 ) ;
V_103 -> V_191 -- ;
F_95 ( V_103 ) ;
V_205 = V_208 | V_209 ;
if ( V_204 ) {
F_45 ( & V_42 -> V_210 , 1 ) ;
V_103 -> V_211 ++ ;
V_205 |= V_212 ;
}
F_48 ( V_94 , V_44 , V_205 ) ;
* V_203 = V_3 ;
return 0 ;
}
void
F_48 (
T_7 * V_94 ,
T_9 * V_67 ,
int V_213 )
{
int V_214 ;
int V_215 ;
static const short V_216 [] = {
F_107 ( T_4 , V_217 ) ,
F_107 ( T_4 , V_218 ) ,
F_107 ( T_4 , V_206 ) ,
F_107 ( T_4 , V_106 ) ,
F_107 ( T_4 , V_219 [ 0 ] ) ,
F_107 ( T_4 , V_220 [ 0 ] ) ,
F_107 ( T_4 , V_207 ) ,
F_107 ( T_4 , V_221 ) ,
F_107 ( T_4 , V_172 ) ,
F_107 ( T_4 , V_45 ) ,
F_107 ( T_4 , V_202 ) ,
F_107 ( T_4 , V_210 ) ,
F_107 ( T_4 , V_222 ) ,
sizeof( T_4 )
} ;
F_108 ( V_94 -> V_177 , F_19 ( V_67 ) , V_213 , V_223 ) ;
F_109 ( V_94 , V_67 , V_224 ) ;
F_110 ( V_213 , V_216 , V_225 , & V_214 , & V_215 ) ;
F_111 ( V_94 , V_67 , ( T_11 ) V_214 , ( T_11 ) V_215 ) ;
}
int
F_112 (
T_6 * V_69 ,
T_7 * V_94 ,
T_8 V_95 ,
int V_52 )
{
T_9 * V_67 ;
int error ;
if ( ( error = F_101 ( V_69 , V_94 , V_95 , V_52 , & V_67 ) ) )
return error ;
if ( V_67 )
F_102 ( V_94 , V_67 ) ;
return 0 ;
}
int
F_104 (
T_7 * V_94 ,
T_9 * V_44 ,
T_9 * V_193 ,
T_1 V_3 ,
int V_204 )
{
T_4 * V_42 ;
T_12 * V_226 ;
int error ;
int V_205 ;
T_6 * V_69 ;
T_10 * V_103 ;
T_12 * V_82 ;
int V_227 ;
V_42 = F_19 ( V_44 ) ;
V_69 = V_94 -> V_177 ;
if ( ! V_193 && ( error = F_38 ( V_69 , V_94 ,
F_10 ( V_42 -> V_206 ) , & V_193 ) ) )
return error ;
F_45 ( & V_42 -> V_221 , 1 ) ;
if ( F_10 ( V_42 -> V_221 ) == F_29 ( V_69 ) )
V_42 -> V_221 = 0 ;
V_103 = F_94 ( V_69 , F_10 ( V_42 -> V_206 ) ) ;
F_45 ( & V_42 -> V_172 , 1 ) ;
F_106 ( V_94 , 1 ) ;
V_103 -> V_191 ++ ;
V_205 = V_228 | V_209 ;
if ( V_204 ) {
F_45 ( & V_42 -> V_210 , - 1 ) ;
V_103 -> V_211 -- ;
V_205 |= V_212 ;
}
F_95 ( V_103 ) ;
F_48 ( V_94 , V_44 , V_205 ) ;
ASSERT ( F_10 ( V_42 -> V_172 ) <= F_29 ( V_69 ) ) ;
V_82 = F_105 ( V_69 , V_193 ) ;
V_226 = & V_82 [ F_10 ( V_42 -> V_221 ) ] ;
* V_226 = F_6 ( V_3 ) ;
V_227 = ( char * ) V_226 - ( char * ) V_193 -> V_229 ;
F_48 ( V_94 , V_44 , V_205 ) ;
F_109 ( V_94 , V_193 , V_230 ) ;
F_111 ( V_94 , V_193 , V_227 ,
V_227 + sizeof( T_1 ) - 1 ) ;
return 0 ;
}
static bool
F_113 (
struct V_68 * V_69 ,
struct V_66 * V_67 )
{
struct V_104 * V_42 = F_19 ( V_67 ) ;
if ( F_31 ( & V_69 -> V_75 ) &&
! F_28 ( & V_42 -> V_222 , & V_69 -> V_75 . V_76 ) )
return false ;
if ( ! ( V_42 -> V_217 == F_6 ( V_231 ) &&
F_114 ( F_10 ( V_42 -> V_218 ) ) &&
F_10 ( V_42 -> V_45 ) <= F_10 ( V_42 -> V_106 ) &&
F_10 ( V_42 -> V_207 ) < F_29 ( V_69 ) &&
F_10 ( V_42 -> V_221 ) < F_29 ( V_69 ) &&
F_10 ( V_42 -> V_172 ) <= F_29 ( V_69 ) ) )
return false ;
if ( F_10 ( V_42 -> V_220 [ V_121 ] ) > V_232 ||
F_10 ( V_42 -> V_220 [ V_124 ] ) > V_232 )
return false ;
if ( V_67 -> V_79 && F_10 ( V_42 -> V_206 ) != V_67 -> V_79 -> V_81 )
return false ;
if ( F_115 ( & V_69 -> V_75 ) &&
F_10 ( V_42 -> V_210 ) > F_10 ( V_42 -> V_106 ) )
return false ;
return true ; ;
}
static void
F_116 (
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 -> V_71 ;
if ( F_31 ( & V_69 -> V_75 ) &&
! F_32 ( V_67 , V_233 ) )
F_33 ( V_67 , - V_85 ) ;
else if ( F_117 ( ! F_113 ( V_69 , V_67 ) , V_69 ,
V_234 ,
V_235 ) )
F_33 ( V_67 , - V_86 ) ;
if ( V_67 -> V_87 )
F_34 ( V_67 ) ;
}
static void
F_118 (
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 -> V_71 ;
struct V_88 * V_89 = V_67 -> V_90 ;
if ( ! F_113 ( V_69 , V_67 ) ) {
F_33 ( V_67 , - V_86 ) ;
F_34 ( V_67 ) ;
return;
}
if ( ! F_31 ( & V_69 -> V_75 ) )
return;
if ( V_89 )
F_19 ( V_67 ) -> V_236 = F_36 ( V_89 -> V_92 . V_93 ) ;
F_37 ( V_67 , V_233 ) ;
}
int
F_119 (
struct V_68 * V_69 ,
struct V_101 * V_94 ,
T_8 V_95 ,
int V_52 ,
struct V_66 * * V_96 )
{
int error ;
F_120 ( V_69 , V_95 ) ;
ASSERT ( V_95 != V_97 ) ;
error = F_39 (
V_69 , V_94 , V_69 -> V_98 ,
F_40 ( V_69 , V_95 , F_121 ( V_69 ) ) ,
F_42 ( V_69 , 1 ) , V_52 , V_96 , & V_237 ) ;
if ( error )
return error ;
if ( ! * V_96 )
return 0 ;
ASSERT ( ! ( * V_96 ) -> V_87 ) ;
F_43 ( * V_96 , V_238 ) ;
return 0 ;
}
int
F_101 (
struct V_68 * V_69 ,
struct V_101 * V_94 ,
T_8 V_95 ,
int V_52 ,
struct V_66 * * V_96 )
{
struct V_104 * V_42 ;
struct V_102 * V_103 ;
int error ;
F_122 ( V_69 , V_95 ) ;
ASSERT ( V_95 != V_97 ) ;
error = F_119 ( V_69 , V_94 , V_95 ,
( V_52 & V_197 ) ? V_239 : 0 ,
V_96 ) ;
if ( error )
return error ;
if ( ! * V_96 )
return 0 ;
ASSERT ( ! ( * V_96 ) -> V_87 ) ;
V_42 = F_19 ( * V_96 ) ;
V_103 = F_94 ( V_69 , V_95 ) ;
if ( ! V_103 -> V_196 ) {
V_103 -> V_105 = F_10 ( V_42 -> V_45 ) ;
V_103 -> V_211 = F_10 ( V_42 -> V_210 ) ;
V_103 -> V_191 = F_10 ( V_42 -> V_172 ) ;
V_103 -> V_192 = F_10 ( V_42 -> V_202 ) ;
V_103 -> V_240 [ V_241 ] =
F_10 ( V_42 -> V_220 [ V_241 ] ) ;
V_103 -> V_240 [ V_242 ] =
F_10 ( V_42 -> V_220 [ V_242 ] ) ;
F_123 ( & V_103 -> V_243 ) ;
V_103 -> V_244 = 0 ;
V_103 -> V_245 = V_246 ;
V_103 -> V_196 = 1 ;
}
#ifdef F_21
else if ( ! F_124 ( V_69 ) ) {
ASSERT ( V_103 -> V_105 == F_10 ( V_42 -> V_45 ) ) ;
ASSERT ( V_103 -> V_211 == F_10 ( V_42 -> V_210 ) ) ;
ASSERT ( V_103 -> V_191 == F_10 ( V_42 -> V_172 ) ) ;
ASSERT ( V_103 -> V_192 == F_10 ( V_42 -> V_202 ) ) ;
ASSERT ( V_103 -> V_240 [ V_241 ] ==
F_10 ( V_42 -> V_220 [ V_241 ] ) ) ;
ASSERT ( V_103 -> V_240 [ V_242 ] ==
F_10 ( V_42 -> V_220 [ V_242 ] ) ) ;
}
#endif
F_95 ( V_103 ) ;
return 0 ;
}
int
F_125 (
T_3 * args )
{
T_1 V_247 ;
int error ;
int V_52 ;
T_2 V_43 ;
T_6 * V_69 ;
T_8 V_248 ;
T_13 type ;
int V_249 = 0 ;
int V_250 = 0 ;
T_8 V_251 = V_252 ;
V_69 = args -> V_69 ;
type = args -> V_253 = args -> type ;
args -> V_46 = V_36 ;
V_247 = V_69 -> V_75 . V_83 ;
if ( args -> V_41 > V_247 )
args -> V_41 = V_247 ;
if ( args -> V_20 == 0 )
args -> V_20 = 1 ;
ASSERT ( F_126 ( V_69 , args -> V_254 ) < V_69 -> V_75 . V_255 ) ;
ASSERT ( F_127 ( V_69 , args -> V_254 ) < V_247 ) ;
ASSERT ( args -> V_21 <= args -> V_41 ) ;
ASSERT ( args -> V_21 <= V_247 ) ;
ASSERT ( args -> V_39 < args -> V_40 ) ;
if ( F_126 ( V_69 , args -> V_254 ) >= V_69 -> V_75 . V_255 ||
F_127 ( V_69 , args -> V_254 ) >= V_247 ||
args -> V_21 > args -> V_41 || args -> V_21 > V_247 ||
args -> V_39 >= args -> V_40 ) {
args -> V_254 = V_256 ;
F_128 ( args ) ;
return 0 ;
}
V_43 = args -> V_43 ;
switch ( type ) {
case V_109 :
case V_110 :
case V_111 :
args -> V_95 = F_126 ( V_69 , args -> V_254 ) ;
args -> V_103 = F_94 ( V_69 , args -> V_95 ) ;
args -> V_43 = 0 ;
error = F_100 ( args , 0 ) ;
args -> V_43 = V_43 ;
if ( error ) {
F_129 ( args ) ;
goto V_122;
}
if ( ! args -> V_44 ) {
F_130 ( args ) ;
break;
}
args -> V_46 = F_127 ( V_69 , args -> V_254 ) ;
if ( ( error = F_49 ( args ) ) )
goto V_122;
break;
case V_257 :
if ( ( args -> V_26 == V_258 ) &&
( V_69 -> V_259 & V_260 ) ) {
args -> V_254 = F_131 ( V_69 ,
( ( V_69 -> V_261 / V_251 ) %
V_69 -> V_75 . V_255 ) , 0 ) ;
V_249 = 1 ;
}
args -> V_46 = F_127 ( V_69 , args -> V_254 ) ;
args -> type = V_110 ;
case V_262 :
case V_263 :
case V_264 :
if ( type == V_262 ) {
args -> V_95 = V_248 = ( V_69 -> V_261 / V_251 ) %
V_69 -> V_75 . V_255 ;
args -> type = V_109 ;
V_52 = V_197 ;
} else if ( type == V_264 ) {
args -> V_95 = F_126 ( V_69 , args -> V_254 ) ;
args -> type = V_109 ;
V_248 = 0 ;
V_52 = 0 ;
} else {
if ( type == V_263 )
args -> type = V_109 ;
args -> V_95 = V_248 = F_126 ( V_69 , args -> V_254 ) ;
V_52 = V_197 ;
}
for (; ; ) {
args -> V_103 = F_94 ( V_69 , args -> V_95 ) ;
if ( V_250 ) args -> V_43 = 0 ;
error = F_100 ( args , V_52 ) ;
args -> V_43 = V_43 ;
if ( error ) {
F_129 ( args ) ;
goto V_122;
}
if ( args -> V_44 ) {
if ( ( error = F_49 ( args ) ) )
goto V_122;
break;
}
F_132 ( args ) ;
if ( args -> V_95 == V_248 &&
type == V_257 )
args -> type = V_109 ;
if ( ++ ( args -> V_95 ) == V_69 -> V_75 . V_255 ) {
if ( args -> V_265 != V_256 )
args -> V_95 = V_248 ;
else
args -> V_95 = 0 ;
}
if ( args -> V_95 == V_248 ) {
if ( V_250 == 1 ) {
args -> V_46 = V_36 ;
F_133 ( args ) ;
break;
}
if ( V_52 == 0 ) {
V_250 = 1 ;
} else {
V_52 = 0 ;
if ( type == V_257 ) {
args -> V_46 = F_127 ( V_69 ,
args -> V_254 ) ;
args -> type = V_110 ;
}
}
}
F_95 ( args -> V_103 ) ;
}
if ( V_249 || ( type == V_262 ) ) {
if ( args -> V_95 == V_248 )
V_69 -> V_261 = ( V_69 -> V_261 + 1 ) %
( V_69 -> V_75 . V_255 * V_251 ) ;
else
V_69 -> V_261 = ( args -> V_95 * V_251 + 1 ) %
( V_69 -> V_75 . V_255 * V_251 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_46 == V_36 )
args -> V_254 = V_256 ;
else {
args -> V_254 = F_131 ( V_69 , args -> V_95 , args -> V_46 ) ;
#ifdef F_21
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_41 ) ;
ASSERT ( args -> V_46 % args -> V_20 == 0 ) ;
F_134 ( V_69 , F_135 ( V_69 , args -> V_254 ) ,
args -> V_4 ) ;
#endif
}
F_95 ( args -> V_103 ) ;
return 0 ;
V_122:
F_95 ( args -> V_103 ) ;
return error ;
}
int
F_136 (
T_7 * V_94 ,
T_14 V_3 ,
T_2 V_4 )
{
T_3 args ;
int error ;
ASSERT ( V_4 != 0 ) ;
memset ( & args , 0 , sizeof( T_3 ) ) ;
args . V_94 = V_94 ;
args . V_69 = V_94 -> V_177 ;
args . V_95 = F_126 ( args . V_69 , V_3 ) ;
if ( args . V_95 >= args . V_69 -> V_75 . V_255 )
return - V_86 ;
args . V_46 = F_127 ( args . V_69 , V_3 ) ;
if ( args . V_46 >= args . V_69 -> V_75 . V_83 )
return - V_86 ;
args . V_103 = F_94 ( args . V_69 , args . V_95 ) ;
ASSERT ( args . V_103 ) ;
error = F_100 ( & args , V_198 ) ;
if ( error )
goto V_122;
if ( args . V_46 + V_4 >
F_10 ( F_19 ( args . V_44 ) -> V_106 ) ) {
error = - V_86 ;
goto V_122;
}
error = F_93 ( V_94 , args . V_44 , args . V_95 , args . V_46 , V_4 , 0 ) ;
if ( ! error )
F_137 ( V_94 , args . V_95 , args . V_46 , V_4 , 0 ) ;
V_122:
F_95 ( args . V_103 ) ;
return error ;
}
