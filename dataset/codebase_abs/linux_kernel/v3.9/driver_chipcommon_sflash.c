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
struct V_8 * V_9 ;
T_1 V_10 , V_11 ;
switch ( V_2 -> V_12 & V_13 ) {
case V_14 :
F_1 ( V_2 , V_15 ) ;
F_2 ( V_2 , V_16 , 0 ) ;
F_1 ( V_2 , V_17 ) ;
V_10 = F_3 ( V_2 , V_18 ) ;
F_2 ( V_2 , V_16 , 1 ) ;
F_1 ( V_2 , V_17 ) ;
V_11 = F_3 ( V_2 , V_18 ) ;
switch ( V_10 ) {
case 0xbf :
for ( V_9 = V_19 ; V_9 -> V_20 ; V_9 ++ ) {
if ( V_9 -> V_10 == V_11 )
break;
}
break;
case 0x13 :
return - V_21 ;
default:
for ( V_9 = V_22 ; V_9 -> V_20 ; V_9 ++ ) {
if ( V_9 -> V_10 == V_10 )
break;
}
break;
}
if ( ! V_9 -> V_20 ) {
F_5 ( L_2 ,
V_10 , V_11 ) ;
return - V_21 ;
}
break;
case V_23 :
F_1 ( V_2 , V_24 ) ;
V_10 = F_3 ( V_2 , V_18 ) & 0x3c ;
for ( V_9 = V_25 ; V_9 -> V_20 ; V_9 ++ ) {
if ( V_9 -> V_10 == V_10 )
break;
}
if ( ! V_9 -> V_20 ) {
F_5 ( L_3 ,
V_10 ) ;
return - V_21 ;
}
break;
default:
F_5 ( L_4 ) ;
return - V_21 ;
}
F_7 ( L_5 ,
V_9 -> V_20 , V_9 -> V_26 , V_9 -> V_27 ) ;
F_5 ( L_6 ) ;
return - V_21 ;
}
