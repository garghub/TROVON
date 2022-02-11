static void
F_1 ( T_1 * V_1 )
{
V_1 -> V_2 = 0 ;
V_1 -> V_3 = NULL ;
V_1 -> V_4 . V_5 = V_6 ;
V_1 -> V_4 . V_7 = 0 ;
V_1 -> V_4 . V_8 = FALSE ;
V_1 -> V_4 . V_9 = 0 ;
V_1 -> V_4 . V_10 = 0 ;
V_1 -> V_4 . V_11 = 0 ;
V_1 -> V_12 . V_5 = V_13 ;
V_1 -> V_12 . V_7 = 0 ;
V_1 -> V_12 . V_8 = FALSE ;
V_1 -> V_12 . V_9 = 0 ;
V_1 -> V_12 . V_10 = 0 ;
V_1 -> V_12 . V_11 = 0 ;
V_1 -> V_14 = NULL ;
V_1 -> V_15 = 0x100000 ;
}
int
F_2 ( T_2 * V_16 , int * V_17 , T_3 * * V_18 )
{
T_4 V_19 [ 6 ] ;
T_1 * V_1 ;
if ( ! F_3 ( V_16 -> V_20 , V_19 , sizeof( V_19 ) ,
V_17 , V_18 ) ) {
if ( * V_17 != V_21 )
return - 1 ;
return 0 ;
}
if ( V_19 [ 0 ] == V_22 &&
( V_19 [ 5 ] == V_23 ||
V_19 [ 5 ] == V_24 ||
V_19 [ 5 ] == V_25 ||
V_19 [ 5 ] == V_26 ||
V_19 [ 5 ] == V_22 ) ) {
goto V_27;
}
else {
return 0 ;
}
V_27:
if ( F_4 ( V_16 -> V_20 , 5 , V_28 , V_17 ) == - 1 )
return - 1 ;
V_1 = ( T_1 * ) F_5 ( sizeof( T_1 ) ) ;
V_16 -> V_29 = ( void * ) V_1 ;
V_1 -> V_30 = F_6 ( & V_19 [ 1 ] ) ;
V_1 -> V_31 = 0 ;
F_1 ( V_1 ) ;
V_1 -> V_15 = 5 ;
V_16 -> V_32 = V_33 ;
V_16 -> V_34 = V_35 ;
V_16 -> V_36 = V_37 ;
V_16 -> V_38 = V_39 ;
V_16 -> V_40 = V_41 ;
V_16 -> V_42 = V_43 ;
V_16 -> V_44 = V_45 ;
V_1 -> V_14 = F_7 ( T_1 , 1 ) ;
if ( V_16 -> V_46 != NULL )
V_1 -> V_47 = F_8 () ;
else
V_1 -> V_47 = NULL ;
V_1 -> V_48 = 0 ;
return 1 ;
}
static void
F_9 ( struct V_49 * V_50 , int V_2 ,
T_5 V_51 )
{
V_50 -> V_52 = V_53 ;
V_50 -> V_54 = V_2 ;
V_50 -> V_55 = V_2 ;
V_50 -> V_56 = V_33 ;
V_50 -> V_57 . V_58 . V_59 = ( V_51 == V_6 ? TRUE : FALSE ) ;
}
static T_6
V_39 ( T_2 * V_16 , int * V_17 , T_3 * * V_18 , T_7 * V_60 )
{
int V_2 ;
T_5 V_51 ;
T_4 * V_61 ;
T_1 * V_1 ;
T_8 * V_62 ;
V_1 = ( T_1 * ) V_16 -> V_29 ;
if ( V_16 -> V_46 != NULL ) {
V_62 = F_7 ( T_8 , 1 ) ;
if ( ! V_62 ) {
* V_17 = V_63 ;
return FALSE ;
}
V_62 -> V_15 = 0 ;
} else
V_62 = NULL ;
F_10 ( V_16 -> V_64 , V_37 ) ;
V_61 = F_11 ( V_16 -> V_64 ) ;
if ( ! F_12 ( V_1 , V_16 -> V_20 , V_17 , V_18 , V_61 , & V_2 , & V_51 ,
V_62 , 0 ) ) {
if ( V_62 != NULL )
F_13 ( V_62 ) ;
return FALSE ;
}
if ( V_62 != NULL )
V_62 -> V_5 = V_51 ;
if ( V_62 != NULL )
F_14 ( V_1 -> V_47 , V_62 ) ;
* V_60 = V_1 -> V_48 ;
V_1 -> V_48 ++ ;
F_9 ( & V_16 -> V_50 , V_2 , V_51 ) ;
V_16 -> V_50 . V_65 = V_66 ;
V_16 -> V_50 . V_67 . V_68 = V_1 -> V_30 ;
V_16 -> V_50 . V_67 . V_69 = V_1 -> V_31 * 100000000 ;
return TRUE ;
}
static int
F_15 ( T_1 * V_1 , T_9 V_20 , T_10 * V_3 , int V_70 , T_4 * V_71 ,
int * V_17 , T_3 * * V_18 , T_8 * V_62 )
{
int V_72 ;
int V_2 = V_70 ;
int V_73 ;
for (; V_2 > 0 ; -- V_2 ) {
V_72 = F_16 ( V_20 ) ;
if ( V_72 == V_74 ) {
* V_17 = F_17 ( V_20 , V_18 ) ;
if ( * V_17 == 0 ) {
* V_17 = V_21 ;
}
return - 1 ;
}
V_1 -> V_15 ++ ;
switch ( V_72 ) {
case 0x7e :
if ( V_3 -> V_7 > 0 ) {
V_3 -> V_8 = FALSE ;
V_73 = V_3 -> V_7 ;
V_3 -> V_7 = 0 ;
if ( V_73 <= 0 ) {
return 0 ;
}
if ( V_73 > V_37 ) {
* V_17 = V_75 ;
return - 1 ;
}
memcpy ( V_71 , V_3 -> V_61 , V_73 ) ;
if ( V_62 ) {
V_62 -> V_15 = V_3 -> V_9 ;
V_62 -> V_76 =
V_3 -> V_10 - V_3 -> V_9 - 3 ;
F_18 ( V_62 -> V_76 >= 0 ) ;
}
V_2 -- ;
if ( V_2 > 0 ) {
V_3 -> V_9 = V_3 -> V_11 ;
V_3 -> V_10 = V_1 -> V_15 ;
} else {
V_3 -> V_9 = 0 ;
V_3 -> V_10 = 0 ;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_3 = V_3 ;
return V_73 ;
}
break;
case 0x7d :
if ( ! V_3 -> V_8 ) {
V_3 -> V_8 = TRUE ;
break;
}
default:
if ( V_3 -> V_8 ) {
V_72 ^= 0x20 ;
V_3 -> V_8 = FALSE ;
}
if ( V_3 -> V_7 >= V_37 ) {
* V_17 = V_75 ;
return - 1 ;
}
V_3 -> V_61 [ V_3 -> V_7 ++ ] = V_72 ;
break;
}
}
return 0 ;
}
static T_6
F_12 ( T_1 * V_1 , T_9 V_20 , int * V_17 , T_3 * * V_18 , T_4 * V_71 ,
int * V_2 , T_5 * V_51 , T_8 * V_62 ,
T_7 V_76 )
{
int V_77 ;
T_10 * V_3 = NULL ;
int V_78 , V_79 ;
int V_70 , V_73 = 0 ;
T_7 V_80 ;
T_11 V_81 ;
T_4 V_82 ;
if ( V_1 -> V_2 > 0 ) {
F_18 ( V_76 == 0 ) ;
V_3 = V_1 -> V_3 ;
V_73 = F_15 ( V_1 , V_20 , V_3 , V_1 -> V_2 ,
V_71 , V_17 , V_18 , V_62 ) ;
if ( V_73 < 0 ) {
return FALSE ;
}
else if ( V_73 > 0 ) {
* V_2 = V_73 ;
* V_51 = V_3 -> V_5 ;
return TRUE ;
}
} else {
if ( V_62 )
V_62 -> V_76 = 0 ;
}
V_80 = V_1 -> V_15 ;
while ( ( V_77 = F_16 ( V_20 ) ) != V_74 ) {
V_1 -> V_15 ++ ;
switch ( V_77 ) {
case V_23 :
case V_24 :
V_3 = V_77 == V_23 ? & V_1 -> V_4 : & V_1 -> V_12 ;
V_3 -> V_11 = V_1 -> V_15 - 1 ;
V_78 = F_16 ( V_20 ) ;
if ( V_78 == V_74 )
goto V_83;
V_1 -> V_15 ++ ;
V_79 = F_16 ( V_20 ) ;
if ( V_79 == V_74 )
goto V_83;
V_1 -> V_15 ++ ;
V_70 = ( V_78 << 8 ) | V_79 ;
if ( V_3 -> V_9 == 0 ) {
V_3 -> V_9 = V_3 -> V_11 ;
V_3 -> V_10 = V_1 -> V_15 ;
}
if ( V_70 == 0 )
continue;
F_18 ( V_76 < V_70 ) ;
while ( V_76 ) {
if ( F_16 ( V_20 ) == V_74 )
goto V_83;
V_1 -> V_15 ++ ;
V_76 -- ;
V_70 -- ;
}
V_73 = F_15 ( V_1 , V_20 , V_3 , V_70 ,
V_71 , V_17 , V_18 , V_62 ) ;
if ( V_73 < 0 ) {
return FALSE ;
}
else if ( V_73 > 0 ) {
* V_2 = V_73 ;
* V_51 = V_3 -> V_5 ;
return TRUE ;
}
break;
case V_84 :
case V_85 :
break;
case V_22 :
if ( ! F_3 ( V_20 , & V_81 , sizeof( T_11 ) , V_17 , V_18 ) )
return FALSE ;
V_1 -> V_15 += sizeof( T_11 ) ;
V_1 -> V_30 = F_6 ( & V_81 ) ;
V_1 -> V_31 = 0 ;
break;
case V_25 :
if ( ! F_3 ( V_20 , & V_81 , sizeof( T_11 ) , V_17 , V_18 ) )
return FALSE ;
V_1 -> V_15 += sizeof( T_11 ) ;
V_1 -> V_31 += F_6 ( & V_81 ) ;
if ( V_1 -> V_31 >= 10 ) {
V_1 -> V_30 += V_1 -> V_31 / 10 ;
V_1 -> V_31 = V_1 -> V_31 % 10 ;
}
break;
case V_26 :
if ( ! F_3 ( V_20 , & V_82 , sizeof( T_4 ) , V_17 , V_18 ) )
return FALSE ;
V_1 -> V_15 += sizeof( T_4 ) ;
V_1 -> V_31 += V_82 ;
if ( V_1 -> V_31 >= 10 ) {
V_1 -> V_30 += V_1 -> V_31 / 10 ;
V_1 -> V_31 = V_1 -> V_31 % 10 ;
}
break;
default:
* V_17 = V_86 ;
* V_18 = F_19 ( L_1 , V_77 ) ;
return FALSE ;
}
}
V_83:
* V_17 = F_17 ( V_20 , V_18 ) ;
if ( * V_17 == 0 ) {
if ( V_1 -> V_15 != V_80 ) {
* V_17 = V_21 ;
}
}
return FALSE ;
}
static T_6
V_41 ( T_2 * V_16 ,
T_7 V_87 ,
struct V_49 * V_50 ,
T_12 * V_61 ,
int * V_17 ,
T_3 * * V_18 )
{
int V_2 ;
T_4 * V_71 ;
T_5 V_51 ;
T_1 * V_1 ;
T_8 * V_62 ;
T_7 V_76 ;
V_1 = ( T_1 * ) V_16 -> V_29 ;
V_62 = ( T_8 * ) F_20 ( V_1 -> V_47 , V_87 ) ;
if ( ! V_62 ) {
* V_17 = V_86 ;
* V_18 = F_21 ( L_2 ) ;
return FALSE ;
}
if ( F_4 ( V_16 -> V_46 , V_62 -> V_15 , V_28 , V_17 ) == - 1 )
return FALSE ;
F_1 ( V_1 -> V_14 ) ;
V_1 -> V_14 -> V_15 = V_62 -> V_15 ;
F_10 ( V_61 , V_37 ) ;
V_71 = F_11 ( V_61 ) ;
V_76 = V_62 -> V_76 ;
do {
if ( ! F_12 ( V_1 -> V_14 , V_16 -> V_46 , V_17 , V_18 ,
V_71 , & V_2 , & V_51 , NULL , V_76 ) )
return FALSE ;
V_76 = 0 ;
} while ( V_51 != V_62 -> V_5 );
F_9 ( V_50 , V_2 , V_62 -> V_5 ) ;
return TRUE ;
}
static void
V_43 ( T_2 * V_16 )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) V_16 -> V_29 ;
if ( V_1 -> V_14 ) {
F_13 ( V_1 -> V_14 ) ;
}
if ( V_1 -> V_47 ) {
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < F_22 ( V_1 -> V_47 ) ; V_88 ++ ) {
F_13 ( F_20 ( V_1 -> V_47 , V_88 ) ) ;
}
F_23 ( V_1 -> V_47 , TRUE ) ;
}
}
