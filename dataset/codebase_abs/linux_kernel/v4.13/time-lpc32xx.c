static T_1 T_2 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static unsigned long F_3 ( void )
{
return F_2 ( V_1 ) ;
}
static int F_4 ( unsigned long V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_5 ( V_4 , struct V_5 , V_4 ) ;
F_6 ( V_7 , V_6 -> V_8 + V_9 ) ;
F_6 ( V_2 , V_6 -> V_8 + V_10 ) ;
F_6 ( V_11 , V_6 -> V_8 + V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_5 ( V_4 , struct V_5 , V_4 ) ;
F_6 ( 0 , V_6 -> V_8 + V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_5 ( V_4 , struct V_5 , V_4 ) ;
F_6 ( 0 , V_6 -> V_8 + V_9 ) ;
F_6 ( V_12 | V_13 |
V_14 , V_6 -> V_8 + V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_5 ( V_4 , struct V_5 , V_4 ) ;
F_6 ( V_12 | V_13 ,
V_6 -> V_8 + V_15 ) ;
F_6 ( V_7 , V_6 -> V_8 + V_9 ) ;
F_6 ( V_6 -> V_16 , V_6 -> V_8 + V_10 ) ;
F_6 ( V_11 , V_6 -> V_8 + V_9 ) ;
return 0 ;
}
static T_3 F_10 ( int V_17 , void * V_18 )
{
struct V_5 * V_6 = V_18 ;
F_6 ( V_19 , V_6 -> V_8 + V_20 ) ;
V_6 -> V_4 . V_21 ( & V_6 -> V_4 ) ;
return V_22 ;
}
static int T_4 F_11 ( struct V_23 * V_24 )
{
void T_5 * V_8 ;
unsigned long V_25 ;
struct V_26 * V_26 ;
int V_27 ;
V_26 = F_12 ( V_24 , L_1 ) ;
if ( F_13 ( V_26 ) ) {
F_14 ( L_2 , F_15 ( V_26 ) ) ;
return F_15 ( V_26 ) ;
}
V_27 = F_16 ( V_26 ) ;
if ( V_27 ) {
F_14 ( L_3 , V_27 ) ;
goto V_28;
}
V_8 = F_17 ( V_24 , 0 ) ;
if ( ! V_8 ) {
F_14 ( L_4 ) ;
V_27 = - V_29 ;
goto V_30;
}
F_6 ( V_7 , V_8 + V_9 ) ;
F_6 ( 0 , V_8 + V_31 ) ;
F_6 ( 0 , V_8 + V_15 ) ;
F_6 ( 0 , V_8 + V_32 ) ;
F_6 ( V_11 , V_8 + V_9 ) ;
V_25 = F_18 ( V_26 ) ;
V_27 = F_19 ( V_8 + V_33 , L_5 ,
V_25 , 300 , 32 , V_34 ) ;
if ( V_27 ) {
F_14 ( L_6 , V_27 ) ;
goto V_35;
}
V_1 = V_8 + V_33 ;
V_36 . V_37 = V_25 ;
F_20 ( & V_36 ) ;
F_21 ( F_1 , 32 , V_25 ) ;
return 0 ;
V_35:
F_22 ( V_8 ) ;
V_30:
F_23 ( V_26 ) ;
V_28:
F_24 ( V_26 ) ;
return V_27 ;
}
static int T_4 F_25 ( struct V_23 * V_24 )
{
void T_5 * V_8 ;
unsigned long V_25 ;
struct V_26 * V_26 ;
int V_27 , V_17 ;
V_26 = F_12 ( V_24 , L_1 ) ;
if ( F_13 ( V_26 ) ) {
F_14 ( L_2 , F_15 ( V_26 ) ) ;
return F_15 ( V_26 ) ;
}
V_27 = F_16 ( V_26 ) ;
if ( V_27 ) {
F_14 ( L_3 , V_27 ) ;
goto V_28;
}
V_8 = F_17 ( V_24 , 0 ) ;
if ( ! V_8 ) {
F_14 ( L_4 ) ;
V_27 = - V_29 ;
goto V_30;
}
V_17 = F_26 ( V_24 , 0 ) ;
if ( ! V_17 ) {
F_14 ( L_7 ) ;
V_27 = - V_38 ;
goto V_39;
}
F_6 ( 0 , V_8 + V_9 ) ;
F_6 ( 0 , V_8 + V_31 ) ;
F_6 ( 0 , V_8 + V_32 ) ;
F_6 ( V_19 , V_8 + V_20 ) ;
V_25 = F_18 ( V_26 ) ;
V_40 . V_8 = V_8 ;
V_40 . V_16 = F_27 ( V_25 , V_41 ) ;
F_28 ( & V_40 . V_4 ,
V_25 , 1 , - 1 ) ;
V_27 = F_29 ( V_17 , F_10 ,
V_42 | V_43 , L_8 ,
& V_40 ) ;
if ( V_27 ) {
F_14 ( L_9 ) ;
goto V_39;
}
return 0 ;
V_39:
F_22 ( V_8 ) ;
V_30:
F_23 ( V_26 ) ;
V_28:
F_24 ( V_26 ) ;
return V_27 ;
}
static int T_4 F_30 ( struct V_23 * V_24 )
{
static int V_44 , V_45 ;
int V_27 = 0 ;
if ( ! V_44 ) {
V_27 = F_11 ( V_24 ) ;
if ( ! V_27 ) {
V_44 = 1 ;
return 0 ;
}
}
if ( ! V_45 ) {
V_27 = F_25 ( V_24 ) ;
if ( ! V_27 ) {
V_45 = 1 ;
return 0 ;
}
}
return V_27 ;
}
