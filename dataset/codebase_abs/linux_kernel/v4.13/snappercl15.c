static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 , 0 , V_12 ,
V_13 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_2 ( V_10 , 0 , V_12 ,
V_14 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_3 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_19 ;
int V_20 ;
V_20 = F_4 () ;
if ( V_20 )
return V_20 ;
V_18 -> V_21 = & V_16 -> V_21 ;
V_20 = F_5 ( V_18 ) ;
if ( V_20 ) {
F_6 ( & V_16 -> V_21 , L_1 ,
V_20 ) ;
F_7 () ;
}
return V_20 ;
}
static int F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_9 ( V_16 ) ;
F_10 ( V_18 ) ;
F_7 () ;
return 0 ;
}
