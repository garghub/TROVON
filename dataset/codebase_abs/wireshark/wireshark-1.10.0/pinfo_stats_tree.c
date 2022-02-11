static const T_1 * F_1 ( T_2 type ) {
switch ( type ) {
case V_1 : return L_1 ;
case V_2 : return L_2 ;
case V_3 : return L_3 ;
case V_4 : return L_4 ;
case V_5 : return L_5 ;
case V_6 : return L_6 ;
case V_7 : return L_7 ;
case V_8 : return L_8 ;
case V_9 : return L_9 ;
case V_10 : return L_10 ;
default: return L_11 ;
}
}
static void * F_2 ( void * V_11 , const void * V_12 , T_3 T_4 V_13 ) {
const T_5 * V_14 = ( const T_5 * ) V_12 ;
T_5 * V_15 = ( T_5 * ) V_11 ;
if ( V_14 -> V_16 )
V_15 -> V_16 = F_3 ( V_14 -> V_16 ) ;
return V_11 ;
}
static void F_4 ( void * V_14 ) {
T_5 * V_17 = ( T_5 * ) V_14 ;
if ( V_17 -> V_16 )
F_5 ( V_17 -> V_16 ) ;
}
static void F_6 ( void ) {
T_6 V_18 , V_19 ;
T_5 V_20 ;
if ( V_21 == 0 ) {
V_19 = sizeof( V_22 ) / sizeof( V_23 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
{
V_20 . V_16 = & V_22 [ V_18 ] ;
F_7 ( V_24 , & V_20 , TRUE ) ;
}
}
}
static void F_8 ( T_7 * V_25 ) {
V_26 = F_9 ( V_25 , V_27 , 0 , TRUE ) ;
}
static int F_10 ( T_7 * V_25 , T_8 * V_28 , T_9 * T_10 V_13 , const void * T_11 V_13 ) {
F_11 ( V_25 , V_27 , 0 , FALSE ) ;
F_11 ( V_25 , F_12 ( & V_28 -> V_29 ) , V_26 , FALSE ) ;
F_11 ( V_25 , F_12 ( & V_28 -> V_30 ) , V_26 , FALSE ) ;
return 1 ;
}
static void F_13 ( T_7 * V_25 ) {
V_31 = F_14 ( V_25 , V_32 , 0 ) ;
}
static int F_15 ( T_7 * V_25 , T_8 * V_28 , T_9 * T_10 V_13 , const void * T_11 V_13 ) {
const T_1 * V_33 ;
V_33 = F_1 ( V_28 -> V_33 ) ;
F_16 ( V_25 , V_31 , V_33 ) ;
return 1 ;
}
static void F_17 ( T_7 * V_25 ) {
T_6 V_18 ;
char * * V_34 = ( char * * ) F_18 ( V_21 * sizeof( char * ) ) ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
V_34 [ V_18 ] = F_19 ( V_35 [ V_18 ] . V_16 ) ;
}
V_36 = F_20 ( V_25 , V_37 , 0 , V_21 , V_34 ) ;
}
static int F_21 ( T_7 * V_25 , T_8 * V_28 , T_9 * T_10 V_13 , const void * T_11 V_13 ) {
F_11 ( V_25 , V_37 , 0 , FALSE ) ;
F_22 ( V_25 , V_37 , 0 , V_28 -> V_38 -> V_39 ) ;
return 1 ;
}
static void F_23 ( T_7 * V_25 ) {
V_40 = F_9 ( V_25 , V_41 , 0 , TRUE ) ;
}
static int F_24 ( T_7 * V_25 , T_8 * V_28 , T_9 * T_10 V_13 , const void * T_11 V_13 ) {
static T_1 V_42 [ 128 ] ;
int V_43 ;
int V_44 ;
F_11 ( V_25 , V_41 , 0 , FALSE ) ;
V_43 = F_11 ( V_25 , F_12 ( & V_28 -> V_29 ) , V_40 , TRUE ) ;
V_44 = F_11 ( V_25 , F_1 ( V_28 -> V_33 ) , V_43 , TRUE ) ;
F_25 ( V_42 , sizeof( V_42 ) , L_12 , V_28 -> V_45 ) ;
F_11 ( V_25 , V_42 , V_44 , TRUE ) ;
return 1 ;
}
void F_26 ( void ) {
T_12 * V_46 ;
static T_13 V_47 [] = {
F_27 ( V_35 , V_16 , L_13 , 0xFFFFFFFF , L_14 ) ,
V_48
} ;
F_28 ( L_15 , L_16 , V_27 , 0 , F_10 , F_8 , NULL ) ;
F_28 ( L_15 , L_17 , V_32 , 0 , F_15 , F_13 , NULL ) ;
F_29 ( L_18 , L_19 , V_37 , 0 , F_21 , F_17 , NULL , V_49 ) ;
F_28 ( L_15 , L_20 , V_41 , 0 , F_24 , F_23 , NULL ) ;
V_46 = F_30 ( L_21 , L_22 , L_22 , NULL ) ;
V_24 = F_31 ( L_23 ,
sizeof( T_5 ) ,
L_24 ,
TRUE ,
( void * * ) & V_35 ,
& V_21 ,
0 ,
NULL ,
F_2 ,
NULL ,
F_4 ,
F_6 ,
V_47 ) ;
F_32 ( V_46 , L_24 ,
L_23 , L_25 , V_24 ) ;
}
