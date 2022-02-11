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
static void
F_26 (
struct V_65 * V_66 )
{
#ifdef F_27
struct V_67 * V_68 = V_66 -> V_69 -> V_70 ;
struct V_71 * V_72 = F_28 ( V_66 ) ;
int V_73 = 1 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < F_29 ( V_68 ) ; V_52 ++ ) {
if ( F_10 ( V_72 -> V_74 [ V_52 ] ) == V_35 ||
F_10 ( V_72 -> V_74 [ V_52 ] ) >= V_68 -> V_75 . V_76 )
V_73 = 0 ;
}
if ( ! V_73 ) {
F_30 ( V_77 , V_78 , V_68 , V_72 ) ;
F_31 ( V_66 , V_79 ) ;
}
#endif
}
static void
F_32 (
struct V_65 * V_66 )
{
F_26 ( V_66 ) ;
}
static void
F_33 (
struct V_65 * V_66 )
{
F_26 ( V_66 ) ;
}
STATIC int
F_34 (
T_6 * V_68 ,
T_7 * V_80 ,
T_8 V_81 ,
T_9 * * V_82 )
{
T_9 * V_66 ;
int error ;
ASSERT ( V_81 != V_83 ) ;
error = F_35 (
V_68 , V_80 , V_68 -> V_84 ,
F_36 ( V_68 , V_81 , F_37 ( V_68 ) ) ,
F_38 ( V_68 , 1 ) , 0 , & V_66 , & V_85 ) ;
if ( error )
return error ;
ASSERT ( ! F_39 ( V_66 ) ) ;
F_40 ( V_66 , V_86 ) ;
* V_82 = V_66 ;
return 0 ;
}
STATIC int
F_41 (
struct V_87 * V_80 ,
struct V_88 * V_89 ,
struct V_65 * V_43 ,
long V_4 )
{
struct V_90 * V_41 = F_19 ( V_43 ) ;
V_89 -> V_91 += V_4 ;
F_42 ( & V_41 -> V_44 , V_4 ) ;
F_43 ( V_80 , V_4 ) ;
if ( F_44 ( F_10 ( V_41 -> V_44 ) >
F_10 ( V_41 -> V_92 ) ) )
return V_79 ;
F_45 ( V_80 , V_43 , V_93 ) ;
return 0 ;
}
STATIC int
F_46 (
T_3 * args )
{
int error = 0 ;
ASSERT ( args -> V_21 > 0 ) ;
ASSERT ( args -> V_40 > 0 ) ;
ASSERT ( args -> V_21 <= args -> V_40 ) ;
ASSERT ( args -> V_38 < args -> V_39 ) ;
ASSERT ( args -> V_20 > 0 ) ;
args -> V_94 = 0 ;
switch ( args -> type ) {
case V_95 :
error = F_47 ( args ) ;
break;
case V_96 :
error = F_48 ( args ) ;
break;
case V_97 :
error = F_49 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error || args -> V_45 == V_35 )
return error ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_40 ) ;
ASSERT ( ! args -> V_94 || ! args -> V_98 ) ;
ASSERT ( args -> V_45 % args -> V_20 == 0 ) ;
if ( ! args -> V_94 ) {
error = F_41 ( args -> V_80 , args -> V_89 ,
args -> V_43 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_50 ( args -> V_68 , args -> V_81 ,
args -> V_45 , args -> V_4 ) ) ;
}
if ( ! args -> V_98 ) {
F_51 ( args -> V_80 , args -> V_99 ?
V_100 :
V_101 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
}
F_52 ( V_102 ) ;
F_53 ( V_103 , args -> V_4 ) ;
return error ;
}
STATIC int
F_49 (
T_3 * args )
{
T_5 * V_47 ;
T_5 * V_46 ;
int error ;
T_1 V_48 ;
T_2 V_49 ;
T_1 V_104 ;
T_2 V_105 ;
T_1 V_106 ;
int V_52 ;
ASSERT ( args -> V_20 == 1 ) ;
V_47 = F_54 ( args -> V_68 , args -> V_80 , args -> V_43 ,
args -> V_81 , V_107 ) ;
error = F_4 ( V_47 , args -> V_45 , args -> V_21 , & V_52 ) ;
if ( error )
goto V_108;
if ( ! V_52 )
goto V_109;
error = F_8 ( V_47 , & V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
ASSERT ( V_48 <= args -> V_45 ) ;
F_12 ( args , V_48 , V_49 , & V_104 , & V_105 ) ;
if ( V_104 > args -> V_45 )
goto V_109;
if ( V_105 < args -> V_21 )
goto V_109;
V_106 = V_104 + V_105 ;
if ( V_106 < args -> V_45 + args -> V_21 )
goto V_109;
args -> V_4 = F_56 ( V_106 , args -> V_45 + args -> V_40 )
- args -> V_45 ;
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_109;
ASSERT ( args -> V_45 + args -> V_4 <= V_106 ) ;
V_46 = F_54 ( args -> V_68 , args -> V_80 , args -> V_43 ,
args -> V_81 , V_110 ) ;
ASSERT ( args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_92 ) ) ;
error = F_20 ( V_46 , V_47 , V_48 , V_49 , args -> V_45 ,
args -> V_4 , V_58 ) ;
if ( error ) {
F_57 ( V_46 , V_111 ) ;
goto V_108;
}
F_57 ( V_47 , V_112 ) ;
F_57 ( V_46 , V_112 ) ;
args -> V_94 = 0 ;
F_58 ( args ) ;
return 0 ;
V_109:
F_57 ( V_47 , V_112 ) ;
args -> V_45 = V_35 ;
F_59 ( args ) ;
return 0 ;
V_108:
F_57 ( V_47 , V_111 ) ;
F_60 ( args ) ;
return error ;
}
STATIC int
F_61 (
struct V_113 * args ,
struct V_1 * * V_114 ,
struct V_1 * * V_115 ,
T_1 V_116 ,
T_1 * V_117 ,
T_2 * V_118 ,
T_1 * V_119 ,
T_2 * V_120 ,
int V_121 )
{
T_1 V_122 ;
T_1 V_123 ;
int error ;
int V_52 ;
if ( ! V_116 )
goto V_124;
do {
error = F_8 ( * V_115 , V_117 , V_118 , & V_52 ) ;
if ( error )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
F_11 ( args , * V_117 , * V_118 , V_119 , V_120 ) ;
if ( ! V_121 ) {
if ( * V_119 >= args -> V_45 + V_116 )
goto V_124;
} else {
if ( * V_119 <= args -> V_45 - V_116 )
goto V_124;
}
if ( * V_120 >= args -> V_21 ) {
args -> V_4 = F_15 ( * V_120 , args -> V_40 ) ;
F_17 ( args ) ;
V_123 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , * V_119 ,
* V_120 , & V_122 ) ;
if ( V_123 < V_116 )
goto V_125;
goto V_124;
}
if ( ! V_121 )
error = F_62 ( * V_115 , 0 , & V_52 ) ;
else
error = F_63 ( * V_115 , 0 , & V_52 ) ;
if ( error )
goto V_108;
} while ( V_52 );
V_124:
F_57 ( * V_115 , V_112 ) ;
* V_115 = NULL ;
return 0 ;
V_125:
F_57 ( * V_114 , V_112 ) ;
* V_114 = NULL ;
return 0 ;
V_108:
return error ;
}
STATIC int
F_48 (
T_3 * args )
{
T_5 * V_126 ;
T_5 * V_127 ;
T_5 * V_46 ;
T_1 V_128 ;
T_1 V_129 ;
T_2 V_130 ;
T_2 V_131 ;
T_2 V_132 ;
T_1 V_133 ;
int error ;
int V_52 ;
int V_134 ;
T_1 V_135 ;
T_1 V_136 ;
T_2 V_137 ;
T_2 V_138 ;
T_2 V_139 ;
T_1 V_140 ;
T_2 V_37 ;
int V_141 = 0 ;
#if F_64 ( F_21 ) && F_64 ( V_142 )
int V_143 ;
V_143 = F_65 () & 1 ;
#endif
V_144:
V_127 = NULL ;
V_126 = NULL ;
V_138 = 0 ;
V_132 = 0 ;
V_139 = 0 ;
V_46 = F_54 ( args -> V_68 , args -> V_80 , args -> V_43 ,
args -> V_81 , V_110 ) ;
if ( ( error = F_3 ( V_46 , 0 , args -> V_40 , & V_52 ) ) )
goto V_108;
if ( ! V_52 ) {
if ( ( error = F_66 ( args , V_46 , & V_135 ,
& V_138 , & V_52 ) ) )
goto V_108;
if ( V_52 == 0 || V_138 == 0 ) {
F_57 ( V_46 , V_112 ) ;
F_67 ( args ) ;
return 0 ;
}
ASSERT ( V_52 == 1 ) ;
}
args -> V_94 = 0 ;
while ( F_68 ( V_46 , 0 ) ) {
T_2 V_145 ;
int V_146 = 0 ;
T_2 V_147 = 0 ;
T_1 V_148 = 0 ;
#if F_64 ( F_21 ) && F_64 ( V_142 )
if ( ! V_143 )
break;
#endif
if ( V_138 || args -> V_20 > 1 ) {
V_46 -> V_149 [ 0 ] = 1 ;
do {
if ( ( error = F_8 ( V_46 , & V_135 ,
& V_138 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( V_138 >= args -> V_21 )
break;
if ( ( error = F_62 ( V_46 , 0 , & V_52 ) ) )
goto V_108;
} while ( V_52 );
ASSERT ( V_138 >= args -> V_21 ) ;
if ( ! V_52 )
break;
}
V_52 = V_46 -> V_149 [ 0 ] ;
for ( V_134 = 1 , V_147 = 0 , V_145 = 0 ;
! error && V_134 && ( V_147 < args -> V_40 || V_145 > 0 ) ;
error = F_62 ( V_46 , 0 , & V_134 ) ) {
if ( ( error = F_8 ( V_46 , & V_135 , & V_138 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
F_11 ( args , V_135 , V_138 ,
& V_136 , & V_139 ) ;
if ( V_139 < args -> V_21 )
continue;
args -> V_4 = F_15 ( V_139 , args -> V_40 ) ;
F_17 ( args ) ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
if ( args -> V_4 < V_147 )
continue;
V_137 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_136 , V_139 , & V_140 ) ;
if ( V_140 != V_35 &&
( args -> V_4 > V_147 || V_137 < V_145 ) ) {
V_145 = V_137 ;
V_148 = V_140 ;
V_147 = args -> V_4 ;
V_146 = V_46 -> V_149 [ 0 ] ;
}
}
if ( V_147 == 0 )
break;
V_46 -> V_149 [ 0 ] = V_146 ;
if ( ( error = F_8 ( V_46 , & V_135 , & V_138 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
ASSERT ( V_135 + V_138 <= F_10 ( F_19 ( args -> V_43 ) -> V_92 ) ) ;
args -> V_4 = V_147 ;
if ( ! F_18 ( args ) ) {
F_57 ( V_46 , V_112 ) ;
F_69 ( args ) ;
return 0 ;
}
V_147 = args -> V_4 ;
args -> V_45 = V_148 ;
ASSERT ( V_148 >= V_135 ) ;
ASSERT ( V_148 + V_147 <= V_135 + V_138 ) ;
V_127 = F_54 ( args -> V_68 , args -> V_80 ,
args -> V_43 , args -> V_81 , V_107 ) ;
if ( ( error = F_20 ( V_46 , V_127 , V_135 ,
V_138 , V_148 , V_147 , V_57 ) ) )
goto V_108;
F_57 ( V_46 , V_112 ) ;
F_57 ( V_127 , V_112 ) ;
F_70 ( args ) ;
return 0 ;
}
V_127 = F_54 ( args -> V_68 , args -> V_80 , args -> V_43 ,
args -> V_81 , V_107 ) ;
if ( ( error = F_4 ( V_127 , args -> V_45 , args -> V_40 , & V_52 ) ) )
goto V_108;
if ( ! V_52 ) {
V_126 = V_127 ;
V_127 = NULL ;
}
else if ( ( error = F_71 ( V_127 , & V_126 ) ) )
goto V_108;
if ( ( error = F_62 ( V_126 , 0 , & V_52 ) ) )
goto V_108;
if ( ! V_52 ) {
F_57 ( V_126 , V_112 ) ;
V_126 = NULL ;
}
do {
if ( V_127 ) {
if ( ( error = F_8 ( V_127 , & V_135 , & V_138 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
F_11 ( args , V_135 , V_138 ,
& V_136 , & V_139 ) ;
if ( V_139 >= args -> V_21 )
break;
if ( ( error = F_63 ( V_127 , 0 , & V_52 ) ) )
goto V_108;
if ( ! V_52 ) {
F_57 ( V_127 ,
V_112 ) ;
V_127 = NULL ;
}
}
if ( V_126 ) {
if ( ( error = F_8 ( V_126 , & V_128 , & V_131 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
F_11 ( args , V_128 , V_131 ,
& V_129 , & V_132 ) ;
if ( V_132 >= args -> V_21 )
break;
if ( ( error = F_62 ( V_126 , 0 , & V_52 ) ) )
goto V_108;
if ( ! V_52 ) {
F_57 ( V_126 ,
V_112 ) ;
V_126 = NULL ;
}
}
} while ( V_127 || V_126 );
if ( V_127 && V_126 ) {
if ( V_139 >= args -> V_21 ) {
args -> V_4 = F_15 ( V_139 , args -> V_40 ) ;
F_17 ( args ) ;
V_137 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_136 , V_139 , & V_140 ) ;
error = F_61 ( args ,
& V_127 , & V_126 ,
V_137 , & V_128 , & V_131 ,
& V_129 , & V_132 ,
0 ) ;
} else {
ASSERT ( V_132 >= args -> V_21 ) ;
args -> V_4 = F_15 ( V_132 , args -> V_40 ) ;
F_17 ( args ) ;
V_130 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_129 , V_132 , & V_133 ) ;
error = F_61 ( args ,
& V_126 , & V_127 ,
V_130 , & V_135 , & V_138 ,
& V_136 , & V_139 ,
1 ) ;
}
if ( error )
goto V_108;
}
if ( V_127 == NULL && V_126 == NULL ) {
F_57 ( V_46 , V_112 ) ;
if ( ! V_141 ++ ) {
F_72 ( args ) ;
F_73 ( args -> V_68 , V_150 ) ;
goto V_144;
}
F_74 ( args ) ;
args -> V_45 = V_35 ;
return 0 ;
}
if ( V_126 ) {
V_127 = V_126 ;
V_126 = NULL ;
V_135 = V_128 ;
V_136 = V_129 ;
V_138 = V_131 ;
V_139 = V_132 ;
V_134 = 1 ;
} else
V_134 = 0 ;
args -> V_4 = F_15 ( V_139 , args -> V_40 ) ;
F_17 ( args ) ;
if ( ! F_18 ( args ) ) {
F_69 ( args ) ;
F_57 ( V_127 , V_112 ) ;
F_57 ( V_46 , V_112 ) ;
return 0 ;
}
V_37 = args -> V_4 ;
( void ) F_14 ( args -> V_45 , V_37 , args -> V_20 ,
V_136 , V_139 , & V_140 ) ;
ASSERT ( V_140 >= V_135 ) ;
ASSERT ( V_140 + V_37 <= V_136 + V_139 ) ;
ASSERT ( V_140 + V_37 <= F_10 ( F_19 ( args -> V_43 ) -> V_92 ) ) ;
args -> V_45 = V_140 ;
if ( ( error = F_20 ( V_46 , V_127 , V_135 , V_138 ,
V_140 , V_37 , V_58 ) ) )
goto V_108;
if ( V_134 )
F_75 ( args ) ;
else
F_76 ( args ) ;
F_57 ( V_46 , V_112 ) ;
F_57 ( V_127 , V_112 ) ;
return 0 ;
V_108:
F_77 ( args ) ;
if ( V_46 != NULL )
F_57 ( V_46 , V_111 ) ;
if ( V_127 != NULL )
F_57 ( V_127 , V_111 ) ;
if ( V_126 != NULL )
F_57 ( V_126 , V_111 ) ;
return error ;
}
STATIC int
F_47 (
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
int V_141 = 0 ;
V_144:
V_46 = F_54 ( args -> V_68 , args -> V_80 , args -> V_43 ,
args -> V_81 , V_110 ) ;
V_47 = NULL ;
if ( ( error = F_3 ( V_46 , 0 ,
args -> V_40 + args -> V_20 - 1 , & V_52 ) ) )
goto V_108;
if ( ! V_52 || V_141 > 1 ) {
error = F_66 ( args , V_46 ,
& V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_108;
if ( V_52 == 0 || V_49 == 0 ) {
F_57 ( V_46 , V_112 ) ;
F_78 ( args ) ;
return 0 ;
}
ASSERT ( V_52 == 1 ) ;
F_11 ( args , V_48 , V_49 , & V_50 , & V_37 ) ;
} else {
for (; ; ) {
error = F_8 ( V_46 , & V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
F_11 ( args , V_48 , V_49 ,
& V_50 , & V_37 ) ;
if ( V_37 >= args -> V_40 )
break;
error = F_62 ( V_46 , 0 , & V_52 ) ;
if ( error )
goto V_108;
if ( V_52 == 0 ) {
F_57 ( V_46 ,
V_112 ) ;
F_79 ( args ) ;
if ( ! V_141 ++ )
F_73 ( args -> V_68 , V_150 ) ;
goto V_144;
}
}
}
V_37 = F_15 ( args -> V_40 , V_37 ) ;
F_55 ( V_37 == 0 ||
( V_37 <= V_49 && V_50 + V_37 <= V_48 + V_49 ) , V_108 ) ;
if ( V_37 < args -> V_40 ) {
T_1 V_151 ;
T_2 V_152 ;
T_1 V_153 ;
T_2 V_154 ;
V_154 = V_37 ;
V_153 = V_50 ;
V_152 = V_49 ;
V_151 = V_48 ;
for (; ; ) {
if ( ( error = F_63 ( V_46 , 0 , & V_52 ) ) )
goto V_108;
if ( V_52 == 0 )
break;
if ( ( error = F_8 ( V_46 , & V_48 , & V_49 ,
& V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( V_49 < V_154 )
break;
F_11 ( args , V_48 , V_49 ,
& V_50 , & V_37 ) ;
V_37 = F_15 ( args -> V_40 , V_37 ) ;
F_55 ( V_37 == 0 ||
( V_37 <= V_49 && V_50 + V_37 <= V_48 + V_49 ) ,
V_108 ) ;
if ( V_37 > V_154 ) {
V_154 = V_37 ;
V_153 = V_50 ;
V_152 = V_49 ;
V_151 = V_48 ;
if ( V_37 == args -> V_40 )
break;
}
}
if ( ( error = F_1 ( V_46 , V_151 , V_152 ,
& V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
V_37 = V_154 ;
V_50 = V_153 ;
V_49 = V_152 ;
V_48 = V_151 ;
}
args -> V_94 = 0 ;
args -> V_4 = V_37 ;
if ( V_37 < args -> V_21 ) {
if ( ! V_141 ++ ) {
F_57 ( V_46 , V_112 ) ;
F_79 ( args ) ;
F_73 ( args -> V_68 , V_150 ) ;
goto V_144;
}
goto V_155;
}
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_155;
V_37 = args -> V_4 ;
F_55 ( V_37 <= V_49 , V_108 ) ;
V_47 = F_54 ( args -> V_68 , args -> V_80 , args -> V_43 ,
args -> V_81 , V_107 ) ;
if ( ( error = F_20 ( V_46 , V_47 , V_48 , V_49 ,
V_50 , V_37 , V_57 ) ) )
goto V_108;
F_57 ( V_46 , V_112 ) ;
F_57 ( V_47 , V_112 ) ;
V_46 = V_47 = NULL ;
args -> V_4 = V_37 ;
args -> V_45 = V_50 ;
F_55 (
args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_92 ) ,
V_108 ) ;
F_80 ( args ) ;
return 0 ;
V_108:
F_81 ( args ) ;
if ( V_46 )
F_57 ( V_46 , V_111 ) ;
if ( V_47 )
F_57 ( V_47 , V_111 ) ;
return error ;
V_155:
F_57 ( V_46 , V_112 ) ;
F_82 ( args ) ;
args -> V_45 = V_35 ;
return 0 ;
}
STATIC int
F_66 (
T_3 * args ,
T_5 * V_156 ,
T_1 * V_157 ,
T_2 * V_158 ,
int * V_5 )
{
int error ;
T_1 V_48 ;
T_2 V_49 ;
int V_52 ;
if ( ( error = F_63 ( V_156 , 0 , & V_52 ) ) )
goto V_108;
if ( V_52 ) {
if ( ( error = F_8 ( V_156 , & V_48 , & V_49 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
}
else if ( args -> V_21 == 1 && args -> V_20 == 1 && ! args -> V_98 &&
( F_10 ( F_19 ( args -> V_43 ) -> V_159 )
> args -> V_42 ) ) {
error = F_83 ( args -> V_80 , args -> V_43 , & V_48 , 0 ) ;
if ( error )
goto V_108;
if ( V_48 != V_35 ) {
F_84 ( args -> V_68 , args -> V_81 , V_48 , 1 ,
args -> V_160 ) ;
if ( args -> V_160 ) {
T_9 * V_66 ;
V_66 = F_85 ( args -> V_68 , args -> V_80 ,
args -> V_81 , V_48 , 0 ) ;
F_86 ( args -> V_80 , V_66 ) ;
}
args -> V_4 = 1 ;
args -> V_45 = V_48 ;
F_55 (
args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_92 ) ,
V_108 ) ;
args -> V_94 = 1 ;
F_87 ( args ) ;
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
F_88 ( args ) ;
V_49 = 0 ;
}
* V_157 = V_48 ;
* V_158 = V_49 ;
* V_5 = 1 ;
F_89 ( args ) ;
return 0 ;
V_108:
F_90 ( args ) ;
return error ;
}
STATIC int
F_91 (
T_7 * V_80 ,
T_9 * V_43 ,
T_8 V_81 ,
T_1 V_3 ,
T_2 V_4 ,
int V_98 )
{
T_5 * V_47 ;
T_5 * V_46 ;
int error ;
T_1 V_128 ;
T_2 V_131 ;
int V_161 ;
int V_162 ;
int V_52 ;
T_1 V_135 ;
T_2 V_138 ;
T_6 * V_68 ;
T_1 V_163 ;
T_2 V_164 ;
T_10 * V_89 ;
V_68 = V_80 -> V_165 ;
V_47 = F_54 ( V_68 , V_80 , V_43 , V_81 , V_107 ) ;
V_46 = NULL ;
if ( ( error = F_4 ( V_47 , V_3 , V_4 , & V_161 ) ) )
goto V_108;
if ( V_161 ) {
if ( ( error = F_8 ( V_47 , & V_135 , & V_138 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( V_135 + V_138 < V_3 )
V_161 = 0 ;
else {
F_55 ( V_135 + V_138 <= V_3 , V_108 ) ;
}
}
if ( ( error = F_62 ( V_47 , 0 , & V_162 ) ) )
goto V_108;
if ( V_162 ) {
if ( ( error = F_8 ( V_47 , & V_128 , & V_131 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( V_3 + V_4 < V_128 )
V_162 = 0 ;
else {
F_55 ( V_128 >= V_3 + V_4 , V_108 ) ;
}
}
V_46 = F_54 ( V_68 , V_80 , V_43 , V_81 , V_110 ) ;
if ( V_161 && V_162 ) {
if ( ( error = F_1 ( V_46 , V_135 , V_138 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( ( error = F_1 ( V_46 , V_128 , V_131 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( ( error = F_24 ( V_47 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( ( error = F_63 ( V_47 , 0 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
#ifdef F_21
{
T_1 V_166 ;
T_2 V_167 ;
if ( ( error = F_8 ( V_47 , & V_166 , & V_167 ,
& V_52 ) ) )
goto V_108;
F_55 (
V_52 == 1 && V_166 == V_135 && V_167 == V_138 ,
V_108 ) ;
}
#endif
V_163 = V_135 ;
V_164 = V_4 + V_138 + V_131 ;
if ( ( error = F_5 ( V_47 , V_163 , V_164 ) ) )
goto V_108;
}
else if ( V_161 ) {
if ( ( error = F_1 ( V_46 , V_135 , V_138 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( ( error = F_63 ( V_47 , 0 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
V_163 = V_135 ;
V_164 = V_4 + V_138 ;
if ( ( error = F_5 ( V_47 , V_163 , V_164 ) ) )
goto V_108;
}
else if ( V_162 ) {
if ( ( error = F_1 ( V_46 , V_128 , V_131 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
V_163 = V_3 ;
V_164 = V_4 + V_131 ;
if ( ( error = F_5 ( V_47 , V_163 , V_164 ) ) )
goto V_108;
}
else {
V_163 = V_3 ;
V_164 = V_4 ;
if ( ( error = F_25 ( V_47 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
}
F_57 ( V_47 , V_112 ) ;
V_47 = NULL ;
if ( ( error = F_1 ( V_46 , V_163 , V_164 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 0 , V_108 ) ;
if ( ( error = F_25 ( V_46 , & V_52 ) ) )
goto V_108;
F_55 ( V_52 == 1 , V_108 ) ;
F_57 ( V_46 , V_112 ) ;
V_46 = NULL ;
V_89 = F_92 ( V_68 , V_81 ) ;
error = F_41 ( V_80 , V_89 , V_43 , V_4 ) ;
F_93 ( V_89 ) ;
if ( error )
goto V_108;
if ( ! V_98 )
F_51 ( V_80 , V_101 , ( long ) V_4 ) ;
F_52 ( V_168 ) ;
F_53 ( V_169 , V_4 ) ;
F_94 ( V_68 , V_81 , V_3 , V_4 , V_98 , V_161 , V_162 ) ;
return 0 ;
V_108:
F_94 ( V_68 , V_81 , V_3 , V_4 , V_98 , - 1 , - 1 ) ;
if ( V_47 )
F_57 ( V_47 , V_111 ) ;
if ( V_46 )
F_57 ( V_46 , V_111 ) ;
return error ;
}
void
F_95 (
T_6 * V_68 )
{
int V_170 ;
T_11 V_171 ;
T_11 V_172 ;
int V_173 ;
int V_174 ;
V_172 = ( V_68 -> V_75 . V_76 + 1 ) / 2 ;
V_173 = V_68 -> V_175 [ 0 ] ;
V_174 = V_68 -> V_175 [ 1 ] ;
V_171 = ( V_172 + V_173 - 1 ) / V_173 ;
for ( V_170 = 1 ; V_171 > 1 ; V_170 ++ )
V_171 = ( V_171 + V_174 - 1 ) / V_174 ;
V_68 -> V_176 = V_170 ;
}
T_2
F_96 (
struct V_67 * V_68 ,
struct V_88 * V_89 )
{
T_2 V_177 , V_178 = 0 ;
V_177 = F_97 ( V_89 , V_68 ) ;
if ( V_177 > V_89 -> V_179 )
V_178 = V_177 - V_89 -> V_179 ;
if ( V_89 -> V_180 > V_178 )
return V_89 -> V_180 - V_178 ;
return V_89 -> V_179 > 0 || V_89 -> V_180 > 0 ;
}
STATIC int
F_98 (
T_3 * args ,
int V_51 )
{
T_9 * V_43 ;
T_4 * V_41 ;
T_9 * V_181 ;
T_1 V_3 ;
T_2 V_178 ;
int error ;
T_2 V_182 ;
T_6 * V_68 ;
T_2 V_177 ;
T_10 * V_89 ;
T_3 V_183 ;
T_7 * V_80 ;
V_68 = args -> V_68 ;
V_89 = args -> V_89 ;
V_80 = args -> V_80 ;
if ( ! V_89 -> V_184 ) {
if ( ( error = F_99 ( V_68 , V_80 , args -> V_81 , V_51 ,
& V_43 ) ) )
return error ;
if ( ! V_89 -> V_184 ) {
ASSERT ( V_51 & V_185 ) ;
ASSERT ( ! ( V_51 & V_186 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
} else
V_43 = NULL ;
if ( V_89 -> V_187 && args -> V_160 &&
( V_51 & V_185 ) ) {
ASSERT ( ! ( V_51 & V_186 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
if ( ! ( V_51 & V_186 ) ) {
V_177 = F_97 ( V_89 , V_68 ) ;
V_182 = F_96 ( V_68 , V_89 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_188 - 1 ) >
V_182 ||
( ( int ) ( V_89 -> V_91 + V_89 -> V_179 -
V_177 - args -> V_189 ) < ( int ) args -> V_42 ) ) {
if ( V_43 )
F_100 ( V_80 , V_43 ) ;
args -> V_43 = NULL ;
return 0 ;
}
}
if ( V_43 == NULL ) {
if ( ( error = F_99 ( V_68 , V_80 , args -> V_81 , V_51 ,
& V_43 ) ) )
return error ;
if ( V_43 == NULL ) {
ASSERT ( V_51 & V_185 ) ;
ASSERT ( ! ( V_51 & V_186 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
}
V_41 = F_19 ( V_43 ) ;
V_177 = F_101 ( V_41 , V_68 ) ;
if ( ! ( V_51 & V_186 ) ) {
V_178 = V_177 > F_10 ( V_41 -> V_159 ) ?
( V_177 - F_10 ( V_41 -> V_159 ) ) : 0 ;
V_182 = F_10 ( V_41 -> V_190 ) ;
V_182 = ( V_182 > V_178 ) ? ( V_182 - V_178 ) :
( F_10 ( V_41 -> V_159 ) > 0 || V_182 > 0 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_188 - 1 ) >
V_182 ||
( ( int ) ( F_10 ( V_41 -> V_44 ) +
F_10 ( V_41 -> V_159 ) - V_177 - args -> V_189 ) <
( int ) args -> V_42 ) ) {
F_100 ( V_80 , V_43 ) ;
args -> V_43 = NULL ;
return 0 ;
}
}
while ( F_10 ( V_41 -> V_159 ) > V_177 ) {
T_9 * V_66 ;
error = F_83 ( V_80 , V_43 , & V_3 , 0 ) ;
if ( error )
return error ;
if ( ( error = F_91 ( V_80 , V_43 , args -> V_81 , V_3 , 1 , 1 ) ) )
return error ;
V_66 = F_85 ( V_68 , V_80 , args -> V_81 , V_3 , 0 ) ;
F_86 ( V_80 , V_66 ) ;
}
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
V_183 . V_80 = V_80 ;
V_183 . V_68 = V_68 ;
V_183 . V_43 = V_43 ;
V_183 . V_81 = args -> V_81 ;
V_183 . V_38 = V_183 . V_42 = V_183 . V_99 = V_183 . V_160 =
V_183 . V_188 = 0 ;
V_183 . V_20 = V_183 . V_21 = V_183 . V_39 = V_183 . V_98 = 1 ;
V_183 . type = V_95 ;
V_183 . V_89 = V_89 ;
if ( ( error = F_34 ( V_68 , V_80 , V_183 . V_81 , & V_181 ) ) )
return error ;
while ( F_10 ( V_41 -> V_159 ) < V_177 ) {
V_183 . V_45 = 0 ;
V_183 . V_40 = V_177 - F_10 ( V_41 -> V_159 ) ;
if ( ( error = F_46 ( & V_183 ) ) ) {
F_100 ( V_80 , V_181 ) ;
return error ;
}
if ( V_183 . V_45 == V_35 ) {
if ( V_51 & V_186 )
break;
F_100 ( V_80 , V_181 ) ;
args -> V_43 = NULL ;
return 0 ;
}
for ( V_3 = V_183 . V_45 ; V_3 < V_183 . V_45 + V_183 . V_4 ; V_3 ++ ) {
error = F_102 ( V_80 , V_43 ,
V_181 , V_3 , 0 ) ;
if ( error )
return error ;
}
}
F_100 ( V_80 , V_181 ) ;
args -> V_43 = V_43 ;
return 0 ;
}
int
F_83 (
T_7 * V_80 ,
T_9 * V_43 ,
T_1 * V_191 ,
int V_192 )
{
T_4 * V_41 ;
T_12 * V_72 ;
T_9 * V_181 ;
T_1 V_3 ;
int error ;
int V_193 ;
T_6 * V_68 ;
T_10 * V_89 ;
V_41 = F_19 ( V_43 ) ;
if ( ! V_41 -> V_159 ) {
* V_191 = V_35 ;
return 0 ;
}
V_68 = V_80 -> V_165 ;
if ( ( error = F_34 ( V_68 , V_80 ,
F_10 ( V_41 -> V_194 ) , & V_181 ) ) )
return error ;
V_72 = F_28 ( V_181 ) ;
V_3 = F_10 ( V_72 -> V_74 [ F_10 ( V_41 -> V_195 ) ] ) ;
F_42 ( & V_41 -> V_195 , 1 ) ;
F_100 ( V_80 , V_181 ) ;
if ( F_10 ( V_41 -> V_195 ) == F_29 ( V_68 ) )
V_41 -> V_195 = 0 ;
V_89 = F_92 ( V_68 , F_10 ( V_41 -> V_194 ) ) ;
F_42 ( & V_41 -> V_159 , - 1 ) ;
F_103 ( V_80 , - 1 ) ;
V_89 -> V_179 -- ;
F_93 ( V_89 ) ;
V_193 = V_196 | V_197 ;
if ( V_192 ) {
F_42 ( & V_41 -> V_198 , 1 ) ;
V_89 -> V_199 ++ ;
V_193 |= V_200 ;
}
F_45 ( V_80 , V_43 , V_193 ) ;
* V_191 = V_3 ;
return 0 ;
}
void
F_45 (
T_7 * V_80 ,
T_9 * V_66 ,
int V_201 )
{
int V_202 ;
int V_203 ;
static const short V_204 [] = {
F_104 ( T_4 , V_205 ) ,
F_104 ( T_4 , V_206 ) ,
F_104 ( T_4 , V_194 ) ,
F_104 ( T_4 , V_92 ) ,
F_104 ( T_4 , V_207 [ 0 ] ) ,
F_104 ( T_4 , V_208 [ 0 ] ) ,
F_104 ( T_4 , V_195 ) ,
F_104 ( T_4 , V_209 ) ,
F_104 ( T_4 , V_159 ) ,
F_104 ( T_4 , V_44 ) ,
F_104 ( T_4 , V_190 ) ,
F_104 ( T_4 , V_198 ) ,
sizeof( T_4 )
} ;
F_105 ( V_80 -> V_165 , F_19 ( V_66 ) , V_201 , V_210 ) ;
F_106 ( V_201 , V_204 , V_211 , & V_202 , & V_203 ) ;
F_107 ( V_80 , V_66 , ( T_11 ) V_202 , ( T_11 ) V_203 ) ;
}
int
F_108 (
T_6 * V_68 ,
T_7 * V_80 ,
T_8 V_81 ,
int V_51 )
{
T_9 * V_66 ;
int error ;
if ( ( error = F_99 ( V_68 , V_80 , V_81 , V_51 , & V_66 ) ) )
return error ;
if ( V_66 )
F_100 ( V_80 , V_66 ) ;
return 0 ;
}
int
F_102 (
T_7 * V_80 ,
T_9 * V_43 ,
T_9 * V_181 ,
T_1 V_3 ,
int V_192 )
{
T_4 * V_41 ;
T_12 * V_72 ;
T_13 * V_212 ;
int error ;
int V_193 ;
T_6 * V_68 ;
T_10 * V_89 ;
V_41 = F_19 ( V_43 ) ;
V_68 = V_80 -> V_165 ;
if ( ! V_181 && ( error = F_34 ( V_68 , V_80 ,
F_10 ( V_41 -> V_194 ) , & V_181 ) ) )
return error ;
V_72 = F_28 ( V_181 ) ;
F_42 ( & V_41 -> V_209 , 1 ) ;
if ( F_10 ( V_41 -> V_209 ) == F_29 ( V_68 ) )
V_41 -> V_209 = 0 ;
V_89 = F_92 ( V_68 , F_10 ( V_41 -> V_194 ) ) ;
F_42 ( & V_41 -> V_159 , 1 ) ;
F_103 ( V_80 , 1 ) ;
V_89 -> V_179 ++ ;
V_193 = V_213 | V_197 ;
if ( V_192 ) {
F_42 ( & V_41 -> V_198 , - 1 ) ;
V_89 -> V_199 -- ;
V_193 |= V_200 ;
}
F_93 ( V_89 ) ;
F_45 ( V_80 , V_43 , V_193 ) ;
ASSERT ( F_10 ( V_41 -> V_159 ) <= F_29 ( V_68 ) ) ;
V_212 = & V_72 -> V_74 [ F_10 ( V_41 -> V_209 ) ] ;
* V_212 = F_6 ( V_3 ) ;
F_45 ( V_80 , V_43 , V_193 ) ;
F_107 ( V_80 , V_181 ,
( int ) ( ( V_214 ) V_212 - ( V_214 ) V_72 ) ,
( int ) ( ( V_214 ) V_212 - ( V_214 ) V_72 +
sizeof( T_1 ) - 1 ) ) ;
return 0 ;
}
static void
F_109 (
struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 -> V_70 ;
struct V_90 * V_41 ;
int V_215 ;
V_41 = F_19 ( V_66 ) ;
V_215 = V_41 -> V_205 == F_6 ( V_216 ) &&
F_110 ( F_10 ( V_41 -> V_206 ) ) &&
F_10 ( V_41 -> V_44 ) <= F_10 ( V_41 -> V_92 ) &&
F_10 ( V_41 -> V_195 ) < F_29 ( V_68 ) &&
F_10 ( V_41 -> V_209 ) < F_29 ( V_68 ) &&
F_10 ( V_41 -> V_159 ) <= F_29 ( V_68 ) ;
if ( V_66 -> V_217 )
V_215 = V_215 && F_10 ( V_41 -> V_194 ) ==
V_66 -> V_217 -> V_218 ;
if ( F_111 ( & V_68 -> V_75 ) )
V_215 = V_215 && F_10 ( V_41 -> V_198 ) <=
F_10 ( V_41 -> V_92 ) ;
if ( F_44 ( F_112 ( ! V_215 , V_68 , V_219 ,
V_220 ) ) ) {
F_30 ( V_77 , V_78 , V_68 , V_41 ) ;
F_31 ( V_66 , V_79 ) ;
}
}
static void
F_113 (
struct V_65 * V_66 )
{
F_109 ( V_66 ) ;
}
static void
F_114 (
struct V_65 * V_66 )
{
F_109 ( V_66 ) ;
}
int
F_115 (
struct V_67 * V_68 ,
struct V_87 * V_80 ,
T_8 V_81 ,
int V_51 ,
struct V_65 * * V_82 )
{
int error ;
ASSERT ( V_81 != V_83 ) ;
error = F_35 (
V_68 , V_80 , V_68 -> V_84 ,
F_36 ( V_68 , V_81 , F_116 ( V_68 ) ) ,
F_38 ( V_68 , 1 ) , V_51 , V_82 , & V_221 ) ;
if ( error )
return error ;
if ( ! * V_82 )
return 0 ;
ASSERT ( ! ( * V_82 ) -> V_222 ) ;
F_40 ( * V_82 , V_223 ) ;
return 0 ;
}
int
F_99 (
struct V_67 * V_68 ,
struct V_87 * V_80 ,
T_8 V_81 ,
int V_51 ,
struct V_65 * * V_82 )
{
struct V_90 * V_41 ;
struct V_88 * V_89 ;
int error ;
ASSERT ( V_81 != V_83 ) ;
error = F_115 ( V_68 , V_80 , V_81 ,
( V_51 & V_185 ) ? V_224 : 0 ,
V_82 ) ;
if ( error )
return error ;
if ( ! * V_82 )
return 0 ;
ASSERT ( ! ( * V_82 ) -> V_222 ) ;
V_41 = F_19 ( * V_82 ) ;
V_89 = F_92 ( V_68 , V_81 ) ;
if ( ! V_89 -> V_184 ) {
V_89 -> V_91 = F_10 ( V_41 -> V_44 ) ;
V_89 -> V_199 = F_10 ( V_41 -> V_198 ) ;
V_89 -> V_179 = F_10 ( V_41 -> V_159 ) ;
V_89 -> V_180 = F_10 ( V_41 -> V_190 ) ;
V_89 -> V_225 [ V_226 ] =
F_10 ( V_41 -> V_208 [ V_226 ] ) ;
V_89 -> V_225 [ V_227 ] =
F_10 ( V_41 -> V_208 [ V_227 ] ) ;
F_117 ( & V_89 -> V_228 ) ;
V_89 -> V_229 = 0 ;
V_89 -> V_230 = V_231 ;
V_89 -> V_184 = 1 ;
}
#ifdef F_21
else if ( ! F_118 ( V_68 ) ) {
ASSERT ( V_89 -> V_91 == F_10 ( V_41 -> V_44 ) ) ;
ASSERT ( V_89 -> V_199 == F_10 ( V_41 -> V_198 ) ) ;
ASSERT ( V_89 -> V_179 == F_10 ( V_41 -> V_159 ) ) ;
ASSERT ( V_89 -> V_180 == F_10 ( V_41 -> V_190 ) ) ;
ASSERT ( V_89 -> V_225 [ V_226 ] ==
F_10 ( V_41 -> V_208 [ V_226 ] ) ) ;
ASSERT ( V_89 -> V_225 [ V_227 ] ==
F_10 ( V_41 -> V_208 [ V_227 ] ) ) ;
}
#endif
F_93 ( V_89 ) ;
return 0 ;
}
int
F_119 (
T_3 * args )
{
T_1 V_232 ;
int error ;
int V_51 ;
T_2 V_42 ;
T_6 * V_68 ;
T_8 V_233 ;
T_14 type ;
int V_234 = 0 ;
int V_235 = 0 ;
T_8 V_236 = V_237 ;
V_68 = args -> V_68 ;
type = args -> V_238 = args -> type ;
args -> V_45 = V_35 ;
V_232 = V_68 -> V_75 . V_76 ;
if ( args -> V_40 > V_232 )
args -> V_40 = V_232 ;
if ( args -> V_20 == 0 )
args -> V_20 = 1 ;
ASSERT ( F_120 ( V_68 , args -> V_239 ) < V_68 -> V_75 . V_240 ) ;
ASSERT ( F_121 ( V_68 , args -> V_239 ) < V_232 ) ;
ASSERT ( args -> V_21 <= args -> V_40 ) ;
ASSERT ( args -> V_21 <= V_232 ) ;
ASSERT ( args -> V_38 < args -> V_39 ) ;
if ( F_120 ( V_68 , args -> V_239 ) >= V_68 -> V_75 . V_240 ||
F_121 ( V_68 , args -> V_239 ) >= V_232 ||
args -> V_21 > args -> V_40 || args -> V_21 > V_232 ||
args -> V_38 >= args -> V_39 ) {
args -> V_239 = V_241 ;
F_122 ( args ) ;
return 0 ;
}
V_42 = args -> V_42 ;
switch ( type ) {
case V_95 :
case V_96 :
case V_97 :
args -> V_81 = F_120 ( V_68 , args -> V_239 ) ;
args -> V_89 = F_92 ( V_68 , args -> V_81 ) ;
args -> V_42 = 0 ;
error = F_98 ( args , 0 ) ;
args -> V_42 = V_42 ;
if ( error ) {
F_123 ( args ) ;
goto V_108;
}
if ( ! args -> V_43 ) {
F_124 ( args ) ;
break;
}
args -> V_45 = F_121 ( V_68 , args -> V_239 ) ;
if ( ( error = F_46 ( args ) ) )
goto V_108;
break;
case V_242 :
if ( ( args -> V_160 == V_243 ) &&
( V_68 -> V_244 & V_245 ) ) {
args -> V_239 = F_125 ( V_68 ,
( ( V_68 -> V_246 / V_236 ) %
V_68 -> V_75 . V_240 ) , 0 ) ;
V_234 = 1 ;
}
args -> V_45 = F_121 ( V_68 , args -> V_239 ) ;
args -> type = V_96 ;
case V_247 :
case V_248 :
case V_249 :
if ( type == V_247 ) {
args -> V_81 = V_233 = ( V_68 -> V_246 / V_236 ) %
V_68 -> V_75 . V_240 ;
args -> type = V_95 ;
V_51 = V_185 ;
} else if ( type == V_249 ) {
args -> V_81 = F_120 ( V_68 , args -> V_239 ) ;
args -> type = V_95 ;
V_233 = 0 ;
V_51 = 0 ;
} else {
if ( type == V_248 )
args -> type = V_95 ;
args -> V_81 = V_233 = F_120 ( V_68 , args -> V_239 ) ;
V_51 = V_185 ;
}
for (; ; ) {
args -> V_89 = F_92 ( V_68 , args -> V_81 ) ;
if ( V_235 ) args -> V_42 = 0 ;
error = F_98 ( args , V_51 ) ;
args -> V_42 = V_42 ;
if ( error ) {
F_123 ( args ) ;
goto V_108;
}
if ( args -> V_43 ) {
if ( ( error = F_46 ( args ) ) )
goto V_108;
break;
}
F_126 ( args ) ;
if ( args -> V_81 == V_233 &&
type == V_242 )
args -> type = V_95 ;
if ( ++ ( args -> V_81 ) == V_68 -> V_75 . V_240 ) {
if ( args -> V_250 != V_241 )
args -> V_81 = V_233 ;
else
args -> V_81 = 0 ;
}
if ( args -> V_81 == V_233 ) {
if ( V_235 == 1 ) {
args -> V_45 = V_35 ;
F_127 ( args ) ;
break;
}
if ( V_51 == 0 ) {
V_235 = 1 ;
} else {
V_51 = 0 ;
if ( type == V_242 ) {
args -> V_45 = F_121 ( V_68 ,
args -> V_239 ) ;
args -> type = V_96 ;
}
}
}
F_93 ( args -> V_89 ) ;
}
if ( V_234 || ( type == V_247 ) ) {
if ( args -> V_81 == V_233 )
V_68 -> V_246 = ( V_68 -> V_246 + 1 ) %
( V_68 -> V_75 . V_240 * V_236 ) ;
else
V_68 -> V_246 = ( args -> V_81 * V_236 + 1 ) %
( V_68 -> V_75 . V_240 * V_236 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_45 == V_35 )
args -> V_239 = V_241 ;
else {
args -> V_239 = F_125 ( V_68 , args -> V_81 , args -> V_45 ) ;
#ifdef F_21
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_40 ) ;
ASSERT ( args -> V_45 % args -> V_20 == 0 ) ;
F_128 ( V_68 , F_129 ( V_68 , args -> V_239 ) ,
args -> V_4 ) ;
#endif
}
F_93 ( args -> V_89 ) ;
return 0 ;
V_108:
F_93 ( args -> V_89 ) ;
return error ;
}
int
F_130 (
T_7 * V_80 ,
T_15 V_3 ,
T_2 V_4 )
{
T_3 args ;
int error ;
ASSERT ( V_4 != 0 ) ;
memset ( & args , 0 , sizeof( T_3 ) ) ;
args . V_80 = V_80 ;
args . V_68 = V_80 -> V_165 ;
args . V_81 = F_120 ( args . V_68 , V_3 ) ;
if ( args . V_81 >= args . V_68 -> V_75 . V_240 )
return V_79 ;
args . V_45 = F_121 ( args . V_68 , V_3 ) ;
if ( args . V_45 >= args . V_68 -> V_75 . V_76 )
return V_79 ;
args . V_89 = F_92 ( args . V_68 , args . V_81 ) ;
ASSERT ( args . V_89 ) ;
error = F_98 ( & args , V_186 ) ;
if ( error )
goto V_108;
if ( args . V_45 + V_4 >
F_10 ( F_19 ( args . V_43 ) -> V_92 ) ) {
error = V_79 ;
goto V_108;
}
error = F_91 ( V_80 , args . V_43 , args . V_81 , args . V_45 , V_4 , 0 ) ;
if ( ! error )
F_131 ( V_80 , args . V_81 , args . V_45 , V_4 , 0 ) ;
V_108:
F_93 ( args . V_89 ) ;
return error ;
}
