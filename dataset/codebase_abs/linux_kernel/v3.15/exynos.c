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
F_8 ( & V_10 ) ;
}
void T_3 F_9 ( void )
{
F_10 ( L_3 , - 1 , NULL , 0 ) ;
}
void T_3 F_11 ( void )
{
if ( F_2 ( L_1 ) )
return;
F_12 () ;
F_13 () ;
}
static int T_3 F_14 ( unsigned long V_11 , const char * V_12 ,
int V_13 , void * V_14 )
{
struct V_15 V_16 ;
T_4 * V_17 ;
unsigned long V_18 ;
if ( ! F_15 ( V_11 , L_4 ) &&
! F_15 ( V_11 , L_2 ) )
return 0 ;
V_17 = F_16 ( V_11 , L_5 , & V_18 ) ;
if ( V_17 == NULL || V_18 != (sizeof( unsigned long ) * 2 ) )
return 0 ;
V_16 . V_19 = F_17 ( F_18 ( V_17 [ 0 ] ) ) ;
V_16 . V_20 = F_18 ( V_17 [ 1 ] ) - 1 ;
V_16 . V_21 = ( unsigned long ) V_22 ;
V_16 . type = V_23 ;
F_19 ( & V_16 , 1 ) ;
return 1 ;
}
static void T_3 F_20 ( void )
{
if ( F_21 () )
F_19 ( V_24 , F_22 ( V_24 ) ) ;
if ( F_23 () )
F_19 ( V_25 , F_22 ( V_25 ) ) ;
if ( F_24 () ) {
if ( F_25 () == V_26 )
F_19 ( V_27 ,
F_22 ( V_27 ) ) ;
else
F_19 ( V_28 ,
F_22 ( V_28 ) ) ;
F_19 ( V_29 , F_22 ( V_29 ) ) ;
}
if ( F_26 () || F_27 () )
F_19 ( V_30 , F_22 ( V_30 ) ) ;
if ( F_28 () )
F_19 ( V_31 , F_22 ( V_31 ) ) ;
}
void T_3 F_29 ( void )
{
F_30 () ;
F_31 ( F_14 , NULL ) ;
F_32 ( V_22 ) ;
F_20 () ;
}
static int T_3 F_33 ( void )
{
return F_34 ( & V_32 , NULL ) ;
}
static int T_3 F_35 ( void )
{
int V_33 ;
V_33 = F_36 ( V_34 , V_35 ) ;
if ( V_33 )
return V_33 ;
if ( F_37 ( V_36 ) ) {
V_37 = F_38 ( & V_38 ) ;
F_39 ( & V_37 , sizeof( unsigned long ) ) ;
}
return 0 ;
}
static void T_3 F_40 ( void )
{
struct V_4 * V_39 ;
const char * V_40 = L_6 ;
unsigned int V_41 ;
int V_42 ;
if ( F_23 () ) {
F_41 (i2c_np, NULL, i2c_compat) {
if ( F_42 ( V_39 ) ) {
V_42 = F_43 ( V_39 , L_7 ) ;
if ( V_42 < 4 ) {
V_41 = F_44 ( V_43 ) ;
F_45 ( V_41 & ~ ( 0x1 << V_42 ) ,
V_43 ) ;
}
}
}
}
F_7 () ;
F_9 () ;
F_46 ( NULL , V_44 , NULL , NULL ) ;
}
static void T_3 F_47 ( void )
{
#ifdef F_48
int V_45 ;
char * V_46 [] = {
L_8 ,
L_9 ,
L_10 ,
} ;
for ( V_45 = 0 ; V_45 < F_22 ( V_46 ) ; V_45 ++ )
if ( F_31 ( V_47 , V_46 [ V_45 ] ) )
break;
#endif
}
