STATIC bool
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
if ( V_9 . V_12 == V_13 ) {
struct V_14 * V_15 = V_4 -> V_7 ;
if ( F_2 ( V_15 -> V_16 . V_17 ) != V_4 -> V_18 )
return false ;
} else if ( V_9 . V_12 != V_19 )
return false ;
return F_3 ( V_2 -> V_20 , V_2 , & V_9 , V_6 ) ;
}
bool
F_3 (
struct V_21 * V_22 ,
struct V_1 * V_2 ,
struct V_8 * V_23 ,
struct V_5 * V_6 )
{
struct V_24 * V_25 ;
T_1 * V_26 ;
int V_27 ;
int V_28 ;
const struct V_29 * V_30 ;
struct V_8 V_9 ;
struct V_31 * V_32 = V_22 -> V_33 ;
V_30 = F_4 ( V_22 , V_2 ) ;
if ( ! V_23 ) {
V_30 -> V_11 ( & V_9 , V_6 ) ;
V_23 = & V_9 ;
}
V_25 = V_30 -> V_34 ( V_6 ) ;
V_26 = F_5 ( V_32 , V_6 ) ;
if ( V_23 -> V_35 > V_30 -> V_36 ( V_32 ) )
return false ;
if ( ( V_23 -> V_12 == V_19 ||
V_23 -> V_12 == V_13 ) &&
( char * ) & V_25 [ V_23 -> V_35 ] > ( char * ) F_6 ( V_26 ) )
return false ;
for ( V_28 = V_27 = 0 ; V_28 < V_23 -> V_35 ; V_28 ++ ) {
if ( V_28 + 1 < V_23 -> V_35 ) {
if ( F_7 ( V_25 [ V_28 ] . V_37 ) >
F_7 ( V_25 [ V_28 + 1 ] . V_37 ) )
return false ;
}
if ( V_25 [ V_28 ] . V_38 == F_8 ( V_39 ) )
V_27 ++ ;
}
if ( V_23 -> V_27 != V_27 )
return false ;
return true ;
}
static bool
F_9 (
struct V_3 * V_4 ,
T_2 V_12 )
{
struct V_21 * V_22 = V_4 -> V_40 -> V_41 ;
struct V_5 * V_6 = V_4 -> V_7 ;
ASSERT ( V_12 == V_19 || V_12 == V_42 ) ;
if ( F_10 ( & V_22 -> V_43 ) ) {
struct V_14 * V_15 = V_4 -> V_7 ;
T_2 V_44 ;
V_44 = ( V_12 == V_19 ) ? V_13
: V_45 ;
if ( V_15 -> V_16 . V_23 . V_12 != F_11 ( V_44 ) )
return false ;
if ( ! F_12 ( & V_15 -> V_16 . V_46 , & V_22 -> V_43 . V_47 ) )
return false ;
if ( F_2 ( V_15 -> V_16 . V_17 ) != V_4 -> V_18 )
return false ;
if ( ! F_13 ( V_22 , F_2 ( V_15 -> V_16 . V_48 ) ) )
return false ;
} else {
if ( V_6 -> V_23 . V_16 . V_12 != F_11 ( V_12 ) )
return false ;
}
return F_3 ( V_22 , NULL , NULL , V_6 ) ;
}
static void
F_14 (
struct V_3 * V_4 ,
T_2 V_12 )
{
struct V_21 * V_22 = V_4 -> V_40 -> V_41 ;
if ( F_10 ( & V_22 -> V_43 ) &&
! F_15 ( V_4 , V_49 ) )
F_16 ( V_4 , - V_50 ) ;
else if ( ! F_9 ( V_4 , V_12 ) )
F_16 ( V_4 , - V_51 ) ;
if ( V_4 -> V_52 )
F_17 ( V_4 ) ;
}
static void
F_18 (
struct V_3 * V_4 ,
T_2 V_12 )
{
struct V_21 * V_22 = V_4 -> V_40 -> V_41 ;
struct V_53 * V_54 = V_4 -> V_55 ;
struct V_14 * V_56 = V_4 -> V_7 ;
if ( ! F_9 ( V_4 , V_12 ) ) {
F_16 ( V_4 , - V_51 ) ;
F_17 ( V_4 ) ;
return;
}
if ( ! F_10 ( & V_22 -> V_43 ) )
return;
if ( V_54 )
V_56 -> V_16 . V_48 = F_19 ( V_54 -> V_57 . V_58 ) ;
F_20 ( V_4 , V_49 ) ;
}
static void
F_21 (
struct V_3 * V_4 )
{
F_14 ( V_4 , V_19 ) ;
}
static void
F_22 (
struct V_3 * V_4 )
{
F_18 ( V_4 , V_19 ) ;
}
static void
F_23 (
struct V_3 * V_4 )
{
F_14 ( V_4 , V_42 ) ;
}
static void
F_24 (
struct V_3 * V_4 )
{
F_18 ( V_4 , V_42 ) ;
}
static int
F_25 (
struct V_59 * V_60 ,
struct V_1 * V_2 ,
T_3 V_61 ,
T_4 V_62 ,
struct V_3 * * V_63 )
{
int V_64 ;
V_64 = F_26 ( V_60 , V_2 , V_61 , V_62 , V_63 ,
V_65 , & V_66 ) ;
if ( ! V_64 && V_60 )
F_27 ( V_60 , * V_63 , V_67 ) ;
return V_64 ;
}
int
F_28 (
struct V_59 * V_60 ,
struct V_1 * V_2 ,
T_3 V_61 ,
T_4 V_62 ,
struct V_3 * * V_63 )
{
int V_64 ;
V_64 = F_26 ( V_60 , V_2 , V_61 , V_62 , V_63 ,
V_65 , & V_68 ) ;
if ( ! V_64 && V_60 )
F_27 ( V_60 , * V_63 , V_69 ) ;
return V_64 ;
}
static void
F_29 (
struct V_21 * V_22 ,
struct V_59 * V_60 ,
struct V_3 * V_4 ,
T_5 V_70 ,
T_2 type )
{
struct V_5 * V_6 = V_4 -> V_7 ;
ASSERT ( type == V_19 || type == V_42 ) ;
if ( F_10 ( & V_22 -> V_43 ) ) {
struct V_14 * V_15 = V_4 -> V_7 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_16 . V_23 . V_12 = ( type == V_19 )
? F_11 ( V_13 )
: F_11 ( V_45 ) ;
V_15 -> V_16 . V_17 = F_19 ( V_4 -> V_18 ) ;
V_15 -> V_16 . V_70 = F_19 ( V_70 ) ;
F_30 ( & V_15 -> V_16 . V_46 , & V_22 -> V_43 . V_47 ) ;
} else {
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_23 . V_16 . V_12 = F_11 ( type ) ;
}
if ( type == V_19 ) {
struct V_71 * V_26 ;
V_26 = F_5 ( V_22 -> V_33 , V_6 ) ;
V_26 -> V_72 = 0 ;
V_4 -> V_73 = & V_66 ;
F_27 ( V_60 , V_4 , V_67 ) ;
} else {
V_4 -> V_73 = & V_68 ;
F_27 ( V_60 , V_4 , V_69 ) ;
}
}
int
F_31 (
T_6 * args ,
T_7 V_74 ,
struct V_3 * * V_63 ,
T_2 V_12 )
{
struct V_1 * V_2 = args -> V_2 ;
struct V_59 * V_60 = args -> V_75 ;
struct V_21 * V_22 = V_2 -> V_20 ;
struct V_3 * V_4 ;
int error ;
ASSERT ( V_12 == V_19 || V_12 == V_42 ) ;
ASSERT ( V_74 >= F_32 ( args -> V_32 , V_76 ) &&
V_74 < F_32 ( args -> V_32 , V_77 ) ) ;
error = F_33 ( V_60 , V_2 , F_34 ( args -> V_32 , V_74 ) ,
- 1 , & V_4 , V_65 ) ;
if ( error )
return error ;
F_29 ( V_22 , V_60 , V_4 , V_2 -> V_78 , V_12 ) ;
F_35 ( args , V_4 ) ;
if ( V_12 == V_19 )
F_36 ( args , V_4 ) ;
* V_63 = V_4 ;
return 0 ;
}
int
F_37 (
T_6 * args ,
struct V_3 * V_79 )
{
T_8 * V_80 ;
T_3 V_17 ;
T_9 * V_23 ;
T_10 * V_81 ;
T_11 * V_82 ;
T_12 * V_2 ;
int error ;
struct V_3 * V_83 ;
T_7 V_84 ;
T_13 * V_6 ;
T_1 * V_26 ;
int V_85 ;
int V_86 ;
T_14 * V_60 ;
struct V_87 * V_88 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
F_38 ( args ) ;
V_2 = args -> V_2 ;
V_60 = args -> V_75 ;
if ( ( error = F_39 ( args , & V_17 ) ) ) {
return error ;
}
V_84 = F_40 ( args -> V_32 , V_17 ) ;
ASSERT ( V_84 == F_32 ( args -> V_32 , V_76 ) ) ;
error = F_31 ( args , V_84 , & V_83 , V_19 ) ;
if ( error )
return error ;
V_6 = V_83 -> V_7 ;
V_23 = V_79 -> V_7 ;
F_41 ( V_2 , V_79 ) ;
V_82 = F_42 ( args -> V_32 , V_23 ) ;
V_81 = F_43 ( V_82 ) ;
V_88 = V_2 -> V_10 -> V_89 ( V_23 ) ;
V_25 = V_2 -> V_10 -> V_34 ( V_6 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_9 . V_35 = F_7 ( V_82 -> V_35 ) ;
V_9 . V_27 = F_7 ( V_82 -> V_27 ) ;
V_2 -> V_10 -> V_90 ( V_6 , & V_9 ) ;
F_35 ( args , V_83 ) ;
memcpy ( V_25 , V_81 , F_7 ( V_82 -> V_35 ) * sizeof( T_10 ) ) ;
F_44 ( args , V_83 , 0 , V_9 . V_35 - 1 ) ;
V_86 = 0 ;
V_85 = 1 ;
F_45 ( args , V_79 ,
( V_91 ) ( ( char * ) V_81 - ( char * ) V_23 ) ,
( V_91 ) ( ( char * ) V_23 + args -> V_32 -> V_92 -
( char * ) V_81 ) ,
& V_85 , & V_86 ) ;
V_79 -> V_73 = & V_93 ;
F_27 ( V_60 , V_79 , V_94 ) ;
if ( V_23 -> V_12 == F_8 ( V_95 ) )
V_23 -> V_12 = F_8 ( V_96 ) ;
else
V_23 -> V_12 = F_8 ( V_97 ) ;
if ( V_86 )
F_46 ( V_2 , V_23 , & V_85 ) ;
V_26 = F_5 ( args -> V_32 , V_6 ) ;
V_26 -> V_72 = F_8 ( 1 ) ;
V_80 = F_6 ( V_26 ) ;
V_80 [ 0 ] = V_88 [ 0 ] . V_98 ;
if ( V_85 )
F_47 ( args , V_79 ) ;
F_48 ( V_2 , V_83 ) ;
F_41 ( V_2 , V_79 ) ;
F_49 ( args , V_83 , 0 , 0 ) ;
return 0 ;
}
STATIC void
F_50 (
struct V_8 * V_9 ,
struct V_24 * V_25 ,
int V_99 ,
int * V_100 ,
int * V_101 )
{
for ( * V_100 = V_99 - 1 ; * V_100 >= 0 ; -- * V_100 ) {
if ( V_25 [ * V_100 ] . V_38 ==
F_8 ( V_39 ) )
break;
}
for ( * V_101 = V_99 ; * V_101 < V_9 -> V_35 ; ++ * V_101 ) {
if ( V_25 [ * V_101 ] . V_38 ==
F_8 ( V_39 ) )
break;
if ( * V_100 >= 0 && V_99 - * V_100 <= * V_101 - V_99 )
break;
}
}
struct V_24 *
F_51 (
struct V_8 * V_9 ,
struct V_24 * V_25 ,
int V_99 ,
int V_102 ,
int V_100 ,
int V_101 ,
int * V_103 ,
int * V_104 )
{
if ( ! V_9 -> V_27 ) {
T_10 * V_105 ;
V_105 = & V_25 [ V_99 ] ;
if ( V_99 < V_9 -> V_35 )
memmove ( V_105 + 1 , V_105 ,
( V_9 -> V_35 - V_99 ) * sizeof( * V_105 ) ) ;
* V_103 = V_99 ;
* V_104 = V_9 -> V_35 ++ ;
return V_105 ;
}
if ( V_102 == 0 )
F_50 ( V_9 , V_25 , V_99 ,
& V_100 , & V_101 ) ;
if ( V_100 >= 0 &&
( V_101 == V_9 -> V_35 ||
V_99 - V_100 - 1 < V_101 - V_99 ) ) {
ASSERT ( V_99 - V_100 - 1 >= 0 ) ;
ASSERT ( V_25 [ V_100 ] . V_38 ==
F_8 ( V_39 ) ) ;
if ( V_99 - V_100 - 1 > 0 ) {
memmove ( & V_25 [ V_100 ] , & V_25 [ V_100 + 1 ] ,
( V_99 - V_100 - 1 ) *
sizeof( T_10 ) ) ;
}
* V_103 = F_52 ( V_100 , * V_103 ) ;
* V_104 = F_53 ( V_99 - 1 , * V_104 ) ;
V_9 -> V_27 -- ;
return & V_25 [ V_99 - 1 ] ;
}
ASSERT ( V_101 - V_99 >= 0 ) ;
ASSERT ( V_25 [ V_101 ] . V_38 == F_8 ( V_39 ) ) ;
if ( V_101 - V_99 > 0 ) {
memmove ( & V_25 [ V_99 + 1 ] , & V_25 [ V_99 ] ,
( V_101 - V_99 ) * sizeof( T_10 ) ) ;
}
* V_103 = F_52 ( V_99 , * V_103 ) ;
* V_104 = F_53 ( V_101 , * V_104 ) ;
V_9 -> V_27 -- ;
return & V_25 [ V_99 ] ;
}
int
F_54 (
T_6 * args )
{
T_8 * V_80 ;
int V_102 ;
T_9 * V_23 ;
struct V_3 * V_79 ;
T_15 * V_106 ;
T_12 * V_2 ;
T_16 * V_107 ;
int error ;
int V_108 ;
int V_101 ;
int V_28 ;
int V_99 ;
struct V_3 * V_83 ;
T_13 * V_6 ;
int V_98 ;
T_10 * V_105 ;
int V_103 ;
int V_104 ;
int V_100 ;
T_1 * V_26 ;
int V_109 ;
int V_85 ;
int V_86 ;
T_8 * V_110 ;
T_14 * V_60 ;
T_7 V_111 ;
struct V_87 * V_88 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
F_55 ( args ) ;
V_2 = args -> V_2 ;
V_60 = args -> V_75 ;
error = F_25 ( V_60 , V_2 , args -> V_32 -> V_112 , - 1 , & V_83 ) ;
if ( error )
return error ;
V_99 = F_56 ( args , V_83 ) ;
V_6 = V_83 -> V_7 ;
V_26 = F_5 ( args -> V_32 , V_6 ) ;
V_25 = V_2 -> V_10 -> V_34 ( V_6 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_80 = F_6 ( V_26 ) ;
V_98 = V_2 -> V_10 -> V_113 ( args -> V_114 ) ;
for ( V_111 = - 1 , V_105 = & V_25 [ V_99 ] ;
V_99 < V_9 . V_35 && F_7 ( V_105 -> V_37 ) == args -> V_37 ;
V_99 ++ , V_105 ++ ) {
if ( F_7 ( V_105 -> V_38 ) == V_39 )
continue;
V_28 = F_57 ( args -> V_32 , F_7 ( V_105 -> V_38 ) ) ;
ASSERT ( V_28 < F_7 ( V_26 -> V_72 ) ) ;
ASSERT ( V_80 [ V_28 ] != F_11 ( V_115 ) ) ;
if ( F_58 ( V_80 [ V_28 ] ) >= V_98 ) {
V_111 = V_28 ;
break;
}
}
if ( V_111 == - 1 ) {
for ( V_28 = 0 ; V_28 < F_7 ( V_26 -> V_72 ) ; V_28 ++ ) {
if ( V_80 [ V_28 ] == F_11 ( V_115 ) &&
V_111 == - 1 )
V_111 = V_28 ;
else if ( F_58 ( V_80 [ V_28 ] ) >= V_98 ) {
V_111 = V_28 ;
break;
}
}
}
V_109 = 0 ;
if ( ! V_9 . V_27 )
V_109 += sizeof( T_10 ) ;
if ( V_111 == - 1 )
V_109 += sizeof( V_116 ) ;
if ( V_111 != - 1 && V_80 [ V_111 ] == F_11 ( V_115 ) )
V_111 = - 1 ;
if ( ( char * ) V_80 - ( char * ) & V_25 [ V_9 . V_35 ] < V_109 &&
V_9 . V_27 > 1 )
V_102 = 1 ;
else if ( ( char * ) V_80 - ( char * ) & V_25 [ V_9 . V_35 ] < V_109 ) {
if ( ( args -> V_117 & V_118 ) ||
args -> V_119 == 0 ) {
F_59 ( V_60 , V_83 ) ;
return - V_120 ;
}
error = F_60 ( args , V_83 ) ;
if ( error )
return error ;
return F_61 ( args ) ;
}
else
V_102 = 0 ;
if ( args -> V_117 & V_118 ) {
F_59 ( V_60 , V_83 ) ;
return V_111 == - 1 ? - V_120 : 0 ;
}
if ( args -> V_119 == 0 && V_111 == - 1 ) {
F_59 ( V_60 , V_83 ) ;
return - V_120 ;
}
if ( V_102 ) {
F_62 ( & V_9 , V_25 , & V_99 , & V_100 ,
& V_101 , & V_103 , & V_104 ) ;
}
else if ( V_9 . V_27 ) {
V_103 = V_9 . V_35 ;
V_104 = - 1 ;
}
if ( V_111 == - 1 ) {
if ( ( error = F_63 ( args , V_121 ,
& V_111 ) ) ) {
F_59 ( V_60 , V_83 ) ;
return error ;
}
if ( ( error = F_64 ( args , V_111 , & V_79 ) ) ) {
F_59 ( V_60 , V_83 ) ;
return error ;
}
if ( V_111 >= F_7 ( V_26 -> V_72 ) ) {
V_80 -- ;
memmove ( & V_80 [ 0 ] , & V_80 [ 1 ] ,
F_7 ( V_26 -> V_72 ) * sizeof( V_80 [ 0 ] ) ) ;
F_65 ( & V_26 -> V_72 , 1 ) ;
F_36 ( args , V_83 ) ;
F_49 ( args , V_83 , 0 ,
F_7 ( V_26 -> V_72 ) - 1 ) ;
}
else
F_49 ( args , V_83 , V_111 , V_111 ) ;
V_23 = V_79 -> V_7 ;
V_88 = V_2 -> V_10 -> V_89 ( V_23 ) ;
V_80 [ V_111 ] = V_88 [ 0 ] . V_98 ;
V_108 = 1 ;
} else {
error = F_66 ( V_60 , V_2 ,
F_34 ( args -> V_32 , V_111 ) ,
- 1 , & V_79 ) ;
if ( error ) {
F_59 ( V_60 , V_83 ) ;
return error ;
}
V_23 = V_79 -> V_7 ;
V_88 = V_2 -> V_10 -> V_89 ( V_23 ) ;
V_108 = 0 ;
}
V_107 = ( T_16 * )
( ( char * ) V_23 + F_58 ( V_88 [ 0 ] . V_122 ) ) ;
ASSERT ( F_58 ( V_107 -> V_98 ) >= V_98 ) ;
V_86 = V_85 = 0 ;
F_67 ( args , V_79 , V_107 ,
( V_91 ) ( ( char * ) V_107 - ( char * ) V_23 ) , V_98 ,
& V_85 , & V_86 ) ;
V_106 = ( T_15 * ) V_107 ;
V_106 -> V_123 = F_19 ( args -> V_123 ) ;
V_106 -> V_114 = args -> V_114 ;
memcpy ( V_106 -> V_124 , args -> V_124 , V_106 -> V_114 ) ;
V_2 -> V_10 -> V_125 ( V_106 , args -> V_126 ) ;
V_110 = V_2 -> V_10 -> V_127 ( V_106 ) ;
* V_110 = F_11 ( ( char * ) V_106 - ( char * ) V_23 ) ;
if ( V_86 )
F_46 ( V_2 , V_23 , & V_85 ) ;
if ( V_85 )
F_47 ( args , V_79 ) ;
F_68 ( args , V_79 , V_106 ) ;
if ( F_58 ( V_80 [ V_111 ] ) != F_58 ( V_88 [ 0 ] . V_98 ) ) {
V_80 [ V_111 ] = V_88 [ 0 ] . V_98 ;
if ( ! V_108 )
F_49 ( args , V_83 , V_111 , V_111 ) ;
}
V_105 = F_51 ( & V_9 , V_25 , V_99 , V_102 , V_100 ,
V_101 , & V_103 , & V_104 ) ;
V_105 -> V_37 = F_8 ( args -> V_37 ) ;
V_105 -> V_38 = F_8 (
F_69 ( args -> V_32 , V_111 ,
F_58 ( * V_110 ) ) ) ;
V_2 -> V_10 -> V_90 ( V_6 , & V_9 ) ;
F_35 ( args , V_83 ) ;
F_44 ( args , V_83 , V_103 , V_104 ) ;
F_48 ( V_2 , V_83 ) ;
F_41 ( V_2 , V_79 ) ;
return 0 ;
}
void
F_70 (
T_6 * args ,
struct V_8 * V_9 ,
struct V_3 * V_4 )
{
int V_128 ;
T_13 * V_6 ;
int V_129 ;
int V_130 ;
struct V_24 * V_25 ;
struct V_1 * V_2 = args -> V_2 ;
V_6 = V_4 -> V_7 ;
if ( ! V_9 -> V_27 )
return;
V_25 = V_2 -> V_10 -> V_34 ( V_6 ) ;
for ( V_128 = V_130 = 0 , V_129 = - 1 ; V_128 < V_9 -> V_35 ; V_128 ++ ) {
if ( V_25 [ V_128 ] . V_38 == F_8 ( V_39 ) )
continue;
if ( V_128 > V_130 ) {
if ( V_129 == - 1 )
V_129 = V_130 ;
V_25 [ V_130 ] = V_25 [ V_128 ] ;
}
V_130 ++ ;
}
ASSERT ( V_9 -> V_27 == V_128 - V_130 ) ;
V_9 -> V_35 -= V_9 -> V_27 ;
V_9 -> V_27 = 0 ;
V_2 -> V_10 -> V_90 ( V_6 , V_9 ) ;
F_35 ( args , V_4 ) ;
if ( V_129 != - 1 )
F_44 ( args , V_4 , V_129 , V_130 - 1 ) ;
}
void
F_62 (
struct V_8 * V_9 ,
struct V_24 * V_25 ,
int * V_131 ,
int * V_132 ,
int * V_133 ,
int * V_134 ,
int * V_135 )
{
int V_128 ;
int V_101 ;
int V_99 ;
int V_136 ;
int V_100 ;
int V_137 = 0 ;
int V_130 ;
ASSERT ( V_9 -> V_27 > 1 ) ;
V_99 = * V_131 ;
F_50 ( V_9 , V_25 , V_99 , & V_100 , & V_101 ) ;
if ( V_100 >= 0 &&
( V_101 == V_9 -> V_35 ||
V_99 - V_100 <= V_101 - V_99 ) )
V_136 = V_100 ;
else
V_136 = V_101 ;
for ( V_128 = V_130 = 0 ; V_128 < V_9 -> V_35 ; V_128 ++ ) {
if ( V_99 == V_128 )
V_137 = V_130 ;
if ( V_128 != V_136 &&
V_25 [ V_128 ] . V_38 == F_8 ( V_39 ) ) {
if ( V_128 == V_130 )
* V_134 = V_130 ;
continue;
}
if ( V_128 == V_136 )
V_100 = V_101 = V_130 ;
if ( V_128 > V_130 )
V_25 [ V_130 ] = V_25 [ V_128 ] ;
V_130 ++ ;
}
ASSERT ( V_128 > V_130 ) ;
if ( V_99 == V_128 )
V_137 = V_130 ;
* V_131 = V_137 ;
V_9 -> V_35 -= V_128 - V_130 ;
V_9 -> V_27 = 1 ;
if ( V_100 >= V_137 )
V_100 = - 1 ;
else
V_101 = V_9 -> V_35 ;
* V_135 = V_9 -> V_35 - 1 ;
* V_132 = V_100 ;
* V_133 = V_101 ;
}
static void
F_49 (
struct V_138 * args ,
struct V_3 * V_4 ,
int V_139 ,
int V_140 )
{
T_8 * V_141 ;
T_8 * V_142 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 * V_26 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ) ;
V_26 = F_5 ( args -> V_32 , V_6 ) ;
V_141 = F_6 ( V_26 ) + V_139 ;
V_142 = F_6 ( V_26 ) + V_140 ;
F_71 ( args -> V_75 , V_4 ,
( V_143 ) ( ( char * ) V_141 - ( char * ) V_6 ) ,
( V_143 ) ( ( char * ) V_142 - ( char * ) V_6 + sizeof( * V_142 ) - 1 ) ) ;
}
void
F_44 (
struct V_138 * args ,
struct V_3 * V_4 ,
int V_139 ,
int V_140 )
{
T_10 * V_144 ;
T_10 * V_145 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_24 * V_25 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_42 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_45 ) ) ;
V_25 = args -> V_2 -> V_10 -> V_34 ( V_6 ) ;
V_144 = & V_25 [ V_139 ] ;
V_145 = & V_25 [ V_140 ] ;
F_71 ( args -> V_75 , V_4 ,
( V_143 ) ( ( char * ) V_144 - ( char * ) V_6 ) ,
( V_143 ) ( ( char * ) V_145 - ( char * ) V_6 + sizeof( * V_145 ) - 1 ) ) ;
}
void
F_35 (
struct V_138 * args ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_42 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_45 ) ) ;
F_71 ( args -> V_75 , V_4 ,
( V_143 ) ( ( char * ) & V_6 -> V_23 - ( char * ) V_6 ) ,
args -> V_2 -> V_10 -> V_146 - 1 ) ;
}
STATIC void
F_36 (
struct V_138 * args ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 * V_26 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_42 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_45 ) ) ;
V_26 = F_5 ( args -> V_32 , V_6 ) ;
F_71 ( args -> V_75 , V_4 , ( V_143 ) ( ( char * ) V_26 - ( char * ) V_6 ) ,
( V_143 ) ( args -> V_32 -> V_92 - 1 ) ) ;
}
int
F_72 (
T_6 * args )
{
struct V_3 * V_79 ;
T_15 * V_106 ;
T_12 * V_2 ;
int error ;
int V_99 ;
struct V_3 * V_83 ;
T_13 * V_6 ;
T_10 * V_105 ;
T_14 * V_60 ;
struct V_24 * V_25 ;
F_73 ( args ) ;
if ( ( error = F_74 ( args , & V_83 , & V_99 , & V_79 ) ) ) {
return error ;
}
V_60 = args -> V_75 ;
V_2 = args -> V_2 ;
F_48 ( V_2 , V_83 ) ;
V_6 = V_83 -> V_7 ;
V_25 = V_2 -> V_10 -> V_34 ( V_6 ) ;
V_105 = & V_25 [ V_99 ] ;
V_106 = ( T_15 * )
( ( char * ) V_79 -> V_7 +
F_75 ( args -> V_32 , F_7 ( V_105 -> V_38 ) ) ) ;
args -> V_123 = F_2 ( V_106 -> V_123 ) ;
args -> V_126 = V_2 -> V_10 -> V_147 ( V_106 ) ;
error = F_76 ( args , V_106 -> V_124 , V_106 -> V_114 ) ;
F_59 ( V_60 , V_79 ) ;
F_59 ( V_60 , V_83 ) ;
return error ;
}
static int
F_74 (
T_6 * args ,
struct V_3 * * V_148 ,
int * V_131 ,
struct V_3 * * V_149 )
{
T_7 V_150 = - 1 ;
struct V_3 * V_79 = NULL ;
T_15 * V_106 ;
T_12 * V_2 ;
int error ;
int V_99 ;
struct V_3 * V_83 ;
T_10 * V_105 ;
T_13 * V_6 ;
T_17 * V_22 ;
T_7 V_151 ;
T_14 * V_60 ;
T_7 V_152 = - 1 ;
enum V_153 V_154 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
V_2 = args -> V_2 ;
V_60 = args -> V_75 ;
V_22 = V_2 -> V_20 ;
error = F_25 ( V_60 , V_2 , args -> V_32 -> V_112 , - 1 , & V_83 ) ;
if ( error )
return error ;
* V_148 = V_83 ;
V_6 = V_83 -> V_7 ;
F_48 ( V_2 , V_83 ) ;
V_25 = V_2 -> V_10 -> V_34 ( V_6 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_99 = F_56 ( args , V_83 ) ;
for ( V_105 = & V_25 [ V_99 ] ;
V_99 < V_9 . V_35 && F_7 ( V_105 -> V_37 ) == args -> V_37 ;
V_105 ++ , V_99 ++ ) {
if ( F_7 ( V_105 -> V_38 ) == V_39 )
continue;
V_151 = F_57 ( args -> V_32 ,
F_7 ( V_105 -> V_38 ) ) ;
if ( V_151 != V_150 ) {
if ( V_79 )
F_59 ( V_60 , V_79 ) ;
error = F_66 ( V_60 , V_2 ,
F_34 ( args -> V_32 , V_151 ) ,
- 1 , & V_79 ) ;
if ( error ) {
F_59 ( V_60 , V_83 ) ;
return error ;
}
V_150 = V_151 ;
}
V_106 = ( T_15 * ) ( ( char * ) V_79 -> V_7 +
F_75 ( args -> V_32 ,
F_7 ( V_105 -> V_38 ) ) ) ;
V_154 = V_22 -> V_155 -> V_156 ( args , V_106 -> V_124 , V_106 -> V_114 ) ;
if ( V_154 != V_157 && V_154 != args -> V_158 ) {
args -> V_158 = V_154 ;
* V_131 = V_99 ;
if ( V_154 == V_159 ) {
* V_149 = V_79 ;
return 0 ;
}
V_152 = V_150 ;
}
}
ASSERT ( args -> V_117 & V_160 ) ;
if ( args -> V_158 == V_161 ) {
ASSERT ( V_152 != - 1 ) ;
if ( V_152 != V_150 ) {
F_59 ( V_60 , V_79 ) ;
error = F_66 ( V_60 , V_2 ,
F_34 ( args -> V_32 , V_152 ) ,
- 1 , & V_79 ) ;
if ( error ) {
F_59 ( V_60 , V_83 ) ;
return error ;
}
}
* V_149 = V_79 ;
return 0 ;
}
ASSERT ( V_152 == - 1 ) ;
if ( V_79 )
F_59 ( V_60 , V_79 ) ;
F_59 ( V_60 , V_83 ) ;
return - V_162 ;
}
int
F_77 (
T_6 * args )
{
T_8 * V_80 ;
T_9 * V_23 ;
T_7 V_163 ;
struct V_3 * V_79 ;
T_15 * V_106 ;
T_12 * V_2 ;
int error ;
T_7 V_28 ;
int V_99 ;
struct V_3 * V_83 ;
T_13 * V_6 ;
T_10 * V_105 ;
T_1 * V_26 ;
int V_85 ;
int V_86 ;
V_116 V_164 ;
struct V_87 * V_88 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
F_78 ( args ) ;
if ( ( error = F_74 ( args , & V_83 , & V_99 , & V_79 ) ) ) {
return error ;
}
V_2 = args -> V_2 ;
V_6 = V_83 -> V_7 ;
V_23 = V_79 -> V_7 ;
F_41 ( V_2 , V_79 ) ;
V_88 = V_2 -> V_10 -> V_89 ( V_23 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_25 = V_2 -> V_10 -> V_34 ( V_6 ) ;
V_105 = & V_25 [ V_99 ] ;
V_163 = F_57 ( args -> V_32 , F_7 ( V_105 -> V_38 ) ) ;
V_106 = ( T_15 * ) ( ( char * ) V_23 +
F_75 ( args -> V_32 , F_7 ( V_105 -> V_38 ) ) ) ;
V_86 = V_85 = 0 ;
V_164 = F_58 ( V_88 [ 0 ] . V_98 ) ;
V_26 = F_5 ( args -> V_32 , V_6 ) ;
V_80 = F_6 ( V_26 ) ;
ASSERT ( F_58 ( V_80 [ V_163 ] ) == V_164 ) ;
F_45 ( args , V_79 ,
( V_91 ) ( ( char * ) V_106 - ( char * ) V_23 ) ,
V_2 -> V_10 -> V_113 ( V_106 -> V_114 ) , & V_85 , & V_86 ) ;
V_9 . V_27 ++ ;
V_2 -> V_10 -> V_90 ( V_6 , & V_9 ) ;
F_35 ( args , V_83 ) ;
V_105 -> V_38 = F_8 ( V_39 ) ;
F_44 ( args , V_83 , V_99 , V_99 ) ;
if ( V_86 )
F_46 ( V_2 , V_23 , & V_85 ) ;
if ( V_85 )
F_47 ( args , V_79 ) ;
if ( F_58 ( V_88 [ 0 ] . V_98 ) != V_164 ) {
V_80 [ V_163 ] = V_88 [ 0 ] . V_98 ;
F_49 ( args , V_83 , V_163 , V_163 ) ;
}
F_41 ( V_2 , V_79 ) ;
if ( F_58 ( V_88 [ 0 ] . V_98 ) ==
args -> V_32 -> V_92 - V_2 -> V_10 -> V_165 ) {
ASSERT ( V_163 != args -> V_32 -> V_166 ) ;
if ( ( error = F_79 ( args , V_163 , V_79 ) ) ) {
if ( error == - V_120 && args -> V_119 == 0 )
error = 0 ;
F_48 ( V_2 , V_83 ) ;
return error ;
}
V_79 = NULL ;
if ( V_163 == F_7 ( V_26 -> V_72 ) - 1 ) {
for ( V_28 = V_163 - 1 ; V_28 > 0 ; V_28 -- ) {
if ( V_80 [ V_28 ] != F_11 ( V_115 ) )
break;
}
memmove ( & V_80 [ V_163 - V_28 ] , V_80 ,
( F_7 ( V_26 -> V_72 ) - ( V_163 - V_28 ) ) * sizeof( * V_80 ) ) ;
F_65 ( & V_26 -> V_72 , - ( V_163 - V_28 ) ) ;
F_36 ( args , V_83 ) ;
F_49 ( args , V_83 , 0 ,
F_7 ( V_26 -> V_72 ) - 1 ) ;
} else
V_80 [ V_163 ] = F_11 ( V_115 ) ;
}
else if ( V_163 != args -> V_32 -> V_166 )
V_79 = NULL ;
F_48 ( V_2 , V_83 ) ;
return F_80 ( args , V_83 , V_79 ) ;
}
int
F_81 (
T_6 * args )
{
struct V_3 * V_79 ;
T_15 * V_106 ;
T_12 * V_2 ;
int error ;
int V_99 ;
struct V_3 * V_83 ;
T_13 * V_6 ;
T_10 * V_105 ;
T_14 * V_60 ;
struct V_24 * V_25 ;
F_82 ( args ) ;
if ( ( error = F_74 ( args , & V_83 , & V_99 , & V_79 ) ) ) {
return error ;
}
V_2 = args -> V_2 ;
V_6 = V_83 -> V_7 ;
V_25 = V_2 -> V_10 -> V_34 ( V_6 ) ;
V_105 = & V_25 [ V_99 ] ;
V_106 = ( T_15 * )
( ( char * ) V_79 -> V_7 +
F_75 ( args -> V_32 , F_7 ( V_105 -> V_38 ) ) ) ;
ASSERT ( args -> V_123 != F_2 ( V_106 -> V_123 ) ) ;
V_106 -> V_123 = F_19 ( args -> V_123 ) ;
V_2 -> V_10 -> V_125 ( V_106 , args -> V_126 ) ;
V_60 = args -> V_75 ;
F_68 ( args , V_79 , V_106 ) ;
F_48 ( V_2 , V_83 ) ;
F_59 ( V_60 , V_83 ) ;
return 0 ;
}
int
F_56 (
T_6 * args ,
struct V_3 * V_83 )
{
T_18 V_167 = 0 ;
T_18 V_168 ;
int V_169 ;
int V_170 ;
T_13 * V_6 ;
T_10 * V_105 ;
int V_171 = 0 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
V_6 = V_83 -> V_7 ;
V_25 = args -> V_2 -> V_10 -> V_34 ( V_6 ) ;
args -> V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
for ( V_105 = V_25 , V_170 = 0 , V_169 = V_9 . V_35 - 1 ,
V_168 = args -> V_37 ;
V_170 <= V_169 ; ) {
V_171 = ( V_170 + V_169 ) >> 1 ;
if ( ( V_167 = F_7 ( V_105 [ V_171 ] . V_37 ) ) == V_168 )
break;
if ( V_167 < V_168 )
V_170 = V_171 + 1 ;
else
V_169 = V_171 - 1 ;
}
if ( V_167 == V_168 ) {
while ( V_171 > 0 && F_7 ( V_105 [ V_171 - 1 ] . V_37 ) == V_168 ) {
V_171 -- ;
}
}
else if ( V_167 < V_168 )
V_171 ++ ;
return V_171 ;
}
int
F_83 (
T_6 * args ,
struct V_3 * V_83 ,
T_7 V_163 )
{
T_8 * V_80 ;
struct V_3 * V_79 ;
T_12 * V_2 ;
int error ;
T_13 * V_6 ;
T_1 * V_26 ;
T_14 * V_60 ;
V_2 = args -> V_2 ;
V_60 = args -> V_75 ;
error = F_66 ( V_60 , V_2 , F_34 ( args -> V_32 , V_163 ) ,
- 1 , & V_79 ) ;
if ( error )
return error ;
V_6 = V_83 -> V_7 ;
V_26 = F_5 ( args -> V_32 , V_6 ) ;
#ifdef F_84
{
struct V_172 * V_23 = V_79 -> V_7 ;
struct V_87 * V_88 = V_2 -> V_10 -> V_89 ( V_23 ) ;
ASSERT ( V_23 -> V_12 == F_8 ( V_96 ) ||
V_23 -> V_12 == F_8 ( V_97 ) ) ;
ASSERT ( F_58 ( V_88 [ 0 ] . V_98 ) ==
args -> V_32 -> V_92 - V_2 -> V_10 -> V_165 ) ;
ASSERT ( V_163 == F_7 ( V_26 -> V_72 ) - 1 ) ;
}
#endif
if ( ( error = F_79 ( args , V_163 , V_79 ) ) ) {
ASSERT ( error != - V_120 ) ;
F_59 ( V_60 , V_79 ) ;
return error ;
}
V_80 = F_6 ( V_26 ) ;
F_65 ( & V_26 -> V_72 , - 1 ) ;
memmove ( & V_80 [ 1 ] , & V_80 [ 0 ] , F_7 ( V_26 -> V_72 ) * sizeof( * V_80 ) ) ;
F_36 ( args , V_83 ) ;
F_49 ( args , V_83 , 0 , F_7 ( V_26 -> V_72 ) - 1 ) ;
return 0 ;
}
static inline T_19
F_85 (
struct V_8 * V_23 ,
int V_173 )
{
int V_174 ;
int V_175 ;
V_174 = V_23 -> V_35 - V_23 -> V_27 ;
if ( V_23 -> V_12 == V_19 ||
V_23 -> V_12 == V_42 )
V_175 = sizeof( struct V_176 ) ;
else
V_175 = sizeof( struct V_14 ) ;
return V_175 + V_174 * sizeof( T_10 )
+ V_173 * sizeof( V_116 )
+ sizeof( T_1 ) ;
}
int
F_86 (
T_20 * V_177 )
{
T_6 * args ;
T_12 * V_2 ;
int error ;
struct V_3 * V_178 ;
T_21 V_179 ;
T_22 * free ;
struct V_3 * V_83 ;
T_1 * V_26 ;
T_13 * V_6 ;
T_17 * V_22 ;
int V_180 ;
T_14 * V_60 ;
struct V_8 V_9 ;
struct V_181 V_182 ;
if ( V_177 -> V_183 . V_184 > 1 )
return 0 ;
args = V_177 -> args ;
F_87 ( args ) ;
V_22 = V_177 -> V_22 ;
V_2 = args -> V_2 ;
V_60 = args -> V_75 ;
if ( ( error = F_88 ( V_2 , & V_179 , V_65 ) ) ) {
return error ;
}
V_179 -= args -> V_32 -> V_185 ;
while ( V_179 > args -> V_32 -> V_186 ) {
if ( ( error = F_89 ( args , V_179 , & V_180 ) ) ) {
return error ;
}
if ( V_180 )
V_179 -= args -> V_32 -> V_185 ;
else
return 0 ;
}
if ( ( error = F_90 ( V_60 , V_2 , & V_179 , V_65 ) ) ) {
return error ;
}
if ( F_91 ( V_22 , V_179 ) > V_76 + args -> V_32 -> V_92 )
return 0 ;
V_83 = V_177 -> V_183 . V_187 [ 0 ] . V_4 ;
V_6 = V_83 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
ASSERT ( V_9 . V_12 == V_42 ||
V_9 . V_12 == V_45 ) ;
error = F_92 ( V_60 , V_2 , args -> V_32 -> V_186 , & V_178 ) ;
if ( error )
return error ;
free = V_178 -> V_7 ;
V_2 -> V_10 -> V_188 ( & V_182 , free ) ;
ASSERT ( ! V_182 . V_189 ) ;
if ( F_85 ( & V_9 , V_182 . V_190 ) > args -> V_32 -> V_92 ) {
F_59 ( V_60 , V_178 ) ;
return 0 ;
}
if ( V_9 . V_27 )
F_70 ( args , & V_9 , V_83 ) ;
V_83 -> V_73 = & V_66 ;
F_27 ( V_60 , V_83 , V_67 ) ;
V_9 . V_12 = ( V_9 . V_12 == V_42 )
? V_19
: V_13 ;
V_26 = F_5 ( args -> V_32 , V_6 ) ;
V_26 -> V_72 = F_8 ( V_182 . V_190 ) ;
memcpy ( F_6 ( V_26 ) , V_2 -> V_10 -> V_191 ( free ) ,
V_182 . V_190 * sizeof( V_116 ) ) ;
V_2 -> V_10 -> V_90 ( V_6 , & V_9 ) ;
F_35 ( args , V_83 ) ;
F_49 ( args , V_83 , 0 , F_7 ( V_26 -> V_72 ) - 1 ) ;
F_36 ( args , V_83 ) ;
F_48 ( V_2 , V_83 ) ;
error = F_79 ( args ,
F_32 ( args -> V_32 , V_77 ) ,
V_178 ) ;
if ( error ) {
ASSERT ( error != - V_120 ) ;
return error ;
}
V_178 = NULL ;
error = F_80 ( args , V_83 , NULL ) ;
V_177 -> V_183 . V_187 [ 0 ] . V_4 = NULL ;
return error ;
}
