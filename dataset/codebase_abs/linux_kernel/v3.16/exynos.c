void F_1 ( enum V_1 V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 = 0x1 ;
void T_2 * V_7 = V_8 ;
if ( F_2 ( L_1 ) ) {
T_1 V_9 ;
V_5 = F_3 ( NULL , NULL , L_2 ) ;
V_7 = F_4 ( V_5 , 0 ) + 0xbc ;
V_9 = F_5 ( V_7 ) ;
V_7 = F_4 ( V_5 , 0 ) + 0xcc ;
V_6 = F_5 ( V_7 ) ;
V_6 = ( V_6 & 0xffff0000 ) | ( V_9 & 0xffff ) ;
}
F_6 ( V_6 , V_7 ) ;
}
void T_3 F_7 ( void )
{
if ( F_8 () || F_9 () )
F_10 ( & V_10 ) ;
}
void T_3 F_11 ( void )
{
F_12 ( L_3 , - 1 , NULL , 0 ) ;
}
void T_3 F_13 ( void )
{
struct V_4 * V_11 ;
F_14 (node, NULL, L_4 ) {
if ( ! F_15 ( V_11 ) )
continue;
V_12 = F_4 ( V_11 , 0 ) ;
break;
}
F_14 (node, NULL, L_5 ) {
if ( ! F_15 ( V_11 ) )
continue;
V_13 = F_4 ( V_11 , 0 ) ;
break;
}
}
void T_3 F_16 ( void )
{
if ( F_2 ( L_1 ) )
return;
F_17 () ;
F_18 () ;
}
static int T_3 F_19 ( unsigned long V_11 , const char * V_14 ,
int V_15 , void * V_16 )
{
struct V_17 V_18 ;
const T_4 * V_19 ;
int V_20 ;
if ( ! F_20 ( V_11 , L_6 ) &&
! F_20 ( V_11 , L_2 ) )
return 0 ;
V_19 = F_21 ( V_11 , L_7 , & V_20 ) ;
if ( V_19 == NULL || V_20 != (sizeof( unsigned long ) * 2 ) )
return 0 ;
V_18 . V_21 = F_22 ( F_23 ( V_19 [ 0 ] ) ) ;
V_18 . V_22 = F_23 ( V_19 [ 1 ] ) - 1 ;
V_18 . V_23 = ( unsigned long ) V_24 ;
V_18 . type = V_25 ;
F_24 ( & V_18 , 1 ) ;
return 1 ;
}
static void T_3 F_25 ( void )
{
if ( F_26 () )
F_24 ( V_26 , F_27 ( V_26 ) ) ;
if ( F_28 () )
F_24 ( V_27 , F_27 ( V_27 ) ) ;
}
void T_3 F_29 ( void )
{
F_30 () ;
F_31 ( F_19 , NULL ) ;
F_32 ( V_24 ) ;
F_25 () ;
}
static void T_3 F_33 ( void )
{
struct V_4 * V_28 ;
const char * V_29 = L_8 ;
unsigned int V_30 ;
int V_31 ;
if ( F_28 () ) {
F_14 (i2c_np, NULL, i2c_compat) {
if ( F_15 ( V_28 ) ) {
V_31 = F_34 ( V_28 , L_9 ) ;
if ( V_31 < 4 ) {
V_30 = F_35 ( V_32 ) ;
F_36 ( V_30 & ~ ( 0x1 << V_31 ) ,
V_32 ) ;
}
}
}
}
if ( ! F_37 ( V_33 ) )
F_13 () ;
F_7 () ;
F_11 () ;
F_38 ( NULL , V_34 , NULL , NULL ) ;
}
static void T_3 F_39 ( void )
{
#ifdef F_40
int V_35 ;
char * V_36 [] = {
L_10 ,
L_11 ,
L_12 ,
} ;
for ( V_35 = 0 ; V_35 < F_27 ( V_36 ) ; V_35 ++ )
if ( F_31 ( V_37 , V_36 [ V_35 ] ) )
break;
#endif
}
static void T_3 F_41 ( void )
{
F_42 ( 8 ) ;
}
