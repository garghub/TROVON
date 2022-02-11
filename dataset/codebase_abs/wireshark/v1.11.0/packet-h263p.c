static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 = NULL ;
T_4 * V_5 = NULL ;
T_4 * V_6 = NULL ;
T_3 * V_7 = NULL ;
T_3 * V_8 = NULL ;
T_3 * V_9 = NULL ;
unsigned int V_10 = 0 ;
T_5 V_11 , V_12 ;
T_6 V_13 ;
F_2 ( V_2 -> V_14 , V_15 , L_1 ) ;
if ( V_3 ) {
V_4 = F_3 ( V_3 , V_16 , V_1 , V_10 , - 1 , V_17 ) ;
V_7 = F_4 ( V_4 , V_18 ) ;
V_11 = F_5 ( V_1 , V_10 ) ;
F_3 ( V_7 , V_19 , V_1 , V_10 , 2 , V_20 ) ;
F_3 ( V_7 , V_21 , V_1 , V_10 , 2 , V_20 ) ;
F_3 ( V_7 , V_22 , V_1 , V_10 , 2 , V_20 ) ;
F_3 ( V_7 , V_23 , V_1 , V_10 , 2 , V_20 ) ;
F_3 ( V_7 , V_24 , V_1 , V_10 , 2 , V_20 ) ;
V_10 = V_10 + 2 ;
if ( ( V_11 & 0x0200 ) == 0x0200 ) {
F_3 ( V_7 , V_25 , V_1 , V_10 , 1 , V_20 ) ;
F_3 ( V_7 , V_26 , V_1 , V_10 , 1 , V_20 ) ;
F_3 ( V_7 , V_27 , V_1 , V_10 , 1 , V_20 ) ;
V_10 ++ ;
}
V_12 = ( V_11 & 0x01f8 ) >> 3 ;
if ( V_12 != 0 ) {
V_6 = F_3 ( V_7 , V_28 , V_1 , V_10 , V_12 , V_17 ) ;
V_8 = F_4 ( V_6 , V_29 ) ;
F_6 ( V_1 , V_2 , V_8 , V_10 , V_12 , TRUE ) ;
V_10 += V_12 ;
}
if ( ( V_11 & 0x0400 ) != 0 ) {
V_5 = F_3 ( V_7 , V_30 , V_1 , V_10 , - 1 , V_17 ) ;
V_9 = F_4 ( V_5 , V_31 ) ;
V_13 = F_7 ( V_1 , V_10 ) & 0xfe ;
if ( V_13 & 0x80 ) {
switch( V_13 ) {
case 0xf8 :
break;
case 0x80 :
case 0x82 :
F_8 ( V_2 -> V_14 , V_32 , L_2 ) ;
F_6 ( V_1 , V_2 , V_9 , V_10 , - 1 , TRUE ) ;
break;
case 0xfc :
case 0xfe :
default:
F_8 ( V_2 -> V_14 , V_32 , L_3 ) ;
F_9 ( V_1 , V_9 , V_10 , TRUE ) ;
break;
}
} else{
}
return;
}
F_3 ( V_7 , V_30 , V_1 , V_10 , - 1 , V_17 ) ;
}
}
void
F_10 ( void )
{
static T_7 V_33 ;
static T_8 V_34 ;
static T_9 V_35 = FALSE ;
if ( ! V_35 ) {
V_33 = F_11 ( L_4 ) ;
F_12 ( L_5 , L_6 , V_33 ) ;
F_12 ( L_5 , L_7 , V_33 ) ;
V_35 = TRUE ;
}
else {
if ( V_34 > 95 )
F_13 ( L_8 , V_34 , V_33 ) ;
}
V_34 = V_36 ;
if ( V_34 > 95 ) {
F_14 ( L_8 , V_34 , V_33 ) ;
}
}
void
F_15 ( void )
{
T_10 * V_37 ;
static T_11 V_38 [] =
{
{
& V_30 ,
{
L_9 ,
L_10 ,
V_39 ,
V_40 ,
NULL ,
0x0 ,
L_11 , V_41
}
} ,
{
& V_19 ,
{
L_12 ,
L_13 ,
V_42 ,
V_43 ,
NULL ,
0xf800 ,
L_14 , V_41
}
} ,
{
& V_21 ,
{
L_15 ,
L_16 ,
V_44 ,
16 ,
NULL ,
0x0400 ,
L_17 , V_41
}
} ,
{
& V_22 ,
{
L_18 ,
L_19 ,
V_44 ,
16 ,
NULL ,
0x0200 ,
L_20 , V_41
}
} ,
{
& V_23 ,
{
L_21 ,
L_22 ,
V_42 ,
V_43 ,
NULL ,
0x01f8 ,
L_23 , V_41
}
} ,
{
& V_24 ,
{
L_24 ,
L_25 ,
V_42 ,
V_43 ,
NULL ,
0x0003 ,
L_26 , V_41
}
} ,
{
& V_25 ,
{
L_27 ,
L_28 ,
V_45 ,
V_43 ,
NULL ,
0xe0 ,
NULL , V_41
}
} ,
{
& V_26 ,
{
L_29 ,
L_30 ,
V_45 ,
V_43 ,
NULL ,
0x1e ,
L_31 , V_41
}
} ,
{
& V_27 ,
{
L_32 ,
L_33 ,
V_45 ,
V_43 ,
NULL ,
0x01 ,
L_34 , V_41
}
} ,
{
& V_28 ,
{
L_35 ,
L_36 ,
V_46 ,
V_40 ,
NULL ,
0x0 ,
NULL , V_41
}
} ,
#if 0
{
&hf_h263P_PSC,
{
"H.263 PSC",
"h263p.PSC",
FT_UINT16,
BASE_HEX,
NULL,
0xfc00,
"Picture Start Code(PSC)", HFILL
}
},
#endif
#if 0
{
&hf_h263P_TR,
{
"H.263 Temporal Reference",
"h263p.tr",
FT_UINT16,
BASE_HEX,
NULL,
0x03fc,
"Temporal Reference, TR", HFILL
}
},
#endif
} ;
static T_12 * V_47 [] =
{
& V_18 ,
& V_29 ,
& V_48 ,
& V_31 ,
} ;
V_16 = F_16 ( L_37 ,
L_38 , L_39 ) ;
F_17 ( V_16 , V_38 , F_18 ( V_38 ) ) ;
F_19 ( V_47 , F_18 ( V_47 ) ) ;
V_37 = F_20 ( V_16 , F_10 ) ;
F_21 ( V_37 , L_40 ,
L_41 ,
L_42
L_43 ,
10 ,
& V_36 ) ;
F_22 ( L_4 , F_1 , V_16 ) ;
}
