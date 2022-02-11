STATIC int
F_1 (
struct V_1 * args ,
struct V_2 * V_3 ,
const unsigned char * V_4 ,
int V_5 )
{
if ( ! V_4 )
return - V_6 ;
memset ( args , 0 , sizeof( * args ) ) ;
args -> V_7 = V_3 -> V_8 -> V_9 ;
args -> V_10 = V_11 ;
args -> V_3 = V_3 ;
args -> V_5 = V_5 ;
args -> V_4 = V_4 ;
args -> V_12 = strlen ( ( const char * ) V_4 ) ;
if ( args -> V_12 >= V_13 )
return - V_14 ;
args -> V_15 = F_2 ( args -> V_4 , args -> V_12 ) ;
return 0 ;
}
int
F_3 (
struct V_2 * V_16 )
{
if ( ! F_4 ( V_16 ) ||
( V_16 -> V_17 . V_18 == V_19 &&
V_16 -> V_17 . V_20 == 0 ) )
return 0 ;
return 1 ;
}
int
F_5 (
struct V_2 * V_16 ,
const unsigned char * V_4 ,
unsigned char * V_21 ,
int * V_22 ,
int V_5 )
{
struct V_1 args ;
T_1 V_23 ;
int error ;
F_6 ( V_16 -> V_8 , V_24 ) ;
if ( F_7 ( V_16 -> V_8 ) )
return - V_25 ;
error = F_1 ( & args , V_16 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_21 = V_21 ;
args . V_26 = * V_22 ;
args . V_27 = V_28 ;
V_23 = F_8 ( V_16 ) ;
if ( ! F_3 ( V_16 ) )
error = - V_29 ;
else if ( V_16 -> V_17 . V_18 == V_30 )
error = F_9 ( & args ) ;
else if ( F_10 ( V_16 , V_11 ) )
error = F_11 ( & args ) ;
else
error = F_12 ( & args ) ;
F_13 ( V_16 , V_23 ) ;
* V_22 = args . V_26 ;
return error == - V_31 ? 0 : error ;
}
STATIC int
F_14 (
struct V_1 * args ,
int * V_32 )
{
struct V_33 * V_34 = args -> V_3 -> V_8 ;
int V_35 ;
int V_36 ;
V_35 = F_15 ( args , V_32 ) ;
V_36 = F_16 ( V_34 , V_11 ) ;
if ( * V_32 ) {
if ( V_35 > ( args -> V_7 -> V_37 / 2 ) ) {
V_36 *= 2 ;
}
} else {
T_1 V_38 = F_17 ( V_34 , args -> V_26 ) ;
V_36 += V_38 ;
V_36 += F_18 ( V_34 , V_38 , V_11 ) ;
}
return V_36 ;
}
int
F_19 (
struct V_2 * V_3 ,
const unsigned char * V_4 ,
unsigned char * V_21 ,
int V_26 ,
int V_5 )
{
struct V_33 * V_34 = V_3 -> V_8 ;
struct V_1 args ;
struct V_39 V_40 ;
struct V_41 V_42 ;
T_2 V_43 ;
int V_44 = ( V_5 & V_45 ) != 0 ;
int error , V_46 , V_32 ;
F_6 ( V_34 , V_47 ) ;
if ( F_7 ( V_3 -> V_8 ) )
return - V_25 ;
error = F_1 ( & args , V_3 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_21 = V_21 ;
args . V_26 = V_26 ;
args . V_43 = & V_43 ;
args . V_40 = & V_40 ;
args . V_27 = V_48 | V_28 ;
args . V_49 = F_14 ( & args , & V_32 ) ;
error = F_20 ( V_3 , 0 ) ;
if ( error )
return error ;
if ( F_4 ( V_3 ) == 0 ) {
int V_50 = sizeof( V_51 ) +
F_21 ( args . V_12 , V_26 ) ;
error = F_22 ( V_3 , V_50 , V_44 ) ;
if ( error )
return error ;
}
V_42 . V_52 = F_23 ( V_34 ) -> V_53 . V_52 +
F_23 ( V_34 ) -> V_54 . V_52 * args . V_49 ;
V_42 . V_55 = V_56 ;
V_42 . V_57 = V_58 ;
error = F_24 ( V_34 , & V_42 , args . V_49 , 0 ,
V_44 ? V_59 : 0 , & args . V_60 ) ;
if ( error )
return error ;
F_25 ( V_3 , V_61 ) ;
error = F_26 ( args . V_60 , V_3 , args . V_49 , 0 ,
V_44 ? V_62 | V_63 :
V_62 ) ;
if ( error ) {
F_13 ( V_3 , V_61 ) ;
F_27 ( args . V_60 ) ;
return error ;
}
F_28 ( args . V_60 , V_3 , 0 ) ;
if ( V_3 -> V_17 . V_18 == V_30 ||
( V_3 -> V_17 . V_18 == V_19 &&
V_3 -> V_17 . V_20 == 0 ) ) {
if ( V_3 -> V_17 . V_18 == V_19 )
F_29 ( & args ) ;
error = F_30 ( & args ) ;
if ( error != - V_64 ) {
ASSERT ( args . V_60 != NULL ) ;
if ( V_34 -> V_65 & V_66 )
F_31 ( args . V_60 ) ;
if ( ! error && ( V_5 & V_67 ) == 0 ) {
F_32 ( args . V_60 , V_3 ,
V_68 ) ;
}
V_46 = F_33 ( args . V_60 ) ;
F_13 ( V_3 , V_61 ) ;
return error ? error : V_46 ;
}
F_34 ( args . V_40 , args . V_43 ) ;
error = F_35 ( & args ) ;
if ( ! error )
error = F_36 ( & args . V_60 , args . V_40 , V_3 ) ;
if ( error ) {
args . V_60 = NULL ;
F_37 ( & V_40 ) ;
goto V_69;
}
error = F_38 ( & args . V_60 , V_3 ) ;
if ( error )
goto V_69;
}
if ( F_10 ( V_3 , V_11 ) )
error = F_39 ( & args ) ;
else
error = F_40 ( & args ) ;
if ( error )
goto V_69;
if ( V_34 -> V_65 & V_66 )
F_31 ( args . V_60 ) ;
if ( ( V_5 & V_67 ) == 0 )
F_32 ( args . V_60 , V_3 , V_68 ) ;
F_41 ( args . V_60 , V_3 , V_70 ) ;
error = F_33 ( args . V_60 ) ;
F_13 ( V_3 , V_61 ) ;
return error ;
V_69:
if ( args . V_60 )
F_27 ( args . V_60 ) ;
F_13 ( V_3 , V_61 ) ;
return error ;
}
int
F_42 (
struct V_2 * V_3 ,
const unsigned char * V_4 ,
int V_5 )
{
struct V_33 * V_34 = V_3 -> V_8 ;
struct V_1 args ;
struct V_39 V_40 ;
T_2 V_43 ;
int error ;
F_6 ( V_34 , V_71 ) ;
if ( F_7 ( V_3 -> V_8 ) )
return - V_25 ;
error = F_1 ( & args , V_3 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_43 = & V_43 ;
args . V_40 = & V_40 ;
args . V_27 = V_28 ;
error = F_20 ( V_3 , 0 ) ;
if ( error )
return error ;
error = F_24 ( V_34 , & F_23 ( V_34 ) -> V_72 ,
F_43 ( V_34 ) , 0 ,
( V_5 & V_45 ) ? V_59 : 0 ,
& args . V_60 ) ;
if ( error )
return error ;
F_25 ( V_3 , V_61 ) ;
F_28 ( args . V_60 , V_3 , 0 ) ;
if ( ! F_3 ( V_3 ) ) {
error = - V_29 ;
} else if ( V_3 -> V_17 . V_18 == V_30 ) {
ASSERT ( V_3 -> V_73 -> V_74 & V_75 ) ;
error = F_44 ( & args ) ;
} else if ( F_10 ( V_3 , V_11 ) ) {
error = F_45 ( & args ) ;
} else {
error = F_46 ( & args ) ;
}
if ( error )
goto V_69;
if ( V_34 -> V_65 & V_66 )
F_31 ( args . V_60 ) ;
if ( ( V_5 & V_67 ) == 0 )
F_32 ( args . V_60 , V_3 , V_68 ) ;
F_41 ( args . V_60 , V_3 , V_70 ) ;
error = F_33 ( args . V_60 ) ;
F_13 ( V_3 , V_61 ) ;
return error ;
V_69:
if ( args . V_60 )
F_27 ( args . V_60 ) ;
F_13 ( V_3 , V_61 ) ;
return error ;
}
STATIC int
F_30 ( T_3 * args )
{
int V_76 , V_77 , V_78 ;
F_47 ( args ) ;
V_78 = F_48 ( args ) ;
if ( ( args -> V_5 & V_79 ) && ( V_78 == - V_29 ) ) {
return V_78 ;
} else if ( V_78 == - V_31 ) {
if ( args -> V_5 & V_80 )
return V_78 ;
V_78 = F_44 ( args ) ;
ASSERT ( V_78 == 0 ) ;
}
if ( args -> V_12 >= V_81 ||
args -> V_26 >= V_81 )
return - V_64 ;
V_76 = F_49 ( args -> V_3 ) ;
V_76 += F_21 ( args -> V_12 , args -> V_26 ) ;
V_77 = F_50 ( args -> V_3 , V_76 ) ;
if ( ! V_77 )
return - V_64 ;
F_51 ( args , V_77 ) ;
return 0 ;
}
STATIC int
F_39 ( T_3 * args )
{
T_4 * V_3 ;
struct V_82 * V_83 ;
int V_78 , error , V_77 ;
F_52 ( args ) ;
V_3 = args -> V_3 ;
args -> V_84 = 0 ;
error = F_53 ( args -> V_60 , args -> V_3 , args -> V_84 , - 1 , & V_83 ) ;
if ( error )
return error ;
V_78 = F_54 ( V_83 , args ) ;
if ( ( args -> V_5 & V_79 ) && ( V_78 == - V_29 ) ) {
F_55 ( args -> V_60 , V_83 ) ;
return V_78 ;
} else if ( V_78 == - V_31 ) {
if ( args -> V_5 & V_80 ) {
F_55 ( args -> V_60 , V_83 ) ;
return V_78 ;
}
F_56 ( args ) ;
args -> V_27 |= V_85 ;
args -> V_86 = args -> V_84 ;
args -> V_87 = args -> V_88 ;
args -> V_89 = args -> V_90 ;
args -> V_91 = args -> V_92 ;
args -> V_93 = args -> V_94 ;
args -> V_90 = 0 ;
args -> V_92 = 0 ;
args -> V_94 = 0 ;
}
V_78 = F_57 ( V_83 , args ) ;
if ( V_78 == - V_64 ) {
F_34 ( args -> V_40 , args -> V_43 ) ;
error = F_58 ( args ) ;
if ( ! error )
error = F_36 ( & args -> V_60 , args -> V_40 , V_3 ) ;
if ( error ) {
args -> V_60 = NULL ;
F_37 ( args -> V_40 ) ;
return error ;
}
error = F_38 ( & args -> V_60 , V_3 ) ;
if ( error )
return error ;
error = F_40 ( args ) ;
return error ;
}
error = F_38 ( & args -> V_60 , V_3 ) ;
if ( error )
return error ;
if ( args -> V_90 > 0 ) {
error = F_59 ( args ) ;
if ( error )
return error ;
}
if ( args -> V_27 & V_85 ) {
error = F_60 ( args ) ;
if ( error )
return error ;
args -> V_88 = args -> V_87 ;
args -> V_84 = args -> V_86 ;
args -> V_90 = args -> V_89 ;
args -> V_92 = args -> V_91 ;
args -> V_94 = args -> V_93 ;
if ( args -> V_90 ) {
error = F_61 ( args ) ;
if ( error )
return error ;
}
error = F_53 ( args -> V_60 , args -> V_3 , args -> V_84 ,
- 1 , & V_83 ) ;
if ( error )
return error ;
F_62 ( V_83 , args ) ;
if ( ( V_77 = F_63 ( V_83 , V_3 ) ) ) {
F_34 ( args -> V_40 , args -> V_43 ) ;
error = F_64 ( V_83 , args , V_77 ) ;
if ( ! error )
error = F_36 ( & args -> V_60 ,
args -> V_40 , V_3 ) ;
if ( error ) {
args -> V_60 = NULL ;
F_37 ( args -> V_40 ) ;
return error ;
}
}
error = F_38 ( & args -> V_60 , V_3 ) ;
} else if ( args -> V_90 > 0 ) {
error = F_65 ( args ) ;
}
return error ;
}
STATIC int
F_45 ( T_3 * args )
{
T_4 * V_3 ;
struct V_82 * V_83 ;
int error , V_77 ;
F_66 ( args ) ;
V_3 = args -> V_3 ;
args -> V_84 = 0 ;
error = F_53 ( args -> V_60 , args -> V_3 , args -> V_84 , - 1 , & V_83 ) ;
if ( error )
return error ;
error = F_54 ( V_83 , args ) ;
if ( error == - V_29 ) {
F_55 ( args -> V_60 , V_83 ) ;
return error ;
}
F_62 ( V_83 , args ) ;
if ( ( V_77 = F_63 ( V_83 , V_3 ) ) ) {
F_34 ( args -> V_40 , args -> V_43 ) ;
error = F_64 ( V_83 , args , V_77 ) ;
if ( ! error )
error = F_36 ( & args -> V_60 , args -> V_40 , V_3 ) ;
if ( error ) {
args -> V_60 = NULL ;
F_37 ( args -> V_40 ) ;
return error ;
}
}
return 0 ;
}
STATIC int
F_11 ( T_3 * args )
{
struct V_82 * V_83 ;
int error ;
F_67 ( args ) ;
args -> V_84 = 0 ;
error = F_53 ( args -> V_60 , args -> V_3 , args -> V_84 , - 1 , & V_83 ) ;
if ( error )
return error ;
error = F_54 ( V_83 , args ) ;
if ( error != - V_31 ) {
F_55 ( args -> V_60 , V_83 ) ;
return error ;
}
error = F_68 ( V_83 , args ) ;
F_55 ( args -> V_60 , V_83 ) ;
if ( ! error && ( args -> V_90 > 0 ) && ! ( args -> V_5 & V_95 ) ) {
error = F_69 ( args ) ;
}
return error ;
}
STATIC int
F_40 ( T_3 * args )
{
T_5 * V_96 ;
T_6 * V_97 ;
T_4 * V_3 ;
T_7 * V_34 ;
int V_78 , error ;
F_70 ( args ) ;
V_3 = args -> V_3 ;
V_34 = V_3 -> V_8 ;
V_98:
V_96 = F_71 () ;
V_96 -> args = args ;
V_96 -> V_34 = V_34 ;
error = F_72 ( V_96 , & V_78 ) ;
if ( error )
goto V_69;
V_97 = & V_96 -> V_99 . V_97 [ V_96 -> V_99 . V_100 - 1 ] ;
ASSERT ( V_97 -> V_101 == V_102 ) ;
if ( ( args -> V_5 & V_79 ) && ( V_78 == - V_29 ) ) {
goto V_69;
} else if ( V_78 == - V_31 ) {
if ( args -> V_5 & V_80 )
goto V_69;
F_73 ( args ) ;
args -> V_27 |= V_85 ;
args -> V_86 = args -> V_84 ;
args -> V_87 = args -> V_88 ;
args -> V_89 = args -> V_90 ;
args -> V_91 = args -> V_92 ;
args -> V_93 = args -> V_94 ;
args -> V_90 = 0 ;
args -> V_92 = 0 ;
args -> V_94 = 0 ;
}
V_78 = F_57 ( V_97 -> V_83 , V_96 -> args ) ;
if ( V_78 == - V_64 ) {
if ( V_96 -> V_99 . V_100 == 1 ) {
F_74 ( V_96 ) ;
V_96 = NULL ;
F_34 ( args -> V_40 , args -> V_43 ) ;
error = F_58 ( args ) ;
if ( ! error )
error = F_36 ( & args -> V_60 ,
args -> V_40 , V_3 ) ;
if ( error ) {
args -> V_60 = NULL ;
F_37 ( args -> V_40 ) ;
goto V_69;
}
error = F_38 ( & args -> V_60 , V_3 ) ;
if ( error )
goto V_69;
goto V_98;
}
F_34 ( args -> V_40 , args -> V_43 ) ;
error = F_75 ( V_96 ) ;
if ( ! error )
error = F_36 ( & args -> V_60 , args -> V_40 , V_3 ) ;
if ( error ) {
args -> V_60 = NULL ;
F_37 ( args -> V_40 ) ;
goto V_69;
}
} else {
F_76 ( V_96 , & V_96 -> V_99 ) ;
}
F_74 ( V_96 ) ;
V_96 = NULL ;
error = F_38 ( & args -> V_60 , V_3 ) ;
if ( error )
goto V_69;
if ( args -> V_90 > 0 ) {
error = F_59 ( args ) ;
if ( error )
return error ;
}
if ( args -> V_27 & V_85 ) {
error = F_60 ( args ) ;
if ( error )
goto V_69;
args -> V_88 = args -> V_87 ;
args -> V_84 = args -> V_86 ;
args -> V_90 = args -> V_89 ;
args -> V_92 = args -> V_91 ;
args -> V_94 = args -> V_93 ;
if ( args -> V_90 ) {
error = F_61 ( args ) ;
if ( error )
return error ;
}
args -> V_5 |= V_103 ;
V_96 = F_71 () ;
V_96 -> args = args ;
V_96 -> V_34 = V_34 ;
V_96 -> V_104 = 0 ;
error = F_72 ( V_96 , & V_78 ) ;
if ( error )
goto V_69;
V_97 = & V_96 -> V_99 . V_97 [ V_96 -> V_99 . V_100 - 1 ] ;
ASSERT ( V_97 -> V_101 == V_102 ) ;
error = F_62 ( V_97 -> V_83 , args ) ;
F_76 ( V_96 , & V_96 -> V_99 ) ;
if ( V_78 && ( V_96 -> V_99 . V_100 > 1 ) ) {
F_34 ( args -> V_40 , args -> V_43 ) ;
error = F_77 ( V_96 ) ;
if ( ! error )
error = F_36 ( & args -> V_60 ,
args -> V_40 , V_3 ) ;
if ( error ) {
args -> V_60 = NULL ;
F_37 ( args -> V_40 ) ;
goto V_69;
}
}
error = F_38 ( & args -> V_60 , V_3 ) ;
if ( error )
goto V_69;
} else if ( args -> V_90 > 0 ) {
error = F_65 ( args ) ;
if ( error )
goto V_69;
}
V_78 = error = 0 ;
V_69:
if ( V_96 )
F_74 ( V_96 ) ;
if ( error )
return error ;
return V_78 ;
}
STATIC int
F_46 ( T_3 * args )
{
T_5 * V_96 ;
T_6 * V_97 ;
T_4 * V_3 ;
struct V_82 * V_83 ;
int V_78 , error , V_77 ;
F_78 ( args ) ;
V_3 = args -> V_3 ;
V_96 = F_71 () ;
V_96 -> args = args ;
V_96 -> V_34 = V_3 -> V_8 ;
error = F_72 ( V_96 , & V_78 ) ;
if ( error || ( V_78 != - V_31 ) ) {
if ( error == 0 )
error = V_78 ;
goto V_69;
}
V_97 = & V_96 -> V_99 . V_97 [ V_96 -> V_99 . V_100 - 1 ] ;
ASSERT ( V_97 -> V_83 != NULL ) ;
ASSERT ( V_97 -> V_101 == V_102 ) ;
if ( args -> V_90 > 0 ) {
error = F_79 ( V_96 ) ;
if ( error )
goto V_69;
error = F_80 ( args ) ;
if ( error )
goto V_69;
error = F_61 ( args ) ;
if ( error )
goto V_69;
error = F_81 ( V_96 ) ;
if ( error )
goto V_69;
}
V_97 = & V_96 -> V_99 . V_97 [ V_96 -> V_99 . V_100 - 1 ] ;
ASSERT ( V_97 -> V_101 == V_102 ) ;
V_78 = F_62 ( V_97 -> V_83 , args ) ;
F_76 ( V_96 , & V_96 -> V_99 ) ;
if ( V_78 && ( V_96 -> V_99 . V_100 > 1 ) ) {
F_34 ( args -> V_40 , args -> V_43 ) ;
error = F_77 ( V_96 ) ;
if ( ! error )
error = F_36 ( & args -> V_60 , args -> V_40 , V_3 ) ;
if ( error ) {
args -> V_60 = NULL ;
F_37 ( args -> V_40 ) ;
goto V_69;
}
error = F_38 ( & args -> V_60 , V_3 ) ;
if ( error )
goto V_69;
}
if ( F_10 ( V_3 , V_11 ) ) {
ASSERT ( V_96 -> V_99 . V_100 == 1 ) ;
ASSERT ( V_96 -> V_99 . V_97 [ 0 ] . V_83 ) ;
V_96 -> V_99 . V_97 [ 0 ] . V_83 = NULL ;
error = F_53 ( args -> V_60 , args -> V_3 , 0 , - 1 , & V_83 ) ;
if ( error )
goto V_69;
if ( ( V_77 = F_63 ( V_83 , V_3 ) ) ) {
F_34 ( args -> V_40 , args -> V_43 ) ;
error = F_64 ( V_83 , args , V_77 ) ;
if ( ! error )
error = F_36 ( & args -> V_60 ,
args -> V_40 , V_3 ) ;
if ( error ) {
args -> V_60 = NULL ;
F_37 ( args -> V_40 ) ;
goto V_69;
}
} else
F_55 ( args -> V_60 , V_83 ) ;
}
error = 0 ;
V_69:
F_74 ( V_96 ) ;
return error ;
}
STATIC int
F_79 ( T_5 * V_96 )
{
T_8 * V_99 ;
T_6 * V_97 ;
int V_105 ;
F_82 ( V_96 -> args ) ;
V_99 = & V_96 -> V_99 ;
ASSERT ( ( V_99 -> V_100 >= 0 ) && ( V_99 -> V_100 < V_106 ) ) ;
for ( V_97 = V_99 -> V_97 , V_105 = 0 ; V_105 < V_99 -> V_100 ; V_97 ++ , V_105 ++ ) {
if ( V_97 -> V_83 ) {
V_97 -> V_107 = F_83 ( V_97 -> V_83 ) ;
V_97 -> V_83 = NULL ;
} else {
V_97 -> V_107 = 0 ;
}
}
V_99 = & V_96 -> V_108 ;
ASSERT ( ( V_99 -> V_100 >= 0 ) && ( V_99 -> V_100 < V_106 ) ) ;
for ( V_97 = V_99 -> V_97 , V_105 = 0 ; V_105 < V_99 -> V_100 ; V_97 ++ , V_105 ++ ) {
if ( V_97 -> V_83 ) {
V_97 -> V_107 = F_83 ( V_97 -> V_83 ) ;
V_97 -> V_83 = NULL ;
} else {
V_97 -> V_107 = 0 ;
}
}
return 0 ;
}
STATIC int
F_81 ( T_5 * V_96 )
{
T_8 * V_99 ;
T_6 * V_97 ;
int V_105 , error ;
F_84 ( V_96 -> args ) ;
V_99 = & V_96 -> V_99 ;
ASSERT ( ( V_99 -> V_100 >= 0 ) && ( V_99 -> V_100 < V_106 ) ) ;
for ( V_97 = V_99 -> V_97 , V_105 = 0 ; V_105 < V_99 -> V_100 ; V_97 ++ , V_105 ++ ) {
if ( V_97 -> V_107 ) {
error = F_85 ( V_96 -> args -> V_60 ,
V_96 -> args -> V_3 ,
V_97 -> V_84 , V_97 -> V_107 ,
& V_97 -> V_83 , V_11 ) ;
if ( error )
return error ;
} else {
V_97 -> V_83 = NULL ;
}
}
V_99 = & V_96 -> V_108 ;
ASSERT ( ( V_99 -> V_100 >= 0 ) && ( V_99 -> V_100 < V_106 ) ) ;
for ( V_97 = V_99 -> V_97 , V_105 = 0 ; V_105 < V_99 -> V_100 ; V_97 ++ , V_105 ++ ) {
if ( V_97 -> V_107 ) {
error = F_85 ( V_96 -> args -> V_60 ,
V_96 -> args -> V_3 ,
V_97 -> V_84 , V_97 -> V_107 ,
& V_97 -> V_83 , V_11 ) ;
if ( error )
return error ;
} else {
V_97 -> V_83 = NULL ;
}
}
return 0 ;
}
STATIC int
F_12 ( T_3 * args )
{
T_5 * V_96 ;
T_6 * V_97 ;
int error , V_78 ;
int V_109 ;
F_86 ( args ) ;
V_96 = F_71 () ;
V_96 -> args = args ;
V_96 -> V_34 = args -> V_3 -> V_8 ;
error = F_72 ( V_96 , & V_78 ) ;
if ( error ) {
V_78 = error ;
} else if ( V_78 == - V_31 ) {
V_97 = & V_96 -> V_99 . V_97 [ V_96 -> V_99 . V_100 - 1 ] ;
ASSERT ( V_97 -> V_83 != NULL ) ;
ASSERT ( V_97 -> V_101 == V_102 ) ;
V_78 = F_68 ( V_97 -> V_83 , args ) ;
if ( ! V_78 && ( args -> V_90 > 0 )
&& ! ( args -> V_5 & V_95 ) ) {
V_78 = F_69 ( args ) ;
}
}
for ( V_109 = 0 ; V_109 < V_96 -> V_99 . V_100 ; V_109 ++ ) {
F_55 ( args -> V_60 , V_96 -> V_99 . V_97 [ V_109 ] . V_83 ) ;
V_96 -> V_99 . V_97 [ V_109 ] . V_83 = NULL ;
}
F_74 ( V_96 ) ;
return V_78 ;
}
