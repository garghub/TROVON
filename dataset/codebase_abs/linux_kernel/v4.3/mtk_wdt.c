static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 ;
void T_1 * V_7 ;
V_6 = F_2 ( V_2 , struct V_5 , V_8 ) ;
V_7 = V_6 -> V_7 ;
while ( 1 ) {
F_3 ( V_9 , V_7 + V_10 ) ;
F_4 ( 5 ) ;
}
return V_11 ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = F_6 ( V_13 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
F_7 ( V_14 , V_7 + V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_12 * V_13 ,
unsigned int V_16 )
{
struct V_5 * V_6 = F_6 ( V_13 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
T_2 V_17 ;
V_13 -> V_16 = V_16 ;
V_17 = F_9 ( V_16 << 6 ) | V_18 ;
F_7 ( V_17 , V_7 + V_19 ) ;
F_5 ( V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = F_6 ( V_13 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
T_2 V_17 ;
V_17 = F_11 ( V_7 + V_20 ) ;
V_17 &= ~ V_21 ;
F_7 ( V_17 , V_7 + V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 )
{
T_2 V_17 ;
struct V_5 * V_6 = F_6 ( V_13 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
int V_22 ;
V_22 = F_8 ( V_13 , V_13 -> V_16 ) ;
if ( V_22 < 0 )
return V_22 ;
V_17 = F_13 ( V_7 + V_20 ) ;
V_17 &= ~ ( V_23 | V_24 ) ;
V_17 |= ( V_21 | V_25 ) ;
F_7 ( V_17 , V_7 + V_20 ) ;
return 0 ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_5 * V_6 ;
struct V_28 * V_29 ;
int V_30 ;
V_6 = F_15 ( & V_27 -> V_31 , sizeof( * V_6 ) , V_32 ) ;
if ( ! V_6 )
return - V_33 ;
F_16 ( V_27 , V_6 ) ;
V_29 = F_17 ( V_27 , V_34 , 0 ) ;
V_6 -> V_7 = F_18 ( & V_27 -> V_31 , V_29 ) ;
if ( F_19 ( V_6 -> V_7 ) )
return F_20 ( V_6 -> V_7 ) ;
V_6 -> V_13 . V_35 = & V_36 ;
V_6 -> V_13 . V_37 = & V_38 ;
V_6 -> V_13 . V_16 = V_39 ;
V_6 -> V_13 . V_40 = V_39 ;
V_6 -> V_13 . V_41 = V_42 ;
V_6 -> V_13 . V_43 = & V_27 -> V_31 ;
F_21 ( & V_6 -> V_13 , V_16 , & V_27 -> V_31 ) ;
F_22 ( & V_6 -> V_13 , V_44 ) ;
F_23 ( & V_6 -> V_13 , V_6 ) ;
F_10 ( & V_6 -> V_13 ) ;
V_30 = F_24 ( & V_6 -> V_13 ) ;
if ( F_25 ( V_30 ) )
return V_30 ;
V_6 -> V_8 . V_45 = F_1 ;
V_6 -> V_8 . V_46 = 128 ;
V_30 = F_26 ( & V_6 -> V_8 ) ;
if ( V_30 )
F_27 ( & V_27 -> V_31 ,
L_1 , V_30 ) ;
F_28 ( & V_27 -> V_31 , L_2 ,
V_6 -> V_13 . V_16 , V_44 ) ;
return 0 ;
}
static void F_29 ( struct V_26 * V_27 )
{
struct V_5 * V_6 = F_30 ( V_27 ) ;
if ( F_31 ( & V_6 -> V_13 ) )
F_10 ( & V_6 -> V_13 ) ;
}
static int F_32 ( struct V_26 * V_27 )
{
struct V_5 * V_6 = F_30 ( V_27 ) ;
F_33 ( & V_6 -> V_8 ) ;
F_34 ( & V_6 -> V_13 ) ;
return 0 ;
}
static int F_35 ( struct V_47 * V_31 )
{
struct V_5 * V_6 = F_36 ( V_31 ) ;
if ( F_31 ( & V_6 -> V_13 ) )
F_10 ( & V_6 -> V_13 ) ;
return 0 ;
}
static int F_37 ( struct V_47 * V_31 )
{
struct V_5 * V_6 = F_36 ( V_31 ) ;
if ( F_31 ( & V_6 -> V_13 ) ) {
F_12 ( & V_6 -> V_13 ) ;
F_5 ( & V_6 -> V_13 ) ;
}
return 0 ;
}
