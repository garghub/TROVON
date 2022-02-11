static int F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
T_2 V_5 ;
V_5 = F_2 (
! ( ( F_3 ( & V_4 -> V_6 ) ) & V_7 ) , V_8 , 0 ) ;
if ( ! V_5 ) {
F_4 ( V_2 , L_1 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
T_2 V_5 ;
V_5 = F_2 (
! ( ( F_3 ( & V_4 -> V_10 ) ) & V_11 ) , V_8 , 0 ) ;
if ( ! V_5 ) {
F_4 ( V_2 , L_2 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_6 ( struct V_12 * V_13 , int V_14 , int V_15 , T_3 V_16 )
{
struct V_3 T_1 * V_4 = V_13 -> V_17 ;
T_4 V_18 = V_15 >> 16 ;
int V_19 ;
F_7 ( & V_4 -> V_6 , F_8 ( 100 ) ) ;
V_19 = F_1 ( & V_13 -> V_2 , V_4 ) ;
if ( V_19 )
return V_19 ;
F_7 ( & V_4 -> V_20 ,
F_9 ( V_14 ) | F_10 ( V_18 ) ) ;
F_7 ( & V_4 -> V_21 , V_15 & 0xffff ) ;
V_19 = F_1 ( & V_13 -> V_2 , V_4 ) ;
if ( V_19 )
return V_19 ;
F_7 ( & V_4 -> V_10 , F_11 ( V_16 ) ) ;
V_19 = F_5 ( & V_13 -> V_2 , V_4 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 , int V_14 , int V_15 )
{
struct V_3 T_1 * V_4 = V_13 -> V_17 ;
T_4 V_18 = V_15 >> 16 ;
T_2 V_20 ;
T_4 V_16 ;
int V_19 ;
F_7 ( & V_4 -> V_6 , F_8 ( 100 ) ) ;
V_19 = F_1 ( & V_13 -> V_2 , V_4 ) ;
if ( V_19 )
return V_19 ;
V_20 = F_9 ( V_14 ) | F_10 ( V_18 ) ;
F_7 ( & V_4 -> V_20 , V_20 ) ;
F_7 ( & V_4 -> V_21 , V_15 & 0xffff ) ;
V_19 = F_1 ( & V_13 -> V_2 , V_4 ) ;
if ( V_19 )
return V_19 ;
F_7 ( & V_4 -> V_20 , V_20 | V_22 ) ;
V_19 = F_5 ( & V_13 -> V_2 , V_4 ) ;
if ( V_19 )
return V_19 ;
if ( F_3 ( & V_4 -> V_6 ) & V_23 ) {
F_4 ( & V_13 -> V_2 , L_3 ) ;
return 0xffff ;
}
V_16 = F_3 ( & V_4 -> V_10 ) & 0xffff ;
F_13 ( & V_13 -> V_2 , L_4 , V_16 ) ;
return V_16 ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_3 T_1 * V_4 = V_13 -> V_17 ;
int V_19 ;
F_15 ( & V_13 -> V_24 ) ;
F_7 ( & V_4 -> V_6 , F_8 ( 100 ) ) ;
V_19 = F_1 ( & V_13 -> V_2 , V_4 ) ;
F_16 ( & V_13 -> V_24 ) ;
return V_19 ;
}
static int F_17 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_2 . V_29 ;
struct V_12 * V_13 ;
struct V_30 V_31 ;
int V_19 ;
V_19 = F_18 ( V_28 , 0 , & V_31 ) ;
if ( V_19 ) {
F_4 ( & V_26 -> V_2 , L_5 ) ;
return V_19 ;
}
V_13 = F_19 ( V_32 * sizeof( int ) ) ;
if ( ! V_13 )
return - V_33 ;
V_13 -> V_34 = L_6 ;
V_13 -> V_35 = F_12 ;
V_13 -> V_36 = F_6 ;
V_13 -> V_37 = F_14 ;
V_13 -> V_38 = V_13 -> V_17 ;
V_13 -> V_39 = & V_26 -> V_2 ;
snprintf ( V_13 -> V_40 , V_41 , L_7 , ( unsigned long long ) V_31 . V_42 ) ;
V_13 -> V_17 = F_20 ( V_28 , 0 ) ;
if ( ! V_13 -> V_17 ) {
V_19 = - V_33 ;
goto V_43;
}
V_19 = F_21 ( V_13 , V_28 ) ;
if ( V_19 ) {
F_4 ( & V_26 -> V_2 , L_8 ) ;
goto V_44;
}
F_22 ( & V_26 -> V_2 , V_13 ) ;
return 0 ;
V_44:
F_23 ( V_13 -> V_17 ) ;
V_43:
F_24 ( V_13 ) ;
return V_19 ;
}
static int F_25 ( struct V_25 * V_26 )
{
struct V_12 * V_13 = F_26 ( & V_26 -> V_2 ) ;
F_27 ( V_13 ) ;
F_23 ( V_13 -> V_17 ) ;
F_24 ( V_13 ) ;
return 0 ;
}
