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
STATIC int
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
STATIC int
F_26 (
T_6 * V_65 ,
T_7 * V_66 ,
T_8 V_67 ,
T_9 * * V_68 )
{
T_9 * V_69 ;
int error ;
ASSERT ( V_67 != V_70 ) ;
error = F_27 (
V_65 , V_66 , V_65 -> V_71 ,
F_28 ( V_65 , V_67 , F_29 ( V_65 ) ) ,
F_30 ( V_65 , 1 ) , 0 , & V_69 ) ;
if ( error )
return error ;
ASSERT ( ! F_31 ( V_69 ) ) ;
F_32 ( V_69 , V_72 , V_73 ) ;
* V_68 = V_69 ;
return 0 ;
}
STATIC int
F_33 (
struct V_74 * V_66 ,
struct V_75 * V_76 ,
struct V_77 * V_43 ,
long V_4 )
{
struct V_78 * V_41 = F_19 ( V_43 ) ;
V_76 -> V_79 += V_4 ;
F_34 ( & V_41 -> V_44 , V_4 ) ;
F_35 ( V_66 , V_4 ) ;
if ( F_36 ( F_10 ( V_41 -> V_44 ) >
F_10 ( V_41 -> V_80 ) ) )
return V_81 ;
F_37 ( V_66 , V_43 , V_82 ) ;
return 0 ;
}
STATIC int
F_38 (
T_3 * args )
{
int error = 0 ;
ASSERT ( args -> V_21 > 0 ) ;
ASSERT ( args -> V_40 > 0 ) ;
ASSERT ( args -> V_21 <= args -> V_40 ) ;
ASSERT ( args -> V_38 < args -> V_39 ) ;
ASSERT ( args -> V_20 > 0 ) ;
args -> V_83 = 0 ;
switch ( args -> type ) {
case V_84 :
error = F_39 ( args ) ;
break;
case V_85 :
error = F_40 ( args ) ;
break;
case V_86 :
error = F_41 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error || args -> V_45 == V_35 )
return error ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_40 ) ;
ASSERT ( ! args -> V_83 || ! args -> V_87 ) ;
ASSERT ( args -> V_45 % args -> V_20 == 0 ) ;
if ( ! args -> V_83 ) {
error = F_33 ( args -> V_66 , args -> V_76 ,
args -> V_43 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_42 ( args -> V_65 , args -> V_67 ,
args -> V_45 , args -> V_4 ) ) ;
}
if ( ! args -> V_87 ) {
F_43 ( args -> V_66 , args -> V_88 ?
V_89 :
V_90 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
}
F_44 ( V_91 ) ;
F_45 ( V_92 , args -> V_4 ) ;
return error ;
}
STATIC int
F_41 (
T_3 * args )
{
T_5 * V_47 ;
T_5 * V_46 ;
int error ;
T_1 V_48 ;
T_2 V_49 ;
T_1 V_93 ;
T_2 V_94 ;
T_1 V_95 ;
int V_52 ;
ASSERT ( args -> V_20 == 1 ) ;
V_47 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_96 ) ;
error = F_4 ( V_47 , args -> V_45 , args -> V_21 , & V_52 ) ;
if ( error )
goto V_97;
if ( ! V_52 )
goto V_98;
error = F_8 ( V_47 , & V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
ASSERT ( V_48 <= args -> V_45 ) ;
F_12 ( args , V_48 , V_49 , & V_93 , & V_94 ) ;
if ( V_93 > args -> V_45 )
goto V_98;
if ( V_94 < args -> V_21 )
goto V_98;
V_95 = V_93 + V_94 ;
if ( V_95 < args -> V_45 + args -> V_21 )
goto V_98;
args -> V_4 = F_48 ( V_95 , args -> V_45 + args -> V_40 )
- args -> V_45 ;
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_98;
ASSERT ( args -> V_45 + args -> V_4 <= V_95 ) ;
V_46 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_99 ) ;
ASSERT ( args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_80 ) ) ;
error = F_20 ( V_46 , V_47 , V_48 , V_49 , args -> V_45 ,
args -> V_4 , V_58 ) ;
if ( error ) {
F_49 ( V_46 , V_100 ) ;
goto V_97;
}
F_49 ( V_47 , V_101 ) ;
F_49 ( V_46 , V_101 ) ;
args -> V_83 = 0 ;
F_50 ( args ) ;
return 0 ;
V_98:
F_49 ( V_47 , V_101 ) ;
args -> V_45 = V_35 ;
F_51 ( args ) ;
return 0 ;
V_97:
F_49 ( V_47 , V_100 ) ;
F_52 ( args ) ;
return error ;
}
STATIC int
F_53 (
struct V_102 * args ,
struct V_1 * * V_103 ,
struct V_1 * * V_104 ,
T_1 V_105 ,
T_1 * V_106 ,
T_2 * V_107 ,
T_1 * V_108 ,
T_2 * V_109 ,
int V_110 )
{
T_1 V_111 ;
T_1 V_112 ;
int error ;
int V_52 ;
if ( ! V_105 )
goto V_113;
do {
error = F_8 ( * V_104 , V_106 , V_107 , & V_52 ) ;
if ( error )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
F_11 ( args , * V_106 , * V_107 , V_108 , V_109 ) ;
if ( ! V_110 ) {
if ( * V_108 >= args -> V_45 + V_105 )
goto V_113;
} else {
if ( * V_108 <= args -> V_45 - V_105 )
goto V_113;
}
if ( * V_109 >= args -> V_21 ) {
args -> V_4 = F_15 ( * V_109 , args -> V_40 ) ;
F_17 ( args ) ;
V_112 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , * V_108 ,
* V_109 , & V_111 ) ;
if ( V_112 < V_105 )
goto V_114;
goto V_113;
}
if ( ! V_110 )
error = F_54 ( * V_104 , 0 , & V_52 ) ;
else
error = F_55 ( * V_104 , 0 , & V_52 ) ;
if ( error )
goto V_97;
} while ( V_52 );
V_113:
F_49 ( * V_104 , V_101 ) ;
* V_104 = NULL ;
return 0 ;
V_114:
F_49 ( * V_103 , V_101 ) ;
* V_103 = NULL ;
return 0 ;
V_97:
return error ;
}
STATIC int
F_40 (
T_3 * args )
{
T_5 * V_115 ;
T_5 * V_116 ;
T_5 * V_46 ;
T_1 V_117 ;
T_1 V_118 ;
T_2 V_119 ;
T_2 V_120 ;
T_2 V_121 ;
T_1 V_122 ;
int error ;
int V_52 ;
int V_123 ;
T_1 V_124 ;
T_1 V_125 ;
T_2 V_126 ;
T_2 V_127 ;
T_2 V_128 ;
T_1 V_129 ;
T_2 V_37 ;
int V_130 = 0 ;
#if F_56 ( F_21 ) && F_56 ( V_131 )
int V_132 ;
V_132 = F_57 () & 1 ;
#endif
V_133:
V_116 = NULL ;
V_115 = NULL ;
V_127 = 0 ;
V_121 = 0 ;
V_128 = 0 ;
V_46 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_99 ) ;
if ( ( error = F_3 ( V_46 , 0 , args -> V_40 , & V_52 ) ) )
goto V_97;
if ( ! V_52 ) {
if ( ( error = F_58 ( args , V_46 , & V_124 ,
& V_127 , & V_52 ) ) )
goto V_97;
if ( V_52 == 0 || V_127 == 0 ) {
F_49 ( V_46 , V_101 ) ;
F_59 ( args ) ;
return 0 ;
}
ASSERT ( V_52 == 1 ) ;
}
args -> V_83 = 0 ;
while ( F_60 ( V_46 , 0 ) ) {
T_2 V_134 ;
int V_135 = 0 ;
T_2 V_136 = 0 ;
T_1 V_137 = 0 ;
#if F_56 ( F_21 ) && F_56 ( V_131 )
if ( ! V_132 )
break;
#endif
if ( V_127 || args -> V_20 > 1 ) {
V_46 -> V_138 [ 0 ] = 1 ;
do {
if ( ( error = F_8 ( V_46 , & V_124 ,
& V_127 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( V_127 >= args -> V_21 )
break;
if ( ( error = F_54 ( V_46 , 0 , & V_52 ) ) )
goto V_97;
} while ( V_52 );
ASSERT ( V_127 >= args -> V_21 ) ;
if ( ! V_52 )
break;
}
V_52 = V_46 -> V_138 [ 0 ] ;
for ( V_123 = 1 , V_136 = 0 , V_134 = 0 ;
! error && V_123 && ( V_136 < args -> V_40 || V_134 > 0 ) ;
error = F_54 ( V_46 , 0 , & V_123 ) ) {
if ( ( error = F_8 ( V_46 , & V_124 , & V_127 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
F_11 ( args , V_124 , V_127 ,
& V_125 , & V_128 ) ;
if ( V_128 < args -> V_21 )
continue;
args -> V_4 = F_15 ( V_128 , args -> V_40 ) ;
F_17 ( args ) ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
if ( args -> V_4 < V_136 )
continue;
V_126 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_125 , V_128 , & V_129 ) ;
if ( V_129 != V_35 &&
( args -> V_4 > V_136 || V_126 < V_134 ) ) {
V_134 = V_126 ;
V_137 = V_129 ;
V_136 = args -> V_4 ;
V_135 = V_46 -> V_138 [ 0 ] ;
}
}
if ( V_136 == 0 )
break;
V_46 -> V_138 [ 0 ] = V_135 ;
if ( ( error = F_8 ( V_46 , & V_124 , & V_127 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
ASSERT ( V_124 + V_127 <= F_10 ( F_19 ( args -> V_43 ) -> V_80 ) ) ;
args -> V_4 = V_136 ;
if ( ! F_18 ( args ) ) {
F_49 ( V_46 , V_101 ) ;
F_61 ( args ) ;
return 0 ;
}
V_136 = args -> V_4 ;
args -> V_45 = V_137 ;
ASSERT ( V_137 >= V_124 ) ;
ASSERT ( V_137 + V_136 <= V_124 + V_127 ) ;
V_116 = F_46 ( args -> V_65 , args -> V_66 ,
args -> V_43 , args -> V_67 , V_96 ) ;
if ( ( error = F_20 ( V_46 , V_116 , V_124 ,
V_127 , V_137 , V_136 , V_57 ) ) )
goto V_97;
F_49 ( V_46 , V_101 ) ;
F_49 ( V_116 , V_101 ) ;
F_62 ( args ) ;
return 0 ;
}
V_116 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_96 ) ;
if ( ( error = F_4 ( V_116 , args -> V_45 , args -> V_40 , & V_52 ) ) )
goto V_97;
if ( ! V_52 ) {
V_115 = V_116 ;
V_116 = NULL ;
}
else if ( ( error = F_63 ( V_116 , & V_115 ) ) )
goto V_97;
if ( ( error = F_54 ( V_115 , 0 , & V_52 ) ) )
goto V_97;
if ( ! V_52 ) {
F_49 ( V_115 , V_101 ) ;
V_115 = NULL ;
}
do {
if ( V_116 ) {
if ( ( error = F_8 ( V_116 , & V_124 , & V_127 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
F_11 ( args , V_124 , V_127 ,
& V_125 , & V_128 ) ;
if ( V_128 >= args -> V_21 )
break;
if ( ( error = F_55 ( V_116 , 0 , & V_52 ) ) )
goto V_97;
if ( ! V_52 ) {
F_49 ( V_116 ,
V_101 ) ;
V_116 = NULL ;
}
}
if ( V_115 ) {
if ( ( error = F_8 ( V_115 , & V_117 , & V_120 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
F_11 ( args , V_117 , V_120 ,
& V_118 , & V_121 ) ;
if ( V_121 >= args -> V_21 )
break;
if ( ( error = F_54 ( V_115 , 0 , & V_52 ) ) )
goto V_97;
if ( ! V_52 ) {
F_49 ( V_115 ,
V_101 ) ;
V_115 = NULL ;
}
}
} while ( V_116 || V_115 );
if ( V_116 && V_115 ) {
if ( V_128 >= args -> V_21 ) {
args -> V_4 = F_15 ( V_128 , args -> V_40 ) ;
F_17 ( args ) ;
V_126 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_125 , V_128 , & V_129 ) ;
error = F_53 ( args ,
& V_116 , & V_115 ,
V_126 , & V_117 , & V_120 ,
& V_118 , & V_121 ,
0 ) ;
} else {
ASSERT ( V_121 >= args -> V_21 ) ;
args -> V_4 = F_15 ( V_121 , args -> V_40 ) ;
F_17 ( args ) ;
V_119 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_118 , V_121 , & V_122 ) ;
error = F_53 ( args ,
& V_115 , & V_116 ,
V_119 , & V_124 , & V_127 ,
& V_125 , & V_128 ,
1 ) ;
}
if ( error )
goto V_97;
}
if ( V_116 == NULL && V_115 == NULL ) {
if ( ! V_130 ++ ) {
F_64 ( args ) ;
F_65 ( args -> V_65 , V_139 ) ;
goto V_133;
}
F_66 ( args ) ;
args -> V_45 = V_35 ;
return 0 ;
}
if ( V_115 ) {
V_116 = V_115 ;
V_115 = NULL ;
V_124 = V_117 ;
V_125 = V_118 ;
V_127 = V_120 ;
V_128 = V_121 ;
V_123 = 1 ;
} else
V_123 = 0 ;
args -> V_4 = F_15 ( V_128 , args -> V_40 ) ;
F_17 ( args ) ;
if ( ! F_18 ( args ) ) {
F_61 ( args ) ;
F_49 ( V_116 , V_101 ) ;
F_49 ( V_46 , V_101 ) ;
return 0 ;
}
V_37 = args -> V_4 ;
( void ) F_14 ( args -> V_45 , V_37 , args -> V_20 ,
V_125 , V_128 , & V_129 ) ;
ASSERT ( V_129 >= V_124 ) ;
ASSERT ( V_129 + V_37 <= V_125 + V_128 ) ;
ASSERT ( V_129 + V_37 <= F_10 ( F_19 ( args -> V_43 ) -> V_80 ) ) ;
args -> V_45 = V_129 ;
if ( ( error = F_20 ( V_46 , V_116 , V_124 , V_127 ,
V_129 , V_37 , V_58 ) ) )
goto V_97;
if ( V_123 )
F_67 ( args ) ;
else
F_68 ( args ) ;
F_49 ( V_46 , V_101 ) ;
F_49 ( V_116 , V_101 ) ;
return 0 ;
V_97:
F_69 ( args ) ;
if ( V_46 != NULL )
F_49 ( V_46 , V_100 ) ;
if ( V_116 != NULL )
F_49 ( V_116 , V_100 ) ;
if ( V_115 != NULL )
F_49 ( V_115 , V_100 ) ;
return error ;
}
STATIC int
F_39 (
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
int V_130 = 0 ;
V_133:
V_46 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_99 ) ;
V_47 = NULL ;
if ( ( error = F_3 ( V_46 , 0 ,
args -> V_40 + args -> V_20 - 1 , & V_52 ) ) )
goto V_97;
if ( ! V_52 || V_130 > 1 ) {
error = F_58 ( args , V_46 ,
& V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_97;
if ( V_52 == 0 || V_49 == 0 ) {
F_49 ( V_46 , V_101 ) ;
F_70 ( args ) ;
return 0 ;
}
ASSERT ( V_52 == 1 ) ;
F_11 ( args , V_48 , V_49 , & V_50 , & V_37 ) ;
} else {
for (; ; ) {
error = F_8 ( V_46 , & V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
F_11 ( args , V_48 , V_49 ,
& V_50 , & V_37 ) ;
if ( V_37 >= args -> V_40 )
break;
error = F_54 ( V_46 , 0 , & V_52 ) ;
if ( error )
goto V_97;
if ( V_52 == 0 ) {
F_49 ( V_46 ,
V_101 ) ;
F_71 ( args ) ;
if ( ! V_130 ++ )
F_65 ( args -> V_65 , V_139 ) ;
goto V_133;
}
}
}
V_37 = F_15 ( args -> V_40 , V_37 ) ;
F_47 ( V_37 == 0 ||
( V_37 <= V_49 && V_50 + V_37 <= V_48 + V_49 ) , V_97 ) ;
if ( V_37 < args -> V_40 ) {
T_1 V_140 ;
T_2 V_141 ;
T_1 V_142 ;
T_2 V_143 ;
V_143 = V_37 ;
V_142 = V_50 ;
V_141 = V_49 ;
V_140 = V_48 ;
for (; ; ) {
if ( ( error = F_55 ( V_46 , 0 , & V_52 ) ) )
goto V_97;
if ( V_52 == 0 )
break;
if ( ( error = F_8 ( V_46 , & V_48 , & V_49 ,
& V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( V_49 < V_143 )
break;
F_11 ( args , V_48 , V_49 ,
& V_50 , & V_37 ) ;
V_37 = F_15 ( args -> V_40 , V_37 ) ;
F_47 ( V_37 == 0 ||
( V_37 <= V_49 && V_50 + V_37 <= V_48 + V_49 ) ,
V_97 ) ;
if ( V_37 > V_143 ) {
V_143 = V_37 ;
V_142 = V_50 ;
V_141 = V_49 ;
V_140 = V_48 ;
if ( V_37 == args -> V_40 )
break;
}
}
if ( ( error = F_1 ( V_46 , V_140 , V_141 ,
& V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
V_37 = V_143 ;
V_50 = V_142 ;
V_49 = V_141 ;
V_48 = V_140 ;
}
args -> V_83 = 0 ;
args -> V_4 = V_37 ;
if ( V_37 < args -> V_21 ) {
if ( ! V_130 ++ ) {
F_49 ( V_46 , V_101 ) ;
F_71 ( args ) ;
F_65 ( args -> V_65 , V_139 ) ;
goto V_133;
}
goto V_144;
}
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_144;
V_37 = args -> V_4 ;
F_47 ( V_37 <= V_49 , V_97 ) ;
V_47 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_96 ) ;
if ( ( error = F_20 ( V_46 , V_47 , V_48 , V_49 ,
V_50 , V_37 , V_57 ) ) )
goto V_97;
F_49 ( V_46 , V_101 ) ;
F_49 ( V_47 , V_101 ) ;
V_46 = V_47 = NULL ;
args -> V_4 = V_37 ;
args -> V_45 = V_50 ;
F_47 (
args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_80 ) ,
V_97 ) ;
F_72 ( args ) ;
return 0 ;
V_97:
F_73 ( args ) ;
if ( V_46 )
F_49 ( V_46 , V_100 ) ;
if ( V_47 )
F_49 ( V_47 , V_100 ) ;
return error ;
V_144:
F_49 ( V_46 , V_101 ) ;
F_74 ( args ) ;
args -> V_45 = V_35 ;
return 0 ;
}
STATIC int
F_58 (
T_3 * args ,
T_5 * V_145 ,
T_1 * V_146 ,
T_2 * V_147 ,
int * V_5 )
{
int error ;
T_1 V_48 ;
T_2 V_49 ;
int V_52 ;
if ( ( error = F_55 ( V_145 , 0 , & V_52 ) ) )
goto V_97;
if ( V_52 ) {
if ( ( error = F_8 ( V_145 , & V_48 , & V_49 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
}
else if ( args -> V_21 == 1 && args -> V_20 == 1 && ! args -> V_87 &&
( F_10 ( F_19 ( args -> V_43 ) -> V_148 )
> args -> V_42 ) ) {
error = F_75 ( args -> V_66 , args -> V_43 , & V_48 , 0 ) ;
if ( error )
goto V_97;
if ( V_48 != V_35 ) {
F_76 ( args -> V_65 , args -> V_67 , V_48 , 1 ,
args -> V_149 ) ;
if ( args -> V_149 ) {
T_9 * V_69 ;
V_69 = F_77 ( args -> V_65 , args -> V_66 ,
args -> V_67 , V_48 , 0 ) ;
F_78 ( args -> V_66 , V_69 ) ;
}
args -> V_4 = 1 ;
args -> V_45 = V_48 ;
F_47 (
args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_80 ) ,
V_97 ) ;
args -> V_83 = 1 ;
F_79 ( args ) ;
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
F_80 ( args ) ;
V_49 = 0 ;
}
* V_146 = V_48 ;
* V_147 = V_49 ;
* V_5 = 1 ;
F_81 ( args ) ;
return 0 ;
V_97:
F_82 ( args ) ;
return error ;
}
STATIC int
F_83 (
T_7 * V_66 ,
T_9 * V_43 ,
T_8 V_67 ,
T_1 V_3 ,
T_2 V_4 ,
int V_87 )
{
T_5 * V_47 ;
T_5 * V_46 ;
int error ;
T_1 V_117 ;
T_2 V_120 ;
int V_150 ;
int V_151 ;
int V_52 ;
T_1 V_124 ;
T_2 V_127 ;
T_6 * V_65 ;
T_1 V_152 ;
T_2 V_153 ;
T_10 * V_76 ;
V_65 = V_66 -> V_154 ;
V_47 = F_46 ( V_65 , V_66 , V_43 , V_67 , V_96 ) ;
V_46 = NULL ;
if ( ( error = F_4 ( V_47 , V_3 , V_4 , & V_150 ) ) )
goto V_97;
if ( V_150 ) {
if ( ( error = F_8 ( V_47 , & V_124 , & V_127 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( V_124 + V_127 < V_3 )
V_150 = 0 ;
else {
F_47 ( V_124 + V_127 <= V_3 , V_97 ) ;
}
}
if ( ( error = F_54 ( V_47 , 0 , & V_151 ) ) )
goto V_97;
if ( V_151 ) {
if ( ( error = F_8 ( V_47 , & V_117 , & V_120 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( V_3 + V_4 < V_117 )
V_151 = 0 ;
else {
F_47 ( V_117 >= V_3 + V_4 , V_97 ) ;
}
}
V_46 = F_46 ( V_65 , V_66 , V_43 , V_67 , V_99 ) ;
if ( V_150 && V_151 ) {
if ( ( error = F_1 ( V_46 , V_124 , V_127 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( ( error = F_1 ( V_46 , V_117 , V_120 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( ( error = F_24 ( V_47 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( ( error = F_55 ( V_47 , 0 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
#ifdef F_21
{
T_1 V_155 ;
T_2 V_156 ;
if ( ( error = F_8 ( V_47 , & V_155 , & V_156 ,
& V_52 ) ) )
goto V_97;
F_47 (
V_52 == 1 && V_155 == V_124 && V_156 == V_127 ,
V_97 ) ;
}
#endif
V_152 = V_124 ;
V_153 = V_4 + V_127 + V_120 ;
if ( ( error = F_5 ( V_47 , V_152 , V_153 ) ) )
goto V_97;
}
else if ( V_150 ) {
if ( ( error = F_1 ( V_46 , V_124 , V_127 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( ( error = F_55 ( V_47 , 0 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
V_152 = V_124 ;
V_153 = V_4 + V_127 ;
if ( ( error = F_5 ( V_47 , V_152 , V_153 ) ) )
goto V_97;
}
else if ( V_151 ) {
if ( ( error = F_1 ( V_46 , V_117 , V_120 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
V_152 = V_3 ;
V_153 = V_4 + V_120 ;
if ( ( error = F_5 ( V_47 , V_152 , V_153 ) ) )
goto V_97;
}
else {
V_152 = V_3 ;
V_153 = V_4 ;
if ( ( error = F_25 ( V_47 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
}
F_49 ( V_47 , V_101 ) ;
V_47 = NULL ;
if ( ( error = F_1 ( V_46 , V_152 , V_153 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 0 , V_97 ) ;
if ( ( error = F_25 ( V_46 , & V_52 ) ) )
goto V_97;
F_47 ( V_52 == 1 , V_97 ) ;
F_49 ( V_46 , V_101 ) ;
V_46 = NULL ;
V_76 = F_84 ( V_65 , V_67 ) ;
error = F_33 ( V_66 , V_76 , V_43 , V_4 ) ;
F_85 ( V_76 ) ;
if ( error )
goto V_97;
if ( ! V_87 )
F_43 ( V_66 , V_90 , ( long ) V_4 ) ;
F_44 ( V_157 ) ;
F_45 ( V_158 , V_4 ) ;
F_86 ( V_65 , V_67 , V_3 , V_4 , V_87 , V_150 , V_151 ) ;
return 0 ;
V_97:
F_86 ( V_65 , V_67 , V_3 , V_4 , V_87 , - 1 , - 1 ) ;
if ( V_47 )
F_49 ( V_47 , V_100 ) ;
if ( V_46 )
F_49 ( V_46 , V_100 ) ;
return error ;
}
void
F_87 (
T_6 * V_65 )
{
int V_159 ;
T_11 V_160 ;
T_11 V_161 ;
int V_162 ;
int V_163 ;
V_161 = ( V_65 -> V_164 . V_165 + 1 ) / 2 ;
V_162 = V_65 -> V_166 [ 0 ] ;
V_163 = V_65 -> V_166 [ 1 ] ;
V_160 = ( V_161 + V_162 - 1 ) / V_162 ;
for ( V_159 = 1 ; V_160 > 1 ; V_159 ++ )
V_160 = ( V_160 + V_163 - 1 ) / V_163 ;
V_65 -> V_167 = V_159 ;
}
T_2
F_88 (
struct V_168 * V_65 ,
struct V_75 * V_76 )
{
T_2 V_169 , V_170 = 0 ;
V_169 = F_89 ( V_76 , V_65 ) ;
if ( V_169 > V_76 -> V_171 )
V_170 = V_169 - V_76 -> V_171 ;
if ( V_76 -> V_172 > V_170 )
return V_76 -> V_172 - V_170 ;
return V_76 -> V_171 > 0 || V_76 -> V_172 > 0 ;
}
STATIC int
F_90 (
T_3 * args ,
int V_51 )
{
T_9 * V_43 ;
T_4 * V_41 ;
T_9 * V_173 ;
T_1 V_3 ;
T_2 V_170 ;
int error ;
T_2 V_174 ;
T_6 * V_65 ;
T_2 V_169 ;
T_10 * V_76 ;
T_3 V_175 ;
T_7 * V_66 ;
V_65 = args -> V_65 ;
V_76 = args -> V_76 ;
V_66 = args -> V_66 ;
if ( ! V_76 -> V_176 ) {
if ( ( error = F_91 ( V_65 , V_66 , args -> V_67 , V_51 ,
& V_43 ) ) )
return error ;
if ( ! V_76 -> V_176 ) {
ASSERT ( V_51 & V_177 ) ;
ASSERT ( ! ( V_51 & V_178 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
} else
V_43 = NULL ;
if ( V_76 -> V_179 && args -> V_149 &&
( V_51 & V_177 ) ) {
ASSERT ( ! ( V_51 & V_178 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
if ( ! ( V_51 & V_178 ) ) {
V_169 = F_89 ( V_76 , V_65 ) ;
V_174 = F_88 ( V_65 , V_76 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_180 - 1 ) >
V_174 ||
( ( int ) ( V_76 -> V_79 + V_76 -> V_171 -
V_169 - args -> V_181 ) < ( int ) args -> V_42 ) ) {
if ( V_43 )
F_92 ( V_66 , V_43 ) ;
args -> V_43 = NULL ;
return 0 ;
}
}
if ( V_43 == NULL ) {
if ( ( error = F_91 ( V_65 , V_66 , args -> V_67 , V_51 ,
& V_43 ) ) )
return error ;
if ( V_43 == NULL ) {
ASSERT ( V_51 & V_177 ) ;
ASSERT ( ! ( V_51 & V_178 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
}
V_41 = F_19 ( V_43 ) ;
V_169 = F_93 ( V_41 , V_65 ) ;
if ( ! ( V_51 & V_178 ) ) {
V_170 = V_169 > F_10 ( V_41 -> V_148 ) ?
( V_169 - F_10 ( V_41 -> V_148 ) ) : 0 ;
V_174 = F_10 ( V_41 -> V_182 ) ;
V_174 = ( V_174 > V_170 ) ? ( V_174 - V_170 ) :
( F_10 ( V_41 -> V_148 ) > 0 || V_174 > 0 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_180 - 1 ) >
V_174 ||
( ( int ) ( F_10 ( V_41 -> V_44 ) +
F_10 ( V_41 -> V_148 ) - V_169 - args -> V_181 ) <
( int ) args -> V_42 ) ) {
F_92 ( V_66 , V_43 ) ;
args -> V_43 = NULL ;
return 0 ;
}
}
while ( F_10 ( V_41 -> V_148 ) > V_169 ) {
T_9 * V_69 ;
error = F_75 ( V_66 , V_43 , & V_3 , 0 ) ;
if ( error )
return error ;
if ( ( error = F_83 ( V_66 , V_43 , args -> V_67 , V_3 , 1 , 1 ) ) )
return error ;
V_69 = F_77 ( V_65 , V_66 , args -> V_67 , V_3 , 0 ) ;
F_78 ( V_66 , V_69 ) ;
}
V_175 . V_66 = V_66 ;
V_175 . V_65 = V_65 ;
V_175 . V_43 = V_43 ;
V_175 . V_67 = args -> V_67 ;
V_175 . V_38 = V_175 . V_42 = V_175 . V_88 = V_175 . V_149 =
V_175 . V_180 = 0 ;
V_175 . V_20 = V_175 . V_21 = V_175 . V_39 = V_175 . V_87 = 1 ;
V_175 . type = V_84 ;
V_175 . V_76 = V_76 ;
if ( ( error = F_26 ( V_65 , V_66 , V_175 . V_67 , & V_173 ) ) )
return error ;
while ( F_10 ( V_41 -> V_148 ) < V_169 ) {
V_175 . V_45 = 0 ;
V_175 . V_40 = V_169 - F_10 ( V_41 -> V_148 ) ;
if ( ( error = F_38 ( & V_175 ) ) ) {
F_92 ( V_66 , V_173 ) ;
return error ;
}
if ( V_175 . V_45 == V_35 ) {
if ( V_51 & V_178 )
break;
F_92 ( V_66 , V_173 ) ;
args -> V_43 = NULL ;
return 0 ;
}
for ( V_3 = V_175 . V_45 ; V_3 < V_175 . V_45 + V_175 . V_4 ; V_3 ++ ) {
error = F_94 ( V_66 , V_43 ,
V_173 , V_3 , 0 ) ;
if ( error )
return error ;
}
}
F_92 ( V_66 , V_173 ) ;
args -> V_43 = V_43 ;
return 0 ;
}
int
F_75 (
T_7 * V_66 ,
T_9 * V_43 ,
T_1 * V_183 ,
int V_184 )
{
T_4 * V_41 ;
T_12 * V_185 ;
T_9 * V_173 ;
T_1 V_3 ;
int error ;
int V_186 ;
T_6 * V_65 ;
T_10 * V_76 ;
V_41 = F_19 ( V_43 ) ;
if ( ! V_41 -> V_148 ) {
* V_183 = V_35 ;
return 0 ;
}
V_65 = V_66 -> V_154 ;
if ( ( error = F_26 ( V_65 , V_66 ,
F_10 ( V_41 -> V_187 ) , & V_173 ) ) )
return error ;
V_185 = F_95 ( V_173 ) ;
V_3 = F_10 ( V_185 -> V_188 [ F_10 ( V_41 -> V_189 ) ] ) ;
F_34 ( & V_41 -> V_189 , 1 ) ;
F_92 ( V_66 , V_173 ) ;
if ( F_10 ( V_41 -> V_189 ) == F_96 ( V_65 ) )
V_41 -> V_189 = 0 ;
V_76 = F_84 ( V_65 , F_10 ( V_41 -> V_187 ) ) ;
F_34 ( & V_41 -> V_148 , - 1 ) ;
F_97 ( V_66 , - 1 ) ;
V_76 -> V_171 -- ;
F_85 ( V_76 ) ;
V_186 = V_190 | V_191 ;
if ( V_184 ) {
F_34 ( & V_41 -> V_192 , 1 ) ;
V_76 -> V_193 ++ ;
V_186 |= V_194 ;
}
F_37 ( V_66 , V_43 , V_186 ) ;
* V_183 = V_3 ;
return 0 ;
}
void
F_37 (
T_7 * V_66 ,
T_9 * V_69 ,
int V_195 )
{
int V_196 ;
int V_197 ;
static const short V_198 [] = {
F_98 ( T_4 , V_199 ) ,
F_98 ( T_4 , V_200 ) ,
F_98 ( T_4 , V_187 ) ,
F_98 ( T_4 , V_80 ) ,
F_98 ( T_4 , V_201 [ 0 ] ) ,
F_98 ( T_4 , V_202 [ 0 ] ) ,
F_98 ( T_4 , V_189 ) ,
F_98 ( T_4 , V_203 ) ,
F_98 ( T_4 , V_148 ) ,
F_98 ( T_4 , V_44 ) ,
F_98 ( T_4 , V_182 ) ,
F_98 ( T_4 , V_192 ) ,
sizeof( T_4 )
} ;
F_99 ( V_66 -> V_154 , F_19 ( V_69 ) , V_195 , V_204 ) ;
F_100 ( V_195 , V_198 , V_205 , & V_196 , & V_197 ) ;
F_101 ( V_66 , V_69 , ( T_11 ) V_196 , ( T_11 ) V_197 ) ;
}
int
F_102 (
T_6 * V_65 ,
T_7 * V_66 ,
T_8 V_67 ,
int V_51 )
{
T_9 * V_69 ;
int error ;
if ( ( error = F_91 ( V_65 , V_66 , V_67 , V_51 , & V_69 ) ) )
return error ;
if ( V_69 )
F_92 ( V_66 , V_69 ) ;
return 0 ;
}
int
F_94 (
T_7 * V_66 ,
T_9 * V_43 ,
T_9 * V_173 ,
T_1 V_3 ,
int V_184 )
{
T_4 * V_41 ;
T_12 * V_185 ;
T_13 * V_206 ;
int error ;
int V_186 ;
T_6 * V_65 ;
T_10 * V_76 ;
V_41 = F_19 ( V_43 ) ;
V_65 = V_66 -> V_154 ;
if ( ! V_173 && ( error = F_26 ( V_65 , V_66 ,
F_10 ( V_41 -> V_187 ) , & V_173 ) ) )
return error ;
V_185 = F_95 ( V_173 ) ;
F_34 ( & V_41 -> V_203 , 1 ) ;
if ( F_10 ( V_41 -> V_203 ) == F_96 ( V_65 ) )
V_41 -> V_203 = 0 ;
V_76 = F_84 ( V_65 , F_10 ( V_41 -> V_187 ) ) ;
F_34 ( & V_41 -> V_148 , 1 ) ;
F_97 ( V_66 , 1 ) ;
V_76 -> V_171 ++ ;
V_186 = V_207 | V_191 ;
if ( V_184 ) {
F_34 ( & V_41 -> V_192 , - 1 ) ;
V_76 -> V_193 -- ;
V_186 |= V_194 ;
}
F_85 ( V_76 ) ;
F_37 ( V_66 , V_43 , V_186 ) ;
ASSERT ( F_10 ( V_41 -> V_148 ) <= F_96 ( V_65 ) ) ;
V_206 = & V_185 -> V_188 [ F_10 ( V_41 -> V_203 ) ] ;
* V_206 = F_6 ( V_3 ) ;
F_37 ( V_66 , V_43 , V_186 ) ;
F_101 ( V_66 , V_173 ,
( int ) ( ( V_208 ) V_206 - ( V_208 ) V_185 ) ,
( int ) ( ( V_208 ) V_206 - ( V_208 ) V_185 +
sizeof( T_1 ) - 1 ) ) ;
return 0 ;
}
int
F_103 (
struct V_168 * V_65 ,
struct V_74 * V_66 ,
T_8 V_67 ,
int V_51 ,
struct V_77 * * V_68 )
{
struct V_78 * V_41 ;
int V_209 ;
int error ;
ASSERT ( V_67 != V_70 ) ;
error = F_27 (
V_65 , V_66 , V_65 -> V_71 ,
F_28 ( V_65 , V_67 , F_104 ( V_65 ) ) ,
F_30 ( V_65 , 1 ) , V_51 , V_68 ) ;
if ( error )
return error ;
if ( ! * V_68 )
return 0 ;
ASSERT ( ! ( * V_68 ) -> V_210 ) ;
V_41 = F_19 ( * V_68 ) ;
V_209 =
V_41 -> V_199 == F_6 ( V_211 ) &&
F_105 ( F_10 ( V_41 -> V_200 ) ) &&
F_10 ( V_41 -> V_44 ) <= F_10 ( V_41 -> V_80 ) &&
F_10 ( V_41 -> V_189 ) < F_96 ( V_65 ) &&
F_10 ( V_41 -> V_203 ) < F_96 ( V_65 ) &&
F_10 ( V_41 -> V_148 ) <= F_96 ( V_65 ) &&
F_10 ( V_41 -> V_187 ) == V_67 ;
if ( F_106 ( & V_65 -> V_164 ) )
V_209 = V_209 && F_10 ( V_41 -> V_192 ) <=
F_10 ( V_41 -> V_80 ) ;
if ( F_36 ( F_107 ( ! V_209 , V_65 , V_212 ,
V_213 ) ) ) {
F_108 ( L_1 ,
V_214 , V_65 , V_41 ) ;
F_92 ( V_66 , * V_68 ) ;
return F_109 ( V_81 ) ;
}
F_32 ( * V_68 , V_215 , V_216 ) ;
return 0 ;
}
int
F_91 (
struct V_168 * V_65 ,
struct V_74 * V_66 ,
T_8 V_67 ,
int V_51 ,
struct V_77 * * V_68 )
{
struct V_78 * V_41 ;
struct V_75 * V_76 ;
int error ;
ASSERT ( V_67 != V_70 ) ;
error = F_103 ( V_65 , V_66 , V_67 ,
( V_51 & V_177 ) ? V_217 : 0 ,
V_68 ) ;
if ( error )
return error ;
if ( ! * V_68 )
return 0 ;
ASSERT ( ! ( * V_68 ) -> V_210 ) ;
V_41 = F_19 ( * V_68 ) ;
V_76 = F_84 ( V_65 , V_67 ) ;
if ( ! V_76 -> V_176 ) {
V_76 -> V_79 = F_10 ( V_41 -> V_44 ) ;
V_76 -> V_193 = F_10 ( V_41 -> V_192 ) ;
V_76 -> V_171 = F_10 ( V_41 -> V_148 ) ;
V_76 -> V_172 = F_10 ( V_41 -> V_182 ) ;
V_76 -> V_218 [ V_219 ] =
F_10 ( V_41 -> V_202 [ V_219 ] ) ;
V_76 -> V_218 [ V_220 ] =
F_10 ( V_41 -> V_202 [ V_220 ] ) ;
F_110 ( & V_76 -> V_221 ) ;
V_76 -> V_222 = 0 ;
V_76 -> V_223 = V_224 ;
V_76 -> V_176 = 1 ;
}
#ifdef F_21
else if ( ! F_111 ( V_65 ) ) {
ASSERT ( V_76 -> V_79 == F_10 ( V_41 -> V_44 ) ) ;
ASSERT ( V_76 -> V_193 == F_10 ( V_41 -> V_192 ) ) ;
ASSERT ( V_76 -> V_171 == F_10 ( V_41 -> V_148 ) ) ;
ASSERT ( V_76 -> V_172 == F_10 ( V_41 -> V_182 ) ) ;
ASSERT ( V_76 -> V_218 [ V_219 ] ==
F_10 ( V_41 -> V_202 [ V_219 ] ) ) ;
ASSERT ( V_76 -> V_218 [ V_220 ] ==
F_10 ( V_41 -> V_202 [ V_220 ] ) ) ;
}
#endif
F_85 ( V_76 ) ;
return 0 ;
}
int
F_112 (
T_3 * args )
{
T_1 V_225 ;
int error ;
int V_51 ;
T_2 V_42 ;
T_6 * V_65 ;
T_8 V_226 ;
T_14 type ;
int V_227 = 0 ;
int V_228 = 0 ;
T_8 V_229 = V_230 ;
V_65 = args -> V_65 ;
type = args -> V_231 = args -> type ;
args -> V_45 = V_35 ;
V_225 = V_65 -> V_164 . V_165 ;
if ( args -> V_40 > V_225 )
args -> V_40 = V_225 ;
if ( args -> V_20 == 0 )
args -> V_20 = 1 ;
ASSERT ( F_113 ( V_65 , args -> V_232 ) < V_65 -> V_164 . V_233 ) ;
ASSERT ( F_114 ( V_65 , args -> V_232 ) < V_225 ) ;
ASSERT ( args -> V_21 <= args -> V_40 ) ;
ASSERT ( args -> V_21 <= V_225 ) ;
ASSERT ( args -> V_38 < args -> V_39 ) ;
if ( F_113 ( V_65 , args -> V_232 ) >= V_65 -> V_164 . V_233 ||
F_114 ( V_65 , args -> V_232 ) >= V_225 ||
args -> V_21 > args -> V_40 || args -> V_21 > V_225 ||
args -> V_38 >= args -> V_39 ) {
args -> V_232 = V_234 ;
F_115 ( args ) ;
return 0 ;
}
V_42 = args -> V_42 ;
switch ( type ) {
case V_84 :
case V_85 :
case V_86 :
args -> V_67 = F_113 ( V_65 , args -> V_232 ) ;
args -> V_76 = F_84 ( V_65 , args -> V_67 ) ;
args -> V_42 = 0 ;
error = F_90 ( args , 0 ) ;
args -> V_42 = V_42 ;
if ( error ) {
F_116 ( args ) ;
goto V_97;
}
if ( ! args -> V_43 ) {
F_117 ( args ) ;
break;
}
args -> V_45 = F_114 ( V_65 , args -> V_232 ) ;
if ( ( error = F_38 ( args ) ) )
goto V_97;
break;
case V_235 :
if ( ( args -> V_149 == V_236 ) &&
( V_65 -> V_237 & V_238 ) ) {
args -> V_232 = F_118 ( V_65 ,
( ( V_65 -> V_239 / V_229 ) %
V_65 -> V_164 . V_233 ) , 0 ) ;
V_227 = 1 ;
}
args -> V_45 = F_114 ( V_65 , args -> V_232 ) ;
args -> type = V_85 ;
case V_240 :
case V_241 :
case V_242 :
if ( type == V_240 ) {
args -> V_67 = V_226 = ( V_65 -> V_239 / V_229 ) %
V_65 -> V_164 . V_233 ;
args -> type = V_84 ;
V_51 = V_177 ;
} else if ( type == V_242 ) {
args -> V_67 = F_113 ( V_65 , args -> V_232 ) ;
args -> type = V_84 ;
V_226 = 0 ;
V_51 = 0 ;
} else {
if ( type == V_241 )
args -> type = V_84 ;
args -> V_67 = V_226 = F_113 ( V_65 , args -> V_232 ) ;
V_51 = V_177 ;
}
for (; ; ) {
args -> V_76 = F_84 ( V_65 , args -> V_67 ) ;
if ( V_228 ) args -> V_42 = 0 ;
error = F_90 ( args , V_51 ) ;
args -> V_42 = V_42 ;
if ( error ) {
F_116 ( args ) ;
goto V_97;
}
if ( args -> V_43 ) {
if ( ( error = F_38 ( args ) ) )
goto V_97;
break;
}
F_119 ( args ) ;
if ( args -> V_67 == V_226 &&
type == V_235 )
args -> type = V_84 ;
if ( ++ ( args -> V_67 ) == V_65 -> V_164 . V_233 ) {
if ( args -> V_243 != V_234 )
args -> V_67 = V_226 ;
else
args -> V_67 = 0 ;
}
if ( args -> V_67 == V_226 ) {
if ( V_228 == 1 ) {
args -> V_45 = V_35 ;
F_120 ( args ) ;
break;
}
if ( V_51 == 0 ) {
V_228 = 1 ;
} else {
V_51 = 0 ;
if ( type == V_235 ) {
args -> V_45 = F_114 ( V_65 ,
args -> V_232 ) ;
args -> type = V_85 ;
}
}
}
F_85 ( args -> V_76 ) ;
}
if ( V_227 || ( type == V_240 ) ) {
if ( args -> V_67 == V_226 )
V_65 -> V_239 = ( V_65 -> V_239 + 1 ) %
( V_65 -> V_164 . V_233 * V_229 ) ;
else
V_65 -> V_239 = ( args -> V_67 * V_229 + 1 ) %
( V_65 -> V_164 . V_233 * V_229 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_45 == V_35 )
args -> V_232 = V_234 ;
else {
args -> V_232 = F_118 ( V_65 , args -> V_67 , args -> V_45 ) ;
#ifdef F_21
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_40 ) ;
ASSERT ( args -> V_45 % args -> V_20 == 0 ) ;
F_121 ( V_65 , F_122 ( V_65 , args -> V_232 ) ,
args -> V_4 ) ;
#endif
}
F_85 ( args -> V_76 ) ;
return 0 ;
V_97:
F_85 ( args -> V_76 ) ;
return error ;
}
int
F_123 (
T_7 * V_66 ,
T_15 V_3 ,
T_2 V_4 )
{
T_3 args ;
int error ;
ASSERT ( V_4 != 0 ) ;
memset ( & args , 0 , sizeof( T_3 ) ) ;
args . V_66 = V_66 ;
args . V_65 = V_66 -> V_154 ;
args . V_67 = F_113 ( args . V_65 , V_3 ) ;
if ( args . V_67 >= args . V_65 -> V_164 . V_233 )
return V_81 ;
args . V_45 = F_114 ( args . V_65 , V_3 ) ;
if ( args . V_45 >= args . V_65 -> V_164 . V_165 )
return V_81 ;
args . V_76 = F_84 ( args . V_65 , args . V_67 ) ;
ASSERT ( args . V_76 ) ;
error = F_90 ( & args , V_178 ) ;
if ( error )
goto V_97;
if ( args . V_45 + V_4 >
F_10 ( F_19 ( args . V_43 ) -> V_80 ) ) {
error = V_81 ;
goto V_97;
}
error = F_83 ( V_66 , args . V_43 , args . V_67 , args . V_45 , V_4 , 0 ) ;
if ( ! error )
F_124 ( V_66 , args . V_67 , args . V_45 , V_4 , 0 ) ;
V_97:
F_85 ( args . V_76 ) ;
return error ;
}
void
F_124 (
struct V_74 * V_66 ,
T_8 V_67 ,
T_1 V_3 ,
T_2 V_4 ,
unsigned int V_51 )
{
struct V_244 * V_111 ;
struct V_244 * V_245 ;
struct V_75 * V_76 ;
struct V_246 * * V_247 ;
struct V_246 * V_248 = NULL ;
V_111 = F_125 ( sizeof( struct V_244 ) , V_249 ) ;
if ( ! V_111 ) {
F_126 ( V_66 -> V_154 , V_67 , V_3 , V_4 ) ;
F_127 ( V_66 ) ;
return;
}
V_111 -> V_67 = V_67 ;
V_111 -> V_3 = V_3 ;
V_111 -> V_250 = V_4 ;
F_128 ( & V_111 -> V_251 ) ;
V_111 -> V_51 = V_51 ;
F_129 ( V_66 -> V_154 , V_67 , V_3 , V_4 ) ;
V_76 = F_84 ( V_66 -> V_154 , V_111 -> V_67 ) ;
F_130 ( & V_76 -> V_221 ) ;
V_247 = & V_76 -> V_223 . V_246 ;
while ( * V_247 ) {
V_248 = * V_247 ;
V_245 = F_131 ( V_248 , struct V_244 , V_246 ) ;
if ( V_111 -> V_3 < V_245 -> V_3 ) {
V_247 = & ( * V_247 ) -> V_252 ;
ASSERT ( V_111 -> V_3 + V_111 -> V_250 <= V_245 -> V_3 ) ;
} else if ( V_111 -> V_3 > V_245 -> V_3 ) {
V_247 = & ( * V_247 ) -> V_253 ;
ASSERT ( V_3 >= V_245 -> V_3 + V_245 -> V_250 ) ;
} else {
ASSERT ( 0 ) ;
}
}
F_132 ( & V_111 -> V_246 , V_248 , V_247 ) ;
F_133 ( & V_111 -> V_246 , & V_76 -> V_223 ) ;
F_134 ( & V_111 -> V_251 , & V_66 -> V_254 ) ;
F_135 ( & V_76 -> V_221 ) ;
F_85 ( V_76 ) ;
}
int
F_42 (
struct V_168 * V_65 ,
T_8 V_67 ,
T_1 V_3 ,
T_2 V_4 )
{
struct V_75 * V_76 ;
struct V_246 * V_247 ;
struct V_244 * V_245 ;
int V_255 = 0 ;
V_76 = F_84 ( V_65 , V_67 ) ;
F_130 ( & V_76 -> V_221 ) ;
V_247 = V_76 -> V_223 . V_246 ;
while ( V_247 ) {
V_245 = F_131 ( V_247 , struct V_244 , V_246 ) ;
if ( V_3 < V_245 -> V_3 ) {
if ( V_3 + V_4 > V_245 -> V_3 )
V_255 = - 1 ;
V_247 = V_247 -> V_252 ;
} else if ( V_3 > V_245 -> V_3 ) {
if ( V_3 < V_245 -> V_3 + V_245 -> V_250 )
V_255 = - 1 ;
V_247 = V_247 -> V_253 ;
} else {
V_255 = ( V_245 -> V_250 == V_4 ) ? 1 : - 1 ;
break;
}
}
F_135 ( & V_76 -> V_221 ) ;
F_85 ( V_76 ) ;
return V_255 ;
}
STATIC bool
F_136 (
struct V_168 * V_65 ,
struct V_75 * V_76 ,
struct V_244 * V_245 ,
T_1 V_48 ,
T_2 V_49 ,
bool V_149 )
{
T_1 V_256 = V_48 + V_49 ;
T_1 V_257 = V_245 -> V_3 ;
T_1 V_258 = V_257 + V_245 -> V_250 ;
if ( V_245 -> V_51 & V_259 ) {
F_135 ( & V_76 -> V_221 ) ;
F_137 ( 1 ) ;
F_130 ( & V_76 -> V_221 ) ;
return false ;
}
if ( V_149 )
goto V_260;
if ( V_257 < V_48 && V_258 > V_256 ) {
goto V_260;
} else if ( V_257 >= V_48 && V_258 <= V_256 ) {
F_138 ( & V_245 -> V_246 , & V_76 -> V_223 ) ;
V_245 -> V_250 = 0 ;
return false ;
} else if ( V_256 < V_258 ) {
V_245 -> V_3 = V_256 ;
} else if ( V_257 < V_48 ) {
V_245 -> V_250 = V_48 - V_245 -> V_3 ;
} else {
ASSERT ( 0 ) ;
}
F_139 ( V_65 , V_76 -> V_261 , V_48 , V_49 ) ;
return true ;
V_260:
F_135 ( & V_76 -> V_221 ) ;
F_65 ( V_65 , V_139 ) ;
F_140 ( V_65 , V_76 -> V_261 , V_48 , V_49 ) ;
F_130 ( & V_76 -> V_221 ) ;
return false ;
}
void
F_76 (
struct V_168 * V_65 ,
T_8 V_67 ,
T_1 V_48 ,
T_2 V_49 ,
bool V_149 )
{
struct V_75 * V_76 ;
struct V_246 * V_247 ;
ASSERT ( V_49 > 0 ) ;
V_76 = F_84 ( V_65 , V_67 ) ;
F_130 ( & V_76 -> V_221 ) ;
V_133:
V_247 = V_76 -> V_223 . V_246 ;
while ( V_247 ) {
struct V_244 * V_245 =
F_131 ( V_247 , struct V_244 , V_246 ) ;
T_1 V_257 = V_245 -> V_3 ;
T_1 V_258 = V_257 + V_245 -> V_250 ;
if ( V_48 + V_49 <= V_257 ) {
V_247 = V_247 -> V_252 ;
continue;
} else if ( V_48 >= V_258 ) {
V_247 = V_247 -> V_253 ;
continue;
}
if ( ! F_136 ( V_65 , V_76 , V_245 , V_48 , V_49 ,
V_149 ) )
goto V_133;
}
F_135 ( & V_76 -> V_221 ) ;
F_85 ( V_76 ) ;
}
STATIC void
F_12 (
struct V_102 * args ,
T_1 V_3 ,
T_2 V_4 ,
T_1 * V_50 ,
T_2 * V_37 )
{
T_1 V_48 ;
T_2 V_49 ;
struct V_246 * V_247 ;
ASSERT ( V_4 > 0 ) ;
F_130 ( & args -> V_76 -> V_221 ) ;
V_133:
V_48 = V_3 ;
V_49 = V_4 ;
V_247 = args -> V_76 -> V_223 . V_246 ;
while ( V_247 && V_49 >= args -> V_21 ) {
struct V_244 * V_245 =
F_131 ( V_247 , struct V_244 , V_246 ) ;
T_1 V_256 = V_48 + V_49 ;
T_1 V_257 = V_245 -> V_3 ;
T_1 V_258 = V_257 + V_245 -> V_250 ;
if ( V_256 <= V_257 ) {
V_247 = V_247 -> V_252 ;
continue;
} else if ( V_48 >= V_258 ) {
V_247 = V_247 -> V_253 ;
continue;
}
if ( ! args -> V_149 &&
! ( V_245 -> V_51 & V_259 ) ) {
if ( ! F_136 ( args -> V_65 , args -> V_76 ,
V_245 , V_48 , V_49 ,
false ) )
goto V_133;
continue;
}
if ( V_257 <= V_48 ) {
if ( V_256 <= V_258 )
goto V_262;
V_48 = V_258 ;
} else if ( V_258 >= V_256 ) {
V_256 = V_257 ;
} else {
if ( V_257 - V_48 >= args -> V_40 ) {
V_256 = V_257 ;
} else if ( V_256 - V_258 >= args -> V_40 * 4 ) {
V_48 = V_258 ;
} else if ( V_257 - V_48 >= args -> V_21 ) {
V_256 = V_257 ;
} else {
goto V_262;
}
}
V_49 = V_256 - V_48 ;
}
F_135 ( & args -> V_76 -> V_221 ) ;
if ( V_48 != V_3 || V_49 != V_4 ) {
F_141 ( args -> V_65 , args -> V_67 , V_3 , V_4 ,
V_48 , V_49 ) ;
}
* V_50 = V_48 ;
* V_37 = V_49 ;
return;
V_262:
F_135 ( & args -> V_76 -> V_221 ) ;
F_141 ( args -> V_65 , args -> V_67 , V_3 , V_4 , V_48 , 0 ) ;
* V_50 = V_48 ;
* V_37 = 0 ;
}
static void
F_142 (
struct V_168 * V_65 ,
struct V_75 * V_76 ,
struct V_244 * V_245 )
{
if ( V_245 -> V_250 ) {
F_143 ( V_65 , V_245 -> V_67 , V_245 -> V_3 ,
V_245 -> V_250 ) ;
F_138 ( & V_245 -> V_246 , & V_76 -> V_223 ) ;
}
F_144 ( & V_245 -> V_251 ) ;
F_145 ( V_245 ) ;
}
void
F_146 (
struct V_168 * V_65 ,
struct V_263 * V_251 ,
bool V_264 )
{
struct V_244 * V_245 , * V_265 ;
struct V_75 * V_76 = NULL ;
T_8 V_67 = V_70 ;
F_147 (busyp, n, list, list) {
if ( V_245 -> V_67 != V_67 ) {
if ( V_76 ) {
F_135 ( & V_76 -> V_221 ) ;
F_85 ( V_76 ) ;
}
V_76 = F_84 ( V_65 , V_245 -> V_67 ) ;
F_130 ( & V_76 -> V_221 ) ;
V_67 = V_245 -> V_67 ;
}
if ( V_264 && V_245 -> V_250 &&
! ( V_245 -> V_51 & V_266 ) )
V_245 -> V_51 = V_259 ;
else
F_142 ( V_65 , V_76 , V_245 ) ;
}
if ( V_76 ) {
F_135 ( & V_76 -> V_221 ) ;
F_85 ( V_76 ) ;
}
}
int
F_148 (
void * V_267 ,
struct V_263 * V_7 ,
struct V_263 * V_268 )
{
return F_149 ( V_7 , struct V_244 , V_251 ) -> V_67 -
F_149 ( V_268 , struct V_244 , V_251 ) -> V_67 ;
}
