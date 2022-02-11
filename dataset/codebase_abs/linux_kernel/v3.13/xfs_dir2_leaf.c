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
V_30 = F_4 ( V_22 , V_2 ) ;
if ( ! V_23 ) {
V_30 -> V_11 ( & V_9 , V_6 ) ;
V_23 = & V_9 ;
}
V_25 = V_30 -> V_31 ( V_6 ) ;
V_26 = F_5 ( V_22 , V_6 ) ;
if ( V_23 -> V_32 > V_30 -> V_33 ( V_22 ) )
return false ;
if ( ( V_23 -> V_12 == V_19 ||
V_23 -> V_12 == V_13 ) &&
( char * ) & V_25 [ V_23 -> V_32 ] > ( char * ) F_6 ( V_26 ) )
return false ;
for ( V_28 = V_27 = 0 ; V_28 < V_23 -> V_32 ; V_28 ++ ) {
if ( V_28 + 1 < V_23 -> V_32 ) {
if ( F_7 ( V_25 [ V_28 ] . V_34 ) >
F_7 ( V_25 [ V_28 + 1 ] . V_34 ) )
return false ;
}
if ( V_25 [ V_28 ] . V_35 == F_8 ( V_36 ) )
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
struct V_21 * V_22 = V_4 -> V_37 -> V_38 ;
struct V_5 * V_6 = V_4 -> V_7 ;
ASSERT ( V_12 == V_19 || V_12 == V_39 ) ;
if ( F_10 ( & V_22 -> V_40 ) ) {
struct V_14 * V_15 = V_4 -> V_7 ;
T_2 V_41 ;
V_41 = ( V_12 == V_19 ) ? V_13
: V_42 ;
if ( V_15 -> V_16 . V_23 . V_12 != F_11 ( V_41 ) )
return false ;
if ( ! F_12 ( & V_15 -> V_16 . V_43 , & V_22 -> V_40 . V_44 ) )
return false ;
if ( F_2 ( V_15 -> V_16 . V_17 ) != V_4 -> V_18 )
return false ;
} else {
if ( V_6 -> V_23 . V_16 . V_12 != F_11 ( V_12 ) )
return false ;
}
return F_3 ( V_22 , NULL , NULL , V_6 ) ;
}
static void
F_13 (
struct V_3 * V_4 ,
T_2 V_12 )
{
struct V_21 * V_22 = V_4 -> V_37 -> V_38 ;
if ( ( F_10 ( & V_22 -> V_40 ) &&
! F_14 ( V_4 -> V_7 , F_15 ( V_4 -> V_45 ) ,
V_46 ) ) ||
! F_9 ( V_4 , V_12 ) ) {
F_16 ( V_47 , V_48 , V_22 , V_4 -> V_7 ) ;
F_17 ( V_4 , V_49 ) ;
}
}
static void
F_18 (
struct V_3 * V_4 ,
T_2 V_12 )
{
struct V_21 * V_22 = V_4 -> V_37 -> V_38 ;
struct V_50 * V_51 = V_4 -> V_52 ;
struct V_14 * V_53 = V_4 -> V_7 ;
if ( ! F_9 ( V_4 , V_12 ) ) {
F_16 ( V_47 , V_48 , V_22 , V_4 -> V_7 ) ;
F_17 ( V_4 , V_49 ) ;
return;
}
if ( ! F_10 ( & V_22 -> V_40 ) )
return;
if ( V_51 )
V_53 -> V_16 . V_54 = F_19 ( V_51 -> V_55 . V_56 ) ;
F_20 ( V_4 -> V_7 , F_15 ( V_4 -> V_45 ) , V_46 ) ;
}
static void
F_21 (
struct V_3 * V_4 )
{
F_13 ( V_4 , V_19 ) ;
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
F_13 ( V_4 , V_39 ) ;
}
static void
F_24 (
struct V_3 * V_4 )
{
F_18 ( V_4 , V_39 ) ;
}
static int
F_25 (
struct V_57 * V_58 ,
struct V_1 * V_2 ,
T_3 V_59 ,
T_4 V_60 ,
struct V_3 * * V_61 )
{
int V_62 ;
V_62 = F_26 ( V_58 , V_2 , V_59 , V_60 , V_61 ,
V_63 , & V_64 ) ;
if ( ! V_62 && V_58 )
F_27 ( V_58 , * V_61 , V_65 ) ;
return V_62 ;
}
int
F_28 (
struct V_57 * V_58 ,
struct V_1 * V_2 ,
T_3 V_59 ,
T_4 V_60 ,
struct V_3 * * V_61 )
{
int V_62 ;
V_62 = F_26 ( V_58 , V_2 , V_59 , V_60 , V_61 ,
V_63 , & V_66 ) ;
if ( ! V_62 && V_58 )
F_27 ( V_58 , * V_61 , V_67 ) ;
return V_62 ;
}
static void
F_29 (
struct V_21 * V_22 ,
struct V_57 * V_58 ,
struct V_3 * V_4 ,
T_5 V_68 ,
T_2 type )
{
struct V_5 * V_6 = V_4 -> V_7 ;
ASSERT ( type == V_19 || type == V_39 ) ;
if ( F_10 ( & V_22 -> V_40 ) ) {
struct V_14 * V_15 = V_4 -> V_7 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_16 . V_23 . V_12 = ( type == V_19 )
? F_11 ( V_13 )
: F_11 ( V_42 ) ;
V_15 -> V_16 . V_17 = F_19 ( V_4 -> V_18 ) ;
V_15 -> V_16 . V_68 = F_19 ( V_68 ) ;
F_30 ( & V_15 -> V_16 . V_43 , & V_22 -> V_40 . V_44 ) ;
} else {
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_23 . V_16 . V_12 = F_11 ( type ) ;
}
if ( type == V_19 ) {
struct V_69 * V_26 ;
V_26 = F_5 ( V_22 , V_6 ) ;
V_26 -> V_70 = 0 ;
V_4 -> V_71 = & V_64 ;
F_27 ( V_58 , V_4 , V_65 ) ;
} else {
V_4 -> V_71 = & V_66 ;
F_27 ( V_58 , V_4 , V_67 ) ;
}
}
int
F_31 (
T_6 * args ,
T_7 V_72 ,
struct V_3 * * V_61 ,
T_2 V_12 )
{
struct V_1 * V_2 = args -> V_2 ;
struct V_57 * V_58 = args -> V_73 ;
struct V_21 * V_22 = V_2 -> V_20 ;
struct V_3 * V_4 ;
int error ;
ASSERT ( V_12 == V_19 || V_12 == V_39 ) ;
ASSERT ( V_72 >= F_32 ( V_22 ) &&
V_72 < F_33 ( V_22 ) ) ;
error = F_34 ( V_58 , V_2 , F_35 ( V_22 , V_72 ) , - 1 , & V_4 ,
V_63 ) ;
if ( error )
return error ;
F_29 ( V_22 , V_58 , V_4 , V_2 -> V_74 , V_12 ) ;
F_36 ( V_58 , V_2 , V_4 ) ;
if ( V_12 == V_19 )
F_37 ( V_58 , V_4 ) ;
* V_61 = V_4 ;
return 0 ;
}
int
F_38 (
T_6 * args ,
struct V_3 * V_75 )
{
T_8 * V_76 ;
T_3 V_17 ;
T_9 * V_23 ;
T_10 * V_77 ;
T_11 * V_78 ;
T_12 * V_2 ;
int error ;
struct V_3 * V_79 ;
T_7 V_80 ;
T_13 * V_6 ;
T_1 * V_26 ;
T_14 * V_22 ;
int V_81 ;
int V_82 ;
T_15 * V_58 ;
struct V_83 * V_84 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
F_39 ( args ) ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_58 = args -> V_73 ;
if ( ( error = F_40 ( args , & V_17 ) ) ) {
return error ;
}
V_80 = F_41 ( V_22 , V_17 ) ;
ASSERT ( V_80 == F_32 ( V_22 ) ) ;
error = F_31 ( args , V_80 , & V_79 , V_19 ) ;
if ( error )
return error ;
V_6 = V_79 -> V_7 ;
V_23 = V_75 -> V_7 ;
F_42 ( V_2 , V_75 ) ;
V_78 = F_43 ( V_22 , V_23 ) ;
V_77 = F_44 ( V_78 ) ;
V_84 = V_2 -> V_10 -> V_85 ( V_23 ) ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_9 . V_32 = F_7 ( V_78 -> V_32 ) ;
V_9 . V_27 = F_7 ( V_78 -> V_27 ) ;
V_2 -> V_10 -> V_86 ( V_6 , & V_9 ) ;
F_36 ( V_58 , V_2 , V_79 ) ;
memcpy ( V_25 , V_77 , F_7 ( V_78 -> V_32 ) * sizeof( T_10 ) ) ;
F_45 ( V_58 , V_2 , V_79 , 0 , V_9 . V_32 - 1 ) ;
V_82 = 0 ;
V_81 = 1 ;
F_46 ( V_58 , V_2 , V_75 ,
( V_87 ) ( ( char * ) V_77 - ( char * ) V_23 ) ,
( V_87 ) ( ( char * ) V_23 + V_22 -> V_88 -
( char * ) V_77 ) ,
& V_81 , & V_82 ) ;
V_75 -> V_71 = & V_89 ;
F_27 ( V_58 , V_75 , V_90 ) ;
if ( V_23 -> V_12 == F_8 ( V_91 ) )
V_23 -> V_12 = F_8 ( V_92 ) ;
else
V_23 -> V_12 = F_8 ( V_93 ) ;
if ( V_82 )
F_47 ( V_2 , V_23 , & V_81 ) ;
V_26 = F_5 ( V_22 , V_6 ) ;
V_26 -> V_70 = F_8 ( 1 ) ;
V_76 = F_6 ( V_26 ) ;
V_76 [ 0 ] = V_84 [ 0 ] . V_94 ;
if ( V_81 )
F_48 ( V_58 , V_2 , V_75 ) ;
F_49 ( V_2 , V_79 ) ;
F_42 ( V_2 , V_75 ) ;
F_50 ( V_58 , V_79 , 0 , 0 ) ;
return 0 ;
}
STATIC void
F_51 (
struct V_8 * V_9 ,
struct V_24 * V_25 ,
int V_95 ,
int * V_96 ,
int * V_97 )
{
for ( * V_96 = V_95 - 1 ; * V_96 >= 0 ; -- * V_96 ) {
if ( V_25 [ * V_96 ] . V_35 ==
F_8 ( V_36 ) )
break;
}
for ( * V_97 = V_95 ; * V_97 < V_9 -> V_32 ; ++ * V_97 ) {
if ( V_25 [ * V_97 ] . V_35 ==
F_8 ( V_36 ) )
break;
if ( * V_96 >= 0 && V_95 - * V_96 <= * V_97 - V_95 )
break;
}
}
struct V_24 *
F_52 (
struct V_8 * V_9 ,
struct V_24 * V_25 ,
int V_95 ,
int V_98 ,
int V_96 ,
int V_97 ,
int * V_99 ,
int * V_100 )
{
if ( ! V_9 -> V_27 ) {
T_10 * V_101 ;
V_101 = & V_25 [ V_95 ] ;
if ( V_95 < V_9 -> V_32 )
memmove ( V_101 + 1 , V_101 ,
( V_9 -> V_32 - V_95 ) * sizeof( * V_101 ) ) ;
* V_99 = V_95 ;
* V_100 = V_9 -> V_32 ++ ;
return V_101 ;
}
if ( V_98 == 0 )
F_51 ( V_9 , V_25 , V_95 ,
& V_96 , & V_97 ) ;
if ( V_96 >= 0 &&
( V_97 == V_9 -> V_32 ||
V_95 - V_96 - 1 < V_97 - V_95 ) ) {
ASSERT ( V_95 - V_96 - 1 >= 0 ) ;
ASSERT ( V_25 [ V_96 ] . V_35 ==
F_8 ( V_36 ) ) ;
if ( V_95 - V_96 - 1 > 0 ) {
memmove ( & V_25 [ V_96 ] , & V_25 [ V_96 + 1 ] ,
( V_95 - V_96 - 1 ) *
sizeof( T_10 ) ) ;
}
* V_99 = F_53 ( V_96 , * V_99 ) ;
* V_100 = F_54 ( V_95 - 1 , * V_100 ) ;
V_9 -> V_27 -- ;
return & V_25 [ V_95 - 1 ] ;
}
ASSERT ( V_97 - V_95 >= 0 ) ;
ASSERT ( V_25 [ V_97 ] . V_35 == F_8 ( V_36 ) ) ;
if ( V_97 - V_95 > 0 ) {
memmove ( & V_25 [ V_95 + 1 ] , & V_25 [ V_95 ] ,
( V_97 - V_95 ) * sizeof( T_10 ) ) ;
}
* V_99 = F_53 ( V_95 , * V_99 ) ;
* V_100 = F_54 ( V_97 , * V_100 ) ;
V_9 -> V_27 -- ;
return & V_25 [ V_95 ] ;
}
int
F_55 (
T_6 * args )
{
T_8 * V_76 ;
int V_98 ;
T_9 * V_23 ;
struct V_3 * V_75 ;
T_16 * V_102 ;
T_12 * V_2 ;
T_17 * V_103 ;
int error ;
int V_104 ;
int V_97 ;
int V_28 ;
int V_95 ;
struct V_3 * V_79 ;
T_13 * V_6 ;
int V_94 ;
T_10 * V_101 ;
int V_99 ;
int V_100 ;
int V_96 ;
T_1 * V_26 ;
T_14 * V_22 ;
int V_105 ;
int V_81 ;
int V_82 ;
T_8 * V_106 ;
T_15 * V_58 ;
T_7 V_107 ;
struct V_83 * V_84 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
F_56 ( args ) ;
V_2 = args -> V_2 ;
V_58 = args -> V_73 ;
V_22 = V_2 -> V_20 ;
error = F_25 ( V_58 , V_2 , V_22 -> V_108 , - 1 , & V_79 ) ;
if ( error )
return error ;
V_95 = F_57 ( args , V_79 ) ;
V_6 = V_79 -> V_7 ;
V_26 = F_5 ( V_22 , V_6 ) ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_76 = F_6 ( V_26 ) ;
V_94 = V_2 -> V_10 -> V_109 ( args -> V_110 ) ;
for ( V_107 = - 1 , V_101 = & V_25 [ V_95 ] ;
V_95 < V_9 . V_32 && F_7 ( V_101 -> V_34 ) == args -> V_34 ;
V_95 ++ , V_101 ++ ) {
if ( F_7 ( V_101 -> V_35 ) == V_36 )
continue;
V_28 = F_58 ( V_22 , F_7 ( V_101 -> V_35 ) ) ;
ASSERT ( V_28 < F_7 ( V_26 -> V_70 ) ) ;
ASSERT ( V_76 [ V_28 ] != F_11 ( V_111 ) ) ;
if ( F_59 ( V_76 [ V_28 ] ) >= V_94 ) {
V_107 = V_28 ;
break;
}
}
if ( V_107 == - 1 ) {
for ( V_28 = 0 ; V_28 < F_7 ( V_26 -> V_70 ) ; V_28 ++ ) {
if ( V_76 [ V_28 ] == F_11 ( V_111 ) &&
V_107 == - 1 )
V_107 = V_28 ;
else if ( F_59 ( V_76 [ V_28 ] ) >= V_94 ) {
V_107 = V_28 ;
break;
}
}
}
V_105 = 0 ;
if ( ! V_9 . V_27 )
V_105 += sizeof( T_10 ) ;
if ( V_107 == - 1 )
V_105 += sizeof( V_112 ) ;
if ( V_107 != - 1 && V_76 [ V_107 ] == F_11 ( V_111 ) )
V_107 = - 1 ;
if ( ( char * ) V_76 - ( char * ) & V_25 [ V_9 . V_32 ] < V_105 &&
V_9 . V_27 > 1 )
V_98 = 1 ;
else if ( ( char * ) V_76 - ( char * ) & V_25 [ V_9 . V_32 ] < V_105 ) {
if ( ( args -> V_113 & V_114 ) ||
args -> V_115 == 0 ) {
F_60 ( V_58 , V_79 ) ;
return F_61 ( V_116 ) ;
}
error = F_62 ( args , V_79 ) ;
if ( error )
return error ;
return F_63 ( args ) ;
}
else
V_98 = 0 ;
if ( args -> V_113 & V_114 ) {
F_60 ( V_58 , V_79 ) ;
return V_107 == - 1 ? F_61 ( V_116 ) : 0 ;
}
if ( args -> V_115 == 0 && V_107 == - 1 ) {
F_60 ( V_58 , V_79 ) ;
return F_61 ( V_116 ) ;
}
if ( V_98 ) {
F_64 ( & V_9 , V_25 , & V_95 , & V_96 ,
& V_97 , & V_99 , & V_100 ) ;
}
else if ( V_9 . V_27 ) {
V_99 = V_9 . V_32 ;
V_100 = - 1 ;
}
if ( V_107 == - 1 ) {
if ( ( error = F_65 ( args , V_117 ,
& V_107 ) ) ) {
F_60 ( V_58 , V_79 ) ;
return error ;
}
if ( ( error = F_66 ( args , V_107 , & V_75 ) ) ) {
F_60 ( V_58 , V_79 ) ;
return error ;
}
if ( V_107 >= F_7 ( V_26 -> V_70 ) ) {
V_76 -- ;
memmove ( & V_76 [ 0 ] , & V_76 [ 1 ] ,
F_7 ( V_26 -> V_70 ) * sizeof( V_76 [ 0 ] ) ) ;
F_67 ( & V_26 -> V_70 , 1 ) ;
F_37 ( V_58 , V_79 ) ;
F_50 ( V_58 , V_79 , 0 , F_7 ( V_26 -> V_70 ) - 1 ) ;
}
else
F_50 ( V_58 , V_79 , V_107 , V_107 ) ;
V_23 = V_75 -> V_7 ;
V_84 = V_2 -> V_10 -> V_85 ( V_23 ) ;
V_76 [ V_107 ] = V_84 [ 0 ] . V_94 ;
V_104 = 1 ;
} else {
error = F_68 ( V_58 , V_2 ,
F_35 ( V_22 , V_107 ) ,
- 1 , & V_75 ) ;
if ( error ) {
F_60 ( V_58 , V_79 ) ;
return error ;
}
V_23 = V_75 -> V_7 ;
V_84 = V_2 -> V_10 -> V_85 ( V_23 ) ;
V_104 = 0 ;
}
V_103 = ( T_17 * )
( ( char * ) V_23 + F_59 ( V_84 [ 0 ] . V_118 ) ) ;
ASSERT ( F_59 ( V_103 -> V_94 ) >= V_94 ) ;
V_82 = V_81 = 0 ;
F_69 ( V_58 , V_2 , V_75 , V_103 ,
( V_87 ) ( ( char * ) V_103 - ( char * ) V_23 ) , V_94 ,
& V_81 , & V_82 ) ;
V_102 = ( T_16 * ) V_103 ;
V_102 -> V_119 = F_19 ( args -> V_119 ) ;
V_102 -> V_110 = args -> V_110 ;
memcpy ( V_102 -> V_120 , args -> V_120 , V_102 -> V_110 ) ;
V_2 -> V_10 -> V_121 ( V_102 , args -> V_122 ) ;
V_106 = V_2 -> V_10 -> V_123 ( V_102 ) ;
* V_106 = F_11 ( ( char * ) V_102 - ( char * ) V_23 ) ;
if ( V_82 )
F_47 ( V_2 , V_23 , & V_81 ) ;
if ( V_81 )
F_48 ( V_58 , V_2 , V_75 ) ;
F_70 ( V_58 , V_2 , V_75 , V_102 ) ;
if ( F_59 ( V_76 [ V_107 ] ) != F_59 ( V_84 [ 0 ] . V_94 ) ) {
V_76 [ V_107 ] = V_84 [ 0 ] . V_94 ;
if ( ! V_104 )
F_50 ( V_58 , V_79 , V_107 , V_107 ) ;
}
V_101 = F_52 ( & V_9 , V_25 , V_95 , V_98 , V_96 ,
V_97 , & V_99 , & V_100 ) ;
V_101 -> V_34 = F_8 ( args -> V_34 ) ;
V_101 -> V_35 = F_8 ( F_71 ( V_22 , V_107 ,
F_59 ( * V_106 ) ) ) ;
V_2 -> V_10 -> V_86 ( V_6 , & V_9 ) ;
F_36 ( V_58 , V_2 , V_79 ) ;
F_45 ( V_58 , V_2 , V_79 , V_99 , V_100 ) ;
F_49 ( V_2 , V_79 ) ;
F_42 ( V_2 , V_75 ) ;
return 0 ;
}
void
F_72 (
T_6 * args ,
struct V_8 * V_9 ,
struct V_3 * V_4 )
{
int V_124 ;
T_13 * V_6 ;
int V_125 ;
int V_126 ;
struct V_24 * V_25 ;
struct V_1 * V_2 = args -> V_2 ;
V_6 = V_4 -> V_7 ;
if ( ! V_9 -> V_27 )
return;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
for ( V_124 = V_126 = 0 , V_125 = - 1 ; V_124 < V_9 -> V_32 ; V_124 ++ ) {
if ( V_25 [ V_124 ] . V_35 == F_8 ( V_36 ) )
continue;
if ( V_124 > V_126 ) {
if ( V_125 == - 1 )
V_125 = V_126 ;
V_25 [ V_126 ] = V_25 [ V_124 ] ;
}
V_126 ++ ;
}
ASSERT ( V_9 -> V_27 == V_124 - V_126 ) ;
V_9 -> V_32 -= V_9 -> V_27 ;
V_9 -> V_27 = 0 ;
V_2 -> V_10 -> V_86 ( V_6 , V_9 ) ;
F_36 ( args -> V_73 , V_2 , V_4 ) ;
if ( V_125 != - 1 )
F_45 ( args -> V_73 , V_2 , V_4 , V_125 , V_126 - 1 ) ;
}
void
F_64 (
struct V_8 * V_9 ,
struct V_24 * V_25 ,
int * V_127 ,
int * V_128 ,
int * V_129 ,
int * V_130 ,
int * V_131 )
{
int V_124 ;
int V_97 ;
int V_95 ;
int V_132 ;
int V_96 ;
int V_133 = 0 ;
int V_126 ;
ASSERT ( V_9 -> V_27 > 1 ) ;
V_95 = * V_127 ;
F_51 ( V_9 , V_25 , V_95 , & V_96 , & V_97 ) ;
if ( V_96 >= 0 &&
( V_97 == V_9 -> V_32 ||
V_95 - V_96 <= V_97 - V_95 ) )
V_132 = V_96 ;
else
V_132 = V_97 ;
for ( V_124 = V_126 = 0 ; V_124 < V_9 -> V_32 ; V_124 ++ ) {
if ( V_95 == V_124 )
V_133 = V_126 ;
if ( V_124 != V_132 &&
V_25 [ V_124 ] . V_35 == F_8 ( V_36 ) ) {
if ( V_124 == V_126 )
* V_130 = V_126 ;
continue;
}
if ( V_124 == V_132 )
V_96 = V_97 = V_126 ;
if ( V_124 > V_126 )
V_25 [ V_126 ] = V_25 [ V_124 ] ;
V_126 ++ ;
}
ASSERT ( V_124 > V_126 ) ;
if ( V_95 == V_124 )
V_133 = V_126 ;
* V_127 = V_133 ;
V_9 -> V_32 -= V_124 - V_126 ;
V_9 -> V_27 = 1 ;
if ( V_96 >= V_133 )
V_96 = - 1 ;
else
V_97 = V_9 -> V_32 ;
* V_131 = V_9 -> V_32 - 1 ;
* V_128 = V_96 ;
* V_129 = V_97 ;
}
static void
F_50 (
T_15 * V_58 ,
struct V_3 * V_4 ,
int V_134 ,
int V_135 )
{
T_8 * V_136 ;
T_8 * V_137 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 * V_26 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ) ;
V_26 = F_5 ( V_58 -> V_138 , V_6 ) ;
V_136 = F_6 ( V_26 ) + V_134 ;
V_137 = F_6 ( V_26 ) + V_135 ;
F_73 ( V_58 , V_4 , ( V_139 ) ( ( char * ) V_136 - ( char * ) V_6 ) ,
( V_139 ) ( ( char * ) V_137 - ( char * ) V_6 + sizeof( * V_137 ) - 1 ) ) ;
}
void
F_45 (
struct V_57 * V_58 ,
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_134 ,
int V_135 )
{
T_10 * V_140 ;
T_10 * V_141 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_24 * V_25 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_39 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_42 ) ) ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_140 = & V_25 [ V_134 ] ;
V_141 = & V_25 [ V_135 ] ;
F_73 ( V_58 , V_4 , ( V_139 ) ( ( char * ) V_140 - ( char * ) V_6 ) ,
( V_139 ) ( ( char * ) V_141 - ( char * ) V_6 + sizeof( * V_141 ) - 1 ) ) ;
}
void
F_36 (
struct V_57 * V_58 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_39 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_42 ) ) ;
F_73 ( V_58 , V_4 , ( V_139 ) ( ( char * ) & V_6 -> V_23 - ( char * ) V_6 ) ,
V_2 -> V_10 -> V_142 - 1 ) ;
}
STATIC void
F_37 (
struct V_57 * V_58 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 * V_26 ;
struct V_21 * V_22 = V_58 -> V_138 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_39 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_42 ) ) ;
V_26 = F_5 ( V_22 , V_6 ) ;
F_73 ( V_58 , V_4 , ( V_139 ) ( ( char * ) V_26 - ( char * ) V_6 ) ,
( V_139 ) ( V_22 -> V_88 - 1 ) ) ;
}
int
F_74 (
T_6 * args )
{
struct V_3 * V_75 ;
T_16 * V_102 ;
T_12 * V_2 ;
int error ;
int V_95 ;
struct V_3 * V_79 ;
T_13 * V_6 ;
T_10 * V_101 ;
T_15 * V_58 ;
struct V_24 * V_25 ;
F_75 ( args ) ;
if ( ( error = F_76 ( args , & V_79 , & V_95 , & V_75 ) ) ) {
return error ;
}
V_58 = args -> V_73 ;
V_2 = args -> V_2 ;
F_49 ( V_2 , V_79 ) ;
V_6 = V_79 -> V_7 ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_101 = & V_25 [ V_95 ] ;
V_102 = ( T_16 * )
( ( char * ) V_75 -> V_7 +
F_77 ( V_2 -> V_20 , F_7 ( V_101 -> V_35 ) ) ) ;
args -> V_119 = F_2 ( V_102 -> V_119 ) ;
args -> V_122 = V_2 -> V_10 -> V_143 ( V_102 ) ;
error = F_78 ( args , V_102 -> V_120 , V_102 -> V_110 ) ;
F_60 ( V_58 , V_75 ) ;
F_60 ( V_58 , V_79 ) ;
return F_61 ( error ) ;
}
static int
F_76 (
T_6 * args ,
struct V_3 * * V_144 ,
int * V_127 ,
struct V_3 * * V_145 )
{
T_7 V_146 = - 1 ;
struct V_3 * V_75 = NULL ;
T_16 * V_102 ;
T_12 * V_2 ;
int error ;
int V_95 ;
struct V_3 * V_79 ;
T_10 * V_101 ;
T_13 * V_6 ;
T_14 * V_22 ;
T_7 V_147 ;
T_15 * V_58 ;
T_7 V_148 = - 1 ;
enum V_149 V_150 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
V_2 = args -> V_2 ;
V_58 = args -> V_73 ;
V_22 = V_2 -> V_20 ;
error = F_25 ( V_58 , V_2 , V_22 -> V_108 , - 1 , & V_79 ) ;
if ( error )
return error ;
* V_144 = V_79 ;
V_6 = V_79 -> V_7 ;
F_49 ( V_2 , V_79 ) ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_95 = F_57 ( args , V_79 ) ;
for ( V_101 = & V_25 [ V_95 ] ;
V_95 < V_9 . V_32 && F_7 ( V_101 -> V_34 ) == args -> V_34 ;
V_101 ++ , V_95 ++ ) {
if ( F_7 ( V_101 -> V_35 ) == V_36 )
continue;
V_147 = F_58 ( V_22 , F_7 ( V_101 -> V_35 ) ) ;
if ( V_147 != V_146 ) {
if ( V_75 )
F_60 ( V_58 , V_75 ) ;
error = F_68 ( V_58 , V_2 ,
F_35 ( V_22 , V_147 ) ,
- 1 , & V_75 ) ;
if ( error ) {
F_60 ( V_58 , V_79 ) ;
return error ;
}
V_146 = V_147 ;
}
V_102 = ( T_16 * ) ( ( char * ) V_75 -> V_7 +
F_77 ( V_22 , F_7 ( V_101 -> V_35 ) ) ) ;
V_150 = V_22 -> V_151 -> V_152 ( args , V_102 -> V_120 , V_102 -> V_110 ) ;
if ( V_150 != V_153 && V_150 != args -> V_154 ) {
args -> V_154 = V_150 ;
* V_127 = V_95 ;
if ( V_150 == V_155 ) {
* V_145 = V_75 ;
return 0 ;
}
V_148 = V_146 ;
}
}
ASSERT ( args -> V_113 & V_156 ) ;
if ( args -> V_154 == V_157 ) {
ASSERT ( V_148 != - 1 ) ;
if ( V_148 != V_146 ) {
F_60 ( V_58 , V_75 ) ;
error = F_68 ( V_58 , V_2 ,
F_35 ( V_22 , V_148 ) ,
- 1 , & V_75 ) ;
if ( error ) {
F_60 ( V_58 , V_79 ) ;
return error ;
}
}
* V_145 = V_75 ;
return 0 ;
}
ASSERT ( V_148 == - 1 ) ;
if ( V_75 )
F_60 ( V_58 , V_75 ) ;
F_60 ( V_58 , V_79 ) ;
return F_61 ( V_158 ) ;
}
int
F_79 (
T_6 * args )
{
T_8 * V_76 ;
T_9 * V_23 ;
T_7 V_159 ;
struct V_3 * V_75 ;
T_16 * V_102 ;
T_12 * V_2 ;
int error ;
T_7 V_28 ;
int V_95 ;
struct V_3 * V_79 ;
T_13 * V_6 ;
T_10 * V_101 ;
T_1 * V_26 ;
T_14 * V_22 ;
int V_81 ;
int V_82 ;
V_112 V_160 ;
T_15 * V_58 ;
struct V_83 * V_84 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
F_80 ( args ) ;
if ( ( error = F_76 ( args , & V_79 , & V_95 , & V_75 ) ) ) {
return error ;
}
V_2 = args -> V_2 ;
V_58 = args -> V_73 ;
V_22 = V_2 -> V_20 ;
V_6 = V_79 -> V_7 ;
V_23 = V_75 -> V_7 ;
F_42 ( V_2 , V_75 ) ;
V_84 = V_2 -> V_10 -> V_85 ( V_23 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_101 = & V_25 [ V_95 ] ;
V_159 = F_58 ( V_22 , F_7 ( V_101 -> V_35 ) ) ;
V_102 = ( T_16 * )
( ( char * ) V_23 + F_77 ( V_22 , F_7 ( V_101 -> V_35 ) ) ) ;
V_82 = V_81 = 0 ;
V_160 = F_59 ( V_84 [ 0 ] . V_94 ) ;
V_26 = F_5 ( V_22 , V_6 ) ;
V_76 = F_6 ( V_26 ) ;
ASSERT ( F_59 ( V_76 [ V_159 ] ) == V_160 ) ;
F_46 ( V_58 , V_2 , V_75 ,
( V_87 ) ( ( char * ) V_102 - ( char * ) V_23 ) ,
V_2 -> V_10 -> V_109 ( V_102 -> V_110 ) , & V_81 , & V_82 ) ;
V_9 . V_27 ++ ;
V_2 -> V_10 -> V_86 ( V_6 , & V_9 ) ;
F_36 ( V_58 , V_2 , V_79 ) ;
V_101 -> V_35 = F_8 ( V_36 ) ;
F_45 ( V_58 , V_2 , V_79 , V_95 , V_95 ) ;
if ( V_82 )
F_47 ( V_2 , V_23 , & V_81 ) ;
if ( V_81 )
F_48 ( V_58 , V_2 , V_75 ) ;
if ( F_59 ( V_84 [ 0 ] . V_94 ) != V_160 ) {
V_76 [ V_159 ] = V_84 [ 0 ] . V_94 ;
F_50 ( V_58 , V_79 , V_159 , V_159 ) ;
}
F_42 ( V_2 , V_75 ) ;
if ( F_59 ( V_84 [ 0 ] . V_94 ) ==
V_22 -> V_88 - V_2 -> V_10 -> V_161 ) {
ASSERT ( V_159 != V_22 -> V_162 ) ;
if ( ( error = F_81 ( args , V_159 , V_75 ) ) ) {
if ( error == V_116 && args -> V_115 == 0 )
error = 0 ;
F_49 ( V_2 , V_79 ) ;
return error ;
}
V_75 = NULL ;
if ( V_159 == F_7 ( V_26 -> V_70 ) - 1 ) {
for ( V_28 = V_159 - 1 ; V_28 > 0 ; V_28 -- ) {
if ( V_76 [ V_28 ] != F_11 ( V_111 ) )
break;
}
memmove ( & V_76 [ V_159 - V_28 ] , V_76 ,
( F_7 ( V_26 -> V_70 ) - ( V_159 - V_28 ) ) * sizeof( * V_76 ) ) ;
F_67 ( & V_26 -> V_70 , - ( V_159 - V_28 ) ) ;
F_37 ( V_58 , V_79 ) ;
F_50 ( V_58 , V_79 , 0 , F_7 ( V_26 -> V_70 ) - 1 ) ;
} else
V_76 [ V_159 ] = F_11 ( V_111 ) ;
}
else if ( V_159 != V_22 -> V_162 )
V_75 = NULL ;
F_49 ( V_2 , V_79 ) ;
return F_82 ( args , V_79 , V_75 ) ;
}
int
F_83 (
T_6 * args )
{
struct V_3 * V_75 ;
T_16 * V_102 ;
T_12 * V_2 ;
int error ;
int V_95 ;
struct V_3 * V_79 ;
T_13 * V_6 ;
T_10 * V_101 ;
T_15 * V_58 ;
struct V_24 * V_25 ;
F_84 ( args ) ;
if ( ( error = F_76 ( args , & V_79 , & V_95 , & V_75 ) ) ) {
return error ;
}
V_2 = args -> V_2 ;
V_6 = V_79 -> V_7 ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_101 = & V_25 [ V_95 ] ;
V_102 = ( T_16 * )
( ( char * ) V_75 -> V_7 +
F_77 ( V_2 -> V_20 , F_7 ( V_101 -> V_35 ) ) ) ;
ASSERT ( args -> V_119 != F_2 ( V_102 -> V_119 ) ) ;
V_102 -> V_119 = F_19 ( args -> V_119 ) ;
V_2 -> V_10 -> V_121 ( V_102 , args -> V_122 ) ;
V_58 = args -> V_73 ;
F_70 ( V_58 , V_2 , V_75 , V_102 ) ;
F_49 ( V_2 , V_79 ) ;
F_60 ( V_58 , V_79 ) ;
return 0 ;
}
int
F_57 (
T_6 * args ,
struct V_3 * V_79 )
{
T_18 V_163 = 0 ;
T_18 V_164 ;
int V_165 ;
int V_166 ;
T_13 * V_6 ;
T_10 * V_101 ;
int V_167 = 0 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
V_6 = V_79 -> V_7 ;
V_25 = args -> V_2 -> V_10 -> V_31 ( V_6 ) ;
args -> V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
for ( V_101 = V_25 , V_166 = 0 , V_165 = V_9 . V_32 - 1 ,
V_164 = args -> V_34 ;
V_166 <= V_165 ; ) {
V_167 = ( V_166 + V_165 ) >> 1 ;
if ( ( V_163 = F_7 ( V_101 [ V_167 ] . V_34 ) ) == V_164 )
break;
if ( V_163 < V_164 )
V_166 = V_167 + 1 ;
else
V_165 = V_167 - 1 ;
}
if ( V_163 == V_164 ) {
while ( V_167 > 0 && F_7 ( V_101 [ V_167 - 1 ] . V_34 ) == V_164 ) {
V_167 -- ;
}
}
else if ( V_163 < V_164 )
V_167 ++ ;
return V_167 ;
}
int
F_85 (
T_6 * args ,
struct V_3 * V_79 ,
T_7 V_159 )
{
T_8 * V_76 ;
struct V_3 * V_75 ;
T_12 * V_2 ;
int error ;
T_13 * V_6 ;
T_1 * V_26 ;
T_14 * V_22 ;
T_15 * V_58 ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_58 = args -> V_73 ;
error = F_68 ( V_58 , V_2 , F_35 ( V_22 , V_159 ) , - 1 , & V_75 ) ;
if ( error )
return error ;
V_6 = V_79 -> V_7 ;
V_26 = F_5 ( V_22 , V_6 ) ;
#ifdef F_86
{
struct V_168 * V_23 = V_75 -> V_7 ;
struct V_83 * V_84 = V_2 -> V_10 -> V_85 ( V_23 ) ;
ASSERT ( V_23 -> V_12 == F_8 ( V_92 ) ||
V_23 -> V_12 == F_8 ( V_93 ) ) ;
ASSERT ( F_59 ( V_84 [ 0 ] . V_94 ) ==
V_22 -> V_88 - V_2 -> V_10 -> V_161 ) ;
ASSERT ( V_159 == F_7 ( V_26 -> V_70 ) - 1 ) ;
}
#endif
if ( ( error = F_81 ( args , V_159 , V_75 ) ) ) {
ASSERT ( error != V_116 ) ;
F_60 ( V_58 , V_75 ) ;
return error ;
}
V_76 = F_6 ( V_26 ) ;
F_67 ( & V_26 -> V_70 , - 1 ) ;
memmove ( & V_76 [ 1 ] , & V_76 [ 0 ] , F_7 ( V_26 -> V_70 ) * sizeof( * V_76 ) ) ;
F_37 ( V_58 , V_79 ) ;
F_50 ( V_58 , V_79 , 0 , F_7 ( V_26 -> V_70 ) - 1 ) ;
return 0 ;
}
static inline T_19
F_87 (
struct V_8 * V_23 ,
int V_169 )
{
int V_170 ;
int V_171 ;
V_170 = V_23 -> V_32 - V_23 -> V_27 ;
if ( V_23 -> V_12 == V_19 ||
V_23 -> V_12 == V_39 )
V_171 = sizeof( struct V_172 ) ;
else
V_171 = sizeof( struct V_14 ) ;
return V_171 + V_170 * sizeof( T_10 )
+ V_169 * sizeof( V_112 )
+ sizeof( T_1 ) ;
}
int
F_88 (
T_20 * V_173 )
{
T_6 * args ;
T_12 * V_2 ;
int error ;
struct V_3 * V_174 ;
T_21 V_175 ;
T_22 * free ;
struct V_3 * V_79 ;
T_1 * V_26 ;
T_13 * V_6 ;
T_14 * V_22 ;
int V_176 ;
T_15 * V_58 ;
struct V_8 V_9 ;
struct V_177 V_178 ;
if ( V_173 -> V_179 . V_180 > 1 )
return 0 ;
args = V_173 -> args ;
F_89 ( args ) ;
V_22 = V_173 -> V_22 ;
V_2 = args -> V_2 ;
V_58 = args -> V_73 ;
if ( ( error = F_90 ( V_58 , V_2 , & V_175 , V_63 ) ) ) {
return error ;
}
V_175 -= V_22 -> V_181 ;
while ( V_175 > V_22 -> V_182 ) {
if ( ( error = F_91 ( args , V_175 , & V_176 ) ) ) {
return error ;
}
if ( V_176 )
V_175 -= V_22 -> V_181 ;
else
return 0 ;
}
if ( ( error = F_92 ( V_58 , V_2 , & V_175 , V_63 ) ) ) {
return error ;
}
if ( F_93 ( V_22 , V_175 ) > V_183 + V_22 -> V_88 )
return 0 ;
V_79 = V_173 -> V_179 . V_184 [ 0 ] . V_4 ;
V_6 = V_79 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
ASSERT ( V_9 . V_12 == V_39 ||
V_9 . V_12 == V_42 ) ;
error = F_94 ( V_58 , V_2 , V_22 -> V_182 , & V_174 ) ;
if ( error )
return error ;
free = V_174 -> V_7 ;
V_2 -> V_10 -> V_185 ( & V_178 , free ) ;
ASSERT ( ! V_178 . V_186 ) ;
if ( F_87 ( & V_9 , V_178 . V_187 ) > V_22 -> V_88 ) {
F_60 ( V_58 , V_174 ) ;
return 0 ;
}
if ( V_9 . V_27 )
F_72 ( args , & V_9 , V_79 ) ;
V_79 -> V_71 = & V_64 ;
F_27 ( V_58 , V_79 , V_65 ) ;
V_9 . V_12 = ( V_9 . V_12 == V_39 )
? V_19
: V_13 ;
V_26 = F_5 ( V_22 , V_6 ) ;
V_26 -> V_70 = F_8 ( V_178 . V_187 ) ;
memcpy ( F_6 ( V_26 ) , V_2 -> V_10 -> V_188 ( free ) ,
V_178 . V_187 * sizeof( V_112 ) ) ;
V_2 -> V_10 -> V_86 ( V_6 , & V_9 ) ;
F_36 ( V_58 , V_2 , V_79 ) ;
F_50 ( V_58 , V_79 , 0 , F_7 ( V_26 -> V_70 ) - 1 ) ;
F_37 ( V_58 , V_79 ) ;
F_49 ( V_2 , V_79 ) ;
error = F_81 ( args , F_33 ( V_22 ) , V_174 ) ;
if ( error ) {
ASSERT ( error != V_116 ) ;
return error ;
}
V_174 = NULL ;
error = F_82 ( args , V_79 , NULL ) ;
V_173 -> V_179 . V_184 [ 0 ] . V_4 = NULL ;
return error ;
}
