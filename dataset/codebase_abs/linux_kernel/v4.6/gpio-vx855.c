static inline T_1 F_1 ( int V_1 )
{
if ( V_1 < 10 )
return 1 << V_1 ;
else
return 1 << ( V_1 + 14 ) ;
}
static inline T_1 F_2 ( int V_1 )
{
if ( V_1 < 11 )
return 1 << V_1 ;
else
return 1 << ( V_1 + 14 ) ;
}
static inline T_1 F_3 ( int V_1 )
{
if ( V_1 < 14 )
return 1 << ( V_1 + 10 ) ;
else
return 1 << ( V_1 + 14 ) ;
}
static inline T_1 F_4 ( int V_1 )
{
if ( V_1 < 14 )
return 1 << ( V_1 + 11 ) ;
else
return 1 << ( V_1 + 13 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_6 ( V_3 ) ;
unsigned long V_7 ;
T_1 V_8 ;
if ( V_4 < V_9 )
return 0 ;
if ( V_4 < V_10 )
return - V_11 ;
F_7 ( & V_6 -> V_12 , V_7 ) ;
V_8 = F_8 ( V_6 -> V_13 ) ;
V_8 |= F_4 ( V_4 - V_10 ) ;
F_9 ( V_8 , V_6 -> V_13 ) ;
F_10 ( & V_6 -> V_12 , V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = F_6 ( V_3 ) ;
T_1 V_14 ;
int V_15 = 0 ;
if ( V_4 < V_9 ) {
V_14 = F_8 ( V_6 -> V_16 ) ;
if ( V_14 & F_1 ( V_4 ) )
V_15 = 1 ;
} else if ( V_4 < V_10 ) {
V_14 = F_8 ( V_6 -> V_13 ) ;
if ( V_14 & F_2 ( V_4 - V_9 ) )
V_15 = 1 ;
} else {
V_14 = F_8 ( V_6 -> V_16 ) ;
if ( V_14 & F_3 ( V_4 - V_10 ) )
V_15 = 1 ;
}
return V_15 ;
}
static void F_12 ( struct V_2 * V_3 , unsigned int V_4 ,
int V_17 )
{
struct V_5 * V_6 = F_6 ( V_3 ) ;
unsigned long V_7 ;
T_1 V_8 ;
if ( V_4 < V_9 )
return;
F_7 ( & V_6 -> V_12 , V_7 ) ;
V_8 = F_8 ( V_6 -> V_13 ) ;
if ( V_4 < V_10 ) {
if ( V_17 )
V_8 |= F_2 ( V_4 - V_9 ) ;
else
V_8 &= ~ F_2 ( V_4 - V_9 ) ;
} else {
if ( V_17 )
V_8 |= F_4 ( V_4 - V_10 ) ;
else
V_8 &= ~ F_4 ( V_4 - V_10 ) ;
}
F_9 ( V_8 , V_6 -> V_13 ) ;
F_10 ( & V_6 -> V_12 , V_7 ) ;
}
static int F_13 ( struct V_2 * V_3 ,
unsigned int V_4 , int V_17 )
{
if ( V_4 < V_9 )
return - V_11 ;
F_12 ( V_3 , V_4 , V_17 ) ;
return 0 ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_2 * V_18 = & V_6 -> V_3 ;
V_18 -> V_19 = L_1 ;
V_18 -> V_20 = V_21 ;
V_18 -> V_22 = F_5 ;
V_18 -> V_23 = F_13 ;
V_18 -> V_24 = F_11 ;
V_18 -> V_25 = F_12 ;
V_18 -> V_26 = NULL ;
V_18 -> V_27 = 0 ;
V_18 -> V_28 = V_29 ;
V_18 -> V_30 = false ;
V_18 -> V_31 = V_32 ;
}
static int F_15 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
struct V_35 * V_37 ;
struct V_5 * V_6 ;
V_36 = F_16 ( V_34 , V_38 , 0 ) ;
V_37 = F_16 ( V_34 , V_38 , 1 ) ;
if ( ! V_36 || ! V_37 )
return - V_39 ;
V_6 = F_17 ( & V_34 -> V_40 , sizeof( * V_6 ) , V_41 ) ;
if ( ! V_6 )
return - V_42 ;
F_18 ( V_34 , V_6 ) ;
F_19 ( & V_34 -> V_40 , L_2 ) ;
V_6 -> V_16 = V_36 -> V_43 ;
V_6 -> V_13 = V_37 -> V_43 ;
F_20 ( & V_6 -> V_12 ) ;
if ( ! F_21 ( & V_34 -> V_40 , V_36 -> V_43 ,
F_22 ( V_36 ) , V_44 L_3 ) )
F_23 ( & V_34 -> V_40 ,
L_4 ) ;
if ( ! F_21 ( & V_34 -> V_40 , V_37 -> V_43 ,
F_22 ( V_37 ) , V_44 L_5 ) )
F_23 ( & V_34 -> V_40 ,
L_6 ) ;
F_14 ( V_6 ) ;
return F_24 ( & V_34 -> V_40 , & V_6 -> V_3 , V_6 ) ;
}
