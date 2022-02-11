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
struct V_1 * args )
{
ASSERT ( F_6 ( V_16 , V_21 | V_22 ) ) ;
if ( ! F_3 ( V_16 ) )
return - V_23 ;
else if ( V_16 -> V_17 . V_18 == V_24 )
return F_7 ( args ) ;
else if ( F_8 ( V_16 , V_11 ) )
return F_9 ( args ) ;
else
return F_10 ( args ) ;
}
int
F_11 (
struct V_2 * V_16 ,
const unsigned char * V_4 ,
unsigned char * V_25 ,
int * V_26 ,
int V_5 )
{
struct V_1 args ;
T_1 V_27 ;
int error ;
F_12 ( V_16 -> V_8 , V_28 ) ;
if ( F_13 ( V_16 -> V_8 ) )
return - V_29 ;
error = F_1 ( & args , V_16 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_25 = V_25 ;
args . V_30 = * V_26 ;
args . V_31 = V_32 ;
V_27 = F_14 ( V_16 ) ;
error = F_5 ( V_16 , & args ) ;
F_15 ( V_16 , V_27 ) ;
* V_26 = args . V_30 ;
return error == - V_33 ? 0 : error ;
}
STATIC int
F_16 (
struct V_1 * args ,
int * V_34 )
{
struct V_35 * V_36 = args -> V_3 -> V_8 ;
int V_37 ;
int V_38 ;
V_37 = F_17 ( args , V_34 ) ;
V_38 = F_18 ( V_36 , V_11 ) ;
if ( * V_34 ) {
if ( V_37 > ( args -> V_7 -> V_39 / 2 ) ) {
V_38 *= 2 ;
}
} else {
T_1 V_40 = F_19 ( V_36 , args -> V_30 ) ;
V_38 += V_40 ;
V_38 += F_20 ( V_36 , V_40 , V_11 ) ;
}
return V_38 ;
}
int
F_21 (
struct V_2 * V_3 ,
const unsigned char * V_4 ,
unsigned char * V_25 ,
int V_30 ,
int V_5 )
{
struct V_35 * V_36 = V_3 -> V_8 ;
struct V_1 args ;
struct V_41 V_42 ;
struct V_43 V_44 ;
T_2 V_45 ;
int V_46 = ( V_5 & V_47 ) != 0 ;
int error , V_48 , V_34 ;
F_12 ( V_36 , V_49 ) ;
if ( F_13 ( V_3 -> V_8 ) )
return - V_29 ;
error = F_1 ( & args , V_3 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_25 = V_25 ;
args . V_30 = V_30 ;
args . V_45 = & V_45 ;
args . V_42 = & V_42 ;
args . V_31 = V_50 | V_32 ;
args . V_51 = F_16 ( & args , & V_34 ) ;
error = F_22 ( V_3 , 0 ) ;
if ( error )
return error ;
if ( F_4 ( V_3 ) == 0 ) {
int V_52 = sizeof( V_53 ) +
F_23 ( args . V_12 , V_30 ) ;
error = F_24 ( V_3 , V_52 , V_46 ) ;
if ( error )
return error ;
}
V_44 . V_54 = F_25 ( V_36 ) -> V_55 . V_54 +
F_25 ( V_36 ) -> V_56 . V_54 * args . V_51 ;
V_44 . V_57 = V_58 ;
V_44 . V_59 = V_60 ;
error = F_26 ( V_36 , & V_44 , args . V_51 , 0 ,
V_46 ? V_61 : 0 , & args . V_62 ) ;
if ( error )
return error ;
F_27 ( V_3 , V_22 ) ;
error = F_28 ( args . V_62 , V_3 , args . V_51 , 0 ,
V_46 ? V_63 | V_64 :
V_63 ) ;
if ( error ) {
F_15 ( V_3 , V_22 ) ;
F_29 ( args . V_62 ) ;
return error ;
}
F_30 ( args . V_62 , V_3 , 0 ) ;
if ( V_3 -> V_17 . V_18 == V_24 ||
( V_3 -> V_17 . V_18 == V_19 &&
V_3 -> V_17 . V_20 == 0 ) ) {
if ( V_3 -> V_17 . V_18 == V_19 )
F_31 ( & args ) ;
error = F_32 ( & args ) ;
if ( error != - V_65 ) {
ASSERT ( args . V_62 != NULL ) ;
if ( V_36 -> V_66 & V_67 )
F_33 ( args . V_62 ) ;
if ( ! error && ( V_5 & V_68 ) == 0 ) {
F_34 ( args . V_62 , V_3 ,
V_69 ) ;
}
V_48 = F_35 ( args . V_62 ) ;
F_15 ( V_3 , V_22 ) ;
return error ? error : V_48 ;
}
F_36 ( args . V_42 , args . V_45 ) ;
error = F_37 ( & args ) ;
if ( ! error )
error = F_38 ( & args . V_62 , args . V_42 , V_3 ) ;
if ( error ) {
args . V_62 = NULL ;
F_39 ( & V_42 ) ;
goto V_70;
}
error = F_40 ( & args . V_62 , V_3 ) ;
if ( error )
goto V_70;
}
if ( F_8 ( V_3 , V_11 ) )
error = F_41 ( & args ) ;
else
error = F_42 ( & args ) ;
if ( error )
goto V_70;
if ( V_36 -> V_66 & V_67 )
F_33 ( args . V_62 ) ;
if ( ( V_5 & V_68 ) == 0 )
F_34 ( args . V_62 , V_3 , V_69 ) ;
F_43 ( args . V_62 , V_3 , V_71 ) ;
error = F_35 ( args . V_62 ) ;
F_15 ( V_3 , V_22 ) ;
return error ;
V_70:
if ( args . V_62 )
F_29 ( args . V_62 ) ;
F_15 ( V_3 , V_22 ) ;
return error ;
}
int
F_44 (
struct V_2 * V_3 ,
const unsigned char * V_4 ,
int V_5 )
{
struct V_35 * V_36 = V_3 -> V_8 ;
struct V_1 args ;
struct V_41 V_42 ;
T_2 V_45 ;
int error ;
F_12 ( V_36 , V_72 ) ;
if ( F_13 ( V_3 -> V_8 ) )
return - V_29 ;
error = F_1 ( & args , V_3 , V_4 , V_5 ) ;
if ( error )
return error ;
args . V_45 = & V_45 ;
args . V_42 = & V_42 ;
args . V_31 = V_32 ;
error = F_22 ( V_3 , 0 ) ;
if ( error )
return error ;
error = F_26 ( V_36 , & F_25 ( V_36 ) -> V_73 ,
F_45 ( V_36 ) , 0 ,
( V_5 & V_47 ) ? V_61 : 0 ,
& args . V_62 ) ;
if ( error )
return error ;
F_27 ( V_3 , V_22 ) ;
F_30 ( args . V_62 , V_3 , 0 ) ;
if ( ! F_3 ( V_3 ) ) {
error = - V_23 ;
} else if ( V_3 -> V_17 . V_18 == V_24 ) {
ASSERT ( V_3 -> V_74 -> V_75 & V_76 ) ;
error = F_46 ( & args ) ;
} else if ( F_8 ( V_3 , V_11 ) ) {
error = F_47 ( & args ) ;
} else {
error = F_48 ( & args ) ;
}
if ( error )
goto V_70;
if ( V_36 -> V_66 & V_67 )
F_33 ( args . V_62 ) ;
if ( ( V_5 & V_68 ) == 0 )
F_34 ( args . V_62 , V_3 , V_69 ) ;
F_43 ( args . V_62 , V_3 , V_71 ) ;
error = F_35 ( args . V_62 ) ;
F_15 ( V_3 , V_22 ) ;
return error ;
V_70:
if ( args . V_62 )
F_29 ( args . V_62 ) ;
F_15 ( V_3 , V_22 ) ;
return error ;
}
STATIC int
F_32 ( T_3 * args )
{
int V_77 , V_78 , V_79 ;
F_49 ( args ) ;
V_79 = F_50 ( args ) ;
if ( ( args -> V_5 & V_80 ) && ( V_79 == - V_23 ) ) {
return V_79 ;
} else if ( V_79 == - V_33 ) {
if ( args -> V_5 & V_81 )
return V_79 ;
V_79 = F_46 ( args ) ;
ASSERT ( V_79 == 0 ) ;
}
if ( args -> V_12 >= V_82 ||
args -> V_30 >= V_82 )
return - V_65 ;
V_77 = F_51 ( args -> V_3 ) ;
V_77 += F_23 ( args -> V_12 , args -> V_30 ) ;
V_78 = F_52 ( args -> V_3 , V_77 ) ;
if ( ! V_78 )
return - V_65 ;
F_53 ( args , V_78 ) ;
return 0 ;
}
STATIC int
F_41 ( T_3 * args )
{
T_4 * V_3 ;
struct V_83 * V_84 ;
int V_79 , error , V_78 ;
F_54 ( args ) ;
V_3 = args -> V_3 ;
args -> V_85 = 0 ;
error = F_55 ( args -> V_62 , args -> V_3 , args -> V_85 , - 1 , & V_84 ) ;
if ( error )
return error ;
V_79 = F_56 ( V_84 , args ) ;
if ( ( args -> V_5 & V_80 ) && ( V_79 == - V_23 ) ) {
F_57 ( args -> V_62 , V_84 ) ;
return V_79 ;
} else if ( V_79 == - V_33 ) {
if ( args -> V_5 & V_81 ) {
F_57 ( args -> V_62 , V_84 ) ;
return V_79 ;
}
F_58 ( args ) ;
args -> V_31 |= V_86 ;
args -> V_87 = args -> V_85 ;
args -> V_88 = args -> V_89 ;
args -> V_90 = args -> V_91 ;
args -> V_92 = args -> V_93 ;
args -> V_94 = args -> V_95 ;
args -> V_91 = 0 ;
args -> V_93 = 0 ;
args -> V_95 = 0 ;
}
V_79 = F_59 ( V_84 , args ) ;
if ( V_79 == - V_65 ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_60 ( args ) ;
if ( ! error )
error = F_38 ( & args -> V_62 , args -> V_42 , V_3 ) ;
if ( error ) {
args -> V_62 = NULL ;
F_39 ( args -> V_42 ) ;
return error ;
}
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
return error ;
error = F_42 ( args ) ;
return error ;
}
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
return error ;
if ( args -> V_91 > 0 ) {
error = F_61 ( args ) ;
if ( error )
return error ;
}
if ( args -> V_31 & V_86 ) {
error = F_62 ( args ) ;
if ( error )
return error ;
args -> V_89 = args -> V_88 ;
args -> V_85 = args -> V_87 ;
args -> V_91 = args -> V_90 ;
args -> V_93 = args -> V_92 ;
args -> V_95 = args -> V_94 ;
if ( args -> V_91 ) {
error = F_63 ( args ) ;
if ( error )
return error ;
}
error = F_55 ( args -> V_62 , args -> V_3 , args -> V_85 ,
- 1 , & V_84 ) ;
if ( error )
return error ;
F_64 ( V_84 , args ) ;
if ( ( V_78 = F_65 ( V_84 , V_3 ) ) ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_66 ( V_84 , args , V_78 ) ;
if ( ! error )
error = F_38 ( & args -> V_62 ,
args -> V_42 , V_3 ) ;
if ( error ) {
args -> V_62 = NULL ;
F_39 ( args -> V_42 ) ;
return error ;
}
}
error = F_40 ( & args -> V_62 , V_3 ) ;
} else if ( args -> V_91 > 0 ) {
error = F_67 ( args ) ;
}
return error ;
}
STATIC int
F_47 ( T_3 * args )
{
T_4 * V_3 ;
struct V_83 * V_84 ;
int error , V_78 ;
F_68 ( args ) ;
V_3 = args -> V_3 ;
args -> V_85 = 0 ;
error = F_55 ( args -> V_62 , args -> V_3 , args -> V_85 , - 1 , & V_84 ) ;
if ( error )
return error ;
error = F_56 ( V_84 , args ) ;
if ( error == - V_23 ) {
F_57 ( args -> V_62 , V_84 ) ;
return error ;
}
F_64 ( V_84 , args ) ;
if ( ( V_78 = F_65 ( V_84 , V_3 ) ) ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_66 ( V_84 , args , V_78 ) ;
if ( ! error )
error = F_38 ( & args -> V_62 , args -> V_42 , V_3 ) ;
if ( error ) {
args -> V_62 = NULL ;
F_39 ( args -> V_42 ) ;
return error ;
}
}
return 0 ;
}
STATIC int
F_9 ( T_3 * args )
{
struct V_83 * V_84 ;
int error ;
F_69 ( args ) ;
args -> V_85 = 0 ;
error = F_55 ( args -> V_62 , args -> V_3 , args -> V_85 , - 1 , & V_84 ) ;
if ( error )
return error ;
error = F_56 ( V_84 , args ) ;
if ( error != - V_33 ) {
F_57 ( args -> V_62 , V_84 ) ;
return error ;
}
error = F_70 ( V_84 , args ) ;
F_57 ( args -> V_62 , V_84 ) ;
if ( ! error && ( args -> V_91 > 0 ) && ! ( args -> V_5 & V_96 ) ) {
error = F_71 ( args ) ;
}
return error ;
}
STATIC int
F_42 ( T_3 * args )
{
T_5 * V_97 ;
T_6 * V_98 ;
T_4 * V_3 ;
T_7 * V_36 ;
int V_79 , error ;
F_72 ( args ) ;
V_3 = args -> V_3 ;
V_36 = V_3 -> V_8 ;
V_99:
V_97 = F_73 () ;
V_97 -> args = args ;
V_97 -> V_36 = V_36 ;
error = F_74 ( V_97 , & V_79 ) ;
if ( error )
goto V_70;
V_98 = & V_97 -> V_100 . V_98 [ V_97 -> V_100 . V_101 - 1 ] ;
ASSERT ( V_98 -> V_102 == V_103 ) ;
if ( ( args -> V_5 & V_80 ) && ( V_79 == - V_23 ) ) {
goto V_70;
} else if ( V_79 == - V_33 ) {
if ( args -> V_5 & V_81 )
goto V_70;
F_75 ( args ) ;
args -> V_31 |= V_86 ;
args -> V_87 = args -> V_85 ;
args -> V_88 = args -> V_89 ;
args -> V_90 = args -> V_91 ;
args -> V_92 = args -> V_93 ;
args -> V_94 = args -> V_95 ;
args -> V_91 = 0 ;
args -> V_93 = 0 ;
args -> V_95 = 0 ;
}
V_79 = F_59 ( V_98 -> V_84 , V_97 -> args ) ;
if ( V_79 == - V_65 ) {
if ( V_97 -> V_100 . V_101 == 1 ) {
F_76 ( V_97 ) ;
V_97 = NULL ;
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_60 ( args ) ;
if ( ! error )
error = F_38 ( & args -> V_62 ,
args -> V_42 , V_3 ) ;
if ( error ) {
args -> V_62 = NULL ;
F_39 ( args -> V_42 ) ;
goto V_70;
}
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
goto V_70;
goto V_99;
}
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_77 ( V_97 ) ;
if ( ! error )
error = F_38 ( & args -> V_62 , args -> V_42 , V_3 ) ;
if ( error ) {
args -> V_62 = NULL ;
F_39 ( args -> V_42 ) ;
goto V_70;
}
} else {
F_78 ( V_97 , & V_97 -> V_100 ) ;
}
F_76 ( V_97 ) ;
V_97 = NULL ;
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
goto V_70;
if ( args -> V_91 > 0 ) {
error = F_61 ( args ) ;
if ( error )
return error ;
}
if ( args -> V_31 & V_86 ) {
error = F_62 ( args ) ;
if ( error )
goto V_70;
args -> V_89 = args -> V_88 ;
args -> V_85 = args -> V_87 ;
args -> V_91 = args -> V_90 ;
args -> V_93 = args -> V_92 ;
args -> V_95 = args -> V_94 ;
if ( args -> V_91 ) {
error = F_63 ( args ) ;
if ( error )
return error ;
}
args -> V_5 |= V_104 ;
V_97 = F_73 () ;
V_97 -> args = args ;
V_97 -> V_36 = V_36 ;
V_97 -> V_105 = 0 ;
error = F_74 ( V_97 , & V_79 ) ;
if ( error )
goto V_70;
V_98 = & V_97 -> V_100 . V_98 [ V_97 -> V_100 . V_101 - 1 ] ;
ASSERT ( V_98 -> V_102 == V_103 ) ;
error = F_64 ( V_98 -> V_84 , args ) ;
F_78 ( V_97 , & V_97 -> V_100 ) ;
if ( V_79 && ( V_97 -> V_100 . V_101 > 1 ) ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_79 ( V_97 ) ;
if ( ! error )
error = F_38 ( & args -> V_62 ,
args -> V_42 , V_3 ) ;
if ( error ) {
args -> V_62 = NULL ;
F_39 ( args -> V_42 ) ;
goto V_70;
}
}
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
goto V_70;
} else if ( args -> V_91 > 0 ) {
error = F_67 ( args ) ;
if ( error )
goto V_70;
}
V_79 = error = 0 ;
V_70:
if ( V_97 )
F_76 ( V_97 ) ;
if ( error )
return error ;
return V_79 ;
}
STATIC int
F_48 ( T_3 * args )
{
T_5 * V_97 ;
T_6 * V_98 ;
T_4 * V_3 ;
struct V_83 * V_84 ;
int V_79 , error , V_78 ;
F_80 ( args ) ;
V_3 = args -> V_3 ;
V_97 = F_73 () ;
V_97 -> args = args ;
V_97 -> V_36 = V_3 -> V_8 ;
error = F_74 ( V_97 , & V_79 ) ;
if ( error || ( V_79 != - V_33 ) ) {
if ( error == 0 )
error = V_79 ;
goto V_70;
}
V_98 = & V_97 -> V_100 . V_98 [ V_97 -> V_100 . V_101 - 1 ] ;
ASSERT ( V_98 -> V_84 != NULL ) ;
ASSERT ( V_98 -> V_102 == V_103 ) ;
if ( args -> V_91 > 0 ) {
error = F_81 ( V_97 ) ;
if ( error )
goto V_70;
error = F_82 ( args ) ;
if ( error )
goto V_70;
error = F_63 ( args ) ;
if ( error )
goto V_70;
error = F_83 ( V_97 ) ;
if ( error )
goto V_70;
}
V_98 = & V_97 -> V_100 . V_98 [ V_97 -> V_100 . V_101 - 1 ] ;
ASSERT ( V_98 -> V_102 == V_103 ) ;
V_79 = F_64 ( V_98 -> V_84 , args ) ;
F_78 ( V_97 , & V_97 -> V_100 ) ;
if ( V_79 && ( V_97 -> V_100 . V_101 > 1 ) ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_79 ( V_97 ) ;
if ( ! error )
error = F_38 ( & args -> V_62 , args -> V_42 , V_3 ) ;
if ( error ) {
args -> V_62 = NULL ;
F_39 ( args -> V_42 ) ;
goto V_70;
}
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
goto V_70;
}
if ( F_8 ( V_3 , V_11 ) ) {
ASSERT ( V_97 -> V_100 . V_101 == 1 ) ;
ASSERT ( V_97 -> V_100 . V_98 [ 0 ] . V_84 ) ;
V_97 -> V_100 . V_98 [ 0 ] . V_84 = NULL ;
error = F_55 ( args -> V_62 , args -> V_3 , 0 , - 1 , & V_84 ) ;
if ( error )
goto V_70;
if ( ( V_78 = F_65 ( V_84 , V_3 ) ) ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_66 ( V_84 , args , V_78 ) ;
if ( ! error )
error = F_38 ( & args -> V_62 ,
args -> V_42 , V_3 ) ;
if ( error ) {
args -> V_62 = NULL ;
F_39 ( args -> V_42 ) ;
goto V_70;
}
} else
F_57 ( args -> V_62 , V_84 ) ;
}
error = 0 ;
V_70:
F_76 ( V_97 ) ;
return error ;
}
STATIC int
F_81 ( T_5 * V_97 )
{
T_8 * V_100 ;
T_6 * V_98 ;
int V_106 ;
F_84 ( V_97 -> args ) ;
V_100 = & V_97 -> V_100 ;
ASSERT ( ( V_100 -> V_101 >= 0 ) && ( V_100 -> V_101 < V_107 ) ) ;
for ( V_98 = V_100 -> V_98 , V_106 = 0 ; V_106 < V_100 -> V_101 ; V_98 ++ , V_106 ++ ) {
if ( V_98 -> V_84 ) {
V_98 -> V_108 = F_85 ( V_98 -> V_84 ) ;
V_98 -> V_84 = NULL ;
} else {
V_98 -> V_108 = 0 ;
}
}
V_100 = & V_97 -> V_109 ;
ASSERT ( ( V_100 -> V_101 >= 0 ) && ( V_100 -> V_101 < V_107 ) ) ;
for ( V_98 = V_100 -> V_98 , V_106 = 0 ; V_106 < V_100 -> V_101 ; V_98 ++ , V_106 ++ ) {
if ( V_98 -> V_84 ) {
V_98 -> V_108 = F_85 ( V_98 -> V_84 ) ;
V_98 -> V_84 = NULL ;
} else {
V_98 -> V_108 = 0 ;
}
}
return 0 ;
}
STATIC int
F_83 ( T_5 * V_97 )
{
T_8 * V_100 ;
T_6 * V_98 ;
int V_106 , error ;
F_86 ( V_97 -> args ) ;
V_100 = & V_97 -> V_100 ;
ASSERT ( ( V_100 -> V_101 >= 0 ) && ( V_100 -> V_101 < V_107 ) ) ;
for ( V_98 = V_100 -> V_98 , V_106 = 0 ; V_106 < V_100 -> V_101 ; V_98 ++ , V_106 ++ ) {
if ( V_98 -> V_108 ) {
error = F_87 ( V_97 -> args -> V_62 ,
V_97 -> args -> V_3 ,
V_98 -> V_85 , V_98 -> V_108 ,
& V_98 -> V_84 , V_11 ) ;
if ( error )
return error ;
} else {
V_98 -> V_84 = NULL ;
}
}
V_100 = & V_97 -> V_109 ;
ASSERT ( ( V_100 -> V_101 >= 0 ) && ( V_100 -> V_101 < V_107 ) ) ;
for ( V_98 = V_100 -> V_98 , V_106 = 0 ; V_106 < V_100 -> V_101 ; V_98 ++ , V_106 ++ ) {
if ( V_98 -> V_108 ) {
error = F_87 ( V_97 -> args -> V_62 ,
V_97 -> args -> V_3 ,
V_98 -> V_85 , V_98 -> V_108 ,
& V_98 -> V_84 , V_11 ) ;
if ( error )
return error ;
} else {
V_98 -> V_84 = NULL ;
}
}
return 0 ;
}
STATIC int
F_10 ( T_3 * args )
{
T_5 * V_97 ;
T_6 * V_98 ;
int error , V_79 ;
int V_110 ;
F_88 ( args ) ;
V_97 = F_73 () ;
V_97 -> args = args ;
V_97 -> V_36 = args -> V_3 -> V_8 ;
error = F_74 ( V_97 , & V_79 ) ;
if ( error ) {
V_79 = error ;
} else if ( V_79 == - V_33 ) {
V_98 = & V_97 -> V_100 . V_98 [ V_97 -> V_100 . V_101 - 1 ] ;
ASSERT ( V_98 -> V_84 != NULL ) ;
ASSERT ( V_98 -> V_102 == V_103 ) ;
V_79 = F_70 ( V_98 -> V_84 , args ) ;
if ( ! V_79 && ( args -> V_91 > 0 )
&& ! ( args -> V_5 & V_96 ) ) {
V_79 = F_71 ( args ) ;
}
}
for ( V_110 = 0 ; V_110 < V_97 -> V_100 . V_101 ; V_110 ++ ) {
F_57 ( args -> V_62 , V_97 -> V_100 . V_98 [ V_110 ] . V_84 ) ;
V_97 -> V_100 . V_98 [ V_110 ] . V_84 = NULL ;
}
F_76 ( V_97 ) ;
return V_79 ;
}
