static unsigned int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
void T_2 * V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_5 + V_7 ) ;
V_4 = F_3 ( V_5 +
V_8 + ( V_9 << 2 ) ) ;
V_6 = V_4 - V_3 ;
return V_6 / V_10 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_3 , V_11 ;
void T_2 * V_5 ;
V_11 = V_2 -> V_12 * V_10 ;
V_5 = F_2 ( V_2 ) ;
F_5 ( 1 , V_5 + V_13 ) ;
V_3 = F_3 ( V_5 + V_14 ) ;
V_3 += V_11 ;
F_5 ( V_3 , V_5 +
V_8 + ( V_9 << 2 ) ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
void T_2 * V_5 = F_2 ( V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( F_3 ( V_5 + V_15 )
| ( 1 << V_9 ) ,
V_5 + V_15 ) ;
F_5 ( 1 , V_5 + V_16 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
void T_2 * V_5 = F_2 ( V_2 ) ;
F_5 ( 0 , V_5 + V_16 ) ;
F_5 ( F_3 ( V_5 + V_15 )
& ( ~ ( 1 << V_9 ) ) ,
V_5 + V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_17 )
{
V_2 -> V_12 = V_17 ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
int V_22 ;
void T_2 * V_23 ;
V_21 = F_10 ( V_19 , V_24 , 0 ) ;
V_23 = F_11 ( & V_19 -> V_25 , V_21 ) ;
if ( F_12 ( V_23 ) )
return F_13 ( V_23 ) ;
F_14 ( & V_26 , V_23 ) ;
F_15 ( & V_26 , V_12 , & V_19 -> V_25 ) ;
F_16 ( & V_26 , V_27 ) ;
V_26 . V_28 = & V_19 -> V_25 ;
V_22 = F_17 ( & V_26 ) ;
if ( V_22 )
return V_22 ;
F_18 ( V_19 , & V_26 ) ;
return 0 ;
}
static void F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_20 ( V_19 ) ;
F_7 ( V_2 ) ;
}
static int F_21 ( struct V_18 * V_19 )
{
F_19 ( V_19 ) ;
return 0 ;
}
static int F_22 ( struct V_29 * V_25 )
{
return 0 ;
}
static int F_23 ( struct V_29 * V_25 )
{
struct V_1 * V_2 = F_24 ( V_25 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
