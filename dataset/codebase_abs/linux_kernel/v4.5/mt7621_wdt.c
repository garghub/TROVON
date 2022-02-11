static inline void F_1 ( unsigned V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_3 + V_1 ) ;
}
static inline T_1 F_3 ( unsigned V_1 )
{
return F_4 ( V_3 + V_1 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
F_1 ( V_6 , V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 , unsigned int V_8 )
{
V_5 -> V_9 = V_8 ;
F_1 ( V_10 , V_8 * 1000 ) ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 )
{
T_1 V_8 ;
F_1 ( V_11 , 1000 << V_12 ) ;
F_6 ( V_5 , V_5 -> V_9 ) ;
V_8 = F_3 ( V_11 ) ;
V_8 |= V_13 ;
F_1 ( V_11 , V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_4 * V_5 )
{
T_1 V_8 ;
F_5 ( V_5 ) ;
V_8 = F_3 ( V_11 ) ;
V_8 &= ~ V_13 ;
F_1 ( V_11 , V_8 ) ;
return 0 ;
}
static int F_9 ( void )
{
if ( F_10 ( V_14 ) & V_15 )
return V_16 ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
int V_21 ;
V_20 = F_12 ( V_18 , V_22 , 0 ) ;
V_3 = F_13 ( & V_18 -> V_23 , V_20 ) ;
if ( F_14 ( V_3 ) )
return F_15 ( V_3 ) ;
V_24 = F_16 ( & V_18 -> V_23 , NULL ) ;
if ( ! F_14 ( V_24 ) )
F_17 ( V_24 ) ;
V_25 . V_23 = & V_18 -> V_23 ;
V_25 . V_26 = F_9 () ;
F_18 ( & V_25 , V_25 . V_27 ,
& V_18 -> V_23 ) ;
F_19 ( & V_25 , V_28 ) ;
V_21 = F_20 ( & V_25 ) ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 )
{
F_22 ( & V_25 ) ;
return 0 ;
}
static void F_23 ( struct V_17 * V_18 )
{
F_8 ( & V_25 ) ;
}
