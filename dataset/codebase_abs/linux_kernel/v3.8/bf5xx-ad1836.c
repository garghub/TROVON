static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_10 [] = { 0 , 4 , 1 , 5 , 2 , 6 , 3 , 7 } ;
int V_11 = 0 ;
V_11 = F_2 ( V_9 , F_3 ( V_10 ) ,
V_10 , F_3 ( V_10 ) , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_16 ;
const char * * V_17 ;
int V_11 ;
V_17 = V_13 -> V_18 . V_19 ;
if ( ! V_17 ) {
F_5 ( & V_13 -> V_18 , L_1 ) ;
return - V_20 ;
}
V_21 . V_22 = V_17 [ 0 ] ;
V_21 . V_23 = V_17 [ 1 ] ;
V_15 -> V_18 = & V_13 -> V_18 ;
F_6 ( V_13 , V_15 ) ;
V_11 = F_7 ( V_15 ) ;
if ( V_11 )
F_5 ( & V_13 -> V_18 , L_2 ) ;
return V_11 ;
}
static int F_8 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_9 ( V_13 ) ;
F_10 ( V_15 ) ;
return 0 ;
}
