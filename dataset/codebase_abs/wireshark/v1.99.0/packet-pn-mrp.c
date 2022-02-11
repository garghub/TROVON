static int
F_1 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 , T_4 * T_5 V_5 )
{
T_6 V_6 ;
T_7 V_7 ;
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_8 , & V_6 ) ;
V_2 = F_3 ( V_1 , V_2 , V_3 , V_4 , V_9 , & V_7 ) ;
return V_2 ;
}
static int
F_4 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 , T_4 * T_5 V_5 , T_8 type )
{
T_8 V_10 [ 6 ] ;
T_6 V_11 ;
T_6 V_12 ;
T_6 V_13 ;
T_4 * V_14 ;
V_2 = F_5 ( V_1 , V_2 , V_3 , V_4 , V_15 , V_10 ) ;
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_16 , & V_11 ) ;
V_2 = F_6 ( V_1 , V_2 , V_3 , V_4 , V_17 , & V_12 , & V_14 ) ;
if ( V_4 )
{
F_7 ( V_14 , L_1 ) ;
if ( V_12 < 0x07D1 )
F_7 ( V_14 , L_2 ) ;
else
F_7 ( V_14 , L_3 ) ;
}
V_2 = F_6 ( V_1 , V_2 , V_3 , V_4 , V_18 , & V_13 , & V_14 ) ;
if ( V_4 )
{
if ( V_13 == 0 )
F_7 ( V_14 , L_4 ) ;
else
if ( V_13 == 1 )
F_7 ( V_14 , L_5 ) ;
else
F_7 ( V_14 , L_6 ) ;
}
V_2 = F_8 ( V_1 , V_2 , V_3 , V_4 ) ;
if( type == 4 )
{
F_9 ( V_3 -> V_19 , V_20 , L_7 ) ;
F_7 ( T_5 , L_7 ) ;
}
else
{
F_9 ( V_3 -> V_19 , V_20 , L_8 ) ;
F_7 ( T_5 , L_8 ) ;
}
return V_2 ;
}
static const char * F_10 ( T_6 V_21 )
{
if ( V_21 == 0x0000 )
return ( L_9 ) ;
if ( ( V_21 >= 0x1000 ) && ( V_21 <= 0x7000 ) )
return ( L_10 ) ;
if ( V_21 == 0x8000 )
return ( L_11 ) ;
if ( ( V_21 >= 0x8001 ) && ( V_21 <= 0x8FFF ) )
return ( L_12 ) ;
if ( ( V_21 >= 0x9000 ) && ( V_21 <= 0x9FFF ) )
return ( L_13 ) ;
if ( V_21 == 0xA000 )
return ( L_14 ) ;
if ( ( V_21 >= 0xA001 ) && ( V_21 <= 0xF000 ) )
return ( L_15 ) ;
if ( V_21 == 0xFFFF )
return ( L_16 ) ;
return ( L_6 ) ;
}
static int
F_11 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 , T_4 * T_5 V_5 )
{
T_6 V_21 ;
T_8 V_10 [ 6 ] ;
T_6 V_11 ;
T_6 V_22 ;
T_6 V_23 ;
T_9 V_24 ;
T_4 * V_14 ;
V_2 = F_6 ( V_1 , V_2 , V_3 , V_4 , V_25 , & V_21 , & V_14 ) ;
if ( V_4 )
F_7 ( V_14 , L_17 , F_10 ( V_21 ) ) ;
V_2 = F_5 ( V_1 , V_2 , V_3 , V_4 , V_15 , V_10 ) ;
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_16 , & V_11 ) ;
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_26 , & V_22 ) ;
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_27 , & V_23 ) ;
V_2 = F_12 ( V_1 , V_2 , V_3 , V_4 , V_28 , & V_24 ) ;
V_2 = F_8 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_2 ;
}
static int
F_13 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 , T_4 * T_5 V_5 )
{
T_6 V_21 ;
T_8 V_10 [ 6 ] ;
T_6 V_12 ;
T_4 * V_14 ;
V_2 = F_6 ( V_1 , V_2 , V_3 , V_4 , V_25 , & V_21 , & V_14 ) ;
if ( V_4 )
F_7 ( V_14 , L_17 , F_10 ( V_21 ) ) ;
V_2 = F_5 ( V_1 , V_2 , V_3 , V_4 , V_15 , V_10 ) ;
V_2 = F_6 ( V_1 , V_2 , V_3 , V_4 , V_17 , & V_12 , & V_14 ) ;
if ( V_4 )
{
F_7 ( V_14 , L_18 ) ;
if ( V_12 < 0x07D1 )
F_7 ( V_14 , L_19 ) ;
else
F_7 ( V_14 , L_20 ) ;
}
return V_2 ;
}
static int
F_14 ( T_1 * V_1 , int V_2 , T_2 * V_3 V_5 ,
T_3 * V_4 , T_9 V_29 )
{
F_15 ( V_4 , V_30 , V_1 , V_2 , V_29 , L_21 ,
L_22 , V_29 ) ;
return V_2 + V_29 ;
}
static int
F_16 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 , T_4 * T_5 , T_8 V_29 )
{
T_9 V_31 ;
V_2 = F_17 ( V_1 , V_2 , V_3 , V_4 , V_32 , & V_31 ) ;
V_29 -= 3 ;
switch ( V_31 )
{
case V_33 :
F_7 ( T_5 , L_23 ) ;
if ( V_29 != 0 ) {
V_2 = F_14 ( V_1 , V_2 , V_3 , V_4 , V_29 ) ;
}
F_9 ( V_3 -> V_19 , V_20 , L_24 ) ;
break;
default:
F_7 ( T_5 , L_25 ) ;
V_2 = F_18 ( V_1 , V_2 , V_3 , V_4 , V_29 ) ;
}
V_2 = F_8 ( V_1 , V_2 , V_3 , V_4 ) ;
return V_2 ;
}
static int
F_19 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 , T_4 * T_5 )
{
T_6 V_34 ;
T_8 type ;
T_8 V_29 ;
T_10 V_35 ;
T_1 * V_36 ;
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_37 , & V_34 ) ;
V_36 = F_20 ( V_1 , V_2 ) ;
V_2 = 0 ;
for( V_35 = 0 ; F_21 ( V_1 , V_2 ) > 0 ; V_35 ++ ) {
V_2 = F_22 ( V_36 , V_2 , V_3 , V_4 , V_38 , & type ) ;
V_2 = F_22 ( V_36 , V_2 , V_3 , V_4 , V_39 , & V_29 ) ;
if ( V_35 != 0 ) {
F_9 ( V_3 -> V_19 , V_20 , L_26 ) ;
F_7 ( T_5 , L_26 ) ;
} else {
F_7 ( T_5 , L_27 ) ;
}
F_9 ( V_3 -> V_19 , V_20 , F_23 ( type , V_40 , L_28 ) ) ;
F_7 ( T_5 , L_17 , F_23 ( type , V_40 , L_28 ) ) ;
switch( type ) {
case 0x00 :
return V_2 ;
break;
case 0x01 :
V_2 = F_1 ( V_36 , V_2 , V_3 , V_4 , T_5 ) ;
break;
case 0x02 :
V_2 = F_11 ( V_36 , V_2 , V_3 , V_4 , T_5 ) ;
break;
case 0x03 :
V_2 = F_13 ( V_36 , V_2 , V_3 , V_4 , T_5 ) ;
break;
case 0x04 :
case 0x05 :
V_2 = F_4 ( V_36 , V_2 , V_3 , V_4 , T_5 , type ) ;
break;
case 0x7f :
V_2 = F_16 ( V_36 , V_2 , V_3 , V_4 , T_5 , V_29 ) ;
break;
default:
V_2 = F_18 ( V_1 , V_2 , V_3 , V_4 , V_29 ) ;
}
}
return V_2 ;
}
static void
F_24 ( T_1 * V_1 , T_2 * V_3 , T_3 * V_4 )
{
T_4 * V_41 = NULL ;
T_3 * V_42 = NULL ;
T_9 V_2 = 0 ;
F_25 ( V_3 -> V_19 , V_43 , L_29 ) ;
F_26 ( V_3 -> V_19 , V_20 ) ;
if ( V_4 )
{
V_41 = F_27 ( V_4 , V_44 , V_1 , V_2 , - 1 , V_45 ) ;
V_42 = F_28 ( V_41 , V_46 ) ;
}
F_19 ( V_1 , V_2 , V_3 , V_42 , V_41 ) ;
}
void
F_29 ( void )
{
static T_11 V_47 [] = {
{ & V_38 ,
{ L_30 , L_31 ,
V_48 , V_49 , F_30 ( V_40 ) , 0x0 ,
NULL , V_50 } } ,
{ & V_39 ,
{ L_32 , L_33 ,
V_48 , V_51 , NULL , 0x0 ,
NULL , V_50 } } ,
{ & V_37 ,
{ L_34 , L_35 ,
V_52 , V_51 , NULL , 0x0 ,
NULL , V_50 } } ,
{ & V_8 ,
{ L_36 , L_37 ,
V_52 , V_49 , NULL , 0x0 ,
L_38 , V_50 } } ,
{ & V_15 ,
{ L_39 , L_40 ,
V_53 , V_54 , 0x0 , 0x0 ,
NULL , V_50 } } ,
{ & V_25 ,
{ L_41 , L_42 ,
V_52 , V_49 , 0 , 0x0 ,
NULL , V_50 } } ,
{ & V_16 ,
{ L_43 , L_44 ,
V_52 , V_49 , F_30 ( V_55 ) , 0x0 ,
NULL , V_50 } } ,
{ & V_26 ,
{ L_45 , L_46 ,
V_52 , V_49 , F_30 ( V_56 ) , 0x0 ,
NULL , V_50 } } ,
{ & V_17 ,
{ L_47 , L_48 ,
V_52 , V_51 , NULL , 0x0 ,
L_1 , V_50 } } ,
{ & V_27 ,
{ L_49 , L_50 ,
V_52 , V_49 , NULL , 0x0 ,
L_51 , V_50 } } ,
{ & V_28 ,
{ L_52 , L_53 ,
V_57 , V_49 , NULL , 0x0 ,
L_54 , V_50 } } ,
{ & V_18 ,
{ L_55 , L_56 ,
V_52 , V_49 , NULL , 0x0 ,
NULL , V_50 } } ,
{ & V_30 ,
{ L_57 , L_58 ,
V_58 , V_54 , NULL , 0x0 ,
NULL , V_50 } } ,
{ & V_9 ,
{ L_59 , L_60 ,
V_59 , V_54 , NULL , 0x0 ,
NULL , V_50 } } ,
{ & V_32 ,
{ L_61 , L_62 ,
V_60 , V_49 , F_30 ( V_61 ) , 0x0 ,
NULL , V_50 } } ,
} ;
static T_10 * V_62 [] = {
& V_46
} ;
V_44 = F_31 ( L_63 , L_29 , L_64 ) ;
F_32 ( V_44 , V_47 , F_33 ( V_47 ) ) ;
F_34 ( V_62 , F_33 ( V_62 ) ) ;
}
void
F_35 ( void )
{
T_12 V_63 ;
V_63 = F_36 ( F_24 , V_44 ) ;
F_37 ( L_65 , V_64 , V_63 ) ;
}
