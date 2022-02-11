static int F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 ) {
if ( F_2 ( V_4 -> V_5 -> V_6 ) )
F_3 ( V_4 -> V_5 -> V_6 , 0 ) ;
if ( F_2 ( V_4 -> V_5 -> V_7 ) )
F_3 ( V_4 -> V_5 -> V_7 , 0 ) ;
if ( V_4 -> V_8 && F_4 ( V_4 ) )
F_5 ( V_4 -> V_8 ) ;
} else {
if ( V_4 -> V_8 && F_6 ( V_4 ) )
F_7 ( V_4 -> V_8 ) ;
if ( F_2 ( V_4 -> V_5 -> V_7 ) )
F_3 ( V_4 -> V_5 -> V_7 , 1 ) ;
if ( F_2 ( V_4 -> V_5 -> V_6 ) )
F_3 ( V_4 -> V_5 -> V_6 , 1 ) ;
}
if ( V_4 -> V_8 )
F_8 ( V_4 , V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_3 * V_4 ;
struct V_11 * V_5 = V_10 -> V_12 . V_13 ;
int V_14 = 0 ;
int V_15 = 0 ;
if ( ! V_5 ) {
F_10 ( L_1 , V_16 ) ;
return - V_17 ;
}
if ( ! V_5 -> V_18 || ( ! F_2 ( V_5 -> V_7 ) &&
! F_2 ( V_5 -> V_6 ) ) ) {
F_10 ( L_2 , V_16 ) ;
return - V_17 ;
}
V_4 = F_11 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return - V_20 ;
V_4 -> V_5 = V_5 ;
V_15 = strlen ( V_5 -> V_18 ) ;
V_4 -> V_21 = F_11 ( V_15 + 7 , V_19 ) ;
if ( ! V_4 -> V_21 ) {
V_14 = - V_20 ;
goto V_22;
}
V_4 -> V_23 = F_11 ( V_15 + 10 , V_19 ) ;
if ( ! V_4 -> V_23 ) {
V_14 = - V_20 ;
goto V_24;
}
snprintf ( V_4 -> V_21 , V_15 + 6 , L_3 , V_5 -> V_18 ) ;
snprintf ( V_4 -> V_23 , V_15 + 9 , L_4 , V_5 -> V_18 ) ;
if ( V_5 -> V_25 ) {
V_4 -> V_8 = F_12 ( & V_10 -> V_12 , V_5 -> V_25 ) ;
if ( F_13 ( V_4 -> V_8 ) ) {
F_10 ( L_5 , V_16 ) ;
goto V_26;
}
}
if ( F_2 ( V_5 -> V_7 ) ) {
V_14 = F_14 ( V_5 -> V_7 , V_4 -> V_21 ) ;
if ( V_14 ) {
F_10 ( L_6 , V_16 ) ;
goto V_27;
}
}
if ( F_2 ( V_5 -> V_6 ) ) {
V_14 = F_14 ( V_5 -> V_6 , V_4 -> V_23 ) ;
if ( V_14 ) {
F_10 ( L_7 , V_16 ) ;
goto V_28;
}
}
V_4 -> V_29 = F_15 ( V_5 -> V_18 , & V_10 -> V_12 , V_5 -> type ,
& V_30 , V_4 ) ;
if ( ! V_4 -> V_29 )
goto V_31;
V_14 = F_16 ( V_4 -> V_29 ) ;
if ( V_14 < 0 )
goto V_32;
F_17 ( V_10 , V_4 ) ;
F_18 ( & V_10 -> V_12 , L_8 , V_5 -> V_18 ) ;
return 0 ;
V_32:
F_19 ( V_4 -> V_29 ) ;
V_31:
if ( F_2 ( V_5 -> V_6 ) )
F_20 ( V_5 -> V_6 ) ;
V_28:
if ( F_2 ( V_5 -> V_7 ) )
F_20 ( V_5 -> V_7 ) ;
V_27:
if ( V_4 -> V_8 )
F_21 ( V_4 -> V_8 ) ;
V_26:
F_22 ( V_4 -> V_23 ) ;
V_24:
F_22 ( V_4 -> V_21 ) ;
V_22:
F_22 ( V_4 ) ;
return V_14 ;
}
static int F_23 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_24 ( V_10 ) ;
F_25 ( V_4 -> V_29 ) ;
F_19 ( V_4 -> V_29 ) ;
if ( F_2 ( V_4 -> V_5 -> V_6 ) )
F_20 ( V_4 -> V_5 -> V_6 ) ;
if ( F_2 ( V_4 -> V_5 -> V_7 ) )
F_20 ( V_4 -> V_5 -> V_7 ) ;
if ( V_4 -> V_8 && F_4 ( V_4 ) )
F_5 ( V_4 -> V_8 ) ;
if ( V_4 -> V_8 )
F_21 ( V_4 -> V_8 ) ;
F_22 ( V_4 -> V_23 ) ;
F_22 ( V_4 -> V_21 ) ;
F_22 ( V_4 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
return F_27 ( & V_33 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_33 ) ;
}
