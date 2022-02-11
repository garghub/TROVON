static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
int V_8 ;
V_5 = ( V_5 & ~ V_9 ) | V_10 ;
F_4 ( V_5 , V_4 -> V_6 + V_7 ) ;
V_8 = F_5 ( V_4 -> V_6 + V_7 , V_5 ,
! ( V_5 & V_11 ) , 650 , 10000 ) ;
if ( V_8 ) {
F_6 ( & V_2 -> V_12 , L_1 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
V_5 = ( V_5 & ~ V_10 ) | V_9 ;
F_4 ( V_5 , V_4 -> V_6 + V_7 ) ;
}
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
V_5 = ( V_5 & ~ V_10 ) | V_9 ;
F_4 ( V_5 , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_6 + V_7 ) & V_10 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
V_5 = ( V_5 & ~ V_14 ) | F_10 ( V_14 , V_13 ) ;
F_4 ( V_5 , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
return F_12 ( V_14 , V_5 ) ;
}
static int F_13 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_3 * V_4 ;
struct V_19 V_20 = { } ;
struct V_1 * V_2 ;
int V_8 ;
V_4 = F_14 ( & V_16 -> V_12 , sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 )
return - V_22 ;
V_18 = F_15 ( V_16 , V_23 , 0 ) ;
V_4 -> V_6 = F_16 ( & V_16 -> V_12 , V_18 ) ;
if ( F_17 ( V_4 -> V_6 ) )
return F_18 ( V_4 -> V_6 ) ;
V_4 -> V_24 = F_19 ( & V_16 -> V_12 , NULL ) ;
if ( F_17 ( V_4 -> V_24 ) )
return F_18 ( V_4 -> V_24 ) ;
V_8 = F_20 ( V_4 -> V_24 ) ;
if ( V_8 ) {
F_6 ( & V_16 -> V_12 , L_2 , V_8 ) ;
return V_8 ;
}
V_20 . V_12 = & V_16 -> V_12 ;
V_20 . V_25 = V_4 ;
V_20 . V_26 = V_16 -> V_12 . V_26 ;
V_20 . V_27 = F_21 ( & V_16 -> V_12 ,
V_16 -> V_12 . V_26 ,
& V_28 ) ;
V_2 = F_22 ( & V_28 , & V_20 ) ;
if ( F_17 ( V_2 ) ) {
V_8 = F_18 ( V_2 ) ;
F_6 ( & V_16 -> V_12 , L_3 , V_8 ) ;
goto V_29;
}
F_23 ( V_16 , V_2 ) ;
return 0 ;
V_29:
F_24 ( V_4 -> V_24 ) ;
return V_8 ;
}
static int F_25 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_26 ( V_16 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_27 ( V_2 ) ;
F_24 ( V_4 -> V_24 ) ;
return 0 ;
}
