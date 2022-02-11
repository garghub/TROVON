STATIC int
F_1 ( const void * V_1 , const void * V_2 )
{
T_1 * V_3 , * V_4 ;
V_3 = ( T_1 * ) V_1 ;
V_4 = ( T_1 * ) V_2 ;
if ( V_3 -> V_5 < V_4 -> V_5 ) {
return ( - 1 ) ;
} else if ( V_3 -> V_5 > V_4 -> V_5 ) {
return ( 1 ) ;
} else {
return ( V_3 -> V_6 - V_4 -> V_6 ) ;
}
}
int
F_2 ( T_2 * V_7 )
{
T_3 * V_8 ;
T_1 * V_9 , * V_10 ;
T_4 * V_11 ;
T_5 * V_12 ;
T_6 * V_13 ;
int V_14 , V_15 , V_16 , V_17 ;
int error ;
ASSERT ( V_7 != NULL ) ;
V_13 = V_7 -> V_13 ;
ASSERT ( V_13 != NULL ) ;
ASSERT ( V_13 -> V_18 != NULL ) ;
V_11 = ( T_4 * ) V_13 -> V_18 -> V_19 . V_20 ;
ASSERT ( V_11 != NULL ) ;
if ( ! V_11 -> V_21 . V_16 )
return ( 0 ) ;
V_8 = V_7 -> V_8 ;
ASSERT ( V_8 != NULL ) ;
F_3 ( V_7 ) ;
if ( V_7 -> V_22 == 0 ||
( F_4 ( V_8 ) &&
( V_13 -> V_18 -> V_23 + V_11 -> V_21 . V_16 * 16 ) < V_7 -> V_22 ) ) {
for ( V_17 = 0 , V_12 = & V_11 -> V_24 [ 0 ] ; V_17 < V_11 -> V_21 . V_16 ; V_17 ++ ) {
error = V_7 -> V_25 ( V_7 ,
V_12 -> V_26 ,
V_12 -> V_27 ,
( int ) V_12 -> V_28 ,
( int ) V_12 -> V_29 ,
& V_12 -> V_27 [ V_12 -> V_28 ] ) ;
if ( V_7 -> V_30 )
break;
if ( error )
return error ;
V_12 = F_5 ( V_12 ) ;
}
F_6 ( V_7 ) ;
return ( 0 ) ;
}
if ( V_7 -> V_22 == 0 )
return 0 ;
V_14 = V_11 -> V_21 . V_16 * sizeof( * V_9 ) ;
V_10 = V_9 = F_7 ( V_14 , V_31 | V_32 ) ;
V_15 = 0 ;
for ( V_17 = 0 , V_12 = & V_11 -> V_24 [ 0 ] ; V_17 < V_11 -> V_21 . V_16 ; V_17 ++ ) {
if ( F_8 (
( ( char * ) V_12 < ( char * ) V_11 ) ||
( ( char * ) V_12 >= ( ( char * ) V_11 + V_13 -> V_18 -> V_23 ) ) ) ) {
F_9 ( L_1 ,
V_33 ,
V_7 -> V_13 -> V_34 , V_12 ) ;
F_10 ( V_9 ) ;
return F_11 ( V_35 ) ;
}
V_10 -> V_6 = V_17 ;
V_10 -> V_5 = F_12 ( V_12 -> V_27 , V_12 -> V_28 ) ;
V_10 -> V_36 = V_12 -> V_27 ;
V_10 -> V_28 = V_12 -> V_28 ;
V_10 -> V_29 = V_12 -> V_29 ;
V_10 -> V_26 = V_12 -> V_26 ;
V_12 = F_5 ( V_12 ) ;
V_10 ++ ;
V_15 ++ ;
}
F_13 ( V_9 , V_15 , sizeof( * V_9 ) , F_1 ) ;
V_16 = 0 ;
V_8 -> V_37 = 1 ;
V_8 -> V_38 = 0 ;
for ( V_10 = V_9 , V_17 = 0 ; V_17 < V_15 ; V_17 ++ , V_10 ++ ) {
if ( V_10 -> V_5 == V_8 -> V_39 ) {
if ( V_8 -> V_40 == V_16 ) {
break;
}
V_16 ++ ;
} else if ( V_10 -> V_5 > V_8 -> V_39 ) {
break;
}
}
if ( V_17 == V_15 ) {
F_10 ( V_9 ) ;
return ( 0 ) ;
}
for ( ; V_17 < V_15 ; V_17 ++ , V_10 ++ ) {
if ( V_8 -> V_39 != V_10 -> V_5 ) {
V_8 -> V_39 = V_10 -> V_5 ;
V_8 -> V_40 = 0 ;
}
error = V_7 -> V_25 ( V_7 ,
V_10 -> V_26 ,
V_10 -> V_36 ,
V_10 -> V_28 ,
V_10 -> V_29 ,
& V_10 -> V_36 [ V_10 -> V_28 ] ) ;
if ( error )
return error ;
if ( V_7 -> V_30 )
break;
V_8 -> V_40 ++ ;
}
F_10 ( V_9 ) ;
return ( 0 ) ;
}
STATIC int
F_14 ( T_2 * V_7 )
{
T_3 * V_8 ;
T_7 * V_41 ;
T_8 * V_42 ;
struct V_43 V_44 ;
struct V_45 V_46 ;
struct V_47 * V_48 ;
int error , V_17 ;
struct V_49 * V_50 ;
struct V_51 * V_13 = V_7 -> V_13 ;
F_15 ( V_7 ) ;
V_8 = V_7 -> V_8 ;
V_8 -> V_37 = 1 ;
V_50 = NULL ;
if ( V_8 -> V_38 > 0 ) {
error = F_16 ( NULL , V_13 , V_8 -> V_38 , - 1 ,
& V_50 , V_52 ) ;
if ( ( error != 0 ) && ( error != V_35 ) )
return ( error ) ;
if ( V_50 ) {
struct V_53 * V_54 ;
V_42 = V_50 -> V_55 ;
switch ( F_17 ( V_42 -> V_21 . V_56 . V_57 ) ) {
case V_58 :
case V_59 :
F_18 ( V_7 ) ;
F_19 ( NULL , V_50 ) ;
V_50 = NULL ;
break;
case V_60 :
case V_61 :
V_41 = V_50 -> V_55 ;
F_20 ( & V_44 , V_41 ) ;
V_54 = F_21 ( V_41 ) ;
if ( V_8 -> V_39 > F_22 (
V_54 [ V_44 . V_16 - 1 ] . V_39 ) ) {
F_18 ( V_7 ) ;
F_19 ( NULL , V_50 ) ;
V_50 = NULL ;
} else if ( V_8 -> V_39 <= F_22 (
V_54 [ 0 ] . V_39 ) ) {
F_18 ( V_7 ) ;
F_19 ( NULL , V_50 ) ;
V_50 = NULL ;
}
break;
default:
F_18 ( V_7 ) ;
F_19 ( NULL , V_50 ) ;
V_50 = NULL ;
}
}
}
if ( V_50 == NULL ) {
V_8 -> V_38 = 0 ;
for (; ; ) {
T_9 V_57 ;
error = F_16 ( NULL , V_13 ,
V_8 -> V_38 , - 1 , & V_50 ,
V_52 ) ;
if ( error )
return ( error ) ;
V_42 = V_50 -> V_55 ;
V_57 = F_17 ( V_42 -> V_21 . V_56 . V_57 ) ;
if ( V_57 == V_60 ||
V_57 == V_61 )
break;
if ( V_57 != V_58 &&
V_57 != V_59 ) {
F_9 ( L_2 ,
V_33 ,
V_7 -> V_13 -> V_34 ,
V_42 ) ;
F_19 ( NULL , V_50 ) ;
return F_11 ( V_35 ) ;
}
V_13 -> V_62 -> V_63 ( & V_46 , V_42 ) ;
V_48 = V_13 -> V_62 -> V_64 ( V_42 ) ;
for ( V_17 = 0 ; V_17 < V_46 . V_16 ; V_48 ++ , V_17 ++ ) {
if ( V_8 -> V_39
<= F_22 ( V_48 -> V_39 ) ) {
V_8 -> V_38 = F_22 ( V_48 -> V_65 ) ;
F_23 ( V_7 ,
V_48 ) ;
break;
}
}
if ( V_17 == V_46 . V_16 ) {
F_19 ( NULL , V_50 ) ;
return 0 ;
}
F_19 ( NULL , V_50 ) ;
}
}
ASSERT ( V_50 != NULL ) ;
for (; ; ) {
V_41 = V_50 -> V_55 ;
error = F_24 ( V_50 , V_7 ) ;
if ( error ) {
F_19 ( NULL , V_50 ) ;
return error ;
}
F_20 ( & V_44 , V_41 ) ;
if ( V_7 -> V_30 || V_44 . V_66 == 0 )
break;
V_8 -> V_38 = V_44 . V_66 ;
F_19 ( NULL , V_50 ) ;
error = F_25 ( NULL , V_13 , V_8 -> V_38 , - 1 , & V_50 ) ;
if ( error )
return error ;
}
F_19 ( NULL , V_50 ) ;
return 0 ;
}
int
F_24 (
struct V_49 * V_50 ,
struct V_67 * V_7 )
{
struct V_68 * V_8 ;
struct V_69 * V_41 ;
struct V_43 V_70 ;
struct V_53 * V_54 ;
struct V_53 * V_71 ;
int V_72 ;
int V_17 ;
F_26 ( V_7 ) ;
V_41 = V_50 -> V_55 ;
F_20 ( & V_70 , V_41 ) ;
V_54 = F_21 ( V_41 ) ;
V_8 = V_7 -> V_8 ;
V_8 -> V_37 = 1 ;
if ( V_7 -> V_73 ) {
V_71 = & V_54 [ 0 ] ;
for ( V_17 = 0 ; V_17 < V_70 . V_16 ; V_71 ++ , V_17 ++ ) {
if ( F_22 ( V_71 -> V_39 ) == V_8 -> V_39 ) {
if ( V_8 -> V_40 == V_7 -> V_74 ) {
V_7 -> V_74 = 0 ;
break;
}
V_7 -> V_74 ++ ;
} else if ( F_22 ( V_71 -> V_39 ) >
V_8 -> V_39 ) {
V_7 -> V_74 = 0 ;
break;
}
}
if ( V_17 == V_70 . V_16 ) {
F_27 ( V_7 ) ;
return 0 ;
}
} else {
V_71 = & V_54 [ 0 ] ;
V_17 = 0 ;
}
V_7 -> V_73 = 0 ;
V_72 = 0 ;
for (; V_17 < V_70 . V_16 ; V_71 ++ , V_17 ++ ) {
if ( F_22 ( V_71 -> V_39 ) != V_8 -> V_39 ) {
V_8 -> V_39 = F_22 ( V_71 -> V_39 ) ;
V_8 -> V_40 = 0 ;
}
if ( V_71 -> V_26 & V_75 )
continue;
if ( V_71 -> V_26 & V_76 ) {
T_10 * V_77 =
F_28 ( V_41 , V_17 ) ;
V_72 = V_7 -> V_25 ( V_7 ,
V_71 -> V_26 ,
V_77 -> V_27 ,
( int ) V_77 -> V_28 ,
F_17 ( V_77 -> V_29 ) ,
& V_77 -> V_27 [ V_77 -> V_28 ] ) ;
if ( V_72 )
return V_72 ;
} else {
T_11 * V_78 =
F_29 ( V_41 , V_17 ) ;
int V_29 = F_22 ( V_78 -> V_29 ) ;
if ( V_7 -> V_79 ) {
T_12 args ;
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_80 = V_7 -> V_13 -> V_34 -> V_81 ;
args . V_13 = V_7 -> V_13 ;
args . V_82 = V_52 ;
args . V_29 = V_29 ;
args . V_83 = V_29 ;
args . V_84 = F_7 ( V_29 , V_31 | V_32 ) ;
args . V_85 = F_22 ( V_78 -> V_86 ) ;
args . V_87 = F_30 (
args . V_13 -> V_34 , V_29 ) ;
V_72 = F_31 ( & args ) ;
if ( V_72 )
return V_72 ;
V_72 = V_7 -> V_25 ( V_7 ,
V_71 -> V_26 ,
V_78 -> V_36 ,
( int ) V_78 -> V_28 ,
V_29 ,
args . V_84 ) ;
F_10 ( args . V_84 ) ;
} else {
V_72 = V_7 -> V_25 ( V_7 ,
V_71 -> V_26 ,
V_78 -> V_36 ,
( int ) V_78 -> V_28 ,
V_29 ,
NULL ) ;
}
if ( V_72 )
return V_72 ;
}
if ( V_7 -> V_30 )
break;
V_8 -> V_40 ++ ;
}
F_32 ( V_7 ) ;
return V_72 ;
}
STATIC int
F_33 ( T_2 * V_7 )
{
int error ;
struct V_49 * V_50 ;
F_34 ( V_7 ) ;
V_7 -> V_8 -> V_38 = 0 ;
error = F_25 ( NULL , V_7 -> V_13 , 0 , - 1 , & V_50 ) ;
if ( error )
return F_11 ( error ) ;
error = F_24 ( V_50 , V_7 ) ;
F_19 ( NULL , V_50 ) ;
return F_11 ( error ) ;
}
int
F_35 (
T_2 * V_7 )
{
int error ;
T_6 * V_13 = V_7 -> V_13 ;
T_13 V_88 ;
F_36 ( V_89 ) ;
if ( F_37 ( V_13 -> V_34 ) )
return V_90 ;
V_88 = F_38 ( V_13 ) ;
if ( ! F_39 ( V_13 ) ) {
error = 0 ;
} else if ( V_13 -> V_91 . V_92 == V_93 ) {
error = F_2 ( V_7 ) ;
} else if ( F_40 ( V_13 , V_52 ) ) {
error = F_33 ( V_7 ) ;
} else {
error = F_14 ( V_7 ) ;
}
F_41 ( V_13 , V_88 ) ;
return error ;
}
STATIC int
F_42 (
T_2 * V_7 ,
int V_26 ,
unsigned char * V_36 ,
int V_28 ,
int V_29 ,
unsigned char * V_84 )
{
struct V_94 * V_95 = (struct V_94 * ) V_7 -> V_95 ;
T_14 * V_96 ;
int V_97 ;
ASSERT ( ! ( V_7 -> V_26 & V_98 ) ) ;
ASSERT ( V_7 -> V_16 >= 0 ) ;
ASSERT ( V_7 -> V_16 < ( V_99 / 8 ) ) ;
ASSERT ( V_7 -> V_100 >= sizeof( * V_95 ) ) ;
ASSERT ( V_7 -> V_100 <= V_7 -> V_22 ) ;
if ( ( ( V_7 -> V_26 & V_101 ) == 0 ) !=
( ( V_26 & V_102 ) == 0 ) )
return 0 ;
if ( ( ( V_7 -> V_26 & V_103 ) == 0 ) !=
( ( V_26 & V_104 ) == 0 ) )
return 0 ;
V_97 = sizeof( * V_95 ) +
V_7 -> V_16 * sizeof( V_95 -> V_105 [ 0 ] ) ;
V_7 -> V_100 -= F_43 ( V_28 ) ;
if ( V_7 -> V_100 < V_97 ) {
F_44 ( V_7 ) ;
V_95 -> V_106 = 1 ;
V_7 -> V_30 = 1 ;
return 1 ;
}
V_96 = ( T_14 * ) & V_7 -> V_95 [ V_7 -> V_100 ] ;
V_96 -> V_107 = V_29 ;
memcpy ( V_96 -> V_108 , V_36 , V_28 ) ;
V_96 -> V_108 [ V_28 ] = 0 ;
V_95 -> V_105 [ V_7 -> V_16 ++ ] = V_7 -> V_100 ;
V_95 -> V_109 = V_7 -> V_16 ;
F_45 ( V_7 ) ;
return 0 ;
}
int
F_46 (
T_6 * V_13 ,
char * V_110 ,
int V_22 ,
int V_26 ,
T_3 * V_8 )
{
T_2 V_7 ;
struct V_94 * V_95 ;
int error ;
if ( V_8 -> V_111 || V_8 -> V_112 )
return ( F_11 ( V_113 ) ) ;
if ( ( V_8 -> V_37 == 0 ) &&
( V_8 -> V_39 || V_8 -> V_38 || V_8 -> V_40 ) )
return F_11 ( V_113 ) ;
if ( ( ( long ) V_110 ) & ( sizeof( int ) - 1 ) )
return F_11 ( V_114 ) ;
if ( V_26 & V_98 )
V_22 = 0 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_13 = V_13 ;
V_7 . V_8 = V_8 ;
V_7 . V_73 = 1 ;
V_7 . V_26 = V_26 ;
V_7 . V_95 = V_110 ;
V_7 . V_22 = ( V_22 & ~ ( sizeof( int ) - 1 ) ) ;
V_7 . V_100 = V_7 . V_22 ;
V_7 . V_25 = F_42 ;
V_95 = (struct V_94 * ) V_7 . V_95 ;
V_95 -> V_109 = 0 ;
V_95 -> V_106 = 0 ;
V_95 -> V_105 [ 0 ] = V_7 . V_22 ;
error = F_35 ( & V_7 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
