static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 =
F_2 ( F_3 ( V_2 ) , struct V_4 ,
V_2 ) ;
V_3 = F_4 ( V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
V_3 = ! V_3 ;
F_5 ( V_5 -> V_8 , V_3 ) ;
}
static T_1 F_6 ( int V_9 , void * V_10 )
{
struct V_4 * V_11 = V_10 ;
F_7 ( V_12 , & V_11 -> V_2 ,
V_11 -> V_13 ) ;
return V_14 ;
}
static int F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_9 ( & V_16 -> V_19 ) ;
struct V_4 * V_11 ;
int V_20 ;
if ( ! V_18 )
return - V_21 ;
if ( ! V_18 -> V_22 ) {
F_10 ( & V_16 -> V_19 , L_1 ) ;
return - V_23 ;
}
V_11 = F_11 ( & V_16 -> V_19 , sizeof( struct V_4 ) ,
V_24 ) ;
if ( ! V_11 )
return - V_25 ;
V_11 -> V_8 = F_12 ( & V_16 -> V_19 , NULL ) ;
if ( F_13 ( V_11 -> V_8 ) ) {
F_10 ( & V_16 -> V_19 , L_2 ) ;
return - V_25 ;
}
V_11 -> V_6 = V_18 -> V_6 ;
V_11 -> V_7 = V_18 -> V_7 ;
V_11 -> V_26 = V_18 -> V_26 ;
V_11 -> V_27 = V_18 -> V_27 ;
V_11 -> V_28 = V_18 -> V_28 ;
V_20 = F_14 ( & V_16 -> V_19 , V_11 -> V_6 , V_29 ,
V_16 -> V_30 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_18 -> V_31 ) {
V_20 = F_15 ( V_11 -> V_6 ,
V_18 -> V_31 * 1000 ) ;
if ( V_20 < 0 )
V_11 -> V_13 =
F_16 ( V_18 -> V_31 ) ;
}
V_20 = F_17 ( & V_16 -> V_19 , V_11 -> V_8 ) ;
if ( V_20 < 0 )
return V_20 ;
F_18 ( & V_11 -> V_2 , F_1 ) ;
V_11 -> V_9 = F_19 ( V_11 -> V_6 ) ;
if ( V_11 -> V_9 < 0 )
return V_11 -> V_9 ;
V_20 = F_20 ( V_11 -> V_9 , F_6 ,
V_18 -> V_22 , V_16 -> V_30 ,
V_11 ) ;
if ( V_20 < 0 )
return V_20 ;
F_21 ( V_16 , V_11 ) ;
F_1 ( & V_11 -> V_2 . V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_15 * V_16 )
{
struct V_4 * V_11 = F_23 ( V_16 ) ;
F_24 ( & V_11 -> V_2 ) ;
F_25 ( V_11 -> V_9 , V_11 ) ;
return 0 ;
}
static int F_26 ( struct V_32 * V_19 )
{
struct V_4 * V_11 ;
V_11 = F_27 ( V_19 ) ;
if ( V_11 -> V_28 )
F_7 ( V_12 ,
& V_11 -> V_2 , V_11 -> V_13 ) ;
return 0 ;
}
