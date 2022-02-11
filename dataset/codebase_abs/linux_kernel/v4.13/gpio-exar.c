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
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_12 = ( V_5 + V_7 -> V_13 ) / 8 ?
V_14 : V_15 ;
unsigned int V_16 = ( V_5 + V_7 -> V_13 ) % 8 ;
F_1 ( V_2 , V_12 , V_11 , V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 ;
F_3 ( & V_7 -> V_9 ) ;
V_17 = F_4 ( V_7 -> V_10 + V_3 ) ;
F_7 ( & V_7 -> V_9 ) ;
return V_17 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_12 = ( V_5 + V_7 -> V_13 ) / 8 ?
V_14 : V_15 ;
unsigned int V_16 = ( V_5 + V_7 -> V_13 ) % 8 ;
return ! ! ( F_9 ( V_2 , V_12 ) & F_5 ( V_16 ) ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_12 = ( V_5 + V_7 -> V_13 ) / 8 ?
V_18 : V_19 ;
unsigned int V_16 = ( V_5 + V_7 -> V_13 ) % 8 ;
return ! ! ( F_9 ( V_2 , V_12 ) & F_5 ( V_16 ) ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_5 ,
int V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_12 = ( V_5 + V_7 -> V_13 ) / 8 ?
V_18 : V_19 ;
unsigned int V_16 = ( V_5 + V_7 -> V_13 ) % 8 ;
F_1 ( V_2 , V_12 , V_17 , V_16 ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_5 ,
int V_17 )
{
F_12 ( V_2 , V_5 , V_17 ) ;
return F_8 ( V_2 , 0 , V_5 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_5 )
{
return F_8 ( V_2 , 1 , V_5 ) ;
}
static int F_15 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_16 ( V_21 -> V_24 . V_25 ) ;
struct V_6 * V_7 ;
T_1 V_13 , V_26 ;
void T_2 * V_27 ;
int V_28 , V_29 ;
V_27 = F_17 ( V_23 ) [ 0 ] ;
if ( ! V_27 )
return - V_30 ;
V_29 = F_18 ( & V_21 -> V_24 , L_1 ,
& V_13 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_18 ( & V_21 -> V_24 , L_2 , & V_26 ) ;
if ( V_29 )
return V_29 ;
V_7 = F_19 ( & V_21 -> V_24 , sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 )
return - V_30 ;
F_20 ( & V_7 -> V_9 ) ;
V_28 = F_21 ( & V_32 , 0 , 0 , V_31 ) ;
sprintf ( V_7 -> V_33 , L_3 , V_28 ) ;
V_7 -> V_1 . V_34 = V_7 -> V_33 ;
V_7 -> V_1 . V_25 = & V_21 -> V_24 ;
V_7 -> V_1 . V_35 = F_13 ;
V_7 -> V_1 . V_36 = F_14 ;
V_7 -> V_1 . V_37 = F_10 ;
V_7 -> V_1 . V_38 = F_11 ;
V_7 -> V_1 . V_39 = F_12 ;
V_7 -> V_1 . V_40 = - 1 ;
V_7 -> V_1 . V_41 = V_26 ;
V_7 -> V_10 = V_27 ;
V_7 -> V_28 = V_28 ;
V_7 -> V_13 = V_13 ;
V_29 = F_22 ( & V_21 -> V_24 ,
& V_7 -> V_1 , V_7 ) ;
if ( V_29 )
goto V_42;
F_23 ( V_21 , V_7 ) ;
return 0 ;
V_42:
F_24 ( & V_32 , V_28 ) ;
F_25 ( & V_7 -> V_9 ) ;
return V_29 ;
}
static int F_26 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = F_27 ( V_21 ) ;
F_24 ( & V_32 , V_7 -> V_28 ) ;
F_25 ( & V_7 -> V_9 ) ;
return 0 ;
}
