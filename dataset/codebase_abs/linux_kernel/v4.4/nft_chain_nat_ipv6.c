static unsigned int F_1 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 V_9 ;
F_2 ( & V_9 , V_3 , V_5 ) ;
return F_3 ( & V_9 , V_1 ) ;
}
static unsigned int F_4 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_5 ( V_1 , V_3 , V_5 , F_1 ) ;
}
static unsigned int F_6 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_7 ( V_1 , V_3 , V_5 , F_1 ) ;
}
static unsigned int F_8 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_9 ( V_1 , V_3 , V_5 , F_1 ) ;
}
static unsigned int F_10 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_11 ( V_1 , V_3 , V_5 , F_1 ) ;
}
static int T_1 F_12 ( void )
{
int V_10 ;
V_10 = F_13 ( & V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_11 ) ;
}
