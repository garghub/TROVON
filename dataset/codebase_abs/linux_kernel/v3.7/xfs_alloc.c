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
F_32 ( V_69 , V_72 ) ;
* V_68 = V_69 ;
return 0 ;
}
STATIC int
F_33 (
struct V_73 * V_66 ,
struct V_74 * V_75 ,
struct V_76 * V_43 ,
long V_4 )
{
struct V_77 * V_41 = F_19 ( V_43 ) ;
V_75 -> V_78 += V_4 ;
F_34 ( & V_41 -> V_44 , V_4 ) ;
F_35 ( V_66 , V_4 ) ;
if ( F_36 ( F_10 ( V_41 -> V_44 ) >
F_10 ( V_41 -> V_79 ) ) )
return V_80 ;
F_37 ( V_66 , V_43 , V_81 ) ;
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
args -> V_82 = 0 ;
switch ( args -> type ) {
case V_83 :
error = F_39 ( args ) ;
break;
case V_84 :
error = F_40 ( args ) ;
break;
case V_85 :
error = F_41 ( args ) ;
break;
default:
ASSERT ( 0 ) ;
}
if ( error || args -> V_45 == V_35 )
return error ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_40 ) ;
ASSERT ( ! args -> V_82 || ! args -> V_86 ) ;
ASSERT ( args -> V_45 % args -> V_20 == 0 ) ;
if ( ! args -> V_82 ) {
error = F_33 ( args -> V_66 , args -> V_75 ,
args -> V_43 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
if ( error )
return error ;
ASSERT ( ! F_42 ( args -> V_65 , args -> V_67 ,
args -> V_45 , args -> V_4 ) ) ;
}
if ( ! args -> V_86 ) {
F_43 ( args -> V_66 , args -> V_87 ?
V_88 :
V_89 ,
- ( ( long ) ( args -> V_4 ) ) ) ;
}
F_44 ( V_90 ) ;
F_45 ( V_91 , args -> V_4 ) ;
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
T_1 V_92 ;
T_2 V_93 ;
T_1 V_94 ;
int V_52 ;
ASSERT ( args -> V_20 == 1 ) ;
V_47 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_95 ) ;
error = F_4 ( V_47 , args -> V_45 , args -> V_21 , & V_52 ) ;
if ( error )
goto V_96;
if ( ! V_52 )
goto V_97;
error = F_8 ( V_47 , & V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
ASSERT ( V_48 <= args -> V_45 ) ;
F_12 ( args , V_48 , V_49 , & V_92 , & V_93 ) ;
if ( V_92 > args -> V_45 )
goto V_97;
if ( V_93 < args -> V_21 )
goto V_97;
V_94 = V_92 + V_93 ;
if ( V_94 < args -> V_45 + args -> V_21 )
goto V_97;
args -> V_4 = F_48 ( V_94 , args -> V_45 + args -> V_40 )
- args -> V_45 ;
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_97;
ASSERT ( args -> V_45 + args -> V_4 <= V_94 ) ;
V_46 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_98 ) ;
ASSERT ( args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_79 ) ) ;
error = F_20 ( V_46 , V_47 , V_48 , V_49 , args -> V_45 ,
args -> V_4 , V_58 ) ;
if ( error ) {
F_49 ( V_46 , V_99 ) ;
goto V_96;
}
F_49 ( V_47 , V_100 ) ;
F_49 ( V_46 , V_100 ) ;
args -> V_82 = 0 ;
F_50 ( args ) ;
return 0 ;
V_97:
F_49 ( V_47 , V_100 ) ;
args -> V_45 = V_35 ;
F_51 ( args ) ;
return 0 ;
V_96:
F_49 ( V_47 , V_99 ) ;
F_52 ( args ) ;
return error ;
}
STATIC int
F_53 (
struct V_101 * args ,
struct V_1 * * V_102 ,
struct V_1 * * V_103 ,
T_1 V_104 ,
T_1 * V_105 ,
T_2 * V_106 ,
T_1 * V_107 ,
T_2 * V_108 ,
int V_109 )
{
T_1 V_110 ;
T_1 V_111 ;
int error ;
int V_52 ;
if ( ! V_104 )
goto V_112;
do {
error = F_8 ( * V_103 , V_105 , V_106 , & V_52 ) ;
if ( error )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
F_11 ( args , * V_105 , * V_106 , V_107 , V_108 ) ;
if ( ! V_109 ) {
if ( * V_107 >= args -> V_45 + V_104 )
goto V_112;
} else {
if ( * V_107 <= args -> V_45 - V_104 )
goto V_112;
}
if ( * V_108 >= args -> V_21 ) {
args -> V_4 = F_15 ( * V_108 , args -> V_40 ) ;
F_17 ( args ) ;
V_111 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , * V_107 ,
* V_108 , & V_110 ) ;
if ( V_111 < V_104 )
goto V_113;
goto V_112;
}
if ( ! V_109 )
error = F_54 ( * V_103 , 0 , & V_52 ) ;
else
error = F_55 ( * V_103 , 0 , & V_52 ) ;
if ( error )
goto V_96;
} while ( V_52 );
V_112:
F_49 ( * V_103 , V_100 ) ;
* V_103 = NULL ;
return 0 ;
V_113:
F_49 ( * V_102 , V_100 ) ;
* V_102 = NULL ;
return 0 ;
V_96:
return error ;
}
STATIC int
F_40 (
T_3 * args )
{
T_5 * V_114 ;
T_5 * V_115 ;
T_5 * V_46 ;
T_1 V_116 ;
T_1 V_117 ;
T_2 V_118 ;
T_2 V_119 ;
T_2 V_120 ;
T_1 V_121 ;
int error ;
int V_52 ;
int V_122 ;
T_1 V_123 ;
T_1 V_124 ;
T_2 V_125 ;
T_2 V_126 ;
T_2 V_127 ;
T_1 V_128 ;
T_2 V_37 ;
int V_129 = 0 ;
#if F_56 ( F_21 ) && F_56 ( V_130 )
int V_131 ;
V_131 = F_57 () & 1 ;
#endif
V_132:
V_115 = NULL ;
V_114 = NULL ;
V_126 = 0 ;
V_120 = 0 ;
V_127 = 0 ;
V_46 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_98 ) ;
if ( ( error = F_3 ( V_46 , 0 , args -> V_40 , & V_52 ) ) )
goto V_96;
if ( ! V_52 ) {
if ( ( error = F_58 ( args , V_46 , & V_123 ,
& V_126 , & V_52 ) ) )
goto V_96;
if ( V_52 == 0 || V_126 == 0 ) {
F_49 ( V_46 , V_100 ) ;
F_59 ( args ) ;
return 0 ;
}
ASSERT ( V_52 == 1 ) ;
}
args -> V_82 = 0 ;
while ( F_60 ( V_46 , 0 ) ) {
T_2 V_133 ;
int V_134 = 0 ;
T_2 V_135 = 0 ;
T_1 V_136 = 0 ;
#if F_56 ( F_21 ) && F_56 ( V_130 )
if ( ! V_131 )
break;
#endif
if ( V_126 || args -> V_20 > 1 ) {
V_46 -> V_137 [ 0 ] = 1 ;
do {
if ( ( error = F_8 ( V_46 , & V_123 ,
& V_126 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( V_126 >= args -> V_21 )
break;
if ( ( error = F_54 ( V_46 , 0 , & V_52 ) ) )
goto V_96;
} while ( V_52 );
ASSERT ( V_126 >= args -> V_21 ) ;
if ( ! V_52 )
break;
}
V_52 = V_46 -> V_137 [ 0 ] ;
for ( V_122 = 1 , V_135 = 0 , V_133 = 0 ;
! error && V_122 && ( V_135 < args -> V_40 || V_133 > 0 ) ;
error = F_54 ( V_46 , 0 , & V_122 ) ) {
if ( ( error = F_8 ( V_46 , & V_123 , & V_126 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
F_11 ( args , V_123 , V_126 ,
& V_124 , & V_127 ) ;
if ( V_127 < args -> V_21 )
continue;
args -> V_4 = F_15 ( V_127 , args -> V_40 ) ;
F_17 ( args ) ;
ASSERT ( args -> V_4 >= args -> V_21 ) ;
if ( args -> V_4 < V_135 )
continue;
V_125 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_124 , V_127 , & V_128 ) ;
if ( V_128 != V_35 &&
( args -> V_4 > V_135 || V_125 < V_133 ) ) {
V_133 = V_125 ;
V_136 = V_128 ;
V_135 = args -> V_4 ;
V_134 = V_46 -> V_137 [ 0 ] ;
}
}
if ( V_135 == 0 )
break;
V_46 -> V_137 [ 0 ] = V_134 ;
if ( ( error = F_8 ( V_46 , & V_123 , & V_126 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
ASSERT ( V_123 + V_126 <= F_10 ( F_19 ( args -> V_43 ) -> V_79 ) ) ;
args -> V_4 = V_135 ;
if ( ! F_18 ( args ) ) {
F_49 ( V_46 , V_100 ) ;
F_61 ( args ) ;
return 0 ;
}
V_135 = args -> V_4 ;
args -> V_45 = V_136 ;
ASSERT ( V_136 >= V_123 ) ;
ASSERT ( V_136 + V_135 <= V_123 + V_126 ) ;
V_115 = F_46 ( args -> V_65 , args -> V_66 ,
args -> V_43 , args -> V_67 , V_95 ) ;
if ( ( error = F_20 ( V_46 , V_115 , V_123 ,
V_126 , V_136 , V_135 , V_57 ) ) )
goto V_96;
F_49 ( V_46 , V_100 ) ;
F_49 ( V_115 , V_100 ) ;
F_62 ( args ) ;
return 0 ;
}
V_115 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_95 ) ;
if ( ( error = F_4 ( V_115 , args -> V_45 , args -> V_40 , & V_52 ) ) )
goto V_96;
if ( ! V_52 ) {
V_114 = V_115 ;
V_115 = NULL ;
}
else if ( ( error = F_63 ( V_115 , & V_114 ) ) )
goto V_96;
if ( ( error = F_54 ( V_114 , 0 , & V_52 ) ) )
goto V_96;
if ( ! V_52 ) {
F_49 ( V_114 , V_100 ) ;
V_114 = NULL ;
}
do {
if ( V_115 ) {
if ( ( error = F_8 ( V_115 , & V_123 , & V_126 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
F_11 ( args , V_123 , V_126 ,
& V_124 , & V_127 ) ;
if ( V_127 >= args -> V_21 )
break;
if ( ( error = F_55 ( V_115 , 0 , & V_52 ) ) )
goto V_96;
if ( ! V_52 ) {
F_49 ( V_115 ,
V_100 ) ;
V_115 = NULL ;
}
}
if ( V_114 ) {
if ( ( error = F_8 ( V_114 , & V_116 , & V_119 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
F_11 ( args , V_116 , V_119 ,
& V_117 , & V_120 ) ;
if ( V_120 >= args -> V_21 )
break;
if ( ( error = F_54 ( V_114 , 0 , & V_52 ) ) )
goto V_96;
if ( ! V_52 ) {
F_49 ( V_114 ,
V_100 ) ;
V_114 = NULL ;
}
}
} while ( V_115 || V_114 );
if ( V_115 && V_114 ) {
if ( V_127 >= args -> V_21 ) {
args -> V_4 = F_15 ( V_127 , args -> V_40 ) ;
F_17 ( args ) ;
V_125 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_124 , V_127 , & V_128 ) ;
error = F_53 ( args ,
& V_115 , & V_114 ,
V_125 , & V_116 , & V_119 ,
& V_117 , & V_120 ,
0 ) ;
} else {
ASSERT ( V_120 >= args -> V_21 ) ;
args -> V_4 = F_15 ( V_120 , args -> V_40 ) ;
F_17 ( args ) ;
V_118 = F_14 ( args -> V_45 , args -> V_4 ,
args -> V_20 , V_117 , V_120 , & V_121 ) ;
error = F_53 ( args ,
& V_114 , & V_115 ,
V_118 , & V_123 , & V_126 ,
& V_124 , & V_127 ,
1 ) ;
}
if ( error )
goto V_96;
}
if ( V_115 == NULL && V_114 == NULL ) {
F_49 ( V_46 , V_100 ) ;
if ( ! V_129 ++ ) {
F_64 ( args ) ;
F_65 ( args -> V_65 , V_138 ) ;
goto V_132;
}
F_66 ( args ) ;
args -> V_45 = V_35 ;
return 0 ;
}
if ( V_114 ) {
V_115 = V_114 ;
V_114 = NULL ;
V_123 = V_116 ;
V_124 = V_117 ;
V_126 = V_119 ;
V_127 = V_120 ;
V_122 = 1 ;
} else
V_122 = 0 ;
args -> V_4 = F_15 ( V_127 , args -> V_40 ) ;
F_17 ( args ) ;
if ( ! F_18 ( args ) ) {
F_61 ( args ) ;
F_49 ( V_115 , V_100 ) ;
F_49 ( V_46 , V_100 ) ;
return 0 ;
}
V_37 = args -> V_4 ;
( void ) F_14 ( args -> V_45 , V_37 , args -> V_20 ,
V_124 , V_127 , & V_128 ) ;
ASSERT ( V_128 >= V_123 ) ;
ASSERT ( V_128 + V_37 <= V_124 + V_127 ) ;
ASSERT ( V_128 + V_37 <= F_10 ( F_19 ( args -> V_43 ) -> V_79 ) ) ;
args -> V_45 = V_128 ;
if ( ( error = F_20 ( V_46 , V_115 , V_123 , V_126 ,
V_128 , V_37 , V_58 ) ) )
goto V_96;
if ( V_122 )
F_67 ( args ) ;
else
F_68 ( args ) ;
F_49 ( V_46 , V_100 ) ;
F_49 ( V_115 , V_100 ) ;
return 0 ;
V_96:
F_69 ( args ) ;
if ( V_46 != NULL )
F_49 ( V_46 , V_99 ) ;
if ( V_115 != NULL )
F_49 ( V_115 , V_99 ) ;
if ( V_114 != NULL )
F_49 ( V_114 , V_99 ) ;
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
int V_129 = 0 ;
V_132:
V_46 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_98 ) ;
V_47 = NULL ;
if ( ( error = F_3 ( V_46 , 0 ,
args -> V_40 + args -> V_20 - 1 , & V_52 ) ) )
goto V_96;
if ( ! V_52 || V_129 > 1 ) {
error = F_58 ( args , V_46 ,
& V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_96;
if ( V_52 == 0 || V_49 == 0 ) {
F_49 ( V_46 , V_100 ) ;
F_70 ( args ) ;
return 0 ;
}
ASSERT ( V_52 == 1 ) ;
F_11 ( args , V_48 , V_49 , & V_50 , & V_37 ) ;
} else {
for (; ; ) {
error = F_8 ( V_46 , & V_48 , & V_49 , & V_52 ) ;
if ( error )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
F_11 ( args , V_48 , V_49 ,
& V_50 , & V_37 ) ;
if ( V_37 >= args -> V_40 )
break;
error = F_54 ( V_46 , 0 , & V_52 ) ;
if ( error )
goto V_96;
if ( V_52 == 0 ) {
F_49 ( V_46 ,
V_100 ) ;
F_71 ( args ) ;
if ( ! V_129 ++ )
F_65 ( args -> V_65 , V_138 ) ;
goto V_132;
}
}
}
V_37 = F_15 ( args -> V_40 , V_37 ) ;
F_47 ( V_37 == 0 ||
( V_37 <= V_49 && V_50 + V_37 <= V_48 + V_49 ) , V_96 ) ;
if ( V_37 < args -> V_40 ) {
T_1 V_139 ;
T_2 V_140 ;
T_1 V_141 ;
T_2 V_142 ;
V_142 = V_37 ;
V_141 = V_50 ;
V_140 = V_49 ;
V_139 = V_48 ;
for (; ; ) {
if ( ( error = F_55 ( V_46 , 0 , & V_52 ) ) )
goto V_96;
if ( V_52 == 0 )
break;
if ( ( error = F_8 ( V_46 , & V_48 , & V_49 ,
& V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( V_49 < V_142 )
break;
F_11 ( args , V_48 , V_49 ,
& V_50 , & V_37 ) ;
V_37 = F_15 ( args -> V_40 , V_37 ) ;
F_47 ( V_37 == 0 ||
( V_37 <= V_49 && V_50 + V_37 <= V_48 + V_49 ) ,
V_96 ) ;
if ( V_37 > V_142 ) {
V_142 = V_37 ;
V_141 = V_50 ;
V_140 = V_49 ;
V_139 = V_48 ;
if ( V_37 == args -> V_40 )
break;
}
}
if ( ( error = F_1 ( V_46 , V_139 , V_140 ,
& V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
V_37 = V_142 ;
V_50 = V_141 ;
V_49 = V_140 ;
V_48 = V_139 ;
}
args -> V_82 = 0 ;
args -> V_4 = V_37 ;
if ( V_37 < args -> V_21 ) {
if ( ! V_129 ++ ) {
F_49 ( V_46 , V_100 ) ;
F_71 ( args ) ;
F_65 ( args -> V_65 , V_138 ) ;
goto V_132;
}
goto V_143;
}
F_17 ( args ) ;
if ( ! F_18 ( args ) )
goto V_143;
V_37 = args -> V_4 ;
F_47 ( V_37 <= V_49 , V_96 ) ;
V_47 = F_46 ( args -> V_65 , args -> V_66 , args -> V_43 ,
args -> V_67 , V_95 ) ;
if ( ( error = F_20 ( V_46 , V_47 , V_48 , V_49 ,
V_50 , V_37 , V_57 ) ) )
goto V_96;
F_49 ( V_46 , V_100 ) ;
F_49 ( V_47 , V_100 ) ;
V_46 = V_47 = NULL ;
args -> V_4 = V_37 ;
args -> V_45 = V_50 ;
F_47 (
args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_79 ) ,
V_96 ) ;
F_72 ( args ) ;
return 0 ;
V_96:
F_73 ( args ) ;
if ( V_46 )
F_49 ( V_46 , V_99 ) ;
if ( V_47 )
F_49 ( V_47 , V_99 ) ;
return error ;
V_143:
F_49 ( V_46 , V_100 ) ;
F_74 ( args ) ;
args -> V_45 = V_35 ;
return 0 ;
}
STATIC int
F_58 (
T_3 * args ,
T_5 * V_144 ,
T_1 * V_145 ,
T_2 * V_146 ,
int * V_5 )
{
int error ;
T_1 V_48 ;
T_2 V_49 ;
int V_52 ;
if ( ( error = F_55 ( V_144 , 0 , & V_52 ) ) )
goto V_96;
if ( V_52 ) {
if ( ( error = F_8 ( V_144 , & V_48 , & V_49 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
}
else if ( args -> V_21 == 1 && args -> V_20 == 1 && ! args -> V_86 &&
( F_10 ( F_19 ( args -> V_43 ) -> V_147 )
> args -> V_42 ) ) {
error = F_75 ( args -> V_66 , args -> V_43 , & V_48 , 0 ) ;
if ( error )
goto V_96;
if ( V_48 != V_35 ) {
F_76 ( args -> V_65 , args -> V_67 , V_48 , 1 ,
args -> V_148 ) ;
if ( args -> V_148 ) {
T_9 * V_69 ;
V_69 = F_77 ( args -> V_65 , args -> V_66 ,
args -> V_67 , V_48 , 0 ) ;
F_78 ( args -> V_66 , V_69 ) ;
}
args -> V_4 = 1 ;
args -> V_45 = V_48 ;
F_47 (
args -> V_45 + args -> V_4 <=
F_10 ( F_19 ( args -> V_43 ) -> V_79 ) ,
V_96 ) ;
args -> V_82 = 1 ;
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
* V_145 = V_48 ;
* V_146 = V_49 ;
* V_5 = 1 ;
F_81 ( args ) ;
return 0 ;
V_96:
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
int V_86 )
{
T_5 * V_47 ;
T_5 * V_46 ;
int error ;
T_1 V_116 ;
T_2 V_119 ;
int V_149 ;
int V_150 ;
int V_52 ;
T_1 V_123 ;
T_2 V_126 ;
T_6 * V_65 ;
T_1 V_151 ;
T_2 V_152 ;
T_10 * V_75 ;
V_65 = V_66 -> V_153 ;
V_47 = F_46 ( V_65 , V_66 , V_43 , V_67 , V_95 ) ;
V_46 = NULL ;
if ( ( error = F_4 ( V_47 , V_3 , V_4 , & V_149 ) ) )
goto V_96;
if ( V_149 ) {
if ( ( error = F_8 ( V_47 , & V_123 , & V_126 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( V_123 + V_126 < V_3 )
V_149 = 0 ;
else {
F_47 ( V_123 + V_126 <= V_3 , V_96 ) ;
}
}
if ( ( error = F_54 ( V_47 , 0 , & V_150 ) ) )
goto V_96;
if ( V_150 ) {
if ( ( error = F_8 ( V_47 , & V_116 , & V_119 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( V_3 + V_4 < V_116 )
V_150 = 0 ;
else {
F_47 ( V_116 >= V_3 + V_4 , V_96 ) ;
}
}
V_46 = F_46 ( V_65 , V_66 , V_43 , V_67 , V_98 ) ;
if ( V_149 && V_150 ) {
if ( ( error = F_1 ( V_46 , V_123 , V_126 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( ( error = F_1 ( V_46 , V_116 , V_119 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( ( error = F_24 ( V_47 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( ( error = F_55 ( V_47 , 0 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
#ifdef F_21
{
T_1 V_154 ;
T_2 V_155 ;
if ( ( error = F_8 ( V_47 , & V_154 , & V_155 ,
& V_52 ) ) )
goto V_96;
F_47 (
V_52 == 1 && V_154 == V_123 && V_155 == V_126 ,
V_96 ) ;
}
#endif
V_151 = V_123 ;
V_152 = V_4 + V_126 + V_119 ;
if ( ( error = F_5 ( V_47 , V_151 , V_152 ) ) )
goto V_96;
}
else if ( V_149 ) {
if ( ( error = F_1 ( V_46 , V_123 , V_126 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( ( error = F_55 ( V_47 , 0 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
V_151 = V_123 ;
V_152 = V_4 + V_126 ;
if ( ( error = F_5 ( V_47 , V_151 , V_152 ) ) )
goto V_96;
}
else if ( V_150 ) {
if ( ( error = F_1 ( V_46 , V_116 , V_119 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
if ( ( error = F_24 ( V_46 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
V_151 = V_3 ;
V_152 = V_4 + V_119 ;
if ( ( error = F_5 ( V_47 , V_151 , V_152 ) ) )
goto V_96;
}
else {
V_151 = V_3 ;
V_152 = V_4 ;
if ( ( error = F_25 ( V_47 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
}
F_49 ( V_47 , V_100 ) ;
V_47 = NULL ;
if ( ( error = F_1 ( V_46 , V_151 , V_152 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 0 , V_96 ) ;
if ( ( error = F_25 ( V_46 , & V_52 ) ) )
goto V_96;
F_47 ( V_52 == 1 , V_96 ) ;
F_49 ( V_46 , V_100 ) ;
V_46 = NULL ;
V_75 = F_84 ( V_65 , V_67 ) ;
error = F_33 ( V_66 , V_75 , V_43 , V_4 ) ;
F_85 ( V_75 ) ;
if ( error )
goto V_96;
if ( ! V_86 )
F_43 ( V_66 , V_89 , ( long ) V_4 ) ;
F_44 ( V_156 ) ;
F_45 ( V_157 , V_4 ) ;
F_86 ( V_65 , V_67 , V_3 , V_4 , V_86 , V_149 , V_150 ) ;
return 0 ;
V_96:
F_86 ( V_65 , V_67 , V_3 , V_4 , V_86 , - 1 , - 1 ) ;
if ( V_47 )
F_49 ( V_47 , V_99 ) ;
if ( V_46 )
F_49 ( V_46 , V_99 ) ;
return error ;
}
void
F_87 (
T_6 * V_65 )
{
int V_158 ;
T_11 V_159 ;
T_11 V_160 ;
int V_161 ;
int V_162 ;
V_160 = ( V_65 -> V_163 . V_164 + 1 ) / 2 ;
V_161 = V_65 -> V_165 [ 0 ] ;
V_162 = V_65 -> V_165 [ 1 ] ;
V_159 = ( V_160 + V_161 - 1 ) / V_161 ;
for ( V_158 = 1 ; V_159 > 1 ; V_158 ++ )
V_159 = ( V_159 + V_162 - 1 ) / V_162 ;
V_65 -> V_166 = V_158 ;
}
T_2
F_88 (
struct V_167 * V_65 ,
struct V_74 * V_75 )
{
T_2 V_168 , V_169 = 0 ;
V_168 = F_89 ( V_75 , V_65 ) ;
if ( V_168 > V_75 -> V_170 )
V_169 = V_168 - V_75 -> V_170 ;
if ( V_75 -> V_171 > V_169 )
return V_75 -> V_171 - V_169 ;
return V_75 -> V_170 > 0 || V_75 -> V_171 > 0 ;
}
STATIC int
F_90 (
T_3 * args ,
int V_51 )
{
T_9 * V_43 ;
T_4 * V_41 ;
T_9 * V_172 ;
T_1 V_3 ;
T_2 V_169 ;
int error ;
T_2 V_173 ;
T_6 * V_65 ;
T_2 V_168 ;
T_10 * V_75 ;
T_3 V_174 ;
T_7 * V_66 ;
V_65 = args -> V_65 ;
V_75 = args -> V_75 ;
V_66 = args -> V_66 ;
if ( ! V_75 -> V_175 ) {
if ( ( error = F_91 ( V_65 , V_66 , args -> V_67 , V_51 ,
& V_43 ) ) )
return error ;
if ( ! V_75 -> V_175 ) {
ASSERT ( V_51 & V_176 ) ;
ASSERT ( ! ( V_51 & V_177 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
} else
V_43 = NULL ;
if ( V_75 -> V_178 && args -> V_148 &&
( V_51 & V_176 ) ) {
ASSERT ( ! ( V_51 & V_177 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
if ( ! ( V_51 & V_177 ) ) {
V_168 = F_89 ( V_75 , V_65 ) ;
V_173 = F_88 ( V_65 , V_75 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_179 - 1 ) >
V_173 ||
( ( int ) ( V_75 -> V_78 + V_75 -> V_170 -
V_168 - args -> V_180 ) < ( int ) args -> V_42 ) ) {
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
ASSERT ( V_51 & V_176 ) ;
ASSERT ( ! ( V_51 & V_177 ) ) ;
args -> V_43 = NULL ;
return 0 ;
}
}
V_41 = F_19 ( V_43 ) ;
V_168 = F_93 ( V_41 , V_65 ) ;
if ( ! ( V_51 & V_177 ) ) {
V_169 = V_168 > F_10 ( V_41 -> V_147 ) ?
( V_168 - F_10 ( V_41 -> V_147 ) ) : 0 ;
V_173 = F_10 ( V_41 -> V_181 ) ;
V_173 = ( V_173 > V_169 ) ? ( V_173 - V_169 ) :
( F_10 ( V_41 -> V_147 ) > 0 || V_173 > 0 ) ;
if ( ( args -> V_21 + args -> V_20 + args -> V_179 - 1 ) >
V_173 ||
( ( int ) ( F_10 ( V_41 -> V_44 ) +
F_10 ( V_41 -> V_147 ) - V_168 - args -> V_180 ) <
( int ) args -> V_42 ) ) {
F_92 ( V_66 , V_43 ) ;
args -> V_43 = NULL ;
return 0 ;
}
}
while ( F_10 ( V_41 -> V_147 ) > V_168 ) {
T_9 * V_69 ;
error = F_75 ( V_66 , V_43 , & V_3 , 0 ) ;
if ( error )
return error ;
if ( ( error = F_83 ( V_66 , V_43 , args -> V_67 , V_3 , 1 , 1 ) ) )
return error ;
V_69 = F_77 ( V_65 , V_66 , args -> V_67 , V_3 , 0 ) ;
F_78 ( V_66 , V_69 ) ;
}
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
V_174 . V_66 = V_66 ;
V_174 . V_65 = V_65 ;
V_174 . V_43 = V_43 ;
V_174 . V_67 = args -> V_67 ;
V_174 . V_38 = V_174 . V_42 = V_174 . V_87 = V_174 . V_148 =
V_174 . V_179 = 0 ;
V_174 . V_20 = V_174 . V_21 = V_174 . V_39 = V_174 . V_86 = 1 ;
V_174 . type = V_83 ;
V_174 . V_75 = V_75 ;
if ( ( error = F_26 ( V_65 , V_66 , V_174 . V_67 , & V_172 ) ) )
return error ;
while ( F_10 ( V_41 -> V_147 ) < V_168 ) {
V_174 . V_45 = 0 ;
V_174 . V_40 = V_168 - F_10 ( V_41 -> V_147 ) ;
if ( ( error = F_38 ( & V_174 ) ) ) {
F_92 ( V_66 , V_172 ) ;
return error ;
}
if ( V_174 . V_45 == V_35 ) {
if ( V_51 & V_177 )
break;
F_92 ( V_66 , V_172 ) ;
args -> V_43 = NULL ;
return 0 ;
}
for ( V_3 = V_174 . V_45 ; V_3 < V_174 . V_45 + V_174 . V_4 ; V_3 ++ ) {
error = F_94 ( V_66 , V_43 ,
V_172 , V_3 , 0 ) ;
if ( error )
return error ;
}
}
F_92 ( V_66 , V_172 ) ;
args -> V_43 = V_43 ;
return 0 ;
}
int
F_75 (
T_7 * V_66 ,
T_9 * V_43 ,
T_1 * V_182 ,
int V_183 )
{
T_4 * V_41 ;
T_12 * V_184 ;
T_9 * V_172 ;
T_1 V_3 ;
int error ;
int V_185 ;
T_6 * V_65 ;
T_10 * V_75 ;
V_41 = F_19 ( V_43 ) ;
if ( ! V_41 -> V_147 ) {
* V_182 = V_35 ;
return 0 ;
}
V_65 = V_66 -> V_153 ;
if ( ( error = F_26 ( V_65 , V_66 ,
F_10 ( V_41 -> V_186 ) , & V_172 ) ) )
return error ;
V_184 = F_95 ( V_172 ) ;
V_3 = F_10 ( V_184 -> V_187 [ F_10 ( V_41 -> V_188 ) ] ) ;
F_34 ( & V_41 -> V_188 , 1 ) ;
F_92 ( V_66 , V_172 ) ;
if ( F_10 ( V_41 -> V_188 ) == F_96 ( V_65 ) )
V_41 -> V_188 = 0 ;
V_75 = F_84 ( V_65 , F_10 ( V_41 -> V_186 ) ) ;
F_34 ( & V_41 -> V_147 , - 1 ) ;
F_97 ( V_66 , - 1 ) ;
V_75 -> V_170 -- ;
F_85 ( V_75 ) ;
V_185 = V_189 | V_190 ;
if ( V_183 ) {
F_34 ( & V_41 -> V_191 , 1 ) ;
V_75 -> V_192 ++ ;
V_185 |= V_193 ;
}
F_37 ( V_66 , V_43 , V_185 ) ;
* V_182 = V_3 ;
return 0 ;
}
void
F_37 (
T_7 * V_66 ,
T_9 * V_69 ,
int V_194 )
{
int V_195 ;
int V_196 ;
static const short V_197 [] = {
F_98 ( T_4 , V_198 ) ,
F_98 ( T_4 , V_199 ) ,
F_98 ( T_4 , V_186 ) ,
F_98 ( T_4 , V_79 ) ,
F_98 ( T_4 , V_200 [ 0 ] ) ,
F_98 ( T_4 , V_201 [ 0 ] ) ,
F_98 ( T_4 , V_188 ) ,
F_98 ( T_4 , V_202 ) ,
F_98 ( T_4 , V_147 ) ,
F_98 ( T_4 , V_44 ) ,
F_98 ( T_4 , V_181 ) ,
F_98 ( T_4 , V_191 ) ,
sizeof( T_4 )
} ;
F_99 ( V_66 -> V_153 , F_19 ( V_69 ) , V_194 , V_203 ) ;
F_100 ( V_194 , V_197 , V_204 , & V_195 , & V_196 ) ;
F_101 ( V_66 , V_69 , ( T_11 ) V_195 , ( T_11 ) V_196 ) ;
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
T_9 * V_172 ,
T_1 V_3 ,
int V_183 )
{
T_4 * V_41 ;
T_12 * V_184 ;
T_13 * V_205 ;
int error ;
int V_185 ;
T_6 * V_65 ;
T_10 * V_75 ;
V_41 = F_19 ( V_43 ) ;
V_65 = V_66 -> V_153 ;
if ( ! V_172 && ( error = F_26 ( V_65 , V_66 ,
F_10 ( V_41 -> V_186 ) , & V_172 ) ) )
return error ;
V_184 = F_95 ( V_172 ) ;
F_34 ( & V_41 -> V_202 , 1 ) ;
if ( F_10 ( V_41 -> V_202 ) == F_96 ( V_65 ) )
V_41 -> V_202 = 0 ;
V_75 = F_84 ( V_65 , F_10 ( V_41 -> V_186 ) ) ;
F_34 ( & V_41 -> V_147 , 1 ) ;
F_97 ( V_66 , 1 ) ;
V_75 -> V_170 ++ ;
V_185 = V_206 | V_190 ;
if ( V_183 ) {
F_34 ( & V_41 -> V_191 , - 1 ) ;
V_75 -> V_192 -- ;
V_185 |= V_193 ;
}
F_85 ( V_75 ) ;
F_37 ( V_66 , V_43 , V_185 ) ;
ASSERT ( F_10 ( V_41 -> V_147 ) <= F_96 ( V_65 ) ) ;
V_205 = & V_184 -> V_187 [ F_10 ( V_41 -> V_202 ) ] ;
* V_205 = F_6 ( V_3 ) ;
F_37 ( V_66 , V_43 , V_185 ) ;
F_101 ( V_66 , V_172 ,
( int ) ( ( V_207 ) V_205 - ( V_207 ) V_184 ) ,
( int ) ( ( V_207 ) V_205 - ( V_207 ) V_184 +
sizeof( T_1 ) - 1 ) ) ;
return 0 ;
}
int
F_103 (
struct V_167 * V_65 ,
struct V_73 * V_66 ,
T_8 V_67 ,
int V_51 ,
struct V_76 * * V_68 )
{
struct V_77 * V_41 ;
int V_208 ;
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
ASSERT ( ! ( * V_68 ) -> V_209 ) ;
V_41 = F_19 ( * V_68 ) ;
V_208 =
V_41 -> V_198 == F_6 ( V_210 ) &&
F_105 ( F_10 ( V_41 -> V_199 ) ) &&
F_10 ( V_41 -> V_44 ) <= F_10 ( V_41 -> V_79 ) &&
F_10 ( V_41 -> V_188 ) < F_96 ( V_65 ) &&
F_10 ( V_41 -> V_202 ) < F_96 ( V_65 ) &&
F_10 ( V_41 -> V_147 ) <= F_96 ( V_65 ) &&
F_10 ( V_41 -> V_186 ) == V_67 ;
if ( F_106 ( & V_65 -> V_163 ) )
V_208 = V_208 && F_10 ( V_41 -> V_191 ) <=
F_10 ( V_41 -> V_79 ) ;
if ( F_36 ( F_107 ( ! V_208 , V_65 , V_211 ,
V_212 ) ) ) {
F_108 ( L_1 ,
V_213 , V_65 , V_41 ) ;
F_92 ( V_66 , * V_68 ) ;
return F_109 ( V_80 ) ;
}
F_32 ( * V_68 , V_214 ) ;
return 0 ;
}
int
F_91 (
struct V_167 * V_65 ,
struct V_73 * V_66 ,
T_8 V_67 ,
int V_51 ,
struct V_76 * * V_68 )
{
struct V_77 * V_41 ;
struct V_74 * V_75 ;
int error ;
ASSERT ( V_67 != V_70 ) ;
error = F_103 ( V_65 , V_66 , V_67 ,
( V_51 & V_176 ) ? V_215 : 0 ,
V_68 ) ;
if ( error )
return error ;
if ( ! * V_68 )
return 0 ;
ASSERT ( ! ( * V_68 ) -> V_209 ) ;
V_41 = F_19 ( * V_68 ) ;
V_75 = F_84 ( V_65 , V_67 ) ;
if ( ! V_75 -> V_175 ) {
V_75 -> V_78 = F_10 ( V_41 -> V_44 ) ;
V_75 -> V_192 = F_10 ( V_41 -> V_191 ) ;
V_75 -> V_170 = F_10 ( V_41 -> V_147 ) ;
V_75 -> V_171 = F_10 ( V_41 -> V_181 ) ;
V_75 -> V_216 [ V_217 ] =
F_10 ( V_41 -> V_201 [ V_217 ] ) ;
V_75 -> V_216 [ V_218 ] =
F_10 ( V_41 -> V_201 [ V_218 ] ) ;
F_110 ( & V_75 -> V_219 ) ;
V_75 -> V_220 = 0 ;
V_75 -> V_221 = V_222 ;
V_75 -> V_175 = 1 ;
}
#ifdef F_21
else if ( ! F_111 ( V_65 ) ) {
ASSERT ( V_75 -> V_78 == F_10 ( V_41 -> V_44 ) ) ;
ASSERT ( V_75 -> V_192 == F_10 ( V_41 -> V_191 ) ) ;
ASSERT ( V_75 -> V_170 == F_10 ( V_41 -> V_147 ) ) ;
ASSERT ( V_75 -> V_171 == F_10 ( V_41 -> V_181 ) ) ;
ASSERT ( V_75 -> V_216 [ V_217 ] ==
F_10 ( V_41 -> V_201 [ V_217 ] ) ) ;
ASSERT ( V_75 -> V_216 [ V_218 ] ==
F_10 ( V_41 -> V_201 [ V_218 ] ) ) ;
}
#endif
F_85 ( V_75 ) ;
return 0 ;
}
int
F_112 (
T_3 * args )
{
T_1 V_223 ;
int error ;
int V_51 ;
T_2 V_42 ;
T_6 * V_65 ;
T_8 V_224 ;
T_14 type ;
int V_225 = 0 ;
int V_226 = 0 ;
T_8 V_227 = V_228 ;
V_65 = args -> V_65 ;
type = args -> V_229 = args -> type ;
args -> V_45 = V_35 ;
V_223 = V_65 -> V_163 . V_164 ;
if ( args -> V_40 > V_223 )
args -> V_40 = V_223 ;
if ( args -> V_20 == 0 )
args -> V_20 = 1 ;
ASSERT ( F_113 ( V_65 , args -> V_230 ) < V_65 -> V_163 . V_231 ) ;
ASSERT ( F_114 ( V_65 , args -> V_230 ) < V_223 ) ;
ASSERT ( args -> V_21 <= args -> V_40 ) ;
ASSERT ( args -> V_21 <= V_223 ) ;
ASSERT ( args -> V_38 < args -> V_39 ) ;
if ( F_113 ( V_65 , args -> V_230 ) >= V_65 -> V_163 . V_231 ||
F_114 ( V_65 , args -> V_230 ) >= V_223 ||
args -> V_21 > args -> V_40 || args -> V_21 > V_223 ||
args -> V_38 >= args -> V_39 ) {
args -> V_230 = V_232 ;
F_115 ( args ) ;
return 0 ;
}
V_42 = args -> V_42 ;
switch ( type ) {
case V_83 :
case V_84 :
case V_85 :
args -> V_67 = F_113 ( V_65 , args -> V_230 ) ;
args -> V_75 = F_84 ( V_65 , args -> V_67 ) ;
args -> V_42 = 0 ;
error = F_90 ( args , 0 ) ;
args -> V_42 = V_42 ;
if ( error ) {
F_116 ( args ) ;
goto V_96;
}
if ( ! args -> V_43 ) {
F_117 ( args ) ;
break;
}
args -> V_45 = F_114 ( V_65 , args -> V_230 ) ;
if ( ( error = F_38 ( args ) ) )
goto V_96;
break;
case V_233 :
if ( ( args -> V_148 == V_234 ) &&
( V_65 -> V_235 & V_236 ) ) {
args -> V_230 = F_118 ( V_65 ,
( ( V_65 -> V_237 / V_227 ) %
V_65 -> V_163 . V_231 ) , 0 ) ;
V_225 = 1 ;
}
args -> V_45 = F_114 ( V_65 , args -> V_230 ) ;
args -> type = V_84 ;
case V_238 :
case V_239 :
case V_240 :
if ( type == V_238 ) {
args -> V_67 = V_224 = ( V_65 -> V_237 / V_227 ) %
V_65 -> V_163 . V_231 ;
args -> type = V_83 ;
V_51 = V_176 ;
} else if ( type == V_240 ) {
args -> V_67 = F_113 ( V_65 , args -> V_230 ) ;
args -> type = V_83 ;
V_224 = 0 ;
V_51 = 0 ;
} else {
if ( type == V_239 )
args -> type = V_83 ;
args -> V_67 = V_224 = F_113 ( V_65 , args -> V_230 ) ;
V_51 = V_176 ;
}
for (; ; ) {
args -> V_75 = F_84 ( V_65 , args -> V_67 ) ;
if ( V_226 ) args -> V_42 = 0 ;
error = F_90 ( args , V_51 ) ;
args -> V_42 = V_42 ;
if ( error ) {
F_116 ( args ) ;
goto V_96;
}
if ( args -> V_43 ) {
if ( ( error = F_38 ( args ) ) )
goto V_96;
break;
}
F_119 ( args ) ;
if ( args -> V_67 == V_224 &&
type == V_233 )
args -> type = V_83 ;
if ( ++ ( args -> V_67 ) == V_65 -> V_163 . V_231 ) {
if ( args -> V_241 != V_232 )
args -> V_67 = V_224 ;
else
args -> V_67 = 0 ;
}
if ( args -> V_67 == V_224 ) {
if ( V_226 == 1 ) {
args -> V_45 = V_35 ;
F_120 ( args ) ;
break;
}
if ( V_51 == 0 ) {
V_226 = 1 ;
} else {
V_51 = 0 ;
if ( type == V_233 ) {
args -> V_45 = F_114 ( V_65 ,
args -> V_230 ) ;
args -> type = V_84 ;
}
}
}
F_85 ( args -> V_75 ) ;
}
if ( V_225 || ( type == V_238 ) ) {
if ( args -> V_67 == V_224 )
V_65 -> V_237 = ( V_65 -> V_237 + 1 ) %
( V_65 -> V_163 . V_231 * V_227 ) ;
else
V_65 -> V_237 = ( args -> V_67 * V_227 + 1 ) %
( V_65 -> V_163 . V_231 * V_227 ) ;
}
break;
default:
ASSERT ( 0 ) ;
}
if ( args -> V_45 == V_35 )
args -> V_230 = V_232 ;
else {
args -> V_230 = F_118 ( V_65 , args -> V_67 , args -> V_45 ) ;
#ifdef F_21
ASSERT ( args -> V_4 >= args -> V_21 ) ;
ASSERT ( args -> V_4 <= args -> V_40 ) ;
ASSERT ( args -> V_45 % args -> V_20 == 0 ) ;
F_121 ( V_65 , F_122 ( V_65 , args -> V_230 ) ,
args -> V_4 ) ;
#endif
}
F_85 ( args -> V_75 ) ;
return 0 ;
V_96:
F_85 ( args -> V_75 ) ;
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
args . V_65 = V_66 -> V_153 ;
args . V_67 = F_113 ( args . V_65 , V_3 ) ;
if ( args . V_67 >= args . V_65 -> V_163 . V_231 )
return V_80 ;
args . V_45 = F_114 ( args . V_65 , V_3 ) ;
if ( args . V_45 >= args . V_65 -> V_163 . V_164 )
return V_80 ;
args . V_75 = F_84 ( args . V_65 , args . V_67 ) ;
ASSERT ( args . V_75 ) ;
error = F_90 ( & args , V_177 ) ;
if ( error )
goto V_96;
if ( args . V_45 + V_4 >
F_10 ( F_19 ( args . V_43 ) -> V_79 ) ) {
error = V_80 ;
goto V_96;
}
error = F_83 ( V_66 , args . V_43 , args . V_67 , args . V_45 , V_4 , 0 ) ;
if ( ! error )
F_124 ( V_66 , args . V_67 , args . V_45 , V_4 , 0 ) ;
V_96:
F_85 ( args . V_75 ) ;
return error ;
}
