static void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 ,
T_3 * V_5 , T_4 * V_6 , T_5 type )
{
switch ( type ) {
case V_7 :
if ( V_4 > 0 ) {
F_2 ( V_5 , V_8 , V_1 , V_3 , V_4 , V_9 | V_10 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_1 , V_4 ) ;
}
break;
case V_12 :
if ( V_4 > 0 ) {
F_2 ( V_5 , V_13 , V_1 , V_3 , V_4 , V_9 | V_10 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_2 , V_4 ) ;
}
break;
case V_14 :
if ( V_4 > 0 ) {
F_2 ( V_5 , V_15 , V_1 , V_3 , V_4 , V_9 | V_10 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_3 , V_4 ) ;
}
break;
case V_16 :
if ( V_4 == 6 ) {
F_2 ( V_5 , V_17 , V_1 , V_3 , V_4 , V_9 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_4 , V_4 ) ;
}
break;
case V_18 :
if ( V_4 == 4 ) {
F_2 ( V_5 , V_19 , V_1 , V_3 , V_4 , V_20 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_5 , V_4 ) ;
}
break;
case V_21 :
if ( V_4 == 2 ) {
F_2 ( V_5 , V_22 , V_1 , V_3 , V_4 , V_20 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_6 , V_4 ) ;
}
break;
case V_23 :
if ( V_4 > 0 ) {
F_2 ( V_5 , V_24 , V_1 , V_3 , V_4 , V_9 | V_10 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_7 , V_4 ) ;
}
break;
case V_25 :
if ( V_4 == 2 ) {
F_2 ( V_5 , V_26 , V_1 , V_3 , V_4 , V_20 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_8 , V_4 ) ;
}
break;
case V_27 :
if ( V_4 == 2 ) {
F_2 ( V_5 , V_28 , V_1 , V_3 , V_4 , V_20 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_9 , V_4 ) ;
}
break;
case V_29 :
if ( V_4 == 4 ) {
F_2 ( V_5 , V_30 , V_1 , V_3 , V_4 , V_20 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_10 , V_4 ) ;
}
break;
case V_31 :
if ( ! ( V_4 % 6 ) )
{ int V_32 = V_4 / 6 ;
F_4 ( V_6 , L_11 , V_32 ) ;
for ( ; V_32 ; V_32 -- )
{
F_2 ( V_5 , V_33 , V_1 , V_3 , V_4 , V_9 ) ;
V_3 += 6 ;
}
} else {
F_3 ( V_2 , V_6 , & V_11 , L_12 , V_4 ) ;
}
break;
case V_34 :
if ( V_4 == 1 ) {
F_2 ( V_5 , V_35 , V_1 , V_3 , V_4 , V_9 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_13 , V_4 ) ;
}
break;
case V_36 :
if ( V_4 > 6 ) {
F_2 ( V_5 , V_37 , V_1 , V_3 , 6 , V_9 ) ;
F_2 ( V_5 , V_38 , V_1 , V_3 + 6 , V_4 - 6 , V_9 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_14 , V_4 ) ;
}
break;
case V_39 :
if ( V_4 == 6 ) {
F_2 ( V_5 , V_40 , V_1 , V_3 , V_4 , V_9 ) ;
} else {
F_3 ( V_2 , V_6 , & V_11 , L_15 , V_4 ) ;
}
break;
default:
F_5 ( V_5 , V_1 , V_3 , V_4 , L_16 ) ;
break;
}
}
static void
F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_5 )
{
T_3 * V_41 = NULL ;
T_3 * V_42 = NULL ;
T_4 * V_6 = NULL ;
T_5 V_43 ;
F_7 ( V_2 -> V_44 , V_45 , L_17 ) ;
F_7 ( V_2 -> V_44 , V_46 , L_18 ) ;
V_43 = F_8 ( V_1 , 0 ) ;
if ( V_5 ) {
T_6 V_3 = 0 ;
V_6 = F_2 ( V_5 , V_47 , V_1 , 0 , - 1 , V_9 ) ;
V_41 = F_9 ( V_6 , V_48 ) ;
F_10 ( V_41 , V_49 , V_1 , 0 , 1 , V_43 ) ;
V_3 ++ ;
F_2 ( V_41 , V_50 , V_1 , 1 , 1 , V_20 ) ;
V_3 ++ ;
while ( F_11 ( V_1 , V_3 ) > 0 )
{
T_5 type , V_4 ;
type = F_8 ( V_1 , V_3 ) ;
V_4 = F_8 ( V_1 , V_3 + 1 ) ;
if ( ( V_4 < 1 ) || ( V_4 > F_12 ( V_1 , V_3 + 2 ) ) )
break;
V_6 = F_5 ( V_41 , V_1 , V_3 , V_4 + 2 , L_19 ,
F_13 ( type , V_51 , L_20 ) ) ;
V_42 = F_9 ( V_6 , V_52 ) ;
F_10 ( V_42 , V_53 , V_1 , V_3 , 1 , type ) ;
V_3 ++ ;
F_10 ( V_42 , V_54 , V_1 , V_3 , 1 , V_4 ) ;
V_3 ++ ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_42 , V_6 , type ) ;
V_3 += V_4 ;
}
}
}
void
F_14 ( void )
{
static T_7 V_55 [] = {
{ & V_49 ,
{ L_21 , L_22 , V_56 , V_57 ,
NULL , 0x0 , NULL , V_58 } } ,
{ & V_50 ,
{ L_23 , L_24 , V_56 , V_57 ,
NULL , 0x0 , NULL , V_58 } } ,
{ & V_53 ,
{ L_23 , L_25 , V_56 , V_57 ,
F_15 ( V_51 ) , 0x0 , NULL , V_58 } } ,
{ & V_54 ,
{ L_26 , L_27 , V_56 , V_59 ,
NULL , 0x0 , NULL , V_58 } } ,
{ & V_8 , { L_28 , L_29 , V_60 , V_61 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_13 , { L_21 , L_30 , V_60 , V_61 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_15 , { L_31 , L_32 , V_60 , V_61 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_17 , { L_33 , L_34 , V_62 , V_61 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_19 , { L_35 , L_36 , V_63 , V_61 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_22 , { L_37 , L_38 , V_64 , V_57 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_24 , { L_39 , L_40 , V_60 , V_61 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_26 , { L_41 , L_42 , V_64 , V_57 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_28 , { L_43 , L_44 , V_64 , V_57 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_30 , { L_45 , L_46 , V_65 , V_57 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_33 , { L_47 , L_48 , V_62 , V_61 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_35 , { L_49 , L_50 , V_56 , V_57 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_40 , { L_51 , L_52 , V_62 , V_61 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_37 , { L_53 , L_54 , V_62 , V_61 , NULL , 0x0 , NULL , V_58 } } ,
{ & V_38 , { L_16 , L_55 , V_66 , V_61 , NULL , 0x0 , NULL , V_58 } } ,
} ;
static T_8 * V_67 [] = {
& V_48 ,
& V_52
} ;
static T_9 V_68 [] = {
{ & V_11 , { L_56 , V_69 , V_70 , L_57 , V_71 } } ,
} ;
T_10 * V_72 ;
V_47 = F_16 ( L_18 , L_58 , L_59 ) ;
F_17 ( V_47 , V_55 , F_18 ( V_55 ) ) ;
F_19 ( V_67 , F_18 ( V_67 ) ) ;
V_72 = F_20 ( V_47 ) ;
F_21 ( V_72 , V_68 , F_18 ( V_68 ) ) ;
F_22 ( L_59 , F_6 , V_47 ) ;
}
void
F_23 ( void )
{
T_11 V_73 ;
V_73 = F_24 ( L_59 ) ;
F_25 ( L_60 , V_74 , V_73 ) ;
}
