int
F_1 (
T_1 * args ,
T_2 * V_1 )
{
T_3 * V_2 ;
T_4 V_3 ;
T_5 * V_4 ;
T_6 * V_5 ;
T_7 * V_6 ;
T_8 * V_7 ;
int error ;
T_2 * V_8 ;
T_9 V_9 ;
T_10 * V_10 ;
T_11 * V_11 ;
T_12 * V_12 ;
int V_13 ;
int V_14 ;
T_13 * V_15 ;
F_2 ( args ) ;
V_7 = args -> V_7 ;
V_12 = V_7 -> V_16 ;
V_15 = args -> V_17 ;
if ( ( error = F_3 ( args , & V_3 ) ) ) {
return error ;
}
V_9 = F_4 ( V_12 , V_3 ) ;
ASSERT ( V_9 == F_5 ( V_12 ) ) ;
if ( ( error = F_6 ( args , V_9 , & V_8 , V_18 ) ) ) {
return error ;
}
ASSERT ( V_8 != NULL ) ;
V_10 = V_8 -> V_19 ;
V_4 = V_1 -> V_19 ;
F_7 ( V_7 , V_1 ) ;
V_6 = F_8 ( V_12 , V_4 ) ;
V_5 = F_9 ( V_6 ) ;
V_10 -> V_4 . V_20 = F_10 ( F_11 ( V_6 -> V_20 ) ) ;
V_10 -> V_4 . V_21 = F_10 ( F_11 ( V_6 -> V_21 ) ) ;
memcpy ( V_10 -> V_22 , V_5 , F_11 ( V_6 -> V_20 ) * sizeof( T_6 ) ) ;
F_12 ( V_15 , V_8 , 0 , F_13 ( V_10 -> V_4 . V_20 ) - 1 ) ;
V_14 = 0 ;
V_13 = 1 ;
F_14 ( V_15 , V_1 ,
( V_23 ) ( ( char * ) V_5 - ( char * ) V_4 ) ,
( V_23 ) ( ( char * ) V_4 + V_12 -> V_24 -
( char * ) V_5 ) ,
& V_13 , & V_14 ) ;
V_4 -> V_25 = F_15 ( V_26 ) ;
if ( V_14 )
F_16 ( V_12 , V_4 , & V_13 ) ;
V_11 = F_17 ( V_12 , V_10 ) ;
V_11 -> V_27 = F_15 ( 1 ) ;
V_2 = F_18 ( V_11 ) ;
V_2 [ 0 ] = V_4 -> V_28 [ 0 ] . V_29 ;
if ( V_13 )
F_19 ( V_15 , V_1 ) ;
F_20 ( V_7 , V_8 ) ;
F_7 ( V_7 , V_1 ) ;
F_21 ( V_15 , V_8 , 0 , 0 ) ;
F_22 ( V_8 ) ;
return 0 ;
}
STATIC void
F_23 (
struct V_30 * V_10 ,
int V_31 ,
int * V_32 ,
int * V_33 )
{
for ( * V_32 = V_31 - 1 ; * V_32 >= 0 ; -- * V_32 ) {
if ( V_10 -> V_22 [ * V_32 ] . V_34 ==
F_15 ( V_35 ) )
break;
}
for ( * V_33 = V_31 ;
* V_33 < F_13 ( V_10 -> V_4 . V_20 ) ;
++ * V_33 ) {
if ( V_10 -> V_22 [ * V_33 ] . V_34 ==
F_15 ( V_35 ) )
break;
if ( * V_32 >= 0 && V_31 - * V_32 <= * V_33 - V_31 )
break;
}
}
struct V_36 *
F_24 (
T_10 * V_10 ,
int V_31 ,
int V_37 ,
int V_32 ,
int V_33 ,
int * V_38 ,
int * V_39 )
{
if ( ! V_10 -> V_4 . V_21 ) {
T_6 * V_40 ;
V_40 = & V_10 -> V_22 [ V_31 ] ;
if ( V_31 < F_13 ( V_10 -> V_4 . V_20 ) )
memmove ( V_40 + 1 , V_40 ,
( F_13 ( V_10 -> V_4 . V_20 ) - V_31 ) *
sizeof( * V_40 ) ) ;
* V_38 = V_31 ;
* V_39 = F_13 ( V_10 -> V_4 . V_20 ) ;
F_25 ( & V_10 -> V_4 . V_20 , 1 ) ;
return V_40 ;
}
if ( V_37 == 0 )
F_23 ( V_10 , V_31 , & V_32 , & V_33 ) ;
if ( V_32 >= 0 &&
( V_33 == F_13 ( V_10 -> V_4 . V_20 ) ||
V_31 - V_32 - 1 < V_33 - V_31 ) ) {
ASSERT ( V_31 - V_32 - 1 >= 0 ) ;
ASSERT ( V_10 -> V_22 [ V_32 ] . V_34 ==
F_15 ( V_35 ) ) ;
if ( V_31 - V_32 - 1 > 0 ) {
memmove ( & V_10 -> V_22 [ V_32 ] ,
& V_10 -> V_22 [ V_32 + 1 ] ,
( V_31 - V_32 - 1 ) *
sizeof( T_6 ) ) ;
}
* V_38 = F_26 ( V_32 , * V_38 ) ;
* V_39 = F_27 ( V_31 - 1 , * V_39 ) ;
F_25 ( & V_10 -> V_4 . V_21 , - 1 ) ;
return & V_10 -> V_22 [ V_31 - 1 ] ;
}
ASSERT ( V_33 - V_31 >= 0 ) ;
ASSERT ( V_10 -> V_22 [ V_33 ] . V_34 ==
F_15 ( V_35 ) ) ;
if ( V_33 - V_31 > 0 ) {
memmove ( & V_10 -> V_22 [ V_31 + 1 ] ,
& V_10 -> V_22 [ V_31 ] ,
( V_33 - V_31 ) * sizeof( T_6 ) ) ;
}
* V_38 = F_26 ( V_31 , * V_38 ) ;
* V_39 = F_27 ( V_33 , * V_39 ) ;
F_25 ( & V_10 -> V_4 . V_21 , - 1 ) ;
return & V_10 -> V_22 [ V_31 ] ;
}
int
F_28 (
T_1 * args )
{
T_3 * V_2 ;
int V_37 ;
T_5 * V_4 ;
T_2 * V_1 ;
T_14 * V_41 ;
T_8 * V_7 ;
T_15 * V_42 ;
int error ;
int V_43 ;
int V_33 ;
int V_44 ;
int V_31 ;
T_2 * V_8 ;
T_10 * V_10 ;
int V_29 ;
T_6 * V_40 ;
int V_38 ;
int V_39 ;
int V_32 ;
T_11 * V_11 ;
T_12 * V_12 ;
int V_45 ;
int V_13 ;
int V_14 ;
T_3 * V_46 ;
T_13 * V_15 ;
T_9 V_47 ;
F_29 ( args ) ;
V_7 = args -> V_7 ;
V_15 = args -> V_17 ;
V_12 = V_7 -> V_16 ;
error = F_30 ( V_15 , V_7 , V_12 -> V_48 , - 1 , & V_8 ,
V_49 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_8 != NULL ) ;
V_31 = F_31 ( args , V_8 ) ;
V_10 = V_8 -> V_19 ;
V_11 = F_17 ( V_12 , V_10 ) ;
V_2 = F_18 ( V_11 ) ;
V_29 = F_32 ( args -> V_50 ) ;
for ( V_47 = - 1 , V_40 = & V_10 -> V_22 [ V_31 ] ;
V_31 < F_13 ( V_10 -> V_4 . V_20 ) && F_11 ( V_40 -> V_51 ) == args -> V_51 ;
V_31 ++ , V_40 ++ ) {
if ( F_11 ( V_40 -> V_34 ) == V_35 )
continue;
V_44 = F_33 ( V_12 , F_11 ( V_40 -> V_34 ) ) ;
ASSERT ( V_44 < F_11 ( V_11 -> V_27 ) ) ;
ASSERT ( V_2 [ V_44 ] != F_10 ( V_52 ) ) ;
if ( F_13 ( V_2 [ V_44 ] ) >= V_29 ) {
V_47 = V_44 ;
break;
}
}
if ( V_47 == - 1 ) {
for ( V_44 = 0 ; V_44 < F_11 ( V_11 -> V_27 ) ; V_44 ++ ) {
if ( V_2 [ V_44 ] == F_10 ( V_52 ) &&
V_47 == - 1 )
V_47 = V_44 ;
else if ( F_13 ( V_2 [ V_44 ] ) >= V_29 ) {
V_47 = V_44 ;
break;
}
}
}
V_45 = 0 ;
if ( ! V_10 -> V_4 . V_21 )
V_45 += sizeof( T_6 ) ;
if ( V_47 == - 1 )
V_45 += sizeof( V_53 ) ;
if ( V_47 != - 1 && V_2 [ V_47 ] == F_10 ( V_52 ) )
V_47 = - 1 ;
if ( ( char * ) V_2 - ( char * ) & V_10 -> V_22 [ F_13 ( V_10 -> V_4 . V_20 ) ] <
V_45 && F_13 ( V_10 -> V_4 . V_21 ) > 1 ) {
V_37 = 1 ;
}
else if ( ( char * ) V_2 - ( char * ) & V_10 -> V_22 [ F_13 (
V_10 -> V_4 . V_20 ) ] < V_45 ) {
if ( ( args -> V_54 & V_55 ) ||
args -> V_56 == 0 ) {
F_34 ( V_15 , V_8 ) ;
return F_35 ( V_57 ) ;
}
error = F_36 ( args , V_8 ) ;
F_22 ( V_8 ) ;
if ( error )
return error ;
return F_37 ( args ) ;
}
else
V_37 = 0 ;
if ( args -> V_54 & V_55 ) {
F_34 ( V_15 , V_8 ) ;
return V_47 == - 1 ? F_35 ( V_57 ) : 0 ;
}
if ( args -> V_56 == 0 && V_47 == - 1 ) {
F_34 ( V_15 , V_8 ) ;
return F_35 ( V_57 ) ;
}
if ( V_37 ) {
F_38 ( V_8 , & V_31 , & V_32 , & V_33 ,
& V_38 , & V_39 ) ;
}
else if ( F_13 ( V_10 -> V_4 . V_21 ) ) {
V_38 = F_13 ( V_10 -> V_4 . V_20 ) ;
V_39 = - 1 ;
}
if ( V_47 == - 1 ) {
if ( ( error = F_39 ( args , V_58 ,
& V_47 ) ) ) {
F_34 ( V_15 , V_8 ) ;
return error ;
}
if ( ( error = F_40 ( args , V_47 , & V_1 ) ) ) {
F_34 ( V_15 , V_8 ) ;
return error ;
}
if ( V_47 >= F_11 ( V_11 -> V_27 ) ) {
V_2 -- ;
memmove ( & V_2 [ 0 ] , & V_2 [ 1 ] ,
F_11 ( V_11 -> V_27 ) * sizeof( V_2 [ 0 ] ) ) ;
F_41 ( & V_11 -> V_27 , 1 ) ;
F_42 ( V_15 , V_8 ) ;
F_21 ( V_15 , V_8 , 0 , F_11 ( V_11 -> V_27 ) - 1 ) ;
}
else
F_21 ( V_15 , V_8 , V_47 , V_47 ) ;
V_4 = V_1 -> V_19 ;
V_2 [ V_47 ] = V_4 -> V_28 [ 0 ] . V_29 ;
V_43 = 1 ;
}
else {
if ( ( error =
F_30 ( V_15 , V_7 , F_43 ( V_12 , V_47 ) ,
- 1 , & V_1 , V_49 ) ) ) {
F_34 ( V_15 , V_8 ) ;
return error ;
}
V_4 = V_1 -> V_19 ;
V_43 = 0 ;
}
F_7 ( V_7 , V_1 ) ;
V_42 = ( T_15 * )
( ( char * ) V_4 + F_13 ( V_4 -> V_28 [ 0 ] . V_59 ) ) ;
ASSERT ( F_13 ( V_42 -> V_29 ) >= V_29 ) ;
V_14 = V_13 = 0 ;
F_44 ( V_15 , V_1 , V_42 ,
( V_23 ) ( ( char * ) V_42 - ( char * ) V_4 ) , V_29 ,
& V_13 , & V_14 ) ;
V_41 = ( T_14 * ) V_42 ;
V_41 -> V_60 = F_45 ( args -> V_60 ) ;
V_41 -> V_50 = args -> V_50 ;
memcpy ( V_41 -> V_61 , args -> V_61 , V_41 -> V_50 ) ;
V_46 = F_46 ( V_41 ) ;
* V_46 = F_10 ( ( char * ) V_41 - ( char * ) V_4 ) ;
if ( V_14 )
F_16 ( V_12 , V_4 , & V_13 ) ;
if ( V_13 )
F_19 ( V_15 , V_1 ) ;
F_47 ( V_15 , V_1 , V_41 ) ;
if ( F_13 ( V_2 [ V_47 ] ) != F_13 ( V_4 -> V_28 [ 0 ] . V_29 ) ) {
V_2 [ V_47 ] = V_4 -> V_28 [ 0 ] . V_29 ;
if ( ! V_43 )
F_21 ( V_15 , V_8 , V_47 , V_47 ) ;
}
V_40 = F_24 ( V_10 , V_31 , V_37 , V_32 ,
V_33 , & V_38 , & V_39 ) ;
V_40 -> V_51 = F_15 ( args -> V_51 ) ;
V_40 -> V_34 = F_15 ( F_48 ( V_12 , V_47 ,
F_13 ( * V_46 ) ) ) ;
F_49 ( V_15 , V_8 ) ;
F_12 ( V_15 , V_8 , V_38 , V_39 ) ;
F_20 ( V_7 , V_8 ) ;
F_22 ( V_8 ) ;
F_7 ( V_7 , V_1 ) ;
F_22 ( V_1 ) ;
return 0 ;
}
STATIC void
F_20 (
T_8 * V_7 ,
T_2 * V_62 )
{
int V_44 ;
T_10 * V_10 ;
T_11 * V_11 ;
T_12 * V_12 ;
int V_21 ;
V_10 = V_62 -> V_19 ;
V_12 = V_7 -> V_16 ;
ASSERT ( V_10 -> V_4 . V_63 . V_25 == F_10 ( V_18 ) ) ;
ASSERT ( F_13 ( V_10 -> V_4 . V_20 ) <= F_50 ( V_12 ) ) ;
V_11 = F_17 ( V_12 , V_10 ) ;
ASSERT ( ( char * ) & V_10 -> V_22 [ F_13 ( V_10 -> V_4 . V_20 ) ] <=
( char * ) F_18 ( V_11 ) ) ;
for ( V_44 = V_21 = 0 ; V_44 < F_13 ( V_10 -> V_4 . V_20 ) ; V_44 ++ ) {
if ( V_44 + 1 < F_13 ( V_10 -> V_4 . V_20 ) )
ASSERT ( F_11 ( V_10 -> V_22 [ V_44 ] . V_51 ) <=
F_11 ( V_10 -> V_22 [ V_44 + 1 ] . V_51 ) ) ;
if ( V_10 -> V_22 [ V_44 ] . V_34 == F_15 ( V_35 ) )
V_21 ++ ;
}
ASSERT ( F_13 ( V_10 -> V_4 . V_21 ) == V_21 ) ;
}
void
F_51 (
T_1 * args ,
T_2 * V_62 )
{
int V_64 ;
T_10 * V_10 ;
int V_65 ;
int V_66 ;
V_10 = V_62 -> V_19 ;
if ( ! V_10 -> V_4 . V_21 ) {
return;
}
for ( V_64 = V_66 = 0 , V_65 = - 1 ; V_64 < F_13 ( V_10 -> V_4 . V_20 ) ; V_64 ++ ) {
if ( V_10 -> V_22 [ V_64 ] . V_34 ==
F_15 ( V_35 ) )
continue;
if ( V_64 > V_66 ) {
if ( V_65 == - 1 )
V_65 = V_66 ;
V_10 -> V_22 [ V_66 ] = V_10 -> V_22 [ V_64 ] ;
}
V_66 ++ ;
}
ASSERT ( F_13 ( V_10 -> V_4 . V_21 ) == V_64 - V_66 ) ;
F_25 ( & V_10 -> V_4 . V_20 , - ( F_13 ( V_10 -> V_4 . V_21 ) ) ) ;
V_10 -> V_4 . V_21 = 0 ;
F_49 ( args -> V_17 , V_62 ) ;
if ( V_65 != - 1 )
F_12 ( args -> V_17 , V_62 , V_65 , V_66 - 1 ) ;
}
void
F_38 (
T_2 * V_62 ,
int * V_67 ,
int * V_68 ,
int * V_69 ,
int * V_70 ,
int * V_71 )
{
int V_64 ;
int V_33 ;
int V_31 ;
int V_72 ;
T_10 * V_10 ;
int V_32 ;
int V_73 = 0 ;
int V_66 ;
V_10 = V_62 -> V_19 ;
ASSERT ( F_13 ( V_10 -> V_4 . V_21 ) > 1 ) ;
V_31 = * V_67 ;
F_23 ( V_10 , V_31 , & V_32 , & V_33 ) ;
if ( V_32 >= 0 &&
( V_33 == F_13 ( V_10 -> V_4 . V_20 ) ||
V_31 - V_32 <= V_33 - V_31 ) )
V_72 = V_32 ;
else
V_72 = V_33 ;
for ( V_64 = V_66 = 0 ; V_64 < F_13 ( V_10 -> V_4 . V_20 ) ; V_64 ++ ) {
if ( V_31 == V_64 )
V_73 = V_66 ;
if ( V_64 != V_72 &&
V_10 -> V_22 [ V_64 ] . V_34 ==
F_15 ( V_35 ) ) {
if ( V_64 == V_66 )
* V_70 = V_66 ;
continue;
}
if ( V_64 == V_72 )
V_32 = V_33 = V_66 ;
if ( V_64 > V_66 )
V_10 -> V_22 [ V_66 ] = V_10 -> V_22 [ V_64 ] ;
V_66 ++ ;
}
ASSERT ( V_64 > V_66 ) ;
if ( V_31 == V_64 )
V_73 = V_66 ;
* V_67 = V_73 ;
F_25 ( & V_10 -> V_4 . V_20 , - ( V_64 - V_66 ) ) ;
V_10 -> V_4 . V_21 = F_10 ( 1 ) ;
if ( V_32 >= V_73 )
V_32 = - 1 ;
else
V_33 = F_13 ( V_10 -> V_4 . V_20 ) ;
* V_71 = F_13 ( V_10 -> V_4 . V_20 ) - 1 ;
* V_68 = V_32 ;
* V_69 = V_33 ;
}
int
F_52 (
T_8 * V_7 ,
void * V_74 ,
T_16 V_75 ,
T_17 * V_59 ,
T_18 V_76 )
{
T_2 * V_62 ;
int V_77 ;
T_9 V_78 ;
T_19 V_79 ;
T_5 * V_4 ;
T_14 * V_41 ;
T_15 * V_42 ;
int error = 0 ;
int V_44 ;
int V_80 ;
int V_29 ;
T_20 * V_81 ;
T_21 V_82 ;
T_4 V_83 ;
int V_84 ;
int V_85 ;
T_12 * V_12 ;
T_19 V_86 ;
int V_87 ;
char * V_88 = NULL ;
int V_89 ;
int V_90 ;
int V_91 ;
int V_92 ;
if ( * V_59 >= V_93 )
return 0 ;
V_12 = V_7 -> V_16 ;
V_84 = F_53 ( V_75 + V_12 -> V_24 , V_12 -> V_94 . V_95 ) ;
V_81 = F_54 ( V_84 * sizeof( * V_81 ) , V_96 ) ;
V_85 = V_90 = V_91 = V_89 = V_82 = 0 ;
V_62 = NULL ;
V_79 = F_55 ( V_12 , * V_59 ) ;
V_83 = F_43 ( V_12 , F_56 ( V_12 , V_79 ) ) ;
while ( V_79 < V_97 ) {
if ( ! V_62 || V_88 >= ( char * ) V_62 -> V_19 + V_12 -> V_24 ) {
if ( V_62 ) {
F_34 ( NULL , V_62 ) ;
V_62 = NULL ;
V_82 -= V_12 -> V_98 ;
for ( V_44 = V_12 -> V_98 ; V_44 > 0 ; ) {
V_80 = F_26 ( ( int ) V_81 -> V_99 , V_44 ) ;
V_81 -> V_99 -= V_80 ;
V_81 -> V_100 += V_80 ;
V_81 -> V_101 += V_80 ;
if ( ! V_81 -> V_99 && -- V_85 )
memmove ( & V_81 [ 0 ] , & V_81 [ 1 ] ,
sizeof( V_81 [ 0 ] ) *
V_85 ) ;
V_44 -= V_80 ;
}
}
V_92 = F_53 ( V_75 + V_12 -> V_24 ,
V_12 -> V_94 . V_95 ) - 1 ;
ASSERT ( V_92 >= 0 ) ;
if ( 1 + V_92 > V_82 &&
V_83 <
F_57 ( V_12 , V_97 ) ) {
V_87 = V_84 - V_85 ;
error = F_58 ( V_7 , V_83 ,
F_57 ( V_12 ,
V_97 ) - V_83 ,
& V_81 [ V_85 ] , & V_87 , 0 ) ;
if ( error )
break;
if ( V_87 == V_84 - V_85 )
V_83 =
V_81 [ V_85 + V_87 - 1 ] . V_101 +
V_81 [ V_85 + V_87 - 1 ] . V_99 ;
else
V_83 =
F_57 ( V_12 ,
V_97 ) ;
for ( V_44 = V_85 ; V_44 < V_85 + V_87 ; ) {
if ( V_81 [ V_44 ] . V_100 ==
V_102 ) {
V_87 -- ;
V_29 = V_85 + V_87 - V_44 ;
if ( V_29 )
memmove ( & V_81 [ V_44 ] ,
& V_81 [ V_44 + 1 ] ,
sizeof( V_81 [ V_44 ] ) *
V_29 ) ;
} else {
V_82 +=
V_81 [ V_44 ] . V_99 ;
V_44 ++ ;
}
}
V_85 += V_87 ;
}
if ( ! V_85 ) {
V_79 = F_59 ( V_12 , V_83 ) ;
break;
}
V_78 = F_4 ( V_12 , V_81 -> V_101 ) ;
error = F_30 ( NULL , V_7 , V_81 -> V_101 ,
V_81 -> V_99 >= V_12 -> V_98 ?
F_60 ( V_12 , V_81 -> V_100 ) :
- 1 ,
& V_62 , V_49 ) ;
if ( error )
break;
if ( V_89 )
V_89 -= V_12 -> V_98 ;
for ( V_90 = V_91 = V_44 = 0 ;
V_92 > V_89 && V_44 < V_82 ;
V_44 += V_12 -> V_98 ) {
ASSERT ( V_90 < V_85 ) ;
if ( V_44 > V_89 &&
V_81 [ V_90 ] . V_99 >=
V_12 -> V_98 ) {
F_61 ( V_12 -> V_103 ,
F_60 ( V_12 ,
V_81 [ V_90 ] . V_100 +
V_91 ) ,
( int ) F_62 ( V_12 -> V_24 ) ) ;
V_89 = V_44 ;
}
else if ( V_44 > V_89 ) {
( void ) F_63 ( NULL , V_7 ,
V_81 [ V_90 ] . V_101 +
V_91 , V_49 ) ;
V_89 = V_44 ;
}
for ( V_80 = 0 ; V_80 < V_12 -> V_98 ; V_80 ++ ) {
V_29 = F_26 ( V_12 -> V_98 ,
( int ) ( V_81 [ V_90 ] . V_99 -
V_91 ) ) ;
V_80 += V_29 ;
V_91 += V_29 ;
if ( V_91 ==
V_81 [ V_90 ] . V_99 ) {
V_91 = 0 ;
V_90 ++ ;
}
}
}
V_86 = F_64 ( V_12 , V_78 , 0 ) ;
if ( V_79 < V_86 )
V_79 = V_86 ;
else if ( V_79 > V_86 )
ASSERT ( F_56 ( V_12 , V_79 ) ==
V_78 ) ;
V_4 = V_62 -> V_19 ;
F_7 ( V_7 , V_62 ) ;
V_88 = ( char * ) ( V_4 + 1 ) ;
V_77 = F_65 ( V_12 , V_79 ) ;
if ( V_77 == 0 )
V_79 += ( V_104 ) sizeof( * V_4 ) ;
else {
while ( ( char * ) V_88 - ( char * ) V_4 < V_77 ) {
V_42 = ( T_15 * ) V_88 ;
if ( F_13 ( V_42 -> V_105 )
== V_106 ) {
V_29 = F_13 ( V_42 -> V_29 ) ;
V_88 += V_29 ;
continue;
}
V_41 = ( T_14 * ) V_88 ;
V_29 =
F_32 ( V_41 -> V_50 ) ;
V_88 += V_29 ;
}
V_79 =
F_64 ( V_12 ,
F_56 ( V_12 , V_79 ) ,
( char * ) V_88 - ( char * ) V_4 ) ;
if ( V_88 >= ( char * ) V_4 + V_12 -> V_24 ) {
continue;
}
}
}
V_42 = ( T_15 * ) V_88 ;
if ( F_13 ( V_42 -> V_105 ) == V_106 ) {
V_29 = F_13 ( V_42 -> V_29 ) ;
V_88 += V_29 ;
V_79 += V_29 ;
continue;
}
V_41 = ( T_14 * ) V_88 ;
V_29 = F_32 ( V_41 -> V_50 ) ;
if ( V_76 ( V_74 , ( char * ) V_41 -> V_61 , V_41 -> V_50 ,
F_66 ( V_12 , V_79 ) & 0x7fffffff ,
F_67 ( V_41 -> V_60 ) , V_107 ) )
break;
V_88 += V_29 ;
V_79 += V_29 ;
V_75 = V_75 > V_29 ? V_75 - V_29 : 0 ;
}
if ( V_79 > F_55 ( V_12 , V_93 ) )
* V_59 = V_93 & 0x7fffffff ;
else
* V_59 = F_66 ( V_12 , V_79 ) & 0x7fffffff ;
F_68 ( V_81 ) ;
if ( V_62 )
F_34 ( NULL , V_62 ) ;
return error ;
}
int
F_6 (
T_1 * args ,
T_9 V_108 ,
T_2 * * V_109 ,
int V_25 )
{
T_2 * V_62 ;
T_8 * V_7 ;
int error ;
T_10 * V_10 ;
T_11 * V_11 ;
T_12 * V_12 ;
T_13 * V_15 ;
V_7 = args -> V_7 ;
ASSERT ( V_7 != NULL ) ;
V_15 = args -> V_17 ;
V_12 = V_7 -> V_16 ;
ASSERT ( V_108 >= F_5 ( V_12 ) &&
V_108 < F_69 ( V_12 ) ) ;
error = F_70 ( V_15 , V_7 , F_43 ( V_12 , V_108 ) , - 1 , & V_62 ,
V_49 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_62 != NULL ) ;
V_10 = V_62 -> V_19 ;
V_10 -> V_4 . V_63 . V_25 = F_10 ( V_25 ) ;
V_10 -> V_4 . V_63 . V_110 = 0 ;
V_10 -> V_4 . V_63 . V_111 = 0 ;
V_10 -> V_4 . V_20 = 0 ;
V_10 -> V_4 . V_21 = 0 ;
F_49 ( V_15 , V_62 ) ;
if ( V_25 == V_18 ) {
V_11 = F_17 ( V_12 , V_10 ) ;
V_11 -> V_27 = 0 ;
F_42 ( V_15 , V_62 ) ;
}
* V_109 = V_62 ;
return 0 ;
}
static void
F_21 (
T_13 * V_15 ,
T_2 * V_62 ,
int V_112 ,
int V_113 )
{
T_3 * V_114 ;
T_3 * V_115 ;
T_10 * V_10 ;
T_11 * V_11 ;
V_10 = V_62 -> V_19 ;
ASSERT ( V_10 -> V_4 . V_63 . V_25 == F_10 ( V_18 ) ) ;
V_11 = F_17 ( V_15 -> V_116 , V_10 ) ;
V_114 = F_18 ( V_11 ) + V_112 ;
V_115 = F_18 ( V_11 ) + V_113 ;
F_71 ( V_15 , V_62 , ( V_104 ) ( ( char * ) V_114 - ( char * ) V_10 ) ,
( V_104 ) ( ( char * ) V_115 - ( char * ) V_10 + sizeof( * V_115 ) - 1 ) ) ;
}
void
F_12 (
T_13 * V_15 ,
T_2 * V_62 ,
int V_112 ,
int V_113 )
{
T_6 * V_117 ;
T_6 * V_118 ;
T_10 * V_10 ;
V_10 = V_62 -> V_19 ;
ASSERT ( V_10 -> V_4 . V_63 . V_25 == F_10 ( V_18 ) ||
V_10 -> V_4 . V_63 . V_25 == F_10 ( V_119 ) ) ;
V_117 = & V_10 -> V_22 [ V_112 ] ;
V_118 = & V_10 -> V_22 [ V_113 ] ;
F_71 ( V_15 , V_62 , ( V_104 ) ( ( char * ) V_117 - ( char * ) V_10 ) ,
( V_104 ) ( ( char * ) V_118 - ( char * ) V_10 + sizeof( * V_118 ) - 1 ) ) ;
}
void
F_49 (
T_13 * V_15 ,
T_2 * V_62 )
{
T_10 * V_10 ;
V_10 = V_62 -> V_19 ;
ASSERT ( V_10 -> V_4 . V_63 . V_25 == F_10 ( V_18 ) ||
V_10 -> V_4 . V_63 . V_25 == F_10 ( V_119 ) ) ;
F_71 ( V_15 , V_62 , ( V_104 ) ( ( char * ) & V_10 -> V_4 - ( char * ) V_10 ) ,
( V_104 ) ( sizeof( V_10 -> V_4 ) - 1 ) ) ;
}
STATIC void
F_42 (
T_13 * V_15 ,
T_2 * V_62 )
{
T_10 * V_10 ;
T_11 * V_11 ;
T_12 * V_12 ;
V_12 = V_15 -> V_116 ;
V_10 = V_62 -> V_19 ;
ASSERT ( V_10 -> V_4 . V_63 . V_25 == F_10 ( V_18 ) ) ;
V_11 = F_17 ( V_12 , V_10 ) ;
F_71 ( V_15 , V_62 , ( V_104 ) ( ( char * ) V_11 - ( char * ) V_10 ) ,
( V_104 ) ( V_12 -> V_24 - 1 ) ) ;
}
int
F_72 (
T_1 * args )
{
T_2 * V_1 ;
T_14 * V_41 ;
T_8 * V_7 ;
int error ;
int V_31 ;
T_2 * V_8 ;
T_10 * V_10 ;
T_6 * V_40 ;
T_13 * V_15 ;
F_73 ( args ) ;
if ( ( error = F_74 ( args , & V_8 , & V_31 , & V_1 ) ) ) {
return error ;
}
V_15 = args -> V_17 ;
V_7 = args -> V_7 ;
F_20 ( V_7 , V_8 ) ;
V_10 = V_8 -> V_19 ;
V_40 = & V_10 -> V_22 [ V_31 ] ;
V_41 = ( T_14 * )
( ( char * ) V_1 -> V_19 +
F_75 ( V_7 -> V_16 , F_11 ( V_40 -> V_34 ) ) ) ;
args -> V_60 = F_67 ( V_41 -> V_60 ) ;
error = F_76 ( args , V_41 -> V_61 , V_41 -> V_50 ) ;
F_34 ( V_15 , V_1 ) ;
F_34 ( V_15 , V_8 ) ;
return F_35 ( error ) ;
}
static int
F_74 (
T_1 * args ,
T_2 * * V_120 ,
int * V_67 ,
T_2 * * V_121 )
{
T_9 V_78 = - 1 ;
T_2 * V_1 = NULL ;
T_14 * V_41 ;
T_8 * V_7 ;
int error ;
int V_31 ;
T_2 * V_8 ;
T_6 * V_40 ;
T_10 * V_10 ;
T_12 * V_12 ;
T_9 V_122 ;
T_13 * V_15 ;
T_9 V_123 = - 1 ;
enum V_124 V_125 ;
V_7 = args -> V_7 ;
V_15 = args -> V_17 ;
V_12 = V_7 -> V_16 ;
error = F_30 ( V_15 , V_7 , V_12 -> V_48 , - 1 , & V_8 ,
V_49 ) ;
if ( error )
return error ;
* V_120 = V_8 ;
V_10 = V_8 -> V_19 ;
F_20 ( V_7 , V_8 ) ;
V_31 = F_31 ( args , V_8 ) ;
for ( V_40 = & V_10 -> V_22 [ V_31 ] ; V_31 < F_13 ( V_10 -> V_4 . V_20 ) &&
F_11 ( V_40 -> V_51 ) == args -> V_51 ;
V_40 ++ , V_31 ++ ) {
if ( F_11 ( V_40 -> V_34 ) == V_35 )
continue;
V_122 = F_33 ( V_12 , F_11 ( V_40 -> V_34 ) ) ;
if ( V_122 != V_78 ) {
if ( V_1 )
F_34 ( V_15 , V_1 ) ;
error = F_30 ( V_15 , V_7 ,
F_43 ( V_12 , V_122 ) ,
- 1 , & V_1 , V_49 ) ;
if ( error ) {
F_34 ( V_15 , V_8 ) ;
return error ;
}
F_7 ( V_7 , V_1 ) ;
V_78 = V_122 ;
}
V_41 = ( T_14 * ) ( ( char * ) V_1 -> V_19 +
F_75 ( V_12 , F_11 ( V_40 -> V_34 ) ) ) ;
V_125 = V_12 -> V_126 -> V_127 ( args , V_41 -> V_61 , V_41 -> V_50 ) ;
if ( V_125 != V_128 && V_125 != args -> V_129 ) {
args -> V_129 = V_125 ;
* V_67 = V_31 ;
if ( V_125 == V_130 ) {
* V_121 = V_1 ;
return 0 ;
}
V_123 = V_78 ;
}
}
ASSERT ( args -> V_54 & V_131 ) ;
if ( args -> V_129 == V_132 ) {
ASSERT ( V_123 != - 1 ) ;
if ( V_123 != V_78 ) {
F_34 ( V_15 , V_1 ) ;
error = F_30 ( V_15 , V_7 ,
F_43 ( V_12 , V_123 ) ,
- 1 , & V_1 , V_49 ) ;
if ( error ) {
F_34 ( V_15 , V_8 ) ;
return error ;
}
}
* V_121 = V_1 ;
return 0 ;
}
ASSERT ( V_123 == - 1 ) ;
if ( V_1 )
F_34 ( V_15 , V_1 ) ;
F_34 ( V_15 , V_8 ) ;
return F_35 ( V_133 ) ;
}
int
F_77 (
T_1 * args )
{
T_3 * V_2 ;
T_5 * V_4 ;
T_9 V_134 ;
T_2 * V_1 ;
T_14 * V_41 ;
T_8 * V_7 ;
int error ;
T_9 V_44 ;
int V_31 ;
T_2 * V_8 ;
T_10 * V_10 ;
T_6 * V_40 ;
T_11 * V_11 ;
T_12 * V_12 ;
int V_13 ;
int V_14 ;
V_53 V_135 ;
T_13 * V_15 ;
F_78 ( args ) ;
if ( ( error = F_74 ( args , & V_8 , & V_31 , & V_1 ) ) ) {
return error ;
}
V_7 = args -> V_7 ;
V_15 = args -> V_17 ;
V_12 = V_7 -> V_16 ;
V_10 = V_8 -> V_19 ;
V_4 = V_1 -> V_19 ;
F_7 ( V_7 , V_1 ) ;
V_40 = & V_10 -> V_22 [ V_31 ] ;
V_134 = F_33 ( V_12 , F_11 ( V_40 -> V_34 ) ) ;
V_41 = ( T_14 * )
( ( char * ) V_4 + F_75 ( V_12 , F_11 ( V_40 -> V_34 ) ) ) ;
V_14 = V_13 = 0 ;
V_135 = F_13 ( V_4 -> V_28 [ 0 ] . V_29 ) ;
V_11 = F_17 ( V_12 , V_10 ) ;
V_2 = F_18 ( V_11 ) ;
ASSERT ( F_13 ( V_2 [ V_134 ] ) == V_135 ) ;
F_14 ( V_15 , V_1 ,
( V_23 ) ( ( char * ) V_41 - ( char * ) V_4 ) ,
F_32 ( V_41 -> V_50 ) , & V_13 , & V_14 ) ;
F_25 ( & V_10 -> V_4 . V_21 , 1 ) ;
F_49 ( V_15 , V_8 ) ;
V_40 -> V_34 = F_15 ( V_35 ) ;
F_12 ( V_15 , V_8 , V_31 , V_31 ) ;
if ( V_14 )
F_16 ( V_12 , V_4 , & V_13 ) ;
if ( V_13 )
F_19 ( V_15 , V_1 ) ;
if ( F_13 ( V_4 -> V_28 [ 0 ] . V_29 ) != V_135 ) {
V_2 [ V_134 ] = V_4 -> V_28 [ 0 ] . V_29 ;
F_21 ( V_15 , V_8 , V_134 , V_134 ) ;
}
F_7 ( V_7 , V_1 ) ;
if ( F_13 ( V_4 -> V_28 [ 0 ] . V_29 ) ==
V_12 -> V_24 - ( V_104 ) sizeof( * V_4 ) ) {
ASSERT ( V_134 != V_12 -> V_136 ) ;
if ( ( error = F_79 ( args , V_134 , V_1 ) ) ) {
if ( error == V_57 && args -> V_56 == 0 ) {
F_22 ( V_1 ) ;
error = 0 ;
}
F_20 ( V_7 , V_8 ) ;
F_22 ( V_8 ) ;
return error ;
}
V_1 = NULL ;
if ( V_134 == F_11 ( V_11 -> V_27 ) - 1 ) {
for ( V_44 = V_134 - 1 ; V_44 > 0 ; V_44 -- ) {
if ( V_2 [ V_44 ] != F_10 ( V_52 ) )
break;
}
memmove ( & V_2 [ V_134 - V_44 ] , V_2 ,
( F_11 ( V_11 -> V_27 ) - ( V_134 - V_44 ) ) * sizeof( * V_2 ) ) ;
F_41 ( & V_11 -> V_27 , - ( V_134 - V_44 ) ) ;
F_42 ( V_15 , V_8 ) ;
F_21 ( V_15 , V_8 , 0 , F_11 ( V_11 -> V_27 ) - 1 ) ;
} else
V_2 [ V_134 ] = F_10 ( V_52 ) ;
}
else if ( V_134 != V_12 -> V_136 && V_1 != NULL ) {
F_22 ( V_1 ) ;
V_1 = NULL ;
}
F_20 ( V_7 , V_8 ) ;
return F_80 ( args , V_8 , V_1 ) ;
}
int
F_81 (
T_1 * args )
{
T_2 * V_1 ;
T_14 * V_41 ;
T_8 * V_7 ;
int error ;
int V_31 ;
T_2 * V_8 ;
T_10 * V_10 ;
T_6 * V_40 ;
T_13 * V_15 ;
F_82 ( args ) ;
if ( ( error = F_74 ( args , & V_8 , & V_31 , & V_1 ) ) ) {
return error ;
}
V_7 = args -> V_7 ;
V_10 = V_8 -> V_19 ;
V_40 = & V_10 -> V_22 [ V_31 ] ;
V_41 = ( T_14 * )
( ( char * ) V_1 -> V_19 +
F_75 ( V_7 -> V_16 , F_11 ( V_40 -> V_34 ) ) ) ;
ASSERT ( args -> V_60 != F_67 ( V_41 -> V_60 ) ) ;
V_41 -> V_60 = F_45 ( args -> V_60 ) ;
V_15 = args -> V_17 ;
F_47 ( V_15 , V_1 , V_41 ) ;
F_22 ( V_1 ) ;
F_20 ( V_7 , V_8 ) ;
F_34 ( V_15 , V_8 ) ;
return 0 ;
}
int
F_31 (
T_1 * args ,
T_2 * V_8 )
{
T_22 V_137 = 0 ;
T_22 V_138 ;
int V_139 ;
int V_140 ;
T_10 * V_10 ;
T_6 * V_40 ;
int V_141 = 0 ;
V_10 = V_8 -> V_19 ;
#ifndef F_83
if ( ! V_10 -> V_4 . V_20 )
return 0 ;
#endif
for ( V_40 = V_10 -> V_22 , V_140 = 0 , V_139 = F_13 ( V_10 -> V_4 . V_20 ) - 1 ,
V_138 = args -> V_51 ;
V_140 <= V_139 ; ) {
V_141 = ( V_140 + V_139 ) >> 1 ;
if ( ( V_137 = F_11 ( V_40 [ V_141 ] . V_51 ) ) == V_138 )
break;
if ( V_137 < V_138 )
V_140 = V_141 + 1 ;
else
V_139 = V_141 - 1 ;
}
if ( V_137 == V_138 ) {
while ( V_141 > 0 && F_11 ( V_40 [ V_141 - 1 ] . V_51 ) == V_138 ) {
V_141 -- ;
}
}
else if ( V_137 < V_138 )
V_141 ++ ;
return V_141 ;
}
int
F_84 (
T_1 * args ,
T_2 * V_8 ,
T_9 V_134 )
{
T_3 * V_2 ;
T_2 * V_1 ;
T_8 * V_7 ;
int error ;
T_10 * V_10 ;
T_11 * V_11 ;
T_12 * V_12 ;
T_13 * V_15 ;
V_7 = args -> V_7 ;
V_12 = V_7 -> V_16 ;
V_15 = args -> V_17 ;
if ( ( error = F_30 ( V_15 , V_7 , F_43 ( V_12 , V_134 ) , - 1 , & V_1 ,
V_49 ) ) ) {
return error ;
}
V_10 = V_8 -> V_19 ;
V_11 = F_17 ( V_12 , V_10 ) ;
#ifdef F_85
{
struct V_142 * V_4 = V_1 -> V_19 ;
ASSERT ( V_4 -> V_25 == F_15 ( V_26 ) ) ;
ASSERT ( F_13 ( V_4 -> V_28 [ 0 ] . V_29 ) ==
V_12 -> V_24 - ( V_104 ) sizeof( * V_4 ) ) ;
ASSERT ( V_134 == F_11 ( V_11 -> V_27 ) - 1 ) ;
}
#endif
if ( ( error = F_79 ( args , V_134 , V_1 ) ) ) {
ASSERT ( error != V_57 ) ;
F_34 ( V_15 , V_1 ) ;
return error ;
}
V_2 = F_18 ( V_11 ) ;
F_41 ( & V_11 -> V_27 , - 1 ) ;
memmove ( & V_2 [ 1 ] , & V_2 [ 0 ] , F_11 ( V_11 -> V_27 ) * sizeof( * V_2 ) ) ;
F_42 ( V_15 , V_8 ) ;
F_21 ( V_15 , V_8 , 0 , F_11 ( V_11 -> V_27 ) - 1 ) ;
return 0 ;
}
static inline T_16
F_86 (
struct V_143 * V_4 ,
int V_144 )
{
int V_145 ;
V_145 = F_13 ( V_4 -> V_20 ) - F_13 ( V_4 -> V_21 ) ;
return sizeof( V_146 ) +
V_145 * sizeof( T_6 ) +
V_144 * sizeof( V_53 ) +
sizeof( T_11 ) ;
}
int
F_87 (
T_23 * V_147 )
{
T_1 * args ;
T_8 * V_7 ;
int error ;
T_2 * V_148 ;
T_24 V_149 ;
T_25 * free ;
T_2 * V_8 ;
T_11 * V_11 ;
T_10 * V_10 ;
T_12 * V_12 ;
int V_150 ;
T_13 * V_15 ;
if ( V_147 -> V_151 . V_152 > 1 )
return 0 ;
args = V_147 -> args ;
F_88 ( args ) ;
V_12 = V_147 -> V_12 ;
V_7 = args -> V_7 ;
V_15 = args -> V_17 ;
if ( ( error = F_89 ( V_15 , V_7 , & V_149 , V_49 ) ) ) {
return error ;
}
V_149 -= V_12 -> V_98 ;
while ( V_149 > V_12 -> V_153 ) {
if ( ( error = F_90 ( args , V_149 , & V_150 ) ) ) {
return error ;
}
if ( V_150 )
V_149 -= V_12 -> V_98 ;
else
return 0 ;
}
if ( ( error = F_91 ( V_15 , V_7 , & V_149 , V_49 ) ) ) {
return error ;
}
if ( F_92 ( V_12 , V_149 ) > V_97 + V_12 -> V_24 )
return 0 ;
V_8 = V_147 -> V_151 . V_154 [ 0 ] . V_62 ;
V_10 = V_8 -> V_19 ;
ASSERT ( V_10 -> V_4 . V_63 . V_25 == F_10 ( V_119 ) ) ;
if ( ( error = F_30 ( V_15 , V_7 , V_12 -> V_153 , - 1 , & V_148 ,
V_49 ) ) ) {
return error ;
}
free = V_148 -> V_19 ;
ASSERT ( free -> V_4 . V_25 == F_15 ( V_155 ) ) ;
ASSERT ( ! free -> V_4 . V_156 ) ;
if ( F_86 ( & V_10 -> V_4 , F_11 ( free -> V_4 . V_157 ) ) >
V_12 -> V_24 ) {
F_34 ( V_15 , V_148 ) ;
return 0 ;
}
if ( F_13 ( V_10 -> V_4 . V_21 ) )
F_51 ( args , V_8 ) ;
else
F_49 ( V_15 , V_8 ) ;
V_10 -> V_4 . V_63 . V_25 = F_10 ( V_18 ) ;
V_11 = F_17 ( V_12 , V_10 ) ;
V_11 -> V_27 = free -> V_4 . V_157 ;
memcpy ( F_18 ( V_11 ) , free -> V_158 ,
F_11 ( V_11 -> V_27 ) * sizeof( V_53 ) ) ;
F_21 ( V_15 , V_8 , 0 , F_11 ( V_11 -> V_27 ) - 1 ) ;
F_42 ( V_15 , V_8 ) ;
F_20 ( V_7 , V_8 ) ;
error = F_79 ( args , F_69 ( V_12 ) , V_148 ) ;
if ( error ) {
ASSERT ( error != V_57 ) ;
return error ;
}
V_148 = NULL ;
error = F_80 ( args , V_8 , NULL ) ;
V_147 -> V_151 . V_154 [ 0 ] . V_62 = NULL ;
return error ;
}
