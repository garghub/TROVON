static T_1 *
F_1 ( T_2 * V_1 , T_3 V_2 )
{
T_3 V_3 ;
T_1 * V_4 ;
V_4 = ( T_1 * ) F_2 ( F_3 () , 16 ) ;
V_3 = F_4 ( V_1 , V_2 + 1 ) << 8 | F_4 ( V_1 , V_2 + 2 ) ;
F_5 ( V_4 , 16 , L_1 , V_3 , F_4 ( V_1 , V_2 + 3 ) ) ;
return V_4 ;
}
static const T_1 *
F_6 ( T_2 * V_1 , T_3 V_2 , int V_5 , T_4 type )
{
if ( F_7 ( type , V_5 ) ) {
return F_8 ( V_1 , V_2 ) ;
}
return F_9 ( F_3 () , V_1 , V_2 , V_5 ) ;
}
static T_1 *
F_10 ( T_2 * V_1 , T_3 V_2 , int V_5 , T_4 type )
{
if ( F_11 ( type , V_5 ) ) {
return F_1 ( V_1 , V_2 ) ;
}
return F_9 ( F_3 () , V_1 , V_2 , V_5 ) ;
}
static int
F_12 ( T_2 * V_1 , T_5 * V_6 , T_6 * V_7 , void * T_7 V_8 ) {
T_4 V_9 ;
T_4 V_10 ;
T_8 V_11 ;
T_8 V_12 ;
T_4 V_13 ;
T_6 * V_14 ;
T_9 * V_15 ;
const T_1 * V_16 ;
int V_17 , V_18 , V_19 , V_20 ;
const T_1 * V_21 , * V_22 , * V_23 ;
F_13 ( V_6 -> V_24 , V_25 , L_2 ) ;
F_14 ( V_6 -> V_24 , V_26 ) ;
V_9 = F_15 ( V_1 , V_27 ) ;
V_10 = F_15 ( V_1 , V_28 ) ;
V_11 = F_4 ( V_1 , V_29 ) ;
V_12 = F_4 ( V_1 , V_30 ) ;
V_13 = F_15 ( V_1 , V_31 ) ;
V_17 = V_32 ;
V_18 = V_17 + V_11 ;
V_19 = V_18 + V_12 ;
V_20 = V_19 + V_11 ;
V_21 = F_6 ( V_1 , V_17 , V_11 , V_9 ) ;
V_22 = F_10 ( V_1 , V_18 , V_12 , V_10 ) ;
#if 0
tha_str = tvb_aarphrdaddr_to_str(tvb, tha_offset, ar_hln, ar_hrd);
#endif
V_23 = F_10 ( V_1 , V_20 , V_12 , V_10 ) ;
switch ( V_13 ) {
case V_33 :
case V_34 :
F_16 ( V_6 -> V_24 , V_26 , L_3 , V_23 , V_22 ) ;
break;
case V_35 :
case V_36 :
F_16 ( V_6 -> V_24 , V_26 , L_4 , V_22 , V_21 ) ;
break;
case V_37 :
case V_38 :
F_16 ( V_6 -> V_24 , V_26 , L_5 , V_23 ) ;
break;
default:
F_16 ( V_6 -> V_24 , V_26 , L_6 , V_13 ) ;
break;
}
if ( V_7 ) {
if ( ( V_16 = F_17 ( V_13 , V_39 ) ) )
V_15 = F_18 ( V_7 , V_40 , V_1 , 0 ,
V_32 + 2 * V_11 +
2 * V_12 , L_7 , V_16 ) ;
else
V_15 = F_18 ( V_7 , V_40 , V_1 , 0 ,
V_32 + 2 * V_11 +
2 * V_12 ,
L_8 , V_13 ) ;
V_14 = F_19 ( V_15 , V_41 ) ;
F_20 ( V_14 , V_42 , V_1 , V_27 , 2 ,
V_9 ) ;
F_20 ( V_14 , V_43 , V_1 , V_28 , 2 ,
V_10 ) ;
F_20 ( V_14 , V_44 , V_1 , V_29 , 1 ,
V_11 ) ;
F_20 ( V_14 , V_45 , V_1 , V_30 , 1 ,
V_12 ) ;
F_20 ( V_14 , V_46 , V_1 , V_31 , 2 ,
V_13 ) ;
if ( V_11 != 0 ) {
F_21 ( V_14 ,
F_7 ( V_9 , V_11 ) ? V_47 : V_48 ,
V_1 , V_17 , V_11 , V_49 ) ;
}
if ( V_12 != 0 ) {
if ( F_11 ( V_10 , V_12 ) ) {
F_22 ( V_14 , V_50 , V_1 ,
V_18 , V_12 , NULL ,
L_9 , V_22 ) ;
} else {
F_22 ( V_14 , V_51 , V_1 ,
V_18 , V_12 , NULL ,
L_9 , V_22 ) ;
}
}
if ( V_11 != 0 ) {
F_21 ( V_14 ,
F_7 ( V_9 , V_11 ) ? V_52 : V_53 ,
V_1 , V_19 , V_11 , V_49 ) ;
}
if ( V_12 != 0 ) {
if ( F_11 ( V_10 , V_12 ) ) {
F_22 ( V_14 , V_54 , V_1 ,
V_20 , V_12 ,
NULL , L_9 , V_23 ) ;
} else {
F_22 ( V_14 , V_55 , V_1 ,
V_20 , V_12 ,
NULL , L_9 , V_23 ) ;
}
}
}
return F_23 ( V_1 ) ;
}
void
F_24 ( void )
{
static T_10 V_56 [] = {
{ & V_42 ,
{ L_10 , L_11 ,
V_57 , V_58 , F_25 ( V_59 ) , 0x0 ,
NULL , V_60 } } ,
{ & V_43 ,
{ L_12 , L_13 ,
V_57 , V_58 , F_25 ( V_61 ) , 0x0 ,
NULL , V_60 } } ,
{ & V_44 ,
{ L_14 , L_15 ,
V_62 , V_63 , NULL , 0x0 ,
NULL , V_60 } } ,
{ & V_45 ,
{ L_16 , L_17 ,
V_62 , V_63 , NULL , 0x0 ,
NULL , V_60 } } ,
{ & V_46 ,
{ L_18 , L_19 ,
V_57 , V_63 , F_25 ( V_39 ) , 0x0 ,
NULL , V_60 } } ,
{ & V_48 ,
{ L_20 , L_21 ,
V_64 , V_65 , NULL , 0x0 ,
NULL , V_60 } } ,
{ & V_47 ,
{ L_22 , L_23 ,
V_66 , V_65 , NULL , 0x0 ,
NULL , V_60 } } ,
{ & V_51 ,
{ L_24 , L_25 ,
V_64 , V_65 , NULL , 0x0 ,
NULL , V_60 } } ,
{ & V_50 ,
{ L_26 , L_27 ,
V_64 , V_65 , NULL , 0x0 ,
NULL , V_60 } } ,
{ & V_53 ,
{ L_28 , L_29 ,
V_64 , V_65 , NULL , 0x0 ,
NULL , V_60 } } ,
{ & V_52 ,
{ L_30 , L_31 ,
V_66 , V_65 , NULL , 0x0 ,
NULL , V_60 } } ,
{ & V_55 ,
{ L_32 , L_33 ,
V_64 , V_65 , NULL , 0x0 ,
NULL , V_60 } } ,
{ & V_54 ,
{ L_34 , L_35 ,
V_64 , V_65 , NULL , 0x0 ,
NULL , V_60 } } ,
} ;
static T_3 * V_67 [] = {
& V_41 ,
} ;
V_40 = F_26 ( L_36 ,
L_2 ,
L_37 ) ;
F_27 ( V_40 , V_56 , F_28 ( V_56 ) ) ;
F_29 ( V_67 , F_28 ( V_67 ) ) ;
}
void
F_30 ( void )
{
T_11 V_68 ;
V_68 = F_31 ( F_12 , V_40 ) ;
F_32 ( L_38 , V_69 , V_68 ) ;
F_32 ( L_39 , V_69 , V_68 ) ;
}
