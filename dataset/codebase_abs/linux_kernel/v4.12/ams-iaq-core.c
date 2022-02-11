static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
struct V_6 V_7 = {
. V_8 = V_4 -> V_8 ,
. V_9 = V_4 -> V_9 | V_10 ,
. V_11 = V_12 ,
. V_13 = ( char * ) & V_2 -> V_14 ,
} ;
V_5 = F_2 ( V_4 -> V_15 , & V_7 , 1 ) ;
return ( V_5 == V_12 ) ? 0 : V_5 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_5 ;
if ( ! F_4 ( V_16 , V_2 -> V_17 + V_18 ) )
return 0 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_17 = V_16 ;
return 0 ;
}
static int F_5 ( struct V_19 * V_20 ,
struct V_21 const * V_22 , int * V_23 ,
int * V_24 , long V_25 )
{
struct V_1 * V_2 = F_6 ( V_20 ) ;
int V_5 ;
if ( V_25 != V_26 )
return - V_27 ;
F_7 ( & V_2 -> V_28 ) ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 )
goto V_29;
switch ( V_22 -> V_30 ) {
case V_31 :
* V_23 = 0 ;
* V_24 = F_8 ( V_2 -> V_14 . V_32 ) ;
V_5 = V_33 ;
break;
case V_34 :
* V_23 = F_9 ( V_2 -> V_14 . V_35 ) ;
V_5 = V_36 ;
break;
case V_37 :
* V_23 = 0 ;
* V_24 = F_8 ( V_2 -> V_14 . V_38 ) ;
V_5 = V_39 ;
break;
default:
V_5 = - V_27 ;
}
V_29:
F_10 ( & V_2 -> V_28 ) ;
return V_5 ;
}
static int F_11 ( struct V_3 * V_4 ,
const struct V_40 * V_41 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 ;
V_20 = F_12 ( & V_4 -> V_42 , sizeof( * V_2 ) ) ;
if ( ! V_20 )
return - V_43 ;
V_2 = F_6 ( V_20 ) ;
F_13 ( V_4 , V_20 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_17 = V_16 - V_18 ;
F_14 ( & V_2 -> V_28 ) ;
V_20 -> V_42 . V_44 = & V_4 -> V_42 ;
V_20 -> V_45 = & V_46 ;
V_20 -> V_47 = F_15 ( & V_4 -> V_42 ) ;
V_20 -> V_48 = V_49 ;
V_20 -> V_50 = V_51 ;
V_20 -> V_52 = F_16 ( V_51 ) ;
return F_17 ( & V_4 -> V_42 , V_20 ) ;
}
