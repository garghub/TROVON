static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_8 = V_9 ;
if ( F_3 ( V_2 ) ) {
F_4 ( V_2 -> V_10 , L_1 ) ;
return 0 ;
}
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_11 + V_8 + V_12 , 2 , & V_3 ) ;
V_3 &= ~ V_13 ;
F_7 ( V_2 -> V_11 + V_8 + V_12 , 2 , V_3 ) ;
F_7 ( V_2 -> V_11 + V_14 , 2 , 0x104A ) ;
F_7 ( V_2 -> V_11 + V_15 , 2 , 0xCD80 ) ;
if ( V_4 -> V_16 ) {
F_6 ( V_2 -> V_11 + V_8 + V_17 ,
4 , & V_3 ) ;
if ( ( V_3 & V_18 ) != V_19 ) {
V_3 &= ~ ( ( T_1 ) V_18 ) ;
V_3 |= V_19 ;
F_7 ( V_2 -> V_11 + V_8 +
V_17 , 4 , V_3 ) ;
}
F_6 ( V_2 -> V_11 + V_8 + V_20 ,
2 , & V_3 ) ;
if ( ( V_3 & V_18 ) != V_19 ) {
V_3 &= ~ ( ( T_1 ) V_18 ) ;
V_3 |= V_19 ;
F_7 ( V_2 -> V_11 + V_8 +
V_20 , 2 , V_3 ) ;
}
}
F_8 ( V_21 | ( 1 << V_22 )
| ( 1 << V_23 )
| ( ( T_1 ) 1 << V_24 ) ,
& V_6 -> V_25 ) ;
return F_9 ( V_2 ) ;
}
static T_2 F_10 ( int V_26 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_28 ;
V_28 = F_11 ( & V_6 -> V_29 ) ;
if ( V_28 & V_30 ) {
F_12 ( ! F_13 ( V_31 ) ) ;
F_14 ( V_2 ) ;
}
F_8 ( V_28 , & V_6 -> V_32 ) ;
return V_33 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_13 ( V_31 ) ) {
F_16 ( V_2 ) ;
F_8 ( F_11 ( & V_6 -> V_34 ) |
V_30 , & V_6 -> V_34 ) ;
}
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
if ( F_11 ( & V_6 -> V_35 ) & V_36 )
return 1 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_15 ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_39 * V_10 = & V_38 -> V_10 ;
int V_40 ;
V_2 -> V_26 = F_20 ( V_38 , 0 ) ;
if ( ! V_2 -> V_26 ) {
F_4 ( V_10 , L_2 ) ;
return - V_41 ;
}
V_40 = F_21 ( V_10 , V_2 -> V_26 , F_10 ,
V_42 | V_43 ,
L_3 , V_2 ) ;
if ( V_40 ) {
F_4 ( V_10 , L_4 , V_2 -> V_26 ) ;
return V_40 ;
}
V_2 -> V_44 = - 1 ;
V_2 -> V_45 = & V_46 ;
V_40 = F_22 ( V_2 ) ;
if ( V_40 ) {
F_4 ( V_10 , L_5 ) ;
return V_40 ;
}
return 0 ;
}
static int F_23 ( struct V_37 * V_38 )
{
struct V_4 * V_4 ;
struct V_1 * V_2 ;
struct V_39 * V_10 = & V_38 -> V_10 ;
struct V_47 * V_48 = V_38 -> V_10 . V_49 ;
struct V_50 * V_11 ;
int V_40 ;
V_4 = F_24 ( V_10 , sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 )
return - V_52 ;
V_4 -> V_53 = F_25 ( V_10 , L_6 ) ;
if ( F_26 ( V_4 -> V_53 ) ) {
V_40 = F_27 ( V_4 -> V_53 ) ;
if ( V_40 == - V_54 )
F_28 ( V_10 , L_7 ) ;
else
F_4 ( V_10 , L_8 ) ;
return V_40 ;
}
F_29 ( V_4 -> V_53 ) ;
V_4 -> V_55 = F_30 ( V_10 , NULL ) ;
if ( F_26 ( V_4 -> V_55 ) ) {
F_4 ( V_10 , L_9 ) ;
return F_27 ( V_4 -> V_55 ) ;
}
V_40 = F_31 ( V_4 -> V_55 ) ;
if ( V_40 ) {
F_4 ( V_10 , L_10 ) ;
return V_40 ;
}
V_2 = & V_4 -> V_2 ;
V_2 -> V_10 = V_10 ;
V_11 = F_32 ( V_38 , V_56 , L_11 ) ;
V_2 -> V_11 = F_33 ( V_10 , V_11 ) ;
if ( F_26 ( V_2 -> V_11 ) ) {
F_4 ( V_10 , L_12 , V_11 ) ;
V_40 = F_27 ( V_2 -> V_11 ) ;
goto V_57;
}
V_4 -> V_7 = V_2 -> V_11 + 0x2000 ;
if ( F_34 ( V_48 , L_13 ) )
V_4 -> V_16 = true ;
V_40 = F_19 ( V_2 , V_38 ) ;
if ( V_40 < 0 )
goto V_57;
F_35 ( V_38 , V_4 ) ;
return 0 ;
V_57:
F_36 ( V_4 -> V_55 ) ;
return V_40 ;
}
static int T_3 F_37 ( void )
{
return F_38 ( & V_58 ) ;
}
