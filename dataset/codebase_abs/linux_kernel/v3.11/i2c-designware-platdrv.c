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
V_15 = F_7 ( V_5 , 0 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_5 -> V_2 , L_1 ) ;
return V_15 ;
}
V_2 = F_9 ( & V_5 -> V_2 , sizeof( struct V_1 ) , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
V_14 = F_10 ( V_5 , V_19 , 0 ) ;
V_2 -> V_20 = F_11 ( & V_5 -> V_2 , V_14 ) ;
if ( F_12 ( V_2 -> V_20 ) )
return F_13 ( V_2 -> V_20 ) ;
F_14 ( & V_2 -> V_21 ) ;
F_15 ( & V_2 -> V_22 ) ;
V_2 -> V_2 = & V_5 -> V_2 ;
V_2 -> V_15 = V_15 ;
F_16 ( V_5 , V_2 ) ;
V_2 -> V_3 = F_17 ( & V_5 -> V_2 , NULL ) ;
V_2 -> V_23 = F_1 ;
if ( F_12 ( V_2 -> V_3 ) )
return F_13 ( V_2 -> V_3 ) ;
F_18 ( V_2 -> V_3 ) ;
if ( V_5 -> V_2 . V_24 ) {
T_1 V_25 = 0 ;
T_1 V_26 = V_2 -> V_23 ( V_2 ) ;
F_19 ( V_5 -> V_2 . V_24 ,
L_2 , & V_25 ) ;
V_2 -> V_27 = F_20 ( ( V_28 ) V_26 * V_25 + 500000 ,
1000000 ) ;
}
V_2 -> V_29 =
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 ;
V_2 -> V_36 = V_37 | V_38 |
V_39 | V_40 ;
V_16 = F_3 ( V_5 ) ;
if ( V_16 ) {
T_1 V_41 = F_21 ( V_2 ) ;
V_2 -> V_9 = ( ( V_41 >> 16 ) & 0xff ) + 1 ;
V_2 -> V_10 = ( ( V_41 >> 8 ) & 0xff ) + 1 ;
V_2 -> V_7 . V_8 = V_5 -> V_42 ;
}
V_16 = F_22 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_23 ( V_2 ) ;
V_16 = F_24 ( & V_5 -> V_2 , V_2 -> V_15 , V_43 , V_44 ,
V_5 -> V_45 , V_2 ) ;
if ( V_16 ) {
F_8 ( & V_5 -> V_2 , L_3 , V_2 -> V_15 ) ;
return V_16 ;
}
V_12 = & V_2 -> V_7 ;
F_25 ( V_12 , V_2 ) ;
V_12 -> V_46 = V_47 ;
V_12 -> V_48 = V_49 ;
F_26 ( V_12 -> V_45 , L_4 ,
sizeof( V_12 -> V_45 ) ) ;
V_12 -> V_50 = & V_51 ;
V_12 -> V_2 . V_52 = & V_5 -> V_2 ;
V_12 -> V_2 . V_24 = V_5 -> V_2 . V_24 ;
V_16 = F_27 ( V_12 ) ;
if ( V_16 ) {
F_8 ( & V_5 -> V_2 , L_5 ) ;
return V_16 ;
}
F_28 ( V_12 ) ;
F_29 ( V_12 ) ;
F_30 ( & V_5 -> V_2 , 1000 ) ;
F_31 ( & V_5 -> V_2 ) ;
F_32 ( & V_5 -> V_2 ) ;
F_33 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_4 ( V_5 ) ;
F_35 ( & V_5 -> V_2 ) ;
F_36 ( & V_2 -> V_7 ) ;
F_37 ( V_2 ) ;
F_38 ( & V_5 -> V_2 ) ;
F_39 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_53 * V_2 )
{
struct V_4 * V_5 = F_41 ( V_2 ) ;
struct V_1 * V_54 = F_4 ( V_5 ) ;
F_42 ( V_54 -> V_3 ) ;
return 0 ;
}
static int F_43 ( struct V_53 * V_2 )
{
struct V_4 * V_5 = F_41 ( V_2 ) ;
struct V_1 * V_54 = F_4 ( V_5 ) ;
F_18 ( V_54 -> V_3 ) ;
F_22 ( V_54 ) ;
return 0 ;
}
static int T_2 F_44 ( void )
{
return F_45 ( & V_55 , F_6 ) ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_55 ) ;
}
