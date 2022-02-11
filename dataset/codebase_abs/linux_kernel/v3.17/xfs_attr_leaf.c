void
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
ASSERT ( V_4 -> V_6 . V_7 . V_8 == F_2 ( V_9 ) ||
V_4 -> V_6 . V_7 . V_8 == F_2 ( V_10 ) ) ;
if ( V_4 -> V_6 . V_7 . V_8 == F_2 ( V_10 ) ) {
struct V_11 * V_12 = (struct V_11 * ) V_4 ;
V_2 -> V_13 = F_3 ( V_12 -> V_7 . V_6 . V_13 ) ;
V_2 -> V_14 = F_3 ( V_12 -> V_7 . V_6 . V_14 ) ;
V_2 -> V_8 = F_4 ( V_12 -> V_7 . V_6 . V_8 ) ;
V_2 -> V_15 = F_4 ( V_12 -> V_15 ) ;
V_2 -> V_16 = F_4 ( V_12 -> V_16 ) ;
V_2 -> V_17 = F_4 ( V_12 -> V_17 ) ;
V_2 -> V_18 = V_12 -> V_18 ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
V_2 -> V_20 [ V_5 ] . V_21 = F_4 ( V_12 -> V_20 [ V_5 ] . V_21 ) ;
V_2 -> V_20 [ V_5 ] . V_22 = F_4 ( V_12 -> V_20 [ V_5 ] . V_22 ) ;
}
return;
}
V_2 -> V_13 = F_3 ( V_4 -> V_6 . V_7 . V_13 ) ;
V_2 -> V_14 = F_3 ( V_4 -> V_6 . V_7 . V_14 ) ;
V_2 -> V_8 = F_4 ( V_4 -> V_6 . V_7 . V_8 ) ;
V_2 -> V_15 = F_4 ( V_4 -> V_6 . V_15 ) ;
V_2 -> V_16 = F_4 ( V_4 -> V_6 . V_16 ) ;
V_2 -> V_17 = F_4 ( V_4 -> V_6 . V_17 ) ;
V_2 -> V_18 = V_4 -> V_6 . V_18 ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
V_2 -> V_20 [ V_5 ] . V_21 = F_4 ( V_4 -> V_6 . V_20 [ V_5 ] . V_21 ) ;
V_2 -> V_20 [ V_5 ] . V_22 = F_4 ( V_4 -> V_6 . V_20 [ V_5 ] . V_22 ) ;
}
}
void
F_5 (
struct V_3 * V_2 ,
struct V_1 * V_4 )
{
int V_5 ;
ASSERT ( V_4 -> V_8 == V_9 ||
V_4 -> V_8 == V_10 ) ;
if ( V_4 -> V_8 == V_10 ) {
struct V_11 * V_12 = (struct V_11 * ) V_2 ;
V_12 -> V_7 . V_6 . V_13 = F_6 ( V_4 -> V_13 ) ;
V_12 -> V_7 . V_6 . V_14 = F_6 ( V_4 -> V_14 ) ;
V_12 -> V_7 . V_6 . V_8 = F_2 ( V_4 -> V_8 ) ;
V_12 -> V_15 = F_2 ( V_4 -> V_15 ) ;
V_12 -> V_16 = F_2 ( V_4 -> V_16 ) ;
V_12 -> V_17 = F_2 ( V_4 -> V_17 ) ;
V_12 -> V_18 = V_4 -> V_18 ;
V_12 -> V_23 = 0 ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
V_12 -> V_20 [ V_5 ] . V_21 = F_2 ( V_4 -> V_20 [ V_5 ] . V_21 ) ;
V_12 -> V_20 [ V_5 ] . V_22 = F_2 ( V_4 -> V_20 [ V_5 ] . V_22 ) ;
}
return;
}
V_2 -> V_6 . V_7 . V_13 = F_6 ( V_4 -> V_13 ) ;
V_2 -> V_6 . V_7 . V_14 = F_6 ( V_4 -> V_14 ) ;
V_2 -> V_6 . V_7 . V_8 = F_2 ( V_4 -> V_8 ) ;
V_2 -> V_6 . V_15 = F_2 ( V_4 -> V_15 ) ;
V_2 -> V_6 . V_16 = F_2 ( V_4 -> V_16 ) ;
V_2 -> V_6 . V_17 = F_2 ( V_4 -> V_17 ) ;
V_2 -> V_6 . V_18 = V_4 -> V_18 ;
V_2 -> V_6 . V_23 = 0 ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
V_2 -> V_6 . V_20 [ V_5 ] . V_21 = F_2 ( V_4 -> V_20 [ V_5 ] . V_21 ) ;
V_2 -> V_6 . V_20 [ V_5 ] . V_22 = F_2 ( V_4 -> V_20 [ V_5 ] . V_22 ) ;
}
}
static bool
F_7 (
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 -> V_29 ;
struct V_3 * V_30 = V_25 -> V_31 ;
struct V_1 V_32 ;
F_1 ( & V_32 , V_30 ) ;
if ( F_8 ( & V_27 -> V_33 ) ) {
struct V_34 * V_12 = V_25 -> V_31 ;
if ( V_32 . V_8 != V_10 )
return false ;
if ( ! F_9 ( & V_12 -> V_7 . V_35 , & V_27 -> V_33 . V_36 ) )
return false ;
if ( F_10 ( V_12 -> V_7 . V_37 ) != V_25 -> V_38 )
return false ;
} else {
if ( V_32 . V_8 != V_9 )
return false ;
}
if ( V_32 . V_15 == 0 )
return false ;
return true ;
}
static void
F_11 (
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 -> V_29 ;
struct V_39 * V_40 = V_25 -> V_41 ;
struct V_11 * V_12 = V_25 -> V_31 ;
if ( ! F_7 ( V_25 ) ) {
F_12 ( V_25 , - V_42 ) ;
F_13 ( V_25 ) ;
return;
}
if ( ! F_8 ( & V_27 -> V_33 ) )
return;
if ( V_40 )
V_12 -> V_7 . V_43 = F_14 ( V_40 -> V_44 . V_45 ) ;
F_15 ( V_25 , V_46 ) ;
}
static void
F_16 (
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 -> V_29 ;
if ( F_8 ( & V_27 -> V_33 ) &&
! F_17 ( V_25 , V_46 ) )
F_12 ( V_25 , - V_47 ) ;
else if ( ! F_7 ( V_25 ) )
F_12 ( V_25 , - V_42 ) ;
if ( V_25 -> V_48 )
F_13 ( V_25 ) ;
}
int
F_18 (
struct V_49 * V_50 ,
struct V_51 * V_52 ,
T_1 V_53 ,
T_2 V_54 ,
struct V_24 * * V_55 )
{
int V_56 ;
V_56 = F_19 ( V_50 , V_52 , V_53 , V_54 , V_55 ,
V_57 , & V_58 ) ;
if ( ! V_56 && V_50 )
F_20 ( V_50 , * V_55 , V_59 ) ;
return V_56 ;
}
STATIC int
F_21 ( int V_60 , int V_61 )
{
return F_22 ( V_61 ) == F_23 ( V_60 ) ;
}
int
F_24 ( T_3 * V_52 , int V_62 )
{
int V_63 ;
int V_64 ;
int V_65 ;
int V_66 ;
T_4 * V_27 = V_52 -> V_67 ;
V_63 = ( F_25 ( V_27 , V_52 -> V_68 . V_69 ) - V_62 ) >> 3 ;
switch ( V_52 -> V_68 . V_70 ) {
case V_71 :
V_64 = F_26 ( sizeof( V_72 ) , 8 ) >> 3 ;
return ( V_63 >= V_64 ) ? V_64 : 0 ;
case V_73 :
V_64 = F_26 ( sizeof( V_74 ) , 8 ) >> 3 ;
return ( V_63 >= V_64 ) ? V_64 : 0 ;
}
if ( V_62 <= F_27 ( V_52 ) )
return V_52 -> V_68 . V_75 ;
if ( ! ( V_27 -> V_76 & V_77 ) )
return 0 ;
V_66 = V_52 -> V_78 . V_79 ;
switch ( V_52 -> V_68 . V_70 ) {
case V_80 :
if ( ! V_52 -> V_68 . V_75 && V_52 -> V_78 . V_79 >
F_28 ( V_52 ) )
V_66 = F_29 ( V_81 ) ;
break;
case V_82 :
if ( V_52 -> V_68 . V_75 ) {
if ( V_63 < V_52 -> V_68 . V_75 )
return 0 ;
return V_52 -> V_68 . V_75 ;
}
V_66 = F_30 ( V_27 , V_52 -> V_78 . V_83 ) ;
break;
}
V_64 = F_31 ( V_66 , F_29 ( V_81 ) ) ;
V_64 = F_26 ( V_64 , 8 ) >> 3 ;
V_65 = F_25 ( V_27 , V_52 -> V_68 . V_69 ) -
F_29 ( V_84 ) ;
V_65 = V_65 >> 3 ;
if ( V_63 >= V_65 )
return V_65 ;
if ( V_63 >= V_64 )
return V_63 ;
return 0 ;
}
STATIC void
F_32 ( T_4 * V_27 , T_5 * V_50 )
{
if ( ( V_27 -> V_76 & V_77 ) &&
! ( F_33 ( & V_27 -> V_33 ) ) ) {
F_34 ( & V_27 -> V_85 ) ;
if ( ! F_33 ( & V_27 -> V_33 ) ) {
F_35 ( & V_27 -> V_33 ) ;
F_36 ( & V_27 -> V_85 ) ;
F_37 ( V_50 , V_86 | V_87 ) ;
} else
F_36 ( & V_27 -> V_85 ) ;
}
}
void
F_38 ( T_6 * args )
{
T_7 * V_6 ;
T_3 * V_52 ;
T_8 * V_88 ;
F_39 ( args ) ;
V_52 = args -> V_52 ;
ASSERT ( V_52 != NULL ) ;
V_88 = V_52 -> V_89 ;
ASSERT ( V_88 != NULL ) ;
ASSERT ( V_88 -> V_79 == 0 ) ;
if ( V_52 -> V_68 . V_90 == V_80 ) {
V_88 -> V_91 &= ~ V_92 ;
V_52 -> V_68 . V_90 = V_93 ;
V_88 -> V_91 |= V_94 ;
} else {
ASSERT ( V_88 -> V_91 & V_94 ) ;
}
F_40 ( V_52 , sizeof( * V_6 ) , V_57 ) ;
V_6 = ( T_7 * ) V_88 -> V_95 . V_96 ;
V_6 -> V_15 = 0 ;
V_6 -> V_97 = F_2 ( sizeof( * V_6 ) ) ;
F_41 ( args -> V_98 , V_52 , V_99 | V_100 ) ;
}
void
F_42 ( T_6 * args , int V_101 )
{
T_9 * V_102 ;
T_10 * V_103 ;
int V_5 , V_63 , V_22 ;
T_4 * V_27 ;
T_3 * V_52 ;
T_8 * V_88 ;
F_43 ( args ) ;
V_52 = args -> V_52 ;
V_27 = V_52 -> V_67 ;
V_52 -> V_68 . V_75 = V_101 ;
V_88 = V_52 -> V_89 ;
ASSERT ( V_88 -> V_91 & V_94 ) ;
V_102 = ( T_9 * ) V_88 -> V_95 . V_96 ;
V_103 = & V_102 -> V_104 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_102 -> V_6 . V_15 ; V_103 = F_44 ( V_103 ) , V_5 ++ ) {
#ifdef F_45
if ( V_103 -> V_105 != args -> V_105 )
continue;
if ( memcmp ( args -> V_106 , V_103 -> V_107 , args -> V_105 ) != 0 )
continue;
if ( ! F_21 ( args -> V_108 , V_103 -> V_108 ) )
continue;
ASSERT ( 0 ) ;
#endif
}
V_63 = ( char * ) V_103 - ( char * ) V_102 ;
V_22 = F_46 ( args -> V_105 , args -> V_109 ) ;
F_40 ( V_52 , V_22 , V_57 ) ;
V_102 = ( T_9 * ) V_88 -> V_95 . V_96 ;
V_103 = ( T_10 * ) ( ( char * ) V_102 + V_63 ) ;
V_103 -> V_105 = args -> V_105 ;
V_103 -> V_109 = args -> V_109 ;
V_103 -> V_108 = F_23 ( args -> V_108 ) ;
memcpy ( V_103 -> V_107 , args -> V_106 , args -> V_105 ) ;
memcpy ( & V_103 -> V_107 [ args -> V_105 ] , args -> V_110 , args -> V_109 ) ;
V_102 -> V_6 . V_15 ++ ;
F_47 ( & V_102 -> V_6 . V_97 , V_22 ) ;
F_41 ( args -> V_98 , V_52 , V_99 | V_100 ) ;
F_32 ( V_27 , args -> V_98 ) ;
}
STATIC void
F_48 (
struct V_51 * V_111 ,
struct V_49 * V_50 )
{
F_49 ( V_111 , V_57 ) ;
V_111 -> V_68 . V_75 = 0 ;
V_111 -> V_68 . V_90 = V_80 ;
ASSERT ( V_111 -> V_68 . V_112 == 0 ) ;
ASSERT ( V_111 -> V_89 == NULL ) ;
F_41 ( V_50 , V_111 , V_99 ) ;
}
int
F_50 ( T_6 * args )
{
T_9 * V_102 ;
T_10 * V_103 ;
int V_21 , V_22 = 0 , V_113 , V_97 , V_5 ;
T_4 * V_27 ;
T_3 * V_52 ;
F_51 ( args ) ;
V_52 = args -> V_52 ;
V_27 = V_52 -> V_67 ;
V_21 = sizeof( T_7 ) ;
V_102 = ( T_9 * ) V_52 -> V_89 -> V_95 . V_96 ;
V_103 = & V_102 -> V_104 [ 0 ] ;
V_113 = V_102 -> V_6 . V_15 ;
for ( V_5 = 0 ; V_5 < V_113 ; V_103 = F_44 ( V_103 ) ,
V_21 += V_22 , V_5 ++ ) {
V_22 = F_52 ( V_103 ) ;
if ( V_103 -> V_105 != args -> V_105 )
continue;
if ( memcmp ( V_103 -> V_107 , args -> V_106 , args -> V_105 ) != 0 )
continue;
if ( ! F_21 ( args -> V_108 , V_103 -> V_108 ) )
continue;
break;
}
if ( V_5 == V_113 )
return - V_114 ;
V_113 = V_21 + V_22 ;
V_97 = F_4 ( V_102 -> V_6 . V_97 ) ;
if ( V_113 != V_97 )
memmove ( & ( ( char * ) V_102 ) [ V_21 ] , & ( ( char * ) V_102 ) [ V_113 ] , V_97 - V_113 ) ;
V_102 -> V_6 . V_15 -- ;
F_47 ( & V_102 -> V_6 . V_97 , - V_22 ) ;
V_97 -= V_22 ;
if ( V_97 == sizeof( T_7 ) &&
( V_27 -> V_76 & V_77 ) &&
( V_52 -> V_68 . V_70 != V_82 ) &&
! ( args -> V_115 & V_116 ) ) {
F_48 ( V_52 , args -> V_98 ) ;
} else {
F_40 ( V_52 , - V_22 , V_57 ) ;
V_52 -> V_68 . V_75 = F_24 ( V_52 , V_97 ) ;
ASSERT ( V_52 -> V_68 . V_75 ) ;
ASSERT ( V_97 > sizeof( T_7 ) ||
( args -> V_115 & V_116 ) ||
! ( V_27 -> V_76 & V_77 ) ||
V_52 -> V_68 . V_70 == V_82 ) ;
F_41 ( args -> V_98 , V_52 ,
V_99 | V_100 ) ;
}
F_32 ( V_27 , args -> V_98 ) ;
return 0 ;
}
int
F_53 ( T_6 * args )
{
T_9 * V_102 ;
T_10 * V_103 ;
int V_5 ;
T_8 * V_88 ;
F_54 ( args ) ;
V_88 = args -> V_52 -> V_89 ;
ASSERT ( V_88 -> V_91 & V_94 ) ;
V_102 = ( T_9 * ) V_88 -> V_95 . V_96 ;
V_103 = & V_102 -> V_104 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_102 -> V_6 . V_15 ;
V_103 = F_44 ( V_103 ) , V_5 ++ ) {
if ( V_103 -> V_105 != args -> V_105 )
continue;
if ( memcmp ( args -> V_106 , V_103 -> V_107 , args -> V_105 ) != 0 )
continue;
if ( ! F_21 ( args -> V_108 , V_103 -> V_108 ) )
continue;
return - V_117 ;
}
return - V_114 ;
}
int
F_55 ( T_6 * args )
{
T_9 * V_102 ;
T_10 * V_103 ;
int V_5 ;
ASSERT ( args -> V_52 -> V_89 -> V_91 == V_94 ) ;
V_102 = ( T_9 * ) args -> V_52 -> V_89 -> V_95 . V_96 ;
V_103 = & V_102 -> V_104 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_102 -> V_6 . V_15 ;
V_103 = F_44 ( V_103 ) , V_5 ++ ) {
if ( V_103 -> V_105 != args -> V_105 )
continue;
if ( memcmp ( args -> V_106 , V_103 -> V_107 , args -> V_105 ) != 0 )
continue;
if ( ! F_21 ( args -> V_108 , V_103 -> V_108 ) )
continue;
if ( args -> V_108 & V_118 ) {
args -> V_109 = V_103 -> V_109 ;
return - V_117 ;
}
if ( args -> V_109 < V_103 -> V_109 ) {
args -> V_109 = V_103 -> V_109 ;
return - V_119 ;
}
args -> V_109 = V_103 -> V_109 ;
memcpy ( args -> V_110 , & V_103 -> V_107 [ args -> V_105 ] ,
args -> V_109 ) ;
return - V_117 ;
}
return - V_114 ;
}
int
F_56 ( T_6 * args )
{
T_3 * V_52 ;
T_9 * V_102 ;
T_10 * V_103 ;
T_6 V_120 ;
char * V_121 ;
int error , V_5 , V_22 ;
T_1 V_37 ;
struct V_24 * V_25 ;
T_8 * V_88 ;
F_57 ( args ) ;
V_52 = args -> V_52 ;
V_88 = V_52 -> V_89 ;
V_102 = ( T_9 * ) V_88 -> V_95 . V_96 ;
V_22 = F_4 ( V_102 -> V_6 . V_97 ) ;
V_121 = F_58 ( V_22 , V_122 ) ;
ASSERT ( V_121 != NULL ) ;
memcpy ( V_121 , V_88 -> V_95 . V_96 , V_22 ) ;
V_102 = ( T_9 * ) V_121 ;
F_40 ( V_52 , - V_22 , V_57 ) ;
F_59 ( V_52 , V_57 ) ;
V_25 = NULL ;
error = F_60 ( args , & V_37 ) ;
if ( error ) {
if ( error == - V_123 )
goto V_124;
F_40 ( V_52 , V_22 , V_57 ) ;
memcpy ( V_88 -> V_95 . V_96 , V_121 , V_22 ) ;
goto V_124;
}
ASSERT ( V_37 == 0 ) ;
error = F_61 ( args , V_37 , & V_25 ) ;
if ( error ) {
error = F_62 ( args , 0 , V_25 ) ;
V_25 = NULL ;
if ( error )
goto V_124;
F_40 ( V_52 , V_22 , V_57 ) ;
memcpy ( V_88 -> V_95 . V_96 , V_121 , V_22 ) ;
goto V_124;
}
memset ( ( char * ) & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_52 = V_52 ;
V_120 . V_125 = args -> V_125 ;
V_120 . V_126 = args -> V_126 ;
V_120 . V_127 = args -> V_127 ;
V_120 . V_128 = args -> V_128 ;
V_120 . V_129 = V_57 ;
V_120 . V_98 = args -> V_98 ;
V_120 . V_115 = V_130 ;
V_103 = & V_102 -> V_104 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_102 -> V_6 . V_15 ; V_5 ++ ) {
V_120 . V_106 = V_103 -> V_107 ;
V_120 . V_105 = V_103 -> V_105 ;
V_120 . V_110 = & V_103 -> V_107 [ V_120 . V_105 ] ;
V_120 . V_109 = V_103 -> V_109 ;
V_120 . V_131 = F_63 ( V_103 -> V_107 ,
V_103 -> V_105 ) ;
V_120 . V_108 = F_64 ( V_103 -> V_108 ) ;
error = F_65 ( V_25 , & V_120 ) ;
ASSERT ( error == - V_114 ) ;
error = F_66 ( V_25 , & V_120 ) ;
ASSERT ( error != - V_132 ) ;
if ( error )
goto V_124;
V_103 = F_44 ( V_103 ) ;
}
error = 0 ;
V_124:
F_67 ( V_121 ) ;
return error ;
}
int
F_68 (
struct V_24 * V_25 ,
struct V_51 * V_52 )
{
struct V_3 * V_30 ;
struct V_133 * V_134 ;
T_11 * V_135 ;
struct V_1 V_136 ;
int V_62 ;
int V_5 ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_136 , V_30 ) ;
V_134 = F_69 ( V_30 ) ;
V_62 = sizeof( struct V_137 ) ;
for ( V_5 = 0 ; V_5 < V_136 . V_15 ; V_134 ++ , V_5 ++ ) {
if ( V_134 -> V_108 & V_138 )
continue;
if ( ! ( V_134 -> V_108 & V_139 ) )
return 0 ;
V_135 = F_70 ( V_30 , V_5 ) ;
if ( V_135 -> V_105 >= V_140 )
return 0 ;
if ( F_4 ( V_135 -> V_109 ) >= V_140 )
return 0 ;
V_62 += sizeof( struct V_141 ) - 1
+ V_135 -> V_105
+ F_4 ( V_135 -> V_109 ) ;
}
if ( ( V_52 -> V_67 -> V_76 & V_77 ) &&
( V_52 -> V_68 . V_70 != V_82 ) &&
( V_62 == sizeof( struct V_137 ) ) )
return - 1 ;
return F_24 ( V_52 , V_62 ) ;
}
int
F_71 (
struct V_24 * V_25 ,
struct V_142 * args ,
int V_101 )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_133 * V_134 ;
struct V_143 * V_135 ;
struct V_142 V_120 ;
struct V_51 * V_52 = args -> V_52 ;
char * V_121 ;
int error ;
int V_5 ;
F_72 ( args ) ;
V_121 = F_58 ( args -> V_125 -> V_144 , V_122 ) ;
if ( ! V_121 )
return - V_145 ;
memcpy ( V_121 , V_25 -> V_31 , args -> V_125 -> V_144 ) ;
V_30 = ( V_146 * ) V_121 ;
F_1 ( & V_32 , V_30 ) ;
V_134 = F_69 ( V_30 ) ;
memset ( V_25 -> V_31 , 0 , args -> V_125 -> V_144 ) ;
error = F_62 ( args , 0 , V_25 ) ;
if ( error )
goto V_124;
if ( V_101 == - 1 ) {
ASSERT ( V_52 -> V_67 -> V_76 & V_77 ) ;
ASSERT ( V_52 -> V_68 . V_70 != V_82 ) ;
F_48 ( V_52 , args -> V_98 ) ;
goto V_124;
}
F_38 ( args ) ;
memset ( ( char * ) & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_125 = args -> V_125 ;
V_120 . V_52 = V_52 ;
V_120 . V_126 = args -> V_126 ;
V_120 . V_127 = args -> V_127 ;
V_120 . V_128 = args -> V_128 ;
V_120 . V_129 = V_57 ;
V_120 . V_98 = args -> V_98 ;
V_120 . V_115 = V_130 ;
for ( V_5 = 0 ; V_5 < V_32 . V_15 ; V_134 ++ , V_5 ++ ) {
if ( V_134 -> V_108 & V_138 )
continue;
if ( ! V_134 -> V_147 )
continue;
ASSERT ( V_134 -> V_108 & V_139 ) ;
V_135 = F_70 ( V_30 , V_5 ) ;
V_120 . V_106 = V_135 -> V_107 ;
V_120 . V_105 = V_135 -> V_105 ;
V_120 . V_110 = & V_135 -> V_107 [ V_120 . V_105 ] ;
V_120 . V_109 = F_4 ( V_135 -> V_109 ) ;
V_120 . V_131 = F_3 ( V_134 -> V_131 ) ;
V_120 . V_108 = F_64 ( V_134 -> V_108 ) ;
F_42 ( & V_120 , V_101 ) ;
}
error = 0 ;
V_124:
F_67 ( V_121 ) ;
return error ;
}
int
F_73 (
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_1 V_148 ;
struct V_133 * V_149 ;
struct V_150 * V_151 ;
struct V_152 V_153 ;
struct V_154 * V_155 ;
struct V_51 * V_52 = args -> V_52 ;
struct V_26 * V_27 = V_52 -> V_67 ;
struct V_24 * V_156 = NULL ;
struct V_24 * V_157 = NULL ;
T_1 V_37 ;
int error ;
F_74 ( args ) ;
error = F_60 ( args , & V_37 ) ;
if ( error )
goto V_124;
error = F_18 ( args -> V_98 , V_52 , 0 , - 1 , & V_156 ) ;
if ( error )
goto V_124;
error = F_75 ( args -> V_98 , V_52 , V_37 , - 1 , & V_157 , V_57 ) ;
if ( error )
goto V_124;
F_20 ( args -> V_98 , V_157 , V_59 ) ;
V_157 -> V_158 = V_156 -> V_158 ;
memcpy ( V_157 -> V_31 , V_156 -> V_31 , args -> V_125 -> V_144 ) ;
if ( F_8 ( & V_27 -> V_33 ) ) {
struct V_159 * V_12 = V_157 -> V_31 ;
V_12 -> V_37 = F_14 ( V_157 -> V_38 ) ;
}
F_76 ( args -> V_98 , V_157 , 0 , args -> V_125 -> V_144 - 1 ) ;
error = F_77 ( args , 0 , 1 , & V_156 , V_57 ) ;
if ( error )
goto V_124;
V_155 = V_156 -> V_31 ;
V_52 -> V_160 -> V_161 ( & V_153 , V_155 ) ;
V_151 = V_52 -> V_160 -> V_162 ( V_155 ) ;
V_30 = V_157 -> V_31 ;
F_1 ( & V_148 , V_30 ) ;
V_149 = F_69 ( V_30 ) ;
V_151 [ 0 ] . V_131 = V_149 [ V_148 . V_15 - 1 ] . V_131 ;
V_151 [ 0 ] . V_163 = F_6 ( V_37 ) ;
V_153 . V_15 = 1 ;
V_52 -> V_160 -> V_164 ( V_155 , & V_153 ) ;
F_76 ( args -> V_98 , V_156 , 0 , args -> V_125 -> V_144 - 1 ) ;
error = 0 ;
V_124:
return error ;
}
STATIC int
F_61 (
struct V_142 * args ,
T_1 V_37 ,
struct V_24 * * V_55 )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_51 * V_52 = args -> V_52 ;
struct V_26 * V_27 = V_52 -> V_67 ;
struct V_24 * V_25 ;
int error ;
F_78 ( args ) ;
error = F_75 ( args -> V_98 , args -> V_52 , V_37 , - 1 , & V_25 ,
V_57 ) ;
if ( error )
return error ;
V_25 -> V_158 = & V_58 ;
F_20 ( args -> V_98 , V_25 , V_59 ) ;
V_30 = V_25 -> V_31 ;
memset ( V_30 , 0 , args -> V_125 -> V_144 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_17 = args -> V_125 -> V_144 ;
if ( F_8 ( & V_27 -> V_33 ) ) {
struct V_159 * V_12 = V_25 -> V_31 ;
V_32 . V_8 = V_10 ;
V_12 -> V_37 = F_14 ( V_25 -> V_38 ) ;
V_12 -> V_165 = F_14 ( V_52 -> V_166 ) ;
F_79 ( & V_12 -> V_35 , & V_27 -> V_33 . V_36 ) ;
V_32 . V_20 [ 0 ] . V_21 = sizeof( struct V_11 ) ;
} else {
V_32 . V_8 = V_9 ;
V_32 . V_20 [ 0 ] . V_21 = sizeof( struct V_167 ) ;
}
V_32 . V_20 [ 0 ] . V_22 = V_32 . V_17 - V_32 . V_20 [ 0 ] . V_21 ;
F_5 ( V_30 , & V_32 ) ;
F_76 ( args -> V_98 , V_25 , 0 , args -> V_125 -> V_144 - 1 ) ;
* V_55 = V_25 ;
return 0 ;
}
int
F_80 (
struct V_168 * V_169 ,
struct V_170 * V_171 ,
struct V_170 * V_172 )
{
T_1 V_37 ;
int error ;
F_81 ( V_169 -> args ) ;
ASSERT ( V_171 -> V_8 == V_9 ) ;
error = F_60 ( V_169 -> args , & V_37 ) ;
if ( error )
return error ;
error = F_61 ( V_169 -> args , V_37 , & V_172 -> V_25 ) ;
if ( error )
return error ;
V_172 -> V_37 = V_37 ;
V_172 -> V_8 = V_9 ;
F_82 ( V_169 , V_171 , V_172 ) ;
error = F_83 ( V_169 , V_171 , V_172 ) ;
if ( error )
return error ;
if ( V_169 -> V_173 ) {
F_84 ( V_169 -> args ) ;
error = F_66 ( V_171 -> V_25 , V_169 -> args ) ;
} else {
F_85 ( V_169 -> args ) ;
error = F_66 ( V_172 -> V_25 , V_169 -> args ) ;
}
V_171 -> V_131 = F_86 ( V_171 -> V_25 , NULL ) ;
V_172 -> V_131 = F_86 ( V_172 -> V_25 , NULL ) ;
return error ;
}
int
F_66 (
struct V_24 * V_25 ,
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
int V_174 ;
int V_175 ;
int V_176 ;
int V_177 ;
int V_5 ;
F_87 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_178 >= 0 && args -> V_178 <= V_32 . V_15 ) ;
V_175 = F_88 ( args , NULL ) ;
V_174 = ( V_32 . V_15 + 1 ) * sizeof( V_179 )
+ F_89 ( V_30 ) ;
for ( V_176 = 0 , V_5 = V_19 - 1 ; V_5 >= 0 ; V_5 -- ) {
if ( V_174 > V_32 . V_17 ) {
V_176 += V_32 . V_20 [ V_5 ] . V_22 ;
continue;
}
if ( ! V_32 . V_20 [ V_5 ] . V_22 )
continue;
V_177 = V_175 ;
if ( V_32 . V_20 [ V_5 ] . V_21 < V_32 . V_17 )
V_177 += sizeof( V_179 ) ;
if ( V_32 . V_20 [ V_5 ] . V_22 >= V_177 ) {
V_177 = F_90 ( V_25 , & V_32 , args , V_5 ) ;
goto V_180;
}
V_176 += V_32 . V_20 [ V_5 ] . V_22 ;
}
if ( ! V_32 . V_18 && V_176 < V_175 )
return - V_132 ;
F_91 ( args , & V_32 , V_25 ) ;
if ( V_32 . V_20 [ 0 ] . V_22 < ( V_175 + sizeof( V_179 ) ) ) {
V_177 = - V_132 ;
goto V_180;
}
V_177 = F_90 ( V_25 , & V_32 , args , 0 ) ;
V_180:
F_5 ( V_30 , & V_32 ) ;
F_76 ( args -> V_98 , V_25 ,
F_92 ( V_30 , & V_30 -> V_6 ,
F_89 ( V_30 ) ) ) ;
return V_177 ;
}
STATIC int
F_90 (
struct V_24 * V_25 ,
struct V_1 * V_32 ,
struct V_142 * args ,
int V_181 )
{
struct V_3 * V_30 ;
struct V_133 * V_134 ;
struct V_143 * V_135 ;
struct V_182 * V_183 ;
struct V_26 * V_27 ;
int V_177 ;
int V_5 ;
F_93 ( args ) ;
V_30 = V_25 -> V_31 ;
ASSERT ( V_181 >= 0 && V_181 < V_19 ) ;
ASSERT ( args -> V_178 >= 0 && args -> V_178 <= V_32 -> V_15 ) ;
V_134 = & F_69 ( V_30 ) [ args -> V_178 ] ;
if ( args -> V_178 < V_32 -> V_15 ) {
V_177 = V_32 -> V_15 - args -> V_178 ;
V_177 *= sizeof( V_179 ) ;
memmove ( V_134 + 1 , V_134 , V_177 ) ;
F_76 ( args -> V_98 , V_25 ,
F_92 ( V_30 , V_134 , V_177 + sizeof( * V_134 ) ) ) ;
}
V_32 -> V_15 ++ ;
V_27 = args -> V_98 -> V_184 ;
ASSERT ( V_32 -> V_20 [ V_181 ] . V_21 < args -> V_125 -> V_144 ) ;
ASSERT ( ( V_32 -> V_20 [ V_181 ] . V_21 & 0x3 ) == 0 ) ;
ASSERT ( V_32 -> V_20 [ V_181 ] . V_22 >=
F_88 ( args , NULL ) ) ;
ASSERT ( V_32 -> V_20 [ V_181 ] . V_22 < args -> V_125 -> V_144 ) ;
ASSERT ( ( V_32 -> V_20 [ V_181 ] . V_22 & 0x3 ) == 0 ) ;
V_32 -> V_20 [ V_181 ] . V_22 -= F_88 ( args , & V_177 ) ;
V_134 -> V_147 = F_2 ( V_32 -> V_20 [ V_181 ] . V_21 +
V_32 -> V_20 [ V_181 ] . V_22 ) ;
V_134 -> V_131 = F_6 ( args -> V_131 ) ;
V_134 -> V_108 = V_177 ? V_139 : 0 ;
V_134 -> V_108 |= F_23 ( args -> V_108 ) ;
if ( args -> V_115 & V_185 ) {
V_134 -> V_108 |= V_138 ;
if ( ( args -> V_186 == args -> V_37 ) &&
( args -> V_187 <= args -> V_178 ) ) {
args -> V_187 ++ ;
}
}
F_76 ( args -> V_98 , V_25 ,
F_92 ( V_30 , V_134 , sizeof( * V_134 ) ) ) ;
ASSERT ( ( args -> V_178 == 0 ) ||
( F_3 ( V_134 -> V_131 ) >= F_3 ( ( V_134 - 1 ) -> V_131 ) ) ) ;
ASSERT ( ( args -> V_178 == V_32 -> V_15 - 1 ) ||
( F_3 ( V_134 -> V_131 ) <= F_3 ( ( V_134 + 1 ) -> V_131 ) ) ) ;
if ( V_134 -> V_108 & V_139 ) {
V_135 = F_70 ( V_30 , args -> V_178 ) ;
V_135 -> V_105 = args -> V_105 ;
V_135 -> V_109 = F_2 ( args -> V_109 ) ;
memcpy ( ( char * ) V_135 -> V_107 , args -> V_106 , args -> V_105 ) ;
memcpy ( ( char * ) & V_135 -> V_107 [ args -> V_105 ] , args -> V_110 ,
F_4 ( V_135 -> V_109 ) ) ;
} else {
V_183 = F_94 ( V_30 , args -> V_178 ) ;
V_183 -> V_105 = args -> V_105 ;
memcpy ( ( char * ) V_183 -> V_106 , args -> V_106 , args -> V_105 ) ;
V_134 -> V_108 |= V_138 ;
V_183 -> V_109 = 0 ;
V_183 -> V_188 = 0 ;
args -> V_189 = 1 ;
args -> V_190 = F_95 ( V_27 , args -> V_109 ) ;
args -> V_191 = args -> V_109 ;
}
F_76 ( args -> V_98 , V_25 ,
F_92 ( V_30 , F_96 ( V_30 , args -> V_178 ) ,
F_97 ( V_30 , args -> V_178 ) ) ) ;
if ( F_4 ( V_134 -> V_147 ) < V_32 -> V_17 )
V_32 -> V_17 = F_4 ( V_134 -> V_147 ) ;
ASSERT ( V_32 -> V_17 >= V_32 -> V_15 * sizeof( V_179 )
+ F_89 ( V_30 ) ) ;
V_177 = ( V_32 -> V_15 - 1 ) * sizeof( V_179 )
+ F_89 ( V_30 ) ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
if ( V_32 -> V_20 [ V_5 ] . V_21 == V_177 ) {
V_32 -> V_20 [ V_5 ] . V_21 += sizeof( V_179 ) ;
V_32 -> V_20 [ V_5 ] . V_22 -= sizeof( V_179 ) ;
}
}
V_32 -> V_16 += F_97 ( V_30 , args -> V_178 ) ;
return 0 ;
}
STATIC void
F_91 (
struct V_142 * args ,
struct V_1 * V_192 ,
struct V_24 * V_25 )
{
struct V_3 * V_193 ;
struct V_3 * V_194 ;
struct V_1 V_195 ;
struct V_49 * V_98 = args -> V_98 ;
char * V_121 ;
F_98 ( args ) ;
V_121 = F_58 ( args -> V_125 -> V_144 , V_122 ) ;
memcpy ( V_121 , V_25 -> V_31 , args -> V_125 -> V_144 ) ;
memset ( V_25 -> V_31 , 0 , args -> V_125 -> V_144 ) ;
V_193 = ( V_146 * ) V_121 ;
V_194 = V_25 -> V_31 ;
memcpy ( V_25 -> V_31 , V_121 , F_89 ( V_193 ) ) ;
V_195 = * V_192 ;
V_192 -> V_17 = args -> V_125 -> V_144 ;
V_192 -> V_16 = 0 ;
V_192 -> V_15 = 0 ;
V_192 -> V_18 = 0 ;
V_192 -> V_20 [ 0 ] . V_21 = F_89 ( V_193 ) ;
V_192 -> V_20 [ 0 ] . V_22 = V_192 -> V_17 -
V_192 -> V_20 [ 0 ] . V_21 ;
F_5 ( V_194 , V_192 ) ;
F_99 ( args , V_193 , & V_195 , 0 ,
V_194 , V_192 , 0 , V_195 . V_15 ) ;
F_76 ( V_98 , V_25 , 0 , args -> V_125 -> V_144 - 1 ) ;
F_67 ( V_121 ) ;
}
static int
F_100 (
struct V_24 * V_196 ,
struct V_1 * V_197 ,
struct V_24 * V_198 ,
struct V_1 * V_199 )
{
struct V_133 * V_200 ;
struct V_133 * V_201 ;
V_200 = F_69 ( V_196 -> V_31 ) ;
V_201 = F_69 ( V_198 -> V_31 ) ;
if ( V_197 -> V_15 > 0 && V_199 -> V_15 > 0 &&
( ( F_3 ( V_201 [ 0 ] . V_131 ) <
F_3 ( V_200 [ 0 ] . V_131 ) ) ||
( F_3 ( V_201 [ V_199 -> V_15 - 1 ] . V_131 ) <
F_3 ( V_200 [ V_197 -> V_15 - 1 ] . V_131 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_101 (
struct V_24 * V_196 ,
struct V_24 * V_198 )
{
struct V_1 V_202 ;
struct V_1 V_203 ;
F_1 ( & V_202 , V_196 -> V_31 ) ;
F_1 ( & V_203 , V_198 -> V_31 ) ;
return F_100 ( V_196 , & V_202 , V_198 , & V_203 ) ;
}
STATIC void
F_82 (
struct V_168 * V_169 ,
struct V_170 * V_204 ,
struct V_170 * V_205 )
{
struct V_142 * args ;
struct V_3 * V_206 ;
struct V_3 * V_207 ;
struct V_1 V_202 ;
struct V_1 V_203 ;
struct V_133 * V_200 ;
struct V_133 * V_201 ;
int V_15 ;
int V_208 ;
int V_209 ;
int V_210 ;
int V_211 ;
ASSERT ( V_204 -> V_8 == V_9 ) ;
ASSERT ( V_205 -> V_8 == V_9 ) ;
V_206 = V_204 -> V_25 -> V_31 ;
V_207 = V_205 -> V_25 -> V_31 ;
F_1 ( & V_202 , V_206 ) ;
F_1 ( & V_203 , V_207 ) ;
ASSERT ( V_203 . V_15 == 0 ) ;
args = V_169 -> args ;
F_102 ( args ) ;
V_211 = 0 ;
if ( F_100 ( V_204 -> V_25 , & V_202 , V_205 -> V_25 , & V_203 ) ) {
struct V_170 * V_212 ;
struct V_1 V_213 ;
V_212 = V_204 ;
V_204 = V_205 ;
V_205 = V_212 ;
V_213 = V_202 ;
V_202 = V_203 ;
V_203 = V_213 ;
V_206 = V_204 -> V_25 -> V_31 ;
V_207 = V_205 -> V_25 -> V_31 ;
V_211 = 1 ;
}
V_169 -> V_173 = F_103 ( V_169 , V_204 , & V_202 ,
V_205 , & V_203 ,
& V_15 , & V_208 ) ;
if ( V_211 )
V_169 -> V_173 = ! V_169 -> V_173 ;
if ( V_15 < V_202 . V_15 ) {
V_15 = V_202 . V_15 - V_15 ;
V_210 = V_202 . V_16 - V_208 ;
V_210 += V_15 * sizeof( V_179 ) ;
V_209 = V_203 . V_17 - F_89 ( V_206 ) ;
V_209 -= V_203 . V_15 * sizeof( V_179 ) ;
if ( V_210 > V_209 )
F_91 ( args , & V_203 , V_205 -> V_25 ) ;
F_99 ( args , V_206 , & V_202 ,
V_202 . V_15 - V_15 , V_207 , & V_203 , 0 , V_15 ) ;
} else if ( V_15 > V_202 . V_15 ) {
ASSERT ( 0 ) ;
V_15 -= V_202 . V_15 ;
V_210 = V_208 - V_202 . V_16 ;
V_210 += V_15 * sizeof( V_179 ) ;
V_209 = V_202 . V_17 - F_89 ( V_206 ) ;
V_209 -= V_202 . V_15 * sizeof( V_179 ) ;
if ( V_210 > V_209 )
F_91 ( args , & V_202 , V_204 -> V_25 ) ;
F_99 ( args , V_207 , & V_203 , 0 , V_206 , & V_202 ,
V_202 . V_15 , V_15 ) ;
}
F_5 ( V_206 , & V_202 ) ;
F_5 ( V_207 , & V_203 ) ;
F_76 ( args -> V_98 , V_204 -> V_25 , 0 , args -> V_125 -> V_144 - 1 ) ;
F_76 ( args -> V_98 , V_205 -> V_25 , 0 , args -> V_125 -> V_144 - 1 ) ;
V_200 = F_69 ( V_206 ) ;
V_201 = F_69 ( V_207 ) ;
V_204 -> V_131 = F_3 ( V_200 [ V_202 . V_15 - 1 ] . V_131 ) ;
V_205 -> V_131 = F_3 ( V_201 [ V_203 . V_15 - 1 ] . V_131 ) ;
if ( V_204 -> V_178 > V_202 . V_15 ) {
ASSERT ( V_169 -> V_173 == 0 ) ;
V_205 -> V_178 = V_204 -> V_178 - V_202 . V_15 ;
args -> V_178 = args -> V_187 = V_205 -> V_178 ;
args -> V_37 = args -> V_186 = V_205 -> V_37 ;
} else if ( V_204 -> V_178 == V_202 . V_15 ) {
if ( V_169 -> V_173 ) {
args -> V_178 = V_204 -> V_178 ;
args -> V_37 = V_204 -> V_37 ;
args -> V_187 = 0 ;
args -> V_186 = V_205 -> V_37 ;
} else {
V_205 -> V_178 = V_204 -> V_178 - V_202 . V_15 ;
args -> V_178 = V_205 -> V_178 ;
args -> V_37 = V_205 -> V_37 ;
if ( ! V_169 -> V_214 ) {
args -> V_187 = V_205 -> V_178 ;
args -> V_186 = V_205 -> V_37 ;
}
}
} else {
ASSERT ( V_169 -> V_173 == 1 ) ;
args -> V_178 = args -> V_187 = V_204 -> V_178 ;
args -> V_37 = args -> V_186 = V_204 -> V_37 ;
}
}
STATIC int
F_103 (
struct V_168 * V_169 ,
struct V_170 * V_204 ,
struct V_1 * V_202 ,
struct V_170 * V_205 ,
struct V_1 * V_203 ,
int * V_215 ,
int * V_216 )
{
struct V_3 * V_206 = V_204 -> V_25 -> V_31 ;
struct V_3 * V_207 = V_205 -> V_25 -> V_31 ;
struct V_133 * V_134 ;
int V_15 ;
int V_209 ;
int V_178 ;
int V_208 = 0 ;
int V_217 ;
int V_218 ;
int V_219 = 0 ;
int V_177 ;
V_209 = V_202 -> V_15 + V_203 -> V_15 ;
V_217 = ( V_209 + 1 ) * sizeof( * V_134 ) ;
V_217 += V_202 -> V_16 + V_203 -> V_16 +
F_88 ( V_169 -> args , NULL ) ;
V_217 /= 2 ;
V_218 = V_169 -> args -> V_125 -> V_144 ;
V_134 = F_69 ( V_206 ) ;
for ( V_15 = V_178 = 0 ; V_15 < V_209 ; V_134 ++ , V_178 ++ , V_15 ++ ) {
#define F_104 ( T_12 ) (((A) < 0) ? -(A) : (A))
if ( V_15 == V_204 -> V_178 ) {
V_177 = V_208 + sizeof( * V_134 ) +
F_88 ( V_169 -> args , NULL ) ;
if ( F_104 ( V_217 - V_177 ) > V_218 )
break;
V_218 = F_104 ( V_217 - V_177 ) ;
V_208 = V_177 ;
V_219 = 1 ;
}
if ( V_15 == V_202 -> V_15 ) {
V_206 = V_207 ;
V_134 = F_69 ( V_206 ) ;
V_178 = 0 ;
}
V_177 = V_208 + sizeof( * V_134 ) + F_97 ( V_206 ,
V_178 ) ;
if ( F_104 ( V_217 - V_177 ) > V_218 )
break;
V_218 = F_104 ( V_217 - V_177 ) ;
V_208 = V_177 ;
#undef F_104
}
V_208 -= V_15 * sizeof( * V_134 ) ;
if ( V_219 ) {
V_208 -= sizeof( * V_134 ) +
F_88 ( V_169 -> args , NULL ) ;
}
* V_215 = V_15 ;
* V_216 = V_208 ;
return V_219 ;
}
int
F_105 (
struct V_168 * V_169 ,
int * V_220 )
{
struct V_3 * V_30 ;
struct V_170 * V_221 ;
struct V_1 V_32 ;
struct V_24 * V_25 ;
T_1 V_37 ;
int V_62 ;
int V_222 ;
int error ;
int V_223 ;
int V_5 ;
F_106 ( V_169 -> args ) ;
V_221 = & V_169 -> V_224 . V_221 [ V_169 -> V_224 . V_225 - 1 ] ;
V_30 = V_221 -> V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_62 = F_89 ( V_30 ) +
V_32 . V_15 * sizeof( V_179 ) +
V_32 . V_16 ;
if ( V_62 > ( V_169 -> args -> V_125 -> V_144 >> 1 ) ) {
* V_220 = 0 ;
return 0 ;
}
if ( V_32 . V_15 == 0 ) {
V_222 = ( V_32 . V_13 != 0 ) ;
memcpy ( & V_169 -> V_226 , & V_169 -> V_224 , sizeof( V_169 -> V_224 ) ) ;
error = F_107 ( V_169 , & V_169 -> V_226 , V_222 ,
0 , & V_223 ) ;
if ( error )
return error ;
if ( V_223 ) {
* V_220 = 0 ;
} else {
* V_220 = 2 ;
}
return 0 ;
}
V_222 = V_32 . V_13 < V_32 . V_14 ;
for ( V_5 = 0 ; V_5 < 2 ; V_222 = ! V_222 , V_5 ++ ) {
struct V_1 V_203 ;
if ( V_222 )
V_37 = V_32 . V_13 ;
else
V_37 = V_32 . V_14 ;
if ( V_37 == 0 )
continue;
error = F_18 ( V_169 -> args -> V_98 , V_169 -> args -> V_52 ,
V_37 , - 1 , & V_25 ) ;
if ( error )
return error ;
F_1 ( & V_203 , V_25 -> V_31 ) ;
V_62 = V_169 -> args -> V_125 -> V_144 -
( V_169 -> args -> V_125 -> V_144 >> 2 ) -
V_32 . V_16 - V_203 . V_16 -
( ( V_32 . V_15 + V_203 . V_15 ) *
sizeof( V_179 ) ) -
F_89 ( V_30 ) ;
F_108 ( V_169 -> args -> V_98 , V_25 ) ;
if ( V_62 >= 0 )
break;
}
if ( V_5 >= 2 ) {
* V_220 = 0 ;
return 0 ;
}
memcpy ( & V_169 -> V_226 , & V_169 -> V_224 , sizeof( V_169 -> V_224 ) ) ;
if ( V_37 < V_221 -> V_37 ) {
error = F_107 ( V_169 , & V_169 -> V_226 , V_222 ,
0 , & V_223 ) ;
} else {
error = F_107 ( V_169 , & V_169 -> V_224 , V_222 ,
0 , & V_223 ) ;
}
if ( error )
return error ;
if ( V_223 ) {
* V_220 = 0 ;
} else {
* V_220 = 1 ;
}
return 0 ;
}
int
F_109 (
struct V_24 * V_25 ,
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_133 * V_134 ;
int V_163 ;
int V_227 ;
int V_228 ;
int V_175 ;
int V_174 ;
int V_177 ;
int V_5 ;
F_110 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( V_32 . V_15 > 0 && V_32 . V_15 < args -> V_125 -> V_144 / 8 ) ;
ASSERT ( args -> V_178 >= 0 && args -> V_178 < V_32 . V_15 ) ;
ASSERT ( V_32 . V_17 >= V_32 . V_15 * sizeof( * V_134 ) +
F_89 ( V_30 ) ) ;
V_134 = & F_69 ( V_30 ) [ args -> V_178 ] ;
ASSERT ( F_4 ( V_134 -> V_147 ) >= V_32 . V_17 ) ;
ASSERT ( F_4 ( V_134 -> V_147 ) < args -> V_125 -> V_144 ) ;
V_174 = V_32 . V_15 * sizeof( V_179 )
+ F_89 ( V_30 ) ;
V_177 = V_32 . V_20 [ 0 ] . V_22 ;
V_163 = V_227 = - 1 ;
V_228 = V_19 - 1 ;
V_175 = F_97 ( V_30 , args -> V_178 ) ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
ASSERT ( V_32 . V_20 [ V_5 ] . V_21 < args -> V_125 -> V_144 ) ;
ASSERT ( V_32 . V_20 [ V_5 ] . V_22 < args -> V_125 -> V_144 ) ;
if ( V_32 . V_20 [ V_5 ] . V_21 == V_174 ) {
V_32 . V_20 [ V_5 ] . V_21 -= sizeof( V_179 ) ;
V_32 . V_20 [ V_5 ] . V_22 += sizeof( V_179 ) ;
}
if ( V_32 . V_20 [ V_5 ] . V_21 + V_32 . V_20 [ V_5 ] . V_22 ==
F_4 ( V_134 -> V_147 ) ) {
V_163 = V_5 ;
} else if ( V_32 . V_20 [ V_5 ] . V_21 ==
( F_4 ( V_134 -> V_147 ) + V_175 ) ) {
V_227 = V_5 ;
} else if ( V_32 . V_20 [ V_5 ] . V_22 < V_177 ) {
V_177 = V_32 . V_20 [ V_5 ] . V_22 ;
V_228 = V_5 ;
}
}
if ( ( V_163 >= 0 ) || ( V_227 >= 0 ) ) {
if ( ( V_163 >= 0 ) && ( V_227 >= 0 ) ) {
V_32 . V_20 [ V_163 ] . V_22 += V_175 ;
V_32 . V_20 [ V_163 ] . V_22 += V_32 . V_20 [ V_227 ] . V_22 ;
V_32 . V_20 [ V_227 ] . V_21 = 0 ;
V_32 . V_20 [ V_227 ] . V_22 = 0 ;
} else if ( V_163 >= 0 ) {
V_32 . V_20 [ V_163 ] . V_22 += V_175 ;
} else {
V_32 . V_20 [ V_227 ] . V_21 = F_4 ( V_134 -> V_147 ) ;
V_32 . V_20 [ V_227 ] . V_22 += V_175 ;
}
} else {
if ( V_32 . V_20 [ V_228 ] . V_22 < V_175 ) {
V_32 . V_20 [ V_228 ] . V_21 = F_4 ( V_134 -> V_147 ) ;
V_32 . V_20 [ V_228 ] . V_22 = V_175 ;
}
}
if ( F_4 ( V_134 -> V_147 ) == V_32 . V_17 )
V_228 = 1 ;
else
V_228 = 0 ;
memset ( F_96 ( V_30 , args -> V_178 ) , 0 , V_175 ) ;
V_32 . V_16 -= V_175 ;
F_76 ( args -> V_98 , V_25 ,
F_92 ( V_30 , F_96 ( V_30 , args -> V_178 ) ,
V_175 ) ) ;
V_177 = ( V_32 . V_15 - args -> V_178 ) * sizeof( V_179 ) ;
memmove ( V_134 , V_134 + 1 , V_177 ) ;
V_32 . V_15 -- ;
F_76 ( args -> V_98 , V_25 ,
F_92 ( V_30 , V_134 , V_177 + sizeof( V_179 ) ) ) ;
V_134 = & F_69 ( V_30 ) [ V_32 . V_15 ] ;
memset ( V_134 , 0 , sizeof( V_179 ) ) ;
if ( V_228 ) {
V_177 = args -> V_125 -> V_144 ;
V_134 = F_69 ( V_30 ) ;
for ( V_5 = V_32 . V_15 - 1 ; V_5 >= 0 ; V_134 ++ , V_5 -- ) {
ASSERT ( F_4 ( V_134 -> V_147 ) >= V_32 . V_17 ) ;
ASSERT ( F_4 ( V_134 -> V_147 ) < args -> V_125 -> V_144 ) ;
if ( F_4 ( V_134 -> V_147 ) < V_177 )
V_177 = F_4 ( V_134 -> V_147 ) ;
}
V_32 . V_17 = V_177 ;
if ( ! V_32 . V_17 )
V_32 . V_17 = V_177 - V_229 ;
} else {
V_32 . V_18 = 1 ;
}
F_5 ( V_30 , & V_32 ) ;
F_76 ( args -> V_98 , V_25 ,
F_92 ( V_30 , & V_30 -> V_6 ,
F_89 ( V_30 ) ) ) ;
V_177 = V_32 . V_16 + F_89 ( V_30 ) +
V_32 . V_15 * sizeof( V_179 ) ;
return V_177 < args -> V_125 -> V_230 ;
}
void
F_111 (
struct V_168 * V_169 ,
struct V_170 * V_231 ,
struct V_170 * V_232 )
{
struct V_3 * V_233 = V_231 -> V_25 -> V_31 ;
struct V_3 * V_234 = V_232 -> V_25 -> V_31 ;
struct V_1 V_235 ;
struct V_1 V_236 ;
struct V_133 * V_134 ;
F_112 ( V_169 -> args ) ;
V_233 = V_231 -> V_25 -> V_31 ;
V_234 = V_232 -> V_25 -> V_31 ;
F_1 ( & V_235 , V_233 ) ;
F_1 ( & V_236 , V_234 ) ;
V_134 = F_69 ( V_233 ) ;
V_231 -> V_131 = F_3 ( V_134 [ V_235 . V_15 - 1 ] . V_131 ) ;
if ( V_236 . V_18 == 0 ) {
if ( F_100 ( V_232 -> V_25 , & V_236 ,
V_231 -> V_25 , & V_235 ) ) {
F_99 ( V_169 -> args ,
V_233 , & V_235 , 0 ,
V_234 , & V_236 , 0 ,
V_235 . V_15 ) ;
} else {
F_99 ( V_169 -> args ,
V_233 , & V_235 , 0 ,
V_234 , & V_236 ,
V_236 . V_15 , V_235 . V_15 ) ;
}
} else {
struct V_3 * V_237 ;
struct V_1 V_238 ;
V_237 = F_113 ( V_169 -> args -> V_125 -> V_144 , V_122 ) ;
memcpy ( V_237 , V_234 , F_89 ( V_234 ) ) ;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_238 . V_8 = V_236 . V_8 ;
V_238 . V_13 = V_236 . V_13 ;
V_238 . V_14 = V_236 . V_14 ;
V_238 . V_17 = V_169 -> args -> V_125 -> V_144 ;
F_5 ( V_237 , & V_238 ) ;
if ( F_100 ( V_232 -> V_25 , & V_236 ,
V_231 -> V_25 , & V_235 ) ) {
F_99 ( V_169 -> args ,
V_233 , & V_235 , 0 ,
V_237 , & V_238 , 0 ,
V_235 . V_15 ) ;
F_99 ( V_169 -> args ,
V_234 , & V_236 , 0 ,
V_237 , & V_238 , V_238 . V_15 ,
V_236 . V_15 ) ;
} else {
F_99 ( V_169 -> args ,
V_234 , & V_236 , 0 ,
V_237 , & V_238 , 0 ,
V_236 . V_15 ) ;
F_99 ( V_169 -> args ,
V_233 , & V_235 , 0 ,
V_237 , & V_238 , V_238 . V_15 ,
V_235 . V_15 ) ;
}
memcpy ( V_234 , V_237 , V_169 -> args -> V_125 -> V_144 ) ;
V_236 = V_238 ;
F_67 ( V_237 ) ;
}
F_5 ( V_234 , & V_236 ) ;
F_76 ( V_169 -> args -> V_98 , V_232 -> V_25 , 0 ,
V_169 -> args -> V_125 -> V_144 - 1 ) ;
V_134 = F_69 ( V_234 ) ;
V_232 -> V_131 = F_3 ( V_134 [ V_236 . V_15 - 1 ] . V_131 ) ;
}
int
F_65 (
struct V_24 * V_25 ,
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_133 * V_134 ;
struct V_133 * V_149 ;
struct V_143 * V_135 ;
struct V_182 * V_183 ;
T_13 V_131 ;
int V_239 ;
int V_240 ;
F_114 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_149 = F_69 ( V_30 ) ;
ASSERT ( V_32 . V_15 < args -> V_125 -> V_144 / 8 ) ;
V_131 = args -> V_131 ;
V_239 = V_240 = V_32 . V_15 / 2 ;
for ( V_134 = & V_149 [ V_239 ] ; V_240 > 4 ; V_134 = & V_149 [ V_239 ] ) {
V_240 /= 2 ;
if ( F_3 ( V_134 -> V_131 ) < V_131 )
V_239 += V_240 ;
else if ( F_3 ( V_134 -> V_131 ) > V_131 )
V_239 -= V_240 ;
else
break;
}
ASSERT ( V_239 >= 0 && ( ! V_32 . V_15 || V_239 < V_32 . V_15 ) ) ;
ASSERT ( V_240 <= 4 || F_3 ( V_134 -> V_131 ) == V_131 ) ;
while ( V_239 > 0 && F_3 ( V_134 -> V_131 ) >= V_131 ) {
V_134 -- ;
V_239 -- ;
}
while ( V_239 < V_32 . V_15 &&
F_3 ( V_134 -> V_131 ) < V_131 ) {
V_134 ++ ;
V_239 ++ ;
}
if ( V_239 == V_32 . V_15 || F_3 ( V_134 -> V_131 ) != V_131 ) {
args -> V_178 = V_239 ;
return - V_114 ;
}
for (; V_239 < V_32 . V_15 && ( F_3 ( V_134 -> V_131 ) == V_131 ) ;
V_134 ++ , V_239 ++ ) {
if ( ( args -> V_108 & V_138 ) !=
( V_134 -> V_108 & V_138 ) ) {
continue;
}
if ( V_134 -> V_108 & V_139 ) {
V_135 = F_70 ( V_30 , V_239 ) ;
if ( V_135 -> V_105 != args -> V_105 )
continue;
if ( memcmp ( args -> V_106 , V_135 -> V_107 ,
args -> V_105 ) != 0 )
continue;
if ( ! F_21 ( args -> V_108 , V_134 -> V_108 ) )
continue;
args -> V_178 = V_239 ;
return - V_117 ;
} else {
V_183 = F_94 ( V_30 , V_239 ) ;
if ( V_183 -> V_105 != args -> V_105 )
continue;
if ( memcmp ( args -> V_106 , V_183 -> V_106 ,
args -> V_105 ) != 0 )
continue;
if ( ! F_21 ( args -> V_108 , V_134 -> V_108 ) )
continue;
args -> V_178 = V_239 ;
args -> V_191 = F_3 ( V_183 -> V_109 ) ;
args -> V_189 = F_3 ( V_183 -> V_188 ) ;
args -> V_190 = F_95 (
args -> V_52 -> V_67 ,
args -> V_191 ) ;
return - V_117 ;
}
}
args -> V_178 = V_239 ;
return - V_114 ;
}
int
F_115 (
struct V_24 * V_25 ,
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_133 * V_134 ;
struct V_143 * V_135 ;
struct V_182 * V_183 ;
int V_109 ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( V_32 . V_15 < args -> V_125 -> V_144 / 8 ) ;
ASSERT ( args -> V_178 < V_32 . V_15 ) ;
V_134 = & F_69 ( V_30 ) [ args -> V_178 ] ;
if ( V_134 -> V_108 & V_139 ) {
V_135 = F_70 ( V_30 , args -> V_178 ) ;
ASSERT ( V_135 -> V_105 == args -> V_105 ) ;
ASSERT ( memcmp ( args -> V_106 , V_135 -> V_107 , args -> V_105 ) == 0 ) ;
V_109 = F_4 ( V_135 -> V_109 ) ;
if ( args -> V_108 & V_118 ) {
args -> V_109 = V_109 ;
return 0 ;
}
if ( args -> V_109 < V_109 ) {
args -> V_109 = V_109 ;
return - V_119 ;
}
args -> V_109 = V_109 ;
memcpy ( args -> V_110 , & V_135 -> V_107 [ args -> V_105 ] , V_109 ) ;
} else {
V_183 = F_94 ( V_30 , args -> V_178 ) ;
ASSERT ( V_183 -> V_105 == args -> V_105 ) ;
ASSERT ( memcmp ( args -> V_106 , V_183 -> V_106 , args -> V_105 ) == 0 ) ;
args -> V_191 = F_3 ( V_183 -> V_109 ) ;
args -> V_189 = F_3 ( V_183 -> V_188 ) ;
args -> V_190 = F_95 ( args -> V_52 -> V_67 ,
args -> V_191 ) ;
if ( args -> V_108 & V_118 ) {
args -> V_109 = args -> V_191 ;
return 0 ;
}
if ( args -> V_109 < args -> V_191 ) {
args -> V_109 = args -> V_191 ;
return - V_119 ;
}
args -> V_109 = args -> V_191 ;
}
return 0 ;
}
STATIC void
F_99 (
struct V_142 * args ,
struct V_3 * V_241 ,
struct V_1 * V_242 ,
int V_243 ,
struct V_3 * V_244 ,
struct V_1 * V_245 ,
int V_246 ,
int V_15 )
{
struct V_133 * V_247 ;
struct V_133 * V_248 ;
int V_249 ;
int V_177 ;
int V_5 ;
if ( V_15 == 0 )
return;
ASSERT ( V_242 -> V_8 == V_9 ||
V_242 -> V_8 == V_10 ) ;
ASSERT ( V_242 -> V_8 == V_245 -> V_8 ) ;
ASSERT ( V_242 -> V_15 > 0 && V_242 -> V_15 < args -> V_125 -> V_144 / 8 ) ;
ASSERT ( V_242 -> V_17 >= ( V_242 -> V_15 * sizeof( * V_247 ) )
+ F_89 ( V_241 ) ) ;
ASSERT ( V_245 -> V_15 < args -> V_125 -> V_144 / 8 ) ;
ASSERT ( V_245 -> V_17 >= ( V_245 -> V_15 * sizeof( * V_248 ) )
+ F_89 ( V_244 ) ) ;
ASSERT ( V_243 < V_242 -> V_15 ) ;
ASSERT ( V_246 <= V_245 -> V_15 ) ;
ASSERT ( V_15 <= V_242 -> V_15 ) ;
if ( V_246 < V_245 -> V_15 ) {
V_177 = V_245 -> V_15 - V_246 ;
V_177 *= sizeof( V_179 ) ;
V_247 = & F_69 ( V_244 ) [ V_246 ] ;
V_248 = & F_69 ( V_244 ) [ V_246 + V_15 ] ;
memmove ( V_248 , V_247 , V_177 ) ;
}
V_247 = & F_69 ( V_241 ) [ V_243 ] ;
V_248 = & F_69 ( V_244 ) [ V_246 ] ;
V_249 = V_246 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_247 ++ , V_248 ++ , V_249 ++ , V_5 ++ ) {
ASSERT ( F_4 ( V_247 -> V_147 ) >= V_242 -> V_17 ) ;
V_177 = F_97 ( V_241 , V_243 + V_5 ) ;
#ifdef F_116
if ( V_247 -> V_108 & V_138 ) {
memset ( F_96 ( V_241 , V_243 + V_5 ) , 0 , V_177 ) ;
V_242 -> V_16 -= V_177 ;
V_242 -> V_15 -= 1 ;
V_248 -- ;
V_249 -- ;
if ( ( V_243 + V_5 ) < V_63 )
V_250 ++ ;
} else {
#endif
V_245 -> V_17 -= V_177 ;
V_248 -> V_131 = V_247 -> V_131 ;
V_248 -> V_147 = F_2 ( V_245 -> V_17 ) ;
V_248 -> V_108 = V_247 -> V_108 ;
ASSERT ( F_4 ( V_248 -> V_147 ) + V_177
<= args -> V_125 -> V_144 ) ;
memmove ( F_96 ( V_244 , V_249 ) ,
F_96 ( V_241 , V_243 + V_5 ) , V_177 ) ;
ASSERT ( F_4 ( V_247 -> V_147 ) + V_177
<= args -> V_125 -> V_144 ) ;
memset ( F_96 ( V_241 , V_243 + V_5 ) , 0 , V_177 ) ;
V_242 -> V_16 -= V_177 ;
V_245 -> V_16 += V_177 ;
V_242 -> V_15 -= 1 ;
V_245 -> V_15 += 1 ;
V_177 = V_245 -> V_15 * sizeof( V_179 )
+ F_89 ( V_244 ) ;
ASSERT ( V_245 -> V_17 >= V_177 ) ;
#ifdef F_116
}
#endif
}
if ( V_243 == V_242 -> V_15 ) {
V_177 = V_15 * sizeof( V_179 ) ;
V_247 = & F_69 ( V_241 ) [ V_243 ] ;
ASSERT ( ( ( char * ) V_247 + V_177 ) <=
( ( char * ) V_241 + args -> V_125 -> V_144 ) ) ;
memset ( V_247 , 0 , V_177 ) ;
} else {
V_177 = ( V_242 -> V_15 - V_15 ) * sizeof( V_179 ) ;
V_247 = & F_69 ( V_241 ) [ V_243 + V_15 ] ;
V_248 = & F_69 ( V_241 ) [ V_243 ] ;
memmove ( V_248 , V_247 , V_177 ) ;
V_177 = V_15 * sizeof( V_179 ) ;
V_247 = & F_69 ( V_241 ) [ V_242 -> V_15 ] ;
ASSERT ( ( ( char * ) V_247 + V_177 ) <=
( ( char * ) V_241 + args -> V_125 -> V_144 ) ) ;
memset ( V_247 , 0 , V_177 ) ;
}
V_245 -> V_20 [ 0 ] . V_21 = F_89 ( V_244 ) ;
V_245 -> V_20 [ 0 ] . V_21 += V_245 -> V_15 * sizeof( V_179 ) ;
V_245 -> V_20 [ 0 ] . V_22 = V_245 -> V_17 - V_245 -> V_20 [ 0 ] . V_21 ;
V_245 -> V_20 [ 1 ] . V_21 = 0 ;
V_245 -> V_20 [ 2 ] . V_21 = 0 ;
V_245 -> V_20 [ 1 ] . V_22 = 0 ;
V_245 -> V_20 [ 2 ] . V_22 = 0 ;
V_242 -> V_18 = 1 ;
}
T_13
F_86 (
struct V_24 * V_25 ,
int * V_15 )
{
struct V_1 V_32 ;
struct V_133 * V_149 ;
F_1 ( & V_32 , V_25 -> V_31 ) ;
V_149 = F_69 ( V_25 -> V_31 ) ;
if ( V_15 )
* V_15 = V_32 . V_15 ;
if ( ! V_32 . V_15 )
return 0 ;
return F_3 ( V_149 [ V_32 . V_15 - 1 ] . V_131 ) ;
}
STATIC int
F_97 ( V_146 * V_30 , int V_178 )
{
struct V_133 * V_149 ;
T_11 * V_135 ;
T_14 * V_183 ;
int V_22 ;
V_149 = F_69 ( V_30 ) ;
if ( V_149 [ V_178 ] . V_108 & V_139 ) {
V_135 = F_70 ( V_30 , V_178 ) ;
V_22 = F_117 ( V_135 -> V_105 ,
F_4 ( V_135 -> V_109 ) ) ;
} else {
V_183 = F_94 ( V_30 , V_178 ) ;
V_22 = F_118 ( V_183 -> V_105 ) ;
}
return V_22 ;
}
int
F_88 (
struct V_142 * args ,
int * V_251 )
{
int V_22 ;
V_22 = F_117 ( args -> V_105 , args -> V_109 ) ;
if ( V_22 < F_119 ( args -> V_125 -> V_144 ) ) {
if ( V_251 )
* V_251 = 1 ;
return V_22 ;
}
if ( V_251 )
* V_251 = 0 ;
return F_118 ( args -> V_105 ) ;
}
int
F_120 (
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_133 * V_134 ;
struct V_182 * V_183 ;
struct V_24 * V_25 ;
int error ;
#ifdef F_45
struct V_1 V_32 ;
T_11 * V_135 ;
int V_105 ;
char * V_106 ;
#endif
F_121 ( args ) ;
error = F_18 ( args -> V_98 , args -> V_52 , args -> V_37 , - 1 , & V_25 ) ;
if ( error )
return error ;
V_30 = V_25 -> V_31 ;
V_134 = & F_69 ( V_30 ) [ args -> V_178 ] ;
ASSERT ( V_134 -> V_108 & V_138 ) ;
#ifdef F_45
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_178 < V_32 . V_15 ) ;
ASSERT ( args -> V_178 >= 0 ) ;
if ( V_134 -> V_108 & V_139 ) {
V_135 = F_70 ( V_30 , args -> V_178 ) ;
V_105 = V_135 -> V_105 ;
V_106 = ( char * ) V_135 -> V_107 ;
} else {
V_183 = F_94 ( V_30 , args -> V_178 ) ;
V_105 = V_183 -> V_105 ;
V_106 = ( char * ) V_183 -> V_106 ;
}
ASSERT ( F_3 ( V_134 -> V_131 ) == args -> V_131 ) ;
ASSERT ( V_105 == args -> V_105 ) ;
ASSERT ( memcmp ( V_106 , args -> V_106 , V_105 ) == 0 ) ;
#endif
V_134 -> V_108 &= ~ V_138 ;
F_76 ( args -> V_98 , V_25 ,
F_92 ( V_30 , V_134 , sizeof( * V_134 ) ) ) ;
if ( args -> V_189 ) {
ASSERT ( ( V_134 -> V_108 & V_139 ) == 0 ) ;
V_183 = F_94 ( V_30 , args -> V_178 ) ;
V_183 -> V_188 = F_6 ( args -> V_189 ) ;
V_183 -> V_109 = F_6 ( args -> V_191 ) ;
F_76 ( args -> V_98 , V_25 ,
F_92 ( V_30 , V_183 , sizeof( * V_183 ) ) ) ;
}
return F_122 ( & args -> V_98 , args -> V_52 ) ;
}
int
F_123 (
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_133 * V_134 ;
struct V_182 * V_183 ;
struct V_24 * V_25 ;
int error ;
#ifdef F_45
struct V_1 V_32 ;
#endif
F_124 ( args ) ;
error = F_18 ( args -> V_98 , args -> V_52 , args -> V_37 , - 1 , & V_25 ) ;
if ( error )
return error ;
V_30 = V_25 -> V_31 ;
#ifdef F_45
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_178 < V_32 . V_15 ) ;
ASSERT ( args -> V_178 >= 0 ) ;
#endif
V_134 = & F_69 ( V_30 ) [ args -> V_178 ] ;
ASSERT ( ( V_134 -> V_108 & V_138 ) == 0 ) ;
V_134 -> V_108 |= V_138 ;
F_76 ( args -> V_98 , V_25 ,
F_92 ( V_30 , V_134 , sizeof( * V_134 ) ) ) ;
if ( ( V_134 -> V_108 & V_139 ) == 0 ) {
V_183 = F_94 ( V_30 , args -> V_178 ) ;
V_183 -> V_188 = 0 ;
V_183 -> V_109 = 0 ;
F_76 ( args -> V_98 , V_25 ,
F_92 ( V_30 , V_183 , sizeof( * V_183 ) ) ) ;
}
return F_122 ( & args -> V_98 , args -> V_52 ) ;
}
int
F_125 (
struct V_142 * args )
{
struct V_3 * V_206 ;
struct V_3 * V_207 ;
struct V_133 * V_252 ;
struct V_133 * V_253 ;
struct V_182 * V_183 ;
struct V_24 * V_156 ;
struct V_24 * V_157 ;
int error ;
#ifdef F_45
struct V_1 V_202 ;
struct V_1 V_203 ;
T_11 * V_135 ;
int V_254 , V_255 ;
char * V_256 , * V_257 ;
#endif
F_126 ( args ) ;
error = F_18 ( args -> V_98 , args -> V_52 , args -> V_37 , - 1 , & V_156 ) ;
if ( error )
return error ;
if ( args -> V_186 != args -> V_37 ) {
error = F_18 ( args -> V_98 , args -> V_52 , args -> V_186 ,
- 1 , & V_157 ) ;
if ( error )
return error ;
} else {
V_157 = V_156 ;
}
V_206 = V_156 -> V_31 ;
V_252 = & F_69 ( V_206 ) [ args -> V_178 ] ;
V_207 = V_157 -> V_31 ;
V_253 = & F_69 ( V_207 ) [ args -> V_187 ] ;
#ifdef F_45
F_1 ( & V_202 , V_206 ) ;
ASSERT ( args -> V_178 < V_202 . V_15 ) ;
ASSERT ( args -> V_178 >= 0 ) ;
F_1 ( & V_203 , V_207 ) ;
ASSERT ( args -> V_187 < V_203 . V_15 ) ;
ASSERT ( args -> V_187 >= 0 ) ;
if ( V_252 -> V_108 & V_139 ) {
V_135 = F_70 ( V_206 , args -> V_178 ) ;
V_254 = V_135 -> V_105 ;
V_256 = ( char * ) V_135 -> V_107 ;
} else {
V_183 = F_94 ( V_206 , args -> V_178 ) ;
V_254 = V_183 -> V_105 ;
V_256 = ( char * ) V_183 -> V_106 ;
}
if ( V_253 -> V_108 & V_139 ) {
V_135 = F_70 ( V_207 , args -> V_187 ) ;
V_255 = V_135 -> V_105 ;
V_257 = ( char * ) V_135 -> V_107 ;
} else {
V_183 = F_94 ( V_207 , args -> V_187 ) ;
V_255 = V_183 -> V_105 ;
V_257 = ( char * ) V_183 -> V_106 ;
}
ASSERT ( F_3 ( V_252 -> V_131 ) == F_3 ( V_253 -> V_131 ) ) ;
ASSERT ( V_254 == V_255 ) ;
ASSERT ( memcmp ( V_256 , V_257 , V_254 ) == 0 ) ;
#endif
ASSERT ( V_252 -> V_108 & V_138 ) ;
ASSERT ( ( V_253 -> V_108 & V_138 ) == 0 ) ;
V_252 -> V_108 &= ~ V_138 ;
F_76 ( args -> V_98 , V_156 ,
F_92 ( V_206 , V_252 , sizeof( * V_252 ) ) ) ;
if ( args -> V_189 ) {
ASSERT ( ( V_252 -> V_108 & V_139 ) == 0 ) ;
V_183 = F_94 ( V_206 , args -> V_178 ) ;
V_183 -> V_188 = F_6 ( args -> V_189 ) ;
V_183 -> V_109 = F_6 ( args -> V_191 ) ;
F_76 ( args -> V_98 , V_156 ,
F_92 ( V_206 , V_183 , sizeof( * V_183 ) ) ) ;
}
V_253 -> V_108 |= V_138 ;
F_76 ( args -> V_98 , V_157 ,
F_92 ( V_207 , V_253 , sizeof( * V_253 ) ) ) ;
if ( ( V_253 -> V_108 & V_139 ) == 0 ) {
V_183 = F_94 ( V_207 , args -> V_187 ) ;
V_183 -> V_188 = 0 ;
V_183 -> V_109 = 0 ;
F_76 ( args -> V_98 , V_157 ,
F_92 ( V_207 , V_183 , sizeof( * V_183 ) ) ) ;
}
error = F_122 ( & args -> V_98 , args -> V_52 ) ;
return error ;
}
