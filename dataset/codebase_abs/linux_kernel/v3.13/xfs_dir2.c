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
V_13 -> V_19 = F_6 ( V_13 , NULL ) ;
V_13 -> V_20 = F_7 ( V_13 , NULL ) ;
V_13 -> V_21 = 1 << ( V_13 -> V_15 . V_16 + V_13 -> V_15 . V_17 ) ;
V_13 -> V_22 = 1 << V_13 -> V_15 . V_17 ;
V_13 -> V_23 = F_8 ( V_13 , F_9 ( V_13 ) ) ;
V_13 -> V_24 = F_8 ( V_13 , F_10 ( V_13 ) ) ;
V_13 -> V_25 = F_8 ( V_13 , F_11 ( V_13 ) ) ;
V_14 = V_13 -> V_19 -> V_26 ;
V_13 -> V_27 = ( V_13 -> V_15 . V_28 - V_14 ) /
( V_29 ) sizeof( V_30 ) ;
V_13 -> V_31 = ( V_13 -> V_21 - V_14 ) /
( V_29 ) sizeof( V_30 ) ;
V_13 -> V_32 = ( V_13 -> V_21 * 37 ) / 100 ;
if ( F_12 ( & V_13 -> V_15 ) )
V_13 -> V_33 = & V_34 ;
else
V_13 -> V_33 = & V_35 ;
}
int
F_13 (
T_3 * V_36 )
{
T_4 * V_37 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
if ( V_36 -> V_38 . V_40 == 0 )
return 1 ;
if ( V_36 -> V_38 . V_40 > F_15 ( V_36 ) )
return 0 ;
V_37 = ( T_4 * ) V_36 -> V_41 . V_42 . V_43 ;
return ! V_37 -> V_44 ;
}
int
F_16 (
T_2 * V_13 ,
T_5 V_45 )
{
T_6 V_46 ;
T_7 V_47 ;
T_8 V_48 ;
int V_49 ;
int V_50 ;
V_48 = F_17 ( V_13 , V_45 ) ;
V_46 = F_18 ( V_13 , V_45 ) ;
V_50 = F_19 ( V_13 , V_45 ) ;
V_47 = F_20 ( V_13 , V_46 , V_50 ) ;
V_49 =
V_48 < V_13 -> V_15 . V_51 &&
V_46 < V_13 -> V_15 . V_52 &&
V_46 != 0 &&
V_50 < ( 1 << V_13 -> V_15 . V_53 ) &&
F_21 ( V_13 , V_48 , V_47 ) == V_45 ;
if ( F_22 ( F_23 ( ! V_49 , V_13 , V_54 ,
V_55 ) ) ) {
F_24 ( V_13 , L_1 ,
( unsigned long long ) V_45 ) ;
F_25 ( L_2 , V_56 , V_13 ) ;
return F_26 ( V_57 ) ;
}
return 0 ;
}
int
F_27 (
T_9 * V_58 ,
T_3 * V_36 ,
T_3 * V_59 )
{
T_10 args ;
int error ;
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_36 = V_36 ;
args . V_60 = V_58 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
if ( ( error = F_16 ( V_58 -> V_61 , V_59 -> V_62 ) ) )
return error ;
return F_28 ( & args , V_59 -> V_62 ) ;
}
int
F_29 (
T_9 * V_58 ,
T_3 * V_36 ,
struct V_1 * V_2 ,
T_5 V_63 ,
T_11 * V_64 ,
T_12 * V_65 ,
T_13 V_66 )
{
T_10 args ;
int V_67 ;
int V_68 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
if ( ( V_67 = F_16 ( V_58 -> V_61 , V_63 ) ) )
return V_67 ;
F_30 ( V_69 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_70 = V_2 -> type ;
args . V_71 = V_36 -> V_72 -> V_33 -> V_73 ( V_2 ) ;
args . V_74 = V_63 ;
args . V_36 = V_36 ;
args . V_75 = V_64 ;
args . V_65 = V_65 ;
args . V_66 = V_66 ;
args . V_76 = V_77 ;
args . V_60 = V_58 ;
args . V_78 = V_79 | V_80 ;
if ( V_36 -> V_38 . V_81 == V_82 )
V_67 = F_31 ( & args ) ;
else if ( ( V_67 = F_32 ( V_58 , V_36 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_33 ( & args ) ;
else if ( ( V_67 = F_34 ( V_58 , V_36 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_35 ( & args ) ;
else
V_67 = F_36 ( & args ) ;
return V_67 ;
}
int
F_37 (
struct V_7 * args ,
const unsigned char * V_2 ,
int V_5 )
{
if ( args -> V_83 == V_10 )
return V_84 ;
if ( args -> V_83 != V_12 ||
! ( args -> V_78 & V_85 ) )
return V_86 ;
args -> V_87 = F_38 ( V_5 , V_88 | V_89 ) ;
if ( ! args -> V_87 )
return V_90 ;
memcpy ( args -> V_87 , V_2 , V_5 ) ;
args -> V_91 = V_5 ;
return V_86 ;
}
int
F_39 (
T_9 * V_58 ,
T_3 * V_36 ,
struct V_1 * V_2 ,
T_5 * V_63 ,
struct V_1 * V_92 )
{
T_10 args ;
int V_67 ;
int V_68 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
F_30 ( V_93 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_70 = V_2 -> type ;
args . V_71 = V_36 -> V_72 -> V_33 -> V_73 ( V_2 ) ;
args . V_36 = V_36 ;
args . V_76 = V_77 ;
args . V_60 = V_58 ;
args . V_78 = V_80 ;
if ( V_92 )
args . V_78 |= V_85 ;
if ( V_36 -> V_38 . V_81 == V_82 )
V_67 = F_40 ( & args ) ;
else if ( ( V_67 = F_32 ( V_58 , V_36 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_41 ( & args ) ;
else if ( ( V_67 = F_34 ( V_58 , V_36 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_42 ( & args ) ;
else
V_67 = F_43 ( & args ) ;
if ( V_67 == V_86 )
V_67 = 0 ;
if ( ! V_67 ) {
* V_63 = args . V_74 ;
if ( V_92 ) {
V_92 -> V_2 = args . V_87 ;
V_92 -> V_5 = args . V_91 ;
}
}
return V_67 ;
}
int
F_44 (
T_9 * V_58 ,
T_3 * V_36 ,
struct V_1 * V_2 ,
T_5 V_45 ,
T_11 * V_64 ,
T_12 * V_65 ,
T_13 V_66 )
{
T_10 args ;
int V_67 ;
int V_68 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
F_30 ( V_94 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_70 = V_2 -> type ;
args . V_71 = V_36 -> V_72 -> V_33 -> V_73 ( V_2 ) ;
args . V_74 = V_45 ;
args . V_36 = V_36 ;
args . V_75 = V_64 ;
args . V_65 = V_65 ;
args . V_66 = V_66 ;
args . V_76 = V_77 ;
args . V_60 = V_58 ;
if ( V_36 -> V_38 . V_81 == V_82 )
V_67 = F_45 ( & args ) ;
else if ( ( V_67 = F_32 ( V_58 , V_36 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_46 ( & args ) ;
else if ( ( V_67 = F_34 ( V_58 , V_36 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_47 ( & args ) ;
else
V_67 = F_48 ( & args ) ;
return V_67 ;
}
int
F_49 (
T_9 * V_58 ,
T_3 * V_36 ,
struct V_1 * V_2 ,
T_5 V_63 ,
T_11 * V_64 ,
T_12 * V_65 ,
T_13 V_66 )
{
T_10 args ;
int V_67 ;
int V_68 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
if ( ( V_67 = F_16 ( V_58 -> V_61 , V_63 ) ) )
return V_67 ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_70 = V_2 -> type ;
args . V_71 = V_36 -> V_72 -> V_33 -> V_73 ( V_2 ) ;
args . V_74 = V_63 ;
args . V_36 = V_36 ;
args . V_75 = V_64 ;
args . V_65 = V_65 ;
args . V_66 = V_66 ;
args . V_76 = V_77 ;
args . V_60 = V_58 ;
if ( V_36 -> V_38 . V_81 == V_82 )
V_67 = F_50 ( & args ) ;
else if ( ( V_67 = F_32 ( V_58 , V_36 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_51 ( & args ) ;
else if ( ( V_67 = F_34 ( V_58 , V_36 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_52 ( & args ) ;
else
V_67 = F_53 ( & args ) ;
return V_67 ;
}
int
F_54 (
T_9 * V_58 ,
T_3 * V_36 ,
struct V_1 * V_2 ,
V_29 V_95 )
{
T_10 args ;
int V_67 ;
int V_68 ;
if ( V_95 )
return 0 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_70 = V_2 -> type ;
args . V_71 = V_36 -> V_72 -> V_33 -> V_73 ( V_2 ) ;
args . V_36 = V_36 ;
args . V_76 = V_77 ;
args . V_60 = V_58 ;
args . V_78 = V_96 | V_79 |
V_80 ;
if ( V_36 -> V_38 . V_81 == V_82 )
V_67 = F_31 ( & args ) ;
else if ( ( V_67 = F_32 ( V_58 , V_36 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_33 ( & args ) ;
else if ( ( V_67 = F_34 ( V_58 , V_36 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_35 ( & args ) ;
else
V_67 = F_36 ( & args ) ;
return V_67 ;
}
int
F_55 (
struct V_7 * args ,
int V_97 ,
T_14 * V_98 )
{
struct V_99 * V_36 = args -> V_36 ;
struct V_100 * V_13 = V_36 -> V_72 ;
T_15 V_101 ;
int V_44 ;
int error ;
F_56 ( args , V_97 ) ;
V_101 = F_57 ( V_13 , V_97 * V_102 ) ;
V_44 = V_13 -> V_22 ;
error = F_58 ( args , & V_101 , V_44 ) ;
if ( error )
return error ;
* V_98 = F_59 ( V_13 , ( V_103 ) V_101 ) ;
if ( V_97 == V_104 ) {
T_16 V_105 ;
V_105 = F_60 ( V_13 , V_101 + V_44 ) ;
if ( V_105 > V_36 -> V_38 . V_40 ) {
V_36 -> V_38 . V_40 = V_105 ;
F_61 ( args -> V_60 , V_36 , V_106 ) ;
}
}
return 0 ;
}
int
F_32 (
T_9 * V_58 ,
T_3 * V_36 ,
int * V_107 )
{
T_15 V_108 ;
T_2 * V_13 ;
int V_67 ;
V_13 = V_36 -> V_72 ;
if ( ( V_67 = F_62 ( V_58 , V_36 , & V_108 , V_77 ) ) )
return V_67 ;
V_67 = F_60 ( V_13 , V_108 ) == V_13 -> V_21 ;
ASSERT ( V_67 == 0 || V_36 -> V_38 . V_40 == V_13 -> V_21 ) ;
* V_107 = V_67 ;
return 0 ;
}
int
F_34 (
T_9 * V_58 ,
T_3 * V_36 ,
int * V_107 )
{
T_15 V_108 ;
T_2 * V_13 ;
int V_67 ;
V_13 = V_36 -> V_72 ;
if ( ( V_67 = F_62 ( V_58 , V_36 , & V_108 , V_77 ) ) )
return V_67 ;
* V_107 = V_108 == V_13 -> V_24 + ( 1 << V_13 -> V_15 . V_17 ) ;
return 0 ;
}
int
F_63 (
T_10 * args ,
T_14 V_109 ,
struct V_110 * V_111 )
{
T_15 V_101 ;
V_103 V_112 ;
int V_113 ;
T_3 * V_36 ;
int error ;
T_2 * V_13 ;
T_9 * V_58 ;
F_64 ( args , V_109 ) ;
V_36 = args -> V_36 ;
V_13 = V_36 -> V_72 ;
V_58 = args -> V_60 ;
V_112 = F_8 ( V_13 , V_109 ) ;
if ( ( error = F_65 ( V_58 , V_36 , V_112 , V_13 -> V_22 ,
V_114 , 0 , args -> V_75 , args -> V_65 ,
& V_113 ) ) ) {
return error ;
}
ASSERT ( V_113 ) ;
F_66 ( V_58 , V_111 ) ;
if ( V_109 >= F_10 ( V_13 ) )
return 0 ;
if ( V_36 -> V_38 . V_40 > F_67 ( V_13 , V_109 + 1 , 0 ) )
return 0 ;
V_101 = V_112 ;
if ( ( error = F_68 ( V_58 , V_36 , & V_101 , V_77 ) ) ) {
return error ;
}
if ( V_109 == V_13 -> V_23 )
ASSERT ( V_101 == 0 ) ;
else
ASSERT ( V_101 > 0 ) ;
V_36 -> V_38 . V_40 = F_60 ( V_13 , V_101 ) ;
F_61 ( V_58 , V_36 , V_106 ) ;
return 0 ;
}
