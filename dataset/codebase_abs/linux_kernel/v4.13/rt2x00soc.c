static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
F_3 ( V_2 -> V_5 . V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 -> V_9 ) ;
struct V_10 * V_11 ;
V_11 = F_6 ( V_8 , V_12 , 0 ) ;
if ( ! V_11 )
return - V_13 ;
V_2 -> V_5 . V_6 = F_7 ( V_11 -> V_14 , F_8 ( V_11 ) ) ;
if ( ! V_2 -> V_5 . V_6 )
return - V_15 ;
V_2 -> V_4 = F_9 ( V_2 -> V_16 -> V_17 , V_18 ) ;
if ( ! V_2 -> V_4 )
goto exit;
V_2 -> V_3 = F_9 ( V_2 -> V_16 -> V_19 , V_18 ) ;
if ( ! V_2 -> V_3 )
goto exit;
return 0 ;
exit:
F_10 ( L_1 ) ;
F_1 ( V_2 ) ;
return - V_15 ;
}
int F_11 ( struct V_7 * V_8 , const struct V_20 * V_16 )
{
struct V_21 * V_22 ;
struct V_1 * V_2 ;
int V_23 ;
V_22 = F_12 ( sizeof( struct V_1 ) , V_16 -> V_22 ) ;
if ( ! V_22 ) {
F_10 ( L_2 ) ;
return - V_15 ;
}
F_13 ( V_8 , V_22 ) ;
V_2 = V_22 -> V_24 ;
V_2 -> V_9 = & V_8 -> V_9 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_25 = F_14 ( V_8 , 0 ) ;
V_2 -> V_26 = V_8 -> V_9 . V_27 -> V_26 ;
V_2 -> V_28 = F_15 ( & V_8 -> V_9 , NULL ) ;
if ( F_16 ( V_2 -> V_28 ) )
V_2 -> V_28 = NULL ;
F_17 ( V_2 , V_29 ) ;
V_23 = F_4 ( V_2 ) ;
if ( V_23 )
goto V_30;
V_23 = F_18 ( V_2 ) ;
if ( V_23 )
goto V_31;
return 0 ;
V_31:
F_1 ( V_2 ) ;
V_30:
F_19 ( V_22 ) ;
return V_23 ;
}
int F_20 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_21 ( V_8 ) ;
struct V_1 * V_2 = V_22 -> V_24 ;
F_22 ( V_2 ) ;
F_1 ( V_2 ) ;
F_19 ( V_22 ) ;
return 0 ;
}
int F_23 ( struct V_7 * V_8 , T_1 V_32 )
{
struct V_21 * V_22 = F_21 ( V_8 ) ;
struct V_1 * V_2 = V_22 -> V_24 ;
return F_24 ( V_2 , V_32 ) ;
}
int F_25 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = F_21 ( V_8 ) ;
struct V_1 * V_2 = V_22 -> V_24 ;
return F_26 ( V_2 ) ;
}
