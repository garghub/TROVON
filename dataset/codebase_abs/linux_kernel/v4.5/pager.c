void F_1 ( const char * V_1 )
{
V_2 . V_1 = V_1 ;
}
static void F_2 ( void )
{
T_1 V_3 ;
F_3 ( & V_3 ) ;
F_4 ( 0 , & V_3 ) ;
F_5 ( 1 , & V_3 , NULL , & V_3 , NULL ) ;
F_6 ( L_1 , L_2 , 0 ) ;
}
static void F_7 ( void )
{
fflush ( stdout ) ;
fflush ( V_4 ) ;
F_8 ( 1 ) ;
F_8 ( 2 ) ;
F_9 ( & V_5 ) ;
}
static void F_10 ( int V_6 )
{
F_7 () ;
F_11 ( V_6 ) ;
raise ( V_6 ) ;
}
void F_12 ( void )
{
const char * V_7 = getenv ( V_2 . V_1 ) ;
if ( ! F_13 ( 1 ) )
return;
if ( ! V_7 )
V_7 = getenv ( L_3 ) ;
if ( ! ( V_7 || F_14 ( L_4 , V_8 ) ) )
V_7 = L_4 ;
if ( ! ( V_7 || F_14 ( L_5 , V_8 ) ) )
V_7 = L_5 ;
if ( ! V_7 )
V_7 = L_6 ;
if ( ! * V_7 || ! strcmp ( V_7 , L_6 ) )
return;
V_9 = 1 ;
V_10 [ 2 ] = V_7 ;
V_5 . V_11 = V_10 ;
V_5 . V_3 = - 1 ;
V_5 . V_12 = F_2 ;
if ( F_15 ( & V_5 ) )
return;
F_16 ( V_5 . V_3 , 1 ) ;
if ( F_13 ( 2 ) )
F_16 ( V_5 . V_3 , 2 ) ;
F_8 ( V_5 . V_3 ) ;
F_17 ( F_10 ) ;
atexit ( F_7 ) ;
}
int F_18 ( void )
{
return V_9 ;
}
