static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 = NULL ;
T_5 * V_6 = NULL ;
T_5 * V_7 = NULL ;
T_3 * V_8 = NULL ;
T_3 * V_9 = NULL ;
T_3 * V_10 = NULL ;
unsigned int V_11 = 0 ;
T_6 V_12 , V_13 ;
T_7 V_14 ;
F_2 ( V_2 -> V_15 , V_16 , L_1 ) ;
if ( V_3 ) {
V_5 = F_3 ( V_3 , V_17 , V_1 , V_11 , - 1 , V_18 ) ;
V_8 = F_4 ( V_5 , V_19 ) ;
V_12 = F_5 ( V_1 , V_11 ) ;
F_3 ( V_8 , V_20 , V_1 , V_11 , 2 , V_21 ) ;
F_3 ( V_8 , V_22 , V_1 , V_11 , 2 , V_21 ) ;
F_3 ( V_8 , V_23 , V_1 , V_11 , 2 , V_21 ) ;
F_3 ( V_8 , V_24 , V_1 , V_11 , 2 , V_21 ) ;
F_3 ( V_8 , V_25 , V_1 , V_11 , 2 , V_21 ) ;
V_11 = V_11 + 2 ;
if ( ( V_12 & 0x0200 ) == 0x0200 ) {
F_3 ( V_8 , V_26 , V_1 , V_11 , 1 , V_21 ) ;
F_3 ( V_8 , V_27 , V_1 , V_11 , 1 , V_21 ) ;
F_3 ( V_8 , V_28 , V_1 , V_11 , 1 , V_21 ) ;
V_11 ++ ;
}
V_13 = ( V_12 & 0x01f8 ) >> 3 ;
if ( V_13 != 0 ) {
V_7 = F_3 ( V_8 , V_29 , V_1 , V_11 , V_13 , V_18 ) ;
V_9 = F_4 ( V_7 , V_30 ) ;
F_6 ( V_1 , V_2 , V_9 , V_11 , V_13 , TRUE ) ;
V_11 += V_13 ;
}
if ( ( V_12 & 0x0400 ) != 0 ) {
V_6 = F_3 ( V_8 , V_31 , V_1 , V_11 , - 1 , V_18 ) ;
V_10 = F_4 ( V_6 , V_32 ) ;
V_14 = F_7 ( V_1 , V_11 ) & 0xfe ;
if ( V_14 & 0x80 ) {
switch( V_14 ) {
case 0xf8 :
break;
case 0x80 :
case 0x82 :
F_8 ( V_2 -> V_15 , V_33 , L_2 ) ;
F_6 ( V_1 , V_2 , V_10 , V_11 , - 1 , TRUE ) ;
break;
case 0xfc :
case 0xfe :
default:
F_8 ( V_2 -> V_15 , V_33 , L_3 ) ;
F_9 ( V_1 , V_10 , V_11 , TRUE ) ;
break;
}
} else{
}
return F_10 ( V_1 ) ;
}
F_3 ( V_8 , V_31 , V_1 , V_11 , - 1 , V_18 ) ;
}
return F_10 ( V_1 ) ;
}
void
F_11 ( void )
{
static T_8 V_34 ;
static T_9 V_35 = FALSE ;
if ( ! V_35 ) {
F_12 ( L_4 , L_5 , V_36 ) ;
F_12 ( L_4 , L_6 , V_36 ) ;
V_35 = TRUE ;
}
else {
if ( V_34 > 95 )
F_13 ( L_7 , V_34 , V_36 ) ;
}
V_34 = V_37 ;
if ( V_34 > 95 ) {
F_14 ( L_7 , V_34 , V_36 ) ;
}
}
void
F_15 ( void )
{
T_10 * V_38 ;
static T_11 V_39 [] =
{
{
& V_31 ,
{
L_8 ,
L_9 ,
V_40 ,
V_41 ,
NULL ,
0x0 ,
L_10 , V_42
}
} ,
{
& V_20 ,
{
L_11 ,
L_12 ,
V_43 ,
V_44 ,
NULL ,
0xf800 ,
L_13 , V_42
}
} ,
{
& V_22 ,
{
L_14 ,
L_15 ,
V_45 ,
16 ,
NULL ,
0x0400 ,
L_16 , V_42
}
} ,
{
& V_23 ,
{
L_17 ,
L_18 ,
V_45 ,
16 ,
NULL ,
0x0200 ,
L_19 , V_42
}
} ,
{
& V_24 ,
{
L_20 ,
L_21 ,
V_43 ,
V_44 ,
NULL ,
0x01f8 ,
L_22 , V_42
}
} ,
{
& V_25 ,
{
L_23 ,
L_24 ,
V_43 ,
V_44 ,
NULL ,
0x0003 ,
L_25 , V_42
}
} ,
{
& V_26 ,
{
L_26 ,
L_27 ,
V_46 ,
V_44 ,
NULL ,
0xe0 ,
NULL , V_42
}
} ,
{
& V_27 ,
{
L_28 ,
L_29 ,
V_46 ,
V_44 ,
NULL ,
0x1e ,
L_30 , V_42
}
} ,
{
& V_28 ,
{
L_31 ,
L_32 ,
V_46 ,
V_44 ,
NULL ,
0x01 ,
L_33 , V_42
}
} ,
{
& V_29 ,
{
L_34 ,
L_35 ,
V_47 ,
V_41 ,
NULL ,
0x0 ,
NULL , V_42
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
static T_12 * V_48 [] =
{
& V_19 ,
& V_30 ,
& V_49 ,
& V_32 ,
} ;
V_17 = F_16 ( L_36 ,
L_37 , L_38 ) ;
F_17 ( V_17 , V_39 , F_18 ( V_39 ) ) ;
F_19 ( V_48 , F_18 ( V_48 ) ) ;
V_38 = F_20 ( V_17 , F_11 ) ;
F_21 ( V_38 ,
L_39 ,
L_40 ,
L_41
L_42 ,
10 ,
& V_37 ) ;
V_36 = F_22 ( L_43 , F_1 , V_17 ) ;
}
