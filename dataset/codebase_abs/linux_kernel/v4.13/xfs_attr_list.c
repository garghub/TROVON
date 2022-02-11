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
V_7 -> V_25 ( V_7 ,
V_12 -> V_26 ,
V_12 -> V_27 ,
( int ) V_12 -> V_28 ,
( int ) V_12 -> V_29 ) ;
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
V_7 -> V_25 ( V_7 ,
V_10 -> V_26 ,
V_10 -> V_36 ,
V_10 -> V_28 ,
V_10 -> V_29 ) ;
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
error = F_15 ( V_7 -> V_54 , V_13 , V_8 -> V_38 , - 1 ,
& V_50 , V_55 ) ;
if ( ( error != 0 ) && ( error != - V_35 ) )
return error ;
if ( V_50 ) {
struct V_56 * V_57 ;
V_42 = V_50 -> V_58 ;
switch ( F_16 ( V_42 -> V_21 . V_59 . V_60 ) ) {
case V_61 :
case V_62 :
F_17 ( V_7 ) ;
F_18 ( V_7 -> V_54 , V_50 ) ;
V_50 = NULL ;
break;
case V_63 :
case V_64 :
V_41 = V_50 -> V_58 ;
F_19 ( V_53 -> V_65 ,
& V_44 , V_41 ) ;
V_57 = F_20 ( V_41 ) ;
if ( V_8 -> V_39 > F_21 (
V_57 [ V_44 . V_16 - 1 ] . V_39 ) ) {
F_17 ( V_7 ) ;
F_18 ( V_7 -> V_54 , V_50 ) ;
V_50 = NULL ;
} else if ( V_8 -> V_39 <= F_21 (
V_57 [ 0 ] . V_39 ) ) {
F_17 ( V_7 ) ;
F_18 ( V_7 -> V_54 , V_50 ) ;
V_50 = NULL ;
}
break;
default:
F_17 ( V_7 ) ;
F_18 ( V_7 -> V_54 , V_50 ) ;
V_50 = NULL ;
}
}
}
if ( V_50 == NULL ) {
V_8 -> V_38 = 0 ;
for (; ; ) {
T_9 V_60 ;
error = F_15 ( V_7 -> V_54 , V_13 ,
V_8 -> V_38 , - 1 , & V_50 ,
V_55 ) ;
if ( error )
return error ;
V_42 = V_50 -> V_58 ;
V_60 = F_16 ( V_42 -> V_21 . V_59 . V_60 ) ;
if ( V_60 == V_63 ||
V_60 == V_64 )
break;
if ( V_60 != V_61 &&
V_60 != V_62 ) {
F_9 ( L_2 ,
V_33 ,
V_7 -> V_13 -> V_34 ,
V_42 ) ;
F_18 ( V_7 -> V_54 , V_50 ) ;
return - V_35 ;
}
V_13 -> V_66 -> V_67 ( & V_46 , V_42 ) ;
V_48 = V_13 -> V_66 -> V_68 ( V_42 ) ;
for ( V_17 = 0 ; V_17 < V_46 . V_16 ; V_48 ++ , V_17 ++ ) {
if ( V_8 -> V_39
<= F_21 ( V_48 -> V_39 ) ) {
V_8 -> V_38 = F_21 ( V_48 -> V_69 ) ;
F_22 ( V_7 ,
V_48 ) ;
break;
}
}
if ( V_17 == V_46 . V_16 ) {
F_18 ( V_7 -> V_54 , V_50 ) ;
return 0 ;
}
F_18 ( V_7 -> V_54 , V_50 ) ;
}
}
ASSERT ( V_50 != NULL ) ;
for (; ; ) {
V_41 = V_50 -> V_58 ;
F_23 ( V_50 , V_7 ) ;
F_19 ( V_53 -> V_65 , & V_44 , V_41 ) ;
if ( V_7 -> V_30 || V_44 . V_70 == 0 )
break;
V_8 -> V_38 = V_44 . V_70 ;
F_18 ( V_7 -> V_54 , V_50 ) ;
error = F_24 ( V_7 -> V_54 , V_13 , V_8 -> V_38 , - 1 , & V_50 ) ;
if ( error )
return error ;
}
F_18 ( V_7 -> V_54 , V_50 ) ;
return 0 ;
}
void
F_23 (
struct V_49 * V_50 ,
struct V_71 * V_7 )
{
struct V_72 * V_8 ;
struct V_73 * V_41 ;
struct V_43 V_74 ;
struct V_56 * V_57 ;
struct V_56 * V_75 ;
int V_17 ;
struct V_52 * V_53 = V_7 -> V_13 -> V_34 ;
F_25 ( V_7 ) ;
V_41 = V_50 -> V_58 ;
F_19 ( V_53 -> V_65 , & V_74 , V_41 ) ;
V_57 = F_20 ( V_41 ) ;
V_8 = V_7 -> V_8 ;
V_8 -> V_37 = 1 ;
if ( V_7 -> V_76 ) {
V_75 = & V_57 [ 0 ] ;
for ( V_17 = 0 ; V_17 < V_74 . V_16 ; V_75 ++ , V_17 ++ ) {
if ( F_21 ( V_75 -> V_39 ) == V_8 -> V_39 ) {
if ( V_8 -> V_40 == V_7 -> V_77 ) {
V_7 -> V_77 = 0 ;
break;
}
V_7 -> V_77 ++ ;
} else if ( F_21 ( V_75 -> V_39 ) >
V_8 -> V_39 ) {
V_7 -> V_77 = 0 ;
break;
}
}
if ( V_17 == V_74 . V_16 ) {
F_26 ( V_7 ) ;
return;
}
} else {
V_75 = & V_57 [ 0 ] ;
V_17 = 0 ;
}
V_7 -> V_76 = 0 ;
for (; V_17 < V_74 . V_16 ; V_75 ++ , V_17 ++ ) {
char * V_36 ;
int V_28 , V_29 ;
if ( F_21 ( V_75 -> V_39 ) != V_8 -> V_39 ) {
V_8 -> V_39 = F_21 ( V_75 -> V_39 ) ;
V_8 -> V_40 = 0 ;
}
if ( V_75 -> V_26 & V_78 )
continue;
if ( V_75 -> V_26 & V_79 ) {
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
V_7 -> V_25 ( V_7 , V_75 -> V_26 ,
V_36 , V_28 , V_29 ) ;
if ( V_7 -> V_30 )
break;
V_8 -> V_40 ++ ;
}
F_29 ( V_7 ) ;
return;
}
STATIC int
F_30 ( T_2 * V_7 )
{
int error ;
struct V_49 * V_50 ;
F_31 ( V_7 ) ;
V_7 -> V_8 -> V_38 = 0 ;
error = F_24 ( V_7 -> V_54 , V_7 -> V_13 , 0 , - 1 , & V_50 ) ;
if ( error )
return error ;
F_23 ( V_50 , V_7 ) ;
F_18 ( V_7 -> V_54 , V_50 ) ;
return 0 ;
}
int
F_32 (
struct V_71 * V_7 )
{
struct V_51 * V_13 = V_7 -> V_13 ;
ASSERT ( F_33 ( V_13 , V_82 | V_83 ) ) ;
if ( ! F_34 ( V_13 ) )
return 0 ;
else if ( V_13 -> V_84 . V_85 == V_86 )
return F_2 ( V_7 ) ;
else if ( F_35 ( V_13 , V_55 ) )
return F_30 ( V_7 ) ;
return F_13 ( V_7 ) ;
}
int
F_36 (
T_2 * V_7 )
{
int error ;
T_6 * V_13 = V_7 -> V_13 ;
T_12 V_87 ;
F_37 ( V_13 -> V_34 , V_88 ) ;
if ( F_38 ( V_13 -> V_34 ) )
return - V_89 ;
V_87 = F_39 ( V_13 ) ;
error = F_32 ( V_7 ) ;
F_40 ( V_13 , V_87 ) ;
return error ;
}
STATIC void
F_41 (
T_2 * V_7 ,
int V_26 ,
unsigned char * V_36 ,
int V_28 ,
int V_29 )
{
struct V_90 * V_91 = (struct V_90 * ) V_7 -> V_91 ;
T_13 * V_92 ;
int V_93 ;
ASSERT ( ! ( V_7 -> V_26 & V_94 ) ) ;
ASSERT ( V_7 -> V_16 >= 0 ) ;
ASSERT ( V_7 -> V_16 < ( V_95 / 8 ) ) ;
ASSERT ( V_7 -> V_96 >= sizeof( * V_91 ) ) ;
ASSERT ( V_7 -> V_96 <= V_7 -> V_22 ) ;
if ( ( ( V_7 -> V_26 & V_97 ) == 0 ) !=
( ( V_26 & V_98 ) == 0 ) )
return;
if ( ( ( V_7 -> V_26 & V_99 ) == 0 ) !=
( ( V_26 & V_100 ) == 0 ) )
return;
V_93 = sizeof( * V_91 ) +
V_7 -> V_16 * sizeof( V_91 -> V_101 [ 0 ] ) ;
V_7 -> V_96 -= F_42 ( V_28 ) ;
if ( V_7 -> V_96 < V_93 ) {
F_43 ( V_7 ) ;
V_91 -> V_102 = 1 ;
V_7 -> V_30 = 1 ;
return;
}
V_92 = ( T_13 * ) & V_7 -> V_91 [ V_7 -> V_96 ] ;
V_92 -> V_103 = V_29 ;
memcpy ( V_92 -> V_104 , V_36 , V_28 ) ;
V_92 -> V_104 [ V_28 ] = 0 ;
V_91 -> V_101 [ V_7 -> V_16 ++ ] = V_7 -> V_96 ;
V_91 -> V_105 = V_7 -> V_16 ;
F_44 ( V_7 ) ;
return;
}
int
F_45 (
T_6 * V_13 ,
char * V_106 ,
int V_22 ,
int V_26 ,
T_3 * V_8 )
{
T_2 V_7 ;
struct V_90 * V_91 ;
int error ;
if ( V_8 -> V_107 || V_8 -> V_108 )
return - V_109 ;
if ( ( V_8 -> V_37 == 0 ) &&
( V_8 -> V_39 || V_8 -> V_38 || V_8 -> V_40 ) )
return - V_109 ;
if ( ( ( long ) V_106 ) & ( sizeof( int ) - 1 ) )
return - V_110 ;
if ( V_26 & V_94 )
V_22 = 0 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_13 = V_13 ;
V_7 . V_8 = V_8 ;
V_7 . V_76 = 1 ;
V_7 . V_26 = V_26 ;
V_7 . V_91 = V_106 ;
V_7 . V_22 = ( V_22 & ~ ( sizeof( int ) - 1 ) ) ;
V_7 . V_96 = V_7 . V_22 ;
V_7 . V_25 = F_41 ;
V_91 = (struct V_90 * ) V_7 . V_91 ;
V_91 -> V_105 = 0 ;
V_91 -> V_102 = 0 ;
V_91 -> V_101 [ 0 ] = V_7 . V_22 ;
error = F_36 ( & V_7 ) ;
ASSERT ( error <= 0 ) ;
return error ;
}
