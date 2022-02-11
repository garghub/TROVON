static unsigned int
F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static void
F_2 ( struct V_1 * V_2 )
{
}
static int
F_3 ( struct V_1 * V_3 , const struct V_4 * V_5 , bool V_6 )
{
return 0 ;
}
static void F_4 ( int V_7 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
if ( V_9 == & V_10 )
F_6 ( V_7 , & V_11 ) ;
}
static void F_7 ( int V_12 , int V_7 )
{
F_8 ( V_12 , V_7 , 0 , 0 , V_13 ) ;
}
int F_9 ( int V_12 )
{
int V_7 = F_10 ( V_14 ) ;
if ( V_7 >= 0 ) {
F_4 ( V_7 ) ;
F_11 ( V_7 , V_15 ) ;
F_7 ( V_12 , V_7 ) ;
}
return V_7 ;
}
void T_1
F_12 ( void )
{
int V_16 ;
F_13 (i)
F_4 ( V_16 ) ;
}
