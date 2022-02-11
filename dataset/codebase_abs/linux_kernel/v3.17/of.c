T_1 void * F_1 ( const char * V_1 )
{
struct V_2 V_3 ;
struct V_4 * V_5 ;
V_5 = F_2 ( NULL , NULL , V_1 ) ;
if ( ! V_5 )
F_3 ( L_1 , V_1 ) ;
if ( F_4 ( V_5 , 0 , & V_3 ) )
F_3 ( L_2 , V_1 ) ;
if ( ( F_5 ( V_3 . V_6 ,
F_6 ( & V_3 ) ,
V_3 . V_7 ) < 0 ) )
F_3 ( L_3 , V_1 ) ;
return F_7 ( V_3 . V_6 , F_6 ( & V_3 ) ) ;
}
void T_2 F_8 ( void )
{
F_9 () ;
}
void T_2 F_10 ( void )
{
F_11 ( V_8 ) ;
F_12 ( V_9 ) ;
if ( V_10 . V_11 )
F_13 ( V_10 . V_12 , V_10 . V_11 * V_13 ,
V_14 ) ;
else
F_14 ( V_10 . V_12 ,
V_10 . V_15 * V_13 ,
V_10 . V_16 * V_13 ) ;
}
static int T_2 F_15 ( void )
{
static struct V_17 V_18 [ 3 ] ;
int V_19 = sizeof( V_18 [ 0 ] . V_20 ) ;
if ( ! F_16 () )
F_3 ( L_4 ) ;
F_17 ( V_18 [ 0 ] . V_20 , V_10 . V_20 , V_19 ) ;
F_17 ( V_18 [ 1 ] . V_20 , L_5 , V_19 ) ;
if ( F_18 ( NULL , V_18 , NULL , NULL ) )
F_3 ( L_6 ) ;
F_19 () ;
return 0 ;
}
