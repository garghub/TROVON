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
unsigned long V_8 , V_9 ;
void * V_10 ;
if ( ! V_11 )
return;
V_8 = F_9 ( ( void * ) V_11 ) ;
V_9 = F_10 ( V_11 -> V_12 ) ;
F_11 ( V_8 , V_9 , V_13 ) ;
V_10 = F_12 ( V_9 ) ;
memcpy ( V_10 , V_11 , V_9 ) ;
V_11 = V_10 ;
F_13 () ;
F_14 ( V_8 , V_9 ) ;
}
void T_2 F_15 ( void )
{
F_16 ( V_14 ) ;
F_17 ( & V_15 ) ;
}
static int T_2 F_18 ( void )
{
static struct V_16 V_17 [ 3 ] ;
int V_18 = sizeof( V_17 [ 0 ] . V_19 ) ;
if ( ! F_19 () )
F_3 ( L_4 ) ;
strncpy ( V_17 [ 0 ] . V_19 , V_20 . V_19 , V_18 ) ;
strncpy ( V_17 [ 1 ] . V_19 , L_5 , V_18 ) ;
if ( F_20 ( NULL , V_17 , NULL , NULL ) )
F_3 ( L_6 ) ;
return 0 ;
}
