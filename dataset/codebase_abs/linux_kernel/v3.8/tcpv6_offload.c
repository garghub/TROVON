static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( ! F_2 ( V_2 , sizeof( * V_6 ) ) )
return - V_7 ;
V_4 = F_3 ( V_2 ) ;
V_6 = F_4 ( V_2 ) ;
V_6 -> V_8 = 0 ;
V_2 -> V_9 = V_10 ;
F_5 ( V_2 , & V_4 -> V_11 , & V_4 -> V_12 ) ;
return 0 ;
}
static struct V_1 * * F_6 ( struct V_1 * * V_13 ,
struct V_1 * V_2 )
{
const struct V_3 * V_14 = F_7 ( V_2 ) ;
T_1 V_15 ;
T_2 V_16 ;
switch ( V_2 -> V_9 ) {
case V_17 :
if ( ! F_8 ( F_9 ( V_2 ) , & V_14 -> V_11 , & V_14 -> V_12 ,
V_2 -> V_18 ) ) {
V_2 -> V_9 = V_19 ;
break;
}
V_20:
F_10 ( V_2 ) -> V_20 = 1 ;
return NULL ;
case V_21 :
V_15 = ~ F_11 ( F_12 ( & V_14 -> V_11 , & V_14 -> V_12 ,
F_9 ( V_2 ) ,
V_22 , 0 ) ) ;
V_16 = F_13 ( F_14 ( V_2 ,
F_15 ( V_2 ) ,
F_9 ( V_2 ) ,
V_15 ) ) ;
if ( V_16 )
goto V_20;
V_2 -> V_9 = V_19 ;
break;
}
return F_16 ( V_13 , V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
const struct V_3 * V_14 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
V_6 -> V_8 = ~ F_8 ( V_2 -> V_23 - F_18 ( V_2 ) ,
& V_14 -> V_11 , & V_14 -> V_12 , 0 ) ;
F_19 ( V_2 ) -> V_24 = V_25 ;
return F_20 ( V_2 ) ;
}
int T_3 F_21 ( void )
{
return F_22 ( & V_26 , V_22 ) ;
}
