static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
int V_9 ;
T_1 V_10 , V_11 ;
F_2 ( & V_8 -> V_5 , L_1 , V_3 ) ;
switch ( V_3 ) {
case V_12 :
V_10 = 0x10 ;
break;
case V_13 :
V_10 = 0x31 ;
break;
case V_14 :
V_10 = 0x38 ;
break;
default:
V_9 = - V_15 ;
goto V_16;
}
if ( V_10 != V_5 -> V_17 [ 0 ] ) {
V_9 = F_3 ( V_8 , & V_10 , 1 ) ;
if ( V_9 < 0 )
goto V_16;
V_5 -> V_17 [ 0 ] = V_10 ;
}
V_11 = 0x82 ;
if ( V_11 != V_5 -> V_17 [ 1 ] ) {
V_9 = F_3 ( V_8 , & V_11 , 1 ) ;
if ( V_9 < 0 )
goto V_16;
V_5 -> V_17 [ 1 ] = V_11 ;
}
F_4 ( 1500 , 50000 ) ;
return 0 ;
V_16:
F_2 ( & V_8 -> V_5 , L_2 , V_9 ) ;
return V_9 ;
}
static int F_5 ( struct V_7 * V_8 ,
const struct V_18 * V_19 )
{
struct V_4 * V_5 ;
struct V_20 * V_21 = V_8 -> V_5 . V_22 ;
struct V_1 * V_2 = V_21 -> V_1 ;
int V_9 ;
T_1 V_23 [ 2 ] ;
V_5 = F_6 ( sizeof( * V_5 ) , V_24 ) ;
if ( ! V_5 ) {
V_9 = - V_25 ;
goto V_16;
}
V_5 -> V_8 = V_8 ;
V_9 = F_7 ( V_8 , V_23 , 2 ) ;
if ( V_9 < 0 )
goto V_26;
V_2 -> V_27 . V_28 = F_1 ;
V_2 -> V_6 = V_5 ;
F_8 ( V_8 , V_5 ) ;
F_9 ( & V_8 -> V_5 , L_3 ) ;
return 0 ;
V_26:
F_10 ( V_5 ) ;
V_16:
F_2 ( & V_8 -> V_5 , L_2 , V_9 ) ;
return V_9 ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_12 ( V_8 ) ;
F_2 ( & V_8 -> V_5 , L_4 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
