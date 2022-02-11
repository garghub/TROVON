STATIC int
F_1 (
struct V_1 * V_2 ,
int V_3 )
{
return V_2 -> V_4 -> V_5 [ V_3 != 0 ] ;
}
STATIC struct V_1 *
F_2 (
struct V_1 * V_2 )
{
return F_3 ( V_2 -> V_4 , V_2 -> V_6 ,
V_2 -> V_7 . V_8 . V_9 , V_2 -> V_7 . V_8 . V_10 ) ;
}
STATIC void
F_4 (
struct V_1 * V_2 ,
union V_11 * V_12 ,
int V_13 )
{
struct V_14 * V_9 = V_2 -> V_7 . V_8 . V_9 ;
struct V_15 * V_16 = F_5 ( V_9 ) ;
V_16 -> V_17 = V_12 -> V_18 ;
F_6 ( & V_16 -> V_19 , V_13 ) ;
F_7 ( V_2 -> V_6 , V_9 , V_20 | V_21 ) ;
}
STATIC int
F_8 (
struct V_1 * V_2 ,
union V_11 * V_22 ,
union V_11 * V_23 ,
int V_24 ,
int * V_25 )
{
T_1 args ;
int error ;
T_2 V_26 = F_9 ( V_22 -> V_18 ) ;
F_10 ( V_2 , V_27 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_28 = V_2 -> V_6 ;
args . V_29 = V_2 -> V_4 ;
args . V_30 = F_11 ( args . V_29 , V_2 -> V_7 . V_8 . V_10 , V_26 ) ;
args . V_31 = 1 ;
args . V_32 = 1 ;
args . V_33 = 1 ;
args . type = V_34 ;
error = F_12 ( & args ) ;
if ( error ) {
F_10 ( V_2 , V_35 ) ;
return error ;
}
if ( args . V_30 == V_36 ) {
F_10 ( V_2 , V_37 ) ;
* V_25 = 0 ;
return 0 ;
}
ASSERT ( args . V_38 == 1 ) ;
F_10 ( V_2 , V_37 ) ;
V_23 -> V_18 = F_13 ( F_14 ( args . V_29 , args . V_30 ) ) ;
* V_25 = 1 ;
return 0 ;
}
STATIC int
F_15 (
struct V_1 * V_2 ,
struct V_14 * V_39 )
{
T_3 V_30 ;
int error ;
V_30 = F_16 ( V_2 -> V_4 , F_17 ( V_39 ) ) ;
error = F_18 ( V_2 -> V_6 , V_30 , 1 ) ;
if ( error )
return error ;
F_19 ( V_2 -> V_6 , V_39 ) ;
return error ;
}
STATIC int
F_20 (
struct V_1 * V_2 ,
int V_3 )
{
return V_2 -> V_4 -> V_40 [ V_3 != 0 ] ;
}
STATIC void
F_21 (
union V_41 * V_42 ,
union V_43 * V_44 )
{
V_42 -> V_45 . V_46 = V_44 -> V_45 . V_46 ;
}
STATIC void
F_22 (
union V_41 * V_42 ,
union V_43 * V_44 )
{
V_44 -> V_45 . V_46 = V_42 -> V_45 . V_46 ;
}
STATIC void
F_23 (
struct V_1 * V_2 ,
union V_43 * V_44 )
{
V_44 -> V_45 . V_46 = F_13 ( V_2 -> V_47 . V_48 . V_46 ) ;
V_44 -> V_45 . V_49 = F_13 ( V_2 -> V_47 . V_48 . V_49 ) ;
V_44 -> V_45 . V_50 = F_24 ( V_2 -> V_47 . V_48 . V_50 ) ;
}
STATIC void
F_25 (
struct V_1 * V_2 ,
union V_11 * V_51 )
{
struct V_15 * V_16 = F_5 ( V_2 -> V_7 . V_8 . V_9 ) ;
ASSERT ( V_2 -> V_7 . V_8 . V_10 == F_9 ( V_16 -> V_52 ) ) ;
V_51 -> V_18 = V_16 -> V_17 ;
}
STATIC T_4
F_26 (
struct V_1 * V_2 ,
union V_41 * V_42 )
{
return ( T_4 ) F_9 ( V_42 -> V_45 . V_46 ) -
V_2 -> V_47 . V_48 . V_46 ;
}
STATIC int
F_27 (
struct V_1 * V_2 ,
union V_41 * V_53 ,
union V_41 * V_54 )
{
return F_9 ( V_53 -> V_45 . V_46 ) <
F_9 ( V_54 -> V_45 . V_46 ) ;
}
STATIC int
F_28 (
struct V_1 * V_2 ,
union V_43 * V_55 ,
union V_43 * V_56 )
{
return F_9 ( V_55 -> V_45 . V_46 ) + V_57 <=
F_9 ( V_56 -> V_45 . V_46 ) ;
}
STATIC void
F_29 (
struct V_1 * V_2 ,
const char * V_58 ,
char * V_18 ,
int type ,
int line ,
T_5 V_59 ,
T_5 V_60 ,
T_5 V_61 ,
T_5 V_62 ,
T_5 V_63 ,
T_5 V_64 ,
T_5 V_65 ,
T_5 V_66 ,
T_5 V_67 ,
T_5 V_68 ,
T_5 V_69 )
{
F_30 ( V_70 , ( void * ) ( V_71 ) type ,
( void * ) V_58 , ( void * ) V_18 , NULL , ( void * ) V_2 ,
( void * ) V_59 , ( void * ) V_60 , ( void * ) V_61 , ( void * ) V_62 ,
( void * ) V_63 , ( void * ) V_64 , ( void * ) V_65 , ( void * ) V_66 ,
( void * ) V_67 , ( void * ) V_68 , ( void * ) V_69 ) ;
}
STATIC void
F_31 (
struct V_1 * V_2 ,
T_6 * V_72 ,
T_7 * V_73 ,
T_7 * V_74 )
{
* V_72 = V_2 -> V_7 . V_8 . V_10 ;
* V_73 = V_2 -> V_47 . V_48 . V_46 ;
* V_74 = V_2 -> V_47 . V_48 . V_50 ;
}
STATIC void
F_32 (
struct V_1 * V_2 ,
union V_41 * V_42 ,
T_7 * V_73 ,
T_7 * V_74 )
{
* V_73 = F_9 ( V_42 -> V_45 . V_46 ) ;
* V_74 = 0 ;
}
STATIC void
F_33 (
struct V_1 * V_2 ,
union V_43 * V_44 ,
T_7 * V_73 ,
T_7 * V_74 ,
T_7 * V_75 )
{
* V_73 = F_9 ( V_44 -> V_45 . V_46 ) ;
* V_74 = F_9 ( V_44 -> V_45 . V_49 ) ;
* V_75 = F_34 ( V_44 -> V_45 . V_50 ) ;
}
struct V_1 *
F_3 (
struct V_76 * V_29 ,
struct V_77 * V_28 ,
struct V_14 * V_9 ,
T_8 V_10 )
{
struct V_15 * V_16 = F_5 ( V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_35 ( V_78 , V_79 ) ;
V_2 -> V_6 = V_28 ;
V_2 -> V_4 = V_29 ;
V_2 -> V_80 = F_9 ( V_16 -> V_19 ) ;
V_2 -> V_81 = V_82 ;
V_2 -> V_83 = V_29 -> V_84 . V_85 ;
V_2 -> V_86 = & V_87 ;
V_2 -> V_7 . V_8 . V_9 = V_9 ;
V_2 -> V_7 . V_8 . V_10 = V_10 ;
return V_2 ;
}
int
F_36 (
struct V_76 * V_29 ,
int V_88 ,
int V_89 )
{
V_88 -= F_37 ( V_29 ) ;
if ( V_89 )
return V_88 / sizeof( V_90 ) ;
return V_88 / ( sizeof( V_91 ) + sizeof( V_92 ) ) ;
}
