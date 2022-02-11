static void
F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
int V_3 ;
for( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_2 -> V_5 [ V_3 ] . V_6 . V_7 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_8 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_9 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_10 . V_11 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_10 . V_12 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_13 . V_11 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_13 . V_12 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_14 . V_11 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_14 . V_12 = 0 ;
V_2 -> V_5 [ V_3 ] . V_15 = 0 ;
V_2 -> V_5 [ V_3 ] . V_16 = 0 ;
V_2 -> V_5 [ V_3 ] . V_17 = 0 ;
V_2 -> V_5 [ V_3 ] . V_18 = 0 ;
}
}
static int
F_2 ( void * V_1 , T_2 * V_19 , T_3 * T_4 V_20 , const void * V_21 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
const T_5 * V_22 = ( T_5 * ) V_21 ;
T_6 V_23 ;
T_7 V_24 = V_25 ;
int V_26 = 0 ;
switch ( V_22 -> V_27 ) {
case V_28 :
case V_29 :
case V_30 :
V_24 = V_31 ;
break;
case V_32 :
case V_33 :
V_24 = V_34 ;
break;
case V_35 :
case V_36 :
case V_37 :
V_24 = V_38 ;
break;
case V_39 :
case V_40 :
V_24 = V_41 ;
break;
case V_42 :
case V_43 :
V_24 = V_44 ;
break;
case V_45 :
case V_46 :
V_24 = V_47 ;
break;
case V_48 :
case V_49 :
V_24 = V_50 ;
break;
case V_51 :
case V_52 :
case V_53 :
V_24 = V_54 ;
break;
case V_55 :
case V_56 :
case V_57 :
V_24 = V_58 ;
break;
}
switch ( V_22 -> V_27 ) {
case V_28 :
case V_32 :
case V_35 :
case V_48 :
case V_51 :
case V_55 :
if( V_22 -> V_59 ) {
V_2 -> V_5 [ V_60 ] . V_17 ++ ;
V_2 -> V_5 [ V_24 ] . V_17 ++ ;
}
else {
V_2 -> V_5 [ V_60 ] . V_15 ++ ;
V_2 -> V_5 [ V_24 ] . V_15 ++ ;
}
break;
case V_29 :
case V_30 :
case V_33 :
case V_36 :
case V_37 :
case V_49 :
case V_52 :
case V_53 :
case V_56 :
case V_57 :
if( V_22 -> V_59 ) {
V_2 -> V_5 [ V_60 ] . V_18 ++ ;
V_2 -> V_5 [ V_24 ] . V_18 ++ ;
}
else if ( ! V_22 -> V_61 ) {
V_2 -> V_5 [ V_60 ] . V_16 ++ ;
V_2 -> V_5 [ V_24 ] . V_16 ++ ;
}
else {
V_2 -> V_5 [ V_60 ] . V_15 -- ;
V_2 -> V_5 [ V_24 ] . V_15 -- ;
F_3 ( & V_23 , & V_19 -> V_62 -> V_63 , & V_22 -> V_64 ) ;
F_4 ( & ( V_2 -> V_5 [ V_60 ] . V_6 ) , & V_23 , V_19 ) ;
F_4 ( & ( V_2 -> V_5 [ V_24 ] . V_6 ) , & V_23 , V_19 ) ;
V_26 = 1 ;
}
break;
default:
break;
}
return V_26 ;
}
static void
F_5 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
int V_3 ;
char V_65 [ 5 ] [ 256 ] ;
T_8 * V_66 ;
T_9 V_67 ;
V_66 = F_6 ( F_7 ( V_2 -> V_68 ) ) ;
F_8 ( V_66 ) ;
for( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if( V_2 -> V_5 [ V_3 ] . V_6 . V_7 == 0 ) {
continue;
}
F_9 ( V_65 [ 0 ] , 256 , L_1 , F_10 ( & ( V_2 -> V_5 [ V_3 ] . V_6 . V_10 ) ) ) ;
F_9 ( V_65 [ 1 ] , 256 , L_1 , F_10 ( & ( V_2 -> V_5 [ V_3 ] . V_6 . V_13 ) ) ) ;
F_9 ( V_65 [ 2 ] , 256 , L_1 , F_11 ( & ( V_2 -> V_5 [ V_3 ] . V_6 . V_14 ) , V_2 -> V_5 [ V_3 ] . V_6 . V_7 ) ) ;
F_9 ( V_65 [ 3 ] , 256 , L_2 , V_2 -> V_5 [ V_3 ] . V_17 ,
V_2 -> V_5 [ V_3 ] . V_6 . V_7 ? ( ( double ) V_2 -> V_5 [ V_3 ] . V_17 * 100 ) / ( double ) V_2 -> V_5 [ V_3 ] . V_6 . V_7 : 0 ) ;
F_9 ( V_65 [ 4 ] , 256 , L_2 , V_2 -> V_5 [ V_3 ] . V_18 ,
V_2 -> V_5 [ V_3 ] . V_6 . V_7 ? ( ( double ) V_2 -> V_5 [ V_3 ] . V_18 * 100 ) / ( double ) V_2 -> V_5 [ V_3 ] . V_6 . V_7 : 0 ) ;
F_12 ( V_66 , & V_67 ) ;
F_13 ( V_66 , & V_67 ,
0 , F_14 ( V_3 , V_69 , L_3 ) ,
1 , V_2 -> V_5 [ V_3 ] . V_6 . V_7 ,
2 , V_65 [ 0 ] ,
3 , V_65 [ 1 ] ,
4 , V_65 [ 2 ] ,
5 , V_2 -> V_5 [ V_3 ] . V_6 . V_8 ,
6 , V_2 -> V_5 [ V_3 ] . V_6 . V_9 ,
7 , V_2 -> V_5 [ V_3 ] . V_15 ,
8 , V_2 -> V_5 [ V_3 ] . V_16 ,
9 , V_65 [ 3 ] ,
10 , V_65 [ 4 ] ,
- 1 ) ;
}
}
static void
F_15 ( T_10 * T_11 V_20 , T_12 V_70 )
{
T_1 * V_2 = ( T_1 * ) V_70 ;
F_16 ( V_2 ) ;
if( V_2 -> V_71 ) {
F_17 ( V_2 -> V_71 ) ;
V_2 -> V_71 = NULL ;
}
F_17 ( V_2 ) ;
}
static void
F_18 ( const char * V_72 , void * T_13 V_20 )
{
T_1 * V_2 ;
T_14 * V_73 ;
T_15 * V_74 ;
T_15 * V_75 ;
V_2 = ( T_1 * ) F_19 ( sizeof( T_1 ) ) ;
if( strncmp ( V_72 , L_4 , 11 ) == 0 ) {
V_2 -> V_71 = F_20 ( V_72 + 11 ) ;
} else {
V_2 -> V_71 = NULL ;
}
F_1 ( V_2 ) ;
V_2 -> T_11 = F_21 ( L_5 ) ;
F_22 ( F_23 ( V_2 -> T_11 ) , TRUE ) ;
F_24 ( F_23 ( V_2 -> T_11 ) , 600 , 150 ) ;
V_2 -> V_76 = F_25 ( V_77 , 3 , FALSE ) ;
F_26 ( V_2 -> T_11 , V_2 -> V_76 , L_6 , V_2 -> V_71 ) ;
V_2 -> V_78 = F_27 ( NULL , NULL ) ;
V_2 -> V_68 = F_28 ( V_2 -> V_78 , V_2 -> V_76 , V_79 , V_80 ) ;
V_73 = F_29 ( L_7 , V_2 , V_2 -> V_71 , 0 , F_1 , F_2 , F_5 ) ;
if( V_73 ) {
F_30 ( V_81 , V_82 , L_8 , V_73 -> V_65 ) ;
F_31 ( V_73 , TRUE ) ;
F_17 ( V_2 -> V_71 ) ;
F_17 ( V_2 ) ;
return;
}
V_75 = F_32 ( V_83 , NULL ) ;
F_33 ( F_34 ( V_2 -> V_76 ) , V_75 , FALSE , FALSE , 0 ) ;
V_74 = ( T_15 * ) F_35 ( F_36 ( V_75 ) , V_83 ) ;
F_37 ( V_2 -> T_11 , V_74 , V_84 ) ;
F_38 ( V_2 -> T_11 , L_9 , F_39 ( V_85 ) , NULL ) ;
F_38 ( V_2 -> T_11 , L_10 , F_39 ( F_15 ) , V_2 ) ;
F_40 ( V_2 -> T_11 ) ;
F_41 ( V_2 -> T_11 ) ;
F_42 ( & V_86 ) ;
F_43 ( F_44 ( V_2 -> T_11 ) ) ;
}
void
F_45 ( void )
{
F_46 ( & V_87 , L_11 ,
V_88 ) ;
}
