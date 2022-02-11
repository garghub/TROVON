static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 -> V_8 ) ;
struct V_9 V_10 ;
const unsigned long V_11 = 1000000 / 33 ;
short V_12 , V_13 ;
T_1 V_14 ;
if ( F_3 ( V_4 , V_4 -> V_15 , & V_10 , V_11 , 1 ) < 0 ) {
F_4 (KERN_ERR DRV_NAME L_1 ) ;
return;
}
V_12 = F_5 ( V_10 . V_16 - 1 , 0 , 15 ) |
( F_5 ( V_10 . V_17 - 1 , 0 , 15 ) << 4 ) ;
V_13 = F_5 ( V_10 . V_18 - 1 , 0 , 15 ) |
( F_5 ( V_10 . V_19 - 1 , 0 , 15 ) << 4 ) ;
if ( V_4 -> V_20 == 0 ) {
F_6 ( V_6 , V_21 , & V_14 ) ;
V_14 &= ~ 0x0F ;
V_14 |= F_5 ( V_10 . V_22 - 1 , 0 , 15 ) ;
F_7 ( V_6 , V_21 , V_14 ) ;
F_8 ( V_6 , V_23 , V_12 ) ;
F_8 ( V_6 , V_24 , V_12 ) ;
F_8 ( V_6 , V_25 , V_13 ) ;
} else {
F_6 ( V_6 , V_21 , & V_14 ) ;
V_14 &= ~ 0xF0 ;
V_14 |= ( F_5 ( V_10 . V_22 - 1 , 0 , 15 ) << 4 ) ;
F_7 ( V_6 , V_21 , V_14 ) ;
F_8 ( V_6 , V_26 , V_12 ) ;
F_8 ( V_6 , V_27 , V_12 ) ;
F_8 ( V_6 , V_28 , V_13 ) ;
}
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_29 = V_30 + V_2 -> V_31 ;
F_10 ( V_29 , 0x22 ) ;
F_10 ( V_4 -> V_32 - V_33 , 0x23 ) ;
F_10 ( V_34 , 0x22 ) ;
F_10 ( 0x50 , 0x23 ) ;
}
static int F_11 ( struct V_5 * V_6 , const struct V_35 * V_36 )
{
static const struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = V_42 ,
. V_43 = V_44 ,
. V_45 = & V_46
} ;
const struct V_37 * V_47 [] = { & V_38 , & V_48 } ;
if ( F_12 ( V_6 -> V_49 ) != 1 )
return - V_50 ;
return F_13 ( V_6 , V_47 , & V_51 , NULL , 0 ) ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_52 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_52 ) ;
}
