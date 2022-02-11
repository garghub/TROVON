void F_1 ()
{
V_1 = 1 ;
}
void F_2 ( void )
{
struct V_2 V_3 ;
V_3 . V_4 = V_5 ;
V_3 . V_6 = F_1 ;
F_3 ( & V_3 . V_7 ) ;
V_2 ( V_8 , & V_3 , NULL ) ;
}
int main ( int V_9 , char * V_10 [] )
{
char * V_11 = NULL ;
T_1 * V_12 = NULL ;
T_1 * V_13 , * V_14 ;
T_2 * V_15 ;
char V_16 [ 512 ] ;
int V_17 = 1 , V_18 ;
if ( V_9 <= 1 )
V_11 = L_1 ;
else
V_11 = V_10 [ 1 ] ;
F_4 () ;
F_5 () ;
V_15 = F_6 ( F_7 () ) ;
if ( ! F_8 ( V_15 , V_19 ) )
goto V_20;
if ( ! F_9 ( V_15 , V_19 , V_21 ) )
goto V_20;
if ( ! F_10 ( V_15 ) )
goto V_20;
V_13 = F_11 ( V_15 , 0 ) ;
if ( ( V_12 = F_12 ( V_11 ) ) == NULL )
goto V_20;
F_13 ( V_12 , V_13 ) ;
F_2 () ;
V_22:
if ( F_14 ( V_12 ) <= 0 )
goto V_20;
while ( ! V_1 ) {
V_18 = F_15 ( V_12 , V_16 , 512 ) ;
if ( V_18 == 0 ) {
printf ( L_2 ) ;
V_14 = F_16 ( V_12 ) ;
F_17 ( V_14 ) ;
goto V_22;
}
if ( V_18 < 0 )
goto V_20;
fwrite ( V_16 , 1 , V_18 , stdout ) ;
fflush ( stdout ) ;
}
V_17 = 0 ;
V_20:
if ( V_17 ) {
F_18 ( V_23 ) ;
}
F_19 ( V_12 ) ;
exit ( V_17 ) ;
return ( ! V_17 ) ;
}
