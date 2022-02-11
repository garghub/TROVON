static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( const struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 , bool V_8 )
{
int V_9 ;
struct V_1 * V_10 = V_7 -> V_10 ;
V_9 = F_6 ( V_10 -> V_11 ) ;
if ( V_9 )
return V_9 ;
if ( V_8 )
F_1 ( V_10 , V_12 , V_13 ) ;
else
F_1 ( V_10 , V_12 , V_14 ) ;
F_7 ( V_10 -> V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 )
{
const struct V_1 * V_10 = V_7 -> V_10 ;
T_1 V_15 ;
int V_9 ;
V_9 = F_6 ( V_10 -> V_11 ) ;
if ( V_9 )
return V_9 ;
V_15 = F_4 ( V_10 -> V_5 ) ;
F_7 ( V_10 -> V_11 ) ;
return ! V_15 ;
}
static int F_9 ( struct V_16 * V_17 )
{
struct V_1 * V_10 ;
int V_9 ;
struct V_18 * V_19 ;
V_10 = F_10 ( & V_17 -> V_20 , sizeof( * V_10 ) , V_21 ) ;
if ( ! V_10 )
return - V_22 ;
V_19 = F_11 ( V_17 , V_23 , 0 ) ;
V_10 -> V_5 = F_12 ( & V_17 -> V_20 , V_19 ) ;
if ( F_13 ( V_10 -> V_5 ) )
return F_14 ( V_10 -> V_5 ) ;
V_10 -> V_11 = F_15 ( & V_17 -> V_20 , L_1 ) ;
if ( F_13 ( V_10 -> V_11 ) ) {
F_16 ( & V_17 -> V_20 , L_2 ) ;
return F_14 ( V_10 -> V_11 ) ;
}
V_9 = F_17 ( V_10 -> V_11 ) ;
if ( V_9 ) {
F_16 ( & V_17 -> V_20 , L_3 ) ;
return V_9 ;
}
F_7 ( V_10 -> V_11 ) ;
V_9 = F_18 ( & V_17 -> V_20 , L_4 ,
& V_24 , V_10 ) ;
if ( V_9 ) {
F_16 ( & V_17 -> V_20 , L_5 ) ;
F_19 ( V_10 -> V_11 ) ;
return V_9 ;
}
return 0 ;
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_6 * V_7 = F_21 ( V_17 ) ;
struct V_1 * V_25 = V_7 -> V_10 ;
F_22 ( & V_17 -> V_20 ) ;
F_19 ( V_25 -> V_11 ) ;
return 0 ;
}
