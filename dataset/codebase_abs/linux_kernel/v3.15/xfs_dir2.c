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
struct V_7 * args ;
int error ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
error = F_16 ( V_58 -> V_60 , V_59 -> V_61 ) ;
if ( error )
return error ;
args = F_28 ( sizeof( * args ) , V_62 | V_63 ) ;
if ( ! args )
return V_64 ;
args -> V_36 = V_36 ;
args -> V_65 = V_58 ;
error = F_29 ( args , V_59 -> V_61 ) ;
F_30 ( args ) ;
return error ;
}
int
F_31 (
T_9 * V_58 ,
T_3 * V_36 ,
struct V_1 * V_2 ,
T_5 V_66 ,
T_10 * V_67 ,
T_11 * V_68 ,
T_12 V_69 )
{
struct V_7 * args ;
int V_70 ;
int V_71 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
V_70 = F_16 ( V_58 -> V_60 , V_66 ) ;
if ( V_70 )
return V_70 ;
F_32 ( V_72 ) ;
args = F_28 ( sizeof( * args ) , V_62 | V_63 ) ;
if ( ! args )
return V_64 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_73 = V_2 -> type ;
args -> V_74 = V_36 -> V_75 -> V_33 -> V_76 ( V_2 ) ;
args -> V_77 = V_66 ;
args -> V_36 = V_36 ;
args -> V_78 = V_67 ;
args -> V_68 = V_68 ;
args -> V_69 = V_69 ;
args -> V_79 = V_80 ;
args -> V_65 = V_58 ;
args -> V_81 = V_82 | V_83 ;
if ( V_36 -> V_38 . V_84 == V_85 ) {
V_70 = F_33 ( args ) ;
goto V_86;
}
V_70 = F_34 ( V_58 , V_36 , & V_71 ) ;
if ( V_70 )
goto V_86;
if ( V_71 ) {
V_70 = F_35 ( args ) ;
goto V_86;
}
V_70 = F_36 ( V_58 , V_36 , & V_71 ) ;
if ( V_70 )
goto V_86;
if ( V_71 )
V_70 = F_37 ( args ) ;
else
V_70 = F_38 ( args ) ;
V_86:
F_30 ( args ) ;
return V_70 ;
}
int
F_39 (
struct V_7 * args ,
const unsigned char * V_2 ,
int V_5 )
{
if ( args -> V_87 == V_10 )
return V_88 ;
if ( args -> V_87 != V_12 ||
! ( args -> V_81 & V_89 ) )
return V_90 ;
args -> V_91 = F_40 ( V_5 , V_63 | V_92 ) ;
if ( ! args -> V_91 )
return V_64 ;
memcpy ( args -> V_91 , V_2 , V_5 ) ;
args -> V_93 = V_5 ;
return V_90 ;
}
int
F_41 (
T_9 * V_58 ,
T_3 * V_36 ,
struct V_1 * V_2 ,
T_5 * V_66 ,
struct V_1 * V_94 )
{
struct V_7 * args ;
int V_70 ;
int V_71 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
F_32 ( V_95 ) ;
args = F_28 ( sizeof( * args ) , V_62 | V_63 ) ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_73 = V_2 -> type ;
args -> V_74 = V_36 -> V_75 -> V_33 -> V_76 ( V_2 ) ;
args -> V_36 = V_36 ;
args -> V_79 = V_80 ;
args -> V_65 = V_58 ;
args -> V_81 = V_83 ;
if ( V_94 )
args -> V_81 |= V_89 ;
if ( V_36 -> V_38 . V_84 == V_85 ) {
V_70 = F_42 ( args ) ;
goto V_96;
}
V_70 = F_34 ( V_58 , V_36 , & V_71 ) ;
if ( V_70 )
goto V_86;
if ( V_71 ) {
V_70 = F_43 ( args ) ;
goto V_96;
}
V_70 = F_36 ( V_58 , V_36 , & V_71 ) ;
if ( V_70 )
goto V_86;
if ( V_71 )
V_70 = F_44 ( args ) ;
else
V_70 = F_45 ( args ) ;
V_96:
if ( V_70 == V_90 )
V_70 = 0 ;
if ( ! V_70 ) {
* V_66 = args -> V_77 ;
if ( V_94 ) {
V_94 -> V_2 = args -> V_91 ;
V_94 -> V_5 = args -> V_93 ;
}
}
V_86:
F_30 ( args ) ;
return V_70 ;
}
int
F_46 (
T_9 * V_58 ,
T_3 * V_36 ,
struct V_1 * V_2 ,
T_5 V_45 ,
T_10 * V_67 ,
T_11 * V_68 ,
T_12 V_69 )
{
struct V_7 * args ;
int V_70 ;
int V_71 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
F_32 ( V_97 ) ;
args = F_28 ( sizeof( * args ) , V_62 | V_63 ) ;
if ( ! args )
return V_64 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_73 = V_2 -> type ;
args -> V_74 = V_36 -> V_75 -> V_33 -> V_76 ( V_2 ) ;
args -> V_77 = V_45 ;
args -> V_36 = V_36 ;
args -> V_78 = V_67 ;
args -> V_68 = V_68 ;
args -> V_69 = V_69 ;
args -> V_79 = V_80 ;
args -> V_65 = V_58 ;
if ( V_36 -> V_38 . V_84 == V_85 ) {
V_70 = F_47 ( args ) ;
goto V_86;
}
V_70 = F_34 ( V_58 , V_36 , & V_71 ) ;
if ( V_70 )
goto V_86;
if ( V_71 ) {
V_70 = F_48 ( args ) ;
goto V_86;
}
V_70 = F_36 ( V_58 , V_36 , & V_71 ) ;
if ( V_70 )
goto V_86;
if ( V_71 )
V_70 = F_49 ( args ) ;
else
V_70 = F_50 ( args ) ;
V_86:
F_30 ( args ) ;
return V_70 ;
}
int
F_51 (
T_9 * V_58 ,
T_3 * V_36 ,
struct V_1 * V_2 ,
T_5 V_66 ,
T_10 * V_67 ,
T_11 * V_68 ,
T_12 V_69 )
{
struct V_7 * args ;
int V_70 ;
int V_71 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
V_70 = F_16 ( V_58 -> V_60 , V_66 ) ;
if ( V_70 )
return V_70 ;
args = F_28 ( sizeof( * args ) , V_62 | V_63 ) ;
if ( ! args )
return V_64 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_73 = V_2 -> type ;
args -> V_74 = V_36 -> V_75 -> V_33 -> V_76 ( V_2 ) ;
args -> V_77 = V_66 ;
args -> V_36 = V_36 ;
args -> V_78 = V_67 ;
args -> V_68 = V_68 ;
args -> V_69 = V_69 ;
args -> V_79 = V_80 ;
args -> V_65 = V_58 ;
if ( V_36 -> V_38 . V_84 == V_85 ) {
V_70 = F_52 ( args ) ;
goto V_86;
}
V_70 = F_34 ( V_58 , V_36 , & V_71 ) ;
if ( V_70 )
goto V_86;
if ( V_71 ) {
V_70 = F_53 ( args ) ;
goto V_86;
}
V_70 = F_36 ( V_58 , V_36 , & V_71 ) ;
if ( V_70 )
goto V_86;
if ( V_71 )
V_70 = F_54 ( args ) ;
else
V_70 = F_55 ( args ) ;
V_86:
F_30 ( args ) ;
return V_70 ;
}
int
F_56 (
T_9 * V_58 ,
T_3 * V_36 ,
struct V_1 * V_2 ,
V_29 V_98 )
{
struct V_7 * args ;
int V_70 ;
int V_71 ;
if ( V_98 )
return 0 ;
ASSERT ( F_14 ( V_36 -> V_38 . V_39 ) ) ;
args = F_28 ( sizeof( * args ) , V_62 | V_63 ) ;
if ( ! args )
return V_64 ;
args -> V_2 = V_2 -> V_2 ;
args -> V_9 = V_2 -> V_5 ;
args -> V_73 = V_2 -> type ;
args -> V_74 = V_36 -> V_75 -> V_33 -> V_76 ( V_2 ) ;
args -> V_36 = V_36 ;
args -> V_79 = V_80 ;
args -> V_65 = V_58 ;
args -> V_81 = V_99 | V_82 |
V_83 ;
if ( V_36 -> V_38 . V_84 == V_85 ) {
V_70 = F_33 ( args ) ;
goto V_86;
}
V_70 = F_34 ( V_58 , V_36 , & V_71 ) ;
if ( V_70 )
goto V_86;
if ( V_71 ) {
V_70 = F_35 ( args ) ;
goto V_86;
}
V_70 = F_36 ( V_58 , V_36 , & V_71 ) ;
if ( V_70 )
goto V_86;
if ( V_71 )
V_70 = F_37 ( args ) ;
else
V_70 = F_38 ( args ) ;
V_86:
F_30 ( args ) ;
return V_70 ;
}
int
F_57 (
struct V_7 * args ,
int V_100 ,
T_13 * V_101 )
{
struct V_102 * V_36 = args -> V_36 ;
struct V_103 * V_13 = V_36 -> V_75 ;
T_14 V_104 ;
int V_44 ;
int error ;
F_58 ( args , V_100 ) ;
V_104 = F_59 ( V_13 , V_100 * V_105 ) ;
V_44 = V_13 -> V_22 ;
error = F_60 ( args , & V_104 , V_44 ) ;
if ( error )
return error ;
* V_101 = F_61 ( V_13 , ( V_106 ) V_104 ) ;
if ( V_100 == V_107 ) {
T_15 V_108 ;
V_108 = F_62 ( V_13 , V_104 + V_44 ) ;
if ( V_108 > V_36 -> V_38 . V_40 ) {
V_36 -> V_38 . V_40 = V_108 ;
F_63 ( args -> V_65 , V_36 , V_109 ) ;
}
}
return 0 ;
}
int
F_34 (
T_9 * V_58 ,
T_3 * V_36 ,
int * V_110 )
{
T_14 V_111 ;
T_2 * V_13 ;
int V_70 ;
V_13 = V_36 -> V_75 ;
if ( ( V_70 = F_64 ( V_58 , V_36 , & V_111 , V_80 ) ) )
return V_70 ;
V_70 = F_62 ( V_13 , V_111 ) == V_13 -> V_21 ;
ASSERT ( V_70 == 0 || V_36 -> V_38 . V_40 == V_13 -> V_21 ) ;
* V_110 = V_70 ;
return 0 ;
}
int
F_36 (
T_9 * V_58 ,
T_3 * V_36 ,
int * V_110 )
{
T_14 V_111 ;
T_2 * V_13 ;
int V_70 ;
V_13 = V_36 -> V_75 ;
if ( ( V_70 = F_64 ( V_58 , V_36 , & V_111 , V_80 ) ) )
return V_70 ;
* V_110 = V_111 == V_13 -> V_24 + ( 1 << V_13 -> V_15 . V_17 ) ;
return 0 ;
}
int
F_65 (
T_16 * args ,
T_13 V_112 ,
struct V_113 * V_114 )
{
T_14 V_104 ;
V_106 V_115 ;
int V_116 ;
T_3 * V_36 ;
int error ;
T_2 * V_13 ;
T_9 * V_58 ;
F_66 ( args , V_112 ) ;
V_36 = args -> V_36 ;
V_13 = V_36 -> V_75 ;
V_58 = args -> V_65 ;
V_115 = F_8 ( V_13 , V_112 ) ;
if ( ( error = F_67 ( V_58 , V_36 , V_115 , V_13 -> V_22 ,
V_117 , 0 , args -> V_78 , args -> V_68 ,
& V_116 ) ) ) {
return error ;
}
ASSERT ( V_116 ) ;
F_68 ( V_58 , V_114 ) ;
if ( V_112 >= F_10 ( V_13 ) )
return 0 ;
if ( V_36 -> V_38 . V_40 > F_69 ( V_13 , V_112 + 1 , 0 ) )
return 0 ;
V_104 = V_115 ;
if ( ( error = F_70 ( V_58 , V_36 , & V_104 , V_80 ) ) ) {
return error ;
}
if ( V_112 == V_13 -> V_23 )
ASSERT ( V_104 == 0 ) ;
else
ASSERT ( V_104 > 0 ) ;
V_36 -> V_38 . V_40 = F_62 ( V_13 , V_104 ) ;
F_63 ( V_58 , V_36 , V_109 ) ;
return 0 ;
}
