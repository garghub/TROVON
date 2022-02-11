static void T_1
F_1 ( struct V_1 * V_1 , char * * V_2 , struct V_3 * V_4 )
{
if ( V_1 -> V_5 . V_1 != V_6 ) {
V_1 -> V_5 . V_1 = V_6 ;
V_1 -> V_5 . V_7 = F_2 ( V_8 ) ;
V_1 -> V_9 . V_10 . V_11 = 0 ;
V_1 -> V_9 . V_10 . V_12 = V_13 ;
V_1 -> V_9 . V_10 . V_14 = 0x0100 ;
V_1 = F_3 ( V_1 ) ;
V_1 -> V_5 . V_1 = V_15 ;
V_1 -> V_5 . V_7 = F_2 ( V_16 ) ;
V_1 -> V_9 . V_17 . V_7 = 4096 ;
V_1 -> V_9 . V_17 . V_18 = V_19 ;
V_1 = F_3 ( V_1 ) ;
V_1 -> V_5 . V_1 = V_20 ;
V_1 -> V_5 . V_7 = 0 ;
}
}
static void T_1 F_4 ( void )
{
F_5 () ;
F_6 ( V_21 , F_7 ( V_21 ) ) ;
}
static void T_1 F_8 ( void )
{
V_22 = 0 ;
V_23 &= ~ ( V_24 | V_25 | V_26 | V_27 ) ;
V_28 = 0 ;
V_29 = 0 ;
V_30 = 0 ;
V_31 = 0 ;
V_32 = 0 ;
V_33 = 0 ;
if ( ! F_9 ( V_34 ) ) {
V_35 = 0 ;
V_36 = 0 ;
}
}
static void F_10 ( struct V_37 * V_38 ,
enum V_39 V_40 )
{
T_2 V_41 = F_11 ( V_42 ) ;
if ( V_40 != V_43 )
V_41 |= 0x1 ;
else
V_41 &= ~ 0x1 ;
F_12 ( V_41 , V_42 ) ;
}
static enum V_39 F_13 ( struct V_37 * V_38 )
{
T_2 V_41 = F_11 ( V_42 ) ;
return ( V_41 & 0x1 ) ? V_44 : V_43 ;
}
static int T_1 F_14 ( void )
{
struct V_37 * V_38 ;
int V_45 ;
if ( ! F_15 () )
return - V_46 ;
V_38 = F_16 ( sizeof( * V_38 ) , V_47 ) ;
if ( ! V_38 )
return - V_48 ;
V_38 -> V_49 = L_1 ;
V_38 -> V_50 = F_10 ;
V_38 -> V_51 = F_13 ;
V_38 -> V_52 = L_2 ;
V_45 = F_17 ( NULL , V_38 ) ;
if ( V_45 < 0 ) {
F_18 ( V_38 ) ;
return V_45 ;
}
return 0 ;
}
