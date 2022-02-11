static void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_3 V_4 )
{
T_4 type , V_5 ;
T_2 * V_6 ;
int V_7 = V_3 ;
V_6 =
F_2 ( V_2 , V_1 , V_3 , V_4 , V_8 , NULL ,
L_1 , V_4 ) ;
while ( V_7 < ( V_3 + V_4 ) )
{
type = F_3 ( V_1 , V_7 ++ ) ;
V_5 = F_3 ( V_1 , V_7 ++ ) ;
switch ( type )
{
case V_9 :
if ( V_5 == 1 )
{
F_4 ( V_6 , V_10 ,
V_1 , V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_13 :
if ( V_5 == 2 )
{
F_4 ( V_6 , V_14 ,
V_1 , V_7 , V_5 , V_15 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
}
V_7 = V_7 + V_5 ;
}
}
static void
F_6 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_3 V_4 )
{
T_4 type , V_5 ;
T_2 * V_6 ;
int V_7 = V_3 ;
V_6 =
F_2 ( V_2 , V_1 , V_3 , V_4 , V_16 , NULL ,
L_2 , V_4 ) ;
while ( V_7 < ( V_3 + V_4 ) )
{
type = F_3 ( V_1 , V_7 ++ ) ;
V_5 = F_3 ( V_1 , V_7 ++ ) ;
switch ( type )
{
case V_17 :
if ( V_5 == 1 )
{
F_4 ( V_6 , V_18 ,
V_1 , V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_19 :
if ( V_5 == 2 )
{
F_4 ( V_6 , V_20 ,
V_1 , V_7 , V_5 , V_15 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
}
V_7 = V_7 + V_5 ;
}
}
static int
F_7 ( T_1 * V_1 , T_5 * T_6 V_21 , T_2 * V_2 , void * T_7 V_21 )
{
T_8 * V_22 ;
T_2 * V_23 ;
int V_7 = 0 ;
T_9 V_24 ;
T_4 type , V_5 ;
V_24 = F_8 ( V_1 , 0 ) ;
V_22 =
F_9 ( V_2 , V_25 , V_1 , 0 ,
V_24 , L_3 ) ;
V_23 = F_10 ( V_22 , V_26 ) ;
while ( V_7 < V_24 )
{
type = F_3 ( V_1 , V_7 ++ ) ;
V_5 = F_3 ( V_1 , V_7 ++ ) ;
switch ( type )
{
case V_27 :
if ( V_5 == 1 )
{
F_4 ( V_23 , V_28 ,
V_1 , V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_29 :
if ( V_5 == 4 || V_5 == 1 )
{
F_4 ( V_23 , V_30 ,
V_1 , V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_31 :
if ( V_5 == 1 )
{
F_4 ( V_23 , V_32 ,
V_1 , V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_33 :
if ( V_5 == 1 )
{
F_4 ( V_23 , V_34 ,
V_1 , V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_35 :
if ( V_5 == 1 )
F_4 ( V_23 , V_36 ,
V_1 , V_7 , V_5 , V_15 ) ;
else
F_1 ( V_1 , V_23 , V_7 , V_5 ) ;
break;
case V_37 :
if ( V_5 == 1 )
F_4 ( V_23 , V_36 ,
V_1 , V_7 , V_5 , V_15 ) ;
else
F_6 ( V_1 , V_23 , V_7 , V_5 ) ;
break;
case V_38 :
if ( V_5 == 2 || V_5 == 1 )
{
F_4 ( V_23 , V_39 ,
V_1 , V_7 , V_5 , V_15 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
}
V_7 = V_7 + V_5 ;
}
return F_11 ( V_1 ) ;
}
void
F_12 ( void )
{
static T_10 V_40 [] = {
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
{ & V_10 ,
{ L_19 , L_20 ,
V_41 , V_42 , NULL , 0x0 ,
L_21 , V_43 }
} ,
{ & V_14 ,
{ L_22 , L_23 ,
V_45 , V_46 , NULL , 0x0 ,
L_24 , V_43 }
} ,
#if 0
{&hf_cmctrl_tlv_us_event,
{"6 Override Upstream Events", "cmctrl_tlv.us_event",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Override Downstream Events", HFILL}
},
#endif
{ & V_18 ,
{ L_25 , L_26 ,
V_41 , V_42 , NULL , 0x0 ,
L_27 , V_43 }
} ,
{ & V_20 ,
{ L_28 , L_29 ,
V_45 , V_46 , NULL , 0x0 ,
L_30 , V_43 }
} ,
{ & V_39 ,
{ L_31 , L_32 ,
V_45 , V_46 , NULL , 0x0 ,
L_33 , V_43 }
} ,
} ;
static T_9 * V_47 [] = {
& V_26 ,
& V_8 ,
& V_16 ,
} ;
V_25 = F_13 ( L_34 ,
L_35 , L_36 ) ;
F_14 ( V_25 , V_40 , F_15 ( V_40 ) ) ;
F_16 ( V_47 , F_15 ( V_47 ) ) ;
F_17 ( L_36 , F_7 , V_25 ) ;
}
void
F_18 ( void )
{
#if 0
dissector_handle_t cmctrl_tlv_handle;
cmctrl_tlv_handle = find_dissector ("cmctrl_tlv");
dissector_add_uint ("docsis", 0xFE, cmctrl_tlv_handle);
#endif
}
