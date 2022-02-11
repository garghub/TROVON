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
static int T_2 F_10 ( unsigned long V_1 ,
const char * V_8 , int V_9 , void * V_10 )
{
if ( V_9 == 1 && ! strcmp ( V_8 , L_4 ) )
V_11 = 1 ;
return 0 ;
}
void T_2 F_11 ( void )
{
F_12 ( V_12 ) ;
F_13 ( V_13 ) ;
F_14 ( F_10 , NULL ) ;
if ( V_11 )
F_14 ( V_14 , NULL ) ;
else if ( V_15 . V_16 )
F_15 ( V_15 . V_17 , V_15 . V_16 * V_18 ,
V_19 ) ;
else
F_16 ( V_15 . V_17 ,
V_15 . V_20 * V_18 ,
V_15 . V_21 * V_18 ) ;
}
static int T_2 F_17 ( void )
{
F_18 ( V_15 . V_22 , L_5 ) ;
F_19 () ;
return 0 ;
}
