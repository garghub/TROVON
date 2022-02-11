int
F_1 (
T_1 * args ,
struct V_1 * V_2 )
{
T_2 * V_3 ;
T_3 V_4 ;
T_4 * V_5 ;
T_5 * V_6 ;
T_6 * V_7 ;
T_7 * V_8 ;
int error ;
struct V_1 * V_9 ;
T_8 V_10 ;
T_9 * V_11 ;
T_10 * V_12 ;
T_11 * V_13 ;
int V_14 ;
int V_15 ;
T_12 * V_16 ;
F_2 ( args ) ;
V_8 = args -> V_8 ;
V_13 = V_8 -> V_17 ;
V_16 = args -> V_18 ;
if ( ( error = F_3 ( args , & V_4 ) ) ) {
return error ;
}
V_10 = F_4 ( V_13 , V_4 ) ;
ASSERT ( V_10 == F_5 ( V_13 ) ) ;
if ( ( error = F_6 ( args , V_10 , & V_9 , V_19 ) ) ) {
return error ;
}
ASSERT ( V_9 != NULL ) ;
V_11 = V_9 -> V_20 ;
V_5 = V_2 -> V_20 ;
F_7 ( V_8 , V_2 ) ;
V_7 = F_8 ( V_13 , V_5 ) ;
V_6 = F_9 ( V_7 ) ;
V_11 -> V_5 . V_21 = F_10 ( F_11 ( V_7 -> V_21 ) ) ;
V_11 -> V_5 . V_22 = F_10 ( F_11 ( V_7 -> V_22 ) ) ;
memcpy ( V_11 -> V_23 , V_6 , F_11 ( V_7 -> V_21 ) * sizeof( T_5 ) ) ;
F_12 ( V_16 , V_9 , 0 , F_13 ( V_11 -> V_5 . V_21 ) - 1 ) ;
V_15 = 0 ;
V_14 = 1 ;
F_14 ( V_16 , V_2 ,
( V_24 ) ( ( char * ) V_6 - ( char * ) V_5 ) ,
( V_24 ) ( ( char * ) V_5 + V_13 -> V_25 -
( char * ) V_6 ) ,
& V_14 , & V_15 ) ;
V_5 -> V_26 = F_15 ( V_27 ) ;
if ( V_15 )
F_16 ( V_13 , V_5 , & V_14 ) ;
V_12 = F_17 ( V_13 , V_11 ) ;
V_12 -> V_28 = F_15 ( 1 ) ;
V_3 = F_18 ( V_12 ) ;
V_3 [ 0 ] = V_5 -> V_29 [ 0 ] . V_30 ;
if ( V_14 )
F_19 ( V_16 , V_2 ) ;
F_20 ( V_8 , V_9 ) ;
F_7 ( V_8 , V_2 ) ;
F_21 ( V_16 , V_9 , 0 , 0 ) ;
return 0 ;
}
STATIC void
F_22 (
struct V_31 * V_11 ,
int V_32 ,
int * V_33 ,
int * V_34 )
{
for ( * V_33 = V_32 - 1 ; * V_33 >= 0 ; -- * V_33 ) {
if ( V_11 -> V_23 [ * V_33 ] . V_35 ==
F_15 ( V_36 ) )
break;
}
for ( * V_34 = V_32 ;
* V_34 < F_13 ( V_11 -> V_5 . V_21 ) ;
++ * V_34 ) {
if ( V_11 -> V_23 [ * V_34 ] . V_35 ==
F_15 ( V_36 ) )
break;
if ( * V_33 >= 0 && V_32 - * V_33 <= * V_34 - V_32 )
break;
}
}
struct V_37 *
F_23 (
T_9 * V_11 ,
int V_32 ,
int V_38 ,
int V_33 ,
int V_34 ,
int * V_39 ,
int * V_40 )
{
if ( ! V_11 -> V_5 . V_22 ) {
T_5 * V_41 ;
V_41 = & V_11 -> V_23 [ V_32 ] ;
if ( V_32 < F_13 ( V_11 -> V_5 . V_21 ) )
memmove ( V_41 + 1 , V_41 ,
( F_13 ( V_11 -> V_5 . V_21 ) - V_32 ) *
sizeof( * V_41 ) ) ;
* V_39 = V_32 ;
* V_40 = F_13 ( V_11 -> V_5 . V_21 ) ;
F_24 ( & V_11 -> V_5 . V_21 , 1 ) ;
return V_41 ;
}
if ( V_38 == 0 )
F_22 ( V_11 , V_32 , & V_33 , & V_34 ) ;
if ( V_33 >= 0 &&
( V_34 == F_13 ( V_11 -> V_5 . V_21 ) ||
V_32 - V_33 - 1 < V_34 - V_32 ) ) {
ASSERT ( V_32 - V_33 - 1 >= 0 ) ;
ASSERT ( V_11 -> V_23 [ V_33 ] . V_35 ==
F_15 ( V_36 ) ) ;
if ( V_32 - V_33 - 1 > 0 ) {
memmove ( & V_11 -> V_23 [ V_33 ] ,
& V_11 -> V_23 [ V_33 + 1 ] ,
( V_32 - V_33 - 1 ) *
sizeof( T_5 ) ) ;
}
* V_39 = F_25 ( V_33 , * V_39 ) ;
* V_40 = F_26 ( V_32 - 1 , * V_40 ) ;
F_24 ( & V_11 -> V_5 . V_22 , - 1 ) ;
return & V_11 -> V_23 [ V_32 - 1 ] ;
}
ASSERT ( V_34 - V_32 >= 0 ) ;
ASSERT ( V_11 -> V_23 [ V_34 ] . V_35 ==
F_15 ( V_36 ) ) ;
if ( V_34 - V_32 > 0 ) {
memmove ( & V_11 -> V_23 [ V_32 + 1 ] ,
& V_11 -> V_23 [ V_32 ] ,
( V_34 - V_32 ) * sizeof( T_5 ) ) ;
}
* V_39 = F_25 ( V_32 , * V_39 ) ;
* V_40 = F_26 ( V_34 , * V_40 ) ;
F_24 ( & V_11 -> V_5 . V_22 , - 1 ) ;
return & V_11 -> V_23 [ V_32 ] ;
}
int
F_27 (
T_1 * args )
{
T_2 * V_3 ;
int V_38 ;
T_4 * V_5 ;
struct V_1 * V_2 ;
T_13 * V_42 ;
T_7 * V_8 ;
T_14 * V_43 ;
int error ;
int V_44 ;
int V_34 ;
int V_45 ;
int V_32 ;
struct V_1 * V_9 ;
T_9 * V_11 ;
int V_30 ;
T_5 * V_41 ;
int V_39 ;
int V_40 ;
int V_33 ;
T_10 * V_12 ;
T_11 * V_13 ;
int V_46 ;
int V_14 ;
int V_15 ;
T_2 * V_47 ;
T_12 * V_16 ;
T_8 V_48 ;
F_28 ( args ) ;
V_8 = args -> V_8 ;
V_16 = args -> V_18 ;
V_13 = V_8 -> V_17 ;
error = F_29 ( V_16 , V_8 , V_13 -> V_49 , - 1 , & V_9 ,
V_50 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_9 != NULL ) ;
V_32 = F_30 ( args , V_9 ) ;
V_11 = V_9 -> V_20 ;
V_12 = F_17 ( V_13 , V_11 ) ;
V_3 = F_18 ( V_12 ) ;
V_30 = F_31 ( args -> V_51 ) ;
for ( V_48 = - 1 , V_41 = & V_11 -> V_23 [ V_32 ] ;
V_32 < F_13 ( V_11 -> V_5 . V_21 ) && F_11 ( V_41 -> V_52 ) == args -> V_52 ;
V_32 ++ , V_41 ++ ) {
if ( F_11 ( V_41 -> V_35 ) == V_36 )
continue;
V_45 = F_32 ( V_13 , F_11 ( V_41 -> V_35 ) ) ;
ASSERT ( V_45 < F_11 ( V_12 -> V_28 ) ) ;
ASSERT ( V_3 [ V_45 ] != F_10 ( V_53 ) ) ;
if ( F_13 ( V_3 [ V_45 ] ) >= V_30 ) {
V_48 = V_45 ;
break;
}
}
if ( V_48 == - 1 ) {
for ( V_45 = 0 ; V_45 < F_11 ( V_12 -> V_28 ) ; V_45 ++ ) {
if ( V_3 [ V_45 ] == F_10 ( V_53 ) &&
V_48 == - 1 )
V_48 = V_45 ;
else if ( F_13 ( V_3 [ V_45 ] ) >= V_30 ) {
V_48 = V_45 ;
break;
}
}
}
V_46 = 0 ;
if ( ! V_11 -> V_5 . V_22 )
V_46 += sizeof( T_5 ) ;
if ( V_48 == - 1 )
V_46 += sizeof( V_54 ) ;
if ( V_48 != - 1 && V_3 [ V_48 ] == F_10 ( V_53 ) )
V_48 = - 1 ;
if ( ( char * ) V_3 - ( char * ) & V_11 -> V_23 [ F_13 ( V_11 -> V_5 . V_21 ) ] <
V_46 && F_13 ( V_11 -> V_5 . V_22 ) > 1 ) {
V_38 = 1 ;
}
else if ( ( char * ) V_3 - ( char * ) & V_11 -> V_23 [ F_13 (
V_11 -> V_5 . V_21 ) ] < V_46 ) {
if ( ( args -> V_55 & V_56 ) ||
args -> V_57 == 0 ) {
F_33 ( V_16 , V_9 ) ;
return F_34 ( V_58 ) ;
}
error = F_35 ( args , V_9 ) ;
if ( error )
return error ;
return F_36 ( args ) ;
}
else
V_38 = 0 ;
if ( args -> V_55 & V_56 ) {
F_33 ( V_16 , V_9 ) ;
return V_48 == - 1 ? F_34 ( V_58 ) : 0 ;
}
if ( args -> V_57 == 0 && V_48 == - 1 ) {
F_33 ( V_16 , V_9 ) ;
return F_34 ( V_58 ) ;
}
if ( V_38 ) {
F_37 ( V_9 , & V_32 , & V_33 , & V_34 ,
& V_39 , & V_40 ) ;
}
else if ( F_13 ( V_11 -> V_5 . V_22 ) ) {
V_39 = F_13 ( V_11 -> V_5 . V_21 ) ;
V_40 = - 1 ;
}
if ( V_48 == - 1 ) {
if ( ( error = F_38 ( args , V_59 ,
& V_48 ) ) ) {
F_33 ( V_16 , V_9 ) ;
return error ;
}
if ( ( error = F_39 ( args , V_48 , & V_2 ) ) ) {
F_33 ( V_16 , V_9 ) ;
return error ;
}
if ( V_48 >= F_11 ( V_12 -> V_28 ) ) {
V_3 -- ;
memmove ( & V_3 [ 0 ] , & V_3 [ 1 ] ,
F_11 ( V_12 -> V_28 ) * sizeof( V_3 [ 0 ] ) ) ;
F_40 ( & V_12 -> V_28 , 1 ) ;
F_41 ( V_16 , V_9 ) ;
F_21 ( V_16 , V_9 , 0 , F_11 ( V_12 -> V_28 ) - 1 ) ;
}
else
F_21 ( V_16 , V_9 , V_48 , V_48 ) ;
V_5 = V_2 -> V_20 ;
V_3 [ V_48 ] = V_5 -> V_29 [ 0 ] . V_30 ;
V_44 = 1 ;
}
else {
if ( ( error =
F_29 ( V_16 , V_8 , F_42 ( V_13 , V_48 ) ,
- 1 , & V_2 , V_50 ) ) ) {
F_33 ( V_16 , V_9 ) ;
return error ;
}
V_5 = V_2 -> V_20 ;
V_44 = 0 ;
}
F_7 ( V_8 , V_2 ) ;
V_43 = ( T_14 * )
( ( char * ) V_5 + F_13 ( V_5 -> V_29 [ 0 ] . V_60 ) ) ;
ASSERT ( F_13 ( V_43 -> V_30 ) >= V_30 ) ;
V_15 = V_14 = 0 ;
F_43 ( V_16 , V_2 , V_43 ,
( V_24 ) ( ( char * ) V_43 - ( char * ) V_5 ) , V_30 ,
& V_14 , & V_15 ) ;
V_42 = ( T_13 * ) V_43 ;
V_42 -> V_61 = F_44 ( args -> V_61 ) ;
V_42 -> V_51 = args -> V_51 ;
memcpy ( V_42 -> V_62 , args -> V_62 , V_42 -> V_51 ) ;
V_47 = F_45 ( V_42 ) ;
* V_47 = F_10 ( ( char * ) V_42 - ( char * ) V_5 ) ;
if ( V_15 )
F_16 ( V_13 , V_5 , & V_14 ) ;
if ( V_14 )
F_19 ( V_16 , V_2 ) ;
F_46 ( V_16 , V_2 , V_42 ) ;
if ( F_13 ( V_3 [ V_48 ] ) != F_13 ( V_5 -> V_29 [ 0 ] . V_30 ) ) {
V_3 [ V_48 ] = V_5 -> V_29 [ 0 ] . V_30 ;
if ( ! V_44 )
F_21 ( V_16 , V_9 , V_48 , V_48 ) ;
}
V_41 = F_23 ( V_11 , V_32 , V_38 , V_33 ,
V_34 , & V_39 , & V_40 ) ;
V_41 -> V_52 = F_15 ( args -> V_52 ) ;
V_41 -> V_35 = F_15 ( F_47 ( V_13 , V_48 ,
F_13 ( * V_47 ) ) ) ;
F_48 ( V_16 , V_9 ) ;
F_12 ( V_16 , V_9 , V_39 , V_40 ) ;
F_20 ( V_8 , V_9 ) ;
F_7 ( V_8 , V_2 ) ;
return 0 ;
}
STATIC void
F_20 (
struct V_63 * V_8 ,
struct V_1 * V_64 )
{
int V_45 ;
T_9 * V_11 ;
T_10 * V_12 ;
T_11 * V_13 ;
int V_22 ;
V_11 = V_64 -> V_20 ;
V_13 = V_8 -> V_17 ;
ASSERT ( V_11 -> V_5 . V_65 . V_26 == F_10 ( V_19 ) ) ;
ASSERT ( F_13 ( V_11 -> V_5 . V_21 ) <= F_49 ( V_13 ) ) ;
V_12 = F_17 ( V_13 , V_11 ) ;
ASSERT ( ( char * ) & V_11 -> V_23 [ F_13 ( V_11 -> V_5 . V_21 ) ] <=
( char * ) F_18 ( V_12 ) ) ;
for ( V_45 = V_22 = 0 ; V_45 < F_13 ( V_11 -> V_5 . V_21 ) ; V_45 ++ ) {
if ( V_45 + 1 < F_13 ( V_11 -> V_5 . V_21 ) )
ASSERT ( F_11 ( V_11 -> V_23 [ V_45 ] . V_52 ) <=
F_11 ( V_11 -> V_23 [ V_45 + 1 ] . V_52 ) ) ;
if ( V_11 -> V_23 [ V_45 ] . V_35 == F_15 ( V_36 ) )
V_22 ++ ;
}
ASSERT ( F_13 ( V_11 -> V_5 . V_22 ) == V_22 ) ;
}
void
F_50 (
T_1 * args ,
struct V_1 * V_64 )
{
int V_66 ;
T_9 * V_11 ;
int V_67 ;
int V_68 ;
V_11 = V_64 -> V_20 ;
if ( ! V_11 -> V_5 . V_22 ) {
return;
}
for ( V_66 = V_68 = 0 , V_67 = - 1 ; V_66 < F_13 ( V_11 -> V_5 . V_21 ) ; V_66 ++ ) {
if ( V_11 -> V_23 [ V_66 ] . V_35 ==
F_15 ( V_36 ) )
continue;
if ( V_66 > V_68 ) {
if ( V_67 == - 1 )
V_67 = V_68 ;
V_11 -> V_23 [ V_68 ] = V_11 -> V_23 [ V_66 ] ;
}
V_68 ++ ;
}
ASSERT ( F_13 ( V_11 -> V_5 . V_22 ) == V_66 - V_68 ) ;
F_24 ( & V_11 -> V_5 . V_21 , - ( F_13 ( V_11 -> V_5 . V_22 ) ) ) ;
V_11 -> V_5 . V_22 = 0 ;
F_48 ( args -> V_18 , V_64 ) ;
if ( V_67 != - 1 )
F_12 ( args -> V_18 , V_64 , V_67 , V_68 - 1 ) ;
}
void
F_37 (
struct V_1 * V_64 ,
int * V_69 ,
int * V_70 ,
int * V_71 ,
int * V_72 ,
int * V_73 )
{
int V_66 ;
int V_34 ;
int V_32 ;
int V_74 ;
T_9 * V_11 ;
int V_33 ;
int V_75 = 0 ;
int V_68 ;
V_11 = V_64 -> V_20 ;
ASSERT ( F_13 ( V_11 -> V_5 . V_22 ) > 1 ) ;
V_32 = * V_69 ;
F_22 ( V_11 , V_32 , & V_33 , & V_34 ) ;
if ( V_33 >= 0 &&
( V_34 == F_13 ( V_11 -> V_5 . V_21 ) ||
V_32 - V_33 <= V_34 - V_32 ) )
V_74 = V_33 ;
else
V_74 = V_34 ;
for ( V_66 = V_68 = 0 ; V_66 < F_13 ( V_11 -> V_5 . V_21 ) ; V_66 ++ ) {
if ( V_32 == V_66 )
V_75 = V_68 ;
if ( V_66 != V_74 &&
V_11 -> V_23 [ V_66 ] . V_35 ==
F_15 ( V_36 ) ) {
if ( V_66 == V_68 )
* V_72 = V_68 ;
continue;
}
if ( V_66 == V_74 )
V_33 = V_34 = V_68 ;
if ( V_66 > V_68 )
V_11 -> V_23 [ V_68 ] = V_11 -> V_23 [ V_66 ] ;
V_68 ++ ;
}
ASSERT ( V_66 > V_68 ) ;
if ( V_32 == V_66 )
V_75 = V_68 ;
* V_69 = V_75 ;
F_24 ( & V_11 -> V_5 . V_21 , - ( V_66 - V_68 ) ) ;
V_11 -> V_5 . V_22 = F_10 ( 1 ) ;
if ( V_33 >= V_75 )
V_33 = - 1 ;
else
V_34 = F_13 ( V_11 -> V_5 . V_21 ) ;
* V_73 = F_13 ( V_11 -> V_5 . V_21 ) - 1 ;
* V_70 = V_33 ;
* V_71 = V_34 ;
}
STATIC int
F_51 (
struct V_63 * V_8 ,
T_15 V_76 ,
struct V_77 * V_78 ,
T_16 * V_79 ,
struct V_1 * * V_80 )
{
struct V_81 * V_13 = V_8 -> V_17 ;
struct V_1 * V_64 = * V_80 ;
struct V_82 * V_83 = V_78 -> V_83 ;
int error = 0 ;
int V_30 ;
int V_45 ;
int V_84 ;
if ( V_64 ) {
F_33 ( NULL , V_64 ) ;
V_64 = NULL ;
V_78 -> V_85 -= V_13 -> V_86 ;
for ( V_45 = V_13 -> V_86 ; V_45 > 0 ; ) {
V_84 = F_52 ( int , V_83 -> V_87 , V_45 ) ;
V_83 -> V_87 -= V_84 ;
V_83 -> V_88 += V_84 ;
V_83 -> V_89 += V_84 ;
if ( ! V_83 -> V_87 && -- V_78 -> V_90 )
memmove ( & V_83 [ 0 ] , & V_83 [ 1 ] ,
sizeof( V_83 [ 0 ] ) * V_78 -> V_90 ) ;
V_45 -= V_84 ;
}
}
V_78 -> V_91 = F_53 ( V_76 + V_13 -> V_25 ,
V_13 -> V_92 . V_93 ) - 1 ;
ASSERT ( V_78 -> V_91 >= 0 ) ;
if ( 1 + V_78 -> V_91 > V_78 -> V_85 &&
V_78 -> V_94 < F_54 ( V_13 , V_95 ) ) {
V_78 -> V_96 = V_78 -> V_97 - V_78 -> V_90 ;
error = F_55 ( V_8 , V_78 -> V_94 ,
F_54 ( V_13 , V_95 ) -
V_78 -> V_94 ,
& V_83 [ V_78 -> V_90 ] , & V_78 -> V_96 , 0 ) ;
if ( error )
goto V_98;
if ( V_78 -> V_96 == V_78 -> V_97 - V_78 -> V_90 ) {
V_45 = V_78 -> V_90 + V_78 -> V_96 - 1 ;
V_78 -> V_94 = V_83 [ V_45 ] . V_89 + V_83 [ V_45 ] . V_87 ;
} else
V_78 -> V_94 = F_54 ( V_13 ,
V_95 ) ;
for ( V_45 = V_78 -> V_90 ; V_45 < V_78 -> V_90 + V_78 -> V_96 ; ) {
if ( V_83 [ V_45 ] . V_88 == V_99 ) {
V_78 -> V_96 -- ;
V_30 = V_78 -> V_90 + V_78 -> V_96 - V_45 ;
if ( V_30 )
memmove ( & V_83 [ V_45 ] , & V_83 [ V_45 + 1 ] ,
sizeof( V_83 [ V_45 ] ) * V_30 ) ;
} else {
V_78 -> V_85 += V_83 [ V_45 ] . V_87 ;
V_45 ++ ;
}
}
V_78 -> V_90 += V_78 -> V_96 ;
}
if ( ! V_78 -> V_90 ) {
* V_79 = F_56 ( V_13 , V_78 -> V_94 ) ;
goto V_98;
}
V_78 -> V_100 = F_4 ( V_13 , V_83 -> V_89 ) ;
error = F_29 ( NULL , V_8 , V_83 -> V_89 ,
V_83 -> V_87 >= V_13 -> V_86 ?
F_57 ( V_13 , V_83 -> V_88 ) : - 1 ,
& V_64 , V_50 ) ;
if ( error )
goto V_98;
if ( V_78 -> V_101 )
V_78 -> V_101 -= V_13 -> V_86 ;
for ( V_78 -> V_102 = V_78 -> V_103 = V_45 = 0 ;
V_78 -> V_91 > V_78 -> V_101 && V_45 < V_78 -> V_85 ;
V_45 += V_13 -> V_86 ) {
ASSERT ( V_78 -> V_102 < V_78 -> V_90 ) ;
if ( V_45 > V_78 -> V_101 &&
V_83 [ V_78 -> V_102 ] . V_87 >= V_13 -> V_86 ) {
F_58 ( V_13 -> V_104 ,
F_57 ( V_13 ,
V_83 [ V_78 -> V_102 ] . V_88 +
V_78 -> V_103 ) ,
( int ) F_59 ( V_13 -> V_25 ) ) ;
V_78 -> V_101 = V_45 ;
}
else if ( V_45 > V_78 -> V_101 ) {
F_60 ( NULL , V_8 ,
V_83 [ V_78 -> V_102 ] . V_89 +
V_78 -> V_103 ,
V_50 ) ;
V_78 -> V_101 = V_45 ;
}
for ( V_84 = 0 ; V_84 < V_13 -> V_86 ; V_84 ++ ) {
V_30 = F_52 ( int , V_13 -> V_86 ,
V_83 [ V_78 -> V_102 ] . V_87 -
V_78 -> V_103 ) ;
V_84 += V_30 ;
V_78 -> V_103 += V_30 ;
if ( V_78 -> V_103 == V_83 [ V_78 -> V_102 ] . V_87 ) {
V_78 -> V_103 = 0 ;
V_78 -> V_102 ++ ;
}
}
}
V_98:
* V_80 = V_64 ;
return error ;
}
int
F_61 (
T_7 * V_8 ,
void * V_105 ,
T_15 V_76 ,
T_17 * V_60 ,
T_18 V_106 )
{
struct V_1 * V_64 = NULL ;
T_4 * V_5 ;
T_13 * V_42 ;
T_14 * V_43 ;
int error = 0 ;
int V_30 ;
T_11 * V_13 ;
int V_107 ;
T_16 V_79 ;
T_16 V_108 ;
char * V_109 = NULL ;
struct V_77 * V_110 ;
if ( * V_60 >= V_111 )
return 0 ;
V_13 = V_8 -> V_17 ;
V_30 = F_53 ( V_76 + V_13 -> V_25 ,
V_13 -> V_92 . V_93 ) ;
V_110 = F_62 ( F_63 ( struct V_77 , V_83 ) +
( V_30 * sizeof( struct V_82 ) ) ,
V_112 ) ;
V_110 -> V_97 = V_30 ;
V_79 = F_64 ( V_13 , * V_60 ) ;
V_110 -> V_94 = F_42 ( V_13 ,
F_65 ( V_13 , V_79 ) ) ;
while ( V_79 < V_95 ) {
if ( ! V_64 || V_109 >= ( char * ) V_64 -> V_20 + V_13 -> V_25 ) {
error = F_51 ( V_8 , V_76 , V_110 ,
& V_79 , & V_64 ) ;
if ( error || ! V_110 -> V_90 )
break;
V_108 = F_66 ( V_13 , V_110 -> V_100 , 0 ) ;
if ( V_79 < V_108 )
V_79 = V_108 ;
else if ( V_79 > V_108 )
ASSERT ( F_65 ( V_13 , V_79 ) ==
V_110 -> V_100 ) ;
V_5 = V_64 -> V_20 ;
F_7 ( V_8 , V_64 ) ;
V_109 = ( char * ) ( V_5 + 1 ) ;
V_107 = F_67 ( V_13 , V_79 ) ;
if ( V_107 == 0 )
V_79 += ( V_113 ) sizeof( * V_5 ) ;
else {
while ( ( char * ) V_109 - ( char * ) V_5 < V_107 ) {
V_43 = ( T_14 * ) V_109 ;
if ( F_13 ( V_43 -> V_114 )
== V_115 ) {
V_30 = F_13 ( V_43 -> V_30 ) ;
V_109 += V_30 ;
continue;
}
V_42 = ( T_13 * ) V_109 ;
V_30 =
F_31 ( V_42 -> V_51 ) ;
V_109 += V_30 ;
}
V_79 =
F_66 ( V_13 ,
F_65 ( V_13 , V_79 ) ,
( char * ) V_109 - ( char * ) V_5 ) ;
if ( V_109 >= ( char * ) V_5 + V_13 -> V_25 ) {
continue;
}
}
}
V_43 = ( T_14 * ) V_109 ;
if ( F_13 ( V_43 -> V_114 ) == V_115 ) {
V_30 = F_13 ( V_43 -> V_30 ) ;
V_109 += V_30 ;
V_79 += V_30 ;
continue;
}
V_42 = ( T_13 * ) V_109 ;
V_30 = F_31 ( V_42 -> V_51 ) ;
if ( V_106 ( V_105 , ( char * ) V_42 -> V_62 , V_42 -> V_51 ,
F_68 ( V_13 , V_79 ) & 0x7fffffff ,
F_69 ( V_42 -> V_61 ) , V_116 ) )
break;
V_109 += V_30 ;
V_79 += V_30 ;
V_76 = V_76 > V_30 ? V_76 - V_30 : 0 ;
}
if ( V_79 > F_64 ( V_13 , V_111 ) )
* V_60 = V_111 & 0x7fffffff ;
else
* V_60 = F_68 ( V_13 , V_79 ) & 0x7fffffff ;
F_70 ( V_110 ) ;
if ( V_64 )
F_33 ( NULL , V_64 ) ;
return error ;
}
int
F_6 (
T_1 * args ,
T_8 V_117 ,
struct V_1 * * V_80 ,
int V_26 )
{
struct V_1 * V_64 ;
T_7 * V_8 ;
int error ;
T_9 * V_11 ;
T_10 * V_12 ;
T_11 * V_13 ;
T_12 * V_16 ;
V_8 = args -> V_8 ;
ASSERT ( V_8 != NULL ) ;
V_16 = args -> V_18 ;
V_13 = V_8 -> V_17 ;
ASSERT ( V_117 >= F_5 ( V_13 ) &&
V_117 < F_71 ( V_13 ) ) ;
error = F_72 ( V_16 , V_8 , F_42 ( V_13 , V_117 ) , - 1 , & V_64 ,
V_50 ) ;
if ( error ) {
return error ;
}
ASSERT ( V_64 != NULL ) ;
V_11 = V_64 -> V_20 ;
V_11 -> V_5 . V_65 . V_26 = F_10 ( V_26 ) ;
V_11 -> V_5 . V_65 . V_118 = 0 ;
V_11 -> V_5 . V_65 . V_119 = 0 ;
V_11 -> V_5 . V_21 = 0 ;
V_11 -> V_5 . V_22 = 0 ;
F_48 ( V_16 , V_64 ) ;
if ( V_26 == V_19 ) {
V_12 = F_17 ( V_13 , V_11 ) ;
V_12 -> V_28 = 0 ;
F_41 ( V_16 , V_64 ) ;
}
* V_80 = V_64 ;
return 0 ;
}
static void
F_21 (
T_12 * V_16 ,
struct V_1 * V_64 ,
int V_120 ,
int V_121 )
{
T_2 * V_122 ;
T_2 * V_123 ;
T_9 * V_11 ;
T_10 * V_12 ;
V_11 = V_64 -> V_20 ;
ASSERT ( V_11 -> V_5 . V_65 . V_26 == F_10 ( V_19 ) ) ;
V_12 = F_17 ( V_16 -> V_124 , V_11 ) ;
V_122 = F_18 ( V_12 ) + V_120 ;
V_123 = F_18 ( V_12 ) + V_121 ;
F_73 ( V_16 , V_64 , ( V_113 ) ( ( char * ) V_122 - ( char * ) V_11 ) ,
( V_113 ) ( ( char * ) V_123 - ( char * ) V_11 + sizeof( * V_123 ) - 1 ) ) ;
}
void
F_12 (
T_12 * V_16 ,
struct V_1 * V_64 ,
int V_120 ,
int V_121 )
{
T_5 * V_125 ;
T_5 * V_126 ;
T_9 * V_11 ;
V_11 = V_64 -> V_20 ;
ASSERT ( V_11 -> V_5 . V_65 . V_26 == F_10 ( V_19 ) ||
V_11 -> V_5 . V_65 . V_26 == F_10 ( V_127 ) ) ;
V_125 = & V_11 -> V_23 [ V_120 ] ;
V_126 = & V_11 -> V_23 [ V_121 ] ;
F_73 ( V_16 , V_64 , ( V_113 ) ( ( char * ) V_125 - ( char * ) V_11 ) ,
( V_113 ) ( ( char * ) V_126 - ( char * ) V_11 + sizeof( * V_126 ) - 1 ) ) ;
}
void
F_48 (
struct V_128 * V_16 ,
struct V_1 * V_64 )
{
T_9 * V_11 ;
V_11 = V_64 -> V_20 ;
ASSERT ( V_11 -> V_5 . V_65 . V_26 == F_10 ( V_19 ) ||
V_11 -> V_5 . V_65 . V_26 == F_10 ( V_127 ) ) ;
F_73 ( V_16 , V_64 , ( V_113 ) ( ( char * ) & V_11 -> V_5 - ( char * ) V_11 ) ,
( V_113 ) ( sizeof( V_11 -> V_5 ) - 1 ) ) ;
}
STATIC void
F_41 (
struct V_128 * V_16 ,
struct V_1 * V_64 )
{
T_9 * V_11 ;
T_10 * V_12 ;
T_11 * V_13 ;
V_13 = V_16 -> V_124 ;
V_11 = V_64 -> V_20 ;
ASSERT ( V_11 -> V_5 . V_65 . V_26 == F_10 ( V_19 ) ) ;
V_12 = F_17 ( V_13 , V_11 ) ;
F_73 ( V_16 , V_64 , ( V_113 ) ( ( char * ) V_12 - ( char * ) V_11 ) ,
( V_113 ) ( V_13 -> V_25 - 1 ) ) ;
}
int
F_74 (
T_1 * args )
{
struct V_1 * V_2 ;
T_13 * V_42 ;
T_7 * V_8 ;
int error ;
int V_32 ;
struct V_1 * V_9 ;
T_9 * V_11 ;
T_5 * V_41 ;
T_12 * V_16 ;
F_75 ( args ) ;
if ( ( error = F_76 ( args , & V_9 , & V_32 , & V_2 ) ) ) {
return error ;
}
V_16 = args -> V_18 ;
V_8 = args -> V_8 ;
F_20 ( V_8 , V_9 ) ;
V_11 = V_9 -> V_20 ;
V_41 = & V_11 -> V_23 [ V_32 ] ;
V_42 = ( T_13 * )
( ( char * ) V_2 -> V_20 +
F_77 ( V_8 -> V_17 , F_11 ( V_41 -> V_35 ) ) ) ;
args -> V_61 = F_69 ( V_42 -> V_61 ) ;
error = F_78 ( args , V_42 -> V_62 , V_42 -> V_51 ) ;
F_33 ( V_16 , V_2 ) ;
F_33 ( V_16 , V_9 ) ;
return F_34 ( error ) ;
}
static int
F_76 (
T_1 * args ,
struct V_1 * * V_129 ,
int * V_69 ,
struct V_1 * * V_130 )
{
T_8 V_100 = - 1 ;
struct V_1 * V_2 = NULL ;
T_13 * V_42 ;
T_7 * V_8 ;
int error ;
int V_32 ;
struct V_1 * V_9 ;
T_5 * V_41 ;
T_9 * V_11 ;
T_11 * V_13 ;
T_8 V_131 ;
T_12 * V_16 ;
T_8 V_132 = - 1 ;
enum V_133 V_134 ;
V_8 = args -> V_8 ;
V_16 = args -> V_18 ;
V_13 = V_8 -> V_17 ;
error = F_29 ( V_16 , V_8 , V_13 -> V_49 , - 1 , & V_9 ,
V_50 ) ;
if ( error )
return error ;
* V_129 = V_9 ;
V_11 = V_9 -> V_20 ;
F_20 ( V_8 , V_9 ) ;
V_32 = F_30 ( args , V_9 ) ;
for ( V_41 = & V_11 -> V_23 [ V_32 ] ; V_32 < F_13 ( V_11 -> V_5 . V_21 ) &&
F_11 ( V_41 -> V_52 ) == args -> V_52 ;
V_41 ++ , V_32 ++ ) {
if ( F_11 ( V_41 -> V_35 ) == V_36 )
continue;
V_131 = F_32 ( V_13 , F_11 ( V_41 -> V_35 ) ) ;
if ( V_131 != V_100 ) {
if ( V_2 )
F_33 ( V_16 , V_2 ) ;
error = F_29 ( V_16 , V_8 ,
F_42 ( V_13 , V_131 ) ,
- 1 , & V_2 , V_50 ) ;
if ( error ) {
F_33 ( V_16 , V_9 ) ;
return error ;
}
F_7 ( V_8 , V_2 ) ;
V_100 = V_131 ;
}
V_42 = ( T_13 * ) ( ( char * ) V_2 -> V_20 +
F_77 ( V_13 , F_11 ( V_41 -> V_35 ) ) ) ;
V_134 = V_13 -> V_135 -> V_136 ( args , V_42 -> V_62 , V_42 -> V_51 ) ;
if ( V_134 != V_137 && V_134 != args -> V_138 ) {
args -> V_138 = V_134 ;
* V_69 = V_32 ;
if ( V_134 == V_139 ) {
* V_130 = V_2 ;
return 0 ;
}
V_132 = V_100 ;
}
}
ASSERT ( args -> V_55 & V_140 ) ;
if ( args -> V_138 == V_141 ) {
ASSERT ( V_132 != - 1 ) ;
if ( V_132 != V_100 ) {
F_33 ( V_16 , V_2 ) ;
error = F_29 ( V_16 , V_8 ,
F_42 ( V_13 , V_132 ) ,
- 1 , & V_2 , V_50 ) ;
if ( error ) {
F_33 ( V_16 , V_9 ) ;
return error ;
}
}
* V_130 = V_2 ;
return 0 ;
}
ASSERT ( V_132 == - 1 ) ;
if ( V_2 )
F_33 ( V_16 , V_2 ) ;
F_33 ( V_16 , V_9 ) ;
return F_34 ( V_142 ) ;
}
int
F_79 (
T_1 * args )
{
T_2 * V_3 ;
T_4 * V_5 ;
T_8 V_143 ;
struct V_1 * V_2 ;
T_13 * V_42 ;
T_7 * V_8 ;
int error ;
T_8 V_45 ;
int V_32 ;
struct V_1 * V_9 ;
T_9 * V_11 ;
T_5 * V_41 ;
T_10 * V_12 ;
T_11 * V_13 ;
int V_14 ;
int V_15 ;
V_54 V_144 ;
T_12 * V_16 ;
F_80 ( args ) ;
if ( ( error = F_76 ( args , & V_9 , & V_32 , & V_2 ) ) ) {
return error ;
}
V_8 = args -> V_8 ;
V_16 = args -> V_18 ;
V_13 = V_8 -> V_17 ;
V_11 = V_9 -> V_20 ;
V_5 = V_2 -> V_20 ;
F_7 ( V_8 , V_2 ) ;
V_41 = & V_11 -> V_23 [ V_32 ] ;
V_143 = F_32 ( V_13 , F_11 ( V_41 -> V_35 ) ) ;
V_42 = ( T_13 * )
( ( char * ) V_5 + F_77 ( V_13 , F_11 ( V_41 -> V_35 ) ) ) ;
V_15 = V_14 = 0 ;
V_144 = F_13 ( V_5 -> V_29 [ 0 ] . V_30 ) ;
V_12 = F_17 ( V_13 , V_11 ) ;
V_3 = F_18 ( V_12 ) ;
ASSERT ( F_13 ( V_3 [ V_143 ] ) == V_144 ) ;
F_14 ( V_16 , V_2 ,
( V_24 ) ( ( char * ) V_42 - ( char * ) V_5 ) ,
F_31 ( V_42 -> V_51 ) , & V_14 , & V_15 ) ;
F_24 ( & V_11 -> V_5 . V_22 , 1 ) ;
F_48 ( V_16 , V_9 ) ;
V_41 -> V_35 = F_15 ( V_36 ) ;
F_12 ( V_16 , V_9 , V_32 , V_32 ) ;
if ( V_15 )
F_16 ( V_13 , V_5 , & V_14 ) ;
if ( V_14 )
F_19 ( V_16 , V_2 ) ;
if ( F_13 ( V_5 -> V_29 [ 0 ] . V_30 ) != V_144 ) {
V_3 [ V_143 ] = V_5 -> V_29 [ 0 ] . V_30 ;
F_21 ( V_16 , V_9 , V_143 , V_143 ) ;
}
F_7 ( V_8 , V_2 ) ;
if ( F_13 ( V_5 -> V_29 [ 0 ] . V_30 ) ==
V_13 -> V_25 - ( V_113 ) sizeof( * V_5 ) ) {
ASSERT ( V_143 != V_13 -> V_145 ) ;
if ( ( error = F_81 ( args , V_143 , V_2 ) ) ) {
if ( error == V_58 && args -> V_57 == 0 )
error = 0 ;
F_20 ( V_8 , V_9 ) ;
return error ;
}
V_2 = NULL ;
if ( V_143 == F_11 ( V_12 -> V_28 ) - 1 ) {
for ( V_45 = V_143 - 1 ; V_45 > 0 ; V_45 -- ) {
if ( V_3 [ V_45 ] != F_10 ( V_53 ) )
break;
}
memmove ( & V_3 [ V_143 - V_45 ] , V_3 ,
( F_11 ( V_12 -> V_28 ) - ( V_143 - V_45 ) ) * sizeof( * V_3 ) ) ;
F_40 ( & V_12 -> V_28 , - ( V_143 - V_45 ) ) ;
F_41 ( V_16 , V_9 ) ;
F_21 ( V_16 , V_9 , 0 , F_11 ( V_12 -> V_28 ) - 1 ) ;
} else
V_3 [ V_143 ] = F_10 ( V_53 ) ;
}
else if ( V_143 != V_13 -> V_145 )
V_2 = NULL ;
F_20 ( V_8 , V_9 ) ;
return F_82 ( args , V_9 , V_2 ) ;
}
int
F_83 (
T_1 * args )
{
struct V_1 * V_2 ;
T_13 * V_42 ;
T_7 * V_8 ;
int error ;
int V_32 ;
struct V_1 * V_9 ;
T_9 * V_11 ;
T_5 * V_41 ;
T_12 * V_16 ;
F_84 ( args ) ;
if ( ( error = F_76 ( args , & V_9 , & V_32 , & V_2 ) ) ) {
return error ;
}
V_8 = args -> V_8 ;
V_11 = V_9 -> V_20 ;
V_41 = & V_11 -> V_23 [ V_32 ] ;
V_42 = ( T_13 * )
( ( char * ) V_2 -> V_20 +
F_77 ( V_8 -> V_17 , F_11 ( V_41 -> V_35 ) ) ) ;
ASSERT ( args -> V_61 != F_69 ( V_42 -> V_61 ) ) ;
V_42 -> V_61 = F_44 ( args -> V_61 ) ;
V_16 = args -> V_18 ;
F_46 ( V_16 , V_2 , V_42 ) ;
F_20 ( V_8 , V_9 ) ;
F_33 ( V_16 , V_9 ) ;
return 0 ;
}
int
F_30 (
T_1 * args ,
struct V_1 * V_9 )
{
T_19 V_146 = 0 ;
T_19 V_147 ;
int V_148 ;
int V_149 ;
T_9 * V_11 ;
T_5 * V_41 ;
int V_150 = 0 ;
V_11 = V_9 -> V_20 ;
#ifndef F_85
if ( ! V_11 -> V_5 . V_21 )
return 0 ;
#endif
for ( V_41 = V_11 -> V_23 , V_149 = 0 , V_148 = F_13 ( V_11 -> V_5 . V_21 ) - 1 ,
V_147 = args -> V_52 ;
V_149 <= V_148 ; ) {
V_150 = ( V_149 + V_148 ) >> 1 ;
if ( ( V_146 = F_11 ( V_41 [ V_150 ] . V_52 ) ) == V_147 )
break;
if ( V_146 < V_147 )
V_149 = V_150 + 1 ;
else
V_148 = V_150 - 1 ;
}
if ( V_146 == V_147 ) {
while ( V_150 > 0 && F_11 ( V_41 [ V_150 - 1 ] . V_52 ) == V_147 ) {
V_150 -- ;
}
}
else if ( V_146 < V_147 )
V_150 ++ ;
return V_150 ;
}
int
F_86 (
T_1 * args ,
struct V_1 * V_9 ,
T_8 V_143 )
{
T_2 * V_3 ;
struct V_1 * V_2 ;
T_7 * V_8 ;
int error ;
T_9 * V_11 ;
T_10 * V_12 ;
T_11 * V_13 ;
T_12 * V_16 ;
V_8 = args -> V_8 ;
V_13 = V_8 -> V_17 ;
V_16 = args -> V_18 ;
if ( ( error = F_29 ( V_16 , V_8 , F_42 ( V_13 , V_143 ) , - 1 , & V_2 ,
V_50 ) ) ) {
return error ;
}
V_11 = V_9 -> V_20 ;
V_12 = F_17 ( V_13 , V_11 ) ;
#ifdef F_87
{
struct V_151 * V_5 = V_2 -> V_20 ;
ASSERT ( V_5 -> V_26 == F_15 ( V_27 ) ) ;
ASSERT ( F_13 ( V_5 -> V_29 [ 0 ] . V_30 ) ==
V_13 -> V_25 - ( V_113 ) sizeof( * V_5 ) ) ;
ASSERT ( V_143 == F_11 ( V_12 -> V_28 ) - 1 ) ;
}
#endif
if ( ( error = F_81 ( args , V_143 , V_2 ) ) ) {
ASSERT ( error != V_58 ) ;
F_33 ( V_16 , V_2 ) ;
return error ;
}
V_3 = F_18 ( V_12 ) ;
F_40 ( & V_12 -> V_28 , - 1 ) ;
memmove ( & V_3 [ 1 ] , & V_3 [ 0 ] , F_11 ( V_12 -> V_28 ) * sizeof( * V_3 ) ) ;
F_41 ( V_16 , V_9 ) ;
F_21 ( V_16 , V_9 , 0 , F_11 ( V_12 -> V_28 ) - 1 ) ;
return 0 ;
}
static inline T_15
F_88 (
struct V_152 * V_5 ,
int V_153 )
{
int V_154 ;
V_154 = F_13 ( V_5 -> V_21 ) - F_13 ( V_5 -> V_22 ) ;
return sizeof( V_155 ) +
V_154 * sizeof( T_5 ) +
V_153 * sizeof( V_54 ) +
sizeof( T_10 ) ;
}
int
F_89 (
T_20 * V_156 )
{
T_1 * args ;
T_7 * V_8 ;
int error ;
struct V_1 * V_157 ;
T_21 V_158 ;
T_22 * free ;
struct V_1 * V_9 ;
T_10 * V_12 ;
T_9 * V_11 ;
T_11 * V_13 ;
int V_159 ;
T_12 * V_16 ;
if ( V_156 -> V_160 . V_161 > 1 )
return 0 ;
args = V_156 -> args ;
F_90 ( args ) ;
V_13 = V_156 -> V_13 ;
V_8 = args -> V_8 ;
V_16 = args -> V_18 ;
if ( ( error = F_91 ( V_16 , V_8 , & V_158 , V_50 ) ) ) {
return error ;
}
V_158 -= V_13 -> V_86 ;
while ( V_158 > V_13 -> V_162 ) {
if ( ( error = F_92 ( args , V_158 , & V_159 ) ) ) {
return error ;
}
if ( V_159 )
V_158 -= V_13 -> V_86 ;
else
return 0 ;
}
if ( ( error = F_93 ( V_16 , V_8 , & V_158 , V_50 ) ) ) {
return error ;
}
if ( F_94 ( V_13 , V_158 ) > V_95 + V_13 -> V_25 )
return 0 ;
V_9 = V_156 -> V_160 . V_163 [ 0 ] . V_64 ;
V_11 = V_9 -> V_20 ;
ASSERT ( V_11 -> V_5 . V_65 . V_26 == F_10 ( V_127 ) ) ;
if ( ( error = F_29 ( V_16 , V_8 , V_13 -> V_162 , - 1 , & V_157 ,
V_50 ) ) ) {
return error ;
}
free = V_157 -> V_20 ;
ASSERT ( free -> V_5 . V_26 == F_15 ( V_164 ) ) ;
ASSERT ( ! free -> V_5 . V_165 ) ;
if ( F_88 ( & V_11 -> V_5 , F_11 ( free -> V_5 . V_166 ) ) >
V_13 -> V_25 ) {
F_33 ( V_16 , V_157 ) ;
return 0 ;
}
if ( F_13 ( V_11 -> V_5 . V_22 ) )
F_50 ( args , V_9 ) ;
else
F_48 ( V_16 , V_9 ) ;
V_11 -> V_5 . V_65 . V_26 = F_10 ( V_19 ) ;
V_12 = F_17 ( V_13 , V_11 ) ;
V_12 -> V_28 = free -> V_5 . V_166 ;
memcpy ( F_18 ( V_12 ) , free -> V_167 ,
F_11 ( V_12 -> V_28 ) * sizeof( V_54 ) ) ;
F_21 ( V_16 , V_9 , 0 , F_11 ( V_12 -> V_28 ) - 1 ) ;
F_41 ( V_16 , V_9 ) ;
F_20 ( V_8 , V_9 ) ;
error = F_81 ( args , F_71 ( V_13 ) , V_157 ) ;
if ( error ) {
ASSERT ( error != V_58 ) ;
return error ;
}
V_157 = NULL ;
error = F_82 ( args , V_9 , NULL ) ;
V_156 -> V_160 . V_163 [ 0 ] . V_64 = NULL ;
return error ;
}
