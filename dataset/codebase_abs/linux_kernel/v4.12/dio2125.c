static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_11 ;
switch ( V_5 ) {
case V_12 :
V_11 = 1 ;
break;
case V_13 :
V_11 = 0 ;
break;
default:
F_4 ( 1 , L_1 ) ;
return - V_14 ;
}
F_5 ( V_10 -> V_15 , V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
struct V_9 * V_10 ;
int V_20 ;
V_10 = F_7 ( V_19 , sizeof( * V_10 ) , V_21 ) ;
if ( V_10 == NULL )
return - V_22 ;
F_8 ( V_17 , V_10 ) ;
V_10 -> V_15 = F_9 ( V_19 , L_2 , V_23 ) ;
if ( F_10 ( V_10 -> V_15 ) ) {
V_20 = F_11 ( V_10 -> V_15 ) ;
if ( V_20 != - V_24 )
F_12 ( V_19 , L_3 , V_20 ) ;
return V_20 ;
}
return F_13 ( V_19 , & V_25 ,
NULL , 0 ) ;
}
