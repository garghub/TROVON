static void
F_1 (
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 = 0 ;
V_10 = V_8 -> V_11 . V_12 == F_2 ( V_13 ) ;
V_10 = V_10 &&
F_3 ( V_8 -> V_14 ) > 0 &&
F_3 ( V_8 -> V_15 ) > 0 ;
if ( ! V_10 ) {
F_4 ( V_16 , V_17 , V_4 , V_8 ) ;
F_5 ( V_2 , V_18 ) ;
}
}
static void
F_6 (
struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
static void
F_7 (
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_19 * V_11 = V_2 -> V_9 ;
switch ( F_3 ( V_11 -> V_12 ) ) {
case V_13 :
F_1 ( V_2 ) ;
break;
case V_20 :
V_2 -> V_21 = & V_22 ;
V_2 -> V_21 -> V_23 ( V_2 ) ;
return;
case V_24 :
V_2 -> V_21 = & V_25 ;
V_2 -> V_21 -> V_23 ( V_2 ) ;
return;
default:
F_4 ( V_16 , V_17 ,
V_4 , V_11 ) ;
F_5 ( V_2 , V_18 ) ;
break;
}
}
int
F_8 (
struct V_26 * V_27 ,
struct V_28 * V_29 ,
T_1 V_30 ,
T_2 V_31 ,
struct V_1 * * V_32 ,
int V_33 )
{
return F_9 ( V_27 , V_29 , V_30 , V_31 , V_32 ,
V_33 , & V_34 ) ;
}
int
F_10 ( T_3 * args , T_1 V_35 , int V_14 ,
struct V_1 * * V_32 , int V_36 )
{
T_4 * V_37 ;
struct V_1 * V_2 ;
int error ;
T_5 * V_27 ;
F_11 ( args ) ;
V_27 = args -> V_38 ;
error = F_12 ( V_27 , args -> V_29 , V_35 , - 1 , & V_2 , V_36 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_2 != NULL ) ;
V_37 = V_2 -> V_9 ;
V_37 -> V_8 . V_11 . V_39 = 0 ;
V_37 -> V_8 . V_11 . V_40 = 0 ;
V_37 -> V_8 . V_11 . V_12 = F_2 ( V_13 ) ;
V_37 -> V_8 . V_11 . V_41 = 0 ;
V_37 -> V_8 . V_15 = 0 ;
V_37 -> V_8 . V_14 = F_2 ( V_14 ) ;
F_13 ( V_27 , V_2 ,
F_14 ( V_37 , & V_37 -> V_8 , sizeof( V_37 -> V_8 ) ) ) ;
V_2 -> V_21 = & V_34 ;
* V_32 = V_2 ;
return ( 0 ) ;
}
int
F_15 ( T_6 * V_42 )
{
T_7 * V_43 , * V_44 , * V_45 ;
T_4 * V_37 ;
struct V_1 * V_2 ;
int V_46 , V_47 , error , V_48 ;
F_16 ( V_42 -> args ) ;
V_46 = V_42 -> V_49 . V_50 - 1 ;
ASSERT ( ( V_46 >= 0 ) && ( V_46 < V_51 ) ) ;
ASSERT ( V_42 -> V_49 . V_52 [ V_46 ] . V_12 == V_20 ||
V_42 -> V_49 . V_52 [ V_46 ] . V_12 == V_24 ) ;
V_45 = & V_42 -> V_49 . V_52 [ V_46 ] ;
for ( V_48 = V_46 ; ( V_48 >= 0 ) && V_45 ; V_42 -> V_49 . V_50 -- , V_48 -- ) {
V_43 = & V_42 -> V_49 . V_52 [ V_48 ] ;
V_44 = & V_42 -> V_53 . V_52 [ V_48 ] ;
switch ( V_43 -> V_12 ) {
case V_20 :
error = F_17 ( V_42 , V_43 , V_44 ) ;
if ( ( error != 0 ) && ( error != V_54 ) ) {
return ( error ) ;
}
if ( ! error ) {
V_45 = V_44 ;
break;
}
V_42 -> V_55 = 1 ;
if ( V_42 -> V_56 ) {
V_42 -> V_57 = 0 ;
F_18 ( V_42 -> args ) ;
error = F_17 ( V_42 , V_43 ,
& V_42 -> V_58 ) ;
} else {
V_42 -> V_57 = 1 ;
F_19 ( V_42 -> args ) ;
error = F_17 ( V_42 , V_44 ,
& V_42 -> V_58 ) ;
}
if ( error )
return ( error ) ;
V_45 = V_44 ;
break;
case V_24 :
error = F_20 ( V_42 , V_43 , V_44 ) ;
if ( error )
return error ;
V_45 = V_44 ;
break;
case V_13 :
error = F_21 ( V_42 , V_43 , V_44 , V_45 ,
V_46 - V_48 , & V_47 ) ;
V_45 -> V_2 = NULL ;
if ( error )
return ( error ) ;
if ( V_47 )
V_45 = V_44 ;
else
V_45 = NULL ;
break;
}
F_22 ( V_42 , & V_42 -> V_49 ) ;
}
if ( ! V_45 )
return ( 0 ) ;
ASSERT ( V_42 -> V_49 . V_50 == 0 ) ;
V_43 = & V_42 -> V_49 . V_52 [ 0 ] ;
error = F_23 ( V_42 , V_43 , V_45 ) ;
if ( error ) {
V_45 -> V_2 = NULL ;
return ( error ) ;
}
V_37 = V_43 -> V_2 -> V_9 ;
if ( V_37 -> V_8 . V_11 . V_39 ) {
if ( F_24 ( V_37 -> V_8 . V_11 . V_39 ) == V_45 -> V_35 ) {
V_2 = V_45 -> V_2 ;
} else {
ASSERT ( V_42 -> V_55 ) ;
V_2 = V_42 -> V_58 . V_2 ;
}
V_37 = V_2 -> V_9 ;
V_37 -> V_8 . V_11 . V_40 = F_25 ( V_43 -> V_35 ) ;
F_13 ( V_42 -> args -> V_38 , V_2 ,
F_14 ( V_37 , & V_37 -> V_8 . V_11 ,
sizeof( V_37 -> V_8 . V_11 ) ) ) ;
}
V_37 = V_43 -> V_2 -> V_9 ;
if ( V_37 -> V_8 . V_11 . V_40 ) {
if ( F_24 ( V_37 -> V_8 . V_11 . V_40 ) == V_45 -> V_35 ) {
V_2 = V_45 -> V_2 ;
} else {
ASSERT ( V_42 -> V_55 ) ;
V_2 = V_42 -> V_58 . V_2 ;
}
V_37 = V_2 -> V_9 ;
V_37 -> V_8 . V_11 . V_39 = F_25 ( V_43 -> V_35 ) ;
F_13 ( V_42 -> args -> V_38 , V_2 ,
F_14 ( V_37 , & V_37 -> V_8 . V_11 ,
sizeof( V_37 -> V_8 . V_11 ) ) ) ;
}
V_45 -> V_2 = NULL ;
return ( 0 ) ;
}
STATIC int
F_23 ( T_6 * V_42 , T_7 * V_59 ,
T_7 * V_60 )
{
T_4 * V_37 , * V_61 ;
T_3 * args ;
T_1 V_35 ;
struct V_1 * V_2 ;
int error , V_62 ;
T_8 * V_29 ;
T_5 * V_27 ;
T_9 * V_4 ;
T_10 * V_63 ;
F_26 ( V_42 -> args ) ;
args = V_42 -> args ;
ASSERT ( args != NULL ) ;
error = F_27 ( args , & V_35 ) ;
if ( error )
return ( error ) ;
V_29 = args -> V_29 ;
V_27 = args -> V_38 ;
V_4 = V_42 -> V_4 ;
error = F_12 ( V_27 , V_29 , V_35 , - 1 , & V_2 , args -> V_36 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_2 != NULL ) ;
V_37 = V_2 -> V_9 ;
V_61 = V_59 -> V_2 -> V_9 ;
if ( V_61 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) {
V_62 = ( int ) ( ( char * ) & V_61 -> V_64 [ F_3 ( V_61 -> V_8 . V_15 ) ] -
( char * ) V_61 ) ;
} else {
ASSERT ( V_61 -> V_8 . V_11 . V_12 == F_2 ( V_24 ) ) ;
V_63 = ( T_10 * ) V_61 ;
V_62 = ( int ) ( ( char * ) & V_63 -> V_65 [ F_3 ( V_63 -> V_8 . V_15 ) ] -
( char * ) V_63 ) ;
}
memcpy ( V_37 , V_61 , V_62 ) ;
F_13 ( V_27 , V_2 , 0 , V_62 - 1 ) ;
V_2 -> V_21 = V_59 -> V_2 -> V_21 ;
V_59 -> V_2 = V_2 ;
V_59 -> V_35 = V_35 ;
error = F_10 ( args ,
( args -> V_36 == V_66 ) ? V_4 -> V_67 : 0 ,
F_3 ( V_37 -> V_8 . V_14 ) + 1 , & V_2 , args -> V_36 ) ;
if ( error )
return ( error ) ;
V_37 = V_2 -> V_9 ;
V_37 -> V_64 [ 0 ] . V_68 = F_25 ( V_59 -> V_68 ) ;
V_37 -> V_64 [ 0 ] . V_69 = F_25 ( V_59 -> V_35 ) ;
V_37 -> V_64 [ 1 ] . V_68 = F_25 ( V_60 -> V_68 ) ;
V_37 -> V_64 [ 1 ] . V_69 = F_25 ( V_60 -> V_35 ) ;
V_37 -> V_8 . V_15 = F_2 ( 2 ) ;
#ifdef F_28
if ( V_61 -> V_8 . V_11 . V_12 == F_2 ( V_24 ) ) {
ASSERT ( V_59 -> V_35 >= V_4 -> V_67 &&
V_59 -> V_35 < V_4 -> V_70 ) ;
ASSERT ( V_60 -> V_35 >= V_4 -> V_67 &&
V_60 -> V_35 < V_4 -> V_70 ) ;
}
#endif
F_13 ( V_27 , V_2 ,
F_14 ( V_37 , V_37 -> V_64 ,
sizeof( V_71 ) * 2 ) ) ;
return ( 0 ) ;
}
STATIC int
F_21 ( T_6 * V_42 , T_7 * V_43 ,
T_7 * V_44 ,
T_7 * V_45 ,
int V_72 , int * V_73 )
{
T_4 * V_37 ;
T_1 V_35 ;
int V_74 , error ;
int V_75 ;
F_29 ( V_42 -> args ) ;
V_37 = V_43 -> V_2 -> V_9 ;
ASSERT ( V_37 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
V_75 = V_42 -> V_55 && V_42 -> args -> V_36 == V_76 ;
V_74 = 1 + V_75 ;
if ( ( F_3 ( V_37 -> V_8 . V_15 ) + V_74 ) > V_42 -> V_77 ) {
error = F_27 ( V_42 -> args , & V_35 ) ;
if ( error )
return ( error ) ;
error = F_10 ( V_42 -> args , V_35 , V_72 ,
& V_44 -> V_2 , V_42 -> args -> V_36 ) ;
if ( error )
return ( error ) ;
V_44 -> V_35 = V_35 ;
V_44 -> V_12 = V_13 ;
F_30 ( V_42 , V_43 , V_44 ) ;
error = F_31 ( V_42 , V_43 , V_44 ) ;
if ( error )
return ( error ) ;
* V_73 = 1 ;
} else {
* V_73 = 0 ;
}
V_37 = V_43 -> V_2 -> V_9 ;
if ( V_43 -> V_78 <= F_3 ( V_37 -> V_8 . V_15 ) ) {
V_43 -> V_78 ++ ;
F_32 ( V_42 , V_43 , V_45 ) ;
if ( V_75 ) {
if ( V_42 -> V_57 )
V_43 -> V_78 ++ ;
F_32 ( V_42 , V_43 , & V_42 -> V_58 ) ;
V_42 -> V_55 = 0 ;
}
} else {
V_44 -> V_78 ++ ;
F_32 ( V_42 , V_44 , V_45 ) ;
if ( V_75 ) {
if ( V_42 -> V_57 )
V_44 -> V_78 ++ ;
F_32 ( V_42 , V_44 , & V_42 -> V_58 ) ;
V_42 -> V_55 = 0 ;
}
}
return ( 0 ) ;
}
STATIC void
F_30 ( T_6 * V_42 , T_7 * V_59 ,
T_7 * V_60 )
{
T_4 * V_79 , * V_80 , * V_81 ;
V_71 * V_82 , * V_83 ;
int V_15 , V_84 ;
T_5 * V_27 ;
F_33 ( V_42 -> args ) ;
V_79 = V_59 -> V_2 -> V_9 ;
V_80 = V_60 -> V_2 -> V_9 ;
if ( ( F_3 ( V_79 -> V_8 . V_15 ) > 0 ) && ( F_3 ( V_80 -> V_8 . V_15 ) > 0 ) &&
( ( F_24 ( V_80 -> V_64 [ 0 ] . V_68 ) < F_24 ( V_79 -> V_64 [ 0 ] . V_68 ) ) ||
( F_24 ( V_80 -> V_64 [ F_3 ( V_80 -> V_8 . V_15 ) - 1 ] . V_68 ) <
F_24 ( V_79 -> V_64 [ F_3 ( V_79 -> V_8 . V_15 ) - 1 ] . V_68 ) ) ) ) {
V_81 = V_79 ;
V_79 = V_80 ;
V_80 = V_81 ;
}
ASSERT ( V_79 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
ASSERT ( V_80 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
V_15 = ( F_3 ( V_79 -> V_8 . V_15 ) - F_3 ( V_80 -> V_8 . V_15 ) ) / 2 ;
if ( V_15 == 0 )
return;
V_27 = V_42 -> args -> V_38 ;
if ( V_15 > 0 ) {
if ( ( V_84 = F_3 ( V_80 -> V_8 . V_15 ) ) > 0 ) {
V_84 *= ( V_85 ) sizeof( V_71 ) ;
V_82 = & V_80 -> V_64 [ 0 ] ;
V_83 = & V_80 -> V_64 [ V_15 ] ;
memmove ( V_83 , V_82 , V_84 ) ;
}
F_34 ( & V_80 -> V_8 . V_15 , V_15 ) ;
V_84 = V_15 * ( V_85 ) sizeof( V_71 ) ;
V_82 = & V_79 -> V_64 [ F_3 ( V_79 -> V_8 . V_15 ) - V_15 ] ;
V_83 = & V_80 -> V_64 [ 0 ] ;
memcpy ( V_83 , V_82 , V_84 ) ;
F_34 ( & V_79 -> V_8 . V_15 , - V_15 ) ;
} else {
V_15 = - V_15 ;
V_84 = V_15 * ( V_85 ) sizeof( V_71 ) ;
V_82 = & V_80 -> V_64 [ 0 ] ;
V_83 = & V_79 -> V_64 [ F_3 ( V_79 -> V_8 . V_15 ) ] ;
memcpy ( V_83 , V_82 , V_84 ) ;
F_34 ( & V_79 -> V_8 . V_15 , V_15 ) ;
F_13 ( V_27 , V_59 -> V_2 ,
F_14 ( V_79 , V_83 , V_84 ) ) ;
V_84 = F_3 ( V_80 -> V_8 . V_15 ) - V_15 ;
V_84 *= ( V_85 ) sizeof( V_71 ) ;
V_82 = & V_80 -> V_64 [ V_15 ] ;
V_83 = & V_80 -> V_64 [ 0 ] ;
memmove ( V_83 , V_82 , V_84 ) ;
F_34 ( & V_80 -> V_8 . V_15 , - V_15 ) ;
}
F_13 ( V_27 , V_59 -> V_2 ,
F_14 ( V_79 , & V_79 -> V_8 , sizeof( V_79 -> V_8 ) ) ) ;
F_13 ( V_27 , V_60 -> V_2 ,
F_14 ( V_80 , & V_80 -> V_8 ,
sizeof( V_80 -> V_8 ) +
sizeof( V_80 -> V_64 [ 0 ] ) * F_3 ( V_80 -> V_8 . V_15 ) ) ) ;
V_79 = V_59 -> V_2 -> V_9 ;
V_80 = V_60 -> V_2 -> V_9 ;
V_59 -> V_68 = F_24 ( V_79 -> V_64 [ F_3 ( V_79 -> V_8 . V_15 ) - 1 ] . V_68 ) ;
V_60 -> V_68 = F_24 ( V_80 -> V_64 [ F_3 ( V_80 -> V_8 . V_15 ) - 1 ] . V_68 ) ;
if ( V_59 -> V_78 >= F_3 ( V_79 -> V_8 . V_15 ) ) {
V_60 -> V_78 = V_59 -> V_78 - F_3 ( V_79 -> V_8 . V_15 ) ;
V_59 -> V_78 = F_3 ( V_79 -> V_8 . V_15 ) + 1 ;
}
}
STATIC void
F_32 ( T_6 * V_42 , T_7 * V_43 ,
T_7 * V_44 )
{
T_4 * V_37 ;
V_71 * V_64 ;
int V_84 ;
F_35 ( V_42 -> args ) ;
V_37 = V_43 -> V_2 -> V_9 ;
ASSERT ( V_37 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
ASSERT ( ( V_43 -> V_78 >= 0 ) && ( V_43 -> V_78 <= F_3 ( V_37 -> V_8 . V_15 ) ) ) ;
ASSERT ( V_44 -> V_35 != 0 ) ;
if ( V_42 -> args -> V_36 == V_66 )
ASSERT ( V_44 -> V_35 >= V_42 -> V_4 -> V_67 &&
V_44 -> V_35 < V_42 -> V_4 -> V_70 ) ;
V_84 = 0 ;
V_64 = & V_37 -> V_64 [ V_43 -> V_78 ] ;
if ( V_43 -> V_78 < F_3 ( V_37 -> V_8 . V_15 ) ) {
V_84 = ( F_3 ( V_37 -> V_8 . V_15 ) - V_43 -> V_78 ) * ( V_85 ) sizeof( * V_64 ) ;
memmove ( V_64 + 1 , V_64 , V_84 ) ;
}
V_64 -> V_68 = F_25 ( V_44 -> V_68 ) ;
V_64 -> V_69 = F_25 ( V_44 -> V_35 ) ;
F_13 ( V_42 -> args -> V_38 , V_43 -> V_2 ,
F_14 ( V_37 , V_64 , V_84 + sizeof( * V_64 ) ) ) ;
F_34 ( & V_37 -> V_8 . V_15 , 1 ) ;
F_13 ( V_42 -> args -> V_38 , V_43 -> V_2 ,
F_14 ( V_37 , & V_37 -> V_8 , sizeof( V_37 -> V_8 ) ) ) ;
V_43 -> V_68 = F_24 ( V_37 -> V_64 [ F_3 ( V_37 -> V_8 . V_15 ) - 1 ] . V_68 ) ;
}
int
F_36 ( T_6 * V_42 )
{
T_7 * V_86 , * V_87 ;
int V_47 , error ;
F_37 ( V_42 -> args ) ;
V_47 = 0 ;
V_86 = & V_42 -> V_49 . V_52 [ V_42 -> V_49 . V_50 - 1 ] ;
V_87 = & V_42 -> V_53 . V_52 [ V_42 -> V_49 . V_50 - 1 ] ;
ASSERT ( V_42 -> V_49 . V_52 [ 0 ] . V_12 == V_13 ) ;
ASSERT ( V_86 -> V_12 == V_20 ||
V_86 -> V_12 == V_24 ) ;
for ( ; V_42 -> V_49 . V_50 >= 2 ; V_86 -- , V_87 -- ,
V_42 -> V_49 . V_50 -- ) {
switch ( V_86 -> V_12 ) {
case V_20 :
error = F_38 ( V_42 , & V_47 ) ;
if ( error )
return ( error ) ;
if ( V_47 == 0 )
return ( 0 ) ;
F_39 ( V_42 , V_86 , V_87 ) ;
break;
case V_24 :
error = F_40 ( V_42 , & V_47 ) ;
if ( error )
return error ;
if ( V_47 == 0 )
return 0 ;
F_41 ( V_42 , V_86 , V_87 ) ;
break;
case V_13 :
F_42 ( V_42 , V_86 ) ;
F_22 ( V_42 , & V_42 -> V_49 ) ;
error = F_43 ( V_42 , & V_47 ) ;
if ( error )
return ( error ) ;
if ( V_47 == 0 )
return 0 ;
F_44 ( V_42 , V_86 , V_87 ) ;
break;
}
F_22 ( V_42 , & V_42 -> V_53 ) ;
error = F_45 ( V_42 , V_86 , V_87 ) ;
F_46 ( V_42 ) ;
if ( error )
return ( error ) ;
error = F_47 ( V_42 -> args , V_86 -> V_35 ,
V_86 -> V_2 ) ;
V_86 -> V_2 = NULL ;
if ( error )
return ( error ) ;
}
F_42 ( V_42 , V_86 ) ;
F_22 ( V_42 , & V_42 -> V_49 ) ;
error = F_48 ( V_42 , & V_42 -> V_49 . V_52 [ 0 ] ) ;
return ( error ) ;
}
static void
F_49 ( struct V_19 * V_88 , T_11 V_14 )
{
T_12 V_12 = V_88 -> V_12 ;
if ( V_14 == 1 ) {
ASSERT ( V_12 == F_2 ( V_24 ) ||
V_12 == F_2 ( V_20 ) ) ;
} else
ASSERT ( V_12 == F_2 ( V_13 ) ) ;
ASSERT ( ! V_88 -> V_39 ) ;
ASSERT ( ! V_88 -> V_40 ) ;
}
STATIC int
F_48 ( T_6 * V_42 , T_7 * V_89 )
{
T_4 * V_61 ;
T_3 * args ;
T_1 V_90 ;
struct V_1 * V_2 ;
int error ;
F_50 ( V_42 -> args ) ;
args = V_42 -> args ;
ASSERT ( args != NULL ) ;
ASSERT ( V_89 -> V_12 == V_13 ) ;
V_61 = V_89 -> V_2 -> V_9 ;
ASSERT ( V_61 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
ASSERT ( ! V_61 -> V_8 . V_11 . V_39 ) ;
ASSERT ( ! V_61 -> V_8 . V_11 . V_40 ) ;
if ( F_3 ( V_61 -> V_8 . V_15 ) > 1 )
return ( 0 ) ;
V_90 = F_24 ( V_61 -> V_64 [ 0 ] . V_69 ) ;
ASSERT ( V_90 != 0 ) ;
error = F_8 ( args -> V_38 , args -> V_29 , V_90 , - 1 , & V_2 ,
args -> V_36 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_2 != NULL ) ;
F_49 ( V_2 -> V_9 ,
F_3 ( V_61 -> V_8 . V_14 ) ) ;
memcpy ( V_89 -> V_2 -> V_9 , V_2 -> V_9 , V_42 -> V_91 ) ;
V_89 -> V_2 -> V_21 = V_2 -> V_21 ;
F_13 ( args -> V_38 , V_89 -> V_2 , 0 , V_42 -> V_91 - 1 ) ;
error = F_47 ( args , V_90 , V_2 ) ;
return ( error ) ;
}
STATIC int
F_43 ( T_6 * V_42 , int * V_47 )
{
T_4 * V_37 ;
T_7 * V_52 ;
T_13 * V_11 ;
int V_15 , V_92 , error , V_93 , V_48 ;
T_1 V_35 ;
struct V_1 * V_2 ;
F_51 ( V_42 -> args ) ;
V_52 = & V_42 -> V_49 . V_52 [ V_42 -> V_49 . V_50 - 1 ] ;
V_11 = V_52 -> V_2 -> V_9 ;
ASSERT ( V_11 -> V_12 == F_2 ( V_13 ) ) ;
V_37 = ( T_4 * ) V_11 ;
V_15 = F_3 ( V_37 -> V_8 . V_15 ) ;
if ( V_15 > ( V_42 -> V_77 >> 1 ) ) {
* V_47 = 0 ;
return ( 0 ) ;
}
if ( V_15 == 0 ) {
V_92 = ( V_11 -> V_39 != 0 ) ;
memcpy ( & V_42 -> V_53 , & V_42 -> V_49 , sizeof( V_42 -> V_49 ) ) ;
error = F_52 ( V_42 , & V_42 -> V_53 , V_92 ,
0 , & V_93 ) ;
if ( error )
return ( error ) ;
if ( V_93 ) {
* V_47 = 0 ;
} else {
* V_47 = 2 ;
}
return ( 0 ) ;
}
V_92 = ( F_24 ( V_11 -> V_39 ) < F_24 ( V_11 -> V_40 ) ) ;
for ( V_48 = 0 ; V_48 < 2 ; V_92 = ! V_92 , V_48 ++ ) {
if ( V_92 )
V_35 = F_24 ( V_11 -> V_39 ) ;
else
V_35 = F_24 ( V_11 -> V_40 ) ;
if ( V_35 == 0 )
continue;
error = F_8 ( V_42 -> args -> V_38 , V_42 -> args -> V_29 ,
V_35 , - 1 , & V_2 , V_42 -> args -> V_36 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_2 != NULL ) ;
V_37 = ( T_4 * ) V_11 ;
V_15 = V_42 -> V_77 ;
V_15 -= V_42 -> V_77 >> 2 ;
V_15 -= F_3 ( V_37 -> V_8 . V_15 ) ;
V_37 = V_2 -> V_9 ;
ASSERT ( V_37 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
V_15 -= F_3 ( V_37 -> V_8 . V_15 ) ;
F_53 ( V_42 -> args -> V_38 , V_2 ) ;
if ( V_15 >= 0 )
break;
}
if ( V_48 >= 2 ) {
* V_47 = 0 ;
return ( 0 ) ;
}
memcpy ( & V_42 -> V_53 , & V_42 -> V_49 , sizeof( V_42 -> V_49 ) ) ;
if ( V_35 < V_52 -> V_35 ) {
error = F_52 ( V_42 , & V_42 -> V_53 , V_92 ,
0 , & V_93 ) ;
if ( error ) {
return ( error ) ;
}
if ( V_93 ) {
* V_47 = 0 ;
return ( 0 ) ;
}
} else {
error = F_52 ( V_42 , & V_42 -> V_49 , V_92 ,
0 , & V_93 ) ;
if ( error ) {
return ( error ) ;
}
if ( V_93 ) {
* V_47 = 0 ;
return ( 0 ) ;
}
}
* V_47 = 1 ;
return ( 0 ) ;
}
void
F_22 ( T_6 * V_42 , T_14 * V_49 )
{
T_7 * V_52 ;
T_4 * V_37 ;
V_71 * V_64 ;
T_15 V_94 = 0 ;
int V_14 , V_15 ;
F_54 ( V_42 -> args ) ;
V_14 = V_49 -> V_50 - 1 ;
V_52 = & V_49 -> V_52 [ V_14 ] ;
switch ( V_52 -> V_12 ) {
case V_20 :
V_94 = F_55 ( V_52 -> V_2 , & V_15 ) ;
if ( V_15 == 0 )
return;
break;
case V_24 :
V_94 = F_56 ( V_52 -> V_2 , & V_15 ) ;
if ( V_15 == 0 )
return;
break;
case V_13 :
V_94 = F_57 ( V_52 -> V_2 , & V_15 ) ;
if ( V_15 == 0 )
return;
break;
}
for ( V_52 -- , V_14 -- ; V_14 >= 0 ; V_52 -- , V_14 -- ) {
V_37 = V_52 -> V_2 -> V_9 ;
ASSERT ( V_37 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
V_64 = & V_37 -> V_64 [ V_52 -> V_78 ] ;
if ( F_24 ( V_64 -> V_68 ) == V_94 )
break;
V_52 -> V_68 = V_94 ;
V_64 -> V_68 = F_25 ( V_94 ) ;
F_13 ( V_42 -> args -> V_38 , V_52 -> V_2 ,
F_14 ( V_37 , V_64 , sizeof( * V_64 ) ) ) ;
V_94 = F_24 ( V_37 -> V_64 [ F_3 ( V_37 -> V_8 . V_15 ) - 1 ] . V_68 ) ;
}
}
STATIC void
F_42 ( T_6 * V_42 , T_7 * V_86 )
{
T_4 * V_37 ;
V_71 * V_64 ;
int V_84 ;
F_58 ( V_42 -> args ) ;
V_37 = V_86 -> V_2 -> V_9 ;
ASSERT ( V_86 -> V_78 < F_3 ( V_37 -> V_8 . V_15 ) ) ;
ASSERT ( V_86 -> V_78 >= 0 ) ;
V_64 = & V_37 -> V_64 [ V_86 -> V_78 ] ;
if ( V_86 -> V_78 < ( F_3 ( V_37 -> V_8 . V_15 ) - 1 ) ) {
V_84 = F_3 ( V_37 -> V_8 . V_15 ) - V_86 -> V_78 - 1 ;
V_84 *= ( V_85 ) sizeof( V_71 ) ;
memmove ( V_64 , V_64 + 1 , V_84 ) ;
F_13 ( V_42 -> args -> V_38 , V_86 -> V_2 ,
F_14 ( V_37 , V_64 , V_84 ) ) ;
V_64 = & V_37 -> V_64 [ F_3 ( V_37 -> V_8 . V_15 ) - 1 ] ;
}
memset ( ( char * ) V_64 , 0 , sizeof( V_71 ) ) ;
F_13 ( V_42 -> args -> V_38 , V_86 -> V_2 ,
F_14 ( V_37 , V_64 , sizeof( * V_64 ) ) ) ;
F_34 ( & V_37 -> V_8 . V_15 , - 1 ) ;
F_13 ( V_42 -> args -> V_38 , V_86 -> V_2 ,
F_14 ( V_37 , & V_37 -> V_8 , sizeof( V_37 -> V_8 ) ) ) ;
V_64 -- ;
V_86 -> V_68 = F_24 ( V_64 -> V_68 ) ;
}
STATIC void
F_44 ( T_6 * V_42 , T_7 * V_86 ,
T_7 * V_87 )
{
T_4 * V_95 , * V_96 ;
V_71 * V_64 ;
int V_84 ;
T_5 * V_27 ;
F_59 ( V_42 -> args ) ;
V_95 = V_86 -> V_2 -> V_9 ;
V_96 = V_87 -> V_2 -> V_9 ;
ASSERT ( V_95 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
ASSERT ( V_96 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
V_27 = V_42 -> args -> V_38 ;
if ( ( F_24 ( V_95 -> V_64 [ 0 ] . V_68 ) < F_24 ( V_96 -> V_64 [ 0 ] . V_68 ) ) ||
( F_24 ( V_95 -> V_64 [ F_3 ( V_95 -> V_8 . V_15 ) - 1 ] . V_68 ) <
F_24 ( V_96 -> V_64 [ F_3 ( V_96 -> V_8 . V_15 ) - 1 ] . V_68 ) ) )
{
V_64 = & V_96 -> V_64 [ F_3 ( V_95 -> V_8 . V_15 ) ] ;
V_84 = F_3 ( V_96 -> V_8 . V_15 ) * ( V_85 ) sizeof( V_71 ) ;
memmove ( V_64 , & V_96 -> V_64 [ 0 ] , V_84 ) ;
V_64 = & V_96 -> V_64 [ 0 ] ;
F_13 ( V_27 , V_87 -> V_2 ,
F_14 ( V_96 , V_64 ,
( F_3 ( V_96 -> V_8 . V_15 ) + F_3 ( V_95 -> V_8 . V_15 ) ) *
sizeof( V_71 ) ) ) ;
} else {
V_64 = & V_96 -> V_64 [ F_3 ( V_96 -> V_8 . V_15 ) ] ;
F_13 ( V_27 , V_87 -> V_2 ,
F_14 ( V_96 , V_64 ,
F_3 ( V_95 -> V_8 . V_15 ) *
sizeof( V_71 ) ) ) ;
}
V_84 = F_3 ( V_95 -> V_8 . V_15 ) * ( V_85 ) sizeof( V_71 ) ;
memcpy ( V_64 , & V_95 -> V_64 [ 0 ] , V_84 ) ;
F_34 ( & V_96 -> V_8 . V_15 , F_3 ( V_95 -> V_8 . V_15 ) ) ;
F_13 ( V_27 , V_87 -> V_2 ,
F_14 ( V_96 , & V_96 -> V_8 ,
sizeof( V_96 -> V_8 ) ) ) ;
V_87 -> V_68 = F_24 ( V_96 -> V_64 [ F_3 ( V_96 -> V_8 . V_15 ) - 1 ] . V_68 ) ;
}
int
F_60 ( T_6 * V_42 , int * V_73 )
{
T_7 * V_52 ;
T_13 * V_97 ;
T_4 * V_37 ;
V_71 * V_64 ;
T_1 V_35 ;
int V_98 , V_99 , V_46 , error , V_93 ;
T_15 V_68 , V_100 ;
T_3 * args ;
args = V_42 -> args ;
V_35 = ( args -> V_36 == V_66 ) ? V_42 -> V_4 -> V_67 : 0 ;
for ( V_52 = & V_42 -> V_49 . V_52 [ 0 ] , V_42 -> V_49 . V_50 = 1 ;
V_42 -> V_49 . V_50 <= V_51 ;
V_52 ++ , V_42 -> V_49 . V_50 ++ ) {
V_52 -> V_35 = V_35 ;
error = F_8 ( args -> V_38 , args -> V_29 , V_35 ,
- 1 , & V_52 -> V_2 , args -> V_36 ) ;
if ( error ) {
V_52 -> V_35 = 0 ;
V_42 -> V_49 . V_50 -- ;
return ( error ) ;
}
V_97 = V_52 -> V_2 -> V_9 ;
V_52 -> V_12 = F_3 ( V_97 -> V_12 ) ;
ASSERT ( V_52 -> V_12 == V_13 ||
V_52 -> V_12 == V_24 ||
V_52 -> V_12 == V_20 ) ;
if ( V_52 -> V_12 == V_13 ) {
V_37 = V_52 -> V_2 -> V_9 ;
V_46 = F_3 ( V_37 -> V_8 . V_15 ) ;
V_52 -> V_68 = F_24 ( V_37 -> V_64 [ V_46 - 1 ] . V_68 ) ;
V_98 = V_99 = V_46 / 2 ;
V_68 = args -> V_68 ;
for ( V_64 = & V_37 -> V_64 [ V_98 ] ; V_99 > 4 ;
V_64 = & V_37 -> V_64 [ V_98 ] ) {
V_99 /= 2 ;
V_100 = F_24 ( V_64 -> V_68 ) ;
if ( V_100 < V_68 )
V_98 += V_99 ;
else if ( V_100 > V_68 )
V_98 -= V_99 ;
else
break;
}
ASSERT ( ( V_98 >= 0 ) && ( V_98 < V_46 ) ) ;
ASSERT ( ( V_99 <= 4 ) || ( F_24 ( V_64 -> V_68 ) == V_68 ) ) ;
while ( ( V_98 > 0 ) && ( F_24 ( V_64 -> V_68 ) >= V_68 ) ) {
V_64 -- ;
V_98 -- ;
}
while ( ( V_98 < V_46 ) && ( F_24 ( V_64 -> V_68 ) < V_68 ) ) {
V_64 ++ ;
V_98 ++ ;
}
if ( V_98 == V_46 ) {
V_52 -> V_78 = V_46 - 1 ;
V_35 = F_24 ( V_37 -> V_64 [ V_46 - 1 ] . V_69 ) ;
} else {
V_52 -> V_78 = V_98 ;
V_35 = F_24 ( V_64 -> V_69 ) ;
}
} else if ( V_52 -> V_12 == V_20 ) {
V_52 -> V_68 = F_55 ( V_52 -> V_2 , NULL ) ;
break;
} else if ( V_52 -> V_12 == V_24 ) {
V_52 -> V_68 = F_56 ( V_52 -> V_2 , NULL ) ;
break;
}
}
for (; ; ) {
if ( V_52 -> V_12 == V_24 ) {
V_93 = F_61 ( V_52 -> V_2 , args ,
& V_52 -> V_78 , V_42 ) ;
} else if ( V_52 -> V_12 == V_20 ) {
V_93 = F_62 ( V_52 -> V_2 , args ) ;
V_52 -> V_78 = args -> V_78 ;
args -> V_35 = V_52 -> V_35 ;
} else {
ASSERT ( 0 ) ;
return F_63 ( V_18 ) ;
}
if ( ( ( V_93 == V_101 ) || ( V_93 == V_102 ) ) &&
( V_52 -> V_68 == args -> V_68 ) ) {
error = F_52 ( V_42 , & V_42 -> V_49 , 1 , 1 ,
& V_93 ) ;
if ( error )
return ( error ) ;
if ( V_93 == 0 ) {
continue;
} else if ( V_52 -> V_12 == V_20 ) {
V_93 = F_63 ( V_102 ) ;
}
}
break;
}
* V_73 = V_93 ;
return ( 0 ) ;
}
int
F_31 ( T_6 * V_42 , T_7 * V_103 ,
T_7 * V_104 )
{
T_13 * V_105 , * V_106 , * V_107 ;
T_3 * args ;
int V_69 = 0 , error ;
struct V_1 * V_2 ;
args = V_42 -> args ;
ASSERT ( args != NULL ) ;
V_105 = V_103 -> V_2 -> V_9 ;
V_106 = V_104 -> V_2 -> V_9 ;
ASSERT ( V_103 -> V_12 == V_13 ||
V_103 -> V_12 == V_24 ||
V_103 -> V_12 == V_20 ) ;
ASSERT ( V_103 -> V_12 == F_3 ( V_105 -> V_12 ) ) ;
ASSERT ( V_104 -> V_12 == F_3 ( V_106 -> V_12 ) ) ;
ASSERT ( V_103 -> V_12 == V_104 -> V_12 ) ;
switch ( V_103 -> V_12 ) {
case V_20 :
V_69 = F_64 ( V_103 -> V_2 , V_104 -> V_2 ) ;
break;
case V_24 :
V_69 = F_65 ( V_103 -> V_2 , V_104 -> V_2 ) ;
break;
case V_13 :
V_69 = F_66 ( V_103 -> V_2 , V_104 -> V_2 ) ;
break;
}
if ( V_69 ) {
F_67 ( args ) ;
V_106 -> V_39 = F_25 ( V_103 -> V_35 ) ;
V_106 -> V_40 = V_105 -> V_40 ;
if ( V_105 -> V_40 ) {
error = F_8 ( args -> V_38 , args -> V_29 ,
F_24 ( V_105 -> V_40 ) ,
- 1 , & V_2 , args -> V_36 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_2 != NULL ) ;
V_107 = V_2 -> V_9 ;
ASSERT ( F_3 ( V_107 -> V_12 ) == F_3 ( V_105 -> V_12 ) ) ;
ASSERT ( F_24 ( V_107 -> V_39 ) == V_103 -> V_35 ) ;
V_107 -> V_39 = F_25 ( V_104 -> V_35 ) ;
F_13 ( args -> V_38 , V_2 , 0 , sizeof( * V_107 ) - 1 ) ;
}
V_105 -> V_40 = F_25 ( V_104 -> V_35 ) ;
} else {
F_68 ( args ) ;
V_106 -> V_39 = V_105 -> V_39 ;
V_106 -> V_40 = F_25 ( V_103 -> V_35 ) ;
if ( V_105 -> V_39 ) {
error = F_8 ( args -> V_38 , args -> V_29 ,
F_24 ( V_105 -> V_39 ) ,
- 1 , & V_2 , args -> V_36 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_2 != NULL ) ;
V_107 = V_2 -> V_9 ;
ASSERT ( V_107 -> V_12 == V_105 -> V_12 ) ;
ASSERT ( F_24 ( V_107 -> V_40 ) == V_103 -> V_35 ) ;
V_107 -> V_40 = F_25 ( V_104 -> V_35 ) ;
F_13 ( args -> V_38 , V_2 , 0 , sizeof( * V_107 ) - 1 ) ;
}
V_105 -> V_39 = F_25 ( V_104 -> V_35 ) ;
}
F_13 ( args -> V_38 , V_103 -> V_2 , 0 , sizeof( * V_107 ) - 1 ) ;
F_13 ( args -> V_38 , V_104 -> V_2 , 0 , sizeof( * V_107 ) - 1 ) ;
return ( 0 ) ;
}
STATIC int
F_66 (
struct V_1 * V_108 ,
struct V_1 * V_109 )
{
T_4 * V_79 , * V_80 ;
V_79 = V_108 -> V_9 ;
V_80 = V_109 -> V_9 ;
ASSERT ( V_79 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) &&
V_80 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
if ( ( F_3 ( V_79 -> V_8 . V_15 ) > 0 ) && ( F_3 ( V_80 -> V_8 . V_15 ) > 0 ) &&
( ( F_24 ( V_80 -> V_64 [ 0 ] . V_68 ) <
F_24 ( V_79 -> V_64 [ 0 ] . V_68 ) ) ||
( F_24 ( V_80 -> V_64 [ F_3 ( V_80 -> V_8 . V_15 ) - 1 ] . V_68 ) <
F_24 ( V_79 -> V_64 [ F_3 ( V_79 -> V_8 . V_15 ) - 1 ] . V_68 ) ) ) ) {
return ( 1 ) ;
}
return ( 0 ) ;
}
STATIC V_85
F_57 (
struct V_1 * V_2 ,
int * V_15 )
{
T_4 * V_37 ;
V_37 = V_2 -> V_9 ;
ASSERT ( V_37 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
if ( V_15 )
* V_15 = F_3 ( V_37 -> V_8 . V_15 ) ;
if ( ! V_37 -> V_8 . V_15 )
return ( 0 ) ;
return F_24 ( V_37 -> V_64 [ F_3 ( V_37 -> V_8 . V_15 ) - 1 ] . V_68 ) ;
}
STATIC int
F_45 ( T_6 * V_42 , T_7 * V_86 ,
T_7 * V_87 )
{
T_13 * V_110 , * V_111 , * V_107 ;
T_3 * args ;
struct V_1 * V_2 ;
int error ;
args = V_42 -> args ;
ASSERT ( args != NULL ) ;
V_111 = V_87 -> V_2 -> V_9 ;
V_110 = V_86 -> V_2 -> V_9 ;
ASSERT ( V_87 -> V_12 == V_13 ||
V_87 -> V_12 == V_24 ||
V_87 -> V_12 == V_20 ) ;
ASSERT ( V_87 -> V_12 == F_3 ( V_111 -> V_12 ) ) ;
ASSERT ( V_86 -> V_12 == F_3 ( V_110 -> V_12 ) ) ;
ASSERT ( V_87 -> V_12 == V_86 -> V_12 ) ;
ASSERT ( ( F_24 ( V_111 -> V_39 ) == V_86 -> V_35 ) ||
( F_24 ( V_111 -> V_40 ) == V_86 -> V_35 ) ) ;
ASSERT ( ( F_24 ( V_110 -> V_39 ) == V_87 -> V_35 ) ||
( F_24 ( V_110 -> V_40 ) == V_87 -> V_35 ) ) ;
if ( F_24 ( V_111 -> V_40 ) == V_86 -> V_35 ) {
F_69 ( args ) ;
V_111 -> V_40 = V_110 -> V_40 ;
if ( V_110 -> V_40 ) {
error = F_8 ( args -> V_38 , args -> V_29 ,
F_24 ( V_110 -> V_40 ) ,
- 1 , & V_2 , args -> V_36 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_2 != NULL ) ;
V_107 = V_2 -> V_9 ;
ASSERT ( V_107 -> V_12 == V_111 -> V_12 ) ;
ASSERT ( F_24 ( V_107 -> V_39 ) == V_86 -> V_35 ) ;
V_107 -> V_39 = F_25 ( V_87 -> V_35 ) ;
F_13 ( args -> V_38 , V_2 , 0 ,
sizeof( * V_107 ) - 1 ) ;
}
} else {
F_70 ( args ) ;
V_111 -> V_39 = V_110 -> V_39 ;
if ( V_110 -> V_39 ) {
error = F_8 ( args -> V_38 , args -> V_29 ,
F_24 ( V_110 -> V_39 ) ,
- 1 , & V_2 , args -> V_36 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_2 != NULL ) ;
V_107 = V_2 -> V_9 ;
ASSERT ( V_107 -> V_12 == V_111 -> V_12 ) ;
ASSERT ( F_24 ( V_107 -> V_40 ) == V_86 -> V_35 ) ;
V_107 -> V_40 = F_25 ( V_87 -> V_35 ) ;
F_13 ( args -> V_38 , V_2 , 0 ,
sizeof( * V_107 ) - 1 ) ;
}
}
F_13 ( args -> V_38 , V_87 -> V_2 , 0 , sizeof( * V_111 ) - 1 ) ;
return ( 0 ) ;
}
int
F_52 ( T_6 * V_42 , T_14 * V_49 ,
int V_92 , int V_112 , int * V_73 )
{
T_7 * V_52 ;
T_13 * V_11 ;
T_4 * V_37 ;
T_3 * args ;
T_1 V_35 = 0 ;
int V_14 , error ;
F_71 ( V_42 -> args ) ;
args = V_42 -> args ;
ASSERT ( args != NULL ) ;
ASSERT ( V_49 != NULL ) ;
ASSERT ( ( V_49 -> V_50 > 0 ) && ( V_49 -> V_50 < V_51 ) ) ;
V_14 = ( V_49 -> V_50 - 1 ) - 1 ;
for ( V_52 = & V_49 -> V_52 [ V_14 ] ; V_14 >= 0 ; V_52 -- , V_14 -- ) {
ASSERT ( V_52 -> V_2 != NULL ) ;
V_37 = V_52 -> V_2 -> V_9 ;
ASSERT ( V_37 -> V_8 . V_11 . V_12 == F_2 ( V_13 ) ) ;
if ( V_92 && ( V_52 -> V_78 < F_3 ( V_37 -> V_8 . V_15 ) - 1 ) ) {
V_52 -> V_78 ++ ;
V_35 = F_24 ( V_37 -> V_64 [ V_52 -> V_78 ] . V_69 ) ;
break;
} else if ( ! V_92 && ( V_52 -> V_78 > 0 ) ) {
V_52 -> V_78 -- ;
V_35 = F_24 ( V_37 -> V_64 [ V_52 -> V_78 ] . V_69 ) ;
break;
}
}
if ( V_14 < 0 ) {
* V_73 = F_63 ( V_101 ) ;
ASSERT ( args -> V_113 & V_114 ) ;
return ( 0 ) ;
}
for ( V_52 ++ , V_14 ++ ; V_14 < V_49 -> V_50 ; V_52 ++ , V_14 ++ ) {
if ( V_112 )
F_53 ( args -> V_38 , V_52 -> V_2 ) ;
V_52 -> V_35 = V_35 ;
error = F_8 ( args -> V_38 , args -> V_29 , V_35 , - 1 ,
& V_52 -> V_2 , args -> V_36 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_52 -> V_2 != NULL ) ;
V_11 = V_52 -> V_2 -> V_9 ;
ASSERT ( V_11 -> V_12 == F_2 ( V_13 ) ||
V_11 -> V_12 == F_2 ( V_24 ) ||
V_11 -> V_12 == F_2 ( V_20 ) ) ;
V_52 -> V_12 = F_3 ( V_11 -> V_12 ) ;
if ( V_52 -> V_12 == V_13 ) {
V_37 = ( T_4 * ) V_11 ;
V_52 -> V_68 = F_24 ( V_37 -> V_64 [ F_3 ( V_37 -> V_8 . V_15 ) - 1 ] . V_68 ) ;
if ( V_92 )
V_52 -> V_78 = 0 ;
else
V_52 -> V_78 = F_3 ( V_37 -> V_8 . V_15 ) - 1 ;
V_35 = F_24 ( V_37 -> V_64 [ V_52 -> V_78 ] . V_69 ) ;
} else {
ASSERT ( V_14 == V_49 -> V_50 - 1 ) ;
V_52 -> V_78 = 0 ;
switch( V_52 -> V_12 ) {
case V_20 :
V_52 -> V_68 = F_55 ( V_52 -> V_2 ,
NULL ) ;
break;
case V_24 :
V_52 -> V_68 = F_56 ( V_52 -> V_2 ,
NULL ) ;
break;
default:
ASSERT ( V_52 -> V_12 == V_20 ||
V_52 -> V_12 == V_24 ) ;
break;
}
}
}
* V_73 = 0 ;
return ( 0 ) ;
}
T_15
F_72 ( const T_16 * V_115 , int V_116 )
{
T_15 V_117 ;
for ( V_117 = 0 ; V_116 >= 4 ; V_116 -= 4 , V_115 += 4 )
V_117 = ( V_115 [ 0 ] << 21 ) ^ ( V_115 [ 1 ] << 14 ) ^ ( V_115 [ 2 ] << 7 ) ^
( V_115 [ 3 ] << 0 ) ^ F_73 ( V_117 , 7 * 4 ) ;
switch ( V_116 ) {
case 3 :
return ( V_115 [ 0 ] << 14 ) ^ ( V_115 [ 1 ] << 7 ) ^ ( V_115 [ 2 ] << 0 ) ^
F_73 ( V_117 , 7 * 3 ) ;
case 2 :
return ( V_115 [ 0 ] << 7 ) ^ ( V_115 [ 1 ] << 0 ) ^ F_73 ( V_117 , 7 * 2 ) ;
case 1 :
return ( V_115 [ 0 ] << 0 ) ^ F_73 ( V_117 , 7 * 1 ) ;
default:
return V_117 ;
}
}
enum V_118
F_74 (
struct V_119 * args ,
const unsigned char * V_115 ,
int V_120 )
{
return ( args -> V_116 == V_120 && memcmp ( args -> V_115 , V_115 , V_120 ) == 0 ) ?
V_121 : V_122 ;
}
static T_15
F_75 (
struct V_123 * V_115 )
{
return F_72 ( V_115 -> V_115 , V_115 -> V_120 ) ;
}
int
F_76 (
struct V_119 * args ,
T_17 * V_30 ,
int V_15 )
{
struct V_26 * V_27 = args -> V_38 ;
struct V_28 * V_29 = args -> V_29 ;
int V_124 = args -> V_36 ;
T_18 V_125 = V_29 -> V_126 . V_127 ;
struct V_128 V_129 , * V_130 ;
int V_131 , error , V_132 , V_48 , V_133 ;
error = F_77 ( V_27 , V_29 , V_15 , V_30 , V_124 ) ;
if ( error )
return error ;
V_131 = 1 ;
ASSERT ( args -> V_134 != NULL ) ;
error = F_78 ( V_27 , V_29 , * V_30 , V_15 ,
F_79 ( V_124 ) | V_135 | V_136 ,
args -> V_134 , args -> V_137 , & V_129 , & V_131 ,
args -> V_138 ) ;
if ( error )
return error ;
ASSERT ( V_131 <= 1 ) ;
if ( V_131 == 1 ) {
V_130 = & V_129 ;
V_133 = 1 ;
} else if ( V_131 == 0 && V_15 > 1 ) {
T_17 V_139 ;
int V_140 ;
V_130 = F_80 ( sizeof( * V_130 ) * V_15 , V_141 ) ;
for ( V_139 = * V_30 , V_133 = 0 ; V_139 < * V_30 + V_15 ; ) {
V_131 = F_81 ( V_142 , V_15 ) ;
V_140 = ( int ) ( * V_30 + V_15 - V_139 ) ;
error = F_78 ( V_27 , V_29 , V_139 , V_140 ,
F_79 ( V_124 ) | V_135 ,
args -> V_134 , args -> V_137 ,
& V_130 [ V_133 ] , & V_131 , args -> V_138 ) ;
if ( error )
goto V_143;
if ( V_131 < 1 )
break;
V_133 += V_131 ;
V_139 = V_130 [ V_133 - 1 ] . V_144 +
V_130 [ V_133 - 1 ] . V_145 ;
}
} else {
V_133 = 0 ;
V_130 = NULL ;
}
for ( V_48 = 0 , V_132 = 0 ; V_48 < V_133 ; V_48 ++ )
V_132 += V_130 [ V_48 ] . V_145 ;
if ( V_132 != V_15 || V_130 [ 0 ] . V_144 != * V_30 ||
V_130 [ V_133 - 1 ] . V_144 + V_130 [ V_133 - 1 ] . V_145 !=
* V_30 + V_15 ) {
error = F_63 ( V_54 ) ;
goto V_143;
}
args -> V_137 -= V_29 -> V_126 . V_127 - V_125 ;
V_143:
if ( V_130 != & V_129 )
F_82 ( V_130 ) ;
return error ;
}
int
F_27 (
struct V_119 * args ,
T_1 * V_146 )
{
T_17 V_30 ;
int V_15 ;
int error ;
F_83 ( args ) ;
if ( args -> V_36 == V_66 ) {
V_30 = args -> V_29 -> V_147 -> V_67 ;
V_15 = args -> V_29 -> V_147 -> V_148 ;
} else {
V_30 = 0 ;
V_15 = 1 ;
}
error = F_76 ( args , & V_30 , V_15 ) ;
if ( ! error )
* V_146 = ( T_1 ) V_30 ;
return error ;
}
STATIC int
F_84 (
T_3 * args ,
T_1 * V_149 ,
struct V_1 * * V_150 )
{
T_1 V_151 , V_152 , V_153 , V_154 ;
struct V_1 * V_155 , * V_156 , * V_157 , * V_158 ;
T_17 V_159 ;
T_8 * V_160 ;
T_5 * V_27 ;
T_9 * V_4 ;
int error , V_124 , V_161 , V_14 , V_162 ;
T_13 * V_163 , * V_164 ;
T_4 * V_165 , * V_166 ;
T_10 * V_167 ;
T_15 V_168 ;
F_85 ( args ) ;
V_155 = * V_150 ;
V_151 = * V_149 ;
V_27 = args -> V_38 ;
V_160 = args -> V_29 ;
V_124 = args -> V_36 ;
ASSERT ( V_124 == V_66 ) ;
V_4 = V_160 -> V_147 ;
V_159 = V_4 -> V_70 ;
error = F_86 ( V_27 , V_160 , & V_159 , V_124 ) ;
if ( error )
return error ;
if ( F_87 ( V_159 == 0 ) ) {
F_88 ( L_1 , V_17 ,
V_4 ) ;
return F_63 ( V_18 ) ;
}
V_152 = ( T_1 ) V_159 - V_4 -> V_148 ;
error = F_8 ( V_27 , V_160 , V_152 , - 1 , & V_156 , V_124 ) ;
if ( error )
return error ;
memcpy ( V_155 -> V_9 , V_156 -> V_9 , V_4 -> V_169 ) ;
F_13 ( V_27 , V_155 , 0 , V_4 -> V_169 - 1 ) ;
V_163 = V_155 -> V_9 ;
if ( V_163 -> V_12 == F_2 ( V_24 ) ) {
V_167 = ( T_10 * ) V_163 ;
V_162 = 0 ;
V_168 = F_24 ( V_167 -> V_65 [ F_3 ( V_167 -> V_8 . V_15 ) - 1 ] . V_68 ) ;
} else {
ASSERT ( V_163 -> V_12 == F_2 ( V_13 ) ) ;
V_166 = ( T_4 * ) V_163 ;
V_162 = F_3 ( V_166 -> V_8 . V_14 ) ;
V_168 = F_24 ( V_166 -> V_64 [ F_3 ( V_166 -> V_8 . V_15 ) - 1 ] . V_68 ) ;
}
V_157 = V_158 = NULL ;
if ( ( V_153 = F_24 ( V_163 -> V_40 ) ) ) {
error = F_8 ( V_27 , V_160 , V_153 , - 1 , & V_157 , V_124 ) ;
if ( error )
goto V_170;
V_164 = V_157 -> V_9 ;
if ( F_87 (
F_24 ( V_164 -> V_39 ) != V_152 ||
V_164 -> V_12 != V_163 -> V_12 ) ) {
F_88 ( L_2 ,
V_17 , V_4 ) ;
error = F_63 ( V_18 ) ;
goto V_170;
}
V_164 -> V_39 = F_25 ( V_151 ) ;
F_13 ( V_27 , V_157 ,
F_14 ( V_164 , & V_164 -> V_39 ,
sizeof( V_164 -> V_39 ) ) ) ;
V_157 = NULL ;
}
if ( ( V_153 = F_24 ( V_163 -> V_39 ) ) ) {
error = F_8 ( V_27 , V_160 , V_153 , - 1 , & V_157 , V_124 ) ;
if ( error )
goto V_170;
V_164 = V_157 -> V_9 ;
if ( F_87 (
F_24 ( V_164 -> V_40 ) != V_152 ||
V_164 -> V_12 != V_163 -> V_12 ) ) {
F_88 ( L_3 ,
V_17 , V_4 ) ;
error = F_63 ( V_18 ) ;
goto V_170;
}
V_164 -> V_40 = F_25 ( V_151 ) ;
F_13 ( V_27 , V_157 ,
F_14 ( V_164 , & V_164 -> V_40 ,
sizeof( V_164 -> V_40 ) ) ) ;
V_157 = NULL ;
}
V_154 = V_4 -> V_67 ;
V_14 = - 1 ;
for (; ; ) {
error = F_8 ( V_27 , V_160 , V_154 , - 1 , & V_158 , V_124 ) ;
if ( error )
goto V_170;
V_165 = V_158 -> V_9 ;
if ( F_87 ( V_165 -> V_8 . V_11 . V_12 !=
F_2 ( V_13 ) ||
( V_14 >= 0 && V_14 != F_3 ( V_165 -> V_8 . V_14 ) + 1 ) ) ) {
F_88 ( L_4 ,
V_17 , V_4 ) ;
error = F_63 ( V_18 ) ;
goto V_170;
}
V_14 = F_3 ( V_165 -> V_8 . V_14 ) ;
for ( V_161 = 0 ;
V_161 < F_3 ( V_165 -> V_8 . V_15 ) &&
F_24 ( V_165 -> V_64 [ V_161 ] . V_68 ) < V_168 ;
V_161 ++ )
continue;
if ( F_87 ( V_161 == F_3 ( V_165 -> V_8 . V_15 ) ) ) {
F_88 ( L_5 ,
V_17 , V_4 ) ;
error = F_63 ( V_18 ) ;
goto V_170;
}
V_154 = F_24 ( V_165 -> V_64 [ V_161 ] . V_69 ) ;
if ( V_14 == V_162 + 1 )
break;
F_53 ( V_27 , V_158 ) ;
V_158 = NULL ;
}
for (; ; ) {
for (;
V_161 < F_3 ( V_165 -> V_8 . V_15 ) &&
F_24 ( V_165 -> V_64 [ V_161 ] . V_69 ) != V_152 ;
V_161 ++ )
continue;
if ( V_161 < F_3 ( V_165 -> V_8 . V_15 ) )
break;
V_154 = F_24 ( V_165 -> V_8 . V_11 . V_39 ) ;
F_53 ( V_27 , V_158 ) ;
V_158 = NULL ;
if ( F_87 ( V_154 == 0 ) ) {
F_88 ( L_6 ,
V_17 , V_4 ) ;
error = F_63 ( V_18 ) ;
goto V_170;
}
error = F_8 ( V_27 , V_160 , V_154 , - 1 , & V_158 , V_124 ) ;
if ( error )
goto V_170;
V_165 = V_158 -> V_9 ;
if ( F_87 (
F_3 ( V_165 -> V_8 . V_14 ) != V_14 ||
V_165 -> V_8 . V_11 . V_12 != F_2 ( V_13 ) ) ) {
F_88 ( L_7 ,
V_17 , V_4 ) ;
error = F_63 ( V_18 ) ;
goto V_170;
}
V_161 = 0 ;
}
V_165 -> V_64 [ V_161 ] . V_69 = F_25 ( V_151 ) ;
F_13 ( V_27 , V_158 ,
F_14 ( V_165 , & V_165 -> V_64 [ V_161 ] . V_69 ,
sizeof( V_165 -> V_64 [ V_161 ] . V_69 ) ) ) ;
* V_149 = V_152 ;
* V_150 = V_156 ;
return 0 ;
V_170:
if ( V_158 )
F_53 ( V_27 , V_158 ) ;
if ( V_157 )
F_53 ( V_27 , V_157 ) ;
F_53 ( V_27 , V_156 ) ;
return error ;
}
int
F_47 (
T_3 * args ,
T_1 V_151 ,
struct V_1 * V_155 )
{
T_8 * V_29 ;
int V_170 , error , V_124 , V_15 ;
T_5 * V_27 ;
T_9 * V_4 ;
F_89 ( args ) ;
V_29 = args -> V_29 ;
V_124 = args -> V_36 ;
V_27 = args -> V_38 ;
V_4 = V_29 -> V_147 ;
if ( V_124 == V_66 )
V_15 = V_4 -> V_148 ;
else
V_15 = 1 ;
for (; ; ) {
if ( ( error = F_90 ( V_27 , V_29 , V_151 , V_15 ,
F_79 ( V_124 ) | V_135 ,
0 , args -> V_134 , args -> V_138 ,
& V_170 ) ) == V_54 ) {
if ( V_124 != V_66 )
break;
if ( ( error = F_84 ( args , & V_151 ,
& V_155 ) ) )
break;
} else {
break;
}
}
F_91 ( V_27 , V_155 ) ;
return error ;
}
STATIC int
F_92 (
int V_131 ,
T_19 * V_130 ,
T_1 V_30 ,
int V_15 )
{
int V_48 ;
T_17 V_171 ;
for ( V_48 = 0 , V_171 = V_30 ; V_48 < V_131 ; V_48 ++ ) {
if ( V_130 [ V_48 ] . V_172 == V_173 ||
V_130 [ V_48 ] . V_172 == V_174 ) {
return 0 ;
}
if ( V_171 != V_130 [ V_48 ] . V_144 ) {
return 0 ;
}
V_171 += V_130 [ V_48 ] . V_145 ;
}
return V_171 == V_30 + V_15 ;
}
static int
F_93 (
struct V_3 * V_4 ,
struct V_175 * * V_130 ,
unsigned int * V_176 ,
struct V_128 * V_177 ,
unsigned int V_178 )
{
struct V_175 * V_129 ;
int V_48 ;
ASSERT ( * V_176 == 1 ) ;
ASSERT ( V_178 >= 1 ) ;
if ( V_178 > 1 ) {
V_129 = F_94 ( V_178 * sizeof( struct V_175 ) , V_141 ) ;
if ( ! V_129 )
return V_179 ;
* V_130 = V_129 ;
}
* V_176 = V_178 ;
V_129 = * V_130 ;
for ( V_48 = 0 ; V_48 < * V_176 ; V_48 ++ ) {
ASSERT ( V_177 [ V_48 ] . V_172 != V_174 &&
V_177 [ V_48 ] . V_172 != V_173 ) ;
V_129 [ V_48 ] . V_180 = F_95 ( V_4 , V_177 [ V_48 ] . V_172 ) ;
V_129 [ V_48 ] . V_181 = F_96 ( V_4 , V_177 [ V_48 ] . V_145 ) ;
}
return 0 ;
}
static int
F_97 (
struct V_26 * V_38 ,
struct V_28 * V_29 ,
T_1 V_30 ,
T_2 V_31 ,
int V_36 ,
struct V_175 * * V_129 ,
int * V_176 )
{
struct V_3 * V_4 = V_29 -> V_147 ;
int V_182 ;
int error = 0 ;
struct V_128 V_183 ;
struct V_128 * V_177 = & V_183 ;
int V_178 ;
ASSERT ( V_129 && * V_129 ) ;
ASSERT ( * V_176 == 1 ) ;
V_182 = ( V_36 == V_66 ) ? V_4 -> V_148 : 1 ;
if ( V_31 == - 1 || V_31 == - 2 ) {
if ( V_182 != 1 )
V_177 = F_94 ( sizeof( V_183 ) * V_182 , V_141 ) ;
V_178 = V_182 ;
error = F_98 ( V_29 , ( T_17 ) V_30 , V_182 , V_177 ,
& V_178 , F_79 ( V_36 ) ) ;
if ( error )
goto V_184;
} else {
V_177 -> V_172 = F_99 ( V_4 , V_31 ) ;
V_177 -> V_144 = ( T_17 ) V_30 ;
V_177 -> V_145 = V_182 ;
V_177 -> V_185 = 0 ;
V_178 = 1 ;
}
if ( ! F_92 ( V_178 , V_177 , V_30 , V_182 ) ) {
error = V_31 == - 2 ? - 1 : F_63 ( V_18 ) ;
if ( F_87 ( error == V_18 ) ) {
if ( V_186 >= V_17 ) {
int V_48 ;
F_100 ( V_4 , L_8 ,
V_16 , ( long long ) V_30 ,
( long long ) V_29 -> V_187 ) ;
for ( V_48 = 0 ; V_48 < * V_176 ; V_48 ++ ) {
F_100 ( V_4 ,
L_9 ,
V_48 ,
( long long ) V_177 [ V_48 ] . V_144 ,
( long long ) V_177 [ V_48 ] . V_172 ,
( long long ) V_177 [ V_48 ] . V_145 ,
V_177 [ V_48 ] . V_185 ) ;
}
}
F_88 ( L_10 ,
V_17 , V_4 ) ;
}
goto V_184;
}
error = F_93 ( V_4 , V_129 , V_176 , V_177 , V_178 ) ;
V_184:
if ( V_177 != & V_183 )
F_82 ( V_177 ) ;
return error ;
}
int
F_12 (
struct V_26 * V_38 ,
struct V_28 * V_29 ,
T_1 V_30 ,
T_2 V_31 ,
struct V_1 * * V_32 ,
int V_36 )
{
struct V_1 * V_2 ;
struct V_175 V_129 ;
struct V_175 * V_130 ;
int V_131 ;
int error ;
* V_32 = NULL ;
V_130 = & V_129 ;
V_131 = 1 ;
error = F_97 ( V_38 , V_29 , V_30 , V_31 , V_36 ,
& V_130 , & V_131 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_188;
}
V_2 = F_101 ( V_38 , V_29 -> V_147 -> V_189 ,
V_130 , V_131 , 0 ) ;
error = V_2 ? V_2 -> V_190 : F_63 ( V_191 ) ;
if ( error ) {
F_53 ( V_38 , V_2 ) ;
goto V_188;
}
* V_32 = V_2 ;
V_188:
if ( V_130 != & V_129 )
F_82 ( V_130 ) ;
return error ;
}
int
F_9 (
struct V_26 * V_38 ,
struct V_28 * V_29 ,
T_1 V_30 ,
T_2 V_31 ,
struct V_1 * * V_32 ,
int V_36 ,
const struct V_192 * V_193 )
{
struct V_1 * V_2 ;
struct V_175 V_129 ;
struct V_175 * V_130 ;
int V_131 ;
int error ;
* V_32 = NULL ;
V_130 = & V_129 ;
V_131 = 1 ;
error = F_97 ( V_38 , V_29 , V_30 , V_31 , V_36 ,
& V_130 , & V_131 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_188;
}
error = F_102 ( V_29 -> V_147 , V_38 ,
V_29 -> V_147 -> V_189 ,
V_130 , V_131 , 0 , & V_2 , V_193 ) ;
if ( error )
goto V_188;
if ( V_36 == V_76 )
F_103 ( V_2 , V_194 ) ;
else
F_103 ( V_2 , V_195 ) ;
{
T_20 * V_8 = V_2 -> V_9 ;
T_21 * free = V_2 -> V_9 ;
T_13 * V_11 = V_2 -> V_9 ;
V_85 V_12 , V_196 ;
struct V_3 * V_4 = V_29 -> V_147 ;
V_12 = F_3 ( V_11 -> V_12 ) ;
V_196 = F_24 ( V_8 -> V_12 ) ;
if ( F_87 (
F_104 ( ( V_12 != V_13 ) &&
( V_12 != V_20 ) &&
( V_12 != V_197 ) &&
( V_12 != V_24 ) &&
( V_196 != V_198 ) &&
( V_196 != V_199 ) &&
( free -> V_8 . V_12 != F_25 ( V_200 ) ) ,
V_4 , V_201 ,
V_202 ) ) ) {
F_105 ( V_2 , V_203 ) ;
F_4 ( L_11 ,
V_17 , V_4 , V_11 ) ;
error = F_63 ( V_18 ) ;
F_53 ( V_38 , V_2 ) ;
goto V_188;
}
}
* V_32 = V_2 ;
V_188:
if ( V_130 != & V_129 )
F_82 ( V_130 ) ;
return error ;
}
T_2
F_106 (
struct V_26 * V_38 ,
struct V_28 * V_29 ,
T_1 V_30 ,
T_2 V_31 ,
int V_36 ,
const struct V_192 * V_193 )
{
struct V_175 V_129 ;
struct V_175 * V_130 ;
int V_131 ;
int error ;
V_130 = & V_129 ;
V_131 = 1 ;
error = F_97 ( V_38 , V_29 , V_30 , V_31 , V_36 ,
& V_130 , & V_131 ) ;
if ( error ) {
if ( error == - 1 )
error = 0 ;
goto V_188;
}
V_31 = V_130 [ 0 ] . V_180 ;
F_107 ( V_29 -> V_147 -> V_189 , V_130 , V_131 , V_193 ) ;
V_188:
if ( V_130 != & V_129 )
F_82 ( V_130 ) ;
if ( error )
return - 1 ;
return V_31 ;
}
T_6 *
F_108 ( void )
{
return F_109 ( V_204 , V_205 ) ;
}
STATIC void
F_46 ( T_6 * V_42 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_42 -> V_53 . V_50 ; V_48 ++ )
V_42 -> V_53 . V_52 [ V_48 ] . V_2 = NULL ;
V_42 -> V_53 . V_50 = 0 ;
}
void
F_110 ( T_6 * V_42 )
{
F_46 ( V_42 ) ;
#ifdef F_28
memset ( ( char * ) V_42 , 0 , sizeof( * V_42 ) ) ;
#endif
F_111 ( V_204 , V_42 ) ;
}
