int F_1 ( unsigned int V_1 )
{
unsigned long V_2 ;
if ( V_1 > V_3 - 1 )
return - V_4 ;
F_2 ( & V_5 , V_2 ) ;
F_3 ( & V_6 -> V_7 . V_8 , V_9 ,
V_1 << V_10 ) ;
F_4 ( & V_5 , V_2 ) ;
return 0 ;
}
int F_5 ( unsigned int V_1 , enum V_11 V_12 )
{
T_1 T_2 * V_13 ;
switch ( V_1 ) {
case 0 : V_13 = & V_6 -> V_14 . V_15 . V_13 ;
break;
case 1 : V_13 = & V_6 -> V_16 . V_15 . V_13 ;
break;
case 2 : V_13 = & V_6 -> V_17 . V_15 . V_13 ;
break;
case 3 : V_13 = & V_6 -> V_18 . V_15 . V_13 ;
break;
case 4 : V_13 = & V_6 -> V_19 . V_15 . V_13 ;
break;
case 5 : V_13 = & V_6 -> V_20 . V_15 . V_13 ;
break;
case 6 : V_13 = & V_6 -> V_21 . V_15 . V_13 ;
break;
case 7 : V_13 = & V_6 -> V_22 . V_15 . V_13 ;
break;
default:
return - V_4 ;
}
F_6 ( V_13 , V_23 ,
V_24 | V_12 ) ;
return 0 ;
}
static void F_7 ( unsigned int V_1 , T_3 T_2 * * V_25 ,
unsigned int * V_26 , unsigned int * V_27 )
{
unsigned int V_28 = ( ( V_1 & 1 ) << 1 ) + ( V_1 > 3 ) ;
* V_26 = V_28 + 1 ;
* V_25 = & V_6 -> V_7 . V_25 [ V_28 ] ;
* V_27 = 16 - 8 * ( V_1 & 2 ) ;
}
int F_8 ( unsigned int V_1 , int V_29 , T_4 V_30 )
{
T_3 T_2 * V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
if ( V_1 > V_3 - 1 )
return - V_4 ;
F_7 ( V_1 , & V_25 , & V_26 , & V_27 ) ;
if ( V_29 )
F_9 ( V_25 , V_30 << V_27 ) ;
else
F_10 ( V_25 , V_30 << V_27 ) ;
return 0 ;
}
int F_11 ( unsigned int V_1 , enum V_31 clock ,
enum V_32 V_33 )
{
T_3 T_2 * V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
T_4 V_34 = 0 ;
if ( V_1 > V_3 - 1 )
return - V_4 ;
if ( ! ( ( V_33 == V_35 ) || ( V_33 == V_36 ) ) )
return - V_4 ;
F_7 ( V_1 , & V_25 , & V_26 , & V_27 ) ;
switch ( V_26 ) {
case 1 :
switch ( clock ) {
case V_37 : V_34 = 1 ; break;
case V_38 : V_34 = 2 ; break;
case V_39 : V_34 = 3 ; break;
case V_40 : V_34 = 4 ; break;
case V_41 : V_34 = 5 ; break;
case V_42 : V_34 = 6 ; break;
case V_43 : V_34 = 7 ; break;
case V_44 : V_34 = 8 ; break;
case V_45 : V_34 = 9 ; break;
case V_46 : V_34 = 10 ; break;
default: break;
}
break;
case 2 :
switch ( clock ) {
case V_47 : V_34 = 1 ; break;
case V_48 : V_34 = 2 ; break;
case V_39 : V_34 = 3 ; break;
case V_40 : V_34 = 4 ; break;
case V_49 : V_34 = 5 ; break;
case V_50 : V_34 = 6 ; break;
case V_51 : V_34 = 7 ; break;
case V_52 : V_34 = 8 ; break;
case V_45 : V_34 = 9 ; break;
case V_46 : V_34 = 10 ; break;
default: break;
}
break;
case 3 :
switch ( clock ) {
case V_53 : V_34 = 1 ; break;
case V_54 : V_34 = 2 ; break;
case V_55 : V_34 = 3 ; break;
case V_56 : V_34 = 4 ; break;
case V_57 : V_34 = 5 ; break;
case V_58 : V_34 = 6 ; break;
case V_59 : V_34 = 7 ; break;
case V_60 : V_34 = 8 ; break;
case V_61 : V_34 = 9 ; break;
case V_62 : V_34 = 10 ; break;
case V_46 : V_34 = 11 ; break;
default: break;
}
break;
case 4 :
switch ( clock ) {
case V_63 : V_34 = 1 ; break;
case V_64 : V_34 = 2 ; break;
case V_55 : V_34 = 3 ; break;
case V_56 : V_34 = 4 ; break;
case V_65 : V_34 = 5 ; break;
case V_66 : V_34 = 6 ; break;
case V_67 : V_34 = 7 ; break;
case V_68 : V_34 = 8 ; break;
case V_61 : V_34 = 9 ; break;
case V_62 : V_34 = 10 ; break;
case V_46 : V_34 = 11 ; break;
default: break;
}
break;
default: break;
}
if ( ! V_34 )
return - V_69 ;
if ( V_33 == V_35 )
V_27 += 4 ;
F_3 ( V_25 , V_70 << V_27 ,
V_34 << V_27 ) ;
return 0 ;
}
