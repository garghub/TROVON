static void
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , T_5 V_4 , T_6 V_5 )
{
T_4 * V_6 ;
T_4 * V_7 ;
T_6 V_8 ;
while ( V_5 > 1 ) {
T_6 V_9 = F_2 ( V_1 , V_4 ) ;
V_4 += 2 ;
V_5 -= 2 ;
V_8 = V_9 & 0xff ;
switch ( V_9 >> 8 ) {
case V_10 : {
T_6 V_11 ;
T_7 V_12 = F_3 ( V_1 , V_4 ) >> 8 ;
if ( V_8 != 3 ) {
F_4 ( T_3 , V_3 , V_13 , V_14 , L_1 , V_8 ) ;
break;
}
V_6 = F_5 ( V_3 , V_15 , V_1 , V_4 , V_8 , V_16 ) ;
V_7 = F_6 ( V_6 , V_17 ) ;
F_5 ( V_7 , V_18 , V_1 , V_4 , V_8 , V_16 ) ;
F_5 ( V_7 , V_19 , V_1 , V_4 , V_8 , V_16 ) ;
F_5 ( V_7 , V_20 , V_1 , V_4 , V_8 , V_16 ) ;
V_6 = F_5 ( V_7 , V_21 , V_1 , V_4 , V_8 , V_16 ) ;
V_11 = ( ( V_12 & V_22 ) >> V_23 ) - 24 ;
if ( V_11 >= 1 && V_11 <= 4 ) {
F_7 ( V_6 , L_2 , V_11 ) ;
}
break;
}
case V_24 :
if ( V_8 != 2 ) {
F_4 ( T_3 , V_3 , V_13 , V_14 , L_1 , V_8 ) ;
break;
}
F_5 ( V_3 , V_25 , V_1 , V_4 , V_8 , V_16 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
if ( V_8 != 8 ) {
F_4 ( T_3 , V_3 , V_13 , V_14 , L_1 , V_8 ) ;
break;
}
V_6 = F_5 ( V_3 , V_30 , V_1 , V_4 , V_8 , V_31 | V_16 ) ;
F_7 ( V_6 , L_3 , F_8 ( V_9 >> 8 , V_32 , L_4 ) ) ;
break;
default:
V_6 = F_5 ( V_3 , V_33 , V_1 , V_4 , V_8 , V_34 ) ;
F_7 ( V_6 , L_5 , V_9 >> 8 , V_8 ) ;
break;
}
V_4 += V_8 ;
V_5 -= V_8 ;
}
}
static void
F_9 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_35 )
{
T_4 * V_6 ;
T_8 V_5 ;
volatile T_6 V_36 ;
volatile T_9 V_37 ;
T_4 * volatile V_3 = NULL ;
volatile T_5 V_4 = 0 ;
V_5 = F_10 ( V_1 , V_4 ) ;
if ( V_35 ) {
V_6 = F_5 ( V_35 , V_38 , V_1 , V_4 , V_5 , V_34 ) ;
if ( V_39 ) {
F_7 ( V_6 , L_6 , V_5 ) ;
}
V_3 = F_6 ( V_6 , V_40 ) ;
F_1 ( V_1 , T_3 , V_3 , V_4 + 1 , V_5 - 1 ) ;
}
V_4 += V_5 ;
V_36 = F_2 ( V_1 , V_4 ) ;
V_4 += 2 ;
if ( V_36 <= V_41 ) {
V_37 = TRUE ;
if ( F_11 ( V_1 , V_4 ) >= 2 ) {
if ( F_2 ( V_1 , V_4 ) == 0xffff ) {
V_37 = FALSE ;
}
}
F_12 ( V_36 , V_37 , V_1 , V_4 , T_3 , V_35 , V_3 ,
V_42 , V_43 , 0 ) ;
} else {
F_13 ( V_36 , V_1 , V_4 , T_3 , V_35 , V_3 ,
V_44 , V_43 , 0 ) ;
}
}
static int
F_14 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_35 )
{
T_4 * V_6 ;
T_5 V_45 , V_5 ;
T_4 * V_3 = NULL ;
T_5 V_4 ;
T_6 V_46 , V_47 ;
V_45 = F_15 ( V_1 ) ;
if ( V_45 < 5 )
return 0 ;
if ( F_2 ( V_1 , V_45 - 4 ) != V_48 )
return 0 ;
V_5 = F_10 ( V_1 , V_45 - 5 ) ;
if ( ( V_45 - 5 ) != V_5 )
return 0 ;
V_4 = V_45 - 5 - V_5 ;
V_46 = F_2 ( V_1 , V_45 - 2 ) ;
{
T_10 V_49 ;
V_49 . V_50 = V_5 + 3 ;
V_49 . V_51 = F_16 ( V_1 , V_4 , V_49 . V_50 ) ;
V_47 = F_17 ( & V_49 , 1 ) ;
if ( F_18 ( & V_47 ) != V_46 ) {
return 0 ;
}
}
if ( V_35 ) {
V_6 = F_5 ( V_35 , V_38 , V_1 , V_4 , V_5 + 5 , V_34 ) ;
if ( V_39 ) {
F_7 ( V_6 , L_7 , V_5 , V_46 ) ;
}
V_3 = F_6 ( V_6 , V_40 ) ;
F_1 ( V_1 , T_3 , V_3 , V_4 , V_5 ) ;
}
return V_45 ;
}
void
F_19 ( void )
{
static T_11 V_52 [] = {
{ & V_15 , {
L_8 , L_9 , V_53 , V_54 ,
NULL , 0 , L_10 , V_55 } } ,
{ & V_18 , {
L_11 , L_12 , V_53 , V_56 ,
F_20 ( V_57 ) , V_58 , L_13 , V_55 } } ,
{ & V_19 , {
L_14 , L_15 , V_53 , V_56 ,
NULL , V_59 , L_16 , V_55 } } ,
{ & V_20 , {
L_17 , L_18 , V_53 , V_56 ,
NULL , V_60 , L_19 , V_55 } } ,
{ & V_21 , {
L_20 , L_21 , V_53 , V_56 ,
NULL , V_22 , L_22 , V_55 } } ,
{ & V_25 , {
L_23 , L_24 , V_61 , V_56 ,
NULL , 0 , NULL , V_55 } } ,
{ & V_30 , {
L_25 , L_26 , V_62 , V_63 ,
NULL , 0x0 , NULL , V_55 } } ,
{ & V_33 , {
L_27 , L_28 , V_64 , V_65 ,
NULL , 0x0 , NULL , V_55 } } ,
{ & V_44 , {
L_29 , L_30 , V_61 , V_54 ,
F_20 ( V_66 ) , 0x0 , L_31 , V_55 } } ,
{ & V_42 , {
L_32 , L_33 , V_61 , V_56 ,
NULL , 0x0 , NULL , V_55 } } ,
{ & V_43 , {
L_34 , L_35 , V_64 , V_65 ,
NULL , 0x0 , L_36 , V_55 } }
} ;
static T_12 * V_67 [] = {
& V_40 ,
& V_17
} ;
T_13 * V_68 ;
V_38 = F_21 ( L_37 , L_38 , L_39 ) ;
F_22 ( V_38 , V_52 , F_23 ( V_52 ) ) ;
F_24 ( V_67 , F_23 ( V_67 ) ) ;
V_68 = F_25 ( V_38 , NULL ) ;
F_26 ( V_68 , L_40 ,
L_41 ,
L_42 ,
& V_39 ) ;
}
void
F_27 ( void )
{
T_14 V_69 ;
V_69 = F_28 ( F_9 , V_38 ) ;
F_29 ( L_43 , V_48 , V_69 ) ;
F_30 ( L_44 , F_14 , V_38 ) ;
}
