int F_1 ( struct V_1 * V_2 ,
void * V_3 , struct V_4 * V_5 )
{
struct V_6 * args = V_3 ;
T_1 V_7 , V_8 , V_9 ;
if ( ! V_2 -> V_10 -> V_11 )
return - V_12 ;
if ( ! args -> V_13 || ! args -> V_14 || ! args -> V_15 )
return - V_16 ;
V_7 = F_2 ( args -> V_15 , 8 ) ;
if ( ! V_7 || V_7 > 0xffffffffU / args -> V_13 )
return - V_16 ;
V_8 = V_7 * args -> V_13 ;
if ( args -> V_14 > 0xffffffffU / V_8 )
return - V_16 ;
V_9 = args -> V_14 * V_8 ;
if ( F_3 ( V_9 ) == 0 )
return - V_16 ;
args -> V_17 = 0 ;
args -> V_18 = 0 ;
args -> V_9 = 0 ;
return V_2 -> V_10 -> V_11 ( V_5 , V_2 , args ) ;
}
int F_4 ( struct V_1 * V_2 ,
void * V_3 , struct V_4 * V_5 )
{
struct V_19 * args = V_3 ;
if ( ! V_2 -> V_10 -> V_11 )
return - V_12 ;
if ( V_2 -> V_10 -> V_20 )
return V_2 -> V_10 -> V_20 ( V_5 , V_2 ,
args -> V_17 ,
& args -> V_21 ) ;
else
return F_5 ( V_5 , V_2 , args -> V_17 ,
& args -> V_21 ) ;
}
int F_6 ( struct V_1 * V_2 ,
void * V_3 , struct V_4 * V_5 )
{
struct V_22 * args = V_3 ;
if ( ! V_2 -> V_10 -> V_11 )
return - V_12 ;
if ( V_2 -> V_10 -> V_23 )
return V_2 -> V_10 -> V_23 ( V_5 , V_2 , args -> V_17 ) ;
else
return F_7 ( V_5 , V_2 , args -> V_17 ) ;
}
