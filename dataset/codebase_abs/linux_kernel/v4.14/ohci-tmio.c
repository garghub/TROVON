static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_7 ;
unsigned long V_8 ;
F_4 ( & V_6 -> V_9 , V_8 ) ;
V_7 = V_10 | V_11 |
V_12 | V_13 ;
F_5 ( V_7 , V_6 -> V_14 + V_15 ) ;
F_6 ( & V_6 -> V_9 , V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_8 ( V_4 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_7 ;
V_7 = V_10 | V_11 ;
switch ( V_17 -> V_18 ) {
default:
F_9 ( & V_2 -> V_2 , L_1 , V_17 -> V_18 ) ;
case 3 :
V_7 |= V_19 ;
case 2 :
V_7 |= V_20 ;
case 1 :
V_7 |= V_21 ;
}
F_10 ( 0 , V_6 -> V_14 + V_22 ) ;
F_10 ( 0 , V_6 -> V_14 + V_23 ) ;
F_5 ( 0 , V_6 -> V_14 + V_24 ) ;
F_5 ( 0 , V_6 -> V_14 + V_24 + 2 ) ;
F_5 ( V_7 , V_6 -> V_14 + V_15 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
unsigned long V_25 = V_4 -> V_26 ;
F_1 ( V_2 ) ;
F_5 ( V_25 , V_6 -> V_14 + V_24 ) ;
F_5 ( V_25 >> 16 , V_6 -> V_14 + V_24 + 2 ) ;
F_10 ( 1 , V_6 -> V_14 + V_23 ) ;
F_10 ( 2 , V_6 -> V_14 + V_22 ) ;
F_12 ( & V_2 -> V_2 , L_2 ,
F_13 ( V_6 -> V_14 + V_27 ) ,
( V_28 ) V_4 -> V_26 , V_4 -> V_29 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = F_8 ( V_4 ) ;
int V_30 ;
if ( ( V_30 = F_15 ( V_17 ) ) < 0 )
return V_30 ;
if ( ( V_30 = F_16 ( V_17 ) ) < 0 ) {
F_9 ( V_4 -> V_31 . V_32 , L_3 ,
V_4 -> V_31 . V_33 ) ;
F_17 ( V_4 ) ;
return V_30 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
const struct V_34 * V_35 = F_19 ( V_2 ) ;
struct V_36 * V_37 = F_20 ( V_2 , V_38 , 0 ) ;
struct V_36 * V_39 = F_20 ( V_2 , V_38 , 1 ) ;
struct V_36 * V_40 = F_20 ( V_2 , V_38 , 2 ) ;
int V_29 = F_21 ( V_2 , 0 ) ;
struct V_5 * V_6 ;
struct V_16 * V_17 ;
struct V_3 * V_4 ;
int V_30 ;
if ( F_22 () )
return - V_41 ;
if ( ! V_35 )
return - V_42 ;
V_4 = F_23 ( & V_43 , & V_2 -> V_2 , F_24 ( & V_2 -> V_2 ) ) ;
if ( ! V_4 ) {
V_30 = - V_44 ;
goto V_45;
}
V_4 -> V_26 = V_37 -> V_46 ;
V_4 -> V_47 = F_25 ( V_37 ) ;
V_6 = F_3 ( V_4 ) ;
F_26 ( & V_6 -> V_9 ) ;
V_6 -> V_14 = F_27 ( V_39 -> V_46 , F_25 ( V_39 ) ) ;
if ( ! V_6 -> V_14 ) {
V_30 = - V_44 ;
goto V_48;
}
V_4 -> V_37 = F_27 ( V_4 -> V_26 , V_4 -> V_47 ) ;
if ( ! V_4 -> V_37 ) {
V_30 = - V_44 ;
goto V_49;
}
V_30 = F_28 ( & V_2 -> V_2 , V_40 -> V_46 , V_40 -> V_46 ,
F_25 ( V_40 ) , V_50 ) ;
if ( V_30 )
goto V_51;
if ( V_35 -> V_52 ) {
V_30 = V_35 -> V_52 ( V_2 ) ;
if ( V_30 )
goto V_53;
}
F_11 ( V_2 ) ;
V_17 = F_8 ( V_4 ) ;
F_29 ( V_17 ) ;
V_30 = F_30 ( V_4 , V_29 , 0 ) ;
if ( V_30 )
goto V_54;
F_31 ( V_4 -> V_31 . V_32 ) ;
if ( V_30 == 0 )
return V_30 ;
F_32 ( V_4 ) ;
V_54:
F_7 ( V_2 ) ;
if ( V_35 -> V_55 )
V_35 -> V_55 ( V_2 ) ;
V_53:
F_33 ( & V_2 -> V_2 ) ;
V_51:
F_34 ( V_4 -> V_37 ) ;
V_49:
F_34 ( V_6 -> V_14 ) ;
V_48:
F_35 ( V_4 ) ;
V_45:
return V_30 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
const struct V_34 * V_35 = F_19 ( V_2 ) ;
F_32 ( V_4 ) ;
F_7 ( V_2 ) ;
if ( V_35 -> V_55 )
V_35 -> V_55 ( V_2 ) ;
F_33 ( & V_2 -> V_2 ) ;
F_34 ( V_4 -> V_37 ) ;
F_34 ( V_6 -> V_14 ) ;
F_35 ( V_4 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 V_56 )
{
const struct V_34 * V_35 = F_19 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_8 ( V_4 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
unsigned long V_8 ;
T_3 V_57 ;
int V_30 ;
if ( F_38 ( V_58 , V_17 -> V_59 ) )
F_39 ( 5 ) ;
V_17 -> V_59 = V_58 ;
F_4 ( & V_6 -> V_9 , V_8 ) ;
V_57 = F_13 ( V_6 -> V_14 + V_60 ) ;
V_57 |= 1 << 3 ;
F_10 ( V_57 , V_6 -> V_14 + V_60 ) ;
F_6 ( & V_6 -> V_9 , V_8 ) ;
if ( V_35 -> V_61 ) {
V_30 = V_35 -> V_61 ( V_2 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
const struct V_34 * V_35 = F_19 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_8 ( V_4 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
unsigned long V_8 ;
T_3 V_57 ;
int V_30 ;
if ( F_38 ( V_58 , V_17 -> V_59 ) )
F_39 ( 5 ) ;
V_17 -> V_59 = V_58 ;
if ( V_35 -> V_62 ) {
V_30 = V_35 -> V_62 ( V_2 ) ;
if ( V_30 )
return V_30 ;
}
F_11 ( V_2 ) ;
F_4 ( & V_6 -> V_9 , V_8 ) ;
V_57 = F_13 ( V_6 -> V_14 + V_60 ) ;
V_57 &= ~ ( 1 << 3 ) ;
F_10 ( V_57 , V_6 -> V_14 + V_60 ) ;
F_6 ( & V_6 -> V_9 , V_8 ) ;
F_41 ( V_4 , false ) ;
return 0 ;
}
