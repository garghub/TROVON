static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 ;
const struct V_6 * V_6 = NULL ;
unsigned long type ;
int V_7 ;
if ( V_2 -> V_8 . V_9 )
type = F_3 ( & V_2 -> V_8 ) ;
else
type = V_4 -> V_10 ;
switch ( type ) {
case V_11 :
if ( F_4 ( V_12 ) )
V_6 = & V_13 ;
break;
case V_14 :
case V_15 :
if ( F_4 ( V_16 ) )
V_6 = & V_17 ;
break;
case V_18 :
case V_19 :
if ( F_4 ( V_20 ) )
V_6 = & V_21 ;
break;
default:
F_5 ( & V_2 -> V_8 , L_1 , type ) ;
return - V_22 ;
}
if ( ! V_6 ) {
F_5 ( & V_2 -> V_8 ,
L_2 , type ) ;
return - V_22 ;
}
V_5 = F_6 ( & V_2 -> V_8 , sizeof( * V_5 ) , V_23 ) ;
if ( V_5 == NULL )
return - V_24 ;
V_5 -> V_25 = F_7 ( V_2 , V_6 ) ;
if ( F_8 ( V_5 -> V_25 ) ) {
V_7 = F_9 ( V_5 -> V_25 ) ;
F_5 ( & V_2 -> V_8 , L_3 ,
V_7 ) ;
return V_7 ;
}
V_5 -> type = type ;
V_5 -> V_8 = & V_2 -> V_8 ;
V_5 -> V_26 = V_2 -> V_26 ;
return F_10 ( V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_12 ( V_2 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
