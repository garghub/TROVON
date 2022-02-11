static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_10 , V_11 = 0 ;
T_2 V_12 [ 2 ] ;
T_3 V_13 = 0 ;
if ( F_3 ( & V_7 -> V_14 ) )
return - V_15 ;
V_10 = F_4 ( V_9 , NULL , 0 , & V_12 [ 0 ] , 2 ) ;
if ( V_10 < 0 ) {
F_5 ( V_2 , L_1 ,
V_10 ) ;
goto V_16;
}
V_13 = ( V_12 [ 0 ] << 8 ) + V_12 [ 1 ] ;
F_6 ( V_2 , L_2 ,
V_12 [ 0 ] , V_12 [ 1 ] , V_13 ) ;
switch ( V_7 -> V_17 ) {
case V_18 :
V_11 = ( ( int ) V_13 / 32 ) * 250 ;
break;
case V_19 :
case V_20 :
case V_21 :
V_11 = ( ( int ) V_13 / 8 ) * 625 / 10 ;
break;
case V_22 :
V_11 = ( ( int ) V_13 / 4 ) * 3125 / 100 ;
break;
}
V_10 = sprintf ( V_5 , L_3 , V_11 ) ;
V_16:
F_7 ( & V_7 -> V_14 ) ;
return V_10 ;
}
static int F_8 ( struct V_8 * V_9 )
{
const struct V_23 * V_24 ;
struct V_1 * V_25 ;
struct V_6 * V_7 ;
int V_17 ;
V_24 = F_9 ( V_26 , & V_9 -> V_2 ) ;
if ( V_24 )
V_17 = ( int ) ( V_27 ) V_24 -> V_28 ;
else
V_17 = F_10 ( V_9 ) -> V_29 ;
if ( V_9 -> V_30 & ( V_31 | V_32 ) )
return - V_33 ;
V_7 = F_11 ( & V_9 -> V_2 , sizeof( * V_7 ) , V_34 ) ;
if ( ! V_7 )
return - V_35 ;
F_12 ( & V_7 -> V_14 ) ;
V_7 -> V_17 = V_17 ;
V_7 -> V_9 = V_9 ;
V_25 = F_13 ( & V_9 -> V_2 ,
V_9 -> V_36 ,
V_7 , V_37 ) ;
return F_14 ( V_25 ) ;
}
