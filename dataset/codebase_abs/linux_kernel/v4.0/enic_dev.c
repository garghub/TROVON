int F_1 ( struct V_1 * V_1 , struct V_2 * * V_3 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_3 ( V_1 -> V_6 , V_3 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_5 ( struct V_1 * V_1 , struct V_7 * * V_8 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_6 ( V_1 -> V_6 , V_8 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_7 ( struct V_1 * V_1 )
{
int V_4 ;
if ( ! F_8 ( V_1 -> V_9 -> V_10 ) )
return - V_11 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_9 ( V_1 -> V_6 , V_1 -> V_9 -> V_10 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_10 ( struct V_1 * V_1 )
{
int V_4 ;
if ( ! F_8 ( V_1 -> V_9 -> V_10 ) )
return - V_11 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_11 ( V_1 -> V_6 , V_1 -> V_9 -> V_10 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_12 ( struct V_1 * V_1 , int V_12 , int V_13 ,
int V_14 , int V_15 , int V_16 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_13 ( V_1 -> V_6 , V_12 ,
V_13 , V_14 , V_15 , V_16 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_14 ( struct V_1 * V_1 , const T_1 * V_17 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_9 ( V_1 -> V_6 , V_17 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_15 ( struct V_1 * V_1 , const T_1 * V_17 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_11 ( V_1 -> V_6 , V_17 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_16 ( struct V_1 * V_1 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_17 ( V_1 -> V_6 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_18 ( struct V_1 * V_1 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_19 ( V_1 -> V_6 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_20 ( struct V_1 * V_1 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_21 ( V_1 -> V_6 ,
V_18 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_22 ( struct V_1 * V_1 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_23 ( V_1 -> V_6 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_24 ( struct V_1 * V_1 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_25 ( V_1 -> V_6 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_26 ( struct V_1 * V_1 )
{
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_27 ( V_1 -> V_6 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_28 ( struct V_19 * V_9 , T_2 V_20 , T_3 V_21 )
{
struct V_1 * V_1 = F_29 ( V_9 ) ;
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_30 ( V_1 , V_21 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_31 ( struct V_19 * V_9 , T_2 V_20 , T_3 V_21 )
{
struct V_1 * V_1 = F_29 ( V_9 ) ;
int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_4 = F_32 ( V_1 , V_21 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_33 ( int V_22 )
{
switch ( V_22 ) {
case V_23 :
return 0 ;
case V_24 :
return - V_25 ;
case V_26 :
return - V_27 ;
case V_28 :
return - V_29 ;
case V_30 :
return - V_31 ;
case V_32 :
case V_33 :
return - V_34 ;
case V_35 :
return - V_25 ;
case V_36 :
return - V_37 ;
case V_38 :
return - V_39 ;
case V_40 :
return - V_41 ;
case V_42 :
return - V_43 ;
case V_44 :
default:
return ( V_22 < 0 ) ? V_22 : - 1 ;
}
}
