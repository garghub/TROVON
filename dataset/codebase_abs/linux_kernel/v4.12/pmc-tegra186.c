static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
const char * V_8 = V_4 ;
T_1 V_9 ;
V_9 = F_3 ( V_6 -> V_10 + V_11 ) ;
V_9 &= ~ V_12 ;
if ( V_8 ) {
if ( strcmp ( V_8 , L_1 ) == 0 )
V_9 |= V_13 ;
if ( strcmp ( V_8 , L_2 ) == 0 )
V_9 |= V_14 ;
if ( strcmp ( V_8 , L_3 ) == 0 )
V_9 |= V_15 ;
}
F_4 ( V_9 , V_6 -> V_10 + V_11 ) ;
if ( V_6 -> V_16 ) {
V_6 -> V_16 ( V_17 , V_8 ) ;
return V_18 ;
}
V_9 = F_3 ( V_6 -> V_19 + V_20 ) ;
V_9 |= V_21 ;
F_4 ( V_9 , V_6 -> V_19 + V_20 ) ;
return V_18 ;
}
static int F_5 ( struct V_5 * V_6 )
{
struct V_22 * V_23 = V_6 -> V_24 -> V_25 ;
bool V_26 ;
T_1 V_9 ;
V_26 = F_6 ( V_23 , L_4 ) ;
V_9 = F_3 ( V_6 -> V_27 + V_28 ) ;
if ( V_26 )
V_9 |= V_29 ;
else
V_9 &= ~ V_29 ;
F_4 ( V_9 , V_6 -> V_27 + V_28 ) ;
V_6 -> V_16 = V_30 ;
V_30 = NULL ;
V_6 -> V_7 . V_31 = F_1 ;
V_6 -> V_7 . V_32 = 128 ;
return F_7 ( & V_6 -> V_7 ) ;
}
static int F_8 ( struct V_33 * V_34 )
{
struct V_5 * V_6 ;
struct V_35 * V_36 ;
V_6 = F_9 ( & V_34 -> V_24 , sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 )
return - V_38 ;
V_6 -> V_24 = & V_34 -> V_24 ;
V_36 = F_10 ( V_34 , V_39 , L_5 ) ;
V_6 -> V_19 = F_11 ( & V_34 -> V_24 , V_36 ) ;
if ( F_12 ( V_6 -> V_19 ) )
return F_13 ( V_6 -> V_19 ) ;
V_36 = F_10 ( V_34 , V_39 , L_6 ) ;
V_6 -> V_27 = F_11 ( & V_34 -> V_24 , V_36 ) ;
if ( F_12 ( V_6 -> V_27 ) )
return F_13 ( V_6 -> V_27 ) ;
V_36 = F_10 ( V_34 , V_39 , L_7 ) ;
V_6 -> V_40 = F_11 ( & V_34 -> V_24 , V_36 ) ;
if ( F_12 ( V_6 -> V_40 ) )
return F_13 ( V_6 -> V_40 ) ;
V_36 = F_10 ( V_34 , V_39 , L_8 ) ;
V_6 -> V_10 = F_11 ( & V_34 -> V_24 , V_36 ) ;
if ( F_12 ( V_6 -> V_10 ) )
return F_13 ( V_6 -> V_10 ) ;
return F_5 ( V_6 ) ;
}
