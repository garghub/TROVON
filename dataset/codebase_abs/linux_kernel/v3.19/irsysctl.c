static int F_1 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
int V_7 ;
V_7 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_7 == 0 && V_3 ) {
struct V_8 * V_9 ;
V_9 = F_3 ( V_10 ) ;
if ( V_9 )
F_4 ( L_1 , L_2 , V_9 ) ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
int V_7 ;
V_7 = F_6 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_7 )
return V_7 ;
if ( V_11 == NULL )
return - V_12 ;
if ( V_13 )
F_7 ( V_11 , V_14 * V_15 ) ;
else
F_8 ( & V_11 -> V_16 ) ;
return V_7 ;
}
int T_4 F_9 ( void )
{
V_17 = F_10 ( & V_18 , L_3 , V_19 ) ;
if ( ! V_17 )
return - V_20 ;
return 0 ;
}
void F_11 ( void )
{
F_12 ( V_17 ) ;
}
