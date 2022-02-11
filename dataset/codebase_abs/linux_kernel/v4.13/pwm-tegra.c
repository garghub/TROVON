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
unsigned long long V_12 = V_9 , V_13 ;
unsigned long V_14 ;
T_1 V_6 = 0 ;
int V_15 ;
V_12 *= ( 1 << V_16 ) ;
V_12 = F_8 ( V_12 , V_10 ) ;
V_6 = ( T_1 ) V_12 << V_17 ;
V_14 = V_11 -> V_18 >> V_16 ;
V_13 = F_8 ( 100ULL * V_19 , V_10 ) ;
V_14 = F_8 ( 100ULL * V_14 , V_13 ) ;
if ( V_14 > 0 )
V_14 -- ;
if ( V_14 >> V_20 )
return - V_21 ;
V_6 |= V_14 << V_22 ;
if ( ! F_9 ( V_8 ) ) {
V_15 = F_10 ( V_11 -> V_23 ) ;
if ( V_15 < 0 )
return V_15 ;
} else
V_6 |= V_24 ;
F_5 ( V_11 , V_8 -> V_25 , V_6 ) ;
if ( ! F_9 ( V_8 ) )
F_11 ( V_11 -> V_23 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
int V_26 = 0 ;
T_1 V_6 ;
V_26 = F_10 ( V_11 -> V_23 ) ;
if ( V_26 < 0 )
return V_26 ;
V_6 = F_3 ( V_11 , V_8 -> V_25 ) ;
V_6 |= V_24 ;
F_5 ( V_11 , V_8 -> V_25 , V_6 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_6 ;
V_6 = F_3 ( V_11 , V_8 -> V_25 ) ;
V_6 &= ~ V_24 ;
F_5 ( V_11 , V_8 -> V_25 , V_6 ) ;
F_11 ( V_11 -> V_23 ) ;
}
static int F_14 ( struct V_27 * V_28 )
{
struct V_1 * V_8 ;
struct V_29 * V_30 ;
int V_31 ;
V_8 = F_15 ( & V_28 -> V_32 , sizeof( * V_8 ) , V_33 ) ;
if ( ! V_8 )
return - V_34 ;
V_8 -> V_35 = F_16 ( & V_28 -> V_32 ) ;
V_8 -> V_32 = & V_28 -> V_32 ;
V_30 = F_17 ( V_28 , V_36 , 0 ) ;
V_8 -> V_5 = F_18 ( & V_28 -> V_32 , V_30 ) ;
if ( F_19 ( V_8 -> V_5 ) )
return F_20 ( V_8 -> V_5 ) ;
F_21 ( V_28 , V_8 ) ;
V_8 -> V_23 = F_22 ( & V_28 -> V_32 , NULL ) ;
if ( F_19 ( V_8 -> V_23 ) )
return F_20 ( V_8 -> V_23 ) ;
V_31 = F_23 ( V_8 -> V_23 , V_8 -> V_35 -> V_37 ) ;
if ( V_31 < 0 ) {
F_24 ( & V_28 -> V_32 , L_1 , V_31 ) ;
return V_31 ;
}
V_8 -> V_18 = F_25 ( V_8 -> V_23 ) ;
V_8 -> V_38 = F_26 ( & V_28 -> V_32 , L_2 ) ;
if ( F_19 ( V_8 -> V_38 ) ) {
V_31 = F_20 ( V_8 -> V_38 ) ;
F_24 ( & V_28 -> V_32 , L_3 , V_31 ) ;
return V_31 ;
}
F_27 ( V_8 -> V_38 ) ;
V_8 -> V_3 . V_32 = & V_28 -> V_32 ;
V_8 -> V_3 . V_39 = & V_40 ;
V_8 -> V_3 . V_41 = - 1 ;
V_8 -> V_3 . V_42 = V_8 -> V_35 -> V_43 ;
V_31 = F_28 ( & V_8 -> V_3 ) ;
if ( V_31 < 0 ) {
F_24 ( & V_28 -> V_32 , L_4 , V_31 ) ;
F_29 ( V_8 -> V_38 ) ;
return V_31 ;
}
return 0 ;
}
static int F_30 ( struct V_27 * V_28 )
{
struct V_1 * V_11 = F_31 ( V_28 ) ;
unsigned int V_44 ;
int V_15 ;
if ( F_32 ( ! V_11 ) )
return - V_45 ;
V_15 = F_10 ( V_11 -> V_23 ) ;
if ( V_15 < 0 )
return V_15 ;
for ( V_44 = 0 ; V_44 < V_11 -> V_3 . V_42 ; V_44 ++ ) {
struct V_7 * V_8 = & V_11 -> V_3 . V_46 [ V_44 ] ;
if ( ! F_9 ( V_8 ) )
if ( F_10 ( V_11 -> V_23 ) < 0 )
continue;
F_5 ( V_11 , V_44 , 0 ) ;
F_11 ( V_11 -> V_23 ) ;
}
F_29 ( V_11 -> V_38 ) ;
F_11 ( V_11 -> V_23 ) ;
return F_33 ( & V_11 -> V_3 ) ;
}
static int F_34 ( struct V_47 * V_32 )
{
return F_35 ( V_32 ) ;
}
static int F_36 ( struct V_47 * V_32 )
{
return F_37 ( V_32 ) ;
}
