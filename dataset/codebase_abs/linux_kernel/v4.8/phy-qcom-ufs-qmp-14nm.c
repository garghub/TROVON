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
struct V_15 * V_13 = F_7 ( V_14 ) ;
struct V_1 * V_10 = & V_13 -> V_16 ;
int V_7 ;
V_7 = F_8 ( V_14 , V_10 ) ;
if ( V_7 ) {
F_4 ( V_10 -> V_8 , L_2 ,
V_9 , V_7 ) ;
goto V_17;
}
V_7 = F_9 ( V_14 , V_10 ) ;
if ( V_7 ) {
F_4 ( V_10 -> V_8 , L_3 ,
V_9 , V_7 ) ;
goto V_17;
}
V_10 -> V_18 . V_19 = V_20 ;
V_10 -> V_18 . V_21 = V_20 ;
F_5 ( V_10 ) ;
V_17:
return V_7 ;
}
static
void F_10 ( struct V_1 * V_13 , bool V_22 )
{
F_11 ( V_22 ? 0x1 : 0x0 , V_13 -> V_23 + V_24 ) ;
F_12 () ;
}
static inline
void F_13 ( struct V_1 * V_13 , T_1 V_22 )
{
}
static inline void F_14 ( struct V_1 * V_13 )
{
T_1 V_25 ;
V_25 = F_15 ( V_13 -> V_23 + V_26 ) ;
V_25 &= ~ V_27 ;
V_25 |= ( 1 << V_28 ) ;
F_11 ( V_25 , V_13 -> V_23 + V_26 ) ;
F_12 () ;
}
static int F_16 ( struct V_1 * V_10 )
{
int V_7 = 0 ;
T_1 V_22 ;
V_7 = F_17 ( V_10 -> V_23 + V_29 ,
V_22 , ( V_22 & V_30 ) , 10 , 1000000 ) ;
if ( V_7 )
F_4 ( V_10 -> V_8 , L_4 ,
V_9 , V_7 ) ;
return V_7 ;
}
static int F_18 ( struct V_31 * V_32 )
{
struct V_33 * V_8 = & V_32 -> V_8 ;
struct V_13 * V_14 ;
struct V_15 * V_13 ;
int V_7 = 0 ;
V_13 = F_19 ( V_8 , sizeof( * V_13 ) , V_34 ) ;
if ( ! V_13 ) {
V_7 = - V_35 ;
goto V_17;
}
V_14 = F_20 ( V_32 , & V_13 -> V_16 ,
& V_36 , & V_37 ) ;
if ( ! V_14 ) {
F_4 ( V_8 , L_5 ,
V_9 ) ;
V_7 = - V_38 ;
goto V_17;
}
F_21 ( V_14 , V_13 ) ;
F_22 ( V_13 -> V_16 . V_39 , V_40 ,
sizeof( V_13 -> V_16 . V_39 ) ) ;
V_17:
return V_7 ;
}
static int F_23 ( struct V_31 * V_32 )
{
struct V_33 * V_8 = & V_32 -> V_8 ;
struct V_13 * V_14 = F_24 ( V_8 ) ;
struct V_1 * V_1 = F_25 ( V_14 ) ;
int V_7 = 0 ;
V_7 = F_26 ( V_14 , V_1 ) ;
if ( V_7 )
F_4 ( V_8 , L_6 ,
V_9 , V_7 ) ;
return V_7 ;
}
