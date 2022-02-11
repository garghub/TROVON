static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , int V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 -> V_8 ) ;
unsigned long V_9 ;
F_3 ( V_9 ) ;
if ( V_4 )
F_4 ( V_10 , V_6 -> V_11 + V_5 ) ;
else
F_4 ( V_12 , V_6 -> V_11 + V_5 ) ;
F_5 ( V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_1 ( V_2 , V_4 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_1 ( V_2 , V_4 , V_14 ) ;
}
static int F_8 ( struct V_6 * V_15 )
{
int V_16 ;
V_16 = F_9 ( & V_15 -> V_7 , & V_17 ) ;
if ( V_16 < 0 )
return V_16 ;
return F_9 ( & V_15 -> V_7 , & V_18 ) ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_19 ) ;
}
