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
T_1 V_26 ,
T_2 V_27 ,
T_1 * V_28 )
{
T_1 V_29 ;
T_1 V_30 ;
T_1 V_31 ;
T_2 V_32 = 0 ;
T_2 V_33 = 0 ;
T_1 V_34 ;
ASSERT ( V_27 >= V_25 ) ;
V_29 = V_26 + V_27 ;
V_34 = V_24 + V_25 ;
if ( V_26 >= V_24 ) {
if ( ( V_30 = F_13 ( V_26 , V_20 ) ) >= V_29 )
V_30 = V_35 ;
} else if ( V_29 >= V_34 && V_20 > 1 ) {
V_30 = F_13 ( V_24 , V_20 ) ;
V_31 = V_30 - V_20 ;
if ( V_30 >= V_29 )
V_30 = V_35 ;
else
V_32 = F_15 ( V_25 , V_29 - V_30 ) ;
if ( V_31 < V_26 )
V_31 = V_35 ;
else
V_33 = F_15 ( V_25 , V_29 - V_31 ) ;
if ( V_30 != V_35 && V_31 != V_35 ) {
if ( V_32 < V_33 ||
( V_32 == V_33 &&
F_16 ( V_30 , V_24 ) >
F_16 ( V_31 , V_24 ) ) )
V_30 = V_31 ;
} else if ( V_31 != V_35 )
V_30 = V_31 ;
} else if ( V_29 >= V_34 ) {
V_30 = V_24 ;
} else if ( V_20 > 1 ) {
V_30 = F_13 ( V_29 - V_25 , V_20 ) ;
if ( V_30 > V_29 - V_25 &&
V_30 - V_20 >= V_26 )
V_30 -= V_20 ;
else if ( V_30 >= V_29 )
V_30 = V_35 ;
} else
V_30 = V_29 - V_25 ;
* V_28 = V_30 ;
return V_30 == V_35 ? 0 : F_16 ( V_30 , V_24 ) ;
}
STATIC void
F_17 (
T_3 * args )
{
T_2 V_36 ;
T_2 V_37 ;
ASSERT ( args -> V_38 < args -> V_39 ) ;
V_37 = args -> V_4 ;
ASSERT ( V_37 >= args -> V_21 ) ;
ASSERT ( V_37 <= args -> V_40 ) ;
if ( args -> V_39 <= 1 || V_37 < args -> V_38 || V_37 == args -> V_40 ||
( args -> V_38 == 0 && V_37 < args -> V_39 ) )
return;
V_36 = V_37 % args -> V_39 ;
if ( V_36 == args -> V_38 )
return;
if ( V_36 > args -> V_38 ) {
if ( ( int ) ( V_37 = V_37 - V_36 - args -> V_38 ) < ( int ) args -> V_21 )
return;
} else {
if ( ( int ) ( V_37 = V_37 - args -> V_39 - ( args -> V_38 - V_36 ) ) <
( int ) args -> V_21 )
return;
}
ASSERT ( V_37 >= args -> V_21 ) ;
ASSERT ( V_37 <= args -> V_40 ) ;
args -> V_4 = V_37 ;
}
STATIC int
F_18 (
T_3 * args )
{
T_4 * V_41 ;
int V_23 ;
if ( args -> V_42 == 0 )
return 1 ;
V_41 = F_19 ( args -> V_43 ) ;
V_23 = F_10 ( V_41 -> V_44 )
- args -> V_4 - args -> V_42 ;
if ( V_23 >= 0 )
return 1 ;
args -> V_4 += V_23 ;
if ( args -> V_4 >= args -> V_21 )
return 1 ;
args -> V_45 = V_35 ;
return 0 ;
}
STATIC int
F_20 (
T_5 * V_46 ,
T_5 * V_47 ,
T_1 V_48 ,
T_2 V_49 ,
T_1 V_50 ,
T_2 V_37 ,
int V_51 )
{
int error ;
int V_52 ;
T_1 V_53 ;
T_1 V_54 ;
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
if ( V_51 & V_57 ) {
#ifdef F_21
if ( ( error = F_8 ( V_46 , & V_53 , & V_55 , & V_52 ) ) )
return error ;
F_22 (
V_52 == 1 && V_53 == V_48 && V_55 == V_49 ) ;
#endif
} else {
if ( ( error = F_1 ( V_46 , V_48 , V_49 , & V_52 ) ) )
return error ;
F_22 ( V_52 == 1 ) ;
}
if ( V_51 & V_58 ) {
#ifdef F_21
if ( ( error = F_8 ( V_47 , & V_53 , & V_55 , & V_52 ) ) )
return error ;
F_22 (
V_52 == 1 && V_53 == V_48 && V_55 == V_49 ) ;
#endif
} else {
if ( ( error = F_1 ( V_47 , V_48 , V_49 , & V_52 ) ) )
return error ;
F_22 ( V_52 == 1 ) ;
}
#ifdef F_21
if ( V_47 -> V_59 == 1 && V_46 -> V_59 == 1 ) {
struct V_60 * V_61 ;
struct V_60 * V_62 ;
V_61 = F_23 ( V_47 -> V_63 [ 0 ] ) ;
V_62 = F_23 ( V_46 -> V_63 [ 0 ] ) ;
F_22 (
V_61 -> V_64 == V_62 -> V_64 ) ;
}
#endif
if ( V_50 == V_48 && V_37 == V_49 )
V_53 = V_54 = V_35 ;
else if ( V_50 == V_48 ) {
V_53 = V_50 + V_37 ;
V_55 = V_49 - V_37 ;
V_54 = V_35 ;
} else if ( V_50 + V_37 == V_48 + V_49 ) {
V_53 = V_48 ;
V_55 = V_49 - V_37 ;
V_54 = V_35 ;
} else {
V_53 = V_48 ;
V_55 = V_50 - V_48 ;
V_54 = V_50 + V_37 ;
V_56 = ( V_48 + V_49 ) - V_54 ;
}
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
return error ;
F_22 ( V_52 == 1 ) ;
if ( V_53 != V_35 ) {
if ( ( error = F_1 ( V_46 , V_53 , V_55 , & V_52 ) ) )
return error ;
F_22 ( V_52 == 0 ) ;
if ( ( error = F_25 ( V_46 , & V_52 ) ) )
return error ;
F_22 ( V_52 == 1 ) ;
}
if ( V_54 != V_35 ) {
if ( ( error = F_1 ( V_46 , V_54 , V_56 , & V_52 ) ) )
return error ;
F_22 ( V_52 == 0 ) ;
if ( ( error = F_25 ( V_46 , & V_52 ) ) )
return error ;
F_22 ( V_52 == 1 ) ;
}
if ( V_53 == V_35 ) {
if ( ( error = F_24 ( V_47 , & V_52 ) ) )
return error ;
F_22 ( V_52 == 1 ) ;
} else {
if ( ( error = F_5 ( V_47 , V_53 , V_55 ) ) )
return error ;
}
if ( V_54 != V_35 ) {
if ( ( error = F_1 ( V_47 , V_54 , V_56 , & V_52 ) ) )
return error ;
F_22 ( V_52 == 0 ) ;
if ( ( error = F_25 ( V_47 , & V_52 ) ) )
return error ;
F_22 ( V_52 == 1 ) ;
}
return 0 ;
}
static bool
F_26 (
struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 -> V_70 ;
struct V_71 * V_72 = F_27 ( V_66 ) ;
int V_52 ;
if ( ! F_28 ( & V_72 -> V_73 , & V_68 -> V_74 . V_75 ) )
return false ;
if ( F_10 ( V_72 -> V_76 ) != V_77 )
return false ;
if ( V_66 -> V_78 && F_10 ( V_72 -> V_79 ) != V_66 -> V_78 -> V_80 )
return false ;
for ( V_52 = 0 ; V_52 < F_29 ( V_68 ) ; V_52 ++ ) {
if ( F_10 ( V_72 -> V_81 [ V_52 ] ) != V_35 &&
F_10 ( V_72 -> V_81 [ V_52 ] ) >= V_68 -> V_74 . V_82 )
return false ;
}
return true ;
}
static void
F_30 (
struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 -> V_70 ;
int V_83 = 1 ;
if ( ! F_31 ( & V_68 -> V_74 ) )
return;
V_83 = F_32 ( V_66 -> V_84 , F_33 ( V_66 -> V_85 ) ,
F_34 ( struct V_71 , V_86 ) ) ;
V_83 = V_83 && F_26 ( V_66 ) ;
if ( ! V_83 ) {
F_35 ( V_87 , V_88 , V_68 , V_66 -> V_84 ) ;
F_36 ( V_66 , V_89 ) ;
}
}
static void
F_37 (
struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 -> V_70 ;
struct V_90 * V_91 = V_66 -> V_92 ;
if ( ! F_31 ( & V_68 -> V_74 ) )
return;
if ( ! F_26 ( V_66 ) ) {
F_35 ( V_87 , V_88 , V_68 , V_66 -> V_84 ) ;
F_36 ( V_66 , V_89 ) ;
return;
}
if ( V_91 )
F_27 ( V_66 ) -> V_93 = F_38 ( V_91 -> V_94 . V_95 ) ;
F_39 ( V_66 -> V_84 , F_33 ( V_66 -> V_85 ) ,
F_34 ( struct V_71 , V_86 ) ) ;
}
STATIC int
F_40 (
T_6 * V_68 ,
T_7 * V_96 ,
T_8 V_97 ,
T_9 * * V_98 )
{
T_9 * V_66 ;
int error ;
ASSERT ( V_97 != V_99 ) ;
error = F_41 (
V_68 , V_96 , V_68 -> V_100 ,
F_42 ( V_68 , V_97 , F_43 ( V_68 ) ) ,
F_44 ( V_68 , 1 ) , 0 , & V_66 , & V_101 ) ;
if ( error )
return error ;
ASSERT ( ! F_45 ( V_66 ) ) ;
F_46 ( V_66 , V_102 ) ;
* V_98 = V_66 ;
return 0 ;
}
STATIC int
F_47 (
struct V_103 * V_96 ,
struct V_104 * V_105 ,
struct V_65 * V_43 ,
long V_4 )
{
struct V_106 * V_41 = F_19 ( V_43 ) ;
V_105 -> V_107 += V_4 ;
F_48 ( & V_41 -> V_44 , V_4 ) ;
F_49 ( V_96 , V_4 ) ;
if ( F_50 ( F_10 ( V_41 -> V_44 ) >
F_10 ( V_41 -> V_108 ) ) )
return V_89 ;
F_51 ( V_96 , V_43 , V_109 ) ;
return 0 ;
}
STATIC int
F_52 (
T_3 * args )
{
int error = 0 ;
ASSERT ( args -> V_21 > 0 ) ;
ASSERT ( args -> V_40 > 0 ) ;
ASSERT ( args -> V_21 <= args -> V_40 ) ;
ASSERT ( args -> V_38 < args -> V_39 ) ;
ASSERT ( args -> V_20 > 0 ) ;
args -> V_110 = 0 ;
switch ( args -> type ) {
case V_111 :
error = F_53 ( args ) ;
break;
case V_112 :
error = F_54 ( args ) ;
break;
case V_113 :
error = F_55 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error || args -> V_45 == V_35 )
return error ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_40 ) ;
ASSERT ( ! args -> V_110 || ! args -> V_114 ) ;
ASSERT ( args -> V_45 % args -> V_20 == 0 ) ;
if ( ! args -> V_110 ) {
error = F_47 ( args -> V_96 , args -> V_105 ,
args -> V_43 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_56 ( args -> V_68 , args -> V_97 ,
args -> V_45 , args -> V_4 ) ) ;
}
if ( ! args -> V_114 ) {
F_57 ( args -> V_96 , args -> V_115 ?
V_116 :
V_117 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
}
F_58 ( V_118 ) ;
F_59 ( V_119 , args -> V_4 ) ;
return error ;
}
STATIC int
F_55 (
T_3 * args )
{
T_5 * V_47 ;
T_5 * V_46 ;
int error ;
T_1 V_48 ;
T_2 V_49 ;
T_1 V_120 ;
T_2 V_121 ;
T_1 V_122 ;
int V_52 ;
ASSERT ( args -> V_20 == 1 ) ;
V_47 = F_60 ( args -> V_68 , args -> V_96 , args -> V_43 ,
args -> V_97 , V_123 ) ;
error = F_4 ( V_47 , args -> V_45 , args -> V_21 , & V_52 ) ;
if ( error )
goto V_124;
if ( ! V_52 )
goto V_125;
error = F_8 ( V_47 , & V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
ASSERT ( V_48 <= args -> V_45 ) ;
F_12 ( args , V_48 , V_49 , & V_120 , & V_121 ) ;
if ( V_120 > args -> V_45 )
goto V_125;
if ( V_121 < args -> V_21 )
goto V_125;
V_122 = V_120 + V_121 ;
if ( V_122 < args -> V_45 + args -> V_21 )
goto V_125;
args -> V_4 = F_62 ( V_122 , args -> V_45 + args -> V_40 )
- args -> V_45 ;
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_125;
ASSERT ( args -> V_45 + args -> V_4 <= V_122 ) ;
V_46 = F_60 ( args -> V_68 , args -> V_96 , args -> V_43 ,
args -> V_97 , V_126 ) ;
ASSERT ( args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_108 ) ) ;
error = F_20 ( V_46 , V_47 , V_48 , V_49 , args -> V_45 ,
args -> V_4 , V_58 ) ;
if ( error ) {
F_63 ( V_46 , V_127 ) ;
goto V_124;
}
F_63 ( V_47 , V_128 ) ;
F_63 ( V_46 , V_128 ) ;
args -> V_110 = 0 ;
F_64 ( args ) ;
return 0 ;
V_125:
F_63 ( V_47 , V_128 ) ;
args -> V_45 = V_35 ;
F_65 ( args ) ;
return 0 ;
V_124:
F_63 ( V_47 , V_127 ) ;
F_66 ( args ) ;
return error ;
}
STATIC int
F_67 (
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
int V_52 ;
if ( ! V_132 )
goto V_140;
do {
error = F_8 ( * V_131 , V_133 , V_134 , & V_52 ) ;
if ( error )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
F_11 ( args , * V_133 , * V_134 , V_135 , V_136 ) ;
if ( ! V_137 ) {
if ( * V_135 >= args -> V_45 + V_132 )
goto V_140;
} else {
if ( * V_135 <= args -> V_45 - V_132 )
goto V_140;
}
if ( * V_136 >= args -> V_21 ) {
args -> V_4 = F_15 ( * V_136 , args -> V_40 ) ;
F_17 ( args ) ;
V_139 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , * V_135 ,
* V_136 , & V_138 ) ;
if ( V_139 < V_132 )
goto V_141;
goto V_140;
}
if ( ! V_137 )
error = F_68 ( * V_131 , 0 , & V_52 ) ;
else
error = F_69 ( * V_131 , 0 , & V_52 ) ;
if ( error )
goto V_124;
} while ( V_52 );
V_140:
F_63 ( * V_131 , V_128 ) ;
* V_131 = NULL ;
return 0 ;
V_141:
F_63 ( * V_130 , V_128 ) ;
* V_130 = NULL ;
return 0 ;
V_124:
return error ;
}
STATIC int
F_54 (
T_3 * args )
{
T_5 * V_142 ;
T_5 * V_143 ;
T_5 * V_46 ;
T_1 V_144 ;
T_1 V_145 ;
T_2 V_146 ;
T_2 V_147 ;
T_2 V_148 ;
T_1 V_149 ;
int error ;
int V_52 ;
int V_150 ;
T_1 V_151 ;
T_1 V_152 ;
T_2 V_153 ;
T_2 V_154 ;
T_2 V_155 ;
T_1 V_156 ;
T_2 V_37 ;
int V_157 = 0 ;
#if F_70 ( F_21 ) && F_70 ( V_158 )
int V_159 ;
V_159 = F_71 () & 1 ;
#endif
V_160:
V_143 = NULL ;
V_142 = NULL ;
V_154 = 0 ;
V_148 = 0 ;
V_155 = 0 ;
V_46 = F_60 ( args -> V_68 , args -> V_96 , args -> V_43 ,
args -> V_97 , V_126 ) ;
if ( ( error = F_3 ( V_46 , 0 , args -> V_40 , & V_52 ) ) )
goto V_124;
if ( ! V_52 ) {
if ( ( error = F_72 ( args , V_46 , & V_151 ,
& V_154 , & V_52 ) ) )
goto V_124;
if ( V_52 == 0 || V_154 == 0 ) {
F_63 ( V_46 , V_128 ) ;
F_73 ( args ) ;
return 0 ;
}
ASSERT ( V_52 == 1 ) ;
}
args -> V_110 = 0 ;
while ( F_74 ( V_46 , 0 ) ) {
T_2 V_161 ;
int V_162 = 0 ;
T_2 V_163 = 0 ;
T_1 V_164 = 0 ;
#if F_70 ( F_21 ) && F_70 ( V_158 )
if ( ! V_159 )
break;
#endif
if ( V_154 || args -> V_20 > 1 ) {
V_46 -> V_165 [ 0 ] = 1 ;
do {
if ( ( error = F_8 ( V_46 , & V_151 ,
& V_154 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( V_154 >= args -> V_21 )
break;
if ( ( error = F_68 ( V_46 , 0 , & V_52 ) ) )
goto V_124;
} while ( V_52 );
ASSERT ( V_154 >= args -> V_21 ) ;
if ( ! V_52 )
break;
}
V_52 = V_46 -> V_165 [ 0 ] ;
for ( V_150 = 1 , V_163 = 0 , V_161 = 0 ;
! error && V_150 && ( V_163 < args -> V_40 || V_161 > 0 ) ;
error = F_68 ( V_46 , 0 , & V_150 ) ) {
if ( ( error = F_8 ( V_46 , & V_151 , & V_154 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
F_11 ( args , V_151 , V_154 ,
& V_152 , & V_155 ) ;
if ( V_155 < args -> V_21 )
continue;
args -> V_4 = F_15 ( V_155 , args -> V_40 ) ;
F_17 ( args ) ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
if ( args -> V_4 < V_163 )
continue;
V_153 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_152 , V_155 , & V_156 ) ;
if ( V_156 != V_35 &&
( args -> V_4 > V_163 || V_153 < V_161 ) ) {
V_161 = V_153 ;
V_164 = V_156 ;
V_163 = args -> V_4 ;
V_162 = V_46 -> V_165 [ 0 ] ;
}
}
if ( V_163 == 0 )
break;
V_46 -> V_165 [ 0 ] = V_162 ;
if ( ( error = F_8 ( V_46 , & V_151 , & V_154 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
ASSERT ( V_151 + V_154 <= F_10 ( F_19 ( args -> V_43 ) -> V_108 ) ) ;
args -> V_4 = V_163 ;
if ( ! F_18 ( args ) ) {
F_63 ( V_46 , V_128 ) ;
F_75 ( args ) ;
return 0 ;
}
V_163 = args -> V_4 ;
args -> V_45 = V_164 ;
ASSERT ( V_164 >= V_151 ) ;
ASSERT ( V_164 + V_163 <= V_151 + V_154 ) ;
V_143 = F_60 ( args -> V_68 , args -> V_96 ,
args -> V_43 , args -> V_97 , V_123 ) ;
if ( ( error = F_20 ( V_46 , V_143 , V_151 ,
V_154 , V_164 , V_163 , V_57 ) ) )
goto V_124;
F_63 ( V_46 , V_128 ) ;
F_63 ( V_143 , V_128 ) ;
F_76 ( args ) ;
return 0 ;
}
V_143 = F_60 ( args -> V_68 , args -> V_96 , args -> V_43 ,
args -> V_97 , V_123 ) ;
if ( ( error = F_4 ( V_143 , args -> V_45 , args -> V_40 , & V_52 ) ) )
goto V_124;
if ( ! V_52 ) {
V_142 = V_143 ;
V_143 = NULL ;
}
else if ( ( error = F_77 ( V_143 , & V_142 ) ) )
goto V_124;
if ( ( error = F_68 ( V_142 , 0 , & V_52 ) ) )
goto V_124;
if ( ! V_52 ) {
F_63 ( V_142 , V_128 ) ;
V_142 = NULL ;
}
do {
if ( V_143 ) {
if ( ( error = F_8 ( V_143 , & V_151 , & V_154 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
F_11 ( args , V_151 , V_154 ,
& V_152 , & V_155 ) ;
if ( V_155 >= args -> V_21 )
break;
if ( ( error = F_69 ( V_143 , 0 , & V_52 ) ) )
goto V_124;
if ( ! V_52 ) {
F_63 ( V_143 ,
V_128 ) ;
V_143 = NULL ;
}
}
if ( V_142 ) {
if ( ( error = F_8 ( V_142 , & V_144 , & V_147 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
F_11 ( args , V_144 , V_147 ,
& V_145 , & V_148 ) ;
if ( V_148 >= args -> V_21 )
break;
if ( ( error = F_68 ( V_142 , 0 , & V_52 ) ) )
goto V_124;
if ( ! V_52 ) {
F_63 ( V_142 ,
V_128 ) ;
V_142 = NULL ;
}
}
} while ( V_143 || V_142 );
if ( V_143 && V_142 ) {
if ( V_155 >= args -> V_21 ) {
args -> V_4 = F_15 ( V_155 , args -> V_40 ) ;
F_17 ( args ) ;
V_153 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_152 , V_155 , & V_156 ) ;
error = F_67 ( args ,
& V_143 , & V_142 ,
V_153 , & V_144 , & V_147 ,
& V_145 , & V_148 ,
0 ) ;
} else {
ASSERT ( V_148 >= args -> V_21 ) ;
args -> V_4 = F_15 ( V_148 , args -> V_40 ) ;
F_17 ( args ) ;
V_146 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_145 , V_148 , & V_149 ) ;
error = F_67 ( args ,
& V_142 , & V_143 ,
V_146 , & V_151 , & V_154 ,
& V_152 , & V_155 ,
1 ) ;
}
if ( error )
goto V_124;
}
if ( V_143 == NULL && V_142 == NULL ) {
F_63 ( V_46 , V_128 ) ;
if ( ! V_157 ++ ) {
F_78 ( args ) ;
F_79 ( args -> V_68 , V_166 ) ;
goto V_160;
}
F_80 ( args ) ;
args -> V_45 = V_35 ;
return 0 ;
}
if ( V_142 ) {
V_143 = V_142 ;
V_142 = NULL ;
V_151 = V_144 ;
V_152 = V_145 ;
V_154 = V_147 ;
V_155 = V_148 ;
V_150 = 1 ;
} else
V_150 = 0 ;
args -> V_4 = F_15 ( V_155 , args -> V_40 ) ;
F_17 ( args ) ;
if ( ! F_18 ( args ) ) {
F_75 ( args ) ;
F_63 ( V_143 , V_128 ) ;
F_63 ( V_46 , V_128 ) ;
return 0 ;
}
V_37 = args -> V_4 ;
( void ) F_14 ( args -> V_45 , V_37 , args -> V_20 ,
V_152 , V_155 , & V_156 ) ;
ASSERT ( V_156 >= V_151 ) ;
ASSERT ( V_156 + V_37 <= V_152 + V_155 ) ;
ASSERT ( V_156 + V_37 <= F_10 ( F_19 ( args -> V_43 ) -> V_108 ) ) ;
args -> V_45 = V_156 ;
if ( ( error = F_20 ( V_46 , V_143 , V_151 , V_154 ,
V_156 , V_37 , V_58 ) ) )
goto V_124;
if ( V_150 )
F_81 ( args ) ;
else
F_82 ( args ) ;
F_63 ( V_46 , V_128 ) ;
F_63 ( V_143 , V_128 ) ;
return 0 ;
V_124:
F_83 ( args ) ;
if ( V_46 != NULL )
F_63 ( V_46 , V_127 ) ;
if ( V_143 != NULL )
F_63 ( V_143 , V_127 ) ;
if ( V_142 != NULL )
F_63 ( V_142 , V_127 ) ;
return error ;
}
STATIC int
F_53 (
T_3 * args )
{
T_5 * V_47 ;
T_5 * V_46 ;
int error ;
T_1 V_48 ;
T_2 V_49 ;
int V_52 ;
T_1 V_50 ;
T_2 V_37 ;
int V_157 = 0 ;
V_160:
V_46 = F_60 ( args -> V_68 , args -> V_96 , args -> V_43 ,
args -> V_97 , V_126 ) ;
V_47 = NULL ;
if ( ( error = F_3 ( V_46 , 0 ,
args -> V_40 + args -> V_20 - 1 , & V_52 ) ) )
goto V_124;
if ( ! V_52 || V_157 > 1 ) {
error = F_72 ( args , V_46 ,
& V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_124;
if ( V_52 == 0 || V_49 == 0 ) {
F_63 ( V_46 , V_128 ) ;
F_84 ( args ) ;
return 0 ;
}
ASSERT ( V_52 == 1 ) ;
F_11 ( args , V_48 , V_49 , & V_50 , & V_37 ) ;
} else {
for (; ; ) {
error = F_8 ( V_46 , & V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
F_11 ( args , V_48 , V_49 ,
& V_50 , & V_37 ) ;
if ( V_37 >= args -> V_40 )
break;
error = F_68 ( V_46 , 0 , & V_52 ) ;
if ( error )
goto V_124;
if ( V_52 == 0 ) {
F_63 ( V_46 ,
V_128 ) ;
F_85 ( args ) ;
if ( ! V_157 ++ )
F_79 ( args -> V_68 , V_166 ) ;
goto V_160;
}
}
}
V_37 = F_15 ( args -> V_40 , V_37 ) ;
F_61 ( V_37 == 0 ||
( V_37 <= V_49 && V_50 + V_37 <= V_48 + V_49 ) , V_124 ) ;
if ( V_37 < args -> V_40 ) {
T_1 V_167 ;
T_2 V_168 ;
T_1 V_169 ;
T_2 V_170 ;
V_170 = V_37 ;
V_169 = V_50 ;
V_168 = V_49 ;
V_167 = V_48 ;
for (; ; ) {
if ( ( error = F_69 ( V_46 , 0 , & V_52 ) ) )
goto V_124;
if ( V_52 == 0 )
break;
if ( ( error = F_8 ( V_46 , & V_48 , & V_49 ,
& V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( V_49 < V_170 )
break;
F_11 ( args , V_48 , V_49 ,
& V_50 , & V_37 ) ;
V_37 = F_15 ( args -> V_40 , V_37 ) ;
F_61 ( V_37 == 0 ||
( V_37 <= V_49 && V_50 + V_37 <= V_48 + V_49 ) ,
V_124 ) ;
if ( V_37 > V_170 ) {
V_170 = V_37 ;
V_169 = V_50 ;
V_168 = V_49 ;
V_167 = V_48 ;
if ( V_37 == args -> V_40 )
break;
}
}
if ( ( error = F_1 ( V_46 , V_167 , V_168 ,
& V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
V_37 = V_170 ;
V_50 = V_169 ;
V_49 = V_168 ;
V_48 = V_167 ;
}
args -> V_110 = 0 ;
args -> V_4 = V_37 ;
if ( V_37 < args -> V_21 ) {
if ( ! V_157 ++ ) {
F_63 ( V_46 , V_128 ) ;
F_85 ( args ) ;
F_79 ( args -> V_68 , V_166 ) ;
goto V_160;
}
goto V_171;
}
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_171;
V_37 = args -> V_4 ;
F_61 ( V_37 <= V_49 , V_124 ) ;
V_47 = F_60 ( args -> V_68 , args -> V_96 , args -> V_43 ,
args -> V_97 , V_123 ) ;
if ( ( error = F_20 ( V_46 , V_47 , V_48 , V_49 ,
V_50 , V_37 , V_57 ) ) )
goto V_124;
F_63 ( V_46 , V_128 ) ;
F_63 ( V_47 , V_128 ) ;
V_46 = V_47 = NULL ;
args -> V_4 = V_37 ;
args -> V_45 = V_50 ;
F_61 (
args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_108 ) ,
V_124 ) ;
F_86 ( args ) ;
return 0 ;
V_124:
F_87 ( args ) ;
if ( V_46 )
F_63 ( V_46 , V_127 ) ;
if ( V_47 )
F_63 ( V_47 , V_127 ) ;
return error ;
V_171:
F_63 ( V_46 , V_128 ) ;
F_88 ( args ) ;
args -> V_45 = V_35 ;
return 0 ;
}
STATIC int
F_72 (
T_3 * args ,
T_5 * V_172 ,
T_1 * V_173 ,
T_2 * V_174 ,
int * V_5 )
{
int error ;
T_1 V_48 ;
T_2 V_49 ;
int V_52 ;
if ( ( error = F_69 ( V_172 , 0 , & V_52 ) ) )
goto V_124;
if ( V_52 ) {
if ( ( error = F_8 ( V_172 , & V_48 , & V_49 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
}
else if ( args -> V_21 == 1 && args -> V_20 == 1 && ! args -> V_114 &&
( F_10 ( F_19 ( args -> V_43 ) -> V_175 )
> args -> V_42 ) ) {
error = F_89 ( args -> V_96 , args -> V_43 , & V_48 , 0 ) ;
if ( error )
goto V_124;
if ( V_48 != V_35 ) {
F_90 ( args -> V_68 , args -> V_97 , V_48 , 1 ,
args -> V_176 ) ;
if ( args -> V_176 ) {
T_9 * V_66 ;
V_66 = F_91 ( args -> V_68 , args -> V_96 ,
args -> V_97 , V_48 , 0 ) ;
F_92 ( args -> V_96 , V_66 ) ;
}
args -> V_4 = 1 ;
args -> V_45 = V_48 ;
F_61 (
args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_108 ) ,
V_124 ) ;
args -> V_110 = 1 ;
F_93 ( args ) ;
* V_5 = 0 ;
return 0 ;
}
else
V_49 = 0 ;
}
else {
V_48 = V_35 ;
V_49 = 0 ;
}
if ( V_49 < args -> V_21 ) {
args -> V_45 = V_35 ;
F_94 ( args ) ;
V_49 = 0 ;
}
* V_173 = V_48 ;
* V_174 = V_49 ;
* V_5 = 1 ;
F_95 ( args ) ;
return 0 ;
V_124:
F_96 ( args ) ;
return error ;
}
STATIC int
F_97 (
T_7 * V_96 ,
T_9 * V_43 ,
T_8 V_97 ,
T_1 V_3 ,
T_2 V_4 ,
int V_114 )
{
T_5 * V_47 ;
T_5 * V_46 ;
int error ;
T_1 V_144 ;
T_2 V_147 ;
int V_177 ;
int V_178 ;
int V_52 ;
T_1 V_151 ;
T_2 V_154 ;
T_6 * V_68 ;
T_1 V_179 ;
T_2 V_180 ;
T_10 * V_105 ;
V_68 = V_96 -> V_181 ;
V_47 = F_60 ( V_68 , V_96 , V_43 , V_97 , V_123 ) ;
V_46 = NULL ;
if ( ( error = F_4 ( V_47 , V_3 , V_4 , & V_177 ) ) )
goto V_124;
if ( V_177 ) {
if ( ( error = F_8 ( V_47 , & V_151 , & V_154 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( V_151 + V_154 < V_3 )
V_177 = 0 ;
else {
F_61 ( V_151 + V_154 <= V_3 , V_124 ) ;
}
}
if ( ( error = F_68 ( V_47 , 0 , & V_178 ) ) )
goto V_124;
if ( V_178 ) {
if ( ( error = F_8 ( V_47 , & V_144 , & V_147 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( V_3 + V_4 < V_144 )
V_178 = 0 ;
else {
F_61 ( V_144 >= V_3 + V_4 , V_124 ) ;
}
}
V_46 = F_60 ( V_68 , V_96 , V_43 , V_97 , V_126 ) ;
if ( V_177 && V_178 ) {
if ( ( error = F_1 ( V_46 , V_151 , V_154 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( ( error = F_1 ( V_46 , V_144 , V_147 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( ( error = F_24 ( V_47 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( ( error = F_69 ( V_47 , 0 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
#ifdef F_21
{
T_1 V_182 ;
T_2 V_183 ;
if ( ( error = F_8 ( V_47 , & V_182 , & V_183 ,
& V_52 ) ) )
goto V_124;
F_61 (
V_52 == 1 && V_182 == V_151 && V_183 == V_154 ,
V_124 ) ;
}
#endif
V_179 = V_151 ;
V_180 = V_4 + V_154 + V_147 ;
if ( ( error = F_5 ( V_47 , V_179 , V_180 ) ) )
goto V_124;
}
else if ( V_177 ) {
if ( ( error = F_1 ( V_46 , V_151 , V_154 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( ( error = F_69 ( V_47 , 0 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
V_179 = V_151 ;
V_180 = V_4 + V_154 ;
if ( ( error = F_5 ( V_47 , V_179 , V_180 ) ) )
goto V_124;
}
else if ( V_178 ) {
if ( ( error = F_1 ( V_46 , V_144 , V_147 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
V_179 = V_3 ;
V_180 = V_4 + V_147 ;
if ( ( error = F_5 ( V_47 , V_179 , V_180 ) ) )
goto V_124;
}
else {
V_179 = V_3 ;
V_180 = V_4 ;
if ( ( error = F_25 ( V_47 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
}
F_63 ( V_47 , V_128 ) ;
V_47 = NULL ;
if ( ( error = F_1 ( V_46 , V_179 , V_180 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 0 , V_124 ) ;
if ( ( error = F_25 ( V_46 , & V_52 ) ) )
goto V_124;
F_61 ( V_52 == 1 , V_124 ) ;
F_63 ( V_46 , V_128 ) ;
V_46 = NULL ;
V_105 = F_98 ( V_68 , V_97 ) ;
error = F_47 ( V_96 , V_105 , V_43 , V_4 ) ;
F_99 ( V_105 ) ;
if ( error )
goto V_124;
if ( ! V_114 )
F_57 ( V_96 , V_117 , ( long ) V_4 ) ;
F_58 ( V_184 ) ;
F_59 ( V_185 , V_4 ) ;
F_100 ( V_68 , V_97 , V_3 , V_4 , V_114 , V_177 , V_178 ) ;
return 0 ;
V_124:
F_100 ( V_68 , V_97 , V_3 , V_4 , V_114 , - 1 , - 1 ) ;
if ( V_47 )
F_63 ( V_47 , V_127 ) ;
if ( V_46 )
F_63 ( V_46 , V_127 ) ;
return error ;
}
void
F_101 (
T_6 * V_68 )
{
int V_186 ;
T_11 V_187 ;
T_11 V_188 ;
int V_189 ;
int V_190 ;
V_188 = ( V_68 -> V_74 . V_82 + 1 ) / 2 ;
V_189 = V_68 -> V_191 [ 0 ] ;
V_190 = V_68 -> V_191 [ 1 ] ;
V_187 = ( V_188 + V_189 - 1 ) / V_189 ;
for ( V_186 = 1 ; V_187 > 1 ; V_186 ++ )
V_187 = ( V_187 + V_190 - 1 ) / V_190 ;
V_68 -> V_192 = V_186 ;
}
T_2
F_102 (
struct V_67 * V_68 ,
struct V_104 * V_105 )
{
T_2 V_193 , V_194 = 0 ;
V_193 = F_103 ( V_105 , V_68 ) ;
if ( V_193 > V_105 -> V_195 )
V_194 = V_193 - V_105 -> V_195 ;
if ( V_105 -> V_196 > V_194 )
return V_105 -> V_196 - V_194 ;
return V_105 -> V_195 > 0 || V_105 -> V_196 > 0 ;
}
STATIC int
F_104 (
T_3 * args ,
int V_51 )
{
T_9 * V_43 ;
T_4 * V_41 ;
T_9 * V_197 ;
T_1 V_3 ;
T_2 V_194 ;
int error ;
T_2 V_198 ;
T_6 * V_68 ;
T_2 V_193 ;
T_10 * V_105 ;
T_3 V_199 ;
T_7 * V_96 ;
V_68 = args -> V_68 ;
V_105 = args -> V_105 ;
V_96 = args -> V_96 ;
if ( ! V_105 -> V_200 ) {
if ( ( error = F_105 ( V_68 , V_96 , args -> V_97 , V_51 ,
& V_43 ) ) )
return error ;
if ( ! V_105 -> V_200 ) {
ASSERT ( V_51 & V_201 ) ;
ASSERT ( ! ( V_51 & V_202 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
} else
V_43 = NULL ;
if ( V_105 -> V_203 && args -> V_176 &&
( V_51 & V_201 ) ) {
ASSERT ( ! ( V_51 & V_202 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
if ( ! ( V_51 & V_202 ) ) {
V_193 = F_103 ( V_105 , V_68 ) ;
V_198 = F_102 ( V_68 , V_105 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_204 - 1 ) >
V_198 ||
( ( int ) ( V_105 -> V_107 + V_105 -> V_195 -
V_193 - args -> V_205 ) < ( int ) args -> V_42 ) ) {
if ( V_43 )
F_106 ( V_96 , V_43 ) ;
args -> V_43 = NULL ;
return 0 ;
}
}
if ( V_43 == NULL ) {
if ( ( error = F_105 ( V_68 , V_96 , args -> V_97 , V_51 ,
& V_43 ) ) )
return error ;
if ( V_43 == NULL ) {
ASSERT ( V_51 & V_201 ) ;
ASSERT ( ! ( V_51 & V_202 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
}
V_41 = F_19 ( V_43 ) ;
V_193 = F_107 ( V_41 , V_68 ) ;
if ( ! ( V_51 & V_202 ) ) {
V_194 = V_193 > F_10 ( V_41 -> V_175 ) ?
( V_193 - F_10 ( V_41 -> V_175 ) ) : 0 ;
V_198 = F_10 ( V_41 -> V_206 ) ;
V_198 = ( V_198 > V_194 ) ? ( V_198 - V_194 ) :
( F_10 ( V_41 -> V_175 ) > 0 || V_198 > 0 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_204 - 1 ) >
V_198 ||
( ( int ) ( F_10 ( V_41 -> V_44 ) +
F_10 ( V_41 -> V_175 ) - V_193 - args -> V_205 ) <
( int ) args -> V_42 ) ) {
F_106 ( V_96 , V_43 ) ;
args -> V_43 = NULL ;
return 0 ;
}
}
while ( F_10 ( V_41 -> V_175 ) > V_193 ) {
T_9 * V_66 ;
error = F_89 ( V_96 , V_43 , & V_3 , 0 ) ;
if ( error )
return error ;
if ( ( error = F_97 ( V_96 , V_43 , args -> V_97 , V_3 , 1 , 1 ) ) )
return error ;
V_66 = F_91 ( V_68 , V_96 , args -> V_97 , V_3 , 0 ) ;
F_92 ( V_96 , V_66 ) ;
}
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
V_199 . V_96 = V_96 ;
V_199 . V_68 = V_68 ;
V_199 . V_43 = V_43 ;
V_199 . V_97 = args -> V_97 ;
V_199 . V_20 = V_199 . V_21 = V_199 . V_39 = V_199 . V_114 = 1 ;
V_199 . type = V_111 ;
V_199 . V_105 = V_105 ;
if ( ( error = F_40 ( V_68 , V_96 , V_199 . V_97 , & V_197 ) ) )
return error ;
while ( F_10 ( V_41 -> V_175 ) < V_193 ) {
V_199 . V_45 = 0 ;
V_199 . V_40 = V_193 - F_10 ( V_41 -> V_175 ) ;
if ( ( error = F_52 ( & V_199 ) ) ) {
F_106 ( V_96 , V_197 ) ;
return error ;
}
if ( V_199 . V_45 == V_35 ) {
if ( V_51 & V_202 )
break;
F_106 ( V_96 , V_197 ) ;
args -> V_43 = NULL ;
return 0 ;
}
for ( V_3 = V_199 . V_45 ; V_3 < V_199 . V_45 + V_199 . V_4 ; V_3 ++ ) {
error = F_108 ( V_96 , V_43 ,
V_197 , V_3 , 0 ) ;
if ( error )
return error ;
}
}
F_106 ( V_96 , V_197 ) ;
args -> V_43 = V_43 ;
return 0 ;
}
int
F_89 (
T_7 * V_96 ,
T_9 * V_43 ,
T_1 * V_207 ,
int V_208 )
{
T_4 * V_41 ;
T_9 * V_197 ;
T_1 V_3 ;
T_12 * V_81 ;
int error ;
int V_209 ;
T_6 * V_68 = V_96 -> V_181 ;
T_10 * V_105 ;
V_41 = F_19 ( V_43 ) ;
if ( ! V_41 -> V_175 ) {
* V_207 = V_35 ;
return 0 ;
}
error = F_40 ( V_68 , V_96 , F_10 ( V_41 -> V_210 ) ,
& V_197 ) ;
if ( error )
return error ;
V_81 = F_109 ( V_68 , V_197 ) ;
V_3 = F_10 ( V_81 [ F_10 ( V_41 -> V_211 ) ] ) ;
F_48 ( & V_41 -> V_211 , 1 ) ;
F_106 ( V_96 , V_197 ) ;
if ( F_10 ( V_41 -> V_211 ) == F_29 ( V_68 ) )
V_41 -> V_211 = 0 ;
V_105 = F_98 ( V_68 , F_10 ( V_41 -> V_210 ) ) ;
F_48 ( & V_41 -> V_175 , - 1 ) ;
F_110 ( V_96 , - 1 ) ;
V_105 -> V_195 -- ;
F_99 ( V_105 ) ;
V_209 = V_212 | V_213 ;
if ( V_208 ) {
F_48 ( & V_41 -> V_214 , 1 ) ;
V_105 -> V_215 ++ ;
V_209 |= V_216 ;
}
F_51 ( V_96 , V_43 , V_209 ) ;
* V_207 = V_3 ;
return 0 ;
}
void
F_51 (
T_7 * V_96 ,
T_9 * V_66 ,
int V_217 )
{
int V_218 ;
int V_219 ;
static const short V_220 [] = {
F_34 ( T_4 , V_221 ) ,
F_34 ( T_4 , V_222 ) ,
F_34 ( T_4 , V_210 ) ,
F_34 ( T_4 , V_108 ) ,
F_34 ( T_4 , V_223 [ 0 ] ) ,
F_34 ( T_4 , V_224 [ 0 ] ) ,
F_34 ( T_4 , V_211 ) ,
F_34 ( T_4 , V_225 ) ,
F_34 ( T_4 , V_175 ) ,
F_34 ( T_4 , V_44 ) ,
F_34 ( T_4 , V_206 ) ,
F_34 ( T_4 , V_214 ) ,
F_34 ( T_4 , V_226 ) ,
sizeof( T_4 )
} ;
F_111 ( V_96 -> V_181 , F_19 ( V_66 ) , V_217 , V_227 ) ;
F_112 ( V_96 , V_66 , V_228 ) ;
F_113 ( V_217 , V_220 , V_229 , & V_218 , & V_219 ) ;
F_114 ( V_96 , V_66 , ( T_11 ) V_218 , ( T_11 ) V_219 ) ;
}
int
F_115 (
T_6 * V_68 ,
T_7 * V_96 ,
T_8 V_97 ,
int V_51 )
{
T_9 * V_66 ;
int error ;
if ( ( error = F_105 ( V_68 , V_96 , V_97 , V_51 , & V_66 ) ) )
return error ;
if ( V_66 )
F_106 ( V_96 , V_66 ) ;
return 0 ;
}
int
F_108 (
T_7 * V_96 ,
T_9 * V_43 ,
T_9 * V_197 ,
T_1 V_3 ,
int V_208 )
{
T_4 * V_41 ;
T_12 * V_230 ;
int error ;
int V_209 ;
T_6 * V_68 ;
T_10 * V_105 ;
T_12 * V_81 ;
int V_231 ;
V_41 = F_19 ( V_43 ) ;
V_68 = V_96 -> V_181 ;
if ( ! V_197 && ( error = F_40 ( V_68 , V_96 ,
F_10 ( V_41 -> V_210 ) , & V_197 ) ) )
return error ;
F_48 ( & V_41 -> V_225 , 1 ) ;
if ( F_10 ( V_41 -> V_225 ) == F_29 ( V_68 ) )
V_41 -> V_225 = 0 ;
V_105 = F_98 ( V_68 , F_10 ( V_41 -> V_210 ) ) ;
F_48 ( & V_41 -> V_175 , 1 ) ;
F_110 ( V_96 , 1 ) ;
V_105 -> V_195 ++ ;
V_209 = V_232 | V_213 ;
if ( V_208 ) {
F_48 ( & V_41 -> V_214 , - 1 ) ;
V_105 -> V_215 -- ;
V_209 |= V_216 ;
}
F_99 ( V_105 ) ;
F_51 ( V_96 , V_43 , V_209 ) ;
ASSERT ( F_10 ( V_41 -> V_175 ) <= F_29 ( V_68 ) ) ;
V_81 = F_109 ( V_68 , V_197 ) ;
V_230 = & V_81 [ F_10 ( V_41 -> V_225 ) ] ;
* V_230 = F_6 ( V_3 ) ;
V_231 = ( char * ) V_230 - ( char * ) V_197 -> V_84 ;
F_51 ( V_96 , V_43 , V_209 ) ;
F_112 ( V_96 , V_197 , V_233 ) ;
F_114 ( V_96 , V_197 , V_231 ,
V_231 + sizeof( T_1 ) - 1 ) ;
return 0 ;
}
static bool
F_116 (
struct V_67 * V_68 ,
struct V_65 * V_66 )
{
struct V_106 * V_41 = F_19 ( V_66 ) ;
if ( F_31 ( & V_68 -> V_74 ) &&
! F_28 ( & V_41 -> V_226 , & V_68 -> V_74 . V_75 ) )
return false ;
if ( ! ( V_41 -> V_221 == F_6 ( V_234 ) &&
F_117 ( F_10 ( V_41 -> V_222 ) ) &&
F_10 ( V_41 -> V_44 ) <= F_10 ( V_41 -> V_108 ) &&
F_10 ( V_41 -> V_211 ) < F_29 ( V_68 ) &&
F_10 ( V_41 -> V_225 ) < F_29 ( V_68 ) &&
F_10 ( V_41 -> V_175 ) <= F_29 ( V_68 ) ) )
return false ;
if ( V_66 -> V_78 && F_10 ( V_41 -> V_210 ) != V_66 -> V_78 -> V_80 )
return false ;
if ( F_118 ( & V_68 -> V_74 ) &&
F_10 ( V_41 -> V_214 ) > F_10 ( V_41 -> V_108 ) )
return false ;
return true ; ;
}
static void
F_119 (
struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 -> V_70 ;
int V_235 = 1 ;
if ( F_31 ( & V_68 -> V_74 ) )
V_235 = F_32 ( V_66 -> V_84 , F_33 ( V_66 -> V_85 ) ,
F_34 ( struct V_106 , V_236 ) ) ;
V_235 = V_235 && F_116 ( V_68 , V_66 ) ;
if ( F_50 ( F_120 ( ! V_235 , V_68 , V_237 ,
V_238 ) ) ) {
F_35 ( V_87 , V_88 , V_68 , V_66 -> V_84 ) ;
F_36 ( V_66 , V_89 ) ;
}
}
static void
F_121 (
struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 -> V_70 ;
struct V_90 * V_91 = V_66 -> V_92 ;
if ( ! F_116 ( V_68 , V_66 ) ) {
F_35 ( V_87 , V_88 , V_68 , V_66 -> V_84 ) ;
F_36 ( V_66 , V_89 ) ;
return;
}
if ( ! F_31 ( & V_68 -> V_74 ) )
return;
if ( V_91 )
F_19 ( V_66 ) -> V_239 = F_38 ( V_91 -> V_94 . V_95 ) ;
F_39 ( V_66 -> V_84 , F_33 ( V_66 -> V_85 ) ,
F_34 ( struct V_106 , V_236 ) ) ;
}
int
F_122 (
struct V_67 * V_68 ,
struct V_103 * V_96 ,
T_8 V_97 ,
int V_51 ,
struct V_65 * * V_98 )
{
int error ;
ASSERT ( V_97 != V_99 ) ;
error = F_41 (
V_68 , V_96 , V_68 -> V_100 ,
F_42 ( V_68 , V_97 , F_123 ( V_68 ) ) ,
F_44 ( V_68 , 1 ) , V_51 , V_98 , & V_240 ) ;
if ( error )
return error ;
if ( ! * V_98 )
return 0 ;
ASSERT ( ! ( * V_98 ) -> V_241 ) ;
F_46 ( * V_98 , V_242 ) ;
return 0 ;
}
int
F_105 (
struct V_67 * V_68 ,
struct V_103 * V_96 ,
T_8 V_97 ,
int V_51 ,
struct V_65 * * V_98 )
{
struct V_106 * V_41 ;
struct V_104 * V_105 ;
int error ;
ASSERT ( V_97 != V_99 ) ;
error = F_122 ( V_68 , V_96 , V_97 ,
( V_51 & V_201 ) ? V_243 : 0 ,
V_98 ) ;
if ( error )
return error ;
if ( ! * V_98 )
return 0 ;
ASSERT ( ! ( * V_98 ) -> V_241 ) ;
V_41 = F_19 ( * V_98 ) ;
V_105 = F_98 ( V_68 , V_97 ) ;
if ( ! V_105 -> V_200 ) {
V_105 -> V_107 = F_10 ( V_41 -> V_44 ) ;
V_105 -> V_215 = F_10 ( V_41 -> V_214 ) ;
V_105 -> V_195 = F_10 ( V_41 -> V_175 ) ;
V_105 -> V_196 = F_10 ( V_41 -> V_206 ) ;
V_105 -> V_244 [ V_245 ] =
F_10 ( V_41 -> V_224 [ V_245 ] ) ;
V_105 -> V_244 [ V_246 ] =
F_10 ( V_41 -> V_224 [ V_246 ] ) ;
F_124 ( & V_105 -> V_247 ) ;
V_105 -> V_248 = 0 ;
V_105 -> V_249 = V_250 ;
V_105 -> V_200 = 1 ;
}
#ifdef F_21
else if ( ! F_125 ( V_68 ) ) {
ASSERT ( V_105 -> V_107 == F_10 ( V_41 -> V_44 ) ) ;
ASSERT ( V_105 -> V_215 == F_10 ( V_41 -> V_214 ) ) ;
ASSERT ( V_105 -> V_195 == F_10 ( V_41 -> V_175 ) ) ;
ASSERT ( V_105 -> V_196 == F_10 ( V_41 -> V_206 ) ) ;
ASSERT ( V_105 -> V_244 [ V_245 ] ==
F_10 ( V_41 -> V_224 [ V_245 ] ) ) ;
ASSERT ( V_105 -> V_244 [ V_246 ] ==
F_10 ( V_41 -> V_224 [ V_246 ] ) ) ;
}
#endif
F_99 ( V_105 ) ;
return 0 ;
}
int
F_126 (
T_3 * args )
{
T_1 V_251 ;
int error ;
int V_51 ;
T_2 V_42 ;
T_6 * V_68 ;
T_8 V_252 ;
T_13 type ;
int V_253 = 0 ;
int V_254 = 0 ;
T_8 V_255 = V_256 ;
V_68 = args -> V_68 ;
type = args -> V_257 = args -> type ;
args -> V_45 = V_35 ;
V_251 = V_68 -> V_74 . V_82 ;
if ( args -> V_40 > V_251 )
args -> V_40 = V_251 ;
if ( args -> V_20 == 0 )
args -> V_20 = 1 ;
ASSERT ( F_127 ( V_68 , args -> V_258 ) < V_68 -> V_74 . V_259 ) ;
ASSERT ( F_128 ( V_68 , args -> V_258 ) < V_251 ) ;
ASSERT ( args -> V_21 <= args -> V_40 ) ;
ASSERT ( args -> V_21 <= V_251 ) ;
ASSERT ( args -> V_38 < args -> V_39 ) ;
if ( F_127 ( V_68 , args -> V_258 ) >= V_68 -> V_74 . V_259 ||
F_128 ( V_68 , args -> V_258 ) >= V_251 ||
args -> V_21 > args -> V_40 || args -> V_21 > V_251 ||
args -> V_38 >= args -> V_39 ) {
args -> V_258 = V_260 ;
F_129 ( args ) ;
return 0 ;
}
V_42 = args -> V_42 ;
switch ( type ) {
case V_111 :
case V_112 :
case V_113 :
args -> V_97 = F_127 ( V_68 , args -> V_258 ) ;
args -> V_105 = F_98 ( V_68 , args -> V_97 ) ;
args -> V_42 = 0 ;
error = F_104 ( args , 0 ) ;
args -> V_42 = V_42 ;
if ( error ) {
F_130 ( args ) ;
goto V_124;
}
if ( ! args -> V_43 ) {
F_131 ( args ) ;
break;
}
args -> V_45 = F_128 ( V_68 , args -> V_258 ) ;
if ( ( error = F_52 ( args ) ) )
goto V_124;
break;
case V_261 :
if ( ( args -> V_176 == V_262 ) &&
( V_68 -> V_263 & V_264 ) ) {
args -> V_258 = F_132 ( V_68 ,
( ( V_68 -> V_265 / V_255 ) %
V_68 -> V_74 . V_259 ) , 0 ) ;
V_253 = 1 ;
}
args -> V_45 = F_128 ( V_68 , args -> V_258 ) ;
args -> type = V_112 ;
case V_266 :
case V_267 :
case V_268 :
if ( type == V_266 ) {
args -> V_97 = V_252 = ( V_68 -> V_265 / V_255 ) %
V_68 -> V_74 . V_259 ;
args -> type = V_111 ;
V_51 = V_201 ;
} else if ( type == V_268 ) {
args -> V_97 = F_127 ( V_68 , args -> V_258 ) ;
args -> type = V_111 ;
V_252 = 0 ;
V_51 = 0 ;
} else {
if ( type == V_267 )
args -> type = V_111 ;
args -> V_97 = V_252 = F_127 ( V_68 , args -> V_258 ) ;
V_51 = V_201 ;
}
for (; ; ) {
args -> V_105 = F_98 ( V_68 , args -> V_97 ) ;
if ( V_254 ) args -> V_42 = 0 ;
error = F_104 ( args , V_51 ) ;
args -> V_42 = V_42 ;
if ( error ) {
F_130 ( args ) ;
goto V_124;
}
if ( args -> V_43 ) {
if ( ( error = F_52 ( args ) ) )
goto V_124;
break;
}
F_133 ( args ) ;
if ( args -> V_97 == V_252 &&
type == V_261 )
args -> type = V_111 ;
if ( ++ ( args -> V_97 ) == V_68 -> V_74 . V_259 ) {
if ( args -> V_269 != V_260 )
args -> V_97 = V_252 ;
else
args -> V_97 = 0 ;
}
if ( args -> V_97 == V_252 ) {
if ( V_254 == 1 ) {
args -> V_45 = V_35 ;
F_134 ( args ) ;
break;
}
if ( V_51 == 0 ) {
V_254 = 1 ;
} else {
V_51 = 0 ;
if ( type == V_261 ) {
args -> V_45 = F_128 ( V_68 ,
args -> V_258 ) ;
args -> type = V_112 ;
}
}
}
F_99 ( args -> V_105 ) ;
}
if ( V_253 || ( type == V_266 ) ) {
if ( args -> V_97 == V_252 )
V_68 -> V_265 = ( V_68 -> V_265 + 1 ) %
( V_68 -> V_74 . V_259 * V_255 ) ;
else
V_68 -> V_265 = ( args -> V_97 * V_255 + 1 ) %
( V_68 -> V_74 . V_259 * V_255 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_45 == V_35 )
args -> V_258 = V_260 ;
else {
args -> V_258 = F_132 ( V_68 , args -> V_97 , args -> V_45 ) ;
#ifdef F_21
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_40 ) ;
ASSERT ( args -> V_45 % args -> V_20 == 0 ) ;
F_135 ( V_68 , F_136 ( V_68 , args -> V_258 ) ,
args -> V_4 ) ;
#endif
}
F_99 ( args -> V_105 ) ;
return 0 ;
V_124:
F_99 ( args -> V_105 ) ;
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
args . V_68 = V_96 -> V_181 ;
args . V_97 = F_127 ( args . V_68 , V_3 ) ;
if ( args . V_97 >= args . V_68 -> V_74 . V_259 )
return V_89 ;
args . V_45 = F_128 ( args . V_68 , V_3 ) ;
if ( args . V_45 >= args . V_68 -> V_74 . V_82 )
return V_89 ;
args . V_105 = F_98 ( args . V_68 , args . V_97 ) ;
ASSERT ( args . V_105 ) ;
error = F_104 ( & args , V_202 ) ;
if ( error )
goto V_124;
if ( args . V_45 + V_4 >
F_10 ( F_19 ( args . V_43 ) -> V_108 ) ) {
error = V_89 ;
goto V_124;
}
error = F_97 ( V_96 , args . V_43 , args . V_97 , args . V_45 , V_4 , 0 ) ;
if ( ! error )
F_138 ( V_96 , args . V_97 , args . V_45 , V_4 , 0 ) ;
V_124:
F_99 ( args . V_105 ) ;
return error ;
}
