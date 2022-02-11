static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_2 ( V_4 , ( void V_5 * ) V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_2 ( V_4 , ( void V_5 * ) V_7 ) ;
}
static int F_4 ( struct V_8 * V_9 )
{
int V_10 ;
V_10 = F_5 ( & V_9 -> V_11 , & V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( & V_9 -> V_11 , & V_13 ) ;
if ( V_10 < 0 )
F_6 ( & V_12 ) ;
return V_10 ;
}
static int F_7 ( struct V_8 * V_9 )
{
F_6 ( & V_12 ) ;
F_6 ( & V_13 ) ;
return 0 ;
}
