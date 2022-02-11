static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
void T_1 * V_7 ;
int V_8 ;
V_4 = F_2 ( & V_2 -> V_9 , sizeof( * V_4 ) , V_10 ) ;
if ( ! V_4 )
return - V_11 ;
V_6 = F_3 ( V_2 , V_12 , 0 ) ;
V_7 = F_4 ( & V_2 -> V_9 , V_6 ) ;
if ( F_5 ( V_7 ) )
return F_6 ( V_7 ) ;
V_4 -> V_13 = F_7 ( & V_2 -> V_9 , NULL , V_7 ,
& V_14 ) ;
if ( F_5 ( V_4 -> V_13 ) ) {
F_8 ( & V_2 -> V_9 ,
L_1 , F_6 ( V_4 -> V_13 ) ) ;
return F_6 ( V_4 -> V_13 ) ;
}
F_9 ( V_4 -> V_13 , V_15 ,
( V_16
| V_17
| V_18 ) ,
( V_19
| V_20 ) ) ;
F_10 ( V_2 , V_4 ) ;
V_8 = F_11 ( & V_2 -> V_9 , 0 , V_21 ,
F_12 ( V_21 ) , NULL , 0 , NULL ) ;
if ( V_8 ) {
F_8 ( & V_2 -> V_9 , L_2 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_9 ) ;
return 0 ;
}
