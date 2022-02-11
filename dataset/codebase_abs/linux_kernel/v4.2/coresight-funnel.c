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
F_8 ( V_2 -> V_15 ) ;
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
F_12 ( V_2 -> V_15 ) ;
F_9 ( V_2 -> V_15 , L_2 , V_13 ) ;
}
static T_2 F_13 ( struct V_17 * V_15 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_1 * V_2 = F_7 ( V_15 -> V_16 ) ;
unsigned long V_21 = V_2 -> V_9 ;
return sprintf ( V_20 , L_3 , V_21 ) ;
}
static T_2 F_14 ( struct V_17 * V_15 ,
struct V_18 * V_19 ,
const char * V_20 , T_3 V_22 )
{
int V_23 ;
unsigned long V_21 ;
struct V_1 * V_2 = F_7 ( V_15 -> V_16 ) ;
V_23 = F_15 ( V_20 , 16 , & V_21 ) ;
if ( V_23 )
return V_23 ;
V_2 -> V_9 = V_21 ;
return V_22 ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_2 ( V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
F_5 ( V_2 -> V_5 ) ;
return V_4 ;
}
static T_2 F_17 ( struct V_17 * V_15 ,
struct V_18 * V_19 , char * V_20 )
{
T_1 V_21 ;
struct V_1 * V_2 = F_7 ( V_15 -> V_16 ) ;
F_8 ( V_2 -> V_15 ) ;
V_21 = F_16 ( V_2 ) ;
F_12 ( V_2 -> V_15 ) ;
return sprintf ( V_20 , L_4 , V_21 ) ;
}
static int F_18 ( struct V_24 * V_25 , const struct V_26 * V_27 )
{
int V_23 ;
void T_4 * V_5 ;
struct V_17 * V_15 = & V_25 -> V_15 ;
struct V_28 * V_29 = NULL ;
struct V_1 * V_2 ;
struct V_30 * V_31 = & V_25 -> V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 = V_25 -> V_15 . V_36 ;
if ( V_35 ) {
V_29 = F_19 ( V_15 , V_35 ) ;
if ( F_20 ( V_29 ) )
return F_21 ( V_29 ) ;
V_25 -> V_15 . V_37 = V_29 ;
}
V_2 = F_22 ( V_15 , sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
V_2 -> V_15 = & V_25 -> V_15 ;
V_2 -> V_40 = F_23 ( & V_25 -> V_15 , L_5 ) ;
if ( ! F_20 ( V_2 -> V_40 ) ) {
V_23 = F_24 ( V_2 -> V_40 ) ;
if ( V_23 )
return V_23 ;
}
F_25 ( V_15 , V_2 ) ;
V_5 = F_26 ( V_15 , V_31 ) ;
if ( F_20 ( V_5 ) )
return F_21 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
F_12 ( & V_25 -> V_15 ) ;
V_33 = F_22 ( V_15 , sizeof( * V_33 ) , V_38 ) ;
if ( ! V_33 )
return - V_39 ;
V_33 -> type = V_41 ;
V_33 -> V_42 . V_43 = V_44 ;
V_33 -> V_45 = & V_46 ;
V_33 -> V_29 = V_29 ;
V_33 -> V_15 = V_15 ;
V_33 -> V_47 = V_48 ;
V_2 -> V_12 = F_27 ( V_33 ) ;
if ( F_20 ( V_2 -> V_12 ) )
return F_21 ( V_2 -> V_12 ) ;
F_9 ( V_15 , L_6 ) ;
return 0 ;
}
static int F_28 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_29 ( V_25 ) ;
F_30 ( V_2 -> V_12 ) ;
return 0 ;
}
static int F_31 ( struct V_17 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
if ( V_2 && ! F_20 ( V_2 -> V_40 ) )
F_32 ( V_2 -> V_40 ) ;
return 0 ;
}
static int F_33 ( struct V_17 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
if ( V_2 && ! F_20 ( V_2 -> V_40 ) )
F_24 ( V_2 -> V_40 ) ;
return 0 ;
}
