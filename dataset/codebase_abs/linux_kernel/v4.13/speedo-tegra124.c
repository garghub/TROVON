static void T_1 F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
int V_4 = V_2 -> V_5 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
* V_3 = V_9 ;
switch ( V_4 ) {
case 0x00 :
case 0x0F :
case 0x23 :
break;
case 0x83 :
V_2 -> V_6 = 2 ;
break;
case 0x1F :
case 0x87 :
case 0x27 :
V_2 -> V_6 = 2 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 1 ;
* V_3 = V_9 ;
break;
case 0x81 :
case 0x21 :
case 0x07 :
V_2 -> V_6 = 1 ;
V_2 -> V_7 = 1 ;
V_2 -> V_8 = 1 ;
* V_3 = V_10 ;
break;
case 0x49 :
case 0x4A :
case 0x48 :
V_2 -> V_6 = 4 ;
V_2 -> V_7 = 2 ;
V_2 -> V_8 = 3 ;
* V_3 = V_10 ;
break;
default:
F_2 ( L_1 , V_4 ) ;
break;
}
}
void T_1 F_3 ( struct V_1 * V_2 )
{
int V_11 , V_3 , V_12 , V_13 ;
int V_14 , V_15 , V_16 ;
F_4 ( F_5 ( V_17 ) !=
V_18 ) ;
F_4 ( F_5 ( V_19 ) !=
V_18 ) ;
F_4 ( F_5 ( V_20 ) !=
V_18 ) ;
V_12 = F_6 ( V_21 ) ;
V_2 -> V_22 = F_6 ( V_23 ) ;
V_13 = F_6 ( V_24 ) ;
V_14 = F_6 ( V_25 ) ;
V_16 = F_6 ( V_26 ) ;
V_15 = F_6 ( V_27 ) ;
V_2 -> V_28 = V_12 ;
if ( V_2 -> V_28 == 0 ) {
F_7 ( L_2 ) ;
F_8 ( 1 ) ;
return;
}
F_1 ( V_2 , & V_3 ) ;
V_2 -> V_14 = F_6 ( V_25 ) ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ )
if ( V_2 -> V_22 <
V_19 [ V_3 ] [ V_11 ] )
break;
V_2 -> V_30 = V_11 ;
for ( V_11 = 0 ; V_11 < V_31 ; V_11 ++ )
if ( V_2 -> V_28 <
V_17 [ V_3 ] [ V_11 ] )
break;
V_2 -> V_32 = V_11 ;
for ( V_11 = 0 ; V_11 < V_33 ; V_11 ++ )
if ( V_13 <
V_20 [ V_3 ] [ V_11 ] )
break;
V_2 -> V_34 = V_11 ;
F_9 ( L_3 ,
V_2 -> V_8 , V_2 -> V_22 ) ;
}
