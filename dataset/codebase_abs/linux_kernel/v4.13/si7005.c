static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 = 50 ;
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 -> V_7 , V_8 ,
V_2 -> V_9 | V_10 |
( V_3 ? V_11 : 0 ) ) ;
if ( V_5 < 0 )
goto V_12;
while ( V_4 -- > 0 ) {
F_4 ( 20 ) ;
V_5 = F_5 ( V_2 -> V_7 , V_13 ) ;
if ( V_5 < 0 )
goto V_12;
if ( ! ( V_5 & V_14 ) )
break;
}
if ( V_4 < 0 ) {
V_5 = - V_15 ;
goto V_12;
}
V_5 = F_6 ( V_2 -> V_7 , V_16 ) ;
V_12:
F_7 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int F_8 ( struct V_17 * V_18 ,
struct V_19 const * V_20 , int * V_21 ,
int * V_22 , long V_23 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
int V_5 ;
switch ( V_23 ) {
case V_24 :
V_5 = F_1 ( V_2 , V_20 -> type == V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_21 = V_5 ;
return V_26 ;
case V_27 :
if ( V_20 -> type == V_25 ) {
* V_21 = 7 ;
* V_22 = 812500 ;
} else {
* V_21 = 3 ;
* V_22 = 906250 ;
}
return V_28 ;
case V_29 :
if ( V_20 -> type == V_25 )
* V_21 = - 50 * 32 * 4 ;
else
* V_21 = - 24 * 16 * 16 ;
return V_26 ;
default:
break;
}
return - V_30 ;
}
static int F_10 ( struct V_31 * V_7 ,
const struct V_32 * V_33 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
int V_5 ;
if ( ! F_11 ( V_7 -> V_34 , V_35 ) )
return - V_36 ;
V_18 = F_12 ( & V_7 -> V_37 , sizeof( * V_2 ) ) ;
if ( ! V_18 )
return - V_38 ;
V_2 = F_9 ( V_18 ) ;
F_13 ( V_7 , V_18 ) ;
V_2 -> V_7 = V_7 ;
F_14 ( & V_2 -> V_6 ) ;
V_18 -> V_37 . V_39 = & V_7 -> V_37 ;
V_18 -> V_40 = F_15 ( & V_7 -> V_37 ) ;
V_18 -> V_41 = V_42 ;
V_18 -> V_43 = & V_44 ;
V_18 -> V_45 = V_46 ;
V_18 -> V_47 = F_16 ( V_46 ) ;
V_5 = F_5 ( V_7 , V_48 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != V_49 && V_5 != V_50 )
return - V_51 ;
V_5 = F_5 ( V_7 , V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_9 = V_5 ;
return F_17 ( & V_7 -> V_37 , V_18 ) ;
}
