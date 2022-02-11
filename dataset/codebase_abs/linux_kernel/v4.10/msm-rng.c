static int F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
T_1 V_5 ;
int V_6 ;
V_6 = F_3 ( V_4 -> V_7 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 ) {
V_5 = F_4 ( V_4 -> V_8 + V_9 ) ;
if ( V_5 & V_10 )
goto V_11;
V_5 = F_4 ( V_4 -> V_8 + V_12 ) ;
V_5 &= ~ V_13 ;
V_5 |= V_14 ;
F_5 ( V_5 , V_4 -> V_8 + V_12 ) ;
V_5 = F_4 ( V_4 -> V_8 + V_9 ) ;
V_5 |= V_10 ;
F_5 ( V_5 , V_4 -> V_8 + V_9 ) ;
} else {
V_5 = F_4 ( V_4 -> V_8 + V_9 ) ;
V_5 &= ~ V_10 ;
F_5 ( V_5 , V_4 -> V_8 + V_9 ) ;
}
V_11:
F_6 ( V_4 -> V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , void * V_15 , T_2 V_16 , bool V_17 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
T_2 V_18 = 0 ;
T_1 * V_19 = V_15 ;
T_2 V_20 ;
int V_6 ;
T_1 V_5 ;
V_20 = F_8 ( T_2 , V_21 , V_16 ) ;
V_6 = F_3 ( V_4 -> V_7 ) ;
if ( V_6 )
return V_6 ;
do {
V_5 = F_4 ( V_4 -> V_8 + V_22 ) ;
if ( ! ( V_5 & V_23 ) )
break;
V_5 = F_4 ( V_4 -> V_8 + V_24 ) ;
if ( ! V_5 )
break;
* V_19 ++ = V_5 ;
V_18 += V_25 ;
if ( ( V_20 - V_18 ) < V_25 )
break;
} while ( V_18 < V_20 );
F_6 ( V_4 -> V_7 ) ;
return V_18 ;
}
static int F_9 ( struct V_1 * V_1 )
{
return F_1 ( V_1 , 1 ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0 ) ;
}
static int F_11 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_3 * V_4 ;
int V_6 ;
V_4 = F_12 ( & V_27 -> V_30 , sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
return - V_32 ;
F_13 ( V_27 , V_4 ) ;
V_29 = F_14 ( V_27 , V_33 , 0 ) ;
V_4 -> V_8 = F_15 ( & V_27 -> V_30 , V_29 ) ;
if ( F_16 ( V_4 -> V_8 ) )
return F_17 ( V_4 -> V_8 ) ;
V_4 -> V_7 = F_18 ( & V_27 -> V_30 , L_1 ) ;
if ( F_16 ( V_4 -> V_7 ) )
return F_17 ( V_4 -> V_7 ) ;
V_4 -> V_1 . V_34 = V_35 ,
V_4 -> V_1 . V_36 = F_9 ,
V_4 -> V_1 . V_37 = F_10 ,
V_4 -> V_1 . V_38 = F_7 ,
V_6 = F_19 ( & V_27 -> V_30 , & V_4 -> V_1 ) ;
if ( V_6 ) {
F_20 ( & V_27 -> V_30 , L_2 ) ;
return V_6 ;
}
return 0 ;
}
