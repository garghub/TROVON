static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
const struct V_6 * V_6 ;
unsigned long type ;
int V_7 ;
if ( V_2 -> V_8 . V_9 )
type = F_2 ( & V_2 -> V_8 ) ;
else
type = V_4 -> V_10 ;
switch ( type ) {
#ifdef F_3
case V_11 :
V_6 = & V_12 ;
break;
#endif
#ifdef F_4
case V_13 :
case V_14 :
V_6 = & V_15 ;
break;
#endif
#ifdef F_5
case V_16 :
V_6 = & V_17 ;
break;
#endif
default:
F_6 ( & V_2 -> V_8 , L_1 ,
V_4 -> V_10 ) ;
return - V_18 ;
}
V_5 = F_7 ( & V_2 -> V_8 , sizeof( * V_5 ) , V_19 ) ;
if ( V_5 == NULL )
return - V_20 ;
V_5 -> V_21 = F_8 ( V_2 , V_6 ) ;
if ( F_9 ( V_5 -> V_21 ) ) {
V_7 = F_10 ( V_5 -> V_21 ) ;
F_6 ( & V_2 -> V_8 , L_2 ,
V_7 ) ;
return V_7 ;
}
V_5 -> type = V_4 -> V_10 ;
V_5 -> V_8 = & V_2 -> V_8 ;
V_5 -> V_22 = V_2 -> V_22 ;
return F_11 ( V_5 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_13 ( & V_2 -> V_8 ) ;
F_14 ( V_5 ) ;
return 0 ;
}
