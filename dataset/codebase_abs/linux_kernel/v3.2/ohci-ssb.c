static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) ( V_3 -> V_4 ) ;
}
static int F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
int V_8 ;
F_3 ( V_7 ) ;
V_8 = F_4 ( V_7 ) ;
return V_8 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
int V_8 ;
V_8 = F_6 ( V_7 ) ;
if ( V_8 < 0 ) {
F_7 ( V_7 , L_1 ) ;
F_8 ( V_3 ) ;
}
return V_8 ;
}
static void F_9 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_10 ( V_10 ) ;
if ( V_3 -> V_11 -> V_12 )
V_3 -> V_11 -> V_12 ( V_3 ) ;
F_11 ( V_3 ) ;
F_12 ( V_3 -> V_13 ) ;
F_13 ( V_3 -> V_14 , V_3 -> V_15 ) ;
F_14 ( V_3 ) ;
F_15 ( V_10 , 0 ) ;
}
static int F_16 ( struct V_9 * V_10 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
int V_8 = - V_16 ;
T_1 V_17 , V_18 = 0 ;
if ( F_17 ( V_10 -> V_19 , F_18 ( 32 ) ) ||
F_19 ( V_10 -> V_19 , F_18 ( 32 ) ) )
return - V_20 ;
if ( V_10 -> V_21 . V_22 == V_23 ) {
V_18 |= V_24 ;
F_20 ( V_10 , V_18 ) ;
} else if ( V_10 -> V_21 . V_22 == V_25 ) {
F_20 ( V_10 , 0 ) ;
F_21 ( V_10 , 0x200 , 0x7ff ) ;
V_17 = F_22 ( V_10 , 0x400 ) ;
V_17 &= ~ 8 ;
F_21 ( V_10 , 0x400 , V_17 ) ;
V_17 = F_22 ( V_10 , 0x400 ) ;
V_17 = F_22 ( V_10 , 0x304 ) ;
V_17 &= ~ 0x100 ;
F_21 ( V_10 , 0x304 , V_17 ) ;
V_17 = F_22 ( V_10 , 0x304 ) ;
F_23 ( 1 ) ;
if ( V_10 -> V_21 . V_26 == 2 && V_10 -> V_27 -> V_28 == 0x5354 ) {
V_17 = 0x00fe00fe ;
F_21 ( V_10 , 0x894 , V_17 ) ;
V_17 = F_22 ( V_10 , 0x89c ) ;
V_17 |= 0x1 ;
F_21 ( V_10 , 0x89c , V_17 ) ;
}
} else
F_20 ( V_10 , 0 ) ;
V_3 = F_24 ( & V_29 , V_10 -> V_10 ,
F_25 ( V_10 -> V_10 ) ) ;
if ( ! V_3 )
goto V_30;
V_5 = F_1 ( V_3 ) ;
V_5 -> V_31 = V_18 ;
V_17 = F_22 ( V_10 , V_32 ) ;
V_3 -> V_14 = F_26 ( V_17 ) ;
V_3 -> V_15 = F_27 ( V_17 ) ;
V_3 -> V_13 = F_28 ( V_3 -> V_14 , V_3 -> V_15 ) ;
if ( ! V_3 -> V_13 )
goto V_33;
V_8 = F_29 ( V_3 , V_10 -> V_34 , V_35 ) ;
if ( V_8 )
goto V_36;
F_30 ( V_10 , V_3 ) ;
return V_8 ;
V_36:
F_12 ( V_3 -> V_13 ) ;
V_33:
F_14 ( V_3 ) ;
V_30:
F_15 ( V_10 , V_18 ) ;
return V_8 ;
}
static int F_31 ( struct V_9 * V_10 ,
const struct V_37 * V_21 )
{
int V_8 ;
T_2 V_38 ;
V_38 = ( V_10 -> V_27 -> V_28 & 0xFF00 ) ;
if ( V_38 != 0x4700 && V_38 != 0x5300 )
return - V_39 ;
if ( F_32 () )
return - V_39 ;
V_8 = F_16 ( V_10 ) ;
return V_8 ;
}
static void F_33 ( struct V_9 * V_10 )
{
F_9 ( V_10 ) ;
}
static int F_34 ( struct V_9 * V_10 , T_3 V_40 )
{
F_15 ( V_10 , 0 ) ;
return 0 ;
}
static int F_35 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_10 ( V_10 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_20 ( V_10 , V_5 -> V_31 ) ;
F_36 ( V_3 ) ;
return 0 ;
}
