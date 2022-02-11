static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 ;
F_2 ( & V_6 ) ;
F_3 (p) {
int V_7 = V_5 -> V_7 ;
if ( F_4 ( ! V_7 ) )
continue;
if ( V_5 -> V_8 )
F_5 ( V_2 , L_1 , V_7 ,
F_6 ( F_7 () , V_5 -> V_8 ) ) ;
}
F_8 ( & V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_9 , struct V_2 * V_2 )
{
return F_10 ( V_2 , F_1 , V_9 -> V_10 ) ;
}
static int T_1 F_11 ( void )
{
struct V_11 * V_12 ;
V_12 = F_12 ( L_2 , V_13 , V_14 ,
NULL , & V_15 ) ;
if ( ! V_12 )
return - V_16 ;
return F_13 ( V_12 ) ;
}
