static void F_1 ( T_1 V_1 , T_2 V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( ! V_5 )
return;
switch ( V_2 ) {
case V_6 :
break;
case V_7 :
F_2 ( V_5 -> V_8 ,
V_9 ) ;
break;
default:
break;
}
}
static int F_3 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( & V_11 -> V_14 ) ;
struct V_4 * V_15 ;
int V_16 ;
if ( ! F_5 ( V_13 -> V_1 , L_1 ) )
return - V_17 ;
V_15 = F_6 ( & V_11 -> V_14 , sizeof( * V_15 ) , V_18 ) ;
if ( ! V_15 )
return - V_19 ;
V_15 -> V_8 = F_7 ( V_13 , NULL ) ;
if ( F_8 ( V_15 -> V_8 ) )
return F_9 ( V_15 -> V_8 ) ;
V_16 = F_10 ( V_13 -> V_1 ,
V_20 ,
F_1 ,
V_15 ) ;
if ( V_16 ) {
F_11 ( V_15 -> V_8 ) ;
return V_16 ;
}
V_15 -> V_1 = V_13 -> V_1 ;
F_12 ( V_11 , V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_4 * V_15 = F_14 ( V_11 ) ;
F_15 ( V_15 -> V_1 ,
V_20 , F_1 ) ;
F_11 ( V_15 -> V_8 ) ;
return 0 ;
}
