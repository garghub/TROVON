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
}
static void T_1 F_17 ( void )
{
F_18 () ;
F_19 ( F_8 , NULL ) ;
F_20 ( V_15 ) ;
F_14 () ;
}
void F_21 ( bool V_18 )
{
if ( F_6 ( L_7 ) ) {
unsigned int V_19 , V_20 ;
for ( V_20 = 0 ; V_20 < F_22 () ; V_20 ++ ) {
V_19 = F_23 ( F_24 ( V_20 ) ) ;
if ( V_18 )
V_19 |= V_21 ;
else
V_19 &= ~ ( V_21 ) ;
F_25 ( V_19 , F_24 ( V_20 ) ) ;
}
}
}
static void F_26 ( void )
{
struct V_1 * V_22 ;
V_22 = F_27 ( NULL , V_23 ) ;
if ( V_22 )
V_24 = F_4 ( V_22 , 0 ) ;
}
static void T_1 F_28 ( void )
{
F_29 () ;
F_26 () ;
}
static void T_1 F_30 ( void )
{
if ( ! F_31 ( V_25 ) )
F_1 () ;
#if F_32 ( V_25 ) && F_32 ( V_26 )
if ( F_6 ( L_8 ) ||
F_6 ( L_9 ) )
V_27 . V_28 . V_29 = & V_30 ;
#endif
if ( F_6 ( L_8 ) ||
F_6 ( L_10 ) ||
( F_6 ( L_11 ) &&
F_6 ( L_12 ) ) ||
F_6 ( L_9 ) ||
F_6 ( L_13 ) )
F_33 ( & V_27 ) ;
F_34 ( NULL , V_31 , NULL , NULL ) ;
}
static void T_1 F_35 ( void )
{
#ifdef F_36
int V_32 ;
char * V_33 [] = {
L_14 ,
L_15 ,
L_16 ,
L_17 ,
} ;
for ( V_32 = 0 ; V_32 < F_16 ( V_33 ) ; V_32 ++ )
if ( F_19 ( V_34 , V_33 [ V_32 ] ) )
break;
#endif
}
static void T_1 F_37 ( void )
{
F_38 ( 8 ) ;
}
