static void F_1 ( T_1 * V_1 , T_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
int V_5 ;
int V_6 ;
V_3 = F_2 ( V_7 ) ;
* V_2 = ( V_3 & 0xFFFF ) * 4 ;
* V_1 = ( ( V_3 >> 16 ) & 0xFFFF ) * 4 ;
V_4 = F_2 ( V_8 ) ;
F_3 ( L_1 , V_9 , V_4 / 10 , V_4 % 10 ) ;
if ( V_4 >= 26 ) {
V_5 = F_4 ( V_10 ) ;
V_5 |= F_4 ( V_11 ) ;
V_6 = F_4 ( V_12 ) ;
V_6 |= F_4 ( V_13 ) ;
* V_2 |= ( V_5 << 1 ) | V_6 ;
V_5 = F_4 ( V_14 ) ;
V_5 |= F_4 ( V_15 ) ;
V_6 = F_4 ( V_16 ) ;
V_6 |= F_4 ( V_17 ) ;
* V_1 |= ( V_5 << 1 ) | V_6 ;
} else {
* V_2 |= 0x3 ;
* V_1 |= 0x3 ;
}
}
static void F_5 ( int V_18 , int V_19 )
{
switch ( V_18 ) {
case V_20 :
V_21 = 0 ;
V_22 = 0 ;
V_23 = V_24 ;
break;
case V_25 :
case V_26 :
switch ( V_19 ) {
case 0x87 :
case 0x82 :
V_21 = 1 ;
V_22 = 1 ;
V_23 = V_27 ;
break;
case 0x81 :
switch ( V_28 ) {
case 1 :
V_21 = 2 ;
V_22 = 2 ;
V_23 = V_29 ;
break;
case 2 :
V_21 = 4 ;
V_22 = 1 ;
V_23 = V_30 ;
break;
default:
F_6 ( L_2 , V_28 ) ;
F_7 () ;
break;
}
break;
case 0x80 :
switch ( V_28 ) {
case 1 :
V_21 = 5 ;
V_22 = 2 ;
V_23 = V_31 ;
break;
case 2 :
V_21 = 6 ;
V_22 = 2 ;
V_23 = V_32 ;
break;
default:
F_6 ( L_2 , V_28 ) ;
F_7 () ;
break;
}
break;
case 0x83 :
switch ( V_28 ) {
case 1 :
V_21 = 7 ;
V_22 = 1 ;
V_23 = V_33 ;
break;
case 2 :
V_21 = 3 ;
V_22 = 2 ;
V_23 = V_34 ;
break;
default:
F_6 ( L_2 , V_28 ) ;
F_7 () ;
break;
}
break;
case 0x8F :
V_21 = 8 ;
V_22 = 1 ;
V_23 = V_35 ;
break;
case 0x08 :
V_21 = 1 ;
V_22 = 1 ;
V_23 = V_36 ;
break;
case 0x02 :
V_21 = 2 ;
V_22 = 2 ;
V_23 = V_37 ;
break;
case 0x04 :
V_21 = 3 ;
V_22 = 2 ;
V_23 = V_38 ;
break;
case 0 :
switch ( V_28 ) {
case 1 :
V_21 = 2 ;
V_22 = 2 ;
V_23 = V_29 ;
break;
case 2 :
V_21 = 3 ;
V_22 = 2 ;
V_23 = V_34 ;
break;
default:
F_6 ( L_2 , V_28 ) ;
F_7 () ;
break;
}
break;
default:
F_8 ( L_3 , V_19 ) ;
V_21 = 0 ;
V_22 = 0 ;
V_23 = V_24 ;
break;
}
break;
default:
F_8 ( L_4 , V_18 ) ;
V_21 = 0 ;
V_22 = 0 ;
V_23 = V_24 ;
break;
}
}
void F_9 ( void )
{
T_1 V_39 ;
T_1 V_40 ;
int V_41 ;
F_10 ( F_11 ( V_42 ) !=
V_43 ) ;
F_10 ( F_11 ( V_44 ) !=
V_43 ) ;
V_28 = F_2 ( V_45 ) & 0x0F ;
F_5 ( V_46 , V_47 ) ;
F_1 ( & V_39 , & V_40 ) ;
F_12 ( L_5 , V_9 , V_39 ) ;
F_12 ( L_6 , V_9 , V_40 ) ;
for ( V_41 = 0 ; V_41 < V_48 ; V_41 ++ ) {
if ( V_39 < V_42 [ V_23 ] [ V_41 ] )
break;
}
V_49 = V_41 - 1 ;
if ( V_49 == - 1 ) {
F_8 ( L_7 ,
V_39 ) ;
V_49 = 0 ;
V_21 = 1 ;
}
for ( V_41 = 0 ; V_41 < V_50 ; V_41 ++ ) {
if ( V_40 < V_44 [ V_23 ] [ V_41 ] )
break;
}
V_51 = V_41 - 1 ;
if ( V_51 == - 1 ) {
F_8 ( L_8 ,
V_40 ) ;
V_51 = 0 ;
V_22 = 1 ;
}
F_3 ( L_9 ,
V_21 , V_22 ) ;
}
