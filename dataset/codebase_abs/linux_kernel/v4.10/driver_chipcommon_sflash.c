static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
F_2 ( V_2 , V_5 ,
V_6 | V_3 ) ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
if ( ! ( F_3 ( V_2 , V_5 ) &
V_7 ) )
return;
F_4 () ;
}
F_5 ( L_1 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_10 -> V_11 -> V_12 . V_9 ;
const struct V_13 * V_14 ;
T_1 V_15 , V_16 ;
switch ( V_2 -> V_17 & V_18 ) {
case V_19 :
F_1 ( V_2 , V_20 ) ;
F_2 ( V_2 , V_21 , 0 ) ;
F_1 ( V_2 , V_22 ) ;
V_15 = F_3 ( V_2 , V_23 ) ;
F_2 ( V_2 , V_21 , 1 ) ;
F_1 ( V_2 , V_22 ) ;
V_16 = F_3 ( V_2 , V_23 ) ;
switch ( V_15 ) {
case 0xbf :
for ( V_14 = V_24 ; V_14 -> V_25 ; V_14 ++ ) {
if ( V_14 -> V_15 == V_16 )
break;
}
break;
case 0x13 :
return - V_26 ;
default:
for ( V_14 = V_27 ; V_14 -> V_25 ; V_14 ++ ) {
if ( V_14 -> V_15 == V_15 )
break;
}
break;
}
if ( ! V_14 -> V_25 ) {
F_5 ( L_2 ,
V_15 , V_16 ) ;
return - V_26 ;
}
break;
case V_28 :
F_1 ( V_2 , V_29 ) ;
V_15 = F_3 ( V_2 , V_23 ) & 0x3c ;
for ( V_14 = V_30 ; V_14 -> V_25 ; V_14 ++ ) {
if ( V_14 -> V_15 == V_15 )
break;
}
if ( ! V_14 -> V_25 ) {
F_5 ( L_3 ,
V_15 ) ;
return - V_26 ;
}
break;
default:
F_5 ( L_4 ) ;
return - V_26 ;
}
V_9 -> V_31 = V_32 ;
V_9 -> V_33 = V_14 -> V_33 ;
V_9 -> V_34 = V_14 -> V_34 ;
V_9 -> V_35 = V_9 -> V_33 * V_9 -> V_34 ;
V_9 -> V_36 = true ;
F_7 ( L_5 ,
V_14 -> V_25 , V_9 -> V_35 / 1024 , V_14 -> V_33 , V_14 -> V_34 ) ;
V_37 . V_38 [ 0 ] . V_39 = V_37 . V_38 [ 0 ] . V_40 +
V_9 -> V_35 ;
V_37 . V_10 . V_41 = V_9 ;
return 0 ;
}
