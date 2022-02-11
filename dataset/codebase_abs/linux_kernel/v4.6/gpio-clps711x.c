static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
void T_1 * V_7 , * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 , V_14 = V_4 ? F_2 ( V_4 , L_1 ) : V_2 -> V_14 ;
if ( ( V_14 < 0 ) || ( V_14 > 4 ) )
return - V_15 ;
V_10 = F_3 ( & V_2 -> V_5 , sizeof( * V_10 ) , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
V_12 = F_4 ( V_2 , V_18 , 0 ) ;
V_7 = F_5 ( & V_2 -> V_5 , V_12 ) ;
if ( F_6 ( V_7 ) )
return F_7 ( V_7 ) ;
V_12 = F_4 ( V_2 , V_18 , 1 ) ;
V_8 = F_5 ( & V_2 -> V_5 , V_12 ) ;
if ( F_6 ( V_8 ) )
return F_7 ( V_8 ) ;
switch ( V_14 ) {
case 3 :
V_13 = F_8 ( V_10 , & V_2 -> V_5 , 1 , V_7 , NULL , NULL ,
NULL , V_8 , 0 ) ;
break;
default:
V_13 = F_8 ( V_10 , & V_2 -> V_5 , 1 , V_7 , NULL , NULL ,
V_8 , NULL , 0 ) ;
break;
}
if ( V_13 )
return V_13 ;
switch ( V_14 ) {
case 4 :
V_10 -> V_19 = 3 ;
break;
default:
break;
}
V_10 -> V_20 = V_14 * 8 ;
V_10 -> V_21 = V_22 ;
F_9 ( V_2 , V_10 ) ;
return F_10 ( & V_2 -> V_5 , V_10 , NULL ) ;
}
