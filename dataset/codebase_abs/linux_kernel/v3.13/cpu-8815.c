static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void F_4 ( enum V_2 V_3 , const char * V_4 )
{
void T_2 * V_5 = F_5 ( V_6 , V_7 ) ;
F_6 ( 1 , V_5 + 0x18 ) ;
}
static int T_1 F_7 ( void )
{
struct V_8 * V_9 ;
int V_10 , V_11 , V_12 ;
V_9 = F_8 ( L_1 ) ;
if ( ! V_9 ) {
F_9 ( L_2 ) ;
return 0 ;
}
V_10 = F_10 ( V_9 , 0 ) ;
V_12 = F_11 ( V_10 , L_3 ) ;
if ( V_12 ) {
F_9 ( L_4 ) ;
return - V_13 ;
}
V_12 = F_12 ( V_10 ) ;
if ( V_12 ) {
F_9 ( L_5 ) ;
return - V_13 ;
}
V_11 = F_13 ( V_10 ) ;
F_9 ( L_6 , V_10 , V_11 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
struct V_8 * V_14 ;
int V_10 , V_12 ;
V_14 = F_8 ( L_7 ) ;
if ( ! V_14 ) {
F_9 ( L_8 ) ;
return 0 ;
}
V_10 = F_10 ( V_14 , 0 ) ;
if ( V_10 < 0 ) {
F_9 ( L_9 ) ;
return 0 ;
}
V_12 = F_11 ( V_10 , L_10 ) ;
if ( V_12 ) {
F_9 ( L_11 , V_10 ) ;
return - V_13 ;
}
V_12 = F_15 ( V_10 , 0 ) ;
if ( V_12 ) {
F_9 ( L_12 , V_10 ) ;
return V_12 ;
}
F_9 ( L_13 , V_10 ) ;
return 0 ;
}
static void T_1 F_16 ( void )
{
#ifdef F_17
F_18 ( 0x00730249 , 0xfe000fff ) ;
#endif
F_19 ( NULL , V_15 , NULL , NULL ) ;
}
