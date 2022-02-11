int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_7 = 0 ;
V_7 |= F_2 ( & V_6 -> V_8 , V_9 | V_10 ) ;
V_7 |= F_2 ( & V_6 -> V_11 , V_12 ) ;
V_7 |= F_2 ( & V_6 -> V_13 , V_9 ) ;
V_7 |= F_2 ( & V_6 -> V_14 , V_15 ) ;
V_7 |= F_2 ( & V_6 -> V_16 , V_15 | V_17 ) ;
if ( V_7 )
return 1 ;
V_7 |= F_3 ( V_6 -> V_8 ) ;
V_7 |= F_3 ( V_6 -> V_16 ) ;
if ( V_7 )
return 2 ;
V_7 |= F_4 ( & V_6 -> V_18 , 0 ) ;
V_7 |= F_4 ( & V_6 -> V_19 , 0 ) ;
V_7 |= F_4 ( & V_6 -> V_20 , 0 ) ;
V_7 |= F_4 ( & V_6 -> V_21 , V_6 -> V_22 ) ;
switch ( V_6 -> V_16 ) {
case V_15 :
break;
case V_17 :
V_7 |= F_4 ( & V_6 -> V_23 , 0 ) ;
break;
default:
break;
}
if ( V_7 )
return 3 ;
return 0 ;
}
