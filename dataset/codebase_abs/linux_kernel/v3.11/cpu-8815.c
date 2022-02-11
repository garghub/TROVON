static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void F_4 ( enum V_2 V_3 , const char * V_4 )
{
void T_2 * V_5 = F_5 ( V_6 , V_7 ) ;
F_6 ( 1 , V_5 + 0x18 ) ;
}
static void T_1 F_7 ( void )
{
struct V_8 * V_9 ;
void T_2 * V_10 ;
int V_11 ;
T_3 V_12 ;
F_8 () ;
V_9 = F_9 ( L_1 ) ;
if ( ! V_9 )
return;
V_10 = F_10 ( V_9 , 0 ) ;
if ( F_11 ( ! V_10 ) )
return;
V_11 = F_12 ( V_9 , 0 ) ;
F_13 ( L_2 , V_10 , V_11 ) ;
V_12 = F_14 ( V_10 ) ;
V_12 &= V_13 ;
V_12 |= V_14 ;
F_6 ( V_12 , V_10 ) ;
F_15 () ;
}
static int T_1 F_16 ( void )
{
struct V_8 * V_15 ;
int V_16 , V_11 , V_17 ;
V_15 = F_9 ( L_3 ) ;
if ( ! V_15 ) {
F_13 ( L_4 ) ;
return 0 ;
}
V_16 = F_17 ( V_15 , 0 ) ;
V_17 = F_18 ( V_16 , L_5 ) ;
if ( V_17 ) {
F_13 ( L_6 ) ;
return - V_18 ;
}
V_17 = F_19 ( V_16 ) ;
if ( V_17 ) {
F_13 ( L_7 ) ;
return - V_18 ;
}
V_11 = F_20 ( V_16 ) ;
F_13 ( L_8 , V_16 , V_11 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
struct V_8 * V_19 ;
int V_16 , V_17 ;
V_19 = F_9 ( L_9 ) ;
if ( ! V_19 ) {
F_13 ( L_10 ) ;
return 0 ;
}
V_16 = F_17 ( V_19 , 0 ) ;
if ( V_16 < 0 ) {
F_13 ( L_11 ) ;
return 0 ;
}
V_17 = F_18 ( V_16 , L_12 ) ;
if ( V_17 ) {
F_13 ( L_13 , V_16 ) ;
return - V_18 ;
}
V_17 = F_22 ( V_16 , 0 ) ;
if ( V_17 ) {
F_13 ( L_14 , V_16 ) ;
return V_17 ;
}
F_13 ( L_15 , V_16 ) ;
return 0 ;
}
static void T_1 F_23 ( void )
{
#ifdef F_24
F_25 ( 0x00730249 , 0xfe000fff ) ;
#endif
F_26 ( NULL , V_20 ,
V_21 , NULL ) ;
}
