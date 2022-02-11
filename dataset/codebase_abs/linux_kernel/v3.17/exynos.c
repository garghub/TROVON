static void F_1 ( enum V_1 V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 = 0x1 ;
void T_2 * V_7 = V_8 + V_9 ;
if ( F_2 ( L_1 ) ) {
T_1 V_10 ;
V_5 = F_3 ( NULL , NULL , L_2 ) ;
V_7 = F_4 ( V_5 , 0 ) + 0xbc ;
V_10 = F_5 ( V_7 ) ;
V_7 = F_4 ( V_5 , 0 ) + 0xcc ;
V_6 = F_5 ( V_7 ) ;
V_6 = ( V_6 & 0xffff0000 ) | ( V_10 & 0xffff ) ;
}
F_6 ( V_6 , V_7 ) ;
}
void T_3 F_7 ( void )
{
struct V_4 * V_11 ;
F_8 (node, NULL, L_3 ) {
if ( ! F_9 ( V_11 ) )
continue;
V_12 = F_4 ( V_11 , 0 ) ;
break;
}
F_8 (node, NULL, L_4 ) {
if ( ! F_9 ( V_11 ) )
continue;
V_13 = F_4 ( V_11 , 0 ) ;
break;
}
}
static void T_3 F_10 ( void )
{
if ( F_2 ( L_1 ) )
return;
F_11 () ;
F_12 () ;
}
static int T_3 F_13 ( unsigned long V_11 , const char * V_14 ,
int V_15 , void * V_16 )
{
struct V_17 V_18 ;
const T_4 * V_19 ;
int V_20 ;
if ( ! F_14 ( V_11 , L_5 ) &&
! F_14 ( V_11 , L_2 ) )
return 0 ;
V_19 = F_15 ( V_11 , L_6 , & V_20 ) ;
if ( V_19 == NULL || V_20 != (sizeof( unsigned long ) * 2 ) )
return 0 ;
V_18 . V_21 = F_16 ( F_17 ( V_19 [ 0 ] ) ) ;
V_18 . V_22 = F_17 ( V_19 [ 1 ] ) - 1 ;
V_18 . V_23 = ( unsigned long ) V_24 ;
V_18 . type = V_25 ;
F_18 ( & V_18 , 1 ) ;
return 1 ;
}
static void T_3 F_19 ( void )
{
if ( F_20 () )
F_18 ( V_26 , F_21 ( V_26 ) ) ;
if ( F_22 () )
F_18 ( V_27 , F_21 ( V_27 ) ) ;
}
static void T_3 F_23 ( void )
{
F_24 () ;
F_25 ( F_13 , NULL ) ;
F_26 ( V_24 ) ;
F_19 () ;
}
static void F_27 ( void )
{
struct V_4 * V_5 ;
V_5 = F_28 ( NULL , V_28 ) ;
if ( V_5 )
V_8 = F_4 ( V_5 , 0 ) ;
if ( ! V_8 )
F_29 ( L_7 ) ;
}
static void T_3 F_30 ( void )
{
F_31 () ;
F_27 () ;
}
static void T_3 F_32 ( void )
{
struct V_4 * V_29 ;
const char * V_30 = L_8 ;
unsigned int V_31 ;
int V_32 ;
if ( F_22 () ) {
F_8 (i2c_np, NULL, i2c_compat) {
if ( F_9 ( V_29 ) ) {
V_32 = F_33 ( V_29 , L_9 ) ;
if ( V_32 < 4 ) {
V_31 = F_34 ( V_33 ) ;
F_35 ( V_31 & ~ ( 0x1 << V_32 ) ,
V_33 ) ;
}
}
}
}
if ( ! F_36 ( V_34 ) )
F_7 () ;
if ( F_2 ( L_10 ) ||
F_2 ( L_11 ) )
F_37 ( & V_35 ) ;
F_38 ( L_12 , - 1 , NULL , 0 ) ;
F_39 ( NULL , V_36 , NULL , NULL ) ;
}
static void T_3 F_40 ( void )
{
#ifdef F_41
int V_37 ;
char * V_38 [] = {
L_13 ,
L_14 ,
L_15 ,
} ;
for ( V_37 = 0 ; V_37 < F_21 ( V_38 ) ; V_37 ++ )
if ( F_25 ( V_39 , V_38 [ V_37 ] ) )
break;
#endif
}
static void T_3 F_42 ( void )
{
F_43 ( 8 ) ;
}
