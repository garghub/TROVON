static int F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_3 , V_4 , V_5 , false ,
& V_6 ) ;
if ( V_2 == NULL )
return - 1 ;
if ( V_7 )
F_3 ( V_2 , & V_6 ) ;
F_4 ( V_2 , stdout , V_7 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_6 ( T_1 * V_8 )
{
T_2 V_9 [ V_10 ] ;
char V_11 [ V_10 * 2 + 1 ] ;
if ( F_7 ( L_1 , V_9 ,
sizeof( V_9 ) ) != 0 )
return - 1 ;
F_8 ( V_9 , sizeof( V_9 ) ,
V_11 ) ;
fprintf ( V_8 , L_2 , V_11 ) ;
return 0 ;
}
static int F_9 ( const char * V_12 , T_1 * V_8 )
{
T_2 V_13 [ V_10 ] ;
char V_11 [ V_10 * 2 + 1 ] ;
if ( F_10 ( V_12 , V_13 ,
sizeof( V_13 ) ) != sizeof( V_13 ) )
return 0 ;
F_8 ( V_13 , sizeof( V_13 ) , V_11 ) ;
return fprintf ( V_8 , L_2 , V_11 ) ;
}
static int F_11 ( void )
{
if ( V_14 )
return F_6 ( stdout ) ;
F_12 ( V_15 ) ;
if ( F_9 ( V_3 , stdout ) )
return 0 ;
return F_1 () ;
}
int F_13 ( int V_16 , const char * * V_17 , const char * T_3 V_18 )
{
V_16 = F_14 ( V_16 , V_17 , V_19 , V_20 , 0 ) ;
F_15 () ;
return F_11 () ;
}
