static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( 0 , V_4 -> V_5 + V_6 ) ;
V_4 -> V_7 . V_8 ( & V_4 -> V_7 ) ;
return V_9 ;
}
static void F_3 ( struct V_3 * V_4 ,
unsigned long V_10 ,
unsigned int V_11 )
{
T_2 V_12 = V_4 -> V_13 ;
if ( V_10 )
V_12 |= V_14 ;
if ( V_11 )
V_12 |= V_15 ;
F_2 ( V_10 , V_4 -> V_5 + V_16 ) ;
F_2 ( V_12 , V_4 -> V_5 + V_17 ) ;
}
static int F_4 ( struct V_18 * V_19 )
{
struct V_3 * V_4 =
F_5 ( V_19 , struct V_3 , V_7 ) ;
F_3 ( V_4 , 0 , 0 ) ;
return 0 ;
}
static int F_6 ( struct V_18 * V_19 )
{
struct V_3 * V_4 =
F_5 ( V_19 , struct V_3 , V_7 ) ;
F_3 ( V_4 , V_4 -> V_20 , 1 ) ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 )
{
struct V_3 * V_4 =
F_5 ( V_19 , struct V_3 , V_7 ) ;
F_3 ( V_4 , V_4 -> V_20 , 0 ) ;
return 0 ;
}
static int F_8 ( unsigned long V_21 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 =
F_5 ( V_19 , struct V_3 , V_7 ) ;
F_3 ( V_4 , V_21 , 0 ) ;
return 0 ;
}
static int T_3 F_9 ( struct V_3 * V_4 )
{
T_4 V_22 = F_10 ( V_4 -> V_23 ) ;
T_4 V_24 ;
V_4 -> V_13 = V_25 ;
V_4 -> V_20 = F_11 ( V_22 , V_26 ) ;
V_24 = V_22 ;
if ( V_4 -> V_20 > V_27 ) {
V_4 -> V_13 = V_28 ;
V_24 = V_22 / 16 ;
V_4 -> V_20 = F_11 ( V_24 , V_26 ) ;
}
if ( V_4 -> V_20 > V_27 ) {
V_4 -> V_13 = V_29 ;
V_24 = V_22 / 256 ;
V_4 -> V_20 = F_11 ( V_24 , V_26 ) ;
}
V_4 -> V_7 . V_30 = L_1 ;
V_4 -> V_7 . V_31 = V_32 |
V_33 |
V_34 ;
V_4 -> V_7 . V_35 = F_4 ;
V_4 -> V_7 . V_36 = F_4 ;
V_4 -> V_7 . V_37 = F_6 ;
V_4 -> V_7 . V_38 = F_7 ;
V_4 -> V_7 . V_39 = F_8 ;
V_4 -> V_7 . V_40 = 200 ;
V_4 -> V_7 . V_41 = V_42 ;
V_4 -> V_7 . V_1 = V_4 -> V_1 ;
F_12 ( & V_4 -> V_7 ,
V_24 ,
1 ,
V_27 ) ;
F_13 ( L_2 ,
V_22 ,
V_4 -> V_13 ,
V_4 -> V_20 ) ;
return 0 ;
}
static T_5 T_6 F_14 ( void )
{
return ~ F_15 ( V_43 ) ;
}
static int T_3 F_16 ( struct V_3 * V_4 )
{
T_4 V_22 = F_10 ( V_4 -> V_23 ) ;
int V_44 ;
V_22 = V_22 / 16 ;
F_2 ( V_27 , V_4 -> V_45 + V_16 ) ;
F_2 ( V_15 | V_14 | V_28 ,
V_4 -> V_45 + V_17 ) ;
V_43 = V_4 -> V_45 + V_46 ;
F_17 ( F_14 ,
V_47 , V_22 ) ;
V_44 = F_18 ( V_43 ,
L_3 ,
V_22 , 250 , V_47 ,
V_48 ) ;
if ( F_19 ( V_44 ) ) {
F_20 ( L_4 ) ;
return V_44 ;
}
F_13 ( L_5 , V_22 ) ;
return 0 ;
}
static int T_3 F_21 ( struct V_49 * V_50 )
{
struct V_3 * V_4 ;
void T_7 * V_51 ;
int V_44 ;
V_4 = F_22 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return - V_53 ;
V_4 -> V_23 = F_23 ( V_50 , 0 ) ;
if ( F_24 ( V_4 -> V_23 ) ) {
V_44 = F_25 ( V_4 -> V_23 ) ;
goto V_54;
}
V_44 = F_26 ( V_4 -> V_23 ) ;
if ( V_44 )
goto V_55;
V_51 = F_27 ( V_50 , 0 ) ;
if ( ! V_51 ) {
V_44 = - V_56 ;
goto V_57;
}
V_4 -> V_1 = F_28 ( V_50 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
V_44 = - V_58 ;
goto V_59;
}
V_4 -> V_5 = V_51 + V_60 ;
V_4 -> V_45 = V_51 + V_61 ;
F_2 ( 0 , V_4 -> V_5 + V_17 ) ;
F_2 ( 0 , V_4 -> V_45 + V_17 ) ;
F_2 ( 0 , V_4 -> V_5 + V_16 ) ;
F_2 ( 0 , V_4 -> V_45 + V_16 ) ;
F_2 ( 0 , V_4 -> V_5 + V_6 ) ;
F_2 ( 0 , V_4 -> V_45 + V_6 ) ;
V_44 = F_29 ( V_4 -> V_1 , F_1 ,
V_62 | V_63 ,
L_6 , V_4 ) ;
if ( V_44 )
goto V_59;
V_44 = F_16 ( V_4 ) ;
if ( V_44 )
goto V_64;
V_44 = F_9 ( V_4 ) ;
if ( V_44 )
goto V_64;
return 0 ;
V_64:
F_30 ( V_4 -> V_1 , V_4 ) ;
V_59:
F_31 ( V_51 ) ;
V_57:
F_32 ( V_4 -> V_23 ) ;
V_55:
F_33 ( V_4 -> V_23 ) ;
V_54:
F_34 ( V_4 ) ;
return V_44 ;
}
