static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
return F_4 ( V_3 -> V_6 + ( V_4 << 4 ) + V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_3 ,
unsigned int V_4 , unsigned long V_5 ,
unsigned long V_7 )
{
F_6 ( V_7 , V_3 -> V_6 + ( V_4 << 4 ) + V_5 ) ;
}
static int F_7 ( struct V_2 * V_3 , struct V_8 * V_9 ,
int V_10 , int V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_2 V_7 , div , V_13 ;
unsigned long V_14 = V_15 , V_16 , V_17 ;
int V_18 ;
V_13 = F_8 ( V_12 -> V_19 ) ;
while ( 1 ) {
div = 1000000000 ;
div *= 1 + V_14 ;
V_7 = V_13 * V_11 ;
V_16 = F_9 ( V_7 , div ) ;
V_7 = V_13 * V_10 ;
V_17 = F_9 ( V_7 , div ) ;
if ( V_16 < V_20 || V_17 < V_21 )
return - V_22 ;
if ( V_16 > V_23 || V_17 > V_24 ) {
if ( ++ V_14 > V_25 )
return - V_22 ;
continue;
}
break;
}
V_18 = F_10 ( V_12 -> V_19 ) ;
if ( V_18 )
return V_18 ;
F_5 ( V_12 , V_9 -> V_26 , V_27 ,
V_14 << V_28 ) ;
F_5 ( V_12 , V_9 -> V_26 , V_29 , V_17 ) ;
F_5 ( V_12 , V_9 -> V_26 , V_30 , V_16 ) ;
F_11 ( V_12 -> V_19 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
int V_31 = 0 ;
T_1 V_7 ;
V_31 = F_10 ( V_12 -> V_19 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_3 ( V_12 , V_9 -> V_26 , V_27 ) ;
V_7 |= V_32 ;
F_5 ( V_12 , V_9 -> V_26 , V_27 , V_7 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_12 , V_9 -> V_26 , V_27 ) ;
V_7 &= ~ V_32 ;
F_5 ( V_12 , V_9 -> V_26 , V_27 , V_7 ) ;
F_11 ( V_12 -> V_19 ) ;
}
static int F_14 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_37 . V_38 ;
struct V_1 * V_12 ;
struct V_39 * V_40 ;
int V_18 ;
T_1 V_7 ;
V_12 = F_15 ( & V_34 -> V_37 , sizeof( * V_12 ) , V_41 ) ;
if ( ! V_12 )
return - V_42 ;
V_40 = F_16 ( V_34 , V_43 , 0 ) ;
V_12 -> V_6 = F_17 ( & V_34 -> V_37 , V_40 ) ;
if ( F_18 ( V_12 -> V_6 ) )
return F_19 ( V_12 -> V_6 ) ;
V_12 -> V_19 = F_20 ( & V_34 -> V_37 , NULL ) ;
if ( F_18 ( V_12 -> V_19 ) )
return F_19 ( V_12 -> V_19 ) ;
F_21 ( V_34 , V_12 ) ;
V_12 -> V_3 . V_37 = & V_34 -> V_37 ;
V_12 -> V_3 . V_44 = & V_45 ;
V_12 -> V_3 . V_46 = - 1 ;
V_12 -> V_3 . V_47 = V_48 ;
V_18 = F_22 ( V_12 -> V_19 ) ;
if ( V_18 )
return V_18 ;
if ( F_23 ( V_36 , L_1 ) ) {
V_18 = F_10 ( V_12 -> V_19 ) ;
if ( V_18 ) {
F_24 ( V_12 -> V_19 ) ;
return V_18 ;
}
V_7 = F_4 ( V_12 -> V_6 + V_49 ) ;
V_7 |= V_50 ;
F_6 ( V_7 , V_12 -> V_6 + V_49 ) ;
F_11 ( V_12 -> V_19 ) ;
}
V_18 = F_25 ( & V_12 -> V_3 ) ;
if ( V_18 < 0 ) {
F_24 ( V_12 -> V_19 ) ;
F_26 ( & V_34 -> V_37 , L_2 , V_18 ) ;
}
return V_18 ;
}
static int F_27 ( struct V_33 * V_34 )
{
struct V_1 * V_12 = F_28 ( V_34 ) ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_48 ; V_51 ++ )
F_29 ( & V_12 -> V_3 . V_52 [ V_51 ] ) ;
F_24 ( V_12 -> V_19 ) ;
return F_30 ( & V_12 -> V_3 ) ;
}
