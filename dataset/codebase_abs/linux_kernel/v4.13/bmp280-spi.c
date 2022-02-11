static int F_1 ( void * V_1 , const void * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_2 V_8 [ 2 ] ;
memcpy ( V_8 , V_2 , 2 ) ;
V_8 [ 0 ] &= ~ 0x80 ;
return F_3 ( V_7 , V_8 , 2 , NULL , 0 ) ;
}
static int F_4 ( void * V_1 , const void * V_9 ,
T_1 V_10 , void * V_11 , T_1 V_12 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
return F_3 ( V_7 , V_9 , V_10 , V_11 , V_12 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
const struct V_13 * V_14 = F_6 ( V_7 ) ;
struct V_15 * V_15 ;
const struct V_16 * V_16 ;
int V_17 ;
V_7 -> V_18 = 8 ;
V_17 = F_7 ( V_7 ) ;
if ( V_17 < 0 ) {
F_8 ( & V_7 -> V_5 , L_1 ) ;
return V_17 ;
}
switch ( V_14 -> V_19 ) {
case V_20 :
V_16 = & V_21 ;
break;
case V_22 :
case V_23 :
V_16 = & V_24 ;
break;
default:
return - V_25 ;
}
V_15 = F_9 ( & V_7 -> V_5 ,
& V_26 ,
& V_7 -> V_5 ,
V_16 ) ;
if ( F_10 ( V_15 ) ) {
F_8 ( & V_7 -> V_5 , L_2 ) ;
return F_11 ( V_15 ) ;
}
return F_12 ( & V_7 -> V_5 ,
V_15 ,
V_14 -> V_19 ,
V_14 -> V_27 ,
V_7 -> V_28 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
return F_14 ( & V_7 -> V_5 ) ;
}
