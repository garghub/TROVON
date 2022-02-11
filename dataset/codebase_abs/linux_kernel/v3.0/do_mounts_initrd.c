static int T_1 F_1 ( char * V_1 )
{
V_2 = 0 ;
return 1 ;
}
static int T_1 F_2 ( void * V_3 )
{
static const char * V_4 [] = { L_1 , NULL , } ;
extern const char * V_5 [] ;
const char * V_6 = V_3 ;
F_3 ( V_7 ) ; F_3 ( V_8 ) ;
F_4 () ;
return F_5 ( V_6 , V_4 , V_5 ) ;
}
static void T_1 F_6 ( void )
{
int error ;
int V_9 ;
V_10 = F_7 ( V_11 ) ;
F_8 ( L_2 , V_12 ) ;
F_9 ( L_2 , V_13 & ~ V_14 ) ;
F_10 ( L_3 , 0700 ) ;
V_8 = F_11 ( L_4 , 0 , 0 ) ;
V_7 = F_11 ( L_3 , 0 , 0 ) ;
F_12 ( L_5 ) ;
F_13 ( L_6 , L_4 , NULL , V_15 , NULL ) ;
F_14 ( L_6 ) ;
V_16 -> V_17 |= V_18 ;
V_9 = F_15 ( F_2 , L_7 , V_19 ) ;
if ( V_9 > 0 )
while ( V_9 != F_16 ( - 1 , NULL , 0 , NULL ) )
F_17 () ;
V_16 -> V_17 &= ~ V_18 ;
F_18 ( V_7 ) ;
F_13 ( L_4 , L_6 , NULL , V_15 , NULL ) ;
F_18 ( V_8 ) ;
F_14 ( L_6 ) ;
F_3 ( V_7 ) ;
F_3 ( V_8 ) ;
if ( F_19 ( V_10 ) == V_12 ) {
F_12 ( L_3 ) ;
return;
}
V_11 = F_19 ( V_10 ) ;
F_20 () ;
F_21 ( V_20 L_8 ) ;
error = F_13 ( L_3 , L_9 , NULL , V_15 , NULL ) ;
if ( ! error )
F_21 ( L_10 ) ;
else {
int V_21 = F_11 ( L_2 , V_22 , 0 ) ;
if ( error == - V_23 )
F_21 ( L_11 ) ;
else
F_21 ( L_12 ) ;
F_21 ( V_20 L_13 ) ;
F_22 ( L_3 , V_24 ) ;
F_21 ( V_20 L_14 ) ;
if ( V_21 < 0 ) {
error = V_21 ;
} else {
error = F_23 ( V_21 , V_25 , 0 ) ;
F_3 ( V_21 ) ;
}
F_21 ( ! error ? L_10 : L_12 ) ;
}
}
int T_1 F_24 ( void )
{
if ( V_2 ) {
F_8 ( L_15 , V_12 ) ;
if ( F_25 ( L_16 ) && V_11 != V_12 ) {
F_26 ( L_16 ) ;
F_6 () ;
return 1 ;
}
}
F_26 ( L_16 ) ;
return 0 ;
}
