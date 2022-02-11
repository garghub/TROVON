static int
F_1 ( T_1 * V_1 , int V_2 , T_2 (* F_2)( T_1 * , int ) )
{
while ( F_3 ( V_1 , V_2 ) > 4 ) {
T_2 V_3 = F_2 ( V_1 , V_2 + 0 ) ;
T_2 V_4 ;
if ( V_3 < 4 )
return 0 ;
V_4 = ( F_2 ( V_1 , V_2 + 2 ) & 0x7fff ) ;
if ( V_4 >= 0x100 )
break;
if ( V_4 )
return 1 ;
V_2 += ( ( V_3 + 3 ) & ~ 3 ) ;
}
return 0 ;
}
static int
F_4 ( T_1 * V_1 , int V_5 )
{
switch ( V_6 ) {
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
case V_11 :
return ( V_12 == V_13 ) ?
V_10 :
V_8 ;
}
if ( F_1 ( V_1 , V_5 , V_14 ) )
return V_8 ;
if ( F_1 ( V_1 , V_5 , V_15 ) )
return V_10 ;
return V_16 ;
}
static void
F_5 ( T_1 * V_1 , T_3 * V_17 , T_4 * V_18 )
{
const int V_19 = 4 ;
T_4 * V_20 = NULL ;
T_5 * V_21 ;
int V_2 = 0 ;
T_1 * V_22 = NULL ;
int V_23 ;
int V_24 ;
T_2 (* F_2)( T_1 * , int );
F_6 ( V_17 -> V_25 , V_26 , L_1 ) ;
F_7 ( V_17 -> V_25 , V_27 ) ;
V_23 = F_8 ( V_1 , 0 ) ;
V_24 = F_4 ( V_1 , V_19 ) ;
switch ( V_24 ) {
case V_10 :
F_2 = V_15 ;
break;
case V_8 :
default:
F_2 = V_14 ;
break;
}
if ( F_9 ( V_18 , V_28 ) ) {
V_21 = F_10 ( V_18 , V_28 , V_1 , 0 , - 1 , V_16 ) ;
V_20 = F_11 ( V_21 , V_29 ) ;
F_10 ( V_20 , V_30 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
F_10 ( V_20 , V_31 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
F_10 ( V_20 , V_32 , V_1 , V_2 , 2 , V_8 ) ;
V_2 += 2 ;
V_21 = F_12 ( V_20 , V_33 ,
V_1 , V_2 , F_3 ( V_1 , V_2 ) , V_24 ) ;
F_13 ( V_21 ) ;
}
V_2 = V_19 ;
while ( F_3 ( V_1 , V_2 ) >= 4 ) {
T_2 V_3 = F_2 ( V_1 , V_2 + 0 ) ;
T_2 V_4 ;
T_2 V_34 ;
T_4 * V_35 ;
if ( V_3 < 4 )
return;
V_34 = V_3 - 4 ;
V_4 = ( F_2 ( V_1 , V_2 + 2 ) & 0x7fff ) ;
if ( V_20 ) {
T_6 V_36 = FALSE ;
V_21 = F_14 ( V_20 , V_37 ,
V_1 , V_2 , V_3 , NULL ,
L_2 ,
F_15 ( V_4 , V_38 , L_3 ) ,
V_4 , V_3 ) ;
V_35 = F_11 ( V_21 , V_39 ) ;
F_10 ( V_35 , V_40 , V_1 , V_2 + 0 , 2 , V_24 ) ;
F_10 ( V_35 , V_41 , V_1 , V_2 + 2 , 2 , V_24 ) ;
switch ( V_4 ) {
case V_42 :
V_36 = TRUE ;
break;
case V_43 :
if ( V_34 >= 1 ) {
F_10 ( V_35 , V_44 ,
V_1 , V_2 + 4 , V_34 , V_16 ) ;
V_36 = TRUE ;
}
break;
case V_45 :
if ( V_34 == 4 ) {
F_10 ( V_35 , V_46 ,
V_1 , V_2 + 4 , V_34 , V_8 ) ;
V_36 = TRUE ;
}
break;
case V_47 :
if ( V_34 == 4 ) {
F_10 ( V_35 , V_48 ,
V_1 , V_2 + 4 , V_34 , V_8 ) ;
V_36 = TRUE ;
}
break;
case V_49 :
if ( V_34 == 16 ) {
T_7 V_50 ;
V_50 . V_51 = F_16 ( V_1 , V_2 + 4 ) ;
V_50 . V_52 = ( int ) F_16 ( V_1 , V_2 + 12 ) ;
F_17 ( V_35 , V_53 ,
V_1 , V_2 + 4 , V_34 , & V_50 ) ;
V_36 = TRUE ;
}
break;
}
if ( ! V_36 )
F_10 ( V_35 , V_54 ,
V_1 , V_2 + 4 , V_34 , V_16 ) ;
}
if ( V_4 == V_42 )
V_22 = F_18 ( V_1 , V_2 + 4 , V_34 , V_34 ) ;
V_2 += ( ( V_3 + 3 ) & ~ 3 ) ;
}
if ( V_22 ) {
switch ( V_23 ) {
case V_55 :
F_19 ( V_56 , V_22 , V_17 , V_18 ) ;
break;
case V_57 :
F_19 ( V_58 , V_22 , V_17 , V_18 ) ;
break;
default:
F_19 ( V_59 , V_22 , V_17 , V_18 ) ;
break;
}
}
}
void
F_20 ( void )
{
static T_8 V_60 [] = {
{ & V_30 ,
{ L_4 , L_5 , V_61 , V_62 , F_21 ( V_63 ) , 0x00 , NULL , V_64 }
} ,
{ & V_31 ,
{ L_6 , L_7 , V_61 , V_62 , NULL , 0x00 , NULL , V_64 }
} ,
{ & V_32 ,
{ L_8 , L_9 , V_65 , V_62 , NULL , 0x00 , NULL , V_64 }
} ,
{ & V_33 ,
{ L_10 , L_11 , V_66 , V_67 , F_21 ( V_68 ) , 0x00 , NULL , V_64 }
} ,
{ & V_37 ,
{ L_12 , L_13 , V_69 , V_70 , NULL , 0x00 , NULL , V_64 }
} ,
{ & V_40 ,
{ L_14 , L_15 , V_65 , V_62 , NULL , 0x00 , L_16 , V_64 }
} ,
{ & V_41 ,
{ L_17 , L_18 , V_65 , V_62 , F_21 ( V_38 ) , 0x7fff , L_19 , V_64 }
} ,
{ & V_44 ,
{ L_20 , L_21 , V_71 , V_70 , NULL , 0x00 , L_22 , V_64 }
} ,
{ & V_46 ,
{ L_23 , L_24 , V_72 , V_62 , NULL , 0x00 , L_25 , V_64 }
} ,
{ & V_48 ,
{ L_26 , L_27 , V_72 , V_62 , NULL , 0x00 , L_28 , V_64 }
} ,
{ & V_53 ,
{ L_29 , L_30 , V_73 , V_74 , NULL , 0x00 , L_31 , V_64 }
} ,
{ & V_54 ,
{ L_32 , L_33 , V_69 , V_70 , NULL , 0x00 , L_34 , V_64 }
} ,
} ;
static T_9 * V_75 [] = {
& V_29 ,
& V_39
} ;
T_10 * V_76 ;
V_28 = F_22 ( L_35 , L_1 , L_36 ) ;
V_76 = F_23 ( V_28 , NULL ) ;
F_24 ( V_76 , L_37 , L_38 , L_38 ,
& V_6 , V_77 , FALSE ) ;
F_25 ( L_36 , F_5 , V_28 ) ;
F_26 ( V_28 , V_60 , F_27 ( V_60 ) ) ;
F_28 ( V_75 , F_27 ( V_75 ) ) ;
}
void
F_29 ( void )
{
T_11 V_78 ;
V_56 = F_30 ( L_39 ) ;
V_58 = F_30 ( L_40 ) ;
V_59 = F_30 ( L_41 ) ;
V_78 = F_30 ( L_36 ) ;
F_31 ( L_42 , V_79 , V_78 ) ;
}
