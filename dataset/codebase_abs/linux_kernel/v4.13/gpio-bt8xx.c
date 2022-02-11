static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 , V_8 ;
F_3 ( & V_5 -> V_9 , V_6 ) ;
V_8 = F_4 ( V_10 ) ;
V_8 &= ~ ( 1 << V_3 ) ;
F_5 ( V_8 , V_10 ) ;
V_7 = F_4 ( V_11 ) ;
V_7 &= ~ ( 1 << V_3 ) ;
F_5 ( V_7 , V_11 ) ;
F_6 ( & V_5 -> V_9 , V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_12 ;
F_3 ( & V_5 -> V_9 , V_6 ) ;
V_12 = F_4 ( V_10 ) ;
F_6 ( & V_5 -> V_9 , V_6 ) ;
return ! ! ( V_12 & ( 1 << V_3 ) ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 , V_8 ;
F_3 ( & V_5 -> V_9 , V_6 ) ;
V_7 = F_4 ( V_11 ) ;
V_7 |= ( 1 << V_3 ) ;
F_5 ( V_7 , V_11 ) ;
V_8 = F_4 ( V_10 ) ;
if ( V_12 )
V_8 |= ( 1 << V_3 ) ;
else
V_8 &= ~ ( 1 << V_3 ) ;
F_5 ( V_8 , V_10 ) ;
F_6 ( & V_5 -> V_9 , V_6 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned V_3 , int V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_8 ;
F_3 ( & V_5 -> V_9 , V_6 ) ;
V_8 = F_4 ( V_10 ) ;
if ( V_12 )
V_8 |= ( 1 << V_3 ) ;
else
V_8 &= ~ ( 1 << V_3 ) ;
F_5 ( V_8 , V_10 ) ;
F_6 ( & V_5 -> V_9 , V_6 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_1 * V_13 = & V_5 -> V_2 ;
V_13 -> V_14 = F_11 ( & V_5 -> V_15 -> V_16 ) ;
V_13 -> V_17 = V_18 ;
V_13 -> V_19 = F_1 ;
V_13 -> V_20 = F_7 ;
V_13 -> V_21 = F_8 ;
V_13 -> V_22 = F_9 ;
V_13 -> V_23 = NULL ;
V_13 -> V_24 = V_25 ;
V_13 -> V_26 = V_27 ;
V_13 -> V_28 = false ;
}
static int F_12 ( struct V_29 * V_16 ,
const struct V_30 * V_31 )
{
struct V_4 * V_5 ;
int V_32 ;
V_5 = F_13 ( & V_16 -> V_16 , sizeof( struct V_4 ) , V_33 ) ;
if ( ! V_5 )
return - V_34 ;
V_5 -> V_15 = V_16 ;
F_14 ( & V_5 -> V_9 ) ;
V_32 = F_15 ( V_16 ) ;
if ( V_32 ) {
F_16 ( V_35 L_1 ) ;
return V_32 ;
}
if ( ! F_17 ( & V_16 -> V_16 , F_18 ( V_16 , 0 ) ,
F_19 ( V_16 , 0 ) ,
L_2 ) ) {
F_16 ( V_36 L_3 ,
( unsigned long long ) F_18 ( V_16 , 0 ) ) ;
V_32 = - V_37 ;
goto V_38;
}
F_20 ( V_16 ) ;
F_21 ( V_16 , V_5 ) ;
V_5 -> V_39 = F_22 ( & V_16 -> V_16 , F_18 ( V_16 , 0 ) , 0x1000 ) ;
if ( ! V_5 -> V_39 ) {
F_16 ( V_35 L_4 ) ;
V_32 = - V_40 ;
goto V_38;
}
F_5 ( 0 , V_41 ) ;
F_5 ( 0 , V_42 ) ;
F_5 ( 0 , V_43 ) ;
F_5 ( 0 , V_11 ) ;
F_10 ( V_5 ) ;
V_32 = F_23 ( & V_5 -> V_2 , V_5 ) ;
if ( V_32 ) {
F_16 ( V_35 L_5 ) ;
goto V_38;
}
return 0 ;
V_38:
F_24 ( V_16 ) ;
return V_32 ;
}
static void F_25 ( struct V_29 * V_15 )
{
struct V_4 * V_5 = F_26 ( V_15 ) ;
F_27 ( & V_5 -> V_2 ) ;
F_5 ( 0 , V_41 ) ;
F_5 ( ~ 0x0 , V_44 ) ;
F_5 ( 0x0 , V_11 ) ;
F_24 ( V_15 ) ;
}
static int F_28 ( struct V_29 * V_15 , T_2 V_45 )
{
struct V_4 * V_5 = F_26 ( V_15 ) ;
unsigned long V_6 ;
F_3 ( & V_5 -> V_9 , V_6 ) ;
V_5 -> V_46 = F_4 ( V_11 ) ;
V_5 -> V_47 = F_4 ( V_10 ) ;
F_5 ( 0 , V_41 ) ;
F_5 ( ~ 0x0 , V_44 ) ;
F_5 ( 0x0 , V_11 ) ;
F_6 ( & V_5 -> V_9 , V_6 ) ;
F_29 ( V_15 ) ;
F_24 ( V_15 ) ;
F_30 ( V_15 , F_31 ( V_15 , V_45 ) ) ;
return 0 ;
}
static int F_32 ( struct V_29 * V_15 )
{
struct V_4 * V_5 = F_26 ( V_15 ) ;
unsigned long V_6 ;
int V_32 ;
F_30 ( V_15 , V_48 ) ;
V_32 = F_15 ( V_15 ) ;
if ( V_32 )
return V_32 ;
F_33 ( V_15 ) ;
F_3 ( & V_5 -> V_9 , V_6 ) ;
F_5 ( 0 , V_41 ) ;
F_5 ( 0 , V_42 ) ;
F_5 ( 0 , V_43 ) ;
F_5 ( V_5 -> V_46 , V_11 ) ;
F_5 ( V_5 -> V_47 & V_5 -> V_46 ,
V_10 ) ;
F_6 ( & V_5 -> V_9 , V_6 ) ;
return 0 ;
}
