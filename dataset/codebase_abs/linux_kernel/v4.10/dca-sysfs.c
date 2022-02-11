int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_3 * V_6 ;
static int V_7 ;
V_6 = F_2 ( V_8 , V_2 -> V_6 , F_3 ( 0 , V_5 + 1 ) , NULL ,
L_1 , V_7 ++ ) ;
if ( F_4 ( V_6 ) )
return F_5 ( V_6 ) ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 , int V_5 )
{
F_7 ( V_8 , F_3 ( 0 , V_5 + 1 ) ) ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_6 ;
int V_9 ;
F_9 ( V_10 ) ;
F_10 ( & V_11 ) ;
V_9 = F_11 ( & V_12 , V_2 , 0 , 0 , V_13 ) ;
if ( V_9 >= 0 )
V_2 -> V_14 = V_9 ;
F_12 ( & V_11 ) ;
F_13 () ;
if ( V_9 < 0 )
return V_9 ;
V_6 = F_2 ( V_8 , V_4 , F_3 ( 0 , 0 ) , NULL , L_2 , V_2 -> V_14 ) ;
if ( F_4 ( V_6 ) ) {
F_10 ( & V_11 ) ;
F_14 ( & V_12 , V_2 -> V_14 ) ;
F_12 ( & V_11 ) ;
return F_5 ( V_6 ) ;
}
V_2 -> V_6 = V_6 ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
F_10 ( & V_11 ) ;
F_14 ( & V_12 , V_2 -> V_14 ) ;
F_12 ( & V_11 ) ;
}
int T_1 F_17 ( void )
{
F_18 ( & V_12 ) ;
F_19 ( & V_11 ) ;
V_8 = F_20 ( V_15 , L_3 ) ;
if ( F_4 ( V_8 ) ) {
F_21 ( & V_12 ) ;
return F_5 ( V_8 ) ;
}
return 0 ;
}
void T_2 F_22 ( void )
{
F_23 ( V_8 ) ;
F_21 ( & V_12 ) ;
}
