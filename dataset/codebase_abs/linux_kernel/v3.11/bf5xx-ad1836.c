static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_5 [] = { 0 , 4 , 1 , 5 , 2 , 6 , 3 , 7 } ;
int V_6 = 0 ;
V_6 = F_2 ( V_4 , F_3 ( V_5 ) ,
V_5 , F_3 ( V_5 ) , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_4 , 0xFF , 0xFF , 8 , 32 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_11 ;
const char * * V_12 ;
int V_6 ;
V_12 = V_8 -> V_13 . V_14 ;
if ( ! V_12 ) {
F_6 ( & V_8 -> V_13 , L_1 ) ;
return - V_15 ;
}
V_16 . V_17 = V_12 [ 0 ] ;
V_16 . V_18 = V_12 [ 1 ] ;
V_10 -> V_13 = & V_8 -> V_13 ;
F_7 ( V_8 , V_10 ) ;
V_6 = F_8 ( V_10 ) ;
if ( V_6 )
F_6 ( & V_8 -> V_13 , L_2 ) ;
return V_6 ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_10 ( V_8 ) ;
F_11 ( V_10 ) ;
return 0 ;
}
