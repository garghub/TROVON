STATIC T_1
F_1 (
struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
for ( V_4 = 0 , V_3 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
V_3 = tolower ( V_2 -> V_2 [ V_4 ] ) ^ F_2 ( V_3 , 7 ) ;
return V_3 ;
}
STATIC enum V_6
F_3 (
struct V_7 * args ,
const unsigned char * V_2 ,
int V_5 )
{
enum V_6 V_8 ;
int V_4 ;
if ( args -> V_9 != V_5 )
return V_10 ;
V_8 = V_11 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( args -> V_2 [ V_4 ] == V_2 [ V_4 ] )
continue;
if ( tolower ( args -> V_2 [ V_4 ] ) != tolower ( V_2 [ V_4 ] ) )
return V_10 ;
V_8 = V_12 ;
}
return V_8 ;
}
void
F_4 (
T_2 * V_13 )
{
int V_14 ;
ASSERT ( F_5 ( & V_13 -> V_15 ) ) ;
ASSERT ( ( 1 << ( V_13 -> V_15 . V_16 + V_13 -> V_15 . V_17 ) ) <=
V_18 ) ;
V_13 -> V_19 = 1 << ( V_13 -> V_15 . V_16 + V_13 -> V_15 . V_17 ) ;
V_13 -> V_20 = 1 << V_13 -> V_15 . V_17 ;
V_13 -> V_21 = F_6 ( V_13 , F_7 ( V_13 ) ) ;
V_13 -> V_22 = F_6 ( V_13 , F_8 ( V_13 ) ) ;
V_13 -> V_23 = F_6 ( V_13 , F_9 ( V_13 ) ) ;
V_14 = F_10 ( F_11 ( & V_13 -> V_15 ) ) ;
V_13 -> V_24 = ( V_13 -> V_15 . V_25 - V_14 ) /
( V_26 ) sizeof( V_27 ) ;
V_13 -> V_28 = ( V_13 -> V_19 - V_14 ) /
( V_26 ) sizeof( V_27 ) ;
V_13 -> V_29 = ( V_13 -> V_19 * 37 ) / 100 ;
if ( F_12 ( & V_13 -> V_15 ) )
V_13 -> V_30 = & V_31 ;
else
V_13 -> V_30 = & V_32 ;
}
int
F_13 (
T_3 * V_33 )
{
T_4 * V_34 ;
ASSERT ( F_14 ( V_33 -> V_35 . V_36 ) ) ;
if ( V_33 -> V_35 . V_37 == 0 )
return 1 ;
if ( V_33 -> V_35 . V_37 > F_15 ( V_33 ) )
return 0 ;
V_34 = ( T_4 * ) V_33 -> V_38 . V_39 . V_40 ;
return ! V_34 -> V_41 ;
}
int
F_16 (
T_2 * V_13 ,
T_5 V_42 )
{
T_6 V_43 ;
T_7 V_44 ;
T_8 V_45 ;
int V_46 ;
int V_47 ;
V_45 = F_17 ( V_13 , V_42 ) ;
V_43 = F_18 ( V_13 , V_42 ) ;
V_47 = F_19 ( V_13 , V_42 ) ;
V_44 = F_20 ( V_13 , V_43 , V_47 ) ;
V_46 =
V_45 < V_13 -> V_15 . V_48 &&
V_43 < V_13 -> V_15 . V_49 &&
V_43 != 0 &&
V_47 < ( 1 << V_13 -> V_15 . V_50 ) &&
F_21 ( V_13 , V_45 , V_44 ) == V_42 ;
if ( F_22 ( F_23 ( ! V_46 , V_13 , V_51 ,
V_52 ) ) ) {
F_24 ( V_13 , L_1 ,
( unsigned long long ) V_42 ) ;
F_25 ( L_2 , V_53 , V_13 ) ;
return F_26 ( V_54 ) ;
}
return 0 ;
}
int
F_27 (
T_9 * V_55 ,
T_3 * V_33 ,
T_3 * V_56 )
{
T_10 args ;
int error ;
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_33 = V_33 ;
args . V_57 = V_55 ;
ASSERT ( F_14 ( V_33 -> V_35 . V_36 ) ) ;
if ( ( error = F_16 ( V_55 -> V_58 , V_56 -> V_59 ) ) )
return error ;
return F_28 ( & args , V_56 -> V_59 ) ;
}
int
F_29 (
T_9 * V_55 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
T_5 V_60 ,
T_11 * V_61 ,
T_12 * V_62 ,
T_13 V_63 )
{
T_10 args ;
int V_64 ;
int V_65 ;
ASSERT ( F_14 ( V_33 -> V_35 . V_36 ) ) ;
if ( ( V_64 = F_16 ( V_55 -> V_58 , V_60 ) ) )
return V_64 ;
F_30 ( V_66 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_67 = V_2 -> type ;
args . V_68 = V_33 -> V_69 -> V_30 -> V_70 ( V_2 ) ;
args . V_71 = V_60 ;
args . V_33 = V_33 ;
args . V_72 = V_61 ;
args . V_62 = V_62 ;
args . V_63 = V_63 ;
args . V_73 = V_74 ;
args . V_57 = V_55 ;
args . V_75 = V_76 | V_77 ;
if ( V_33 -> V_35 . V_78 == V_79 )
V_64 = F_31 ( & args ) ;
else if ( ( V_64 = F_32 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_33 ( & args ) ;
else if ( ( V_64 = F_34 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_35 ( & args ) ;
else
V_64 = F_36 ( & args ) ;
return V_64 ;
}
int
F_37 (
struct V_7 * args ,
const unsigned char * V_2 ,
int V_5 )
{
if ( args -> V_80 == V_10 )
return V_81 ;
if ( args -> V_80 != V_12 ||
! ( args -> V_75 & V_82 ) )
return V_83 ;
args -> V_84 = F_38 ( V_5 , V_85 | V_86 ) ;
if ( ! args -> V_84 )
return V_87 ;
memcpy ( args -> V_84 , V_2 , V_5 ) ;
args -> V_88 = V_5 ;
return V_83 ;
}
int
F_39 (
T_9 * V_55 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
T_5 * V_60 ,
struct V_1 * V_89 )
{
T_10 args ;
int V_64 ;
int V_65 ;
ASSERT ( F_14 ( V_33 -> V_35 . V_36 ) ) ;
F_30 ( V_90 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_67 = V_2 -> type ;
args . V_68 = V_33 -> V_69 -> V_30 -> V_70 ( V_2 ) ;
args . V_33 = V_33 ;
args . V_73 = V_74 ;
args . V_57 = V_55 ;
args . V_75 = V_77 ;
if ( V_89 )
args . V_75 |= V_82 ;
if ( V_33 -> V_35 . V_78 == V_79 )
V_64 = F_40 ( & args ) ;
else if ( ( V_64 = F_32 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_41 ( & args ) ;
else if ( ( V_64 = F_34 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_42 ( & args ) ;
else
V_64 = F_43 ( & args ) ;
if ( V_64 == V_83 )
V_64 = 0 ;
if ( ! V_64 ) {
* V_60 = args . V_71 ;
if ( V_89 ) {
V_89 -> V_2 = args . V_84 ;
V_89 -> V_5 = args . V_88 ;
}
}
return V_64 ;
}
int
F_44 (
T_9 * V_55 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
T_5 V_42 ,
T_11 * V_61 ,
T_12 * V_62 ,
T_13 V_63 )
{
T_10 args ;
int V_64 ;
int V_65 ;
ASSERT ( F_14 ( V_33 -> V_35 . V_36 ) ) ;
F_30 ( V_91 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_67 = V_2 -> type ;
args . V_68 = V_33 -> V_69 -> V_30 -> V_70 ( V_2 ) ;
args . V_71 = V_42 ;
args . V_33 = V_33 ;
args . V_72 = V_61 ;
args . V_62 = V_62 ;
args . V_63 = V_63 ;
args . V_73 = V_74 ;
args . V_57 = V_55 ;
if ( V_33 -> V_35 . V_78 == V_79 )
V_64 = F_45 ( & args ) ;
else if ( ( V_64 = F_32 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_46 ( & args ) ;
else if ( ( V_64 = F_34 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_47 ( & args ) ;
else
V_64 = F_48 ( & args ) ;
return V_64 ;
}
int
F_49 (
T_9 * V_55 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
T_5 V_60 ,
T_11 * V_61 ,
T_12 * V_62 ,
T_13 V_63 )
{
T_10 args ;
int V_64 ;
int V_65 ;
ASSERT ( F_14 ( V_33 -> V_35 . V_36 ) ) ;
if ( ( V_64 = F_16 ( V_55 -> V_58 , V_60 ) ) )
return V_64 ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_67 = V_2 -> type ;
args . V_68 = V_33 -> V_69 -> V_30 -> V_70 ( V_2 ) ;
args . V_71 = V_60 ;
args . V_33 = V_33 ;
args . V_72 = V_61 ;
args . V_62 = V_62 ;
args . V_63 = V_63 ;
args . V_73 = V_74 ;
args . V_57 = V_55 ;
if ( V_33 -> V_35 . V_78 == V_79 )
V_64 = F_50 ( & args ) ;
else if ( ( V_64 = F_32 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_51 ( & args ) ;
else if ( ( V_64 = F_34 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_52 ( & args ) ;
else
V_64 = F_53 ( & args ) ;
return V_64 ;
}
int
F_54 (
T_9 * V_55 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
V_26 V_92 )
{
T_10 args ;
int V_64 ;
int V_65 ;
if ( V_92 )
return 0 ;
ASSERT ( F_14 ( V_33 -> V_35 . V_36 ) ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_67 = V_2 -> type ;
args . V_68 = V_33 -> V_69 -> V_30 -> V_70 ( V_2 ) ;
args . V_33 = V_33 ;
args . V_73 = V_74 ;
args . V_57 = V_55 ;
args . V_75 = V_93 | V_76 |
V_77 ;
if ( V_33 -> V_35 . V_78 == V_79 )
V_64 = F_31 ( & args ) ;
else if ( ( V_64 = F_32 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_33 ( & args ) ;
else if ( ( V_64 = F_34 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_35 ( & args ) ;
else
V_64 = F_36 ( & args ) ;
return V_64 ;
}
int
F_55 (
struct V_7 * args ,
int V_94 ,
T_14 * V_95 )
{
struct V_96 * V_33 = args -> V_33 ;
struct V_97 * V_13 = V_33 -> V_69 ;
T_15 V_98 ;
int V_41 ;
int error ;
F_56 ( args , V_94 ) ;
V_98 = F_57 ( V_13 , V_94 * V_99 ) ;
V_41 = V_13 -> V_20 ;
error = F_58 ( args , & V_98 , V_41 ) ;
if ( error )
return error ;
* V_95 = F_59 ( V_13 , ( V_100 ) V_98 ) ;
if ( V_94 == V_101 ) {
T_16 V_102 ;
V_102 = F_60 ( V_13 , V_98 + V_41 ) ;
if ( V_102 > V_33 -> V_35 . V_37 ) {
V_33 -> V_35 . V_37 = V_102 ;
F_61 ( args -> V_57 , V_33 , V_103 ) ;
}
}
return 0 ;
}
int
F_32 (
T_9 * V_55 ,
T_3 * V_33 ,
int * V_104 )
{
T_15 V_105 ;
T_2 * V_13 ;
int V_64 ;
V_13 = V_33 -> V_69 ;
if ( ( V_64 = F_62 ( V_55 , V_33 , & V_105 , V_74 ) ) )
return V_64 ;
V_64 = F_60 ( V_13 , V_105 ) == V_13 -> V_19 ;
ASSERT ( V_64 == 0 || V_33 -> V_35 . V_37 == V_13 -> V_19 ) ;
* V_104 = V_64 ;
return 0 ;
}
int
F_34 (
T_9 * V_55 ,
T_3 * V_33 ,
int * V_104 )
{
T_15 V_105 ;
T_2 * V_13 ;
int V_64 ;
V_13 = V_33 -> V_69 ;
if ( ( V_64 = F_62 ( V_55 , V_33 , & V_105 , V_74 ) ) )
return V_64 ;
* V_104 = V_105 == V_13 -> V_22 + ( 1 << V_13 -> V_15 . V_17 ) ;
return 0 ;
}
int
F_63 (
T_10 * args ,
T_14 V_106 ,
struct V_107 * V_108 )
{
T_15 V_98 ;
V_100 V_109 ;
int V_110 ;
T_3 * V_33 ;
int error ;
T_2 * V_13 ;
T_9 * V_55 ;
F_64 ( args , V_106 ) ;
V_33 = args -> V_33 ;
V_13 = V_33 -> V_69 ;
V_55 = args -> V_57 ;
V_109 = F_6 ( V_13 , V_106 ) ;
if ( ( error = F_65 ( V_55 , V_33 , V_109 , V_13 -> V_20 ,
V_111 , 0 , args -> V_72 , args -> V_62 ,
& V_110 ) ) ) {
return error ;
}
ASSERT ( V_110 ) ;
F_66 ( V_55 , V_108 ) ;
if ( V_106 >= F_8 ( V_13 ) )
return 0 ;
if ( V_33 -> V_35 . V_37 > F_67 ( V_13 , V_106 + 1 , 0 ) )
return 0 ;
V_98 = V_109 ;
if ( ( error = F_68 ( V_55 , V_33 , & V_98 , V_74 ) ) ) {
return error ;
}
if ( V_106 == V_13 -> V_21 )
ASSERT ( V_98 == 0 ) ;
else
ASSERT ( V_98 > 0 ) ;
V_33 -> V_35 . V_37 = F_60 ( V_13 , V_98 ) ;
F_61 ( V_55 , V_33 , V_103 ) ;
return 0 ;
}
