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
if ( F_10 ( & V_22 -> V_40 ) &&
! F_14 ( V_4 , V_45 ) )
F_15 ( V_4 , V_46 ) ;
else if ( ! F_9 ( V_4 , V_12 ) )
F_15 ( V_4 , V_47 ) ;
if ( V_4 -> V_48 )
F_16 ( V_4 ) ;
}
static void
F_17 (
struct V_3 * V_4 ,
T_2 V_12 )
{
struct V_21 * V_22 = V_4 -> V_37 -> V_38 ;
struct V_49 * V_50 = V_4 -> V_51 ;
struct V_14 * V_52 = V_4 -> V_7 ;
if ( ! F_9 ( V_4 , V_12 ) ) {
F_15 ( V_4 , V_47 ) ;
F_16 ( V_4 ) ;
return;
}
if ( ! F_10 ( & V_22 -> V_40 ) )
return;
if ( V_50 )
V_52 -> V_16 . V_53 = F_18 ( V_50 -> V_54 . V_55 ) ;
F_19 ( V_4 , V_45 ) ;
}
static void
F_20 (
struct V_3 * V_4 )
{
F_13 ( V_4 , V_19 ) ;
}
static void
F_21 (
struct V_3 * V_4 )
{
F_17 ( V_4 , V_19 ) ;
}
static void
F_22 (
struct V_3 * V_4 )
{
F_13 ( V_4 , V_39 ) ;
}
static void
F_23 (
struct V_3 * V_4 )
{
F_17 ( V_4 , V_39 ) ;
}
static int
F_24 (
struct V_56 * V_57 ,
struct V_1 * V_2 ,
T_3 V_58 ,
T_4 V_59 ,
struct V_3 * * V_60 )
{
int V_61 ;
V_61 = F_25 ( V_57 , V_2 , V_58 , V_59 , V_60 ,
V_62 , & V_63 ) ;
if ( ! V_61 && V_57 )
F_26 ( V_57 , * V_60 , V_64 ) ;
return V_61 ;
}
int
F_27 (
struct V_56 * V_57 ,
struct V_1 * V_2 ,
T_3 V_58 ,
T_4 V_59 ,
struct V_3 * * V_60 )
{
int V_61 ;
V_61 = F_25 ( V_57 , V_2 , V_58 , V_59 , V_60 ,
V_62 , & V_65 ) ;
if ( ! V_61 && V_57 )
F_26 ( V_57 , * V_60 , V_66 ) ;
return V_61 ;
}
static void
F_28 (
struct V_21 * V_22 ,
struct V_56 * V_57 ,
struct V_3 * V_4 ,
T_5 V_67 ,
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
V_15 -> V_16 . V_17 = F_18 ( V_4 -> V_18 ) ;
V_15 -> V_16 . V_67 = F_18 ( V_67 ) ;
F_29 ( & V_15 -> V_16 . V_43 , & V_22 -> V_40 . V_44 ) ;
} else {
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_23 . V_16 . V_12 = F_11 ( type ) ;
}
if ( type == V_19 ) {
struct V_68 * V_26 ;
V_26 = F_5 ( V_22 , V_6 ) ;
V_26 -> V_69 = 0 ;
V_4 -> V_70 = & V_63 ;
F_26 ( V_57 , V_4 , V_64 ) ;
} else {
V_4 -> V_70 = & V_65 ;
F_26 ( V_57 , V_4 , V_66 ) ;
}
}
int
F_30 (
T_6 * args ,
T_7 V_71 ,
struct V_3 * * V_60 ,
T_2 V_12 )
{
struct V_1 * V_2 = args -> V_2 ;
struct V_56 * V_57 = args -> V_72 ;
struct V_21 * V_22 = V_2 -> V_20 ;
struct V_3 * V_4 ;
int error ;
ASSERT ( V_12 == V_19 || V_12 == V_39 ) ;
ASSERT ( V_71 >= F_31 ( V_22 ) &&
V_71 < F_32 ( V_22 ) ) ;
error = F_33 ( V_57 , V_2 , F_34 ( V_22 , V_71 ) , - 1 , & V_4 ,
V_62 ) ;
if ( error )
return error ;
F_28 ( V_22 , V_57 , V_4 , V_2 -> V_73 , V_12 ) ;
F_35 ( V_57 , V_2 , V_4 ) ;
if ( V_12 == V_19 )
F_36 ( V_57 , V_4 ) ;
* V_60 = V_4 ;
return 0 ;
}
int
F_37 (
T_6 * args ,
struct V_3 * V_74 )
{
T_8 * V_75 ;
T_3 V_17 ;
T_9 * V_23 ;
T_10 * V_76 ;
T_11 * V_77 ;
T_12 * V_2 ;
int error ;
struct V_3 * V_78 ;
T_7 V_79 ;
T_13 * V_6 ;
T_1 * V_26 ;
T_14 * V_22 ;
int V_80 ;
int V_81 ;
T_15 * V_57 ;
struct V_82 * V_83 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
F_38 ( args ) ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_57 = args -> V_72 ;
if ( ( error = F_39 ( args , & V_17 ) ) ) {
return error ;
}
V_79 = F_40 ( V_22 , V_17 ) ;
ASSERT ( V_79 == F_31 ( V_22 ) ) ;
error = F_30 ( args , V_79 , & V_78 , V_19 ) ;
if ( error )
return error ;
V_6 = V_78 -> V_7 ;
V_23 = V_74 -> V_7 ;
F_41 ( V_2 , V_74 ) ;
V_77 = F_42 ( V_22 , V_23 ) ;
V_76 = F_43 ( V_77 ) ;
V_83 = V_2 -> V_10 -> V_84 ( V_23 ) ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_9 . V_32 = F_7 ( V_77 -> V_32 ) ;
V_9 . V_27 = F_7 ( V_77 -> V_27 ) ;
V_2 -> V_10 -> V_85 ( V_6 , & V_9 ) ;
F_35 ( V_57 , V_2 , V_78 ) ;
memcpy ( V_25 , V_76 , F_7 ( V_77 -> V_32 ) * sizeof( T_10 ) ) ;
F_44 ( V_57 , V_2 , V_78 , 0 , V_9 . V_32 - 1 ) ;
V_81 = 0 ;
V_80 = 1 ;
F_45 ( V_57 , V_2 , V_74 ,
( V_86 ) ( ( char * ) V_76 - ( char * ) V_23 ) ,
( V_86 ) ( ( char * ) V_23 + V_22 -> V_87 -
( char * ) V_76 ) ,
& V_80 , & V_81 ) ;
V_74 -> V_70 = & V_88 ;
F_26 ( V_57 , V_74 , V_89 ) ;
if ( V_23 -> V_12 == F_8 ( V_90 ) )
V_23 -> V_12 = F_8 ( V_91 ) ;
else
V_23 -> V_12 = F_8 ( V_92 ) ;
if ( V_81 )
F_46 ( V_2 , V_23 , & V_80 ) ;
V_26 = F_5 ( V_22 , V_6 ) ;
V_26 -> V_69 = F_8 ( 1 ) ;
V_75 = F_6 ( V_26 ) ;
V_75 [ 0 ] = V_83 [ 0 ] . V_93 ;
if ( V_80 )
F_47 ( V_57 , V_2 , V_74 ) ;
F_48 ( V_2 , V_78 ) ;
F_41 ( V_2 , V_74 ) ;
F_49 ( V_57 , V_78 , 0 , 0 ) ;
return 0 ;
}
STATIC void
F_50 (
struct V_8 * V_9 ,
struct V_24 * V_25 ,
int V_94 ,
int * V_95 ,
int * V_96 )
{
for ( * V_95 = V_94 - 1 ; * V_95 >= 0 ; -- * V_95 ) {
if ( V_25 [ * V_95 ] . V_35 ==
F_8 ( V_36 ) )
break;
}
for ( * V_96 = V_94 ; * V_96 < V_9 -> V_32 ; ++ * V_96 ) {
if ( V_25 [ * V_96 ] . V_35 ==
F_8 ( V_36 ) )
break;
if ( * V_95 >= 0 && V_94 - * V_95 <= * V_96 - V_94 )
break;
}
}
struct V_24 *
F_51 (
struct V_8 * V_9 ,
struct V_24 * V_25 ,
int V_94 ,
int V_97 ,
int V_95 ,
int V_96 ,
int * V_98 ,
int * V_99 )
{
if ( ! V_9 -> V_27 ) {
T_10 * V_100 ;
V_100 = & V_25 [ V_94 ] ;
if ( V_94 < V_9 -> V_32 )
memmove ( V_100 + 1 , V_100 ,
( V_9 -> V_32 - V_94 ) * sizeof( * V_100 ) ) ;
* V_98 = V_94 ;
* V_99 = V_9 -> V_32 ++ ;
return V_100 ;
}
if ( V_97 == 0 )
F_50 ( V_9 , V_25 , V_94 ,
& V_95 , & V_96 ) ;
if ( V_95 >= 0 &&
( V_96 == V_9 -> V_32 ||
V_94 - V_95 - 1 < V_96 - V_94 ) ) {
ASSERT ( V_94 - V_95 - 1 >= 0 ) ;
ASSERT ( V_25 [ V_95 ] . V_35 ==
F_8 ( V_36 ) ) ;
if ( V_94 - V_95 - 1 > 0 ) {
memmove ( & V_25 [ V_95 ] , & V_25 [ V_95 + 1 ] ,
( V_94 - V_95 - 1 ) *
sizeof( T_10 ) ) ;
}
* V_98 = F_52 ( V_95 , * V_98 ) ;
* V_99 = F_53 ( V_94 - 1 , * V_99 ) ;
V_9 -> V_27 -- ;
return & V_25 [ V_94 - 1 ] ;
}
ASSERT ( V_96 - V_94 >= 0 ) ;
ASSERT ( V_25 [ V_96 ] . V_35 == F_8 ( V_36 ) ) ;
if ( V_96 - V_94 > 0 ) {
memmove ( & V_25 [ V_94 + 1 ] , & V_25 [ V_94 ] ,
( V_96 - V_94 ) * sizeof( T_10 ) ) ;
}
* V_98 = F_52 ( V_94 , * V_98 ) ;
* V_99 = F_53 ( V_96 , * V_99 ) ;
V_9 -> V_27 -- ;
return & V_25 [ V_94 ] ;
}
int
F_54 (
T_6 * args )
{
T_8 * V_75 ;
int V_97 ;
T_9 * V_23 ;
struct V_3 * V_74 ;
T_16 * V_101 ;
T_12 * V_2 ;
T_17 * V_102 ;
int error ;
int V_103 ;
int V_96 ;
int V_28 ;
int V_94 ;
struct V_3 * V_78 ;
T_13 * V_6 ;
int V_93 ;
T_10 * V_100 ;
int V_98 ;
int V_99 ;
int V_95 ;
T_1 * V_26 ;
T_14 * V_22 ;
int V_104 ;
int V_80 ;
int V_81 ;
T_8 * V_105 ;
T_15 * V_57 ;
T_7 V_106 ;
struct V_82 * V_83 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
F_55 ( args ) ;
V_2 = args -> V_2 ;
V_57 = args -> V_72 ;
V_22 = V_2 -> V_20 ;
error = F_24 ( V_57 , V_2 , V_22 -> V_107 , - 1 , & V_78 ) ;
if ( error )
return error ;
V_94 = F_56 ( args , V_78 ) ;
V_6 = V_78 -> V_7 ;
V_26 = F_5 ( V_22 , V_6 ) ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_75 = F_6 ( V_26 ) ;
V_93 = V_2 -> V_10 -> V_108 ( args -> V_109 ) ;
for ( V_106 = - 1 , V_100 = & V_25 [ V_94 ] ;
V_94 < V_9 . V_32 && F_7 ( V_100 -> V_34 ) == args -> V_34 ;
V_94 ++ , V_100 ++ ) {
if ( F_7 ( V_100 -> V_35 ) == V_36 )
continue;
V_28 = F_57 ( V_22 , F_7 ( V_100 -> V_35 ) ) ;
ASSERT ( V_28 < F_7 ( V_26 -> V_69 ) ) ;
ASSERT ( V_75 [ V_28 ] != F_11 ( V_110 ) ) ;
if ( F_58 ( V_75 [ V_28 ] ) >= V_93 ) {
V_106 = V_28 ;
break;
}
}
if ( V_106 == - 1 ) {
for ( V_28 = 0 ; V_28 < F_7 ( V_26 -> V_69 ) ; V_28 ++ ) {
if ( V_75 [ V_28 ] == F_11 ( V_110 ) &&
V_106 == - 1 )
V_106 = V_28 ;
else if ( F_58 ( V_75 [ V_28 ] ) >= V_93 ) {
V_106 = V_28 ;
break;
}
}
}
V_104 = 0 ;
if ( ! V_9 . V_27 )
V_104 += sizeof( T_10 ) ;
if ( V_106 == - 1 )
V_104 += sizeof( V_111 ) ;
if ( V_106 != - 1 && V_75 [ V_106 ] == F_11 ( V_110 ) )
V_106 = - 1 ;
if ( ( char * ) V_75 - ( char * ) & V_25 [ V_9 . V_32 ] < V_104 &&
V_9 . V_27 > 1 )
V_97 = 1 ;
else if ( ( char * ) V_75 - ( char * ) & V_25 [ V_9 . V_32 ] < V_104 ) {
if ( ( args -> V_112 & V_113 ) ||
args -> V_114 == 0 ) {
F_59 ( V_57 , V_78 ) ;
return F_60 ( V_115 ) ;
}
error = F_61 ( args , V_78 ) ;
if ( error )
return error ;
return F_62 ( args ) ;
}
else
V_97 = 0 ;
if ( args -> V_112 & V_113 ) {
F_59 ( V_57 , V_78 ) ;
return V_106 == - 1 ? F_60 ( V_115 ) : 0 ;
}
if ( args -> V_114 == 0 && V_106 == - 1 ) {
F_59 ( V_57 , V_78 ) ;
return F_60 ( V_115 ) ;
}
if ( V_97 ) {
F_63 ( & V_9 , V_25 , & V_94 , & V_95 ,
& V_96 , & V_98 , & V_99 ) ;
}
else if ( V_9 . V_27 ) {
V_98 = V_9 . V_32 ;
V_99 = - 1 ;
}
if ( V_106 == - 1 ) {
if ( ( error = F_64 ( args , V_116 ,
& V_106 ) ) ) {
F_59 ( V_57 , V_78 ) ;
return error ;
}
if ( ( error = F_65 ( args , V_106 , & V_74 ) ) ) {
F_59 ( V_57 , V_78 ) ;
return error ;
}
if ( V_106 >= F_7 ( V_26 -> V_69 ) ) {
V_75 -- ;
memmove ( & V_75 [ 0 ] , & V_75 [ 1 ] ,
F_7 ( V_26 -> V_69 ) * sizeof( V_75 [ 0 ] ) ) ;
F_66 ( & V_26 -> V_69 , 1 ) ;
F_36 ( V_57 , V_78 ) ;
F_49 ( V_57 , V_78 , 0 , F_7 ( V_26 -> V_69 ) - 1 ) ;
}
else
F_49 ( V_57 , V_78 , V_106 , V_106 ) ;
V_23 = V_74 -> V_7 ;
V_83 = V_2 -> V_10 -> V_84 ( V_23 ) ;
V_75 [ V_106 ] = V_83 [ 0 ] . V_93 ;
V_103 = 1 ;
} else {
error = F_67 ( V_57 , V_2 ,
F_34 ( V_22 , V_106 ) ,
- 1 , & V_74 ) ;
if ( error ) {
F_59 ( V_57 , V_78 ) ;
return error ;
}
V_23 = V_74 -> V_7 ;
V_83 = V_2 -> V_10 -> V_84 ( V_23 ) ;
V_103 = 0 ;
}
V_102 = ( T_17 * )
( ( char * ) V_23 + F_58 ( V_83 [ 0 ] . V_117 ) ) ;
ASSERT ( F_58 ( V_102 -> V_93 ) >= V_93 ) ;
V_81 = V_80 = 0 ;
F_68 ( V_57 , V_2 , V_74 , V_102 ,
( V_86 ) ( ( char * ) V_102 - ( char * ) V_23 ) , V_93 ,
& V_80 , & V_81 ) ;
V_101 = ( T_16 * ) V_102 ;
V_101 -> V_118 = F_18 ( args -> V_118 ) ;
V_101 -> V_109 = args -> V_109 ;
memcpy ( V_101 -> V_119 , args -> V_119 , V_101 -> V_109 ) ;
V_2 -> V_10 -> V_120 ( V_101 , args -> V_121 ) ;
V_105 = V_2 -> V_10 -> V_122 ( V_101 ) ;
* V_105 = F_11 ( ( char * ) V_101 - ( char * ) V_23 ) ;
if ( V_81 )
F_46 ( V_2 , V_23 , & V_80 ) ;
if ( V_80 )
F_47 ( V_57 , V_2 , V_74 ) ;
F_69 ( V_57 , V_2 , V_74 , V_101 ) ;
if ( F_58 ( V_75 [ V_106 ] ) != F_58 ( V_83 [ 0 ] . V_93 ) ) {
V_75 [ V_106 ] = V_83 [ 0 ] . V_93 ;
if ( ! V_103 )
F_49 ( V_57 , V_78 , V_106 , V_106 ) ;
}
V_100 = F_51 ( & V_9 , V_25 , V_94 , V_97 , V_95 ,
V_96 , & V_98 , & V_99 ) ;
V_100 -> V_34 = F_8 ( args -> V_34 ) ;
V_100 -> V_35 = F_8 ( F_70 ( V_22 , V_106 ,
F_58 ( * V_105 ) ) ) ;
V_2 -> V_10 -> V_85 ( V_6 , & V_9 ) ;
F_35 ( V_57 , V_2 , V_78 ) ;
F_44 ( V_57 , V_2 , V_78 , V_98 , V_99 ) ;
F_48 ( V_2 , V_78 ) ;
F_41 ( V_2 , V_74 ) ;
return 0 ;
}
void
F_71 (
T_6 * args ,
struct V_8 * V_9 ,
struct V_3 * V_4 )
{
int V_123 ;
T_13 * V_6 ;
int V_124 ;
int V_125 ;
struct V_24 * V_25 ;
struct V_1 * V_2 = args -> V_2 ;
V_6 = V_4 -> V_7 ;
if ( ! V_9 -> V_27 )
return;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
for ( V_123 = V_125 = 0 , V_124 = - 1 ; V_123 < V_9 -> V_32 ; V_123 ++ ) {
if ( V_25 [ V_123 ] . V_35 == F_8 ( V_36 ) )
continue;
if ( V_123 > V_125 ) {
if ( V_124 == - 1 )
V_124 = V_125 ;
V_25 [ V_125 ] = V_25 [ V_123 ] ;
}
V_125 ++ ;
}
ASSERT ( V_9 -> V_27 == V_123 - V_125 ) ;
V_9 -> V_32 -= V_9 -> V_27 ;
V_9 -> V_27 = 0 ;
V_2 -> V_10 -> V_85 ( V_6 , V_9 ) ;
F_35 ( args -> V_72 , V_2 , V_4 ) ;
if ( V_124 != - 1 )
F_44 ( args -> V_72 , V_2 , V_4 , V_124 , V_125 - 1 ) ;
}
void
F_63 (
struct V_8 * V_9 ,
struct V_24 * V_25 ,
int * V_126 ,
int * V_127 ,
int * V_128 ,
int * V_129 ,
int * V_130 )
{
int V_123 ;
int V_96 ;
int V_94 ;
int V_131 ;
int V_95 ;
int V_132 = 0 ;
int V_125 ;
ASSERT ( V_9 -> V_27 > 1 ) ;
V_94 = * V_126 ;
F_50 ( V_9 , V_25 , V_94 , & V_95 , & V_96 ) ;
if ( V_95 >= 0 &&
( V_96 == V_9 -> V_32 ||
V_94 - V_95 <= V_96 - V_94 ) )
V_131 = V_95 ;
else
V_131 = V_96 ;
for ( V_123 = V_125 = 0 ; V_123 < V_9 -> V_32 ; V_123 ++ ) {
if ( V_94 == V_123 )
V_132 = V_125 ;
if ( V_123 != V_131 &&
V_25 [ V_123 ] . V_35 == F_8 ( V_36 ) ) {
if ( V_123 == V_125 )
* V_129 = V_125 ;
continue;
}
if ( V_123 == V_131 )
V_95 = V_96 = V_125 ;
if ( V_123 > V_125 )
V_25 [ V_125 ] = V_25 [ V_123 ] ;
V_125 ++ ;
}
ASSERT ( V_123 > V_125 ) ;
if ( V_94 == V_123 )
V_132 = V_125 ;
* V_126 = V_132 ;
V_9 -> V_32 -= V_123 - V_125 ;
V_9 -> V_27 = 1 ;
if ( V_95 >= V_132 )
V_95 = - 1 ;
else
V_96 = V_9 -> V_32 ;
* V_130 = V_9 -> V_32 - 1 ;
* V_127 = V_95 ;
* V_128 = V_96 ;
}
static void
F_49 (
T_15 * V_57 ,
struct V_3 * V_4 ,
int V_133 ,
int V_134 )
{
T_8 * V_135 ;
T_8 * V_136 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 * V_26 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ) ;
V_26 = F_5 ( V_57 -> V_137 , V_6 ) ;
V_135 = F_6 ( V_26 ) + V_133 ;
V_136 = F_6 ( V_26 ) + V_134 ;
F_72 ( V_57 , V_4 , ( V_138 ) ( ( char * ) V_135 - ( char * ) V_6 ) ,
( V_138 ) ( ( char * ) V_136 - ( char * ) V_6 + sizeof( * V_136 ) - 1 ) ) ;
}
void
F_44 (
struct V_56 * V_57 ,
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_133 ,
int V_134 )
{
T_10 * V_139 ;
T_10 * V_140 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_24 * V_25 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_39 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_42 ) ) ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_139 = & V_25 [ V_133 ] ;
V_140 = & V_25 [ V_134 ] ;
F_72 ( V_57 , V_4 , ( V_138 ) ( ( char * ) V_139 - ( char * ) V_6 ) ,
( V_138 ) ( ( char * ) V_140 - ( char * ) V_6 + sizeof( * V_140 ) - 1 ) ) ;
}
void
F_35 (
struct V_56 * V_57 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_39 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_42 ) ) ;
F_72 ( V_57 , V_4 , ( V_138 ) ( ( char * ) & V_6 -> V_23 - ( char * ) V_6 ) ,
V_2 -> V_10 -> V_141 - 1 ) ;
}
STATIC void
F_36 (
struct V_56 * V_57 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 * V_26 ;
struct V_21 * V_22 = V_57 -> V_137 ;
ASSERT ( V_6 -> V_23 . V_16 . V_12 == F_11 ( V_19 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_13 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_39 ) ||
V_6 -> V_23 . V_16 . V_12 == F_11 ( V_42 ) ) ;
V_26 = F_5 ( V_22 , V_6 ) ;
F_72 ( V_57 , V_4 , ( V_138 ) ( ( char * ) V_26 - ( char * ) V_6 ) ,
( V_138 ) ( V_22 -> V_87 - 1 ) ) ;
}
int
F_73 (
T_6 * args )
{
struct V_3 * V_74 ;
T_16 * V_101 ;
T_12 * V_2 ;
int error ;
int V_94 ;
struct V_3 * V_78 ;
T_13 * V_6 ;
T_10 * V_100 ;
T_15 * V_57 ;
struct V_24 * V_25 ;
F_74 ( args ) ;
if ( ( error = F_75 ( args , & V_78 , & V_94 , & V_74 ) ) ) {
return error ;
}
V_57 = args -> V_72 ;
V_2 = args -> V_2 ;
F_48 ( V_2 , V_78 ) ;
V_6 = V_78 -> V_7 ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_100 = & V_25 [ V_94 ] ;
V_101 = ( T_16 * )
( ( char * ) V_74 -> V_7 +
F_76 ( V_2 -> V_20 , F_7 ( V_100 -> V_35 ) ) ) ;
args -> V_118 = F_2 ( V_101 -> V_118 ) ;
args -> V_121 = V_2 -> V_10 -> V_142 ( V_101 ) ;
error = F_77 ( args , V_101 -> V_119 , V_101 -> V_109 ) ;
F_59 ( V_57 , V_74 ) ;
F_59 ( V_57 , V_78 ) ;
return F_60 ( error ) ;
}
static int
F_75 (
T_6 * args ,
struct V_3 * * V_143 ,
int * V_126 ,
struct V_3 * * V_144 )
{
T_7 V_145 = - 1 ;
struct V_3 * V_74 = NULL ;
T_16 * V_101 ;
T_12 * V_2 ;
int error ;
int V_94 ;
struct V_3 * V_78 ;
T_10 * V_100 ;
T_13 * V_6 ;
T_14 * V_22 ;
T_7 V_146 ;
T_15 * V_57 ;
T_7 V_147 = - 1 ;
enum V_148 V_149 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
V_2 = args -> V_2 ;
V_57 = args -> V_72 ;
V_22 = V_2 -> V_20 ;
error = F_24 ( V_57 , V_2 , V_22 -> V_107 , - 1 , & V_78 ) ;
if ( error )
return error ;
* V_143 = V_78 ;
V_6 = V_78 -> V_7 ;
F_48 ( V_2 , V_78 ) ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_94 = F_56 ( args , V_78 ) ;
for ( V_100 = & V_25 [ V_94 ] ;
V_94 < V_9 . V_32 && F_7 ( V_100 -> V_34 ) == args -> V_34 ;
V_100 ++ , V_94 ++ ) {
if ( F_7 ( V_100 -> V_35 ) == V_36 )
continue;
V_146 = F_57 ( V_22 , F_7 ( V_100 -> V_35 ) ) ;
if ( V_146 != V_145 ) {
if ( V_74 )
F_59 ( V_57 , V_74 ) ;
error = F_67 ( V_57 , V_2 ,
F_34 ( V_22 , V_146 ) ,
- 1 , & V_74 ) ;
if ( error ) {
F_59 ( V_57 , V_78 ) ;
return error ;
}
V_145 = V_146 ;
}
V_101 = ( T_16 * ) ( ( char * ) V_74 -> V_7 +
F_76 ( V_22 , F_7 ( V_100 -> V_35 ) ) ) ;
V_149 = V_22 -> V_150 -> V_151 ( args , V_101 -> V_119 , V_101 -> V_109 ) ;
if ( V_149 != V_152 && V_149 != args -> V_153 ) {
args -> V_153 = V_149 ;
* V_126 = V_94 ;
if ( V_149 == V_154 ) {
* V_144 = V_74 ;
return 0 ;
}
V_147 = V_145 ;
}
}
ASSERT ( args -> V_112 & V_155 ) ;
if ( args -> V_153 == V_156 ) {
ASSERT ( V_147 != - 1 ) ;
if ( V_147 != V_145 ) {
F_59 ( V_57 , V_74 ) ;
error = F_67 ( V_57 , V_2 ,
F_34 ( V_22 , V_147 ) ,
- 1 , & V_74 ) ;
if ( error ) {
F_59 ( V_57 , V_78 ) ;
return error ;
}
}
* V_144 = V_74 ;
return 0 ;
}
ASSERT ( V_147 == - 1 ) ;
if ( V_74 )
F_59 ( V_57 , V_74 ) ;
F_59 ( V_57 , V_78 ) ;
return F_60 ( V_157 ) ;
}
int
F_78 (
T_6 * args )
{
T_8 * V_75 ;
T_9 * V_23 ;
T_7 V_158 ;
struct V_3 * V_74 ;
T_16 * V_101 ;
T_12 * V_2 ;
int error ;
T_7 V_28 ;
int V_94 ;
struct V_3 * V_78 ;
T_13 * V_6 ;
T_10 * V_100 ;
T_1 * V_26 ;
T_14 * V_22 ;
int V_80 ;
int V_81 ;
V_111 V_159 ;
T_15 * V_57 ;
struct V_82 * V_83 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
F_79 ( args ) ;
if ( ( error = F_75 ( args , & V_78 , & V_94 , & V_74 ) ) ) {
return error ;
}
V_2 = args -> V_2 ;
V_57 = args -> V_72 ;
V_22 = V_2 -> V_20 ;
V_6 = V_78 -> V_7 ;
V_23 = V_74 -> V_7 ;
F_41 ( V_2 , V_74 ) ;
V_83 = V_2 -> V_10 -> V_84 ( V_23 ) ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_100 = & V_25 [ V_94 ] ;
V_158 = F_57 ( V_22 , F_7 ( V_100 -> V_35 ) ) ;
V_101 = ( T_16 * )
( ( char * ) V_23 + F_76 ( V_22 , F_7 ( V_100 -> V_35 ) ) ) ;
V_81 = V_80 = 0 ;
V_159 = F_58 ( V_83 [ 0 ] . V_93 ) ;
V_26 = F_5 ( V_22 , V_6 ) ;
V_75 = F_6 ( V_26 ) ;
ASSERT ( F_58 ( V_75 [ V_158 ] ) == V_159 ) ;
F_45 ( V_57 , V_2 , V_74 ,
( V_86 ) ( ( char * ) V_101 - ( char * ) V_23 ) ,
V_2 -> V_10 -> V_108 ( V_101 -> V_109 ) , & V_80 , & V_81 ) ;
V_9 . V_27 ++ ;
V_2 -> V_10 -> V_85 ( V_6 , & V_9 ) ;
F_35 ( V_57 , V_2 , V_78 ) ;
V_100 -> V_35 = F_8 ( V_36 ) ;
F_44 ( V_57 , V_2 , V_78 , V_94 , V_94 ) ;
if ( V_81 )
F_46 ( V_2 , V_23 , & V_80 ) ;
if ( V_80 )
F_47 ( V_57 , V_2 , V_74 ) ;
if ( F_58 ( V_83 [ 0 ] . V_93 ) != V_159 ) {
V_75 [ V_158 ] = V_83 [ 0 ] . V_93 ;
F_49 ( V_57 , V_78 , V_158 , V_158 ) ;
}
F_41 ( V_2 , V_74 ) ;
if ( F_58 ( V_83 [ 0 ] . V_93 ) ==
V_22 -> V_87 - V_2 -> V_10 -> V_160 ) {
ASSERT ( V_158 != V_22 -> V_161 ) ;
if ( ( error = F_80 ( args , V_158 , V_74 ) ) ) {
if ( error == V_115 && args -> V_114 == 0 )
error = 0 ;
F_48 ( V_2 , V_78 ) ;
return error ;
}
V_74 = NULL ;
if ( V_158 == F_7 ( V_26 -> V_69 ) - 1 ) {
for ( V_28 = V_158 - 1 ; V_28 > 0 ; V_28 -- ) {
if ( V_75 [ V_28 ] != F_11 ( V_110 ) )
break;
}
memmove ( & V_75 [ V_158 - V_28 ] , V_75 ,
( F_7 ( V_26 -> V_69 ) - ( V_158 - V_28 ) ) * sizeof( * V_75 ) ) ;
F_66 ( & V_26 -> V_69 , - ( V_158 - V_28 ) ) ;
F_36 ( V_57 , V_78 ) ;
F_49 ( V_57 , V_78 , 0 , F_7 ( V_26 -> V_69 ) - 1 ) ;
} else
V_75 [ V_158 ] = F_11 ( V_110 ) ;
}
else if ( V_158 != V_22 -> V_161 )
V_74 = NULL ;
F_48 ( V_2 , V_78 ) ;
return F_81 ( args , V_78 , V_74 ) ;
}
int
F_82 (
T_6 * args )
{
struct V_3 * V_74 ;
T_16 * V_101 ;
T_12 * V_2 ;
int error ;
int V_94 ;
struct V_3 * V_78 ;
T_13 * V_6 ;
T_10 * V_100 ;
T_15 * V_57 ;
struct V_24 * V_25 ;
F_83 ( args ) ;
if ( ( error = F_75 ( args , & V_78 , & V_94 , & V_74 ) ) ) {
return error ;
}
V_2 = args -> V_2 ;
V_6 = V_78 -> V_7 ;
V_25 = V_2 -> V_10 -> V_31 ( V_6 ) ;
V_100 = & V_25 [ V_94 ] ;
V_101 = ( T_16 * )
( ( char * ) V_74 -> V_7 +
F_76 ( V_2 -> V_20 , F_7 ( V_100 -> V_35 ) ) ) ;
ASSERT ( args -> V_118 != F_2 ( V_101 -> V_118 ) ) ;
V_101 -> V_118 = F_18 ( args -> V_118 ) ;
V_2 -> V_10 -> V_120 ( V_101 , args -> V_121 ) ;
V_57 = args -> V_72 ;
F_69 ( V_57 , V_2 , V_74 , V_101 ) ;
F_48 ( V_2 , V_78 ) ;
F_59 ( V_57 , V_78 ) ;
return 0 ;
}
int
F_56 (
T_6 * args ,
struct V_3 * V_78 )
{
T_18 V_162 = 0 ;
T_18 V_163 ;
int V_164 ;
int V_165 ;
T_13 * V_6 ;
T_10 * V_100 ;
int V_166 = 0 ;
struct V_24 * V_25 ;
struct V_8 V_9 ;
V_6 = V_78 -> V_7 ;
V_25 = args -> V_2 -> V_10 -> V_31 ( V_6 ) ;
args -> V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
for ( V_100 = V_25 , V_165 = 0 , V_164 = V_9 . V_32 - 1 ,
V_163 = args -> V_34 ;
V_165 <= V_164 ; ) {
V_166 = ( V_165 + V_164 ) >> 1 ;
if ( ( V_162 = F_7 ( V_100 [ V_166 ] . V_34 ) ) == V_163 )
break;
if ( V_162 < V_163 )
V_165 = V_166 + 1 ;
else
V_164 = V_166 - 1 ;
}
if ( V_162 == V_163 ) {
while ( V_166 > 0 && F_7 ( V_100 [ V_166 - 1 ] . V_34 ) == V_163 ) {
V_166 -- ;
}
}
else if ( V_162 < V_163 )
V_166 ++ ;
return V_166 ;
}
int
F_84 (
T_6 * args ,
struct V_3 * V_78 ,
T_7 V_158 )
{
T_8 * V_75 ;
struct V_3 * V_74 ;
T_12 * V_2 ;
int error ;
T_13 * V_6 ;
T_1 * V_26 ;
T_14 * V_22 ;
T_15 * V_57 ;
V_2 = args -> V_2 ;
V_22 = V_2 -> V_20 ;
V_57 = args -> V_72 ;
error = F_67 ( V_57 , V_2 , F_34 ( V_22 , V_158 ) , - 1 , & V_74 ) ;
if ( error )
return error ;
V_6 = V_78 -> V_7 ;
V_26 = F_5 ( V_22 , V_6 ) ;
#ifdef F_85
{
struct V_167 * V_23 = V_74 -> V_7 ;
struct V_82 * V_83 = V_2 -> V_10 -> V_84 ( V_23 ) ;
ASSERT ( V_23 -> V_12 == F_8 ( V_91 ) ||
V_23 -> V_12 == F_8 ( V_92 ) ) ;
ASSERT ( F_58 ( V_83 [ 0 ] . V_93 ) ==
V_22 -> V_87 - V_2 -> V_10 -> V_160 ) ;
ASSERT ( V_158 == F_7 ( V_26 -> V_69 ) - 1 ) ;
}
#endif
if ( ( error = F_80 ( args , V_158 , V_74 ) ) ) {
ASSERT ( error != V_115 ) ;
F_59 ( V_57 , V_74 ) ;
return error ;
}
V_75 = F_6 ( V_26 ) ;
F_66 ( & V_26 -> V_69 , - 1 ) ;
memmove ( & V_75 [ 1 ] , & V_75 [ 0 ] , F_7 ( V_26 -> V_69 ) * sizeof( * V_75 ) ) ;
F_36 ( V_57 , V_78 ) ;
F_49 ( V_57 , V_78 , 0 , F_7 ( V_26 -> V_69 ) - 1 ) ;
return 0 ;
}
static inline T_19
F_86 (
struct V_8 * V_23 ,
int V_168 )
{
int V_169 ;
int V_170 ;
V_169 = V_23 -> V_32 - V_23 -> V_27 ;
if ( V_23 -> V_12 == V_19 ||
V_23 -> V_12 == V_39 )
V_170 = sizeof( struct V_171 ) ;
else
V_170 = sizeof( struct V_14 ) ;
return V_170 + V_169 * sizeof( T_10 )
+ V_168 * sizeof( V_111 )
+ sizeof( T_1 ) ;
}
int
F_87 (
T_20 * V_172 )
{
T_6 * args ;
T_12 * V_2 ;
int error ;
struct V_3 * V_173 ;
T_21 V_174 ;
T_22 * free ;
struct V_3 * V_78 ;
T_1 * V_26 ;
T_13 * V_6 ;
T_14 * V_22 ;
int V_175 ;
T_15 * V_57 ;
struct V_8 V_9 ;
struct V_176 V_177 ;
if ( V_172 -> V_178 . V_179 > 1 )
return 0 ;
args = V_172 -> args ;
F_88 ( args ) ;
V_22 = V_172 -> V_22 ;
V_2 = args -> V_2 ;
V_57 = args -> V_72 ;
if ( ( error = F_89 ( V_57 , V_2 , & V_174 , V_62 ) ) ) {
return error ;
}
V_174 -= V_22 -> V_180 ;
while ( V_174 > V_22 -> V_181 ) {
if ( ( error = F_90 ( args , V_174 , & V_175 ) ) ) {
return error ;
}
if ( V_175 )
V_174 -= V_22 -> V_180 ;
else
return 0 ;
}
if ( ( error = F_91 ( V_57 , V_2 , & V_174 , V_62 ) ) ) {
return error ;
}
if ( F_92 ( V_22 , V_174 ) > V_182 + V_22 -> V_87 )
return 0 ;
V_78 = V_172 -> V_178 . V_183 [ 0 ] . V_4 ;
V_6 = V_78 -> V_7 ;
V_2 -> V_10 -> V_11 ( & V_9 , V_6 ) ;
ASSERT ( V_9 . V_12 == V_39 ||
V_9 . V_12 == V_42 ) ;
error = F_93 ( V_57 , V_2 , V_22 -> V_181 , & V_173 ) ;
if ( error )
return error ;
free = V_173 -> V_7 ;
V_2 -> V_10 -> V_184 ( & V_177 , free ) ;
ASSERT ( ! V_177 . V_185 ) ;
if ( F_86 ( & V_9 , V_177 . V_186 ) > V_22 -> V_87 ) {
F_59 ( V_57 , V_173 ) ;
return 0 ;
}
if ( V_9 . V_27 )
F_71 ( args , & V_9 , V_78 ) ;
V_78 -> V_70 = & V_63 ;
F_26 ( V_57 , V_78 , V_64 ) ;
V_9 . V_12 = ( V_9 . V_12 == V_39 )
? V_19
: V_13 ;
V_26 = F_5 ( V_22 , V_6 ) ;
V_26 -> V_69 = F_8 ( V_177 . V_186 ) ;
memcpy ( F_6 ( V_26 ) , V_2 -> V_10 -> V_187 ( free ) ,
V_177 . V_186 * sizeof( V_111 ) ) ;
V_2 -> V_10 -> V_85 ( V_6 , & V_9 ) ;
F_35 ( V_57 , V_2 , V_78 ) ;
F_49 ( V_57 , V_78 , 0 , F_7 ( V_26 -> V_69 ) - 1 ) ;
F_36 ( V_57 , V_78 ) ;
F_48 ( V_2 , V_78 ) ;
error = F_80 ( args , F_32 ( V_22 ) , V_173 ) ;
if ( error ) {
ASSERT ( error != V_115 ) ;
return error ;
}
V_173 = NULL ;
error = F_81 ( args , V_78 , NULL ) ;
V_172 -> V_178 . V_183 [ 0 ] . V_4 = NULL ;
return error ;
}
