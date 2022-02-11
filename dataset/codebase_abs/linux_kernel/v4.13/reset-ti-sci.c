static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , bool assert )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_6 * V_7 = V_5 -> V_7 ;
const struct V_8 * V_9 = & V_7 -> V_10 . V_9 ;
struct V_11 * V_12 ;
T_1 V_13 ;
int V_14 ;
V_12 = F_3 ( & V_5 -> V_15 , V_3 ) ;
if ( ! V_12 )
return - V_16 ;
F_4 ( & V_12 -> V_17 ) ;
V_14 = V_9 -> V_18 ( V_7 , V_12 -> V_19 , & V_13 ) ;
if ( V_14 )
goto V_20;
if ( assert )
V_13 |= V_12 -> V_21 ;
else
V_13 &= ~ V_12 -> V_21 ;
V_14 = V_9 -> V_22 ( V_7 , V_12 -> V_19 , V_13 ) ;
V_20:
F_5 ( & V_12 -> V_17 ) ;
return V_14 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , true ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , false ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_6 * V_7 = V_5 -> V_7 ;
const struct V_8 * V_9 = & V_7 -> V_10 . V_9 ;
struct V_11 * V_12 ;
T_1 V_13 ;
int V_14 ;
V_12 = F_3 ( & V_5 -> V_15 , V_3 ) ;
if ( ! V_12 )
return - V_16 ;
V_14 = V_9 -> V_18 ( V_7 , V_12 -> V_19 , & V_13 ) ;
if ( V_14 )
return V_14 ;
return V_13 & V_12 -> V_21 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( F_10 ( V_24 -> V_25 != V_2 -> V_26 ) )
return - V_16 ;
V_12 = F_11 ( V_5 -> V_27 , sizeof( * V_12 ) , V_28 ) ;
if ( ! V_12 )
return - V_29 ;
V_12 -> V_19 = V_24 -> args [ 0 ] ;
V_12 -> V_21 = V_24 -> args [ 1 ] ;
F_12 ( & V_12 -> V_17 ) ;
return F_13 ( & V_5 -> V_15 , V_12 , 0 , 0 , V_28 ) ;
}
static int F_14 ( struct V_30 * V_31 )
{
struct V_4 * V_5 ;
if ( ! V_31 -> V_27 . V_32 )
return - V_33 ;
V_5 = F_11 ( & V_31 -> V_27 , sizeof( * V_5 ) , V_28 ) ;
if ( ! V_5 )
return - V_29 ;
V_5 -> V_7 = F_15 ( & V_31 -> V_27 ) ;
if ( F_16 ( V_5 -> V_7 ) )
return F_17 ( V_5 -> V_7 ) ;
V_5 -> V_2 . V_10 = & V_34 ;
V_5 -> V_2 . V_35 = V_36 ;
V_5 -> V_2 . V_32 = V_31 -> V_27 . V_32 ;
V_5 -> V_2 . V_26 = 2 ;
V_5 -> V_2 . V_37 = F_9 ;
V_5 -> V_27 = & V_31 -> V_27 ;
F_18 ( & V_5 -> V_15 ) ;
F_19 ( V_31 , V_5 ) ;
return F_20 ( & V_5 -> V_2 ) ;
}
static int F_21 ( struct V_30 * V_31 )
{
struct V_4 * V_5 = F_22 ( V_31 ) ;
F_23 ( & V_5 -> V_2 ) ;
F_24 ( & V_5 -> V_15 ) ;
return 0 ;
}
