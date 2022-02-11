static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
V_8 = F_2 ( V_2 ) ;
if ( V_8 == NULL )
return - V_10 ;
if ( V_8 -> V_11 <= 0 )
return 0 ;
if ( V_8 -> V_12 < 1 )
V_8 -> V_12 = 1 ;
else if ( V_8 -> V_12 > 64 )
V_8 -> V_12 = 64 ;
if ( F_3 ( & V_4 ) < 0 )
return - V_13 ;
F_4 ( V_4 ) ;
V_6 = V_8 -> V_14 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_12 = V_8 -> V_12 ;
V_4 -> V_15 = V_8 -> V_11 ;
V_4 -> V_16 = - 501 ;
V_4 -> V_17 = V_6 -> V_17 ;
V_4 -> V_18 = V_8 -> V_11 < 2 ? V_8 -> V_11 : 2 ;
V_4 -> V_19 = V_6 -> V_20 ? 2 : 1 ;
V_4 -> V_21 = 0 ;
V_4 -> V_22 = 2 ;
if ( F_5 ( V_4 , V_2 -> V_23 , V_8 -> V_24 , L_1 ) < 0 ) {
F_6 ( V_4 ) ;
return - V_13 ;
}
F_7 ( & V_6 -> V_25 , V_9 ) ;
V_6 -> V_26 = V_4 ;
V_6 -> V_27 = V_28 ;
F_8 ( & V_6 -> V_25 , V_9 ) ;
V_2 -> V_29 = V_4 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_9 ;
if ( V_2 -> V_29 == NULL )
return 0 ;
V_4 = V_2 -> V_29 ;
V_6 = V_4 -> V_6 ;
F_7 ( & V_6 -> V_25 , V_9 ) ;
V_6 -> V_26 = NULL ;
V_6 -> V_27 = NULL ;
F_8 ( & V_6 -> V_25 , V_9 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int T_1 F_10 ( void )
{
static struct V_30 V_31 = {
F_1 ,
F_9 ,
} ;
return F_11 ( V_32 , & V_31 ,
sizeof( struct V_7 ) ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( V_32 ) ;
}
