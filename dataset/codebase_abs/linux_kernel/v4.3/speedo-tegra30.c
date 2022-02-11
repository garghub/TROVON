static void T_1 F_1 ( T_2 * V_1 , T_2 * V_2 )
{
T_2 V_3 ;
int V_4 ;
int V_5 ;
int V_6 ;
V_3 = F_2 ( V_7 ) ;
* V_2 = ( V_3 & 0xFFFF ) * 4 ;
* V_1 = ( ( V_3 >> 16 ) & 0xFFFF ) * 4 ;
V_4 = F_2 ( V_8 ) ;
F_3 ( L_1 , V_4 / 10 , V_4 % 10 ) ;
if ( V_4 >= 26 ) {
V_5 = F_4 ( V_9 ) ;
V_5 |= F_4 ( V_10 ) ;
V_6 = F_4 ( V_11 ) ;
V_6 |= F_4 ( V_12 ) ;
* V_2 |= ( V_5 << 1 ) | V_6 ;
V_5 = F_4 ( V_13 ) ;
V_5 |= F_4 ( V_14 ) ;
V_6 = F_4 ( V_15 ) ;
V_6 |= F_4 ( V_16 ) ;
* V_1 |= ( V_5 << 1 ) | V_6 ;
} else {
* V_2 |= 0x3 ;
* V_1 |= 0x3 ;
}
}
static void T_1 F_5 ( struct V_17 * V_18 )
{
int V_19 = F_2 ( V_20 ) & 0x0F ;
switch ( V_18 -> V_21 ) {
case V_22 :
V_18 -> V_23 = 0 ;
V_18 -> V_24 = 0 ;
V_25 = V_26 ;
break;
case V_27 :
case V_28 :
switch ( V_18 -> V_29 ) {
case 0x87 :
case 0x82 :
V_18 -> V_23 = 1 ;
V_18 -> V_24 = 1 ;
V_25 = V_30 ;
break;
case 0x81 :
switch ( V_19 ) {
case 1 :
V_18 -> V_23 = 2 ;
V_18 -> V_24 = 2 ;
V_25 = V_31 ;
break;
case 2 :
V_18 -> V_23 = 4 ;
V_18 -> V_24 = 1 ;
V_25 = V_32 ;
break;
default:
F_6 ( L_2 , V_19 ) ;
break;
}
break;
case 0x80 :
switch ( V_19 ) {
case 1 :
V_18 -> V_23 = 5 ;
V_18 -> V_24 = 2 ;
V_25 = V_33 ;
break;
case 2 :
V_18 -> V_23 = 6 ;
V_18 -> V_24 = 2 ;
V_25 = V_34 ;
break;
default:
F_6 ( L_2 , V_19 ) ;
break;
}
break;
case 0x83 :
switch ( V_19 ) {
case 1 :
V_18 -> V_23 = 7 ;
V_18 -> V_24 = 1 ;
V_25 = V_35 ;
break;
case 2 :
V_18 -> V_23 = 3 ;
V_18 -> V_24 = 2 ;
V_25 = V_36 ;
break;
default:
F_6 ( L_2 , V_19 ) ;
break;
}
break;
case 0x8F :
V_18 -> V_23 = 8 ;
V_18 -> V_24 = 1 ;
V_25 = V_37 ;
break;
case 0x08 :
V_18 -> V_23 = 1 ;
V_18 -> V_24 = 1 ;
V_25 = V_38 ;
break;
case 0x02 :
V_18 -> V_23 = 2 ;
V_18 -> V_24 = 2 ;
V_25 = V_39 ;
break;
case 0x04 :
V_18 -> V_23 = 3 ;
V_18 -> V_24 = 2 ;
V_25 = V_40 ;
break;
case 0 :
switch ( V_19 ) {
case 1 :
V_18 -> V_23 = 2 ;
V_18 -> V_24 = 2 ;
V_25 = V_31 ;
break;
case 2 :
V_18 -> V_23 = 3 ;
V_18 -> V_24 = 2 ;
V_25 = V_36 ;
break;
default:
F_6 ( L_2 , V_19 ) ;
break;
}
break;
default:
F_7 ( L_3 , V_18 -> V_29 ) ;
V_18 -> V_23 = 0 ;
V_18 -> V_24 = 0 ;
V_25 = V_26 ;
break;
}
break;
default:
F_7 ( L_4 , V_18 -> V_21 ) ;
V_18 -> V_23 = 0 ;
V_18 -> V_24 = 0 ;
V_25 = V_26 ;
break;
}
}
void T_1 F_8 ( struct V_17 * V_18 )
{
T_2 V_41 ;
T_2 V_42 ;
int V_43 ;
F_9 ( F_10 ( V_44 ) !=
V_45 ) ;
F_9 ( F_10 ( V_46 ) !=
V_45 ) ;
F_5 ( V_18 ) ;
F_1 ( & V_41 , & V_42 ) ;
F_3 ( L_5 , V_41 ) ;
F_3 ( L_6 , V_42 ) ;
for ( V_43 = 0 ; V_43 < V_47 ; V_43 ++ ) {
if ( V_41 < V_44 [ V_25 ] [ V_43 ] )
break;
}
V_18 -> V_48 = V_43 - 1 ;
if ( V_18 -> V_48 == - 1 ) {
F_7 ( L_7 ,
V_41 ) ;
V_18 -> V_48 = 0 ;
V_18 -> V_23 = 1 ;
}
for ( V_43 = 0 ; V_43 < V_49 ; V_43 ++ ) {
if ( V_42 < V_46 [ V_25 ] [ V_43 ] )
break;
}
V_18 -> V_50 = V_43 - 1 ;
if ( V_18 -> V_50 == - 1 ) {
F_7 ( L_8 ,
V_42 ) ;
V_18 -> V_50 = 0 ;
V_18 -> V_24 = 1 ;
}
}
