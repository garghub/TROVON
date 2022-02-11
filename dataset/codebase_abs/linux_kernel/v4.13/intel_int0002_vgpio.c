static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return 0 ;
}
static void F_2 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 )
{
return 0 ;
}
static void F_4 ( struct V_5 * V_6 )
{
F_5 ( V_7 , V_8 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
T_1 V_9 ;
V_9 = F_7 ( V_10 ) ;
V_9 |= V_11 ;
F_5 ( V_9 , V_10 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
T_1 V_9 ;
V_9 = F_7 ( V_10 ) ;
V_9 &= ~ V_11 ;
F_5 ( V_9 , V_10 ) ;
}
static T_2 F_9 ( int V_12 , void * V_6 )
{
struct V_1 * V_2 = V_6 ;
T_1 V_13 ;
V_13 = F_7 ( V_8 ) ;
if ( ! ( V_13 & V_7 ) )
return V_14 ;
F_10 ( F_11 ( V_2 -> V_15 ,
V_16 ) ) ;
F_12 () ;
return V_17 ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_21 ;
const struct V_22 * V_23 ;
struct V_1 * V_2 ;
int V_12 , V_24 ;
V_23 = F_14 ( V_25 ) ;
if ( ! V_23 )
return - V_26 ;
V_12 = F_15 ( V_19 , 0 ) ;
if ( V_12 < 0 ) {
F_16 ( V_21 , L_1 , V_12 ) ;
return V_12 ;
}
V_2 = F_17 ( V_21 , sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = V_21 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_34 = F_1 ;
V_2 -> V_35 = F_2 ;
V_2 -> V_36 = F_1 ;
V_2 -> V_37 = F_3 ;
V_2 -> V_38 = - 1 ;
V_2 -> V_39 = V_16 + 1 ;
V_2 -> V_40 = true ;
V_24 = F_18 ( & V_19 -> V_21 , V_2 , NULL ) ;
if ( V_24 ) {
F_16 ( V_21 , L_2 , V_24 ) ;
return V_24 ;
}
F_19 ( V_2 -> V_41 , 0 , V_16 ) ;
V_24 = F_20 ( V_21 , V_12 , F_9 ,
V_42 | V_43 , L_3 , V_2 ) ;
if ( V_24 ) {
F_16 ( V_21 , L_4 , V_12 , V_24 ) ;
return V_24 ;
}
V_24 = F_21 ( V_2 , & V_44 , 0 , V_45 ,
V_46 ) ;
if ( V_24 ) {
F_16 ( V_21 , L_5 , V_24 ) ;
return V_24 ;
}
F_22 ( V_2 , & V_44 , V_12 , NULL ) ;
return 0 ;
}
