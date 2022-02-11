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
if ( V_37 > args -> V_39 ) {
if ( ( int ) ( V_38 = V_38 - V_37 - args -> V_39 ) < ( int ) args -> V_21 )
return;
} else {
if ( ( int ) ( V_38 = V_38 - args -> V_40 - ( args -> V_39 - V_37 ) ) <
( int ) args -> V_21 )
return;
}
ASSERT ( V_38 >= args -> V_21 ) ;
ASSERT ( V_38 <= args -> V_41 ) ;
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
int V_84 = 1 ;
if ( ! F_31 ( & V_69 -> V_75 ) )
return;
V_84 = F_32 ( V_67 -> V_85 , F_33 ( V_67 -> V_86 ) ,
F_34 ( struct V_72 , V_87 ) ) ;
V_84 = V_84 && F_26 ( V_67 ) ;
if ( ! V_84 ) {
F_35 ( V_88 , V_89 , V_69 , V_67 -> V_85 ) ;
F_36 ( V_67 , V_90 ) ;
}
}
static void
F_37 (
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 -> V_71 ;
struct V_91 * V_92 = V_67 -> V_93 ;
if ( ! F_31 ( & V_69 -> V_75 ) )
return;
if ( ! F_26 ( V_67 ) ) {
F_35 ( V_88 , V_89 , V_69 , V_67 -> V_85 ) ;
F_36 ( V_67 , V_90 ) ;
return;
}
if ( V_92 )
F_27 ( V_67 ) -> V_94 = F_38 ( V_92 -> V_95 . V_96 ) ;
F_39 ( V_67 -> V_85 , F_33 ( V_67 -> V_86 ) ,
F_34 ( struct V_72 , V_87 ) ) ;
}
STATIC int
F_40 (
T_6 * V_69 ,
T_7 * V_97 ,
T_8 V_98 ,
T_9 * * V_99 )
{
T_9 * V_67 ;
int error ;
ASSERT ( V_98 != V_100 ) ;
error = F_41 (
V_69 , V_97 , V_69 -> V_101 ,
F_42 ( V_69 , V_98 , F_43 ( V_69 ) ) ,
F_44 ( V_69 , 1 ) , 0 , & V_67 , & V_102 ) ;
if ( error )
return error ;
ASSERT ( ! F_45 ( V_67 ) ) ;
F_46 ( V_67 , V_103 ) ;
* V_99 = V_67 ;
return 0 ;
}
STATIC int
F_47 (
struct V_104 * V_97 ,
struct V_105 * V_106 ,
struct V_66 * V_44 ,
long V_4 )
{
struct V_107 * V_42 = F_19 ( V_44 ) ;
V_106 -> V_108 += V_4 ;
F_48 ( & V_42 -> V_45 , V_4 ) ;
F_49 ( V_97 , V_4 ) ;
if ( F_50 ( F_10 ( V_42 -> V_45 ) >
F_10 ( V_42 -> V_109 ) ) )
return V_90 ;
F_51 ( V_97 , V_44 , V_110 ) ;
return 0 ;
}
STATIC int
F_52 (
T_3 * args )
{
int error = 0 ;
ASSERT ( args -> V_21 > 0 ) ;
ASSERT ( args -> V_41 > 0 ) ;
ASSERT ( args -> V_21 <= args -> V_41 ) ;
ASSERT ( args -> V_39 < args -> V_40 ) ;
ASSERT ( args -> V_20 > 0 ) ;
args -> V_111 = 0 ;
switch ( args -> type ) {
case V_112 :
error = F_53 ( args ) ;
break;
case V_113 :
error = F_54 ( args ) ;
break;
case V_114 :
error = F_55 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error || args -> V_46 == V_36 )
return error ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_41 ) ;
ASSERT ( ! args -> V_111 || ! args -> V_115 ) ;
ASSERT ( args -> V_46 % args -> V_20 == 0 ) ;
if ( ! args -> V_111 ) {
error = F_47 ( args -> V_97 , args -> V_106 ,
args -> V_44 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_56 ( args -> V_69 , args -> V_98 ,
args -> V_46 , args -> V_4 ) ) ;
}
if ( ! args -> V_115 ) {
F_57 ( args -> V_97 , args -> V_116 ?
V_117 :
V_118 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
}
F_58 ( V_119 ) ;
F_59 ( V_120 , args -> V_4 ) ;
return error ;
}
STATIC int
F_55 (
T_3 * args )
{
T_5 * V_48 ;
T_5 * V_47 ;
int error ;
T_1 V_49 ;
T_2 V_50 ;
T_1 V_121 ;
T_2 V_122 ;
T_1 V_123 ;
int V_53 ;
ASSERT ( args -> V_20 == 1 ) ;
V_48 = F_60 ( args -> V_69 , args -> V_97 , args -> V_44 ,
args -> V_98 , V_124 ) ;
error = F_4 ( V_48 , args -> V_46 , args -> V_21 , & V_53 ) ;
if ( error )
goto V_125;
if ( ! V_53 )
goto V_126;
error = F_8 ( V_48 , & V_49 , & V_50 , & V_53 ) ;
if ( error )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
ASSERT ( V_49 <= args -> V_46 ) ;
F_12 ( args , V_49 , V_50 , & V_121 , & V_122 ) ;
if ( V_121 > args -> V_46 )
goto V_126;
if ( V_122 < args -> V_21 )
goto V_126;
V_123 = V_121 + V_122 ;
if ( V_123 < args -> V_46 + args -> V_21 )
goto V_126;
args -> V_4 = F_62 ( V_123 , args -> V_46 + args -> V_41 )
- args -> V_46 ;
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_126;
ASSERT ( args -> V_46 + args -> V_4 <= V_123 ) ;
V_47 = F_60 ( args -> V_69 , args -> V_97 , args -> V_44 ,
args -> V_98 , V_127 ) ;
ASSERT ( args -> V_46 + args -> V_4 <=
F_10 ( F_19 ( args -> V_44 ) -> V_109 ) ) ;
error = F_20 ( V_47 , V_48 , V_49 , V_50 , args -> V_46 ,
args -> V_4 , V_59 ) ;
if ( error ) {
F_63 ( V_47 , V_128 ) ;
goto V_125;
}
F_63 ( V_48 , V_129 ) ;
F_63 ( V_47 , V_129 ) ;
args -> V_111 = 0 ;
F_64 ( args ) ;
return 0 ;
V_126:
F_63 ( V_48 , V_129 ) ;
args -> V_46 = V_36 ;
F_65 ( args ) ;
return 0 ;
V_125:
F_63 ( V_48 , V_128 ) ;
F_66 ( args ) ;
return error ;
}
STATIC int
F_67 (
struct V_130 * args ,
struct V_1 * * V_131 ,
struct V_1 * * V_132 ,
T_1 V_133 ,
T_1 * V_134 ,
T_2 * V_135 ,
T_1 * V_136 ,
T_2 * V_137 ,
int V_138 )
{
T_1 V_139 ;
T_1 V_140 ;
int error ;
int V_53 ;
if ( ! V_133 )
goto V_141;
do {
error = F_8 ( * V_132 , V_134 , V_135 , & V_53 ) ;
if ( error )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
F_11 ( args , * V_134 , * V_135 , V_136 , V_137 ) ;
if ( ! V_138 ) {
if ( * V_136 >= args -> V_46 + V_133 )
goto V_141;
} else {
if ( * V_136 <= args -> V_46 - V_133 )
goto V_141;
}
if ( * V_137 >= args -> V_21 ) {
args -> V_4 = F_15 ( * V_137 , args -> V_41 ) ;
F_17 ( args ) ;
V_140 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 ,
args -> V_26 , * V_136 ,
* V_137 , & V_139 ) ;
if ( V_140 < V_133 )
goto V_142;
goto V_141;
}
if ( ! V_138 )
error = F_68 ( * V_132 , 0 , & V_53 ) ;
else
error = F_69 ( * V_132 , 0 , & V_53 ) ;
if ( error )
goto V_125;
} while ( V_53 );
V_141:
F_63 ( * V_132 , V_129 ) ;
* V_132 = NULL ;
return 0 ;
V_142:
F_63 ( * V_131 , V_129 ) ;
* V_131 = NULL ;
return 0 ;
V_125:
return error ;
}
STATIC int
F_54 (
T_3 * args )
{
T_5 * V_143 ;
T_5 * V_144 ;
T_5 * V_47 ;
T_1 V_145 ;
T_1 V_146 ;
T_2 V_147 ;
T_2 V_148 ;
T_2 V_149 ;
T_1 V_150 ;
int error ;
int V_53 ;
int V_151 ;
T_1 V_152 ;
T_1 V_153 ;
T_2 V_154 ;
T_2 V_155 ;
T_2 V_156 ;
T_1 V_157 ;
T_2 V_38 ;
int V_158 = 0 ;
#if F_70 ( F_21 ) && F_70 ( V_159 )
int V_160 ;
V_160 = F_71 () & 1 ;
#endif
V_161:
V_144 = NULL ;
V_143 = NULL ;
V_155 = 0 ;
V_149 = 0 ;
V_156 = 0 ;
V_47 = F_60 ( args -> V_69 , args -> V_97 , args -> V_44 ,
args -> V_98 , V_127 ) ;
if ( ( error = F_3 ( V_47 , 0 , args -> V_41 , & V_53 ) ) )
goto V_125;
if ( ! V_53 ) {
if ( ( error = F_72 ( args , V_47 , & V_152 ,
& V_155 , & V_53 ) ) )
goto V_125;
if ( V_53 == 0 || V_155 == 0 ) {
F_63 ( V_47 , V_129 ) ;
F_73 ( args ) ;
return 0 ;
}
ASSERT ( V_53 == 1 ) ;
}
args -> V_111 = 0 ;
while ( F_74 ( V_47 , 0 ) ) {
T_2 V_162 ;
int V_163 = 0 ;
T_2 V_164 = 0 ;
T_1 V_165 = 0 ;
#if F_70 ( F_21 ) && F_70 ( V_159 )
if ( ! V_160 )
break;
#endif
if ( V_155 || args -> V_20 > 1 ) {
V_47 -> V_166 [ 0 ] = 1 ;
do {
if ( ( error = F_8 ( V_47 , & V_152 ,
& V_155 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( V_155 >= args -> V_21 )
break;
if ( ( error = F_68 ( V_47 , 0 , & V_53 ) ) )
goto V_125;
} while ( V_53 );
ASSERT ( V_155 >= args -> V_21 ) ;
if ( ! V_53 )
break;
}
V_53 = V_47 -> V_166 [ 0 ] ;
for ( V_151 = 1 , V_164 = 0 , V_162 = 0 ;
! error && V_151 && ( V_164 < args -> V_41 || V_162 > 0 ) ;
error = F_68 ( V_47 , 0 , & V_151 ) ) {
if ( ( error = F_8 ( V_47 , & V_152 , & V_155 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
F_11 ( args , V_152 , V_155 ,
& V_153 , & V_156 ) ;
if ( V_156 < args -> V_21 )
continue;
args -> V_4 = F_15 ( V_156 , args -> V_41 ) ;
F_17 ( args ) ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
if ( args -> V_4 < V_164 )
continue;
V_154 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 , args -> V_26 , V_153 ,
V_156 , & V_157 ) ;
if ( V_157 != V_36 &&
( args -> V_4 > V_164 || V_154 < V_162 ) ) {
V_162 = V_154 ;
V_165 = V_157 ;
V_164 = args -> V_4 ;
V_163 = V_47 -> V_166 [ 0 ] ;
}
}
if ( V_164 == 0 )
break;
V_47 -> V_166 [ 0 ] = V_163 ;
if ( ( error = F_8 ( V_47 , & V_152 , & V_155 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
ASSERT ( V_152 + V_155 <= F_10 ( F_19 ( args -> V_44 ) -> V_109 ) ) ;
args -> V_4 = V_164 ;
if ( ! F_18 ( args ) ) {
F_63 ( V_47 , V_129 ) ;
F_75 ( args ) ;
return 0 ;
}
V_164 = args -> V_4 ;
args -> V_46 = V_165 ;
ASSERT ( V_165 >= V_152 ) ;
ASSERT ( V_165 + V_164 <= V_152 + V_155 ) ;
V_144 = F_60 ( args -> V_69 , args -> V_97 ,
args -> V_44 , args -> V_98 , V_124 ) ;
if ( ( error = F_20 ( V_47 , V_144 , V_152 ,
V_155 , V_165 , V_164 , V_58 ) ) )
goto V_125;
F_63 ( V_47 , V_129 ) ;
F_63 ( V_144 , V_129 ) ;
F_76 ( args ) ;
return 0 ;
}
V_144 = F_60 ( args -> V_69 , args -> V_97 , args -> V_44 ,
args -> V_98 , V_124 ) ;
if ( ( error = F_4 ( V_144 , args -> V_46 , args -> V_41 , & V_53 ) ) )
goto V_125;
if ( ! V_53 ) {
V_143 = V_144 ;
V_144 = NULL ;
}
else if ( ( error = F_77 ( V_144 , & V_143 ) ) )
goto V_125;
if ( ( error = F_68 ( V_143 , 0 , & V_53 ) ) )
goto V_125;
if ( ! V_53 ) {
F_63 ( V_143 , V_129 ) ;
V_143 = NULL ;
}
do {
if ( V_144 ) {
if ( ( error = F_8 ( V_144 , & V_152 , & V_155 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
F_11 ( args , V_152 , V_155 ,
& V_153 , & V_156 ) ;
if ( V_156 >= args -> V_21 )
break;
if ( ( error = F_69 ( V_144 , 0 , & V_53 ) ) )
goto V_125;
if ( ! V_53 ) {
F_63 ( V_144 ,
V_129 ) ;
V_144 = NULL ;
}
}
if ( V_143 ) {
if ( ( error = F_8 ( V_143 , & V_145 , & V_148 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
F_11 ( args , V_145 , V_148 ,
& V_146 , & V_149 ) ;
if ( V_149 >= args -> V_21 )
break;
if ( ( error = F_68 ( V_143 , 0 , & V_53 ) ) )
goto V_125;
if ( ! V_53 ) {
F_63 ( V_143 ,
V_129 ) ;
V_143 = NULL ;
}
}
} while ( V_144 || V_143 );
if ( V_144 && V_143 ) {
if ( V_156 >= args -> V_21 ) {
args -> V_4 = F_15 ( V_156 , args -> V_41 ) ;
F_17 ( args ) ;
V_154 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 , args -> V_26 , V_153 ,
V_156 , & V_157 ) ;
error = F_67 ( args ,
& V_144 , & V_143 ,
V_154 , & V_145 , & V_148 ,
& V_146 , & V_149 ,
0 ) ;
} else {
ASSERT ( V_149 >= args -> V_21 ) ;
args -> V_4 = F_15 ( V_149 , args -> V_41 ) ;
F_17 ( args ) ;
V_147 = F_14 ( args -> V_46 , args -> V_4 ,
args -> V_20 , args -> V_26 , V_146 ,
V_149 , & V_150 ) ;
error = F_67 ( args ,
& V_143 , & V_144 ,
V_147 , & V_152 , & V_155 ,
& V_153 , & V_156 ,
1 ) ;
}
if ( error )
goto V_125;
}
if ( V_144 == NULL && V_143 == NULL ) {
F_63 ( V_47 , V_129 ) ;
if ( ! V_158 ++ ) {
F_78 ( args ) ;
F_79 ( args -> V_69 , V_167 ) ;
goto V_161;
}
F_80 ( args ) ;
args -> V_46 = V_36 ;
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
args -> V_4 = F_15 ( V_156 , args -> V_41 ) ;
F_17 ( args ) ;
if ( ! F_18 ( args ) ) {
F_75 ( args ) ;
F_63 ( V_144 , V_129 ) ;
F_63 ( V_47 , V_129 ) ;
return 0 ;
}
V_38 = args -> V_4 ;
( void ) F_14 ( args -> V_46 , V_38 , args -> V_20 ,
args -> V_26 , V_153 , V_156 , & V_157 ) ;
ASSERT ( V_157 >= V_152 ) ;
ASSERT ( V_157 + V_38 <= V_153 + V_156 ) ;
ASSERT ( V_157 + V_38 <= F_10 ( F_19 ( args -> V_44 ) -> V_109 ) ) ;
args -> V_46 = V_157 ;
if ( ( error = F_20 ( V_47 , V_144 , V_152 , V_155 ,
V_157 , V_38 , V_59 ) ) )
goto V_125;
if ( V_151 )
F_81 ( args ) ;
else
F_82 ( args ) ;
F_63 ( V_47 , V_129 ) ;
F_63 ( V_144 , V_129 ) ;
return 0 ;
V_125:
F_83 ( args ) ;
if ( V_47 != NULL )
F_63 ( V_47 , V_128 ) ;
if ( V_144 != NULL )
F_63 ( V_144 , V_128 ) ;
if ( V_143 != NULL )
F_63 ( V_143 , V_128 ) ;
return error ;
}
STATIC int
F_53 (
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
int V_158 = 0 ;
V_161:
V_47 = F_60 ( args -> V_69 , args -> V_97 , args -> V_44 ,
args -> V_98 , V_127 ) ;
V_48 = NULL ;
if ( ( error = F_3 ( V_47 , 0 ,
args -> V_41 + args -> V_20 - 1 , & V_53 ) ) )
goto V_125;
if ( ! V_53 || V_158 > 1 ) {
error = F_72 ( args , V_47 ,
& V_49 , & V_50 , & V_53 ) ;
if ( error )
goto V_125;
if ( V_53 == 0 || V_50 == 0 ) {
F_63 ( V_47 , V_129 ) ;
F_84 ( args ) ;
return 0 ;
}
ASSERT ( V_53 == 1 ) ;
F_11 ( args , V_49 , V_50 , & V_51 , & V_38 ) ;
} else {
for (; ; ) {
error = F_8 ( V_47 , & V_49 , & V_50 , & V_53 ) ;
if ( error )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
F_11 ( args , V_49 , V_50 ,
& V_51 , & V_38 ) ;
if ( V_38 >= args -> V_41 )
break;
error = F_68 ( V_47 , 0 , & V_53 ) ;
if ( error )
goto V_125;
if ( V_53 == 0 ) {
F_63 ( V_47 ,
V_129 ) ;
F_85 ( args ) ;
if ( ! V_158 ++ )
F_79 ( args -> V_69 , V_167 ) ;
goto V_161;
}
}
}
V_38 = F_15 ( args -> V_41 , V_38 ) ;
F_61 ( V_38 == 0 ||
( V_38 <= V_50 && V_51 + V_38 <= V_49 + V_50 ) , V_125 ) ;
if ( V_38 < args -> V_41 ) {
T_1 V_168 ;
T_2 V_169 ;
T_1 V_170 ;
T_2 V_171 ;
V_171 = V_38 ;
V_170 = V_51 ;
V_169 = V_50 ;
V_168 = V_49 ;
for (; ; ) {
if ( ( error = F_69 ( V_47 , 0 , & V_53 ) ) )
goto V_125;
if ( V_53 == 0 )
break;
if ( ( error = F_8 ( V_47 , & V_49 , & V_50 ,
& V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( V_50 < V_171 )
break;
F_11 ( args , V_49 , V_50 ,
& V_51 , & V_38 ) ;
V_38 = F_15 ( args -> V_41 , V_38 ) ;
F_61 ( V_38 == 0 ||
( V_38 <= V_50 && V_51 + V_38 <= V_49 + V_50 ) ,
V_125 ) ;
if ( V_38 > V_171 ) {
V_171 = V_38 ;
V_170 = V_51 ;
V_169 = V_50 ;
V_168 = V_49 ;
if ( V_38 == args -> V_41 )
break;
}
}
if ( ( error = F_1 ( V_47 , V_168 , V_169 ,
& V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
V_38 = V_171 ;
V_51 = V_170 ;
V_50 = V_169 ;
V_49 = V_168 ;
}
args -> V_111 = 0 ;
args -> V_4 = V_38 ;
if ( V_38 < args -> V_21 ) {
if ( ! V_158 ++ ) {
F_63 ( V_47 , V_129 ) ;
F_85 ( args ) ;
F_79 ( args -> V_69 , V_167 ) ;
goto V_161;
}
goto V_172;
}
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_172;
V_38 = args -> V_4 ;
F_61 ( V_38 <= V_50 , V_125 ) ;
V_48 = F_60 ( args -> V_69 , args -> V_97 , args -> V_44 ,
args -> V_98 , V_124 ) ;
if ( ( error = F_20 ( V_47 , V_48 , V_49 , V_50 ,
V_51 , V_38 , V_58 ) ) )
goto V_125;
F_63 ( V_47 , V_129 ) ;
F_63 ( V_48 , V_129 ) ;
V_47 = V_48 = NULL ;
args -> V_4 = V_38 ;
args -> V_46 = V_51 ;
F_61 (
args -> V_46 + args -> V_4 <=
F_10 ( F_19 ( args -> V_44 ) -> V_109 ) ,
V_125 ) ;
F_86 ( args ) ;
return 0 ;
V_125:
F_87 ( args ) ;
if ( V_47 )
F_63 ( V_47 , V_128 ) ;
if ( V_48 )
F_63 ( V_48 , V_128 ) ;
return error ;
V_172:
F_63 ( V_47 , V_129 ) ;
F_88 ( args ) ;
args -> V_46 = V_36 ;
return 0 ;
}
STATIC int
F_72 (
T_3 * args ,
T_5 * V_173 ,
T_1 * V_174 ,
T_2 * V_175 ,
int * V_5 )
{
int error ;
T_1 V_49 ;
T_2 V_50 ;
int V_53 ;
if ( ( error = F_69 ( V_173 , 0 , & V_53 ) ) )
goto V_125;
if ( V_53 ) {
if ( ( error = F_8 ( V_173 , & V_49 , & V_50 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
}
else if ( args -> V_21 == 1 && args -> V_20 == 1 && ! args -> V_115 &&
( F_10 ( F_19 ( args -> V_44 ) -> V_176 )
> args -> V_43 ) ) {
error = F_89 ( args -> V_97 , args -> V_44 , & V_49 , 0 ) ;
if ( error )
goto V_125;
if ( V_49 != V_36 ) {
F_90 ( args -> V_69 , args -> V_98 , V_49 , 1 ,
args -> V_26 ) ;
if ( args -> V_26 ) {
T_9 * V_67 ;
V_67 = F_91 ( args -> V_69 , args -> V_97 ,
args -> V_98 , V_49 , 0 ) ;
F_92 ( args -> V_97 , V_67 ) ;
}
args -> V_4 = 1 ;
args -> V_46 = V_49 ;
F_61 (
args -> V_46 + args -> V_4 <=
F_10 ( F_19 ( args -> V_44 ) -> V_109 ) ,
V_125 ) ;
args -> V_111 = 1 ;
F_93 ( args ) ;
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
F_94 ( args ) ;
V_50 = 0 ;
}
* V_174 = V_49 ;
* V_175 = V_50 ;
* V_5 = 1 ;
F_95 ( args ) ;
return 0 ;
V_125:
F_96 ( args ) ;
return error ;
}
STATIC int
F_97 (
T_7 * V_97 ,
T_9 * V_44 ,
T_8 V_98 ,
T_1 V_3 ,
T_2 V_4 ,
int V_115 )
{
T_5 * V_48 ;
T_5 * V_47 ;
int error ;
T_1 V_145 ;
T_2 V_148 ;
int V_177 ;
int V_178 ;
int V_53 ;
T_1 V_152 ;
T_2 V_155 ;
T_6 * V_69 ;
T_1 V_179 ;
T_2 V_180 ;
T_10 * V_106 ;
V_69 = V_97 -> V_181 ;
V_48 = F_60 ( V_69 , V_97 , V_44 , V_98 , V_124 ) ;
V_47 = NULL ;
if ( ( error = F_4 ( V_48 , V_3 , V_4 , & V_177 ) ) )
goto V_125;
if ( V_177 ) {
if ( ( error = F_8 ( V_48 , & V_152 , & V_155 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( V_152 + V_155 < V_3 )
V_177 = 0 ;
else {
F_61 ( V_152 + V_155 <= V_3 , V_125 ) ;
}
}
if ( ( error = F_68 ( V_48 , 0 , & V_178 ) ) )
goto V_125;
if ( V_178 ) {
if ( ( error = F_8 ( V_48 , & V_145 , & V_148 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( V_3 + V_4 < V_145 )
V_178 = 0 ;
else {
F_61 ( V_145 >= V_3 + V_4 , V_125 ) ;
}
}
V_47 = F_60 ( V_69 , V_97 , V_44 , V_98 , V_127 ) ;
if ( V_177 && V_178 ) {
if ( ( error = F_1 ( V_47 , V_152 , V_155 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( ( error = F_1 ( V_47 , V_145 , V_148 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( ( error = F_24 ( V_48 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( ( error = F_69 ( V_48 , 0 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
#ifdef F_21
{
T_1 V_182 ;
T_2 V_183 ;
if ( ( error = F_8 ( V_48 , & V_182 , & V_183 ,
& V_53 ) ) )
goto V_125;
F_61 (
V_53 == 1 && V_182 == V_152 && V_183 == V_155 ,
V_125 ) ;
}
#endif
V_179 = V_152 ;
V_180 = V_4 + V_155 + V_148 ;
if ( ( error = F_5 ( V_48 , V_179 , V_180 ) ) )
goto V_125;
}
else if ( V_177 ) {
if ( ( error = F_1 ( V_47 , V_152 , V_155 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( ( error = F_69 ( V_48 , 0 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
V_179 = V_152 ;
V_180 = V_4 + V_155 ;
if ( ( error = F_5 ( V_48 , V_179 , V_180 ) ) )
goto V_125;
}
else if ( V_178 ) {
if ( ( error = F_1 ( V_47 , V_145 , V_148 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
if ( ( error = F_24 ( V_47 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
V_179 = V_3 ;
V_180 = V_4 + V_148 ;
if ( ( error = F_5 ( V_48 , V_179 , V_180 ) ) )
goto V_125;
}
else {
V_179 = V_3 ;
V_180 = V_4 ;
if ( ( error = F_25 ( V_48 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
}
F_63 ( V_48 , V_129 ) ;
V_48 = NULL ;
if ( ( error = F_1 ( V_47 , V_179 , V_180 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 0 , V_125 ) ;
if ( ( error = F_25 ( V_47 , & V_53 ) ) )
goto V_125;
F_61 ( V_53 == 1 , V_125 ) ;
F_63 ( V_47 , V_129 ) ;
V_47 = NULL ;
V_106 = F_98 ( V_69 , V_98 ) ;
error = F_47 ( V_97 , V_106 , V_44 , V_4 ) ;
F_99 ( V_106 ) ;
if ( error )
goto V_125;
if ( ! V_115 )
F_57 ( V_97 , V_118 , ( long ) V_4 ) ;
F_58 ( V_184 ) ;
F_59 ( V_185 , V_4 ) ;
F_100 ( V_69 , V_98 , V_3 , V_4 , V_115 , V_177 , V_178 ) ;
return 0 ;
V_125:
F_100 ( V_69 , V_98 , V_3 , V_4 , V_115 , - 1 , - 1 ) ;
if ( V_48 )
F_63 ( V_48 , V_128 ) ;
if ( V_47 )
F_63 ( V_47 , V_128 ) ;
return error ;
}
void
F_101 (
T_6 * V_69 )
{
int V_186 ;
T_11 V_187 ;
T_11 V_188 ;
int V_189 ;
int V_190 ;
V_188 = ( V_69 -> V_75 . V_83 + 1 ) / 2 ;
V_189 = V_69 -> V_191 [ 0 ] ;
V_190 = V_69 -> V_191 [ 1 ] ;
V_187 = ( V_188 + V_189 - 1 ) / V_189 ;
for ( V_186 = 1 ; V_187 > 1 ; V_186 ++ )
V_187 = ( V_187 + V_190 - 1 ) / V_190 ;
V_69 -> V_192 = V_186 ;
}
T_2
F_102 (
struct V_68 * V_69 ,
struct V_105 * V_106 )
{
T_2 V_193 , V_194 = 0 ;
V_193 = F_103 ( V_106 , V_69 ) ;
if ( V_193 > V_106 -> V_195 )
V_194 = V_193 - V_106 -> V_195 ;
if ( V_106 -> V_196 > V_194 )
return V_106 -> V_196 - V_194 ;
return V_106 -> V_195 > 0 || V_106 -> V_196 > 0 ;
}
STATIC int
F_104 (
T_3 * args ,
int V_52 )
{
T_9 * V_44 ;
T_4 * V_42 ;
T_9 * V_197 ;
T_1 V_3 ;
T_2 V_194 ;
int error ;
T_2 V_198 ;
T_6 * V_69 ;
T_2 V_193 ;
T_10 * V_106 ;
T_3 V_199 ;
T_7 * V_97 ;
V_69 = args -> V_69 ;
V_106 = args -> V_106 ;
V_97 = args -> V_97 ;
if ( ! V_106 -> V_200 ) {
if ( ( error = F_105 ( V_69 , V_97 , args -> V_98 , V_52 ,
& V_44 ) ) )
return error ;
if ( ! V_106 -> V_200 ) {
ASSERT ( V_52 & V_201 ) ;
ASSERT ( ! ( V_52 & V_202 ) ) ;
args -> V_44 = NULL ;
return 0 ;
}
} else
V_44 = NULL ;
if ( V_106 -> V_203 && args -> V_26 &&
( V_52 & V_201 ) ) {
ASSERT ( ! ( V_52 & V_202 ) ) ;
args -> V_44 = NULL ;
return 0 ;
}
if ( ! ( V_52 & V_202 ) ) {
V_193 = F_103 ( V_106 , V_69 ) ;
V_198 = F_102 ( V_69 , V_106 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_204 - 1 ) >
V_198 ||
( ( int ) ( V_106 -> V_108 + V_106 -> V_195 -
V_193 - args -> V_205 ) < ( int ) args -> V_43 ) ) {
if ( V_44 )
F_106 ( V_97 , V_44 ) ;
args -> V_44 = NULL ;
return 0 ;
}
}
if ( V_44 == NULL ) {
if ( ( error = F_105 ( V_69 , V_97 , args -> V_98 , V_52 ,
& V_44 ) ) )
return error ;
if ( V_44 == NULL ) {
ASSERT ( V_52 & V_201 ) ;
ASSERT ( ! ( V_52 & V_202 ) ) ;
args -> V_44 = NULL ;
return 0 ;
}
}
V_42 = F_19 ( V_44 ) ;
V_193 = F_107 ( V_42 , V_69 ) ;
if ( ! ( V_52 & V_202 ) ) {
V_194 = V_193 > F_10 ( V_42 -> V_176 ) ?
( V_193 - F_10 ( V_42 -> V_176 ) ) : 0 ;
V_198 = F_10 ( V_42 -> V_206 ) ;
V_198 = ( V_198 > V_194 ) ? ( V_198 - V_194 ) :
( F_10 ( V_42 -> V_176 ) > 0 || V_198 > 0 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_204 - 1 ) >
V_198 ||
( ( int ) ( F_10 ( V_42 -> V_45 ) +
F_10 ( V_42 -> V_176 ) - V_193 - args -> V_205 ) <
( int ) args -> V_43 ) ) {
F_106 ( V_97 , V_44 ) ;
args -> V_44 = NULL ;
return 0 ;
}
}
while ( F_10 ( V_42 -> V_176 ) > V_193 ) {
T_9 * V_67 ;
error = F_89 ( V_97 , V_44 , & V_3 , 0 ) ;
if ( error )
return error ;
if ( ( error = F_97 ( V_97 , V_44 , args -> V_98 , V_3 , 1 , 1 ) ) )
return error ;
V_67 = F_91 ( V_69 , V_97 , args -> V_98 , V_3 , 0 ) ;
F_92 ( V_97 , V_67 ) ;
}
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
V_199 . V_97 = V_97 ;
V_199 . V_69 = V_69 ;
V_199 . V_44 = V_44 ;
V_199 . V_98 = args -> V_98 ;
V_199 . V_20 = V_199 . V_21 = V_199 . V_40 = V_199 . V_115 = 1 ;
V_199 . type = V_112 ;
V_199 . V_106 = V_106 ;
if ( ( error = F_40 ( V_69 , V_97 , V_199 . V_98 , & V_197 ) ) )
return error ;
while ( F_10 ( V_42 -> V_176 ) < V_193 ) {
V_199 . V_46 = 0 ;
V_199 . V_41 = V_193 - F_10 ( V_42 -> V_176 ) ;
if ( ( error = F_52 ( & V_199 ) ) ) {
F_106 ( V_97 , V_197 ) ;
return error ;
}
if ( V_199 . V_46 == V_36 ) {
if ( V_52 & V_202 )
break;
F_106 ( V_97 , V_197 ) ;
args -> V_44 = NULL ;
return 0 ;
}
for ( V_3 = V_199 . V_46 ; V_3 < V_199 . V_46 + V_199 . V_4 ; V_3 ++ ) {
error = F_108 ( V_97 , V_44 ,
V_197 , V_3 , 0 ) ;
if ( error )
return error ;
}
}
F_106 ( V_97 , V_197 ) ;
args -> V_44 = V_44 ;
return 0 ;
}
int
F_89 (
T_7 * V_97 ,
T_9 * V_44 ,
T_1 * V_207 ,
int V_208 )
{
T_4 * V_42 ;
T_9 * V_197 ;
T_1 V_3 ;
T_12 * V_82 ;
int error ;
int V_209 ;
T_6 * V_69 = V_97 -> V_181 ;
T_10 * V_106 ;
V_42 = F_19 ( V_44 ) ;
if ( ! V_42 -> V_176 ) {
* V_207 = V_36 ;
return 0 ;
}
error = F_40 ( V_69 , V_97 , F_10 ( V_42 -> V_210 ) ,
& V_197 ) ;
if ( error )
return error ;
V_82 = F_109 ( V_69 , V_197 ) ;
V_3 = F_10 ( V_82 [ F_10 ( V_42 -> V_211 ) ] ) ;
F_48 ( & V_42 -> V_211 , 1 ) ;
F_106 ( V_97 , V_197 ) ;
if ( F_10 ( V_42 -> V_211 ) == F_29 ( V_69 ) )
V_42 -> V_211 = 0 ;
V_106 = F_98 ( V_69 , F_10 ( V_42 -> V_210 ) ) ;
F_48 ( & V_42 -> V_176 , - 1 ) ;
F_110 ( V_97 , - 1 ) ;
V_106 -> V_195 -- ;
F_99 ( V_106 ) ;
V_209 = V_212 | V_213 ;
if ( V_208 ) {
F_48 ( & V_42 -> V_214 , 1 ) ;
V_106 -> V_215 ++ ;
V_209 |= V_216 ;
}
F_51 ( V_97 , V_44 , V_209 ) ;
* V_207 = V_3 ;
return 0 ;
}
void
F_51 (
T_7 * V_97 ,
T_9 * V_67 ,
int V_217 )
{
int V_218 ;
int V_219 ;
static const short V_220 [] = {
F_34 ( T_4 , V_221 ) ,
F_34 ( T_4 , V_222 ) ,
F_34 ( T_4 , V_210 ) ,
F_34 ( T_4 , V_109 ) ,
F_34 ( T_4 , V_223 [ 0 ] ) ,
F_34 ( T_4 , V_224 [ 0 ] ) ,
F_34 ( T_4 , V_211 ) ,
F_34 ( T_4 , V_225 ) ,
F_34 ( T_4 , V_176 ) ,
F_34 ( T_4 , V_45 ) ,
F_34 ( T_4 , V_206 ) ,
F_34 ( T_4 , V_214 ) ,
F_34 ( T_4 , V_226 ) ,
sizeof( T_4 )
} ;
F_111 ( V_97 -> V_181 , F_19 ( V_67 ) , V_217 , V_227 ) ;
F_112 ( V_97 , V_67 , V_228 ) ;
F_113 ( V_217 , V_220 , V_229 , & V_218 , & V_219 ) ;
F_114 ( V_97 , V_67 , ( T_11 ) V_218 , ( T_11 ) V_219 ) ;
}
int
F_115 (
T_6 * V_69 ,
T_7 * V_97 ,
T_8 V_98 ,
int V_52 )
{
T_9 * V_67 ;
int error ;
if ( ( error = F_105 ( V_69 , V_97 , V_98 , V_52 , & V_67 ) ) )
return error ;
if ( V_67 )
F_106 ( V_97 , V_67 ) ;
return 0 ;
}
int
F_108 (
T_7 * V_97 ,
T_9 * V_44 ,
T_9 * V_197 ,
T_1 V_3 ,
int V_208 )
{
T_4 * V_42 ;
T_12 * V_230 ;
int error ;
int V_209 ;
T_6 * V_69 ;
T_10 * V_106 ;
T_12 * V_82 ;
int V_231 ;
V_42 = F_19 ( V_44 ) ;
V_69 = V_97 -> V_181 ;
if ( ! V_197 && ( error = F_40 ( V_69 , V_97 ,
F_10 ( V_42 -> V_210 ) , & V_197 ) ) )
return error ;
F_48 ( & V_42 -> V_225 , 1 ) ;
if ( F_10 ( V_42 -> V_225 ) == F_29 ( V_69 ) )
V_42 -> V_225 = 0 ;
V_106 = F_98 ( V_69 , F_10 ( V_42 -> V_210 ) ) ;
F_48 ( & V_42 -> V_176 , 1 ) ;
F_110 ( V_97 , 1 ) ;
V_106 -> V_195 ++ ;
V_209 = V_232 | V_213 ;
if ( V_208 ) {
F_48 ( & V_42 -> V_214 , - 1 ) ;
V_106 -> V_215 -- ;
V_209 |= V_216 ;
}
F_99 ( V_106 ) ;
F_51 ( V_97 , V_44 , V_209 ) ;
ASSERT ( F_10 ( V_42 -> V_176 ) <= F_29 ( V_69 ) ) ;
V_82 = F_109 ( V_69 , V_197 ) ;
V_230 = & V_82 [ F_10 ( V_42 -> V_225 ) ] ;
* V_230 = F_6 ( V_3 ) ;
V_231 = ( char * ) V_230 - ( char * ) V_197 -> V_85 ;
F_51 ( V_97 , V_44 , V_209 ) ;
F_112 ( V_97 , V_197 , V_233 ) ;
F_114 ( V_97 , V_197 , V_231 ,
V_231 + sizeof( T_1 ) - 1 ) ;
return 0 ;
}
static bool
F_116 (
struct V_68 * V_69 ,
struct V_66 * V_67 )
{
struct V_107 * V_42 = F_19 ( V_67 ) ;
if ( F_31 ( & V_69 -> V_75 ) &&
! F_28 ( & V_42 -> V_226 , & V_69 -> V_75 . V_76 ) )
return false ;
if ( ! ( V_42 -> V_221 == F_6 ( V_234 ) &&
F_117 ( F_10 ( V_42 -> V_222 ) ) &&
F_10 ( V_42 -> V_45 ) <= F_10 ( V_42 -> V_109 ) &&
F_10 ( V_42 -> V_211 ) < F_29 ( V_69 ) &&
F_10 ( V_42 -> V_225 ) < F_29 ( V_69 ) &&
F_10 ( V_42 -> V_176 ) <= F_29 ( V_69 ) ) )
return false ;
if ( V_67 -> V_79 && F_10 ( V_42 -> V_210 ) != V_67 -> V_79 -> V_81 )
return false ;
if ( F_118 ( & V_69 -> V_75 ) &&
F_10 ( V_42 -> V_214 ) > F_10 ( V_42 -> V_109 ) )
return false ;
return true ; ;
}
static void
F_119 (
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 -> V_71 ;
int V_235 = 1 ;
if ( F_31 ( & V_69 -> V_75 ) )
V_235 = F_32 ( V_67 -> V_85 , F_33 ( V_67 -> V_86 ) ,
F_34 ( struct V_107 , V_236 ) ) ;
V_235 = V_235 && F_116 ( V_69 , V_67 ) ;
if ( F_50 ( F_120 ( ! V_235 , V_69 , V_237 ,
V_238 ) ) ) {
F_35 ( V_88 , V_89 , V_69 , V_67 -> V_85 ) ;
F_36 ( V_67 , V_90 ) ;
}
}
static void
F_121 (
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 -> V_71 ;
struct V_91 * V_92 = V_67 -> V_93 ;
if ( ! F_116 ( V_69 , V_67 ) ) {
F_35 ( V_88 , V_89 , V_69 , V_67 -> V_85 ) ;
F_36 ( V_67 , V_90 ) ;
return;
}
if ( ! F_31 ( & V_69 -> V_75 ) )
return;
if ( V_92 )
F_19 ( V_67 ) -> V_239 = F_38 ( V_92 -> V_95 . V_96 ) ;
F_39 ( V_67 -> V_85 , F_33 ( V_67 -> V_86 ) ,
F_34 ( struct V_107 , V_236 ) ) ;
}
int
F_122 (
struct V_68 * V_69 ,
struct V_104 * V_97 ,
T_8 V_98 ,
int V_52 ,
struct V_66 * * V_99 )
{
int error ;
ASSERT ( V_98 != V_100 ) ;
error = F_41 (
V_69 , V_97 , V_69 -> V_101 ,
F_42 ( V_69 , V_98 , F_123 ( V_69 ) ) ,
F_44 ( V_69 , 1 ) , V_52 , V_99 , & V_240 ) ;
if ( error )
return error ;
if ( ! * V_99 )
return 0 ;
ASSERT ( ! ( * V_99 ) -> V_241 ) ;
F_46 ( * V_99 , V_242 ) ;
return 0 ;
}
int
F_105 (
struct V_68 * V_69 ,
struct V_104 * V_97 ,
T_8 V_98 ,
int V_52 ,
struct V_66 * * V_99 )
{
struct V_107 * V_42 ;
struct V_105 * V_106 ;
int error ;
ASSERT ( V_98 != V_100 ) ;
error = F_122 ( V_69 , V_97 , V_98 ,
( V_52 & V_201 ) ? V_243 : 0 ,
V_99 ) ;
if ( error )
return error ;
if ( ! * V_99 )
return 0 ;
ASSERT ( ! ( * V_99 ) -> V_241 ) ;
V_42 = F_19 ( * V_99 ) ;
V_106 = F_98 ( V_69 , V_98 ) ;
if ( ! V_106 -> V_200 ) {
V_106 -> V_108 = F_10 ( V_42 -> V_45 ) ;
V_106 -> V_215 = F_10 ( V_42 -> V_214 ) ;
V_106 -> V_195 = F_10 ( V_42 -> V_176 ) ;
V_106 -> V_196 = F_10 ( V_42 -> V_206 ) ;
V_106 -> V_244 [ V_245 ] =
F_10 ( V_42 -> V_224 [ V_245 ] ) ;
V_106 -> V_244 [ V_246 ] =
F_10 ( V_42 -> V_224 [ V_246 ] ) ;
F_124 ( & V_106 -> V_247 ) ;
V_106 -> V_248 = 0 ;
V_106 -> V_249 = V_250 ;
V_106 -> V_200 = 1 ;
}
#ifdef F_21
else if ( ! F_125 ( V_69 ) ) {
ASSERT ( V_106 -> V_108 == F_10 ( V_42 -> V_45 ) ) ;
ASSERT ( V_106 -> V_215 == F_10 ( V_42 -> V_214 ) ) ;
ASSERT ( V_106 -> V_195 == F_10 ( V_42 -> V_176 ) ) ;
ASSERT ( V_106 -> V_196 == F_10 ( V_42 -> V_206 ) ) ;
ASSERT ( V_106 -> V_244 [ V_245 ] ==
F_10 ( V_42 -> V_224 [ V_245 ] ) ) ;
ASSERT ( V_106 -> V_244 [ V_246 ] ==
F_10 ( V_42 -> V_224 [ V_246 ] ) ) ;
}
#endif
F_99 ( V_106 ) ;
return 0 ;
}
int
F_126 (
T_3 * args )
{
T_1 V_251 ;
int error ;
int V_52 ;
T_2 V_43 ;
T_6 * V_69 ;
T_8 V_252 ;
T_13 type ;
int V_253 = 0 ;
int V_254 = 0 ;
T_8 V_255 = V_256 ;
V_69 = args -> V_69 ;
type = args -> V_257 = args -> type ;
args -> V_46 = V_36 ;
V_251 = V_69 -> V_75 . V_83 ;
if ( args -> V_41 > V_251 )
args -> V_41 = V_251 ;
if ( args -> V_20 == 0 )
args -> V_20 = 1 ;
ASSERT ( F_127 ( V_69 , args -> V_258 ) < V_69 -> V_75 . V_259 ) ;
ASSERT ( F_128 ( V_69 , args -> V_258 ) < V_251 ) ;
ASSERT ( args -> V_21 <= args -> V_41 ) ;
ASSERT ( args -> V_21 <= V_251 ) ;
ASSERT ( args -> V_39 < args -> V_40 ) ;
if ( F_127 ( V_69 , args -> V_258 ) >= V_69 -> V_75 . V_259 ||
F_128 ( V_69 , args -> V_258 ) >= V_251 ||
args -> V_21 > args -> V_41 || args -> V_21 > V_251 ||
args -> V_39 >= args -> V_40 ) {
args -> V_258 = V_260 ;
F_129 ( args ) ;
return 0 ;
}
V_43 = args -> V_43 ;
switch ( type ) {
case V_112 :
case V_113 :
case V_114 :
args -> V_98 = F_127 ( V_69 , args -> V_258 ) ;
args -> V_106 = F_98 ( V_69 , args -> V_98 ) ;
args -> V_43 = 0 ;
error = F_104 ( args , 0 ) ;
args -> V_43 = V_43 ;
if ( error ) {
F_130 ( args ) ;
goto V_125;
}
if ( ! args -> V_44 ) {
F_131 ( args ) ;
break;
}
args -> V_46 = F_128 ( V_69 , args -> V_258 ) ;
if ( ( error = F_52 ( args ) ) )
goto V_125;
break;
case V_261 :
if ( ( args -> V_26 == V_262 ) &&
( V_69 -> V_263 & V_264 ) ) {
args -> V_258 = F_132 ( V_69 ,
( ( V_69 -> V_265 / V_255 ) %
V_69 -> V_75 . V_259 ) , 0 ) ;
V_253 = 1 ;
}
args -> V_46 = F_128 ( V_69 , args -> V_258 ) ;
args -> type = V_113 ;
case V_266 :
case V_267 :
case V_268 :
if ( type == V_266 ) {
args -> V_98 = V_252 = ( V_69 -> V_265 / V_255 ) %
V_69 -> V_75 . V_259 ;
args -> type = V_112 ;
V_52 = V_201 ;
} else if ( type == V_268 ) {
args -> V_98 = F_127 ( V_69 , args -> V_258 ) ;
args -> type = V_112 ;
V_252 = 0 ;
V_52 = 0 ;
} else {
if ( type == V_267 )
args -> type = V_112 ;
args -> V_98 = V_252 = F_127 ( V_69 , args -> V_258 ) ;
V_52 = V_201 ;
}
for (; ; ) {
args -> V_106 = F_98 ( V_69 , args -> V_98 ) ;
if ( V_254 ) args -> V_43 = 0 ;
error = F_104 ( args , V_52 ) ;
args -> V_43 = V_43 ;
if ( error ) {
F_130 ( args ) ;
goto V_125;
}
if ( args -> V_44 ) {
if ( ( error = F_52 ( args ) ) )
goto V_125;
break;
}
F_133 ( args ) ;
if ( args -> V_98 == V_252 &&
type == V_261 )
args -> type = V_112 ;
if ( ++ ( args -> V_98 ) == V_69 -> V_75 . V_259 ) {
if ( args -> V_269 != V_260 )
args -> V_98 = V_252 ;
else
args -> V_98 = 0 ;
}
if ( args -> V_98 == V_252 ) {
if ( V_254 == 1 ) {
args -> V_46 = V_36 ;
F_134 ( args ) ;
break;
}
if ( V_52 == 0 ) {
V_254 = 1 ;
} else {
V_52 = 0 ;
if ( type == V_261 ) {
args -> V_46 = F_128 ( V_69 ,
args -> V_258 ) ;
args -> type = V_113 ;
}
}
}
F_99 ( args -> V_106 ) ;
}
if ( V_253 || ( type == V_266 ) ) {
if ( args -> V_98 == V_252 )
V_69 -> V_265 = ( V_69 -> V_265 + 1 ) %
( V_69 -> V_75 . V_259 * V_255 ) ;
else
V_69 -> V_265 = ( args -> V_98 * V_255 + 1 ) %
( V_69 -> V_75 . V_259 * V_255 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_46 == V_36 )
args -> V_258 = V_260 ;
else {
args -> V_258 = F_132 ( V_69 , args -> V_98 , args -> V_46 ) ;
#ifdef F_21
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_41 ) ;
ASSERT ( args -> V_46 % args -> V_20 == 0 ) ;
F_135 ( V_69 , F_136 ( V_69 , args -> V_258 ) ,
args -> V_4 ) ;
#endif
}
F_99 ( args -> V_106 ) ;
return 0 ;
V_125:
F_99 ( args -> V_106 ) ;
return error ;
}
int
F_137 (
T_7 * V_97 ,
T_14 V_3 ,
T_2 V_4 )
{
T_3 args ;
int error ;
ASSERT ( V_4 != 0 ) ;
memset ( & args , 0 , sizeof( T_3 ) ) ;
args . V_97 = V_97 ;
args . V_69 = V_97 -> V_181 ;
args . V_98 = F_127 ( args . V_69 , V_3 ) ;
if ( args . V_98 >= args . V_69 -> V_75 . V_259 )
return V_90 ;
args . V_46 = F_128 ( args . V_69 , V_3 ) ;
if ( args . V_46 >= args . V_69 -> V_75 . V_83 )
return V_90 ;
args . V_106 = F_98 ( args . V_69 , args . V_98 ) ;
ASSERT ( args . V_106 ) ;
error = F_104 ( & args , V_202 ) ;
if ( error )
goto V_125;
if ( args . V_46 + V_4 >
F_10 ( F_19 ( args . V_44 ) -> V_109 ) ) {
error = V_90 ;
goto V_125;
}
error = F_97 ( V_97 , args . V_44 , args . V_98 , args . V_46 , V_4 , 0 ) ;
if ( ! error )
F_138 ( V_97 , args . V_98 , args . V_46 , V_4 , 0 ) ;
V_125:
F_99 ( args . V_106 ) ;
return error ;
}
