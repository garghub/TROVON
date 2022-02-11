static void F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
F_3 ( & V_7 -> V_9 ) ;
V_8 = F_4 ( V_7 -> V_10 + V_3 ) ;
V_8 &= ~ F_5 ( V_5 ) ;
if ( V_4 )
V_8 |= F_5 ( V_5 ) ;
F_6 ( V_8 , V_7 -> V_10 + V_3 ) ;
F_7 ( & V_7 -> V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_11 ,
unsigned int V_5 )
{
unsigned int V_12 = V_5 / 8 ;
unsigned int V_13 ;
V_13 = V_12 ? V_14 : V_15 ;
F_1 ( V_2 , V_13 , V_11 , V_5 % 8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_5 ,
int V_16 )
{
return F_8 ( V_2 , 0 , V_5 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_5 )
{
return F_8 ( V_2 , 1 , V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_16 ;
F_3 ( & V_7 -> V_9 ) ;
V_16 = F_4 ( V_7 -> V_10 + V_3 ) ;
F_7 ( & V_7 -> V_9 ) ;
return ! ! V_16 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_5 )
{
unsigned int V_12 = V_5 / 8 ;
unsigned int V_13 ;
int V_4 ;
V_13 = V_12 ? V_14 : V_15 ;
V_4 = F_11 ( V_2 , V_13 ) >> ( V_5 % 8 ) ;
return ! ! V_4 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_5 )
{
unsigned int V_12 = V_5 / 8 ;
unsigned int V_13 ;
int V_4 ;
V_13 = V_12 ? V_17 : V_18 ;
V_4 = F_11 ( V_2 , V_13 ) >> ( V_5 % 8 ) ;
return ! ! V_4 ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_5 ,
int V_16 )
{
unsigned int V_12 = V_5 / 8 ;
unsigned int V_13 ;
V_13 = V_12 ? V_18 : V_17 ;
F_1 ( V_2 , V_13 , V_16 , V_5 % 8 ) ;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_16 ( V_20 ) ;
struct V_6 * V_7 ;
void T_1 * V_23 ;
int V_24 , V_25 ;
if ( V_22 -> V_26 != V_27 )
return - V_28 ;
V_23 = F_17 ( V_22 , 0 , 0 ) ;
if ( ! V_23 )
return - V_29 ;
V_7 = F_18 ( & V_22 -> V_30 , sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 )
return - V_29 ;
F_19 ( & V_7 -> V_9 ) ;
V_24 = F_20 ( & V_32 , 0 , 0 , V_31 ) ;
sprintf ( V_7 -> V_33 , L_1 , V_24 ) ;
V_7 -> V_1 . V_34 = V_7 -> V_33 ;
V_7 -> V_1 . V_35 = & V_22 -> V_30 ;
V_7 -> V_1 . V_36 = F_9 ;
V_7 -> V_1 . V_37 = F_10 ;
V_7 -> V_1 . V_38 = F_12 ;
V_7 -> V_1 . V_39 = F_13 ;
V_7 -> V_1 . V_40 = F_14 ;
V_7 -> V_1 . V_41 = - 1 ;
V_7 -> V_1 . V_42 = 16 ;
V_7 -> V_10 = V_23 ;
V_7 -> V_24 = V_24 ;
V_25 = F_21 ( & V_22 -> V_30 ,
& V_7 -> V_1 , V_7 ) ;
if ( V_25 )
goto V_43;
F_22 ( V_20 , V_7 ) ;
return 0 ;
V_43:
F_23 ( & V_32 , V_24 ) ;
F_24 ( & V_7 -> V_9 ) ;
return V_25 ;
}
static int F_25 ( struct V_19 * V_20 )
{
struct V_6 * V_7 = F_16 ( V_20 ) ;
F_23 ( & V_32 , V_7 -> V_24 ) ;
F_24 ( & V_7 -> V_9 ) ;
return 0 ;
}
