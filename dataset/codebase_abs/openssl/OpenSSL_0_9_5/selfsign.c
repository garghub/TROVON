int main ()
{
T_1 * V_1 ;
T_2 * V_2 = NULL ;
T_3 * V_3 = NULL ;
F_1 ( V_4 ) ;
V_1 = F_2 ( V_5 , V_6 ) ;
F_3 ( & V_2 , & V_3 , 512 , 0 , 365 ) ;
F_4 ( stdout , V_3 -> V_3 . V_7 , 0 ) ;
F_5 ( stdout , V_2 ) ;
F_6 ( stdout , V_3 , NULL , NULL , 0 , NULL , NULL ) ;
F_7 ( stdout , V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_3 ) ;
#ifdef F_10
F_11 () ;
F_12 () ;
#endif
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
return ( 0 ) ;
}
static void T_4 F_15 ( T_5 , T_6 , T_7 )
int T_5 ;
int T_6 ;
void * T_7 ;
{
char V_8 = 'B' ;
if ( T_5 == 0 ) V_8 = '.' ;
if ( T_5 == 1 ) V_8 = '+' ;
if ( T_5 == 2 ) V_8 = '*' ;
if ( T_5 == 3 ) V_8 = '\n' ;
fputc ( V_8 , V_5 ) ;
}
int F_3 ( T_8 , T_9 , T_10 , T_11 , T_12 )
T_2 * * T_8 ;
T_3 * * T_9 ;
int T_10 ;
int T_11 ;
int T_12 ;
{
T_2 * V_9 ;
T_3 * V_10 ;
T_13 * V_7 ;
T_14 * V_11 = NULL ;
T_15 * V_12 = NULL ;
T_16 * V_13 = NULL ;
if ( ( T_9 == NULL ) || ( * T_9 == NULL ) )
{
if ( ( V_10 = F_16 () ) == NULL )
{
abort () ;
return ( 0 ) ;
}
}
else
V_10 = * T_9 ;
if ( ( T_8 == NULL ) || ( * T_8 == NULL ) )
{
if ( ( V_9 = F_17 () ) == NULL )
goto V_14;
}
else
V_9 = * T_8 ;
V_7 = F_18 ( T_10 , V_15 , F_15 , NULL ) ;
if ( ! F_19 ( V_10 , V_7 ) )
{
abort () ;
goto V_14;
}
V_7 = NULL ;
F_20 ( V_9 , 3 ) ;
F_21 ( F_22 ( V_9 ) , T_11 ) ;
F_23 ( F_24 ( V_9 ) , 0 ) ;
F_23 ( F_25 ( V_9 ) , ( long ) 60 * 60 * 24 * T_12 ) ;
F_26 ( V_9 , V_10 ) ;
V_11 = F_27 ( V_9 ) ;
F_28 ( V_11 , L_1 ,
V_16 , L_2 , - 1 , - 1 , 0 ) ;
F_28 ( V_11 , L_3 ,
V_16 , L_4 , - 1 , - 1 , 0 ) ;
F_29 ( V_9 , V_11 ) ;
V_13 = F_30 ( NULL , NULL , V_17 , L_5 ) ;
F_31 ( V_9 , V_13 , - 1 ) ;
F_32 ( V_13 ) ;
V_13 = F_30 ( NULL , NULL , V_18 ,
L_6 ) ;
F_31 ( V_9 , V_13 , - 1 ) ;
F_32 ( V_13 ) ;
V_13 = F_30 ( NULL , NULL , V_19 ,
L_7 ) ;
F_31 ( V_9 , V_13 , - 1 ) ;
F_32 ( V_13 ) ;
#if 0
ex = X509V3_EXT_conf_nid(NULL, NULL, NID_basic_constraints,
"critical,CA:TRUE");
X509_add_ext(x,ex,-1);
X509_EXTENSION_free(ex);
#endif
#ifdef F_10
{
int V_20 ;
V_20 = F_33 ( L_8 , L_9 , L_10 ) ;
F_34 ( V_20 , V_18 ) ;
V_13 = F_30 ( NULL , NULL , V_20 ,
L_11 ) ;
F_31 ( V_9 , V_13 , - 1 ) ;
F_32 ( V_13 ) ;
}
#endif
if ( ! F_35 ( V_9 , V_10 , F_36 () ) )
goto V_14;
* T_8 = V_9 ;
* T_9 = V_10 ;
return ( 1 ) ;
V_14:
return ( 0 ) ;
}
