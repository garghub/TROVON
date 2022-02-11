static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_6 = & V_5 -> V_6 ;
F_4 ( V_2 , L_1 , V_7 ) ;
F_5 ( V_2 , & V_6 -> V_8 ) ;
F_6 ( & V_3 -> V_9 , V_6 -> V_10 ) ;
F_7 ( V_6 -> V_11 ) ;
F_7 ( V_5 ) ;
}
bool F_8 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_12 : false ;
}
struct V_5 * F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_9 ( V_2 , struct V_5 , V_6 . V_2 ) ;
F_10 ( ! F_8 ( V_2 ) ) ;
return V_5 ;
}
static struct V_5 * F_11 ( struct V_3 * V_3 )
{
struct V_6 * V_6 ;
struct V_5 * V_5 ;
struct V_1 * V_2 ;
V_5 = F_12 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
return NULL ;
V_6 = & V_5 -> V_6 ;
V_6 -> V_10 = F_13 ( & V_3 -> V_9 , 0 , 0 , V_13 ) ;
if ( V_6 -> V_10 < 0 ) {
F_7 ( V_5 ) ;
return NULL ;
}
V_2 = & V_6 -> V_2 ;
F_14 ( V_2 , L_2 , V_3 -> V_10 , V_6 -> V_10 ) ;
V_2 -> V_14 = V_15 ;
V_2 -> type = & V_12 ;
V_2 -> V_4 = & V_3 -> V_2 ;
return V_5 ;
}
struct V_1 * F_15 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = NULL ;
struct V_5 * V_5 ;
if ( ! F_16 ( & V_3 -> V_2 ) )
return NULL ;
V_5 = F_11 ( V_3 ) ;
if ( V_5 )
V_2 = F_17 ( & V_5 -> V_6 , NULL ) ;
F_18 ( V_2 ) ;
return V_2 ;
}
int F_19 ( struct V_1 * V_2 , struct V_16 * V_8 )
{
int V_17 ;
struct V_5 * V_5 ;
struct V_1 * V_18 ;
struct V_6 * V_6 ;
struct V_19 * V_20 ;
struct V_3 * V_3 = F_2 ( V_8 -> V_2 . V_4 ) ;
if ( V_8 -> V_21 )
return - V_22 ;
F_20 ( & V_8 -> V_2 ) ;
V_5 = F_11 ( V_3 ) ;
V_6 = & V_5 -> V_6 ;
V_18 = F_17 ( V_6 , V_8 ) ;
F_21 ( & V_8 -> V_2 ) ;
if ( ! V_18 )
return - V_23 ;
V_20 = F_22 ( V_2 , sizeof( * V_20 ) , V_13 ) ;
V_6 -> V_20 = V_20 ;
V_17 = F_23 ( V_6 , V_24 ) ;
F_4 ( V_2 , L_3 , V_7 ,
V_17 == 0 ? F_24 ( V_18 ) : L_4 ) ;
if ( V_17 < 0 ) {
F_25 ( V_18 , & V_6 -> V_8 ) ;
F_26 ( V_18 ) ;
} else
F_18 ( V_18 ) ;
return V_17 ;
}
