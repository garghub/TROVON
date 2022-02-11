int F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_3 ( V_2 ) ;
T_1 V_5 = F_2 ( V_4 -> V_5 ) ;
if ( V_4 -> V_6 != F_2 ( V_7 ) )
return 0 ;
return F_3 ( V_4 -> V_8 , & V_9 ,
& V_5 , sizeof( V_5 ) , V_10 ) ;
}
void F_4 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_3 ( V_2 ) ;
T_1 V_5 = F_2 ( V_4 -> V_5 ) ;
if ( V_4 -> V_6 != F_2 ( V_7 ) )
return;
F_5 ( V_4 -> V_8 , & V_9 ,
& V_5 , sizeof( V_5 ) , V_10 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , & V_9 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 , & V_9 ) ;
}
int T_2 F_10 ( void )
{
return F_11 ( & V_9 ) ;
}
void F_12 ( void )
{
F_13 ( & V_9 ) ;
}
