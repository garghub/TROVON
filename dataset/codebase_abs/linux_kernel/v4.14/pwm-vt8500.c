static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int V_5 = F_2 ( 10 ) ;
T_2 V_6 = V_4 << ( V_3 << 8 ) ;
while ( ( F_3 ( V_2 -> V_7 + V_8 ) & V_6 ) && -- V_5 )
F_4 () ;
if ( F_5 ( ! V_5 ) )
F_6 ( V_2 -> V_9 . V_10 , L_1 ,
V_6 ) ;
}
static int F_7 ( struct V_11 * V_9 , struct V_12 * V_13 ,
int V_14 , int V_15 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
unsigned long long V_16 ;
unsigned long V_17 , V_18 , V_19 , V_20 ;
int V_21 ;
T_2 V_22 ;
V_21 = F_9 ( V_2 -> V_23 ) ;
if ( V_21 < 0 ) {
F_10 ( V_9 -> V_10 , L_2 ) ;
return V_21 ;
}
V_16 = F_11 ( V_2 -> V_23 ) ;
V_16 = V_16 * V_15 ;
F_12 ( V_16 , 1000000000 ) ;
V_17 = V_16 ;
if ( V_17 < 1 )
V_17 = 1 ;
V_18 = ( V_17 - 1 ) / 4096 ;
V_19 = V_17 / ( V_18 + 1 ) - 1 ;
if ( V_19 > 4095 )
V_19 = 4095 ;
if ( V_18 > 1023 ) {
F_13 ( V_2 -> V_23 ) ;
return - V_24 ;
}
V_16 = ( unsigned long long ) V_19 * V_14 ;
F_12 ( V_16 , V_15 ) ;
V_20 = V_16 ;
F_14 ( V_18 , V_2 -> V_7 + F_15 ( V_13 -> V_25 ) ) ;
F_1 ( V_2 , V_13 -> V_25 , V_26 ) ;
F_14 ( V_19 , V_2 -> V_7 + F_16 ( V_13 -> V_25 ) ) ;
F_1 ( V_2 , V_13 -> V_25 , V_27 ) ;
F_14 ( V_20 , V_2 -> V_7 + F_17 ( V_13 -> V_25 ) ) ;
F_1 ( V_2 , V_13 -> V_25 , V_28 ) ;
V_22 = F_3 ( V_2 -> V_7 + F_18 ( V_13 -> V_25 ) ) ;
V_22 |= V_29 ;
F_14 ( V_22 , V_2 -> V_7 + F_18 ( V_13 -> V_25 ) ) ;
F_1 ( V_2 , V_13 -> V_25 , V_30 ) ;
F_13 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_9 , struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
int V_21 ;
T_2 V_22 ;
V_21 = F_9 ( V_2 -> V_23 ) ;
if ( V_21 < 0 ) {
F_10 ( V_9 -> V_10 , L_2 ) ;
return V_21 ;
}
V_22 = F_3 ( V_2 -> V_7 + F_18 ( V_13 -> V_25 ) ) ;
V_22 |= V_31 ;
F_14 ( V_22 , V_2 -> V_7 + F_18 ( V_13 -> V_25 ) ) ;
F_1 ( V_2 , V_13 -> V_25 , V_30 ) ;
return 0 ;
}
static void F_20 ( struct V_11 * V_9 , struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
T_2 V_22 ;
V_22 = F_3 ( V_2 -> V_7 + F_18 ( V_13 -> V_25 ) ) ;
V_22 &= ~ V_31 ;
F_14 ( V_22 , V_2 -> V_7 + F_18 ( V_13 -> V_25 ) ) ;
F_1 ( V_2 , V_13 -> V_25 , V_30 ) ;
F_13 ( V_2 -> V_23 ) ;
}
static int F_21 ( struct V_11 * V_9 ,
struct V_12 * V_13 ,
enum V_32 V_33 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
T_2 V_22 ;
V_22 = F_3 ( V_2 -> V_7 + F_18 ( V_13 -> V_25 ) ) ;
if ( V_33 == V_34 )
V_22 |= V_35 ;
else
V_22 &= ~ V_35 ;
F_14 ( V_22 , V_2 -> V_7 + F_18 ( V_13 -> V_25 ) ) ;
F_1 ( V_2 , V_13 -> V_25 , V_30 ) ;
return 0 ;
}
static int F_22 ( struct V_36 * V_37 )
{
struct V_1 * V_9 ;
struct V_38 * V_39 ;
struct V_40 * V_41 = V_37 -> V_10 . V_42 ;
int V_43 ;
if ( ! V_41 ) {
F_10 ( & V_37 -> V_10 , L_3 ) ;
return - V_24 ;
}
V_9 = F_23 ( & V_37 -> V_10 , sizeof( * V_9 ) , V_44 ) ;
if ( V_9 == NULL )
return - V_45 ;
V_9 -> V_9 . V_10 = & V_37 -> V_10 ;
V_9 -> V_9 . V_46 = & V_47 ;
V_9 -> V_9 . V_48 = V_49 ;
V_9 -> V_9 . V_50 = 3 ;
V_9 -> V_9 . V_7 = - 1 ;
V_9 -> V_9 . V_51 = V_52 ;
V_9 -> V_23 = F_24 ( & V_37 -> V_10 , NULL ) ;
if ( F_25 ( V_9 -> V_23 ) ) {
F_10 ( & V_37 -> V_10 , L_4 ) ;
return F_26 ( V_9 -> V_23 ) ;
}
V_39 = F_27 ( V_37 , V_53 , 0 ) ;
V_9 -> V_7 = F_28 ( & V_37 -> V_10 , V_39 ) ;
if ( F_25 ( V_9 -> V_7 ) )
return F_26 ( V_9 -> V_7 ) ;
V_43 = F_29 ( V_9 -> V_23 ) ;
if ( V_43 < 0 ) {
F_10 ( & V_37 -> V_10 , L_5 ) ;
return V_43 ;
}
V_43 = F_30 ( & V_9 -> V_9 ) ;
if ( V_43 < 0 ) {
F_10 ( & V_37 -> V_10 , L_6 ) ;
F_31 ( V_9 -> V_23 ) ;
return V_43 ;
}
F_32 ( V_37 , V_9 ) ;
return V_43 ;
}
static int F_33 ( struct V_36 * V_37 )
{
struct V_1 * V_9 ;
V_9 = F_34 ( V_37 ) ;
if ( V_9 == NULL )
return - V_54 ;
F_31 ( V_9 -> V_23 ) ;
return F_35 ( & V_9 -> V_9 ) ;
}
