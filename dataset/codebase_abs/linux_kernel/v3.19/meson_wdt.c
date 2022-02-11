static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
T_1 V_5 = V_6 | V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ,
struct V_8 ,
V_10 ) ;
while ( 1 ) {
F_3 ( V_5 , V_9 -> V_11 + V_12 ) ;
F_4 ( 5 ) ;
}
return V_13 ;
}
static int F_5 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = F_6 ( V_15 ) ;
F_3 ( 0 , V_9 -> V_11 + V_16 ) ;
return 0 ;
}
static void F_7 ( struct V_14 * V_15 ,
unsigned int V_17 )
{
struct V_8 * V_9 = F_6 ( V_15 ) ;
T_1 V_18 ;
V_18 = F_8 ( V_9 -> V_11 + V_12 ) ;
V_18 &= ~ V_19 ;
V_18 |= F_9 ( V_17 ) ;
F_3 ( V_18 , V_9 -> V_11 + V_12 ) ;
}
static int F_10 ( struct V_14 * V_15 ,
unsigned int V_17 )
{
V_15 -> V_17 = V_17 ;
F_7 ( V_15 , V_17 ) ;
F_5 ( V_15 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = F_6 ( V_15 ) ;
T_1 V_18 ;
V_18 = F_8 ( V_9 -> V_11 + V_12 ) ;
V_18 &= ~ V_7 ;
F_3 ( V_18 , V_9 -> V_11 + V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = F_6 ( V_15 ) ;
T_1 V_18 ;
F_7 ( V_15 , V_9 -> V_15 . V_17 ) ;
F_5 ( V_15 ) ;
V_18 = F_8 ( V_9 -> V_11 + V_12 ) ;
V_18 |= V_7 ;
F_3 ( V_18 , V_9 -> V_11 + V_12 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
struct V_8 * V_9 ;
int V_24 ;
V_9 = F_14 ( & V_21 -> V_25 , sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
V_23 = F_15 ( V_21 , V_28 , 0 ) ;
V_9 -> V_11 = F_16 ( & V_21 -> V_25 , V_23 ) ;
if ( F_17 ( V_9 -> V_11 ) )
return F_18 ( V_9 -> V_11 ) ;
V_9 -> V_15 . V_29 = & V_21 -> V_25 ;
V_9 -> V_15 . V_30 = & V_31 ;
V_9 -> V_15 . V_32 = & V_33 ;
V_9 -> V_15 . V_17 = V_34 ;
V_9 -> V_15 . V_35 = V_36 ;
V_9 -> V_15 . V_37 = V_38 ;
F_19 ( & V_9 -> V_15 , V_9 ) ;
F_20 ( & V_9 -> V_15 , V_17 , & V_21 -> V_25 ) ;
F_21 ( & V_9 -> V_15 , V_39 ) ;
F_11 ( & V_9 -> V_15 ) ;
V_24 = F_22 ( & V_9 -> V_15 ) ;
if ( V_24 )
return V_24 ;
F_23 ( V_21 , V_9 ) ;
V_9 -> V_10 . V_40 = F_1 ;
V_9 -> V_10 . V_41 = 128 ;
V_24 = F_24 ( & V_9 -> V_10 ) ;
if ( V_24 )
F_25 ( & V_21 -> V_25 ,
L_1 , V_24 ) ;
F_26 ( & V_21 -> V_25 , L_2 ,
V_9 -> V_15 . V_17 , V_39 ) ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 )
{
struct V_8 * V_9 = F_28 ( V_21 ) ;
F_29 ( & V_9 -> V_10 ) ;
F_30 ( & V_9 -> V_15 ) ;
return 0 ;
}
static void F_31 ( struct V_20 * V_21 )
{
struct V_8 * V_9 = F_28 ( V_21 ) ;
F_11 ( & V_9 -> V_15 ) ;
}
