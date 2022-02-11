static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
V_2 -> V_4 = V_3 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
T_1 V_7 ;
V_7 = 1 + V_2 -> V_4 * V_6 -> V_8 ;
F_4 ( V_7 , V_6 -> V_9 + V_10 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
F_4 ( 0 , V_6 -> V_9 + V_10 ) ;
return 0 ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
T_1 V_11 ;
V_11 = F_7 ( V_6 -> V_9 + V_10 ) ;
if ( ! V_11 )
return 0 ;
return ( V_11 - 1 ) / V_6 -> V_8 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_12 , void * V_13 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
F_4 ( 1 , V_6 -> V_9 + V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_5 * V_6 ;
struct V_16 * V_17 ;
T_1 V_18 ;
int V_19 ;
V_6 = F_10 ( & V_15 -> V_6 , sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 )
return - V_21 ;
V_17 = F_11 ( V_15 , V_22 , 0 ) ;
V_6 -> V_9 = F_12 ( & V_15 -> V_6 , V_17 ) ;
if ( F_13 ( V_6 -> V_9 ) )
return F_14 ( V_6 -> V_9 ) ;
V_6 -> V_23 = F_15 ( & V_15 -> V_6 , NULL ) ;
if ( F_13 ( V_6 -> V_23 ) )
return F_14 ( V_6 -> V_23 ) ;
V_19 = F_16 ( V_6 -> V_23 ) ;
if ( V_19 )
return V_19 ;
V_6 -> V_8 = F_17 ( V_6 -> V_23 ) ;
if ( ! V_6 -> V_8 ) {
V_19 = - V_24 ;
goto V_19;
}
V_6 -> V_2 . V_25 = & V_15 -> V_6 ;
V_6 -> V_2 . V_26 = & V_27 ;
V_6 -> V_2 . V_28 = & V_29 ;
V_6 -> V_2 . V_4 = V_30 ;
V_6 -> V_2 . V_31 = 1 ;
V_6 -> V_2 . V_32 = ( V_33 - 1 ) / V_6 -> V_8 ;
F_18 ( & V_6 -> V_2 , V_4 , & V_15 -> V_6 ) ;
F_19 ( & V_6 -> V_2 , V_34 ) ;
F_20 ( & V_6 -> V_2 , V_6 ) ;
V_18 = F_7 ( V_6 -> V_9 + V_35 ) ;
if ( V_18 & V_36 )
F_4 ( 0 , V_6 -> V_9 + V_10 ) ;
F_4 ( V_37 , V_6 -> V_9 + V_35 ) ;
if ( F_7 ( V_6 -> V_9 + V_10 ) ) {
F_21 ( V_38 , & V_6 -> V_2 . V_39 ) ;
F_2 ( & V_6 -> V_2 ) ;
}
F_22 ( & V_6 -> V_2 , 128 ) ;
V_19 = F_23 ( & V_6 -> V_2 ) ;
if ( V_19 )
goto V_19;
F_24 ( V_15 , V_6 ) ;
F_25 ( & V_15 -> V_6 , L_1 ) ;
return 0 ;
V_19:
F_26 ( V_6 -> V_23 ) ;
return V_19 ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_5 * V_6 = F_28 ( V_15 ) ;
F_5 ( & V_6 -> V_2 ) ;
F_26 ( V_6 -> V_23 ) ;
F_29 ( & V_6 -> V_2 ) ;
return 0 ;
}
