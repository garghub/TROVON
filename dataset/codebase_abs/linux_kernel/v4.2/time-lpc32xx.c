static T_1 T_2 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static int F_3 ( unsigned long V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_4 ( V_4 , struct V_5 , V_4 ) ;
F_5 ( V_7 , V_6 -> V_8 + V_9 ) ;
F_5 ( V_2 , V_6 -> V_8 + V_10 ) ;
F_5 ( V_11 , V_6 -> V_8 + V_9 ) ;
return 0 ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_4 ( V_4 , struct V_5 , V_4 ) ;
F_5 ( 0 , V_6 -> V_8 + V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 )
{
return F_6 ( V_4 ) ;
}
static T_3 F_8 ( int V_12 , void * V_13 )
{
struct V_5 * V_6 = V_13 ;
F_5 ( V_14 , V_6 -> V_8 + V_15 ) ;
V_6 -> V_4 . V_16 ( & V_6 -> V_4 ) ;
return V_17 ;
}
static int T_4 F_9 ( struct V_18 * V_19 )
{
void T_5 * V_8 ;
unsigned long V_20 ;
struct V_21 * V_21 ;
int V_22 ;
V_21 = F_10 ( V_19 , L_1 ) ;
if ( F_11 ( V_21 ) ) {
F_12 ( L_2 , F_13 ( V_21 ) ) ;
return F_13 ( V_21 ) ;
}
V_22 = F_14 ( V_21 ) ;
if ( V_22 ) {
F_12 ( L_3 , V_22 ) ;
goto V_23;
}
V_8 = F_15 ( V_19 , 0 ) ;
if ( ! V_8 ) {
F_12 ( L_4 ) ;
V_22 = - V_24 ;
goto V_25;
}
F_5 ( V_7 , V_8 + V_9 ) ;
F_5 ( 0 , V_8 + V_10 ) ;
F_5 ( 0 , V_8 + V_26 ) ;
F_5 ( 0 , V_8 + V_27 ) ;
F_5 ( V_11 , V_8 + V_9 ) ;
V_20 = F_16 ( V_21 ) ;
V_22 = F_17 ( V_8 + V_28 , L_5 ,
V_20 , 300 , 32 , V_29 ) ;
if ( V_22 ) {
F_12 ( L_6 , V_22 ) ;
goto V_30;
}
V_1 = V_8 + V_28 ;
F_18 ( F_1 , 32 , V_20 ) ;
return 0 ;
V_30:
F_19 ( V_8 ) ;
V_25:
F_20 ( V_21 ) ;
V_23:
F_21 ( V_21 ) ;
return V_22 ;
}
static int T_4 F_22 ( struct V_18 * V_19 )
{
void T_5 * V_8 ;
unsigned long V_20 ;
struct V_21 * V_21 ;
int V_22 , V_12 ;
V_21 = F_10 ( V_19 , L_1 ) ;
if ( F_11 ( V_21 ) ) {
F_12 ( L_2 , F_13 ( V_21 ) ) ;
return F_13 ( V_21 ) ;
}
V_22 = F_14 ( V_21 ) ;
if ( V_22 ) {
F_12 ( L_3 , V_22 ) ;
goto V_23;
}
V_8 = F_15 ( V_19 , 0 ) ;
if ( ! V_8 ) {
F_12 ( L_4 ) ;
V_22 = - V_24 ;
goto V_25;
}
V_12 = F_23 ( V_19 , 0 ) ;
if ( ! V_12 ) {
F_12 ( L_7 ) ;
V_22 = - V_31 ;
goto V_32;
}
F_5 ( 0 , V_8 + V_9 ) ;
F_5 ( 0 , V_8 + V_27 ) ;
F_5 ( V_14 , V_8 + V_15 ) ;
F_5 ( 1 , V_8 + V_33 ) ;
F_5 ( V_34 | V_35 |
V_36 , V_8 + V_26 ) ;
V_20 = F_16 ( V_21 ) ;
V_37 . V_8 = V_8 ;
F_24 ( & V_37 . V_4 ,
V_20 , 1 , - 1 ) ;
V_22 = F_25 ( V_12 , F_8 ,
V_38 | V_39 , L_8 ,
& V_37 ) ;
if ( V_22 ) {
F_12 ( L_9 ) ;
goto V_32;
}
return 0 ;
V_32:
F_19 ( V_8 ) ;
V_25:
F_20 ( V_21 ) ;
V_23:
F_21 ( V_21 ) ;
return V_22 ;
}
static void T_4 F_26 ( struct V_18 * V_19 )
{
static int V_40 , V_41 ;
int V_22 ;
if ( ! V_40 ) {
V_22 = F_9 ( V_19 ) ;
if ( ! V_22 ) {
V_40 = 1 ;
return;
}
}
if ( ! V_41 ) {
V_22 = F_22 ( V_19 ) ;
if ( ! V_22 ) {
V_41 = 1 ;
return;
}
}
}
