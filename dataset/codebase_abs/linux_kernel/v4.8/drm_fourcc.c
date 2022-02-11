static char F_1 ( int V_1 )
{
return isascii ( V_1 ) && isprint ( V_1 ) ? V_1 : '?' ;
}
const char * F_2 ( T_1 V_2 )
{
static char V_3 [ 32 ] ;
snprintf ( V_3 , sizeof( V_3 ) ,
L_1 ,
F_1 ( V_2 & 0xff ) ,
F_1 ( ( V_2 >> 8 ) & 0xff ) ,
F_1 ( ( V_2 >> 16 ) & 0xff ) ,
F_1 ( ( V_2 >> 24 ) & 0x7f ) ,
V_2 & V_4 ? L_2 : L_3 ,
V_2 ) ;
return V_3 ;
}
void F_3 ( T_1 V_2 , unsigned int * V_5 ,
int * V_6 )
{
switch ( V_2 ) {
case V_7 :
case V_8 :
case V_9 :
* V_5 = 8 ;
* V_6 = 8 ;
break;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
* V_5 = 15 ;
* V_6 = 16 ;
break;
case V_18 :
case V_19 :
* V_5 = 16 ;
* V_6 = 16 ;
break;
case V_20 :
case V_21 :
* V_5 = 24 ;
* V_6 = 24 ;
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
* V_5 = 24 ;
* V_6 = 32 ;
break;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
* V_5 = 30 ;
* V_6 = 32 ;
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
* V_5 = 32 ;
* V_6 = 32 ;
break;
default:
F_4 ( L_4 ,
F_2 ( V_2 ) ) ;
* V_5 = 0 ;
* V_6 = 0 ;
break;
}
}
int F_5 ( T_1 V_2 )
{
switch ( V_2 ) {
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
return 3 ;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return 2 ;
default:
return 1 ;
}
}
int F_6 ( T_1 V_2 , int V_54 )
{
unsigned int V_5 ;
int V_6 ;
if ( V_54 >= F_5 ( V_2 ) )
return 0 ;
switch ( V_2 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
return 2 ;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return V_54 ? 2 : 1 ;
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
return 1 ;
default:
F_3 ( V_2 , & V_5 , & V_6 ) ;
return V_6 >> 3 ;
}
}
int F_7 ( T_1 V_2 )
{
switch ( V_2 ) {
case V_40 :
case V_41 :
case V_38 :
case V_39 :
return 4 ;
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_44 :
case V_45 :
case V_42 :
case V_43 :
return 2 ;
default:
return 1 ;
}
}
int F_8 ( T_1 V_2 )
{
switch ( V_2 ) {
case V_38 :
case V_39 :
return 4 ;
case V_42 :
case V_43 :
case V_48 :
case V_49 :
return 2 ;
default:
return 1 ;
}
}
int F_9 ( int V_59 , T_1 V_2 , int V_54 )
{
if ( V_54 >= F_5 ( V_2 ) )
return 0 ;
if ( V_54 == 0 )
return V_59 ;
return V_59 / F_7 ( V_2 ) ;
}
int F_10 ( int V_60 , T_1 V_2 , int V_54 )
{
if ( V_54 >= F_5 ( V_2 ) )
return 0 ;
if ( V_54 == 0 )
return V_60 ;
return V_60 / F_8 ( V_2 ) ;
}
