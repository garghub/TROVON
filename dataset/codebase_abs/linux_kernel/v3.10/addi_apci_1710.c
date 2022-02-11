static void F_1 ( void )
{
F_2 () ;
}
static void F_3 ( void )
{
F_4 () ;
}
static T_1 F_5 ( int V_1 , void * V_2 )
{
F_6 ( V_1 , V_2 ) ;
return F_7 ( 1 ) ;
}
static int F_8 ( struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_6 * V_7 = F_9 ( V_4 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 ;
V_9 = F_10 ( sizeof( * V_9 ) , V_13 ) ;
if ( ! V_9 )
return - V_14 ;
V_4 -> V_15 = V_9 ;
V_12 = F_11 ( V_4 ) ;
if ( V_12 )
return V_12 ;
V_9 -> V_16 . V_17 = F_12 ( V_7 , 2 ) ;
if ( V_7 -> V_1 > 0 ) {
V_12 = F_13 ( V_7 -> V_1 , F_5 , V_18 ,
V_4 -> V_19 , V_4 ) ;
if ( V_12 == 0 )
V_4 -> V_1 = V_7 -> V_1 ;
}
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
return 0 ;
}
static void F_16 ( struct V_3 * V_4 )
{
if ( V_4 -> V_20 )
F_15 ( V_4 ) ;
if ( V_4 -> V_1 )
F_17 ( V_4 -> V_1 , V_4 ) ;
F_18 ( V_4 ) ;
}
static int F_19 ( struct V_6 * V_4 ,
const struct V_21 * V_22 )
{
return F_20 ( V_4 , & V_23 , V_22 -> V_24 ) ;
}
