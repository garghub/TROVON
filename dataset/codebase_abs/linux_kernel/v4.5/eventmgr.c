static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 V_5 = { { 0 } } ;
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
V_3 = F_4 ( V_2 , V_6 , & V_5 ) ;
if ( 0 != V_3 )
return V_3 ;
V_3 = F_5 ( V_2 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 V_5 = { { 0 } } ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_4 ( V_2 , V_7 , & V_5 ) ;
if ( V_2 != NULL )
F_9 ( V_2 ) ;
}
int F_10 ( struct V_8 * V_9 )
{
int V_3 = 0 ;
struct V_1 * V_2 ;
if ( V_9 == NULL )
return - V_10 ;
V_2 = F_11 ( sizeof( struct V_1 ) , V_11 ) ;
if ( V_2 == NULL )
return - V_12 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_9 -> V_2 = V_2 ;
V_2 -> V_14 = & ( V_2 -> V_13 -> V_14 ) ;
V_2 -> V_15 = F_1 ;
V_2 -> V_16 = F_6 ;
return V_3 ;
}
int F_12 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , enum V_17 V_18 , struct V_4 * V_19 )
{
if ( V_2 == NULL || V_18 >= V_20 || V_19 == NULL )
return - V_10 ;
return F_14 ( V_2 , V_2 -> V_21 [ V_18 ] , V_19 ) ;
}
int F_4 ( struct V_1 * V_2 , enum V_17 V_18 , struct V_4 * V_5 )
{
int V_22 = 0 ;
V_22 = F_13 ( V_2 , V_18 , V_5 ) ;
return V_22 ;
}
bool F_15 ( struct V_1 * V_2 )
{
return ( V_2 -> V_23 || F_16 ( V_2 -> V_13 ) ) ;
}
