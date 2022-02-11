static int T_1 F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 ;
const struct V_6 * V_6 ;
int V_7 ;
switch ( V_4 -> V_8 ) {
#ifdef F_3
case V_9 :
V_6 = & V_10 ;
break;
#endif
#ifdef F_4
case V_11 :
V_6 = & V_12 ;
break;
#endif
default:
F_5 ( & V_2 -> V_13 , L_1 ,
V_4 -> V_8 ) ;
return - V_14 ;
}
V_5 = F_6 ( & V_2 -> V_13 , sizeof( * V_5 ) , V_15 ) ;
if ( V_5 == NULL )
return - V_16 ;
V_5 -> V_17 = F_7 ( V_2 , V_6 ) ;
if ( F_8 ( V_5 -> V_17 ) ) {
V_7 = F_9 ( V_5 -> V_17 ) ;
F_5 ( & V_2 -> V_13 , L_2 ,
V_7 ) ;
return V_7 ;
}
V_5 -> type = V_4 -> V_8 ;
V_5 -> V_13 = & V_2 -> V_13 ;
V_5 -> V_18 = V_2 -> V_18 ;
return F_10 ( V_5 ) ;
}
static int T_2 F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_12 ( & V_2 -> V_13 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
