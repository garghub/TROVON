static int T_1 F_1 ( char * V_1 )
{
V_2 = 0 ;
return 1 ;
}
static int F_2 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
F_3 ( V_7 | V_8 ) ;
F_4 ( L_1 , V_9 , 0 ) ;
F_5 ( 0 ) ;
F_5 ( 0 ) ;
F_6 ( L_2 ) ;
F_7 ( L_3 , L_4 , NULL , V_10 , NULL ) ;
F_8 ( L_3 ) ;
F_9 () ;
return 0 ;
}
static void T_1 F_10 ( void )
{
struct V_3 * V_4 ;
static char * V_11 [] = { L_5 , NULL , } ;
extern char * V_12 [] ;
int error ;
V_13 = F_11 ( V_14 ) ;
F_12 ( L_6 , V_15 ) ;
F_13 ( L_6 , V_16 & ~ V_17 ) ;
F_14 ( L_7 , 0700 ) ;
F_6 ( L_7 ) ;
F_15 () ;
V_18 -> V_19 |= V_20 ;
V_4 = F_16 ( L_8 , V_11 , V_12 ,
V_21 , F_2 , NULL , NULL ) ;
if ( ! V_4 )
return;
F_17 ( V_4 , V_22 ) ;
V_18 -> V_19 &= ~ V_20 ;
F_7 ( L_9 , L_3 , NULL , V_10 , NULL ) ;
F_8 ( L_9 ) ;
if ( F_18 ( V_13 ) == V_15 ) {
F_6 ( L_7 ) ;
return;
}
F_6 ( L_4 ) ;
V_14 = F_18 ( V_13 ) ;
F_19 () ;
F_20 ( V_23 L_10 ) ;
error = F_7 ( L_7 , L_11 , NULL , V_10 , NULL ) ;
if ( ! error )
F_20 ( L_12 ) ;
else {
int V_24 = F_4 ( L_6 , V_9 , 0 ) ;
if ( error == - V_25 )
F_20 ( L_13 ) ;
else
F_20 ( L_14 ) ;
F_20 ( V_23 L_15 ) ;
F_21 ( L_7 , V_26 ) ;
F_20 ( V_23 L_16 ) ;
if ( V_24 < 0 ) {
error = V_24 ;
} else {
error = F_22 ( V_24 , V_27 , 0 ) ;
F_23 ( V_24 ) ;
}
F_20 ( ! error ? L_12 : L_14 ) ;
}
}
bool T_1 F_24 ( void )
{
if ( V_2 ) {
F_12 ( L_17 , V_15 ) ;
if ( F_25 ( L_18 ) && V_14 != V_15 ) {
F_26 ( L_18 ) ;
F_10 () ;
return true ;
}
}
F_26 ( L_18 ) ;
return false ;
}
