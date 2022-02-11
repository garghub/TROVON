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
static int
F_4 ( T_3 * V_7 , T_4 * V_8 , T_5 * V_9 , void * T_6 V_10 )
{
T_5 * V_11 ;
T_7 * V_12 ;
T_3 * V_13 ;
T_1 V_14 ;
T_1 V_15 ;
const char * V_16 ;
T_8 V_17 ;
const char * V_18 ;
T_8 V_19 , V_20 ;
static const int * V_1 [] = {
& V_21 ,
& V_22 ,
& V_23 ,
& V_24 ,
NULL
} ;
F_5 ( V_8 -> V_25 , V_26 , L_11 ) ;
F_5 ( V_8 -> V_25 , V_27 , L_11 ) ;
V_12 = F_6 ( V_9 , V_28 , V_7 , 0 , V_29 , V_30 ) ;
V_11 = F_7 ( V_12 , V_31 ) ;
V_14 = F_8 ( V_7 , 0 ) ;
V_18 = F_1 ( V_14 ) ;
F_9 ( V_8 -> V_25 , V_27 , L_12 , V_18 ) ;
F_10 ( V_11 , V_7 , 0 , V_32 , V_33 ,
V_1 , V_30 , V_34 ) ;
V_15 = F_8 ( V_7 , 1 ) ;
V_16 = F_3 ( V_15 ) ;
if ( V_16 != NULL ) {
F_9 ( V_8 -> V_25 , V_27 , L_13 , V_16 ) ;
}
if ( V_9 ) {
if ( V_16 != NULL ) {
F_11 ( V_11 , V_35 , V_7 ,
1 , 1 , V_15 ,
L_14 ,
V_16 ,
V_15 ) ;
} else {
F_12 ( V_11 , V_35 , V_7 ,
1 , 1 , V_15 ) ;
}
F_6 ( V_11 , V_36 , V_7 , 2 , 2 , V_37 ) ;
F_6 ( V_11 , V_38 , V_7 , 4 , 2 , V_37 ) ;
}
V_17 = F_13 ( V_7 , 6 ) ;
if ( V_9 ) {
F_12 ( V_11 , V_39 , V_7 , 6 , 2 , V_17 ) ;
F_6 ( V_11 , V_40 , V_7 , 8 , 2 , V_37 ) ;
F_6 ( V_11 , V_41 , V_7 , 10 , 2 , V_37 ) ;
}
if ( F_14 ( V_7 , V_29 ) > 0 ) {
if ( V_8 -> V_42 > V_8 -> V_43 ) {
V_19 = V_8 -> V_43 ;
V_20 = V_8 -> V_42 ;
} else {
V_19 = V_8 -> V_42 ;
V_20 = V_8 -> V_43 ;
}
V_13 = F_15 ( V_7 , V_29 ) ;
if ( F_16 ( V_44 , V_19 ,
V_13 , V_8 , V_9 ) )
return F_17 ( V_7 ) ;
if ( F_16 ( V_44 , V_20 ,
V_13 , V_8 , V_9 ) )
return F_17 ( V_7 ) ;
F_18 ( V_13 , V_8 , V_9 ) ;
}
return F_17 ( V_7 ) ;
}
void
F_19 ( void )
{
static T_9 V_45 [] = {
{ & V_32 ,
{ L_15 , L_16 ,
V_46 , V_47 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_21 ,
{ L_6 , L_17 ,
V_49 , 8 , NULL , V_6 ,
NULL , V_48 } } ,
{ & V_22 ,
{ L_18 , L_19 ,
V_49 , 8 , NULL , V_5 ,
NULL , V_48 } } ,
{ & V_23 ,
{ L_3 , L_20 ,
V_49 , 8 , NULL , V_4 ,
NULL , V_48 } } ,
{ & V_24 ,
{ L_21 , L_22 ,
V_49 , 8 , NULL , V_3 ,
NULL , V_48 } } ,
{ & V_35 ,
{ L_23 , L_24 ,
V_46 , V_47 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_36 ,
{ L_25 , L_26 ,
V_50 , V_51 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_38 ,
{ L_27 , L_28 ,
V_50 , V_51 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_39 ,
{ L_29 , L_30 ,
V_50 , V_51 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_40 ,
{ L_31 , L_32 ,
V_50 , V_51 , NULL , 0x0 ,
NULL , V_48 } } ,
{ & V_41 ,
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
static T_10 * V_52 [] = {
& V_31 ,
& V_33 ,
} ;
V_28 = F_20 ( L_35 ,
L_11 , L_36 ) ;
F_21 ( V_28 , V_45 , F_22 ( V_45 ) ) ;
F_23 ( V_52 , F_22 ( V_52 ) ) ;
V_44 = F_24 ( L_37 ,
L_38 , V_28 , V_50 , V_47 ) ;
}
void
F_25 ( void )
{
T_11 V_53 ;
V_53 = F_26 ( F_4 , V_28 ) ;
F_27 ( L_39 , V_54 , V_53 ) ;
}
