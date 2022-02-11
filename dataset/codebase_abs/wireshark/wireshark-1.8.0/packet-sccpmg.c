static void
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 V_3 ;
V_3 = F_2 ( V_1 ) ;
F_3 ( V_2 , V_1 , 0 , V_3 ,
L_1 , V_3 ,
F_4 ( V_3 , L_2 , L_3 ) ) ;
}
static void
F_5 ( T_1 * V_4 , T_2 * V_2 )
{
F_6 ( V_2 , V_5 , V_4 ,
V_6 , V_7 ,
V_8 ) ;
}
static void
F_7 ( T_1 * V_4 , T_2 * V_2 )
{
T_4 V_9 = V_10 ;
if ( V_11 == V_12 ) {
F_6 ( V_2 , V_13 , V_4 ,
V_9 , V_14 , V_15 ) ;
} else if ( V_11 == V_16 ) {
F_6 ( V_2 , V_17 ,
V_4 , V_9 , V_18 , V_15 ) ;
} else {
int * V_19 ;
if ( V_11 == V_20 )
{
V_19 = & V_21 ;
} else {
V_19 = & V_22 ;
}
F_8 ( V_4 , V_9 , V_2 ,
V_23 , * V_19 ,
V_24 ,
V_25 ,
V_26 , 0 , 0 ) ;
V_9 += V_27 ;
}
}
static void
F_9 ( T_1 * V_4 , T_2 * V_2 )
{
T_4 V_9 = 0 ;
if ( V_11 == V_12 || V_11 == V_16 )
V_9 = V_28 ;
else
V_9 = V_29 ;
F_6 ( V_2 , V_30 , V_4 , V_9 ,
V_31 , V_8 ) ;
}
static void
F_10 ( T_1 * V_4 , T_2 * V_2 )
{
T_4 V_9 = 0 ;
if ( V_11 == V_32 )
V_9 = V_33 ;
else
V_9 = V_34 ;
F_6 ( V_2 , V_35 , V_4 ,
V_9 , V_36 , V_8 ) ;
}
static void
F_11 ( T_1 * V_4 , T_5 * V_37 , T_2 * V_2 )
{
T_4 V_38 ;
V_38 = F_12 ( V_4 , V_39 ) ;
F_13 ( V_37 -> V_40 , V_41 , L_4 , F_14 ( V_38 , V_42 , L_5 ) ) ;
if ( V_2 ) {
F_15 ( V_2 , V_43 , V_4 ,
V_39 ,
V_44 , V_38 ) ;
}
switch( V_38 ) {
case V_45 :
case V_46 :
case V_47 :
if ( V_11 != V_20 )
{
F_1 ( V_4 , V_2 ) ;
break;
}
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_5 ( V_4 , V_2 ) ;
F_7 ( V_4 , V_2 ) ;
F_9 ( V_4 , V_2 ) ;
break;
case V_53 :
if ( V_11 != V_20 )
{
F_5 ( V_4 , V_2 ) ;
F_7 ( V_4 , V_2 ) ;
F_9 ( V_4 , V_2 ) ;
F_10 ( V_4 , V_2 ) ;
}
default:
F_1 ( V_4 , V_2 ) ;
}
}
static void
F_16 ( T_1 * V_4 , T_5 * V_37 , T_2 * V_54 )
{
T_6 * V_55 ;
T_2 * V_2 = NULL ;
switch( V_11 ) {
case V_12 :
F_17 ( V_37 -> V_40 , V_56 , L_6 ) ;
break;
case V_20 :
F_17 ( V_37 -> V_40 , V_56 , L_7 ) ;
break;
case V_32 :
F_17 ( V_37 -> V_40 , V_56 , L_8 ) ;
break;
} ;
if ( V_54 ) {
V_55 = F_6 ( V_54 , V_57 , V_4 , 0 ,
- 1 , V_58 ) ;
V_2 = F_18 ( V_55 , V_59 ) ;
}
F_11 ( V_4 , V_37 , V_2 ) ;
}
void
F_19 ( void )
{
static T_7 V_60 [] = {
{ & V_43 ,
{ L_9 , L_10 ,
V_61 , V_62 , F_20 ( V_63 ) , 0x0 ,
NULL , V_64 } } ,
{ & V_5 ,
{ L_11 , L_12 ,
V_61 , V_65 , NULL , 0x0 ,
NULL , V_64 } } ,
{ & V_13 ,
{ L_13 , L_14 ,
V_66 , V_65 , NULL , V_67 ,
NULL , V_64 } } ,
{ & V_17 ,
{ L_13 , L_14 ,
V_66 , V_65 , NULL , 0x0 ,
NULL , V_64 } } ,
{ & V_21 ,
{ L_13 , L_15 ,
V_68 , V_69 , NULL , 0x0 ,
NULL , V_64 } } ,
{ & V_22 ,
{ L_13 , L_16 ,
V_68 , V_69 , NULL , 0x0 ,
NULL , V_64 } } ,
{ & V_24 ,
{ L_17 , L_18 ,
V_70 , V_65 , NULL , V_71 ,
NULL , V_64 } } ,
{ & V_25 ,
{ L_19 , L_20 ,
V_70 , V_65 , NULL , V_72 ,
NULL , V_64 } } ,
{ & V_26 ,
{ L_21 , L_22 ,
V_70 , V_65 , NULL , V_73 ,
NULL , V_64 } } ,
{ & V_30 ,
{ L_23 , L_24 ,
V_61 , V_65 , NULL , V_74 ,
NULL , V_64 } } ,
{ & V_35 ,
{ L_25 , L_26 ,
V_61 , V_65 , NULL , V_75 ,
NULL , V_64 } }
} ;
static T_8 * V_76 [] = {
& V_59 ,
& V_23
} ;
V_57 = F_21 ( L_27 ,
L_28 , L_29 ) ;
F_22 ( V_57 , V_60 , F_23 ( V_60 ) ) ;
F_24 ( V_76 , F_23 ( V_76 ) ) ;
}
void
F_25 ( void )
{
T_9 V_77 ;
V_77 = F_26 ( F_16 , V_57 ) ;
F_27 ( L_30 , V_78 , V_77 ) ;
}
