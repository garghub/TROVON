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
static void F_7 ( struct V_8 * V_9 )
{
F_2 ( 0 , V_9 -> V_1 + V_13 ) ;
F_2 ( V_14 , V_9 -> V_1 + V_4 ) ;
}
static int F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_7 ;
struct V_8 * V_9 ;
struct V_18 * V_19 ;
V_9 = F_9 ( & V_16 -> V_20 , sizeof( * V_9 ) , V_21 ) ;
if ( ! V_9 )
return - V_22 ;
V_7 = F_10 ( V_16 , V_23 , 0 ) ;
V_9 -> V_1 = F_11 ( & V_16 -> V_20 , V_7 ) ;
if ( F_12 ( V_9 -> V_1 ) )
return F_13 ( V_9 -> V_1 ) ;
F_14 ( V_16 , V_9 ) ;
V_9 -> V_2 = V_12 ;
F_7 ( V_9 ) ;
V_19 = F_15 ( & V_16 -> V_20 , 0 , V_9 , & V_24 ) ;
return F_16 ( V_19 ) ;
}
static int T_2 F_17 ( struct V_25 * V_20 )
{
F_7 ( F_18 ( V_20 ) ) ;
return 0 ;
}
