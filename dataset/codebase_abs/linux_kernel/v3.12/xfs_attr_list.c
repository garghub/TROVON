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
F_15 ( V_7 ) ;
V_8 = V_7 -> V_8 ;
V_8 -> V_37 = 1 ;
V_50 = NULL ;
if ( V_8 -> V_38 > 0 ) {
error = F_16 ( NULL , V_7 -> V_13 , V_8 -> V_38 , - 1 ,
& V_50 , V_51 ) ;
if ( ( error != 0 ) && ( error != V_35 ) )
return ( error ) ;
if ( V_50 ) {
struct V_52 * V_53 ;
V_42 = V_50 -> V_54 ;
switch ( F_17 ( V_42 -> V_21 . V_55 . V_56 ) ) {
case V_57 :
case V_58 :
F_18 ( V_7 ) ;
F_19 ( NULL , V_50 ) ;
V_50 = NULL ;
break;
case V_59 :
case V_60 :
V_41 = V_50 -> V_54 ;
F_20 ( & V_44 , V_41 ) ;
V_53 = F_21 ( V_41 ) ;
if ( V_8 -> V_39 > F_22 (
V_53 [ V_44 . V_16 - 1 ] . V_39 ) ) {
F_18 ( V_7 ) ;
F_19 ( NULL , V_50 ) ;
V_50 = NULL ;
} else if ( V_8 -> V_39 <= F_22 (
V_53 [ 0 ] . V_39 ) ) {
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
T_9 V_56 ;
error = F_16 ( NULL , V_7 -> V_13 ,
V_8 -> V_38 , - 1 , & V_50 ,
V_51 ) ;
if ( error )
return ( error ) ;
V_42 = V_50 -> V_54 ;
V_56 = F_17 ( V_42 -> V_21 . V_55 . V_56 ) ;
if ( V_56 == V_59 ||
V_56 == V_60 )
break;
if ( V_56 != V_57 &&
V_56 != V_58 ) {
F_9 ( L_2 ,
V_33 ,
V_7 -> V_13 -> V_34 ,
V_42 ) ;
F_19 ( NULL , V_50 ) ;
return F_11 ( V_35 ) ;
}
F_23 ( & V_46 , V_42 ) ;
V_48 = F_24 ( V_42 ) ;
for ( V_17 = 0 ; V_17 < V_46 . V_16 ; V_48 ++ , V_17 ++ ) {
if ( V_8 -> V_39
<= F_22 ( V_48 -> V_39 ) ) {
V_8 -> V_38 = F_22 ( V_48 -> V_61 ) ;
F_25 ( V_7 ,
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
V_41 = V_50 -> V_54 ;
error = F_26 ( V_50 , V_7 ) ;
if ( error ) {
F_19 ( NULL , V_50 ) ;
return error ;
}
F_20 ( & V_44 , V_41 ) ;
if ( V_7 -> V_30 || V_44 . V_62 == 0 )
break;
V_8 -> V_38 = V_44 . V_62 ;
F_19 ( NULL , V_50 ) ;
error = F_27 ( NULL , V_7 -> V_13 , V_8 -> V_38 , - 1 ,
& V_50 ) ;
if ( error )
return error ;
}
F_19 ( NULL , V_50 ) ;
return 0 ;
}
int
F_26 (
struct V_49 * V_50 ,
struct V_63 * V_7 )
{
struct V_64 * V_8 ;
struct V_65 * V_41 ;
struct V_43 V_66 ;
struct V_52 * V_53 ;
struct V_52 * V_67 ;
int V_68 ;
int V_17 ;
F_28 ( V_7 ) ;
V_41 = V_50 -> V_54 ;
F_20 ( & V_66 , V_41 ) ;
V_53 = F_21 ( V_41 ) ;
V_8 = V_7 -> V_8 ;
V_8 -> V_37 = 1 ;
if ( V_7 -> V_69 ) {
V_67 = & V_53 [ 0 ] ;
for ( V_17 = 0 ; V_17 < V_66 . V_16 ; V_67 ++ , V_17 ++ ) {
if ( F_22 ( V_67 -> V_39 ) == V_8 -> V_39 ) {
if ( V_8 -> V_40 == V_7 -> V_70 ) {
V_7 -> V_70 = 0 ;
break;
}
V_7 -> V_70 ++ ;
} else if ( F_22 ( V_67 -> V_39 ) >
V_8 -> V_39 ) {
V_7 -> V_70 = 0 ;
break;
}
}
if ( V_17 == V_66 . V_16 ) {
F_29 ( V_7 ) ;
return 0 ;
}
} else {
V_67 = & V_53 [ 0 ] ;
V_17 = 0 ;
}
V_7 -> V_69 = 0 ;
V_68 = 0 ;
for (; V_17 < V_66 . V_16 ; V_67 ++ , V_17 ++ ) {
if ( F_22 ( V_67 -> V_39 ) != V_8 -> V_39 ) {
V_8 -> V_39 = F_22 ( V_67 -> V_39 ) ;
V_8 -> V_40 = 0 ;
}
if ( V_67 -> V_26 & V_71 )
continue;
if ( V_67 -> V_26 & V_72 ) {
T_10 * V_73 =
F_30 ( V_41 , V_17 ) ;
V_68 = V_7 -> V_25 ( V_7 ,
V_67 -> V_26 ,
V_73 -> V_27 ,
( int ) V_73 -> V_28 ,
F_17 ( V_73 -> V_29 ) ,
& V_73 -> V_27 [ V_73 -> V_28 ] ) ;
if ( V_68 )
return V_68 ;
} else {
T_11 * V_74 =
F_31 ( V_41 , V_17 ) ;
int V_29 = F_22 ( V_74 -> V_29 ) ;
if ( V_7 -> V_75 ) {
T_12 args ;
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_13 = V_7 -> V_13 ;
args . V_76 = V_51 ;
args . V_29 = V_29 ;
args . V_77 = F_7 ( V_29 , V_31 | V_32 ) ;
args . V_78 = F_22 ( V_74 -> V_79 ) ;
args . V_80 = F_32 (
args . V_13 -> V_34 , V_29 ) ;
V_68 = F_33 ( & args ) ;
if ( V_68 )
return V_68 ;
V_68 = V_7 -> V_25 ( V_7 ,
V_67 -> V_26 ,
V_74 -> V_36 ,
( int ) V_74 -> V_28 ,
V_29 ,
args . V_77 ) ;
F_10 ( args . V_77 ) ;
} else {
V_68 = V_7 -> V_25 ( V_7 ,
V_67 -> V_26 ,
V_74 -> V_36 ,
( int ) V_74 -> V_28 ,
V_29 ,
NULL ) ;
}
if ( V_68 )
return V_68 ;
}
if ( V_7 -> V_30 )
break;
V_8 -> V_40 ++ ;
}
F_34 ( V_7 ) ;
return V_68 ;
}
STATIC int
F_35 ( T_2 * V_7 )
{
int error ;
struct V_49 * V_50 ;
F_36 ( V_7 ) ;
V_7 -> V_8 -> V_38 = 0 ;
error = F_27 ( NULL , V_7 -> V_13 , 0 , - 1 , & V_50 ) ;
if ( error )
return F_11 ( error ) ;
error = F_26 ( V_50 , V_7 ) ;
F_19 ( NULL , V_50 ) ;
return F_11 ( error ) ;
}
int
F_37 (
T_2 * V_7 )
{
int error ;
T_6 * V_13 = V_7 -> V_13 ;
F_38 ( V_81 ) ;
if ( F_39 ( V_13 -> V_34 ) )
return V_82 ;
F_40 ( V_13 , V_83 ) ;
if ( ! F_41 ( V_13 ) ) {
error = 0 ;
} else if ( V_13 -> V_84 . V_85 == V_86 ) {
error = F_2 ( V_7 ) ;
} else if ( F_42 ( V_13 , V_51 ) ) {
error = F_35 ( V_7 ) ;
} else {
error = F_14 ( V_7 ) ;
}
F_43 ( V_13 , V_83 ) ;
return error ;
}
STATIC int
F_44 (
T_2 * V_7 ,
int V_26 ,
unsigned char * V_36 ,
int V_28 ,
int V_29 ,
unsigned char * V_77 )
{
struct V_87 * V_88 = (struct V_87 * ) V_7 -> V_88 ;
T_13 * V_89 ;
int V_90 ;
ASSERT ( ! ( V_7 -> V_26 & V_91 ) ) ;
ASSERT ( V_7 -> V_16 >= 0 ) ;
ASSERT ( V_7 -> V_16 < ( V_92 / 8 ) ) ;
ASSERT ( V_7 -> V_93 >= sizeof( * V_88 ) ) ;
ASSERT ( V_7 -> V_93 <= V_7 -> V_22 ) ;
if ( ( ( V_7 -> V_26 & V_94 ) == 0 ) !=
( ( V_26 & V_95 ) == 0 ) )
return 0 ;
if ( ( ( V_7 -> V_26 & V_96 ) == 0 ) !=
( ( V_26 & V_97 ) == 0 ) )
return 0 ;
V_90 = sizeof( * V_88 ) +
V_7 -> V_16 * sizeof( V_88 -> V_98 [ 0 ] ) ;
V_7 -> V_93 -= F_45 ( V_28 ) ;
if ( V_7 -> V_93 < V_90 ) {
F_46 ( V_7 ) ;
V_88 -> V_99 = 1 ;
V_7 -> V_30 = 1 ;
return 1 ;
}
V_89 = ( T_13 * ) & V_7 -> V_88 [ V_7 -> V_93 ] ;
V_89 -> V_100 = V_29 ;
memcpy ( V_89 -> V_101 , V_36 , V_28 ) ;
V_89 -> V_101 [ V_28 ] = 0 ;
V_88 -> V_98 [ V_7 -> V_16 ++ ] = V_7 -> V_93 ;
V_88 -> V_102 = V_7 -> V_16 ;
F_47 ( V_7 ) ;
return 0 ;
}
int
F_48 (
T_6 * V_13 ,
char * V_103 ,
int V_22 ,
int V_26 ,
T_3 * V_8 )
{
T_2 V_7 ;
struct V_87 * V_88 ;
int error ;
if ( V_8 -> V_104 || V_8 -> V_105 )
return ( F_11 ( V_106 ) ) ;
if ( ( V_8 -> V_37 == 0 ) &&
( V_8 -> V_39 || V_8 -> V_38 || V_8 -> V_40 ) )
return F_11 ( V_106 ) ;
if ( ( ( long ) V_103 ) & ( sizeof( int ) - 1 ) )
return F_11 ( V_107 ) ;
if ( V_26 & V_91 )
V_22 = 0 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_13 = V_13 ;
V_7 . V_8 = V_8 ;
V_7 . V_69 = 1 ;
V_7 . V_26 = V_26 ;
V_7 . V_88 = V_103 ;
V_7 . V_22 = ( V_22 & ~ ( sizeof( int ) - 1 ) ) ;
V_7 . V_93 = V_7 . V_22 ;
V_7 . V_25 = F_44 ;
V_88 = (struct V_87 * ) V_7 . V_88 ;
V_88 -> V_102 = 0 ;
V_88 -> V_99 = 0 ;
V_88 -> V_98 [ 0 ] = V_7 . V_22 ;
error = F_37 ( & V_7 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
