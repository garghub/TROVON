static void
F_1 (
struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
V_11 = V_9 -> V_12 . V_3 == V_3 ;
if ( ! V_11 ) {
F_2 ( V_13 , V_14 , V_5 , V_9 ) ;
F_3 ( V_2 , V_15 ) ;
}
}
static void
F_4 (
struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_16 ) ) ;
}
static void
F_6 (
struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_16 ) ) ;
}
void
F_7 (
struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_17 ) ) ;
}
void
F_8 (
struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_17 ) ) ;
}
static int
F_9 (
struct V_18 * V_19 ,
struct V_20 * V_21 ,
T_2 V_22 ,
T_3 V_23 ,
struct V_1 * * V_24 )
{
return F_10 ( V_19 , V_21 , V_22 , V_23 , V_24 ,
V_25 , & V_26 ) ;
}
int
F_11 (
struct V_18 * V_19 ,
struct V_20 * V_21 ,
T_2 V_22 ,
T_3 V_23 ,
struct V_1 * * V_24 )
{
return F_10 ( V_19 , V_21 , V_22 , V_23 , V_24 ,
V_25 , & V_27 ) ;
}
int
F_12 (
T_4 * args ,
struct V_1 * V_28 )
{
T_1 * V_29 ;
T_2 V_30 ;
T_5 * V_9 ;
T_6 * V_31 ;
T_7 * V_32 ;
T_8 * V_21 ;
int error ;
struct V_1 * V_33 ;
T_9 V_34 ;
T_10 * V_35 ;
T_11 * V_36 ;
T_12 * V_5 ;
int V_37 ;
int V_38 ;
T_13 * V_19 ;
F_13 ( args ) ;
V_21 = args -> V_21 ;
V_5 = V_21 -> V_39 ;
V_19 = args -> V_40 ;
if ( ( error = F_14 ( args , & V_30 ) ) ) {
return error ;
}
V_34 = F_15 ( V_5 , V_30 ) ;
ASSERT ( V_34 == F_16 ( V_5 ) ) ;
if ( ( error = F_17 ( args , V_34 , & V_33 , V_16 ) ) ) {
return error ;
}
ASSERT ( V_33 != NULL ) ;
V_35 = V_33 -> V_10 ;
V_9 = V_28 -> V_10 ;
F_18 ( V_21 , V_28 ) ;
V_32 = F_19 ( V_5 , V_9 ) ;
V_31 = F_20 ( V_32 ) ;
V_35 -> V_9 . V_41 = F_5 ( F_21 ( V_32 -> V_41 ) ) ;
V_35 -> V_9 . V_42 = F_5 ( F_21 ( V_32 -> V_42 ) ) ;
memcpy ( V_35 -> V_43 , V_31 , F_21 ( V_32 -> V_41 ) * sizeof( T_6 ) ) ;
F_22 ( V_19 , V_33 , 0 , F_23 ( V_35 -> V_9 . V_41 ) - 1 ) ;
V_38 = 0 ;
V_37 = 1 ;
F_24 ( V_19 , V_28 ,
( V_44 ) ( ( char * ) V_31 - ( char * ) V_9 ) ,
( V_44 ) ( ( char * ) V_9 + V_5 -> V_45 -
( char * ) V_31 ) ,
& V_37 , & V_38 ) ;
V_28 -> V_46 = & V_47 ;
V_9 -> V_3 = F_25 ( V_48 ) ;
if ( V_38 )
F_26 ( V_5 , V_9 , & V_37 ) ;
V_36 = F_27 ( V_5 , V_35 ) ;
V_36 -> V_49 = F_25 ( 1 ) ;
V_29 = F_28 ( V_36 ) ;
V_29 [ 0 ] = V_9 -> V_50 [ 0 ] . V_51 ;
if ( V_37 )
F_29 ( V_19 , V_28 ) ;
F_30 ( V_21 , V_33 ) ;
F_18 ( V_21 , V_28 ) ;
F_31 ( V_19 , V_33 , 0 , 0 ) ;
return 0 ;
}
STATIC void
F_32 (
struct V_52 * V_35 ,
int V_53 ,
int * V_54 ,
int * V_55 )
{
for ( * V_54 = V_53 - 1 ; * V_54 >= 0 ; -- * V_54 ) {
if ( V_35 -> V_43 [ * V_54 ] . V_56 ==
F_25 ( V_57 ) )
break;
}
for ( * V_55 = V_53 ;
* V_55 < F_23 ( V_35 -> V_9 . V_41 ) ;
++ * V_55 ) {
if ( V_35 -> V_43 [ * V_55 ] . V_56 ==
F_25 ( V_57 ) )
break;
if ( * V_54 >= 0 && V_53 - * V_54 <= * V_55 - V_53 )
break;
}
}
struct V_58 *
F_33 (
T_10 * V_35 ,
int V_53 ,
int V_59 ,
int V_54 ,
int V_55 ,
int * V_60 ,
int * V_61 )
{
if ( ! V_35 -> V_9 . V_42 ) {
T_6 * V_62 ;
V_62 = & V_35 -> V_43 [ V_53 ] ;
if ( V_53 < F_23 ( V_35 -> V_9 . V_41 ) )
memmove ( V_62 + 1 , V_62 ,
( F_23 ( V_35 -> V_9 . V_41 ) - V_53 ) *
sizeof( * V_62 ) ) ;
* V_60 = V_53 ;
* V_61 = F_23 ( V_35 -> V_9 . V_41 ) ;
F_34 ( & V_35 -> V_9 . V_41 , 1 ) ;
return V_62 ;
}
if ( V_59 == 0 )
F_32 ( V_35 , V_53 , & V_54 , & V_55 ) ;
if ( V_54 >= 0 &&
( V_55 == F_23 ( V_35 -> V_9 . V_41 ) ||
V_53 - V_54 - 1 < V_55 - V_53 ) ) {
ASSERT ( V_53 - V_54 - 1 >= 0 ) ;
ASSERT ( V_35 -> V_43 [ V_54 ] . V_56 ==
F_25 ( V_57 ) ) ;
if ( V_53 - V_54 - 1 > 0 ) {
memmove ( & V_35 -> V_43 [ V_54 ] ,
& V_35 -> V_43 [ V_54 + 1 ] ,
( V_53 - V_54 - 1 ) *
sizeof( T_6 ) ) ;
}
* V_60 = F_35 ( V_54 , * V_60 ) ;
* V_61 = F_36 ( V_53 - 1 , * V_61 ) ;
F_34 ( & V_35 -> V_9 . V_42 , - 1 ) ;
return & V_35 -> V_43 [ V_53 - 1 ] ;
}
ASSERT ( V_55 - V_53 >= 0 ) ;
ASSERT ( V_35 -> V_43 [ V_55 ] . V_56 ==
F_25 ( V_57 ) ) ;
if ( V_55 - V_53 > 0 ) {
memmove ( & V_35 -> V_43 [ V_53 + 1 ] ,
& V_35 -> V_43 [ V_53 ] ,
( V_55 - V_53 ) * sizeof( T_6 ) ) ;
}
* V_60 = F_35 ( V_53 , * V_60 ) ;
* V_61 = F_36 ( V_55 , * V_61 ) ;
F_34 ( & V_35 -> V_9 . V_42 , - 1 ) ;
return & V_35 -> V_43 [ V_53 ] ;
}
int
F_37 (
T_4 * args )
{
T_1 * V_29 ;
int V_59 ;
T_5 * V_9 ;
struct V_1 * V_28 ;
T_14 * V_63 ;
T_8 * V_21 ;
T_15 * V_64 ;
int error ;
int V_65 ;
int V_55 ;
int V_66 ;
int V_53 ;
struct V_1 * V_33 ;
T_10 * V_35 ;
int V_51 ;
T_6 * V_62 ;
int V_60 ;
int V_61 ;
int V_54 ;
T_11 * V_36 ;
T_12 * V_5 ;
int V_67 ;
int V_37 ;
int V_38 ;
T_1 * V_68 ;
T_13 * V_19 ;
T_9 V_69 ;
F_38 ( args ) ;
V_21 = args -> V_21 ;
V_19 = args -> V_40 ;
V_5 = V_21 -> V_39 ;
error = F_9 ( V_19 , V_21 , V_5 -> V_70 , - 1 , & V_33 ) ;
if ( error )
return error ;
V_53 = F_39 ( args , V_33 ) ;
V_35 = V_33 -> V_10 ;
V_36 = F_27 ( V_5 , V_35 ) ;
V_29 = F_28 ( V_36 ) ;
V_51 = F_40 ( args -> V_71 ) ;
for ( V_69 = - 1 , V_62 = & V_35 -> V_43 [ V_53 ] ;
V_53 < F_23 ( V_35 -> V_9 . V_41 ) && F_21 ( V_62 -> V_72 ) == args -> V_72 ;
V_53 ++ , V_62 ++ ) {
if ( F_21 ( V_62 -> V_56 ) == V_57 )
continue;
V_66 = F_41 ( V_5 , F_21 ( V_62 -> V_56 ) ) ;
ASSERT ( V_66 < F_21 ( V_36 -> V_49 ) ) ;
ASSERT ( V_29 [ V_66 ] != F_5 ( V_73 ) ) ;
if ( F_23 ( V_29 [ V_66 ] ) >= V_51 ) {
V_69 = V_66 ;
break;
}
}
if ( V_69 == - 1 ) {
for ( V_66 = 0 ; V_66 < F_21 ( V_36 -> V_49 ) ; V_66 ++ ) {
if ( V_29 [ V_66 ] == F_5 ( V_73 ) &&
V_69 == - 1 )
V_69 = V_66 ;
else if ( F_23 ( V_29 [ V_66 ] ) >= V_51 ) {
V_69 = V_66 ;
break;
}
}
}
V_67 = 0 ;
if ( ! V_35 -> V_9 . V_42 )
V_67 += sizeof( T_6 ) ;
if ( V_69 == - 1 )
V_67 += sizeof( V_74 ) ;
if ( V_69 != - 1 && V_29 [ V_69 ] == F_5 ( V_73 ) )
V_69 = - 1 ;
if ( ( char * ) V_29 - ( char * ) & V_35 -> V_43 [ F_23 ( V_35 -> V_9 . V_41 ) ] <
V_67 && F_23 ( V_35 -> V_9 . V_42 ) > 1 ) {
V_59 = 1 ;
}
else if ( ( char * ) V_29 - ( char * ) & V_35 -> V_43 [ F_23 (
V_35 -> V_9 . V_41 ) ] < V_67 ) {
if ( ( args -> V_75 & V_76 ) ||
args -> V_77 == 0 ) {
F_42 ( V_19 , V_33 ) ;
return F_43 ( V_78 ) ;
}
error = F_44 ( args , V_33 ) ;
if ( error )
return error ;
return F_45 ( args ) ;
}
else
V_59 = 0 ;
if ( args -> V_75 & V_76 ) {
F_42 ( V_19 , V_33 ) ;
return V_69 == - 1 ? F_43 ( V_78 ) : 0 ;
}
if ( args -> V_77 == 0 && V_69 == - 1 ) {
F_42 ( V_19 , V_33 ) ;
return F_43 ( V_78 ) ;
}
if ( V_59 ) {
F_46 ( V_33 , & V_53 , & V_54 , & V_55 ,
& V_60 , & V_61 ) ;
}
else if ( F_23 ( V_35 -> V_9 . V_42 ) ) {
V_60 = F_23 ( V_35 -> V_9 . V_41 ) ;
V_61 = - 1 ;
}
if ( V_69 == - 1 ) {
if ( ( error = F_47 ( args , V_79 ,
& V_69 ) ) ) {
F_42 ( V_19 , V_33 ) ;
return error ;
}
if ( ( error = F_48 ( args , V_69 , & V_28 ) ) ) {
F_42 ( V_19 , V_33 ) ;
return error ;
}
if ( V_69 >= F_21 ( V_36 -> V_49 ) ) {
V_29 -- ;
memmove ( & V_29 [ 0 ] , & V_29 [ 1 ] ,
F_21 ( V_36 -> V_49 ) * sizeof( V_29 [ 0 ] ) ) ;
F_49 ( & V_36 -> V_49 , 1 ) ;
F_50 ( V_19 , V_33 ) ;
F_31 ( V_19 , V_33 , 0 , F_21 ( V_36 -> V_49 ) - 1 ) ;
}
else
F_31 ( V_19 , V_33 , V_69 , V_69 ) ;
V_9 = V_28 -> V_10 ;
V_29 [ V_69 ] = V_9 -> V_50 [ 0 ] . V_51 ;
V_65 = 1 ;
} else {
error = F_51 ( V_19 , V_21 ,
F_52 ( V_5 , V_69 ) ,
- 1 , & V_28 ) ;
if ( error ) {
F_42 ( V_19 , V_33 ) ;
return error ;
}
V_9 = V_28 -> V_10 ;
V_65 = 0 ;
}
V_64 = ( T_15 * )
( ( char * ) V_9 + F_23 ( V_9 -> V_50 [ 0 ] . V_80 ) ) ;
ASSERT ( F_23 ( V_64 -> V_51 ) >= V_51 ) ;
V_38 = V_37 = 0 ;
F_53 ( V_19 , V_28 , V_64 ,
( V_44 ) ( ( char * ) V_64 - ( char * ) V_9 ) , V_51 ,
& V_37 , & V_38 ) ;
V_63 = ( T_14 * ) V_64 ;
V_63 -> V_81 = F_54 ( args -> V_81 ) ;
V_63 -> V_71 = args -> V_71 ;
memcpy ( V_63 -> V_82 , args -> V_82 , V_63 -> V_71 ) ;
V_68 = F_55 ( V_63 ) ;
* V_68 = F_5 ( ( char * ) V_63 - ( char * ) V_9 ) ;
if ( V_38 )
F_26 ( V_5 , V_9 , & V_37 ) ;
if ( V_37 )
F_29 ( V_19 , V_28 ) ;
F_56 ( V_19 , V_28 , V_63 ) ;
if ( F_23 ( V_29 [ V_69 ] ) != F_23 ( V_9 -> V_50 [ 0 ] . V_51 ) ) {
V_29 [ V_69 ] = V_9 -> V_50 [ 0 ] . V_51 ;
if ( ! V_65 )
F_31 ( V_19 , V_33 , V_69 , V_69 ) ;
}
V_62 = F_33 ( V_35 , V_53 , V_59 , V_54 ,
V_55 , & V_60 , & V_61 ) ;
V_62 -> V_72 = F_25 ( args -> V_72 ) ;
V_62 -> V_56 = F_25 ( F_57 ( V_5 , V_69 ,
F_23 ( * V_68 ) ) ) ;
F_58 ( V_19 , V_33 ) ;
F_22 ( V_19 , V_33 , V_60 , V_61 ) ;
F_30 ( V_21 , V_33 ) ;
F_18 ( V_21 , V_28 ) ;
return 0 ;
}
STATIC void
F_30 (
struct V_20 * V_21 ,
struct V_1 * V_2 )
{
int V_66 ;
T_10 * V_35 ;
T_11 * V_36 ;
T_12 * V_5 ;
int V_42 ;
V_35 = V_2 -> V_10 ;
V_5 = V_21 -> V_39 ;
ASSERT ( V_35 -> V_9 . V_12 . V_3 == F_5 ( V_16 ) ) ;
ASSERT ( F_23 ( V_35 -> V_9 . V_41 ) <= F_59 ( V_5 ) ) ;
V_36 = F_27 ( V_5 , V_35 ) ;
ASSERT ( ( char * ) & V_35 -> V_43 [ F_23 ( V_35 -> V_9 . V_41 ) ] <=
( char * ) F_28 ( V_36 ) ) ;
for ( V_66 = V_42 = 0 ; V_66 < F_23 ( V_35 -> V_9 . V_41 ) ; V_66 ++ ) {
if ( V_66 + 1 < F_23 ( V_35 -> V_9 . V_41 ) )
ASSERT ( F_21 ( V_35 -> V_43 [ V_66 ] . V_72 ) <=
F_21 ( V_35 -> V_43 [ V_66 + 1 ] . V_72 ) ) ;
if ( V_35 -> V_43 [ V_66 ] . V_56 == F_25 ( V_57 ) )
V_42 ++ ;
}
ASSERT ( F_23 ( V_35 -> V_9 . V_42 ) == V_42 ) ;
}
void
F_60 (
T_4 * args ,
struct V_1 * V_2 )
{
int V_83 ;
T_10 * V_35 ;
int V_84 ;
int V_85 ;
V_35 = V_2 -> V_10 ;
if ( ! V_35 -> V_9 . V_42 ) {
return;
}
for ( V_83 = V_85 = 0 , V_84 = - 1 ; V_83 < F_23 ( V_35 -> V_9 . V_41 ) ; V_83 ++ ) {
if ( V_35 -> V_43 [ V_83 ] . V_56 ==
F_25 ( V_57 ) )
continue;
if ( V_83 > V_85 ) {
if ( V_84 == - 1 )
V_84 = V_85 ;
V_35 -> V_43 [ V_85 ] = V_35 -> V_43 [ V_83 ] ;
}
V_85 ++ ;
}
ASSERT ( F_23 ( V_35 -> V_9 . V_42 ) == V_83 - V_85 ) ;
F_34 ( & V_35 -> V_9 . V_41 , - ( F_23 ( V_35 -> V_9 . V_42 ) ) ) ;
V_35 -> V_9 . V_42 = 0 ;
F_58 ( args -> V_40 , V_2 ) ;
if ( V_84 != - 1 )
F_22 ( args -> V_40 , V_2 , V_84 , V_85 - 1 ) ;
}
void
F_46 (
struct V_1 * V_2 ,
int * V_86 ,
int * V_87 ,
int * V_88 ,
int * V_89 ,
int * V_90 )
{
int V_83 ;
int V_55 ;
int V_53 ;
int V_91 ;
T_10 * V_35 ;
int V_54 ;
int V_92 = 0 ;
int V_85 ;
V_35 = V_2 -> V_10 ;
ASSERT ( F_23 ( V_35 -> V_9 . V_42 ) > 1 ) ;
V_53 = * V_86 ;
F_32 ( V_35 , V_53 , & V_54 , & V_55 ) ;
if ( V_54 >= 0 &&
( V_55 == F_23 ( V_35 -> V_9 . V_41 ) ||
V_53 - V_54 <= V_55 - V_53 ) )
V_91 = V_54 ;
else
V_91 = V_55 ;
for ( V_83 = V_85 = 0 ; V_83 < F_23 ( V_35 -> V_9 . V_41 ) ; V_83 ++ ) {
if ( V_53 == V_83 )
V_92 = V_85 ;
if ( V_83 != V_91 &&
V_35 -> V_43 [ V_83 ] . V_56 ==
F_25 ( V_57 ) ) {
if ( V_83 == V_85 )
* V_89 = V_85 ;
continue;
}
if ( V_83 == V_91 )
V_54 = V_55 = V_85 ;
if ( V_83 > V_85 )
V_35 -> V_43 [ V_85 ] = V_35 -> V_43 [ V_83 ] ;
V_85 ++ ;
}
ASSERT ( V_83 > V_85 ) ;
if ( V_53 == V_83 )
V_92 = V_85 ;
* V_86 = V_92 ;
F_34 ( & V_35 -> V_9 . V_41 , - ( V_83 - V_85 ) ) ;
V_35 -> V_9 . V_42 = F_5 ( 1 ) ;
if ( V_54 >= V_92 )
V_54 = - 1 ;
else
V_55 = F_23 ( V_35 -> V_9 . V_41 ) ;
* V_90 = F_23 ( V_35 -> V_9 . V_41 ) - 1 ;
* V_87 = V_54 ;
* V_88 = V_55 ;
}
STATIC int
F_61 (
struct V_20 * V_21 ,
T_16 V_93 ,
struct V_94 * V_95 ,
T_17 * V_96 ,
struct V_1 * * V_24 )
{
struct V_4 * V_5 = V_21 -> V_39 ;
struct V_1 * V_2 = * V_24 ;
struct V_97 * V_98 = V_95 -> V_98 ;
int error = 0 ;
int V_51 ;
int V_66 ;
int V_99 ;
if ( V_2 ) {
F_42 ( NULL , V_2 ) ;
V_2 = NULL ;
V_95 -> V_100 -= V_5 -> V_101 ;
for ( V_66 = V_5 -> V_101 ; V_66 > 0 ; ) {
V_99 = F_62 ( int , V_98 -> V_102 , V_66 ) ;
V_98 -> V_102 -= V_99 ;
V_98 -> V_103 += V_99 ;
V_98 -> V_104 += V_99 ;
if ( ! V_98 -> V_102 && -- V_95 -> V_105 )
memmove ( & V_98 [ 0 ] , & V_98 [ 1 ] ,
sizeof( V_98 [ 0 ] ) * V_95 -> V_105 ) ;
V_66 -= V_99 ;
}
}
V_95 -> V_106 = F_63 ( V_93 + V_5 -> V_45 ,
V_5 -> V_107 . V_108 ) - 1 ;
ASSERT ( V_95 -> V_106 >= 0 ) ;
if ( 1 + V_95 -> V_106 > V_95 -> V_100 &&
V_95 -> V_109 < F_64 ( V_5 , V_110 ) ) {
V_95 -> V_111 = V_95 -> V_112 - V_95 -> V_105 ;
error = F_65 ( V_21 , V_95 -> V_109 ,
F_64 ( V_5 , V_110 ) -
V_95 -> V_109 ,
& V_98 [ V_95 -> V_105 ] , & V_95 -> V_111 , 0 ) ;
if ( error )
goto V_113;
if ( V_95 -> V_111 == V_95 -> V_112 - V_95 -> V_105 ) {
V_66 = V_95 -> V_105 + V_95 -> V_111 - 1 ;
V_95 -> V_109 = V_98 [ V_66 ] . V_104 + V_98 [ V_66 ] . V_102 ;
} else
V_95 -> V_109 = F_64 ( V_5 ,
V_110 ) ;
for ( V_66 = V_95 -> V_105 ; V_66 < V_95 -> V_105 + V_95 -> V_111 ; ) {
if ( V_98 [ V_66 ] . V_103 == V_114 ) {
V_95 -> V_111 -- ;
V_51 = V_95 -> V_105 + V_95 -> V_111 - V_66 ;
if ( V_51 )
memmove ( & V_98 [ V_66 ] , & V_98 [ V_66 + 1 ] ,
sizeof( V_98 [ V_66 ] ) * V_51 ) ;
} else {
V_95 -> V_100 += V_98 [ V_66 ] . V_102 ;
V_66 ++ ;
}
}
V_95 -> V_105 += V_95 -> V_111 ;
}
if ( ! V_95 -> V_105 ) {
* V_96 = F_66 ( V_5 , V_95 -> V_109 ) ;
goto V_113;
}
V_95 -> V_115 = F_15 ( V_5 , V_98 -> V_104 ) ;
error = F_51 ( NULL , V_21 , V_98 -> V_104 ,
V_98 -> V_102 >= V_5 -> V_101 ?
F_67 ( V_5 , V_98 -> V_103 ) : - 1 , & V_2 ) ;
if ( error )
goto V_113;
if ( V_95 -> V_116 )
V_95 -> V_116 -= V_5 -> V_101 ;
for ( V_95 -> V_117 = V_95 -> V_118 = V_66 = 0 ;
V_95 -> V_106 > V_95 -> V_116 && V_66 < V_95 -> V_100 ;
V_66 += V_5 -> V_101 ) {
ASSERT ( V_95 -> V_117 < V_95 -> V_105 ) ;
if ( V_66 > V_95 -> V_116 &&
V_98 [ V_95 -> V_117 ] . V_102 >= V_5 -> V_101 ) {
F_68 ( NULL , V_21 ,
V_98 [ V_95 -> V_117 ] . V_104 + V_95 -> V_118 ,
F_67 ( V_5 ,
V_98 [ V_95 -> V_117 ] . V_103 +
V_95 -> V_118 ) ) ;
V_95 -> V_116 = V_66 ;
}
else if ( V_66 > V_95 -> V_116 ) {
F_68 ( NULL , V_21 ,
V_98 [ V_95 -> V_117 ] . V_104 +
V_95 -> V_118 , - 1 ) ;
V_95 -> V_116 = V_66 ;
}
for ( V_99 = 0 ; V_99 < V_5 -> V_101 ; V_99 ++ ) {
V_51 = F_62 ( int , V_5 -> V_101 ,
V_98 [ V_95 -> V_117 ] . V_102 -
V_95 -> V_118 ) ;
V_99 += V_51 ;
V_95 -> V_118 += V_51 ;
if ( V_95 -> V_118 == V_98 [ V_95 -> V_117 ] . V_102 ) {
V_95 -> V_118 = 0 ;
V_95 -> V_117 ++ ;
}
}
}
V_113:
* V_24 = V_2 ;
return error ;
}
int
F_69 (
T_8 * V_21 ,
void * V_119 ,
T_16 V_93 ,
T_18 * V_80 ,
T_19 V_120 )
{
struct V_1 * V_2 = NULL ;
T_5 * V_9 ;
T_14 * V_63 ;
T_15 * V_64 ;
int error = 0 ;
int V_51 ;
T_12 * V_5 ;
int V_121 ;
T_17 V_96 ;
T_17 V_122 ;
char * V_123 = NULL ;
struct V_94 * V_124 ;
if ( * V_80 >= V_125 )
return 0 ;
V_5 = V_21 -> V_39 ;
V_51 = F_63 ( V_93 + V_5 -> V_45 ,
V_5 -> V_107 . V_108 ) ;
V_124 = F_70 ( F_71 ( struct V_94 , V_98 ) +
( V_51 * sizeof( struct V_97 ) ) ,
V_126 ) ;
V_124 -> V_112 = V_51 ;
V_96 = F_72 ( V_5 , * V_80 ) ;
V_124 -> V_109 = F_52 ( V_5 ,
F_73 ( V_5 , V_96 ) ) ;
while ( V_96 < V_110 ) {
if ( ! V_2 || V_123 >= ( char * ) V_2 -> V_10 + V_5 -> V_45 ) {
error = F_61 ( V_21 , V_93 , V_124 ,
& V_96 , & V_2 ) ;
if ( error || ! V_124 -> V_105 )
break;
V_122 = F_74 ( V_5 , V_124 -> V_115 , 0 ) ;
if ( V_96 < V_122 )
V_96 = V_122 ;
else if ( V_96 > V_122 )
ASSERT ( F_73 ( V_5 , V_96 ) ==
V_124 -> V_115 ) ;
V_9 = V_2 -> V_10 ;
F_18 ( V_21 , V_2 ) ;
V_123 = ( char * ) ( V_9 + 1 ) ;
V_121 = F_75 ( V_5 , V_96 ) ;
if ( V_121 == 0 )
V_96 += ( V_127 ) sizeof( * V_9 ) ;
else {
while ( ( char * ) V_123 - ( char * ) V_9 < V_121 ) {
V_64 = ( T_15 * ) V_123 ;
if ( F_23 ( V_64 -> V_128 )
== V_129 ) {
V_51 = F_23 ( V_64 -> V_51 ) ;
V_123 += V_51 ;
continue;
}
V_63 = ( T_14 * ) V_123 ;
V_51 =
F_40 ( V_63 -> V_71 ) ;
V_123 += V_51 ;
}
V_96 =
F_74 ( V_5 ,
F_73 ( V_5 , V_96 ) ,
( char * ) V_123 - ( char * ) V_9 ) ;
if ( V_123 >= ( char * ) V_9 + V_5 -> V_45 ) {
continue;
}
}
}
V_64 = ( T_15 * ) V_123 ;
if ( F_23 ( V_64 -> V_128 ) == V_129 ) {
V_51 = F_23 ( V_64 -> V_51 ) ;
V_123 += V_51 ;
V_96 += V_51 ;
continue;
}
V_63 = ( T_14 * ) V_123 ;
V_51 = F_40 ( V_63 -> V_71 ) ;
if ( V_120 ( V_119 , ( char * ) V_63 -> V_82 , V_63 -> V_71 ,
F_76 ( V_5 , V_96 ) & 0x7fffffff ,
F_77 ( V_63 -> V_81 ) , V_130 ) )
break;
V_123 += V_51 ;
V_96 += V_51 ;
V_93 = V_93 > V_51 ? V_93 - V_51 : 0 ;
}
if ( V_96 > F_72 ( V_5 , V_125 ) )
* V_80 = V_125 & 0x7fffffff ;
else
* V_80 = F_76 ( V_5 , V_96 ) & 0x7fffffff ;
F_78 ( V_124 ) ;
if ( V_2 )
F_42 ( NULL , V_2 ) ;
return error ;
}
int
F_17 (
T_4 * args ,
T_9 V_131 ,
struct V_1 * * V_24 ,
int V_3 )
{
struct V_1 * V_2 ;
T_8 * V_21 ;
int error ;
T_10 * V_35 ;
T_11 * V_36 ;
T_12 * V_5 ;
T_13 * V_19 ;
V_21 = args -> V_21 ;
ASSERT ( V_21 != NULL ) ;
V_19 = args -> V_40 ;
V_5 = V_21 -> V_39 ;
ASSERT ( V_131 >= F_16 ( V_5 ) &&
V_131 < F_79 ( V_5 ) ) ;
error = F_80 ( V_19 , V_21 , F_52 ( V_5 , V_131 ) , - 1 , & V_2 ,
V_25 ) ;
if ( error )
return error ;
V_35 = V_2 -> V_10 ;
V_35 -> V_9 . V_12 . V_3 = F_5 ( V_3 ) ;
V_35 -> V_9 . V_12 . V_132 = 0 ;
V_35 -> V_9 . V_12 . V_133 = 0 ;
V_35 -> V_9 . V_41 = 0 ;
V_35 -> V_9 . V_42 = 0 ;
F_58 ( V_19 , V_2 ) ;
if ( V_3 == V_16 ) {
V_2 -> V_46 = & V_26 ;
V_36 = F_27 ( V_5 , V_35 ) ;
V_36 -> V_49 = 0 ;
F_50 ( V_19 , V_2 ) ;
} else
V_2 -> V_46 = & V_27 ;
* V_24 = V_2 ;
return 0 ;
}
static void
F_31 (
T_13 * V_19 ,
struct V_1 * V_2 ,
int V_134 ,
int V_135 )
{
T_1 * V_136 ;
T_1 * V_137 ;
T_10 * V_35 ;
T_11 * V_36 ;
V_35 = V_2 -> V_10 ;
ASSERT ( V_35 -> V_9 . V_12 . V_3 == F_5 ( V_16 ) ) ;
V_36 = F_27 ( V_19 -> V_138 , V_35 ) ;
V_136 = F_28 ( V_36 ) + V_134 ;
V_137 = F_28 ( V_36 ) + V_135 ;
F_81 ( V_19 , V_2 , ( V_127 ) ( ( char * ) V_136 - ( char * ) V_35 ) ,
( V_127 ) ( ( char * ) V_137 - ( char * ) V_35 + sizeof( * V_137 ) - 1 ) ) ;
}
void
F_22 (
T_13 * V_19 ,
struct V_1 * V_2 ,
int V_134 ,
int V_135 )
{
T_6 * V_139 ;
T_6 * V_140 ;
T_10 * V_35 ;
V_35 = V_2 -> V_10 ;
ASSERT ( V_35 -> V_9 . V_12 . V_3 == F_5 ( V_16 ) ||
V_35 -> V_9 . V_12 . V_3 == F_5 ( V_17 ) ) ;
V_139 = & V_35 -> V_43 [ V_134 ] ;
V_140 = & V_35 -> V_43 [ V_135 ] ;
F_81 ( V_19 , V_2 , ( V_127 ) ( ( char * ) V_139 - ( char * ) V_35 ) ,
( V_127 ) ( ( char * ) V_140 - ( char * ) V_35 + sizeof( * V_140 ) - 1 ) ) ;
}
void
F_58 (
struct V_18 * V_19 ,
struct V_1 * V_2 )
{
T_10 * V_35 ;
V_35 = V_2 -> V_10 ;
ASSERT ( V_35 -> V_9 . V_12 . V_3 == F_5 ( V_16 ) ||
V_35 -> V_9 . V_12 . V_3 == F_5 ( V_17 ) ) ;
F_81 ( V_19 , V_2 , ( V_127 ) ( ( char * ) & V_35 -> V_9 - ( char * ) V_35 ) ,
( V_127 ) ( sizeof( V_35 -> V_9 ) - 1 ) ) ;
}
STATIC void
F_50 (
struct V_18 * V_19 ,
struct V_1 * V_2 )
{
T_10 * V_35 ;
T_11 * V_36 ;
T_12 * V_5 ;
V_5 = V_19 -> V_138 ;
V_35 = V_2 -> V_10 ;
ASSERT ( V_35 -> V_9 . V_12 . V_3 == F_5 ( V_16 ) ) ;
V_36 = F_27 ( V_5 , V_35 ) ;
F_81 ( V_19 , V_2 , ( V_127 ) ( ( char * ) V_36 - ( char * ) V_35 ) ,
( V_127 ) ( V_5 -> V_45 - 1 ) ) ;
}
int
F_82 (
T_4 * args )
{
struct V_1 * V_28 ;
T_14 * V_63 ;
T_8 * V_21 ;
int error ;
int V_53 ;
struct V_1 * V_33 ;
T_10 * V_35 ;
T_6 * V_62 ;
T_13 * V_19 ;
F_83 ( args ) ;
if ( ( error = F_84 ( args , & V_33 , & V_53 , & V_28 ) ) ) {
return error ;
}
V_19 = args -> V_40 ;
V_21 = args -> V_21 ;
F_30 ( V_21 , V_33 ) ;
V_35 = V_33 -> V_10 ;
V_62 = & V_35 -> V_43 [ V_53 ] ;
V_63 = ( T_14 * )
( ( char * ) V_28 -> V_10 +
F_85 ( V_21 -> V_39 , F_21 ( V_62 -> V_56 ) ) ) ;
args -> V_81 = F_77 ( V_63 -> V_81 ) ;
error = F_86 ( args , V_63 -> V_82 , V_63 -> V_71 ) ;
F_42 ( V_19 , V_28 ) ;
F_42 ( V_19 , V_33 ) ;
return F_43 ( error ) ;
}
static int
F_84 (
T_4 * args ,
struct V_1 * * V_141 ,
int * V_86 ,
struct V_1 * * V_142 )
{
T_9 V_115 = - 1 ;
struct V_1 * V_28 = NULL ;
T_14 * V_63 ;
T_8 * V_21 ;
int error ;
int V_53 ;
struct V_1 * V_33 ;
T_6 * V_62 ;
T_10 * V_35 ;
T_12 * V_5 ;
T_9 V_143 ;
T_13 * V_19 ;
T_9 V_144 = - 1 ;
enum V_145 V_146 ;
V_21 = args -> V_21 ;
V_19 = args -> V_40 ;
V_5 = V_21 -> V_39 ;
error = F_9 ( V_19 , V_21 , V_5 -> V_70 , - 1 , & V_33 ) ;
if ( error )
return error ;
* V_141 = V_33 ;
V_35 = V_33 -> V_10 ;
F_30 ( V_21 , V_33 ) ;
V_53 = F_39 ( args , V_33 ) ;
for ( V_62 = & V_35 -> V_43 [ V_53 ] ; V_53 < F_23 ( V_35 -> V_9 . V_41 ) &&
F_21 ( V_62 -> V_72 ) == args -> V_72 ;
V_62 ++ , V_53 ++ ) {
if ( F_21 ( V_62 -> V_56 ) == V_57 )
continue;
V_143 = F_41 ( V_5 , F_21 ( V_62 -> V_56 ) ) ;
if ( V_143 != V_115 ) {
if ( V_28 )
F_42 ( V_19 , V_28 ) ;
error = F_51 ( V_19 , V_21 ,
F_52 ( V_5 , V_143 ) ,
- 1 , & V_28 ) ;
if ( error ) {
F_42 ( V_19 , V_33 ) ;
return error ;
}
V_115 = V_143 ;
}
V_63 = ( T_14 * ) ( ( char * ) V_28 -> V_10 +
F_85 ( V_5 , F_21 ( V_62 -> V_56 ) ) ) ;
V_146 = V_5 -> V_147 -> V_148 ( args , V_63 -> V_82 , V_63 -> V_71 ) ;
if ( V_146 != V_149 && V_146 != args -> V_150 ) {
args -> V_150 = V_146 ;
* V_86 = V_53 ;
if ( V_146 == V_151 ) {
* V_142 = V_28 ;
return 0 ;
}
V_144 = V_115 ;
}
}
ASSERT ( args -> V_75 & V_152 ) ;
if ( args -> V_150 == V_153 ) {
ASSERT ( V_144 != - 1 ) ;
if ( V_144 != V_115 ) {
F_42 ( V_19 , V_28 ) ;
error = F_51 ( V_19 , V_21 ,
F_52 ( V_5 , V_144 ) ,
- 1 , & V_28 ) ;
if ( error ) {
F_42 ( V_19 , V_33 ) ;
return error ;
}
}
* V_142 = V_28 ;
return 0 ;
}
ASSERT ( V_144 == - 1 ) ;
if ( V_28 )
F_42 ( V_19 , V_28 ) ;
F_42 ( V_19 , V_33 ) ;
return F_43 ( V_154 ) ;
}
int
F_87 (
T_4 * args )
{
T_1 * V_29 ;
T_5 * V_9 ;
T_9 V_155 ;
struct V_1 * V_28 ;
T_14 * V_63 ;
T_8 * V_21 ;
int error ;
T_9 V_66 ;
int V_53 ;
struct V_1 * V_33 ;
T_10 * V_35 ;
T_6 * V_62 ;
T_11 * V_36 ;
T_12 * V_5 ;
int V_37 ;
int V_38 ;
V_74 V_156 ;
T_13 * V_19 ;
F_88 ( args ) ;
if ( ( error = F_84 ( args , & V_33 , & V_53 , & V_28 ) ) ) {
return error ;
}
V_21 = args -> V_21 ;
V_19 = args -> V_40 ;
V_5 = V_21 -> V_39 ;
V_35 = V_33 -> V_10 ;
V_9 = V_28 -> V_10 ;
F_18 ( V_21 , V_28 ) ;
V_62 = & V_35 -> V_43 [ V_53 ] ;
V_155 = F_41 ( V_5 , F_21 ( V_62 -> V_56 ) ) ;
V_63 = ( T_14 * )
( ( char * ) V_9 + F_85 ( V_5 , F_21 ( V_62 -> V_56 ) ) ) ;
V_38 = V_37 = 0 ;
V_156 = F_23 ( V_9 -> V_50 [ 0 ] . V_51 ) ;
V_36 = F_27 ( V_5 , V_35 ) ;
V_29 = F_28 ( V_36 ) ;
ASSERT ( F_23 ( V_29 [ V_155 ] ) == V_156 ) ;
F_24 ( V_19 , V_28 ,
( V_44 ) ( ( char * ) V_63 - ( char * ) V_9 ) ,
F_40 ( V_63 -> V_71 ) , & V_37 , & V_38 ) ;
F_34 ( & V_35 -> V_9 . V_42 , 1 ) ;
F_58 ( V_19 , V_33 ) ;
V_62 -> V_56 = F_25 ( V_57 ) ;
F_22 ( V_19 , V_33 , V_53 , V_53 ) ;
if ( V_38 )
F_26 ( V_5 , V_9 , & V_37 ) ;
if ( V_37 )
F_29 ( V_19 , V_28 ) ;
if ( F_23 ( V_9 -> V_50 [ 0 ] . V_51 ) != V_156 ) {
V_29 [ V_155 ] = V_9 -> V_50 [ 0 ] . V_51 ;
F_31 ( V_19 , V_33 , V_155 , V_155 ) ;
}
F_18 ( V_21 , V_28 ) ;
if ( F_23 ( V_9 -> V_50 [ 0 ] . V_51 ) ==
V_5 -> V_45 - ( V_127 ) sizeof( * V_9 ) ) {
ASSERT ( V_155 != V_5 -> V_157 ) ;
if ( ( error = F_89 ( args , V_155 , V_28 ) ) ) {
if ( error == V_78 && args -> V_77 == 0 )
error = 0 ;
F_30 ( V_21 , V_33 ) ;
return error ;
}
V_28 = NULL ;
if ( V_155 == F_21 ( V_36 -> V_49 ) - 1 ) {
for ( V_66 = V_155 - 1 ; V_66 > 0 ; V_66 -- ) {
if ( V_29 [ V_66 ] != F_5 ( V_73 ) )
break;
}
memmove ( & V_29 [ V_155 - V_66 ] , V_29 ,
( F_21 ( V_36 -> V_49 ) - ( V_155 - V_66 ) ) * sizeof( * V_29 ) ) ;
F_49 ( & V_36 -> V_49 , - ( V_155 - V_66 ) ) ;
F_50 ( V_19 , V_33 ) ;
F_31 ( V_19 , V_33 , 0 , F_21 ( V_36 -> V_49 ) - 1 ) ;
} else
V_29 [ V_155 ] = F_5 ( V_73 ) ;
}
else if ( V_155 != V_5 -> V_157 )
V_28 = NULL ;
F_30 ( V_21 , V_33 ) ;
return F_90 ( args , V_33 , V_28 ) ;
}
int
F_91 (
T_4 * args )
{
struct V_1 * V_28 ;
T_14 * V_63 ;
T_8 * V_21 ;
int error ;
int V_53 ;
struct V_1 * V_33 ;
T_10 * V_35 ;
T_6 * V_62 ;
T_13 * V_19 ;
F_92 ( args ) ;
if ( ( error = F_84 ( args , & V_33 , & V_53 , & V_28 ) ) ) {
return error ;
}
V_21 = args -> V_21 ;
V_35 = V_33 -> V_10 ;
V_62 = & V_35 -> V_43 [ V_53 ] ;
V_63 = ( T_14 * )
( ( char * ) V_28 -> V_10 +
F_85 ( V_21 -> V_39 , F_21 ( V_62 -> V_56 ) ) ) ;
ASSERT ( args -> V_81 != F_77 ( V_63 -> V_81 ) ) ;
V_63 -> V_81 = F_54 ( args -> V_81 ) ;
V_19 = args -> V_40 ;
F_56 ( V_19 , V_28 , V_63 ) ;
F_30 ( V_21 , V_33 ) ;
F_42 ( V_19 , V_33 ) ;
return 0 ;
}
int
F_39 (
T_4 * args ,
struct V_1 * V_33 )
{
T_20 V_158 = 0 ;
T_20 V_159 ;
int V_160 ;
int V_161 ;
T_10 * V_35 ;
T_6 * V_62 ;
int V_162 = 0 ;
V_35 = V_33 -> V_10 ;
#ifndef F_93
if ( ! V_35 -> V_9 . V_41 )
return 0 ;
#endif
for ( V_62 = V_35 -> V_43 , V_161 = 0 , V_160 = F_23 ( V_35 -> V_9 . V_41 ) - 1 ,
V_159 = args -> V_72 ;
V_161 <= V_160 ; ) {
V_162 = ( V_161 + V_160 ) >> 1 ;
if ( ( V_158 = F_21 ( V_62 [ V_162 ] . V_72 ) ) == V_159 )
break;
if ( V_158 < V_159 )
V_161 = V_162 + 1 ;
else
V_160 = V_162 - 1 ;
}
if ( V_158 == V_159 ) {
while ( V_162 > 0 && F_21 ( V_62 [ V_162 - 1 ] . V_72 ) == V_159 ) {
V_162 -- ;
}
}
else if ( V_158 < V_159 )
V_162 ++ ;
return V_162 ;
}
int
F_94 (
T_4 * args ,
struct V_1 * V_33 ,
T_9 V_155 )
{
T_1 * V_29 ;
struct V_1 * V_28 ;
T_8 * V_21 ;
int error ;
T_10 * V_35 ;
T_11 * V_36 ;
T_12 * V_5 ;
T_13 * V_19 ;
V_21 = args -> V_21 ;
V_5 = V_21 -> V_39 ;
V_19 = args -> V_40 ;
error = F_51 ( V_19 , V_21 , F_52 ( V_5 , V_155 ) , - 1 , & V_28 ) ;
if ( error )
return error ;
V_35 = V_33 -> V_10 ;
V_36 = F_27 ( V_5 , V_35 ) ;
#ifdef F_95
{
struct V_163 * V_9 = V_28 -> V_10 ;
ASSERT ( V_9 -> V_3 == F_25 ( V_48 ) ) ;
ASSERT ( F_23 ( V_9 -> V_50 [ 0 ] . V_51 ) ==
V_5 -> V_45 - ( V_127 ) sizeof( * V_9 ) ) ;
ASSERT ( V_155 == F_21 ( V_36 -> V_49 ) - 1 ) ;
}
#endif
if ( ( error = F_89 ( args , V_155 , V_28 ) ) ) {
ASSERT ( error != V_78 ) ;
F_42 ( V_19 , V_28 ) ;
return error ;
}
V_29 = F_28 ( V_36 ) ;
F_49 ( & V_36 -> V_49 , - 1 ) ;
memmove ( & V_29 [ 1 ] , & V_29 [ 0 ] , F_21 ( V_36 -> V_49 ) * sizeof( * V_29 ) ) ;
F_50 ( V_19 , V_33 ) ;
F_31 ( V_19 , V_33 , 0 , F_21 ( V_36 -> V_49 ) - 1 ) ;
return 0 ;
}
static inline T_16
F_96 (
struct V_8 * V_9 ,
int V_164 )
{
int V_165 ;
V_165 = F_23 ( V_9 -> V_41 ) - F_23 ( V_9 -> V_42 ) ;
return sizeof( V_166 ) +
V_165 * sizeof( T_6 ) +
V_164 * sizeof( V_74 ) +
sizeof( T_11 ) ;
}
int
F_97 (
T_21 * V_167 )
{
T_4 * args ;
T_8 * V_21 ;
int error ;
struct V_1 * V_168 ;
T_22 V_169 ;
T_23 * free ;
struct V_1 * V_33 ;
T_11 * V_36 ;
T_10 * V_35 ;
T_12 * V_5 ;
int V_170 ;
T_13 * V_19 ;
if ( V_167 -> V_171 . V_172 > 1 )
return 0 ;
args = V_167 -> args ;
F_98 ( args ) ;
V_5 = V_167 -> V_5 ;
V_21 = args -> V_21 ;
V_19 = args -> V_40 ;
if ( ( error = F_99 ( V_19 , V_21 , & V_169 , V_25 ) ) ) {
return error ;
}
V_169 -= V_5 -> V_101 ;
while ( V_169 > V_5 -> V_173 ) {
if ( ( error = F_100 ( args , V_169 , & V_170 ) ) ) {
return error ;
}
if ( V_170 )
V_169 -= V_5 -> V_101 ;
else
return 0 ;
}
if ( ( error = F_101 ( V_19 , V_21 , & V_169 , V_25 ) ) ) {
return error ;
}
if ( F_102 ( V_5 , V_169 ) > V_110 + V_5 -> V_45 )
return 0 ;
V_33 = V_167 -> V_171 . V_174 [ 0 ] . V_2 ;
V_35 = V_33 -> V_10 ;
ASSERT ( V_35 -> V_9 . V_12 . V_3 == F_5 ( V_17 ) ) ;
error = F_103 ( V_19 , V_21 , V_5 -> V_173 , & V_168 ) ;
if ( error )
return error ;
free = V_168 -> V_10 ;
ASSERT ( free -> V_9 . V_3 == F_25 ( V_175 ) ) ;
ASSERT ( ! free -> V_9 . V_176 ) ;
if ( F_96 ( & V_35 -> V_9 , F_21 ( free -> V_9 . V_177 ) ) >
V_5 -> V_45 ) {
F_42 ( V_19 , V_168 ) ;
return 0 ;
}
if ( F_23 ( V_35 -> V_9 . V_42 ) )
F_60 ( args , V_33 ) ;
else
F_58 ( V_19 , V_33 ) ;
V_33 -> V_46 = & V_26 ;
V_35 -> V_9 . V_12 . V_3 = F_5 ( V_16 ) ;
V_36 = F_27 ( V_5 , V_35 ) ;
V_36 -> V_49 = free -> V_9 . V_177 ;
memcpy ( F_28 ( V_36 ) , free -> V_178 ,
F_21 ( V_36 -> V_49 ) * sizeof( V_74 ) ) ;
F_31 ( V_19 , V_33 , 0 , F_21 ( V_36 -> V_49 ) - 1 ) ;
F_50 ( V_19 , V_33 ) ;
F_30 ( V_21 , V_33 ) ;
error = F_89 ( args , F_79 ( V_5 ) , V_168 ) ;
if ( error ) {
ASSERT ( error != V_78 ) ;
return error ;
}
V_168 = NULL ;
error = F_90 ( args , V_33 , NULL ) ;
V_167 -> V_171 . V_174 [ 0 ] . V_2 = NULL ;
return error ;
}
