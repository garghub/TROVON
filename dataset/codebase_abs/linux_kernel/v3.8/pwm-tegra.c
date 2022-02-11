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
unsigned long long V_12 ;
unsigned long V_13 , V_14 ;
T_1 V_6 = 0 ;
int V_15 ;
V_12 = V_9 * ( ( 1 << V_16 ) - 1 ) + V_10 / 2 ;
F_8 ( V_12 , V_10 ) ;
V_6 = ( T_1 ) V_12 << V_17 ;
V_13 = F_9 ( V_11 -> V_18 ) >> V_16 ;
V_14 = 1000000000ul / V_10 ;
V_13 = ( V_13 + ( V_14 / 2 ) ) / V_14 ;
if ( V_13 > 0 )
V_13 -- ;
if ( V_13 >> V_19 )
return - V_20 ;
V_6 |= V_13 << V_21 ;
if ( ! F_10 ( V_22 , & V_8 -> V_23 ) ) {
V_15 = F_11 ( V_11 -> V_18 ) ;
if ( V_15 < 0 )
return V_15 ;
} else
V_6 |= V_24 ;
F_5 ( V_11 , V_8 -> V_25 , V_6 ) ;
if ( ! F_10 ( V_22 , & V_8 -> V_23 ) )
F_12 ( V_11 -> V_18 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
int V_26 = 0 ;
T_1 V_6 ;
V_26 = F_11 ( V_11 -> V_18 ) ;
if ( V_26 < 0 )
return V_26 ;
V_6 = F_3 ( V_11 , V_8 -> V_25 ) ;
V_6 |= V_24 ;
F_5 ( V_11 , V_8 -> V_25 , V_6 ) ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_6 ;
V_6 = F_3 ( V_11 , V_8 -> V_25 ) ;
V_6 &= ~ V_24 ;
F_5 ( V_11 , V_8 -> V_25 , V_6 ) ;
F_12 ( V_11 -> V_18 ) ;
}
static int F_15 ( struct V_27 * V_28 )
{
struct V_1 * V_8 ;
struct V_29 * V_30 ;
int V_31 ;
V_8 = F_16 ( & V_28 -> V_32 , sizeof( * V_8 ) , V_33 ) ;
if ( ! V_8 ) {
F_17 ( & V_28 -> V_32 , L_1 ) ;
return - V_34 ;
}
V_8 -> V_32 = & V_28 -> V_32 ;
V_30 = F_18 ( V_28 , V_35 , 0 ) ;
if ( ! V_30 ) {
F_17 ( & V_28 -> V_32 , L_2 ) ;
return - V_36 ;
}
V_8 -> V_5 = F_19 ( & V_28 -> V_32 , V_30 ) ;
if ( ! V_8 -> V_5 )
return - V_37 ;
F_20 ( V_28 , V_8 ) ;
V_8 -> V_18 = F_21 ( & V_28 -> V_32 , NULL ) ;
if ( F_22 ( V_8 -> V_18 ) )
return F_23 ( V_8 -> V_18 ) ;
V_8 -> V_3 . V_32 = & V_28 -> V_32 ;
V_8 -> V_3 . V_38 = & V_39 ;
V_8 -> V_3 . V_40 = - 1 ;
V_8 -> V_3 . V_41 = V_42 ;
V_31 = F_24 ( & V_8 -> V_3 ) ;
if ( V_31 < 0 ) {
F_17 ( & V_28 -> V_32 , L_3 , V_31 ) ;
return V_31 ;
}
return 0 ;
}
static int F_25 ( struct V_27 * V_28 )
{
struct V_1 * V_11 = F_26 ( V_28 ) ;
int V_43 ;
if ( F_27 ( ! V_11 ) )
return - V_36 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
struct V_7 * V_8 = & V_11 -> V_3 . V_44 [ V_43 ] ;
if ( ! F_10 ( V_22 , & V_8 -> V_23 ) )
if ( F_11 ( V_11 -> V_18 ) < 0 )
continue;
F_5 ( V_11 , V_43 , 0 ) ;
F_12 ( V_11 -> V_18 ) ;
}
return F_28 ( & V_11 -> V_3 ) ;
}
