static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_8 ) ;
void T_1 * V_9 = V_5 -> V_9 + V_7 -> V_10 ;
return ! ! ( F_4 ( V_9 + V_11 ) & F_5 ( V_3 ) ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_3 , int V_12 )
{
unsigned long V_13 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_8 ) ;
void T_1 * V_9 = V_5 -> V_9 ;
F_7 ( & V_7 -> V_14 , V_13 ) ;
if ( V_12 )
V_7 -> V_15 |= F_5 ( V_3 ) ;
else
V_7 -> V_15 &= ~ F_5 ( V_3 ) ;
F_8 ( V_9 + V_7 -> V_10 + V_11 ,
V_7 -> V_15 ) ;
F_9 ( & V_7 -> V_14 , V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_13 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_8 ) ;
void T_1 * V_9 = V_5 -> V_9 ;
F_7 ( & V_7 -> V_14 , V_13 ) ;
V_7 -> V_16 |= F_5 ( V_3 ) ;
F_8 ( V_9 + V_7 -> V_10 + V_17 , V_7 -> V_16 ) ;
F_9 ( & V_7 -> V_14 , V_13 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_3 , int V_12 )
{
unsigned long V_13 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_8 ) ;
void T_1 * V_9 = V_5 -> V_9 ;
F_7 ( & V_7 -> V_14 , V_13 ) ;
if ( V_12 )
V_7 -> V_15 |= F_5 ( V_3 ) ;
else
V_7 -> V_15 &= ~ F_5 ( V_3 ) ;
F_8 ( V_9 + V_7 -> V_10 + V_11 ,
V_7 -> V_15 ) ;
V_7 -> V_16 &= ~ F_5 ( V_3 ) ;
F_8 ( V_9 + V_7 -> V_10 + V_17 , V_7 -> V_16 ) ;
F_9 ( & V_7 -> V_14 , V_13 ) ;
return 0 ;
}
static void F_12 ( struct V_4 * V_5 )
{
struct V_6 * V_7 =
F_3 ( V_5 , struct V_6 , V_8 ) ;
F_8 ( V_5 -> V_9 + V_7 -> V_10 + V_11 ,
V_7 -> V_15 ) ;
F_8 ( V_5 -> V_9 + V_7 -> V_10 + V_17 ,
V_7 -> V_16 ) ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_6 * V_7 ;
int V_20 = 0 ;
const T_2 * V_21 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_22 ) ;
if ( ! V_7 )
return - V_23 ;
F_15 ( V_19 , L_1 , & V_7 -> V_15 ) ;
V_7 -> V_16 = 0xFFFFFFFF ;
F_15 ( V_19 , L_2 , & V_7 -> V_16 ) ;
V_7 -> V_8 . V_2 . V_24 = 32 ;
F_15 ( V_19 , L_3 ,
( T_2 * ) & V_7 -> V_8 . V_2 . V_24 ) ;
F_16 ( & V_7 -> V_14 ) ;
V_7 -> V_8 . V_2 . V_25 = F_10 ;
V_7 -> V_8 . V_2 . V_26 = F_11 ;
V_7 -> V_8 . V_2 . V_27 = F_1 ;
V_7 -> V_8 . V_2 . V_28 = F_6 ;
V_7 -> V_8 . V_29 = F_12 ;
V_20 = F_17 ( V_19 , & V_7 -> V_8 ) ;
if ( V_20 ) {
F_18 ( V_7 ) ;
F_19 ( L_4 ,
V_19 -> V_30 , V_20 ) ;
return V_20 ;
}
F_20 ( L_5 , V_19 -> V_30 ,
V_7 -> V_8 . V_2 . V_31 ) ;
V_21 = F_21 ( V_19 , L_6 , NULL ) ;
if ( V_21 && F_22 ( V_21 ) ) {
V_7 = F_14 ( sizeof( * V_7 ) , V_22 ) ;
if ( ! V_7 )
return - V_23 ;
V_7 -> V_10 = V_32 ;
F_15 ( V_19 , L_7 ,
& V_7 -> V_15 ) ;
V_7 -> V_16 = 0xFFFFFFFF ;
F_15 ( V_19 , L_8 , & V_7 -> V_16 ) ;
V_7 -> V_8 . V_2 . V_24 = 32 ;
F_15 ( V_19 , L_9 ,
( T_2 * ) & V_7 -> V_8 . V_2 . V_24 ) ;
F_16 ( & V_7 -> V_14 ) ;
V_7 -> V_8 . V_2 . V_25 = F_10 ;
V_7 -> V_8 . V_2 . V_26 = F_11 ;
V_7 -> V_8 . V_2 . V_27 = F_1 ;
V_7 -> V_8 . V_2 . V_28 = F_6 ;
V_7 -> V_8 . V_29 = F_12 ;
V_20 = F_17 ( V_19 , & V_7 -> V_8 ) ;
if ( V_20 ) {
F_18 ( V_7 ) ;
F_19 ( L_4 ,
V_19 -> V_30 , V_20 ) ;
return V_20 ;
}
F_20 ( L_10 ,
V_19 -> V_30 , V_7 -> V_8 . V_2 . V_31 ) ;
}
return 0 ;
}
static int T_3 F_23 ( void )
{
struct V_18 * V_19 ;
F_24 (np, xgpio_of_match)
F_13 ( V_19 ) ;
return 0 ;
}
