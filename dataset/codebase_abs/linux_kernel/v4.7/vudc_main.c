static int T_1 F_1 ( void )
{
int V_1 = - V_2 ;
int V_3 ;
struct V_4 * V_5 = NULL , * V_6 = NULL ;
if ( F_2 () )
return - V_7 ;
if ( V_8 < 1 ) {
F_3 ( L_1 ) ;
return - V_9 ;
}
V_1 = F_4 ( & V_10 ) ;
if ( V_1 < 0 )
goto V_11;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ ) {
V_5 = F_5 ( V_3 ) ;
if ( ! V_5 ) {
V_1 = - V_2 ;
goto V_12;
}
V_1 = F_6 ( V_5 -> V_13 ) ;
if ( V_1 < 0 ) {
F_7 ( V_5 ) ;
goto V_12;
}
F_8 ( & V_5 -> V_14 , & V_15 ) ;
if ( ! F_9 ( V_5 -> V_13 ) ) {
V_1 = - V_9 ;
goto V_12;
}
}
goto V_11;
V_12:
F_10 (udc_dev, udc_dev2, &vudc_devices, dev_entry) {
F_11 ( & V_5 -> V_14 ) ;
F_12 ( V_5 -> V_13 ) ;
F_7 ( V_5 ) ;
}
F_13 ( & V_10 ) ;
V_11:
return V_1 ;
}
static void T_2 V_12 ( void )
{
struct V_4 * V_5 = NULL , * V_6 = NULL ;
F_10 (udc_dev, udc_dev2, &vudc_devices, dev_entry) {
F_11 ( & V_5 -> V_14 ) ;
F_14 ( V_5 -> V_13 ) ;
F_7 ( V_5 ) ;
}
F_13 ( & V_10 ) ;
}
