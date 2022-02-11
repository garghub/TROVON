static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
void * V_5 = V_4 -> V_5 ;
F_3 ( 0 , V_5 + V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
void * V_5 = V_4 -> V_5 ;
F_3 ( V_4 -> V_7 , V_5 + V_8 ) ;
F_3 ( V_9 | V_10 , V_5 + V_6 ) ;
return 0 ;
}
static int F_5 ( unsigned long V_11 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_11 , V_4 -> V_5 + V_8 ) ;
F_3 ( V_9 | V_12 | V_10 ,
V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static T_1 F_6 ( int V_13 , void * V_14 )
{
struct V_3 * V_4 = V_14 ;
F_3 ( 0 , V_4 -> V_5 + V_15 ) ;
V_4 -> V_2 . V_16 ( & V_4 -> V_2 ) ;
return V_17 ;
}
static int T_2 F_7 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = & V_20 ;
struct V_21 * V_21 ;
struct V_22 * V_23 ;
unsigned long V_24 , V_25 ;
int V_13 , V_26 , V_27 , V_28 = 1 ;
V_21 = F_8 ( V_19 , 0 ) ;
if ( F_9 ( V_21 ) ) {
V_26 = F_10 ( V_21 ) ;
F_11 ( L_1 , V_26 ) ;
goto V_29;
}
V_26 = F_12 ( V_21 ) ;
if ( V_26 ) {
F_11 ( L_2 ,
V_26 ) ;
goto V_30;
}
V_24 = F_13 ( V_21 ) ;
V_23 = F_14 ( V_19 , NULL ) ;
if ( ! F_9 ( V_23 ) ) {
F_15 ( V_23 ) ;
F_16 ( V_23 ) ;
}
V_4 -> V_5 = F_17 ( V_19 , 0 ) ;
if ( ! V_4 -> V_5 ) {
V_26 = - V_31 ;
F_11 ( L_3 ) ;
goto V_32;
}
V_13 = F_18 ( V_19 , 0 ) ;
if ( ! V_13 ) {
V_26 = - V_33 ;
F_11 ( L_4 , V_19 -> V_34 ) ;
goto V_35;
}
F_3 ( ~ 0U , V_4 -> V_5 + V_8 ) ;
V_25 = F_19 ( V_4 -> V_5 + V_8 ) ;
if ( V_25 == ~ 0U ) {
V_28 = 1 ;
V_27 = 32 ;
} else {
V_28 = 1024 ;
V_27 = 16 ;
}
F_3 ( 0 , V_4 -> V_5 + V_8 ) ;
F_3 ( V_28 - 1 , V_4 -> V_5 + V_36 ) ;
F_3 ( V_37 , V_4 -> V_5 + V_38 ) ;
F_3 ( V_39 , V_4 -> V_5 + V_40 ) ;
F_3 ( 0 , V_4 -> V_5 + V_15 ) ;
V_4 -> V_7 = F_20 ( V_24 , V_28 * V_41 ) ;
F_21 ( & V_4 -> V_2 ,
F_20 ( V_24 , V_28 ) ,
0x1 , V_25 ) ;
V_26 = F_22 ( V_13 , F_6 , V_42 ,
L_5 , V_4 ) ;
if ( V_26 ) {
F_11 ( L_6 , V_19 -> V_34 ) ;
goto V_35;
}
F_23 ( L_7 ,
V_19 -> V_34 , V_27 ) ;
return V_26 ;
V_35:
F_24 ( V_4 -> V_5 ) ;
V_32:
F_25 ( V_21 ) ;
V_30:
F_26 ( V_21 ) ;
V_29:
return V_26 ;
}
