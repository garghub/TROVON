static void T_1 * F_1 ( struct V_1 * V_2 )
{
return ( void T_1 V_3 * ) F_2 ( V_2 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
T_2 V_4 , V_5 ;
void T_1 * V_6 ;
int V_7 ;
V_6 = F_1 ( V_2 ) ;
V_4 = F_4 ( V_6 + V_8 ) ;
V_5 = F_4 ( V_6 +
V_9 + ( V_10 << 2 ) ) ;
V_7 = V_5 - V_4 ;
return V_7 / V_11 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_2 V_4 , V_12 ;
void T_1 * V_6 ;
V_12 = V_2 -> V_13 * V_11 ;
V_6 = F_1 ( V_2 ) ;
F_6 ( 1 , V_6 + V_14 ) ;
V_4 = F_4 ( V_6 + V_15 ) ;
V_4 += V_12 ;
F_6 ( V_4 , V_6 +
V_9 + ( V_10 << 2 ) ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
void T_1 * V_6 = F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
F_6 ( F_4 ( V_6 + V_16 )
| ( 1 << V_10 ) ,
V_6 + V_16 ) ;
F_6 ( 1 , V_6 + V_17 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
void T_1 * V_6 = F_1 ( V_2 ) ;
F_6 ( 0 , V_6 + V_17 ) ;
F_6 ( F_4 ( V_6 + V_16 )
& ( ~ ( 1 << V_10 ) ) ,
V_6 + V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_18 )
{
V_2 -> V_13 = V_18 ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_23 ;
void T_1 * V_24 ;
V_22 = F_11 ( V_20 , V_25 , 0 ) ;
V_24 = F_12 ( & V_20 -> V_26 , V_22 ) ;
if ( F_13 ( V_24 ) )
return F_14 ( V_24 ) ;
F_15 ( & V_27 , ( V_3 void * ) V_24 ) ;
F_16 ( & V_27 , V_13 , & V_20 -> V_26 ) ;
F_17 ( & V_27 , V_28 ) ;
V_27 . V_29 = & V_20 -> V_26 ;
V_23 = F_18 ( & V_27 ) ;
if ( V_23 )
return V_23 ;
F_19 ( V_20 , & V_27 ) ;
return 0 ;
}
static void F_20 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_21 ( V_20 ) ;
F_8 ( V_2 ) ;
}
static int F_22 ( struct V_19 * V_20 )
{
F_20 ( V_20 ) ;
return 0 ;
}
static int F_23 ( struct V_30 * V_26 )
{
return 0 ;
}
static int F_24 ( struct V_30 * V_26 )
{
struct V_1 * V_2 = F_25 ( V_26 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
