static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , const T_1 * V_6 ,
unsigned int V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_4 () ) {
F_5 () ;
V_4 -> V_5 = F_6 ( V_4 -> V_5 , V_6 , V_7 ) ;
F_7 () ;
} else
V_4 -> V_5 = F_8 ( V_4 -> V_5 , V_6 , V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* ( V_9 * ) V_8 = V_4 -> V_5 ;
return 0 ;
}
static int F_10 ( V_9 * V_10 , const T_1 * V_6 , unsigned int V_11 ,
T_1 * V_8 )
{
if ( F_4 () ) {
F_5 () ;
* ( V_9 * ) V_8 = F_6 ( * V_10 , V_6 , V_11 ) ;
F_7 () ;
} else
* ( V_9 * ) V_8 = F_8 ( * V_10 , V_6 , V_11 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , const T_1 * V_6 ,
unsigned int V_11 , T_1 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_10 ( & V_4 -> V_5 , V_6 , V_11 , V_8 ) ;
}
static int F_12 ( struct V_1 * V_2 , const T_1 * V_6 ,
unsigned int V_7 , T_1 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_10 ( & V_4 -> V_5 , V_6 , V_7 , V_8 ) ;
}
static int T_2 F_13 ( void )
{
if ( ! F_14 ( V_12 ) )
return - V_13 ;
return F_15 ( & V_14 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_14 ) ;
}
