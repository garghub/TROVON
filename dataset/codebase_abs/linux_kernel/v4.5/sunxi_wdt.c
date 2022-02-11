static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
const struct V_6 * V_7 = V_4 -> V_8 ;
T_2 V_9 ;
V_9 = F_3 ( V_5 + V_7 -> V_10 ) ;
V_9 &= ~ ( V_7 -> V_11 ) ;
V_9 |= V_7 -> V_12 ;
F_4 ( V_9 , V_5 + V_7 -> V_10 ) ;
V_9 = F_3 ( V_5 + V_7 -> V_13 ) ;
V_9 &= ~ ( V_14 << V_7 -> V_15 ) ;
V_9 |= V_16 ;
F_4 ( V_9 , V_5 + V_7 -> V_13 ) ;
F_4 ( V_17 , V_5 + V_7 -> V_18 ) ;
while ( 1 ) {
F_5 ( 5 ) ;
V_9 = F_3 ( V_5 + V_7 -> V_13 ) ;
V_9 |= V_16 ;
F_4 ( V_9 , V_5 + V_7 -> V_13 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
const struct V_6 * V_7 = V_4 -> V_8 ;
F_4 ( V_17 , V_5 + V_7 -> V_18 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
const struct V_6 * V_7 = V_4 -> V_8 ;
T_2 V_20 ;
if ( V_21 [ V_19 ] == 0 )
V_19 ++ ;
V_4 -> V_2 . V_19 = V_19 ;
V_20 = F_3 ( V_5 + V_7 -> V_13 ) ;
V_20 &= ~ ( V_14 << V_7 -> V_15 ) ;
V_20 |= V_21 [ V_19 ] << V_7 -> V_15 ;
F_4 ( V_20 , V_5 + V_7 -> V_13 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
const struct V_6 * V_7 = V_4 -> V_8 ;
F_4 ( 0 , V_5 + V_7 -> V_13 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_2 V_20 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
const struct V_6 * V_7 = V_4 -> V_8 ;
int V_22 ;
V_22 = F_7 ( & V_4 -> V_2 ,
V_4 -> V_2 . V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
V_20 = F_3 ( V_5 + V_7 -> V_10 ) ;
V_20 &= ~ ( V_7 -> V_11 ) ;
V_20 |= V_7 -> V_12 ;
F_4 ( V_20 , V_5 + V_7 -> V_10 ) ;
V_20 = F_3 ( V_5 + V_7 -> V_13 ) ;
V_20 |= V_16 ;
F_4 ( V_20 , V_5 + V_7 -> V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_23 * V_24 )
{
struct V_3 * V_4 ;
const struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_29 ;
V_4 = F_11 ( & V_24 -> V_30 , sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
return - V_32 ;
F_12 ( V_24 , V_4 ) ;
V_26 = F_13 ( V_33 , & V_24 -> V_30 ) ;
if ( ! V_26 )
return - V_34 ;
V_4 -> V_8 = V_26 -> V_35 ;
V_28 = F_14 ( V_24 , V_36 , 0 ) ;
V_4 -> V_5 = F_15 ( & V_24 -> V_30 , V_28 ) ;
if ( F_16 ( V_4 -> V_5 ) )
return F_17 ( V_4 -> V_5 ) ;
V_4 -> V_2 . V_37 = & V_38 ;
V_4 -> V_2 . V_39 = & V_40 ;
V_4 -> V_2 . V_19 = V_41 ;
V_4 -> V_2 . V_42 = V_41 ;
V_4 -> V_2 . V_43 = V_44 ;
V_4 -> V_2 . V_45 = & V_24 -> V_30 ;
F_18 ( & V_4 -> V_2 , V_19 , & V_24 -> V_30 ) ;
F_19 ( & V_4 -> V_2 , V_46 ) ;
F_20 ( & V_4 -> V_2 , 128 ) ;
F_21 ( & V_4 -> V_2 , V_4 ) ;
F_8 ( & V_4 -> V_2 ) ;
V_29 = F_22 ( & V_4 -> V_2 ) ;
if ( F_23 ( V_29 ) )
return V_29 ;
F_24 ( & V_24 -> V_30 , L_1 ,
V_4 -> V_2 . V_19 , V_46 ) ;
return 0 ;
}
static int F_25 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_26 ( V_24 ) ;
F_27 ( & V_4 -> V_2 ) ;
F_21 ( & V_4 -> V_2 , NULL ) ;
return 0 ;
}
static void F_28 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_26 ( V_24 ) ;
F_8 ( & V_4 -> V_2 ) ;
}
