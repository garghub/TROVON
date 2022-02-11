static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_6 )
F_2 ( V_7 , 1 ) ;
else if ( V_5 & V_8 )
F_2 ( V_7 , 0 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_6 )
F_2 ( V_9 , 0 ) ;
else if ( V_5 & V_8 )
F_2 ( V_9 , 1 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = & V_14 ;
int V_15 ;
V_15 = F_5 ( V_16 ,
F_6 ( V_16 ) ) ;
if ( V_15 )
return V_15 ;
V_13 -> V_17 = & V_11 -> V_17 ;
V_15 = F_7 ( V_13 ) ;
if ( V_15 ) {
F_8 ( & V_11 -> V_17 , L_1 ,
V_15 ) ;
F_9 ( V_16 , F_6 ( V_16 ) ) ;
}
return V_15 ;
}
static int F_10 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_11 ( V_11 ) ;
F_9 ( V_16 , F_6 ( V_16 ) ) ;
F_12 ( V_13 ) ;
return 0 ;
}
