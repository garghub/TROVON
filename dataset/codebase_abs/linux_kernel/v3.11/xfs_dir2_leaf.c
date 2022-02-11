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
F_2 ( & V_9 , V_6 ) ;
if ( F_15 ( & V_2 -> V_37 ) ) {
struct V_12 * V_13 = V_4 -> V_7 ;
if ( ( V_10 == V_17 &&
V_9 . V_10 != V_11 ) ||
( V_10 == V_21 &&
V_9 . V_10 != V_27 ) )
return false ;
if ( ! F_16 ( & V_13 -> V_14 . V_38 , & V_2 -> V_37 . V_39 ) )
return false ;
if ( F_3 ( V_13 -> V_14 . V_15 ) != V_4 -> V_16 )
return false ;
} else {
if ( V_9 . V_10 != V_10 )
return false ;
}
return F_4 ( V_2 , & V_9 , V_6 ) ;
}
static void
F_17 (
struct V_3 * V_4 ,
T_2 V_10 )
{
struct V_1 * V_2 = V_4 -> V_35 -> V_36 ;
if ( ( F_15 ( & V_2 -> V_37 ) &&
! F_18 ( V_4 -> V_7 , F_19 ( V_4 -> V_40 ) ,
V_41 ) ) ||
! F_14 ( V_4 , V_10 ) ) {
F_20 ( V_42 , V_43 , V_2 , V_4 -> V_7 ) ;
F_21 ( V_4 , V_44 ) ;
}
}
static void
F_22 (
struct V_3 * V_4 ,
T_2 V_10 )
{
struct V_1 * V_2 = V_4 -> V_35 -> V_36 ;
struct V_45 * V_46 = V_4 -> V_47 ;
struct V_12 * V_26 = V_4 -> V_7 ;
if ( ! F_14 ( V_4 , V_10 ) ) {
F_20 ( V_42 , V_43 , V_2 , V_4 -> V_7 ) ;
F_21 ( V_4 , V_44 ) ;
return;
}
if ( ! F_15 ( & V_2 -> V_37 ) )
return;
if ( V_46 )
V_26 -> V_14 . V_48 = F_23 ( V_46 -> V_49 . V_50 ) ;
F_24 ( V_4 -> V_7 , F_19 ( V_4 -> V_40 ) , V_41 ) ;
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
struct V_51 * V_52 ,
struct V_53 * V_54 ,
T_3 V_55 ,
T_4 V_56 ,
struct V_3 * * V_57 )
{
int V_58 ;
V_58 = F_30 ( V_52 , V_54 , V_55 , V_56 , V_57 ,
V_59 , & V_60 ) ;
if ( ! V_58 && V_52 )
F_31 ( V_52 , * V_57 , V_61 ) ;
return V_58 ;
}
int
F_32 (
struct V_51 * V_52 ,
struct V_53 * V_54 ,
T_3 V_55 ,
T_4 V_56 ,
struct V_3 * * V_57 )
{
int V_58 ;
V_58 = F_30 ( V_52 , V_54 , V_55 , V_56 , V_57 ,
V_59 , & V_62 ) ;
if ( ! V_58 && V_52 )
F_31 ( V_52 , * V_57 , V_63 ) ;
return V_58 ;
}
static void
F_33 (
struct V_1 * V_2 ,
struct V_51 * V_52 ,
struct V_3 * V_4 ,
T_5 V_64 ,
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
V_13 -> V_14 . V_64 = F_23 ( V_64 ) ;
F_34 ( & V_13 -> V_14 . V_38 , & V_2 -> V_37 . V_39 ) ;
} else {
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_20 . V_14 . V_10 = F_5 ( type ) ;
}
if ( type == V_17 ) {
struct V_65 * V_30 ;
V_30 = F_11 ( V_2 , V_6 ) ;
V_30 -> V_66 = 0 ;
V_4 -> V_67 = & V_60 ;
F_31 ( V_52 , V_4 , V_61 ) ;
} else {
V_4 -> V_67 = & V_62 ;
F_31 ( V_52 , V_4 , V_63 ) ;
}
}
int
F_35 (
T_6 * args ,
T_7 V_68 ,
struct V_3 * * V_57 ,
T_2 V_10 )
{
struct V_53 * V_54 = args -> V_54 ;
struct V_51 * V_52 = args -> V_69 ;
struct V_1 * V_2 = V_54 -> V_70 ;
struct V_3 * V_4 ;
int error ;
ASSERT ( V_10 == V_17 || V_10 == V_21 ) ;
ASSERT ( V_68 >= F_36 ( V_2 ) &&
V_68 < F_37 ( V_2 ) ) ;
error = F_38 ( V_52 , V_54 , F_39 ( V_2 , V_68 ) , - 1 , & V_4 ,
V_59 ) ;
if ( error )
return error ;
F_33 ( V_2 , V_52 , V_4 , V_54 -> V_71 , V_10 ) ;
F_40 ( V_52 , V_4 ) ;
if ( V_10 == V_17 )
F_41 ( V_52 , V_4 ) ;
* V_57 = V_4 ;
return 0 ;
}
int
F_42 (
T_6 * args ,
struct V_3 * V_72 )
{
T_8 * V_73 ;
T_3 V_15 ;
T_9 * V_20 ;
T_10 * V_74 ;
T_11 * V_75 ;
T_12 * V_54 ;
int error ;
struct V_3 * V_76 ;
T_7 V_77 ;
T_13 * V_6 ;
T_1 * V_30 ;
T_14 * V_2 ;
int V_78 ;
int V_79 ;
T_15 * V_52 ;
struct V_80 * V_81 ;
struct V_28 * V_29 ;
struct V_8 V_9 ;
F_43 ( args ) ;
V_54 = args -> V_54 ;
V_2 = V_54 -> V_70 ;
V_52 = args -> V_69 ;
if ( ( error = F_44 ( args , & V_15 ) ) ) {
return error ;
}
V_77 = F_45 ( V_2 , V_15 ) ;
ASSERT ( V_77 == F_36 ( V_2 ) ) ;
error = F_35 ( args , V_77 , & V_76 , V_17 ) ;
if ( error )
return error ;
V_6 = V_76 -> V_7 ;
V_20 = V_72 -> V_7 ;
F_46 ( V_54 , V_72 ) ;
V_75 = F_47 ( V_2 , V_20 ) ;
V_74 = F_48 ( V_75 ) ;
V_81 = F_49 ( V_20 ) ;
V_29 = F_10 ( V_6 ) ;
F_2 ( & V_9 , V_6 ) ;
V_9 . V_24 = F_6 ( V_75 -> V_24 ) ;
V_9 . V_25 = F_6 ( V_75 -> V_25 ) ;
F_8 ( V_6 , & V_9 ) ;
F_40 ( V_52 , V_76 ) ;
memcpy ( V_29 , V_74 , F_6 ( V_75 -> V_24 ) * sizeof( T_10 ) ) ;
F_50 ( V_52 , V_76 , 0 , V_9 . V_24 - 1 ) ;
V_79 = 0 ;
V_78 = 1 ;
F_51 ( V_52 , V_72 ,
( V_82 ) ( ( char * ) V_74 - ( char * ) V_20 ) ,
( V_82 ) ( ( char * ) V_20 + V_2 -> V_83 -
( char * ) V_74 ) ,
& V_78 , & V_79 ) ;
V_72 -> V_67 = & V_84 ;
F_31 ( V_52 , V_72 , V_85 ) ;
if ( V_20 -> V_10 == F_9 ( V_86 ) )
V_20 -> V_10 = F_9 ( V_87 ) ;
else
V_20 -> V_10 = F_9 ( V_88 ) ;
if ( V_79 )
F_52 ( V_2 , V_20 , & V_78 ) ;
V_30 = F_11 ( V_2 , V_6 ) ;
V_30 -> V_66 = F_9 ( 1 ) ;
V_73 = F_13 ( V_30 ) ;
V_73 [ 0 ] = V_81 [ 0 ] . V_89 ;
if ( V_78 )
F_53 ( V_52 , V_72 ) ;
F_54 ( V_2 , V_76 ) ;
F_46 ( V_54 , V_72 ) ;
F_55 ( V_52 , V_76 , 0 , 0 ) ;
return 0 ;
}
STATIC void
F_56 (
struct V_8 * V_9 ,
struct V_28 * V_29 ,
int V_90 ,
int * V_91 ,
int * V_92 )
{
for ( * V_91 = V_90 - 1 ; * V_91 >= 0 ; -- * V_91 ) {
if ( V_29 [ * V_91 ] . V_33 ==
F_9 ( V_34 ) )
break;
}
for ( * V_92 = V_90 ; * V_92 < V_9 -> V_24 ; ++ * V_92 ) {
if ( V_29 [ * V_92 ] . V_33 ==
F_9 ( V_34 ) )
break;
if ( * V_91 >= 0 && V_90 - * V_91 <= * V_92 - V_90 )
break;
}
}
struct V_28 *
F_57 (
struct V_8 * V_9 ,
struct V_28 * V_29 ,
int V_90 ,
int V_93 ,
int V_91 ,
int V_92 ,
int * V_94 ,
int * V_95 )
{
if ( ! V_9 -> V_25 ) {
T_10 * V_96 ;
V_96 = & V_29 [ V_90 ] ;
if ( V_90 < V_9 -> V_24 )
memmove ( V_96 + 1 , V_96 ,
( V_9 -> V_24 - V_90 ) * sizeof( * V_96 ) ) ;
* V_94 = V_90 ;
* V_95 = V_9 -> V_24 ++ ;
return V_96 ;
}
if ( V_93 == 0 )
F_56 ( V_9 , V_29 , V_90 ,
& V_91 , & V_92 ) ;
if ( V_91 >= 0 &&
( V_92 == V_9 -> V_24 ||
V_90 - V_91 - 1 < V_92 - V_90 ) ) {
ASSERT ( V_90 - V_91 - 1 >= 0 ) ;
ASSERT ( V_29 [ V_91 ] . V_33 ==
F_9 ( V_34 ) ) ;
if ( V_90 - V_91 - 1 > 0 ) {
memmove ( & V_29 [ V_91 ] , & V_29 [ V_91 + 1 ] ,
( V_90 - V_91 - 1 ) *
sizeof( T_10 ) ) ;
}
* V_94 = F_58 ( V_91 , * V_94 ) ;
* V_95 = F_59 ( V_90 - 1 , * V_95 ) ;
V_9 -> V_25 -- ;
return & V_29 [ V_90 - 1 ] ;
}
ASSERT ( V_92 - V_90 >= 0 ) ;
ASSERT ( V_29 [ V_92 ] . V_33 == F_9 ( V_34 ) ) ;
if ( V_92 - V_90 > 0 ) {
memmove ( & V_29 [ V_90 + 1 ] , & V_29 [ V_90 ] ,
( V_92 - V_90 ) * sizeof( T_10 ) ) ;
}
* V_94 = F_58 ( V_90 , * V_94 ) ;
* V_95 = F_59 ( V_92 , * V_95 ) ;
V_9 -> V_25 -- ;
return & V_29 [ V_90 ] ;
}
int
F_60 (
T_6 * args )
{
T_8 * V_73 ;
int V_93 ;
T_9 * V_20 ;
struct V_3 * V_72 ;
T_16 * V_97 ;
T_12 * V_54 ;
T_17 * V_98 ;
int error ;
int V_99 ;
int V_92 ;
int V_31 ;
int V_90 ;
struct V_3 * V_76 ;
T_13 * V_6 ;
int V_89 ;
T_10 * V_96 ;
int V_94 ;
int V_95 ;
int V_91 ;
T_1 * V_30 ;
T_14 * V_2 ;
int V_100 ;
int V_78 ;
int V_79 ;
T_8 * V_101 ;
T_15 * V_52 ;
T_7 V_102 ;
struct V_80 * V_81 ;
struct V_28 * V_29 ;
struct V_8 V_9 ;
F_61 ( args ) ;
V_54 = args -> V_54 ;
V_52 = args -> V_69 ;
V_2 = V_54 -> V_70 ;
error = F_29 ( V_52 , V_54 , V_2 -> V_103 , - 1 , & V_76 ) ;
if ( error )
return error ;
V_90 = F_62 ( args , V_76 ) ;
V_6 = V_76 -> V_7 ;
V_30 = F_11 ( V_2 , V_6 ) ;
V_29 = F_10 ( V_6 ) ;
F_2 ( & V_9 , V_6 ) ;
V_73 = F_13 ( V_30 ) ;
V_89 = F_63 ( args -> V_104 ) ;
for ( V_102 = - 1 , V_96 = & V_29 [ V_90 ] ;
V_90 < V_9 . V_24 && F_6 ( V_96 -> V_32 ) == args -> V_32 ;
V_90 ++ , V_96 ++ ) {
if ( F_6 ( V_96 -> V_33 ) == V_34 )
continue;
V_31 = F_64 ( V_2 , F_6 ( V_96 -> V_33 ) ) ;
ASSERT ( V_31 < F_6 ( V_30 -> V_66 ) ) ;
ASSERT ( V_73 [ V_31 ] != F_5 ( V_105 ) ) ;
if ( F_7 ( V_73 [ V_31 ] ) >= V_89 ) {
V_102 = V_31 ;
break;
}
}
if ( V_102 == - 1 ) {
for ( V_31 = 0 ; V_31 < F_6 ( V_30 -> V_66 ) ; V_31 ++ ) {
if ( V_73 [ V_31 ] == F_5 ( V_105 ) &&
V_102 == - 1 )
V_102 = V_31 ;
else if ( F_7 ( V_73 [ V_31 ] ) >= V_89 ) {
V_102 = V_31 ;
break;
}
}
}
V_100 = 0 ;
if ( ! V_9 . V_25 )
V_100 += sizeof( T_10 ) ;
if ( V_102 == - 1 )
V_100 += sizeof( V_106 ) ;
if ( V_102 != - 1 && V_73 [ V_102 ] == F_5 ( V_105 ) )
V_102 = - 1 ;
if ( ( char * ) V_73 - ( char * ) & V_29 [ V_9 . V_24 ] < V_100 &&
V_9 . V_25 > 1 )
V_93 = 1 ;
else if ( ( char * ) V_73 - ( char * ) & V_29 [ V_9 . V_24 ] < V_100 ) {
if ( ( args -> V_107 & V_108 ) ||
args -> V_109 == 0 ) {
F_65 ( V_52 , V_76 ) ;
return F_66 ( V_110 ) ;
}
error = F_67 ( args , V_76 ) ;
if ( error )
return error ;
return F_68 ( args ) ;
}
else
V_93 = 0 ;
if ( args -> V_107 & V_108 ) {
F_65 ( V_52 , V_76 ) ;
return V_102 == - 1 ? F_66 ( V_110 ) : 0 ;
}
if ( args -> V_109 == 0 && V_102 == - 1 ) {
F_65 ( V_52 , V_76 ) ;
return F_66 ( V_110 ) ;
}
if ( V_93 ) {
F_69 ( & V_9 , V_29 , & V_90 , & V_91 ,
& V_92 , & V_94 , & V_95 ) ;
}
else if ( V_9 . V_25 ) {
V_94 = V_9 . V_24 ;
V_95 = - 1 ;
}
if ( V_102 == - 1 ) {
if ( ( error = F_70 ( args , V_111 ,
& V_102 ) ) ) {
F_65 ( V_52 , V_76 ) ;
return error ;
}
if ( ( error = F_71 ( args , V_102 , & V_72 ) ) ) {
F_65 ( V_52 , V_76 ) ;
return error ;
}
if ( V_102 >= F_6 ( V_30 -> V_66 ) ) {
V_73 -- ;
memmove ( & V_73 [ 0 ] , & V_73 [ 1 ] ,
F_6 ( V_30 -> V_66 ) * sizeof( V_73 [ 0 ] ) ) ;
F_72 ( & V_30 -> V_66 , 1 ) ;
F_41 ( V_52 , V_76 ) ;
F_55 ( V_52 , V_76 , 0 , F_6 ( V_30 -> V_66 ) - 1 ) ;
}
else
F_55 ( V_52 , V_76 , V_102 , V_102 ) ;
V_20 = V_72 -> V_7 ;
V_81 = F_49 ( V_20 ) ;
V_73 [ V_102 ] = V_81 [ 0 ] . V_89 ;
V_99 = 1 ;
} else {
error = F_73 ( V_52 , V_54 ,
F_39 ( V_2 , V_102 ) ,
- 1 , & V_72 ) ;
if ( error ) {
F_65 ( V_52 , V_76 ) ;
return error ;
}
V_20 = V_72 -> V_7 ;
V_81 = F_49 ( V_20 ) ;
V_99 = 0 ;
}
V_98 = ( T_17 * )
( ( char * ) V_20 + F_7 ( V_81 [ 0 ] . V_112 ) ) ;
ASSERT ( F_7 ( V_98 -> V_89 ) >= V_89 ) ;
V_79 = V_78 = 0 ;
F_74 ( V_52 , V_72 , V_98 ,
( V_82 ) ( ( char * ) V_98 - ( char * ) V_20 ) , V_89 ,
& V_78 , & V_79 ) ;
V_97 = ( T_16 * ) V_98 ;
V_97 -> V_113 = F_23 ( args -> V_113 ) ;
V_97 -> V_104 = args -> V_104 ;
memcpy ( V_97 -> V_114 , args -> V_114 , V_97 -> V_104 ) ;
V_101 = F_75 ( V_97 ) ;
* V_101 = F_5 ( ( char * ) V_97 - ( char * ) V_20 ) ;
if ( V_79 )
F_52 ( V_2 , V_20 , & V_78 ) ;
if ( V_78 )
F_53 ( V_52 , V_72 ) ;
F_76 ( V_52 , V_72 , V_97 ) ;
if ( F_7 ( V_73 [ V_102 ] ) != F_7 ( V_81 [ 0 ] . V_89 ) ) {
V_73 [ V_102 ] = V_81 [ 0 ] . V_89 ;
if ( ! V_99 )
F_55 ( V_52 , V_76 , V_102 , V_102 ) ;
}
V_96 = F_57 ( & V_9 , V_29 , V_90 , V_93 , V_91 ,
V_92 , & V_94 , & V_95 ) ;
V_96 -> V_32 = F_9 ( args -> V_32 ) ;
V_96 -> V_33 = F_9 ( F_77 ( V_2 , V_102 ,
F_7 ( * V_101 ) ) ) ;
F_8 ( V_6 , & V_9 ) ;
F_40 ( V_52 , V_76 ) ;
F_50 ( V_52 , V_76 , V_94 , V_95 ) ;
F_54 ( V_2 , V_76 ) ;
F_46 ( V_54 , V_72 ) ;
return 0 ;
}
void
F_78 (
T_6 * args ,
struct V_8 * V_9 ,
struct V_3 * V_4 )
{
int V_19 ;
T_13 * V_6 ;
int V_115 ;
int V_18 ;
struct V_28 * V_29 ;
V_6 = V_4 -> V_7 ;
if ( ! V_9 -> V_25 )
return;
V_29 = F_10 ( V_6 ) ;
for ( V_19 = V_18 = 0 , V_115 = - 1 ; V_19 < V_9 -> V_24 ; V_19 ++ ) {
if ( V_29 [ V_19 ] . V_33 == F_9 ( V_34 ) )
continue;
if ( V_19 > V_18 ) {
if ( V_115 == - 1 )
V_115 = V_18 ;
V_29 [ V_18 ] = V_29 [ V_19 ] ;
}
V_18 ++ ;
}
ASSERT ( V_9 -> V_25 == V_19 - V_18 ) ;
V_9 -> V_24 -= V_9 -> V_25 ;
V_9 -> V_25 = 0 ;
F_8 ( V_6 , V_9 ) ;
F_40 ( args -> V_69 , V_4 ) ;
if ( V_115 != - 1 )
F_50 ( args -> V_69 , V_4 , V_115 , V_18 - 1 ) ;
}
void
F_69 (
struct V_8 * V_9 ,
struct V_28 * V_29 ,
int * V_116 ,
int * V_117 ,
int * V_118 ,
int * V_119 ,
int * V_120 )
{
int V_19 ;
int V_92 ;
int V_90 ;
int V_121 ;
int V_91 ;
int V_122 = 0 ;
int V_18 ;
ASSERT ( V_9 -> V_25 > 1 ) ;
V_90 = * V_116 ;
F_56 ( V_9 , V_29 , V_90 , & V_91 , & V_92 ) ;
if ( V_91 >= 0 &&
( V_92 == V_9 -> V_24 ||
V_90 - V_91 <= V_92 - V_90 ) )
V_121 = V_91 ;
else
V_121 = V_92 ;
for ( V_19 = V_18 = 0 ; V_19 < V_9 -> V_24 ; V_19 ++ ) {
if ( V_90 == V_19 )
V_122 = V_18 ;
if ( V_19 != V_121 &&
V_29 [ V_19 ] . V_33 == F_9 ( V_34 ) ) {
if ( V_19 == V_18 )
* V_119 = V_18 ;
continue;
}
if ( V_19 == V_121 )
V_91 = V_92 = V_18 ;
if ( V_19 > V_18 )
V_29 [ V_18 ] = V_29 [ V_19 ] ;
V_18 ++ ;
}
ASSERT ( V_19 > V_18 ) ;
if ( V_90 == V_19 )
V_122 = V_18 ;
* V_116 = V_122 ;
V_9 -> V_24 -= V_19 - V_18 ;
V_9 -> V_25 = 1 ;
if ( V_91 >= V_122 )
V_91 = - 1 ;
else
V_92 = V_9 -> V_24 ;
* V_120 = V_9 -> V_24 - 1 ;
* V_117 = V_91 ;
* V_118 = V_92 ;
}
STATIC int
F_79 (
struct V_53 * V_54 ,
T_18 V_123 ,
struct V_124 * V_125 ,
T_19 * V_126 ,
struct V_3 * * V_57 )
{
struct V_1 * V_2 = V_54 -> V_70 ;
struct V_3 * V_4 = * V_57 ;
struct V_127 * V_128 = V_125 -> V_128 ;
struct V_129 V_130 ;
int error = 0 ;
int V_89 ;
int V_31 ;
int V_131 ;
if ( V_4 ) {
F_65 ( NULL , V_4 ) ;
V_4 = NULL ;
V_125 -> V_132 -= V_2 -> V_133 ;
for ( V_31 = V_2 -> V_133 ; V_31 > 0 ; ) {
V_131 = F_80 ( int , V_128 -> V_134 , V_31 ) ;
V_128 -> V_134 -= V_131 ;
V_128 -> V_135 += V_131 ;
V_128 -> V_136 += V_131 ;
if ( ! V_128 -> V_134 && -- V_125 -> V_137 )
memmove ( & V_128 [ 0 ] , & V_128 [ 1 ] ,
sizeof( V_128 [ 0 ] ) * V_125 -> V_137 ) ;
V_31 -= V_131 ;
}
}
V_125 -> V_138 = F_81 ( V_123 + V_2 -> V_83 ,
V_2 -> V_37 . V_139 ) - 1 ;
ASSERT ( V_125 -> V_138 >= 0 ) ;
if ( 1 + V_125 -> V_138 > V_125 -> V_132 &&
V_125 -> V_140 < F_82 ( V_2 , V_141 ) ) {
V_125 -> V_142 = V_125 -> V_143 - V_125 -> V_137 ;
error = F_83 ( V_54 , V_125 -> V_140 ,
F_82 ( V_2 , V_141 ) -
V_125 -> V_140 ,
& V_128 [ V_125 -> V_137 ] , & V_125 -> V_142 , 0 ) ;
if ( error )
goto V_144;
if ( V_125 -> V_142 == V_125 -> V_143 - V_125 -> V_137 ) {
V_31 = V_125 -> V_137 + V_125 -> V_142 - 1 ;
V_125 -> V_140 = V_128 [ V_31 ] . V_136 + V_128 [ V_31 ] . V_134 ;
} else
V_125 -> V_140 = F_82 ( V_2 ,
V_141 ) ;
for ( V_31 = V_125 -> V_137 ; V_31 < V_125 -> V_137 + V_125 -> V_142 ; ) {
if ( V_128 [ V_31 ] . V_135 == V_145 ) {
V_125 -> V_142 -- ;
V_89 = V_125 -> V_137 + V_125 -> V_142 - V_31 ;
if ( V_89 )
memmove ( & V_128 [ V_31 ] , & V_128 [ V_31 + 1 ] ,
sizeof( V_128 [ V_31 ] ) * V_89 ) ;
} else {
V_125 -> V_132 += V_128 [ V_31 ] . V_134 ;
V_31 ++ ;
}
}
V_125 -> V_137 += V_125 -> V_142 ;
}
if ( ! V_125 -> V_137 ) {
* V_126 = F_84 ( V_2 , V_125 -> V_140 ) ;
goto V_144;
}
V_125 -> V_146 = F_45 ( V_2 , V_128 -> V_136 ) ;
error = F_73 ( NULL , V_54 , V_128 -> V_136 ,
V_128 -> V_134 >= V_2 -> V_133 ?
F_85 ( V_2 , V_128 -> V_135 ) : - 1 , & V_4 ) ;
if ( error )
goto V_144;
if ( V_125 -> V_147 )
V_125 -> V_147 -= V_2 -> V_133 ;
F_86 ( & V_130 ) ;
for ( V_125 -> V_148 = V_125 -> V_149 = V_31 = 0 ;
V_125 -> V_138 > V_125 -> V_147 && V_31 < V_125 -> V_132 ;
V_31 += V_2 -> V_133 ) {
ASSERT ( V_125 -> V_148 < V_125 -> V_137 ) ;
if ( V_31 > V_125 -> V_147 &&
V_128 [ V_125 -> V_148 ] . V_134 >= V_2 -> V_133 ) {
F_87 ( NULL , V_54 ,
V_128 [ V_125 -> V_148 ] . V_136 + V_125 -> V_149 ,
F_85 ( V_2 ,
V_128 [ V_125 -> V_148 ] . V_135 +
V_125 -> V_149 ) ) ;
V_125 -> V_147 = V_31 ;
}
else if ( V_31 > V_125 -> V_147 ) {
F_87 ( NULL , V_54 ,
V_128 [ V_125 -> V_148 ] . V_136 +
V_125 -> V_149 , - 1 ) ;
V_125 -> V_147 = V_31 ;
}
for ( V_131 = 0 ; V_131 < V_2 -> V_133 ; V_131 ++ ) {
V_89 = F_80 ( int , V_2 -> V_133 ,
V_128 [ V_125 -> V_148 ] . V_134 -
V_125 -> V_149 ) ;
V_131 += V_89 ;
V_125 -> V_149 += V_89 ;
if ( V_125 -> V_149 == V_128 [ V_125 -> V_148 ] . V_134 ) {
V_125 -> V_149 = 0 ;
V_125 -> V_148 ++ ;
}
}
}
F_88 ( & V_130 ) ;
V_144:
* V_57 = V_4 ;
return error ;
}
int
F_89 (
T_12 * V_54 ,
struct V_150 * V_151 ,
T_18 V_123 )
{
struct V_3 * V_4 = NULL ;
T_9 * V_20 ;
T_16 * V_97 ;
T_17 * V_98 ;
int error = 0 ;
int V_89 ;
T_14 * V_2 ;
int V_152 ;
T_19 V_126 ;
T_19 V_153 ;
char * V_154 = NULL ;
struct V_124 * V_155 ;
if ( V_151 -> V_156 >= V_157 )
return 0 ;
V_2 = V_54 -> V_70 ;
V_89 = F_81 ( V_123 + V_2 -> V_83 ,
V_2 -> V_37 . V_139 ) ;
V_155 = F_90 ( F_91 ( struct V_124 , V_128 ) +
( V_89 * sizeof( struct V_127 ) ) ,
V_158 | V_159 ) ;
V_155 -> V_143 = V_89 ;
V_126 = F_92 ( V_2 , V_151 -> V_156 ) ;
V_155 -> V_140 = F_39 ( V_2 ,
F_93 ( V_2 , V_126 ) ) ;
while ( V_126 < V_141 ) {
if ( ! V_4 || V_154 >= ( char * ) V_4 -> V_7 + V_2 -> V_83 ) {
error = F_79 ( V_54 , V_123 , V_155 ,
& V_126 , & V_4 ) ;
if ( error || ! V_155 -> V_137 )
break;
V_153 = F_94 ( V_2 , V_155 -> V_146 , 0 ) ;
if ( V_126 < V_153 )
V_126 = V_153 ;
else if ( V_126 > V_153 )
ASSERT ( F_93 ( V_2 , V_126 ) ==
V_155 -> V_146 ) ;
V_20 = V_4 -> V_7 ;
F_46 ( V_54 , V_4 ) ;
V_154 = ( char * ) F_95 ( V_20 ) ;
V_152 = F_96 ( V_2 , V_126 ) ;
if ( V_152 == 0 )
V_126 += F_97 ( V_20 ) ;
else {
while ( ( char * ) V_154 - ( char * ) V_20 < V_152 ) {
V_98 = ( T_17 * ) V_154 ;
if ( F_7 ( V_98 -> V_160 )
== V_161 ) {
V_89 = F_7 ( V_98 -> V_89 ) ;
V_154 += V_89 ;
continue;
}
V_97 = ( T_16 * ) V_154 ;
V_89 =
F_63 ( V_97 -> V_104 ) ;
V_154 += V_89 ;
}
V_126 =
F_94 ( V_2 ,
F_93 ( V_2 , V_126 ) ,
( char * ) V_154 - ( char * ) V_20 ) ;
if ( V_154 >= ( char * ) V_20 + V_2 -> V_83 ) {
continue;
}
}
}
V_98 = ( T_17 * ) V_154 ;
if ( F_7 ( V_98 -> V_160 ) == V_161 ) {
V_89 = F_7 ( V_98 -> V_89 ) ;
V_154 += V_89 ;
V_126 += V_89 ;
continue;
}
V_97 = ( T_16 * ) V_154 ;
V_89 = F_63 ( V_97 -> V_104 ) ;
V_151 -> V_156 = F_98 ( V_2 , V_126 ) & 0x7fffffff ;
if ( ! F_99 ( V_151 , ( char * ) V_97 -> V_114 , V_97 -> V_104 ,
F_3 ( V_97 -> V_113 ) , V_162 ) )
break;
V_154 += V_89 ;
V_126 += V_89 ;
V_123 = V_123 > V_89 ? V_123 - V_89 : 0 ;
}
if ( V_126 > F_92 ( V_2 , V_157 ) )
V_151 -> V_156 = V_157 & 0x7fffffff ;
else
V_151 -> V_156 = F_98 ( V_2 , V_126 ) & 0x7fffffff ;
F_100 ( V_155 ) ;
if ( V_4 )
F_65 ( NULL , V_4 ) ;
return error ;
}
static void
F_55 (
T_15 * V_52 ,
struct V_3 * V_4 ,
int V_163 ,
int V_164 )
{
T_8 * V_165 ;
T_8 * V_166 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 * V_30 ;
ASSERT ( V_6 -> V_20 . V_14 . V_10 == F_5 ( V_17 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_11 ) ) ;
V_30 = F_11 ( V_52 -> V_167 , V_6 ) ;
V_165 = F_13 ( V_30 ) + V_163 ;
V_166 = F_13 ( V_30 ) + V_164 ;
F_101 ( V_52 , V_4 , ( V_168 ) ( ( char * ) V_165 - ( char * ) V_6 ) ,
( V_168 ) ( ( char * ) V_166 - ( char * ) V_6 + sizeof( * V_166 ) - 1 ) ) ;
}
void
F_50 (
T_15 * V_52 ,
struct V_3 * V_4 ,
int V_163 ,
int V_164 )
{
T_10 * V_169 ;
T_10 * V_170 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_28 * V_29 ;
ASSERT ( V_6 -> V_20 . V_14 . V_10 == F_5 ( V_17 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_11 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_21 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_27 ) ) ;
V_29 = F_10 ( V_6 ) ;
V_169 = & V_29 [ V_163 ] ;
V_170 = & V_29 [ V_164 ] ;
F_101 ( V_52 , V_4 , ( V_168 ) ( ( char * ) V_169 - ( char * ) V_6 ) ,
( V_168 ) ( ( char * ) V_170 - ( char * ) V_6 + sizeof( * V_170 ) - 1 ) ) ;
}
void
F_40 (
struct V_51 * V_52 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
ASSERT ( V_6 -> V_20 . V_14 . V_10 == F_5 ( V_17 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_11 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_21 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_27 ) ) ;
F_101 ( V_52 , V_4 , ( V_168 ) ( ( char * ) & V_6 -> V_20 - ( char * ) V_6 ) ,
F_102 ( V_6 ) - 1 ) ;
}
STATIC void
F_41 (
struct V_51 * V_52 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 * V_30 ;
struct V_1 * V_2 = V_52 -> V_167 ;
ASSERT ( V_6 -> V_20 . V_14 . V_10 == F_5 ( V_17 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_11 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_21 ) ||
V_6 -> V_20 . V_14 . V_10 == F_5 ( V_27 ) ) ;
V_30 = F_11 ( V_2 , V_6 ) ;
F_101 ( V_52 , V_4 , ( V_168 ) ( ( char * ) V_30 - ( char * ) V_6 ) ,
( V_168 ) ( V_2 -> V_83 - 1 ) ) ;
}
int
F_103 (
T_6 * args )
{
struct V_3 * V_72 ;
T_16 * V_97 ;
T_12 * V_54 ;
int error ;
int V_90 ;
struct V_3 * V_76 ;
T_13 * V_6 ;
T_10 * V_96 ;
T_15 * V_52 ;
struct V_28 * V_29 ;
F_104 ( args ) ;
if ( ( error = F_105 ( args , & V_76 , & V_90 , & V_72 ) ) ) {
return error ;
}
V_52 = args -> V_69 ;
V_54 = args -> V_54 ;
F_54 ( V_54 -> V_70 , V_76 ) ;
V_6 = V_76 -> V_7 ;
V_29 = F_10 ( V_6 ) ;
V_96 = & V_29 [ V_90 ] ;
V_97 = ( T_16 * )
( ( char * ) V_72 -> V_7 +
F_106 ( V_54 -> V_70 , F_6 ( V_96 -> V_33 ) ) ) ;
args -> V_113 = F_3 ( V_97 -> V_113 ) ;
error = F_107 ( args , V_97 -> V_114 , V_97 -> V_104 ) ;
F_65 ( V_52 , V_72 ) ;
F_65 ( V_52 , V_76 ) ;
return F_66 ( error ) ;
}
static int
F_105 (
T_6 * args ,
struct V_3 * * V_171 ,
int * V_116 ,
struct V_3 * * V_172 )
{
T_7 V_146 = - 1 ;
struct V_3 * V_72 = NULL ;
T_16 * V_97 ;
T_12 * V_54 ;
int error ;
int V_90 ;
struct V_3 * V_76 ;
T_10 * V_96 ;
T_13 * V_6 ;
T_14 * V_2 ;
T_7 V_173 ;
T_15 * V_52 ;
T_7 V_174 = - 1 ;
enum V_175 V_176 ;
struct V_28 * V_29 ;
struct V_8 V_9 ;
V_54 = args -> V_54 ;
V_52 = args -> V_69 ;
V_2 = V_54 -> V_70 ;
error = F_29 ( V_52 , V_54 , V_2 -> V_103 , - 1 , & V_76 ) ;
if ( error )
return error ;
* V_171 = V_76 ;
V_6 = V_76 -> V_7 ;
F_54 ( V_2 , V_76 ) ;
V_29 = F_10 ( V_6 ) ;
F_2 ( & V_9 , V_6 ) ;
V_90 = F_62 ( args , V_76 ) ;
for ( V_96 = & V_29 [ V_90 ] ;
V_90 < V_9 . V_24 && F_6 ( V_96 -> V_32 ) == args -> V_32 ;
V_96 ++ , V_90 ++ ) {
if ( F_6 ( V_96 -> V_33 ) == V_34 )
continue;
V_173 = F_64 ( V_2 , F_6 ( V_96 -> V_33 ) ) ;
if ( V_173 != V_146 ) {
if ( V_72 )
F_65 ( V_52 , V_72 ) ;
error = F_73 ( V_52 , V_54 ,
F_39 ( V_2 , V_173 ) ,
- 1 , & V_72 ) ;
if ( error ) {
F_65 ( V_52 , V_76 ) ;
return error ;
}
V_146 = V_173 ;
}
V_97 = ( T_16 * ) ( ( char * ) V_72 -> V_7 +
F_106 ( V_2 , F_6 ( V_96 -> V_33 ) ) ) ;
V_176 = V_2 -> V_177 -> V_178 ( args , V_97 -> V_114 , V_97 -> V_104 ) ;
if ( V_176 != V_179 && V_176 != args -> V_180 ) {
args -> V_180 = V_176 ;
* V_116 = V_90 ;
if ( V_176 == V_181 ) {
* V_172 = V_72 ;
return 0 ;
}
V_174 = V_146 ;
}
}
ASSERT ( args -> V_107 & V_182 ) ;
if ( args -> V_180 == V_183 ) {
ASSERT ( V_174 != - 1 ) ;
if ( V_174 != V_146 ) {
F_65 ( V_52 , V_72 ) ;
error = F_73 ( V_52 , V_54 ,
F_39 ( V_2 , V_174 ) ,
- 1 , & V_72 ) ;
if ( error ) {
F_65 ( V_52 , V_76 ) ;
return error ;
}
}
* V_172 = V_72 ;
return 0 ;
}
ASSERT ( V_174 == - 1 ) ;
if ( V_72 )
F_65 ( V_52 , V_72 ) ;
F_65 ( V_52 , V_76 ) ;
return F_66 ( V_184 ) ;
}
int
F_108 (
T_6 * args )
{
T_8 * V_73 ;
T_9 * V_20 ;
T_7 V_185 ;
struct V_3 * V_72 ;
T_16 * V_97 ;
T_12 * V_54 ;
int error ;
T_7 V_31 ;
int V_90 ;
struct V_3 * V_76 ;
T_13 * V_6 ;
T_10 * V_96 ;
T_1 * V_30 ;
T_14 * V_2 ;
int V_78 ;
int V_79 ;
V_106 V_186 ;
T_15 * V_52 ;
struct V_80 * V_81 ;
struct V_28 * V_29 ;
struct V_8 V_9 ;
F_109 ( args ) ;
if ( ( error = F_105 ( args , & V_76 , & V_90 , & V_72 ) ) ) {
return error ;
}
V_54 = args -> V_54 ;
V_52 = args -> V_69 ;
V_2 = V_54 -> V_70 ;
V_6 = V_76 -> V_7 ;
V_20 = V_72 -> V_7 ;
F_46 ( V_54 , V_72 ) ;
V_81 = F_49 ( V_20 ) ;
F_2 ( & V_9 , V_6 ) ;
V_29 = F_10 ( V_6 ) ;
V_96 = & V_29 [ V_90 ] ;
V_185 = F_64 ( V_2 , F_6 ( V_96 -> V_33 ) ) ;
V_97 = ( T_16 * )
( ( char * ) V_20 + F_106 ( V_2 , F_6 ( V_96 -> V_33 ) ) ) ;
V_79 = V_78 = 0 ;
V_186 = F_7 ( V_81 [ 0 ] . V_89 ) ;
V_30 = F_11 ( V_2 , V_6 ) ;
V_73 = F_13 ( V_30 ) ;
ASSERT ( F_7 ( V_73 [ V_185 ] ) == V_186 ) ;
F_51 ( V_52 , V_72 ,
( V_82 ) ( ( char * ) V_97 - ( char * ) V_20 ) ,
F_63 ( V_97 -> V_104 ) , & V_78 , & V_79 ) ;
V_9 . V_25 ++ ;
F_8 ( V_6 , & V_9 ) ;
F_40 ( V_52 , V_76 ) ;
V_96 -> V_33 = F_9 ( V_34 ) ;
F_50 ( V_52 , V_76 , V_90 , V_90 ) ;
if ( V_79 )
F_52 ( V_2 , V_20 , & V_78 ) ;
if ( V_78 )
F_53 ( V_52 , V_72 ) ;
if ( F_7 ( V_81 [ 0 ] . V_89 ) != V_186 ) {
V_73 [ V_185 ] = V_81 [ 0 ] . V_89 ;
F_55 ( V_52 , V_76 , V_185 , V_185 ) ;
}
F_46 ( V_54 , V_72 ) ;
if ( F_7 ( V_81 [ 0 ] . V_89 ) ==
V_2 -> V_83 - F_97 ( V_20 ) ) {
ASSERT ( V_185 != V_2 -> V_187 ) ;
if ( ( error = F_110 ( args , V_185 , V_72 ) ) ) {
if ( error == V_110 && args -> V_109 == 0 )
error = 0 ;
F_54 ( V_2 , V_76 ) ;
return error ;
}
V_72 = NULL ;
if ( V_185 == F_6 ( V_30 -> V_66 ) - 1 ) {
for ( V_31 = V_185 - 1 ; V_31 > 0 ; V_31 -- ) {
if ( V_73 [ V_31 ] != F_5 ( V_105 ) )
break;
}
memmove ( & V_73 [ V_185 - V_31 ] , V_73 ,
( F_6 ( V_30 -> V_66 ) - ( V_185 - V_31 ) ) * sizeof( * V_73 ) ) ;
F_72 ( & V_30 -> V_66 , - ( V_185 - V_31 ) ) ;
F_41 ( V_52 , V_76 ) ;
F_55 ( V_52 , V_76 , 0 , F_6 ( V_30 -> V_66 ) - 1 ) ;
} else
V_73 [ V_185 ] = F_5 ( V_105 ) ;
}
else if ( V_185 != V_2 -> V_187 )
V_72 = NULL ;
F_54 ( V_2 , V_76 ) ;
return F_111 ( args , V_76 , V_72 ) ;
}
int
F_112 (
T_6 * args )
{
struct V_3 * V_72 ;
T_16 * V_97 ;
T_12 * V_54 ;
int error ;
int V_90 ;
struct V_3 * V_76 ;
T_13 * V_6 ;
T_10 * V_96 ;
T_15 * V_52 ;
struct V_28 * V_29 ;
F_113 ( args ) ;
if ( ( error = F_105 ( args , & V_76 , & V_90 , & V_72 ) ) ) {
return error ;
}
V_54 = args -> V_54 ;
V_6 = V_76 -> V_7 ;
V_29 = F_10 ( V_6 ) ;
V_96 = & V_29 [ V_90 ] ;
V_97 = ( T_16 * )
( ( char * ) V_72 -> V_7 +
F_106 ( V_54 -> V_70 , F_6 ( V_96 -> V_33 ) ) ) ;
ASSERT ( args -> V_113 != F_3 ( V_97 -> V_113 ) ) ;
V_97 -> V_113 = F_23 ( args -> V_113 ) ;
V_52 = args -> V_69 ;
F_76 ( V_52 , V_72 , V_97 ) ;
F_54 ( V_54 -> V_70 , V_76 ) ;
F_65 ( V_52 , V_76 ) ;
return 0 ;
}
int
F_62 (
T_6 * args ,
struct V_3 * V_76 )
{
T_20 V_188 = 0 ;
T_20 V_189 ;
int V_190 ;
int V_191 ;
T_13 * V_6 ;
T_10 * V_96 ;
int V_192 = 0 ;
struct V_28 * V_29 ;
struct V_8 V_9 ;
V_6 = V_76 -> V_7 ;
V_29 = F_10 ( V_6 ) ;
F_2 ( & V_9 , V_6 ) ;
#ifndef F_114
if ( ! V_9 . V_24 )
return 0 ;
#endif
for ( V_96 = V_29 , V_191 = 0 , V_190 = V_9 . V_24 - 1 ,
V_189 = args -> V_32 ;
V_191 <= V_190 ; ) {
V_192 = ( V_191 + V_190 ) >> 1 ;
if ( ( V_188 = F_6 ( V_96 [ V_192 ] . V_32 ) ) == V_189 )
break;
if ( V_188 < V_189 )
V_191 = V_192 + 1 ;
else
V_190 = V_192 - 1 ;
}
if ( V_188 == V_189 ) {
while ( V_192 > 0 && F_6 ( V_96 [ V_192 - 1 ] . V_32 ) == V_189 ) {
V_192 -- ;
}
}
else if ( V_188 < V_189 )
V_192 ++ ;
return V_192 ;
}
int
F_115 (
T_6 * args ,
struct V_3 * V_76 ,
T_7 V_185 )
{
T_8 * V_73 ;
struct V_3 * V_72 ;
T_12 * V_54 ;
int error ;
T_13 * V_6 ;
T_1 * V_30 ;
T_14 * V_2 ;
T_15 * V_52 ;
V_54 = args -> V_54 ;
V_2 = V_54 -> V_70 ;
V_52 = args -> V_69 ;
error = F_73 ( V_52 , V_54 , F_39 ( V_2 , V_185 ) , - 1 , & V_72 ) ;
if ( error )
return error ;
V_6 = V_76 -> V_7 ;
V_30 = F_11 ( V_2 , V_6 ) ;
#ifdef F_116
{
struct V_193 * V_20 = V_72 -> V_7 ;
struct V_80 * V_81 = F_49 ( V_20 ) ;
ASSERT ( V_20 -> V_10 == F_9 ( V_87 ) ||
V_20 -> V_10 == F_9 ( V_88 ) ) ;
ASSERT ( F_7 ( V_81 [ 0 ] . V_89 ) ==
V_2 -> V_83 - F_97 ( V_20 ) ) ;
ASSERT ( V_185 == F_6 ( V_30 -> V_66 ) - 1 ) ;
}
#endif
if ( ( error = F_110 ( args , V_185 , V_72 ) ) ) {
ASSERT ( error != V_110 ) ;
F_65 ( V_52 , V_72 ) ;
return error ;
}
V_73 = F_13 ( V_30 ) ;
F_72 ( & V_30 -> V_66 , - 1 ) ;
memmove ( & V_73 [ 1 ] , & V_73 [ 0 ] , F_6 ( V_30 -> V_66 ) * sizeof( * V_73 ) ) ;
F_41 ( V_52 , V_76 ) ;
F_55 ( V_52 , V_76 , 0 , F_6 ( V_30 -> V_66 ) - 1 ) ;
return 0 ;
}
static inline T_18
F_117 (
struct V_8 * V_20 ,
int V_194 )
{
int V_195 ;
int V_196 ;
V_195 = V_20 -> V_24 - V_20 -> V_25 ;
if ( V_20 -> V_10 == V_17 ||
V_20 -> V_10 == V_21 )
V_196 = sizeof( struct V_197 ) ;
else
V_196 = sizeof( struct V_12 ) ;
return V_196 + V_195 * sizeof( T_10 )
+ V_194 * sizeof( V_106 )
+ sizeof( T_1 ) ;
}
int
F_118 (
T_21 * V_198 )
{
T_6 * args ;
T_12 * V_54 ;
int error ;
struct V_3 * V_199 ;
T_22 V_200 ;
T_23 * free ;
struct V_3 * V_76 ;
T_1 * V_30 ;
T_13 * V_6 ;
T_14 * V_2 ;
int V_201 ;
T_15 * V_52 ;
struct V_8 V_9 ;
struct V_202 V_203 ;
if ( V_198 -> V_204 . V_205 > 1 )
return 0 ;
args = V_198 -> args ;
F_119 ( args ) ;
V_2 = V_198 -> V_2 ;
V_54 = args -> V_54 ;
V_52 = args -> V_69 ;
if ( ( error = F_120 ( V_52 , V_54 , & V_200 , V_59 ) ) ) {
return error ;
}
V_200 -= V_2 -> V_133 ;
while ( V_200 > V_2 -> V_206 ) {
if ( ( error = F_121 ( args , V_200 , & V_201 ) ) ) {
return error ;
}
if ( V_201 )
V_200 -= V_2 -> V_133 ;
else
return 0 ;
}
if ( ( error = F_122 ( V_52 , V_54 , & V_200 , V_59 ) ) ) {
return error ;
}
if ( F_123 ( V_2 , V_200 ) > V_141 + V_2 -> V_83 )
return 0 ;
V_76 = V_198 -> V_204 . V_207 [ 0 ] . V_4 ;
V_6 = V_76 -> V_7 ;
F_2 ( & V_9 , V_6 ) ;
ASSERT ( V_9 . V_10 == V_21 ||
V_9 . V_10 == V_27 ) ;
error = F_124 ( V_52 , V_54 , V_2 -> V_206 , & V_199 ) ;
if ( error )
return error ;
free = V_199 -> V_7 ;
F_125 ( & V_203 , free ) ;
ASSERT ( ! V_203 . V_208 ) ;
if ( F_117 ( & V_9 , V_203 . V_209 ) > V_2 -> V_83 ) {
F_65 ( V_52 , V_199 ) ;
return 0 ;
}
if ( V_9 . V_25 )
F_78 ( args , & V_9 , V_76 ) ;
V_76 -> V_67 = & V_60 ;
F_31 ( V_52 , V_76 , V_61 ) ;
V_9 . V_10 = ( V_9 . V_10 == V_21 )
? V_17
: V_11 ;
V_30 = F_11 ( V_2 , V_6 ) ;
V_30 -> V_66 = F_9 ( V_203 . V_209 ) ;
memcpy ( F_13 ( V_30 ) , F_126 ( V_2 , free ) ,
V_203 . V_209 * sizeof( V_106 ) ) ;
F_8 ( V_6 , & V_9 ) ;
F_40 ( V_52 , V_76 ) ;
F_55 ( V_52 , V_76 , 0 , F_6 ( V_30 -> V_66 ) - 1 ) ;
F_41 ( V_52 , V_76 ) ;
F_54 ( V_2 , V_76 ) ;
error = F_110 ( args , F_37 ( V_2 ) , V_199 ) ;
if ( error ) {
ASSERT ( error != V_110 ) ;
return error ;
}
V_199 = NULL ;
error = F_111 ( args , V_76 , NULL ) ;
V_198 -> V_204 . V_207 [ 0 ] . V_4 = NULL ;
return error ;
}
