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
int V_9 = 0 ;
V_10:
if ( ! F_9 ( & V_11 , V_12 ) )
return - V_13 ;
F_10 ( & V_14 ) ;
V_9 = F_11 ( & V_11 , V_2 , & V_2 -> V_15 ) ;
F_12 ( & V_14 ) ;
switch ( V_9 ) {
case 0 :
break;
case - V_16 :
goto V_10;
default:
return V_9 ;
}
V_6 = F_2 ( V_8 , V_4 , F_3 ( 0 , 0 ) , NULL , L_2 , V_2 -> V_15 ) ;
if ( F_4 ( V_6 ) ) {
F_10 ( & V_14 ) ;
F_13 ( & V_11 , V_2 -> V_15 ) ;
F_12 ( & V_14 ) ;
return F_5 ( V_6 ) ;
}
V_2 -> V_6 = V_6 ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
F_10 ( & V_14 ) ;
F_13 ( & V_11 , V_2 -> V_15 ) ;
F_12 ( & V_14 ) ;
}
int T_1 F_16 ( void )
{
F_17 ( & V_11 ) ;
F_18 ( & V_14 ) ;
V_8 = F_19 ( V_17 , L_3 ) ;
if ( F_4 ( V_8 ) ) {
F_20 ( & V_11 ) ;
return F_5 ( V_8 ) ;
}
return 0 ;
}
void T_2 F_21 ( void )
{
F_22 ( V_8 ) ;
F_20 ( & V_11 ) ;
}
