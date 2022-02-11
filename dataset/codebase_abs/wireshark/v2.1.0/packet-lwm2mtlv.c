static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
F_2 ( V_2 , V_4 , V_1 , 0 , 1 , V_5 ) ;
F_2 ( V_2 , V_6 , V_1 , 0 , 1 , V_5 ) ;
F_2 ( V_2 , V_7 , V_1 , 0 , 1 , V_5 ) ;
if ( V_3 -> V_8 == 0 ) {
F_2 ( V_2 , V_9 , V_1 , 0 , 1 , V_5 ) ;
} else {
F_2 ( V_2 , V_10 , V_1 , 0 , 1 , V_5 ) ;
}
F_2 ( V_2 , V_11 , V_1 , 1 , V_3 -> V_12 , V_5 ) ;
if ( V_3 -> V_8 > 0 ) {
F_2 ( V_2 , V_13 , V_1 , 1 + V_3 -> V_12 , V_3 -> V_8 , V_5 ) ;
}
}
static void
F_3 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_14 = NULL ;
T_2 * V_15 = NULL ;
T_5 V_16 = 1 + V_3 -> V_12 + V_3 -> V_8 ;
V_14 = F_2 ( V_2 , V_17 , V_1 , 0 , V_16 , V_18 ) ;
V_15 = F_4 ( V_14 , V_19 ) ;
F_1 ( V_1 , V_15 , V_3 ) ;
}
static T_2 *
F_5 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_5 V_16 = 1 + V_3 -> V_12 + V_3 -> V_8 ;
T_6 * V_20 ;
switch ( V_3 -> type )
{
case V_21 :
return F_6 ( V_2 , V_1 , 0 , V_3 -> V_22 , V_23 , NULL ,
L_1 , V_3 -> V_24 , V_3 -> V_25 ) ;
case V_26 :
V_20 = F_7 ( F_8 () , V_1 , V_16 , V_3 -> V_25 , V_27 ) ;
return F_6 ( V_2 , V_1 , 0 , V_3 -> V_22 , V_28 , NULL ,
L_2 , V_3 -> V_24 , V_20 ) ;
case V_29 :
return F_6 ( V_2 , V_1 , 0 , V_3 -> V_22 , V_30 , NULL ,
L_3 , V_3 -> V_24 , V_3 -> V_25 ) ;
case V_31 :
V_20 = F_7 ( F_8 () , V_1 , V_16 , V_3 -> V_25 , V_27 ) ;
return F_6 ( V_2 , V_1 , 0 , V_3 -> V_22 , V_32 , NULL ,
L_2 , V_3 -> V_24 , V_20 ) ;
}
return NULL ;
}
static void
F_9 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_5 V_16 ;
if ( V_3 -> V_25 == 0 ) return;
V_16 = 1 + V_3 -> V_12 + V_3 -> V_8 ;
F_2 ( V_2 , V_33 , V_1 , V_16 , V_3 -> V_25 , V_27 | V_18 ) ;
switch( V_3 -> V_25 )
{
case 0x01 :
F_2 ( V_2 , V_34 , V_1 , V_16 , V_3 -> V_25 , V_5 ) ;
F_2 ( V_2 , V_35 , V_1 , V_16 , V_3 -> V_25 , V_5 ) ;
break;
case 0x02 :
F_2 ( V_2 , V_34 , V_1 , V_16 , V_3 -> V_25 , V_5 ) ;
break;
case 0x04 :
F_2 ( V_2 , V_34 , V_1 , V_16 , V_3 -> V_25 , V_5 ) ;
F_2 ( V_2 , V_36 , V_1 , V_16 , V_3 -> V_25 , V_5 ) ;
F_2 ( V_2 , V_37 , V_1 , V_16 , V_3 -> V_25 , V_5 ) ;
break;
case 0x08 :
F_2 ( V_2 , V_34 , V_1 , V_16 , V_3 -> V_25 , V_5 ) ;
F_2 ( V_2 , V_38 , V_1 , V_16 , V_3 -> V_25 , V_5 ) ;
F_2 ( V_2 , V_37 , V_1 , V_16 + 4 , V_3 -> V_25 - 4 , V_5 ) ;
break;
}
}
static void
F_10 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_5 V_16 = 1 + V_3 -> V_12 + V_3 -> V_8 ;
if ( V_3 -> type == V_31 || V_3 -> type == V_26 ) {
F_2 ( V_2 , V_39 , V_1 , V_16 , V_3 -> V_25 , V_18 ) ;
F_9 ( V_1 , V_2 , V_3 ) ;
} else {
T_1 * V_40 = F_11 ( V_1 , V_16 , V_3 -> V_25 ) ;
F_12 ( V_40 , V_2 ) ;
}
}
static void
F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_2 * V_41 = NULL ;
V_41 = F_5 ( V_1 , V_2 , V_3 ) ;
F_3 ( V_1 , V_41 , V_3 ) ;
F_10 ( V_1 , V_41 , V_3 ) ;
}
static T_7
F_14 ( T_1 * V_1 , const T_8 V_42 , const T_5 V_43 )
{
switch( V_43 )
{
case 1 :
return F_15 ( V_1 , V_42 ) ;
case 2 :
return F_16 ( V_1 , V_42 ) ;
case 3 :
return F_17 ( V_1 , V_42 ) ;
case 4 :
return F_18 ( V_1 , V_42 ) ;
case 5 :
return F_19 ( V_1 , V_42 ) ;
case 6 :
return F_20 ( V_1 , V_42 ) ;
case 7 :
return F_21 ( V_1 , V_42 ) ;
case 8 :
return F_22 ( V_1 , V_42 ) ;
default:
return 0 ;
}
}
static T_5 F_23 ( T_1 * V_1 , T_3 * V_3 )
{
T_5 V_44 = F_15 ( V_1 , 0 ) ;
V_3 -> type = ( ( V_44 >> 6 ) & 0x03 ) ;
V_3 -> V_12 = ( ( V_44 >> 5 ) & 0x01 ) + 1 ;
V_3 -> V_8 = ( ( V_44 >> 3 ) & 0x03 ) ;
V_3 -> V_25 = ( ( V_44 >> 0 ) & 0x07 ) ;
V_3 -> V_24 = ( T_5 ) F_14 ( V_1 , 1 , V_3 -> V_12 ) ;
if ( V_3 -> V_8 > 0 ) {
V_3 -> V_25 = ( T_5 ) F_14 ( V_1 , 1 + V_3 -> V_12 , V_3 -> V_8 ) ;
}
V_3 -> V_22 = 1 + V_3 -> V_12 + V_3 -> V_8 + V_3 -> V_25 ;
return V_3 -> V_22 ;
}
static void F_12 ( T_1 * V_1 , T_2 * V_2 )
{
T_5 V_43 ;
T_5 V_42 = 0 ;
T_5 V_45 = 0 ;
T_3 V_3 ;
V_43 = F_24 ( V_1 ) ;
while ( V_43 > 0 ) {
T_1 * V_40 = F_11 ( V_1 , V_42 , V_43 ) ;
V_45 = F_23 ( V_40 , & V_3 ) ;
F_13 ( V_40 , V_2 , & V_3 ) ;
V_43 -= V_45 ;
V_42 += V_45 ;
if ( V_45 == 0 )
{
break;
}
}
}
static int
F_25 ( T_1 * V_1 , T_9 * T_10 V_46 , T_2 * V_47 , void * T_11 V_46 )
{
T_2 * V_48 ;
T_4 * V_49 ;
if ( V_47 ) {
V_49 = F_2 ( V_47 , V_50 , V_1 , 0 , - 1 , V_18 ) ;
V_48 = F_4 ( V_49 , V_51 ) ;
F_12 ( V_1 , V_48 ) ;
}
return F_26 ( V_1 ) ;
}
void F_27 ( void )
{
static T_12 V_52 [] = {
{ & V_17 ,
{ L_4 , L_5 ,
V_53 , V_54 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_4 ,
{ L_6 , L_7 ,
V_56 , V_57 , F_28 ( V_58 ) , 0xC0 ,
NULL , V_55 }
} ,
{ & V_6 ,
{ L_8 , L_9 ,
V_56 , V_57 , F_28 ( V_59 ) , 0x20 ,
NULL , V_55 }
} ,
{ & V_7 ,
{ L_10 , L_11 ,
V_56 , V_57 , F_28 ( V_60 ) , 0x18 ,
NULL , V_55 }
} ,
{ & V_9 ,
{ L_12 , L_13 ,
V_56 , V_57 , NULL , 0x07 ,
NULL , V_55 }
} ,
{ & V_10 ,
{ L_14 , L_15 ,
V_56 , V_57 , NULL , 0x07 ,
NULL , V_55 }
} ,
{ & V_11 ,
{ L_16 , L_17 ,
V_61 , V_57 , NULL , 0 ,
NULL , V_55 }
} ,
{ & V_13 ,
{ L_12 , L_18 ,
V_62 , V_57 , NULL , 0 ,
NULL , V_55 }
} ,
{ & V_39 ,
{ L_19 , L_20 ,
V_63 , V_54 , NULL , 0 ,
NULL , V_55 }
} ,
{ & V_33 ,
{ L_21 , L_22 ,
V_64 , V_54 , NULL , 0 ,
NULL , V_55 }
} ,
{ & V_34 ,
{ L_23 , L_24 ,
V_65 , V_57 , NULL , 0 ,
NULL , V_55 }
} ,
{ & V_36 ,
{ L_25 , L_26 ,
V_66 , V_54 , NULL , 0 ,
NULL , V_55 }
} ,
{ & V_38 ,
{ L_27 , L_28 ,
V_67 , V_54 , NULL , 0 ,
NULL , V_55 }
} ,
{ & V_35 ,
{ L_29 , L_30 ,
V_68 , V_54 , NULL , 0 ,
NULL , V_55 }
} ,
{ & V_37 ,
{ L_31 , L_32 ,
V_69 , V_70 , NULL , 0 ,
NULL , V_55 }
} ,
} ;
static T_8 * V_71 [] = {
& V_51 ,
& V_19 ,
& V_32 ,
& V_28 ,
& V_30 ,
& V_23
} ;
V_50 = F_29 (
L_33 ,
L_34 ,
L_35
) ;
F_30 ( V_50 , V_52 , F_31 ( V_52 ) ) ;
F_32 ( V_71 , F_31 ( V_71 ) ) ;
F_33 ( L_35 , F_25 , V_50 ) ;
}
void
F_34 ( void )
{
static T_13 V_72 ;
V_72 = F_35 ( F_25 , V_50 ) ;
F_36 ( L_36 , L_37 , V_72 ) ;
}
