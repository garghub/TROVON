struct V_1 * F_1 ( T_1 V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( sizeof( struct V_4 ) , V_6 ) ;
if ( ! V_5 ) {
F_3 ( L_1 ) ;
return NULL ;
}
F_4 ( F_5 ( struct V_4 , V_7 ) == 0 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
F_6 ( V_5 , V_2 , V_3 , false ) ;
V_5 -> V_7 . V_8 = V_9 ;
V_5 -> V_7 . V_10 = V_11 ;
snprintf ( V_5 -> V_7 . V_12 , V_13 - 1 , L_2 ) ;
return & V_5 -> V_7 ;
}
static int V_9 ( struct V_1 * V_14 , struct V_15 * V_16 )
{
T_2 V_17 ;
if ( F_7 ( V_16 , & V_17 , 4 ) < 0 ) {
F_8 ( L_3 ) ;
F_9 ( V_16 ) ;
return - V_18 ;
}
return V_14 -> V_19 -> V_8 ( V_14 -> V_19 , V_16 ) ;
}
static int V_11 ( struct V_1 * V_14 , struct V_15 * V_16 )
{
struct V_4 * V_20 = F_10 ( V_14 ) ;
struct V_21 * V_22 ;
T_2 V_17 = 0 ;
int V_23 ;
if ( ! F_11 ( V_20 , & V_23 ) )
return V_23 ;
F_12 ( V_16 , & V_17 , 4 ) ;
V_22 = F_13 ( V_16 ) ;
V_22 -> V_2 = V_20 -> V_7 . V_24 ;
V_22 -> V_3 = & V_20 -> V_3 ;
return V_14 -> V_25 -> V_10 ( V_14 -> V_25 , V_16 ) ;
}
