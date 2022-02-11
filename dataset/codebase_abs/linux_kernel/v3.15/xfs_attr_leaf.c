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
F_12 ( V_25 , V_42 ) ;
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
F_12 ( V_25 , V_47 ) ;
else if ( ! F_7 ( V_25 ) )
F_12 ( V_25 , V_42 ) ;
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
return ( F_53 ( V_114 ) ) ;
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
return ( 0 ) ;
}
int
F_54 ( T_6 * args )
{
T_9 * V_102 ;
T_10 * V_103 ;
int V_5 ;
T_8 * V_88 ;
F_55 ( args ) ;
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
return ( F_53 ( V_117 ) ) ;
}
return ( F_53 ( V_114 ) ) ;
}
int
F_56 ( T_6 * args )
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
return ( F_53 ( V_117 ) ) ;
}
if ( args -> V_109 < V_103 -> V_109 ) {
args -> V_109 = V_103 -> V_109 ;
return ( F_53 ( V_119 ) ) ;
}
args -> V_109 = V_103 -> V_109 ;
memcpy ( args -> V_110 , & V_103 -> V_107 [ args -> V_105 ] ,
args -> V_109 ) ;
return ( F_53 ( V_117 ) ) ;
}
return ( F_53 ( V_114 ) ) ;
}
int
F_57 ( T_6 * args )
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
F_58 ( args ) ;
V_52 = args -> V_52 ;
V_88 = V_52 -> V_89 ;
V_102 = ( T_9 * ) V_88 -> V_95 . V_96 ;
V_22 = F_4 ( V_102 -> V_6 . V_97 ) ;
V_121 = F_59 ( V_22 , V_122 ) ;
ASSERT ( V_121 != NULL ) ;
memcpy ( V_121 , V_88 -> V_95 . V_96 , V_22 ) ;
V_102 = ( T_9 * ) V_121 ;
F_40 ( V_52 , - V_22 , V_57 ) ;
F_60 ( V_52 , V_57 ) ;
V_25 = NULL ;
error = F_61 ( args , & V_37 ) ;
if ( error ) {
if ( error == V_123 )
goto V_124;
F_40 ( V_52 , V_22 , V_57 ) ;
memcpy ( V_88 -> V_95 . V_96 , V_121 , V_22 ) ;
goto V_124;
}
ASSERT ( V_37 == 0 ) ;
error = F_62 ( args , V_37 , & V_25 ) ;
if ( error ) {
error = F_63 ( args , 0 , V_25 ) ;
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
V_120 . V_128 = V_57 ;
V_120 . V_98 = args -> V_98 ;
V_120 . V_115 = V_129 ;
V_103 = & V_102 -> V_104 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_102 -> V_6 . V_15 ; V_5 ++ ) {
V_120 . V_106 = V_103 -> V_107 ;
V_120 . V_105 = V_103 -> V_105 ;
V_120 . V_110 = & V_103 -> V_107 [ V_120 . V_105 ] ;
V_120 . V_109 = V_103 -> V_109 ;
V_120 . V_130 = F_64 ( V_103 -> V_107 ,
V_103 -> V_105 ) ;
V_120 . V_108 = F_65 ( V_103 -> V_108 ) ;
error = F_66 ( V_25 , & V_120 ) ;
ASSERT ( error == V_114 ) ;
error = F_67 ( V_25 , & V_120 ) ;
ASSERT ( error != V_131 ) ;
if ( error )
goto V_124;
V_103 = F_44 ( V_103 ) ;
}
error = 0 ;
V_124:
F_68 ( V_121 ) ;
return ( error ) ;
}
int
F_69 (
struct V_24 * V_25 ,
struct V_51 * V_52 )
{
struct V_3 * V_30 ;
struct V_132 * V_133 ;
T_11 * V_134 ;
struct V_1 V_135 ;
int V_62 ;
int V_5 ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_135 , V_30 ) ;
V_133 = F_70 ( V_30 ) ;
V_62 = sizeof( struct V_136 ) ;
for ( V_5 = 0 ; V_5 < V_135 . V_15 ; V_133 ++ , V_5 ++ ) {
if ( V_133 -> V_108 & V_137 )
continue;
if ( ! ( V_133 -> V_108 & V_138 ) )
return ( 0 ) ;
V_134 = F_71 ( V_30 , V_5 ) ;
if ( V_134 -> V_105 >= V_139 )
return ( 0 ) ;
if ( F_4 ( V_134 -> V_109 ) >= V_139 )
return ( 0 ) ;
V_62 += sizeof( struct V_140 ) - 1
+ V_134 -> V_105
+ F_4 ( V_134 -> V_109 ) ;
}
if ( ( V_52 -> V_67 -> V_76 & V_77 ) &&
( V_52 -> V_68 . V_70 != V_82 ) &&
( V_62 == sizeof( struct V_136 ) ) )
return - 1 ;
return F_24 ( V_52 , V_62 ) ;
}
int
F_72 (
struct V_24 * V_25 ,
struct V_141 * args ,
int V_101 )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_132 * V_133 ;
struct V_142 * V_134 ;
struct V_141 V_120 ;
struct V_51 * V_52 = args -> V_52 ;
char * V_121 ;
int error ;
int V_5 ;
F_73 ( args ) ;
V_121 = F_59 ( F_74 ( V_52 -> V_67 ) , V_122 ) ;
if ( ! V_121 )
return V_143 ;
memcpy ( V_121 , V_25 -> V_31 , F_74 ( V_52 -> V_67 ) ) ;
V_30 = ( V_144 * ) V_121 ;
F_1 ( & V_32 , V_30 ) ;
V_133 = F_70 ( V_30 ) ;
memset ( V_25 -> V_31 , 0 , F_74 ( V_52 -> V_67 ) ) ;
error = F_63 ( args , 0 , V_25 ) ;
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
V_120 . V_52 = V_52 ;
V_120 . V_125 = args -> V_125 ;
V_120 . V_126 = args -> V_126 ;
V_120 . V_127 = args -> V_127 ;
V_120 . V_128 = V_57 ;
V_120 . V_98 = args -> V_98 ;
V_120 . V_115 = V_129 ;
for ( V_5 = 0 ; V_5 < V_32 . V_15 ; V_133 ++ , V_5 ++ ) {
if ( V_133 -> V_108 & V_137 )
continue;
if ( ! V_133 -> V_145 )
continue;
ASSERT ( V_133 -> V_108 & V_138 ) ;
V_134 = F_71 ( V_30 , V_5 ) ;
V_120 . V_106 = V_134 -> V_107 ;
V_120 . V_105 = V_134 -> V_105 ;
V_120 . V_110 = & V_134 -> V_107 [ V_120 . V_105 ] ;
V_120 . V_109 = F_4 ( V_134 -> V_109 ) ;
V_120 . V_130 = F_3 ( V_133 -> V_130 ) ;
V_120 . V_108 = F_65 ( V_133 -> V_108 ) ;
F_42 ( & V_120 , V_101 ) ;
}
error = 0 ;
V_124:
F_68 ( V_121 ) ;
return error ;
}
int
F_75 (
struct V_141 * args )
{
struct V_3 * V_30 ;
struct V_1 V_146 ;
struct V_132 * V_147 ;
struct V_148 * V_149 ;
struct V_150 V_151 ;
struct V_152 * V_153 ;
struct V_51 * V_52 = args -> V_52 ;
struct V_26 * V_27 = V_52 -> V_67 ;
struct V_24 * V_154 = NULL ;
struct V_24 * V_155 = NULL ;
T_1 V_37 ;
int error ;
F_76 ( args ) ;
error = F_61 ( args , & V_37 ) ;
if ( error )
goto V_124;
error = F_18 ( args -> V_98 , V_52 , 0 , - 1 , & V_154 ) ;
if ( error )
goto V_124;
error = F_77 ( args -> V_98 , V_52 , V_37 , - 1 , & V_155 , V_57 ) ;
if ( error )
goto V_124;
F_20 ( args -> V_98 , V_155 , V_59 ) ;
V_155 -> V_156 = V_154 -> V_156 ;
memcpy ( V_155 -> V_31 , V_154 -> V_31 , F_74 ( V_27 ) ) ;
if ( F_8 ( & V_27 -> V_33 ) ) {
struct V_157 * V_12 = V_155 -> V_31 ;
V_12 -> V_37 = F_14 ( V_155 -> V_38 ) ;
}
F_78 ( args -> V_98 , V_155 , 0 , F_74 ( V_27 ) - 1 ) ;
error = F_79 ( args , 0 , 1 , & V_154 , V_57 ) ;
if ( error )
goto V_124;
V_153 = V_154 -> V_31 ;
V_52 -> V_158 -> V_159 ( & V_151 , V_153 ) ;
V_149 = V_52 -> V_158 -> V_160 ( V_153 ) ;
V_30 = V_155 -> V_31 ;
F_1 ( & V_146 , V_30 ) ;
V_147 = F_70 ( V_30 ) ;
V_149 [ 0 ] . V_130 = V_147 [ V_146 . V_15 - 1 ] . V_130 ;
V_149 [ 0 ] . V_161 = F_6 ( V_37 ) ;
V_151 . V_15 = 1 ;
V_52 -> V_158 -> V_162 ( V_153 , & V_151 ) ;
F_78 ( args -> V_98 , V_154 , 0 , F_74 ( V_27 ) - 1 ) ;
error = 0 ;
V_124:
return error ;
}
STATIC int
F_62 (
struct V_141 * args ,
T_1 V_37 ,
struct V_24 * * V_55 )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_51 * V_52 = args -> V_52 ;
struct V_26 * V_27 = V_52 -> V_67 ;
struct V_24 * V_25 ;
int error ;
F_80 ( args ) ;
error = F_77 ( args -> V_98 , args -> V_52 , V_37 , - 1 , & V_25 ,
V_57 ) ;
if ( error )
return error ;
V_25 -> V_156 = & V_58 ;
F_20 ( args -> V_98 , V_25 , V_59 ) ;
V_30 = V_25 -> V_31 ;
memset ( V_30 , 0 , F_74 ( V_27 ) ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_17 = F_74 ( V_27 ) ;
if ( F_8 ( & V_27 -> V_33 ) ) {
struct V_157 * V_12 = V_25 -> V_31 ;
V_32 . V_8 = V_10 ;
V_12 -> V_37 = F_14 ( V_25 -> V_38 ) ;
V_12 -> V_163 = F_14 ( V_52 -> V_164 ) ;
F_81 ( & V_12 -> V_35 , & V_27 -> V_33 . V_36 ) ;
V_32 . V_20 [ 0 ] . V_21 = sizeof( struct V_11 ) ;
} else {
V_32 . V_8 = V_9 ;
V_32 . V_20 [ 0 ] . V_21 = sizeof( struct V_165 ) ;
}
V_32 . V_20 [ 0 ] . V_22 = V_32 . V_17 - V_32 . V_20 [ 0 ] . V_21 ;
F_5 ( V_30 , & V_32 ) ;
F_78 ( args -> V_98 , V_25 , 0 , F_74 ( V_27 ) - 1 ) ;
* V_55 = V_25 ;
return 0 ;
}
int
F_82 (
struct V_166 * V_167 ,
struct V_168 * V_169 ,
struct V_168 * V_170 )
{
T_1 V_37 ;
int error ;
F_83 ( V_167 -> args ) ;
ASSERT ( V_169 -> V_8 == V_9 ) ;
error = F_61 ( V_167 -> args , & V_37 ) ;
if ( error )
return ( error ) ;
error = F_62 ( V_167 -> args , V_37 , & V_170 -> V_25 ) ;
if ( error )
return ( error ) ;
V_170 -> V_37 = V_37 ;
V_170 -> V_8 = V_9 ;
F_84 ( V_167 , V_169 , V_170 ) ;
error = F_85 ( V_167 , V_169 , V_170 ) ;
if ( error )
return ( error ) ;
if ( V_167 -> V_171 ) {
F_86 ( V_167 -> args ) ;
error = F_67 ( V_169 -> V_25 , V_167 -> args ) ;
} else {
F_87 ( V_167 -> args ) ;
error = F_67 ( V_170 -> V_25 , V_167 -> args ) ;
}
V_169 -> V_130 = F_88 ( V_169 -> V_25 , NULL ) ;
V_170 -> V_130 = F_88 ( V_170 -> V_25 , NULL ) ;
return ( error ) ;
}
int
F_67 (
struct V_24 * V_25 ,
struct V_141 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
int V_172 ;
int V_173 ;
int V_174 ;
int V_175 ;
int V_5 ;
F_89 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_176 >= 0 && args -> V_176 <= V_32 . V_15 ) ;
V_173 = F_90 ( args -> V_105 , args -> V_109 ,
args -> V_98 -> V_177 -> V_33 . V_178 , NULL ) ;
V_172 = ( V_32 . V_15 + 1 ) * sizeof( V_179 )
+ F_91 ( V_30 ) ;
for ( V_174 = 0 , V_5 = V_19 - 1 ; V_5 >= 0 ; V_5 -- ) {
if ( V_172 > V_32 . V_17 ) {
V_174 += V_32 . V_20 [ V_5 ] . V_22 ;
continue;
}
if ( ! V_32 . V_20 [ V_5 ] . V_22 )
continue;
V_175 = V_173 ;
if ( V_32 . V_20 [ V_5 ] . V_21 < V_32 . V_17 )
V_175 += sizeof( V_179 ) ;
if ( V_32 . V_20 [ V_5 ] . V_22 >= V_175 ) {
V_175 = F_92 ( V_25 , & V_32 , args , V_5 ) ;
goto V_180;
}
V_174 += V_32 . V_20 [ V_5 ] . V_22 ;
}
if ( ! V_32 . V_18 && V_174 < V_173 )
return F_53 ( V_131 ) ;
F_93 ( args , & V_32 , V_25 ) ;
if ( V_32 . V_20 [ 0 ] . V_22 < ( V_173 + sizeof( V_179 ) ) ) {
V_175 = V_131 ;
goto V_180;
}
V_175 = F_92 ( V_25 , & V_32 , args , 0 ) ;
V_180:
F_5 ( V_30 , & V_32 ) ;
F_78 ( args -> V_98 , V_25 ,
F_94 ( V_30 , & V_30 -> V_6 ,
F_91 ( V_30 ) ) ) ;
return V_175 ;
}
STATIC int
F_92 (
struct V_24 * V_25 ,
struct V_1 * V_32 ,
struct V_141 * args ,
int V_181 )
{
struct V_3 * V_30 ;
struct V_132 * V_133 ;
struct V_142 * V_134 ;
struct V_182 * V_183 ;
struct V_26 * V_27 ;
int V_175 ;
int V_5 ;
F_95 ( args ) ;
V_30 = V_25 -> V_31 ;
ASSERT ( V_181 >= 0 && V_181 < V_19 ) ;
ASSERT ( args -> V_176 >= 0 && args -> V_176 <= V_32 -> V_15 ) ;
V_133 = & F_70 ( V_30 ) [ args -> V_176 ] ;
if ( args -> V_176 < V_32 -> V_15 ) {
V_175 = V_32 -> V_15 - args -> V_176 ;
V_175 *= sizeof( V_179 ) ;
memmove ( V_133 + 1 , V_133 , V_175 ) ;
F_78 ( args -> V_98 , V_25 ,
F_94 ( V_30 , V_133 , V_175 + sizeof( * V_133 ) ) ) ;
}
V_32 -> V_15 ++ ;
V_27 = args -> V_98 -> V_177 ;
ASSERT ( V_32 -> V_20 [ V_181 ] . V_21 < F_74 ( V_27 ) ) ;
ASSERT ( ( V_32 -> V_20 [ V_181 ] . V_21 & 0x3 ) == 0 ) ;
ASSERT ( V_32 -> V_20 [ V_181 ] . V_22 >=
F_90 ( args -> V_105 , args -> V_109 ,
V_27 -> V_33 . V_178 , NULL ) ) ;
ASSERT ( V_32 -> V_20 [ V_181 ] . V_22 < F_74 ( V_27 ) ) ;
ASSERT ( ( V_32 -> V_20 [ V_181 ] . V_22 & 0x3 ) == 0 ) ;
V_32 -> V_20 [ V_181 ] . V_22 -=
F_90 ( args -> V_105 , args -> V_109 ,
V_27 -> V_33 . V_178 , & V_175 ) ;
V_133 -> V_145 = F_2 ( V_32 -> V_20 [ V_181 ] . V_21 +
V_32 -> V_20 [ V_181 ] . V_22 ) ;
V_133 -> V_130 = F_6 ( args -> V_130 ) ;
V_133 -> V_108 = V_175 ? V_138 : 0 ;
V_133 -> V_108 |= F_23 ( args -> V_108 ) ;
if ( args -> V_115 & V_184 ) {
V_133 -> V_108 |= V_137 ;
if ( ( args -> V_185 == args -> V_37 ) &&
( args -> V_186 <= args -> V_176 ) ) {
args -> V_186 ++ ;
}
}
F_78 ( args -> V_98 , V_25 ,
F_94 ( V_30 , V_133 , sizeof( * V_133 ) ) ) ;
ASSERT ( ( args -> V_176 == 0 ) ||
( F_3 ( V_133 -> V_130 ) >= F_3 ( ( V_133 - 1 ) -> V_130 ) ) ) ;
ASSERT ( ( args -> V_176 == V_32 -> V_15 - 1 ) ||
( F_3 ( V_133 -> V_130 ) <= F_3 ( ( V_133 + 1 ) -> V_130 ) ) ) ;
if ( V_133 -> V_108 & V_138 ) {
V_134 = F_71 ( V_30 , args -> V_176 ) ;
V_134 -> V_105 = args -> V_105 ;
V_134 -> V_109 = F_2 ( args -> V_109 ) ;
memcpy ( ( char * ) V_134 -> V_107 , args -> V_106 , args -> V_105 ) ;
memcpy ( ( char * ) & V_134 -> V_107 [ args -> V_105 ] , args -> V_110 ,
F_4 ( V_134 -> V_109 ) ) ;
} else {
V_183 = F_96 ( V_30 , args -> V_176 ) ;
V_183 -> V_105 = args -> V_105 ;
memcpy ( ( char * ) V_183 -> V_106 , args -> V_106 , args -> V_105 ) ;
V_133 -> V_108 |= V_137 ;
V_183 -> V_109 = 0 ;
V_183 -> V_187 = 0 ;
args -> V_188 = 1 ;
args -> V_189 = F_97 ( V_27 , args -> V_109 ) ;
args -> V_190 = args -> V_109 ;
}
F_78 ( args -> V_98 , V_25 ,
F_94 ( V_30 , F_98 ( V_30 , args -> V_176 ) ,
F_99 ( V_30 , args -> V_176 ) ) ) ;
if ( F_4 ( V_133 -> V_145 ) < V_32 -> V_17 )
V_32 -> V_17 = F_4 ( V_133 -> V_145 ) ;
ASSERT ( V_32 -> V_17 >= V_32 -> V_15 * sizeof( V_179 )
+ F_91 ( V_30 ) ) ;
V_175 = ( V_32 -> V_15 - 1 ) * sizeof( V_179 )
+ F_91 ( V_30 ) ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
if ( V_32 -> V_20 [ V_5 ] . V_21 == V_175 ) {
V_32 -> V_20 [ V_5 ] . V_21 += sizeof( V_179 ) ;
V_32 -> V_20 [ V_5 ] . V_22 -= sizeof( V_179 ) ;
}
}
V_32 -> V_16 += F_99 ( V_30 , args -> V_176 ) ;
return 0 ;
}
STATIC void
F_93 (
struct V_141 * args ,
struct V_1 * V_191 ,
struct V_24 * V_25 )
{
struct V_3 * V_192 ;
struct V_3 * V_193 ;
struct V_1 V_194 ;
struct V_49 * V_98 = args -> V_98 ;
struct V_26 * V_27 = V_98 -> V_177 ;
char * V_121 ;
F_100 ( args ) ;
V_121 = F_59 ( F_74 ( V_27 ) , V_122 ) ;
memcpy ( V_121 , V_25 -> V_31 , F_74 ( V_27 ) ) ;
memset ( V_25 -> V_31 , 0 , F_74 ( V_27 ) ) ;
V_192 = ( V_144 * ) V_121 ;
V_193 = V_25 -> V_31 ;
memcpy ( V_25 -> V_31 , V_121 , F_91 ( V_192 ) ) ;
V_194 = * V_191 ;
V_191 -> V_17 = F_74 ( V_27 ) ;
V_191 -> V_16 = 0 ;
V_191 -> V_15 = 0 ;
V_191 -> V_18 = 0 ;
V_191 -> V_20 [ 0 ] . V_21 = F_91 ( V_192 ) ;
V_191 -> V_20 [ 0 ] . V_22 = V_191 -> V_17 -
V_191 -> V_20 [ 0 ] . V_21 ;
F_5 ( V_193 , V_191 ) ;
F_101 ( V_192 , & V_194 , 0 , V_193 , V_191 , 0 ,
V_194 . V_15 , V_27 ) ;
F_78 ( V_98 , V_25 , 0 , F_74 ( V_27 ) - 1 ) ;
F_68 ( V_121 ) ;
}
static int
F_102 (
struct V_24 * V_195 ,
struct V_1 * V_196 ,
struct V_24 * V_197 ,
struct V_1 * V_198 )
{
struct V_132 * V_199 ;
struct V_132 * V_200 ;
V_199 = F_70 ( V_195 -> V_31 ) ;
V_200 = F_70 ( V_197 -> V_31 ) ;
if ( V_196 -> V_15 > 0 && V_198 -> V_15 > 0 &&
( ( F_3 ( V_200 [ 0 ] . V_130 ) <
F_3 ( V_199 [ 0 ] . V_130 ) ) ||
( F_3 ( V_200 [ V_198 -> V_15 - 1 ] . V_130 ) <
F_3 ( V_199 [ V_196 -> V_15 - 1 ] . V_130 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_103 (
struct V_24 * V_195 ,
struct V_24 * V_197 )
{
struct V_1 V_201 ;
struct V_1 V_202 ;
F_1 ( & V_201 , V_195 -> V_31 ) ;
F_1 ( & V_202 , V_197 -> V_31 ) ;
return F_102 ( V_195 , & V_201 , V_197 , & V_202 ) ;
}
STATIC void
F_84 (
struct V_166 * V_167 ,
struct V_168 * V_203 ,
struct V_168 * V_204 )
{
struct V_141 * args ;
struct V_3 * V_205 ;
struct V_3 * V_206 ;
struct V_1 V_201 ;
struct V_1 V_202 ;
struct V_132 * V_199 ;
struct V_132 * V_200 ;
int V_15 ;
int V_207 ;
int V_208 ;
int V_209 ;
int V_210 ;
ASSERT ( V_203 -> V_8 == V_9 ) ;
ASSERT ( V_204 -> V_8 == V_9 ) ;
V_205 = V_203 -> V_25 -> V_31 ;
V_206 = V_204 -> V_25 -> V_31 ;
F_1 ( & V_201 , V_205 ) ;
F_1 ( & V_202 , V_206 ) ;
ASSERT ( V_202 . V_15 == 0 ) ;
args = V_167 -> args ;
F_104 ( args ) ;
V_210 = 0 ;
if ( F_102 ( V_203 -> V_25 , & V_201 , V_204 -> V_25 , & V_202 ) ) {
struct V_168 * V_211 ;
struct V_1 V_212 ;
V_211 = V_203 ;
V_203 = V_204 ;
V_204 = V_211 ;
V_212 = V_201 ;
V_201 = V_202 ;
V_202 = V_212 ;
V_205 = V_203 -> V_25 -> V_31 ;
V_206 = V_204 -> V_25 -> V_31 ;
V_210 = 1 ;
}
V_167 -> V_171 = F_105 ( V_167 , V_203 , & V_201 ,
V_204 , & V_202 ,
& V_15 , & V_207 ) ;
if ( V_210 )
V_167 -> V_171 = ! V_167 -> V_171 ;
if ( V_15 < V_201 . V_15 ) {
V_15 = V_201 . V_15 - V_15 ;
V_209 = V_201 . V_16 - V_207 ;
V_209 += V_15 * sizeof( V_179 ) ;
V_208 = V_202 . V_17 - F_91 ( V_205 ) ;
V_208 -= V_202 . V_15 * sizeof( V_179 ) ;
if ( V_209 > V_208 )
F_93 ( args , & V_202 , V_204 -> V_25 ) ;
F_101 ( V_205 , & V_201 , V_201 . V_15 - V_15 ,
V_206 , & V_202 , 0 , V_15 , V_167 -> V_27 ) ;
} else if ( V_15 > V_201 . V_15 ) {
ASSERT ( 0 ) ;
V_15 -= V_201 . V_15 ;
V_209 = V_207 - V_201 . V_16 ;
V_209 += V_15 * sizeof( V_179 ) ;
V_208 = V_201 . V_17 - F_91 ( V_205 ) ;
V_208 -= V_201 . V_15 * sizeof( V_179 ) ;
if ( V_209 > V_208 )
F_93 ( args , & V_201 , V_203 -> V_25 ) ;
F_101 ( V_206 , & V_202 , 0 , V_205 , & V_201 ,
V_201 . V_15 , V_15 , V_167 -> V_27 ) ;
}
F_5 ( V_205 , & V_201 ) ;
F_5 ( V_206 , & V_202 ) ;
F_78 ( args -> V_98 , V_203 -> V_25 , 0 , V_167 -> V_213 - 1 ) ;
F_78 ( args -> V_98 , V_204 -> V_25 , 0 , V_167 -> V_213 - 1 ) ;
V_199 = F_70 ( V_205 ) ;
V_200 = F_70 ( V_206 ) ;
V_203 -> V_130 = F_3 ( V_199 [ V_201 . V_15 - 1 ] . V_130 ) ;
V_204 -> V_130 = F_3 ( V_200 [ V_202 . V_15 - 1 ] . V_130 ) ;
if ( V_203 -> V_176 > V_201 . V_15 ) {
ASSERT ( V_167 -> V_171 == 0 ) ;
V_204 -> V_176 = V_203 -> V_176 - V_201 . V_15 ;
args -> V_176 = args -> V_186 = V_204 -> V_176 ;
args -> V_37 = args -> V_185 = V_204 -> V_37 ;
} else if ( V_203 -> V_176 == V_201 . V_15 ) {
if ( V_167 -> V_171 ) {
args -> V_176 = V_203 -> V_176 ;
args -> V_37 = V_203 -> V_37 ;
args -> V_186 = 0 ;
args -> V_185 = V_204 -> V_37 ;
} else {
V_204 -> V_176 = V_203 -> V_176 - V_201 . V_15 ;
args -> V_176 = V_204 -> V_176 ;
args -> V_37 = V_204 -> V_37 ;
if ( ! V_167 -> V_214 ) {
args -> V_186 = V_204 -> V_176 ;
args -> V_185 = V_204 -> V_37 ;
}
}
} else {
ASSERT ( V_167 -> V_171 == 1 ) ;
args -> V_176 = args -> V_186 = V_203 -> V_176 ;
args -> V_37 = args -> V_185 = V_203 -> V_37 ;
}
}
STATIC int
F_105 (
struct V_166 * V_167 ,
struct V_168 * V_203 ,
struct V_1 * V_201 ,
struct V_168 * V_204 ,
struct V_1 * V_202 ,
int * V_215 ,
int * V_216 )
{
struct V_3 * V_205 = V_203 -> V_25 -> V_31 ;
struct V_3 * V_206 = V_204 -> V_25 -> V_31 ;
struct V_132 * V_133 ;
int V_15 ;
int V_208 ;
int V_176 ;
int V_207 = 0 ;
int V_217 ;
int V_218 ;
int V_219 = 0 ;
int V_175 ;
V_208 = V_201 -> V_15 + V_202 -> V_15 ;
V_217 = ( V_208 + 1 ) * sizeof( * V_133 ) ;
V_217 += V_201 -> V_16 + V_202 -> V_16 +
F_90 ( V_167 -> args -> V_105 ,
V_167 -> args -> V_109 ,
V_167 -> V_213 , NULL ) ;
V_217 /= 2 ;
V_218 = V_167 -> V_213 ;
V_133 = F_70 ( V_205 ) ;
for ( V_15 = V_176 = 0 ; V_15 < V_208 ; V_133 ++ , V_176 ++ , V_15 ++ ) {
#define F_106 ( T_12 ) (((A) < 0) ? -(A) : (A))
if ( V_15 == V_203 -> V_176 ) {
V_175 = V_207 + sizeof( * V_133 ) +
F_90 (
V_167 -> args -> V_105 ,
V_167 -> args -> V_109 ,
V_167 -> V_213 , NULL ) ;
if ( F_106 ( V_217 - V_175 ) > V_218 )
break;
V_218 = F_106 ( V_217 - V_175 ) ;
V_207 = V_175 ;
V_219 = 1 ;
}
if ( V_15 == V_201 -> V_15 ) {
V_205 = V_206 ;
V_133 = F_70 ( V_205 ) ;
V_176 = 0 ;
}
V_175 = V_207 + sizeof( * V_133 ) + F_99 ( V_205 ,
V_176 ) ;
if ( F_106 ( V_217 - V_175 ) > V_218 )
break;
V_218 = F_106 ( V_217 - V_175 ) ;
V_207 = V_175 ;
#undef F_106
}
V_207 -= V_15 * sizeof( * V_133 ) ;
if ( V_219 ) {
V_207 -= sizeof( * V_133 ) +
F_90 (
V_167 -> args -> V_105 ,
V_167 -> args -> V_109 ,
V_167 -> V_213 , NULL ) ;
}
* V_215 = V_15 ;
* V_216 = V_207 ;
return V_219 ;
}
int
F_107 (
struct V_166 * V_167 ,
int * V_220 )
{
struct V_3 * V_30 ;
struct V_168 * V_221 ;
struct V_1 V_32 ;
struct V_24 * V_25 ;
T_1 V_37 ;
int V_62 ;
int V_222 ;
int error ;
int V_223 ;
int V_5 ;
F_108 ( V_167 -> args ) ;
V_221 = & V_167 -> V_224 . V_221 [ V_167 -> V_224 . V_225 - 1 ] ;
V_30 = V_221 -> V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_62 = F_91 ( V_30 ) +
V_32 . V_15 * sizeof( V_179 ) +
V_32 . V_16 ;
if ( V_62 > ( V_167 -> V_213 >> 1 ) ) {
* V_220 = 0 ;
return ( 0 ) ;
}
if ( V_32 . V_15 == 0 ) {
V_222 = ( V_32 . V_13 != 0 ) ;
memcpy ( & V_167 -> V_226 , & V_167 -> V_224 , sizeof( V_167 -> V_224 ) ) ;
error = F_109 ( V_167 , & V_167 -> V_226 , V_222 ,
0 , & V_223 ) ;
if ( error )
return ( error ) ;
if ( V_223 ) {
* V_220 = 0 ;
} else {
* V_220 = 2 ;
}
return 0 ;
}
V_222 = V_32 . V_13 < V_32 . V_14 ;
for ( V_5 = 0 ; V_5 < 2 ; V_222 = ! V_222 , V_5 ++ ) {
struct V_1 V_202 ;
if ( V_222 )
V_37 = V_32 . V_13 ;
else
V_37 = V_32 . V_14 ;
if ( V_37 == 0 )
continue;
error = F_18 ( V_167 -> args -> V_98 , V_167 -> args -> V_52 ,
V_37 , - 1 , & V_25 ) ;
if ( error )
return ( error ) ;
F_1 ( & V_202 , V_25 -> V_31 ) ;
V_62 = V_167 -> V_213 - ( V_167 -> V_213 >> 2 ) -
V_32 . V_16 - V_202 . V_16 -
( ( V_32 . V_15 + V_202 . V_15 ) *
sizeof( V_179 ) ) -
F_91 ( V_30 ) ;
F_110 ( V_167 -> args -> V_98 , V_25 ) ;
if ( V_62 >= 0 )
break;
}
if ( V_5 >= 2 ) {
* V_220 = 0 ;
return ( 0 ) ;
}
memcpy ( & V_167 -> V_226 , & V_167 -> V_224 , sizeof( V_167 -> V_224 ) ) ;
if ( V_37 < V_221 -> V_37 ) {
error = F_109 ( V_167 , & V_167 -> V_226 , V_222 ,
0 , & V_223 ) ;
} else {
error = F_109 ( V_167 , & V_167 -> V_224 , V_222 ,
0 , & V_223 ) ;
}
if ( error )
return ( error ) ;
if ( V_223 ) {
* V_220 = 0 ;
} else {
* V_220 = 1 ;
}
return ( 0 ) ;
}
int
F_111 (
struct V_24 * V_25 ,
struct V_141 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_132 * V_133 ;
struct V_26 * V_27 = args -> V_98 -> V_177 ;
int V_161 ;
int V_227 ;
int V_228 ;
int V_173 ;
int V_172 ;
int V_175 ;
int V_5 ;
F_112 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( V_32 . V_15 > 0 && V_32 . V_15 < F_74 ( V_27 ) / 8 ) ;
ASSERT ( args -> V_176 >= 0 && args -> V_176 < V_32 . V_15 ) ;
ASSERT ( V_32 . V_17 >= V_32 . V_15 * sizeof( * V_133 ) +
F_91 ( V_30 ) ) ;
V_133 = & F_70 ( V_30 ) [ args -> V_176 ] ;
ASSERT ( F_4 ( V_133 -> V_145 ) >= V_32 . V_17 ) ;
ASSERT ( F_4 ( V_133 -> V_145 ) < F_74 ( V_27 ) ) ;
V_172 = V_32 . V_15 * sizeof( V_179 )
+ F_91 ( V_30 ) ;
V_175 = V_32 . V_20 [ 0 ] . V_22 ;
V_161 = V_227 = - 1 ;
V_228 = V_19 - 1 ;
V_173 = F_99 ( V_30 , args -> V_176 ) ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
ASSERT ( V_32 . V_20 [ V_5 ] . V_21 < F_74 ( V_27 ) ) ;
ASSERT ( V_32 . V_20 [ V_5 ] . V_22 < F_74 ( V_27 ) ) ;
if ( V_32 . V_20 [ V_5 ] . V_21 == V_172 ) {
V_32 . V_20 [ V_5 ] . V_21 -= sizeof( V_179 ) ;
V_32 . V_20 [ V_5 ] . V_22 += sizeof( V_179 ) ;
}
if ( V_32 . V_20 [ V_5 ] . V_21 + V_32 . V_20 [ V_5 ] . V_22 ==
F_4 ( V_133 -> V_145 ) ) {
V_161 = V_5 ;
} else if ( V_32 . V_20 [ V_5 ] . V_21 ==
( F_4 ( V_133 -> V_145 ) + V_173 ) ) {
V_227 = V_5 ;
} else if ( V_32 . V_20 [ V_5 ] . V_22 < V_175 ) {
V_175 = V_32 . V_20 [ V_5 ] . V_22 ;
V_228 = V_5 ;
}
}
if ( ( V_161 >= 0 ) || ( V_227 >= 0 ) ) {
if ( ( V_161 >= 0 ) && ( V_227 >= 0 ) ) {
V_32 . V_20 [ V_161 ] . V_22 += V_173 ;
V_32 . V_20 [ V_161 ] . V_22 += V_32 . V_20 [ V_227 ] . V_22 ;
V_32 . V_20 [ V_227 ] . V_21 = 0 ;
V_32 . V_20 [ V_227 ] . V_22 = 0 ;
} else if ( V_161 >= 0 ) {
V_32 . V_20 [ V_161 ] . V_22 += V_173 ;
} else {
V_32 . V_20 [ V_227 ] . V_21 = F_4 ( V_133 -> V_145 ) ;
V_32 . V_20 [ V_227 ] . V_22 += V_173 ;
}
} else {
if ( V_32 . V_20 [ V_228 ] . V_22 < V_173 ) {
V_32 . V_20 [ V_228 ] . V_21 = F_4 ( V_133 -> V_145 ) ;
V_32 . V_20 [ V_228 ] . V_22 = V_173 ;
}
}
if ( F_4 ( V_133 -> V_145 ) == V_32 . V_17 )
V_228 = 1 ;
else
V_228 = 0 ;
memset ( F_98 ( V_30 , args -> V_176 ) , 0 , V_173 ) ;
V_32 . V_16 -= V_173 ;
F_78 ( args -> V_98 , V_25 ,
F_94 ( V_30 , F_98 ( V_30 , args -> V_176 ) ,
V_173 ) ) ;
V_175 = ( V_32 . V_15 - args -> V_176 ) * sizeof( V_179 ) ;
memmove ( V_133 , V_133 + 1 , V_175 ) ;
V_32 . V_15 -- ;
F_78 ( args -> V_98 , V_25 ,
F_94 ( V_30 , V_133 , V_175 + sizeof( V_179 ) ) ) ;
V_133 = & F_70 ( V_30 ) [ V_32 . V_15 ] ;
memset ( V_133 , 0 , sizeof( V_179 ) ) ;
if ( V_228 ) {
V_175 = F_74 ( V_27 ) ;
V_133 = F_70 ( V_30 ) ;
for ( V_5 = V_32 . V_15 - 1 ; V_5 >= 0 ; V_133 ++ , V_5 -- ) {
ASSERT ( F_4 ( V_133 -> V_145 ) >= V_32 . V_17 ) ;
ASSERT ( F_4 ( V_133 -> V_145 ) < F_74 ( V_27 ) ) ;
if ( F_4 ( V_133 -> V_145 ) < V_175 )
V_175 = F_4 ( V_133 -> V_145 ) ;
}
V_32 . V_17 = V_175 ;
if ( ! V_32 . V_17 )
V_32 . V_17 = V_175 - V_229 ;
} else {
V_32 . V_18 = 1 ;
}
F_5 ( V_30 , & V_32 ) ;
F_78 ( args -> V_98 , V_25 ,
F_94 ( V_30 , & V_30 -> V_6 ,
F_91 ( V_30 ) ) ) ;
V_175 = V_32 . V_16 + F_91 ( V_30 ) +
V_32 . V_15 * sizeof( V_179 ) ;
return V_175 < V_27 -> V_230 ;
}
void
F_113 (
struct V_166 * V_167 ,
struct V_168 * V_231 ,
struct V_168 * V_232 )
{
struct V_3 * V_233 = V_231 -> V_25 -> V_31 ;
struct V_3 * V_234 = V_232 -> V_25 -> V_31 ;
struct V_1 V_235 ;
struct V_1 V_236 ;
struct V_132 * V_133 ;
struct V_26 * V_27 = V_167 -> V_27 ;
F_114 ( V_167 -> args ) ;
V_233 = V_231 -> V_25 -> V_31 ;
V_234 = V_232 -> V_25 -> V_31 ;
F_1 ( & V_235 , V_233 ) ;
F_1 ( & V_236 , V_234 ) ;
V_133 = F_70 ( V_233 ) ;
V_231 -> V_130 = F_3 ( V_133 [ V_235 . V_15 - 1 ] . V_130 ) ;
if ( V_236 . V_18 == 0 ) {
if ( F_102 ( V_232 -> V_25 , & V_236 ,
V_231 -> V_25 , & V_235 ) ) {
F_101 ( V_233 , & V_235 , 0 ,
V_234 , & V_236 , 0 ,
V_235 . V_15 , V_27 ) ;
} else {
F_101 ( V_233 , & V_235 , 0 ,
V_234 , & V_236 ,
V_236 . V_15 , V_235 . V_15 , V_27 ) ;
}
} else {
struct V_3 * V_237 ;
struct V_1 V_238 ;
V_237 = F_115 ( V_167 -> V_213 , V_122 ) ;
memcpy ( V_237 , V_234 , F_91 ( V_234 ) ) ;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_238 . V_8 = V_236 . V_8 ;
V_238 . V_13 = V_236 . V_13 ;
V_238 . V_14 = V_236 . V_14 ;
V_238 . V_17 = V_167 -> V_213 ;
F_5 ( V_237 , & V_238 ) ;
if ( F_102 ( V_232 -> V_25 , & V_236 ,
V_231 -> V_25 , & V_235 ) ) {
F_101 ( V_233 , & V_235 , 0 ,
V_237 , & V_238 , 0 ,
V_235 . V_15 , V_27 ) ;
F_101 ( V_234 , & V_236 , 0 ,
V_237 , & V_238 , V_238 . V_15 ,
V_236 . V_15 , V_27 ) ;
} else {
F_101 ( V_234 , & V_236 , 0 ,
V_237 , & V_238 , 0 ,
V_236 . V_15 , V_27 ) ;
F_101 ( V_233 , & V_235 , 0 ,
V_237 , & V_238 , V_238 . V_15 ,
V_235 . V_15 , V_27 ) ;
}
memcpy ( V_234 , V_237 , V_167 -> V_213 ) ;
V_236 = V_238 ;
F_68 ( V_237 ) ;
}
F_5 ( V_234 , & V_236 ) ;
F_78 ( V_167 -> args -> V_98 , V_232 -> V_25 , 0 ,
V_167 -> V_213 - 1 ) ;
V_133 = F_70 ( V_234 ) ;
V_232 -> V_130 = F_3 ( V_133 [ V_236 . V_15 - 1 ] . V_130 ) ;
}
int
F_66 (
struct V_24 * V_25 ,
struct V_141 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_132 * V_133 ;
struct V_132 * V_147 ;
struct V_142 * V_134 ;
struct V_182 * V_183 ;
T_13 V_130 ;
int V_239 ;
int V_240 ;
F_116 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_147 = F_70 ( V_30 ) ;
ASSERT ( V_32 . V_15 < F_74 ( args -> V_52 -> V_67 ) / 8 ) ;
V_130 = args -> V_130 ;
V_239 = V_240 = V_32 . V_15 / 2 ;
for ( V_133 = & V_147 [ V_239 ] ; V_240 > 4 ; V_133 = & V_147 [ V_239 ] ) {
V_240 /= 2 ;
if ( F_3 ( V_133 -> V_130 ) < V_130 )
V_239 += V_240 ;
else if ( F_3 ( V_133 -> V_130 ) > V_130 )
V_239 -= V_240 ;
else
break;
}
ASSERT ( V_239 >= 0 && ( ! V_32 . V_15 || V_239 < V_32 . V_15 ) ) ;
ASSERT ( V_240 <= 4 || F_3 ( V_133 -> V_130 ) == V_130 ) ;
while ( V_239 > 0 && F_3 ( V_133 -> V_130 ) >= V_130 ) {
V_133 -- ;
V_239 -- ;
}
while ( V_239 < V_32 . V_15 &&
F_3 ( V_133 -> V_130 ) < V_130 ) {
V_133 ++ ;
V_239 ++ ;
}
if ( V_239 == V_32 . V_15 || F_3 ( V_133 -> V_130 ) != V_130 ) {
args -> V_176 = V_239 ;
return F_53 ( V_114 ) ;
}
for (; V_239 < V_32 . V_15 && ( F_3 ( V_133 -> V_130 ) == V_130 ) ;
V_133 ++ , V_239 ++ ) {
if ( ( args -> V_108 & V_137 ) !=
( V_133 -> V_108 & V_137 ) ) {
continue;
}
if ( V_133 -> V_108 & V_138 ) {
V_134 = F_71 ( V_30 , V_239 ) ;
if ( V_134 -> V_105 != args -> V_105 )
continue;
if ( memcmp ( args -> V_106 , V_134 -> V_107 ,
args -> V_105 ) != 0 )
continue;
if ( ! F_21 ( args -> V_108 , V_133 -> V_108 ) )
continue;
args -> V_176 = V_239 ;
return F_53 ( V_117 ) ;
} else {
V_183 = F_96 ( V_30 , V_239 ) ;
if ( V_183 -> V_105 != args -> V_105 )
continue;
if ( memcmp ( args -> V_106 , V_183 -> V_106 ,
args -> V_105 ) != 0 )
continue;
if ( ! F_21 ( args -> V_108 , V_133 -> V_108 ) )
continue;
args -> V_176 = V_239 ;
args -> V_190 = F_3 ( V_183 -> V_109 ) ;
args -> V_188 = F_3 ( V_183 -> V_187 ) ;
args -> V_189 = F_97 (
args -> V_52 -> V_67 ,
args -> V_190 ) ;
return F_53 ( V_117 ) ;
}
}
args -> V_176 = V_239 ;
return F_53 ( V_114 ) ;
}
int
F_117 (
struct V_24 * V_25 ,
struct V_141 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_132 * V_133 ;
struct V_142 * V_134 ;
struct V_182 * V_183 ;
int V_109 ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( V_32 . V_15 < F_74 ( args -> V_52 -> V_67 ) / 8 ) ;
ASSERT ( args -> V_176 < V_32 . V_15 ) ;
V_133 = & F_70 ( V_30 ) [ args -> V_176 ] ;
if ( V_133 -> V_108 & V_138 ) {
V_134 = F_71 ( V_30 , args -> V_176 ) ;
ASSERT ( V_134 -> V_105 == args -> V_105 ) ;
ASSERT ( memcmp ( args -> V_106 , V_134 -> V_107 , args -> V_105 ) == 0 ) ;
V_109 = F_4 ( V_134 -> V_109 ) ;
if ( args -> V_108 & V_118 ) {
args -> V_109 = V_109 ;
return 0 ;
}
if ( args -> V_109 < V_109 ) {
args -> V_109 = V_109 ;
return F_53 ( V_119 ) ;
}
args -> V_109 = V_109 ;
memcpy ( args -> V_110 , & V_134 -> V_107 [ args -> V_105 ] , V_109 ) ;
} else {
V_183 = F_96 ( V_30 , args -> V_176 ) ;
ASSERT ( V_183 -> V_105 == args -> V_105 ) ;
ASSERT ( memcmp ( args -> V_106 , V_183 -> V_106 , args -> V_105 ) == 0 ) ;
args -> V_190 = F_3 ( V_183 -> V_109 ) ;
args -> V_188 = F_3 ( V_183 -> V_187 ) ;
args -> V_189 = F_97 ( args -> V_52 -> V_67 ,
args -> V_190 ) ;
if ( args -> V_108 & V_118 ) {
args -> V_109 = args -> V_190 ;
return 0 ;
}
if ( args -> V_109 < args -> V_190 ) {
args -> V_109 = args -> V_190 ;
return F_53 ( V_119 ) ;
}
args -> V_109 = args -> V_190 ;
}
return 0 ;
}
STATIC void
F_101 (
struct V_3 * V_241 ,
struct V_1 * V_242 ,
int V_243 ,
struct V_3 * V_244 ,
struct V_1 * V_245 ,
int V_246 ,
int V_15 ,
struct V_26 * V_27 )
{
struct V_132 * V_247 ;
struct V_132 * V_248 ;
int V_249 ;
int V_175 ;
int V_5 ;
if ( V_15 == 0 )
return;
ASSERT ( V_242 -> V_8 == V_9 ||
V_242 -> V_8 == V_10 ) ;
ASSERT ( V_242 -> V_8 == V_245 -> V_8 ) ;
ASSERT ( V_242 -> V_15 > 0 && V_242 -> V_15 < F_74 ( V_27 ) / 8 ) ;
ASSERT ( V_242 -> V_17 >= ( V_242 -> V_15 * sizeof( * V_247 ) )
+ F_91 ( V_241 ) ) ;
ASSERT ( V_245 -> V_15 < F_74 ( V_27 ) / 8 ) ;
ASSERT ( V_245 -> V_17 >= ( V_245 -> V_15 * sizeof( * V_248 ) )
+ F_91 ( V_244 ) ) ;
ASSERT ( V_243 < V_242 -> V_15 ) ;
ASSERT ( V_246 <= V_245 -> V_15 ) ;
ASSERT ( V_15 <= V_242 -> V_15 ) ;
if ( V_246 < V_245 -> V_15 ) {
V_175 = V_245 -> V_15 - V_246 ;
V_175 *= sizeof( V_179 ) ;
V_247 = & F_70 ( V_244 ) [ V_246 ] ;
V_248 = & F_70 ( V_244 ) [ V_246 + V_15 ] ;
memmove ( V_248 , V_247 , V_175 ) ;
}
V_247 = & F_70 ( V_241 ) [ V_243 ] ;
V_248 = & F_70 ( V_244 ) [ V_246 ] ;
V_249 = V_246 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_247 ++ , V_248 ++ , V_249 ++ , V_5 ++ ) {
ASSERT ( F_4 ( V_247 -> V_145 ) >= V_242 -> V_17 ) ;
V_175 = F_99 ( V_241 , V_243 + V_5 ) ;
#ifdef F_118
if ( V_247 -> V_108 & V_137 ) {
memset ( F_98 ( V_241 , V_243 + V_5 ) , 0 , V_175 ) ;
V_242 -> V_16 -= V_175 ;
V_242 -> V_15 -= 1 ;
V_248 -- ;
V_249 -- ;
if ( ( V_243 + V_5 ) < V_63 )
V_250 ++ ;
} else {
#endif
V_245 -> V_17 -= V_175 ;
V_248 -> V_130 = V_247 -> V_130 ;
V_248 -> V_145 = F_2 ( V_245 -> V_17 ) ;
V_248 -> V_108 = V_247 -> V_108 ;
ASSERT ( F_4 ( V_248 -> V_145 ) + V_175
<= F_74 ( V_27 ) ) ;
memmove ( F_98 ( V_244 , V_249 ) ,
F_98 ( V_241 , V_243 + V_5 ) , V_175 ) ;
ASSERT ( F_4 ( V_247 -> V_145 ) + V_175
<= F_74 ( V_27 ) ) ;
memset ( F_98 ( V_241 , V_243 + V_5 ) , 0 , V_175 ) ;
V_242 -> V_16 -= V_175 ;
V_245 -> V_16 += V_175 ;
V_242 -> V_15 -= 1 ;
V_245 -> V_15 += 1 ;
V_175 = V_245 -> V_15 * sizeof( V_179 )
+ F_91 ( V_244 ) ;
ASSERT ( V_245 -> V_17 >= V_175 ) ;
#ifdef F_118
}
#endif
}
if ( V_243 == V_242 -> V_15 ) {
V_175 = V_15 * sizeof( V_179 ) ;
V_247 = & F_70 ( V_241 ) [ V_243 ] ;
ASSERT ( ( ( char * ) V_247 + V_175 ) <=
( ( char * ) V_241 + F_74 ( V_27 ) ) ) ;
memset ( V_247 , 0 , V_175 ) ;
} else {
V_175 = ( V_242 -> V_15 - V_15 ) * sizeof( V_179 ) ;
V_247 = & F_70 ( V_241 ) [ V_243 + V_15 ] ;
V_248 = & F_70 ( V_241 ) [ V_243 ] ;
memmove ( V_248 , V_247 , V_175 ) ;
V_175 = V_15 * sizeof( V_179 ) ;
V_247 = & F_70 ( V_241 ) [ V_242 -> V_15 ] ;
ASSERT ( ( ( char * ) V_247 + V_175 ) <=
( ( char * ) V_241 + F_74 ( V_27 ) ) ) ;
memset ( V_247 , 0 , V_175 ) ;
}
V_245 -> V_20 [ 0 ] . V_21 = F_91 ( V_244 ) ;
V_245 -> V_20 [ 0 ] . V_21 += V_245 -> V_15 * sizeof( V_179 ) ;
V_245 -> V_20 [ 0 ] . V_22 = V_245 -> V_17 - V_245 -> V_20 [ 0 ] . V_21 ;
V_245 -> V_20 [ 1 ] . V_21 = 0 ;
V_245 -> V_20 [ 2 ] . V_21 = 0 ;
V_245 -> V_20 [ 1 ] . V_22 = 0 ;
V_245 -> V_20 [ 2 ] . V_22 = 0 ;
V_242 -> V_18 = 1 ;
}
T_13
F_88 (
struct V_24 * V_25 ,
int * V_15 )
{
struct V_1 V_32 ;
struct V_132 * V_147 ;
F_1 ( & V_32 , V_25 -> V_31 ) ;
V_147 = F_70 ( V_25 -> V_31 ) ;
if ( V_15 )
* V_15 = V_32 . V_15 ;
if ( ! V_32 . V_15 )
return 0 ;
return F_3 ( V_147 [ V_32 . V_15 - 1 ] . V_130 ) ;
}
STATIC int
F_99 ( V_144 * V_30 , int V_176 )
{
struct V_132 * V_147 ;
T_11 * V_134 ;
T_14 * V_183 ;
int V_22 ;
V_147 = F_70 ( V_30 ) ;
if ( V_147 [ V_176 ] . V_108 & V_138 ) {
V_134 = F_71 ( V_30 , V_176 ) ;
V_22 = F_119 ( V_134 -> V_105 ,
F_4 ( V_134 -> V_109 ) ) ;
} else {
V_183 = F_96 ( V_30 , V_176 ) ;
V_22 = F_120 ( V_183 -> V_105 ) ;
}
return V_22 ;
}
int
F_90 ( int V_105 , int V_109 , int V_213 , int * V_251 )
{
int V_22 ;
V_22 = F_119 ( V_105 , V_109 ) ;
if ( V_22 < F_121 ( V_213 ) ) {
if ( V_251 ) {
* V_251 = 1 ;
}
} else {
V_22 = F_120 ( V_105 ) ;
if ( V_251 ) {
* V_251 = 0 ;
}
}
return V_22 ;
}
int
F_122 (
struct V_141 * args )
{
struct V_3 * V_30 ;
struct V_132 * V_133 ;
struct V_182 * V_183 ;
struct V_24 * V_25 ;
int error ;
#ifdef F_45
struct V_1 V_32 ;
T_11 * V_134 ;
int V_105 ;
char * V_106 ;
#endif
F_123 ( args ) ;
error = F_18 ( args -> V_98 , args -> V_52 , args -> V_37 , - 1 , & V_25 ) ;
if ( error )
return ( error ) ;
V_30 = V_25 -> V_31 ;
V_133 = & F_70 ( V_30 ) [ args -> V_176 ] ;
ASSERT ( V_133 -> V_108 & V_137 ) ;
#ifdef F_45
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_176 < V_32 . V_15 ) ;
ASSERT ( args -> V_176 >= 0 ) ;
if ( V_133 -> V_108 & V_138 ) {
V_134 = F_71 ( V_30 , args -> V_176 ) ;
V_105 = V_134 -> V_105 ;
V_106 = ( char * ) V_134 -> V_107 ;
} else {
V_183 = F_96 ( V_30 , args -> V_176 ) ;
V_105 = V_183 -> V_105 ;
V_106 = ( char * ) V_183 -> V_106 ;
}
ASSERT ( F_3 ( V_133 -> V_130 ) == args -> V_130 ) ;
ASSERT ( V_105 == args -> V_105 ) ;
ASSERT ( memcmp ( V_106 , args -> V_106 , V_105 ) == 0 ) ;
#endif
V_133 -> V_108 &= ~ V_137 ;
F_78 ( args -> V_98 , V_25 ,
F_94 ( V_30 , V_133 , sizeof( * V_133 ) ) ) ;
if ( args -> V_188 ) {
ASSERT ( ( V_133 -> V_108 & V_138 ) == 0 ) ;
V_183 = F_96 ( V_30 , args -> V_176 ) ;
V_183 -> V_187 = F_6 ( args -> V_188 ) ;
V_183 -> V_109 = F_6 ( args -> V_190 ) ;
F_78 ( args -> V_98 , V_25 ,
F_94 ( V_30 , V_183 , sizeof( * V_183 ) ) ) ;
}
return F_124 ( & args -> V_98 , args -> V_52 ) ;
}
int
F_125 (
struct V_141 * args )
{
struct V_3 * V_30 ;
struct V_132 * V_133 ;
struct V_182 * V_183 ;
struct V_24 * V_25 ;
int error ;
#ifdef F_45
struct V_1 V_32 ;
#endif
F_126 ( args ) ;
error = F_18 ( args -> V_98 , args -> V_52 , args -> V_37 , - 1 , & V_25 ) ;
if ( error )
return ( error ) ;
V_30 = V_25 -> V_31 ;
#ifdef F_45
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_176 < V_32 . V_15 ) ;
ASSERT ( args -> V_176 >= 0 ) ;
#endif
V_133 = & F_70 ( V_30 ) [ args -> V_176 ] ;
ASSERT ( ( V_133 -> V_108 & V_137 ) == 0 ) ;
V_133 -> V_108 |= V_137 ;
F_78 ( args -> V_98 , V_25 ,
F_94 ( V_30 , V_133 , sizeof( * V_133 ) ) ) ;
if ( ( V_133 -> V_108 & V_138 ) == 0 ) {
V_183 = F_96 ( V_30 , args -> V_176 ) ;
V_183 -> V_187 = 0 ;
V_183 -> V_109 = 0 ;
F_78 ( args -> V_98 , V_25 ,
F_94 ( V_30 , V_183 , sizeof( * V_183 ) ) ) ;
}
return F_124 ( & args -> V_98 , args -> V_52 ) ;
}
int
F_127 (
struct V_141 * args )
{
struct V_3 * V_205 ;
struct V_3 * V_206 ;
struct V_132 * V_252 ;
struct V_132 * V_253 ;
struct V_182 * V_183 ;
struct V_24 * V_154 ;
struct V_24 * V_155 ;
int error ;
#ifdef F_45
struct V_1 V_201 ;
struct V_1 V_202 ;
T_11 * V_134 ;
int V_254 , V_255 ;
char * V_256 , * V_257 ;
#endif
F_128 ( args ) ;
error = F_18 ( args -> V_98 , args -> V_52 , args -> V_37 , - 1 , & V_154 ) ;
if ( error )
return error ;
if ( args -> V_185 != args -> V_37 ) {
error = F_18 ( args -> V_98 , args -> V_52 , args -> V_185 ,
- 1 , & V_155 ) ;
if ( error )
return error ;
} else {
V_155 = V_154 ;
}
V_205 = V_154 -> V_31 ;
V_252 = & F_70 ( V_205 ) [ args -> V_176 ] ;
V_206 = V_155 -> V_31 ;
V_253 = & F_70 ( V_206 ) [ args -> V_186 ] ;
#ifdef F_45
F_1 ( & V_201 , V_205 ) ;
ASSERT ( args -> V_176 < V_201 . V_15 ) ;
ASSERT ( args -> V_176 >= 0 ) ;
F_1 ( & V_202 , V_206 ) ;
ASSERT ( args -> V_186 < V_202 . V_15 ) ;
ASSERT ( args -> V_186 >= 0 ) ;
if ( V_252 -> V_108 & V_138 ) {
V_134 = F_71 ( V_205 , args -> V_176 ) ;
V_254 = V_134 -> V_105 ;
V_256 = ( char * ) V_134 -> V_107 ;
} else {
V_183 = F_96 ( V_205 , args -> V_176 ) ;
V_254 = V_183 -> V_105 ;
V_256 = ( char * ) V_183 -> V_106 ;
}
if ( V_253 -> V_108 & V_138 ) {
V_134 = F_71 ( V_206 , args -> V_186 ) ;
V_255 = V_134 -> V_105 ;
V_257 = ( char * ) V_134 -> V_107 ;
} else {
V_183 = F_96 ( V_206 , args -> V_186 ) ;
V_255 = V_183 -> V_105 ;
V_257 = ( char * ) V_183 -> V_106 ;
}
ASSERT ( F_3 ( V_252 -> V_130 ) == F_3 ( V_253 -> V_130 ) ) ;
ASSERT ( V_254 == V_255 ) ;
ASSERT ( memcmp ( V_256 , V_257 , V_254 ) == 0 ) ;
#endif
ASSERT ( V_252 -> V_108 & V_137 ) ;
ASSERT ( ( V_253 -> V_108 & V_137 ) == 0 ) ;
V_252 -> V_108 &= ~ V_137 ;
F_78 ( args -> V_98 , V_154 ,
F_94 ( V_205 , V_252 , sizeof( * V_252 ) ) ) ;
if ( args -> V_188 ) {
ASSERT ( ( V_252 -> V_108 & V_138 ) == 0 ) ;
V_183 = F_96 ( V_205 , args -> V_176 ) ;
V_183 -> V_187 = F_6 ( args -> V_188 ) ;
V_183 -> V_109 = F_6 ( args -> V_190 ) ;
F_78 ( args -> V_98 , V_154 ,
F_94 ( V_205 , V_183 , sizeof( * V_183 ) ) ) ;
}
V_253 -> V_108 |= V_137 ;
F_78 ( args -> V_98 , V_155 ,
F_94 ( V_206 , V_253 , sizeof( * V_253 ) ) ) ;
if ( ( V_253 -> V_108 & V_138 ) == 0 ) {
V_183 = F_96 ( V_206 , args -> V_186 ) ;
V_183 -> V_187 = 0 ;
V_183 -> V_109 = 0 ;
F_78 ( args -> V_98 , V_155 ,
F_94 ( V_206 , V_183 , sizeof( * V_183 ) ) ) ;
}
error = F_124 ( & args -> V_98 , args -> V_52 ) ;
return error ;
}
