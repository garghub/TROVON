static struct V_1 *
F_1 (
struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_5 . V_6 . V_7 , V_2 -> V_5 . V_6 . V_8 ,
V_2 -> V_5 . V_6 . V_9 ) ;
}
STATIC void
F_3 (
struct V_1 * V_2 ,
union V_10 * V_11 ,
int V_12 )
{
struct V_13 * V_7 = V_2 -> V_5 . V_6 . V_7 ;
struct V_14 * V_15 = F_4 ( V_7 ) ;
T_1 V_16 = F_5 ( V_15 -> V_17 ) ;
struct V_18 * V_19 = F_6 ( V_2 -> V_3 , V_16 ) ;
ASSERT ( V_11 -> V_20 != 0 ) ;
V_15 -> V_21 = V_11 -> V_20 ;
F_7 ( & V_15 -> V_22 , V_12 ) ;
V_19 -> V_23 += V_12 ;
F_8 ( V_19 ) ;
F_9 ( V_2 -> V_4 , V_7 ,
V_24 | V_25 ) ;
}
STATIC int
F_10 (
struct V_1 * V_2 ,
union V_10 * V_26 ,
union V_10 * V_27 ,
int * V_28 )
{
struct V_13 * V_7 = V_2 -> V_5 . V_6 . V_7 ;
struct V_14 * V_15 = F_4 ( V_7 ) ;
struct V_29 args ;
int error ;
F_11 ( V_2 , V_30 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_31 = V_2 -> V_4 ;
args . V_32 = V_2 -> V_3 ;
args . type = V_33 ;
args . V_34 = F_12 ( V_2 -> V_3 , V_2 -> V_5 . V_6 . V_8 ,
F_13 ( args . V_32 ) ) ;
args . V_35 = args . V_34 ;
F_14 ( & args . V_36 , V_37 ) ;
args . V_38 = args . V_39 = args . V_40 = 1 ;
args . V_41 = V_42 ;
error = F_15 ( & args ) ;
if ( error )
goto V_43;
F_16 ( V_2 -> V_3 , V_2 -> V_5 . V_6 . V_8 ,
args . V_44 , 1 ) ;
if ( args . V_34 == V_45 ) {
F_11 ( V_2 , V_46 ) ;
* V_28 = 0 ;
return 0 ;
}
ASSERT ( args . V_8 == V_2 -> V_5 . V_6 . V_8 ) ;
ASSERT ( args . V_47 == 1 ) ;
V_27 -> V_20 = F_17 ( args . V_44 ) ;
F_7 ( & V_15 -> V_48 , 1 ) ;
F_9 ( V_2 -> V_4 , V_7 , V_49 ) ;
F_11 ( V_2 , V_46 ) ;
* V_28 = 1 ;
return 0 ;
V_43:
F_11 ( V_2 , V_50 ) ;
return error ;
}
STATIC int
F_18 (
struct V_1 * V_2 ,
struct V_13 * V_51 )
{
struct V_52 * V_32 = V_2 -> V_3 ;
struct V_13 * V_7 = V_2 -> V_5 . V_6 . V_7 ;
struct V_14 * V_15 = F_4 ( V_7 ) ;
T_2 V_34 = F_19 ( V_32 , F_20 ( V_51 ) ) ;
struct V_53 V_36 ;
int error ;
F_21 ( V_2 -> V_3 , V_2 -> V_5 . V_6 . V_8 ,
F_22 ( V_2 -> V_3 , V_34 ) , 1 ) ;
F_14 ( & V_36 , V_37 ) ;
F_7 ( & V_15 -> V_48 , - 1 ) ;
F_9 ( V_2 -> V_4 , V_7 , V_49 ) ;
error = F_23 ( V_2 -> V_4 , V_34 , 1 , & V_36 ,
V_42 ) ;
if ( error )
return error ;
return error ;
}
STATIC int
F_24 (
struct V_1 * V_2 ,
int V_54 )
{
return V_2 -> V_3 -> V_55 [ V_54 != 0 ] ;
}
STATIC int
F_25 (
struct V_1 * V_2 ,
int V_54 )
{
return V_2 -> V_3 -> V_56 [ V_54 != 0 ] ;
}
STATIC void
F_26 (
union V_57 * V_58 ,
union V_59 * V_60 )
{
V_58 -> V_61 . V_62 = V_60 -> V_61 . V_62 ;
}
STATIC void
F_27 (
union V_57 * V_58 ,
union V_59 * V_60 )
{
T_3 V_63 ;
V_63 = F_5 ( V_60 -> V_61 . V_62 ) ;
V_63 += F_5 ( V_60 -> V_61 . V_64 ) - 1 ;
V_58 -> V_61 . V_62 = F_17 ( V_63 ) ;
}
STATIC void
F_28 (
struct V_1 * V_2 ,
union V_59 * V_60 )
{
V_60 -> V_61 . V_62 = F_17 ( V_2 -> V_65 . V_66 . V_62 ) ;
V_60 -> V_61 . V_64 = F_17 ( V_2 -> V_65 . V_66 . V_64 ) ;
V_60 -> V_61 . V_67 = F_17 ( V_2 -> V_65 . V_66 . V_67 ) ;
}
STATIC void
F_29 (
struct V_1 * V_2 ,
union V_10 * V_11 )
{
struct V_14 * V_15 = F_4 ( V_2 -> V_5 . V_6 . V_7 ) ;
ASSERT ( V_2 -> V_5 . V_6 . V_8 == F_5 ( V_15 -> V_17 ) ) ;
ASSERT ( V_15 -> V_21 != 0 ) ;
V_11 -> V_20 = V_15 -> V_21 ;
}
STATIC T_4
F_30 (
struct V_1 * V_2 ,
union V_57 * V_58 )
{
struct V_68 * V_60 = & V_2 -> V_65 . V_66 ;
struct V_69 * V_70 = & V_58 -> V_61 ;
return ( T_4 ) F_5 ( V_70 -> V_62 ) - V_60 -> V_62 ;
}
STATIC T_4
F_31 (
struct V_1 * V_2 ,
union V_57 * V_71 ,
union V_57 * V_72 )
{
return ( T_4 ) F_5 ( V_71 -> V_61 . V_62 ) -
F_5 ( V_72 -> V_61 . V_62 ) ;
}
STATIC bool
F_32 (
struct V_13 * V_51 )
{
struct V_52 * V_32 = V_51 -> V_73 -> V_74 ;
struct V_75 * V_76 = F_33 ( V_51 ) ;
struct V_18 * V_19 = V_51 -> V_77 ;
unsigned int V_54 ;
if ( V_76 -> V_78 != F_17 ( V_79 ) )
return false ;
if ( ! F_34 ( & V_32 -> V_80 ) )
return false ;
if ( ! F_35 ( V_51 ) )
return false ;
V_54 = F_36 ( V_76 -> V_81 ) ;
if ( V_19 && V_19 -> V_82 ) {
if ( V_54 >= V_19 -> V_23 )
return false ;
} else if ( V_54 >= V_32 -> V_83 )
return false ;
return F_37 ( V_51 , V_32 -> V_56 [ V_54 != 0 ] ) ;
}
STATIC void
F_38 (
struct V_13 * V_51 )
{
if ( ! F_39 ( V_51 ) )
F_40 ( V_51 , - V_84 ) ;
else if ( ! F_32 ( V_51 ) )
F_40 ( V_51 , - V_85 ) ;
if ( V_51 -> V_86 ) {
F_41 ( V_51 , V_87 ) ;
F_42 ( V_51 ) ;
}
}
STATIC void
F_43 (
struct V_13 * V_51 )
{
if ( ! F_32 ( V_51 ) ) {
F_41 ( V_51 , V_87 ) ;
F_40 ( V_51 , - V_85 ) ;
F_42 ( V_51 ) ;
return;
}
F_44 ( V_51 ) ;
}
STATIC int
F_45 (
struct V_1 * V_2 ,
union V_57 * V_71 ,
union V_57 * V_72 )
{
return F_5 ( V_71 -> V_61 . V_62 ) <
F_5 ( V_72 -> V_61 . V_62 ) ;
}
STATIC int
F_46 (
struct V_1 * V_2 ,
union V_59 * V_88 ,
union V_59 * V_89 )
{
return F_5 ( V_88 -> V_61 . V_62 ) +
F_5 ( V_88 -> V_61 . V_64 ) <=
F_5 ( V_89 -> V_61 . V_62 ) ;
}
struct V_1 *
F_2 (
struct V_52 * V_32 ,
struct V_90 * V_31 ,
struct V_13 * V_7 ,
T_1 V_8 ,
struct V_91 * V_9 )
{
struct V_14 * V_15 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
ASSERT ( V_8 != V_92 ) ;
ASSERT ( V_8 < V_32 -> V_80 . V_93 ) ;
V_2 = F_47 ( V_94 , V_95 ) ;
V_2 -> V_4 = V_31 ;
V_2 -> V_3 = V_32 ;
V_2 -> V_96 = V_97 ;
V_2 -> V_98 = V_32 -> V_80 . V_99 ;
V_2 -> V_100 = & V_101 ;
V_2 -> V_102 = F_48 ( V_103 ) ;
V_2 -> V_104 = F_5 ( V_15 -> V_22 ) ;
V_2 -> V_5 . V_6 . V_7 = V_7 ;
V_2 -> V_5 . V_6 . V_8 = V_8 ;
V_2 -> V_5 . V_6 . V_9 = V_9 ;
V_2 -> V_105 |= V_106 ;
V_2 -> V_5 . V_6 . V_107 . V_61 . V_108 = 0 ;
V_2 -> V_5 . V_6 . V_107 . V_61 . V_109 = 0 ;
return V_2 ;
}
int
F_49 (
struct V_52 * V_32 ,
int V_110 ,
bool V_111 )
{
V_110 -= V_112 ;
if ( V_111 )
return V_110 / sizeof( struct V_113 ) ;
return V_110 / ( sizeof( struct V_69 ) +
sizeof( V_114 ) ) ;
}
void
F_50 (
struct V_52 * V_32 )
{
V_32 -> V_83 = F_51 ( V_32 ,
V_32 -> V_55 , V_32 -> V_80 . V_115 ) ;
}
T_5
F_52 (
struct V_52 * V_32 ,
unsigned long long V_47 )
{
return F_53 ( V_32 , V_32 -> V_55 , V_47 ) ;
}
T_5
F_54 (
struct V_52 * V_32 ,
T_6 V_116 )
{
if ( V_32 -> V_56 [ 0 ] == 0 )
return 0 ;
return F_52 ( V_32 , V_116 ) ;
}
int
F_55 (
struct V_52 * V_32 ,
T_1 V_8 ,
T_5 * V_117 ,
T_5 * V_118 )
{
struct V_13 * V_7 ;
struct V_14 * V_15 ;
T_6 V_116 ;
T_5 V_119 ;
int error ;
if ( ! F_34 ( & V_32 -> V_80 ) )
return 0 ;
error = F_56 ( V_32 , NULL , V_8 , 0 , & V_7 ) ;
if ( error )
return error ;
V_15 = F_4 ( V_7 ) ;
V_116 = F_5 ( V_15 -> V_120 ) ;
V_119 = F_5 ( V_15 -> V_48 ) ;
F_57 ( V_7 ) ;
* V_117 += F_54 ( V_32 , V_116 ) ;
* V_118 += V_119 ;
return error ;
}
