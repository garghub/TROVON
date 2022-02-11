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
ASSERT ( F_12 ( V_33 -> V_35 . V_36 ) ) ;
if ( V_33 -> V_35 . V_37 == 0 )
return 1 ;
if ( V_33 -> V_35 . V_37 > F_13 ( V_33 ) )
return 0 ;
V_34 = ( T_4 * ) V_33 -> V_38 . V_39 . V_40 ;
return ! V_34 -> V_41 ;
}
int
F_14 (
T_2 * V_13 ,
T_5 V_42 )
{
T_6 V_43 ;
T_7 V_44 ;
T_8 V_45 ;
int V_46 ;
int V_47 ;
V_45 = F_15 ( V_13 , V_42 ) ;
V_43 = F_16 ( V_13 , V_42 ) ;
V_47 = F_17 ( V_13 , V_42 ) ;
V_44 = F_18 ( V_13 , V_43 , V_47 ) ;
V_46 =
V_45 < V_13 -> V_14 . V_48 &&
V_43 < V_13 -> V_14 . V_49 &&
V_43 != 0 &&
V_47 < ( 1 << V_13 -> V_14 . V_50 ) &&
F_19 ( V_13 , V_45 , V_44 ) == V_42 ;
if ( F_20 ( F_21 ( ! V_46 , V_13 , V_51 ,
V_52 ) ) ) {
F_22 ( V_13 , L_1 ,
( unsigned long long ) V_42 ) ;
F_23 ( L_2 , V_53 , V_13 ) ;
return F_24 ( V_54 ) ;
}
return 0 ;
}
int
F_25 (
T_9 * V_55 ,
T_3 * V_33 ,
T_3 * V_56 )
{
T_10 args ;
int error ;
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_33 = V_33 ;
args . V_57 = V_55 ;
ASSERT ( F_12 ( V_33 -> V_35 . V_36 ) ) ;
if ( ( error = F_14 ( V_55 -> V_58 , V_56 -> V_59 ) ) )
return error ;
return F_26 ( & args , V_56 -> V_59 ) ;
}
int
F_27 (
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
ASSERT ( F_12 ( V_33 -> V_35 . V_36 ) ) ;
if ( ( V_64 = F_14 ( V_55 -> V_58 , V_60 ) ) )
return V_64 ;
F_28 ( V_66 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_67 = V_33 -> V_68 -> V_30 -> V_69 ( V_2 ) ;
args . V_70 = V_60 ;
args . V_33 = V_33 ;
args . V_71 = V_61 ;
args . V_62 = V_62 ;
args . V_63 = V_63 ;
args . V_72 = V_73 ;
args . V_57 = V_55 ;
args . V_74 = V_75 | V_76 ;
if ( V_33 -> V_35 . V_77 == V_78 )
V_64 = F_29 ( & args ) ;
else if ( ( V_64 = F_30 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_31 ( & args ) ;
else if ( ( V_64 = F_32 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_33 ( & args ) ;
else
V_64 = F_34 ( & args ) ;
return V_64 ;
}
int
F_35 (
struct V_7 * args ,
const unsigned char * V_2 ,
int V_5 )
{
if ( args -> V_79 == V_10 )
return V_80 ;
if ( args -> V_79 != V_12 ||
! ( args -> V_74 & V_81 ) )
return V_82 ;
args -> V_83 = F_36 ( V_5 , V_84 | V_85 ) ;
if ( ! args -> V_83 )
return V_86 ;
memcpy ( args -> V_83 , V_2 , V_5 ) ;
args -> V_87 = V_5 ;
return V_82 ;
}
int
F_37 (
T_9 * V_55 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
T_5 * V_60 ,
struct V_1 * V_88 )
{
T_10 args ;
int V_64 ;
int V_65 ;
ASSERT ( F_12 ( V_33 -> V_35 . V_36 ) ) ;
F_28 ( V_89 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_67 = V_33 -> V_68 -> V_30 -> V_69 ( V_2 ) ;
args . V_33 = V_33 ;
args . V_72 = V_73 ;
args . V_57 = V_55 ;
args . V_74 = V_76 ;
if ( V_88 )
args . V_74 |= V_81 ;
if ( V_33 -> V_35 . V_77 == V_78 )
V_64 = F_38 ( & args ) ;
else if ( ( V_64 = F_30 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_39 ( & args ) ;
else if ( ( V_64 = F_32 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_40 ( & args ) ;
else
V_64 = F_41 ( & args ) ;
if ( V_64 == V_82 )
V_64 = 0 ;
if ( ! V_64 ) {
* V_60 = args . V_70 ;
if ( V_88 ) {
V_88 -> V_2 = args . V_83 ;
V_88 -> V_5 = args . V_87 ;
}
}
return V_64 ;
}
int
F_42 (
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
ASSERT ( F_12 ( V_33 -> V_35 . V_36 ) ) ;
F_28 ( V_90 ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_67 = V_33 -> V_68 -> V_30 -> V_69 ( V_2 ) ;
args . V_70 = V_42 ;
args . V_33 = V_33 ;
args . V_71 = V_61 ;
args . V_62 = V_62 ;
args . V_63 = V_63 ;
args . V_72 = V_73 ;
args . V_57 = V_55 ;
if ( V_33 -> V_35 . V_77 == V_78 )
V_64 = F_43 ( & args ) ;
else if ( ( V_64 = F_30 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_44 ( & args ) ;
else if ( ( V_64 = F_32 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_45 ( & args ) ;
else
V_64 = F_46 ( & args ) ;
return V_64 ;
}
int
F_47 (
T_3 * V_33 ,
void * V_91 ,
T_14 V_92 ,
T_15 * V_93 ,
T_16 V_94 )
{
int V_64 ;
int V_65 ;
F_48 ( V_33 ) ;
if ( F_49 ( V_33 -> V_68 ) )
return F_24 ( V_95 ) ;
ASSERT ( F_12 ( V_33 -> V_35 . V_36 ) ) ;
F_28 ( V_96 ) ;
if ( V_33 -> V_35 . V_77 == V_78 )
V_64 = F_50 ( V_33 , V_91 , V_93 , V_94 ) ;
else if ( ( V_64 = F_30 ( NULL , V_33 , & V_65 ) ) )
;
else if ( V_65 )
V_64 = F_51 ( V_33 , V_91 , V_93 , V_94 ) ;
else
V_64 = F_52 ( V_33 , V_91 , V_92 , V_93 ,
V_94 ) ;
return V_64 ;
}
int
F_53 (
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
ASSERT ( F_12 ( V_33 -> V_35 . V_36 ) ) ;
if ( ( V_64 = F_14 ( V_55 -> V_58 , V_60 ) ) )
return V_64 ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_67 = V_33 -> V_68 -> V_30 -> V_69 ( V_2 ) ;
args . V_70 = V_60 ;
args . V_33 = V_33 ;
args . V_71 = V_61 ;
args . V_62 = V_62 ;
args . V_63 = V_63 ;
args . V_72 = V_73 ;
args . V_57 = V_55 ;
if ( V_33 -> V_35 . V_77 == V_78 )
V_64 = F_54 ( & args ) ;
else if ( ( V_64 = F_30 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_55 ( & args ) ;
else if ( ( V_64 = F_32 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_56 ( & args ) ;
else
V_64 = F_57 ( & args ) ;
return V_64 ;
}
int
F_58 (
T_9 * V_55 ,
T_3 * V_33 ,
struct V_1 * V_2 ,
V_25 V_97 )
{
T_10 args ;
int V_64 ;
int V_65 ;
if ( V_97 )
return 0 ;
ASSERT ( F_12 ( V_33 -> V_35 . V_36 ) ) ;
memset ( & args , 0 , sizeof( T_10 ) ) ;
args . V_2 = V_2 -> V_2 ;
args . V_9 = V_2 -> V_5 ;
args . V_67 = V_33 -> V_68 -> V_30 -> V_69 ( V_2 ) ;
args . V_33 = V_33 ;
args . V_72 = V_73 ;
args . V_57 = V_55 ;
args . V_74 = V_98 | V_75 |
V_76 ;
if ( V_33 -> V_35 . V_77 == V_78 )
V_64 = F_29 ( & args ) ;
else if ( ( V_64 = F_30 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_31 ( & args ) ;
else if ( ( V_64 = F_32 ( V_55 , V_33 , & V_65 ) ) )
return V_64 ;
else if ( V_65 )
V_64 = F_33 ( & args ) ;
else
V_64 = F_34 ( & args ) ;
return V_64 ;
}
int
F_59 (
struct V_7 * args ,
int V_99 ,
T_17 * V_100 )
{
struct V_101 * V_33 = args -> V_33 ;
struct V_102 * V_13 = V_33 -> V_68 ;
T_18 V_103 ;
int V_41 ;
int error ;
F_60 ( args , V_99 ) ;
V_103 = F_61 ( V_13 , V_99 * V_104 ) ;
V_41 = V_13 -> V_19 ;
error = F_62 ( args , & V_103 , V_41 ) ;
if ( error )
return error ;
* V_100 = F_63 ( V_13 , ( V_105 ) V_103 ) ;
if ( V_99 == V_106 ) {
T_19 V_107 ;
V_107 = F_64 ( V_13 , V_103 + V_41 ) ;
if ( V_107 > V_33 -> V_35 . V_37 ) {
V_33 -> V_35 . V_37 = V_107 ;
F_65 ( args -> V_57 , V_33 , V_108 ) ;
}
}
return 0 ;
}
int
F_30 (
T_9 * V_55 ,
T_3 * V_33 ,
int * V_109 )
{
T_18 V_110 ;
T_2 * V_13 ;
int V_64 ;
V_13 = V_33 -> V_68 ;
if ( ( V_64 = F_66 ( V_55 , V_33 , & V_110 , V_73 ) ) )
return V_64 ;
V_64 = F_64 ( V_13 , V_110 ) == V_13 -> V_18 ;
ASSERT ( V_64 == 0 || V_33 -> V_35 . V_37 == V_13 -> V_18 ) ;
* V_109 = V_64 ;
return 0 ;
}
int
F_32 (
T_9 * V_55 ,
T_3 * V_33 ,
int * V_109 )
{
T_18 V_110 ;
T_2 * V_13 ;
int V_64 ;
V_13 = V_33 -> V_68 ;
if ( ( V_64 = F_66 ( V_55 , V_33 , & V_110 , V_73 ) ) )
return V_64 ;
* V_109 = V_110 == V_13 -> V_21 + ( 1 << V_13 -> V_14 . V_16 ) ;
return 0 ;
}
int
F_67 (
T_10 * args ,
T_17 V_111 ,
struct V_112 * V_113 )
{
T_18 V_103 ;
V_105 V_114 ;
int V_115 ;
T_3 * V_33 ;
int error ;
T_2 * V_13 ;
T_9 * V_55 ;
F_68 ( args , V_111 ) ;
V_33 = args -> V_33 ;
V_13 = V_33 -> V_68 ;
V_55 = args -> V_57 ;
V_114 = F_6 ( V_13 , V_111 ) ;
if ( ( error = F_69 ( V_55 , V_33 , V_114 , V_13 -> V_19 ,
V_116 , 0 , args -> V_71 , args -> V_62 ,
& V_115 ) ) ) {
return error ;
}
ASSERT ( V_115 ) ;
F_70 ( V_55 , V_113 ) ;
if ( V_111 >= F_8 ( V_13 ) )
return 0 ;
if ( V_33 -> V_35 . V_37 > F_71 ( V_13 , V_111 + 1 , 0 ) )
return 0 ;
V_103 = V_114 ;
if ( ( error = F_72 ( V_55 , V_33 , & V_103 , V_73 ) ) ) {
return error ;
}
if ( V_111 == V_13 -> V_20 )
ASSERT ( V_103 == 0 ) ;
else
ASSERT ( V_103 > 0 ) ;
V_33 -> V_35 . V_37 = F_64 ( V_13 , V_103 ) ;
F_65 ( V_55 , V_33 , V_108 ) ;
return 0 ;
}
