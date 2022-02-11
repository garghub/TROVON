static int T_1 F_1 ( char * V_1 )
{
V_2 = 0 ;
return 1 ;
}
static int F_2 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
F_3 ( V_7 | V_8 ) ;
F_4 ( L_1 ) ;
F_5 ( L_2 , L_3 , NULL , V_9 , NULL ) ;
F_6 ( L_2 ) ;
F_7 () ;
return 0 ;
}
static void T_1 F_8 ( void )
{
static char * V_10 [] = { L_4 , NULL , } ;
extern char * V_11 [] ;
int error ;
V_12 = F_9 ( V_13 ) ;
F_10 ( L_5 , V_14 ) ;
F_11 ( L_5 , V_15 & ~ V_16 ) ;
F_12 ( L_6 , 0700 ) ;
F_4 ( L_6 ) ;
V_17 -> V_18 |= V_19 ;
F_13 ( L_7 , V_10 , V_11 , V_20 ,
F_2 , NULL , NULL ) ;
V_17 -> V_18 &= ~ V_19 ;
F_5 ( L_8 , L_2 , NULL , V_9 , NULL ) ;
F_6 ( L_8 ) ;
if ( F_14 ( V_12 ) == V_14 ) {
F_4 ( L_6 ) ;
return;
}
F_4 ( L_3 ) ;
V_13 = F_14 ( V_12 ) ;
F_15 () ;
F_16 ( V_21 L_9 ) ;
error = F_5 ( L_6 , L_10 , NULL , V_9 , NULL ) ;
if ( ! error )
F_16 ( L_11 ) ;
else {
int V_22 = F_17 ( L_5 , V_23 , 0 ) ;
if ( error == - V_24 )
F_16 ( L_12 ) ;
else
F_16 ( L_13 ) ;
F_16 ( V_21 L_14 ) ;
F_18 ( L_6 , V_25 ) ;
F_16 ( V_21 L_15 ) ;
if ( V_22 < 0 ) {
error = V_22 ;
} else {
error = F_19 ( V_22 , V_26 , 0 ) ;
F_20 ( V_22 ) ;
}
F_16 ( ! error ? L_11 : L_13 ) ;
}
}
int T_1 F_21 ( void )
{
if ( V_2 ) {
F_10 ( L_16 , V_14 ) ;
if ( F_22 ( L_17 ) && V_13 != V_14 ) {
F_23 ( L_17 ) ;
F_8 () ;
return 1 ;
}
}
F_23 ( L_17 ) ;
return 0 ;
}
