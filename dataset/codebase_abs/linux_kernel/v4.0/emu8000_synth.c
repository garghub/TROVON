static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = * (struct V_3 * * ) F_2 ( V_2 ) ;
if ( V_4 == NULL )
return - V_7 ;
if ( V_4 -> V_6 )
return - V_8 ;
if ( F_3 ( & V_6 ) < 0 )
return - V_9 ;
V_4 -> V_6 = V_6 ;
F_4 ( V_4 ) ;
V_6 -> V_4 = V_4 ;
V_6 -> V_10 = V_11 ;
V_6 -> V_12 = V_4 -> V_13 ;
if ( V_4 -> V_14 ) {
F_5 ( V_15 L_1 ) ;
F_6 ( V_4 -> V_14 ) ;
}
V_4 -> V_14 = F_7 ( V_4 -> V_16 ) ;
if ( V_4 -> V_14 == NULL ) {
F_8 ( V_6 ) ;
V_4 -> V_6 = NULL ;
return - V_9 ;
}
V_6 -> V_14 = V_4 -> V_14 ;
V_6 -> V_17 = V_4 -> V_13 < 2 ? V_4 -> V_13 : 2 ;
V_6 -> V_18 = 1 ;
V_6 -> V_19 = 1 ;
V_6 -> V_20 = 2 ;
if ( F_9 ( V_6 , V_2 -> V_21 , V_4 -> V_22 , L_2 ) < 0 ) {
F_8 ( V_6 ) ;
F_6 ( V_4 -> V_14 ) ;
V_4 -> V_6 = NULL ;
V_4 -> V_14 = NULL ;
return - V_9 ;
}
if ( V_4 -> V_16 > 0 )
F_10 ( V_2 -> V_21 , V_4 , 1 ) ;
V_2 -> V_23 = V_4 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_23 == NULL )
return 0 ;
V_4 = V_2 -> V_23 ;
if ( V_4 -> V_24 )
F_12 ( V_2 -> V_21 , V_4 -> V_24 ) ;
F_8 ( V_4 -> V_6 ) ;
F_6 ( V_4 -> V_14 ) ;
V_4 -> V_6 = NULL ;
V_4 -> V_14 = NULL ;
return 0 ;
}
static int T_1 F_13 ( void )
{
static struct V_25 V_26 = {
F_1 ,
F_11 ,
} ;
return F_14 ( V_27 , & V_26 ,
sizeof( struct V_3 * ) ) ;
}
static void T_2 F_15 ( void )
{
F_16 ( V_27 ) ;
}
