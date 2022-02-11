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
F_12 ( V_42 , V_43 , V_27 , V_25 -> V_31 ) ;
F_13 ( V_25 , V_44 ) ;
return;
}
if ( ! F_8 ( & V_27 -> V_33 ) )
return;
if ( V_40 )
V_12 -> V_7 . V_45 = F_14 ( V_40 -> V_46 . V_47 ) ;
F_15 ( V_25 -> V_31 , F_16 ( V_25 -> V_48 ) , V_49 ) ;
}
static void
F_17 (
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 -> V_29 ;
if ( ( F_8 ( & V_27 -> V_33 ) &&
! F_18 ( V_25 -> V_31 , F_16 ( V_25 -> V_48 ) ,
V_49 ) ) ||
! F_7 ( V_25 ) ) {
F_12 ( V_42 , V_43 , V_27 , V_25 -> V_31 ) ;
F_13 ( V_25 , V_44 ) ;
}
}
int
F_19 (
struct V_50 * V_51 ,
struct V_52 * V_53 ,
T_1 V_54 ,
T_2 V_55 ,
struct V_24 * * V_56 )
{
int V_57 ;
V_57 = F_20 ( V_51 , V_53 , V_54 , V_55 , V_56 ,
V_58 , & V_59 ) ;
if ( ! V_57 && V_51 )
F_21 ( V_51 , * V_56 , V_60 ) ;
return V_57 ;
}
STATIC int
F_22 ( int V_61 , int V_62 )
{
return F_23 ( V_62 ) == F_24 ( V_61 ) ;
}
int
F_25 ( T_3 * V_53 , int V_63 )
{
int V_64 ;
int V_65 ;
int V_66 ;
int V_67 ;
T_4 * V_27 = V_53 -> V_68 ;
V_64 = ( F_26 ( V_27 , V_53 -> V_69 . V_70 ) - V_63 ) >> 3 ;
switch ( V_53 -> V_69 . V_71 ) {
case V_72 :
V_65 = F_27 ( sizeof( V_73 ) , 8 ) >> 3 ;
return ( V_64 >= V_65 ) ? V_65 : 0 ;
case V_74 :
V_65 = F_27 ( sizeof( V_75 ) , 8 ) >> 3 ;
return ( V_64 >= V_65 ) ? V_65 : 0 ;
}
if ( V_63 <= F_28 ( V_53 ) )
return V_53 -> V_69 . V_76 ;
if ( ! ( V_27 -> V_77 & V_78 ) )
return 0 ;
V_67 = V_53 -> V_79 . V_80 ;
switch ( V_53 -> V_69 . V_71 ) {
case V_81 :
if ( ! V_53 -> V_69 . V_76 && V_53 -> V_79 . V_80 >
F_29 ( V_53 ) )
V_67 = F_30 ( V_82 ) ;
break;
case V_83 :
if ( V_53 -> V_69 . V_76 ) {
if ( V_64 < V_53 -> V_69 . V_76 )
return 0 ;
return V_53 -> V_69 . V_76 ;
}
V_67 = F_31 ( V_27 , V_53 -> V_79 . V_84 ) ;
break;
}
V_65 = F_32 ( V_67 , F_30 ( V_82 ) ) ;
V_65 = F_27 ( V_65 , 8 ) >> 3 ;
V_66 = F_26 ( V_27 , V_53 -> V_69 . V_70 ) -
F_30 ( V_85 ) ;
V_66 = V_66 >> 3 ;
if ( V_64 >= V_66 )
return V_66 ;
if ( V_64 >= V_65 )
return V_64 ;
return 0 ;
}
STATIC void
F_33 ( T_4 * V_27 , T_5 * V_51 )
{
if ( ( V_27 -> V_77 & V_78 ) &&
! ( F_34 ( & V_27 -> V_33 ) ) ) {
F_35 ( & V_27 -> V_86 ) ;
if ( ! F_34 ( & V_27 -> V_33 ) ) {
F_36 ( & V_27 -> V_33 ) ;
F_37 ( & V_27 -> V_86 ) ;
F_38 ( V_51 , V_87 | V_88 ) ;
} else
F_37 ( & V_27 -> V_86 ) ;
}
}
void
F_39 ( T_6 * args )
{
T_7 * V_6 ;
T_3 * V_53 ;
T_8 * V_89 ;
F_40 ( args ) ;
V_53 = args -> V_53 ;
ASSERT ( V_53 != NULL ) ;
V_89 = V_53 -> V_90 ;
ASSERT ( V_89 != NULL ) ;
ASSERT ( V_89 -> V_80 == 0 ) ;
if ( V_53 -> V_69 . V_91 == V_81 ) {
V_89 -> V_92 &= ~ V_93 ;
V_53 -> V_69 . V_91 = V_94 ;
V_89 -> V_92 |= V_95 ;
} else {
ASSERT ( V_89 -> V_92 & V_95 ) ;
}
F_41 ( V_53 , sizeof( * V_6 ) , V_58 ) ;
V_6 = ( T_7 * ) V_89 -> V_96 . V_97 ;
V_6 -> V_15 = 0 ;
V_6 -> V_98 = F_2 ( sizeof( * V_6 ) ) ;
F_42 ( args -> V_99 , V_53 , V_100 | V_101 ) ;
}
void
F_43 ( T_6 * args , int V_102 )
{
T_9 * V_103 ;
T_10 * V_104 ;
int V_5 , V_64 , V_22 ;
T_4 * V_27 ;
T_3 * V_53 ;
T_8 * V_89 ;
F_44 ( args ) ;
V_53 = args -> V_53 ;
V_27 = V_53 -> V_68 ;
V_53 -> V_69 . V_76 = V_102 ;
V_89 = V_53 -> V_90 ;
ASSERT ( V_89 -> V_92 & V_95 ) ;
V_103 = ( T_9 * ) V_89 -> V_96 . V_97 ;
V_104 = & V_103 -> V_105 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_103 -> V_6 . V_15 ; V_104 = F_45 ( V_104 ) , V_5 ++ ) {
#ifdef F_46
if ( V_104 -> V_106 != args -> V_106 )
continue;
if ( memcmp ( args -> V_107 , V_104 -> V_108 , args -> V_106 ) != 0 )
continue;
if ( ! F_22 ( args -> V_109 , V_104 -> V_109 ) )
continue;
ASSERT ( 0 ) ;
#endif
}
V_64 = ( char * ) V_104 - ( char * ) V_103 ;
V_22 = F_47 ( args -> V_106 , args -> V_110 ) ;
F_41 ( V_53 , V_22 , V_58 ) ;
V_103 = ( T_9 * ) V_89 -> V_96 . V_97 ;
V_104 = ( T_10 * ) ( ( char * ) V_103 + V_64 ) ;
V_104 -> V_106 = args -> V_106 ;
V_104 -> V_110 = args -> V_110 ;
V_104 -> V_109 = F_24 ( args -> V_109 ) ;
memcpy ( V_104 -> V_108 , args -> V_107 , args -> V_106 ) ;
memcpy ( & V_104 -> V_108 [ args -> V_106 ] , args -> V_111 , args -> V_110 ) ;
V_103 -> V_6 . V_15 ++ ;
F_48 ( & V_103 -> V_6 . V_98 , V_22 ) ;
F_42 ( args -> V_99 , V_53 , V_100 | V_101 ) ;
F_33 ( V_27 , args -> V_99 ) ;
}
STATIC void
F_49 (
struct V_52 * V_112 ,
struct V_50 * V_51 )
{
F_50 ( V_112 , V_58 ) ;
V_112 -> V_69 . V_76 = 0 ;
V_112 -> V_69 . V_91 = V_81 ;
ASSERT ( V_112 -> V_69 . V_113 == 0 ) ;
ASSERT ( V_112 -> V_90 == NULL ) ;
F_42 ( V_51 , V_112 , V_100 ) ;
}
int
F_51 ( T_6 * args )
{
T_9 * V_103 ;
T_10 * V_104 ;
int V_21 , V_22 = 0 , V_114 , V_98 , V_5 ;
T_4 * V_27 ;
T_3 * V_53 ;
F_52 ( args ) ;
V_53 = args -> V_53 ;
V_27 = V_53 -> V_68 ;
V_21 = sizeof( T_7 ) ;
V_103 = ( T_9 * ) V_53 -> V_90 -> V_96 . V_97 ;
V_104 = & V_103 -> V_105 [ 0 ] ;
V_114 = V_103 -> V_6 . V_15 ;
for ( V_5 = 0 ; V_5 < V_114 ; V_104 = F_45 ( V_104 ) ,
V_21 += V_22 , V_5 ++ ) {
V_22 = F_53 ( V_104 ) ;
if ( V_104 -> V_106 != args -> V_106 )
continue;
if ( memcmp ( V_104 -> V_108 , args -> V_107 , args -> V_106 ) != 0 )
continue;
if ( ! F_22 ( args -> V_109 , V_104 -> V_109 ) )
continue;
break;
}
if ( V_5 == V_114 )
return ( F_54 ( V_115 ) ) ;
V_114 = V_21 + V_22 ;
V_98 = F_4 ( V_103 -> V_6 . V_98 ) ;
if ( V_114 != V_98 )
memmove ( & ( ( char * ) V_103 ) [ V_21 ] , & ( ( char * ) V_103 ) [ V_114 ] , V_98 - V_114 ) ;
V_103 -> V_6 . V_15 -- ;
F_48 ( & V_103 -> V_6 . V_98 , - V_22 ) ;
V_98 -= V_22 ;
if ( V_98 == sizeof( T_7 ) &&
( V_27 -> V_77 & V_78 ) &&
( V_53 -> V_69 . V_71 != V_83 ) &&
! ( args -> V_116 & V_117 ) ) {
F_49 ( V_53 , args -> V_99 ) ;
} else {
F_41 ( V_53 , - V_22 , V_58 ) ;
V_53 -> V_69 . V_76 = F_25 ( V_53 , V_98 ) ;
ASSERT ( V_53 -> V_69 . V_76 ) ;
ASSERT ( V_98 > sizeof( T_7 ) ||
( args -> V_116 & V_117 ) ||
! ( V_27 -> V_77 & V_78 ) ||
V_53 -> V_69 . V_71 == V_83 ) ;
F_42 ( args -> V_99 , V_53 ,
V_100 | V_101 ) ;
}
F_33 ( V_27 , args -> V_99 ) ;
return ( 0 ) ;
}
int
F_55 ( T_6 * args )
{
T_9 * V_103 ;
T_10 * V_104 ;
int V_5 ;
T_8 * V_89 ;
F_56 ( args ) ;
V_89 = args -> V_53 -> V_90 ;
ASSERT ( V_89 -> V_92 & V_95 ) ;
V_103 = ( T_9 * ) V_89 -> V_96 . V_97 ;
V_104 = & V_103 -> V_105 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_103 -> V_6 . V_15 ;
V_104 = F_45 ( V_104 ) , V_5 ++ ) {
if ( V_104 -> V_106 != args -> V_106 )
continue;
if ( memcmp ( args -> V_107 , V_104 -> V_108 , args -> V_106 ) != 0 )
continue;
if ( ! F_22 ( args -> V_109 , V_104 -> V_109 ) )
continue;
return ( F_54 ( V_118 ) ) ;
}
return ( F_54 ( V_115 ) ) ;
}
int
F_57 ( T_6 * args )
{
T_9 * V_103 ;
T_10 * V_104 ;
int V_5 ;
ASSERT ( args -> V_53 -> V_69 . V_91 == V_95 ) ;
V_103 = ( T_9 * ) args -> V_53 -> V_90 -> V_96 . V_97 ;
V_104 = & V_103 -> V_105 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_103 -> V_6 . V_15 ;
V_104 = F_45 ( V_104 ) , V_5 ++ ) {
if ( V_104 -> V_106 != args -> V_106 )
continue;
if ( memcmp ( args -> V_107 , V_104 -> V_108 , args -> V_106 ) != 0 )
continue;
if ( ! F_22 ( args -> V_109 , V_104 -> V_109 ) )
continue;
if ( args -> V_109 & V_119 ) {
args -> V_110 = V_104 -> V_110 ;
return ( F_54 ( V_118 ) ) ;
}
if ( args -> V_110 < V_104 -> V_110 ) {
args -> V_110 = V_104 -> V_110 ;
return ( F_54 ( V_120 ) ) ;
}
args -> V_110 = V_104 -> V_110 ;
memcpy ( args -> V_111 , & V_104 -> V_108 [ args -> V_106 ] ,
args -> V_110 ) ;
return ( F_54 ( V_118 ) ) ;
}
return ( F_54 ( V_115 ) ) ;
}
int
F_58 ( T_6 * args )
{
T_3 * V_53 ;
T_9 * V_103 ;
T_10 * V_104 ;
T_6 V_121 ;
char * V_122 ;
int error , V_5 , V_22 ;
T_1 V_37 ;
struct V_24 * V_25 ;
T_8 * V_89 ;
F_59 ( args ) ;
V_53 = args -> V_53 ;
V_89 = V_53 -> V_90 ;
V_103 = ( T_9 * ) V_89 -> V_96 . V_97 ;
V_22 = F_4 ( V_103 -> V_6 . V_98 ) ;
V_122 = F_60 ( V_22 , V_123 ) ;
ASSERT ( V_122 != NULL ) ;
memcpy ( V_122 , V_89 -> V_96 . V_97 , V_22 ) ;
V_103 = ( T_9 * ) V_122 ;
F_41 ( V_53 , - V_22 , V_58 ) ;
F_61 ( V_53 , V_58 ) ;
V_25 = NULL ;
error = F_62 ( args , & V_37 ) ;
if ( error ) {
if ( error == V_124 )
goto V_125;
F_41 ( V_53 , V_22 , V_58 ) ;
memcpy ( V_89 -> V_96 . V_97 , V_122 , V_22 ) ;
goto V_125;
}
ASSERT ( V_37 == 0 ) ;
error = F_63 ( args , V_37 , & V_25 ) ;
if ( error ) {
error = F_64 ( args , 0 , V_25 ) ;
V_25 = NULL ;
if ( error )
goto V_125;
F_41 ( V_53 , V_22 , V_58 ) ;
memcpy ( V_89 -> V_96 . V_97 , V_122 , V_22 ) ;
goto V_125;
}
memset ( ( char * ) & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_53 = V_53 ;
V_121 . V_126 = args -> V_126 ;
V_121 . V_127 = args -> V_127 ;
V_121 . V_128 = args -> V_128 ;
V_121 . V_129 = V_58 ;
V_121 . V_99 = args -> V_99 ;
V_121 . V_116 = V_130 ;
V_104 = & V_103 -> V_105 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_103 -> V_6 . V_15 ; V_5 ++ ) {
V_121 . V_107 = V_104 -> V_108 ;
V_121 . V_106 = V_104 -> V_106 ;
V_121 . V_111 = & V_104 -> V_108 [ V_121 . V_106 ] ;
V_121 . V_110 = V_104 -> V_110 ;
V_121 . V_131 = F_65 ( V_104 -> V_108 ,
V_104 -> V_106 ) ;
V_121 . V_109 = F_66 ( V_104 -> V_109 ) ;
error = F_67 ( V_25 , & V_121 ) ;
ASSERT ( error == V_115 ) ;
error = F_68 ( V_25 , & V_121 ) ;
ASSERT ( error != V_132 ) ;
if ( error )
goto V_125;
V_104 = F_45 ( V_104 ) ;
}
error = 0 ;
V_125:
F_69 ( V_122 ) ;
return ( error ) ;
}
STATIC int
F_70 ( const void * V_133 , const void * V_134 )
{
T_11 * V_135 , * V_136 ;
V_135 = ( T_11 * ) V_133 ;
V_136 = ( T_11 * ) V_134 ;
if ( V_135 -> V_137 < V_136 -> V_137 ) {
return ( - 1 ) ;
} else if ( V_135 -> V_137 > V_136 -> V_137 ) {
return ( 1 ) ;
} else {
return ( V_135 -> V_138 - V_136 -> V_138 ) ;
}
}
int
F_71 ( T_12 * V_139 )
{
T_13 * V_140 ;
T_11 * V_141 , * V_142 ;
T_9 * V_103 ;
T_10 * V_104 ;
T_3 * V_53 ;
int V_143 , V_144 , V_15 , V_5 ;
int error ;
ASSERT ( V_139 != NULL ) ;
V_53 = V_139 -> V_53 ;
ASSERT ( V_53 != NULL ) ;
ASSERT ( V_53 -> V_90 != NULL ) ;
V_103 = ( T_9 * ) V_53 -> V_90 -> V_96 . V_97 ;
ASSERT ( V_103 != NULL ) ;
if ( ! V_103 -> V_6 . V_15 )
return ( 0 ) ;
V_140 = V_139 -> V_140 ;
ASSERT ( V_140 != NULL ) ;
F_72 ( V_139 ) ;
if ( V_139 -> V_145 == 0 ||
( F_73 ( V_140 ) &&
( V_53 -> V_90 -> V_80 + V_103 -> V_6 . V_15 * 16 ) < V_139 -> V_145 ) ) {
for ( V_5 = 0 , V_104 = & V_103 -> V_105 [ 0 ] ; V_5 < V_103 -> V_6 . V_15 ; V_5 ++ ) {
error = V_139 -> V_146 ( V_139 ,
V_104 -> V_109 ,
V_104 -> V_108 ,
( int ) V_104 -> V_106 ,
( int ) V_104 -> V_110 ,
& V_104 -> V_108 [ V_104 -> V_106 ] ) ;
if ( V_139 -> V_147 )
break;
if ( error )
return error ;
V_104 = F_45 ( V_104 ) ;
}
F_74 ( V_139 ) ;
return ( 0 ) ;
}
if ( V_139 -> V_145 == 0 )
return 0 ;
V_143 = V_103 -> V_6 . V_15 * sizeof( * V_141 ) ;
V_142 = V_141 = F_60 ( V_143 , V_123 | V_148 ) ;
V_144 = 0 ;
for ( V_5 = 0 , V_104 = & V_103 -> V_105 [ 0 ] ; V_5 < V_103 -> V_6 . V_15 ; V_5 ++ ) {
if ( F_75 (
( ( char * ) V_104 < ( char * ) V_103 ) ||
( ( char * ) V_104 >= ( ( char * ) V_103 + V_53 -> V_90 -> V_80 ) ) ) ) {
F_12 ( L_1 ,
V_43 ,
V_139 -> V_53 -> V_68 , V_104 ) ;
F_69 ( V_141 ) ;
return F_54 ( V_44 ) ;
}
V_142 -> V_138 = V_5 ;
V_142 -> V_137 = F_65 ( V_104 -> V_108 , V_104 -> V_106 ) ;
V_142 -> V_107 = V_104 -> V_108 ;
V_142 -> V_106 = V_104 -> V_106 ;
V_142 -> V_110 = V_104 -> V_110 ;
V_142 -> V_109 = V_104 -> V_109 ;
V_104 = F_45 ( V_104 ) ;
V_142 ++ ;
V_144 ++ ;
}
F_76 ( V_141 , V_144 , sizeof( * V_141 ) , F_70 ) ;
V_15 = 0 ;
V_140 -> V_149 = 1 ;
V_140 -> V_37 = 0 ;
for ( V_142 = V_141 , V_5 = 0 ; V_5 < V_144 ; V_5 ++ , V_142 ++ ) {
if ( V_142 -> V_137 == V_140 -> V_131 ) {
if ( V_140 -> V_64 == V_15 ) {
break;
}
V_15 ++ ;
} else if ( V_142 -> V_137 > V_140 -> V_131 ) {
break;
}
}
if ( V_5 == V_144 ) {
F_69 ( V_141 ) ;
return ( 0 ) ;
}
for ( ; V_5 < V_144 ; V_5 ++ , V_142 ++ ) {
if ( V_140 -> V_131 != V_142 -> V_137 ) {
V_140 -> V_131 = V_142 -> V_137 ;
V_140 -> V_64 = 0 ;
}
error = V_139 -> V_146 ( V_139 ,
V_142 -> V_109 ,
V_142 -> V_107 ,
V_142 -> V_106 ,
V_142 -> V_110 ,
& V_142 -> V_107 [ V_142 -> V_106 ] ) ;
if ( error )
return error ;
if ( V_139 -> V_147 )
break;
V_140 -> V_64 ++ ;
}
F_69 ( V_141 ) ;
return ( 0 ) ;
}
int
F_77 (
struct V_24 * V_25 ,
struct V_52 * V_53 )
{
struct V_3 * V_30 ;
struct V_150 * V_151 ;
T_14 * V_152 ;
struct V_1 V_153 ;
int V_63 ;
int V_5 ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_153 , V_30 ) ;
V_151 = F_78 ( V_30 ) ;
V_63 = sizeof( struct V_154 ) ;
for ( V_5 = 0 ; V_5 < V_153 . V_15 ; V_151 ++ , V_5 ++ ) {
if ( V_151 -> V_109 & V_155 )
continue;
if ( ! ( V_151 -> V_109 & V_156 ) )
return ( 0 ) ;
V_152 = F_79 ( V_30 , V_5 ) ;
if ( V_152 -> V_106 >= V_157 )
return ( 0 ) ;
if ( F_4 ( V_152 -> V_110 ) >= V_157 )
return ( 0 ) ;
V_63 += sizeof( struct V_158 ) - 1
+ V_152 -> V_106
+ F_4 ( V_152 -> V_110 ) ;
}
if ( ( V_53 -> V_68 -> V_77 & V_78 ) &&
( V_53 -> V_69 . V_71 != V_83 ) &&
( V_63 == sizeof( struct V_154 ) ) )
return - 1 ;
return F_25 ( V_53 , V_63 ) ;
}
int
F_80 (
struct V_24 * V_25 ,
struct V_159 * args ,
int V_102 )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_150 * V_151 ;
struct V_160 * V_152 ;
struct V_159 V_121 ;
struct V_52 * V_53 = args -> V_53 ;
char * V_122 ;
int error ;
int V_5 ;
F_81 ( args ) ;
V_122 = F_60 ( F_82 ( V_53 -> V_68 ) , V_123 ) ;
if ( ! V_122 )
return V_161 ;
memcpy ( V_122 , V_25 -> V_31 , F_82 ( V_53 -> V_68 ) ) ;
V_30 = ( V_162 * ) V_122 ;
F_1 ( & V_32 , V_30 ) ;
V_151 = F_78 ( V_30 ) ;
memset ( V_25 -> V_31 , 0 , F_82 ( V_53 -> V_68 ) ) ;
error = F_64 ( args , 0 , V_25 ) ;
if ( error )
goto V_125;
if ( V_102 == - 1 ) {
ASSERT ( V_53 -> V_68 -> V_77 & V_78 ) ;
ASSERT ( V_53 -> V_69 . V_71 != V_83 ) ;
F_49 ( V_53 , args -> V_99 ) ;
goto V_125;
}
F_39 ( args ) ;
memset ( ( char * ) & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_53 = V_53 ;
V_121 . V_126 = args -> V_126 ;
V_121 . V_127 = args -> V_127 ;
V_121 . V_128 = args -> V_128 ;
V_121 . V_129 = V_58 ;
V_121 . V_99 = args -> V_99 ;
V_121 . V_116 = V_130 ;
for ( V_5 = 0 ; V_5 < V_32 . V_15 ; V_151 ++ , V_5 ++ ) {
if ( V_151 -> V_109 & V_155 )
continue;
if ( ! V_151 -> V_163 )
continue;
ASSERT ( V_151 -> V_109 & V_156 ) ;
V_152 = F_79 ( V_30 , V_5 ) ;
V_121 . V_107 = V_152 -> V_108 ;
V_121 . V_106 = V_152 -> V_106 ;
V_121 . V_111 = & V_152 -> V_108 [ V_121 . V_106 ] ;
V_121 . V_110 = F_4 ( V_152 -> V_110 ) ;
V_121 . V_131 = F_3 ( V_151 -> V_131 ) ;
V_121 . V_109 = F_66 ( V_151 -> V_109 ) ;
F_43 ( & V_121 , V_102 ) ;
}
error = 0 ;
V_125:
F_69 ( V_122 ) ;
return error ;
}
int
F_83 (
struct V_159 * args )
{
struct V_3 * V_30 ;
struct V_1 V_164 ;
struct V_150 * V_165 ;
struct V_166 * V_167 ;
struct V_168 V_169 ;
struct V_170 * V_171 ;
struct V_52 * V_53 = args -> V_53 ;
struct V_26 * V_27 = V_53 -> V_68 ;
struct V_24 * V_172 = NULL ;
struct V_24 * V_173 = NULL ;
T_1 V_37 ;
int error ;
F_84 ( args ) ;
error = F_62 ( args , & V_37 ) ;
if ( error )
goto V_125;
error = F_19 ( args -> V_99 , V_53 , 0 , - 1 , & V_172 ) ;
if ( error )
goto V_125;
error = F_85 ( args -> V_99 , V_53 , V_37 , - 1 , & V_173 , V_58 ) ;
if ( error )
goto V_125;
F_21 ( args -> V_99 , V_173 , V_60 ) ;
V_173 -> V_174 = V_172 -> V_174 ;
memcpy ( V_173 -> V_31 , V_172 -> V_31 , F_82 ( V_27 ) ) ;
if ( F_8 ( & V_27 -> V_33 ) ) {
struct V_175 * V_12 = V_173 -> V_31 ;
V_12 -> V_37 = F_14 ( V_173 -> V_38 ) ;
}
F_86 ( args -> V_99 , V_173 , 0 , F_82 ( V_27 ) - 1 ) ;
error = F_87 ( args , 0 , 1 , & V_172 , V_58 ) ;
if ( error )
goto V_125;
V_171 = V_172 -> V_31 ;
F_88 ( & V_169 , V_171 ) ;
V_167 = F_89 ( V_171 ) ;
V_30 = V_173 -> V_31 ;
F_1 ( & V_164 , V_30 ) ;
V_165 = F_78 ( V_30 ) ;
V_167 [ 0 ] . V_131 = V_165 [ V_164 . V_15 - 1 ] . V_131 ;
V_167 [ 0 ] . V_176 = F_6 ( V_37 ) ;
V_169 . V_15 = 1 ;
F_90 ( V_171 , & V_169 ) ;
F_86 ( args -> V_99 , V_172 , 0 , F_82 ( V_27 ) - 1 ) ;
error = 0 ;
V_125:
return error ;
}
STATIC int
F_63 (
struct V_159 * args ,
T_1 V_37 ,
struct V_24 * * V_56 )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_52 * V_53 = args -> V_53 ;
struct V_26 * V_27 = V_53 -> V_68 ;
struct V_24 * V_25 ;
int error ;
F_91 ( args ) ;
error = F_85 ( args -> V_99 , args -> V_53 , V_37 , - 1 , & V_25 ,
V_58 ) ;
if ( error )
return error ;
V_25 -> V_174 = & V_59 ;
F_21 ( args -> V_99 , V_25 , V_60 ) ;
V_30 = V_25 -> V_31 ;
memset ( V_30 , 0 , F_82 ( V_27 ) ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_17 = F_82 ( V_27 ) ;
if ( F_8 ( & V_27 -> V_33 ) ) {
struct V_175 * V_12 = V_25 -> V_31 ;
V_32 . V_8 = V_10 ;
V_12 -> V_37 = F_14 ( V_25 -> V_38 ) ;
V_12 -> V_177 = F_14 ( V_53 -> V_178 ) ;
F_92 ( & V_12 -> V_35 , & V_27 -> V_33 . V_36 ) ;
V_32 . V_20 [ 0 ] . V_21 = sizeof( struct V_11 ) ;
} else {
V_32 . V_8 = V_9 ;
V_32 . V_20 [ 0 ] . V_21 = sizeof( struct V_179 ) ;
}
V_32 . V_20 [ 0 ] . V_22 = V_32 . V_17 - V_32 . V_20 [ 0 ] . V_21 ;
F_5 ( V_30 , & V_32 ) ;
F_86 ( args -> V_99 , V_25 , 0 , F_82 ( V_27 ) - 1 ) ;
* V_56 = V_25 ;
return 0 ;
}
int
F_93 (
struct V_180 * V_181 ,
struct V_182 * V_183 ,
struct V_182 * V_184 )
{
T_1 V_37 ;
int error ;
F_94 ( V_181 -> args ) ;
ASSERT ( V_183 -> V_8 == V_9 ) ;
error = F_62 ( V_181 -> args , & V_37 ) ;
if ( error )
return ( error ) ;
error = F_63 ( V_181 -> args , V_37 , & V_184 -> V_25 ) ;
if ( error )
return ( error ) ;
V_184 -> V_37 = V_37 ;
V_184 -> V_8 = V_9 ;
F_95 ( V_181 , V_183 , V_184 ) ;
error = F_96 ( V_181 , V_183 , V_184 ) ;
if ( error )
return ( error ) ;
if ( V_181 -> V_185 ) {
F_97 ( V_181 -> args ) ;
error = F_68 ( V_183 -> V_25 , V_181 -> args ) ;
} else {
F_98 ( V_181 -> args ) ;
error = F_68 ( V_184 -> V_25 , V_181 -> args ) ;
}
V_183 -> V_131 = F_99 ( V_183 -> V_25 , NULL ) ;
V_184 -> V_131 = F_99 ( V_184 -> V_25 , NULL ) ;
return ( error ) ;
}
int
F_68 (
struct V_24 * V_25 ,
struct V_159 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
int V_186 ;
int V_187 ;
int V_188 ;
int V_189 ;
int V_5 ;
F_100 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_190 >= 0 && args -> V_190 <= V_32 . V_15 ) ;
V_187 = F_101 ( args -> V_106 , args -> V_110 ,
args -> V_99 -> V_191 -> V_33 . V_192 , NULL ) ;
V_186 = ( V_32 . V_15 + 1 ) * sizeof( V_193 )
+ F_102 ( V_30 ) ;
for ( V_188 = 0 , V_5 = V_19 - 1 ; V_5 >= 0 ; V_5 -- ) {
if ( V_186 > V_32 . V_17 ) {
V_188 += V_32 . V_20 [ V_5 ] . V_22 ;
continue;
}
if ( ! V_32 . V_20 [ V_5 ] . V_22 )
continue;
V_189 = V_187 ;
if ( V_32 . V_20 [ V_5 ] . V_21 < V_32 . V_17 )
V_189 += sizeof( V_193 ) ;
if ( V_32 . V_20 [ V_5 ] . V_22 >= V_189 ) {
V_189 = F_103 ( V_25 , & V_32 , args , V_5 ) ;
goto V_194;
}
V_188 += V_32 . V_20 [ V_5 ] . V_22 ;
}
if ( ! V_32 . V_18 && V_188 < V_187 )
return F_54 ( V_132 ) ;
F_104 ( args , & V_32 , V_25 ) ;
if ( V_32 . V_20 [ 0 ] . V_22 < ( V_187 + sizeof( V_193 ) ) ) {
V_189 = V_132 ;
goto V_194;
}
V_189 = F_103 ( V_25 , & V_32 , args , 0 ) ;
V_194:
F_5 ( V_30 , & V_32 ) ;
F_86 ( args -> V_99 , V_25 ,
F_105 ( V_30 , & V_30 -> V_6 ,
F_102 ( V_30 ) ) ) ;
return V_189 ;
}
STATIC int
F_103 (
struct V_24 * V_25 ,
struct V_1 * V_32 ,
struct V_159 * args ,
int V_195 )
{
struct V_3 * V_30 ;
struct V_150 * V_151 ;
struct V_160 * V_152 ;
struct V_196 * V_197 ;
struct V_26 * V_27 ;
int V_189 ;
int V_5 ;
F_106 ( args ) ;
V_30 = V_25 -> V_31 ;
ASSERT ( V_195 >= 0 && V_195 < V_19 ) ;
ASSERT ( args -> V_190 >= 0 && args -> V_190 <= V_32 -> V_15 ) ;
V_151 = & F_78 ( V_30 ) [ args -> V_190 ] ;
if ( args -> V_190 < V_32 -> V_15 ) {
V_189 = V_32 -> V_15 - args -> V_190 ;
V_189 *= sizeof( V_193 ) ;
memmove ( V_151 + 1 , V_151 , V_189 ) ;
F_86 ( args -> V_99 , V_25 ,
F_105 ( V_30 , V_151 , V_189 + sizeof( * V_151 ) ) ) ;
}
V_32 -> V_15 ++ ;
V_27 = args -> V_99 -> V_191 ;
ASSERT ( V_32 -> V_20 [ V_195 ] . V_21 < F_82 ( V_27 ) ) ;
ASSERT ( ( V_32 -> V_20 [ V_195 ] . V_21 & 0x3 ) == 0 ) ;
ASSERT ( V_32 -> V_20 [ V_195 ] . V_22 >=
F_101 ( args -> V_106 , args -> V_110 ,
V_27 -> V_33 . V_192 , NULL ) ) ;
ASSERT ( V_32 -> V_20 [ V_195 ] . V_22 < F_82 ( V_27 ) ) ;
ASSERT ( ( V_32 -> V_20 [ V_195 ] . V_22 & 0x3 ) == 0 ) ;
V_32 -> V_20 [ V_195 ] . V_22 -=
F_101 ( args -> V_106 , args -> V_110 ,
V_27 -> V_33 . V_192 , & V_189 ) ;
V_151 -> V_163 = F_2 ( V_32 -> V_20 [ V_195 ] . V_21 +
V_32 -> V_20 [ V_195 ] . V_22 ) ;
V_151 -> V_131 = F_6 ( args -> V_131 ) ;
V_151 -> V_109 = V_189 ? V_156 : 0 ;
V_151 -> V_109 |= F_24 ( args -> V_109 ) ;
if ( args -> V_116 & V_198 ) {
V_151 -> V_109 |= V_155 ;
if ( ( args -> V_199 == args -> V_37 ) &&
( args -> V_200 <= args -> V_190 ) ) {
args -> V_200 ++ ;
}
}
F_86 ( args -> V_99 , V_25 ,
F_105 ( V_30 , V_151 , sizeof( * V_151 ) ) ) ;
ASSERT ( ( args -> V_190 == 0 ) ||
( F_3 ( V_151 -> V_131 ) >= F_3 ( ( V_151 - 1 ) -> V_131 ) ) ) ;
ASSERT ( ( args -> V_190 == V_32 -> V_15 - 1 ) ||
( F_3 ( V_151 -> V_131 ) <= F_3 ( ( V_151 + 1 ) -> V_131 ) ) ) ;
if ( V_151 -> V_109 & V_156 ) {
V_152 = F_79 ( V_30 , args -> V_190 ) ;
V_152 -> V_106 = args -> V_106 ;
V_152 -> V_110 = F_2 ( args -> V_110 ) ;
memcpy ( ( char * ) V_152 -> V_108 , args -> V_107 , args -> V_106 ) ;
memcpy ( ( char * ) & V_152 -> V_108 [ args -> V_106 ] , args -> V_111 ,
F_4 ( V_152 -> V_110 ) ) ;
} else {
V_197 = F_107 ( V_30 , args -> V_190 ) ;
V_197 -> V_106 = args -> V_106 ;
memcpy ( ( char * ) V_197 -> V_107 , args -> V_107 , args -> V_106 ) ;
V_151 -> V_109 |= V_155 ;
V_197 -> V_110 = 0 ;
V_197 -> V_201 = 0 ;
args -> V_202 = 1 ;
args -> V_203 = F_108 ( V_27 , args -> V_110 ) ;
}
F_86 ( args -> V_99 , V_25 ,
F_105 ( V_30 , F_109 ( V_30 , args -> V_190 ) ,
F_110 ( V_30 , args -> V_190 ) ) ) ;
if ( F_4 ( V_151 -> V_163 ) < V_32 -> V_17 )
V_32 -> V_17 = F_4 ( V_151 -> V_163 ) ;
ASSERT ( V_32 -> V_17 >= V_32 -> V_15 * sizeof( V_193 )
+ F_102 ( V_30 ) ) ;
V_189 = ( V_32 -> V_15 - 1 ) * sizeof( V_193 )
+ F_102 ( V_30 ) ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
if ( V_32 -> V_20 [ V_5 ] . V_21 == V_189 ) {
V_32 -> V_20 [ V_5 ] . V_21 += sizeof( V_193 ) ;
V_32 -> V_20 [ V_5 ] . V_22 -= sizeof( V_193 ) ;
}
}
V_32 -> V_16 += F_110 ( V_30 , args -> V_190 ) ;
return 0 ;
}
STATIC void
F_104 (
struct V_159 * args ,
struct V_1 * V_204 ,
struct V_24 * V_25 )
{
struct V_3 * V_205 ;
struct V_3 * V_206 ;
struct V_1 V_207 ;
struct V_50 * V_99 = args -> V_99 ;
struct V_26 * V_27 = V_99 -> V_191 ;
char * V_122 ;
F_111 ( args ) ;
V_122 = F_60 ( F_82 ( V_27 ) , V_123 ) ;
memcpy ( V_122 , V_25 -> V_31 , F_82 ( V_27 ) ) ;
memset ( V_25 -> V_31 , 0 , F_82 ( V_27 ) ) ;
V_205 = ( V_162 * ) V_122 ;
V_206 = V_25 -> V_31 ;
memcpy ( V_25 -> V_31 , V_122 , F_102 ( V_205 ) ) ;
V_207 = * V_204 ;
V_204 -> V_17 = F_82 ( V_27 ) ;
V_204 -> V_16 = 0 ;
V_204 -> V_15 = 0 ;
V_204 -> V_18 = 0 ;
V_204 -> V_20 [ 0 ] . V_21 = F_102 ( V_205 ) ;
V_204 -> V_20 [ 0 ] . V_22 = V_204 -> V_17 -
V_204 -> V_20 [ 0 ] . V_21 ;
F_5 ( V_206 , V_204 ) ;
F_112 ( V_205 , & V_207 , 0 , V_206 , V_204 , 0 ,
V_207 . V_15 , V_27 ) ;
F_86 ( V_99 , V_25 , 0 , F_82 ( V_27 ) - 1 ) ;
F_69 ( V_122 ) ;
}
static int
F_113 (
struct V_24 * V_208 ,
struct V_1 * V_209 ,
struct V_24 * V_210 ,
struct V_1 * V_211 )
{
struct V_150 * V_212 ;
struct V_150 * V_213 ;
V_212 = F_78 ( V_208 -> V_31 ) ;
V_213 = F_78 ( V_210 -> V_31 ) ;
if ( V_209 -> V_15 > 0 && V_211 -> V_15 > 0 &&
( ( F_3 ( V_213 [ 0 ] . V_131 ) <
F_3 ( V_212 [ 0 ] . V_131 ) ) ||
( F_3 ( V_213 [ V_211 -> V_15 - 1 ] . V_131 ) <
F_3 ( V_212 [ V_209 -> V_15 - 1 ] . V_131 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_114 (
struct V_24 * V_208 ,
struct V_24 * V_210 )
{
struct V_1 V_214 ;
struct V_1 V_215 ;
F_1 ( & V_214 , V_208 -> V_31 ) ;
F_1 ( & V_215 , V_210 -> V_31 ) ;
return F_113 ( V_208 , & V_214 , V_210 , & V_215 ) ;
}
STATIC void
F_95 (
struct V_180 * V_181 ,
struct V_182 * V_216 ,
struct V_182 * V_217 )
{
struct V_159 * args ;
struct V_3 * V_218 ;
struct V_3 * V_219 ;
struct V_1 V_214 ;
struct V_1 V_215 ;
struct V_150 * V_212 ;
struct V_150 * V_213 ;
int V_15 ;
int V_220 ;
int V_221 ;
int V_222 ;
int V_223 ;
ASSERT ( V_216 -> V_8 == V_9 ) ;
ASSERT ( V_217 -> V_8 == V_9 ) ;
V_218 = V_216 -> V_25 -> V_31 ;
V_219 = V_217 -> V_25 -> V_31 ;
F_1 ( & V_214 , V_218 ) ;
F_1 ( & V_215 , V_219 ) ;
ASSERT ( V_215 . V_15 == 0 ) ;
args = V_181 -> args ;
F_115 ( args ) ;
V_223 = 0 ;
if ( F_113 ( V_216 -> V_25 , & V_214 , V_217 -> V_25 , & V_215 ) ) {
struct V_182 * V_224 ;
struct V_1 V_225 ;
V_224 = V_216 ;
V_216 = V_217 ;
V_217 = V_224 ;
V_225 = V_214 ;
V_214 = V_215 ;
V_215 = V_225 ;
V_218 = V_216 -> V_25 -> V_31 ;
V_219 = V_217 -> V_25 -> V_31 ;
V_223 = 1 ;
}
V_181 -> V_185 = F_116 ( V_181 , V_216 , & V_214 ,
V_217 , & V_215 ,
& V_15 , & V_220 ) ;
if ( V_223 )
V_181 -> V_185 = ! V_181 -> V_185 ;
if ( V_15 < V_214 . V_15 ) {
V_15 = V_214 . V_15 - V_15 ;
V_222 = V_214 . V_16 - V_220 ;
V_222 += V_15 * sizeof( V_193 ) ;
V_221 = V_215 . V_17 - F_102 ( V_218 ) ;
V_221 -= V_215 . V_15 * sizeof( V_193 ) ;
if ( V_222 > V_221 )
F_104 ( args , & V_215 , V_217 -> V_25 ) ;
F_112 ( V_218 , & V_214 , V_214 . V_15 - V_15 ,
V_219 , & V_215 , 0 , V_15 , V_181 -> V_27 ) ;
} else if ( V_15 > V_214 . V_15 ) {
ASSERT ( 0 ) ;
V_15 -= V_214 . V_15 ;
V_222 = V_220 - V_214 . V_16 ;
V_222 += V_15 * sizeof( V_193 ) ;
V_221 = V_214 . V_17 - F_102 ( V_218 ) ;
V_221 -= V_214 . V_15 * sizeof( V_193 ) ;
if ( V_222 > V_221 )
F_104 ( args , & V_214 , V_216 -> V_25 ) ;
F_112 ( V_219 , & V_215 , 0 , V_218 , & V_214 ,
V_214 . V_15 , V_15 , V_181 -> V_27 ) ;
}
F_5 ( V_218 , & V_214 ) ;
F_5 ( V_219 , & V_215 ) ;
F_86 ( args -> V_99 , V_216 -> V_25 , 0 , V_181 -> V_226 - 1 ) ;
F_86 ( args -> V_99 , V_217 -> V_25 , 0 , V_181 -> V_226 - 1 ) ;
V_212 = F_78 ( V_218 ) ;
V_213 = F_78 ( V_219 ) ;
V_216 -> V_131 = F_3 ( V_212 [ V_214 . V_15 - 1 ] . V_131 ) ;
V_217 -> V_131 = F_3 ( V_213 [ V_215 . V_15 - 1 ] . V_131 ) ;
if ( V_216 -> V_190 > V_214 . V_15 ) {
ASSERT ( V_181 -> V_185 == 0 ) ;
V_217 -> V_190 = V_216 -> V_190 - V_214 . V_15 ;
args -> V_190 = args -> V_200 = V_217 -> V_190 ;
args -> V_37 = args -> V_199 = V_217 -> V_37 ;
} else if ( V_216 -> V_190 == V_214 . V_15 ) {
if ( V_181 -> V_185 ) {
args -> V_190 = V_216 -> V_190 ;
args -> V_37 = V_216 -> V_37 ;
args -> V_200 = 0 ;
args -> V_199 = V_217 -> V_37 ;
} else {
V_217 -> V_190 = V_216 -> V_190 - V_214 . V_15 ;
args -> V_190 = V_217 -> V_190 ;
args -> V_37 = V_217 -> V_37 ;
if ( ! V_181 -> V_227 ) {
args -> V_200 = V_217 -> V_190 ;
args -> V_199 = V_217 -> V_37 ;
}
}
} else {
ASSERT ( V_181 -> V_185 == 1 ) ;
args -> V_190 = args -> V_200 = V_216 -> V_190 ;
args -> V_37 = args -> V_199 = V_216 -> V_37 ;
}
}
STATIC int
F_116 (
struct V_180 * V_181 ,
struct V_182 * V_216 ,
struct V_1 * V_214 ,
struct V_182 * V_217 ,
struct V_1 * V_215 ,
int * V_228 ,
int * V_229 )
{
struct V_3 * V_218 = V_216 -> V_25 -> V_31 ;
struct V_3 * V_219 = V_217 -> V_25 -> V_31 ;
struct V_150 * V_151 ;
int V_15 ;
int V_221 ;
int V_190 ;
int V_220 = 0 ;
int V_230 ;
int V_231 ;
int V_232 = 0 ;
int V_189 ;
V_221 = V_214 -> V_15 + V_215 -> V_15 ;
V_230 = ( V_221 + 1 ) * sizeof( * V_151 ) ;
V_230 += V_214 -> V_16 + V_215 -> V_16 +
F_101 ( V_181 -> args -> V_106 ,
V_181 -> args -> V_110 ,
V_181 -> V_226 , NULL ) ;
V_230 /= 2 ;
V_231 = V_181 -> V_226 ;
V_151 = F_78 ( V_218 ) ;
for ( V_15 = V_190 = 0 ; V_15 < V_221 ; V_151 ++ , V_190 ++ , V_15 ++ ) {
#define F_117 ( T_15 ) (((A) < 0) ? -(A) : (A))
if ( V_15 == V_216 -> V_190 ) {
V_189 = V_220 + sizeof( * V_151 ) +
F_101 (
V_181 -> args -> V_106 ,
V_181 -> args -> V_110 ,
V_181 -> V_226 , NULL ) ;
if ( F_117 ( V_230 - V_189 ) > V_231 )
break;
V_231 = F_117 ( V_230 - V_189 ) ;
V_220 = V_189 ;
V_232 = 1 ;
}
if ( V_15 == V_214 -> V_15 ) {
V_218 = V_219 ;
V_151 = F_78 ( V_218 ) ;
V_190 = 0 ;
}
V_189 = V_220 + sizeof( * V_151 ) + F_110 ( V_218 ,
V_190 ) ;
if ( F_117 ( V_230 - V_189 ) > V_231 )
break;
V_231 = F_117 ( V_230 - V_189 ) ;
V_220 = V_189 ;
#undef F_117
}
V_220 -= V_15 * sizeof( * V_151 ) ;
if ( V_232 ) {
V_220 -= sizeof( * V_151 ) +
F_101 (
V_181 -> args -> V_106 ,
V_181 -> args -> V_110 ,
V_181 -> V_226 , NULL ) ;
}
* V_228 = V_15 ;
* V_229 = V_220 ;
return V_232 ;
}
int
F_118 (
struct V_180 * V_181 ,
int * V_233 )
{
struct V_3 * V_30 ;
struct V_182 * V_234 ;
struct V_1 V_32 ;
struct V_24 * V_25 ;
T_1 V_37 ;
int V_63 ;
int V_235 ;
int error ;
int V_236 ;
int V_5 ;
F_119 ( V_181 -> args ) ;
V_234 = & V_181 -> V_237 . V_234 [ V_181 -> V_237 . V_238 - 1 ] ;
V_30 = V_234 -> V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_63 = F_102 ( V_30 ) +
V_32 . V_15 * sizeof( V_193 ) +
V_32 . V_16 ;
if ( V_63 > ( V_181 -> V_226 >> 1 ) ) {
* V_233 = 0 ;
return ( 0 ) ;
}
if ( V_32 . V_15 == 0 ) {
V_235 = ( V_32 . V_13 != 0 ) ;
memcpy ( & V_181 -> V_239 , & V_181 -> V_237 , sizeof( V_181 -> V_237 ) ) ;
error = F_120 ( V_181 , & V_181 -> V_239 , V_235 ,
0 , & V_236 ) ;
if ( error )
return ( error ) ;
if ( V_236 ) {
* V_233 = 0 ;
} else {
* V_233 = 2 ;
}
return 0 ;
}
V_235 = V_32 . V_13 < V_32 . V_14 ;
for ( V_5 = 0 ; V_5 < 2 ; V_235 = ! V_235 , V_5 ++ ) {
struct V_1 V_215 ;
if ( V_235 )
V_37 = V_32 . V_13 ;
else
V_37 = V_32 . V_14 ;
if ( V_37 == 0 )
continue;
error = F_19 ( V_181 -> args -> V_99 , V_181 -> args -> V_53 ,
V_37 , - 1 , & V_25 ) ;
if ( error )
return ( error ) ;
F_1 ( & V_215 , V_25 -> V_31 ) ;
V_63 = V_181 -> V_226 - ( V_181 -> V_226 >> 2 ) -
V_32 . V_16 - V_215 . V_16 -
( ( V_32 . V_15 + V_215 . V_15 ) *
sizeof( V_193 ) ) -
F_102 ( V_30 ) ;
F_121 ( V_181 -> args -> V_99 , V_25 ) ;
if ( V_63 >= 0 )
break;
}
if ( V_5 >= 2 ) {
* V_233 = 0 ;
return ( 0 ) ;
}
memcpy ( & V_181 -> V_239 , & V_181 -> V_237 , sizeof( V_181 -> V_237 ) ) ;
if ( V_37 < V_234 -> V_37 ) {
error = F_120 ( V_181 , & V_181 -> V_239 , V_235 ,
0 , & V_236 ) ;
} else {
error = F_120 ( V_181 , & V_181 -> V_237 , V_235 ,
0 , & V_236 ) ;
}
if ( error )
return ( error ) ;
if ( V_236 ) {
* V_233 = 0 ;
} else {
* V_233 = 1 ;
}
return ( 0 ) ;
}
int
F_122 (
struct V_24 * V_25 ,
struct V_159 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_150 * V_151 ;
struct V_26 * V_27 = args -> V_99 -> V_191 ;
int V_176 ;
int V_240 ;
int V_241 ;
int V_187 ;
int V_186 ;
int V_189 ;
int V_5 ;
F_123 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( V_32 . V_15 > 0 && V_32 . V_15 < F_82 ( V_27 ) / 8 ) ;
ASSERT ( args -> V_190 >= 0 && args -> V_190 < V_32 . V_15 ) ;
ASSERT ( V_32 . V_17 >= V_32 . V_15 * sizeof( * V_151 ) +
F_102 ( V_30 ) ) ;
V_151 = & F_78 ( V_30 ) [ args -> V_190 ] ;
ASSERT ( F_4 ( V_151 -> V_163 ) >= V_32 . V_17 ) ;
ASSERT ( F_4 ( V_151 -> V_163 ) < F_82 ( V_27 ) ) ;
V_186 = V_32 . V_15 * sizeof( V_193 )
+ F_102 ( V_30 ) ;
V_189 = V_32 . V_20 [ 0 ] . V_22 ;
V_176 = V_240 = - 1 ;
V_241 = V_19 - 1 ;
V_187 = F_110 ( V_30 , args -> V_190 ) ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
ASSERT ( V_32 . V_20 [ V_5 ] . V_21 < F_82 ( V_27 ) ) ;
ASSERT ( V_32 . V_20 [ V_5 ] . V_22 < F_82 ( V_27 ) ) ;
if ( V_32 . V_20 [ V_5 ] . V_21 == V_186 ) {
V_32 . V_20 [ V_5 ] . V_21 -= sizeof( V_193 ) ;
V_32 . V_20 [ V_5 ] . V_22 += sizeof( V_193 ) ;
}
if ( V_32 . V_20 [ V_5 ] . V_21 + V_32 . V_20 [ V_5 ] . V_22 ==
F_4 ( V_151 -> V_163 ) ) {
V_176 = V_5 ;
} else if ( V_32 . V_20 [ V_5 ] . V_21 ==
( F_4 ( V_151 -> V_163 ) + V_187 ) ) {
V_240 = V_5 ;
} else if ( V_32 . V_20 [ V_5 ] . V_22 < V_189 ) {
V_189 = V_32 . V_20 [ V_5 ] . V_22 ;
V_241 = V_5 ;
}
}
if ( ( V_176 >= 0 ) || ( V_240 >= 0 ) ) {
if ( ( V_176 >= 0 ) && ( V_240 >= 0 ) ) {
V_32 . V_20 [ V_176 ] . V_22 += V_187 ;
V_32 . V_20 [ V_176 ] . V_22 += V_32 . V_20 [ V_240 ] . V_22 ;
V_32 . V_20 [ V_240 ] . V_21 = 0 ;
V_32 . V_20 [ V_240 ] . V_22 = 0 ;
} else if ( V_176 >= 0 ) {
V_32 . V_20 [ V_176 ] . V_22 += V_187 ;
} else {
V_32 . V_20 [ V_240 ] . V_21 = F_4 ( V_151 -> V_163 ) ;
V_32 . V_20 [ V_240 ] . V_22 += V_187 ;
}
} else {
if ( V_32 . V_20 [ V_241 ] . V_22 < V_187 ) {
V_32 . V_20 [ V_241 ] . V_21 = F_4 ( V_151 -> V_163 ) ;
V_32 . V_20 [ V_241 ] . V_22 = V_187 ;
}
}
if ( F_4 ( V_151 -> V_163 ) == V_32 . V_17 )
V_241 = 1 ;
else
V_241 = 0 ;
memset ( F_109 ( V_30 , args -> V_190 ) , 0 , V_187 ) ;
V_32 . V_16 -= V_187 ;
F_86 ( args -> V_99 , V_25 ,
F_105 ( V_30 , F_109 ( V_30 , args -> V_190 ) ,
V_187 ) ) ;
V_189 = ( V_32 . V_15 - args -> V_190 ) * sizeof( V_193 ) ;
memmove ( V_151 , V_151 + 1 , V_189 ) ;
V_32 . V_15 -- ;
F_86 ( args -> V_99 , V_25 ,
F_105 ( V_30 , V_151 , V_189 + sizeof( V_193 ) ) ) ;
V_151 = & F_78 ( V_30 ) [ V_32 . V_15 ] ;
memset ( V_151 , 0 , sizeof( V_193 ) ) ;
if ( V_241 ) {
V_189 = F_82 ( V_27 ) ;
V_151 = F_78 ( V_30 ) ;
for ( V_5 = V_32 . V_15 - 1 ; V_5 >= 0 ; V_151 ++ , V_5 -- ) {
ASSERT ( F_4 ( V_151 -> V_163 ) >= V_32 . V_17 ) ;
ASSERT ( F_4 ( V_151 -> V_163 ) < F_82 ( V_27 ) ) ;
if ( F_4 ( V_151 -> V_163 ) < V_189 )
V_189 = F_4 ( V_151 -> V_163 ) ;
}
V_32 . V_17 = V_189 ;
if ( ! V_32 . V_17 )
V_32 . V_17 = V_189 - V_242 ;
} else {
V_32 . V_18 = 1 ;
}
F_5 ( V_30 , & V_32 ) ;
F_86 ( args -> V_99 , V_25 ,
F_105 ( V_30 , & V_30 -> V_6 ,
F_102 ( V_30 ) ) ) ;
V_189 = V_32 . V_16 + F_102 ( V_30 ) +
V_32 . V_15 * sizeof( V_193 ) ;
return V_189 < V_27 -> V_243 ;
}
void
F_124 (
struct V_180 * V_181 ,
struct V_182 * V_244 ,
struct V_182 * V_245 )
{
struct V_3 * V_246 = V_244 -> V_25 -> V_31 ;
struct V_3 * V_247 = V_245 -> V_25 -> V_31 ;
struct V_1 V_248 ;
struct V_1 V_249 ;
struct V_150 * V_151 ;
struct V_26 * V_27 = V_181 -> V_27 ;
F_125 ( V_181 -> args ) ;
V_246 = V_244 -> V_25 -> V_31 ;
V_247 = V_245 -> V_25 -> V_31 ;
F_1 ( & V_248 , V_246 ) ;
F_1 ( & V_249 , V_247 ) ;
V_151 = F_78 ( V_246 ) ;
V_244 -> V_131 = F_3 ( V_151 [ V_248 . V_15 - 1 ] . V_131 ) ;
if ( V_249 . V_18 == 0 ) {
if ( F_113 ( V_245 -> V_25 , & V_249 ,
V_244 -> V_25 , & V_248 ) ) {
F_112 ( V_246 , & V_248 , 0 ,
V_247 , & V_249 , 0 ,
V_248 . V_15 , V_27 ) ;
} else {
F_112 ( V_246 , & V_248 , 0 ,
V_247 , & V_249 ,
V_249 . V_15 , V_248 . V_15 , V_27 ) ;
}
} else {
struct V_3 * V_250 ;
struct V_1 V_251 ;
V_250 = F_126 ( V_181 -> V_226 , V_123 ) ;
memcpy ( V_250 , V_247 , F_102 ( V_247 ) ) ;
memset ( & V_251 , 0 , sizeof( V_251 ) ) ;
V_251 . V_8 = V_249 . V_8 ;
V_251 . V_13 = V_249 . V_13 ;
V_251 . V_14 = V_249 . V_14 ;
V_251 . V_17 = V_181 -> V_226 ;
F_5 ( V_250 , & V_251 ) ;
if ( F_113 ( V_245 -> V_25 , & V_249 ,
V_244 -> V_25 , & V_248 ) ) {
F_112 ( V_246 , & V_248 , 0 ,
V_250 , & V_251 , 0 ,
V_248 . V_15 , V_27 ) ;
F_112 ( V_247 , & V_249 , 0 ,
V_250 , & V_251 , V_251 . V_15 ,
V_249 . V_15 , V_27 ) ;
} else {
F_112 ( V_247 , & V_249 , 0 ,
V_250 , & V_251 , 0 ,
V_249 . V_15 , V_27 ) ;
F_112 ( V_246 , & V_248 , 0 ,
V_250 , & V_251 , V_251 . V_15 ,
V_248 . V_15 , V_27 ) ;
}
memcpy ( V_247 , V_250 , V_181 -> V_226 ) ;
V_249 = V_251 ;
F_69 ( V_250 ) ;
}
F_5 ( V_247 , & V_249 ) ;
F_86 ( V_181 -> args -> V_99 , V_245 -> V_25 , 0 ,
V_181 -> V_226 - 1 ) ;
V_151 = F_78 ( V_247 ) ;
V_245 -> V_131 = F_3 ( V_151 [ V_249 . V_15 - 1 ] . V_131 ) ;
}
int
F_67 (
struct V_24 * V_25 ,
struct V_159 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_150 * V_151 ;
struct V_150 * V_165 ;
struct V_160 * V_152 ;
struct V_196 * V_197 ;
T_16 V_131 ;
int V_252 ;
int V_253 ;
F_127 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_165 = F_78 ( V_30 ) ;
ASSERT ( V_32 . V_15 < F_82 ( args -> V_53 -> V_68 ) / 8 ) ;
V_131 = args -> V_131 ;
V_252 = V_253 = V_32 . V_15 / 2 ;
for ( V_151 = & V_165 [ V_252 ] ; V_253 > 4 ; V_151 = & V_165 [ V_252 ] ) {
V_253 /= 2 ;
if ( F_3 ( V_151 -> V_131 ) < V_131 )
V_252 += V_253 ;
else if ( F_3 ( V_151 -> V_131 ) > V_131 )
V_252 -= V_253 ;
else
break;
}
ASSERT ( V_252 >= 0 && ( ! V_32 . V_15 || V_252 < V_32 . V_15 ) ) ;
ASSERT ( V_253 <= 4 || F_3 ( V_151 -> V_131 ) == V_131 ) ;
while ( V_252 > 0 && F_3 ( V_151 -> V_131 ) >= V_131 ) {
V_151 -- ;
V_252 -- ;
}
while ( V_252 < V_32 . V_15 &&
F_3 ( V_151 -> V_131 ) < V_131 ) {
V_151 ++ ;
V_252 ++ ;
}
if ( V_252 == V_32 . V_15 || F_3 ( V_151 -> V_131 ) != V_131 ) {
args -> V_190 = V_252 ;
return F_54 ( V_115 ) ;
}
for (; V_252 < V_32 . V_15 && ( F_3 ( V_151 -> V_131 ) == V_131 ) ;
V_151 ++ , V_252 ++ ) {
if ( ( args -> V_109 & V_155 ) !=
( V_151 -> V_109 & V_155 ) ) {
continue;
}
if ( V_151 -> V_109 & V_156 ) {
V_152 = F_79 ( V_30 , V_252 ) ;
if ( V_152 -> V_106 != args -> V_106 )
continue;
if ( memcmp ( args -> V_107 , V_152 -> V_108 ,
args -> V_106 ) != 0 )
continue;
if ( ! F_22 ( args -> V_109 , V_151 -> V_109 ) )
continue;
args -> V_190 = V_252 ;
return F_54 ( V_118 ) ;
} else {
V_197 = F_107 ( V_30 , V_252 ) ;
if ( V_197 -> V_106 != args -> V_106 )
continue;
if ( memcmp ( args -> V_107 , V_197 -> V_107 ,
args -> V_106 ) != 0 )
continue;
if ( ! F_22 ( args -> V_109 , V_151 -> V_109 ) )
continue;
args -> V_190 = V_252 ;
args -> V_110 = F_3 ( V_197 -> V_110 ) ;
args -> V_202 = F_3 ( V_197 -> V_201 ) ;
args -> V_203 = F_108 (
args -> V_53 -> V_68 ,
args -> V_110 ) ;
return F_54 ( V_118 ) ;
}
}
args -> V_190 = V_252 ;
return F_54 ( V_115 ) ;
}
int
F_128 (
struct V_24 * V_25 ,
struct V_159 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_150 * V_151 ;
struct V_160 * V_152 ;
struct V_196 * V_197 ;
int V_110 ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( V_32 . V_15 < F_82 ( args -> V_53 -> V_68 ) / 8 ) ;
ASSERT ( args -> V_190 < V_32 . V_15 ) ;
V_151 = & F_78 ( V_30 ) [ args -> V_190 ] ;
if ( V_151 -> V_109 & V_156 ) {
V_152 = F_79 ( V_30 , args -> V_190 ) ;
ASSERT ( V_152 -> V_106 == args -> V_106 ) ;
ASSERT ( memcmp ( args -> V_107 , V_152 -> V_108 , args -> V_106 ) == 0 ) ;
V_110 = F_4 ( V_152 -> V_110 ) ;
if ( args -> V_109 & V_119 ) {
args -> V_110 = V_110 ;
return 0 ;
}
if ( args -> V_110 < V_110 ) {
args -> V_110 = V_110 ;
return F_54 ( V_120 ) ;
}
args -> V_110 = V_110 ;
memcpy ( args -> V_111 , & V_152 -> V_108 [ args -> V_106 ] , V_110 ) ;
} else {
V_197 = F_107 ( V_30 , args -> V_190 ) ;
ASSERT ( V_197 -> V_106 == args -> V_106 ) ;
ASSERT ( memcmp ( args -> V_107 , V_197 -> V_107 , args -> V_106 ) == 0 ) ;
V_110 = F_3 ( V_197 -> V_110 ) ;
args -> V_202 = F_3 ( V_197 -> V_201 ) ;
args -> V_203 = F_108 ( args -> V_53 -> V_68 ,
V_110 ) ;
if ( args -> V_109 & V_119 ) {
args -> V_110 = V_110 ;
return 0 ;
}
if ( args -> V_110 < V_110 ) {
args -> V_110 = V_110 ;
return F_54 ( V_120 ) ;
}
args -> V_110 = V_110 ;
}
return 0 ;
}
STATIC void
F_112 (
struct V_3 * V_254 ,
struct V_1 * V_255 ,
int V_256 ,
struct V_3 * V_257 ,
struct V_1 * V_258 ,
int V_259 ,
int V_15 ,
struct V_26 * V_27 )
{
struct V_150 * V_260 ;
struct V_150 * V_261 ;
int V_262 ;
int V_189 ;
int V_5 ;
if ( V_15 == 0 )
return;
ASSERT ( V_255 -> V_8 == V_9 ||
V_255 -> V_8 == V_10 ) ;
ASSERT ( V_255 -> V_8 == V_258 -> V_8 ) ;
ASSERT ( V_255 -> V_15 > 0 && V_255 -> V_15 < F_82 ( V_27 ) / 8 ) ;
ASSERT ( V_255 -> V_17 >= ( V_255 -> V_15 * sizeof( * V_260 ) )
+ F_102 ( V_254 ) ) ;
ASSERT ( V_258 -> V_15 < F_82 ( V_27 ) / 8 ) ;
ASSERT ( V_258 -> V_17 >= ( V_258 -> V_15 * sizeof( * V_261 ) )
+ F_102 ( V_257 ) ) ;
ASSERT ( V_256 < V_255 -> V_15 ) ;
ASSERT ( V_259 <= V_258 -> V_15 ) ;
ASSERT ( V_15 <= V_255 -> V_15 ) ;
if ( V_259 < V_258 -> V_15 ) {
V_189 = V_258 -> V_15 - V_259 ;
V_189 *= sizeof( V_193 ) ;
V_260 = & F_78 ( V_257 ) [ V_259 ] ;
V_261 = & F_78 ( V_257 ) [ V_259 + V_15 ] ;
memmove ( V_261 , V_260 , V_189 ) ;
}
V_260 = & F_78 ( V_254 ) [ V_256 ] ;
V_261 = & F_78 ( V_257 ) [ V_259 ] ;
V_262 = V_259 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_260 ++ , V_261 ++ , V_262 ++ , V_5 ++ ) {
ASSERT ( F_4 ( V_260 -> V_163 ) >= V_255 -> V_17 ) ;
V_189 = F_110 ( V_254 , V_256 + V_5 ) ;
#ifdef F_129
if ( V_260 -> V_109 & V_155 ) {
memset ( F_109 ( V_254 , V_256 + V_5 ) , 0 , V_189 ) ;
V_255 -> V_16 -= V_189 ;
V_255 -> V_15 -= 1 ;
V_261 -- ;
V_262 -- ;
if ( ( V_256 + V_5 ) < V_64 )
V_263 ++ ;
} else {
#endif
V_258 -> V_17 -= V_189 ;
V_261 -> V_131 = V_260 -> V_131 ;
V_261 -> V_163 = F_2 ( V_258 -> V_17 ) ;
V_261 -> V_109 = V_260 -> V_109 ;
ASSERT ( F_4 ( V_261 -> V_163 ) + V_189
<= F_82 ( V_27 ) ) ;
memmove ( F_109 ( V_257 , V_262 ) ,
F_109 ( V_254 , V_256 + V_5 ) , V_189 ) ;
ASSERT ( F_4 ( V_260 -> V_163 ) + V_189
<= F_82 ( V_27 ) ) ;
memset ( F_109 ( V_254 , V_256 + V_5 ) , 0 , V_189 ) ;
V_255 -> V_16 -= V_189 ;
V_258 -> V_16 += V_189 ;
V_255 -> V_15 -= 1 ;
V_258 -> V_15 += 1 ;
V_189 = V_258 -> V_15 * sizeof( V_193 )
+ F_102 ( V_257 ) ;
ASSERT ( V_258 -> V_17 >= V_189 ) ;
#ifdef F_129
}
#endif
}
if ( V_256 == V_255 -> V_15 ) {
V_189 = V_15 * sizeof( V_193 ) ;
V_260 = & F_78 ( V_254 ) [ V_256 ] ;
ASSERT ( ( ( char * ) V_260 + V_189 ) <=
( ( char * ) V_254 + F_82 ( V_27 ) ) ) ;
memset ( V_260 , 0 , V_189 ) ;
} else {
V_189 = ( V_255 -> V_15 - V_15 ) * sizeof( V_193 ) ;
V_260 = & F_78 ( V_254 ) [ V_256 + V_15 ] ;
V_261 = & F_78 ( V_254 ) [ V_256 ] ;
memmove ( V_261 , V_260 , V_189 ) ;
V_189 = V_15 * sizeof( V_193 ) ;
V_260 = & F_78 ( V_254 ) [ V_255 -> V_15 ] ;
ASSERT ( ( ( char * ) V_260 + V_189 ) <=
( ( char * ) V_254 + F_82 ( V_27 ) ) ) ;
memset ( V_260 , 0 , V_189 ) ;
}
V_258 -> V_20 [ 0 ] . V_21 = F_102 ( V_257 ) ;
V_258 -> V_20 [ 0 ] . V_21 += V_258 -> V_15 * sizeof( V_193 ) ;
V_258 -> V_20 [ 0 ] . V_22 = V_258 -> V_17 - V_258 -> V_20 [ 0 ] . V_21 ;
V_258 -> V_20 [ 1 ] . V_21 = 0 ;
V_258 -> V_20 [ 2 ] . V_21 = 0 ;
V_258 -> V_20 [ 1 ] . V_22 = 0 ;
V_258 -> V_20 [ 2 ] . V_22 = 0 ;
V_255 -> V_18 = 1 ;
}
T_16
F_99 (
struct V_24 * V_25 ,
int * V_15 )
{
struct V_1 V_32 ;
struct V_150 * V_165 ;
F_1 ( & V_32 , V_25 -> V_31 ) ;
V_165 = F_78 ( V_25 -> V_31 ) ;
if ( V_15 )
* V_15 = V_32 . V_15 ;
if ( ! V_32 . V_15 )
return 0 ;
return F_3 ( V_165 [ V_32 . V_15 - 1 ] . V_131 ) ;
}
STATIC int
F_110 ( V_162 * V_30 , int V_190 )
{
struct V_150 * V_165 ;
T_14 * V_152 ;
T_17 * V_197 ;
int V_22 ;
V_165 = F_78 ( V_30 ) ;
if ( V_165 [ V_190 ] . V_109 & V_156 ) {
V_152 = F_79 ( V_30 , V_190 ) ;
V_22 = F_130 ( V_152 -> V_106 ,
F_4 ( V_152 -> V_110 ) ) ;
} else {
V_197 = F_107 ( V_30 , V_190 ) ;
V_22 = F_131 ( V_197 -> V_106 ) ;
}
return V_22 ;
}
int
F_101 ( int V_106 , int V_110 , int V_226 , int * V_264 )
{
int V_22 ;
V_22 = F_130 ( V_106 , V_110 ) ;
if ( V_22 < F_132 ( V_226 ) ) {
if ( V_264 ) {
* V_264 = 1 ;
}
} else {
V_22 = F_131 ( V_106 ) ;
if ( V_264 ) {
* V_264 = 0 ;
}
}
return V_22 ;
}
int
F_133 (
struct V_24 * V_25 ,
struct V_265 * V_139 )
{
struct V_266 * V_140 ;
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_150 * V_165 ;
struct V_150 * V_151 ;
int V_236 ;
int V_5 ;
F_134 ( V_139 ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_165 = F_78 ( V_30 ) ;
V_140 = V_139 -> V_140 ;
V_140 -> V_149 = 1 ;
if ( V_139 -> V_267 ) {
V_151 = & V_165 [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_32 . V_15 ; V_151 ++ , V_5 ++ ) {
if ( F_3 ( V_151 -> V_131 ) == V_140 -> V_131 ) {
if ( V_140 -> V_64 == V_139 -> V_268 ) {
V_139 -> V_268 = 0 ;
break;
}
V_139 -> V_268 ++ ;
} else if ( F_3 ( V_151 -> V_131 ) >
V_140 -> V_131 ) {
V_139 -> V_268 = 0 ;
break;
}
}
if ( V_5 == V_32 . V_15 ) {
F_135 ( V_139 ) ;
return 0 ;
}
} else {
V_151 = & V_165 [ 0 ] ;
V_5 = 0 ;
}
V_139 -> V_267 = 0 ;
V_236 = 0 ;
for (; V_5 < V_32 . V_15 ; V_151 ++ , V_5 ++ ) {
if ( F_3 ( V_151 -> V_131 ) != V_140 -> V_131 ) {
V_140 -> V_131 = F_3 ( V_151 -> V_131 ) ;
V_140 -> V_64 = 0 ;
}
if ( V_151 -> V_109 & V_155 )
continue;
if ( V_151 -> V_109 & V_156 ) {
T_14 * V_152 =
F_79 ( V_30 , V_5 ) ;
V_236 = V_139 -> V_146 ( V_139 ,
V_151 -> V_109 ,
V_152 -> V_108 ,
( int ) V_152 -> V_106 ,
F_4 ( V_152 -> V_110 ) ,
& V_152 -> V_108 [ V_152 -> V_106 ] ) ;
if ( V_236 )
return V_236 ;
} else {
T_17 * V_197 =
F_107 ( V_30 , V_5 ) ;
int V_110 = F_3 ( V_197 -> V_110 ) ;
if ( V_139 -> V_269 ) {
T_6 args ;
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_53 = V_139 -> V_53 ;
args . V_129 = V_58 ;
args . V_110 = V_110 ;
args . V_111 = F_60 ( V_110 , V_123 | V_148 ) ;
args . V_202 = F_3 ( V_197 -> V_201 ) ;
args . V_203 = F_108 (
args . V_53 -> V_68 , V_110 ) ;
V_236 = F_136 ( & args ) ;
if ( V_236 )
return V_236 ;
V_236 = V_139 -> V_146 ( V_139 ,
V_151 -> V_109 ,
V_197 -> V_107 ,
( int ) V_197 -> V_106 ,
V_110 ,
args . V_111 ) ;
F_69 ( args . V_111 ) ;
} else {
V_236 = V_139 -> V_146 ( V_139 ,
V_151 -> V_109 ,
V_197 -> V_107 ,
( int ) V_197 -> V_106 ,
V_110 ,
NULL ) ;
}
if ( V_236 )
return V_236 ;
}
if ( V_139 -> V_147 )
break;
V_140 -> V_64 ++ ;
}
F_137 ( V_139 ) ;
return V_236 ;
}
int
F_138 (
struct V_159 * args )
{
struct V_3 * V_30 ;
struct V_150 * V_151 ;
struct V_196 * V_197 ;
struct V_24 * V_25 ;
int error ;
#ifdef F_46
struct V_1 V_32 ;
T_14 * V_152 ;
int V_106 ;
char * V_107 ;
#endif
F_139 ( args ) ;
error = F_19 ( args -> V_99 , args -> V_53 , args -> V_37 , - 1 , & V_25 ) ;
if ( error )
return ( error ) ;
V_30 = V_25 -> V_31 ;
V_151 = & F_78 ( V_30 ) [ args -> V_190 ] ;
ASSERT ( V_151 -> V_109 & V_155 ) ;
#ifdef F_46
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_190 < V_32 . V_15 ) ;
ASSERT ( args -> V_190 >= 0 ) ;
if ( V_151 -> V_109 & V_156 ) {
V_152 = F_79 ( V_30 , args -> V_190 ) ;
V_106 = V_152 -> V_106 ;
V_107 = ( char * ) V_152 -> V_108 ;
} else {
V_197 = F_107 ( V_30 , args -> V_190 ) ;
V_106 = V_197 -> V_106 ;
V_107 = ( char * ) V_197 -> V_107 ;
}
ASSERT ( F_3 ( V_151 -> V_131 ) == args -> V_131 ) ;
ASSERT ( V_106 == args -> V_106 ) ;
ASSERT ( memcmp ( V_107 , args -> V_107 , V_106 ) == 0 ) ;
#endif
V_151 -> V_109 &= ~ V_155 ;
F_86 ( args -> V_99 , V_25 ,
F_105 ( V_30 , V_151 , sizeof( * V_151 ) ) ) ;
if ( args -> V_202 ) {
ASSERT ( ( V_151 -> V_109 & V_156 ) == 0 ) ;
V_197 = F_107 ( V_30 , args -> V_190 ) ;
V_197 -> V_201 = F_6 ( args -> V_202 ) ;
V_197 -> V_110 = F_6 ( args -> V_110 ) ;
F_86 ( args -> V_99 , V_25 ,
F_105 ( V_30 , V_197 , sizeof( * V_197 ) ) ) ;
}
return F_140 ( & args -> V_99 , args -> V_53 ) ;
}
int
F_141 (
struct V_159 * args )
{
struct V_3 * V_30 ;
struct V_150 * V_151 ;
struct V_196 * V_197 ;
struct V_24 * V_25 ;
int error ;
#ifdef F_46
struct V_1 V_32 ;
#endif
F_142 ( args ) ;
error = F_19 ( args -> V_99 , args -> V_53 , args -> V_37 , - 1 , & V_25 ) ;
if ( error )
return ( error ) ;
V_30 = V_25 -> V_31 ;
#ifdef F_46
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_190 < V_32 . V_15 ) ;
ASSERT ( args -> V_190 >= 0 ) ;
#endif
V_151 = & F_78 ( V_30 ) [ args -> V_190 ] ;
ASSERT ( ( V_151 -> V_109 & V_155 ) == 0 ) ;
V_151 -> V_109 |= V_155 ;
F_86 ( args -> V_99 , V_25 ,
F_105 ( V_30 , V_151 , sizeof( * V_151 ) ) ) ;
if ( ( V_151 -> V_109 & V_156 ) == 0 ) {
V_197 = F_107 ( V_30 , args -> V_190 ) ;
V_197 -> V_201 = 0 ;
V_197 -> V_110 = 0 ;
F_86 ( args -> V_99 , V_25 ,
F_105 ( V_30 , V_197 , sizeof( * V_197 ) ) ) ;
}
return F_140 ( & args -> V_99 , args -> V_53 ) ;
}
int
F_143 (
struct V_159 * args )
{
struct V_3 * V_218 ;
struct V_3 * V_219 ;
struct V_150 * V_270 ;
struct V_150 * V_271 ;
struct V_196 * V_197 ;
struct V_24 * V_172 ;
struct V_24 * V_173 ;
int error ;
#ifdef F_46
struct V_1 V_214 ;
struct V_1 V_215 ;
T_14 * V_152 ;
int V_272 , V_273 ;
char * V_274 , * V_275 ;
#endif
F_144 ( args ) ;
error = F_19 ( args -> V_99 , args -> V_53 , args -> V_37 , - 1 , & V_172 ) ;
if ( error )
return error ;
if ( args -> V_199 != args -> V_37 ) {
error = F_19 ( args -> V_99 , args -> V_53 , args -> V_199 ,
- 1 , & V_173 ) ;
if ( error )
return error ;
} else {
V_173 = V_172 ;
}
V_218 = V_172 -> V_31 ;
V_270 = & F_78 ( V_218 ) [ args -> V_190 ] ;
V_219 = V_173 -> V_31 ;
V_271 = & F_78 ( V_219 ) [ args -> V_200 ] ;
#ifdef F_46
F_1 ( & V_214 , V_218 ) ;
ASSERT ( args -> V_190 < V_214 . V_15 ) ;
ASSERT ( args -> V_190 >= 0 ) ;
F_1 ( & V_215 , V_219 ) ;
ASSERT ( args -> V_200 < V_215 . V_15 ) ;
ASSERT ( args -> V_200 >= 0 ) ;
if ( V_270 -> V_109 & V_156 ) {
V_152 = F_79 ( V_218 , args -> V_190 ) ;
V_272 = V_152 -> V_106 ;
V_274 = ( char * ) V_152 -> V_108 ;
} else {
V_197 = F_107 ( V_218 , args -> V_190 ) ;
V_272 = V_197 -> V_106 ;
V_274 = ( char * ) V_197 -> V_107 ;
}
if ( V_271 -> V_109 & V_156 ) {
V_152 = F_79 ( V_219 , args -> V_200 ) ;
V_273 = V_152 -> V_106 ;
V_275 = ( char * ) V_152 -> V_108 ;
} else {
V_197 = F_107 ( V_219 , args -> V_200 ) ;
V_273 = V_197 -> V_106 ;
V_275 = ( char * ) V_197 -> V_107 ;
}
ASSERT ( F_3 ( V_270 -> V_131 ) == F_3 ( V_271 -> V_131 ) ) ;
ASSERT ( V_272 == V_273 ) ;
ASSERT ( memcmp ( V_274 , V_275 , V_272 ) == 0 ) ;
#endif
ASSERT ( V_270 -> V_109 & V_155 ) ;
ASSERT ( ( V_271 -> V_109 & V_155 ) == 0 ) ;
V_270 -> V_109 &= ~ V_155 ;
F_86 ( args -> V_99 , V_172 ,
F_105 ( V_218 , V_270 , sizeof( * V_270 ) ) ) ;
if ( args -> V_202 ) {
ASSERT ( ( V_270 -> V_109 & V_156 ) == 0 ) ;
V_197 = F_107 ( V_218 , args -> V_190 ) ;
V_197 -> V_201 = F_6 ( args -> V_202 ) ;
V_197 -> V_110 = F_6 ( args -> V_110 ) ;
F_86 ( args -> V_99 , V_172 ,
F_105 ( V_218 , V_197 , sizeof( * V_197 ) ) ) ;
}
V_271 -> V_109 |= V_155 ;
F_86 ( args -> V_99 , V_173 ,
F_105 ( V_219 , V_271 , sizeof( * V_271 ) ) ) ;
if ( ( V_271 -> V_109 & V_156 ) == 0 ) {
V_197 = F_107 ( V_219 , args -> V_200 ) ;
V_197 -> V_201 = 0 ;
V_197 -> V_110 = 0 ;
F_86 ( args -> V_99 , V_173 ,
F_105 ( V_219 , V_197 , sizeof( * V_197 ) ) ) ;
}
error = F_140 ( & args -> V_99 , args -> V_53 ) ;
return error ;
}
int
F_145 (
struct V_50 * * V_99 ,
struct V_52 * V_53 )
{
struct V_276 * V_7 ;
struct V_24 * V_25 ;
T_2 V_37 ;
int error ;
error = F_146 ( * V_99 , V_53 , 0 , - 1 , & V_25 , V_58 ) ;
if ( error )
return error ;
V_37 = V_25 -> V_38 ;
V_7 = V_25 -> V_31 ;
switch ( V_7 -> V_8 ) {
case F_2 ( V_277 ) :
case F_2 ( V_278 ) :
error = F_147 ( V_99 , V_53 , V_25 , 1 ) ;
break;
case F_2 ( V_9 ) :
case F_2 ( V_10 ) :
error = F_148 ( V_99 , V_53 , V_25 ) ;
break;
default:
error = F_54 ( V_124 ) ;
F_121 ( * V_99 , V_25 ) ;
break;
}
if ( error )
return error ;
error = F_85 ( * V_99 , V_53 , 0 , V_37 , & V_25 , V_58 ) ;
if ( error )
return error ;
F_149 ( * V_99 , V_25 ) ;
error = F_140 ( V_99 , V_53 ) ;
return error ;
}
STATIC int
F_147 (
struct V_50 * * V_99 ,
struct V_52 * V_53 ,
struct V_24 * V_25 ,
int V_279 )
{
T_18 * V_7 ;
T_19 * V_171 ;
T_1 V_280 ;
T_2 V_281 , V_282 ;
int error , V_5 ;
struct V_24 * V_283 ;
struct V_166 * V_167 ;
struct V_168 V_32 ;
if ( V_279 > V_284 ) {
F_121 ( * V_99 , V_25 ) ;
return F_54 ( V_124 ) ;
}
V_171 = V_25 -> V_31 ;
F_88 ( & V_32 , V_171 ) ;
V_281 = V_25 -> V_38 ;
if ( ! V_32 . V_15 ) {
F_121 ( * V_99 , V_25 ) ;
return 0 ;
}
V_167 = F_89 ( V_171 ) ;
V_280 = F_3 ( V_167 [ 0 ] . V_176 ) ;
F_121 ( * V_99 , V_25 ) ;
for ( V_5 = 0 ; V_5 < V_32 . V_15 ; V_5 ++ ) {
error = F_146 ( * V_99 , V_53 , V_280 , - 2 , & V_283 ,
V_58 ) ;
if ( error )
return ( error ) ;
if ( V_283 ) {
V_282 = F_150 ( V_283 ) ;
V_7 = V_283 -> V_31 ;
switch ( V_7 -> V_8 ) {
case F_2 ( V_277 ) :
case F_2 ( V_278 ) :
error = F_147 ( V_99 , V_53 ,
V_283 , V_279 + 1 ) ;
break;
case F_2 ( V_9 ) :
case F_2 ( V_10 ) :
error = F_148 ( V_99 , V_53 ,
V_283 ) ;
break;
default:
error = F_54 ( V_124 ) ;
F_121 ( * V_99 , V_283 ) ;
break;
}
if ( error )
return error ;
error = F_85 ( * V_99 , V_53 , 0 , V_282 ,
& V_283 , V_58 ) ;
if ( error )
return error ;
F_149 ( * V_99 , V_283 ) ;
}
if ( V_5 + 1 < V_32 . V_15 ) {
error = F_146 ( * V_99 , V_53 , 0 , V_281 ,
& V_25 , V_58 ) ;
if ( error )
return error ;
V_280 = F_3 ( V_167 [ V_5 + 1 ] . V_176 ) ;
F_121 ( * V_99 , V_25 ) ;
}
error = F_140 ( V_99 , V_53 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_148 (
struct V_50 * * V_99 ,
struct V_52 * V_53 ,
struct V_24 * V_25 )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_150 * V_151 ;
struct V_196 * V_197 ;
struct V_285 * V_105 ;
struct V_285 * V_286 ;
int error ;
int V_15 ;
int V_22 ;
int V_189 ;
int V_5 ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_15 = 0 ;
V_151 = F_78 ( V_30 ) ;
for ( V_5 = 0 ; V_5 < V_32 . V_15 ; V_151 ++ , V_5 ++ ) {
if ( F_4 ( V_151 -> V_163 ) &&
( ( V_151 -> V_109 & V_156 ) == 0 ) ) {
V_197 = F_107 ( V_30 , V_5 ) ;
if ( V_197 -> V_201 )
V_15 ++ ;
}
}
if ( V_15 == 0 ) {
F_121 ( * V_99 , V_25 ) ;
return 0 ;
}
V_22 = V_15 * sizeof( V_287 ) ;
V_105 = F_60 ( V_22 , V_123 ) ;
V_286 = V_105 ;
V_151 = F_78 ( V_30 ) ;
for ( V_5 = 0 ; V_5 < V_32 . V_15 ; V_151 ++ , V_5 ++ ) {
if ( F_4 ( V_151 -> V_163 ) &&
( ( V_151 -> V_109 & V_156 ) == 0 ) ) {
V_197 = F_107 ( V_30 , V_5 ) ;
if ( V_197 -> V_201 ) {
V_286 -> V_201 = F_3 ( V_197 -> V_201 ) ;
V_286 -> V_110 = F_108 ( V_53 -> V_68 ,
F_3 ( V_197 -> V_110 ) ) ;
V_286 ++ ;
}
}
}
F_121 ( * V_99 , V_25 ) ;
error = 0 ;
for ( V_286 = V_105 , V_5 = 0 ; V_5 < V_15 ; V_5 ++ , V_286 ++ ) {
V_189 = F_151 ( V_99 , V_53 ,
V_286 -> V_201 , V_286 -> V_110 ) ;
if ( error == 0 )
error = V_189 ;
}
F_69 ( V_105 ) ;
return error ;
}
STATIC int
F_151 (
struct V_50 * * V_99 ,
struct V_52 * V_53 ,
T_1 V_37 ,
int V_288 )
{
struct V_289 V_290 ;
struct V_24 * V_25 ;
T_1 V_291 ;
T_2 V_292 ;
int V_293 ;
int V_294 ;
int V_295 ;
int error ;
V_291 = V_37 ;
V_293 = V_288 ;
while ( V_293 > 0 ) {
V_295 = 1 ;
error = F_152 ( V_53 , ( V_296 ) V_291 , V_293 ,
& V_290 , & V_295 , V_297 ) ;
if ( error ) {
return ( error ) ;
}
ASSERT ( V_295 == 1 ) ;
ASSERT ( V_290 . V_298 != V_299 ) ;
if ( V_290 . V_298 != V_300 ) {
V_292 = F_153 ( V_53 -> V_68 ,
V_290 . V_298 ) ;
V_294 = F_154 ( V_53 -> V_68 ,
V_290 . V_301 ) ;
V_25 = F_155 ( * V_99 ,
V_53 -> V_68 -> V_302 ,
V_292 , V_294 , 0 ) ;
if ( ! V_25 )
return V_161 ;
F_149 ( * V_99 , V_25 ) ;
error = F_140 ( V_99 , V_53 ) ;
if ( error )
return ( error ) ;
}
V_291 += V_290 . V_301 ;
V_293 -= V_290 . V_301 ;
}
return ( 0 ) ;
}
