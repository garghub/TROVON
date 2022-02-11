static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
F_2 ( V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
V_4 &= ~ V_7 ;
V_4 |= V_8 ;
V_4 |= ( 1 << V_3 ) ;
F_4 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_4 ( V_2 -> V_9 , V_2 -> V_5 + V_10 ) ;
F_5 ( V_2 -> V_5 ) ;
}
static int F_6 ( struct V_11 * V_12 , int V_13 ,
int V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 -> V_15 . V_16 ) ;
int V_17 ;
V_17 = F_8 ( V_2 -> V_18 ) ;
if ( V_17 )
return V_17 ;
F_1 ( V_2 , V_13 ) ;
F_9 ( V_2 -> V_15 , L_1 , V_13 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , int V_13 )
{
T_1 V_4 ;
F_2 ( V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
V_4 &= ~ ( 1 << V_13 ) ;
F_4 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_5 ( V_2 -> V_5 ) ;
}
static void F_11 ( struct V_11 * V_12 , int V_13 ,
int V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 -> V_15 . V_16 ) ;
F_10 ( V_2 , V_13 ) ;
F_12 ( V_2 -> V_18 ) ;
F_9 ( V_2 -> V_15 , L_2 , V_13 ) ;
}
static T_2 F_13 ( struct V_19 * V_15 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_1 * V_2 = F_7 ( V_15 -> V_16 ) ;
unsigned long V_23 = V_2 -> V_9 ;
return sprintf ( V_22 , L_3 , V_23 ) ;
}
static T_2 F_14 ( struct V_19 * V_15 ,
struct V_20 * V_21 ,
const char * V_22 , T_3 V_24 )
{
int V_17 ;
unsigned long V_23 ;
struct V_1 * V_2 = F_7 ( V_15 -> V_16 ) ;
V_17 = F_15 ( V_22 , 16 , & V_23 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_9 = V_23 ;
return V_24 ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_2 ( V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
F_5 ( V_2 -> V_5 ) ;
return V_4 ;
}
static T_2 F_17 ( struct V_19 * V_15 ,
struct V_20 * V_21 , char * V_22 )
{
int V_17 ;
T_1 V_23 ;
struct V_1 * V_2 = F_7 ( V_15 -> V_16 ) ;
V_17 = F_8 ( V_2 -> V_18 ) ;
if ( V_17 )
return V_17 ;
V_23 = F_16 ( V_2 ) ;
F_12 ( V_2 -> V_18 ) ;
return sprintf ( V_22 , L_4 , V_23 ) ;
}
static int F_18 ( struct V_25 * V_26 , const struct V_27 * V_28 )
{
void T_4 * V_5 ;
struct V_19 * V_15 = & V_26 -> V_15 ;
struct V_29 * V_30 = NULL ;
struct V_1 * V_2 ;
struct V_31 * V_32 = & V_26 -> V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 = V_26 -> V_15 . V_37 ;
if ( V_36 ) {
V_30 = F_19 ( V_15 , V_36 ) ;
if ( F_20 ( V_30 ) )
return F_21 ( V_30 ) ;
V_26 -> V_15 . V_38 = V_30 ;
}
V_2 = F_22 ( V_15 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
V_2 -> V_15 = & V_26 -> V_15 ;
F_23 ( V_15 , V_2 ) ;
V_5 = F_24 ( V_15 , V_32 ) ;
if ( F_20 ( V_5 ) )
return F_21 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_18 = V_26 -> V_41 ;
V_34 = F_22 ( V_15 , sizeof( * V_34 ) , V_39 ) ;
if ( ! V_34 )
return - V_40 ;
V_34 -> type = V_42 ;
V_34 -> V_43 . V_44 = V_45 ;
V_34 -> V_46 = & V_47 ;
V_34 -> V_30 = V_30 ;
V_34 -> V_15 = V_15 ;
V_34 -> V_48 = V_49 ;
V_2 -> V_12 = F_25 ( V_34 ) ;
if ( F_20 ( V_2 -> V_12 ) )
return F_21 ( V_2 -> V_12 ) ;
F_9 ( V_15 , L_5 ) ;
return 0 ;
}
static int F_26 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_27 ( V_26 ) ;
F_28 ( V_2 -> V_12 ) ;
return 0 ;
}
static int T_5 F_29 ( void )
{
return F_30 ( & V_50 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_50 ) ;
}
