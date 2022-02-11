static T_1
F_1 ( const T_2 * V_1 , int T_3 V_2 , int V_3 , T_4 * V_4 , const union V_5 * T_5 V_2 )
{
T_6 V_6 ;
if ( ! F_2 ( 0 , V_3 , 2 ) )
return FALSE ;
if ( V_1 [ 0 ] == 0xFF && V_1 [ 1 ] == 0x03 ) {
return F_3 ( V_1 , 0 , V_3 , V_4 , T_5 ) ;
} else {
if ( ! F_2 ( 0 , V_3 , ( int ) sizeof( V_6 ) ) )
return FALSE ;
memcpy ( ( char * ) & V_6 , ( const char * ) & V_1 [ 0 ] , sizeof( V_6 ) ) ;
if ( ( V_6 & 0xFFFF0000 ) != 0 ) {
if ( ( V_6 & 0xFF000000 ) == 0 &&
( V_6 & 0x00FF0000 ) < 0x00060000 ) {
V_6 >>= 16 ;
} else {
V_6 = F_4 ( V_6 ) ;
}
} else {
if ( ( V_6 & 0x000000FF ) == 0 &&
( V_6 & 0x0000FF00 ) < 0x00000600 ) {
V_6 = F_5 ( V_6 & 0xFFFF ) ;
}
}
if ( V_6 > V_7 )
return F_6 ( L_1 , V_6 , V_1 , 4 , V_3 , V_4 , T_5 ) ;
else {
switch ( V_6 ) {
case V_8 :
return F_7 ( V_1 , 4 , V_3 , V_4 , T_5 ) ;
case V_9 :
case V_10 :
case V_11 :
return F_8 ( V_1 , 4 , V_3 , V_4 , T_5 ) ;
}
}
}
return FALSE ;
}
static T_1
F_9 ( const T_2 * V_1 , int T_3 V_2 , int V_3 , T_4 * V_4 , const union V_5 * T_5 V_2 )
{
T_6 V_12 ;
if ( ! F_2 ( 0 , V_3 , ( int ) sizeof( V_12 ) ) )
return FALSE ;
V_12 = F_10 ( & V_1 [ 0 ] ) ;
switch ( V_12 ) {
case V_8 :
return F_7 ( V_1 , 4 , V_3 , V_4 , T_5 ) ;
case V_9 :
case V_10 :
case V_11 :
return F_8 ( V_1 , 4 , V_3 , V_4 , T_5 ) ;
}
return FALSE ;
}
static int
F_11 ( T_7 * V_13 , T_8 * V_14 , T_9 * V_15 , void * T_10 V_2 )
{
T_6 V_6 ;
T_9 * V_16 ;
T_11 * V_17 ;
T_7 * V_18 ;
if ( F_12 ( V_13 , 0 ) == 0xFF03 ) {
F_13 ( V_19 , V_13 , V_14 , V_15 ) ;
} else {
F_14 ( V_14 -> V_20 , V_21 , L_2 ) ;
F_14 ( V_14 -> V_20 , V_22 , L_2 ) ;
F_14 ( V_14 -> V_20 , V_23 , L_2 ) ;
F_14 ( V_14 -> V_20 , V_24 , L_3 ) ;
F_15 ( V_13 , ( V_25 * ) & V_6 , 0 , sizeof( V_6 ) ) ;
if ( ( V_6 & 0xFFFF0000 ) != 0 ) {
if ( ( V_6 & 0xFF000000 ) == 0 &&
( V_6 & 0x00FF0000 ) < 0x00060000 ) {
V_6 >>= 16 ;
} else {
V_6 = F_4 ( V_6 ) ;
}
} else {
if ( ( V_6 & 0x000000FF ) == 0 &&
( V_6 & 0x0000FF00 ) < 0x00000600 ) {
V_6 = F_5 ( V_6 & 0xFFFF ) ;
}
}
if ( V_6 > V_7 ) {
if ( V_15 ) {
V_17 = F_16 ( V_15 , V_26 , V_13 , 0 , 4 , V_27 ) ;
V_16 = F_17 ( V_17 , V_28 ) ;
F_18 ( V_16 , V_29 , V_13 , 0 , 4 ,
( V_30 ) V_6 ) ;
}
V_18 = F_19 ( V_13 , 4 ) ;
if ( ! F_20 ( V_31 ,
( V_30 ) V_6 , V_18 , V_14 , V_15 ) )
F_21 ( V_18 , V_14 , V_15 ) ;
} else {
if ( V_15 ) {
V_17 = F_16 ( V_15 , V_26 , V_13 , 0 , 4 , V_27 ) ;
V_16 = F_17 ( V_17 , V_28 ) ;
F_18 ( V_16 , V_32 , V_13 , 0 , 4 , V_6 ) ;
}
V_18 = F_19 ( V_13 , 4 ) ;
if ( ! F_20 ( V_33 , V_6 ,
V_18 , V_14 , V_15 ) ) {
F_21 ( V_18 , V_14 , V_15 ) ;
}
}
}
return F_22 ( V_13 ) ;
}
static int
F_23 ( T_7 * V_13 , T_8 * V_14 , T_9 * V_15 , void * T_10 V_2 )
{
T_6 V_12 ;
T_9 * V_16 ;
T_11 * V_17 ;
T_7 * V_18 ;
F_14 ( V_14 -> V_20 , V_21 , L_2 ) ;
F_14 ( V_14 -> V_20 , V_22 , L_2 ) ;
F_14 ( V_14 -> V_20 , V_23 , L_2 ) ;
F_14 ( V_14 -> V_20 , V_24 , L_3 ) ;
V_12 = F_24 ( V_13 , 0 ) ;
if ( V_15 ) {
V_17 = F_16 ( V_15 , V_26 , V_13 , 0 , 4 , V_27 ) ;
V_16 = F_17 ( V_17 , V_28 ) ;
F_18 ( V_16 , V_32 , V_13 , 0 , 4 , V_12 ) ;
}
V_18 = F_19 ( V_13 , 4 ) ;
if ( ! F_20 ( V_33 , V_12 ,
V_18 , V_14 , V_15 ) ) {
F_21 ( V_18 , V_14 , V_15 ) ;
}
return F_22 ( V_13 ) ;
}
void
F_25 ( void )
{
static T_12 V_34 [] = {
{ & V_29 ,
{ L_4 , L_5 , V_35 , V_36 , F_26 ( V_37 ) , 0x0 ,
NULL , V_38 } } ,
{ & V_32 ,
{ L_6 , L_7 , V_39 , V_40 , F_26 ( V_41 ) , 0x0 ,
NULL , V_38 } }
} ;
static T_13 * V_42 [] = {
& V_28 ,
} ;
V_26 = F_27 ( L_3 , L_8 , L_9 ) ;
F_28 ( V_26 , V_34 , F_29 ( V_34 ) ) ;
F_30 ( V_42 , F_29 ( V_42 ) ) ;
V_33 = F_31 ( L_5 ,
L_10 , V_26 , V_39 , V_40 ) ;
}
void
F_32 ( void )
{
T_14 V_43 , V_44 ;
V_19 = F_33 ( L_11 , V_26 ) ;
V_31 = F_34 ( L_1 ) ;
V_43 = F_35 ( F_11 , V_26 ) ;
F_36 ( L_12 , V_45 , V_43 ) ;
V_44 = F_35 ( F_23 , V_26 ) ;
F_36 ( L_12 , V_46 , V_44 ) ;
F_37 ( L_12 , V_45 , F_1 , V_26 ) ;
F_37 ( L_12 , V_46 , F_9 , V_26 ) ;
}
