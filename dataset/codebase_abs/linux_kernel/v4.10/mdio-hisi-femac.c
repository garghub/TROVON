static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
return F_2 ( V_2 -> V_4 + V_5 ,
V_3 , V_3 & V_6 , 20 , 10000 ) ;
}
static int F_3 ( struct V_7 * V_8 , int V_9 , int V_10 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_12 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( ( V_9 << V_13 ) | V_10 ,
V_2 -> V_4 + V_5 ) ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return F_5 ( V_2 -> V_4 + V_14 ) & 0xFFFF ;
}
static int F_6 ( struct V_7 * V_8 , int V_9 , int V_10 ,
T_2 V_15 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_12 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_16 | ( V_15 << V_17 ) |
( V_9 << V_13 ) | V_10 ,
V_2 -> V_4 + V_5 ) ;
return F_1 ( V_2 ) ;
}
static int F_7 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 . V_23 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
int V_12 ;
V_8 = F_8 ( sizeof( * V_2 ) ) ;
if ( ! V_8 )
return - V_26 ;
V_8 -> V_27 = L_1 ;
V_8 -> V_28 = & F_3 ;
V_8 -> V_29 = & F_6 ;
snprintf ( V_8 -> V_30 , V_31 , L_2 , V_19 -> V_27 ) ;
V_8 -> V_32 = & V_19 -> V_22 ;
V_2 = V_8 -> V_11 ;
V_25 = F_9 ( V_19 , V_33 , 0 ) ;
V_2 -> V_4 = F_10 ( & V_19 -> V_22 , V_25 ) ;
if ( F_11 ( V_2 -> V_4 ) ) {
V_12 = F_12 ( V_2 -> V_4 ) ;
goto V_34;
}
V_2 -> V_35 = F_13 ( & V_19 -> V_22 , NULL ) ;
if ( F_11 ( V_2 -> V_35 ) ) {
V_12 = F_12 ( V_2 -> V_35 ) ;
goto V_34;
}
V_12 = F_14 ( V_2 -> V_35 ) ;
if ( V_12 )
goto V_34;
V_12 = F_15 ( V_8 , V_21 ) ;
if ( V_12 )
goto V_36;
F_16 ( V_19 , V_8 ) ;
return 0 ;
V_36:
F_17 ( V_2 -> V_35 ) ;
V_34:
F_18 ( V_8 ) ;
return V_12 ;
}
static int F_19 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = F_20 ( V_19 ) ;
struct V_1 * V_2 = V_8 -> V_11 ;
F_21 ( V_8 ) ;
F_17 ( V_2 -> V_35 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
