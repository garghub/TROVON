int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_8 )
return - V_9 ;
return V_6 -> V_8 ( V_2 , V_4 ) ;
}
int F_2 ( struct V_1 * V_2 , T_1 V_10 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_11 )
return - V_9 ;
F_3 ( ! V_6 -> V_8 ) ;
return V_6 -> V_11 ( V_2 , V_10 ) ;
}
int F_4 ( struct V_12 * V_13 )
{
int V_14 ;
F_5 ( & V_15 ) ;
V_14 = F_6 ( & V_16 , V_13 ) ;
F_7 ( & V_15 ) ;
return V_14 ;
}
int F_8 ( struct V_12 * V_13 )
{
int V_14 ;
F_5 ( & V_15 ) ;
V_14 = F_9 ( & V_16 , V_13 ) ;
F_7 ( & V_15 ) ;
return V_14 ;
}
int F_10 ( unsigned long V_17 , struct V_1 * V_2 ,
struct V_18 * V_19 )
{
int V_14 ;
V_19 -> V_2 = V_2 ;
F_5 ( & V_15 ) ;
V_14 = F_11 ( & V_16 , V_17 , V_19 ) ;
F_7 ( & V_15 ) ;
return V_14 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_20 * V_21 , T_2 V_22 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! ( V_2 -> V_23 & V_24 ) )
return 0 ;
if ( ! V_6 -> V_25 )
return - V_9 ;
return V_6 -> V_25 ( V_2 , V_21 , V_22 ) ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_20 * V_21 , T_2 V_22 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! ( V_2 -> V_23 & V_24 ) )
return 0 ;
if ( ! V_6 -> V_26 )
return - V_9 ;
return V_6 -> V_26 ( V_2 , V_21 , V_22 ) ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_20 * V_21 , T_2 V_22 )
{
struct V_1 * V_27 ;
struct V_28 * V_29 ;
int V_30 = 0 , V_14 = 0 ;
if ( ! ( V_2 -> V_23 & V_24 ) )
return V_30 ;
F_15 (dev, lower_dev, iter) {
V_14 = F_12 ( V_27 , V_21 , V_22 ) ;
if ( V_14 && V_14 != - V_9 )
V_30 = V_14 ;
}
return V_30 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_20 * V_21 , T_2 V_22 )
{
struct V_1 * V_27 ;
struct V_28 * V_29 ;
int V_30 = 0 , V_14 = 0 ;
if ( ! ( V_2 -> V_23 & V_24 ) )
return V_30 ;
F_15 (dev, lower_dev, iter) {
V_14 = F_13 ( V_27 , V_21 , V_22 ) ;
if ( V_14 && V_14 != - V_9 )
V_30 = V_14 ;
}
return V_30 ;
}
