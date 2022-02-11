static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( F_4 ( V_2 ) ) ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( F_3 ( F_4 ( V_2 ) ) ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short * V_4 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
unsigned short V_7 = V_8 | V_9 | V_3 ;
return F_8 ( V_6 , ( V_10 * ) & V_7 , 2 , ( V_10 * ) V_4 , 2 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short V_4 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
unsigned short V_7 [ 2 ] = {
V_8 | V_3 ,
V_4
} ;
return F_10 ( V_6 , ( V_10 * ) V_7 , 4 ) ;
}
static int T_1 F_11 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
V_12 = F_12 ( & V_6 -> V_2 , V_13 , V_6 -> V_14 ,
F_7 , F_9 ) ;
if ( F_13 ( V_12 ) )
return F_14 ( V_12 ) ;
F_15 ( V_6 , V_12 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_3 ( V_6 ) ;
F_17 ( V_12 ) ;
F_15 ( V_6 , NULL ) ;
return 0 ;
}
static T_3 int F_18 ( void )
{
return F_19 ( & V_15 ) ;
}
static T_4 void F_20 ( void )
{
F_21 ( & V_15 ) ;
}
