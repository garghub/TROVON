static void F_1 ( int V_1 ) { F_2 ( V_2 , V_1 ) ; }
unsigned int F_3 ( void )
{
if ( V_3 | V_4 )
return F_4 () ;
else
return 0 ;
}
void F_5 ( void )
{
char * V_5 ;
struct V_6 V_7 , V_8 ;
T_1 V_9 ;
static int V_10 = 0 ;
if ( V_10 ) return;
V_10 = 1 ;
if ( ( V_5 = getenv ( L_1 ) ) )
{
V_3 = strtoul ( V_5 , NULL , 0 ) ;
return;
}
F_6 ( & V_11 ) ;
F_7 ( & V_11 , V_12 ) ;
F_7 ( & V_11 , V_13 ) ;
F_7 ( & V_11 , V_14 ) ;
F_7 ( & V_11 , V_15 ) ;
F_7 ( & V_11 , V_16 ) ;
V_3 = 0 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_17 = F_1 ;
V_8 . V_18 = V_11 ;
F_8 ( V_19 , & V_8 . V_18 , & V_9 ) ;
V_6 ( V_12 , & V_8 , & V_7 ) ;
if ( F_9 ( V_2 , 1 ) == 0 )
{
F_10 () ;
V_3 |= V_20 ;
}
if ( F_9 ( V_2 , 1 ) == 0 )
{
F_4 () ;
V_3 |= V_4 ;
}
V_6 ( V_12 , & V_7 , NULL ) ;
F_8 ( V_19 , & V_9 , NULL ) ;
}
