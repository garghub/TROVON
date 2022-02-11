struct V_1 * V_1 ( const struct V_2 * V_3 )
{
if ( ! V_3 -> V_4 )
return NULL ;
return F_1 ( V_3 -> V_4 , & V_5 ) ;
}
struct V_1 * F_2 ( const struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
if ( V_6 && V_6 -> V_7 != V_8 && V_6 -> V_7 != V_9 )
return NULL ;
return V_6 ;
}
struct V_1 * F_3 ( const struct V_2 * V_3 )
{
struct V_1 * V_6 = F_2 ( V_3 ) ;
F_4 ( V_6 != NULL ) ;
return V_6 ;
}
int F_5 ( void )
{
F_6 ( & V_5 ) ;
return F_7 ( & V_5 ) ;
}
void F_8 ( void )
{
F_9 ( & V_5 ) ;
}
