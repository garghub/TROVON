static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_2 T_3 * V_3 = NULL ;
if ( V_4 . V_5 )
V_4 . V_5 ( L_1 , 0 ) ;
V_2 = F_2 ( NULL , L_2 ) ;
if ( V_2 ) {
struct V_6 V_7 ;
F_3 ( V_2 , 0 , & V_7 ) ;
V_3 = F_4 ( V_7 . V_8 , F_5 ( & V_7 ) ) ;
F_6 ( V_2 ) ;
}
#ifdef F_7
F_8 (np, L_3 , L_4 )
F_9 ( V_2 ) ;
#endif
#ifdef F_10
F_11 () ;
if ( ( V_2 = F_2 ( NULL , L_5 ) ) != NULL ) {
F_12 ( V_2 ) ;
F_6 ( V_2 ) ;
for ( V_2 = NULL ; ( V_2 = F_2 ( V_2 , L_6 ) ) != NULL ; )
F_13 ( V_2 ) ;
#ifdef F_14
F_15 ( 1 , 2 , 1 , 0 , 3 , 0 ) ;
F_15 ( 1 , 3 , 1 , 0 , 3 , 0 ) ;
F_15 ( 1 , 8 , 1 , 0 , 1 , 0 ) ;
F_15 ( 1 , 10 , 2 , 0 , 3 , 0 ) ;
F_15 ( 1 , 9 , 2 , 1 , 3 , 0 ) ;
F_15 ( 1 , 11 , 2 , 1 , 3 , 0 ) ;
F_15 ( 2 , 20 , 2 , 0 , 1 , 0 ) ;
#endif
}
if ( ( V_2 = F_16 ( NULL , L_7 , L_8 ) )
!= NULL ) {
T_4 V_9 ;
#define F_17 0x20
F_18 ( & V_3 [ 9 ] , F_17 ) ;
F_19 ( 1000 ) ;
F_20 ( & V_3 [ 9 ] , F_17 ) ;
V_9 = F_21 ( V_10 ) ;
if ( V_9 == 0x80480021 ) {
void T_3 * V_11 ;
V_11 = F_4 ( F_22 () + 0x14a8 , 8 ) ;
F_23 ( V_11 , 0x0c003000 ) ;
F_24 ( V_11 + 4 , 0xff0 , 0xaa0 ) ;
F_25 ( V_11 ) ;
}
F_25 ( V_3 ) ;
F_6 ( V_2 ) ;
}
#endif
}
static int T_1 F_26 ( void )
{
F_27 ( NULL , V_12 , NULL ) ;
return 0 ;
}
static int T_1 F_28 ( void )
{
T_2 T_3 * V_13 ;
struct V_1 * V_2 ;
const char * V_14 ;
int V_15 = 0 ;
V_2 = F_16 ( NULL , NULL , L_9 ) ;
if ( ! V_2 )
return - V_16 ;
V_13 = F_29 ( V_2 , 0 ) ;
F_6 ( V_2 ) ;
if ( ! V_13 )
return - V_17 ;
V_2 = F_16 ( NULL , NULL , L_10 ) ;
if ( ! V_2 ) {
V_15 = - V_16 ;
goto V_18;
}
#define F_30 (0x3 << 6)
#define F_31 (0x0 << 6)
#define F_32 (0x3 << 4)
#define F_33 (0x0 << 4)
F_34 ( & V_13 [ 8 ] , F_30 | F_32 ,
F_31 | F_33 ) ;
#define F_35 0x0f
#define F_36 0x08
#define F_37 0x04
#define F_38 0x02
#define F_39 0x01
F_34 ( & V_13 [ 13 ] , F_35 , F_37 ) ;
V_14 = F_40 ( V_2 , L_11 , NULL ) ;
if ( V_14 && ! strcmp ( V_14 , L_12 ) ) {
F_20 ( & V_13 [ 13 ] , F_39 ) ;
F_41 ( V_19 , 48000000 ) ;
} else {
F_20 ( & V_13 [ 13 ] , F_38 ) ;
F_42 ( L_13 ) ;
}
F_6 ( V_2 ) ;
V_18:
F_25 ( V_13 ) ;
return V_15 ;
}
static void T_1 F_43 ( void )
{
struct V_1 * V_2 ;
V_2 = F_44 ( NULL , L_14 ) ;
if ( ! V_2 )
return;
F_45 ( V_2 , 0 ) ;
F_46 () ;
F_6 ( V_2 ) ;
#ifdef F_10
V_2 = F_16 ( NULL , NULL , L_15 ) ;
if ( ! V_2 ) {
V_2 = F_44 ( NULL , L_16 ) ;
if ( ! V_2 )
return;
}
F_47 ( V_2 , 0 , V_20 , V_21 ) ;
F_6 ( V_2 ) ;
#endif
}
static int T_1 F_48 ( void )
{
unsigned long V_22 = F_49 () ;
return F_50 ( V_22 , L_17 ) ;
}
