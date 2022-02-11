static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
void T_1 * V_6 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_9 * V_10 ;
V_5 = F_2 ( V_2 , V_11 , 0 ) ;
if ( ! V_5 )
return - V_12 ;
if ( ! F_3 ( V_5 -> V_13 , F_4 ( V_5 ) , V_2 -> V_14 ) ) {
F_5 ( L_1
L_2 ,
V_15 , ( unsigned int ) V_5 -> V_13 ) ;
return - V_16 ;
}
V_6 = F_6 ( V_5 -> V_13 , F_4 ( V_5 ) ) ;
if ( ! V_6 ) {
F_5 ( L_3 , V_15 ) ;
V_3 = - V_17 ;
goto V_18;
}
V_10 = V_2 -> V_19 . V_20 ;
if ( V_10 -> V_21 ) {
V_3 = V_10 -> V_21 ( V_2 ) ;
if ( F_7 ( V_3 ) )
goto V_22;
}
V_8 = F_8 ( & ( V_2 -> V_19 ) , V_10 , V_6 ) ;
if ( ! V_8 ) {
F_5 ( L_4 , V_15 ) ;
goto V_22;
}
V_8 -> V_19 -> V_23 = F_9 ( V_2 , L_5 ) ;
if ( V_8 -> V_19 -> V_23 == - V_24 ) {
F_5 ( L_6
L_7 , V_15 ) ;
V_3 = - V_24 ;
goto V_22;
}
V_8 -> V_25 = F_9 ( V_2 , L_8 ) ;
if ( V_8 -> V_25 == - V_24 )
V_8 -> V_25 = V_8 -> V_19 -> V_23 ;
F_10 ( V_2 , V_8 -> V_19 ) ;
F_11 ( L_9 ) ;
return 0 ;
V_22:
F_12 ( V_6 ) ;
F_10 ( V_2 , NULL ) ;
V_18:
F_13 ( V_5 -> V_13 , F_4 ( V_5 ) ) ;
return V_3 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_15 ( V_2 ) ;
struct V_7 * V_8 = F_16 ( V_27 ) ;
struct V_4 * V_5 ;
int V_3 = F_17 ( V_27 ) ;
if ( V_8 -> V_28 -> exit )
V_8 -> V_28 -> exit ( V_2 ) ;
if ( V_8 -> V_28 -> exit )
V_8 -> V_28 -> exit ( V_2 ) ;
F_10 ( V_2 , NULL ) ;
F_12 ( ( void * ) V_8 -> V_29 ) ;
V_5 = F_2 ( V_2 , V_11 , 0 ) ;
F_13 ( V_5 -> V_13 , F_4 ( V_5 ) ) ;
return V_3 ;
}
static int F_18 ( struct V_30 * V_19 )
{
struct V_26 * V_27 = F_19 ( V_19 ) ;
return F_20 ( V_27 ) ;
}
static int F_21 ( struct V_30 * V_19 )
{
struct V_26 * V_27 = F_19 ( V_19 ) ;
return F_22 ( V_27 ) ;
}
int F_23 ( struct V_30 * V_19 )
{
struct V_26 * V_27 = F_19 ( V_19 ) ;
return F_24 ( V_27 ) ;
}
int F_25 ( struct V_30 * V_19 )
{
struct V_26 * V_27 = F_19 ( V_19 ) ;
return F_26 ( V_27 ) ;
}
