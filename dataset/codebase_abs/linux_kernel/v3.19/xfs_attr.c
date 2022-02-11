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
F_6 ( V_24 ) ;
if ( F_7 ( V_16 -> V_8 ) )
return - V_25 ;
if ( ! F_3 ( V_16 ) )
return - V_26 ;
error = F_1 ( & args , V_16 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_21 = V_21 ;
args . V_27 = * V_22 ;
V_23 = F_8 ( V_16 ) ;
if ( ! F_3 ( V_16 ) )
error = - V_26 ;
else if ( V_16 -> V_17 . V_18 == V_28 )
error = F_9 ( & args ) ;
else if ( F_10 ( V_16 , V_11 ) )
error = F_11 ( & args ) ;
else
error = F_12 ( & args ) ;
F_13 ( V_16 , V_23 ) ;
* V_22 = args . V_27 ;
return error == - V_29 ? 0 : error ;
}
STATIC int
F_14 (
struct V_1 * args ,
int * V_30 )
{
struct V_31 * V_32 = args -> V_3 -> V_8 ;
int V_33 ;
int V_34 ;
V_33 = F_15 ( args , V_30 ) ;
V_34 = F_16 ( V_32 , V_11 ) ;
if ( * V_30 ) {
if ( V_33 > ( args -> V_7 -> V_35 / 2 ) ) {
V_34 *= 2 ;
}
} else {
T_1 V_36 = F_17 ( V_32 , args -> V_27 ) ;
V_34 += V_36 ;
V_34 += F_18 ( V_32 , V_36 , V_11 ) ;
}
return V_34 ;
}
int
F_19 (
struct V_2 * V_3 ,
const unsigned char * V_4 ,
unsigned char * V_21 ,
int V_27 ,
int V_5 )
{
struct V_31 * V_32 = V_3 -> V_8 ;
struct V_1 args ;
struct V_37 V_38 ;
struct V_39 V_40 ;
T_2 V_41 ;
int V_42 = ( V_5 & V_43 ) != 0 ;
int error , V_44 , V_45 , V_30 ;
F_6 ( V_46 ) ;
if ( F_7 ( V_3 -> V_8 ) )
return - V_25 ;
error = F_1 ( & args , V_3 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_21 = V_21 ;
args . V_27 = V_27 ;
args . V_41 = & V_41 ;
args . V_38 = & V_38 ;
args . V_47 = V_48 | V_49 ;
args . V_50 = F_14 ( & args , & V_30 ) ;
error = F_20 ( V_3 , 0 ) ;
if ( error )
return error ;
if ( F_4 ( V_3 ) == 0 ) {
int V_51 = sizeof( V_52 ) +
F_21 ( args . V_12 , V_27 ) ;
error = F_22 ( V_3 , V_51 , V_42 ) ;
if ( error )
return error ;
}
args . V_53 = F_23 ( V_32 , V_54 ) ;
if ( V_42 )
args . V_53 -> V_55 |= V_56 ;
V_40 . V_57 = F_24 ( V_32 ) -> V_58 . V_57 +
F_24 ( V_32 ) -> V_59 . V_57 * args . V_50 ;
V_40 . V_60 = V_61 ;
V_40 . V_62 = V_63 ;
error = F_25 ( args . V_53 , & V_40 , args . V_50 , 0 ) ;
if ( error ) {
F_26 ( args . V_53 , 0 ) ;
return error ;
}
F_27 ( V_3 , V_64 ) ;
error = F_28 ( args . V_53 , V_3 , args . V_50 , 0 ,
V_42 ? V_65 | V_66 :
V_65 ) ;
if ( error ) {
F_13 ( V_3 , V_64 ) ;
F_26 ( args . V_53 , V_67 ) ;
return error ;
}
F_29 ( args . V_53 , V_3 , 0 ) ;
if ( V_3 -> V_17 . V_18 == V_28 ||
( V_3 -> V_17 . V_18 == V_19 &&
V_3 -> V_17 . V_20 == 0 ) ) {
if ( V_3 -> V_17 . V_18 == V_19 )
F_30 ( & args ) ;
error = F_31 ( & args ) ;
if ( error != - V_68 ) {
ASSERT ( args . V_53 != NULL ) ;
if ( V_32 -> V_69 & V_70 )
F_32 ( args . V_53 ) ;
if ( ! error && ( V_5 & V_71 ) == 0 ) {
F_33 ( args . V_53 , V_3 ,
V_72 ) ;
}
V_44 = F_34 ( args . V_53 ,
V_67 ) ;
F_13 ( V_3 , V_64 ) ;
return error ? error : V_44 ;
}
F_35 ( args . V_38 , args . V_41 ) ;
error = F_36 ( & args ) ;
if ( ! error ) {
error = F_37 ( & args . V_53 , args . V_38 ,
& V_45 ) ;
}
if ( error ) {
ASSERT ( V_45 ) ;
args . V_53 = NULL ;
F_38 ( & V_38 ) ;
goto V_73;
}
if ( V_45 )
F_29 ( args . V_53 , V_3 , 0 ) ;
error = F_39 ( & args . V_53 , V_3 ) ;
if ( error )
goto V_73;
}
if ( F_10 ( V_3 , V_11 ) )
error = F_40 ( & args ) ;
else
error = F_41 ( & args ) ;
if ( error )
goto V_73;
if ( V_32 -> V_69 & V_70 )
F_32 ( args . V_53 ) ;
if ( ( V_5 & V_71 ) == 0 )
F_33 ( args . V_53 , V_3 , V_72 ) ;
F_42 ( args . V_53 , V_3 , V_74 ) ;
error = F_34 ( args . V_53 , V_67 ) ;
F_13 ( V_3 , V_64 ) ;
return error ;
V_73:
if ( args . V_53 ) {
F_26 ( args . V_53 ,
V_67 | V_75 ) ;
}
F_13 ( V_3 , V_64 ) ;
return error ;
}
int
F_43 (
struct V_2 * V_3 ,
const unsigned char * V_4 ,
int V_5 )
{
struct V_31 * V_32 = V_3 -> V_8 ;
struct V_1 args ;
struct V_37 V_38 ;
T_2 V_41 ;
int error ;
F_6 ( V_76 ) ;
if ( F_7 ( V_3 -> V_8 ) )
return - V_25 ;
if ( ! F_3 ( V_3 ) )
return - V_26 ;
error = F_1 ( & args , V_3 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_41 = & V_41 ;
args . V_38 = & V_38 ;
args . V_47 = V_49 ;
error = F_20 ( V_3 , 0 ) ;
if ( error )
return error ;
args . V_53 = F_23 ( V_32 , V_77 ) ;
if ( V_5 & V_43 )
args . V_53 -> V_55 |= V_56 ;
error = F_25 ( args . V_53 , & F_24 ( V_32 ) -> V_78 ,
F_44 ( V_32 ) , 0 ) ;
if ( error ) {
F_26 ( args . V_53 , 0 ) ;
return error ;
}
F_27 ( V_3 , V_64 ) ;
F_29 ( args . V_53 , V_3 , 0 ) ;
if ( ! F_3 ( V_3 ) ) {
error = - V_26 ;
} else if ( V_3 -> V_17 . V_18 == V_28 ) {
ASSERT ( V_3 -> V_79 -> V_80 & V_81 ) ;
error = F_45 ( & args ) ;
} else if ( F_10 ( V_3 , V_11 ) ) {
error = F_46 ( & args ) ;
} else {
error = F_47 ( & args ) ;
}
if ( error )
goto V_73;
if ( V_32 -> V_69 & V_70 )
F_32 ( args . V_53 ) ;
if ( ( V_5 & V_71 ) == 0 )
F_33 ( args . V_53 , V_3 , V_72 ) ;
F_42 ( args . V_53 , V_3 , V_74 ) ;
error = F_34 ( args . V_53 , V_67 ) ;
F_13 ( V_3 , V_64 ) ;
return error ;
V_73:
if ( args . V_53 ) {
F_26 ( args . V_53 ,
V_67 | V_75 ) ;
}
F_13 ( V_3 , V_64 ) ;
return error ;
}
STATIC int
F_31 ( T_3 * args )
{
int V_82 , V_83 , V_84 ;
F_48 ( args ) ;
V_84 = F_49 ( args ) ;
if ( ( args -> V_5 & V_85 ) && ( V_84 == - V_26 ) ) {
return V_84 ;
} else if ( V_84 == - V_29 ) {
if ( args -> V_5 & V_86 )
return V_84 ;
V_84 = F_45 ( args ) ;
ASSERT ( V_84 == 0 ) ;
}
if ( args -> V_12 >= V_87 ||
args -> V_27 >= V_87 )
return - V_68 ;
V_82 = F_50 ( args -> V_3 ) ;
V_82 += F_21 ( args -> V_12 , args -> V_27 ) ;
V_83 = F_51 ( args -> V_3 , V_82 ) ;
if ( ! V_83 )
return - V_68 ;
F_52 ( args , V_83 ) ;
return 0 ;
}
STATIC int
F_40 ( T_3 * args )
{
T_4 * V_3 ;
struct V_88 * V_89 ;
int V_84 , error , V_45 , V_83 ;
F_53 ( args ) ;
V_3 = args -> V_3 ;
args -> V_90 = 0 ;
error = F_54 ( args -> V_53 , args -> V_3 , args -> V_90 , - 1 , & V_89 ) ;
if ( error )
return error ;
V_84 = F_55 ( V_89 , args ) ;
if ( ( args -> V_5 & V_85 ) && ( V_84 == - V_26 ) ) {
F_56 ( args -> V_53 , V_89 ) ;
return V_84 ;
} else if ( V_84 == - V_29 ) {
if ( args -> V_5 & V_86 ) {
F_56 ( args -> V_53 , V_89 ) ;
return V_84 ;
}
F_57 ( args ) ;
args -> V_47 |= V_91 ;
args -> V_92 = args -> V_90 ;
args -> V_93 = args -> V_94 ;
args -> V_95 = args -> V_96 ;
args -> V_97 = args -> V_98 ;
args -> V_99 = args -> V_100 ;
args -> V_96 = 0 ;
args -> V_98 = 0 ;
args -> V_100 = 0 ;
}
V_84 = F_58 ( V_89 , args ) ;
if ( V_84 == - V_68 ) {
F_35 ( args -> V_38 , args -> V_41 ) ;
error = F_59 ( args ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_38 ,
& V_45 ) ;
}
if ( error ) {
ASSERT ( V_45 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_38 ) ;
return error ;
}
if ( V_45 )
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
if ( args -> V_96 > 0 ) {
error = F_60 ( args ) ;
if ( error )
return error ;
}
if ( args -> V_47 & V_91 ) {
error = F_61 ( args ) ;
if ( error )
return error ;
args -> V_94 = args -> V_93 ;
args -> V_90 = args -> V_92 ;
args -> V_96 = args -> V_95 ;
args -> V_98 = args -> V_97 ;
args -> V_100 = args -> V_99 ;
if ( args -> V_96 ) {
error = F_62 ( args ) ;
if ( error )
return error ;
}
error = F_54 ( args -> V_53 , args -> V_3 , args -> V_90 ,
- 1 , & V_89 ) ;
if ( error )
return error ;
F_63 ( V_89 , args ) ;
if ( ( V_83 = F_64 ( V_89 , V_3 ) ) ) {
F_35 ( args -> V_38 , args -> V_41 ) ;
error = F_65 ( V_89 , args , V_83 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_38 ,
& V_45 ) ;
}
if ( error ) {
ASSERT ( V_45 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_38 ) ;
return error ;
}
if ( V_45 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
}
error = F_39 ( & args -> V_53 , V_3 ) ;
} else if ( args -> V_96 > 0 ) {
error = F_66 ( args ) ;
}
return error ;
}
STATIC int
F_46 ( T_3 * args )
{
T_4 * V_3 ;
struct V_88 * V_89 ;
int error , V_45 , V_83 ;
F_67 ( args ) ;
V_3 = args -> V_3 ;
args -> V_90 = 0 ;
error = F_54 ( args -> V_53 , args -> V_3 , args -> V_90 , - 1 , & V_89 ) ;
if ( error )
return error ;
error = F_55 ( V_89 , args ) ;
if ( error == - V_26 ) {
F_56 ( args -> V_53 , V_89 ) ;
return error ;
}
F_63 ( V_89 , args ) ;
if ( ( V_83 = F_64 ( V_89 , V_3 ) ) ) {
F_35 ( args -> V_38 , args -> V_41 ) ;
error = F_65 ( V_89 , args , V_83 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_38 ,
& V_45 ) ;
}
if ( error ) {
ASSERT ( V_45 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_38 ) ;
return error ;
}
if ( V_45 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
}
return 0 ;
}
STATIC int
F_11 ( T_3 * args )
{
struct V_88 * V_89 ;
int error ;
F_68 ( args ) ;
args -> V_90 = 0 ;
error = F_54 ( args -> V_53 , args -> V_3 , args -> V_90 , - 1 , & V_89 ) ;
if ( error )
return error ;
error = F_55 ( V_89 , args ) ;
if ( error != - V_29 ) {
F_56 ( args -> V_53 , V_89 ) ;
return error ;
}
error = F_69 ( V_89 , args ) ;
F_56 ( args -> V_53 , V_89 ) ;
if ( ! error && ( args -> V_96 > 0 ) && ! ( args -> V_5 & V_101 ) ) {
error = F_70 ( args ) ;
}
return error ;
}
STATIC int
F_41 ( T_3 * args )
{
T_5 * V_102 ;
T_6 * V_103 ;
T_4 * V_3 ;
T_7 * V_32 ;
int V_45 , V_84 , error ;
F_71 ( args ) ;
V_3 = args -> V_3 ;
V_32 = V_3 -> V_8 ;
V_104:
V_102 = F_72 () ;
V_102 -> args = args ;
V_102 -> V_32 = V_32 ;
error = F_73 ( V_102 , & V_84 ) ;
if ( error )
goto V_73;
V_103 = & V_102 -> V_105 . V_103 [ V_102 -> V_105 . V_106 - 1 ] ;
ASSERT ( V_103 -> V_107 == V_108 ) ;
if ( ( args -> V_5 & V_85 ) && ( V_84 == - V_26 ) ) {
goto V_73;
} else if ( V_84 == - V_29 ) {
if ( args -> V_5 & V_86 )
goto V_73;
F_74 ( args ) ;
args -> V_47 |= V_91 ;
args -> V_92 = args -> V_90 ;
args -> V_93 = args -> V_94 ;
args -> V_95 = args -> V_96 ;
args -> V_97 = args -> V_98 ;
args -> V_99 = args -> V_100 ;
args -> V_96 = 0 ;
args -> V_98 = 0 ;
args -> V_100 = 0 ;
}
V_84 = F_58 ( V_103 -> V_89 , V_102 -> args ) ;
if ( V_84 == - V_68 ) {
if ( V_102 -> V_105 . V_106 == 1 ) {
F_75 ( V_102 ) ;
V_102 = NULL ;
F_35 ( args -> V_38 , args -> V_41 ) ;
error = F_59 ( args ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_38 ,
& V_45 ) ;
}
if ( error ) {
ASSERT ( V_45 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_38 ) ;
goto V_73;
}
if ( V_45 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
error = F_39 ( & args -> V_53 , V_3 ) ;
if ( error )
goto V_73;
goto V_104;
}
F_35 ( args -> V_38 , args -> V_41 ) ;
error = F_76 ( V_102 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_38 ,
& V_45 ) ;
}
if ( error ) {
ASSERT ( V_45 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_38 ) ;
goto V_73;
}
if ( V_45 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
} else {
F_77 ( V_102 , & V_102 -> V_105 ) ;
}
F_75 ( V_102 ) ;
V_102 = NULL ;
error = F_39 ( & args -> V_53 , V_3 ) ;
if ( error )
goto V_73;
if ( args -> V_96 > 0 ) {
error = F_60 ( args ) ;
if ( error )
return error ;
}
if ( args -> V_47 & V_91 ) {
error = F_61 ( args ) ;
if ( error )
goto V_73;
args -> V_94 = args -> V_93 ;
args -> V_90 = args -> V_92 ;
args -> V_96 = args -> V_95 ;
args -> V_98 = args -> V_97 ;
args -> V_100 = args -> V_99 ;
if ( args -> V_96 ) {
error = F_62 ( args ) ;
if ( error )
return error ;
}
args -> V_5 |= V_109 ;
V_102 = F_72 () ;
V_102 -> args = args ;
V_102 -> V_32 = V_32 ;
V_102 -> V_110 = 0 ;
error = F_73 ( V_102 , & V_84 ) ;
if ( error )
goto V_73;
V_103 = & V_102 -> V_105 . V_103 [ V_102 -> V_105 . V_106 - 1 ] ;
ASSERT ( V_103 -> V_107 == V_108 ) ;
error = F_63 ( V_103 -> V_89 , args ) ;
F_77 ( V_102 , & V_102 -> V_105 ) ;
if ( V_84 && ( V_102 -> V_105 . V_106 > 1 ) ) {
F_35 ( args -> V_38 , args -> V_41 ) ;
error = F_78 ( V_102 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_38 ,
& V_45 ) ;
}
if ( error ) {
ASSERT ( V_45 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_38 ) ;
goto V_73;
}
if ( V_45 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
}
error = F_39 ( & args -> V_53 , V_3 ) ;
if ( error )
goto V_73;
} else if ( args -> V_96 > 0 ) {
error = F_66 ( args ) ;
if ( error )
goto V_73;
}
V_84 = error = 0 ;
V_73:
if ( V_102 )
F_75 ( V_102 ) ;
if ( error )
return error ;
return V_84 ;
}
STATIC int
F_47 ( T_3 * args )
{
T_5 * V_102 ;
T_6 * V_103 ;
T_4 * V_3 ;
struct V_88 * V_89 ;
int V_84 , error , V_45 , V_83 ;
F_79 ( args ) ;
V_3 = args -> V_3 ;
V_102 = F_72 () ;
V_102 -> args = args ;
V_102 -> V_32 = V_3 -> V_8 ;
error = F_73 ( V_102 , & V_84 ) ;
if ( error || ( V_84 != - V_29 ) ) {
if ( error == 0 )
error = V_84 ;
goto V_73;
}
V_103 = & V_102 -> V_105 . V_103 [ V_102 -> V_105 . V_106 - 1 ] ;
ASSERT ( V_103 -> V_89 != NULL ) ;
ASSERT ( V_103 -> V_107 == V_108 ) ;
if ( args -> V_96 > 0 ) {
error = F_80 ( V_102 ) ;
if ( error )
goto V_73;
error = F_81 ( args ) ;
if ( error )
goto V_73;
error = F_62 ( args ) ;
if ( error )
goto V_73;
error = F_82 ( V_102 ) ;
if ( error )
goto V_73;
}
V_103 = & V_102 -> V_105 . V_103 [ V_102 -> V_105 . V_106 - 1 ] ;
ASSERT ( V_103 -> V_107 == V_108 ) ;
V_84 = F_63 ( V_103 -> V_89 , args ) ;
F_77 ( V_102 , & V_102 -> V_105 ) ;
if ( V_84 && ( V_102 -> V_105 . V_106 > 1 ) ) {
F_35 ( args -> V_38 , args -> V_41 ) ;
error = F_78 ( V_102 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_38 ,
& V_45 ) ;
}
if ( error ) {
ASSERT ( V_45 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_38 ) ;
goto V_73;
}
if ( V_45 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
error = F_39 ( & args -> V_53 , V_3 ) ;
if ( error )
goto V_73;
}
if ( F_10 ( V_3 , V_11 ) ) {
ASSERT ( V_102 -> V_105 . V_106 == 1 ) ;
ASSERT ( V_102 -> V_105 . V_103 [ 0 ] . V_89 ) ;
V_102 -> V_105 . V_103 [ 0 ] . V_89 = NULL ;
error = F_54 ( args -> V_53 , args -> V_3 , 0 , - 1 , & V_89 ) ;
if ( error )
goto V_73;
if ( ( V_83 = F_64 ( V_89 , V_3 ) ) ) {
F_35 ( args -> V_38 , args -> V_41 ) ;
error = F_65 ( V_89 , args , V_83 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_38 ,
& V_45 ) ;
}
if ( error ) {
ASSERT ( V_45 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_38 ) ;
goto V_73;
}
if ( V_45 )
F_29 ( args -> V_53 , V_3 , 0 ) ;
} else
F_56 ( args -> V_53 , V_89 ) ;
}
error = 0 ;
V_73:
F_75 ( V_102 ) ;
return error ;
}
STATIC int
F_80 ( T_5 * V_102 )
{
T_8 * V_105 ;
T_6 * V_103 ;
int V_111 ;
F_83 ( V_102 -> args ) ;
V_105 = & V_102 -> V_105 ;
ASSERT ( ( V_105 -> V_106 >= 0 ) && ( V_105 -> V_106 < V_112 ) ) ;
for ( V_103 = V_105 -> V_103 , V_111 = 0 ; V_111 < V_105 -> V_106 ; V_103 ++ , V_111 ++ ) {
if ( V_103 -> V_89 ) {
V_103 -> V_113 = F_84 ( V_103 -> V_89 ) ;
V_103 -> V_89 = NULL ;
} else {
V_103 -> V_113 = 0 ;
}
}
V_105 = & V_102 -> V_114 ;
ASSERT ( ( V_105 -> V_106 >= 0 ) && ( V_105 -> V_106 < V_112 ) ) ;
for ( V_103 = V_105 -> V_103 , V_111 = 0 ; V_111 < V_105 -> V_106 ; V_103 ++ , V_111 ++ ) {
if ( V_103 -> V_89 ) {
V_103 -> V_113 = F_84 ( V_103 -> V_89 ) ;
V_103 -> V_89 = NULL ;
} else {
V_103 -> V_113 = 0 ;
}
}
return 0 ;
}
STATIC int
F_82 ( T_5 * V_102 )
{
T_8 * V_105 ;
T_6 * V_103 ;
int V_111 , error ;
F_85 ( V_102 -> args ) ;
V_105 = & V_102 -> V_105 ;
ASSERT ( ( V_105 -> V_106 >= 0 ) && ( V_105 -> V_106 < V_112 ) ) ;
for ( V_103 = V_105 -> V_103 , V_111 = 0 ; V_111 < V_105 -> V_106 ; V_103 ++ , V_111 ++ ) {
if ( V_103 -> V_113 ) {
error = F_86 ( V_102 -> args -> V_53 ,
V_102 -> args -> V_3 ,
V_103 -> V_90 , V_103 -> V_113 ,
& V_103 -> V_89 , V_11 ) ;
if ( error )
return error ;
} else {
V_103 -> V_89 = NULL ;
}
}
V_105 = & V_102 -> V_114 ;
ASSERT ( ( V_105 -> V_106 >= 0 ) && ( V_105 -> V_106 < V_112 ) ) ;
for ( V_103 = V_105 -> V_103 , V_111 = 0 ; V_111 < V_105 -> V_106 ; V_103 ++ , V_111 ++ ) {
if ( V_103 -> V_113 ) {
error = F_86 ( V_102 -> args -> V_53 ,
V_102 -> args -> V_3 ,
V_103 -> V_90 , V_103 -> V_113 ,
& V_103 -> V_89 , V_11 ) ;
if ( error )
return error ;
} else {
V_103 -> V_89 = NULL ;
}
}
return 0 ;
}
STATIC int
F_12 ( T_3 * args )
{
T_5 * V_102 ;
T_6 * V_103 ;
int error , V_84 ;
int V_115 ;
F_87 ( args ) ;
V_102 = F_72 () ;
V_102 -> args = args ;
V_102 -> V_32 = args -> V_3 -> V_8 ;
error = F_73 ( V_102 , & V_84 ) ;
if ( error ) {
V_84 = error ;
} else if ( V_84 == - V_29 ) {
V_103 = & V_102 -> V_105 . V_103 [ V_102 -> V_105 . V_106 - 1 ] ;
ASSERT ( V_103 -> V_89 != NULL ) ;
ASSERT ( V_103 -> V_107 == V_108 ) ;
V_84 = F_69 ( V_103 -> V_89 , args ) ;
if ( ! V_84 && ( args -> V_96 > 0 )
&& ! ( args -> V_5 & V_101 ) ) {
V_84 = F_70 ( args ) ;
}
}
for ( V_115 = 0 ; V_115 < V_102 -> V_105 . V_106 ; V_115 ++ ) {
F_56 ( args -> V_53 , V_102 -> V_105 . V_103 [ V_115 ] . V_89 ) ;
V_102 -> V_105 . V_103 [ V_115 ] . V_89 = NULL ;
}
F_75 ( V_102 ) ;
return V_84 ;
}
