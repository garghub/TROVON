static void F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
F_2 ( V_4 L_1 , V_3 ) ;
V_5 . V_6 = V_3 ;
F_3 () ;
}
static unsigned char F_4 ( struct V_1 * V_2 )
{
return V_5 . V_6 ;
}
static unsigned char F_5 ( unsigned char V_7 )
{
return V_8 |
V_9 | V_10 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned char V_7 )
{
F_2 ( V_4 L_2 , V_7 ) ;
}
static unsigned char F_7 ( struct V_1 * V_2 )
{
F_2 ( V_4 L_3 ) ;
return F_5 ( 0 ) ;
}
static unsigned char F_8 ( struct V_1 * V_2 , unsigned char V_11 , unsigned char V_12 )
{
unsigned char V_13 ;
F_2 ( V_4 L_4 , V_11 , V_12 ) ;
V_13 = F_7 ( V_2 ) ;
F_6 ( V_2 , ( V_13 & ~ V_11 ) ^ V_12 ) ;
return V_13 ;
}
static unsigned char F_9 ( unsigned char V_14 )
{
unsigned char V_15 = V_16 | V_17 | V_18 ;
if ( V_14 & 1 )
V_15 &= ~ V_16 ;
if ( V_14 & 2 )
V_15 |= V_19 ;
if ( V_14 & 4 )
V_15 |= V_20 ;
return V_15 ;
}
static unsigned char F_10 ( struct V_1 * V_2 )
{
unsigned char V_14 ;
V_14 = F_9 ( V_21 . V_22 & 7 ) ;
F_2 ( V_4 L_5 , V_14 ) ;
return V_14 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_23 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_23 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_2 ( V_4 L_6 ) ;
V_5 . V_24 = 0xff ;
F_3 () ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_2 ( V_4 L_7 ) ;
V_5 . V_24 = 0 ;
F_3 () ;
}
static void F_17 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
V_28 -> V_29 . V_30 . V_3 = 0 ;
V_28 -> V_29 . V_30 . V_31 = 255 ;
V_28 -> V_29 . V_30 . V_14 = 0 ;
V_28 -> V_29 . V_30 . V_32 = 0 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
F_3 () ;
V_28 -> V_29 . V_30 . V_3 = V_5 . V_6 ;
V_28 -> V_29 . V_30 . V_31 = V_5 . V_24 ;
V_28 -> V_29 . V_30 . V_14 = V_21 . V_22 & 7 ;
V_28 -> V_29 . V_30 . V_32 = V_21 . V_33 & 7 ;
F_3 () ;
}
static void F_19 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
F_3 () ;
V_5 . V_6 = V_28 -> V_29 . V_30 . V_3 ;
V_5 . V_24 = V_28 -> V_29 . V_30 . V_31 ;
V_21 . V_22 |= ( V_21 . V_22 & 0xf8 ) | V_28 -> V_29 . V_30 . V_14 ;
V_21 . V_33 |= ( V_21 . V_33 & 0xf8 ) | V_28 -> V_29 . V_30 . V_32 ;
F_3 () ;
}
static int T_1 F_20 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
int V_36 ;
V_5 . V_24 = 0xff ;
V_21 . V_33 &= 0xf8 ;
F_3 () ;
V_2 = F_21 ( ( unsigned long ) & V_5 . V_6 , V_23 ,
V_37 , & V_38 ) ;
if ( ! V_2 )
return - V_39 ;
V_36 = F_22 ( V_23 , V_40 , 0 , V_2 -> V_41 ,
V_2 ) ;
if ( V_36 )
goto V_42;
F_23 ( V_43 L_8 , V_2 -> V_41 ) ;
F_24 ( V_2 ) ;
F_25 ( V_35 , V_2 ) ;
return 0 ;
V_42:
F_26 ( V_2 ) ;
return V_36 ;
}
static int T_2 F_27 ( struct V_34 * V_35 )
{
struct V_1 * V_44 = F_28 ( V_35 ) ;
F_29 ( V_44 ) ;
if ( V_44 -> V_45 != V_46 )
F_30 ( V_23 , V_44 ) ;
F_26 ( V_44 ) ;
return 0 ;
}
