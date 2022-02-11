static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
F_3 ( V_8 |
V_9 |
V_10 |
V_11 ,
V_4 -> V_6 + V_12 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
F_3 ( V_4 -> V_13 , V_4 -> V_6 + V_14 ) ;
F_3 ( V_8 |
V_9 |
V_11 ,
V_4 -> V_6 + V_12 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_6 ( unsigned long V_16 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
F_3 ( V_16 , V_4 -> V_6 + V_17 ) ;
F_3 ( V_15 , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static T_1 F_7 ( int V_18 , void * V_19 )
{
struct V_3 * V_4 = V_19 ;
F_3 ( V_20 , V_4 -> V_6 + V_21 ) ;
V_4 -> V_2 . V_22 ( & V_4 -> V_2 ) ;
return V_23 ;
}
static int T_2 F_8 ( struct V_24 * V_25 )
{
struct V_26 * V_26 ;
void T_3 * V_6 ;
unsigned long V_27 ;
int V_28 ;
V_26 = F_9 ( V_25 , 0 ) ;
if ( F_10 ( V_26 ) ) {
V_28 = F_11 ( V_26 ) ;
F_12 ( L_1 , V_28 ) ;
goto V_29;
}
V_28 = F_13 ( V_26 ) ;
if ( V_28 ) {
F_12 ( L_2 ,
V_28 ) ;
goto V_30;
}
V_27 = F_14 ( V_26 ) ;
V_6 = F_15 ( V_25 , 0 ) ;
if ( ! V_6 ) {
V_28 = - V_31 ;
F_12 ( L_3 ) ;
goto V_32;
}
F_3 ( V_8 |
V_9 |
V_33 , V_6 + V_12 ) ;
F_3 ( V_15 , V_6 + V_7 ) ;
V_28 = F_16 ( V_6 + V_17 , L_4 ,
F_17 ( V_27 , 1024 ) , 200 , 16 ,
V_34 ) ;
if ( V_28 ) {
F_12 ( L_5 , V_28 ) ;
goto V_35;
}
return 0 ;
V_35:
F_18 ( V_6 ) ;
V_32:
F_19 ( V_26 ) ;
V_30:
F_20 ( V_26 ) ;
V_29:
return V_28 ;
}
static int T_2 F_21 ( struct V_24 * V_25 )
{
struct V_26 * V_26 ;
void T_3 * V_6 ;
unsigned long V_27 ;
int V_18 ;
int V_28 ;
V_26 = F_9 ( V_25 , 0 ) ;
if ( F_10 ( V_26 ) ) {
V_28 = F_11 ( V_26 ) ;
F_12 ( L_6 , V_28 ) ;
goto V_29;
}
V_28 = F_13 ( V_26 ) ;
if ( V_28 ) {
F_12 ( L_7 ,
V_28 ) ;
goto V_30;
}
V_27 = F_14 ( V_26 ) ;
V_6 = F_15 ( V_25 , 0 ) ;
if ( ! V_6 ) {
V_28 = - V_31 ;
F_12 ( L_8 ) ;
goto V_32;
}
V_18 = F_22 ( V_25 , 0 ) ;
if ( ! V_18 ) {
V_28 = - V_36 ;
F_12 ( L_9 ) ;
goto V_37;
}
F_3 ( V_20 , V_6 + V_38 ) ;
V_39 . V_6 = V_6 ;
V_39 . V_13 = F_17 ( V_27 , 1024 * V_40 ) ;
F_23 ( & V_39 . V_2 ,
F_17 ( V_27 , 1024 ) ,
0xf , 0xffff ) ;
F_24 ( V_18 , & V_41 ) ;
return 0 ;
V_37:
F_18 ( V_6 ) ;
V_32:
F_19 ( V_26 ) ;
V_30:
F_20 ( V_26 ) ;
V_29:
return V_28 ;
}
static void T_2 F_25 ( struct V_24 * V_25 )
{
static int V_42 , V_43 ;
int V_28 ;
if ( ! V_42 ) {
V_28 = F_8 ( V_25 ) ;
if ( ! V_28 ) {
V_42 = 1 ;
return;
}
}
if ( ! V_43 ) {
V_28 = F_21 ( V_25 ) ;
if ( ! V_28 ) {
V_43 = 1 ;
return;
}
}
}
