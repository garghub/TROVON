int
F_1 ( T_1 * V_1 , T_2 V_2 , T_3 * T_4 V_3 ,
T_5 * V_4 , int V_5 , T_6 * V_6 , T_7 * * V_7 )
{
T_6 V_8 ;
T_7 * V_9 = NULL ;
V_8 = F_2 ( V_1 , V_2 ) ;
if ( V_4 ) {
V_9 = F_3 ( V_4 , V_5 , V_1 , V_2 , 2 , V_8 ) ;
}
if ( V_6 )
* V_6 = V_8 ;
if ( V_7 )
* V_7 = V_9 ;
return V_2 + 2 ;
}
static int
F_4 ( T_1 * V_1 , int V_2 ,
T_3 * T_4 , T_5 * V_4 , T_7 * V_9 V_3 )
{
T_6 V_10 ;
T_8 V_11 ;
V_2 = F_5 ( V_1 , V_2 , T_4 , V_4 , V_12 , & V_10 ) ;
V_2 = F_6 ( V_1 , V_2 , T_4 , V_4 , V_13 , & V_11 ) ;
return V_2 ;
}
static int
F_7 ( T_1 * V_1 , int V_2 ,
T_3 * T_4 , T_5 * V_4 , T_7 * V_9 V_3 )
{
T_9 V_14 [ 6 ] ;
T_6 V_15 ;
T_6 V_16 ;
T_6 V_17 ;
T_7 * V_18 ;
V_2 = F_8 ( V_1 , V_2 , T_4 , V_4 , V_19 , V_14 ) ;
V_2 = F_5 ( V_1 , V_2 , T_4 , V_4 , V_20 , & V_15 ) ;
V_2 = F_1 ( V_1 , V_2 , T_4 , V_4 , V_21 , & V_16 , & V_18 ) ;
if ( V_4 )
{
F_9 ( V_18 , L_1 ) ;
if ( V_16 < 0x07D1 )
F_9 ( V_18 , L_2 ) ;
else
F_9 ( V_18 , L_3 ) ;
}
V_2 = F_1 ( V_1 , V_2 , T_4 , V_4 , V_22 , & V_17 , & V_18 ) ;
if ( V_4 )
{
if ( V_17 == 0 )
F_9 ( V_18 , L_4 ) ;
else
if ( V_17 == 1 )
F_9 ( V_18 , L_5 ) ;
else
F_9 ( V_18 , L_6 ) ;
}
V_2 = F_10 ( V_1 , V_2 , T_4 , V_4 ) ;
return V_2 ;
}
static const char * F_11 ( T_6 V_23 )
{
if ( V_23 == 0x0000 )
return ( L_7 ) ;
if ( ( V_23 >= 0x1000 ) && ( V_23 <= 0x7000 ) )
return ( L_8 ) ;
if ( V_23 == 0x8000 )
return ( L_9 ) ;
if ( ( V_23 >= 0x8001 ) && ( V_23 <= 0x8FFF ) )
return ( L_10 ) ;
if ( ( V_23 >= 0x9000 ) && ( V_23 <= 0x9FFF ) )
return ( L_11 ) ;
if ( V_23 == 0xA000 )
return ( L_12 ) ;
if ( ( V_23 >= 0xA001 ) && ( V_23 <= 0xF000 ) )
return ( L_13 ) ;
if ( V_23 == 0xFFFF )
return ( L_14 ) ;
return ( L_6 ) ;
}
static int
F_12 ( T_1 * V_1 , int V_2 ,
T_3 * T_4 , T_5 * V_4 , T_7 * V_9 V_3 )
{
T_6 V_23 ;
T_9 V_14 [ 6 ] ;
T_6 V_15 ;
T_6 V_24 ;
T_6 V_25 ;
T_10 V_26 ;
T_7 * V_18 ;
V_2 = F_1 ( V_1 , V_2 , T_4 , V_4 , V_27 , & V_23 , & V_18 ) ;
if ( V_4 )
F_9 ( V_18 , L_15 , F_11 ( V_23 ) ) ;
V_2 = F_8 ( V_1 , V_2 , T_4 , V_4 , V_19 , V_14 ) ;
V_2 = F_5 ( V_1 , V_2 , T_4 , V_4 , V_20 , & V_15 ) ;
V_2 = F_5 ( V_1 , V_2 , T_4 , V_4 , V_28 , & V_24 ) ;
V_2 = F_5 ( V_1 , V_2 , T_4 , V_4 , V_29 , & V_25 ) ;
V_2 = F_13 ( V_1 , V_2 , T_4 , V_4 , V_30 , & V_26 ) ;
V_2 = F_10 ( V_1 , V_2 , T_4 , V_4 ) ;
return V_2 ;
}
static int
F_14 ( T_1 * V_1 , int V_2 ,
T_3 * T_4 , T_5 * V_4 , T_7 * V_9 V_3 )
{
T_6 V_23 ;
T_9 V_14 [ 6 ] ;
T_6 V_16 ;
T_7 * V_18 ;
V_2 = F_1 ( V_1 , V_2 , T_4 , V_4 , V_27 , & V_23 , & V_18 ) ;
if ( V_4 )
F_9 ( V_18 , L_15 , F_11 ( V_23 ) ) ;
V_2 = F_8 ( V_1 , V_2 , T_4 , V_4 , V_19 , V_14 ) ;
V_2 = F_1 ( V_1 , V_2 , T_4 , V_4 , V_21 , & V_16 , & V_18 ) ;
if ( V_4 )
{
F_9 ( V_18 , L_16 ) ;
if ( V_16 < 0x07D1 )
F_9 ( V_18 , L_17 ) ;
else
F_9 ( V_18 , L_18 ) ;
}
return V_2 ;
}
static int
F_15 ( T_1 * V_1 , int V_2 , T_3 * T_4 V_3 ,
T_5 * V_4 , T_10 V_31 )
{
F_16 ( V_4 , V_32 , V_1 , V_2 , V_31 , L_19 ,
L_20 , V_31 ) ;
return V_2 + V_31 ;
}
static int
F_17 ( T_1 * V_1 , int V_2 ,
T_3 * T_4 , T_5 * V_4 , T_7 * V_9 , T_9 V_31 )
{
T_10 V_33 ;
V_2 = F_18 ( V_1 , V_2 , T_4 , V_4 , V_34 , & V_33 ) ;
V_31 -= 3 ;
switch ( V_33 )
{
case V_35 :
F_9 ( V_9 , L_21 ) ;
if ( V_31 != 0 ) {
V_2 = F_15 ( V_1 , V_2 , T_4 , V_4 , V_31 ) ;
}
F_19 ( T_4 -> V_36 , V_37 , L_22 ) ;
break;
default:
F_9 ( V_9 , L_23 ) ;
V_2 = F_20 ( V_1 , V_2 , T_4 , V_4 , V_31 ) ;
}
V_2 = F_10 ( V_1 , V_2 , T_4 , V_4 ) ;
return V_2 ;
}
static int
F_21 ( T_1 * V_1 , int V_2 ,
T_3 * T_4 , T_5 * V_4 , T_7 * V_9 )
{
T_6 V_38 ;
T_9 type ;
T_9 V_31 ;
T_2 V_39 ;
T_1 * V_40 ;
V_2 = F_5 ( V_1 , V_2 , T_4 , V_4 , V_41 , & V_38 ) ;
V_40 = F_22 ( V_1 , V_2 ) ;
V_2 = 0 ;
for( V_39 = 0 ; F_23 ( V_1 , V_2 ) > 0 ; V_39 ++ ) {
V_2 = F_24 ( V_40 , V_2 , T_4 , V_4 , V_42 , & type ) ;
V_2 = F_24 ( V_40 , V_2 , T_4 , V_4 , V_43 , & V_31 ) ;
if ( V_39 != 0 ) {
F_19 ( T_4 -> V_36 , V_37 , L_24 ) ;
F_9 ( V_9 , L_24 ) ;
} else {
F_9 ( V_9 , L_25 ) ;
}
F_25 ( T_4 -> V_36 , V_37 , L_15 , F_26 ( type , V_44 , L_26 ) ) ;
F_9 ( V_9 , L_15 , F_26 ( type , V_44 , L_26 ) ) ;
switch( type ) {
case 0x00 :
return V_2 ;
break;
case 0x01 :
V_2 = F_4 ( V_40 , V_2 , T_4 , V_4 , V_9 ) ;
break;
case 0x02 :
V_2 = F_12 ( V_40 , V_2 , T_4 , V_4 , V_9 ) ;
break;
case 0x03 :
V_2 = F_14 ( V_40 , V_2 , T_4 , V_4 , V_9 ) ;
break;
case 0x04 :
case 0x05 :
V_2 = F_7 ( V_40 , V_2 , T_4 , V_4 , V_9 ) ;
break;
case 0x7f :
V_2 = F_17 ( V_40 , V_2 , T_4 , V_4 , V_9 , V_31 ) ;
break;
default:
V_2 = F_20 ( V_1 , V_2 , T_4 , V_4 , V_31 ) ;
}
}
return V_2 ;
}
static void
F_27 ( T_1 * V_1 , T_3 * T_4 , T_5 * V_4 )
{
T_7 * V_45 = NULL ;
T_5 * V_46 = NULL ;
T_10 V_2 = 0 ;
F_28 ( T_4 -> V_36 , V_47 , L_27 ) ;
F_29 ( T_4 -> V_36 , V_37 ) ;
if ( V_4 )
{
V_45 = F_30 ( V_4 , V_48 , V_1 , V_2 , - 1 , V_49 ) ;
V_46 = F_31 ( V_45 , V_50 ) ;
}
F_21 ( V_1 , V_2 , T_4 , V_46 , V_45 ) ;
}
void
F_32 ( void )
{
static T_11 V_51 [] = {
{ & V_42 ,
{ L_28 , L_29 ,
V_52 , V_53 , F_33 ( V_44 ) , 0x0 ,
NULL , V_54 } } ,
{ & V_43 ,
{ L_30 , L_31 ,
V_52 , V_55 , NULL , 0x0 ,
NULL , V_54 } } ,
{ & V_41 ,
{ L_32 , L_33 ,
V_56 , V_55 , NULL , 0x0 ,
NULL , V_54 } } ,
{ & V_12 ,
{ L_34 , L_35 ,
V_56 , V_53 , NULL , 0x0 ,
L_36 , V_54 } } ,
{ & V_19 ,
{ L_37 , L_38 ,
V_57 , V_58 , 0x0 , 0x0 ,
NULL , V_54 } } ,
{ & V_27 ,
{ L_39 , L_40 ,
V_56 , V_53 , 0 , 0x0 ,
NULL , V_54 } } ,
{ & V_20 ,
{ L_41 , L_42 ,
V_56 , V_53 , F_33 ( V_59 ) , 0x0 ,
NULL , V_54 } } ,
{ & V_28 ,
{ L_43 , L_44 ,
V_56 , V_53 , F_33 ( V_60 ) , 0x0 ,
NULL , V_54 } } ,
{ & V_21 ,
{ L_45 , L_46 ,
V_56 , V_55 , NULL , 0x0 ,
L_47 , V_54 } } ,
{ & V_29 ,
{ L_48 , L_49 ,
V_56 , V_53 , NULL , 0x0 ,
L_50 , V_54 } } ,
{ & V_30 ,
{ L_51 , L_52 ,
V_61 , V_53 , NULL , 0x0 ,
L_53 , V_54 } } ,
{ & V_22 ,
{ L_54 , L_55 ,
V_56 , V_53 , NULL , 0x0 ,
NULL , V_54 } } ,
{ & V_32 ,
{ L_56 , L_57 ,
V_62 , V_58 , NULL , 0x0 ,
NULL , V_54 } } ,
{ & V_13 ,
{ L_58 , L_59 ,
V_63 , V_58 , NULL , 0x0 ,
NULL , V_54 } } ,
{ & V_34 ,
{ L_60 , L_61 ,
V_64 , V_53 , F_33 ( V_65 ) , 0x0 ,
NULL , V_54 } } ,
} ;
static T_2 * V_66 [] = {
& V_50
} ;
V_48 = F_34 ( L_62 , L_27 , L_63 ) ;
F_35 ( V_48 , V_51 , F_36 ( V_51 ) ) ;
F_37 ( V_66 , F_36 ( V_66 ) ) ;
}
void
F_38 ( void )
{
T_12 V_67 ;
V_67 = F_39 ( F_27 , V_48 ) ;
F_40 ( L_64 , V_68 , V_67 ) ;
}
