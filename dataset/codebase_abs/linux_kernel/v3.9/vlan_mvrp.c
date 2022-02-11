int F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_3 ( V_2 ) ;
T_1 V_5 = F_2 ( V_4 -> V_5 ) ;
return F_3 ( V_4 -> V_6 , & V_7 ,
& V_5 , sizeof( V_5 ) , V_8 ) ;
}
void F_4 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_3 ( V_2 ) ;
T_1 V_5 = F_2 ( V_4 -> V_5 ) ;
F_5 ( V_4 -> V_6 , & V_7 ,
& V_5 , sizeof( V_5 ) , V_8 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , & V_7 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 , & V_7 ) ;
}
int T_2 F_10 ( void )
{
return F_11 ( & V_7 ) ;
}
void F_12 ( void )
{
F_13 ( & V_7 ) ;
}
