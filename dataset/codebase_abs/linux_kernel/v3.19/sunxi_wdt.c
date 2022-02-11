static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 ,
V_7 ) ;
void T_1 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_11 ;
T_2 V_12 ;
V_12 = F_3 ( V_8 + V_10 -> V_13 ) ;
V_12 &= ~ ( V_10 -> V_14 ) ;
V_12 |= V_10 -> V_15 ;
F_4 ( V_12 , V_8 + V_10 -> V_13 ) ;
V_12 = F_3 ( V_8 + V_10 -> V_16 ) ;
V_12 &= ~ ( V_17 << V_10 -> V_18 ) ;
V_12 |= V_19 ;
F_4 ( V_12 , V_8 + V_10 -> V_16 ) ;
F_4 ( V_20 , V_8 + V_10 -> V_21 ) ;
while ( 1 ) {
F_5 ( 5 ) ;
V_12 = F_3 ( V_8 + V_10 -> V_16 ) ;
V_12 |= V_19 ;
F_4 ( V_12 , V_8 + V_10 -> V_16 ) ;
}
return V_22 ;
}
static int F_6 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_7 ( V_24 ) ;
void T_1 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_11 ;
F_4 ( V_20 , V_8 + V_10 -> V_21 ) ;
return 0 ;
}
static int F_8 ( struct V_23 * V_24 ,
unsigned int V_25 )
{
struct V_5 * V_6 = F_7 ( V_24 ) ;
void T_1 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_11 ;
T_2 V_26 ;
if ( V_27 [ V_25 ] == 0 )
V_25 ++ ;
V_6 -> V_24 . V_25 = V_25 ;
V_26 = F_3 ( V_8 + V_10 -> V_16 ) ;
V_26 &= ~ ( V_17 << V_10 -> V_18 ) ;
V_26 |= V_27 [ V_25 ] << V_10 -> V_18 ;
F_4 ( V_26 , V_8 + V_10 -> V_16 ) ;
F_6 ( V_24 ) ;
return 0 ;
}
static int F_9 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_7 ( V_24 ) ;
void T_1 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_11 ;
F_4 ( 0 , V_8 + V_10 -> V_16 ) ;
return 0 ;
}
static int F_10 ( struct V_23 * V_24 )
{
T_2 V_26 ;
struct V_5 * V_6 = F_7 ( V_24 ) ;
void T_1 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_11 ;
int V_28 ;
V_28 = F_8 ( & V_6 -> V_24 ,
V_6 -> V_24 . V_25 ) ;
if ( V_28 < 0 )
return V_28 ;
V_26 = F_3 ( V_8 + V_10 -> V_13 ) ;
V_26 &= ~ ( V_10 -> V_14 ) ;
V_26 |= ~ ( V_10 -> V_15 ) ;
F_4 ( V_26 , V_8 + V_10 -> V_13 ) ;
V_26 = F_3 ( V_8 + V_10 -> V_16 ) ;
V_26 |= V_19 ;
F_4 ( V_26 , V_8 + V_10 -> V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_29 * V_30 )
{
struct V_5 * V_6 ;
const struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_35 ;
V_6 = F_12 ( & V_30 -> V_36 , sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 )
return - V_38 ;
F_13 ( V_30 , V_6 ) ;
V_32 = F_14 ( V_39 , & V_30 -> V_36 ) ;
if ( ! V_32 )
return - V_40 ;
V_6 -> V_11 = V_32 -> V_41 ;
V_34 = F_15 ( V_30 , V_42 , 0 ) ;
V_6 -> V_8 = F_16 ( & V_30 -> V_36 , V_34 ) ;
if ( F_17 ( V_6 -> V_8 ) )
return F_18 ( V_6 -> V_8 ) ;
V_6 -> V_24 . V_43 = & V_44 ;
V_6 -> V_24 . V_45 = & V_46 ;
V_6 -> V_24 . V_25 = V_47 ;
V_6 -> V_24 . V_48 = V_47 ;
V_6 -> V_24 . V_49 = V_50 ;
V_6 -> V_24 . V_51 = & V_30 -> V_36 ;
F_19 ( & V_6 -> V_24 , V_25 , & V_30 -> V_36 ) ;
F_20 ( & V_6 -> V_24 , V_52 ) ;
F_21 ( & V_6 -> V_24 , V_6 ) ;
F_9 ( & V_6 -> V_24 ) ;
V_35 = F_22 ( & V_6 -> V_24 ) ;
if ( F_23 ( V_35 ) )
return V_35 ;
V_6 -> V_7 . V_53 = F_1 ;
V_6 -> V_7 . V_54 = 128 ;
V_35 = F_24 ( & V_6 -> V_7 ) ;
if ( V_35 )
F_25 ( & V_30 -> V_36 ,
L_1 , V_35 ) ;
F_26 ( & V_30 -> V_36 , L_2 ,
V_6 -> V_24 . V_25 , V_52 ) ;
return 0 ;
}
static int F_27 ( struct V_29 * V_30 )
{
struct V_5 * V_6 = F_28 ( V_30 ) ;
F_29 ( & V_6 -> V_7 ) ;
F_30 ( & V_6 -> V_24 ) ;
F_21 ( & V_6 -> V_24 , NULL ) ;
return 0 ;
}
static void F_31 ( struct V_29 * V_30 )
{
struct V_5 * V_6 = F_28 ( V_30 ) ;
F_9 ( & V_6 -> V_24 ) ;
}
