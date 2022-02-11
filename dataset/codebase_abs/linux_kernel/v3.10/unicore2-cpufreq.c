int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return - V_4 ;
F_2 ( V_2 ,
V_2 -> V_5 . V_6 , V_2 -> V_5 . V_7 ) ;
return 0 ;
}
static unsigned int F_3 ( unsigned int V_3 )
{
struct V_8 * V_9 = F_4 ( NULL , L_1 ) ;
if ( V_3 )
return 0 ;
return F_5 ( V_9 ) / 1000 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_10 ,
unsigned int V_11 )
{
unsigned int V_12 = F_3 ( 0 ) ;
struct V_13 V_14 ;
struct V_8 * V_9 = F_4 ( NULL , L_1 ) ;
F_7 ( V_2 , & V_14 , V_15 ) ;
if ( ! F_8 ( V_9 , V_10 * 1000 ) ) {
V_14 . V_16 = V_12 ;
V_14 . V_17 = V_10 ;
}
F_7 ( V_2 , & V_14 , V_18 ) ;
return 0 ;
}
static int T_1 F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != 0 )
return - V_4 ;
V_2 -> V_12 = F_3 ( 0 ) ;
V_2 -> V_19 = V_2 -> V_5 . V_6 = 250000 ;
V_2 -> V_20 = V_2 -> V_5 . V_7 = 1000000 ;
V_2 -> V_5 . V_21 = V_22 ;
return 0 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_23 ) ;
}
