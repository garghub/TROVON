unsigned char F_1 ( int V_1 )
{
switch ( V_1 & V_2 ) {
case V_3 :
return V_4 ;
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
case V_11 :
return V_12 ;
case V_13 :
return V_14 ;
case V_15 :
return V_16 ;
default:
return V_17 ;
}
}
STATIC T_1
F_2 (
struct V_18 * V_19 )
{
T_1 V_20 ;
int V_21 ;
for ( V_21 = 0 , V_20 = 0 ; V_21 < V_19 -> V_22 ; V_21 ++ )
V_20 = tolower ( V_19 -> V_19 [ V_21 ] ) ^ F_3 ( V_20 , 7 ) ;
return V_20 ;
}
STATIC enum V_23
F_4 (
struct V_24 * args ,
const unsigned char * V_19 ,
int V_22 )
{
enum V_23 V_25 ;
int V_21 ;
if ( args -> V_26 != V_22 )
return V_27 ;
V_25 = V_28 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( args -> V_19 [ V_21 ] == V_19 [ V_21 ] )
continue;
if ( tolower ( args -> V_19 [ V_21 ] ) != tolower ( V_19 [ V_21 ] ) )
return V_27 ;
V_25 = V_29 ;
}
return V_25 ;
}
int
F_5 (
struct V_30 * V_31 )
{
struct V_32 * V_33 ;
int V_34 ;
ASSERT ( V_31 -> V_35 . V_36 & V_37 ) ;
ASSERT ( ( 1 << ( V_31 -> V_35 . V_38 + V_31 -> V_35 . V_39 ) ) <=
V_40 ) ;
V_31 -> V_41 = F_6 ( V_31 , NULL ) ;
V_31 -> V_42 = F_7 ( V_31 , NULL ) ;
V_34 = V_31 -> V_41 -> V_43 ;
V_31 -> V_44 = F_8 ( sizeof( struct V_32 ) ,
V_45 | V_46 ) ;
V_31 -> V_47 = F_8 ( sizeof( struct V_32 ) ,
V_45 | V_46 ) ;
if ( ! V_31 -> V_44 || ! V_31 -> V_47 ) {
F_9 ( V_31 -> V_44 ) ;
F_9 ( V_31 -> V_47 ) ;
return - V_48 ;
}
V_33 = V_31 -> V_44 ;
V_33 -> V_49 = V_31 -> V_35 . V_38 + V_31 -> V_35 . V_39 ;
V_33 -> V_50 = V_31 -> V_35 . V_38 ;
V_33 -> V_51 = 1 << V_33 -> V_49 ;
V_33 -> V_52 = 1 << V_31 -> V_35 . V_39 ;
V_33 -> V_53 = F_10 ( V_33 , V_54 ) ;
V_33 -> V_55 = F_10 ( V_33 , V_56 ) ;
V_33 -> V_57 = F_10 ( V_33 , V_58 ) ;
V_33 -> V_59 = ( V_33 -> V_51 - V_34 ) /
( V_60 ) sizeof( V_61 ) ;
V_33 -> V_62 = ( V_33 -> V_51 * 37 ) / 100 ;
V_33 = V_31 -> V_47 ;
V_33 -> V_49 = V_31 -> V_35 . V_38 ;
V_33 -> V_50 = V_31 -> V_35 . V_38 ;
V_33 -> V_51 = 1 << V_33 -> V_49 ;
V_33 -> V_52 = 1 ;
V_33 -> V_59 = ( V_33 -> V_51 - V_34 ) /
( V_60 ) sizeof( V_61 ) ;
V_33 -> V_62 = ( V_33 -> V_51 * 37 ) / 100 ;
if ( F_11 ( & V_31 -> V_35 ) )
V_31 -> V_63 = & V_64 ;
else
V_31 -> V_63 = & V_65 ;
return 0 ;
}
void
F_12 (
struct V_30 * V_31 )
{
F_9 ( V_31 -> V_44 ) ;
F_9 ( V_31 -> V_47 ) ;
}
int
F_13 (
T_2 * V_66 )
{
T_3 * V_67 ;
ASSERT ( F_14 ( F_15 ( V_66 ) -> V_68 ) ) ;
if ( V_66 -> V_69 . V_70 == 0 )
return 1 ;
if ( V_66 -> V_69 . V_70 > F_16 ( V_66 ) )
return 0 ;
V_67 = ( T_3 * ) V_66 -> V_71 . V_72 . V_73 ;
return ! V_67 -> V_74 ;
}
int
F_17 (
T_4 * V_31 ,
T_5 V_75 )
{
T_6 V_76 ;
T_7 V_77 ;
T_8 V_78 ;
int V_79 ;
int V_80 ;
V_78 = F_18 ( V_31 , V_75 ) ;
V_76 = F_19 ( V_31 , V_75 ) ;
V_80 = F_20 ( V_31 , V_75 ) ;
V_77 = F_21 ( V_31 , V_76 , V_80 ) ;
V_79 =
V_78 < V_31 -> V_35 . V_81 &&
V_76 < V_31 -> V_35 . V_82 &&
V_76 != 0 &&
V_80 < ( 1 << V_31 -> V_35 . V_83 ) &&
F_22 ( V_31 , V_78 , V_77 ) == V_75 ;
if ( F_23 ( F_24 ( ! V_79 , V_31 , V_84 ,
V_85 ) ) ) {
F_25 ( V_31 , L_1 ,
( unsigned long long ) V_75 ) ;
F_26 ( L_2 , V_86 , V_31 ) ;
return - V_87 ;
}
return 0 ;
}
int
F_27 (
T_9 * V_88 ,
T_2 * V_66 ,
T_2 * V_89 )
{
struct V_24 * args ;
int error ;
ASSERT ( F_14 ( F_15 ( V_66 ) -> V_68 ) ) ;
error = F_17 ( V_88 -> V_90 , V_89 -> V_91 ) ;
if ( error )
return error ;
args = F_8 ( sizeof( * args ) , V_45 | V_92 ) ;
if ( ! args )
return - V_48 ;
args -> V_93 = V_66 -> V_94 -> V_44 ;
args -> V_66 = V_66 ;
args -> V_95 = V_88 ;
error = F_28 ( args , V_89 -> V_91 ) ;
F_9 ( args ) ;
return error ;
}
int
F_29 (
T_9 * V_88 ,
T_2 * V_66 ,
struct V_18 * V_19 ,
T_5 V_96 ,
T_10 * V_97 ,
struct V_98 * V_99 ,
T_11 V_100 )
{
struct V_24 * args ;
int V_101 ;
int V_102 ;
ASSERT ( F_14 ( F_15 ( V_66 ) -> V_68 ) ) ;
if ( V_96 ) {
V_101 = F_17 ( V_88 -> V_90 , V_96 ) ;
if ( V_101 )
return V_101 ;
F_30 ( V_66 -> V_94 , V_103 ) ;
}
args = F_8 ( sizeof( * args ) , V_45 | V_92 ) ;
if ( ! args )
return - V_48 ;
args -> V_93 = V_66 -> V_94 -> V_44 ;
args -> V_19 = V_19 -> V_19 ;
args -> V_26 = V_19 -> V_22 ;
args -> V_104 = V_19 -> type ;
args -> V_105 = V_66 -> V_94 -> V_63 -> V_106 ( V_19 ) ;
args -> V_107 = V_96 ;
args -> V_66 = V_66 ;
args -> V_108 = V_97 ;
args -> V_99 = V_99 ;
args -> V_100 = V_100 ;
args -> V_109 = V_110 ;
args -> V_95 = V_88 ;
args -> V_111 = V_112 | V_113 ;
if ( ! V_96 )
args -> V_111 |= V_114 ;
if ( V_66 -> V_69 . V_115 == V_116 ) {
V_101 = F_31 ( args ) ;
goto V_117;
}
V_101 = F_32 ( args , & V_102 ) ;
if ( V_101 )
goto V_117;
if ( V_102 ) {
V_101 = F_33 ( args ) ;
goto V_117;
}
V_101 = F_34 ( args , & V_102 ) ;
if ( V_101 )
goto V_117;
if ( V_102 )
V_101 = F_35 ( args ) ;
else
V_101 = F_36 ( args ) ;
V_117:
F_9 ( args ) ;
return V_101 ;
}
int
F_37 (
struct V_24 * args ,
const unsigned char * V_19 ,
int V_22 )
{
if ( args -> V_118 == V_27 )
return - V_119 ;
if ( args -> V_118 != V_29 ||
! ( args -> V_111 & V_120 ) )
return - V_121 ;
args -> V_122 = F_38 ( V_22 , V_92 | V_46 ) ;
if ( ! args -> V_122 )
return - V_48 ;
memcpy ( args -> V_122 , V_19 , V_22 ) ;
args -> V_123 = V_22 ;
return - V_121 ;
}
int
F_39 (
T_9 * V_88 ,
T_2 * V_66 ,
struct V_18 * V_19 ,
T_5 * V_96 ,
struct V_18 * V_124 )
{
struct V_24 * args ;
int V_101 ;
int V_102 ;
int V_125 ;
ASSERT ( F_14 ( F_15 ( V_66 ) -> V_68 ) ) ;
F_30 ( V_66 -> V_94 , V_126 ) ;
args = F_8 ( sizeof( * args ) , V_45 | V_92 ) ;
args -> V_93 = V_66 -> V_94 -> V_44 ;
args -> V_19 = V_19 -> V_19 ;
args -> V_26 = V_19 -> V_22 ;
args -> V_104 = V_19 -> type ;
args -> V_105 = V_66 -> V_94 -> V_63 -> V_106 ( V_19 ) ;
args -> V_66 = V_66 ;
args -> V_109 = V_110 ;
args -> V_95 = V_88 ;
args -> V_111 = V_113 ;
if ( V_124 )
args -> V_111 |= V_120 ;
V_125 = F_40 ( V_66 ) ;
if ( V_66 -> V_69 . V_115 == V_116 ) {
V_101 = F_41 ( args ) ;
goto V_127;
}
V_101 = F_32 ( args , & V_102 ) ;
if ( V_101 )
goto V_117;
if ( V_102 ) {
V_101 = F_42 ( args ) ;
goto V_127;
}
V_101 = F_34 ( args , & V_102 ) ;
if ( V_101 )
goto V_117;
if ( V_102 )
V_101 = F_43 ( args ) ;
else
V_101 = F_44 ( args ) ;
V_127:
if ( V_101 == - V_121 )
V_101 = 0 ;
if ( ! V_101 ) {
* V_96 = args -> V_107 ;
if ( V_124 ) {
V_124 -> V_19 = args -> V_122 ;
V_124 -> V_22 = args -> V_123 ;
}
}
V_117:
F_45 ( V_66 , V_125 ) ;
F_9 ( args ) ;
return V_101 ;
}
int
F_46 (
T_9 * V_88 ,
T_2 * V_66 ,
struct V_18 * V_19 ,
T_5 V_75 ,
T_10 * V_97 ,
struct V_98 * V_99 ,
T_11 V_100 )
{
struct V_24 * args ;
int V_101 ;
int V_102 ;
ASSERT ( F_14 ( F_15 ( V_66 ) -> V_68 ) ) ;
F_30 ( V_66 -> V_94 , V_128 ) ;
args = F_8 ( sizeof( * args ) , V_45 | V_92 ) ;
if ( ! args )
return - V_48 ;
args -> V_93 = V_66 -> V_94 -> V_44 ;
args -> V_19 = V_19 -> V_19 ;
args -> V_26 = V_19 -> V_22 ;
args -> V_104 = V_19 -> type ;
args -> V_105 = V_66 -> V_94 -> V_63 -> V_106 ( V_19 ) ;
args -> V_107 = V_75 ;
args -> V_66 = V_66 ;
args -> V_108 = V_97 ;
args -> V_99 = V_99 ;
args -> V_100 = V_100 ;
args -> V_109 = V_110 ;
args -> V_95 = V_88 ;
if ( V_66 -> V_69 . V_115 == V_116 ) {
V_101 = F_47 ( args ) ;
goto V_117;
}
V_101 = F_32 ( args , & V_102 ) ;
if ( V_101 )
goto V_117;
if ( V_102 ) {
V_101 = F_48 ( args ) ;
goto V_117;
}
V_101 = F_34 ( args , & V_102 ) ;
if ( V_101 )
goto V_117;
if ( V_102 )
V_101 = F_49 ( args ) ;
else
V_101 = F_50 ( args ) ;
V_117:
F_9 ( args ) ;
return V_101 ;
}
int
F_51 (
T_9 * V_88 ,
T_2 * V_66 ,
struct V_18 * V_19 ,
T_5 V_96 ,
T_10 * V_97 ,
struct V_98 * V_99 ,
T_11 V_100 )
{
struct V_24 * args ;
int V_101 ;
int V_102 ;
ASSERT ( F_14 ( F_15 ( V_66 ) -> V_68 ) ) ;
V_101 = F_17 ( V_88 -> V_90 , V_96 ) ;
if ( V_101 )
return V_101 ;
args = F_8 ( sizeof( * args ) , V_45 | V_92 ) ;
if ( ! args )
return - V_48 ;
args -> V_93 = V_66 -> V_94 -> V_44 ;
args -> V_19 = V_19 -> V_19 ;
args -> V_26 = V_19 -> V_22 ;
args -> V_104 = V_19 -> type ;
args -> V_105 = V_66 -> V_94 -> V_63 -> V_106 ( V_19 ) ;
args -> V_107 = V_96 ;
args -> V_66 = V_66 ;
args -> V_108 = V_97 ;
args -> V_99 = V_99 ;
args -> V_100 = V_100 ;
args -> V_109 = V_110 ;
args -> V_95 = V_88 ;
if ( V_66 -> V_69 . V_115 == V_116 ) {
V_101 = F_52 ( args ) ;
goto V_117;
}
V_101 = F_32 ( args , & V_102 ) ;
if ( V_101 )
goto V_117;
if ( V_102 ) {
V_101 = F_53 ( args ) ;
goto V_117;
}
V_101 = F_34 ( args , & V_102 ) ;
if ( V_101 )
goto V_117;
if ( V_102 )
V_101 = F_54 ( args ) ;
else
V_101 = F_55 ( args ) ;
V_117:
F_9 ( args ) ;
return V_101 ;
}
int
F_56 (
T_9 * V_88 ,
T_2 * V_66 ,
struct V_18 * V_19 )
{
return F_29 ( V_88 , V_66 , V_19 , 0 , NULL , NULL , 0 ) ;
}
int
F_57 (
struct V_24 * args ,
int V_129 ,
T_12 * V_130 )
{
struct V_131 * V_66 = args -> V_66 ;
struct V_30 * V_31 = V_66 -> V_94 ;
T_13 V_132 ;
int V_74 ;
int error ;
F_58 ( args , V_129 ) ;
V_132 = F_59 ( V_31 , V_129 * V_133 ) ;
V_74 = args -> V_93 -> V_52 ;
error = F_60 ( args , & V_132 , V_74 ) ;
if ( error )
return error ;
* V_130 = F_61 ( args -> V_93 , ( V_134 ) V_132 ) ;
if ( V_129 == V_135 ) {
T_14 V_136 ;
V_136 = F_62 ( V_31 , V_132 + V_74 ) ;
if ( V_136 > V_66 -> V_69 . V_70 ) {
V_66 -> V_69 . V_70 = V_136 ;
F_63 ( args -> V_95 , V_66 , V_137 ) ;
}
}
return 0 ;
}
int
F_32 (
struct V_24 * args ,
int * V_138 )
{
T_13 V_139 ;
int V_101 ;
if ( ( V_101 = F_64 ( args -> V_66 , & V_139 , V_110 ) ) )
return V_101 ;
V_101 = F_62 ( args -> V_66 -> V_94 , V_139 ) == args -> V_93 -> V_51 ;
if ( V_101 != 0 && args -> V_66 -> V_69 . V_70 != args -> V_93 -> V_51 )
return - V_87 ;
* V_138 = V_101 ;
return 0 ;
}
int
F_34 (
struct V_24 * args ,
int * V_138 )
{
T_13 V_139 ;
int V_101 ;
if ( ( V_101 = F_64 ( args -> V_66 , & V_139 , V_110 ) ) )
return V_101 ;
* V_138 = V_139 == args -> V_93 -> V_55 + args -> V_93 -> V_52 ;
return 0 ;
}
int
F_65 (
T_15 * args ,
T_12 V_140 ,
struct V_141 * V_142 )
{
T_13 V_132 ;
V_134 V_143 ;
int V_144 ;
T_2 * V_66 ;
int error ;
T_4 * V_31 ;
T_9 * V_88 ;
F_66 ( args , V_140 ) ;
V_66 = args -> V_66 ;
V_31 = V_66 -> V_94 ;
V_88 = args -> V_95 ;
V_143 = F_67 ( args -> V_93 , V_140 ) ;
error = F_68 ( V_88 , V_66 , V_143 , args -> V_93 -> V_52 , 0 , 0 ,
args -> V_108 , args -> V_99 , & V_144 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_144 ) ;
F_69 ( V_88 , V_142 ) ;
if ( V_140 >= F_70 ( args -> V_93 , V_56 ) )
return 0 ;
if ( V_66 -> V_69 . V_70 > F_71 ( args -> V_93 , V_140 + 1 , 0 ) )
return 0 ;
V_132 = V_143 ;
if ( ( error = F_72 ( V_88 , V_66 , & V_132 , V_110 ) ) ) {
return error ;
}
if ( V_140 == args -> V_93 -> V_53 )
ASSERT ( V_132 == 0 ) ;
else
ASSERT ( V_132 > 0 ) ;
V_66 -> V_69 . V_70 = F_62 ( V_31 , V_132 ) ;
F_63 ( V_88 , V_66 , V_137 ) ;
return 0 ;
}
