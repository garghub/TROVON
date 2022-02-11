static
int F_1 ( struct V_1 * V_1 ,
bool V_2 )
{
int V_3 = F_2 ( V_4 ) ;
int V_5 = F_2 ( V_6 ) ;
int V_7 ;
V_7 = F_3 ( V_1 , V_4 ,
V_3 , V_6 , V_5 , V_2 ) ;
if ( V_7 )
F_4 ( V_1 -> V_8 ,
L_1 ,
V_9 , V_7 ) ;
return V_7 ;
}
static
void F_5 ( struct V_1 * V_10 )
{
V_10 -> V_11 =
V_12 ;
}
static int F_6 ( struct V_13 * V_14 )
{
return 0 ;
}
static int F_7 ( struct V_13 * V_14 )
{
return 0 ;
}
static
void F_8 ( struct V_1 * V_13 , bool V_15 )
{
F_9 ( V_15 ? 0x1 : 0x0 , V_13 -> V_16 + V_17 ) ;
F_10 () ;
}
static inline
void F_11 ( struct V_1 * V_13 , T_1 V_15 )
{
}
static inline void F_12 ( struct V_1 * V_13 )
{
T_1 V_18 ;
V_18 = F_13 ( V_13 -> V_16 + V_19 ) ;
V_18 &= ~ V_20 ;
V_18 |= ( 1 << V_21 ) ;
F_9 ( V_18 , V_13 -> V_16 + V_19 ) ;
F_10 () ;
}
static int F_14 ( struct V_1 * V_10 )
{
int V_7 = 0 ;
T_1 V_15 ;
V_7 = F_15 ( V_10 -> V_16 + V_22 ,
V_15 , ( V_15 & V_23 ) , 10 , 1000000 ) ;
if ( V_7 )
F_4 ( V_10 -> V_8 , L_2 ,
V_9 , V_7 ) ;
return V_7 ;
}
static int F_16 ( struct V_24 * V_25 )
{
struct V_26 * V_8 = & V_25 -> V_8 ;
struct V_13 * V_14 ;
struct V_27 * V_13 ;
struct V_1 * V_10 ;
int V_7 = 0 ;
V_13 = F_17 ( V_8 , sizeof( * V_13 ) , V_28 ) ;
if ( ! V_13 ) {
V_7 = - V_29 ;
goto V_30;
}
V_10 = & V_13 -> V_31 ;
V_14 = F_18 ( V_25 , V_10 ,
& V_32 , & V_33 ) ;
if ( ! V_14 ) {
F_4 ( V_8 , L_3 ,
V_9 ) ;
V_7 = - V_34 ;
goto V_30;
}
V_7 = F_19 ( V_10 ) ;
if ( V_7 ) {
F_4 ( V_10 -> V_8 ,
L_4 ,
V_9 , V_7 ) ;
goto V_30;
}
V_7 = F_20 ( V_10 ) ;
if ( V_7 ) {
F_4 ( V_10 -> V_8 ,
L_5 ,
V_9 , V_7 ) ;
goto V_30;
}
V_10 -> V_35 . V_36 = V_37 ;
V_10 -> V_35 . V_38 = V_37 ;
F_5 ( V_10 ) ;
F_21 ( V_14 , V_13 ) ;
F_22 ( V_10 -> V_39 , V_40 , sizeof( V_10 -> V_39 ) ) ;
V_30:
return V_7 ;
}
