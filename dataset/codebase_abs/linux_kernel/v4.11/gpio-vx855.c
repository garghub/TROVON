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
static int F_14 ( struct V_2 * V_3 , unsigned int V_4 ,
unsigned long V_18 )
{
enum V_19 V_20 = F_15 ( V_18 ) ;
if ( V_4 < V_9 )
return - V_11 ;
if ( V_4 < V_10 ) {
if ( V_20 != V_21 )
return - V_22 ;
return 0 ;
}
if ( V_20 != V_23 )
return - V_22 ;
return 0 ;
}
static void F_16 ( struct V_5 * V_6 )
{
struct V_2 * V_24 = & V_6 -> V_3 ;
V_24 -> V_25 = L_1 ;
V_24 -> V_26 = V_27 ;
V_24 -> V_28 = F_5 ;
V_24 -> V_29 = F_13 ;
V_24 -> V_30 = F_11 ;
V_24 -> V_31 = F_12 ;
V_24 -> V_32 = F_14 ,
V_24 -> V_33 = NULL ;
V_24 -> V_34 = 0 ;
V_24 -> V_35 = V_36 ;
V_24 -> V_37 = false ;
V_24 -> V_38 = V_39 ;
}
static int F_17 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
struct V_42 * V_44 ;
struct V_5 * V_6 ;
V_43 = F_18 ( V_41 , V_45 , 0 ) ;
V_44 = F_18 ( V_41 , V_45 , 1 ) ;
if ( ! V_43 || ! V_44 )
return - V_46 ;
V_6 = F_19 ( & V_41 -> V_47 , sizeof( * V_6 ) , V_48 ) ;
if ( ! V_6 )
return - V_49 ;
F_20 ( V_41 , V_6 ) ;
F_21 ( & V_41 -> V_47 , L_2 ) ;
V_6 -> V_16 = V_43 -> V_50 ;
V_6 -> V_13 = V_44 -> V_50 ;
F_22 ( & V_6 -> V_12 ) ;
if ( ! F_23 ( & V_41 -> V_47 , V_43 -> V_50 ,
F_24 ( V_43 ) , V_51 L_3 ) )
F_25 ( & V_41 -> V_47 ,
L_4 ) ;
if ( ! F_23 ( & V_41 -> V_47 , V_44 -> V_50 ,
F_24 ( V_44 ) , V_51 L_5 ) )
F_25 ( & V_41 -> V_47 ,
L_6 ) ;
F_16 ( V_6 ) ;
return F_26 ( & V_41 -> V_47 , & V_6 -> V_3 , V_6 ) ;
}
