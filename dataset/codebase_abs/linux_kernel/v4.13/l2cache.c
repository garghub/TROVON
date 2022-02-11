static int T_1 F_1 ( char * V_1 )
{
char * V_2 = V_1 ;
if ( F_2 ( & V_2 , & V_3 ) != 1 ) {
F_3 ( L_1 , V_1 ) ;
return 1 ;
}
return 0 ;
}
static int T_1 F_4 ( char * V_1 )
{
char * V_2 = V_1 ;
if ( F_2 ( & V_2 , & V_4 ) != 1 ) {
F_3 ( L_2 , V_1 ) ;
return 1 ;
}
return 0 ;
}
static int T_1 F_5 ( void )
{
if ( ! F_6 () ) {
F_7 ( L_3 ) ;
return 0 ;
}
if ( ! F_8 () ) {
F_9 ( L_4 ,
F_10 () ) ;
}
V_5 = F_11 () ;
if ( V_3 ) {
F_7 ( L_5 ) ;
if ( F_12 () )
F_13 ( L_6 ) ;
else
F_13 ( L_7 ) ;
} else {
F_7 ( L_8 ) ;
}
if ( V_4 ) {
F_7 ( L_9 ) ;
if ( F_14 ( 1 ) )
F_13 ( L_6 ) ;
else
F_13 ( L_7 ) ;
} else {
F_7 ( L_10 ) ;
}
return 0 ;
}
int F_15 ( void )
{
unsigned long V_6 ;
int V_7 ;
if ( ! F_6 () )
return 1 ;
F_16 ( V_6 ) ;
V_7 = F_17 () ;
if ( F_18 ( V_7 ) ) {
F_19 ( 0 ) ;
F_20 () ;
F_21 () ;
F_22 ( 0 ) ;
}
F_23 ( V_6 ) ;
return ! V_7 ;
}
int F_12 ( void )
{
unsigned long V_6 ;
int V_7 ;
if ( ! F_6 () )
return 0 ;
F_24 ( V_6 ) ;
V_7 = F_17 () ;
if ( F_18 ( ! V_7 ) ) {
F_25 () ;
F_22 ( 1 ) ;
F_19 ( V_5 ) ;
}
F_26 ( V_6 ) ;
return V_7 ;
}
int F_14 ( int V_8 )
{
unsigned long V_6 ;
int V_7 = V_5 ;
if ( ! F_6 () )
return 0 ;
F_24 ( V_6 ) ;
V_7 = V_5 ;
V_5 = V_8 ;
if ( F_17 () )
F_19 ( V_8 ) ;
F_26 ( V_6 ) ;
return V_7 ;
}
int F_27 ( void )
{
unsigned long V_6 ;
int V_7 ;
F_16 ( V_6 ) ;
V_7 = F_17 () ;
if ( F_18 ( V_7 ) ) {
F_19 ( 0 ) ;
F_20 () ;
F_21 () ;
F_22 ( 0 ) ;
F_25 () ;
F_22 ( 1 ) ;
F_19 ( V_5 ) ;
}
F_23 ( V_6 ) ;
return ! V_7 ;
}
