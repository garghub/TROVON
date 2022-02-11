static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
unsigned int V_12 ;
unsigned int V_13 = F_2 ( V_4 ) ;
if ( V_13 < 50000 )
V_12 = V_13 * 64 * 4 ;
else
V_12 = V_13 * 64 * 2 ;
V_11 = F_3 ( V_9 , 0 , V_12 ,
V_14 ) ;
if ( V_11 )
return V_11 ;
return F_3 ( V_10 , 0 , V_12 ,
V_15 ) ;
}
static int T_1 F_4 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_20 ;
int V_21 ;
V_21 = F_5 () ;
if ( V_21 )
return V_21 ;
V_19 -> V_22 = & V_17 -> V_22 ;
V_21 = F_6 ( V_19 ) ;
if ( V_21 ) {
F_7 ( & V_17 -> V_22 , L_1 ,
V_21 ) ;
F_8 () ;
}
return V_21 ;
}
static int T_2 F_9 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_10 ( V_17 ) ;
F_11 ( V_19 ) ;
F_8 () ;
return 0 ;
}
