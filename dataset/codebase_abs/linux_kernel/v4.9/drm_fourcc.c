static char F_1 ( int V_1 )
{
return isascii ( V_1 ) && isprint ( V_1 ) ? V_1 : '?' ;
}
T_1 F_2 ( T_1 V_2 , T_1 V_3 )
{
T_1 V_4 ;
switch ( V_2 ) {
case 8 :
V_4 = V_5 ;
break;
case 16 :
if ( V_3 == 15 )
V_4 = V_6 ;
else
V_4 = V_7 ;
break;
case 24 :
V_4 = V_8 ;
break;
case 32 :
if ( V_3 == 24 )
V_4 = V_9 ;
else if ( V_3 == 30 )
V_4 = V_10 ;
else
V_4 = V_11 ;
break;
default:
F_3 ( L_1 ) ;
V_4 = V_9 ;
break;
}
return V_4 ;
}
char * F_4 ( T_1 V_12 )
{
char * V_13 = F_5 ( 32 , V_14 ) ;
snprintf ( V_13 , 32 ,
L_2 ,
F_1 ( V_12 & 0xff ) ,
F_1 ( ( V_12 >> 8 ) & 0xff ) ,
F_1 ( ( V_12 >> 16 ) & 0xff ) ,
F_1 ( ( V_12 >> 24 ) & 0x7f ) ,
V_12 & V_15 ? L_3 : L_4 ,
V_12 ) ;
return V_13 ;
}
void F_6 ( T_1 V_12 , unsigned int * V_3 ,
int * V_2 )
{
char * V_16 ;
switch ( V_12 ) {
case V_5 :
case V_17 :
case V_18 :
* V_3 = 8 ;
* V_2 = 8 ;
break;
case V_6 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
* V_3 = 15 ;
* V_2 = 16 ;
break;
case V_7 :
case V_26 :
* V_3 = 16 ;
* V_2 = 16 ;
break;
case V_8 :
case V_27 :
* V_3 = 24 ;
* V_2 = 24 ;
break;
case V_9 :
case V_28 :
case V_29 :
case V_30 :
* V_3 = 24 ;
* V_2 = 32 ;
break;
case V_10 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
* V_3 = 30 ;
* V_2 = 32 ;
break;
case V_11 :
case V_38 :
case V_39 :
case V_40 :
* V_3 = 32 ;
* V_2 = 32 ;
break;
default:
V_16 = F_4 ( V_12 ) ;
F_7 ( L_5 , V_16 ) ;
F_8 ( V_16 ) ;
* V_3 = 0 ;
* V_2 = 0 ;
break;
}
}
int F_9 ( T_1 V_12 )
{
switch ( V_12 ) {
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
return 3 ;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
return 2 ;
default:
return 1 ;
}
}
int F_10 ( T_1 V_12 , int V_57 )
{
unsigned int V_3 ;
int V_2 ;
if ( V_57 >= F_9 ( V_12 ) )
return 0 ;
switch ( V_12 ) {
case V_58 :
case V_59 :
case V_60 :
case V_61 :
return 2 ;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
return V_57 ? 2 : 1 ;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
return 1 ;
default:
F_6 ( V_12 , & V_3 , & V_2 ) ;
return V_2 >> 3 ;
}
}
int F_11 ( T_1 V_12 )
{
switch ( V_12 ) {
case V_43 :
case V_44 :
case V_41 :
case V_42 :
return 4 ;
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_47 :
case V_48 :
case V_45 :
case V_46 :
return 2 ;
default:
return 1 ;
}
}
int F_12 ( T_1 V_12 )
{
switch ( V_12 ) {
case V_41 :
case V_42 :
return 4 ;
case V_45 :
case V_46 :
case V_51 :
case V_52 :
return 2 ;
default:
return 1 ;
}
}
int F_13 ( int V_62 , T_1 V_12 , int V_57 )
{
if ( V_57 >= F_9 ( V_12 ) )
return 0 ;
if ( V_57 == 0 )
return V_62 ;
return V_62 / F_11 ( V_12 ) ;
}
int F_14 ( int V_63 , T_1 V_12 , int V_57 )
{
if ( V_57 >= F_9 ( V_12 ) )
return 0 ;
if ( V_57 == 0 )
return V_63 ;
return V_63 / F_12 ( V_12 ) ;
}
