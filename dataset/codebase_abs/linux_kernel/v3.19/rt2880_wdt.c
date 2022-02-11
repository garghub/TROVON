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
F_1 ( V_6 , V_5 -> V_7 * V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 )
{
T_1 V_9 ;
V_9 = F_3 ( V_10 ) ;
V_9 &= ~ ( V_11 << V_12 |
V_13 ) ;
V_9 |= ( V_14 << V_12 |
V_15 ) ;
F_1 ( V_10 , V_9 ) ;
F_5 ( V_5 ) ;
V_9 = F_3 ( V_10 ) ;
V_9 |= V_16 ;
F_1 ( V_10 , V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 )
{
T_1 V_9 ;
F_5 ( V_5 ) ;
V_9 = F_3 ( V_10 ) ;
V_9 &= ~ V_16 ;
F_1 ( V_10 , V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_4 * V_5 , unsigned int V_9 )
{
V_5 -> V_7 = V_9 ;
F_5 ( V_5 ) ;
return 0 ;
}
static int F_9 ( void )
{
if ( F_10 ( V_17 ) & V_18 )
return V_19 ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
int V_24 ;
V_23 = F_12 ( V_21 , V_25 , 0 ) ;
V_3 = F_13 ( & V_21 -> V_26 , V_23 ) ;
if ( F_14 ( V_3 ) )
return F_15 ( V_3 ) ;
V_27 = F_16 ( & V_21 -> V_26 , NULL ) ;
if ( F_14 ( V_27 ) )
return F_15 ( V_27 ) ;
F_17 ( & V_21 -> V_26 ) ;
V_8 = F_18 ( V_27 ) / V_28 ;
V_29 . V_26 = & V_21 -> V_26 ;
V_29 . V_30 = F_9 () ;
V_29 . V_31 = ( 0xfffful / V_8 ) ;
V_29 . V_7 = V_29 . V_31 ;
F_19 ( & V_29 , V_32 ) ;
V_24 = F_20 ( & V_29 ) ;
if ( ! V_24 )
F_21 ( & V_21 -> V_26 , L_1 ) ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 )
{
F_23 ( & V_29 ) ;
return 0 ;
}
static void F_24 ( struct V_20 * V_21 )
{
F_7 ( & V_29 ) ;
}
