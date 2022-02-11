static int F_1 ( T_1 * T_2 V_1 , T_3 T_4 V_1 , T_5 * T_6 V_1 , T_7 * V_2 )
{
int V_3 = 0 ;
int V_4 ;
T_1 * V_5 ;
T_3 V_6 , V_7 ;
T_8 * V_8 = F_2 ( T_2 , V_9 ) ;
F_3 ( V_8 , V_10 , T_6 , V_3 , 2 , V_11 ) ;
V_3 += 2 ;
F_3 ( V_8 , V_12 , T_6 , V_3 , 4 , V_11 ) ;
V_3 += 4 ;
F_3 ( V_8 , V_13 , T_6 , V_3 , 2 , V_11 ) ;
V_6 = F_4 ( T_6 , V_3 ) ;
V_3 += 2 ;
F_3 ( V_8 , V_14 , T_6 , V_3 , 2 , V_11 ) ;
V_3 += 2 ;
switch( V_6 ) {
case V_15 : return V_3 ;
case V_16 : return V_3 ;
case V_17 :
break;
case V_18 :
F_3 ( V_8 , V_19 , T_6 , V_3 , 1 , V_11 ) ;
return V_3 + 1 ;
case V_20 :
case V_21 :
V_7 = F_4 ( T_6 , V_3 ) ;
V_5 = F_3 ( V_8 , V_22 , T_6 , V_3 , 2 , V_11 ) ; V_3 += 2 ;
for( V_4 = 0 ; V_23 [ V_4 ] . V_24 ; V_4 ++ ) {
if( V_23 [ V_4 ] . T_4 == V_7 ) break;
}
F_5 ( V_2 -> V_25 , V_26 , V_23 [ V_4 ] . V_24 ? V_23 [ V_4 ] . V_24 : L_1 ) ;
F_6 ( V_5 , L_2 , V_23 [ V_4 ] . V_24 ? V_23 [ V_4 ] . V_24 : L_3 ) ;
if( V_23 [ V_4 ] . V_27 )
return V_23 [ V_4 ] . V_27 ( F_7 ( T_6 , V_3 ) , V_2 , V_8 ) ;
default:
break;
}
return V_3 ;
}
static int F_8 ( T_5 * T_6 , T_7 * V_2 , T_8 * V_28 )
{
return F_9 ( T_6 , V_2 , 0 , V_28 , V_29 ) ;
}
void
F_10 ( void )
{
static T_9 V_30 [] = {
{ & V_10 ,
{ L_4 , L_5 , V_31 , V_32 , NULL , 0x0 , NULL , V_33 } ,
} ,
{ & V_12 ,
{ L_6 , L_7 , V_34 , V_32 , NULL , 0x0 , NULL , V_33 } ,
} ,
{ & V_13 ,
{ L_8 , L_9 , V_31 , V_32 , F_11 ( V_35 ) , 0x0 , NULL , V_33 } ,
} ,
{ & V_14 ,
{ L_10 , L_11 , V_31 , V_32 , NULL , 0x0 , NULL , V_33 } ,
} ,
{ & V_19 ,
{ L_12 , L_13 , V_36 , V_32 , NULL , 0x0 , NULL , V_33 } ,
} ,
{ & V_22 ,
{ L_14 , L_15 , V_31 , V_37 , NULL , 0x0 , NULL , V_33 } ,
} ,
} ;
static T_10 * V_38 [] = {
& V_39 ,
& V_9
} ;
V_40 = F_12 ( L_16 , L_16 , L_17 ) ;
F_13 ( V_40 , V_30 , F_14 ( V_30 ) ) ;
F_15 ( V_38 , F_14 ( V_38 ) ) ;
}
void
F_16 ( void )
{
F_17 ( V_40 , V_39 , V_41 , V_42 ) ;
}
