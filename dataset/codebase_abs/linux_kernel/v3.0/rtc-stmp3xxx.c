static void F_1 ( struct V_1 * V_2 )
{
while ( F_2 ( V_2 -> V_3 + V_4 ) &
F_3 ( 0x80 , V_5 ) )
F_4 () ;
}
static int F_5 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_1 ( V_2 ) ;
F_7 ( F_2 ( V_2 -> V_3 + V_10 ) , V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 , unsigned long V_11 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_9 ( V_11 , V_2 -> V_3 + V_10 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static T_1 F_10 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
T_2 V_14 ;
T_2 V_15 = 0 ;
V_14 = F_2 ( V_2 -> V_3 + V_16 ) &
( V_17 | V_18 ) ;
if ( V_14 & V_17 ) {
F_11 ( V_17 ,
V_2 -> V_3 + V_16 ) ;
V_15 |= V_19 | V_20 ;
}
if ( V_14 & V_18 ) {
F_11 ( V_18 ,
V_2 -> V_3 + V_16 ) ;
if ( ++ V_2 -> V_21 % 1000 == 0 ) {
V_15 |= V_22 | V_20 ;
V_2 -> V_21 = 0 ;
}
}
if ( V_15 )
F_12 ( V_2 -> V_23 , 1 , V_15 ) ;
return V_24 ;
}
static int F_13 ( struct V_6 * V_7 , unsigned int V_25 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
void T_3 * V_26 = V_2 -> V_3 + V_27 ,
* V_28 = V_2 -> V_3 + V_16 ;
if ( V_25 ) {
F_14 ( V_29 |
V_30 , V_26 ) ;
F_14 ( V_31 , V_28 ) ;
} else {
F_11 ( V_29 |
V_30 , V_26 ) ;
F_11 ( V_31 , V_28 ) ;
}
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_7 ( F_2 ( V_2 -> V_3 + V_34 ) , & V_33 -> time ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , struct V_32 * V_33 )
{
unsigned long V_11 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_17 ( & V_33 -> time , & V_11 ) ;
F_9 ( V_11 , V_2 -> V_3 + V_34 ) ;
return 0 ;
}
static int F_18 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
if ( ! V_2 )
return 0 ;
F_11 ( V_37 | V_31 ,
V_2 -> V_3 + V_16 ) ;
F_20 ( V_2 -> V_38 , & V_36 -> V_7 ) ;
F_20 ( V_2 -> V_39 , & V_36 -> V_7 ) ;
F_21 ( V_2 -> V_23 ) ;
F_22 ( V_2 -> V_3 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_40 * V_41 ;
int V_42 ;
V_2 = F_25 ( sizeof *V_2 , V_43 ) ;
if ( ! V_2 )
return - V_44 ;
V_41 = F_26 ( V_36 , V_45 , 0 ) ;
if ( ! V_41 ) {
F_27 ( & V_36 -> V_7 , L_1 ) ;
V_42 = - V_46 ;
goto V_47;
}
V_2 -> V_3 = F_28 ( V_41 -> V_48 , F_29 ( V_41 ) ) ;
if ( ! V_2 -> V_3 ) {
F_27 ( & V_36 -> V_7 , L_2 ) ;
V_42 = - V_49 ;
goto V_47;
}
V_2 -> V_38 = F_30 ( V_36 , 0 ) ;
V_2 -> V_39 = F_30 ( V_36 , 1 ) ;
if ( ! ( F_2 ( V_4 + V_2 -> V_3 ) &
V_50 ) ) {
F_27 ( & V_36 -> V_7 , L_3 ) ;
V_42 = - V_51 ;
goto V_52;
}
F_31 ( V_2 -> V_3 , true ) ;
F_11 ( V_29 |
V_30 |
V_53 ,
V_2 -> V_3 + V_27 ) ;
V_2 -> V_23 = F_32 ( V_36 -> V_54 , & V_36 -> V_7 ,
& V_55 , V_56 ) ;
if ( F_33 ( V_2 -> V_23 ) ) {
V_42 = F_34 ( V_2 -> V_23 ) ;
goto V_52;
}
V_2 -> V_21 = 0 ;
V_42 = F_35 ( V_2 -> V_38 , F_10 ,
V_57 , L_4 , & V_36 -> V_7 ) ;
if ( V_42 ) {
F_27 ( & V_36 -> V_7 , L_5 ,
V_2 -> V_38 ) ;
goto V_58;
}
V_42 = F_35 ( V_2 -> V_39 , F_10 ,
V_57 , L_6 , & V_36 -> V_7 ) ;
if ( V_42 ) {
F_27 ( & V_36 -> V_7 , L_5 ,
V_2 -> V_39 ) ;
goto V_59;
}
F_36 ( V_36 , V_2 ) ;
return 0 ;
V_59:
F_20 ( V_2 -> V_38 , & V_36 -> V_7 ) ;
V_58:
F_11 ( V_37 | V_31 ,
V_2 -> V_3 + V_16 ) ;
F_21 ( V_2 -> V_23 ) ;
V_52:
F_22 ( V_2 -> V_3 ) ;
V_47:
F_23 ( V_2 ) ;
return V_42 ;
}
static int F_37 ( struct V_35 * V_7 , T_4 V_60 )
{
return 0 ;
}
static int F_38 ( struct V_35 * V_7 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
F_31 ( V_2 -> V_3 , true ) ;
F_11 ( V_29 |
V_30 |
V_53 ,
V_2 -> V_3 + V_27 ) ;
return 0 ;
}
static int T_5 F_39 ( void )
{
return F_40 ( & V_61 ) ;
}
static void T_6 F_41 ( void )
{
F_42 ( & V_61 ) ;
}
