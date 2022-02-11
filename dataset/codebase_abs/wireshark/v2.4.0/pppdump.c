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
T_2
F_2 ( T_3 * V_16 , int * V_17 , T_4 * * V_18 )
{
T_5 V_19 [ 6 ] ;
T_1 * V_1 ;
if ( ! F_3 ( V_16 -> V_20 , V_19 , sizeof( V_19 ) ,
V_17 , V_18 ) ) {
if ( * V_17 != V_21 )
return V_22 ;
return V_23 ;
}
if ( V_19 [ 0 ] == V_24 &&
( V_19 [ 5 ] == V_25 ||
V_19 [ 5 ] == V_26 ||
V_19 [ 5 ] == V_27 ||
V_19 [ 5 ] == V_28 ||
V_19 [ 5 ] == V_24 ) ) {
goto V_29;
}
else {
return V_23 ;
}
V_29:
if ( F_4 ( V_16 -> V_20 , 5 , V_30 , V_17 ) == - 1 )
return V_22 ;
V_1 = ( T_1 * ) F_5 ( sizeof( T_1 ) ) ;
V_16 -> V_31 = ( void * ) V_1 ;
V_1 -> V_32 = F_6 ( & V_19 [ 1 ] ) ;
V_1 -> V_33 = 0 ;
F_1 ( V_1 ) ;
V_1 -> V_15 = 5 ;
V_16 -> V_34 = V_35 ;
V_16 -> V_36 = V_37 ;
V_16 -> V_38 = V_39 ;
V_16 -> V_40 = V_41 ;
V_16 -> V_42 = V_43 ;
V_16 -> V_44 = V_45 ;
V_16 -> V_46 = V_47 ;
V_1 -> V_14 = F_7 ( T_1 , 1 ) ;
if ( V_16 -> V_48 != NULL )
V_1 -> V_49 = F_8 () ;
else
V_1 -> V_49 = NULL ;
V_1 -> V_50 = 0 ;
return V_51 ;
}
static void
F_9 ( struct V_52 * V_53 , int V_2 ,
T_6 V_54 )
{
V_53 -> V_55 = V_56 ;
V_53 -> V_57 = V_2 ;
V_53 -> V_58 = V_2 ;
V_53 -> V_59 = V_35 ;
V_53 -> V_60 . V_61 . V_62 = ( V_54 == V_6 ? TRUE : FALSE ) ;
}
static T_7
V_41 ( T_3 * V_16 , int * V_17 , T_4 * * V_18 , T_8 * V_63 )
{
int V_2 ;
T_6 V_54 ;
T_5 * V_64 ;
T_1 * V_1 ;
T_9 * V_65 ;
V_1 = ( T_1 * ) V_16 -> V_31 ;
if ( V_16 -> V_48 != NULL ) {
V_65 = F_7 ( T_9 , 1 ) ;
if ( ! V_65 ) {
* V_17 = V_66 ;
return FALSE ;
}
V_65 -> V_15 = 0 ;
} else
V_65 = NULL ;
F_10 ( V_16 -> V_67 , V_39 ) ;
V_64 = F_11 ( V_16 -> V_67 ) ;
if ( ! F_12 ( V_1 , V_16 -> V_20 , V_17 , V_18 , V_64 , & V_2 , & V_54 ,
V_65 , 0 ) ) {
if ( V_65 != NULL )
F_13 ( V_65 ) ;
return FALSE ;
}
if ( V_65 != NULL )
V_65 -> V_5 = V_54 ;
if ( V_65 != NULL )
F_14 ( V_1 -> V_49 , V_65 ) ;
* V_63 = V_1 -> V_50 ;
V_1 -> V_50 ++ ;
F_9 ( & V_16 -> V_53 , V_2 , V_54 ) ;
V_16 -> V_53 . V_68 = V_69 ;
V_16 -> V_53 . V_70 . V_71 = V_1 -> V_32 ;
V_16 -> V_53 . V_70 . V_72 = V_1 -> V_33 * 100000000 ;
return TRUE ;
}
static int
F_15 ( T_1 * V_1 , T_10 V_20 , T_11 * V_3 , int V_73 , T_5 * V_74 ,
int * V_17 , T_4 * * V_18 , T_9 * V_65 )
{
int V_75 ;
int V_2 = V_73 ;
int V_76 ;
for (; V_2 > 0 ; -- V_2 ) {
V_75 = F_16 ( V_20 ) ;
if ( V_75 == V_77 ) {
* V_17 = F_17 ( V_20 , V_18 ) ;
if ( * V_17 == 0 ) {
* V_17 = V_21 ;
}
return - 1 ;
}
V_1 -> V_15 ++ ;
switch ( V_75 ) {
case 0x7e :
if ( V_3 -> V_7 > 0 ) {
V_3 -> V_8 = FALSE ;
V_76 = V_3 -> V_7 ;
V_3 -> V_7 = 0 ;
if ( V_76 <= 0 ) {
return 0 ;
}
if ( V_76 > V_39 ) {
* V_17 = V_78 ;
* V_18 = F_18 ( L_1 ,
V_76 , V_39 ) ;
return - 1 ;
}
memcpy ( V_74 , V_3 -> V_64 , V_76 ) ;
if ( V_65 ) {
V_65 -> V_15 = V_3 -> V_9 ;
V_65 -> V_79 =
V_3 -> V_10 - V_3 -> V_9 - 3 ;
F_19 ( V_65 -> V_79 >= 0 ) ;
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
return V_76 ;
}
break;
case 0x7d :
if ( ! V_3 -> V_8 ) {
V_3 -> V_8 = TRUE ;
break;
}
default:
if ( V_3 -> V_8 ) {
V_75 ^= 0x20 ;
V_3 -> V_8 = FALSE ;
}
if ( V_3 -> V_7 >= V_39 ) {
* V_17 = V_78 ;
* V_18 = F_18 ( L_1 ,
V_3 -> V_7 - 1 , V_39 ) ;
return - 1 ;
}
V_3 -> V_64 [ V_3 -> V_7 ++ ] = V_75 ;
break;
}
}
return 0 ;
}
static T_7
F_12 ( T_1 * V_1 , T_10 V_20 , int * V_17 , T_4 * * V_18 , T_5 * V_74 ,
int * V_2 , T_6 * V_54 , T_9 * V_65 ,
T_8 V_79 )
{
int V_80 ;
T_11 * V_3 = NULL ;
int V_81 , V_82 ;
int V_73 , V_76 = 0 ;
T_8 V_83 ;
T_12 V_84 ;
T_5 V_85 ;
if ( V_1 -> V_2 > 0 ) {
F_19 ( V_79 == 0 ) ;
V_3 = V_1 -> V_3 ;
V_76 = F_15 ( V_1 , V_20 , V_3 , V_1 -> V_2 ,
V_74 , V_17 , V_18 , V_65 ) ;
if ( V_76 < 0 ) {
return FALSE ;
}
else if ( V_76 > 0 ) {
* V_2 = V_76 ;
* V_54 = V_3 -> V_5 ;
return TRUE ;
}
} else {
if ( V_65 )
V_65 -> V_79 = 0 ;
}
V_83 = V_1 -> V_15 ;
while ( ( V_80 = F_16 ( V_20 ) ) != V_77 ) {
V_1 -> V_15 ++ ;
switch ( V_80 ) {
case V_25 :
case V_26 :
V_3 = V_80 == V_25 ? & V_1 -> V_4 : & V_1 -> V_12 ;
V_3 -> V_11 = V_1 -> V_15 - 1 ;
V_81 = F_16 ( V_20 ) ;
if ( V_81 == V_77 )
goto V_86;
V_1 -> V_15 ++ ;
V_82 = F_16 ( V_20 ) ;
if ( V_82 == V_77 )
goto V_86;
V_1 -> V_15 ++ ;
V_73 = ( V_81 << 8 ) | V_82 ;
if ( V_3 -> V_9 == 0 ) {
V_3 -> V_9 = V_3 -> V_11 ;
V_3 -> V_10 = V_1 -> V_15 ;
}
if ( V_73 == 0 )
continue;
F_19 ( V_79 < V_73 ) ;
while ( V_79 ) {
if ( F_16 ( V_20 ) == V_77 )
goto V_86;
V_1 -> V_15 ++ ;
V_79 -- ;
V_73 -- ;
}
V_76 = F_15 ( V_1 , V_20 , V_3 , V_73 ,
V_74 , V_17 , V_18 , V_65 ) ;
if ( V_76 < 0 ) {
return FALSE ;
}
else if ( V_76 > 0 ) {
* V_2 = V_76 ;
* V_54 = V_3 -> V_5 ;
return TRUE ;
}
break;
case V_87 :
case V_88 :
break;
case V_24 :
if ( ! F_3 ( V_20 , & V_84 , sizeof( T_12 ) , V_17 , V_18 ) )
return FALSE ;
V_1 -> V_15 += sizeof( T_12 ) ;
V_1 -> V_32 = F_6 ( & V_84 ) ;
V_1 -> V_33 = 0 ;
break;
case V_27 :
if ( ! F_3 ( V_20 , & V_84 , sizeof( T_12 ) , V_17 , V_18 ) )
return FALSE ;
V_1 -> V_15 += sizeof( T_12 ) ;
V_1 -> V_33 += F_6 ( & V_84 ) ;
if ( V_1 -> V_33 >= 10 ) {
V_1 -> V_32 += V_1 -> V_33 / 10 ;
V_1 -> V_33 = V_1 -> V_33 % 10 ;
}
break;
case V_28 :
if ( ! F_3 ( V_20 , & V_85 , sizeof( T_5 ) , V_17 , V_18 ) )
return FALSE ;
V_1 -> V_15 += sizeof( T_5 ) ;
V_1 -> V_33 += V_85 ;
if ( V_1 -> V_33 >= 10 ) {
V_1 -> V_32 += V_1 -> V_33 / 10 ;
V_1 -> V_33 = V_1 -> V_33 % 10 ;
}
break;
default:
* V_17 = V_78 ;
* V_18 = F_18 ( L_2 , V_80 ) ;
return FALSE ;
}
}
V_86:
* V_17 = F_17 ( V_20 , V_18 ) ;
if ( * V_17 == 0 ) {
if ( V_1 -> V_15 != V_83 ) {
* V_17 = V_21 ;
}
}
return FALSE ;
}
static T_7
V_43 ( T_3 * V_16 ,
T_8 V_89 ,
struct V_52 * V_53 ,
T_13 * V_64 ,
int * V_17 ,
T_4 * * V_18 )
{
int V_2 ;
T_5 * V_74 ;
T_6 V_54 ;
T_1 * V_1 ;
T_9 * V_65 ;
T_8 V_79 ;
V_1 = ( T_1 * ) V_16 -> V_31 ;
V_65 = ( T_9 * ) F_20 ( V_1 -> V_49 , V_89 ) ;
if ( ! V_65 ) {
* V_17 = V_78 ;
* V_18 = F_21 ( L_3 ) ;
return FALSE ;
}
if ( F_4 ( V_16 -> V_48 , V_65 -> V_15 , V_30 , V_17 ) == - 1 )
return FALSE ;
F_1 ( V_1 -> V_14 ) ;
V_1 -> V_14 -> V_15 = V_65 -> V_15 ;
F_10 ( V_64 , V_39 ) ;
V_74 = F_11 ( V_64 ) ;
V_79 = V_65 -> V_79 ;
do {
if ( ! F_12 ( V_1 -> V_14 , V_16 -> V_48 , V_17 , V_18 ,
V_74 , & V_2 , & V_54 , NULL , V_79 ) )
return FALSE ;
V_79 = 0 ;
} while ( V_54 != V_65 -> V_5 );
F_9 ( V_53 , V_2 , V_65 -> V_5 ) ;
return TRUE ;
}
static void
V_45 ( T_3 * V_16 )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) V_16 -> V_31 ;
if ( V_1 -> V_14 ) {
F_13 ( V_1 -> V_14 ) ;
}
if ( V_1 -> V_49 ) {
unsigned int V_90 ;
for ( V_90 = 0 ; V_90 < F_22 ( V_1 -> V_49 ) ; V_90 ++ ) {
F_13 ( F_20 ( V_1 -> V_49 , V_90 ) ) ;
}
F_23 ( V_1 -> V_49 , TRUE ) ;
}
}
