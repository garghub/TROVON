static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_3 ( V_4 -> V_6 , V_4 -> V_7 , true ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_3 ( V_4 -> V_6 , V_4 -> V_7 , false ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_3 * V_4 ;
struct V_10 * V_5 = & V_9 -> V_5 ;
int V_11 ;
V_4 = F_6 ( V_5 , sizeof( * V_4 ) , V_12 ) ;
if ( ! V_4 )
return - V_13 ;
V_4 -> V_6 = F_7 ( V_5 ) ;
if ( ! V_4 -> V_6 )
return - V_14 ;
V_4 -> V_7 = F_8 ( V_9 -> V_5 . V_15 , L_1 ) ;
if ( V_4 -> V_7 < 0 ) {
F_9 ( & V_9 -> V_5 , L_2 , V_4 -> V_7 ) ;
return V_4 -> V_7 ;
}
V_11 = F_10 ( V_5 , & V_4 -> V_16 , NULL ) ;
if ( V_11 )
return V_11 ;
V_11 = F_11 ( & V_4 -> V_16 . V_2 ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_16 . V_2 . V_17 = F_1 ;
V_4 -> V_16 . V_2 . V_18 = F_4 ;
F_12 ( V_9 , V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_14 ( V_9 ) ;
F_15 ( & V_4 -> V_16 . V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_10 * V_5 )
{
struct V_8 * V_9 = F_17 ( V_5 ) ;
struct V_3 * V_4 = F_14 ( V_9 ) ;
if ( F_18 ( V_5 ) )
F_19 ( V_4 -> V_6 , V_4 -> V_7 , true ) ;
F_3 ( V_4 -> V_6 , V_4 -> V_7 , false ) ;
return 0 ;
}
static int F_20 ( struct V_10 * V_5 )
{
struct V_8 * V_9 = F_17 ( V_5 ) ;
struct V_3 * V_4 = F_14 ( V_9 ) ;
F_3 ( V_4 -> V_6 , V_4 -> V_7 , true ) ;
if ( F_18 ( V_5 ) )
F_19 ( V_4 -> V_6 , V_4 -> V_7 , false ) ;
return 0 ;
}
