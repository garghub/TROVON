STATIC int
F_1 (
struct V_1 * V_2 ,
const unsigned char * V_3 )
{
if ( ! V_3 )
return V_4 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_6 = strlen ( ( char * ) V_3 ) ;
if ( V_2 -> V_6 >= V_7 )
return V_8 ;
return 0 ;
}
int
F_2 (
struct V_9 * V_10 )
{
if ( ! F_3 ( V_10 ) ||
( V_10 -> V_11 . V_12 == V_13 &&
V_10 -> V_11 . V_14 == 0 ) )
return 0 ;
return 1 ;
}
STATIC int
F_4 (
struct V_9 * V_10 ,
struct V_1 * V_5 ,
unsigned char * V_15 ,
int * V_16 ,
int V_17 )
{
T_1 args ;
int error ;
if ( ! F_2 ( V_10 ) )
return V_18 ;
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_5 = V_5 -> V_5 ;
args . V_19 = V_5 -> V_6 ;
args . V_15 = V_15 ;
args . V_20 = * V_16 ;
args . V_17 = V_17 ;
args . V_21 = F_5 ( args . V_5 , args . V_19 ) ;
args . V_22 = V_10 ;
args . V_23 = V_24 ;
if ( V_10 -> V_11 . V_12 == V_25 ) {
error = F_6 ( & args ) ;
} else if ( F_7 ( V_10 , V_24 ) ) {
error = F_8 ( & args ) ;
} else {
error = F_9 ( & args ) ;
}
* V_16 = args . V_20 ;
if ( error == V_26 )
error = 0 ;
return ( error ) ;
}
int
F_10 (
T_2 * V_10 ,
const unsigned char * V_5 ,
unsigned char * V_15 ,
int * V_16 ,
int V_17 )
{
int error ;
struct V_1 V_2 ;
F_11 ( V_27 ) ;
if ( F_12 ( V_10 -> V_28 ) )
return ( V_29 ) ;
error = F_1 ( & V_2 , V_5 ) ;
if ( error )
return error ;
F_13 ( V_10 , V_30 ) ;
error = F_4 ( V_10 , & V_2 , V_15 , V_16 , V_17 ) ;
F_14 ( V_10 , V_30 ) ;
return ( error ) ;
}
STATIC int
F_15 (
struct V_9 * V_10 ,
int V_19 ,
int V_20 ,
int * V_31 )
{
struct V_32 * V_33 = V_10 -> V_28 ;
int V_34 ;
int V_35 ;
V_34 = F_16 ( V_19 , V_20 ,
V_33 -> V_36 . V_37 , V_31 ) ;
V_35 = F_17 ( V_33 , V_24 ) ;
if ( * V_31 ) {
if ( V_34 > ( V_33 -> V_36 . V_37 >> 1 ) ) {
V_35 *= 2 ;
}
} else {
T_3 V_38 = F_18 ( V_33 , V_20 ) ;
V_35 += V_38 ;
V_35 += F_19 ( V_33 , V_38 , V_24 ) ;
}
return V_35 ;
}
STATIC int
F_20 (
struct V_9 * V_22 ,
struct V_1 * V_5 ,
unsigned char * V_15 ,
int V_20 ,
int V_17 )
{
T_1 args ;
T_4 V_39 ;
T_5 V_40 ;
int error , V_41 , V_42 ;
struct V_32 * V_33 = V_22 -> V_28 ;
struct V_43 V_44 ;
int V_45 = ( V_17 & V_46 ) != 0 ;
int V_31 ;
error = F_21 ( V_22 , 0 ) ;
if ( error )
return error ;
if ( F_3 ( V_22 ) == 0 ) {
int V_47 = sizeof( V_48 ) +
F_22 ( V_5 -> V_6 , V_20 ) ;
if ( ( error = F_23 ( V_22 , V_47 , V_45 ) ) )
return ( error ) ;
}
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_5 = V_5 -> V_5 ;
args . V_19 = V_5 -> V_6 ;
args . V_15 = V_15 ;
args . V_20 = V_20 ;
args . V_17 = V_17 ;
args . V_21 = F_5 ( args . V_5 , args . V_19 ) ;
args . V_22 = V_22 ;
args . V_39 = & V_39 ;
args . V_40 = & V_40 ;
args . V_23 = V_24 ;
args . V_49 = V_50 | V_51 ;
args . V_52 = F_15 ( V_22 , V_5 -> V_6 , V_20 , & V_31 ) ;
args . V_53 = F_24 ( V_33 , V_54 ) ;
if ( V_45 )
args . V_53 -> V_55 |= V_56 ;
V_44 . V_57 = F_25 ( V_33 ) -> V_58 . V_57 +
F_25 ( V_33 ) -> V_59 . V_57 * args . V_52 ;
V_44 . V_60 = V_61 ;
V_44 . V_62 = V_63 ;
error = F_26 ( args . V_53 , & V_44 , args . V_52 , 0 ) ;
if ( error ) {
F_27 ( args . V_53 , 0 ) ;
return ( error ) ;
}
F_13 ( V_22 , V_64 ) ;
error = F_28 ( args . V_53 , V_22 , args . V_52 , 0 ,
V_45 ? V_65 | V_66 :
V_65 ) ;
if ( error ) {
F_14 ( V_22 , V_64 ) ;
F_27 ( args . V_53 , V_67 ) ;
return ( error ) ;
}
F_29 ( args . V_53 , V_22 , 0 ) ;
if ( ( V_22 -> V_11 . V_12 == V_25 ) ||
( ( V_22 -> V_11 . V_12 == V_13 ) &&
( V_22 -> V_11 . V_14 == 0 ) ) ) {
if ( V_22 -> V_11 . V_12 == V_13 )
F_30 ( & args ) ;
error = F_31 ( & args ) ;
if ( error != V_68 ) {
ASSERT ( args . V_53 != NULL ) ;
if ( V_33 -> V_69 & V_70 ) {
F_32 ( args . V_53 ) ;
}
if ( ! error && ( V_17 & V_71 ) == 0 ) {
F_33 ( args . V_53 , V_22 ,
V_72 ) ;
}
V_41 = F_34 ( args . V_53 ,
V_67 ) ;
F_14 ( V_22 , V_64 ) ;
return ( error == 0 ? V_41 : error ) ;
}
F_35 ( args . V_40 , args . V_39 ) ;
error = F_36 ( & args ) ;
if ( ! error ) {
error = F_37 ( & args . V_53 , args . V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args . V_53 = NULL ;
F_38 ( & V_40 ) ;
goto V_73;
}
if ( V_42 )
F_29 ( args . V_53 , V_22 , 0 ) ;
error = F_39 ( & args . V_53 , V_22 ) ;
if ( error )
goto V_73;
}
if ( F_7 ( V_22 , V_24 ) ) {
error = F_40 ( & args ) ;
} else {
error = F_41 ( & args ) ;
}
if ( error ) {
goto V_73;
}
if ( V_33 -> V_69 & V_70 ) {
F_32 ( args . V_53 ) ;
}
if ( ( V_17 & V_71 ) == 0 )
F_33 ( args . V_53 , V_22 , V_72 ) ;
F_42 ( args . V_53 , V_22 , V_74 ) ;
error = F_34 ( args . V_53 , V_67 ) ;
F_14 ( V_22 , V_64 ) ;
return ( error ) ;
V_73:
if ( args . V_53 )
F_27 ( args . V_53 ,
V_67 | V_75 ) ;
F_14 ( V_22 , V_64 ) ;
return ( error ) ;
}
int
F_43 (
T_2 * V_22 ,
const unsigned char * V_5 ,
unsigned char * V_15 ,
int V_20 ,
int V_17 )
{
int error ;
struct V_1 V_2 ;
F_11 ( V_76 ) ;
if ( F_12 ( V_22 -> V_28 ) )
return ( V_29 ) ;
error = F_1 ( & V_2 , V_5 ) ;
if ( error )
return error ;
return F_20 ( V_22 , & V_2 , V_15 , V_20 , V_17 ) ;
}
STATIC int
F_44 ( T_2 * V_22 , struct V_1 * V_5 , int V_17 )
{
T_1 args ;
T_4 V_39 ;
T_5 V_40 ;
int error ;
T_6 * V_33 = V_22 -> V_28 ;
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_5 = V_5 -> V_5 ;
args . V_19 = V_5 -> V_6 ;
args . V_17 = V_17 ;
args . V_21 = F_5 ( args . V_5 , args . V_19 ) ;
args . V_22 = V_22 ;
args . V_39 = & V_39 ;
args . V_40 = & V_40 ;
args . V_52 = 0 ;
args . V_23 = V_24 ;
args . V_49 = V_51 ;
error = F_21 ( V_22 , 0 ) ;
if ( error )
return error ;
args . V_53 = F_24 ( V_33 , V_77 ) ;
if ( V_17 & V_46 )
args . V_53 -> V_55 |= V_56 ;
error = F_26 ( args . V_53 , & F_25 ( V_33 ) -> V_78 ,
F_45 ( V_33 ) , 0 ) ;
if ( error ) {
F_27 ( args . V_53 , 0 ) ;
return ( error ) ;
}
F_13 ( V_22 , V_64 ) ;
F_29 ( args . V_53 , V_22 , 0 ) ;
if ( ! F_2 ( V_22 ) ) {
error = F_46 ( V_18 ) ;
goto V_73;
}
if ( V_22 -> V_11 . V_12 == V_25 ) {
ASSERT ( V_22 -> V_79 -> V_80 & V_81 ) ;
error = F_47 ( & args ) ;
if ( error ) {
goto V_73;
}
} else if ( F_7 ( V_22 , V_24 ) ) {
error = F_48 ( & args ) ;
} else {
error = F_49 ( & args ) ;
}
if ( error ) {
goto V_73;
}
if ( V_33 -> V_69 & V_70 ) {
F_32 ( args . V_53 ) ;
}
if ( ( V_17 & V_71 ) == 0 )
F_33 ( args . V_53 , V_22 , V_72 ) ;
F_42 ( args . V_53 , V_22 , V_74 ) ;
error = F_34 ( args . V_53 , V_67 ) ;
F_14 ( V_22 , V_64 ) ;
return ( error ) ;
V_73:
if ( args . V_53 )
F_27 ( args . V_53 ,
V_67 | V_75 ) ;
F_14 ( V_22 , V_64 ) ;
return ( error ) ;
}
int
F_50 (
T_2 * V_22 ,
const unsigned char * V_5 ,
int V_17 )
{
int error ;
struct V_1 V_2 ;
F_11 ( V_82 ) ;
if ( F_12 ( V_22 -> V_28 ) )
return ( V_29 ) ;
error = F_1 ( & V_2 , V_5 ) ;
if ( error )
return error ;
F_13 ( V_22 , V_30 ) ;
if ( ! F_2 ( V_22 ) ) {
F_14 ( V_22 , V_30 ) ;
return F_46 ( V_18 ) ;
}
F_14 ( V_22 , V_30 ) ;
return F_44 ( V_22 , & V_2 , V_17 ) ;
}
STATIC int
F_31 ( T_1 * args )
{
int V_83 , V_84 , V_85 ;
F_51 ( args ) ;
V_85 = F_52 ( args ) ;
if ( ( args -> V_17 & V_86 ) && ( V_85 == V_18 ) ) {
return ( V_85 ) ;
} else if ( V_85 == V_26 ) {
if ( args -> V_17 & V_87 )
return ( V_85 ) ;
V_85 = F_47 ( args ) ;
ASSERT ( V_85 == 0 ) ;
}
if ( args -> V_19 >= V_88 ||
args -> V_20 >= V_88 )
return ( F_46 ( V_68 ) ) ;
V_83 = F_53 ( args -> V_22 ) ;
V_83 += F_22 ( args -> V_19 , args -> V_20 ) ;
V_84 = F_54 ( args -> V_22 , V_83 ) ;
if ( ! V_84 )
return ( F_46 ( V_68 ) ) ;
F_55 ( args , V_84 ) ;
return ( 0 ) ;
}
STATIC int
F_40 ( T_1 * args )
{
T_2 * V_22 ;
struct V_89 * V_90 ;
int V_85 , error , V_42 , V_84 ;
F_56 ( args ) ;
V_22 = args -> V_22 ;
args -> V_91 = 0 ;
error = F_57 ( args -> V_53 , args -> V_22 , args -> V_91 , - 1 , & V_90 ) ;
if ( error )
return error ;
V_85 = F_58 ( V_90 , args ) ;
if ( ( args -> V_17 & V_86 ) && ( V_85 == V_18 ) ) {
F_59 ( args -> V_53 , V_90 ) ;
return V_85 ;
} else if ( V_85 == V_26 ) {
if ( args -> V_17 & V_87 ) {
F_59 ( args -> V_53 , V_90 ) ;
return V_85 ;
}
F_60 ( args ) ;
args -> V_49 |= V_92 ;
args -> V_93 = args -> V_91 ;
args -> V_94 = args -> V_95 ;
args -> V_96 = args -> V_97 ;
args -> V_98 = args -> V_99 ;
}
V_85 = F_61 ( V_90 , args ) ;
if ( V_85 == V_68 ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_62 ( args ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
return ( error ) ;
}
if ( V_42 )
F_29 ( args -> V_53 , V_22 , 0 ) ;
error = F_39 ( & args -> V_53 , V_22 ) ;
if ( error )
return ( error ) ;
error = F_41 ( args ) ;
return ( error ) ;
}
error = F_39 ( & args -> V_53 , V_22 ) ;
if ( error )
return ( error ) ;
if ( args -> V_97 > 0 ) {
error = F_63 ( args ) ;
if ( error )
return ( error ) ;
}
if ( args -> V_49 & V_92 ) {
error = F_64 ( args ) ;
if ( error )
return ( error ) ;
args -> V_95 = args -> V_94 ;
args -> V_91 = args -> V_93 ;
args -> V_97 = args -> V_96 ;
args -> V_99 = args -> V_98 ;
if ( args -> V_97 ) {
error = F_65 ( args ) ;
if ( error )
return ( error ) ;
}
error = F_57 ( args -> V_53 , args -> V_22 , args -> V_91 ,
- 1 , & V_90 ) ;
if ( error )
return error ;
F_66 ( V_90 , args ) ;
if ( ( V_84 = F_67 ( V_90 , V_22 ) ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_68 ( V_90 , args , V_84 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
return ( error ) ;
}
if ( V_42 )
F_29 ( args -> V_53 , V_22 , 0 ) ;
}
error = F_39 ( & args -> V_53 , V_22 ) ;
} else if ( args -> V_97 > 0 ) {
error = F_69 ( args ) ;
}
return error ;
}
STATIC int
F_48 ( T_1 * args )
{
T_2 * V_22 ;
struct V_89 * V_90 ;
int error , V_42 , V_84 ;
F_70 ( args ) ;
V_22 = args -> V_22 ;
args -> V_91 = 0 ;
error = F_57 ( args -> V_53 , args -> V_22 , args -> V_91 , - 1 , & V_90 ) ;
if ( error )
return error ;
error = F_58 ( V_90 , args ) ;
if ( error == V_18 ) {
F_59 ( args -> V_53 , V_90 ) ;
return error ;
}
F_66 ( V_90 , args ) ;
if ( ( V_84 = F_67 ( V_90 , V_22 ) ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_68 ( V_90 , args , V_84 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
return error ;
}
if ( V_42 )
F_29 ( args -> V_53 , V_22 , 0 ) ;
}
return 0 ;
}
STATIC int
F_8 ( T_1 * args )
{
struct V_89 * V_90 ;
int error ;
F_71 ( args ) ;
args -> V_91 = 0 ;
error = F_57 ( args -> V_53 , args -> V_22 , args -> V_91 , - 1 , & V_90 ) ;
if ( error )
return error ;
error = F_58 ( V_90 , args ) ;
if ( error != V_26 ) {
F_59 ( args -> V_53 , V_90 ) ;
return error ;
}
error = F_72 ( V_90 , args ) ;
F_59 ( args -> V_53 , V_90 ) ;
if ( ! error && ( args -> V_97 > 0 ) && ! ( args -> V_17 & V_100 ) ) {
error = F_73 ( args ) ;
}
return error ;
}
STATIC int
F_41 ( T_1 * args )
{
T_7 * V_101 ;
T_8 * V_102 ;
T_2 * V_22 ;
T_6 * V_33 ;
int V_42 , V_85 , error ;
F_74 ( args ) ;
V_22 = args -> V_22 ;
V_33 = V_22 -> V_28 ;
V_103:
V_101 = F_75 () ;
V_101 -> args = args ;
V_101 -> V_33 = V_33 ;
V_101 -> V_104 = V_101 -> V_33 -> V_36 . V_37 ;
V_101 -> V_105 = V_101 -> V_33 -> V_106 ;
error = F_76 ( V_101 , & V_85 ) ;
if ( error )
goto V_73;
V_102 = & V_101 -> V_107 . V_102 [ V_101 -> V_107 . V_108 - 1 ] ;
ASSERT ( V_102 -> V_109 == V_110 ) ;
if ( ( args -> V_17 & V_86 ) && ( V_85 == V_18 ) ) {
goto V_73;
} else if ( V_85 == V_26 ) {
if ( args -> V_17 & V_87 )
goto V_73;
F_77 ( args ) ;
args -> V_49 |= V_92 ;
args -> V_93 = args -> V_91 ;
args -> V_94 = args -> V_95 ;
args -> V_96 = args -> V_97 ;
args -> V_98 = args -> V_99 ;
args -> V_97 = 0 ;
args -> V_99 = 0 ;
}
V_85 = F_61 ( V_102 -> V_90 , V_101 -> args ) ;
if ( V_85 == V_68 ) {
if ( V_101 -> V_107 . V_108 == 1 ) {
F_78 ( V_101 ) ;
V_101 = NULL ;
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_62 ( args ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_73;
}
if ( V_42 )
F_29 ( args -> V_53 , V_22 , 0 ) ;
error = F_39 ( & args -> V_53 , V_22 ) ;
if ( error )
goto V_73;
goto V_103;
}
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_79 ( V_101 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_73;
}
if ( V_42 )
F_29 ( args -> V_53 , V_22 , 0 ) ;
} else {
F_80 ( V_101 , & V_101 -> V_107 ) ;
}
F_78 ( V_101 ) ;
V_101 = NULL ;
error = F_39 ( & args -> V_53 , V_22 ) ;
if ( error )
goto V_73;
if ( args -> V_97 > 0 ) {
error = F_63 ( args ) ;
if ( error )
return ( error ) ;
}
if ( args -> V_49 & V_92 ) {
error = F_64 ( args ) ;
if ( error )
goto V_73;
args -> V_95 = args -> V_94 ;
args -> V_91 = args -> V_93 ;
args -> V_97 = args -> V_96 ;
args -> V_99 = args -> V_98 ;
if ( args -> V_97 ) {
error = F_65 ( args ) ;
if ( error )
return ( error ) ;
}
args -> V_17 |= V_111 ;
V_101 = F_75 () ;
V_101 -> args = args ;
V_101 -> V_33 = V_33 ;
V_101 -> V_104 = V_101 -> V_33 -> V_36 . V_37 ;
V_101 -> V_105 = V_101 -> V_33 -> V_106 ;
V_101 -> V_112 = 0 ;
error = F_76 ( V_101 , & V_85 ) ;
if ( error )
goto V_73;
V_102 = & V_101 -> V_107 . V_102 [ V_101 -> V_107 . V_108 - 1 ] ;
ASSERT ( V_102 -> V_109 == V_110 ) ;
error = F_66 ( V_102 -> V_90 , args ) ;
F_80 ( V_101 , & V_101 -> V_107 ) ;
if ( V_85 && ( V_101 -> V_107 . V_108 > 1 ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_81 ( V_101 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_73;
}
if ( V_42 )
F_29 ( args -> V_53 , V_22 , 0 ) ;
}
error = F_39 ( & args -> V_53 , V_22 ) ;
if ( error )
goto V_73;
} else if ( args -> V_97 > 0 ) {
error = F_69 ( args ) ;
if ( error )
goto V_73;
}
V_85 = error = 0 ;
V_73:
if ( V_101 )
F_78 ( V_101 ) ;
if ( error )
return ( error ) ;
return ( V_85 ) ;
}
STATIC int
F_49 ( T_1 * args )
{
T_7 * V_101 ;
T_8 * V_102 ;
T_2 * V_22 ;
struct V_89 * V_90 ;
int V_85 , error , V_42 , V_84 ;
F_82 ( args ) ;
V_22 = args -> V_22 ;
V_101 = F_75 () ;
V_101 -> args = args ;
V_101 -> V_33 = V_22 -> V_28 ;
V_101 -> V_104 = V_101 -> V_33 -> V_36 . V_37 ;
V_101 -> V_105 = V_101 -> V_33 -> V_106 ;
error = F_76 ( V_101 , & V_85 ) ;
if ( error || ( V_85 != V_26 ) ) {
if ( error == 0 )
error = V_85 ;
goto V_73;
}
V_102 = & V_101 -> V_107 . V_102 [ V_101 -> V_107 . V_108 - 1 ] ;
ASSERT ( V_102 -> V_90 != NULL ) ;
ASSERT ( V_102 -> V_109 == V_110 ) ;
if ( args -> V_97 > 0 ) {
error = F_83 ( V_101 ) ;
if ( error )
goto V_73;
error = F_84 ( args ) ;
if ( error )
goto V_73;
error = F_65 ( args ) ;
if ( error )
goto V_73;
error = F_85 ( V_101 ) ;
if ( error )
goto V_73;
}
V_102 = & V_101 -> V_107 . V_102 [ V_101 -> V_107 . V_108 - 1 ] ;
ASSERT ( V_102 -> V_109 == V_110 ) ;
V_85 = F_66 ( V_102 -> V_90 , args ) ;
F_80 ( V_101 , & V_101 -> V_107 ) ;
if ( V_85 && ( V_101 -> V_107 . V_108 > 1 ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_81 ( V_101 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_73;
}
if ( V_42 )
F_29 ( args -> V_53 , V_22 , 0 ) ;
error = F_39 ( & args -> V_53 , V_22 ) ;
if ( error )
goto V_73;
}
if ( F_7 ( V_22 , V_24 ) ) {
ASSERT ( V_101 -> V_107 . V_108 == 1 ) ;
ASSERT ( V_101 -> V_107 . V_102 [ 0 ] . V_90 ) ;
V_101 -> V_107 . V_102 [ 0 ] . V_90 = NULL ;
error = F_57 ( args -> V_53 , args -> V_22 , 0 , - 1 , & V_90 ) ;
if ( error )
goto V_73;
if ( ( V_84 = F_67 ( V_90 , V_22 ) ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_68 ( V_90 , args , V_84 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_53 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_53 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_73;
}
if ( V_42 )
F_29 ( args -> V_53 , V_22 , 0 ) ;
} else
F_59 ( args -> V_53 , V_90 ) ;
}
error = 0 ;
V_73:
F_78 ( V_101 ) ;
return ( error ) ;
}
STATIC int
F_83 ( T_7 * V_101 )
{
T_9 * V_107 ;
T_8 * V_102 ;
int V_113 ;
F_86 ( V_101 -> args ) ;
V_107 = & V_101 -> V_107 ;
ASSERT ( ( V_107 -> V_108 >= 0 ) && ( V_107 -> V_108 < V_114 ) ) ;
for ( V_102 = V_107 -> V_102 , V_113 = 0 ; V_113 < V_107 -> V_108 ; V_102 ++ , V_113 ++ ) {
if ( V_102 -> V_90 ) {
V_102 -> V_115 = F_87 ( V_102 -> V_90 ) ;
V_102 -> V_90 = NULL ;
} else {
V_102 -> V_115 = 0 ;
}
}
V_107 = & V_101 -> V_116 ;
ASSERT ( ( V_107 -> V_108 >= 0 ) && ( V_107 -> V_108 < V_114 ) ) ;
for ( V_102 = V_107 -> V_102 , V_113 = 0 ; V_113 < V_107 -> V_108 ; V_102 ++ , V_113 ++ ) {
if ( V_102 -> V_90 ) {
V_102 -> V_115 = F_87 ( V_102 -> V_90 ) ;
V_102 -> V_90 = NULL ;
} else {
V_102 -> V_115 = 0 ;
}
}
return ( 0 ) ;
}
STATIC int
F_85 ( T_7 * V_101 )
{
T_9 * V_107 ;
T_8 * V_102 ;
int V_113 , error ;
F_88 ( V_101 -> args ) ;
V_107 = & V_101 -> V_107 ;
ASSERT ( ( V_107 -> V_108 >= 0 ) && ( V_107 -> V_108 < V_114 ) ) ;
for ( V_102 = V_107 -> V_102 , V_113 = 0 ; V_113 < V_107 -> V_108 ; V_102 ++ , V_113 ++ ) {
if ( V_102 -> V_115 ) {
error = F_89 ( V_101 -> args -> V_53 ,
V_101 -> args -> V_22 ,
V_102 -> V_91 , V_102 -> V_115 ,
& V_102 -> V_90 , V_24 ) ;
if ( error )
return ( error ) ;
} else {
V_102 -> V_90 = NULL ;
}
}
V_107 = & V_101 -> V_116 ;
ASSERT ( ( V_107 -> V_108 >= 0 ) && ( V_107 -> V_108 < V_114 ) ) ;
for ( V_102 = V_107 -> V_102 , V_113 = 0 ; V_113 < V_107 -> V_108 ; V_102 ++ , V_113 ++ ) {
if ( V_102 -> V_115 ) {
error = F_89 ( V_101 -> args -> V_53 ,
V_101 -> args -> V_22 ,
V_102 -> V_91 , V_102 -> V_115 ,
& V_102 -> V_90 , V_24 ) ;
if ( error )
return ( error ) ;
} else {
V_102 -> V_90 = NULL ;
}
}
return ( 0 ) ;
}
STATIC int
F_9 ( T_1 * args )
{
T_7 * V_101 ;
T_8 * V_102 ;
int error , V_85 ;
int V_117 ;
F_90 ( args ) ;
V_101 = F_75 () ;
V_101 -> args = args ;
V_101 -> V_33 = args -> V_22 -> V_28 ;
V_101 -> V_104 = V_101 -> V_33 -> V_36 . V_37 ;
V_101 -> V_105 = V_101 -> V_33 -> V_106 ;
error = F_76 ( V_101 , & V_85 ) ;
if ( error ) {
V_85 = error ;
} else if ( V_85 == V_26 ) {
V_102 = & V_101 -> V_107 . V_102 [ V_101 -> V_107 . V_108 - 1 ] ;
ASSERT ( V_102 -> V_90 != NULL ) ;
ASSERT ( V_102 -> V_109 == V_110 ) ;
V_85 = F_72 ( V_102 -> V_90 , args ) ;
if ( ! V_85 && ( args -> V_97 > 0 )
&& ! ( args -> V_17 & V_100 ) ) {
V_85 = F_73 ( args ) ;
}
}
for ( V_117 = 0 ; V_117 < V_101 -> V_107 . V_108 ; V_117 ++ ) {
F_59 ( args -> V_53 , V_101 -> V_107 . V_102 [ V_117 ] . V_90 ) ;
V_101 -> V_107 . V_102 [ V_117 ] . V_90 = NULL ;
}
F_78 ( V_101 ) ;
return ( V_85 ) ;
}
