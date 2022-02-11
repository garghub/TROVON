static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
struct V_6 * V_7 = V_1 -> V_8 ;
T_1 V_9 ;
T_1 V_10 = V_11 ;
if ( F_2 ( V_3 ) ) {
F_3 ( V_3 -> V_12 , L_1 ) ;
return 0 ;
}
F_4 ( V_5 ) ;
F_5 ( V_3 -> V_13 + V_10 + V_14 , 2 , & V_9 ) ;
V_9 &= ~ V_15 ;
F_6 ( V_3 -> V_13 + V_10 + V_14 , 2 , V_9 ) ;
F_6 ( V_3 -> V_13 + V_16 , 2 , 0x104A ) ;
F_6 ( V_3 -> V_13 + V_17 , 2 , 0xCD80 ) ;
if ( V_1 -> V_18 ) {
F_5 ( V_3 -> V_13 + V_10 + V_19 ,
4 , & V_9 ) ;
if ( ( V_9 & V_20 ) != V_21 ) {
V_9 &= ~ ( ( T_1 ) V_20 ) ;
V_9 |= V_21 ;
F_6 ( V_3 -> V_13 + V_10 +
V_19 , 4 , V_9 ) ;
}
F_5 ( V_3 -> V_13 + V_10 + V_22 ,
2 , & V_9 ) ;
if ( ( V_9 & V_20 ) != V_21 ) {
V_9 &= ~ ( ( T_1 ) V_20 ) ;
V_9 |= V_21 ;
F_6 ( V_3 -> V_13 + V_10 +
V_22 , 2 , V_9 ) ;
}
}
F_7 ( V_23 | ( 1 << V_24 )
| ( 1 << V_25 )
| ( ( T_1 ) 1 << V_26 ) ,
& V_7 -> V_27 ) ;
return F_8 ( V_3 ) ;
}
static T_2 F_9 ( int V_28 , void * V_29 )
{
struct V_1 * V_1 = V_29 ;
struct V_6 * V_7 = V_1 -> V_8 ;
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
unsigned int V_30 ;
V_30 = F_10 ( & V_7 -> V_31 ) ;
if ( V_30 & V_32 ) {
F_11 ( ! F_12 ( V_33 ) ) ;
F_13 ( V_5 ) ;
}
F_7 ( V_30 , & V_7 -> V_34 ) ;
return V_35 ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
struct V_6 * V_7 = V_1 -> V_8 ;
if ( F_12 ( V_33 ) ) {
F_15 ( V_5 ) ;
F_7 ( F_10 ( & V_7 -> V_36 ) |
V_32 , & V_7 -> V_36 ) ;
}
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_17 ( V_3 ) ;
struct V_6 * V_7 = V_1 -> V_8 ;
if ( F_10 ( & V_7 -> V_37 ) & V_38 )
return 1 ;
return 0 ;
}
static void F_18 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_19 ( V_5 ) ;
struct V_1 * V_1 = F_17 ( V_3 ) ;
F_1 ( V_1 ) ;
F_14 ( V_1 ) ;
}
static int F_20 ( struct V_1 * V_1 ,
struct V_39 * V_40 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
struct V_41 * V_12 = & V_40 -> V_12 ;
int V_42 ;
V_5 -> V_28 = F_21 ( V_40 , 0 ) ;
if ( ! V_5 -> V_28 ) {
F_3 ( V_12 , L_2 ) ;
return - V_43 ;
}
V_42 = F_22 ( V_12 , V_5 -> V_28 , F_9 ,
V_44 | V_45 ,
L_3 , V_1 ) ;
if ( V_42 ) {
F_3 ( V_12 , L_4 , V_5 -> V_28 ) ;
return V_42 ;
}
V_5 -> V_46 = - 1 ;
V_5 -> V_47 = & V_48 ;
V_42 = F_23 ( V_5 ) ;
if ( V_42 ) {
F_3 ( V_12 , L_5 ) ;
return V_42 ;
}
return 0 ;
}
static int F_24 ( struct V_39 * V_40 )
{
struct V_41 * V_12 = & V_40 -> V_12 ;
struct V_2 * V_3 ;
struct V_1 * V_1 ;
struct V_49 * V_50 = V_12 -> V_51 ;
struct V_52 * V_13 ;
int V_42 ;
V_1 = F_25 ( V_12 , sizeof( * V_1 ) , V_53 ) ;
if ( ! V_1 )
return - V_54 ;
V_3 = F_25 ( V_12 , sizeof( * V_3 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
V_3 -> V_12 = V_12 ;
V_3 -> V_47 = & V_55 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_56 = F_26 ( V_12 , L_6 ) ;
if ( F_27 ( V_1 -> V_56 ) ) {
V_42 = F_28 ( V_1 -> V_56 ) ;
if ( V_42 == - V_57 )
F_29 ( V_12 , L_7 ) ;
else
F_3 ( V_12 , L_8 ) ;
return V_42 ;
}
F_30 ( V_1 -> V_56 ) ;
V_1 -> V_58 = F_31 ( V_12 , NULL ) ;
if ( F_27 ( V_1 -> V_58 ) ) {
F_3 ( V_12 , L_9 ) ;
return F_28 ( V_1 -> V_58 ) ;
}
V_42 = F_32 ( V_1 -> V_58 ) ;
if ( V_42 ) {
F_3 ( V_12 , L_10 ) ;
return V_42 ;
}
V_13 = F_33 ( V_40 , V_59 , L_11 ) ;
V_3 -> V_13 = F_34 ( V_12 , V_13 ) ;
if ( F_27 ( V_3 -> V_13 ) ) {
F_3 ( V_12 , L_12 , V_13 ) ;
V_42 = F_28 ( V_3 -> V_13 ) ;
goto V_60;
}
V_1 -> V_8 = V_3 -> V_13 + 0x2000 ;
if ( F_35 ( V_50 , L_13 ) )
V_1 -> V_18 = true ;
F_36 ( V_40 , V_1 ) ;
V_42 = F_20 ( V_1 , V_40 ) ;
if ( V_42 < 0 )
goto V_60;
return 0 ;
V_60:
F_37 ( V_1 -> V_58 ) ;
return V_42 ;
}
