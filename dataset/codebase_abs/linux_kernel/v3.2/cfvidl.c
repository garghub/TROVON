struct V_1 * F_1 ( T_1 V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( sizeof( struct V_4 ) , V_6 ) ;
if ( ! V_5 )
return NULL ;
F_3 ( F_4 ( struct V_4 , V_7 ) == 0 ) ;
F_5 ( V_5 , V_2 , V_3 , false ) ;
V_5 -> V_7 . V_8 = V_9 ;
V_5 -> V_7 . V_10 = V_11 ;
snprintf ( V_5 -> V_7 . V_12 , V_13 - 1 , L_1 ) ;
return & V_5 -> V_7 ;
}
static int V_9 ( struct V_1 * V_14 , struct V_15 * V_16 )
{
T_2 V_17 ;
if ( F_6 ( V_16 , & V_17 , 4 ) < 0 ) {
F_7 ( L_2 ) ;
F_8 ( V_16 ) ;
return - V_18 ;
}
return V_14 -> V_19 -> V_8 ( V_14 -> V_19 , V_16 ) ;
}
static int V_11 ( struct V_1 * V_14 , struct V_15 * V_16 )
{
struct V_4 * V_20 = F_9 ( V_14 ) ;
struct V_21 * V_22 ;
T_2 V_17 = 0 ;
int V_23 ;
if ( ! F_10 ( V_20 , & V_23 ) )
return V_23 ;
F_11 ( V_16 , & V_17 , 4 ) ;
V_22 = F_12 ( V_16 ) ;
V_22 -> V_2 = V_20 -> V_7 . V_24 ;
V_22 -> V_3 = & V_20 -> V_3 ;
return V_14 -> V_25 -> V_10 ( V_14 -> V_25 , V_16 ) ;
}
