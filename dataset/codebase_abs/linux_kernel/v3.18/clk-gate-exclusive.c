static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = F_2 ( V_4 ,
struct V_5 , V_4 ) ;
T_1 V_7 = F_3 ( V_4 -> V_8 ) ;
if ( V_7 & V_6 -> V_9 )
return - V_10 ;
return V_11 . V_12 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_11 . V_13 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return V_11 . V_14 ( V_2 ) ;
}
struct V_15 * F_6 ( const char * V_16 , const char * V_17 ,
void T_2 * V_8 , T_3 V_18 , T_1 V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_15 * V_15 ;
struct V_19 V_20 ;
if ( V_9 == 0 )
return F_7 ( - V_21 ) ;
V_6 = F_8 ( sizeof( * V_6 ) , V_22 ) ;
if ( ! V_6 )
return F_7 ( - V_23 ) ;
V_4 = & V_6 -> V_4 ;
V_20 . V_16 = V_16 ;
V_20 . V_24 = & V_25 ;
V_20 . V_26 = V_27 ;
V_20 . V_28 = V_17 ? & V_17 : NULL ;
V_20 . V_29 = V_17 ? 1 : 0 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_30 = V_18 ;
V_4 -> V_31 = & V_32 ;
V_4 -> V_2 . V_20 = & V_20 ;
V_6 -> V_9 = V_9 ;
V_15 = F_9 ( NULL , & V_4 -> V_2 ) ;
if ( F_10 ( V_15 ) )
F_11 ( V_6 ) ;
return V_15 ;
}
