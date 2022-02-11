static int F_1 ( T_1 * V_1 , T_2 T_3 V_2 , T_4 * V_3 , T_5 * V_4 )
{
int V_5 = 0 ;
int V_6 ;
T_1 * V_7 ;
T_2 V_8 , V_9 ;
T_6 * V_10 = F_2 ( V_1 , V_11 ) ;
F_3 ( V_10 , V_12 , V_3 , V_5 , 2 , V_13 ) ;
V_5 += 2 ;
F_3 ( V_10 , V_14 , V_3 , V_5 , 4 , V_13 ) ;
V_5 += 4 ;
F_3 ( V_10 , V_15 , V_3 , V_5 , 2 , V_13 ) ;
V_8 = F_4 ( V_3 , V_5 ) ;
V_5 += 2 ;
F_3 ( V_10 , V_16 , V_3 , V_5 , 2 , V_13 ) ;
V_5 += 2 ;
switch ( V_8 ) {
case V_17 : return V_5 ;
case V_18 : return V_5 ;
case V_19 :
break;
case V_20 :
F_3 ( V_10 , V_21 , V_3 , V_5 , 1 , V_13 ) ;
return V_5 + 1 ;
case V_22 :
case V_23 :
V_9 = F_4 ( V_3 , V_5 ) ;
V_7 = F_3 ( V_10 , V_24 , V_3 , V_5 , 2 , V_13 ) ; V_5 += 2 ;
for ( V_6 = 0 ; V_25 [ V_6 ] . V_26 ; V_6 ++ ) {
if ( V_25 [ V_6 ] . T_3 == V_9 ) break;
}
F_5 ( V_4 -> V_27 , V_28 , V_25 [ V_6 ] . V_26 ? V_25 [ V_6 ] . V_26 : L_1 ) ;
F_6 ( V_7 , L_2 , V_25 [ V_6 ] . V_26 ? V_25 [ V_6 ] . V_26 : L_3 ) ;
if ( V_25 [ V_6 ] . V_29 )
return V_25 [ V_6 ] . V_29 ( F_7 ( V_3 , V_5 ) , V_4 , V_10 ) ;
default:
break;
}
return V_5 ;
}
static int F_8 ( T_4 * V_3 , T_5 * V_4 , T_6 * V_30 )
{
return F_9 ( V_3 , V_4 , 0 , V_30 , V_31 ) ;
}
void
F_10 ( void )
{
static T_7 V_32 [] = {
{ & V_12 ,
{ L_4 , L_5 , V_33 , V_34 , NULL , 0x0 , NULL , V_35 } ,
} ,
{ & V_14 ,
{ L_6 , L_7 , V_36 , V_34 , NULL , 0x0 , NULL , V_35 } ,
} ,
{ & V_15 ,
{ L_8 , L_9 , V_33 , V_34 , F_11 ( V_37 ) , 0x0 , NULL , V_35 } ,
} ,
{ & V_16 ,
{ L_10 , L_11 , V_33 , V_34 , NULL , 0x0 , NULL , V_35 } ,
} ,
{ & V_21 ,
{ L_12 , L_13 , V_38 , V_34 , NULL , 0x0 , NULL , V_35 } ,
} ,
{ & V_24 ,
{ L_14 , L_15 , V_33 , V_39 , NULL , 0x0 , NULL , V_35 } ,
} ,
} ;
static T_8 * V_40 [] = {
& V_41 ,
& V_11
} ;
V_42 = F_12 ( L_16 , L_16 , L_17 ) ;
F_13 ( V_42 , V_32 , F_14 ( V_32 ) ) ;
F_15 ( V_40 , F_14 ( V_40 ) ) ;
}
void
F_16 ( void )
{
F_17 ( V_42 , V_41 , V_43 , V_44 ) ;
}
