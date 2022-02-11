static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_7 ;
T_1 V_8 ;
F_4 ( & V_6 -> V_9 -> V_10 , V_7 ) ;
V_8 = F_5 ( V_6 -> V_9 -> V_11 ) ;
if ( V_5 ) {
V_8 &= ~ V_6 -> V_12 ;
V_8 |= V_6 -> V_13 ;
} else {
V_8 &= ~ V_6 -> V_13 ;
}
F_6 ( V_8 , V_6 -> V_9 -> V_11 ) ;
F_7 ( & V_6 -> V_9 -> V_10 , V_7 ) ;
}
static enum V_4 F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_7 ;
T_1 V_8 ;
F_4 ( & V_6 -> V_9 -> V_10 , V_7 ) ;
V_8 = F_5 ( V_6 -> V_9 -> V_11 ) ;
F_7 ( & V_6 -> V_9 -> V_10 , V_7 ) ;
return ( V_8 & V_6 -> V_13 ) ? 1 : V_14 ;
}
static int F_9 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 , V_24 ;
V_20 = F_10 ( V_18 , sizeof( * V_20 ) , V_25 ) ;
if ( ! V_20 )
return - V_26 ;
V_20 -> V_16 = V_16 ;
F_11 ( V_16 , V_20 ) ;
V_22 = F_12 ( V_16 , V_27 , 0 ) ;
if ( ! V_22 ) {
F_13 ( V_18 , L_1 ) ;
return - V_28 ;
}
if ( F_14 ( V_22 ) < V_29 ) {
F_13 ( V_18 , L_2 ) ;
return - V_28 ;
}
if ( ! F_15 ( V_18 , V_22 -> V_30 , F_14 ( V_22 ) ,
V_31 ) ) {
F_13 ( V_18 , L_3 ) ;
return - V_32 ;
}
V_20 -> V_11 = V_22 -> V_30 ;
F_16 ( & V_20 -> V_10 ) ;
for ( V_24 = 0 ; V_24 < F_17 ( V_33 ) ; V_24 ++ ) {
V_33 [ V_24 ] . V_9 = V_20 ;
V_23 = F_18 ( V_18 , & V_33 [ V_24 ] . V_3 ) ;
if ( V_23 )
return V_23 ;
}
F_6 ( V_34 ,
V_20 -> V_11 + V_35 ) ;
return V_23 ;
}
static int F_19 ( struct V_15 * V_16 )
{
struct V_19 * V_20 = F_20 ( V_16 ) ;
F_6 ( V_36 ,
V_20 -> V_11 + V_35 ) ;
return 0 ;
}
