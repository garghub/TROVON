static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
T_3 * V_5 = NULL ;
T_4 * V_6 ;
T_5 V_7 ;
T_5 V_8 ;
T_6 V_9 ;
T_7 V_10 = 0 ;
T_8 V_11 = FALSE ;
F_2 ( V_2 -> V_12 , V_13 , L_1 ) ;
F_3 ( V_2 -> V_12 , V_14 ) ;
V_7 = F_4 ( V_1 , 0 ) ;
V_8 = F_4 ( V_1 , 1 ) ;
F_2 ( V_2 -> V_12 , V_13 ,
F_5 ( V_8 , V_15 , L_1 ) ) ;
F_6 ( V_2 -> V_12 , V_14 ,
F_7 ( V_7 , V_16 , L_2 ) ) ;
if ( V_3 ) {
V_6 = F_8 ( V_3 , V_17 , V_1 , 0 , - 1 , V_18 ) ;
V_5 = F_9 ( V_6 , V_19 ) ;
F_10 ( V_5 , & V_20 , V_1 , 0 , 1 , V_7 ) ;
F_10 ( V_5 , & V_21 , V_1 , 1 , 1 , V_8 ) ;
if ( V_8 == V_22 && V_23 == TRUE )
F_10 ( V_5 , & V_24 , V_1 , 2 , 2 ,
F_11 ( V_1 , 2 ) ) ;
V_4 = V_25 ;
while ( F_12 ( V_1 , V_4 ) > V_10 ) {
V_9 = F_11 ( V_1 , V_4 ) ;
switch ( V_9 ) {
case V_26 :
F_13 ( V_1 , V_4 , V_8 , V_5 ) ;
break;
case V_27 :
F_14 ( V_1 , V_4 , V_8 , V_5 ) ;
break;
case 0xFFFF :
if( V_4 == V_25 ) {
V_10 = F_15 ( V_1 , V_4 , V_5 ) ;
V_11 = TRUE ;
break;
}
if( V_11 && F_12 ( V_1 , V_4 ) == 20 )
break;
default:
F_16 ( V_5 , V_2 , & V_28 , V_1 , V_4 ,
V_29 , L_3 , V_9 ) ;
break;
}
V_4 += V_29 ;
}
}
}
static void
F_13 ( T_1 * V_1 , int V_4 , T_5 V_8 ,
T_3 * V_3 )
{
T_3 * V_30 ;
T_9 V_31 ;
V_31 = F_17 ( V_1 , V_4 + 16 ) ;
V_30 = F_18 ( V_3 , V_1 , V_4 ,
V_29 , V_32 , NULL , L_4 ,
V_31 ) ;
F_8 ( V_30 , & V_33 , V_1 , V_4 , 2 , V_34 ) ;
if ( V_8 == V_22 ) {
F_8 ( V_30 , & V_35 , V_1 , V_4 + 2 , 2 ,
V_34 ) ;
F_8 ( V_30 , & V_36 , V_1 , V_4 + 8 , 4 ,
V_34 ) ;
F_8 ( V_30 , & V_37 , V_1 , V_4 + 12 , 4 ,
V_34 ) ;
}
F_10 ( V_30 , & V_38 , V_1 ,
V_4 + 16 , 4 , V_31 ) ;
}
static void
F_14 ( T_1 * V_1 , int V_4 , T_5 V_8 ,
T_3 * V_3 )
{
T_3 * V_30 ;
T_9 V_31 ;
V_31 = F_17 ( V_1 , V_4 + 16 ) ;
V_30 = F_18 ( V_3 , V_1 , V_4 ,
V_29 , V_32 , NULL , L_5 ,
F_19 ( V_1 , V_4 + 4 ) , V_31 ) ;
F_8 ( V_30 , & V_33 , V_1 , V_4 , 2 , V_34 ) ;
if ( V_8 == V_22 ) {
F_8 ( V_30 , & V_35 , V_1 , V_4 + 2 , 2 ,
V_34 ) ;
}
F_8 ( V_30 , & V_39 , V_1 , V_4 + 4 , 4 , V_34 ) ;
if ( V_8 == V_22 ) {
F_8 ( V_30 , & V_36 , V_1 , V_4 + 8 , 4 ,
V_34 ) ;
F_8 ( V_30 , & V_37 , V_1 , V_4 + 12 , 4 ,
V_34 ) ;
}
F_10 ( V_30 , & V_38 , V_1 ,
V_4 + 16 , 4 , V_31 ) ;
}
static T_7
F_15 ( T_1 * V_1 , int V_4 , T_3 * V_3 )
{
T_3 * V_40 ;
T_6 V_41 ;
T_9 V_42 , V_43 ;
V_43 = 0 ;
V_41 = F_11 ( V_1 , V_4 + 2 ) ;
V_40 = F_18 ( V_3 , V_1 , V_4 , V_29 ,
V_32 , NULL , L_6 , F_7 ( V_41 , V_44 , L_7 ) ) ;
F_10 ( V_40 , & V_45 , V_1 , V_4 + 2 , 2 ,
V_41 ) ;
switch ( V_41 ) {
case V_46 :
F_8 ( V_40 , & V_47 ,
V_1 , V_4 + 4 , 16 , V_48 | V_18 ) ;
break;
case V_49 :
V_42 = F_11 ( V_1 , V_4 + 4 ) ;
F_8 ( V_40 , & V_50 , V_1 , V_4 + 4 , 2 , V_34 ) ;
F_8 ( V_40 , & V_51 , V_1 , V_4 + 6 , 1 , V_18 ) ;
V_43 = F_4 ( V_1 , V_4 + 7 ) ;
F_8 ( V_40 , & V_52 , V_1 , V_4 + 7 , 1 , V_18 ) ;
F_8 ( V_40 , & V_53 , V_1 , V_4 + 8 , 4 , V_34 ) ;
F_8 ( V_40 , & V_54 , V_1 , V_4 + 12 , 8 , V_18 ) ;
V_40 = F_20 ( V_40 , V_1 , V_4 - 4 + V_42 ,
V_55 + 4 , V_56 , NULL , L_8 ) ;
F_8 ( V_40 , & V_57 , V_1 , V_4 - 4 + V_42 + 4 ,
V_55 , V_18 ) ;
break;
}
return V_43 ;
}
void
F_21 ( void )
{
#ifndef F_22
static T_10 * V_58 [] = {
& V_20 ,
& V_21 ,
& V_24 ,
& V_39 ,
& V_36 ,
& V_37 ,
& V_38 ,
& V_45 ,
& V_47 ,
& V_33 ,
& V_35 ,
& V_54 ,
& V_50 ,
& V_51 ,
& V_52 ,
& V_53 ,
& V_57 ,
} ;
#endif
static T_7 * V_59 [] = {
& V_19 ,
& V_32 ,
& V_56 ,
} ;
static T_11 V_60 [] = {
{ & V_28 , { L_9 , V_61 , V_62 , L_10 , V_63 } } ,
} ;
T_12 * V_64 ;
T_13 * V_65 ;
int V_66 ;
V_66 = F_23 ( L_11 , L_1 , L_12 ) ;
V_17 = F_24 ( V_66 ) ;
F_25 ( V_66 , V_58 , F_26 ( V_58 ) ) ;
F_27 ( V_59 , F_26 ( V_59 ) ) ;
V_64 = F_28 ( V_66 ) ;
F_29 ( V_64 , V_60 , F_26 ( V_60 ) ) ;
V_65 = F_30 ( V_66 , V_67 ) ;
F_31 ( V_65 , L_13 , L_14 , L_15 , & V_23 ) ;
V_68 = F_32 ( F_1 , V_66 ) ;
}
void
V_67 ( void )
{
F_33 ( L_16 , V_69 , V_68 ) ;
}
