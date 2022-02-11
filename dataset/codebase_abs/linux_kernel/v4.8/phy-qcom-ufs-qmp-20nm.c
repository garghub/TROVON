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
struct V_27 * V_25 = F_7 ( V_26 ) ;
struct V_1 * V_22 = & V_25 -> V_28 ;
int V_14 = 0 ;
V_14 = F_8 ( V_26 , V_22 ) ;
if ( V_14 ) {
F_3 ( V_22 -> V_17 , L_3 ,
V_18 , V_14 ) ;
goto V_20;
}
V_14 = F_9 ( V_26 , V_22 ) ;
if ( V_14 ) {
F_3 ( V_22 -> V_17 , L_4 ,
V_18 , V_14 ) ;
goto V_20;
}
F_5 ( V_22 ) ;
V_20:
return V_14 ;
}
static
void F_10 ( struct V_1 * V_25 , bool V_29 )
{
bool V_30 = V_25 -> V_23 &
V_24 ;
if ( V_29 ) {
F_11 ( 0x1 , V_25 -> V_31 + V_32 ) ;
F_12 () ;
if ( V_30 ) {
F_13 ( 1 , 2 ) ;
F_11 ( 0x0A , V_25 -> V_31 +
V_33 ) ;
F_11 ( 0x08 , V_25 -> V_31 +
V_33 ) ;
F_12 () ;
}
} else {
if ( V_30 ) {
F_11 ( 0x0A , V_25 -> V_31 +
V_33 ) ;
F_11 ( 0x02 , V_25 -> V_31 +
V_33 ) ;
F_12 () ;
}
F_11 ( 0x0 , V_25 -> V_31 + V_32 ) ;
F_12 () ;
}
}
static
void F_14 ( struct V_1 * V_25 , T_3 V_29 )
{
F_11 ( V_29 & V_34 ,
V_25 -> V_31 + V_35 ) ;
F_12 () ;
}
static inline void F_15 ( struct V_1 * V_25 )
{
T_3 V_36 ;
V_36 = F_16 ( V_25 -> V_31 + V_37 ) ;
V_36 &= ~ V_38 ;
V_36 |= ( 1 << V_39 ) ;
F_11 ( V_36 , V_25 -> V_31 + V_37 ) ;
F_12 () ;
}
static int F_17 ( struct V_1 * V_22 )
{
int V_14 = 0 ;
T_3 V_29 ;
V_14 = F_18 ( V_22 -> V_31 + V_40 ,
V_29 , ( V_29 & V_41 ) , 10 , 1000000 ) ;
if ( V_14 )
F_3 ( V_22 -> V_17 , L_5 ,
V_18 , V_14 ) ;
return V_14 ;
}
static int F_19 ( struct V_42 * V_43 )
{
struct V_44 * V_17 = & V_43 -> V_17 ;
struct V_25 * V_26 ;
struct V_27 * V_25 ;
int V_14 = 0 ;
V_25 = F_20 ( V_17 , sizeof( * V_25 ) , V_45 ) ;
if ( ! V_25 ) {
V_14 = - V_46 ;
goto V_20;
}
V_26 = F_21 ( V_43 , & V_25 -> V_28 ,
& V_47 , & V_48 ) ;
if ( ! V_26 ) {
F_3 ( V_17 , L_6 ,
V_18 ) ;
V_14 = - V_49 ;
goto V_20;
}
F_22 ( V_26 , V_25 ) ;
F_23 ( V_25 -> V_28 . V_50 , V_51 ,
sizeof( V_25 -> V_28 . V_50 ) ) ;
V_20:
return V_14 ;
}
static int F_24 ( struct V_42 * V_43 )
{
struct V_44 * V_17 = & V_43 -> V_17 ;
struct V_25 * V_26 = F_25 ( V_17 ) ;
struct V_1 * V_1 = F_26 ( V_26 ) ;
int V_14 = 0 ;
V_14 = F_27 ( V_26 , V_1 ) ;
if ( V_14 )
F_3 ( V_17 , L_7 ,
V_18 , V_14 ) ;
return V_14 ;
}
