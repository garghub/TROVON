static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) -> V_3 . V_4 )
V_2 -> V_5 . V_6 |= V_7 ;
return 0 ;
}
static void
F_3 ( struct V_8 * V_9 , const struct V_10 * V_11 )
{
const struct V_12 * V_13 = & V_11 -> V_14 . V_15 ;
V_9 -> V_16 . V_17 = V_13 -> V_16 ;
V_9 -> V_18 . V_17 = V_13 -> V_18 ;
V_9 -> V_19 = F_4 ( V_11 , & V_13 -> V_20 ) ;
V_9 -> V_21 = F_5 ( 0xffff ) ;
V_9 -> V_22 = F_6 ( V_11 , & V_13 -> V_20 ) ;
V_9 -> V_23 = F_5 ( 0xffff ) ;
V_9 -> V_24 = V_25 ;
V_9 -> V_26 = 32 ;
V_9 -> V_27 = 32 ;
V_9 -> V_28 = V_13 -> V_29 ;
V_9 -> V_30 = V_13 -> V_31 ;
}
static void
F_7 ( struct V_1 * V_2 , const struct V_32 * V_33 ,
const T_1 * V_16 , const T_1 * V_18 )
{
V_2 -> V_34 = V_33 -> V_34 ;
if ( V_2 -> V_34 . V_16 . V_17 == 0 )
V_2 -> V_34 . V_16 . V_17 = V_16 -> V_17 ;
V_2 -> V_5 . V_18 = V_33 -> V_18 ;
if ( V_2 -> V_5 . V_18 . V_17 == 0 )
V_2 -> V_5 . V_18 . V_17 = V_18 -> V_17 ;
V_2 -> V_5 . V_35 = V_33 -> V_35 ;
V_2 -> V_5 . V_36 = V_33 -> V_36 ;
V_2 -> V_5 . V_24 = V_25 ;
}
int F_8 ( struct V_37 * V_38 )
{
const struct V_39 * V_40 = F_9 ( V_38 ) ;
F_10 ( V_38 ) -> V_41 = sizeof( * V_40 ) ;
F_10 ( V_38 ) -> V_34 = V_40 -> V_34 ;
F_10 ( V_38 ) -> V_42 = V_40 -> V_42 ;
F_10 ( V_38 ) -> V_43 = V_40 -> V_43 ;
F_10 ( V_38 ) -> V_44 = V_40 -> V_44 ;
F_10 ( V_38 ) -> V_45 = V_40 -> V_41 * 4 - sizeof( * V_40 ) ;
memset ( F_10 ( V_38 ) -> V_46 , 0 ,
sizeof( F_10 ( V_38 ) -> V_46 ) ) ;
return 0 ;
}
void T_2 F_11 ( void )
{
F_12 ( & V_47 ) ;
}
