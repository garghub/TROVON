static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 ;
V_5 = V_4 -> V_5 ;
while ( 1 ) {
F_3 ( V_6 , V_5 + V_7 ) ;
F_4 ( 5 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
F_6 ( V_8 , V_5 + V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_11 ;
V_2 -> V_10 = V_10 ;
V_11 = F_8 ( V_10 << 6 ) | V_12 ;
F_6 ( V_11 , V_5 + V_13 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_11 ;
V_11 = F_10 ( V_5 + V_14 ) ;
V_11 &= ~ V_15 ;
V_11 |= V_16 ;
F_6 ( V_11 , V_5 + V_14 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_2 V_11 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
int V_17 ;
V_17 = F_7 ( V_2 , V_2 -> V_10 ) ;
if ( V_17 < 0 )
return V_17 ;
V_11 = F_12 ( V_5 + V_14 ) ;
V_11 &= ~ ( V_18 | V_19 ) ;
V_11 |= ( V_15 | V_16 ) ;
F_6 ( V_11 , V_5 + V_14 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_3 * V_4 ;
struct V_22 * V_23 ;
int V_24 ;
V_4 = F_14 ( & V_21 -> V_25 , sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
F_15 ( V_21 , V_4 ) ;
V_23 = F_16 ( V_21 , V_28 , 0 ) ;
V_4 -> V_5 = F_17 ( & V_21 -> V_25 , V_23 ) ;
if ( F_18 ( V_4 -> V_5 ) )
return F_19 ( V_4 -> V_5 ) ;
V_4 -> V_2 . V_29 = & V_30 ;
V_4 -> V_2 . V_31 = & V_32 ;
V_4 -> V_2 . V_10 = V_33 ;
V_4 -> V_2 . V_34 = V_33 ;
V_4 -> V_2 . V_35 = V_36 ;
V_4 -> V_2 . V_37 = & V_21 -> V_25 ;
F_20 ( & V_4 -> V_2 , V_10 , & V_21 -> V_25 ) ;
F_21 ( & V_4 -> V_2 , V_38 ) ;
F_22 ( & V_4 -> V_2 , 128 ) ;
F_23 ( & V_4 -> V_2 , V_4 ) ;
F_9 ( & V_4 -> V_2 ) ;
V_24 = F_24 ( & V_4 -> V_2 ) ;
if ( F_25 ( V_24 ) )
return V_24 ;
F_26 ( & V_21 -> V_25 , L_1 ,
V_4 -> V_2 . V_10 , V_38 ) ;
return 0 ;
}
static void F_27 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_28 ( V_21 ) ;
if ( F_29 ( & V_4 -> V_2 ) )
F_9 ( & V_4 -> V_2 ) ;
}
static int F_30 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_28 ( V_21 ) ;
F_31 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_39 * V_25 )
{
struct V_3 * V_4 = F_33 ( V_25 ) ;
if ( F_29 ( & V_4 -> V_2 ) )
F_9 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_39 * V_25 )
{
struct V_3 * V_4 = F_33 ( V_25 ) ;
if ( F_29 ( & V_4 -> V_2 ) ) {
F_11 ( & V_4 -> V_2 ) ;
F_5 ( & V_4 -> V_2 ) ;
}
return 0 ;
}
