static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = 6 ;
memcpy ( V_4 -> V_6 , F_3 ( V_2 ) -> V_6 ,
sizeof( V_4 -> V_6 ) ) ;
V_4 -> V_7 = F_3 ( V_2 ) -> V_8 ;
F_4 ( V_4 , 0 , F_3 ( V_2 ) -> V_9 ) ;
V_4 -> V_10 = F_3 ( V_2 ) -> V_11 ;
}
static int F_5 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_3 * V_14 ;
struct V_15 * V_16 ;
int V_17 , V_18 ;
V_18 = 0 ;
V_17 = F_3 ( V_2 ) -> V_17 ;
if ( F_6 ( V_17 ) )
V_18 += V_19 - ( V_17 & 4 ) ;
F_7 ( V_2 , - V_13 -> V_20 . V_21 - V_18 ) ;
if ( V_13 -> V_22 . V_23 != V_24 )
V_2 -> V_25 += V_19 ;
V_2 -> V_26 = V_2 -> V_25 +
F_8 ( struct V_3 , V_7 ) ;
V_2 -> V_27 = V_2 -> V_25 + sizeof( * V_14 ) ;
V_16 = (struct V_15 * ) F_9 ( V_2 , F_3 ( V_2 ) -> V_28 - V_18 ) ;
F_1 ( V_2 ) ;
V_14 = F_2 ( V_2 ) ;
if ( F_6 ( V_17 ) ) {
F_10 ( V_17 < 0 ) ;
V_16 -> V_29 = 4 - ( V_17 & 4 ) ;
V_16 -> V_30 = V_17 / 8 ;
V_16 -> V_7 = V_14 -> V_7 ;
if ( V_16 -> V_29 )
memset ( V_16 + 1 , V_31 , V_16 -> V_29 ) ;
V_14 -> V_7 = V_32 ;
}
F_11 ( & V_14 -> V_33 , (struct V_34 * ) & V_13 -> V_20 . V_33 ) ;
F_11 ( & V_14 -> V_35 , (struct V_34 * ) & V_13 -> V_36 . V_35 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_3 * V_37 ;
const unsigned char * V_38 ;
int V_39 = sizeof( struct V_3 ) ;
int V_40 ;
V_40 = F_13 ( V_2 , V_39 + V_2 -> V_41 ) ;
if ( V_40 )
goto V_42;
F_14 ( V_2 , V_39 ) ;
F_15 ( V_2 ) ;
V_38 = F_16 ( V_2 ) ;
F_17 ( V_2 , - V_2 -> V_41 ) ;
memmove ( F_16 ( V_2 ) , V_38 , V_2 -> V_41 ) ;
F_1 ( V_2 ) ;
V_37 = F_2 ( V_2 ) ;
V_37 -> V_43 = F_18 ( V_2 -> V_44 - V_39 ) ;
F_11 ( & V_37 -> V_35 , (struct V_34 * ) & V_13 -> V_22 . V_35 . V_45 ) ;
F_11 ( & V_37 -> V_33 , (struct V_34 * ) & V_13 -> V_22 . V_33 . V_45 ) ;
V_40 = 0 ;
V_42:
return V_40 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_46 , V_24 ) ;
}
static void T_2 F_21 ( void )
{
int V_40 ;
V_40 = F_22 ( & V_46 , V_24 ) ;
F_10 ( V_40 ) ;
}
