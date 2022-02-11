static int
F_1 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 , T_4 * V_5 , T_5 T_6 V_6 )
{
T_7 V_7 ;
T_8 V_8 ;
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_9 , & V_7 ) ;
V_2 = F_3 ( V_1 , V_2 , V_3 , V_4 , V_10 , & V_8 ) ;
F_4 ( V_3 -> V_11 , V_12 , L_1 ) ;
F_5 ( V_5 , L_1 ) ;
return V_2 ;
}
static int
F_6 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 , T_4 * V_5 , T_5 T_6 V_6 )
{
T_5 V_13 [ 6 ] ;
V_2 = F_7 ( V_1 , V_2 , V_3 , V_4 , V_14 , V_13 ) ;
V_2 = F_8 ( V_1 , V_2 , V_3 , V_4 ) ;
F_4 ( V_3 -> V_11 , V_12 , L_2 ) ;
F_5 ( V_5 , L_2 ) ;
return V_2 ;
}
static int
F_9 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 , T_4 * V_5 )
{
T_7 V_15 ;
T_5 type ;
T_5 T_6 ;
T_9 V_16 = 0 ;
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_17 , & V_15 ) ;
while ( F_10 ( V_1 , V_2 ) > 0 ) {
V_2 = F_11 ( V_1 , V_2 , V_3 , V_4 , V_18 , & type ) ;
V_2 = F_11 ( V_1 , V_2 , V_3 , V_4 , V_19 , & T_6 ) ;
if ( V_16 != 0 ) {
F_4 ( V_3 -> V_11 , V_12 , L_3 ) ;
F_5 ( V_5 , L_3 ) ;
}
V_16 ++ ;
switch( type ) {
case 0x00 :
F_4 ( V_3 -> V_11 , V_12 , L_4 ) ;
F_5 ( V_5 , L_4 ) ;
return V_2 ;
break;
case 0x01 :
V_2 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , T_6 ) ;
break;
case 0x02 :
V_2 = F_6 ( V_1 , V_2 , V_3 , V_4 , V_5 , T_6 ) ;
break;
default:
V_2 = F_12 ( V_1 , V_2 , V_3 , V_4 , T_6 ) ;
F_13 ( V_3 -> V_11 , V_12 , L_5 , type ) ;
F_5 ( V_5 , L_5 , type ) ;
break;
}
}
return V_2 ;
}
static T_10
F_14 ( T_1 * V_1 , T_2 * V_3 , T_3 * V_4 ,
void * V_20 )
{
T_7 V_21 = F_15 ( V_20 ) ;
T_4 * V_5 ;
T_3 * V_22 ;
int V_2 = 0 ;
T_11 V_23 ;
if ( V_21 != 0xFF60 ) {
return FALSE ;
}
F_16 ( V_3 -> V_11 , V_24 , L_6 ) ;
F_17 ( V_3 -> V_11 , V_12 ) ;
V_5 = F_18 ( V_4 , V_25 , V_1 , 0 , 0 , L_7 ) ;
V_22 = F_19 ( V_5 , V_26 ) ;
V_23 = V_2 ;
V_2 = F_9 ( V_1 , V_2 , V_3 , V_22 , V_5 ) ;
F_20 ( V_5 , V_2 - V_23 ) ;
return TRUE ;
}
void
F_21 ( void )
{
static T_12 V_27 [] = {
{ & V_18 ,
{ L_8 , L_9 ,
V_28 , V_29 , F_22 ( V_30 ) , 0x0 ,
NULL , V_31 } } ,
{ & V_19 ,
{ L_10 , L_11 ,
V_28 , V_32 , NULL , 0x0 ,
NULL , V_31 } } ,
{ & V_17 ,
{ L_12 , L_13 ,
V_33 , V_32 , NULL , 0x0 ,
NULL , V_31 } } ,
{ & V_9 ,
{ L_14 , L_15 ,
V_33 , V_29 , NULL , 0x0 ,
L_16 , V_31 } } ,
{ & V_14 ,
{ L_17 , L_18 ,
V_34 , V_35 , 0x0 , 0x0 ,
NULL , V_31 } } ,
{ & V_10 ,
{ L_19 , L_20 ,
V_36 , V_35 , NULL , 0x0 ,
NULL , V_31 } } ,
} ;
static T_9 * V_37 [] = {
& V_26
} ;
V_25 = F_23 ( L_21 , L_6 , L_22 ) ;
F_24 ( V_25 , V_27 , F_25 ( V_27 ) ) ;
F_26 ( V_37 , F_25 ( V_37 ) ) ;
}
void
F_27 ( void )
{
F_28 ( L_23 , F_14 , L_24 , L_25 , V_25 , V_38 ) ;
}
