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
static void F_4 ( struct V_6 * V_7 )
{
F_5 ( V_12 | 1 , V_7 -> V_9 + V_13 ) ;
}
static void F_6 ( struct V_6 * V_7 )
{
F_5 ( V_12 , V_7 -> V_9 + V_13 ) ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_6 * V_7 ;
struct V_16 * V_17 ;
int V_18 ;
V_7 = F_8 ( & V_15 -> V_19 , sizeof( * V_7 ) , V_20 ) ;
if ( ! V_7 )
return - V_21 ;
V_17 = F_9 ( V_15 , V_22 , 0 ) ;
V_7 -> V_9 = F_10 ( & V_15 -> V_19 , V_17 ) ;
if ( F_11 ( V_7 -> V_9 ) )
return F_12 ( V_7 -> V_9 ) ;
V_7 -> V_23 = F_13 ( & V_15 -> V_19 , NULL ) ;
if ( F_11 ( V_7 -> V_23 ) )
return F_12 ( V_7 -> V_23 ) ;
V_18 = F_14 ( V_7 -> V_23 ) ;
if ( V_18 )
return V_18 ;
F_4 ( V_7 ) ;
V_7 -> V_2 . V_24 = V_15 -> V_24 ;
V_7 -> V_2 . V_25 = F_1 ;
V_18 = F_15 ( & V_7 -> V_2 ) ;
if ( V_18 )
goto V_26;
F_16 ( V_15 , V_7 ) ;
return 0 ;
V_26:
F_17 ( V_7 -> V_23 ) ;
return V_18 ;
}
static int F_18 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_19 ( V_15 ) ;
F_20 ( & V_7 -> V_2 ) ;
F_6 ( V_7 ) ;
F_17 ( V_7 -> V_23 ) ;
return 0 ;
}
static int F_21 ( struct V_27 * V_19 )
{
struct V_6 * V_7 = F_22 ( V_19 ) ;
F_6 ( V_7 ) ;
F_17 ( V_7 -> V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_27 * V_19 )
{
struct V_6 * V_7 = F_22 ( V_19 ) ;
int V_18 ;
V_18 = F_14 ( V_7 -> V_23 ) ;
if ( V_18 )
return V_18 ;
F_4 ( V_7 ) ;
return 0 ;
}
