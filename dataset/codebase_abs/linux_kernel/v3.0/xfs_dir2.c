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
ASSERT ( F_5 ( & V_13 -> V_14 ) ) ;
ASSERT ( ( 1 << ( V_13 -> V_14 . V_15 + V_13 -> V_14 . V_16 ) ) <=
V_17 ) ;
V_13 -> V_18 = 1 << ( V_13 -> V_14 . V_15 + V_13 -> V_14 . V_16 ) ;
V_13 -> V_19 = 1 << V_13 -> V_14 . V_16 ;
V_13 -> V_20 = F_6 ( V_13 , F_7 ( V_13 ) ) ;
V_13 -> V_21 = F_6 ( V_13 , F_8 ( V_13 ) ) ;
V_13 -> V_22 = F_6 ( V_13 , F_9 ( V_13 ) ) ;
V_13 -> V_23 =
( V_13 -> V_14 . V_24 - ( V_25 ) sizeof( V_26 ) ) /
( V_25 ) sizeof( V_27 ) ;
V_13 -> V_28 =
( V_13 -> V_18 - ( V_25 ) sizeof( V_26 ) ) /
( V_25 ) sizeof( V_27 ) ;
V_13 -> V_29 = ( V_13 -> V_18 * 37 ) / 100 ;
if ( F_10 ( & V_13 -> V_14 ) )
V_13 -> V_30 = & V_31 ;
else
V_13 -> V_30 = & V_32 ;
}
int
F_11 (
T_3 * V_33 )
{
T_4 * V_34 ;
ASSERT ( ( V_33 -> V_35 . V_36 & V_37 ) == V_38 ) ;
if ( V_33 -> V_35 . V_39 == 0 )
return 1 ;
if ( V_33 -> V_35 . V_39 > F_12 ( V_33 ) )
return 0 ;
V_34 = ( T_4 * ) V_33 -> V_40 . V_41 . V_42 ;
return ! V_34 -> V_43 . V_44 ;
}
int
F_13 (
T_2 * V_13 ,
T_5 V_45 )
{
T_6 V_46 ;
T_7 V_47 ;
T_8 V_48 ;
int V_49 ;
int V_50 ;
V_48 = F_14 ( V_13 , V_45 ) ;
V_46 = F_15 ( V_13 , V_45 ) ;
V_50 = F_16 ( V_13 , V_45 ) ;
V_47 = F_17 ( V_13 , V_46 , V_50 ) ;
V_49 =
V_48 < V_13 -> V_14 . V_51 &&
V_46 < V_13 -> V_14 . V_52 &&
V_46 != 0 &&
V_50 < ( 1 << V_13 -> V_14 . V_53 ) &&
F_18 ( V_13 , V_48 , V_47 ) == V_45 ;
if ( F_19 ( F_20 ( ! V_49 , V_13 , V_54 ,
V_55 ) ) ) {
F_21 ( V_13 , L_1 ,
( unsigned long long ) V_45 ) ;
F_22 ( L_2 , V_56 , V_13 ) ;
return F_23 ( V_57 ) ;
}
return 0 ;
}
int
F_24 (
T_9 * V_58 ,
T_3 * V_33 ,
T_3 * V_59 )
{
T_10 args ;
int error ;
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_33 = V_33 ;
args . V_60 = V_58 ;
ASSERT ( ( V_33 -> V_35 . V_36 & V_37 ) == V_38 ) ;
if ( ( error = F_13 ( V_58 -> V_61 , V_59 -> V_62 ) ) )
return error ;
return F_25 ( & args , V_59 -> V_62 ) ;
}
int
F_26 (
T_9 * V_58 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
T_5 V_63 ,
T_11 * V_64 ,
T_12 * V_65 ,
T_13 V_66 )
{
T_10 args ;
int V_67 ;
int V_68 ;
ASSERT ( ( V_33 -> V_35 . V_36 & V_37 ) == V_38 ) ;
if ( ( V_67 = F_13 ( V_58 -> V_61 , V_63 ) ) )
return V_67 ;
F_27 ( V_69 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_70 = V_33 -> V_71 -> V_30 -> V_72 ( V_2 ) ;
args . V_73 = V_63 ;
args . V_33 = V_33 ;
args . V_74 = V_64 ;
args . V_65 = V_65 ;
args . V_66 = V_66 ;
args . V_75 = V_76 ;
args . V_60 = V_58 ;
args . V_77 = V_78 | V_79 ;
if ( V_33 -> V_35 . V_80 == V_81 )
V_67 = F_28 ( & args ) ;
else if ( ( V_67 = F_29 ( V_58 , V_33 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_30 ( & args ) ;
else if ( ( V_67 = F_31 ( V_58 , V_33 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_32 ( & args ) ;
else
V_67 = F_33 ( & args ) ;
return V_67 ;
}
int
F_34 (
struct V_7 * args ,
const unsigned char * V_2 ,
int V_5 )
{
if ( args -> V_82 == V_10 )
return V_83 ;
if ( args -> V_82 != V_12 ||
! ( args -> V_77 & V_84 ) )
return V_85 ;
args -> V_86 = F_35 ( V_5 , V_87 | V_88 ) ;
if ( ! args -> V_86 )
return V_89 ;
memcpy ( args -> V_86 , V_2 , V_5 ) ;
args -> V_90 = V_5 ;
return V_85 ;
}
int
F_36 (
T_9 * V_58 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
T_5 * V_63 ,
struct V_1 * V_91 )
{
T_10 args ;
int V_67 ;
int V_68 ;
ASSERT ( ( V_33 -> V_35 . V_36 & V_37 ) == V_38 ) ;
F_27 ( V_92 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_70 = V_33 -> V_71 -> V_30 -> V_72 ( V_2 ) ;
args . V_33 = V_33 ;
args . V_75 = V_76 ;
args . V_60 = V_58 ;
args . V_77 = V_79 ;
if ( V_91 )
args . V_77 |= V_84 ;
if ( V_33 -> V_35 . V_80 == V_81 )
V_67 = F_37 ( & args ) ;
else if ( ( V_67 = F_29 ( V_58 , V_33 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_38 ( & args ) ;
else if ( ( V_67 = F_31 ( V_58 , V_33 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_39 ( & args ) ;
else
V_67 = F_40 ( & args ) ;
if ( V_67 == V_85 )
V_67 = 0 ;
if ( ! V_67 ) {
* V_63 = args . V_73 ;
if ( V_91 ) {
V_91 -> V_2 = args . V_86 ;
V_91 -> V_5 = args . V_90 ;
}
}
return V_67 ;
}
int
F_41 (
T_9 * V_58 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
T_5 V_45 ,
T_11 * V_64 ,
T_12 * V_65 ,
T_13 V_66 )
{
T_10 args ;
int V_67 ;
int V_68 ;
ASSERT ( ( V_33 -> V_35 . V_36 & V_37 ) == V_38 ) ;
F_27 ( V_93 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_70 = V_33 -> V_71 -> V_30 -> V_72 ( V_2 ) ;
args . V_73 = V_45 ;
args . V_33 = V_33 ;
args . V_74 = V_64 ;
args . V_65 = V_65 ;
args . V_66 = V_66 ;
args . V_75 = V_76 ;
args . V_60 = V_58 ;
if ( V_33 -> V_35 . V_80 == V_81 )
V_67 = F_42 ( & args ) ;
else if ( ( V_67 = F_29 ( V_58 , V_33 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_43 ( & args ) ;
else if ( ( V_67 = F_31 ( V_58 , V_33 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_44 ( & args ) ;
else
V_67 = F_45 ( & args ) ;
return V_67 ;
}
int
F_46 (
T_3 * V_33 ,
void * V_94 ,
T_14 V_95 ,
T_15 * V_96 ,
T_16 V_97 )
{
int V_67 ;
int V_68 ;
F_47 ( V_33 ) ;
if ( F_48 ( V_33 -> V_71 ) )
return F_23 ( V_98 ) ;
ASSERT ( ( V_33 -> V_35 . V_36 & V_37 ) == V_38 ) ;
F_27 ( V_99 ) ;
if ( V_33 -> V_35 . V_80 == V_81 )
V_67 = F_49 ( V_33 , V_94 , V_96 , V_97 ) ;
else if ( ( V_67 = F_29 ( NULL , V_33 , & V_68 ) ) )
;
else if ( V_68 )
V_67 = F_50 ( V_33 , V_94 , V_96 , V_97 ) ;
else
V_67 = F_51 ( V_33 , V_94 , V_95 , V_96 ,
V_97 ) ;
return V_67 ;
}
int
F_52 (
T_9 * V_58 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
T_5 V_63 ,
T_11 * V_64 ,
T_12 * V_65 ,
T_13 V_66 )
{
T_10 args ;
int V_67 ;
int V_68 ;
ASSERT ( ( V_33 -> V_35 . V_36 & V_37 ) == V_38 ) ;
if ( ( V_67 = F_13 ( V_58 -> V_61 , V_63 ) ) )
return V_67 ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_70 = V_33 -> V_71 -> V_30 -> V_72 ( V_2 ) ;
args . V_73 = V_63 ;
args . V_33 = V_33 ;
args . V_74 = V_64 ;
args . V_65 = V_65 ;
args . V_66 = V_66 ;
args . V_75 = V_76 ;
args . V_60 = V_58 ;
if ( V_33 -> V_35 . V_80 == V_81 )
V_67 = F_53 ( & args ) ;
else if ( ( V_67 = F_29 ( V_58 , V_33 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_54 ( & args ) ;
else if ( ( V_67 = F_31 ( V_58 , V_33 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_55 ( & args ) ;
else
V_67 = F_56 ( & args ) ;
return V_67 ;
}
int
F_57 (
T_9 * V_58 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
V_25 V_100 )
{
T_10 args ;
int V_67 ;
int V_68 ;
if ( V_100 )
return 0 ;
ASSERT ( ( V_33 -> V_35 . V_36 & V_37 ) == V_38 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_70 = V_33 -> V_71 -> V_30 -> V_72 ( V_2 ) ;
args . V_33 = V_33 ;
args . V_75 = V_76 ;
args . V_60 = V_58 ;
args . V_77 = V_101 | V_78 |
V_79 ;
if ( V_33 -> V_35 . V_80 == V_81 )
V_67 = F_28 ( & args ) ;
else if ( ( V_67 = F_29 ( V_58 , V_33 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_30 ( & args ) ;
else if ( ( V_67 = F_31 ( V_58 , V_33 , & V_68 ) ) )
return V_67 ;
else if ( V_68 )
V_67 = F_32 ( & args ) ;
else
V_67 = F_33 ( & args ) ;
return V_67 ;
}
int
F_58 (
T_10 * args ,
int V_102 ,
T_17 * V_103 )
{
T_18 V_104 ;
int V_44 ;
T_3 * V_33 ;
int error ;
int V_105 ;
int V_4 ;
T_19 V_106 ;
int V_107 ;
T_19 * V_108 ;
T_2 * V_13 ;
int V_109 ;
T_9 * V_58 ;
T_20 V_110 ;
F_59 ( args , V_102 ) ;
V_33 = args -> V_33 ;
V_58 = args -> V_60 ;
V_13 = V_33 -> V_71 ;
V_110 = V_33 -> V_35 . V_111 ;
V_104 = F_60 ( V_13 , V_102 * V_112 ) ;
V_44 = V_13 -> V_19 ;
if ( ( error = F_61 ( V_58 , V_33 , V_44 , & V_104 , V_76 ) ) )
return error ;
V_109 = 1 ;
ASSERT ( args -> V_74 != NULL ) ;
if ( ( error = F_62 ( V_58 , V_33 , V_104 , V_44 ,
V_113 | V_114 | V_115 ,
args -> V_74 , args -> V_66 , & V_106 , & V_109 ,
args -> V_65 ) ) )
return error ;
ASSERT ( V_109 <= 1 ) ;
if ( V_109 == 1 ) {
V_108 = & V_106 ;
V_107 = 1 ;
}
else if ( V_109 == 0 && V_44 > 1 ) {
T_18 V_116 ;
V_108 = F_35 ( sizeof( * V_108 ) * V_44 , V_117 ) ;
for ( V_116 = V_104 , V_107 = 0 ; V_116 < V_104 + V_44 ; ) {
int V_118 ;
V_109 = F_63 ( V_119 , V_44 ) ;
V_118 = ( int ) ( V_104 + V_44 - V_116 ) ;
if ( ( error = F_62 ( V_58 , V_33 , V_116 , V_118 ,
V_113 | V_114 ,
args -> V_74 , args -> V_66 ,
& V_108 [ V_107 ] , & V_109 , args -> V_65 ) ) ) {
F_64 ( V_108 ) ;
return error ;
}
if ( V_109 < 1 )
break;
V_107 += V_109 ;
V_116 = V_108 [ V_107 - 1 ] . V_120 +
V_108 [ V_107 - 1 ] . V_121 ;
}
}
else {
V_107 = 0 ;
V_108 = NULL ;
}
for ( V_4 = 0 , V_105 = 0 ; V_4 < V_107 ; V_4 ++ )
V_105 += V_108 [ V_4 ] . V_121 ;
if ( V_105 != V_44 || V_108 [ 0 ] . V_120 != V_104 ||
V_108 [ V_107 - 1 ] . V_120 + V_108 [ V_107 - 1 ] . V_121 !=
V_104 + V_44 ) {
if ( V_108 != & V_106 )
F_64 ( V_108 ) ;
return F_23 ( V_122 ) ;
}
if ( V_108 != & V_106 )
F_64 ( V_108 ) ;
args -> V_66 -= V_33 -> V_35 . V_111 - V_110 ;
* V_103 = F_65 ( V_13 , ( V_123 ) V_104 ) ;
if ( V_102 == V_124 ) {
T_21 V_125 ;
V_125 = F_66 ( V_13 , V_104 + V_44 ) ;
if ( V_125 > V_33 -> V_35 . V_39 ) {
V_33 -> V_35 . V_39 = V_125 ;
F_67 ( V_58 , V_33 , V_126 ) ;
}
}
return 0 ;
}
int
F_29 (
T_9 * V_58 ,
T_3 * V_33 ,
int * V_127 )
{
T_18 V_128 ;
T_2 * V_13 ;
int V_67 ;
V_13 = V_33 -> V_71 ;
if ( ( V_67 = F_68 ( V_58 , V_33 , & V_128 , V_76 ) ) )
return V_67 ;
V_67 = F_66 ( V_13 , V_128 ) == V_13 -> V_18 ;
ASSERT ( V_67 == 0 || V_33 -> V_35 . V_39 == V_13 -> V_18 ) ;
* V_127 = V_67 ;
return 0 ;
}
int
F_31 (
T_9 * V_58 ,
T_3 * V_33 ,
int * V_127 )
{
T_18 V_128 ;
T_2 * V_13 ;
int V_67 ;
V_13 = V_33 -> V_71 ;
if ( ( V_67 = F_68 ( V_58 , V_33 , & V_128 , V_76 ) ) )
return V_67 ;
* V_127 = V_128 == V_13 -> V_21 + ( 1 << V_13 -> V_14 . V_16 ) ;
return 0 ;
}
int
F_69 (
T_10 * args ,
T_17 V_129 ,
T_22 * V_130 )
{
T_18 V_104 ;
V_123 V_131 ;
int V_132 ;
T_3 * V_33 ;
int error ;
T_2 * V_13 ;
T_9 * V_58 ;
F_70 ( args , V_129 ) ;
V_33 = args -> V_33 ;
V_13 = V_33 -> V_71 ;
V_58 = args -> V_60 ;
V_131 = F_6 ( V_13 , V_129 ) ;
if ( ( error = F_71 ( V_58 , V_33 , V_131 , V_13 -> V_19 ,
V_114 , 0 , args -> V_74 , args -> V_65 ,
& V_132 ) ) ) {
return error ;
}
ASSERT ( V_132 ) ;
F_72 ( V_58 , V_130 ) ;
if ( V_129 >= F_8 ( V_13 ) )
return 0 ;
if ( V_33 -> V_35 . V_39 > F_73 ( V_13 , V_129 + 1 , 0 ) )
return 0 ;
V_104 = V_131 ;
if ( ( error = F_74 ( V_58 , V_33 , & V_104 , V_76 ) ) ) {
return error ;
}
if ( V_129 == V_13 -> V_20 )
ASSERT ( V_104 == 0 ) ;
else
ASSERT ( V_104 > 0 ) ;
V_33 -> V_35 . V_39 = F_66 ( V_13 , V_104 ) ;
F_67 ( V_58 , V_33 , V_126 ) ;
return 0 ;
}
