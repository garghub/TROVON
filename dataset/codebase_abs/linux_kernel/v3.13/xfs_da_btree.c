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
F_13 ( V_41 , V_42 , V_11 , V_8 -> V_16 ) ;
F_14 ( V_8 , V_43 ) ;
return;
}
if ( ! F_9 ( & V_11 -> V_22 ) )
return;
if ( V_39 )
V_24 -> V_27 . V_44 = F_15 ( V_39 -> V_45 . V_46 ) ;
F_16 ( V_8 -> V_16 , F_17 ( V_8 -> V_47 ) , V_48 ) ;
}
static void
F_18 (
struct V_9 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 -> V_13 ;
struct V_49 * V_27 = V_8 -> V_16 ;
switch ( F_19 ( V_27 -> V_25 ) ) {
case V_26 :
if ( ! F_20 ( V_8 -> V_16 , F_17 ( V_8 -> V_47 ) ,
V_48 ) )
break;
case V_32 :
if ( ! F_7 ( V_8 ) )
break;
return;
case V_50 :
case V_51 :
V_8 -> V_52 = & V_53 ;
V_8 -> V_52 -> V_54 ( V_8 ) ;
return;
case V_55 :
case V_56 :
V_8 -> V_52 = & V_57 ;
V_8 -> V_52 -> V_54 ( V_8 ) ;
return;
default:
break;
}
F_13 ( V_41 , V_42 , V_11 , V_8 -> V_16 ) ;
F_14 ( V_8 , V_43 ) ;
}
int
F_21 (
struct V_58 * V_59 ,
struct V_60 * V_61 ,
T_2 V_62 ,
T_3 V_63 ,
struct V_9 * * V_64 ,
int V_65 )
{
int V_66 ;
V_66 = F_22 ( V_59 , V_61 , V_62 , V_63 , V_64 ,
V_65 , & V_67 ) ;
if ( ! V_66 && V_59 ) {
struct V_49 * V_27 = ( * V_64 ) -> V_16 ;
int type ;
switch ( F_19 ( V_27 -> V_25 ) ) {
case V_32 :
case V_26 :
type = V_68 ;
break;
case V_50 :
case V_51 :
type = V_69 ;
break;
case V_55 :
case V_56 :
type = V_70 ;
break;
default:
type = 0 ;
ASSERT ( 0 ) ;
break;
}
F_23 ( V_59 , * V_64 , type ) ;
}
return V_66 ;
}
int
F_24 (
struct V_71 * args ,
T_2 V_30 ,
int V_33 ,
struct V_9 * * V_64 ,
int V_72 )
{
struct V_14 * V_73 ;
struct V_58 * V_59 = args -> V_74 ;
struct V_10 * V_11 = V_59 -> V_75 ;
struct V_17 V_18 = { 0 } ;
struct V_9 * V_8 ;
int error ;
struct V_60 * V_61 = args -> V_61 ;
F_25 ( args ) ;
ASSERT ( V_33 <= V_34 ) ;
error = F_26 ( V_59 , V_61 , V_30 , - 1 , & V_8 , V_72 ) ;
if ( error )
return ( error ) ;
V_8 -> V_52 = & V_67 ;
F_23 ( V_59 , V_8 , V_68 ) ;
V_73 = V_8 -> V_16 ;
if ( F_9 ( & V_11 -> V_22 ) ) {
struct V_23 * V_24 = V_8 -> V_16 ;
V_18 . V_25 = V_26 ;
V_24 -> V_27 . V_30 = F_15 ( V_8 -> V_31 ) ;
V_24 -> V_27 . V_76 = F_15 ( args -> V_61 -> V_77 ) ;
F_27 ( & V_24 -> V_27 . V_28 , & V_11 -> V_22 . V_29 ) ;
} else {
V_18 . V_25 = V_32 ;
}
V_18 . V_33 = V_33 ;
V_61 -> V_78 -> V_79 ( V_73 , & V_18 ) ;
F_28 ( V_59 , V_8 ,
F_29 ( V_73 , & V_73 -> V_15 , V_61 -> V_78 -> V_80 ) ) ;
* V_64 = V_8 ;
return ( 0 ) ;
}
int
F_30 (
struct V_81 * V_3 )
{
struct V_82 * V_83 ;
struct V_82 * V_84 ;
struct V_82 * V_85 ;
struct V_14 * V_73 ;
struct V_9 * V_8 ;
int V_86 ;
int V_87 = 0 ;
int error ;
int V_4 ;
F_31 ( V_3 -> args ) ;
V_86 = V_3 -> V_88 . V_6 - 1 ;
ASSERT ( ( V_86 >= 0 ) && ( V_86 < V_34 ) ) ;
ASSERT ( V_3 -> V_88 . V_7 [ V_86 ] . V_25 == V_50 ||
V_3 -> V_88 . V_7 [ V_86 ] . V_25 == V_55 ) ;
V_85 = & V_3 -> V_88 . V_7 [ V_86 ] ;
for ( V_4 = V_86 ; ( V_4 >= 0 ) && V_85 ; V_3 -> V_88 . V_6 -- , V_4 -- ) {
V_83 = & V_3 -> V_88 . V_7 [ V_4 ] ;
V_84 = & V_3 -> V_5 . V_7 [ V_4 ] ;
switch ( V_83 -> V_25 ) {
case V_50 :
error = F_32 ( V_3 , V_83 , V_84 ) ;
if ( ( error != 0 ) && ( error != V_89 ) ) {
return ( error ) ;
}
if ( ! error ) {
V_85 = V_84 ;
break;
}
V_3 -> V_90 = 1 ;
if ( V_3 -> V_91 ) {
V_3 -> V_92 = 0 ;
F_33 ( V_3 -> args ) ;
error = F_32 ( V_3 , V_83 ,
& V_3 -> V_93 ) ;
} else {
V_3 -> V_92 = 1 ;
F_34 ( V_3 -> args ) ;
error = F_32 ( V_3 , V_84 ,
& V_3 -> V_93 ) ;
}
if ( error )
return ( error ) ;
V_85 = V_84 ;
break;
case V_55 :
error = F_35 ( V_3 , V_83 , V_84 ) ;
if ( error )
return error ;
V_85 = V_84 ;
break;
case V_32 :
error = F_36 ( V_3 , V_83 , V_84 , V_85 ,
V_86 - V_4 , & V_87 ) ;
V_85 -> V_8 = NULL ;
if ( error )
return ( error ) ;
if ( V_87 )
V_85 = V_84 ;
else
V_85 = NULL ;
break;
}
F_37 ( V_3 , & V_3 -> V_88 ) ;
}
if ( ! V_85 )
return ( 0 ) ;
ASSERT ( V_3 -> V_88 . V_6 == 0 ) ;
V_83 = & V_3 -> V_88 . V_7 [ 0 ] ;
error = F_38 ( V_3 , V_83 , V_85 ) ;
if ( error ) {
V_85 -> V_8 = NULL ;
return ( error ) ;
}
V_73 = V_83 -> V_8 -> V_16 ;
if ( V_73 -> V_15 . V_27 . V_94 ) {
if ( F_39 ( V_73 -> V_15 . V_27 . V_94 ) == V_85 -> V_30 ) {
V_8 = V_85 -> V_8 ;
} else {
ASSERT ( V_3 -> V_90 ) ;
V_8 = V_3 -> V_93 . V_8 ;
}
V_73 = V_8 -> V_16 ;
V_73 -> V_15 . V_27 . V_95 = F_40 ( V_83 -> V_30 ) ;
F_28 ( V_3 -> args -> V_74 , V_8 ,
F_29 ( V_73 , & V_73 -> V_15 . V_27 ,
sizeof( V_73 -> V_15 . V_27 ) ) ) ;
}
V_73 = V_83 -> V_8 -> V_16 ;
if ( V_73 -> V_15 . V_27 . V_95 ) {
if ( F_39 ( V_73 -> V_15 . V_27 . V_95 ) == V_85 -> V_30 ) {
V_8 = V_85 -> V_8 ;
} else {
ASSERT ( V_3 -> V_90 ) ;
V_8 = V_3 -> V_93 . V_8 ;
}
V_73 = V_8 -> V_16 ;
V_73 -> V_15 . V_27 . V_94 = F_40 ( V_83 -> V_30 ) ;
F_28 ( V_3 -> args -> V_74 , V_8 ,
F_29 ( V_73 , & V_73 -> V_15 . V_27 ,
sizeof( V_73 -> V_15 . V_27 ) ) ) ;
}
V_85 -> V_8 = NULL ;
return ( 0 ) ;
}
STATIC int
F_38 (
struct V_81 * V_3 ,
struct V_82 * V_96 ,
struct V_82 * V_97 )
{
struct V_14 * V_73 ;
struct V_14 * V_98 ;
struct V_99 * V_100 ;
struct V_17 V_101 ;
struct V_71 * args ;
struct V_9 * V_8 ;
struct V_60 * V_61 ;
struct V_58 * V_59 ;
struct V_10 * V_11 ;
struct V_102 * V_103 ;
T_2 V_30 ;
int V_33 ;
int error ;
int V_104 ;
F_41 ( V_3 -> args ) ;
args = V_3 -> args ;
error = F_42 ( args , & V_30 ) ;
if ( error )
return error ;
V_61 = args -> V_61 ;
V_59 = args -> V_74 ;
V_11 = V_3 -> V_11 ;
error = F_26 ( V_59 , V_61 , V_30 , - 1 , & V_8 , args -> V_72 ) ;
if ( error )
return error ;
V_73 = V_8 -> V_16 ;
V_98 = V_96 -> V_8 -> V_16 ;
if ( V_98 -> V_15 . V_27 . V_25 == F_43 ( V_32 ) ||
V_98 -> V_15 . V_27 . V_25 == F_43 ( V_26 ) ) {
struct V_17 V_101 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_98 ) ;
V_100 = V_61 -> V_78 -> V_105 ( V_98 ) ;
V_104 = ( int ) ( ( char * ) & V_100 [ V_101 . V_35 ] - ( char * ) V_98 ) ;
V_33 = V_101 . V_33 ;
F_23 ( V_59 , V_8 , V_68 ) ;
} else {
struct V_106 V_107 ;
struct V_108 * V_109 ;
V_103 = ( V_110 * ) V_98 ;
V_61 -> V_78 -> V_111 ( & V_107 , V_103 ) ;
V_109 = V_61 -> V_78 -> V_112 ( V_103 ) ;
ASSERT ( V_107 . V_25 == V_55 ||
V_107 . V_25 == V_56 ) ;
V_104 = ( int ) ( ( char * ) & V_109 [ V_107 . V_35 ] - ( char * ) V_103 ) ;
V_33 = 0 ;
F_23 ( V_59 , V_8 , V_70 ) ;
}
memcpy ( V_73 , V_98 , V_104 ) ;
if ( V_98 -> V_15 . V_27 . V_25 == F_43 ( V_26 ) ||
V_98 -> V_15 . V_27 . V_25 == F_43 ( V_56 ) ) {
struct V_113 * V_114 = (struct V_113 * ) V_73 ;
V_114 -> V_15 . V_27 . V_30 = F_15 ( V_8 -> V_31 ) ;
}
F_28 ( V_59 , V_8 , 0 , V_104 - 1 ) ;
V_8 -> V_52 = V_96 -> V_8 -> V_52 ;
F_44 ( V_8 , V_96 -> V_8 ) ;
V_96 -> V_8 = V_8 ;
V_96 -> V_30 = V_30 ;
error = F_24 ( args ,
( args -> V_72 == V_115 ) ? V_11 -> V_116 : 0 ,
V_33 + 1 , & V_8 , args -> V_72 ) ;
if ( error )
return error ;
V_73 = V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_73 ) ;
V_100 = V_61 -> V_78 -> V_105 ( V_73 ) ;
V_100 [ 0 ] . V_117 = F_40 ( V_96 -> V_117 ) ;
V_100 [ 0 ] . V_118 = F_40 ( V_96 -> V_30 ) ;
V_100 [ 1 ] . V_117 = F_40 ( V_97 -> V_117 ) ;
V_100 [ 1 ] . V_118 = F_40 ( V_97 -> V_30 ) ;
V_101 . V_35 = 2 ;
V_61 -> V_78 -> V_79 ( V_73 , & V_101 ) ;
#ifdef F_5
if ( V_98 -> V_15 . V_27 . V_25 == F_43 ( V_55 ) ||
V_98 -> V_15 . V_27 . V_25 == F_43 ( V_56 ) ) {
ASSERT ( V_96 -> V_30 >= V_11 -> V_116 &&
V_96 -> V_30 < V_11 -> V_119 ) ;
ASSERT ( V_97 -> V_30 >= V_11 -> V_116 &&
V_97 -> V_30 < V_11 -> V_119 ) ;
}
#endif
F_28 ( V_59 , V_8 ,
F_29 ( V_73 , V_100 , sizeof( V_120 ) * 2 ) ) ;
return 0 ;
}
STATIC int
F_36 (
struct V_81 * V_3 ,
struct V_82 * V_83 ,
struct V_82 * V_84 ,
struct V_82 * V_85 ,
int V_121 ,
int * V_122 )
{
struct V_14 * V_73 ;
struct V_17 V_101 ;
T_2 V_30 ;
int V_123 ;
int error ;
int V_124 ;
struct V_60 * V_61 = V_3 -> args -> V_61 ;
F_45 ( V_3 -> args ) ;
V_73 = V_83 -> V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_73 ) ;
V_124 = V_3 -> V_90 && V_3 -> args -> V_72 == V_125 ;
V_123 = 1 + V_124 ;
if ( V_101 . V_35 + V_123 > V_3 -> V_126 ) {
error = F_42 ( V_3 -> args , & V_30 ) ;
if ( error )
return ( error ) ;
error = F_24 ( V_3 -> args , V_30 , V_121 ,
& V_84 -> V_8 , V_3 -> args -> V_72 ) ;
if ( error )
return ( error ) ;
V_84 -> V_30 = V_30 ;
V_84 -> V_25 = V_32 ;
F_46 ( V_3 , V_83 , V_84 ) ;
error = F_47 ( V_3 , V_83 , V_84 ) ;
if ( error )
return ( error ) ;
* V_122 = 1 ;
} else {
* V_122 = 0 ;
}
V_73 = V_83 -> V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_73 ) ;
if ( V_83 -> V_127 <= V_101 . V_35 ) {
V_83 -> V_127 ++ ;
F_48 ( V_3 , V_83 , V_85 ) ;
if ( V_124 ) {
if ( V_3 -> V_92 )
V_83 -> V_127 ++ ;
F_48 ( V_3 , V_83 , & V_3 -> V_93 ) ;
V_3 -> V_90 = 0 ;
}
} else {
V_84 -> V_127 ++ ;
F_48 ( V_3 , V_84 , V_85 ) ;
if ( V_124 ) {
if ( V_3 -> V_92 )
V_84 -> V_127 ++ ;
F_48 ( V_3 , V_84 , & V_3 -> V_93 ) ;
V_3 -> V_90 = 0 ;
}
}
return ( 0 ) ;
}
STATIC void
F_46 (
struct V_81 * V_3 ,
struct V_82 * V_96 ,
struct V_82 * V_97 )
{
struct V_14 * V_128 ;
struct V_14 * V_129 ;
struct V_14 * V_130 ;
struct V_99 * V_131 ;
struct V_99 * V_132 ;
struct V_99 * V_133 ;
struct V_99 * V_134 ;
struct V_17 V_135 ;
struct V_17 V_136 ;
struct V_58 * V_59 ;
int V_35 ;
int V_137 ;
int V_138 = 0 ;
struct V_60 * V_61 = V_3 -> args -> V_61 ;
F_49 ( V_3 -> args ) ;
V_128 = V_96 -> V_8 -> V_16 ;
V_129 = V_97 -> V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_135 , V_128 ) ;
V_61 -> V_78 -> V_21 ( & V_136 , V_129 ) ;
V_131 = V_61 -> V_78 -> V_105 ( V_128 ) ;
V_132 = V_61 -> V_78 -> V_105 ( V_129 ) ;
if ( V_135 . V_35 > 0 && V_136 . V_35 > 0 &&
( ( F_39 ( V_132 [ 0 ] . V_117 ) < F_39 ( V_131 [ 0 ] . V_117 ) ) ||
( F_39 ( V_132 [ V_136 . V_35 - 1 ] . V_117 ) <
F_39 ( V_131 [ V_135 . V_35 - 1 ] . V_117 ) ) ) ) {
V_130 = V_128 ;
V_128 = V_129 ;
V_129 = V_130 ;
V_61 -> V_78 -> V_21 ( & V_135 , V_128 ) ;
V_61 -> V_78 -> V_21 ( & V_136 , V_129 ) ;
V_131 = V_61 -> V_78 -> V_105 ( V_128 ) ;
V_132 = V_61 -> V_78 -> V_105 ( V_129 ) ;
V_138 = 1 ;
}
V_35 = ( V_135 . V_35 - V_136 . V_35 ) / 2 ;
if ( V_35 == 0 )
return;
V_59 = V_3 -> args -> V_74 ;
if ( V_35 > 0 ) {
V_137 = V_136 . V_35 ;
if ( V_137 > 0 ) {
V_137 *= ( V_139 ) sizeof( V_120 ) ;
V_133 = & V_132 [ 0 ] ;
V_134 = & V_132 [ V_35 ] ;
memmove ( V_134 , V_133 , V_137 ) ;
}
V_136 . V_35 += V_35 ;
V_137 = V_35 * ( V_139 ) sizeof( V_120 ) ;
V_133 = & V_131 [ V_135 . V_35 - V_35 ] ;
V_134 = & V_132 [ 0 ] ;
memcpy ( V_134 , V_133 , V_137 ) ;
V_135 . V_35 -= V_35 ;
} else {
V_35 = - V_35 ;
V_137 = V_35 * ( V_139 ) sizeof( V_120 ) ;
V_133 = & V_132 [ 0 ] ;
V_134 = & V_131 [ V_135 . V_35 ] ;
memcpy ( V_134 , V_133 , V_137 ) ;
V_135 . V_35 += V_35 ;
F_28 ( V_59 , V_96 -> V_8 ,
F_29 ( V_128 , V_134 , V_137 ) ) ;
V_137 = V_136 . V_35 - V_35 ;
V_137 *= ( V_139 ) sizeof( V_120 ) ;
V_133 = & V_132 [ V_35 ] ;
V_134 = & V_132 [ 0 ] ;
memmove ( V_134 , V_133 , V_137 ) ;
V_136 . V_35 -= V_35 ;
}
V_61 -> V_78 -> V_79 ( V_128 , & V_135 ) ;
F_28 ( V_59 , V_96 -> V_8 ,
F_29 ( V_128 , & V_128 -> V_15 , V_61 -> V_78 -> V_80 ) ) ;
V_61 -> V_78 -> V_79 ( V_129 , & V_136 ) ;
F_28 ( V_59 , V_97 -> V_8 ,
F_29 ( V_129 , & V_129 -> V_15 ,
V_61 -> V_78 -> V_80 +
( sizeof( V_132 [ 0 ] ) * V_136 . V_35 ) ) ) ;
if ( V_138 ) {
V_128 = V_96 -> V_8 -> V_16 ;
V_129 = V_97 -> V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_135 , V_128 ) ;
V_61 -> V_78 -> V_21 ( & V_136 , V_129 ) ;
V_131 = V_61 -> V_78 -> V_105 ( V_128 ) ;
V_132 = V_61 -> V_78 -> V_105 ( V_129 ) ;
}
V_96 -> V_117 = F_39 ( V_131 [ V_135 . V_35 - 1 ] . V_117 ) ;
V_97 -> V_117 = F_39 ( V_132 [ V_136 . V_35 - 1 ] . V_117 ) ;
if ( V_96 -> V_127 >= V_135 . V_35 ) {
V_97 -> V_127 = V_96 -> V_127 - V_135 . V_35 ;
V_96 -> V_127 = V_135 . V_35 + 1 ;
}
}
STATIC void
F_48 (
struct V_81 * V_3 ,
struct V_82 * V_83 ,
struct V_82 * V_84 )
{
struct V_14 * V_73 ;
struct V_17 V_101 ;
struct V_99 * V_100 ;
int V_137 ;
struct V_60 * V_61 = V_3 -> args -> V_61 ;
F_50 ( V_3 -> args ) ;
V_73 = V_83 -> V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_73 ) ;
V_100 = V_61 -> V_78 -> V_105 ( V_73 ) ;
ASSERT ( V_83 -> V_127 >= 0 && V_83 -> V_127 <= V_101 . V_35 ) ;
ASSERT ( V_84 -> V_30 != 0 ) ;
if ( V_3 -> args -> V_72 == V_115 )
ASSERT ( V_84 -> V_30 >= V_3 -> V_11 -> V_116 &&
V_84 -> V_30 < V_3 -> V_11 -> V_119 ) ;
V_137 = 0 ;
if ( V_83 -> V_127 < V_101 . V_35 ) {
V_137 = ( V_101 . V_35 - V_83 -> V_127 ) * ( V_139 ) sizeof( * V_100 ) ;
memmove ( & V_100 [ V_83 -> V_127 + 1 ] , & V_100 [ V_83 -> V_127 ] , V_137 ) ;
}
V_100 [ V_83 -> V_127 ] . V_117 = F_40 ( V_84 -> V_117 ) ;
V_100 [ V_83 -> V_127 ] . V_118 = F_40 ( V_84 -> V_30 ) ;
F_28 ( V_3 -> args -> V_74 , V_83 -> V_8 ,
F_29 ( V_73 , & V_100 [ V_83 -> V_127 ] ,
V_137 + sizeof( * V_100 ) ) ) ;
V_101 . V_35 += 1 ;
V_61 -> V_78 -> V_79 ( V_73 , & V_101 ) ;
F_28 ( V_3 -> args -> V_74 , V_83 -> V_8 ,
F_29 ( V_73 , & V_73 -> V_15 , V_61 -> V_78 -> V_80 ) ) ;
V_83 -> V_117 = F_39 ( V_100 [ V_101 . V_35 - 1 ] . V_117 ) ;
}
int
F_51 (
struct V_81 * V_3 )
{
struct V_82 * V_140 ;
struct V_82 * V_141 ;
int V_87 = 0 ;
int error ;
F_52 ( V_3 -> args ) ;
V_140 = & V_3 -> V_88 . V_7 [ V_3 -> V_88 . V_6 - 1 ] ;
V_141 = & V_3 -> V_5 . V_7 [ V_3 -> V_88 . V_6 - 1 ] ;
ASSERT ( V_3 -> V_88 . V_7 [ 0 ] . V_25 == V_32 ) ;
ASSERT ( V_140 -> V_25 == V_50 ||
V_140 -> V_25 == V_55 ) ;
for ( ; V_3 -> V_88 . V_6 >= 2 ; V_140 -- , V_141 -- ,
V_3 -> V_88 . V_6 -- ) {
switch ( V_140 -> V_25 ) {
case V_50 :
error = F_53 ( V_3 , & V_87 ) ;
if ( error )
return ( error ) ;
if ( V_87 == 0 )
return ( 0 ) ;
F_54 ( V_3 , V_140 , V_141 ) ;
break;
case V_55 :
error = F_55 ( V_3 , & V_87 ) ;
if ( error )
return error ;
if ( V_87 == 0 )
return 0 ;
F_56 ( V_3 , V_140 , V_141 ) ;
break;
case V_32 :
F_57 ( V_3 , V_140 ) ;
F_37 ( V_3 , & V_3 -> V_88 ) ;
error = F_58 ( V_3 , & V_87 ) ;
if ( error )
return ( error ) ;
if ( V_87 == 0 )
return 0 ;
F_59 ( V_3 , V_140 , V_141 ) ;
break;
}
F_37 ( V_3 , & V_3 -> V_5 ) ;
error = F_60 ( V_3 , V_140 , V_141 ) ;
F_3 ( V_3 ) ;
if ( error )
return ( error ) ;
error = F_61 ( V_3 -> args , V_140 -> V_30 ,
V_140 -> V_8 ) ;
V_140 -> V_8 = NULL ;
if ( error )
return ( error ) ;
}
F_57 ( V_3 , V_140 ) ;
F_37 ( V_3 , & V_3 -> V_88 ) ;
error = F_62 ( V_3 , & V_3 -> V_88 . V_7 [ 0 ] ) ;
return ( error ) ;
}
static void
F_63 ( struct V_49 * V_142 , T_4 V_33 )
{
T_5 V_25 = V_142 -> V_25 ;
if ( V_33 == 1 ) {
ASSERT ( V_25 == F_43 ( V_55 ) ||
V_25 == F_43 ( V_56 ) ||
V_25 == F_43 ( V_50 ) ||
V_25 == F_43 ( V_51 ) ) ;
} else {
ASSERT ( V_25 == F_43 ( V_32 ) ||
V_25 == F_43 ( V_26 ) ) ;
}
ASSERT ( ! V_142 -> V_94 ) ;
ASSERT ( ! V_142 -> V_95 ) ;
}
STATIC int
F_62 (
struct V_81 * V_3 ,
struct V_82 * V_143 )
{
struct V_14 * V_98 ;
struct V_71 * args ;
T_2 V_144 ;
struct V_9 * V_8 ;
struct V_17 V_145 ;
struct V_99 * V_100 ;
int error ;
struct V_60 * V_61 = V_3 -> args -> V_61 ;
F_64 ( V_3 -> args ) ;
ASSERT ( V_143 -> V_25 == V_32 ) ;
args = V_3 -> args ;
V_98 = V_143 -> V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_145 , V_98 ) ;
ASSERT ( V_145 . V_94 == 0 ) ;
ASSERT ( V_145 . V_95 == 0 ) ;
if ( V_145 . V_35 > 1 )
return 0 ;
V_100 = V_61 -> V_78 -> V_105 ( V_98 ) ;
V_144 = F_39 ( V_100 [ 0 ] . V_118 ) ;
ASSERT ( V_144 != 0 ) ;
error = F_21 ( args -> V_74 , V_61 , V_144 , - 1 , & V_8 ,
args -> V_72 ) ;
if ( error )
return error ;
F_63 ( V_8 -> V_16 , V_145 . V_33 ) ;
memcpy ( V_143 -> V_8 -> V_16 , V_8 -> V_16 , V_3 -> V_146 ) ;
V_143 -> V_8 -> V_52 = V_8 -> V_52 ;
F_44 ( V_143 -> V_8 , V_8 ) ;
if ( V_145 . V_25 == V_26 ) {
struct V_147 * V_148 = V_143 -> V_8 -> V_16 ;
V_148 -> V_30 = F_15 ( V_143 -> V_8 -> V_31 ) ;
}
F_28 ( args -> V_74 , V_143 -> V_8 , 0 , V_3 -> V_146 - 1 ) ;
error = F_61 ( args , V_144 , V_8 ) ;
return ( error ) ;
}
STATIC int
F_58 (
struct V_81 * V_3 ,
int * V_87 )
{
struct V_14 * V_73 ;
struct V_82 * V_7 ;
struct V_49 * V_27 ;
T_2 V_30 ;
struct V_9 * V_8 ;
struct V_17 V_101 ;
int V_35 ;
int V_149 ;
int error ;
int V_150 ;
int V_4 ;
struct V_60 * V_61 = V_3 -> args -> V_61 ;
F_65 ( V_3 -> args ) ;
V_7 = & V_3 -> V_88 . V_7 [ V_3 -> V_88 . V_6 - 1 ] ;
V_27 = V_7 -> V_8 -> V_16 ;
V_73 = ( V_151 * ) V_27 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_73 ) ;
if ( V_101 . V_35 > ( V_3 -> V_126 >> 1 ) ) {
* V_87 = 0 ;
return ( 0 ) ;
}
if ( V_101 . V_35 == 0 ) {
V_149 = ( V_27 -> V_94 != 0 ) ;
memcpy ( & V_3 -> V_5 , & V_3 -> V_88 , sizeof( V_3 -> V_88 ) ) ;
error = F_66 ( V_3 , & V_3 -> V_5 , V_149 ,
0 , & V_150 ) ;
if ( error )
return ( error ) ;
if ( V_150 ) {
* V_87 = 0 ;
} else {
* V_87 = 2 ;
}
return ( 0 ) ;
}
V_35 = V_3 -> V_126 ;
V_35 -= V_3 -> V_126 >> 2 ;
V_35 -= V_101 . V_35 ;
V_149 = V_101 . V_94 < V_101 . V_95 ;
for ( V_4 = 0 ; V_4 < 2 ; V_149 = ! V_149 , V_4 ++ ) {
struct V_17 V_152 ;
if ( V_149 )
V_30 = V_101 . V_94 ;
else
V_30 = V_101 . V_95 ;
if ( V_30 == 0 )
continue;
error = F_21 ( V_3 -> args -> V_74 , V_61 ,
V_30 , - 1 , & V_8 , V_3 -> args -> V_72 ) ;
if ( error )
return ( error ) ;
V_73 = V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_152 , V_73 ) ;
F_67 ( V_3 -> args -> V_74 , V_8 ) ;
if ( V_35 - V_152 . V_35 >= 0 )
break;
}
if ( V_4 >= 2 ) {
* V_87 = 0 ;
return 0 ;
}
memcpy ( & V_3 -> V_5 , & V_3 -> V_88 , sizeof( V_3 -> V_88 ) ) ;
if ( V_30 < V_7 -> V_30 ) {
error = F_66 ( V_3 , & V_3 -> V_5 , V_149 ,
0 , & V_150 ) ;
} else {
error = F_66 ( V_3 , & V_3 -> V_88 , V_149 ,
0 , & V_150 ) ;
}
if ( error )
return error ;
if ( V_150 ) {
* V_87 = 0 ;
return 0 ;
}
* V_87 = 1 ;
return 0 ;
}
STATIC V_139
F_68 (
struct V_60 * V_61 ,
struct V_9 * V_8 ,
int * V_35 )
{
struct V_14 * V_73 ;
struct V_99 * V_100 ;
struct V_17 V_101 ;
V_73 = V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_73 ) ;
if ( V_35 )
* V_35 = V_101 . V_35 ;
if ( ! V_101 . V_35 )
return 0 ;
V_100 = V_61 -> V_78 -> V_105 ( V_73 ) ;
return F_39 ( V_100 [ V_101 . V_35 - 1 ] . V_117 ) ;
}
void
F_37 (
struct V_81 * V_3 ,
struct V_153 * V_88 )
{
struct V_82 * V_7 ;
struct V_14 * V_73 ;
struct V_99 * V_100 ;
T_6 V_154 = 0 ;
int V_33 ;
int V_35 ;
struct V_60 * V_61 = V_3 -> args -> V_61 ;
F_69 ( V_3 -> args ) ;
V_33 = V_88 -> V_6 - 1 ;
V_7 = & V_88 -> V_7 [ V_33 ] ;
switch ( V_7 -> V_25 ) {
case V_50 :
V_154 = F_70 ( V_7 -> V_8 , & V_35 ) ;
if ( V_35 == 0 )
return;
break;
case V_55 :
V_154 = F_71 ( V_61 , V_7 -> V_8 , & V_35 ) ;
if ( V_35 == 0 )
return;
break;
case V_32 :
V_154 = F_68 ( V_61 , V_7 -> V_8 , & V_35 ) ;
if ( V_35 == 0 )
return;
break;
}
for ( V_7 -- , V_33 -- ; V_33 >= 0 ; V_7 -- , V_33 -- ) {
struct V_17 V_101 ;
V_73 = V_7 -> V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_73 ) ;
V_100 = V_61 -> V_78 -> V_105 ( V_73 ) ;
if ( F_39 ( V_100 -> V_117 ) == V_154 )
break;
V_7 -> V_117 = V_154 ;
V_100 [ V_7 -> V_127 ] . V_117 = F_40 ( V_154 ) ;
F_28 ( V_3 -> args -> V_74 , V_7 -> V_8 ,
F_29 ( V_73 , & V_100 [ V_7 -> V_127 ] ,
sizeof( * V_100 ) ) ) ;
V_154 = F_39 ( V_100 [ V_101 . V_35 - 1 ] . V_117 ) ;
}
}
STATIC void
F_57 (
struct V_81 * V_3 ,
struct V_82 * V_140 )
{
struct V_14 * V_73 ;
struct V_17 V_101 ;
struct V_99 * V_100 ;
int V_127 ;
int V_137 ;
struct V_60 * V_61 = V_3 -> args -> V_61 ;
F_72 ( V_3 -> args ) ;
V_73 = V_140 -> V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_73 ) ;
ASSERT ( V_140 -> V_127 < V_101 . V_35 ) ;
ASSERT ( V_140 -> V_127 >= 0 ) ;
V_127 = V_140 -> V_127 ;
V_100 = V_61 -> V_78 -> V_105 ( V_73 ) ;
if ( V_127 < V_101 . V_35 - 1 ) {
V_137 = V_101 . V_35 - V_127 - 1 ;
V_137 *= ( V_139 ) sizeof( V_120 ) ;
memmove ( & V_100 [ V_127 ] , & V_100 [ V_127 + 1 ] , V_137 ) ;
F_28 ( V_3 -> args -> V_74 , V_140 -> V_8 ,
F_29 ( V_73 , & V_100 [ V_127 ] , V_137 ) ) ;
V_127 = V_101 . V_35 - 1 ;
}
memset ( & V_100 [ V_127 ] , 0 , sizeof( V_120 ) ) ;
F_28 ( V_3 -> args -> V_74 , V_140 -> V_8 ,
F_29 ( V_73 , & V_100 [ V_127 ] , sizeof( V_100 [ V_127 ] ) ) ) ;
V_101 . V_35 -= 1 ;
V_61 -> V_78 -> V_79 ( V_73 , & V_101 ) ;
F_28 ( V_3 -> args -> V_74 , V_140 -> V_8 ,
F_29 ( V_73 , & V_73 -> V_15 , V_61 -> V_78 -> V_80 ) ) ;
V_140 -> V_117 = F_39 ( V_100 [ V_127 - 1 ] . V_117 ) ;
}
STATIC void
F_59 (
struct V_81 * V_3 ,
struct V_82 * V_140 ,
struct V_82 * V_141 )
{
struct V_14 * V_155 ;
struct V_14 * V_156 ;
struct V_99 * V_157 ;
struct V_99 * V_158 ;
struct V_17 V_159 ;
struct V_17 V_160 ;
struct V_58 * V_59 ;
int V_161 ;
int V_137 ;
struct V_60 * V_61 = V_3 -> args -> V_61 ;
F_73 ( V_3 -> args ) ;
V_155 = V_140 -> V_8 -> V_16 ;
V_156 = V_141 -> V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_159 , V_155 ) ;
V_61 -> V_78 -> V_21 ( & V_160 , V_156 ) ;
V_157 = V_61 -> V_78 -> V_105 ( V_155 ) ;
V_158 = V_61 -> V_78 -> V_105 ( V_156 ) ;
V_59 = V_3 -> args -> V_74 ;
if ( ( F_39 ( V_157 [ 0 ] . V_117 ) <
F_39 ( V_158 [ 0 ] . V_117 ) ) ||
( F_39 ( V_157 [ V_159 . V_35 - 1 ] . V_117 ) <
F_39 ( V_158 [ V_160 . V_35 - 1 ] . V_117 ) ) ) {
V_137 = V_160 . V_35 * sizeof( V_120 ) ;
memmove ( & V_158 [ V_159 . V_35 ] , & V_158 [ 0 ] , V_137 ) ;
V_161 = 0 ;
F_28 ( V_59 , V_141 -> V_8 ,
F_29 ( V_156 , & V_158 [ 0 ] ,
( V_160 . V_35 + V_159 . V_35 ) *
sizeof( V_120 ) ) ) ;
} else {
V_161 = V_160 . V_35 ;
F_28 ( V_59 , V_141 -> V_8 ,
F_29 ( V_156 , & V_158 [ V_161 ] ,
V_159 . V_35 * sizeof( V_120 ) ) ) ;
}
V_137 = V_159 . V_35 * ( V_139 ) sizeof( V_120 ) ;
memcpy ( & V_158 [ V_161 ] , & V_157 [ 0 ] , V_137 ) ;
V_160 . V_35 += V_159 . V_35 ;
V_61 -> V_78 -> V_79 ( V_156 , & V_160 ) ;
F_28 ( V_59 , V_141 -> V_8 ,
F_29 ( V_156 , & V_156 -> V_15 ,
V_61 -> V_78 -> V_80 ) ) ;
V_141 -> V_117 = F_39 ( V_158 [ V_160 . V_35 - 1 ] . V_117 ) ;
}
int
F_74 (
struct V_81 * V_3 ,
int * V_122 )
{
struct V_82 * V_7 ;
struct V_49 * V_162 ;
struct V_14 * V_73 ;
struct V_99 * V_100 ;
struct V_17 V_101 ;
struct V_71 * args ;
T_2 V_30 ;
T_6 V_117 ;
T_6 V_163 ;
int V_164 ;
int V_165 ;
int V_86 ;
int error ;
int V_150 ;
struct V_60 * V_61 = V_3 -> args -> V_61 ;
args = V_3 -> args ;
V_30 = ( args -> V_72 == V_115 ) ? V_3 -> V_11 -> V_116 : 0 ;
for ( V_7 = & V_3 -> V_88 . V_7 [ 0 ] , V_3 -> V_88 . V_6 = 1 ;
V_3 -> V_88 . V_6 <= V_34 ;
V_7 ++ , V_3 -> V_88 . V_6 ++ ) {
V_7 -> V_30 = V_30 ;
error = F_21 ( args -> V_74 , args -> V_61 , V_30 ,
- 1 , & V_7 -> V_8 , args -> V_72 ) ;
if ( error ) {
V_7 -> V_30 = 0 ;
V_3 -> V_88 . V_6 -- ;
return ( error ) ;
}
V_162 = V_7 -> V_8 -> V_16 ;
V_7 -> V_25 = F_19 ( V_162 -> V_25 ) ;
if ( V_7 -> V_25 == V_50 ||
V_7 -> V_25 == V_51 ) {
V_7 -> V_25 = V_50 ;
V_7 -> V_117 = F_70 ( V_7 -> V_8 , NULL ) ;
break;
}
if ( V_7 -> V_25 == V_55 ||
V_7 -> V_25 == V_56 ) {
V_7 -> V_25 = V_55 ;
V_7 -> V_117 = F_71 ( args -> V_61 ,
V_7 -> V_8 , NULL ) ;
break;
}
V_7 -> V_25 = V_32 ;
V_73 = V_7 -> V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_73 ) ;
V_100 = V_61 -> V_78 -> V_105 ( V_73 ) ;
V_86 = V_101 . V_35 ;
V_7 -> V_117 = F_39 ( V_100 [ V_86 - 1 ] . V_117 ) ;
V_164 = V_165 = V_86 / 2 ;
V_117 = args -> V_117 ;
while ( V_165 > 4 ) {
V_165 /= 2 ;
V_163 = F_39 ( V_100 [ V_164 ] . V_117 ) ;
if ( V_163 < V_117 )
V_164 += V_165 ;
else if ( V_163 > V_117 )
V_164 -= V_165 ;
else
break;
}
ASSERT ( ( V_164 >= 0 ) && ( V_164 < V_86 ) ) ;
ASSERT ( ( V_165 <= 4 ) ||
( F_39 ( V_100 [ V_164 ] . V_117 ) == V_117 ) ) ;
while ( V_164 > 0 &&
F_39 ( V_100 [ V_164 ] . V_117 ) >= V_117 ) {
V_164 -- ;
}
while ( V_164 < V_86 &&
F_39 ( V_100 [ V_164 ] . V_117 ) < V_117 ) {
V_164 ++ ;
}
if ( V_164 == V_86 ) {
V_7 -> V_127 = V_86 - 1 ;
V_30 = F_39 ( V_100 [ V_86 - 1 ] . V_118 ) ;
} else {
V_7 -> V_127 = V_164 ;
V_30 = F_39 ( V_100 [ V_164 ] . V_118 ) ;
}
}
for (; ; ) {
if ( V_7 -> V_25 == V_55 ) {
V_150 = F_75 ( V_7 -> V_8 , args ,
& V_7 -> V_127 , V_3 ) ;
} else if ( V_7 -> V_25 == V_50 ) {
V_150 = F_76 ( V_7 -> V_8 , args ) ;
V_7 -> V_127 = args -> V_127 ;
args -> V_30 = V_7 -> V_30 ;
} else {
ASSERT ( 0 ) ;
return F_77 ( V_43 ) ;
}
if ( ( ( V_150 == V_166 ) || ( V_150 == V_167 ) ) &&
( V_7 -> V_117 == args -> V_117 ) ) {
error = F_66 ( V_3 , & V_3 -> V_88 , 1 , 1 ,
& V_150 ) ;
if ( error )
return ( error ) ;
if ( V_150 == 0 ) {
continue;
} else if ( V_7 -> V_25 == V_50 ) {
V_150 = F_77 ( V_167 ) ;
}
}
break;
}
* V_122 = V_150 ;
return ( 0 ) ;
}
STATIC int
F_78 (
struct V_60 * V_61 ,
struct V_9 * V_168 ,
struct V_9 * V_169 )
{
struct V_14 * V_128 ;
struct V_14 * V_129 ;
struct V_99 * V_131 ;
struct V_99 * V_132 ;
struct V_17 V_170 ;
struct V_17 V_171 ;
V_128 = V_168 -> V_16 ;
V_129 = V_169 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_170 , V_128 ) ;
V_61 -> V_78 -> V_21 ( & V_171 , V_129 ) ;
V_131 = V_61 -> V_78 -> V_105 ( V_128 ) ;
V_132 = V_61 -> V_78 -> V_105 ( V_129 ) ;
if ( V_170 . V_35 > 0 && V_171 . V_35 > 0 &&
( ( F_39 ( V_132 [ 0 ] . V_117 ) < F_39 ( V_131 [ 0 ] . V_117 ) ) ||
( F_39 ( V_132 [ V_171 . V_35 - 1 ] . V_117 ) <
F_39 ( V_131 [ V_170 . V_35 - 1 ] . V_117 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_47 (
struct V_81 * V_3 ,
struct V_82 * V_172 ,
struct V_82 * V_173 )
{
struct V_49 * V_174 ;
struct V_49 * V_175 ;
struct V_49 * V_176 ;
struct V_71 * args ;
struct V_9 * V_8 ;
int V_118 = 0 ;
int error ;
struct V_60 * V_61 = V_3 -> args -> V_61 ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
V_174 = V_172 -> V_8 -> V_16 ;
V_175 = V_173 -> V_8 -> V_16 ;
ASSERT ( V_172 -> V_25 == V_32 ||
V_172 -> V_25 == V_55 ||
V_172 -> V_25 == V_50 ) ;
switch ( V_172 -> V_25 ) {
case V_50 :
V_118 = F_79 ( V_172 -> V_8 , V_173 -> V_8 ) ;
break;
case V_55 :
V_118 = F_80 ( V_61 , V_172 -> V_8 , V_173 -> V_8 ) ;
break;
case V_32 :
V_118 = F_78 ( V_61 , V_172 -> V_8 , V_173 -> V_8 ) ;
break;
}
if ( V_118 ) {
F_81 ( args ) ;
V_175 -> V_94 = F_40 ( V_172 -> V_30 ) ;
V_175 -> V_95 = V_174 -> V_95 ;
if ( V_174 -> V_95 ) {
error = F_21 ( args -> V_74 , V_61 ,
F_39 ( V_174 -> V_95 ) ,
- 1 , & V_8 , args -> V_72 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_176 = V_8 -> V_16 ;
ASSERT ( V_176 -> V_25 == V_174 -> V_25 ) ;
ASSERT ( F_39 ( V_176 -> V_94 ) == V_172 -> V_30 ) ;
V_176 -> V_94 = F_40 ( V_173 -> V_30 ) ;
F_28 ( args -> V_74 , V_8 , 0 , sizeof( * V_176 ) - 1 ) ;
}
V_174 -> V_95 = F_40 ( V_173 -> V_30 ) ;
} else {
F_82 ( args ) ;
V_175 -> V_94 = V_174 -> V_94 ;
V_175 -> V_95 = F_40 ( V_172 -> V_30 ) ;
if ( V_174 -> V_94 ) {
error = F_21 ( args -> V_74 , V_61 ,
F_39 ( V_174 -> V_94 ) ,
- 1 , & V_8 , args -> V_72 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_176 = V_8 -> V_16 ;
ASSERT ( V_176 -> V_25 == V_174 -> V_25 ) ;
ASSERT ( F_39 ( V_176 -> V_95 ) == V_172 -> V_30 ) ;
V_176 -> V_95 = F_40 ( V_173 -> V_30 ) ;
F_28 ( args -> V_74 , V_8 , 0 , sizeof( * V_176 ) - 1 ) ;
}
V_174 -> V_94 = F_40 ( V_173 -> V_30 ) ;
}
F_28 ( args -> V_74 , V_172 -> V_8 , 0 , sizeof( * V_176 ) - 1 ) ;
F_28 ( args -> V_74 , V_173 -> V_8 , 0 , sizeof( * V_176 ) - 1 ) ;
return ( 0 ) ;
}
STATIC int
F_60 (
struct V_81 * V_3 ,
struct V_82 * V_140 ,
struct V_82 * V_141 )
{
struct V_49 * V_177 ;
struct V_49 * V_178 ;
struct V_49 * V_176 ;
struct V_71 * args ;
struct V_9 * V_8 ;
int error ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
V_178 = V_141 -> V_8 -> V_16 ;
V_177 = V_140 -> V_8 -> V_16 ;
ASSERT ( V_141 -> V_25 == V_32 ||
V_141 -> V_25 == V_55 ||
V_141 -> V_25 == V_50 ) ;
ASSERT ( V_141 -> V_25 == V_140 -> V_25 ) ;
ASSERT ( ( F_39 ( V_178 -> V_94 ) == V_140 -> V_30 ) ||
( F_39 ( V_178 -> V_95 ) == V_140 -> V_30 ) ) ;
ASSERT ( ( F_39 ( V_177 -> V_94 ) == V_141 -> V_30 ) ||
( F_39 ( V_177 -> V_95 ) == V_141 -> V_30 ) ) ;
if ( F_39 ( V_178 -> V_95 ) == V_140 -> V_30 ) {
F_83 ( args ) ;
V_178 -> V_95 = V_177 -> V_95 ;
if ( V_177 -> V_95 ) {
error = F_21 ( args -> V_74 , args -> V_61 ,
F_39 ( V_177 -> V_95 ) ,
- 1 , & V_8 , args -> V_72 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_176 = V_8 -> V_16 ;
ASSERT ( V_176 -> V_25 == V_178 -> V_25 ) ;
ASSERT ( F_39 ( V_176 -> V_94 ) == V_140 -> V_30 ) ;
V_176 -> V_94 = F_40 ( V_141 -> V_30 ) ;
F_28 ( args -> V_74 , V_8 , 0 ,
sizeof( * V_176 ) - 1 ) ;
}
} else {
F_84 ( args ) ;
V_178 -> V_94 = V_177 -> V_94 ;
if ( V_177 -> V_94 ) {
error = F_21 ( args -> V_74 , args -> V_61 ,
F_39 ( V_177 -> V_94 ) ,
- 1 , & V_8 , args -> V_72 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_176 = V_8 -> V_16 ;
ASSERT ( V_176 -> V_25 == V_178 -> V_25 ) ;
ASSERT ( F_39 ( V_176 -> V_95 ) == V_140 -> V_30 ) ;
V_176 -> V_95 = F_40 ( V_141 -> V_30 ) ;
F_28 ( args -> V_74 , V_8 , 0 ,
sizeof( * V_176 ) - 1 ) ;
}
}
F_28 ( args -> V_74 , V_141 -> V_8 , 0 , sizeof( * V_178 ) - 1 ) ;
return ( 0 ) ;
}
int
F_66 (
struct V_81 * V_3 ,
struct V_153 * V_88 ,
int V_149 ,
int V_179 ,
int * V_122 )
{
struct V_82 * V_7 ;
struct V_49 * V_27 ;
struct V_14 * V_73 ;
struct V_71 * args ;
struct V_99 * V_100 ;
struct V_17 V_101 ;
T_2 V_30 = 0 ;
int V_33 ;
int error ;
struct V_60 * V_61 = V_3 -> args -> V_61 ;
F_85 ( V_3 -> args ) ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
ASSERT ( V_88 != NULL ) ;
ASSERT ( ( V_88 -> V_6 > 0 ) && ( V_88 -> V_6 < V_34 ) ) ;
V_33 = ( V_88 -> V_6 - 1 ) - 1 ;
for ( V_7 = & V_88 -> V_7 [ V_33 ] ; V_33 >= 0 ; V_7 -- , V_33 -- ) {
V_73 = V_7 -> V_8 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_73 ) ;
V_100 = V_61 -> V_78 -> V_105 ( V_73 ) ;
if ( V_149 && ( V_7 -> V_127 < V_101 . V_35 - 1 ) ) {
V_7 -> V_127 ++ ;
V_30 = F_39 ( V_100 [ V_7 -> V_127 ] . V_118 ) ;
break;
} else if ( ! V_149 && ( V_7 -> V_127 > 0 ) ) {
V_7 -> V_127 -- ;
V_30 = F_39 ( V_100 [ V_7 -> V_127 ] . V_118 ) ;
break;
}
}
if ( V_33 < 0 ) {
* V_122 = F_77 ( V_166 ) ;
ASSERT ( args -> V_180 & V_181 ) ;
return ( 0 ) ;
}
for ( V_7 ++ , V_33 ++ ; V_33 < V_88 -> V_6 ; V_7 ++ , V_33 ++ ) {
if ( V_179 )
F_67 ( args -> V_74 , V_7 -> V_8 ) ;
V_7 -> V_30 = V_30 ;
error = F_21 ( args -> V_74 , V_61 , V_30 , - 1 ,
& V_7 -> V_8 , args -> V_72 ) ;
if ( error )
return ( error ) ;
V_27 = V_7 -> V_8 -> V_16 ;
ASSERT ( V_27 -> V_25 == F_43 ( V_32 ) ||
V_27 -> V_25 == F_43 ( V_26 ) ||
V_27 -> V_25 == F_43 ( V_55 ) ||
V_27 -> V_25 == F_43 ( V_56 ) ||
V_27 -> V_25 == F_43 ( V_50 ) ||
V_27 -> V_25 == F_43 ( V_51 ) ) ;
switch ( F_19 ( V_27 -> V_25 ) ) {
case V_32 :
case V_26 :
V_7 -> V_25 = V_32 ;
V_73 = ( V_151 * ) V_27 ;
V_61 -> V_78 -> V_21 ( & V_101 , V_73 ) ;
V_100 = V_61 -> V_78 -> V_105 ( V_73 ) ;
V_7 -> V_117 = F_39 ( V_100 [ V_101 . V_35 - 1 ] . V_117 ) ;
if ( V_149 )
V_7 -> V_127 = 0 ;
else
V_7 -> V_127 = V_101 . V_35 - 1 ;
V_30 = F_39 ( V_100 [ V_7 -> V_127 ] . V_118 ) ;
break;
case V_50 :
case V_51 :
V_7 -> V_25 = V_50 ;
ASSERT ( V_33 == V_88 -> V_6 - 1 ) ;
V_7 -> V_127 = 0 ;
V_7 -> V_117 = F_70 ( V_7 -> V_8 , NULL ) ;
break;
case V_55 :
case V_56 :
V_7 -> V_25 = V_55 ;
ASSERT ( V_33 == V_88 -> V_6 - 1 ) ;
V_7 -> V_127 = 0 ;
V_7 -> V_117 = F_71 ( args -> V_61 ,
V_7 -> V_8 , NULL ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
}
* V_122 = 0 ;
return 0 ;
}
T_6
F_86 ( const T_7 * V_182 , int V_183 )
{
T_6 V_184 ;
for ( V_184 = 0 ; V_183 >= 4 ; V_183 -= 4 , V_182 += 4 )
V_184 = ( V_182 [ 0 ] << 21 ) ^ ( V_182 [ 1 ] << 14 ) ^ ( V_182 [ 2 ] << 7 ) ^
( V_182 [ 3 ] << 0 ) ^ F_87 ( V_184 , 7 * 4 ) ;
switch ( V_183 ) {
case 3 :
return ( V_182 [ 0 ] << 14 ) ^ ( V_182 [ 1 ] << 7 ) ^ ( V_182 [ 2 ] << 0 ) ^
F_87 ( V_184 , 7 * 3 ) ;
case 2 :
return ( V_182 [ 0 ] << 7 ) ^ ( V_182 [ 1 ] << 0 ) ^ F_87 ( V_184 , 7 * 2 ) ;
case 1 :
return ( V_182 [ 0 ] << 0 ) ^ F_87 ( V_184 , 7 * 1 ) ;
default:
return V_184 ;
}
}
enum V_185
F_88 (
struct V_71 * args ,
const unsigned char * V_182 ,
int V_186 )
{
return ( args -> V_183 == V_186 && memcmp ( args -> V_182 , V_182 , V_186 ) == 0 ) ?
V_187 : V_188 ;
}
static T_6
F_89 (
struct V_189 * V_182 )
{
return F_86 ( V_182 -> V_182 , V_182 -> V_186 ) ;
}
int
F_90 (
struct V_71 * args ,
T_8 * V_62 ,
int V_35 )
{
struct V_58 * V_59 = args -> V_74 ;
struct V_60 * V_61 = args -> V_61 ;
int V_190 = args -> V_72 ;
T_9 V_191 = V_61 -> V_192 . V_193 ;
struct V_194 V_195 , * V_196 ;
int V_197 , error , V_198 , V_4 , V_199 ;
error = F_91 ( V_59 , V_61 , V_35 , V_62 , V_190 ) ;
if ( error )
return error ;
V_197 = 1 ;
ASSERT ( args -> V_200 != NULL ) ;
error = F_92 ( V_59 , V_61 , * V_62 , V_35 ,
F_93 ( V_190 ) | V_201 | V_202 ,
args -> V_200 , args -> V_203 , & V_195 , & V_197 ,
args -> V_204 ) ;
if ( error )
return error ;
ASSERT ( V_197 <= 1 ) ;
if ( V_197 == 1 ) {
V_196 = & V_195 ;
V_199 = 1 ;
} else if ( V_197 == 0 && V_35 > 1 ) {
T_8 V_205 ;
int V_206 ;
V_196 = F_94 ( sizeof( * V_196 ) * V_35 , V_207 ) ;
for ( V_205 = * V_62 , V_199 = 0 ; V_205 < * V_62 + V_35 ; ) {
V_197 = F_95 ( V_208 , V_35 ) ;
V_206 = ( int ) ( * V_62 + V_35 - V_205 ) ;
error = F_92 ( V_59 , V_61 , V_205 , V_206 ,
F_93 ( V_190 ) | V_201 ,
args -> V_200 , args -> V_203 ,
& V_196 [ V_199 ] , & V_197 , args -> V_204 ) ;
if ( error )
goto V_209;
if ( V_197 < 1 )
break;
V_199 += V_197 ;
V_205 = V_196 [ V_199 - 1 ] . V_210 +
V_196 [ V_199 - 1 ] . V_211 ;
}
} else {
V_199 = 0 ;
V_196 = NULL ;
}
for ( V_4 = 0 , V_198 = 0 ; V_4 < V_199 ; V_4 ++ )
V_198 += V_196 [ V_4 ] . V_211 ;
if ( V_198 != V_35 || V_196 [ 0 ] . V_210 != * V_62 ||
V_196 [ V_199 - 1 ] . V_210 + V_196 [ V_199 - 1 ] . V_211 !=
* V_62 + V_35 ) {
error = F_77 ( V_89 ) ;
goto V_209;
}
args -> V_203 -= V_61 -> V_192 . V_193 - V_191 ;
V_209:
if ( V_196 != & V_195 )
F_96 ( V_196 ) ;
return error ;
}
int
F_42 (
struct V_71 * args ,
T_2 * V_212 )
{
T_8 V_62 ;
int V_35 ;
int error ;
F_97 ( args ) ;
if ( args -> V_72 == V_115 ) {
V_62 = args -> V_61 -> V_213 -> V_116 ;
V_35 = args -> V_61 -> V_213 -> V_214 ;
} else {
V_62 = 0 ;
V_35 = 1 ;
}
error = F_90 ( args , & V_62 , V_35 ) ;
if ( ! error )
* V_212 = ( T_2 ) V_62 ;
return error ;
}
STATIC int
F_98 (
struct V_71 * args ,
T_2 * V_215 ,
struct V_9 * * V_216 )
{
struct V_49 * V_217 ;
struct V_49 * V_218 ;
struct V_14 * V_219 ;
struct V_14 * V_220 ;
struct V_102 * V_221 ;
struct V_99 * V_100 ;
struct V_17 V_222 ;
struct V_60 * V_61 ;
struct V_58 * V_59 ;
struct V_10 * V_11 ;
struct V_9 * V_223 ;
struct V_9 * V_224 ;
struct V_9 * V_225 ;
struct V_9 * V_226 ;
T_6 V_227 ;
T_8 V_228 ;
T_2 V_229 ;
T_2 V_230 ;
T_2 V_231 ;
T_2 V_232 ;
int error ;
int V_190 ;
int V_233 ;
int V_33 ;
int V_234 ;
F_99 ( args ) ;
V_223 = * V_216 ;
V_229 = * V_215 ;
V_59 = args -> V_74 ;
V_61 = args -> V_61 ;
V_190 = args -> V_72 ;
ASSERT ( V_190 == V_115 ) ;
V_11 = V_61 -> V_213 ;
V_228 = V_11 -> V_119 ;
error = F_100 ( V_59 , V_61 , & V_228 , V_190 ) ;
if ( error )
return error ;
if ( F_101 ( V_228 == 0 ) ) {
F_102 ( L_1 , V_42 ,
V_11 ) ;
return F_77 ( V_43 ) ;
}
V_230 = ( T_2 ) V_228 - V_11 -> V_214 ;
error = F_21 ( V_59 , V_61 , V_230 , - 1 , & V_224 , V_190 ) ;
if ( error )
return error ;
memcpy ( V_223 -> V_16 , V_224 -> V_16 , V_11 -> V_235 ) ;
F_28 ( V_59 , V_223 , 0 , V_11 -> V_235 - 1 ) ;
V_217 = V_223 -> V_16 ;
if ( V_217 -> V_25 == F_43 ( V_55 ) ||
V_217 -> V_25 == F_43 ( V_56 ) ) {
struct V_106 V_107 ;
struct V_108 * V_109 ;
V_221 = ( V_110 * ) V_217 ;
V_61 -> V_78 -> V_111 ( & V_107 , V_221 ) ;
V_109 = V_61 -> V_78 -> V_112 ( V_221 ) ;
V_234 = 0 ;
V_227 = F_39 ( V_109 [ V_107 . V_35 - 1 ] . V_117 ) ;
} else {
struct V_17 V_236 ;
V_220 = ( V_151 * ) V_217 ;
V_61 -> V_78 -> V_21 ( & V_236 , V_220 ) ;
V_100 = V_61 -> V_78 -> V_105 ( V_220 ) ;
V_234 = V_236 . V_33 ;
V_227 = F_39 ( V_100 [ V_236 . V_35 - 1 ] . V_117 ) ;
}
V_225 = V_226 = NULL ;
if ( ( V_231 = F_39 ( V_217 -> V_95 ) ) ) {
error = F_21 ( V_59 , V_61 , V_231 , - 1 , & V_225 , V_190 ) ;
if ( error )
goto V_237;
V_218 = V_225 -> V_16 ;
if ( F_101 (
F_39 ( V_218 -> V_94 ) != V_230 ||
V_218 -> V_25 != V_217 -> V_25 ) ) {
F_102 ( L_2 ,
V_42 , V_11 ) ;
error = F_77 ( V_43 ) ;
goto V_237;
}
V_218 -> V_94 = F_40 ( V_229 ) ;
F_28 ( V_59 , V_225 ,
F_29 ( V_218 , & V_218 -> V_94 ,
sizeof( V_218 -> V_94 ) ) ) ;
V_225 = NULL ;
}
if ( ( V_231 = F_39 ( V_217 -> V_94 ) ) ) {
error = F_21 ( V_59 , V_61 , V_231 , - 1 , & V_225 , V_190 ) ;
if ( error )
goto V_237;
V_218 = V_225 -> V_16 ;
if ( F_101 (
F_39 ( V_218 -> V_95 ) != V_230 ||
V_218 -> V_25 != V_217 -> V_25 ) ) {
F_102 ( L_3 ,
V_42 , V_11 ) ;
error = F_77 ( V_43 ) ;
goto V_237;
}
V_218 -> V_95 = F_40 ( V_229 ) ;
F_28 ( V_59 , V_225 ,
F_29 ( V_218 , & V_218 -> V_95 ,
sizeof( V_218 -> V_95 ) ) ) ;
V_225 = NULL ;
}
V_232 = V_11 -> V_116 ;
V_33 = - 1 ;
for (; ; ) {
error = F_21 ( V_59 , V_61 , V_232 , - 1 , & V_226 , V_190 ) ;
if ( error )
goto V_237;
V_219 = V_226 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_222 , V_219 ) ;
if ( V_33 >= 0 && V_33 != V_222 . V_33 + 1 ) {
F_102 ( L_4 ,
V_42 , V_11 ) ;
error = F_77 ( V_43 ) ;
goto V_237;
}
V_33 = V_222 . V_33 ;
V_100 = V_61 -> V_78 -> V_105 ( V_219 ) ;
for ( V_233 = 0 ;
V_233 < V_222 . V_35 &&
F_39 ( V_100 [ V_233 ] . V_117 ) < V_227 ;
V_233 ++ )
continue;
if ( V_233 == V_222 . V_35 ) {
F_102 ( L_5 ,
V_42 , V_11 ) ;
error = F_77 ( V_43 ) ;
goto V_237;
}
V_232 = F_39 ( V_100 [ V_233 ] . V_118 ) ;
if ( V_33 == V_234 + 1 )
break;
F_67 ( V_59 , V_226 ) ;
V_226 = NULL ;
}
for (; ; ) {
for (;
V_233 < V_222 . V_35 &&
F_39 ( V_100 [ V_233 ] . V_118 ) != V_230 ;
V_233 ++ )
continue;
if ( V_233 < V_222 . V_35 )
break;
V_232 = V_222 . V_94 ;
F_67 ( V_59 , V_226 ) ;
V_226 = NULL ;
if ( F_101 ( V_232 == 0 ) ) {
F_102 ( L_6 ,
V_42 , V_11 ) ;
error = F_77 ( V_43 ) ;
goto V_237;
}
error = F_21 ( V_59 , V_61 , V_232 , - 1 , & V_226 , V_190 ) ;
if ( error )
goto V_237;
V_219 = V_226 -> V_16 ;
V_61 -> V_78 -> V_21 ( & V_222 , V_219 ) ;
if ( V_222 . V_33 != V_33 ) {
F_102 ( L_7 ,
V_42 , V_11 ) ;
error = F_77 ( V_43 ) ;
goto V_237;
}
V_100 = V_61 -> V_78 -> V_105 ( V_219 ) ;
V_233 = 0 ;
}
V_100 [ V_233 ] . V_118 = F_40 ( V_229 ) ;
F_28 ( V_59 , V_226 ,
F_29 ( V_219 , & V_100 [ V_233 ] . V_118 ,
sizeof( V_100 [ V_233 ] . V_118 ) ) ) ;
* V_215 = V_230 ;
* V_216 = V_224 ;
return 0 ;
V_237:
if ( V_226 )
F_67 ( V_59 , V_226 ) ;
if ( V_225 )
F_67 ( V_59 , V_225 ) ;
F_67 ( V_59 , V_224 ) ;
return error ;
}
int
F_61 (
T_10 * args ,
T_2 V_229 ,
struct V_9 * V_223 )
{
T_11 * V_61 ;
int V_237 , error , V_190 , V_35 ;
T_12 * V_59 ;
T_13 * V_11 ;
F_103 ( args ) ;
V_61 = args -> V_61 ;
V_190 = args -> V_72 ;
V_59 = args -> V_74 ;
V_11 = V_61 -> V_213 ;
if ( V_190 == V_115 )
V_35 = V_11 -> V_214 ;
else
V_35 = 1 ;
for (; ; ) {
error = F_104 ( V_59 , V_61 , V_229 , V_35 ,
F_93 ( V_190 ) | V_201 ,
0 , args -> V_200 , args -> V_204 , & V_237 ) ;
if ( error == V_89 ) {
if ( V_190 != V_115 )
break;
error = F_98 ( args , & V_229 ,
& V_223 ) ;
if ( error )
break;
} else {
break;
}
}
F_105 ( V_59 , V_223 ) ;
return error ;
}
STATIC int
F_106 (
int V_197 ,
T_14 * V_196 ,
T_2 V_62 ,
int V_35 )
{
int V_4 ;
T_8 V_238 ;
for ( V_4 = 0 , V_238 = V_62 ; V_4 < V_197 ; V_4 ++ ) {
if ( V_196 [ V_4 ] . V_239 == V_240 ||
V_196 [ V_4 ] . V_239 == V_241 ) {
return 0 ;
}
if ( V_238 != V_196 [ V_4 ] . V_210 ) {
return 0 ;
}
V_238 += V_196 [ V_4 ] . V_211 ;
}
return V_238 == V_62 + V_35 ;
}
static int
F_107 (
struct V_10 * V_11 ,
struct V_242 * * V_196 ,
int * V_243 ,
struct V_194 * V_244 ,
int V_245 )
{
struct V_242 * V_195 ;
int V_4 ;
ASSERT ( * V_243 == 1 ) ;
ASSERT ( V_245 >= 1 ) ;
if ( V_245 > 1 ) {
V_195 = F_108 ( V_245 * sizeof( struct V_242 ) ,
V_207 | V_2 ) ;
if ( ! V_195 )
return V_246 ;
* V_196 = V_195 ;
}
* V_243 = V_245 ;
V_195 = * V_196 ;
for ( V_4 = 0 ; V_4 < * V_243 ; V_4 ++ ) {
ASSERT ( V_244 [ V_4 ] . V_239 != V_241 &&
V_244 [ V_4 ] . V_239 != V_240 ) ;
V_195 [ V_4 ] . V_247 = F_109 ( V_11 , V_244 [ V_4 ] . V_239 ) ;
V_195 [ V_4 ] . V_248 = F_110 ( V_11 , V_244 [ V_4 ] . V_211 ) ;
}
return 0 ;
}
static int
F_111 (
struct V_58 * V_74 ,
struct V_60 * V_61 ,
T_2 V_62 ,
T_3 V_63 ,
int V_72 ,
struct V_242 * * V_195 ,
int * V_243 )
{
struct V_10 * V_11 = V_61 -> V_213 ;
int V_249 ;
int error = 0 ;
struct V_194 V_250 ;
struct V_194 * V_244 = & V_250 ;
int V_245 ;
ASSERT ( V_195 && * V_195 ) ;
ASSERT ( * V_243 == 1 ) ;
V_249 = ( V_72 == V_115 ) ? V_11 -> V_214 : 1 ;
if ( V_63 == - 1 || V_63 == - 2 ) {
if ( V_249 != 1 )
V_244 = F_108 ( sizeof( V_250 ) * V_249 ,
V_207 | V_2 ) ;
V_245 = V_249 ;
error = F_112 ( V_61 , ( T_8 ) V_62 , V_249 , V_244 ,
& V_245 , F_93 ( V_72 ) ) ;
if ( error )
goto V_251;
} else {
V_244 -> V_239 = F_113 ( V_11 , V_63 ) ;
V_244 -> V_210 = ( T_8 ) V_62 ;
V_244 -> V_211 = V_249 ;
V_244 -> V_252 = 0 ;
V_245 = 1 ;
}
if ( ! F_106 ( V_245 , V_244 , V_62 , V_249 ) ) {
error = V_63 == - 2 ? - 1 : F_77 ( V_43 ) ;
if ( F_101 ( error == V_43 ) ) {
if ( V_253 >= V_42 ) {
int V_4 ;
F_114 ( V_11 , L_8 ,
V_41 , ( long long ) V_62 ,
( long long ) V_61 -> V_77 ) ;
for ( V_4 = 0 ; V_4 < * V_243 ; V_4 ++ ) {
F_114 ( V_11 ,
L_9 ,
V_4 ,
( long long ) V_244 [ V_4 ] . V_210 ,
( long long ) V_244 [ V_4 ] . V_239 ,
( long long ) V_244 [ V_4 ] . V_211 ,
V_244 [ V_4 ] . V_252 ) ;
}
}
F_102 ( L_10 ,
V_42 , V_11 ) ;
}
goto V_251;
}
error = F_107 ( V_11 , V_195 , V_243 , V_244 , V_245 ) ;
V_251:
if ( V_244 != & V_250 )
F_96 ( V_244 ) ;
return error ;
}
int
F_26 (
struct V_58 * V_74 ,
struct V_60 * V_61 ,
T_2 V_62 ,
T_3 V_63 ,
struct V_9 * * V_64 ,
int V_72 )
{
struct V_9 * V_8 ;
struct V_242 V_195 ;
struct V_242 * V_196 ;
int V_197 ;
int error ;
* V_64 = NULL ;
V_196 = & V_195 ;
V_197 = 1 ;
error = F_111 ( V_74 , V_61 , V_62 , V_63 , V_72 ,
& V_196 , & V_197 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_254;
}
V_8 = F_115 ( V_74 , V_61 -> V_213 -> V_255 ,
V_196 , V_197 , 0 ) ;
error = V_8 ? V_8 -> V_256 : F_77 ( V_257 ) ;
if ( error ) {
F_67 ( V_74 , V_8 ) ;
goto V_254;
}
* V_64 = V_8 ;
V_254:
if ( V_196 != & V_195 )
F_96 ( V_196 ) ;
return error ;
}
int
F_22 (
struct V_58 * V_74 ,
struct V_60 * V_61 ,
T_2 V_62 ,
T_3 V_63 ,
struct V_9 * * V_64 ,
int V_72 ,
const struct V_258 * V_20 )
{
struct V_9 * V_8 ;
struct V_242 V_195 ;
struct V_242 * V_196 ;
int V_197 ;
int error ;
* V_64 = NULL ;
V_196 = & V_195 ;
V_197 = 1 ;
error = F_111 ( V_74 , V_61 , V_62 , V_63 , V_72 ,
& V_196 , & V_197 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_254;
}
error = F_116 ( V_61 -> V_213 , V_74 ,
V_61 -> V_213 -> V_255 ,
V_196 , V_197 , 0 , & V_8 , V_20 ) ;
if ( error )
goto V_254;
if ( V_72 == V_125 )
F_117 ( V_8 , V_259 ) ;
else
F_117 ( V_8 , V_260 ) ;
{
T_15 * V_15 = V_8 -> V_16 ;
T_16 * free = V_8 -> V_16 ;
T_17 * V_27 = V_8 -> V_16 ;
V_139 V_25 , V_261 ;
struct V_10 * V_11 = V_61 -> V_213 ;
V_25 = F_19 ( V_27 -> V_25 ) ;
V_261 = F_39 ( V_15 -> V_25 ) ;
if ( F_101 (
F_118 ( ( V_25 != V_32 ) &&
( V_25 != V_26 ) &&
( V_25 != V_50 ) &&
( V_25 != V_51 ) &&
( V_25 != V_262 ) &&
( V_25 != V_263 ) &&
( V_25 != V_55 ) &&
( V_25 != V_56 ) &&
( V_261 != V_264 ) &&
( V_261 != V_265 ) &&
( V_261 != V_266 ) &&
( V_261 != V_267 ) &&
( free -> V_15 . V_25 !=
F_40 ( V_268 ) ) &&
( free -> V_15 . V_25 !=
F_40 ( V_269 ) ) ,
V_11 , V_270 ,
V_271 ) ) ) {
F_119 ( V_8 , V_272 ) ;
F_13 ( L_11 ,
V_42 , V_11 , V_27 ) ;
error = F_77 ( V_43 ) ;
F_67 ( V_74 , V_8 ) ;
goto V_254;
}
}
* V_64 = V_8 ;
V_254:
if ( V_196 != & V_195 )
F_96 ( V_196 ) ;
return error ;
}
T_3
F_120 (
struct V_58 * V_74 ,
struct V_60 * V_61 ,
T_2 V_62 ,
T_3 V_63 ,
int V_72 ,
const struct V_258 * V_20 )
{
struct V_242 V_195 ;
struct V_242 * V_196 ;
int V_197 ;
int error ;
V_196 = & V_195 ;
V_197 = 1 ;
error = F_111 ( V_74 , V_61 , V_62 , V_63 , V_72 ,
& V_196 , & V_197 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_254;
}
V_63 = V_196 [ 0 ] . V_247 ;
F_121 ( V_61 -> V_213 -> V_255 , V_196 , V_197 , V_20 ) ;
V_254:
if ( V_196 != & V_195 )
F_96 ( V_196 ) ;
if ( error )
return - 1 ;
return V_63 ;
}
