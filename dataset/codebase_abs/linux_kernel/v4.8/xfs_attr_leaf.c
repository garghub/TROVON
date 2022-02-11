static void
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
if ( V_6 -> V_9 . V_10 . V_11 == F_2 ( V_12 ) ) {
V_8 = (struct V_7 * ) V_6 ;
V_4 -> V_13 = F_3 ( V_8 -> V_13 ) ;
} else {
V_4 -> V_13 = F_3 ( V_6 -> V_9 . V_13 ) ;
}
if ( V_4 -> V_13 == V_14 ) {
ASSERT ( ! V_4 -> V_15 && ! V_4 -> V_16 ) ;
ASSERT ( V_2 -> V_17 > V_18 ) ;
V_4 -> V_13 = V_2 -> V_17 ;
}
}
static void
F_4 (
struct V_1 * V_2 ,
struct V_5 * V_4 ,
struct V_3 * V_6 )
{
struct V_7 * V_8 ;
T_1 V_13 ;
ASSERT ( V_6 -> V_13 != V_14 ) ;
V_13 = V_6 -> V_13 ;
if ( V_13 > V_18 ) {
ASSERT ( V_6 -> V_13 == V_2 -> V_17 ) ;
V_13 = V_14 ;
}
if ( V_6 -> V_11 == V_12 ) {
V_8 = (struct V_7 * ) V_4 ;
V_8 -> V_13 = F_2 ( V_13 ) ;
} else {
V_4 -> V_9 . V_13 = F_2 ( V_13 ) ;
}
}
void
F_5 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_19 ;
ASSERT ( V_6 -> V_9 . V_10 . V_11 == F_2 ( V_20 ) ||
V_6 -> V_9 . V_10 . V_11 == F_2 ( V_12 ) ) ;
if ( V_6 -> V_9 . V_10 . V_11 == F_2 ( V_12 ) ) {
struct V_7 * V_8 = (struct V_7 * ) V_6 ;
V_4 -> V_21 = F_6 ( V_8 -> V_10 . V_9 . V_21 ) ;
V_4 -> V_22 = F_6 ( V_8 -> V_10 . V_9 . V_22 ) ;
V_4 -> V_11 = F_3 ( V_8 -> V_10 . V_9 . V_11 ) ;
V_4 -> V_15 = F_3 ( V_8 -> V_15 ) ;
V_4 -> V_16 = F_3 ( V_8 -> V_16 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_23 = V_8 -> V_23 ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
V_4 -> V_25 [ V_19 ] . V_26 = F_3 ( V_8 -> V_25 [ V_19 ] . V_26 ) ;
V_4 -> V_25 [ V_19 ] . V_27 = F_3 ( V_8 -> V_25 [ V_19 ] . V_27 ) ;
}
return;
}
V_4 -> V_21 = F_6 ( V_6 -> V_9 . V_10 . V_21 ) ;
V_4 -> V_22 = F_6 ( V_6 -> V_9 . V_10 . V_22 ) ;
V_4 -> V_11 = F_3 ( V_6 -> V_9 . V_10 . V_11 ) ;
V_4 -> V_15 = F_3 ( V_6 -> V_9 . V_15 ) ;
V_4 -> V_16 = F_3 ( V_6 -> V_9 . V_16 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_23 = V_6 -> V_9 . V_23 ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
V_4 -> V_25 [ V_19 ] . V_26 = F_3 ( V_6 -> V_9 . V_25 [ V_19 ] . V_26 ) ;
V_4 -> V_25 [ V_19 ] . V_27 = F_3 ( V_6 -> V_9 . V_25 [ V_19 ] . V_27 ) ;
}
}
void
F_7 (
struct V_1 * V_2 ,
struct V_5 * V_4 ,
struct V_3 * V_6 )
{
int V_19 ;
ASSERT ( V_6 -> V_11 == V_20 ||
V_6 -> V_11 == V_12 ) ;
if ( V_6 -> V_11 == V_12 ) {
struct V_7 * V_8 = (struct V_7 * ) V_4 ;
V_8 -> V_10 . V_9 . V_21 = F_8 ( V_6 -> V_21 ) ;
V_8 -> V_10 . V_9 . V_22 = F_8 ( V_6 -> V_22 ) ;
V_8 -> V_10 . V_9 . V_11 = F_2 ( V_6 -> V_11 ) ;
V_8 -> V_15 = F_2 ( V_6 -> V_15 ) ;
V_8 -> V_16 = F_2 ( V_6 -> V_16 ) ;
F_4 ( V_2 , V_4 , V_6 ) ;
V_8 -> V_23 = V_6 -> V_23 ;
V_8 -> V_28 = 0 ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
V_8 -> V_25 [ V_19 ] . V_26 = F_2 ( V_6 -> V_25 [ V_19 ] . V_26 ) ;
V_8 -> V_25 [ V_19 ] . V_27 = F_2 ( V_6 -> V_25 [ V_19 ] . V_27 ) ;
}
return;
}
V_4 -> V_9 . V_10 . V_21 = F_8 ( V_6 -> V_21 ) ;
V_4 -> V_9 . V_10 . V_22 = F_8 ( V_6 -> V_22 ) ;
V_4 -> V_9 . V_10 . V_11 = F_2 ( V_6 -> V_11 ) ;
V_4 -> V_9 . V_15 = F_2 ( V_6 -> V_15 ) ;
V_4 -> V_9 . V_16 = F_2 ( V_6 -> V_16 ) ;
F_4 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_9 . V_23 = V_6 -> V_23 ;
V_4 -> V_9 . V_28 = 0 ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
V_4 -> V_9 . V_25 [ V_19 ] . V_26 = F_2 ( V_6 -> V_25 [ V_19 ] . V_26 ) ;
V_4 -> V_9 . V_25 [ V_19 ] . V_27 = F_2 ( V_6 -> V_25 [ V_19 ] . V_27 ) ;
}
}
static bool
F_9 (
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
struct V_5 * V_35 = V_30 -> V_36 ;
struct V_3 V_37 ;
F_5 ( V_32 -> V_38 , & V_37 , V_35 ) ;
if ( F_10 ( & V_32 -> V_39 ) ) {
struct V_40 * V_8 = V_30 -> V_36 ;
if ( V_37 . V_11 != V_12 )
return false ;
if ( ! F_11 ( & V_8 -> V_10 . V_41 , & V_32 -> V_39 . V_42 ) )
return false ;
if ( F_12 ( V_8 -> V_10 . V_43 ) != V_30 -> V_44 )
return false ;
if ( ! F_13 ( V_32 , F_12 ( V_8 -> V_10 . V_45 ) ) )
return false ;
} else {
if ( V_37 . V_11 != V_20 )
return false ;
}
if ( V_37 . V_15 == 0 )
return false ;
return true ;
}
static void
F_14 (
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
struct V_46 * V_47 = V_30 -> V_48 ;
struct V_7 * V_8 = V_30 -> V_36 ;
if ( ! F_9 ( V_30 ) ) {
F_15 ( V_30 , - V_49 ) ;
F_16 ( V_30 ) ;
return;
}
if ( ! F_10 ( & V_32 -> V_39 ) )
return;
if ( V_47 )
V_8 -> V_10 . V_45 = F_17 ( V_47 -> V_50 . V_51 ) ;
F_18 ( V_30 , V_52 ) ;
}
static void
F_19 (
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
if ( F_10 ( & V_32 -> V_39 ) &&
! F_20 ( V_30 , V_52 ) )
F_15 ( V_30 , - V_53 ) ;
else if ( ! F_9 ( V_30 ) )
F_15 ( V_30 , - V_49 ) ;
if ( V_30 -> V_54 )
F_16 ( V_30 ) ;
}
int
F_21 (
struct V_55 * V_56 ,
struct V_57 * V_58 ,
T_2 V_59 ,
T_3 V_60 ,
struct V_29 * * V_61 )
{
int V_62 ;
V_62 = F_22 ( V_56 , V_58 , V_59 , V_60 , V_61 ,
V_63 , & V_64 ) ;
if ( ! V_62 && V_56 )
F_23 ( V_56 , * V_61 , V_65 ) ;
return V_62 ;
}
STATIC int
F_24 ( int V_66 , int V_67 )
{
return F_25 ( V_67 ) == F_26 ( V_66 ) ;
}
int
F_27 ( T_4 * V_58 , int V_68 )
{
int V_69 ;
int V_70 ;
int V_71 ;
int V_72 ;
T_5 * V_32 = V_58 -> V_73 ;
V_69 = ( F_28 ( V_32 , V_58 -> V_74 . V_75 ) - V_68 ) >> 3 ;
switch ( V_58 -> V_74 . V_76 ) {
case V_77 :
V_70 = F_29 ( sizeof( V_78 ) , 8 ) >> 3 ;
return ( V_69 >= V_70 ) ? V_70 : 0 ;
case V_79 :
V_70 = F_29 ( sizeof( V_80 ) , 8 ) >> 3 ;
return ( V_69 >= V_70 ) ? V_70 : 0 ;
}
if ( V_68 <= F_30 ( V_58 ) )
return V_58 -> V_74 . V_81 ;
if ( ! ( V_32 -> V_82 & V_83 ) )
return 0 ;
V_72 = V_58 -> V_84 . V_85 ;
switch ( V_58 -> V_74 . V_76 ) {
case V_86 :
if ( ! V_58 -> V_74 . V_81 && V_58 -> V_84 . V_85 >
F_31 ( V_58 ) )
V_72 = F_32 ( V_87 ) ;
break;
case V_88 :
if ( V_58 -> V_74 . V_81 ) {
if ( V_69 < V_58 -> V_74 . V_81 )
return 0 ;
return V_58 -> V_74 . V_81 ;
}
V_72 = F_33 ( V_32 , V_58 -> V_84 . V_89 ) ;
break;
}
V_70 = F_34 ( V_72 , F_32 ( V_87 ) ) ;
V_70 = F_29 ( V_70 , 8 ) >> 3 ;
V_71 = F_28 ( V_32 , V_58 -> V_74 . V_75 ) -
F_32 ( V_90 ) ;
V_71 = V_71 >> 3 ;
if ( V_69 >= V_71 )
return V_71 ;
if ( V_69 >= V_70 )
return V_69 ;
return 0 ;
}
STATIC void
F_35 ( T_5 * V_32 , T_6 * V_56 )
{
if ( ( V_32 -> V_82 & V_83 ) &&
! ( F_36 ( & V_32 -> V_39 ) ) ) {
F_37 ( & V_32 -> V_91 ) ;
if ( ! F_36 ( & V_32 -> V_39 ) ) {
F_38 ( & V_32 -> V_39 ) ;
F_39 ( & V_32 -> V_91 ) ;
F_40 ( V_56 ) ;
} else
F_39 ( & V_32 -> V_91 ) ;
}
}
void
F_41 ( T_7 * args )
{
T_8 * V_9 ;
T_4 * V_58 ;
T_9 * V_92 ;
F_42 ( args ) ;
V_58 = args -> V_58 ;
ASSERT ( V_58 != NULL ) ;
V_92 = V_58 -> V_93 ;
ASSERT ( V_92 != NULL ) ;
ASSERT ( V_92 -> V_85 == 0 ) ;
if ( V_58 -> V_74 . V_94 == V_86 ) {
V_92 -> V_95 &= ~ V_96 ;
V_58 -> V_74 . V_94 = V_97 ;
V_92 -> V_95 |= V_98 ;
} else {
ASSERT ( V_92 -> V_95 & V_98 ) ;
}
F_43 ( V_58 , sizeof( * V_9 ) , V_63 ) ;
V_9 = ( T_8 * ) V_92 -> V_99 . V_100 ;
V_9 -> V_15 = 0 ;
V_9 -> V_101 = F_2 ( sizeof( * V_9 ) ) ;
F_44 ( args -> V_102 , V_58 , V_103 | V_104 ) ;
}
void
F_45 ( T_7 * args , int V_105 )
{
T_10 * V_106 ;
T_11 * V_107 ;
int V_19 , V_69 , V_27 ;
T_5 * V_32 ;
T_4 * V_58 ;
T_9 * V_92 ;
F_46 ( args ) ;
V_58 = args -> V_58 ;
V_32 = V_58 -> V_73 ;
V_58 -> V_74 . V_81 = V_105 ;
V_92 = V_58 -> V_93 ;
ASSERT ( V_92 -> V_95 & V_98 ) ;
V_106 = ( T_10 * ) V_92 -> V_99 . V_100 ;
V_107 = & V_106 -> V_108 [ 0 ] ;
for ( V_19 = 0 ; V_19 < V_106 -> V_9 . V_15 ; V_107 = F_47 ( V_107 ) , V_19 ++ ) {
#ifdef F_48
if ( V_107 -> V_109 != args -> V_109 )
continue;
if ( memcmp ( args -> V_110 , V_107 -> V_111 , args -> V_109 ) != 0 )
continue;
if ( ! F_24 ( args -> V_112 , V_107 -> V_112 ) )
continue;
ASSERT ( 0 ) ;
#endif
}
V_69 = ( char * ) V_107 - ( char * ) V_106 ;
V_27 = F_49 ( args -> V_109 , args -> V_113 ) ;
F_43 ( V_58 , V_27 , V_63 ) ;
V_106 = ( T_10 * ) V_92 -> V_99 . V_100 ;
V_107 = ( T_11 * ) ( ( char * ) V_106 + V_69 ) ;
V_107 -> V_109 = args -> V_109 ;
V_107 -> V_113 = args -> V_113 ;
V_107 -> V_112 = F_26 ( args -> V_112 ) ;
memcpy ( V_107 -> V_111 , args -> V_110 , args -> V_109 ) ;
memcpy ( & V_107 -> V_111 [ args -> V_109 ] , args -> V_114 , args -> V_113 ) ;
V_106 -> V_9 . V_15 ++ ;
F_50 ( & V_106 -> V_9 . V_101 , V_27 ) ;
F_44 ( args -> V_102 , V_58 , V_103 | V_104 ) ;
F_35 ( V_32 , args -> V_102 ) ;
}
void
F_51 (
struct V_57 * V_115 ,
struct V_55 * V_56 )
{
F_52 ( V_115 , V_63 ) ;
V_115 -> V_74 . V_81 = 0 ;
V_115 -> V_74 . V_94 = V_86 ;
ASSERT ( V_115 -> V_74 . V_116 == 0 ) ;
ASSERT ( V_115 -> V_93 == NULL ) ;
F_44 ( V_56 , V_115 , V_103 ) ;
}
int
F_53 ( T_7 * args )
{
T_10 * V_106 ;
T_11 * V_107 ;
int V_26 , V_27 = 0 , V_117 , V_101 , V_19 ;
T_5 * V_32 ;
T_4 * V_58 ;
F_54 ( args ) ;
V_58 = args -> V_58 ;
V_32 = V_58 -> V_73 ;
V_26 = sizeof( T_8 ) ;
V_106 = ( T_10 * ) V_58 -> V_93 -> V_99 . V_100 ;
V_107 = & V_106 -> V_108 [ 0 ] ;
V_117 = V_106 -> V_9 . V_15 ;
for ( V_19 = 0 ; V_19 < V_117 ; V_107 = F_47 ( V_107 ) ,
V_26 += V_27 , V_19 ++ ) {
V_27 = F_55 ( V_107 ) ;
if ( V_107 -> V_109 != args -> V_109 )
continue;
if ( memcmp ( V_107 -> V_111 , args -> V_110 , args -> V_109 ) != 0 )
continue;
if ( ! F_24 ( args -> V_112 , V_107 -> V_112 ) )
continue;
break;
}
if ( V_19 == V_117 )
return - V_118 ;
V_117 = V_26 + V_27 ;
V_101 = F_3 ( V_106 -> V_9 . V_101 ) ;
if ( V_117 != V_101 )
memmove ( & ( ( char * ) V_106 ) [ V_26 ] , & ( ( char * ) V_106 ) [ V_117 ] , V_101 - V_117 ) ;
V_106 -> V_9 . V_15 -- ;
F_50 ( & V_106 -> V_9 . V_101 , - V_27 ) ;
V_101 -= V_27 ;
if ( V_101 == sizeof( T_8 ) &&
( V_32 -> V_82 & V_83 ) &&
( V_58 -> V_74 . V_76 != V_88 ) &&
! ( args -> V_119 & V_120 ) ) {
F_51 ( V_58 , args -> V_102 ) ;
} else {
F_43 ( V_58 , - V_27 , V_63 ) ;
V_58 -> V_74 . V_81 = F_27 ( V_58 , V_101 ) ;
ASSERT ( V_58 -> V_74 . V_81 ) ;
ASSERT ( V_101 > sizeof( T_8 ) ||
( args -> V_119 & V_120 ) ||
! ( V_32 -> V_82 & V_83 ) ||
V_58 -> V_74 . V_76 == V_88 ) ;
F_44 ( args -> V_102 , V_58 ,
V_103 | V_104 ) ;
}
F_35 ( V_32 , args -> V_102 ) ;
return 0 ;
}
int
F_56 ( T_7 * args )
{
T_10 * V_106 ;
T_11 * V_107 ;
int V_19 ;
T_9 * V_92 ;
F_57 ( args ) ;
V_92 = args -> V_58 -> V_93 ;
ASSERT ( V_92 -> V_95 & V_98 ) ;
V_106 = ( T_10 * ) V_92 -> V_99 . V_100 ;
V_107 = & V_106 -> V_108 [ 0 ] ;
for ( V_19 = 0 ; V_19 < V_106 -> V_9 . V_15 ;
V_107 = F_47 ( V_107 ) , V_19 ++ ) {
if ( V_107 -> V_109 != args -> V_109 )
continue;
if ( memcmp ( args -> V_110 , V_107 -> V_111 , args -> V_109 ) != 0 )
continue;
if ( ! F_24 ( args -> V_112 , V_107 -> V_112 ) )
continue;
return - V_121 ;
}
return - V_118 ;
}
int
F_58 ( T_7 * args )
{
T_10 * V_106 ;
T_11 * V_107 ;
int V_19 ;
ASSERT ( args -> V_58 -> V_93 -> V_95 == V_98 ) ;
V_106 = ( T_10 * ) args -> V_58 -> V_93 -> V_99 . V_100 ;
V_107 = & V_106 -> V_108 [ 0 ] ;
for ( V_19 = 0 ; V_19 < V_106 -> V_9 . V_15 ;
V_107 = F_47 ( V_107 ) , V_19 ++ ) {
if ( V_107 -> V_109 != args -> V_109 )
continue;
if ( memcmp ( args -> V_110 , V_107 -> V_111 , args -> V_109 ) != 0 )
continue;
if ( ! F_24 ( args -> V_112 , V_107 -> V_112 ) )
continue;
if ( args -> V_112 & V_122 ) {
args -> V_113 = V_107 -> V_113 ;
return - V_121 ;
}
if ( args -> V_113 < V_107 -> V_113 ) {
args -> V_113 = V_107 -> V_113 ;
return - V_123 ;
}
args -> V_113 = V_107 -> V_113 ;
memcpy ( args -> V_114 , & V_107 -> V_111 [ args -> V_109 ] ,
args -> V_113 ) ;
return - V_121 ;
}
return - V_118 ;
}
int
F_59 ( T_7 * args )
{
T_4 * V_58 ;
T_10 * V_106 ;
T_11 * V_107 ;
T_7 V_124 ;
char * V_125 ;
int error , V_19 , V_27 ;
T_2 V_43 ;
struct V_29 * V_30 ;
T_9 * V_92 ;
F_60 ( args ) ;
V_58 = args -> V_58 ;
V_92 = V_58 -> V_93 ;
V_106 = ( T_10 * ) V_92 -> V_99 . V_100 ;
V_27 = F_3 ( V_106 -> V_9 . V_101 ) ;
V_125 = F_61 ( V_27 , V_126 ) ;
ASSERT ( V_125 != NULL ) ;
memcpy ( V_125 , V_92 -> V_99 . V_100 , V_27 ) ;
V_106 = ( T_10 * ) V_125 ;
F_43 ( V_58 , - V_27 , V_63 ) ;
F_62 ( V_58 , V_63 ) ;
V_30 = NULL ;
error = F_63 ( args , & V_43 ) ;
if ( error ) {
if ( error == - V_127 )
goto V_128;
F_43 ( V_58 , V_27 , V_63 ) ;
memcpy ( V_92 -> V_99 . V_100 , V_125 , V_27 ) ;
goto V_128;
}
ASSERT ( V_43 == 0 ) ;
error = F_64 ( args , V_43 , & V_30 ) ;
if ( error ) {
error = F_65 ( args , 0 , V_30 ) ;
V_30 = NULL ;
if ( error )
goto V_128;
F_43 ( V_58 , V_27 , V_63 ) ;
memcpy ( V_92 -> V_99 . V_100 , V_125 , V_27 ) ;
goto V_128;
}
memset ( ( char * ) & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_58 = V_58 ;
V_124 . V_2 = args -> V_2 ;
V_124 . V_129 = args -> V_129 ;
V_124 . V_130 = args -> V_130 ;
V_124 . V_131 = args -> V_131 ;
V_124 . V_132 = V_63 ;
V_124 . V_102 = args -> V_102 ;
V_124 . V_119 = V_133 ;
V_107 = & V_106 -> V_108 [ 0 ] ;
for ( V_19 = 0 ; V_19 < V_106 -> V_9 . V_15 ; V_19 ++ ) {
V_124 . V_110 = V_107 -> V_111 ;
V_124 . V_109 = V_107 -> V_109 ;
V_124 . V_114 = & V_107 -> V_111 [ V_124 . V_109 ] ;
V_124 . V_113 = V_107 -> V_113 ;
V_124 . V_134 = F_66 ( V_107 -> V_111 ,
V_107 -> V_109 ) ;
V_124 . V_112 = F_67 ( V_107 -> V_112 ) ;
error = F_68 ( V_30 , & V_124 ) ;
ASSERT ( error == - V_118 ) ;
error = F_69 ( V_30 , & V_124 ) ;
ASSERT ( error != - V_135 ) ;
if ( error )
goto V_128;
V_107 = F_47 ( V_107 ) ;
}
error = 0 ;
V_128:
F_70 ( V_125 ) ;
return error ;
}
int
F_71 (
struct V_29 * V_30 ,
struct V_57 * V_58 )
{
struct V_5 * V_35 ;
struct V_136 * V_137 ;
T_12 * V_138 ;
struct V_3 V_139 ;
int V_68 ;
int V_19 ;
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
V_35 = V_30 -> V_36 ;
F_5 ( V_32 -> V_38 , & V_139 , V_35 ) ;
V_137 = F_72 ( V_35 ) ;
V_68 = sizeof( struct V_140 ) ;
for ( V_19 = 0 ; V_19 < V_139 . V_15 ; V_137 ++ , V_19 ++ ) {
if ( V_137 -> V_112 & V_141 )
continue;
if ( ! ( V_137 -> V_112 & V_142 ) )
return 0 ;
V_138 = F_73 ( V_35 , V_19 ) ;
if ( V_138 -> V_109 >= V_143 )
return 0 ;
if ( F_3 ( V_138 -> V_113 ) >= V_143 )
return 0 ;
V_68 += sizeof( struct V_144 ) - 1
+ V_138 -> V_109
+ F_3 ( V_138 -> V_113 ) ;
}
if ( ( V_58 -> V_73 -> V_82 & V_83 ) &&
( V_58 -> V_74 . V_76 != V_88 ) &&
( V_68 == sizeof( struct V_140 ) ) )
return - 1 ;
return F_27 ( V_58 , V_68 ) ;
}
int
F_74 (
struct V_29 * V_30 ,
struct V_145 * args ,
int V_105 )
{
struct V_5 * V_35 ;
struct V_3 V_37 ;
struct V_136 * V_137 ;
struct V_146 * V_138 ;
struct V_145 V_124 ;
struct V_57 * V_58 = args -> V_58 ;
char * V_125 ;
int error ;
int V_19 ;
F_75 ( args ) ;
V_125 = F_61 ( args -> V_2 -> V_17 , V_126 ) ;
if ( ! V_125 )
return - V_147 ;
memcpy ( V_125 , V_30 -> V_36 , args -> V_2 -> V_17 ) ;
V_35 = ( V_148 * ) V_125 ;
F_5 ( args -> V_2 , & V_37 , V_35 ) ;
V_137 = F_72 ( V_35 ) ;
memset ( V_30 -> V_36 , 0 , args -> V_2 -> V_17 ) ;
error = F_65 ( args , 0 , V_30 ) ;
if ( error )
goto V_128;
if ( V_105 == - 1 ) {
ASSERT ( V_58 -> V_73 -> V_82 & V_83 ) ;
ASSERT ( V_58 -> V_74 . V_76 != V_88 ) ;
F_51 ( V_58 , args -> V_102 ) ;
goto V_128;
}
F_41 ( args ) ;
memset ( ( char * ) & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_2 = args -> V_2 ;
V_124 . V_58 = V_58 ;
V_124 . V_129 = args -> V_129 ;
V_124 . V_130 = args -> V_130 ;
V_124 . V_131 = args -> V_131 ;
V_124 . V_132 = V_63 ;
V_124 . V_102 = args -> V_102 ;
V_124 . V_119 = V_133 ;
for ( V_19 = 0 ; V_19 < V_37 . V_15 ; V_137 ++ , V_19 ++ ) {
if ( V_137 -> V_112 & V_141 )
continue;
if ( ! V_137 -> V_149 )
continue;
ASSERT ( V_137 -> V_112 & V_142 ) ;
V_138 = F_73 ( V_35 , V_19 ) ;
V_124 . V_110 = V_138 -> V_111 ;
V_124 . V_109 = V_138 -> V_109 ;
V_124 . V_114 = & V_138 -> V_111 [ V_124 . V_109 ] ;
V_124 . V_113 = F_3 ( V_138 -> V_113 ) ;
V_124 . V_134 = F_6 ( V_137 -> V_134 ) ;
V_124 . V_112 = F_67 ( V_137 -> V_112 ) ;
F_45 ( & V_124 , V_105 ) ;
}
error = 0 ;
V_128:
F_70 ( V_125 ) ;
return error ;
}
int
F_76 (
struct V_145 * args )
{
struct V_5 * V_35 ;
struct V_3 V_150 ;
struct V_136 * V_151 ;
struct V_152 * V_153 ;
struct V_154 V_155 ;
struct V_156 * V_157 ;
struct V_57 * V_58 = args -> V_58 ;
struct V_31 * V_32 = V_58 -> V_73 ;
struct V_29 * V_158 = NULL ;
struct V_29 * V_159 = NULL ;
T_2 V_43 ;
int error ;
F_77 ( args ) ;
error = F_63 ( args , & V_43 ) ;
if ( error )
goto V_128;
error = F_21 ( args -> V_102 , V_58 , 0 , - 1 , & V_158 ) ;
if ( error )
goto V_128;
error = F_78 ( args -> V_102 , V_58 , V_43 , - 1 , & V_159 , V_63 ) ;
if ( error )
goto V_128;
F_23 ( args -> V_102 , V_159 , V_65 ) ;
V_159 -> V_160 = V_158 -> V_160 ;
memcpy ( V_159 -> V_36 , V_158 -> V_36 , args -> V_2 -> V_17 ) ;
if ( F_10 ( & V_32 -> V_39 ) ) {
struct V_161 * V_8 = V_159 -> V_36 ;
V_8 -> V_43 = F_17 ( V_159 -> V_44 ) ;
}
F_79 ( args -> V_102 , V_159 , 0 , args -> V_2 -> V_17 - 1 ) ;
error = F_80 ( args , 0 , 1 , & V_158 , V_63 ) ;
if ( error )
goto V_128;
V_157 = V_158 -> V_36 ;
V_58 -> V_162 -> V_163 ( & V_155 , V_157 ) ;
V_153 = V_58 -> V_162 -> V_164 ( V_157 ) ;
V_35 = V_159 -> V_36 ;
F_5 ( args -> V_2 , & V_150 , V_35 ) ;
V_151 = F_72 ( V_35 ) ;
V_153 [ 0 ] . V_134 = V_151 [ V_150 . V_15 - 1 ] . V_134 ;
V_153 [ 0 ] . V_165 = F_8 ( V_43 ) ;
V_155 . V_15 = 1 ;
V_58 -> V_162 -> V_166 ( V_157 , & V_155 ) ;
F_79 ( args -> V_102 , V_158 , 0 , args -> V_2 -> V_17 - 1 ) ;
error = 0 ;
V_128:
return error ;
}
STATIC int
F_64 (
struct V_145 * args ,
T_2 V_43 ,
struct V_29 * * V_61 )
{
struct V_5 * V_35 ;
struct V_3 V_37 ;
struct V_57 * V_58 = args -> V_58 ;
struct V_31 * V_32 = V_58 -> V_73 ;
struct V_29 * V_30 ;
int error ;
F_81 ( args ) ;
error = F_78 ( args -> V_102 , args -> V_58 , V_43 , - 1 , & V_30 ,
V_63 ) ;
if ( error )
return error ;
V_30 -> V_160 = & V_64 ;
F_23 ( args -> V_102 , V_30 , V_65 ) ;
V_35 = V_30 -> V_36 ;
memset ( V_35 , 0 , args -> V_2 -> V_17 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_13 = args -> V_2 -> V_17 ;
if ( F_10 ( & V_32 -> V_39 ) ) {
struct V_161 * V_8 = V_30 -> V_36 ;
V_37 . V_11 = V_12 ;
V_8 -> V_43 = F_17 ( V_30 -> V_44 ) ;
V_8 -> V_167 = F_17 ( V_58 -> V_168 ) ;
F_82 ( & V_8 -> V_41 , & V_32 -> V_39 . V_42 ) ;
V_37 . V_25 [ 0 ] . V_26 = sizeof( struct V_7 ) ;
} else {
V_37 . V_11 = V_20 ;
V_37 . V_25 [ 0 ] . V_26 = sizeof( struct V_169 ) ;
}
V_37 . V_25 [ 0 ] . V_27 = V_37 . V_13 - V_37 . V_25 [ 0 ] . V_26 ;
F_7 ( args -> V_2 , V_35 , & V_37 ) ;
F_79 ( args -> V_102 , V_30 , 0 , args -> V_2 -> V_17 - 1 ) ;
* V_61 = V_30 ;
return 0 ;
}
int
F_83 (
struct V_170 * V_171 ,
struct V_172 * V_173 ,
struct V_172 * V_174 )
{
T_2 V_43 ;
int error ;
F_84 ( V_171 -> args ) ;
ASSERT ( V_173 -> V_11 == V_20 ) ;
error = F_63 ( V_171 -> args , & V_43 ) ;
if ( error )
return error ;
error = F_64 ( V_171 -> args , V_43 , & V_174 -> V_30 ) ;
if ( error )
return error ;
V_174 -> V_43 = V_43 ;
V_174 -> V_11 = V_20 ;
F_85 ( V_171 , V_173 , V_174 ) ;
error = F_86 ( V_171 , V_173 , V_174 ) ;
if ( error )
return error ;
if ( V_171 -> V_175 ) {
F_87 ( V_171 -> args ) ;
error = F_69 ( V_173 -> V_30 , V_171 -> args ) ;
} else {
F_88 ( V_171 -> args ) ;
error = F_69 ( V_174 -> V_30 , V_171 -> args ) ;
}
V_173 -> V_134 = F_89 ( V_173 -> V_30 , NULL ) ;
V_174 -> V_134 = F_89 ( V_174 -> V_30 , NULL ) ;
return error ;
}
int
F_69 (
struct V_29 * V_30 ,
struct V_145 * args )
{
struct V_5 * V_35 ;
struct V_3 V_37 ;
int V_176 ;
int V_177 ;
int V_178 ;
int V_179 ;
int V_19 ;
F_90 ( args ) ;
V_35 = V_30 -> V_36 ;
F_5 ( args -> V_2 , & V_37 , V_35 ) ;
ASSERT ( args -> V_180 >= 0 && args -> V_180 <= V_37 . V_15 ) ;
V_177 = F_91 ( args , NULL ) ;
V_176 = ( V_37 . V_15 + 1 ) * sizeof( V_181 )
+ F_92 ( V_35 ) ;
for ( V_178 = 0 , V_19 = V_24 - 1 ; V_19 >= 0 ; V_19 -- ) {
if ( V_176 > V_37 . V_13 ) {
V_178 += V_37 . V_25 [ V_19 ] . V_27 ;
continue;
}
if ( ! V_37 . V_25 [ V_19 ] . V_27 )
continue;
V_179 = V_177 ;
if ( V_37 . V_25 [ V_19 ] . V_26 < V_37 . V_13 )
V_179 += sizeof( V_181 ) ;
if ( V_37 . V_25 [ V_19 ] . V_27 >= V_179 ) {
V_179 = F_93 ( V_30 , & V_37 , args , V_19 ) ;
goto V_182;
}
V_178 += V_37 . V_25 [ V_19 ] . V_27 ;
}
if ( ! V_37 . V_23 && V_178 < V_177 )
return - V_135 ;
F_94 ( args , & V_37 , V_30 ) ;
if ( V_37 . V_25 [ 0 ] . V_27 < ( V_177 + sizeof( V_181 ) ) ) {
V_179 = - V_135 ;
goto V_182;
}
V_179 = F_93 ( V_30 , & V_37 , args , 0 ) ;
V_182:
F_7 ( args -> V_2 , V_35 , & V_37 ) ;
F_79 ( args -> V_102 , V_30 ,
F_95 ( V_35 , & V_35 -> V_9 ,
F_92 ( V_35 ) ) ) ;
return V_179 ;
}
STATIC int
F_93 (
struct V_29 * V_30 ,
struct V_3 * V_37 ,
struct V_145 * args ,
int V_183 )
{
struct V_5 * V_35 ;
struct V_136 * V_137 ;
struct V_146 * V_138 ;
struct V_184 * V_185 ;
struct V_31 * V_32 ;
int V_179 ;
int V_19 ;
F_96 ( args ) ;
V_35 = V_30 -> V_36 ;
ASSERT ( V_183 >= 0 && V_183 < V_24 ) ;
ASSERT ( args -> V_180 >= 0 && args -> V_180 <= V_37 -> V_15 ) ;
V_137 = & F_72 ( V_35 ) [ args -> V_180 ] ;
if ( args -> V_180 < V_37 -> V_15 ) {
V_179 = V_37 -> V_15 - args -> V_180 ;
V_179 *= sizeof( V_181 ) ;
memmove ( V_137 + 1 , V_137 , V_179 ) ;
F_79 ( args -> V_102 , V_30 ,
F_95 ( V_35 , V_137 , V_179 + sizeof( * V_137 ) ) ) ;
}
V_37 -> V_15 ++ ;
V_32 = args -> V_102 -> V_186 ;
ASSERT ( V_37 -> V_25 [ V_183 ] . V_26 < args -> V_2 -> V_17 ) ;
ASSERT ( ( V_37 -> V_25 [ V_183 ] . V_26 & 0x3 ) == 0 ) ;
ASSERT ( V_37 -> V_25 [ V_183 ] . V_27 >=
F_91 ( args , NULL ) ) ;
ASSERT ( V_37 -> V_25 [ V_183 ] . V_27 < args -> V_2 -> V_17 ) ;
ASSERT ( ( V_37 -> V_25 [ V_183 ] . V_27 & 0x3 ) == 0 ) ;
V_37 -> V_25 [ V_183 ] . V_27 -= F_91 ( args , & V_179 ) ;
V_137 -> V_149 = F_2 ( V_37 -> V_25 [ V_183 ] . V_26 +
V_37 -> V_25 [ V_183 ] . V_27 ) ;
V_137 -> V_134 = F_8 ( args -> V_134 ) ;
V_137 -> V_112 = V_179 ? V_142 : 0 ;
V_137 -> V_112 |= F_26 ( args -> V_112 ) ;
if ( args -> V_119 & V_187 ) {
V_137 -> V_112 |= V_141 ;
if ( ( args -> V_188 == args -> V_43 ) &&
( args -> V_189 <= args -> V_180 ) ) {
args -> V_189 ++ ;
}
}
F_79 ( args -> V_102 , V_30 ,
F_95 ( V_35 , V_137 , sizeof( * V_137 ) ) ) ;
ASSERT ( ( args -> V_180 == 0 ) ||
( F_6 ( V_137 -> V_134 ) >= F_6 ( ( V_137 - 1 ) -> V_134 ) ) ) ;
ASSERT ( ( args -> V_180 == V_37 -> V_15 - 1 ) ||
( F_6 ( V_137 -> V_134 ) <= F_6 ( ( V_137 + 1 ) -> V_134 ) ) ) ;
if ( V_137 -> V_112 & V_142 ) {
V_138 = F_73 ( V_35 , args -> V_180 ) ;
V_138 -> V_109 = args -> V_109 ;
V_138 -> V_113 = F_2 ( args -> V_113 ) ;
memcpy ( ( char * ) V_138 -> V_111 , args -> V_110 , args -> V_109 ) ;
memcpy ( ( char * ) & V_138 -> V_111 [ args -> V_109 ] , args -> V_114 ,
F_3 ( V_138 -> V_113 ) ) ;
} else {
V_185 = F_97 ( V_35 , args -> V_180 ) ;
V_185 -> V_109 = args -> V_109 ;
memcpy ( ( char * ) V_185 -> V_110 , args -> V_110 , args -> V_109 ) ;
V_137 -> V_112 |= V_141 ;
V_185 -> V_113 = 0 ;
V_185 -> V_190 = 0 ;
args -> V_191 = 1 ;
args -> V_192 = F_98 ( V_32 , args -> V_113 ) ;
args -> V_193 = args -> V_113 ;
}
F_79 ( args -> V_102 , V_30 ,
F_95 ( V_35 , F_99 ( V_35 , args -> V_180 ) ,
F_100 ( V_35 , args -> V_180 ) ) ) ;
if ( F_3 ( V_137 -> V_149 ) < V_37 -> V_13 )
V_37 -> V_13 = F_3 ( V_137 -> V_149 ) ;
ASSERT ( V_37 -> V_13 >= V_37 -> V_15 * sizeof( V_181 )
+ F_92 ( V_35 ) ) ;
V_179 = ( V_37 -> V_15 - 1 ) * sizeof( V_181 )
+ F_92 ( V_35 ) ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
if ( V_37 -> V_25 [ V_19 ] . V_26 == V_179 ) {
V_37 -> V_25 [ V_19 ] . V_26 += sizeof( V_181 ) ;
V_37 -> V_25 [ V_19 ] . V_27 -= sizeof( V_181 ) ;
}
}
V_37 -> V_16 += F_100 ( V_35 , args -> V_180 ) ;
return 0 ;
}
STATIC void
F_94 (
struct V_145 * args ,
struct V_3 * V_194 ,
struct V_29 * V_30 )
{
struct V_5 * V_195 ;
struct V_5 * V_196 ;
struct V_3 V_197 ;
struct V_55 * V_102 = args -> V_102 ;
char * V_125 ;
F_101 ( args ) ;
V_125 = F_61 ( args -> V_2 -> V_17 , V_126 ) ;
memcpy ( V_125 , V_30 -> V_36 , args -> V_2 -> V_17 ) ;
memset ( V_30 -> V_36 , 0 , args -> V_2 -> V_17 ) ;
V_195 = ( V_148 * ) V_125 ;
V_196 = V_30 -> V_36 ;
memcpy ( V_30 -> V_36 , V_125 , F_92 ( V_195 ) ) ;
V_197 = * V_194 ;
V_194 -> V_13 = args -> V_2 -> V_17 ;
V_194 -> V_16 = 0 ;
V_194 -> V_15 = 0 ;
V_194 -> V_23 = 0 ;
V_194 -> V_25 [ 0 ] . V_26 = F_92 ( V_195 ) ;
V_194 -> V_25 [ 0 ] . V_27 = V_194 -> V_13 -
V_194 -> V_25 [ 0 ] . V_26 ;
F_7 ( args -> V_2 , V_196 , V_194 ) ;
F_102 ( args , V_195 , & V_197 , 0 ,
V_196 , V_194 , 0 , V_197 . V_15 ) ;
F_79 ( V_102 , V_30 , 0 , args -> V_2 -> V_17 - 1 ) ;
F_70 ( V_125 ) ;
}
static int
F_103 (
struct V_29 * V_198 ,
struct V_3 * V_199 ,
struct V_29 * V_200 ,
struct V_3 * V_201 )
{
struct V_136 * V_202 ;
struct V_136 * V_203 ;
V_202 = F_72 ( V_198 -> V_36 ) ;
V_203 = F_72 ( V_200 -> V_36 ) ;
if ( V_199 -> V_15 > 0 && V_201 -> V_15 > 0 &&
( ( F_6 ( V_203 [ 0 ] . V_134 ) <
F_6 ( V_202 [ 0 ] . V_134 ) ) ||
( F_6 ( V_203 [ V_201 -> V_15 - 1 ] . V_134 ) <
F_6 ( V_202 [ V_199 -> V_15 - 1 ] . V_134 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_104 (
struct V_29 * V_198 ,
struct V_29 * V_200 )
{
struct V_3 V_204 ;
struct V_3 V_205 ;
struct V_31 * V_32 = V_198 -> V_33 -> V_34 ;
F_5 ( V_32 -> V_38 , & V_204 , V_198 -> V_36 ) ;
F_5 ( V_32 -> V_38 , & V_205 , V_200 -> V_36 ) ;
return F_103 ( V_198 , & V_204 , V_200 , & V_205 ) ;
}
STATIC void
F_85 (
struct V_170 * V_171 ,
struct V_172 * V_206 ,
struct V_172 * V_207 )
{
struct V_145 * args ;
struct V_5 * V_208 ;
struct V_5 * V_209 ;
struct V_3 V_204 ;
struct V_3 V_205 ;
struct V_136 * V_202 ;
struct V_136 * V_203 ;
int V_15 ;
int V_210 ;
int V_211 ;
int V_212 ;
int V_213 ;
ASSERT ( V_206 -> V_11 == V_20 ) ;
ASSERT ( V_207 -> V_11 == V_20 ) ;
V_208 = V_206 -> V_30 -> V_36 ;
V_209 = V_207 -> V_30 -> V_36 ;
F_5 ( V_171 -> args -> V_2 , & V_204 , V_208 ) ;
F_5 ( V_171 -> args -> V_2 , & V_205 , V_209 ) ;
ASSERT ( V_205 . V_15 == 0 ) ;
args = V_171 -> args ;
F_105 ( args ) ;
V_213 = 0 ;
if ( F_103 ( V_206 -> V_30 , & V_204 , V_207 -> V_30 , & V_205 ) ) {
struct V_172 * V_214 ;
struct V_3 V_215 ;
V_214 = V_206 ;
V_206 = V_207 ;
V_207 = V_214 ;
V_215 = V_204 ;
V_204 = V_205 ;
V_205 = V_215 ;
V_208 = V_206 -> V_30 -> V_36 ;
V_209 = V_207 -> V_30 -> V_36 ;
V_213 = 1 ;
}
V_171 -> V_175 = F_106 ( V_171 , V_206 , & V_204 ,
V_207 , & V_205 ,
& V_15 , & V_210 ) ;
if ( V_213 )
V_171 -> V_175 = ! V_171 -> V_175 ;
if ( V_15 < V_204 . V_15 ) {
V_15 = V_204 . V_15 - V_15 ;
V_212 = V_204 . V_16 - V_210 ;
V_212 += V_15 * sizeof( V_181 ) ;
V_211 = V_205 . V_13 - F_92 ( V_208 ) ;
V_211 -= V_205 . V_15 * sizeof( V_181 ) ;
if ( V_212 > V_211 )
F_94 ( args , & V_205 , V_207 -> V_30 ) ;
F_102 ( args , V_208 , & V_204 ,
V_204 . V_15 - V_15 , V_209 , & V_205 , 0 , V_15 ) ;
} else if ( V_15 > V_204 . V_15 ) {
ASSERT ( 0 ) ;
V_15 -= V_204 . V_15 ;
V_212 = V_210 - V_204 . V_16 ;
V_212 += V_15 * sizeof( V_181 ) ;
V_211 = V_204 . V_13 - F_92 ( V_208 ) ;
V_211 -= V_204 . V_15 * sizeof( V_181 ) ;
if ( V_212 > V_211 )
F_94 ( args , & V_204 , V_206 -> V_30 ) ;
F_102 ( args , V_209 , & V_205 , 0 , V_208 , & V_204 ,
V_204 . V_15 , V_15 ) ;
}
F_7 ( V_171 -> args -> V_2 , V_208 , & V_204 ) ;
F_7 ( V_171 -> args -> V_2 , V_209 , & V_205 ) ;
F_79 ( args -> V_102 , V_206 -> V_30 , 0 , args -> V_2 -> V_17 - 1 ) ;
F_79 ( args -> V_102 , V_207 -> V_30 , 0 , args -> V_2 -> V_17 - 1 ) ;
V_202 = F_72 ( V_208 ) ;
V_203 = F_72 ( V_209 ) ;
V_206 -> V_134 = F_6 ( V_202 [ V_204 . V_15 - 1 ] . V_134 ) ;
V_207 -> V_134 = F_6 ( V_203 [ V_205 . V_15 - 1 ] . V_134 ) ;
if ( V_206 -> V_180 > V_204 . V_15 ) {
ASSERT ( V_171 -> V_175 == 0 ) ;
V_207 -> V_180 = V_206 -> V_180 - V_204 . V_15 ;
args -> V_180 = args -> V_189 = V_207 -> V_180 ;
args -> V_43 = args -> V_188 = V_207 -> V_43 ;
} else if ( V_206 -> V_180 == V_204 . V_15 ) {
if ( V_171 -> V_175 ) {
args -> V_180 = V_206 -> V_180 ;
args -> V_43 = V_206 -> V_43 ;
args -> V_189 = 0 ;
args -> V_188 = V_207 -> V_43 ;
} else {
V_207 -> V_180 = V_206 -> V_180 - V_204 . V_15 ;
args -> V_180 = V_207 -> V_180 ;
args -> V_43 = V_207 -> V_43 ;
if ( ! V_171 -> V_216 ) {
args -> V_189 = V_207 -> V_180 ;
args -> V_188 = V_207 -> V_43 ;
}
}
} else {
ASSERT ( V_171 -> V_175 == 1 ) ;
args -> V_180 = args -> V_189 = V_206 -> V_180 ;
args -> V_43 = args -> V_188 = V_206 -> V_43 ;
}
}
STATIC int
F_106 (
struct V_170 * V_171 ,
struct V_172 * V_206 ,
struct V_3 * V_204 ,
struct V_172 * V_207 ,
struct V_3 * V_205 ,
int * V_217 ,
int * V_218 )
{
struct V_5 * V_208 = V_206 -> V_30 -> V_36 ;
struct V_5 * V_209 = V_207 -> V_30 -> V_36 ;
struct V_136 * V_137 ;
int V_15 ;
int V_211 ;
int V_180 ;
int V_210 = 0 ;
int V_219 ;
int V_220 ;
int V_221 = 0 ;
int V_179 ;
V_211 = V_204 -> V_15 + V_205 -> V_15 ;
V_219 = ( V_211 + 1 ) * sizeof( * V_137 ) ;
V_219 += V_204 -> V_16 + V_205 -> V_16 +
F_91 ( V_171 -> args , NULL ) ;
V_219 /= 2 ;
V_220 = V_171 -> args -> V_2 -> V_17 ;
V_137 = F_72 ( V_208 ) ;
for ( V_15 = V_180 = 0 ; V_15 < V_211 ; V_137 ++ , V_180 ++ , V_15 ++ ) {
#define F_107 ( T_13 ) (((A) < 0) ? -(A) : (A))
if ( V_15 == V_206 -> V_180 ) {
V_179 = V_210 + sizeof( * V_137 ) +
F_91 ( V_171 -> args , NULL ) ;
if ( F_107 ( V_219 - V_179 ) > V_220 )
break;
V_220 = F_107 ( V_219 - V_179 ) ;
V_210 = V_179 ;
V_221 = 1 ;
}
if ( V_15 == V_204 -> V_15 ) {
V_208 = V_209 ;
V_137 = F_72 ( V_208 ) ;
V_180 = 0 ;
}
V_179 = V_210 + sizeof( * V_137 ) + F_100 ( V_208 ,
V_180 ) ;
if ( F_107 ( V_219 - V_179 ) > V_220 )
break;
V_220 = F_107 ( V_219 - V_179 ) ;
V_210 = V_179 ;
#undef F_107
}
V_210 -= V_15 * sizeof( * V_137 ) ;
if ( V_221 ) {
V_210 -= sizeof( * V_137 ) +
F_91 ( V_171 -> args , NULL ) ;
}
* V_217 = V_15 ;
* V_218 = V_210 ;
return V_221 ;
}
int
F_108 (
struct V_170 * V_171 ,
int * V_222 )
{
struct V_5 * V_35 ;
struct V_172 * V_223 ;
struct V_3 V_37 ;
struct V_29 * V_30 ;
T_2 V_43 ;
int V_68 ;
int V_224 ;
int error ;
int V_225 ;
int V_19 ;
F_109 ( V_171 -> args ) ;
V_223 = & V_171 -> V_226 . V_223 [ V_171 -> V_226 . V_227 - 1 ] ;
V_35 = V_223 -> V_30 -> V_36 ;
F_5 ( V_171 -> args -> V_2 , & V_37 , V_35 ) ;
V_68 = F_92 ( V_35 ) +
V_37 . V_15 * sizeof( V_181 ) +
V_37 . V_16 ;
if ( V_68 > ( V_171 -> args -> V_2 -> V_17 >> 1 ) ) {
* V_222 = 0 ;
return 0 ;
}
if ( V_37 . V_15 == 0 ) {
V_224 = ( V_37 . V_21 != 0 ) ;
memcpy ( & V_171 -> V_228 , & V_171 -> V_226 , sizeof( V_171 -> V_226 ) ) ;
error = F_110 ( V_171 , & V_171 -> V_228 , V_224 ,
0 , & V_225 ) ;
if ( error )
return error ;
if ( V_225 ) {
* V_222 = 0 ;
} else {
* V_222 = 2 ;
}
return 0 ;
}
V_224 = V_37 . V_21 < V_37 . V_22 ;
for ( V_19 = 0 ; V_19 < 2 ; V_224 = ! V_224 , V_19 ++ ) {
struct V_3 V_205 ;
if ( V_224 )
V_43 = V_37 . V_21 ;
else
V_43 = V_37 . V_22 ;
if ( V_43 == 0 )
continue;
error = F_21 ( V_171 -> args -> V_102 , V_171 -> args -> V_58 ,
V_43 , - 1 , & V_30 ) ;
if ( error )
return error ;
F_5 ( V_171 -> args -> V_2 , & V_205 , V_30 -> V_36 ) ;
V_68 = V_171 -> args -> V_2 -> V_17 -
( V_171 -> args -> V_2 -> V_17 >> 2 ) -
V_37 . V_16 - V_205 . V_16 -
( ( V_37 . V_15 + V_205 . V_15 ) *
sizeof( V_181 ) ) -
F_92 ( V_35 ) ;
F_111 ( V_171 -> args -> V_102 , V_30 ) ;
if ( V_68 >= 0 )
break;
}
if ( V_19 >= 2 ) {
* V_222 = 0 ;
return 0 ;
}
memcpy ( & V_171 -> V_228 , & V_171 -> V_226 , sizeof( V_171 -> V_226 ) ) ;
if ( V_43 < V_223 -> V_43 ) {
error = F_110 ( V_171 , & V_171 -> V_228 , V_224 ,
0 , & V_225 ) ;
} else {
error = F_110 ( V_171 , & V_171 -> V_226 , V_224 ,
0 , & V_225 ) ;
}
if ( error )
return error ;
if ( V_225 ) {
* V_222 = 0 ;
} else {
* V_222 = 1 ;
}
return 0 ;
}
int
F_112 (
struct V_29 * V_30 ,
struct V_145 * args )
{
struct V_5 * V_35 ;
struct V_3 V_37 ;
struct V_136 * V_137 ;
int V_165 ;
int V_229 ;
int V_230 ;
int V_177 ;
int V_176 ;
int V_179 ;
int V_19 ;
F_113 ( args ) ;
V_35 = V_30 -> V_36 ;
F_5 ( args -> V_2 , & V_37 , V_35 ) ;
ASSERT ( V_37 . V_15 > 0 && V_37 . V_15 < args -> V_2 -> V_17 / 8 ) ;
ASSERT ( args -> V_180 >= 0 && args -> V_180 < V_37 . V_15 ) ;
ASSERT ( V_37 . V_13 >= V_37 . V_15 * sizeof( * V_137 ) +
F_92 ( V_35 ) ) ;
V_137 = & F_72 ( V_35 ) [ args -> V_180 ] ;
ASSERT ( F_3 ( V_137 -> V_149 ) >= V_37 . V_13 ) ;
ASSERT ( F_3 ( V_137 -> V_149 ) < args -> V_2 -> V_17 ) ;
V_176 = V_37 . V_15 * sizeof( V_181 )
+ F_92 ( V_35 ) ;
V_179 = V_37 . V_25 [ 0 ] . V_27 ;
V_165 = V_229 = - 1 ;
V_230 = V_24 - 1 ;
V_177 = F_100 ( V_35 , args -> V_180 ) ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
ASSERT ( V_37 . V_25 [ V_19 ] . V_26 < args -> V_2 -> V_17 ) ;
ASSERT ( V_37 . V_25 [ V_19 ] . V_27 < args -> V_2 -> V_17 ) ;
if ( V_37 . V_25 [ V_19 ] . V_26 == V_176 ) {
V_37 . V_25 [ V_19 ] . V_26 -= sizeof( V_181 ) ;
V_37 . V_25 [ V_19 ] . V_27 += sizeof( V_181 ) ;
}
if ( V_37 . V_25 [ V_19 ] . V_26 + V_37 . V_25 [ V_19 ] . V_27 ==
F_3 ( V_137 -> V_149 ) ) {
V_165 = V_19 ;
} else if ( V_37 . V_25 [ V_19 ] . V_26 ==
( F_3 ( V_137 -> V_149 ) + V_177 ) ) {
V_229 = V_19 ;
} else if ( V_37 . V_25 [ V_19 ] . V_27 < V_179 ) {
V_179 = V_37 . V_25 [ V_19 ] . V_27 ;
V_230 = V_19 ;
}
}
if ( ( V_165 >= 0 ) || ( V_229 >= 0 ) ) {
if ( ( V_165 >= 0 ) && ( V_229 >= 0 ) ) {
V_37 . V_25 [ V_165 ] . V_27 += V_177 ;
V_37 . V_25 [ V_165 ] . V_27 += V_37 . V_25 [ V_229 ] . V_27 ;
V_37 . V_25 [ V_229 ] . V_26 = 0 ;
V_37 . V_25 [ V_229 ] . V_27 = 0 ;
} else if ( V_165 >= 0 ) {
V_37 . V_25 [ V_165 ] . V_27 += V_177 ;
} else {
V_37 . V_25 [ V_229 ] . V_26 = F_3 ( V_137 -> V_149 ) ;
V_37 . V_25 [ V_229 ] . V_27 += V_177 ;
}
} else {
if ( V_37 . V_25 [ V_230 ] . V_27 < V_177 ) {
V_37 . V_25 [ V_230 ] . V_26 = F_3 ( V_137 -> V_149 ) ;
V_37 . V_25 [ V_230 ] . V_27 = V_177 ;
}
}
if ( F_3 ( V_137 -> V_149 ) == V_37 . V_13 )
V_230 = 1 ;
else
V_230 = 0 ;
memset ( F_99 ( V_35 , args -> V_180 ) , 0 , V_177 ) ;
V_37 . V_16 -= V_177 ;
F_79 ( args -> V_102 , V_30 ,
F_95 ( V_35 , F_99 ( V_35 , args -> V_180 ) ,
V_177 ) ) ;
V_179 = ( V_37 . V_15 - args -> V_180 ) * sizeof( V_181 ) ;
memmove ( V_137 , V_137 + 1 , V_179 ) ;
V_37 . V_15 -- ;
F_79 ( args -> V_102 , V_30 ,
F_95 ( V_35 , V_137 , V_179 + sizeof( V_181 ) ) ) ;
V_137 = & F_72 ( V_35 ) [ V_37 . V_15 ] ;
memset ( V_137 , 0 , sizeof( V_181 ) ) ;
if ( V_230 ) {
V_179 = args -> V_2 -> V_17 ;
V_137 = F_72 ( V_35 ) ;
for ( V_19 = V_37 . V_15 - 1 ; V_19 >= 0 ; V_137 ++ , V_19 -- ) {
ASSERT ( F_3 ( V_137 -> V_149 ) >= V_37 . V_13 ) ;
ASSERT ( F_3 ( V_137 -> V_149 ) < args -> V_2 -> V_17 ) ;
if ( F_3 ( V_137 -> V_149 ) < V_179 )
V_179 = F_3 ( V_137 -> V_149 ) ;
}
V_37 . V_13 = V_179 ;
ASSERT ( V_37 . V_13 != 0 ) ;
} else {
V_37 . V_23 = 1 ;
}
F_7 ( args -> V_2 , V_35 , & V_37 ) ;
F_79 ( args -> V_102 , V_30 ,
F_95 ( V_35 , & V_35 -> V_9 ,
F_92 ( V_35 ) ) ) ;
V_179 = V_37 . V_16 + F_92 ( V_35 ) +
V_37 . V_15 * sizeof( V_181 ) ;
return V_179 < args -> V_2 -> V_231 ;
}
void
F_114 (
struct V_170 * V_171 ,
struct V_172 * V_232 ,
struct V_172 * V_233 )
{
struct V_5 * V_234 = V_232 -> V_30 -> V_36 ;
struct V_5 * V_235 = V_233 -> V_30 -> V_36 ;
struct V_3 V_236 ;
struct V_3 V_237 ;
struct V_136 * V_137 ;
F_115 ( V_171 -> args ) ;
V_234 = V_232 -> V_30 -> V_36 ;
V_235 = V_233 -> V_30 -> V_36 ;
F_5 ( V_171 -> args -> V_2 , & V_236 , V_234 ) ;
F_5 ( V_171 -> args -> V_2 , & V_237 , V_235 ) ;
V_137 = F_72 ( V_234 ) ;
V_232 -> V_134 = F_6 ( V_137 [ V_236 . V_15 - 1 ] . V_134 ) ;
if ( V_237 . V_23 == 0 ) {
if ( F_103 ( V_233 -> V_30 , & V_237 ,
V_232 -> V_30 , & V_236 ) ) {
F_102 ( V_171 -> args ,
V_234 , & V_236 , 0 ,
V_235 , & V_237 , 0 ,
V_236 . V_15 ) ;
} else {
F_102 ( V_171 -> args ,
V_234 , & V_236 , 0 ,
V_235 , & V_237 ,
V_237 . V_15 , V_236 . V_15 ) ;
}
} else {
struct V_5 * V_238 ;
struct V_3 V_239 ;
V_238 = F_116 ( V_171 -> args -> V_2 -> V_17 , V_126 ) ;
memcpy ( V_238 , V_235 , F_92 ( V_235 ) ) ;
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
V_239 . V_11 = V_237 . V_11 ;
V_239 . V_21 = V_237 . V_21 ;
V_239 . V_22 = V_237 . V_22 ;
V_239 . V_13 = V_171 -> args -> V_2 -> V_17 ;
F_7 ( V_171 -> args -> V_2 , V_238 , & V_239 ) ;
if ( F_103 ( V_233 -> V_30 , & V_237 ,
V_232 -> V_30 , & V_236 ) ) {
F_102 ( V_171 -> args ,
V_234 , & V_236 , 0 ,
V_238 , & V_239 , 0 ,
V_236 . V_15 ) ;
F_102 ( V_171 -> args ,
V_235 , & V_237 , 0 ,
V_238 , & V_239 , V_239 . V_15 ,
V_237 . V_15 ) ;
} else {
F_102 ( V_171 -> args ,
V_235 , & V_237 , 0 ,
V_238 , & V_239 , 0 ,
V_237 . V_15 ) ;
F_102 ( V_171 -> args ,
V_234 , & V_236 , 0 ,
V_238 , & V_239 , V_239 . V_15 ,
V_236 . V_15 ) ;
}
memcpy ( V_235 , V_238 , V_171 -> args -> V_2 -> V_17 ) ;
V_237 = V_239 ;
F_70 ( V_238 ) ;
}
F_7 ( V_171 -> args -> V_2 , V_235 , & V_237 ) ;
F_79 ( V_171 -> args -> V_102 , V_233 -> V_30 , 0 ,
V_171 -> args -> V_2 -> V_17 - 1 ) ;
V_137 = F_72 ( V_235 ) ;
V_233 -> V_134 = F_6 ( V_137 [ V_237 . V_15 - 1 ] . V_134 ) ;
}
int
F_68 (
struct V_29 * V_30 ,
struct V_145 * args )
{
struct V_5 * V_35 ;
struct V_3 V_37 ;
struct V_136 * V_137 ;
struct V_136 * V_151 ;
struct V_146 * V_138 ;
struct V_184 * V_185 ;
T_14 V_134 ;
int V_240 ;
int V_241 ;
F_117 ( args ) ;
V_35 = V_30 -> V_36 ;
F_5 ( args -> V_2 , & V_37 , V_35 ) ;
V_151 = F_72 ( V_35 ) ;
ASSERT ( V_37 . V_15 < args -> V_2 -> V_17 / 8 ) ;
V_134 = args -> V_134 ;
V_240 = V_241 = V_37 . V_15 / 2 ;
for ( V_137 = & V_151 [ V_240 ] ; V_241 > 4 ; V_137 = & V_151 [ V_240 ] ) {
V_241 /= 2 ;
if ( F_6 ( V_137 -> V_134 ) < V_134 )
V_240 += V_241 ;
else if ( F_6 ( V_137 -> V_134 ) > V_134 )
V_240 -= V_241 ;
else
break;
}
ASSERT ( V_240 >= 0 && ( ! V_37 . V_15 || V_240 < V_37 . V_15 ) ) ;
ASSERT ( V_241 <= 4 || F_6 ( V_137 -> V_134 ) == V_134 ) ;
while ( V_240 > 0 && F_6 ( V_137 -> V_134 ) >= V_134 ) {
V_137 -- ;
V_240 -- ;
}
while ( V_240 < V_37 . V_15 &&
F_6 ( V_137 -> V_134 ) < V_134 ) {
V_137 ++ ;
V_240 ++ ;
}
if ( V_240 == V_37 . V_15 || F_6 ( V_137 -> V_134 ) != V_134 ) {
args -> V_180 = V_240 ;
return - V_118 ;
}
for (; V_240 < V_37 . V_15 && ( F_6 ( V_137 -> V_134 ) == V_134 ) ;
V_137 ++ , V_240 ++ ) {
if ( ( args -> V_112 & V_141 ) !=
( V_137 -> V_112 & V_141 ) ) {
continue;
}
if ( V_137 -> V_112 & V_142 ) {
V_138 = F_73 ( V_35 , V_240 ) ;
if ( V_138 -> V_109 != args -> V_109 )
continue;
if ( memcmp ( args -> V_110 , V_138 -> V_111 ,
args -> V_109 ) != 0 )
continue;
if ( ! F_24 ( args -> V_112 , V_137 -> V_112 ) )
continue;
args -> V_180 = V_240 ;
return - V_121 ;
} else {
V_185 = F_97 ( V_35 , V_240 ) ;
if ( V_185 -> V_109 != args -> V_109 )
continue;
if ( memcmp ( args -> V_110 , V_185 -> V_110 ,
args -> V_109 ) != 0 )
continue;
if ( ! F_24 ( args -> V_112 , V_137 -> V_112 ) )
continue;
args -> V_180 = V_240 ;
args -> V_193 = F_6 ( V_185 -> V_113 ) ;
args -> V_191 = F_6 ( V_185 -> V_190 ) ;
args -> V_192 = F_98 (
args -> V_58 -> V_73 ,
args -> V_193 ) ;
return - V_121 ;
}
}
args -> V_180 = V_240 ;
return - V_118 ;
}
int
F_118 (
struct V_29 * V_30 ,
struct V_145 * args )
{
struct V_5 * V_35 ;
struct V_3 V_37 ;
struct V_136 * V_137 ;
struct V_146 * V_138 ;
struct V_184 * V_185 ;
int V_113 ;
V_35 = V_30 -> V_36 ;
F_5 ( args -> V_2 , & V_37 , V_35 ) ;
ASSERT ( V_37 . V_15 < args -> V_2 -> V_17 / 8 ) ;
ASSERT ( args -> V_180 < V_37 . V_15 ) ;
V_137 = & F_72 ( V_35 ) [ args -> V_180 ] ;
if ( V_137 -> V_112 & V_142 ) {
V_138 = F_73 ( V_35 , args -> V_180 ) ;
ASSERT ( V_138 -> V_109 == args -> V_109 ) ;
ASSERT ( memcmp ( args -> V_110 , V_138 -> V_111 , args -> V_109 ) == 0 ) ;
V_113 = F_3 ( V_138 -> V_113 ) ;
if ( args -> V_112 & V_122 ) {
args -> V_113 = V_113 ;
return 0 ;
}
if ( args -> V_113 < V_113 ) {
args -> V_113 = V_113 ;
return - V_123 ;
}
args -> V_113 = V_113 ;
memcpy ( args -> V_114 , & V_138 -> V_111 [ args -> V_109 ] , V_113 ) ;
} else {
V_185 = F_97 ( V_35 , args -> V_180 ) ;
ASSERT ( V_185 -> V_109 == args -> V_109 ) ;
ASSERT ( memcmp ( args -> V_110 , V_185 -> V_110 , args -> V_109 ) == 0 ) ;
args -> V_193 = F_6 ( V_185 -> V_113 ) ;
args -> V_191 = F_6 ( V_185 -> V_190 ) ;
args -> V_192 = F_98 ( args -> V_58 -> V_73 ,
args -> V_193 ) ;
if ( args -> V_112 & V_122 ) {
args -> V_113 = args -> V_193 ;
return 0 ;
}
if ( args -> V_113 < args -> V_193 ) {
args -> V_113 = args -> V_193 ;
return - V_123 ;
}
args -> V_113 = args -> V_193 ;
}
return 0 ;
}
STATIC void
F_102 (
struct V_145 * args ,
struct V_5 * V_242 ,
struct V_3 * V_243 ,
int V_244 ,
struct V_5 * V_245 ,
struct V_3 * V_246 ,
int V_247 ,
int V_15 )
{
struct V_136 * V_248 ;
struct V_136 * V_249 ;
int V_250 ;
int V_179 ;
int V_19 ;
if ( V_15 == 0 )
return;
ASSERT ( V_243 -> V_11 == V_20 ||
V_243 -> V_11 == V_12 ) ;
ASSERT ( V_243 -> V_11 == V_246 -> V_11 ) ;
ASSERT ( V_243 -> V_15 > 0 && V_243 -> V_15 < args -> V_2 -> V_17 / 8 ) ;
ASSERT ( V_243 -> V_13 >= ( V_243 -> V_15 * sizeof( * V_248 ) )
+ F_92 ( V_242 ) ) ;
ASSERT ( V_246 -> V_15 < args -> V_2 -> V_17 / 8 ) ;
ASSERT ( V_246 -> V_13 >= ( V_246 -> V_15 * sizeof( * V_249 ) )
+ F_92 ( V_245 ) ) ;
ASSERT ( V_244 < V_243 -> V_15 ) ;
ASSERT ( V_247 <= V_246 -> V_15 ) ;
ASSERT ( V_15 <= V_243 -> V_15 ) ;
if ( V_247 < V_246 -> V_15 ) {
V_179 = V_246 -> V_15 - V_247 ;
V_179 *= sizeof( V_181 ) ;
V_248 = & F_72 ( V_245 ) [ V_247 ] ;
V_249 = & F_72 ( V_245 ) [ V_247 + V_15 ] ;
memmove ( V_249 , V_248 , V_179 ) ;
}
V_248 = & F_72 ( V_242 ) [ V_244 ] ;
V_249 = & F_72 ( V_245 ) [ V_247 ] ;
V_250 = V_247 ;
for ( V_19 = 0 ; V_19 < V_15 ; V_248 ++ , V_249 ++ , V_250 ++ , V_19 ++ ) {
ASSERT ( F_3 ( V_248 -> V_149 ) >= V_243 -> V_13 ) ;
V_179 = F_100 ( V_242 , V_244 + V_19 ) ;
#ifdef F_119
if ( V_248 -> V_112 & V_141 ) {
memset ( F_99 ( V_242 , V_244 + V_19 ) , 0 , V_179 ) ;
V_243 -> V_16 -= V_179 ;
V_243 -> V_15 -= 1 ;
V_249 -- ;
V_250 -- ;
if ( ( V_244 + V_19 ) < V_69 )
V_251 ++ ;
} else {
#endif
V_246 -> V_13 -= V_179 ;
V_249 -> V_134 = V_248 -> V_134 ;
V_249 -> V_149 = F_2 ( V_246 -> V_13 ) ;
V_249 -> V_112 = V_248 -> V_112 ;
ASSERT ( F_3 ( V_249 -> V_149 ) + V_179
<= args -> V_2 -> V_17 ) ;
memmove ( F_99 ( V_245 , V_250 ) ,
F_99 ( V_242 , V_244 + V_19 ) , V_179 ) ;
ASSERT ( F_3 ( V_248 -> V_149 ) + V_179
<= args -> V_2 -> V_17 ) ;
memset ( F_99 ( V_242 , V_244 + V_19 ) , 0 , V_179 ) ;
V_243 -> V_16 -= V_179 ;
V_246 -> V_16 += V_179 ;
V_243 -> V_15 -= 1 ;
V_246 -> V_15 += 1 ;
V_179 = V_246 -> V_15 * sizeof( V_181 )
+ F_92 ( V_245 ) ;
ASSERT ( V_246 -> V_13 >= V_179 ) ;
#ifdef F_119
}
#endif
}
if ( V_244 == V_243 -> V_15 ) {
V_179 = V_15 * sizeof( V_181 ) ;
V_248 = & F_72 ( V_242 ) [ V_244 ] ;
ASSERT ( ( ( char * ) V_248 + V_179 ) <=
( ( char * ) V_242 + args -> V_2 -> V_17 ) ) ;
memset ( V_248 , 0 , V_179 ) ;
} else {
V_179 = ( V_243 -> V_15 - V_15 ) * sizeof( V_181 ) ;
V_248 = & F_72 ( V_242 ) [ V_244 + V_15 ] ;
V_249 = & F_72 ( V_242 ) [ V_244 ] ;
memmove ( V_249 , V_248 , V_179 ) ;
V_179 = V_15 * sizeof( V_181 ) ;
V_248 = & F_72 ( V_242 ) [ V_243 -> V_15 ] ;
ASSERT ( ( ( char * ) V_248 + V_179 ) <=
( ( char * ) V_242 + args -> V_2 -> V_17 ) ) ;
memset ( V_248 , 0 , V_179 ) ;
}
V_246 -> V_25 [ 0 ] . V_26 = F_92 ( V_245 ) ;
V_246 -> V_25 [ 0 ] . V_26 += V_246 -> V_15 * sizeof( V_181 ) ;
V_246 -> V_25 [ 0 ] . V_27 = V_246 -> V_13 - V_246 -> V_25 [ 0 ] . V_26 ;
V_246 -> V_25 [ 1 ] . V_26 = 0 ;
V_246 -> V_25 [ 2 ] . V_26 = 0 ;
V_246 -> V_25 [ 1 ] . V_27 = 0 ;
V_246 -> V_25 [ 2 ] . V_27 = 0 ;
V_243 -> V_23 = 1 ;
}
T_14
F_89 (
struct V_29 * V_30 ,
int * V_15 )
{
struct V_3 V_37 ;
struct V_136 * V_151 ;
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
F_5 ( V_32 -> V_38 , & V_37 , V_30 -> V_36 ) ;
V_151 = F_72 ( V_30 -> V_36 ) ;
if ( V_15 )
* V_15 = V_37 . V_15 ;
if ( ! V_37 . V_15 )
return 0 ;
return F_6 ( V_151 [ V_37 . V_15 - 1 ] . V_134 ) ;
}
STATIC int
F_100 ( V_148 * V_35 , int V_180 )
{
struct V_136 * V_151 ;
T_12 * V_138 ;
T_15 * V_185 ;
int V_27 ;
V_151 = F_72 ( V_35 ) ;
if ( V_151 [ V_180 ] . V_112 & V_142 ) {
V_138 = F_73 ( V_35 , V_180 ) ;
V_27 = F_120 ( V_138 -> V_109 ,
F_3 ( V_138 -> V_113 ) ) ;
} else {
V_185 = F_97 ( V_35 , V_180 ) ;
V_27 = F_121 ( V_185 -> V_109 ) ;
}
return V_27 ;
}
int
F_91 (
struct V_145 * args ,
int * V_252 )
{
int V_27 ;
V_27 = F_120 ( args -> V_109 , args -> V_113 ) ;
if ( V_27 < F_122 ( args -> V_2 -> V_17 ) ) {
if ( V_252 )
* V_252 = 1 ;
return V_27 ;
}
if ( V_252 )
* V_252 = 0 ;
return F_121 ( args -> V_109 ) ;
}
int
F_123 (
struct V_145 * args )
{
struct V_5 * V_35 ;
struct V_136 * V_137 ;
struct V_184 * V_185 ;
struct V_29 * V_30 ;
int error ;
#ifdef F_48
struct V_3 V_37 ;
T_12 * V_138 ;
int V_109 ;
char * V_110 ;
#endif
F_124 ( args ) ;
error = F_21 ( args -> V_102 , args -> V_58 , args -> V_43 , - 1 , & V_30 ) ;
if ( error )
return error ;
V_35 = V_30 -> V_36 ;
V_137 = & F_72 ( V_35 ) [ args -> V_180 ] ;
ASSERT ( V_137 -> V_112 & V_141 ) ;
#ifdef F_48
F_5 ( args -> V_2 , & V_37 , V_35 ) ;
ASSERT ( args -> V_180 < V_37 . V_15 ) ;
ASSERT ( args -> V_180 >= 0 ) ;
if ( V_137 -> V_112 & V_142 ) {
V_138 = F_73 ( V_35 , args -> V_180 ) ;
V_109 = V_138 -> V_109 ;
V_110 = ( char * ) V_138 -> V_111 ;
} else {
V_185 = F_97 ( V_35 , args -> V_180 ) ;
V_109 = V_185 -> V_109 ;
V_110 = ( char * ) V_185 -> V_110 ;
}
ASSERT ( F_6 ( V_137 -> V_134 ) == args -> V_134 ) ;
ASSERT ( V_109 == args -> V_109 ) ;
ASSERT ( memcmp ( V_110 , args -> V_110 , V_109 ) == 0 ) ;
#endif
V_137 -> V_112 &= ~ V_141 ;
F_79 ( args -> V_102 , V_30 ,
F_95 ( V_35 , V_137 , sizeof( * V_137 ) ) ) ;
if ( args -> V_191 ) {
ASSERT ( ( V_137 -> V_112 & V_142 ) == 0 ) ;
V_185 = F_97 ( V_35 , args -> V_180 ) ;
V_185 -> V_190 = F_8 ( args -> V_191 ) ;
V_185 -> V_113 = F_8 ( args -> V_193 ) ;
F_79 ( args -> V_102 , V_30 ,
F_95 ( V_35 , V_185 , sizeof( * V_185 ) ) ) ;
}
return F_125 ( & args -> V_102 , args -> V_58 ) ;
}
int
F_126 (
struct V_145 * args )
{
struct V_5 * V_35 ;
struct V_136 * V_137 ;
struct V_184 * V_185 ;
struct V_29 * V_30 ;
int error ;
#ifdef F_48
struct V_3 V_37 ;
#endif
F_127 ( args ) ;
error = F_21 ( args -> V_102 , args -> V_58 , args -> V_43 , - 1 , & V_30 ) ;
if ( error )
return error ;
V_35 = V_30 -> V_36 ;
#ifdef F_48
F_5 ( args -> V_2 , & V_37 , V_35 ) ;
ASSERT ( args -> V_180 < V_37 . V_15 ) ;
ASSERT ( args -> V_180 >= 0 ) ;
#endif
V_137 = & F_72 ( V_35 ) [ args -> V_180 ] ;
ASSERT ( ( V_137 -> V_112 & V_141 ) == 0 ) ;
V_137 -> V_112 |= V_141 ;
F_79 ( args -> V_102 , V_30 ,
F_95 ( V_35 , V_137 , sizeof( * V_137 ) ) ) ;
if ( ( V_137 -> V_112 & V_142 ) == 0 ) {
V_185 = F_97 ( V_35 , args -> V_180 ) ;
V_185 -> V_190 = 0 ;
V_185 -> V_113 = 0 ;
F_79 ( args -> V_102 , V_30 ,
F_95 ( V_35 , V_185 , sizeof( * V_185 ) ) ) ;
}
return F_125 ( & args -> V_102 , args -> V_58 ) ;
}
int
F_128 (
struct V_145 * args )
{
struct V_5 * V_208 ;
struct V_5 * V_209 ;
struct V_136 * V_253 ;
struct V_136 * V_254 ;
struct V_184 * V_185 ;
struct V_29 * V_158 ;
struct V_29 * V_159 ;
int error ;
#ifdef F_48
struct V_3 V_204 ;
struct V_3 V_205 ;
T_12 * V_138 ;
int V_255 , V_256 ;
char * V_257 , * V_258 ;
#endif
F_129 ( args ) ;
error = F_21 ( args -> V_102 , args -> V_58 , args -> V_43 , - 1 , & V_158 ) ;
if ( error )
return error ;
if ( args -> V_188 != args -> V_43 ) {
error = F_21 ( args -> V_102 , args -> V_58 , args -> V_188 ,
- 1 , & V_159 ) ;
if ( error )
return error ;
} else {
V_159 = V_158 ;
}
V_208 = V_158 -> V_36 ;
V_253 = & F_72 ( V_208 ) [ args -> V_180 ] ;
V_209 = V_159 -> V_36 ;
V_254 = & F_72 ( V_209 ) [ args -> V_189 ] ;
#ifdef F_48
F_5 ( args -> V_2 , & V_204 , V_208 ) ;
ASSERT ( args -> V_180 < V_204 . V_15 ) ;
ASSERT ( args -> V_180 >= 0 ) ;
F_5 ( args -> V_2 , & V_205 , V_209 ) ;
ASSERT ( args -> V_189 < V_205 . V_15 ) ;
ASSERT ( args -> V_189 >= 0 ) ;
if ( V_253 -> V_112 & V_142 ) {
V_138 = F_73 ( V_208 , args -> V_180 ) ;
V_255 = V_138 -> V_109 ;
V_257 = ( char * ) V_138 -> V_111 ;
} else {
V_185 = F_97 ( V_208 , args -> V_180 ) ;
V_255 = V_185 -> V_109 ;
V_257 = ( char * ) V_185 -> V_110 ;
}
if ( V_254 -> V_112 & V_142 ) {
V_138 = F_73 ( V_209 , args -> V_189 ) ;
V_256 = V_138 -> V_109 ;
V_258 = ( char * ) V_138 -> V_111 ;
} else {
V_185 = F_97 ( V_209 , args -> V_189 ) ;
V_256 = V_185 -> V_109 ;
V_258 = ( char * ) V_185 -> V_110 ;
}
ASSERT ( F_6 ( V_253 -> V_134 ) == F_6 ( V_254 -> V_134 ) ) ;
ASSERT ( V_255 == V_256 ) ;
ASSERT ( memcmp ( V_257 , V_258 , V_255 ) == 0 ) ;
#endif
ASSERT ( V_253 -> V_112 & V_141 ) ;
ASSERT ( ( V_254 -> V_112 & V_141 ) == 0 ) ;
V_253 -> V_112 &= ~ V_141 ;
F_79 ( args -> V_102 , V_158 ,
F_95 ( V_208 , V_253 , sizeof( * V_253 ) ) ) ;
if ( args -> V_191 ) {
ASSERT ( ( V_253 -> V_112 & V_142 ) == 0 ) ;
V_185 = F_97 ( V_208 , args -> V_180 ) ;
V_185 -> V_190 = F_8 ( args -> V_191 ) ;
V_185 -> V_113 = F_8 ( args -> V_193 ) ;
F_79 ( args -> V_102 , V_158 ,
F_95 ( V_208 , V_185 , sizeof( * V_185 ) ) ) ;
}
V_254 -> V_112 |= V_141 ;
F_79 ( args -> V_102 , V_159 ,
F_95 ( V_209 , V_254 , sizeof( * V_254 ) ) ) ;
if ( ( V_254 -> V_112 & V_142 ) == 0 ) {
V_185 = F_97 ( V_209 , args -> V_189 ) ;
V_185 -> V_190 = 0 ;
V_185 -> V_113 = 0 ;
F_79 ( args -> V_102 , V_159 ,
F_95 ( V_209 , V_185 , sizeof( * V_185 ) ) ) ;
}
error = F_125 ( & args -> V_102 , args -> V_58 ) ;
return error ;
}
