static T_1 * F_1 ( const T_2 * V_1 ) {
T_1 * V_2 = F_2 ( T_1 , 1 ) ;
V_2 -> V_1 = F_3 ( V_1 ) ;
V_2 -> V_3 = F_4 ( L_1 ) ;
if ( ! V_4 )
V_4 = F_5 () ;
F_6 ( V_4 , V_2 ) ;
return V_2 ;
}
static void F_7 ( T_1 * V_2 ) {
F_8 ( V_2 -> V_3 , TRUE ) ;
V_2 -> V_3 = F_4 ( L_1 ) ;
}
static void F_9 ( T_1 * V_2 , const char * V_3 ) {
F_10 ( V_2 -> V_3 , V_3 ) ;
}
static void F_11 ( T_1 * V_2 , const char * V_3 ) {
F_8 ( V_2 -> V_3 , TRUE ) ;
V_2 -> V_3 = F_4 ( V_3 ) ;
}
static void F_12 ( T_1 * V_2 , const char * V_3 ) {
F_13 ( V_2 -> V_3 , V_3 ) ;
}
static const T_2 * F_14 ( T_1 * V_2 ) {
return V_2 -> V_3 -> V_5 ;
}
static void F_15 ( const T_2 * T_3 V_6 ,
T_4 T_5 V_6 ,
const T_2 * V_7 ,
T_6 T_7 V_6 ) {
fputs ( V_7 , V_8 ) ;
}
void F_16 ( void ) {
F_17 ( & V_9 ) ;
}
void F_18 ( void ) {
T_8 V_10 ;
if ( ! V_4 ) return;
for ( V_10 = 0 ; V_10 < V_4 -> V_11 ; V_10 ++ ) {
T_1 * V_2 = ( T_1 * ) F_19 ( V_4 , V_10 ) ;
printf ( L_2
L_3 , V_2 -> V_1 , V_2 -> V_3 -> V_5 ) ;
F_20 ( V_4 , V_10 ) ;
F_21 ( V_2 -> V_1 ) ;
F_8 ( V_2 -> V_3 , TRUE ) ;
F_21 ( V_2 ) ;
}
}
void
F_22 ( void )
{
#if 0
funnel_register_all_menus(register_menu_cb);
#endif
}
