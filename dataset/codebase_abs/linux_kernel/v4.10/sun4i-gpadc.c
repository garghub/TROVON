static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
const struct V_7 * V_8 ;
const struct V_9 * V_10 ;
unsigned int V_11 , V_12 ;
int V_13 ;
V_8 = F_2 ( V_14 , V_2 -> V_4 . V_15 ) ;
if ( ! V_8 )
return - V_16 ;
switch ( ( long ) V_8 -> V_17 ) {
case V_18 :
V_10 = V_19 ;
V_12 = F_3 ( V_19 ) ;
break;
case V_20 :
V_10 = V_21 ;
V_12 = F_3 ( V_21 ) ;
break;
case V_22 :
V_10 = V_23 ;
V_12 = F_3 ( V_23 ) ;
break;
default:
return - V_16 ;
}
V_4 = F_4 ( & V_2 -> V_4 , sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_6 = F_5 ( V_2 , V_26 , 0 ) ;
V_4 -> V_27 = F_6 ( & V_2 -> V_4 , V_6 ) ;
if ( F_7 ( V_4 -> V_27 ) )
return F_8 ( V_4 -> V_27 ) ;
V_4 -> V_4 = & V_2 -> V_4 ;
F_9 ( V_4 -> V_4 , V_4 ) ;
V_4 -> V_28 = F_10 ( V_4 -> V_4 , V_4 -> V_27 ,
& V_29 ) ;
if ( F_7 ( V_4 -> V_28 ) ) {
V_13 = F_8 ( V_4 -> V_28 ) ;
F_11 ( & V_2 -> V_4 , L_1 , V_13 ) ;
return V_13 ;
}
F_12 ( V_4 -> V_28 , V_30 , 0 ) ;
V_11 = F_13 ( V_2 , 0 ) ;
V_13 = F_14 ( & V_2 -> V_4 , V_4 -> V_28 , V_11 ,
V_31 , 0 ,
& V_32 ,
& V_4 -> V_33 ) ;
if ( V_13 ) {
F_11 ( & V_2 -> V_4 , L_2 , V_13 ) ;
return V_13 ;
}
V_13 = F_15 ( V_4 -> V_4 , 0 , V_10 , V_12 , NULL , 0 , NULL ) ;
if ( V_13 ) {
F_11 ( & V_2 -> V_4 , L_3 , V_13 ) ;
return V_13 ;
}
return 0 ;
}
