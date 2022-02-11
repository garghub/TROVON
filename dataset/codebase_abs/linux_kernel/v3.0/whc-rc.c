static int F_1 ( struct V_1 * V_1 ,
const struct V_2 * V_3 , T_1 V_4 )
{
int V_5 = 0 ;
struct V_6 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 -> V_9 ;
T_2 V_11 ;
if ( V_4 >= 4096 )
return - V_12 ;
if ( F_2 ( V_6 -> V_13 + V_14 ) & V_15 ) {
F_3 ( V_9 , L_1 ) ;
F_4 ( V_1 ) ;
return - V_16 ;
}
V_5 = F_5 ( V_6 -> V_17 ,
! ( F_2 ( V_6 -> V_13 + V_18 ) & V_19 ) , V_20 / 2 ) ;
if ( V_5 == 0 ) {
F_3 ( V_9 , L_2 ) ;
return - V_21 ;
}
memmove ( V_6 -> V_22 , V_3 , V_4 ) ;
F_6 ( V_6 -> V_23 , V_6 -> V_13 + V_24 ) ;
F_7 ( & V_6 -> V_25 ) ;
V_11 = F_2 ( V_6 -> V_13 + V_18 ) ;
V_11 &= ~ ( V_26 | V_27 ) ;
F_8 ( V_11 | V_19 | V_28 | V_4 ,
V_6 -> V_13 + V_18 ) ;
F_9 ( & V_6 -> V_25 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_29 )
{
struct V_6 * V_6 = V_29 -> V_7 ;
return F_11 ( V_6 -> V_10 ) ;
}
static
void F_12 ( struct V_6 * V_6 )
{
T_2 V_11 ;
F_6 ( V_6 -> V_30 , V_6 -> V_13 + V_31 ) ;
F_7 ( & V_6 -> V_25 ) ;
V_11 = F_2 ( V_6 -> V_13 + V_18 ) & ~ V_19 ;
F_8 ( V_11 | V_26 , V_6 -> V_13 + V_18 ) ;
F_9 ( & V_6 -> V_25 ) ;
}
static void F_13 ( struct V_32 * V_33 )
{
struct V_6 * V_6 = F_14 ( V_33 , struct V_6 , V_34 ) ;
T_1 V_35 ;
T_3 V_36 ;
V_36 = F_15 ( V_6 -> V_13 + V_31 ) ;
V_35 = V_36 & V_37 ;
F_16 ( V_6 -> V_1 , V_6 -> V_38 , V_35 ) ;
F_12 ( V_6 ) ;
}
static
T_4 F_17 ( int V_39 , void * V_40 )
{
struct V_6 * V_6 = V_40 ;
struct V_8 * V_9 = & V_6 -> V_10 -> V_9 ;
T_2 V_41 ;
V_41 = F_2 ( V_6 -> V_13 + V_14 ) ;
if ( ! ( V_41 & V_42 ) )
return V_43 ;
F_8 ( V_41 & V_42 , V_6 -> V_13 + V_14 ) ;
if ( V_41 & V_44 ) {
F_3 ( V_9 , L_3 ) ;
goto V_45;
}
if ( V_41 & V_46 )
F_18 ( & V_6 -> V_34 ) ;
if ( V_41 & V_47 )
F_19 ( & V_6 -> V_17 ) ;
V_45:
return V_48 ;
}
static
int F_20 ( struct V_6 * V_6 )
{
int V_5 = 0 ;
struct V_8 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_10 * V_10 = V_6 -> V_10 ;
V_6 -> V_49 = V_10 -> V_50 . V_51 ;
V_6 -> V_52 = V_10 -> V_50 . V_53 - V_10 -> V_50 . V_51 + 1 ;
V_5 = - V_54 ;
if ( F_21 ( V_6 -> V_49 , V_6 -> V_52 , V_55 ) == NULL ) {
F_3 ( V_9 , L_4 ,
V_6 -> V_52 , V_6 -> V_49 , V_5 ) ;
goto V_56;
}
V_6 -> V_13 = F_22 ( V_6 -> V_49 , V_6 -> V_52 ) ;
if ( V_6 -> V_13 == NULL ) {
F_3 ( V_9 , L_5 ,
V_6 -> V_52 , V_6 -> V_49 , V_5 ) ;
goto V_57;
}
V_5 = F_23 ( V_10 -> V_39 , F_17 , V_58 ,
V_55 , V_6 ) ;
if ( V_5 < 0 ) {
F_3 ( V_9 , L_6 ,
V_10 -> V_39 , V_5 ) ;
goto V_59;
}
V_5 = - V_60 ;
V_6 -> V_22 = F_24 ( & V_10 -> V_9 , V_61 ,
& V_6 -> V_23 , V_62 ) ;
if ( V_6 -> V_22 == NULL ) {
F_3 ( V_9 , L_7 ) ;
goto V_63;
}
V_6 -> V_38 = F_24 ( & V_10 -> V_9 , V_61 ,
& V_6 -> V_30 , V_62 ) ;
if ( V_6 -> V_38 == NULL ) {
F_3 ( V_9 , L_8 ) ;
goto V_64;
}
return 0 ;
V_64:
F_25 ( & V_10 -> V_9 , V_61 , V_6 -> V_22 ,
V_6 -> V_23 ) ;
V_63:
F_26 ( V_10 -> V_39 , V_6 ) ;
V_59:
F_27 ( V_6 -> V_13 ) ;
V_57:
F_28 ( V_6 -> V_49 , V_6 -> V_52 ) ;
V_56:
return V_5 ;
}
static
void F_29 ( struct V_6 * V_6 )
{
struct V_10 * V_10 = V_6 -> V_10 ;
F_25 ( & V_10 -> V_9 , V_61 , V_6 -> V_38 ,
V_6 -> V_30 ) ;
F_25 ( & V_10 -> V_9 , V_61 , V_6 -> V_22 ,
V_6 -> V_23 ) ;
F_26 ( V_10 -> V_39 , V_6 ) ;
F_27 ( V_6 -> V_13 ) ;
F_28 ( V_6 -> V_49 , V_6 -> V_52 ) ;
}
static int F_30 ( struct V_1 * V_29 )
{
struct V_6 * V_6 = V_29 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 -> V_9 ;
F_8 ( V_65 , V_6 -> V_13 + V_18 ) ;
if ( F_31 ( V_9 , V_6 -> V_13 + V_18 , V_65 , 0 ,
5000 , L_9 ) < 0 )
return - V_54 ;
F_8 ( 0 , V_6 -> V_13 + V_66 ) ;
F_8 ( V_67 , V_6 -> V_13 + V_18 ) ;
if ( F_31 ( V_9 , V_6 -> V_13 + V_14 , V_15 , 0 ,
5000 , L_10 ) < 0 )
return - V_21 ;
F_12 ( V_6 ) ;
F_8 ( V_68 , V_6 -> V_13 + V_66 ) ;
return 0 ;
}
static
void F_32 ( struct V_1 * V_29 )
{
struct V_6 * V_6 = V_29 -> V_7 ;
struct V_10 * V_10 = V_6 -> V_10 ;
F_8 ( 0 , V_6 -> V_13 + V_66 ) ;
F_33 ( & V_6 -> V_34 ) ;
F_8 ( 0 , V_6 -> V_13 + V_18 ) ;
F_31 ( & V_10 -> V_9 , V_6 -> V_13 + V_14 ,
V_15 , V_15 , 100 , L_11 ) ;
}
static void F_34 ( struct V_6 * V_6 )
{
F_35 ( & V_6 -> V_25 ) ;
F_36 ( & V_6 -> V_17 ) ;
F_37 ( & V_6 -> V_34 , F_13 ) ;
}
static
int F_38 ( struct V_10 * V_10 )
{
int V_5 ;
struct V_1 * V_1 ;
struct V_6 * V_6 ;
struct V_8 * V_9 = & V_10 -> V_9 ;
V_5 = - V_60 ;
V_1 = F_39 () ;
if ( V_1 == NULL ) {
F_3 ( V_9 , L_12 ) ;
goto V_69;
}
V_6 = F_40 ( sizeof( * V_6 ) , V_62 ) ;
if ( V_6 == NULL ) {
F_3 ( V_9 , L_13 ) ;
goto V_70;
}
F_34 ( V_6 ) ;
V_6 -> V_10 = V_10 ;
V_5 = F_20 ( V_6 ) ;
if ( V_5 < 0 ) {
F_3 ( V_9 , L_14 , V_5 ) ;
goto V_71;
}
V_6 -> V_1 = V_1 ;
V_1 -> V_72 = V_73 ;
V_1 -> V_3 = F_1 ;
V_1 -> V_74 = F_10 ;
V_1 -> V_51 = F_30 ;
V_1 -> V_75 = F_32 ;
V_5 = F_41 ( V_1 , V_9 , V_6 ) ;
if ( V_5 < 0 )
goto V_76;
F_42 ( V_10 , V_6 ) ;
return 0 ;
V_76:
F_29 ( V_6 ) ;
V_71:
F_43 ( V_6 ) ;
V_70:
F_44 ( V_1 ) ;
V_69:
return V_5 ;
}
static void F_45 ( struct V_10 * V_10 )
{
struct V_6 * V_6 = F_46 ( V_10 ) ;
struct V_1 * V_1 = V_6 -> V_1 ;
F_42 ( V_10 , NULL ) ;
F_47 ( V_1 ) ;
F_29 ( V_6 ) ;
F_43 ( V_6 ) ;
F_44 ( V_1 ) ;
}
static int F_48 ( struct V_10 * V_77 )
{
struct V_6 * V_6 = F_46 ( V_77 ) ;
struct V_1 * V_1 = V_6 -> V_1 ;
F_49 ( V_1 ) ;
return 0 ;
}
static int F_50 ( struct V_10 * V_77 )
{
struct V_6 * V_6 = F_46 ( V_77 ) ;
struct V_1 * V_1 = V_6 -> V_1 ;
return F_51 ( V_1 ) ;
}
static int T_5 F_52 ( void )
{
return F_53 ( & V_78 ) ;
}
static void T_6 F_54 ( void )
{
F_55 ( & V_78 ) ;
}
