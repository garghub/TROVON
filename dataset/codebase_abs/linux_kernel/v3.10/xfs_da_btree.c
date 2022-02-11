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
void
F_7 (
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
ASSERT ( V_12 -> V_13 . V_14 . V_15 == F_8 ( V_16 ) ||
V_12 -> V_13 . V_14 . V_15 == F_8 ( V_17 ) ) ;
if ( V_12 -> V_13 . V_14 . V_15 == F_8 ( V_17 ) ) {
struct V_18 * V_19 = (struct V_18 * ) V_12 ;
V_10 -> V_20 = F_9 ( V_19 -> V_14 . V_13 . V_20 ) ;
V_10 -> V_21 = F_9 ( V_19 -> V_14 . V_13 . V_21 ) ;
V_10 -> V_15 = F_10 ( V_19 -> V_14 . V_13 . V_15 ) ;
V_10 -> V_22 = F_10 ( V_19 -> V_23 ) ;
V_10 -> V_24 = F_10 ( V_19 -> V_25 ) ;
return;
}
V_10 -> V_20 = F_9 ( V_12 -> V_13 . V_14 . V_20 ) ;
V_10 -> V_21 = F_9 ( V_12 -> V_13 . V_14 . V_21 ) ;
V_10 -> V_15 = F_10 ( V_12 -> V_13 . V_14 . V_15 ) ;
V_10 -> V_22 = F_10 ( V_12 -> V_13 . V_23 ) ;
V_10 -> V_24 = F_10 ( V_12 -> V_13 . V_25 ) ;
}
void
F_11 (
struct V_11 * V_10 ,
struct V_9 * V_12 )
{
ASSERT ( V_12 -> V_15 == V_16 ||
V_12 -> V_15 == V_17 ) ;
if ( V_12 -> V_15 == V_17 ) {
struct V_18 * V_19 = (struct V_18 * ) V_10 ;
V_19 -> V_14 . V_13 . V_20 = F_12 ( V_12 -> V_20 ) ;
V_19 -> V_14 . V_13 . V_21 = F_12 ( V_12 -> V_21 ) ;
V_19 -> V_14 . V_13 . V_15 = F_8 ( V_12 -> V_15 ) ;
V_19 -> V_23 = F_8 ( V_12 -> V_22 ) ;
V_19 -> V_25 = F_8 ( V_12 -> V_24 ) ;
return;
}
V_10 -> V_13 . V_14 . V_20 = F_12 ( V_12 -> V_20 ) ;
V_10 -> V_13 . V_14 . V_21 = F_12 ( V_12 -> V_21 ) ;
V_10 -> V_13 . V_14 . V_15 = F_8 ( V_12 -> V_15 ) ;
V_10 -> V_13 . V_23 = F_8 ( V_12 -> V_22 ) ;
V_10 -> V_13 . V_25 = F_8 ( V_12 -> V_24 ) ;
}
static bool
F_13 (
struct V_26 * V_8 )
{
struct V_27 * V_28 = V_8 -> V_29 -> V_30 ;
struct V_11 * V_13 = V_8 -> V_31 ;
struct V_9 V_32 ;
F_7 ( & V_32 , V_13 ) ;
if ( F_14 ( & V_28 -> V_33 ) ) {
struct V_18 * V_19 = V_8 -> V_31 ;
if ( V_32 . V_15 != V_17 )
return false ;
if ( ! F_15 ( & V_19 -> V_14 . V_34 , & V_28 -> V_33 . V_35 ) )
return false ;
if ( F_16 ( V_19 -> V_14 . V_36 ) != V_8 -> V_37 )
return false ;
} else {
if ( V_32 . V_15 != V_16 )
return false ;
}
if ( V_32 . V_24 == 0 )
return false ;
if ( V_32 . V_24 > V_38 )
return false ;
if ( V_32 . V_22 == 0 )
return false ;
if ( V_32 . V_22 > V_28 -> V_39 &&
V_32 . V_22 > V_28 -> V_40 )
return false ;
return true ;
}
static void
F_17 (
struct V_26 * V_8 )
{
struct V_27 * V_28 = V_8 -> V_29 -> V_30 ;
struct V_41 * V_42 = V_8 -> V_43 ;
struct V_18 * V_19 = V_8 -> V_31 ;
if ( ! F_13 ( V_8 ) ) {
F_18 ( V_44 , V_45 , V_28 , V_8 -> V_31 ) ;
F_19 ( V_8 , V_46 ) ;
return;
}
if ( ! F_14 ( & V_28 -> V_33 ) )
return;
if ( V_42 )
V_19 -> V_14 . V_47 = F_20 ( V_42 -> V_48 . V_49 ) ;
F_21 ( V_8 -> V_31 , F_22 ( V_8 -> V_50 ) , V_51 ) ;
}
static void
F_23 (
struct V_26 * V_8 )
{
struct V_27 * V_28 = V_8 -> V_29 -> V_30 ;
struct V_52 * V_14 = V_8 -> V_31 ;
switch ( F_10 ( V_14 -> V_15 ) ) {
case V_17 :
if ( ! F_24 ( V_8 -> V_31 , F_22 ( V_8 -> V_50 ) ,
V_51 ) )
break;
case V_16 :
if ( ! F_13 ( V_8 ) )
break;
return;
case V_53 :
case V_54 :
V_8 -> V_55 = & V_56 ;
V_8 -> V_55 -> V_57 ( V_8 ) ;
return;
case V_58 :
case V_59 :
V_8 -> V_55 = & V_60 ;
V_8 -> V_55 -> V_57 ( V_8 ) ;
return;
default:
break;
}
F_18 ( V_44 , V_45 , V_28 , V_8 -> V_31 ) ;
F_19 ( V_8 , V_46 ) ;
}
int
F_25 (
struct V_61 * V_62 ,
struct V_63 * V_64 ,
T_2 V_65 ,
T_3 V_66 ,
struct V_26 * * V_67 ,
int V_68 )
{
int V_69 ;
V_69 = F_26 ( V_62 , V_64 , V_65 , V_66 , V_67 ,
V_68 , & V_70 ) ;
if ( ! V_69 && V_62 ) {
struct V_52 * V_14 = ( * V_67 ) -> V_31 ;
int type ;
switch ( F_10 ( V_14 -> V_15 ) ) {
case V_16 :
case V_17 :
type = V_71 ;
break;
case V_53 :
case V_54 :
type = V_72 ;
break;
case V_58 :
case V_59 :
type = V_73 ;
break;
default:
type = 0 ;
ASSERT ( 0 ) ;
break;
}
F_27 ( V_62 , * V_67 , type ) ;
}
return V_69 ;
}
int
F_28 (
struct V_74 * args ,
T_2 V_36 ,
int V_24 ,
struct V_26 * * V_67 ,
int V_75 )
{
struct V_11 * V_76 ;
struct V_61 * V_62 = args -> V_77 ;
struct V_27 * V_28 = V_62 -> V_78 ;
struct V_9 V_32 = { 0 } ;
struct V_26 * V_8 ;
int error ;
F_29 ( args ) ;
ASSERT ( V_24 <= V_38 ) ;
error = F_30 ( V_62 , args -> V_64 , V_36 , - 1 , & V_8 , V_75 ) ;
if ( error )
return ( error ) ;
V_8 -> V_55 = & V_70 ;
F_27 ( V_62 , V_8 , V_71 ) ;
V_76 = V_8 -> V_31 ;
if ( F_14 ( & V_28 -> V_33 ) ) {
struct V_18 * V_19 = V_8 -> V_31 ;
V_32 . V_15 = V_17 ;
V_19 -> V_14 . V_36 = F_20 ( V_8 -> V_37 ) ;
V_19 -> V_14 . V_79 = F_20 ( args -> V_64 -> V_80 ) ;
F_31 ( & V_19 -> V_14 . V_34 , & V_28 -> V_33 . V_35 ) ;
} else {
V_32 . V_15 = V_16 ;
}
V_32 . V_24 = V_24 ;
F_11 ( V_76 , & V_32 ) ;
F_32 ( V_62 , V_8 ,
F_33 ( V_76 , & V_76 -> V_13 , F_34 ( V_76 ) ) ) ;
* V_67 = V_8 ;
return ( 0 ) ;
}
int
F_35 (
struct V_81 * V_3 )
{
struct V_82 * V_83 ;
struct V_82 * V_84 ;
struct V_82 * V_85 ;
struct V_11 * V_76 ;
struct V_26 * V_8 ;
int V_86 ;
int V_87 ;
int error ;
int V_4 ;
F_36 ( V_3 -> args ) ;
V_86 = V_3 -> V_88 . V_6 - 1 ;
ASSERT ( ( V_86 >= 0 ) && ( V_86 < V_38 ) ) ;
ASSERT ( V_3 -> V_88 . V_7 [ V_86 ] . V_15 == V_53 ||
V_3 -> V_88 . V_7 [ V_86 ] . V_15 == V_58 ) ;
V_85 = & V_3 -> V_88 . V_7 [ V_86 ] ;
for ( V_4 = V_86 ; ( V_4 >= 0 ) && V_85 ; V_3 -> V_88 . V_6 -- , V_4 -- ) {
V_83 = & V_3 -> V_88 . V_7 [ V_4 ] ;
V_84 = & V_3 -> V_5 . V_7 [ V_4 ] ;
switch ( V_83 -> V_15 ) {
case V_53 :
error = F_37 ( V_3 , V_83 , V_84 ) ;
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
F_38 ( V_3 -> args ) ;
error = F_37 ( V_3 , V_83 ,
& V_3 -> V_93 ) ;
} else {
V_3 -> V_92 = 1 ;
F_39 ( V_3 -> args ) ;
error = F_37 ( V_3 , V_84 ,
& V_3 -> V_93 ) ;
}
if ( error )
return ( error ) ;
V_85 = V_84 ;
break;
case V_58 :
error = F_40 ( V_3 , V_83 , V_84 ) ;
if ( error )
return error ;
V_85 = V_84 ;
break;
case V_16 :
error = F_41 ( V_3 , V_83 , V_84 , V_85 ,
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
F_42 ( V_3 , & V_3 -> V_88 ) ;
}
if ( ! V_85 )
return ( 0 ) ;
ASSERT ( V_3 -> V_88 . V_6 == 0 ) ;
V_83 = & V_3 -> V_88 . V_7 [ 0 ] ;
error = F_43 ( V_3 , V_83 , V_85 ) ;
if ( error ) {
V_85 -> V_8 = NULL ;
return ( error ) ;
}
V_76 = V_83 -> V_8 -> V_31 ;
if ( V_76 -> V_13 . V_14 . V_20 ) {
if ( F_9 ( V_76 -> V_13 . V_14 . V_20 ) == V_85 -> V_36 ) {
V_8 = V_85 -> V_8 ;
} else {
ASSERT ( V_3 -> V_90 ) ;
V_8 = V_3 -> V_93 . V_8 ;
}
V_76 = V_8 -> V_31 ;
V_76 -> V_13 . V_14 . V_21 = F_12 ( V_83 -> V_36 ) ;
F_32 ( V_3 -> args -> V_77 , V_8 ,
F_33 ( V_76 , & V_76 -> V_13 . V_14 ,
sizeof( V_76 -> V_13 . V_14 ) ) ) ;
}
V_76 = V_83 -> V_8 -> V_31 ;
if ( V_76 -> V_13 . V_14 . V_21 ) {
if ( F_9 ( V_76 -> V_13 . V_14 . V_21 ) == V_85 -> V_36 ) {
V_8 = V_85 -> V_8 ;
} else {
ASSERT ( V_3 -> V_90 ) ;
V_8 = V_3 -> V_93 . V_8 ;
}
V_76 = V_8 -> V_31 ;
V_76 -> V_13 . V_14 . V_20 = F_12 ( V_83 -> V_36 ) ;
F_32 ( V_3 -> args -> V_77 , V_8 ,
F_33 ( V_76 , & V_76 -> V_13 . V_14 ,
sizeof( V_76 -> V_13 . V_14 ) ) ) ;
}
V_85 -> V_8 = NULL ;
return ( 0 ) ;
}
STATIC int
F_43 (
struct V_81 * V_3 ,
struct V_82 * V_94 ,
struct V_82 * V_95 )
{
struct V_11 * V_76 ;
struct V_11 * V_96 ;
struct V_97 * V_98 ;
struct V_9 V_99 ;
struct V_74 * args ;
struct V_26 * V_8 ;
struct V_63 * V_64 ;
struct V_61 * V_62 ;
struct V_27 * V_28 ;
struct V_100 * V_101 ;
T_2 V_36 ;
int V_24 ;
int error ;
int V_102 ;
F_44 ( V_3 -> args ) ;
args = V_3 -> args ;
error = F_45 ( args , & V_36 ) ;
if ( error )
return error ;
V_64 = args -> V_64 ;
V_62 = args -> V_77 ;
V_28 = V_3 -> V_28 ;
error = F_30 ( V_62 , V_64 , V_36 , - 1 , & V_8 , args -> V_75 ) ;
if ( error )
return error ;
V_76 = V_8 -> V_31 ;
V_96 = V_94 -> V_8 -> V_31 ;
if ( V_96 -> V_13 . V_14 . V_15 == F_8 ( V_16 ) ||
V_96 -> V_13 . V_14 . V_15 == F_8 ( V_17 ) ) {
struct V_9 V_99 ;
F_7 ( & V_99 , V_96 ) ;
V_98 = F_46 ( V_96 ) ;
V_102 = ( int ) ( ( char * ) & V_98 [ V_99 . V_22 ] - ( char * ) V_96 ) ;
V_24 = V_99 . V_24 ;
F_27 ( V_62 , V_8 , V_71 ) ;
} else {
struct V_103 V_104 ;
struct V_105 * V_106 ;
V_101 = ( V_107 * ) V_96 ;
F_47 ( & V_104 , V_101 ) ;
V_106 = F_48 ( V_101 ) ;
ASSERT ( V_104 . V_15 == V_58 ||
V_104 . V_15 == V_59 ) ;
V_102 = ( int ) ( ( char * ) & V_106 [ V_104 . V_22 ] - ( char * ) V_101 ) ;
V_24 = 0 ;
F_27 ( V_62 , V_8 , V_73 ) ;
}
memcpy ( V_76 , V_96 , V_102 ) ;
if ( V_96 -> V_13 . V_14 . V_15 == F_8 ( V_17 ) ||
V_96 -> V_13 . V_14 . V_15 == F_8 ( V_59 ) ) {
struct V_108 * V_109 = (struct V_108 * ) V_76 ;
V_109 -> V_13 . V_14 . V_36 = F_20 ( V_8 -> V_37 ) ;
}
F_32 ( V_62 , V_8 , 0 , V_102 - 1 ) ;
V_8 -> V_55 = V_94 -> V_8 -> V_55 ;
V_94 -> V_8 = V_8 ;
V_94 -> V_36 = V_36 ;
error = F_28 ( args ,
( args -> V_75 == V_110 ) ? V_28 -> V_111 : 0 ,
V_24 + 1 , & V_8 , args -> V_75 ) ;
if ( error )
return error ;
V_76 = V_8 -> V_31 ;
F_7 ( & V_99 , V_76 ) ;
V_98 = F_46 ( V_76 ) ;
V_98 [ 0 ] . V_112 = F_12 ( V_94 -> V_112 ) ;
V_98 [ 0 ] . V_113 = F_12 ( V_94 -> V_36 ) ;
V_98 [ 1 ] . V_112 = F_12 ( V_95 -> V_112 ) ;
V_98 [ 1 ] . V_113 = F_12 ( V_95 -> V_36 ) ;
V_99 . V_22 = 2 ;
F_11 ( V_76 , & V_99 ) ;
#ifdef F_5
if ( V_96 -> V_13 . V_14 . V_15 == F_8 ( V_58 ) ||
V_96 -> V_13 . V_14 . V_15 == F_8 ( V_59 ) ) {
ASSERT ( V_94 -> V_36 >= V_28 -> V_111 &&
V_94 -> V_36 < V_28 -> V_114 ) ;
ASSERT ( V_95 -> V_36 >= V_28 -> V_111 &&
V_95 -> V_36 < V_28 -> V_114 ) ;
}
#endif
F_32 ( V_62 , V_8 ,
F_33 ( V_76 , V_98 , sizeof( V_115 ) * 2 ) ) ;
return 0 ;
}
STATIC int
F_41 (
struct V_81 * V_3 ,
struct V_82 * V_83 ,
struct V_82 * V_84 ,
struct V_82 * V_85 ,
int V_116 ,
int * V_117 )
{
struct V_11 * V_76 ;
struct V_9 V_99 ;
T_2 V_36 ;
int V_118 ;
int error ;
int V_119 ;
F_49 ( V_3 -> args ) ;
V_76 = V_83 -> V_8 -> V_31 ;
F_7 ( & V_99 , V_76 ) ;
V_119 = V_3 -> V_90 && V_3 -> args -> V_75 == V_120 ;
V_118 = 1 + V_119 ;
if ( V_99 . V_22 + V_118 > V_3 -> V_121 ) {
error = F_45 ( V_3 -> args , & V_36 ) ;
if ( error )
return ( error ) ;
error = F_28 ( V_3 -> args , V_36 , V_116 ,
& V_84 -> V_8 , V_3 -> args -> V_75 ) ;
if ( error )
return ( error ) ;
V_84 -> V_36 = V_36 ;
V_84 -> V_15 = V_16 ;
F_50 ( V_3 , V_83 , V_84 ) ;
error = F_51 ( V_3 , V_83 , V_84 ) ;
if ( error )
return ( error ) ;
* V_117 = 1 ;
} else {
* V_117 = 0 ;
}
V_76 = V_83 -> V_8 -> V_31 ;
F_7 ( & V_99 , V_76 ) ;
if ( V_83 -> V_122 <= V_99 . V_22 ) {
V_83 -> V_122 ++ ;
F_52 ( V_3 , V_83 , V_85 ) ;
if ( V_119 ) {
if ( V_3 -> V_92 )
V_83 -> V_122 ++ ;
F_52 ( V_3 , V_83 , & V_3 -> V_93 ) ;
V_3 -> V_90 = 0 ;
}
} else {
V_84 -> V_122 ++ ;
F_52 ( V_3 , V_84 , V_85 ) ;
if ( V_119 ) {
if ( V_3 -> V_92 )
V_84 -> V_122 ++ ;
F_52 ( V_3 , V_84 , & V_3 -> V_93 ) ;
V_3 -> V_90 = 0 ;
}
}
return ( 0 ) ;
}
STATIC void
F_50 (
struct V_81 * V_3 ,
struct V_82 * V_94 ,
struct V_82 * V_95 )
{
struct V_11 * V_123 ;
struct V_11 * V_124 ;
struct V_11 * V_125 ;
struct V_97 * V_126 ;
struct V_97 * V_127 ;
struct V_97 * V_128 ;
struct V_97 * V_129 ;
struct V_9 V_130 ;
struct V_9 V_131 ;
struct V_61 * V_62 ;
int V_22 ;
int V_132 ;
int V_133 = 0 ;
F_53 ( V_3 -> args ) ;
V_123 = V_94 -> V_8 -> V_31 ;
V_124 = V_95 -> V_8 -> V_31 ;
F_7 ( & V_130 , V_123 ) ;
F_7 ( & V_131 , V_124 ) ;
V_126 = F_46 ( V_123 ) ;
V_127 = F_46 ( V_124 ) ;
if ( V_130 . V_22 > 0 && V_131 . V_22 > 0 &&
( ( F_9 ( V_127 [ 0 ] . V_112 ) < F_9 ( V_126 [ 0 ] . V_112 ) ) ||
( F_9 ( V_127 [ V_131 . V_22 - 1 ] . V_112 ) <
F_9 ( V_126 [ V_130 . V_22 - 1 ] . V_112 ) ) ) ) {
V_125 = V_123 ;
V_123 = V_124 ;
V_124 = V_125 ;
F_7 ( & V_130 , V_123 ) ;
F_7 ( & V_131 , V_124 ) ;
V_126 = F_46 ( V_123 ) ;
V_127 = F_46 ( V_124 ) ;
V_133 = 1 ;
}
V_22 = ( V_130 . V_22 - V_131 . V_22 ) / 2 ;
if ( V_22 == 0 )
return;
V_62 = V_3 -> args -> V_77 ;
if ( V_22 > 0 ) {
V_132 = V_131 . V_22 ;
if ( V_132 > 0 ) {
V_132 *= ( V_134 ) sizeof( V_115 ) ;
V_128 = & V_127 [ 0 ] ;
V_129 = & V_127 [ V_22 ] ;
memmove ( V_129 , V_128 , V_132 ) ;
}
V_131 . V_22 += V_22 ;
V_132 = V_22 * ( V_134 ) sizeof( V_115 ) ;
V_128 = & V_126 [ V_130 . V_22 - V_22 ] ;
V_129 = & V_127 [ 0 ] ;
memcpy ( V_129 , V_128 , V_132 ) ;
V_130 . V_22 -= V_22 ;
} else {
V_22 = - V_22 ;
V_132 = V_22 * ( V_134 ) sizeof( V_115 ) ;
V_128 = & V_127 [ 0 ] ;
V_129 = & V_126 [ V_130 . V_22 ] ;
memcpy ( V_129 , V_128 , V_132 ) ;
V_130 . V_22 += V_22 ;
F_32 ( V_62 , V_94 -> V_8 ,
F_33 ( V_123 , V_129 , V_132 ) ) ;
V_132 = V_131 . V_22 - V_22 ;
V_132 *= ( V_134 ) sizeof( V_115 ) ;
V_128 = & V_127 [ V_22 ] ;
V_129 = & V_127 [ 0 ] ;
memmove ( V_129 , V_128 , V_132 ) ;
V_131 . V_22 -= V_22 ;
}
F_11 ( V_123 , & V_130 ) ;
F_32 ( V_62 , V_94 -> V_8 ,
F_33 ( V_123 , & V_123 -> V_13 ,
F_34 ( V_123 ) ) ) ;
F_11 ( V_124 , & V_131 ) ;
F_32 ( V_62 , V_95 -> V_8 ,
F_33 ( V_124 , & V_124 -> V_13 ,
F_34 ( V_124 ) +
( sizeof( V_127 [ 0 ] ) * V_131 . V_22 ) ) ) ;
if ( V_133 ) {
V_123 = V_94 -> V_8 -> V_31 ;
V_124 = V_95 -> V_8 -> V_31 ;
F_7 ( & V_130 , V_123 ) ;
F_7 ( & V_131 , V_124 ) ;
V_126 = F_46 ( V_123 ) ;
V_127 = F_46 ( V_124 ) ;
}
V_94 -> V_112 = F_9 ( V_126 [ V_130 . V_22 - 1 ] . V_112 ) ;
V_95 -> V_112 = F_9 ( V_127 [ V_131 . V_22 - 1 ] . V_112 ) ;
if ( V_94 -> V_122 >= V_130 . V_22 ) {
V_95 -> V_122 = V_94 -> V_122 - V_130 . V_22 ;
V_94 -> V_122 = V_130 . V_22 + 1 ;
}
}
STATIC void
F_52 (
struct V_81 * V_3 ,
struct V_82 * V_83 ,
struct V_82 * V_84 )
{
struct V_11 * V_76 ;
struct V_9 V_99 ;
struct V_97 * V_98 ;
int V_132 ;
F_54 ( V_3 -> args ) ;
V_76 = V_83 -> V_8 -> V_31 ;
F_7 ( & V_99 , V_76 ) ;
V_98 = F_46 ( V_76 ) ;
ASSERT ( V_83 -> V_122 >= 0 && V_83 -> V_122 <= V_99 . V_22 ) ;
ASSERT ( V_84 -> V_36 != 0 ) ;
if ( V_3 -> args -> V_75 == V_110 )
ASSERT ( V_84 -> V_36 >= V_3 -> V_28 -> V_111 &&
V_84 -> V_36 < V_3 -> V_28 -> V_114 ) ;
V_132 = 0 ;
if ( V_83 -> V_122 < V_99 . V_22 ) {
V_132 = ( V_99 . V_22 - V_83 -> V_122 ) * ( V_134 ) sizeof( * V_98 ) ;
memmove ( & V_98 [ V_83 -> V_122 + 1 ] , & V_98 [ V_83 -> V_122 ] , V_132 ) ;
}
V_98 [ V_83 -> V_122 ] . V_112 = F_12 ( V_84 -> V_112 ) ;
V_98 [ V_83 -> V_122 ] . V_113 = F_12 ( V_84 -> V_36 ) ;
F_32 ( V_3 -> args -> V_77 , V_83 -> V_8 ,
F_33 ( V_76 , & V_98 [ V_83 -> V_122 ] ,
V_132 + sizeof( * V_98 ) ) ) ;
V_99 . V_22 += 1 ;
F_11 ( V_76 , & V_99 ) ;
F_32 ( V_3 -> args -> V_77 , V_83 -> V_8 ,
F_33 ( V_76 , & V_76 -> V_13 , F_34 ( V_76 ) ) ) ;
V_83 -> V_112 = F_9 ( V_98 [ V_99 . V_22 - 1 ] . V_112 ) ;
}
int
F_55 (
struct V_81 * V_3 )
{
struct V_82 * V_135 ;
struct V_82 * V_136 ;
int V_87 = 0 ;
int error ;
F_56 ( V_3 -> args ) ;
V_135 = & V_3 -> V_88 . V_7 [ V_3 -> V_88 . V_6 - 1 ] ;
V_136 = & V_3 -> V_5 . V_7 [ V_3 -> V_88 . V_6 - 1 ] ;
ASSERT ( V_3 -> V_88 . V_7 [ 0 ] . V_15 == V_16 ) ;
ASSERT ( V_135 -> V_15 == V_53 ||
V_135 -> V_15 == V_58 ) ;
for ( ; V_3 -> V_88 . V_6 >= 2 ; V_135 -- , V_136 -- ,
V_3 -> V_88 . V_6 -- ) {
switch ( V_135 -> V_15 ) {
case V_53 :
error = F_57 ( V_3 , & V_87 ) ;
if ( error )
return ( error ) ;
if ( V_87 == 0 )
return ( 0 ) ;
F_58 ( V_3 , V_135 , V_136 ) ;
break;
case V_58 :
error = F_59 ( V_3 , & V_87 ) ;
if ( error )
return error ;
if ( V_87 == 0 )
return 0 ;
F_60 ( V_3 , V_135 , V_136 ) ;
break;
case V_16 :
F_61 ( V_3 , V_135 ) ;
F_42 ( V_3 , & V_3 -> V_88 ) ;
error = F_62 ( V_3 , & V_87 ) ;
if ( error )
return ( error ) ;
if ( V_87 == 0 )
return 0 ;
F_63 ( V_3 , V_135 , V_136 ) ;
break;
}
F_42 ( V_3 , & V_3 -> V_5 ) ;
error = F_64 ( V_3 , V_135 , V_136 ) ;
F_3 ( V_3 ) ;
if ( error )
return ( error ) ;
error = F_65 ( V_3 -> args , V_135 -> V_36 ,
V_135 -> V_8 ) ;
V_135 -> V_8 = NULL ;
if ( error )
return ( error ) ;
}
F_61 ( V_3 , V_135 ) ;
F_42 ( V_3 , & V_3 -> V_88 ) ;
error = F_66 ( V_3 , & V_3 -> V_88 . V_7 [ 0 ] ) ;
return ( error ) ;
}
static void
F_67 ( struct V_52 * V_137 , T_4 V_24 )
{
T_5 V_15 = V_137 -> V_15 ;
if ( V_24 == 1 ) {
ASSERT ( V_15 == F_8 ( V_58 ) ||
V_15 == F_8 ( V_59 ) ||
V_15 == F_8 ( V_53 ) ||
V_15 == F_8 ( V_54 ) ) ;
} else {
ASSERT ( V_15 == F_8 ( V_16 ) ||
V_15 == F_8 ( V_17 ) ) ;
}
ASSERT ( ! V_137 -> V_20 ) ;
ASSERT ( ! V_137 -> V_21 ) ;
}
STATIC int
F_66 (
struct V_81 * V_3 ,
struct V_82 * V_138 )
{
struct V_11 * V_96 ;
struct V_74 * args ;
T_2 V_139 ;
struct V_26 * V_8 ;
struct V_9 V_140 ;
struct V_97 * V_98 ;
int error ;
F_68 ( V_3 -> args ) ;
ASSERT ( V_138 -> V_15 == V_16 ) ;
args = V_3 -> args ;
V_96 = V_138 -> V_8 -> V_31 ;
F_7 ( & V_140 , V_96 ) ;
ASSERT ( V_140 . V_20 == 0 ) ;
ASSERT ( V_140 . V_21 == 0 ) ;
if ( V_140 . V_22 > 1 )
return 0 ;
V_98 = F_46 ( V_96 ) ;
V_139 = F_9 ( V_98 [ 0 ] . V_113 ) ;
ASSERT ( V_139 != 0 ) ;
error = F_25 ( args -> V_77 , args -> V_64 , V_139 , - 1 , & V_8 ,
args -> V_75 ) ;
if ( error )
return error ;
F_67 ( V_8 -> V_31 , V_140 . V_24 ) ;
memcpy ( V_138 -> V_8 -> V_31 , V_8 -> V_31 , V_3 -> V_141 ) ;
V_138 -> V_8 -> V_55 = V_8 -> V_55 ;
F_69 ( V_138 -> V_8 , V_8 ) ;
if ( V_140 . V_15 == V_17 ) {
struct V_142 * V_143 = V_138 -> V_8 -> V_31 ;
V_143 -> V_36 = F_20 ( V_138 -> V_8 -> V_37 ) ;
}
F_32 ( args -> V_77 , V_138 -> V_8 , 0 , V_3 -> V_141 - 1 ) ;
error = F_65 ( args , V_139 , V_8 ) ;
return ( error ) ;
}
STATIC int
F_62 (
struct V_81 * V_3 ,
int * V_87 )
{
struct V_11 * V_76 ;
struct V_82 * V_7 ;
struct V_52 * V_14 ;
T_2 V_36 ;
struct V_26 * V_8 ;
struct V_9 V_99 ;
int V_22 ;
int V_144 ;
int error ;
int V_145 ;
int V_4 ;
F_70 ( V_3 -> args ) ;
V_7 = & V_3 -> V_88 . V_7 [ V_3 -> V_88 . V_6 - 1 ] ;
V_14 = V_7 -> V_8 -> V_31 ;
V_76 = ( V_146 * ) V_14 ;
F_7 ( & V_99 , V_76 ) ;
if ( V_99 . V_22 > ( V_3 -> V_121 >> 1 ) ) {
* V_87 = 0 ;
return ( 0 ) ;
}
if ( V_99 . V_22 == 0 ) {
V_144 = ( V_14 -> V_20 != 0 ) ;
memcpy ( & V_3 -> V_5 , & V_3 -> V_88 , sizeof( V_3 -> V_88 ) ) ;
error = F_71 ( V_3 , & V_3 -> V_5 , V_144 ,
0 , & V_145 ) ;
if ( error )
return ( error ) ;
if ( V_145 ) {
* V_87 = 0 ;
} else {
* V_87 = 2 ;
}
return ( 0 ) ;
}
V_22 = V_3 -> V_121 ;
V_22 -= V_3 -> V_121 >> 2 ;
V_22 -= V_99 . V_22 ;
V_144 = V_99 . V_20 < V_99 . V_21 ;
for ( V_4 = 0 ; V_4 < 2 ; V_144 = ! V_144 , V_4 ++ ) {
if ( V_144 )
V_36 = V_99 . V_20 ;
else
V_36 = V_99 . V_21 ;
if ( V_36 == 0 )
continue;
error = F_25 ( V_3 -> args -> V_77 , V_3 -> args -> V_64 ,
V_36 , - 1 , & V_8 , V_3 -> args -> V_75 ) ;
if ( error )
return ( error ) ;
V_76 = V_8 -> V_31 ;
F_7 ( & V_99 , V_76 ) ;
F_72 ( V_3 -> args -> V_77 , V_8 ) ;
if ( V_22 - V_99 . V_22 >= 0 )
break;
}
if ( V_4 >= 2 ) {
* V_87 = 0 ;
return 0 ;
}
memcpy ( & V_3 -> V_5 , & V_3 -> V_88 , sizeof( V_3 -> V_88 ) ) ;
if ( V_36 < V_7 -> V_36 ) {
error = F_71 ( V_3 , & V_3 -> V_5 , V_144 ,
0 , & V_145 ) ;
} else {
error = F_71 ( V_3 , & V_3 -> V_88 , V_144 ,
0 , & V_145 ) ;
}
if ( error )
return error ;
if ( V_145 ) {
* V_87 = 0 ;
return 0 ;
}
* V_87 = 1 ;
return 0 ;
}
STATIC V_134
F_73 (
struct V_26 * V_8 ,
int * V_22 )
{
struct V_11 * V_76 ;
struct V_97 * V_98 ;
struct V_9 V_99 ;
V_76 = V_8 -> V_31 ;
F_7 ( & V_99 , V_76 ) ;
if ( V_22 )
* V_22 = V_99 . V_22 ;
if ( ! V_99 . V_22 )
return 0 ;
V_98 = F_46 ( V_76 ) ;
return F_9 ( V_98 [ V_99 . V_22 - 1 ] . V_112 ) ;
}
void
F_42 (
struct V_81 * V_3 ,
struct V_147 * V_88 )
{
struct V_82 * V_7 ;
struct V_11 * V_76 ;
struct V_97 * V_98 ;
T_6 V_148 = 0 ;
int V_24 ;
int V_22 ;
F_74 ( V_3 -> args ) ;
V_24 = V_88 -> V_6 - 1 ;
V_7 = & V_88 -> V_7 [ V_24 ] ;
switch ( V_7 -> V_15 ) {
case V_53 :
V_148 = F_75 ( V_7 -> V_8 , & V_22 ) ;
if ( V_22 == 0 )
return;
break;
case V_58 :
V_148 = F_76 ( V_7 -> V_8 , & V_22 ) ;
if ( V_22 == 0 )
return;
break;
case V_16 :
V_148 = F_73 ( V_7 -> V_8 , & V_22 ) ;
if ( V_22 == 0 )
return;
break;
}
for ( V_7 -- , V_24 -- ; V_24 >= 0 ; V_7 -- , V_24 -- ) {
struct V_9 V_99 ;
V_76 = V_7 -> V_8 -> V_31 ;
F_7 ( & V_99 , V_76 ) ;
V_98 = F_46 ( V_76 ) ;
if ( F_9 ( V_98 -> V_112 ) == V_148 )
break;
V_7 -> V_112 = V_148 ;
V_98 [ V_7 -> V_122 ] . V_112 = F_12 ( V_148 ) ;
F_32 ( V_3 -> args -> V_77 , V_7 -> V_8 ,
F_33 ( V_76 , & V_98 [ V_7 -> V_122 ] ,
sizeof( * V_98 ) ) ) ;
V_148 = F_9 ( V_98 [ V_99 . V_22 - 1 ] . V_112 ) ;
}
}
STATIC void
F_61 (
struct V_81 * V_3 ,
struct V_82 * V_135 )
{
struct V_11 * V_76 ;
struct V_9 V_99 ;
struct V_97 * V_98 ;
int V_122 ;
int V_132 ;
F_77 ( V_3 -> args ) ;
V_76 = V_135 -> V_8 -> V_31 ;
F_7 ( & V_99 , V_76 ) ;
ASSERT ( V_135 -> V_122 < V_99 . V_22 ) ;
ASSERT ( V_135 -> V_122 >= 0 ) ;
V_122 = V_135 -> V_122 ;
V_98 = F_46 ( V_76 ) ;
if ( V_122 < V_99 . V_22 - 1 ) {
V_132 = V_99 . V_22 - V_122 - 1 ;
V_132 *= ( V_134 ) sizeof( V_115 ) ;
memmove ( & V_98 [ V_122 ] , & V_98 [ V_122 + 1 ] , V_132 ) ;
F_32 ( V_3 -> args -> V_77 , V_135 -> V_8 ,
F_33 ( V_76 , & V_98 [ V_122 ] , V_132 ) ) ;
V_122 = V_99 . V_22 - 1 ;
}
memset ( & V_98 [ V_122 ] , 0 , sizeof( V_115 ) ) ;
F_32 ( V_3 -> args -> V_77 , V_135 -> V_8 ,
F_33 ( V_76 , & V_98 [ V_122 ] , sizeof( V_98 [ V_122 ] ) ) ) ;
V_99 . V_22 -= 1 ;
F_11 ( V_76 , & V_99 ) ;
F_32 ( V_3 -> args -> V_77 , V_135 -> V_8 ,
F_33 ( V_76 , & V_76 -> V_13 , F_34 ( V_76 ) ) ) ;
V_135 -> V_112 = F_9 ( V_98 [ V_122 - 1 ] . V_112 ) ;
}
STATIC void
F_63 (
struct V_81 * V_3 ,
struct V_82 * V_135 ,
struct V_82 * V_136 )
{
struct V_11 * V_149 ;
struct V_11 * V_150 ;
struct V_97 * V_151 ;
struct V_97 * V_152 ;
struct V_9 V_153 ;
struct V_9 V_154 ;
struct V_61 * V_62 ;
int V_155 ;
int V_132 ;
F_78 ( V_3 -> args ) ;
V_149 = V_135 -> V_8 -> V_31 ;
V_150 = V_136 -> V_8 -> V_31 ;
F_7 ( & V_153 , V_149 ) ;
F_7 ( & V_154 , V_150 ) ;
V_151 = F_46 ( V_149 ) ;
V_152 = F_46 ( V_150 ) ;
V_62 = V_3 -> args -> V_77 ;
if ( ( F_9 ( V_151 [ 0 ] . V_112 ) <
F_9 ( V_152 [ 0 ] . V_112 ) ) ||
( F_9 ( V_151 [ V_153 . V_22 - 1 ] . V_112 ) <
F_9 ( V_152 [ V_154 . V_22 - 1 ] . V_112 ) ) ) {
V_132 = V_154 . V_22 * sizeof( V_115 ) ;
memmove ( & V_152 [ V_153 . V_22 ] , & V_152 [ 0 ] , V_132 ) ;
V_155 = 0 ;
F_32 ( V_62 , V_136 -> V_8 ,
F_33 ( V_150 , & V_152 [ 0 ] ,
( V_154 . V_22 + V_153 . V_22 ) *
sizeof( V_115 ) ) ) ;
} else {
V_155 = V_154 . V_22 ;
F_32 ( V_62 , V_136 -> V_8 ,
F_33 ( V_150 , & V_152 [ V_155 ] ,
V_153 . V_22 * sizeof( V_115 ) ) ) ;
}
V_132 = V_153 . V_22 * ( V_134 ) sizeof( V_115 ) ;
memcpy ( & V_152 [ V_155 ] , & V_151 [ 0 ] , V_132 ) ;
V_154 . V_22 += V_153 . V_22 ;
F_11 ( V_150 , & V_154 ) ;
F_32 ( V_62 , V_136 -> V_8 ,
F_33 ( V_150 , & V_150 -> V_13 ,
F_34 ( V_150 ) ) ) ;
V_136 -> V_112 = F_9 ( V_152 [ V_154 . V_22 - 1 ] . V_112 ) ;
}
int
F_79 (
struct V_81 * V_3 ,
int * V_117 )
{
struct V_82 * V_7 ;
struct V_52 * V_156 ;
struct V_11 * V_76 ;
struct V_97 * V_98 ;
struct V_9 V_99 ;
struct V_74 * args ;
T_2 V_36 ;
T_6 V_112 ;
T_6 V_157 ;
int V_158 ;
int V_159 ;
int V_86 ;
int error ;
int V_145 ;
args = V_3 -> args ;
V_36 = ( args -> V_75 == V_110 ) ? V_3 -> V_28 -> V_111 : 0 ;
for ( V_7 = & V_3 -> V_88 . V_7 [ 0 ] , V_3 -> V_88 . V_6 = 1 ;
V_3 -> V_88 . V_6 <= V_38 ;
V_7 ++ , V_3 -> V_88 . V_6 ++ ) {
V_7 -> V_36 = V_36 ;
error = F_25 ( args -> V_77 , args -> V_64 , V_36 ,
- 1 , & V_7 -> V_8 , args -> V_75 ) ;
if ( error ) {
V_7 -> V_36 = 0 ;
V_3 -> V_88 . V_6 -- ;
return ( error ) ;
}
V_156 = V_7 -> V_8 -> V_31 ;
V_7 -> V_15 = F_10 ( V_156 -> V_15 ) ;
if ( V_7 -> V_15 == V_53 ||
V_7 -> V_15 == V_54 ) {
V_7 -> V_15 = V_53 ;
V_7 -> V_112 = F_75 ( V_7 -> V_8 , NULL ) ;
break;
}
if ( V_7 -> V_15 == V_58 ||
V_7 -> V_15 == V_59 ) {
V_7 -> V_15 = V_58 ;
V_7 -> V_112 = F_76 ( V_7 -> V_8 , NULL ) ;
break;
}
V_7 -> V_15 = V_16 ;
V_76 = V_7 -> V_8 -> V_31 ;
F_7 ( & V_99 , V_76 ) ;
V_98 = F_46 ( V_76 ) ;
V_86 = V_99 . V_22 ;
V_7 -> V_112 = F_9 ( V_98 [ V_86 - 1 ] . V_112 ) ;
V_158 = V_159 = V_86 / 2 ;
V_112 = args -> V_112 ;
while ( V_159 > 4 ) {
V_159 /= 2 ;
V_157 = F_9 ( V_98 [ V_158 ] . V_112 ) ;
if ( V_157 < V_112 )
V_158 += V_159 ;
else if ( V_157 > V_112 )
V_158 -= V_159 ;
else
break;
}
ASSERT ( ( V_158 >= 0 ) && ( V_158 < V_86 ) ) ;
ASSERT ( ( V_159 <= 4 ) ||
( F_9 ( V_98 [ V_158 ] . V_112 ) == V_112 ) ) ;
while ( V_158 > 0 &&
F_9 ( V_98 [ V_158 ] . V_112 ) >= V_112 ) {
V_158 -- ;
}
while ( V_158 < V_86 &&
F_9 ( V_98 [ V_158 ] . V_112 ) < V_112 ) {
V_158 ++ ;
}
if ( V_158 == V_86 ) {
V_7 -> V_122 = V_86 - 1 ;
V_36 = F_9 ( V_98 [ V_86 - 1 ] . V_113 ) ;
} else {
V_7 -> V_122 = V_158 ;
V_36 = F_9 ( V_98 [ V_158 ] . V_113 ) ;
}
}
for (; ; ) {
if ( V_7 -> V_15 == V_58 ) {
V_145 = F_80 ( V_7 -> V_8 , args ,
& V_7 -> V_122 , V_3 ) ;
} else if ( V_7 -> V_15 == V_53 ) {
V_145 = F_81 ( V_7 -> V_8 , args ) ;
V_7 -> V_122 = args -> V_122 ;
args -> V_36 = V_7 -> V_36 ;
} else {
ASSERT ( 0 ) ;
return F_82 ( V_46 ) ;
}
if ( ( ( V_145 == V_160 ) || ( V_145 == V_161 ) ) &&
( V_7 -> V_112 == args -> V_112 ) ) {
error = F_71 ( V_3 , & V_3 -> V_88 , 1 , 1 ,
& V_145 ) ;
if ( error )
return ( error ) ;
if ( V_145 == 0 ) {
continue;
} else if ( V_7 -> V_15 == V_53 ) {
V_145 = F_82 ( V_161 ) ;
}
}
break;
}
* V_117 = V_145 ;
return ( 0 ) ;
}
STATIC int
F_83 (
struct V_26 * V_162 ,
struct V_26 * V_163 )
{
struct V_11 * V_123 ;
struct V_11 * V_124 ;
struct V_97 * V_126 ;
struct V_97 * V_127 ;
struct V_9 V_164 ;
struct V_9 V_165 ;
V_123 = V_162 -> V_31 ;
V_124 = V_163 -> V_31 ;
F_7 ( & V_164 , V_123 ) ;
F_7 ( & V_165 , V_124 ) ;
V_126 = F_46 ( V_123 ) ;
V_127 = F_46 ( V_124 ) ;
if ( V_164 . V_22 > 0 && V_165 . V_22 > 0 &&
( ( F_9 ( V_127 [ 0 ] . V_112 ) < F_9 ( V_126 [ 0 ] . V_112 ) ) ||
( F_9 ( V_127 [ V_165 . V_22 - 1 ] . V_112 ) <
F_9 ( V_126 [ V_164 . V_22 - 1 ] . V_112 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_51 (
struct V_81 * V_3 ,
struct V_82 * V_166 ,
struct V_82 * V_167 )
{
struct V_52 * V_168 ;
struct V_52 * V_169 ;
struct V_52 * V_170 ;
struct V_74 * args ;
struct V_26 * V_8 ;
int V_113 = 0 ;
int error ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
V_168 = V_166 -> V_8 -> V_31 ;
V_169 = V_167 -> V_8 -> V_31 ;
ASSERT ( V_166 -> V_15 == V_16 ||
V_166 -> V_15 == V_58 ||
V_166 -> V_15 == V_53 ) ;
switch ( V_166 -> V_15 ) {
case V_53 :
V_113 = F_84 ( V_166 -> V_8 , V_167 -> V_8 ) ;
break;
case V_58 :
V_113 = F_85 ( V_166 -> V_8 , V_167 -> V_8 ) ;
break;
case V_16 :
V_113 = F_83 ( V_166 -> V_8 , V_167 -> V_8 ) ;
break;
}
if ( V_113 ) {
F_86 ( args ) ;
V_169 -> V_20 = F_12 ( V_166 -> V_36 ) ;
V_169 -> V_21 = V_168 -> V_21 ;
if ( V_168 -> V_21 ) {
error = F_25 ( args -> V_77 , args -> V_64 ,
F_9 ( V_168 -> V_21 ) ,
- 1 , & V_8 , args -> V_75 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_170 = V_8 -> V_31 ;
ASSERT ( V_170 -> V_15 == V_168 -> V_15 ) ;
ASSERT ( F_9 ( V_170 -> V_20 ) == V_166 -> V_36 ) ;
V_170 -> V_20 = F_12 ( V_167 -> V_36 ) ;
F_32 ( args -> V_77 , V_8 , 0 , sizeof( * V_170 ) - 1 ) ;
}
V_168 -> V_21 = F_12 ( V_167 -> V_36 ) ;
} else {
F_87 ( args ) ;
V_169 -> V_20 = V_168 -> V_20 ;
V_169 -> V_21 = F_12 ( V_166 -> V_36 ) ;
if ( V_168 -> V_20 ) {
error = F_25 ( args -> V_77 , args -> V_64 ,
F_9 ( V_168 -> V_20 ) ,
- 1 , & V_8 , args -> V_75 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_170 = V_8 -> V_31 ;
ASSERT ( V_170 -> V_15 == V_168 -> V_15 ) ;
ASSERT ( F_9 ( V_170 -> V_21 ) == V_166 -> V_36 ) ;
V_170 -> V_21 = F_12 ( V_167 -> V_36 ) ;
F_32 ( args -> V_77 , V_8 , 0 , sizeof( * V_170 ) - 1 ) ;
}
V_168 -> V_20 = F_12 ( V_167 -> V_36 ) ;
}
F_32 ( args -> V_77 , V_166 -> V_8 , 0 , sizeof( * V_170 ) - 1 ) ;
F_32 ( args -> V_77 , V_167 -> V_8 , 0 , sizeof( * V_170 ) - 1 ) ;
return ( 0 ) ;
}
STATIC int
F_64 (
struct V_81 * V_3 ,
struct V_82 * V_135 ,
struct V_82 * V_136 )
{
struct V_52 * V_171 ;
struct V_52 * V_172 ;
struct V_52 * V_170 ;
struct V_74 * args ;
struct V_26 * V_8 ;
int error ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
V_172 = V_136 -> V_8 -> V_31 ;
V_171 = V_135 -> V_8 -> V_31 ;
ASSERT ( V_136 -> V_15 == V_16 ||
V_136 -> V_15 == V_58 ||
V_136 -> V_15 == V_53 ) ;
ASSERT ( V_136 -> V_15 == V_135 -> V_15 ) ;
ASSERT ( ( F_9 ( V_172 -> V_20 ) == V_135 -> V_36 ) ||
( F_9 ( V_172 -> V_21 ) == V_135 -> V_36 ) ) ;
ASSERT ( ( F_9 ( V_171 -> V_20 ) == V_136 -> V_36 ) ||
( F_9 ( V_171 -> V_21 ) == V_136 -> V_36 ) ) ;
if ( F_9 ( V_172 -> V_21 ) == V_135 -> V_36 ) {
F_88 ( args ) ;
V_172 -> V_21 = V_171 -> V_21 ;
if ( V_171 -> V_21 ) {
error = F_25 ( args -> V_77 , args -> V_64 ,
F_9 ( V_171 -> V_21 ) ,
- 1 , & V_8 , args -> V_75 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_170 = V_8 -> V_31 ;
ASSERT ( V_170 -> V_15 == V_172 -> V_15 ) ;
ASSERT ( F_9 ( V_170 -> V_20 ) == V_135 -> V_36 ) ;
V_170 -> V_20 = F_12 ( V_136 -> V_36 ) ;
F_32 ( args -> V_77 , V_8 , 0 ,
sizeof( * V_170 ) - 1 ) ;
}
} else {
F_89 ( args ) ;
V_172 -> V_20 = V_171 -> V_20 ;
if ( V_171 -> V_20 ) {
error = F_25 ( args -> V_77 , args -> V_64 ,
F_9 ( V_171 -> V_20 ) ,
- 1 , & V_8 , args -> V_75 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_170 = V_8 -> V_31 ;
ASSERT ( V_170 -> V_15 == V_172 -> V_15 ) ;
ASSERT ( F_9 ( V_170 -> V_21 ) == V_135 -> V_36 ) ;
V_170 -> V_21 = F_12 ( V_136 -> V_36 ) ;
F_32 ( args -> V_77 , V_8 , 0 ,
sizeof( * V_170 ) - 1 ) ;
}
}
F_32 ( args -> V_77 , V_136 -> V_8 , 0 , sizeof( * V_172 ) - 1 ) ;
return ( 0 ) ;
}
int
F_71 (
struct V_81 * V_3 ,
struct V_147 * V_88 ,
int V_144 ,
int V_173 ,
int * V_117 )
{
struct V_82 * V_7 ;
struct V_52 * V_14 ;
struct V_11 * V_76 ;
struct V_74 * args ;
struct V_97 * V_98 ;
struct V_9 V_99 ;
T_2 V_36 = 0 ;
int V_24 ;
int error ;
F_90 ( V_3 -> args ) ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
ASSERT ( V_88 != NULL ) ;
ASSERT ( ( V_88 -> V_6 > 0 ) && ( V_88 -> V_6 < V_38 ) ) ;
V_24 = ( V_88 -> V_6 - 1 ) - 1 ;
for ( V_7 = & V_88 -> V_7 [ V_24 ] ; V_24 >= 0 ; V_7 -- , V_24 -- ) {
V_76 = V_7 -> V_8 -> V_31 ;
F_7 ( & V_99 , V_76 ) ;
V_98 = F_46 ( V_76 ) ;
if ( V_144 && ( V_7 -> V_122 < V_99 . V_22 - 1 ) ) {
V_7 -> V_122 ++ ;
V_36 = F_9 ( V_98 [ V_7 -> V_122 ] . V_113 ) ;
break;
} else if ( ! V_144 && ( V_7 -> V_122 > 0 ) ) {
V_7 -> V_122 -- ;
V_36 = F_9 ( V_98 [ V_7 -> V_122 ] . V_113 ) ;
break;
}
}
if ( V_24 < 0 ) {
* V_117 = F_82 ( V_160 ) ;
ASSERT ( args -> V_174 & V_175 ) ;
return ( 0 ) ;
}
for ( V_7 ++ , V_24 ++ ; V_24 < V_88 -> V_6 ; V_7 ++ , V_24 ++ ) {
if ( V_173 )
F_72 ( args -> V_77 , V_7 -> V_8 ) ;
V_7 -> V_36 = V_36 ;
error = F_25 ( args -> V_77 , args -> V_64 , V_36 , - 1 ,
& V_7 -> V_8 , args -> V_75 ) ;
if ( error )
return ( error ) ;
V_14 = V_7 -> V_8 -> V_31 ;
ASSERT ( V_14 -> V_15 == F_8 ( V_16 ) ||
V_14 -> V_15 == F_8 ( V_17 ) ||
V_14 -> V_15 == F_8 ( V_58 ) ||
V_14 -> V_15 == F_8 ( V_59 ) ||
V_14 -> V_15 == F_8 ( V_53 ) ||
V_14 -> V_15 == F_8 ( V_54 ) ) ;
switch ( F_10 ( V_14 -> V_15 ) ) {
case V_16 :
case V_17 :
V_7 -> V_15 = V_16 ;
V_76 = ( V_146 * ) V_14 ;
F_7 ( & V_99 , V_76 ) ;
V_98 = F_46 ( V_76 ) ;
V_7 -> V_112 = F_9 ( V_98 [ V_99 . V_22 - 1 ] . V_112 ) ;
if ( V_144 )
V_7 -> V_122 = 0 ;
else
V_7 -> V_122 = V_99 . V_22 - 1 ;
V_36 = F_9 ( V_98 [ V_7 -> V_122 ] . V_113 ) ;
break;
case V_53 :
case V_54 :
V_7 -> V_15 = V_53 ;
ASSERT ( V_24 == V_88 -> V_6 - 1 ) ;
V_7 -> V_122 = 0 ;
V_7 -> V_112 = F_75 ( V_7 -> V_8 ,
NULL ) ;
break;
case V_58 :
case V_59 :
V_7 -> V_15 = V_58 ;
ASSERT ( V_24 == V_88 -> V_6 - 1 ) ;
V_7 -> V_122 = 0 ;
V_7 -> V_112 = F_76 ( V_7 -> V_8 ,
NULL ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
}
* V_117 = 0 ;
return 0 ;
}
T_6
F_91 ( const T_7 * V_176 , int V_177 )
{
T_6 V_178 ;
for ( V_178 = 0 ; V_177 >= 4 ; V_177 -= 4 , V_176 += 4 )
V_178 = ( V_176 [ 0 ] << 21 ) ^ ( V_176 [ 1 ] << 14 ) ^ ( V_176 [ 2 ] << 7 ) ^
( V_176 [ 3 ] << 0 ) ^ F_92 ( V_178 , 7 * 4 ) ;
switch ( V_177 ) {
case 3 :
return ( V_176 [ 0 ] << 14 ) ^ ( V_176 [ 1 ] << 7 ) ^ ( V_176 [ 2 ] << 0 ) ^
F_92 ( V_178 , 7 * 3 ) ;
case 2 :
return ( V_176 [ 0 ] << 7 ) ^ ( V_176 [ 1 ] << 0 ) ^ F_92 ( V_178 , 7 * 2 ) ;
case 1 :
return ( V_176 [ 0 ] << 0 ) ^ F_92 ( V_178 , 7 * 1 ) ;
default:
return V_178 ;
}
}
enum V_179
F_93 (
struct V_74 * args ,
const unsigned char * V_176 ,
int V_180 )
{
return ( args -> V_177 == V_180 && memcmp ( args -> V_176 , V_176 , V_180 ) == 0 ) ?
V_181 : V_182 ;
}
static T_6
F_94 (
struct V_183 * V_176 )
{
return F_91 ( V_176 -> V_176 , V_176 -> V_180 ) ;
}
int
F_95 (
struct V_74 * args ,
T_8 * V_65 ,
int V_22 )
{
struct V_61 * V_62 = args -> V_77 ;
struct V_63 * V_64 = args -> V_64 ;
int V_184 = args -> V_75 ;
T_9 V_185 = V_64 -> V_186 . V_187 ;
struct V_188 V_189 , * V_190 ;
int V_191 , error , V_192 , V_4 , V_193 ;
error = F_96 ( V_62 , V_64 , V_22 , V_65 , V_184 ) ;
if ( error )
return error ;
V_191 = 1 ;
ASSERT ( args -> V_194 != NULL ) ;
error = F_97 ( V_62 , V_64 , * V_65 , V_22 ,
F_98 ( V_184 ) | V_195 | V_196 ,
args -> V_194 , args -> V_197 , & V_189 , & V_191 ,
args -> V_198 ) ;
if ( error )
return error ;
ASSERT ( V_191 <= 1 ) ;
if ( V_191 == 1 ) {
V_190 = & V_189 ;
V_193 = 1 ;
} else if ( V_191 == 0 && V_22 > 1 ) {
T_8 V_199 ;
int V_200 ;
V_190 = F_99 ( sizeof( * V_190 ) * V_22 , V_201 ) ;
for ( V_199 = * V_65 , V_193 = 0 ; V_199 < * V_65 + V_22 ; ) {
V_191 = F_100 ( V_202 , V_22 ) ;
V_200 = ( int ) ( * V_65 + V_22 - V_199 ) ;
error = F_97 ( V_62 , V_64 , V_199 , V_200 ,
F_98 ( V_184 ) | V_195 ,
args -> V_194 , args -> V_197 ,
& V_190 [ V_193 ] , & V_191 , args -> V_198 ) ;
if ( error )
goto V_203;
if ( V_191 < 1 )
break;
V_193 += V_191 ;
V_199 = V_190 [ V_193 - 1 ] . V_204 +
V_190 [ V_193 - 1 ] . V_205 ;
}
} else {
V_193 = 0 ;
V_190 = NULL ;
}
for ( V_4 = 0 , V_192 = 0 ; V_4 < V_193 ; V_4 ++ )
V_192 += V_190 [ V_4 ] . V_205 ;
if ( V_192 != V_22 || V_190 [ 0 ] . V_204 != * V_65 ||
V_190 [ V_193 - 1 ] . V_204 + V_190 [ V_193 - 1 ] . V_205 !=
* V_65 + V_22 ) {
error = F_82 ( V_89 ) ;
goto V_203;
}
args -> V_197 -= V_64 -> V_186 . V_187 - V_185 ;
V_203:
if ( V_190 != & V_189 )
F_101 ( V_190 ) ;
return error ;
}
int
F_45 (
struct V_74 * args ,
T_2 * V_206 )
{
T_8 V_65 ;
int V_22 ;
int error ;
F_102 ( args ) ;
if ( args -> V_75 == V_110 ) {
V_65 = args -> V_64 -> V_207 -> V_111 ;
V_22 = args -> V_64 -> V_207 -> V_208 ;
} else {
V_65 = 0 ;
V_22 = 1 ;
}
error = F_95 ( args , & V_65 , V_22 ) ;
if ( ! error )
* V_206 = ( T_2 ) V_65 ;
return error ;
}
STATIC int
F_103 (
struct V_74 * args ,
T_2 * V_209 ,
struct V_26 * * V_210 )
{
struct V_52 * V_211 ;
struct V_52 * V_212 ;
struct V_11 * V_213 ;
struct V_11 * V_214 ;
struct V_100 * V_215 ;
struct V_97 * V_98 ;
struct V_9 V_216 ;
struct V_63 * V_217 ;
struct V_61 * V_62 ;
struct V_27 * V_28 ;
struct V_26 * V_218 ;
struct V_26 * V_219 ;
struct V_26 * V_220 ;
struct V_26 * V_221 ;
T_6 V_222 ;
T_8 V_223 ;
T_2 V_224 ;
T_2 V_225 ;
T_2 V_226 ;
T_2 V_227 ;
int error ;
int V_184 ;
int V_228 ;
int V_24 ;
int V_229 ;
F_104 ( args ) ;
V_218 = * V_210 ;
V_224 = * V_209 ;
V_62 = args -> V_77 ;
V_217 = args -> V_64 ;
V_184 = args -> V_75 ;
ASSERT ( V_184 == V_110 ) ;
V_28 = V_217 -> V_207 ;
V_223 = V_28 -> V_114 ;
error = F_105 ( V_62 , V_217 , & V_223 , V_184 ) ;
if ( error )
return error ;
if ( F_106 ( V_223 == 0 ) ) {
F_107 ( L_1 , V_45 ,
V_28 ) ;
return F_82 ( V_46 ) ;
}
V_225 = ( T_2 ) V_223 - V_28 -> V_208 ;
error = F_25 ( V_62 , V_217 , V_225 , - 1 , & V_219 , V_184 ) ;
if ( error )
return error ;
memcpy ( V_218 -> V_31 , V_219 -> V_31 , V_28 -> V_230 ) ;
F_32 ( V_62 , V_218 , 0 , V_28 -> V_230 - 1 ) ;
V_211 = V_218 -> V_31 ;
if ( V_211 -> V_15 == F_8 ( V_58 ) ||
V_211 -> V_15 == F_8 ( V_59 ) ) {
struct V_103 V_104 ;
struct V_105 * V_106 ;
V_215 = ( V_107 * ) V_211 ;
F_47 ( & V_104 , V_215 ) ;
V_106 = F_48 ( V_215 ) ;
V_229 = 0 ;
V_222 = F_9 ( V_106 [ V_104 . V_22 - 1 ] . V_112 ) ;
} else {
struct V_9 V_231 ;
V_214 = ( V_146 * ) V_211 ;
F_7 ( & V_231 , V_214 ) ;
V_98 = F_46 ( V_214 ) ;
V_229 = V_231 . V_24 ;
V_222 = F_9 ( V_98 [ V_231 . V_22 - 1 ] . V_112 ) ;
}
V_220 = V_221 = NULL ;
if ( ( V_226 = F_9 ( V_211 -> V_21 ) ) ) {
error = F_25 ( V_62 , V_217 , V_226 , - 1 , & V_220 , V_184 ) ;
if ( error )
goto V_232;
V_212 = V_220 -> V_31 ;
if ( F_106 (
F_9 ( V_212 -> V_20 ) != V_225 ||
V_212 -> V_15 != V_211 -> V_15 ) ) {
F_107 ( L_2 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_232;
}
V_212 -> V_20 = F_12 ( V_224 ) ;
F_32 ( V_62 , V_220 ,
F_33 ( V_212 , & V_212 -> V_20 ,
sizeof( V_212 -> V_20 ) ) ) ;
V_220 = NULL ;
}
if ( ( V_226 = F_9 ( V_211 -> V_20 ) ) ) {
error = F_25 ( V_62 , V_217 , V_226 , - 1 , & V_220 , V_184 ) ;
if ( error )
goto V_232;
V_212 = V_220 -> V_31 ;
if ( F_106 (
F_9 ( V_212 -> V_21 ) != V_225 ||
V_212 -> V_15 != V_211 -> V_15 ) ) {
F_107 ( L_3 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_232;
}
V_212 -> V_21 = F_12 ( V_224 ) ;
F_32 ( V_62 , V_220 ,
F_33 ( V_212 , & V_212 -> V_21 ,
sizeof( V_212 -> V_21 ) ) ) ;
V_220 = NULL ;
}
V_227 = V_28 -> V_111 ;
V_24 = - 1 ;
for (; ; ) {
error = F_25 ( V_62 , V_217 , V_227 , - 1 , & V_221 , V_184 ) ;
if ( error )
goto V_232;
V_213 = V_221 -> V_31 ;
F_7 ( & V_216 , V_213 ) ;
if ( V_24 >= 0 && V_24 != V_216 . V_24 + 1 ) {
F_107 ( L_4 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_232;
}
V_24 = V_216 . V_24 ;
V_98 = F_46 ( V_213 ) ;
for ( V_228 = 0 ;
V_228 < V_216 . V_22 &&
F_9 ( V_98 [ V_228 ] . V_112 ) < V_222 ;
V_228 ++ )
continue;
if ( V_228 == V_216 . V_22 ) {
F_107 ( L_5 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_232;
}
V_227 = F_9 ( V_98 [ V_228 ] . V_113 ) ;
if ( V_24 == V_229 + 1 )
break;
F_72 ( V_62 , V_221 ) ;
V_221 = NULL ;
}
for (; ; ) {
for (;
V_228 < V_216 . V_22 &&
F_9 ( V_98 [ V_228 ] . V_113 ) != V_225 ;
V_228 ++ )
continue;
if ( V_228 < V_216 . V_22 )
break;
V_227 = V_216 . V_20 ;
F_72 ( V_62 , V_221 ) ;
V_221 = NULL ;
if ( F_106 ( V_227 == 0 ) ) {
F_107 ( L_6 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_232;
}
error = F_25 ( V_62 , V_217 , V_227 , - 1 , & V_221 , V_184 ) ;
if ( error )
goto V_232;
V_213 = V_221 -> V_31 ;
F_7 ( & V_216 , V_213 ) ;
if ( V_216 . V_24 != V_24 ) {
F_107 ( L_7 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_232;
}
V_98 = F_46 ( V_213 ) ;
V_228 = 0 ;
}
V_98 [ V_228 ] . V_113 = F_12 ( V_224 ) ;
F_32 ( V_62 , V_221 ,
F_33 ( V_213 , & V_98 [ V_228 ] . V_113 ,
sizeof( V_98 [ V_228 ] . V_113 ) ) ) ;
* V_209 = V_225 ;
* V_210 = V_219 ;
return 0 ;
V_232:
if ( V_221 )
F_72 ( V_62 , V_221 ) ;
if ( V_220 )
F_72 ( V_62 , V_220 ) ;
F_72 ( V_62 , V_219 ) ;
return error ;
}
int
F_65 (
T_10 * args ,
T_2 V_224 ,
struct V_26 * V_218 )
{
T_11 * V_64 ;
int V_232 , error , V_184 , V_22 ;
T_12 * V_62 ;
T_13 * V_28 ;
F_108 ( args ) ;
V_64 = args -> V_64 ;
V_184 = args -> V_75 ;
V_62 = args -> V_77 ;
V_28 = V_64 -> V_207 ;
if ( V_184 == V_110 )
V_22 = V_28 -> V_208 ;
else
V_22 = 1 ;
for (; ; ) {
error = F_109 ( V_62 , V_64 , V_224 , V_22 ,
F_98 ( V_184 ) | V_195 ,
0 , args -> V_194 , args -> V_198 , & V_232 ) ;
if ( error == V_89 ) {
if ( V_184 != V_110 )
break;
error = F_103 ( args , & V_224 ,
& V_218 ) ;
if ( error )
break;
} else {
break;
}
}
F_110 ( V_62 , V_218 ) ;
return error ;
}
STATIC int
F_111 (
int V_191 ,
T_14 * V_190 ,
T_2 V_65 ,
int V_22 )
{
int V_4 ;
T_8 V_233 ;
for ( V_4 = 0 , V_233 = V_65 ; V_4 < V_191 ; V_4 ++ ) {
if ( V_190 [ V_4 ] . V_234 == V_235 ||
V_190 [ V_4 ] . V_234 == V_236 ) {
return 0 ;
}
if ( V_233 != V_190 [ V_4 ] . V_204 ) {
return 0 ;
}
V_233 += V_190 [ V_4 ] . V_205 ;
}
return V_233 == V_65 + V_22 ;
}
static int
F_112 (
struct V_27 * V_28 ,
struct V_237 * * V_190 ,
unsigned int * V_238 ,
struct V_188 * V_239 ,
unsigned int V_240 )
{
struct V_237 * V_189 ;
int V_4 ;
ASSERT ( * V_238 == 1 ) ;
ASSERT ( V_240 >= 1 ) ;
if ( V_240 > 1 ) {
V_189 = F_113 ( V_240 * sizeof( struct V_237 ) ,
V_201 | V_2 ) ;
if ( ! V_189 )
return V_241 ;
* V_190 = V_189 ;
}
* V_238 = V_240 ;
V_189 = * V_190 ;
for ( V_4 = 0 ; V_4 < * V_238 ; V_4 ++ ) {
ASSERT ( V_239 [ V_4 ] . V_234 != V_236 &&
V_239 [ V_4 ] . V_234 != V_235 ) ;
V_189 [ V_4 ] . V_242 = F_114 ( V_28 , V_239 [ V_4 ] . V_234 ) ;
V_189 [ V_4 ] . V_243 = F_115 ( V_28 , V_239 [ V_4 ] . V_205 ) ;
}
return 0 ;
}
static int
F_116 (
struct V_61 * V_77 ,
struct V_63 * V_64 ,
T_2 V_65 ,
T_3 V_66 ,
int V_75 ,
struct V_237 * * V_189 ,
int * V_238 )
{
struct V_27 * V_28 = V_64 -> V_207 ;
int V_244 ;
int error = 0 ;
struct V_188 V_245 ;
struct V_188 * V_239 = & V_245 ;
int V_240 ;
ASSERT ( V_189 && * V_189 ) ;
ASSERT ( * V_238 == 1 ) ;
V_244 = ( V_75 == V_110 ) ? V_28 -> V_208 : 1 ;
if ( V_66 == - 1 || V_66 == - 2 ) {
if ( V_244 != 1 )
V_239 = F_113 ( sizeof( V_245 ) * V_244 ,
V_201 | V_2 ) ;
V_240 = V_244 ;
error = F_117 ( V_64 , ( T_8 ) V_65 , V_244 , V_239 ,
& V_240 , F_98 ( V_75 ) ) ;
if ( error )
goto V_246;
} else {
V_239 -> V_234 = F_118 ( V_28 , V_66 ) ;
V_239 -> V_204 = ( T_8 ) V_65 ;
V_239 -> V_205 = V_244 ;
V_239 -> V_247 = 0 ;
V_240 = 1 ;
}
if ( ! F_111 ( V_240 , V_239 , V_65 , V_244 ) ) {
error = V_66 == - 2 ? - 1 : F_82 ( V_46 ) ;
if ( F_106 ( error == V_46 ) ) {
if ( V_248 >= V_45 ) {
int V_4 ;
F_119 ( V_28 , L_8 ,
V_44 , ( long long ) V_65 ,
( long long ) V_64 -> V_80 ) ;
for ( V_4 = 0 ; V_4 < * V_238 ; V_4 ++ ) {
F_119 ( V_28 ,
L_9 ,
V_4 ,
( long long ) V_239 [ V_4 ] . V_204 ,
( long long ) V_239 [ V_4 ] . V_234 ,
( long long ) V_239 [ V_4 ] . V_205 ,
V_239 [ V_4 ] . V_247 ) ;
}
}
F_107 ( L_10 ,
V_45 , V_28 ) ;
}
goto V_246;
}
error = F_112 ( V_28 , V_189 , V_238 , V_239 , V_240 ) ;
V_246:
if ( V_239 != & V_245 )
F_101 ( V_239 ) ;
return error ;
}
int
F_30 (
struct V_61 * V_77 ,
struct V_63 * V_64 ,
T_2 V_65 ,
T_3 V_66 ,
struct V_26 * * V_67 ,
int V_75 )
{
struct V_26 * V_8 ;
struct V_237 V_189 ;
struct V_237 * V_190 ;
int V_191 ;
int error ;
* V_67 = NULL ;
V_190 = & V_189 ;
V_191 = 1 ;
error = F_116 ( V_77 , V_64 , V_65 , V_66 , V_75 ,
& V_190 , & V_191 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_249;
}
V_8 = F_120 ( V_77 , V_64 -> V_207 -> V_250 ,
V_190 , V_191 , 0 ) ;
error = V_8 ? V_8 -> V_251 : F_82 ( V_252 ) ;
if ( error ) {
F_72 ( V_77 , V_8 ) ;
goto V_249;
}
* V_67 = V_8 ;
V_249:
if ( V_190 != & V_189 )
F_101 ( V_190 ) ;
return error ;
}
int
F_26 (
struct V_61 * V_77 ,
struct V_63 * V_64 ,
T_2 V_65 ,
T_3 V_66 ,
struct V_26 * * V_67 ,
int V_75 ,
const struct V_253 * V_254 )
{
struct V_26 * V_8 ;
struct V_237 V_189 ;
struct V_237 * V_190 ;
int V_191 ;
int error ;
* V_67 = NULL ;
V_190 = & V_189 ;
V_191 = 1 ;
error = F_116 ( V_77 , V_64 , V_65 , V_66 , V_75 ,
& V_190 , & V_191 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_249;
}
error = F_121 ( V_64 -> V_207 , V_77 ,
V_64 -> V_207 -> V_250 ,
V_190 , V_191 , 0 , & V_8 , V_254 ) ;
if ( error )
goto V_249;
if ( V_75 == V_120 )
F_122 ( V_8 , V_255 ) ;
else
F_122 ( V_8 , V_256 ) ;
{
T_15 * V_13 = V_8 -> V_31 ;
T_16 * free = V_8 -> V_31 ;
T_17 * V_14 = V_8 -> V_31 ;
V_134 V_15 , V_257 ;
struct V_27 * V_28 = V_64 -> V_207 ;
V_15 = F_10 ( V_14 -> V_15 ) ;
V_257 = F_9 ( V_13 -> V_15 ) ;
if ( F_106 (
F_123 ( ( V_15 != V_16 ) &&
( V_15 != V_17 ) &&
( V_15 != V_53 ) &&
( V_15 != V_54 ) &&
( V_15 != V_258 ) &&
( V_15 != V_259 ) &&
( V_15 != V_58 ) &&
( V_15 != V_59 ) &&
( V_257 != V_260 ) &&
( V_257 != V_261 ) &&
( V_257 != V_262 ) &&
( V_257 != V_263 ) &&
( free -> V_13 . V_15 !=
F_12 ( V_264 ) ) &&
( free -> V_13 . V_15 !=
F_12 ( V_265 ) ) ,
V_28 , V_266 ,
V_267 ) ) ) {
F_124 ( V_8 , V_268 ) ;
F_18 ( L_11 ,
V_45 , V_28 , V_14 ) ;
error = F_82 ( V_46 ) ;
F_72 ( V_77 , V_8 ) ;
goto V_249;
}
}
* V_67 = V_8 ;
V_249:
if ( V_190 != & V_189 )
F_101 ( V_190 ) ;
return error ;
}
T_3
F_125 (
struct V_61 * V_77 ,
struct V_63 * V_64 ,
T_2 V_65 ,
T_3 V_66 ,
int V_75 ,
const struct V_253 * V_254 )
{
struct V_237 V_189 ;
struct V_237 * V_190 ;
int V_191 ;
int error ;
V_190 = & V_189 ;
V_191 = 1 ;
error = F_116 ( V_77 , V_64 , V_65 , V_66 , V_75 ,
& V_190 , & V_191 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_249;
}
V_66 = V_190 [ 0 ] . V_242 ;
F_126 ( V_64 -> V_207 -> V_250 , V_190 , V_191 , V_254 ) ;
V_249:
if ( V_190 != & V_189 )
F_101 ( V_190 ) ;
if ( error )
return - 1 ;
return V_66 ;
}
