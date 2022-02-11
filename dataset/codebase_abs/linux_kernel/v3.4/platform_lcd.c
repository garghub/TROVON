static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return V_4 -> V_5 ;
}
static int F_4 ( struct V_2 * V_3 , int V_5 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_6 = 1 ;
if ( V_5 == V_7 || V_4 -> V_8 )
V_6 = 0 ;
V_4 -> V_9 -> V_10 ( V_4 -> V_9 , V_6 ) ;
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_13 * V_9 = V_4 -> V_9 ;
if ( V_9 -> V_14 )
return V_9 -> V_14 ( V_9 , V_12 ) ;
return V_4 -> V_15 -> V_16 == V_12 -> V_17 ;
}
static int T_1 F_6 ( struct V_18 * V_19 )
{
struct V_13 * V_9 ;
struct V_1 * V_4 ;
struct V_17 * V_20 = & V_19 -> V_20 ;
int V_21 ;
V_9 = V_19 -> V_20 . V_22 ;
if ( ! V_9 ) {
F_7 ( V_20 , L_1 ) ;
return - V_23 ;
}
V_4 = F_8 ( & V_19 -> V_20 , sizeof( struct V_1 ) ,
V_24 ) ;
if ( ! V_4 ) {
F_7 ( V_20 , L_2 ) ;
return - V_25 ;
}
V_4 -> V_15 = V_20 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_3 = F_9 ( F_10 ( V_20 ) , V_20 ,
V_4 , & V_26 ) ;
if ( F_11 ( V_4 -> V_3 ) ) {
F_7 ( V_20 , L_3 ) ;
V_21 = F_12 ( V_4 -> V_3 ) ;
goto V_21;
}
F_13 ( V_19 , V_4 ) ;
F_4 ( V_4 -> V_3 , V_27 ) ;
return 0 ;
V_21:
return V_21 ;
}
static int T_2 F_14 ( struct V_18 * V_19 )
{
struct V_1 * V_4 = F_15 ( V_19 ) ;
F_16 ( V_4 -> V_3 ) ;
return 0 ;
}
static int F_17 ( struct V_17 * V_20 )
{
struct V_1 * V_4 = F_18 ( V_20 ) ;
V_4 -> V_8 = 1 ;
F_4 ( V_4 -> V_3 , V_4 -> V_5 ) ;
return 0 ;
}
static int F_19 ( struct V_17 * V_20 )
{
struct V_1 * V_4 = F_18 ( V_20 ) ;
V_4 -> V_8 = 0 ;
F_4 ( V_4 -> V_3 , V_4 -> V_5 ) ;
return 0 ;
}
