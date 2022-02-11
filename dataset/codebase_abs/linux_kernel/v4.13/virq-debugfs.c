static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
F_2 ( V_2 , L_1 , L_2 , L_3 , L_4 ) ;
for ( V_4 = 1 ; V_4 < V_5 ; V_4 ++ ) {
struct V_6 * V_7 = F_3 ( V_4 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( ! V_9 )
continue;
F_2 ( V_2 , L_5 , V_4 ) ;
F_2 ( V_2 , L_6 , V_7 -> V_10 ) ;
F_2 ( V_2 , L_7 , V_9 -> V_11 . V_12 ) ;
}
return 0 ;
}
static int F_4 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
return F_5 ( V_14 , F_1 , V_13 -> V_15 ) ;
}
static int T_1 F_6 ( void )
{
if ( F_7 ( L_8 , V_16 , NULL , NULL ,
& V_17 ) == NULL )
return - V_18 ;
return 0 ;
}
