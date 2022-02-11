static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
unsigned int V_4 ;
T_4 * V_5 ;
T_3 * V_6 ;
const char * V_7 = 0 ;
F_2 ( V_2 -> V_8 , V_9 , L_1 ) ;
V_5 = F_3 ( V_3 , V_10 , V_1 , 0 , - 1 , V_11 ) ;
V_6 = F_4 ( V_5 , V_12 ) ;
F_3 ( V_6 ,
V_13 , V_1 , 0 , 4 , V_14 ) ;
F_3 ( V_6 ,
V_15 , V_1 , 4 , 4 , V_14 ) ;
F_3 ( V_6 ,
V_16 , V_1 , 8 , 4 , V_14 ) ;
F_3 ( V_6 ,
V_17 , V_1 , 12 , 4 , V_14 ) ;
if ( F_5 ( V_1 ) == 19 ) {
V_7 = L_2 ;
F_3 ( V_6 ,
V_18 , V_1 , 16 , 3 , V_14 ) ;
} else {
F_3 ( V_6 ,
V_19 , V_1 , 16 , 4 , V_14 ) ;
}
if ( F_5 ( V_1 ) <= 20 )
{
F_2 ( V_2 -> V_8 , V_20 , L_3 ) ;
} else {
V_4 = 20 ;
do
{
T_5 V_21 ;
T_6 V_22 ;
T_6 V_23 ;
T_6 * V_24 ;
int V_25 ;
char V_26 [ 3 ] ;
const char * V_27 ;
V_25 = V_4 ;
V_21 = F_6 ( V_1 , V_4 ) ;
V_4 += 2 ;
if ( V_21 == 0x434b )
V_7 = L_4 ;
if ( V_21 == 0x4e43 )
V_7 = L_5 ;
if ( V_21 == 0x464e )
V_7 = L_6 ;
if ( V_21 == 0x4944 )
V_7 = L_7 ;
if ( V_21 == 0x5054 )
V_7 = L_8 ;
if ( V_21 == 0x4d45 )
V_7 = L_9 ;
if ( F_5 ( V_1 ) == 20 )
V_7 = L_3 ;
switch( V_21 )
{
case 0x5346 : V_27 = L_10 ; break;
case 0x534b : V_27 = L_11 ; break;
case 0x4e49 : V_27 = L_12 ; break;
case 0x4e43 : V_27 = L_13 ; break;
case 0x4356 : V_27 = L_14 ; break;
case 0x564c : V_27 = L_15 ; break;
case 0x464e : V_27 = L_16 ; break;
case 0x464c : V_27 = L_17 ; break;
case 0x4252 : V_27 = L_18 ; break;
case 0x4643 : V_27 = L_19 ; break;
case 0x5354 : V_27 = L_20 ; break;
case 0x534c : V_27 = L_21 ; break;
case 0x434b : V_27 = L_22 ; break;
case 0x4e4e : V_27 = L_23 ; break;
case 0x434e : V_27 = L_24 ; break;
case 0x5054 : V_27 = L_25 ; break;
case 0x484e : V_27 = L_20 ; break;
case 0x4d45 : V_27 = L_26 ; break;
case 0x4944 : V_27 = L_27 ; break;
case 0x4144 : V_27 = L_20 ; break;
default: V_27 = L_28 ; break;
}
#define F_7 1
#define F_8 0
V_22 = F_9 ( V_1 , V_4 ) ;
V_23 = F_9 ( V_1 , ++ V_4 ) ;
V_24 = ( T_6 * ) F_10 ( F_11 () , ( V_28 ) V_23 + 1 ) ;
F_12 ( V_1 , V_24 , ++ V_4 , V_23 ) ;
V_4 += V_23 ;
V_26 [ 0 ] = F_13 ( V_21 ) & 0x00ff ;
V_26 [ 1 ] = ( F_13 ( V_21 ) & 0xff00 ) >> 8 ;
V_26 [ 2 ] = 0 ;
if ( V_22 == F_7 )
{
V_24 [ V_23 ] = 0 ;
F_14 ( V_6 , V_29 , V_1 , V_25 ,
V_4 - V_25 , V_24 , L_29 ,
( char * ) V_26 , V_27 , V_24 ) ;
} else if ( V_22 == F_8 ) {
int V_30 = 0 ;
switch( V_23 )
{
case 5 : V_30 += V_24 [ 4 ] << ( ( V_23 - 5 ) * 8 ) ;
case 4 : V_30 += V_24 [ 3 ] << ( ( V_23 - 4 ) * 8 ) ;
case 3 : V_30 += V_24 [ 2 ] << ( ( V_23 - 3 ) * 8 ) ;
case 2 : V_30 += V_24 [ 1 ] << ( ( V_23 - 2 ) * 8 ) ;
case 1 : V_30 += V_24 [ 0 ] << ( ( V_23 - 1 ) * 8 ) ;
}
V_5 = F_15 ( V_6 , V_31 , V_1 , V_25 ,
1 , V_30 , L_30 ,
( char * ) V_26 , V_27 , V_30 ) ;
F_16 ( V_5 , V_4 - V_25 ) ;
} else {
F_17 ( V_6 , V_2 , & V_32 ,
V_1 , V_25 , V_4 - V_25 , L_31 , V_22 ) ;
}
} while( V_4 < F_5 ( V_1 ) );
}
if ( V_7 )
{
F_2 ( V_2 -> V_8 , V_20 , V_7 ) ;
}
}
void
F_18 ( void )
{
static T_7 V_33 [] = {
{ & V_13 ,
{ L_22 , L_32 ,
V_34 , V_35 , NULL , 0 ,
L_33 , V_36 }
} ,
{ & V_15 ,
{ L_34 , L_35 ,
V_34 , V_35 , NULL , 0 ,
L_36 , V_36 }
} ,
{ & V_16 ,
{ L_37 , L_38 ,
V_37 , V_38 , NULL , 0 ,
L_39 , V_36 }
} ,
{ & V_17 ,
{ L_40 , L_41 ,
V_37 , V_38 , NULL , 0 ,
L_42 , V_36 }
} ,
{ & V_18 ,
{ L_43 , L_44 ,
V_39 , V_35 , NULL , 0 ,
L_45 , V_36 }
} ,
{ & V_19 ,
{ L_43 , L_44 ,
V_34 , V_35 , NULL , 0 ,
L_45 , V_36 }
} ,
{ & V_29 ,
{ L_46 , L_47 ,
V_40 , V_38 , NULL , 0 ,
NULL , V_36 }
} ,
{ & V_31 ,
{ L_48 , L_49 ,
V_34 , V_41 , NULL , 0 ,
NULL , V_36 }
} ,
} ;
static T_8 * V_42 [] = {
& V_12 ,
} ;
static T_9 V_43 [] = {
{ & V_32 , { L_50 , V_44 , V_45 , L_51 , V_46 } } ,
} ;
T_10 * V_47 ;
V_10 = F_19 ( L_52 , L_53 , L_54 ) ;
F_20 ( V_10 , V_33 , F_21 ( V_33 ) ) ;
F_22 ( V_42 , F_21 ( V_42 ) ) ;
V_47 = F_23 ( V_10 ) ;
F_24 ( V_47 , V_43 , F_21 ( V_43 ) ) ;
}
void
F_25 ( void )
{
T_11 V_48 ;
V_48 = F_26 ( F_1 ,
V_10 ) ;
F_27 ( L_55 , 41170 , V_48 ) ;
}
