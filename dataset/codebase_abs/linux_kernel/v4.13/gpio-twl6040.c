static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 -> V_5 ) ;
int V_6 = 0 ;
V_6 = F_3 ( V_4 , V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
return ( V_6 >> V_3 ) & 1 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 ,
int V_8 )
{
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 , int V_8 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 -> V_5 ) ;
int V_6 ;
T_1 V_9 ;
V_6 = F_3 ( V_4 , V_7 ) ;
if ( V_6 < 0 )
return;
if ( V_8 )
V_9 = V_6 | ( 1 << V_3 ) ;
else
V_9 = V_6 & ~ ( 1 << V_3 ) ;
F_6 ( V_4 , V_7 , V_9 ) ;
}
static int F_7 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 . V_5 ;
struct V_4 * V_4 = F_2 ( V_13 ) ;
int V_6 ;
V_15 . V_16 = - 1 ;
if ( F_8 ( V_4 ) < V_17 )
V_15 . V_18 = 3 ;
else
V_15 . V_18 = 1 ;
V_15 . V_5 = & V_11 -> V_14 ;
#ifdef F_9
V_15 . V_19 = V_13 -> V_19 ;
#endif
V_6 = F_10 ( & V_11 -> V_14 , & V_15 , NULL ) ;
if ( V_6 < 0 ) {
F_11 ( & V_11 -> V_14 , L_1 , V_6 ) ;
V_15 . V_18 = 0 ;
}
return V_6 ;
}
