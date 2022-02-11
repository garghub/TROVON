static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , int * V_6 )
{
int V_7 = 20 ;
T_2 V_8 ;
int V_9 ;
F_2 ( & V_2 -> V_10 ) ;
V_9 = F_3 ( V_2 -> V_11 , V_12 ,
V_3 ) ;
if ( V_9 < 0 )
goto V_13;
while ( V_7 -- ) {
V_9 = F_4 ( V_2 -> V_11 , V_12 ) ;
if ( V_9 < 0 )
goto V_13;
if ( V_9 & V_4 )
break;
F_5 ( 20 ) ;
}
if ( V_7 < 0 ) {
F_6 ( & V_2 -> V_11 -> V_14 ,
L_1 ) ;
V_9 = - V_15 ;
goto V_13;
}
V_9 = F_7 ( V_2 -> V_11 ,
V_5 , sizeof( V_8 ) , ( T_1 * ) & V_8 ) ;
if ( V_9 < 0 )
goto V_13;
F_8 ( & V_2 -> V_10 ) ;
* V_6 = F_9 ( V_8 ) ;
return 0 ;
V_13:
F_8 ( & V_2 -> V_10 ) ;
return V_9 ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_18 const * V_19 ,
int * V_6 , int * V_20 , long V_21 )
{
int V_9 ;
struct V_1 * V_2 = F_11 ( V_17 ) ;
switch ( V_21 ) {
case V_22 :
switch ( V_19 -> type ) {
case V_23 :
V_9 = F_1 ( V_2 ,
V_24 , V_25 ,
V_26 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_27 ;
case V_28 :
V_9 = F_1 ( V_2 ,
V_29 , V_30 ,
V_31 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_27 ;
default:
return - V_32 ;
}
case V_33 :
if ( V_19 -> type != V_23 )
return - V_32 ;
* V_6 = 0 ;
* V_20 = 250000 ;
return V_34 ;
default:
return - V_32 ;
}
}
static int F_12 ( struct V_35 * V_11 ,
const struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_9 , V_38 ;
V_17 = F_13 ( & V_11 -> V_14 , sizeof( * V_2 ) ) ;
if ( ! V_17 )
return - V_39 ;
V_2 = F_11 ( V_17 ) ;
F_14 ( V_11 , V_17 ) ;
V_2 -> V_11 = V_11 ;
F_15 ( & V_2 -> V_10 ) ;
V_9 = F_4 ( V_2 -> V_11 , V_40 ) ;
if ( V_9 < 0 )
return V_9 ;
V_38 = V_9 >> 4 ;
if ( V_38 != V_41 && V_38 != V_42 )
return - V_43 ;
F_16 ( & V_11 -> V_14 , L_2 ,
( V_38 == V_41 ) ? L_3 : L_4 ,
V_9 & 0xf ) ;
V_17 -> V_14 . V_44 = & V_11 -> V_14 ;
V_17 -> V_45 = & V_46 ;
V_17 -> V_47 = V_48 ;
V_17 -> V_49 = F_17 ( V_48 ) ;
V_17 -> V_50 = V_51 ;
V_17 -> V_52 = V_53 ;
return F_18 ( & V_11 -> V_14 , V_17 ) ;
}
