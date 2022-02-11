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
if ( V_18 . V_35 > V_11 -> V_36 -> V_37 &&
V_18 . V_35 > V_11 -> V_38 -> V_37 )
return false ;
return true ;
}
static void
F_12 (
struct V_9 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 -> V_13 ;
struct V_39 * V_40 = V_8 -> V_41 ;
struct V_23 * V_24 = V_8 -> V_16 ;
if ( ! F_7 ( V_8 ) ) {
F_13 ( V_8 , - V_42 ) ;
F_14 ( V_8 ) ;
return;
}
if ( ! F_9 ( & V_11 -> V_22 ) )
return;
if ( V_40 )
V_24 -> V_27 . V_43 = F_15 ( V_40 -> V_44 . V_45 ) ;
F_16 ( V_8 , V_46 ) ;
}
static void
F_17 (
struct V_9 * V_8 )
{
struct V_47 * V_27 = V_8 -> V_16 ;
switch ( F_18 ( V_27 -> V_25 ) ) {
case V_26 :
if ( ! F_19 ( V_8 , V_46 ) ) {
F_13 ( V_8 , - V_48 ) ;
break;
}
case V_32 :
if ( ! F_7 ( V_8 ) ) {
F_13 ( V_8 , - V_42 ) ;
break;
}
return;
case V_49 :
case V_50 :
V_8 -> V_51 = & V_52 ;
V_8 -> V_51 -> V_53 ( V_8 ) ;
return;
case V_54 :
case V_55 :
V_8 -> V_51 = & V_56 ;
V_8 -> V_51 -> V_53 ( V_8 ) ;
return;
default:
break;
}
F_14 ( V_8 ) ;
}
int
F_20 (
struct V_57 * V_58 ,
struct V_59 * V_60 ,
T_2 V_61 ,
T_3 V_62 ,
struct V_9 * * V_63 ,
int V_64 )
{
int V_65 ;
V_65 = F_21 ( V_58 , V_60 , V_61 , V_62 , V_63 ,
V_64 , & V_66 ) ;
if ( ! V_65 && V_58 ) {
struct V_47 * V_27 = ( * V_63 ) -> V_16 ;
int type ;
switch ( F_18 ( V_27 -> V_25 ) ) {
case V_32 :
case V_26 :
type = V_67 ;
break;
case V_49 :
case V_50 :
type = V_68 ;
break;
case V_54 :
case V_55 :
type = V_69 ;
break;
default:
type = 0 ;
ASSERT ( 0 ) ;
break;
}
F_22 ( V_58 , * V_63 , type ) ;
}
return V_65 ;
}
int
F_23 (
struct V_70 * args ,
T_2 V_30 ,
int V_33 ,
struct V_9 * * V_63 ,
int V_71 )
{
struct V_14 * V_72 ;
struct V_57 * V_58 = args -> V_73 ;
struct V_10 * V_11 = V_58 -> V_74 ;
struct V_17 V_18 = { 0 } ;
struct V_9 * V_8 ;
int error ;
struct V_59 * V_60 = args -> V_60 ;
F_24 ( args ) ;
ASSERT ( V_33 <= V_34 ) ;
error = F_25 ( V_58 , V_60 , V_30 , - 1 , & V_8 , V_71 ) ;
if ( error )
return error ;
V_8 -> V_51 = & V_66 ;
F_22 ( V_58 , V_8 , V_67 ) ;
V_72 = V_8 -> V_16 ;
if ( F_9 ( & V_11 -> V_22 ) ) {
struct V_23 * V_24 = V_8 -> V_16 ;
V_18 . V_25 = V_26 ;
V_24 -> V_27 . V_30 = F_15 ( V_8 -> V_31 ) ;
V_24 -> V_27 . V_75 = F_15 ( args -> V_60 -> V_76 ) ;
F_26 ( & V_24 -> V_27 . V_28 , & V_11 -> V_22 . V_29 ) ;
} else {
V_18 . V_25 = V_32 ;
}
V_18 . V_33 = V_33 ;
V_60 -> V_77 -> V_78 ( V_72 , & V_18 ) ;
F_27 ( V_58 , V_8 ,
F_28 ( V_72 , & V_72 -> V_15 , V_60 -> V_77 -> V_79 ) ) ;
* V_63 = V_8 ;
return 0 ;
}
int
F_29 (
struct V_80 * V_3 )
{
struct V_81 * V_82 ;
struct V_81 * V_83 ;
struct V_81 * V_84 ;
struct V_14 * V_72 ;
struct V_9 * V_8 ;
int V_85 ;
int V_86 = 0 ;
int error ;
int V_4 ;
F_30 ( V_3 -> args ) ;
V_85 = V_3 -> V_87 . V_6 - 1 ;
ASSERT ( ( V_85 >= 0 ) && ( V_85 < V_34 ) ) ;
ASSERT ( V_3 -> V_87 . V_7 [ V_85 ] . V_25 == V_49 ||
V_3 -> V_87 . V_7 [ V_85 ] . V_25 == V_54 ) ;
V_84 = & V_3 -> V_87 . V_7 [ V_85 ] ;
for ( V_4 = V_85 ; ( V_4 >= 0 ) && V_84 ; V_3 -> V_87 . V_6 -- , V_4 -- ) {
V_82 = & V_3 -> V_87 . V_7 [ V_4 ] ;
V_83 = & V_3 -> V_5 . V_7 [ V_4 ] ;
switch ( V_82 -> V_25 ) {
case V_49 :
error = F_31 ( V_3 , V_82 , V_83 ) ;
if ( ( error != 0 ) && ( error != - V_88 ) ) {
return error ;
}
if ( ! error ) {
V_84 = V_83 ;
break;
}
V_3 -> V_89 = 1 ;
if ( V_3 -> V_90 ) {
V_3 -> V_91 = 0 ;
F_32 ( V_3 -> args ) ;
error = F_31 ( V_3 , V_82 ,
& V_3 -> V_92 ) ;
} else {
V_3 -> V_91 = 1 ;
F_33 ( V_3 -> args ) ;
error = F_31 ( V_3 , V_83 ,
& V_3 -> V_92 ) ;
}
if ( error )
return error ;
V_84 = V_83 ;
break;
case V_54 :
error = F_34 ( V_3 , V_82 , V_83 ) ;
if ( error )
return error ;
V_84 = V_83 ;
break;
case V_32 :
error = F_35 ( V_3 , V_82 , V_83 , V_84 ,
V_85 - V_4 , & V_86 ) ;
V_84 -> V_8 = NULL ;
if ( error )
return error ;
if ( V_86 )
V_84 = V_83 ;
else
V_84 = NULL ;
break;
}
F_36 ( V_3 , & V_3 -> V_87 ) ;
}
if ( ! V_84 )
return 0 ;
ASSERT ( V_3 -> V_87 . V_6 == 0 ) ;
V_82 = & V_3 -> V_87 . V_7 [ 0 ] ;
error = F_37 ( V_3 , V_82 , V_84 ) ;
if ( error ) {
V_84 -> V_8 = NULL ;
return error ;
}
V_72 = V_82 -> V_8 -> V_16 ;
if ( V_72 -> V_15 . V_27 . V_93 ) {
if ( F_38 ( V_72 -> V_15 . V_27 . V_93 ) == V_84 -> V_30 ) {
V_8 = V_84 -> V_8 ;
} else {
ASSERT ( V_3 -> V_89 ) ;
V_8 = V_3 -> V_92 . V_8 ;
}
V_72 = V_8 -> V_16 ;
V_72 -> V_15 . V_27 . V_94 = F_39 ( V_82 -> V_30 ) ;
F_27 ( V_3 -> args -> V_73 , V_8 ,
F_28 ( V_72 , & V_72 -> V_15 . V_27 ,
sizeof( V_72 -> V_15 . V_27 ) ) ) ;
}
V_72 = V_82 -> V_8 -> V_16 ;
if ( V_72 -> V_15 . V_27 . V_94 ) {
if ( F_38 ( V_72 -> V_15 . V_27 . V_94 ) == V_84 -> V_30 ) {
V_8 = V_84 -> V_8 ;
} else {
ASSERT ( V_3 -> V_89 ) ;
V_8 = V_3 -> V_92 . V_8 ;
}
V_72 = V_8 -> V_16 ;
V_72 -> V_15 . V_27 . V_93 = F_39 ( V_82 -> V_30 ) ;
F_27 ( V_3 -> args -> V_73 , V_8 ,
F_28 ( V_72 , & V_72 -> V_15 . V_27 ,
sizeof( V_72 -> V_15 . V_27 ) ) ) ;
}
V_84 -> V_8 = NULL ;
return 0 ;
}
STATIC int
F_37 (
struct V_80 * V_3 ,
struct V_81 * V_95 ,
struct V_81 * V_96 )
{
struct V_14 * V_72 ;
struct V_14 * V_97 ;
struct V_98 * V_99 ;
struct V_17 V_100 ;
struct V_70 * args ;
struct V_9 * V_8 ;
struct V_59 * V_60 ;
struct V_57 * V_58 ;
struct V_101 * V_102 ;
T_2 V_30 ;
int V_33 ;
int error ;
int V_103 ;
F_40 ( V_3 -> args ) ;
args = V_3 -> args ;
error = F_41 ( args , & V_30 ) ;
if ( error )
return error ;
V_60 = args -> V_60 ;
V_58 = args -> V_73 ;
error = F_25 ( V_58 , V_60 , V_30 , - 1 , & V_8 , args -> V_71 ) ;
if ( error )
return error ;
V_72 = V_8 -> V_16 ;
V_97 = V_95 -> V_8 -> V_16 ;
if ( V_97 -> V_15 . V_27 . V_25 == F_42 ( V_32 ) ||
V_97 -> V_15 . V_27 . V_25 == F_42 ( V_26 ) ) {
struct V_17 V_104 ;
V_60 -> V_77 -> V_21 ( & V_104 , V_97 ) ;
V_99 = V_60 -> V_77 -> V_105 ( V_97 ) ;
V_103 = ( int ) ( ( char * ) & V_99 [ V_104 . V_35 ] - ( char * ) V_97 ) ;
V_33 = V_104 . V_33 ;
F_22 ( V_58 , V_8 , V_67 ) ;
} else {
struct V_106 V_107 ;
struct V_108 * V_109 ;
V_102 = ( V_110 * ) V_97 ;
V_60 -> V_77 -> V_111 ( & V_107 , V_102 ) ;
V_109 = V_60 -> V_77 -> V_112 ( V_102 ) ;
ASSERT ( V_107 . V_25 == V_54 ||
V_107 . V_25 == V_55 ) ;
V_103 = ( int ) ( ( char * ) & V_109 [ V_107 . V_35 ] - ( char * ) V_102 ) ;
V_33 = 0 ;
F_22 ( V_58 , V_8 , V_69 ) ;
}
memcpy ( V_72 , V_97 , V_103 ) ;
if ( V_97 -> V_15 . V_27 . V_25 == F_42 ( V_26 ) ||
V_97 -> V_15 . V_27 . V_25 == F_42 ( V_55 ) ) {
struct V_113 * V_114 = (struct V_113 * ) V_72 ;
V_114 -> V_15 . V_27 . V_30 = F_15 ( V_8 -> V_31 ) ;
}
F_27 ( V_58 , V_8 , 0 , V_103 - 1 ) ;
V_8 -> V_51 = V_95 -> V_8 -> V_51 ;
F_43 ( V_8 , V_95 -> V_8 ) ;
V_95 -> V_8 = V_8 ;
V_95 -> V_30 = V_30 ;
error = F_23 ( args ,
( args -> V_71 == V_115 ) ? args -> V_116 -> V_117 : 0 ,
V_33 + 1 , & V_8 , args -> V_71 ) ;
if ( error )
return error ;
V_72 = V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_100 , V_72 ) ;
V_99 = V_60 -> V_77 -> V_105 ( V_72 ) ;
V_99 [ 0 ] . V_118 = F_39 ( V_95 -> V_118 ) ;
V_99 [ 0 ] . V_119 = F_39 ( V_95 -> V_30 ) ;
V_99 [ 1 ] . V_118 = F_39 ( V_96 -> V_118 ) ;
V_99 [ 1 ] . V_119 = F_39 ( V_96 -> V_30 ) ;
V_100 . V_35 = 2 ;
V_60 -> V_77 -> V_78 ( V_72 , & V_100 ) ;
#ifdef F_5
if ( V_97 -> V_15 . V_27 . V_25 == F_42 ( V_54 ) ||
V_97 -> V_15 . V_27 . V_25 == F_42 ( V_55 ) ) {
ASSERT ( V_95 -> V_30 >= args -> V_116 -> V_117 &&
V_95 -> V_30 < args -> V_116 -> V_120 ) ;
ASSERT ( V_96 -> V_30 >= args -> V_116 -> V_117 &&
V_96 -> V_30 < args -> V_116 -> V_120 ) ;
}
#endif
F_27 ( V_58 , V_8 ,
F_28 ( V_72 , V_99 , sizeof( V_121 ) * 2 ) ) ;
return 0 ;
}
STATIC int
F_35 (
struct V_80 * V_3 ,
struct V_81 * V_82 ,
struct V_81 * V_83 ,
struct V_81 * V_84 ,
int V_122 ,
int * V_123 )
{
struct V_14 * V_72 ;
struct V_17 V_100 ;
T_2 V_30 ;
int V_124 ;
int error ;
int V_125 ;
struct V_59 * V_60 = V_3 -> args -> V_60 ;
F_44 ( V_3 -> args ) ;
V_72 = V_82 -> V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_100 , V_72 ) ;
V_125 = V_3 -> V_89 && V_3 -> args -> V_71 == V_126 ;
V_124 = 1 + V_125 ;
if ( V_100 . V_35 + V_124 > V_3 -> args -> V_116 -> V_37 ) {
error = F_41 ( V_3 -> args , & V_30 ) ;
if ( error )
return error ;
error = F_23 ( V_3 -> args , V_30 , V_122 ,
& V_83 -> V_8 , V_3 -> args -> V_71 ) ;
if ( error )
return error ;
V_83 -> V_30 = V_30 ;
V_83 -> V_25 = V_32 ;
F_45 ( V_3 , V_82 , V_83 ) ;
error = F_46 ( V_3 , V_82 , V_83 ) ;
if ( error )
return error ;
* V_123 = 1 ;
} else {
* V_123 = 0 ;
}
V_72 = V_82 -> V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_100 , V_72 ) ;
if ( V_82 -> V_127 <= V_100 . V_35 ) {
V_82 -> V_127 ++ ;
F_47 ( V_3 , V_82 , V_84 ) ;
if ( V_125 ) {
if ( V_3 -> V_91 )
V_82 -> V_127 ++ ;
F_47 ( V_3 , V_82 , & V_3 -> V_92 ) ;
V_3 -> V_89 = 0 ;
}
} else {
V_83 -> V_127 ++ ;
F_47 ( V_3 , V_83 , V_84 ) ;
if ( V_125 ) {
if ( V_3 -> V_91 )
V_83 -> V_127 ++ ;
F_47 ( V_3 , V_83 , & V_3 -> V_92 ) ;
V_3 -> V_89 = 0 ;
}
}
return 0 ;
}
STATIC void
F_45 (
struct V_80 * V_3 ,
struct V_81 * V_95 ,
struct V_81 * V_96 )
{
struct V_14 * V_128 ;
struct V_14 * V_129 ;
struct V_14 * V_130 ;
struct V_98 * V_131 ;
struct V_98 * V_132 ;
struct V_98 * V_133 ;
struct V_98 * V_134 ;
struct V_17 V_135 ;
struct V_17 V_136 ;
struct V_57 * V_58 ;
int V_35 ;
int V_137 ;
int V_138 = 0 ;
struct V_59 * V_60 = V_3 -> args -> V_60 ;
F_48 ( V_3 -> args ) ;
V_128 = V_95 -> V_8 -> V_16 ;
V_129 = V_96 -> V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_135 , V_128 ) ;
V_60 -> V_77 -> V_21 ( & V_136 , V_129 ) ;
V_131 = V_60 -> V_77 -> V_105 ( V_128 ) ;
V_132 = V_60 -> V_77 -> V_105 ( V_129 ) ;
if ( V_135 . V_35 > 0 && V_136 . V_35 > 0 &&
( ( F_38 ( V_132 [ 0 ] . V_118 ) < F_38 ( V_131 [ 0 ] . V_118 ) ) ||
( F_38 ( V_132 [ V_136 . V_35 - 1 ] . V_118 ) <
F_38 ( V_131 [ V_135 . V_35 - 1 ] . V_118 ) ) ) ) {
V_130 = V_128 ;
V_128 = V_129 ;
V_129 = V_130 ;
V_60 -> V_77 -> V_21 ( & V_135 , V_128 ) ;
V_60 -> V_77 -> V_21 ( & V_136 , V_129 ) ;
V_131 = V_60 -> V_77 -> V_105 ( V_128 ) ;
V_132 = V_60 -> V_77 -> V_105 ( V_129 ) ;
V_138 = 1 ;
}
V_35 = ( V_135 . V_35 - V_136 . V_35 ) / 2 ;
if ( V_35 == 0 )
return;
V_58 = V_3 -> args -> V_73 ;
if ( V_35 > 0 ) {
V_137 = V_136 . V_35 ;
if ( V_137 > 0 ) {
V_137 *= ( V_139 ) sizeof( V_121 ) ;
V_133 = & V_132 [ 0 ] ;
V_134 = & V_132 [ V_35 ] ;
memmove ( V_134 , V_133 , V_137 ) ;
}
V_136 . V_35 += V_35 ;
V_137 = V_35 * ( V_139 ) sizeof( V_121 ) ;
V_133 = & V_131 [ V_135 . V_35 - V_35 ] ;
V_134 = & V_132 [ 0 ] ;
memcpy ( V_134 , V_133 , V_137 ) ;
V_135 . V_35 -= V_35 ;
} else {
V_35 = - V_35 ;
V_137 = V_35 * ( V_139 ) sizeof( V_121 ) ;
V_133 = & V_132 [ 0 ] ;
V_134 = & V_131 [ V_135 . V_35 ] ;
memcpy ( V_134 , V_133 , V_137 ) ;
V_135 . V_35 += V_35 ;
F_27 ( V_58 , V_95 -> V_8 ,
F_28 ( V_128 , V_134 , V_137 ) ) ;
V_137 = V_136 . V_35 - V_35 ;
V_137 *= ( V_139 ) sizeof( V_121 ) ;
V_133 = & V_132 [ V_35 ] ;
V_134 = & V_132 [ 0 ] ;
memmove ( V_134 , V_133 , V_137 ) ;
V_136 . V_35 -= V_35 ;
}
V_60 -> V_77 -> V_78 ( V_128 , & V_135 ) ;
F_27 ( V_58 , V_95 -> V_8 ,
F_28 ( V_128 , & V_128 -> V_15 , V_60 -> V_77 -> V_79 ) ) ;
V_60 -> V_77 -> V_78 ( V_129 , & V_136 ) ;
F_27 ( V_58 , V_96 -> V_8 ,
F_28 ( V_129 , & V_129 -> V_15 ,
V_60 -> V_77 -> V_79 +
( sizeof( V_132 [ 0 ] ) * V_136 . V_35 ) ) ) ;
if ( V_138 ) {
V_128 = V_95 -> V_8 -> V_16 ;
V_129 = V_96 -> V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_135 , V_128 ) ;
V_60 -> V_77 -> V_21 ( & V_136 , V_129 ) ;
V_131 = V_60 -> V_77 -> V_105 ( V_128 ) ;
V_132 = V_60 -> V_77 -> V_105 ( V_129 ) ;
}
V_95 -> V_118 = F_38 ( V_131 [ V_135 . V_35 - 1 ] . V_118 ) ;
V_96 -> V_118 = F_38 ( V_132 [ V_136 . V_35 - 1 ] . V_118 ) ;
if ( V_95 -> V_127 >= V_135 . V_35 ) {
V_96 -> V_127 = V_95 -> V_127 - V_135 . V_35 ;
V_95 -> V_127 = V_135 . V_35 + 1 ;
}
}
STATIC void
F_47 (
struct V_80 * V_3 ,
struct V_81 * V_82 ,
struct V_81 * V_83 )
{
struct V_14 * V_72 ;
struct V_17 V_100 ;
struct V_98 * V_99 ;
int V_137 ;
struct V_59 * V_60 = V_3 -> args -> V_60 ;
F_49 ( V_3 -> args ) ;
V_72 = V_82 -> V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_100 , V_72 ) ;
V_99 = V_60 -> V_77 -> V_105 ( V_72 ) ;
ASSERT ( V_82 -> V_127 >= 0 && V_82 -> V_127 <= V_100 . V_35 ) ;
ASSERT ( V_83 -> V_30 != 0 ) ;
if ( V_3 -> args -> V_71 == V_115 )
ASSERT ( V_83 -> V_30 >= V_3 -> args -> V_116 -> V_117 &&
V_83 -> V_30 < V_3 -> args -> V_116 -> V_120 ) ;
V_137 = 0 ;
if ( V_82 -> V_127 < V_100 . V_35 ) {
V_137 = ( V_100 . V_35 - V_82 -> V_127 ) * ( V_139 ) sizeof( * V_99 ) ;
memmove ( & V_99 [ V_82 -> V_127 + 1 ] , & V_99 [ V_82 -> V_127 ] , V_137 ) ;
}
V_99 [ V_82 -> V_127 ] . V_118 = F_39 ( V_83 -> V_118 ) ;
V_99 [ V_82 -> V_127 ] . V_119 = F_39 ( V_83 -> V_30 ) ;
F_27 ( V_3 -> args -> V_73 , V_82 -> V_8 ,
F_28 ( V_72 , & V_99 [ V_82 -> V_127 ] ,
V_137 + sizeof( * V_99 ) ) ) ;
V_100 . V_35 += 1 ;
V_60 -> V_77 -> V_78 ( V_72 , & V_100 ) ;
F_27 ( V_3 -> args -> V_73 , V_82 -> V_8 ,
F_28 ( V_72 , & V_72 -> V_15 , V_60 -> V_77 -> V_79 ) ) ;
V_82 -> V_118 = F_38 ( V_99 [ V_100 . V_35 - 1 ] . V_118 ) ;
}
int
F_50 (
struct V_80 * V_3 )
{
struct V_81 * V_140 ;
struct V_81 * V_141 ;
int V_86 = 0 ;
int error ;
F_51 ( V_3 -> args ) ;
V_140 = & V_3 -> V_87 . V_7 [ V_3 -> V_87 . V_6 - 1 ] ;
V_141 = & V_3 -> V_5 . V_7 [ V_3 -> V_87 . V_6 - 1 ] ;
ASSERT ( V_3 -> V_87 . V_7 [ 0 ] . V_25 == V_32 ) ;
ASSERT ( V_140 -> V_25 == V_49 ||
V_140 -> V_25 == V_54 ) ;
for ( ; V_3 -> V_87 . V_6 >= 2 ; V_140 -- , V_141 -- ,
V_3 -> V_87 . V_6 -- ) {
switch ( V_140 -> V_25 ) {
case V_49 :
error = F_52 ( V_3 , & V_86 ) ;
if ( error )
return error ;
if ( V_86 == 0 )
return 0 ;
F_53 ( V_3 , V_140 , V_141 ) ;
break;
case V_54 :
error = F_54 ( V_3 , & V_86 ) ;
if ( error )
return error ;
if ( V_86 == 0 )
return 0 ;
F_55 ( V_3 , V_140 , V_141 ) ;
break;
case V_32 :
F_56 ( V_3 , V_140 ) ;
F_36 ( V_3 , & V_3 -> V_87 ) ;
error = F_57 ( V_3 , & V_86 ) ;
if ( error )
return error ;
if ( V_86 == 0 )
return 0 ;
F_58 ( V_3 , V_140 , V_141 ) ;
break;
}
F_36 ( V_3 , & V_3 -> V_5 ) ;
error = F_59 ( V_3 , V_140 , V_141 ) ;
F_3 ( V_3 ) ;
if ( error )
return error ;
error = F_60 ( V_3 -> args , V_140 -> V_30 ,
V_140 -> V_8 ) ;
V_140 -> V_8 = NULL ;
if ( error )
return error ;
}
F_56 ( V_3 , V_140 ) ;
F_36 ( V_3 , & V_3 -> V_87 ) ;
error = F_61 ( V_3 , & V_3 -> V_87 . V_7 [ 0 ] ) ;
return error ;
}
static void
F_62 ( struct V_47 * V_142 , T_4 V_33 )
{
T_5 V_25 = V_142 -> V_25 ;
if ( V_33 == 1 ) {
ASSERT ( V_25 == F_42 ( V_54 ) ||
V_25 == F_42 ( V_55 ) ||
V_25 == F_42 ( V_49 ) ||
V_25 == F_42 ( V_50 ) ) ;
} else {
ASSERT ( V_25 == F_42 ( V_32 ) ||
V_25 == F_42 ( V_26 ) ) ;
}
ASSERT ( ! V_142 -> V_93 ) ;
ASSERT ( ! V_142 -> V_94 ) ;
}
STATIC int
F_61 (
struct V_80 * V_3 ,
struct V_81 * V_143 )
{
struct V_14 * V_97 ;
struct V_70 * args ;
T_2 V_144 ;
struct V_9 * V_8 ;
struct V_17 V_145 ;
struct V_98 * V_99 ;
int error ;
struct V_59 * V_60 = V_3 -> args -> V_60 ;
F_63 ( V_3 -> args ) ;
ASSERT ( V_143 -> V_25 == V_32 ) ;
args = V_3 -> args ;
V_97 = V_143 -> V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_145 , V_97 ) ;
ASSERT ( V_145 . V_93 == 0 ) ;
ASSERT ( V_145 . V_94 == 0 ) ;
if ( V_145 . V_35 > 1 )
return 0 ;
V_99 = V_60 -> V_77 -> V_105 ( V_97 ) ;
V_144 = F_38 ( V_99 [ 0 ] . V_119 ) ;
ASSERT ( V_144 != 0 ) ;
error = F_20 ( args -> V_73 , V_60 , V_144 , - 1 , & V_8 ,
args -> V_71 ) ;
if ( error )
return error ;
F_62 ( V_8 -> V_16 , V_145 . V_33 ) ;
memcpy ( V_143 -> V_8 -> V_16 , V_8 -> V_16 , args -> V_116 -> V_146 ) ;
V_143 -> V_8 -> V_51 = V_8 -> V_51 ;
F_43 ( V_143 -> V_8 , V_8 ) ;
if ( V_145 . V_25 == V_26 ) {
struct V_147 * V_148 = V_143 -> V_8 -> V_16 ;
V_148 -> V_30 = F_15 ( V_143 -> V_8 -> V_31 ) ;
}
F_27 ( args -> V_73 , V_143 -> V_8 , 0 ,
args -> V_116 -> V_146 - 1 ) ;
error = F_60 ( args , V_144 , V_8 ) ;
return error ;
}
STATIC int
F_57 (
struct V_80 * V_3 ,
int * V_86 )
{
struct V_14 * V_72 ;
struct V_81 * V_7 ;
struct V_47 * V_27 ;
T_2 V_30 ;
struct V_9 * V_8 ;
struct V_17 V_100 ;
int V_35 ;
int V_149 ;
int error ;
int V_150 ;
int V_4 ;
struct V_59 * V_60 = V_3 -> args -> V_60 ;
F_64 ( V_3 -> args ) ;
V_7 = & V_3 -> V_87 . V_7 [ V_3 -> V_87 . V_6 - 1 ] ;
V_27 = V_7 -> V_8 -> V_16 ;
V_72 = ( V_151 * ) V_27 ;
V_60 -> V_77 -> V_21 ( & V_100 , V_72 ) ;
if ( V_100 . V_35 > ( V_3 -> args -> V_116 -> V_37 >> 1 ) ) {
* V_86 = 0 ;
return 0 ;
}
if ( V_100 . V_35 == 0 ) {
V_149 = ( V_27 -> V_93 != 0 ) ;
memcpy ( & V_3 -> V_5 , & V_3 -> V_87 , sizeof( V_3 -> V_87 ) ) ;
error = F_65 ( V_3 , & V_3 -> V_5 , V_149 ,
0 , & V_150 ) ;
if ( error )
return error ;
if ( V_150 ) {
* V_86 = 0 ;
} else {
* V_86 = 2 ;
}
return 0 ;
}
V_35 = V_3 -> args -> V_116 -> V_37 ;
V_35 -= V_3 -> args -> V_116 -> V_37 >> 2 ;
V_35 -= V_100 . V_35 ;
V_149 = V_100 . V_93 < V_100 . V_94 ;
for ( V_4 = 0 ; V_4 < 2 ; V_149 = ! V_149 , V_4 ++ ) {
struct V_17 V_152 ;
if ( V_149 )
V_30 = V_100 . V_93 ;
else
V_30 = V_100 . V_94 ;
if ( V_30 == 0 )
continue;
error = F_20 ( V_3 -> args -> V_73 , V_60 ,
V_30 , - 1 , & V_8 , V_3 -> args -> V_71 ) ;
if ( error )
return error ;
V_72 = V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_152 , V_72 ) ;
F_66 ( V_3 -> args -> V_73 , V_8 ) ;
if ( V_35 - V_152 . V_35 >= 0 )
break;
}
if ( V_4 >= 2 ) {
* V_86 = 0 ;
return 0 ;
}
memcpy ( & V_3 -> V_5 , & V_3 -> V_87 , sizeof( V_3 -> V_87 ) ) ;
if ( V_30 < V_7 -> V_30 ) {
error = F_65 ( V_3 , & V_3 -> V_5 , V_149 ,
0 , & V_150 ) ;
} else {
error = F_65 ( V_3 , & V_3 -> V_87 , V_149 ,
0 , & V_150 ) ;
}
if ( error )
return error ;
if ( V_150 ) {
* V_86 = 0 ;
return 0 ;
}
* V_86 = 1 ;
return 0 ;
}
STATIC V_139
F_67 (
struct V_59 * V_60 ,
struct V_9 * V_8 ,
int * V_35 )
{
struct V_14 * V_72 ;
struct V_98 * V_99 ;
struct V_17 V_100 ;
V_72 = V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_100 , V_72 ) ;
if ( V_35 )
* V_35 = V_100 . V_35 ;
if ( ! V_100 . V_35 )
return 0 ;
V_99 = V_60 -> V_77 -> V_105 ( V_72 ) ;
return F_38 ( V_99 [ V_100 . V_35 - 1 ] . V_118 ) ;
}
void
F_36 (
struct V_80 * V_3 ,
struct V_153 * V_87 )
{
struct V_81 * V_7 ;
struct V_14 * V_72 ;
struct V_98 * V_99 ;
T_6 V_154 = 0 ;
int V_33 ;
int V_35 ;
struct V_59 * V_60 = V_3 -> args -> V_60 ;
F_68 ( V_3 -> args ) ;
V_33 = V_87 -> V_6 - 1 ;
V_7 = & V_87 -> V_7 [ V_33 ] ;
switch ( V_7 -> V_25 ) {
case V_49 :
V_154 = F_69 ( V_7 -> V_8 , & V_35 ) ;
if ( V_35 == 0 )
return;
break;
case V_54 :
V_154 = F_70 ( V_60 , V_7 -> V_8 , & V_35 ) ;
if ( V_35 == 0 )
return;
break;
case V_32 :
V_154 = F_67 ( V_60 , V_7 -> V_8 , & V_35 ) ;
if ( V_35 == 0 )
return;
break;
}
for ( V_7 -- , V_33 -- ; V_33 >= 0 ; V_7 -- , V_33 -- ) {
struct V_17 V_100 ;
V_72 = V_7 -> V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_100 , V_72 ) ;
V_99 = V_60 -> V_77 -> V_105 ( V_72 ) ;
if ( F_38 ( V_99 [ V_7 -> V_127 ] . V_118 ) == V_154 )
break;
V_7 -> V_118 = V_154 ;
V_99 [ V_7 -> V_127 ] . V_118 = F_39 ( V_154 ) ;
F_27 ( V_3 -> args -> V_73 , V_7 -> V_8 ,
F_28 ( V_72 , & V_99 [ V_7 -> V_127 ] ,
sizeof( * V_99 ) ) ) ;
V_154 = F_38 ( V_99 [ V_100 . V_35 - 1 ] . V_118 ) ;
}
}
STATIC void
F_56 (
struct V_80 * V_3 ,
struct V_81 * V_140 )
{
struct V_14 * V_72 ;
struct V_17 V_100 ;
struct V_98 * V_99 ;
int V_127 ;
int V_137 ;
struct V_59 * V_60 = V_3 -> args -> V_60 ;
F_71 ( V_3 -> args ) ;
V_72 = V_140 -> V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_100 , V_72 ) ;
ASSERT ( V_140 -> V_127 < V_100 . V_35 ) ;
ASSERT ( V_140 -> V_127 >= 0 ) ;
V_127 = V_140 -> V_127 ;
V_99 = V_60 -> V_77 -> V_105 ( V_72 ) ;
if ( V_127 < V_100 . V_35 - 1 ) {
V_137 = V_100 . V_35 - V_127 - 1 ;
V_137 *= ( V_139 ) sizeof( V_121 ) ;
memmove ( & V_99 [ V_127 ] , & V_99 [ V_127 + 1 ] , V_137 ) ;
F_27 ( V_3 -> args -> V_73 , V_140 -> V_8 ,
F_28 ( V_72 , & V_99 [ V_127 ] , V_137 ) ) ;
V_127 = V_100 . V_35 - 1 ;
}
memset ( & V_99 [ V_127 ] , 0 , sizeof( V_121 ) ) ;
F_27 ( V_3 -> args -> V_73 , V_140 -> V_8 ,
F_28 ( V_72 , & V_99 [ V_127 ] , sizeof( V_99 [ V_127 ] ) ) ) ;
V_100 . V_35 -= 1 ;
V_60 -> V_77 -> V_78 ( V_72 , & V_100 ) ;
F_27 ( V_3 -> args -> V_73 , V_140 -> V_8 ,
F_28 ( V_72 , & V_72 -> V_15 , V_60 -> V_77 -> V_79 ) ) ;
V_140 -> V_118 = F_38 ( V_99 [ V_127 - 1 ] . V_118 ) ;
}
STATIC void
F_58 (
struct V_80 * V_3 ,
struct V_81 * V_140 ,
struct V_81 * V_141 )
{
struct V_14 * V_155 ;
struct V_14 * V_156 ;
struct V_98 * V_157 ;
struct V_98 * V_158 ;
struct V_17 V_159 ;
struct V_17 V_160 ;
struct V_57 * V_58 ;
int V_161 ;
int V_137 ;
struct V_59 * V_60 = V_3 -> args -> V_60 ;
F_72 ( V_3 -> args ) ;
V_155 = V_140 -> V_8 -> V_16 ;
V_156 = V_141 -> V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_159 , V_155 ) ;
V_60 -> V_77 -> V_21 ( & V_160 , V_156 ) ;
V_157 = V_60 -> V_77 -> V_105 ( V_155 ) ;
V_158 = V_60 -> V_77 -> V_105 ( V_156 ) ;
V_58 = V_3 -> args -> V_73 ;
if ( ( F_38 ( V_157 [ 0 ] . V_118 ) <
F_38 ( V_158 [ 0 ] . V_118 ) ) ||
( F_38 ( V_157 [ V_159 . V_35 - 1 ] . V_118 ) <
F_38 ( V_158 [ V_160 . V_35 - 1 ] . V_118 ) ) ) {
V_137 = V_160 . V_35 * sizeof( V_121 ) ;
memmove ( & V_158 [ V_159 . V_35 ] , & V_158 [ 0 ] , V_137 ) ;
V_161 = 0 ;
F_27 ( V_58 , V_141 -> V_8 ,
F_28 ( V_156 , & V_158 [ 0 ] ,
( V_160 . V_35 + V_159 . V_35 ) *
sizeof( V_121 ) ) ) ;
} else {
V_161 = V_160 . V_35 ;
F_27 ( V_58 , V_141 -> V_8 ,
F_28 ( V_156 , & V_158 [ V_161 ] ,
V_159 . V_35 * sizeof( V_121 ) ) ) ;
}
V_137 = V_159 . V_35 * ( V_139 ) sizeof( V_121 ) ;
memcpy ( & V_158 [ V_161 ] , & V_157 [ 0 ] , V_137 ) ;
V_160 . V_35 += V_159 . V_35 ;
V_60 -> V_77 -> V_78 ( V_156 , & V_160 ) ;
F_27 ( V_58 , V_141 -> V_8 ,
F_28 ( V_156 , & V_156 -> V_15 ,
V_60 -> V_77 -> V_79 ) ) ;
V_141 -> V_118 = F_38 ( V_158 [ V_160 . V_35 - 1 ] . V_118 ) ;
}
int
F_73 (
struct V_80 * V_3 ,
int * V_123 )
{
struct V_81 * V_7 ;
struct V_47 * V_162 ;
struct V_14 * V_72 ;
struct V_98 * V_99 ;
struct V_17 V_100 ;
struct V_70 * args ;
T_2 V_30 ;
T_6 V_118 ;
T_6 V_163 ;
int V_164 ;
int V_165 ;
int V_85 ;
int error ;
int V_150 ;
struct V_59 * V_60 = V_3 -> args -> V_60 ;
args = V_3 -> args ;
V_30 = ( args -> V_71 == V_115 ) ? args -> V_116 -> V_117 : 0 ;
for ( V_7 = & V_3 -> V_87 . V_7 [ 0 ] , V_3 -> V_87 . V_6 = 1 ;
V_3 -> V_87 . V_6 <= V_34 ;
V_7 ++ , V_3 -> V_87 . V_6 ++ ) {
V_7 -> V_30 = V_30 ;
error = F_20 ( args -> V_73 , args -> V_60 , V_30 ,
- 1 , & V_7 -> V_8 , args -> V_71 ) ;
if ( error ) {
V_7 -> V_30 = 0 ;
V_3 -> V_87 . V_6 -- ;
return error ;
}
V_162 = V_7 -> V_8 -> V_16 ;
V_7 -> V_25 = F_18 ( V_162 -> V_25 ) ;
if ( V_7 -> V_25 == V_49 ||
V_7 -> V_25 == V_50 ) {
V_7 -> V_25 = V_49 ;
V_7 -> V_118 = F_69 ( V_7 -> V_8 , NULL ) ;
break;
}
if ( V_7 -> V_25 == V_54 ||
V_7 -> V_25 == V_55 ) {
V_7 -> V_25 = V_54 ;
V_7 -> V_118 = F_70 ( args -> V_60 ,
V_7 -> V_8 , NULL ) ;
break;
}
V_7 -> V_25 = V_32 ;
V_72 = V_7 -> V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_100 , V_72 ) ;
V_99 = V_60 -> V_77 -> V_105 ( V_72 ) ;
V_85 = V_100 . V_35 ;
V_7 -> V_118 = F_38 ( V_99 [ V_85 - 1 ] . V_118 ) ;
V_164 = V_165 = V_85 / 2 ;
V_118 = args -> V_118 ;
while ( V_165 > 4 ) {
V_165 /= 2 ;
V_163 = F_38 ( V_99 [ V_164 ] . V_118 ) ;
if ( V_163 < V_118 )
V_164 += V_165 ;
else if ( V_163 > V_118 )
V_164 -= V_165 ;
else
break;
}
ASSERT ( ( V_164 >= 0 ) && ( V_164 < V_85 ) ) ;
ASSERT ( ( V_165 <= 4 ) ||
( F_38 ( V_99 [ V_164 ] . V_118 ) == V_118 ) ) ;
while ( V_164 > 0 &&
F_38 ( V_99 [ V_164 ] . V_118 ) >= V_118 ) {
V_164 -- ;
}
while ( V_164 < V_85 &&
F_38 ( V_99 [ V_164 ] . V_118 ) < V_118 ) {
V_164 ++ ;
}
if ( V_164 == V_85 ) {
V_7 -> V_127 = V_85 - 1 ;
V_30 = F_38 ( V_99 [ V_85 - 1 ] . V_119 ) ;
} else {
V_7 -> V_127 = V_164 ;
V_30 = F_38 ( V_99 [ V_164 ] . V_119 ) ;
}
}
for (; ; ) {
if ( V_7 -> V_25 == V_54 ) {
V_150 = F_74 ( V_7 -> V_8 , args ,
& V_7 -> V_127 , V_3 ) ;
} else if ( V_7 -> V_25 == V_49 ) {
V_150 = F_75 ( V_7 -> V_8 , args ) ;
V_7 -> V_127 = args -> V_127 ;
args -> V_30 = V_7 -> V_30 ;
} else {
ASSERT ( 0 ) ;
return - V_42 ;
}
if ( ( ( V_150 == - V_166 ) || ( V_150 == - V_167 ) ) &&
( V_7 -> V_118 == args -> V_118 ) ) {
error = F_65 ( V_3 , & V_3 -> V_87 , 1 , 1 ,
& V_150 ) ;
if ( error )
return error ;
if ( V_150 == 0 ) {
continue;
} else if ( V_7 -> V_25 == V_49 ) {
V_150 = - V_167 ;
}
}
break;
}
* V_123 = V_150 ;
return 0 ;
}
STATIC int
F_76 (
struct V_59 * V_60 ,
struct V_9 * V_168 ,
struct V_9 * V_169 )
{
struct V_14 * V_128 ;
struct V_14 * V_129 ;
struct V_98 * V_131 ;
struct V_98 * V_132 ;
struct V_17 V_170 ;
struct V_17 V_171 ;
V_128 = V_168 -> V_16 ;
V_129 = V_169 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_170 , V_128 ) ;
V_60 -> V_77 -> V_21 ( & V_171 , V_129 ) ;
V_131 = V_60 -> V_77 -> V_105 ( V_128 ) ;
V_132 = V_60 -> V_77 -> V_105 ( V_129 ) ;
if ( V_170 . V_35 > 0 && V_171 . V_35 > 0 &&
( ( F_38 ( V_132 [ 0 ] . V_118 ) < F_38 ( V_131 [ 0 ] . V_118 ) ) ||
( F_38 ( V_132 [ V_171 . V_35 - 1 ] . V_118 ) <
F_38 ( V_131 [ V_170 . V_35 - 1 ] . V_118 ) ) ) ) {
return 1 ;
}
return 0 ;
}
int
F_46 (
struct V_80 * V_3 ,
struct V_81 * V_172 ,
struct V_81 * V_173 )
{
struct V_47 * V_174 ;
struct V_47 * V_175 ;
struct V_47 * V_176 ;
struct V_70 * args ;
struct V_9 * V_8 ;
int V_119 = 0 ;
int error ;
struct V_59 * V_60 = V_3 -> args -> V_60 ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
V_174 = V_172 -> V_8 -> V_16 ;
V_175 = V_173 -> V_8 -> V_16 ;
ASSERT ( V_172 -> V_25 == V_32 ||
V_172 -> V_25 == V_54 ||
V_172 -> V_25 == V_49 ) ;
switch ( V_172 -> V_25 ) {
case V_49 :
V_119 = F_77 ( V_172 -> V_8 , V_173 -> V_8 ) ;
break;
case V_54 :
V_119 = F_78 ( V_60 , V_172 -> V_8 , V_173 -> V_8 ) ;
break;
case V_32 :
V_119 = F_76 ( V_60 , V_172 -> V_8 , V_173 -> V_8 ) ;
break;
}
if ( V_119 ) {
F_79 ( args ) ;
V_175 -> V_93 = F_39 ( V_172 -> V_30 ) ;
V_175 -> V_94 = V_174 -> V_94 ;
if ( V_174 -> V_94 ) {
error = F_20 ( args -> V_73 , V_60 ,
F_38 ( V_174 -> V_94 ) ,
- 1 , & V_8 , args -> V_71 ) ;
if ( error )
return error ;
ASSERT ( V_8 != NULL ) ;
V_176 = V_8 -> V_16 ;
ASSERT ( V_176 -> V_25 == V_174 -> V_25 ) ;
ASSERT ( F_38 ( V_176 -> V_93 ) == V_172 -> V_30 ) ;
V_176 -> V_93 = F_39 ( V_173 -> V_30 ) ;
F_27 ( args -> V_73 , V_8 , 0 , sizeof( * V_176 ) - 1 ) ;
}
V_174 -> V_94 = F_39 ( V_173 -> V_30 ) ;
} else {
F_80 ( args ) ;
V_175 -> V_93 = V_174 -> V_93 ;
V_175 -> V_94 = F_39 ( V_172 -> V_30 ) ;
if ( V_174 -> V_93 ) {
error = F_20 ( args -> V_73 , V_60 ,
F_38 ( V_174 -> V_93 ) ,
- 1 , & V_8 , args -> V_71 ) ;
if ( error )
return error ;
ASSERT ( V_8 != NULL ) ;
V_176 = V_8 -> V_16 ;
ASSERT ( V_176 -> V_25 == V_174 -> V_25 ) ;
ASSERT ( F_38 ( V_176 -> V_94 ) == V_172 -> V_30 ) ;
V_176 -> V_94 = F_39 ( V_173 -> V_30 ) ;
F_27 ( args -> V_73 , V_8 , 0 , sizeof( * V_176 ) - 1 ) ;
}
V_174 -> V_93 = F_39 ( V_173 -> V_30 ) ;
}
F_27 ( args -> V_73 , V_172 -> V_8 , 0 , sizeof( * V_176 ) - 1 ) ;
F_27 ( args -> V_73 , V_173 -> V_8 , 0 , sizeof( * V_176 ) - 1 ) ;
return 0 ;
}
STATIC int
F_59 (
struct V_80 * V_3 ,
struct V_81 * V_140 ,
struct V_81 * V_141 )
{
struct V_47 * V_177 ;
struct V_47 * V_178 ;
struct V_47 * V_176 ;
struct V_70 * args ;
struct V_9 * V_8 ;
int error ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
V_178 = V_141 -> V_8 -> V_16 ;
V_177 = V_140 -> V_8 -> V_16 ;
ASSERT ( V_141 -> V_25 == V_32 ||
V_141 -> V_25 == V_54 ||
V_141 -> V_25 == V_49 ) ;
ASSERT ( V_141 -> V_25 == V_140 -> V_25 ) ;
ASSERT ( ( F_38 ( V_178 -> V_93 ) == V_140 -> V_30 ) ||
( F_38 ( V_178 -> V_94 ) == V_140 -> V_30 ) ) ;
ASSERT ( ( F_38 ( V_177 -> V_93 ) == V_141 -> V_30 ) ||
( F_38 ( V_177 -> V_94 ) == V_141 -> V_30 ) ) ;
if ( F_38 ( V_178 -> V_94 ) == V_140 -> V_30 ) {
F_81 ( args ) ;
V_178 -> V_94 = V_177 -> V_94 ;
if ( V_177 -> V_94 ) {
error = F_20 ( args -> V_73 , args -> V_60 ,
F_38 ( V_177 -> V_94 ) ,
- 1 , & V_8 , args -> V_71 ) ;
if ( error )
return error ;
ASSERT ( V_8 != NULL ) ;
V_176 = V_8 -> V_16 ;
ASSERT ( V_176 -> V_25 == V_178 -> V_25 ) ;
ASSERT ( F_38 ( V_176 -> V_93 ) == V_140 -> V_30 ) ;
V_176 -> V_93 = F_39 ( V_141 -> V_30 ) ;
F_27 ( args -> V_73 , V_8 , 0 ,
sizeof( * V_176 ) - 1 ) ;
}
} else {
F_82 ( args ) ;
V_178 -> V_93 = V_177 -> V_93 ;
if ( V_177 -> V_93 ) {
error = F_20 ( args -> V_73 , args -> V_60 ,
F_38 ( V_177 -> V_93 ) ,
- 1 , & V_8 , args -> V_71 ) ;
if ( error )
return error ;
ASSERT ( V_8 != NULL ) ;
V_176 = V_8 -> V_16 ;
ASSERT ( V_176 -> V_25 == V_178 -> V_25 ) ;
ASSERT ( F_38 ( V_176 -> V_94 ) == V_140 -> V_30 ) ;
V_176 -> V_94 = F_39 ( V_141 -> V_30 ) ;
F_27 ( args -> V_73 , V_8 , 0 ,
sizeof( * V_176 ) - 1 ) ;
}
}
F_27 ( args -> V_73 , V_141 -> V_8 , 0 , sizeof( * V_178 ) - 1 ) ;
return 0 ;
}
int
F_65 (
struct V_80 * V_3 ,
struct V_153 * V_87 ,
int V_149 ,
int V_179 ,
int * V_123 )
{
struct V_81 * V_7 ;
struct V_47 * V_27 ;
struct V_14 * V_72 ;
struct V_70 * args ;
struct V_98 * V_99 ;
struct V_17 V_100 ;
T_2 V_30 = 0 ;
int V_33 ;
int error ;
struct V_59 * V_60 = V_3 -> args -> V_60 ;
F_83 ( V_3 -> args ) ;
args = V_3 -> args ;
ASSERT ( args != NULL ) ;
ASSERT ( V_87 != NULL ) ;
ASSERT ( ( V_87 -> V_6 > 0 ) && ( V_87 -> V_6 < V_34 ) ) ;
V_33 = ( V_87 -> V_6 - 1 ) - 1 ;
for ( V_7 = & V_87 -> V_7 [ V_33 ] ; V_33 >= 0 ; V_7 -- , V_33 -- ) {
V_72 = V_7 -> V_8 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_100 , V_72 ) ;
V_99 = V_60 -> V_77 -> V_105 ( V_72 ) ;
if ( V_149 && ( V_7 -> V_127 < V_100 . V_35 - 1 ) ) {
V_7 -> V_127 ++ ;
V_30 = F_38 ( V_99 [ V_7 -> V_127 ] . V_119 ) ;
break;
} else if ( ! V_149 && ( V_7 -> V_127 > 0 ) ) {
V_7 -> V_127 -- ;
V_30 = F_38 ( V_99 [ V_7 -> V_127 ] . V_119 ) ;
break;
}
}
if ( V_33 < 0 ) {
* V_123 = - V_166 ;
ASSERT ( args -> V_180 & V_181 ) ;
return 0 ;
}
for ( V_7 ++ , V_33 ++ ; V_33 < V_87 -> V_6 ; V_7 ++ , V_33 ++ ) {
if ( V_179 )
F_66 ( args -> V_73 , V_7 -> V_8 ) ;
V_7 -> V_30 = V_30 ;
error = F_20 ( args -> V_73 , V_60 , V_30 , - 1 ,
& V_7 -> V_8 , args -> V_71 ) ;
if ( error )
return error ;
V_27 = V_7 -> V_8 -> V_16 ;
ASSERT ( V_27 -> V_25 == F_42 ( V_32 ) ||
V_27 -> V_25 == F_42 ( V_26 ) ||
V_27 -> V_25 == F_42 ( V_54 ) ||
V_27 -> V_25 == F_42 ( V_55 ) ||
V_27 -> V_25 == F_42 ( V_49 ) ||
V_27 -> V_25 == F_42 ( V_50 ) ) ;
switch ( F_18 ( V_27 -> V_25 ) ) {
case V_32 :
case V_26 :
V_7 -> V_25 = V_32 ;
V_72 = ( V_151 * ) V_27 ;
V_60 -> V_77 -> V_21 ( & V_100 , V_72 ) ;
V_99 = V_60 -> V_77 -> V_105 ( V_72 ) ;
V_7 -> V_118 = F_38 ( V_99 [ V_100 . V_35 - 1 ] . V_118 ) ;
if ( V_149 )
V_7 -> V_127 = 0 ;
else
V_7 -> V_127 = V_100 . V_35 - 1 ;
V_30 = F_38 ( V_99 [ V_7 -> V_127 ] . V_119 ) ;
break;
case V_49 :
case V_50 :
V_7 -> V_25 = V_49 ;
ASSERT ( V_33 == V_87 -> V_6 - 1 ) ;
V_7 -> V_127 = 0 ;
V_7 -> V_118 = F_69 ( V_7 -> V_8 , NULL ) ;
break;
case V_54 :
case V_55 :
V_7 -> V_25 = V_54 ;
ASSERT ( V_33 == V_87 -> V_6 - 1 ) ;
V_7 -> V_127 = 0 ;
V_7 -> V_118 = F_70 ( args -> V_60 ,
V_7 -> V_8 , NULL ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
}
* V_123 = 0 ;
return 0 ;
}
T_6
F_84 ( const T_7 * V_182 , int V_183 )
{
T_6 V_184 ;
for ( V_184 = 0 ; V_183 >= 4 ; V_183 -= 4 , V_182 += 4 )
V_184 = ( V_182 [ 0 ] << 21 ) ^ ( V_182 [ 1 ] << 14 ) ^ ( V_182 [ 2 ] << 7 ) ^
( V_182 [ 3 ] << 0 ) ^ F_85 ( V_184 , 7 * 4 ) ;
switch ( V_183 ) {
case 3 :
return ( V_182 [ 0 ] << 14 ) ^ ( V_182 [ 1 ] << 7 ) ^ ( V_182 [ 2 ] << 0 ) ^
F_85 ( V_184 , 7 * 3 ) ;
case 2 :
return ( V_182 [ 0 ] << 7 ) ^ ( V_182 [ 1 ] << 0 ) ^ F_85 ( V_184 , 7 * 2 ) ;
case 1 :
return ( V_182 [ 0 ] << 0 ) ^ F_85 ( V_184 , 7 * 1 ) ;
default:
return V_184 ;
}
}
enum V_185
F_86 (
struct V_70 * args ,
const unsigned char * V_182 ,
int V_186 )
{
return ( args -> V_183 == V_186 && memcmp ( args -> V_182 , V_182 , V_186 ) == 0 ) ?
V_187 : V_188 ;
}
static T_6
F_87 (
struct V_189 * V_182 )
{
return F_84 ( V_182 -> V_182 , V_182 -> V_186 ) ;
}
int
F_88 (
struct V_70 * args ,
T_8 * V_61 ,
int V_35 )
{
struct V_57 * V_58 = args -> V_73 ;
struct V_59 * V_60 = args -> V_60 ;
int V_190 = args -> V_71 ;
T_9 V_191 = V_60 -> V_192 . V_193 ;
struct V_194 V_195 , * V_196 ;
int V_197 , error , V_198 , V_4 , V_199 ;
error = F_89 ( V_58 , V_60 , V_35 , V_61 , V_190 ) ;
if ( error )
return error ;
V_197 = 1 ;
ASSERT ( args -> V_200 != NULL ) ;
error = F_90 ( V_58 , V_60 , * V_61 , V_35 ,
F_91 ( V_190 ) | V_201 | V_202 ,
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
V_196 = F_92 ( sizeof( * V_196 ) * V_35 , V_207 ) ;
for ( V_205 = * V_61 , V_199 = 0 ; V_205 < * V_61 + V_35 ; ) {
V_197 = F_93 ( V_208 , V_35 ) ;
V_206 = ( int ) ( * V_61 + V_35 - V_205 ) ;
error = F_90 ( V_58 , V_60 , V_205 , V_206 ,
F_91 ( V_190 ) | V_201 ,
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
if ( V_198 != V_35 || V_196 [ 0 ] . V_210 != * V_61 ||
V_196 [ V_199 - 1 ] . V_210 + V_196 [ V_199 - 1 ] . V_211 !=
* V_61 + V_35 ) {
error = - V_88 ;
goto V_209;
}
args -> V_203 -= V_60 -> V_192 . V_193 - V_191 ;
V_209:
if ( V_196 != & V_195 )
F_94 ( V_196 ) ;
return error ;
}
int
F_41 (
struct V_70 * args ,
T_2 * V_212 )
{
T_8 V_61 ;
int error ;
F_95 ( args ) ;
V_61 = args -> V_116 -> V_117 ;
error = F_88 ( args , & V_61 , args -> V_116 -> V_213 ) ;
if ( ! error )
* V_212 = ( T_2 ) V_61 ;
return error ;
}
STATIC int
F_96 (
struct V_70 * args ,
T_2 * V_214 ,
struct V_9 * * V_215 )
{
struct V_47 * V_216 ;
struct V_47 * V_217 ;
struct V_14 * V_218 ;
struct V_14 * V_219 ;
struct V_101 * V_220 ;
struct V_98 * V_99 ;
struct V_17 V_221 ;
struct V_59 * V_60 ;
struct V_57 * V_58 ;
struct V_10 * V_11 ;
struct V_9 * V_222 ;
struct V_9 * V_223 ;
struct V_9 * V_224 ;
struct V_9 * V_225 ;
T_6 V_226 ;
T_8 V_227 ;
T_2 V_228 ;
T_2 V_229 ;
T_2 V_230 ;
T_2 V_231 ;
int error ;
int V_190 ;
int V_232 ;
int V_33 ;
int V_233 ;
F_97 ( args ) ;
V_222 = * V_215 ;
V_228 = * V_214 ;
V_58 = args -> V_73 ;
V_60 = args -> V_60 ;
V_190 = args -> V_71 ;
ASSERT ( V_190 == V_115 ) ;
V_11 = V_60 -> V_234 ;
V_227 = args -> V_116 -> V_120 ;
error = F_98 ( V_58 , V_60 , & V_227 , V_190 ) ;
if ( error )
return error ;
if ( F_99 ( V_227 == 0 ) ) {
F_100 ( L_1 , V_235 ,
V_11 ) ;
return - V_42 ;
}
V_229 = ( T_2 ) V_227 - args -> V_116 -> V_213 ;
error = F_20 ( V_58 , V_60 , V_229 , - 1 , & V_223 , V_190 ) ;
if ( error )
return error ;
memcpy ( V_222 -> V_16 , V_223 -> V_16 , args -> V_116 -> V_146 ) ;
F_27 ( V_58 , V_222 , 0 , args -> V_116 -> V_146 - 1 ) ;
V_216 = V_222 -> V_16 ;
if ( V_216 -> V_25 == F_42 ( V_54 ) ||
V_216 -> V_25 == F_42 ( V_55 ) ) {
struct V_106 V_107 ;
struct V_108 * V_109 ;
V_220 = ( V_110 * ) V_216 ;
V_60 -> V_77 -> V_111 ( & V_107 , V_220 ) ;
V_109 = V_60 -> V_77 -> V_112 ( V_220 ) ;
V_233 = 0 ;
V_226 = F_38 ( V_109 [ V_107 . V_35 - 1 ] . V_118 ) ;
} else {
struct V_17 V_236 ;
V_219 = ( V_151 * ) V_216 ;
V_60 -> V_77 -> V_21 ( & V_236 , V_219 ) ;
V_99 = V_60 -> V_77 -> V_105 ( V_219 ) ;
V_233 = V_236 . V_33 ;
V_226 = F_38 ( V_99 [ V_236 . V_35 - 1 ] . V_118 ) ;
}
V_224 = V_225 = NULL ;
if ( ( V_230 = F_38 ( V_216 -> V_94 ) ) ) {
error = F_20 ( V_58 , V_60 , V_230 , - 1 , & V_224 , V_190 ) ;
if ( error )
goto V_237;
V_217 = V_224 -> V_16 ;
if ( F_99 (
F_38 ( V_217 -> V_93 ) != V_229 ||
V_217 -> V_25 != V_216 -> V_25 ) ) {
F_100 ( L_2 ,
V_235 , V_11 ) ;
error = - V_42 ;
goto V_237;
}
V_217 -> V_93 = F_39 ( V_228 ) ;
F_27 ( V_58 , V_224 ,
F_28 ( V_217 , & V_217 -> V_93 ,
sizeof( V_217 -> V_93 ) ) ) ;
V_224 = NULL ;
}
if ( ( V_230 = F_38 ( V_216 -> V_93 ) ) ) {
error = F_20 ( V_58 , V_60 , V_230 , - 1 , & V_224 , V_190 ) ;
if ( error )
goto V_237;
V_217 = V_224 -> V_16 ;
if ( F_99 (
F_38 ( V_217 -> V_94 ) != V_229 ||
V_217 -> V_25 != V_216 -> V_25 ) ) {
F_100 ( L_3 ,
V_235 , V_11 ) ;
error = - V_42 ;
goto V_237;
}
V_217 -> V_94 = F_39 ( V_228 ) ;
F_27 ( V_58 , V_224 ,
F_28 ( V_217 , & V_217 -> V_94 ,
sizeof( V_217 -> V_94 ) ) ) ;
V_224 = NULL ;
}
V_231 = args -> V_116 -> V_117 ;
V_33 = - 1 ;
for (; ; ) {
error = F_20 ( V_58 , V_60 , V_231 , - 1 , & V_225 , V_190 ) ;
if ( error )
goto V_237;
V_218 = V_225 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_221 , V_218 ) ;
if ( V_33 >= 0 && V_33 != V_221 . V_33 + 1 ) {
F_100 ( L_4 ,
V_235 , V_11 ) ;
error = - V_42 ;
goto V_237;
}
V_33 = V_221 . V_33 ;
V_99 = V_60 -> V_77 -> V_105 ( V_218 ) ;
for ( V_232 = 0 ;
V_232 < V_221 . V_35 &&
F_38 ( V_99 [ V_232 ] . V_118 ) < V_226 ;
V_232 ++ )
continue;
if ( V_232 == V_221 . V_35 ) {
F_100 ( L_5 ,
V_235 , V_11 ) ;
error = - V_42 ;
goto V_237;
}
V_231 = F_38 ( V_99 [ V_232 ] . V_119 ) ;
if ( V_33 == V_233 + 1 )
break;
F_66 ( V_58 , V_225 ) ;
V_225 = NULL ;
}
for (; ; ) {
for (;
V_232 < V_221 . V_35 &&
F_38 ( V_99 [ V_232 ] . V_119 ) != V_229 ;
V_232 ++ )
continue;
if ( V_232 < V_221 . V_35 )
break;
V_231 = V_221 . V_93 ;
F_66 ( V_58 , V_225 ) ;
V_225 = NULL ;
if ( F_99 ( V_231 == 0 ) ) {
F_100 ( L_6 ,
V_235 , V_11 ) ;
error = - V_42 ;
goto V_237;
}
error = F_20 ( V_58 , V_60 , V_231 , - 1 , & V_225 , V_190 ) ;
if ( error )
goto V_237;
V_218 = V_225 -> V_16 ;
V_60 -> V_77 -> V_21 ( & V_221 , V_218 ) ;
if ( V_221 . V_33 != V_33 ) {
F_100 ( L_7 ,
V_235 , V_11 ) ;
error = - V_42 ;
goto V_237;
}
V_99 = V_60 -> V_77 -> V_105 ( V_218 ) ;
V_232 = 0 ;
}
V_99 [ V_232 ] . V_119 = F_39 ( V_228 ) ;
F_27 ( V_58 , V_225 ,
F_28 ( V_218 , & V_99 [ V_232 ] . V_119 ,
sizeof( V_99 [ V_232 ] . V_119 ) ) ) ;
* V_214 = V_229 ;
* V_215 = V_223 ;
return 0 ;
V_237:
if ( V_225 )
F_66 ( V_58 , V_225 ) ;
if ( V_224 )
F_66 ( V_58 , V_224 ) ;
F_66 ( V_58 , V_223 ) ;
return error ;
}
int
F_60 (
T_10 * args ,
T_2 V_228 ,
struct V_9 * V_222 )
{
T_11 * V_60 ;
int V_237 , error , V_190 , V_35 ;
T_12 * V_58 ;
F_101 ( args ) ;
V_60 = args -> V_60 ;
V_190 = args -> V_71 ;
V_58 = args -> V_73 ;
V_35 = args -> V_116 -> V_213 ;
for (; ; ) {
error = F_102 ( V_58 , V_60 , V_228 , V_35 ,
F_91 ( V_190 ) | V_201 ,
0 , args -> V_200 , args -> V_204 , & V_237 ) ;
if ( error == - V_88 ) {
if ( V_190 != V_115 )
break;
error = F_96 ( args , & V_228 ,
& V_222 ) ;
if ( error )
break;
} else {
break;
}
}
F_103 ( V_58 , V_222 ) ;
return error ;
}
STATIC int
F_104 (
int V_197 ,
T_13 * V_196 ,
T_2 V_61 ,
int V_35 )
{
int V_4 ;
T_8 V_238 ;
for ( V_4 = 0 , V_238 = V_61 ; V_4 < V_197 ; V_4 ++ ) {
if ( V_196 [ V_4 ] . V_239 == V_240 ||
V_196 [ V_4 ] . V_239 == V_241 ) {
return 0 ;
}
if ( V_238 != V_196 [ V_4 ] . V_210 ) {
return 0 ;
}
V_238 += V_196 [ V_4 ] . V_211 ;
}
return V_238 == V_61 + V_35 ;
}
static int
F_105 (
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
V_195 = F_106 ( V_245 * sizeof( struct V_242 ) ,
V_207 | V_2 ) ;
if ( ! V_195 )
return - V_246 ;
* V_196 = V_195 ;
}
* V_243 = V_245 ;
V_195 = * V_196 ;
for ( V_4 = 0 ; V_4 < * V_243 ; V_4 ++ ) {
ASSERT ( V_244 [ V_4 ] . V_239 != V_241 &&
V_244 [ V_4 ] . V_239 != V_240 ) ;
V_195 [ V_4 ] . V_247 = F_107 ( V_11 , V_244 [ V_4 ] . V_239 ) ;
V_195 [ V_4 ] . V_248 = F_108 ( V_11 , V_244 [ V_4 ] . V_211 ) ;
}
return 0 ;
}
static int
F_109 (
struct V_59 * V_60 ,
T_2 V_61 ,
T_3 V_62 ,
int V_71 ,
struct V_242 * * V_195 ,
int * V_243 )
{
struct V_10 * V_11 = V_60 -> V_234 ;
int V_249 ;
int error = 0 ;
struct V_194 V_250 ;
struct V_194 * V_244 = & V_250 ;
int V_245 ;
ASSERT ( V_195 && * V_195 ) ;
ASSERT ( * V_243 == 1 ) ;
if ( V_71 == V_115 )
V_249 = V_11 -> V_36 -> V_213 ;
else
V_249 = V_11 -> V_38 -> V_213 ;
if ( V_62 == - 1 || V_62 == - 2 ) {
if ( V_249 != 1 )
V_244 = F_106 ( sizeof( V_250 ) * V_249 ,
V_207 | V_2 ) ;
V_245 = V_249 ;
error = F_110 ( V_60 , ( T_8 ) V_61 , V_249 , V_244 ,
& V_245 , F_91 ( V_71 ) ) ;
if ( error )
goto V_251;
} else {
V_244 -> V_239 = F_111 ( V_11 , V_62 ) ;
V_244 -> V_210 = ( T_8 ) V_61 ;
V_244 -> V_211 = V_249 ;
V_244 -> V_252 = 0 ;
V_245 = 1 ;
}
if ( ! F_104 ( V_245 , V_244 , V_61 , V_249 ) ) {
error = V_62 == - 2 ? - 1 : - V_42 ;
if ( F_99 ( error == - V_42 ) ) {
if ( V_253 >= V_235 ) {
int V_4 ;
F_112 ( V_11 , L_8 ,
V_254 , ( long long ) V_61 ,
( long long ) V_60 -> V_76 ) ;
for ( V_4 = 0 ; V_4 < * V_243 ; V_4 ++ ) {
F_112 ( V_11 ,
L_9 ,
V_4 ,
( long long ) V_244 [ V_4 ] . V_210 ,
( long long ) V_244 [ V_4 ] . V_239 ,
( long long ) V_244 [ V_4 ] . V_211 ,
V_244 [ V_4 ] . V_252 ) ;
}
}
F_100 ( L_10 ,
V_235 , V_11 ) ;
}
goto V_251;
}
error = F_105 ( V_11 , V_195 , V_243 , V_244 , V_245 ) ;
V_251:
if ( V_244 != & V_250 )
F_94 ( V_244 ) ;
return error ;
}
int
F_25 (
struct V_57 * V_73 ,
struct V_59 * V_60 ,
T_2 V_61 ,
T_3 V_62 ,
struct V_9 * * V_63 ,
int V_71 )
{
struct V_9 * V_8 ;
struct V_242 V_195 ;
struct V_242 * V_196 ;
int V_197 ;
int error ;
* V_63 = NULL ;
V_196 = & V_195 ;
V_197 = 1 ;
error = F_109 ( V_60 , V_61 , V_62 , V_71 ,
& V_196 , & V_197 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_255;
}
V_8 = F_113 ( V_73 , V_60 -> V_234 -> V_256 ,
V_196 , V_197 , 0 ) ;
error = V_8 ? V_8 -> V_257 : - V_258 ;
if ( error ) {
if ( V_8 )
F_66 ( V_73 , V_8 ) ;
goto V_255;
}
* V_63 = V_8 ;
V_255:
if ( V_196 != & V_195 )
F_94 ( V_196 ) ;
return error ;
}
int
F_21 (
struct V_57 * V_73 ,
struct V_59 * V_60 ,
T_2 V_61 ,
T_3 V_62 ,
struct V_9 * * V_63 ,
int V_71 ,
const struct V_259 * V_20 )
{
struct V_9 * V_8 ;
struct V_242 V_195 ;
struct V_242 * V_196 ;
int V_197 ;
int error ;
* V_63 = NULL ;
V_196 = & V_195 ;
V_197 = 1 ;
error = F_109 ( V_60 , V_61 , V_62 , V_71 ,
& V_196 , & V_197 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_255;
}
error = F_114 ( V_60 -> V_234 , V_73 ,
V_60 -> V_234 -> V_256 ,
V_196 , V_197 , 0 , & V_8 , V_20 ) ;
if ( error )
goto V_255;
if ( V_71 == V_126 )
F_115 ( V_8 , V_260 ) ;
else
F_115 ( V_8 , V_261 ) ;
* V_63 = V_8 ;
V_255:
if ( V_196 != & V_195 )
F_94 ( V_196 ) ;
return error ;
}
T_3
F_116 (
struct V_59 * V_60 ,
T_2 V_61 ,
T_3 V_62 ,
int V_71 ,
const struct V_259 * V_20 )
{
struct V_242 V_195 ;
struct V_242 * V_196 ;
int V_197 ;
int error ;
V_196 = & V_195 ;
V_197 = 1 ;
error = F_109 ( V_60 , V_61 , V_62 , V_71 ,
& V_196 , & V_197 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_255;
}
V_62 = V_196 [ 0 ] . V_247 ;
F_117 ( V_60 -> V_234 -> V_256 , V_196 , V_197 , V_20 ) ;
V_255:
if ( V_196 != & V_195 )
F_94 ( V_196 ) ;
if ( error )
return - 1 ;
return V_62 ;
}
