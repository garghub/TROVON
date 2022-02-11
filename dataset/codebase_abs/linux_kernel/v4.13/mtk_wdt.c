static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 ;
V_7 = V_6 -> V_7 ;
while ( 1 ) {
F_3 ( V_8 , V_7 + V_9 ) ;
F_4 ( 5 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
F_6 ( V_10 , V_7 + V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
T_2 V_13 ;
V_2 -> V_12 = V_12 ;
V_13 = F_8 ( V_12 << 6 ) | V_14 ;
F_6 ( V_13 , V_7 + V_15 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
T_2 V_13 ;
V_13 = F_10 ( V_7 + V_16 ) ;
V_13 &= ~ V_17 ;
V_13 |= V_18 ;
F_6 ( V_13 , V_7 + V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_2 V_13 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
int V_19 ;
V_19 = F_7 ( V_2 , V_2 -> V_12 ) ;
if ( V_19 < 0 )
return V_19 ;
V_13 = F_12 ( V_7 + V_16 ) ;
V_13 &= ~ ( V_20 | V_21 ) ;
V_13 |= ( V_17 | V_18 ) ;
F_6 ( V_13 , V_7 + V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_5 * V_6 ;
struct V_24 * V_25 ;
int V_26 ;
V_6 = F_14 ( & V_23 -> V_27 , sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 )
return - V_29 ;
F_15 ( V_23 , V_6 ) ;
V_25 = F_16 ( V_23 , V_30 , 0 ) ;
V_6 -> V_7 = F_17 ( & V_23 -> V_27 , V_25 ) ;
if ( F_18 ( V_6 -> V_7 ) )
return F_19 ( V_6 -> V_7 ) ;
V_6 -> V_2 . V_31 = & V_32 ;
V_6 -> V_2 . V_33 = & V_34 ;
V_6 -> V_2 . V_12 = V_35 ;
V_6 -> V_2 . V_36 = V_35 ;
V_6 -> V_2 . V_37 = V_38 ;
V_6 -> V_2 . V_39 = & V_23 -> V_27 ;
F_20 ( & V_6 -> V_2 , V_12 , & V_23 -> V_27 ) ;
F_21 ( & V_6 -> V_2 , V_40 ) ;
F_22 ( & V_6 -> V_2 , 128 ) ;
F_23 ( & V_6 -> V_2 , V_6 ) ;
F_9 ( & V_6 -> V_2 ) ;
V_26 = F_24 ( & V_6 -> V_2 ) ;
if ( F_25 ( V_26 ) )
return V_26 ;
F_26 ( & V_23 -> V_27 , L_1 ,
V_6 -> V_2 . V_12 , V_40 ) ;
return 0 ;
}
static void F_27 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = F_28 ( V_23 ) ;
if ( F_29 ( & V_6 -> V_2 ) )
F_9 ( & V_6 -> V_2 ) ;
}
static int F_30 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = F_28 ( V_23 ) ;
F_31 ( & V_6 -> V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_41 * V_27 )
{
struct V_5 * V_6 = F_33 ( V_27 ) ;
if ( F_29 ( & V_6 -> V_2 ) )
F_9 ( & V_6 -> V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_41 * V_27 )
{
struct V_5 * V_6 = F_33 ( V_27 ) ;
if ( F_29 ( & V_6 -> V_2 ) ) {
F_11 ( & V_6 -> V_2 ) ;
F_5 ( & V_6 -> V_2 ) ;
}
return 0 ;
}
