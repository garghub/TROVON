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
static int F_8 ( struct V_20 * V_21 , struct V_22 * V_12 )
{
struct V_23 V_24 ;
snprintf ( V_24 . type , V_25 , L_1 , L_2 ) ;
V_24 . V_26 = V_12 -> V_14 . V_26 ;
if ( F_9 ( V_21 , V_27 ,
sizeof( struct V_23 ) , & V_24 ) )
goto V_28;
return 0 ;
V_28:
return - V_29 ;
}
static int F_8 ( struct V_20 * V_21 , struct V_22 * V_12 )
{
return - V_30 ;
}
static void F_10 ( struct V_31 * V_32 , struct V_22 * V_12 )
{
F_11 ( V_32 , L_3 ) ;
F_11 ( V_32 , L_4 , V_12 -> V_14 . V_26 ) ;
}
static unsigned int F_12 ( struct V_22 * V_12 , T_2 type ,
T_2 V_10 )
{
return V_12 -> V_33 ;
}
int F_13 ( void )
{
struct V_1 * V_34 ;
int V_6 ;
F_14 ( & V_35 ) ;
if ( ! V_36 ) {
V_34 = F_15 ( L_5 , 0 , 0 ) ;
V_6 = F_16 ( V_34 ) ;
if ( F_17 ( V_34 ) )
goto V_37;
V_6 = F_18 ( V_34 , NULL , F_19 ( V_34 ) ) ;
if ( V_6 ) {
F_20 ( V_34 ) ;
goto V_37;
}
V_36 = V_34 ;
}
V_38 ++ ;
V_6 = 0 ;
V_37:
F_21 ( & V_35 ) ;
return V_6 ;
}
void F_22 ( void )
{
F_14 ( & V_35 ) ;
if ( ! -- V_38 ) {
F_20 ( V_36 ) ;
V_36 = NULL ;
}
F_21 ( & V_35 ) ;
}
