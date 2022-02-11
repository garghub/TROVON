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
ASSERT ( args -> V_53 -> V_90 -> V_92 == V_95 ) ;
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
int
F_70 (
struct V_24 * V_25 ,
struct V_52 * V_53 )
{
struct V_3 * V_30 ;
struct V_133 * V_134 ;
T_11 * V_135 ;
struct V_1 V_136 ;
int V_63 ;
int V_5 ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_136 , V_30 ) ;
V_134 = F_71 ( V_30 ) ;
V_63 = sizeof( struct V_137 ) ;
for ( V_5 = 0 ; V_5 < V_136 . V_15 ; V_134 ++ , V_5 ++ ) {
if ( V_134 -> V_109 & V_138 )
continue;
if ( ! ( V_134 -> V_109 & V_139 ) )
return ( 0 ) ;
V_135 = F_72 ( V_30 , V_5 ) ;
if ( V_135 -> V_106 >= V_140 )
return ( 0 ) ;
if ( F_4 ( V_135 -> V_110 ) >= V_140 )
return ( 0 ) ;
V_63 += sizeof( struct V_141 ) - 1
+ V_135 -> V_106
+ F_4 ( V_135 -> V_110 ) ;
}
if ( ( V_53 -> V_68 -> V_77 & V_78 ) &&
( V_53 -> V_69 . V_71 != V_83 ) &&
( V_63 == sizeof( struct V_137 ) ) )
return - 1 ;
return F_25 ( V_53 , V_63 ) ;
}
int
F_73 (
struct V_24 * V_25 ,
struct V_142 * args ,
int V_102 )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_133 * V_134 ;
struct V_143 * V_135 ;
struct V_142 V_121 ;
struct V_52 * V_53 = args -> V_53 ;
char * V_122 ;
int error ;
int V_5 ;
F_74 ( args ) ;
V_122 = F_60 ( F_75 ( V_53 -> V_68 ) , V_123 ) ;
if ( ! V_122 )
return V_144 ;
memcpy ( V_122 , V_25 -> V_31 , F_75 ( V_53 -> V_68 ) ) ;
V_30 = ( V_145 * ) V_122 ;
F_1 ( & V_32 , V_30 ) ;
V_134 = F_71 ( V_30 ) ;
memset ( V_25 -> V_31 , 0 , F_75 ( V_53 -> V_68 ) ) ;
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
for ( V_5 = 0 ; V_5 < V_32 . V_15 ; V_134 ++ , V_5 ++ ) {
if ( V_134 -> V_109 & V_138 )
continue;
if ( ! V_134 -> V_146 )
continue;
ASSERT ( V_134 -> V_109 & V_139 ) ;
V_135 = F_72 ( V_30 , V_5 ) ;
V_121 . V_107 = V_135 -> V_108 ;
V_121 . V_106 = V_135 -> V_106 ;
V_121 . V_111 = & V_135 -> V_108 [ V_121 . V_106 ] ;
V_121 . V_110 = F_4 ( V_135 -> V_110 ) ;
V_121 . V_131 = F_3 ( V_134 -> V_131 ) ;
V_121 . V_109 = F_66 ( V_134 -> V_109 ) ;
F_43 ( & V_121 , V_102 ) ;
}
error = 0 ;
V_125:
F_69 ( V_122 ) ;
return error ;
}
int
F_76 (
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_1 V_147 ;
struct V_133 * V_148 ;
struct V_149 * V_150 ;
struct V_151 V_152 ;
struct V_153 * V_154 ;
struct V_52 * V_53 = args -> V_53 ;
struct V_26 * V_27 = V_53 -> V_68 ;
struct V_24 * V_155 = NULL ;
struct V_24 * V_156 = NULL ;
T_1 V_37 ;
int error ;
F_77 ( args ) ;
error = F_62 ( args , & V_37 ) ;
if ( error )
goto V_125;
error = F_19 ( args -> V_99 , V_53 , 0 , - 1 , & V_155 ) ;
if ( error )
goto V_125;
error = F_78 ( args -> V_99 , V_53 , V_37 , - 1 , & V_156 , V_58 ) ;
if ( error )
goto V_125;
F_21 ( args -> V_99 , V_156 , V_60 ) ;
V_156 -> V_157 = V_155 -> V_157 ;
memcpy ( V_156 -> V_31 , V_155 -> V_31 , F_75 ( V_27 ) ) ;
if ( F_8 ( & V_27 -> V_33 ) ) {
struct V_158 * V_12 = V_156 -> V_31 ;
V_12 -> V_37 = F_14 ( V_156 -> V_38 ) ;
}
F_79 ( args -> V_99 , V_156 , 0 , F_75 ( V_27 ) - 1 ) ;
error = F_80 ( args , 0 , 1 , & V_155 , V_58 ) ;
if ( error )
goto V_125;
V_154 = V_155 -> V_31 ;
F_81 ( & V_152 , V_154 ) ;
V_150 = F_82 ( V_154 ) ;
V_30 = V_156 -> V_31 ;
F_1 ( & V_147 , V_30 ) ;
V_148 = F_71 ( V_30 ) ;
V_150 [ 0 ] . V_131 = V_148 [ V_147 . V_15 - 1 ] . V_131 ;
V_150 [ 0 ] . V_159 = F_6 ( V_37 ) ;
V_152 . V_15 = 1 ;
F_83 ( V_154 , & V_152 ) ;
F_79 ( args -> V_99 , V_155 , 0 , F_75 ( V_27 ) - 1 ) ;
error = 0 ;
V_125:
return error ;
}
STATIC int
F_63 (
struct V_142 * args ,
T_1 V_37 ,
struct V_24 * * V_56 )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_52 * V_53 = args -> V_53 ;
struct V_26 * V_27 = V_53 -> V_68 ;
struct V_24 * V_25 ;
int error ;
F_84 ( args ) ;
error = F_78 ( args -> V_99 , args -> V_53 , V_37 , - 1 , & V_25 ,
V_58 ) ;
if ( error )
return error ;
V_25 -> V_157 = & V_59 ;
F_21 ( args -> V_99 , V_25 , V_60 ) ;
V_30 = V_25 -> V_31 ;
memset ( V_30 , 0 , F_75 ( V_27 ) ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_17 = F_75 ( V_27 ) ;
if ( F_8 ( & V_27 -> V_33 ) ) {
struct V_158 * V_12 = V_25 -> V_31 ;
V_32 . V_8 = V_10 ;
V_12 -> V_37 = F_14 ( V_25 -> V_38 ) ;
V_12 -> V_160 = F_14 ( V_53 -> V_161 ) ;
F_85 ( & V_12 -> V_35 , & V_27 -> V_33 . V_36 ) ;
V_32 . V_20 [ 0 ] . V_21 = sizeof( struct V_11 ) ;
} else {
V_32 . V_8 = V_9 ;
V_32 . V_20 [ 0 ] . V_21 = sizeof( struct V_162 ) ;
}
V_32 . V_20 [ 0 ] . V_22 = V_32 . V_17 - V_32 . V_20 [ 0 ] . V_21 ;
F_5 ( V_30 , & V_32 ) ;
F_79 ( args -> V_99 , V_25 , 0 , F_75 ( V_27 ) - 1 ) ;
* V_56 = V_25 ;
return 0 ;
}
int
F_86 (
struct V_163 * V_164 ,
struct V_165 * V_166 ,
struct V_165 * V_167 )
{
T_1 V_37 ;
int error ;
F_87 ( V_164 -> args ) ;
ASSERT ( V_166 -> V_8 == V_9 ) ;
error = F_62 ( V_164 -> args , & V_37 ) ;
if ( error )
return ( error ) ;
error = F_63 ( V_164 -> args , V_37 , & V_167 -> V_25 ) ;
if ( error )
return ( error ) ;
V_167 -> V_37 = V_37 ;
V_167 -> V_8 = V_9 ;
F_88 ( V_164 , V_166 , V_167 ) ;
error = F_89 ( V_164 , V_166 , V_167 ) ;
if ( error )
return ( error ) ;
if ( V_164 -> V_168 ) {
F_90 ( V_164 -> args ) ;
error = F_68 ( V_166 -> V_25 , V_164 -> args ) ;
} else {
F_91 ( V_164 -> args ) ;
error = F_68 ( V_167 -> V_25 , V_164 -> args ) ;
}
V_166 -> V_131 = F_92 ( V_166 -> V_25 , NULL ) ;
V_167 -> V_131 = F_92 ( V_167 -> V_25 , NULL ) ;
return ( error ) ;
}
int
F_68 (
struct V_24 * V_25 ,
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
int V_169 ;
int V_170 ;
int V_171 ;
int V_172 ;
int V_5 ;
F_93 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_173 >= 0 && args -> V_173 <= V_32 . V_15 ) ;
V_170 = F_94 ( args -> V_106 , args -> V_110 ,
args -> V_99 -> V_174 -> V_33 . V_175 , NULL ) ;
V_169 = ( V_32 . V_15 + 1 ) * sizeof( V_176 )
+ F_95 ( V_30 ) ;
for ( V_171 = 0 , V_5 = V_19 - 1 ; V_5 >= 0 ; V_5 -- ) {
if ( V_169 > V_32 . V_17 ) {
V_171 += V_32 . V_20 [ V_5 ] . V_22 ;
continue;
}
if ( ! V_32 . V_20 [ V_5 ] . V_22 )
continue;
V_172 = V_170 ;
if ( V_32 . V_20 [ V_5 ] . V_21 < V_32 . V_17 )
V_172 += sizeof( V_176 ) ;
if ( V_32 . V_20 [ V_5 ] . V_22 >= V_172 ) {
V_172 = F_96 ( V_25 , & V_32 , args , V_5 ) ;
goto V_177;
}
V_171 += V_32 . V_20 [ V_5 ] . V_22 ;
}
if ( ! V_32 . V_18 && V_171 < V_170 )
return F_54 ( V_132 ) ;
F_97 ( args , & V_32 , V_25 ) ;
if ( V_32 . V_20 [ 0 ] . V_22 < ( V_170 + sizeof( V_176 ) ) ) {
V_172 = V_132 ;
goto V_177;
}
V_172 = F_96 ( V_25 , & V_32 , args , 0 ) ;
V_177:
F_5 ( V_30 , & V_32 ) ;
F_79 ( args -> V_99 , V_25 ,
F_98 ( V_30 , & V_30 -> V_6 ,
F_95 ( V_30 ) ) ) ;
return V_172 ;
}
STATIC int
F_96 (
struct V_24 * V_25 ,
struct V_1 * V_32 ,
struct V_142 * args ,
int V_178 )
{
struct V_3 * V_30 ;
struct V_133 * V_134 ;
struct V_143 * V_135 ;
struct V_179 * V_180 ;
struct V_26 * V_27 ;
int V_172 ;
int V_5 ;
F_99 ( args ) ;
V_30 = V_25 -> V_31 ;
ASSERT ( V_178 >= 0 && V_178 < V_19 ) ;
ASSERT ( args -> V_173 >= 0 && args -> V_173 <= V_32 -> V_15 ) ;
V_134 = & F_71 ( V_30 ) [ args -> V_173 ] ;
if ( args -> V_173 < V_32 -> V_15 ) {
V_172 = V_32 -> V_15 - args -> V_173 ;
V_172 *= sizeof( V_176 ) ;
memmove ( V_134 + 1 , V_134 , V_172 ) ;
F_79 ( args -> V_99 , V_25 ,
F_98 ( V_30 , V_134 , V_172 + sizeof( * V_134 ) ) ) ;
}
V_32 -> V_15 ++ ;
V_27 = args -> V_99 -> V_174 ;
ASSERT ( V_32 -> V_20 [ V_178 ] . V_21 < F_75 ( V_27 ) ) ;
ASSERT ( ( V_32 -> V_20 [ V_178 ] . V_21 & 0x3 ) == 0 ) ;
ASSERT ( V_32 -> V_20 [ V_178 ] . V_22 >=
F_94 ( args -> V_106 , args -> V_110 ,
V_27 -> V_33 . V_175 , NULL ) ) ;
ASSERT ( V_32 -> V_20 [ V_178 ] . V_22 < F_75 ( V_27 ) ) ;
ASSERT ( ( V_32 -> V_20 [ V_178 ] . V_22 & 0x3 ) == 0 ) ;
V_32 -> V_20 [ V_178 ] . V_22 -=
F_94 ( args -> V_106 , args -> V_110 ,
V_27 -> V_33 . V_175 , & V_172 ) ;
V_134 -> V_146 = F_2 ( V_32 -> V_20 [ V_178 ] . V_21 +
V_32 -> V_20 [ V_178 ] . V_22 ) ;
V_134 -> V_131 = F_6 ( args -> V_131 ) ;
V_134 -> V_109 = V_172 ? V_139 : 0 ;
V_134 -> V_109 |= F_24 ( args -> V_109 ) ;
if ( args -> V_116 & V_181 ) {
V_134 -> V_109 |= V_138 ;
if ( ( args -> V_182 == args -> V_37 ) &&
( args -> V_183 <= args -> V_173 ) ) {
args -> V_183 ++ ;
}
}
F_79 ( args -> V_99 , V_25 ,
F_98 ( V_30 , V_134 , sizeof( * V_134 ) ) ) ;
ASSERT ( ( args -> V_173 == 0 ) ||
( F_3 ( V_134 -> V_131 ) >= F_3 ( ( V_134 - 1 ) -> V_131 ) ) ) ;
ASSERT ( ( args -> V_173 == V_32 -> V_15 - 1 ) ||
( F_3 ( V_134 -> V_131 ) <= F_3 ( ( V_134 + 1 ) -> V_131 ) ) ) ;
if ( V_134 -> V_109 & V_139 ) {
V_135 = F_72 ( V_30 , args -> V_173 ) ;
V_135 -> V_106 = args -> V_106 ;
V_135 -> V_110 = F_2 ( args -> V_110 ) ;
memcpy ( ( char * ) V_135 -> V_108 , args -> V_107 , args -> V_106 ) ;
memcpy ( ( char * ) & V_135 -> V_108 [ args -> V_106 ] , args -> V_111 ,
F_4 ( V_135 -> V_110 ) ) ;
} else {
V_180 = F_100 ( V_30 , args -> V_173 ) ;
V_180 -> V_106 = args -> V_106 ;
memcpy ( ( char * ) V_180 -> V_107 , args -> V_107 , args -> V_106 ) ;
V_134 -> V_109 |= V_138 ;
V_180 -> V_110 = 0 ;
V_180 -> V_184 = 0 ;
args -> V_185 = 1 ;
args -> V_186 = F_101 ( V_27 , args -> V_110 ) ;
}
F_79 ( args -> V_99 , V_25 ,
F_98 ( V_30 , F_102 ( V_30 , args -> V_173 ) ,
F_103 ( V_30 , args -> V_173 ) ) ) ;
if ( F_4 ( V_134 -> V_146 ) < V_32 -> V_17 )
V_32 -> V_17 = F_4 ( V_134 -> V_146 ) ;
ASSERT ( V_32 -> V_17 >= V_32 -> V_15 * sizeof( V_176 )
+ F_95 ( V_30 ) ) ;
V_172 = ( V_32 -> V_15 - 1 ) * sizeof( V_176 )
+ F_95 ( V_30 ) ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
if ( V_32 -> V_20 [ V_5 ] . V_21 == V_172 ) {
V_32 -> V_20 [ V_5 ] . V_21 += sizeof( V_176 ) ;
V_32 -> V_20 [ V_5 ] . V_22 -= sizeof( V_176 ) ;
}
}
V_32 -> V_16 += F_103 ( V_30 , args -> V_173 ) ;
return 0 ;
}
STATIC void
F_97 (
struct V_142 * args ,
struct V_1 * V_187 ,
struct V_24 * V_25 )
{
struct V_3 * V_188 ;
struct V_3 * V_189 ;
struct V_1 V_190 ;
struct V_50 * V_99 = args -> V_99 ;
struct V_26 * V_27 = V_99 -> V_174 ;
char * V_122 ;
F_104 ( args ) ;
V_122 = F_60 ( F_75 ( V_27 ) , V_123 ) ;
memcpy ( V_122 , V_25 -> V_31 , F_75 ( V_27 ) ) ;
memset ( V_25 -> V_31 , 0 , F_75 ( V_27 ) ) ;
V_188 = ( V_145 * ) V_122 ;
V_189 = V_25 -> V_31 ;
memcpy ( V_25 -> V_31 , V_122 , F_95 ( V_188 ) ) ;
V_190 = * V_187 ;
V_187 -> V_17 = F_75 ( V_27 ) ;
V_187 -> V_16 = 0 ;
V_187 -> V_15 = 0 ;
V_187 -> V_18 = 0 ;
V_187 -> V_20 [ 0 ] . V_21 = F_95 ( V_188 ) ;
V_187 -> V_20 [ 0 ] . V_22 = V_187 -> V_17 -
V_187 -> V_20 [ 0 ] . V_21 ;
F_5 ( V_189 , V_187 ) ;
F_105 ( V_188 , & V_190 , 0 , V_189 , V_187 , 0 ,
V_190 . V_15 , V_27 ) ;
F_79 ( V_99 , V_25 , 0 , F_75 ( V_27 ) - 1 ) ;
F_69 ( V_122 ) ;
}
static int
F_106 (
struct V_24 * V_191 ,
struct V_1 * V_192 ,
struct V_24 * V_193 ,
struct V_1 * V_194 )
{
struct V_133 * V_195 ;
struct V_133 * V_196 ;
V_195 = F_71 ( V_191 -> V_31 ) ;
V_196 = F_71 ( V_193 -> V_31 ) ;
if ( V_192 -> V_15 > 0 && V_194 -> V_15 > 0 &&
( ( F_3 ( V_196 [ 0 ] . V_131 ) <
F_3 ( V_195 [ 0 ] . V_131 ) ) ||
( F_3 ( V_196 [ V_194 -> V_15 - 1 ] . V_131 ) <
F_3 ( V_195 [ V_192 -> V_15 - 1 ] . V_131 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_107 (
struct V_24 * V_191 ,
struct V_24 * V_193 )
{
struct V_1 V_197 ;
struct V_1 V_198 ;
F_1 ( & V_197 , V_191 -> V_31 ) ;
F_1 ( & V_198 , V_193 -> V_31 ) ;
return F_106 ( V_191 , & V_197 , V_193 , & V_198 ) ;
}
STATIC void
F_88 (
struct V_163 * V_164 ,
struct V_165 * V_199 ,
struct V_165 * V_200 )
{
struct V_142 * args ;
struct V_3 * V_201 ;
struct V_3 * V_202 ;
struct V_1 V_197 ;
struct V_1 V_198 ;
struct V_133 * V_195 ;
struct V_133 * V_196 ;
int V_15 ;
int V_203 ;
int V_204 ;
int V_205 ;
int V_206 ;
ASSERT ( V_199 -> V_8 == V_9 ) ;
ASSERT ( V_200 -> V_8 == V_9 ) ;
V_201 = V_199 -> V_25 -> V_31 ;
V_202 = V_200 -> V_25 -> V_31 ;
F_1 ( & V_197 , V_201 ) ;
F_1 ( & V_198 , V_202 ) ;
ASSERT ( V_198 . V_15 == 0 ) ;
args = V_164 -> args ;
F_108 ( args ) ;
V_206 = 0 ;
if ( F_106 ( V_199 -> V_25 , & V_197 , V_200 -> V_25 , & V_198 ) ) {
struct V_165 * V_207 ;
struct V_1 V_208 ;
V_207 = V_199 ;
V_199 = V_200 ;
V_200 = V_207 ;
V_208 = V_197 ;
V_197 = V_198 ;
V_198 = V_208 ;
V_201 = V_199 -> V_25 -> V_31 ;
V_202 = V_200 -> V_25 -> V_31 ;
V_206 = 1 ;
}
V_164 -> V_168 = F_109 ( V_164 , V_199 , & V_197 ,
V_200 , & V_198 ,
& V_15 , & V_203 ) ;
if ( V_206 )
V_164 -> V_168 = ! V_164 -> V_168 ;
if ( V_15 < V_197 . V_15 ) {
V_15 = V_197 . V_15 - V_15 ;
V_205 = V_197 . V_16 - V_203 ;
V_205 += V_15 * sizeof( V_176 ) ;
V_204 = V_198 . V_17 - F_95 ( V_201 ) ;
V_204 -= V_198 . V_15 * sizeof( V_176 ) ;
if ( V_205 > V_204 )
F_97 ( args , & V_198 , V_200 -> V_25 ) ;
F_105 ( V_201 , & V_197 , V_197 . V_15 - V_15 ,
V_202 , & V_198 , 0 , V_15 , V_164 -> V_27 ) ;
} else if ( V_15 > V_197 . V_15 ) {
ASSERT ( 0 ) ;
V_15 -= V_197 . V_15 ;
V_205 = V_203 - V_197 . V_16 ;
V_205 += V_15 * sizeof( V_176 ) ;
V_204 = V_197 . V_17 - F_95 ( V_201 ) ;
V_204 -= V_197 . V_15 * sizeof( V_176 ) ;
if ( V_205 > V_204 )
F_97 ( args , & V_197 , V_199 -> V_25 ) ;
F_105 ( V_202 , & V_198 , 0 , V_201 , & V_197 ,
V_197 . V_15 , V_15 , V_164 -> V_27 ) ;
}
F_5 ( V_201 , & V_197 ) ;
F_5 ( V_202 , & V_198 ) ;
F_79 ( args -> V_99 , V_199 -> V_25 , 0 , V_164 -> V_209 - 1 ) ;
F_79 ( args -> V_99 , V_200 -> V_25 , 0 , V_164 -> V_209 - 1 ) ;
V_195 = F_71 ( V_201 ) ;
V_196 = F_71 ( V_202 ) ;
V_199 -> V_131 = F_3 ( V_195 [ V_197 . V_15 - 1 ] . V_131 ) ;
V_200 -> V_131 = F_3 ( V_196 [ V_198 . V_15 - 1 ] . V_131 ) ;
if ( V_199 -> V_173 > V_197 . V_15 ) {
ASSERT ( V_164 -> V_168 == 0 ) ;
V_200 -> V_173 = V_199 -> V_173 - V_197 . V_15 ;
args -> V_173 = args -> V_183 = V_200 -> V_173 ;
args -> V_37 = args -> V_182 = V_200 -> V_37 ;
} else if ( V_199 -> V_173 == V_197 . V_15 ) {
if ( V_164 -> V_168 ) {
args -> V_173 = V_199 -> V_173 ;
args -> V_37 = V_199 -> V_37 ;
args -> V_183 = 0 ;
args -> V_182 = V_200 -> V_37 ;
} else {
V_200 -> V_173 = V_199 -> V_173 - V_197 . V_15 ;
args -> V_173 = V_200 -> V_173 ;
args -> V_37 = V_200 -> V_37 ;
if ( ! V_164 -> V_210 ) {
args -> V_183 = V_200 -> V_173 ;
args -> V_182 = V_200 -> V_37 ;
}
}
} else {
ASSERT ( V_164 -> V_168 == 1 ) ;
args -> V_173 = args -> V_183 = V_199 -> V_173 ;
args -> V_37 = args -> V_182 = V_199 -> V_37 ;
}
}
STATIC int
F_109 (
struct V_163 * V_164 ,
struct V_165 * V_199 ,
struct V_1 * V_197 ,
struct V_165 * V_200 ,
struct V_1 * V_198 ,
int * V_211 ,
int * V_212 )
{
struct V_3 * V_201 = V_199 -> V_25 -> V_31 ;
struct V_3 * V_202 = V_200 -> V_25 -> V_31 ;
struct V_133 * V_134 ;
int V_15 ;
int V_204 ;
int V_173 ;
int V_203 = 0 ;
int V_213 ;
int V_214 ;
int V_215 = 0 ;
int V_172 ;
V_204 = V_197 -> V_15 + V_198 -> V_15 ;
V_213 = ( V_204 + 1 ) * sizeof( * V_134 ) ;
V_213 += V_197 -> V_16 + V_198 -> V_16 +
F_94 ( V_164 -> args -> V_106 ,
V_164 -> args -> V_110 ,
V_164 -> V_209 , NULL ) ;
V_213 /= 2 ;
V_214 = V_164 -> V_209 ;
V_134 = F_71 ( V_201 ) ;
for ( V_15 = V_173 = 0 ; V_15 < V_204 ; V_134 ++ , V_173 ++ , V_15 ++ ) {
#define F_110 ( T_12 ) (((A) < 0) ? -(A) : (A))
if ( V_15 == V_199 -> V_173 ) {
V_172 = V_203 + sizeof( * V_134 ) +
F_94 (
V_164 -> args -> V_106 ,
V_164 -> args -> V_110 ,
V_164 -> V_209 , NULL ) ;
if ( F_110 ( V_213 - V_172 ) > V_214 )
break;
V_214 = F_110 ( V_213 - V_172 ) ;
V_203 = V_172 ;
V_215 = 1 ;
}
if ( V_15 == V_197 -> V_15 ) {
V_201 = V_202 ;
V_134 = F_71 ( V_201 ) ;
V_173 = 0 ;
}
V_172 = V_203 + sizeof( * V_134 ) + F_103 ( V_201 ,
V_173 ) ;
if ( F_110 ( V_213 - V_172 ) > V_214 )
break;
V_214 = F_110 ( V_213 - V_172 ) ;
V_203 = V_172 ;
#undef F_110
}
V_203 -= V_15 * sizeof( * V_134 ) ;
if ( V_215 ) {
V_203 -= sizeof( * V_134 ) +
F_94 (
V_164 -> args -> V_106 ,
V_164 -> args -> V_110 ,
V_164 -> V_209 , NULL ) ;
}
* V_211 = V_15 ;
* V_212 = V_203 ;
return V_215 ;
}
int
F_111 (
struct V_163 * V_164 ,
int * V_216 )
{
struct V_3 * V_30 ;
struct V_165 * V_217 ;
struct V_1 V_32 ;
struct V_24 * V_25 ;
T_1 V_37 ;
int V_63 ;
int V_218 ;
int error ;
int V_219 ;
int V_5 ;
F_112 ( V_164 -> args ) ;
V_217 = & V_164 -> V_220 . V_217 [ V_164 -> V_220 . V_221 - 1 ] ;
V_30 = V_217 -> V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_63 = F_95 ( V_30 ) +
V_32 . V_15 * sizeof( V_176 ) +
V_32 . V_16 ;
if ( V_63 > ( V_164 -> V_209 >> 1 ) ) {
* V_216 = 0 ;
return ( 0 ) ;
}
if ( V_32 . V_15 == 0 ) {
V_218 = ( V_32 . V_13 != 0 ) ;
memcpy ( & V_164 -> V_222 , & V_164 -> V_220 , sizeof( V_164 -> V_220 ) ) ;
error = F_113 ( V_164 , & V_164 -> V_222 , V_218 ,
0 , & V_219 ) ;
if ( error )
return ( error ) ;
if ( V_219 ) {
* V_216 = 0 ;
} else {
* V_216 = 2 ;
}
return 0 ;
}
V_218 = V_32 . V_13 < V_32 . V_14 ;
for ( V_5 = 0 ; V_5 < 2 ; V_218 = ! V_218 , V_5 ++ ) {
struct V_1 V_198 ;
if ( V_218 )
V_37 = V_32 . V_13 ;
else
V_37 = V_32 . V_14 ;
if ( V_37 == 0 )
continue;
error = F_19 ( V_164 -> args -> V_99 , V_164 -> args -> V_53 ,
V_37 , - 1 , & V_25 ) ;
if ( error )
return ( error ) ;
F_1 ( & V_198 , V_25 -> V_31 ) ;
V_63 = V_164 -> V_209 - ( V_164 -> V_209 >> 2 ) -
V_32 . V_16 - V_198 . V_16 -
( ( V_32 . V_15 + V_198 . V_15 ) *
sizeof( V_176 ) ) -
F_95 ( V_30 ) ;
F_114 ( V_164 -> args -> V_99 , V_25 ) ;
if ( V_63 >= 0 )
break;
}
if ( V_5 >= 2 ) {
* V_216 = 0 ;
return ( 0 ) ;
}
memcpy ( & V_164 -> V_222 , & V_164 -> V_220 , sizeof( V_164 -> V_220 ) ) ;
if ( V_37 < V_217 -> V_37 ) {
error = F_113 ( V_164 , & V_164 -> V_222 , V_218 ,
0 , & V_219 ) ;
} else {
error = F_113 ( V_164 , & V_164 -> V_220 , V_218 ,
0 , & V_219 ) ;
}
if ( error )
return ( error ) ;
if ( V_219 ) {
* V_216 = 0 ;
} else {
* V_216 = 1 ;
}
return ( 0 ) ;
}
int
F_115 (
struct V_24 * V_25 ,
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_133 * V_134 ;
struct V_26 * V_27 = args -> V_99 -> V_174 ;
int V_159 ;
int V_223 ;
int V_224 ;
int V_170 ;
int V_169 ;
int V_172 ;
int V_5 ;
F_116 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( V_32 . V_15 > 0 && V_32 . V_15 < F_75 ( V_27 ) / 8 ) ;
ASSERT ( args -> V_173 >= 0 && args -> V_173 < V_32 . V_15 ) ;
ASSERT ( V_32 . V_17 >= V_32 . V_15 * sizeof( * V_134 ) +
F_95 ( V_30 ) ) ;
V_134 = & F_71 ( V_30 ) [ args -> V_173 ] ;
ASSERT ( F_4 ( V_134 -> V_146 ) >= V_32 . V_17 ) ;
ASSERT ( F_4 ( V_134 -> V_146 ) < F_75 ( V_27 ) ) ;
V_169 = V_32 . V_15 * sizeof( V_176 )
+ F_95 ( V_30 ) ;
V_172 = V_32 . V_20 [ 0 ] . V_22 ;
V_159 = V_223 = - 1 ;
V_224 = V_19 - 1 ;
V_170 = F_103 ( V_30 , args -> V_173 ) ;
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
ASSERT ( V_32 . V_20 [ V_5 ] . V_21 < F_75 ( V_27 ) ) ;
ASSERT ( V_32 . V_20 [ V_5 ] . V_22 < F_75 ( V_27 ) ) ;
if ( V_32 . V_20 [ V_5 ] . V_21 == V_169 ) {
V_32 . V_20 [ V_5 ] . V_21 -= sizeof( V_176 ) ;
V_32 . V_20 [ V_5 ] . V_22 += sizeof( V_176 ) ;
}
if ( V_32 . V_20 [ V_5 ] . V_21 + V_32 . V_20 [ V_5 ] . V_22 ==
F_4 ( V_134 -> V_146 ) ) {
V_159 = V_5 ;
} else if ( V_32 . V_20 [ V_5 ] . V_21 ==
( F_4 ( V_134 -> V_146 ) + V_170 ) ) {
V_223 = V_5 ;
} else if ( V_32 . V_20 [ V_5 ] . V_22 < V_172 ) {
V_172 = V_32 . V_20 [ V_5 ] . V_22 ;
V_224 = V_5 ;
}
}
if ( ( V_159 >= 0 ) || ( V_223 >= 0 ) ) {
if ( ( V_159 >= 0 ) && ( V_223 >= 0 ) ) {
V_32 . V_20 [ V_159 ] . V_22 += V_170 ;
V_32 . V_20 [ V_159 ] . V_22 += V_32 . V_20 [ V_223 ] . V_22 ;
V_32 . V_20 [ V_223 ] . V_21 = 0 ;
V_32 . V_20 [ V_223 ] . V_22 = 0 ;
} else if ( V_159 >= 0 ) {
V_32 . V_20 [ V_159 ] . V_22 += V_170 ;
} else {
V_32 . V_20 [ V_223 ] . V_21 = F_4 ( V_134 -> V_146 ) ;
V_32 . V_20 [ V_223 ] . V_22 += V_170 ;
}
} else {
if ( V_32 . V_20 [ V_224 ] . V_22 < V_170 ) {
V_32 . V_20 [ V_224 ] . V_21 = F_4 ( V_134 -> V_146 ) ;
V_32 . V_20 [ V_224 ] . V_22 = V_170 ;
}
}
if ( F_4 ( V_134 -> V_146 ) == V_32 . V_17 )
V_224 = 1 ;
else
V_224 = 0 ;
memset ( F_102 ( V_30 , args -> V_173 ) , 0 , V_170 ) ;
V_32 . V_16 -= V_170 ;
F_79 ( args -> V_99 , V_25 ,
F_98 ( V_30 , F_102 ( V_30 , args -> V_173 ) ,
V_170 ) ) ;
V_172 = ( V_32 . V_15 - args -> V_173 ) * sizeof( V_176 ) ;
memmove ( V_134 , V_134 + 1 , V_172 ) ;
V_32 . V_15 -- ;
F_79 ( args -> V_99 , V_25 ,
F_98 ( V_30 , V_134 , V_172 + sizeof( V_176 ) ) ) ;
V_134 = & F_71 ( V_30 ) [ V_32 . V_15 ] ;
memset ( V_134 , 0 , sizeof( V_176 ) ) ;
if ( V_224 ) {
V_172 = F_75 ( V_27 ) ;
V_134 = F_71 ( V_30 ) ;
for ( V_5 = V_32 . V_15 - 1 ; V_5 >= 0 ; V_134 ++ , V_5 -- ) {
ASSERT ( F_4 ( V_134 -> V_146 ) >= V_32 . V_17 ) ;
ASSERT ( F_4 ( V_134 -> V_146 ) < F_75 ( V_27 ) ) ;
if ( F_4 ( V_134 -> V_146 ) < V_172 )
V_172 = F_4 ( V_134 -> V_146 ) ;
}
V_32 . V_17 = V_172 ;
if ( ! V_32 . V_17 )
V_32 . V_17 = V_172 - V_225 ;
} else {
V_32 . V_18 = 1 ;
}
F_5 ( V_30 , & V_32 ) ;
F_79 ( args -> V_99 , V_25 ,
F_98 ( V_30 , & V_30 -> V_6 ,
F_95 ( V_30 ) ) ) ;
V_172 = V_32 . V_16 + F_95 ( V_30 ) +
V_32 . V_15 * sizeof( V_176 ) ;
return V_172 < V_27 -> V_226 ;
}
void
F_117 (
struct V_163 * V_164 ,
struct V_165 * V_227 ,
struct V_165 * V_228 )
{
struct V_3 * V_229 = V_227 -> V_25 -> V_31 ;
struct V_3 * V_230 = V_228 -> V_25 -> V_31 ;
struct V_1 V_231 ;
struct V_1 V_232 ;
struct V_133 * V_134 ;
struct V_26 * V_27 = V_164 -> V_27 ;
F_118 ( V_164 -> args ) ;
V_229 = V_227 -> V_25 -> V_31 ;
V_230 = V_228 -> V_25 -> V_31 ;
F_1 ( & V_231 , V_229 ) ;
F_1 ( & V_232 , V_230 ) ;
V_134 = F_71 ( V_229 ) ;
V_227 -> V_131 = F_3 ( V_134 [ V_231 . V_15 - 1 ] . V_131 ) ;
if ( V_232 . V_18 == 0 ) {
if ( F_106 ( V_228 -> V_25 , & V_232 ,
V_227 -> V_25 , & V_231 ) ) {
F_105 ( V_229 , & V_231 , 0 ,
V_230 , & V_232 , 0 ,
V_231 . V_15 , V_27 ) ;
} else {
F_105 ( V_229 , & V_231 , 0 ,
V_230 , & V_232 ,
V_232 . V_15 , V_231 . V_15 , V_27 ) ;
}
} else {
struct V_3 * V_233 ;
struct V_1 V_234 ;
V_233 = F_119 ( V_164 -> V_209 , V_123 ) ;
memcpy ( V_233 , V_230 , F_95 ( V_230 ) ) ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_8 = V_232 . V_8 ;
V_234 . V_13 = V_232 . V_13 ;
V_234 . V_14 = V_232 . V_14 ;
V_234 . V_17 = V_164 -> V_209 ;
F_5 ( V_233 , & V_234 ) ;
if ( F_106 ( V_228 -> V_25 , & V_232 ,
V_227 -> V_25 , & V_231 ) ) {
F_105 ( V_229 , & V_231 , 0 ,
V_233 , & V_234 , 0 ,
V_231 . V_15 , V_27 ) ;
F_105 ( V_230 , & V_232 , 0 ,
V_233 , & V_234 , V_234 . V_15 ,
V_232 . V_15 , V_27 ) ;
} else {
F_105 ( V_230 , & V_232 , 0 ,
V_233 , & V_234 , 0 ,
V_232 . V_15 , V_27 ) ;
F_105 ( V_229 , & V_231 , 0 ,
V_233 , & V_234 , V_234 . V_15 ,
V_231 . V_15 , V_27 ) ;
}
memcpy ( V_230 , V_233 , V_164 -> V_209 ) ;
V_232 = V_234 ;
F_69 ( V_233 ) ;
}
F_5 ( V_230 , & V_232 ) ;
F_79 ( V_164 -> args -> V_99 , V_228 -> V_25 , 0 ,
V_164 -> V_209 - 1 ) ;
V_134 = F_71 ( V_230 ) ;
V_228 -> V_131 = F_3 ( V_134 [ V_232 . V_15 - 1 ] . V_131 ) ;
}
int
F_67 (
struct V_24 * V_25 ,
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_133 * V_134 ;
struct V_133 * V_148 ;
struct V_143 * V_135 ;
struct V_179 * V_180 ;
T_13 V_131 ;
int V_235 ;
int V_236 ;
F_120 ( args ) ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
V_148 = F_71 ( V_30 ) ;
ASSERT ( V_32 . V_15 < F_75 ( args -> V_53 -> V_68 ) / 8 ) ;
V_131 = args -> V_131 ;
V_235 = V_236 = V_32 . V_15 / 2 ;
for ( V_134 = & V_148 [ V_235 ] ; V_236 > 4 ; V_134 = & V_148 [ V_235 ] ) {
V_236 /= 2 ;
if ( F_3 ( V_134 -> V_131 ) < V_131 )
V_235 += V_236 ;
else if ( F_3 ( V_134 -> V_131 ) > V_131 )
V_235 -= V_236 ;
else
break;
}
ASSERT ( V_235 >= 0 && ( ! V_32 . V_15 || V_235 < V_32 . V_15 ) ) ;
ASSERT ( V_236 <= 4 || F_3 ( V_134 -> V_131 ) == V_131 ) ;
while ( V_235 > 0 && F_3 ( V_134 -> V_131 ) >= V_131 ) {
V_134 -- ;
V_235 -- ;
}
while ( V_235 < V_32 . V_15 &&
F_3 ( V_134 -> V_131 ) < V_131 ) {
V_134 ++ ;
V_235 ++ ;
}
if ( V_235 == V_32 . V_15 || F_3 ( V_134 -> V_131 ) != V_131 ) {
args -> V_173 = V_235 ;
return F_54 ( V_115 ) ;
}
for (; V_235 < V_32 . V_15 && ( F_3 ( V_134 -> V_131 ) == V_131 ) ;
V_134 ++ , V_235 ++ ) {
if ( ( args -> V_109 & V_138 ) !=
( V_134 -> V_109 & V_138 ) ) {
continue;
}
if ( V_134 -> V_109 & V_139 ) {
V_135 = F_72 ( V_30 , V_235 ) ;
if ( V_135 -> V_106 != args -> V_106 )
continue;
if ( memcmp ( args -> V_107 , V_135 -> V_108 ,
args -> V_106 ) != 0 )
continue;
if ( ! F_22 ( args -> V_109 , V_134 -> V_109 ) )
continue;
args -> V_173 = V_235 ;
return F_54 ( V_118 ) ;
} else {
V_180 = F_100 ( V_30 , V_235 ) ;
if ( V_180 -> V_106 != args -> V_106 )
continue;
if ( memcmp ( args -> V_107 , V_180 -> V_107 ,
args -> V_106 ) != 0 )
continue;
if ( ! F_22 ( args -> V_109 , V_134 -> V_109 ) )
continue;
args -> V_173 = V_235 ;
args -> V_110 = F_3 ( V_180 -> V_110 ) ;
args -> V_185 = F_3 ( V_180 -> V_184 ) ;
args -> V_186 = F_101 (
args -> V_53 -> V_68 ,
args -> V_110 ) ;
return F_54 ( V_118 ) ;
}
}
args -> V_173 = V_235 ;
return F_54 ( V_115 ) ;
}
int
F_121 (
struct V_24 * V_25 ,
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_1 V_32 ;
struct V_133 * V_134 ;
struct V_143 * V_135 ;
struct V_179 * V_180 ;
int V_110 ;
V_30 = V_25 -> V_31 ;
F_1 ( & V_32 , V_30 ) ;
ASSERT ( V_32 . V_15 < F_75 ( args -> V_53 -> V_68 ) / 8 ) ;
ASSERT ( args -> V_173 < V_32 . V_15 ) ;
V_134 = & F_71 ( V_30 ) [ args -> V_173 ] ;
if ( V_134 -> V_109 & V_139 ) {
V_135 = F_72 ( V_30 , args -> V_173 ) ;
ASSERT ( V_135 -> V_106 == args -> V_106 ) ;
ASSERT ( memcmp ( args -> V_107 , V_135 -> V_108 , args -> V_106 ) == 0 ) ;
V_110 = F_4 ( V_135 -> V_110 ) ;
if ( args -> V_109 & V_119 ) {
args -> V_110 = V_110 ;
return 0 ;
}
if ( args -> V_110 < V_110 ) {
args -> V_110 = V_110 ;
return F_54 ( V_120 ) ;
}
args -> V_110 = V_110 ;
memcpy ( args -> V_111 , & V_135 -> V_108 [ args -> V_106 ] , V_110 ) ;
} else {
V_180 = F_100 ( V_30 , args -> V_173 ) ;
ASSERT ( V_180 -> V_106 == args -> V_106 ) ;
ASSERT ( memcmp ( args -> V_107 , V_180 -> V_107 , args -> V_106 ) == 0 ) ;
V_110 = F_3 ( V_180 -> V_110 ) ;
args -> V_185 = F_3 ( V_180 -> V_184 ) ;
args -> V_186 = F_101 ( args -> V_53 -> V_68 ,
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
F_105 (
struct V_3 * V_237 ,
struct V_1 * V_238 ,
int V_239 ,
struct V_3 * V_240 ,
struct V_1 * V_241 ,
int V_242 ,
int V_15 ,
struct V_26 * V_27 )
{
struct V_133 * V_243 ;
struct V_133 * V_244 ;
int V_245 ;
int V_172 ;
int V_5 ;
if ( V_15 == 0 )
return;
ASSERT ( V_238 -> V_8 == V_9 ||
V_238 -> V_8 == V_10 ) ;
ASSERT ( V_238 -> V_8 == V_241 -> V_8 ) ;
ASSERT ( V_238 -> V_15 > 0 && V_238 -> V_15 < F_75 ( V_27 ) / 8 ) ;
ASSERT ( V_238 -> V_17 >= ( V_238 -> V_15 * sizeof( * V_243 ) )
+ F_95 ( V_237 ) ) ;
ASSERT ( V_241 -> V_15 < F_75 ( V_27 ) / 8 ) ;
ASSERT ( V_241 -> V_17 >= ( V_241 -> V_15 * sizeof( * V_244 ) )
+ F_95 ( V_240 ) ) ;
ASSERT ( V_239 < V_238 -> V_15 ) ;
ASSERT ( V_242 <= V_241 -> V_15 ) ;
ASSERT ( V_15 <= V_238 -> V_15 ) ;
if ( V_242 < V_241 -> V_15 ) {
V_172 = V_241 -> V_15 - V_242 ;
V_172 *= sizeof( V_176 ) ;
V_243 = & F_71 ( V_240 ) [ V_242 ] ;
V_244 = & F_71 ( V_240 ) [ V_242 + V_15 ] ;
memmove ( V_244 , V_243 , V_172 ) ;
}
V_243 = & F_71 ( V_237 ) [ V_239 ] ;
V_244 = & F_71 ( V_240 ) [ V_242 ] ;
V_245 = V_242 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_243 ++ , V_244 ++ , V_245 ++ , V_5 ++ ) {
ASSERT ( F_4 ( V_243 -> V_146 ) >= V_238 -> V_17 ) ;
V_172 = F_103 ( V_237 , V_239 + V_5 ) ;
#ifdef F_122
if ( V_243 -> V_109 & V_138 ) {
memset ( F_102 ( V_237 , V_239 + V_5 ) , 0 , V_172 ) ;
V_238 -> V_16 -= V_172 ;
V_238 -> V_15 -= 1 ;
V_244 -- ;
V_245 -- ;
if ( ( V_239 + V_5 ) < V_64 )
V_246 ++ ;
} else {
#endif
V_241 -> V_17 -= V_172 ;
V_244 -> V_131 = V_243 -> V_131 ;
V_244 -> V_146 = F_2 ( V_241 -> V_17 ) ;
V_244 -> V_109 = V_243 -> V_109 ;
ASSERT ( F_4 ( V_244 -> V_146 ) + V_172
<= F_75 ( V_27 ) ) ;
memmove ( F_102 ( V_240 , V_245 ) ,
F_102 ( V_237 , V_239 + V_5 ) , V_172 ) ;
ASSERT ( F_4 ( V_243 -> V_146 ) + V_172
<= F_75 ( V_27 ) ) ;
memset ( F_102 ( V_237 , V_239 + V_5 ) , 0 , V_172 ) ;
V_238 -> V_16 -= V_172 ;
V_241 -> V_16 += V_172 ;
V_238 -> V_15 -= 1 ;
V_241 -> V_15 += 1 ;
V_172 = V_241 -> V_15 * sizeof( V_176 )
+ F_95 ( V_240 ) ;
ASSERT ( V_241 -> V_17 >= V_172 ) ;
#ifdef F_122
}
#endif
}
if ( V_239 == V_238 -> V_15 ) {
V_172 = V_15 * sizeof( V_176 ) ;
V_243 = & F_71 ( V_237 ) [ V_239 ] ;
ASSERT ( ( ( char * ) V_243 + V_172 ) <=
( ( char * ) V_237 + F_75 ( V_27 ) ) ) ;
memset ( V_243 , 0 , V_172 ) ;
} else {
V_172 = ( V_238 -> V_15 - V_15 ) * sizeof( V_176 ) ;
V_243 = & F_71 ( V_237 ) [ V_239 + V_15 ] ;
V_244 = & F_71 ( V_237 ) [ V_239 ] ;
memmove ( V_244 , V_243 , V_172 ) ;
V_172 = V_15 * sizeof( V_176 ) ;
V_243 = & F_71 ( V_237 ) [ V_238 -> V_15 ] ;
ASSERT ( ( ( char * ) V_243 + V_172 ) <=
( ( char * ) V_237 + F_75 ( V_27 ) ) ) ;
memset ( V_243 , 0 , V_172 ) ;
}
V_241 -> V_20 [ 0 ] . V_21 = F_95 ( V_240 ) ;
V_241 -> V_20 [ 0 ] . V_21 += V_241 -> V_15 * sizeof( V_176 ) ;
V_241 -> V_20 [ 0 ] . V_22 = V_241 -> V_17 - V_241 -> V_20 [ 0 ] . V_21 ;
V_241 -> V_20 [ 1 ] . V_21 = 0 ;
V_241 -> V_20 [ 2 ] . V_21 = 0 ;
V_241 -> V_20 [ 1 ] . V_22 = 0 ;
V_241 -> V_20 [ 2 ] . V_22 = 0 ;
V_238 -> V_18 = 1 ;
}
T_13
F_92 (
struct V_24 * V_25 ,
int * V_15 )
{
struct V_1 V_32 ;
struct V_133 * V_148 ;
F_1 ( & V_32 , V_25 -> V_31 ) ;
V_148 = F_71 ( V_25 -> V_31 ) ;
if ( V_15 )
* V_15 = V_32 . V_15 ;
if ( ! V_32 . V_15 )
return 0 ;
return F_3 ( V_148 [ V_32 . V_15 - 1 ] . V_131 ) ;
}
STATIC int
F_103 ( V_145 * V_30 , int V_173 )
{
struct V_133 * V_148 ;
T_11 * V_135 ;
T_14 * V_180 ;
int V_22 ;
V_148 = F_71 ( V_30 ) ;
if ( V_148 [ V_173 ] . V_109 & V_139 ) {
V_135 = F_72 ( V_30 , V_173 ) ;
V_22 = F_123 ( V_135 -> V_106 ,
F_4 ( V_135 -> V_110 ) ) ;
} else {
V_180 = F_100 ( V_30 , V_173 ) ;
V_22 = F_124 ( V_180 -> V_106 ) ;
}
return V_22 ;
}
int
F_94 ( int V_106 , int V_110 , int V_209 , int * V_247 )
{
int V_22 ;
V_22 = F_123 ( V_106 , V_110 ) ;
if ( V_22 < F_125 ( V_209 ) ) {
if ( V_247 ) {
* V_247 = 1 ;
}
} else {
V_22 = F_124 ( V_106 ) ;
if ( V_247 ) {
* V_247 = 0 ;
}
}
return V_22 ;
}
int
F_126 (
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_133 * V_134 ;
struct V_179 * V_180 ;
struct V_24 * V_25 ;
int error ;
#ifdef F_46
struct V_1 V_32 ;
T_11 * V_135 ;
int V_106 ;
char * V_107 ;
#endif
F_127 ( args ) ;
error = F_19 ( args -> V_99 , args -> V_53 , args -> V_37 , - 1 , & V_25 ) ;
if ( error )
return ( error ) ;
V_30 = V_25 -> V_31 ;
V_134 = & F_71 ( V_30 ) [ args -> V_173 ] ;
ASSERT ( V_134 -> V_109 & V_138 ) ;
#ifdef F_46
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_173 < V_32 . V_15 ) ;
ASSERT ( args -> V_173 >= 0 ) ;
if ( V_134 -> V_109 & V_139 ) {
V_135 = F_72 ( V_30 , args -> V_173 ) ;
V_106 = V_135 -> V_106 ;
V_107 = ( char * ) V_135 -> V_108 ;
} else {
V_180 = F_100 ( V_30 , args -> V_173 ) ;
V_106 = V_180 -> V_106 ;
V_107 = ( char * ) V_180 -> V_107 ;
}
ASSERT ( F_3 ( V_134 -> V_131 ) == args -> V_131 ) ;
ASSERT ( V_106 == args -> V_106 ) ;
ASSERT ( memcmp ( V_107 , args -> V_107 , V_106 ) == 0 ) ;
#endif
V_134 -> V_109 &= ~ V_138 ;
F_79 ( args -> V_99 , V_25 ,
F_98 ( V_30 , V_134 , sizeof( * V_134 ) ) ) ;
if ( args -> V_185 ) {
ASSERT ( ( V_134 -> V_109 & V_139 ) == 0 ) ;
V_180 = F_100 ( V_30 , args -> V_173 ) ;
V_180 -> V_184 = F_6 ( args -> V_185 ) ;
V_180 -> V_110 = F_6 ( args -> V_110 ) ;
F_79 ( args -> V_99 , V_25 ,
F_98 ( V_30 , V_180 , sizeof( * V_180 ) ) ) ;
}
return F_128 ( & args -> V_99 , args -> V_53 ) ;
}
int
F_129 (
struct V_142 * args )
{
struct V_3 * V_30 ;
struct V_133 * V_134 ;
struct V_179 * V_180 ;
struct V_24 * V_25 ;
int error ;
#ifdef F_46
struct V_1 V_32 ;
#endif
F_130 ( args ) ;
error = F_19 ( args -> V_99 , args -> V_53 , args -> V_37 , - 1 , & V_25 ) ;
if ( error )
return ( error ) ;
V_30 = V_25 -> V_31 ;
#ifdef F_46
F_1 ( & V_32 , V_30 ) ;
ASSERT ( args -> V_173 < V_32 . V_15 ) ;
ASSERT ( args -> V_173 >= 0 ) ;
#endif
V_134 = & F_71 ( V_30 ) [ args -> V_173 ] ;
ASSERT ( ( V_134 -> V_109 & V_138 ) == 0 ) ;
V_134 -> V_109 |= V_138 ;
F_79 ( args -> V_99 , V_25 ,
F_98 ( V_30 , V_134 , sizeof( * V_134 ) ) ) ;
if ( ( V_134 -> V_109 & V_139 ) == 0 ) {
V_180 = F_100 ( V_30 , args -> V_173 ) ;
V_180 -> V_184 = 0 ;
V_180 -> V_110 = 0 ;
F_79 ( args -> V_99 , V_25 ,
F_98 ( V_30 , V_180 , sizeof( * V_180 ) ) ) ;
}
return F_128 ( & args -> V_99 , args -> V_53 ) ;
}
int
F_131 (
struct V_142 * args )
{
struct V_3 * V_201 ;
struct V_3 * V_202 ;
struct V_133 * V_248 ;
struct V_133 * V_249 ;
struct V_179 * V_180 ;
struct V_24 * V_155 ;
struct V_24 * V_156 ;
int error ;
#ifdef F_46
struct V_1 V_197 ;
struct V_1 V_198 ;
T_11 * V_135 ;
int V_250 , V_251 ;
char * V_252 , * V_253 ;
#endif
F_132 ( args ) ;
error = F_19 ( args -> V_99 , args -> V_53 , args -> V_37 , - 1 , & V_155 ) ;
if ( error )
return error ;
if ( args -> V_182 != args -> V_37 ) {
error = F_19 ( args -> V_99 , args -> V_53 , args -> V_182 ,
- 1 , & V_156 ) ;
if ( error )
return error ;
} else {
V_156 = V_155 ;
}
V_201 = V_155 -> V_31 ;
V_248 = & F_71 ( V_201 ) [ args -> V_173 ] ;
V_202 = V_156 -> V_31 ;
V_249 = & F_71 ( V_202 ) [ args -> V_183 ] ;
#ifdef F_46
F_1 ( & V_197 , V_201 ) ;
ASSERT ( args -> V_173 < V_197 . V_15 ) ;
ASSERT ( args -> V_173 >= 0 ) ;
F_1 ( & V_198 , V_202 ) ;
ASSERT ( args -> V_183 < V_198 . V_15 ) ;
ASSERT ( args -> V_183 >= 0 ) ;
if ( V_248 -> V_109 & V_139 ) {
V_135 = F_72 ( V_201 , args -> V_173 ) ;
V_250 = V_135 -> V_106 ;
V_252 = ( char * ) V_135 -> V_108 ;
} else {
V_180 = F_100 ( V_201 , args -> V_173 ) ;
V_250 = V_180 -> V_106 ;
V_252 = ( char * ) V_180 -> V_107 ;
}
if ( V_249 -> V_109 & V_139 ) {
V_135 = F_72 ( V_202 , args -> V_183 ) ;
V_251 = V_135 -> V_106 ;
V_253 = ( char * ) V_135 -> V_108 ;
} else {
V_180 = F_100 ( V_202 , args -> V_183 ) ;
V_251 = V_180 -> V_106 ;
V_253 = ( char * ) V_180 -> V_107 ;
}
ASSERT ( F_3 ( V_248 -> V_131 ) == F_3 ( V_249 -> V_131 ) ) ;
ASSERT ( V_250 == V_251 ) ;
ASSERT ( memcmp ( V_252 , V_253 , V_250 ) == 0 ) ;
#endif
ASSERT ( V_248 -> V_109 & V_138 ) ;
ASSERT ( ( V_249 -> V_109 & V_138 ) == 0 ) ;
V_248 -> V_109 &= ~ V_138 ;
F_79 ( args -> V_99 , V_155 ,
F_98 ( V_201 , V_248 , sizeof( * V_248 ) ) ) ;
if ( args -> V_185 ) {
ASSERT ( ( V_248 -> V_109 & V_139 ) == 0 ) ;
V_180 = F_100 ( V_201 , args -> V_173 ) ;
V_180 -> V_184 = F_6 ( args -> V_185 ) ;
V_180 -> V_110 = F_6 ( args -> V_110 ) ;
F_79 ( args -> V_99 , V_155 ,
F_98 ( V_201 , V_180 , sizeof( * V_180 ) ) ) ;
}
V_249 -> V_109 |= V_138 ;
F_79 ( args -> V_99 , V_156 ,
F_98 ( V_202 , V_249 , sizeof( * V_249 ) ) ) ;
if ( ( V_249 -> V_109 & V_139 ) == 0 ) {
V_180 = F_100 ( V_202 , args -> V_183 ) ;
V_180 -> V_184 = 0 ;
V_180 -> V_110 = 0 ;
F_79 ( args -> V_99 , V_156 ,
F_98 ( V_202 , V_180 , sizeof( * V_180 ) ) ) ;
}
error = F_128 ( & args -> V_99 , args -> V_53 ) ;
return error ;
}
