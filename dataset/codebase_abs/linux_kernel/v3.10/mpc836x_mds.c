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
F_7 () ;
#ifdef F_8
F_9 () ;
if ( ( V_2 = F_2 ( NULL , L_3 ) ) != NULL ) {
F_10 ( V_2 ) ;
F_6 ( V_2 ) ;
for ( V_2 = NULL ; ( V_2 = F_2 ( V_2 , L_4 ) ) != NULL ; )
F_11 ( V_2 ) ;
#ifdef F_12
F_13 ( 1 , 2 , 1 , 0 , 3 , 0 ) ;
F_13 ( 1 , 3 , 1 , 0 , 3 , 0 ) ;
F_13 ( 1 , 8 , 1 , 0 , 1 , 0 ) ;
F_13 ( 1 , 10 , 2 , 0 , 3 , 0 ) ;
F_13 ( 1 , 9 , 2 , 1 , 3 , 0 ) ;
F_13 ( 1 , 11 , 2 , 1 , 3 , 0 ) ;
F_13 ( 2 , 20 , 2 , 0 , 1 , 0 ) ;
#endif
}
if ( ( V_2 = F_14 ( NULL , L_5 , L_6 ) )
!= NULL ) {
T_4 V_9 ;
#define F_15 0x20
F_16 ( & V_3 [ 9 ] , F_15 ) ;
F_17 ( 1000 ) ;
F_18 ( & V_3 [ 9 ] , F_15 ) ;
V_9 = F_19 ( V_10 ) ;
if ( V_9 == 0x80480021 ) {
void T_3 * V_11 ;
V_11 = F_4 ( F_20 () + 0x14a8 , 8 ) ;
F_21 ( V_11 , 0x0c003000 ) ;
F_22 ( V_11 + 4 , 0xff0 , 0xaa0 ) ;
F_23 ( V_11 ) ;
}
F_23 ( V_3 ) ;
F_6 ( V_2 ) ;
}
#endif
}
static int T_1 F_24 ( void )
{
T_2 T_3 * V_12 ;
struct V_1 * V_2 ;
const char * V_13 ;
int V_14 = 0 ;
V_2 = F_14 ( NULL , NULL , L_7 ) ;
if ( ! V_2 )
return - V_15 ;
V_12 = F_25 ( V_2 , 0 ) ;
F_6 ( V_2 ) ;
if ( ! V_12 )
return - V_16 ;
V_2 = F_14 ( NULL , NULL , L_8 ) ;
if ( ! V_2 ) {
V_14 = - V_15 ;
goto V_17;
}
#define F_26 (0x3 << 6)
#define F_27 (0x0 << 6)
#define F_28 (0x3 << 4)
#define F_29 (0x0 << 4)
F_30 ( & V_12 [ 8 ] , F_26 | F_28 ,
F_27 | F_29 ) ;
#define F_31 0x0f
#define F_32 0x08
#define F_33 0x04
#define F_34 0x02
#define F_35 0x01
F_30 ( & V_12 [ 13 ] , F_31 , F_33 ) ;
V_13 = F_36 ( V_2 , L_9 , NULL ) ;
if ( V_13 && ! strcmp ( V_13 , L_10 ) ) {
F_18 ( & V_12 [ 13 ] , F_35 ) ;
F_37 ( V_18 , 48000000 ) ;
} else {
F_18 ( & V_12 [ 13 ] , F_34 ) ;
F_38 ( L_11 ) ;
}
F_6 ( V_2 ) ;
V_17:
F_23 ( V_12 ) ;
return V_14 ;
}
static int T_1 F_39 ( void )
{
unsigned long V_19 = F_40 () ;
return F_41 ( V_19 , L_12 ) ;
}
