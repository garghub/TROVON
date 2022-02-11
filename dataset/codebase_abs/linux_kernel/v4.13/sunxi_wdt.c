static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
const struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_11 ;
V_11 = F_3 ( V_7 + V_9 -> V_12 ) ;
V_11 &= ~ ( V_9 -> V_13 ) ;
V_11 |= V_9 -> V_14 ;
F_4 ( V_11 , V_7 + V_9 -> V_12 ) ;
V_11 = F_3 ( V_7 + V_9 -> V_15 ) ;
V_11 &= ~ ( V_16 << V_9 -> V_17 ) ;
V_11 |= V_18 ;
F_4 ( V_11 , V_7 + V_9 -> V_15 ) ;
F_4 ( V_19 , V_7 + V_9 -> V_20 ) ;
while ( 1 ) {
F_5 ( 5 ) ;
V_11 = F_3 ( V_7 + V_9 -> V_15 ) ;
V_11 |= V_18 ;
F_4 ( V_11 , V_7 + V_9 -> V_15 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
const struct V_8 * V_9 = V_6 -> V_10 ;
F_4 ( V_19 , V_7 + V_9 -> V_20 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
const struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_22 ;
if ( V_23 [ V_21 ] == 0 )
V_21 ++ ;
V_6 -> V_2 . V_21 = V_21 ;
V_22 = F_3 ( V_7 + V_9 -> V_15 ) ;
V_22 &= ~ ( V_16 << V_9 -> V_17 ) ;
V_22 |= V_23 [ V_21 ] << V_9 -> V_17 ;
F_4 ( V_22 , V_7 + V_9 -> V_15 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
const struct V_8 * V_9 = V_6 -> V_10 ;
F_4 ( 0 , V_7 + V_9 -> V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_2 V_22 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
const struct V_8 * V_9 = V_6 -> V_10 ;
int V_24 ;
V_24 = F_7 ( & V_6 -> V_2 ,
V_6 -> V_2 . V_21 ) ;
if ( V_24 < 0 )
return V_24 ;
V_22 = F_3 ( V_7 + V_9 -> V_12 ) ;
V_22 &= ~ ( V_9 -> V_13 ) ;
V_22 |= V_9 -> V_14 ;
F_4 ( V_22 , V_7 + V_9 -> V_12 ) ;
V_22 = F_3 ( V_7 + V_9 -> V_15 ) ;
V_22 |= V_18 ;
F_4 ( V_22 , V_7 + V_9 -> V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_25 * V_26 )
{
struct V_5 * V_6 ;
const struct V_27 * V_28 ;
struct V_29 * V_30 ;
int V_31 ;
V_6 = F_11 ( & V_26 -> V_32 , sizeof( * V_6 ) , V_33 ) ;
if ( ! V_6 )
return - V_34 ;
V_28 = F_12 ( V_35 , & V_26 -> V_32 ) ;
if ( ! V_28 )
return - V_36 ;
V_6 -> V_10 = V_28 -> V_4 ;
V_30 = F_13 ( V_26 , V_37 , 0 ) ;
V_6 -> V_7 = F_14 ( & V_26 -> V_32 , V_30 ) ;
if ( F_15 ( V_6 -> V_7 ) )
return F_16 ( V_6 -> V_7 ) ;
V_6 -> V_2 . V_38 = & V_39 ;
V_6 -> V_2 . V_40 = & V_41 ;
V_6 -> V_2 . V_21 = V_42 ;
V_6 -> V_2 . V_43 = V_42 ;
V_6 -> V_2 . V_44 = V_45 ;
V_6 -> V_2 . V_46 = & V_26 -> V_32 ;
F_17 ( & V_6 -> V_2 , V_21 , & V_26 -> V_32 ) ;
F_18 ( & V_6 -> V_2 , V_47 ) ;
F_19 ( & V_6 -> V_2 , 128 ) ;
F_20 ( & V_6 -> V_2 , V_6 ) ;
F_8 ( & V_6 -> V_2 ) ;
F_21 ( & V_6 -> V_2 ) ;
V_31 = F_22 ( & V_26 -> V_32 , & V_6 -> V_2 ) ;
if ( F_23 ( V_31 ) )
return V_31 ;
F_24 ( & V_26 -> V_32 , L_1 ,
V_6 -> V_2 . V_21 , V_47 ) ;
return 0 ;
}
