STATIC bool
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
F_2 ( & V_9 , V_6 ) ;
if ( V_9 . V_10 == V_11 ) {
struct V_12 * V_13 = V_4 -> V_7 ;
if ( F_3 ( V_13 -> V_14 . V_15 ) != V_4 -> V_16 )
return false ;
} else if ( V_9 . V_10 != V_17 )
return false ;
return F_4 ( V_2 , & V_9 , V_6 ) ;
}
void
F_2 (
struct V_8 * V_18 ,
struct V_5 * V_19 )
{
if ( V_19 -> V_20 . V_14 . V_10 == F_5 ( V_17 ) ||
V_19 -> V_20 . V_14 . V_10 == F_5 ( V_21 ) ) {
V_18 -> V_22 = F_6 ( V_19 -> V_20 . V_14 . V_22 ) ;
V_18 -> V_23 = F_6 ( V_19 -> V_20 . V_14 . V_23 ) ;
V_18 -> V_10 = F_7 ( V_19 -> V_20 . V_14 . V_10 ) ;
V_18 -> V_24 = F_7 ( V_19 -> V_20 . V_24 ) ;
V_18 -> V_25 = F_7 ( V_19 -> V_20 . V_25 ) ;
} else {
struct V_12 * V_26 = (struct V_12 * ) V_19 ;
V_18 -> V_22 = F_6 ( V_26 -> V_14 . V_20 . V_22 ) ;
V_18 -> V_23 = F_6 ( V_26 -> V_14 . V_20 . V_23 ) ;
V_18 -> V_10 = F_7 ( V_26 -> V_14 . V_20 . V_10 ) ;
V_18 -> V_24 = F_7 ( V_26 -> V_24 ) ;
V_18 -> V_25 = F_7 ( V_26 -> V_25 ) ;
}
ASSERT ( V_18 -> V_10 == V_17 ||
V_18 -> V_10 == V_11 ||
V_18 -> V_10 == V_21 ||
V_18 -> V_10 == V_27 ) ;
}
void
F_8 (
struct V_5 * V_18 ,
struct V_8 * V_19 )
{
ASSERT ( V_19 -> V_10 == V_17 ||
V_19 -> V_10 == V_11 ||
V_19 -> V_10 == V_21 ||
V_19 -> V_10 == V_27 ) ;
if ( V_19 -> V_10 == V_17 ||
V_19 -> V_10 == V_21 ) {
V_18 -> V_20 . V_14 . V_22 = F_9 ( V_19 -> V_22 ) ;
V_18 -> V_20 . V_14 . V_23 = F_9 ( V_19 -> V_23 ) ;
V_18 -> V_20 . V_14 . V_10 = F_5 ( V_19 -> V_10 ) ;
V_18 -> V_20 . V_24 = F_5 ( V_19 -> V_24 ) ;
V_18 -> V_20 . V_25 = F_5 ( V_19 -> V_25 ) ;
} else {
struct V_12 * V_26 = (struct V_12 * ) V_18 ;
V_26 -> V_14 . V_20 . V_22 = F_9 ( V_19 -> V_22 ) ;
V_26 -> V_14 . V_20 . V_23 = F_9 ( V_19 -> V_23 ) ;
V_26 -> V_14 . V_20 . V_10 = F_5 ( V_19 -> V_10 ) ;
V_26 -> V_24 = F_5 ( V_19 -> V_24 ) ;
V_26 -> V_25 = F_5 ( V_19 -> V_25 ) ;
}
}
bool
F_4 (
struct V_1 * V_2 ,
struct V_8 * V_20 ,
struct V_5 * V_6 )
{
struct V_28 * V_29 ;
T_1 * V_30 ;
int V_25 ;
int V_31 ;
V_29 = F_10 ( V_6 ) ;
V_30 = F_11 ( V_2 , V_6 ) ;
if ( V_20 -> V_24 > F_12 ( V_2 , V_6 ) )
return false ;
if ( ( V_20 -> V_10 == V_17 ||
V_20 -> V_10 == V_11 ) &&
( char * ) & V_29 [ V_20 -> V_24 ] > ( char * ) F_13 ( V_30 ) )
return false ;
for ( V_31 = V_25 = 0 ; V_31 < V_20 -> V_24 ; V_31 ++ ) {
if ( V_31 + 1 < V_20 -> V_24 ) {
if ( F_6 ( V_29 [ V_31 ] . V_32 ) >
F_6 ( V_29 [ V_31 + 1 ] . V_32 ) )
return false ;
}
if ( V_29 [ V_31 ] . V_33 == F_9 ( V_34 ) )
V_25 ++ ;
}
if ( V_20 -> V_25 != V_25 )
return false ;
return true ;
}
static bool
F_14 (
struct V_3 * V_4 ,
T_2 V_10 )
{
struct V_1 * V_2 = V_4 -> V_35 -> V_36 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
ASSERT ( V_10 == V_17 || V_10 == V_21 ) ;
if ( F_15 ( & V_2 -> V_37 ) ) {
struct V_12 * V_13 = V_4 -> V_7 ;
T_2 V_38 ;
V_38 = ( V_10 == V_17 ) ? V_11
: V_27 ;
if ( V_13 -> V_14 . V_20 . V_10 != F_5 ( V_38 ) )
return false ;
if ( ! F_16 ( & V_13 -> V_14 . V_39 , & V_2 -> V_37 . V_40 ) )
return false ;
if ( F_3 ( V_13 -> V_14 . V_15 ) != V_4 -> V_16 )
return false ;
} else {
if ( V_6 -> V_20 . V_14 . V_10 != F_5 ( V_10 ) )
return false ;
}
F_2 ( & V_9 , V_6 ) ;
return F_4 ( V_2 , & V_9 , V_6 ) ;
}
static void
F_17 (
struct V_3 * V_4 ,
T_2 V_10 )
{
struct V_1 * V_2 = V_4 -> V_35 -> V_36 ;
if ( ( F_15 ( & V_2 -> V_37 ) &&
! F_18 ( V_4 -> V_7 , F_19 ( V_4 -> V_41 ) ,
V_42 ) ) ||
! F_14 ( V_4 , V_10 ) ) {
F_20 ( V_43 , V_44 , V_2 , V_4 -> V_7 ) ;
F_21 ( V_4 , V_45 ) ;
}
}
static void
F_22 (
struct V_3 * V_4 ,
T_2 V_10 )
{
struct V_1 * V_2 = V_4 -> V_35 -> V_36 ;
struct V_46 * V_47 = V_4 -> V_48 ;
struct V_12 * V_26 = V_4 -> V_7 ;
if ( ! F_14 ( V_4 , V_10 ) ) {
F_20 ( V_43 , V_44 , V_2 , V_4 -> V_7 ) ;
F_21 ( V_4 , V_45 ) ;
return;
}
if ( ! F_15 ( & V_2 -> V_37 ) )
return;
if ( V_47 )
V_26 -> V_14 . V_49 = F_23 ( V_47 -> V_50 . V_51 ) ;
F_24 ( V_4 -> V_7 , F_19 ( V_4 -> V_41 ) , V_42 ) ;
}
static void
F_25 (
struct V_3 * V_4 )
{
F_17 ( V_4 , V_17 ) ;
}
static void
F_26 (
struct V_3 * V_4 )
{
F_22 ( V_4 , V_17 ) ;
}
static void
F_27 (
struct V_3 * V_4 )
{
F_17 ( V_4 , V_21 ) ;
}
static void
F_28 (
struct V_3 * V_4 )
{
F_22 ( V_4 , V_21 ) ;
}
static int
F_29 (
struct V_52 * V_53 ,
struct V_54 * V_55 ,
T_3 V_56 ,
T_4 V_57 ,
struct V_3 * * V_58 )
{
int V_59 ;
V_59 = F_30 ( V_53 , V_55 , V_56 , V_57 , V_58 ,
V_60 , & V_61 ) ;
if ( ! V_59 && V_53 )
F_31 ( V_53 , * V_58 , V_62 ) ;
return V_59 ;
}
int
F_32 (
struct V_52 * V_53 ,
struct V_54 * V_55 ,
T_3 V_56 ,
T_4 V_57 ,
struct V_3 * * V_58 )
{
int V_59 ;
V_59 = F_30 ( V_53 , V_55 , V_56 , V_57 , V_58 ,
V_60 , & V_63 ) ;
if ( ! V_59 && V_53 )
F_31 ( V_53 , * V_58 , V_64 ) ;
return V_59 ;
}
static void
F_33 (
struct V_1 * V_2 ,
struct V_52 * V_53 ,
struct V_3 * V_4 ,
T_5 V_65 ,
T_2 type )
{
struct V_5 * V_6 = V_4 -> V_7 ;
ASSERT ( type == V_17 || type == V_21 ) ;
if ( F_15 ( & V_2 -> V_37 ) ) {
struct V_12 * V_13 = V_4 -> V_7 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_14 . V_20 . V_10 = ( type == V_17 )
? F_5 ( V_11 )
: F_5 ( V_27 ) ;
V_13 -> V_14 . V_15 = F_23 ( V_4 -> V_16 ) ;
V_13 -> V_14 . V_65 = F_23 ( V_65 ) ;
F_34 ( & V_13 -> V_14 . V_39 , & V_2 -> V_37 . V_40 ) ;
} else {
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_20 . V_14 . V_10 = F_5 ( type ) ;
}
if ( type == V_17 ) {
struct V_66 * V_30 ;
V_30 = F_11 ( V_2 , V_6 ) ;
V_30 -> V_67 = 0 ;
V_4 -> V_68 = & V_61 ;
F_31 ( V_53 , V_4 , V_62 ) ;
} else {
V_4 -> V_68 = & V_63 ;
F_31 ( V_53 , V_4 , V_64 ) ;
}
}
int
F_35 (
T_6 * args ,
T_7 V_69 ,
struct V_3 * * V_58 ,
T_2 V_10 )
{
struct V_54 * V_55 = args -> V_55 ;
struct V_52 * V_53 = args -> V_70 ;
struct V_1 * V_2 = V_55 -> V_71 ;
struct V_3 * V_4 ;
int error ;
ASSERT ( V_10 == V_17 || V_10 == V_21 ) ;
ASSERT ( V_69 >= F_36 ( V_2 ) &&
V_69 < F_37 ( V_2 ) ) ;
error = F_38 ( V_53 , V_55 , F_39 ( V_2 , V_69 ) , - 1 , & V_4 ,
V_60 ) ;
if ( error )
return error ;
F_33 ( V_2 , V_53 , V_4 , V_55 -> V_72 , V_10 ) ;
F_40 ( V_53 , V_4 ) ;
if ( V_10 == V_17 )
F_41 ( V_53 , V_4 ) ;
* V_58 = V_4 ;
return 0 ;
}
int
F_42 (
T_6 * args ,
struct V_3 * V_73 )
{
T_8 * V_74 ;
T_3 V_15 ;
T_9 * V_20 ;
T_10 * V_75 ;
T_11 * V_76 ;
T_12 * V_55 ;
int error ;
struct V_3 * V_77 ;
T_7 V_78 ;
T_13 * V_6 ;
T_1 * V_30 ;
T_14 * V_2 ;
int V_79 ;
int V_80 ;
T_15 * V_53 ;
struct V_81 * V_82 ;
struct V_28 * V_29 ;
struct V_8 V_9 ;
F_43 ( args ) ;
V_55 = args -> V_55 ;
V_2 = V_55 -> V_71 ;
V_53 = args -> V_70 ;
if ( ( error = F_44 ( args , & V_15 ) ) ) {
return error ;
}
V_78 = F_45 ( V_2 , V_15 ) ;
ASSERT ( V_78 == F_36 ( V_2 ) ) ;
error = F_35 ( args , V_78 , & V_77 , V_17 ) ;
if ( error )
return error ;
V_6 = V_77 -> V_7 ;
V_20 = V_73 -> V_7 ;
F_46 ( V_55 , V_73 ) ;
V_76 = F_47 ( V_2 , V_20 ) ;
V_75 = F_48 ( V_76 ) ;
V_82 = F_49 ( V_20 ) ;
V_29 = F_10 ( V_6 ) ;
F_2 ( & V_9 , V_6 ) ;
V_9 . V_24 = F_6 ( V_76 -> V_24 ) ;
V_9 . V_25 = F_6 ( V_76 -> V_25 ) ;
F_8 ( V_6 , & V_9 ) ;
F_40 ( V_53 , V_77 ) ;
memcpy ( V_29 , V_75 , F_6 ( V_76 -> V_24 ) * sizeof( T_10 ) ) ;
F_50 ( V_53 , V_77 , 0 , V_9 . V_24 - 1 ) ;
V_80 = 0 ;
V_79 = 1 ;
F_51 ( V_53 , V_73 ,
( V_83 ) ( ( char * ) V_75 - ( char * ) V_20 ) ,
( V_83 ) ( ( char * ) V_20 + V_2 -> V_84 -
( char * ) V_75 ) ,
& V_79 , & V_80 ) ;
V_73 -> V_68 = & V_85 ;
F_31 ( V_53 , V_73 , V_86 ) ;
if ( V_20 -> V_10 == F_9 ( V_87 ) )
V_20 -> V_10 = F_9 ( V_88 ) ;
else
V_20 -> V_10 = F_9 ( V_89 ) ;
if ( V_80 )
F_52 ( V_2 , V_20 , & V_79 ) ;
V_30 = F_11 ( V_2 , V_6 ) ;
V_30 -> V_67 = F_9 ( 1 ) ;
V_74 = F_13 ( V_30 ) ;
V_74 [ 0 ] = V_82 [ 0 ] . V_90 ;
if ( V_79 )
F_53 ( V_53 , V_73 ) ;
F_54 ( V_2 , V_77 ) ;
F_46 ( V_55 , V_73 ) ;
F_55 ( V_53 , V_77 , 0 , 0 ) ;
return 0 ;
}
STATIC void
F_56 (
struct V_8 * V_9 ,
struct V_28 * V_29 ,
int V_91 ,
int * V_92 ,
int * V_93 )
{
for ( * V_92 = V_91 - 1 ; * V_92 >= 0 ; -- * V_92 ) {
if ( V_29 [ * V_92 ] . V_33 ==
F_9 ( V_34 ) )
break;
}
for ( * V_93 = V_91 ; * V_93 < V_9 -> V_24 ; ++ * V_93 ) {
if ( V_29 [ * V_93 ] . V_33 ==
F_9 ( V_34 ) )
break;
if ( * V_92 >= 0 && V_91 - * V_92 <= * V_93 - V_91 )
break;
}
}
struct V_28 *
F_57 (
struct V_8 * V_9 ,
struct V_28 * V_29 ,
int V_91 ,
int V_94 ,
int V_92 ,
int V_93 ,
int * V_95 ,
int * V_96 )
{
if ( ! V_9 -> V_25 ) {
T_10 * V_97 ;
V_97 = & V_29 [ V_91 ] ;
if ( V_91 < V_9 -> V_24 )
memmove ( V_97 + 1 , V_97 ,
( V_9 -> V_24 - V_91 ) * sizeof( * V_97 ) ) ;
* V_95 = V_91 ;
* V_96 = V_9 -> V_24 ++ ;
return V_97 ;
}
if ( V_94 == 0 )
F_56 ( V_9 , V_29 , V_91 ,
& V_92 , & V_93 ) ;
if ( V_92 >= 0 &&
( V_93 == V_9 -> V_24 ||
V_91 - V_92 - 1 < V_93 - V_91 ) ) {
ASSERT ( V_91 - V_92 - 1 >= 0 ) ;
ASSERT ( V_29 [ V_92 ] . V_33 ==
F_9 ( V_34 ) ) ;
if ( V_91 - V_92 - 1 > 0 ) {
memmove ( & V_29 [ V_92 ] , & V_29 [ V_92 + 1 ] ,
( V_91 - V_92 - 1 ) *
sizeof( T_10 ) ) ;
}
* V_95 = F_58 ( V_92 , * V_95 ) ;
* V_96 = F_59 ( V_91 - 1 , * V_96 ) ;
V_9 -> V_25 -- ;
return & V_29 [ V_91 - 1 ] ;
}
ASSERT ( V_93 - V_91 >= 0 ) ;
ASSERT ( V_29 [ V_93 ] . V_33 == F_9 ( V_34 ) ) ;
if ( V_93 - V_91 > 0 ) {
memmove ( & V_29 [ V_91 + 1 ] , & V_29 [ V_91 ] ,
( V_93 - V_91 ) * sizeof( T_10 ) ) ;
}
* V_95 = F_58 ( V_91 , * V_95 ) ;
* V_96 = F_59 ( V_93 , * V_96 ) ;
V_9 -> V_25 -- ;
return & V_29 [ V_91 ] ;
}
int
F_60 (
T_6 * args )
{
T_8 * V_74 ;
int V_94 ;
T_9 * V_20 ;
struct V_3 * V_73 ;
T_16 * V_98 ;
T_12 * V_55 ;
T_17 * V_99 ;
int error ;
int V_100 ;
int V_93 ;
int V_31 ;
int V_91 ;
struct V_3 * V_77 ;
T_13 * V_6 ;
int V_90 ;
T_10 * V_97 ;
int V_95 ;
int V_96 ;
int V_92 ;
T_1 * V_30 ;
T_14 * V_2 ;
int V_101 ;
int V_79 ;
int V_80 ;
T_8 * V_102 ;
T_15 * V_53 ;
T_7 V_103 ;
struct V_81 * V_82 ;
struct V_28 * V_29 ;
struct V_8 V_9 ;
F_61 ( args ) ;
V_55 = args -> V_55 ;
V_53 = args -> V_70 ;
V_2 = V_55 -> V_71 ;
error = F_29 ( V_53 , V_55 , V_2 -> V_104 , - 1 , & V_77 ) ;
if ( error )
return error ;
V_91 = F_62 ( args , V_77 ) ;
V_6 = V_77 -> V_7 ;
V_30 = F_11 ( V_2 , V_6 ) ;
V_29 = F_10 ( V_6 ) ;
F_2 ( & V_9 , V_6 ) ;
V_74 = F_13 ( V_30 ) ;
V_90 = F_63 ( V_2 , args -> V_105 ) ;
for ( V_103 = - 1 , V_97 = & V_29 [ V_91 ] ;
V_91 < V_9 . V_24 && F_6 ( V_97 -> V_32 ) == args -> V_32 ;
V_91 ++ , V_97 ++ ) {
if ( F_6 ( V_97 -> V_33 ) == V_34 )
continue;
V_31 = F_64 ( V_2 , F_6 ( V_97 -> V_33 ) ) ;
ASSERT ( V_31 < F_6 ( V_30 -> V_67 ) ) ;
ASSERT ( V_74 [ V_31 ] != F_5 ( V_106 ) ) ;
if ( F_7 ( V_74 [ V_31 ] ) >= V_90 ) {
V_103 = V_31 ;
break;
}
}
if ( V_103 == - 1 ) {
for ( V_31 = 0 ; V_31 < F_6 ( V_30 -> V_67 ) ; V_31 ++ ) {
if ( V_74 [ V_31 ] == F_5 ( V_106 ) &&
V_103 == - 1 )
V_103 = V_31 ;
else if ( F_7 ( V_74 [ V_31 ] ) >= V_90 ) {
V_103 = V_31 ;
break;
}
}
}
V_101 = 0 ;
if ( ! V_9 . V_25 )
V_101 += sizeof( T_10 ) ;
if ( V_103 == - 1 )
V_101 += sizeof( V_107 ) ;
if ( V_103 != - 1 && V_74 [ V_103 ] == F_5 ( V_106 ) )
V_103 = - 1 ;
if ( ( char * ) V_74 - ( char * ) & V_29 [ V_9 . V_24 ] < V_101 &&
V_9 . V_25 > 1 )
V_94 = 1 ;
else if ( ( char * ) V_74 - ( char * ) & V_29 [ V_9 . V_24 ] < V_101 ) {
if ( ( args -> V_108 & V_109 ) ||
args -> V_110 == 0 ) {
F_65 ( V_53 , V_77 ) ;
return F_66 ( V_111 ) ;
}
error = F_67 ( args , V_77 ) ;
if ( error )
return error ;
return F_68 ( args ) ;
}
else
V_94 = 0 ;
if ( args -> V_108 & V_109 ) {
F_65 ( V_53 , V_77 ) ;
return V_103 == - 1 ? F_66 ( V_111 ) : 0 ;
}
if ( args -> V_110 == 0 && V_103 == - 1 ) {
F_65 ( V_53 , V_77 ) ;
return F_66 ( V_111 ) ;
}
if ( V_94 ) {
F_69 ( & V_9 , V_29 , & V_91 , & V_92 ,
& V_93 , & V_95 , & V_96 ) ;
}
else if ( V_9 . V_25 ) {
V_95 = V_9 . V_24 ;
V_96 = - 1 ;
}
if ( V_103 == - 1 ) {
if ( ( error = F_70 ( args , V_112 ,
& V_103 ) ) ) {
F_65 ( V_53 , V_77 ) ;
return error ;
}
if ( ( error = F_71 ( args , V_103 , & V_73 ) ) ) {
F_65 ( V_53 , V_77 ) ;
return error ;
}
if ( V_103 >= F_6 ( V_30 -> V_67 ) ) {
V_74 -- ;
memmove ( & V_74 [ 0 ] , & V_74 [ 1 ] ,
F_6 ( V_30 -> V_67 ) * sizeof( V_74 [ 0 ] ) ) ;
F_72 ( & V_30 -> V_67 , 1 ) ;
F_41 ( V_53 , V_77 ) ;
F_55 ( V_53 , V_77 , 0 , F_6 ( V_30 -> V_67 ) - 1 ) ;
}
else
F_55 ( V_53 , V_77 , V_103 , V_103 ) ;
V_20 = V_73 -> V_7 ;
V_82 = F_49 ( V_20 ) ;
V_74 [ V_103 ] = V_82 [ 0 ] . V_90 ;
V_100 = 1 ;
} else {
error = F_73 ( V_53 , V_55 ,
F_39 ( V_2 , V_103 ) ,
- 1 , & V_73 ) ;
if ( error ) {
F_65 ( V_53 , V_77 ) ;
return error ;
}
V_20 = V_73 -> V_7 ;
V_82 = F_49 ( V_20 ) ;
V_100 = 0 ;
}
V_99 = ( T_17 * )
( ( char * ) V_20 + F_7 ( V_82 [ 0 ] . V_113 ) ) ;
ASSERT ( F_7 ( V_99 -> V_90 ) >= V_90 ) ;
V_80 = V_79 = 0 ;
F_74 ( V_53 , V_73 , V_99 ,
( V_83 ) ( ( char * ) V_99 - ( char * ) V_20 ) , V_90 ,
& V_79 , & V_80 ) ;
V_98 = ( T_16 * ) V_99 ;
V_98 -> V_114 = F_23 ( args -> V_114 ) ;
V_98 -> V_105 = args -> V_105 ;
memcpy ( V_98 -> V_115 , args -> V_115 , V_98 -> V_105 ) ;
F_75 ( V_2 , V_98 , args -> V_116 ) ;
V_102 = F_76 ( V_2 , V_98 ) ;
* V_102 = F_5 ( ( char * ) V_98 - ( char * ) V_20 ) ;
if ( V_80 )
F_52 ( V_2 , V_20 , & V_79 ) ;
if ( V_79 )
F_53 ( V_53 , V_73 ) ;
F_77 ( V_53 , V_73 , V_98 ) ;
if ( F_7 ( V_74 [ V_103 ] ) != F_7 ( V_82 [ 0 ] . V_90 ) ) {
V_74 [ V_103 ] = V_82 [ 0 ] . V_90 ;
if ( ! V_100 )
F_55 ( V_53 , V_77 , V_103 , V_103 ) ;
}
V_97 = F_57 ( & V_9 , V_29 , V_91 , V_94 , V_92 ,
V_93 , & V_95 , & V_96 ) ;
V_97 -> V_32 = F_9 ( args -> V_32 ) ;
V_97 -> V_33 = F_9 ( F_78 ( V_2 , V_103 ,
F_7 ( * V_102 ) ) ) ;
F_8 ( V_6 , & V_9 ) ;
F_40 ( V_53 , V_77 ) ;
F_50 ( V_53 , V_77 , V_95 , V_96 ) ;
F_54 ( V_2 , V_77 ) ;
F_46 ( V_55 , V_73 ) ;
return 0 ;
}
void
F_79 (
T_6 * args ,
struct V_8 * V_9 ,
struct V_3 * V_4 )
{
int V_19 ;
T_13 * V_6 ;
int V_117 ;
int V_18 ;
struct V_28 * V_29 ;
V_6 = V_4 -> V_7 ;
if ( ! V_9 -> V_25 )
return;
V_29 = F_10 ( V_6 ) ;
for ( V_19 = V_18 = 0 , V_117 = - 1 ; V_19 < V_9 -> V_24 ; V_19 ++ ) {
if ( V_29 [ V_19 ] . V_33 == F_9 ( V_34 ) )
continue;
if ( V_19 > V_18 ) {
if ( V_117 == - 1 )
V_117 = V_18 ;
V_29 [ V_18 ] = V_29 [ V_19 ] ;
}
V_18 ++ ;
}
ASSERT ( V_9 -> V_25 == V_19 - V_18 ) ;
V_9 -> V_24 -= V_9 -> V_25 ;
V_9 -> V_25 = 0 ;
F_8 ( V_6 , V_9 ) ;
F_40 ( args -> V_70 , V_4 ) ;
if ( V_117 != - 1 )
F_50 ( args -> V_70 , V_4 , V_117 , V_18 - 1 ) ;
}
void
F_69 (
struct V_8 * V_9 ,
struct V_28 * V_29 ,
int * V_118 ,
int * V_119 ,
int * V_120 ,
int * V_121 ,
int * V_122 )
{
int V_19 ;
int V_93 ;
int V_91 ;
int V_123 ;
int V_92 ;
int V_124 = 0 ;
int V_18 ;
ASSERT ( V_9 -> V_25 > 1 ) ;
V_91 = * V_118 ;
F_56 ( V_9 , V_29 , V_91 , & V_92 , & V_93 ) ;
if ( V_92 >= 0 &&
( V_93 == V_9 -> V_24 ||
V_91 - V_92 <= V_93 - V_91 ) )
V_123 = V_92 ;
else
V_123 = V_93 ;
for ( V_19 = V_18 = 0 ; V_19 < V_9 -> V_24 ; V_19 ++ ) {
if ( V_91 == V_19 )
V_124 = V_18 ;
if ( V_19 != V_123 &&
V_29 [ V_19 ] . V_33 == F_9 ( V_34 ) ) {
if ( V_19 == V_18 )
* V_121 = V_18 ;
continue;
}
if ( V_19 == V_123 )
V_92 = V_93 = V_18 ;
if ( V_19 > V_18 )
V_29 [ V_18 ] = V_29 [ V_19 ] ;
V_18 ++ ;
}
ASSERT ( V_19 > V_18 ) ;
if ( V_91 == V_19 )
V_124 = V_18 ;
* V_118 = V_124 ;
V_9 -> V_24 -= V_19 - V_18 ;
V_9 -> V_25 = 1 ;
if ( V_92 >= V_124 )
V_92 = - 1 ;
else
V_93 = V_9 -> V_24 ;
* V_122 = V_9 -> V_24 - 1 ;
* V_119 = V_92 ;
* V_120 = V_93 ;
}
static void
F_55 (
T_15 * V_53 ,
struct V_3 * V_4 ,
int V_125 ,
int V_126 )
{
T_8 * V_127 ;
T_8 * V_128 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 * V_30 ;
ASSERT ( V_6 -> V_20 . V_14 . V_10 == F_5 ( V_17 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_11 ) ) ;
V_30 = F_11 ( V_53 -> V_129 , V_6 ) ;
V_127 = F_13 ( V_30 ) + V_125 ;
V_128 = F_13 ( V_30 ) + V_126 ;
F_80 ( V_53 , V_4 , ( V_130 ) ( ( char * ) V_127 - ( char * ) V_6 ) ,
( V_130 ) ( ( char * ) V_128 - ( char * ) V_6 + sizeof( * V_128 ) - 1 ) ) ;
}
void
F_50 (
T_15 * V_53 ,
struct V_3 * V_4 ,
int V_125 ,
int V_126 )
{
T_10 * V_131 ;
T_10 * V_132 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_28 * V_29 ;
ASSERT ( V_6 -> V_20 . V_14 . V_10 == F_5 ( V_17 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_11 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_21 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_27 ) ) ;
V_29 = F_10 ( V_6 ) ;
V_131 = & V_29 [ V_125 ] ;
V_132 = & V_29 [ V_126 ] ;
F_80 ( V_53 , V_4 , ( V_130 ) ( ( char * ) V_131 - ( char * ) V_6 ) ,
( V_130 ) ( ( char * ) V_132 - ( char * ) V_6 + sizeof( * V_132 ) - 1 ) ) ;
}
void
F_40 (
struct V_52 * V_53 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
ASSERT ( V_6 -> V_20 . V_14 . V_10 == F_5 ( V_17 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_11 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_21 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_27 ) ) ;
F_80 ( V_53 , V_4 , ( V_130 ) ( ( char * ) & V_6 -> V_20 - ( char * ) V_6 ) ,
F_81 ( V_6 ) - 1 ) ;
}
STATIC void
F_41 (
struct V_52 * V_53 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 * V_30 ;
struct V_1 * V_2 = V_53 -> V_129 ;
ASSERT ( V_6 -> V_20 . V_14 . V_10 == F_5 ( V_17 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_11 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_21 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_27 ) ) ;
V_30 = F_11 ( V_2 , V_6 ) ;
F_80 ( V_53 , V_4 , ( V_130 ) ( ( char * ) V_30 - ( char * ) V_6 ) ,
( V_130 ) ( V_2 -> V_84 - 1 ) ) ;
}
int
F_82 (
T_6 * args )
{
struct V_3 * V_73 ;
T_16 * V_98 ;
T_12 * V_55 ;
int error ;
int V_91 ;
struct V_3 * V_77 ;
T_13 * V_6 ;
T_10 * V_97 ;
T_15 * V_53 ;
struct V_28 * V_29 ;
F_83 ( args ) ;
if ( ( error = F_84 ( args , & V_77 , & V_91 , & V_73 ) ) ) {
return error ;
}
V_53 = args -> V_70 ;
V_55 = args -> V_55 ;
F_54 ( V_55 -> V_71 , V_77 ) ;
V_6 = V_77 -> V_7 ;
V_29 = F_10 ( V_6 ) ;
V_97 = & V_29 [ V_91 ] ;
V_98 = ( T_16 * )
( ( char * ) V_73 -> V_7 +
F_85 ( V_55 -> V_71 , F_6 ( V_97 -> V_33 ) ) ) ;
args -> V_114 = F_3 ( V_98 -> V_114 ) ;
args -> V_116 = F_86 ( V_55 -> V_71 , V_98 ) ;
error = F_87 ( args , V_98 -> V_115 , V_98 -> V_105 ) ;
F_65 ( V_53 , V_73 ) ;
F_65 ( V_53 , V_77 ) ;
return F_66 ( error ) ;
}
static int
F_84 (
T_6 * args ,
struct V_3 * * V_133 ,
int * V_118 ,
struct V_3 * * V_134 )
{
T_7 V_135 = - 1 ;
struct V_3 * V_73 = NULL ;
T_16 * V_98 ;
T_12 * V_55 ;
int error ;
int V_91 ;
struct V_3 * V_77 ;
T_10 * V_97 ;
T_13 * V_6 ;
T_14 * V_2 ;
T_7 V_136 ;
T_15 * V_53 ;
T_7 V_137 = - 1 ;
enum V_138 V_139 ;
struct V_28 * V_29 ;
struct V_8 V_9 ;
V_55 = args -> V_55 ;
V_53 = args -> V_70 ;
V_2 = V_55 -> V_71 ;
error = F_29 ( V_53 , V_55 , V_2 -> V_104 , - 1 , & V_77 ) ;
if ( error )
return error ;
* V_133 = V_77 ;
V_6 = V_77 -> V_7 ;
F_54 ( V_2 , V_77 ) ;
V_29 = F_10 ( V_6 ) ;
F_2 ( & V_9 , V_6 ) ;
V_91 = F_62 ( args , V_77 ) ;
for ( V_97 = & V_29 [ V_91 ] ;
V_91 < V_9 . V_24 && F_6 ( V_97 -> V_32 ) == args -> V_32 ;
V_97 ++ , V_91 ++ ) {
if ( F_6 ( V_97 -> V_33 ) == V_34 )
continue;
V_136 = F_64 ( V_2 , F_6 ( V_97 -> V_33 ) ) ;
if ( V_136 != V_135 ) {
if ( V_73 )
F_65 ( V_53 , V_73 ) ;
error = F_73 ( V_53 , V_55 ,
F_39 ( V_2 , V_136 ) ,
- 1 , & V_73 ) ;
if ( error ) {
F_65 ( V_53 , V_77 ) ;
return error ;
}
V_135 = V_136 ;
}
V_98 = ( T_16 * ) ( ( char * ) V_73 -> V_7 +
F_85 ( V_2 , F_6 ( V_97 -> V_33 ) ) ) ;
V_139 = V_2 -> V_140 -> V_141 ( args , V_98 -> V_115 , V_98 -> V_105 ) ;
if ( V_139 != V_142 && V_139 != args -> V_143 ) {
args -> V_143 = V_139 ;
* V_118 = V_91 ;
if ( V_139 == V_144 ) {
* V_134 = V_73 ;
return 0 ;
}
V_137 = V_135 ;
}
}
ASSERT ( args -> V_108 & V_145 ) ;
if ( args -> V_143 == V_146 ) {
ASSERT ( V_137 != - 1 ) ;
if ( V_137 != V_135 ) {
F_65 ( V_53 , V_73 ) ;
error = F_73 ( V_53 , V_55 ,
F_39 ( V_2 , V_137 ) ,
- 1 , & V_73 ) ;
if ( error ) {
F_65 ( V_53 , V_77 ) ;
return error ;
}
}
* V_134 = V_73 ;
return 0 ;
}
ASSERT ( V_137 == - 1 ) ;
if ( V_73 )
F_65 ( V_53 , V_73 ) ;
F_65 ( V_53 , V_77 ) ;
return F_66 ( V_147 ) ;
}
int
F_88 (
T_6 * args )
{
T_8 * V_74 ;
T_9 * V_20 ;
T_7 V_148 ;
struct V_3 * V_73 ;
T_16 * V_98 ;
T_12 * V_55 ;
int error ;
T_7 V_31 ;
int V_91 ;
struct V_3 * V_77 ;
T_13 * V_6 ;
T_10 * V_97 ;
T_1 * V_30 ;
T_14 * V_2 ;
int V_79 ;
int V_80 ;
V_107 V_149 ;
T_15 * V_53 ;
struct V_81 * V_82 ;
struct V_28 * V_29 ;
struct V_8 V_9 ;
F_89 ( args ) ;
if ( ( error = F_84 ( args , & V_77 , & V_91 , & V_73 ) ) ) {
return error ;
}
V_55 = args -> V_55 ;
V_53 = args -> V_70 ;
V_2 = V_55 -> V_71 ;
V_6 = V_77 -> V_7 ;
V_20 = V_73 -> V_7 ;
F_46 ( V_55 , V_73 ) ;
V_82 = F_49 ( V_20 ) ;
F_2 ( & V_9 , V_6 ) ;
V_29 = F_10 ( V_6 ) ;
V_97 = & V_29 [ V_91 ] ;
V_148 = F_64 ( V_2 , F_6 ( V_97 -> V_33 ) ) ;
V_98 = ( T_16 * )
( ( char * ) V_20 + F_85 ( V_2 , F_6 ( V_97 -> V_33 ) ) ) ;
V_80 = V_79 = 0 ;
V_149 = F_7 ( V_82 [ 0 ] . V_90 ) ;
V_30 = F_11 ( V_2 , V_6 ) ;
V_74 = F_13 ( V_30 ) ;
ASSERT ( F_7 ( V_74 [ V_148 ] ) == V_149 ) ;
F_51 ( V_53 , V_73 ,
( V_83 ) ( ( char * ) V_98 - ( char * ) V_20 ) ,
F_63 ( V_2 , V_98 -> V_105 ) , & V_79 , & V_80 ) ;
V_9 . V_25 ++ ;
F_8 ( V_6 , & V_9 ) ;
F_40 ( V_53 , V_77 ) ;
V_97 -> V_33 = F_9 ( V_34 ) ;
F_50 ( V_53 , V_77 , V_91 , V_91 ) ;
if ( V_80 )
F_52 ( V_2 , V_20 , & V_79 ) ;
if ( V_79 )
F_53 ( V_53 , V_73 ) ;
if ( F_7 ( V_82 [ 0 ] . V_90 ) != V_149 ) {
V_74 [ V_148 ] = V_82 [ 0 ] . V_90 ;
F_55 ( V_53 , V_77 , V_148 , V_148 ) ;
}
F_46 ( V_55 , V_73 ) ;
if ( F_7 ( V_82 [ 0 ] . V_90 ) ==
V_2 -> V_84 - F_90 ( V_20 ) ) {
ASSERT ( V_148 != V_2 -> V_150 ) ;
if ( ( error = F_91 ( args , V_148 , V_73 ) ) ) {
if ( error == V_111 && args -> V_110 == 0 )
error = 0 ;
F_54 ( V_2 , V_77 ) ;
return error ;
}
V_73 = NULL ;
if ( V_148 == F_6 ( V_30 -> V_67 ) - 1 ) {
for ( V_31 = V_148 - 1 ; V_31 > 0 ; V_31 -- ) {
if ( V_74 [ V_31 ] != F_5 ( V_106 ) )
break;
}
memmove ( & V_74 [ V_148 - V_31 ] , V_74 ,
( F_6 ( V_30 -> V_67 ) - ( V_148 - V_31 ) ) * sizeof( * V_74 ) ) ;
F_72 ( & V_30 -> V_67 , - ( V_148 - V_31 ) ) ;
F_41 ( V_53 , V_77 ) ;
F_55 ( V_53 , V_77 , 0 , F_6 ( V_30 -> V_67 ) - 1 ) ;
} else
V_74 [ V_148 ] = F_5 ( V_106 ) ;
}
else if ( V_148 != V_2 -> V_150 )
V_73 = NULL ;
F_54 ( V_2 , V_77 ) ;
return F_92 ( args , V_77 , V_73 ) ;
}
int
F_93 (
T_6 * args )
{
struct V_3 * V_73 ;
T_16 * V_98 ;
T_12 * V_55 ;
int error ;
int V_91 ;
struct V_3 * V_77 ;
T_13 * V_6 ;
T_10 * V_97 ;
T_15 * V_53 ;
struct V_28 * V_29 ;
F_94 ( args ) ;
if ( ( error = F_84 ( args , & V_77 , & V_91 , & V_73 ) ) ) {
return error ;
}
V_55 = args -> V_55 ;
V_6 = V_77 -> V_7 ;
V_29 = F_10 ( V_6 ) ;
V_97 = & V_29 [ V_91 ] ;
V_98 = ( T_16 * )
( ( char * ) V_73 -> V_7 +
F_85 ( V_55 -> V_71 , F_6 ( V_97 -> V_33 ) ) ) ;
ASSERT ( args -> V_114 != F_3 ( V_98 -> V_114 ) ) ;
V_98 -> V_114 = F_23 ( args -> V_114 ) ;
F_75 ( V_55 -> V_71 , V_98 , args -> V_116 ) ;
V_53 = args -> V_70 ;
F_77 ( V_53 , V_73 , V_98 ) ;
F_54 ( V_55 -> V_71 , V_77 ) ;
F_65 ( V_53 , V_77 ) ;
return 0 ;
}
int
F_62 (
T_6 * args ,
struct V_3 * V_77 )
{
T_18 V_151 = 0 ;
T_18 V_152 ;
int V_153 ;
int V_154 ;
T_13 * V_6 ;
T_10 * V_97 ;
int V_155 = 0 ;
struct V_28 * V_29 ;
struct V_8 V_9 ;
V_6 = V_77 -> V_7 ;
V_29 = F_10 ( V_6 ) ;
F_2 ( & V_9 , V_6 ) ;
for ( V_97 = V_29 , V_154 = 0 , V_153 = V_9 . V_24 - 1 ,
V_152 = args -> V_32 ;
V_154 <= V_153 ; ) {
V_155 = ( V_154 + V_153 ) >> 1 ;
if ( ( V_151 = F_6 ( V_97 [ V_155 ] . V_32 ) ) == V_152 )
break;
if ( V_151 < V_152 )
V_154 = V_155 + 1 ;
else
V_153 = V_155 - 1 ;
}
if ( V_151 == V_152 ) {
while ( V_155 > 0 && F_6 ( V_97 [ V_155 - 1 ] . V_32 ) == V_152 ) {
V_155 -- ;
}
}
else if ( V_151 < V_152 )
V_155 ++ ;
return V_155 ;
}
int
F_95 (
T_6 * args ,
struct V_3 * V_77 ,
T_7 V_148 )
{
T_8 * V_74 ;
struct V_3 * V_73 ;
T_12 * V_55 ;
int error ;
T_13 * V_6 ;
T_1 * V_30 ;
T_14 * V_2 ;
T_15 * V_53 ;
V_55 = args -> V_55 ;
V_2 = V_55 -> V_71 ;
V_53 = args -> V_70 ;
error = F_73 ( V_53 , V_55 , F_39 ( V_2 , V_148 ) , - 1 , & V_73 ) ;
if ( error )
return error ;
V_6 = V_77 -> V_7 ;
V_30 = F_11 ( V_2 , V_6 ) ;
#ifdef F_96
{
struct V_156 * V_20 = V_73 -> V_7 ;
struct V_81 * V_82 = F_49 ( V_20 ) ;
ASSERT ( V_20 -> V_10 == F_9 ( V_88 ) ||
V_20 -> V_10 == F_9 ( V_89 ) ) ;
ASSERT ( F_7 ( V_82 [ 0 ] . V_90 ) ==
V_2 -> V_84 - F_90 ( V_20 ) ) ;
ASSERT ( V_148 == F_6 ( V_30 -> V_67 ) - 1 ) ;
}
#endif
if ( ( error = F_91 ( args , V_148 , V_73 ) ) ) {
ASSERT ( error != V_111 ) ;
F_65 ( V_53 , V_73 ) ;
return error ;
}
V_74 = F_13 ( V_30 ) ;
F_72 ( & V_30 -> V_67 , - 1 ) ;
memmove ( & V_74 [ 1 ] , & V_74 [ 0 ] , F_6 ( V_30 -> V_67 ) * sizeof( * V_74 ) ) ;
F_41 ( V_53 , V_77 ) ;
F_55 ( V_53 , V_77 , 0 , F_6 ( V_30 -> V_67 ) - 1 ) ;
return 0 ;
}
static inline T_19
F_97 (
struct V_8 * V_20 ,
int V_157 )
{
int V_158 ;
int V_159 ;
V_158 = V_20 -> V_24 - V_20 -> V_25 ;
if ( V_20 -> V_10 == V_17 ||
V_20 -> V_10 == V_21 )
V_159 = sizeof( struct V_160 ) ;
else
V_159 = sizeof( struct V_12 ) ;
return V_159 + V_158 * sizeof( T_10 )
+ V_157 * sizeof( V_107 )
+ sizeof( T_1 ) ;
}
int
F_98 (
T_20 * V_161 )
{
T_6 * args ;
T_12 * V_55 ;
int error ;
struct V_3 * V_162 ;
T_21 V_163 ;
T_22 * free ;
struct V_3 * V_77 ;
T_1 * V_30 ;
T_13 * V_6 ;
T_14 * V_2 ;
int V_164 ;
T_15 * V_53 ;
struct V_8 V_9 ;
struct V_165 V_166 ;
if ( V_161 -> V_167 . V_168 > 1 )
return 0 ;
args = V_161 -> args ;
F_99 ( args ) ;
V_2 = V_161 -> V_2 ;
V_55 = args -> V_55 ;
V_53 = args -> V_70 ;
if ( ( error = F_100 ( V_53 , V_55 , & V_163 , V_60 ) ) ) {
return error ;
}
V_163 -= V_2 -> V_169 ;
while ( V_163 > V_2 -> V_170 ) {
if ( ( error = F_101 ( args , V_163 , & V_164 ) ) ) {
return error ;
}
if ( V_164 )
V_163 -= V_2 -> V_169 ;
else
return 0 ;
}
if ( ( error = F_102 ( V_53 , V_55 , & V_163 , V_60 ) ) ) {
return error ;
}
if ( F_103 ( V_2 , V_163 ) > V_171 + V_2 -> V_84 )
return 0 ;
V_77 = V_161 -> V_167 . V_172 [ 0 ] . V_4 ;
V_6 = V_77 -> V_7 ;
F_2 ( & V_9 , V_6 ) ;
ASSERT ( V_9 . V_10 == V_21 ||
V_9 . V_10 == V_27 ) ;
error = F_104 ( V_53 , V_55 , V_2 -> V_170 , & V_162 ) ;
if ( error )
return error ;
free = V_162 -> V_7 ;
F_105 ( & V_166 , free ) ;
ASSERT ( ! V_166 . V_173 ) ;
if ( F_97 ( & V_9 , V_166 . V_174 ) > V_2 -> V_84 ) {
F_65 ( V_53 , V_162 ) ;
return 0 ;
}
if ( V_9 . V_25 )
F_79 ( args , & V_9 , V_77 ) ;
V_77 -> V_68 = & V_61 ;
F_31 ( V_53 , V_77 , V_62 ) ;
V_9 . V_10 = ( V_9 . V_10 == V_21 )
? V_17
: V_11 ;
V_30 = F_11 ( V_2 , V_6 ) ;
V_30 -> V_67 = F_9 ( V_166 . V_174 ) ;
memcpy ( F_13 ( V_30 ) , F_106 ( V_2 , free ) ,
V_166 . V_174 * sizeof( V_107 ) ) ;
F_8 ( V_6 , & V_9 ) ;
F_40 ( V_53 , V_77 ) ;
F_55 ( V_53 , V_77 , 0 , F_6 ( V_30 -> V_67 ) - 1 ) ;
F_41 ( V_53 , V_77 ) ;
F_54 ( V_2 , V_77 ) ;
error = F_91 ( args , F_37 ( V_2 ) , V_162 ) ;
if ( error ) {
ASSERT ( error != V_111 ) ;
return error ;
}
V_162 = NULL ;
error = F_92 ( args , V_77 , NULL ) ;
V_161 -> V_167 . V_172 [ 0 ] . V_4 = NULL ;
return error ;
}
