void
F_1 ( const T_1 * V_1 , int V_2 , int V_3 , T_2 * V_4 ) {
if ( ! F_2 ( V_2 , V_3 , 4 ) ) {
V_4 -> V_5 ++ ;
return;
}
switch ( F_3 ( & V_1 [ V_2 + 2 ] ) ) {
case V_6 :
F_4 ( V_1 , V_2 + 4 , V_3 , V_4 ) ;
break;
default:
V_4 -> V_5 ++ ;
break;
}
}
void
F_5 ( T_3 V_7 , T_4 * V_8 , int V_9 ,
T_5 * V_10 , T_6 * V_11 , T_6 * V_12 ,
int V_13 )
{
T_4 * V_14 ;
int V_15 ;
F_6 ( V_12 , V_13 , V_8 ,
V_9 - 2 , 2 , V_7 ) ;
V_15 = F_7 ( V_8 , V_9 ) ;
if ( V_7 == V_16 &&
! ( V_15 == V_17 ||
V_15 == V_18 ||
V_15 == V_19 ) ) {
F_8 ( V_12 , V_20 , V_8 , V_9 , 1 , V_21 ) ;
V_14 = F_9 ( V_8 , V_9 + 1 ) ;
} else {
V_14 = F_9 ( V_8 , V_9 ) ;
}
if ( ! F_10 ( V_22 , V_7 , V_14 , V_10 , V_11 ) ) {
F_11 ( V_10 -> V_23 , V_24 , L_1 , V_7 ) ;
F_12 ( V_25 , V_14 , V_10 , V_11 ) ;
}
}
static void
F_13 ( T_4 * V_8 , T_5 * V_10 , T_6 * V_11 )
{
T_7 * V_26 ;
T_6 * V_12 = NULL ;
T_8 V_27 ;
T_3 V_28 ;
F_14 ( V_10 -> V_23 , V_24 , L_2 ) ;
F_15 ( V_10 -> V_23 , V_29 ) ;
switch ( V_10 -> V_30 ) {
case V_31 :
F_14 ( V_10 -> V_23 , V_32 , L_3 ) ;
F_14 ( V_10 -> V_23 , V_33 , L_4 ) ;
break;
case V_34 :
F_14 ( V_10 -> V_23 , V_32 , L_4 ) ;
F_14 ( V_10 -> V_23 , V_33 , L_3 ) ;
break;
default:
F_14 ( V_10 -> V_23 , V_32 , L_5 ) ;
F_14 ( V_10 -> V_23 , V_33 , L_5 ) ;
break;
}
V_27 = F_7 ( V_8 , 0 ) ;
V_28 = F_16 ( V_8 , 2 ) ;
if ( V_11 ) {
V_26 = F_8 ( V_11 , V_35 , V_8 , 0 , 4 , V_21 ) ;
V_12 = F_17 ( V_26 , V_36 ) ;
F_6 ( V_12 , V_37 , V_8 , 0 , 1 , V_27 ) ;
}
F_18 ( V_8 , V_12 , V_38 , 2 ) ;
F_5 ( V_28 , V_8 , 4 , V_10 , V_11 , V_12 , V_39 ) ;
}
void
F_19 ( void )
{
static T_9 V_40 [] = {
{ & V_37 ,
{ L_6 , L_7 , V_41 , V_42 ,
F_20 ( V_43 ) , 0x0 , NULL , V_44 } } ,
{ & V_39 ,
{ L_8 , L_9 , V_45 , V_42 ,
F_20 ( V_46 ) , 0x0 , NULL , V_44 } } ,
{ & V_20 ,
{ L_10 , L_11 , V_41 , V_42 ,
NULL , 0x0 , NULL , V_44 } } ,
} ;
static T_10 * V_47 [] = {
& V_36 ,
} ;
T_11 * V_48 ;
V_35 = F_21 ( L_12 , L_2 , L_13 ) ;
F_22 ( V_35 , V_40 , F_23 ( V_40 ) ) ;
F_24 ( V_47 , F_23 ( V_47 ) ) ;
V_22 = F_25 ( L_9 ,
L_14 ,
V_45 , V_42 ) ;
F_26 ( L_13 , F_13 , V_35 ) ;
V_48 = F_27 ( V_35 , NULL ) ;
F_28 ( V_48 ,
L_15 ,
L_16 ,
L_17 ,
& V_38 ,
V_49 , V_50 ) ;
}
void
F_29 ( void )
{
T_12 V_51 ;
V_25 = F_30 ( L_18 ) ;
V_51 = F_30 ( L_13 ) ;
F_31 ( L_19 , V_52 , V_51 ) ;
F_31 ( L_19 , V_53 , V_51 ) ;
}
static void
F_32 ( T_4 * V_8 , T_5 * V_10 , T_6 * V_11 )
{
T_7 * V_26 ;
T_6 * V_54 = NULL ;
T_13 V_55 ;
T_13 V_27 ;
T_13 V_56 ;
T_13 V_57 ;
F_14 ( V_10 -> V_23 , V_24 , L_20 ) ;
F_15 ( V_10 -> V_23 , V_29 ) ;
V_55 = F_33 ( V_8 , 0 ) ;
if ( V_11 ) {
V_26 = F_8 ( V_11 , V_58 , V_8 , 0 , 14 , V_21 ) ;
V_54 = F_17 ( V_26 , V_59 ) ;
}
switch ( V_55 ) {
case V_60 :
case V_61 :
V_27 = F_34 ( V_8 , 4 ) ;
F_11 ( V_10 -> V_23 , V_29 , L_21 ,
F_35 ( V_55 , V_62 , L_22 ) ,
F_36 ( V_27 ) , F_37 ( V_8 , 8 ) ) ;
if ( V_11 ) {
F_6 ( V_54 , V_63 , V_8 , 0 , 4 , V_55 ) ;
F_8 ( V_54 , V_64 , V_8 , 4 , 4 , V_50 ) ;
F_8 ( V_54 , V_65 , V_8 , 8 , 4 , V_50 ) ;
}
break;
case V_66 :
V_56 = F_33 ( V_8 , 4 ) ;
V_57 = F_33 ( V_8 , 8 ) ;
F_11 ( V_10 -> V_23 , V_29 ,
L_23 ,
F_35 ( V_55 , V_62 , L_22 ) ,
V_56 , V_57 ) ;
if ( V_11 ) {
F_6 ( V_54 , V_63 , V_8 , 0 , 4 , V_55 ) ;
F_6 ( V_54 , V_67 , V_8 , 4 , 4 ,
V_56 ) ;
F_6 ( V_54 , V_67 , V_8 , 8 , 4 ,
V_57 ) ;
}
break;
default:
F_11 ( V_10 -> V_23 , V_29 , L_24 , V_55 ) ;
if ( V_11 ) {
F_6 ( V_54 , V_63 , V_8 , 0 , 4 , V_55 ) ;
F_12 ( V_25 , F_9 ( V_8 , 4 ) , V_10 ,
V_54 ) ;
}
break;
}
}
void
F_38 ( void )
{
static T_9 V_40 [] = {
{ & V_63 ,
{ L_25 , L_26 , V_68 , V_69 ,
F_20 ( V_62 ) , 0x0 , NULL , V_44 } } ,
{ & V_64 ,
{ L_6 , L_27 , V_70 , V_71 ,
NULL , 0x0 , NULL , V_44 } } ,
{ & V_65 ,
{ L_28 , L_29 , V_70 , V_71 ,
NULL , 0x0 , NULL , V_44 } } ,
{ & V_67 ,
{ L_30 , L_31 , V_68 , V_69 ,
NULL , 0x0 , NULL , V_44 } } ,
#if 0
{ &hf_slarp_yoursequence,
{ "Returned sequence number", "slarp.yoursequence", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
#endif
} ;
static T_10 * V_47 [] = {
& V_59 ,
} ;
V_58 = F_21 ( L_32 , L_20 , L_33 ) ;
F_22 ( V_58 , V_40 , F_23 ( V_40 ) ) ;
F_24 ( V_47 , F_23 ( V_47 ) ) ;
}
void
F_39 ( void )
{
T_12 V_72 ;
V_72 = F_40 ( F_32 , V_58 ) ;
F_31 ( L_9 , V_73 , V_72 ) ;
}
