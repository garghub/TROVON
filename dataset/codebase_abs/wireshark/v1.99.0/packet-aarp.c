static T_1 *
F_1 ( T_2 * V_1 , T_3 V_2 )
{
T_3 V_3 ;
T_1 * V_4 ;
V_4 = ( T_1 * ) F_2 ( F_3 () , 16 ) ;
V_3 = F_4 ( V_1 , V_2 ) << 8 | F_4 ( V_1 , V_2 + 1 ) ;
F_5 ( V_4 , 16 , L_1 , V_3 , F_4 ( V_1 , V_2 + 2 ) ) ;
return V_4 ;
}
static const T_1 *
F_6 ( T_2 * V_1 , T_3 V_2 , int V_5 , T_4 type )
{
if ( F_7 ( type , V_5 ) ) {
return F_8 ( V_1 , V_2 ) ;
}
return F_9 ( V_1 , V_2 , V_5 ) ;
}
static T_1 *
F_10 ( T_2 * V_1 , T_3 V_2 , int V_5 , T_4 type )
{
if ( F_11 ( type , V_5 ) ) {
return F_1 ( V_1 , V_2 ) ;
}
return F_9 ( V_1 , V_2 , V_5 ) ;
}
static void
F_12 ( T_2 * V_1 , T_5 * V_6 , T_6 * V_7 ) {
T_4 V_8 ;
T_4 V_9 ;
T_7 V_10 ;
T_7 V_11 ;
T_4 V_12 ;
T_6 * V_13 ;
T_8 * V_14 ;
const T_1 * V_15 ;
int V_16 , V_17 , V_18 , V_19 ;
const T_1 * V_20 , * V_21 , * V_22 ;
F_13 ( V_6 -> V_23 , V_24 , L_2 ) ;
F_14 ( V_6 -> V_23 , V_25 ) ;
V_8 = F_15 ( V_1 , V_26 ) ;
V_9 = F_15 ( V_1 , V_27 ) ;
V_10 = F_4 ( V_1 , V_28 ) ;
V_11 = F_4 ( V_1 , V_29 ) ;
V_12 = F_15 ( V_1 , V_30 ) ;
V_16 = V_31 ;
V_17 = V_16 + V_10 ;
V_18 = V_17 + V_11 ;
V_19 = V_18 + V_10 ;
V_20 = F_6 ( V_1 , V_16 , V_10 , V_8 ) ;
V_21 = F_10 ( V_1 , V_17 , V_11 , V_9 ) ;
#if 0
tha_str = tvb_aarphrdaddr_to_str(tvb, tha_offset, ar_hln, ar_hrd);
#endif
V_22 = F_10 ( V_1 , V_19 , V_11 , V_9 ) ;
switch ( V_12 ) {
case V_32 :
case V_33 :
F_16 ( V_6 -> V_23 , V_25 , L_3 , V_22 , V_21 ) ;
break;
case V_34 :
case V_35 :
F_16 ( V_6 -> V_23 , V_25 , L_4 , V_21 , V_20 ) ;
break;
case V_36 :
case V_37 :
F_16 ( V_6 -> V_23 , V_25 , L_5 , V_22 ) ;
break;
default:
F_16 ( V_6 -> V_23 , V_25 , L_6 , V_12 ) ;
break;
}
if ( V_7 ) {
if ( ( V_15 = F_17 ( V_12 , V_38 ) ) )
V_14 = F_18 ( V_7 , V_39 , V_1 , 0 ,
V_31 + 2 * V_10 +
2 * V_11 , L_7 , V_15 ) ;
else
V_14 = F_18 ( V_7 , V_39 , V_1 , 0 ,
V_31 + 2 * V_10 +
2 * V_11 ,
L_8 , V_12 ) ;
V_13 = F_19 ( V_14 , V_40 ) ;
F_20 ( V_13 , V_41 , V_1 , V_26 , 2 ,
V_8 ) ;
F_20 ( V_13 , V_42 , V_1 , V_27 , 2 ,
V_9 ) ;
F_20 ( V_13 , V_43 , V_1 , V_28 , 1 ,
V_10 ) ;
F_20 ( V_13 , V_44 , V_1 , V_29 , 1 ,
V_11 ) ;
F_20 ( V_13 , V_45 , V_1 , V_30 , 2 ,
V_12 ) ;
if ( V_10 != 0 ) {
F_21 ( V_13 ,
F_7 ( V_8 , V_10 ) ? V_46 : V_47 ,
V_1 , V_16 , V_10 , V_48 ) ;
}
if ( V_11 != 0 ) {
if ( F_11 ( V_9 , V_11 ) ) {
F_22 ( V_13 , V_49 , V_1 ,
V_17 , V_11 , NULL ,
L_9 , V_21 ) ;
} else {
F_22 ( V_13 , V_50 , V_1 ,
V_17 , V_11 , NULL ,
L_9 , V_21 ) ;
}
}
if ( V_10 != 0 ) {
F_21 ( V_13 ,
F_7 ( V_8 , V_10 ) ? V_51 : V_52 ,
V_1 , V_18 , V_10 , V_48 ) ;
}
if ( V_11 != 0 ) {
if ( F_11 ( V_9 , V_11 ) ) {
F_22 ( V_13 , V_53 , V_1 ,
V_19 , V_11 ,
NULL , L_9 , V_22 ) ;
} else {
F_22 ( V_13 , V_54 , V_1 ,
V_19 , V_11 ,
NULL , L_9 , V_22 ) ;
}
}
}
}
void
F_23 ( void )
{
static T_9 V_55 [] = {
{ & V_41 ,
{ L_10 , L_11 ,
V_56 , V_57 , F_24 ( V_58 ) , 0x0 ,
NULL , V_59 } } ,
{ & V_42 ,
{ L_12 , L_13 ,
V_56 , V_57 , F_24 ( V_60 ) , 0x0 ,
NULL , V_59 } } ,
{ & V_43 ,
{ L_14 , L_15 ,
V_61 , V_62 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_44 ,
{ L_16 , L_17 ,
V_61 , V_62 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_45 ,
{ L_18 , L_19 ,
V_56 , V_62 , F_24 ( V_38 ) , 0x0 ,
NULL , V_59 } } ,
{ & V_47 ,
{ L_20 , L_21 ,
V_63 , V_64 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_46 ,
{ L_22 , L_23 ,
V_65 , V_64 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_50 ,
{ L_24 , L_25 ,
V_63 , V_64 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_49 ,
{ L_26 , L_27 ,
V_63 , V_64 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_52 ,
{ L_28 , L_29 ,
V_63 , V_64 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_51 ,
{ L_30 , L_31 ,
V_65 , V_64 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_54 ,
{ L_32 , L_33 ,
V_63 , V_64 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_53 ,
{ L_34 , L_35 ,
V_63 , V_64 , NULL , 0x0 ,
NULL , V_59 } } ,
} ;
static T_3 * V_66 [] = {
& V_40 ,
} ;
V_39 = F_25 ( L_36 ,
L_2 ,
L_37 ) ;
F_26 ( V_39 , V_55 , F_27 ( V_55 ) ) ;
F_28 ( V_66 , F_27 ( V_66 ) ) ;
}
void
F_29 ( void )
{
T_10 V_67 ;
V_67 = F_30 ( F_12 , V_39 ) ;
F_31 ( L_38 , V_68 , V_67 ) ;
F_31 ( L_39 , V_68 , V_67 ) ;
}
