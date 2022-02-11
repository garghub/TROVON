static void F_1 ( unsigned V_1 , int V_2 )
{
void T_1 * V_3 = V_4 ;
if ( V_2 )
F_2 ( 1 << V_1 , V_3 + V_5 ) ;
else
F_2 ( 1 << V_1 , V_3 + V_6 ) ;
}
static int F_3 ( unsigned V_1 )
{
return ( F_4 ( V_4 + V_7 ) >> V_1 ) & 1 ;
}
static int F_5 ( struct V_8 * V_9 , unsigned V_10 )
{
return F_3 ( V_10 ) ;
}
static void F_6 ( struct V_8 * V_9 ,
unsigned V_10 , int V_2 )
{
F_1 ( V_10 , V_2 ) ;
}
static int F_7 ( struct V_8 * V_9 ,
unsigned V_10 )
{
void T_1 * V_3 = V_4 ;
unsigned long V_11 ;
F_8 ( & V_12 , V_11 ) ;
F_2 ( F_4 ( V_3 + V_13 ) & ~ ( 1 << V_10 ) ,
V_3 + V_13 ) ;
F_9 ( & V_12 , V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 ,
unsigned V_10 , int V_2 )
{
void T_1 * V_3 = V_4 ;
unsigned long V_11 ;
F_8 ( & V_12 , V_11 ) ;
if ( V_2 )
F_2 ( 1 << V_10 , V_3 + V_5 ) ;
else
F_2 ( 1 << V_10 , V_3 + V_6 ) ;
F_2 ( F_4 ( V_3 + V_13 ) | ( 1 << V_10 ) ,
V_3 + V_13 ) ;
F_9 ( & V_12 , V_11 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 , unsigned V_10 )
{
void T_1 * V_3 = V_4 ;
unsigned long V_11 ;
F_8 ( & V_12 , V_11 ) ;
F_2 ( F_4 ( V_3 + V_13 ) | ( 1 << V_10 ) ,
V_3 + V_13 ) ;
F_9 ( & V_12 , V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_8 * V_9 , unsigned V_10 ,
int V_2 )
{
void T_1 * V_3 = V_4 ;
unsigned long V_11 ;
F_8 ( & V_12 , V_11 ) ;
if ( V_2 )
F_2 ( 1 << V_10 , V_3 + V_5 ) ;
else
F_2 ( 1 << V_10 , V_3 + V_6 ) ;
F_2 ( F_4 ( V_3 + V_13 ) & ~ ( 1 << V_10 ) ,
V_3 + V_13 ) ;
F_9 ( & V_12 , V_11 ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 . V_19 ;
struct V_20 * V_21 = V_15 -> V_18 . V_22 ;
struct V_23 * V_24 ;
bool V_25 ;
int V_26 ;
if ( V_21 ) {
V_26 = F_14 ( V_21 , L_1 , & V_27 ) ;
if ( V_26 ) {
F_15 ( & V_15 -> V_18 , L_2 ) ;
return V_26 ;
}
if ( V_27 >= 32 ) {
F_15 ( & V_15 -> V_18 , L_3 ) ;
return - V_28 ;
}
V_25 = F_16 ( V_21 , L_4 ) ;
} else if ( V_17 ) {
V_27 = V_17 -> V_29 ;
V_25 = V_17 -> V_25 ;
} else {
F_15 ( & V_15 -> V_18 , L_5 ) ;
return - V_28 ;
}
V_24 = F_17 ( V_15 , V_30 , 0 ) ;
V_4 = F_18 (
& V_15 -> V_18 , V_24 -> V_31 , F_19 ( V_24 ) ) ;
if ( ! V_4 )
return - V_32 ;
V_33 . V_18 = & V_15 -> V_18 ;
V_33 . V_34 = V_27 ;
if ( V_25 ) {
V_33 . V_35 = F_11 ;
V_33 . V_36 = F_12 ;
}
V_26 = F_20 ( & V_33 ) ;
if ( V_26 ) {
F_15 ( & V_15 -> V_18 ,
L_6 , V_26 ) ;
return V_26 ;
}
return 0 ;
}
