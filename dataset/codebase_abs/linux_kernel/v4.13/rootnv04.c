static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
union {
struct V_8 V_9 ;
} * args = V_4 ;
struct V_10 * V_11 ;
int V_12 , V_13 = - V_14 ;
F_2 ( V_2 , L_1 , V_5 ) ;
if ( ! ( V_13 = F_3 ( V_13 , & V_4 , & V_5 , args -> V_9 , 0 , 0 , true ) ) ) {
F_2 ( V_2 , L_2 ,
args -> V_9 . V_15 , args -> V_9 . V_16 , args -> V_9 . V_11 ) ;
V_3 = args -> V_9 . V_16 ;
V_12 = args -> V_9 . V_11 ;
} else
return V_13 ;
if ( ! ( V_11 = F_4 ( V_7 -> V_17 , V_12 ) ) )
return - V_18 ;
switch ( V_3 ) {
case V_19 :
return F_5 ( V_2 , V_11 , V_4 , V_5 ) ;
default:
break;
}
return - V_20 ;
}
static int
F_6 ( struct V_21 * V_17 , const struct V_22 * V_23 ,
void * V_4 , T_1 V_5 , struct V_1 * * V_24 )
{
struct V_6 * V_7 ;
if ( ! ( V_7 = F_7 ( sizeof( * V_7 ) , V_25 ) ) )
return - V_26 ;
V_7 -> V_17 = V_17 ;
* V_24 = & V_7 -> V_2 ;
F_8 ( & V_6 , V_23 , & V_7 -> V_2 ) ;
return 0 ;
}
