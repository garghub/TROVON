static inline void F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_3 * V_5 = F_3 ( V_2 ) ;
if ( F_4 ( F_5 ( V_4 ) ) )
F_6 ( V_5 ) ;
}
static int F_7 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_8 * V_9 = F_8 ( V_2 ) ;
struct V_3 * V_10 ;
int V_11 ;
F_9 ( V_2 , - V_7 -> V_12 . V_13 ) ;
V_2 -> V_14 = V_2 -> V_15 +
F_10 ( struct V_3 , V_16 ) ;
V_2 -> V_17 = V_2 -> V_15 + sizeof( * V_10 ) ;
V_10 = F_2 ( V_2 ) ;
V_10 -> V_18 = 6 ;
memcpy ( V_10 -> V_19 , F_11 ( V_2 ) -> V_19 ,
sizeof( V_10 -> V_19 ) ) ;
V_10 -> V_16 = F_12 ( F_8 ( V_2 ) -> V_20 -> V_21 ) ;
V_11 = F_11 ( V_2 ) -> V_22 ;
V_11 = F_13 ( V_11 , V_11 ) ;
if ( V_7 -> V_12 . V_23 & V_24 )
V_11 &= ~ V_25 ;
F_14 ( V_10 , 0 , V_11 ) ;
V_10 -> V_26 = F_15 ( V_9 -> V_27 ) ;
F_16 ( & V_10 -> V_28 , ( const struct V_29 * ) & V_7 -> V_12 . V_28 ) ;
F_16 ( & V_10 -> V_30 , ( const struct V_29 * ) & V_7 -> V_31 . V_30 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
int V_32 = - V_33 ;
const unsigned char * V_34 ;
if ( F_11 ( V_2 ) -> V_35 != V_36 )
goto V_37;
if ( ! F_18 ( V_2 , sizeof( struct V_3 ) ) )
goto V_37;
if ( F_19 ( V_2 ) &&
( V_32 = F_20 ( V_2 , 0 , 0 , V_38 ) ) )
goto V_37;
if ( V_7 -> V_12 . V_23 & V_39 )
F_21 ( F_5 ( F_2 ( V_2 ) ) ,
F_3 ( V_2 ) ) ;
if ( ! ( V_7 -> V_12 . V_23 & V_24 ) )
F_1 ( V_2 ) ;
V_34 = F_22 ( V_2 ) ;
F_23 ( V_2 , - V_2 -> V_40 ) ;
memmove ( F_22 ( V_2 ) , V_34 , V_2 -> V_40 ) ;
F_24 ( V_2 ) ;
V_32 = 0 ;
V_37:
return V_32 ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_41 , V_42 ) ;
}
static void T_2 F_27 ( void )
{
int V_32 ;
V_32 = F_28 ( & V_41 , V_42 ) ;
F_29 ( V_32 ) ;
}
