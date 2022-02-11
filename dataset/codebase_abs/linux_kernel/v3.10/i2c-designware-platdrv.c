static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) / 1000 ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_4 ( V_5 ) ;
if ( ! F_5 ( & V_5 -> V_2 ) )
return - V_6 ;
V_2 -> V_7 . V_8 = - 1 ;
V_2 -> V_9 = 32 ;
V_2 -> V_10 = 32 ;
return 0 ;
}
static inline int F_3 ( struct V_4 * V_5 )
{
return - V_6 ;
}
static int F_6 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 , V_16 ;
V_14 = F_7 ( V_5 , V_17 , 0 ) ;
if ( ! V_14 ) {
F_8 ( & V_5 -> V_2 , L_1 ) ;
return - V_18 ;
}
V_15 = F_9 ( V_5 , 0 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_5 -> V_2 , L_2 ) ;
return V_15 ;
}
V_2 = F_10 ( & V_5 -> V_2 , sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_2 )
return - V_20 ;
V_2 -> V_21 = F_11 ( & V_5 -> V_2 , V_14 ) ;
if ( F_12 ( V_2 -> V_21 ) )
return F_13 ( V_2 -> V_21 ) ;
F_14 ( & V_2 -> V_22 ) ;
F_15 ( & V_2 -> V_23 ) ;
V_2 -> V_2 = & V_5 -> V_2 ;
V_2 -> V_15 = V_15 ;
F_16 ( V_5 , V_2 ) ;
V_2 -> V_3 = F_17 ( & V_5 -> V_2 , NULL ) ;
V_2 -> V_24 = F_1 ;
if ( F_12 ( V_2 -> V_3 ) )
return F_13 ( V_2 -> V_3 ) ;
F_18 ( V_2 -> V_3 ) ;
V_2 -> V_25 =
V_26 |
V_27 |
V_28 |
V_29 |
V_30 |
V_31 ;
V_2 -> V_32 = V_33 | V_34 |
V_35 | V_36 ;
V_16 = F_3 ( V_5 ) ;
if ( V_16 ) {
T_1 V_37 = F_19 ( V_2 ) ;
V_2 -> V_9 = ( ( V_37 >> 16 ) & 0xff ) + 1 ;
V_2 -> V_10 = ( ( V_37 >> 8 ) & 0xff ) + 1 ;
V_2 -> V_7 . V_8 = V_5 -> V_38 ;
}
V_16 = F_20 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_21 ( V_2 ) ;
V_16 = F_22 ( & V_5 -> V_2 , V_2 -> V_15 , V_39 , V_40 ,
V_5 -> V_41 , V_2 ) ;
if ( V_16 ) {
F_8 ( & V_5 -> V_2 , L_3 , V_2 -> V_15 ) ;
return V_16 ;
}
V_12 = & V_2 -> V_7 ;
F_23 ( V_12 , V_2 ) ;
V_12 -> V_42 = V_43 ;
V_12 -> V_44 = V_45 ;
F_24 ( V_12 -> V_41 , L_4 ,
sizeof( V_12 -> V_41 ) ) ;
V_12 -> V_46 = & V_47 ;
V_12 -> V_2 . V_48 = & V_5 -> V_2 ;
V_12 -> V_2 . V_49 = V_5 -> V_2 . V_49 ;
V_16 = F_25 ( V_12 ) ;
if ( V_16 ) {
F_8 ( & V_5 -> V_2 , L_5 ) ;
return V_16 ;
}
F_26 ( V_12 ) ;
F_27 ( V_12 ) ;
F_28 ( & V_5 -> V_2 , 1000 ) ;
F_29 ( & V_5 -> V_2 ) ;
F_30 ( & V_5 -> V_2 ) ;
F_31 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_4 ( V_5 ) ;
F_33 ( & V_5 -> V_2 ) ;
F_34 ( & V_2 -> V_7 ) ;
F_35 ( V_2 ) ;
F_36 ( & V_5 -> V_2 ) ;
F_37 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_50 * V_2 )
{
struct V_4 * V_5 = F_39 ( V_2 ) ;
struct V_1 * V_51 = F_4 ( V_5 ) ;
F_40 ( V_51 -> V_3 ) ;
return 0 ;
}
static int F_41 ( struct V_50 * V_2 )
{
struct V_4 * V_5 = F_39 ( V_2 ) ;
struct V_1 * V_51 = F_4 ( V_5 ) ;
F_18 ( V_51 -> V_3 ) ;
F_20 ( V_51 ) ;
return 0 ;
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_52 , F_6 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_52 ) ;
}
