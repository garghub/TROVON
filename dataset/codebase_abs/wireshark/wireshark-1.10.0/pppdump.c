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
int V_20 ;
T_1 * V_1 ;
V_20 = F_3 ( V_19 , sizeof( V_19 ) , V_16 -> V_21 ) ;
if ( V_20 != ( int ) sizeof( V_19 ) ) {
* V_17 = F_4 ( V_16 -> V_21 , V_18 ) ;
if ( * V_17 != 0 && * V_17 != V_22 )
return - 1 ;
return 0 ;
}
if ( V_19 [ 0 ] == V_23 &&
( V_19 [ 5 ] == V_24 ||
V_19 [ 5 ] == V_25 ||
V_19 [ 5 ] == V_26 ||
V_19 [ 5 ] == V_27 ||
V_19 [ 5 ] == V_23 ) ) {
goto V_28;
}
else {
return 0 ;
}
V_28:
if ( F_5 ( V_16 -> V_21 , 5 , V_29 , V_17 ) == - 1 )
return - 1 ;
V_1 = ( T_1 * ) F_6 ( sizeof( T_1 ) ) ;
V_16 -> V_30 = ( void * ) V_1 ;
V_1 -> V_31 = F_7 ( & V_19 [ 1 ] ) ;
V_1 -> V_32 = 0 ;
F_1 ( V_1 ) ;
V_1 -> V_15 = 5 ;
V_16 -> V_33 = V_34 ;
V_16 -> V_35 = V_36 ;
V_16 -> V_37 = V_38 ;
V_16 -> V_39 = V_40 ;
V_16 -> V_41 = V_42 ;
V_16 -> V_43 = V_44 ;
V_16 -> V_45 = V_46 ;
V_1 -> V_14 = F_8 ( T_1 , 1 ) ;
if ( V_16 -> V_47 != NULL )
V_1 -> V_48 = F_9 () ;
else
V_1 -> V_48 = NULL ;
V_1 -> V_49 = 0 ;
return 1 ;
}
static T_5
V_40 ( T_2 * V_16 , int * V_17 , T_3 * * V_18 , T_6 * V_50 )
{
int V_2 ;
T_7 V_51 ;
T_4 * V_52 ;
T_1 * V_1 ;
T_8 * V_53 ;
F_10 ( V_16 -> V_54 , V_38 ) ;
V_52 = F_11 ( V_16 -> V_54 ) ;
V_1 = ( T_1 * ) V_16 -> V_30 ;
if ( V_16 -> V_47 != NULL ) {
V_53 = F_8 ( T_8 , 1 ) ;
if ( ! V_53 ) {
* V_17 = V_55 ;
return FALSE ;
}
V_53 -> V_15 = 0 ;
} else
V_53 = NULL ;
if ( ! F_12 ( V_1 , V_16 -> V_21 , V_17 , V_18 , V_52 , & V_2 , & V_51 ,
V_53 , 0 ) ) {
if ( V_53 != NULL )
F_13 ( V_53 ) ;
return FALSE ;
}
if ( V_53 != NULL )
V_53 -> V_5 = V_51 ;
if ( V_53 != NULL )
F_14 ( V_1 -> V_48 , V_53 ) ;
* V_50 = V_1 -> V_49 ;
V_1 -> V_49 ++ ;
V_16 -> V_56 . V_57 = V_58 ;
V_16 -> V_56 . V_59 = V_2 ;
V_16 -> V_56 . V_60 = V_2 ;
V_16 -> V_56 . V_61 . V_62 = V_1 -> V_31 ;
V_16 -> V_56 . V_61 . V_63 = V_1 -> V_32 * 100000000 ;
V_16 -> V_56 . V_64 = V_34 ;
V_16 -> V_56 . V_65 . V_66 . V_67 = ( V_51 == V_6 ? TRUE : FALSE ) ;
return TRUE ;
}
static int
F_15 ( T_1 * V_1 , T_9 V_21 , T_10 * V_3 , int V_68 , T_4 * V_69 ,
int * V_17 , T_3 * * V_18 , T_8 * V_53 )
{
int V_70 ;
int V_2 = V_68 ;
int V_71 ;
for (; V_2 > 0 ; -- V_2 ) {
V_70 = F_16 ( V_21 ) ;
if ( V_70 == V_72 ) {
* V_17 = F_4 ( V_21 , V_18 ) ;
if ( * V_17 == 0 ) {
* V_17 = V_22 ;
}
return - 1 ;
}
V_1 -> V_15 ++ ;
switch ( V_70 ) {
case 0x7e :
if ( V_3 -> V_7 > 0 ) {
V_3 -> V_8 = FALSE ;
V_71 = V_3 -> V_7 ;
V_3 -> V_7 = 0 ;
if ( V_71 <= 0 ) {
return 0 ;
}
if ( V_71 > V_38 ) {
* V_17 = V_73 ;
return - 1 ;
}
memcpy ( V_69 , V_3 -> V_52 , V_71 ) ;
if ( V_53 ) {
V_53 -> V_15 = V_3 -> V_9 ;
V_53 -> V_74 =
V_3 -> V_10 - V_3 -> V_9 - 3 ;
F_17 ( V_53 -> V_74 >= 0 ) ;
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
return V_71 ;
}
break;
case 0x7d :
if ( ! V_3 -> V_8 ) {
V_3 -> V_8 = TRUE ;
break;
}
default:
if ( V_3 -> V_8 ) {
V_70 ^= 0x20 ;
V_3 -> V_8 = FALSE ;
}
if ( V_3 -> V_7 >= V_38 ) {
* V_17 = V_73 ;
return - 1 ;
}
V_3 -> V_52 [ V_3 -> V_7 ++ ] = V_70 ;
break;
}
}
return 0 ;
}
static T_5
F_12 ( T_1 * V_1 , T_9 V_21 , int * V_17 , T_3 * * V_18 , T_4 * V_69 ,
int * V_2 , T_7 * V_51 , T_8 * V_53 ,
T_6 V_74 )
{
int V_75 ;
T_10 * V_3 = NULL ;
int V_76 , V_77 ;
int V_68 , V_71 = 0 ;
T_6 V_78 ;
T_11 V_79 ;
T_4 V_80 ;
if ( V_1 -> V_2 > 0 ) {
F_17 ( V_74 == 0 ) ;
V_3 = V_1 -> V_3 ;
V_71 = F_15 ( V_1 , V_21 , V_3 , V_1 -> V_2 ,
V_69 , V_17 , V_18 , V_53 ) ;
if ( V_71 < 0 ) {
return FALSE ;
}
else if ( V_71 > 0 ) {
* V_2 = V_71 ;
* V_51 = V_3 -> V_5 ;
return TRUE ;
}
} else {
if ( V_53 )
V_53 -> V_74 = 0 ;
}
V_78 = V_1 -> V_15 ;
while ( ( V_75 = F_16 ( V_21 ) ) != V_72 ) {
V_1 -> V_15 ++ ;
switch ( V_75 ) {
case V_24 :
case V_25 :
V_3 = V_75 == V_24 ? & V_1 -> V_4 : & V_1 -> V_12 ;
V_3 -> V_11 = V_1 -> V_15 - 1 ;
V_76 = F_16 ( V_21 ) ;
if ( V_76 == V_72 )
goto V_81;
V_1 -> V_15 ++ ;
V_77 = F_16 ( V_21 ) ;
if ( V_77 == V_72 )
goto V_81;
V_1 -> V_15 ++ ;
V_68 = ( V_76 << 8 ) | V_77 ;
if ( V_3 -> V_9 == 0 ) {
V_3 -> V_9 = V_3 -> V_11 ;
V_3 -> V_10 = V_1 -> V_15 ;
}
if ( V_68 == 0 )
continue;
F_17 ( V_74 < V_68 ) ;
while ( V_74 ) {
if ( F_16 ( V_21 ) == V_72 )
goto V_81;
V_1 -> V_15 ++ ;
V_74 -- ;
V_68 -- ;
}
V_71 = F_15 ( V_1 , V_21 , V_3 , V_68 ,
V_69 , V_17 , V_18 , V_53 ) ;
if ( V_71 < 0 ) {
return FALSE ;
}
else if ( V_71 > 0 ) {
* V_2 = V_71 ;
* V_51 = V_3 -> V_5 ;
return TRUE ;
}
break;
case V_82 :
case V_83 :
break;
case V_23 :
F_18 ( & V_79 , sizeof( T_11 ) , V_21 , V_17 , V_18 ) ;
V_1 -> V_15 += sizeof( T_11 ) ;
V_1 -> V_31 = F_7 ( & V_79 ) ;
V_1 -> V_32 = 0 ;
break;
case V_26 :
F_18 ( & V_79 , sizeof( T_11 ) , V_21 , V_17 , V_18 ) ;
V_1 -> V_15 += sizeof( T_11 ) ;
V_1 -> V_32 += F_7 ( & V_79 ) ;
if ( V_1 -> V_32 >= 10 ) {
V_1 -> V_31 += V_1 -> V_32 / 10 ;
V_1 -> V_32 = V_1 -> V_32 % 10 ;
}
break;
case V_27 :
F_18 ( & V_80 , sizeof( T_4 ) , V_21 , V_17 , V_18 ) ;
V_1 -> V_15 += sizeof( T_4 ) ;
V_1 -> V_32 += V_80 ;
if ( V_1 -> V_32 >= 10 ) {
V_1 -> V_31 += V_1 -> V_32 / 10 ;
V_1 -> V_32 = V_1 -> V_32 % 10 ;
}
break;
default:
* V_17 = V_84 ;
* V_18 = F_19 ( L_1 , V_75 ) ;
return FALSE ;
}
}
V_81:
* V_17 = F_4 ( V_21 , V_18 ) ;
if ( * V_17 == 0 ) {
if ( V_1 -> V_15 != V_78 ) {
* V_17 = V_22 ;
}
}
return FALSE ;
}
static T_5
V_42 ( T_2 * V_16 ,
T_6 V_85 ,
struct V_86 * V_56 ,
T_4 * V_69 ,
int V_59 ,
int * V_17 ,
T_3 * * V_18 )
{
union V_87 * V_65 = & V_56 -> V_65 ;
int V_2 ;
T_7 V_51 ;
T_1 * V_1 ;
T_8 * V_53 ;
T_6 V_74 ;
V_1 = ( T_1 * ) V_16 -> V_30 ;
V_53 = ( T_8 * ) F_20 ( V_1 -> V_48 , V_85 ) ;
if ( ! V_53 ) {
* V_17 = V_84 ;
* V_18 = F_21 ( L_2 ) ;
return FALSE ;
}
if ( F_5 ( V_16 -> V_47 , V_53 -> V_15 , V_29 , V_17 ) == - 1 )
return FALSE ;
F_1 ( V_1 -> V_14 ) ;
V_1 -> V_14 -> V_15 = V_53 -> V_15 ;
V_74 = V_53 -> V_74 ;
do {
if ( ! F_12 ( V_1 -> V_14 , V_16 -> V_47 , V_17 , V_18 ,
V_69 , & V_2 , & V_51 , NULL , V_74 ) )
return FALSE ;
V_74 = 0 ;
} while ( V_51 != V_53 -> V_5 );
if ( V_59 != V_2 ) {
* V_17 = V_84 ;
* V_18 = F_19 ( L_3 ,
V_59 , V_2 ) ;
return FALSE ;
}
V_65 -> V_66 . V_67 = ( V_53 -> V_5 == V_6 ? TRUE : FALSE ) ;
return TRUE ;
}
static void
V_44 ( T_2 * V_16 )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) V_16 -> V_30 ;
if ( V_1 -> V_14 ) {
F_13 ( V_1 -> V_14 ) ;
}
if ( V_1 -> V_48 ) {
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < F_22 ( V_1 -> V_48 ) ; V_88 ++ ) {
F_13 ( F_20 ( V_1 -> V_48 , V_88 ) ) ;
}
F_23 ( V_1 -> V_48 , TRUE ) ;
}
}
