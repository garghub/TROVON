static bool F_1 ( void T_1 * V_1 , T_2 V_2 , unsigned long V_3 )
{
V_3 += V_4 ;
while ( F_2 ( V_3 ) ) {
if ( ( F_3 ( V_1 ) & V_2 ) == V_2 )
return true ;
F_4 ( 1 ) ;
}
return false ;
}
static int F_5 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
void T_1 * V_10 = V_7 -> V_10 ;
T_2 V_1 ;
int V_11 ;
F_7 ( V_7 -> V_12 ) ;
V_1 = F_3 ( V_10 + V_13 ) &
~ ( V_14 | V_15
| V_16 | V_17 ) ;
F_8 ( V_1 | ( 0x1 << V_18
| 0xf0 << V_19
| 0x3 << V_20
| 0xd << V_21 ) ,
V_10 + V_13 ) ;
V_1 = F_3 ( V_10 + V_22 ) ;
F_8 ( V_1 | V_23 | V_24 ,
V_10 + V_22 ) ;
V_1 = F_3 ( V_10 + V_25 ) & ~ V_26 ;
F_8 ( V_1 | V_27 | 0x3 << V_28 |
V_29 ,
V_10 + V_25 ) ;
V_1 = F_3 ( V_10 + V_30 ) & ~ V_31 ;
F_8 ( V_1 | 0xa << V_32 ,
V_10 + V_30 ) ;
V_1 = F_3 ( V_10 + V_33 ) &
~ ( V_34 | V_35 |
V_36 | V_37 |
V_38 ) ;
F_8 ( V_1 | ( 0x1 << V_39 |
V_40 ) ,
V_10 + V_33 ) ;
V_1 = F_3 ( V_10 + V_41 ) | V_42 ;
F_8 ( V_1 & ~ V_43 , V_10 + V_41 ) ;
if ( ! F_1 ( V_10 + V_44 ,
V_45 | V_46 ,
V_47 / 10 ) ) {
F_9 ( & V_9 -> V_48 , L_1 ) ;
V_11 = - V_49 ;
goto V_50;
}
if ( ! F_1 ( V_10 + V_51 ,
V_52 , V_47 / 10 ) ) {
F_9 ( & V_9 -> V_48 , L_2 ) ;
V_11 = - V_49 ;
goto V_50;
}
if ( ! F_1 ( V_10 + V_13 ,
V_53 , V_47 / 10 ) ) {
F_9 ( & V_9 -> V_48 , L_3 ) ;
V_11 = - V_49 ;
goto V_50;
}
return 0 ;
V_50:
F_10 ( V_7 -> V_12 ) ;
return V_11 ;
}
static int F_11 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
void T_1 * V_10 = V_7 -> V_10 ;
F_8 ( F_3 ( V_10 + V_54 ) |
( V_55 | V_56 |
V_57 | V_58 ) ,
V_10 + V_54 ) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
void T_1 * V_10 = V_7 -> V_10 ;
F_8 ( F_3 ( V_10 + V_54 ) |
~ ( V_55 | V_56
| V_57 | V_58 ) ,
V_10 + V_54 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
void T_1 * V_10 = V_7 -> V_10 ;
unsigned int V_59 ;
V_59 = F_14 ( V_10 + V_22 ) ;
V_59 &= ~ V_23 ;
F_15 ( V_59 , V_10 + V_22 ) ;
V_59 = F_14 ( V_10 + V_25 ) ;
V_59 &= ~ V_29 ;
F_15 ( V_59 , V_10 + V_25 ) ;
V_59 = F_14 ( V_10 + V_41 ) ;
V_59 &= ~ V_42 ;
F_15 ( V_59 , V_10 + V_41 ) ;
F_10 ( V_7 -> V_12 ) ;
return 0 ;
}
static int F_16 ( struct V_8 * V_9 )
{
struct V_60 * V_60 ;
struct V_6 * V_7 ;
struct V_61 * V_62 ;
V_7 = F_17 ( & V_9 -> V_48 , sizeof( * V_7 ) , V_63 ) ;
if ( ! V_7 )
return - V_64 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_12 = F_18 ( & V_9 -> V_48 , NULL ) ;
if ( F_19 ( V_7 -> V_12 ) ) {
F_20 ( & V_9 -> V_48 , L_4 ) ;
return F_21 ( V_7 -> V_12 ) ;
}
V_62 = F_22 ( V_9 , V_65 , 0 ) ;
V_7 -> V_10 = F_23 ( & V_9 -> V_48 , V_62 ) ;
if ( F_19 ( V_7 -> V_10 ) )
return F_21 ( V_7 -> V_10 ) ;
V_7 -> V_5 = F_24 ( & V_9 -> V_48 , V_9 -> V_48 . V_66 , & V_67 ) ;
if ( F_19 ( V_7 -> V_5 ) )
return F_21 ( V_7 -> V_5 ) ;
F_25 ( V_7 -> V_5 , V_7 ) ;
V_60 = F_26 ( & V_9 -> V_48 , V_68 ) ;
return F_27 ( V_60 ) ;
}
