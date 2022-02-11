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
#ifdef F_6
case V_18 :
case V_19 :
V_6 = & V_20 ;
break;
#endif
default:
F_7 ( & V_2 -> V_8 , L_1 ,
V_4 -> V_10 ) ;
return - V_21 ;
}
V_5 = F_8 ( & V_2 -> V_8 , sizeof( * V_5 ) , V_22 ) ;
if ( V_5 == NULL )
return - V_23 ;
V_5 -> V_24 = F_9 ( V_2 , V_6 ) ;
if ( F_10 ( V_5 -> V_24 ) ) {
V_7 = F_11 ( V_5 -> V_24 ) ;
F_7 ( & V_2 -> V_8 , L_2 ,
V_7 ) ;
return V_7 ;
}
V_5 -> type = V_4 -> V_10 ;
V_5 -> V_8 = & V_2 -> V_8 ;
V_5 -> V_25 = V_2 -> V_25 ;
return F_12 ( V_5 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_14 ( & V_2 -> V_8 ) ;
F_15 ( V_5 ) ;
return 0 ;
}
