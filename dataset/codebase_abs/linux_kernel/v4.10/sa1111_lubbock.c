static int
F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 , V_7 , V_8 , V_9 ;
int V_10 = 0 ;
V_6 = V_7 = V_8 = V_9 = 0 ;
V_11:
switch ( V_2 -> V_12 ) {
case 0 :
V_6 = V_13 | V_14 | V_15 | V_16 ;
switch ( V_3 -> V_17 ) {
case 0 :
break;
case 33 :
V_7 |= V_16 ;
break;
case 50 :
V_7 |= V_15 ;
break;
default:
F_3 ( V_18 L_1 ,
V_19 , V_3 -> V_17 ) ;
V_10 = - 1 ;
}
switch ( V_3 -> V_20 ) {
case 0 :
break;
case 120 :
V_7 |= V_14 ;
break;
default:
if ( V_3 -> V_20 == V_3 -> V_17 )
V_7 |= V_13 ;
else {
F_3 ( V_18 L_2 ,
V_19 , V_3 -> V_20 ) ;
V_10 = - 1 ;
break;
}
}
break;
case 1 :
V_8 = ( 1 << 15 ) | ( 1 << 14 ) ;
switch ( V_3 -> V_17 ) {
case 0 :
break;
case 33 :
V_9 |= 1 << 15 ;
break;
case 50 :
V_9 |= 1 << 14 ;
break;
default:
F_3 ( V_18 L_1 ,
V_19 , V_3 -> V_17 ) ;
V_10 = - 1 ;
break;
}
if ( V_3 -> V_20 != V_3 -> V_17 && V_3 -> V_20 != 0 ) {
F_3 ( V_18 L_3 ,
V_19 , V_3 -> V_20 ) ;
V_10 = - 1 ;
break;
}
break;
default:
V_10 = - 1 ;
}
if ( V_10 == 0 )
V_10 = F_4 ( V_2 , V_3 ) ;
if ( V_10 == 0 ) {
F_5 ( V_8 , V_9 ) ;
F_6 ( V_5 -> V_21 , V_6 , V_7 ) ;
}
#if 1
if ( V_10 == 0 && V_3 -> V_17 == 33 ) {
struct V_22 V_23 ;
F_7 ( 3 ) ;
F_8 ( V_2 , & V_23 ) ;
if ( ! V_23 . V_24 && ! V_23 . V_25 ) {
F_5 ( V_8 , 0 ) ;
F_6 ( V_5 -> V_21 , V_6 , 0 ) ;
F_7 ( 100 ) ;
( ( T_1 * ) V_3 ) -> V_17 = 50 ;
( ( T_1 * ) V_3 ) -> V_20 = 50 ;
goto V_11;
}
}
#endif
return V_10 ;
}
int F_9 ( struct V_26 * V_27 )
{
F_10 ( V_27 , V_13 | V_14 | V_15 | V_16 , 0 , 0 ) ;
F_6 ( V_27 , V_13 | V_14 | V_15 | V_16 , 0 ) ;
F_11 ( V_27 , V_13 | V_14 | V_15 | V_16 , 0 ) ;
F_5 ( ( 1 << 15 ) | ( 1 << 14 ) , 0 ) ;
F_12 ( & V_28 ) ;
F_13 ( & V_27 -> V_21 , & V_28 ) ;
return F_14 ( V_27 , & V_28 ,
V_29 ) ;
}
