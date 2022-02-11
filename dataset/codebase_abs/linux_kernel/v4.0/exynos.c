void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
F_2 (node, NULL, L_1 ) {
if ( ! F_3 ( V_2 ) )
continue;
V_3 = F_4 ( V_2 , 0 ) ;
break;
}
F_2 (node, NULL, L_2 ) {
if ( ! F_3 ( V_2 ) )
continue;
V_4 = F_4 ( V_2 , 0 ) ;
break;
}
}
static void T_1 F_5 ( void )
{
if ( F_6 ( L_3 ) )
return;
F_7 () ;
}
static int T_1 F_8 ( unsigned long V_2 , const char * V_5 ,
int V_6 , void * V_7 )
{
struct V_8 V_9 ;
const T_2 * V_10 ;
int V_11 ;
if ( ! F_9 ( V_2 , L_4 ) &&
! F_9 ( V_2 , L_5 ) )
return 0 ;
V_10 = F_10 ( V_2 , L_6 , & V_11 ) ;
if ( V_10 == NULL || V_11 != (sizeof( unsigned long ) * 2 ) )
return 0 ;
V_9 . V_12 = F_11 ( F_12 ( V_10 [ 0 ] ) ) ;
V_9 . V_13 = F_12 ( V_10 [ 1 ] ) - 1 ;
V_9 . V_14 = ( unsigned long ) V_15 ;
V_9 . type = V_16 ;
F_13 ( & V_9 , 1 ) ;
return 1 ;
}
static void T_1 F_14 ( void )
{
if ( F_15 () )
F_13 ( V_17 , F_16 ( V_17 ) ) ;
if ( F_17 () )
F_13 ( V_18 , F_16 ( V_18 ) ) ;
}
static void T_1 F_18 ( void )
{
F_19 () ;
F_20 ( F_8 , NULL ) ;
F_21 ( V_15 ) ;
F_14 () ;
}
static void F_22 ( void )
{
struct V_1 * V_19 ;
V_19 = F_23 ( NULL , V_20 ) ;
if ( V_19 )
V_21 = F_4 ( V_19 , 0 ) ;
if ( ! V_21 )
F_24 ( L_7 ) ;
}
static void T_1 F_25 ( void )
{
F_26 () ;
F_22 () ;
}
static void T_1 F_27 ( void )
{
if ( ! F_28 ( V_22 ) )
F_1 () ;
#ifdef F_29
if ( F_6 ( L_8 ) )
V_23 . V_24 . V_25 = & V_26 ;
#endif
if ( F_6 ( L_8 ) ||
F_6 ( L_9 ) ||
( F_6 ( L_10 ) &&
F_6 ( L_11 ) ) ||
F_6 ( L_12 ) )
F_30 ( & V_23 ) ;
F_31 ( L_13 , - 1 , NULL , 0 ) ;
F_32 ( NULL , V_27 , NULL , NULL ) ;
}
static void T_1 F_33 ( void )
{
#ifdef F_34
int V_28 ;
char * V_29 [] = {
L_14 ,
L_15 ,
L_16 ,
L_17 ,
} ;
for ( V_28 = 0 ; V_28 < F_16 ( V_29 ) ; V_28 ++ )
if ( F_20 ( V_30 , V_29 [ V_28 ] ) )
break;
#endif
}
static void T_1 F_35 ( void )
{
F_36 ( 8 ) ;
}
