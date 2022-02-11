static inline T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 = 0 ;
V_3 = F_2 ( V_2 -> V_5 , V_2 -> V_6 , & V_4 ) ;
if ( V_3 < 0 )
F_3 ( V_2 -> V_7 , L_1 , V_3 ) ;
return V_4 ;
}
static inline void
F_4 ( struct V_1 * V_2 , T_1 V_8 )
{
int V_3 ;
V_3 = F_5 ( V_2 -> V_5 , V_2 -> V_6 , V_8 ) ;
if ( V_3 < 0 )
F_3 ( V_2 -> V_7 , L_2 , V_3 ) ;
}
static void F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
V_2 -> V_11 |= F_8 ( V_10 -> V_12 ) ;
F_3 ( V_2 -> V_7 , L_3 , V_10 -> V_12 , V_2 -> V_11 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
V_2 -> V_11 &= ~ F_8 ( V_10 -> V_12 ) ;
F_3 ( V_2 -> V_7 , L_4 , V_10 -> V_12 , V_2 -> V_11 ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
}
static void F_11 ( unsigned V_13 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
unsigned long V_16 ;
int V_17 , V_18 ;
F_3 ( V_2 -> V_7 , L_5 , V_13 ) ;
F_13 ( F_14 ( V_15 ) , V_15 ) ;
V_16 = F_1 ( V_2 ) ;
F_4 ( V_2 , V_16 ) ;
F_3 ( V_2 -> V_7 , L_6 , V_16 , V_2 -> V_11 ) ;
V_16 = ( V_16 >> V_19 ) & ~ V_2 -> V_11 ;
F_3 ( V_2 -> V_7 , L_7 , V_16 ) ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ ) {
if ( F_8 ( V_17 ) & V_16 ) {
V_18 = F_15 ( V_2 -> V_21 , V_17 ) ;
F_3 ( V_2 -> V_7 , L_8 ,
V_17 , V_18 ) ;
if ( ! V_18 )
F_16 ( V_2 -> V_7 , L_9 ,
V_17 , V_18 ) ;
F_17 ( V_18 ) ;
}
}
F_18 ( F_14 ( V_15 ) , V_15 ) ;
F_3 ( V_2 -> V_7 , L_10 , V_13 ) ;
}
static int F_19 ( struct V_22 * V_23 , unsigned int V_18 ,
T_2 V_24 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_20 ( V_18 , V_2 ) ;
F_21 ( V_18 , & V_2 -> V_26 , V_27 ) ;
F_22 ( V_18 , V_28 | V_29 ) ;
return 0 ;
}
static int F_23 ( struct V_30 * V_31 )
{
struct V_32 * V_7 = & V_31 -> V_7 ;
struct V_33 * V_34 = V_7 -> V_35 ;
struct V_1 * V_2 ;
int V_3 ;
if ( V_34 == NULL )
return - V_36 ;
V_2 = F_24 ( V_7 , sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
V_2 -> V_5 =
F_25 ( V_34 , L_11 ) ;
if ( F_26 ( V_2 -> V_5 ) )
return F_27 ( V_2 -> V_5 ) ;
V_3 = F_28 ( V_34 , L_11 , 1 ,
& V_2 -> V_6 ) ;
if ( V_3 ) {
F_29 ( V_7 , L_12 ) ;
return V_3 ;
}
V_2 -> V_13 = F_30 ( V_31 , 0 ) ;
if ( V_2 -> V_13 < 0 ) {
F_29 ( V_7 , L_13 , V_2 -> V_13 ) ;
return V_2 -> V_13 ;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_11 = ~ 0x0 ;
V_2 -> V_26 . V_39 = L_14 ;
V_2 -> V_26 . V_40 = F_10 ;
V_2 -> V_26 . V_41 = F_6 ;
V_2 -> V_26 . V_42 = F_9 ;
V_2 -> V_21 = F_31 ( V_34 , V_20 ,
& V_43 , V_2 ) ;
if ( ! V_2 -> V_21 ) {
F_29 ( V_7 , L_15 ) ;
return - V_44 ;
}
F_32 ( V_31 , V_2 ) ;
F_33 ( V_2 -> V_13 , F_11 ) ;
F_34 ( V_2 -> V_13 , V_2 ) ;
F_4 ( V_2 , ~ 0x0 ) ;
F_35 ( V_7 , L_16 , V_20 ) ;
return 0 ;
}
static int F_36 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_37 ( V_31 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ )
F_38 ( F_15 ( V_2 -> V_21 , V_12 ) ) ;
F_39 ( V_2 -> V_21 ) ;
return 0 ;
}
