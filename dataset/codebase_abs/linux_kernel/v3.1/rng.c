static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , unsigned int V_4 )
{
T_1 * V_5 = NULL ;
int V_6 ;
if ( ! V_3 && V_4 ) {
V_5 = F_2 ( V_4 , V_7 ) ;
if ( ! V_5 )
return - V_8 ;
F_3 ( V_5 , V_4 ) ;
V_3 = V_5 ;
}
V_6 = F_4 ( V_2 ) -> F_5 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_5 ) ;
return V_6 ;
}
static int F_7 ( struct V_9 * V_2 , T_2 type , T_2 V_10 )
{
struct V_11 * V_12 = & V_2 -> V_13 -> V_14 ;
struct V_15 * V_16 = & V_2 -> V_17 ;
V_16 -> V_18 = V_12 -> V_19 ;
V_16 -> F_5 = F_1 ;
return 0 ;
}
static void F_8 ( struct V_20 * V_21 , struct V_22 * V_12 )
{
F_9 ( V_21 , L_1 ) ;
F_9 ( V_21 , L_2 , V_12 -> V_14 . V_23 ) ;
}
static unsigned int F_10 ( struct V_22 * V_12 , T_2 type ,
T_2 V_10 )
{
return V_12 -> V_24 ;
}
int F_11 ( void )
{
struct V_1 * V_25 ;
int V_6 ;
F_12 ( & V_26 ) ;
if ( ! V_27 ) {
V_25 = F_13 ( L_3 , 0 , 0 ) ;
V_6 = F_14 ( V_25 ) ;
if ( F_15 ( V_25 ) )
goto V_28;
V_6 = F_16 ( V_25 , NULL , F_17 ( V_25 ) ) ;
if ( V_6 ) {
F_18 ( V_25 ) ;
goto V_28;
}
V_27 = V_25 ;
}
V_29 ++ ;
V_6 = 0 ;
V_28:
F_19 ( & V_26 ) ;
return V_6 ;
}
void F_20 ( void )
{
F_12 ( & V_26 ) ;
if ( ! -- V_29 ) {
F_18 ( V_27 ) ;
V_27 = NULL ;
}
F_19 ( & V_26 ) ;
}
