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
int
F_4 (
struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_17 ;
ASSERT ( V_14 -> V_18 . V_19 & V_20 ) ;
ASSERT ( ( 1 << ( V_14 -> V_18 . V_21 + V_14 -> V_18 . V_22 ) ) <=
V_23 ) ;
V_14 -> V_24 = F_5 ( V_14 , NULL ) ;
V_14 -> V_25 = F_6 ( V_14 , NULL ) ;
V_17 = V_14 -> V_24 -> V_26 ;
V_14 -> V_27 = F_7 ( sizeof( struct V_15 ) ,
V_28 | V_29 ) ;
V_14 -> V_30 = F_7 ( sizeof( struct V_15 ) ,
V_28 | V_29 ) ;
if ( ! V_14 -> V_27 || ! V_14 -> V_30 ) {
F_8 ( V_14 -> V_27 ) ;
F_8 ( V_14 -> V_30 ) ;
return - V_31 ;
}
V_16 = V_14 -> V_27 ;
V_16 -> V_32 = V_14 -> V_18 . V_21 + V_14 -> V_18 . V_22 ;
V_16 -> V_33 = V_14 -> V_18 . V_21 ;
V_16 -> V_34 = 1 << V_16 -> V_32 ;
V_16 -> V_35 = 1 << V_14 -> V_18 . V_22 ;
V_16 -> V_36 = F_9 ( V_16 , V_37 ) ;
V_16 -> V_38 = F_9 ( V_16 , V_39 ) ;
V_16 -> V_40 = F_9 ( V_16 , V_41 ) ;
V_16 -> V_42 = ( V_16 -> V_34 - V_17 ) /
( V_43 ) sizeof( V_44 ) ;
V_16 -> V_45 = ( V_16 -> V_34 * 37 ) / 100 ;
V_16 = V_14 -> V_30 ;
V_16 -> V_32 = V_14 -> V_18 . V_21 ;
V_16 -> V_33 = V_14 -> V_18 . V_21 ;
V_16 -> V_34 = 1 << V_16 -> V_32 ;
V_16 -> V_35 = 1 ;
V_16 -> V_42 = ( V_16 -> V_34 - V_17 ) /
( V_43 ) sizeof( V_44 ) ;
V_16 -> V_45 = ( V_16 -> V_34 * 37 ) / 100 ;
if ( F_10 ( & V_14 -> V_18 ) )
V_14 -> V_46 = & V_47 ;
else
V_14 -> V_46 = & V_48 ;
return 0 ;
}
void
F_11 (
struct V_13 * V_14 )
{
F_8 ( V_14 -> V_27 ) ;
F_8 ( V_14 -> V_30 ) ;
}
int
F_12 (
T_2 * V_49 )
{
T_3 * V_50 ;
ASSERT ( F_13 ( F_14 ( V_49 ) -> V_51 ) ) ;
if ( V_49 -> V_52 . V_53 == 0 )
return 1 ;
if ( V_49 -> V_52 . V_53 > F_15 ( V_49 ) )
return 0 ;
V_50 = ( T_3 * ) V_49 -> V_54 . V_55 . V_56 ;
return ! V_50 -> V_57 ;
}
int
F_16 (
T_4 * V_14 ,
T_5 V_58 )
{
T_6 V_59 ;
T_7 V_60 ;
T_8 V_61 ;
int V_62 ;
int V_63 ;
V_61 = F_17 ( V_14 , V_58 ) ;
V_59 = F_18 ( V_14 , V_58 ) ;
V_63 = F_19 ( V_14 , V_58 ) ;
V_60 = F_20 ( V_14 , V_59 , V_63 ) ;
V_62 =
V_61 < V_14 -> V_18 . V_64 &&
V_59 < V_14 -> V_18 . V_65 &&
V_59 != 0 &&
V_63 < ( 1 << V_14 -> V_18 . V_66 ) &&
F_21 ( V_14 , V_61 , V_60 ) == V_58 ;
if ( F_22 ( F_23 ( ! V_62 , V_14 , V_67 ,
V_68 ) ) ) {
F_24 ( V_14 , L_1 ,
( unsigned long long ) V_58 ) ;
F_25 ( L_2 , V_69 , V_14 ) ;
return - V_70 ;
}
return 0 ;
}
int
F_26 (
T_9 * V_71 ,
T_2 * V_49 ,
T_2 * V_72 )
{
struct V_7 * args ;
int error ;
ASSERT ( F_13 ( F_14 ( V_49 ) -> V_51 ) ) ;
error = F_16 ( V_71 -> V_73 , V_72 -> V_74 ) ;
if ( error )
return error ;
args = F_7 ( sizeof( * args ) , V_28 | V_75 ) ;
if ( ! args )
return - V_31 ;
args -> V_76 = V_49 -> V_77 -> V_27 ;
args -> V_49 = V_49 ;
args -> V_78 = V_71 ;
error = F_27 ( args , V_72 -> V_74 ) ;
F_8 ( args ) ;
return error ;
}
int
F_28 (
T_9 * V_71 ,
T_2 * V_49 ,
struct V_1 * V_2 ,
T_5 V_79 ,
T_10 * V_80 ,
struct V_81 * V_82 ,
T_11 V_83 )
{
struct V_7 * args ;
int V_84 ;
int V_85 ;
ASSERT ( F_13 ( F_14 ( V_49 ) -> V_51 ) ) ;
if ( V_79 ) {
V_84 = F_16 ( V_71 -> V_73 , V_79 ) ;
if ( V_84 )
return V_84 ;
F_29 ( V_49 -> V_77 , V_86 ) ;
}
args = F_7 ( sizeof( * args ) , V_28 | V_75 ) ;
if ( ! args )
return - V_31 ;
args -> V_76 = V_49 -> V_77 -> V_27 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_87 = V_2 -> type ;
args -> V_88 = V_49 -> V_77 -> V_46 -> V_89 ( V_2 ) ;
args -> V_90 = V_79 ;
args -> V_49 = V_49 ;
args -> V_91 = V_80 ;
args -> V_82 = V_82 ;
args -> V_83 = V_83 ;
args -> V_92 = V_93 ;
args -> V_78 = V_71 ;
args -> V_94 = V_95 | V_96 ;
if ( ! V_79 )
args -> V_94 |= V_97 ;
if ( V_49 -> V_52 . V_98 == V_99 ) {
V_84 = F_30 ( args ) ;
goto V_100;
}
V_84 = F_31 ( args , & V_85 ) ;
if ( V_84 )
goto V_100;
if ( V_85 ) {
V_84 = F_32 ( args ) ;
goto V_100;
}
V_84 = F_33 ( args , & V_85 ) ;
if ( V_84 )
goto V_100;
if ( V_85 )
V_84 = F_34 ( args ) ;
else
V_84 = F_35 ( args ) ;
V_100:
F_8 ( args ) ;
return V_84 ;
}
int
F_36 (
struct V_7 * args ,
const unsigned char * V_2 ,
int V_5 )
{
if ( args -> V_101 == V_10 )
return - V_102 ;
if ( args -> V_101 != V_12 ||
! ( args -> V_94 & V_103 ) )
return - V_104 ;
args -> V_105 = F_37 ( V_5 , V_75 | V_29 ) ;
if ( ! args -> V_105 )
return - V_31 ;
memcpy ( args -> V_105 , V_2 , V_5 ) ;
args -> V_106 = V_5 ;
return - V_104 ;
}
int
F_38 (
T_9 * V_71 ,
T_2 * V_49 ,
struct V_1 * V_2 ,
T_5 * V_79 ,
struct V_1 * V_107 )
{
struct V_7 * args ;
int V_84 ;
int V_85 ;
int V_108 ;
ASSERT ( F_13 ( F_14 ( V_49 ) -> V_51 ) ) ;
F_29 ( V_49 -> V_77 , V_109 ) ;
args = F_7 ( sizeof( * args ) , V_28 | V_75 ) ;
args -> V_76 = V_49 -> V_77 -> V_27 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_87 = V_2 -> type ;
args -> V_88 = V_49 -> V_77 -> V_46 -> V_89 ( V_2 ) ;
args -> V_49 = V_49 ;
args -> V_92 = V_93 ;
args -> V_78 = V_71 ;
args -> V_94 = V_96 ;
if ( V_107 )
args -> V_94 |= V_103 ;
V_108 = F_39 ( V_49 ) ;
if ( V_49 -> V_52 . V_98 == V_99 ) {
V_84 = F_40 ( args ) ;
goto V_110;
}
V_84 = F_31 ( args , & V_85 ) ;
if ( V_84 )
goto V_100;
if ( V_85 ) {
V_84 = F_41 ( args ) ;
goto V_110;
}
V_84 = F_33 ( args , & V_85 ) ;
if ( V_84 )
goto V_100;
if ( V_85 )
V_84 = F_42 ( args ) ;
else
V_84 = F_43 ( args ) ;
V_110:
if ( V_84 == - V_104 )
V_84 = 0 ;
if ( ! V_84 ) {
* V_79 = args -> V_90 ;
if ( V_107 ) {
V_107 -> V_2 = args -> V_105 ;
V_107 -> V_5 = args -> V_106 ;
}
}
V_100:
F_44 ( V_49 , V_108 ) ;
F_8 ( args ) ;
return V_84 ;
}
int
F_45 (
T_9 * V_71 ,
T_2 * V_49 ,
struct V_1 * V_2 ,
T_5 V_58 ,
T_10 * V_80 ,
struct V_81 * V_82 ,
T_11 V_83 )
{
struct V_7 * args ;
int V_84 ;
int V_85 ;
ASSERT ( F_13 ( F_14 ( V_49 ) -> V_51 ) ) ;
F_29 ( V_49 -> V_77 , V_111 ) ;
args = F_7 ( sizeof( * args ) , V_28 | V_75 ) ;
if ( ! args )
return - V_31 ;
args -> V_76 = V_49 -> V_77 -> V_27 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_87 = V_2 -> type ;
args -> V_88 = V_49 -> V_77 -> V_46 -> V_89 ( V_2 ) ;
args -> V_90 = V_58 ;
args -> V_49 = V_49 ;
args -> V_91 = V_80 ;
args -> V_82 = V_82 ;
args -> V_83 = V_83 ;
args -> V_92 = V_93 ;
args -> V_78 = V_71 ;
if ( V_49 -> V_52 . V_98 == V_99 ) {
V_84 = F_46 ( args ) ;
goto V_100;
}
V_84 = F_31 ( args , & V_85 ) ;
if ( V_84 )
goto V_100;
if ( V_85 ) {
V_84 = F_47 ( args ) ;
goto V_100;
}
V_84 = F_33 ( args , & V_85 ) ;
if ( V_84 )
goto V_100;
if ( V_85 )
V_84 = F_48 ( args ) ;
else
V_84 = F_49 ( args ) ;
V_100:
F_8 ( args ) ;
return V_84 ;
}
int
F_50 (
T_9 * V_71 ,
T_2 * V_49 ,
struct V_1 * V_2 ,
T_5 V_79 ,
T_10 * V_80 ,
struct V_81 * V_82 ,
T_11 V_83 )
{
struct V_7 * args ;
int V_84 ;
int V_85 ;
ASSERT ( F_13 ( F_14 ( V_49 ) -> V_51 ) ) ;
V_84 = F_16 ( V_71 -> V_73 , V_79 ) ;
if ( V_84 )
return V_84 ;
args = F_7 ( sizeof( * args ) , V_28 | V_75 ) ;
if ( ! args )
return - V_31 ;
args -> V_76 = V_49 -> V_77 -> V_27 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_87 = V_2 -> type ;
args -> V_88 = V_49 -> V_77 -> V_46 -> V_89 ( V_2 ) ;
args -> V_90 = V_79 ;
args -> V_49 = V_49 ;
args -> V_91 = V_80 ;
args -> V_82 = V_82 ;
args -> V_83 = V_83 ;
args -> V_92 = V_93 ;
args -> V_78 = V_71 ;
if ( V_49 -> V_52 . V_98 == V_99 ) {
V_84 = F_51 ( args ) ;
goto V_100;
}
V_84 = F_31 ( args , & V_85 ) ;
if ( V_84 )
goto V_100;
if ( V_85 ) {
V_84 = F_52 ( args ) ;
goto V_100;
}
V_84 = F_33 ( args , & V_85 ) ;
if ( V_84 )
goto V_100;
if ( V_85 )
V_84 = F_53 ( args ) ;
else
V_84 = F_54 ( args ) ;
V_100:
F_8 ( args ) ;
return V_84 ;
}
int
F_55 (
T_9 * V_71 ,
T_2 * V_49 ,
struct V_1 * V_2 )
{
return F_28 ( V_71 , V_49 , V_2 , 0 , NULL , NULL , 0 ) ;
}
int
F_56 (
struct V_7 * args ,
int V_112 ,
T_12 * V_113 )
{
struct V_114 * V_49 = args -> V_49 ;
struct V_13 * V_14 = V_49 -> V_77 ;
T_13 V_115 ;
int V_57 ;
int error ;
F_57 ( args , V_112 ) ;
V_115 = F_58 ( V_14 , V_112 * V_116 ) ;
V_57 = args -> V_76 -> V_35 ;
error = F_59 ( args , & V_115 , V_57 ) ;
if ( error )
return error ;
* V_113 = F_60 ( args -> V_76 , ( V_117 ) V_115 ) ;
if ( V_112 == V_118 ) {
T_14 V_119 ;
V_119 = F_61 ( V_14 , V_115 + V_57 ) ;
if ( V_119 > V_49 -> V_52 . V_53 ) {
V_49 -> V_52 . V_53 = V_119 ;
F_62 ( args -> V_78 , V_49 , V_120 ) ;
}
}
return 0 ;
}
int
F_31 (
struct V_7 * args ,
int * V_121 )
{
T_13 V_122 ;
int V_84 ;
if ( ( V_84 = F_63 ( args -> V_49 , & V_122 , V_93 ) ) )
return V_84 ;
V_84 = F_61 ( args -> V_49 -> V_77 , V_122 ) == args -> V_76 -> V_34 ;
ASSERT ( V_84 == 0 || args -> V_49 -> V_52 . V_53 == args -> V_76 -> V_34 ) ;
* V_121 = V_84 ;
return 0 ;
}
int
F_33 (
struct V_7 * args ,
int * V_121 )
{
T_13 V_122 ;
int V_84 ;
if ( ( V_84 = F_63 ( args -> V_49 , & V_122 , V_93 ) ) )
return V_84 ;
* V_121 = V_122 == args -> V_76 -> V_38 + args -> V_76 -> V_35 ;
return 0 ;
}
int
F_64 (
T_15 * args ,
T_12 V_123 ,
struct V_124 * V_125 )
{
T_13 V_115 ;
V_117 V_126 ;
int V_127 ;
T_2 * V_49 ;
int error ;
T_4 * V_14 ;
T_9 * V_71 ;
F_65 ( args , V_123 ) ;
V_49 = args -> V_49 ;
V_14 = V_49 -> V_77 ;
V_71 = args -> V_78 ;
V_126 = F_66 ( args -> V_76 , V_123 ) ;
error = F_67 ( V_71 , V_49 , V_126 , args -> V_76 -> V_35 , 0 , 0 ,
args -> V_91 , args -> V_82 , & V_127 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_127 ) ;
F_68 ( V_71 , V_125 ) ;
if ( V_123 >= F_69 ( args -> V_76 , V_39 ) )
return 0 ;
if ( V_49 -> V_52 . V_53 > F_70 ( args -> V_76 , V_123 + 1 , 0 ) )
return 0 ;
V_115 = V_126 ;
if ( ( error = F_71 ( V_71 , V_49 , & V_115 , V_93 ) ) ) {
return error ;
}
if ( V_123 == args -> V_76 -> V_36 )
ASSERT ( V_115 == 0 ) ;
else
ASSERT ( V_115 > 0 ) ;
V_49 -> V_52 . V_53 = F_61 ( V_14 , V_115 ) ;
F_62 ( V_71 , V_49 , V_120 ) ;
return 0 ;
}
