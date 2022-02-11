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
V_7 = F_5 ( & V_13 -> V_17 , sizeof( * V_7 ) , V_18 ) ;
if ( ! V_7 )
return - V_19 ;
V_15 = F_6 ( V_13 , V_20 , 0 ) ;
V_7 -> V_9 = F_7 ( & V_13 -> V_17 , V_15 ) ;
if ( F_8 ( V_7 -> V_9 ) )
return F_9 ( V_7 -> V_9 ) ;
V_7 -> V_21 = F_10 ( & V_13 -> V_17 , NULL ) ;
if ( F_8 ( V_7 -> V_21 ) )
return F_9 ( V_7 -> V_21 ) ;
V_16 = F_11 ( V_7 -> V_21 ) ;
if ( V_16 )
return V_16 ;
F_12 ( V_22 | 1 , V_7 -> V_9 + V_23 ) ;
V_7 -> V_2 . V_24 = V_13 -> V_24 ;
V_7 -> V_2 . V_25 = F_1 ;
V_16 = F_13 ( & V_7 -> V_2 ) ;
if ( V_16 )
goto V_26;
F_14 ( V_13 , V_7 ) ;
return 0 ;
V_26:
F_15 ( V_7 -> V_21 ) ;
return V_16 ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_6 * V_7 = F_17 ( V_13 ) ;
F_18 ( & V_7 -> V_2 ) ;
F_12 ( V_22 , V_7 -> V_9 + V_23 ) ;
F_19 ( V_7 -> V_21 ) ;
return 0 ;
}
static int F_20 ( struct V_27 * V_17 )
{
struct V_6 * V_7 = F_21 ( V_17 ) ;
F_19 ( V_7 -> V_21 ) ;
return 0 ;
}
static int F_22 ( struct V_27 * V_17 )
{
struct V_6 * V_7 = F_21 ( V_17 ) ;
return F_11 ( V_7 -> V_21 ) ;
}
