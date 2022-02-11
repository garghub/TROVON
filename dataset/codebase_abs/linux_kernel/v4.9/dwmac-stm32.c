static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 = V_4 -> V_7 ;
T_1 V_8 ;
int V_9 ;
V_8 = ( V_2 -> V_10 == V_11 ) ? 0 : 1 ;
V_9 = F_2 ( V_4 -> V_12 , V_6 , V_13 , V_8 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_4 -> V_14 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_4 -> V_15 ) ;
if ( V_9 )
F_4 ( V_4 -> V_14 ) ;
return V_9 ;
}
static void F_5 ( struct V_3 * V_4 )
{
F_4 ( V_4 -> V_14 ) ;
F_4 ( V_4 -> V_15 ) ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
int V_21 ;
V_4 -> V_14 = F_7 ( V_17 , L_1 ) ;
if ( F_8 ( V_4 -> V_14 ) ) {
F_9 ( V_17 , L_2 ) ;
return F_10 ( V_4 -> V_14 ) ;
}
V_4 -> V_15 = F_7 ( V_17 , L_3 ) ;
if ( F_8 ( V_4 -> V_15 ) ) {
F_9 ( V_17 , L_4 ) ;
return F_10 ( V_4 -> V_15 ) ;
}
V_4 -> V_12 = F_11 ( V_19 , L_5 ) ;
if ( F_8 ( V_4 -> V_12 ) )
return F_10 ( V_4 -> V_12 ) ;
V_21 = F_12 ( V_19 , L_5 , 1 , & V_4 -> V_7 ) ;
if ( V_21 )
F_9 ( V_17 , L_6 , V_21 ) ;
return V_21 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
struct V_24 V_25 ;
struct V_3 * V_4 ;
int V_9 ;
V_9 = F_14 ( V_23 , & V_25 ) ;
if ( V_9 )
return V_9 ;
V_2 = F_15 ( V_23 , & V_25 . V_26 ) ;
if ( F_8 ( V_2 ) )
return F_10 ( V_2 ) ;
V_4 = F_16 ( & V_23 -> V_17 , sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 ) {
V_9 = - V_28 ;
goto V_29;
}
V_9 = F_6 ( V_4 , & V_23 -> V_17 ) ;
if ( V_9 ) {
F_9 ( & V_23 -> V_17 , L_7 ) ;
goto V_29;
}
V_2 -> V_5 = V_4 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
goto V_29;
V_9 = F_17 ( & V_23 -> V_17 , V_2 , & V_25 ) ;
if ( V_9 )
goto V_30;
return 0 ;
V_30:
F_5 ( V_4 ) ;
V_29:
F_18 ( V_23 , V_2 ) ;
return V_9 ;
}
static int F_19 ( struct V_22 * V_23 )
{
struct V_31 * V_32 = F_20 ( V_23 ) ;
struct V_33 * V_34 = F_21 ( V_32 ) ;
int V_9 = F_22 ( & V_23 -> V_17 ) ;
F_5 ( V_34 -> V_35 -> V_5 ) ;
return V_9 ;
}
static int F_23 ( struct V_16 * V_17 )
{
struct V_31 * V_32 = F_24 ( V_17 ) ;
struct V_33 * V_34 = F_21 ( V_32 ) ;
int V_9 ;
V_9 = F_25 ( V_17 ) ;
F_5 ( V_34 -> V_35 -> V_5 ) ;
return V_9 ;
}
static int F_26 ( struct V_16 * V_17 )
{
struct V_31 * V_32 = F_24 ( V_17 ) ;
struct V_33 * V_34 = F_21 ( V_32 ) ;
int V_9 ;
V_9 = F_1 ( V_34 -> V_35 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_27 ( V_17 ) ;
return V_9 ;
}
