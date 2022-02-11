static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_3 ( V_4 -> V_6 , V_4 -> V_7 , V_4 -> V_8 , true ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_3 ( V_4 -> V_6 , V_4 -> V_7 , V_4 -> V_8 , false ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_3 * V_4 ;
struct V_11 * V_5 = & V_10 -> V_5 ;
int V_12 ;
V_4 = F_6 ( V_5 , sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 )
return - V_14 ;
V_4 -> V_6 = F_7 ( V_5 ) ;
if ( ! V_4 -> V_6 )
return - V_15 ;
V_4 -> V_7 = F_8 ( V_10 -> V_5 . V_16 , L_1 ) ;
if ( V_4 -> V_7 < 0 ) {
F_9 ( & V_10 -> V_5 , L_2 , V_4 -> V_7 ) ;
return V_4 -> V_7 ;
}
V_4 -> V_8 = F_10 ( V_10 -> V_5 . V_16 , - 1 ) ;
V_12 = F_11 ( V_5 , & V_4 -> V_17 , NULL ) ;
if ( V_12 )
return V_12 ;
V_12 = F_12 ( & V_4 -> V_17 . V_2 ) ;
if ( V_12 )
return V_12 ;
V_4 -> V_17 . V_2 . V_18 = F_1 ;
V_4 -> V_17 . V_2 . V_19 = F_4 ;
F_13 ( V_10 , V_4 ) ;
F_14 ( V_5 , true ) ;
F_15 ( V_5 , false ) ;
F_3 ( V_4 -> V_6 , V_4 -> V_7 , V_4 -> V_8 , false ) ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_17 ( V_10 ) ;
F_18 ( & V_4 -> V_17 . V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_5 )
{
struct V_9 * V_10 = F_20 ( V_5 ) ;
struct V_3 * V_4 = F_17 ( V_10 ) ;
if ( F_21 ( V_5 ) )
F_22 ( V_4 -> V_6 , V_4 -> V_7 , true ) ;
F_3 ( V_4 -> V_6 , V_4 -> V_7 , V_4 -> V_8 , false ) ;
return 0 ;
}
static int F_23 ( struct V_11 * V_5 )
{
struct V_9 * V_10 = F_20 ( V_5 ) ;
struct V_3 * V_4 = F_17 ( V_10 ) ;
F_3 ( V_4 -> V_6 , V_4 -> V_7 , V_4 -> V_8 , true ) ;
if ( F_21 ( V_5 ) )
F_22 ( V_4 -> V_6 , V_4 -> V_7 , false ) ;
return 0 ;
}
