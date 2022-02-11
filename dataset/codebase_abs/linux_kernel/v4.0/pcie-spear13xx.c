static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 0 ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_9 = V_10 ;
if ( F_3 ( V_2 ) ) {
F_4 ( V_2 -> V_11 , L_1 ) ;
return 0 ;
}
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_12 , V_9 + V_13 , 4 , & V_3 ) ;
V_3 &= ~ V_14 ;
F_7 ( V_2 -> V_12 , V_9 + V_13 , 4 , V_3 ) ;
F_7 ( V_2 -> V_12 , V_15 , 2 , 0x104A ) ;
F_7 ( V_2 -> V_12 , V_16 , 2 , 0xCD80 ) ;
if ( V_5 -> V_17 ) {
F_6 ( V_2 -> V_12 , V_9 + V_18 , 4 ,
& V_3 ) ;
if ( ( V_3 & V_19 ) != V_20 ) {
V_3 &= ~ ( ( T_1 ) V_19 ) ;
V_3 |= V_20 ;
F_7 ( V_2 -> V_12 , V_9 +
V_18 , 4 , V_3 ) ;
}
F_6 ( V_2 -> V_12 , V_9 + V_21 , 4 ,
& V_3 ) ;
if ( ( V_3 & V_19 ) != V_20 ) {
V_3 &= ~ ( ( T_1 ) V_19 ) ;
V_3 |= V_20 ;
F_7 ( V_2 -> V_12 , V_9 +
V_21 , 4 , V_3 ) ;
}
}
F_8 ( V_22 | ( 1 << V_23 )
| ( 1 << V_24 )
| ( ( T_1 ) 1 << V_25 ) ,
& V_7 -> V_26 ) ;
while ( ! F_3 ( V_2 ) ) {
F_9 ( 100 ) ;
V_4 ++ ;
if ( V_4 == 10 ) {
F_4 ( V_2 -> V_11 , L_2 ) ;
return - V_27 ;
}
}
F_10 ( V_2 -> V_11 , L_3 ) ;
return 0 ;
}
static T_2 F_11 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned int V_30 ;
V_30 = F_12 ( & V_7 -> V_31 ) ;
if ( V_30 & V_32 ) {
if ( ! F_13 ( V_33 ) )
F_14 () ;
F_15 ( V_2 ) ;
}
F_8 ( V_30 , & V_7 -> V_34 ) ;
return V_35 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_13 ( V_33 ) ) {
F_17 ( V_2 ) ;
F_8 ( F_12 ( & V_7 -> V_36 ) |
V_32 , & V_7 -> V_36 ) ;
}
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_12 ( & V_7 -> V_37 ) & V_38 )
return 1 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_16 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_41 * V_11 = & V_40 -> V_11 ;
int V_42 ;
V_2 -> V_28 = F_21 ( V_40 , 0 ) ;
if ( ! V_2 -> V_28 ) {
F_4 ( V_11 , L_4 ) ;
return - V_43 ;
}
V_42 = F_22 ( V_11 , V_2 -> V_28 , F_11 ,
V_44 , L_5 , V_2 ) ;
if ( V_42 ) {
F_4 ( V_11 , L_6 , V_2 -> V_28 ) ;
return V_42 ;
}
V_2 -> V_45 = - 1 ;
V_2 -> V_46 = & V_47 ;
V_42 = F_23 ( V_2 ) ;
if ( V_42 ) {
F_4 ( V_11 , L_7 ) ;
return V_42 ;
}
return 0 ;
}
static int F_24 ( struct V_39 * V_40 )
{
struct V_5 * V_5 ;
struct V_1 * V_2 ;
struct V_41 * V_11 = & V_40 -> V_11 ;
struct V_48 * V_49 = V_40 -> V_11 . V_50 ;
struct V_51 * V_12 ;
int V_42 ;
V_5 = F_25 ( V_11 , sizeof( * V_5 ) , V_52 ) ;
if ( ! V_5 )
return - V_53 ;
V_5 -> V_54 = F_26 ( V_11 , L_8 ) ;
if ( F_27 ( V_5 -> V_54 ) ) {
V_42 = F_28 ( V_5 -> V_54 ) ;
if ( V_42 == - V_55 )
F_10 ( V_11 , L_9 ) ;
else
F_4 ( V_11 , L_10 ) ;
return V_42 ;
}
F_29 ( V_5 -> V_54 ) ;
V_5 -> V_56 = F_30 ( V_11 , NULL ) ;
if ( F_27 ( V_5 -> V_56 ) ) {
F_4 ( V_11 , L_11 ) ;
return F_28 ( V_5 -> V_56 ) ;
}
V_42 = F_31 ( V_5 -> V_56 ) ;
if ( V_42 ) {
F_4 ( V_11 , L_12 ) ;
return V_42 ;
}
V_2 = & V_5 -> V_2 ;
V_2 -> V_11 = V_11 ;
V_12 = F_32 ( V_40 , V_57 , L_13 ) ;
V_2 -> V_12 = F_33 ( V_11 , V_12 ) ;
if ( F_27 ( V_2 -> V_12 ) ) {
F_4 ( V_11 , L_14 , V_12 ) ;
V_42 = F_28 ( V_2 -> V_12 ) ;
goto V_58;
}
V_5 -> V_8 = V_2 -> V_12 + 0x2000 ;
if ( F_34 ( V_49 , L_15 ) )
V_5 -> V_17 = true ;
V_42 = F_20 ( V_2 , V_40 ) ;
if ( V_42 < 0 )
goto V_58;
F_35 ( V_40 , V_5 ) ;
return 0 ;
V_58:
F_36 ( V_5 -> V_56 ) ;
return V_42 ;
}
static int T_3 F_37 ( void )
{
return F_38 ( & V_59 ) ;
}
