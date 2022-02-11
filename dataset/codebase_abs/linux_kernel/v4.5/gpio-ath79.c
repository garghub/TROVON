static void F_1 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_4 )
F_3 ( F_4 ( V_3 ) , V_6 -> V_7 + V_8 ) ;
else
F_3 ( F_4 ( V_3 ) , V_6 -> V_7 + V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ( F_6 ( V_6 -> V_7 + V_10 ) >> V_3 ) & 1 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
F_8 ( & V_6 -> V_13 , V_12 ) ;
F_3 (
F_6 ( V_6 -> V_7 + V_14 ) & ~ F_4 ( V_11 ) ,
V_6 -> V_7 + V_14 ) ;
F_9 ( & V_6 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_11 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
F_8 ( & V_6 -> V_13 , V_12 ) ;
if ( V_4 )
F_3 ( F_4 ( V_11 ) , V_6 -> V_7 + V_8 ) ;
else
F_3 ( F_4 ( V_11 ) , V_6 -> V_7 + V_9 ) ;
F_3 (
F_6 ( V_6 -> V_7 + V_14 ) | F_4 ( V_11 ) ,
V_6 -> V_7 + V_14 ) ;
F_9 ( & V_6 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
F_8 ( & V_6 -> V_13 , V_12 ) ;
F_3 (
F_6 ( V_6 -> V_7 + V_14 ) | F_4 ( V_11 ) ,
V_6 -> V_7 + V_14 ) ;
F_9 ( & V_6 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_11 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_12 ;
F_8 ( & V_6 -> V_13 , V_12 ) ;
if ( V_4 )
F_3 ( F_4 ( V_11 ) , V_6 -> V_7 + V_8 ) ;
else
F_3 ( F_4 ( V_11 ) , V_6 -> V_7 + V_9 ) ;
F_3 (
F_6 ( V_6 -> V_7 + V_14 ) & ~ F_4 ( V_11 ) ,
V_6 -> V_7 + V_14 ) ;
F_9 ( & V_6 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_14 ( & V_16 -> V_19 ) ;
struct V_20 * V_21 = V_16 -> V_19 . V_22 ;
struct V_5 * V_6 ;
struct V_23 * V_24 ;
T_1 V_25 ;
bool V_26 ;
int V_27 ;
V_6 = F_15 ( & V_16 -> V_19 , sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 )
return - V_29 ;
if ( V_21 ) {
V_27 = F_16 ( V_21 , L_1 , & V_25 ) ;
if ( V_27 ) {
F_17 ( & V_16 -> V_19 , L_2 ) ;
return V_27 ;
}
if ( V_25 >= 32 ) {
F_17 ( & V_16 -> V_19 , L_3 ) ;
return - V_30 ;
}
V_26 = F_18 ( V_21 , L_4 ) ;
} else if ( V_18 ) {
V_25 = V_18 -> V_31 ;
V_26 = V_18 -> V_26 ;
} else {
F_17 ( & V_16 -> V_19 , L_5 ) ;
return - V_30 ;
}
V_24 = F_19 ( V_16 , V_32 , 0 ) ;
V_6 -> V_7 = F_20 (
& V_16 -> V_19 , V_24 -> V_33 , F_21 ( V_24 ) ) ;
if ( ! V_6 -> V_7 )
return - V_29 ;
F_22 ( & V_6 -> V_13 ) ;
memcpy ( & V_6 -> V_2 , & V_34 , sizeof( V_6 -> V_2 ) ) ;
V_6 -> V_2 . V_35 = & V_16 -> V_19 ;
V_6 -> V_2 . V_36 = V_25 ;
if ( V_26 ) {
V_6 -> V_2 . V_37 = F_11 ;
V_6 -> V_2 . V_38 = F_12 ;
}
V_27 = F_23 ( & V_6 -> V_2 , V_6 ) ;
if ( V_27 ) {
F_17 ( & V_16 -> V_19 ,
L_6 , V_27 ) ;
return V_27 ;
}
return 0 ;
}
