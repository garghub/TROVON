void F_1 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_2 , L_1 ) ;
if ( V_1 -> V_3 == V_4 ) {
struct V_5 * V_6 = V_1 -> V_2 ;
V_6 -> V_7 |= V_8 ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
}
F_2 ( V_1 -> V_2 , L_2 ) ;
}
int F_3 ( T_1 * V_1 , struct V_11 * V_12 , int V_13 )
{
F_2 ( V_1 -> V_2 , L_3 ) ;
if ( V_1 -> V_3 == V_14 )
return F_4 ( V_1 -> V_2 , V_12 , V_13 ) ;
return - V_15 ;
}
int F_5 ( T_1 * V_1 )
{
int V_16 = 0 ;
F_2 ( V_1 -> V_2 , L_4 ) ;
if ( V_1 -> V_3 == V_14 ) {
V_16 = F_6 ( V_1 -> V_2 ) ;
if ( V_16 < 0 )
F_7 ( V_17 L_5 ,
V_1 -> V_18 , V_16 ) ;
}
F_2 ( V_1 -> V_2 , L_6 ) ;
return V_16 ;
}
void F_8 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_2 , L_7 ) ;
if ( V_1 -> V_3 == V_14 )
F_9 ( V_1 -> V_2 ) ;
F_2 ( V_1 -> V_2 , L_8 ) ;
}
T_2 F_10 ( T_1 * V_1 , struct V_19 * V_20 )
{
F_2 ( V_1 -> V_2 , L_9 ) ;
switch( V_1 -> V_3 ) {
case V_14 :
return F_11 ( V_20 , V_1 -> V_2 ) ;
break;
case V_4 :
return F_12 ( V_21 ) ;
break;
case V_22 :
return F_12 ( V_21 ) ;
break;
default:
F_7 ( V_17 L_10 , V_1 -> V_18 ) ;
return F_12 ( V_21 ) ;
break;
}
F_2 ( V_1 -> V_2 , L_11 ) ;
}
void F_13 ( T_1 * V_1 , struct V_19 * V_20 )
{
F_2 ( V_1 -> V_2 , L_12 ) ;
switch( V_1 -> V_3 ) {
case V_14 :
case V_4 :
default:
F_14 ( V_20 ) ;
break;
case V_22 :
break;
}
F_2 ( V_1 -> V_2 , L_13 ) ;
}
