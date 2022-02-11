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
F_37 ( V_50 ) ;
} else
F_36 ( & V_27 -> V_85 ) ;
}
}
void
F_38 ( T_6 * args )
{
T_7 * V_6 ;
T_3 * V_52 ;
T_8 * V_86 ;
F_39 ( args ) ;
V_52 = args -> V_52 ;
ASSERT ( V_52 != NULL ) ;
V_86 = V_52 -> V_87 ;
ASSERT ( V_86 != NULL ) ;
ASSERT ( V_86 -> V_79 == 0 ) ;
if ( V_52 -> V_68 . V_88 == V_80 ) {
V_86 -> V_89 &= ~ V_90 ;
V_52 -> V_68 . V_88 = V_91 ;
V_86 -> V_89 |= V_92 ;
} else {
ASSERT ( V_86 -> V_89 & V_92 ) ;
}
F_40 ( V_52 , sizeof( * V_6 ) , V_57 ) ;
V_6 = ( T_7 * ) V_86 -> V_93 . V_94 ;
V_6 -> V_15 = 0 ;
V_6 -> V_95 = F_2 ( sizeof( * V_6 ) ) ;
F_41 ( args -> V_96 , V_52 , V_97 | V_98 ) ;
}
void
F_42 ( T_6 * args , int V_99 )
{
T_9 * V_100 ;
T_10 * V_101 ;
int V_5 , V_63 , V_22 ;
T_4 * V_27 ;
T_3 * V_52 ;
T_8 * V_86 ;
F_43 ( args ) ;
V_52 = args -> V_52 ;
V_27 = V_52 -> V_67 ;
V_52 -> V_68 . V_75 = V_99 ;
V_86 = V_52 -> V_87 ;
ASSERT ( V_86 -> V_89 & V_92 ) ;
V_100 = ( T_9 * ) V_86 -> V_93 . V_94 ;
V_101 = & V_100 -> V_102 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_100 -> V_6 . V_15 ; V_101 = F_44 ( V_101 ) , V_5 ++ ) {
#ifdef F_45
if ( V_101 -> V_103 != args -> V_103 )
continue;
if ( memcmp ( args -> V_104 , V_101 -> V_105 , args -> V_103 ) != 0 )
continue;
if ( ! F_21 ( args -> V_106 , V_101 -> V_106 ) )
continue;
ASSERT ( 0 ) ;
#endif
}
V_63 = ( char * ) V_101 - ( char * ) V_100 ;
V_22 = F_46 ( args -> V_103 , args -> V_107 ) ;
F_40 ( V_52 , V_22 , V_57 ) ;
V_100 = ( T_9 * ) V_86 -> V_93 . V_94 ;
V_101 = ( T_10 * ) ( ( char * ) V_100 + V_63 ) ;
V_101 -> V_103 = args -> V_103 ;
V_101 -> V_107 = args -> V_107 ;
V_101 -> V_106 = F_23 ( args -> V_106 ) ;
memcpy ( V_101 -> V_105 , args -> V_104 , args -> V_103 ) ;
memcpy ( & V_101 -> V_105 [ args -> V_103 ] , args -> V_108 , args -> V_107 ) ;
V_100 -> V_6 . V_15 ++ ;
F_47 ( & V_100 -> V_6 . V_95 , V_22 ) ;
F_41 ( args -> V_96 , V_52 , V_97 | V_98 ) ;
F_32 ( V_27 , args -> V_96 ) ;
}
STATIC void
F_48 (
struct V_51 * V_109 ,
struct V_49 * V_50 )
{
F_49 ( V_109 , V_57 ) ;
V_109 -> V_68 . V_75 = 0 ;
V_109 -> V_68 . V_88 = V_80 ;
ASSERT ( V_109 -> V_68 . V_110 == 0 ) ;
ASSERT ( V_109 -> V_87 == NULL ) ;
F_41 ( V_50 , V_109 , V_97 ) ;
}
int
F_50 ( T_6 * args )
{
T_9 * V_100 ;
T_10 * V_101 ;
int V_21 , V_22 = 0 , V_111 , V_95 , V_5 ;
T_4 * V_27 ;
T_3 * V_52 ;
F_51 ( args ) ;
V_52 = args -> V_52 ;
V_27 = V_52 -> V_67 ;
V_21 = sizeof( T_7 ) ;
V_100 = ( T_9 * ) V_52 -> V_87 -> V_93 . V_94 ;
V_101 = & V_100 -> V_102 [ 0 ] ;
V_111 = V_100 -> V_6 . V_15 ;
for ( V_5 = 0 ; V_5 < V_111 ; V_101 = F_44 ( V_101 ) ,
V_21 += V_22 , V_5 ++ ) {
V_22 = F_52 ( V_101 ) ;
if ( V_101 -> V_103 != args -> V_103 )
continue;
if ( memcmp ( V_101 -> V_105 , args -> V_104 , args -> V_103 ) != 0 )
continue;
if ( ! F_21 ( args -> V_106 , V_101 -> V_106 ) )
continue;
break;
}
if ( V_5 == V_111 )
return - V_112 ;
V_111 = V_21 + V_22 ;
V_95 = F_4 ( V_100 -> V_6 . V_95 ) ;
if ( V_111 != V_95 )
memmove ( & ( ( char * ) V_100 ) [ V_21 ] , & ( ( char * ) V_100 ) [ V_111 ] , V_95 - V_111 ) ;
V_100 -> V_6 . V_15 -- ;
F_47 ( & V_100 -> V_6 . V_95 , - V_22 ) ;
V_95 -= V_22 ;
if ( V_95 == sizeof( T_7 ) &&
( V_27 -> V_76 & V_77 ) &&
( V_52 -> V_68 . V_70 != V_82 ) &&
! ( args -> V_113 & V_114 ) ) {
F_48 ( V_52 , args -> V_96 ) ;
} else {
F_40 ( V_52 , - V_22 , V_57 ) ;
V_52 -> V_68 . V_75 = F_24 ( V_52 , V_95 ) ;
ASSERT ( V_52 -> V_68 . V_75 ) ;
ASSERT ( V_95 > sizeof( T_7 ) ||
( args -> V_113 & V_114 ) ||
! ( V_27 -> V_76 & V_77 ) ||
V_52 -> V_68 . V_70 == V_82 ) ;
F_41 ( args -> V_96 , V_52 ,
V_97 | V_98 ) ;
}
F_32 ( V_27 , args -> V_96 ) ;
return 0 ;
}
int
F_53 ( T_6 * args )
{
T_9 * V_100 ;
T_10 * V_101 ;
int V_5 ;
T_8 * V_86 ;
F_54 ( args ) ;
V_86 = args -> V_52 -> V_87 ;
ASSERT ( V_86 -> V_89 & V_92 ) ;
V_100 = ( T_9 * ) V_86 -> V_93 . V_94 ;
V_101 = & V_100 -> V_102 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_100 -> V_6 . V_15 ;
V_101 = F_44 ( V_101 ) , V_5 ++ ) {
if ( V_101 -> V_103 != args -> V_103 )
continue;
if ( memcmp ( args -> V_104 , V_101 -> V_105 , args -> V_103 ) != 0 )
continue;
if ( ! F_21 ( args -> V_106 , V_101 -> V_106 ) )
continue;
return - V_115 ;
}
return - V_112 ;
}
int
F_55 ( T_6 * args )
{
T_9 * V_100 ;
T_10 * V_101 ;
int V_5 ;
ASSERT ( args -> V_52 -> V_87 -> V_89 == V_92 ) ;
V_100 = ( T_9 * ) args -> V_52 -> V_87 -> V_93 . V_94 ;
V_101 = & V_100 -> V_102 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_100 -> V_6 . V_15 ;
V_101 = F_44 ( V_101 ) , V_5 ++ ) {
if ( V_101 -> V_103 != args -> V_103 )
continue;
if ( memcmp ( args -> V_104 , V_101 -> V_105 , args -> V_103 ) != 0 )
continue;
if ( ! F_21 ( args -> V_106 , V_101 -> V_106 ) )
continue;
if ( args -> V_106 & V_116 ) {
args -> V_107 = V_101 -> V_107 ;
return - V_115 ;
}
if ( args -> V_107 < V_101 -> V_107 ) {
args -> V_107 = V_101 -> V_107 ;
return - V_117 ;
}
args -> V_107 = V_101 -> V_107 ;
memcpy ( args -> V_108 , & V_101 -> V_105 [ args -> V_103 ] ,
args -> V_107 ) ;
return - V_115 ;
}
return - V_112 ;
}
int
F_56 ( T_6 * args )
{
T_3 * V_52 ;
T_9 * V_100 ;
T_10 * V_101 ;
T_6 V_118 ;
char * V_119 ;
int error , V_5 , V_22 ;
T_1 V_37 ;
struct V_24 * V_25 ;
T_8 * V_86 ;
F_57 ( args ) ;
V_52 = args -> V_52 ;
V_86 = V_52 -> V_87 ;
V_100 = ( T_9 * ) V_86 -> V_93 . V_94 ;
V_22 = F_4 ( V_100 -> V_6 . V_95 ) ;
V_119 = F_58 ( V_22 , V_120 ) ;
ASSERT ( V_119 != NULL ) ;
memcpy ( V_119 , V_86 -> V_93 . V_94 , V_22 ) ;
V_100 = ( T_9 * ) V_119 ;
F_40 ( V_52 , - V_22 , V_57 ) ;
F_59 ( V_52 , V_57 ) ;
V_25 = NULL ;
error = F_60 ( args , & V_37 ) ;
if ( error ) {
if ( error == - V_121 )
goto V_122;
F_40 ( V_52 , V_22 , V_57 ) ;
memcpy ( V_86 -> V_93 . V_94 , V_119 , V_22 ) ;
goto V_122;
}
ASSERT ( V_37 == 0 ) ;
error = F_61 ( args , V_37 , & V_25 ) ;
if ( error ) {
error = F_62 ( args , 0 , V_25 ) ;
V_25 = NULL ;
if ( error )
goto V_122;
F_40 ( V_52 , V_22 , V_57 ) ;
memcpy ( V_86 -> V_93 . V_94 , V_119 , V_22 ) ;
goto V_122;
}
memset ( ( char * ) & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_52 = V_52 ;
V_118 . V_123 = args -> V_123 ;
V_118 . V_124 = args -> V_124 ;
V_118 . V_125 = args -> V_125 ;
V_118 . V_126 = args -> V_126 ;
V_118 . V_127 = V_57 ;
V_118 . V_96 = args -> V_96 ;
V_118 . V_113 = V_128 ;
V_101 = & V_100 -> V_102 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_100 -> V_6 . V_15 ; V_5 ++ ) {
V_118 . V_104 = V_101 -> V_105 ;
V_118 . V_103 = V_101 -> V_103 ;
V_118 . V_108 = & V_101 -> V_105 [ V_118 . V_103 ] ;
V_118 . V_107 = V_101 -> V_107 ;
V_118 . V_129 = F_63 ( V_101 -> V_105 ,
V_101 -> V_103 ) ;
V_118 . V_106 = F_64 ( V_101 -> V_106 ) ;
error = F_65 ( V_25 , & V_118 ) ;
ASSERT ( error == - V_112 ) ;
error = F_66 ( V_25 , & V_118 ) ;
ASSERT ( error != - V_130 ) ;
if ( error )
goto V_122;
V_101 = F_44 ( V_101 ) ;
}
error = 0 ;
V_122:
F_67 ( V_119 ) ;
return error ;
}
int
F_68 (
struct V_24 * V_25 ,
struct V_51 * V_52 )
{
struct V_3 * V_30 ;
struct V_131 * V_132 ;
T_11 * V_133 ;
struct V_1 V_134 ;
int V_62 ;
int V_5 ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_134 , V_30 ) ;
V_132 = F_69 ( V_30 ) ;
V_62 = sizeof( struct V_135 ) ;
for ( V_5 = 0 ; V_5 < V_134 . V_15 ; V_132 ++ , V_5 ++ ) {
if ( V_132 -> V_106 & V_136 )
continue;
if ( ! ( V_132 -> V_106 & V_137 ) )
return 0 ;
V_133 = F_70 ( V_30 , V_5 ) ;
if ( V_133 -> V_103 >= V_138 )
return 0 ;
if ( F_4 ( V_133 -> V_107 ) >= V_138 )
return 0 ;
V_62 += sizeof( struct V_139 ) - 1
+ V_133 -> V_103
+ F_4 ( V_133 -> V_107 ) ;
}
if ( ( V_52 -> V_67 -> V_76 & V_77 ) &&
( V_52 -> V_68 . V_70 != V_82 ) &&
( V_62 == sizeof( struct V_135 ) ) )
return - 1 ;
return F_24 ( V_52 , V_62 ) ;
}
int
F_71 (
struct V_24 * V_25 ,
struct V_140 * args ,
int V_99 )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_131 * V_132 ;
struct V_141 * V_133 ;
struct V_140 V_118 ;
struct V_51 * V_52 = args -> V_52 ;
char * V_119 ;
int error ;
int V_5 ;
F_72 ( args ) ;
V_119 = F_58 ( args -> V_123 -> V_142 , V_120 ) ;
if ( ! V_119 )
return - V_143 ;
memcpy ( V_119 , V_25 -> V_31 , args -> V_123 -> V_142 ) ;
V_30 = ( V_144 * ) V_119 ;
F_1 ( & V_32 , V_30 ) ;
V_132 = F_69 ( V_30 ) ;
memset ( V_25 -> V_31 , 0 , args -> V_123 -> V_142 ) ;
error = F_62 ( args , 0 , V_25 ) ;
if ( error )
goto V_122;
if ( V_99 == - 1 ) {
ASSERT ( V_52 -> V_67 -> V_76 & V_77 ) ;
ASSERT ( V_52 -> V_68 . V_70 != V_82 ) ;
F_48 ( V_52 , args -> V_96 ) ;
goto V_122;
}
F_38 ( args ) ;
memset ( ( char * ) & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_123 = args -> V_123 ;
V_118 . V_52 = V_52 ;
V_118 . V_124 = args -> V_124 ;
V_118 . V_125 = args -> V_125 ;
V_118 . V_126 = args -> V_126 ;
V_118 . V_127 = V_57 ;
V_118 . V_96 = args -> V_96 ;
V_118 . V_113 = V_128 ;
for ( V_5 = 0 ; V_5 < V_32 . V_15 ; V_132 ++ , V_5 ++ ) {
if ( V_132 -> V_106 & V_136 )
continue;
if ( ! V_132 -> V_145 )
continue;
ASSERT ( V_132 -> V_106 & V_137 ) ;
V_133 = F_70 ( V_30 , V_5 ) ;
V_118 . V_104 = V_133 -> V_105 ;
V_118 . V_103 = V_133 -> V_103 ;
V_118 . V_108 = & V_133 -> V_105 [ V_118 . V_103 ] ;
V_118 . V_107 = F_4 ( V_133 -> V_107 ) ;
V_118 . V_129 = F_3 ( V_132 -> V_129 ) ;
V_118 . V_106 = F_64 ( V_132 -> V_106 ) ;
F_42 ( & V_118 , V_99 ) ;
}
error = 0 ;
V_122:
F_67 ( V_119 ) ;
return error ;
}
int
F_73 (
struct V_140 * args )
{
struct V_3 * V_30 ;
struct V_1 V_146 ;
struct V_131 * V_147 ;
struct V_148 * V_149 ;
struct V_150 V_151 ;
struct V_152 * V_153 ;
struct V_51 * V_52 = args -> V_52 ;
struct V_26 * V_27 = V_52 -> V_67 ;
struct V_24 * V_154 = NULL ;
struct V_24 * V_155 = NULL ;
T_1 V_37 ;
int error ;
F_74 ( args ) ;
error = F_60 ( args , & V_37 ) ;
if ( error )
goto V_122;
error = F_18 ( args -> V_96 , V_52 , 0 , - 1 , & V_154 ) ;
if ( error )
goto V_122;
error = F_75 ( args -> V_96 , V_52 , V_37 , - 1 , & V_155 , V_57 ) ;
if ( error )
goto V_122;
F_20 ( args -> V_96 , V_155 , V_59 ) ;
V_155 -> V_156 = V_154 -> V_156 ;
memcpy ( V_155 -> V_31 , V_154 -> V_31 , args -> V_123 -> V_142 ) ;
if ( F_8 ( & V_27 -> V_33 ) ) {
struct V_157 * V_12 = V_155 -> V_31 ;
V_12 -> V_37 = F_14 ( V_155 -> V_38 ) ;
}
F_76 ( args -> V_96 , V_155 , 0 , args -> V_123 -> V_142 - 1 ) ;
error = F_77 ( args , 0 , 1 , & V_154 , V_57 ) ;
if ( error )
goto V_122;
V_153 = V_154 -> V_31 ;
V_52 -> V_158 -> V_159 ( & V_151 , V_153 ) ;
V_149 = V_52 -> V_158 -> V_160 ( V_153 ) ;
V_30 = V_155 -> V_31 ;
F_1 ( & V_146 , V_30 ) ;
V_147 = F_69 ( V_30 ) ;
V_149 [ 0 ] . V_129 = V_147 [ V_146 . V_15 - 1 ] . V_129 ;
V_149 [ 0 ] . V_161 = F_6 ( V_37 ) ;
V_151 . V_15 = 1 ;
V_52 -> V_158 -> V_162 ( V_153 , & V_151 ) ;
F_76 ( args -> V_96 , V_154 , 0 , args -> V_123 -> V_142 - 1 ) ;
error = 0 ;
V_122:
return error ;
}
STATIC int
F_61 (
struct V_140 * args ,
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
error = F_75 ( args -> V_96 , args -> V_52 , V_37 , - 1 , & V_25 ,
V_57 ) ;
if ( error )
return error ;
V_25 -> V_156 = & V_58 ;
F_20 ( args -> V_96 , V_25 , V_59 ) ;
V_30 = V_25 -> V_31 ;
memset ( V_30 , 0 , args -> V_123 -> V_142 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_17 = args -> V_123 -> V_142 ;
if ( F_8 ( & V_27 -> V_33 ) ) {
struct V_157 * V_12 = V_25 -> V_31 ;
V_32 . V_8 = V_10 ;
V_12 -> V_37 = F_14 ( V_25 -> V_38 ) ;
V_12 -> V_163 = F_14 ( V_52 -> V_164 ) ;
F_79 ( & V_12 -> V_35 , & V_27 -> V_33 . V_36 ) ;
V_32 . V_20 [ 0 ] . V_21 = sizeof( struct V_11 ) ;
} else {
V_32 . V_8 = V_9 ;
V_32 . V_20 [ 0 ] . V_21 = sizeof( struct V_165 ) ;
}
V_32 . V_20 [ 0 ] . V_22 = V_32 . V_17 - V_32 . V_20 [ 0 ] . V_21 ;
F_5 ( V_30 , & V_32 ) ;
F_76 ( args -> V_96 , V_25 , 0 , args -> V_123 -> V_142 - 1 ) ;
* V_55 = V_25 ;
return 0 ;
}
int
F_80 (
struct V_166 * V_167 ,
struct V_168 * V_169 ,
struct V_168 * V_170 )
{
T_1 V_37 ;
int error ;
F_81 ( V_167 -> args ) ;
ASSERT ( V_169 -> V_8 == V_9 ) ;
error = F_60 ( V_167 -> args , & V_37 ) ;
if ( error )
return error ;
error = F_61 ( V_167 -> args , V_37 , & V_170 -> V_25 ) ;
if ( error )
return error ;
V_170 -> V_37 = V_37 ;
V_170 -> V_8 = V_9 ;
F_82 ( V_167 , V_169 , V_170 ) ;
error = F_83 ( V_167 , V_169 , V_170 ) ;
if ( error )
return error ;
if ( V_167 -> V_171 ) {
F_84 ( V_167 -> args ) ;
error = F_66 ( V_169 -> V_25 , V_167 -> args ) ;
} else {
F_85 ( V_167 -> args ) ;
error = F_66 ( V_170 -> V_25 , V_167 -> args ) ;
}
V_169 -> V_129 = F_86 ( V_169 -> V_25 , NULL ) ;
V_170 -> V_129 = F_86 ( V_170 -> V_25 , NULL ) ;
return error ;
}
int
F_66 (
struct V_24 * V_25 ,
struct V_140 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
int V_172 ;
int V_173 ;
int V_174 ;
int V_175 ;
int V_5 ;
F_87 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_176 >= 0 && args -> V_176 <= V_32 . V_15 ) ;
V_173 = F_88 ( args , NULL ) ;
V_172 = ( V_32 . V_15 + 1 ) * sizeof( V_177 )
+ F_89 ( V_30 ) ;
for ( V_174 = 0 , V_5 = V_19 - 1 ; V_5 >= 0 ; V_5 -- ) {
if ( V_172 > V_32 . V_17 ) {
V_174 += V_32 . V_20 [ V_5 ] . V_22 ;
continue;
}
if ( ! V_32 . V_20 [ V_5 ] . V_22 )
continue;
V_175 = V_173 ;
if ( V_32 . V_20 [ V_5 ] . V_21 < V_32 . V_17 )
V_175 += sizeof( V_177 ) ;
if ( V_32 . V_20 [ V_5 ] . V_22 >= V_175 ) {
V_175 = F_90 ( V_25 , & V_32 , args , V_5 ) ;
goto V_178;
}
V_174 += V_32 . V_20 [ V_5 ] . V_22 ;
}
if ( ! V_32 . V_18 && V_174 < V_173 )
return - V_130 ;
F_91 ( args , & V_32 , V_25 ) ;
if ( V_32 . V_20 [ 0 ] . V_22 < ( V_173 + sizeof( V_177 ) ) ) {
V_175 = - V_130 ;
goto V_178;
}
V_175 = F_90 ( V_25 , & V_32 , args , 0 ) ;
V_178:
F_5 ( V_30 , & V_32 ) ;
F_76 ( args -> V_96 , V_25 ,
F_92 ( V_30 , & V_30 -> V_6 ,
F_89 ( V_30 ) ) ) ;
return V_175 ;
}
STATIC int
F_90 (
struct V_24 * V_25 ,
struct V_1 * V_32 ,
struct V_140 * args ,
int V_179 )
{
struct V_3 * V_30 ;
struct V_131 * V_132 ;
struct V_141 * V_133 ;
struct V_180 * V_181 ;
struct V_26 * V_27 ;
int V_175 ;
int V_5 ;
F_93 ( args ) ;
V_30 = V_25 -> V_31 ;
ASSERT ( V_179 >= 0 && V_179 < V_19 ) ;
ASSERT ( args -> V_176 >= 0 && args -> V_176 <= V_32 -> V_15 ) ;
V_132 = & F_69 ( V_30 ) [ args -> V_176 ] ;
if ( args -> V_176 < V_32 -> V_15 ) {
V_175 = V_32 -> V_15 - args -> V_176 ;
V_175 *= sizeof( V_177 ) ;
memmove ( V_132 + 1 , V_132 , V_175 ) ;
F_76 ( args -> V_96 , V_25 ,
F_92 ( V_30 , V_132 , V_175 + sizeof( * V_132 ) ) ) ;
}
V_32 -> V_15 ++ ;
V_27 = args -> V_96 -> V_182 ;
ASSERT ( V_32 -> V_20 [ V_179 ] . V_21 < args -> V_123 -> V_142 ) ;
ASSERT ( ( V_32 -> V_20 [ V_179 ] . V_21 & 0x3 ) == 0 ) ;
ASSERT ( V_32 -> V_20 [ V_179 ] . V_22 >=
F_88 ( args , NULL ) ) ;
ASSERT ( V_32 -> V_20 [ V_179 ] . V_22 < args -> V_123 -> V_142 ) ;
ASSERT ( ( V_32 -> V_20 [ V_179 ] . V_22 & 0x3 ) == 0 ) ;
V_32 -> V_20 [ V_179 ] . V_22 -= F_88 ( args , & V_175 ) ;
V_132 -> V_145 = F_2 ( V_32 -> V_20 [ V_179 ] . V_21 +
V_32 -> V_20 [ V_179 ] . V_22 ) ;
V_132 -> V_129 = F_6 ( args -> V_129 ) ;
V_132 -> V_106 = V_175 ? V_137 : 0 ;
V_132 -> V_106 |= F_23 ( args -> V_106 ) ;
if ( args -> V_113 & V_183 ) {
V_132 -> V_106 |= V_136 ;
if ( ( args -> V_184 == args -> V_37 ) &&
( args -> V_185 <= args -> V_176 ) ) {
args -> V_185 ++ ;
}
}
F_76 ( args -> V_96 , V_25 ,
F_92 ( V_30 , V_132 , sizeof( * V_132 ) ) ) ;
ASSERT ( ( args -> V_176 == 0 ) ||
( F_3 ( V_132 -> V_129 ) >= F_3 ( ( V_132 - 1 ) -> V_129 ) ) ) ;
ASSERT ( ( args -> V_176 == V_32 -> V_15 - 1 ) ||
( F_3 ( V_132 -> V_129 ) <= F_3 ( ( V_132 + 1 ) -> V_129 ) ) ) ;
if ( V_132 -> V_106 & V_137 ) {
V_133 = F_70 ( V_30 , args -> V_176 ) ;
V_133 -> V_103 = args -> V_103 ;
V_133 -> V_107 = F_2 ( args -> V_107 ) ;
memcpy ( ( char * ) V_133 -> V_105 , args -> V_104 , args -> V_103 ) ;
memcpy ( ( char * ) & V_133 -> V_105 [ args -> V_103 ] , args -> V_108 ,
F_4 ( V_133 -> V_107 ) ) ;
} else {
V_181 = F_94 ( V_30 , args -> V_176 ) ;
V_181 -> V_103 = args -> V_103 ;
memcpy ( ( char * ) V_181 -> V_104 , args -> V_104 , args -> V_103 ) ;
V_132 -> V_106 |= V_136 ;
V_181 -> V_107 = 0 ;
V_181 -> V_186 = 0 ;
args -> V_187 = 1 ;
args -> V_188 = F_95 ( V_27 , args -> V_107 ) ;
args -> V_189 = args -> V_107 ;
}
F_76 ( args -> V_96 , V_25 ,
F_92 ( V_30 , F_96 ( V_30 , args -> V_176 ) ,
F_97 ( V_30 , args -> V_176 ) ) ) ;
if ( F_4 ( V_132 -> V_145 ) < V_32 -> V_17 )
V_32 -> V_17 = F_4 ( V_132 -> V_145 ) ;
ASSERT ( V_32 -> V_17 >= V_32 -> V_15 * sizeof( V_177 )
+ F_89 ( V_30 ) ) ;
V_175 = ( V_32 -> V_15 - 1 ) * sizeof( V_177 )
+ F_89 ( V_30 ) ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
if ( V_32 -> V_20 [ V_5 ] . V_21 == V_175 ) {
V_32 -> V_20 [ V_5 ] . V_21 += sizeof( V_177 ) ;
V_32 -> V_20 [ V_5 ] . V_22 -= sizeof( V_177 ) ;
}
}
V_32 -> V_16 += F_97 ( V_30 , args -> V_176 ) ;
return 0 ;
}
STATIC void
F_91 (
struct V_140 * args ,
struct V_1 * V_190 ,
struct V_24 * V_25 )
{
struct V_3 * V_191 ;
struct V_3 * V_192 ;
struct V_1 V_193 ;
struct V_49 * V_96 = args -> V_96 ;
char * V_119 ;
F_98 ( args ) ;
V_119 = F_58 ( args -> V_123 -> V_142 , V_120 ) ;
memcpy ( V_119 , V_25 -> V_31 , args -> V_123 -> V_142 ) ;
memset ( V_25 -> V_31 , 0 , args -> V_123 -> V_142 ) ;
V_191 = ( V_144 * ) V_119 ;
V_192 = V_25 -> V_31 ;
memcpy ( V_25 -> V_31 , V_119 , F_89 ( V_191 ) ) ;
V_193 = * V_190 ;
V_190 -> V_17 = args -> V_123 -> V_142 ;
V_190 -> V_16 = 0 ;
V_190 -> V_15 = 0 ;
V_190 -> V_18 = 0 ;
V_190 -> V_20 [ 0 ] . V_21 = F_89 ( V_191 ) ;
V_190 -> V_20 [ 0 ] . V_22 = V_190 -> V_17 -
V_190 -> V_20 [ 0 ] . V_21 ;
F_5 ( V_192 , V_190 ) ;
F_99 ( args , V_191 , & V_193 , 0 ,
V_192 , V_190 , 0 , V_193 . V_15 ) ;
F_76 ( V_96 , V_25 , 0 , args -> V_123 -> V_142 - 1 ) ;
F_67 ( V_119 ) ;
}
static int
F_100 (
struct V_24 * V_194 ,
struct V_1 * V_195 ,
struct V_24 * V_196 ,
struct V_1 * V_197 )
{
struct V_131 * V_198 ;
struct V_131 * V_199 ;
V_198 = F_69 ( V_194 -> V_31 ) ;
V_199 = F_69 ( V_196 -> V_31 ) ;
if ( V_195 -> V_15 > 0 && V_197 -> V_15 > 0 &&
( ( F_3 ( V_199 [ 0 ] . V_129 ) <
F_3 ( V_198 [ 0 ] . V_129 ) ) ||
( F_3 ( V_199 [ V_197 -> V_15 - 1 ] . V_129 ) <
F_3 ( V_198 [ V_195 -> V_15 - 1 ] . V_129 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_101 (
struct V_24 * V_194 ,
struct V_24 * V_196 )
{
struct V_1 V_200 ;
struct V_1 V_201 ;
F_1 ( & V_200 , V_194 -> V_31 ) ;
F_1 ( & V_201 , V_196 -> V_31 ) ;
return F_100 ( V_194 , & V_200 , V_196 , & V_201 ) ;
}
STATIC void
F_82 (
struct V_166 * V_167 ,
struct V_168 * V_202 ,
struct V_168 * V_203 )
{
struct V_140 * args ;
struct V_3 * V_204 ;
struct V_3 * V_205 ;
struct V_1 V_200 ;
struct V_1 V_201 ;
struct V_131 * V_198 ;
struct V_131 * V_199 ;
int V_15 ;
int V_206 ;
int V_207 ;
int V_208 ;
int V_209 ;
ASSERT ( V_202 -> V_8 == V_9 ) ;
ASSERT ( V_203 -> V_8 == V_9 ) ;
V_204 = V_202 -> V_25 -> V_31 ;
V_205 = V_203 -> V_25 -> V_31 ;
F_1 ( & V_200 , V_204 ) ;
F_1 ( & V_201 , V_205 ) ;
ASSERT ( V_201 . V_15 == 0 ) ;
args = V_167 -> args ;
F_102 ( args ) ;
V_209 = 0 ;
if ( F_100 ( V_202 -> V_25 , & V_200 , V_203 -> V_25 , & V_201 ) ) {
struct V_168 * V_210 ;
struct V_1 V_211 ;
V_210 = V_202 ;
V_202 = V_203 ;
V_203 = V_210 ;
V_211 = V_200 ;
V_200 = V_201 ;
V_201 = V_211 ;
V_204 = V_202 -> V_25 -> V_31 ;
V_205 = V_203 -> V_25 -> V_31 ;
V_209 = 1 ;
}
V_167 -> V_171 = F_103 ( V_167 , V_202 , & V_200 ,
V_203 , & V_201 ,
& V_15 , & V_206 ) ;
if ( V_209 )
V_167 -> V_171 = ! V_167 -> V_171 ;
if ( V_15 < V_200 . V_15 ) {
V_15 = V_200 . V_15 - V_15 ;
V_208 = V_200 . V_16 - V_206 ;
V_208 += V_15 * sizeof( V_177 ) ;
V_207 = V_201 . V_17 - F_89 ( V_204 ) ;
V_207 -= V_201 . V_15 * sizeof( V_177 ) ;
if ( V_208 > V_207 )
F_91 ( args , & V_201 , V_203 -> V_25 ) ;
F_99 ( args , V_204 , & V_200 ,
V_200 . V_15 - V_15 , V_205 , & V_201 , 0 , V_15 ) ;
} else if ( V_15 > V_200 . V_15 ) {
ASSERT ( 0 ) ;
V_15 -= V_200 . V_15 ;
V_208 = V_206 - V_200 . V_16 ;
V_208 += V_15 * sizeof( V_177 ) ;
V_207 = V_200 . V_17 - F_89 ( V_204 ) ;
V_207 -= V_200 . V_15 * sizeof( V_177 ) ;
if ( V_208 > V_207 )
F_91 ( args , & V_200 , V_202 -> V_25 ) ;
F_99 ( args , V_205 , & V_201 , 0 , V_204 , & V_200 ,
V_200 . V_15 , V_15 ) ;
}
F_5 ( V_204 , & V_200 ) ;
F_5 ( V_205 , & V_201 ) ;
F_76 ( args -> V_96 , V_202 -> V_25 , 0 , args -> V_123 -> V_142 - 1 ) ;
F_76 ( args -> V_96 , V_203 -> V_25 , 0 , args -> V_123 -> V_142 - 1 ) ;
V_198 = F_69 ( V_204 ) ;
V_199 = F_69 ( V_205 ) ;
V_202 -> V_129 = F_3 ( V_198 [ V_200 . V_15 - 1 ] . V_129 ) ;
V_203 -> V_129 = F_3 ( V_199 [ V_201 . V_15 - 1 ] . V_129 ) ;
if ( V_202 -> V_176 > V_200 . V_15 ) {
ASSERT ( V_167 -> V_171 == 0 ) ;
V_203 -> V_176 = V_202 -> V_176 - V_200 . V_15 ;
args -> V_176 = args -> V_185 = V_203 -> V_176 ;
args -> V_37 = args -> V_184 = V_203 -> V_37 ;
} else if ( V_202 -> V_176 == V_200 . V_15 ) {
if ( V_167 -> V_171 ) {
args -> V_176 = V_202 -> V_176 ;
args -> V_37 = V_202 -> V_37 ;
args -> V_185 = 0 ;
args -> V_184 = V_203 -> V_37 ;
} else {
V_203 -> V_176 = V_202 -> V_176 - V_200 . V_15 ;
args -> V_176 = V_203 -> V_176 ;
args -> V_37 = V_203 -> V_37 ;
if ( ! V_167 -> V_212 ) {
args -> V_185 = V_203 -> V_176 ;
args -> V_184 = V_203 -> V_37 ;
}
}
} else {
ASSERT ( V_167 -> V_171 == 1 ) ;
args -> V_176 = args -> V_185 = V_202 -> V_176 ;
args -> V_37 = args -> V_184 = V_202 -> V_37 ;
}
}
STATIC int
F_103 (
struct V_166 * V_167 ,
struct V_168 * V_202 ,
struct V_1 * V_200 ,
struct V_168 * V_203 ,
struct V_1 * V_201 ,
int * V_213 ,
int * V_214 )
{
struct V_3 * V_204 = V_202 -> V_25 -> V_31 ;
struct V_3 * V_205 = V_203 -> V_25 -> V_31 ;
struct V_131 * V_132 ;
int V_15 ;
int V_207 ;
int V_176 ;
int V_206 = 0 ;
int V_215 ;
int V_216 ;
int V_217 = 0 ;
int V_175 ;
V_207 = V_200 -> V_15 + V_201 -> V_15 ;
V_215 = ( V_207 + 1 ) * sizeof( * V_132 ) ;
V_215 += V_200 -> V_16 + V_201 -> V_16 +
F_88 ( V_167 -> args , NULL ) ;
V_215 /= 2 ;
V_216 = V_167 -> args -> V_123 -> V_142 ;
V_132 = F_69 ( V_204 ) ;
for ( V_15 = V_176 = 0 ; V_15 < V_207 ; V_132 ++ , V_176 ++ , V_15 ++ ) {
#define F_104 ( T_12 ) (((A) < 0) ? -(A) : (A))
if ( V_15 == V_202 -> V_176 ) {
V_175 = V_206 + sizeof( * V_132 ) +
F_88 ( V_167 -> args , NULL ) ;
if ( F_104 ( V_215 - V_175 ) > V_216 )
break;
V_216 = F_104 ( V_215 - V_175 ) ;
V_206 = V_175 ;
V_217 = 1 ;
}
if ( V_15 == V_200 -> V_15 ) {
V_204 = V_205 ;
V_132 = F_69 ( V_204 ) ;
V_176 = 0 ;
}
V_175 = V_206 + sizeof( * V_132 ) + F_97 ( V_204 ,
V_176 ) ;
if ( F_104 ( V_215 - V_175 ) > V_216 )
break;
V_216 = F_104 ( V_215 - V_175 ) ;
V_206 = V_175 ;
#undef F_104
}
V_206 -= V_15 * sizeof( * V_132 ) ;
if ( V_217 ) {
V_206 -= sizeof( * V_132 ) +
F_88 ( V_167 -> args , NULL ) ;
}
* V_213 = V_15 ;
* V_214 = V_206 ;
return V_217 ;
}
int
F_105 (
struct V_166 * V_167 ,
int * V_218 )
{
struct V_3 * V_30 ;
struct V_168 * V_219 ;
struct V_1 V_32 ;
struct V_24 * V_25 ;
T_1 V_37 ;
int V_62 ;
int V_220 ;
int error ;
int V_221 ;
int V_5 ;
F_106 ( V_167 -> args ) ;
V_219 = & V_167 -> V_222 . V_219 [ V_167 -> V_222 . V_223 - 1 ] ;
V_30 = V_219 -> V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_62 = F_89 ( V_30 ) +
V_32 . V_15 * sizeof( V_177 ) +
V_32 . V_16 ;
if ( V_62 > ( V_167 -> args -> V_123 -> V_142 >> 1 ) ) {
* V_218 = 0 ;
return 0 ;
}
if ( V_32 . V_15 == 0 ) {
V_220 = ( V_32 . V_13 != 0 ) ;
memcpy ( & V_167 -> V_224 , & V_167 -> V_222 , sizeof( V_167 -> V_222 ) ) ;
error = F_107 ( V_167 , & V_167 -> V_224 , V_220 ,
0 , & V_221 ) ;
if ( error )
return error ;
if ( V_221 ) {
* V_218 = 0 ;
} else {
* V_218 = 2 ;
}
return 0 ;
}
V_220 = V_32 . V_13 < V_32 . V_14 ;
for ( V_5 = 0 ; V_5 < 2 ; V_220 = ! V_220 , V_5 ++ ) {
struct V_1 V_201 ;
if ( V_220 )
V_37 = V_32 . V_13 ;
else
V_37 = V_32 . V_14 ;
if ( V_37 == 0 )
continue;
error = F_18 ( V_167 -> args -> V_96 , V_167 -> args -> V_52 ,
V_37 , - 1 , & V_25 ) ;
if ( error )
return error ;
F_1 ( & V_201 , V_25 -> V_31 ) ;
V_62 = V_167 -> args -> V_123 -> V_142 -
( V_167 -> args -> V_123 -> V_142 >> 2 ) -
V_32 . V_16 - V_201 . V_16 -
( ( V_32 . V_15 + V_201 . V_15 ) *
sizeof( V_177 ) ) -
F_89 ( V_30 ) ;
F_108 ( V_167 -> args -> V_96 , V_25 ) ;
if ( V_62 >= 0 )
break;
}
if ( V_5 >= 2 ) {
* V_218 = 0 ;
return 0 ;
}
memcpy ( & V_167 -> V_224 , & V_167 -> V_222 , sizeof( V_167 -> V_222 ) ) ;
if ( V_37 < V_219 -> V_37 ) {
error = F_107 ( V_167 , & V_167 -> V_224 , V_220 ,
0 , & V_221 ) ;
} else {
error = F_107 ( V_167 , & V_167 -> V_222 , V_220 ,
0 , & V_221 ) ;
}
if ( error )
return error ;
if ( V_221 ) {
* V_218 = 0 ;
} else {
* V_218 = 1 ;
}
return 0 ;
}
int
F_109 (
struct V_24 * V_25 ,
struct V_140 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_131 * V_132 ;
int V_161 ;
int V_225 ;
int V_226 ;
int V_173 ;
int V_172 ;
int V_175 ;
int V_5 ;
F_110 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( V_32 . V_15 > 0 && V_32 . V_15 < args -> V_123 -> V_142 / 8 ) ;
ASSERT ( args -> V_176 >= 0 && args -> V_176 < V_32 . V_15 ) ;
ASSERT ( V_32 . V_17 >= V_32 . V_15 * sizeof( * V_132 ) +
F_89 ( V_30 ) ) ;
V_132 = & F_69 ( V_30 ) [ args -> V_176 ] ;
ASSERT ( F_4 ( V_132 -> V_145 ) >= V_32 . V_17 ) ;
ASSERT ( F_4 ( V_132 -> V_145 ) < args -> V_123 -> V_142 ) ;
V_172 = V_32 . V_15 * sizeof( V_177 )
+ F_89 ( V_30 ) ;
V_175 = V_32 . V_20 [ 0 ] . V_22 ;
V_161 = V_225 = - 1 ;
V_226 = V_19 - 1 ;
V_173 = F_97 ( V_30 , args -> V_176 ) ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
ASSERT ( V_32 . V_20 [ V_5 ] . V_21 < args -> V_123 -> V_142 ) ;
ASSERT ( V_32 . V_20 [ V_5 ] . V_22 < args -> V_123 -> V_142 ) ;
if ( V_32 . V_20 [ V_5 ] . V_21 == V_172 ) {
V_32 . V_20 [ V_5 ] . V_21 -= sizeof( V_177 ) ;
V_32 . V_20 [ V_5 ] . V_22 += sizeof( V_177 ) ;
}
if ( V_32 . V_20 [ V_5 ] . V_21 + V_32 . V_20 [ V_5 ] . V_22 ==
F_4 ( V_132 -> V_145 ) ) {
V_161 = V_5 ;
} else if ( V_32 . V_20 [ V_5 ] . V_21 ==
( F_4 ( V_132 -> V_145 ) + V_173 ) ) {
V_225 = V_5 ;
} else if ( V_32 . V_20 [ V_5 ] . V_22 < V_175 ) {
V_175 = V_32 . V_20 [ V_5 ] . V_22 ;
V_226 = V_5 ;
}
}
if ( ( V_161 >= 0 ) || ( V_225 >= 0 ) ) {
if ( ( V_161 >= 0 ) && ( V_225 >= 0 ) ) {
V_32 . V_20 [ V_161 ] . V_22 += V_173 ;
V_32 . V_20 [ V_161 ] . V_22 += V_32 . V_20 [ V_225 ] . V_22 ;
V_32 . V_20 [ V_225 ] . V_21 = 0 ;
V_32 . V_20 [ V_225 ] . V_22 = 0 ;
} else if ( V_161 >= 0 ) {
V_32 . V_20 [ V_161 ] . V_22 += V_173 ;
} else {
V_32 . V_20 [ V_225 ] . V_21 = F_4 ( V_132 -> V_145 ) ;
V_32 . V_20 [ V_225 ] . V_22 += V_173 ;
}
} else {
if ( V_32 . V_20 [ V_226 ] . V_22 < V_173 ) {
V_32 . V_20 [ V_226 ] . V_21 = F_4 ( V_132 -> V_145 ) ;
V_32 . V_20 [ V_226 ] . V_22 = V_173 ;
}
}
if ( F_4 ( V_132 -> V_145 ) == V_32 . V_17 )
V_226 = 1 ;
else
V_226 = 0 ;
memset ( F_96 ( V_30 , args -> V_176 ) , 0 , V_173 ) ;
V_32 . V_16 -= V_173 ;
F_76 ( args -> V_96 , V_25 ,
F_92 ( V_30 , F_96 ( V_30 , args -> V_176 ) ,
V_173 ) ) ;
V_175 = ( V_32 . V_15 - args -> V_176 ) * sizeof( V_177 ) ;
memmove ( V_132 , V_132 + 1 , V_175 ) ;
V_32 . V_15 -- ;
F_76 ( args -> V_96 , V_25 ,
F_92 ( V_30 , V_132 , V_175 + sizeof( V_177 ) ) ) ;
V_132 = & F_69 ( V_30 ) [ V_32 . V_15 ] ;
memset ( V_132 , 0 , sizeof( V_177 ) ) ;
if ( V_226 ) {
V_175 = args -> V_123 -> V_142 ;
V_132 = F_69 ( V_30 ) ;
for ( V_5 = V_32 . V_15 - 1 ; V_5 >= 0 ; V_132 ++ , V_5 -- ) {
ASSERT ( F_4 ( V_132 -> V_145 ) >= V_32 . V_17 ) ;
ASSERT ( F_4 ( V_132 -> V_145 ) < args -> V_123 -> V_142 ) ;
if ( F_4 ( V_132 -> V_145 ) < V_175 )
V_175 = F_4 ( V_132 -> V_145 ) ;
}
V_32 . V_17 = V_175 ;
if ( ! V_32 . V_17 )
V_32 . V_17 = V_175 - V_227 ;
} else {
V_32 . V_18 = 1 ;
}
F_5 ( V_30 , & V_32 ) ;
F_76 ( args -> V_96 , V_25 ,
F_92 ( V_30 , & V_30 -> V_6 ,
F_89 ( V_30 ) ) ) ;
V_175 = V_32 . V_16 + F_89 ( V_30 ) +
V_32 . V_15 * sizeof( V_177 ) ;
return V_175 < args -> V_123 -> V_228 ;
}
void
F_111 (
struct V_166 * V_167 ,
struct V_168 * V_229 ,
struct V_168 * V_230 )
{
struct V_3 * V_231 = V_229 -> V_25 -> V_31 ;
struct V_3 * V_232 = V_230 -> V_25 -> V_31 ;
struct V_1 V_233 ;
struct V_1 V_234 ;
struct V_131 * V_132 ;
F_112 ( V_167 -> args ) ;
V_231 = V_229 -> V_25 -> V_31 ;
V_232 = V_230 -> V_25 -> V_31 ;
F_1 ( & V_233 , V_231 ) ;
F_1 ( & V_234 , V_232 ) ;
V_132 = F_69 ( V_231 ) ;
V_229 -> V_129 = F_3 ( V_132 [ V_233 . V_15 - 1 ] . V_129 ) ;
if ( V_234 . V_18 == 0 ) {
if ( F_100 ( V_230 -> V_25 , & V_234 ,
V_229 -> V_25 , & V_233 ) ) {
F_99 ( V_167 -> args ,
V_231 , & V_233 , 0 ,
V_232 , & V_234 , 0 ,
V_233 . V_15 ) ;
} else {
F_99 ( V_167 -> args ,
V_231 , & V_233 , 0 ,
V_232 , & V_234 ,
V_234 . V_15 , V_233 . V_15 ) ;
}
} else {
struct V_3 * V_235 ;
struct V_1 V_236 ;
V_235 = F_113 ( V_167 -> args -> V_123 -> V_142 , V_120 ) ;
memcpy ( V_235 , V_232 , F_89 ( V_232 ) ) ;
memset ( & V_236 , 0 , sizeof( V_236 ) ) ;
V_236 . V_8 = V_234 . V_8 ;
V_236 . V_13 = V_234 . V_13 ;
V_236 . V_14 = V_234 . V_14 ;
V_236 . V_17 = V_167 -> args -> V_123 -> V_142 ;
F_5 ( V_235 , & V_236 ) ;
if ( F_100 ( V_230 -> V_25 , & V_234 ,
V_229 -> V_25 , & V_233 ) ) {
F_99 ( V_167 -> args ,
V_231 , & V_233 , 0 ,
V_235 , & V_236 , 0 ,
V_233 . V_15 ) ;
F_99 ( V_167 -> args ,
V_232 , & V_234 , 0 ,
V_235 , & V_236 , V_236 . V_15 ,
V_234 . V_15 ) ;
} else {
F_99 ( V_167 -> args ,
V_232 , & V_234 , 0 ,
V_235 , & V_236 , 0 ,
V_234 . V_15 ) ;
F_99 ( V_167 -> args ,
V_231 , & V_233 , 0 ,
V_235 , & V_236 , V_236 . V_15 ,
V_233 . V_15 ) ;
}
memcpy ( V_232 , V_235 , V_167 -> args -> V_123 -> V_142 ) ;
V_234 = V_236 ;
F_67 ( V_235 ) ;
}
F_5 ( V_232 , & V_234 ) ;
F_76 ( V_167 -> args -> V_96 , V_230 -> V_25 , 0 ,
V_167 -> args -> V_123 -> V_142 - 1 ) ;
V_132 = F_69 ( V_232 ) ;
V_230 -> V_129 = F_3 ( V_132 [ V_234 . V_15 - 1 ] . V_129 ) ;
}
int
F_65 (
struct V_24 * V_25 ,
struct V_140 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_131 * V_132 ;
struct V_131 * V_147 ;
struct V_141 * V_133 ;
struct V_180 * V_181 ;
T_13 V_129 ;
int V_237 ;
int V_238 ;
F_114 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_147 = F_69 ( V_30 ) ;
ASSERT ( V_32 . V_15 < args -> V_123 -> V_142 / 8 ) ;
V_129 = args -> V_129 ;
V_237 = V_238 = V_32 . V_15 / 2 ;
for ( V_132 = & V_147 [ V_237 ] ; V_238 > 4 ; V_132 = & V_147 [ V_237 ] ) {
V_238 /= 2 ;
if ( F_3 ( V_132 -> V_129 ) < V_129 )
V_237 += V_238 ;
else if ( F_3 ( V_132 -> V_129 ) > V_129 )
V_237 -= V_238 ;
else
break;
}
ASSERT ( V_237 >= 0 && ( ! V_32 . V_15 || V_237 < V_32 . V_15 ) ) ;
ASSERT ( V_238 <= 4 || F_3 ( V_132 -> V_129 ) == V_129 ) ;
while ( V_237 > 0 && F_3 ( V_132 -> V_129 ) >= V_129 ) {
V_132 -- ;
V_237 -- ;
}
while ( V_237 < V_32 . V_15 &&
F_3 ( V_132 -> V_129 ) < V_129 ) {
V_132 ++ ;
V_237 ++ ;
}
if ( V_237 == V_32 . V_15 || F_3 ( V_132 -> V_129 ) != V_129 ) {
args -> V_176 = V_237 ;
return - V_112 ;
}
for (; V_237 < V_32 . V_15 && ( F_3 ( V_132 -> V_129 ) == V_129 ) ;
V_132 ++ , V_237 ++ ) {
if ( ( args -> V_106 & V_136 ) !=
( V_132 -> V_106 & V_136 ) ) {
continue;
}
if ( V_132 -> V_106 & V_137 ) {
V_133 = F_70 ( V_30 , V_237 ) ;
if ( V_133 -> V_103 != args -> V_103 )
continue;
if ( memcmp ( args -> V_104 , V_133 -> V_105 ,
args -> V_103 ) != 0 )
continue;
if ( ! F_21 ( args -> V_106 , V_132 -> V_106 ) )
continue;
args -> V_176 = V_237 ;
return - V_115 ;
} else {
V_181 = F_94 ( V_30 , V_237 ) ;
if ( V_181 -> V_103 != args -> V_103 )
continue;
if ( memcmp ( args -> V_104 , V_181 -> V_104 ,
args -> V_103 ) != 0 )
continue;
if ( ! F_21 ( args -> V_106 , V_132 -> V_106 ) )
continue;
args -> V_176 = V_237 ;
args -> V_189 = F_3 ( V_181 -> V_107 ) ;
args -> V_187 = F_3 ( V_181 -> V_186 ) ;
args -> V_188 = F_95 (
args -> V_52 -> V_67 ,
args -> V_189 ) ;
return - V_115 ;
}
}
args -> V_176 = V_237 ;
return - V_112 ;
}
int
F_115 (
struct V_24 * V_25 ,
struct V_140 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_131 * V_132 ;
struct V_141 * V_133 ;
struct V_180 * V_181 ;
int V_107 ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( V_32 . V_15 < args -> V_123 -> V_142 / 8 ) ;
ASSERT ( args -> V_176 < V_32 . V_15 ) ;
V_132 = & F_69 ( V_30 ) [ args -> V_176 ] ;
if ( V_132 -> V_106 & V_137 ) {
V_133 = F_70 ( V_30 , args -> V_176 ) ;
ASSERT ( V_133 -> V_103 == args -> V_103 ) ;
ASSERT ( memcmp ( args -> V_104 , V_133 -> V_105 , args -> V_103 ) == 0 ) ;
V_107 = F_4 ( V_133 -> V_107 ) ;
if ( args -> V_106 & V_116 ) {
args -> V_107 = V_107 ;
return 0 ;
}
if ( args -> V_107 < V_107 ) {
args -> V_107 = V_107 ;
return - V_117 ;
}
args -> V_107 = V_107 ;
memcpy ( args -> V_108 , & V_133 -> V_105 [ args -> V_103 ] , V_107 ) ;
} else {
V_181 = F_94 ( V_30 , args -> V_176 ) ;
ASSERT ( V_181 -> V_103 == args -> V_103 ) ;
ASSERT ( memcmp ( args -> V_104 , V_181 -> V_104 , args -> V_103 ) == 0 ) ;
args -> V_189 = F_3 ( V_181 -> V_107 ) ;
args -> V_187 = F_3 ( V_181 -> V_186 ) ;
args -> V_188 = F_95 ( args -> V_52 -> V_67 ,
args -> V_189 ) ;
if ( args -> V_106 & V_116 ) {
args -> V_107 = args -> V_189 ;
return 0 ;
}
if ( args -> V_107 < args -> V_189 ) {
args -> V_107 = args -> V_189 ;
return - V_117 ;
}
args -> V_107 = args -> V_189 ;
}
return 0 ;
}
STATIC void
F_99 (
struct V_140 * args ,
struct V_3 * V_239 ,
struct V_1 * V_240 ,
int V_241 ,
struct V_3 * V_242 ,
struct V_1 * V_243 ,
int V_244 ,
int V_15 )
{
struct V_131 * V_245 ;
struct V_131 * V_246 ;
int V_247 ;
int V_175 ;
int V_5 ;
if ( V_15 == 0 )
return;
ASSERT ( V_240 -> V_8 == V_9 ||
V_240 -> V_8 == V_10 ) ;
ASSERT ( V_240 -> V_8 == V_243 -> V_8 ) ;
ASSERT ( V_240 -> V_15 > 0 && V_240 -> V_15 < args -> V_123 -> V_142 / 8 ) ;
ASSERT ( V_240 -> V_17 >= ( V_240 -> V_15 * sizeof( * V_245 ) )
+ F_89 ( V_239 ) ) ;
ASSERT ( V_243 -> V_15 < args -> V_123 -> V_142 / 8 ) ;
ASSERT ( V_243 -> V_17 >= ( V_243 -> V_15 * sizeof( * V_246 ) )
+ F_89 ( V_242 ) ) ;
ASSERT ( V_241 < V_240 -> V_15 ) ;
ASSERT ( V_244 <= V_243 -> V_15 ) ;
ASSERT ( V_15 <= V_240 -> V_15 ) ;
if ( V_244 < V_243 -> V_15 ) {
V_175 = V_243 -> V_15 - V_244 ;
V_175 *= sizeof( V_177 ) ;
V_245 = & F_69 ( V_242 ) [ V_244 ] ;
V_246 = & F_69 ( V_242 ) [ V_244 + V_15 ] ;
memmove ( V_246 , V_245 , V_175 ) ;
}
V_245 = & F_69 ( V_239 ) [ V_241 ] ;
V_246 = & F_69 ( V_242 ) [ V_244 ] ;
V_247 = V_244 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_245 ++ , V_246 ++ , V_247 ++ , V_5 ++ ) {
ASSERT ( F_4 ( V_245 -> V_145 ) >= V_240 -> V_17 ) ;
V_175 = F_97 ( V_239 , V_241 + V_5 ) ;
#ifdef F_116
if ( V_245 -> V_106 & V_136 ) {
memset ( F_96 ( V_239 , V_241 + V_5 ) , 0 , V_175 ) ;
V_240 -> V_16 -= V_175 ;
V_240 -> V_15 -= 1 ;
V_246 -- ;
V_247 -- ;
if ( ( V_241 + V_5 ) < V_63 )
V_248 ++ ;
} else {
#endif
V_243 -> V_17 -= V_175 ;
V_246 -> V_129 = V_245 -> V_129 ;
V_246 -> V_145 = F_2 ( V_243 -> V_17 ) ;
V_246 -> V_106 = V_245 -> V_106 ;
ASSERT ( F_4 ( V_246 -> V_145 ) + V_175
<= args -> V_123 -> V_142 ) ;
memmove ( F_96 ( V_242 , V_247 ) ,
F_96 ( V_239 , V_241 + V_5 ) , V_175 ) ;
ASSERT ( F_4 ( V_245 -> V_145 ) + V_175
<= args -> V_123 -> V_142 ) ;
memset ( F_96 ( V_239 , V_241 + V_5 ) , 0 , V_175 ) ;
V_240 -> V_16 -= V_175 ;
V_243 -> V_16 += V_175 ;
V_240 -> V_15 -= 1 ;
V_243 -> V_15 += 1 ;
V_175 = V_243 -> V_15 * sizeof( V_177 )
+ F_89 ( V_242 ) ;
ASSERT ( V_243 -> V_17 >= V_175 ) ;
#ifdef F_116
}
#endif
}
if ( V_241 == V_240 -> V_15 ) {
V_175 = V_15 * sizeof( V_177 ) ;
V_245 = & F_69 ( V_239 ) [ V_241 ] ;
ASSERT ( ( ( char * ) V_245 + V_175 ) <=
( ( char * ) V_239 + args -> V_123 -> V_142 ) ) ;
memset ( V_245 , 0 , V_175 ) ;
} else {
V_175 = ( V_240 -> V_15 - V_15 ) * sizeof( V_177 ) ;
V_245 = & F_69 ( V_239 ) [ V_241 + V_15 ] ;
V_246 = & F_69 ( V_239 ) [ V_241 ] ;
memmove ( V_246 , V_245 , V_175 ) ;
V_175 = V_15 * sizeof( V_177 ) ;
V_245 = & F_69 ( V_239 ) [ V_240 -> V_15 ] ;
ASSERT ( ( ( char * ) V_245 + V_175 ) <=
( ( char * ) V_239 + args -> V_123 -> V_142 ) ) ;
memset ( V_245 , 0 , V_175 ) ;
}
V_243 -> V_20 [ 0 ] . V_21 = F_89 ( V_242 ) ;
V_243 -> V_20 [ 0 ] . V_21 += V_243 -> V_15 * sizeof( V_177 ) ;
V_243 -> V_20 [ 0 ] . V_22 = V_243 -> V_17 - V_243 -> V_20 [ 0 ] . V_21 ;
V_243 -> V_20 [ 1 ] . V_21 = 0 ;
V_243 -> V_20 [ 2 ] . V_21 = 0 ;
V_243 -> V_20 [ 1 ] . V_22 = 0 ;
V_243 -> V_20 [ 2 ] . V_22 = 0 ;
V_240 -> V_18 = 1 ;
}
T_13
F_86 (
struct V_24 * V_25 ,
int * V_15 )
{
struct V_1 V_32 ;
struct V_131 * V_147 ;
F_1 ( & V_32 , V_25 -> V_31 ) ;
V_147 = F_69 ( V_25 -> V_31 ) ;
if ( V_15 )
* V_15 = V_32 . V_15 ;
if ( ! V_32 . V_15 )
return 0 ;
return F_3 ( V_147 [ V_32 . V_15 - 1 ] . V_129 ) ;
}
STATIC int
F_97 ( V_144 * V_30 , int V_176 )
{
struct V_131 * V_147 ;
T_11 * V_133 ;
T_14 * V_181 ;
int V_22 ;
V_147 = F_69 ( V_30 ) ;
if ( V_147 [ V_176 ] . V_106 & V_137 ) {
V_133 = F_70 ( V_30 , V_176 ) ;
V_22 = F_117 ( V_133 -> V_103 ,
F_4 ( V_133 -> V_107 ) ) ;
} else {
V_181 = F_94 ( V_30 , V_176 ) ;
V_22 = F_118 ( V_181 -> V_103 ) ;
}
return V_22 ;
}
int
F_88 (
struct V_140 * args ,
int * V_249 )
{
int V_22 ;
V_22 = F_117 ( args -> V_103 , args -> V_107 ) ;
if ( V_22 < F_119 ( args -> V_123 -> V_142 ) ) {
if ( V_249 )
* V_249 = 1 ;
return V_22 ;
}
if ( V_249 )
* V_249 = 0 ;
return F_118 ( args -> V_103 ) ;
}
int
F_120 (
struct V_140 * args )
{
struct V_3 * V_30 ;
struct V_131 * V_132 ;
struct V_180 * V_181 ;
struct V_24 * V_25 ;
int error ;
#ifdef F_45
struct V_1 V_32 ;
T_11 * V_133 ;
int V_103 ;
char * V_104 ;
#endif
F_121 ( args ) ;
error = F_18 ( args -> V_96 , args -> V_52 , args -> V_37 , - 1 , & V_25 ) ;
if ( error )
return error ;
V_30 = V_25 -> V_31 ;
V_132 = & F_69 ( V_30 ) [ args -> V_176 ] ;
ASSERT ( V_132 -> V_106 & V_136 ) ;
#ifdef F_45
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_176 < V_32 . V_15 ) ;
ASSERT ( args -> V_176 >= 0 ) ;
if ( V_132 -> V_106 & V_137 ) {
V_133 = F_70 ( V_30 , args -> V_176 ) ;
V_103 = V_133 -> V_103 ;
V_104 = ( char * ) V_133 -> V_105 ;
} else {
V_181 = F_94 ( V_30 , args -> V_176 ) ;
V_103 = V_181 -> V_103 ;
V_104 = ( char * ) V_181 -> V_104 ;
}
ASSERT ( F_3 ( V_132 -> V_129 ) == args -> V_129 ) ;
ASSERT ( V_103 == args -> V_103 ) ;
ASSERT ( memcmp ( V_104 , args -> V_104 , V_103 ) == 0 ) ;
#endif
V_132 -> V_106 &= ~ V_136 ;
F_76 ( args -> V_96 , V_25 ,
F_92 ( V_30 , V_132 , sizeof( * V_132 ) ) ) ;
if ( args -> V_187 ) {
ASSERT ( ( V_132 -> V_106 & V_137 ) == 0 ) ;
V_181 = F_94 ( V_30 , args -> V_176 ) ;
V_181 -> V_186 = F_6 ( args -> V_187 ) ;
V_181 -> V_107 = F_6 ( args -> V_189 ) ;
F_76 ( args -> V_96 , V_25 ,
F_92 ( V_30 , V_181 , sizeof( * V_181 ) ) ) ;
}
return F_122 ( & args -> V_96 , args -> V_52 ) ;
}
int
F_123 (
struct V_140 * args )
{
struct V_3 * V_30 ;
struct V_131 * V_132 ;
struct V_180 * V_181 ;
struct V_24 * V_25 ;
int error ;
#ifdef F_45
struct V_1 V_32 ;
#endif
F_124 ( args ) ;
error = F_18 ( args -> V_96 , args -> V_52 , args -> V_37 , - 1 , & V_25 ) ;
if ( error )
return error ;
V_30 = V_25 -> V_31 ;
#ifdef F_45
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_176 < V_32 . V_15 ) ;
ASSERT ( args -> V_176 >= 0 ) ;
#endif
V_132 = & F_69 ( V_30 ) [ args -> V_176 ] ;
ASSERT ( ( V_132 -> V_106 & V_136 ) == 0 ) ;
V_132 -> V_106 |= V_136 ;
F_76 ( args -> V_96 , V_25 ,
F_92 ( V_30 , V_132 , sizeof( * V_132 ) ) ) ;
if ( ( V_132 -> V_106 & V_137 ) == 0 ) {
V_181 = F_94 ( V_30 , args -> V_176 ) ;
V_181 -> V_186 = 0 ;
V_181 -> V_107 = 0 ;
F_76 ( args -> V_96 , V_25 ,
F_92 ( V_30 , V_181 , sizeof( * V_181 ) ) ) ;
}
return F_122 ( & args -> V_96 , args -> V_52 ) ;
}
int
F_125 (
struct V_140 * args )
{
struct V_3 * V_204 ;
struct V_3 * V_205 ;
struct V_131 * V_250 ;
struct V_131 * V_251 ;
struct V_180 * V_181 ;
struct V_24 * V_154 ;
struct V_24 * V_155 ;
int error ;
#ifdef F_45
struct V_1 V_200 ;
struct V_1 V_201 ;
T_11 * V_133 ;
int V_252 , V_253 ;
char * V_254 , * V_255 ;
#endif
F_126 ( args ) ;
error = F_18 ( args -> V_96 , args -> V_52 , args -> V_37 , - 1 , & V_154 ) ;
if ( error )
return error ;
if ( args -> V_184 != args -> V_37 ) {
error = F_18 ( args -> V_96 , args -> V_52 , args -> V_184 ,
- 1 , & V_155 ) ;
if ( error )
return error ;
} else {
V_155 = V_154 ;
}
V_204 = V_154 -> V_31 ;
V_250 = & F_69 ( V_204 ) [ args -> V_176 ] ;
V_205 = V_155 -> V_31 ;
V_251 = & F_69 ( V_205 ) [ args -> V_185 ] ;
#ifdef F_45
F_1 ( & V_200 , V_204 ) ;
ASSERT ( args -> V_176 < V_200 . V_15 ) ;
ASSERT ( args -> V_176 >= 0 ) ;
F_1 ( & V_201 , V_205 ) ;
ASSERT ( args -> V_185 < V_201 . V_15 ) ;
ASSERT ( args -> V_185 >= 0 ) ;
if ( V_250 -> V_106 & V_137 ) {
V_133 = F_70 ( V_204 , args -> V_176 ) ;
V_252 = V_133 -> V_103 ;
V_254 = ( char * ) V_133 -> V_105 ;
} else {
V_181 = F_94 ( V_204 , args -> V_176 ) ;
V_252 = V_181 -> V_103 ;
V_254 = ( char * ) V_181 -> V_104 ;
}
if ( V_251 -> V_106 & V_137 ) {
V_133 = F_70 ( V_205 , args -> V_185 ) ;
V_253 = V_133 -> V_103 ;
V_255 = ( char * ) V_133 -> V_105 ;
} else {
V_181 = F_94 ( V_205 , args -> V_185 ) ;
V_253 = V_181 -> V_103 ;
V_255 = ( char * ) V_181 -> V_104 ;
}
ASSERT ( F_3 ( V_250 -> V_129 ) == F_3 ( V_251 -> V_129 ) ) ;
ASSERT ( V_252 == V_253 ) ;
ASSERT ( memcmp ( V_254 , V_255 , V_252 ) == 0 ) ;
#endif
ASSERT ( V_250 -> V_106 & V_136 ) ;
ASSERT ( ( V_251 -> V_106 & V_136 ) == 0 ) ;
V_250 -> V_106 &= ~ V_136 ;
F_76 ( args -> V_96 , V_154 ,
F_92 ( V_204 , V_250 , sizeof( * V_250 ) ) ) ;
if ( args -> V_187 ) {
ASSERT ( ( V_250 -> V_106 & V_137 ) == 0 ) ;
V_181 = F_94 ( V_204 , args -> V_176 ) ;
V_181 -> V_186 = F_6 ( args -> V_187 ) ;
V_181 -> V_107 = F_6 ( args -> V_189 ) ;
F_76 ( args -> V_96 , V_154 ,
F_92 ( V_204 , V_181 , sizeof( * V_181 ) ) ) ;
}
V_251 -> V_106 |= V_136 ;
F_76 ( args -> V_96 , V_155 ,
F_92 ( V_205 , V_251 , sizeof( * V_251 ) ) ) ;
if ( ( V_251 -> V_106 & V_137 ) == 0 ) {
V_181 = F_94 ( V_205 , args -> V_185 ) ;
V_181 -> V_186 = 0 ;
V_181 -> V_107 = 0 ;
F_76 ( args -> V_96 , V_155 ,
F_92 ( V_205 , V_181 , sizeof( * V_181 ) ) ) ;
}
error = F_122 ( & args -> V_96 , args -> V_52 ) ;
return error ;
}
