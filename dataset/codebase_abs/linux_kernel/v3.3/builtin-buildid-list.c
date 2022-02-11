static int F_1 ( T_1 * V_1 )
{
T_2 V_2 [ V_3 ] ;
char V_4 [ V_3 * 2 + 1 ] ;
if ( F_2 ( L_1 , V_2 ,
sizeof( V_2 ) ) != 0 )
return - 1 ;
F_3 ( V_2 , sizeof( V_2 ) ,
V_4 ) ;
fprintf ( V_1 , L_2 , V_4 ) ;
return 0 ;
}
static int F_4 ( const char * V_5 , T_1 * V_1 )
{
T_2 V_6 [ V_3 ] ;
char V_4 [ V_3 * 2 + 1 ] ;
if ( F_5 ( V_5 , V_6 ,
sizeof( V_6 ) ) != sizeof( V_6 ) )
return 0 ;
F_3 ( V_6 , sizeof( V_6 ) , V_4 ) ;
return fprintf ( V_1 , L_2 , V_4 ) ;
}
static int F_6 ( void )
{
struct V_7 * V_8 ;
F_7 ( V_9 ) ;
V_8 = F_8 ( V_10 , V_11 , V_12 , false ,
& V_13 ) ;
if ( V_8 == NULL )
return - 1 ;
if ( F_4 ( V_8 -> V_14 , stdout ) )
goto V_15;
if ( V_16 )
F_9 ( V_8 , & V_13 ) ;
F_10 ( V_8 , stdout , V_16 ) ;
V_15:
F_11 ( V_8 ) ;
return 0 ;
}
static int F_12 ( void )
{
if ( V_17 )
return F_1 ( stdout ) ;
return F_6 () ;
}
int F_13 ( int V_18 , const char * * V_19 , const char * T_3 V_20 )
{
V_18 = F_14 ( V_18 , V_19 , V_21 , V_22 , 0 ) ;
F_15 () ;
return F_12 () ;
}
