static void F_1 ( void )
{
T_1 V_1 ;
F_2 ( & V_1 ) ;
F_3 ( 0 , & V_1 ) ;
F_4 ( 1 , & V_1 , NULL , & V_1 , NULL ) ;
F_5 ( L_1 , L_2 , 0 ) ;
}
static void F_6 ( void )
{
fflush ( stdout ) ;
fflush ( V_2 ) ;
F_7 ( 1 ) ;
F_7 ( 2 ) ;
F_8 ( & V_3 ) ;
}
static void F_9 ( int V_4 )
{
F_6 () ;
F_10 ( V_4 ) ;
raise ( V_4 ) ;
}
void F_11 ( void )
{
const char * V_5 = getenv ( L_3 ) ;
if ( ! F_12 ( 1 ) )
return;
if ( ! V_5 ) {
if ( ! V_6 )
F_13 ( V_7 , NULL ) ;
V_5 = V_6 ;
}
if ( ! V_5 )
V_5 = getenv ( L_4 ) ;
if ( ! V_5 )
V_5 = L_5 ;
else if ( ! * V_5 || ! strcmp ( V_5 , L_6 ) )
return;
V_8 = 1 ;
V_9 [ 2 ] = V_5 ;
V_3 . V_10 = V_9 ;
V_3 . V_1 = - 1 ;
V_3 . V_11 = F_1 ;
if ( F_14 ( & V_3 ) )
return;
F_15 ( V_3 . V_1 , 1 ) ;
if ( F_12 ( 2 ) )
F_15 ( V_3 . V_1 , 2 ) ;
F_7 ( V_3 . V_1 ) ;
F_16 ( F_9 ) ;
atexit ( F_6 ) ;
}
int F_17 ( void )
{
const char * V_12 ;
if ( V_8 )
return 1 ;
V_12 = getenv ( L_7 ) ;
return V_12 ? F_18 ( L_7 , V_12 ) : 0 ;
}
