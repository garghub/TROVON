void F_1 ( struct V_1 * V_1 )
{
}
static T_1 F_2 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_6 , T_2 V_7 )
{
struct V_8 * V_8 = F_3 ( F_4 () ) ;
struct V_9 * V_10 ;
F_5 (notifier, &vpe->notify, list)
V_10 -> V_11 ( F_4 () ) ;
F_6 ( V_8 -> V_12 ) ;
V_8 -> V_13 = V_14 ;
return V_7 ;
}
static T_1 F_7 ( struct V_2 * V_15 , struct V_4 * V_5 ,
char * V_6 )
{
struct V_8 * V_8 = F_3 ( F_4 () ) ;
return sprintf ( V_6 , L_1 , V_8 -> V_16 ) ;
}
static T_1 F_8 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_6 , T_2 V_7 )
{
struct V_8 * V_8 = F_3 ( F_4 () ) ;
unsigned long V_17 ;
int V_18 ;
V_18 = F_9 ( V_6 , 0 , & V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_17 != 1 )
return - V_19 ;
V_8 -> V_16 = V_17 ;
return V_7 ;
}
static void F_10 ( struct V_2 * V_15 )
{
F_11 ( V_15 ) ;
}
int T_3 F_12 ( void )
{
struct V_8 * V_20 = NULL ;
struct V_1 * V_21 ;
int V_22 ;
if ( ! V_23 ) {
F_13 ( L_2 ) ;
return - V_24 ;
}
if ( F_14 () - F_4 () < 1 ) {
F_13 ( L_3
L_4 ) ;
return - V_24 ;
}
V_25 = F_15 ( 0 , V_26 , & V_27 ) ;
if ( V_25 < 0 ) {
F_13 ( L_5 ) ;
return V_25 ;
}
V_22 = F_16 ( & V_28 ) ;
if ( V_22 ) {
F_17 ( L_6 ) ;
goto V_29;
}
F_18 ( & V_30 ) ;
V_30 . V_31 = & V_28 ,
V_30 . V_32 = NULL ,
F_19 ( & V_30 , L_7 ) ;
V_30 . V_33 = F_20 ( V_25 , V_34 ) ;
V_22 = F_21 ( & V_30 ) ;
if ( V_22 ) {
F_17 ( L_8 ) ;
goto V_35;
}
V_21 = F_22 ( F_4 () ) ;
if ( ! V_21 ) {
F_13 ( L_9 ) ;
V_22 = - V_36 ;
goto V_37;
}
V_20 = F_23 ( F_4 () ) ;
if ( V_20 == NULL ) {
F_13 ( L_10 ) ;
F_11 ( V_21 ) ;
V_22 = - V_36 ;
goto V_37;
}
V_20 -> V_16 = 1 ;
F_24 ( & V_21 -> V_1 , & V_20 -> V_1 ) ;
V_21 -> V_38 = V_20 ;
return 0 ;
V_37:
F_25 ( & V_30 ) ;
V_35:
F_26 ( & V_28 ) ;
V_29:
F_27 ( V_25 , V_26 ) ;
return V_22 ;
}
void T_4 F_28 ( void )
{
struct V_8 * V_20 , * V_39 ;
F_25 ( & V_30 ) ;
F_26 ( & V_28 ) ;
F_27 ( V_25 , V_26 ) ;
F_29 (v, n, &vpecontrol.vpe_list, list)
if ( V_20 -> V_13 != V_14 )
F_30 ( V_20 ) ;
}
