static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
T_3 V_5 = V_3 + V_4 ;
while ( V_3 < V_5 ) {
T_3 V_6 = V_3 ;
T_5 V_7 ;
T_5 V_8 ;
char * V_9 ;
char * V_10 ;
V_7 = F_2 ( V_1 , V_3 ) ;
if ( ( V_7 & 0x80 ) == 0 ) {
V_3 += 1 ;
} else {
V_7 = F_3 ( V_1 , V_3 ) & 0x7FFFFFFF ;
V_3 += 4 ;
}
V_8 = F_2 ( V_1 , V_3 ) ;
if ( ( V_8 & 0x80 ) == 0 ) {
V_3 += 1 ;
} else {
V_8 = F_3 ( V_1 , V_3 ) & 0x7FFFFFFF ;
V_3 += 4 ;
}
V_9 = F_4 ( F_5 () , V_1 , V_3 , V_7 , V_11 ) ;
V_3 += V_7 ;
if ( V_8 > 0 ) {
V_10 = F_4 ( F_5 () , V_1 , V_3 , V_8 , V_11 ) ;
V_3 += V_8 ;
F_6 ( V_2 , V_12 , V_1 , V_6 , V_3 - V_6 ,
V_9 , L_1 , V_9 , V_10 ) ;
} else {
F_6 ( V_2 , V_12 , V_1 , V_6 , V_3 - V_6 ,
V_9 , L_2 , V_9 ) ;
}
}
}
static int
F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
T_2 * V_13 ;
V_13 = F_8 ( V_2 , V_1 , V_3 , V_4 , V_14 , NULL , L_3 ) ;
F_9 ( V_13 , V_15 , V_1 , V_3 , 2 , V_16 ) ;
V_3 += 2 ;
F_9 ( V_13 , V_17 , V_1 , V_3 , 1 , V_16 ) ;
F_9 ( V_13 , V_18 , V_1 , V_3 , 1 , V_16 ) ;
V_3 += 1 ;
V_3 += 5 ;
return V_3 ;
}
static void
F_10 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
F_8 ( V_2 , V_1 , V_3 , V_4 , V_19 , NULL , L_4 ) ;
return;
}
static int
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
T_2 * V_20 ;
V_20 = F_8 ( V_2 , V_1 , V_3 , V_4 , V_21 , NULL , L_5 ) ;
F_9 ( V_20 , V_22 , V_1 , V_3 , 4 , V_16 ) ;
V_3 += 4 ;
F_9 ( V_20 , V_23 , V_1 , V_3 , 1 , V_16 ) ;
V_3 += 1 ;
V_3 += 3 ;
return V_3 ;
}
static void
F_12 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
T_2 * V_24 ;
V_24 = F_8 ( V_2 , V_1 , V_3 , V_4 , V_25 , NULL , L_6 ) ;
F_1 ( V_1 , V_24 , V_3 , V_4 ) ;
return;
}
static void
F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
T_2 * V_26 ;
V_26 = F_8 ( V_2 , V_1 , V_3 , V_4 , V_25 , NULL , L_7 ) ;
F_1 ( V_1 , V_26 , V_3 , V_4 ) ;
return;
}
static void
F_14 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
T_2 * V_27 ;
V_27 = F_8 ( V_2 , V_1 , V_3 , V_4 , V_25 , NULL , L_7 ) ;
F_1 ( V_1 , V_27 , V_3 , V_4 ) ;
return;
}
static int
F_15 ( T_1 * V_1 , T_6 * V_28 , T_2 * V_29 , void * T_7 V_30 )
{
T_3 V_3 = 0 ;
T_8 type ;
type = F_2 ( V_1 , 1 ) ;
F_16 ( V_28 -> V_31 , V_32 , L_8 ) ;
F_17 ( V_28 -> V_31 , V_33 ) ;
F_18 ( V_28 -> V_31 , V_33 , NULL ,
F_19 ( type , V_34 , L_9 ) ) ;
F_20 ( V_28 -> V_31 , V_33 ) ;
if ( V_29 ) {
T_9 * V_35 ;
T_2 * V_2 ;
T_4 V_36 ;
T_8 V_37 ;
V_35 = F_9 ( V_29 , V_38 , V_1 , 0 , - 1 , V_39 ) ;
F_21 ( V_35 , L_10 ,
F_19 ( type , V_34 , L_9 ) ) ;
V_2 = F_22 ( V_35 , V_40 ) ;
F_9 ( V_2 , V_41 , V_1 , V_3 , 1 , V_16 ) ;
V_3 += 1 ;
F_9 ( V_2 , V_42 , V_1 , V_3 , 1 , V_16 ) ;
V_3 += 1 ;
F_9 ( V_2 , V_43 , V_1 , V_3 , 2 , V_16 ) ;
V_3 += 2 ;
V_36 = F_23 ( V_1 , V_3 ) ;
F_9 ( V_2 , V_44 , V_1 , V_3 , 2 , V_16 ) ;
V_3 += 2 ;
V_37 = F_2 ( V_1 , V_3 ) ;
F_9 ( V_2 , V_45 , V_1 , V_3 , 1 , V_16 ) ;
V_3 += 1 ;
V_3 += 1 ;
switch ( type )
{
case V_46 :
F_7 ( V_1 , V_2 , V_3 , V_36 ) ;
V_3 += V_36 ;
break;
case V_47 :
F_10 ( V_1 , V_2 , V_3 , V_36 ) ;
V_3 += V_36 ;
break;
case V_48 :
F_11 ( V_1 , V_2 , V_3 , V_36 ) ;
V_3 += V_36 ;
break;
case V_49 :
F_12 ( V_1 , V_2 , V_3 , V_36 ) ;
V_3 += V_36 ;
break;
case V_50 :
F_13 ( V_1 , V_2 , V_3 , V_36 ) ;
V_3 += V_36 ;
break;
case V_51 :
F_14 ( V_1 , V_2 , V_3 , V_36 ) ;
V_3 += V_36 ;
break;
default:
if ( V_36 > 0 ) {
F_9 ( V_2 , V_52 , V_1 , V_3 , V_36 , V_39 ) ;
V_3 += V_36 ;
}
break;
}
if ( V_37 > 0 ) {
F_9 ( V_2 , V_53 , V_1 , V_3 , V_37 , V_39 ) ;
}
}
return F_24 ( V_1 ) ;
}
static T_10
F_25 ( T_6 * V_28 V_30 , T_1 * V_1 , int V_3 , void * T_7 V_30 )
{
return 8 + F_23 ( V_1 , V_3 + 4 ) + F_2 ( V_1 , V_3 + 6 ) ;
}
static int
F_26 ( T_1 * V_1 , T_6 * V_28 , T_2 * V_29 , void * T_7 )
{
F_27 ( V_1 , V_28 , V_29 , TRUE , 8 , F_25 , F_15 , T_7 ) ;
return F_24 ( V_1 ) ;
}
void
F_28 ( void )
{
static T_11 V_54 [] = {
{ & V_41 ,
{ L_11 , L_12 ,
V_55 , V_56 , NULL , 0x0 , NULL , V_57 } } ,
{ & V_42 ,
{ L_13 , L_14 ,
V_55 , V_56 , F_29 ( V_34 ) , 0x0 , NULL , V_57 } } ,
{ & V_43 ,
{ L_15 , L_16 ,
V_58 , V_56 , NULL , 0x0 , NULL , V_57 } } ,
{ & V_44 ,
{ L_17 , L_18 ,
V_58 , V_56 , NULL , 0x0 , NULL , V_57 } } ,
{ & V_45 ,
{ L_19 , L_20 ,
V_55 , V_56 , NULL , 0x0 , NULL , V_57 } } ,
{ & V_52 ,
{ L_21 , L_22 ,
V_59 , V_60 , NULL , 0x0 , NULL , V_57 } } ,
{ & V_53 ,
{ L_23 , L_24 ,
V_59 , V_60 , NULL , 0x0 , NULL , V_57 } } ,
{ & V_15 ,
{ L_25 , L_26 ,
V_58 , V_56 , F_29 ( V_61 ) , 0x0 , NULL , V_57 } } ,
{ & V_17 ,
{ L_27 , L_28 ,
V_55 , V_62 , NULL , 0x0 , NULL , V_57 } } ,
{ & V_18 ,
{ L_29 , L_30 ,
V_63 , 8 , NULL , V_64 , NULL , V_57 } } ,
{ & V_22 ,
{ L_31 , L_32 ,
V_65 , V_56 , NULL , 0x0 , NULL , V_57 } } ,
{ & V_23 ,
{ L_33 , L_34 ,
V_65 , V_56 , F_29 ( V_66 ) , 0x0 , NULL , V_57 } } ,
{ & V_12 ,
{ L_35 , L_36 ,
V_67 , V_60 , NULL , 0x0 , NULL , V_57 } } ,
} ;
static T_3 * V_68 [] = {
& V_40 ,
& V_14 ,
& V_19 ,
& V_21 ,
& V_25
} ;
T_12 * V_69 ;
V_38 = F_30 ( L_37 , L_8 , L_38 ) ;
F_31 ( V_38 , V_54 , F_32 ( V_54 ) ) ;
F_33 ( V_68 , F_32 ( V_68 ) ) ;
V_69 = F_34 ( V_38 , V_70 ) ;
F_35 ( V_69 ,
L_39 ,
L_40 ,
L_41 ,
10 ,
& V_71 ) ;
V_72 = F_36 ( L_38 , F_26 , V_38 ) ;
}
void
V_70 ( void )
{
static T_13 V_73 = FALSE ;
static T_10 V_74 ;
if ( ! V_73 ) {
F_37 ( L_39 , V_72 ) ;
V_73 = TRUE ;
} else if ( V_74 != 0 ) {
F_38 ( L_39 , V_74 , V_72 ) ;
}
if ( V_71 != 0 ) {
F_39 ( L_39 , V_71 , V_72 ) ;
}
V_74 = V_71 ;
}
