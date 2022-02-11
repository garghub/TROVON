static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = * (struct V_5 * * ) F_3 ( V_4 ) ;
if ( V_6 == NULL )
return - V_9 ;
if ( V_6 -> V_8 )
return - V_10 ;
if ( F_4 ( & V_8 ) < 0 )
return - V_11 ;
V_6 -> V_8 = V_8 ;
F_5 ( V_6 ) ;
V_8 -> V_6 = V_6 ;
V_8 -> V_12 = V_13 ;
V_8 -> V_14 = V_6 -> V_15 ;
if ( V_6 -> V_16 ) {
F_6 ( V_17 L_1 ) ;
F_7 ( V_6 -> V_16 ) ;
}
V_6 -> V_16 = F_8 ( V_6 -> V_18 ) ;
if ( V_6 -> V_16 == NULL ) {
F_9 ( V_8 ) ;
V_6 -> V_8 = NULL ;
return - V_11 ;
}
V_8 -> V_16 = V_6 -> V_16 ;
V_8 -> V_19 = V_6 -> V_15 < 2 ? V_6 -> V_15 : 2 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 = 1 ;
V_8 -> V_22 = 2 ;
if ( F_10 ( V_8 , V_4 -> V_23 , V_6 -> V_24 , L_2 ) < 0 ) {
F_9 ( V_8 ) ;
F_7 ( V_6 -> V_16 ) ;
V_6 -> V_8 = NULL ;
V_6 -> V_16 = NULL ;
return - V_11 ;
}
if ( V_6 -> V_18 > 0 )
F_11 ( V_4 -> V_23 , V_6 , 1 ) ;
V_4 -> V_25 = V_6 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
if ( V_4 -> V_25 == NULL )
return 0 ;
V_6 = V_4 -> V_25 ;
if ( V_6 -> V_26 )
F_13 ( V_4 -> V_23 , V_6 -> V_26 ) ;
F_9 ( V_6 -> V_8 ) ;
F_7 ( V_6 -> V_16 ) ;
V_6 -> V_8 = NULL ;
V_6 -> V_16 = NULL ;
return 0 ;
}
