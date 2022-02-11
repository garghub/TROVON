static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
F_3 ( V_6 , V_5 + V_7 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_9 ;
if ( V_10 [ V_8 ] == 0 )
V_8 ++ ;
V_4 -> V_2 . V_8 = V_8 ;
V_9 = F_5 ( V_5 + V_11 ) ;
V_9 &= ~ V_12 ;
V_9 |= F_6 ( V_10 [ V_8 ] ) ;
F_3 ( V_9 , V_5 + V_11 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
F_3 ( 0 , V_5 + V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_2 V_9 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
int V_13 ;
V_13 = F_4 ( & V_4 -> V_2 ,
V_4 -> V_2 . V_8 ) ;
if ( V_13 < 0 )
return V_13 ;
V_9 = F_5 ( V_5 + V_11 ) ;
V_9 |= ( V_14 | V_15 ) ;
F_3 ( V_9 , V_5 + V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_16 * V_17 )
{
struct V_3 * V_4 ;
struct V_18 * V_19 ;
int V_20 ;
V_4 = F_10 ( & V_17 -> V_21 , sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
F_11 ( V_17 , V_4 ) ;
V_19 = F_12 ( V_17 , V_24 , 0 ) ;
V_4 -> V_5 = F_13 ( & V_17 -> V_21 , V_19 ) ;
if ( F_14 ( V_4 -> V_5 ) )
return F_15 ( V_4 -> V_5 ) ;
V_4 -> V_2 . V_25 = & V_26 ;
V_4 -> V_2 . V_27 = & V_28 ;
V_4 -> V_2 . V_8 = V_29 ;
V_4 -> V_2 . V_30 = V_29 ;
V_4 -> V_2 . V_31 = V_32 ;
V_4 -> V_2 . V_33 = & V_17 -> V_21 ;
F_16 ( & V_4 -> V_2 , V_8 , & V_17 -> V_21 ) ;
F_17 ( & V_4 -> V_2 , V_34 ) ;
F_18 ( & V_4 -> V_2 , V_4 ) ;
F_7 ( & V_4 -> V_2 ) ;
V_20 = F_19 ( & V_4 -> V_2 ) ;
if ( F_20 ( V_20 ) )
return V_20 ;
F_21 ( & V_17 -> V_21 , L_1 ,
V_4 -> V_2 . V_8 , V_34 ) ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_23 ( V_17 ) ;
F_24 ( & V_4 -> V_2 ) ;
F_18 ( & V_4 -> V_2 , NULL ) ;
return 0 ;
}
static void F_25 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_23 ( V_17 ) ;
F_7 ( & V_4 -> V_2 ) ;
}
