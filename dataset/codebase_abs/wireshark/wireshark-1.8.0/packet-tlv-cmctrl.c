static void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_3 V_4 )
{
T_4 type , V_5 ;
T_5 * V_6 ;
T_2 * V_7 ;
int V_8 = V_3 ;
V_6 =
F_2 ( V_2 , V_1 , V_3 , V_4 ,
L_1 , V_4 ) ;
V_7 = F_3 ( V_6 , V_9 ) ;
while ( V_8 < ( V_3 + V_4 ) )
{
type = F_4 ( V_1 , V_8 ++ ) ;
V_5 = F_4 ( V_1 , V_8 ++ ) ;
switch ( type )
{
case V_10 :
if ( V_5 == 1 )
{
F_5 ( V_7 , V_11 ,
V_1 , V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_14 :
if ( V_5 == 2 )
{
F_5 ( V_7 , V_15 ,
V_1 , V_8 , V_5 , V_16 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
}
V_8 = V_8 + V_5 ;
}
}
static void
F_7 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_3 V_4 )
{
T_4 type , V_5 ;
T_5 * V_6 ;
T_2 * V_7 ;
int V_8 = V_3 ;
V_6 =
F_2 ( V_2 , V_1 , V_3 , V_4 ,
L_2 , V_4 ) ;
V_7 = F_3 ( V_6 , V_17 ) ;
while ( V_8 < ( V_3 + V_4 ) )
{
type = F_4 ( V_1 , V_8 ++ ) ;
V_5 = F_4 ( V_1 , V_8 ++ ) ;
switch ( type )
{
case V_18 :
if ( V_5 == 1 )
{
F_5 ( V_7 , V_19 ,
V_1 , V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_20 :
if ( V_5 == 2 )
{
F_5 ( V_7 , V_21 ,
V_1 , V_8 , V_5 , V_16 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
}
V_8 = V_8 + V_5 ;
}
}
static void
F_8 ( T_1 * V_1 , T_6 * T_7 V_22 , T_2 * V_2 )
{
T_5 * V_6 ;
T_2 * V_23 ;
int V_8 = 0 ;
T_8 V_24 ;
T_4 type , V_5 ;
V_24 = F_9 ( V_1 , 0 ) ;
V_6 =
F_10 ( V_2 , V_25 , V_1 , 0 ,
V_24 , L_3 ) ;
V_23 = F_3 ( V_6 , V_26 ) ;
while ( V_8 < V_24 )
{
type = F_4 ( V_1 , V_8 ++ ) ;
V_5 = F_4 ( V_1 , V_8 ++ ) ;
switch ( type )
{
case V_27 :
if ( V_5 == 1 )
{
F_5 ( V_23 , V_28 ,
V_1 , V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_29 :
if ( V_5 == 4 || V_5 == 1 )
{
F_5 ( V_23 , V_30 ,
V_1 , V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_31 :
if ( V_5 == 1 )
{
F_5 ( V_23 , V_32 ,
V_1 , V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_33 :
if ( V_5 == 1 )
{
F_5 ( V_23 , V_34 ,
V_1 , V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_35 :
if ( V_5 == 1 )
F_5 ( V_23 , V_36 ,
V_1 , V_8 , V_5 , V_16 ) ;
else
F_1 ( V_1 , V_23 , V_8 , V_5 ) ;
break;
case V_37 :
if ( V_5 == 1 )
F_5 ( V_23 , V_36 ,
V_1 , V_8 , V_5 , V_16 ) ;
else
F_7 ( V_1 , V_23 , V_8 , V_5 ) ;
break;
case V_38 :
if ( V_5 == 2 || V_5 == 1 )
{
F_5 ( V_23 , V_39 ,
V_1 , V_8 , V_5 , V_16 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
}
V_8 = V_8 + V_5 ;
}
}
void
F_11 ( void )
{
static T_9 V_40 [] = {
{ & V_28 ,
{ L_4 , L_5 ,
V_41 , V_42 , NULL , 0x0 ,
L_6 , V_43 }
} ,
{ & V_30 ,
{ L_7 , L_8 ,
V_44 , V_42 , NULL , 0x0 ,
L_9 , V_43 }
} ,
{ & V_32 ,
{ L_10 , L_11 ,
V_41 , V_42 , NULL , 0x0 ,
L_12 , V_43 }
} ,
{ & V_34 ,
{ L_13 , L_14 ,
V_41 , V_42 , NULL , 0x0 ,
L_15 , V_43 }
} ,
{ & V_36 ,
{ L_16 , L_17 ,
V_45 , V_46 , NULL , 0x0 ,
L_18 , V_43 }
} ,
{ & V_11 ,
{ L_19 , L_20 ,
V_41 , V_42 , NULL , 0x0 ,
L_21 , V_43 }
} ,
{ & V_15 ,
{ L_22 , L_23 ,
V_45 , V_46 , NULL , 0x0 ,
L_24 , V_43 }
} ,
{ & V_47 ,
{ L_25 , L_26 ,
V_45 , V_46 , NULL , 0x0 ,
L_18 , V_43 }
} ,
{ & V_19 ,
{ L_27 , L_28 ,
V_41 , V_42 , NULL , 0x0 ,
L_29 , V_43 }
} ,
{ & V_21 ,
{ L_30 , L_31 ,
V_45 , V_46 , NULL , 0x0 ,
L_32 , V_43 }
} ,
{ & V_39 ,
{ L_33 , L_34 ,
V_45 , V_46 , NULL , 0x0 ,
L_35 , V_43 }
} ,
} ;
static T_8 * V_48 [] = {
& V_26 ,
& V_9 ,
& V_17 ,
} ;
V_25 = F_12 ( L_36 ,
L_37 , L_38 ) ;
F_13 ( V_25 , V_40 , F_14 ( V_40 ) ) ;
F_15 ( V_48 , F_14 ( V_48 ) ) ;
F_16 ( L_38 , F_8 , V_25 ) ;
}
void
F_17 ( void )
{
#if 0
dissector_handle_t cmctrl_tlv_handle;
cmctrl_tlv_handle = find_dissector ("cmctrl_tlv");
dissector_add_uint ("docsis", 0xFE, cmctrl_tlv_handle);
#endif
}
