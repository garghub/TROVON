static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0x1 , V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_8 = V_2 -> V_9 / 1000 ;
unsigned int V_10 ;
V_2 -> V_7 = V_7 ;
V_10 = V_4 -> V_11 * F_5 ( V_7 , V_8 ) ;
F_3 ( V_10 , V_4 -> V_5 + V_12 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0x1 , V_4 -> V_5 + V_13 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0x0 , V_4 -> V_5 + V_13 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_3 * V_4 ;
struct V_1 * V_16 ;
unsigned long V_11 ;
struct V_17 * V_18 ;
int V_19 ;
V_4 = F_9 ( & V_15 -> V_20 , sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 )
return - V_22 ;
V_18 = F_10 ( V_15 , V_23 , 0 ) ;
V_4 -> V_5 = F_11 ( & V_15 -> V_20 , V_18 ) ;
if ( F_12 ( V_4 -> V_5 ) )
return F_13 ( V_4 -> V_5 ) ;
V_4 -> V_24 = F_14 ( & V_15 -> V_20 , V_15 -> V_25 ) ;
if ( F_12 ( V_4 -> V_24 ) )
return F_13 ( V_4 -> V_24 ) ;
V_19 = F_15 ( V_4 -> V_24 ) ;
if ( V_19 ) {
F_16 ( & V_15 -> V_20 , L_1 ) ;
return V_19 ;
}
V_11 = F_17 ( V_4 -> V_24 ) ;
if ( ! V_11 ) {
V_19 = - V_26 ;
goto V_27;
}
V_4 -> V_11 = V_11 ;
V_16 = & V_4 -> V_28 ;
V_16 -> V_29 = & V_30 ;
V_16 -> V_31 = & V_32 ;
V_16 -> V_7 = V_33 ;
V_16 -> V_34 = 1 ;
V_16 -> V_9 = V_35 / V_11 * 1000 ;
V_16 -> V_36 = & V_15 -> V_20 ;
F_18 ( V_16 , V_37 , & V_15 -> V_20 ) ;
F_19 ( V_16 , V_38 ) ;
F_20 ( V_16 , V_4 ) ;
V_19 = F_21 ( & V_4 -> V_28 ) ;
if ( V_19 ) {
F_16 ( & V_15 -> V_20 , L_2 ) ;
goto V_27;
}
F_22 ( V_15 , V_4 ) ;
F_23 ( & V_15 -> V_20 , L_3 ) ;
return 0 ;
V_27:
F_24 ( V_4 -> V_24 ) ;
return V_19 ;
}
static int F_25 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_26 ( V_15 ) ;
F_27 ( & V_4 -> V_28 ) ;
F_24 ( V_4 -> V_24 ) ;
return 0 ;
}
