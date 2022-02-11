static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 ,
bool V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_2 * V_8 = V_3 ;
if ( F_3 ( V_7 -> V_9 + V_10 ) & 1 ) {
* V_8 = F_3 ( V_7 -> V_9 + V_11 ) ;
F_3 ( V_7 -> V_9 + V_10 ) ;
return 4 ;
} else
return 0 ;
}
static int F_4 ( struct V_12 * V_13 )
{
struct V_6 * V_7 ;
struct V_14 * V_15 ;
int V_16 ;
V_15 = F_5 ( V_13 , V_17 , 0 ) ;
if ( ! V_15 )
return - V_18 ;
V_7 = F_6 ( & V_13 -> V_19 , sizeof( * V_7 ) , V_20 ) ;
if ( ! V_7 )
return - V_21 ;
if ( ! F_7 ( & V_13 -> V_19 , V_15 -> V_22 ,
F_8 ( V_15 ) , V_13 -> V_23 ) )
return - V_24 ;
V_7 -> V_9 = F_9 ( & V_13 -> V_19 , V_15 -> V_22 , F_8 ( V_15 ) ) ;
if ( ! V_7 -> V_9 )
return - V_24 ;
V_7 -> V_25 = F_10 ( & V_13 -> V_19 , NULL ) ;
if ( F_11 ( V_7 -> V_25 ) )
return F_12 ( V_7 -> V_25 ) ;
V_16 = F_13 ( V_7 -> V_25 ) ;
if ( V_16 )
goto V_26;
F_14 ( V_27 | 1 , V_7 -> V_9 + V_28 ) ;
V_7 -> V_2 . V_23 = V_13 -> V_23 ;
V_7 -> V_2 . V_29 = F_1 ;
V_16 = F_15 ( & V_7 -> V_2 ) ;
if ( V_16 )
goto V_30;
F_16 ( V_13 , V_7 ) ;
return 0 ;
V_30:
F_17 ( V_7 -> V_25 ) ;
V_26:
F_18 ( V_7 -> V_25 ) ;
return V_16 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_6 * V_7 = F_20 ( V_13 ) ;
F_21 ( & V_7 -> V_2 ) ;
F_14 ( V_27 , V_7 -> V_9 + V_28 ) ;
F_17 ( V_7 -> V_25 ) ;
F_18 ( V_7 -> V_25 ) ;
F_16 ( V_13 , NULL ) ;
return 0 ;
}
static int F_22 ( struct V_31 * V_19 )
{
struct V_6 * V_7 = F_23 ( V_19 ) ;
F_17 ( V_7 -> V_25 ) ;
return 0 ;
}
static int F_24 ( struct V_31 * V_19 )
{
struct V_6 * V_7 = F_23 ( V_19 ) ;
return F_13 ( V_7 -> V_25 ) ;
}
