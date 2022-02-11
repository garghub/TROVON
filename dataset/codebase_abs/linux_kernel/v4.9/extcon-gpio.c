static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 =
F_2 ( F_3 ( V_2 ) , struct V_4 ,
V_2 ) ;
V_3 = F_4 ( V_5 -> V_6 ) ;
if ( V_5 -> V_7 -> V_8 )
V_3 = ! V_3 ;
F_5 ( V_5 -> V_9 , V_5 -> V_7 -> V_10 , V_3 ) ;
}
static T_1 F_6 ( int V_11 , void * V_12 )
{
struct V_4 * V_5 = V_12 ;
F_7 ( V_13 , & V_5 -> V_2 ,
V_5 -> V_14 ) ;
return V_15 ;
}
static int F_8 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
struct V_18 * V_7 = V_5 -> V_7 ;
int V_19 ;
V_19 = F_9 ( V_17 , V_7 -> V_20 , V_21 ,
F_10 ( V_17 ) ) ;
if ( V_19 < 0 )
return V_19 ;
V_5 -> V_6 = F_11 ( V_7 -> V_20 ) ;
if ( ! V_5 -> V_6 )
return - V_22 ;
if ( V_7 -> V_23 ) {
V_19 = F_12 ( V_5 -> V_6 ,
V_7 -> V_23 * 1000 ) ;
if ( V_19 < 0 )
V_5 -> V_14 =
F_13 ( V_7 -> V_23 ) ;
}
V_5 -> V_11 = F_14 ( V_5 -> V_6 ) ;
if ( V_5 -> V_11 < 0 )
return V_5 -> V_11 ;
return 0 ;
}
static int F_15 ( struct V_24 * V_25 )
{
struct V_18 * V_7 = F_16 ( & V_25 -> V_17 ) ;
struct V_4 * V_5 ;
int V_19 ;
if ( ! V_7 )
return - V_26 ;
if ( ! V_7 -> V_27 || V_7 -> V_10 > V_28 )
return - V_22 ;
V_5 = F_17 ( & V_25 -> V_17 , sizeof( struct V_4 ) ,
V_29 ) ;
if ( ! V_5 )
return - V_30 ;
V_5 -> V_7 = V_7 ;
V_19 = F_8 ( & V_25 -> V_17 , V_5 ) ;
if ( V_19 < 0 )
return V_19 ;
V_5 -> V_9 = F_18 ( & V_25 -> V_17 , & V_7 -> V_10 ) ;
if ( F_19 ( V_5 -> V_9 ) ) {
F_20 ( & V_25 -> V_17 , L_1 ) ;
return - V_30 ;
}
V_19 = F_21 ( & V_25 -> V_17 , V_5 -> V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
F_22 ( & V_5 -> V_2 , F_1 ) ;
V_19 = F_23 ( & V_25 -> V_17 , V_5 -> V_11 ,
F_6 , V_7 -> V_27 ,
V_25 -> V_31 , V_5 ) ;
if ( V_19 < 0 )
return V_19 ;
F_24 ( V_25 , V_5 ) ;
F_1 ( & V_5 -> V_2 . V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_26 ( V_25 ) ;
F_27 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_16 * V_17 )
{
struct V_4 * V_5 ;
V_5 = F_29 ( V_17 ) ;
if ( V_5 -> V_7 -> V_32 )
F_7 ( V_13 ,
& V_5 -> V_2 , V_5 -> V_14 ) ;
return 0 ;
}
