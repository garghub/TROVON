int F_1 ( T_1 * V_1 , T_1 * V_2 )
{
if ( V_3 ) {
* V_1 = V_4 ;
* V_2 = V_5 ;
return 0 ;
} else
return - 1 ;
}
static int T_2 F_2 ( void )
{
struct V_6 * V_7 ;
int V_8 = 0 ;
void T_3 * V_9 ;
struct V_10 * V_10 ;
struct V_6 * V_11 ;
V_7 = F_3 ( NULL , V_12 ) ;
if ( ! V_7 )
return V_8 ;
V_11 = F_4 ( V_7 , NULL ) ;
if ( V_11 == NULL ) {
F_5 ( L_1 ) ;
V_8 = - V_13 ;
goto V_14;
}
V_10 = F_6 ( V_11 , NULL ) ;
if ( F_7 ( V_10 ) ) {
F_5 ( L_2 ) ;
V_8 = - V_13 ;
goto V_14;
}
V_8 = F_8 ( V_10 ) ;
if ( V_8 ) {
F_5 ( L_3 ) ;
goto V_14;
}
V_9 = F_9 ( V_11 , 0 ) ;
if ( V_9 == NULL ) {
F_5 ( L_4 ) ;
V_8 = - V_13 ;
goto V_15;
}
V_4 = F_10 ( V_9 + V_16 ) >> 16 ;
V_5 = F_10 ( V_9 + V_17 ) & V_18 ;
V_3 = true ;
F_11 ( L_5 , V_4 , V_5 ) ;
F_12 ( V_9 ) ;
V_15:
F_13 ( V_10 ) ;
V_14:
F_14 ( V_11 ) ;
F_14 ( V_7 ) ;
return V_8 ;
}
