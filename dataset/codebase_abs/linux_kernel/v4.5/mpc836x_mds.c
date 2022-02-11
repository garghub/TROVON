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
if ( ( V_2 = F_2 ( NULL , L_3 ) ) != NULL ) {
F_9 ( V_2 ) ;
F_6 ( V_2 ) ;
for ( V_2 = NULL ; ( V_2 = F_2 ( V_2 , L_4 ) ) != NULL ; )
F_10 ( V_2 ) ;
#ifdef F_11
F_12 ( 1 , 2 , 1 , 0 , 3 , 0 ) ;
F_12 ( 1 , 3 , 1 , 0 , 3 , 0 ) ;
F_12 ( 1 , 8 , 1 , 0 , 1 , 0 ) ;
F_12 ( 1 , 10 , 2 , 0 , 3 , 0 ) ;
F_12 ( 1 , 9 , 2 , 1 , 3 , 0 ) ;
F_12 ( 1 , 11 , 2 , 1 , 3 , 0 ) ;
F_12 ( 2 , 20 , 2 , 0 , 1 , 0 ) ;
#endif
}
if ( ( V_2 = F_13 ( NULL , L_5 , L_6 ) )
!= NULL ) {
T_4 V_9 ;
#define F_14 0x20
F_15 ( & V_3 [ 9 ] , F_14 ) ;
F_16 ( 1000 ) ;
F_17 ( & V_3 [ 9 ] , F_14 ) ;
V_9 = F_18 ( V_10 ) ;
if ( V_9 == 0x80480021 ) {
void T_3 * V_11 ;
V_11 = F_4 ( F_19 () + 0x14a8 , 8 ) ;
F_20 ( V_11 , 0x0c003000 ) ;
F_21 ( V_11 + 4 , 0xff0 , 0xaa0 ) ;
F_22 ( V_11 ) ;
}
F_22 ( V_3 ) ;
F_6 ( V_2 ) ;
}
#endif
}
static int T_1 F_23 ( void )
{
T_2 T_3 * V_12 ;
struct V_1 * V_2 ;
const char * V_13 ;
int V_14 = 0 ;
V_2 = F_13 ( NULL , NULL , L_7 ) ;
if ( ! V_2 )
return - V_15 ;
V_12 = F_24 ( V_2 , 0 ) ;
F_6 ( V_2 ) ;
if ( ! V_12 )
return - V_16 ;
V_2 = F_13 ( NULL , NULL , L_8 ) ;
if ( ! V_2 ) {
V_14 = - V_15 ;
goto V_17;
}
#define F_25 (0x3 << 6)
#define F_26 (0x0 << 6)
#define F_27 (0x3 << 4)
#define F_28 (0x0 << 4)
F_29 ( & V_12 [ 8 ] , F_25 | F_27 ,
F_26 | F_28 ) ;
#define F_30 0x0f
#define F_31 0x08
#define F_32 0x04
#define F_33 0x02
#define F_34 0x01
F_29 ( & V_12 [ 13 ] , F_30 , F_32 ) ;
V_13 = F_35 ( V_2 , L_9 , NULL ) ;
if ( V_13 && ! strcmp ( V_13 , L_10 ) ) {
F_17 ( & V_12 [ 13 ] , F_34 ) ;
F_36 ( V_18 , 48000000 ) ;
} else {
F_17 ( & V_12 [ 13 ] , F_33 ) ;
F_37 ( L_11 ) ;
}
F_6 ( V_2 ) ;
V_17:
F_22 ( V_12 ) ;
return V_14 ;
}
static int T_1 F_38 ( void )
{
unsigned long V_19 = F_39 () ;
return F_40 ( V_19 , L_12 ) ;
}
