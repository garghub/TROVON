static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
struct V_5 * V_5 = (struct V_5 * ) V_2 -> V_6 ;
int V_7 = 0 ;
T_5 * V_8 ;
T_3 * V_9 ;
int V_10 ;
T_1 * V_11 ;
static const T_6 V_12 [] = { 0xff , 0xff } ;
static const T_6 V_13 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
V_10 = F_2 ( V_1 , V_7 ) ;
F_3 ( V_2 -> V_14 , V_15 , L_1 ,
( V_10 == 0x01 ) ? L_2 :
( V_10 == 0x02 ) ? L_3 :
( V_10 == 0x03 ) ? L_4 :
( V_10 == 0x07 ) ? L_5 :
L_6 ) ;
if ( F_4 ( V_1 ) < 44 ) {
F_5 ( V_3 , V_2 , & V_16 , V_1 , V_7 , - 1 ) ;
V_11 = F_6 ( V_1 , V_7 ) ;
F_7 ( V_17 , V_11 , V_2 , V_3 ) ;
return F_4 ( V_1 ) ;
}
V_8 = F_8 ( V_3 , V_1 , V_7 , 44 , L_7 ) ;
V_9 = F_9 ( V_8 , V_18 ) ;
if ( V_5 -> V_19 != V_20 )
F_10 ( V_9 , V_2 , & V_21 , V_1 , V_7 - 4 , 3 ,
L_8 , V_20 ) ;
if ( V_5 -> exp != 0 )
F_5 ( V_9 , V_2 , & V_22 , V_1 , V_7 - 2 , 1 ) ;
if ( V_5 -> V_23 != 1 )
F_5 ( V_9 , V_2 , & V_24 , V_1 , V_7 - 2 , 1 ) ;
if ( V_5 -> V_25 != 1 )
F_5 ( V_9 , V_2 , & V_26 , V_1 , V_7 - 1 , 1 ) ;
V_10 = F_2 ( V_1 , V_7 ) ;
F_11 ( V_9 , V_27 , V_1 ,
V_7 , 1 ,
V_28 ) ;
V_7 ++ ;
switch ( V_10 ) {
case 0x01 :
{
if ( F_12 ( V_1 , V_7 , V_13 , 3 ) == - 1 ) {
F_5 ( V_9 , V_2 , & V_29 , V_1 , V_7 , 3 ) ;
}
V_7 += 3 ;
if ( F_12 ( V_1 , V_7 , V_13 , 10 ) == - 1 ) {
F_5 ( V_9 , V_2 , & V_30 , V_1 , V_7 , 10 ) ;
}
V_7 += 10 ;
if ( F_12 ( V_1 , V_7 , V_12 , 2 ) == - 1 ) {
F_5 ( V_9 , V_2 , & V_31 , V_1 , V_7 , 2 ) ;
}
V_7 += 2 ;
F_11 ( V_9 , V_32 , V_1 , V_7 , 4 , V_33 ) ;
V_7 += 4 ;
F_11 ( V_9 , V_34 , V_1 , V_7 , 4 , V_33 ) ;
V_7 += 4 ;
if ( F_12 ( V_1 , V_7 , V_13 , 18 ) == - 1 ) {
F_5 ( V_9 , V_2 , & V_30 , V_1 , V_7 , 18 ) ;
}
V_7 += 18 ;
}
break;
case 0x02 :
case 0x03 :
{
if ( F_12 ( V_1 , V_7 , V_13 , 1 ) == - 1 ) {
F_10 ( V_9 , V_2 , & V_29 , V_1 , V_7 , 3 ,
L_9 ) ;
}
V_7 ++ ;
F_11 ( V_9 , V_35 , V_1 ,
V_7 , 2 ,
V_28 ) ;
V_7 += 2 ;
if ( F_12 ( V_1 , V_7 , V_13 , 20 ) == 0 ) {
F_5 ( V_9 , V_2 , & V_36 , V_1 , V_7 , 20 ) ;
V_7 += 20 ;
} else {
if ( F_12 ( V_1 , V_7 , V_13 , 10 ) == - 1 ) {
F_5 ( V_9 , V_2 , & V_30 , V_1 , V_7 , 10 ) ;
}
V_7 += 10 ;
if ( F_12 ( V_1 , V_7 , V_12 , 2 ) == - 1 ) {
F_5 ( V_9 , V_2 , & V_31 , V_1 , V_7 , 2 ) ;
}
V_7 += 2 ;
F_11 ( V_9 , V_32 , V_1 , V_7 , 4 , V_33 ) ;
V_7 += 4 ;
F_11 ( V_9 , V_34 , V_1 , V_7 , 4 , V_33 ) ;
V_7 += 4 ;
}
F_11 ( V_9 , V_37 , V_1 ,
V_7 , 4 ,
V_28 ) ;
V_7 += 4 ;
if ( F_12 ( V_1 , V_7 , V_13 , 14 ) == - 1 ) {
F_5 ( V_9 , V_2 , & V_30 , V_1 , V_7 , 14 ) ;
}
V_7 += 14 ;
}
break;
case 0x07 :
{
if ( F_12 ( V_1 , V_7 , V_13 , 3 ) == - 1 ) {
F_5 ( V_9 , V_2 , & V_29 , V_1 , V_7 , 3 ) ;
}
V_7 += 3 ;
if ( F_12 ( V_1 , V_7 , V_13 , 10 ) == - 1 ) {
F_5 ( V_9 , V_2 , & V_30 , V_1 , V_7 , 10 ) ;
}
V_7 += 10 ;
if ( F_12 ( V_1 , V_7 , V_12 , 2 ) == - 1 ) {
F_5 ( V_9 , V_2 , & V_31 , V_1 , V_7 , 2 ) ;
}
V_7 += 2 ;
F_11 ( V_9 , V_32 , V_1 , V_7 , 4 , V_33 ) ;
V_7 += 4 ;
F_11 ( V_9 , V_34 , V_1 , V_7 , 4 , V_33 ) ;
V_7 += 4 ;
F_11 ( V_9 , V_38 , V_1 ,
V_7 , 1 ,
V_28 ) ;
V_7 ++ ;
if ( F_12 ( V_1 , V_7 , V_13 , 17 ) == - 1 ) {
F_5 ( V_9 , V_2 , & V_30 , V_1 , V_7 , 17 ) ;
}
V_7 += 17 ;
}
break;
default:
F_5 ( V_9 , V_2 , & V_39 , V_1 , V_7 - 1 , - 1 ) ;
return V_7 ;
}
F_11 ( V_9 , V_40 , V_1 , V_7 , 2 ,
V_28 ) ;
V_7 += 2 ;
return V_7 ;
}
void
F_13 ( void )
{
static T_7 V_41 [] = {
{
& V_27 ,
{
L_10 , L_11 , V_42 ,
V_43 , F_14 ( V_44 ) ,
0x0 , L_12 , V_45
}
} ,
#if 0
{
&hf_mpls_y1711_ttsi,
{
"Trail Termination Source Identifier",
"mpls_y1711.ttsi",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
#endif
{
& V_38 ,
{
L_13 , L_14 , V_42 ,
V_43 , F_14 ( V_46 ) , 0x0 ,
L_15 , V_45
}
} ,
{
& V_35 ,
{
L_16 , L_17 , V_47 ,
V_43 , F_14 ( V_48 ) , 0x0 , NULL , V_45
}
} ,
{
& V_37 ,
{
L_18 , L_19 ,
V_49 , V_50 , NULL , 0x0 , L_20 , V_45
}
} ,
{
& V_40 ,
{
L_21 , L_22 , V_47 ,
V_43 , NULL , 0x0 , NULL , V_45
}
} ,
{ & V_32 , { L_23 , L_24 , V_51 , V_52 , NULL , 0x0 , NULL , V_45 } } ,
{ & V_34 , { L_25 , L_26 , V_53 , V_50 , NULL , 0x0 , NULL , V_45 } } ,
} ;
static T_8 * V_54 [] = {
& V_18
} ;
static T_9 V_55 [] = {
{ & V_16 , { L_27 , V_56 , V_57 , L_28 , V_58 } } ,
{ & V_21 , { L_29 , V_59 , V_60 , L_8 , V_58 } } ,
{ & V_22 , { L_30 , V_59 , V_60 , L_31 , V_58 } } ,
{ & V_24 , { L_32 , V_59 , V_60 , L_33 , V_58 } } ,
{ & V_26 , { L_34 , V_59 , V_60 , L_35 , V_58 } } ,
{ & V_29 , { L_36 , V_59 , V_60 , L_37 , V_58 } } ,
{ & V_30 , { L_38 , V_59 , V_60 , L_39 , V_58 } } ,
{ & V_31 , { L_40 , V_59 , V_60 , L_41 , V_58 } } ,
{ & V_36 , { L_42 , V_59 , V_61 , L_43 , V_58 } } ,
{ & V_39 , { L_44 , V_59 , V_60 , L_45 , V_58 } } ,
} ;
T_10 * V_62 ;
V_63 =
F_15 ( L_46 ,
L_46 ,
L_47 ) ;
F_16 ( V_63 , V_41 , F_17 ( V_41 ) ) ;
F_18 ( V_54 , F_17 ( V_54 ) ) ;
V_62 = F_19 ( V_63 ) ;
F_20 ( V_62 , V_55 , F_17 ( V_55 ) ) ;
F_21 ( L_47 , F_1 , V_63 ) ;
}
void
F_22 ( void )
{
V_64 = F_23 ( L_47 ) ;
F_24 ( L_48 ,
V_20 ,
V_64 ) ;
V_17 = F_23 ( L_49 ) ;
}
