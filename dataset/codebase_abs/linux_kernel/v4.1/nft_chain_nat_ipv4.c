static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 V_10 ;
F_2 ( & V_10 , V_2 , V_4 , V_6 ) ;
return F_3 ( & V_10 , V_2 ) ;
}
static unsigned int F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_5 ( V_2 , V_4 , V_6 , F_1 ) ;
}
static unsigned int F_6 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_7 ( V_2 , V_4 , V_6 , F_1 ) ;
}
static unsigned int F_8 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_9 ( V_2 , V_4 , V_6 , F_1 ) ;
}
static unsigned int F_10 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_11 ( V_2 , V_4 , V_6 , F_1 ) ;
}
static int T_1 F_12 ( void )
{
int V_11 ;
V_11 = F_13 ( & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_12 ) ;
}
