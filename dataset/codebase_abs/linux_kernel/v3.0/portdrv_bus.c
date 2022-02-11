static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( V_4 -> V_9 != & V_10 || V_2 -> V_9 != & V_10 )
return 0 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_4 ) ;
if ( V_8 -> V_11 != V_6 -> V_11 )
return 0 ;
if ( ( V_8 -> V_12 != V_13 ) &&
( V_8 -> V_12 != V_6 -> V_14 -> V_15 ) )
return 0 ;
return 1 ;
}
int F_4 ( void )
{
return F_5 ( & V_10 ) ;
}
void F_6 ( void )
{
F_7 ( & V_10 ) ;
}
