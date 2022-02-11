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
static int F_8 ( struct V_12 * V_13 , unsigned long V_14 ,
void * V_15 )
{
struct V_5 * V_6 =
F_9 ( V_13 , struct V_5 , V_16 ) ;
F_4 ( 1 , V_6 -> V_9 + V_10 ) ;
return V_17 ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_5 * V_6 ;
struct V_20 * V_21 ;
T_1 V_22 ;
int V_23 ;
V_6 = F_11 ( & V_19 -> V_6 , sizeof( * V_6 ) , V_24 ) ;
if ( ! V_6 )
return - V_25 ;
V_21 = F_12 ( V_19 , V_26 , 0 ) ;
V_6 -> V_9 = F_13 ( & V_19 -> V_6 , V_21 ) ;
if ( F_14 ( V_6 -> V_9 ) )
return F_15 ( V_6 -> V_9 ) ;
V_6 -> V_27 = F_16 ( & V_19 -> V_6 , NULL ) ;
if ( F_14 ( V_6 -> V_27 ) )
return F_15 ( V_6 -> V_27 ) ;
V_23 = F_17 ( V_6 -> V_27 ) ;
if ( V_23 )
return V_23 ;
V_6 -> V_8 = F_18 ( V_6 -> V_27 ) ;
if ( ! V_6 -> V_8 ) {
V_23 = - V_28 ;
goto V_23;
}
V_6 -> V_2 . V_29 = & V_19 -> V_6 ;
V_6 -> V_2 . V_30 = & V_31 ;
V_6 -> V_2 . V_32 = & V_33 ;
V_6 -> V_2 . V_4 = V_34 ;
V_6 -> V_2 . V_35 = 1 ;
V_6 -> V_2 . V_36 = ( V_37 - 1 ) / V_6 -> V_8 ;
F_19 ( & V_6 -> V_2 , V_4 , & V_19 -> V_6 ) ;
F_20 ( & V_6 -> V_2 , V_38 ) ;
F_21 ( & V_6 -> V_2 , V_6 ) ;
V_22 = F_7 ( V_6 -> V_9 + V_39 ) ;
if ( V_22 & V_40 )
F_4 ( 0 , V_6 -> V_9 + V_10 ) ;
F_4 ( V_41 , V_6 -> V_9 + V_39 ) ;
if ( F_7 ( V_6 -> V_9 + V_10 ) ) {
F_22 ( V_42 , & V_6 -> V_2 . V_43 ) ;
F_2 ( & V_6 -> V_2 ) ;
}
V_23 = F_23 ( & V_6 -> V_2 ) ;
if ( V_23 )
goto V_23;
F_24 ( V_19 , V_6 ) ;
V_6 -> V_16 . V_44 = F_8 ;
V_6 -> V_16 . V_45 = 128 ;
V_23 = F_25 ( & V_6 -> V_16 ) ;
if ( V_23 )
F_26 ( & V_19 -> V_6 , L_1 ) ;
F_27 ( & V_19 -> V_6 , L_2 ) ;
return 0 ;
V_23:
F_28 ( V_6 -> V_27 ) ;
return V_23 ;
}
static int F_29 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = F_30 ( V_19 ) ;
F_5 ( & V_6 -> V_2 ) ;
F_28 ( V_6 -> V_27 ) ;
F_31 ( & V_6 -> V_16 ) ;
F_32 ( & V_6 -> V_2 ) ;
return 0 ;
}
