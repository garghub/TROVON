static int F_1 ( T_1 * V_1 , int V_2 )
{
T_2 V_3 = 2 + F_2 ( V_1 , V_2 ) + 2 * 3 ;
V_3 += F_2 ( V_1 , V_2 + V_3 ) + 2 ;
return V_3 ;
}
static int F_3 ( T_1 * V_1 , T_3 * T_4 V_4 , int V_2 , T_5 * V_5 )
{
T_6 V_6 = 0 ;
int V_7 ;
T_6 V_8 = 0 ;
V_6 = F_2 ( V_1 , V_2 ) ;
F_4 ( V_5 , V_9 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
if ( V_6 > 0 ) {
F_4 ( V_5 , V_11 , V_1 , V_2 , V_6 , V_12 | V_13 ) ;
V_2 += V_6 ;
}
F_4 ( V_5 , V_14 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
F_4 ( V_5 , V_15 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
F_4 ( V_5 , V_16 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
V_8 = F_2 ( V_1 , V_2 ) ;
F_4 ( V_5 , V_17 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
V_7 = V_2 ;
while( V_7 < V_2 + V_8 ) {
V_7 = F_5 ( V_1 , T_4 , V_7 , V_5 , V_18 ) ;
}
return V_7 ;
}
static int F_6 ( T_1 * V_1 , T_3 * T_4 , T_5 * V_5 )
{
return F_3 ( V_1 , T_4 , 0 , V_5 ) ;
}
static int F_7 ( T_1 * V_1 , T_3 * T_4 , T_5 * V_19 )
{
int V_2 = 0 ;
T_2 V_3 ;
T_5 * V_5 = NULL ;
int V_20 = F_8 ( V_1 ) ;
while ( V_20 > V_2 )
{
V_3 = F_1 ( V_1 , V_2 ) ;
V_5 = F_9 ( V_19 , V_1 , V_2 , V_3 , V_21 , NULL , L_1 ) ;
V_2 = F_3 ( V_1 , T_4 , V_2 , V_5 ) ;
}
return V_2 ;
}
static int F_10 ( T_1 * V_1 , T_3 * T_4 , T_5 * V_22 )
{
return F_11 ( V_1 , T_4 , 0 , V_22 , V_23 ) ;
}
static int F_12 ( T_1 * V_1 , T_3 * T_4 , T_5 * V_22 )
{
return F_13 ( V_1 , T_4 , 0 , V_22 ) ;
}
static int F_14 ( T_1 * V_1 , T_3 * T_4 V_4 , T_5 * V_19 )
{
int V_2 = 0 ;
T_7 V_24 ;
V_24 . V_25 = F_15 ( V_1 , V_2 ) ;
V_24 . V_26 = 0 ;
F_16 ( V_19 , V_27 , V_1 , V_2 , 4 , & V_24 ) ;
V_2 += 4 ;
F_4 ( V_19 , V_28 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
return V_2 ;
}
static int F_17 ( T_1 * V_1 , T_3 * T_4 V_4 , T_5 * V_19 )
{
int V_2 = 0 ;
T_5 * V_5 = NULL ;
T_6 V_29 , V_30 ;
T_7 V_24 ;
T_2 V_3 ;
F_4 ( V_19 , V_31 , V_1 , V_2 , 1 , V_10 ) ;
V_2 += 1 ;
F_4 ( V_19 , V_28 , V_1 , V_2 , 2 , V_10 ) ;
V_29 = F_2 ( V_1 , V_2 ) ;
V_2 += 2 ;
for( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
V_3 = F_1 ( V_1 , V_2 ) ;
V_5 = F_18 ( V_19 , V_1 , V_2 , V_3 ,
V_21 , NULL , L_2 , V_30 ) ;
V_2 = F_3 ( V_1 , T_4 , V_2 , V_5 ) ;
}
V_24 . V_25 = F_15 ( V_1 , V_2 ) ;
V_24 . V_26 = 0 ;
F_16 ( V_19 , V_27 , V_1 , V_2 , 4 , & V_24 ) ;
return V_2 ;
}
static int F_19 ( T_1 * V_1 , T_3 * T_4 V_4 , T_5 * V_19 )
{
int V_2 = 0 ;
T_6 V_32 ;
T_8 V_6 = F_20 ( V_1 , V_2 ) ;
F_4 ( V_19 , V_33 , V_1 , V_2 , 1 , V_10 ) ;
V_2 += 1 ;
if ( V_6 > 0 ) {
F_4 ( V_19 , V_11 , V_1 , V_2 , V_6 , V_12 | V_13 ) ;
V_2 += V_6 ;
}
V_32 = F_2 ( V_1 , V_2 ) ;
F_4 ( V_19 , V_34 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
if ( V_32 > 0 ) {
F_4 ( V_19 , V_35 , V_1 , V_2 , V_32 , V_12 | V_13 ) ;
V_2 += V_32 ;
}
F_4 ( V_19 , V_36 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
return V_2 ;
}
static int F_21 ( T_1 * V_1 , T_3 * T_4 V_4 , T_5 * V_19 )
{
int V_2 = 0 ;
T_6 V_32 ;
T_8 V_6 = F_20 ( V_1 , V_2 ) ;
F_4 ( V_19 , V_33 , V_1 , V_2 , 1 , V_10 ) ;
V_2 += 1 ;
if ( V_6 > 0 ) {
F_4 ( V_19 , V_11 , V_1 , V_2 , V_6 , V_12 | V_13 ) ;
V_2 += V_6 ;
}
F_4 ( V_19 , V_37 , V_1 , V_2 , 1 , V_10 ) ;
V_2 += 1 ;
V_32 = F_2 ( V_1 , V_2 ) ;
F_4 ( V_19 , V_34 , V_1 , V_2 , 2 , V_10 ) ;
V_2 += 2 ;
if ( V_32 > 0 ) {
F_4 ( V_19 , V_35 , V_1 , V_2 , V_32 , V_12 | V_13 ) ;
V_2 += V_32 ;
}
return V_2 ;
}
void
F_22 ( void )
{
static T_9 V_38 [] = {
{ & V_31 ,
{ L_3 , L_4 , V_39 , V_40 , NULL , 0x0 , NULL , V_41 }
} ,
{ & V_28 ,
{ L_5 , L_6 , V_42 , V_40 , NULL , 0x0 , NULL , V_41 }
} ,
{ & V_27 ,
{ L_7 , L_8 , V_43 , V_44 , NULL , 0x0 , NULL , V_41 }
} ,
{ & V_9 ,
{ L_9 , L_10 , V_42 , V_40 , NULL , 0x0 , NULL , V_41 }
} ,
{ & V_11 ,
{ L_11 , L_12 , V_45 , V_46 , NULL , 0x0 , NULL , V_41 }
} ,
{ & V_14 ,
{ L_13 , L_14 , V_42 , V_40 , NULL , 0x0 , NULL , V_41 }
} ,
{ & V_15 ,
{ L_15 , L_16 , V_42 , V_40 , NULL , 0x0 , NULL , V_41 }
} ,
{ & V_16 ,
{ L_17 , L_18 , V_42 , V_40 , F_23 ( V_47 ) , 0x0 , NULL , V_41 }
} ,
{ & V_17 ,
{ L_19 , L_20 , V_42 , V_40 , NULL , 0x0 , NULL , V_41 }
} ,
#if 0
{ &hf_aim_fnac_subtype_ssi_data,
{ "SSI Buddy Data", "aim_ssi.fnac.data", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
#endif
{ & V_33 ,
{ L_9 , L_21 , V_39 , V_40 , NULL , 0x0 , NULL , V_41 }
} ,
{ & V_34 ,
{ L_22 , L_23 , V_42 , V_40 , NULL , 0x0 , NULL , V_41 }
} ,
{ & V_35 ,
{ L_24 , L_25 , V_45 , V_46 , NULL , 0x0 , NULL , V_41 }
} ,
{ & V_36 ,
{ L_26 , L_27 , V_42 , V_40 , NULL , 0x0 , NULL , V_41 }
} ,
{ & V_37 ,
{ L_28 , L_29 , V_39 , V_40 , NULL , 0x0 , NULL , V_41 }
} ,
} ;
static T_2 * V_48 [] = {
& V_21 ,
& V_49 ,
} ;
V_50 = F_24 ( L_30 , L_31 , L_32 ) ;
F_25 ( V_50 , V_38 , F_26 ( V_38 ) ) ;
F_27 ( V_48 , F_26 ( V_48 ) ) ;
}
void F_28 ( void )
{
F_29 ( V_50 , V_21 , V_51 , V_52 ) ;
}
