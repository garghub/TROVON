void F_1 ( unsigned int clock )
{
V_1 = clock ;
}
int F_2 ( void )
{
if ( F_3 ( V_2 ) )
return 0 ;
F_4 ( V_2 , V_1 / V_3 ) ;
F_4 ( V_4 , V_5 ) ;
return 1 ;
}
static int F_5 ( unsigned long V_6 ,
struct V_7 * V_8 )
{
T_1 V_9 ;
F_6 ( & V_10 ) ;
V_9 = F_3 ( V_4 ) ;
V_9 &= ~ ( V_5 | V_11 ) ;
V_9 |= V_5 ;
F_4 ( V_2 , V_6 ) ;
F_4 ( V_4 , V_9 ) ;
F_7 ( & V_10 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
T_1 V_9 ;
F_6 ( & V_10 ) ;
V_9 = F_3 ( V_4 ) ;
V_9 &= ~ ( V_5 | V_11 ) ;
F_4 ( V_4 , V_9 ) ;
F_7 ( & V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
T_1 V_9 ;
F_6 ( & V_10 ) ;
V_9 = F_3 ( V_4 ) ;
V_9 &= ~ V_11 ;
V_9 |= V_5 ;
F_4 ( V_4 , V_9 ) ;
F_7 ( & V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
T_1 V_9 ;
F_6 ( & V_10 ) ;
V_9 = F_3 ( V_4 ) ;
V_9 |= V_5 | V_11 ;
F_4 ( V_4 , V_9 ) ;
F_7 ( & V_10 ) ;
return 0 ;
}
static void F_11 ( struct V_7 * V_12 )
{
}
static T_2 F_12 ( int V_13 , void * V_14 )
{
struct V_7 * V_15 = & V_16 ;
V_15 -> V_17 ( V_15 ) ;
return V_18 ;
}
static int T_3 F_13 ( void )
{
struct V_7 * V_15 ;
if ( ! V_1 )
return 0 ;
F_4 ( V_2 , V_1 / V_3 ) ;
V_15 = & V_16 ;
V_15 -> V_19 = 200 + V_1 / 10000000 ;
F_14 ( V_15 , V_1 ) ;
V_15 -> V_20 = F_15 ( 0x7fffffff , V_15 ) ;
V_15 -> V_21 = F_15 ( 0x300 , V_15 ) ;
V_15 -> V_22 = F_16 ( 0 ) ;
F_17 ( & V_16 ) ;
return F_18 ( V_23 , & V_24 ) ;
}
