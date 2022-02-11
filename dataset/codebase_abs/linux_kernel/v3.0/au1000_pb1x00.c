static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = V_4 | V_5 ;
F_2 ( 0x8000 , V_6 ) ;
F_3 ( 100 ) ;
F_2 ( 0x4000 , V_6 ) ;
F_4 () ;
V_3 |= F_5 ( V_7 , V_8 , 0 ) ;
V_3 |= F_5 ( V_7 , V_8 , 1 ) ;
F_2 ( V_3 , V_9 ) ;
F_3 ( 20 ) ;
return V_10 ;
}
static int F_6 ( void )
{
T_1 V_3 ;
V_3 = V_4 | V_5 ;
V_3 |= F_5 ( V_7 , V_8 , 0 ) ;
V_3 |= F_5 ( V_7 , V_8 , 1 ) ;
F_2 ( V_3 , V_9 ) ;
F_3 ( 20 ) ;
return 0 ;
}
static int
F_7 ( unsigned V_11 , struct V_12 * V_13 )
{
T_2 V_14 , V_15 ;
T_1 V_16 , V_17 ;
V_16 = V_17 = ( T_1 ) F_8 ( V_18 ) ;
V_14 = ! ( V_16 & ( V_19 | V_20 ) ) ;
V_15 = ! ( V_17 & ( V_21 | V_22 ) ) ;
V_16 = ( V_16 >> 4 ) & 0x3 ;
V_17 = ( V_17 >> 12 ) & 0x3 ;
V_13 -> V_23 = 0 ;
V_13 -> V_24 = 0 ;
V_13 -> V_25 = 0 ;
V_13 -> V_26 = 0 ;
if ( V_11 == 0 ) {
if ( V_14 ) {
switch ( V_16 ) {
case 0 :
case 2 :
V_13 -> V_25 = 1 ;
break;
case 3 :
break;
default:
F_9 ( V_27 L_1 ,
V_16 ) ;
return 0 ;
}
V_13 -> V_26 = 1 ;
}
}
else {
if ( V_15 ) {
switch ( V_17 ) {
case 0 :
case 2 :
V_13 -> V_25 = 1 ;
break;
case 3 :
break;
default:
F_9 ( V_27 L_1 ,
V_17 ) ;
return 0 ;
}
V_13 -> V_26 = 1 ;
}
}
if ( V_13 -> V_26 ) {
V_13 -> V_23 = 1 ;
}
V_13 -> V_28 = 1 ;
V_13 -> V_29 = 1 ;
V_13 -> V_30 = 0 ;
return 1 ;
}
static int F_10 ( struct V_31 * V_32 )
{
if( V_32 -> V_11 > V_33 ) return - 1 ;
V_32 -> V_34 = V_35 ;
return 0 ;
}
static int
F_11 ( const struct V_36 * V_37 )
{
T_1 V_3 ;
if( V_37 -> V_11 > V_33 ) return - 1 ;
V_3 = F_8 ( V_9 ) ;
if ( V_37 -> V_11 == 0 ) {
V_3 &= ~ ( V_38 | V_39 |
V_40 | V_41 ) ;
}
else {
V_3 &= ~ ( V_42 | V_43 |
V_44 | V_45 ) ;
}
V_3 &= ~ V_4 ;
F_12 ( L_2 ,
V_37 -> V_46 , V_37 -> V_47 , V_3 ) ;
switch( V_37 -> V_46 ) {
case 0 :
switch( V_37 -> V_47 ) {
case 0 :
V_3 |= F_5 ( V_7 , V_48 ,
V_37 -> V_11 ) ;
break;
case 12 :
V_3 |= F_5 ( V_7 , V_49 ,
V_37 -> V_11 ) ;
break;
case 50 :
V_3 |= F_5 ( V_7 , V_50 ,
V_37 -> V_11 ) ;
break;
case 33 :
V_3 |= F_5 ( V_7 , V_51 ,
V_37 -> V_11 ) ;
break;
default:
V_3 |= F_5 ( V_7 , V_8 ,
V_37 -> V_11 ) ;
F_9 ( L_3 ,
V_52 ,
V_37 -> V_46 ,
V_37 -> V_47 ) ;
break;
}
break;
case 50 :
switch( V_37 -> V_47 ) {
case 0 :
V_3 |= F_5 ( V_53 , V_48 ,
V_37 -> V_11 ) ;
break;
case 50 :
V_3 |= F_5 ( V_53 , V_50 ,
V_37 -> V_11 ) ;
break;
case 12 :
V_3 |= F_5 ( V_53 , V_49 ,
V_37 -> V_11 ) ;
break;
case 33 :
V_3 |= F_5 ( V_53 , V_51 ,
V_37 -> V_11 ) ;
break;
default:
V_3 |= F_5 ( V_7 , V_8 ,
V_37 -> V_11 ) ;
F_9 ( L_3 ,
V_52 ,
V_37 -> V_46 ,
V_37 -> V_47 ) ;
break;
}
break;
case 33 :
switch( V_37 -> V_47 ) {
case 0 :
V_3 |= F_5 ( V_54 , V_48 ,
V_37 -> V_11 ) ;
break;
case 50 :
V_3 |= F_5 ( V_54 , V_50 ,
V_37 -> V_11 ) ;
break;
case 12 :
V_3 |= F_5 ( V_54 , V_49 ,
V_37 -> V_11 ) ;
break;
case 33 :
V_3 |= F_5 ( V_54 , V_51 ,
V_37 -> V_11 ) ;
break;
default:
V_3 |= F_5 ( V_7 , V_8 ,
V_37 -> V_11 ) ;
F_9 ( L_3 ,
V_52 ,
V_37 -> V_46 ,
V_37 -> V_47 ) ;
break;
}
break;
default:
V_3 |= F_5 ( V_7 , V_8 , V_37 -> V_11 ) ;
F_9 ( V_27 L_4 ,
V_52 , V_37 -> V_46 ) ;
break;
}
if ( V_37 -> V_11 == 0 ) {
V_3 &= ~ ( V_4 ) ;
if ( V_37 -> V_55 )
V_3 |= V_4 ;
}
else {
V_3 &= ~ ( V_5 ) ;
if ( V_37 -> V_55 )
V_3 |= V_5 ;
}
F_2 ( V_3 , V_9 ) ;
F_3 ( 300 ) ;
return 0 ;
}
