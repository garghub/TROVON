static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void F_4 ( char V_2 , const char * V_3 )
{
void T_2 * V_4 = F_5 ( V_5 , V_6 ) ;
F_6 ( 1 , V_4 + 0x18 ) ;
}
static void T_1 F_7 ( void )
{
struct V_7 * V_8 ;
void T_2 * V_9 ;
int V_10 ;
T_3 V_11 ;
F_8 () ;
V_8 = F_9 ( L_1 ) ;
if ( ! V_8 )
return;
V_9 = F_10 ( V_8 , 0 ) ;
if ( F_11 ( ! V_9 ) )
return;
V_10 = F_12 ( V_8 , 0 ) ;
F_13 ( L_2 , V_9 , V_10 ) ;
V_11 = F_14 ( V_9 ) ;
V_11 &= V_12 ;
V_11 |= V_13 ;
F_6 ( V_11 , V_9 ) ;
F_15 ( V_9 , V_10 ) ;
}
static int T_1 F_16 ( void )
{
struct V_7 * V_14 ;
int V_15 , V_10 , V_16 ;
V_14 = F_9 ( L_3 ) ;
if ( ! V_14 ) {
F_13 ( L_4 ) ;
return 0 ;
}
V_15 = F_17 ( V_14 , 0 ) ;
V_16 = F_18 ( V_15 , L_5 ) ;
if ( V_16 ) {
F_13 ( L_6 ) ;
return - V_17 ;
}
V_16 = F_19 ( V_15 ) ;
if ( V_16 ) {
F_13 ( L_7 ) ;
return - V_17 ;
}
V_10 = F_20 ( V_15 ) ;
F_13 ( L_8 , V_15 , V_10 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
struct V_7 * V_18 ;
int V_15 , V_16 ;
V_18 = F_9 ( L_9 ) ;
if ( ! V_18 ) {
F_13 ( L_10 ) ;
return 0 ;
}
V_15 = F_17 ( V_18 , 0 ) ;
if ( V_15 < 0 ) {
F_13 ( L_11 ) ;
return 0 ;
}
V_16 = F_18 ( V_15 , L_12 ) ;
if ( V_16 ) {
F_13 ( L_13 , V_15 ) ;
return - V_17 ;
}
V_16 = F_22 ( V_15 , 0 ) ;
if ( V_16 ) {
F_13 ( L_14 , V_15 ) ;
return V_16 ;
}
F_13 ( L_15 , V_15 ) ;
return 0 ;
}
static void T_1 F_23 ( void )
{
#ifdef F_24
F_25 ( 0x00730249 , 0xfe000fff ) ;
#endif
F_26 ( V_19 , F_3 ( V_19 ) ) ;
F_27 ( NULL , V_20 ,
V_21 , NULL ) ;
}
