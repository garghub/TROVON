T_1 *
F_1 ( void )
{
return F_2 ( V_1 , V_2 ) ;
}
STATIC void
F_3 ( T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 . V_6 ; V_4 ++ )
V_3 -> V_5 . V_7 [ V_4 ] . V_8 = NULL ;
V_3 -> V_5 . V_6 = 0 ;
}
void
F_4 ( T_1 * V_3 )
{
F_3 ( V_3 ) ;
#ifdef F_5
memset ( ( char * ) V_3 , 0 , sizeof( * V_3 ) ) ;
#endif
F_6 ( V_1 , V_3 ) ;
}
static bool
F_7 (
struct V_9 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 -> V_13 ;
struct V_14 * V_15 = V_8 -> V_16 ;
struct V_17 V_18 ;
const struct V_19 * V_20 ;
V_20 = F_8 ( V_11 , NULL ) ;
V_20 -> V_21 ( & V_18 , V_15 ) ;
if ( F_9 ( & V_11 -> V_22 ) ) {
struct V_23 * V_24 = V_8 -> V_16 ;
if ( V_18 . V_25 != V_26 )
return false ;
if ( ! F_10 ( & V_24 -> V_27 . V_28 , & V_11 -> V_22 . V_29 ) )
return false ;
if ( F_11 ( V_24 -> V_27 . V_30 ) != V_8 -> V_31 )
return false ;
} else {
if ( V_18 . V_25 != V_32 )
return false ;
}
if ( V_18 . V_33 == 0 )
return false ;
if ( V_18 . V_33 > V_34 )
return false ;
if ( V_18 . V_35 == 0 )
return false ;
if ( V_18 . V_35 > V_11 -> V_36 &&
V_18 . V_35 > V_11 -> V_37 )
return false ;
return true ;
}
static void
F_12 (
struct V_9 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 -> V_13 ;
struct V_38 * V_39 = V_8 -> V_40 ;
struct V_23 * V_24 = V_8 -> V_16 ;
if ( ! F_7 ( V_8 ) ) {
F_13 ( V_8 , V_41 ) ;
F_14 ( V_8 ) ;
return;
}
if ( ! F_9 ( & V_11 -> V_22 ) )
return;
if ( V_39 )
V_24 -> V_27 . V_42 = F_15 ( V_39 -> V_43 . V_44 ) ;
F_16 ( V_8 , V_45 ) ;
}
static void
F_17 (
struct V_9 * V_8 )
{
struct V_46 * V_27 = V_8 -> V_16 ;
switch ( F_18 ( V_27 -> V_25 ) ) {
case V_26 :
if ( ! F_19 ( V_8 , V_45 ) ) {
F_13 ( V_8 , V_47 ) ;
break;
}
case V_32 :
if ( ! F_7 ( V_8 ) ) {
F_13 ( V_8 , V_41 ) ;
break;
}
return;
case V_48 :
case V_49 :
V_8 -> V_50 = & V_51 ;
V_8 -> V_50 -> V_52 ( V_8 ) ;
return;
case V_53 :
case V_54 :
V_8 -> V_50 = & V_55 ;
V_8 -> V_50 -> V_52 ( V_8 ) ;
return;
default:
break;
}
F_14 ( V_8 ) ;
}
int
F_20 (
struct V_56 * V_57 ,
struct V_58 * V_59 ,
T_2 V_60 ,
T_3 V_61 ,
struct V_9 * * V_62 ,
int V_63 )
{
int V_64 ;
V_64 = F_21 ( V_57 , V_59 , V_60 , V_61 , V_62 ,
V_63 , & V_65 ) ;
if ( ! V_64 && V_57 ) {
struct V_46 * V_27 = ( * V_62 ) -> V_16 ;
int type ;
switch ( F_18 ( V_27 -> V_25 ) ) {
case V_32 :
case V_26 :
type = V_66 ;
break;
case V_48 :
case V_49 :
type = V_67 ;
break;
case V_53 :
case V_54 :
type = V_68 ;
break;
default:
type = 0 ;
ASSERT ( 0 ) ;
break;
}
F_22 ( V_57 , * V_62 , type ) ;
}
return V_64 ;
}
int
F_23 (
struct V_69 * args ,
T_2 V_30 ,
int V_33 ,
struct V_9 * * V_62 ,
int V_70 )
{
struct V_14 * V_71 ;
struct V_56 * V_57 = args -> V_72 ;
struct V_10 * V_11 = V_57 -> V_73 ;
struct V_17 V_18 = { 0 } ;
struct V_9 * V_8 ;
int error ;
struct V_58 * V_59 = args -> V_59 ;
F_24 ( args ) ;
ASSERT ( V_33 <= V_34 ) ;
error = F_25 ( V_57 , V_59 , V_30 , - 1 , & V_8 , V_70 ) ;
if ( error )
return ( error ) ;
V_8 -> V_50 = & V_65 ;
F_22 ( V_57 , V_8 , V_66 ) ;
V_71 = V_8 -> V_16 ;
if ( F_9 ( & V_11 -> V_22 ) ) {
struct V_23 * V_24 = V_8 -> V_16 ;
V_18 . V_25 = V_26 ;
V_24 -> V_27 . V_30 = F_15 ( V_8 -> V_31 ) ;
V_24 -> V_27 . V_74 = F_15 ( args -> V_59 -> V_75 ) ;
F_26 ( & V_24 -> V_27 . V_28 , & V_11 -> V_22 . V_29 ) ;
} else {
V_18 . V_25 = V_32 ;
}
V_18 . V_33 = V_33 ;
V_59 -> V_76 -> V_77 ( V_71 , & V_18 ) ;
F_27 ( V_57 , V_8 ,
F_28 ( V_71 , & V_71 -> V_15 , V_59 -> V_76 -> V_78 ) ) ;
* V_62 = V_8 ;
return ( 0 ) ;
}
int
F_29 (
struct V_79 * V_3 )
{
struct V_80 * V_81 ;
struct V_80 * V_82 ;
struct V_80 * V_83 ;
struct V_14 * V_71 ;
struct V_9 * V_8 ;
int V_84 ;
int V_85 = 0 ;
int error ;
int V_4 ;
F_30 ( V_3 -> args ) ;
V_84 = V_3 -> V_86 . V_6 - 1 ;
ASSERT ( ( V_84 >= 0 ) && ( V_84 < V_34 ) ) ;
ASSERT ( V_3 -> V_86 . V_7 [ V_84 ] . V_25 == V_48 ||
V_3 -> V_86 . V_7 [ V_84 ] . V_25 == V_53 ) ;
V_83 = & V_3 -> V_86 . V_7 [ V_84 ] ;
for ( V_4 = V_84 ; ( V_4 >= 0 ) && V_83 ; V_3 -> V_86 . V_6 -- , V_4 -- ) {
V_81 = & V_3 -> V_86 . V_7 [ V_4 ] ;
V_82 = & V_3 -> V_5 . V_7 [ V_4 ] ;
switch ( V_81 -> V_25 ) {
case V_48 :
error = F_31 ( V_3 , V_81 , V_82 ) ;
if ( ( error != 0 ) && ( error != V_87 ) ) {
return ( error ) ;
}
if ( ! error ) {
V_83 = V_82 ;
break;
}
V_3 -> V_88 = 1 ;
if ( V_3 -> V_89 ) {
V_3 -> V_90 = 0 ;
F_32 ( V_3 -> args ) ;
error = F_31 ( V_3 , V_81 ,
& V_3 -> V_91 ) ;
} else {
V_3 -> V_90 = 1 ;
F_33 ( V_3 -> args ) ;
error = F_31 ( V_3 , V_82 ,
& V_3 -> V_91 ) ;
}
if ( error )
return ( error ) ;
V_83 = V_82 ;
break;
case V_53 :
error = F_34 ( V_3 , V_81 , V_82 ) ;
if ( error )
return error ;
V_83 = V_82 ;
break;
case V_32 :
error = F_35 ( V_3 , V_81 , V_82 , V_83 ,
V_84 - V_4 , & V_85 ) ;
V_83 -> V_8 = NULL ;
if ( error )
return ( error ) ;
if ( V_85 )
V_83 = V_82 ;
else
V_83 = NULL ;
break;
}
F_36 ( V_3 , & V_3 -> V_86 ) ;
}
if ( ! V_83 )
return ( 0 ) ;
ASSERT ( V_3 -> V_86 . V_6 == 0 ) ;
V_81 = & V_3 -> V_86 . V_7 [ 0 ] ;
error = F_37 ( V_3 , V_81 , V_83 ) ;
if ( error ) {
V_83 -> V_8 = NULL ;
return ( error ) ;
}
V_71 = V_81 -> V_8 -> V_16 ;
if ( V_71 -> V_15 . V_27 . V_92 ) {
if ( F_38 ( V_71 -> V_15 . V_27 . V_92 ) == V_83 -> V_30 ) {
V_8 = V_83 -> V_8 ;
} else {
ASSERT ( V_3 -> V_88 ) ;
V_8 = V_3 -> V_91 . V_8 ;
}
V_71 = V_8 -> V_16 ;
V_71 -> V_15 . V_27 . V_93 = F_39 ( V_81 -> V_30 ) ;
F_27 ( V_3 -> args -> V_72 , V_8 ,
F_28 ( V_71 , & V_71 -> V_15 . V_27 ,
sizeof( V_71 -> V_15 . V_27 ) ) ) ;
}
V_71 = V_81 -> V_8 -> V_16 ;
if ( V_71 -> V_15 . V_27 . V_93 ) {
if ( F_38 ( V_71 -> V_15 . V_27 . V_93 ) == V_83 -> V_30 ) {
V_8 = V_83 -> V_8 ;
} else {
ASSERT ( V_3 -> V_88 ) ;
V_8 = V_3 -> V_91 . V_8 ;
}
V_71 = V_8 -> V_16 ;
V_71 -> V_15 . V_27 . V_92 = F_39 ( V_81 -> V_30 ) ;
F_27 ( V_3 -> args -> V_72 , V_8 ,
F_28 ( V_71 , & V_71 -> V_15 . V_27 ,
sizeof( V_71 -> V_15 . V_27 ) ) ) ;
}
V_83 -> V_8 = NULL ;
return ( 0 ) ;
}
STATIC int
F_37 (
struct V_79 * V_3 ,
struct V_80 * V_94 ,
struct V_80 * V_95 )
{
struct V_14 * V_71 ;
struct V_14 * V_96 ;
struct V_97 * V_98 ;
struct V_17 V_99 ;
struct V_69 * args ;
struct V_9 * V_8 ;
struct V_58 * V_59 ;
struct V_56 * V_57 ;
struct V_10 * V_11 ;
struct V_100 * V_101 ;
T_2 V_30 ;
int V_33 ;
int error ;
int V_102 ;
F_40 ( V_3 -> args ) ;
args = V_3 -> args ;
error = F_41 ( args , & V_30 ) ;
if ( error )
return error ;
V_59 = args -> V_59 ;
V_57 = args -> V_72 ;
V_11 = V_3 -> V_11 ;
error = F_25 ( V_57 , V_59 , V_30 , - 1 , & V_8 , args -> V_70 ) ;
if ( error )
return error ;
V_71 = V_8 -> V_16 ;
V_96 = V_94 -> V_8 -> V_16 ;
if ( V_96 -> V_15 . V_27 . V_25 == F_42 ( V_32 ) ||
V_96 -> V_15 . V_27 . V_25 == F_42 ( V_26 ) ) {
struct V_17 V_99 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_96 ) ;
V_98 = V_59 -> V_76 -> V_103 ( V_96 ) ;
V_102 = ( int ) ( ( char * ) & V_98 [ V_99 . V_35 ] - ( char * ) V_96 ) ;
V_33 = V_99 . V_33 ;
F_22 ( V_57 , V_8 , V_66 ) ;
} else {
struct V_104 V_105 ;
struct V_106 * V_107 ;
V_101 = ( V_108 * ) V_96 ;
V_59 -> V_76 -> V_109 ( & V_105 , V_101 ) ;
V_107 = V_59 -> V_76 -> V_110 ( V_101 ) ;
ASSERT ( V_105 . V_25 == V_53 ||
V_105 . V_25 == V_54 ) ;
V_102 = ( int ) ( ( char * ) & V_107 [ V_105 . V_35 ] - ( char * ) V_101 ) ;
V_33 = 0 ;
F_22 ( V_57 , V_8 , V_68 ) ;
}
memcpy ( V_71 , V_96 , V_102 ) ;
if ( V_96 -> V_15 . V_27 . V_25 == F_42 ( V_26 ) ||
V_96 -> V_15 . V_27 . V_25 == F_42 ( V_54 ) ) {
struct V_111 * V_112 = (struct V_111 * ) V_71 ;
V_112 -> V_15 . V_27 . V_30 = F_15 ( V_8 -> V_31 ) ;
}
F_27 ( V_57 , V_8 , 0 , V_102 - 1 ) ;
V_8 -> V_50 = V_94 -> V_8 -> V_50 ;
F_43 ( V_8 , V_94 -> V_8 ) ;
V_94 -> V_8 = V_8 ;
V_94 -> V_30 = V_30 ;
error = F_23 ( args ,
( args -> V_70 == V_113 ) ? V_11 -> V_114 : 0 ,
V_33 + 1 , & V_8 , args -> V_70 ) ;
if ( error )
return error ;
V_71 = V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_71 ) ;
V_98 = V_59 -> V_76 -> V_103 ( V_71 ) ;
V_98 [ 0 ] . V_115 = F_39 ( V_94 -> V_115 ) ;
V_98 [ 0 ] . V_116 = F_39 ( V_94 -> V_30 ) ;
V_98 [ 1 ] . V_115 = F_39 ( V_95 -> V_115 ) ;
V_98 [ 1 ] . V_116 = F_39 ( V_95 -> V_30 ) ;
V_99 . V_35 = 2 ;
V_59 -> V_76 -> V_77 ( V_71 , & V_99 ) ;
#ifdef F_5
if ( V_96 -> V_15 . V_27 . V_25 == F_42 ( V_53 ) ||
V_96 -> V_15 . V_27 . V_25 == F_42 ( V_54 ) ) {
ASSERT ( V_94 -> V_30 >= V_11 -> V_114 &&
V_94 -> V_30 < V_11 -> V_117 ) ;
ASSERT ( V_95 -> V_30 >= V_11 -> V_114 &&
V_95 -> V_30 < V_11 -> V_117 ) ;
}
#endif
F_27 ( V_57 , V_8 ,
F_28 ( V_71 , V_98 , sizeof( V_118 ) * 2 ) ) ;
return 0 ;
}
STATIC int
F_35 (
struct V_79 * V_3 ,
struct V_80 * V_81 ,
struct V_80 * V_82 ,
struct V_80 * V_83 ,
int V_119 ,
int * V_120 )
{
struct V_14 * V_71 ;
struct V_17 V_99 ;
T_2 V_30 ;
int V_121 ;
int error ;
int V_122 ;
struct V_58 * V_59 = V_3 -> args -> V_59 ;
F_44 ( V_3 -> args ) ;
V_71 = V_81 -> V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_71 ) ;
V_122 = V_3 -> V_88 && V_3 -> args -> V_70 == V_123 ;
V_121 = 1 + V_122 ;
if ( V_99 . V_35 + V_121 > V_3 -> V_124 ) {
error = F_41 ( V_3 -> args , & V_30 ) ;
if ( error )
return ( error ) ;
error = F_23 ( V_3 -> args , V_30 , V_119 ,
& V_82 -> V_8 , V_3 -> args -> V_70 ) ;
if ( error )
return ( error ) ;
V_82 -> V_30 = V_30 ;
V_82 -> V_25 = V_32 ;
F_45 ( V_3 , V_81 , V_82 ) ;
error = F_46 ( V_3 , V_81 , V_82 ) ;
if ( error )
return ( error ) ;
* V_120 = 1 ;
} else {
* V_120 = 0 ;
}
V_71 = V_81 -> V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_71 ) ;
if ( V_81 -> V_125 <= V_99 . V_35 ) {
V_81 -> V_125 ++ ;
F_47 ( V_3 , V_81 , V_83 ) ;
if ( V_122 ) {
if ( V_3 -> V_90 )
V_81 -> V_125 ++ ;
F_47 ( V_3 , V_81 , & V_3 -> V_91 ) ;
V_3 -> V_88 = 0 ;
}
} else {
V_82 -> V_125 ++ ;
F_47 ( V_3 , V_82 , V_83 ) ;
if ( V_122 ) {
if ( V_3 -> V_90 )
V_82 -> V_125 ++ ;
F_47 ( V_3 , V_82 , & V_3 -> V_91 ) ;
V_3 -> V_88 = 0 ;
}
}
return ( 0 ) ;
}
STATIC void
F_45 (
struct V_79 * V_3 ,
struct V_80 * V_94 ,
struct V_80 * V_95 )
{
struct V_14 * V_126 ;
struct V_14 * V_127 ;
struct V_14 * V_128 ;
struct V_97 * V_129 ;
struct V_97 * V_130 ;
struct V_97 * V_131 ;
struct V_97 * V_132 ;
struct V_17 V_133 ;
struct V_17 V_134 ;
struct V_56 * V_57 ;
int V_35 ;
int V_135 ;
int V_136 = 0 ;
struct V_58 * V_59 = V_3 -> args -> V_59 ;
F_48 ( V_3 -> args ) ;
V_126 = V_94 -> V_8 -> V_16 ;
V_127 = V_95 -> V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_133 , V_126 ) ;
V_59 -> V_76 -> V_21 ( & V_134 , V_127 ) ;
V_129 = V_59 -> V_76 -> V_103 ( V_126 ) ;
V_130 = V_59 -> V_76 -> V_103 ( V_127 ) ;
if ( V_133 . V_35 > 0 && V_134 . V_35 > 0 &&
( ( F_38 ( V_130 [ 0 ] . V_115 ) < F_38 ( V_129 [ 0 ] . V_115 ) ) ||
( F_38 ( V_130 [ V_134 . V_35 - 1 ] . V_115 ) <
F_38 ( V_129 [ V_133 . V_35 - 1 ] . V_115 ) ) ) ) {
V_128 = V_126 ;
V_126 = V_127 ;
V_127 = V_128 ;
V_59 -> V_76 -> V_21 ( & V_133 , V_126 ) ;
V_59 -> V_76 -> V_21 ( & V_134 , V_127 ) ;
V_129 = V_59 -> V_76 -> V_103 ( V_126 ) ;
V_130 = V_59 -> V_76 -> V_103 ( V_127 ) ;
V_136 = 1 ;
}
V_35 = ( V_133 . V_35 - V_134 . V_35 ) / 2 ;
if ( V_35 == 0 )
return;
V_57 = V_3 -> args -> V_72 ;
if ( V_35 > 0 ) {
V_135 = V_134 . V_35 ;
if ( V_135 > 0 ) {
V_135 *= ( V_137 ) sizeof( V_118 ) ;
V_131 = & V_130 [ 0 ] ;
V_132 = & V_130 [ V_35 ] ;
memmove ( V_132 , V_131 , V_135 ) ;
}
V_134 . V_35 += V_35 ;
V_135 = V_35 * ( V_137 ) sizeof( V_118 ) ;
V_131 = & V_129 [ V_133 . V_35 - V_35 ] ;
V_132 = & V_130 [ 0 ] ;
memcpy ( V_132 , V_131 , V_135 ) ;
V_133 . V_35 -= V_35 ;
} else {
V_35 = - V_35 ;
V_135 = V_35 * ( V_137 ) sizeof( V_118 ) ;
V_131 = & V_130 [ 0 ] ;
V_132 = & V_129 [ V_133 . V_35 ] ;
memcpy ( V_132 , V_131 , V_135 ) ;
V_133 . V_35 += V_35 ;
F_27 ( V_57 , V_94 -> V_8 ,
F_28 ( V_126 , V_132 , V_135 ) ) ;
V_135 = V_134 . V_35 - V_35 ;
V_135 *= ( V_137 ) sizeof( V_118 ) ;
V_131 = & V_130 [ V_35 ] ;
V_132 = & V_130 [ 0 ] ;
memmove ( V_132 , V_131 , V_135 ) ;
V_134 . V_35 -= V_35 ;
}
V_59 -> V_76 -> V_77 ( V_126 , & V_133 ) ;
F_27 ( V_57 , V_94 -> V_8 ,
F_28 ( V_126 , & V_126 -> V_15 , V_59 -> V_76 -> V_78 ) ) ;
V_59 -> V_76 -> V_77 ( V_127 , & V_134 ) ;
F_27 ( V_57 , V_95 -> V_8 ,
F_28 ( V_127 , & V_127 -> V_15 ,
V_59 -> V_76 -> V_78 +
( sizeof( V_130 [ 0 ] ) * V_134 . V_35 ) ) ) ;
if ( V_136 ) {
V_126 = V_94 -> V_8 -> V_16 ;
V_127 = V_95 -> V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_133 , V_126 ) ;
V_59 -> V_76 -> V_21 ( & V_134 , V_127 ) ;
V_129 = V_59 -> V_76 -> V_103 ( V_126 ) ;
V_130 = V_59 -> V_76 -> V_103 ( V_127 ) ;
}
V_94 -> V_115 = F_38 ( V_129 [ V_133 . V_35 - 1 ] . V_115 ) ;
V_95 -> V_115 = F_38 ( V_130 [ V_134 . V_35 - 1 ] . V_115 ) ;
if ( V_94 -> V_125 >= V_133 . V_35 ) {
V_95 -> V_125 = V_94 -> V_125 - V_133 . V_35 ;
V_94 -> V_125 = V_133 . V_35 + 1 ;
}
}
STATIC void
F_47 (
struct V_79 * V_3 ,
struct V_80 * V_81 ,
struct V_80 * V_82 )
{
struct V_14 * V_71 ;
struct V_17 V_99 ;
struct V_97 * V_98 ;
int V_135 ;
struct V_58 * V_59 = V_3 -> args -> V_59 ;
F_49 ( V_3 -> args ) ;
V_71 = V_81 -> V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_71 ) ;
V_98 = V_59 -> V_76 -> V_103 ( V_71 ) ;
ASSERT ( V_81 -> V_125 >= 0 && V_81 -> V_125 <= V_99 . V_35 ) ;
ASSERT ( V_82 -> V_30 != 0 ) ;
if ( V_3 -> args -> V_70 == V_113 )
ASSERT ( V_82 -> V_30 >= V_3 -> V_11 -> V_114 &&
V_82 -> V_30 < V_3 -> V_11 -> V_117 ) ;
V_135 = 0 ;
if ( V_81 -> V_125 < V_99 . V_35 ) {
V_135 = ( V_99 . V_35 - V_81 -> V_125 ) * ( V_137 ) sizeof( * V_98 ) ;
memmove ( & V_98 [ V_81 -> V_125 + 1 ] , & V_98 [ V_81 -> V_125 ] , V_135 ) ;
}
V_98 [ V_81 -> V_125 ] . V_115 = F_39 ( V_82 -> V_115 ) ;
V_98 [ V_81 -> V_125 ] . V_116 = F_39 ( V_82 -> V_30 ) ;
F_27 ( V_3 -> args -> V_72 , V_81 -> V_8 ,
F_28 ( V_71 , & V_98 [ V_81 -> V_125 ] ,
V_135 + sizeof( * V_98 ) ) ) ;
V_99 . V_35 += 1 ;
V_59 -> V_76 -> V_77 ( V_71 , & V_99 ) ;
F_27 ( V_3 -> args -> V_72 , V_81 -> V_8 ,
F_28 ( V_71 , & V_71 -> V_15 , V_59 -> V_76 -> V_78 ) ) ;
V_81 -> V_115 = F_38 ( V_98 [ V_99 . V_35 - 1 ] . V_115 ) ;
}
int
F_50 (
struct V_79 * V_3 )
{
struct V_80 * V_138 ;
struct V_80 * V_139 ;
int V_85 = 0 ;
int error ;
F_51 ( V_3 -> args ) ;
V_138 = & V_3 -> V_86 . V_7 [ V_3 -> V_86 . V_6 - 1 ] ;
V_139 = & V_3 -> V_5 . V_7 [ V_3 -> V_86 . V_6 - 1 ] ;
ASSERT ( V_3 -> V_86 . V_7 [ 0 ] . V_25 == V_32 ) ;
ASSERT ( V_138 -> V_25 == V_48 ||
V_138 -> V_25 == V_53 ) ;
for ( ; V_3 -> V_86 . V_6 >= 2 ; V_138 -- , V_139 -- ,
V_3 -> V_86 . V_6 -- ) {
switch ( V_138 -> V_25 ) {
case V_48 :
error = F_52 ( V_3 , & V_85 ) ;
if ( error )
return ( error ) ;
if ( V_85 == 0 )
return ( 0 ) ;
F_53 ( V_3 , V_138 , V_139 ) ;
break;
case V_53 :
error = F_54 ( V_3 , & V_85 ) ;
if ( error )
return error ;
if ( V_85 == 0 )
return 0 ;
F_55 ( V_3 , V_138 , V_139 ) ;
break;
case V_32 :
F_56 ( V_3 , V_138 ) ;
F_36 ( V_3 , & V_3 -> V_86 ) ;
error = F_57 ( V_3 , & V_85 ) ;
if ( error )
return ( error ) ;
if ( V_85 == 0 )
return 0 ;
F_58 ( V_3 , V_138 , V_139 ) ;
break;
}
F_36 ( V_3 , & V_3 -> V_5 ) ;
error = F_59 ( V_3 , V_138 , V_139 ) ;
F_3 ( V_3 ) ;
if ( error )
return ( error ) ;
error = F_60 ( V_3 -> args , V_138 -> V_30 ,
V_138 -> V_8 ) ;
V_138 -> V_8 = NULL ;
if ( error )
return ( error ) ;
}
F_56 ( V_3 , V_138 ) ;
F_36 ( V_3 , & V_3 -> V_86 ) ;
error = F_61 ( V_3 , & V_3 -> V_86 . V_7 [ 0 ] ) ;
return ( error ) ;
}
static void
F_62 ( struct V_46 * V_140 , T_4 V_33 )
{
T_5 V_25 = V_140 -> V_25 ;
if ( V_33 == 1 ) {
ASSERT ( V_25 == F_42 ( V_53 ) ||
V_25 == F_42 ( V_54 ) ||
V_25 == F_42 ( V_48 ) ||
V_25 == F_42 ( V_49 ) ) ;
} else {
ASSERT ( V_25 == F_42 ( V_32 ) ||
V_25 == F_42 ( V_26 ) ) ;
}
ASSERT ( ! V_140 -> V_92 ) ;
ASSERT ( ! V_140 -> V_93 ) ;
}
STATIC int
F_61 (
struct V_79 * V_3 ,
struct V_80 * V_141 )
{
struct V_14 * V_96 ;
struct V_69 * args ;
T_2 V_142 ;
struct V_9 * V_8 ;
struct V_17 V_143 ;
struct V_97 * V_98 ;
int error ;
struct V_58 * V_59 = V_3 -> args -> V_59 ;
F_63 ( V_3 -> args ) ;
ASSERT ( V_141 -> V_25 == V_32 ) ;
args = V_3 -> args ;
V_96 = V_141 -> V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_143 , V_96 ) ;
ASSERT ( V_143 . V_92 == 0 ) ;
ASSERT ( V_143 . V_93 == 0 ) ;
if ( V_143 . V_35 > 1 )
return 0 ;
V_98 = V_59 -> V_76 -> V_103 ( V_96 ) ;
V_142 = F_38 ( V_98 [ 0 ] . V_116 ) ;
ASSERT ( V_142 != 0 ) ;
error = F_20 ( args -> V_72 , V_59 , V_142 , - 1 , & V_8 ,
args -> V_70 ) ;
if ( error )
return error ;
F_62 ( V_8 -> V_16 , V_143 . V_33 ) ;
memcpy ( V_141 -> V_8 -> V_16 , V_8 -> V_16 , V_3 -> V_144 ) ;
V_141 -> V_8 -> V_50 = V_8 -> V_50 ;
F_43 ( V_141 -> V_8 , V_8 ) ;
if ( V_143 . V_25 == V_26 ) {
struct V_145 * V_146 = V_141 -> V_8 -> V_16 ;
V_146 -> V_30 = F_15 ( V_141 -> V_8 -> V_31 ) ;
}
F_27 ( args -> V_72 , V_141 -> V_8 , 0 , V_3 -> V_144 - 1 ) ;
error = F_60 ( args , V_142 , V_8 ) ;
return ( error ) ;
}
STATIC int
F_57 (
struct V_79 * V_3 ,
int * V_85 )
{
struct V_14 * V_71 ;
struct V_80 * V_7 ;
struct V_46 * V_27 ;
T_2 V_30 ;
struct V_9 * V_8 ;
struct V_17 V_99 ;
int V_35 ;
int V_147 ;
int error ;
int V_148 ;
int V_4 ;
struct V_58 * V_59 = V_3 -> args -> V_59 ;
F_64 ( V_3 -> args ) ;
V_7 = & V_3 -> V_86 . V_7 [ V_3 -> V_86 . V_6 - 1 ] ;
V_27 = V_7 -> V_8 -> V_16 ;
V_71 = ( V_149 * ) V_27 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_71 ) ;
if ( V_99 . V_35 > ( V_3 -> V_124 >> 1 ) ) {
* V_85 = 0 ;
return ( 0 ) ;
}
if ( V_99 . V_35 == 0 ) {
V_147 = ( V_27 -> V_92 != 0 ) ;
memcpy ( & V_3 -> V_5 , & V_3 -> V_86 , sizeof( V_3 -> V_86 ) ) ;
error = F_65 ( V_3 , & V_3 -> V_5 , V_147 ,
0 , & V_148 ) ;
if ( error )
return ( error ) ;
if ( V_148 ) {
* V_85 = 0 ;
} else {
* V_85 = 2 ;
}
return ( 0 ) ;
}
V_35 = V_3 -> V_124 ;
V_35 -= V_3 -> V_124 >> 2 ;
V_35 -= V_99 . V_35 ;
V_147 = V_99 . V_92 < V_99 . V_93 ;
for ( V_4 = 0 ; V_4 < 2 ; V_147 = ! V_147 , V_4 ++ ) {
struct V_17 V_150 ;
if ( V_147 )
V_30 = V_99 . V_92 ;
else
V_30 = V_99 . V_93 ;
if ( V_30 == 0 )
continue;
error = F_20 ( V_3 -> args -> V_72 , V_59 ,
V_30 , - 1 , & V_8 , V_3 -> args -> V_70 ) ;
if ( error )
return ( error ) ;
V_71 = V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_150 , V_71 ) ;
F_66 ( V_3 -> args -> V_72 , V_8 ) ;
if ( V_35 - V_150 . V_35 >= 0 )
break;
}
if ( V_4 >= 2 ) {
* V_85 = 0 ;
return 0 ;
}
memcpy ( & V_3 -> V_5 , & V_3 -> V_86 , sizeof( V_3 -> V_86 ) ) ;
if ( V_30 < V_7 -> V_30 ) {
error = F_65 ( V_3 , & V_3 -> V_5 , V_147 ,
0 , & V_148 ) ;
} else {
error = F_65 ( V_3 , & V_3 -> V_86 , V_147 ,
0 , & V_148 ) ;
}
if ( error )
return error ;
if ( V_148 ) {
* V_85 = 0 ;
return 0 ;
}
* V_85 = 1 ;
return 0 ;
}
STATIC V_137
F_67 (
struct V_58 * V_59 ,
struct V_9 * V_8 ,
int * V_35 )
{
struct V_14 * V_71 ;
struct V_97 * V_98 ;
struct V_17 V_99 ;
V_71 = V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_71 ) ;
if ( V_35 )
* V_35 = V_99 . V_35 ;
if ( ! V_99 . V_35 )
return 0 ;
V_98 = V_59 -> V_76 -> V_103 ( V_71 ) ;
return F_38 ( V_98 [ V_99 . V_35 - 1 ] . V_115 ) ;
}
void
F_36 (
struct V_79 * V_3 ,
struct V_151 * V_86 )
{
struct V_80 * V_7 ;
struct V_14 * V_71 ;
struct V_97 * V_98 ;
T_6 V_152 = 0 ;
int V_33 ;
int V_35 ;
struct V_58 * V_59 = V_3 -> args -> V_59 ;
F_68 ( V_3 -> args ) ;
V_33 = V_86 -> V_6 - 1 ;
V_7 = & V_86 -> V_7 [ V_33 ] ;
switch ( V_7 -> V_25 ) {
case V_48 :
V_152 = F_69 ( V_7 -> V_8 , & V_35 ) ;
if ( V_35 == 0 )
return;
break;
case V_53 :
V_152 = F_70 ( V_59 , V_7 -> V_8 , & V_35 ) ;
if ( V_35 == 0 )
return;
break;
case V_32 :
V_152 = F_67 ( V_59 , V_7 -> V_8 , & V_35 ) ;
if ( V_35 == 0 )
return;
break;
}
for ( V_7 -- , V_33 -- ; V_33 >= 0 ; V_7 -- , V_33 -- ) {
struct V_17 V_99 ;
V_71 = V_7 -> V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_71 ) ;
V_98 = V_59 -> V_76 -> V_103 ( V_71 ) ;
if ( F_38 ( V_98 [ V_7 -> V_125 ] . V_115 ) == V_152 )
break;
V_7 -> V_115 = V_152 ;
V_98 [ V_7 -> V_125 ] . V_115 = F_39 ( V_152 ) ;
F_27 ( V_3 -> args -> V_72 , V_7 -> V_8 ,
F_28 ( V_71 , & V_98 [ V_7 -> V_125 ] ,
sizeof( * V_98 ) ) ) ;
V_152 = F_38 ( V_98 [ V_99 . V_35 - 1 ] . V_115 ) ;
}
}
STATIC void
F_56 (
struct V_79 * V_3 ,
struct V_80 * V_138 )
{
struct V_14 * V_71 ;
struct V_17 V_99 ;
struct V_97 * V_98 ;
int V_125 ;
int V_135 ;
struct V_58 * V_59 = V_3 -> args -> V_59 ;
F_71 ( V_3 -> args ) ;
V_71 = V_138 -> V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_71 ) ;
ASSERT ( V_138 -> V_125 < V_99 . V_35 ) ;
ASSERT ( V_138 -> V_125 >= 0 ) ;
V_125 = V_138 -> V_125 ;
V_98 = V_59 -> V_76 -> V_103 ( V_71 ) ;
if ( V_125 < V_99 . V_35 - 1 ) {
V_135 = V_99 . V_35 - V_125 - 1 ;
V_135 *= ( V_137 ) sizeof( V_118 ) ;
memmove ( & V_98 [ V_125 ] , & V_98 [ V_125 + 1 ] , V_135 ) ;
F_27 ( V_3 -> args -> V_72 , V_138 -> V_8 ,
F_28 ( V_71 , & V_98 [ V_125 ] , V_135 ) ) ;
V_125 = V_99 . V_35 - 1 ;
}
memset ( & V_98 [ V_125 ] , 0 , sizeof( V_118 ) ) ;
F_27 ( V_3 -> args -> V_72 , V_138 -> V_8 ,
F_28 ( V_71 , & V_98 [ V_125 ] , sizeof( V_98 [ V_125 ] ) ) ) ;
V_99 . V_35 -= 1 ;
V_59 -> V_76 -> V_77 ( V_71 , & V_99 ) ;
F_27 ( V_3 -> args -> V_72 , V_138 -> V_8 ,
F_28 ( V_71 , & V_71 -> V_15 , V_59 -> V_76 -> V_78 ) ) ;
V_138 -> V_115 = F_38 ( V_98 [ V_125 - 1 ] . V_115 ) ;
}
STATIC void
F_58 (
struct V_79 * V_3 ,
struct V_80 * V_138 ,
struct V_80 * V_139 )
{
struct V_14 * V_153 ;
struct V_14 * V_154 ;
struct V_97 * V_155 ;
struct V_97 * V_156 ;
struct V_17 V_157 ;
struct V_17 V_158 ;
struct V_56 * V_57 ;
int V_159 ;
int V_135 ;
struct V_58 * V_59 = V_3 -> args -> V_59 ;
F_72 ( V_3 -> args ) ;
V_153 = V_138 -> V_8 -> V_16 ;
V_154 = V_139 -> V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_157 , V_153 ) ;
V_59 -> V_76 -> V_21 ( & V_158 , V_154 ) ;
V_155 = V_59 -> V_76 -> V_103 ( V_153 ) ;
V_156 = V_59 -> V_76 -> V_103 ( V_154 ) ;
V_57 = V_3 -> args -> V_72 ;
if ( ( F_38 ( V_155 [ 0 ] . V_115 ) <
F_38 ( V_156 [ 0 ] . V_115 ) ) ||
( F_38 ( V_155 [ V_157 . V_35 - 1 ] . V_115 ) <
F_38 ( V_156 [ V_158 . V_35 - 1 ] . V_115 ) ) ) {
V_135 = V_158 . V_35 * sizeof( V_118 ) ;
memmove ( & V_156 [ V_157 . V_35 ] , & V_156 [ 0 ] , V_135 ) ;
V_159 = 0 ;
F_27 ( V_57 , V_139 -> V_8 ,
F_28 ( V_154 , & V_156 [ 0 ] ,
( V_158 . V_35 + V_157 . V_35 ) *
sizeof( V_118 ) ) ) ;
} else {
V_159 = V_158 . V_35 ;
F_27 ( V_57 , V_139 -> V_8 ,
F_28 ( V_154 , & V_156 [ V_159 ] ,
V_157 . V_35 * sizeof( V_118 ) ) ) ;
}
V_135 = V_157 . V_35 * ( V_137 ) sizeof( V_118 ) ;
memcpy ( & V_156 [ V_159 ] , & V_155 [ 0 ] , V_135 ) ;
V_158 . V_35 += V_157 . V_35 ;
V_59 -> V_76 -> V_77 ( V_154 , & V_158 ) ;
F_27 ( V_57 , V_139 -> V_8 ,
F_28 ( V_154 , & V_154 -> V_15 ,
V_59 -> V_76 -> V_78 ) ) ;
V_139 -> V_115 = F_38 ( V_156 [ V_158 . V_35 - 1 ] . V_115 ) ;
}
int
F_73 (
struct V_79 * V_3 ,
int * V_120 )
{
struct V_80 * V_7 ;
struct V_46 * V_160 ;
struct V_14 * V_71 ;
struct V_97 * V_98 ;
struct V_17 V_99 ;
struct V_69 * args ;
T_2 V_30 ;
T_6 V_115 ;
T_6 V_161 ;
int V_162 ;
int V_163 ;
int V_84 ;
int error ;
int V_148 ;
struct V_58 * V_59 = V_3 -> args -> V_59 ;
args = V_3 -> args ;
V_30 = ( args -> V_70 == V_113 ) ? V_3 -> V_11 -> V_114 : 0 ;
for ( V_7 = & V_3 -> V_86 . V_7 [ 0 ] , V_3 -> V_86 . V_6 = 1 ;
V_3 -> V_86 . V_6 <= V_34 ;
V_7 ++ , V_3 -> V_86 . V_6 ++ ) {
V_7 -> V_30 = V_30 ;
error = F_20 ( args -> V_72 , args -> V_59 , V_30 ,
- 1 , & V_7 -> V_8 , args -> V_70 ) ;
if ( error ) {
V_7 -> V_30 = 0 ;
V_3 -> V_86 . V_6 -- ;
return ( error ) ;
}
V_160 = V_7 -> V_8 -> V_16 ;
V_7 -> V_25 = F_18 ( V_160 -> V_25 ) ;
if ( V_7 -> V_25 == V_48 ||
V_7 -> V_25 == V_49 ) {
V_7 -> V_25 = V_48 ;
V_7 -> V_115 = F_69 ( V_7 -> V_8 , NULL ) ;
break;
}
if ( V_7 -> V_25 == V_53 ||
V_7 -> V_25 == V_54 ) {
V_7 -> V_25 = V_53 ;
V_7 -> V_115 = F_70 ( args -> V_59 ,
V_7 -> V_8 , NULL ) ;
break;
}
V_7 -> V_25 = V_32 ;
V_71 = V_7 -> V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_71 ) ;
V_98 = V_59 -> V_76 -> V_103 ( V_71 ) ;
V_84 = V_99 . V_35 ;
V_7 -> V_115 = F_38 ( V_98 [ V_84 - 1 ] . V_115 ) ;
V_162 = V_163 = V_84 / 2 ;
V_115 = args -> V_115 ;
while ( V_163 > 4 ) {
V_163 /= 2 ;
V_161 = F_38 ( V_98 [ V_162 ] . V_115 ) ;
if ( V_161 < V_115 )
V_162 += V_163 ;
else if ( V_161 > V_115 )
V_162 -= V_163 ;
else
break;
}
ASSERT ( ( V_162 >= 0 ) && ( V_162 < V_84 ) ) ;
ASSERT ( ( V_163 <= 4 ) ||
( F_38 ( V_98 [ V_162 ] . V_115 ) == V_115 ) ) ;
while ( V_162 > 0 &&
F_38 ( V_98 [ V_162 ] . V_115 ) >= V_115 ) {
V_162 -- ;
}
while ( V_162 < V_84 &&
F_38 ( V_98 [ V_162 ] . V_115 ) < V_115 ) {
V_162 ++ ;
}
if ( V_162 == V_84 ) {
V_7 -> V_125 = V_84 - 1 ;
V_30 = F_38 ( V_98 [ V_84 - 1 ] . V_116 ) ;
} else {
V_7 -> V_125 = V_162 ;
V_30 = F_38 ( V_98 [ V_162 ] . V_116 ) ;
}
}
for (; ; ) {
if ( V_7 -> V_25 == V_53 ) {
V_148 = F_74 ( V_7 -> V_8 , args ,
& V_7 -> V_125 , V_3 ) ;
} else if ( V_7 -> V_25 == V_48 ) {
V_148 = F_75 ( V_7 -> V_8 , args ) ;
V_7 -> V_125 = args -> V_125 ;
args -> V_30 = V_7 -> V_30 ;
} else {
ASSERT ( 0 ) ;
return F_76 ( V_41 ) ;
}
if ( ( ( V_148 == V_164 ) || ( V_148 == V_165 ) ) &&
( V_7 -> V_115 == args -> V_115 ) ) {
error = F_65 ( V_3 , & V_3 -> V_86 , 1 , 1 ,
& V_148 ) ;
if ( error )
return ( error ) ;
if ( V_148 == 0 ) {
continue;
} else if ( V_7 -> V_25 == V_48 ) {
V_148 = F_76 ( V_165 ) ;
}
}
break;
}
* V_120 = V_148 ;
return ( 0 ) ;
}
STATIC int
F_77 (
struct V_58 * V_59 ,
struct V_9 * V_166 ,
struct V_9 * V_167 )
{
struct V_14 * V_126 ;
struct V_14 * V_127 ;
struct V_97 * V_129 ;
struct V_97 * V_130 ;
struct V_17 V_168 ;
struct V_17 V_169 ;
V_126 = V_166 -> V_16 ;
V_127 = V_167 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_168 , V_126 ) ;
V_59 -> V_76 -> V_21 ( & V_169 , V_127 ) ;
V_129 = V_59 -> V_76 -> V_103 ( V_126 ) ;
V_130 = V_59 -> V_76 -> V_103 ( V_127 ) ;
if ( V_168 . V_35 > 0 && V_169 . V_35 > 0 &&
( ( F_38 ( V_130 [ 0 ] . V_115 ) < F_38 ( V_129 [ 0 ] . V_115 ) ) ||
( F_38 ( V_130 [ V_169 . V_35 - 1 ] . V_115 ) <
F_38 ( V_129 [ V_168 . V_35 - 1 ] . V_115 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_46 (
struct V_79 * V_3 ,
struct V_80 * V_170 ,
struct V_80 * V_171 )
{
struct V_46 * V_172 ;
struct V_46 * V_173 ;
struct V_46 * V_174 ;
struct V_69 * args ;
struct V_9 * V_8 ;
int V_116 = 0 ;
int error ;
struct V_58 * V_59 = V_3 -> args -> V_59 ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
V_172 = V_170 -> V_8 -> V_16 ;
V_173 = V_171 -> V_8 -> V_16 ;
ASSERT ( V_170 -> V_25 == V_32 ||
V_170 -> V_25 == V_53 ||
V_170 -> V_25 == V_48 ) ;
switch ( V_170 -> V_25 ) {
case V_48 :
V_116 = F_78 ( V_170 -> V_8 , V_171 -> V_8 ) ;
break;
case V_53 :
V_116 = F_79 ( V_59 , V_170 -> V_8 , V_171 -> V_8 ) ;
break;
case V_32 :
V_116 = F_77 ( V_59 , V_170 -> V_8 , V_171 -> V_8 ) ;
break;
}
if ( V_116 ) {
F_80 ( args ) ;
V_173 -> V_92 = F_39 ( V_170 -> V_30 ) ;
V_173 -> V_93 = V_172 -> V_93 ;
if ( V_172 -> V_93 ) {
error = F_20 ( args -> V_72 , V_59 ,
F_38 ( V_172 -> V_93 ) ,
- 1 , & V_8 , args -> V_70 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_174 = V_8 -> V_16 ;
ASSERT ( V_174 -> V_25 == V_172 -> V_25 ) ;
ASSERT ( F_38 ( V_174 -> V_92 ) == V_170 -> V_30 ) ;
V_174 -> V_92 = F_39 ( V_171 -> V_30 ) ;
F_27 ( args -> V_72 , V_8 , 0 , sizeof( * V_174 ) - 1 ) ;
}
V_172 -> V_93 = F_39 ( V_171 -> V_30 ) ;
} else {
F_81 ( args ) ;
V_173 -> V_92 = V_172 -> V_92 ;
V_173 -> V_93 = F_39 ( V_170 -> V_30 ) ;
if ( V_172 -> V_92 ) {
error = F_20 ( args -> V_72 , V_59 ,
F_38 ( V_172 -> V_92 ) ,
- 1 , & V_8 , args -> V_70 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_174 = V_8 -> V_16 ;
ASSERT ( V_174 -> V_25 == V_172 -> V_25 ) ;
ASSERT ( F_38 ( V_174 -> V_93 ) == V_170 -> V_30 ) ;
V_174 -> V_93 = F_39 ( V_171 -> V_30 ) ;
F_27 ( args -> V_72 , V_8 , 0 , sizeof( * V_174 ) - 1 ) ;
}
V_172 -> V_92 = F_39 ( V_171 -> V_30 ) ;
}
F_27 ( args -> V_72 , V_170 -> V_8 , 0 , sizeof( * V_174 ) - 1 ) ;
F_27 ( args -> V_72 , V_171 -> V_8 , 0 , sizeof( * V_174 ) - 1 ) ;
return ( 0 ) ;
}
STATIC int
F_59 (
struct V_79 * V_3 ,
struct V_80 * V_138 ,
struct V_80 * V_139 )
{
struct V_46 * V_175 ;
struct V_46 * V_176 ;
struct V_46 * V_174 ;
struct V_69 * args ;
struct V_9 * V_8 ;
int error ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
V_176 = V_139 -> V_8 -> V_16 ;
V_175 = V_138 -> V_8 -> V_16 ;
ASSERT ( V_139 -> V_25 == V_32 ||
V_139 -> V_25 == V_53 ||
V_139 -> V_25 == V_48 ) ;
ASSERT ( V_139 -> V_25 == V_138 -> V_25 ) ;
ASSERT ( ( F_38 ( V_176 -> V_92 ) == V_138 -> V_30 ) ||
( F_38 ( V_176 -> V_93 ) == V_138 -> V_30 ) ) ;
ASSERT ( ( F_38 ( V_175 -> V_92 ) == V_139 -> V_30 ) ||
( F_38 ( V_175 -> V_93 ) == V_139 -> V_30 ) ) ;
if ( F_38 ( V_176 -> V_93 ) == V_138 -> V_30 ) {
F_82 ( args ) ;
V_176 -> V_93 = V_175 -> V_93 ;
if ( V_175 -> V_93 ) {
error = F_20 ( args -> V_72 , args -> V_59 ,
F_38 ( V_175 -> V_93 ) ,
- 1 , & V_8 , args -> V_70 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_174 = V_8 -> V_16 ;
ASSERT ( V_174 -> V_25 == V_176 -> V_25 ) ;
ASSERT ( F_38 ( V_174 -> V_92 ) == V_138 -> V_30 ) ;
V_174 -> V_92 = F_39 ( V_139 -> V_30 ) ;
F_27 ( args -> V_72 , V_8 , 0 ,
sizeof( * V_174 ) - 1 ) ;
}
} else {
F_83 ( args ) ;
V_176 -> V_92 = V_175 -> V_92 ;
if ( V_175 -> V_92 ) {
error = F_20 ( args -> V_72 , args -> V_59 ,
F_38 ( V_175 -> V_92 ) ,
- 1 , & V_8 , args -> V_70 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_174 = V_8 -> V_16 ;
ASSERT ( V_174 -> V_25 == V_176 -> V_25 ) ;
ASSERT ( F_38 ( V_174 -> V_93 ) == V_138 -> V_30 ) ;
V_174 -> V_93 = F_39 ( V_139 -> V_30 ) ;
F_27 ( args -> V_72 , V_8 , 0 ,
sizeof( * V_174 ) - 1 ) ;
}
}
F_27 ( args -> V_72 , V_139 -> V_8 , 0 , sizeof( * V_176 ) - 1 ) ;
return ( 0 ) ;
}
int
F_65 (
struct V_79 * V_3 ,
struct V_151 * V_86 ,
int V_147 ,
int V_177 ,
int * V_120 )
{
struct V_80 * V_7 ;
struct V_46 * V_27 ;
struct V_14 * V_71 ;
struct V_69 * args ;
struct V_97 * V_98 ;
struct V_17 V_99 ;
T_2 V_30 = 0 ;
int V_33 ;
int error ;
struct V_58 * V_59 = V_3 -> args -> V_59 ;
F_84 ( V_3 -> args ) ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
ASSERT ( V_86 != NULL ) ;
ASSERT ( ( V_86 -> V_6 > 0 ) && ( V_86 -> V_6 < V_34 ) ) ;
V_33 = ( V_86 -> V_6 - 1 ) - 1 ;
for ( V_7 = & V_86 -> V_7 [ V_33 ] ; V_33 >= 0 ; V_7 -- , V_33 -- ) {
V_71 = V_7 -> V_8 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_71 ) ;
V_98 = V_59 -> V_76 -> V_103 ( V_71 ) ;
if ( V_147 && ( V_7 -> V_125 < V_99 . V_35 - 1 ) ) {
V_7 -> V_125 ++ ;
V_30 = F_38 ( V_98 [ V_7 -> V_125 ] . V_116 ) ;
break;
} else if ( ! V_147 && ( V_7 -> V_125 > 0 ) ) {
V_7 -> V_125 -- ;
V_30 = F_38 ( V_98 [ V_7 -> V_125 ] . V_116 ) ;
break;
}
}
if ( V_33 < 0 ) {
* V_120 = F_76 ( V_164 ) ;
ASSERT ( args -> V_178 & V_179 ) ;
return ( 0 ) ;
}
for ( V_7 ++ , V_33 ++ ; V_33 < V_86 -> V_6 ; V_7 ++ , V_33 ++ ) {
if ( V_177 )
F_66 ( args -> V_72 , V_7 -> V_8 ) ;
V_7 -> V_30 = V_30 ;
error = F_20 ( args -> V_72 , V_59 , V_30 , - 1 ,
& V_7 -> V_8 , args -> V_70 ) ;
if ( error )
return ( error ) ;
V_27 = V_7 -> V_8 -> V_16 ;
ASSERT ( V_27 -> V_25 == F_42 ( V_32 ) ||
V_27 -> V_25 == F_42 ( V_26 ) ||
V_27 -> V_25 == F_42 ( V_53 ) ||
V_27 -> V_25 == F_42 ( V_54 ) ||
V_27 -> V_25 == F_42 ( V_48 ) ||
V_27 -> V_25 == F_42 ( V_49 ) ) ;
switch ( F_18 ( V_27 -> V_25 ) ) {
case V_32 :
case V_26 :
V_7 -> V_25 = V_32 ;
V_71 = ( V_149 * ) V_27 ;
V_59 -> V_76 -> V_21 ( & V_99 , V_71 ) ;
V_98 = V_59 -> V_76 -> V_103 ( V_71 ) ;
V_7 -> V_115 = F_38 ( V_98 [ V_99 . V_35 - 1 ] . V_115 ) ;
if ( V_147 )
V_7 -> V_125 = 0 ;
else
V_7 -> V_125 = V_99 . V_35 - 1 ;
V_30 = F_38 ( V_98 [ V_7 -> V_125 ] . V_116 ) ;
break;
case V_48 :
case V_49 :
V_7 -> V_25 = V_48 ;
ASSERT ( V_33 == V_86 -> V_6 - 1 ) ;
V_7 -> V_125 = 0 ;
V_7 -> V_115 = F_69 ( V_7 -> V_8 , NULL ) ;
break;
case V_53 :
case V_54 :
V_7 -> V_25 = V_53 ;
ASSERT ( V_33 == V_86 -> V_6 - 1 ) ;
V_7 -> V_125 = 0 ;
V_7 -> V_115 = F_70 ( args -> V_59 ,
V_7 -> V_8 , NULL ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
}
* V_120 = 0 ;
return 0 ;
}
T_6
F_85 ( const T_7 * V_180 , int V_181 )
{
T_6 V_182 ;
for ( V_182 = 0 ; V_181 >= 4 ; V_181 -= 4 , V_180 += 4 )
V_182 = ( V_180 [ 0 ] << 21 ) ^ ( V_180 [ 1 ] << 14 ) ^ ( V_180 [ 2 ] << 7 ) ^
( V_180 [ 3 ] << 0 ) ^ F_86 ( V_182 , 7 * 4 ) ;
switch ( V_181 ) {
case 3 :
return ( V_180 [ 0 ] << 14 ) ^ ( V_180 [ 1 ] << 7 ) ^ ( V_180 [ 2 ] << 0 ) ^
F_86 ( V_182 , 7 * 3 ) ;
case 2 :
return ( V_180 [ 0 ] << 7 ) ^ ( V_180 [ 1 ] << 0 ) ^ F_86 ( V_182 , 7 * 2 ) ;
case 1 :
return ( V_180 [ 0 ] << 0 ) ^ F_86 ( V_182 , 7 * 1 ) ;
default:
return V_182 ;
}
}
enum V_183
F_87 (
struct V_69 * args ,
const unsigned char * V_180 ,
int V_184 )
{
return ( args -> V_181 == V_184 && memcmp ( args -> V_180 , V_180 , V_184 ) == 0 ) ?
V_185 : V_186 ;
}
static T_6
F_88 (
struct V_187 * V_180 )
{
return F_85 ( V_180 -> V_180 , V_180 -> V_184 ) ;
}
int
F_89 (
struct V_69 * args ,
T_8 * V_60 ,
int V_35 )
{
struct V_56 * V_57 = args -> V_72 ;
struct V_58 * V_59 = args -> V_59 ;
int V_188 = args -> V_70 ;
T_9 V_189 = V_59 -> V_190 . V_191 ;
struct V_192 V_193 , * V_194 ;
int V_195 , error , V_196 , V_4 , V_197 ;
error = F_90 ( V_57 , V_59 , V_35 , V_60 , V_188 ) ;
if ( error )
return error ;
V_195 = 1 ;
ASSERT ( args -> V_198 != NULL ) ;
error = F_91 ( V_57 , V_59 , * V_60 , V_35 ,
F_92 ( V_188 ) | V_199 | V_200 ,
args -> V_198 , args -> V_201 , & V_193 , & V_195 ,
args -> V_202 ) ;
if ( error )
return error ;
ASSERT ( V_195 <= 1 ) ;
if ( V_195 == 1 ) {
V_194 = & V_193 ;
V_197 = 1 ;
} else if ( V_195 == 0 && V_35 > 1 ) {
T_8 V_203 ;
int V_204 ;
V_194 = F_93 ( sizeof( * V_194 ) * V_35 , V_205 ) ;
for ( V_203 = * V_60 , V_197 = 0 ; V_203 < * V_60 + V_35 ; ) {
V_195 = F_94 ( V_206 , V_35 ) ;
V_204 = ( int ) ( * V_60 + V_35 - V_203 ) ;
error = F_91 ( V_57 , V_59 , V_203 , V_204 ,
F_92 ( V_188 ) | V_199 ,
args -> V_198 , args -> V_201 ,
& V_194 [ V_197 ] , & V_195 , args -> V_202 ) ;
if ( error )
goto V_207;
if ( V_195 < 1 )
break;
V_197 += V_195 ;
V_203 = V_194 [ V_197 - 1 ] . V_208 +
V_194 [ V_197 - 1 ] . V_209 ;
}
} else {
V_197 = 0 ;
V_194 = NULL ;
}
for ( V_4 = 0 , V_196 = 0 ; V_4 < V_197 ; V_4 ++ )
V_196 += V_194 [ V_4 ] . V_209 ;
if ( V_196 != V_35 || V_194 [ 0 ] . V_208 != * V_60 ||
V_194 [ V_197 - 1 ] . V_208 + V_194 [ V_197 - 1 ] . V_209 !=
* V_60 + V_35 ) {
error = F_76 ( V_87 ) ;
goto V_207;
}
args -> V_201 -= V_59 -> V_190 . V_191 - V_189 ;
V_207:
if ( V_194 != & V_193 )
F_95 ( V_194 ) ;
return error ;
}
int
F_41 (
struct V_69 * args ,
T_2 * V_210 )
{
T_8 V_60 ;
int V_35 ;
int error ;
F_96 ( args ) ;
if ( args -> V_70 == V_113 ) {
V_60 = args -> V_59 -> V_211 -> V_114 ;
V_35 = args -> V_59 -> V_211 -> V_212 ;
} else {
V_60 = 0 ;
V_35 = 1 ;
}
error = F_89 ( args , & V_60 , V_35 ) ;
if ( ! error )
* V_210 = ( T_2 ) V_60 ;
return error ;
}
STATIC int
F_97 (
struct V_69 * args ,
T_2 * V_213 ,
struct V_9 * * V_214 )
{
struct V_46 * V_215 ;
struct V_46 * V_216 ;
struct V_14 * V_217 ;
struct V_14 * V_218 ;
struct V_100 * V_219 ;
struct V_97 * V_98 ;
struct V_17 V_220 ;
struct V_58 * V_59 ;
struct V_56 * V_57 ;
struct V_10 * V_11 ;
struct V_9 * V_221 ;
struct V_9 * V_222 ;
struct V_9 * V_223 ;
struct V_9 * V_224 ;
T_6 V_225 ;
T_8 V_226 ;
T_2 V_227 ;
T_2 V_228 ;
T_2 V_229 ;
T_2 V_230 ;
int error ;
int V_188 ;
int V_231 ;
int V_33 ;
int V_232 ;
F_98 ( args ) ;
V_221 = * V_214 ;
V_227 = * V_213 ;
V_57 = args -> V_72 ;
V_59 = args -> V_59 ;
V_188 = args -> V_70 ;
ASSERT ( V_188 == V_113 ) ;
V_11 = V_59 -> V_211 ;
V_226 = V_11 -> V_117 ;
error = F_99 ( V_57 , V_59 , & V_226 , V_188 ) ;
if ( error )
return error ;
if ( F_100 ( V_226 == 0 ) ) {
F_101 ( L_1 , V_233 ,
V_11 ) ;
return F_76 ( V_41 ) ;
}
V_228 = ( T_2 ) V_226 - V_11 -> V_212 ;
error = F_20 ( V_57 , V_59 , V_228 , - 1 , & V_222 , V_188 ) ;
if ( error )
return error ;
memcpy ( V_221 -> V_16 , V_222 -> V_16 , V_11 -> V_234 ) ;
F_27 ( V_57 , V_221 , 0 , V_11 -> V_234 - 1 ) ;
V_215 = V_221 -> V_16 ;
if ( V_215 -> V_25 == F_42 ( V_53 ) ||
V_215 -> V_25 == F_42 ( V_54 ) ) {
struct V_104 V_105 ;
struct V_106 * V_107 ;
V_219 = ( V_108 * ) V_215 ;
V_59 -> V_76 -> V_109 ( & V_105 , V_219 ) ;
V_107 = V_59 -> V_76 -> V_110 ( V_219 ) ;
V_232 = 0 ;
V_225 = F_38 ( V_107 [ V_105 . V_35 - 1 ] . V_115 ) ;
} else {
struct V_17 V_235 ;
V_218 = ( V_149 * ) V_215 ;
V_59 -> V_76 -> V_21 ( & V_235 , V_218 ) ;
V_98 = V_59 -> V_76 -> V_103 ( V_218 ) ;
V_232 = V_235 . V_33 ;
V_225 = F_38 ( V_98 [ V_235 . V_35 - 1 ] . V_115 ) ;
}
V_223 = V_224 = NULL ;
if ( ( V_229 = F_38 ( V_215 -> V_93 ) ) ) {
error = F_20 ( V_57 , V_59 , V_229 , - 1 , & V_223 , V_188 ) ;
if ( error )
goto V_236;
V_216 = V_223 -> V_16 ;
if ( F_100 (
F_38 ( V_216 -> V_92 ) != V_228 ||
V_216 -> V_25 != V_215 -> V_25 ) ) {
F_101 ( L_2 ,
V_233 , V_11 ) ;
error = F_76 ( V_41 ) ;
goto V_236;
}
V_216 -> V_92 = F_39 ( V_227 ) ;
F_27 ( V_57 , V_223 ,
F_28 ( V_216 , & V_216 -> V_92 ,
sizeof( V_216 -> V_92 ) ) ) ;
V_223 = NULL ;
}
if ( ( V_229 = F_38 ( V_215 -> V_92 ) ) ) {
error = F_20 ( V_57 , V_59 , V_229 , - 1 , & V_223 , V_188 ) ;
if ( error )
goto V_236;
V_216 = V_223 -> V_16 ;
if ( F_100 (
F_38 ( V_216 -> V_93 ) != V_228 ||
V_216 -> V_25 != V_215 -> V_25 ) ) {
F_101 ( L_3 ,
V_233 , V_11 ) ;
error = F_76 ( V_41 ) ;
goto V_236;
}
V_216 -> V_93 = F_39 ( V_227 ) ;
F_27 ( V_57 , V_223 ,
F_28 ( V_216 , & V_216 -> V_93 ,
sizeof( V_216 -> V_93 ) ) ) ;
V_223 = NULL ;
}
V_230 = V_11 -> V_114 ;
V_33 = - 1 ;
for (; ; ) {
error = F_20 ( V_57 , V_59 , V_230 , - 1 , & V_224 , V_188 ) ;
if ( error )
goto V_236;
V_217 = V_224 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_220 , V_217 ) ;
if ( V_33 >= 0 && V_33 != V_220 . V_33 + 1 ) {
F_101 ( L_4 ,
V_233 , V_11 ) ;
error = F_76 ( V_41 ) ;
goto V_236;
}
V_33 = V_220 . V_33 ;
V_98 = V_59 -> V_76 -> V_103 ( V_217 ) ;
for ( V_231 = 0 ;
V_231 < V_220 . V_35 &&
F_38 ( V_98 [ V_231 ] . V_115 ) < V_225 ;
V_231 ++ )
continue;
if ( V_231 == V_220 . V_35 ) {
F_101 ( L_5 ,
V_233 , V_11 ) ;
error = F_76 ( V_41 ) ;
goto V_236;
}
V_230 = F_38 ( V_98 [ V_231 ] . V_116 ) ;
if ( V_33 == V_232 + 1 )
break;
F_66 ( V_57 , V_224 ) ;
V_224 = NULL ;
}
for (; ; ) {
for (;
V_231 < V_220 . V_35 &&
F_38 ( V_98 [ V_231 ] . V_116 ) != V_228 ;
V_231 ++ )
continue;
if ( V_231 < V_220 . V_35 )
break;
V_230 = V_220 . V_92 ;
F_66 ( V_57 , V_224 ) ;
V_224 = NULL ;
if ( F_100 ( V_230 == 0 ) ) {
F_101 ( L_6 ,
V_233 , V_11 ) ;
error = F_76 ( V_41 ) ;
goto V_236;
}
error = F_20 ( V_57 , V_59 , V_230 , - 1 , & V_224 , V_188 ) ;
if ( error )
goto V_236;
V_217 = V_224 -> V_16 ;
V_59 -> V_76 -> V_21 ( & V_220 , V_217 ) ;
if ( V_220 . V_33 != V_33 ) {
F_101 ( L_7 ,
V_233 , V_11 ) ;
error = F_76 ( V_41 ) ;
goto V_236;
}
V_98 = V_59 -> V_76 -> V_103 ( V_217 ) ;
V_231 = 0 ;
}
V_98 [ V_231 ] . V_116 = F_39 ( V_227 ) ;
F_27 ( V_57 , V_224 ,
F_28 ( V_217 , & V_98 [ V_231 ] . V_116 ,
sizeof( V_98 [ V_231 ] . V_116 ) ) ) ;
* V_213 = V_228 ;
* V_214 = V_222 ;
return 0 ;
V_236:
if ( V_224 )
F_66 ( V_57 , V_224 ) ;
if ( V_223 )
F_66 ( V_57 , V_223 ) ;
F_66 ( V_57 , V_222 ) ;
return error ;
}
int
F_60 (
T_10 * args ,
T_2 V_227 ,
struct V_9 * V_221 )
{
T_11 * V_59 ;
int V_236 , error , V_188 , V_35 ;
T_12 * V_57 ;
T_13 * V_11 ;
F_102 ( args ) ;
V_59 = args -> V_59 ;
V_188 = args -> V_70 ;
V_57 = args -> V_72 ;
V_11 = V_59 -> V_211 ;
if ( V_188 == V_113 )
V_35 = V_11 -> V_212 ;
else
V_35 = 1 ;
for (; ; ) {
error = F_103 ( V_57 , V_59 , V_227 , V_35 ,
F_92 ( V_188 ) | V_199 ,
0 , args -> V_198 , args -> V_202 , & V_236 ) ;
if ( error == V_87 ) {
if ( V_188 != V_113 )
break;
error = F_97 ( args , & V_227 ,
& V_221 ) ;
if ( error )
break;
} else {
break;
}
}
F_104 ( V_57 , V_221 ) ;
return error ;
}
STATIC int
F_105 (
int V_195 ,
T_14 * V_194 ,
T_2 V_60 ,
int V_35 )
{
int V_4 ;
T_8 V_237 ;
for ( V_4 = 0 , V_237 = V_60 ; V_4 < V_195 ; V_4 ++ ) {
if ( V_194 [ V_4 ] . V_238 == V_239 ||
V_194 [ V_4 ] . V_238 == V_240 ) {
return 0 ;
}
if ( V_237 != V_194 [ V_4 ] . V_208 ) {
return 0 ;
}
V_237 += V_194 [ V_4 ] . V_209 ;
}
return V_237 == V_60 + V_35 ;
}
static int
F_106 (
struct V_10 * V_11 ,
struct V_241 * * V_194 ,
int * V_242 ,
struct V_192 * V_243 ,
int V_244 )
{
struct V_241 * V_193 ;
int V_4 ;
ASSERT ( * V_242 == 1 ) ;
ASSERT ( V_244 >= 1 ) ;
if ( V_244 > 1 ) {
V_193 = F_107 ( V_244 * sizeof( struct V_241 ) ,
V_205 | V_2 ) ;
if ( ! V_193 )
return V_245 ;
* V_194 = V_193 ;
}
* V_242 = V_244 ;
V_193 = * V_194 ;
for ( V_4 = 0 ; V_4 < * V_242 ; V_4 ++ ) {
ASSERT ( V_243 [ V_4 ] . V_238 != V_240 &&
V_243 [ V_4 ] . V_238 != V_239 ) ;
V_193 [ V_4 ] . V_246 = F_108 ( V_11 , V_243 [ V_4 ] . V_238 ) ;
V_193 [ V_4 ] . V_247 = F_109 ( V_11 , V_243 [ V_4 ] . V_209 ) ;
}
return 0 ;
}
static int
F_110 (
struct V_56 * V_72 ,
struct V_58 * V_59 ,
T_2 V_60 ,
T_3 V_61 ,
int V_70 ,
struct V_241 * * V_193 ,
int * V_242 )
{
struct V_10 * V_11 = V_59 -> V_211 ;
int V_248 ;
int error = 0 ;
struct V_192 V_249 ;
struct V_192 * V_243 = & V_249 ;
int V_244 ;
ASSERT ( V_193 && * V_193 ) ;
ASSERT ( * V_242 == 1 ) ;
V_248 = ( V_70 == V_113 ) ? V_11 -> V_212 : 1 ;
if ( V_61 == - 1 || V_61 == - 2 ) {
if ( V_248 != 1 )
V_243 = F_107 ( sizeof( V_249 ) * V_248 ,
V_205 | V_2 ) ;
V_244 = V_248 ;
error = F_111 ( V_59 , ( T_8 ) V_60 , V_248 , V_243 ,
& V_244 , F_92 ( V_70 ) ) ;
if ( error )
goto V_250;
} else {
V_243 -> V_238 = F_112 ( V_11 , V_61 ) ;
V_243 -> V_208 = ( T_8 ) V_60 ;
V_243 -> V_209 = V_248 ;
V_243 -> V_251 = 0 ;
V_244 = 1 ;
}
if ( ! F_105 ( V_244 , V_243 , V_60 , V_248 ) ) {
error = V_61 == - 2 ? - 1 : F_76 ( V_41 ) ;
if ( F_100 ( error == V_41 ) ) {
if ( V_252 >= V_233 ) {
int V_4 ;
F_113 ( V_11 , L_8 ,
V_253 , ( long long ) V_60 ,
( long long ) V_59 -> V_75 ) ;
for ( V_4 = 0 ; V_4 < * V_242 ; V_4 ++ ) {
F_113 ( V_11 ,
L_9 ,
V_4 ,
( long long ) V_243 [ V_4 ] . V_208 ,
( long long ) V_243 [ V_4 ] . V_238 ,
( long long ) V_243 [ V_4 ] . V_209 ,
V_243 [ V_4 ] . V_251 ) ;
}
}
F_101 ( L_10 ,
V_233 , V_11 ) ;
}
goto V_250;
}
error = F_106 ( V_11 , V_193 , V_242 , V_243 , V_244 ) ;
V_250:
if ( V_243 != & V_249 )
F_95 ( V_243 ) ;
return error ;
}
int
F_25 (
struct V_56 * V_72 ,
struct V_58 * V_59 ,
T_2 V_60 ,
T_3 V_61 ,
struct V_9 * * V_62 ,
int V_70 )
{
struct V_9 * V_8 ;
struct V_241 V_193 ;
struct V_241 * V_194 ;
int V_195 ;
int error ;
* V_62 = NULL ;
V_194 = & V_193 ;
V_195 = 1 ;
error = F_110 ( V_72 , V_59 , V_60 , V_61 , V_70 ,
& V_194 , & V_195 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_254;
}
V_8 = F_114 ( V_72 , V_59 -> V_211 -> V_255 ,
V_194 , V_195 , 0 ) ;
error = V_8 ? V_8 -> V_256 : F_76 ( V_257 ) ;
if ( error ) {
F_66 ( V_72 , V_8 ) ;
goto V_254;
}
* V_62 = V_8 ;
V_254:
if ( V_194 != & V_193 )
F_95 ( V_194 ) ;
return error ;
}
int
F_21 (
struct V_56 * V_72 ,
struct V_58 * V_59 ,
T_2 V_60 ,
T_3 V_61 ,
struct V_9 * * V_62 ,
int V_70 ,
const struct V_258 * V_20 )
{
struct V_9 * V_8 ;
struct V_241 V_193 ;
struct V_241 * V_194 ;
int V_195 ;
int error ;
* V_62 = NULL ;
V_194 = & V_193 ;
V_195 = 1 ;
error = F_110 ( V_72 , V_59 , V_60 , V_61 , V_70 ,
& V_194 , & V_195 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_254;
}
error = F_115 ( V_59 -> V_211 , V_72 ,
V_59 -> V_211 -> V_255 ,
V_194 , V_195 , 0 , & V_8 , V_20 ) ;
if ( error )
goto V_254;
if ( V_70 == V_123 )
F_116 ( V_8 , V_259 ) ;
else
F_116 ( V_8 , V_260 ) ;
{
T_15 * V_15 = V_8 -> V_16 ;
T_16 * free = V_8 -> V_16 ;
T_17 * V_27 = V_8 -> V_16 ;
V_137 V_25 , V_261 ;
struct V_10 * V_11 = V_59 -> V_211 ;
V_25 = F_18 ( V_27 -> V_25 ) ;
V_261 = F_38 ( V_15 -> V_25 ) ;
if ( F_100 (
F_117 ( ( V_25 != V_32 ) &&
( V_25 != V_26 ) &&
( V_25 != V_48 ) &&
( V_25 != V_49 ) &&
( V_25 != V_262 ) &&
( V_25 != V_263 ) &&
( V_25 != V_53 ) &&
( V_25 != V_54 ) &&
( V_261 != V_264 ) &&
( V_261 != V_265 ) &&
( V_261 != V_266 ) &&
( V_261 != V_267 ) &&
( free -> V_15 . V_25 !=
F_39 ( V_268 ) ) &&
( free -> V_15 . V_25 !=
F_39 ( V_269 ) ) ,
V_11 , V_270 ,
V_271 ) ) ) {
F_118 ( V_8 , V_272 ) ;
F_119 ( L_11 ,
V_233 , V_11 , V_27 ) ;
error = F_76 ( V_41 ) ;
F_66 ( V_72 , V_8 ) ;
goto V_254;
}
}
* V_62 = V_8 ;
V_254:
if ( V_194 != & V_193 )
F_95 ( V_194 ) ;
return error ;
}
T_3
F_120 (
struct V_56 * V_72 ,
struct V_58 * V_59 ,
T_2 V_60 ,
T_3 V_61 ,
int V_70 ,
const struct V_258 * V_20 )
{
struct V_241 V_193 ;
struct V_241 * V_194 ;
int V_195 ;
int error ;
V_194 = & V_193 ;
V_195 = 1 ;
error = F_110 ( V_72 , V_59 , V_60 , V_61 , V_70 ,
& V_194 , & V_195 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_254;
}
V_61 = V_194 [ 0 ] . V_246 ;
F_121 ( V_59 -> V_211 -> V_255 , V_194 , V_195 , V_20 ) ;
V_254:
if ( V_194 != & V_193 )
F_95 ( V_194 ) ;
if ( error )
return - 1 ;
return V_61 ;
}
