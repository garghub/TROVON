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
return V_31 ;
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
ASSERT ( F_13 ( V_49 -> V_51 . V_52 ) ) ;
if ( V_49 -> V_51 . V_53 == 0 )
return 1 ;
if ( V_49 -> V_51 . V_53 > F_14 ( V_49 ) )
return 0 ;
V_50 = ( T_3 * ) V_49 -> V_54 . V_55 . V_56 ;
return ! V_50 -> V_57 ;
}
int
F_15 (
T_4 * V_14 ,
T_5 V_58 )
{
T_6 V_59 ;
T_7 V_60 ;
T_8 V_61 ;
int V_62 ;
int V_63 ;
V_61 = F_16 ( V_14 , V_58 ) ;
V_59 = F_17 ( V_14 , V_58 ) ;
V_63 = F_18 ( V_14 , V_58 ) ;
V_60 = F_19 ( V_14 , V_59 , V_63 ) ;
V_62 =
V_61 < V_14 -> V_18 . V_64 &&
V_59 < V_14 -> V_18 . V_65 &&
V_59 != 0 &&
V_63 < ( 1 << V_14 -> V_18 . V_66 ) &&
F_20 ( V_14 , V_61 , V_60 ) == V_58 ;
if ( F_21 ( F_22 ( ! V_62 , V_14 , V_67 ,
V_68 ) ) ) {
F_23 ( V_14 , L_1 ,
( unsigned long long ) V_58 ) ;
F_24 ( L_2 , V_69 , V_14 ) ;
return F_25 ( V_70 ) ;
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
ASSERT ( F_13 ( V_49 -> V_51 . V_52 ) ) ;
error = F_15 ( V_71 -> V_73 , V_72 -> V_74 ) ;
if ( error )
return error ;
args = F_7 ( sizeof( * args ) , V_28 | V_75 ) ;
if ( ! args )
return V_31 ;
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
T_11 * V_81 ,
T_12 V_82 )
{
struct V_7 * args ;
int V_83 ;
int V_84 ;
ASSERT ( F_13 ( V_49 -> V_51 . V_52 ) ) ;
V_83 = F_15 ( V_71 -> V_73 , V_79 ) ;
if ( V_83 )
return V_83 ;
F_29 ( V_85 ) ;
args = F_7 ( sizeof( * args ) , V_28 | V_75 ) ;
if ( ! args )
return V_31 ;
args -> V_76 = V_49 -> V_77 -> V_27 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_86 = V_2 -> type ;
args -> V_87 = V_49 -> V_77 -> V_46 -> V_88 ( V_2 ) ;
args -> V_89 = V_79 ;
args -> V_49 = V_49 ;
args -> V_90 = V_80 ;
args -> V_81 = V_81 ;
args -> V_82 = V_82 ;
args -> V_91 = V_92 ;
args -> V_78 = V_71 ;
args -> V_93 = V_94 | V_95 ;
if ( V_49 -> V_51 . V_96 == V_97 ) {
V_83 = F_30 ( args ) ;
goto V_98;
}
V_83 = F_31 ( args , & V_84 ) ;
if ( V_83 )
goto V_98;
if ( V_84 ) {
V_83 = F_32 ( args ) ;
goto V_98;
}
V_83 = F_33 ( args , & V_84 ) ;
if ( V_83 )
goto V_98;
if ( V_84 )
V_83 = F_34 ( args ) ;
else
V_83 = F_35 ( args ) ;
V_98:
F_8 ( args ) ;
return V_83 ;
}
int
F_36 (
struct V_7 * args ,
const unsigned char * V_2 ,
int V_5 )
{
if ( args -> V_99 == V_10 )
return V_100 ;
if ( args -> V_99 != V_12 ||
! ( args -> V_93 & V_101 ) )
return V_102 ;
args -> V_103 = F_37 ( V_5 , V_75 | V_29 ) ;
if ( ! args -> V_103 )
return V_31 ;
memcpy ( args -> V_103 , V_2 , V_5 ) ;
args -> V_104 = V_5 ;
return V_102 ;
}
int
F_38 (
T_9 * V_71 ,
T_2 * V_49 ,
struct V_1 * V_2 ,
T_5 * V_79 ,
struct V_1 * V_105 )
{
struct V_7 * args ;
int V_83 ;
int V_84 ;
ASSERT ( F_13 ( V_49 -> V_51 . V_52 ) ) ;
F_29 ( V_106 ) ;
args = F_7 ( sizeof( * args ) , V_28 | V_75 ) ;
args -> V_76 = V_49 -> V_77 -> V_27 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_86 = V_2 -> type ;
args -> V_87 = V_49 -> V_77 -> V_46 -> V_88 ( V_2 ) ;
args -> V_49 = V_49 ;
args -> V_91 = V_92 ;
args -> V_78 = V_71 ;
args -> V_93 = V_95 ;
if ( V_105 )
args -> V_93 |= V_101 ;
if ( V_49 -> V_51 . V_96 == V_97 ) {
V_83 = F_39 ( args ) ;
goto V_107;
}
V_83 = F_31 ( args , & V_84 ) ;
if ( V_83 )
goto V_98;
if ( V_84 ) {
V_83 = F_40 ( args ) ;
goto V_107;
}
V_83 = F_33 ( args , & V_84 ) ;
if ( V_83 )
goto V_98;
if ( V_84 )
V_83 = F_41 ( args ) ;
else
V_83 = F_42 ( args ) ;
V_107:
if ( V_83 == V_102 )
V_83 = 0 ;
if ( ! V_83 ) {
* V_79 = args -> V_89 ;
if ( V_105 ) {
V_105 -> V_2 = args -> V_103 ;
V_105 -> V_5 = args -> V_104 ;
}
}
V_98:
F_8 ( args ) ;
return V_83 ;
}
int
F_43 (
T_9 * V_71 ,
T_2 * V_49 ,
struct V_1 * V_2 ,
T_5 V_58 ,
T_10 * V_80 ,
T_11 * V_81 ,
T_12 V_82 )
{
struct V_7 * args ;
int V_83 ;
int V_84 ;
ASSERT ( F_13 ( V_49 -> V_51 . V_52 ) ) ;
F_29 ( V_108 ) ;
args = F_7 ( sizeof( * args ) , V_28 | V_75 ) ;
if ( ! args )
return V_31 ;
args -> V_76 = V_49 -> V_77 -> V_27 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_86 = V_2 -> type ;
args -> V_87 = V_49 -> V_77 -> V_46 -> V_88 ( V_2 ) ;
args -> V_89 = V_58 ;
args -> V_49 = V_49 ;
args -> V_90 = V_80 ;
args -> V_81 = V_81 ;
args -> V_82 = V_82 ;
args -> V_91 = V_92 ;
args -> V_78 = V_71 ;
if ( V_49 -> V_51 . V_96 == V_97 ) {
V_83 = F_44 ( args ) ;
goto V_98;
}
V_83 = F_31 ( args , & V_84 ) ;
if ( V_83 )
goto V_98;
if ( V_84 ) {
V_83 = F_45 ( args ) ;
goto V_98;
}
V_83 = F_33 ( args , & V_84 ) ;
if ( V_83 )
goto V_98;
if ( V_84 )
V_83 = F_46 ( args ) ;
else
V_83 = F_47 ( args ) ;
V_98:
F_8 ( args ) ;
return V_83 ;
}
int
F_48 (
T_9 * V_71 ,
T_2 * V_49 ,
struct V_1 * V_2 ,
T_5 V_79 ,
T_10 * V_80 ,
T_11 * V_81 ,
T_12 V_82 )
{
struct V_7 * args ;
int V_83 ;
int V_84 ;
ASSERT ( F_13 ( V_49 -> V_51 . V_52 ) ) ;
V_83 = F_15 ( V_71 -> V_73 , V_79 ) ;
if ( V_83 )
return V_83 ;
args = F_7 ( sizeof( * args ) , V_28 | V_75 ) ;
if ( ! args )
return V_31 ;
args -> V_76 = V_49 -> V_77 -> V_27 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_86 = V_2 -> type ;
args -> V_87 = V_49 -> V_77 -> V_46 -> V_88 ( V_2 ) ;
args -> V_89 = V_79 ;
args -> V_49 = V_49 ;
args -> V_90 = V_80 ;
args -> V_81 = V_81 ;
args -> V_82 = V_82 ;
args -> V_91 = V_92 ;
args -> V_78 = V_71 ;
if ( V_49 -> V_51 . V_96 == V_97 ) {
V_83 = F_49 ( args ) ;
goto V_98;
}
V_83 = F_31 ( args , & V_84 ) ;
if ( V_83 )
goto V_98;
if ( V_84 ) {
V_83 = F_50 ( args ) ;
goto V_98;
}
V_83 = F_33 ( args , & V_84 ) ;
if ( V_83 )
goto V_98;
if ( V_84 )
V_83 = F_51 ( args ) ;
else
V_83 = F_52 ( args ) ;
V_98:
F_8 ( args ) ;
return V_83 ;
}
int
F_53 (
T_9 * V_71 ,
T_2 * V_49 ,
struct V_1 * V_2 ,
V_43 V_109 )
{
struct V_7 * args ;
int V_83 ;
int V_84 ;
if ( V_109 )
return 0 ;
ASSERT ( F_13 ( V_49 -> V_51 . V_52 ) ) ;
args = F_7 ( sizeof( * args ) , V_28 | V_75 ) ;
if ( ! args )
return V_31 ;
args -> V_76 = V_49 -> V_77 -> V_27 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_86 = V_2 -> type ;
args -> V_87 = V_49 -> V_77 -> V_46 -> V_88 ( V_2 ) ;
args -> V_49 = V_49 ;
args -> V_91 = V_92 ;
args -> V_78 = V_71 ;
args -> V_93 = V_110 | V_94 |
V_95 ;
if ( V_49 -> V_51 . V_96 == V_97 ) {
V_83 = F_30 ( args ) ;
goto V_98;
}
V_83 = F_31 ( args , & V_84 ) ;
if ( V_83 )
goto V_98;
if ( V_84 ) {
V_83 = F_32 ( args ) ;
goto V_98;
}
V_83 = F_33 ( args , & V_84 ) ;
if ( V_83 )
goto V_98;
if ( V_84 )
V_83 = F_34 ( args ) ;
else
V_83 = F_35 ( args ) ;
V_98:
F_8 ( args ) ;
return V_83 ;
}
int
F_54 (
struct V_7 * args ,
int V_111 ,
T_13 * V_112 )
{
struct V_113 * V_49 = args -> V_49 ;
struct V_13 * V_14 = V_49 -> V_77 ;
T_14 V_114 ;
int V_57 ;
int error ;
F_55 ( args , V_111 ) ;
V_114 = F_56 ( V_14 , V_111 * V_115 ) ;
V_57 = args -> V_76 -> V_35 ;
error = F_57 ( args , & V_114 , V_57 ) ;
if ( error )
return error ;
* V_112 = F_58 ( args -> V_76 , ( V_116 ) V_114 ) ;
if ( V_111 == V_117 ) {
T_15 V_118 ;
V_118 = F_59 ( V_14 , V_114 + V_57 ) ;
if ( V_118 > V_49 -> V_51 . V_53 ) {
V_49 -> V_51 . V_53 = V_118 ;
F_60 ( args -> V_78 , V_49 , V_119 ) ;
}
}
return 0 ;
}
int
F_31 (
struct V_7 * args ,
int * V_120 )
{
T_14 V_121 ;
int V_83 ;
if ( ( V_83 = F_61 ( args -> V_49 , & V_121 , V_92 ) ) )
return V_83 ;
V_83 = F_59 ( args -> V_49 -> V_77 , V_121 ) == args -> V_76 -> V_34 ;
ASSERT ( V_83 == 0 || args -> V_49 -> V_51 . V_53 == args -> V_76 -> V_34 ) ;
* V_120 = V_83 ;
return 0 ;
}
int
F_33 (
struct V_7 * args ,
int * V_120 )
{
T_14 V_121 ;
int V_83 ;
if ( ( V_83 = F_61 ( args -> V_49 , & V_121 , V_92 ) ) )
return V_83 ;
* V_120 = V_121 == args -> V_76 -> V_38 + args -> V_76 -> V_35 ;
return 0 ;
}
int
F_62 (
T_16 * args ,
T_13 V_122 ,
struct V_123 * V_124 )
{
T_14 V_114 ;
V_116 V_125 ;
int V_126 ;
T_2 * V_49 ;
int error ;
T_4 * V_14 ;
T_9 * V_71 ;
F_63 ( args , V_122 ) ;
V_49 = args -> V_49 ;
V_14 = V_49 -> V_77 ;
V_71 = args -> V_78 ;
V_125 = F_64 ( args -> V_76 , V_122 ) ;
if ( ( error = F_65 ( V_71 , V_49 , V_125 , args -> V_76 -> V_35 ,
V_127 , 0 , args -> V_90 , args -> V_81 ,
& V_126 ) ) ) {
return error ;
}
ASSERT ( V_126 ) ;
F_66 ( V_71 , V_124 ) ;
if ( V_122 >= F_67 ( args -> V_76 , V_39 ) )
return 0 ;
if ( V_49 -> V_51 . V_53 > F_68 ( args -> V_76 , V_122 + 1 , 0 ) )
return 0 ;
V_114 = V_125 ;
if ( ( error = F_69 ( V_71 , V_49 , & V_114 , V_92 ) ) ) {
return error ;
}
if ( V_122 == args -> V_76 -> V_36 )
ASSERT ( V_114 == 0 ) ;
else
ASSERT ( V_114 > 0 ) ;
V_49 -> V_51 . V_53 = F_59 ( V_14 , V_114 ) ;
F_60 ( V_71 , V_49 , V_119 ) ;
return 0 ;
}
