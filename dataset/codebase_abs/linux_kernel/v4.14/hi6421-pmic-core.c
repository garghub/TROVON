static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
const struct V_7 * V_8 ;
const struct V_9 * V_10 ;
enum V_11 type ;
void T_1 * V_12 ;
int V_13 , V_14 ;
V_8 = F_2 ( V_15 , & V_2 -> V_16 ) ;
if ( ! V_8 )
return - V_17 ;
type = (enum V_11 ) V_8 -> V_18 ;
V_4 = F_3 ( & V_2 -> V_16 , sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return - V_20 ;
V_6 = F_4 ( V_2 , V_21 , 0 ) ;
V_12 = F_5 ( & V_2 -> V_16 , V_6 ) ;
if ( F_6 ( V_12 ) )
return F_7 ( V_12 ) ;
V_4 -> V_22 = F_8 ( & V_2 -> V_16 , NULL , V_12 ,
& V_23 ) ;
if ( F_6 ( V_4 -> V_22 ) ) {
F_9 ( & V_2 -> V_16 , L_1 ,
F_7 ( V_4 -> V_22 ) ) ;
return F_7 ( V_4 -> V_22 ) ;
}
F_10 ( V_2 , V_4 ) ;
switch ( type ) {
case V_24 :
F_11 ( V_4 -> V_22 , V_25 ,
( V_26
| V_27
| V_28 ) ,
( V_29
| V_30 ) ) ;
V_10 = V_31 ;
V_13 = F_12 ( V_31 ) ;
break;
case V_32 :
V_10 = V_33 ;
V_13 = F_12 ( V_33 ) ;
break;
default:
F_9 ( & V_2 -> V_16 , L_2 ,
( unsigned int ) type ) ;
return - V_17 ;
}
V_14 = F_13 ( & V_2 -> V_16 , V_34 ,
V_10 , V_13 , NULL , 0 , NULL ) ;
if ( V_14 ) {
F_9 ( & V_2 -> V_16 , L_3 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
