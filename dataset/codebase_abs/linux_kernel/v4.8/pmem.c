struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_4 ( V_1 -> V_4 , L_1 , V_5 ) ;
F_5 ( & V_1 -> V_6 ) ;
}
static void F_6 ( void * V_7 )
{
struct V_2 * V_3 = V_7 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_4 ( V_1 -> V_4 , L_1 , V_5 ) ;
F_7 ( V_3 ) ;
F_8 ( & V_1 -> V_6 ) ;
}
static void F_9 ( void * V_7 )
{
struct V_2 * V_3 = V_7 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_4 ( V_1 -> V_4 , L_1 , V_5 ) ;
F_10 ( V_3 ) ;
}
static int F_11 ( struct V_8 * V_4 )
{
int V_9 ;
void * V_10 ;
struct V_11 V_12 ;
struct V_13 * V_14 ;
struct V_1 * V_1 ;
struct V_15 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_21 = F_12 ( V_4 ) ;
struct V_22 * V_22 = & V_21 -> V_22 ;
struct V_23 V_24 , * V_25 = NULL ;
V_20 = F_13 ( V_4 ) ;
if ( F_14 ( V_20 ) )
return F_15 ( V_20 ) ;
V_17 = F_16 ( & V_20 -> V_4 ) ;
F_17 ( V_4 , V_17 ) ;
V_25 = F_18 ( V_22 , & V_12 , & V_24 ) ;
if ( F_14 ( V_25 ) )
return F_15 ( V_25 ) ;
F_19 ( V_4 , V_17 ) ;
V_14 = V_22 -> V_14 ;
if ( ! F_20 ( V_4 , V_17 -> V_12 . V_26 ,
F_21 ( & V_17 -> V_12 ) , F_22 ( V_4 ) ) ) {
F_23 ( V_4 , L_2 , & V_17 -> V_12 ) ;
return - V_27 ;
}
V_1 = F_24 ( V_4 , sizeof( * V_1 ) , V_28 ) ;
if ( ! V_1 )
return - V_29 ;
V_1 -> V_4 = V_4 ;
F_25 ( & V_1 -> V_6 ) ;
V_9 = F_26 ( & V_1 -> V_3 , F_3 , 0 ,
V_28 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_27 ( V_4 , F_6 ,
& V_1 -> V_3 ) ;
if ( V_9 )
return V_9 ;
V_10 = F_28 ( V_4 , & V_12 , & V_1 -> V_3 , V_25 ) ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
V_9 = F_27 ( V_4 , F_9 ,
& V_1 -> V_3 ) ;
if ( V_9 )
return V_9 ;
V_12 . V_26 += F_29 ( V_14 -> V_30 ) ;
V_15 = F_30 ( V_4 -> V_31 ) ;
V_18 = F_31 ( V_4 , V_15 -> V_32 , & V_12 ,
F_32 ( V_14 -> V_33 ) , V_10 , V_34 | V_35 ) ;
if ( ! V_18 )
return - V_29 ;
V_9 = F_33 ( V_18 , & V_12 , 1 ) ;
F_34 ( V_18 ) ;
return V_9 ;
}
static int T_1 F_35 ( void )
{
return F_36 ( & V_36 ) ;
}
static void T_2 F_37 ( void )
{
F_38 ( & V_36 . V_37 ) ;
}
