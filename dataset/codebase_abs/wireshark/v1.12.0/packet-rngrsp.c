static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 ;
T_3 * V_5 ;
T_5 V_6 , V_7 ;
int V_8 ;
T_6 V_9 ;
T_5 V_10 ;
T_7 V_11 ;
T_8 V_12 ;
T_9 V_13 ;
V_11 = F_2 ( V_1 , 0 ) ;
V_10 = F_3 ( V_1 , 2 ) ;
if ( V_10 > 0 )
F_4 ( V_2 -> V_14 , V_15 ,
L_1 ,
V_11 , V_10 , V_10 - 1 ) ;
else
F_4 ( V_2 -> V_14 , V_15 ,
L_2 , V_11 ) ;
if ( V_3 )
{
V_4 =
F_5 ( V_3 , V_16 , V_1 , 0 , - 1 ,
L_3 ) ;
V_5 = F_6 ( V_4 , V_17 ) ;
F_7 ( V_5 , V_18 , V_1 , 0 , 2 ,
V_19 ) ;
F_7 ( V_5 , V_20 , V_1 ,
2 , 1 , V_19 ) ;
V_9 = F_8 ( V_1 , 0 ) ;
V_8 = 3 ;
while ( V_8 < V_9 )
{
V_6 = F_3 ( V_1 , V_8 ++ ) ;
V_7 = F_3 ( V_1 , V_8 ++ ) ;
switch ( V_6 )
{
case V_21 :
if ( V_7 == 4 )
{
V_13 = F_9 ( V_1 , V_8 ) ;
F_10 ( V_5 ,
V_22 , V_1 , V_8 ,
V_7 , V_13 ) ;
}
else
{
F_11 ( V_23 ) ;
}
break;
case V_24 :
if ( V_7 == 1 )
{
V_12 = F_3 ( V_1 , V_8 ) ;
F_10 ( V_5 , V_25 ,
V_1 , V_8 , V_7 , V_12 ) ;
}
else
{
F_11 ( V_23 ) ;
}
break;
case V_26 :
if ( V_7 == 2 )
{
F_7 ( V_5 , V_27 ,
V_1 , V_8 , V_7 , V_19 ) ;
}
else
{
F_11 ( V_23 ) ;
}
break;
case V_28 :
F_7 ( V_5 , V_29 ,
V_1 , V_8 , V_7 , V_30 ) ;
break;
case V_31 :
if ( V_7 == 1 )
F_7 ( V_5 ,
V_32 , V_1 ,
V_8 , V_7 , V_19 ) ;
else
{
F_11 ( V_23 ) ;
}
break;
case V_33 :
if ( V_7 == 4 )
F_7 ( V_5 ,
V_34 , V_1 ,
V_8 , V_7 , V_19 ) ;
else
{
F_11 ( V_23 ) ;
}
break;
case V_35 :
if ( V_7 == 1 )
F_7 ( V_5 ,
V_36 , V_1 ,
V_8 , V_7 , V_19 ) ;
else
{
F_11 ( V_23 ) ;
}
break;
}
V_8 = V_8 + V_7 ;
}
}
}
void
F_12 ( void )
{
static T_10 V_37 [] = {
{ & V_18 ,
{ L_4 , L_5 ,
V_38 , V_39 , NULL , 0x0 ,
NULL , V_40 }
} ,
{ & V_20 ,
{ L_6 , L_7 ,
V_41 , V_39 , NULL , 0x0 ,
NULL , V_40 }
} ,
{ & V_22 ,
{ L_8 , L_9 ,
V_42 , V_39 , NULL , 0x0 ,
L_10 , V_40 }
} ,
{ & V_25 ,
{ L_11 , L_12 ,
V_43 , V_39 , NULL , 0x0 ,
L_13 , V_40 }
} ,
{ & V_27 ,
{ L_14 , L_15 ,
V_44 , V_39 , NULL , 0x0 ,
L_16 , V_40 }
} ,
{ & V_29 ,
{ L_17 , L_18 ,
V_45 , V_46 , NULL , 0x0 ,
L_19 , V_40 }
} ,
{ & V_32 ,
{ L_20 , L_21 ,
V_41 , V_39 , F_13 ( V_47 ) , 0x0 ,
NULL , V_40 }
} ,
{ & V_34 ,
{ L_22 , L_23 ,
V_48 , V_39 , NULL , 0x0 ,
L_24 , V_40 }
} ,
{ & V_36 ,
{ L_25 , L_26 ,
V_41 , V_39 , NULL , 0x0 ,
NULL , V_40 }
} ,
} ;
static T_6 * V_49 [] = {
& V_17 ,
} ;
V_16 = F_14 ( L_27 ,
L_28 ,
L_29 ) ;
F_15 ( V_16 , V_37 , F_16 ( V_37 ) ) ;
F_17 ( V_49 , F_16 ( V_49 ) ) ;
F_18 ( L_29 , F_1 , V_16 ) ;
}
void
F_19 ( void )
{
T_11 V_50 ;
V_50 = F_20 ( L_29 ) ;
F_21 ( L_30 , 0x05 , V_50 ) ;
}
