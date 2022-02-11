static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_3 , unsigned int V_4 )
{
return F_4 ( V_3 -> V_5 + ( V_4 << 4 ) ) ;
}
static inline void F_5 ( struct V_1 * V_3 , unsigned int V_4 ,
unsigned long V_6 )
{
F_6 ( V_6 , V_3 -> V_5 + ( V_4 << 4 ) ) ;
}
static int F_7 ( struct V_2 * V_3 , struct V_7 * V_8 ,
int V_9 , int V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
unsigned long long V_12 = V_9 ;
unsigned long V_13 , V_14 ;
T_1 V_6 = 0 ;
int V_15 ;
V_12 *= ( 1 << V_16 ) ;
V_12 += V_10 / 2 ;
F_8 ( V_12 , V_10 ) ;
V_6 = ( T_1 ) V_12 << V_17 ;
V_13 = F_9 ( V_11 -> V_18 ) >> V_16 ;
V_14 = V_19 / V_10 ;
V_13 = ( V_13 + ( V_14 / 2 ) ) / V_14 ;
if ( V_13 > 0 )
V_13 -- ;
if ( V_13 >> V_20 )
return - V_21 ;
V_6 |= V_13 << V_22 ;
if ( ! F_10 ( V_8 ) ) {
V_15 = F_11 ( V_11 -> V_18 ) ;
if ( V_15 < 0 )
return V_15 ;
} else
V_6 |= V_23 ;
F_5 ( V_11 , V_8 -> V_24 , V_6 ) ;
if ( ! F_10 ( V_8 ) )
F_12 ( V_11 -> V_18 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
int V_25 = 0 ;
T_1 V_6 ;
V_25 = F_11 ( V_11 -> V_18 ) ;
if ( V_25 < 0 )
return V_25 ;
V_6 = F_3 ( V_11 , V_8 -> V_24 ) ;
V_6 |= V_23 ;
F_5 ( V_11 , V_8 -> V_24 , V_6 ) ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_6 ;
V_6 = F_3 ( V_11 , V_8 -> V_24 ) ;
V_6 &= ~ V_23 ;
F_5 ( V_11 , V_8 -> V_24 , V_6 ) ;
F_12 ( V_11 -> V_18 ) ;
}
static int F_15 ( struct V_26 * V_27 )
{
struct V_1 * V_8 ;
struct V_28 * V_29 ;
int V_30 ;
V_8 = F_16 ( & V_27 -> V_31 , sizeof( * V_8 ) , V_32 ) ;
if ( ! V_8 )
return - V_33 ;
V_8 -> V_34 = F_17 ( & V_27 -> V_31 ) ;
V_8 -> V_31 = & V_27 -> V_31 ;
V_29 = F_18 ( V_27 , V_35 , 0 ) ;
V_8 -> V_5 = F_19 ( & V_27 -> V_31 , V_29 ) ;
if ( F_20 ( V_8 -> V_5 ) )
return F_21 ( V_8 -> V_5 ) ;
F_22 ( V_27 , V_8 ) ;
V_8 -> V_18 = F_23 ( & V_27 -> V_31 , NULL ) ;
if ( F_20 ( V_8 -> V_18 ) )
return F_21 ( V_8 -> V_18 ) ;
V_8 -> V_36 = F_24 ( & V_27 -> V_31 , L_1 ) ;
if ( F_20 ( V_8 -> V_36 ) ) {
V_30 = F_21 ( V_8 -> V_36 ) ;
F_25 ( & V_27 -> V_31 , L_2 , V_30 ) ;
return V_30 ;
}
F_26 ( V_8 -> V_36 ) ;
V_8 -> V_3 . V_31 = & V_27 -> V_31 ;
V_8 -> V_3 . V_37 = & V_38 ;
V_8 -> V_3 . V_39 = - 1 ;
V_8 -> V_3 . V_40 = V_8 -> V_34 -> V_41 ;
V_30 = F_27 ( & V_8 -> V_3 ) ;
if ( V_30 < 0 ) {
F_25 ( & V_27 -> V_31 , L_3 , V_30 ) ;
F_28 ( V_8 -> V_36 ) ;
return V_30 ;
}
return 0 ;
}
static int F_29 ( struct V_26 * V_27 )
{
struct V_1 * V_11 = F_30 ( V_27 ) ;
unsigned int V_42 ;
int V_15 ;
if ( F_31 ( ! V_11 ) )
return - V_43 ;
V_15 = F_11 ( V_11 -> V_18 ) ;
if ( V_15 < 0 )
return V_15 ;
for ( V_42 = 0 ; V_42 < V_11 -> V_3 . V_40 ; V_42 ++ ) {
struct V_7 * V_8 = & V_11 -> V_3 . V_44 [ V_42 ] ;
if ( ! F_10 ( V_8 ) )
if ( F_11 ( V_11 -> V_18 ) < 0 )
continue;
F_5 ( V_11 , V_42 , 0 ) ;
F_12 ( V_11 -> V_18 ) ;
}
F_28 ( V_11 -> V_36 ) ;
F_12 ( V_11 -> V_18 ) ;
return F_32 ( & V_11 -> V_3 ) ;
}
