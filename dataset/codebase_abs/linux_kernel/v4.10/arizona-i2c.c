static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
const struct V_6 * V_6 = NULL ;
unsigned long type ;
int V_7 ;
if ( V_2 -> V_8 . V_9 )
type = F_2 ( & V_2 -> V_8 ) ;
else
type = V_4 -> V_10 ;
switch ( type ) {
case V_11 :
if ( F_3 ( V_12 ) )
V_6 = & V_13 ;
break;
case V_14 :
case V_15 :
if ( F_3 ( V_16 ) )
V_6 = & V_17 ;
break;
case V_18 :
if ( F_3 ( V_19 ) )
V_6 = & V_20 ;
break;
case V_21 :
case V_22 :
if ( F_3 ( V_23 ) )
V_6 = & V_24 ;
break;
default:
F_4 ( & V_2 -> V_8 , L_1 , type ) ;
return - V_25 ;
}
if ( ! V_6 ) {
F_4 ( & V_2 -> V_8 ,
L_2 , type ) ;
return - V_25 ;
}
V_5 = F_5 ( & V_2 -> V_8 , sizeof( * V_5 ) , V_26 ) ;
if ( V_5 == NULL )
return - V_27 ;
V_5 -> V_28 = F_6 ( V_2 , V_6 ) ;
if ( F_7 ( V_5 -> V_28 ) ) {
V_7 = F_8 ( V_5 -> V_28 ) ;
F_4 ( & V_2 -> V_8 , L_3 ,
V_7 ) ;
return V_7 ;
}
V_5 -> type = type ;
V_5 -> V_8 = & V_2 -> V_8 ;
V_5 -> V_29 = V_2 -> V_29 ;
return F_9 ( V_5 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_11 ( & V_2 -> V_8 ) ;
F_12 ( V_5 ) ;
return 0 ;
}
