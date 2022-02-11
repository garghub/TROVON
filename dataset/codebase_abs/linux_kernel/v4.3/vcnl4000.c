static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , int * V_6 )
{
int V_7 = 20 ;
T_2 V_8 ;
int V_9 ;
V_9 = F_2 ( V_2 -> V_10 , V_11 ,
V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
while ( V_7 -- ) {
V_9 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 & V_4 )
break;
F_4 ( 20 ) ;
}
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_10 -> V_12 ,
L_1 ) ;
return - V_13 ;
}
V_9 = F_6 ( V_2 -> V_10 ,
V_5 , sizeof( V_8 ) , ( T_1 * ) & V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_6 = F_7 ( V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 ,
struct V_16 const * V_17 ,
int * V_6 , int * V_18 , long V_19 )
{
int V_9 = - V_20 ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
switch ( V_19 ) {
case V_21 :
switch ( V_17 -> type ) {
case V_22 :
V_9 = F_1 ( V_2 ,
V_23 , V_24 ,
V_25 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = V_26 ;
break;
case V_27 :
V_9 = F_1 ( V_2 ,
V_28 , V_29 ,
V_30 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = V_26 ;
break;
default:
break;
}
break;
case V_31 :
if ( V_17 -> type == V_22 ) {
* V_6 = 0 ;
* V_18 = 250000 ;
V_9 = V_32 ;
}
break;
default:
break;
}
return V_9 ;
}
static int F_10 ( struct V_33 * V_10 ,
const struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_9 ;
V_15 = F_11 ( & V_10 -> V_12 , sizeof( * V_2 ) ) ;
if ( ! V_15 )
return - V_36 ;
V_2 = F_9 ( V_15 ) ;
F_12 ( V_10 , V_15 ) ;
V_2 -> V_10 = V_10 ;
V_9 = F_3 ( V_2 -> V_10 , V_37 ) ;
if ( V_9 < 0 )
return V_9 ;
F_13 ( & V_10 -> V_12 , L_2 ,
V_9 >> 4 , V_9 & 0xf ) ;
V_15 -> V_12 . V_38 = & V_10 -> V_12 ;
V_15 -> V_39 = & V_40 ;
V_15 -> V_41 = V_42 ;
V_15 -> V_43 = F_14 ( V_42 ) ;
V_15 -> V_44 = V_45 ;
V_15 -> V_46 = V_47 ;
return F_15 ( & V_10 -> V_12 , V_15 ) ;
}
