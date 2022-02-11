static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
if ( V_7 -> V_8 -> V_3 )
return V_7 -> V_8 -> V_3 ( V_7 , V_3 , V_4 , V_5 ) ;
return - V_9 ;
}
static int
F_2 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_10 * * V_11 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
switch ( V_3 ) {
case V_12 :
* V_11 = & V_7 -> V_13 -> V_14 ;
return 0 ;
default:
break;
}
return - V_15 ;
}
int
F_3 ( const struct V_16 * V_8 , struct V_17 * V_13 ,
const struct V_18 * V_19 , void * V_4 , T_1 V_5 ,
struct V_1 * * V_20 )
{
struct V_6 * V_7 ;
if ( ! ( V_7 = F_4 ( sizeof( * V_7 ) , V_21 ) ) )
return - V_22 ;
* V_20 = & V_7 -> V_2 ;
F_5 ( & V_23 , V_19 , & V_7 -> V_2 ) ;
V_7 -> V_8 = V_8 ;
V_7 -> V_13 = V_13 ;
return 0 ;
}
int
F_6 ( struct V_17 * V_13 , const struct V_18 * V_19 ,
void * V_4 , T_1 V_5 , struct V_1 * * V_20 )
{
return F_3 ( & V_6 , V_13 , V_19 , V_4 , V_5 , V_20 ) ;
}
