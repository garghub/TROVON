static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_3 -> V_5 * V_6 , V_4 -> V_7 + V_8 ) ;
F_4 ( V_9 , V_4 -> V_7 + V_10 ) ;
F_4 ( V_11 | V_12 ,
V_4 -> V_7 + V_13 ) ;
F_4 ( V_11 | V_12 | V_14 ,
V_4 -> V_7 + V_13 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( 0 , V_4 -> V_7 + V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_9 , V_4 -> V_7 + V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 ,
unsigned int V_5 )
{
V_3 -> V_5 = V_5 ;
if ( F_8 ( V_3 ) )
F_3 ( V_3 ) ;
return 0 ;
}
static T_1 F_9 ( int V_15 , void * V_16 )
{
struct V_1 * V_4 = V_16 ;
F_10 ( & V_4 -> V_3 ) ;
return V_17 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_21 ;
struct V_22 * V_23 ;
struct V_1 * V_4 ;
unsigned int V_24 ;
int V_15 ;
int V_25 ;
V_4 = F_12 ( V_21 , sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
V_23 = F_13 ( V_19 , V_28 , 0 ) ;
V_4 -> V_7 = F_14 ( V_21 , V_23 ) ;
if ( F_15 ( V_4 -> V_7 ) )
return F_16 ( V_4 -> V_7 ) ;
V_15 = F_17 ( V_19 , 0 ) ;
if ( ! V_15 )
return - V_29 ;
V_4 -> V_21 = V_21 ;
V_4 -> V_3 . V_30 = & V_31 ;
V_4 -> V_3 . V_32 = & V_33 ;
V_4 -> V_3 . V_34 = 1 ;
V_4 -> V_3 . V_35 = 0xFFFFFFFF / V_6 ;
V_4 -> V_3 . V_36 = V_21 ;
V_4 -> V_3 . V_5 = 13U ;
F_18 ( & V_4 -> V_3 , 0 , V_21 ) ;
V_24 = F_19 ( V_4 -> V_7 + V_13 ) ;
if ( V_24 & V_14 ) {
V_24 &= ~ V_14 ;
F_4 ( V_24 , V_4 -> V_7 + V_13 ) ;
}
V_25 = F_20 ( V_21 , V_15 , F_9 , 0 ,
L_1 , V_4 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_21 ( V_21 , & V_4 -> V_3 ) ;
if ( V_25 ) {
F_22 ( & V_19 -> V_21 , L_2 ) ;
return V_25 ;
}
F_23 ( V_19 , V_4 ) ;
F_24 ( V_21 , L_3 ) ;
return 0 ;
}
static int T_2 F_25 ( struct V_20 * V_21 )
{
struct V_1 * V_4 = F_26 ( V_21 ) ;
unsigned int V_24 ;
V_24 = F_19 ( V_4 -> V_7 + V_13 ) ;
V_24 &= ~ V_14 ;
F_4 ( V_24 , V_4 -> V_7 + V_13 ) ;
return 0 ;
}
static int T_2 F_27 ( struct V_20 * V_21 )
{
struct V_1 * V_4 = F_26 ( V_21 ) ;
unsigned int V_24 ;
if ( F_8 ( & V_4 -> V_3 ) ) {
V_24 = F_19 ( V_4 -> V_7 + V_13 ) ;
V_24 |= V_14 ;
F_4 ( V_24 , V_4 -> V_7 + V_13 ) ;
}
return 0 ;
}
