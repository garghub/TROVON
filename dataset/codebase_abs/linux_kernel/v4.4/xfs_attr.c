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
if ( ! F_3 ( V_16 ) )
return - V_26 ;
error = F_1 ( & args , V_16 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_21 = V_21 ;
args . V_27 = * V_22 ;
args . V_28 = V_29 ;
V_23 = F_8 ( V_16 ) ;
if ( ! F_3 ( V_16 ) )
error = - V_26 ;
else if ( V_16 -> V_17 . V_18 == V_30 )
error = F_9 ( & args ) ;
else if ( F_10 ( V_16 , V_11 ) )
error = F_11 ( & args ) ;
else
error = F_12 ( & args ) ;
F_13 ( V_16 , V_23 ) ;
* V_22 = args . V_27 ;
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
T_1 V_38 = F_17 ( V_34 , args -> V_27 ) ;
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
int V_27 ,
int V_5 )
{
struct V_33 * V_34 = V_3 -> V_8 ;
struct V_1 args ;
struct V_39 V_40 ;
struct V_41 V_42 ;
T_2 V_43 ;
int V_44 = ( V_5 & V_45 ) != 0 ;
int error , V_46 , V_47 , V_32 ;
F_6 ( V_34 , V_48 ) ;
if ( F_7 ( V_3 -> V_8 ) )
return - V_25 ;
error = F_1 ( & args , V_3 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_21 = V_21 ;
args . V_27 = V_27 ;
args . V_43 = & V_43 ;
args . V_40 = & V_40 ;
args . V_28 = V_49 | V_29 ;
args . V_50 = F_14 ( & args , & V_32 ) ;
error = F_20 ( V_3 , 0 ) ;
if ( error )
return error ;
if ( F_4 ( V_3 ) == 0 ) {
int V_51 = sizeof( V_52 ) +
F_21 ( args . V_12 , V_27 ) ;
error = F_22 ( V_3 , V_51 , V_44 ) ;
if ( error )
return error ;
}
args . V_53 = F_23 ( V_34 , V_54 ) ;
if ( V_44 )
args . V_53 -> V_55 |= V_56 ;
V_42 . V_57 = F_24 ( V_34 ) -> V_58 . V_57 +
F_24 ( V_34 ) -> V_59 . V_57 * args . V_50 ;
V_42 . V_60 = V_61 ;
V_42 . V_62 = V_63 ;
error = F_25 ( args . V_53 , & V_42 , args . V_50 , 0 ) ;
if ( error ) {
F_26 ( args . V_53 ) ;
return error ;
}
F_27 ( V_3 , V_64 ) ;
error = F_28 ( args . V_53 , V_3 , args . V_50 , 0 ,
V_44 ? V_65 | V_66 :
V_65 ) ;
if ( error ) {
F_13 ( V_3 , V_64 ) ;
F_26 ( args . V_53 ) ;
return error ;
}
F_29 ( args . V_53 , V_3 , 0 ) ;
if ( V_3 -> V_17 . V_18 == V_30 ||
( V_3 -> V_17 . V_18 == V_19 &&
V_3 -> V_17 . V_20 == 0 ) ) {
if ( V_3 -> V_17 . V_18 == V_19 )
F_30 ( & args ) ;
error = F_31 ( & args ) ;
if ( error != - V_67 ) {
ASSERT ( args . V_53 != NULL ) ;
if ( V_34 -> V_68 & V_69 )
F_32 ( args . V_53 ) ;
if ( ! error && ( V_5 & V_70 ) == 0 ) {
F_33 ( args . V_53 , V_3 ,
V_71 ) ;
}
V_46 = F_34 ( args . V_53 ) ;
F_13 ( V_3 , V_64 ) ;
return error ? error : V_46 ;
}
F_35 ( args . V_40 , args . V_43 ) ;
error = F_36 ( & args ) ;
if ( ! error ) {
error = F_37 ( & args . V_53 , args . V_40 ,
& V_47 ) ;
}
if ( error ) {
ASSERT ( V_47 ) ;
args . V_53 = NULL ;
F_38 ( & V_40 ) ;
goto V_72;
}
if ( V_47 )
F_29 ( args . V_53 , V_3 , 0 ) ;
error = F_39 ( & args . V_53 , V_3 ) ;
if ( error )
goto V_72;
}
if ( F_10 ( V_3 , V_11 ) )
error = F_40 ( & args ) ;
else
error = F_41 ( & args ) ;
if ( error )
goto V_72;
if ( V_34 -> V_68 & V_69 )
F_32 ( args . V_53 ) ;
if ( ( V_5 & V_70 ) == 0 )
F_33 ( args . V_53 , V_3 , V_71 ) ;
F_42 ( args . V_53 , V_3 , V_73 ) ;
error = F_34 ( args . V_53 ) ;
F_13 ( V_3 , V_64 ) ;
return error ;
V_72:
if ( args . V_53 )
F_26 ( args . V_53 ) ;
F_13 ( V_3 , V_64 ) ;
return error ;
}
int
F_43 (
struct V_2 * V_3 ,
const unsigned char * V_4 ,
int V_5 )
{
struct V_33 * V_34 = V_3 -> V_8 ;
struct V_1 args ;
struct V_39 V_40 ;
T_2 V_43 ;
int error ;
F_6 ( V_34 , V_74 ) ;
if ( F_7 ( V_3 -> V_8 ) )
return - V_25 ;
if ( ! F_3 ( V_3 ) )
return - V_26 ;
error = F_1 ( & args , V_3 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_43 = & V_43 ;
args . V_40 = & V_40 ;
args . V_28 = V_29 ;
error = F_20 ( V_3 , 0 ) ;
if ( error )
return error ;
args . V_53 = F_23 ( V_34 , V_75 ) ;
if ( V_5 & V_45 )
args . V_53 -> V_55 |= V_56 ;
error = F_25 ( args . V_53 , & F_24 ( V_34 ) -> V_76 ,
F_44 ( V_34 ) , 0 ) ;
if ( error ) {
F_26 ( args . V_53 ) ;
return error ;
}
F_27 ( V_3 , V_64 ) ;
F_29 ( args . V_53 , V_3 , 0 ) ;
if ( ! F_3 ( V_3 ) ) {
error = - V_26 ;
} else if ( V_3 -> V_17 . V_18 == V_30 ) {
ASSERT ( V_3 -> V_77 -> V_78 & V_79 ) ;
error = F_45 ( & args ) ;
} else if ( F_10 ( V_3 , V_11 ) ) {
error = F_46 ( & args ) ;
} else {
error = F_47 ( & args ) ;
}
if ( error )
goto V_72;
if ( V_34 -> V_68 & V_69 )
F_32 ( args . V_53 ) ;
if ( ( V_5 & V_70 ) == 0 )
F_33 ( args . V_53 , V_3 , V_71 ) ;
F_42 ( args . V_53 , V_3 , V_73 ) ;
error = F_34 ( args . V_53 ) ;
F_13 ( V_3 , V_64 ) ;
return error ;
V_72:
if ( args . V_53 )
F_26 ( args . V_53 ) ;
F_13 ( V_3 , V_64 ) ;
return error ;
}
STATIC int
F_31 ( T_3 * args )
{
int V_80 , V_81 , V_82 ;
F_48 ( args ) ;
V_82 = F_49 ( args ) ;
if ( ( args -> V_5 & V_83 ) && ( V_82 == - V_26 ) ) {
return V_82 ;
} else if ( V_82 == - V_31 ) {
if ( args -> V_5 & V_84 )
return V_82 ;
V_82 = F_45 ( args ) ;
ASSERT ( V_82 == 0 ) ;
}
if ( args -> V_12 >= V_85 ||
args -> V_27 >= V_85 )
return - V_67 ;
V_80 = F_50 ( args -> V_3 ) ;
V_80 += F_21 ( args -> V_12 , args -> V_27 ) ;
V_81 = F_51 ( args -> V_3 , V_80 ) ;
if ( ! V_81 )
return - V_67 ;
F_52 ( args , V_81 ) ;
return 0 ;
}
STATIC int
F_40 ( T_3 * args )
{
T_4 * V_3 ;
struct V_86 * V_87 ;
int V_82 , error , V_47 , V_81 ;
F_53 ( args ) ;
V_3 = args -> V_3 ;
args -> V_88 = 0 ;
error = F_54 ( args -> V_53 , args -> V_3 , args -> V_88 , - 1 , & V_87 ) ;
if ( error )
return error ;
V_82 = F_55 ( V_87 , args ) ;
if ( ( args -> V_5 & V_83 ) && ( V_82 == - V_26 ) ) {
F_56 ( args -> V_53 , V_87 ) ;
return V_82 ;
} else if ( V_82 == - V_31 ) {
if ( args -> V_5 & V_84 ) {
F_56 ( args -> V_53 , V_87 ) ;
return V_82 ;
}
F_57 ( args ) ;
args -> V_28 |= V_89 ;
args -> V_90 = args -> V_88 ;
args -> V_91 = args -> V_92 ;
args -> V_93 = args -> V_94 ;
args -> V_95 = args -> V_96 ;
args -> V_97 = args -> V_98 ;
args -> V_94 = 0 ;
args -> V_96 = 0 ;
args -> V_98 = 0 ;
}
V_82 = F_58 ( V_87 , args ) ;
if ( V_82 == - V_67 ) {
F_35 ( args -> V_40 , args -> V_43 ) ;
error = F_59 ( args ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_40 ,
& V_47 ) ;
}
if ( error ) {
ASSERT ( V_47 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
return error ;
}
if ( V_47 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
error = F_39 ( & args -> V_53 , V_3 ) ;
if ( error )
return error ;
error = F_41 ( args ) ;
return error ;
}
error = F_39 ( & args -> V_53 , V_3 ) ;
if ( error )
return error ;
if ( args -> V_94 > 0 ) {
error = F_60 ( args ) ;
if ( error )
return error ;
}
if ( args -> V_28 & V_89 ) {
error = F_61 ( args ) ;
if ( error )
return error ;
args -> V_92 = args -> V_91 ;
args -> V_88 = args -> V_90 ;
args -> V_94 = args -> V_93 ;
args -> V_96 = args -> V_95 ;
args -> V_98 = args -> V_97 ;
if ( args -> V_94 ) {
error = F_62 ( args ) ;
if ( error )
return error ;
}
error = F_54 ( args -> V_53 , args -> V_3 , args -> V_88 ,
- 1 , & V_87 ) ;
if ( error )
return error ;
F_63 ( V_87 , args ) ;
if ( ( V_81 = F_64 ( V_87 , V_3 ) ) ) {
F_35 ( args -> V_40 , args -> V_43 ) ;
error = F_65 ( V_87 , args , V_81 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_40 ,
& V_47 ) ;
}
if ( error ) {
ASSERT ( V_47 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
return error ;
}
if ( V_47 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
}
error = F_39 ( & args -> V_53 , V_3 ) ;
} else if ( args -> V_94 > 0 ) {
error = F_66 ( args ) ;
}
return error ;
}
STATIC int
F_46 ( T_3 * args )
{
T_4 * V_3 ;
struct V_86 * V_87 ;
int error , V_47 , V_81 ;
F_67 ( args ) ;
V_3 = args -> V_3 ;
args -> V_88 = 0 ;
error = F_54 ( args -> V_53 , args -> V_3 , args -> V_88 , - 1 , & V_87 ) ;
if ( error )
return error ;
error = F_55 ( V_87 , args ) ;
if ( error == - V_26 ) {
F_56 ( args -> V_53 , V_87 ) ;
return error ;
}
F_63 ( V_87 , args ) ;
if ( ( V_81 = F_64 ( V_87 , V_3 ) ) ) {
F_35 ( args -> V_40 , args -> V_43 ) ;
error = F_65 ( V_87 , args , V_81 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_40 ,
& V_47 ) ;
}
if ( error ) {
ASSERT ( V_47 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
return error ;
}
if ( V_47 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
}
return 0 ;
}
STATIC int
F_11 ( T_3 * args )
{
struct V_86 * V_87 ;
int error ;
F_68 ( args ) ;
args -> V_88 = 0 ;
error = F_54 ( args -> V_53 , args -> V_3 , args -> V_88 , - 1 , & V_87 ) ;
if ( error )
return error ;
error = F_55 ( V_87 , args ) ;
if ( error != - V_31 ) {
F_56 ( args -> V_53 , V_87 ) ;
return error ;
}
error = F_69 ( V_87 , args ) ;
F_56 ( args -> V_53 , V_87 ) ;
if ( ! error && ( args -> V_94 > 0 ) && ! ( args -> V_5 & V_99 ) ) {
error = F_70 ( args ) ;
}
return error ;
}
STATIC int
F_41 ( T_3 * args )
{
T_5 * V_100 ;
T_6 * V_101 ;
T_4 * V_3 ;
T_7 * V_34 ;
int V_47 , V_82 , error ;
F_71 ( args ) ;
V_3 = args -> V_3 ;
V_34 = V_3 -> V_8 ;
V_102:
V_100 = F_72 () ;
V_100 -> args = args ;
V_100 -> V_34 = V_34 ;
error = F_73 ( V_100 , & V_82 ) ;
if ( error )
goto V_72;
V_101 = & V_100 -> V_103 . V_101 [ V_100 -> V_103 . V_104 - 1 ] ;
ASSERT ( V_101 -> V_105 == V_106 ) ;
if ( ( args -> V_5 & V_83 ) && ( V_82 == - V_26 ) ) {
goto V_72;
} else if ( V_82 == - V_31 ) {
if ( args -> V_5 & V_84 )
goto V_72;
F_74 ( args ) ;
args -> V_28 |= V_89 ;
args -> V_90 = args -> V_88 ;
args -> V_91 = args -> V_92 ;
args -> V_93 = args -> V_94 ;
args -> V_95 = args -> V_96 ;
args -> V_97 = args -> V_98 ;
args -> V_94 = 0 ;
args -> V_96 = 0 ;
args -> V_98 = 0 ;
}
V_82 = F_58 ( V_101 -> V_87 , V_100 -> args ) ;
if ( V_82 == - V_67 ) {
if ( V_100 -> V_103 . V_104 == 1 ) {
F_75 ( V_100 ) ;
V_100 = NULL ;
F_35 ( args -> V_40 , args -> V_43 ) ;
error = F_59 ( args ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_40 ,
& V_47 ) ;
}
if ( error ) {
ASSERT ( V_47 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_72;
}
if ( V_47 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
error = F_39 ( & args -> V_53 , V_3 ) ;
if ( error )
goto V_72;
goto V_102;
}
F_35 ( args -> V_40 , args -> V_43 ) ;
error = F_76 ( V_100 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_40 ,
& V_47 ) ;
}
if ( error ) {
ASSERT ( V_47 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_72;
}
if ( V_47 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
} else {
F_77 ( V_100 , & V_100 -> V_103 ) ;
}
F_75 ( V_100 ) ;
V_100 = NULL ;
error = F_39 ( & args -> V_53 , V_3 ) ;
if ( error )
goto V_72;
if ( args -> V_94 > 0 ) {
error = F_60 ( args ) ;
if ( error )
return error ;
}
if ( args -> V_28 & V_89 ) {
error = F_61 ( args ) ;
if ( error )
goto V_72;
args -> V_92 = args -> V_91 ;
args -> V_88 = args -> V_90 ;
args -> V_94 = args -> V_93 ;
args -> V_96 = args -> V_95 ;
args -> V_98 = args -> V_97 ;
if ( args -> V_94 ) {
error = F_62 ( args ) ;
if ( error )
return error ;
}
args -> V_5 |= V_107 ;
V_100 = F_72 () ;
V_100 -> args = args ;
V_100 -> V_34 = V_34 ;
V_100 -> V_108 = 0 ;
error = F_73 ( V_100 , & V_82 ) ;
if ( error )
goto V_72;
V_101 = & V_100 -> V_103 . V_101 [ V_100 -> V_103 . V_104 - 1 ] ;
ASSERT ( V_101 -> V_105 == V_106 ) ;
error = F_63 ( V_101 -> V_87 , args ) ;
F_77 ( V_100 , & V_100 -> V_103 ) ;
if ( V_82 && ( V_100 -> V_103 . V_104 > 1 ) ) {
F_35 ( args -> V_40 , args -> V_43 ) ;
error = F_78 ( V_100 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_40 ,
& V_47 ) ;
}
if ( error ) {
ASSERT ( V_47 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_72;
}
if ( V_47 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
}
error = F_39 ( & args -> V_53 , V_3 ) ;
if ( error )
goto V_72;
} else if ( args -> V_94 > 0 ) {
error = F_66 ( args ) ;
if ( error )
goto V_72;
}
V_82 = error = 0 ;
V_72:
if ( V_100 )
F_75 ( V_100 ) ;
if ( error )
return error ;
return V_82 ;
}
STATIC int
F_47 ( T_3 * args )
{
T_5 * V_100 ;
T_6 * V_101 ;
T_4 * V_3 ;
struct V_86 * V_87 ;
int V_82 , error , V_47 , V_81 ;
F_79 ( args ) ;
V_3 = args -> V_3 ;
V_100 = F_72 () ;
V_100 -> args = args ;
V_100 -> V_34 = V_3 -> V_8 ;
error = F_73 ( V_100 , & V_82 ) ;
if ( error || ( V_82 != - V_31 ) ) {
if ( error == 0 )
error = V_82 ;
goto V_72;
}
V_101 = & V_100 -> V_103 . V_101 [ V_100 -> V_103 . V_104 - 1 ] ;
ASSERT ( V_101 -> V_87 != NULL ) ;
ASSERT ( V_101 -> V_105 == V_106 ) ;
if ( args -> V_94 > 0 ) {
error = F_80 ( V_100 ) ;
if ( error )
goto V_72;
error = F_81 ( args ) ;
if ( error )
goto V_72;
error = F_62 ( args ) ;
if ( error )
goto V_72;
error = F_82 ( V_100 ) ;
if ( error )
goto V_72;
}
V_101 = & V_100 -> V_103 . V_101 [ V_100 -> V_103 . V_104 - 1 ] ;
ASSERT ( V_101 -> V_105 == V_106 ) ;
V_82 = F_63 ( V_101 -> V_87 , args ) ;
F_77 ( V_100 , & V_100 -> V_103 ) ;
if ( V_82 && ( V_100 -> V_103 . V_104 > 1 ) ) {
F_35 ( args -> V_40 , args -> V_43 ) ;
error = F_78 ( V_100 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_40 ,
& V_47 ) ;
}
if ( error ) {
ASSERT ( V_47 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_72;
}
if ( V_47 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
error = F_39 ( & args -> V_53 , V_3 ) ;
if ( error )
goto V_72;
}
if ( F_10 ( V_3 , V_11 ) ) {
ASSERT ( V_100 -> V_103 . V_104 == 1 ) ;
ASSERT ( V_100 -> V_103 . V_101 [ 0 ] . V_87 ) ;
V_100 -> V_103 . V_101 [ 0 ] . V_87 = NULL ;
error = F_54 ( args -> V_53 , args -> V_3 , 0 , - 1 , & V_87 ) ;
if ( error )
goto V_72;
if ( ( V_81 = F_64 ( V_87 , V_3 ) ) ) {
F_35 ( args -> V_40 , args -> V_43 ) ;
error = F_65 ( V_87 , args , V_81 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_40 ,
& V_47 ) ;
}
if ( error ) {
ASSERT ( V_47 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_72;
}
if ( V_47 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
} else
F_56 ( args -> V_53 , V_87 ) ;
}
error = 0 ;
V_72:
F_75 ( V_100 ) ;
return error ;
}
STATIC int
F_80 ( T_5 * V_100 )
{
T_8 * V_103 ;
T_6 * V_101 ;
int V_109 ;
F_83 ( V_100 -> args ) ;
V_103 = & V_100 -> V_103 ;
ASSERT ( ( V_103 -> V_104 >= 0 ) && ( V_103 -> V_104 < V_110 ) ) ;
for ( V_101 = V_103 -> V_101 , V_109 = 0 ; V_109 < V_103 -> V_104 ; V_101 ++ , V_109 ++ ) {
if ( V_101 -> V_87 ) {
V_101 -> V_111 = F_84 ( V_101 -> V_87 ) ;
V_101 -> V_87 = NULL ;
} else {
V_101 -> V_111 = 0 ;
}
}
V_103 = & V_100 -> V_112 ;
ASSERT ( ( V_103 -> V_104 >= 0 ) && ( V_103 -> V_104 < V_110 ) ) ;
for ( V_101 = V_103 -> V_101 , V_109 = 0 ; V_109 < V_103 -> V_104 ; V_101 ++ , V_109 ++ ) {
if ( V_101 -> V_87 ) {
V_101 -> V_111 = F_84 ( V_101 -> V_87 ) ;
V_101 -> V_87 = NULL ;
} else {
V_101 -> V_111 = 0 ;
}
}
return 0 ;
}
STATIC int
F_82 ( T_5 * V_100 )
{
T_8 * V_103 ;
T_6 * V_101 ;
int V_109 , error ;
F_85 ( V_100 -> args ) ;
V_103 = & V_100 -> V_103 ;
ASSERT ( ( V_103 -> V_104 >= 0 ) && ( V_103 -> V_104 < V_110 ) ) ;
for ( V_101 = V_103 -> V_101 , V_109 = 0 ; V_109 < V_103 -> V_104 ; V_101 ++ , V_109 ++ ) {
if ( V_101 -> V_111 ) {
error = F_86 ( V_100 -> args -> V_53 ,
V_100 -> args -> V_3 ,
V_101 -> V_88 , V_101 -> V_111 ,
& V_101 -> V_87 , V_11 ) ;
if ( error )
return error ;
} else {
V_101 -> V_87 = NULL ;
}
}
V_103 = & V_100 -> V_112 ;
ASSERT ( ( V_103 -> V_104 >= 0 ) && ( V_103 -> V_104 < V_110 ) ) ;
for ( V_101 = V_103 -> V_101 , V_109 = 0 ; V_109 < V_103 -> V_104 ; V_101 ++ , V_109 ++ ) {
if ( V_101 -> V_111 ) {
error = F_86 ( V_100 -> args -> V_53 ,
V_100 -> args -> V_3 ,
V_101 -> V_88 , V_101 -> V_111 ,
& V_101 -> V_87 , V_11 ) ;
if ( error )
return error ;
} else {
V_101 -> V_87 = NULL ;
}
}
return 0 ;
}
STATIC int
F_12 ( T_3 * args )
{
T_5 * V_100 ;
T_6 * V_101 ;
int error , V_82 ;
int V_113 ;
F_87 ( args ) ;
V_100 = F_72 () ;
V_100 -> args = args ;
V_100 -> V_34 = args -> V_3 -> V_8 ;
error = F_73 ( V_100 , & V_82 ) ;
if ( error ) {
V_82 = error ;
} else if ( V_82 == - V_31 ) {
V_101 = & V_100 -> V_103 . V_101 [ V_100 -> V_103 . V_104 - 1 ] ;
ASSERT ( V_101 -> V_87 != NULL ) ;
ASSERT ( V_101 -> V_105 == V_106 ) ;
V_82 = F_69 ( V_101 -> V_87 , args ) ;
if ( ! V_82 && ( args -> V_94 > 0 )
&& ! ( args -> V_5 & V_99 ) ) {
V_82 = F_70 ( args ) ;
}
}
for ( V_113 = 0 ; V_113 < V_100 -> V_103 . V_104 ; V_113 ++ ) {
F_56 ( args -> V_53 , V_100 -> V_103 . V_101 [ V_113 ] . V_87 ) ;
V_100 -> V_103 . V_101 [ V_113 ] . V_87 = NULL ;
}
F_75 ( V_100 ) ;
return V_82 ;
}
