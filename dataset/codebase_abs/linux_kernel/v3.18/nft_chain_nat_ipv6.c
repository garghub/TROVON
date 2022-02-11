static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 V_11 ;
F_2 ( & V_11 , V_2 , V_4 , V_6 , V_7 ) ;
return F_3 ( & V_11 , V_2 ) ;
}
static unsigned int F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_5)( struct V_3 * ) )
{
return F_6 ( V_2 , V_4 , V_6 , V_7 , F_1 ) ;
}
static unsigned int F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_5)( struct V_3 * ) )
{
return F_8 ( V_2 , V_4 , V_6 , V_7 , F_1 ) ;
}
static unsigned int F_9 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_5)( struct V_3 * ) )
{
return F_10 ( V_2 , V_4 , V_6 , V_7 , F_1 ) ;
}
static unsigned int F_11 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_5)( struct V_3 * ) )
{
return F_12 ( V_2 , V_4 , V_6 , V_7 , F_1 ) ;
}
static int T_1 F_13 ( void )
{
int V_12 ;
V_12 = F_14 ( & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static void T_2 F_15 ( void )
{
F_16 ( & V_13 ) ;
}
