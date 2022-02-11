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
void F_22 ( bool V_19 )
{
if ( F_6 ( L_7 ) ) {
unsigned int V_20 , V_21 ;
for ( V_21 = 0 ; V_21 < F_23 () ; V_21 ++ ) {
V_20 = F_24 ( F_25 ( V_21 ) ) ;
if ( V_19 )
V_20 |= V_22 ;
else
V_20 &= ~ ( V_22 ) ;
F_26 ( V_20 , F_25 ( V_21 ) ) ;
}
}
}
static void F_27 ( void )
{
struct V_1 * V_23 ;
V_23 = F_28 ( NULL , V_24 ) ;
if ( V_23 )
V_25 = F_4 ( V_23 , 0 ) ;
}
static void T_1 F_29 ( void )
{
F_30 () ;
F_27 () ;
}
static void T_1 F_31 ( void )
{
struct V_1 * V_26 = F_32 ( L_8 ) ;
const struct V_27 * V_28 ;
V_28 = F_33 ( V_29 , V_26 ) ;
if ( ! V_28 ) {
F_34 ( L_9 , - 1 , NULL , 0 ) ;
return;
}
F_34 ( V_28 -> V_7 , - 1 , NULL , 0 ) ;
}
static void T_1 F_35 ( void )
{
if ( ! F_36 ( V_30 ) )
F_1 () ;
#if F_37 ( V_30 ) && F_37 ( V_31 )
if ( F_6 ( L_10 ) ||
F_6 ( L_11 ) )
V_32 . V_33 . V_34 = & V_35 ;
#endif
if ( F_6 ( L_10 ) ||
F_6 ( L_12 ) ||
( F_6 ( L_13 ) &&
F_6 ( L_14 ) ) ||
F_6 ( L_11 ) ||
F_6 ( L_15 ) )
F_38 ( & V_32 ) ;
F_31 () ;
F_39 ( NULL , V_36 , NULL , NULL ) ;
}
static void T_1 F_40 ( void )
{
#ifdef F_41
int V_37 ;
char * V_38 [] = {
L_16 ,
L_17 ,
L_18 ,
L_19 ,
} ;
for ( V_37 = 0 ; V_37 < F_16 ( V_38 ) ; V_37 ++ )
if ( F_20 ( V_39 , V_38 [ V_37 ] ) )
break;
#endif
}
static void T_1 F_42 ( void )
{
F_43 ( 8 ) ;
}
