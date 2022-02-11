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
int V_87 = 0 ;
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
F_49 ( V_8 , V_94 -> V_8 ) ;
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
F_50 ( V_3 -> args ) ;
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
F_51 ( V_3 , V_83 , V_84 ) ;
error = F_52 ( V_3 , V_83 , V_84 ) ;
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
F_53 ( V_3 , V_83 , V_85 ) ;
if ( V_119 ) {
if ( V_3 -> V_92 )
V_83 -> V_122 ++ ;
F_53 ( V_3 , V_83 , & V_3 -> V_93 ) ;
V_3 -> V_90 = 0 ;
}
} else {
V_84 -> V_122 ++ ;
F_53 ( V_3 , V_84 , V_85 ) ;
if ( V_119 ) {
if ( V_3 -> V_92 )
V_84 -> V_122 ++ ;
F_53 ( V_3 , V_84 , & V_3 -> V_93 ) ;
V_3 -> V_90 = 0 ;
}
}
return ( 0 ) ;
}
STATIC void
F_51 (
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
F_54 ( V_3 -> args ) ;
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
F_53 (
struct V_81 * V_3 ,
struct V_82 * V_83 ,
struct V_82 * V_84 )
{
struct V_11 * V_76 ;
struct V_9 V_99 ;
struct V_97 * V_98 ;
int V_132 ;
F_55 ( V_3 -> args ) ;
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
F_56 (
struct V_81 * V_3 )
{
struct V_82 * V_135 ;
struct V_82 * V_136 ;
int V_87 = 0 ;
int error ;
F_57 ( V_3 -> args ) ;
V_135 = & V_3 -> V_88 . V_7 [ V_3 -> V_88 . V_6 - 1 ] ;
V_136 = & V_3 -> V_5 . V_7 [ V_3 -> V_88 . V_6 - 1 ] ;
ASSERT ( V_3 -> V_88 . V_7 [ 0 ] . V_15 == V_16 ) ;
ASSERT ( V_135 -> V_15 == V_53 ||
V_135 -> V_15 == V_58 ) ;
for ( ; V_3 -> V_88 . V_6 >= 2 ; V_135 -- , V_136 -- ,
V_3 -> V_88 . V_6 -- ) {
switch ( V_135 -> V_15 ) {
case V_53 :
error = F_58 ( V_3 , & V_87 ) ;
if ( error )
return ( error ) ;
if ( V_87 == 0 )
return ( 0 ) ;
F_59 ( V_3 , V_135 , V_136 ) ;
break;
case V_58 :
error = F_60 ( V_3 , & V_87 ) ;
if ( error )
return error ;
if ( V_87 == 0 )
return 0 ;
F_61 ( V_3 , V_135 , V_136 ) ;
break;
case V_16 :
F_62 ( V_3 , V_135 ) ;
F_42 ( V_3 , & V_3 -> V_88 ) ;
error = F_63 ( V_3 , & V_87 ) ;
if ( error )
return ( error ) ;
if ( V_87 == 0 )
return 0 ;
F_64 ( V_3 , V_135 , V_136 ) ;
break;
}
F_42 ( V_3 , & V_3 -> V_5 ) ;
error = F_65 ( V_3 , V_135 , V_136 ) ;
F_3 ( V_3 ) ;
if ( error )
return ( error ) ;
error = F_66 ( V_3 -> args , V_135 -> V_36 ,
V_135 -> V_8 ) ;
V_135 -> V_8 = NULL ;
if ( error )
return ( error ) ;
}
F_62 ( V_3 , V_135 ) ;
F_42 ( V_3 , & V_3 -> V_88 ) ;
error = F_67 ( V_3 , & V_3 -> V_88 . V_7 [ 0 ] ) ;
return ( error ) ;
}
static void
F_68 ( struct V_52 * V_137 , T_4 V_24 )
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
F_67 (
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
F_69 ( V_3 -> args ) ;
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
F_68 ( V_8 -> V_31 , V_140 . V_24 ) ;
memcpy ( V_138 -> V_8 -> V_31 , V_8 -> V_31 , V_3 -> V_141 ) ;
V_138 -> V_8 -> V_55 = V_8 -> V_55 ;
F_49 ( V_138 -> V_8 , V_8 ) ;
if ( V_140 . V_15 == V_17 ) {
struct V_142 * V_143 = V_138 -> V_8 -> V_31 ;
V_143 -> V_36 = F_20 ( V_138 -> V_8 -> V_37 ) ;
}
F_32 ( args -> V_77 , V_138 -> V_8 , 0 , V_3 -> V_141 - 1 ) ;
error = F_66 ( args , V_139 , V_8 ) ;
return ( error ) ;
}
STATIC int
F_63 (
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
struct V_9 V_147 ;
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
F_7 ( & V_147 , V_76 ) ;
F_72 ( V_3 -> args -> V_77 , V_8 ) ;
if ( V_22 - V_147 . V_22 >= 0 )
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
struct V_148 * V_88 )
{
struct V_82 * V_7 ;
struct V_11 * V_76 ;
struct V_97 * V_98 ;
T_6 V_149 = 0 ;
int V_24 ;
int V_22 ;
F_74 ( V_3 -> args ) ;
V_24 = V_88 -> V_6 - 1 ;
V_7 = & V_88 -> V_7 [ V_24 ] ;
switch ( V_7 -> V_15 ) {
case V_53 :
V_149 = F_75 ( V_7 -> V_8 , & V_22 ) ;
if ( V_22 == 0 )
return;
break;
case V_58 :
V_149 = F_76 ( V_7 -> V_8 , & V_22 ) ;
if ( V_22 == 0 )
return;
break;
case V_16 :
V_149 = F_73 ( V_7 -> V_8 , & V_22 ) ;
if ( V_22 == 0 )
return;
break;
}
for ( V_7 -- , V_24 -- ; V_24 >= 0 ; V_7 -- , V_24 -- ) {
struct V_9 V_99 ;
V_76 = V_7 -> V_8 -> V_31 ;
F_7 ( & V_99 , V_76 ) ;
V_98 = F_46 ( V_76 ) ;
if ( F_9 ( V_98 -> V_112 ) == V_149 )
break;
V_7 -> V_112 = V_149 ;
V_98 [ V_7 -> V_122 ] . V_112 = F_12 ( V_149 ) ;
F_32 ( V_3 -> args -> V_77 , V_7 -> V_8 ,
F_33 ( V_76 , & V_98 [ V_7 -> V_122 ] ,
sizeof( * V_98 ) ) ) ;
V_149 = F_9 ( V_98 [ V_99 . V_22 - 1 ] . V_112 ) ;
}
}
STATIC void
F_62 (
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
F_64 (
struct V_81 * V_3 ,
struct V_82 * V_135 ,
struct V_82 * V_136 )
{
struct V_11 * V_150 ;
struct V_11 * V_151 ;
struct V_97 * V_152 ;
struct V_97 * V_153 ;
struct V_9 V_154 ;
struct V_9 V_155 ;
struct V_61 * V_62 ;
int V_156 ;
int V_132 ;
F_78 ( V_3 -> args ) ;
V_150 = V_135 -> V_8 -> V_31 ;
V_151 = V_136 -> V_8 -> V_31 ;
F_7 ( & V_154 , V_150 ) ;
F_7 ( & V_155 , V_151 ) ;
V_152 = F_46 ( V_150 ) ;
V_153 = F_46 ( V_151 ) ;
V_62 = V_3 -> args -> V_77 ;
if ( ( F_9 ( V_152 [ 0 ] . V_112 ) <
F_9 ( V_153 [ 0 ] . V_112 ) ) ||
( F_9 ( V_152 [ V_154 . V_22 - 1 ] . V_112 ) <
F_9 ( V_153 [ V_155 . V_22 - 1 ] . V_112 ) ) ) {
V_132 = V_155 . V_22 * sizeof( V_115 ) ;
memmove ( & V_153 [ V_154 . V_22 ] , & V_153 [ 0 ] , V_132 ) ;
V_156 = 0 ;
F_32 ( V_62 , V_136 -> V_8 ,
F_33 ( V_151 , & V_153 [ 0 ] ,
( V_155 . V_22 + V_154 . V_22 ) *
sizeof( V_115 ) ) ) ;
} else {
V_156 = V_155 . V_22 ;
F_32 ( V_62 , V_136 -> V_8 ,
F_33 ( V_151 , & V_153 [ V_156 ] ,
V_154 . V_22 * sizeof( V_115 ) ) ) ;
}
V_132 = V_154 . V_22 * ( V_134 ) sizeof( V_115 ) ;
memcpy ( & V_153 [ V_156 ] , & V_152 [ 0 ] , V_132 ) ;
V_155 . V_22 += V_154 . V_22 ;
F_11 ( V_151 , & V_155 ) ;
F_32 ( V_62 , V_136 -> V_8 ,
F_33 ( V_151 , & V_151 -> V_13 ,
F_34 ( V_151 ) ) ) ;
V_136 -> V_112 = F_9 ( V_153 [ V_155 . V_22 - 1 ] . V_112 ) ;
}
int
F_79 (
struct V_81 * V_3 ,
int * V_117 )
{
struct V_82 * V_7 ;
struct V_52 * V_157 ;
struct V_11 * V_76 ;
struct V_97 * V_98 ;
struct V_9 V_99 ;
struct V_74 * args ;
T_2 V_36 ;
T_6 V_112 ;
T_6 V_158 ;
int V_159 ;
int V_160 ;
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
V_157 = V_7 -> V_8 -> V_31 ;
V_7 -> V_15 = F_10 ( V_157 -> V_15 ) ;
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
V_159 = V_160 = V_86 / 2 ;
V_112 = args -> V_112 ;
while ( V_160 > 4 ) {
V_160 /= 2 ;
V_158 = F_9 ( V_98 [ V_159 ] . V_112 ) ;
if ( V_158 < V_112 )
V_159 += V_160 ;
else if ( V_158 > V_112 )
V_159 -= V_160 ;
else
break;
}
ASSERT ( ( V_159 >= 0 ) && ( V_159 < V_86 ) ) ;
ASSERT ( ( V_160 <= 4 ) ||
( F_9 ( V_98 [ V_159 ] . V_112 ) == V_112 ) ) ;
while ( V_159 > 0 &&
F_9 ( V_98 [ V_159 ] . V_112 ) >= V_112 ) {
V_159 -- ;
}
while ( V_159 < V_86 &&
F_9 ( V_98 [ V_159 ] . V_112 ) < V_112 ) {
V_159 ++ ;
}
if ( V_159 == V_86 ) {
V_7 -> V_122 = V_86 - 1 ;
V_36 = F_9 ( V_98 [ V_86 - 1 ] . V_113 ) ;
} else {
V_7 -> V_122 = V_159 ;
V_36 = F_9 ( V_98 [ V_159 ] . V_113 ) ;
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
if ( ( ( V_145 == V_161 ) || ( V_145 == V_162 ) ) &&
( V_7 -> V_112 == args -> V_112 ) ) {
error = F_71 ( V_3 , & V_3 -> V_88 , 1 , 1 ,
& V_145 ) ;
if ( error )
return ( error ) ;
if ( V_145 == 0 ) {
continue;
} else if ( V_7 -> V_15 == V_53 ) {
V_145 = F_82 ( V_162 ) ;
}
}
break;
}
* V_117 = V_145 ;
return ( 0 ) ;
}
STATIC int
F_83 (
struct V_26 * V_163 ,
struct V_26 * V_164 )
{
struct V_11 * V_123 ;
struct V_11 * V_124 ;
struct V_97 * V_126 ;
struct V_97 * V_127 ;
struct V_9 V_165 ;
struct V_9 V_166 ;
V_123 = V_163 -> V_31 ;
V_124 = V_164 -> V_31 ;
F_7 ( & V_165 , V_123 ) ;
F_7 ( & V_166 , V_124 ) ;
V_126 = F_46 ( V_123 ) ;
V_127 = F_46 ( V_124 ) ;
if ( V_165 . V_22 > 0 && V_166 . V_22 > 0 &&
( ( F_9 ( V_127 [ 0 ] . V_112 ) < F_9 ( V_126 [ 0 ] . V_112 ) ) ||
( F_9 ( V_127 [ V_166 . V_22 - 1 ] . V_112 ) <
F_9 ( V_126 [ V_165 . V_22 - 1 ] . V_112 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_52 (
struct V_81 * V_3 ,
struct V_82 * V_167 ,
struct V_82 * V_168 )
{
struct V_52 * V_169 ;
struct V_52 * V_170 ;
struct V_52 * V_171 ;
struct V_74 * args ;
struct V_26 * V_8 ;
int V_113 = 0 ;
int error ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
V_169 = V_167 -> V_8 -> V_31 ;
V_170 = V_168 -> V_8 -> V_31 ;
ASSERT ( V_167 -> V_15 == V_16 ||
V_167 -> V_15 == V_58 ||
V_167 -> V_15 == V_53 ) ;
switch ( V_167 -> V_15 ) {
case V_53 :
V_113 = F_84 ( V_167 -> V_8 , V_168 -> V_8 ) ;
break;
case V_58 :
V_113 = F_85 ( V_167 -> V_8 , V_168 -> V_8 ) ;
break;
case V_16 :
V_113 = F_83 ( V_167 -> V_8 , V_168 -> V_8 ) ;
break;
}
if ( V_113 ) {
F_86 ( args ) ;
V_170 -> V_20 = F_12 ( V_167 -> V_36 ) ;
V_170 -> V_21 = V_169 -> V_21 ;
if ( V_169 -> V_21 ) {
error = F_25 ( args -> V_77 , args -> V_64 ,
F_9 ( V_169 -> V_21 ) ,
- 1 , & V_8 , args -> V_75 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_171 = V_8 -> V_31 ;
ASSERT ( V_171 -> V_15 == V_169 -> V_15 ) ;
ASSERT ( F_9 ( V_171 -> V_20 ) == V_167 -> V_36 ) ;
V_171 -> V_20 = F_12 ( V_168 -> V_36 ) ;
F_32 ( args -> V_77 , V_8 , 0 , sizeof( * V_171 ) - 1 ) ;
}
V_169 -> V_21 = F_12 ( V_168 -> V_36 ) ;
} else {
F_87 ( args ) ;
V_170 -> V_20 = V_169 -> V_20 ;
V_170 -> V_21 = F_12 ( V_167 -> V_36 ) ;
if ( V_169 -> V_20 ) {
error = F_25 ( args -> V_77 , args -> V_64 ,
F_9 ( V_169 -> V_20 ) ,
- 1 , & V_8 , args -> V_75 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_171 = V_8 -> V_31 ;
ASSERT ( V_171 -> V_15 == V_169 -> V_15 ) ;
ASSERT ( F_9 ( V_171 -> V_21 ) == V_167 -> V_36 ) ;
V_171 -> V_21 = F_12 ( V_168 -> V_36 ) ;
F_32 ( args -> V_77 , V_8 , 0 , sizeof( * V_171 ) - 1 ) ;
}
V_169 -> V_20 = F_12 ( V_168 -> V_36 ) ;
}
F_32 ( args -> V_77 , V_167 -> V_8 , 0 , sizeof( * V_171 ) - 1 ) ;
F_32 ( args -> V_77 , V_168 -> V_8 , 0 , sizeof( * V_171 ) - 1 ) ;
return ( 0 ) ;
}
STATIC int
F_65 (
struct V_81 * V_3 ,
struct V_82 * V_135 ,
struct V_82 * V_136 )
{
struct V_52 * V_172 ;
struct V_52 * V_173 ;
struct V_52 * V_171 ;
struct V_74 * args ;
struct V_26 * V_8 ;
int error ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
V_173 = V_136 -> V_8 -> V_31 ;
V_172 = V_135 -> V_8 -> V_31 ;
ASSERT ( V_136 -> V_15 == V_16 ||
V_136 -> V_15 == V_58 ||
V_136 -> V_15 == V_53 ) ;
ASSERT ( V_136 -> V_15 == V_135 -> V_15 ) ;
ASSERT ( ( F_9 ( V_173 -> V_20 ) == V_135 -> V_36 ) ||
( F_9 ( V_173 -> V_21 ) == V_135 -> V_36 ) ) ;
ASSERT ( ( F_9 ( V_172 -> V_20 ) == V_136 -> V_36 ) ||
( F_9 ( V_172 -> V_21 ) == V_136 -> V_36 ) ) ;
if ( F_9 ( V_173 -> V_21 ) == V_135 -> V_36 ) {
F_88 ( args ) ;
V_173 -> V_21 = V_172 -> V_21 ;
if ( V_172 -> V_21 ) {
error = F_25 ( args -> V_77 , args -> V_64 ,
F_9 ( V_172 -> V_21 ) ,
- 1 , & V_8 , args -> V_75 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_171 = V_8 -> V_31 ;
ASSERT ( V_171 -> V_15 == V_173 -> V_15 ) ;
ASSERT ( F_9 ( V_171 -> V_20 ) == V_135 -> V_36 ) ;
V_171 -> V_20 = F_12 ( V_136 -> V_36 ) ;
F_32 ( args -> V_77 , V_8 , 0 ,
sizeof( * V_171 ) - 1 ) ;
}
} else {
F_89 ( args ) ;
V_173 -> V_20 = V_172 -> V_20 ;
if ( V_172 -> V_20 ) {
error = F_25 ( args -> V_77 , args -> V_64 ,
F_9 ( V_172 -> V_20 ) ,
- 1 , & V_8 , args -> V_75 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_8 != NULL ) ;
V_171 = V_8 -> V_31 ;
ASSERT ( V_171 -> V_15 == V_173 -> V_15 ) ;
ASSERT ( F_9 ( V_171 -> V_21 ) == V_135 -> V_36 ) ;
V_171 -> V_21 = F_12 ( V_136 -> V_36 ) ;
F_32 ( args -> V_77 , V_8 , 0 ,
sizeof( * V_171 ) - 1 ) ;
}
}
F_32 ( args -> V_77 , V_136 -> V_8 , 0 , sizeof( * V_173 ) - 1 ) ;
return ( 0 ) ;
}
int
F_71 (
struct V_81 * V_3 ,
struct V_148 * V_88 ,
int V_144 ,
int V_174 ,
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
* V_117 = F_82 ( V_161 ) ;
ASSERT ( args -> V_175 & V_176 ) ;
return ( 0 ) ;
}
for ( V_7 ++ , V_24 ++ ; V_24 < V_88 -> V_6 ; V_7 ++ , V_24 ++ ) {
if ( V_174 )
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
F_91 ( const T_7 * V_177 , int V_178 )
{
T_6 V_179 ;
for ( V_179 = 0 ; V_178 >= 4 ; V_178 -= 4 , V_177 += 4 )
V_179 = ( V_177 [ 0 ] << 21 ) ^ ( V_177 [ 1 ] << 14 ) ^ ( V_177 [ 2 ] << 7 ) ^
( V_177 [ 3 ] << 0 ) ^ F_92 ( V_179 , 7 * 4 ) ;
switch ( V_178 ) {
case 3 :
return ( V_177 [ 0 ] << 14 ) ^ ( V_177 [ 1 ] << 7 ) ^ ( V_177 [ 2 ] << 0 ) ^
F_92 ( V_179 , 7 * 3 ) ;
case 2 :
return ( V_177 [ 0 ] << 7 ) ^ ( V_177 [ 1 ] << 0 ) ^ F_92 ( V_179 , 7 * 2 ) ;
case 1 :
return ( V_177 [ 0 ] << 0 ) ^ F_92 ( V_179 , 7 * 1 ) ;
default:
return V_179 ;
}
}
enum V_180
F_93 (
struct V_74 * args ,
const unsigned char * V_177 ,
int V_181 )
{
return ( args -> V_178 == V_181 && memcmp ( args -> V_177 , V_177 , V_181 ) == 0 ) ?
V_182 : V_183 ;
}
static T_6
F_94 (
struct V_184 * V_177 )
{
return F_91 ( V_177 -> V_177 , V_177 -> V_181 ) ;
}
int
F_95 (
struct V_74 * args ,
T_8 * V_65 ,
int V_22 )
{
struct V_61 * V_62 = args -> V_77 ;
struct V_63 * V_64 = args -> V_64 ;
int V_185 = args -> V_75 ;
T_9 V_186 = V_64 -> V_187 . V_188 ;
struct V_189 V_190 , * V_191 ;
int V_192 , error , V_193 , V_4 , V_194 ;
error = F_96 ( V_62 , V_64 , V_22 , V_65 , V_185 ) ;
if ( error )
return error ;
V_192 = 1 ;
ASSERT ( args -> V_195 != NULL ) ;
error = F_97 ( V_62 , V_64 , * V_65 , V_22 ,
F_98 ( V_185 ) | V_196 | V_197 ,
args -> V_195 , args -> V_198 , & V_190 , & V_192 ,
args -> V_199 ) ;
if ( error )
return error ;
ASSERT ( V_192 <= 1 ) ;
if ( V_192 == 1 ) {
V_191 = & V_190 ;
V_194 = 1 ;
} else if ( V_192 == 0 && V_22 > 1 ) {
T_8 V_200 ;
int V_201 ;
V_191 = F_99 ( sizeof( * V_191 ) * V_22 , V_202 ) ;
for ( V_200 = * V_65 , V_194 = 0 ; V_200 < * V_65 + V_22 ; ) {
V_192 = F_100 ( V_203 , V_22 ) ;
V_201 = ( int ) ( * V_65 + V_22 - V_200 ) ;
error = F_97 ( V_62 , V_64 , V_200 , V_201 ,
F_98 ( V_185 ) | V_196 ,
args -> V_195 , args -> V_198 ,
& V_191 [ V_194 ] , & V_192 , args -> V_199 ) ;
if ( error )
goto V_204;
if ( V_192 < 1 )
break;
V_194 += V_192 ;
V_200 = V_191 [ V_194 - 1 ] . V_205 +
V_191 [ V_194 - 1 ] . V_206 ;
}
} else {
V_194 = 0 ;
V_191 = NULL ;
}
for ( V_4 = 0 , V_193 = 0 ; V_4 < V_194 ; V_4 ++ )
V_193 += V_191 [ V_4 ] . V_206 ;
if ( V_193 != V_22 || V_191 [ 0 ] . V_205 != * V_65 ||
V_191 [ V_194 - 1 ] . V_205 + V_191 [ V_194 - 1 ] . V_206 !=
* V_65 + V_22 ) {
error = F_82 ( V_89 ) ;
goto V_204;
}
args -> V_198 -= V_64 -> V_187 . V_188 - V_186 ;
V_204:
if ( V_191 != & V_190 )
F_101 ( V_191 ) ;
return error ;
}
int
F_45 (
struct V_74 * args ,
T_2 * V_207 )
{
T_8 V_65 ;
int V_22 ;
int error ;
F_102 ( args ) ;
if ( args -> V_75 == V_110 ) {
V_65 = args -> V_64 -> V_208 -> V_111 ;
V_22 = args -> V_64 -> V_208 -> V_209 ;
} else {
V_65 = 0 ;
V_22 = 1 ;
}
error = F_95 ( args , & V_65 , V_22 ) ;
if ( ! error )
* V_207 = ( T_2 ) V_65 ;
return error ;
}
STATIC int
F_103 (
struct V_74 * args ,
T_2 * V_210 ,
struct V_26 * * V_211 )
{
struct V_52 * V_212 ;
struct V_52 * V_213 ;
struct V_11 * V_214 ;
struct V_11 * V_215 ;
struct V_100 * V_216 ;
struct V_97 * V_98 ;
struct V_9 V_217 ;
struct V_63 * V_218 ;
struct V_61 * V_62 ;
struct V_27 * V_28 ;
struct V_26 * V_219 ;
struct V_26 * V_220 ;
struct V_26 * V_221 ;
struct V_26 * V_222 ;
T_6 V_223 ;
T_8 V_224 ;
T_2 V_225 ;
T_2 V_226 ;
T_2 V_227 ;
T_2 V_228 ;
int error ;
int V_185 ;
int V_229 ;
int V_24 ;
int V_230 ;
F_104 ( args ) ;
V_219 = * V_211 ;
V_225 = * V_210 ;
V_62 = args -> V_77 ;
V_218 = args -> V_64 ;
V_185 = args -> V_75 ;
ASSERT ( V_185 == V_110 ) ;
V_28 = V_218 -> V_208 ;
V_224 = V_28 -> V_114 ;
error = F_105 ( V_62 , V_218 , & V_224 , V_185 ) ;
if ( error )
return error ;
if ( F_106 ( V_224 == 0 ) ) {
F_107 ( L_1 , V_45 ,
V_28 ) ;
return F_82 ( V_46 ) ;
}
V_226 = ( T_2 ) V_224 - V_28 -> V_209 ;
error = F_25 ( V_62 , V_218 , V_226 , - 1 , & V_220 , V_185 ) ;
if ( error )
return error ;
memcpy ( V_219 -> V_31 , V_220 -> V_31 , V_28 -> V_231 ) ;
F_32 ( V_62 , V_219 , 0 , V_28 -> V_231 - 1 ) ;
V_212 = V_219 -> V_31 ;
if ( V_212 -> V_15 == F_8 ( V_58 ) ||
V_212 -> V_15 == F_8 ( V_59 ) ) {
struct V_103 V_104 ;
struct V_105 * V_106 ;
V_216 = ( V_107 * ) V_212 ;
F_47 ( & V_104 , V_216 ) ;
V_106 = F_48 ( V_216 ) ;
V_230 = 0 ;
V_223 = F_9 ( V_106 [ V_104 . V_22 - 1 ] . V_112 ) ;
} else {
struct V_9 V_232 ;
V_215 = ( V_146 * ) V_212 ;
F_7 ( & V_232 , V_215 ) ;
V_98 = F_46 ( V_215 ) ;
V_230 = V_232 . V_24 ;
V_223 = F_9 ( V_98 [ V_232 . V_22 - 1 ] . V_112 ) ;
}
V_221 = V_222 = NULL ;
if ( ( V_227 = F_9 ( V_212 -> V_21 ) ) ) {
error = F_25 ( V_62 , V_218 , V_227 , - 1 , & V_221 , V_185 ) ;
if ( error )
goto V_233;
V_213 = V_221 -> V_31 ;
if ( F_106 (
F_9 ( V_213 -> V_20 ) != V_226 ||
V_213 -> V_15 != V_212 -> V_15 ) ) {
F_107 ( L_2 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_233;
}
V_213 -> V_20 = F_12 ( V_225 ) ;
F_32 ( V_62 , V_221 ,
F_33 ( V_213 , & V_213 -> V_20 ,
sizeof( V_213 -> V_20 ) ) ) ;
V_221 = NULL ;
}
if ( ( V_227 = F_9 ( V_212 -> V_20 ) ) ) {
error = F_25 ( V_62 , V_218 , V_227 , - 1 , & V_221 , V_185 ) ;
if ( error )
goto V_233;
V_213 = V_221 -> V_31 ;
if ( F_106 (
F_9 ( V_213 -> V_21 ) != V_226 ||
V_213 -> V_15 != V_212 -> V_15 ) ) {
F_107 ( L_3 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_233;
}
V_213 -> V_21 = F_12 ( V_225 ) ;
F_32 ( V_62 , V_221 ,
F_33 ( V_213 , & V_213 -> V_21 ,
sizeof( V_213 -> V_21 ) ) ) ;
V_221 = NULL ;
}
V_228 = V_28 -> V_111 ;
V_24 = - 1 ;
for (; ; ) {
error = F_25 ( V_62 , V_218 , V_228 , - 1 , & V_222 , V_185 ) ;
if ( error )
goto V_233;
V_214 = V_222 -> V_31 ;
F_7 ( & V_217 , V_214 ) ;
if ( V_24 >= 0 && V_24 != V_217 . V_24 + 1 ) {
F_107 ( L_4 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_233;
}
V_24 = V_217 . V_24 ;
V_98 = F_46 ( V_214 ) ;
for ( V_229 = 0 ;
V_229 < V_217 . V_22 &&
F_9 ( V_98 [ V_229 ] . V_112 ) < V_223 ;
V_229 ++ )
continue;
if ( V_229 == V_217 . V_22 ) {
F_107 ( L_5 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_233;
}
V_228 = F_9 ( V_98 [ V_229 ] . V_113 ) ;
if ( V_24 == V_230 + 1 )
break;
F_72 ( V_62 , V_222 ) ;
V_222 = NULL ;
}
for (; ; ) {
for (;
V_229 < V_217 . V_22 &&
F_9 ( V_98 [ V_229 ] . V_113 ) != V_226 ;
V_229 ++ )
continue;
if ( V_229 < V_217 . V_22 )
break;
V_228 = V_217 . V_20 ;
F_72 ( V_62 , V_222 ) ;
V_222 = NULL ;
if ( F_106 ( V_228 == 0 ) ) {
F_107 ( L_6 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_233;
}
error = F_25 ( V_62 , V_218 , V_228 , - 1 , & V_222 , V_185 ) ;
if ( error )
goto V_233;
V_214 = V_222 -> V_31 ;
F_7 ( & V_217 , V_214 ) ;
if ( V_217 . V_24 != V_24 ) {
F_107 ( L_7 ,
V_45 , V_28 ) ;
error = F_82 ( V_46 ) ;
goto V_233;
}
V_98 = F_46 ( V_214 ) ;
V_229 = 0 ;
}
V_98 [ V_229 ] . V_113 = F_12 ( V_225 ) ;
F_32 ( V_62 , V_222 ,
F_33 ( V_214 , & V_98 [ V_229 ] . V_113 ,
sizeof( V_98 [ V_229 ] . V_113 ) ) ) ;
* V_210 = V_226 ;
* V_211 = V_220 ;
return 0 ;
V_233:
if ( V_222 )
F_72 ( V_62 , V_222 ) ;
if ( V_221 )
F_72 ( V_62 , V_221 ) ;
F_72 ( V_62 , V_220 ) ;
return error ;
}
int
F_66 (
T_10 * args ,
T_2 V_225 ,
struct V_26 * V_219 )
{
T_11 * V_64 ;
int V_233 , error , V_185 , V_22 ;
T_12 * V_62 ;
T_13 * V_28 ;
F_108 ( args ) ;
V_64 = args -> V_64 ;
V_185 = args -> V_75 ;
V_62 = args -> V_77 ;
V_28 = V_64 -> V_208 ;
if ( V_185 == V_110 )
V_22 = V_28 -> V_209 ;
else
V_22 = 1 ;
for (; ; ) {
error = F_109 ( V_62 , V_64 , V_225 , V_22 ,
F_98 ( V_185 ) | V_196 ,
0 , args -> V_195 , args -> V_199 , & V_233 ) ;
if ( error == V_89 ) {
if ( V_185 != V_110 )
break;
error = F_103 ( args , & V_225 ,
& V_219 ) ;
if ( error )
break;
} else {
break;
}
}
F_110 ( V_62 , V_219 ) ;
return error ;
}
STATIC int
F_111 (
int V_192 ,
T_14 * V_191 ,
T_2 V_65 ,
int V_22 )
{
int V_4 ;
T_8 V_234 ;
for ( V_4 = 0 , V_234 = V_65 ; V_4 < V_192 ; V_4 ++ ) {
if ( V_191 [ V_4 ] . V_235 == V_236 ||
V_191 [ V_4 ] . V_235 == V_237 ) {
return 0 ;
}
if ( V_234 != V_191 [ V_4 ] . V_205 ) {
return 0 ;
}
V_234 += V_191 [ V_4 ] . V_206 ;
}
return V_234 == V_65 + V_22 ;
}
static int
F_112 (
struct V_27 * V_28 ,
struct V_238 * * V_191 ,
int * V_239 ,
struct V_189 * V_240 ,
int V_241 )
{
struct V_238 * V_190 ;
int V_4 ;
ASSERT ( * V_239 == 1 ) ;
ASSERT ( V_241 >= 1 ) ;
if ( V_241 > 1 ) {
V_190 = F_113 ( V_241 * sizeof( struct V_238 ) ,
V_202 | V_2 ) ;
if ( ! V_190 )
return V_242 ;
* V_191 = V_190 ;
}
* V_239 = V_241 ;
V_190 = * V_191 ;
for ( V_4 = 0 ; V_4 < * V_239 ; V_4 ++ ) {
ASSERT ( V_240 [ V_4 ] . V_235 != V_237 &&
V_240 [ V_4 ] . V_235 != V_236 ) ;
V_190 [ V_4 ] . V_243 = F_114 ( V_28 , V_240 [ V_4 ] . V_235 ) ;
V_190 [ V_4 ] . V_244 = F_115 ( V_28 , V_240 [ V_4 ] . V_206 ) ;
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
struct V_238 * * V_190 ,
int * V_239 )
{
struct V_27 * V_28 = V_64 -> V_208 ;
int V_245 ;
int error = 0 ;
struct V_189 V_246 ;
struct V_189 * V_240 = & V_246 ;
int V_241 ;
ASSERT ( V_190 && * V_190 ) ;
ASSERT ( * V_239 == 1 ) ;
V_245 = ( V_75 == V_110 ) ? V_28 -> V_209 : 1 ;
if ( V_66 == - 1 || V_66 == - 2 ) {
if ( V_245 != 1 )
V_240 = F_113 ( sizeof( V_246 ) * V_245 ,
V_202 | V_2 ) ;
V_241 = V_245 ;
error = F_117 ( V_64 , ( T_8 ) V_65 , V_245 , V_240 ,
& V_241 , F_98 ( V_75 ) ) ;
if ( error )
goto V_247;
} else {
V_240 -> V_235 = F_118 ( V_28 , V_66 ) ;
V_240 -> V_205 = ( T_8 ) V_65 ;
V_240 -> V_206 = V_245 ;
V_240 -> V_248 = 0 ;
V_241 = 1 ;
}
if ( ! F_111 ( V_241 , V_240 , V_65 , V_245 ) ) {
error = V_66 == - 2 ? - 1 : F_82 ( V_46 ) ;
if ( F_106 ( error == V_46 ) ) {
if ( V_249 >= V_45 ) {
int V_4 ;
F_119 ( V_28 , L_8 ,
V_44 , ( long long ) V_65 ,
( long long ) V_64 -> V_80 ) ;
for ( V_4 = 0 ; V_4 < * V_239 ; V_4 ++ ) {
F_119 ( V_28 ,
L_9 ,
V_4 ,
( long long ) V_240 [ V_4 ] . V_205 ,
( long long ) V_240 [ V_4 ] . V_235 ,
( long long ) V_240 [ V_4 ] . V_206 ,
V_240 [ V_4 ] . V_248 ) ;
}
}
F_107 ( L_10 ,
V_45 , V_28 ) ;
}
goto V_247;
}
error = F_112 ( V_28 , V_190 , V_239 , V_240 , V_241 ) ;
V_247:
if ( V_240 != & V_246 )
F_101 ( V_240 ) ;
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
struct V_238 V_190 ;
struct V_238 * V_191 ;
int V_192 ;
int error ;
* V_67 = NULL ;
V_191 = & V_190 ;
V_192 = 1 ;
error = F_116 ( V_77 , V_64 , V_65 , V_66 , V_75 ,
& V_191 , & V_192 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_250;
}
V_8 = F_120 ( V_77 , V_64 -> V_208 -> V_251 ,
V_191 , V_192 , 0 ) ;
error = V_8 ? V_8 -> V_252 : F_82 ( V_253 ) ;
if ( error ) {
F_72 ( V_77 , V_8 ) ;
goto V_250;
}
* V_67 = V_8 ;
V_250:
if ( V_191 != & V_190 )
F_101 ( V_191 ) ;
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
const struct V_254 * V_255 )
{
struct V_26 * V_8 ;
struct V_238 V_190 ;
struct V_238 * V_191 ;
int V_192 ;
int error ;
* V_67 = NULL ;
V_191 = & V_190 ;
V_192 = 1 ;
error = F_116 ( V_77 , V_64 , V_65 , V_66 , V_75 ,
& V_191 , & V_192 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_250;
}
error = F_121 ( V_64 -> V_208 , V_77 ,
V_64 -> V_208 -> V_251 ,
V_191 , V_192 , 0 , & V_8 , V_255 ) ;
if ( error )
goto V_250;
if ( V_75 == V_120 )
F_122 ( V_8 , V_256 ) ;
else
F_122 ( V_8 , V_257 ) ;
{
T_15 * V_13 = V_8 -> V_31 ;
T_16 * free = V_8 -> V_31 ;
T_17 * V_14 = V_8 -> V_31 ;
V_134 V_15 , V_258 ;
struct V_27 * V_28 = V_64 -> V_208 ;
V_15 = F_10 ( V_14 -> V_15 ) ;
V_258 = F_9 ( V_13 -> V_15 ) ;
if ( F_106 (
F_123 ( ( V_15 != V_16 ) &&
( V_15 != V_17 ) &&
( V_15 != V_53 ) &&
( V_15 != V_54 ) &&
( V_15 != V_259 ) &&
( V_15 != V_260 ) &&
( V_15 != V_58 ) &&
( V_15 != V_59 ) &&
( V_258 != V_261 ) &&
( V_258 != V_262 ) &&
( V_258 != V_263 ) &&
( V_258 != V_264 ) &&
( free -> V_13 . V_15 !=
F_12 ( V_265 ) ) &&
( free -> V_13 . V_15 !=
F_12 ( V_266 ) ) ,
V_28 , V_267 ,
V_268 ) ) ) {
F_124 ( V_8 , V_269 ) ;
F_18 ( L_11 ,
V_45 , V_28 , V_14 ) ;
error = F_82 ( V_46 ) ;
F_72 ( V_77 , V_8 ) ;
goto V_250;
}
}
* V_67 = V_8 ;
V_250:
if ( V_191 != & V_190 )
F_101 ( V_191 ) ;
return error ;
}
T_3
F_125 (
struct V_61 * V_77 ,
struct V_63 * V_64 ,
T_2 V_65 ,
T_3 V_66 ,
int V_75 ,
const struct V_254 * V_255 )
{
struct V_238 V_190 ;
struct V_238 * V_191 ;
int V_192 ;
int error ;
V_191 = & V_190 ;
V_192 = 1 ;
error = F_116 ( V_77 , V_64 , V_65 , V_66 , V_75 ,
& V_191 , & V_192 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_250;
}
V_66 = V_191 [ 0 ] . V_243 ;
F_126 ( V_64 -> V_208 -> V_251 , V_191 , V_192 , V_255 ) ;
V_250:
if ( V_191 != & V_190 )
F_101 ( V_191 ) ;
if ( error )
return - 1 ;
return V_66 ;
}
