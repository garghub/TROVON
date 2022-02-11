static T_1
F_1 ( int V_1 )
{
T_2 V_2 ;
T_3 V_3 ;
T_3 error ;
V_2 = F_2 ( V_1 ) ;
if ( V_2 == NULL ) {
return TRUE ;
}
if ( V_2 == V_4 ) {
return FALSE ;
}
V_3 = F_3 ( V_2 ) ;
if ( V_3 == V_5 ) {
error = F_4 () ;
if ( error == V_6 ) {
return TRUE ;
}
}
return FALSE ;
}
void
F_5 ( void )
{
T_1 V_7 ;
T_1 V_8 ;
T_1 V_9 ;
if ( V_10 ) {
return;
}
if ( ! V_11 ) {
V_7 = F_1 ( V_12 ) ;
V_8 = F_1 ( V_13 ) ;
V_9 = F_1 ( V_14 ) ;
if ( ! V_7 && ! V_8 && ! V_9 )
return;
if ( ! F_6 ( V_15 ) ) {
F_7 () ;
if ( F_8 () ) {
V_16 = TRUE ;
F_9 ( F_10 ( L_1 ) ) ;
} else {
return;
}
}
if ( V_7 )
F_11 ( L_2 , L_3 , V_17 ) ;
if ( V_8 ) {
F_11 ( L_4 , L_5 , stdout ) ;
fprintf ( stdout , L_6 ) ;
}
if ( V_9 ) {
F_11 ( L_4 , L_5 , V_18 ) ;
fprintf ( V_18 , L_6 ) ;
}
atexit ( V_19 ) ;
V_11 = TRUE ;
}
}
void
V_19 ( void )
{
if ( V_16 ) {
printf ( L_7 ) ;
F_12 () ;
}
F_7 () ;
}
void
F_13 ( T_1 F_13 )
{
V_16 = F_13 ;
}
T_1
F_14 ( void )
{
return V_16 ;
}
void
F_15 ( T_1 F_15 )
{
V_11 = V_11 ;
}
T_1
F_16 ( void )
{
return V_11 ;
}
void
F_17 ( T_1 F_17 )
{
V_10 = F_17 ;
}
T_1
F_18 ( void )
{
return V_10 ;
}
