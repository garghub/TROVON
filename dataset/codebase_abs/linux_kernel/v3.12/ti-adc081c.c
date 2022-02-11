static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
switch ( V_7 ) {
case V_11 :
V_10 = F_3 ( V_9 -> V_12 , V_13 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_5 = ( V_10 >> 4 ) & 0xff ;
return V_14 ;
case V_15 :
V_10 = F_4 ( V_9 -> V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_5 = V_10 / 1000 ;
* V_6 = 8 ;
return V_17 ;
default:
break;
}
return - V_18 ;
}
static int F_5 ( struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_10 ;
if ( ! F_6 ( V_20 -> V_23 , V_24 ) )
return - V_25 ;
V_2 = F_7 ( & V_20 -> V_26 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_27 ;
V_9 = F_2 ( V_2 ) ;
V_9 -> V_12 = V_20 ;
V_9 -> V_16 = F_8 ( & V_20 -> V_26 , L_1 ) ;
if ( F_9 ( V_9 -> V_16 ) )
return F_10 ( V_9 -> V_16 ) ;
V_10 = F_11 ( V_9 -> V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_26 . V_28 = & V_20 -> V_26 ;
V_2 -> V_29 = F_12 ( & V_20 -> V_26 ) ;
V_2 -> V_30 = V_31 ;
V_2 -> V_32 = & V_33 ;
V_2 -> V_34 = & V_35 ;
V_2 -> V_36 = 1 ;
V_10 = F_13 ( V_2 ) ;
if ( V_10 < 0 )
goto V_37;
F_14 ( V_20 , V_2 ) ;
return 0 ;
V_37:
V_37 ( V_9 -> V_16 ) ;
return V_10 ;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_16 ( V_20 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_17 ( V_2 ) ;
V_37 ( V_9 -> V_16 ) ;
return 0 ;
}
