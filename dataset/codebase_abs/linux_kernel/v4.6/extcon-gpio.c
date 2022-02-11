static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 =
F_2 ( F_3 ( V_2 ) , struct V_4 ,
V_2 ) ;
V_3 = F_4 ( V_5 -> V_6 ) ;
if ( V_5 -> V_7 -> V_8 )
V_3 = ! V_3 ;
F_5 ( V_5 -> V_9 , V_3 ) ;
}
static T_1 F_6 ( int V_10 , void * V_11 )
{
struct V_4 * V_5 = V_11 ;
F_7 ( V_12 , & V_5 -> V_2 ,
V_5 -> V_13 ) ;
return V_14 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_4 * V_5 )
{
struct V_17 * V_7 = V_5 -> V_7 ;
int V_18 ;
V_18 = F_9 ( V_16 , V_7 -> V_19 , V_20 ,
F_10 ( V_16 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_5 -> V_6 = F_11 ( V_7 -> V_19 ) ;
if ( ! V_5 -> V_6 )
return - V_21 ;
if ( V_7 -> V_22 ) {
V_18 = F_12 ( V_5 -> V_6 ,
V_7 -> V_22 * 1000 ) ;
if ( V_18 < 0 )
V_5 -> V_13 =
F_13 ( V_7 -> V_22 ) ;
}
V_5 -> V_10 = F_14 ( V_5 -> V_6 ) ;
if ( V_5 -> V_10 < 0 )
return V_5 -> V_10 ;
return 0 ;
}
static int F_15 ( struct V_23 * V_24 )
{
struct V_17 * V_7 = F_16 ( & V_24 -> V_16 ) ;
struct V_4 * V_5 ;
int V_18 ;
if ( ! V_7 )
return - V_25 ;
if ( ! V_7 -> V_26 || V_7 -> V_27 > V_28 )
return - V_21 ;
V_5 = F_17 ( & V_24 -> V_16 , sizeof( struct V_4 ) ,
V_29 ) ;
if ( ! V_5 )
return - V_30 ;
V_5 -> V_7 = V_7 ;
V_18 = F_8 ( & V_24 -> V_16 , V_5 ) ;
if ( V_18 < 0 )
return V_18 ;
V_5 -> V_9 = F_18 ( & V_24 -> V_16 , & V_7 -> V_27 ) ;
if ( F_19 ( V_5 -> V_9 ) ) {
F_20 ( & V_24 -> V_16 , L_1 ) ;
return - V_30 ;
}
V_18 = F_21 ( & V_24 -> V_16 , V_5 -> V_9 ) ;
if ( V_18 < 0 )
return V_18 ;
F_22 ( & V_5 -> V_2 , F_1 ) ;
V_18 = F_23 ( & V_24 -> V_16 , V_5 -> V_10 ,
F_6 , V_7 -> V_26 ,
V_24 -> V_31 , V_5 ) ;
if ( V_18 < 0 )
return V_18 ;
F_24 ( V_24 , V_5 ) ;
F_1 ( & V_5 -> V_2 . V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_26 ( V_24 ) ;
F_27 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_15 * V_16 )
{
struct V_4 * V_5 ;
V_5 = F_29 ( V_16 ) ;
if ( V_5 -> V_7 -> V_32 )
F_7 ( V_12 ,
& V_5 -> V_2 , V_5 -> V_13 ) ;
return 0 ;
}
