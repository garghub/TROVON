int
F_1 ( T_1 * args , T_2 V_1 , int V_2 ,
struct V_3 * * V_4 , int V_5 )
{
T_3 * V_6 ;
struct V_3 * V_7 ;
int error ;
T_4 * V_8 ;
F_2 ( args ) ;
V_8 = args -> V_9 ;
error = F_3 ( V_8 , args -> V_10 , V_1 , - 1 , & V_7 , V_5 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_7 != NULL ) ;
V_6 = V_7 -> V_11 ;
V_6 -> V_12 . V_13 . V_14 = 0 ;
V_6 -> V_12 . V_13 . V_15 = 0 ;
V_6 -> V_12 . V_13 . V_16 = F_4 ( V_17 ) ;
V_6 -> V_12 . V_13 . V_18 = 0 ;
V_6 -> V_12 . V_19 = 0 ;
V_6 -> V_12 . V_2 = F_4 ( V_2 ) ;
F_5 ( V_8 , V_7 ,
F_6 ( V_6 , & V_6 -> V_12 , sizeof( V_6 -> V_12 ) ) ) ;
* V_4 = V_7 ;
return ( 0 ) ;
}
int
F_7 ( T_5 * V_20 )
{
T_6 * V_21 , * V_22 , * V_23 ;
T_3 * V_6 ;
struct V_3 * V_7 ;
int V_24 , V_25 , error , V_26 ;
F_8 ( V_20 -> args ) ;
V_24 = V_20 -> V_27 . V_28 - 1 ;
ASSERT ( ( V_24 >= 0 ) && ( V_24 < V_29 ) ) ;
ASSERT ( V_20 -> V_27 . V_30 [ V_24 ] . V_16 == V_31 ||
V_20 -> V_27 . V_30 [ V_24 ] . V_16 == V_32 ) ;
V_23 = & V_20 -> V_27 . V_30 [ V_24 ] ;
for ( V_26 = V_24 ; ( V_26 >= 0 ) && V_23 ; V_20 -> V_27 . V_28 -- , V_26 -- ) {
V_21 = & V_20 -> V_27 . V_30 [ V_26 ] ;
V_22 = & V_20 -> V_33 . V_30 [ V_26 ] ;
switch ( V_21 -> V_16 ) {
case V_31 :
error = F_9 ( V_20 , V_21 , V_22 ) ;
if ( ( error != 0 ) && ( error != V_34 ) ) {
return ( error ) ;
}
if ( ! error ) {
V_23 = V_22 ;
break;
}
V_20 -> V_35 = 1 ;
if ( V_20 -> V_36 ) {
V_20 -> V_37 = 0 ;
F_10 ( V_20 -> args ) ;
error = F_9 ( V_20 , V_21 ,
& V_20 -> V_38 ) ;
} else {
V_20 -> V_37 = 1 ;
F_11 ( V_20 -> args ) ;
error = F_9 ( V_20 , V_22 ,
& V_20 -> V_38 ) ;
}
if ( error )
return ( error ) ;
V_23 = V_22 ;
break;
case V_32 :
error = F_12 ( V_20 , V_21 , V_22 ) ;
if ( error )
return error ;
V_23 = V_22 ;
break;
case V_17 :
error = F_13 ( V_20 , V_21 , V_22 , V_23 ,
V_24 - V_26 , & V_25 ) ;
V_23 -> V_7 = NULL ;
if ( error )
return ( error ) ;
if ( V_25 )
V_23 = V_22 ;
else
V_23 = NULL ;
break;
}
F_14 ( V_20 , & V_20 -> V_27 ) ;
}
if ( ! V_23 )
return ( 0 ) ;
ASSERT ( V_20 -> V_27 . V_28 == 0 ) ;
V_21 = & V_20 -> V_27 . V_30 [ 0 ] ;
error = F_15 ( V_20 , V_21 , V_23 ) ;
if ( error ) {
V_23 -> V_7 = NULL ;
return ( error ) ;
}
V_6 = V_21 -> V_7 -> V_11 ;
if ( V_6 -> V_12 . V_13 . V_14 ) {
if ( F_16 ( V_6 -> V_12 . V_13 . V_14 ) == V_23 -> V_1 ) {
V_7 = V_23 -> V_7 ;
} else {
ASSERT ( V_20 -> V_35 ) ;
V_7 = V_20 -> V_38 . V_7 ;
}
V_6 = V_7 -> V_11 ;
V_6 -> V_12 . V_13 . V_15 = F_17 ( V_21 -> V_1 ) ;
F_5 ( V_20 -> args -> V_9 , V_7 ,
F_6 ( V_6 , & V_6 -> V_12 . V_13 ,
sizeof( V_6 -> V_12 . V_13 ) ) ) ;
}
V_6 = V_21 -> V_7 -> V_11 ;
if ( V_6 -> V_12 . V_13 . V_15 ) {
if ( F_16 ( V_6 -> V_12 . V_13 . V_15 ) == V_23 -> V_1 ) {
V_7 = V_23 -> V_7 ;
} else {
ASSERT ( V_20 -> V_35 ) ;
V_7 = V_20 -> V_38 . V_7 ;
}
V_6 = V_7 -> V_11 ;
V_6 -> V_12 . V_13 . V_14 = F_17 ( V_21 -> V_1 ) ;
F_5 ( V_20 -> args -> V_9 , V_7 ,
F_6 ( V_6 , & V_6 -> V_12 . V_13 ,
sizeof( V_6 -> V_12 . V_13 ) ) ) ;
}
V_23 -> V_7 = NULL ;
return ( 0 ) ;
}
STATIC int
F_15 ( T_5 * V_20 , T_6 * V_39 ,
T_6 * V_40 )
{
T_3 * V_6 , * V_41 ;
T_1 * args ;
T_2 V_1 ;
struct V_3 * V_7 ;
int error , V_42 ;
T_7 * V_10 ;
T_4 * V_8 ;
T_8 * V_43 ;
T_9 * V_44 ;
F_18 ( V_20 -> args ) ;
args = V_20 -> args ;
ASSERT ( args != NULL ) ;
error = F_19 ( args , & V_1 ) ;
if ( error )
return ( error ) ;
V_10 = args -> V_10 ;
V_8 = args -> V_9 ;
V_43 = V_20 -> V_43 ;
error = F_3 ( V_8 , V_10 , V_1 , - 1 , & V_7 , args -> V_5 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_7 != NULL ) ;
V_6 = V_7 -> V_11 ;
V_41 = V_39 -> V_7 -> V_11 ;
if ( V_41 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) {
V_42 = ( int ) ( ( char * ) & V_41 -> V_45 [ F_20 ( V_41 -> V_12 . V_19 ) ] -
( char * ) V_41 ) ;
} else {
ASSERT ( V_41 -> V_12 . V_13 . V_16 == F_4 ( V_32 ) ) ;
V_44 = ( T_9 * ) V_41 ;
V_42 = ( int ) ( ( char * ) & V_44 -> V_46 [ F_20 ( V_44 -> V_12 . V_19 ) ] -
( char * ) V_44 ) ;
}
memcpy ( V_6 , V_41 , V_42 ) ;
F_5 ( V_8 , V_7 , 0 , V_42 - 1 ) ;
V_39 -> V_7 = V_7 ;
V_39 -> V_1 = V_1 ;
error = F_1 ( args ,
( args -> V_5 == V_47 ) ? V_43 -> V_48 : 0 ,
F_20 ( V_6 -> V_12 . V_2 ) + 1 , & V_7 , args -> V_5 ) ;
if ( error )
return ( error ) ;
V_6 = V_7 -> V_11 ;
V_6 -> V_45 [ 0 ] . V_49 = F_17 ( V_39 -> V_49 ) ;
V_6 -> V_45 [ 0 ] . V_50 = F_17 ( V_39 -> V_1 ) ;
V_6 -> V_45 [ 1 ] . V_49 = F_17 ( V_40 -> V_49 ) ;
V_6 -> V_45 [ 1 ] . V_50 = F_17 ( V_40 -> V_1 ) ;
V_6 -> V_12 . V_19 = F_4 ( 2 ) ;
#ifdef F_21
if ( V_41 -> V_12 . V_13 . V_16 == F_4 ( V_32 ) ) {
ASSERT ( V_39 -> V_1 >= V_43 -> V_48 &&
V_39 -> V_1 < V_43 -> V_51 ) ;
ASSERT ( V_40 -> V_1 >= V_43 -> V_48 &&
V_40 -> V_1 < V_43 -> V_51 ) ;
}
#endif
F_5 ( V_8 , V_7 ,
F_6 ( V_6 , V_6 -> V_45 ,
sizeof( V_52 ) * 2 ) ) ;
return ( 0 ) ;
}
STATIC int
F_13 ( T_5 * V_20 , T_6 * V_21 ,
T_6 * V_22 ,
T_6 * V_23 ,
int V_53 , int * V_54 )
{
T_3 * V_6 ;
T_2 V_1 ;
int V_55 , error ;
int V_56 ;
F_22 ( V_20 -> args ) ;
V_6 = V_21 -> V_7 -> V_11 ;
ASSERT ( V_6 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
V_56 = V_20 -> V_35 && V_20 -> args -> V_5 == V_57 ;
V_55 = 1 + V_56 ;
if ( ( F_20 ( V_6 -> V_12 . V_19 ) + V_55 ) > V_20 -> V_58 ) {
error = F_19 ( V_20 -> args , & V_1 ) ;
if ( error )
return ( error ) ;
error = F_1 ( V_20 -> args , V_1 , V_53 ,
& V_22 -> V_7 , V_20 -> args -> V_5 ) ;
if ( error )
return ( error ) ;
V_22 -> V_1 = V_1 ;
V_22 -> V_16 = V_17 ;
F_23 ( V_20 , V_21 , V_22 ) ;
error = F_24 ( V_20 , V_21 , V_22 ) ;
if ( error )
return ( error ) ;
* V_54 = 1 ;
} else {
* V_54 = 0 ;
}
V_6 = V_21 -> V_7 -> V_11 ;
if ( V_21 -> V_59 <= F_20 ( V_6 -> V_12 . V_19 ) ) {
V_21 -> V_59 ++ ;
F_25 ( V_20 , V_21 , V_23 ) ;
if ( V_56 ) {
if ( V_20 -> V_37 )
V_21 -> V_59 ++ ;
F_25 ( V_20 , V_21 , & V_20 -> V_38 ) ;
V_20 -> V_35 = 0 ;
}
} else {
V_22 -> V_59 ++ ;
F_25 ( V_20 , V_22 , V_23 ) ;
if ( V_56 ) {
if ( V_20 -> V_37 )
V_22 -> V_59 ++ ;
F_25 ( V_20 , V_22 , & V_20 -> V_38 ) ;
V_20 -> V_35 = 0 ;
}
}
return ( 0 ) ;
}
STATIC void
F_23 ( T_5 * V_20 , T_6 * V_39 ,
T_6 * V_40 )
{
T_3 * V_60 , * V_61 , * V_62 ;
V_52 * V_63 , * V_64 ;
int V_19 , V_65 ;
T_4 * V_8 ;
F_26 ( V_20 -> args ) ;
V_60 = V_39 -> V_7 -> V_11 ;
V_61 = V_40 -> V_7 -> V_11 ;
if ( ( F_20 ( V_60 -> V_12 . V_19 ) > 0 ) && ( F_20 ( V_61 -> V_12 . V_19 ) > 0 ) &&
( ( F_16 ( V_61 -> V_45 [ 0 ] . V_49 ) < F_16 ( V_60 -> V_45 [ 0 ] . V_49 ) ) ||
( F_16 ( V_61 -> V_45 [ F_20 ( V_61 -> V_12 . V_19 ) - 1 ] . V_49 ) <
F_16 ( V_60 -> V_45 [ F_20 ( V_60 -> V_12 . V_19 ) - 1 ] . V_49 ) ) ) ) {
V_62 = V_60 ;
V_60 = V_61 ;
V_61 = V_62 ;
}
ASSERT ( V_60 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
ASSERT ( V_61 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
V_19 = ( F_20 ( V_60 -> V_12 . V_19 ) - F_20 ( V_61 -> V_12 . V_19 ) ) / 2 ;
if ( V_19 == 0 )
return;
V_8 = V_20 -> args -> V_9 ;
if ( V_19 > 0 ) {
if ( ( V_65 = F_20 ( V_61 -> V_12 . V_19 ) ) > 0 ) {
V_65 *= ( V_66 ) sizeof( V_52 ) ;
V_63 = & V_61 -> V_45 [ 0 ] ;
V_64 = & V_61 -> V_45 [ V_19 ] ;
memmove ( V_64 , V_63 , V_65 ) ;
}
F_27 ( & V_61 -> V_12 . V_19 , V_19 ) ;
V_65 = V_19 * ( V_66 ) sizeof( V_52 ) ;
V_63 = & V_60 -> V_45 [ F_20 ( V_60 -> V_12 . V_19 ) - V_19 ] ;
V_64 = & V_61 -> V_45 [ 0 ] ;
memcpy ( V_64 , V_63 , V_65 ) ;
F_27 ( & V_60 -> V_12 . V_19 , - V_19 ) ;
} else {
V_19 = - V_19 ;
V_65 = V_19 * ( V_66 ) sizeof( V_52 ) ;
V_63 = & V_61 -> V_45 [ 0 ] ;
V_64 = & V_60 -> V_45 [ F_20 ( V_60 -> V_12 . V_19 ) ] ;
memcpy ( V_64 , V_63 , V_65 ) ;
F_27 ( & V_60 -> V_12 . V_19 , V_19 ) ;
F_5 ( V_8 , V_39 -> V_7 ,
F_6 ( V_60 , V_64 , V_65 ) ) ;
V_65 = F_20 ( V_61 -> V_12 . V_19 ) - V_19 ;
V_65 *= ( V_66 ) sizeof( V_52 ) ;
V_63 = & V_61 -> V_45 [ V_19 ] ;
V_64 = & V_61 -> V_45 [ 0 ] ;
memmove ( V_64 , V_63 , V_65 ) ;
F_27 ( & V_61 -> V_12 . V_19 , - V_19 ) ;
}
F_5 ( V_8 , V_39 -> V_7 ,
F_6 ( V_60 , & V_60 -> V_12 , sizeof( V_60 -> V_12 ) ) ) ;
F_5 ( V_8 , V_40 -> V_7 ,
F_6 ( V_61 , & V_61 -> V_12 ,
sizeof( V_61 -> V_12 ) +
sizeof( V_61 -> V_45 [ 0 ] ) * F_20 ( V_61 -> V_12 . V_19 ) ) ) ;
V_60 = V_39 -> V_7 -> V_11 ;
V_61 = V_40 -> V_7 -> V_11 ;
V_39 -> V_49 = F_16 ( V_60 -> V_45 [ F_20 ( V_60 -> V_12 . V_19 ) - 1 ] . V_49 ) ;
V_40 -> V_49 = F_16 ( V_61 -> V_45 [ F_20 ( V_61 -> V_12 . V_19 ) - 1 ] . V_49 ) ;
if ( V_39 -> V_59 >= F_20 ( V_60 -> V_12 . V_19 ) ) {
V_40 -> V_59 = V_39 -> V_59 - F_20 ( V_60 -> V_12 . V_19 ) ;
V_39 -> V_59 = F_20 ( V_60 -> V_12 . V_19 ) + 1 ;
}
}
STATIC void
F_25 ( T_5 * V_20 , T_6 * V_21 ,
T_6 * V_22 )
{
T_3 * V_6 ;
V_52 * V_45 ;
int V_65 ;
F_28 ( V_20 -> args ) ;
V_6 = V_21 -> V_7 -> V_11 ;
ASSERT ( V_6 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
ASSERT ( ( V_21 -> V_59 >= 0 ) && ( V_21 -> V_59 <= F_20 ( V_6 -> V_12 . V_19 ) ) ) ;
ASSERT ( V_22 -> V_1 != 0 ) ;
if ( V_20 -> args -> V_5 == V_47 )
ASSERT ( V_22 -> V_1 >= V_20 -> V_43 -> V_48 &&
V_22 -> V_1 < V_20 -> V_43 -> V_51 ) ;
V_65 = 0 ;
V_45 = & V_6 -> V_45 [ V_21 -> V_59 ] ;
if ( V_21 -> V_59 < F_20 ( V_6 -> V_12 . V_19 ) ) {
V_65 = ( F_20 ( V_6 -> V_12 . V_19 ) - V_21 -> V_59 ) * ( V_66 ) sizeof( * V_45 ) ;
memmove ( V_45 + 1 , V_45 , V_65 ) ;
}
V_45 -> V_49 = F_17 ( V_22 -> V_49 ) ;
V_45 -> V_50 = F_17 ( V_22 -> V_1 ) ;
F_5 ( V_20 -> args -> V_9 , V_21 -> V_7 ,
F_6 ( V_6 , V_45 , V_65 + sizeof( * V_45 ) ) ) ;
F_27 ( & V_6 -> V_12 . V_19 , 1 ) ;
F_5 ( V_20 -> args -> V_9 , V_21 -> V_7 ,
F_6 ( V_6 , & V_6 -> V_12 , sizeof( V_6 -> V_12 ) ) ) ;
V_21 -> V_49 = F_16 ( V_6 -> V_45 [ F_20 ( V_6 -> V_12 . V_19 ) - 1 ] . V_49 ) ;
}
int
F_29 ( T_5 * V_20 )
{
T_6 * V_67 , * V_68 ;
int V_25 , error ;
F_30 ( V_20 -> args ) ;
V_25 = 0 ;
V_67 = & V_20 -> V_27 . V_30 [ V_20 -> V_27 . V_28 - 1 ] ;
V_68 = & V_20 -> V_33 . V_30 [ V_20 -> V_27 . V_28 - 1 ] ;
ASSERT ( V_20 -> V_27 . V_30 [ 0 ] . V_16 == V_17 ) ;
ASSERT ( V_67 -> V_16 == V_31 ||
V_67 -> V_16 == V_32 ) ;
for ( ; V_20 -> V_27 . V_28 >= 2 ; V_67 -- , V_68 -- ,
V_20 -> V_27 . V_28 -- ) {
switch ( V_67 -> V_16 ) {
case V_31 :
error = F_31 ( V_20 , & V_25 ) ;
if ( error )
return ( error ) ;
if ( V_25 == 0 )
return ( 0 ) ;
F_32 ( V_20 , V_67 , V_68 ) ;
break;
case V_32 :
error = F_33 ( V_20 , & V_25 ) ;
if ( error )
return error ;
if ( V_25 == 0 )
return 0 ;
F_34 ( V_20 , V_67 , V_68 ) ;
break;
case V_17 :
F_35 ( V_20 , V_67 ) ;
F_14 ( V_20 , & V_20 -> V_27 ) ;
error = F_36 ( V_20 , & V_25 ) ;
if ( error )
return ( error ) ;
if ( V_25 == 0 )
return 0 ;
F_37 ( V_20 , V_67 , V_68 ) ;
break;
}
F_14 ( V_20 , & V_20 -> V_33 ) ;
error = F_38 ( V_20 , V_67 , V_68 ) ;
F_39 ( V_20 ) ;
if ( error )
return ( error ) ;
error = F_40 ( V_20 -> args , V_67 -> V_1 ,
V_67 -> V_7 ) ;
V_67 -> V_7 = NULL ;
if ( error )
return ( error ) ;
}
F_35 ( V_20 , V_67 ) ;
F_14 ( V_20 , & V_20 -> V_27 ) ;
error = F_41 ( V_20 , & V_20 -> V_27 . V_30 [ 0 ] ) ;
return ( error ) ;
}
static void
F_42 ( struct V_69 * V_70 , T_10 V_2 )
{
T_11 V_16 = V_70 -> V_16 ;
if ( V_2 == 1 ) {
ASSERT ( V_16 == F_4 ( V_32 ) ||
V_16 == F_4 ( V_31 ) ) ;
} else
ASSERT ( V_16 == F_4 ( V_17 ) ) ;
ASSERT ( ! V_70 -> V_14 ) ;
ASSERT ( ! V_70 -> V_15 ) ;
}
STATIC int
F_41 ( T_5 * V_20 , T_6 * V_71 )
{
T_3 * V_41 ;
T_1 * args ;
T_2 V_72 ;
struct V_3 * V_7 ;
int error ;
F_43 ( V_20 -> args ) ;
args = V_20 -> args ;
ASSERT ( args != NULL ) ;
ASSERT ( V_71 -> V_16 == V_17 ) ;
V_41 = V_71 -> V_7 -> V_11 ;
ASSERT ( V_41 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
ASSERT ( ! V_41 -> V_12 . V_13 . V_14 ) ;
ASSERT ( ! V_41 -> V_12 . V_13 . V_15 ) ;
if ( F_20 ( V_41 -> V_12 . V_19 ) > 1 )
return ( 0 ) ;
V_72 = F_16 ( V_41 -> V_45 [ 0 ] . V_50 ) ;
ASSERT ( V_72 != 0 ) ;
error = F_44 ( args -> V_9 , args -> V_10 , V_72 , - 1 , & V_7 ,
args -> V_5 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_7 != NULL ) ;
F_42 ( V_7 -> V_11 ,
F_20 ( V_41 -> V_12 . V_2 ) ) ;
memcpy ( V_71 -> V_7 -> V_11 , V_7 -> V_11 , V_20 -> V_73 ) ;
F_5 ( args -> V_9 , V_71 -> V_7 , 0 , V_20 -> V_73 - 1 ) ;
error = F_40 ( args , V_72 , V_7 ) ;
return ( error ) ;
}
STATIC int
F_36 ( T_5 * V_20 , int * V_25 )
{
T_3 * V_6 ;
T_6 * V_30 ;
T_12 * V_13 ;
int V_19 , V_74 , error , V_75 , V_26 ;
T_2 V_1 ;
struct V_3 * V_7 ;
V_30 = & V_20 -> V_27 . V_30 [ V_20 -> V_27 . V_28 - 1 ] ;
V_13 = V_30 -> V_7 -> V_11 ;
ASSERT ( V_13 -> V_16 == F_4 ( V_17 ) ) ;
V_6 = ( T_3 * ) V_13 ;
V_19 = F_20 ( V_6 -> V_12 . V_19 ) ;
if ( V_19 > ( V_20 -> V_58 >> 1 ) ) {
* V_25 = 0 ;
return ( 0 ) ;
}
if ( V_19 == 0 ) {
V_74 = ( V_13 -> V_14 != 0 ) ;
memcpy ( & V_20 -> V_33 , & V_20 -> V_27 , sizeof( V_20 -> V_27 ) ) ;
error = F_45 ( V_20 , & V_20 -> V_33 , V_74 ,
0 , & V_75 ) ;
if ( error )
return ( error ) ;
if ( V_75 ) {
* V_25 = 0 ;
} else {
* V_25 = 2 ;
}
return ( 0 ) ;
}
V_74 = ( F_16 ( V_13 -> V_14 ) < F_16 ( V_13 -> V_15 ) ) ;
for ( V_26 = 0 ; V_26 < 2 ; V_74 = ! V_74 , V_26 ++ ) {
if ( V_74 )
V_1 = F_16 ( V_13 -> V_14 ) ;
else
V_1 = F_16 ( V_13 -> V_15 ) ;
if ( V_1 == 0 )
continue;
error = F_44 ( V_20 -> args -> V_9 , V_20 -> args -> V_10 ,
V_1 , - 1 , & V_7 , V_20 -> args -> V_5 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_7 != NULL ) ;
V_6 = ( T_3 * ) V_13 ;
V_19 = V_20 -> V_58 ;
V_19 -= V_20 -> V_58 >> 2 ;
V_19 -= F_20 ( V_6 -> V_12 . V_19 ) ;
V_6 = V_7 -> V_11 ;
ASSERT ( V_6 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
V_19 -= F_20 ( V_6 -> V_12 . V_19 ) ;
F_46 ( V_20 -> args -> V_9 , V_7 ) ;
if ( V_19 >= 0 )
break;
}
if ( V_26 >= 2 ) {
* V_25 = 0 ;
return ( 0 ) ;
}
memcpy ( & V_20 -> V_33 , & V_20 -> V_27 , sizeof( V_20 -> V_27 ) ) ;
if ( V_1 < V_30 -> V_1 ) {
error = F_45 ( V_20 , & V_20 -> V_33 , V_74 ,
0 , & V_75 ) ;
if ( error ) {
return ( error ) ;
}
if ( V_75 ) {
* V_25 = 0 ;
return ( 0 ) ;
}
} else {
error = F_45 ( V_20 , & V_20 -> V_27 , V_74 ,
0 , & V_75 ) ;
if ( error ) {
return ( error ) ;
}
if ( V_75 ) {
* V_25 = 0 ;
return ( 0 ) ;
}
}
* V_25 = 1 ;
return ( 0 ) ;
}
void
F_14 ( T_5 * V_20 , T_13 * V_27 )
{
T_6 * V_30 ;
T_3 * V_6 ;
V_52 * V_45 ;
T_14 V_76 = 0 ;
int V_2 , V_19 ;
V_2 = V_27 -> V_28 - 1 ;
V_30 = & V_27 -> V_30 [ V_2 ] ;
switch ( V_30 -> V_16 ) {
case V_31 :
V_76 = F_47 ( V_30 -> V_7 , & V_19 ) ;
if ( V_19 == 0 )
return;
break;
case V_32 :
V_76 = F_48 ( V_30 -> V_7 , & V_19 ) ;
if ( V_19 == 0 )
return;
break;
case V_17 :
V_76 = F_49 ( V_30 -> V_7 , & V_19 ) ;
if ( V_19 == 0 )
return;
break;
}
for ( V_30 -- , V_2 -- ; V_2 >= 0 ; V_30 -- , V_2 -- ) {
V_6 = V_30 -> V_7 -> V_11 ;
ASSERT ( V_6 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
V_45 = & V_6 -> V_45 [ V_30 -> V_59 ] ;
if ( F_16 ( V_45 -> V_49 ) == V_76 )
break;
V_30 -> V_49 = V_76 ;
V_45 -> V_49 = F_17 ( V_76 ) ;
F_5 ( V_20 -> args -> V_9 , V_30 -> V_7 ,
F_6 ( V_6 , V_45 , sizeof( * V_45 ) ) ) ;
V_76 = F_16 ( V_6 -> V_45 [ F_20 ( V_6 -> V_12 . V_19 ) - 1 ] . V_49 ) ;
}
}
STATIC void
F_35 ( T_5 * V_20 , T_6 * V_67 )
{
T_3 * V_6 ;
V_52 * V_45 ;
int V_65 ;
F_50 ( V_20 -> args ) ;
V_6 = V_67 -> V_7 -> V_11 ;
ASSERT ( V_67 -> V_59 < F_20 ( V_6 -> V_12 . V_19 ) ) ;
ASSERT ( V_67 -> V_59 >= 0 ) ;
V_45 = & V_6 -> V_45 [ V_67 -> V_59 ] ;
if ( V_67 -> V_59 < ( F_20 ( V_6 -> V_12 . V_19 ) - 1 ) ) {
V_65 = F_20 ( V_6 -> V_12 . V_19 ) - V_67 -> V_59 - 1 ;
V_65 *= ( V_66 ) sizeof( V_52 ) ;
memmove ( V_45 , V_45 + 1 , V_65 ) ;
F_5 ( V_20 -> args -> V_9 , V_67 -> V_7 ,
F_6 ( V_6 , V_45 , V_65 ) ) ;
V_45 = & V_6 -> V_45 [ F_20 ( V_6 -> V_12 . V_19 ) - 1 ] ;
}
memset ( ( char * ) V_45 , 0 , sizeof( V_52 ) ) ;
F_5 ( V_20 -> args -> V_9 , V_67 -> V_7 ,
F_6 ( V_6 , V_45 , sizeof( * V_45 ) ) ) ;
F_27 ( & V_6 -> V_12 . V_19 , - 1 ) ;
F_5 ( V_20 -> args -> V_9 , V_67 -> V_7 ,
F_6 ( V_6 , & V_6 -> V_12 , sizeof( V_6 -> V_12 ) ) ) ;
V_45 -- ;
V_67 -> V_49 = F_16 ( V_45 -> V_49 ) ;
}
STATIC void
F_37 ( T_5 * V_20 , T_6 * V_67 ,
T_6 * V_68 )
{
T_3 * V_77 , * V_78 ;
V_52 * V_45 ;
int V_65 ;
T_4 * V_8 ;
F_51 ( V_20 -> args ) ;
V_77 = V_67 -> V_7 -> V_11 ;
V_78 = V_68 -> V_7 -> V_11 ;
ASSERT ( V_77 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
ASSERT ( V_78 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
V_8 = V_20 -> args -> V_9 ;
if ( ( F_16 ( V_77 -> V_45 [ 0 ] . V_49 ) < F_16 ( V_78 -> V_45 [ 0 ] . V_49 ) ) ||
( F_16 ( V_77 -> V_45 [ F_20 ( V_77 -> V_12 . V_19 ) - 1 ] . V_49 ) <
F_16 ( V_78 -> V_45 [ F_20 ( V_78 -> V_12 . V_19 ) - 1 ] . V_49 ) ) )
{
V_45 = & V_78 -> V_45 [ F_20 ( V_77 -> V_12 . V_19 ) ] ;
V_65 = F_20 ( V_78 -> V_12 . V_19 ) * ( V_66 ) sizeof( V_52 ) ;
memmove ( V_45 , & V_78 -> V_45 [ 0 ] , V_65 ) ;
V_45 = & V_78 -> V_45 [ 0 ] ;
F_5 ( V_8 , V_68 -> V_7 ,
F_6 ( V_78 , V_45 ,
( F_20 ( V_78 -> V_12 . V_19 ) + F_20 ( V_77 -> V_12 . V_19 ) ) *
sizeof( V_52 ) ) ) ;
} else {
V_45 = & V_78 -> V_45 [ F_20 ( V_78 -> V_12 . V_19 ) ] ;
F_5 ( V_8 , V_68 -> V_7 ,
F_6 ( V_78 , V_45 ,
F_20 ( V_77 -> V_12 . V_19 ) *
sizeof( V_52 ) ) ) ;
}
V_65 = F_20 ( V_77 -> V_12 . V_19 ) * ( V_66 ) sizeof( V_52 ) ;
memcpy ( V_45 , & V_77 -> V_45 [ 0 ] , V_65 ) ;
F_27 ( & V_78 -> V_12 . V_19 , F_20 ( V_77 -> V_12 . V_19 ) ) ;
F_5 ( V_8 , V_68 -> V_7 ,
F_6 ( V_78 , & V_78 -> V_12 ,
sizeof( V_78 -> V_12 ) ) ) ;
V_68 -> V_49 = F_16 ( V_78 -> V_45 [ F_20 ( V_78 -> V_12 . V_19 ) - 1 ] . V_49 ) ;
}
int
F_52 ( T_5 * V_20 , int * V_54 )
{
T_6 * V_30 ;
T_12 * V_79 ;
T_3 * V_6 ;
V_52 * V_45 ;
T_2 V_1 ;
int V_80 , V_81 , V_24 , error , V_75 ;
T_14 V_49 , V_82 ;
T_1 * args ;
args = V_20 -> args ;
V_1 = ( args -> V_5 == V_47 ) ? V_20 -> V_43 -> V_48 : 0 ;
for ( V_30 = & V_20 -> V_27 . V_30 [ 0 ] , V_20 -> V_27 . V_28 = 1 ;
V_20 -> V_27 . V_28 <= V_29 ;
V_30 ++ , V_20 -> V_27 . V_28 ++ ) {
V_30 -> V_1 = V_1 ;
error = F_44 ( args -> V_9 , args -> V_10 , V_1 ,
- 1 , & V_30 -> V_7 , args -> V_5 ) ;
if ( error ) {
V_30 -> V_1 = 0 ;
V_20 -> V_27 . V_28 -- ;
return ( error ) ;
}
V_79 = V_30 -> V_7 -> V_11 ;
V_30 -> V_16 = F_20 ( V_79 -> V_16 ) ;
ASSERT ( V_30 -> V_16 == V_17 ||
V_30 -> V_16 == V_32 ||
V_30 -> V_16 == V_31 ) ;
if ( V_30 -> V_16 == V_17 ) {
V_6 = V_30 -> V_7 -> V_11 ;
V_24 = F_20 ( V_6 -> V_12 . V_19 ) ;
V_30 -> V_49 = F_16 ( V_6 -> V_45 [ V_24 - 1 ] . V_49 ) ;
V_80 = V_81 = V_24 / 2 ;
V_49 = args -> V_49 ;
for ( V_45 = & V_6 -> V_45 [ V_80 ] ; V_81 > 4 ;
V_45 = & V_6 -> V_45 [ V_80 ] ) {
V_81 /= 2 ;
V_82 = F_16 ( V_45 -> V_49 ) ;
if ( V_82 < V_49 )
V_80 += V_81 ;
else if ( V_82 > V_49 )
V_80 -= V_81 ;
else
break;
}
ASSERT ( ( V_80 >= 0 ) && ( V_80 < V_24 ) ) ;
ASSERT ( ( V_81 <= 4 ) || ( F_16 ( V_45 -> V_49 ) == V_49 ) ) ;
while ( ( V_80 > 0 ) && ( F_16 ( V_45 -> V_49 ) >= V_49 ) ) {
V_45 -- ;
V_80 -- ;
}
while ( ( V_80 < V_24 ) && ( F_16 ( V_45 -> V_49 ) < V_49 ) ) {
V_45 ++ ;
V_80 ++ ;
}
if ( V_80 == V_24 ) {
V_30 -> V_59 = V_24 - 1 ;
V_1 = F_16 ( V_6 -> V_45 [ V_24 - 1 ] . V_50 ) ;
} else {
V_30 -> V_59 = V_80 ;
V_1 = F_16 ( V_45 -> V_50 ) ;
}
} else if ( V_30 -> V_16 == V_31 ) {
V_30 -> V_49 = F_47 ( V_30 -> V_7 , NULL ) ;
break;
} else if ( V_30 -> V_16 == V_32 ) {
V_30 -> V_49 = F_48 ( V_30 -> V_7 , NULL ) ;
break;
}
}
for (; ; ) {
if ( V_30 -> V_16 == V_32 ) {
V_75 = F_53 ( V_30 -> V_7 , args ,
& V_30 -> V_59 , V_20 ) ;
} else if ( V_30 -> V_16 == V_31 ) {
V_75 = F_54 ( V_30 -> V_7 , args ) ;
V_30 -> V_59 = args -> V_59 ;
args -> V_1 = V_30 -> V_1 ;
} else {
ASSERT ( 0 ) ;
return F_55 ( V_83 ) ;
}
if ( ( ( V_75 == V_84 ) || ( V_75 == V_85 ) ) &&
( V_30 -> V_49 == args -> V_49 ) ) {
error = F_45 ( V_20 , & V_20 -> V_27 , 1 , 1 ,
& V_75 ) ;
if ( error )
return ( error ) ;
if ( V_75 == 0 ) {
continue;
} else if ( V_30 -> V_16 == V_31 ) {
V_75 = F_55 ( V_85 ) ;
}
}
break;
}
* V_54 = V_75 ;
return ( 0 ) ;
}
int
F_24 ( T_5 * V_20 , T_6 * V_86 ,
T_6 * V_87 )
{
T_12 * V_88 , * V_89 , * V_90 ;
T_1 * args ;
int V_50 = 0 , error ;
struct V_3 * V_7 ;
args = V_20 -> args ;
ASSERT ( args != NULL ) ;
V_88 = V_86 -> V_7 -> V_11 ;
V_89 = V_87 -> V_7 -> V_11 ;
ASSERT ( V_86 -> V_16 == V_17 ||
V_86 -> V_16 == V_32 ||
V_86 -> V_16 == V_31 ) ;
ASSERT ( V_86 -> V_16 == F_20 ( V_88 -> V_16 ) ) ;
ASSERT ( V_87 -> V_16 == F_20 ( V_89 -> V_16 ) ) ;
ASSERT ( V_86 -> V_16 == V_87 -> V_16 ) ;
switch ( V_86 -> V_16 ) {
case V_31 :
V_50 = F_56 ( V_86 -> V_7 , V_87 -> V_7 ) ;
break;
case V_32 :
V_50 = F_57 ( V_86 -> V_7 , V_87 -> V_7 ) ;
break;
case V_17 :
V_50 = F_58 ( V_86 -> V_7 , V_87 -> V_7 ) ;
break;
}
if ( V_50 ) {
F_59 ( args ) ;
V_89 -> V_14 = F_17 ( V_86 -> V_1 ) ;
V_89 -> V_15 = V_88 -> V_15 ;
if ( V_88 -> V_15 ) {
error = F_44 ( args -> V_9 , args -> V_10 ,
F_16 ( V_88 -> V_15 ) ,
- 1 , & V_7 , args -> V_5 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_7 != NULL ) ;
V_90 = V_7 -> V_11 ;
ASSERT ( F_20 ( V_90 -> V_16 ) == F_20 ( V_88 -> V_16 ) ) ;
ASSERT ( F_16 ( V_90 -> V_14 ) == V_86 -> V_1 ) ;
V_90 -> V_14 = F_17 ( V_87 -> V_1 ) ;
F_5 ( args -> V_9 , V_7 , 0 , sizeof( * V_90 ) - 1 ) ;
}
V_88 -> V_15 = F_17 ( V_87 -> V_1 ) ;
} else {
F_60 ( args ) ;
V_89 -> V_14 = V_88 -> V_14 ;
V_89 -> V_15 = F_17 ( V_86 -> V_1 ) ;
if ( V_88 -> V_14 ) {
error = F_44 ( args -> V_9 , args -> V_10 ,
F_16 ( V_88 -> V_14 ) ,
- 1 , & V_7 , args -> V_5 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_7 != NULL ) ;
V_90 = V_7 -> V_11 ;
ASSERT ( V_90 -> V_16 == V_88 -> V_16 ) ;
ASSERT ( F_16 ( V_90 -> V_15 ) == V_86 -> V_1 ) ;
V_90 -> V_15 = F_17 ( V_87 -> V_1 ) ;
F_5 ( args -> V_9 , V_7 , 0 , sizeof( * V_90 ) - 1 ) ;
}
V_88 -> V_14 = F_17 ( V_87 -> V_1 ) ;
}
F_5 ( args -> V_9 , V_86 -> V_7 , 0 , sizeof( * V_90 ) - 1 ) ;
F_5 ( args -> V_9 , V_87 -> V_7 , 0 , sizeof( * V_90 ) - 1 ) ;
return ( 0 ) ;
}
STATIC int
F_58 (
struct V_3 * V_91 ,
struct V_3 * V_92 )
{
T_3 * V_60 , * V_61 ;
V_60 = V_91 -> V_11 ;
V_61 = V_92 -> V_11 ;
ASSERT ( V_60 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) &&
V_61 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
if ( ( F_20 ( V_60 -> V_12 . V_19 ) > 0 ) && ( F_20 ( V_61 -> V_12 . V_19 ) > 0 ) &&
( ( F_16 ( V_61 -> V_45 [ 0 ] . V_49 ) <
F_16 ( V_60 -> V_45 [ 0 ] . V_49 ) ) ||
( F_16 ( V_61 -> V_45 [ F_20 ( V_61 -> V_12 . V_19 ) - 1 ] . V_49 ) <
F_16 ( V_60 -> V_45 [ F_20 ( V_60 -> V_12 . V_19 ) - 1 ] . V_49 ) ) ) ) {
return ( 1 ) ;
}
return ( 0 ) ;
}
STATIC V_66
F_49 (
struct V_3 * V_7 ,
int * V_19 )
{
T_3 * V_6 ;
V_6 = V_7 -> V_11 ;
ASSERT ( V_6 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
if ( V_19 )
* V_19 = F_20 ( V_6 -> V_12 . V_19 ) ;
if ( ! V_6 -> V_12 . V_19 )
return ( 0 ) ;
return F_16 ( V_6 -> V_45 [ F_20 ( V_6 -> V_12 . V_19 ) - 1 ] . V_49 ) ;
}
STATIC int
F_38 ( T_5 * V_20 , T_6 * V_67 ,
T_6 * V_68 )
{
T_12 * V_93 , * V_94 , * V_90 ;
T_1 * args ;
struct V_3 * V_7 ;
int error ;
args = V_20 -> args ;
ASSERT ( args != NULL ) ;
V_94 = V_68 -> V_7 -> V_11 ;
V_93 = V_67 -> V_7 -> V_11 ;
ASSERT ( V_68 -> V_16 == V_17 ||
V_68 -> V_16 == V_32 ||
V_68 -> V_16 == V_31 ) ;
ASSERT ( V_68 -> V_16 == F_20 ( V_94 -> V_16 ) ) ;
ASSERT ( V_67 -> V_16 == F_20 ( V_93 -> V_16 ) ) ;
ASSERT ( V_68 -> V_16 == V_67 -> V_16 ) ;
ASSERT ( ( F_16 ( V_94 -> V_14 ) == V_67 -> V_1 ) ||
( F_16 ( V_94 -> V_15 ) == V_67 -> V_1 ) ) ;
ASSERT ( ( F_16 ( V_93 -> V_14 ) == V_68 -> V_1 ) ||
( F_16 ( V_93 -> V_15 ) == V_68 -> V_1 ) ) ;
if ( F_16 ( V_94 -> V_15 ) == V_67 -> V_1 ) {
F_61 ( args ) ;
V_94 -> V_15 = V_93 -> V_15 ;
if ( V_93 -> V_15 ) {
error = F_44 ( args -> V_9 , args -> V_10 ,
F_16 ( V_93 -> V_15 ) ,
- 1 , & V_7 , args -> V_5 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_7 != NULL ) ;
V_90 = V_7 -> V_11 ;
ASSERT ( V_90 -> V_16 == V_94 -> V_16 ) ;
ASSERT ( F_16 ( V_90 -> V_14 ) == V_67 -> V_1 ) ;
V_90 -> V_14 = F_17 ( V_68 -> V_1 ) ;
F_5 ( args -> V_9 , V_7 , 0 ,
sizeof( * V_90 ) - 1 ) ;
}
} else {
F_62 ( args ) ;
V_94 -> V_14 = V_93 -> V_14 ;
if ( V_93 -> V_14 ) {
error = F_44 ( args -> V_9 , args -> V_10 ,
F_16 ( V_93 -> V_14 ) ,
- 1 , & V_7 , args -> V_5 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_7 != NULL ) ;
V_90 = V_7 -> V_11 ;
ASSERT ( V_90 -> V_16 == V_94 -> V_16 ) ;
ASSERT ( F_16 ( V_90 -> V_15 ) == V_67 -> V_1 ) ;
V_90 -> V_15 = F_17 ( V_68 -> V_1 ) ;
F_5 ( args -> V_9 , V_7 , 0 ,
sizeof( * V_90 ) - 1 ) ;
}
}
F_5 ( args -> V_9 , V_68 -> V_7 , 0 , sizeof( * V_94 ) - 1 ) ;
return ( 0 ) ;
}
int
F_45 ( T_5 * V_20 , T_13 * V_27 ,
int V_74 , int V_95 , int * V_54 )
{
T_6 * V_30 ;
T_12 * V_13 ;
T_3 * V_6 ;
T_1 * args ;
T_2 V_1 = 0 ;
int V_2 , error ;
args = V_20 -> args ;
ASSERT ( args != NULL ) ;
ASSERT ( V_27 != NULL ) ;
ASSERT ( ( V_27 -> V_28 > 0 ) && ( V_27 -> V_28 < V_29 ) ) ;
V_2 = ( V_27 -> V_28 - 1 ) - 1 ;
for ( V_30 = & V_27 -> V_30 [ V_2 ] ; V_2 >= 0 ; V_30 -- , V_2 -- ) {
ASSERT ( V_30 -> V_7 != NULL ) ;
V_6 = V_30 -> V_7 -> V_11 ;
ASSERT ( V_6 -> V_12 . V_13 . V_16 == F_4 ( V_17 ) ) ;
if ( V_74 && ( V_30 -> V_59 < F_20 ( V_6 -> V_12 . V_19 ) - 1 ) ) {
V_30 -> V_59 ++ ;
V_1 = F_16 ( V_6 -> V_45 [ V_30 -> V_59 ] . V_50 ) ;
break;
} else if ( ! V_74 && ( V_30 -> V_59 > 0 ) ) {
V_30 -> V_59 -- ;
V_1 = F_16 ( V_6 -> V_45 [ V_30 -> V_59 ] . V_50 ) ;
break;
}
}
if ( V_2 < 0 ) {
* V_54 = F_55 ( V_84 ) ;
ASSERT ( args -> V_96 & V_97 ) ;
return ( 0 ) ;
}
for ( V_30 ++ , V_2 ++ ; V_2 < V_27 -> V_28 ; V_30 ++ , V_2 ++ ) {
if ( V_95 )
F_46 ( args -> V_9 , V_30 -> V_7 ) ;
V_30 -> V_1 = V_1 ;
error = F_44 ( args -> V_9 , args -> V_10 , V_1 , - 1 ,
& V_30 -> V_7 , args -> V_5 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_30 -> V_7 != NULL ) ;
V_13 = V_30 -> V_7 -> V_11 ;
ASSERT ( V_13 -> V_16 == F_4 ( V_17 ) ||
V_13 -> V_16 == F_4 ( V_32 ) ||
V_13 -> V_16 == F_4 ( V_31 ) ) ;
V_30 -> V_16 = F_20 ( V_13 -> V_16 ) ;
if ( V_30 -> V_16 == V_17 ) {
V_6 = ( T_3 * ) V_13 ;
V_30 -> V_49 = F_16 ( V_6 -> V_45 [ F_20 ( V_6 -> V_12 . V_19 ) - 1 ] . V_49 ) ;
if ( V_74 )
V_30 -> V_59 = 0 ;
else
V_30 -> V_59 = F_20 ( V_6 -> V_12 . V_19 ) - 1 ;
V_1 = F_16 ( V_6 -> V_45 [ V_30 -> V_59 ] . V_50 ) ;
} else {
ASSERT ( V_2 == V_27 -> V_28 - 1 ) ;
V_30 -> V_59 = 0 ;
switch( V_30 -> V_16 ) {
case V_31 :
V_30 -> V_49 = F_47 ( V_30 -> V_7 ,
NULL ) ;
break;
case V_32 :
V_30 -> V_49 = F_48 ( V_30 -> V_7 ,
NULL ) ;
break;
default:
ASSERT ( V_30 -> V_16 == V_31 ||
V_30 -> V_16 == V_32 ) ;
break;
}
}
}
* V_54 = 0 ;
return ( 0 ) ;
}
T_14
F_63 ( const T_15 * V_98 , int V_99 )
{
T_14 V_100 ;
for ( V_100 = 0 ; V_99 >= 4 ; V_99 -= 4 , V_98 += 4 )
V_100 = ( V_98 [ 0 ] << 21 ) ^ ( V_98 [ 1 ] << 14 ) ^ ( V_98 [ 2 ] << 7 ) ^
( V_98 [ 3 ] << 0 ) ^ F_64 ( V_100 , 7 * 4 ) ;
switch ( V_99 ) {
case 3 :
return ( V_98 [ 0 ] << 14 ) ^ ( V_98 [ 1 ] << 7 ) ^ ( V_98 [ 2 ] << 0 ) ^
F_64 ( V_100 , 7 * 3 ) ;
case 2 :
return ( V_98 [ 0 ] << 7 ) ^ ( V_98 [ 1 ] << 0 ) ^ F_64 ( V_100 , 7 * 2 ) ;
case 1 :
return ( V_98 [ 0 ] << 0 ) ^ F_64 ( V_100 , 7 * 1 ) ;
default:
return V_100 ;
}
}
enum V_101
F_65 (
struct V_102 * args ,
const unsigned char * V_98 ,
int V_103 )
{
return ( args -> V_99 == V_103 && memcmp ( args -> V_98 , V_98 , V_103 ) == 0 ) ?
V_104 : V_105 ;
}
static T_14
F_66 (
struct V_106 * V_98 )
{
return F_63 ( V_98 -> V_98 , V_98 -> V_103 ) ;
}
int
F_67 (
struct V_102 * args ,
T_16 * V_107 ,
int V_19 )
{
struct V_108 * V_8 = args -> V_9 ;
struct V_109 * V_10 = args -> V_10 ;
int V_110 = args -> V_5 ;
T_17 V_111 = V_10 -> V_112 . V_113 ;
struct V_114 V_115 , * V_116 ;
int V_117 , error , V_118 , V_26 , V_119 ;
error = F_68 ( V_8 , V_10 , V_19 , V_107 , V_110 ) ;
if ( error )
return error ;
V_117 = 1 ;
ASSERT ( args -> V_120 != NULL ) ;
error = F_69 ( V_8 , V_10 , * V_107 , V_19 ,
F_70 ( V_110 ) | V_121 | V_122 ,
args -> V_120 , args -> V_123 , & V_115 , & V_117 ,
args -> V_124 ) ;
if ( error )
return error ;
ASSERT ( V_117 <= 1 ) ;
if ( V_117 == 1 ) {
V_116 = & V_115 ;
V_119 = 1 ;
} else if ( V_117 == 0 && V_19 > 1 ) {
T_16 V_125 ;
int V_126 ;
V_116 = F_71 ( sizeof( * V_116 ) * V_19 , V_127 ) ;
for ( V_125 = * V_107 , V_119 = 0 ; V_125 < * V_107 + V_19 ; ) {
V_117 = F_72 ( V_128 , V_19 ) ;
V_126 = ( int ) ( * V_107 + V_19 - V_125 ) ;
error = F_69 ( V_8 , V_10 , V_125 , V_126 ,
F_70 ( V_110 ) | V_121 ,
args -> V_120 , args -> V_123 ,
& V_116 [ V_119 ] , & V_117 , args -> V_124 ) ;
if ( error )
goto V_129;
if ( V_117 < 1 )
break;
V_119 += V_117 ;
V_125 = V_116 [ V_119 - 1 ] . V_130 +
V_116 [ V_119 - 1 ] . V_131 ;
}
} else {
V_119 = 0 ;
V_116 = NULL ;
}
for ( V_26 = 0 , V_118 = 0 ; V_26 < V_119 ; V_26 ++ )
V_118 += V_116 [ V_26 ] . V_131 ;
if ( V_118 != V_19 || V_116 [ 0 ] . V_130 != * V_107 ||
V_116 [ V_119 - 1 ] . V_130 + V_116 [ V_119 - 1 ] . V_131 !=
* V_107 + V_19 ) {
error = F_55 ( V_34 ) ;
goto V_129;
}
args -> V_123 -= V_10 -> V_112 . V_113 - V_111 ;
V_129:
if ( V_116 != & V_115 )
F_73 ( V_116 ) ;
return error ;
}
int
F_19 (
struct V_102 * args ,
T_2 * V_132 )
{
T_16 V_107 ;
int V_19 ;
int error ;
F_74 ( args ) ;
if ( args -> V_5 == V_47 ) {
V_107 = args -> V_10 -> V_133 -> V_48 ;
V_19 = args -> V_10 -> V_133 -> V_134 ;
} else {
V_107 = 0 ;
V_19 = 1 ;
}
error = F_67 ( args , & V_107 , V_19 ) ;
if ( ! error )
* V_132 = ( T_2 ) V_107 ;
return error ;
}
STATIC int
F_75 (
T_1 * args ,
T_2 * V_135 ,
struct V_3 * * V_136 )
{
T_2 V_137 , V_138 , V_139 , V_140 ;
struct V_3 * V_141 , * V_142 , * V_143 , * V_144 ;
T_16 V_145 ;
T_7 * V_146 ;
T_4 * V_8 ;
T_8 * V_43 ;
int error , V_110 , V_147 , V_2 , V_148 ;
T_12 * V_149 , * V_150 ;
T_3 * V_151 , * V_152 ;
T_9 * V_153 ;
T_14 V_154 ;
F_76 ( args ) ;
V_141 = * V_136 ;
V_137 = * V_135 ;
V_8 = args -> V_9 ;
V_146 = args -> V_10 ;
V_110 = args -> V_5 ;
ASSERT ( V_110 == V_47 ) ;
V_43 = V_146 -> V_133 ;
V_145 = V_43 -> V_51 ;
error = F_77 ( V_8 , V_146 , & V_145 , V_110 ) ;
if ( error )
return error ;
if ( F_78 ( V_145 == 0 ) ) {
F_79 ( L_1 , V_155 ,
V_43 ) ;
return F_55 ( V_83 ) ;
}
V_138 = ( T_2 ) V_145 - V_43 -> V_134 ;
if ( ( error = F_44 ( V_8 , V_146 , V_138 , - 1 , & V_142 , V_110 ) ) )
return error ;
memcpy ( V_141 -> V_11 , V_142 -> V_11 , V_43 -> V_156 ) ;
F_5 ( V_8 , V_141 , 0 , V_43 -> V_156 - 1 ) ;
V_149 = V_141 -> V_11 ;
if ( V_149 -> V_16 == F_4 ( V_32 ) ) {
V_153 = ( T_9 * ) V_149 ;
V_148 = 0 ;
V_154 = F_16 ( V_153 -> V_46 [ F_20 ( V_153 -> V_12 . V_19 ) - 1 ] . V_49 ) ;
} else {
ASSERT ( V_149 -> V_16 == F_4 ( V_17 ) ) ;
V_152 = ( T_3 * ) V_149 ;
V_148 = F_20 ( V_152 -> V_12 . V_2 ) ;
V_154 = F_16 ( V_152 -> V_45 [ F_20 ( V_152 -> V_12 . V_19 ) - 1 ] . V_49 ) ;
}
V_143 = V_144 = NULL ;
if ( ( V_139 = F_16 ( V_149 -> V_15 ) ) ) {
if ( ( error = F_44 ( V_8 , V_146 , V_139 , - 1 , & V_143 , V_110 ) ) )
goto V_157;
V_150 = V_143 -> V_11 ;
if ( F_78 (
F_16 ( V_150 -> V_14 ) != V_138 ||
V_150 -> V_16 != V_149 -> V_16 ) ) {
F_79 ( L_2 ,
V_155 , V_43 ) ;
error = F_55 ( V_83 ) ;
goto V_157;
}
V_150 -> V_14 = F_17 ( V_137 ) ;
F_5 ( V_8 , V_143 ,
F_6 ( V_150 , & V_150 -> V_14 ,
sizeof( V_150 -> V_14 ) ) ) ;
V_143 = NULL ;
}
if ( ( V_139 = F_16 ( V_149 -> V_14 ) ) ) {
if ( ( error = F_44 ( V_8 , V_146 , V_139 , - 1 , & V_143 , V_110 ) ) )
goto V_157;
V_150 = V_143 -> V_11 ;
if ( F_78 (
F_16 ( V_150 -> V_15 ) != V_138 ||
V_150 -> V_16 != V_149 -> V_16 ) ) {
F_79 ( L_3 ,
V_155 , V_43 ) ;
error = F_55 ( V_83 ) ;
goto V_157;
}
V_150 -> V_15 = F_17 ( V_137 ) ;
F_5 ( V_8 , V_143 ,
F_6 ( V_150 , & V_150 -> V_15 ,
sizeof( V_150 -> V_15 ) ) ) ;
V_143 = NULL ;
}
V_140 = V_43 -> V_48 ;
V_2 = - 1 ;
for (; ; ) {
if ( ( error = F_44 ( V_8 , V_146 , V_140 , - 1 , & V_144 , V_110 ) ) )
goto V_157;
V_151 = V_144 -> V_11 ;
if ( F_78 ( V_151 -> V_12 . V_13 . V_16 !=
F_4 ( V_17 ) ||
( V_2 >= 0 && V_2 != F_20 ( V_151 -> V_12 . V_2 ) + 1 ) ) ) {
F_79 ( L_4 ,
V_155 , V_43 ) ;
error = F_55 ( V_83 ) ;
goto V_157;
}
V_2 = F_20 ( V_151 -> V_12 . V_2 ) ;
for ( V_147 = 0 ;
V_147 < F_20 ( V_151 -> V_12 . V_19 ) &&
F_16 ( V_151 -> V_45 [ V_147 ] . V_49 ) < V_154 ;
V_147 ++ )
continue;
if ( F_78 ( V_147 == F_20 ( V_151 -> V_12 . V_19 ) ) ) {
F_79 ( L_5 ,
V_155 , V_43 ) ;
error = F_55 ( V_83 ) ;
goto V_157;
}
V_140 = F_16 ( V_151 -> V_45 [ V_147 ] . V_50 ) ;
if ( V_2 == V_148 + 1 )
break;
F_46 ( V_8 , V_144 ) ;
V_144 = NULL ;
}
for (; ; ) {
for (;
V_147 < F_20 ( V_151 -> V_12 . V_19 ) &&
F_16 ( V_151 -> V_45 [ V_147 ] . V_50 ) != V_138 ;
V_147 ++ )
continue;
if ( V_147 < F_20 ( V_151 -> V_12 . V_19 ) )
break;
V_140 = F_16 ( V_151 -> V_12 . V_13 . V_14 ) ;
F_46 ( V_8 , V_144 ) ;
V_144 = NULL ;
if ( F_78 ( V_140 == 0 ) ) {
F_79 ( L_6 ,
V_155 , V_43 ) ;
error = F_55 ( V_83 ) ;
goto V_157;
}
if ( ( error = F_44 ( V_8 , V_146 , V_140 , - 1 , & V_144 , V_110 ) ) )
goto V_157;
V_151 = V_144 -> V_11 ;
if ( F_78 (
F_20 ( V_151 -> V_12 . V_2 ) != V_2 ||
V_151 -> V_12 . V_13 . V_16 != F_4 ( V_17 ) ) ) {
F_79 ( L_7 ,
V_155 , V_43 ) ;
error = F_55 ( V_83 ) ;
goto V_157;
}
V_147 = 0 ;
}
V_151 -> V_45 [ V_147 ] . V_50 = F_17 ( V_137 ) ;
F_5 ( V_8 , V_144 ,
F_6 ( V_151 , & V_151 -> V_45 [ V_147 ] . V_50 ,
sizeof( V_151 -> V_45 [ V_147 ] . V_50 ) ) ) ;
* V_135 = V_138 ;
* V_136 = V_142 ;
return 0 ;
V_157:
if ( V_144 )
F_46 ( V_8 , V_144 ) ;
if ( V_143 )
F_46 ( V_8 , V_143 ) ;
F_46 ( V_8 , V_142 ) ;
return error ;
}
int
F_40 (
T_1 * args ,
T_2 V_137 ,
struct V_3 * V_141 )
{
T_7 * V_10 ;
int V_157 , error , V_110 , V_19 ;
T_4 * V_8 ;
T_8 * V_43 ;
F_80 ( args ) ;
V_10 = args -> V_10 ;
V_110 = args -> V_5 ;
V_8 = args -> V_9 ;
V_43 = V_10 -> V_133 ;
if ( V_110 == V_47 )
V_19 = V_43 -> V_134 ;
else
V_19 = 1 ;
for (; ; ) {
if ( ( error = F_81 ( V_8 , V_10 , V_137 , V_19 ,
F_70 ( V_110 ) | V_121 ,
0 , args -> V_120 , args -> V_124 ,
& V_157 ) ) == V_34 ) {
if ( V_110 != V_47 )
break;
if ( ( error = F_75 ( args , & V_137 ,
& V_141 ) ) )
break;
} else {
break;
}
}
F_82 ( V_8 , V_141 ) ;
return error ;
}
STATIC int
F_83 (
int V_117 ,
T_18 * V_116 ,
T_2 V_107 ,
int V_19 )
{
int V_26 ;
T_16 V_158 ;
for ( V_26 = 0 , V_158 = V_107 ; V_26 < V_117 ; V_26 ++ ) {
if ( V_116 [ V_26 ] . V_159 == V_160 ||
V_116 [ V_26 ] . V_159 == V_161 ) {
return 0 ;
}
if ( V_158 != V_116 [ V_26 ] . V_130 ) {
return 0 ;
}
V_158 += V_116 [ V_26 ] . V_131 ;
}
return V_158 == V_107 + V_19 ;
}
static int
F_84 (
struct V_162 * V_43 ,
struct V_163 * * V_116 ,
unsigned int * V_164 ,
struct V_114 * V_165 ,
unsigned int V_166 )
{
struct V_163 * V_115 ;
int V_26 ;
ASSERT ( * V_164 == 1 ) ;
ASSERT ( V_166 >= 1 ) ;
if ( V_166 > 1 ) {
V_115 = F_85 ( V_166 * sizeof( struct V_163 ) , V_127 ) ;
if ( ! V_115 )
return V_167 ;
* V_116 = V_115 ;
}
* V_164 = V_166 ;
V_115 = * V_116 ;
for ( V_26 = 0 ; V_26 < * V_164 ; V_26 ++ ) {
ASSERT ( V_165 [ V_26 ] . V_159 != V_161 &&
V_165 [ V_26 ] . V_159 != V_160 ) ;
V_115 [ V_26 ] . V_168 = F_86 ( V_43 , V_165 [ V_26 ] . V_159 ) ;
V_115 [ V_26 ] . V_169 = F_87 ( V_43 , V_165 [ V_26 ] . V_131 ) ;
}
return 0 ;
}
static int
F_88 (
struct V_108 * V_9 ,
struct V_109 * V_10 ,
T_2 V_107 ,
T_19 V_170 ,
int V_5 ,
struct V_163 * * V_115 ,
int * V_164 )
{
struct V_162 * V_43 = V_10 -> V_133 ;
int V_171 ;
int error = 0 ;
struct V_114 V_172 ;
struct V_114 * V_165 = & V_172 ;
int V_166 ;
ASSERT ( V_115 && * V_115 ) ;
ASSERT ( * V_164 == 1 ) ;
V_171 = ( V_5 == V_47 ) ? V_43 -> V_134 : 1 ;
if ( V_170 == - 1 || V_170 == - 2 ) {
if ( V_171 != 1 )
V_165 = F_85 ( sizeof( V_172 ) * V_171 , V_127 ) ;
V_166 = V_171 ;
error = F_89 ( V_10 , ( T_16 ) V_107 , V_171 , V_165 ,
& V_166 , F_70 ( V_5 ) ) ;
if ( error )
goto V_173;
} else {
V_165 -> V_159 = F_90 ( V_43 , V_170 ) ;
V_165 -> V_130 = ( T_16 ) V_107 ;
V_165 -> V_131 = V_171 ;
V_165 -> V_174 = 0 ;
V_166 = 1 ;
}
if ( ! F_83 ( V_166 , V_165 , V_107 , V_171 ) ) {
error = V_170 == - 2 ? - 1 : F_55 ( V_83 ) ;
if ( F_78 ( error == V_83 ) ) {
if ( V_175 >= V_155 ) {
int V_26 ;
F_91 ( V_43 , L_8 ,
V_176 , ( long long ) V_107 ,
( long long ) V_10 -> V_177 ) ;
for ( V_26 = 0 ; V_26 < * V_164 ; V_26 ++ ) {
F_91 ( V_43 ,
L_9 ,
V_26 ,
( long long ) V_165 [ V_26 ] . V_130 ,
( long long ) V_165 [ V_26 ] . V_159 ,
( long long ) V_165 [ V_26 ] . V_131 ,
V_165 [ V_26 ] . V_174 ) ;
}
}
F_79 ( L_10 ,
V_155 , V_43 ) ;
}
goto V_173;
}
error = F_84 ( V_43 , V_115 , V_164 , V_165 , V_166 ) ;
V_173:
if ( V_165 != & V_172 )
F_73 ( V_165 ) ;
return error ;
}
int
F_3 (
struct V_108 * V_9 ,
struct V_109 * V_10 ,
T_2 V_107 ,
T_19 V_170 ,
struct V_3 * * V_4 ,
int V_5 )
{
struct V_3 * V_7 ;
struct V_163 V_115 ;
struct V_163 * V_116 ;
int V_117 ;
int error ;
* V_4 = NULL ;
V_116 = & V_115 ;
V_117 = 1 ;
error = F_88 ( V_9 , V_10 , V_107 , V_170 , V_5 ,
& V_116 , & V_117 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_178;
}
V_7 = F_92 ( V_9 , V_10 -> V_133 -> V_179 ,
V_116 , V_117 , 0 ) ;
error = V_7 ? V_7 -> V_180 : F_55 ( V_181 ) ;
if ( error ) {
F_46 ( V_9 , V_7 ) ;
goto V_178;
}
* V_4 = V_7 ;
V_178:
if ( V_116 != & V_115 )
F_73 ( V_116 ) ;
return error ;
}
int
F_44 (
struct V_108 * V_9 ,
struct V_109 * V_10 ,
T_2 V_107 ,
T_19 V_170 ,
struct V_3 * * V_4 ,
int V_5 )
{
struct V_3 * V_7 ;
struct V_163 V_115 ;
struct V_163 * V_116 ;
int V_117 ;
int error ;
* V_4 = NULL ;
V_116 = & V_115 ;
V_117 = 1 ;
error = F_88 ( V_9 , V_10 , V_107 , V_170 , V_5 ,
& V_116 , & V_117 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_178;
}
error = F_93 ( V_10 -> V_133 , V_9 ,
V_10 -> V_133 -> V_179 ,
V_116 , V_117 , 0 , & V_7 ) ;
if ( error )
goto V_178;
if ( V_5 == V_57 )
F_94 ( V_7 , V_182 ) ;
else
F_94 ( V_7 , V_183 ) ;
{
T_20 * V_12 = V_7 -> V_11 ;
T_21 * free = V_7 -> V_11 ;
T_12 * V_13 = V_7 -> V_11 ;
V_66 V_16 , V_184 ;
struct V_162 * V_43 = V_10 -> V_133 ;
V_16 = F_20 ( V_13 -> V_16 ) ;
V_184 = F_16 ( V_12 -> V_16 ) ;
if ( F_78 (
F_95 ( ( V_16 != V_17 ) &&
( V_16 != V_31 ) &&
( V_16 != V_185 ) &&
( V_16 != V_32 ) &&
( V_184 != V_186 ) &&
( V_184 != V_187 ) &&
( free -> V_12 . V_16 != F_17 ( V_188 ) ) ,
V_43 , V_189 ,
V_190 ) ) ) {
F_96 ( V_7 , V_191 ) ;
F_97 ( L_11 ,
V_155 , V_43 , V_13 ) ;
error = F_55 ( V_83 ) ;
F_46 ( V_9 , V_7 ) ;
goto V_178;
}
}
* V_4 = V_7 ;
V_178:
if ( V_116 != & V_115 )
F_73 ( V_116 ) ;
return error ;
}
T_19
F_98 (
struct V_108 * V_9 ,
struct V_109 * V_10 ,
T_2 V_107 ,
int V_5 )
{
T_19 V_170 = - 1 ;
struct V_163 V_115 ;
struct V_163 * V_116 ;
int V_117 ;
int error ;
V_116 = & V_115 ;
V_117 = 1 ;
error = F_88 ( V_9 , V_10 , V_107 , - 1 , V_5 ,
& V_116 , & V_117 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_178;
}
V_170 = V_116 [ 0 ] . V_168 ;
F_99 ( V_10 -> V_133 -> V_179 , V_116 , V_117 ) ;
V_178:
if ( V_116 != & V_115 )
F_73 ( V_116 ) ;
if ( error )
return - 1 ;
return V_170 ;
}
T_5 *
F_100 ( void )
{
return F_101 ( V_192 , V_193 ) ;
}
STATIC void
F_39 ( T_5 * V_20 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_20 -> V_33 . V_28 ; V_26 ++ )
V_20 -> V_33 . V_30 [ V_26 ] . V_7 = NULL ;
V_20 -> V_33 . V_28 = 0 ;
}
void
F_102 ( T_5 * V_20 )
{
F_39 ( V_20 ) ;
#ifdef F_21
memset ( ( char * ) V_20 , 0 , sizeof( * V_20 ) ) ;
#endif
F_103 ( V_192 , V_20 ) ;
}
