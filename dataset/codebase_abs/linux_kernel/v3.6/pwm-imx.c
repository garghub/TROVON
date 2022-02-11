static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( F_3 () || F_4 () ) ) {
unsigned long long V_9 ;
unsigned long V_10 , V_11 , V_12 ;
T_1 V_13 ;
V_9 = F_5 ( V_8 -> V_14 ) ;
V_9 = V_9 * V_6 ;
F_6 ( V_9 , 1000000000 ) ;
V_10 = V_9 ;
V_12 = V_10 / 0x10000 + 1 ;
V_10 /= V_12 ;
V_9 = ( unsigned long long ) V_10 * V_5 ;
F_6 ( V_9 , V_6 ) ;
V_11 = V_9 ;
if ( V_10 > 2 )
V_10 -= 2 ;
else
V_10 = 0 ;
F_7 ( V_11 , V_8 -> V_15 + V_16 ) ;
F_7 ( V_10 , V_8 -> V_15 + V_17 ) ;
V_13 = F_8 ( V_12 ) |
V_18 | V_19 |
V_20 | V_21 ;
if ( F_9 () )
V_13 |= V_22 ;
else
V_13 |= V_23 ;
F_7 ( V_13 , V_8 -> V_15 + V_24 ) ;
} else if ( F_3 () || F_4 () ) {
T_1 V_25 = F_10 ( V_8 -> V_15 + V_26 ) ;
T_1 V_27 = V_25 * V_5 / V_6 ;
F_7 ( V_25 - V_27 , V_8 -> V_15 + V_28 ) ;
} else {
F_11 () ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_29 = 0 ;
if ( ! V_8 -> V_30 ) {
V_29 = F_13 ( V_8 -> V_14 ) ;
if ( ! V_29 )
V_8 -> V_30 = 1 ;
}
return V_29 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_7 ( 0 , V_8 -> V_15 + V_24 ) ;
if ( V_8 -> V_30 ) {
F_15 ( V_8 -> V_14 ) ;
V_8 -> V_30 = 0 ;
}
}
static int T_2 F_16 ( struct V_31 * V_32 )
{
struct V_7 * V_8 ;
struct V_33 * V_34 ;
int V_35 = 0 ;
V_8 = F_17 ( & V_32 -> V_36 , sizeof( * V_8 ) , V_37 ) ;
if ( V_8 == NULL ) {
F_18 ( & V_32 -> V_36 , L_1 ) ;
return - V_38 ;
}
V_8 -> V_14 = F_19 ( & V_32 -> V_36 , L_2 ) ;
if ( F_20 ( V_8 -> V_14 ) )
return F_21 ( V_8 -> V_14 ) ;
V_8 -> V_2 . V_39 = & V_40 ;
V_8 -> V_2 . V_36 = & V_32 -> V_36 ;
V_8 -> V_2 . V_41 = - 1 ;
V_8 -> V_2 . V_42 = 1 ;
V_8 -> V_30 = 0 ;
V_34 = F_22 ( V_32 , V_43 , 0 ) ;
if ( V_34 == NULL ) {
F_18 ( & V_32 -> V_36 , L_3 ) ;
return - V_44 ;
}
V_8 -> V_15 = F_23 ( & V_32 -> V_36 , V_34 ) ;
if ( V_8 -> V_15 == NULL )
return - V_45 ;
V_35 = F_24 ( & V_8 -> V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
F_25 ( V_32 , V_8 ) ;
return 0 ;
}
static int T_3 F_26 ( struct V_31 * V_32 )
{
struct V_7 * V_8 ;
V_8 = F_27 ( V_32 ) ;
if ( V_8 == NULL )
return - V_44 ;
return F_28 ( & V_8 -> V_2 ) ;
}
static int T_4 F_29 ( void )
{
return F_30 ( & V_46 ) ;
}
static void T_5 F_31 ( void )
{
F_32 ( & V_46 ) ;
}
