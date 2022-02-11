static bool F_1 ( void T_1 * V_1 , int V_2 )
{
F_2 ( V_3 | V_2 << 8 , V_1 + V_4 ) ;
F_3 ( 10 , 20 ) ;
F_2 ( V_3 | V_2 << 8 , V_1 + V_4 ) ;
return F_4 ( V_1 + V_5 ) ;
}
static int F_5 ( void * V_6 , int * V_7 )
{
struct V_8 * V_9 = V_6 ;
int V_10 = V_9 -> V_2 ;
if ( F_1 ( V_9 -> V_1 , V_10 ) ) {
while ( V_10 < V_11 && F_1 ( V_9 -> V_1 , ++ V_10 ) )
F_6 () ;
V_10 = V_10 - 1 ;
} else {
while ( V_10 > V_12 && ! F_1 ( V_9 -> V_1 , -- V_10 ) )
F_6 () ;
}
* V_7 = ( V_10 * 9 / 2 - 38 ) * 1000 ;
V_9 -> V_2 = V_10 ;
return 0 ;
}
static int F_7 ( struct V_13 * V_14 )
{
struct V_15 * V_7 ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
V_9 = F_8 ( & V_14 -> V_18 , sizeof( * V_9 ) , V_19 ) ;
if ( ! V_9 )
return - V_20 ;
V_7 = F_9 ( V_14 , V_21 , 0 ) ;
V_9 -> V_1 = F_10 ( & V_14 -> V_18 , V_7 ) ;
if ( F_11 ( V_9 -> V_1 ) )
return F_12 ( V_9 -> V_1 ) ;
V_9 -> V_2 = V_12 ;
F_2 ( 0 , V_9 -> V_1 + V_22 ) ;
F_2 ( V_23 , V_9 -> V_1 + V_4 ) ;
V_17 = F_13 ( & V_14 -> V_18 , 0 , V_9 , & V_24 ) ;
return F_14 ( V_17 ) ;
}
