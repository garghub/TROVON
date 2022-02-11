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
F_3 ( V_19 , sizeof( V_19 ) , V_16 -> V_20 , V_17 ,
V_18 ) ;
if ( V_19 [ 0 ] == V_21 &&
( V_19 [ 5 ] == V_22 ||
V_19 [ 5 ] == V_23 ||
V_19 [ 5 ] == V_24 ||
V_19 [ 5 ] == V_25 ||
V_19 [ 5 ] == V_21 ) ) {
goto V_26;
}
else {
return 0 ;
}
V_26:
if ( F_4 ( V_16 -> V_20 , 5 , V_27 , V_17 ) == - 1 )
return - 1 ;
V_1 = ( T_1 * ) F_5 ( sizeof( T_1 ) ) ;
V_16 -> V_28 = ( void * ) V_1 ;
V_1 -> V_29 = F_6 ( & V_19 [ 1 ] ) ;
V_1 -> V_30 = 0 ;
F_1 ( V_1 ) ;
V_1 -> V_15 = 5 ;
V_16 -> V_31 = V_32 ;
V_16 -> V_33 = V_34 ;
V_16 -> V_35 = V_36 ;
V_16 -> V_37 = V_38 ;
V_16 -> V_39 = V_40 ;
V_16 -> V_41 = V_42 ;
V_16 -> V_43 = V_44 ;
V_1 -> V_14 = F_7 ( T_1 , 1 ) ;
if ( V_16 -> V_45 != NULL )
V_1 -> V_46 = F_8 () ;
else
V_1 -> V_46 = NULL ;
V_1 -> V_47 = 0 ;
return 1 ;
}
static T_5
V_38 ( T_2 * V_16 , int * V_17 , T_3 * * V_18 , T_6 * V_48 )
{
int V_2 ;
T_7 V_49 ;
T_4 * V_50 ;
T_1 * V_1 ;
T_8 * V_51 ;
F_9 ( V_16 -> V_52 , V_36 ) ;
V_50 = F_10 ( V_16 -> V_52 ) ;
V_1 = ( T_1 * ) V_16 -> V_28 ;
if ( V_16 -> V_45 != NULL ) {
V_51 = F_7 ( T_8 , 1 ) ;
if ( ! V_51 ) {
* V_17 = V_53 ;
return FALSE ;
}
V_51 -> V_15 = 0 ;
} else
V_51 = NULL ;
if ( ! F_11 ( V_1 , V_16 -> V_20 , V_17 , V_18 , V_50 , & V_2 , & V_49 ,
V_51 , 0 ) ) {
if ( V_51 != NULL )
F_12 ( V_51 ) ;
return FALSE ;
}
if ( V_51 != NULL )
V_51 -> V_5 = V_49 ;
if ( V_51 != NULL )
F_13 ( V_1 -> V_46 , V_51 ) ;
* V_48 = V_1 -> V_47 ;
V_1 -> V_47 ++ ;
V_16 -> V_54 . V_55 = V_56 ;
V_16 -> V_54 . V_57 = V_2 ;
V_16 -> V_54 . V_58 = V_2 ;
V_16 -> V_54 . V_59 . V_60 = V_1 -> V_29 ;
V_16 -> V_54 . V_59 . V_61 = V_1 -> V_30 * 100000000 ;
V_16 -> V_54 . V_62 = V_32 ;
V_16 -> V_63 . V_64 . V_65 = ( V_49 == V_6 ? TRUE : FALSE ) ;
return TRUE ;
}
static int
F_14 ( T_1 * V_1 , T_9 V_20 , T_10 * V_3 , int V_66 , T_4 * V_67 ,
int * V_17 , T_3 * * V_18 , T_8 * V_51 )
{
int V_68 ;
int V_2 = V_66 ;
int V_69 ;
for (; V_2 > 0 ; -- V_2 ) {
V_68 = F_15 ( V_20 ) ;
if ( V_68 == V_70 ) {
* V_17 = F_16 ( V_20 , V_18 ) ;
if ( * V_17 == 0 ) {
* V_17 = V_71 ;
}
return - 1 ;
}
V_1 -> V_15 ++ ;
switch ( V_68 ) {
case 0x7e :
if ( V_3 -> V_7 > 0 ) {
V_3 -> V_8 = FALSE ;
V_69 = V_3 -> V_7 ;
V_3 -> V_7 = 0 ;
if ( V_69 <= 0 ) {
return 0 ;
}
if ( V_69 > V_36 ) {
* V_17 = V_72 ;
return - 1 ;
}
memcpy ( V_67 , V_3 -> V_50 , V_69 ) ;
if ( V_51 ) {
V_51 -> V_15 = V_3 -> V_9 ;
V_51 -> V_73 =
V_3 -> V_10 - V_3 -> V_9 - 3 ;
F_17 ( V_51 -> V_73 >= 0 ) ;
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
return V_69 ;
}
break;
case 0x7d :
if ( ! V_3 -> V_8 ) {
V_3 -> V_8 = TRUE ;
break;
}
default:
if ( V_3 -> V_8 ) {
V_68 ^= 0x20 ;
V_3 -> V_8 = FALSE ;
}
if ( V_3 -> V_7 >= V_36 ) {
* V_17 = V_72 ;
return - 1 ;
}
V_3 -> V_50 [ V_3 -> V_7 ++ ] = V_68 ;
break;
}
}
return 0 ;
}
static T_5
F_11 ( T_1 * V_1 , T_9 V_20 , int * V_17 , T_3 * * V_18 , T_4 * V_67 ,
int * V_2 , T_7 * V_49 , T_8 * V_51 ,
T_6 V_73 )
{
int V_74 ;
T_10 * V_3 = NULL ;
int V_75 , V_76 ;
int V_66 , V_69 = 0 ;
T_6 V_77 ;
T_11 V_78 ;
T_4 V_79 ;
if ( V_1 -> V_2 > 0 ) {
F_17 ( V_73 == 0 ) ;
V_3 = V_1 -> V_3 ;
V_69 = F_14 ( V_1 , V_20 , V_3 , V_1 -> V_2 ,
V_67 , V_17 , V_18 , V_51 ) ;
if ( V_69 < 0 ) {
return FALSE ;
}
else if ( V_69 > 0 ) {
* V_2 = V_69 ;
* V_49 = V_3 -> V_5 ;
return TRUE ;
}
} else {
if ( V_51 )
V_51 -> V_73 = 0 ;
}
V_77 = V_1 -> V_15 ;
while ( ( V_74 = F_15 ( V_20 ) ) != V_70 ) {
V_1 -> V_15 ++ ;
switch ( V_74 ) {
case V_22 :
case V_23 :
V_3 = V_74 == V_22 ? & V_1 -> V_4 : & V_1 -> V_12 ;
V_3 -> V_11 = V_1 -> V_15 - 1 ;
V_75 = F_15 ( V_20 ) ;
if ( V_75 == V_70 )
goto V_80;
V_1 -> V_15 ++ ;
V_76 = F_15 ( V_20 ) ;
if ( V_76 == V_70 )
goto V_80;
V_1 -> V_15 ++ ;
V_66 = ( V_75 << 8 ) | V_76 ;
if ( V_3 -> V_9 == 0 ) {
V_3 -> V_9 = V_3 -> V_11 ;
V_3 -> V_10 = V_1 -> V_15 ;
}
if ( V_66 == 0 )
continue;
F_17 ( V_73 < V_66 ) ;
while ( V_73 ) {
if ( F_15 ( V_20 ) == V_70 )
goto V_80;
V_1 -> V_15 ++ ;
V_73 -- ;
V_66 -- ;
}
V_69 = F_14 ( V_1 , V_20 , V_3 , V_66 ,
V_67 , V_17 , V_18 , V_51 ) ;
if ( V_69 < 0 ) {
return FALSE ;
}
else if ( V_69 > 0 ) {
* V_2 = V_69 ;
* V_49 = V_3 -> V_5 ;
return TRUE ;
}
break;
case V_81 :
case V_82 :
break;
case V_21 :
F_3 ( & V_78 , sizeof( T_11 ) , V_20 , V_17 , V_18 ) ;
V_1 -> V_15 += sizeof( T_11 ) ;
V_1 -> V_29 = F_6 ( & V_78 ) ;
V_1 -> V_30 = 0 ;
break;
case V_24 :
F_3 ( & V_78 , sizeof( T_11 ) , V_20 , V_17 , V_18 ) ;
V_1 -> V_15 += sizeof( T_11 ) ;
V_1 -> V_30 += F_6 ( & V_78 ) ;
if ( V_1 -> V_30 >= 10 ) {
V_1 -> V_29 += V_1 -> V_30 / 10 ;
V_1 -> V_30 = V_1 -> V_30 % 10 ;
}
break;
case V_25 :
F_3 ( & V_79 , sizeof( T_4 ) , V_20 , V_17 , V_18 ) ;
V_1 -> V_15 += sizeof( T_4 ) ;
V_1 -> V_30 += V_79 ;
if ( V_1 -> V_30 >= 10 ) {
V_1 -> V_29 += V_1 -> V_30 / 10 ;
V_1 -> V_30 = V_1 -> V_30 % 10 ;
}
break;
default:
* V_17 = V_83 ;
* V_18 = F_18 ( L_1 , V_74 ) ;
return FALSE ;
}
}
V_80:
* V_17 = F_16 ( V_20 , V_18 ) ;
if ( * V_17 == 0 ) {
if ( V_1 -> V_15 != V_77 ) {
* V_17 = V_71 ;
}
}
return FALSE ;
}
static T_5
V_40 ( T_2 * V_16 ,
T_6 V_84 ,
union V_85 * V_63 ,
T_4 * V_67 ,
int V_57 ,
int * V_17 ,
T_3 * * V_18 )
{
int V_2 ;
T_7 V_49 ;
T_1 * V_1 ;
T_8 * V_51 ;
T_6 V_73 ;
V_1 = ( T_1 * ) V_16 -> V_28 ;
V_51 = ( T_8 * ) F_19 ( V_1 -> V_46 , V_84 ) ;
if ( ! V_51 ) {
* V_17 = V_83 ;
* V_18 = F_20 ( L_2 ) ;
return FALSE ;
}
if ( F_4 ( V_16 -> V_45 , V_51 -> V_15 , V_27 , V_17 ) == - 1 )
return FALSE ;
F_1 ( V_1 -> V_14 ) ;
V_1 -> V_14 -> V_15 = V_51 -> V_15 ;
V_73 = V_51 -> V_73 ;
do {
if ( ! F_11 ( V_1 -> V_14 , V_16 -> V_45 , V_17 , V_18 ,
V_67 , & V_2 , & V_49 , NULL , V_73 ) )
return FALSE ;
V_73 = 0 ;
} while ( V_49 != V_51 -> V_5 );
if ( V_57 != V_2 ) {
* V_17 = V_83 ;
* V_18 = F_18 ( L_3 ,
V_57 , V_2 ) ;
return FALSE ;
}
V_63 -> V_64 . V_65 = ( V_51 -> V_5 == V_6 ? TRUE : FALSE ) ;
return TRUE ;
}
static void
V_42 ( T_2 * V_16 )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) V_16 -> V_28 ;
if ( V_1 -> V_14 ) {
F_12 ( V_1 -> V_14 ) ;
}
if ( V_1 -> V_46 ) {
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < F_21 ( V_1 -> V_46 ) ; V_86 ++ ) {
F_12 ( F_19 ( V_1 -> V_46 , V_86 ) ) ;
}
F_22 ( V_1 -> V_46 , TRUE ) ;
}
}
