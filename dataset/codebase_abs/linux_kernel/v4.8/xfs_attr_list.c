STATIC int
F_1 ( const void * V_1 , const void * V_2 )
{
T_1 * V_3 , * V_4 ;
V_3 = ( T_1 * ) V_1 ;
V_4 = ( T_1 * ) V_2 ;
if ( V_3 -> V_5 < V_4 -> V_5 ) {
return - 1 ;
} else if ( V_3 -> V_5 > V_4 -> V_5 ) {
return 1 ;
} else {
return V_3 -> V_6 - V_4 -> V_6 ;
}
}
static int
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
return 0 ;
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
( int ) V_12 -> V_29 ) ;
if ( error )
return error ;
if ( V_7 -> V_30 )
break;
V_12 = F_5 ( V_12 ) ;
}
F_6 ( V_7 ) ;
return 0 ;
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
return - V_35 ;
}
V_10 -> V_6 = V_17 ;
V_10 -> V_5 = F_11 ( V_12 -> V_27 , V_12 -> V_28 ) ;
V_10 -> V_36 = V_12 -> V_27 ;
V_10 -> V_28 = V_12 -> V_28 ;
V_10 -> V_29 = V_12 -> V_29 ;
V_10 -> V_26 = V_12 -> V_26 ;
V_12 = F_5 ( V_12 ) ;
V_10 ++ ;
V_15 ++ ;
}
F_12 ( V_9 , V_15 , sizeof( * V_9 ) , F_1 ) ;
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
return 0 ;
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
V_10 -> V_29 ) ;
if ( error ) {
F_10 ( V_9 ) ;
return error ;
}
if ( V_7 -> V_30 )
break;
V_8 -> V_40 ++ ;
}
F_10 ( V_9 ) ;
return 0 ;
}
STATIC int
F_13 ( T_2 * V_7 )
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
struct V_52 * V_53 = V_13 -> V_34 ;
F_14 ( V_7 ) ;
V_8 = V_7 -> V_8 ;
V_8 -> V_37 = 1 ;
V_50 = NULL ;
if ( V_8 -> V_38 > 0 ) {
error = F_15 ( NULL , V_13 , V_8 -> V_38 , - 1 ,
& V_50 , V_54 ) ;
if ( ( error != 0 ) && ( error != - V_35 ) )
return error ;
if ( V_50 ) {
struct V_55 * V_56 ;
V_42 = V_50 -> V_57 ;
switch ( F_16 ( V_42 -> V_21 . V_58 . V_59 ) ) {
case V_60 :
case V_61 :
F_17 ( V_7 ) ;
F_18 ( NULL , V_50 ) ;
V_50 = NULL ;
break;
case V_62 :
case V_63 :
V_41 = V_50 -> V_57 ;
F_19 ( V_53 -> V_64 ,
& V_44 , V_41 ) ;
V_56 = F_20 ( V_41 ) ;
if ( V_8 -> V_39 > F_21 (
V_56 [ V_44 . V_16 - 1 ] . V_39 ) ) {
F_17 ( V_7 ) ;
F_18 ( NULL , V_50 ) ;
V_50 = NULL ;
} else if ( V_8 -> V_39 <= F_21 (
V_56 [ 0 ] . V_39 ) ) {
F_17 ( V_7 ) ;
F_18 ( NULL , V_50 ) ;
V_50 = NULL ;
}
break;
default:
F_17 ( V_7 ) ;
F_18 ( NULL , V_50 ) ;
V_50 = NULL ;
}
}
}
if ( V_50 == NULL ) {
V_8 -> V_38 = 0 ;
for (; ; ) {
T_9 V_59 ;
error = F_15 ( NULL , V_13 ,
V_8 -> V_38 , - 1 , & V_50 ,
V_54 ) ;
if ( error )
return error ;
V_42 = V_50 -> V_57 ;
V_59 = F_16 ( V_42 -> V_21 . V_58 . V_59 ) ;
if ( V_59 == V_62 ||
V_59 == V_63 )
break;
if ( V_59 != V_60 &&
V_59 != V_61 ) {
F_9 ( L_2 ,
V_33 ,
V_7 -> V_13 -> V_34 ,
V_42 ) ;
F_18 ( NULL , V_50 ) ;
return - V_35 ;
}
V_13 -> V_65 -> V_66 ( & V_46 , V_42 ) ;
V_48 = V_13 -> V_65 -> V_67 ( V_42 ) ;
for ( V_17 = 0 ; V_17 < V_46 . V_16 ; V_48 ++ , V_17 ++ ) {
if ( V_8 -> V_39
<= F_21 ( V_48 -> V_39 ) ) {
V_8 -> V_38 = F_21 ( V_48 -> V_68 ) ;
F_22 ( V_7 ,
V_48 ) ;
break;
}
}
if ( V_17 == V_46 . V_16 ) {
F_18 ( NULL , V_50 ) ;
return 0 ;
}
F_18 ( NULL , V_50 ) ;
}
}
ASSERT ( V_50 != NULL ) ;
for (; ; ) {
V_41 = V_50 -> V_57 ;
error = F_23 ( V_50 , V_7 ) ;
if ( error ) {
F_18 ( NULL , V_50 ) ;
return error ;
}
F_19 ( V_53 -> V_64 , & V_44 , V_41 ) ;
if ( V_7 -> V_30 || V_44 . V_69 == 0 )
break;
V_8 -> V_38 = V_44 . V_69 ;
F_18 ( NULL , V_50 ) ;
error = F_24 ( NULL , V_13 , V_8 -> V_38 , - 1 , & V_50 ) ;
if ( error )
return error ;
}
F_18 ( NULL , V_50 ) ;
return 0 ;
}
int
F_23 (
struct V_49 * V_50 ,
struct V_70 * V_7 )
{
struct V_71 * V_8 ;
struct V_72 * V_41 ;
struct V_43 V_73 ;
struct V_55 * V_56 ;
struct V_55 * V_74 ;
int V_75 ;
int V_17 ;
struct V_52 * V_53 = V_7 -> V_13 -> V_34 ;
F_25 ( V_7 ) ;
V_41 = V_50 -> V_57 ;
F_19 ( V_53 -> V_64 , & V_73 , V_41 ) ;
V_56 = F_20 ( V_41 ) ;
V_8 = V_7 -> V_8 ;
V_8 -> V_37 = 1 ;
if ( V_7 -> V_76 ) {
V_74 = & V_56 [ 0 ] ;
for ( V_17 = 0 ; V_17 < V_73 . V_16 ; V_74 ++ , V_17 ++ ) {
if ( F_21 ( V_74 -> V_39 ) == V_8 -> V_39 ) {
if ( V_8 -> V_40 == V_7 -> V_77 ) {
V_7 -> V_77 = 0 ;
break;
}
V_7 -> V_77 ++ ;
} else if ( F_21 ( V_74 -> V_39 ) >
V_8 -> V_39 ) {
V_7 -> V_77 = 0 ;
break;
}
}
if ( V_17 == V_73 . V_16 ) {
F_26 ( V_7 ) ;
return 0 ;
}
} else {
V_74 = & V_56 [ 0 ] ;
V_17 = 0 ;
}
V_7 -> V_76 = 0 ;
V_75 = 0 ;
for (; V_17 < V_73 . V_16 ; V_74 ++ , V_17 ++ ) {
char * V_36 ;
int V_28 , V_29 ;
if ( F_21 ( V_74 -> V_39 ) != V_8 -> V_39 ) {
V_8 -> V_39 = F_21 ( V_74 -> V_39 ) ;
V_8 -> V_40 = 0 ;
}
if ( V_74 -> V_26 & V_78 )
continue;
if ( V_74 -> V_26 & V_79 ) {
T_10 * V_80 ;
V_80 = F_27 ( V_41 , V_17 ) ;
V_36 = V_80 -> V_27 ;
V_28 = V_80 -> V_28 ;
V_29 = F_16 ( V_80 -> V_29 ) ;
} else {
T_11 * V_81 ;
V_81 = F_28 ( V_41 , V_17 ) ;
V_36 = V_81 -> V_36 ;
V_28 = V_81 -> V_28 ;
V_29 = F_21 ( V_81 -> V_29 ) ;
}
V_75 = V_7 -> V_25 ( V_7 , V_74 -> V_26 ,
V_36 , V_28 , V_29 ) ;
if ( V_75 )
break;
if ( V_7 -> V_30 )
break;
V_8 -> V_40 ++ ;
}
F_29 ( V_7 ) ;
return V_75 ;
}
STATIC int
F_30 ( T_2 * V_7 )
{
int error ;
struct V_49 * V_50 ;
F_31 ( V_7 ) ;
V_7 -> V_8 -> V_38 = 0 ;
error = F_24 ( NULL , V_7 -> V_13 , 0 , - 1 , & V_50 ) ;
if ( error )
return error ;
error = F_23 ( V_50 , V_7 ) ;
F_18 ( NULL , V_50 ) ;
return error ;
}
int
F_32 (
T_2 * V_7 )
{
int error ;
T_6 * V_13 = V_7 -> V_13 ;
T_12 V_82 ;
F_33 ( V_13 -> V_34 , V_83 ) ;
if ( F_34 ( V_13 -> V_34 ) )
return - V_84 ;
V_82 = F_35 ( V_13 ) ;
if ( ! F_36 ( V_13 ) ) {
error = 0 ;
} else if ( V_13 -> V_85 . V_86 == V_87 ) {
error = F_2 ( V_7 ) ;
} else if ( F_37 ( V_13 , V_54 ) ) {
error = F_30 ( V_7 ) ;
} else {
error = F_13 ( V_7 ) ;
}
F_38 ( V_13 , V_82 ) ;
return error ;
}
STATIC int
F_39 (
T_2 * V_7 ,
int V_26 ,
unsigned char * V_36 ,
int V_28 ,
int V_29 )
{
struct V_88 * V_89 = (struct V_88 * ) V_7 -> V_89 ;
T_13 * V_90 ;
int V_91 ;
ASSERT ( ! ( V_7 -> V_26 & V_92 ) ) ;
ASSERT ( V_7 -> V_16 >= 0 ) ;
ASSERT ( V_7 -> V_16 < ( V_93 / 8 ) ) ;
ASSERT ( V_7 -> V_94 >= sizeof( * V_89 ) ) ;
ASSERT ( V_7 -> V_94 <= V_7 -> V_22 ) ;
if ( ( ( V_7 -> V_26 & V_95 ) == 0 ) !=
( ( V_26 & V_96 ) == 0 ) )
return 0 ;
if ( ( ( V_7 -> V_26 & V_97 ) == 0 ) !=
( ( V_26 & V_98 ) == 0 ) )
return 0 ;
V_91 = sizeof( * V_89 ) +
V_7 -> V_16 * sizeof( V_89 -> V_99 [ 0 ] ) ;
V_7 -> V_94 -= F_40 ( V_28 ) ;
if ( V_7 -> V_94 < V_91 ) {
F_41 ( V_7 ) ;
V_89 -> V_100 = 1 ;
V_7 -> V_30 = 1 ;
return 0 ;
}
V_90 = ( T_13 * ) & V_7 -> V_89 [ V_7 -> V_94 ] ;
V_90 -> V_101 = V_29 ;
memcpy ( V_90 -> V_102 , V_36 , V_28 ) ;
V_90 -> V_102 [ V_28 ] = 0 ;
V_89 -> V_99 [ V_7 -> V_16 ++ ] = V_7 -> V_94 ;
V_89 -> V_103 = V_7 -> V_16 ;
F_42 ( V_7 ) ;
return 0 ;
}
int
F_43 (
T_6 * V_13 ,
char * V_104 ,
int V_22 ,
int V_26 ,
T_3 * V_8 )
{
T_2 V_7 ;
struct V_88 * V_89 ;
int error ;
if ( V_8 -> V_105 || V_8 -> V_106 )
return - V_107 ;
if ( ( V_8 -> V_37 == 0 ) &&
( V_8 -> V_39 || V_8 -> V_38 || V_8 -> V_40 ) )
return - V_107 ;
if ( ( ( long ) V_104 ) & ( sizeof( int ) - 1 ) )
return - V_108 ;
if ( V_26 & V_92 )
V_22 = 0 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_13 = V_13 ;
V_7 . V_8 = V_8 ;
V_7 . V_76 = 1 ;
V_7 . V_26 = V_26 ;
V_7 . V_89 = V_104 ;
V_7 . V_22 = ( V_22 & ~ ( sizeof( int ) - 1 ) ) ;
V_7 . V_94 = V_7 . V_22 ;
V_7 . V_25 = F_39 ;
V_89 = (struct V_88 * ) V_7 . V_89 ;
V_89 -> V_103 = 0 ;
V_89 -> V_100 = 0 ;
V_89 -> V_99 [ 0 ] = V_7 . V_22 ;
error = F_32 ( & V_7 ) ;
ASSERT ( error <= 0 ) ;
return error ;
}
