static
int F_1 ( struct V_1 * V_1 ,
bool V_2 )
{
struct V_3 * V_4 , * V_5 ;
int V_6 , V_7 ;
T_1 V_8 = V_1 -> V_9 ;
T_2 V_10 = V_1 -> V_11 ;
T_2 V_12 = V_1 -> V_13 ;
int V_14 ;
if ( ( V_8 == 0x1 ) && ( V_10 == 0x002 ) && ( V_12 == 0x0000 ) ) {
V_6 = F_2 ( V_15 ) ;
V_4 = V_15 ;
} else if ( ( V_8 == 0x1 ) && ( V_10 == 0x003 ) && ( V_12 == 0x0000 ) ) {
V_6 = F_2 ( V_16 ) ;
V_4 = V_16 ;
} else {
F_3 ( V_1 -> V_17 , L_1 ,
V_18 ) ;
V_14 = - V_19 ;
goto V_20;
}
V_7 = F_2 ( V_21 ) ;
V_5 = V_21 ;
V_14 = F_4 ( V_1 , V_4 , V_6 ,
V_5 , V_7 , V_2 ) ;
if ( V_14 )
F_3 ( V_1 -> V_17 , L_2 ,
V_18 , V_14 ) ;
V_20:
return V_14 ;
}
static
void F_5 ( struct V_1 * V_22 )
{
V_22 -> V_23 =
V_24 ;
}
static int F_6 ( struct V_25 * V_26 )
{
return 0 ;
}
static int F_7 ( struct V_25 * V_26 )
{
return 0 ;
}
static
void F_8 ( struct V_1 * V_25 , bool V_27 )
{
bool V_28 = V_25 -> V_23 &
V_24 ;
if ( V_27 ) {
F_9 ( 0x1 , V_25 -> V_29 + V_30 ) ;
F_10 () ;
if ( V_28 ) {
F_11 ( 1 , 2 ) ;
F_9 ( 0x0A , V_25 -> V_29 +
V_31 ) ;
F_9 ( 0x08 , V_25 -> V_29 +
V_31 ) ;
F_10 () ;
}
} else {
if ( V_28 ) {
F_9 ( 0x0A , V_25 -> V_29 +
V_31 ) ;
F_9 ( 0x02 , V_25 -> V_29 +
V_31 ) ;
F_10 () ;
}
F_9 ( 0x0 , V_25 -> V_29 + V_30 ) ;
F_10 () ;
}
}
static
void F_12 ( struct V_1 * V_25 , T_3 V_27 )
{
F_9 ( V_27 & V_32 ,
V_25 -> V_29 + V_33 ) ;
F_10 () ;
}
static inline void F_13 ( struct V_1 * V_25 )
{
T_3 V_34 ;
V_34 = F_14 ( V_25 -> V_29 + V_35 ) ;
V_34 &= ~ V_36 ;
V_34 |= ( 1 << V_37 ) ;
F_9 ( V_34 , V_25 -> V_29 + V_35 ) ;
F_10 () ;
}
static int F_15 ( struct V_1 * V_22 )
{
int V_14 = 0 ;
T_3 V_27 ;
V_14 = F_16 ( V_22 -> V_29 + V_38 ,
V_27 , ( V_27 & V_39 ) , 10 , 1000000 ) ;
if ( V_14 )
F_3 ( V_22 -> V_17 , L_3 ,
V_18 , V_14 ) ;
return V_14 ;
}
static int F_17 ( struct V_40 * V_41 )
{
struct V_42 * V_17 = & V_41 -> V_17 ;
struct V_25 * V_26 ;
struct V_43 * V_25 ;
struct V_1 * V_22 ;
int V_14 = 0 ;
V_25 = F_18 ( V_17 , sizeof( * V_25 ) , V_44 ) ;
if ( ! V_25 ) {
V_14 = - V_45 ;
goto V_20;
}
V_22 = & V_25 -> V_46 ;
V_26 = F_19 ( V_41 , V_22 ,
& V_47 , & V_48 ) ;
if ( ! V_26 ) {
F_3 ( V_17 , L_4 ,
V_18 ) ;
V_14 = - V_49 ;
goto V_20;
}
V_14 = F_20 ( V_22 ) ;
if ( V_14 ) {
F_3 ( V_22 -> V_17 , L_5 ,
V_18 , V_14 ) ;
goto V_20;
}
V_14 = F_21 ( V_22 ) ;
if ( V_14 ) {
F_3 ( V_22 -> V_17 , L_6 ,
V_18 , V_14 ) ;
goto V_20;
}
F_5 ( V_22 ) ;
F_22 ( V_26 , V_25 ) ;
F_23 ( V_22 -> V_50 , V_51 , sizeof( V_22 -> V_50 ) ) ;
V_20:
return V_14 ;
}
