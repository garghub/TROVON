static const char *
F_1 ( T_1 V_1 )
{
static const T_2 V_2 [] = {
{ 0x00 , L_1 } ,
{ V_3 , L_2 } ,
{ V_4 , L_3 } ,
{ V_5 , L_4 } ,
{ V_5 | V_3 , L_5 } ,
{ V_6 , L_6 } ,
{ V_6 | V_5 , L_7 } ,
{ 0x00 , NULL }
} ;
return F_2 ( ( V_1 & 0xf0 ) , V_2 , L_8 ) ;
}
static const char *
F_3 ( T_1 type )
{
switch ( type ) {
case 0xfe :
return L_9 ;
case 0xff :
return L_10 ;
default:
return NULL ;
}
}
static void
F_4 ( T_3 * V_7 , T_4 * V_8 , T_5 * V_9 )
{
T_5 * V_10 = NULL ;
T_6 * V_11 ;
T_3 * V_12 ;
T_1 V_13 ;
T_5 * V_14 ;
T_1 V_15 ;
const char * V_16 ;
T_7 V_17 ;
const char * V_18 ;
T_7 V_19 , V_20 ;
F_5 ( V_8 -> V_21 , V_22 , L_11 ) ;
F_5 ( V_8 -> V_21 , V_23 , L_11 ) ;
if ( V_9 ) {
V_11 = F_6 ( V_9 , V_24 , V_7 , 0 , V_25 , V_26 ) ;
V_10 = F_7 ( V_11 , V_27 ) ;
}
V_13 = F_8 ( V_7 , 0 ) ;
V_18 = F_1 ( V_13 ) ;
F_9 ( V_8 -> V_21 , V_23 , L_12 , V_18 ) ;
if ( V_9 ) {
V_11 = F_10 ( V_10 , V_28 , V_7 ,
0 , 1 , V_13 ,
L_13 ,
V_18 , V_13 ) ;
V_14 = F_7 ( V_11 , V_29 ) ;
F_11 ( V_14 , V_30 , V_7 ,
0 , 1 , V_13 ) ;
F_11 ( V_14 , V_31 , V_7 ,
0 , 1 , V_13 ) ;
F_11 ( V_14 , V_32 , V_7 ,
0 , 1 , V_13 ) ;
F_11 ( V_14 , V_33 , V_7 ,
0 , 1 , V_13 ) ;
}
V_15 = F_8 ( V_7 , 1 ) ;
V_16 = F_3 ( V_15 ) ;
if ( V_16 != NULL ) {
F_9 ( V_8 -> V_21 , V_23 , L_14 , V_16 ) ;
}
if ( V_9 ) {
if ( V_16 != NULL ) {
F_10 ( V_10 , V_34 , V_7 ,
1 , 1 , V_15 ,
L_13 ,
V_16 ,
V_15 ) ;
} else {
F_12 ( V_10 , V_34 , V_7 ,
1 , 1 , V_15 ) ;
}
F_6 ( V_10 , V_35 , V_7 , 2 , 2 , V_36 ) ;
F_6 ( V_10 , V_37 , V_7 , 4 , 2 , V_36 ) ;
}
V_17 = F_13 ( V_7 , 6 ) ;
if ( V_9 ) {
F_12 ( V_10 , V_38 , V_7 , 6 , 2 , V_17 ) ;
F_6 ( V_10 , V_39 , V_7 , 8 , 2 , V_36 ) ;
F_6 ( V_10 , V_40 , V_7 , 10 , 2 , V_36 ) ;
}
if ( F_14 ( V_7 , V_25 ) > 0 ) {
if ( V_8 -> V_41 > V_8 -> V_42 ) {
V_19 = V_8 -> V_42 ;
V_20 = V_8 -> V_41 ;
} else {
V_19 = V_8 -> V_41 ;
V_20 = V_8 -> V_42 ;
}
V_12 = F_15 ( V_7 , V_25 ) ;
if ( F_16 ( V_43 , V_19 ,
V_12 , V_8 , V_9 ) )
return;
if ( F_16 ( V_43 , V_20 ,
V_12 , V_8 , V_9 ) )
return;
F_17 ( V_44 , V_12 , V_8 , V_9 ) ;
}
}
void
F_18 ( void )
{
static T_8 V_45 [] = {
{ & V_28 ,
{ L_15 , L_16 ,
V_46 , V_47 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_30 ,
{ L_6 , L_17 ,
V_49 , 8 , NULL , V_6 ,
NULL , V_48 } } ,
{ & V_31 ,
{ L_18 , L_19 ,
V_49 , 8 , NULL , V_5 ,
NULL , V_48 } } ,
{ & V_32 ,
{ L_3 , L_20 ,
V_49 , 8 , NULL , V_4 ,
NULL , V_48 } } ,
{ & V_33 ,
{ L_21 , L_22 ,
V_49 , 8 , NULL , V_3 ,
NULL , V_48 } } ,
{ & V_34 ,
{ L_23 , L_24 ,
V_46 , V_47 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_35 ,
{ L_25 , L_26 ,
V_50 , V_51 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_37 ,
{ L_27 , L_28 ,
V_50 , V_51 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_38 ,
{ L_29 , L_30 ,
V_50 , V_51 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_39 ,
{ L_31 , L_32 ,
V_50 , V_51 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_40 ,
{ L_33 , L_34 ,
V_50 , V_51 , NULL , 0x0 ,
NULL , V_48 } } ,
#if 0
{ &hf_spp_rexmt_frame,
{ "Retransmitted Frame Number", "spp.rexmt_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#endif
} ;
static T_9 * V_52 [] = {
& V_27 ,
& V_29 ,
} ;
V_24 = F_19 ( L_35 ,
L_11 , L_36 ) ;
F_20 ( V_24 , V_45 , F_21 ( V_45 ) ) ;
F_22 ( V_52 , F_21 ( V_52 ) ) ;
V_43 = F_23 ( L_37 ,
L_38 , V_50 , V_47 ) ;
}
void
F_24 ( void )
{
T_10 V_53 ;
V_53 = F_25 ( F_4 , V_24 ) ;
F_26 ( L_39 , V_54 , V_53 ) ;
V_44 = F_27 ( L_40 ) ;
}
