static int F_1 ( T_1 * V_1 , int V_2 ,
void T_2 * V_3 , T_3 * V_4 , T_4 * V_5 )
{
int V_6 ;
V_6 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 == 0 && V_2 ) {
struct V_7 * V_8 ;
V_8 = F_3 ( V_9 ) ;
if ( V_8 )
F_4 ( L_1 , L_2 , V_8 ) ;
}
return V_6 ;
}
static int F_5 ( T_1 * V_1 , int V_2 ,
void T_2 * V_3 , T_3 * V_4 , T_4 * V_5 )
{
int V_6 ;
V_6 = F_6 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
if ( V_10 == NULL )
return - V_11 ;
if ( V_12 )
F_7 ( V_10 , V_13 * V_14 ) ;
else
F_8 ( & V_10 -> V_15 ) ;
return V_6 ;
}
int T_5 F_9 ( void )
{
V_16 = F_10 ( V_17 , V_18 ) ;
if ( ! V_16 )
return - V_19 ;
return 0 ;
}
void F_11 ( void )
{
F_12 ( V_16 ) ;
}
