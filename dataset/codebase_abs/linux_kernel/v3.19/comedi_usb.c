struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ? F_2 ( V_3 -> V_4 ) : NULL ;
}
struct V_5 * F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return V_6 ? F_4 ( V_6 ) : NULL ;
}
int F_5 ( struct V_1 * V_6 ,
struct V_7 * V_8 ,
unsigned long V_9 )
{
return F_6 ( & V_6 -> V_3 , V_8 , V_9 ) ;
}
void F_7 ( struct V_1 * V_6 )
{
F_8 ( & V_6 -> V_3 ) ;
}
int F_9 ( struct V_7 * V_7 ,
struct V_10 * V_10 )
{
int V_11 ;
V_11 = F_10 ( V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_11 ( V_10 ) ;
if ( V_11 < 0 ) {
F_12 ( V_7 ) ;
return V_11 ;
}
return 0 ;
}
void F_13 ( struct V_7 * V_7 ,
struct V_10 * V_10 )
{
F_14 ( V_10 ) ;
F_12 ( V_7 ) ;
}
static int T_1 F_15 ( void )
{
return 0 ;
}
static void T_2 F_16 ( void )
{
}
