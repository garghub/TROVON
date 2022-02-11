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
if ( F_9 ( V_18 , V_28 -> V_29 ) ) {
V_21 = F_10 ( V_18 , V_28 , V_1 , 0 , - 1 , V_16 ) ;
V_20 = F_11 ( V_21 , V_30 ) ;
F_10 ( V_20 , & V_31 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
F_10 ( V_20 , & V_32 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
F_10 ( V_20 , & V_33 , V_1 , V_2 , 2 , V_8 ) ;
V_2 += 2 ;
V_21 = F_12 ( V_20 , & V_34 ,
V_1 , V_2 , F_3 ( V_1 , V_2 ) , V_24 ) ;
F_13 ( V_21 ) ;
}
V_2 = V_19 ;
while ( F_3 ( V_1 , V_2 ) >= 4 ) {
T_2 V_3 = F_2 ( V_1 , V_2 + 0 ) ;
T_2 V_4 ;
T_2 V_35 ;
T_4 * V_36 ;
if ( V_3 < 4 )
return;
V_35 = V_3 - 4 ;
V_4 = ( F_2 ( V_1 , V_2 + 2 ) & 0x7fff ) ;
if ( V_20 ) {
T_6 V_37 = FALSE ;
V_21 = F_14 ( V_20 , V_38 . V_29 ,
V_1 , V_2 , V_3 , NULL ,
L_2 ,
F_15 ( V_4 , V_39 , L_3 ) ,
V_4 , V_3 ) ;
V_36 = F_11 ( V_21 , V_40 ) ;
F_10 ( V_36 , & V_41 , V_1 , V_2 + 0 , 2 , V_24 ) ;
F_10 ( V_36 , & V_42 , V_1 , V_2 + 2 , 2 , V_24 ) ;
switch ( V_4 ) {
case V_43 :
V_37 = TRUE ;
break;
case V_44 :
if ( V_35 >= 1 ) {
F_10 ( V_36 , & V_45 ,
V_1 , V_2 + 4 , V_35 , V_16 ) ;
V_37 = TRUE ;
}
break;
case V_46 :
if ( V_35 == 4 ) {
F_10 ( V_36 , & V_47 ,
V_1 , V_2 + 4 , V_35 , V_8 ) ;
V_37 = TRUE ;
}
break;
case V_48 :
if ( V_35 == 4 ) {
F_10 ( V_36 , & V_49 ,
V_1 , V_2 + 4 , V_35 , V_8 ) ;
V_37 = TRUE ;
}
break;
case V_50 :
if ( V_35 == 16 ) {
T_7 V_51 ;
V_51 . V_52 = ( V_53 ) F_16 ( V_1 , V_2 + 4 ) ;
V_51 . V_54 = ( int ) F_16 ( V_1 , V_2 + 12 ) ;
F_17 ( V_36 , & V_55 ,
V_1 , V_2 + 4 , V_35 , & V_51 ) ;
V_37 = TRUE ;
}
break;
}
if ( ! V_37 )
F_10 ( V_36 , & V_56 ,
V_1 , V_2 + 4 , V_35 , V_16 ) ;
}
if ( V_4 == V_43 )
V_22 = F_18 ( V_1 , V_2 + 4 , V_35 , V_35 ) ;
V_2 += ( ( V_3 + 3 ) & ~ 3 ) ;
}
if ( V_22 ) {
switch ( V_23 ) {
case V_57 :
F_19 ( V_58 , V_22 , V_17 , V_18 ) ;
break;
case V_59 :
F_19 ( V_60 , V_22 , V_17 , V_18 ) ;
break;
default:
F_19 ( V_61 , V_22 , V_17 , V_18 ) ;
break;
}
}
}
void
F_20 ( void )
{
static T_8 * V_62 [] = {
& V_31 ,
& V_32 ,
& V_33 ,
& V_34 ,
& V_38 ,
& V_41 ,
& V_42 ,
& V_45 ,
& V_47 ,
& V_49 ,
& V_55 ,
& V_56 ,
} ;
static T_9 * V_63 [] = {
& V_30 ,
& V_40
} ;
T_10 * V_64 ;
int V_65 ;
V_65 = F_21 ( L_4 , L_1 , L_5 ) ;
V_28 = F_22 ( V_65 ) ;
V_64 = F_23 ( V_65 , NULL ) ;
F_24 ( V_64 , L_6 , L_7 , L_7 ,
& V_6 , V_66 , FALSE ) ;
F_25 ( L_5 , F_5 , V_65 ) ;
F_26 ( V_65 , V_62 , F_27 ( V_62 ) ) ;
F_28 ( V_63 , F_27 ( V_63 ) ) ;
}
void
F_29 ( void )
{
T_11 V_67 ;
V_58 = F_30 ( L_8 ) ;
V_60 = F_30 ( L_9 ) ;
V_61 = F_30 ( L_10 ) ;
V_67 = F_30 ( L_5 ) ;
F_31 ( L_11 , V_68 , V_67 ) ;
}
