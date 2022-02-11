static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = V_4 -> V_6 * V_2 -> V_5 ;
F_3 ( V_5 , V_4 -> V_7 + V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_9 , V_4 -> V_7 + V_10 ) ;
F_3 ( V_11 , V_4 -> V_7 + V_10 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_12 , V_4 -> V_7 + V_10 ) ;
F_3 ( V_13 , V_4 -> V_7 + V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
F_6 ( V_2 ) ;
V_2 -> V_5 = V_14 ;
F_5 ( V_2 ) ;
return 0 ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_15 ;
V_15 = F_9 ( V_4 -> V_7 + V_10 ) ;
return V_15 / V_4 -> V_6 ;
}
static int F_10 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
struct V_3 * V_4 ;
struct V_20 * V_21 ;
int V_22 ;
V_4 = F_11 ( V_19 , sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
F_12 ( V_17 , V_4 ) ;
V_21 = F_13 ( V_17 , V_25 , 0 ) ;
V_4 -> V_7 = F_14 ( V_19 , V_21 ) ;
if ( F_15 ( V_4 -> V_7 ) )
return F_16 ( V_4 -> V_7 ) ;
V_4 -> V_26 = F_17 ( V_19 , NULL ) ;
if ( ! F_15 ( V_4 -> V_26 ) ) {
V_22 = F_18 ( V_4 -> V_26 ) ;
if ( V_22 )
return V_22 ;
V_4 -> V_6 = F_19 ( V_4 -> V_26 ) ;
if ( ! V_4 -> V_6 )
V_4 -> V_6 = V_27 ;
} else {
V_4 -> V_6 = V_27 ;
V_4 -> V_26 = NULL ;
}
V_4 -> V_28 . V_29 = & V_30 ;
V_4 -> V_28 . V_31 = & V_32 ;
V_4 -> V_28 . V_33 = V_34 ;
V_4 -> V_28 . V_5 = V_35 ;
V_4 -> V_28 . V_36 = 0xffffffff / V_4 -> V_6 ;
V_4 -> V_28 . V_37 = V_19 ;
F_20 ( & V_4 -> V_28 , V_4 ) ;
V_22 = F_21 ( & V_4 -> V_28 ) ;
if ( V_22 ) {
F_22 ( V_19 , L_1 ) ;
F_23 ( V_4 -> V_26 ) ;
return V_22 ;
}
F_24 ( V_19 , L_2 ) ;
return 0 ;
}
static int F_25 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_26 ( V_17 ) ;
if ( ! V_38 )
F_6 ( & V_4 -> V_28 ) ;
F_27 ( & V_4 -> V_28 ) ;
F_23 ( V_4 -> V_26 ) ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_29 ( V_19 ) ;
if ( F_30 ( & V_4 -> V_28 ) )
return F_6 ( & V_4 -> V_28 ) ;
return 0 ;
}
static int F_31 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_29 ( V_19 ) ;
if ( F_30 ( & V_4 -> V_28 ) )
return F_5 ( & V_4 -> V_28 ) ;
return 0 ;
}
static void F_32 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_26 ( V_17 ) ;
if ( F_30 ( & V_4 -> V_28 ) )
F_6 ( & V_4 -> V_28 ) ;
}
