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
if ( error )
goto V_70;
F_38 ( args . V_42 , V_3 ) ;
error = F_39 ( & args . V_62 , args . V_42 ) ;
if ( error )
goto V_70;
error = F_40 ( & args . V_62 , V_3 ) ;
if ( error )
goto V_71;
}
if ( F_8 ( V_3 , V_11 ) )
error = F_41 ( & args ) ;
else
error = F_42 ( & args ) ;
if ( error )
goto V_71;
if ( V_36 -> V_66 & V_67 )
F_33 ( args . V_62 ) ;
if ( ( V_5 & V_68 ) == 0 )
F_34 ( args . V_62 , V_3 , V_69 ) ;
F_43 ( args . V_62 , V_3 , V_72 ) ;
error = F_35 ( args . V_62 ) ;
F_15 ( V_3 , V_22 ) ;
return error ;
V_70:
F_44 ( & V_42 ) ;
args . V_62 = NULL ;
V_71:
if ( args . V_62 )
F_29 ( args . V_62 ) ;
F_15 ( V_3 , V_22 ) ;
return error ;
}
int
F_45 (
struct V_2 * V_3 ,
const unsigned char * V_4 ,
int V_5 )
{
struct V_35 * V_36 = V_3 -> V_8 ;
struct V_1 args ;
struct V_41 V_42 ;
T_2 V_45 ;
int error ;
F_12 ( V_36 , V_73 ) ;
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
error = F_26 ( V_36 , & F_25 ( V_36 ) -> V_74 ,
F_46 ( V_36 ) , 0 ,
( V_5 & V_47 ) ? V_61 : 0 ,
& args . V_62 ) ;
if ( error )
return error ;
F_27 ( V_3 , V_22 ) ;
F_30 ( args . V_62 , V_3 , 0 ) ;
if ( ! F_3 ( V_3 ) ) {
error = - V_23 ;
} else if ( V_3 -> V_17 . V_18 == V_24 ) {
ASSERT ( V_3 -> V_75 -> V_76 & V_77 ) ;
error = F_47 ( & args ) ;
} else if ( F_8 ( V_3 , V_11 ) ) {
error = F_48 ( & args ) ;
} else {
error = F_49 ( & args ) ;
}
if ( error )
goto V_71;
if ( V_36 -> V_66 & V_67 )
F_33 ( args . V_62 ) ;
if ( ( V_5 & V_68 ) == 0 )
F_34 ( args . V_62 , V_3 , V_69 ) ;
F_43 ( args . V_62 , V_3 , V_72 ) ;
error = F_35 ( args . V_62 ) ;
F_15 ( V_3 , V_22 ) ;
return error ;
V_71:
if ( args . V_62 )
F_29 ( args . V_62 ) ;
F_15 ( V_3 , V_22 ) ;
return error ;
}
STATIC int
F_32 ( T_3 * args )
{
int V_78 , V_79 , V_80 ;
F_50 ( args ) ;
V_80 = F_51 ( args ) ;
if ( ( args -> V_5 & V_81 ) && ( V_80 == - V_23 ) ) {
return V_80 ;
} else if ( V_80 == - V_33 ) {
if ( args -> V_5 & V_82 )
return V_80 ;
V_80 = F_47 ( args ) ;
ASSERT ( V_80 == 0 ) ;
}
if ( args -> V_12 >= V_83 ||
args -> V_30 >= V_83 )
return - V_65 ;
V_78 = F_52 ( args -> V_3 ) ;
V_78 += F_23 ( args -> V_12 , args -> V_30 ) ;
V_79 = F_53 ( args -> V_3 , V_78 ) ;
if ( ! V_79 )
return - V_65 ;
F_54 ( args , V_79 ) ;
return 0 ;
}
STATIC int
F_41 ( T_3 * args )
{
T_4 * V_3 ;
struct V_84 * V_85 ;
int V_80 , error , V_79 ;
F_55 ( args ) ;
V_3 = args -> V_3 ;
args -> V_86 = 0 ;
error = F_56 ( args -> V_62 , args -> V_3 , args -> V_86 , - 1 , & V_85 ) ;
if ( error )
return error ;
V_80 = F_57 ( V_85 , args ) ;
if ( ( args -> V_5 & V_81 ) && ( V_80 == - V_23 ) ) {
F_58 ( args -> V_62 , V_85 ) ;
return V_80 ;
} else if ( V_80 == - V_33 ) {
if ( args -> V_5 & V_82 ) {
F_58 ( args -> V_62 , V_85 ) ;
return V_80 ;
}
F_59 ( args ) ;
args -> V_31 |= V_87 ;
args -> V_88 = args -> V_86 ;
args -> V_89 = args -> V_90 ;
args -> V_91 = args -> V_92 ;
args -> V_93 = args -> V_94 ;
args -> V_95 = args -> V_96 ;
args -> V_92 = 0 ;
args -> V_94 = 0 ;
args -> V_96 = 0 ;
}
V_80 = F_60 ( V_85 , args ) ;
if ( V_80 == - V_65 ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_61 ( args ) ;
if ( error )
goto V_70;
F_38 ( args -> V_42 , V_3 ) ;
error = F_39 ( & args -> V_62 , args -> V_42 ) ;
if ( error )
goto V_70;
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
return error ;
error = F_42 ( args ) ;
return error ;
}
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
return error ;
if ( args -> V_92 > 0 ) {
error = F_62 ( args ) ;
if ( error )
return error ;
}
if ( args -> V_31 & V_87 ) {
error = F_63 ( args ) ;
if ( error )
return error ;
args -> V_90 = args -> V_89 ;
args -> V_86 = args -> V_88 ;
args -> V_92 = args -> V_91 ;
args -> V_94 = args -> V_93 ;
args -> V_96 = args -> V_95 ;
if ( args -> V_92 ) {
error = F_64 ( args ) ;
if ( error )
return error ;
}
error = F_56 ( args -> V_62 , args -> V_3 , args -> V_86 ,
- 1 , & V_85 ) ;
if ( error )
return error ;
F_65 ( V_85 , args ) ;
if ( ( V_79 = F_66 ( V_85 , V_3 ) ) ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_67 ( V_85 , args , V_79 ) ;
if ( error )
goto V_70;
F_38 ( args -> V_42 , V_3 ) ;
error = F_39 ( & args -> V_62 , args -> V_42 ) ;
if ( error )
goto V_70;
}
error = F_40 ( & args -> V_62 , V_3 ) ;
} else if ( args -> V_92 > 0 ) {
error = F_68 ( args ) ;
}
return error ;
V_70:
F_44 ( args -> V_42 ) ;
args -> V_62 = NULL ;
return error ;
}
STATIC int
F_48 ( T_3 * args )
{
T_4 * V_3 ;
struct V_84 * V_85 ;
int error , V_79 ;
F_69 ( args ) ;
V_3 = args -> V_3 ;
args -> V_86 = 0 ;
error = F_56 ( args -> V_62 , args -> V_3 , args -> V_86 , - 1 , & V_85 ) ;
if ( error )
return error ;
error = F_57 ( V_85 , args ) ;
if ( error == - V_23 ) {
F_58 ( args -> V_62 , V_85 ) ;
return error ;
}
F_65 ( V_85 , args ) ;
if ( ( V_79 = F_66 ( V_85 , V_3 ) ) ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_67 ( V_85 , args , V_79 ) ;
if ( error )
goto V_70;
F_38 ( args -> V_42 , V_3 ) ;
error = F_39 ( & args -> V_62 , args -> V_42 ) ;
if ( error )
goto V_70;
}
return 0 ;
V_70:
F_44 ( args -> V_42 ) ;
args -> V_62 = NULL ;
return error ;
}
STATIC int
F_9 ( T_3 * args )
{
struct V_84 * V_85 ;
int error ;
F_70 ( args ) ;
args -> V_86 = 0 ;
error = F_56 ( args -> V_62 , args -> V_3 , args -> V_86 , - 1 , & V_85 ) ;
if ( error )
return error ;
error = F_57 ( V_85 , args ) ;
if ( error != - V_33 ) {
F_58 ( args -> V_62 , V_85 ) ;
return error ;
}
error = F_71 ( V_85 , args ) ;
F_58 ( args -> V_62 , V_85 ) ;
if ( ! error && ( args -> V_92 > 0 ) && ! ( args -> V_5 & V_97 ) ) {
error = F_72 ( args ) ;
}
return error ;
}
STATIC int
F_42 ( T_3 * args )
{
T_5 * V_98 ;
T_6 * V_99 ;
T_4 * V_3 ;
T_7 * V_36 ;
int V_80 , error ;
F_73 ( args ) ;
V_3 = args -> V_3 ;
V_36 = V_3 -> V_8 ;
V_100:
V_98 = F_74 () ;
V_98 -> args = args ;
V_98 -> V_36 = V_36 ;
error = F_75 ( V_98 , & V_80 ) ;
if ( error )
goto V_71;
V_99 = & V_98 -> V_101 . V_99 [ V_98 -> V_101 . V_102 - 1 ] ;
ASSERT ( V_99 -> V_103 == V_104 ) ;
if ( ( args -> V_5 & V_81 ) && ( V_80 == - V_23 ) ) {
goto V_71;
} else if ( V_80 == - V_33 ) {
if ( args -> V_5 & V_82 )
goto V_71;
F_76 ( args ) ;
args -> V_31 |= V_87 ;
args -> V_88 = args -> V_86 ;
args -> V_89 = args -> V_90 ;
args -> V_91 = args -> V_92 ;
args -> V_93 = args -> V_94 ;
args -> V_95 = args -> V_96 ;
args -> V_92 = 0 ;
args -> V_94 = 0 ;
args -> V_96 = 0 ;
}
V_80 = F_60 ( V_99 -> V_85 , V_98 -> args ) ;
if ( V_80 == - V_65 ) {
if ( V_98 -> V_101 . V_102 == 1 ) {
F_77 ( V_98 ) ;
V_98 = NULL ;
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_61 ( args ) ;
if ( error )
goto V_70;
F_38 ( args -> V_42 , V_3 ) ;
error = F_39 ( & args -> V_62 , args -> V_42 ) ;
if ( error )
goto V_70;
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
goto V_71;
goto V_100;
}
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_78 ( V_98 ) ;
if ( error )
goto V_70;
F_38 ( args -> V_42 , V_3 ) ;
error = F_39 ( & args -> V_62 , args -> V_42 ) ;
if ( error )
goto V_70;
} else {
F_79 ( V_98 , & V_98 -> V_101 ) ;
}
F_77 ( V_98 ) ;
V_98 = NULL ;
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
goto V_71;
if ( args -> V_92 > 0 ) {
error = F_62 ( args ) ;
if ( error )
return error ;
}
if ( args -> V_31 & V_87 ) {
error = F_63 ( args ) ;
if ( error )
goto V_71;
args -> V_90 = args -> V_89 ;
args -> V_86 = args -> V_88 ;
args -> V_92 = args -> V_91 ;
args -> V_94 = args -> V_93 ;
args -> V_96 = args -> V_95 ;
if ( args -> V_92 ) {
error = F_64 ( args ) ;
if ( error )
return error ;
}
args -> V_5 |= V_105 ;
V_98 = F_74 () ;
V_98 -> args = args ;
V_98 -> V_36 = V_36 ;
V_98 -> V_106 = 0 ;
error = F_75 ( V_98 , & V_80 ) ;
if ( error )
goto V_71;
V_99 = & V_98 -> V_101 . V_99 [ V_98 -> V_101 . V_102 - 1 ] ;
ASSERT ( V_99 -> V_103 == V_104 ) ;
error = F_65 ( V_99 -> V_85 , args ) ;
F_79 ( V_98 , & V_98 -> V_101 ) ;
if ( V_80 && ( V_98 -> V_101 . V_102 > 1 ) ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_80 ( V_98 ) ;
if ( error )
goto V_70;
F_38 ( args -> V_42 , V_3 ) ;
error = F_39 ( & args -> V_62 , args -> V_42 ) ;
if ( error )
goto V_70;
}
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
goto V_71;
} else if ( args -> V_92 > 0 ) {
error = F_68 ( args ) ;
if ( error )
goto V_71;
}
V_80 = error = 0 ;
V_71:
if ( V_98 )
F_77 ( V_98 ) ;
if ( error )
return error ;
return V_80 ;
V_70:
F_44 ( args -> V_42 ) ;
args -> V_62 = NULL ;
goto V_71;
}
STATIC int
F_49 ( T_3 * args )
{
T_5 * V_98 ;
T_6 * V_99 ;
T_4 * V_3 ;
struct V_84 * V_85 ;
int V_80 , error , V_79 ;
F_81 ( args ) ;
V_3 = args -> V_3 ;
V_98 = F_74 () ;
V_98 -> args = args ;
V_98 -> V_36 = V_3 -> V_8 ;
error = F_75 ( V_98 , & V_80 ) ;
if ( error || ( V_80 != - V_33 ) ) {
if ( error == 0 )
error = V_80 ;
goto V_71;
}
V_99 = & V_98 -> V_101 . V_99 [ V_98 -> V_101 . V_102 - 1 ] ;
ASSERT ( V_99 -> V_85 != NULL ) ;
ASSERT ( V_99 -> V_103 == V_104 ) ;
if ( args -> V_92 > 0 ) {
error = F_82 ( V_98 ) ;
if ( error )
goto V_71;
error = F_83 ( args ) ;
if ( error )
goto V_71;
error = F_64 ( args ) ;
if ( error )
goto V_71;
error = F_84 ( V_98 ) ;
if ( error )
goto V_71;
}
V_99 = & V_98 -> V_101 . V_99 [ V_98 -> V_101 . V_102 - 1 ] ;
ASSERT ( V_99 -> V_103 == V_104 ) ;
V_80 = F_65 ( V_99 -> V_85 , args ) ;
F_79 ( V_98 , & V_98 -> V_101 ) ;
if ( V_80 && ( V_98 -> V_101 . V_102 > 1 ) ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_80 ( V_98 ) ;
if ( error )
goto V_70;
F_38 ( args -> V_42 , V_3 ) ;
error = F_39 ( & args -> V_62 , args -> V_42 ) ;
if ( error )
goto V_70;
error = F_40 ( & args -> V_62 , V_3 ) ;
if ( error )
goto V_71;
}
if ( F_8 ( V_3 , V_11 ) ) {
ASSERT ( V_98 -> V_101 . V_102 == 1 ) ;
ASSERT ( V_98 -> V_101 . V_99 [ 0 ] . V_85 ) ;
V_98 -> V_101 . V_99 [ 0 ] . V_85 = NULL ;
error = F_56 ( args -> V_62 , args -> V_3 , 0 , - 1 , & V_85 ) ;
if ( error )
goto V_71;
if ( ( V_79 = F_66 ( V_85 , V_3 ) ) ) {
F_36 ( args -> V_42 , args -> V_45 ) ;
error = F_67 ( V_85 , args , V_79 ) ;
if ( error )
goto V_70;
F_38 ( args -> V_42 , V_3 ) ;
error = F_39 ( & args -> V_62 , args -> V_42 ) ;
if ( error )
goto V_70;
} else
F_58 ( args -> V_62 , V_85 ) ;
}
error = 0 ;
V_71:
F_77 ( V_98 ) ;
return error ;
V_70:
F_44 ( args -> V_42 ) ;
args -> V_62 = NULL ;
goto V_71;
}
STATIC int
F_82 ( T_5 * V_98 )
{
T_8 * V_101 ;
T_6 * V_99 ;
int V_107 ;
F_85 ( V_98 -> args ) ;
V_101 = & V_98 -> V_101 ;
ASSERT ( ( V_101 -> V_102 >= 0 ) && ( V_101 -> V_102 < V_108 ) ) ;
for ( V_99 = V_101 -> V_99 , V_107 = 0 ; V_107 < V_101 -> V_102 ; V_99 ++ , V_107 ++ ) {
if ( V_99 -> V_85 ) {
V_99 -> V_109 = F_86 ( V_99 -> V_85 ) ;
V_99 -> V_85 = NULL ;
} else {
V_99 -> V_109 = 0 ;
}
}
V_101 = & V_98 -> V_110 ;
ASSERT ( ( V_101 -> V_102 >= 0 ) && ( V_101 -> V_102 < V_108 ) ) ;
for ( V_99 = V_101 -> V_99 , V_107 = 0 ; V_107 < V_101 -> V_102 ; V_99 ++ , V_107 ++ ) {
if ( V_99 -> V_85 ) {
V_99 -> V_109 = F_86 ( V_99 -> V_85 ) ;
V_99 -> V_85 = NULL ;
} else {
V_99 -> V_109 = 0 ;
}
}
return 0 ;
}
STATIC int
F_84 ( T_5 * V_98 )
{
T_8 * V_101 ;
T_6 * V_99 ;
int V_107 , error ;
F_87 ( V_98 -> args ) ;
V_101 = & V_98 -> V_101 ;
ASSERT ( ( V_101 -> V_102 >= 0 ) && ( V_101 -> V_102 < V_108 ) ) ;
for ( V_99 = V_101 -> V_99 , V_107 = 0 ; V_107 < V_101 -> V_102 ; V_99 ++ , V_107 ++ ) {
if ( V_99 -> V_109 ) {
error = F_88 ( V_98 -> args -> V_62 ,
V_98 -> args -> V_3 ,
V_99 -> V_86 , V_99 -> V_109 ,
& V_99 -> V_85 , V_11 ) ;
if ( error )
return error ;
} else {
V_99 -> V_85 = NULL ;
}
}
V_101 = & V_98 -> V_110 ;
ASSERT ( ( V_101 -> V_102 >= 0 ) && ( V_101 -> V_102 < V_108 ) ) ;
for ( V_99 = V_101 -> V_99 , V_107 = 0 ; V_107 < V_101 -> V_102 ; V_99 ++ , V_107 ++ ) {
if ( V_99 -> V_109 ) {
error = F_88 ( V_98 -> args -> V_62 ,
V_98 -> args -> V_3 ,
V_99 -> V_86 , V_99 -> V_109 ,
& V_99 -> V_85 , V_11 ) ;
if ( error )
return error ;
} else {
V_99 -> V_85 = NULL ;
}
}
return 0 ;
}
STATIC int
F_10 ( T_3 * args )
{
T_5 * V_98 ;
T_6 * V_99 ;
int error , V_80 ;
int V_111 ;
F_89 ( args ) ;
V_98 = F_74 () ;
V_98 -> args = args ;
V_98 -> V_36 = args -> V_3 -> V_8 ;
error = F_75 ( V_98 , & V_80 ) ;
if ( error ) {
V_80 = error ;
} else if ( V_80 == - V_33 ) {
V_99 = & V_98 -> V_101 . V_99 [ V_98 -> V_101 . V_102 - 1 ] ;
ASSERT ( V_99 -> V_85 != NULL ) ;
ASSERT ( V_99 -> V_103 == V_104 ) ;
V_80 = F_71 ( V_99 -> V_85 , args ) ;
if ( ! V_80 && ( args -> V_92 > 0 )
&& ! ( args -> V_5 & V_97 ) ) {
V_80 = F_72 ( args ) ;
}
}
for ( V_111 = 0 ; V_111 < V_98 -> V_101 . V_102 ; V_111 ++ ) {
F_58 ( args -> V_62 , V_98 -> V_101 . V_99 [ V_111 ] . V_85 ) ;
V_98 -> V_101 . V_99 [ V_111 ] . V_85 = NULL ;
}
F_77 ( V_98 ) ;
return V_80 ;
}
