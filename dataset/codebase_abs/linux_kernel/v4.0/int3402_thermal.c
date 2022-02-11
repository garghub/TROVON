static void F_1 ( T_1 V_1 , T_2 V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( ! V_5 )
return;
switch ( V_2 ) {
case V_6 :
break;
case V_7 :
F_2 ( V_5 -> V_8 ) ;
break;
default:
break;
}
}
static int F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 ) ;
struct V_4 * V_14 ;
int V_15 ;
if ( ! F_5 ( V_12 -> V_1 , L_1 ) )
return - V_16 ;
V_14 = F_6 ( & V_10 -> V_13 , sizeof( * V_14 ) , V_17 ) ;
if ( ! V_14 )
return - V_18 ;
V_14 -> V_8 = F_7 ( V_12 , NULL ) ;
if ( F_8 ( V_14 -> V_8 ) )
return F_9 ( V_14 -> V_8 ) ;
V_15 = F_10 ( V_12 -> V_1 ,
V_19 ,
F_1 ,
V_14 ) ;
if ( V_15 ) {
F_11 ( V_14 -> V_8 ) ;
return V_15 ;
}
V_14 -> V_1 = V_12 -> V_1 ;
F_12 ( V_10 , V_14 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 )
{
struct V_4 * V_14 = F_14 ( V_10 ) ;
F_15 ( V_14 -> V_1 ,
V_19 , F_1 ) ;
F_11 ( V_14 -> V_8 ) ;
return 0 ;
}
